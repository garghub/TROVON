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
F_12 ( V_49 , V_50 |
V_51 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static inline T_1 F_23 ( struct V_52 * V_53 )
{
T_1 V_54 ;
V_54 = V_53 -> V_55 * V_56 +
V_53 -> V_57 * V_58 ;
F_24 ( L_1 , V_54 ) ;
return V_54 ;
}
static inline struct V_59 * F_25 ( void * V_60 )
{
return (struct V_59 * ) V_60 ;
}
static inline struct V_52 * F_26 ( void * V_60 )
{
return (struct V_52 * ) V_60 ;
}
static int F_27 ( struct V_1 * V_2 , void * V_60 , T_1 V_30 ,
T_1 V_31 , T_1 T_3 * V_61 ,
T_1 V_62 , T_1 V_63 ,
struct V_64 * V_65 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_59 * V_53 ;
T_1 * V_66 ;
T_1 V_67 , V_68 , V_69 ;
V_53 = F_25 ( V_60 ) ;
F_15 ( V_2 , V_30 , V_31 ) ;
V_66 = & V_53 -> V_70 ;
for ( V_67 = V_71 ; V_67 <= V_72 ; V_67 ++ )
F_12 ( V_67 , V_66 [ V_67 - V_71 ] ) ;
V_69 = F_28 ( V_53 -> V_73 ,
V_74 , V_75 , 1 ) ;
F_12 ( V_76 , V_69 ) ;
if ( F_29 ( V_65 , V_61 , V_68 ) )
F_12 ( V_77 , ( V_68 << V_62 ) & V_63 ) ;
V_69 = F_28 ( V_53 -> V_78 , V_79 , V_80 , 1 ) ;
F_12 ( V_81 , V_69 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , void * V_60 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_52 * V_53 ;
T_1 V_82 ;
V_53 = F_26 ( V_60 ) ;
V_82 = F_23 ( V_53 ) ;
F_12 ( V_82 + V_83 ,
V_53 -> V_84 ) ;
F_12 ( V_82 + V_85 ,
V_53 -> V_86 ) ;
F_12 ( V_82 + V_87 ,
V_53 -> V_88 ) ;
F_12 ( V_82 + V_89 ,
V_53 -> V_90 ) ;
F_12 ( V_82 + V_91 ,
V_53 -> V_92 ) ;
F_12 ( V_82 + V_93 ,
V_53 -> V_94 ) ;
F_12 ( V_82 + V_95 ,
V_53 -> V_96 ) ;
return 0 ;
}
static bool F_31 ( struct V_1 * V_2 , T_2 V_97 ,
T_1 V_30 , T_1 V_31 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_1 V_98 ;
bool V_54 = false ;
T_1 V_99 , V_100 ;
F_15 ( V_2 , V_30 , V_31 ) ;
V_98 = F_19 ( V_81 ) ;
if ( V_98 ) {
V_99 = F_32 ( V_97 >> 8 ) ;
V_100 = F_33 ( V_97 >> 8 ) ;
if ( V_99 == F_19 ( V_101 ) &&
V_100 == F_19 ( V_102 ) )
V_54 = true ;
}
F_16 ( V_2 ) ;
return V_54 ;
}
static bool F_34 ( struct V_1 * V_2 , void * V_60 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_52 * V_53 ;
T_1 V_82 ;
T_1 V_96 ;
V_53 = F_26 ( V_60 ) ;
V_82 = F_23 ( V_53 ) ;
V_96 = F_19 ( V_82 + V_95 ) ;
if ( V_96 & V_103 )
return true ;
return false ;
}
static int F_35 ( struct V_1 * V_2 , void * V_60 ,
enum V_104 V_105 ,
unsigned int V_106 , T_1 V_30 ,
T_1 V_31 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_1 V_107 ;
enum V_108 type ;
unsigned long V_109 , V_110 ;
int V_111 ;
F_15 ( V_2 , V_30 , V_31 ) ;
F_12 ( V_76 , 0 ) ;
switch ( V_105 ) {
case V_112 :
type = V_113 ;
break;
case V_114 :
type = V_115 ;
break;
default:
type = V_113 ;
break;
}
F_36 ( V_109 ) ;
F_37 () ;
V_111 = 5000 ;
while ( true ) {
V_107 = F_19 ( V_116 ) ;
if ( F_2 ( V_107 , V_117 , V_118 ) ) {
F_24 ( L_2 ) ;
goto V_119;
}
if ( F_2 ( V_107 , V_117 , V_80 ) ) {
if ( F_2 ( V_107 , V_117 , V_120 )
== 3 )
break;
if ( F_2 ( V_107 , V_117 , V_121 )
>= 10 )
break;
F_24 ( L_3 ) ;
} else
break;
V_119:
if ( ! V_111 ) {
F_38 ( L_4 ) ;
break;
}
F_39 ( 100 ) ;
-- V_111 ;
}
V_111 = 1000 ;
while ( true ) {
V_107 = F_19 ( V_122 ) ;
if ( ! ( V_107 & V_123 ) )
break;
F_24 ( L_5 ) ;
if ( ! V_111 ) {
F_38 ( L_6 ) ;
break;
}
F_39 ( 100 ) ;
-- V_111 ;
}
F_40 ( V_109 ) ;
F_41 () ;
F_12 ( V_122 , type ) ;
V_110 = ( V_106 * V_124 / 1000 ) + V_125 ;
while ( true ) {
V_107 = F_19 ( V_81 ) ;
if ( ! ( V_107 & V_126 ) )
break;
if ( F_42 ( V_125 , V_110 ) ) {
F_38 ( L_7 ) ;
F_16 ( V_2 ) ;
return - V_127 ;
}
F_43 ( 500 , 1000 ) ;
}
F_16 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , void * V_60 ,
unsigned int V_106 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_52 * V_53 ;
T_1 V_82 ;
T_1 V_107 ;
int V_128 = V_106 ;
V_53 = F_26 ( V_60 ) ;
V_82 = F_23 ( V_53 ) ;
V_107 = F_19 ( V_82 + V_95 ) ;
V_107 = V_107 & ~ V_103 ;
F_12 ( V_82 + V_95 , V_107 ) ;
while ( true ) {
V_107 = F_19 ( V_82 + V_129 ) ;
if ( V_107 & V_130 )
break;
if ( V_128 <= 0 )
return - V_127 ;
F_45 ( 20 ) ;
V_128 -= 20 ;
}
F_12 ( V_82 + V_93 , 0 ) ;
F_12 ( V_82 + V_131 , 0 ) ;
F_12 ( V_82 + V_132 , 0 ) ;
F_12 ( V_82 + V_85 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
union V_133 V_134 ;
unsigned int V_135 ;
V_134 . V_136 = 0 ;
V_134 . V_137 . V_138 = 0 ;
V_134 . V_137 . V_139 = V_140 ;
V_134 . V_137 . V_141 = 1 ;
for ( V_135 = 0 ; V_135 < V_142 ; V_135 ++ )
F_12 ( V_143 [ V_135 * V_144 +
V_145 ] , V_134 . V_136 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
unsigned int V_146 ,
T_1 V_147 ,
T_1 V_148 ,
T_1 V_149 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
union V_133 V_134 ;
V_134 . V_136 = V_147 ;
V_134 . V_137 . V_138 = 0 ;
F_12 ( V_143 [ V_146 * V_144 +
V_145 ] , V_134 . V_136 ) ;
F_12 ( V_143 [ V_146 * V_144 +
V_150 ] , V_148 ) ;
F_12 ( V_143 [ V_146 * V_144 +
V_151 ] , V_149 ) ;
V_134 . V_137 . V_138 = 1 ;
F_12 ( V_143 [ V_146 * V_144 +
V_145 ] , V_134 . V_136 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
T_1 V_152 ,
T_1 V_153 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_1 V_69 ;
F_11 ( & V_6 -> V_154 ) ;
F_12 ( V_155 , V_152 ) ;
F_12 ( V_156 , V_153 ) ;
V_69 = V_157 |
V_158 |
V_159 ;
F_12 ( V_155 , V_69 ) ;
F_14 ( & V_6 -> V_154 ) ;
return 0 ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
unsigned int V_146 ,
unsigned int V_160 )
{
return V_143 [ V_146 * V_144 + V_160 ] ;
}
static bool F_50 ( struct V_1 * V_2 ,
T_4 V_26 )
{
T_1 V_67 ;
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
V_67 = F_19 ( V_44 + V_26 ) ;
return V_67 & V_43 ;
}
static T_5 F_51 ( struct V_1 * V_2 ,
T_4 V_26 )
{
T_1 V_67 ;
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
V_67 = F_19 ( V_44 + V_26 ) ;
return V_67 & V_43 ;
}
static void F_52 ( struct V_1 * V_2 , T_4 V_26 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
F_12 ( V_161 , 1 << V_26 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
T_2 V_162 , T_1 V_26 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
F_6 ( V_2 , 0 , 0 , 0 , V_26 ) ;
F_12 ( V_163 , V_162 ) ;
F_13 ( V_2 ) ;
}
static T_5 F_54 ( struct V_1 * V_2 , enum V_164 type )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
const union V_165 * V_166 ;
F_55 ( V_2 == NULL ) ;
switch ( type ) {
case V_167 :
V_166 = ( const union V_165 * )
V_6 -> V_8 . V_168 -> V_69 ;
break;
case V_169 :
V_166 = ( const union V_165 * )
V_6 -> V_8 . V_170 -> V_69 ;
break;
case V_171 :
V_166 = ( const union V_165 * )
V_6 -> V_8 . V_172 -> V_69 ;
break;
case V_173 :
V_166 = ( const union V_165 * )
V_6 -> V_8 . V_174 -> V_69 ;
break;
case V_175 :
V_166 = ( const union V_165 * )
V_6 -> V_8 . V_176 -> V_69 ;
break;
case V_177 :
V_166 = ( const union V_165 * )
V_6 -> V_8 . V_178 -> V_69 ;
break;
case V_179 :
V_166 = ( const union V_165 * )
V_6 -> V_180 . V_181 [ 0 ] . V_182 -> V_69 ;
break;
case V_183 :
V_166 = ( const union V_165 * )
V_6 -> V_180 . V_181 [ 1 ] . V_182 -> V_69 ;
break;
default:
return 0 ;
}
if ( V_166 == NULL )
return 0 ;
return V_166 -> V_184 . V_185 ;
}
