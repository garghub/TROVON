int
F_1 ( const char * string , const char * V_1 )
{
T_1 V_2 ;
if ( ! F_2 ( string , NULL , & V_2 ) ) {
if ( V_3 == V_4 ) {
F_3 ( L_1 , V_1 , string ) ;
exit ( 1 ) ;
}
if ( V_2 < 0 ) {
F_3 ( L_2 , V_1 , string ) ;
exit ( 1 ) ;
}
F_3 ( L_3 ,
V_1 , string , V_2 ) ;
exit ( 1 ) ;
}
if ( V_2 < 0 ) {
F_3 ( L_2 , V_1 , string ) ;
exit ( 1 ) ;
}
return ( int ) V_2 ;
}
int
F_4 ( const char * string , const char * V_1 )
{
int V_2 ;
V_2 = F_1 ( string , V_1 ) ;
if ( V_2 == 0 ) {
F_3 ( L_4 , V_1 ) ;
exit ( 1 ) ;
}
return V_2 ;
}
T_2
F_5 ( const char * string , const char * V_1 )
{
T_2 V_2 ;
if ( ! F_6 ( string , NULL , & V_2 ) ) {
if ( V_3 == V_4 ) {
F_3 ( L_1 , V_1 , string ) ;
exit ( 1 ) ;
}
F_3 ( L_3 ,
V_1 , string , V_2 ) ;
exit ( 1 ) ;
}
return V_2 ;
}
T_2
F_7 ( const char * string , const char * V_1 )
{
T_2 V_2 ;
V_2 = F_5 ( string , V_1 ) ;
if ( V_2 == 0 ) {
F_3 ( L_4 , V_1 ) ;
exit ( 1 ) ;
}
return V_2 ;
}
