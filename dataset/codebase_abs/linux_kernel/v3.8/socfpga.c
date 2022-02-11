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
F_3 ( & V_4 , 1 ) ;
F_5 ( L_1 ) ;
}
void T_1 F_6 ( void )
{
struct V_5 * V_6 ;
V_6 = F_7 ( NULL , NULL , L_2 ) ;
V_7 = F_8 ( V_6 , 0 ) ;
V_6 = F_7 ( NULL , NULL , L_3 ) ;
V_8 = F_8 ( V_6 , 0 ) ;
}
static void T_1 F_9 ( void )
{
F_10 ( V_9 ) ;
F_6 () ;
}
static void F_11 ( char V_10 , const char * V_11 )
{
}
static void T_1 F_12 ( void )
{
F_13 ( 0 , ~ 0UL ) ;
F_14 ( NULL , V_12 , NULL , NULL ) ;
F_15 () ;
}
