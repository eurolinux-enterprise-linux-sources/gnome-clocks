/* timer.c generated by valac 0.20.1.4-f5a54, the Vala compiler
 * generated from timer.vala, do not modify */

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
#include <libgd/gd.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <gtk/gtk.h>
#include <float.h>
#include <math.h>
#include <glib/gi18n-lib.h>


#define CLOCKS_TYPE_CLOCK (clocks_clock_get_type ())
#define CLOCKS_CLOCK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLOCKS_TYPE_CLOCK, ClocksClock))
#define CLOCKS_IS_CLOCK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLOCKS_TYPE_CLOCK))
#define CLOCKS_CLOCK_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), CLOCKS_TYPE_CLOCK, ClocksClockIface))

typedef struct _ClocksClock ClocksClock;
typedef struct _ClocksClockIface ClocksClockIface;

#define CLOCKS_TYPE_HEADER_BAR (clocks_header_bar_get_type ())
#define CLOCKS_HEADER_BAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLOCKS_TYPE_HEADER_BAR, ClocksHeaderBar))
#define CLOCKS_HEADER_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CLOCKS_TYPE_HEADER_BAR, ClocksHeaderBarClass))
#define CLOCKS_IS_HEADER_BAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLOCKS_TYPE_HEADER_BAR))
#define CLOCKS_IS_HEADER_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CLOCKS_TYPE_HEADER_BAR))
#define CLOCKS_HEADER_BAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CLOCKS_TYPE_HEADER_BAR, ClocksHeaderBarClass))

typedef struct _ClocksHeaderBar ClocksHeaderBar;
typedef struct _ClocksHeaderBarClass ClocksHeaderBarClass;

#define CLOCKS_TIMER_TYPE_MAIN_PANEL (clocks_timer_main_panel_get_type ())
#define CLOCKS_TIMER_MAIN_PANEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLOCKS_TIMER_TYPE_MAIN_PANEL, ClocksTimerMainPanel))
#define CLOCKS_TIMER_MAIN_PANEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CLOCKS_TIMER_TYPE_MAIN_PANEL, ClocksTimerMainPanelClass))
#define CLOCKS_TIMER_IS_MAIN_PANEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLOCKS_TIMER_TYPE_MAIN_PANEL))
#define CLOCKS_TIMER_IS_MAIN_PANEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CLOCKS_TIMER_TYPE_MAIN_PANEL))
#define CLOCKS_TIMER_MAIN_PANEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CLOCKS_TIMER_TYPE_MAIN_PANEL, ClocksTimerMainPanelClass))

typedef struct _ClocksTimerMainPanel ClocksTimerMainPanel;
typedef struct _ClocksTimerMainPanelClass ClocksTimerMainPanelClass;
typedef struct _ClocksTimerMainPanelPrivate ClocksTimerMainPanelPrivate;

#define CLOCKS_TIMER_MAIN_PANEL_TYPE_STATE (clocks_timer_main_panel_state_get_type ())

#define CLOCKS_UTILS_TYPE_BELL (clocks_utils_bell_get_type ())
#define CLOCKS_UTILS_BELL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLOCKS_UTILS_TYPE_BELL, ClocksUtilsBell))
#define CLOCKS_UTILS_BELL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CLOCKS_UTILS_TYPE_BELL, ClocksUtilsBellClass))
#define CLOCKS_UTILS_IS_BELL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLOCKS_UTILS_TYPE_BELL))
#define CLOCKS_UTILS_IS_BELL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CLOCKS_UTILS_TYPE_BELL))
#define CLOCKS_UTILS_BELL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CLOCKS_UTILS_TYPE_BELL, ClocksUtilsBellClass))

typedef struct _ClocksUtilsBell ClocksUtilsBell;
typedef struct _ClocksUtilsBellClass ClocksUtilsBellClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_timer_destroy0(var) ((var == NULL) ? NULL : (var = (g_timer_destroy (var), NULL)))

struct _ClocksClockIface {
	GTypeInterface parent_iface;
	void (*activate_new) (ClocksClock* self);
	void (*activate_select_all) (ClocksClock* self);
	void (*activate_select_none) (ClocksClock* self);
	gboolean (*escape_pressed) (ClocksClock* self);
	void (*update_header_bar) (ClocksClock* self);
	const gchar* (*get_label) (ClocksClock* self);
	void (*set_label) (ClocksClock* self, const gchar* value);
	ClocksHeaderBar* (*get_header_bar) (ClocksClock* self);
	void (*set_header_bar) (ClocksClock* self, ClocksHeaderBar* value);
};

struct _ClocksTimerMainPanel {
	GdStack parent_instance;
	ClocksTimerMainPanelPrivate * priv;
};

struct _ClocksTimerMainPanelClass {
	GdStackClass parent_class;
	void (*ring) (ClocksTimerMainPanel* self);
};

typedef enum  {
	CLOCKS_TIMER_MAIN_PANEL_STATE_STOPPED,
	CLOCKS_TIMER_MAIN_PANEL_STATE_RUNNING,
	CLOCKS_TIMER_MAIN_PANEL_STATE_PAUSED
} ClocksTimerMainPanelState;

struct _ClocksTimerMainPanelPrivate {
	gchar* _label;
	ClocksHeaderBar* _header_bar;
	ClocksTimerMainPanelState state;
	GSettings* settings;
	guint timeout_id;
	ClocksUtilsBell* bell;
	GtkWidget* setup_panel;
	GtkSpinButton* h_spinbutton;
	GtkSpinButton* m_spinbutton;
	GtkSpinButton* s_spinbutton;
	GtkButton* start_button;
	GtkWidget* countdown_panel;
	GtkLabel* time_label;
	GtkButton* left_button;
	GtkButton* right_button;
	gdouble span;
	GTimer* timer;
};


