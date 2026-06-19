# A nice!view

The nice!view is a low-power, high refresh rate display meant to replace I2C OLEDs traditionally used.

This shield requires that a `&pro_micro_spi` labeled SPI bus is provided with _at least_ MOSI, SCK, and CS pins defined (this is exposed natively by boards using the Arduino Pro Micro footprint, such as nice!nano).

160x68

https://docs.lvgl.io/7.11/widgets/canvas.html

    lv_canvas_draw_rect(canvas, x, y, width, heigth, &draw_dsc)

    lv_canvas_draw_text(canvas, x, y, max_width, &draw_dsc, txt, LV_LABEL_ALIGN_LEFT/CENTER/RIGHT)

    lv_canvas_draw_img(canvas, x, y, &img_src, &draw_dsc)

    lv_canvas_draw_line(canvas, point_array, point_cnt, &draw_dsc)

    lv_canvas_draw_polygon(canvas, points_array, point_cnt, &draw_dsc)

    lv_canvas_draw_arc(canvas, x, y, radius, start_angle, end_angle, &draw_dsc)
