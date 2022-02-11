static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 , V_5 , V_6 ;
unsigned long long * V_7 ;
V_7 = calloc ( 1 , 8 ) ;
if ( ! V_7 )
exit ( V_8 ) ;
V_3 = 0 ;
for ( V_6 = 0 ; V_2 -> V_9 [ V_6 ] != - 1 ; V_6 ++ ) {
V_4 = 63 - ( V_2 -> V_9 [ V_6 ] & 63 ) ;
V_5 = V_2 -> V_9 [ V_6 ] / 64 ;
if ( V_5 > V_3 ) {
V_7 = realloc ( V_7 , ( V_5 + 1 ) * 8 ) ;
if ( ! V_7 )
exit ( V_8 ) ;
memset ( V_7 + V_3 + 1 , 0 , ( V_5 - V_3 ) * 8 ) ;
V_3 = V_5 ;
}
V_7 [ V_5 ] |= 1ULL << V_4 ;
}
printf ( L_1 , V_2 -> V_10 ) ;
for ( V_6 = 0 ; V_6 <= V_3 ; V_6 ++ )
printf ( L_2 , V_7 [ V_6 ] , V_6 < V_3 ? ',' : '\n' ) ;
printf ( L_3 , V_2 -> V_10 , V_3 + 1 ) ;
free ( V_7 ) ;
}
static void F_2 ( void )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < sizeof( V_11 ) / sizeof( V_11 [ 0 ] ) ; V_6 ++ )
F_1 ( & V_11 [ V_6 ] ) ;
}
int main ( int V_12 , char * * V_13 )
{
printf ( L_4 ) ;
printf ( L_5 ) ;
printf ( L_6 ) ;
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 , __FILE__ ) ;
printf ( L_10 ) ;
printf ( L_11 ) ;
F_2 () ;
printf ( L_12 ) ;
return 0 ;
}