static gpointer clocks_timer_main_panel_parent_class = NULL;
static ClocksClockIface* clocks_timer_main_panel_clocks_clock_parent_iface = NULL;

GType clocks_header_bar_get_type (void) G_GNUC_CONST;
GType clocks_clock_get_type (void) G_GNUC_CONST;
GType clocks_timer_main_panel_get_type (void) G_GNUC_CONST;
static GType clocks_timer_main_panel_state_get_type (void) G_GNUC_UNUSED;
GType clocks_utils_bell_get_type (void) G_GNUC_CONST;
#define CLOCKS_TIMER_MAIN_PANEL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), CLOCKS_TIMER_TYPE_MAIN_PANEL, ClocksTimerMainPanelPrivate))
enum  {
	CLOCKS_TIMER_MAIN_PANEL_DUMMY_PROPERTY,
	CLOCKS_TIMER_MAIN_PANEL_LABEL,
	CLOCKS_TIMER_MAIN_PANEL_HEADER_BAR
};
ClocksTimerMainPanel* clocks_timer_main_panel_new (ClocksHeaderBar* header_bar);
ClocksTimerMainPanel* clocks_timer_main_panel_construct (GType object_type, ClocksHeaderBar* header_bar);
ClocksUtilsBell* clocks_utils_bell_new (const gchar* soundid, const gchar* title, const gchar* msg);
ClocksUtilsBell* clocks_utils_bell_construct (GType object_type, const gchar* soundid, const gchar* title, const gchar* msg);
GtkBuilder* clocks_utils_load_ui (const gchar* ui);
static gboolean clocks_timer_main_panel_show_leading_zeros (ClocksTimerMainPanel* self, GtkSpinButton* spin_button);
static gboolean _clocks_timer_main_panel_show_leading_zeros_gtk_spin_button_output (GtkSpinButton* _sender, gpointer self);
static void clocks_timer_main_panel_update_start_button (ClocksTimerMainPanel* self);
static void _clocks_timer_main_panel_update_start_button_gtk_spin_button_value_changed (GtkSpinButton* _sender, gpointer self);
static void __lambda46_ (ClocksTimerMainPanel* self);
static void clocks_timer_main_panel_start (ClocksTimerMainPanel* self);
static void ___lambda46__gtk_button_clicked (GtkButton* _sender, gpointer self);
static void __lambda47_ (ClocksTimerMainPanel* self);
static void clocks_timer_main_panel_pause (ClocksTimerMainPanel* self);
static void clocks_timer_main_panel_restart (ClocksTimerMainPanel* self);
static void ___lambda47__gtk_button_clicked (GtkButton* _sender, gpointer self);
static void __lambda48_ (ClocksTimerMainPanel* self);
static void clocks_timer_main_panel_reset (ClocksTimerMainPanel* self);
static void ___lambda48__gtk_button_clicked (GtkButton* _sender, gpointer self);
static void clocks_timer_main_panel_remove_timeout (ClocksTimerMainPanel* self);
static void clocks_timer_main_panel_update_countdown_label (ClocksTimerMainPanel* self, gint h, gint m, gint s);
static void clocks_timer_main_panel_add_timeout (ClocksTimerMainPanel* self);
static gboolean clocks_timer_main_panel_count (ClocksTimerMainPanel* self);
static gboolean _clocks_timer_main_panel_count_gsource_func (gpointer self);
static void clocks_timer_main_panel_update_countdown (ClocksTimerMainPanel* self, gdouble t);
void clocks_utils_time_to_hms (gdouble t, gint* h, gint* m, gint* s, gdouble* remainder);
static void clocks_timer_main_panel_real_grab_focus (GtkWidget* base);
static void clocks_timer_main_panel_real_ring (ClocksTimerMainPanel* self);
void clocks_utils_bell_ring_once (ClocksUtilsBell* self);
static void clocks_timer_main_panel_finalize (GObject* obj);
const gchar* clocks_clock_get_label (ClocksClock* self);
ClocksHeaderBar* clocks_clock_get_header_bar (ClocksClock* self);
static void _vala_clocks_timer_main_panel_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
void clocks_clock_set_label (ClocksClock* self, const gchar* value);
void clocks_clock_set_header_bar (ClocksClock* self, ClocksHeaderBar* value);
static void _vala_clocks_timer_main_panel_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static GType clocks_timer_main_panel_state_get_type (void) {
	static volatile gsize clocks_timer_main_panel_state_type_id__volatile = 0;
	if (g_once_init_enter (&clocks_timer_main_panel_state_type_id__volatile)) {
		static const GEnumValue values[] = {{CLOCKS_TIMER_MAIN_PANEL_STATE_STOPPED, "CLOCKS_TIMER_MAIN_PANEL_STATE_STOPPED", "stopped"}, {CLOCKS_TIMER_MAIN_PANEL_STATE_RUNNING, "CLOCKS_TIMER_MAIN_PANEL_STATE_RUNNING", "running"}, {CLOCKS_TIMER_MAIN_PANEL_STATE_PAUSED, "CLOCKS_TIMER_MAIN_PANEL_STATE_PAUSED", "paused"}, {0, NULL, NULL}};
		GType clocks_timer_main_panel_state_type_id;
		clocks_timer_main_panel_state_type_id = g_enum_register_static ("ClocksTimerMainPanelState", values);
		g_once_init_leave (&clocks_timer_main_panel_state_type_id__volatile, clocks_timer_main_panel_state_type_id);
	}
	return clocks_timer_main_panel_state_type_id__volatile;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean _clocks_timer_main_panel_show_leading_zeros_gtk_spin_button_output (GtkSpinButton* _sender, gpointer self) {
	gboolean result;
	result = clocks_timer_main_panel_show_leading_zeros (self, _sender);
	return result;
}


static void _clocks_timer_main_panel_update_start_button_gtk_spin_button_value_changed (GtkSpinButton* _sender, gpointer self) {
	clocks_timer_main_panel_update_start_button (self);
}


static void __lambda46_ (ClocksTimerMainPanel* self) {
	clocks_timer_main_panel_start (self);
}


static void ___lambda46__gtk_button_clicked (GtkButton* _sender, gpointer self) {
	__lambda46_ (self);
}


static void __lambda47_ (ClocksTimerMainPanel* self) {
	ClocksTimerMainPanelState _tmp0_;
	_tmp0_ = self->priv->state;
	switch (_tmp0_) {
		case CLOCKS_TIMER_MAIN_PANEL_STATE_RUNNING:
		{
			GtkButton* _tmp1_;
			const gchar* _tmp2_ = NULL;
			GtkButton* _tmp3_;
			GtkStyleContext* _tmp4_ = NULL;
			clocks_timer_main_panel_pause (self);
			_tmp1_ = self->priv->left_button;
			_tmp2_ = _ ("Continue");
			gtk_button_set_label (_tmp1_, _tmp2_);
			_tmp3_ = self->priv->left_button;
			_tmp4_ = gtk_widget_get_style_context ((GtkWidget*) _tmp3_);
			gtk_style_context_add_class (_tmp4_, "clocks-go");
			break;
		}
		case CLOCKS_TIMER_MAIN_PANEL_STATE_PAUSED:
		{
			GtkButton* _tmp5_;
			const gchar* _tmp6_ = NULL;
			GtkButton* _tmp7_;
			GtkStyleContext* _tmp8_ = NULL;
			clocks_timer_main_panel_restart (self);
			_tmp5_ = self->priv->left_button;
			_tmp6_ = _ ("Pause");
			gtk_button_set_label (_tmp5_, _tmp6_);
			_tmp7_ = self->priv->left_button;
			_tmp8_ = gtk_widget_get_style_context ((GtkWidget*) _tmp7_);
			gtk_style_context_remove_class (_tmp8_, "clocks-go");
			break;
		}
		default:
		{
			g_assert_not_reached ();
		}
	}
}


static void ___lambda47__gtk_button_clicked (GtkButton* _sender, gpointer self) {
	__lambda47_ (self);
}


static void __lambda48_ (ClocksTimerMainPanel* self) {
	GtkButton* _tmp0_;
	const gchar* _tmp1_ = NULL;
	clocks_timer_main_panel_reset (self);
	_tmp0_ = self->priv->left_button;
	_tmp1_ = _ ("Pause");
	gtk_button_set_label (_tmp0_, _tmp1_);
}


static void ___lambda48__gtk_button_clicked (GtkButton* _sender, gpointer self) {
	__lambda48_ (self);
}


ClocksTimerMainPanel* clocks_timer_main_panel_construct (GType object_type, ClocksHeaderBar* header_bar) {
	ClocksTimerMainPanel * self = NULL;
	const gchar* _tmp0_ = NULL;
	ClocksHeaderBar* _tmp1_;
	GSettings* _tmp2_;
	const gchar* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	ClocksUtilsBell* _tmp5_;
	GTimer* _tmp6_;
	GtkBuilder* _tmp7_ = NULL;
	GtkBuilder* builder;
	GObject* _tmp8_ = NULL;
	GtkWidget* _tmp9_;
	GObject* _tmp10_ = NULL;
	GtkSpinButton* _tmp11_;
	GObject* _tmp12_ = NULL;
	GtkSpinButton* _tmp13_;
	GObject* _tmp14_ = NULL;
	GtkSpinButton* _tmp15_;
	GObject* _tmp16_ = NULL;
	GtkButton* _tmp17_;
	GtkSpinButton* _tmp18_;
	GtkSpinButton* _tmp19_;
	GtkSpinButton* _tmp20_;
	GtkSpinButton* _tmp21_;
	GtkSpinButton* _tmp22_;
	GtkSpinButton* _tmp23_;
	GtkButton* _tmp24_;
	GObject* _tmp25_ = NULL;
	GtkWidget* _tmp26_;
	GObject* _tmp27_ = NULL;
	GtkLabel* _tmp28_;
	GObject* _tmp29_ = NULL;
	GtkButton* _tmp30_;
	GObject* _tmp31_ = NULL;
	GtkButton* _tmp32_;
	GtkButton* _tmp33_;
	GtkButton* _tmp34_;
	GtkWidget* _tmp35_;
	GtkWidget* _tmp36_;
	GtkWidget* _tmp37_;
	g_return_val_if_fail (header_bar != NULL, NULL);
	_tmp0_ = _ ("Timer");
	_tmp1_ = header_bar;
	self = (ClocksTimerMainPanel*) g_object_new (object_type, "label", _tmp0_, "header-bar", _tmp1_, "transition-type", GD_STACK_TRANSITION_TYPE_CROSSFADE, NULL);
	_tmp2_ = g_settings_new ("org.gnome.clocks");
	_g_object_unref0 (self->priv->settings);
	self->priv->settings = _tmp2_;
	_tmp3_ = _ ("Time is up!");
	_tmp4_ = _ ("Timer countdown finished");
	_tmp5_ = clocks_utils_bell_new ("complete", _tmp3_, _tmp4_);
	_g_object_unref0 (self->priv->bell);
	self->priv->bell = _tmp5_;
	self->priv->timeout_id = (guint) 0;
	self->priv->span = (gdouble) 0;
	_tmp6_ = g_timer_new ();
	_g_timer_destroy0 (self->priv->timer);
	self->priv->timer = _tmp6_;
	_tmp7_ = clocks_utils_load_ui ("timer.ui");
	builder = _tmp7_;
	_tmp8_ = gtk_builder_get_object (builder, "setup_panel");
	_tmp9_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp8_, GTK_TYPE_WIDGET) ? ((GtkWidget*) _tmp8_) : NULL);
	_g_object_unref0 (self->priv->setup_panel);
	self->priv->setup_panel = _tmp9_;
	_tmp10_ = gtk_builder_get_object (builder, "spinbutton_hours");
	_tmp11_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp10_, GTK_TYPE_SPIN_BUTTON) ? ((GtkSpinButton*) _tmp10_) : NULL);
	_g_object_unref0 (self->priv->h_spinbutton);
	self->priv->h_spinbutton = _tmp11_;
	_tmp12_ = gtk_builder_get_object (builder, "spinbutton_minutes");
	_tmp13_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp12_, GTK_TYPE_SPIN_BUTTON) ? ((GtkSpinButton*) _tmp12_) : NULL);
	_g_object_unref0 (self->priv->m_spinbutton);
	self->priv->m_spinbutton = _tmp13_;
	_tmp14_ = gtk_builder_get_object (builder, "spinbutton_seconds");
	_tmp15_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp14_, GTK_TYPE_SPIN_BUTTON) ? ((GtkSpinButton*) _tmp14_) : NULL);
	_g_object_unref0 (self->priv->s_spinbutton);
	self->priv->s_spinbutton = _tmp15_;
	_tmp16_ = gtk_builder_get_object (builder, "start_button");
	_tmp17_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp16_, GTK_TYPE_BUTTON) ? ((GtkButton*) _tmp16_) : NULL);
	_g_object_unref0 (self->priv->start_button);
	self->priv->start_button = _tmp17_;
	_tmp18_ = self->priv->h_spinbutton;
	g_signal_connect_object (_tmp18_, "output", (GCallback) _clocks_timer_main_panel_show_leading_zeros_gtk_spin_button_output, self, 0);
	_tmp19_ = self->priv->m_spinbutton;
	g_signal_connect_object (_tmp19_, "output", (GCallback) _clocks_timer_main_panel_show_leading_zeros_gtk_spin_button_output, self, 0);
	_tmp20_ = self->priv->s_spinbutton;
	g_signal_connect_object (_tmp20_, "output", (GCallback) _clocks_timer_main_panel_show_leading_zeros_gtk_spin_button_output, self, 0);
	_tmp21_ = self->priv->h_spinbutton;
	g_signal_connect_object (_tmp21_, "value-changed", (GCallback) _clocks_timer_main_panel_update_start_button_gtk_spin_button_value_changed, self, 0);
	_tmp22_ = self->priv->m_spinbutton;
	g_signal_connect_object (_tmp22_, "value-changed", (GCallback) _clocks_timer_main_panel_update_start_button_gtk_spin_button_value_changed, self, 0);
	_tmp23_ = self->priv->s_spinbutton;
	g_signal_connect_object (_tmp23_, "value-changed", (GCallback) _clocks_timer_main_panel_update_start_button_gtk_spin_button_value_changed, self, 0);
	_tmp24_ = self->priv->start_button;
	g_signal_connect_object (_tmp24_, "clicked", (GCallback) ___lambda46__gtk_button_clicked, self, 0);
	_tmp25_ = gtk_builder_get_object (builder, "countdown_panel");
	_tmp26_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp25_, GTK_TYPE_WIDGET) ? ((GtkWidget*) _tmp25_) : NULL);
	_g_object_unref0 (self->priv->countdown_panel);
	self->priv->countdown_panel = _tmp26_;
	_tmp27_ = gtk_builder_get_object (builder, "time_label");
	_tmp28_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp27_, GTK_TYPE_LABEL) ? ((GtkLabel*) _tmp27_) : NULL);
	_g_object_unref0 (self->priv->time_label);
	self->priv->time_label = _tmp28_;
	_tmp29_ = gtk_builder_get_object (builder, "left_button");
	_tmp30_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp29_, GTK_TYPE_BUTTON) ? ((GtkButton*) _tmp29_) : NULL);
	_g_object_unref0 (self->priv->left_button);
	self->priv->left_button = _tmp30_;
	_tmp31_ = gtk_builder_get_object (builder, "right_button");
	_tmp32_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp31_, GTK_TYPE_BUTTON) ? ((GtkButton*) _tmp31_) : NULL);
	_g_object_unref0 (self->priv->right_button);
	self->priv->right_button = _tmp32_;
	_tmp33_ = self->priv->left_button;
	g_signal_connect_object (_tmp33_, "clicked", (GCallback) ___lambda47__gtk_button_clicked, self, 0);
	_tmp34_ = self->priv->right_button;
	g_signal_connect_object (_tmp34_, "clicked", (GCallback) ___lambda48__gtk_button_clicked, self, 0);
	_tmp35_ = self->priv->setup_panel;
	gtk_container_add ((GtkContainer*) self, _tmp35_);
	_tmp36_ = self->priv->countdown_panel;
	gtk_container_add ((GtkContainer*) self, _tmp36_);
	clocks_timer_main_panel_reset (self);
	_tmp37_ = self->priv->setup_panel;
	gd_stack_set_visible_child ((GdStack*) self, _tmp37_);
	gtk_widget_show_all ((GtkWidget*) self);
	_g_object_unref0 (builder);
	return self;
}


