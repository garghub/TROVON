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
T_1 V_47 , V_48 ;
enum V_28 V_49 ;
F_12 ( L_1 ) ;
for ( V_49 = V_50 ; V_49 <= V_51 ; V_49 ++ ) {
V_47 = F_19 ( F_20 ( V_49 ) ) ;
V_48 = F_19 ( F_38 ( V_49 ) ) ;
if ( ( V_47 & V_40 ) || ( V_48 & V_52 ) ) {
if ( F_19 ( F_23 ( V_49 ) ) & V_31 ) {
* V_28 = V_49 ;
return true ;
}
}
}
return false ;
}
static void F_39 ( struct V_11 * V_12 ,
struct V_13 * V_53 )
{
F_12 ( L_1 ) ;
}
static enum V_54
F_40 ( struct V_5 * V_6 ,
struct V_17 * V_21 )
{
struct V_15 * V_15 = F_41 ( V_6 ) ;
struct V_17 * V_18 = V_15 -> V_19 . V_18 ;
struct V_4 * V_4 = F_6 ( V_6 ) ;
F_12 ( L_1 ) ;
if ( V_21 -> V_55 & V_56 ) {
F_12 ( L_3 ) ;
return V_57 ;
}
if ( V_18 ) {
if ( V_21 -> V_58 > V_18 -> V_58 )
return V_59 ;
if ( V_21 -> V_60 > V_18 -> V_60 )
return V_59 ;
}
return V_4 -> V_8 . V_23 -> V_61 ( & V_4 -> V_8 , V_21 ) ;
}
static T_2 F_42 ( T_1 V_62 , unsigned int V_63 )
{
switch ( V_62 ) {
case V_64 :
default:
return 20 * V_63 ;
case V_65 :
return 10 * V_63 ;
case V_66 :
return 5 * V_63 ;
}
}
static T_2 F_43 ( T_2 V_67 , int V_68 , int V_69 )
{
return F_44 ( F_44 ( V_67 * V_68 , 8 ) , V_69 ) ;
}
static void F_45 ( struct V_70 * V_12 ,
const struct V_17 * V_21 )
{
struct V_35 * V_8 = V_12 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_25 ;
struct V_26 * V_26 = F_18 ( V_12 -> V_27 ) ;
struct V_4 * V_4 = F_25 ( V_12 ) ;
int V_28 = V_26 -> V_28 ;
unsigned int V_68 = V_26 -> V_14 . V_71 ;
unsigned int V_69 = V_4 -> V_69 ;
T_2 V_72 , V_73 , V_74 , V_75 , V_76 , V_77 , V_78 ;
V_72 = V_21 -> V_58 ;
V_73 = V_21 -> V_79 - V_21 -> V_58 ;
V_74 = V_21 -> V_80 - V_21 -> V_79 ;
V_75 = V_21 -> V_81 - V_21 -> V_80 ;
V_76 = V_21 -> V_82 - V_21 -> V_60 ;
V_77 = V_21 -> V_83 - V_21 -> V_82 ;
V_78 = V_21 -> V_84 - V_21 -> V_83 ;
V_72 = F_43 ( V_72 , V_68 , V_69 ) ;
V_73 = F_43 ( V_73 , V_68 , V_69 ) ;
V_74 = F_43 ( V_74 , V_68 , V_69 ) ;
V_75 = F_43 ( V_75 , V_68 , V_69 ) ;
F_21 ( F_46 ( V_28 ) , V_72 ) ;
F_21 ( F_47 ( V_28 ) , V_73 ) ;
F_21 ( F_48 ( V_28 ) , V_74 ) ;
F_21 ( F_49 ( V_28 ) , V_75 ) ;
F_21 ( F_50 ( V_28 ) , V_76 ) ;
F_21 ( F_51 ( V_28 ) , V_77 ) ;
F_21 ( F_52 ( V_28 ) , V_78 ) ;
}
static void F_53 ( struct V_11 * V_11 )
{
struct V_70 * V_12 = & V_11 -> V_7 ;
struct V_35 * V_8 = V_12 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_25 ;
struct V_26 * V_26 = F_18 ( V_12 -> V_27 ) ;
struct V_4 * V_4 = F_25 ( V_12 ) ;
struct V_17 * V_20 =
& V_26 -> V_14 . V_20 ;
int V_28 = V_26 -> V_28 ;
unsigned int V_68 = V_26 -> V_14 . V_71 ;
T_1 V_29 , V_85 ;
F_12 ( L_4 , F_54 ( V_28 ) ) ;
F_1 ( V_2 ) ;
V_85 = F_19 ( F_55 ( 0 ) ) ;
V_85 &= ~ V_86 ;
F_21 ( F_55 ( 0 ) , V_85 | V_64 ) ;
V_85 = F_19 ( F_55 ( V_28 ) ) ;
V_85 &= ~ V_87 ;
F_21 ( F_55 ( V_28 ) , V_85 | V_88 ) ;
F_21 ( F_56 ( V_28 ) , 0xffffffff ) ;
F_21 ( F_57 ( V_28 ) , 0xffffffff ) ;
F_21 ( F_58 ( V_28 ) , V_4 -> V_89 ) ;
F_21 ( F_59 ( V_28 ) ,
V_20 -> V_60 << V_90 |
V_20 -> V_58 << V_91 ) ;
F_45 ( V_12 , V_20 ) ;
V_29 = V_4 -> V_69 << V_92 ;
if ( F_10 ( V_4 ) ) {
V_29 |= V_4 -> V_93 << V_94 ;
V_29 |= V_95 ;
} else {
V_29 |= V_4 -> V_93 << V_96 ;
V_29 |= V_4 -> V_97 ;
}
F_21 ( F_38 ( V_28 ) , V_29 ) ;
if ( F_9 ( V_4 ) &&
V_4 -> V_98 == V_99 ) {
F_21 ( F_60 ( V_28 ) ,
F_43 ( V_20 -> V_81 , V_68 ,
V_4 -> V_69 ) + 1 ) ;
} else {
F_21 ( F_60 ( V_28 ) ,
F_43 ( V_20 -> V_84 *
V_20 -> V_81 ,
V_68 , V_4 -> V_69 ) + 1 ) ;
}
F_21 ( F_61 ( V_28 ) , V_4 -> V_100 ) ;
F_21 ( F_62 ( V_28 ) , V_4 -> V_101 ) ;
F_21 ( F_63 ( V_28 ) , V_4 -> V_102 ) ;
F_21 ( F_64 ( V_28 ) , F_42 ( V_64 , 100 ) ) ;
F_21 ( F_65 ( V_28 ) , V_4 -> V_103 ) ;
F_21 ( F_66 ( V_28 ) ,
V_4 -> V_104 ) ;
F_21 ( F_67 ( V_28 ) , V_4 -> V_105 ) ;
F_21 ( F_68 ( V_28 ) , V_4 -> V_106 ) ;
F_21 ( F_69 ( V_28 ) ,
V_4 -> V_107 << V_108 |
V_4 -> V_109 << V_110 ) ;
if ( F_9 ( V_4 ) )
F_21 ( F_70 ( V_28 ) ,
V_4 -> V_111 |
V_4 -> V_98 ) ;
}
static enum V_112
F_71 ( struct V_5 * V_6 , bool V_113 )
{
struct V_4 * V_4 = F_6 ( V_6 ) ;
F_12 ( L_1 ) ;
return V_4 -> V_8 . V_23 -> V_114 ( & V_4 -> V_8 ) ;
}
static int F_72 ( struct V_5 * V_6 )
{
struct V_15 * V_15 = F_41 ( V_6 ) ;
struct V_17 * V_21 ;
F_12 ( L_1 ) ;
if ( ! V_15 -> V_19 . V_18 ) {
F_12 ( L_5 ) ;
return 0 ;
}
V_21 = F_73 ( V_6 -> V_8 ,
V_15 -> V_19 . V_18 ) ;
if ( ! V_21 ) {
F_12 ( L_6 ) ;
return 0 ;
}
F_74 ( V_6 , V_21 ) ;
return 1 ;
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_15 * V_15 = F_41 ( V_6 ) ;
F_12 ( L_1 ) ;
F_76 ( & V_15 -> V_19 ) ;
F_77 ( V_6 ) ;
F_78 ( V_6 ) ;
}
bool F_79 ( struct V_35 * V_8 )
{
struct V_4 * V_4 ;
struct V_11 * V_11 ;
struct V_70 * V_12 ;
struct V_15 * V_15 ;
struct V_5 * V_6 ;
struct V_17 * V_18 = NULL ;
const struct V_115 * V_116 ;
unsigned int V_117 ;
F_12 ( L_1 ) ;
V_4 = F_80 ( sizeof( * V_4 ) , V_118 ) ;
if ( ! V_4 )
return false ;
V_15 = F_80 ( sizeof( * V_15 ) , V_118 ) ;
if ( ! V_15 ) {
F_78 ( V_4 ) ;
return false ;
}
V_11 = & V_4 -> V_7 ;
V_12 = & V_11 -> V_7 ;
V_4 -> V_16 = V_15 ;
V_6 = & V_15 -> V_7 ;
F_81 ( V_8 , V_12 , & V_119 , V_120 ) ;
V_11 -> V_121 = F_11 ;
V_11 -> V_122 = F_13 ;
V_11 -> V_123 = F_15 ;
V_11 -> V_124 = F_24 ;
V_11 -> V_41 = F_26 ;
V_11 -> V_125 = F_53 ;
V_11 -> V_43 = F_31 ;
V_11 -> V_126 = F_36 ;
V_11 -> V_127 = F_37 ;
V_11 -> V_128 = F_39 ;
V_15 -> V_127 = V_129 ;
for ( V_117 = 0 ; V_117 < F_82 ( V_130 ) ; V_117 ++ ) {
V_116 = & V_130 [ V_117 ] ;
V_4 -> V_8 = * V_116 ;
if ( V_116 -> V_23 -> V_131 ( & V_4 -> V_8 ) )
break;
}
if ( V_117 == F_82 ( V_130 ) ) {
F_12 ( L_7 ) ;
goto V_132;
}
V_11 -> type = V_133 ;
V_11 -> V_134 = ( 1 << 0 ) ;
V_11 -> V_135 = false ;
F_83 ( V_8 , V_6 , & V_136 ,
V_137 ) ;
F_84 ( V_6 , & V_138 ) ;
V_6 -> V_139 . V_140 = V_141 ;
V_6 -> V_142 = false ;
V_6 -> V_143 = false ;
F_85 ( V_15 , V_11 ) ;
F_86 ( V_6 ) ;
V_18 = V_116 -> V_23 -> V_144 ( & V_4 -> V_8 ) ;
if ( ! V_18 ) {
F_12 ( L_5 ) ;
goto V_132;
}
V_18 -> type |= V_145 ;
F_87 ( & V_15 -> V_19 , V_18 ) ;
return true ;
V_132:
F_88 ( & V_11 -> V_7 ) ;
F_78 ( V_4 ) ;
F_78 ( V_15 ) ;
return false ;
}
