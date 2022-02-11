void F_1 ( unsigned long V_1 )
{
int V_2 ;
char * V_3 ;
unsigned long V_4 ;
unsigned long V_5 , V_6 ;
V_2 = * ( int * ) V_1 ;
V_1 += sizeof( int ) + ( V_2 + 1 ) * sizeof( char * ) ;
do {
V_3 = * ( char * * ) V_1 ;
V_1 += sizeof( char * ) ;
} while ( V_3 != NULL );
V_5 = V_1 ;
do {
V_4 = * ( unsigned long * ) V_1 ;
V_1 += 2 * sizeof( unsigned long ) ;
} while ( V_4 != V_7 );
V_6 = ( ( V_5 + 15 ) & ~ 15 ) - V_5 ;
if ( V_6 != 0 ) {
do {
V_1 -= sizeof( unsigned long ) ;
V_4 = * ( unsigned long * ) V_1 ;
* ( unsigned long * ) ( V_1 + V_6 ) = V_4 ;
} while ( V_1 > V_5 );
}
}
