static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , int V_5 )
{
V_4 -> V_6 |= V_7 ;
F_4 ( 0 , V_4 -> V_8 + V_9 ) ;
F_4 ( V_5 , V_4 -> V_8 + V_10 ) ;
F_4 ( V_11 , V_4 -> V_8 + V_12 ) ;
F_4 ( V_4 -> V_6 , V_4 -> V_8 + V_9 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_3 ( V_4 , V_3 -> V_13 * V_14 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_6 &= ~ V_7 ;
F_4 ( V_4 -> V_6 , V_4 -> V_8 + V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_11 , V_4 -> V_8 + V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 ,
unsigned int V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_15 ;
V_3 -> V_13 = V_13 ;
V_15 = F_9 ( V_13 , V_3 -> V_16 * 1000 ) ;
F_4 ( V_15 * V_14 , V_4 -> V_8 + V_10 ) ;
F_4 ( V_11 , V_4 -> V_8 + V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
unsigned long V_17 , void * V_18 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_3 ( V_4 , 128 * V_14 / 1000 ) ;
F_11 ( 1000 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 )
{
struct V_1 * V_4 = F_13 ( V_20 ) ;
F_14 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_1 * V_4 ;
struct V_21 * V_22 ;
int V_23 ;
V_4 = F_16 ( & V_20 -> V_24 , sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 )
return - V_26 ;
V_22 = F_17 ( V_20 , V_27 , 0 ) ;
V_4 -> V_8 = F_18 ( & V_20 -> V_24 , V_22 ) ;
if ( F_19 ( V_4 -> V_8 ) )
return F_20 ( V_4 -> V_8 ) ;
V_4 -> V_3 . V_28 = & V_29 ;
V_4 -> V_3 . V_30 = & V_31 ;
V_4 -> V_3 . V_16 = V_32 ;
V_4 -> V_3 . V_33 = & V_20 -> V_24 ;
V_4 -> V_3 . V_13 = V_34 ;
F_21 ( & V_4 -> V_3 , 0 , & V_20 -> V_24 ) ;
V_4 -> V_6 = V_35 |
V_36 |
V_37 ;
if ( F_22 ( V_4 -> V_8 + V_9 ) & V_7 ) {
F_5 ( & V_4 -> V_3 ) ;
F_23 ( V_38 , & V_4 -> V_3 . V_39 ) ;
}
V_23 = F_24 ( & V_4 -> V_3 ) ;
if ( V_23 ) {
F_25 ( & V_20 -> V_24 , L_1 ) ;
return V_23 ;
}
F_26 ( V_20 , V_4 ) ;
return 0 ;
}
