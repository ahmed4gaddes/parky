#ifndef AGENT_H_
#define AGENT_H_

#include <gtk/gtk.h>

typedef struct {
    char day[60];
    char month[60];
    char year[60];
}Date;

typedef struct {
    char id_parking[60];
    char first_name[60];
    char last_name[60];
    Date birth_date;
    char civil_status[60];
    char cin[60];
    char phone_number[60];
    char email[60];
    char address[60];
    char job_title[60];
    char contract_duration[60];
}Agent;



bool is_parking_exist(const char *parking_id);
bool is_cin_exist(const char *cin);
int is_all_digits(const char *str) ;
int contains_at(const char *email);



void add_agent(Agent a);
void update_agent(Agent updated_agent);
void delete_agent(const char *cin_to_delete);

void show_agents(GtkWidget *fr);
void search_agents(GtkWidget *fr, const char *recherche);
void search_reservation_by_conditions(GtkWidget *fr, const char *id_parking, const char *date);


#endif

