/* plugin.c generated by valac 0.34.9, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
 * plugin.vala - This file is part of the Geany MultiTerm plugin
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
#include <geanyplugin.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>
#include <glib/gstdio.h>

#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))


GeanyPlugin* geany_plugin = NULL;
GeanyData* geany_data = NULL;
GeanyFunctions* geany_functions = NULL;
extern GList* toplevel_widgets;
GList* toplevel_widgets = NULL;

static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);


static gint geany_vala_plugin_VERSION_CHECK (gint abi_version, gint api_required) {
	gint result = 0;
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	_tmp0_ = abi_version;
	_tmp1_ = GEANY_ABI_VERSION;
	if (_tmp0_ != _tmp1_) {
		result = -1;
		return result;
	}
	_tmp2_ = api_required;
	result = _tmp2_;
	return result;
}


gint plugin_version_check (gint abi_version) {
	gint result = 0;
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	_tmp0_ = abi_version;
	_tmp1_ = geany_vala_plugin_VERSION_CHECK (_tmp0_, 185);
	result = _tmp1_;
	return result;
}


static void geany_vala_plugin_SET_INFO (PluginInfo* self, const gchar* name, const gchar* description, const gchar* version, const gchar* author) {
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	_tmp0_ = name;
	self->name = _tmp0_;
	_tmp1_ = description;
	self->description = _tmp1_;
	_tmp2_ = version;
	self->version = _tmp2_;
	_tmp3_ = author;
	self->author = _tmp3_;
}


void plugin_set_info (PluginInfo* info) {
	PluginInfo* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	g_return_if_fail (info != NULL);
	main_locale_init (LOCALEDIR, GETTEXT_PACKAGE);
	_tmp0_ = info;
	_tmp1_ = _ ("MultiTerm");
	_tmp2_ = _ ("Multi-tabbed virtual terminal emulator.");
	geany_vala_plugin_SET_INFO (_tmp0_, _tmp1_, _tmp2_, "0.1", "Matthew Brush <matt@geany.org>");
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static GtkNotebook* geany_vala_plugin_main_widgets_get_message_window_notebook (GeanyMainWidgets* self) {
	GtkNotebook* result;
	GtkWidget* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->message_window_notebook;
	result = G_TYPE_CHECK_INSTANCE_TYPE (_tmp0_, GTK_TYPE_NOTEBOOK) ? ((GtkNotebook*) _tmp0_) : NULL;
	return result;
}


static GtkNotebook* geany_vala_plugin_main_widgets_get_sidebar_notebook (GeanyMainWidgets* self) {
	GtkNotebook* result;
	GtkWidget* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->sidebar_notebook;
	result = G_TYPE_CHECK_INSTANCE_TYPE (_tmp0_, GTK_TYPE_NOTEBOOK) ? ((GtkNotebook*) _tmp0_) : NULL;
	return result;
}


void plugin_init (GeanyData* data) {
	gchar* config_file = NULL;
	gchar* config_dir = NULL;
	GtkLabel* label = NULL;
	GtkAlignment* align = NULL;
	MultiTermNotebook* notebook = NULL;
	GeanyPlugin* _tmp0_ = NULL;
	GeanyData* _tmp1_ = NULL;
	GeanyApp* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	const gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	const gchar* _tmp7_ = NULL;
	GtkAlignment* _tmp14_ = NULL;
	const gchar* _tmp15_ = NULL;
	MultiTermNotebook* _tmp16_ = NULL;
	GtkAlignment* _tmp17_ = NULL;
	MultiTermNotebook* _tmp18_ = NULL;
	GtkAlignment* _tmp19_ = NULL;
	GtkAlignment* _tmp20_ = NULL;
	GtkWidget* _tmp21_ = NULL;
	const gchar* _tmp22_ = NULL;
	GtkLabel* _tmp23_ = NULL;
	MultiTermNotebook* _tmp24_ = NULL;
	GtkLabel* _tmp25_ = NULL;
	GtkLabel* _tmp26_ = NULL;
	MultiTermNotebook* _tmp27_ = NULL;
	GeanyData* _tmp28_ = NULL;
	GeanyMainWidgets* _tmp29_ = NULL;
	GtkNotebook* _tmp30_ = NULL;
	GtkNotebook* _tmp31_ = NULL;
	GtkNotebook* _tmp32_ = NULL;
	MultiTermNotebook* _tmp33_ = NULL;
	GeanyData* _tmp34_ = NULL;
	GeanyMainWidgets* _tmp35_ = NULL;
	GtkNotebook* _tmp36_ = NULL;
	GtkNotebook* _tmp37_ = NULL;
	GtkNotebook* _tmp38_ = NULL;
	MultiTermNotebook* _tmp39_ = NULL;
	MultiTermConfig* _tmp40_ = NULL;
	gchar* _tmp41_ = NULL;
	gchar* _tmp42_ = NULL;
	gchar* _tmp43_ = NULL;
	gboolean _tmp44_ = FALSE;
	GError * _inner_error_ = NULL;
	g_return_if_fail (data != NULL);
	_tmp0_ = geany_plugin;
	plugin_module_make_resident (_tmp0_);
	__g_list_free__g_object_unref0_0 (toplevel_widgets);
	toplevel_widgets = NULL;
	_tmp1_ = geany_data;
	_tmp2_ = _tmp1_->app;
	_tmp3_ = _tmp2_->configdir;
	_tmp4_ = g_build_filename (_tmp3_, "plugins", "multiterm", NULL);
	_g_free0 (config_dir);
	config_dir = _tmp4_;
	_tmp5_ = config_dir;
	_tmp6_ = g_build_filename (_tmp5_, "multiterm.conf", NULL);
	_g_free0 (config_file);
	config_file = _tmp6_;
	_tmp7_ = config_dir;
	g_mkdir_with_parents (_tmp7_, 0755);
	{
		const gchar* _tmp8_ = NULL;
		gboolean _tmp9_ = FALSE;
		_tmp8_ = config_file;
		_tmp9_ = g_file_test (_tmp8_, G_FILE_TEST_EXISTS | G_FILE_TEST_IS_REGULAR);
		if (!_tmp9_) {
			const gchar* _tmp10_ = NULL;
			_tmp10_ = config_file;
			g_file_set_contents (_tmp10_, MULTI_TERM_default_config, (gssize) -1, &_inner_error_);
			if (G_UNLIKELY (_inner_error_ != NULL)) {
				if (_inner_error_->domain == G_FILE_ERROR) {
					goto __catch6_g_file_error;
				}
				_g_object_unref0 (notebook);
				_g_object_unref0 (align);
				_g_object_unref0 (label);
				_g_free0 (config_dir);
				_g_free0 (config_file);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
	}
	goto __finally6;
	__catch6_g_file_error:
	{
		GError* err = NULL;
		const gchar* _tmp11_ = NULL;
		GError* _tmp12_ = NULL;
		const gchar* _tmp13_ = NULL;
		err = _inner_error_;
		_inner_error_ = NULL;
		_tmp11_ = _ ("Unable to write default config file: %s");
		_tmp12_ = err;
		_tmp13_ = _tmp12_->message;
		g_warning (_tmp11_, _tmp13_);
		_g_error_free0 (err);
	}
	__finally6:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		_g_object_unref0 (notebook);
		_g_object_unref0 (align);
		_g_object_unref0 (label);
		_g_free0 (config_dir);
		_g_free0 (config_file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp14_ = (GtkAlignment*) gtk_alignment_new (0.5f, 0.5f, 1.0f, 1.0f);
	g_object_ref_sink (_tmp14_);
	_g_object_unref0 (align);
	align = _tmp14_;
	_tmp15_ = config_file;
	_tmp16_ = multi_term_notebook_new (_tmp15_);
	g_object_ref_sink (_tmp16_);
	_g_object_unref0 (notebook);
	notebook = _tmp16_;
	_tmp17_ = align;
	_tmp18_ = notebook;
	gtk_container_add ((GtkContainer*) _tmp17_, (GtkWidget*) (G_TYPE_CHECK_INSTANCE_TYPE (_tmp18_, GTK_TYPE_NOTEBOOK) ? ((GtkNotebook*) _tmp18_) : NULL));
	_tmp19_ = align;
	gtk_widget_show_all ((GtkWidget*) _tmp19_);
	_tmp20_ = align;
	_tmp21_ = _g_object_ref0 ((GtkWidget*) _tmp20_);
	toplevel_widgets = g_list_append (toplevel_widgets, _tmp21_);
	_tmp22_ = _ ("MultiTerm");
	_tmp23_ = (GtkLabel*) gtk_label_new (_tmp22_);
	g_object_ref_sink (_tmp23_);
	_g_object_unref0 (label);
	label = _tmp23_;
	_tmp24_ = notebook;
	_tmp25_ = label;
	_tmp26_ = _g_object_ref0 (_tmp25_);
	g_object_set_data_full ((GObject*) _tmp24_, "label", _tmp26_, g_object_unref);
	_tmp27_ = notebook;
	_tmp28_ = data;
	_tmp29_ = _tmp28_->main_widgets;
	_tmp30_ = geany_vala_plugin_main_widgets_get_message_window_notebook (_tmp29_);
	_tmp31_ = _tmp30_;
	_tmp32_ = _g_object_ref0 (_tmp31_);
	g_object_set_data_full ((GObject*) _tmp27_, "msgwin_notebook", _tmp32_, g_object_unref);
	_tmp33_ = notebook;
	_tmp34_ = data;
	_tmp35_ = _tmp34_->main_widgets;
	_tmp36_ = geany_vala_plugin_main_widgets_get_sidebar_notebook (_tmp35_);
	_tmp37_ = _tmp36_;
	_tmp38_ = _g_object_ref0 (_tmp37_);
	g_object_set_data_full ((GObject*) _tmp33_, "sidebar_notebook", _tmp38_, g_object_unref);
	_tmp39_ = notebook;
	_tmp40_ = _tmp39_->cfg;
	_tmp41_ = multi_term_config_get_location (_tmp40_);
	_tmp42_ = _tmp41_;
	_tmp43_ = _tmp42_;
	_tmp44_ = g_strcmp0 (_tmp43_, "msgwin") == 0;
	_g_free0 (_tmp43_);
	if (_tmp44_) {
		GeanyData* _tmp45_ = NULL;
		GeanyMainWidgets* _tmp46_ = NULL;
		GtkNotebook* _tmp47_ = NULL;
		GtkNotebook* _tmp48_ = NULL;
		GtkAlignment* _tmp49_ = NULL;
		GtkLabel* _tmp50_ = NULL;
		GeanyData* _tmp51_ = NULL;
		GeanyMainWidgets* _tmp52_ = NULL;
		GtkNotebook* _tmp53_ = NULL;
		GtkNotebook* _tmp54_ = NULL;
		GeanyData* _tmp55_ = NULL;
		GeanyMainWidgets* _tmp56_ = NULL;
		GtkNotebook* _tmp57_ = NULL;
		GtkNotebook* _tmp58_ = NULL;
		GtkAlignment* _tmp59_ = NULL;
		gint _tmp60_ = 0;
		_tmp45_ = data;
		_tmp46_ = _tmp45_->main_widgets;
		_tmp47_ = geany_vala_plugin_main_widgets_get_message_window_notebook (_tmp46_);
		_tmp48_ = _tmp47_;
		_tmp49_ = align;
		_tmp50_ = label;
		gtk_notebook_append_page (_tmp48_, (GtkWidget*) _tmp49_, (GtkWidget*) _tmp50_);
		_tmp51_ = data;
		_tmp52_ = _tmp51_->main_widgets;
		_tmp53_ = geany_vala_plugin_main_widgets_get_message_window_notebook (_tmp52_);
		_tmp54_ = _tmp53_;
		_tmp55_ = data;
		_tmp56_ = _tmp55_->main_widgets;
		_tmp57_ = geany_vala_plugin_main_widgets_get_message_window_notebook (_tmp56_);
		_tmp58_ = _tmp57_;
		_tmp59_ = align;
		_tmp60_ = gtk_notebook_page_num (_tmp58_, (GtkWidget*) _tmp59_);
		gtk_notebook_set_current_page (_tmp54_, _tmp60_);
	} else {
		GeanyData* _tmp61_ = NULL;
		GeanyMainWidgets* _tmp62_ = NULL;
		GtkNotebook* _tmp63_ = NULL;
		GtkNotebook* _tmp64_ = NULL;
		GtkAlignment* _tmp65_ = NULL;
		GtkLabel* _tmp66_ = NULL;
		GeanyData* _tmp67_ = NULL;
		GeanyMainWidgets* _tmp68_ = NULL;
		GtkNotebook* _tmp69_ = NULL;
		GtkNotebook* _tmp70_ = NULL;
		GeanyData* _tmp71_ = NULL;
		GeanyMainWidgets* _tmp72_ = NULL;
		GtkNotebook* _tmp73_ = NULL;
		GtkNotebook* _tmp74_ = NULL;
		GtkAlignment* _tmp75_ = NULL;
		gint _tmp76_ = 0;
		_tmp61_ = data;
		_tmp62_ = _tmp61_->main_widgets;
		_tmp63_ = geany_vala_plugin_main_widgets_get_sidebar_notebook (_tmp62_);
		_tmp64_ = _tmp63_;
		_tmp65_ = align;
		_tmp66_ = label;
		gtk_notebook_append_page (_tmp64_, (GtkWidget*) _tmp65_, (GtkWidget*) _tmp66_);
		_tmp67_ = data;
		_tmp68_ = _tmp67_->main_widgets;
		_tmp69_ = geany_vala_plugin_main_widgets_get_sidebar_notebook (_tmp68_);
		_tmp70_ = _tmp69_;
		_tmp71_ = data;
		_tmp72_ = _tmp71_->main_widgets;
		_tmp73_ = geany_vala_plugin_main_widgets_get_sidebar_notebook (_tmp72_);
		_tmp74_ = _tmp73_;
		_tmp75_ = align;
		_tmp76_ = gtk_notebook_page_num (_tmp74_, (GtkWidget*) _tmp75_);
		gtk_notebook_set_current_page (_tmp70_, _tmp76_);
	}
	_g_object_unref0 (notebook);
	_g_object_unref0 (align);
	_g_object_unref0 (label);
	_g_free0 (config_dir);
	_g_free0 (config_file);
}


void plugin_cleanup (void) {
	GList* _tmp0_ = NULL;
	_tmp0_ = toplevel_widgets;
	{
		GList* wid_collection = NULL;
		GList* wid_it = NULL;
		wid_collection = _tmp0_;
		for (wid_it = wid_collection; wid_it != NULL; wid_it = wid_it->next) {
			GtkWidget* _tmp1_ = NULL;
			GtkWidget* wid = NULL;
			_tmp1_ = _g_object_ref0 ((GtkWidget*) wid_it->data);
			wid = _tmp1_;
			{
				GtkWidget* _tmp2_ = NULL;
				_tmp2_ = wid;
				gtk_object_destroy ((GtkObject*) _tmp2_);
				_g_object_unref0 (wid);
			}
		}
	}
	__g_list_free__g_object_unref0_0 (toplevel_widgets);
	toplevel_widgets = NULL;
}