ClocksTimerMainPanel* clocks_timer_main_panel_new (ClocksHeaderBar* header_bar) {
	return clocks_timer_main_panel_construct (CLOCKS_TIMER_TYPE_MAIN_PANEL, header_bar);
}


static gboolean clocks_timer_main_panel_show_leading_zeros (ClocksTimerMainPanel* self, GtkSpinButton* spin_button) {
	gboolean result = FALSE;
	GtkSpinButton* _tmp0_;
	GtkSpinButton* _tmp1_;
	gint _tmp2_ = 0;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (spin_button != NULL, FALSE);
	_tmp0_ = spin_button;
	_tmp1_ = spin_button;
	_tmp2_ = gtk_spin_button_get_value_as_int (_tmp1_);
	_tmp3_ = g_strdup_printf ("%02i", _tmp2_);
	_tmp4_ = _tmp3_;
	gtk_entry_set_text ((GtkEntry*) _tmp0_, _tmp4_);
	_g_free0 (_tmp4_);
	result = TRUE;
	return result;
}


static void clocks_timer_main_panel_update_start_button (ClocksTimerMainPanel* self) {
	GtkSpinButton* _tmp0_;
	gint _tmp1_ = 0;
	gint h;
	GtkSpinButton* _tmp2_;
	gint _tmp3_ = 0;
	gint m;
	GtkSpinButton* _tmp4_;
	gint _tmp5_ = 0;
	gint s;
	gboolean _tmp6_ = FALSE;
	gboolean _tmp7_ = FALSE;
	gint _tmp8_;
	gboolean _tmp10_;
	gboolean _tmp12_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->h_spinbutton;
	_tmp1_ = gtk_spin_button_get_value_as_int (_tmp0_);
	h = _tmp1_;
	_tmp2_ = self->priv->m_spinbutton;
	_tmp3_ = gtk_spin_button_get_value_as_int (_tmp2_);
	m = _tmp3_;
	_tmp4_ = self->priv->s_spinbutton;
	_tmp5_ = gtk_spin_button_get_value_as_int (_tmp4_);
	s = _tmp5_;
	_tmp8_ = h;
	if (_tmp8_ != 0) {
		_tmp7_ = TRUE;
	} else {
		gint _tmp9_;
		_tmp9_ = m;
		_tmp7_ = _tmp9_ != 0;
	}
	_tmp10_ = _tmp7_;
	if (_tmp10_) {
		_tmp6_ = TRUE;
	} else {
		gint _tmp11_;
		_tmp11_ = s;
		_tmp6_ = _tmp11_ != 0;
	}
	_tmp12_ = _tmp6_;
	if (_tmp12_) {
		GtkButton* _tmp13_;
		GtkButton* _tmp14_;
		GtkStyleContext* _tmp15_ = NULL;
		_tmp13_ = self->priv->start_button;
		gtk_widget_set_sensitive ((GtkWidget*) _tmp13_, TRUE);
		_tmp14_ = self->priv->start_button;
		_tmp15_ = gtk_widget_get_style_context ((GtkWidget*) _tmp14_);
		gtk_style_context_add_class (_tmp15_, "clocks-go");
	} else {
		GtkButton* _tmp16_;
		GtkButton* _tmp17_;
		GtkStyleContext* _tmp18_ = NULL;
		_tmp16_ = self->priv->start_button;
		gtk_widget_set_sensitive ((GtkWidget*) _tmp16_, FALSE);
		_tmp17_ = self->priv->start_button;
		_tmp18_ = gtk_widget_get_style_context ((GtkWidget*) _tmp17_);
		gtk_style_context_remove_class (_tmp18_, "clocks-go");
	}
}


