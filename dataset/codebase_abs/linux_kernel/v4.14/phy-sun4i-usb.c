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
if ( V_20 -> V_25 -> V_26 == V_30 ) {
F_5 ( 0 , V_24 ) ;
}
for ( V_28 = 0 ; V_28 < V_19 ; V_28 ++ ) {
V_21 = F_4 ( V_24 ) ;
V_21 &= ~ ( 0xff << 8 ) ;
V_21 |= ( ( V_18 + V_28 ) << 8 ) ;
F_5 ( V_21 , V_24 ) ;
V_21 = F_11 ( V_24 ) ;
if ( V_7 & 0x1 )
V_21 |= V_31 ;
else
V_21 &= ~ V_31 ;
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
static void F_14 ( struct V_5 * V_1 , int V_32 )
{
struct V_6 * V_20 = F_3 ( V_1 ) ;
T_1 V_33 , V_34 ;
if ( ! V_1 -> V_35 )
return;
V_33 = V_36 | V_37 |
V_38 | V_39 ;
if ( V_20 -> V_25 -> type == V_40 && V_1 -> V_23 == 2 )
V_33 |= V_41 | V_42 |
V_43 ;
V_34 = F_4 ( V_1 -> V_35 ) ;
if ( V_32 )
V_34 |= V_33 ;
else
V_34 &= ~ V_33 ;
F_5 ( V_34 , V_1 -> V_35 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_44 ;
T_1 V_11 ;
V_44 = F_16 ( V_1 -> V_45 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_16 ( V_1 -> V_46 ) ;
if ( V_44 ) {
F_17 ( V_1 -> V_45 ) ;
return V_44 ;
}
V_44 = F_18 ( V_1 -> V_47 ) ;
if ( V_44 ) {
F_17 ( V_1 -> V_46 ) ;
F_17 ( V_1 -> V_45 ) ;
return V_44 ;
}
if ( V_7 -> V_25 -> type == V_40 ) {
if ( V_1 -> V_23 == 0 ) {
V_11 = F_4 ( V_7 -> V_9 + V_7 -> V_25 -> V_26 ) ;
V_11 |= V_48 ;
V_11 &= ~ V_49 ;
F_5 ( V_11 , V_7 -> V_9 + V_7 -> V_25 -> V_26 ) ;
}
} else {
if ( V_1 -> V_35 && V_7 -> V_25 -> V_50 ) {
V_11 = F_4 ( V_1 -> V_35 + V_51 ) ;
F_5 ( V_11 & ~ 2 , V_1 -> V_35 + V_51 ) ;
}
if ( V_1 -> V_23 == 0 )
F_8 ( V_1 , V_52 , 0x01 , 1 ) ;
F_8 ( V_1 , V_53 , 0x14 , 5 ) ;
F_8 ( V_1 , V_54 ,
V_7 -> V_25 -> V_55 , 2 ) ;
}
F_14 ( V_1 , 1 ) ;
if ( V_1 -> V_23 == 0 ) {
V_7 -> V_56 = true ;
F_1 ( V_2 , 0 , V_57 ) ;
F_1 ( V_2 , 0 , V_58 ) ;
V_7 -> V_59 = - 1 ;
V_7 -> V_60 = - 1 ;
F_19 ( V_61 , & V_7 -> V_62 , 0 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( V_1 -> V_23 == 0 ) {
if ( V_7 -> V_25 -> type == V_40 ) {
void T_2 * V_24 = V_7 -> V_9 +
V_7 -> V_25 -> V_26 ;
F_5 ( F_4 ( V_24 ) | V_49 , V_24 ) ;
}
F_1 ( V_2 , V_57 , 0 ) ;
F_1 ( V_2 , V_58 , 0 ) ;
V_7 -> V_56 = false ;
}
F_14 ( V_1 , 0 ) ;
F_21 ( V_1 -> V_47 ) ;
F_17 ( V_1 -> V_46 ) ;
F_17 ( V_1 -> V_45 ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_63 ) {
case V_64 :
if ( V_7 -> V_65 )
return F_23 ( V_7 -> V_65 ) ;
else
return 1 ;
case V_66 :
return 0 ;
case V_67 :
default:
return 1 ;
}
}
static int F_24 ( struct V_6 * V_7 )
{
if ( V_7 -> V_68 )
return F_23 ( V_7 -> V_68 ) ;
if ( V_7 -> V_69 ) {
union V_70 V_11 ;
int V_71 ;
V_71 = F_25 ( V_7 -> V_69 ,
V_72 , & V_11 ) ;
if ( V_71 == 0 )
return V_11 . V_73 ;
}
return 1 ;
}
static bool F_26 ( struct V_6 * V_7 )
{
return V_7 -> V_68 || V_7 -> V_69 ;
}
static bool F_27 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_65 && V_7 -> V_74 <= 0 ) ||
( V_7 -> V_68 && V_7 -> V_75 <= 0 ) )
return true ;
if ( V_7 -> V_25 -> type == V_76 &&
V_7 -> V_69 && V_7 -> V_77 [ 0 ] . V_78 )
return true ;
return false ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_44 ;
if ( ! V_1 -> V_79 || V_1 -> V_78 )
return 0 ;
if ( V_1 -> V_23 == 0 && F_26 ( V_7 ) &&
V_7 -> V_60 ) {
F_29 ( & V_2 -> V_80 , L_1 ) ;
return 0 ;
}
V_44 = F_30 ( V_1 -> V_79 ) ;
if ( V_44 )
return V_44 ;
V_1 -> V_78 = true ;
if ( V_1 -> V_23 == 0 && F_27 ( V_7 ) )
F_31 ( V_61 , & V_7 -> V_62 , V_81 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! V_1 -> V_79 || ! V_1 -> V_78 )
return 0 ;
F_33 ( V_1 -> V_79 ) ;
V_1 -> V_78 = false ;
if ( V_1 -> V_23 == 0 && ! F_27 ( V_7 ) )
F_31 ( V_61 , & V_7 -> V_62 , V_82 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , enum V_83 V_84 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_85 ;
if ( V_1 -> V_23 != 0 )
return - V_86 ;
switch ( V_84 ) {
case V_87 :
V_85 = V_66 ;
break;
case V_88 :
V_85 = V_67 ;
break;
case V_89 :
V_85 = V_64 ;
break;
default:
return - V_86 ;
}
if ( V_85 != V_7 -> V_63 ) {
F_35 ( & V_2 -> V_80 , L_2 , V_85 ) ;
V_7 -> V_63 = V_85 ;
}
V_7 -> V_59 = - 1 ;
V_7 -> V_90 = true ;
F_19 ( V_61 , & V_7 -> V_62 , 0 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 , bool V_91 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
F_8 ( V_1 , V_92 , V_91 ? 0 : 2 , 2 ) ;
}
static void F_37 ( struct V_6 * V_7 , int V_59 )
{
T_1 V_93 ;
V_93 = F_4 ( V_7 -> V_9 + V_94 ) ;
if ( V_59 == 0 ) {
V_93 &= ~ V_95 ;
} else {
V_93 |= V_95 ;
}
F_5 ( V_93 , V_7 -> V_9 + V_94 ) ;
}
static void F_38 ( struct V_96 * V_97 )
{
struct V_6 * V_7 =
F_39 ( V_97 , struct V_6 , V_62 . V_97 ) ;
struct V_1 * V_98 = V_7 -> V_77 [ 0 ] . V_1 ;
bool V_90 , V_99 = false , V_100 = false ;
int V_59 , V_60 ;
if ( V_98 == NULL )
return;
V_59 = F_22 ( V_7 ) ;
V_60 = F_24 ( V_7 ) ;
F_40 ( & V_98 -> V_101 ) ;
if ( ! V_7 -> V_56 ) {
F_41 ( & V_98 -> V_101 ) ;
return;
}
V_90 = V_7 -> V_90 ;
V_7 -> V_90 = false ;
if ( V_59 != V_7 -> V_59 ) {
if ( V_7 -> V_63 == V_64 &&
! F_26 ( V_7 ) )
V_90 = true ;
if ( V_90 && V_59 == 0 ) {
F_7 ( V_98 , 0 ) ;
F_42 ( 200 ) ;
F_7 ( V_98 , 1 ) ;
}
F_6 ( V_98 , V_59 ) ;
V_7 -> V_59 = V_59 ;
V_99 = true ;
}
if ( V_60 != V_7 -> V_60 ) {
F_7 ( V_98 , V_60 ) ;
V_7 -> V_60 = V_60 ;
V_100 = true ;
}
F_41 ( & V_98 -> V_101 ) ;
if ( V_99 ) {
F_43 ( V_7 -> V_102 , V_103 ,
! V_59 ) ;
if ( V_90 && V_59 == 1 ) {
F_40 ( & V_98 -> V_101 ) ;
F_7 ( V_98 , 0 ) ;
F_42 ( 1000 ) ;
F_7 ( V_98 , 1 ) ;
F_41 ( & V_98 -> V_101 ) ;
}
if ( V_7 -> V_25 -> V_104 )
F_37 ( V_7 , V_59 ) ;
}
if ( V_100 )
F_43 ( V_7 -> V_102 , V_105 , V_60 ) ;
if ( F_27 ( V_7 ) )
F_19 ( V_61 , & V_7 -> V_62 , V_82 ) ;
}
static T_3 F_44 ( int V_106 , void * V_107 )
{
struct V_6 * V_7 = V_107 ;
F_31 ( V_61 , & V_7 -> V_62 , V_81 ) ;
return V_108 ;
}
static int F_45 ( struct V_109 * V_110 ,
unsigned long V_11 , void * V_111 )
{
struct V_6 * V_7 =
F_39 ( V_110 , struct V_6 , V_112 ) ;
struct V_113 * V_114 = V_111 ;
if ( V_11 == V_115 && V_114 == V_7 -> V_69 )
F_31 ( V_61 , & V_7 -> V_62 , V_81 ) ;
return V_116 ;
}
static struct V_1 * F_46 ( struct V_117 * V_80 ,
struct V_118 * args )
{
struct V_6 * V_7 = F_47 ( V_80 ) ;
if ( args -> args [ 0 ] >= V_7 -> V_25 -> V_119 )
return F_48 ( - V_120 ) ;
return V_7 -> V_77 [ args -> args [ 0 ] ] . V_1 ;
}
static int F_49 ( struct V_121 * V_122 )
{
struct V_117 * V_80 = & V_122 -> V_80 ;
struct V_6 * V_7 = F_47 ( V_80 ) ;
if ( V_7 -> V_123 )
F_50 ( & V_7 -> V_112 ) ;
if ( V_7 -> V_74 > 0 )
F_51 ( V_80 , V_7 -> V_74 , V_7 ) ;
if ( V_7 -> V_75 > 0 )
F_51 ( V_80 , V_7 -> V_75 , V_7 ) ;
F_52 ( & V_7 -> V_62 ) ;
return 0 ;
}
static int F_53 ( struct V_121 * V_122 )
{
struct V_6 * V_7 ;
struct V_117 * V_80 = & V_122 -> V_80 ;
struct V_124 * V_125 = V_80 -> V_126 ;
struct V_127 * V_127 ;
struct V_128 * V_129 ;
int V_28 , V_44 ;
V_7 = F_54 ( V_80 , sizeof( * V_7 ) , V_130 ) ;
if ( ! V_7 )
return - V_131 ;
F_55 ( & V_7 -> V_29 ) ;
F_56 ( & V_7 -> V_62 , F_38 ) ;
F_57 ( V_80 , V_7 ) ;
V_7 -> V_25 = F_58 ( V_80 ) ;
if ( ! V_7 -> V_25 )
return - V_86 ;
V_129 = F_59 ( V_122 , V_132 , L_3 ) ;
V_7 -> V_9 = F_60 ( V_80 , V_129 ) ;
if ( F_61 ( V_7 -> V_9 ) )
return F_62 ( V_7 -> V_9 ) ;
V_7 -> V_65 = F_63 ( V_80 , L_4 ,
V_133 ) ;
if ( F_61 ( V_7 -> V_65 ) ) {
F_64 ( V_80 , L_5 ) ;
return F_62 ( V_7 -> V_65 ) ;
}
V_7 -> V_68 = F_63 ( V_80 , L_6 ,
V_133 ) ;
if ( F_61 ( V_7 -> V_68 ) ) {
F_64 ( V_80 , L_7 ) ;
return F_62 ( V_7 -> V_68 ) ;
}
if ( F_65 ( V_125 , L_8 , NULL ) ) {
V_7 -> V_69 = F_66 ( V_80 ,
L_8 ) ;
if ( F_61 ( V_7 -> V_69 ) ) {
F_64 ( V_80 , L_9 ) ;
return F_62 ( V_7 -> V_69 ) ;
}
if ( ! V_7 -> V_69 )
return - V_134 ;
}
V_7 -> V_63 = F_67 ( V_125 , 0 ) ;
V_7 -> V_102 = F_68 ( V_80 , V_135 ) ;
if ( F_61 ( V_7 -> V_102 ) ) {
F_64 ( V_80 , L_10 ) ;
return F_62 ( V_7 -> V_102 ) ;
}
V_44 = F_69 ( V_80 , V_7 -> V_102 ) ;
if ( V_44 ) {
F_64 ( V_80 , L_11 , V_44 ) ;
return V_44 ;
}
for ( V_28 = 0 ; V_28 < V_7 -> V_25 -> V_119 ; V_28 ++ ) {
struct V_5 * V_1 = V_7 -> V_77 + V_28 ;
char V_136 [ 16 ] ;
snprintf ( V_136 , sizeof( V_136 ) , L_12 , V_28 ) ;
V_1 -> V_79 = F_70 ( V_80 , V_136 ) ;
if ( F_61 ( V_1 -> V_79 ) ) {
if ( F_62 ( V_1 -> V_79 ) == - V_134 ) {
F_64 ( V_80 ,
L_13 ,
V_136 ) ;
return - V_134 ;
}
V_1 -> V_79 = NULL ;
}
if ( V_7 -> V_25 -> V_137 )
snprintf ( V_136 , sizeof( V_136 ) , L_14 , V_28 ) ;
else
F_71 ( V_136 , L_15 , sizeof( V_136 ) ) ;
V_1 -> V_45 = F_72 ( V_80 , V_136 ) ;
if ( F_61 ( V_1 -> V_45 ) ) {
F_64 ( V_80 , L_16 , V_136 ) ;
return F_62 ( V_1 -> V_45 ) ;
}
if ( V_7 -> V_25 -> V_138 && V_28 == V_7 -> V_25 -> V_138 ) {
snprintf ( V_136 , sizeof( V_136 ) , L_17 , V_28 ) ;
V_1 -> V_46 = F_72 ( V_80 , V_136 ) ;
if ( F_61 ( V_1 -> V_46 ) ) {
F_64 ( V_80 , L_16 , V_136 ) ;
return F_62 ( V_1 -> V_46 ) ;
}
}
snprintf ( V_136 , sizeof( V_136 ) , L_18 , V_28 ) ;
V_1 -> V_47 = F_73 ( V_80 , V_136 ) ;
if ( F_61 ( V_1 -> V_47 ) ) {
F_64 ( V_80 , L_19 , V_136 ) ;
return F_62 ( V_1 -> V_47 ) ;
}
if ( V_28 || V_7 -> V_25 -> V_104 ) {
snprintf ( V_136 , sizeof( V_136 ) , L_20 , V_28 ) ;
V_129 = F_59 ( V_122 ,
V_132 , V_136 ) ;
V_1 -> V_35 = F_60 ( V_80 , V_129 ) ;
if ( F_61 ( V_1 -> V_35 ) )
return F_62 ( V_1 -> V_35 ) ;
}
V_1 -> V_1 = F_74 ( V_80 , NULL , & V_139 ) ;
if ( F_61 ( V_1 -> V_1 ) ) {
F_64 ( V_80 , L_21 , V_28 ) ;
return F_62 ( V_1 -> V_1 ) ;
}
V_1 -> V_23 = V_28 ;
F_75 ( V_1 -> V_1 , & V_7 -> V_77 [ V_28 ] ) ;
}
V_7 -> V_74 = F_76 ( V_7 -> V_65 ) ;
if ( V_7 -> V_74 > 0 ) {
V_44 = F_77 ( V_80 , V_7 -> V_74 ,
F_44 ,
V_140 | V_141 ,
L_22 , V_7 ) ;
if ( V_44 ) {
F_64 ( V_80 , L_23 , V_44 ) ;
return V_44 ;
}
}
V_7 -> V_75 = F_76 ( V_7 -> V_68 ) ;
if ( V_7 -> V_75 > 0 ) {
V_44 = F_77 ( V_80 , V_7 -> V_75 ,
F_44 ,
V_140 | V_141 ,
L_24 , V_7 ) ;
if ( V_44 ) {
F_64 ( V_80 , L_25 , V_44 ) ;
V_7 -> V_75 = - 1 ;
F_49 ( V_122 ) ;
return V_44 ;
}
}
if ( V_7 -> V_69 ) {
V_7 -> V_112 . V_142 = F_45 ;
V_7 -> V_112 . V_143 = 0 ;
V_44 = F_78 ( & V_7 -> V_112 ) ;
if ( V_44 ) {
F_49 ( V_122 ) ;
return V_44 ;
}
V_7 -> V_123 = true ;
}
V_127 = F_79 ( V_80 , F_46 ) ;
if ( F_61 ( V_127 ) ) {
F_49 ( V_122 ) ;
return F_62 ( V_127 ) ;
}
F_80 ( V_80 , L_26 ) ;
return 0 ;
}
