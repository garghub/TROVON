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
V_20 -> V_25 -> type == V_31 ||
V_20 -> V_25 -> type == V_32 ) {
F_5 ( 0 , V_24 ) ;
}
for ( V_28 = 0 ; V_28 < V_19 ; V_28 ++ ) {
V_21 = F_4 ( V_24 ) ;
V_21 &= ~ ( 0xff << 8 ) ;
V_21 |= ( ( V_18 + V_28 ) << 8 ) ;
F_5 ( V_21 , V_24 ) ;
V_21 = F_11 ( V_24 ) ;
if ( V_7 & 0x1 )
V_21 |= V_33 ;
else
V_21 &= ~ V_33 ;
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
static void F_14 ( struct V_5 * V_1 , int V_34 )
{
T_1 V_35 , V_36 ;
if ( ! V_1 -> V_37 )
return;
V_35 = V_38 | V_39 |
V_40 | V_41 ;
V_36 = F_4 ( V_1 -> V_37 ) ;
if ( V_34 )
V_36 |= V_35 ;
else
V_36 &= ~ V_35 ;
F_5 ( V_36 , V_1 -> V_37 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_42 ;
T_1 V_11 ;
V_42 = F_16 ( V_1 -> V_43 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_17 ( V_1 -> V_44 ) ;
if ( V_42 ) {
F_18 ( V_1 -> V_43 ) ;
return V_42 ;
}
if ( V_1 -> V_37 && V_7 -> V_25 -> V_45 ) {
V_11 = F_4 ( V_1 -> V_37 + V_46 ) ;
F_5 ( V_11 & ~ 2 , V_1 -> V_37 + V_46 ) ;
}
if ( V_7 -> V_25 -> type == V_47 ) {
if ( V_1 -> V_23 == 0 ) {
V_11 = F_4 ( V_7 -> V_9 + V_48 ) ;
F_5 ( V_11 & ~ 1 , V_7 -> V_9 + V_48 ) ;
}
} else {
if ( V_1 -> V_23 == 0 )
F_8 ( V_1 , V_49 , 0x01 , 1 ) ;
F_8 ( V_1 , V_50 , 0x14 , 5 ) ;
F_8 ( V_1 , V_51 ,
V_7 -> V_25 -> V_52 , 2 ) ;
}
F_14 ( V_1 , 1 ) ;
if ( V_1 -> V_23 == 0 ) {
V_7 -> V_53 = true ;
F_1 ( V_2 , 0 , V_54 ) ;
F_1 ( V_2 , 0 , V_55 ) ;
V_7 -> V_56 = - 1 ;
V_7 -> V_57 = - 1 ;
F_19 ( V_58 , & V_7 -> V_59 , 0 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( V_1 -> V_23 == 0 ) {
F_1 ( V_2 , V_54 , 0 ) ;
F_1 ( V_2 , V_55 , 0 ) ;
V_7 -> V_53 = false ;
}
F_14 ( V_1 , 0 ) ;
F_21 ( V_1 -> V_44 ) ;
F_18 ( V_1 -> V_43 ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_60 ) {
case V_61 :
if ( V_7 -> V_62 )
return F_23 ( V_7 -> V_62 ) ;
else
return 1 ;
case V_63 :
return 0 ;
case V_64 :
default:
return 1 ;
}
}
static int F_24 ( struct V_6 * V_7 )
{
if ( V_7 -> V_65 )
return F_23 ( V_7 -> V_65 ) ;
if ( V_7 -> V_66 ) {
union V_67 V_11 ;
int V_68 ;
V_68 = F_25 ( V_7 -> V_66 ,
V_69 , & V_11 ) ;
if ( V_68 == 0 )
return V_11 . V_70 ;
}
return 1 ;
}
static bool F_26 ( struct V_6 * V_7 )
{
return V_7 -> V_65 || V_7 -> V_66 ;
}
static bool F_27 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_62 && V_7 -> V_71 <= 0 ) ||
( V_7 -> V_65 && V_7 -> V_72 <= 0 ) )
return true ;
if ( V_7 -> V_25 -> type == V_73 &&
V_7 -> V_66 && V_7 -> V_74 [ 0 ] . V_75 )
return true ;
return false ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_42 ;
if ( ! V_1 -> V_76 || V_1 -> V_75 )
return 0 ;
if ( V_1 -> V_23 == 0 && F_26 ( V_7 ) &&
V_7 -> V_57 ) {
F_29 ( & V_2 -> V_77 , L_1 ) ;
return 0 ;
}
V_42 = F_30 ( V_1 -> V_76 ) ;
if ( V_42 )
return V_42 ;
V_1 -> V_75 = true ;
if ( V_1 -> V_23 == 0 && F_27 ( V_7 ) )
F_31 ( V_58 , & V_7 -> V_59 , V_78 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! V_1 -> V_76 || ! V_1 -> V_75 )
return 0 ;
F_33 ( V_1 -> V_76 ) ;
V_1 -> V_75 = false ;
if ( V_1 -> V_23 == 0 && ! F_27 ( V_7 ) )
F_31 ( V_58 , & V_7 -> V_59 , V_79 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , enum V_80 V_81 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_82 ;
if ( V_1 -> V_23 != 0 )
return - V_83 ;
switch ( V_81 ) {
case V_84 :
V_82 = V_63 ;
break;
case V_85 :
V_82 = V_64 ;
break;
case V_86 :
V_82 = V_61 ;
break;
default:
return - V_83 ;
}
if ( V_82 != V_7 -> V_60 ) {
F_35 ( & V_2 -> V_77 , L_2 , V_82 ) ;
V_7 -> V_60 = V_82 ;
}
V_7 -> V_56 = - 1 ;
V_7 -> V_87 = true ;
F_19 ( V_58 , & V_7 -> V_59 , 0 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 , bool V_88 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
F_8 ( V_1 , V_89 , V_88 ? 0 : 2 , 2 ) ;
}
static void F_37 ( struct V_90 * V_91 )
{
struct V_6 * V_7 =
F_38 ( V_91 , struct V_6 , V_59 . V_91 ) ;
struct V_1 * V_92 = V_7 -> V_74 [ 0 ] . V_1 ;
bool V_87 , V_93 = false , V_94 = false ;
int V_56 , V_57 ;
if ( V_92 == NULL )
return;
V_56 = F_22 ( V_7 ) ;
V_57 = F_24 ( V_7 ) ;
F_39 ( & V_92 -> V_95 ) ;
if ( ! V_7 -> V_53 ) {
F_40 ( & V_92 -> V_95 ) ;
return;
}
V_87 = V_7 -> V_87 ;
V_7 -> V_87 = false ;
if ( V_56 != V_7 -> V_56 ) {
if ( V_7 -> V_60 == V_61 &&
! F_26 ( V_7 ) )
V_87 = true ;
if ( V_87 && V_56 == 0 ) {
F_7 ( V_92 , 0 ) ;
F_41 ( 200 ) ;
F_7 ( V_92 , 1 ) ;
}
F_6 ( V_92 , V_56 ) ;
V_7 -> V_56 = V_56 ;
V_93 = true ;
}
if ( V_57 != V_7 -> V_57 ) {
F_7 ( V_92 , V_57 ) ;
V_7 -> V_57 = V_57 ;
V_94 = true ;
}
F_40 ( & V_92 -> V_95 ) ;
if ( V_93 ) {
F_42 ( V_7 -> V_96 , V_97 ,
! V_56 ) ;
if ( V_87 && V_56 == 1 ) {
F_39 ( & V_92 -> V_95 ) ;
F_7 ( V_92 , 0 ) ;
F_41 ( 1000 ) ;
F_7 ( V_92 , 1 ) ;
F_40 ( & V_92 -> V_95 ) ;
}
}
if ( V_94 )
F_42 ( V_7 -> V_96 , V_98 , V_57 ) ;
if ( F_27 ( V_7 ) )
F_19 ( V_58 , & V_7 -> V_59 , V_79 ) ;
}
static T_3 F_43 ( int V_99 , void * V_100 )
{
struct V_6 * V_7 = V_100 ;
F_31 ( V_58 , & V_7 -> V_59 , V_78 ) ;
return V_101 ;
}
static int F_44 ( struct V_102 * V_103 ,
unsigned long V_11 , void * V_104 )
{
struct V_6 * V_7 =
F_38 ( V_103 , struct V_6 , V_105 ) ;
struct V_106 * V_107 = V_104 ;
if ( V_11 == V_108 && V_107 == V_7 -> V_66 )
F_31 ( V_58 , & V_7 -> V_59 , V_78 ) ;
return V_109 ;
}
static struct V_1 * F_45 ( struct V_110 * V_77 ,
struct V_111 * args )
{
struct V_6 * V_7 = F_46 ( V_77 ) ;
if ( args -> args [ 0 ] >= V_7 -> V_25 -> V_112 )
return F_47 ( - V_113 ) ;
return V_7 -> V_74 [ args -> args [ 0 ] ] . V_1 ;
}
static int F_48 ( struct V_114 * V_115 )
{
struct V_110 * V_77 = & V_115 -> V_77 ;
struct V_6 * V_7 = F_46 ( V_77 ) ;
if ( V_7 -> V_116 )
F_49 ( & V_7 -> V_105 ) ;
if ( V_7 -> V_71 > 0 )
F_50 ( V_77 , V_7 -> V_71 , V_7 ) ;
if ( V_7 -> V_72 > 0 )
F_50 ( V_77 , V_7 -> V_72 , V_7 ) ;
F_51 ( & V_7 -> V_59 ) ;
return 0 ;
}
static int F_52 ( struct V_114 * V_115 )
{
struct V_6 * V_7 ;
struct V_110 * V_77 = & V_115 -> V_77 ;
struct V_117 * V_118 = V_77 -> V_119 ;
struct V_120 * V_120 ;
struct V_121 * V_122 ;
int V_28 , V_42 ;
V_7 = F_53 ( V_77 , sizeof( * V_7 ) , V_123 ) ;
if ( ! V_7 )
return - V_124 ;
F_54 ( & V_7 -> V_29 ) ;
F_55 ( & V_7 -> V_59 , F_37 ) ;
F_56 ( V_77 , V_7 ) ;
V_7 -> V_25 = F_57 ( V_77 ) ;
if ( ! V_7 -> V_25 )
return - V_83 ;
V_122 = F_58 ( V_115 , V_125 , L_3 ) ;
V_7 -> V_9 = F_59 ( V_77 , V_122 ) ;
if ( F_60 ( V_7 -> V_9 ) )
return F_61 ( V_7 -> V_9 ) ;
V_7 -> V_62 = F_62 ( V_77 , L_4 ,
V_126 ) ;
if ( F_60 ( V_7 -> V_62 ) )
return F_61 ( V_7 -> V_62 ) ;
V_7 -> V_65 = F_62 ( V_77 , L_5 ,
V_126 ) ;
if ( F_60 ( V_7 -> V_65 ) )
return F_61 ( V_7 -> V_65 ) ;
if ( F_63 ( V_118 , L_6 , NULL ) ) {
V_7 -> V_66 = F_64 ( V_77 ,
L_6 ) ;
if ( F_60 ( V_7 -> V_66 ) )
return F_61 ( V_7 -> V_66 ) ;
if ( ! V_7 -> V_66 )
return - V_127 ;
}
V_7 -> V_60 = F_65 ( V_118 , 0 ) ;
V_7 -> V_96 = F_66 ( V_77 , V_128 ) ;
if ( F_60 ( V_7 -> V_96 ) )
return F_61 ( V_7 -> V_96 ) ;
V_42 = F_67 ( V_77 , V_7 -> V_96 ) ;
if ( V_42 ) {
F_68 ( V_77 , L_7 , V_42 ) ;
return V_42 ;
}
for ( V_28 = 0 ; V_28 < V_7 -> V_25 -> V_112 ; V_28 ++ ) {
struct V_5 * V_1 = V_7 -> V_74 + V_28 ;
char V_129 [ 16 ] ;
snprintf ( V_129 , sizeof( V_129 ) , L_8 , V_28 ) ;
V_1 -> V_76 = F_69 ( V_77 , V_129 ) ;
if ( F_60 ( V_1 -> V_76 ) ) {
if ( F_61 ( V_1 -> V_76 ) == - V_127 )
return - V_127 ;
V_1 -> V_76 = NULL ;
}
if ( V_7 -> V_25 -> V_130 )
snprintf ( V_129 , sizeof( V_129 ) , L_9 , V_28 ) ;
else
F_70 ( V_129 , L_10 , sizeof( V_129 ) ) ;
V_1 -> V_43 = F_71 ( V_77 , V_129 ) ;
if ( F_60 ( V_1 -> V_43 ) ) {
F_68 ( V_77 , L_11 , V_129 ) ;
return F_61 ( V_1 -> V_43 ) ;
}
snprintf ( V_129 , sizeof( V_129 ) , L_12 , V_28 ) ;
V_1 -> V_44 = F_72 ( V_77 , V_129 ) ;
if ( F_60 ( V_1 -> V_44 ) ) {
F_68 ( V_77 , L_13 , V_129 ) ;
return F_61 ( V_1 -> V_44 ) ;
}
if ( V_28 ) {
snprintf ( V_129 , sizeof( V_129 ) , L_14 , V_28 ) ;
V_122 = F_58 ( V_115 ,
V_125 , V_129 ) ;
V_1 -> V_37 = F_59 ( V_77 , V_122 ) ;
if ( F_60 ( V_1 -> V_37 ) )
return F_61 ( V_1 -> V_37 ) ;
}
V_1 -> V_1 = F_73 ( V_77 , NULL , & V_131 ) ;
if ( F_60 ( V_1 -> V_1 ) ) {
F_68 ( V_77 , L_15 , V_28 ) ;
return F_61 ( V_1 -> V_1 ) ;
}
V_1 -> V_23 = V_28 ;
F_74 ( V_1 -> V_1 , & V_7 -> V_74 [ V_28 ] ) ;
}
V_7 -> V_71 = F_75 ( V_7 -> V_62 ) ;
if ( V_7 -> V_71 > 0 ) {
V_42 = F_76 ( V_77 , V_7 -> V_71 ,
F_43 ,
V_132 | V_133 ,
L_16 , V_7 ) ;
if ( V_42 ) {
F_68 ( V_77 , L_17 , V_42 ) ;
return V_42 ;
}
}
V_7 -> V_72 = F_75 ( V_7 -> V_65 ) ;
if ( V_7 -> V_72 > 0 ) {
V_42 = F_76 ( V_77 , V_7 -> V_72 ,
F_43 ,
V_132 | V_133 ,
L_18 , V_7 ) ;
if ( V_42 ) {
F_68 ( V_77 , L_19 , V_42 ) ;
V_7 -> V_72 = - 1 ;
F_48 ( V_115 ) ;
return V_42 ;
}
}
if ( V_7 -> V_66 ) {
V_7 -> V_105 . V_134 = F_44 ;
V_7 -> V_105 . V_135 = 0 ;
V_42 = F_77 ( & V_7 -> V_105 ) ;
if ( V_42 ) {
F_48 ( V_115 ) ;
return V_42 ;
}
V_7 -> V_116 = true ;
}
V_120 = F_78 ( V_77 , F_45 ) ;
if ( F_60 ( V_120 ) ) {
F_48 ( V_115 ) ;
return F_61 ( V_120 ) ;
}
return 0 ;
}
