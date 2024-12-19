#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "service.c"
#include "agent.c"

//  ki tzid il 5idma mta3 il reservation hadhi lazim tfasa5ha
#include "reservation.h"
//**********************

char Target[60];
char civil_status[20];
int check = 0;
int checks = 0;



// fn de show msg de controle saisie
void show_error_dialog(const char *message) {
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "%s", message);
    gtk_window_set_title(GTK_WINDOW(dialog), "Erreur");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}





void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_modify_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_add_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_remove__clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_show_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button9_leave                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}









void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{





}

//*********************************************ahmed********************************************************************





 // btn cancel ajout


void
on_button125_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *agent_list, *formulaire_ajout,*treeview6;
formulaire_ajout = lookup_widget(GTK_WIDGET(button), "formulaire_ajout");
   gtk_widget_destroy(formulaire_ajout);
        agent_list = create_agent_list();
        gtk_widget_show(agent_list);
treeview6 = lookup_widget(agent_list, "treeview6");
show_agents(treeview6);
}

//btn radio
void
on_radiobutton28_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(civil_status,"Single");}
}


void
on_radiobutton30_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(civil_status,"Married");}
}


void
on_radiobutton29_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(civil_status,"Divorced");}
}

//  btn d ajout d un agent

void on_button124_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *formulaire_ajout,*agent_list,*treeview6;
    formulaire_ajout = lookup_widget(GTK_WIDGET(button), "formulaire_ajout");

    Agent d; 

    GtkWidget *dialog;
    GtkWidget *id_parking,*last_name, *first_name, *day, *month, *year,  *cin, *phone_number, *email, *address, *job_title, *contract_duration;


    id_parking = lookup_widget(GTK_WIDGET(button), "entry202");
    last_name = lookup_widget(GTK_WIDGET(button), "entry182");
    first_name = lookup_widget(GTK_WIDGET(button), "entry183");
    day = lookup_widget(GTK_WIDGET(button), "spinbutton8");
    month = lookup_widget(GTK_WIDGET(button), "combobox200");
    year = lookup_widget(GTK_WIDGET(button), "spinbutton9");
    cin = lookup_widget(GTK_WIDGET(button), "entry184");
    phone_number = lookup_widget(GTK_WIDGET(button), "entry185");
    email = lookup_widget(GTK_WIDGET(button), "entry186");
    address = lookup_widget(GTK_WIDGET(button), "entry187");
    job_title = lookup_widget(GTK_WIDGET(button), "combobox4");
    contract_duration = lookup_widget(GTK_WIDGET(button), "entry188");


    strcpy(d.last_name, gtk_entry_get_text(GTK_ENTRY(last_name)));
    if (strcmp(d.last_name, "") == 0) {
        show_error_dialog("The last name can't be empty");
        return;
    }

    strcpy(d.first_name, gtk_entry_get_text(GTK_ENTRY(first_name)));
    if (strcmp(d.first_name, "") == 0) {
        show_error_dialog("The first name can't be empty");
        return;
    }
// id parking
    strcpy(d.id_parking, gtk_entry_get_text(GTK_ENTRY(id_parking)));
if (strcmp(d.id_parking, "") == 0 || !is_parking_exist(d.id_parking)) {
    show_error_dialog("The id_parking can't be empty or the parking doesn't exist.");
    return;
}

    // Handle date of birth
    int j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));

    int a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));

    sprintf(d.birth_date.day, "%d", j);  
if (strcmp(d.birth_date.day, "") == 0) {
        show_error_dialog("jour");
        return;
    }


    sprintf(d.birth_date.year, "%d", a);  
if (strcmp(d.birth_date.year, "") == 0) {
        show_error_dialog("year");
        return;
    }
  strcpy(d.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
    if (strlen(d.cin) != 8) {
        show_error_dialog("CIN is incorrect ");
        return;
    }
   if (!is_all_digits(d.cin)) {
        show_error_dialog("CIN form not correct (8 numbers)");
        return;
    }

    if (is_cin_exist(d.cin)) {
        show_error_dialog("CIN is already exists");
        return;
    }
 


    strcpy(d.phone_number, gtk_entry_get_text(GTK_ENTRY(phone_number)));
    if (strlen(d.phone_number) != 8||!is_all_digits(d.phone_number)) {
        show_error_dialog("Phone number is incorrect");
        return;
    }

    strcpy(d.email, gtk_entry_get_text(GTK_ENTRY(email)));
    if (strcmp(d.email, "") == 0) {
        show_error_dialog("Email can't be empty");
        return;
    }

    strcpy(d.email, gtk_entry_get_text(GTK_ENTRY(email)));
    if (!contains_at(d.email)) {
        show_error_dialog("Email invalid");
        return;
    }
    strcpy(d.address, gtk_entry_get_text(GTK_ENTRY(address)));
    if (strcmp(d.address, "") == 0) {
        show_error_dialog("Address can't be empty");
        return;
    }

    strcpy(d.contract_duration, gtk_entry_get_text(GTK_ENTRY(contract_duration)));
    if (strcmp(d.contract_duration, "") == 0) {
        show_error_dialog("Contract duration can't be empty");
        return;
    }

    const gchar *job_title_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(job_title));
    strcpy(d.job_title, job_title_text);


   month = gtk_combo_box_get_active_text(GTK_COMBO_BOX(month));

    strcpy(d.birth_date.month, month);
