unsigned F_1 ( unsigned char V_1 )
{
return ( V_1 & 0x0f ) + ( V_1 >> 4 ) * 10 ;
}
unsigned char F_2 ( unsigned V_1 )
{
return ( ( V_1 / 10 ) << 4 ) + V_1 % 10 ;
}
