static int T_1 F_1 ( void )
{
unsigned long V_1 ;
void T_2 * V_2 ;
unsigned int V_3 , V_4 ;
if ( ! F_2 () ) {
F_3 ( L_1 ) ;
return - V_5 ;
}
V_1 = F_4 () ;
if ( ! V_1 ) {
F_3 ( L_2 ) ;
return - V_6 ;
}
V_2 = F_5 ( ( V_7 ) V_1 , V_8 ) ;
if ( ! V_2 ) {
F_3 ( L_3 ,
V_1 , V_8 ) ;
return - V_9 ;
}
F_6 ( V_2 ) ;
V_4 = V_2 ? F_7 ( V_2 ) : 1 ;
if ( V_4 > V_10 ) {
F_8 ( L_4 ,
V_4 , V_10 ) ;
V_4 = V_10 ;
}
#ifdef F_9
if ( V_4 > 1 ) {
F_8 ( L_5 ) ;
F_10 () ;
#ifdef F_11
F_12 ( 1 , L_6 ) ;
V_4 = 1 ;
#endif
}
#endif
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_13 ( V_3 , true ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_15 ( unsigned int V_11 ,
struct V_12 * V_13 )
{
void T_2 * V_14 ;
struct V_15 * V_16 ;
int V_17 = 0 ;
T_3 V_18 ;
V_16 = F_16 ( NULL , V_19 ) ;
if ( ! V_16 ) {
F_3 ( L_7 ) ;
return - V_20 ;
}
V_14 = F_17 ( V_16 , 0 ) ;
F_18 ( V_16 ) ;
if ( ! V_14 ) {
F_3 ( L_8 ) ;
return - V_9 ;
}
V_16 = F_19 ( F_20 ( V_11 ) , NULL ) ;
if ( ! V_16 ) {
F_3 ( L_9 , V_11 ) ;
V_17 = - V_20 ;
goto V_21;
}
V_18 = F_21 ( V_22 ) ;
F_22 ( V_18 , V_14 + V_23 ) ;
V_17 = F_23 ( V_16 ) ;
if ( V_17 )
goto V_21;
V_21:
F_14 ( V_14 ) ;
return V_17 ;
}
static void T_1 F_24 ( unsigned int V_24 )
{
int V_17 ;
V_17 = F_1 () ;
if ( V_17 ) {
F_8 ( L_10 ) ;
return;
}
}