if (strcmp(d.birth_date.month, "") == 0) {
        show_error_dialog("month");
        return;
    }


    strcpy(d.civil_status, civil_status);
if (strcmp(d.civil_status, "") == 0) {
        show_error_dialog("civil_status");
        return;
    }
     if (check == 0) {
        show_error_dialog("You must accept the general conditions and the confidentiality policy");
        return;
    }


 add_agent(d);
check = 0;
    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_OTHER,
                                    GTK_BUTTONS_OK,
                                    "Added successfully ✔");
    gtk_window_set_title(GTK_WINDOW(dialog), "Alert");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
   gtk_widget_destroy(formulaire_ajout);
        agent_list = create_agent_list();
        gtk_widget_show(agent_list);
treeview6 = lookup_widget(agent_list, "treeview6");
show_agents(treeview6);
}

void
on_checkbutton53_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton54_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton55_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton59_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
        check = 1;
    } else {
        check = 0; 
    }
}


void
on_button122_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *agent_list, *formulaire_ajout;
agent_list = lookup_widget(GTK_WIDGET(button), "agent_list");
   gtk_widget_destroy(agent_list);
        formulaire_ajout = create_formulaire_ajout();
        gtk_widget_show(formulaire_ajout);


}


void
on_button120_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *agent_list,*treeview6;
agent_list = lookup_widget(GTK_WIDGET(button), "agent_list");
   gtk_widget_destroy(agent_list);
        agent_list = create_agent_list();
        gtk_widget_show(agent_list);
treeview6 = lookup_widget(agent_list, "treeview6");
show_agents(treeview6);
}


void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button116_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview6, *dialog;
    GtkWidget *entry;

    char search[30];
	Agent d;
    entry = lookup_widget(GTK_WIDGET(button), "entry181");
   treeview6 = lookup_widget(GTK_WIDGET(button), "treeview6");
    strcpy(search, gtk_entry_get_text(GTK_ENTRY(entry)));

    FILE *f;
    f = fopen("agents.txt", "r");

    if (strcmp(search, "") == 0)
    {        dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_WARNING,
                                        GTK_BUTTONS_OK,
                                        "La recherche n'a pas abouti");
        gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }

//condition search
    else if (f != NULL)
    {
        int found = 0; 

        while (fscanf(f, "%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^\n]\n", 
                 d.id_parking,  d.first_name, d.last_name, d.birth_date.day, d.birth_date.month, d.birth_date.year,
                  d.civil_status, d.cin, d.phone_number, d.email, d.address, d.job_title, d.contract_duration) != EOF)
        {
            if ((strcmp(search, d.first_name) == 0)||(strcmp(search,d.last_name) == 0)||(strcmp(search,d.cin) == 0)||(strcmp(search,d.phone_number) == 0)||(strcmp(search,d.job_title) == 0))
            {
                found = 1;
                break; 
            }
        }

        fclose(f);

        if (found == 0)
        {
            dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_WARNING,
                                            GTK_BUTTONS_OK,
                                            "Aucun résultat trouvé pour votre recherche");
            gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
        }
        else
        {
           search_agents(treeview6, search);
        }
    }


}
//select supprimer

void on_button119_clicked(GtkButton *button, gpointer user_data) {
    GtkTreeSelection *selection;
    GtkTreeIter iter;
    GtkTreeModel *model;
    GtkWidget *treeview6, *dialog;

    // Declare variables to hold the agent's details
    gchar *first_name, *last_name, *civil_status;
    gchar *id_parking, *cin, *phone_number, *email, *address, *job_title, *contract_duration;
    gchar *day, *month, *year;

    // Get the selected item in the treeview
    treeview6 = lookup_widget(GTK_WIDGET(button), "treeview6");
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview6));

    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        // Retrieve data from the selected row, in the order of the structure fields
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter,
                           0, &id_parking, 
                           1, &first_name, 
                           2, &last_name, 
                           3, &day, 
                           4, &month, 
                           5, &year, 
                           6, &civil_status, 
                           7, &cin, 
                           8, &phone_number, 
                           9, &email, 
                           10, &address, 
                           11, &job_title, 
                           12, &contract_duration, 
                           -1);

        // Remove the item from the treeview
        gtk_list_store_remove(GTK_LIST_STORE(model), &iter);

        // Call the function to delete the agent from the data source (file, database, etc.)
        delete_agent(cin);  // Assuming this function deletes the agent by CIN

        // Show a success dialog
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_OTHER,
                                        GTK_BUTTONS_OK,
                                        "Agent removed successfully ✔");
        gtk_window_set_title(GTK_WINDOW(dialog), "Alert");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);

    } else {
        // Show an error dialog if no item was selected
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_ERROR,
                                        GTK_BUTTONS_OK,
                                        "Please select a person to delete.");
        gtk_window_set_title(GTK_WINDOW(dialog), "Alert");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}
