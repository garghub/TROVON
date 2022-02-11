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
if ( F_8 ( V_6 , L_3 ,
( V_7 * ) & V_8 ) )
F_9 ( L_4 ) ;
V_9 = F_10 ( V_6 , 0 ) ;
V_6 = F_7 ( NULL , NULL , L_5 ) ;
V_10 = F_10 ( V_6 , 0 ) ;
}
static void T_1 F_11 ( void )
{
F_12 () ;
F_6 () ;
}
static void F_13 ( enum V_11 V_12 , const char * V_13 )
{
V_7 V_14 ;
V_14 = F_14 ( V_10 + V_15 ) ;
if ( V_12 == V_16 )
V_14 |= V_17 ;
else
V_14 |= V_18 ;
F_15 ( V_14 , V_10 + V_15 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( 0 , ~ 0UL ) ;
F_18 ( NULL , V_19 , NULL , NULL ) ;
}
