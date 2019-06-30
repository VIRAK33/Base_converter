#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <math.h>
#include "convert2.h"


// Make them global

GtkWidget	*window;
GtkWidget	*fixed1;
GtkWidget	*menu1;
GtkWidget	*label1;
GtkWidget	*label2;
GtkWidget	*label3;
GtkWidget	*label4;
GtkWidget	*cbox1;
GtkWidget	*cbox2;
GtkWidget	*entry;
GtkWidget	*result;
GtkWidget	*btn;


GtkBuilder	*builder; 


gboolean timer_handler(GtkWidget *);



void onConvert(GtkButton *button, gpointer user_data) {

	const gchar *active_left = gtk_combo_box_get_active_id(cbox1);
	const gchar *active_right = gtk_combo_box_get_active_id(cbox2);
	
	//const gchar *text = gtk_entry_get_text(entry);
	const gchar *text = gtk_entry_get_text(entry);


	g_print("%s\n", active_left);
	g_print("%s\n", active_right);
	g_print("%s\n", text);
	
	//convert input (string) to integer
	int value;
	value = str2int(text);
	//Condition for convert
	if(!(strcmp("base10",active_left)) && !(strcmp("base2",active_right))){
		gtk_label_set_text(GTK_LABEL(result), decToBinary(value));	
	}
	else if(!(strcmp("base10",active_left)) && !(strcmp("base8",active_right))){
		gtk_label_set_text(GTK_LABEL(result), decToOcta(value));	
	}
	else if(!(strcmp("base10",active_left)) && !(strcmp("base10",active_right))){
		gtk_label_set_text(GTK_LABEL(result), text);
	}
	else if(!(strcmp("base10",active_left)) && !(strcmp("base16",active_right))){
		gtk_label_set_text(GTK_LABEL(result), decToHexa(value));
	}
	else if(!(strcmp("base2",active_left)) && !(strcmp("base10",active_right))){
		gtk_label_set_text(GTK_LABEL(result), binaryToDec(value));
	}
	else if(!(strcmp("base2",active_left)) && !(strcmp("base8",active_right))){
		gtk_label_set_text(GTK_LABEL(result), binaryToOctal(value));
	}
	else if(!(strcmp("base2",active_left)) && !(strcmp("base16",active_right))){
		gtk_label_set_text(GTK_LABEL(result), binaryToHex(value));
	}
	else if(!(strcmp("base2",active_left)) && !(strcmp("base2",active_right))){
		gtk_label_set_text(GTK_LABEL(result), text);
	}
	else if(!(strcmp("base8",active_left)) && !(strcmp("base2",active_right))){
		gtk_label_set_text(GTK_LABEL(result), octalToBinary(value));
	}
	else if(!(strcmp("base8",active_left)) && !(strcmp("base10",active_right))){
		gtk_label_set_text(GTK_LABEL(result), octalToDec(value));
	}
	else if(!(strcmp("base8",active_left)) && !(strcmp("base16",active_right))){
		gtk_label_set_text(GTK_LABEL(result), octalToHex(value));
	}
	else if(!(strcmp("base8",active_left)) && !(strcmp("base8",active_right))){
		gtk_label_set_text(GTK_LABEL(result), text);
	}
	else if(!(strcmp("base16",active_left)) && !(strcmp("base10",active_right))){
		gtk_label_set_text(GTK_LABEL(result), hexadecimalToDecimal(text));
	}
	else if(!(strcmp("base16",active_left)) && !(strcmp("base2",active_right))){
		gtk_label_set_text(GTK_LABEL(result), hexadecimalToBinary(text));
	}
	else if(!(strcmp("base16",active_left)) && !(strcmp("base8",active_right))){
		gtk_label_set_text(GTK_LABEL(result), hexadecimalToOcta(text));
	}else if(!(strcmp("base16",active_left)) && !(strcmp("base16",active_right))){
		gtk_label_set_text(GTK_LABEL(result), text);
	}
	else{
		gtk_label_set_text(GTK_LABEL(result), "Choose the base again!");
		
	}

	
	
	
	//g_print("%s",decToHexa(value));
	//g_print("%s",decToOcta(value));
	//g_print("%d%d",base10, base2);
  	
	
}



int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk


	builder = gtk_builder_new_from_file ("glade/part1.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

        gtk_builder_connect_signals(builder, NULL);

	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	menu1 = GTK_WIDGET(gtk_builder_get_object(builder, "menu1"));
	label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
	label2 = GTK_WIDGET(gtk_builder_get_object(builder, "label2"));
	label3 = GTK_WIDGET(gtk_builder_get_object(builder, "label3"));
	label4 = GTK_WIDGET(gtk_builder_get_object(builder, "label4"));
	cbox1 = GTK_WIDGET(gtk_builder_get_object(builder, "cbox1"));
	cbox2 = GTK_WIDGET(gtk_builder_get_object(builder, "cbox2"));
	entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
	result = GTK_WIDGET(gtk_builder_get_object(builder, "result"));
	btn = GTK_WIDGET(gtk_builder_get_object(builder, "btn"));
	


       	gtk_widget_show(window);
	gtk_main();

	return EXIT_SUCCESS;
	}

