unsigned int F_1 ( void )
{
V_1 = V_2 * ( V_1 & 65535 ) + ( V_1 >> 16 ) ;
V_3 = V_4 * ( V_3 & 65535 ) + ( V_3 >> 16 ) ;
return ( ( V_1 << 16 ) + ( V_3 & 65535 ) ) ;
}
void F_2 ( unsigned int V_5 , unsigned int V_6 )
{
if ( V_5 )
V_1 = V_5 ;
if ( V_6 )
V_3 = V_6 ;
}
void F_3 ( void * V_7 , int V_8 )
{
int * V_9 = V_7 ;
int V_10 , V_11 ;
F_4 ( V_8 >= 0 ) ;
V_10 = F_5 ( ( int ) ( ( unsigned long ) V_7 & ( sizeof( int ) - 1 ) ) , V_8 ) ;
if ( V_10 ) {
F_6 ( & V_11 , sizeof( V_11 ) ) ;
V_11 ^= F_1 () ;
memcpy ( V_7 , & V_11 , V_10 ) ;
V_9 = V_7 + V_10 ;
V_8 -= V_10 ;
}
while ( V_8 >= sizeof( int ) ) {
F_6 ( & V_11 , sizeof( V_11 ) ) ;
* V_9 = F_1 () ^ V_11 ;
V_8 -= sizeof( int ) ;
V_9 ++ ;
}
V_7 = V_9 ;
if ( V_8 ) {
F_6 ( & V_11 , sizeof( V_11 ) ) ;
V_11 ^= F_1 () ;
memcpy ( V_7 , & V_11 , V_8 ) ;
}
}
