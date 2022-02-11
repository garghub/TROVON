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
struct V_18 * V_19 = V_2 -> V_19 ;
unsigned long long V_20 ;
unsigned long V_21 , V_22 , V_23 ;
unsigned int V_24 ;
bool V_14 = F_7 ( V_4 ) ;
int V_25 = 0 , V_26 ;
T_1 V_27 , V_28 ;
if ( V_14 ) {
V_28 = F_3 ( V_8 -> V_10 + V_29 ) ;
V_26 = V_28 & V_30 ;
if ( V_26 == V_31 ) {
V_24 = F_8 ( F_9 ( V_4 ) ,
V_32 ) ;
F_10 ( V_24 ) ;
V_28 = F_3 ( V_8 -> V_10 + V_29 ) ;
if ( V_26 == ( V_28 & V_30 ) )
F_11 ( V_19 , L_1 ) ;
}
} else {
F_4 ( V_33 , V_8 -> V_10 + V_34 ) ;
do {
F_12 ( 200 , 1000 ) ;
V_27 = F_3 ( V_8 -> V_10 + V_34 ) ;
} while ( ( V_27 & V_33 ) &&
( V_25 ++ < V_35 ) );
if ( V_27 & V_33 )
F_11 ( V_19 , L_2 ) ;
}
V_20 = F_13 ( V_8 -> V_36 ) ;
V_20 = V_20 * V_6 ;
F_14 ( V_20 , 1000000000 ) ;
V_21 = V_20 ;
V_23 = V_21 / 0x10000 + 1 ;
V_21 /= V_23 ;
V_20 = ( unsigned long long ) V_21 * V_5 ;
F_14 ( V_20 , V_6 ) ;
V_22 = V_20 ;
if ( V_21 > 2 )
V_21 -= 2 ;
else
V_21 = 0 ;
F_4 ( V_22 , V_8 -> V_10 + V_37 ) ;
F_4 ( V_21 , V_8 -> V_10 + V_38 ) ;
V_27 = F_15 ( V_23 ) |
V_39 | V_40 |
V_41 | V_42 ;
if ( V_14 )
V_27 |= V_43 ;
F_4 ( V_27 , V_8 -> V_10 + V_34 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , bool V_14 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_15 ;
V_15 = F_3 ( V_8 -> V_10 + V_34 ) ;
if ( V_14 )
V_15 |= V_43 ;
else
V_15 &= ~ V_43 ;
F_4 ( V_15 , V_8 -> V_10 + V_34 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_44 ;
V_44 = F_18 ( V_8 -> V_45 ) ;
if ( V_44 )
return V_44 ;
V_44 = V_8 -> V_46 ( V_2 , V_4 , V_5 , V_6 ) ;
F_19 ( V_8 -> V_45 ) ;
return V_44 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_44 ;
V_44 = F_18 ( V_8 -> V_36 ) ;
if ( V_44 )
return V_44 ;
V_8 -> V_47 ( V_2 , true ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_47 ( V_2 , false ) ;
F_19 ( V_8 -> V_36 ) ;
}
static int F_22 ( struct V_48 * V_49 )
{
const struct V_50 * V_51 =
F_23 ( V_52 , & V_49 -> V_19 ) ;
const struct V_53 * V_54 ;
struct V_7 * V_8 ;
struct V_55 * V_56 ;
int V_44 = 0 ;
if ( ! V_51 )
return - V_57 ;
V_8 = F_24 ( & V_49 -> V_19 , sizeof( * V_8 ) , V_58 ) ;
if ( V_8 == NULL )
return - V_59 ;
V_8 -> V_36 = F_25 ( & V_49 -> V_19 , L_3 ) ;
if ( F_26 ( V_8 -> V_36 ) ) {
F_27 ( & V_49 -> V_19 , L_4 ,
F_28 ( V_8 -> V_36 ) ) ;
return F_28 ( V_8 -> V_36 ) ;
}
V_8 -> V_45 = F_25 ( & V_49 -> V_19 , L_5 ) ;
if ( F_26 ( V_8 -> V_45 ) ) {
F_27 ( & V_49 -> V_19 , L_6 ,
F_28 ( V_8 -> V_45 ) ) ;
return F_28 ( V_8 -> V_45 ) ;
}
V_8 -> V_2 . V_60 = & V_61 ;
V_8 -> V_2 . V_19 = & V_49 -> V_19 ;
V_8 -> V_2 . V_62 = - 1 ;
V_8 -> V_2 . V_63 = 1 ;
V_8 -> V_2 . V_64 = true ;
V_56 = F_29 ( V_49 , V_65 , 0 ) ;
V_8 -> V_10 = F_30 ( & V_49 -> V_19 , V_56 ) ;
if ( F_26 ( V_8 -> V_10 ) )
return F_28 ( V_8 -> V_10 ) ;
V_54 = V_51 -> V_54 ;
V_8 -> V_46 = V_54 -> V_46 ;
V_8 -> V_47 = V_54 -> V_47 ;
V_44 = F_31 ( & V_8 -> V_2 ) ;
if ( V_44 < 0 )
return V_44 ;
F_32 ( V_49 , V_8 ) ;
return 0 ;
}
static int F_33 ( struct V_48 * V_49 )
{
struct V_7 * V_8 ;
V_8 = F_34 ( V_49 ) ;
if ( V_8 == NULL )
return - V_57 ;
return F_35 ( & V_8 -> V_2 ) ;
}
