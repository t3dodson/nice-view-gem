#include <zephyr/kernel.h>
#include "battery.h"
#include "../assets/custom_fonts.h"

LV_IMG_DECLARE(bolt);

const int BOLT_WIDTH = 5;
const int BOLT_MARGIN = 2;
const int TOP_LEFT_MARGIN = 1;

static void draw_level(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_right_dsc;
    init_label_dsc(&label_right_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_LEFT);

    char text[10] = {};

    sprintf(text, "%i%%", state->battery);
    lv_canvas_draw_text(canvas, 0 + BOLT_WIDTH + (2 * BOLT_MARGIN) + TOP_LEFT_MARGIN, 0 + TOP_LEFT_MARGIN, 42, &label_right_dsc, text);
}

static void draw_charging_level(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    lv_canvas_draw_img(canvas, BOLT_MARGIN + TOP_LEFT_MARGIN, BOLT_MARGIN + TOP_LEFT_MARGIN, &bolt, &img_dsc);
}

void draw_battery_status(lv_obj_t *canvas, const struct status_state *state) {
    if (state->charging) {
        draw_charging_level(canvas, state);
    }
    draw_level(canvas, state);
}