// modif select
void on_button118_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *agent_list, *modifier_agent;
    GtkTreeSelection *selection2;
    GtkTreeIter iter;
    GtkTreeModel *model;
    GtkWidget *treeview6;

    // Declare variables to hold the agent's details
    gchar *first_name, *last_name, *civil_status;
    gchar *cin, *phone_number, *email, *address, *job_title, *contract_duration,*id_parking;
    gchar *day, *month, *year;

    int jj, mm, aa; // day, month, and year as integers
    treeview6 = lookup_widget(GTK_WIDGET(button), "treeview6");
    selection2 = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview6));

    // Check if a row is selected in the treeview
    if (gtk_tree_selection_get_selected(selection2, &model, &iter)) {
        // Retrieve the values of the selected agent
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter,
          		   0, &id_parking, 
                           1, &first_name, 
                           2, &last_name, 
                           3, &day, 
                           4, &month, 
                           5, &year, 
                           6, &civil_status, 
                           7, &cin, 
                           8, &phone_number, 
                           9, &email, 
                           10, &address, 
                           11, &job_title, 
                           12, &contract_duration, 
                           -1);

        // Remove the selected agent from the treeview (list store)
        gtk_list_store_remove(GTK_LIST_STORE(model), &iter);

        // Destroy the current agent list view
        agent_list = lookup_widget(GTK_WIDGET(button), "agent_list");
        gtk_widget_destroy(agent_list);

        // Create the "Modify Agent" window
        modifier_agent = create_modifier_agent();
        gtk_widget_show(modifier_agent);

        // Populate the modify agent form with the current values
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_agent, "entry195")), first_name);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_agent, "entry196")), last_name);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_agent, "entry197")), cin);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_agent, "entry198")), phone_number);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_agent, "entry199")), email);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_agent, "entry200")), address);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_agent, "entry201")), contract_duration);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_agent, "entry203")), id_parking);
        // Convert day, month, and year from strings to integers for date fields
        jj = atoi(day);  // Convert string to integer
        mm = atoi(month);
        aa = atoi(year);

        // Set the spin button for day and year in the modify form
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier_agent, "spinbutton11")), jj);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier_agent, "spinbutton12")), aa);

        // Set the combobox for month
        if (strcmp(month, "January") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 0);
        } else if (strcmp(month, "February") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 1);
        } else if (strcmp(month, "March") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 2);
        } else if (strcmp(month, "April") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 3);
        } else if (strcmp(month, "May") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 4);
        } else if (strcmp(month, "June") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 5);
        } else if (strcmp(month, "July") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 6);
        } else if (strcmp(month, "August") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 7);
        } else if (strcmp(month, "September") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 8);
        } else if (strcmp(month, "October") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 9);
        } else if (strcmp(month, "November") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 10);
        } else if (strcmp(month, "December") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox202")), 11);
        }

        // Set the combobox for job title
        if (strcmp(job_title, "Surveillance agent") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox201")), 0);
        } else if (strcmp(job_title, "Security agent") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox201")), 1);
        } else if (strcmp(job_title, "Parking manager") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier_agent, "combobox201")), 2);
        }
    } else {
        // Show error dialog if no agent is selected
        show_error_dialog("Please select an agent to modify.");
    }
}


void
on_radiobutton33_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(civil_status,"Single");}
}


void
on_radiobutton34_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(civil_status,"Married");}
}


void
on_radiobutton35_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(civil_status,"Divorced");}
}


void
on_checkbutton60_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
        check = 1;
    } else {
        check = 0; 
    }
}


void
on_button128_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *agent_list,*modifier_agent,*treeview6;
modifier_agent = lookup_widget(GTK_WIDGET(button), "modifier_agent");
   gtk_widget_destroy(modifier_agent);
        agent_list = create_agent_list();
        gtk_widget_show(agent_list);
treeview6 = lookup_widget(agent_list, "treeview6");
show_agents(treeview6);
}


