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
const struct V_7 * V_8 ;
T_1 V_9 ;
T_1 V_5 ;
V_8 = F_4 ( V_10 , F_5 ( V_10 ) , V_3 ) ;
if ( ! V_8 )
return V_11 ;
V_9 = V_8 -> V_9 ;
V_5 = F_6 ( V_8 -> V_5 ) ;
if ( ! ( F_7 ( V_2 , V_12 + V_9 , 32 ) & V_5 ) )
return V_11 ;
else if ( F_7 ( V_2 , V_13 + V_9 , 32 ) & V_5 )
return V_14 ;
else
return V_15 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_16 )
{
const struct V_7 * V_8 ;
T_1 V_17 , V_18 ;
T_1 V_9 ;
T_1 V_5 ;
V_8 = F_4 ( V_10 , F_5 ( V_10 ) , V_3 ) ;
if ( ! V_8 )
return;
V_9 = V_8 -> V_9 ;
V_5 = F_6 ( V_8 -> V_5 ) ;
V_17 = F_7 ( V_2 , V_12 + V_9 , 32 ) & ~ V_5 ;
if ( V_16 != V_11 )
V_17 |= V_5 ;
V_18 = F_7 ( V_2 , V_13 + V_9 , 32 ) & ~ V_5 ;
if ( V_16 == V_14 )
V_18 |= V_5 ;
F_9 ( V_2 , V_13 + V_9 , 32 , V_18 ) ;
F_9 ( V_2 , V_12 + V_9 , 32 , V_17 ) ;
}
