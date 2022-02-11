static int F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
if ( V_3 & V_4 )
return F_2 ( ( V_5 ) V_1 , V_2 ) ;
return F_3 ( ( V_5 ) V_1 , V_2 ) ;
}
static int F_4 ( unsigned long V_1 , unsigned long V_2 )
{
return F_3 ( ( V_5 ) V_1 , V_2 ) - 1 ;
}
static int F_5 ( struct V_6 * V_7 , int V_8 )
{
struct V_9 * V_10 =
F_6 ( V_7 ) ;
int V_11 ;
T_1 V_12 ;
V_12 = V_10 -> div . V_12 ;
V_11 = 1 << V_12 ;
return F_7 ( V_8 , 1 , V_11 ) ;
}
static unsigned long F_8 ( struct V_6 * V_7 ,
unsigned long V_1 )
{
struct V_9 * V_10 =
F_6 ( V_7 ) ;
struct V_13 * V_14 ;
unsigned long V_15 , V_8 ;
V_14 = & V_10 -> div ;
V_15 = F_9 ( V_10 -> V_16 + V_14 -> V_17 ) ;
V_8 = F_10 ( V_14 -> V_12 , V_14 -> V_18 , V_15 ) + 1 ;
return F_3 ( ( V_5 ) V_1 , V_8 ) ;
}
static long F_11 ( struct V_6 * V_7 ,
unsigned long V_2 ,
unsigned long * V_1 )
{
struct V_9 * V_10 =
F_6 ( V_7 ) ;
unsigned long V_19 ;
int V_8 ;
if ( ! ( F_12 ( V_7 ) & V_20 ) ) {
V_8 = F_1 ( * V_1 , V_2 , V_10 -> V_3 ) ;
V_8 = F_5 ( V_7 , V_8 ) ;
return F_3 ( ( V_5 ) * V_1 , V_8 ) ;
}
V_19 = F_13 ( F_14 ( V_7 ) , V_21 ) ;
V_8 = V_19 / V_2 ;
V_8 = F_5 ( V_7 , V_8 ) ;
* V_1 = F_13 ( F_14 ( V_7 ) ,
V_8 * V_2 ) ;
return F_3 ( ( V_5 ) * V_1 , V_8 ) ;
}
static int F_15 ( struct V_6 * V_7 ,
unsigned long V_2 ,
unsigned long V_1 )
{
struct V_9 * V_10 =
F_6 ( V_7 ) ;
struct V_13 * V_14 ;
unsigned long V_15 , V_3 = 0 ;
int V_22 ;
V_22 = F_4 ( V_1 , V_2 ) ;
if ( V_10 -> V_23 )
F_16 ( V_10 -> V_23 , V_3 ) ;
else
F_17 ( V_10 -> V_23 ) ;
V_14 = & V_10 -> div ;
V_15 = F_9 ( V_10 -> V_16 + V_14 -> V_17 ) ;
V_15 = F_18 ( V_14 -> V_12 , V_14 -> V_18 , V_15 , V_22 ) ;
F_19 ( V_15 , V_10 -> V_16 + V_14 -> V_17 ) ;
if ( V_10 -> V_23 )
F_20 ( V_10 -> V_23 , V_3 ) ;
else
F_21 ( V_10 -> V_23 ) ;
return 0 ;
}