static void clocks_timer_main_panel_reset (ClocksTimerMainPanel* self) {
	GTimer* _tmp0_;
	GSettings* _tmp1_;
	guint _tmp2_ = 0U;
	GtkSpinButton* _tmp3_;
	gdouble _tmp4_;
	GtkSpinButton* _tmp5_;
	gdouble _tmp6_;
	GtkSpinButton* _tmp7_;
	gdouble _tmp8_;
	GtkButton* _tmp9_;
	gdouble _tmp10_;
	GtkWidget* _tmp11_;
	g_return_if_fail (self != NULL);
	self->priv->state = CLOCKS_TIMER_MAIN_PANEL_STATE_STOPPED;
	_tmp0_ = self->priv->timer;
	g_timer_reset (_tmp0_);
	clocks_timer_main_panel_remove_timeout (self);
	_tmp1_ = self->priv->settings;
	_tmp2_ = g_settings_get_uint (_tmp1_, "timer");
	self->priv->span = (gdouble) _tmp2_;
	_tmp3_ = self->priv->h_spinbutton;
	_tmp4_ = self->priv->span;
	gtk_spin_button_set_value (_tmp3_, (gdouble) (((gint) _tmp4_) / 3600));
	_tmp5_ = self->priv->m_spinbutton;
	_tmp6_ = self->priv->span;
	gtk_spin_button_set_value (_tmp5_, (gdouble) (((gint) _tmp6_) / 60));
	_tmp7_ = self->priv->s_spinbutton;
	_tmp8_ = self->priv->span;
	gtk_spin_button_set_value (_tmp7_, fmod (_tmp8_, 60));
	_tmp9_ = self->priv->start_button;
	_tmp10_ = self->priv->span;
	gtk_widget_set_sensitive ((GtkWidget*) _tmp9_, _tmp10_ > ((gdouble) 0));
	_tmp11_ = self->priv->setup_panel;
	gd_stack_set_visible_child ((GdStack*) self, _tmp11_);
}


