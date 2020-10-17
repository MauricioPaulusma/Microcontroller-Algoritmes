//////////////////////////////////////////////////////////////////////////
// 	Name: Wait_For_Button_Press
// 	Function: This function waits in blockin mode for button B1 to be pressed.
// 	Arguments: void
//	Returns: void
void Wait_For_Button_Press(void)
{
	uint8_t button_state;
	uint32_t time;
	uint16_t debounce_time  = 100; // debounce time in milliseconds

	uint8_t high_state, low_state;

	while(1) // this double loop will check if the button reads a high state for t = debounce_time in milliseconds
	{
		time = HAL_GetTick();
		while(1)
		{
			button_state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
			if(button_state == 0)
				break;
			else if((HAL_GetTick() - time) > debounce_time)
				high_state = 1;
			else
				continue;
		}
		if(high_state == 1)
			break;
	}

	while(1) // this double loop will check if the button reads a high state for t = debounce_time in milliseconds
	{
		time = HAL_GetTick();
		while(1)
		{
			button_state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
			if(button_state == 1)
				break;
			else if((HAL_GetTick() - time) > debounce_time)
				return;
			else
				continue;
		}
	}
}
