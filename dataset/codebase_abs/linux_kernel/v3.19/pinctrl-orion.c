static int F_1 ( unsigned V_1 , unsigned long * V_2 )
{
unsigned V_3 = ( V_1 % V_4 ) * V_5 ;
if ( V_1 < 16 ) {
unsigned V_6 = ( V_1 / V_4 ) * V_5 ;
* V_2 = ( F_2 ( V_7 + V_6 ) >> V_3 ) & V_8 ;
}
else {
* V_2 = ( F_2 ( V_9 ) >> V_3 ) & V_8 ;
}
return 0 ;
}
static int F_3 ( unsigned V_1 , unsigned long V_2 )
{
unsigned V_3 = ( V_1 % V_4 ) * V_5 ;
if ( V_1 < 16 ) {
unsigned V_6 = ( V_1 / V_4 ) * V_5 ;
T_1 V_10 = F_2 ( V_7 + V_6 ) & ~ ( V_8 << V_3 ) ;
F_4 ( V_10 | ( V_2 << V_3 ) , V_7 + V_6 ) ;
}
else {
T_1 V_10 = F_2 ( V_9 ) & ~ ( V_8 << V_3 ) ;
F_4 ( V_10 | ( V_2 << V_3 ) , V_9 ) ;
}
return 0 ;
}
static int F_5 ( struct V_11 * V_12 )
{
const struct V_13 * V_14 =
F_6 ( V_15 , & V_12 -> V_16 ) ;
struct V_17 * V_18 ;
V_12 -> V_16 . V_19 = ( void * ) V_14 -> V_20 ;
V_18 = F_7 ( V_12 , V_21 , 0 ) ;
V_7 = F_8 ( & V_12 -> V_16 , V_18 ) ;
if ( F_9 ( V_7 ) )
return F_10 ( V_7 ) ;
V_18 = F_7 ( V_12 , V_21 , 1 ) ;
V_9 = F_8 ( & V_12 -> V_16 , V_18 ) ;
if ( F_9 ( V_9 ) )
return F_10 ( V_9 ) ;
return F_11 ( V_12 ) ;
}
static int F_12 ( struct V_11 * V_12 )
{
return F_13 ( V_12 ) ;
}