static void clocks_timer_main_panel_start (ClocksTimerMainPanel* self) {
	gboolean _tmp0_ = FALSE;
	ClocksTimerMainPanelState _tmp1_;
	gboolean _tmp3_;
	g_return_if_fail (self != NULL);
	_tmp1_ = self->priv->state;
	if (_tmp1_ == CLOCKS_TIMER_MAIN_PANEL_STATE_STOPPED) {
		guint _tmp2_;
		_tmp2_ = self->priv->timeout_id;
		_tmp0_ = _tmp2_ == ((guint) 0);
	} else {
		_tmp0_ = FALSE;
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		GtkSpinButton* _tmp4_;
		gint _tmp5_ = 0;
		gint h;
		GtkSpinButton* _tmp6_;
		gint _tmp7_ = 0;
		gint m;
		GtkSpinButton* _tmp8_;
		gint _tmp9_ = 0;
		gint s;
		gint _tmp10_;
		gint _tmp11_;
		gint _tmp12_;
		GSettings* _tmp13_;
		gdouble _tmp14_;
		GTimer* _tmp15_;
		GtkWidget* _tmp16_;
		gint _tmp17_;
		gint _tmp18_;
		gint _tmp19_;
		_tmp4_ = self->priv->h_spinbutton;
		_tmp5_ = gtk_spin_button_get_value_as_int (_tmp4_);
		h = _tmp5_;
		_tmp6_ = self->priv->m_spinbutton;
		_tmp7_ = gtk_spin_button_get_value_as_int (_tmp6_);
		m = _tmp7_;
		_tmp8_ = self->priv->s_spinbutton;
		_tmp9_ = gtk_spin_button_get_value_as_int (_tmp8_);
		s = _tmp9_;
		self->priv->state = CLOCKS_TIMER_MAIN_PANEL_STATE_RUNNING;
		_tmp10_ = h;
		_tmp11_ = m;
		_tmp12_ = s;
		self->priv->span = (gdouble) (((_tmp10_ * 3600) + (_tmp11_ * 60)) + _tmp12_);
		_tmp13_ = self->priv->settings;
		_tmp14_ = self->priv->span;
		g_settings_set_uint (_tmp13_, "timer", (guint) _tmp14_);
		_tmp15_ = self->priv->timer;
		g_timer_start (_tmp15_);
		_tmp16_ = self->priv->countdown_panel;
		gd_stack_set_visible_child ((GdStack*) self, _tmp16_);
		_tmp17_ = h;
		_tmp18_ = m;
		_tmp19_ = s;
		clocks_timer_main_panel_update_countdown_label (self, _tmp17_, _tmp18_, _tmp19_);
		clocks_timer_main_panel_add_timeout (self);
	}
}


