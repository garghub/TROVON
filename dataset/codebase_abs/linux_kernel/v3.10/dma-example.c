static int T_1 F_1 ( void )
{
int V_1 ;
unsigned int V_2 ;
unsigned int V_3 ;
struct V_4 V_5 [ 10 ] ;
F_2 ( V_6 L_1 ) ;
if ( F_3 ( & V_7 , V_8 , V_9 ) ) {
F_2 ( V_10 L_2 ) ;
return - V_11 ;
}
F_2 ( V_6 L_3 , F_4 ( & V_7 ) ) ;
F_5 ( & V_7 , L_4 , 4 ) ;
for ( V_1 = 0 ; V_1 != 9 ; V_1 ++ )
F_6 ( & V_7 , & V_1 ) ;
F_7 ( & V_7 ) ;
F_2 ( V_6 L_5 , F_8 ( & V_7 ) ) ;
F_9 ( V_5 , F_10 ( V_5 ) ) ;
V_3 = F_11 ( & V_7 , V_5 , F_10 ( V_5 ) , V_8 ) ;
F_2 ( V_6 L_6 , V_3 ) ;
if ( ! V_3 ) {
F_2 ( V_10 L_7 ) ;
return - V_12 ;
}
F_2 ( V_6 L_8 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
F_2 ( V_6
L_9
L_10 ,
V_1 , V_5 [ V_1 ] . V_13 , V_5 [ V_1 ] . V_14 , V_5 [ V_1 ] . V_15 ) ;
if ( F_12 ( & V_5 [ V_1 ] ) )
break;
}
V_2 = 0 ;
F_13 ( & V_7 , V_2 ) ;
V_3 = F_14 ( & V_7 , V_5 , F_10 ( V_5 ) , 8 ) ;
F_2 ( V_6 L_6 , V_3 ) ;
if ( ! V_3 ) {
F_2 ( V_10 L_11 ) ;
return - V_12 ;
}
F_2 ( V_6 L_12 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
F_2 ( V_6
L_9
L_10 ,
V_1 , V_5 [ V_1 ] . V_13 , V_5 [ V_1 ] . V_14 , V_5 [ V_1 ] . V_15 ) ;
if ( F_12 ( & V_5 [ V_1 ] ) )
break;
}
V_2 = 5 ;
F_15 ( & V_7 , V_2 ) ;
V_2 = F_8 ( & V_7 ) ;
F_2 ( V_6 L_5 , F_8 ( & V_7 ) ) ;
if ( V_2 != 7 ) {
F_2 ( V_10 L_13 ) ;
return - V_12 ;
}
F_2 ( V_6 L_14 ) ;
return 0 ;
}
static void T_2 F_16 ( void )
{
F_17 ( & V_7 ) ;
}