void
on_button127_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *modifier_agent,*agent_list,*treeview6;
    modifier_agent = lookup_widget(GTK_WIDGET(button), "modifier_agent");

    Agent d; 

    GtkWidget *dialog;
    GtkWidget *id_parking ,*last_name, *first_name, *day, *month, *year,  *cin, *phone_number, *email, *address, *job_title, *contract_duration;

    id_parking = lookup_widget(GTK_WIDGET(button), "entry203");
    last_name = lookup_widget(GTK_WIDGET(button), "entry195");
    first_name = lookup_widget(GTK_WIDGET(button), "entry196");
    day = lookup_widget(GTK_WIDGET(button), "spinbutton11");
    month = lookup_widget(GTK_WIDGET(button), "combobox202");
    year = lookup_widget(GTK_WIDGET(button), "spinbutton12");
    cin = lookup_widget(GTK_WIDGET(button), "entry197");
    phone_number = lookup_widget(GTK_WIDGET(button), "entry198");
    email = lookup_widget(GTK_WIDGET(button), "entry199");
    address = lookup_widget(GTK_WIDGET(button), "entry200");
    job_title = lookup_widget(GTK_WIDGET(button), "combobox201");
    contract_duration = lookup_widget(GTK_WIDGET(button), "entry201");

    strcpy(d.id_parking, gtk_entry_get_text(GTK_ENTRY(id_parking)));
if (strcmp(d.id_parking, "") == 0 || !is_parking_exist(d.id_parking)) {
    show_error_dialog("The id_parking can't be empty or the parking doesn't exist.");
    return;
}


    strcpy(d.last_name, gtk_entry_get_text(GTK_ENTRY(last_name)));
    if (strcmp(d.last_name, "") == 0) {
        show_error_dialog("The last name can't be empty");
        return;
    }

    strcpy(d.first_name, gtk_entry_get_text(GTK_ENTRY(first_name)));
    if (strcmp(d.first_name, "") == 0) {
        show_error_dialog("The first name can't be empty");
        return;
    }


    int j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));

    int a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));

    sprintf(d.birth_date.day, "%d", j);  
if (strcmp(d.birth_date.day, "") == 0) {
        show_error_dialog("jour");
        return;
    }


    sprintf(d.birth_date.year, "%d", a);  
if (strcmp(d.birth_date.year, "") == 0) {
        show_error_dialog("year");
        return;
    }

    strcpy(d.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
    if (strlen(d.cin) != 8) {
        show_error_dialog("CIN is incorrect ");
        return;
    }

    strcpy(d.phone_number, gtk_entry_get_text(GTK_ENTRY(phone_number)));
    if (strlen(d.phone_number) != 8) {
        show_error_dialog("Phone number is incorrect");
        return;
    }

    strcpy(d.email, gtk_entry_get_text(GTK_ENTRY(email)));
    if (strcmp(d.email, "") == 0) {
        show_error_dialog("Email can't be empty");
        return;
    }
 strcpy(d.email, gtk_entry_get_text(GTK_ENTRY(email)));
    if (!contains_at(d.email)) {
        show_error_dialog("Email invalid");
        return;
    }

    strcpy(d.address, gtk_entry_get_text(GTK_ENTRY(address)));
    if (strcmp(d.address, "") == 0) {
        show_error_dialog("Address can't be empty");
        return;
    }

    strcpy(d.contract_duration, gtk_entry_get_text(GTK_ENTRY(contract_duration)));
    if (strcmp(d.contract_duration, "") == 0) {
        show_error_dialog("Contract duration can't be empty");
        return;
    }

    const gchar *job_title_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(job_title));
    strcpy(d.job_title, job_title_text);


   month = gtk_combo_box_get_active_text(GTK_COMBO_BOX(month));

    strcpy(d.birth_date.month, month);
if (strcmp(d.birth_date.month, "") == 0) {
        show_error_dialog("month");
        return;
    }


    strcpy(d.civil_status, civil_status);
if (strcmp(d.civil_status, "") == 0) {
        show_error_dialog("civil_status");
        return;
    }
     if (check == 0) {
        show_error_dialog("You must accept the general conditions and the confidentiality policy");
        return;
    }


 update_agent(d);
check =0;
    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_OTHER,
                                    GTK_BUTTONS_OK,
                                    "updated successfully ✔");
    gtk_window_set_title(GTK_WINDOW(dialog), "Alert");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
   gtk_widget_destroy(modifier_agent);    
        agent_list = create_agent_list();
        gtk_widget_show(agent_list);
treeview6 = lookup_widget(agent_list, "treeview6");
show_agents(treeview6);
}


void
on_button123_activate                  (GtkButton       *button,
                                        gpointer         user_data)
{


}


