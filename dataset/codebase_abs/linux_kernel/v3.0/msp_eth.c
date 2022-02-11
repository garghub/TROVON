int T_1 F_1 ( void )
{
int V_1 , V_2 = 0 ;
F_2 ( V_3 , V_4 ) ;
F_3 ( V_4 ) ;
#ifdef F_4
F_2 ( V_3 , V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_3 , V_6 ) ;
F_3 ( V_6 ) ;
#endif
for ( V_1 = 0 ; V_1 < F_5 ( V_7 ) ; V_1 ++ ) {
V_2 = F_6 ( & V_7 [ V_1 ] ) ;
F_7 ( V_8 L_1 , V_1 , V_2 ) ;
if ( V_2 ) {
F_8 ( & V_7 [ V_1 ] ) ;
break;
}
}
if ( V_2 )
F_7 ( V_9 L_2
L_3 ) ;
return V_2 ;
}
