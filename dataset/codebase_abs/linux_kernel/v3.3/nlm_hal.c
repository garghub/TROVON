void F_1 ( void )
{
V_1 = F_2 ( V_2 ) ;
V_3 = F_3 ( 0 ) ;
V_4 = F_4 ( 0 ) ;
}
int F_5 ( int V_5 )
{
if ( ! F_6 ( V_5 ) )
return - 1 ;
switch ( V_5 ) {
case V_6 :
return V_7 ;
case V_8 :
return V_9 ;
default:
return - 1 ;
}
}
int F_7 ( int V_10 )
{
switch ( V_10 ) {
case V_7 :
return V_6 ;
case V_9 :
return V_8 ;
default:
return - 1 ;
}
}
unsigned int F_8 ( int V_11 )
{
unsigned int V_12 , V_13 , V_14 , V_15 ;
unsigned int V_16 , V_17 , V_18 ;
T_1 V_19 ;
V_16 = F_9 ( V_3 , V_20 ) ;
V_17 = F_9 ( V_3 , V_21 ) ;
V_12 = ( ( V_16 >> 10 ) & 0x7f ) + 1 ;
V_13 = ( ( V_16 >> 8 ) & 0x3 ) + 1 ;
V_15 = ( ( V_16 >> 30 ) & 0x3 ) + 1 ;
V_14 = ( ( V_17 >> ( V_11 * 4 ) ) & 0xf ) + 1 ;
V_19 = 800000000ULL * V_12 ;
V_18 = 3 * V_13 * V_15 * V_14 ;
F_10 ( V_19 , V_18 ) ;
return ( unsigned int ) V_19 ;
}
unsigned int F_11 ( void )
{
return F_8 ( 0 ) ;
}
