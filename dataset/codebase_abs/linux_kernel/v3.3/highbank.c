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
static void T_1 F_14 ( void )
{
F_15 ( V_6 ) ;
F_16 ( 0 , ~ 0UL ) ;
}
static void T_1 F_17 ( void )
{
int V_7 ;
struct V_8 * V_9 ;
void T_2 * V_10 ;
V_9 = F_18 ( NULL , NULL , L_1 ) ;
V_11 = F_19 ( V_9 , 0 ) ;
F_20 ( ! V_11 ) ;
V_9 = F_18 ( NULL , NULL , L_2 ) ;
V_10 = F_19 ( V_9 , 0 ) ;
F_20 ( ! V_10 ) ;
V_7 = F_21 ( V_9 , 0 ) ;
F_22 () ;
F_23 ( V_10 + 0x20 , L_3 ) ;
F_24 ( V_10 , V_7 , L_4 ) ;
}
static void F_25 ( void )
{
F_26 () ;
F_27 ( V_12 , V_13 ) ;
while ( 1 )
F_28 () ;
}
static void T_1 F_29 ( void )
{
V_14 = F_25 ;
F_30 ( NULL , V_15 , NULL , NULL ) ;
}