void
on_treeview7_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button129_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

 GtkWidget *show_reservation, *treeview7, *id_entry, *date_entry, *dialog;
    char getid[60], getdate[60];
    Book B;

    show_reservation = lookup_widget(GTK_WIDGET(button), "show_reservation");
    id_entry = lookup_widget(GTK_WIDGET(button), "entry205");
    date_entry = lookup_widget(GTK_WIDGET(button), "entry204");

    strcpy(getid, gtk_entry_get_text(GTK_ENTRY(id_entry)));
    strcpy(getdate, gtk_entry_get_text(GTK_ENTRY(date_entry)));

    if (strcmp(getid, "") == 0 && strcmp(getdate, "") == 0) {
        dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_WARNING,
                                        GTK_BUTTONS_OK,
                                        "La recherche n'a pas abouti");
        gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }

    FILE *f = fopen("reservations.txt", "r");
    if (f == NULL) {
        perror("Unable to open file");
        return;
    }

    int found = 0;

    while (fscanf(f, "%s %s %s %s %f %d %d %s\n", B.u_id, B.res_id, B.p_id, B.ph_num,
                  &B.duration, &B.option, &B.priority, B.date) != EOF) {
        if (strcmp(B.p_id, getid) == 0 && strcmp(B.date, getdate) == 0) {
            found = 1;
            break;
        }
    }

    fclose(f);

    if (found == 0) {
        dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_WARNING,
                                        GTK_BUTTONS_OK,
                                        "Aucun résultat trouvé pour votre recherche");
        gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    } else {
treeview7 = lookup_widget(show_reservation, "treeview7");
search_reservation_by_conditions(treeview7,getid, getdate);
    }

 


}


void
on_button130_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *agent_list,*show_reservation,*treeview6;
show_reservation = lookup_widget(GTK_WIDGET(button), "show_reservation");
   gtk_widget_destroy(show_reservation);
        agent_list = create_agent_list();
        gtk_widget_show(agent_list);
treeview6 = lookup_widget(agent_list, "treeview6");
show_agents(treeview6);

}





void
on_button123_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *agent_list,*show_reservation;
agent_list = lookup_widget(GTK_WIDGET(button), "agent_list");
   gtk_widget_destroy(agent_list);
        show_reservation = create_show_reservation();
        gtk_widget_show(show_reservation);
}



///**********************hideya*********************************************************

void
on_button132_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *service_list, *add;
service_list = lookup_widget(GTK_WIDGET(button), "service_list");
   gtk_widget_destroy(service_list);
        add = create_add();
        gtk_widget_show(add);
}


void
on_button133_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *service_list, *modify;
    GtkTreeSelection *selection3;
    GtkTreeIter iter;
    GtkTreeModel *model;
    GtkWidget *treeview8;

    // Declare variables to hold the service's details
    gchar *name, *id_service, *manager_name;
    gchar *available, *s_desc, *s_phnumber, *s_email, *price, *target;
    gchar *day, *month, *year;

    int jj, mm, aa; // day, month, and year as integers
    treeview8 = lookup_widget(GTK_WIDGET(button), "treeview8");
    selection3 = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview8));

    // Check if a row is selected in the treeview
    if (gtk_tree_selection_get_selected(selection3, &model, &iter)) {
        // Retrieve the values of the selected agent
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter,
          		   0, &name, 
                           1, &id_service, 
                           2, &manager_name, 
                           3, &day, 
                           4, &month, 
                           5, &year, 
                           6, &available, 
                           7, &s_desc, 
                           8, &s_phnumber, 
                           9, &s_email, 
                           10, &price, 
                           11, &target, 
                           -1);
                 
        // Remove the selected service from the treeview (list store)
        gtk_list_store_remove(GTK_LIST_STORE(model), &iter);

        // Destroy the current service list view
        service_list = lookup_widget(GTK_WIDGET(button), "service_list");
        gtk_widget_destroy(service_list);

        // Create the "Modify service" window
        modify = create_modify();
        gtk_widget_show(modify);

        // Populate the modify service form with the current values
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modify, "entry217")), name);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modify, "entry216")), id_service);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modify, "entry218")), manager_name);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modify, "entry219")), s_phnumber);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modify, "entry220")), s_email);
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(modify, "entry221")), s_desc);
       
        // Convert day, month, and year from strings to integers for date fields
        jj = atoi(day);  // Convert string to integer
        mm = atoi(month);
        aa = atoi(year);

        // Set the spin button for day and year in the modify form
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modify, "spinbutton17")), jj);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modify, "spinbutton19")), aa);

        // Set the combobox for month
        if (strcmp(month, "January") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 0);
        } else if (strcmp(month, "February") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 1);
        } else if (strcmp(month, "March") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 2);
        } else if (strcmp(month, "April") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 3);
        } else if (strcmp(month, "May") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 4);
        } else if (strcmp(month, "June") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 5);
        } else if (strcmp(month, "July") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 6);
        } else if (strcmp(month, "August") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 7);
        } else if (strcmp(month, "September") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 8);
        } else if (strcmp(month, "October") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 9);
        } else if (strcmp(month, "November") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 10);
        } else if (strcmp(month, "December") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox206")), 11);
        }

        // Set the combobox for availaible
        if (strcmp(available, "24/7") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox207")), 0);
        } else if (strcmp(available, "Weekends only") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox207")), 1);
        } else if (strcmp(available, "Monday to Friday") == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modify, "combobox207")), 2);
        }
    } else {
        // Show error dialog if no service is selected
        show_error_dialog("Please select an service to modify.");
    }
}


