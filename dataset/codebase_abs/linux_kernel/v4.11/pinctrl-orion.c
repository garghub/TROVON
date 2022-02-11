static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned long * V_4 )
{
unsigned V_5 = ( V_3 % V_6 ) * V_7 ;
if ( V_3 < 16 ) {
unsigned V_8 = ( V_3 / V_6 ) * V_7 ;
* V_4 = ( F_2 ( V_9 + V_8 ) >> V_5 ) & V_10 ;
}
else {
* V_4 = ( F_2 ( V_11 ) >> V_5 ) & V_10 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned long V_4 )
{
unsigned V_5 = ( V_3 % V_6 ) * V_7 ;
if ( V_3 < 16 ) {
unsigned V_8 = ( V_3 / V_6 ) * V_7 ;
T_1 V_12 = F_2 ( V_9 + V_8 ) & ~ ( V_10 << V_5 ) ;
F_4 ( V_12 | ( V_4 << V_5 ) , V_9 + V_8 ) ;
}
else {
T_1 V_12 = F_2 ( V_11 ) & ~ ( V_10 << V_5 ) ;
F_4 ( V_12 | ( V_4 << V_5 ) , V_11 ) ;
}
return 0 ;
}
static int F_5 ( struct V_13 * V_14 )
{
const struct V_15 * V_16 =
F_6 ( V_17 , & V_14 -> V_18 ) ;
struct V_19 * V_20 ;
V_14 -> V_18 . V_21 = ( void * ) V_16 -> V_2 ;
V_20 = F_7 ( V_14 , V_22 , 0 ) ;
V_9 = F_8 ( & V_14 -> V_18 , V_20 ) ;
if ( F_9 ( V_9 ) )
return F_10 ( V_9 ) ;
V_20 = F_7 ( V_14 , V_22 , 1 ) ;
V_11 = F_8 ( & V_14 -> V_18 , V_20 ) ;
if ( F_9 ( V_11 ) )
return F_10 ( V_11 ) ;
return F_11 ( V_14 ) ;
}
