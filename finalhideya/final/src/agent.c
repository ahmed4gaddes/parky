 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>  
#include<gtk/gtk.h>
#include <ctype.h>

#include "agent.h"
#include "reservation.h"
#include "parking.h"

//**********************************
enum {
    EIdParking,
    EFirstName,
    ELastName,
    EDay,
    EMonth,
    EYear,
    ECivilStatus,
    ECIN,
    EPhoneNumber,
    EEmail,
    EAddress,
    EJobTitle,
    EContractDuration,
    COLUMNS
};
//**********************************************************
enum {
    EIdUser,
    ERes_Id,
    EIdPark,
    EPhone,
    EDuration,
    EOption,
    EPriority,
    EDate,
    COLUMNS_BOOK
};
//**********************************************************


void add_agent(Agent a) {
    FILE *f = fopen("agents.txt", "a");

    fprintf(f, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
	    a.id_parking,
            a.first_name,
            a.last_name,
            a.birth_date.day, a.birth_date.month, a.birth_date.year,
	    a.civil_status,
            a.cin,
            a.phone_number,
            a.email,
            a.address,
            a.job_title,
            a.contract_duration);

    fclose(f);

}




//**********************************************

bool is_parking_exist(const char *parking_id) {
    FILE *f;
    Parking p;


    f = fopen("parkings.txt", "r"); 
    if (f == NULL) {
        perror("Unable to open file");
        return ;  
    }


    while (fscanf(f, "%s %s %s %s %d %s %s %d %d %s\n", 
                  p.parking_id, p.parking_name, p.address, p.parking_type, 
                  &p.ability, p.opening_hours, p.pricing, &p.confirm, &p.cancel, p.agent_id) != EOF) {

        if (strcmp(p.parking_id, parking_id) == 0) {
            fclose(f); 
            return true; 
        }
    }

    fclose(f);  
    return false; 
}






//**********************************************************

bool is_cin_exist(const char *cin) {
    FILE *f;
    Agent temp;


    f = fopen("agents.txt", "r"); 



    while (fscanf(f, "%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^\n]\n",
                temp.id_parking,  temp.first_name, temp.last_name, temp.birth_date.day, temp.birth_date.month, temp.birth_date.year,
                  temp.civil_status, temp.cin, temp.phone_number, temp.email, temp.address, temp.job_title, temp.contract_duration) != EOF) {

        if (strcmp(temp.cin, cin) == 0) {
            fclose(f); 
            return true; 
        }
    }

    fclose(f);  
    return false; 
}


int is_all_digits(const char *str) {

    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0; 
        }
    }
    return 1; 
}






int contains_at(const char *email) {
    return strchr(email, '@') != NULL;
}



//**********************************************************




void update_agent(Agent updated_agent) {
    FILE *f = fopen("agents.txt", "r");
    FILE *f_temp = fopen("agents_temp.txt", "w+");
    Agent temp;
    int found = 0;

    if (f == NULL) {
        printf("Error opening agents file for reading.\n");
        return;
    }

    if (f_temp == NULL) {
        printf("Error opening temporary file for writing.\n");
        fclose(f);
        return;
    }

    while (fscanf(f, "%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^\n]\n",
                temp.id_parking,  temp.first_name, temp.last_name, temp.birth_date.day, temp.birth_date.month, temp.birth_date.year,
                  temp.civil_status, temp.cin, temp.phone_number, temp.email, temp.address, temp.job_title, temp.contract_duration) != EOF) {
        

        if (strcmp(temp.cin, updated_agent.cin) == 0) {

            fprintf(f_temp, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
                     updated_agent.id_parking,updated_agent.first_name, updated_agent.last_name, updated_agent.birth_date.day,
                    updated_agent.birth_date.month, updated_agent.birth_date.year, updated_agent.civil_status,
                    updated_agent.cin, updated_agent.phone_number, updated_agent.email, updated_agent.address,
                    updated_agent.job_title, updated_agent.contract_duration);
            found = 1;
        } else {

            fprintf(f_temp, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
                    temp.id_parking,temp.first_name, temp.last_name, temp.birth_date.day, temp.birth_date.month, temp.birth_date.year,
                    temp.civil_status, temp.cin, temp.phone_number, temp.email, temp.address,
                    temp.job_title, temp.contract_duration);
        }
    }

    fclose(f);
    fclose(f_temp);

    if (found) {
        remove("agents.txt");
        rename("agents_temp.txt", "agents.txt");
        printf("Agent updated successfully.\n");
    } else {
        printf("Agent not found.\n");
        remove("agents_temp.txt"); 
    }
}




