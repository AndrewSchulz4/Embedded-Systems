#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

uint32_t Bits2Unsigned(int8_t bits[8])
{
	uint32_t unsigned_value = 0;

	//polynomial expansion where the values are multiplied by 2^n based on what slot they are in
	for (int i = 7; i >= 0; i--)
	{
		unsigned_value += (bits[i] * pow(2, i));
	}

	return unsigned_value;
}

//converts the value similar to bits2signed but the leading largest number is negative
int32_t Bits2Signed(int8_t bits[8])
{
	int32_t signed_value = 0;

	int32_t first = 1;

	for (int i = 7; i >= 0; i--)
	{
		if ((first == 1) && (bits[7] == 1))
		{
			signed_value -= (bits[i] * pow(2, i));
			first = 0;
		}
		else 
		{
			signed_value += (bits[i] * pow(2, i));
		}
	}

	return signed_value;
}


void Increment(int8_t bits[8])
{
	//will have to add one to the last value and check for values over 1
	bits[0]++;
	for (int i = 0; i < 8; i++)
	{
		//if the value is above 1 then carry a value to the next "slot"
		if (bits[i] > 1)
		{
			if ((i + 1) <= 7)
			{
				bits[i + 1]++;
				bits[i] = 0;
			}
			//if the value is over 1 at bits[7] reset
			if(bits[7] > 1)
			{
				bits[7] = 0;
			}
		}
		//exits the loop if there is no overflow
		else
		{
			break;
		}

	}
}

//opposite of bits2unsigned
void Unsigned2Bits(uint32_t n, int8_t bits[8])
{
	//convert new value to binary
	for (int i = 0; i < 8; i++)
	{
		//checking for remainder
		if (n % 2 != 0)
		{
			bits[i] = 1;
		}
		//if there is no remainder
		else
		{
			bits[i] = 0;
		}
		n = (n / 2);
	}
}
