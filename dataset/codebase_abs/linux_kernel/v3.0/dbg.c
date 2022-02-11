void __weak putc ( char V_1 )
{
}
void puts ( const char * V_2 )
{
char V_1 ;
while ( ( V_1 = * V_2 ++ ) != '\0' ) {
putc ( V_1 ) ;
if ( V_1 == '\n' )
putc ( '\r' ) ;
}
}
void F_1 ( unsigned long long V_3 )
{
unsigned char V_4 [ 10 ] ;
int V_5 ;
for ( V_5 = 7 ; V_5 >= 0 ; V_5 -- ) {
V_4 [ V_5 ] = L_1 [ V_3 & 0x0F ] ;
V_3 >>= 4 ;
}
V_4 [ 8 ] = '\0' ;
puts ( V_4 ) ;
}
