#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_DATE_LEN 11

// ---------------------------
// Structures and Definitions
// ---------------------------

// Attribute Node: Represents extra attributes for an event (e.g., decorations, catering)
typedef struct Attribute {
    char name[50];
    float cost;
    struct Attribute *next;
} Attribute;

// Event Node: Represents each event with name, date, base cost and attribute list
typedef struct Event {
    char name[MAX_NAME_LEN];
    char date[MAX_DATE_LEN];  // Format: DD-MM-YYYY
    float baseCost;
    Attribute *attributes;    // Linked list of attributes
    struct Event *next;       // Pointer to next event
} Event;

Event *eventList = NULL;  // Head of the event linked list

// Queue Node: Used for processing events in order (FIFO)
typedef struct QueueNode {
    Event *event;
    struct QueueNode *next;
} QueueNode;

QueueNode *front = NULL, *rear = NULL;  // Front and rear of the event queue

// ---------------------------
// Function Prototypes
// ---------------------------

void addEvent();
void displayEvents();
int checkDateClash(char *date);
void addAttributeToEvent(Event *e);
float estimateCost(Event *e);
void enqueue(Event *e);
void processQueue();
void freeAttributes(Attribute *head);
void freeEvents();

// ---------------------------
// Core Functions
// ---------------------------

// Add a new event
void addEvent() {
    Event *newEvent = (Event *)malloc(sizeof(Event));
    newEvent->attributes = NULL;
    newEvent->next = NULL;

    printf("Enter event name: ");
    scanf(" %[^\n]", newEvent->name);

    printf("Enter event date (DD-MM-YYYY): ");
    scanf("%s", newEvent->date);

    if (checkDateClash(newEvent->date)) {
        printf("⚠️  Date clash detected! Another event exists on this date.\n");
    }

    printf("Enter base cost of the event: ");
    scanf("%f", &newEvent->baseCost);

    // Add one or more attributes to the event
    char choice;
    do {
        addAttributeToEvent(newEvent);
        printf("Add another attribute? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Insert event at the beginning of the list
    newEvent->next = eventList;
    eventList = newEvent;

    // Add to queue for processing
    enqueue(newEvent);

    printf("✅ Event added successfully and enqueued for processing.\n");
}

// Add an attribute to a given event
void addAttributeToEvent(Event *e) {
    Attribute *newAttr = (Attribute *)malloc(sizeof(Attribute));

    printf("Enter attribute name: ");
    scanf(" %[^\n]", newAttr->name);

    printf("Enter attribute cost: ");
    scanf("%f", &newAttr->cost);

    // Insert attribute at the beginning of attribute list
    newAttr->next = e->attributes;
    e->attributes = newAttr;
}

// Check if an event already exists on a given date
int checkDateClash(char *date) {
    Event *temp = eventList;
    while (temp != NULL) {
        if (strcmp(temp->date, date) == 0)
            return 1;
        temp = temp->next;
    }
    return 0;
}

// Display all events in the list
void displayEvents() {
    if (!eventList) {
        printf("No events to display.\n");
        return;
    }

    Event *temp = eventList;
    while (temp != NULL) {
        printf("\n📅 Event: %s\n", temp->name);
        printf("   Date: %s\n", temp->date);
        printf("   Base Cost: %.2f\n", temp->baseCost);
        printf("   Attributes:\n");

        Attribute *attr = temp->attributes;
        while (attr != NULL) {
            printf("     - %s (Cost: %.2f)\n", attr->name, attr->cost);
            attr = attr->next;
        }

        printf("   Estimated Total Cost: %.2f\n", estimateCost(temp));
        temp = temp->next;
    }
}

// Estimate total cost of an event (base + all attributes)
float estimateCost(Event *e) {
    float total = e->baseCost;
    Attribute *attr = e->attributes;

    while (attr != NULL) {
        total += attr->cost;
        attr = attr->next;
    }

    return total;
}

// Enqueue event for processing
void enqueue(Event *e) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->event = e;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Process events from the queue
void processQueue() {
    if (!front) {
        printf("📭 Queue is empty.\n");
        return;
    }

    printf("\n📦 Processing Events Queue:\n");

    while (front) {
        printf("-> Processing Event: %s on %s\n", front->event->name, front->event->date);

        QueueNode *temp = front;
        front = front->next;
        free(temp);  // Only free queue node, not the event itself
    }

    rear = NULL;
    printf("✅ All events processed.\n");
}

// Free all attributes of an event
void freeAttributes(Attribute *head) {
    while (head) {
        Attribute *temp = head;
        head = head->next;
        free(temp);
    }
}

// Free all events and their attributes from memory
void freeEvents() {
    while (eventList) {
        Event *temp = eventList;
        eventList = eventList->next;
        freeAttributes(temp->attributes);
        free(temp);
    }
}

// ---------------------------
// Main Function (Menu)
// ---------------------------

int main() {
    int choice;

    do {
        printf("\n===== Event Management System =====\n");
        printf("1. Add Event\n");
        printf("2. Display Events\n");
        printf("3. Process Event Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEvent(); break;
        case 2:
            displayEvents(); break;
        case 3:
            processQueue(); break;
        case 4:
            printf("Exiting...\n");
            freeEvents(); break;
        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
