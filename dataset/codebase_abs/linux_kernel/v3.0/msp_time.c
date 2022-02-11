void T_1 F_1 ( void )
{
char * V_1 , * V_2 ;
unsigned long V_3 = 0 ;
if ( V_3 == 0 ) {
V_2 = F_2 ( L_1 ) ;
V_3 = F_3 ( V_2 , & V_1 , 10 ) ;
if ( V_1 != NULL && * V_1 != 0 ) {
F_4 ( V_4
L_2 , V_2 ) ;
V_3 = 0 ;
}
}
if ( V_3 == 0 ) {
V_2 = F_2 ( L_3 ) ;
V_3 = 1000 * F_3 ( V_2 , & V_1 , 10 ) ;
if ( V_1 != NULL && * V_1 != 0 ) {
F_4 ( V_4
L_4 , V_2 ) ;
V_3 = 0 ;
}
}
if ( V_3 == 0 ) {
#if F_5 ( V_5 ) \
|| F_5 ( V_6 )
V_3 = 400000000 ;
#elif F_5 ( V_7 )
V_3 = 25000000 ;
#else
V_3 = 150000000 ;
#endif
F_4 ( V_4
L_5
L_6 , V_3 ) ;
}
F_4 ( V_8 L_7 , V_3 ) ;
V_9 = V_3 / 2 ;
}
unsigned int T_2 F_6 ( void )
{
if ( ( F_7 () ) && ! V_10 ) {
memcpy ( & V_11 , & V_12 , sizeof( V_11 ) ) ;
F_8 ( V_13 , & V_11 ) ;
V_10 ++ ;
}
return F_7 () ? V_13 : V_14 ;
}
