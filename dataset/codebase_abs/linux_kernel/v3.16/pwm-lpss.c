static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_6 , int V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_1 V_9 ;
unsigned long V_10 ;
unsigned long long V_11 , V_12 = V_13 ;
T_2 V_14 ;
F_4 ( V_12 , V_7 ) ;
V_11 = V_12 * 65536 ;
V_10 = V_8 -> V_15 ;
if ( ! V_10 )
return - V_16 ;
F_4 ( V_11 , V_10 ) ;
V_11 += V_17 ;
if ( V_11 > V_18 )
return - V_16 ;
if ( V_6 <= 0 )
V_6 = 1 ;
V_9 = 255 - ( 255 * V_6 / V_7 ) ;
V_14 = F_5 ( V_8 -> V_19 + V_20 ) ;
V_14 &= ~ ( V_21 | V_22 ) ;
V_14 |= ( V_23 ) V_11 << V_24 ;
V_14 |= V_9 ;
V_14 |= V_25 ;
F_6 ( V_14 , V_8 -> V_19 + V_20 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_14 ;
int V_26 ;
V_26 = F_8 ( V_8 -> V_27 ) ;
if ( V_26 )
return V_26 ;
V_14 = F_5 ( V_8 -> V_19 + V_20 ) ;
F_6 ( V_14 | V_28 , V_8 -> V_19 + V_20 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_14 ;
V_14 = F_5 ( V_8 -> V_19 + V_20 ) ;
F_6 ( V_14 & ~ V_28 , V_8 -> V_19 + V_20 ) ;
F_10 ( V_8 -> V_27 ) ;
}
static struct V_1 * F_11 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
struct V_1 * V_8 ;
int V_26 ;
V_8 = F_12 ( V_30 , sizeof( * V_8 ) , V_35 ) ;
if ( ! V_8 )
return F_13 ( - V_36 ) ;
V_8 -> V_19 = F_14 ( V_30 , V_32 ) ;
if ( F_15 ( V_8 -> V_19 ) )
return F_16 ( V_8 -> V_19 ) ;
if ( V_34 ) {
V_8 -> V_15 = V_34 -> V_15 ;
} else {
V_8 -> V_27 = F_17 ( V_30 , NULL ) ;
if ( F_15 ( V_8 -> V_27 ) ) {
F_18 ( V_30 , L_1 ) ;
return F_16 ( V_8 -> V_27 ) ;
}
V_8 -> V_15 = F_19 ( V_8 -> V_27 ) ;
}
V_8 -> V_3 . V_30 = V_30 ;
V_8 -> V_3 . V_37 = & V_38 ;
V_8 -> V_3 . V_39 = - 1 ;
V_8 -> V_3 . V_40 = 1 ;
V_26 = F_20 ( & V_8 -> V_3 ) ;
if ( V_26 ) {
F_18 ( V_30 , L_2 , V_26 ) ;
return F_13 ( V_26 ) ;
}
return V_8 ;
}
static int F_21 ( struct V_1 * V_8 )
{
T_2 V_14 ;
V_14 = F_5 ( V_8 -> V_19 + V_20 ) ;
F_6 ( V_14 & ~ V_28 , V_8 -> V_19 + V_20 ) ;
return F_22 ( & V_8 -> V_3 ) ;
}
static int F_23 ( struct V_41 * V_42 ,
const struct V_43 * V_44 )
{
const struct V_33 * V_34 ;
struct V_1 * V_8 ;
int V_45 ;
V_45 = F_24 ( V_42 ) ;
if ( V_45 < 0 )
return V_45 ;
V_34 = (struct V_33 * ) V_44 -> V_46 ;
V_8 = F_11 ( & V_42 -> V_30 , & V_42 -> V_31 [ 0 ] , V_34 ) ;
if ( F_15 ( V_8 ) )
return F_25 ( V_8 ) ;
F_26 ( V_42 , V_8 ) ;
return 0 ;
}
static void F_27 ( struct V_41 * V_42 )
{
struct V_1 * V_8 = F_28 ( V_42 ) ;
F_21 ( V_8 ) ;
F_29 ( V_42 ) ;
}
static int F_30 ( struct V_47 * V_42 )
{
struct V_1 * V_8 ;
struct V_31 * V_32 ;
V_32 = F_31 ( V_42 , V_48 , 0 ) ;
V_8 = F_11 ( & V_42 -> V_30 , V_32 , NULL ) ;
if ( F_15 ( V_8 ) )
return F_25 ( V_8 ) ;
F_32 ( V_42 , V_8 ) ;
return 0 ;
}
static int F_33 ( struct V_47 * V_42 )
{
struct V_1 * V_8 = F_34 ( V_42 ) ;
return F_21 ( V_8 ) ;
}
static int T_3 F_35 ( void )
{
V_49 = F_36 ( & V_50 ) ;
V_51 = F_37 ( & V_52 ) ;
if ( V_49 && V_51 )
return V_49 ;
return 0 ;
}
static void T_4 F_38 ( void )
{
if ( ! V_49 )
F_39 ( & V_50 ) ;
if ( ! V_51 )
F_40 ( & V_52 ) ;
}
