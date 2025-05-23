CAPS_WORD_ENABLE = yes
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
# Mouse keys needed for wheel up/down/left/right
#MOUSEKEY_ENABLE = yes
SPACE_CADET_ENABLE = no
TAP_DANCE_ENABLE = yes
UNICODEMAP_ENABLE = yes
AVR_USE_MINIMAL_PRINTF = yes

SRC += napoli1084.c
SRC += napoli1084_symbolkeys.c
#SRC += napoli1084_tapdance.c
SRC += napoli1084_utils.c

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  SRC += napoli1084_rgblayers.c
  SRC += napoli1084_rgbmode.c
endif

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
  SRC += napoli1084_rgbmatrix.c
  SRC += napoli1084_rgbmode.c
endif

# Copied from https://github.com/splitkb/qmk_userspace/blob/halcyon/users/halcyon_modules/rules.mk
ifneq ($(filter $(strip $(KEYBOARD)), splitkb/halcyon/kyria/rev4 \
                                      splitkb/halcyon/ferris/rev1 \
                                      splitkb/halcyon/lily58/rev2 \
                                      splitkb/halcyon/elora/rev2 \
                                      splitkb/halcyon/corne/rev2),)
    include $(USER_PATH)/splitkb/rules.mk
endif
