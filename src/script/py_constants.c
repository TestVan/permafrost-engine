/*
 *  This file is part of Permafrost Engine. 
 *  Copyright (C) 2018-2020 Eduard Permyakov 
 *
 *  Permafrost Engine is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Permafrost Engine is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *  Linking this software statically or dynamically with other modules is making 
 *  a combined work based on this software. Thus, the terms and conditions of 
 *  the GNU General Public License cover the whole combination. 
 *  
 *  As a special exception, the copyright holders of Permafrost Engine give 
 *  you permission to link Permafrost Engine with independent modules to produce 
 *  an executable, regardless of the license terms of these independent 
 *  modules, and to copy and distribute the resulting executable under 
 *  terms of your choice, provided that you also meet, for each linked 
 *  independent module, the terms and conditions of the license of that 
 *  module. An independent module is a module which is not derived from 
 *  or based on Permafrost Engine. If you modify Permafrost Engine, you may 
 *  extend this exception to your version of Permafrost Engine, but you are not 
 *  obliged to do so. If you do not wish to do so, delete this exception 
 *  statement from your version.
 *
 */

#include "py_constants.h"
#include "../lib/public/nuklear.h"
#include "../event.h"
#include "../config.h"
#include "../map/public/map.h"
#include "../map/public/tile.h"
#include "../game/public/game.h"
#include "../anim/public/anim.h"
#include "../main.h"
#include "../ui.h"

#include <SDL.h>

