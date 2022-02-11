static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned int V_6 = V_7 [ V_5 -> V_8 ] ;
int V_9 ;
if ( V_5 -> V_8 < 2 )
return - V_10 ;
V_9 = F_4 ( V_6 , V_5 -> V_11 ) ;
if ( V_9 ) {
F_5 ( V_3 -> V_12 , L_1 ,
V_6 , V_9 ) ;
return V_9 ;
}
F_6 ( V_6 , V_13 ) ;
F_7 ( V_5 -> V_8 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned int V_6 = V_7 [ V_5 -> V_8 ] ;
F_9 ( V_5 -> V_8 , 0 ) ;
F_6 ( V_6 , V_14 ) ;
F_10 ( V_6 ) ;
F_11 ( V_5 -> V_8 ) ;
}
static int F_12 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
T_1 V_15 = F_13 ( V_5 -> V_5 ) ;
V_15 |= V_16 ;
F_9 ( V_5 -> V_8 , V_15 ) ;
F_14 ( V_5 -> V_8 ) ;
return 0 ;
}
static void F_15 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
T_1 V_15 = F_13 ( V_5 -> V_8 ) ;
V_15 &= ~ V_16 ;
F_16 ( V_5 -> V_8 ) ;
F_9 ( V_5 -> V_8 , V_15 ) ;
}
static int F_17 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_17 , int V_18 )
{
struct V_1 * V_19 = F_1 ( V_5 -> V_3 ) ;
unsigned long long V_20 ;
unsigned long V_21 , V_22 ;
unsigned int V_23 = 0 ;
T_2 V_15 ;
bool V_24 ;
V_20 = ( unsigned long long ) F_18 ( V_19 -> V_25 ) * V_18 ;
F_19 ( V_20 , 1000000000 ) ;
V_21 = V_20 ;
while ( V_21 > 0xffff && V_23 < 6 ) {
V_21 >>= 2 ;
++ V_23 ;
}
if ( V_23 == 6 )
return - V_26 ;
V_20 = ( unsigned long long ) V_21 * V_17 ;
F_19 ( V_20 , V_18 ) ;
V_22 = V_21 - V_20 ;
if ( V_22 >= V_21 )
V_22 = V_21 - 1 ;
V_24 = F_20 ( V_5 -> V_8 ) ;
if ( V_24 )
F_15 ( V_3 , V_5 ) ;
F_21 ( V_5 -> V_8 , 0 ) ;
F_22 ( V_5 -> V_8 , V_22 ) ;
F_23 ( V_5 -> V_8 , V_21 ) ;
V_15 = F_24 ( V_23 ) | V_27 |
V_28 ;
F_9 ( V_5 -> V_8 , V_15 ) ;
if ( V_24 )
F_12 ( V_3 , V_5 ) ;
return 0 ;
}
static int F_25 ( struct V_29 * V_30 )
{
struct V_1 * V_19 ;
int V_9 ;
V_19 = F_26 ( & V_30 -> V_12 , sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 )
return - V_32 ;
V_19 -> V_25 = F_27 ( NULL , L_2 ) ;
if ( F_28 ( V_19 -> V_25 ) )
return F_29 ( V_19 -> V_25 ) ;
V_19 -> V_3 . V_12 = & V_30 -> V_12 ;
V_19 -> V_3 . V_33 = & V_34 ;
V_19 -> V_3 . V_35 = V_36 ;
V_19 -> V_3 . V_37 = - 1 ;
V_9 = F_30 ( & V_19 -> V_3 ) ;
if ( V_9 < 0 ) {
F_31 ( V_19 -> V_25 ) ;
return V_9 ;
}
F_32 ( V_30 , V_19 ) ;
return 0 ;
}
static int F_33 ( struct V_29 * V_30 )
{
struct V_1 * V_19 = F_34 ( V_30 ) ;
int V_9 ;
V_9 = F_35 ( & V_19 -> V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
F_31 ( V_19 -> V_25 ) ;
return 0 ;
}
