void F_1 ( void )
{
T_1 V_1 , V_2 ;
F_2 ( & V_2 ) ;
if ( ! F_3 ( V_3 , & V_2 , & V_1 ) ) {
if ( V_4 )
F_4 ( V_4 ) ;
else
F_5 ( L_1 ) ;
( void ) F_3 ( V_5 , & V_1 , NULL ) ;
}
return;
}
static int T_2 F_6 ( void )
{
int V_6 ;
T_3 V_7 ;
F_7 ( L_2 ) ;
V_4 = F_8 ( NULL , L_3 ) ;
if ( F_9 ( V_4 ) ) {
F_5 ( L_4 ) ;
return F_10 ( V_4 ) ;
}
V_6 = F_11 ( V_4 ) ;
if ( V_6 ) {
F_5 ( L_5 ) ;
return V_6 ;
}
F_7 ( L_6 ) ;
V_7 = F_12 ( V_8 + V_9 ) ;
V_7 &= ~ V_10 ;
F_13 ( V_7 , V_8 + V_9 ) ;
V_11 = F_1 ;
return 0 ;
}