static void clocks_timer_main_panel_restart (ClocksTimerMainPanel* self) {
	GTimer* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->state = CLOCKS_TIMER_MAIN_PANEL_STATE_RUNNING;
	_tmp0_ = self->priv->timer;
	g_timer_start (_tmp0_);
	clocks_timer_main_panel_add_timeout (self);
}


static void clocks_timer_main_panel_pause (ClocksTimerMainPanel* self) {
	GTimer* _tmp0_;
	gdouble _tmp1_;
	GTimer* _tmp2_;
	gdouble _tmp3_ = 0.0;
	g_return_if_fail (self != NULL);
	self->priv->state = CLOCKS_TIMER_MAIN_PANEL_STATE_PAUSED;
	_tmp0_ = self->priv->timer;
	g_timer_stop (_tmp0_);
	_tmp1_ = self->priv->span;
	_tmp2_ = self->priv->timer;
	_tmp3_ = g_timer_elapsed (_tmp2_, NULL);
	self->priv->span = _tmp1_ - _tmp3_;
	clocks_timer_main_panel_remove_timeout (self);
}


static gboolean _clocks_timer_main_panel_count_gsource_func (gpointer self) {
	gboolean result;
	result = clocks_timer_main_panel_count (self);
	return result;
}


static void clocks_timer_main_panel_add_timeout (ClocksTimerMainPanel* self) {
	guint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->timeout_id;
	if (_tmp0_ == ((guint) 0)) {
		guint _tmp1_ = 0U;
		_tmp1_ = g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 100, _clocks_timer_main_panel_count_gsource_func, g_object_ref (self), g_object_unref);
		self->priv->timeout_id = _tmp1_;
	}
}


static void clocks_timer_main_panel_remove_timeout (ClocksTimerMainPanel* self) {
	guint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->timeout_id;
	if (_tmp0_ != ((guint) 0)) {
		guint _tmp1_;
		_tmp1_ = self->priv->timeout_id;
		g_source_remove (_tmp1_);
		self->priv->timeout_id = (guint) 0;
	}
}


