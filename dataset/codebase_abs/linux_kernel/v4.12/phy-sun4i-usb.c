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
T_1 V_33 , V_34 ;
if ( ! V_1 -> V_35 )
return;
V_33 = V_36 | V_37 |
V_38 | V_39 ;
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
int V_40 ;
T_1 V_11 ;
V_40 = F_16 ( V_1 -> V_41 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_17 ( V_1 -> V_42 ) ;
if ( V_40 ) {
F_18 ( V_1 -> V_41 ) ;
return V_40 ;
}
if ( V_1 -> V_35 && V_7 -> V_25 -> V_43 ) {
V_11 = F_4 ( V_1 -> V_35 + V_44 ) ;
F_5 ( V_11 & ~ 2 , V_1 -> V_35 + V_44 ) ;
}
if ( V_1 -> V_23 == 0 )
F_8 ( V_1 , V_45 , 0x01 , 1 ) ;
F_8 ( V_1 , V_46 , 0x14 , 5 ) ;
F_8 ( V_1 , V_47 ,
V_7 -> V_25 -> V_48 , 2 ) ;
F_14 ( V_1 , 1 ) ;
if ( V_1 -> V_23 == 0 ) {
V_7 -> V_49 = true ;
F_1 ( V_2 , 0 , V_50 ) ;
F_1 ( V_2 , 0 , V_51 ) ;
V_7 -> V_52 = - 1 ;
V_7 -> V_53 = - 1 ;
F_19 ( V_54 , & V_7 -> V_55 , 0 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( V_1 -> V_23 == 0 ) {
F_1 ( V_2 , V_50 , 0 ) ;
F_1 ( V_2 , V_51 , 0 ) ;
V_7 -> V_49 = false ;
}
F_14 ( V_1 , 0 ) ;
F_21 ( V_1 -> V_42 ) ;
F_18 ( V_1 -> V_41 ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_56 ) {
case V_57 :
if ( V_7 -> V_58 )
return F_23 ( V_7 -> V_58 ) ;
else
return 1 ;
case V_59 :
return 0 ;
case V_60 :
default:
return 1 ;
}
}
static int F_24 ( struct V_6 * V_7 )
{
if ( V_7 -> V_61 )
return F_23 ( V_7 -> V_61 ) ;
if ( V_7 -> V_62 ) {
union V_63 V_11 ;
int V_64 ;
V_64 = F_25 ( V_7 -> V_62 ,
V_65 , & V_11 ) ;
if ( V_64 == 0 )
return V_11 . V_66 ;
}
return 1 ;
}
static bool F_26 ( struct V_6 * V_7 )
{
return V_7 -> V_61 || V_7 -> V_62 ;
}
static bool F_27 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_58 && V_7 -> V_67 <= 0 ) ||
( V_7 -> V_61 && V_7 -> V_68 <= 0 ) )
return true ;
if ( V_7 -> V_25 -> type == V_69 &&
V_7 -> V_62 && V_7 -> V_70 [ 0 ] . V_71 )
return true ;
return false ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_40 ;
if ( ! V_1 -> V_72 || V_1 -> V_71 )
return 0 ;
if ( V_1 -> V_23 == 0 && F_26 ( V_7 ) &&
V_7 -> V_53 ) {
F_29 ( & V_2 -> V_73 , L_1 ) ;
return 0 ;
}
V_40 = F_30 ( V_1 -> V_72 ) ;
if ( V_40 )
return V_40 ;
V_1 -> V_71 = true ;
if ( V_1 -> V_23 == 0 && F_27 ( V_7 ) )
F_31 ( V_54 , & V_7 -> V_55 , V_74 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! V_1 -> V_72 || ! V_1 -> V_71 )
return 0 ;
F_33 ( V_1 -> V_72 ) ;
V_1 -> V_71 = false ;
if ( V_1 -> V_23 == 0 && ! F_27 ( V_7 ) )
F_31 ( V_54 , & V_7 -> V_55 , V_75 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , enum V_76 V_77 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_78 ;
if ( V_1 -> V_23 != 0 )
return - V_79 ;
switch ( V_77 ) {
case V_80 :
V_78 = V_59 ;
break;
case V_81 :
V_78 = V_60 ;
break;
case V_82 :
V_78 = V_57 ;
break;
default:
return - V_79 ;
}
if ( V_78 != V_7 -> V_56 ) {
F_35 ( & V_2 -> V_73 , L_2 , V_78 ) ;
V_7 -> V_56 = V_78 ;
}
V_7 -> V_52 = - 1 ;
V_7 -> V_83 = true ;
F_19 ( V_54 , & V_7 -> V_55 , 0 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 , bool V_84 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
F_8 ( V_1 , V_85 , V_84 ? 0 : 2 , 2 ) ;
}
static void F_37 ( struct V_6 * V_7 , int V_52 )
{
T_1 V_86 ;
V_86 = F_4 ( V_7 -> V_9 + V_87 ) ;
if ( V_52 == 0 ) {
V_86 &= ~ V_88 ;
} else {
V_86 |= V_88 ;
}
F_5 ( V_86 , V_7 -> V_9 + V_87 ) ;
}
static void F_38 ( struct V_89 * V_90 )
{
struct V_6 * V_7 =
F_39 ( V_90 , struct V_6 , V_55 . V_90 ) ;
struct V_1 * V_91 = V_7 -> V_70 [ 0 ] . V_1 ;
bool V_83 , V_92 = false , V_93 = false ;
int V_52 , V_53 ;
if ( V_91 == NULL )
return;
V_52 = F_22 ( V_7 ) ;
V_53 = F_24 ( V_7 ) ;
F_40 ( & V_91 -> V_94 ) ;
if ( ! V_7 -> V_49 ) {
F_41 ( & V_91 -> V_94 ) ;
return;
}
V_83 = V_7 -> V_83 ;
V_7 -> V_83 = false ;
if ( V_52 != V_7 -> V_52 ) {
if ( V_7 -> V_56 == V_57 &&
! F_26 ( V_7 ) )
V_83 = true ;
if ( V_83 && V_52 == 0 ) {
F_7 ( V_91 , 0 ) ;
F_42 ( 200 ) ;
F_7 ( V_91 , 1 ) ;
}
F_6 ( V_91 , V_52 ) ;
V_7 -> V_52 = V_52 ;
V_92 = true ;
}
if ( V_53 != V_7 -> V_53 ) {
F_7 ( V_91 , V_53 ) ;
V_7 -> V_53 = V_53 ;
V_93 = true ;
}
F_41 ( & V_91 -> V_94 ) ;
if ( V_92 ) {
F_43 ( V_7 -> V_95 , V_96 ,
! V_52 ) ;
if ( V_83 && V_52 == 1 ) {
F_40 ( & V_91 -> V_94 ) ;
F_7 ( V_91 , 0 ) ;
F_42 ( 1000 ) ;
F_7 ( V_91 , 1 ) ;
F_41 ( & V_91 -> V_94 ) ;
}
if ( V_7 -> V_25 -> V_97 )
F_37 ( V_7 , V_52 ) ;
}
if ( V_93 )
F_43 ( V_7 -> V_95 , V_98 , V_53 ) ;
if ( F_27 ( V_7 ) )
F_19 ( V_54 , & V_7 -> V_55 , V_75 ) ;
}
static T_3 F_44 ( int V_99 , void * V_100 )
{
struct V_6 * V_7 = V_100 ;
F_31 ( V_54 , & V_7 -> V_55 , V_74 ) ;
return V_101 ;
}
static int F_45 ( struct V_102 * V_103 ,
unsigned long V_11 , void * V_104 )
{
struct V_6 * V_7 =
F_39 ( V_103 , struct V_6 , V_105 ) ;
struct V_106 * V_107 = V_104 ;
if ( V_11 == V_108 && V_107 == V_7 -> V_62 )
F_31 ( V_54 , & V_7 -> V_55 , V_74 ) ;
return V_109 ;
}
static struct V_1 * F_46 ( struct V_110 * V_73 ,
struct V_111 * args )
{
struct V_6 * V_7 = F_47 ( V_73 ) ;
if ( args -> args [ 0 ] >= V_7 -> V_25 -> V_112 )
return F_48 ( - V_113 ) ;
return V_7 -> V_70 [ args -> args [ 0 ] ] . V_1 ;
}
static int F_49 ( struct V_114 * V_115 )
{
struct V_110 * V_73 = & V_115 -> V_73 ;
struct V_6 * V_7 = F_47 ( V_73 ) ;
if ( V_7 -> V_116 )
F_50 ( & V_7 -> V_105 ) ;
if ( V_7 -> V_67 > 0 )
F_51 ( V_73 , V_7 -> V_67 , V_7 ) ;
if ( V_7 -> V_68 > 0 )
F_51 ( V_73 , V_7 -> V_68 , V_7 ) ;
F_52 ( & V_7 -> V_55 ) ;
return 0 ;
}
static int F_53 ( struct V_114 * V_115 )
{
struct V_6 * V_7 ;
struct V_110 * V_73 = & V_115 -> V_73 ;
struct V_117 * V_118 = V_73 -> V_119 ;
struct V_120 * V_120 ;
struct V_121 * V_122 ;
int V_28 , V_40 ;
V_7 = F_54 ( V_73 , sizeof( * V_7 ) , V_123 ) ;
if ( ! V_7 )
return - V_124 ;
F_55 ( & V_7 -> V_29 ) ;
F_56 ( & V_7 -> V_55 , F_38 ) ;
F_57 ( V_73 , V_7 ) ;
V_7 -> V_25 = F_58 ( V_73 ) ;
if ( ! V_7 -> V_25 )
return - V_79 ;
V_122 = F_59 ( V_115 , V_125 , L_3 ) ;
V_7 -> V_9 = F_60 ( V_73 , V_122 ) ;
if ( F_61 ( V_7 -> V_9 ) )
return F_62 ( V_7 -> V_9 ) ;
V_7 -> V_58 = F_63 ( V_73 , L_4 ,
V_126 ) ;
if ( F_61 ( V_7 -> V_58 ) )
return F_62 ( V_7 -> V_58 ) ;
V_7 -> V_61 = F_63 ( V_73 , L_5 ,
V_126 ) ;
if ( F_61 ( V_7 -> V_61 ) )
return F_62 ( V_7 -> V_61 ) ;
if ( F_64 ( V_118 , L_6 , NULL ) ) {
V_7 -> V_62 = F_65 ( V_73 ,
L_6 ) ;
if ( F_61 ( V_7 -> V_62 ) )
return F_62 ( V_7 -> V_62 ) ;
if ( ! V_7 -> V_62 )
return - V_127 ;
}
V_7 -> V_56 = F_66 ( V_118 , 0 ) ;
V_7 -> V_95 = F_67 ( V_73 , V_128 ) ;
if ( F_61 ( V_7 -> V_95 ) )
return F_62 ( V_7 -> V_95 ) ;
V_40 = F_68 ( V_73 , V_7 -> V_95 ) ;
if ( V_40 ) {
F_69 ( V_73 , L_7 , V_40 ) ;
return V_40 ;
}
for ( V_28 = 0 ; V_28 < V_7 -> V_25 -> V_112 ; V_28 ++ ) {
struct V_5 * V_1 = V_7 -> V_70 + V_28 ;
char V_129 [ 16 ] ;
snprintf ( V_129 , sizeof( V_129 ) , L_8 , V_28 ) ;
V_1 -> V_72 = F_70 ( V_73 , V_129 ) ;
if ( F_61 ( V_1 -> V_72 ) ) {
if ( F_62 ( V_1 -> V_72 ) == - V_127 )
return - V_127 ;
V_1 -> V_72 = NULL ;
}
if ( V_7 -> V_25 -> V_130 )
snprintf ( V_129 , sizeof( V_129 ) , L_9 , V_28 ) ;
else
F_71 ( V_129 , L_10 , sizeof( V_129 ) ) ;
V_1 -> V_41 = F_72 ( V_73 , V_129 ) ;
if ( F_61 ( V_1 -> V_41 ) ) {
F_69 ( V_73 , L_11 , V_129 ) ;
return F_62 ( V_1 -> V_41 ) ;
}
snprintf ( V_129 , sizeof( V_129 ) , L_12 , V_28 ) ;
V_1 -> V_42 = F_73 ( V_73 , V_129 ) ;
if ( F_61 ( V_1 -> V_42 ) ) {
F_69 ( V_73 , L_13 , V_129 ) ;
return F_62 ( V_1 -> V_42 ) ;
}
if ( V_28 || V_7 -> V_25 -> V_97 ) {
snprintf ( V_129 , sizeof( V_129 ) , L_14 , V_28 ) ;
V_122 = F_59 ( V_115 ,
V_125 , V_129 ) ;
V_1 -> V_35 = F_60 ( V_73 , V_122 ) ;
if ( F_61 ( V_1 -> V_35 ) )
return F_62 ( V_1 -> V_35 ) ;
}
V_1 -> V_1 = F_74 ( V_73 , NULL , & V_131 ) ;
if ( F_61 ( V_1 -> V_1 ) ) {
F_69 ( V_73 , L_15 , V_28 ) ;
return F_62 ( V_1 -> V_1 ) ;
}
V_1 -> V_23 = V_28 ;
F_75 ( V_1 -> V_1 , & V_7 -> V_70 [ V_28 ] ) ;
}
V_7 -> V_67 = F_76 ( V_7 -> V_58 ) ;
if ( V_7 -> V_67 > 0 ) {
V_40 = F_77 ( V_73 , V_7 -> V_67 ,
F_44 ,
V_132 | V_133 ,
L_16 , V_7 ) ;
if ( V_40 ) {
F_69 ( V_73 , L_17 , V_40 ) ;
return V_40 ;
}
}
V_7 -> V_68 = F_76 ( V_7 -> V_61 ) ;
if ( V_7 -> V_68 > 0 ) {
V_40 = F_77 ( V_73 , V_7 -> V_68 ,
F_44 ,
V_132 | V_133 ,
L_18 , V_7 ) ;
if ( V_40 ) {
F_69 ( V_73 , L_19 , V_40 ) ;
V_7 -> V_68 = - 1 ;
F_49 ( V_115 ) ;
return V_40 ;
}
}
if ( V_7 -> V_62 ) {
V_7 -> V_105 . V_134 = F_45 ;
V_7 -> V_105 . V_135 = 0 ;
V_40 = F_78 ( & V_7 -> V_105 ) ;
if ( V_40 ) {
F_49 ( V_115 ) ;
return V_40 ;
}
V_7 -> V_116 = true ;
}
V_120 = F_79 ( V_73 , F_46 ) ;
if ( F_61 ( V_120 ) ) {
F_49 ( V_115 ) ;
return F_62 ( V_120 ) ;
}
return 0 ;
}
