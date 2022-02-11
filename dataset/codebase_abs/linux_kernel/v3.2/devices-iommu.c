static int T_1 F_1 ( void )
{
int V_1 , V_2 ;
V_1 = F_2 ( & V_3 ) ;
if ( V_1 != 0 ) {
F_3 ( L_1 ) ;
goto V_4;
}
for ( V_2 = 0 ; V_2 < F_4 ( V_5 ) ; V_2 ++ ) {
V_1 = F_5 ( V_5 [ V_2 ] ,
V_6 [ V_2 ] ,
sizeof( struct V_7 ) ) ;
if ( V_1 != 0 ) {
F_3 ( L_2
L_3 , V_2 ) ;
goto V_8;
}
V_1 = F_2 ( V_5 [ V_2 ] ) ;
if ( V_1 != 0 ) {
F_3 ( L_4
L_3 , V_2 ) ;
goto V_8;
}
}
for ( V_2 = 0 ; V_2 < F_4 ( V_9 ) ; V_2 ++ ) {
V_1 = F_5 ( V_9 [ V_2 ] ,
V_10 [ V_2 ] ,
sizeof( * V_9 [ V_2 ] ) ) ;
if ( V_1 != 0 ) {
F_3 ( L_5
L_3 , V_2 ) ;
goto V_11;
}
V_1 = F_2 ( V_9 [ V_2 ] ) ;
if ( V_1 != 0 ) {
F_3 ( L_6
L_3 , V_2 ) ;
goto V_11;
}
}
return 0 ;
V_11:
while ( -- V_2 >= 0 )
F_6 ( V_9 [ V_2 ] ) ;
V_8:
while ( -- V_2 >= 0 )
F_6 ( V_5 [ V_2 ] ) ;
F_6 ( & V_3 ) ;
V_4:
return V_1 ;
}
static void T_2 F_7 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_4 ( V_9 ) ; V_2 ++ )
F_6 ( V_9 [ V_2 ] ) ;
for ( V_2 = 0 ; V_2 < F_4 ( V_5 ) ; ++ V_2 )
F_6 ( V_5 [ V_2 ] ) ;
F_6 ( & V_3 ) ;
}