static gboolean clocks_timer_main_panel_count (ClocksTimerMainPanel* self) {
	gboolean result = FALSE;
	GTimer* _tmp0_;
	gdouble _tmp1_ = 0.0;
	gdouble e;
	gdouble _tmp2_;
	gdouble _tmp3_;
	gdouble _tmp5_;
	gdouble _tmp6_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->timer;
	_tmp1_ = g_timer_elapsed (_tmp0_, NULL);
	e = _tmp1_;
	_tmp2_ = e;
	_tmp3_ = self->priv->span;
	if (_tmp2_ >= _tmp3_) {
		GtkWidget* _tmp4_;
		g_signal_emit_by_name (self, "ring");
		self->priv->state = CLOCKS_TIMER_MAIN_PANEL_STATE_STOPPED;
		clocks_timer_main_panel_remove_timeout (self);
		clocks_timer_main_panel_update_countdown_label (self, 0, 0, 0);
		_tmp4_ = self->priv->setup_panel;
		gd_stack_set_visible_child ((GdStack*) self, _tmp4_);
		result = FALSE;
		return result;
	}
	_tmp5_ = self->priv->span;
	_tmp6_ = e;
	clocks_timer_main_panel_update_countdown (self, _tmp5_ - _tmp6_);
	result = TRUE;
	return result;
}


static void clocks_timer_main_panel_update_countdown (ClocksTimerMainPanel* self, gdouble t) {
	GtkLabel* _tmp0_;
	gboolean _tmp1_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->time_label;
	_tmp1_ = gtk_widget_get_mapped ((GtkWidget*) _tmp0_);
	if (_tmp1_) {
		gdouble _tmp2_;
		gdouble _tmp3_ = 0.0;
		gint h = 0;
		gint m = 0;
		gint s = 0;
		gdouble r = 0.0;
		gdouble _tmp4_;
		gint _tmp5_ = 0;
		gint _tmp6_ = 0;
		gint _tmp7_ = 0;
		gdouble _tmp8_ = 0.0;
		gint _tmp9_;
		gint _tmp10_;
		gint _tmp11_;
		_tmp2_ = t;
		_tmp3_ = ceil (_tmp2_);
		t = _tmp3_;
		_tmp4_ = t;
		clocks_utils_time_to_hms (_tmp4_, &_tmp5_, &_tmp6_, &_tmp7_, &_tmp8_);
		h = _tmp5_;
		m = _tmp6_;
		s = _tmp7_;
		r = _tmp8_;
		_tmp9_ = h;
		_tmp10_ = m;
		_tmp11_ = s;
		clocks_timer_main_panel_update_countdown_label (self, _tmp9_, _tmp10_, _tmp11_);
	}
}


static void clocks_timer_main_panel_update_countdown_label (ClocksTimerMainPanel* self, gint h, gint m, gint s) {
	GtkLabel* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	gchar* _tmp4_ = NULL;
	gchar* _tmp5_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->time_label;
	_tmp1_ = h;
	_tmp2_ = m;
	_tmp3_ = s;
	_tmp4_ = g_strdup_printf ("%02i∶%02i∶%02i", _tmp1_, _tmp2_, _tmp3_);
	_tmp5_ = _tmp4_;
	gtk_label_set_text (_tmp0_, _tmp5_);
	_g_free0 (_tmp5_);
}


static void clocks_timer_main_panel_real_grab_focus (GtkWidget* base) {
	ClocksTimerMainPanel * self;
	GtkWidget* _tmp0_;
	GtkWidget* _tmp1_;
	GtkWidget* _tmp2_;
	self = (ClocksTimerMainPanel*) base;
	_tmp0_ = gd_stack_get_visible_child ((GdStack*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = self->priv->setup_panel;
	if (_tmp1_ == _tmp2_) {
		GtkButton* _tmp3_;
		_tmp3_ = self->priv->start_button;
		gtk_widget_grab_focus ((GtkWidget*) _tmp3_);
	}
}


static const gchar* clocks_timer_main_panel_real_get_label (ClocksClock* base) {
	const gchar* result;
	ClocksTimerMainPanel* self;
	const gchar* _tmp0_;
	self = (ClocksTimerMainPanel*) base;
	_tmp0_ = self->priv->_label;
	result = _tmp0_;
	return result;
}


static void clocks_timer_main_panel_real_set_label (ClocksClock* base, const gchar* value) {
	ClocksTimerMainPanel* self;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	self = (ClocksTimerMainPanel*) base;
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_label);
	self->priv->_label = _tmp1_;
	g_object_notify ((GObject *) self, "label");
}


static ClocksHeaderBar* clocks_timer_main_panel_real_get_header_bar (ClocksClock* base) {
	ClocksHeaderBar* result;
	ClocksTimerMainPanel* self;
	ClocksHeaderBar* _tmp0_;
	self = (ClocksTimerMainPanel*) base;
	_tmp0_ = self->priv->_header_bar;
	result = _tmp0_;
	return result;
}


static void clocks_timer_main_panel_real_set_header_bar (ClocksClock* base, ClocksHeaderBar* value) {
	ClocksTimerMainPanel* self;
	ClocksHeaderBar* _tmp0_;
	ClocksHeaderBar* _tmp1_;
	self = (ClocksTimerMainPanel*) base;
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_header_bar);
	self->priv->_header_bar = _tmp1_;
	g_object_notify ((GObject *) self, "header-bar");
}


