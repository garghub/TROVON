int main ( int V_1 , char * V_2 [] )
{
int V_3 , V_4 = 0 ;
if ( V_1 > 1 )
printf ( L_1 ,
V_2 [ 1 ] , V_1 > 2 ? V_2 [ 2 ] : L_2 ) ;
do {
printf ( L_3 ) ;
while ( ( V_3 = getchar () ) != V_5 ) {
V_4 ++ ;
printf ( L_4 , V_3 ) ;
if ( V_4 % 16 == 0 )
break;
}
printf ( L_5 ) ;
} while ( V_3 != V_5 );
if ( V_1 > 1 )
printf ( L_6 ,
V_2 [ 1 ] , V_4 ) ;
return 0 ;
}
