unsigned int F_1 ( unsigned int V_1 )
{
return ( ( ( V_1 ) & 0xff000000 ) >> 24 ) |
( ( ( V_1 ) & 0x00ff0000 ) >> 8 ) |
( ( ( V_1 ) & 0x0000ff00 ) << 8 ) |
( ( ( V_1 ) & 0x000000ff ) << 24 ) ;
}