#define PY_EXPOSE_ENUM(module, enumval)                     \
    do{                                                     \
        PyModule_AddIntConstant(module, #enumval, enumval); \
    }while(0)

/*****************************************************************************/
/* STATIC FUNCTIONS                                                          */
/*****************************************************************************/

static void s_expose_sdl_constants(PyObject *module)
{
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_A);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_B);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_C);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_D);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_E);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_G);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_H);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_I);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_J);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_K);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_L);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_M);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_N);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_O);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_P);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_Q);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_R);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_S);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_T);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_U);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_V);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_W);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_X);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_Y);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_Z);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_1);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_2);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_3);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_4);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_5);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_6);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_7);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_8);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_9);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_0);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_RETURN);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_ESCAPE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_BACKSPACE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_TAB);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_SPACE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_MINUS);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_EQUALS);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LEFTBRACKET);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_RIGHTBRACKET);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_BACKSLASH);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_NONUSHASH);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_SEMICOLON);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_APOSTROPHE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_GRAVE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_COMMA);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_PERIOD);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_SLASH);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_CAPSLOCK);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F1);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F2);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F3);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F4);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F5);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F6);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F7);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F8);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F9);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F10);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F11);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F12);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_PRINTSCREEN);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_SCROLLLOCK);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_PAUSE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_INSERT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_HOME);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_PAGEUP);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_DELETE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_END);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_PAGEDOWN);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_RIGHT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LEFT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_DOWN);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_UP);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_NUMLOCKCLEAR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_DIVIDE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_MULTIPLY);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_MINUS);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_PLUS);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_ENTER);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_1);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_2);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_3);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_4);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_5);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_6);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_7);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_8);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_9);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_0);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_PERIOD);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_NONUSBACKSLASH);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_APPLICATION);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_POWER);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_EQUALS);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F13);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F14);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F15);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F16);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F17);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F18);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F19);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F20);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F21);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F22);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F23);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_F24);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_EXECUTE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_HELP);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_MENU);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_SELECT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_STOP);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AGAIN);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_UNDO);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_CUT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_COPY);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_PASTE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_FIND);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_MUTE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_VOLUMEUP);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_VOLUMEDOWN);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_INTERNATIONAL2);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_INTERNATIONAL3);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_INTERNATIONAL4);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_INTERNATIONAL5);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_INTERNATIONAL6);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_INTERNATIONAL7);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_INTERNATIONAL8);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_INTERNATIONAL9);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LANG1);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LANG2);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LANG3);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LANG4);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LANG5);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LANG6);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LANG7);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LANG8);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LANG9);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_ALTERASE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_SYSREQ);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_CANCEL);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_CLEAR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_PRIOR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_RETURN2);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_SEPARATOR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_OUT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_OPER);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_CLEARAGAIN);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_CRSEL);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_EXSEL);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_00);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_000);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_THOUSANDSSEPARATOR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_DECIMALSEPARATOR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_CURRENCYUNIT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_CURRENCYSUBUNIT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_LEFTPAREN);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_RIGHTPAREN);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_LEFTBRACE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_RIGHTBRACE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_TAB);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_BACKSPACE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_A);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_B);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_C);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_D);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_E);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_F);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_XOR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_POWER);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_PERCENT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_LESS);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_GREATER);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_AMPERSAND);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_DBLAMPERSAND);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_VERTICALBAR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_DBLVERTICALBAR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_COLON);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_HASH);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_SPACE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_AT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_EXCLAM);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_MEMSTORE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_MEMRECALL);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_MEMCLEAR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_MEMADD);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_MEMSUBTRACT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_MEMMULTIPLY);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_MEMDIVIDE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_PLUSMINUS);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_CLEAR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_CLEARENTRY);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_BINARY);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_OCTAL);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_DECIMAL);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KP_HEXADECIMAL);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LCTRL);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LSHIFT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LALT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_LGUI);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_RCTRL);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_RSHIFT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_RALT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_RGUI);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_MODE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AUDIONEXT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AUDIOPREV);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AUDIOSTOP);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AUDIOPLAY);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AUDIOMUTE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_MEDIASELECT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_WWW);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_MAIL);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_CALCULATOR);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_COMPUTER);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AC_SEARCH);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AC_HOME);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AC_BACK);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AC_FORWARD);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AC_STOP);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AC_REFRESH);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_AC_BOOKMARKS);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_BRIGHTNESSDOWN);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_BRIGHTNESSUP);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_DISPLAYSWITCH);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KBDILLUMTOGGLE);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KBDILLUMDOWN);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_KBDILLUMUP);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_EJECT);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_SLEEP);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_APP1);
    PY_EXPOSE_ENUM(module, SDL_SCANCODE_APP2);

    PY_EXPOSE_ENUM(module, SDL_BUTTON_LEFT);
    PY_EXPOSE_ENUM(module, SDL_BUTTON_MIDDLE);
    PY_EXPOSE_ENUM(module, SDL_BUTTON_RIGHT);
    PY_EXPOSE_ENUM(module, SDL_BUTTON_X1);
    PY_EXPOSE_ENUM(module, SDL_BUTTON_X2);

    PY_EXPOSE_ENUM(module, SDL_RELEASED);
    PY_EXPOSE_ENUM(module, SDL_PRESSED);

    PY_EXPOSE_ENUM(module, SDL_QUIT);
    PY_EXPOSE_ENUM(module, SDL_APP_TERMINATING);
    PY_EXPOSE_ENUM(module, SDL_APP_LOWMEMORY);
    PY_EXPOSE_ENUM(module, SDL_APP_WILLENTERBACKGROUND);
    PY_EXPOSE_ENUM(module, SDL_APP_DIDENTERBACKGROUND);
    PY_EXPOSE_ENUM(module, SDL_APP_WILLENTERFOREGROUND);
    PY_EXPOSE_ENUM(module, SDL_APP_DIDENTERFOREGROUND);
    PY_EXPOSE_ENUM(module, SDL_WINDOWEVENT);
    PY_EXPOSE_ENUM(module, SDL_SYSWMEVENT);
    PY_EXPOSE_ENUM(module, SDL_KEYDOWN);
    PY_EXPOSE_ENUM(module, SDL_KEYUP);
    PY_EXPOSE_ENUM(module, SDL_TEXTEDITING);
    PY_EXPOSE_ENUM(module, SDL_TEXTINPUT);
    PY_EXPOSE_ENUM(module, SDL_KEYMAPCHANGED);
    PY_EXPOSE_ENUM(module, SDL_MOUSEMOTION);
    PY_EXPOSE_ENUM(module, SDL_MOUSEBUTTONDOWN);
    PY_EXPOSE_ENUM(module, SDL_MOUSEBUTTONUP);
    PY_EXPOSE_ENUM(module, SDL_MOUSEWHEEL);
    PY_EXPOSE_ENUM(module, SDL_JOYAXISMOTION);
    PY_EXPOSE_ENUM(module, SDL_JOYBALLMOTION);
    PY_EXPOSE_ENUM(module, SDL_JOYHATMOTION);
    PY_EXPOSE_ENUM(module, SDL_JOYBUTTONDOWN);
    PY_EXPOSE_ENUM(module, SDL_JOYBUTTONUP);
    PY_EXPOSE_ENUM(module, SDL_JOYDEVICEADDED);
    PY_EXPOSE_ENUM(module, SDL_JOYDEVICEREMOVED);
    PY_EXPOSE_ENUM(module, SDL_CONTROLLERAXISMOTION);
    PY_EXPOSE_ENUM(module, SDL_CONTROLLERBUTTONDOWN);
    PY_EXPOSE_ENUM(module, SDL_CONTROLLERBUTTONUP);
    PY_EXPOSE_ENUM(module, SDL_CONTROLLERDEVICEADDED);
    PY_EXPOSE_ENUM(module, SDL_CONTROLLERDEVICEREMOVED);
    PY_EXPOSE_ENUM(module, SDL_CONTROLLERDEVICEREMAPPED);
    PY_EXPOSE_ENUM(module, SDL_FINGERDOWN);
    PY_EXPOSE_ENUM(module, SDL_FINGERUP);
    PY_EXPOSE_ENUM(module, SDL_FINGERMOTION);
    PY_EXPOSE_ENUM(module, SDL_DOLLARGESTURE);
    PY_EXPOSE_ENUM(module, SDL_DOLLARRECORD);
    PY_EXPOSE_ENUM(module, SDL_MULTIGESTURE);
    PY_EXPOSE_ENUM(module, SDL_CLIPBOARDUPDATE);
    PY_EXPOSE_ENUM(module, SDL_DROPFILE);
    PY_EXPOSE_ENUM(module, SDL_DROPTEXT);
    PY_EXPOSE_ENUM(module, SDL_DROPBEGIN);
    PY_EXPOSE_ENUM(module, SDL_DROPCOMPLETE);
    PY_EXPOSE_ENUM(module, SDL_AUDIODEVICEADDED);
    PY_EXPOSE_ENUM(module, SDL_AUDIODEVICEREMOVED);
    PY_EXPOSE_ENUM(module, SDL_RENDER_TARGETS_RESET);
    PY_EXPOSE_ENUM(module, SDL_RENDER_DEVICE_RESET);
    PY_EXPOSE_ENUM(module, SDL_USEREVENT);
    PY_EXPOSE_ENUM(module, SDL_LASTEVENT);
}

