static int T_1 F_1 ( void )
{
int V_1 = - 1 ;
T_2 V_2 = 0 ;
V_1 = F_2 ( & V_3 ) ;
if ( V_1 )
return V_1 ;
if ( V_4 < 0 )
V_4 = 0 ;
if ( V_5 < 0 )
V_5 = 0 ;
V_1 = F_3 () ;
if ( V_1 < 0 )
goto V_6;
V_1 = F_4 () ;
if ( V_1 < 0 )
goto V_7;
V_8 =
F_5 ( V_9 , sizeof( struct V_10 ) , V_11 ) ;
if ( ! V_8 ) {
F_6 ( L_1 ) ;
V_1 = - V_12 ;
goto V_13;
}
for ( V_2 = 0 ; V_2 < V_9 ; V_2 ++ )
F_7 ( & V_8 [ V_2 ] ) ;
V_1 = F_8 () ;
if ( V_1 < 0 )
goto V_14;
V_1 = F_9 ( 1 ) ;
if ( V_1 )
goto V_15;
V_1 = F_10 ( V_16 ) ;
if ( V_1 )
goto V_17;
V_1 = F_11 () ;
if ( V_1 )
goto V_18;
V_1 = F_12 () ;
if ( V_1 < 0 ) {
F_6 ( L_2 ,
V_19 ,
V_1 ) ;
goto V_20;
}
V_1 = F_13 ( & V_21 ) ;
if ( V_1 == 0 ) {
F_14 ( L_3 ,
V_19 ,
V_22 ) ;
V_1 = 0 ;
goto V_23;
}
F_15 () ;
V_20:
F_16 () ;
V_18:
V_17:
F_17 () ;
V_15:
F_18 () ;
V_14:
F_19 ( V_8 ) ;
V_13:
F_20 () ;
V_7:
F_21 () ;
V_6:
F_22 ( & V_3 ) ;
V_23:
return V_1 ;
}
static void T_3 F_23 ( void )
{
int V_2 = 0 ;
F_24 ( V_24 , L_4 ) ;
F_25 ( & V_21 ) ;
F_17 () ;
F_15 () ;
F_18 () ;
F_16 () ;
F_26 ( ! F_27 ( & V_25 ) ) ;
for ( V_2 = 0 ; V_2 < V_9 ; V_2 ++ )
F_26 ( ! F_27 ( & V_8 [ V_2 ] ) ) ;
F_20 () ;
F_21 () ;
F_19 ( V_8 ) ;
F_22 ( & V_3 ) ;
F_14 ( L_5 , V_22 ) ;
}
void F_28 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_9 ; V_2 ++ ) {
struct V_26 * V_27 ;
struct V_26 * V_28 ;
F_29 ( & V_29 ) ;
F_30 (op,
next,
&orangefs_htable_ops_in_progress[i],
list) {
F_31 ( V_27 ) ;
F_24 ( V_30 ,
L_6 ,
V_19 ,
F_32 ( V_27 ) ,
V_27 -> V_31 ,
V_32 -> V_33 ) ;
}
F_33 ( & V_29 ) ;
}
}
