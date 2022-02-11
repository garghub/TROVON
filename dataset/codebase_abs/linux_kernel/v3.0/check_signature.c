int F_1 ( const volatile void T_1 * V_1 ,
const unsigned char * V_2 , int V_3 )
{
while ( V_3 -- ) {
if ( F_2 ( V_1 ) != * V_2 )
return 0 ;
V_1 ++ ;
V_2 ++ ;
}
return 1 ;
}