static void s_expose_nuklear_constants(PyObject *module)
{
    PY_EXPOSE_ENUM(module, NK_WINDOW_BORDER);
    PY_EXPOSE_ENUM(module, NK_WINDOW_MOVABLE);
    PY_EXPOSE_ENUM(module, NK_WINDOW_SCALABLE);
    PY_EXPOSE_ENUM(module, NK_WINDOW_CLOSABLE);
    PY_EXPOSE_ENUM(module, NK_WINDOW_MINIMIZABLE);
    PY_EXPOSE_ENUM(module, NK_WINDOW_NO_SCROLLBAR);
    PY_EXPOSE_ENUM(module, NK_WINDOW_TITLE);
    PY_EXPOSE_ENUM(module, NK_WINDOW_SCROLL_AUTO_HIDE);
    PY_EXPOSE_ENUM(module, NK_WINDOW_BACKGROUND);
    PY_EXPOSE_ENUM(module, NK_WINDOW_SCALE_LEFT);
    PY_EXPOSE_ENUM(module, NK_WINDOW_NO_INPUT);

    PY_EXPOSE_ENUM(module, NK_TEXT_ALIGN_LEFT);
    PY_EXPOSE_ENUM(module, NK_TEXT_ALIGN_CENTERED);
    PY_EXPOSE_ENUM(module, NK_TEXT_ALIGN_RIGHT);
    PY_EXPOSE_ENUM(module, NK_TEXT_ALIGN_TOP);
    PY_EXPOSE_ENUM(module, NK_TEXT_ALIGN_MIDDLE);
    PY_EXPOSE_ENUM(module, NK_TEXT_ALIGN_BOTTOM);

    PY_EXPOSE_ENUM(module, NK_TEXT_LEFT);
    PY_EXPOSE_ENUM(module, NK_TEXT_CENTERED);
    PY_EXPOSE_ENUM(module, NK_TEXT_RIGHT);

    PY_EXPOSE_ENUM(module, NK_CHART_LINES);
    PY_EXPOSE_ENUM(module, NK_CHART_COLUMN);
    PY_EXPOSE_ENUM(module, NK_CHART_MAX);

    PY_EXPOSE_ENUM(module, NK_DYNAMIC);
    PY_EXPOSE_ENUM(module, NK_STATIC);

    PY_EXPOSE_ENUM(module, NK_EDIT_DEFAULT);
    PY_EXPOSE_ENUM(module, NK_EDIT_READ_ONLY);
    PY_EXPOSE_ENUM(module, NK_EDIT_AUTO_SELECT);
    PY_EXPOSE_ENUM(module, NK_EDIT_SIG_ENTER);
    PY_EXPOSE_ENUM(module, NK_EDIT_ALLOW_TAB);
    PY_EXPOSE_ENUM(module, NK_EDIT_NO_CURSOR);
    PY_EXPOSE_ENUM(module, NK_EDIT_SELECTABLE);
    PY_EXPOSE_ENUM(module, NK_EDIT_CLIPBOARD);
    PY_EXPOSE_ENUM(module, NK_EDIT_CTRL_ENTER_NEWLINE);
    PY_EXPOSE_ENUM(module, NK_EDIT_NO_HORIZONTAL_SCROLL);
    PY_EXPOSE_ENUM(module, NK_EDIT_ALWAYS_INSERT_MODE);
    PY_EXPOSE_ENUM(module, NK_EDIT_MULTILINE);
    PY_EXPOSE_ENUM(module, NK_EDIT_GOTO_END_ON_ACTIVATE);

    PY_EXPOSE_ENUM(module, NK_EDIT_SIMPLE);
    PY_EXPOSE_ENUM(module, NK_EDIT_FIELD);
    PY_EXPOSE_ENUM(module, NK_EDIT_BOX);
    PY_EXPOSE_ENUM(module, NK_EDIT_EDITOR);
}

