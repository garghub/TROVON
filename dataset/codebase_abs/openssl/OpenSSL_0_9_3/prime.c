void F_1 ( type , T_1 )
int type , T_1 ;
{
if ( type == 0 )
fprintf ( V_1 , L_1 ) ;
else if ( type == 1 )
fprintf ( V_1 , L_2 ) ;
else if ( type == 2 )
fprintf ( V_1 , L_3 ) ;
fflush ( V_1 ) ;
}
int main ( T_2 , T_3 )
int T_2 ;
char * T_3 [] ;
{
T_4 * rand ;
int T_1 = 256 ;
if ( T_2 >= 2 )
{
T_1 = atoi ( T_3 [ 1 ] ) ;
if ( T_1 == 0 ) T_1 = 256 ;
}
fprintf ( V_1 , L_4 ) ;
rand = F_2 ( T_1 , 1 , NULL , NULL , F_1 ) ;
fprintf ( V_1 , L_5 ) ;
F_3 ( stdout , rand ) ;
fprintf ( stdout , L_5 ) ;
F_4 ( rand ) ;
exit ( 0 ) ;
return ( 0 ) ;
}
