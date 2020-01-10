/* main.c generated by valac 0.20.1.4-f5a54, the Vala compiler
 * generated from main.vala, do not modify */

/*
 * Copyright (C) 2013  Paolo Borelli <pborelli@gnome.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>
#include "config.h"
#include <gtk/gtk.h>
#include <gio/gio.h>


#define CLOCKS_TYPE_APPLICATION (clocks_application_get_type ())
#define CLOCKS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLOCKS_TYPE_APPLICATION, ClocksApplication))
#define CLOCKS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CLOCKS_TYPE_APPLICATION, ClocksApplicationClass))
#define CLOCKS_IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLOCKS_TYPE_APPLICATION))
#define CLOCKS_IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CLOCKS_TYPE_APPLICATION))
#define CLOCKS_APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CLOCKS_TYPE_APPLICATION, ClocksApplicationClass))

typedef struct _ClocksApplication ClocksApplication;
typedef struct _ClocksApplicationClass ClocksApplicationClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))



gint _vala_main (gchar** args, int args_length1);
ClocksApplication* clocks_application_new (void);
ClocksApplication* clocks_application_construct (GType object_type);
GType clocks_application_get_type (void) G_GNUC_CONST;


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	ClocksApplication* _tmp0_;
	ClocksApplication* app;
	gchar** _tmp1_;
	gint _tmp1__length1;
	gint _tmp2_ = 0;
	bindtextdomain (GETTEXT_PACKAGE, GNOMELOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
	_tmp0_ = clocks_application_new ();
	app = _tmp0_;
	_tmp1_ = args;
	_tmp1__length1 = args_length1;
	_tmp2_ = g_application_run ((GApplication*) app, _tmp1__length1, _tmp1_);
	result = _tmp2_;
	_g_object_unref0 (app);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return _vala_main (argv, argc);
}



