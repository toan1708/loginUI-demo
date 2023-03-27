#include <gtk/gtk.h>

GtkBuilder *builder;
GtkWidget *window;
GtkWidget *entry_username;
GtkWidget *entry_password;

void on_button_login_clicked(GtkButton *button, gpointer user_data) {
    const gchar *username = gtk_entry_get_text(GTK_ENTRY(entry_username));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(entry_password));

    // TODO: Implement login logic here

    g_print("Username: %s\n", username);
    g_print("Password: %s\n", password);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("login.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    entry_username = GTK_WIDGET(gtk_builder_get_object(builder, "entry_username"));
    entry_password = GTK_WIDGET(gtk_builder_get_object(builder, "entry_password"));

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}
