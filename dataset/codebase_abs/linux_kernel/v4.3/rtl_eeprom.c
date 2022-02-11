static void F_1 ( struct V_1 * V_2 , int V_3 , bool V_4 )
{
T_1 V_5 = F_2 ( V_2 , V_6 ) ;
if ( V_4 )
V_5 |= 1 << V_3 ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_3 ( V_2 , V_6 , V_5 ) ;
F_4 ( V_7 ) ;
}
static bool F_5 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_5 = F_2 ( V_2 , V_6 ) ;
return ( V_5 >> V_3 ) & 0x1 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_8 , 1 ) ;
F_1 ( V_2 , V_8 , 0 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 , T_2 V_9 , int V_10 )
{
T_2 V_11 = 0 ;
int V_12 = 16 ;
F_1 ( V_2 , V_13 , 1 ) ;
F_6 ( V_2 ) ;
while ( V_10 -- ) {
F_1 ( V_2 , V_14 ,
( V_9 >> V_10 ) & 0x1 ) ;
F_6 ( V_2 ) ;
}
F_1 ( V_2 , V_14 , 0 ) ;
while ( V_12 -- ) {
F_6 ( V_2 ) ;
V_11 |= F_5 ( V_2 , V_15 ) << V_12 ;
}
F_1 ( V_2 , V_13 , 0 ) ;
F_6 ( V_2 ) ;
return V_11 ;
}
T_3 F_8 ( struct V_1 * V_2 , T_3 V_16 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
T_3 V_11 = 0 ;
F_3 ( V_2 , V_6 ,
( V_19 << V_20 ) ) ;
F_4 ( V_7 ) ;
if ( V_18 -> V_21 == V_22 )
V_11 = F_7 ( V_2 , ( V_16 & 0xFF ) | ( 0x6 << 8 ) , 11 ) ;
else
V_11 = F_7 ( V_2 , ( V_16 & 0x3F ) | ( 0x6 << 6 ) , 9 ) ;
F_3 ( V_2 , V_6 ,
( V_23 << V_20 ) ) ;
return V_11 ;
}