static void s_expose_event_constants(PyObject *module)
{
    PY_EXPOSE_ENUM(module, EVENT_UPDATE_START);
    PY_EXPOSE_ENUM(module, EVENT_UPDATE_END);
    PY_EXPOSE_ENUM(module, EVENT_UPDATE_UI);
    PY_EXPOSE_ENUM(module, EVENT_RENDER_3D);
    PY_EXPOSE_ENUM(module, EVENT_RENDER_UI);
    PY_EXPOSE_ENUM(module, EVENT_SELECTED_TILE_CHANGED);
    PY_EXPOSE_ENUM(module, EVENT_NEW_GAME);
    PY_EXPOSE_ENUM(module, EVENT_UNIT_SELECTION_CHANGED);
    PY_EXPOSE_ENUM(module, EVENT_60HZ_TICK);
    PY_EXPOSE_ENUM(module, EVENT_30HZ_TICK);
    PY_EXPOSE_ENUM(module, EVENT_10HZ_TICK);
    PY_EXPOSE_ENUM(module, EVENT_1HZ_TICK);
    PY_EXPOSE_ENUM(module, EVENT_ANIM_FINISHED);
    PY_EXPOSE_ENUM(module, EVENT_ANIM_CYCLE_FINISHED);
    PY_EXPOSE_ENUM(module, EVENT_MOTION_START);
    PY_EXPOSE_ENUM(module, EVENT_MOTION_END);
    PY_EXPOSE_ENUM(module, EVENT_ATTACK_START);
    PY_EXPOSE_ENUM(module, EVENT_ATTACK_END);
    PY_EXPOSE_ENUM(module, EVENT_ENTITY_DEATH);
    PY_EXPOSE_ENUM(module, EVENT_ENGINE_LAST);
}

