static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_6 , int V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long long V_9 ;
unsigned int V_10 ;
if ( V_6 < 1 ) {
if ( V_5 -> V_11 >= V_12 )
V_10 = V_13 ;
else
V_10 = F_4 ( V_5 -> V_11 ) ;
F_5 ( V_8 -> V_14 , V_10 , V_15 ) ;
return 0 ;
}
if ( V_6 == V_7 ) {
if ( V_5 -> V_11 >= V_12 )
V_10 = V_16 ;
else
V_10 = F_6 ( V_5 -> V_11 ) ;
F_5 ( V_8 -> V_14 , V_10 , V_15 ) ;
return 0 ;
}
V_9 = 4096 * ( unsigned long long ) V_6 ;
V_9 = F_7 ( V_9 , V_7 ) ;
if ( V_5 -> V_11 >= V_12 )
V_10 = V_17 ;
else
V_10 = F_8 ( V_5 -> V_11 ) ;
F_5 ( V_8 -> V_14 , V_10 , ( int ) V_9 & 0xff ) ;
if ( V_5 -> V_11 >= V_12 )
V_10 = V_13 ;
else
V_10 = F_4 ( V_5 -> V_11 ) ;
F_5 ( V_8 -> V_14 , V_10 , ( ( int ) V_9 >> 8 ) & 0xf ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned int V_10 ;
if ( V_5 -> V_11 >= V_12 )
V_10 = V_18 ;
else
V_10 = F_10 ( V_5 -> V_11 ) ;
F_5 ( V_8 -> V_14 , V_10 , 0 ) ;
if ( V_5 -> V_11 >= V_12 )
V_10 = V_16 ;
else
V_10 = F_6 ( V_5 -> V_11 ) ;
F_5 ( V_8 -> V_14 , V_10 , 0 ) ;
if ( V_5 -> V_11 >= V_12 )
V_10 = V_13 ;
else
V_10 = F_4 ( V_5 -> V_11 ) ;
F_11 ( V_8 -> V_14 , V_10 , V_15 , 0x0 ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned int V_10 ;
if ( V_5 -> V_11 >= V_12 )
V_10 = V_13 ;
else
V_10 = F_4 ( V_5 -> V_11 ) ;
F_5 ( V_8 -> V_14 , V_10 , V_15 ) ;
if ( V_5 -> V_11 >= V_12 )
V_10 = V_17 ;
else
V_10 = F_8 ( V_5 -> V_11 ) ;
F_5 ( V_8 -> V_14 , V_10 , 0x0 ) ;
}
static int F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_8 -> V_19 ++ == 0 )
return F_11 ( V_8 -> V_14 , V_20 ,
V_21 , 0x0 ) ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( -- V_8 -> V_19 == 0 )
F_11 ( V_8 -> V_14 , V_20 , V_21 ,
V_21 ) ;
}
static int F_15 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 * V_27 = V_23 -> V_28 . V_29 ;
struct V_1 * V_8 ;
int V_30 ;
int V_31 ;
V_8 = F_16 ( & V_23 -> V_28 , sizeof( * V_8 ) , V_32 ) ;
if ( ! V_8 )
return - V_33 ;
V_8 -> V_14 = F_17 ( V_23 , & V_34 ) ;
if ( F_18 ( V_8 -> V_14 ) ) {
V_30 = F_19 ( V_8 -> V_14 ) ;
F_20 ( & V_23 -> V_28 , L_1 ,
V_30 ) ;
return V_30 ;
}
F_21 ( V_23 , V_8 ) ;
F_22 ( V_8 -> V_14 , V_35 , & V_31 ) ;
if ( F_23 ( V_27 , L_2 ) )
V_31 |= V_36 ;
else
V_31 &= ~ V_36 ;
if ( F_23 ( V_27 , L_3 ) )
V_31 &= ~ V_37 ;
else
V_31 |= V_37 ;
F_5 ( V_8 -> V_14 , V_35 , V_31 ) ;
F_5 ( V_8 -> V_14 , V_17 , 0 ) ;
F_5 ( V_8 -> V_14 , V_13 , 0 ) ;
V_8 -> V_3 . V_38 = & V_39 ;
V_8 -> V_3 . V_40 = V_12 + 1 ;
V_8 -> V_3 . V_28 = & V_23 -> V_28 ;
V_8 -> V_3 . V_41 = - 1 ;
V_8 -> V_3 . V_42 = true ;
return F_24 ( & V_8 -> V_3 ) ;
}
static int F_25 ( struct V_22 * V_23 )
{
struct V_1 * V_8 = F_26 ( V_23 ) ;
F_11 ( V_8 -> V_14 , V_20 , V_21 ,
V_21 ) ;
return F_27 ( & V_8 -> V_3 ) ;
}
