static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 = F_3 ( V_8 -> V_10 + V_11 ) ;
T_1 V_12 = V_9 * V_5 / V_6 ;
F_4 ( V_9 - V_12 , V_8 -> V_10 + V_13 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_14 ;
int V_15 ;
V_15 = F_6 ( V_8 -> V_16 ) ;
if ( V_15 < 0 )
return V_15 ;
V_14 = F_3 ( V_8 -> V_10 + V_17 ) ;
V_14 |= V_18 ;
F_4 ( V_14 , V_8 -> V_10 + V_17 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_14 ;
V_14 = F_3 ( V_8 -> V_10 + V_17 ) ;
V_14 &= ~ V_18 ;
F_4 ( V_14 , V_8 -> V_10 + V_17 ) ;
F_8 ( V_8 -> V_16 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
int V_21 = 0 ;
T_1 V_22 ;
F_4 ( V_23 , V_8 -> V_10 + V_24 ) ;
do {
F_10 ( 200 , 1000 ) ;
V_22 = F_3 ( V_8 -> V_10 + V_24 ) ;
} while ( ( V_22 & V_23 ) &&
( V_21 ++ < V_25 ) );
if ( V_22 & V_23 )
F_11 ( V_20 , L_1 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
unsigned int V_26 ;
int V_27 ;
T_1 V_28 ;
V_28 = F_3 ( V_8 -> V_10 + V_29 ) ;
V_27 = V_28 & V_30 ;
if ( V_27 == V_31 ) {
V_26 = F_13 ( F_14 ( V_4 ) ,
V_32 ) ;
F_15 ( V_26 ) ;
V_28 = F_3 ( V_8 -> V_10 + V_29 ) ;
if ( V_27 == ( V_28 & V_30 ) )
F_11 ( V_20 , L_2 ) ;
}
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_33 * V_34 )
{
unsigned long V_35 , V_36 , V_37 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_33 V_38 ;
unsigned long long V_39 ;
int V_15 ;
T_1 V_22 ;
F_17 ( V_4 , & V_38 ) ;
if ( V_34 -> V_40 ) {
V_39 = F_18 ( V_8 -> V_16 ) ;
V_39 *= V_34 -> V_41 ;
F_19 ( V_39 , 1000000000 ) ;
V_35 = V_39 ;
V_37 = V_35 / 0x10000 + 1 ;
V_35 /= V_37 ;
V_39 = ( unsigned long long ) V_35 * V_34 -> V_42 ;
F_19 ( V_39 , V_34 -> V_41 ) ;
V_36 = V_39 ;
if ( V_35 > 2 )
V_35 -= 2 ;
else
V_35 = 0 ;
if ( V_38 . V_40 ) {
F_12 ( V_2 , V_4 ) ;
} else {
V_15 = F_6 ( V_8 -> V_16 ) ;
if ( V_15 )
return V_15 ;
F_9 ( V_2 ) ;
}
F_4 ( V_36 , V_8 -> V_10 + V_43 ) ;
F_4 ( V_35 , V_8 -> V_10 + V_44 ) ;
V_22 = F_20 ( V_37 ) |
V_45 | V_46 |
V_47 | V_48 |
V_49 ;
if ( V_34 -> V_50 == V_51 )
V_22 |= V_52 ;
F_4 ( V_22 , V_8 -> V_10 + V_24 ) ;
} else if ( V_38 . V_40 ) {
F_4 ( 0 , V_8 -> V_10 + V_24 ) ;
F_8 ( V_8 -> V_16 ) ;
}
return 0 ;
}
static int F_21 ( struct V_53 * V_54 )
{
const struct V_55 * V_56 =
F_22 ( V_57 , & V_54 -> V_20 ) ;
const struct V_58 * V_59 ;
struct V_7 * V_8 ;
struct V_60 * V_61 ;
int V_15 = 0 ;
if ( ! V_56 )
return - V_62 ;
V_59 = V_56 -> V_59 ;
V_8 = F_23 ( & V_54 -> V_20 , sizeof( * V_8 ) , V_63 ) ;
if ( V_8 == NULL )
return - V_64 ;
V_8 -> V_16 = F_24 ( & V_54 -> V_20 , L_3 ) ;
if ( F_25 ( V_8 -> V_16 ) ) {
F_26 ( & V_54 -> V_20 , L_4 ,
F_27 ( V_8 -> V_16 ) ) ;
return F_27 ( V_8 -> V_16 ) ;
}
V_8 -> V_2 . V_65 = V_59 -> V_65 ;
V_8 -> V_2 . V_20 = & V_54 -> V_20 ;
V_8 -> V_2 . V_66 = - 1 ;
V_8 -> V_2 . V_67 = 1 ;
if ( V_59 -> V_68 ) {
F_28 ( & V_54 -> V_20 , L_5 ) ;
V_8 -> V_2 . V_69 = V_70 ;
V_8 -> V_2 . V_71 = 3 ;
}
V_61 = F_29 ( V_54 , V_72 , 0 ) ;
V_8 -> V_10 = F_30 ( & V_54 -> V_20 , V_61 ) ;
if ( F_25 ( V_8 -> V_10 ) )
return F_27 ( V_8 -> V_10 ) ;
V_15 = F_31 ( & V_8 -> V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
F_32 ( V_54 , V_8 ) ;
return 0 ;
}
static int F_33 ( struct V_53 * V_54 )
{
struct V_7 * V_8 ;
V_8 = F_34 ( V_54 ) ;
if ( V_8 == NULL )
return - V_62 ;
return F_35 ( & V_8 -> V_2 ) ;
}