void
on_button134_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection4;
    GtkTreeIter iter;
    GtkTreeModel *model;
    GtkWidget *treeview8, *dialog;

   // Declare variables to hold the service's details
    gchar *name, *id_service, *manager_name;
    gchar *available, *s_desc, *s_phnumber, *s_email, *price, *target;
    gchar *day, *month, *year;

    // Get the selected item in the treeview
    treeview8 = lookup_widget(GTK_WIDGET(button), "treeview8");
    selection4 = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview8));

    if (gtk_tree_selection_get_selected(selection4, &model, &iter)) {
        // Retrieve data from the selected row, in the order of the structure fields
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter,
                           0, &name, 
                           1, &id_service, 
                           2, &manager_name, 
                           3, &day, 
                           4, &month, 
                           5, &year, 
                           6, &available, 
                           7, &s_desc, 
                           8, &s_phnumber, 
                           9, &s_email, 
                           10, &price, 
                           11, &target, 
                           -1);
                 

        // Remove the item from the treeview
        gtk_list_store_remove(GTK_LIST_STORE(model), &iter);

        // Call the function to delete the agent from the data source (file, database, etc.)
        delete_service(id_service);  // Assuming this function deletes the service by id

        // Show a success dialog
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_OTHER,
                                        GTK_BUTTONS_OK,
                                        "Service removed successfully ✔");
        gtk_window_set_title(GTK_WINDOW(dialog), "Alert");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);

    } else {
        // Show an error dialog if no item was selected
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_ERROR,
                                        GTK_BUTTONS_OK,
                                        "Please select an serviceto delete.");
        gtk_window_set_title(GTK_WINDOW(dialog), "Alert");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}


void
on_button135_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button136_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *service_list,*treeview8;
service_list = lookup_widget(GTK_WIDGET(button), "service_list");
   gtk_widget_destroy(service_list);
        service_list = create_service_list();
        gtk_widget_show(service_list);
treeview8 = lookup_widget(service_list, "treeview8");
 show_service(treeview8);
}


void
on_button131_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview8, *dialog;
    GtkWidget *entry;

    char searchs[30];
	service s;
    entry = lookup_widget(GTK_WIDGET(button), "entry206");
   treeview8 = lookup_widget(GTK_WIDGET(button), "treeview8");
    strcpy(searchs, gtk_entry_get_text(GTK_ENTRY(entry)));

    FILE *f;
    f = fopen("service2.txt", "r");

    if (strcmp(searchs, "") == 0)
    {        dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_WARNING,
                                        GTK_BUTTONS_OK,
                                        "La recherche n'a pas abouti");
        gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }

//condition search
    else if (f != NULL)
    {
        int founds = 0; 

        while (fscanf(f, "%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^\n]\n",
                  s.name, s.id_service, s.manager_name,
                  s.date.day, s.date.month, s.date.year,
                  s.available, s.s_desc, s.s_phnumber,
                  s.s_email, s.price, s.target) != EOF)
        {
           if ((strcmp(searchs,s.name) == 0)||(strcmp(searchs,s.id_service) == 0))
            {
                founds = 1;
                break; 
            }
        }

        fclose(f);

        if (founds == 0)
        {
            dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_WARNING,
                                            GTK_BUTTONS_OK,
                                            "Aucun résultat trouvé pour votre recherche");
            gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
        }
        else
        {
           search_service(treeview8, searchs);
        }



     }
}


//////


void
on_checkbutton64_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
        checks = 1;
    } else {
        checks = 0; 
    }
}



void
on_checkbutton63_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
        checks = 1;
    } else {
        checks = 0; 
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////


void
on_treeview8_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeview10_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button137_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *service_list, *add,*treeview8;
add = lookup_widget(GTK_WIDGET(button), "add");
   gtk_widget_destroy(add);
        service_list = create_service_list();
        gtk_widget_show (service_list);
treeview8 = lookup_widget(service_list, "treeview8");
show_service(treeview8);
}


