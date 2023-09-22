#include "monty.h"
/**
 * f_mod - computes the reminder of the division
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void f_mod(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	stack_t *Local_Stack_Queue;

	Local_Stack_Queue = *Copy_Stack_Head;
	if (Local_Stack_Queue && Local_Stack_Queue->next)
	{
		if (Local_Stack_Queue->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", Copy_U32_Counter);
			free_stack(*Copy_Stack_Head);
			free(bus.content);
			fclose(bus.file);
			exit(EXIT_FAILURE);
		}
		Local_Stack_Queue->next->n = Local_Stack_Queue->next->n %
			Local_Stack_Queue->n;
		*Copy_Stack_Head = Local_Stack_Queue->next;
		free(Local_Stack_Queue);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", Copy_U32_Counter);
		free_stack(*Copy_Stack_Head);
		free(bus.content);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
}
