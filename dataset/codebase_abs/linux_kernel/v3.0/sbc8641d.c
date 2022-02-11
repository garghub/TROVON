static void T_1
F_1 ( void )
{
#ifdef F_2
struct V_1 * V_2 ;
#endif
if ( V_3 . V_4 )
V_3 . V_4 ( L_1 , 0 ) ;
#ifdef F_2
F_3 (np, L_2 , L_3 )
F_4 ( V_2 , 0 ) ;
#endif
F_5 ( L_4 ) ;
#ifdef F_6
F_7 () ;
#endif
}
static void
F_8 ( struct V_5 * V_6 )
{
T_2 V_7 = F_9 ( V_8 ) ;
F_10 ( V_6 , L_5 ) ;
F_10 ( V_6 , L_6 , V_7 ) ;
}
static int T_1 F_11 ( void )
{
unsigned long V_9 = F_12 () ;
if ( F_13 ( V_9 , L_7 ) )
return 1 ;
return 0 ;
}
static long T_1
F_14 ( void )
{
unsigned int V_10 ;
F_15 ( V_11 , 0 ) ;
F_15 ( V_12 , 0 ) ;
V_10 = F_9 ( V_13 ) ;
V_10 |= V_14 ;
F_15 ( V_13 , V_10 ) ;
asm volatile("isync");
return 0 ;
}
static int T_1 F_16 ( void )
{
F_17 ( NULL , V_15 , NULL ) ;
return 0 ;
}
