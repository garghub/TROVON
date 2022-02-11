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
int V_81 ;
if ( V_1 -> V_23 != 0 )
return - V_82 ;
switch ( V_80 ) {
case V_83 :
V_81 = V_62 ;
break;
case V_84 :
V_81 = V_63 ;
break;
case V_85 :
V_81 = V_60 ;
break;
default:
return - V_82 ;
}
if ( V_81 != V_7 -> V_59 ) {
F_35 ( & V_2 -> V_76 , L_2 , V_81 ) ;
V_7 -> V_59 = V_81 ;
}
V_7 -> V_55 = - 1 ;
V_7 -> V_86 = true ;
F_19 ( V_57 , & V_7 -> V_58 , 0 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 , bool V_87 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
F_8 ( V_1 , V_88 , V_87 ? 0 : 2 , 2 ) ;
}
static void F_37 ( struct V_89 * V_90 )
{
struct V_6 * V_7 =
F_38 ( V_90 , struct V_6 , V_58 . V_90 ) ;
struct V_1 * V_91 = V_7 -> V_73 [ 0 ] . V_1 ;
bool V_86 , V_92 = false , V_93 = false ;
int V_55 , V_56 ;
if ( V_91 == NULL )
return;
V_55 = F_22 ( V_7 ) ;
V_56 = F_24 ( V_7 ) ;
F_39 ( & V_91 -> V_94 ) ;
if ( ! V_7 -> V_52 ) {
F_40 ( & V_91 -> V_94 ) ;
return;
}
V_86 = V_7 -> V_86 ;
V_7 -> V_86 = false ;
if ( V_55 != V_7 -> V_55 ) {
if ( V_7 -> V_59 == V_60 &&
! F_26 ( V_7 ) )
V_86 = true ;
if ( V_86 && V_55 == 0 ) {
F_7 ( V_91 , 0 ) ;
F_41 ( 200 ) ;
F_7 ( V_91 , 1 ) ;
}
F_6 ( V_91 , V_55 ) ;
V_7 -> V_55 = V_55 ;
V_92 = true ;
}
if ( V_56 != V_7 -> V_56 ) {
F_7 ( V_91 , V_56 ) ;
V_7 -> V_56 = V_56 ;
V_93 = true ;
}
F_40 ( & V_91 -> V_94 ) ;
if ( V_92 ) {
F_42 ( V_7 -> V_95 , V_96 ,
! V_55 ) ;
if ( V_86 && V_55 == 1 ) {
F_39 ( & V_91 -> V_94 ) ;
F_7 ( V_91 , 0 ) ;
F_41 ( 1000 ) ;
F_7 ( V_91 , 1 ) ;
F_40 ( & V_91 -> V_94 ) ;
}
}
if ( V_93 )
F_42 ( V_7 -> V_95 , V_97 , V_56 ) ;
if ( F_27 ( V_7 ) )
F_19 ( V_57 , & V_7 -> V_58 , V_78 ) ;
}
static T_3 F_43 ( int V_98 , void * V_99 )
{
struct V_6 * V_7 = V_99 ;
F_31 ( V_57 , & V_7 -> V_58 , V_77 ) ;
return V_100 ;
}
static int F_44 ( struct V_101 * V_102 ,
unsigned long V_11 , void * V_103 )
{
struct V_6 * V_7 =
F_38 ( V_102 , struct V_6 , V_104 ) ;
struct V_105 * V_106 = V_103 ;
if ( V_11 == V_107 && V_106 == V_7 -> V_65 )
F_31 ( V_57 , & V_7 -> V_58 , V_77 ) ;
return V_108 ;
}
static struct V_1 * F_45 ( struct V_109 * V_76 ,
struct V_110 * args )
{
struct V_6 * V_7 = F_46 ( V_76 ) ;
if ( args -> args [ 0 ] >= V_7 -> V_25 -> V_111 )
return F_47 ( - V_112 ) ;
return V_7 -> V_73 [ args -> args [ 0 ] ] . V_1 ;
}
static int F_48 ( struct V_113 * V_114 )
{
struct V_109 * V_76 = & V_114 -> V_76 ;
struct V_6 * V_7 = F_46 ( V_76 ) ;
if ( V_7 -> V_115 )
F_49 ( & V_7 -> V_104 ) ;
if ( V_7 -> V_70 > 0 )
F_50 ( V_76 , V_7 -> V_70 , V_7 ) ;
if ( V_7 -> V_71 > 0 )
F_50 ( V_76 , V_7 -> V_71 , V_7 ) ;
F_51 ( & V_7 -> V_58 ) ;
return 0 ;
}
static int F_52 ( struct V_113 * V_114 )
{
struct V_6 * V_7 ;
struct V_109 * V_76 = & V_114 -> V_76 ;
struct V_116 * V_117 = V_76 -> V_118 ;
struct V_119 * V_119 ;
struct V_120 * V_121 ;
int V_28 , V_41 ;
V_7 = F_53 ( V_76 , sizeof( * V_7 ) , V_122 ) ;
if ( ! V_7 )
return - V_123 ;
F_54 ( & V_7 -> V_29 ) ;
F_55 ( & V_7 -> V_58 , F_37 ) ;
F_56 ( V_76 , V_7 ) ;
V_7 -> V_25 = F_57 ( V_76 ) ;
if ( ! V_7 -> V_25 )
return - V_82 ;
V_121 = F_58 ( V_114 , V_124 , L_3 ) ;
V_7 -> V_9 = F_59 ( V_76 , V_121 ) ;
if ( F_60 ( V_7 -> V_9 ) )
return F_61 ( V_7 -> V_9 ) ;
V_7 -> V_61 = F_62 ( V_76 , L_4 ,
V_125 ) ;
if ( F_60 ( V_7 -> V_61 ) )
return F_61 ( V_7 -> V_61 ) ;
V_7 -> V_64 = F_62 ( V_76 , L_5 ,
V_125 ) ;
if ( F_60 ( V_7 -> V_64 ) )
return F_61 ( V_7 -> V_64 ) ;
if ( F_63 ( V_117 , L_6 , NULL ) ) {
V_7 -> V_65 = F_64 ( V_76 ,
L_6 ) ;
if ( F_60 ( V_7 -> V_65 ) )
return F_61 ( V_7 -> V_65 ) ;
if ( ! V_7 -> V_65 )
return - V_126 ;
}
V_7 -> V_59 = F_65 ( V_117 , 0 ) ;
V_7 -> V_95 = F_66 ( V_76 , V_127 ) ;
if ( F_60 ( V_7 -> V_95 ) )
return F_61 ( V_7 -> V_95 ) ;
V_41 = F_67 ( V_76 , V_7 -> V_95 ) ;
if ( V_41 ) {
F_68 ( V_76 , L_7 , V_41 ) ;
return V_41 ;
}
for ( V_28 = 0 ; V_28 < V_7 -> V_25 -> V_111 ; V_28 ++ ) {
struct V_5 * V_1 = V_7 -> V_73 + V_28 ;
char V_128 [ 16 ] ;
snprintf ( V_128 , sizeof( V_128 ) , L_8 , V_28 ) ;
V_1 -> V_75 = F_69 ( V_76 , V_128 ) ;
if ( F_60 ( V_1 -> V_75 ) ) {
if ( F_61 ( V_1 -> V_75 ) == - V_126 )
return - V_126 ;
V_1 -> V_75 = NULL ;
}
if ( V_7 -> V_25 -> V_129 )
snprintf ( V_128 , sizeof( V_128 ) , L_9 , V_28 ) ;
else
F_70 ( V_128 , L_10 , sizeof( V_128 ) ) ;
V_1 -> V_42 = F_71 ( V_76 , V_128 ) ;
if ( F_60 ( V_1 -> V_42 ) ) {
F_68 ( V_76 , L_11 , V_128 ) ;
return F_61 ( V_1 -> V_42 ) ;
}
snprintf ( V_128 , sizeof( V_128 ) , L_12 , V_28 ) ;
V_1 -> V_43 = F_72 ( V_76 , V_128 ) ;
if ( F_60 ( V_1 -> V_43 ) ) {
F_68 ( V_76 , L_13 , V_128 ) ;
return F_61 ( V_1 -> V_43 ) ;
}
if ( V_28 ) {
snprintf ( V_128 , sizeof( V_128 ) , L_14 , V_28 ) ;
V_121 = F_58 ( V_114 ,
V_124 , V_128 ) ;
V_1 -> V_36 = F_59 ( V_76 , V_121 ) ;
if ( F_60 ( V_1 -> V_36 ) )
return F_61 ( V_1 -> V_36 ) ;
}
V_1 -> V_1 = F_73 ( V_76 , NULL , & V_130 ) ;
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
V_131 | V_132 ,
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
V_131 | V_132 ,
L_18 , V_7 ) ;
if ( V_41 ) {
F_68 ( V_76 , L_19 , V_41 ) ;
V_7 -> V_71 = - 1 ;
F_48 ( V_114 ) ;
return V_41 ;
}
}
if ( V_7 -> V_65 ) {
V_7 -> V_104 . V_133 = F_44 ;
V_7 -> V_104 . V_134 = 0 ;
V_41 = F_77 ( & V_7 -> V_104 ) ;
if ( V_41 ) {
F_48 ( V_114 ) ;
return V_41 ;
}
V_7 -> V_115 = true ;
}
V_119 = F_78 ( V_76 , F_45 ) ;
if ( F_60 ( V_119 ) ) {
F_48 ( V_114 ) ;
return F_61 ( V_119 ) ;
}
return 0 ;
}
