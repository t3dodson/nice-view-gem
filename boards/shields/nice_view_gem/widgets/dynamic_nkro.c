#include <zephyr/kernel.h>
#include "dynamic_nkro.h"
#include "../assets/custom_fonts.h"

// Only the central side has hid_dynamic_nkro.c compiled in, and only when the
// CONFIG_ZMK_HID_REPORT_TYPE_DYNAMIC feature is enabled. Mode never changes mid-session (toggling
// it reboots the MCU), so we just read it fresh on every redraw instead of wiring up an event.
#if (!IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)) &&                \
    IS_ENABLED(CONFIG_ZMK_HID_REPORT_TYPE_DYNAMIC)

#include <zmk/hid_dynamic_nkro.h>

void draw_dynamic_nkro_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_LEFT);

    const char *text =
        zmk_hid_dynamic_nkro_get_mode() == ZMK_HID_DYNAMIC_NKRO_MODE_NKRO ? "nkro" : "hkro";

    // Own row below the battery%/output-icon line (which occupies y 0..14). The 4-char,
    // 8px/glyph label needs ~32px, so it's left-aligned from x=2 rather than tucked under
    // the output icon where it would overrun the 68px-wide canvas.
    canvas_draw_text(canvas, 2, 18, 64, &label_dsc, text);
}

#else

void draw_dynamic_nkro_status(lv_obj_t *canvas, const struct status_state *state) {}

#endif
