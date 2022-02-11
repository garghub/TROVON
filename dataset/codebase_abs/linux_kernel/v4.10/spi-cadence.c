static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_6 = V_7 ;
if ( V_2 -> V_8 )
V_6 |= V_9 ;
F_3 ( V_2 , V_10 , V_11 ) ;
F_3 ( V_2 , V_12 , V_13 ) ;
while ( F_1 ( V_2 , V_14 ) & V_15 )
F_1 ( V_2 , V_16 ) ;
F_3 ( V_2 , V_14 , V_13 ) ;
F_3 ( V_2 , V_17 , V_6 ) ;
F_3 ( V_2 , V_10 , V_18 ) ;
}
static void F_6 ( struct V_19 * V_20 , bool V_21 )
{
struct V_1 * V_2 = F_7 ( V_20 -> V_22 ) ;
T_1 V_6 ;
V_6 = F_1 ( V_2 , V_17 ) ;
if ( V_21 ) {
V_6 |= V_23 ;
} else {
V_6 &= ~ V_23 ;
if ( ! ( V_2 -> V_8 ) )
V_6 |= ( ( ~ ( V_24 << V_20 -> V_25 ) ) <<
V_26 ) &
V_23 ;
else
V_6 |= ( V_20 -> V_25 << V_26 ) &
V_23 ;
}
F_3 ( V_2 , V_17 , V_6 ) ;
}
static void F_8 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_20 -> V_22 ) ;
T_1 V_6 , V_27 ;
V_27 = F_1 ( V_2 , V_17 ) ;
V_6 = V_27 ;
V_27 &= ~ ( V_28 | V_29 ) ;
if ( V_20 -> V_30 & V_31 )
V_27 |= V_28 ;
if ( V_20 -> V_30 & V_32 )
V_27 |= V_29 ;
if ( V_27 != V_6 ) {
F_3 ( V_2 , V_10 , V_11 ) ;
F_3 ( V_2 , V_17 , V_27 ) ;
F_3 ( V_2 , V_10 , V_18 ) ;
}
}
static void F_9 ( struct V_19 * V_20 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_7 ( V_20 -> V_22 ) ;
T_1 V_6 , V_35 ;
unsigned long V_36 ;
V_36 = F_10 ( V_2 -> V_37 ) ;
V_6 = F_1 ( V_2 , V_17 ) ;
if ( V_2 -> V_38 != V_34 -> V_38 ) {
V_35 = V_39 ;
while ( ( V_35 < V_40 ) &&
( V_36 / ( 2 << V_35 ) ) > V_34 -> V_38 )
V_35 ++ ;
V_6 &= ~ V_41 ;
V_6 |= V_35 << V_42 ;
V_2 -> V_38 = V_36 / ( 2 << V_35 ) ;
}
F_3 ( V_2 , V_17 , V_6 ) ;
}
static int F_11 ( struct V_19 * V_20 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_7 ( V_20 -> V_22 ) ;
F_9 ( V_20 , V_34 ) ;
F_12 ( & V_20 -> V_43 , L_1 ,
V_44 , V_20 -> V_30 , V_20 -> V_45 ,
V_2 -> V_38 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_46 = 0 ;
while ( ( V_46 < V_47 ) &&
( V_2 -> V_48 > 0 ) ) {
if ( V_2 -> V_49 )
F_3 ( V_2 , V_50 , * V_2 -> V_49 ++ ) ;
else
F_3 ( V_2 , V_50 , 0 ) ;
V_2 -> V_48 -- ;
V_46 ++ ;
}
}
static T_2 F_14 ( int V_51 , void * V_52 )
{
struct V_53 * V_22 = V_52 ;
struct V_1 * V_2 = F_7 ( V_22 ) ;
T_1 V_54 , V_55 ;
V_55 = V_56 ;
V_54 = F_1 ( V_2 , V_14 ) ;
F_3 ( V_2 , V_14 , V_54 ) ;
if ( V_54 & V_57 ) {
F_3 ( V_2 , V_12 , V_58 ) ;
F_15 ( V_22 ) ;
V_55 = V_59 ;
} else if ( V_54 & V_60 ) {
unsigned long V_46 ;
V_46 = V_2 -> V_61 - V_2 -> V_48 ;
while ( V_46 ) {
T_3 V_62 ;
V_62 = F_1 ( V_2 , V_16 ) ;
if ( V_2 -> V_63 )
* V_2 -> V_63 ++ = V_62 ;
V_2 -> V_61 -- ;
V_46 -- ;
}
if ( V_2 -> V_48 ) {
F_13 ( V_2 ) ;
} else {
F_3 ( V_2 , V_12 ,
V_58 ) ;
F_15 ( V_22 ) ;
}
V_55 = V_59 ;
}
return V_55 ;
}
static int F_16 ( struct V_53 * V_22 ,
struct V_64 * V_65 )
{
F_8 ( V_65 -> V_20 ) ;
return 0 ;
}
static int F_17 ( struct V_53 * V_22 ,
struct V_19 * V_20 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
V_2 -> V_49 = V_34 -> V_66 ;
V_2 -> V_63 = V_34 -> V_67 ;
V_2 -> V_48 = V_34 -> V_68 ;
V_2 -> V_61 = V_34 -> V_68 ;
F_11 ( V_20 , V_34 ) ;
F_13 ( V_2 ) ;
F_3 ( V_2 , V_69 , V_58 ) ;
return V_34 -> V_68 ;
}
static int F_18 ( struct V_53 * V_22 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
F_3 ( V_2 , V_10 , V_18 ) ;
return 0 ;
}
static int F_19 ( struct V_53 * V_22 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
F_3 ( V_2 , V_10 , V_11 ) ;
return 0 ;
}
static int F_20 ( struct V_70 * V_71 )
{
int V_72 = 0 , V_51 ;
struct V_53 * V_22 ;
struct V_1 * V_2 ;
struct V_73 * V_74 ;
T_1 V_75 ;
V_22 = F_21 ( & V_71 -> V_43 , sizeof( * V_2 ) ) ;
if ( ! V_22 )
return - V_76 ;
V_2 = F_7 ( V_22 ) ;
V_22 -> V_43 . V_77 = V_71 -> V_43 . V_77 ;
F_22 ( V_71 , V_22 ) ;
V_74 = F_23 ( V_71 , V_78 , 0 ) ;
V_2 -> V_4 = F_24 ( & V_71 -> V_43 , V_74 ) ;
if ( F_25 ( V_2 -> V_4 ) ) {
V_72 = F_26 ( V_2 -> V_4 ) ;
goto V_79;
}
V_2 -> V_80 = F_27 ( & V_71 -> V_43 , L_2 ) ;
if ( F_25 ( V_2 -> V_80 ) ) {
F_28 ( & V_71 -> V_43 , L_3 ) ;
V_72 = F_26 ( V_2 -> V_80 ) ;
goto V_79;
}
V_2 -> V_37 = F_27 ( & V_71 -> V_43 , L_4 ) ;
if ( F_25 ( V_2 -> V_37 ) ) {
F_28 ( & V_71 -> V_43 , L_5 ) ;
V_72 = F_26 ( V_2 -> V_37 ) ;
goto V_79;
}
V_72 = F_29 ( V_2 -> V_80 ) ;
if ( V_72 ) {
F_28 ( & V_71 -> V_43 , L_6 ) ;
goto V_79;
}
V_72 = F_29 ( V_2 -> V_37 ) ;
if ( V_72 ) {
F_28 ( & V_71 -> V_43 , L_7 ) ;
goto V_81;
}
F_30 ( & V_71 -> V_43 ) ;
F_31 ( & V_71 -> V_43 ) ;
F_32 ( & V_71 -> V_43 , V_82 ) ;
F_33 ( & V_71 -> V_43 ) ;
V_72 = F_34 ( V_71 -> V_43 . V_77 , L_8 , & V_75 ) ;
if ( V_72 < 0 )
V_22 -> V_83 = V_84 ;
else
V_22 -> V_83 = V_75 ;
V_72 = F_34 ( V_71 -> V_43 . V_77 , L_9 ,
& V_2 -> V_8 ) ;
if ( V_72 < 0 )
V_2 -> V_8 = 0 ;
F_5 ( V_2 ) ;
F_35 ( & V_71 -> V_43 ) ;
F_36 ( & V_71 -> V_43 ) ;
V_51 = F_37 ( V_71 , 0 ) ;
if ( V_51 <= 0 ) {
V_72 = - V_85 ;
F_28 ( & V_71 -> V_43 , L_10 ) ;
goto V_86;
}
V_72 = F_38 ( & V_71 -> V_43 , V_51 , F_14 ,
0 , V_71 -> V_87 , V_22 ) ;
if ( V_72 != 0 ) {
V_72 = - V_85 ;
F_28 ( & V_71 -> V_43 , L_11 ) ;
goto V_86;
}
V_22 -> V_88 = F_18 ;
V_22 -> V_89 = F_16 ;
V_22 -> V_90 = F_17 ;
V_22 -> V_91 = F_19 ;
V_22 -> V_92 = F_6 ;
V_22 -> V_93 = true ;
V_22 -> V_94 = V_32 | V_31 ;
V_22 -> V_95 = F_10 ( V_2 -> V_37 ) / 4 ;
V_2 -> V_38 = V_22 -> V_95 ;
V_22 -> V_96 = F_39 ( 8 ) ;
V_72 = F_40 ( V_22 ) ;
if ( V_72 ) {
F_28 ( & V_71 -> V_43 , L_12 ) ;
goto V_86;
}
return V_72 ;
V_86:
F_41 ( & V_71 -> V_43 ) ;
F_42 ( & V_71 -> V_43 ) ;
F_43 ( V_2 -> V_37 ) ;
V_81:
F_43 ( V_2 -> V_80 ) ;
V_79:
F_44 ( V_22 ) ;
return V_72 ;
}
static int F_45 ( struct V_70 * V_71 )
{
struct V_53 * V_22 = F_46 ( V_71 ) ;
struct V_1 * V_2 = F_7 ( V_22 ) ;
F_3 ( V_2 , V_10 , V_11 ) ;
F_43 ( V_2 -> V_37 ) ;
F_43 ( V_2 -> V_80 ) ;
F_41 ( & V_71 -> V_43 ) ;
F_42 ( & V_71 -> V_43 ) ;
F_47 ( V_22 ) ;
return 0 ;
}
static int T_4 F_48 ( struct V_97 * V_43 )
{
struct V_70 * V_71 = F_49 ( V_43 ) ;
struct V_53 * V_22 = F_46 ( V_71 ) ;
return F_50 ( V_22 ) ;
}
static int T_4 F_51 ( struct V_97 * V_43 )
{
struct V_70 * V_71 = F_49 ( V_43 ) ;
struct V_53 * V_22 = F_46 ( V_71 ) ;
return F_52 ( V_22 ) ;
}
static int T_4 F_53 ( struct V_97 * V_43 )
{
struct V_53 * V_22 = F_54 ( V_43 ) ;
struct V_1 * V_2 = F_7 ( V_22 ) ;
int V_72 ;
V_72 = F_29 ( V_2 -> V_80 ) ;
if ( V_72 ) {
F_28 ( V_43 , L_13 ) ;
return V_72 ;
}
V_72 = F_29 ( V_2 -> V_37 ) ;
if ( V_72 ) {
F_28 ( V_43 , L_14 ) ;
F_55 ( V_2 -> V_80 ) ;
return V_72 ;
}
return 0 ;
}
static int T_4 F_56 ( struct V_97 * V_43 )
{
struct V_53 * V_22 = F_54 ( V_43 ) ;
struct V_1 * V_2 = F_7 ( V_22 ) ;
F_43 ( V_2 -> V_37 ) ;
F_43 ( V_2 -> V_80 ) ;
return 0 ;
}
