int main ( void )
{
int V_1 ;
unsigned long V_2 ;
char * V_3 ;
if ( ( V_1 = F_1 ( 2 , V_4 ,
V_5 | V_6 | V_7 | V_8 ) ) < 0 ) {
perror ( L_1 ) ;
exit ( 1 ) ;
}
printf ( L_2 , V_1 ) ;
V_3 = F_2 ( V_1 , V_9 , V_10 ) ;
if ( V_3 == ( char * ) - 1 ) {
perror ( L_3 ) ;
F_3 ( V_1 , V_11 , NULL ) ;
exit ( 2 ) ;
}
printf ( L_4 , V_3 ) ;
F_4 ( L_5 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
V_3 [ V_2 ] = ( char ) ( V_2 ) ;
if ( ! ( V_2 % ( 1024 * 1024 ) ) )
F_4 ( L_6 ) ;
}
F_4 ( L_7 ) ;
F_4 ( L_8 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ )
if ( V_3 [ V_2 ] != ( char ) V_2 )
printf ( L_9 , V_2 ) ;
F_4 ( L_10 ) ;
if ( F_5 ( ( const void * ) V_3 ) != 0 ) {
perror ( L_11 ) ;
F_3 ( V_1 , V_11 , NULL ) ;
exit ( 3 ) ;
}
F_3 ( V_1 , V_11 , NULL ) ;
return 0 ;
}
