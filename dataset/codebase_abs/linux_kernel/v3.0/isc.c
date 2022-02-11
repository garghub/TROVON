void F_1 ( unsigned int V_1 )
{
if ( V_1 > V_2 ) {
F_2 ( 1 ) ;
return;
}
F_3 ( & V_3 ) ;
if ( V_4 [ V_1 ] == 0 )
F_4 ( 6 , 31 - V_1 ) ;
V_4 [ V_1 ] ++ ;
F_5 ( & V_3 ) ;
}
void F_6 ( unsigned int V_1 )
{
F_3 ( & V_3 ) ;
if ( V_1 > V_2 || V_4 [ V_1 ] == 0 ) {
F_2 ( 1 ) ;
goto V_5;
}
if ( V_4 [ V_1 ] == 1 )
F_7 ( 6 , 31 - V_1 ) ;
V_4 [ V_1 ] -- ;
V_5:
F_5 ( & V_3 ) ;
}
