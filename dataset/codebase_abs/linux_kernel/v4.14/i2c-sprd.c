static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 = F_4 ( V_2 -> V_4 + V_8 ) ;
if ( V_6 )
F_2 ( V_7 & ~ V_9 , V_2 -> V_4 + V_8 ) ;
else
F_2 ( V_7 | V_9 , V_2 -> V_4 + V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_7 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_2 ( V_7 & ~ V_10 , V_2 -> V_4 + V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_7 = F_4 ( V_2 -> V_4 + V_11 ) ;
F_2 ( V_7 & ~ V_12 , V_2 -> V_4 + V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_7 = F_4 ( V_2 -> V_4 + V_11 ) ;
F_2 ( V_7 & ~ V_13 , V_2 -> V_4 + V_11 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_2 ( V_14 , V_2 -> V_4 + V_15 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
F_2 ( V_17 -> V_18 << 1 , V_2 -> V_4 + V_19 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_2 * V_20 , T_1 V_21 )
{
T_1 V_22 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ )
F_11 ( V_20 [ V_22 ] , V_2 -> V_4 + V_23 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_2 * V_20 , T_1 V_21 )
{
T_1 V_22 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ )
V_20 [ V_22 ] = F_13 ( V_2 -> V_4 + V_24 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_25 )
{
T_1 V_7 = F_4 ( V_2 -> V_4 + V_8 ) ;
V_7 &= ~ V_26 ;
V_7 |= V_25 << V_27 ;
F_2 ( V_7 , V_2 -> V_4 + V_8 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_7 = F_4 ( V_2 -> V_4 + V_8 ) ;
V_7 &= ~ V_29 ;
V_7 |= V_28 << V_30 ;
F_2 ( V_7 , V_2 -> V_4 + V_8 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_31 )
{
T_1 V_7 = F_4 ( V_2 -> V_4 + V_8 ) ;
if ( V_31 )
V_7 |= V_32 ;
else
V_7 &= ~ V_32 ;
F_2 ( V_7 , V_2 -> V_4 + V_8 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_31 )
{
T_1 V_7 = F_4 ( V_2 -> V_4 + V_8 ) ;
if ( V_31 )
V_7 |= V_33 ;
else
V_7 &= ~ V_33 ;
F_2 ( V_7 , V_2 -> V_4 + V_8 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_7 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_2 ( V_7 | V_10 , V_2 -> V_4 + V_8 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_34 )
{
T_1 V_35 = F_4 ( V_2 -> V_4 + V_8 ) & ~ V_36 ;
F_2 ( V_35 | V_34 << 3 , V_2 -> V_4 + V_8 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_37 = V_2 -> V_3 ;
T_1 V_38 = V_37 <= V_39 ? V_37 : V_39 ;
struct V_16 * V_40 = V_2 -> V_40 ;
if ( V_40 -> V_41 & V_42 ) {
F_12 ( V_2 , V_2 -> V_20 , V_43 ) ;
V_2 -> V_3 -= V_43 ;
V_2 -> V_20 += V_43 ;
if ( V_2 -> V_3 >= V_43 )
F_16 ( V_2 , 1 ) ;
} else {
F_10 ( V_2 , V_2 -> V_20 , V_38 ) ;
V_2 -> V_20 += V_38 ;
V_2 -> V_3 -= V_38 ;
if ( V_37 > V_39 )
F_17 ( V_2 , 1 ) ;
}
}
static int F_21 ( struct V_44 * V_45 ,
struct V_16 * V_40 , bool V_46 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_20 = V_40 -> V_20 ;
V_2 -> V_3 = V_40 -> V_21 ;
F_22 ( & V_2 -> V_48 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 , V_40 ) ;
F_1 ( V_2 , V_40 -> V_21 ) ;
if ( V_40 -> V_41 & V_42 ) {
F_19 ( V_2 , 1 ) ;
F_3 ( V_2 , 1 ) ;
} else {
F_19 ( V_2 , 0 ) ;
F_3 ( V_2 , ! ! V_46 ) ;
}
if ( V_40 -> V_41 & V_42 )
F_16 ( V_2 , 1 ) ;
else
F_20 ( V_2 ) ;
F_18 ( V_2 ) ;
F_23 ( & V_2 -> V_48 ) ;
return V_2 -> V_49 ;
}
static int F_24 ( struct V_44 * V_45 ,
struct V_16 * V_50 , int V_51 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
int V_52 , V_53 ;
V_53 = F_25 ( V_2 -> V_54 ) ;
if ( V_53 < 0 )
return V_53 ;
for ( V_52 = 0 ; V_52 < V_51 - 1 ; V_52 ++ ) {
V_53 = F_21 ( V_45 , & V_50 [ V_52 ] , 0 ) ;
if ( V_53 )
goto V_55;
}
V_53 = F_21 ( V_45 , & V_50 [ V_52 ++ ] , 1 ) ;
V_55:
F_26 ( V_2 -> V_54 ) ;
F_27 ( V_2 -> V_54 ) ;
return V_53 < 0 ? V_53 : V_52 ;
}
static T_1 F_28 ( struct V_44 * V_56 )
{
return V_57 | V_58 ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_59 )
{
T_1 V_60 = V_2 -> V_61 ;
T_1 V_62 = V_60 / ( 4 * V_59 ) - 1 ;
T_1 V_63 = ( ( V_62 << 1 ) * 2 ) / 5 ;
T_1 V_64 = ( ( V_62 << 1 ) * 3 ) / 5 ;
T_1 V_65 = F_30 ( V_63 , V_64 ) ;
T_1 V_66 = F_31 ( V_63 , V_64 ) ;
F_2 ( V_65 , V_2 -> V_4 + V_67 ) ;
F_2 ( V_66 , V_2 -> V_4 + V_68 ) ;
if ( V_59 == 400000 )
F_2 ( ( 6 * V_60 ) / 10000000 , V_2 -> V_4 + V_69 ) ;
else if ( V_59 == 100000 )
F_2 ( ( 4 * V_60 ) / 1000000 , V_2 -> V_4 + V_69 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_7 = V_70 ;
F_2 ( V_7 , V_2 -> V_4 + V_8 ) ;
F_14 ( V_2 , V_43 ) ;
F_15 ( V_2 , V_71 ) ;
F_29 ( V_2 , V_2 -> V_72 ) ;
F_8 ( V_2 ) ;
F_7 ( V_2 ) ;
V_7 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_2 ( V_7 | V_73 | V_74 , V_2 -> V_4 + V_8 ) ;
}
static T_3 F_33 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
struct V_16 * V_40 = V_2 -> V_40 ;
bool V_77 = ! ( F_4 ( V_2 -> V_4 + V_11 ) & V_12 ) ;
T_1 V_37 = F_4 ( V_2 -> V_4 + V_5 ) ;
T_1 V_78 ;
if ( V_40 -> V_41 & V_42 )
V_78 = V_2 -> V_3 >= V_43 ;
else
V_78 = V_37 ;
if ( V_78 && V_77 ) {
F_20 ( V_2 ) ;
return V_79 ;
}
V_2 -> V_49 = 0 ;
if ( ! V_77 )
V_2 -> V_49 = - V_80 ;
else if ( V_40 -> V_41 & V_42 && V_2 -> V_3 )
F_12 ( V_2 , V_2 -> V_20 , V_2 -> V_3 ) ;
F_6 ( V_2 ) ;
F_5 ( V_2 ) ;
V_48 ( & V_2 -> V_48 ) ;
return V_79 ;
}
static T_3 F_34 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
struct V_16 * V_40 = V_2 -> V_40 ;
T_1 V_37 = F_4 ( V_2 -> V_4 + V_5 ) ;
bool V_77 = ! ( F_4 ( V_2 -> V_4 + V_11 ) & V_12 ) ;
T_1 V_78 ;
if ( V_40 -> V_41 & V_42 )
V_78 = V_2 -> V_3 >= V_43 ;
else
V_78 = V_37 ;
if ( ! V_78 || ! V_77 ) {
F_5 ( V_2 ) ;
F_7 ( V_2 ) ;
}
F_17 ( V_2 , 0 ) ;
F_16 ( V_2 , 0 ) ;
return V_81 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_82 * V_83 , * V_84 ;
V_83 = F_36 ( V_2 -> V_54 , L_1 ) ;
if ( F_37 ( V_83 ) ) {
F_38 ( V_2 -> V_54 , L_2 ,
V_2 -> V_56 . V_85 ) ;
V_83 = NULL ;
}
V_84 = F_36 ( V_2 -> V_54 , L_3 ) ;
if ( F_37 ( V_84 ) ) {
F_38 ( V_2 -> V_54 , L_4 ,
V_2 -> V_56 . V_85 ) ;
V_84 = NULL ;
}
if ( F_39 ( V_83 , V_84 ) )
V_2 -> V_61 = F_40 ( V_83 ) ;
else
V_2 -> V_61 = 26000000 ;
F_41 ( V_2 -> V_54 , L_5 ,
V_2 -> V_56 . V_85 , V_2 -> V_61 ) ;
V_2 -> V_82 = F_36 ( V_2 -> V_54 , L_6 ) ;
if ( F_37 ( V_2 -> V_82 ) ) {
F_38 ( V_2 -> V_54 , L_7 ,
V_2 -> V_56 . V_85 ) ;
V_2 -> V_82 = NULL ;
}
return 0 ;
}
static int F_42 ( struct V_86 * V_87 )
{
struct V_88 * V_54 = & V_87 -> V_54 ;
struct V_1 * V_2 ;
struct V_89 * V_90 ;
T_1 V_91 ;
int V_53 ;
V_87 -> V_92 = F_43 ( V_54 -> V_93 , L_1 ) ;
V_2 = F_44 ( V_54 , sizeof( struct V_1 ) , V_94 ) ;
if ( ! V_2 )
return - V_95 ;
V_90 = F_45 ( V_87 , V_96 , 0 ) ;
V_2 -> V_4 = F_46 ( V_54 , V_90 ) ;
if ( F_37 ( V_2 -> V_4 ) )
return F_47 ( V_2 -> V_4 ) ;
V_2 -> V_75 = F_48 ( V_87 , 0 ) ;
if ( V_2 -> V_75 < 0 ) {
F_49 ( & V_87 -> V_54 , L_8 ) ;
return V_2 -> V_75 ;
}
F_50 ( & V_2 -> V_56 , V_2 ) ;
F_51 ( & V_2 -> V_48 ) ;
snprintf ( V_2 -> V_56 . V_97 , sizeof( V_2 -> V_56 . V_97 ) ,
L_9 , L_10 ) ;
V_2 -> V_72 = 100000 ;
V_2 -> V_56 . V_98 = V_99 ;
V_2 -> V_54 = V_54 ;
V_2 -> V_56 . V_100 = 3 ;
V_2 -> V_56 . V_101 = & V_102 ;
V_2 -> V_56 . V_47 = V_2 ;
V_2 -> V_56 . V_54 . V_103 = V_54 ;
V_2 -> V_56 . V_85 = V_87 -> V_92 ;
V_2 -> V_56 . V_54 . V_93 = V_54 -> V_93 ;
if ( ! F_52 ( V_54 -> V_93 , L_11 , & V_91 ) )
V_2 -> V_72 = V_91 ;
if ( V_2 -> V_72 != 100000 && V_2 -> V_72 != 400000 )
return - V_104 ;
F_35 ( V_2 ) ;
F_53 ( V_87 , V_2 ) ;
V_53 = F_54 ( V_2 -> V_82 ) ;
if ( V_53 )
return V_53 ;
F_32 ( V_2 ) ;
F_55 ( V_2 -> V_54 , V_105 ) ;
F_56 ( V_2 -> V_54 ) ;
F_57 ( V_2 -> V_54 ) ;
F_58 ( V_2 -> V_54 ) ;
V_53 = F_25 ( V_2 -> V_54 ) ;
if ( V_53 < 0 )
goto V_106;
V_53 = F_59 ( V_54 , V_2 -> V_75 ,
F_34 , F_33 ,
V_107 | V_108 ,
V_87 -> V_97 , V_2 ) ;
if ( V_53 ) {
F_49 ( & V_87 -> V_54 , L_12 , V_2 -> V_75 ) ;
goto V_106;
}
V_53 = F_60 ( & V_2 -> V_56 ) ;
if ( V_53 ) {
F_49 ( & V_87 -> V_54 , L_13 ) ;
goto V_106;
}
F_26 ( V_2 -> V_54 ) ;
F_27 ( V_2 -> V_54 ) ;
return 0 ;
V_106:
F_61 ( V_2 -> V_54 ) ;
F_62 ( V_2 -> V_54 ) ;
F_63 ( V_2 -> V_82 ) ;
return V_53 ;
}
static int F_64 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_65 ( V_87 ) ;
int V_53 ;
V_53 = F_25 ( V_2 -> V_54 ) ;
if ( V_53 < 0 )
return V_53 ;
F_66 ( & V_2 -> V_56 ) ;
F_63 ( V_2 -> V_82 ) ;
F_61 ( V_2 -> V_54 ) ;
F_62 ( V_2 -> V_54 ) ;
return 0 ;
}
static int T_4 F_67 ( struct V_88 * V_87 )
{
return F_68 ( V_87 ) ;
}
static int T_4 F_69 ( struct V_88 * V_87 )
{
return F_70 ( V_87 ) ;
}
static int T_4 F_71 ( struct V_88 * V_87 )
{
struct V_1 * V_2 = F_72 ( V_87 ) ;
F_63 ( V_2 -> V_82 ) ;
return 0 ;
}
static int T_4 F_73 ( struct V_88 * V_87 )
{
struct V_1 * V_2 = F_72 ( V_87 ) ;
int V_53 ;
V_53 = F_54 ( V_2 -> V_82 ) ;
if ( V_53 )
return V_53 ;
F_32 ( V_2 ) ;
return 0 ;
}
static int F_74 ( void )
{
return F_75 ( & V_109 ) ;
}
