T_1 F_1 ( int V_1 )
{
return ( T_1 ) ( V_2 ) * 1000 * V_1 ;
}
void F_2 ( bool V_3 )
{
int V_4 ;
int V_5 = F_3 () ;
if ( F_4 ( 0 , & V_6 ) ) {
F_5 () ;
return;
}
F_6 ( F_7 ( V_7 ) , V_8 ) ;
if ( ! V_3 )
F_8 ( V_5 , F_7 ( V_7 ) ) ;
if ( ! F_9 ( F_7 ( V_7 ) ) ) {
F_10 ( L_1 ,
( V_3 ? L_2 : L_3 ) ) ;
V_9 -> V_10 ( F_7 ( V_7 ) , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < 10 * 1000 ; V_4 ++ ) {
if ( F_9 ( F_7 ( V_7 ) ) )
break;
F_11 ( 1 ) ;
F_12 () ;
}
F_13 ( 0 , & V_6 ) ;
F_14 () ;
F_5 () ;
}
static int
F_15 ( unsigned int V_12 , struct V_13 * V_14 )
{
int V_5 ;
V_5 = F_16 () ;
if ( F_17 ( V_5 , F_7 ( V_7 ) ) ) {
static T_2 V_15 = V_16 ;
F_18 ( & V_15 ) ;
F_19 ( V_17 L_4 , V_5 ) ;
F_20 ( V_14 ) ;
F_21 ( & V_15 ) ;
F_8 ( V_5 , F_7 ( V_7 ) ) ;
return V_18 ;
}
return V_19 ;
}
static int T_3 F_22 ( void )
{
F_23 ( V_20 , F_15 ,
0 , L_5 ) ;
return 0 ;
}