static void s_expose_map_constants(PyObject *module)
{
    PY_EXPOSE_ENUM(module, TILETYPE_FLAT);
    PY_EXPOSE_ENUM(module, TILETYPE_RAMP_SN);
    PY_EXPOSE_ENUM(module, TILETYPE_RAMP_NS);
    PY_EXPOSE_ENUM(module, TILETYPE_RAMP_EW);
    PY_EXPOSE_ENUM(module, TILETYPE_RAMP_WE);
    PY_EXPOSE_ENUM(module, TILETYPE_CORNER_CONCAVE_SW);
    PY_EXPOSE_ENUM(module, TILETYPE_CORNER_CONVEX_SW);
    PY_EXPOSE_ENUM(module, TILETYPE_CORNER_CONCAVE_SE);
    PY_EXPOSE_ENUM(module, TILETYPE_CORNER_CONVEX_SE);
    PY_EXPOSE_ENUM(module, TILETYPE_CORNER_CONCAVE_NW);
    PY_EXPOSE_ENUM(module, TILETYPE_CORNER_CONVEX_NW);
    PY_EXPOSE_ENUM(module, TILETYPE_CORNER_CONCAVE_NE);
    PY_EXPOSE_ENUM(module, TILETYPE_CORNER_CONVEX_NE);

    PY_EXPOSE_ENUM(module, TILES_PER_CHUNK_WIDTH);
    PY_EXPOSE_ENUM(module, TILES_PER_CHUNK_HEIGHT);

    PY_EXPOSE_ENUM(module, BLEND_MODE_NOBLEND);
    PY_EXPOSE_ENUM(module, BLEND_MODE_BLUR);

    PY_EXPOSE_ENUM(module, X_COORDS_PER_TILE);
    PY_EXPOSE_ENUM(module, Y_COORDS_PER_TILE);
    PY_EXPOSE_ENUM(module, Z_COORDS_PER_TILE);
}

static void s_expose_game_constants(PyObject *module)
{
    PY_EXPOSE_ENUM(module, CAM_MODE_FPS);
    PY_EXPOSE_ENUM(module, CAM_MODE_RTS);

    PY_EXPOSE_ENUM(module, DIPLOMACY_STATE_PEACE);
    PY_EXPOSE_ENUM(module, DIPLOMACY_STATE_WAR);

    PY_EXPOSE_ENUM(module, G_RUNNING);
    PY_EXPOSE_ENUM(module, G_PAUSED_FULL);
    PY_EXPOSE_ENUM(module, G_PAUSED_UI_RUNNING);
}

static void s_expose_anim_constants(PyObject *module)
{
    PY_EXPOSE_ENUM(module, ANIM_MODE_LOOP);
    PY_EXPOSE_ENUM(module, ANIM_MODE_ONCE);
    PY_EXPOSE_ENUM(module, ANIM_MODE_ONCE_HIDE_ON_FINISH);
}

static void s_expose_engine_constants(PyObject *module)
{
    PY_EXPOSE_ENUM(module, PF_WF_FULLSCREEN);
    PY_EXPOSE_ENUM(module, PF_WF_BORDERLESS_WIN);
    PY_EXPOSE_ENUM(module, PF_WF_WINDOW);
}

static void s_expose_ui_constants(PyObject *module)
{
    PY_EXPOSE_ENUM(module, ANCHOR_X_LEFT);
    PY_EXPOSE_ENUM(module, ANCHOR_X_RIGHT);
    PY_EXPOSE_ENUM(module, ANCHOR_X_CENTER);
    PY_EXPOSE_ENUM(module, ANCHOR_Y_TOP);
    PY_EXPOSE_ENUM(module, ANCHOR_Y_BOT);
    PY_EXPOSE_ENUM(module, ANCHOR_Y_CENTER);
    PY_EXPOSE_ENUM(module, ANCHOR_DEFAULT);
    PY_EXPOSE_ENUM(module, ANCHOR_X_MASK);
    PY_EXPOSE_ENUM(module, ANCHOR_Y_MASK);
}

/*****************************************************************************/
/* EXTERN FUNCTIONS                                                          */
/*****************************************************************************/

void S_Constants_Expose(PyObject *module)
{
    s_expose_sdl_constants(module);
    s_expose_nuklear_constants(module);
    s_expose_event_constants(module);
    s_expose_map_constants(module);
    s_expose_game_constants(module);
    s_expose_anim_constants(module);
    s_expose_engine_constants(module);
    s_expose_ui_constants(module);
}
