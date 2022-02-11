static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
if ( V_2 -> V_5 & V_6 )
return F_2 ( V_3 , V_4 ) ;
return V_3 / V_4 ;
}
static unsigned long F_3 ( struct V_7 * V_8 ,
unsigned long V_4 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned long V_9 ;
V_9 = F_5 ( V_2 -> V_10 ) >> V_2 -> V_11 ;
V_9 &= F_6 ( V_2 -> V_12 - 1 , 0 ) ;
if ( ! V_9 && V_2 -> V_5 & V_13 )
V_9 = 1 ;
return V_4 * V_9 ;
}
static bool F_7 ( unsigned long V_3 , unsigned long V_14 ,
unsigned long V_15 , unsigned long V_5 )
{
if ( V_5 & V_6 )
return abs ( V_3 - V_14 ) < abs ( V_3 - V_15 ) ;
return V_14 >= V_3 && V_14 < V_15 ;
}
static unsigned long F_8 ( struct V_7 * V_8 , unsigned long V_3 ,
unsigned long * V_16 ,
T_1 V_12 , unsigned long V_5 )
{
unsigned long V_17 = * V_16 ;
unsigned long V_4 , V_18 , V_19 = ~ 0 ;
unsigned int V_20 , V_21 = 0 ;
if ( ! ( F_9 ( V_8 ) & V_22 ) )
return V_3 / * V_16 ;
for ( V_20 = 1 ; V_20 < ( ( 1 << V_12 ) - 1 ) ; V_20 ++ ) {
if ( V_3 == V_17 * V_20 ) {
* V_16 = V_17 ;
return V_20 ;
}
V_4 = F_10 ( F_11 ( V_8 ) ,
V_3 / V_20 ) ;
V_18 = V_4 * V_20 ;
if ( F_7 ( V_3 , V_18 , V_19 , V_5 ) ) {
V_21 = V_20 ;
V_19 = V_18 ;
* V_16 = V_4 ;
}
}
return V_21 ;
}
static long F_12 ( struct V_7 * V_8 , unsigned long V_3 ,
unsigned long * V_4 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned long V_23 = F_8 ( V_8 , V_3 , V_4 ,
V_2 -> V_12 , V_2 -> V_5 ) ;
return * V_4 * V_23 ;
}
static int F_13 ( struct V_7 * V_8 , unsigned long V_3 ,
unsigned long V_4 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned long V_23 = F_1 ( V_2 , V_3 , V_4 ) ;
unsigned long V_5 = 0 ;
unsigned long V_9 ;
if ( V_2 -> V_24 )
F_14 ( V_2 -> V_24 , V_5 ) ;
else
F_15 ( V_2 -> V_24 ) ;
V_9 = F_5 ( V_2 -> V_10 ) ;
V_9 &= ~ F_6 ( V_2 -> V_12 + V_2 -> V_11 - 1 , V_2 -> V_11 ) ;
V_9 |= V_23 << V_2 -> V_11 ;
F_16 ( V_9 , V_2 -> V_10 ) ;
if ( V_2 -> V_24 )
F_17 ( V_2 -> V_24 , V_5 ) ;
else
F_18 ( V_2 -> V_24 ) ;
return 0 ;
}
