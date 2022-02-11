static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
V_4 -> V_7 = V_6 -> V_8 . V_4 . V_7 ;
V_4 -> V_9 = F_2 ( V_6 -> V_8 . V_4 . V_10 ,
V_11 , V_12 ) ;
V_4 -> V_13 = F_2 ( V_6 -> V_8 . V_4 . V_10 ,
V_11 , V_14 ) ;
V_4 -> V_15 = V_6 -> V_8 . V_4 . V_16 ;
V_4 -> V_17 =
F_3 ( V_6 -> V_8 . V_4 . V_16 ) ;
V_4 -> V_18 =
V_6 -> V_8 . V_4 . V_19 ;
V_4 -> V_20 =
F_3 ( V_6 -> V_8 . V_4 . V_19 ) ;
return 0 ;
}
struct V_21 * F_4 ( void )
{
return (struct V_21 * ) & V_22 ;
}
static inline struct V_5 * F_5 ( struct V_1 * V_2 )
{
return (struct V_5 * ) V_2 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_23 , T_1 V_24 ,
T_1 V_25 , T_1 V_26 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_1 V_27 = F_7 ( V_24 ) | F_8 ( V_23 ) | F_9 ( V_26 ) | F_10 ( V_25 ) ;
F_11 ( & V_6 -> V_28 ) ;
F_12 ( V_29 , V_27 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_12 ( V_29 , 0 ) ;
F_14 ( & V_6 -> V_28 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_30 ,
T_1 V_31 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_1 V_23 = ( V_30 / V_6 -> V_8 . V_23 . V_32 ) + 1 ;
T_1 V_24 = ( V_30 % V_6 -> V_8 . V_23 . V_32 ) ;
F_6 ( V_2 , V_23 , V_24 , V_31 , 0 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_26 ,
T_1 V_33 ,
T_1 V_34 ,
T_1 V_35 ,
T_1 V_36 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_6 ( V_2 , 0 , 0 , 0 , V_26 ) ;
F_12 ( V_37 , V_33 ) ;
F_12 ( V_38 , V_34 ) ;
F_12 ( V_39 , V_35 ) ;
F_12 ( V_40 , V_36 ) ;
F_13 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_41 ,
unsigned int V_26 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_1 V_42 = ( V_41 == 0 ) ? 0 : ( T_1 ) V_41 |
V_43 ;
F_12 ( V_44 + V_26 , V_42 ) ;
while ( ! ( F_19 ( V_45 ) & ( 1U << V_26 ) ) )
F_20 () ;
F_12 ( V_45 , 1U << V_26 ) ;
F_12 ( V_46 + V_26 , V_42 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_30 ,
T_1 V_47 , T_2 V_48 )
{
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_1 V_23 ;
T_1 V_24 ;
V_23 = ( V_30 / V_6 -> V_8 . V_23 . V_32 ) + 1 ;
V_24 = ( V_30 % V_6 -> V_8 . V_23 . V_32 ) ;
F_6 ( V_2 , V_23 , V_24 , 0 , 0 ) ;
F_12 ( V_49 , V_50 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static inline T_1 F_23 ( struct V_51 * V_52 )
{
return 0 ;
}
static inline struct V_53 * F_24 ( void * V_54 )
{
return (struct V_53 * ) V_54 ;
}
static inline struct V_51 * F_25 ( void * V_54 )
{
return (struct V_51 * ) V_54 ;
}
static int F_26 ( struct V_1 * V_2 , void * V_54 , T_1 V_30 ,
T_1 V_31 , T_1 T_3 * V_55 ,
T_1 V_56 , T_1 V_57 ,
struct V_58 * V_59 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_53 * V_52 ;
T_1 * V_60 ;
T_1 V_61 , V_62 , V_63 ;
V_52 = F_24 ( V_54 ) ;
F_15 ( V_2 , V_30 , V_31 ) ;
if ( V_52 -> V_64 == 0 ) {
T_1 V_27 , V_23 , V_24 ;
V_23 = ( V_30 / V_6 -> V_8 . V_23 . V_32 ) + 1 ;
V_24 = ( V_30 % V_6 -> V_8 . V_23 . V_32 ) ;
F_27 ( L_1 ,
V_23 , V_24 , V_31 ) ;
V_27 = F_19 ( V_65 ) ;
V_27 = F_28 ( V_27 , V_66 , V_67 ,
( ( V_23 << 5 ) | ( V_24 << 3 ) | V_31 | 0x80 ) ) ;
F_12 ( V_65 , V_27 ) ;
}
V_60 = & V_52 -> V_68 ;
for ( V_61 = V_69 ; V_61 <= V_70 ; V_61 ++ )
F_12 ( V_61 , V_60 [ V_61 - V_69 ] ) ;
if ( F_5 ( V_2 ) -> V_71 != V_72 ) {
F_12 ( V_73 , V_52 -> V_74 ) ;
F_12 ( V_75 , V_52 -> V_76 ) ;
F_12 ( V_77 , V_52 -> V_78 ) ;
}
for ( V_61 = V_79 ; V_61 <= V_80 ; V_61 ++ )
F_12 ( V_61 , V_60 [ V_61 - V_69 ] ) ;
V_63 = F_28 ( V_52 -> V_81 ,
V_82 , V_83 , 1 ) ;
F_12 ( V_84 , V_63 ) ;
if ( F_29 ( V_59 , V_55 , V_62 ) )
F_12 ( V_85 , ( V_62 << V_56 ) & V_57 ) ;
V_63 = F_28 ( V_52 -> V_86 , V_87 , V_88 , 1 ) ;
F_12 ( V_89 , V_63 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , void * V_54 )
{
return 0 ;
}
static bool F_31 ( struct V_1 * V_2 , T_2 V_90 ,
T_1 V_30 , T_1 V_31 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_1 V_91 ;
bool V_92 = false ;
T_1 V_93 , V_94 ;
F_15 ( V_2 , V_30 , V_31 ) ;
V_91 = F_19 ( V_89 ) ;
if ( V_91 ) {
V_93 = F_32 ( V_90 >> 8 ) ;
V_94 = F_33 ( V_90 >> 8 ) ;
if ( V_93 == F_19 ( V_95 ) &&
V_94 == F_19 ( V_96 ) )
V_92 = true ;
}
F_16 ( V_2 ) ;
return V_92 ;
}
static bool F_34 ( struct V_1 * V_2 , void * V_54 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_51 * V_52 ;
T_1 V_97 ;
T_1 V_98 ;
V_52 = F_25 ( V_54 ) ;
V_97 = F_23 ( V_52 ) ;
V_98 = F_19 ( V_97 + V_99 ) ;
if ( V_98 & V_100 )
return true ;
return false ;
}
static int F_35 ( struct V_1 * V_2 , void * V_54 ,
enum V_101 V_102 ,
unsigned int V_103 , T_1 V_30 ,
T_1 V_31 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_1 V_104 ;
enum V_105 type ;
unsigned long V_106 , V_107 ;
int V_108 ;
struct V_53 * V_52 = F_24 ( V_54 ) ;
F_15 ( V_2 , V_30 , V_31 ) ;
if ( V_52 -> V_64 == 0 )
F_36 ( V_66 , V_67 , 0 ) ;
switch ( V_102 ) {
case V_109 :
type = V_110 ;
break;
case V_111 :
type = V_112 ;
break;
default:
type = V_110 ;
break;
}
F_37 ( V_106 ) ;
F_38 () ;
V_108 = 5000 ;
while ( true ) {
V_104 = F_19 ( V_113 ) ;
if ( F_2 ( V_104 , V_114 , V_115 ) ) {
F_27 ( L_2 ) ;
goto V_116;
}
if ( F_2 ( V_104 , V_114 , V_88 ) ) {
if ( F_2 ( V_104 , V_114 , V_117 )
== 3 )
break;
if ( F_2 ( V_104 , V_114 , V_118 )
>= 10 )
break;
F_27 ( L_3 ) ;
} else
break;
V_116:
if ( ! V_108 ) {
F_39 ( L_4 ) ;
break;
}
F_40 ( 100 ) ;
-- V_108 ;
}
V_108 = 1000 ;
while ( true ) {
V_104 = F_19 ( V_119 ) ;
if ( ! ( V_104 & V_120 ) )
break;
F_27 ( L_5 ) ;
if ( ! V_108 ) {
F_39 ( L_6 ) ;
break;
}
F_40 ( 100 ) ;
-- V_108 ;
}
F_41 ( V_106 ) ;
F_42 () ;
F_12 ( V_119 , type ) ;
V_107 = ( V_103 * V_121 / 1000 ) + V_122 ;
while ( true ) {
V_104 = F_19 ( V_89 ) ;
if ( ! ( V_104 & V_123 ) )
break;
if ( F_43 ( V_122 , V_107 ) ) {
F_39 ( L_7 ) ;
F_16 ( V_2 ) ;
return - V_124 ;
}
F_44 ( 500 , 1000 ) ;
}
F_16 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , void * V_54 ,
unsigned int V_103 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_51 * V_52 ;
T_1 V_97 ;
T_1 V_104 ;
int V_125 = V_103 ;
V_52 = F_25 ( V_54 ) ;
V_97 = F_23 ( V_52 ) ;
V_104 = F_19 ( V_97 + V_99 ) ;
V_104 = V_104 & ~ V_100 ;
F_12 ( V_97 + V_99 , V_104 ) ;
while ( true ) {
V_104 = F_19 ( V_97 + V_126 ) ;
if ( V_104 & V_127 )
break;
if ( V_125 <= 0 )
return - V_124 ;
F_46 ( 20 ) ;
V_125 -= 20 ;
}
F_12 ( V_97 + V_128 , 0 ) ;
F_12 ( V_97 + V_129 , 0 ) ;
F_12 ( V_97 + V_130 , 0 ) ;
F_12 ( V_97 + V_131 , 0 ) ;
return 0 ;
}
static bool F_47 ( struct V_1 * V_2 ,
T_4 V_26 )
{
T_1 V_61 ;
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
V_61 = F_19 ( V_44 + V_26 ) ;
return V_61 & V_43 ;
}
static T_5 F_48 ( struct V_1 * V_2 ,
T_4 V_26 )
{
T_1 V_61 ;
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
V_61 = F_19 ( V_44 + V_26 ) ;
return V_61 & V_43 ;
}
static void F_49 ( struct V_1 * V_2 , T_4 V_26 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
F_12 ( V_132 , 1 << V_26 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned int V_133 ,
T_1 V_134 ,
T_1 V_135 ,
T_1 V_136 )
{
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
T_1 V_137 ,
T_1 V_138 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_1 V_63 = 0 ;
F_11 ( & V_6 -> V_139 ) ;
F_12 ( V_140 , V_137 ) ;
F_12 ( V_141 , V_138 ) ;
V_63 = F_28 ( V_63 , V_142 ,
V_143 , 1 ) ;
V_63 = F_28 ( V_63 , V_142 ,
V_144 , 1 ) ;
V_63 = F_28 ( V_63 , V_142 ,
V_145 , 1 ) ;
F_12 ( V_140 , V_63 ) ;
F_14 ( & V_6 -> V_139 ) ;
return 0 ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
unsigned int V_133 ,
unsigned int V_146 )
{
return 0 ;
}
static void F_54 ( struct V_1 * V_2 ,
T_2 V_147 , T_1 V_26 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
F_6 ( V_2 , 0 , 0 , 0 , V_26 ) ;
F_12 ( V_148 , V_147 ) ;
F_13 ( V_2 ) ;
}
static T_5 F_55 ( struct V_1 * V_2 , enum V_149 type )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
const union V_150 * V_151 ;
F_56 ( V_2 == NULL ) ;
switch ( type ) {
case V_152 :
V_151 = ( const union V_150 * )
V_6 -> V_8 . V_153 -> V_63 ;
break;
case V_154 :
V_151 = ( const union V_150 * )
V_6 -> V_8 . V_155 -> V_63 ;
break;
case V_156 :
V_151 = ( const union V_150 * )
V_6 -> V_8 . V_157 -> V_63 ;
break;
case V_158 :
V_151 = ( const union V_150 * )
V_6 -> V_8 . V_159 -> V_63 ;
break;
case V_160 :
V_151 = ( const union V_150 * )
V_6 -> V_8 . V_161 -> V_63 ;
break;
case V_162 :
V_151 = ( const union V_150 * )
V_6 -> V_8 . V_163 -> V_63 ;
break;
case V_164 :
V_151 = ( const union V_150 * )
V_6 -> V_165 . V_166 [ 0 ] . V_167 -> V_63 ;
break;
case V_168 :
V_151 = ( const union V_150 * )
V_6 -> V_165 . V_166 [ 1 ] . V_167 -> V_63 ;
break;
default:
return 0 ;
}
if ( V_151 == NULL )
return 0 ;
return V_151 -> V_169 . V_170 ;
}
