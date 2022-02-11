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
bool V_14 = F_7 ( V_25 , & V_4 -> V_26 ) ;
int V_27 = 0 , V_28 ;
T_1 V_29 , V_30 ;
if ( V_14 ) {
V_30 = F_3 ( V_8 -> V_10 + V_31 ) ;
V_28 = V_30 & V_32 ;
if ( V_28 == V_33 ) {
V_24 = F_8 ( V_4 -> V_34 , V_35 ) ;
F_9 ( V_24 ) ;
V_30 = F_3 ( V_8 -> V_10 + V_31 ) ;
if ( V_28 == ( V_30 & V_32 ) )
F_10 ( V_19 , L_1 ) ;
}
} else {
F_4 ( V_36 , V_8 -> V_10 + V_37 ) ;
do {
F_11 ( 200 , 1000 ) ;
V_29 = F_3 ( V_8 -> V_10 + V_37 ) ;
} while ( ( V_29 & V_36 ) &&
( V_27 ++ < V_38 ) );
if ( V_29 & V_36 )
F_10 ( V_19 , L_2 ) ;
}
V_20 = F_12 ( V_8 -> V_39 ) ;
V_20 = V_20 * V_6 ;
F_13 ( V_20 , 1000000000 ) ;
V_21 = V_20 ;
V_23 = V_21 / 0x10000 + 1 ;
V_21 /= V_23 ;
V_20 = ( unsigned long long ) V_21 * V_5 ;
F_13 ( V_20 , V_6 ) ;
V_22 = V_20 ;
if ( V_21 > 2 )
V_21 -= 2 ;
else
V_21 = 0 ;
F_4 ( V_22 , V_8 -> V_10 + V_40 ) ;
F_4 ( V_21 , V_8 -> V_10 + V_41 ) ;
V_29 = F_14 ( V_23 ) |
V_42 | V_43 |
V_44 | V_45 ;
if ( V_14 )
V_29 |= V_46 ;
F_4 ( V_29 , V_8 -> V_10 + V_37 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , bool V_14 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_15 ;
V_15 = F_3 ( V_8 -> V_10 + V_37 ) ;
if ( V_14 )
V_15 |= V_46 ;
else
V_15 &= ~ V_46 ;
F_4 ( V_15 , V_8 -> V_10 + V_37 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_47 ;
V_47 = F_17 ( V_8 -> V_48 ) ;
if ( V_47 )
return V_47 ;
V_47 = V_8 -> V_49 ( V_2 , V_4 , V_5 , V_6 ) ;
F_18 ( V_8 -> V_48 ) ;
return V_47 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_47 ;
V_47 = F_17 ( V_8 -> V_39 ) ;
if ( V_47 )
return V_47 ;
V_8 -> V_50 ( V_2 , true ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_50 ( V_2 , false ) ;
F_18 ( V_8 -> V_39 ) ;
}
static int F_21 ( struct V_51 * V_52 )
{
const struct V_53 * V_54 =
F_22 ( V_55 , & V_52 -> V_19 ) ;
const struct V_56 * V_57 ;
struct V_7 * V_8 ;
struct V_58 * V_59 ;
int V_47 = 0 ;
if ( ! V_54 )
return - V_60 ;
V_8 = F_23 ( & V_52 -> V_19 , sizeof( * V_8 ) , V_61 ) ;
if ( V_8 == NULL )
return - V_62 ;
V_8 -> V_39 = F_24 ( & V_52 -> V_19 , L_3 ) ;
if ( F_25 ( V_8 -> V_39 ) ) {
F_26 ( & V_52 -> V_19 , L_4 ,
F_27 ( V_8 -> V_39 ) ) ;
return F_27 ( V_8 -> V_39 ) ;
}
V_8 -> V_48 = F_24 ( & V_52 -> V_19 , L_5 ) ;
if ( F_25 ( V_8 -> V_48 ) ) {
F_26 ( & V_52 -> V_19 , L_6 ,
F_27 ( V_8 -> V_48 ) ) ;
return F_27 ( V_8 -> V_48 ) ;
}
V_8 -> V_2 . V_63 = & V_64 ;
V_8 -> V_2 . V_19 = & V_52 -> V_19 ;
V_8 -> V_2 . V_65 = - 1 ;
V_8 -> V_2 . V_66 = 1 ;
V_8 -> V_2 . V_67 = true ;
V_59 = F_28 ( V_52 , V_68 , 0 ) ;
V_8 -> V_10 = F_29 ( & V_52 -> V_19 , V_59 ) ;
if ( F_25 ( V_8 -> V_10 ) )
return F_27 ( V_8 -> V_10 ) ;
V_57 = V_54 -> V_57 ;
V_8 -> V_49 = V_57 -> V_49 ;
V_8 -> V_50 = V_57 -> V_50 ;
V_47 = F_30 ( & V_8 -> V_2 ) ;
if ( V_47 < 0 )
return V_47 ;
F_31 ( V_52 , V_8 ) ;
return 0 ;
}
static int F_32 ( struct V_51 * V_52 )
{
struct V_7 * V_8 ;
V_8 = F_33 ( V_52 ) ;
if ( V_8 == NULL )
return - V_60 ;
return F_34 ( & V_8 -> V_2 ) ;
}
