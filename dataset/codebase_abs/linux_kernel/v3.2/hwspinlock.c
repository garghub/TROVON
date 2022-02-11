int T_1 F_1 ( void )
{
int V_1 = 0 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
const char * V_6 = L_1 ;
const char * V_7 = L_2 ;
V_3 = F_2 ( V_6 ) ;
if ( V_3 == NULL )
return - V_8 ;
V_5 = F_3 ( V_7 , 0 , V_3 , & V_9 ,
sizeof( struct V_10 ) ,
NULL , 0 , false ) ;
if ( F_4 ( V_5 ) ) {
F_5 ( L_3 , V_7 ,
V_6 ) ;
V_1 = F_6 ( V_5 ) ;
}
return V_1 ;
}
