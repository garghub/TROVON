static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , F_3 ( V_3 ) & ~ ( 1UL << V_2 -> V_4 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_3 , F_3 ( V_3 ) | ( 1UL << V_2 -> V_4 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_5 , ( 1UL << V_2 -> V_4 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( V_3 , F_3 ( V_3 ) & ~ ( 1UL << V_2 -> V_4 ) ) ;
F_2 ( V_5 , ( 1UL << V_2 -> V_4 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_2 ( V_5 , F_3 ( V_5 ) & ~ ( 1UL << V_2 -> V_4 ) ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_2 ( V_3 , F_3 ( V_3 ) & ~ ( 1UL << V_2 -> V_4 ) ) ;
F_2 ( V_5 , F_3 ( V_5 ) & ~ ( 1UL << V_2 -> V_4 ) ) ;
}
static inline int F_9 ( int V_6 )
{
int V_4 ;
V_4 = F_10 ( F_3 ( V_5 ) >> V_6 ) ;
if ( ! V_4 )
return V_7 ;
else
V_4 = V_4 + V_6 - 1 ;
return V_4 ;
}
static void F_11 ( struct V_8 * V_9 )
{
int V_10 = - 1 ;
while ( ( V_10 = F_9 ( V_10 + 1 ) ) != V_7 )
F_12 ( V_11 , V_10 , V_9 ) ;
}
static int F_13 ( struct V_12 * V_13 , unsigned int V_10 , T_1 V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
F_14 ( V_10 , & V_16 -> V_18 , V_16 -> V_19 ) ;
F_15 ( V_10 , V_16 -> V_20 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_21 * V_22 ,
struct V_15 * V_16 )
{
F_2 ( V_3 , ( 0UL ) ) ;
V_11 = F_17 ( V_22 , 32 , & V_23 ,
V_16 ) ;
F_18 ( F_11 ) ;
return 0 ;
}
static int T_2 F_19 ( struct V_21 * V_22 ,
struct V_21 * V_24 )
{
return F_16 ( V_22 , & V_25 ) ;
}
static int T_2 F_20 ( struct V_21 * V_22 ,
struct V_21 * V_24 )
{
return F_16 ( V_22 , & V_26 ) ;
}
static int T_2 F_21 ( struct V_21 * V_22 ,
struct V_21 * V_24 )
{
return F_16 ( V_22 , & V_27 ) ;
}
