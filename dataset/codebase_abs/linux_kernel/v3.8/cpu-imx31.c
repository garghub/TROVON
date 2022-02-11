static int F_1 ( void )
{
T_1 V_1 , V_2 ;
V_2 = F_2 ( F_3 ( V_3 + V_4 ) ) ;
V_2 &= 0xff ;
for ( V_1 = 0 ; V_1 < F_4 ( V_5 ) ; V_1 ++ )
if ( V_2 == V_5 [ V_1 ] . V_2 ) {
F_5 ( V_5 [ V_1 ] . V_6 ,
V_5 [ V_1 ] . V_7 ) ;
return V_5 [ V_1 ] . V_7 ;
}
F_5 ( L_1 , V_8 ) ;
return V_8 ;
}
int F_6 ( void )
{
if ( V_9 == - 1 )
V_9 = F_1 () ;
return V_9 ;
}