void
on_button139_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *add,*service_list,*treeview8;
    add = lookup_widget(GTK_WIDGET(button), "add");

    service d; 

    GtkWidget *dialog;
    GtkWidget  *name,*id_service,*manager_name,*day,*month,*year,*available,*s_desc,*s_phnumber,*s_email,*price;
                


    name = lookup_widget(GTK_WIDGET(button), "entry226");
    id_service = lookup_widget(GTK_WIDGET(button), "entry225");
    manager_name= lookup_widget(GTK_WIDGET(button), "entry227");
    day = lookup_widget(GTK_WIDGET(button), "spinbutton22");
    month = lookup_widget(GTK_WIDGET(button), "combobox210");
    year = lookup_widget(GTK_WIDGET(button), "spinbutton23");
    available = lookup_widget(GTK_WIDGET(button), "combobox209");
    s_desc= lookup_widget(GTK_WIDGET(button), "entry230");
    s_phnumber= lookup_widget(GTK_WIDGET(button), "entry228");
    s_email= lookup_widget(GTK_WIDGET(button), "entry229");
    price = lookup_widget(GTK_WIDGET(button), "spinbutton21");
    

    strcpy(d.s_desc, gtk_entry_get_text(GTK_ENTRY(s_desc)));
    strcpy(d.name, gtk_entry_get_text(GTK_ENTRY(name)));
    if (strcmp(d.name, "") == 0) {
        show_error_dialog("The name can't be empty");
        return;
    }

    strcpy(d.manager_name, gtk_entry_get_text(GTK_ENTRY(manager_name)));
    if (strcmp(d.manager_name, "") == 0) {
        show_error_dialog("The manager name can't be empty");
        return;
    }

// id_service
    strcpy(d.id_service, gtk_entry_get_text(GTK_ENTRY(id_service)));
if (strcmp(d.id_service, "") == 0 ) {
    show_error_dialog("The id_service can't be empty.");
    return;
}

    // Handle date 
    int j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));

    int a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));
    int p = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(price));
    sprintf(d.date.day, "%d", j);  
if (strcmp(d.date.day, "") == 0) {
        show_error_dialog("jour");
        return;
    }


    sprintf(d.date.year, "%d", a);  
if (strcmp(d.date.year, "") == 0) {
        show_error_dialog("year");
        return;
    }
sprintf(d.price, "%d", p);
  //sprintf(d.price, "%d", p);
 
    strcpy(d.s_phnumber, gtk_entry_get_text(GTK_ENTRY(s_phnumber)));
    if (strlen(d.s_phnumber) != 8||!is_digits(d.s_phnumber)) {
        show_error_dialog("Phone number is incorrect");
        return;
    }

    strcpy(d.s_email, gtk_entry_get_text(GTK_ENTRY(s_email)));
    if (strcmp(d.s_email, "") == 0) {
        show_error_dialog("Email can't be empty");
        return;
    }

    
    if (!contain_at(d.s_email)) {
        show_error_dialog("Email invalid");
        return;
    }


    const gchar *available_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(available));
    strcpy(d.available, available_text);


   month = gtk_combo_box_get_active_text(GTK_COMBO_BOX(month));

    strcpy(d.date.month, month);
if (strcmp(d.date.month, "") == 0) {
        show_error_dialog("month");
        return;
    }


       strcpy(d.target,Target);

     if (checks == 0) {
        show_error_dialog("You must accept the general conditions and the confidentiality policy");
        return;
    }


 add_service(d);
checks = 0;
    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_OTHER,
                                    GTK_BUTTONS_OK,
                                    "Added successfully ✔");
    gtk_window_set_title(GTK_WINDOW(dialog), "Alert");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
   gtk_widget_destroy(add);
        service_list = create_service_list();
        gtk_widget_show(service_list);
treeview8 = lookup_widget(service_list, "treeview8");
show_service(treeview8);
}


void
on_radiobutton46_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(Target,"Corporate Clients");}
}





void
on_radiobutton48_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(Target,"Corporate Clients");}
}


void
on_radiobutton47_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(Target,"Members Only");}
}


void
on_radiobutton45_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(Target,"Members Only");}
}


void
on_radiobutton49_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(Target,"General Public");}
}


void
on_radiobutton50_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(Target,"General Public");}

}


void
on_button140_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modify,*service_list,*treeview8;
    modify = lookup_widget(GTK_WIDGET(button), "modify");

    service d; 

    GtkWidget *dialog;
    GtkWidget  *name,*id_service,*manager_name,*day,*month,*year,*available,*s_desc,*s_phnumber,*s_email,*price;
                


    name = lookup_widget(GTK_WIDGET(button), "entry217");
    id_service = lookup_widget(GTK_WIDGET(button), "entry216");
    manager_name= lookup_widget(GTK_WIDGET(button), "entry218");
    day = lookup_widget(GTK_WIDGET(button), "spinbutton18");
    month = lookup_widget(GTK_WIDGET(button), "combobox206");
    year = lookup_widget(GTK_WIDGET(button), "spinbutton20");
    available = lookup_widget(GTK_WIDGET(button), "combobox207");
    s_desc= lookup_widget(GTK_WIDGET(button), "entry221");
    s_phnumber= lookup_widget(GTK_WIDGET(button), "entry219");
    s_email= lookup_widget(GTK_WIDGET(button), "entry220");
    price = lookup_widget(GTK_WIDGET(button), "spinbutton17");
    

    strcpy(d.s_desc, gtk_entry_get_text(GTK_ENTRY(s_desc)));
    strcpy(d.name, gtk_entry_get_text(GTK_ENTRY(name)));
    if (strcmp(d.name, "") == 0) {
        show_error_dialog("The name can't be empty");
        return;
    }

    strcpy(d.manager_name, gtk_entry_get_text(GTK_ENTRY(manager_name)));
    if (strcmp(d.manager_name, "") == 0) {
        show_error_dialog("The manager name can't be empty");
        return;
    }

