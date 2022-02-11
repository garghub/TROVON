static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_6 + V_4 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_6 + V_4 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_7 + V_4 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_7 + V_4 ) ;
}
static void F_9 ( struct V_8 * V_9 , bool V_10 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
if ( V_10 ) {
V_3 = F_3 ( V_1 , V_11 ) ;
V_3 |= V_12 ;
F_1 ( V_1 , V_3 , V_11 ) ;
} else {
V_3 = F_3 ( V_1 , V_11 ) ;
V_3 &= ~ V_12 ;
F_1 ( V_1 , V_3 , V_11 ) ;
}
}
static void F_11 ( struct V_8 * V_9 , bool V_10 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
if ( V_10 ) {
V_3 = F_3 ( V_1 , V_13 ) ;
V_3 |= V_12 ;
F_1 ( V_1 , V_3 , V_13 ) ;
} else {
V_3 = F_3 ( V_1 , V_13 ) ;
V_3 &= ~ V_12 ;
F_1 ( V_1 , V_3 , V_13 ) ;
}
}
static void F_12 ( struct V_8 * V_9 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
V_3 = F_3 ( V_1 , V_14 ) ;
V_3 &= ~ V_15 ;
F_1 ( V_1 , V_3 , V_14 ) ;
F_1 ( V_1 , 0 , V_16 ) ;
F_1 ( V_1 , 0 , V_17 ) ;
F_1 ( V_1 , 0 , V_18 ) ;
}
static void F_13 ( struct V_8 * V_9 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
V_3 = F_3 ( V_1 , V_14 ) ;
V_3 |= V_15 ;
F_1 ( V_1 , V_3 , V_14 ) ;
F_1 ( V_1 , 1 , V_17 ) ;
F_1 ( V_1 , 1 , V_18 ) ;
F_1 ( V_1 , 1 , V_19 ) ;
F_1 ( V_1 , 0 , V_19 ) ;
F_7 ( V_1 , 1 , V_20 ) ;
}
static void F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_10 ( V_9 ) ;
F_7 ( V_1 , 0 , V_20 ) ;
F_7 ( V_1 , 1 , V_21 ) ;
}
static void F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_10 ( V_9 ) ;
F_7 ( V_1 , 0 , V_21 ) ;
F_1 ( V_1 , 1 , V_16 ) ;
F_7 ( V_1 , 0 , V_22 ) ;
F_7 ( V_1 , 0 , V_23 ) ;
F_7 ( V_1 , 0 , V_24 ) ;
F_7 ( V_1 , 0 , V_25 ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_10 ( V_9 ) ;
F_5 ( V_1 , 0x29 , V_26 ) ;
F_5 ( V_1 , 0xd5 , V_27 ) ;
F_5 ( V_1 , 0x14 , V_28 ) ;
F_5 ( V_1 , 0x12 , V_29 ) ;
F_5 ( V_1 , 0x7f , V_30 ) ;
F_5 ( V_1 , 0x0 , V_31 ) ;
F_5 ( V_1 , 0xe7 , V_32 ) ;
F_5 ( V_1 , 0x82 , V_33 ) ;
F_5 ( V_1 , 0x82 , V_34 ) ;
F_5 ( V_1 , 0x82 , V_35 ) ;
F_5 ( V_1 , 0x82 , V_36 ) ;
F_5 ( V_1 , 0x39 , V_31 ) ;
F_5 ( V_1 , 0x39 , V_37 ) ;
F_5 ( V_1 , 0x39 , V_38 ) ;
F_5 ( V_1 , 0x39 , V_39 ) ;
F_5 ( V_1 , 0x20 , V_40 ) ;
F_5 ( V_1 , 0xa0 , V_41 ) ;
F_5 ( V_1 , 0xa0 , V_42 ) ;
F_5 ( V_1 , 0xa0 , V_43 ) ;
}
static void F_17 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_10 ( V_9 ) ;
if ( V_1 -> V_44 >= 0 )
F_18 ( V_9 -> V_45 , V_1 -> V_44 ,
V_46 , L_1 ) ;
return;
}
static int F_19 ( struct V_8 * V_9 )
{
T_1 V_3 ;
int V_47 = 0 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
if ( F_20 ( V_9 ) ) {
F_21 ( V_9 -> V_45 , L_2 ) ;
return 0 ;
}
F_12 ( V_9 ) ;
F_14 ( V_9 ) ;
F_15 ( V_9 ) ;
F_16 ( V_9 ) ;
F_7 ( V_1 , 1 , V_22 ) ;
F_22 ( 500 ) ;
F_7 ( V_1 , 0 , V_22 ) ;
F_13 ( V_9 ) ;
F_23 ( V_9 ) ;
F_17 ( V_9 ) ;
F_1 ( V_1 , V_48 ,
V_49 ) ;
while ( ! F_20 ( V_9 ) ) {
F_24 ( 100 ) ;
V_47 ++ ;
if ( V_47 == 10 ) {
while ( F_6 ( V_1 ,
V_50 ) == 0 ) {
V_3 = F_8 ( V_1 ,
V_50 ) ;
F_25 ( V_9 -> V_45 , L_3 , V_3 ) ;
}
F_21 ( V_9 -> V_45 , L_4 ) ;
return - V_51 ;
}
}
F_25 ( V_9 -> V_45 , L_5 ) ;
return 0 ;
}
static void F_26 ( struct V_8 * V_9 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
V_3 = F_3 ( V_1 , V_52 ) ;
F_1 ( V_1 , V_3 , V_52 ) ;
return;
}
static void F_27 ( struct V_8 * V_9 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
V_3 = V_53 | V_54 |
V_55 | V_56 ,
F_1 ( V_1 , V_3 , V_57 ) ;
return;
}
static T_2 F_28 ( int V_58 , void * V_59 )
{
struct V_8 * V_9 = V_59 ;
F_26 ( V_9 ) ;
return V_60 ;
}
static void F_29 ( struct V_8 * V_9 )
{
F_27 ( V_9 ) ;
return;
}
static inline void F_30 ( struct V_8 * V_9 ,
void T_3 * V_61 , T_1 * V_3 )
{
F_11 ( V_9 , true ) ;
* V_3 = F_4 ( V_61 ) ;
F_11 ( V_9 , false ) ;
return;
}
static inline void F_31 ( struct V_8 * V_9 ,
T_1 V_3 , void T_3 * V_61 )
{
F_9 ( V_9 , true ) ;
F_2 ( V_3 , V_61 ) ;
F_9 ( V_9 , false ) ;
return;
}
static int F_32 ( struct V_8 * V_9 , int V_62 , int V_63 ,
T_1 * V_3 )
{
int V_64 ;
F_11 ( V_9 , true ) ;
V_64 = F_33 ( V_9 -> V_61 + ( V_62 & ~ 0x3 ) , V_62 , V_63 , V_3 ) ;
F_11 ( V_9 , false ) ;
return V_64 ;
}
static int F_34 ( struct V_8 * V_9 , int V_62 , int V_63 ,
T_1 V_3 )
{
int V_64 ;
F_9 ( V_9 , true ) ;
V_64 = F_35 ( V_9 -> V_61 + ( V_62 & ~ 0x3 ) , V_62 , V_63 , V_3 ) ;
F_9 ( V_9 , false ) ;
return V_64 ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_10 ( V_9 ) ;
T_1 V_3 = F_3 ( V_1 , V_65 ) ;
if ( V_3 == V_48 )
return 1 ;
return 0 ;
}
static void F_37 ( struct V_8 * V_9 )
{
F_19 ( V_9 ) ;
F_29 ( V_9 ) ;
}
static int F_38 ( struct V_8 * V_9 , struct V_66 * V_67 )
{
int V_64 ;
V_9 -> V_58 = F_39 ( V_67 , 1 ) ;
if ( ! V_9 -> V_58 ) {
F_21 ( & V_67 -> V_45 , L_6 ) ;
return - V_68 ;
}
V_64 = F_40 ( & V_67 -> V_45 , V_9 -> V_58 , F_28 ,
V_69 , L_7 , V_9 ) ;
if ( V_64 ) {
F_21 ( & V_67 -> V_45 , L_8 ) ;
return V_64 ;
}
V_9 -> V_70 = - 1 ;
V_9 -> V_71 = & V_72 ;
F_41 ( & V_9 -> V_73 ) ;
V_64 = F_42 ( V_9 ) ;
if ( V_64 ) {
F_21 ( & V_67 -> V_45 , L_9 ) ;
return V_64 ;
}
return 0 ;
}
static int T_4 F_43 ( struct V_66 * V_67 )
{
struct V_1 * V_1 ;
struct V_8 * V_9 ;
struct V_74 * V_75 = V_67 -> V_45 . V_76 ;
struct V_77 * V_5 ;
struct V_77 * V_6 ;
struct V_77 * V_7 ;
int V_64 ;
V_1 = F_44 ( & V_67 -> V_45 , sizeof( * V_1 ) ,
V_78 ) ;
if ( ! V_1 ) {
F_21 ( & V_67 -> V_45 , L_10 ) ;
return - V_79 ;
}
V_9 = & V_1 -> V_9 ;
V_9 -> V_45 = & V_67 -> V_45 ;
V_1 -> V_44 = F_45 ( V_75 , L_11 , 0 ) ;
V_1 -> V_80 = F_46 ( & V_67 -> V_45 , L_12 ) ;
if ( F_47 ( V_1 -> V_80 ) ) {
F_21 ( & V_67 -> V_45 , L_13 ) ;
return F_48 ( V_1 -> V_80 ) ;
}
V_64 = F_49 ( V_1 -> V_80 ) ;
if ( V_64 )
return V_64 ;
V_1 -> V_81 = F_46 ( & V_67 -> V_45 , L_14 ) ;
if ( F_47 ( V_1 -> V_81 ) ) {
F_21 ( & V_67 -> V_45 , L_15 ) ;
V_64 = F_48 ( V_1 -> V_81 ) ;
goto V_82;
}
V_64 = F_49 ( V_1 -> V_81 ) ;
if ( V_64 )
goto V_82;
V_5 = F_50 ( V_67 , V_83 , 0 ) ;
V_1 -> V_5 = F_51 ( & V_67 -> V_45 , V_5 ) ;
if ( F_47 ( V_1 -> V_5 ) )
return F_48 ( V_1 -> V_5 ) ;
V_6 = F_50 ( V_67 , V_83 , 1 ) ;
V_1 -> V_6 = F_51 ( & V_67 -> V_45 , V_6 ) ;
if ( F_47 ( V_1 -> V_6 ) )
return F_48 ( V_1 -> V_6 ) ;
V_7 = F_50 ( V_67 , V_83 , 2 ) ;
V_1 -> V_7 = F_51 ( & V_67 -> V_45 , V_7 ) ;
if ( F_47 ( V_1 -> V_7 ) )
return F_48 ( V_1 -> V_7 ) ;
V_64 = F_38 ( V_9 , V_67 ) ;
if ( V_64 < 0 )
goto V_84;
F_52 ( V_67 , V_1 ) ;
return 0 ;
V_84:
F_53 ( V_1 -> V_81 ) ;
V_82:
F_53 ( V_1 -> V_80 ) ;
return V_64 ;
}
static int T_5 F_54 ( struct V_66 * V_67 )
{
struct V_1 * V_1 = F_55 ( V_67 ) ;
F_53 ( V_1 -> V_81 ) ;
F_53 ( V_1 -> V_80 ) ;
return 0 ;
}
static int T_4 F_56 ( void )
{
return F_57 ( & V_85 , F_43 ) ;
}
