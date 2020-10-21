		.syntax     unified
		.cpu        cortex-m4
        .text

//------------------------------------------
//extern int32_t Add(int32_t x, int32_t y) ;
//return a + b ;
//------------------------------------------
		.global		Add
        .thumb_func
        .align

Add:
		ADD		r0,r0,r1
		BX		LR

//------------------------------------------
//extern int32_t Less1(int32_t x) ;
//return a - 1 ;
//------------------------------------------
		.global		Less1
        .thumb_func
        .align

Less1:
		ADD		r0,r0,-1
		BX		LR

//------------------------------------------
//extern int32_t Square2x(int32_t x) ;
//return Square(x + x) ;
//------------------------------------------
		.global		Square2x
        .thumb_func
        .align

Square2x:	
		PUSH	{LR}
		ADD		r0,r0,r0
		Bl		Square
		POP		{LR}
		BX		LR

//------------------------------------------
//extern int32_t Last(int32_t x) ;
//return x + SquareRoot(x) ;
//------------------------------------------
		.global		Last
        .thumb_func
        .align

Last:
		PUSH	{LR}
		MOV		r4,r0
		Bl		SquareRoot
		ADD		r0,r0,r4
		POP		{LR}
		BX		LR


		.end