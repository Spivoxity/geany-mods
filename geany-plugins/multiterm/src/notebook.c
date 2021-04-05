/* notebook.c generated by valac 0.34.9, the Vala compiler
 * generated from notebook.vala, do not modify */

/*
 * notebook.vala - This file is part of the Geany MultiTerm plugin
 *
 * Copyright (c) 2012 Matthew Brush <matt@geany.org>.
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include "multiterm.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>
#include <gdk/gdk.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _multi_term_config_unref0(var) ((var == NULL) ? NULL : (var = (multi_term_config_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _multi_term_shell_config_unref0(var) ((var == NULL) ? NULL : (var = (multi_term_shell_config_unref (var), NULL)))

struct _MultiTermNotebookPrivate {
	GtkButton* add_button;
	MultiTermContextMenu* context_menu;
};


static gpointer multi_term_notebook_parent_class = NULL;

#define MULTI_TERM_NOTEBOOK_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), MULTI_TERM_TYPE_NOTEBOOK, MultiTermNotebookPrivate))
enum  {
	MULTI_TERM_NOTEBOOK_DUMMY_PROPERTY
};
static void multi_term_notebook_on_tab_label_close_clicked (MultiTermNotebook* self, gint tab_num);
static void multi_term_notebook_on_show_tabs_activate (MultiTermNotebook* self, gboolean show_tabs);
static gboolean multi_term_notebook_on_next_tab_activate (MultiTermNotebook* self);
static gboolean multi_term_notebook_on_previous_tab_activate (MultiTermNotebook* self);
static void multi_term_notebook_on_new_shell_activate (MultiTermNotebook* self, MultiTermShellConfig* cfg);
static void multi_term_notebook_on_new_window_activate (MultiTermNotebook* self);
static void multi_term_notebook_on_move_to_location (MultiTermNotebook* self, const gchar* location);
static void multi_term_notebook_on_add_button_style_set (MultiTermNotebook* self);
static void multi_term_notebook_on_add_button_clicked (MultiTermNotebook* self);
static gboolean multi_term_notebook_on_terminal_right_click_event (MultiTermNotebook* self, GdkEventButton* event);
static void _multi_term_notebook_on_show_tabs_activate_multi_term_context_menu_show_tabs_activate (MultiTermContextMenu* _sender, gboolean show_tabs, gpointer self);
static gboolean _multi_term_notebook_on_next_tab_activate_multi_term_context_menu_next_tab_activate (MultiTermContextMenu* _sender, gpointer self);
static gboolean _multi_term_notebook_on_previous_tab_activate_multi_term_context_menu_previous_tab_activate (MultiTermContextMenu* _sender, gpointer self);
static void _multi_term_notebook_on_new_shell_activate_multi_term_context_menu_new_shell_activate (MultiTermContextMenu* _sender, MultiTermShellConfig* sh, gpointer self);
static void _multi_term_notebook_on_new_window_activate_multi_term_context_menu_new_window_activate (MultiTermContextMenu* _sender, gpointer self);
static void _multi_term_notebook_on_move_to_location_multi_term_context_menu_move_to_location_activate (MultiTermContextMenu* _sender, const gchar* location, gpointer self);
static void _multi_term_notebook_on_tab_label_close_clicked_multi_term_tab_label_close_clicked (MultiTermTabLabel* _sender, gint tab_num, gpointer self);
static gboolean _multi_term_notebook_on_terminal_right_click_event_multi_term_terminal_right_click_event (MultiTermTerminal* _sender, GdkEventButton* event, gpointer self);
static void _multi_term_notebook_on_add_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self);
static void _multi_term_notebook_on_add_button_style_set_gtk_widget_style_set (GtkWidget* _sender, GtkStyle* previous_style, gpointer self);
static void multi_term_notebook_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static void multi_term_notebook_on_tab_label_close_clicked (MultiTermNotebook* self, gint tab_num) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = gtk_notebook_get_n_pages ((GtkNotebook*) self);
	if (_tmp0_ > 1) {
		gint _tmp1_ = 0;
		_tmp1_ = tab_num;
		multi_term_notebook_remove_terminal (self, _tmp1_);
	}
}


static void multi_term_notebook_on_show_tabs_activate (MultiTermNotebook* self, gboolean show_tabs) {
	gboolean _tmp0_ = FALSE;
	MultiTermConfig* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = show_tabs;
	gtk_notebook_set_show_tabs ((GtkNotebook*) self, _tmp0_);
	_tmp1_ = self->cfg;
	_tmp2_ = show_tabs;
	multi_term_config_set_show_tabs (_tmp1_, _tmp2_);
}


static gboolean multi_term_notebook_on_next_tab_activate (MultiTermNotebook* self) {
	gboolean result = FALSE;
	gint n_tabs = 0;
	gint _tmp0_ = 0;
	gint current = 0;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	gboolean _tmp6_ = FALSE;
	gint _tmp7_ = 0;
	gint _tmp8_ = 0;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = gtk_notebook_get_n_pages ((GtkNotebook*) self);
	n_tabs = _tmp0_;
	_tmp1_ = gtk_notebook_get_current_page ((GtkNotebook*) self);
	current = _tmp1_;
	_tmp2_ = current;
	_tmp3_ = n_tabs;
	if (_tmp2_ < (_tmp3_ - 1)) {
		gint _tmp4_ = 0;
		gint _tmp5_ = 0;
		_tmp4_ = current;
		current = _tmp4_ + 1;
		_tmp5_ = current;
		gtk_notebook_set_current_page ((GtkNotebook*) self, _tmp5_);
	}
	_tmp7_ = current;
	_tmp8_ = n_tabs;
	if (_tmp7_ < (_tmp8_ - 1)) {
		_tmp6_ = TRUE;
	} else {
		_tmp6_ = FALSE;
	}
	result = _tmp6_;
	return result;
}


static gboolean multi_term_notebook_on_previous_tab_activate (MultiTermNotebook* self) {
	gboolean result = FALSE;
	gint current = 0;
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	gboolean _tmp4_ = FALSE;
	gint _tmp5_ = 0;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = gtk_notebook_get_current_page ((GtkNotebook*) self);
	current = _tmp0_;
	_tmp1_ = current;
	if (_tmp1_ > 0) {
		gint _tmp2_ = 0;
		gint _tmp3_ = 0;
		_tmp2_ = current;
		current = _tmp2_ - 1;
		_tmp3_ = current;
		gtk_notebook_set_current_page ((GtkNotebook*) self, _tmp3_);
	}
	_tmp5_ = current;
	if (_tmp5_ > 0) {
		_tmp4_ = TRUE;
	} else {
		_tmp4_ = FALSE;
	}
	result = _tmp4_;
	return result;
}


static void multi_term_notebook_on_new_shell_activate (MultiTermNotebook* self, MultiTermShellConfig* cfg) {
	MultiTermShellConfig* _tmp0_ = NULL;
	MultiTermTerminal* _tmp1_ = NULL;
	MultiTermTerminal* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cfg != NULL);
	_tmp0_ = cfg;
	_tmp1_ = multi_term_notebook_add_terminal (self, _tmp0_);
	_tmp2_ = _tmp1_;
	_g_object_unref0 (_tmp2_);
}


static void multi_term_notebook_on_new_window_activate (MultiTermNotebook* self) {
	GPid pid = 0;
	gchar** args = NULL;
	MultiTermConfig* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar** _tmp3_ = NULL;
	gint args_length1 = 0;
	gint _args_size_ = 0;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->cfg;
	_tmp1_ = multi_term_config_get_external_terminal (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = g_new0 (gchar*, 2 + 1);
	_tmp3_[0] = _tmp2_;
	_tmp3_[1] = NULL;
	args = _tmp3_;
	args_length1 = 2;
	_args_size_ = args_length1;
	{
		gboolean _tmp4_ = FALSE;
		GPid _tmp5_ = 0;
		gboolean _tmp6_ = FALSE;
		_tmp6_ = g_spawn_async (NULL, args, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, &_tmp5_, &_inner_error_);
		pid = _tmp5_;
		_tmp4_ = _tmp6_;
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			if (_inner_error_->domain == G_SPAWN_ERROR) {
				goto __catch5_g_spawn_error;
			}
			args = (_vala_array_free (args, args_length1, (GDestroyNotify) g_free), NULL);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		if (_tmp4_) {
			const gchar* _tmp7_ = NULL;
			_tmp7_ = args[0];
			g_debug ("notebook.vala:87: Started external terminal '%s' with pid of '%d'", _tmp7_, (gint) pid);
		}
	}
	goto __finally5;
	__catch5_g_spawn_error:
	{
		GError* err = NULL;
		const gchar* _tmp8_ = NULL;
		GError* _tmp9_ = NULL;
		const gchar* _tmp10_ = NULL;
		gchar* _tmp11_ = NULL;
		gchar* _tmp12_ = NULL;
		err = _inner_error_;
		_inner_error_ = NULL;
		_tmp8_ = _ ("Unable to launch external terminal: %s");
		_tmp9_ = err;
		_tmp10_ = _tmp9_->message;
		_tmp11_ = g_strdup_printf (_tmp8_, _tmp10_);
		_tmp12_ = _tmp11_;
		g_warning ("notebook.vala:91: %s", _tmp12_);
		_g_free0 (_tmp12_);
		_g_error_free0 (err);
	}
	__finally5:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		args = (_vala_array_free (args, args_length1, (GDestroyNotify) g_free), NULL);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	args = (_vala_array_free (args, args_length1, (GDestroyNotify) g_free), NULL);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void multi_term_notebook_on_move_to_location (MultiTermNotebook* self, const gchar* location) {
	GtkContainer* frame = NULL;
	GtkContainer* _tmp0_ = NULL;
	GtkContainer* _tmp1_ = NULL;
	GtkContainer* parent = NULL;
	GtkContainer* _tmp2_ = NULL;
	GtkContainer* _tmp3_ = NULL;
	GtkContainer* _tmp4_ = NULL;
	GtkNotebook* new_nb = NULL;
	GtkContainer* _tmp5_ = NULL;
	GtkContainer* _tmp6_ = NULL;
	const gchar* _tmp7_ = NULL;
	GtkNotebook* _tmp18_ = NULL;
	GtkNotebook* _tmp19_ = NULL;
	GtkContainer* _tmp20_ = NULL;
	gint _tmp21_ = 0;
	MultiTermConfig* _tmp22_ = NULL;
	const gchar* _tmp23_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (location != NULL);
	_tmp0_ = (GtkContainer*) gtk_widget_get_parent ((GtkWidget*) self);
	_tmp1_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp0_, GTK_TYPE_CONTAINER) ? ((GtkContainer*) _tmp0_) : NULL);
	frame = _tmp1_;
	_tmp2_ = frame;
	_tmp3_ = (GtkContainer*) gtk_widget_get_parent ((GtkWidget*) _tmp2_);
	_tmp4_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp3_, GTK_TYPE_CONTAINER) ? ((GtkContainer*) _tmp3_) : NULL);
	parent = _tmp4_;
	_tmp5_ = parent;
	_tmp6_ = frame;
	gtk_container_remove (_tmp5_, (GtkWidget*) _tmp6_);
	_tmp7_ = location;
	if (g_strcmp0 (_tmp7_, "msgwin") == 0) {
		gconstpointer _tmp8_ = NULL;
		GtkNotebook* _tmp9_ = NULL;
		GtkNotebook* _tmp10_ = NULL;
		GtkContainer* _tmp11_ = NULL;
		gconstpointer _tmp12_ = NULL;
		_tmp8_ = g_object_get_data ((GObject*) self, "msgwin_notebook");
		_tmp9_ = _g_object_ref0 ((GtkNotebook*) ((MultiTermNotebook*) _tmp8_));
		_g_object_unref0 (new_nb);
		new_nb = _tmp9_;
		_tmp10_ = new_nb;
		_tmp11_ = frame;
		_tmp12_ = g_object_get_data ((GObject*) self, "label");
		gtk_notebook_append_page (_tmp10_, (GtkWidget*) _tmp11_, (GtkWidget*) ((GtkLabel*) _tmp12_));
	} else {
		gconstpointer _tmp13_ = NULL;
		GtkNotebook* _tmp14_ = NULL;
		GtkNotebook* _tmp15_ = NULL;
		GtkContainer* _tmp16_ = NULL;
		gconstpointer _tmp17_ = NULL;
		_tmp13_ = g_object_get_data ((GObject*) self, "sidebar_notebook");
		_tmp14_ = _g_object_ref0 ((GtkNotebook*) ((MultiTermNotebook*) _tmp13_));
		_g_object_unref0 (new_nb);
		new_nb = _tmp14_;
		_tmp15_ = new_nb;
		_tmp16_ = frame;
		_tmp17_ = g_object_get_data ((GObject*) self, "label");
		gtk_notebook_append_page (_tmp15_, (GtkWidget*) _tmp16_, (GtkWidget*) ((GtkLabel*) _tmp17_));
	}
	_tmp18_ = new_nb;
	_tmp19_ = new_nb;
	_tmp20_ = frame;
	_tmp21_ = gtk_notebook_page_num (_tmp19_, (GtkWidget*) _tmp20_);
	gtk_notebook_set_current_page (_tmp18_, _tmp21_);
	_tmp22_ = self->cfg;
	_tmp23_ = location;
	multi_term_config_set_location (_tmp22_, _tmp23_);
	_g_object_unref0 (new_nb);
	_g_object_unref0 (parent);
	_g_object_unref0 (frame);
}


static void multi_term_notebook_on_add_button_style_set (MultiTermNotebook* self) {
	gint w = 0;
	gint h = 0;
	GtkButton* _tmp0_ = NULL;
	GtkSettings* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	GtkButton* _tmp4_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->add_button;
	_tmp1_ = gtk_widget_get_settings ((GtkWidget*) _tmp0_);
	gtk_icon_size_lookup_for_settings (_tmp1_, GTK_ICON_SIZE_MENU, &_tmp2_, &_tmp3_);
	w = _tmp2_;
	h = _tmp3_;
	_tmp4_ = self->priv->add_button;
	gtk_widget_set_size_request ((GtkWidget*) _tmp4_, w + 2, h + 2);
}


static gpointer _multi_term_shell_config_ref0 (gpointer self) {
	return self ? multi_term_shell_config_ref (self) : NULL;
}


static gchar* string_strip (const gchar* self) {
	gchar* result = NULL;
	gchar* _result_ = NULL;
	gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup (self);
	_result_ = _tmp0_;
	_tmp1_ = _result_;
	g_strstrip (_tmp1_);
	result = _result_;
	return result;
}


static void multi_term_notebook_on_add_button_clicked (MultiTermNotebook* self) {
	MultiTermConfig* _tmp0_ = NULL;
	GList* _tmp1_ = NULL;
	GList* _tmp2_ = NULL;
	const gchar* _tmp13_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->cfg;
	_tmp1_ = multi_term_config_get_shell_configs (_tmp0_);
	_tmp2_ = _tmp1_;
	{
		GList* sh_collection = NULL;
		GList* sh_it = NULL;
		sh_collection = _tmp2_;
		for (sh_it = sh_collection; sh_it != NULL; sh_it = sh_it->next) {
			MultiTermShellConfig* _tmp3_ = NULL;
			MultiTermShellConfig* sh = NULL;
			_tmp3_ = _multi_term_shell_config_ref0 ((MultiTermShellConfig*) sh_it->data);
			sh = _tmp3_;
			{
				MultiTermShellConfig* _tmp4_ = NULL;
				const gchar* _tmp5_ = NULL;
				const gchar* _tmp6_ = NULL;
				gchar* _tmp7_ = NULL;
				gchar* _tmp8_ = NULL;
				gboolean _tmp9_ = FALSE;
				_tmp4_ = sh;
				_tmp5_ = multi_term_shell_config_get_section (_tmp4_);
				_tmp6_ = _tmp5_;
				_tmp7_ = string_strip (_tmp6_);
				_tmp8_ = _tmp7_;
				_tmp9_ = g_strcmp0 (_tmp8_, "shell=default") == 0;
				_g_free0 (_tmp8_);
				if (_tmp9_) {
					MultiTermShellConfig* _tmp10_ = NULL;
					MultiTermTerminal* _tmp11_ = NULL;
					MultiTermTerminal* _tmp12_ = NULL;
					_tmp10_ = sh;
					_tmp11_ = multi_term_notebook_add_terminal (self, _tmp10_);
					_tmp12_ = _tmp11_;
					_g_object_unref0 (_tmp12_);
					_multi_term_shell_config_unref0 (sh);
					return;
				}
				_multi_term_shell_config_unref0 (sh);
			}
		}
	}
	_tmp13_ = _ ("Unable to locate default shell in configuration file");
	g_warning ("notebook.vala:137: %s", _tmp13_);
}


static void _multi_term_notebook_on_show_tabs_activate_multi_term_context_menu_show_tabs_activate (MultiTermContextMenu* _sender, gboolean show_tabs, gpointer self) {
	multi_term_notebook_on_show_tabs_activate ((MultiTermNotebook*) self, show_tabs);
}


static gboolean _multi_term_notebook_on_next_tab_activate_multi_term_context_menu_next_tab_activate (MultiTermContextMenu* _sender, gpointer self) {
	gboolean result;
	result = multi_term_notebook_on_next_tab_activate ((MultiTermNotebook*) self);
	return result;
}


static gboolean _multi_term_notebook_on_previous_tab_activate_multi_term_context_menu_previous_tab_activate (MultiTermContextMenu* _sender, gpointer self) {
	gboolean result;
	result = multi_term_notebook_on_previous_tab_activate ((MultiTermNotebook*) self);
	return result;
}


static void _multi_term_notebook_on_new_shell_activate_multi_term_context_menu_new_shell_activate (MultiTermContextMenu* _sender, MultiTermShellConfig* sh, gpointer self) {
	multi_term_notebook_on_new_shell_activate ((MultiTermNotebook*) self, sh);
}


static void _multi_term_notebook_on_new_window_activate_multi_term_context_menu_new_window_activate (MultiTermContextMenu* _sender, gpointer self) {
	multi_term_notebook_on_new_window_activate ((MultiTermNotebook*) self);
}


static void _multi_term_notebook_on_move_to_location_multi_term_context_menu_move_to_location_activate (MultiTermContextMenu* _sender, const gchar* location, gpointer self) {
	multi_term_notebook_on_move_to_location ((MultiTermNotebook*) self, location);
}


static gboolean multi_term_notebook_on_terminal_right_click_event (MultiTermNotebook* self, GdkEventButton* event) {
	gboolean result = FALSE;
	MultiTermContextMenu* _tmp0_ = NULL;
	MultiTermContextMenu* _tmp9_ = NULL;
	GdkEventButton _tmp10_ = {0};
	guint _tmp11_ = 0U;
	GdkEventButton _tmp12_ = {0};
	guint32 _tmp13_ = 0U;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (event != NULL, FALSE);
	_tmp0_ = self->priv->context_menu;
	if (_tmp0_ == NULL) {
		MultiTermConfig* _tmp1_ = NULL;
		MultiTermContextMenu* _tmp2_ = NULL;
		MultiTermContextMenu* _tmp3_ = NULL;
		MultiTermContextMenu* _tmp4_ = NULL;
		MultiTermContextMenu* _tmp5_ = NULL;
		MultiTermContextMenu* _tmp6_ = NULL;
		MultiTermContextMenu* _tmp7_ = NULL;
		MultiTermContextMenu* _tmp8_ = NULL;
		_tmp1_ = self->cfg;
		_tmp2_ = multi_term_context_menu_new (_tmp1_);
		g_object_ref_sink (_tmp2_);
		_g_object_unref0 (self->priv->context_menu);
		self->priv->context_menu = _tmp2_;
		_tmp3_ = self->priv->context_menu;
		g_signal_connect_object (_tmp3_, "show-tabs-activate", (GCallback) _multi_term_notebook_on_show_tabs_activate_multi_term_context_menu_show_tabs_activate, self, 0);
		_tmp4_ = self->priv->context_menu;
		g_signal_connect_object (_tmp4_, "next-tab-activate", (GCallback) _multi_term_notebook_on_next_tab_activate_multi_term_context_menu_next_tab_activate, self, 0);
		_tmp5_ = self->priv->context_menu;
		g_signal_connect_object (_tmp5_, "previous-tab-activate", (GCallback) _multi_term_notebook_on_previous_tab_activate_multi_term_context_menu_previous_tab_activate, self, 0);
		_tmp6_ = self->priv->context_menu;
		g_signal_connect_object (_tmp6_, "new-shell-activate", (GCallback) _multi_term_notebook_on_new_shell_activate_multi_term_context_menu_new_shell_activate, self, 0);
		_tmp7_ = self->priv->context_menu;
		g_signal_connect_object (_tmp7_, "new-window-activate", (GCallback) _multi_term_notebook_on_new_window_activate_multi_term_context_menu_new_window_activate, self, 0);
		_tmp8_ = self->priv->context_menu;
		g_signal_connect_object (_tmp8_, "move-to-location-activate", (GCallback) _multi_term_notebook_on_move_to_location_multi_term_context_menu_move_to_location_activate, self, 0);
	}
	_tmp9_ = self->priv->context_menu;
	_tmp10_ = *event;
	_tmp11_ = _tmp10_.button;
	_tmp12_ = *event;
	_tmp13_ = _tmp12_.time;
	gtk_menu_popup ((GtkMenu*) _tmp9_, NULL, NULL, NULL, NULL, _tmp11_, _tmp13_);
	result = TRUE;
	return result;
}


static void _multi_term_notebook_on_tab_label_close_clicked_multi_term_tab_label_close_clicked (MultiTermTabLabel* _sender, gint tab_num, gpointer self) {
	multi_term_notebook_on_tab_label_close_clicked ((MultiTermNotebook*) self, tab_num);
}


static gboolean _multi_term_notebook_on_terminal_right_click_event_multi_term_terminal_right_click_event (MultiTermTerminal* _sender, GdkEventButton* event, gpointer self) {
	gboolean result;
	result = multi_term_notebook_on_terminal_right_click_event ((MultiTermNotebook*) self, event);
	return result;
}


MultiTermTerminal* multi_term_notebook_add_terminal (MultiTermNotebook* self, MultiTermShellConfig* cfg) {
	MultiTermTerminal* result = NULL;
	MultiTermTabLabel* label = NULL;
	MultiTermShellConfig* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	MultiTermTabLabel* _tmp4_ = NULL;
	MultiTermTabLabel* _tmp5_ = NULL;
	MultiTermTerminal* term = NULL;
	MultiTermShellConfig* _tmp6_ = NULL;
	MultiTermTerminal* _tmp7_ = NULL;
	MultiTermTerminal* _tmp8_ = NULL;
	MultiTermTabLabel* _tmp9_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (cfg != NULL, NULL);
	_tmp0_ = cfg;
	_tmp1_ = multi_term_shell_config_get_name (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = _tmp2_;
	_tmp4_ = multi_term_tab_label_new (_tmp3_);
	g_object_ref_sink (_tmp4_);
	_tmp5_ = _tmp4_;
	_g_free0 (_tmp3_);
	label = _tmp5_;
	_tmp6_ = cfg;
	_tmp7_ = multi_term_terminal_new (_tmp6_);
	g_object_ref_sink (_tmp7_);
	term = _tmp7_;
	gtk_widget_show_all ((GtkWidget*) label);
	g_signal_connect_object (label, "close-clicked", (GCallback) _multi_term_notebook_on_tab_label_close_clicked_multi_term_tab_label_close_clicked, self, 0);
	_tmp8_ = _g_object_ref0 (term);
	g_object_set_data_full ((GObject*) label, "terminal", _tmp8_, g_object_unref);
	_tmp9_ = _g_object_ref0 (label);
	g_object_set_data_full ((GObject*) term, "label", _tmp9_, g_object_unref);
	gtk_widget_show_all ((GtkWidget*) term);
	g_signal_connect_object (term, "right-click-event", (GCallback) _multi_term_notebook_on_terminal_right_click_event_multi_term_terminal_right_click_event, self, 0);
	gtk_notebook_append_page ((GtkNotebook*) self, (GtkWidget*) term, (GtkWidget*) label);
	gtk_notebook_set_tab_reorderable ((GtkNotebook*) self, (GtkWidget*) term, TRUE);
	gtk_notebook_set_tab_label_packing ((GtkNotebook*) self, (GtkWidget*) term, TRUE, TRUE, GTK_PACK_END);
	gtk_notebook_set_scrollable ((GtkNotebook*) self, TRUE);
	result = term;
	_g_object_unref0 (label);
	return result;
}


void multi_term_notebook_remove_terminal (MultiTermNotebook* self, gint tab_num) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = tab_num;
	gtk_notebook_remove_page ((GtkNotebook*) self, _tmp0_);
}


static void _multi_term_notebook_on_add_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self) {
	multi_term_notebook_on_add_button_clicked ((MultiTermNotebook*) self);
}


static void _multi_term_notebook_on_add_button_style_set_gtk_widget_style_set (GtkWidget* _sender, GtkStyle* previous_style, gpointer self) {
	multi_term_notebook_on_add_button_style_set ((MultiTermNotebook*) self);
}


MultiTermNotebook* multi_term_notebook_construct (GType object_type, const gchar* config_filename) {
	MultiTermNotebook * self = NULL;
	GtkImage* img = NULL;
	GtkRcStyle* style = NULL;
	const gchar* _tmp0_ = NULL;
	MultiTermConfig* _tmp1_ = NULL;
	GtkRcStyle* _tmp2_ = NULL;
	GtkRcStyle* _tmp3_ = NULL;
	GtkRcStyle* _tmp4_ = NULL;
	GtkImage* _tmp5_ = NULL;
	GtkButton* _tmp6_ = NULL;
	GtkButton* _tmp7_ = NULL;
	GtkRcStyle* _tmp8_ = NULL;
	GtkButton* _tmp9_ = NULL;
	GtkButton* _tmp10_ = NULL;
	GtkButton* _tmp11_ = NULL;
	GtkButton* _tmp12_ = NULL;
	const gchar* _tmp13_ = NULL;
	GtkButton* _tmp14_ = NULL;
	GtkImage* _tmp15_ = NULL;
	GtkButton* _tmp16_ = NULL;
	GtkButton* _tmp17_ = NULL;
	GtkButton* _tmp18_ = NULL;
	MultiTermConfig* _tmp19_ = NULL;
	gboolean _tmp20_ = FALSE;
	gboolean _tmp21_ = FALSE;
	MultiTermConfig* _tmp22_ = NULL;
	GList* _tmp23_ = NULL;
	GList* _tmp24_ = NULL;
	g_return_val_if_fail (config_filename != NULL, NULL);
	self = (MultiTermNotebook*) g_object_new (object_type, NULL);
	_tmp0_ = config_filename;
	_tmp1_ = multi_term_config_new (_tmp0_);
	_multi_term_config_unref0 (self->cfg);
	self->cfg = _tmp1_;
	_tmp2_ = gtk_rc_style_new ();
	_g_object_unref0 (style);
	style = _tmp2_;
	_tmp3_ = style;
	_tmp3_->xthickness = 0;
	_tmp4_ = style;
	_tmp4_->ythickness = 0;
	_tmp5_ = (GtkImage*) gtk_image_new_from_stock (GTK_STOCK_ADD, GTK_ICON_SIZE_MENU);
	g_object_ref_sink (_tmp5_);
	_g_object_unref0 (img);
	img = _tmp5_;
	_tmp6_ = (GtkButton*) gtk_button_new ();
	g_object_ref_sink (_tmp6_);
	_g_object_unref0 (self->priv->add_button);
	self->priv->add_button = _tmp6_;
	_tmp7_ = self->priv->add_button;
	_tmp8_ = style;
	gtk_widget_modify_style ((GtkWidget*) _tmp7_, _tmp8_);
	_tmp9_ = self->priv->add_button;
	gtk_button_set_relief (_tmp9_, GTK_RELIEF_NONE);
	_tmp10_ = self->priv->add_button;
	gtk_button_set_focus_on_click (_tmp10_, FALSE);
	_tmp11_ = self->priv->add_button;
	gtk_container_set_border_width ((GtkContainer*) _tmp11_, (guint) 2);
	_tmp12_ = self->priv->add_button;
	_tmp13_ = _ ("New terminal");
	gtk_widget_set_tooltip_text ((GtkWidget*) _tmp12_, _tmp13_);
	_tmp14_ = self->priv->add_button;
	_tmp15_ = img;
	gtk_container_add ((GtkContainer*) _tmp14_, (GtkWidget*) _tmp15_);
	_tmp16_ = self->priv->add_button;
	g_signal_connect_object (_tmp16_, "clicked", (GCallback) _multi_term_notebook_on_add_button_clicked_gtk_button_clicked, self, 0);
	_tmp17_ = self->priv->add_button;
	gtk_widget_show_all ((GtkWidget*) _tmp17_);
	_tmp18_ = self->priv->add_button;
	g_signal_connect_object ((GtkWidget*) _tmp18_, "style-set", (GCallback) _multi_term_notebook_on_add_button_style_set_gtk_widget_style_set, self, 0);
	_tmp19_ = self->cfg;
	_tmp20_ = multi_term_config_get_show_tabs (_tmp19_);
	_tmp21_ = _tmp20_;
	gtk_notebook_set_show_tabs ((GtkNotebook*) self, _tmp21_);
	_tmp22_ = self->cfg;
	_tmp23_ = multi_term_config_get_shell_configs (_tmp22_);
	_tmp24_ = _tmp23_;
	{
		GList* sh_collection = NULL;
		GList* sh_it = NULL;
		sh_collection = _tmp24_;
		for (sh_it = sh_collection; sh_it != NULL; sh_it = sh_it->next) {
			MultiTermShellConfig* _tmp25_ = NULL;
			MultiTermShellConfig* sh = NULL;
			_tmp25_ = _multi_term_shell_config_ref0 ((MultiTermShellConfig*) sh_it->data);
			sh = _tmp25_;
			{
				MultiTermTerminal* term = NULL;
				MultiTermShellConfig* _tmp26_ = NULL;
				MultiTermTerminal* _tmp27_ = NULL;
				MultiTermTerminal* _tmp28_ = NULL;
				_tmp26_ = sh;
				_tmp27_ = multi_term_notebook_add_terminal (self, _tmp26_);
				term = _tmp27_;
				_tmp28_ = term;
				g_signal_connect_object (_tmp28_, "right-click-event", (GCallback) _multi_term_notebook_on_terminal_right_click_event_multi_term_terminal_right_click_event, self, 0);
				_g_object_unref0 (term);
				_multi_term_shell_config_unref0 (sh);
			}
		}
	}
	_g_object_unref0 (style);
	_g_object_unref0 (img);
	return self;
}


MultiTermNotebook* multi_term_notebook_new (const gchar* config_filename) {
	return multi_term_notebook_construct (MULTI_TERM_TYPE_NOTEBOOK, config_filename);
}


static void multi_term_notebook_class_init (MultiTermNotebookClass * klass) {
	multi_term_notebook_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (MultiTermNotebookPrivate));
	G_OBJECT_CLASS (klass)->finalize = multi_term_notebook_finalize;
}


static void multi_term_notebook_instance_init (MultiTermNotebook * self) {
	self->priv = MULTI_TERM_NOTEBOOK_GET_PRIVATE (self);
}


static void multi_term_notebook_finalize (GObject* obj) {
	MultiTermNotebook * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, MULTI_TERM_TYPE_NOTEBOOK, MultiTermNotebook);
	_g_object_unref0 (self->priv->add_button);
	_multi_term_config_unref0 (self->cfg);
	_g_object_unref0 (self->priv->context_menu);
	G_OBJECT_CLASS (multi_term_notebook_parent_class)->finalize (obj);
}


GType multi_term_notebook_get_type (void) {
	static volatile gsize multi_term_notebook_type_id__volatile = 0;
	if (g_once_init_enter (&multi_term_notebook_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MultiTermNotebookClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) multi_term_notebook_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MultiTermNotebook), 0, (GInstanceInitFunc) multi_term_notebook_instance_init, NULL };
		GType multi_term_notebook_type_id;
		multi_term_notebook_type_id = g_type_register_static (GTK_TYPE_NOTEBOOK, "MultiTermNotebook", &g_define_type_info, 0);
		g_once_init_leave (&multi_term_notebook_type_id__volatile, multi_term_notebook_type_id);
	}
	return multi_term_notebook_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


