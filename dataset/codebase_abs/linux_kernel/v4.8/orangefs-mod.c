static int T_1 F_1 ( void )
{
int V_1 = - 1 ;
T_2 V_2 = 0 ;
V_3 = ( unsigned long long ) V_4 ;
F_2 ( & V_3 , 0 ) ;
F_3 ( V_5 , & V_3 , 0 ) ;
if ( V_3 != 0 )
V_6 = true ;
F_4 ( L_1 ,
V_7 ,
V_5 ,
( unsigned long long ) V_3 ) ;
V_1 = F_5 ( & V_8 ) ;
if ( V_1 )
return V_1 ;
if ( V_9 < 0 )
V_9 = 0 ;
if ( V_10 < 0 )
V_10 = 0 ;
V_1 = F_6 () ;
if ( V_1 < 0 )
goto V_11;
V_1 = F_7 () ;
if ( V_1 < 0 )
goto V_12;
V_13 =
F_8 ( V_14 , sizeof( struct V_15 ) , V_16 ) ;
if ( ! V_13 ) {
F_9 ( L_2 ) ;
V_1 = - V_17 ;
goto V_18;
}
for ( V_2 = 0 ; V_2 < V_14 ; V_2 ++ )
F_10 ( & V_13 [ V_2 ] ) ;
V_1 = F_11 () ;
if ( V_1 < 0 )
goto V_19;
V_1 = F_12 ( 1 ) ;
if ( V_1 )
goto V_20;
V_1 = F_13 () ;
if ( V_1 )
goto V_21;
V_1 = F_14 () ;
if ( V_1 )
goto V_22;
V_1 = F_15 () ;
if ( V_1 )
goto V_23;
V_1 = F_16 () ;
if ( V_1 < 0 ) {
F_9 ( L_3 ,
V_7 ,
V_1 ) ;
goto V_24;
}
V_1 = F_17 ( & V_25 ) ;
if ( V_1 == 0 ) {
F_4 ( L_4 , V_26 ) ;
V_1 = 0 ;
goto V_27;
}
F_18 () ;
V_24:
F_19 () ;
V_23:
V_22:
V_21:
F_20 () ;
V_20:
F_21 () ;
V_19:
F_22 ( V_13 ) ;
V_18:
F_23 () ;
V_12:
F_24 () ;
V_11:
F_25 ( & V_8 ) ;
V_27:
return V_1 ;
}
static void T_3 F_26 ( void )
{
int V_2 = 0 ;
F_27 ( V_28 , L_5 ) ;
F_28 ( & V_25 ) ;
F_20 () ;
F_18 () ;
F_21 () ;
F_19 () ;
F_29 ( ! F_30 ( & V_29 ) ) ;
for ( V_2 = 0 ; V_2 < V_14 ; V_2 ++ )
F_29 ( ! F_30 ( & V_13 [ V_2 ] ) ) ;
F_23 () ;
F_24 () ;
F_22 ( V_13 ) ;
F_25 ( & V_8 ) ;
F_4 ( L_6 , V_26 ) ;
}
void F_31 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_14 ; V_2 ++ ) {
struct V_30 * V_31 ;
struct V_30 * V_32 ;
F_32 ( & V_33 ) ;
F_33 (op,
next,
&htable_ops_in_progress[i],
list) {
F_34 ( V_31 ) ;
F_27 ( V_34 ,
L_7 ,
V_7 ,
F_35 ( V_31 ) ,
V_31 -> V_35 ,
V_36 -> V_37 ) ;
}
F_36 ( & V_33 ) ;
}
}
