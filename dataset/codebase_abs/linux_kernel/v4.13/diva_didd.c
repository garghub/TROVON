static char * F_1 ( const char * V_1 )
{
char * V_2 ;
char * V_3 ;
if ( ( V_3 = strchr ( V_1 , ':' ) ) ) {
V_2 = V_3 + 2 ;
V_3 = strchr ( V_2 , '$' ) ;
* -- V_3 = 0 ;
} else
V_2 = L_1 ;
return V_2 ;
}
static int F_2 ( struct V_4 * V_5 , void * V_6 )
{
char V_7 [ 32 ] ;
strcpy ( V_7 , V_8 ) ;
F_3 ( V_5 , L_2 , V_9 ) ;
F_3 ( V_5 , L_3 , V_10 ) ;
F_3 ( V_5 , L_4 , V_11 ) ;
F_3 ( V_5 , L_5 ,
V_12 , V_13 ) ;
F_3 ( V_5 , L_6 , F_1 ( V_7 ) ) ;
return 0 ;
}
static int F_4 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
return F_5 ( V_15 , F_2 , NULL ) ;
}
static int T_1 F_6 ( void )
{
V_16 = F_7 ( L_7 , V_17 . V_18 ) ;
if ( V_16 ) {
V_19 = F_8 ( V_10 , V_20 , V_16 ,
& V_21 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
}
static void F_9 ( void )
{
F_10 ( V_10 , V_16 ) ;
F_10 ( L_7 , V_17 . V_18 ) ;
}
static int T_1 F_11 ( void )
{
char V_7 [ 32 ] ;
int V_22 = 0 ;
F_12 ( V_23 L_2 , V_9 ) ;
F_12 ( V_23 L_8 , V_10 , V_11 ) ;
strcpy ( V_7 , V_8 ) ;
F_12 ( L_9 , F_1 ( V_7 ) ,
V_12 , V_13 ) ;
if ( ! F_6 () ) {
F_12 ( V_24 L_10 ,
V_10 ) ;
V_22 = - V_25 ;
goto V_26;
}
if ( ! F_13 () ) {
F_12 ( V_24 L_11 ,
V_10 ) ;
#ifdef F_14
F_9 () ;
#endif
V_22 = - V_25 ;
goto V_26;
}
V_26:
return ( V_22 ) ;
}
static void T_2 F_15 ( void )
{
F_16 () ;
F_9 () ;
F_12 ( V_23 L_12 , V_10 ) ;
}
