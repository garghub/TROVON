int
F_1 ( const char * string , const char * V_1 )
{
long V_2 ;
char * V_3 ;
V_2 = strtol ( string , & V_3 , 10 ) ;
if ( V_3 == string || * V_3 != '\0' ) {
F_2 ( L_1 , V_1 , string ) ;
exit ( 1 ) ;
}
if ( V_2 < 0 ) {
F_2 ( L_2 , V_1 , string ) ;
exit ( 1 ) ;
}
if ( V_2 > V_4 ) {
F_2 ( L_3 ,
V_1 , string , V_4 ) ;
exit ( 1 ) ;
}
return ( int ) V_2 ;
}
int
F_3 ( const char * string , const char * V_1 )
{
int V_2 ;
V_2 = F_1 ( string , V_1 ) ;
if ( V_2 == 0 ) {
F_2 ( L_4 , V_1 ) ;
exit ( 1 ) ;
}
return V_2 ;
}
