static void F_1 ( void )
{
V_1 = V_2 ;
V_3 = V_4 ;
V_5 = 0 ;
V_6 = 0 ;
}
static void F_2 ( T_1 V_7 , T_1 V_8 )
{
V_2 = V_7 ;
V_4 = V_8 ;
F_1 () ;
}
static void F_3 ( T_2 V_9 )
{
V_6 |= V_9 << ( 8 * V_5 ) ;
V_5 ++ ;
if ( V_5 >= 4 ) {
V_1 ^= V_6 ;
V_3 ^= F_4 ( V_1 , 17 ) ;
V_1 += V_3 ;
V_3 ^= ( ( V_1 & 0xff00ff00 ) >> 8 ) | ( ( V_1 & 0x00ff00ff ) << 8 ) ;
V_1 += V_3 ;
V_3 ^= F_4 ( V_1 , 3 ) ;
V_1 += V_3 ;
V_3 ^= F_5 ( V_1 , 2 ) ;
V_1 += V_3 ;
V_6 = 0 ;
V_5 = 0 ;
}
}
void F_6 ( T_1 V_7 , T_1 V_8 )
{
F_2 ( V_7 , V_8 ) ;
}
void F_7 ( void )
{
V_2 = 0 ;
V_4 = 0 ;
F_1 () ;
}
void F_8 ( T_3 V_10 , unsigned int V_11 )
{
while ( V_11 > 0 ) {
F_3 ( * V_10 ++ ) ;
V_11 -- ;
}
}
void F_9 ( T_4 V_12 , T_4 V_13 )
{
F_3 ( 0x5a ) ;
F_3 ( 0 ) ;
F_3 ( 0 ) ;
F_3 ( 0 ) ;
F_3 ( 0 ) ;
while ( V_5 != 0 )
F_3 ( 0 ) ;
* V_12 = V_1 ;
* V_13 = V_3 ;
F_1 () ;
}
