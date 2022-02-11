static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 = F_3 ( V_8 -> V_10 + V_11 ) ;
T_1 V_12 = V_9 * V_5 / V_6 ;
F_4 ( V_9 - V_12 , V_8 -> V_10 + V_13 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , bool V_14 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_15 ;
V_15 = F_3 ( V_8 -> V_10 + V_16 ) ;
if ( V_14 )
V_15 |= V_17 ;
else
V_15 &= ~ V_17 ;
F_4 ( V_15 , V_8 -> V_10 + V_16 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long long V_18 ;
unsigned long V_19 , V_20 , V_21 ;
T_1 V_22 ;
V_18 = F_7 ( V_8 -> V_23 ) ;
V_18 = V_18 * V_6 ;
F_8 ( V_18 , 1000000000 ) ;
V_19 = V_18 ;
V_21 = V_19 / 0x10000 + 1 ;
V_19 /= V_21 ;
V_18 = ( unsigned long long ) V_19 * V_5 ;
F_8 ( V_18 , V_6 ) ;
V_20 = V_18 ;
if ( V_19 > 2 )
V_19 -= 2 ;
else
V_19 = 0 ;
F_4 ( V_20 , V_8 -> V_10 + V_24 ) ;
F_4 ( V_19 , V_8 -> V_10 + V_25 ) ;
V_22 = F_9 ( V_21 ) |
V_26 | V_27 |
V_28 | V_29 ;
if ( V_8 -> V_30 )
V_22 |= V_31 ;
F_4 ( V_22 , V_8 -> V_10 + V_32 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , bool V_14 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_15 ;
V_15 = F_3 ( V_8 -> V_10 + V_32 ) ;
if ( V_14 )
V_15 |= V_31 ;
else
V_15 &= ~ V_31 ;
F_4 ( V_15 , V_8 -> V_10 + V_32 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_33 ;
V_33 = F_12 ( V_8 -> V_34 ) ;
if ( V_33 )
return V_33 ;
V_33 = V_8 -> V_35 ( V_2 , V_4 , V_5 , V_6 ) ;
F_13 ( V_8 -> V_34 ) ;
return V_33 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_33 ;
V_33 = F_12 ( V_8 -> V_23 ) ;
if ( V_33 )
return V_33 ;
V_8 -> V_36 ( V_2 , true ) ;
V_8 -> V_30 = 1 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_36 ( V_2 , false ) ;
F_13 ( V_8 -> V_23 ) ;
V_8 -> V_30 = 0 ;
}
static int F_16 ( struct V_37 * V_38 )
{
const struct V_39 * V_40 =
F_17 ( V_41 , & V_38 -> V_42 ) ;
const struct V_43 * V_44 ;
struct V_7 * V_8 ;
struct V_45 * V_46 ;
int V_33 = 0 ;
if ( ! V_40 )
return - V_47 ;
V_8 = F_18 ( & V_38 -> V_42 , sizeof( * V_8 ) , V_48 ) ;
if ( V_8 == NULL ) {
F_19 ( & V_38 -> V_42 , L_1 ) ;
return - V_49 ;
}
V_8 -> V_23 = F_20 ( & V_38 -> V_42 , L_2 ) ;
if ( F_21 ( V_8 -> V_23 ) ) {
F_19 ( & V_38 -> V_42 , L_3 ,
F_22 ( V_8 -> V_23 ) ) ;
return F_22 ( V_8 -> V_23 ) ;
}
V_8 -> V_34 = F_20 ( & V_38 -> V_42 , L_4 ) ;
if ( F_21 ( V_8 -> V_34 ) ) {
F_19 ( & V_38 -> V_42 , L_5 ,
F_22 ( V_8 -> V_34 ) ) ;
return F_22 ( V_8 -> V_34 ) ;
}
V_8 -> V_2 . V_50 = & V_51 ;
V_8 -> V_2 . V_42 = & V_38 -> V_42 ;
V_8 -> V_2 . V_52 = - 1 ;
V_8 -> V_2 . V_53 = 1 ;
V_46 = F_23 ( V_38 , V_54 , 0 ) ;
if ( V_46 == NULL ) {
F_19 ( & V_38 -> V_42 , L_6 ) ;
return - V_47 ;
}
V_8 -> V_10 = F_24 ( & V_38 -> V_42 , V_46 ) ;
if ( V_8 -> V_10 == NULL )
return - V_55 ;
V_44 = V_40 -> V_44 ;
V_8 -> V_35 = V_44 -> V_35 ;
V_8 -> V_36 = V_44 -> V_36 ;
V_33 = F_25 ( & V_8 -> V_2 ) ;
if ( V_33 < 0 )
return V_33 ;
F_26 ( V_38 , V_8 ) ;
return 0 ;
}
static int F_27 ( struct V_37 * V_38 )
{
struct V_7 * V_8 ;
V_8 = F_28 ( V_38 ) ;
if ( V_8 == NULL )
return - V_47 ;
return F_29 ( & V_8 -> V_2 ) ;
}
