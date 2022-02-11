char *
F_1 ( T_1 V_1 )
{
T_2 V_2 ;
char * string ;
V_2 = F_2 ( F_3 ( V_1 ) ,
V_3 ) ;
string = ( char * ) F_4 ( V_2 + 1 ) ;
if ( ! F_5 ( V_1 , string , V_2 + 1 ,
V_3 ) ) {
F_6 ( string ) ;
return NULL ;
}
return string ;
}
