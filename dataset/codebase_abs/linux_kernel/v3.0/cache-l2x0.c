static int F_1 ( void )
{
void T_1 * V_1 ;
void T_1 * V_2 ;
if ( ! F_2 () && ! F_3 () )
return 0 ;
#define F_4 0x10
V_2 = F_5 ( V_3 , 4096 ) ;
if ( V_2 != NULL ) {
F_6 ( 0x00000515 , V_2 + F_4 ) ;
F_7 ( V_2 ) ;
} else {
F_8 ( L_1 ) ;
}
V_1 = F_5 ( V_4 , 4096 ) ;
if ( F_9 ( V_1 ) ) {
F_10 ( V_5 L_2 ,
F_11 ( V_1 ) ) ;
return 0 ;
}
F_12 ( V_1 , 0x00030024 , 0x00000000 ) ;
return 0 ;
}
