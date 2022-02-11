int F_1 ( int * V_1 , char * * * V_2 )
{
if ( V_3 )
return V_3 ( V_1 , V_2 ) ;
return 0 ;
}
int F_2 ( const T_1 * V_4 , T_2 V_5 ) {
return F_3 ( V_4 , V_5 ) ;
}
int main ( int V_1 , char * * V_2 )
{
if ( V_3 )
V_3 ( & V_1 , & V_2 ) ;
while ( F_4 ( 10000 ) ) {
T_1 * V_4 = malloc ( V_6 ) ;
T_2 V_7 = F_5 ( 0 , V_4 , V_6 ) ;
F_3 ( V_4 , V_7 ) ;
free ( V_4 ) ;
}
return 0 ;
}
