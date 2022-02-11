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
if ( F_10 ( V_30 , & V_4 -> V_31 ) )
V_22 |= V_32 ;
F_4 ( V_22 , V_8 -> V_10 + V_33 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , bool V_14 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_15 ;
V_15 = F_3 ( V_8 -> V_10 + V_33 ) ;
if ( V_14 )
V_15 |= V_32 ;
else
V_15 &= ~ V_32 ;
F_4 ( V_15 , V_8 -> V_10 + V_33 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_34 ;
V_34 = F_13 ( V_8 -> V_35 ) ;
if ( V_34 )
return V_34 ;
V_34 = V_8 -> V_36 ( V_2 , V_4 , V_5 , V_6 ) ;
F_14 ( V_8 -> V_35 ) ;
return V_34 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_34 ;
V_34 = F_13 ( V_8 -> V_23 ) ;
if ( V_34 )
return V_34 ;
V_8 -> V_37 ( V_2 , true ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_37 ( V_2 , false ) ;
F_14 ( V_8 -> V_23 ) ;
}
static int F_17 ( struct V_38 * V_39 )
{
const struct V_40 * V_41 =
F_18 ( V_42 , & V_39 -> V_43 ) ;
const struct V_44 * V_45 ;
struct V_7 * V_8 ;
struct V_46 * V_47 ;
int V_34 = 0 ;
if ( ! V_41 )
return - V_48 ;
V_8 = F_19 ( & V_39 -> V_43 , sizeof( * V_8 ) , V_49 ) ;
if ( V_8 == NULL ) {
F_20 ( & V_39 -> V_43 , L_1 ) ;
return - V_50 ;
}
V_8 -> V_23 = F_21 ( & V_39 -> V_43 , L_2 ) ;
if ( F_22 ( V_8 -> V_23 ) ) {
F_20 ( & V_39 -> V_43 , L_3 ,
F_23 ( V_8 -> V_23 ) ) ;
return F_23 ( V_8 -> V_23 ) ;
}
V_8 -> V_35 = F_21 ( & V_39 -> V_43 , L_4 ) ;
if ( F_22 ( V_8 -> V_35 ) ) {
F_20 ( & V_39 -> V_43 , L_5 ,
F_23 ( V_8 -> V_35 ) ) ;
return F_23 ( V_8 -> V_35 ) ;
}
V_8 -> V_2 . V_51 = & V_52 ;
V_8 -> V_2 . V_43 = & V_39 -> V_43 ;
V_8 -> V_2 . V_53 = - 1 ;
V_8 -> V_2 . V_54 = 1 ;
V_47 = F_24 ( V_39 , V_55 , 0 ) ;
V_8 -> V_10 = F_25 ( & V_39 -> V_43 , V_47 ) ;
if ( F_22 ( V_8 -> V_10 ) )
return F_23 ( V_8 -> V_10 ) ;
V_45 = V_41 -> V_45 ;
V_8 -> V_36 = V_45 -> V_36 ;
V_8 -> V_37 = V_45 -> V_37 ;
V_34 = F_26 ( & V_8 -> V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
F_27 ( V_39 , V_8 ) ;
return 0 ;
}
static int F_28 ( struct V_38 * V_39 )
{
struct V_7 * V_8 ;
V_8 = F_29 ( V_39 ) ;
if ( V_8 == NULL )
return - V_48 ;
return F_30 ( & V_8 -> V_2 ) ;
}