static void clocks_timer_main_panel_real_ring (ClocksTimerMainPanel* self) {
	ClocksUtilsBell* _tmp0_;
	_tmp0_ = self->priv->bell;
	clocks_utils_bell_ring_once (_tmp0_);
}


static void clocks_timer_main_panel_class_init (ClocksTimerMainPanelClass * klass) {
	clocks_timer_main_panel_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (ClocksTimerMainPanelPrivate));
	GTK_WIDGET_CLASS (klass)->grab_focus = clocks_timer_main_panel_real_grab_focus;
	CLOCKS_TIMER_MAIN_PANEL_CLASS (klass)->ring = clocks_timer_main_panel_real_ring;
	G_OBJECT_CLASS (klass)->get_property = _vala_clocks_timer_main_panel_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_clocks_timer_main_panel_set_property;
	G_OBJECT_CLASS (klass)->finalize = clocks_timer_main_panel_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), CLOCKS_TIMER_MAIN_PANEL_LABEL, g_param_spec_string ("label", "label", "label", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
	g_object_class_install_property (G_OBJECT_CLASS (klass), CLOCKS_TIMER_MAIN_PANEL_HEADER_BAR, g_param_spec_object ("header-bar", "header-bar", "header-bar", CLOCKS_TYPE_HEADER_BAR, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
	g_signal_new ("ring", CLOCKS_TIMER_TYPE_MAIN_PANEL, G_SIGNAL_RUN_LAST, G_STRUCT_OFFSET (ClocksTimerMainPanelClass, ring), NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}


static void clocks_timer_main_panel_clocks_clock_interface_init (ClocksClockIface * iface) {
	clocks_timer_main_panel_clocks_clock_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_label = clocks_timer_main_panel_real_get_label;
	iface->set_label = clocks_timer_main_panel_real_set_label;
	iface->get_header_bar = clocks_timer_main_panel_real_get_header_bar;
	iface->set_header_bar = clocks_timer_main_panel_real_set_header_bar;
}


static void clocks_timer_main_panel_instance_init (ClocksTimerMainPanel * self) {
	self->priv = CLOCKS_TIMER_MAIN_PANEL_GET_PRIVATE (self);
}


static void clocks_timer_main_panel_finalize (GObject* obj) {
	ClocksTimerMainPanel * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, CLOCKS_TIMER_TYPE_MAIN_PANEL, ClocksTimerMainPanel);
	_g_free0 (self->priv->_label);
	_g_object_unref0 (self->priv->_header_bar);
	_g_object_unref0 (self->priv->settings);
	_g_object_unref0 (self->priv->bell);
	_g_object_unref0 (self->priv->setup_panel);
	_g_object_unref0 (self->priv->h_spinbutton);
	_g_object_unref0 (self->priv->m_spinbutton);
	_g_object_unref0 (self->priv->s_spinbutton);
	_g_object_unref0 (self->priv->start_button);
	_g_object_unref0 (self->priv->countdown_panel);
	_g_object_unref0 (self->priv->time_label);
	_g_object_unref0 (self->priv->left_button);
	_g_object_unref0 (self->priv->right_button);
	_g_timer_destroy0 (self->priv->timer);
	G_OBJECT_CLASS (clocks_timer_main_panel_parent_class)->finalize (obj);
}


GType clocks_timer_main_panel_get_type (void) {
	static volatile gsize clocks_timer_main_panel_type_id__volatile = 0;
	if (g_once_init_enter (&clocks_timer_main_panel_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ClocksTimerMainPanelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) clocks_timer_main_panel_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ClocksTimerMainPanel), 0, (GInstanceInitFunc) clocks_timer_main_panel_instance_init, NULL };
		static const GInterfaceInfo clocks_clock_info = { (GInterfaceInitFunc) clocks_timer_main_panel_clocks_clock_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType clocks_timer_main_panel_type_id;
		clocks_timer_main_panel_type_id = g_type_register_static (gd_stack_get_type (), "ClocksTimerMainPanel", &g_define_type_info, 0);
		g_type_add_interface_static (clocks_timer_main_panel_type_id, CLOCKS_TYPE_CLOCK, &clocks_clock_info);
		g_once_init_leave (&clocks_timer_main_panel_type_id__volatile, clocks_timer_main_panel_type_id);
	}
	return clocks_timer_main_panel_type_id__volatile;
}


static void _vala_clocks_timer_main_panel_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	ClocksTimerMainPanel * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, CLOCKS_TIMER_TYPE_MAIN_PANEL, ClocksTimerMainPanel);
	switch (property_id) {
		case CLOCKS_TIMER_MAIN_PANEL_LABEL:
		g_value_set_string (value, clocks_clock_get_label ((ClocksClock*) self));
		break;
		case CLOCKS_TIMER_MAIN_PANEL_HEADER_BAR:
		g_value_set_object (value, clocks_clock_get_header_bar ((ClocksClock*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_clocks_timer_main_panel_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	ClocksTimerMainPanel * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, CLOCKS_TIMER_TYPE_MAIN_PANEL, ClocksTimerMainPanel);
	switch (property_id) {
		case CLOCKS_TIMER_MAIN_PANEL_LABEL:
		clocks_clock_set_label ((ClocksClock*) self, g_value_get_string (value));
		break;
		case CLOCKS_TIMER_MAIN_PANEL_HEADER_BAR:
		clocks_clock_set_header_bar ((ClocksClock*) self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



