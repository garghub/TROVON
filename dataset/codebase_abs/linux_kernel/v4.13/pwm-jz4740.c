static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( V_5 -> V_6 < 2 )
return - V_7 ;
F_4 ( V_5 -> V_6 ) ;
return 0 ;
}
static void F_5 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_6 ( V_5 -> V_6 , 0 ) ;
F_7 ( V_5 -> V_6 ) ;
}
static int F_8 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
T_1 V_8 = F_9 ( V_5 -> V_5 ) ;
V_8 |= V_9 ;
F_6 ( V_5 -> V_6 , V_8 ) ;
F_10 ( V_5 -> V_6 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
T_1 V_8 = F_9 ( V_5 -> V_6 ) ;
V_8 &= ~ V_9 ;
F_12 ( V_5 -> V_6 ) ;
F_6 ( V_5 -> V_6 , V_8 ) ;
}
static int F_13 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_10 , int V_11 )
{
struct V_1 * V_12 = F_1 ( V_5 -> V_3 ) ;
unsigned long long V_13 ;
unsigned long V_14 , V_15 ;
unsigned int V_16 = 0 ;
T_2 V_8 ;
bool V_17 ;
V_13 = ( unsigned long long ) F_14 ( V_12 -> V_18 ) * V_11 ;
F_15 ( V_13 , 1000000000 ) ;
V_14 = V_13 ;
while ( V_14 > 0xffff && V_16 < 6 ) {
V_14 >>= 2 ;
++ V_16 ;
}
if ( V_16 == 6 )
return - V_19 ;
V_13 = ( unsigned long long ) V_14 * V_10 ;
F_15 ( V_13 , V_11 ) ;
V_15 = V_14 - V_13 ;
if ( V_15 >= V_14 )
V_15 = V_14 - 1 ;
V_17 = F_16 ( V_5 -> V_6 ) ;
if ( V_17 )
F_11 ( V_3 , V_5 ) ;
F_17 ( V_5 -> V_6 , 0 ) ;
F_18 ( V_5 -> V_6 , V_15 ) ;
F_19 ( V_5 -> V_6 , V_14 ) ;
V_8 = F_20 ( V_16 ) | V_20 |
V_21 ;
F_6 ( V_5 -> V_6 , V_8 ) ;
if ( V_17 )
F_8 ( V_3 , V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_22 * V_23 )
{
struct V_1 * V_12 ;
V_12 = F_22 ( & V_23 -> V_24 , sizeof( * V_12 ) , V_25 ) ;
if ( ! V_12 )
return - V_26 ;
V_12 -> V_18 = F_23 ( & V_23 -> V_24 , L_1 ) ;
if ( F_24 ( V_12 -> V_18 ) )
return F_25 ( V_12 -> V_18 ) ;
V_12 -> V_3 . V_24 = & V_23 -> V_24 ;
V_12 -> V_3 . V_27 = & V_28 ;
V_12 -> V_3 . V_29 = V_30 ;
V_12 -> V_3 . V_31 = - 1 ;
F_26 ( V_23 , V_12 ) ;
return F_27 ( & V_12 -> V_3 ) ;
}
static int F_28 ( struct V_22 * V_23 )
{
struct V_1 * V_12 = F_29 ( V_23 ) ;
return F_30 ( & V_12 -> V_3 ) ;
}