//**********************************************************



void delete_agent(const char *cin_to_delete) {
    FILE *f, *temp_file;
    Agent agent;
    int found = 0;


    f = fopen("agents.txt", "r");
    if (f == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    temp_file = fopen("temp_agents.txt", "w");
    if (temp_file == NULL) {
        perror("Unable to open temporary file for writing");
        fclose(f);
        return;
    }


    while (fscanf(f, "%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^\n]\n",
                  agent.id_parking,agent.first_name, agent.last_name, agent.birth_date.day, agent.birth_date.month, agent.birth_date.year,
                  agent.civil_status, agent.cin, agent.phone_number, agent.email, agent.address, agent.job_title, agent.contract_duration) != EOF) {


        if (strcmp(agent.cin, cin_to_delete) == 0) {
            found = 1;  
            continue;   
        }

        fprintf(temp_file, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
                agent.id_parking,agent.first_name, agent.last_name, agent.birth_date.day, agent.birth_date.month, agent.birth_date.year,
                agent.civil_status, agent.cin, agent.phone_number, agent.email, agent.address, agent.job_title, agent.contract_duration);
    }


    fclose(f);
    fclose(temp_file);


        remove("agents.txt");  
        rename("temp_agents.txt", "agents.txt");  

    
}





//**********************************************************







void show_agents(GtkWidget *fr) {
    Agent d; 
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    FILE *f;

    
    store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 if (store == NULL) {
        fprintf(stderr, "Error: Failed to create GtkListStore\n");
        return;  // Handle the error gracefully
    }
    if (gtk_tree_view_get_model(GTK_TREE_VIEW(fr)) == NULL) {

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Id Parking", renderer, "text", EIdParking, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("First Name", renderer, "text", EFirstName, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Last Name", renderer, "text", ELastName, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

       
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Day", renderer, "text", EDay, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Month", renderer, "text", EMonth, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Year", renderer, "text", EYear, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Civil Status", renderer, "text", ECivilStatus, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text", ECIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Phone Number", renderer, "text", EPhoneNumber, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Email", renderer, "text", EEmail, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Address", renderer, "text", EAddress, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Job Title", renderer, "text", EJobTitle, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Contract Duration", renderer, "text", EContractDuration, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);
    }


    f = fopen("agents.txt", "r");
    if (f == NULL) {
        perror("Unable to open file");
        return;
    }


    while (fscanf(f, "%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^\n]\n",d.id_parking,d.first_name, d.last_name, d.birth_date.day, d.birth_date.month, d.birth_date.year,
        d.civil_status, d.cin, d.phone_number, d.email, d.address, d.job_title, d.contract_duration) != EOF) {

        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter,EIdParking,d.id_parking,
                           EFirstName, d.first_name, ELastName, d.last_name,
                           EDay, d.birth_date.day, EMonth, d.birth_date.month, EYear, d.birth_date.year,
                           ECivilStatus, d.civil_status, ECIN, d.cin,
                           EPhoneNumber, d.phone_number, EEmail, d.email, 
                           EAddress, d.address, EJobTitle, d.job_title, 
                           EContractDuration, d.contract_duration, -1);
    }

    
    gtk_tree_view_set_model(GTK_TREE_VIEW(fr), GTK_TREE_MODEL(store));
    g_object_unref(store);  

    fclose(f); 
}


//*******************************************************************************

