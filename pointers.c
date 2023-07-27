#include <stdio.h>
#include "inventory.h"

/**
 * print_oct - Print octal representation of an integer.
 * main - Start of the function
 * @value: The integer value to be printed in octal.
 */
void print_oct(const int *value)
{
	/* Check if the value is not NULL*/
	if (value == NULL)
	{
	printf("Error: NULL pointer!\n");
	return;
	}
	/*Print the octal representation of the integer*/
	printf("Octal representation: %o\n", *value);
}

/**
 * print_octal - Print octal representation of inventory data.
 * @list: Pointer to the inventory structure.
 */
void print_octal(const inventory_t *list)
{
	/*Check if the list is not NULL*/
	if (list == NULL)
	{
	printf("Error: NULL inventory list!\n");
	return;
	}

	/*Print the octal representation of the inventory fields*/
	/*For example:*/
	/*printf("Item ID (octal): %o\n", list->item_id);*/
	/*printf("Item Quantity (octal): %o\n", list->quantity);*/
	/*... (print other fields as needed)*/
}

/**
 * modify_inventory - Modify inventory item using a pointer.
 * @item: Pointer to the inventory item to be modified.
 * @new_id: The new item ID to set.
 * @new_quantity: The new quantity to set.
 */
void modify_inventory(inventory_t *item, int new_id, int new_quantity)
{
	/*Check if the item pointer is not NULL*/
	if (item == NULL)
	{
	printf("Error: NULL inventory item!\n");
	return;
	}

	/*Modify the inventory item's fields*/
	item->item_id = new_id;
	item->quantity = new_quantity;
}

/**
 * main - Entry point of the program.
 * Return: 0 on success.
 */
int main(void)
{
	/*Example usage of the print_oct function with an integer value*/
	int exampleValue = 42;

	print_oct(&exampleValue);

	/*Example usage of the print_octal function with inventory data*/
	inventory_t item1;

	item1.item_id = 1234;
	item1.quantity = 42;

	print_octal(&item1);


	/*Example usage of modifying inventory using a pointer*/
	inventory_t item2;

	item2.item_id = 5678;
	item2.quantity = 100;

	printf("Before modification:\n");
	print_octal(&item2);

	modify_inventory(&item2, 9876, 50);

	printf("After modification:\n");
	print_octal(&item2);

	return (0);
}

