static void T_1 F_1 ( void )
{
unsigned long V_1 ;
asm("mrc p15, 4, %0, c15, c0, 0" : "=r" (base));
V_2 . V_3 = F_2 ( V_1 ) ;
F_3 ( & V_2 , 1 ) ;
}
static void T_1 F_4 ( void )
{
F_1 () ;
F_5 () ;
}
void F_6 ( int V_4 , void * V_5 )
{
V_4 = F_7 ( V_4 ) ;
F_8 ( F_9 ( V_5 ) , F_10 ( V_4 ) ) ;
F_11 ( F_10 ( V_4 ) , 16 ) ;
F_12 ( F_13 ( V_4 ) ,
F_13 ( V_4 ) + 15 ) ;
}
static void F_14 ( void )
{
F_15 ( 0x102 , 0x0 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( V_6 ) ;
#ifdef F_18
F_15 ( 0x102 , 0x1 ) ;
F_19 ( 0 , ~ 0UL ) ;
V_7 . V_8 = F_14 ;
#endif
}
static void T_1 F_20 ( void )
{
int V_9 ;
struct V_10 * V_11 ;
void T_2 * V_12 ;
V_11 = F_21 ( NULL , NULL , L_1 ) ;
V_13 = F_22 ( V_11 , 0 ) ;
F_23 ( ! V_13 ) ;
V_11 = F_21 ( NULL , NULL , L_2 ) ;
V_12 = F_22 ( V_11 , 0 ) ;
F_23 ( ! V_12 ) ;
V_9 = F_24 ( V_11 , 0 ) ;
F_25 () ;
V_14 . V_15 = F_26 ( V_11 , 0 ) ;
F_27 ( & V_14 ) ;
F_28 ( V_12 + 0x20 , L_3 ) ;
F_29 ( V_12 , V_9 , L_4 ) ;
F_30 () ;
}
static void F_31 ( void )
{
F_32 () ;
F_33 ( V_16 , V_17 ) ;
while ( 1 )
F_34 () ;
}
static void T_1 F_35 ( void )
{
V_18 = F_31 ;
F_36 ( NULL , V_19 , NULL , NULL ) ;
}
