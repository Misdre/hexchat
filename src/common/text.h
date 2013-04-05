/* HexChat
 * Copyright (C) 1998-2010 Peter Zelezny.
 * Copyright (C) 2009-2013 Berke Viktor.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "textenums.h"

#ifndef HEXCHAT_TEXT_H
#define HEXCHAT_TEXT_H

#define EMIT_SIGNAL(i, sess, a, b, c, d, e) text_emit(i, sess, a, b, c, d)

struct text_event
{
	char *name;
	char * const *help;
	int num_args;
	char *def;
};

void scrollback_close (session *sess);
void scrollback_load (session *sess);

int text_word_check (char *word, int len);
void PrintText (session *sess, char *text);
void PrintTextf (session *sess, char *format, ...);
void log_close (session *sess);
void log_open_or_close (session *sess);
void load_text_events (void);
void pevent_save (char *fn);
int pevt_build_string (const char *input, char **output, int *max_arg);
int pevent_load (char *filename);
void pevent_make_pntevts (void);
int text_color_of (char *name);
void text_emit (int index, session *sess, char *a, char *b, char *c, char *d);
int text_emit_by_name (char *name, session *sess, char *a, char *b, char *c, char *d);
char *text_validate (char **text, int *len);
int get_stamp_str (char *fmt, time_t tim, char **ret);
void format_event (session *sess, int index, char **args, char *o, int sizeofo, unsigned int stripcolor_args);
char *text_find_format_string (char *name);
 
void sound_play (const char *file, gboolean quiet);
void sound_play_event (int i);
void sound_beep (session *);
void sound_load ();
void sound_save ();

#endif
