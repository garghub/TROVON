static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_8 ;
V_8 = F_4 ( V_7 -> V_9 + V_10 ) ;
V_8 &= ~ V_3 ;
V_8 |= V_4 ;
F_5 ( V_8 , V_7 -> V_9 + V_10 ) ;
}
static void F_6 ( struct V_1 * V_1 , T_1 V_11 )
{
if ( V_11 )
V_11 = V_12 ;
else
V_11 = V_13 ;
F_1 ( V_1 , V_14 , V_11 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_11 )
{
if ( V_11 )
V_11 = V_15 ;
else
V_11 = V_16 ;
F_1 ( V_1 , V_17 , V_11 ) ;
}
static void F_8 ( struct V_5 * V_1 , T_1 V_18 , T_1 V_7 ,
int V_19 )
{
struct V_6 * V_20 = F_3 ( V_1 ) ;
T_1 V_21 , V_22 = F_9 ( V_1 -> V_23 * 2 ) ;
void T_2 * V_24 = V_20 -> V_9 + V_20 -> V_25 -> V_26 ;
unsigned long V_27 ;
int V_28 ;
F_10 ( & V_20 -> V_29 , V_27 ) ;
if ( V_20 -> V_25 -> type == V_30 ||
V_20 -> V_25 -> type == V_31 ) {
F_5 ( 0 , V_24 ) ;
}
for ( V_28 = 0 ; V_28 < V_19 ; V_28 ++ ) {
V_21 = F_4 ( V_24 ) ;
V_21 &= ~ ( 0xff << 8 ) ;
V_21 |= ( ( V_18 + V_28 ) << 8 ) ;
F_5 ( V_21 , V_24 ) ;
V_21 = F_11 ( V_24 ) ;
if ( V_7 & 0x1 )
V_21 |= V_32 ;
else
V_21 &= ~ V_32 ;
V_21 &= ~ V_22 ;
F_12 ( V_21 , V_24 ) ;
V_21 = F_11 ( V_24 ) ;
V_21 |= V_22 ;
F_12 ( V_21 , V_24 ) ;
V_21 = F_11 ( V_24 ) ;
V_21 &= ~ V_22 ;
F_12 ( V_21 , V_24 ) ;
V_7 >>= 1 ;
}
F_13 ( & V_20 -> V_29 , V_27 ) ;
}
static void F_14 ( struct V_5 * V_1 , int V_33 )
{
T_1 V_34 , V_35 ;
if ( ! V_1 -> V_36 )
return;
V_34 = V_37 | V_38 |
V_39 | V_40 ;
V_35 = F_4 ( V_1 -> V_36 ) ;
if ( V_33 )
V_35 |= V_34 ;
else
V_35 &= ~ V_34 ;
F_5 ( V_35 , V_1 -> V_36 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_41 ;
T_1 V_11 ;
V_41 = F_16 ( V_1 -> V_42 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_17 ( V_1 -> V_43 ) ;
if ( V_41 ) {
F_18 ( V_1 -> V_42 ) ;
return V_41 ;
}
if ( V_1 -> V_36 && V_7 -> V_25 -> V_44 ) {
V_11 = F_4 ( V_1 -> V_36 + V_45 ) ;
F_5 ( V_11 & ~ 2 , V_1 -> V_36 + V_45 ) ;
}
if ( V_7 -> V_25 -> type == V_46 ) {
if ( V_1 -> V_23 == 0 ) {
V_11 = F_4 ( V_7 -> V_9 + V_47 ) ;
F_5 ( V_11 & ~ 1 , V_7 -> V_9 + V_47 ) ;
}
} else {
if ( V_1 -> V_23 == 0 )
F_8 ( V_1 , V_48 , 0x01 , 1 ) ;
F_8 ( V_1 , V_49 , 0x14 , 5 ) ;
F_8 ( V_1 , V_50 ,
V_7 -> V_25 -> V_51 , 2 ) ;
}
F_14 ( V_1 , 1 ) ;
if ( V_1 -> V_23 == 0 ) {
V_7 -> V_52 = true ;
F_1 ( V_2 , 0 , V_53 ) ;
F_1 ( V_2 , 0 , V_54 ) ;
V_7 -> V_55 = - 1 ;
V_7 -> V_56 = - 1 ;
F_19 ( V_57 , & V_7 -> V_58 , 0 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( V_1 -> V_23 == 0 ) {
F_1 ( V_2 , V_53 , 0 ) ;
F_1 ( V_2 , V_54 , 0 ) ;
V_7 -> V_52 = false ;
}
F_14 ( V_1 , 0 ) ;
F_21 ( V_1 -> V_43 ) ;
F_18 ( V_1 -> V_42 ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_59 ) {
case V_60 :
if ( V_7 -> V_61 )
return F_23 ( V_7 -> V_61 ) ;
else
return 1 ;
case V_62 :
return 0 ;
case V_63 :
default:
return 1 ;
}
}
static int F_24 ( struct V_6 * V_7 )
{
if ( V_7 -> V_64 )
return F_23 ( V_7 -> V_64 ) ;
if ( V_7 -> V_65 ) {
union V_66 V_11 ;
int V_67 ;
V_67 = F_25 ( V_7 -> V_65 ,
V_68 , & V_11 ) ;
if ( V_67 == 0 )
return V_11 . V_69 ;
}
return 1 ;
}
static bool F_26 ( struct V_6 * V_7 )
{
return V_7 -> V_64 || V_7 -> V_65 ;
}
static bool F_27 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_61 && V_7 -> V_70 <= 0 ) ||
( V_7 -> V_64 && V_7 -> V_71 <= 0 ) )
return true ;
if ( V_7 -> V_25 -> type == V_72 &&
V_7 -> V_65 && V_7 -> V_73 [ 0 ] . V_74 )
return true ;
return false ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_41 ;
if ( ! V_1 -> V_75 || V_1 -> V_74 )
return 0 ;
if ( V_1 -> V_23 == 0 && F_26 ( V_7 ) &&
V_7 -> V_56 ) {
F_29 ( & V_2 -> V_76 , L_1 ) ;
return 0 ;
}
V_41 = F_30 ( V_1 -> V_75 ) ;
if ( V_41 )
return V_41 ;
V_1 -> V_74 = true ;
if ( V_1 -> V_23 == 0 && F_27 ( V_7 ) )
F_31 ( V_57 , & V_7 -> V_58 , V_77 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! V_1 -> V_75 || ! V_1 -> V_74 )
return 0 ;
F_33 ( V_1 -> V_75 ) ;
V_1 -> V_74 = false ;
if ( V_1 -> V_23 == 0 && ! F_27 ( V_7 ) )
F_31 ( V_57 , & V_7 -> V_58 , V_78 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , enum V_79 V_80 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( V_1 -> V_23 != 0 )
return - V_81 ;
switch ( V_80 ) {
case V_82 :
V_7 -> V_59 = V_62 ;
break;
case V_83 :
V_7 -> V_59 = V_63 ;
break;
case V_84 :
V_7 -> V_59 = V_60 ;
break;
default:
return - V_81 ;
}
F_35 ( & V_2 -> V_76 , L_2 , ( int ) V_7 -> V_59 ) ;
V_7 -> V_85 = true ;
F_19 ( V_57 , & V_7 -> V_58 , 0 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 , bool V_86 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
F_8 ( V_1 , V_87 , V_86 ? 0 : 2 , 2 ) ;
}
static void F_37 ( struct V_88 * V_89 )
{
struct V_6 * V_7 =
F_38 ( V_89 , struct V_6 , V_58 . V_89 ) ;
struct V_1 * V_90 = V_7 -> V_73 [ 0 ] . V_1 ;
bool V_85 , V_91 = false , V_92 = false ;
int V_55 , V_56 ;
if ( V_90 == NULL )
return;
V_55 = F_22 ( V_7 ) ;
V_56 = F_24 ( V_7 ) ;
F_39 ( & V_90 -> V_93 ) ;
if ( ! V_7 -> V_52 ) {
F_40 ( & V_90 -> V_93 ) ;
return;
}
V_85 = V_7 -> V_85 ;
V_7 -> V_85 = false ;
if ( V_55 != V_7 -> V_55 ) {
if ( V_7 -> V_59 == V_60 &&
! F_26 ( V_7 ) )
V_85 = true ;
if ( V_85 && V_55 == 0 ) {
F_7 ( V_90 , 0 ) ;
F_41 ( 200 ) ;
F_7 ( V_90 , 1 ) ;
}
F_6 ( V_90 , V_55 ) ;
V_7 -> V_55 = V_55 ;
V_91 = true ;
}
if ( V_56 != V_7 -> V_56 ) {
F_7 ( V_90 , V_56 ) ;
V_7 -> V_56 = V_56 ;
V_92 = true ;
}
F_40 ( & V_90 -> V_93 ) ;
if ( V_91 ) {
F_42 ( V_7 -> V_94 , V_95 ,
! V_55 ) ;
if ( V_85 && V_55 == 1 ) {
F_39 ( & V_90 -> V_93 ) ;
F_7 ( V_90 , 0 ) ;
F_41 ( 1000 ) ;
F_7 ( V_90 , 1 ) ;
F_40 ( & V_90 -> V_93 ) ;
}
}
if ( V_92 )
F_42 ( V_7 -> V_94 , V_96 , V_56 ) ;
if ( F_27 ( V_7 ) )
F_19 ( V_57 , & V_7 -> V_58 , V_78 ) ;
}
static T_3 F_43 ( int V_97 , void * V_98 )
{
struct V_6 * V_7 = V_98 ;
F_31 ( V_57 , & V_7 -> V_58 , V_77 ) ;
return V_99 ;
}
static int F_44 ( struct V_100 * V_101 ,
unsigned long V_11 , void * V_102 )
{
struct V_6 * V_7 =
F_38 ( V_101 , struct V_6 , V_103 ) ;
struct V_104 * V_105 = V_102 ;
if ( V_11 == V_106 && V_105 == V_7 -> V_65 )
F_31 ( V_57 , & V_7 -> V_58 , V_77 ) ;
return V_107 ;
}
static struct V_1 * F_45 ( struct V_108 * V_76 ,
struct V_109 * args )
{
struct V_6 * V_7 = F_46 ( V_76 ) ;
if ( args -> args [ 0 ] >= V_7 -> V_25 -> V_110 )
return F_47 ( - V_111 ) ;
return V_7 -> V_73 [ args -> args [ 0 ] ] . V_1 ;
}
static int F_48 ( struct V_112 * V_113 )
{
struct V_108 * V_76 = & V_113 -> V_76 ;
struct V_6 * V_7 = F_46 ( V_76 ) ;
if ( V_7 -> V_114 )
F_49 ( & V_7 -> V_103 ) ;
if ( V_7 -> V_70 > 0 )
F_50 ( V_76 , V_7 -> V_70 , V_7 ) ;
if ( V_7 -> V_71 > 0 )
F_50 ( V_76 , V_7 -> V_71 , V_7 ) ;
F_51 ( & V_7 -> V_58 ) ;
return 0 ;
}
static int F_52 ( struct V_112 * V_113 )
{
struct V_6 * V_7 ;
struct V_108 * V_76 = & V_113 -> V_76 ;
struct V_115 * V_116 = V_76 -> V_117 ;
struct V_118 * V_118 ;
struct V_119 * V_120 ;
int V_28 , V_41 ;
V_7 = F_53 ( V_76 , sizeof( * V_7 ) , V_121 ) ;
if ( ! V_7 )
return - V_122 ;
F_54 ( & V_7 -> V_29 ) ;
F_55 ( & V_7 -> V_58 , F_37 ) ;
F_56 ( V_76 , V_7 ) ;
V_7 -> V_25 = F_57 ( V_76 ) ;
if ( ! V_7 -> V_25 )
return - V_81 ;
V_120 = F_58 ( V_113 , V_123 , L_3 ) ;
V_7 -> V_9 = F_59 ( V_76 , V_120 ) ;
if ( F_60 ( V_7 -> V_9 ) )
return F_61 ( V_7 -> V_9 ) ;
V_7 -> V_61 = F_62 ( V_76 , L_4 ,
V_124 ) ;
if ( F_60 ( V_7 -> V_61 ) )
return F_61 ( V_7 -> V_61 ) ;
V_7 -> V_64 = F_62 ( V_76 , L_5 ,
V_124 ) ;
if ( F_60 ( V_7 -> V_64 ) )
return F_61 ( V_7 -> V_64 ) ;
if ( F_63 ( V_116 , L_6 , NULL ) ) {
V_7 -> V_65 = F_64 ( V_76 ,
L_6 ) ;
if ( F_60 ( V_7 -> V_65 ) )
return F_61 ( V_7 -> V_65 ) ;
if ( ! V_7 -> V_65 )
return - V_125 ;
}
V_7 -> V_59 = F_65 ( V_116 , 0 ) ;
V_7 -> V_94 = F_66 ( V_76 , V_126 ) ;
if ( F_60 ( V_7 -> V_94 ) )
return F_61 ( V_7 -> V_94 ) ;
V_41 = F_67 ( V_76 , V_7 -> V_94 ) ;
if ( V_41 ) {
F_68 ( V_76 , L_7 , V_41 ) ;
return V_41 ;
}
for ( V_28 = 0 ; V_28 < V_7 -> V_25 -> V_110 ; V_28 ++ ) {
struct V_5 * V_1 = V_7 -> V_73 + V_28 ;
char V_127 [ 16 ] ;
snprintf ( V_127 , sizeof( V_127 ) , L_8 , V_28 ) ;
V_1 -> V_75 = F_69 ( V_76 , V_127 ) ;
if ( F_60 ( V_1 -> V_75 ) ) {
if ( F_61 ( V_1 -> V_75 ) == - V_125 )
return - V_125 ;
V_1 -> V_75 = NULL ;
}
if ( V_7 -> V_25 -> V_128 )
snprintf ( V_127 , sizeof( V_127 ) , L_9 , V_28 ) ;
else
F_70 ( V_127 , L_10 , sizeof( V_127 ) ) ;
V_1 -> V_42 = F_71 ( V_76 , V_127 ) ;
if ( F_60 ( V_1 -> V_42 ) ) {
F_68 ( V_76 , L_11 , V_127 ) ;
return F_61 ( V_1 -> V_42 ) ;
}
snprintf ( V_127 , sizeof( V_127 ) , L_12 , V_28 ) ;
V_1 -> V_43 = F_72 ( V_76 , V_127 ) ;
if ( F_60 ( V_1 -> V_43 ) ) {
F_68 ( V_76 , L_13 , V_127 ) ;
return F_61 ( V_1 -> V_43 ) ;
}
if ( V_28 ) {
snprintf ( V_127 , sizeof( V_127 ) , L_14 , V_28 ) ;
V_120 = F_58 ( V_113 ,
V_123 , V_127 ) ;
V_1 -> V_36 = F_59 ( V_76 , V_120 ) ;
if ( F_60 ( V_1 -> V_36 ) )
return F_61 ( V_1 -> V_36 ) ;
}
V_1 -> V_1 = F_73 ( V_76 , NULL , & V_129 ) ;
if ( F_60 ( V_1 -> V_1 ) ) {
F_68 ( V_76 , L_15 , V_28 ) ;
return F_61 ( V_1 -> V_1 ) ;
}
V_1 -> V_23 = V_28 ;
F_74 ( V_1 -> V_1 , & V_7 -> V_73 [ V_28 ] ) ;
}
V_7 -> V_70 = F_75 ( V_7 -> V_61 ) ;
if ( V_7 -> V_70 > 0 ) {
V_41 = F_76 ( V_76 , V_7 -> V_70 ,
F_43 ,
V_130 | V_131 ,
L_16 , V_7 ) ;
if ( V_41 ) {
F_68 ( V_76 , L_17 , V_41 ) ;
return V_41 ;
}
}
V_7 -> V_71 = F_75 ( V_7 -> V_64 ) ;
if ( V_7 -> V_71 > 0 ) {
V_41 = F_76 ( V_76 , V_7 -> V_71 ,
F_43 ,
V_130 | V_131 ,
L_18 , V_7 ) ;
if ( V_41 ) {
F_68 ( V_76 , L_19 , V_41 ) ;
V_7 -> V_71 = - 1 ;
F_48 ( V_113 ) ;
return V_41 ;
}
}
if ( V_7 -> V_65 ) {
V_7 -> V_103 . V_132 = F_44 ;
V_7 -> V_103 . V_133 = 0 ;
V_41 = F_77 ( & V_7 -> V_103 ) ;
if ( V_41 ) {
F_48 ( V_113 ) ;
return V_41 ;
}
V_7 -> V_114 = true ;
}
V_118 = F_78 ( V_76 , F_45 ) ;
if ( F_60 ( V_118 ) ) {
F_48 ( V_113 ) ;
return F_61 ( V_118 ) ;
}
return 0 ;
}
