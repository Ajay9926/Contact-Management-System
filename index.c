#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 100

// Define a structure for a contact
typedef struct {
    int id;                 // Contact ID
    char name[MAX_NAME_LENGTH];  // Contact name
    char phone[MAX_NAME_LENGTH]; // Contact phone number
} Contact;

// Function to add a contact to the list
void addContact(Contact contacts[], int *count) {
    // Check if the contact list is full
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    // Create a new contact
    Contact newContact;
    newContact.id = *count + 1;  // Assign a unique ID
    printf("Enter name: ");
    scanf(" %[^\n]", newContact.name);  // Read input with spaces
    printf("Enter phone: ");
    scanf(" %[^\n]", newContact.phone);  // Read input with spaces

    // Add the new contact to the list and increment the count
    contacts[*count] = newContact;
    (*count)++;
    printf("Contact added successfully.\n");
}

// Function to view all contacts in the list
void viewContacts(const Contact contacts[], int count) {
    printf("\nContact List:\n");
    printf("ID\tName\t\tPhone\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\n", contacts[i].id, contacts[i].name, contacts[i].phone);
    }
}

// Function to delete a contact from the list
void deleteContact(Contact contacts[], int *count) {
    // Check if there are no contacts to delete
    if (*count == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    int id;
    printf("Enter ID of contact to delete: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (contacts[i].id == id) {
            found = 1;
            // Shift contacts to fill the deleted contact's position
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully.\n");
            break;
        }
    }

    // If contact not found
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Main function
int main() {
    Contact contacts[MAX_CONTACTS]; // Array to store contacts
    int count = 0;  // Number of contacts
    int choice;     // User's choice

    // Menu-driven loop
    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n2. View Contacts\n3. Delete Contact\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user's choice
        switch (choice) {
            case 1:
                addContact(contacts, &count); // Add a contact
                break;
            case 2:
                viewContacts(contacts, count); // View all contacts
                break;
            case 3:
                deleteContact(contacts, &count); // Delete a contact
                break;
            case 4:
                return 0; // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
