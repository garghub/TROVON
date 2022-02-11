static void T_1
F_1 ( void )
{
if ( V_1 . V_2 )
V_1 . V_2 ( L_1 , 0 ) ;
F_2 ( L_2 ) ;
#ifdef F_3
F_4 () ;
#endif
F_5 () ;
}
static void
F_6 ( struct V_3 * V_4 )
{
T_2 V_5 = F_7 ( V_6 ) ;
F_8 ( V_4 , L_3 ) ;
F_8 ( V_4 , L_4 , V_5 ) ;
}
static int T_1 F_9 ( void )
{
unsigned long V_7 = F_10 () ;
if ( F_11 ( V_7 , L_5 ) )
return 1 ;
return 0 ;
}
static long T_1
F_12 ( void )
{
unsigned int V_8 ;
F_13 ( V_9 , 0 ) ;
F_13 ( V_10 , 0 ) ;
V_8 = F_7 ( V_11 ) ;
V_8 |= V_12 ;
F_13 ( V_11 , V_8 ) ;
asm volatile("isync");
return 0 ;
}
static int T_1 F_14 ( void )
{
F_15 ( NULL , V_13 , NULL ) ;
return 0 ;
}
