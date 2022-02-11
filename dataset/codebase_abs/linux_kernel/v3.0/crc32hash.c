static unsigned int F_1 ( unsigned char const * V_1 , unsigned int V_2 )
{
int V_3 ;
unsigned int V_4 = 0 ;
while ( V_2 -- ) {
V_4 ^= * V_1 ++ ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
V_4 = ( V_4 >> 1 ) ^ ( ( V_4 & 1 ) ? 0xedb88320 : 0 ) ;
}
return V_4 ;
}
int main ( int V_5 , char * * V_6 ) {
unsigned int V_7 ;
if ( V_5 != 2 ) {
printf ( L_1 ) ;
return - 1 ;
}
V_7 = F_1 ( ( unsigned char const * ) V_6 [ 1 ] , strlen ( V_6 [ 1 ] ) ) ;
printf ( L_2 , V_7 ) ;
return 0 ;
}
