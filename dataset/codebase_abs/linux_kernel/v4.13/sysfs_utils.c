int F_1 ( const char * V_1 , const char * V_2 ,
T_1 V_3 )
{
int V_4 ;
int V_5 ;
V_4 = F_2 ( V_1 , V_6 ) ;
if ( V_4 < 0 ) {
F_3 ( L_1 , V_1 ) ;
return - 1 ;
}
V_5 = F_4 ( V_4 , V_2 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( L_2 , V_1 ) ;
F_5 ( V_4 ) ;
return - 1 ;
}
F_5 ( V_4 ) ;
return 0 ;
}
