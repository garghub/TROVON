static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , T_1 * V_4 )
{
int V_5 = - V_6 ;
* V_4 = 0xe6060380 ;
if ( V_3 >= F_2 ( 3 , 0 ) && V_3 <= F_2 ( 3 , 11 ) )
V_5 = V_3 & 0x1f ;
if ( V_3 >= F_2 ( 4 , 0 ) && V_3 <= F_2 ( 4 , 17 ) )
V_5 = ( V_3 & 0x1f ) + 12 ;
return V_5 ;
}
static unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 V_7 ;
T_1 V_5 ;
if ( F_4 ( ! V_8 [ V_3 ] . V_7 ) )
return V_9 ;
V_7 = V_8 [ V_3 ] . V_7 ;
V_5 = F_5 ( V_8 [ V_3 ] . V_5 ) ;
if ( F_6 ( V_2 , V_10 + V_7 , 32 ) & V_5 ) {
if ( F_6 ( V_2 , V_11 + V_7 , 32 ) & V_5 )
return V_12 ;
else
return V_13 ;
} else
return V_9 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 )
{
T_1 V_15 , V_16 ;
T_1 V_7 ;
T_1 V_5 ;
if ( F_4 ( ! V_8 [ V_3 ] . V_7 ) )
return;
V_7 = V_8 [ V_3 ] . V_7 ;
V_5 = F_5 ( V_8 [ V_3 ] . V_5 ) ;
V_15 = F_6 ( V_2 , V_10 + V_7 , 32 ) & ~ V_5 ;
if ( V_14 != V_9 )
V_15 |= V_5 ;
V_16 = F_6 ( V_2 , V_11 + V_7 , 32 ) & ~ V_5 ;
if ( V_14 == V_12 )
V_16 |= V_5 ;
F_8 ( V_2 , V_11 + V_7 , 32 , V_16 ) ;
F_8 ( V_2 , V_10 + V_7 , 32 , V_15 ) ;
}
