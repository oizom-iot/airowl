SET(SOURCES screens/ui_Screen1.c
    screens/ui_Screen2.c
    screens/ui_Screen3.c
    screens/ui_Screen4.c
    screens/ui_Screen5.c
    screens/ui_Screen6.c
    screens/ui_Screen7.c
    screens/ui_Screen8.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_sls_logo_png.c
    ui_temporary_image.c
    fonts/ui_font_clock_66.c)

add_library(ui ${SOURCES})
