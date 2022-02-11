int F_1 ( int * V_1 , char * * * V_2 ) {
return 1 ;
}
int F_2 ( const T_1 * V_3 , T_2 V_4 ) {
static T_3 * V_5 ;
if ( V_5 == NULL )
V_5 = F_3 ( L_1 , L_2 ) ;
( void ) F_4 ( V_5 , V_3 , V_4 , 0 , 0 ) ;
return 0 ;
}
