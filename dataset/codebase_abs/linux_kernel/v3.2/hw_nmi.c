T_1 F_1 ( int V_1 )
{
return ( T_1 ) ( V_2 ) * 1000 * V_1 ;
}
void F_2 ( void )
{
int V_3 ;
if ( F_3 ( 0 , & V_4 ) )
return;
F_4 ( F_5 ( V_5 ) , V_6 ) ;
F_6 ( V_7 L_1 ) ;
V_8 -> V_9 ( V_10 ) ;
for ( V_3 = 0 ; V_3 < 10 * 1000 ; V_3 ++ ) {
if ( F_7 ( F_5 ( V_5 ) ) )
break;
F_8 ( 1 ) ;
}
F_9 ( 0 , & V_4 ) ;
F_10 () ;
}
static int T_2
F_11 ( unsigned int V_11 , struct V_12 * V_13 )
{
int V_14 ;
V_14 = F_12 () ;
if ( F_13 ( V_14 , F_5 ( V_5 ) ) ) {
static T_3 V_15 = V_16 ;
F_14 ( & V_15 ) ;
F_6 ( V_17 L_2 , V_14 ) ;
F_15 ( V_13 ) ;
F_16 ( & V_15 ) ;
F_17 ( V_14 , F_5 ( V_5 ) ) ;
return V_18 ;
}
return V_19 ;
}
static int T_4 F_18 ( void )
{
F_19 ( V_20 , F_11 ,
0 , L_3 ) ;
return 0 ;
}
