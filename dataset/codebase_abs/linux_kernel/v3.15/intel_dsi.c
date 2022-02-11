static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( V_2 , 0x08 , 0x0001 ) ;
F_3 ( V_2 , 0x0F , 0x0005 ) ;
F_3 ( V_2 , 0x0F , 0x0025 ) ;
F_4 ( 150 ) ;
F_3 ( V_2 , 0x0F , 0x0000 ) ;
F_3 ( V_2 , 0x08 , 0x0000 ) ;
F_5 ( & V_2 -> V_3 ) ;
}
static struct V_4 * F_6 ( struct V_5 * V_6 )
{
return F_7 ( F_8 ( V_6 ) ,
struct V_4 , V_7 ) ;
}
static inline bool F_9 ( struct V_4 * V_4 )
{
return V_4 -> V_8 . type == V_9 ;
}
static inline bool F_10 ( struct V_4 * V_4 )
{
return V_4 -> V_8 . type == V_10 ;
}
static void F_11 ( struct V_11 * V_12 )
{
F_12 ( L_1 ) ;
}
static bool F_13 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_4 * V_4 = F_7 ( V_12 , struct V_4 ,
V_7 ) ;
struct V_15 * V_15 = V_4 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_19 . V_18 ;
struct V_17 * V_20 = & V_14 -> V_20 ;
struct V_17 * V_21 = & V_14 -> V_22 ;
F_12 ( L_1 ) ;
if ( V_18 )
F_14 ( V_18 , V_20 ) ;
if ( V_4 -> V_8 . V_23 -> V_24 )
return V_4 -> V_8 . V_23 -> V_24 ( & V_4 -> V_8 ,
V_21 , V_20 ) ;
return true ;
}
static void F_15 ( struct V_11 * V_12 )
{
F_12 ( L_1 ) ;
F_16 ( V_12 ) ;
}
static void F_17 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_7 . V_8 -> V_25 ;
struct V_26 * V_26 = F_18 ( V_12 -> V_7 . V_27 ) ;
int V_28 = V_26 -> V_28 ;
T_1 V_29 ;
F_12 ( L_1 ) ;
V_29 = F_19 ( F_20 ( V_28 ) ) ;
F_21 ( F_20 ( V_28 ) , V_29 | V_30 ) ;
F_22 ( 1000 , 1500 ) ;
F_21 ( F_23 ( V_28 ) , V_31 | V_32 ) ;
F_22 ( 2000 , 2500 ) ;
F_21 ( F_23 ( V_28 ) , V_31 ) ;
F_22 ( 2000 , 2500 ) ;
F_21 ( F_23 ( V_28 ) , 0x00 ) ;
F_22 ( 2000 , 2500 ) ;
F_21 ( F_23 ( V_28 ) , V_31 ) ;
F_22 ( 2000 , 2500 ) ;
}
static void F_24 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_25 ( & V_12 -> V_7 ) ;
F_12 ( L_1 ) ;
if ( V_4 -> V_8 . V_23 -> V_33 )
V_4 -> V_8 . V_23 -> V_33 ( & V_4 -> V_8 ) ;
F_17 ( V_12 ) ;
if ( V_4 -> V_8 . V_23 -> V_34 )
V_4 -> V_8 . V_23 -> V_34 ( & V_4 -> V_8 ) ;
}
static void F_26 ( struct V_11 * V_12 )
{
struct V_35 * V_8 = V_12 -> V_7 . V_8 ;
struct V_1 * V_2 = V_8 -> V_25 ;
struct V_26 * V_26 = F_18 ( V_12 -> V_7 . V_27 ) ;
struct V_4 * V_4 = F_25 ( & V_12 -> V_7 ) ;
int V_28 = V_26 -> V_28 ;
T_1 V_36 ;
F_12 ( L_1 ) ;
if ( F_10 ( V_4 ) )
F_21 ( F_27 ( V_28 ) , 8 * 4 ) ;
else {
F_28 ( 20 ) ;
F_29 ( V_4 , V_37 ) ;
F_28 ( 100 ) ;
V_36 = F_19 ( F_20 ( V_28 ) ) & ~ V_38 ;
V_36 = V_36 | V_4 -> V_39 ;
F_21 ( F_20 ( V_28 ) , V_36 | V_40 ) ;
F_30 ( F_20 ( V_28 ) ) ;
}
if ( V_4 -> V_8 . V_23 -> V_41 )
V_4 -> V_8 . V_23 -> V_41 ( & V_4 -> V_8 ) ;
}
static void F_31 ( struct V_11 * V_12 )
{
struct V_35 * V_8 = V_12 -> V_7 . V_8 ;
struct V_1 * V_2 = V_8 -> V_25 ;
struct V_26 * V_26 = F_18 ( V_12 -> V_7 . V_27 ) ;
struct V_4 * V_4 = F_25 ( & V_12 -> V_7 ) ;
int V_28 = V_26 -> V_28 ;
T_1 V_36 ;
F_12 ( L_1 ) ;
if ( F_9 ( V_4 ) ) {
F_29 ( V_4 , V_42 ) ;
F_28 ( 10 ) ;
V_36 = F_19 ( F_20 ( V_28 ) ) ;
F_21 ( F_20 ( V_28 ) , V_36 & ~ V_40 ) ;
F_30 ( F_20 ( V_28 ) ) ;
F_28 ( 2 ) ;
}
if ( V_4 -> V_8 . V_23 -> V_43 )
V_4 -> V_8 . V_23 -> V_43 ( & V_4 -> V_8 ) ;
}
static void F_32 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_7 . V_8 -> V_25 ;
struct V_26 * V_26 = F_18 ( V_12 -> V_7 . V_27 ) ;
int V_28 = V_26 -> V_28 ;
T_1 V_29 ;
F_12 ( L_1 ) ;
F_21 ( F_23 ( V_28 ) , V_44 ) ;
F_22 ( 2000 , 2500 ) ;
F_21 ( F_23 ( V_28 ) , V_32 ) ;
F_22 ( 2000 , 2500 ) ;
F_21 ( F_23 ( V_28 ) , V_44 ) ;
F_22 ( 2000 , 2500 ) ;
V_29 = F_19 ( F_20 ( V_28 ) ) ;
F_21 ( F_20 ( V_28 ) , V_29 & ~ V_30 ) ;
F_22 ( 1000 , 1500 ) ;
if ( F_33 ( ( ( F_19 ( F_20 ( V_28 ) ) & V_45 )
== 0x00000 ) , 30 ) )
F_34 ( L_2 ) ;
F_21 ( F_23 ( V_28 ) , 0x00 ) ;
F_22 ( 2000 , 2500 ) ;
F_35 ( V_12 ) ;
}
static void F_36 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_25 ( & V_12 -> V_7 ) ;
F_12 ( L_1 ) ;
F_32 ( V_12 ) ;
if ( V_4 -> V_8 . V_23 -> V_46 )
V_4 -> V_8 . V_23 -> V_46 ( & V_4 -> V_8 ) ;
}
static bool F_37 ( struct V_11 * V_12 ,
enum V_28 * V_28 )
{
struct V_1 * V_2 = V_12 -> V_7 . V_8 -> V_25 ;
enum V_47 V_48 ;
T_1 V_49 , V_50 ;
enum V_28 V_51 ;
F_12 ( L_1 ) ;
V_48 = F_38 ( V_12 ) ;
if ( ! F_39 ( V_2 , V_48 ) )
return false ;
for ( V_51 = V_52 ; V_51 <= V_53 ; V_51 ++ ) {
V_49 = F_19 ( F_20 ( V_51 ) ) ;
V_50 = F_19 ( F_40 ( V_51 ) ) ;
if ( ( V_49 & V_40 ) || ( V_50 & V_54 ) ) {
if ( F_19 ( F_23 ( V_51 ) ) & V_31 ) {
* V_28 = V_51 ;
return true ;
}
}
}
return false ;
}
static void F_41 ( struct V_11 * V_12 ,
struct V_13 * V_55 )
{
F_12 ( L_1 ) ;
}
static enum V_56
F_42 ( struct V_5 * V_6 ,
struct V_17 * V_21 )
{
struct V_15 * V_15 = F_43 ( V_6 ) ;
struct V_17 * V_18 = V_15 -> V_19 . V_18 ;
struct V_4 * V_4 = F_6 ( V_6 ) ;
F_12 ( L_1 ) ;
if ( V_21 -> V_57 & V_58 ) {
F_12 ( L_3 ) ;
return V_59 ;
}
if ( V_18 ) {
if ( V_21 -> V_60 > V_18 -> V_60 )
return V_61 ;
if ( V_21 -> V_62 > V_18 -> V_62 )
return V_61 ;
}
return V_4 -> V_8 . V_23 -> V_63 ( & V_4 -> V_8 , V_21 ) ;
}
static T_2 F_44 ( T_1 V_64 , unsigned int V_65 )
{
switch ( V_64 ) {
case V_66 :
default:
return 20 * V_65 ;
case V_67 :
return 10 * V_65 ;
case V_68 :
return 5 * V_65 ;
}
}
static T_2 F_45 ( T_2 V_69 , int V_70 , int V_71 )
{
return F_46 ( F_46 ( V_69 * V_70 , 8 ) , V_71 ) ;
}
static void F_47 ( struct V_72 * V_12 ,
const struct V_17 * V_21 )
{
struct V_35 * V_8 = V_12 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_25 ;
struct V_26 * V_26 = F_18 ( V_12 -> V_27 ) ;
struct V_4 * V_4 = F_25 ( V_12 ) ;
int V_28 = V_26 -> V_28 ;
unsigned int V_70 = V_26 -> V_14 . V_73 ;
unsigned int V_71 = V_4 -> V_71 ;
T_2 V_74 , V_75 , V_76 , V_77 , V_78 , V_79 , V_80 ;
V_74 = V_21 -> V_60 ;
V_75 = V_21 -> V_81 - V_21 -> V_60 ;
V_76 = V_21 -> V_82 - V_21 -> V_81 ;
V_77 = V_21 -> V_83 - V_21 -> V_82 ;
V_78 = V_21 -> V_84 - V_21 -> V_62 ;
V_79 = V_21 -> V_85 - V_21 -> V_84 ;
V_80 = V_21 -> V_86 - V_21 -> V_85 ;
V_74 = F_45 ( V_74 , V_70 , V_71 ) ;
V_75 = F_45 ( V_75 , V_70 , V_71 ) ;
V_76 = F_45 ( V_76 , V_70 , V_71 ) ;
V_77 = F_45 ( V_77 , V_70 , V_71 ) ;
F_21 ( F_48 ( V_28 ) , V_74 ) ;
F_21 ( F_49 ( V_28 ) , V_75 ) ;
F_21 ( F_50 ( V_28 ) , V_76 ) ;
F_21 ( F_51 ( V_28 ) , V_77 ) ;
F_21 ( F_52 ( V_28 ) , V_78 ) ;
F_21 ( F_53 ( V_28 ) , V_79 ) ;
F_21 ( F_54 ( V_28 ) , V_80 ) ;
}
static void F_55 ( struct V_11 * V_11 )
{
struct V_72 * V_12 = & V_11 -> V_7 ;
struct V_35 * V_8 = V_12 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_25 ;
struct V_26 * V_26 = F_18 ( V_12 -> V_27 ) ;
struct V_4 * V_4 = F_25 ( V_12 ) ;
struct V_17 * V_20 =
& V_26 -> V_14 . V_20 ;
int V_28 = V_26 -> V_28 ;
unsigned int V_70 = V_26 -> V_14 . V_73 ;
T_1 V_29 , V_87 ;
F_12 ( L_4 , F_56 ( V_28 ) ) ;
F_1 ( V_2 ) ;
V_87 = F_19 ( F_57 ( 0 ) ) ;
V_87 &= ~ V_88 ;
F_21 ( F_57 ( 0 ) , V_87 | V_66 ) ;
V_87 = F_19 ( F_57 ( V_28 ) ) ;
V_87 &= ~ V_89 ;
F_21 ( F_57 ( V_28 ) , V_87 | V_90 ) ;
F_21 ( F_58 ( V_28 ) , 0xffffffff ) ;
F_21 ( F_59 ( V_28 ) , 0xffffffff ) ;
F_21 ( F_60 ( V_28 ) , V_4 -> V_91 ) ;
F_21 ( F_61 ( V_28 ) ,
V_20 -> V_62 << V_92 |
V_20 -> V_60 << V_93 ) ;
F_47 ( V_12 , V_20 ) ;
V_29 = V_4 -> V_71 << V_94 ;
if ( F_10 ( V_4 ) ) {
V_29 |= V_4 -> V_95 << V_96 ;
V_29 |= V_97 ;
} else {
V_29 |= V_4 -> V_95 << V_98 ;
V_29 |= V_4 -> V_99 ;
}
F_21 ( F_40 ( V_28 ) , V_29 ) ;
if ( F_9 ( V_4 ) &&
V_4 -> V_100 == V_101 ) {
F_21 ( F_62 ( V_28 ) ,
F_45 ( V_20 -> V_83 , V_70 ,
V_4 -> V_71 ) + 1 ) ;
} else {
F_21 ( F_62 ( V_28 ) ,
F_45 ( V_20 -> V_86 *
V_20 -> V_83 ,
V_70 , V_4 -> V_71 ) + 1 ) ;
}
F_21 ( F_63 ( V_28 ) , V_4 -> V_102 ) ;
F_21 ( F_64 ( V_28 ) , V_4 -> V_103 ) ;
F_21 ( F_65 ( V_28 ) , V_4 -> V_104 ) ;
F_21 ( F_66 ( V_28 ) , F_44 ( V_66 , 100 ) ) ;
F_21 ( F_67 ( V_28 ) , V_4 -> V_105 ) ;
F_21 ( F_68 ( V_28 ) ,
V_4 -> V_106 ) ;
F_21 ( F_69 ( V_28 ) , V_4 -> V_107 ) ;
F_21 ( F_70 ( V_28 ) , V_4 -> V_108 ) ;
F_21 ( F_71 ( V_28 ) ,
V_4 -> V_109 << V_110 |
V_4 -> V_111 << V_112 ) ;
if ( F_9 ( V_4 ) )
F_21 ( F_72 ( V_28 ) ,
V_4 -> V_113 |
V_4 -> V_100 ) ;
}
static enum V_114
F_73 ( struct V_5 * V_6 , bool V_115 )
{
struct V_4 * V_4 = F_6 ( V_6 ) ;
struct V_11 * V_11 = & V_4 -> V_7 ;
enum V_47 V_48 ;
enum V_114 V_116 ;
struct V_1 * V_2 = V_11 -> V_7 . V_8 -> V_25 ;
F_12 ( L_1 ) ;
V_48 = F_38 ( V_11 ) ;
F_74 ( V_2 , V_48 ) ;
V_116 = V_4 -> V_8 . V_23 -> V_117 ( & V_4 -> V_8 ) ;
F_75 ( V_2 , V_48 ) ;
return V_116 ;
}
static int F_76 ( struct V_5 * V_6 )
{
struct V_15 * V_15 = F_43 ( V_6 ) ;
struct V_17 * V_21 ;
F_12 ( L_1 ) ;
if ( ! V_15 -> V_19 . V_18 ) {
F_12 ( L_5 ) ;
return 0 ;
}
V_21 = F_77 ( V_6 -> V_8 ,
V_15 -> V_19 . V_18 ) ;
if ( ! V_21 ) {
F_12 ( L_6 ) ;
return 0 ;
}
F_78 ( V_6 , V_21 ) ;
return 1 ;
}
static void F_79 ( struct V_5 * V_6 )
{
struct V_15 * V_15 = F_43 ( V_6 ) ;
F_12 ( L_1 ) ;
F_80 ( & V_15 -> V_19 ) ;
F_81 ( V_6 ) ;
F_82 ( V_6 ) ;
}
bool F_83 ( struct V_35 * V_8 )
{
struct V_4 * V_4 ;
struct V_11 * V_11 ;
struct V_72 * V_12 ;
struct V_15 * V_15 ;
struct V_5 * V_6 ;
struct V_17 * V_18 = NULL ;
const struct V_118 * V_119 ;
unsigned int V_120 ;
F_12 ( L_1 ) ;
V_4 = F_84 ( sizeof( * V_4 ) , V_121 ) ;
if ( ! V_4 )
return false ;
V_15 = F_84 ( sizeof( * V_15 ) , V_121 ) ;
if ( ! V_15 ) {
F_82 ( V_4 ) ;
return false ;
}
V_11 = & V_4 -> V_7 ;
V_12 = & V_11 -> V_7 ;
V_4 -> V_16 = V_15 ;
V_6 = & V_15 -> V_7 ;
F_85 ( V_8 , V_12 , & V_122 , V_123 ) ;
V_11 -> V_124 = F_11 ;
V_11 -> V_125 = F_13 ;
V_11 -> V_126 = F_15 ;
V_11 -> V_127 = F_24 ;
V_11 -> V_41 = F_26 ;
V_11 -> V_128 = F_55 ;
V_11 -> V_43 = F_31 ;
V_11 -> V_129 = F_36 ;
V_11 -> V_130 = F_37 ;
V_11 -> V_131 = F_41 ;
V_15 -> V_130 = V_132 ;
V_15 -> V_133 = V_134 ;
for ( V_120 = 0 ; V_120 < F_86 ( V_135 ) ; V_120 ++ ) {
V_119 = & V_135 [ V_120 ] ;
V_4 -> V_8 = * V_119 ;
if ( V_119 -> V_23 -> V_136 ( & V_4 -> V_8 ) )
break;
}
if ( V_120 == F_86 ( V_135 ) ) {
F_12 ( L_7 ) ;
goto V_137;
}
V_11 -> type = V_138 ;
V_11 -> V_139 = ( 1 << 0 ) ;
V_11 -> V_140 = 0 ;
F_87 ( V_8 , V_6 , & V_141 ,
V_142 ) ;
F_88 ( V_6 , & V_143 ) ;
V_6 -> V_144 . V_145 = V_146 ;
V_6 -> V_147 = false ;
V_6 -> V_148 = false ;
F_89 ( V_15 , V_11 ) ;
F_90 ( V_6 ) ;
V_18 = V_119 -> V_23 -> V_149 ( & V_4 -> V_8 ) ;
if ( ! V_18 ) {
F_12 ( L_5 ) ;
goto V_137;
}
V_18 -> type |= V_150 ;
F_91 ( & V_15 -> V_19 , V_18 , NULL ) ;
return true ;
V_137:
F_92 ( & V_11 -> V_7 ) ;
F_82 ( V_4 ) ;
F_82 ( V_15 ) ;
return false ;
}
