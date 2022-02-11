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
int V_11 ;
if ( V_7 != V_8 -> V_7 ) {
V_11 = F_4 ( V_12 * V_7 ,
V_13 * 1000 ) - 1 ;
if ( V_11 >= V_14 &&
V_11 <= V_15 ) {
F_5 ( V_8 -> V_16 , V_17 ,
V_18 , V_18 ) ;
F_6 ( V_8 -> V_16 , V_19 , V_11 ) ;
F_5 ( V_8 -> V_16 , V_17 ,
V_18 , 0x0 ) ;
F_7 ( 500 ) ;
V_8 -> V_7 = V_7 ;
if ( V_6 == V_8 -> V_6 ) {
F_5 ( V_8 -> V_16 , V_17 ,
V_20 , 0x1 ) ;
return 0 ;
}
} else {
F_8 ( V_3 -> V_21 ,
L_1 ) ;
return - V_22 ;
}
}
V_8 -> V_6 = V_6 ;
if ( V_6 < 1 ) {
if ( V_5 -> V_23 >= V_24 )
V_10 = V_25 ;
else
V_10 = F_9 ( V_5 -> V_23 ) ;
F_6 ( V_8 -> V_16 , V_10 , V_26 ) ;
return 0 ;
}
if ( V_6 == V_7 ) {
if ( V_5 -> V_23 >= V_24 )
V_10 = V_27 ;
else
V_10 = F_10 ( V_5 -> V_23 ) ;
F_6 ( V_8 -> V_16 , V_10 , 0x0 ) ;
if ( V_5 -> V_23 >= V_24 )
V_10 = V_25 ;
else
V_10 = F_9 ( V_5 -> V_23 ) ;
F_6 ( V_8 -> V_16 , V_10 , 0x0 ) ;
if ( V_5 -> V_23 >= V_24 )
V_10 = V_28 ;
else
V_10 = F_11 ( V_5 -> V_23 ) ;
F_6 ( V_8 -> V_16 , V_10 , V_26 ) ;
return 0 ;
}
V_9 = V_13 * ( unsigned long long ) V_6 ;
V_9 = F_12 ( V_9 , V_7 ) ;
if ( V_5 -> V_23 >= V_24 )
V_10 = V_27 ;
else
V_10 = F_10 ( V_5 -> V_23 ) ;
F_6 ( V_8 -> V_16 , V_10 , ( int ) V_9 & 0xff ) ;
if ( V_5 -> V_23 >= V_24 )
V_10 = V_25 ;
else
V_10 = F_9 ( V_5 -> V_23 ) ;
F_6 ( V_8 -> V_16 , V_10 , ( ( int ) V_9 >> 8 ) & 0xf ) ;
if ( V_5 -> V_23 >= V_24 )
V_10 = V_28 ;
else
V_10 = F_11 ( V_5 -> V_23 ) ;
F_6 ( V_8 -> V_16 , V_10 , 0 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned int V_10 ;
if ( V_5 -> V_23 >= V_24 )
V_10 = V_29 ;
else
V_10 = F_14 ( V_5 -> V_23 ) ;
F_6 ( V_8 -> V_16 , V_10 , 0 ) ;
if ( V_5 -> V_23 >= V_24 )
V_10 = V_28 ;
else
V_10 = F_11 ( V_5 -> V_23 ) ;
F_6 ( V_8 -> V_16 , V_10 , 0 ) ;
if ( V_5 -> V_23 >= V_24 )
V_10 = V_25 ;
else
V_10 = F_9 ( V_5 -> V_23 ) ;
F_5 ( V_8 -> V_16 , V_10 , V_26 , 0x0 ) ;
return 0 ;
}
static void F_15 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned int V_10 ;
if ( V_5 -> V_23 >= V_24 )
V_10 = V_25 ;
else
V_10 = F_9 ( V_5 -> V_23 ) ;
F_6 ( V_8 -> V_16 , V_10 , V_26 ) ;
if ( V_5 -> V_23 >= V_24 )
V_10 = V_27 ;
else
V_10 = F_10 ( V_5 -> V_23 ) ;
F_6 ( V_8 -> V_16 , V_10 , 0x0 ) ;
}
static int F_16 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_8 -> V_30 ++ == 0 )
return F_5 ( V_8 -> V_16 , V_17 ,
V_18 , 0x0 ) ;
return 0 ;
}
static void F_17 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( -- V_8 -> V_30 == 0 )
F_5 ( V_8 -> V_16 , V_17 , V_18 ,
V_18 ) ;
}
static int F_18 ( struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
struct V_35 * V_36 = V_32 -> V_21 . V_37 ;
struct V_1 * V_8 ;
int V_38 ;
int V_39 ;
V_8 = F_19 ( & V_32 -> V_21 , sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 )
return - V_41 ;
V_8 -> V_16 = F_20 ( V_32 , & V_42 ) ;
if ( F_21 ( V_8 -> V_16 ) ) {
V_38 = F_22 ( V_8 -> V_16 ) ;
F_8 ( & V_32 -> V_21 , L_2 ,
V_38 ) ;
return V_38 ;
}
V_8 -> V_6 = 0 ;
V_8 -> V_7 = V_43 ;
F_23 ( V_32 , V_8 ) ;
F_24 ( V_8 -> V_16 , V_44 , & V_39 ) ;
if ( F_25 ( V_36 , L_3 ) )
V_39 |= V_45 ;
else
V_39 &= ~ V_45 ;
if ( F_25 ( V_36 , L_4 ) )
V_39 &= ~ V_46 ;
else
V_39 |= V_46 ;
F_6 ( V_8 -> V_16 , V_44 , V_39 ) ;
F_6 ( V_8 -> V_16 , V_27 , 0 ) ;
F_6 ( V_8 -> V_16 , V_25 , 0 ) ;
V_8 -> V_3 . V_47 = & V_48 ;
V_8 -> V_3 . V_49 = V_24 + 1 ;
V_8 -> V_3 . V_21 = & V_32 -> V_21 ;
V_8 -> V_3 . V_50 = - 1 ;
V_8 -> V_3 . V_51 = true ;
return F_26 ( & V_8 -> V_3 ) ;
}
static int F_27 ( struct V_31 * V_32 )
{
struct V_1 * V_8 = F_28 ( V_32 ) ;
F_5 ( V_8 -> V_16 , V_17 , V_18 ,
V_18 ) ;
return F_29 ( & V_8 -> V_3 ) ;
}
