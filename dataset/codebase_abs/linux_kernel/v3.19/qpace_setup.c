static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const char * V_5 = L_1 ;
V_4 = F_2 ( L_2 ) ;
if ( V_4 )
V_5 = F_3 ( V_4 , L_3 , NULL ) ;
F_4 ( V_2 , L_4 , V_5 ) ;
F_5 ( V_4 ) ;
}
static void F_6 ( char * V_6 , unsigned short V_7 )
{
F_7 ( L_5 , V_7 , V_6 ? V_6 : L_1 ) ;
}
static int T_1 F_8 ( void )
{
int V_8 ;
F_9 ( NULL , V_9 , NULL ) ;
F_10 (node) {
if ( F_11 ( F_12 ( V_8 ) ) == NULL )
continue;
F_13 ( L_6 , V_8 , NULL , 0 ) ;
}
return 0 ;
}
static void T_1 F_14 ( void )
{
#ifdef F_15
V_10 = & V_11 ;
V_12 = & V_13 ;
#endif
F_16 () ;
#ifdef F_17
F_18 () ;
#endif
#ifdef F_19
F_20 () ;
#endif
V_14 = 50000000 ;
F_21 () ;
#ifdef F_22
V_15 = & V_16 ;
#endif
}
static int T_1 F_23 ( void )
{
unsigned long V_4 = F_24 () ;
if ( ! F_25 ( V_4 , L_7 ) )
return 0 ;
F_26 () ;
V_17 = V_18 ;
return 1 ;
}
