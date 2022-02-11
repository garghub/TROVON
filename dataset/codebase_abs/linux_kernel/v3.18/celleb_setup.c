static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const char * V_5 = L_1 ;
V_4 = F_2 ( L_2 ) ;
if ( V_4 )
V_5 = F_3 ( V_4 , L_3 , NULL ) ;
F_4 ( V_2 , L_4 , V_6 , V_5 ) ;
F_5 ( V_4 ) ;
}
static int T_1 F_6 ( char * V_7 )
{
F_7 ( V_6 , V_7 , sizeof( V_6 ) ) ;
return 0 ;
}
static void F_8 ( char * V_8 , unsigned short V_9 )
{
F_9 ( L_5 , V_9 , V_8 ? V_8 : L_1 ) ;
}
static void T_1 F_10 ( void )
{
V_10 = 50000000 ;
#ifdef F_11
V_11 = & V_12 ;
#endif
}
static int T_1 F_12 ( void )
{
F_13 ( NULL , V_13 , NULL ) ;
return 0 ;
}
static void T_1 F_14 ( void )
{
#ifdef F_15
V_14 = & V_15 ;
V_16 = & V_17 ;
#endif
F_10 () ;
}
static int T_1 F_16 ( void )
{
unsigned long V_4 = F_17 () ;
if ( ! F_18 ( V_4 , L_6 ) )
return 0 ;
V_18 |= V_19
| V_20 | V_21 ;
F_19 () ;
return 1 ;
}
static void T_1 F_20 ( void )
{
F_21 () ;
F_22 () ;
}
static void T_1 F_23 ( void )
{
#ifdef F_15
V_14 = & V_22 ;
V_16 = & V_17 ;
#endif
F_24 () ;
#ifdef F_25
F_26 () ;
#endif
#ifdef F_27
F_28 () ;
#endif
F_29 () ;
F_10 () ;
}
static int T_1 F_30 ( void )
{
unsigned long V_4 = F_17 () ;
if ( F_18 ( V_4 , L_6 ) ||
! F_18 ( V_4 , L_7 ) )
return 0 ;
V_18 |= V_19 ;
F_31 () ;
return 1 ;
}
