#include <zephyr/kernel.h>
#include "layer.h"
#include "../assets/custom_fonts.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim_layer_suffix(char *str) {
    size_t len = strlen(str);

    // Walk backwards
    ssize_t i = len - 1;

    // First skip digits
    while (i >= 0 && isdigit((unsigned char)str[i])) {
        i--;
    }

    // If we find an underscore before the digits, remove it
    if (i >= 0 && str[i] == '_') {
        str[i] = '\0';
    }
}


void draw_layer_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_CENTER);

    char text[10] = {};

    if (state->layer_label == NULL) {
        sprintf(text, "Layer %i", state->layer_index);
    } else {
        strncpy(text, trim_layer_suffix(state->layer_label), 9);
        to_uppercase(text);
    }

    lv_canvas_draw_text(canvas, 0, 146 + BUFFER_OFFSET_BOTTOM, 68, &label_dsc, text);
}