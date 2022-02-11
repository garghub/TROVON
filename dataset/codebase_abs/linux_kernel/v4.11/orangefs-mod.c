static int T_1 F_1 ( void )
{
int V_1 = - 1 ;
T_2 V_2 = 0 ;
if ( V_3 < 0 )
V_3 = 0 ;
if ( V_4 < 0 )
V_4 = 0 ;
V_1 = F_2 () ;
if ( V_1 < 0 )
goto V_5;
V_1 = F_3 () ;
if ( V_1 < 0 )
goto V_6;
V_7 =
F_4 ( V_8 , sizeof( struct V_9 ) , V_10 ) ;
if ( ! V_7 ) {
F_5 ( L_1 ) ;
V_1 = - V_11 ;
goto V_12;
}
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ )
F_6 ( & V_7 [ V_2 ] ) ;
V_1 = F_7 () ;
if ( V_1 < 0 )
goto V_13;
V_1 = F_8 ( 1 ) ;
if ( V_1 )
goto V_14;
V_1 = F_9 ( V_15 ) ;
if ( V_1 )
goto V_16;
V_1 = F_10 () ;
if ( V_1 )
goto V_17;
V_1 = F_11 () ;
if ( V_1 < 0 ) {
F_5 ( L_2 ,
V_18 ,
V_1 ) ;
goto V_19;
}
V_1 = F_12 ( & V_20 ) ;
if ( V_1 == 0 ) {
F_13 ( L_3 ,
V_18 ,
V_21 ) ;
V_1 = 0 ;
goto V_5;
}
F_14 () ;
V_19:
F_15 () ;
V_17:
V_16:
F_16 () ;
V_14:
F_17 () ;
V_13:
F_18 ( V_7 ) ;
V_12:
F_19 () ;
V_6:
F_20 () ;
V_5:
return V_1 ;
}
static void T_3 F_21 ( void )
{
int V_2 = 0 ;
F_22 ( V_22 , L_4 ) ;
F_23 ( & V_20 ) ;
F_16 () ;
F_14 () ;
F_17 () ;
F_15 () ;
F_24 ( ! F_25 ( & V_23 ) ) ;
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ )
F_24 ( ! F_25 ( & V_7 [ V_2 ] ) ) ;
F_19 () ;
F_20 () ;
F_18 ( V_7 ) ;
F_13 ( L_5 , V_21 ) ;
}
void F_26 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ ) {
struct V_24 * V_25 ;
struct V_24 * V_26 ;
F_27 ( & V_27 ) ;
F_28 (op,
next,
&orangefs_htable_ops_in_progress[i],
list) {
F_29 ( V_25 ) ;
F_22 ( V_28 ,
L_6 ,
V_18 ,
F_30 ( V_25 ) ,
V_25 -> V_29 ,
V_30 -> V_31 ) ;
}
F_31 ( & V_27 ) ;
}
}
