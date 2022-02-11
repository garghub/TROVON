static T_1 F_1 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_3 + 1900 ) << V_4 )
| ( ( V_2 -> V_5 + 1 ) << V_6 )
| V_2 -> V_7 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
return ( ( ( ( V_2 -> V_7 + 6 ) / 7 ) << V_8 ) & V_9 )
| ( ( ( V_2 -> V_10 + 1 ) << V_11 ) & V_12 )
| ( V_2 -> V_13 << V_14 )
| ( V_2 -> V_15 << V_16 )
| V_2 -> V_17 ;
}
static void F_3 ( T_1 V_18 , T_1 V_19 , struct V_1 * V_2 )
{
V_2 -> V_3 = ( ( V_18 & V_20 ) >> V_4 ) - 1900 ;
V_2 -> V_5 = ( ( ( V_18 & V_21 ) >> V_6 ) ) - 1 ;
V_2 -> V_7 = ( V_18 & V_22 ) ;
V_2 -> V_10 = ( ( V_18 & V_12 ) >> V_11 ) - 1 ;
V_2 -> V_13 = ( V_19 & V_23 ) >> V_14 ;
V_2 -> V_15 = ( V_19 & V_24 ) >> V_16 ;
V_2 -> V_17 = V_19 & V_25 ;
}
static void F_4 ( struct V_26 * V_26 , T_1 V_27 )
{
T_1 V_28 ;
V_28 = F_5 ( V_26 , V_29 ) ;
V_28 &= ~ V_30 ;
V_28 &= ~ V_27 ;
F_6 ( V_26 , V_29 , V_28 ) ;
}
static void F_7 ( struct V_26 * V_26 , T_1 V_27 )
{
T_1 V_28 ;
V_28 = F_5 ( V_26 , V_29 ) ;
V_28 &= ~ V_30 ;
V_28 |= V_27 ;
F_6 ( V_26 , V_29 , V_28 ) ;
}
static T_2 F_8 ( int V_31 , void * V_32 )
{
struct V_33 * V_34 = F_9 ( V_32 ) ;
struct V_26 * V_26 = F_10 ( V_34 ) ;
T_1 V_28 ;
unsigned long V_35 = 0 ;
F_11 ( & V_26 -> V_36 ) ;
V_28 = F_5 ( V_26 , V_29 ) ;
F_6 ( V_26 , V_29 , V_28 ) ;
F_4 ( V_26 , V_37 | V_38 | V_39 ) ;
if ( V_28 & V_40 )
V_28 &= ~ V_37 ;
if ( V_28 & V_40 )
V_35 |= V_41 | V_42 ;
if ( V_28 & V_43 )
V_35 |= V_44 | V_42 ;
if ( V_28 & V_45 )
V_35 |= V_46 | V_42 ;
F_12 ( V_26 -> V_47 , 1 , V_35 ) ;
F_6 ( V_26 , V_29 , V_28 & ~ V_30 ) ;
F_13 ( & V_26 -> V_36 ) ;
return V_48 ;
}
static int F_14 ( struct V_49 * V_50 )
{
struct V_26 * V_26 = F_15 ( V_50 ) ;
int V_51 ;
V_51 = F_16 ( V_26 -> V_52 . V_53 , F_8 , 0 ,
L_1 , V_50 ) ;
if ( V_51 < 0 ) {
F_17 ( V_50 , L_2 ,
V_26 -> V_52 . V_53 , V_51 ) ;
goto V_54;
}
V_51 = F_16 ( V_26 -> V_52 . V_55 , F_8 , 0 ,
L_3 , V_50 ) ;
if ( V_51 < 0 ) {
F_17 ( V_50 , L_2 ,
V_26 -> V_52 . V_55 , V_51 ) ;
goto V_56;
}
return 0 ;
V_56:
F_18 ( V_26 -> V_52 . V_53 , V_50 ) ;
V_54:
return V_51 ;
}
static void F_19 ( struct V_49 * V_50 )
{
struct V_26 * V_26 = F_15 ( V_50 ) ;
F_20 ( & V_26 -> V_36 ) ;
F_4 ( V_26 , V_38 | V_37 | V_39 ) ;
F_21 ( & V_26 -> V_36 ) ;
F_18 ( V_26 -> V_52 . V_53 , V_50 ) ;
F_18 ( V_26 -> V_52 . V_55 , V_50 ) ;
}
static int F_22 ( struct V_49 * V_50 , unsigned int V_57 )
{
struct V_26 * V_26 = F_15 ( V_50 ) ;
F_20 ( & V_26 -> V_36 ) ;
if ( V_57 )
F_7 ( V_26 , V_37 ) ;
else
F_4 ( V_26 , V_37 ) ;
F_21 ( & V_26 -> V_36 ) ;
return 0 ;
}
static int F_23 ( struct V_49 * V_50 , struct V_1 * V_2 )
{
struct V_26 * V_26 = F_15 ( V_50 ) ;
T_1 V_18 , V_19 ;
V_18 = F_5 ( V_26 , V_58 ) ;
V_19 = F_5 ( V_26 , V_59 ) ;
F_3 ( V_18 , V_19 , V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_49 * V_50 , struct V_1 * V_2 )
{
struct V_26 * V_26 = F_15 ( V_50 ) ;
F_6 ( V_26 , V_58 , F_1 ( V_2 ) ) ;
F_6 ( V_26 , V_59 , F_2 ( V_2 ) ) ;
return 0 ;
}
static int F_25 ( struct V_49 * V_50 , struct V_60 * V_61 )
{
struct V_26 * V_26 = F_15 ( V_50 ) ;
T_1 V_28 , V_62 , V_63 ;
V_62 = F_5 ( V_26 , V_64 ) ;
V_63 = F_5 ( V_26 , V_65 ) ;
F_3 ( V_62 , V_63 , & V_61 -> time ) ;
V_28 = F_5 ( V_26 , V_29 ) ;
V_61 -> V_57 = ( V_28 & V_37 ) ? 1 : 0 ;
V_61 -> V_66 = ( V_28 & V_40 ) ? 1 : 0 ;
return 0 ;
}
static int F_26 ( struct V_49 * V_50 , struct V_60 * V_61 )
{
struct V_26 * V_26 = F_15 ( V_50 ) ;
T_1 V_28 ;
F_20 ( & V_26 -> V_36 ) ;
F_6 ( V_26 , V_64 , F_1 ( & V_61 -> time ) ) ;
F_6 ( V_26 , V_65 , F_2 ( & V_61 -> time ) ) ;
V_28 = F_5 ( V_26 , V_29 ) ;
if ( V_61 -> V_57 )
V_28 |= V_37 ;
else
V_28 &= ~ V_37 ;
F_6 ( V_26 , V_29 , V_28 ) ;
F_21 ( & V_26 -> V_36 ) ;
return 0 ;
}
static int F_27 ( struct V_49 * V_50 , struct V_67 * V_68 )
{
struct V_26 * V_26 = F_15 ( V_50 ) ;
F_28 ( V_68 , L_4 , F_5 ( V_26 , V_69 ) ) ;
F_28 ( V_68 , L_5 ,
( F_5 ( V_26 , V_29 ) & V_39 ) ? L_6 : L_7 ) ;
F_28 ( V_68 , L_8 ,
( F_5 ( V_26 , V_29 ) & V_38 ) ? L_6 : L_7 ) ;
F_28 ( V_68 , L_9 , F_5 ( V_26 , V_70 ) ) ;
return 0 ;
}
static int T_3 F_29 ( struct V_33 * V_34 )
{
struct V_49 * V_50 = & V_34 -> V_50 ;
struct V_26 * V_26 ;
struct V_52 * V_52 ;
int V_51 ;
V_26 = F_30 ( V_50 , sizeof( * V_26 ) , V_71 ) ;
if ( ! V_26 )
return - V_72 ;
V_52 = & V_26 -> V_52 ;
F_31 ( & V_26 -> V_36 ) ;
F_32 ( V_34 , V_26 ) ;
V_26 -> V_73 = F_33 ( V_34 , V_74 , 0 ) ;
if ( ! V_26 -> V_73 ) {
F_17 ( V_50 , L_10 ) ;
return - V_75 ;
}
V_52 -> V_53 = F_34 ( V_34 , 0 ) ;
if ( V_52 -> V_53 < 0 ) {
F_17 ( V_50 , L_11 ) ;
return - V_75 ;
}
V_52 -> V_55 = F_34 ( V_34 , 1 ) ;
if ( V_52 -> V_55 < 0 ) {
F_17 ( V_50 , L_12 ) ;
return - V_75 ;
}
V_26 -> V_76 = F_35 ( V_50 , V_26 -> V_73 -> V_77 ,
F_36 ( V_26 -> V_73 ) ) ;
if ( ! V_26 -> V_76 ) {
F_17 ( V_50 , L_13 ) ;
return - V_72 ;
}
F_14 ( V_50 ) ;
V_52 -> V_78 = V_26 -> V_76 + 0x0 ;
V_52 -> V_28 = V_26 -> V_76 + 0x8 ;
V_52 -> V_79 = V_26 -> V_76 + 0x4 ;
V_52 -> V_80 = V_26 -> V_76 + 0xc ;
V_51 = F_37 ( V_34 , V_52 ) ;
if ( ! V_51 ) {
F_17 ( V_50 , L_14 ) ;
return V_51 ;
}
F_4 ( V_26 , V_38 | V_37 | V_39 ) ;
V_26 -> V_47 = F_38 ( & V_34 -> V_50 , L_15 ,
& V_81 , V_82 ) ;
if ( F_39 ( V_26 -> V_47 ) ) {
V_51 = F_40 ( V_26 -> V_47 ) ;
F_17 ( V_50 , L_16 , V_51 ) ;
return V_51 ;
}
F_41 ( V_50 , 1 ) ;
return 0 ;
}
static int T_4 F_42 ( struct V_33 * V_34 )
{
struct V_49 * V_50 = & V_34 -> V_50 ;
F_19 ( V_50 ) ;
return 0 ;
}
static int F_43 ( struct V_49 * V_50 )
{
struct V_26 * V_26 = F_15 ( V_50 ) ;
if ( F_44 ( V_50 ) )
F_45 ( V_26 -> V_52 . V_55 ) ;
return 0 ;
}
static int F_46 ( struct V_49 * V_50 )
{
struct V_26 * V_26 = F_15 ( V_50 ) ;
if ( F_44 ( V_50 ) )
F_47 ( V_26 -> V_52 . V_55 ) ;
return 0 ;
}
