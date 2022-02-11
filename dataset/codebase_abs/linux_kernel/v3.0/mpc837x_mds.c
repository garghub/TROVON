static int F_1 ( void )
{
struct V_1 * V_2 ;
const void * V_3 , * V_4 ;
void T_1 * V_5 = NULL ;
T_2 V_6 ;
int V_7 ;
V_7 = F_2 () ;
if ( V_7 )
return V_7 ;
V_2 = F_3 ( NULL , NULL , L_1 ) ;
if ( V_2 ) {
V_5 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
}
if ( ! V_5 )
return - 1 ;
V_2 = F_6 ( NULL , L_2 ) ;
if ( ! V_2 ) {
V_7 = - V_8 ;
goto V_9;
}
V_3 = F_7 ( V_2 , L_3 , NULL ) ;
if ( V_3 && ! strcmp ( V_3 , L_4 ) ) {
F_8 ( V_5 + 12 , V_10 ) ;
} else if ( V_3 && ! strcmp ( V_3 , L_5 ) ) {
V_4 = F_7 ( V_2 , L_6 , NULL ) ;
V_6 = F_9 ( V_5 + 12 ) & ~ V_11 ;
V_6 |= V_10 ;
if ( V_4 && ! strcmp ( V_4 , L_7 ) )
V_6 |= V_12 ;
F_10 ( V_5 + 12 , V_6 ) ;
} else {
F_11 ( V_13 L_8 ) ;
}
F_5 ( V_2 ) ;
V_9:
F_12 ( V_5 ) ;
return V_7 ;
}
static void T_3 F_13 ( void )
{
#ifdef F_14
struct V_1 * V_2 ;
#endif
if ( V_14 . V_15 )
V_14 . V_15 ( L_9 , 0 ) ;
#ifdef F_14
F_15 (np, L_10 , L_11 )
F_16 ( V_2 ) ;
F_15 (np, L_10 , L_12 )
F_16 ( V_2 ) ;
#endif
F_1 () ;
}
static int T_3 F_17 ( void )
{
F_18 ( NULL , V_16 , NULL ) ;
return 0 ;
}
static void T_3 F_19 ( void )
{
struct V_1 * V_2 ;
V_2 = F_3 ( NULL , NULL , L_13 ) ;
if ( ! V_2 )
return;
F_20 ( V_2 , 0 ) ;
F_21 () ;
}
static int T_3 F_22 ( void )
{
unsigned long V_17 = F_23 () ;
return F_24 ( V_17 , L_14 ) ;
}
