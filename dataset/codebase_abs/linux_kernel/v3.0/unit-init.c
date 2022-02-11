T_1 void T_2 F_1 ( void )
{
F_2 ( 0 , V_1 ) ;
F_2 ( 2 , V_2 ) ;
F_2 ( 3 , V_1 ) ;
F_2 ( 4 , V_2 ) ;
F_2 ( 5 , V_2 ) ;
#ifdef F_3
F_4 ( V_3 , F_5 ( F_3 ) ) ;
#endif
#ifdef F_6
F_4 ( V_4 , F_5 ( F_6 ) ) ;
#endif
}
void T_2 F_7 ( void )
{
}
void T_2 F_8 ( void )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
switch ( F_9 ( V_5 ) ) {
case V_1 :
case V_2 :
F_10 ( F_11 ( V_5 ) ) ;
break;
default:
break;
}
}
}
