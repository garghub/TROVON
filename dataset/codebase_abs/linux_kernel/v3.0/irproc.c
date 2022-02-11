void T_1 F_1 ( void )
{
int V_1 ;
V_2 = F_2 ( L_1 , V_3 . V_4 ) ;
if ( V_2 == NULL )
return;
for ( V_1 = 0 ; V_1 < F_3 ( V_5 ) ; V_1 ++ )
( void ) F_4 ( V_5 [ V_1 ] . V_6 , 0 , V_2 ,
V_5 [ V_1 ] . V_7 ) ;
}
void F_5 ( void )
{
int V_1 ;
if ( V_2 ) {
for ( V_1 = 0 ; V_1 < F_3 ( V_5 ) ; V_1 ++ )
F_6 ( V_5 [ V_1 ] . V_6 , V_2 ) ;
F_6 ( L_1 , V_3 . V_4 ) ;
V_2 = NULL ;
}
}
