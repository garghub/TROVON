int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 0 ;
char V_5 [ 256 ] ;
unsigned long V_6 ;
F_1 () ;
if ( V_7 == NULL )
if ( ( V_7 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_7 , V_8 , V_9 | V_10 ) ;
F_5 () ;
if ( ( V_1 > 1 ) && ( strcmp ( V_2 [ 1 ] , L_1 ) == 0 ) ) {
T_1 * V_11 = NULL ;
V_11 = F_2 ( F_3 () ) ;
if ( ( V_11 != NULL ) && F_4 ( V_11 , stdout , V_9 ) ) {
#ifdef F_6
{
T_1 * V_12 = F_2 ( F_7 () ) ;
V_11 = F_8 ( V_12 , V_11 ) ;
}
#endif
F_9 ( F_10 () , V_11 ) ;
F_11 ( F_10 () , V_11 ) ;
F_12 ( F_10 () ,
V_11 ) ;
}
if ( V_11 != NULL )
F_13 ( V_11 ) ;
V_1 -- ;
V_2 ++ ;
}
for ( V_3 = 1 ; V_3 < V_1 ; V_3 ++ ) {
if ( sscanf ( V_2 [ V_3 ] , L_2 , & V_6 ) ) {
F_14 ( V_6 , V_5 , sizeof V_5 ) ;
printf ( L_3 , V_5 ) ;
} else {
printf ( L_4 , V_2 [ V_3 ] ) ;
printf ( L_5 ) ;
V_4 ++ ;
}
}
F_15 () ;
F_16 ( V_4 ) ;
}
