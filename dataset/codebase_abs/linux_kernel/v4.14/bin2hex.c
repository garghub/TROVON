int main ( int V_1 , const char * V_2 [] )
{
const char * V_3 ;
int V_4 = 0 ;
int V_5 ;
int V_6 = 0 ;
if( V_2 [ 1 ] && strcmp ( V_2 [ 1 ] , L_1 ) == 0 )
{
V_2 ++ ;
V_1 -- ;
V_6 = 1 ;
}
if( V_1 == 1 )
{
fprintf ( V_7 , L_2 ) ;
exit ( 1 ) ;
}
V_3 = V_2 [ 1 ] ;
printf ( L_3 ) ;
printf ( L_4 , V_3 , V_6 ? L_5 : L_6 ) ;
while ( ( V_5 = getchar ( ) ) != V_8 )
{
if ( V_4 != 0 && V_4 % 10 == 0 )
printf ( L_7 ) ;
printf ( L_8 , V_5 & 0xFFl ) ;
V_4 ++ ;
}
printf ( L_9 , V_3 , V_4 ) ;
return 0 ;
}
