static int F_1 ( const unsigned char * V_1 , const unsigned char * V_2 )
{
T_1 V_3 ;
T_2 V_4 , V_5 ;
F_2 ( V_1 , V_4 ) ;
F_2 ( V_2 , V_5 ) ;
V_3 = V_4 - V_5 ;
if ( V_4 > V_5 && V_3 < 0 )
return 128 ;
else if ( V_5 > V_4 && V_3 > 0 )
return - 128 ;
if ( V_3 > 128 )
return 128 ;
else if ( V_3 < - 128 )
return - 128 ;
else
return ( int ) V_3 ;
}
int F_3 ( T_3 * V_6 , T_4 * V_7 )
{
int V_8 ;
unsigned int V_9 ;
const unsigned char * V_10 = V_6 -> V_11 . V_12 ;
V_8 = F_1 ( V_10 , V_7 -> V_13 ) ;
if ( V_8 > 0 ) {
F_4 ( F_5 ( & V_6 -> V_11 ) , V_10 ) ;
return 1 ;
}
V_9 = - V_8 ;
if ( V_9 >= sizeof( V_7 -> V_14 ) * 8 )
return 0 ;
else if ( V_7 -> V_14 & ( 1UL << V_9 ) )
return 0 ;
F_4 ( F_5 ( & V_6 -> V_11 ) , V_10 ) ;
return 1 ;
}
void F_6 ( T_3 * V_6 , T_4 * V_7 )
{
int V_8 ;
unsigned int V_9 ;
const unsigned char * V_10 = F_7 ( & V_6 -> V_11 ) ;
V_8 = F_1 ( V_10 , V_7 -> V_13 ) ;
if ( V_8 > 0 ) {
V_9 = V_8 ;
if ( V_9 < sizeof( V_7 -> V_14 ) * 8 )
V_7 -> V_14 <<= V_9 , V_7 -> V_14 |= 1UL ;
else
V_7 -> V_14 = 1UL ;
memcpy ( V_7 -> V_13 , V_10 , V_15 ) ;
} else {
V_9 = - V_8 ;
if ( V_9 < sizeof( V_7 -> V_14 ) * 8 )
V_7 -> V_14 |= 1UL << V_9 ;
}
}