void search_agents(GtkWidget *fr, const char *recherche) { 
    Agent d; 
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    FILE *f;


    store = gtk_list_store_new(COLUMNS, 
                               G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, 
                               G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, 
                               G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


    if (store == NULL) {
        fprintf(stderr, "Error: Failed to create GtkListStore\n");
        return; 
    }

    if (gtk_tree_view_get_model(GTK_TREE_VIEW(fr)) == NULL) {

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("First Name", renderer, "text", EFirstName, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Last Name", renderer, "text", ELastName, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Day", renderer, "text", EDay, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Month", renderer, "text", EMonth, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Year", renderer, "text", EYear, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Civil Status", renderer, "text", ECivilStatus, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text", ECIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Phone Number", renderer, "text", EPhoneNumber, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Email", renderer, "text", EEmail, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Address", renderer, "text", EAddress, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Job Title", renderer, "text", EJobTitle, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Contract Duration", renderer, "text", EContractDuration, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);
    }


    f = fopen("agents.txt", "r");
    if (f == NULL) {
        perror("Unable to open file");
        return;
    }

    while (fscanf(f, "%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^\n]\n",d.id_parking,d.first_name, d.last_name, d.birth_date.day, d.birth_date.month, d.birth_date.year,
        d.civil_status, d.cin, d.phone_number, d.email, d.address, d.job_title, d.contract_duration) != EOF) {

//recherche mta3 il home 

        if ((strcmp(d.first_name, recherche) == 0)||(strcmp(d.last_name,recherche) == 0)||(strcmp(d.cin,recherche) == 0)||(strcmp(d.phone_number,recherche) == 0)||(strcmp(d.job_title,recherche) == 0)) {
            gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter,EIdParking,d.id_parking,
                           EFirstName, d.first_name, ELastName, d.last_name,
                           EDay, d.birth_date.day, EMonth, d.birth_date.month, EYear, d.birth_date.year,
                           ECivilStatus, d.civil_status, ECIN, d.cin,
                           EPhoneNumber, d.phone_number, EEmail, d.email, 
                           EAddress, d.address, EJobTitle, d.job_title, 
                           EContractDuration, d.contract_duration, -1);
        }
    }

    gtk_tree_view_set_model(GTK_TREE_VIEW(fr), GTK_TREE_MODEL(store));


    g_object_unref(store);  

    fclose(f);
}





//**********************************************************





void search_reservation_by_conditions(GtkWidget *fr, const char *id_parking, const char *date) {
    Book B;
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    FILE *f;

    store = gtk_list_store_new(COLUMNS_BOOK, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                               G_TYPE_FLOAT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);

    if (store == NULL) {
        fprintf(stderr, "Error: Failed to create GtkListStore\n");
        return;
    }

    if (gtk_tree_view_get_model(GTK_TREE_VIEW(fr)) == NULL) {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("User ID", renderer, "text", EIdUser, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Reservation ID", renderer, "text", ERes_Id, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Parking ID", renderer, "text", EIdPark, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Phone Number", renderer, "text", EPhone, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Duration", renderer, "text", EDuration, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Option", renderer, "text", EOption, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Priority", renderer, "text", EPriority, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text", EDate, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(fr), column);
    }

    f = fopen("reservations.txt", "r");
    if (f == NULL) {
        perror("Unable to open file");
        return;
    }

    while (fscanf(f, "%s %s %s %s %f %d %d %s\n", B.u_id, B.res_id, B.p_id, B.ph_num, 
                  &B.duration, &B.option, &B.priority, B.date) != EOF) {
        if (strcmp(B.p_id, id_parking) == 0 && strcmp(B.date, date) == 0) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EIdUser, B.u_id, ERes_Id, B.res_id, 
                               EIdPark, B.p_id, EPhone, B.ph_num, 
                               EDuration, B.duration, EOption, B.option, 
                               EPriority, B.priority, EDate, B.date, -1);
        }
    }

    gtk_tree_view_set_model(GTK_TREE_VIEW(fr), GTK_TREE_MODEL(store));
    g_object_unref(store);
    fclose(f);
}

