
#include <iostream>
#include <gtk/gtk.h>

//#include "lib.h"
//#include "send_CAN.h"


void print_msg(GtkWidget *widget, gpointer window) {
//  send_CAN();
  std::cout<<"Button clicked"<<std::endl;
}

int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *button;
//  GtkWidget *title;
//  GtkWidget *halign;
  
  GtkWidget *table;
  GtkWidget *label1;
  GtkWidget *entry1;

  gtk_init(&argc, &argv);

//  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//  gtk_window_set_title(GTK_WINDOW(window), "Mnemonic");
//  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
//  gtk_container_set_border_width(GTK_CONTAINER(window), 15);
  
//  button = gtk_button_new_with_mnemonic("_Button");
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "Mnemonic");
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  
  table = gtk_table_new(6, 4, FALSE);
//  gtk_container_add(GTK_CONTAINER(window), table);
  gtk_table_set_col_spacings(GTK_TABLE(table), 3);
  gtk_table_set_row_spacing(GTK_TABLE(table), 0, 3);
//  title = gtk_label_new("Windows");

//  halign = gtk_alignment_new(0, 0, 0, 0);
//  gtk_container_add(GTK_CONTAINER(halign), title);
//  gtk_table_attach(GTK_TABLE(table), halign, 0, 1, 0, 1, 
//      GTK_FILL, GTK_FILL, 0, 0);
//  gtk_container_add(GTK_CONTAINER(halign), button);

  button = gtk_button_new_with_label("Send");
  gtk_widget_set_size_request(button, 50, 30);
  gtk_table_attach(GTK_TABLE(table), button, 3, 4, 4, 5, 
      GTK_FILL, GTK_FILL, 0, 0);
  
  g_signal_connect(button, "clicked", 
      G_CALLBACK(print_msg), NULL);  
  
  label1 = gtk_label_new("Name");
  gtk_table_attach(GTK_TABLE(table), label1, 0, 1, 0, 1, 
     GTK_FILL, GTK_FILL, 5, 5);
	 
  entry1 = gtk_entry_new();
  gtk_table_attach(GTK_TABLE(table), entry1, 1, 2, 0, 1, 
     GTK_FILL, GTK_FILL, 5, 5);
  
  gtk_container_add(GTK_CONTAINER(window), table);

  gtk_widget_show_all(window);
  
  g_signal_connect(G_OBJECT(window), "destroy",
      G_CALLBACK(gtk_main_quit), NULL); 

  gtk_main();

  return 0;
}