// id_service
    strcpy(d.id_service, gtk_entry_get_text(GTK_ENTRY(id_service)));
if (strcmp(d.id_service, "") == 0 ) {
    show_error_dialog("The id_service can't be empty.");
    return;
}

    // Handle date 
    int j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));

    int a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));
    int p = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(price));
    sprintf(d.date.day, "%d", j);  
if (strcmp(d.date.day, "") == 0) {
        show_error_dialog("jour");
        return;
    }


    sprintf(d.date.year, "%d", a);  
if (strcmp(d.date.year, "") == 0) {
        show_error_dialog("year");
        return;
    }
sprintf(d.price, "%d", p);
  
 
    strcpy(d.s_phnumber, gtk_entry_get_text(GTK_ENTRY(s_phnumber)));
    if (strlen(d.s_phnumber) != 8||!is_digits(d.s_phnumber)) {
        show_error_dialog("Phone number is incorrect");
        return;
    }

    strcpy(d.s_email, gtk_entry_get_text(GTK_ENTRY(s_email)));
    if (strcmp(d.s_email, "") == 0) {
        show_error_dialog("Email can't be empty");
        return;
    }

    
    if (!contain_at(d.s_email)) {
        show_error_dialog("Email invalid");
        return;
    }


    const gchar *available_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(available));
    strcpy(d.available, available_text);


   month = gtk_combo_box_get_active_text(GTK_COMBO_BOX(month));

    strcpy(d.date.month, month);
if (strcmp(d.date.month, "") == 0) {
        show_error_dialog("month");
        return;
    }


       strcpy(d.target,Target);

     if (checks == 0) {
        show_error_dialog("You must accept the general conditions and the confidentiality policy");
        return;
    }


 update_service(d);
checks = 0;
    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_OTHER,
                                    GTK_BUTTONS_OK,
                                    "Updated successfully ✔");
    gtk_window_set_title(GTK_WINDOW(dialog), "Alert");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
   gtk_widget_destroy(modify);
        service_list = create_service_list();
        gtk_widget_show(service_list);
treeview8 = lookup_widget(service_list, "treeview8");
show_service(treeview8);
}


void
on_button141_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *service_list,*modify,*treeview8;
modify = lookup_widget(GTK_WIDGET(button), "modify");
   gtk_widget_destroy(modify);
        service_list = create_service_list();
        gtk_widget_show(service_list);
treeview8 = lookup_widget(service_list, "treeview8");
show_service(treeview8);
}


void
on_button144_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Parking_Managment,*Authentification;
Authentification = lookup_widget(GTK_WIDGET(button), "Authentification");
   gtk_widget_destroy(Authentification);
        Parking_Managment = create_Parking_Managment();
        gtk_widget_show(Parking_Managment);
}


void
on_button145_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *agent_list,*Authentification;
Authentification = lookup_widget(GTK_WIDGET(button), "Authentification");
   gtk_widget_destroy(Authentification);
        agent_list = create_agent_list();
        gtk_widget_show(agent_list);
}


void
on_button146_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *service_list,*Authentification;
Authentification = lookup_widget(GTK_WIDGET(button), "Authentification");
   gtk_widget_destroy(Authentification);
        service_list = create_service_list();
        gtk_widget_show(service_list);
}


void
on_button147_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Account_Managment,*Authentification;
Authentification = lookup_widget(GTK_WIDGET(button), "Authentification");
   gtk_widget_destroy(Authentification);
        Account_Managment = create_Account_Managment();
        gtk_widget_show(Account_Managment);
}


void
on_button148_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Reservation_Managment,*Authentification;
Authentification = lookup_widget(GTK_WIDGET(button), "Authentification");
   gtk_widget_destroy(Authentification);
        Reservation_Managment = create_Reservation_Managment();
        gtk_widget_show(Reservation_Managment);
}


void
on_button149_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *service_list,*Authentification;
service_list = lookup_widget(GTK_WIDGET(button), "service_list");
   gtk_widget_destroy(service_list);
        Authentification = create_Authentification();
        gtk_widget_show(Authentification);
}


void
on_button117_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *agent_list,*Authentification;
agent_list = lookup_widget(GTK_WIDGET(button), "agent_list");
   gtk_widget_destroy(agent_list);
        Authentification = create_Authentification();
        gtk_widget_show(Authentification);
}

