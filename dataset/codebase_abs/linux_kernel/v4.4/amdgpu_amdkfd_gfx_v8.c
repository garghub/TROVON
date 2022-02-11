struct V_1 * F_1 ()
{
return (struct V_1 * ) & V_2 ;
}
static inline struct V_3 * F_2 ( struct V_4 * V_5 )
{
return (struct V_3 * ) V_5 ;
}
static void F_3 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 ,
T_1 V_8 , T_1 V_9 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_11 = F_4 ( V_7 ) | F_5 ( V_6 ) | F_6 ( V_9 ) | F_7 ( V_8 ) ;
F_8 ( & V_10 -> V_12 ) ;
F_9 ( V_13 , V_11 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
F_9 ( V_13 , 0 ) ;
F_11 ( & V_10 -> V_12 ) ;
}
static void F_12 ( struct V_4 * V_5 , T_1 V_14 ,
T_1 V_15 )
{
T_1 V_6 = ( ++ V_14 / V_16 ) + 1 ;
T_1 V_7 = ( V_14 % V_16 ) ;
F_3 ( V_5 , V_6 , V_7 , V_15 , 0 ) ;
}
static void F_13 ( struct V_4 * V_5 )
{
F_10 ( V_5 ) ;
}
static void F_14 ( struct V_4 * V_5 , T_1 V_9 ,
T_1 V_17 ,
T_1 V_18 ,
T_1 V_19 ,
T_1 V_20 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
F_3 ( V_5 , 0 , 0 , 0 , V_9 ) ;
F_9 ( V_21 , V_17 ) ;
F_9 ( V_22 , V_18 ) ;
F_9 ( V_23 , V_19 ) ;
F_9 ( V_24 , V_20 ) ;
F_10 ( V_5 ) ;
}
static int F_15 ( struct V_4 * V_5 , unsigned int V_25 ,
unsigned int V_9 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_26 = ( V_25 == 0 ) ? 0 : ( T_1 ) V_25 |
V_27 ;
F_9 ( V_28 + V_9 , V_26 ) ;
while ( ! ( F_16 ( V_29 ) & ( 1U << V_9 ) ) )
F_17 () ;
F_9 ( V_29 , 1U << V_9 ) ;
F_9 ( V_30 + V_9 , V_26 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 , T_1 V_14 ,
T_1 V_31 , T_2 V_32 )
{
return 0 ;
}
static int F_19 ( struct V_4 * V_5 , T_1 V_14 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_6 ;
T_1 V_7 ;
V_6 = ( ++ V_14 / V_16 ) + 1 ;
V_7 = ( V_14 % V_16 ) ;
F_3 ( V_5 , V_6 , V_7 , 0 , 0 ) ;
F_9 ( V_33 , V_34 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
static inline T_1 F_20 ( struct V_35 * V_36 )
{
return 0 ;
}
static inline struct V_37 * F_21 ( void * V_38 )
{
return (struct V_37 * ) V_38 ;
}
static inline struct V_35 * F_22 ( void * V_38 )
{
return (struct V_35 * ) V_38 ;
}
static int F_23 ( struct V_4 * V_5 , void * V_38 , T_1 V_14 ,
T_1 V_15 , T_1 T_3 * V_39 )
{
struct V_37 * V_36 ;
T_1 V_40 , V_41 ;
struct V_3 * V_10 = F_2 ( V_5 ) ;
V_36 = F_21 ( V_38 ) ;
V_41 = F_24 ( & V_40 , V_39 , sizeof( V_40 ) ) ;
F_12 ( V_5 , V_14 , V_15 ) ;
F_9 ( V_42 , V_36 -> V_43 ) ;
F_9 ( V_44 , V_36 -> V_45 ) ;
F_9 ( V_46 , V_36 -> V_47 ) ;
F_9 ( V_48 , V_36 -> V_49 ) ;
F_9 ( V_50 , V_36 -> V_51 ) ;
F_9 ( V_52 , V_36 -> V_53 ) ;
F_9 ( V_54 , V_36 -> V_55 ) ;
F_9 ( V_56 , V_36 -> V_57 ) ;
F_9 ( V_58 , V_36 -> V_59 ) ;
F_9 ( V_60 , V_36 -> V_61 ) ;
F_9 ( V_62 , V_36 -> V_63 ) ;
F_9 ( V_64 ,
V_36 -> V_65 ) ;
if ( V_41 > 0 )
F_9 ( V_66 , V_40 ) ;
F_9 ( V_67 , V_36 -> V_68 ) ;
F_9 ( V_69 , V_36 -> V_70 ) ;
F_9 ( V_71 , V_36 -> V_72 ) ;
F_9 ( V_73 , V_36 -> V_74 ) ;
F_9 ( V_75 , V_36 -> V_76 ) ;
F_9 ( V_77 , V_36 -> V_78 ) ;
F_9 ( V_79 , V_36 -> V_80 ) ;
F_9 ( V_81 , V_36 -> V_82 ) ;
F_9 ( V_83 , V_36 -> V_84 ) ;
F_9 ( V_85 , V_36 -> V_86 ) ;
F_9 ( V_87 , V_36 -> V_88 ) ;
F_9 ( V_89 , V_36 -> V_90 ) ;
F_9 ( V_91 , V_36 -> V_92 ) ;
F_9 ( V_93 , V_36 -> V_94 ) ;
F_9 ( V_95 , V_36 -> V_96 ) ;
F_9 ( V_97 , V_36 -> V_98 ) ;
F_9 ( V_99 , V_36 -> V_100 ) ;
F_9 ( V_101 , V_36 -> V_102 ) ;
F_9 ( V_103 , V_36 -> V_104 ) ;
F_9 ( V_105 , V_36 -> V_106 ) ;
F_9 ( V_107 , V_36 -> V_108 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 , void * V_38 )
{
return 0 ;
}
static bool F_26 ( struct V_4 * V_5 , T_2 V_109 ,
T_1 V_14 , T_1 V_15 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_110 ;
bool V_111 = false ;
T_1 V_112 , V_113 ;
F_12 ( V_5 , V_14 , V_15 ) ;
V_110 = F_16 ( V_107 ) ;
if ( V_110 ) {
V_112 = F_27 ( V_109 >> 8 ) ;
V_113 = F_28 ( V_109 >> 8 ) ;
if ( V_112 == F_16 ( V_58 ) &&
V_113 == F_16 ( V_60 ) )
V_111 = true ;
}
F_13 ( V_5 ) ;
return V_111 ;
}
static bool F_29 ( struct V_4 * V_5 , void * V_38 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
struct V_35 * V_36 ;
T_1 V_114 ;
T_1 V_115 ;
V_36 = F_22 ( V_38 ) ;
V_114 = F_20 ( V_36 ) ;
V_115 = F_16 ( V_114 + V_116 ) ;
if ( V_115 & V_117 )
return true ;
return false ;
}
static int F_30 ( struct V_4 * V_5 , T_1 V_118 ,
unsigned int V_119 , T_1 V_14 ,
T_1 V_15 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_120 ;
F_12 ( V_5 , V_14 , V_15 ) ;
F_9 ( V_99 , V_118 ) ;
while ( true ) {
V_120 = F_16 ( V_107 ) ;
if ( V_120 & V_121 )
break;
if ( V_119 == 0 ) {
F_31 ( L_1 ,
V_120 ) ;
F_13 ( V_5 ) ;
return - V_122 ;
}
F_32 ( 20 ) ;
V_119 -= 20 ;
}
F_13 ( V_5 ) ;
return 0 ;
}
static int F_33 ( struct V_4 * V_5 , void * V_38 ,
unsigned int V_119 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
struct V_35 * V_36 ;
T_1 V_114 ;
T_1 V_120 ;
V_36 = F_22 ( V_38 ) ;
V_114 = F_20 ( V_36 ) ;
V_120 = F_16 ( V_114 + V_116 ) ;
V_120 = V_120 & ~ V_117 ;
F_9 ( V_114 + V_116 , V_120 ) ;
while ( true ) {
V_120 = F_16 ( V_114 + V_123 ) ;
if ( V_120 & V_124 )
break;
if ( V_119 == 0 )
return - V_122 ;
F_32 ( 20 ) ;
V_119 -= 20 ;
}
F_9 ( V_114 + V_125 , 0 ) ;
F_9 ( V_114 + V_126 , 0 ) ;
F_9 ( V_114 + V_127 , 0 ) ;
F_9 ( V_114 + V_128 , 0 ) ;
return 0 ;
}
static bool F_34 ( struct V_4 * V_5 ,
T_4 V_9 )
{
T_1 V_129 ;
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
V_129 = F_16 ( V_28 + V_9 ) ;
return V_129 & V_27 ;
}
static T_5 F_35 ( struct V_4 * V_5 ,
T_4 V_9 )
{
T_1 V_129 ;
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
V_129 = F_16 ( V_28 + V_9 ) ;
return V_129 & V_27 ;
}
static void F_36 ( struct V_4 * V_5 , T_4 V_9 )
{
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
F_9 ( V_130 , 1 << V_9 ) ;
}
static int F_37 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_38 ( struct V_4 * V_5 ,
unsigned int V_131 ,
T_1 V_132 ,
T_1 V_133 ,
T_1 V_134 )
{
return 0 ;
}
static int F_39 ( struct V_4 * V_5 ,
T_1 V_135 ,
T_1 V_136 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_137 = 0 ;
F_8 ( & V_10 -> V_138 ) ;
F_9 ( V_139 , V_135 ) ;
F_9 ( V_140 , V_136 ) ;
V_137 = F_40 ( V_137 , V_141 ,
V_142 , 1 ) ;
V_137 = F_40 ( V_137 , V_141 ,
V_143 , 1 ) ;
V_137 = F_40 ( V_137 , V_141 ,
V_144 , 1 ) ;
F_9 ( V_139 , V_137 ) ;
F_11 ( & V_10 -> V_138 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_4 * V_5 ,
unsigned int V_131 ,
unsigned int V_145 )
{
return 0 ;
}
static T_5 F_42 ( struct V_4 * V_5 , enum V_146 type )
{
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
const union V_147 * V_148 ;
F_43 ( V_5 == NULL ) ;
switch ( type ) {
case V_149 :
V_148 = ( const union V_147 * )
V_10 -> V_150 . V_151 -> V_137 ;
break;
case V_152 :
V_148 = ( const union V_147 * )
V_10 -> V_150 . V_153 -> V_137 ;
break;
case V_154 :
V_148 = ( const union V_147 * )
V_10 -> V_150 . V_155 -> V_137 ;
break;
case V_156 :
V_148 = ( const union V_147 * )
V_10 -> V_150 . V_157 -> V_137 ;
break;
case V_158 :
V_148 = ( const union V_147 * )
V_10 -> V_150 . V_159 -> V_137 ;
break;
case V_160 :
V_148 = ( const union V_147 * )
V_10 -> V_150 . V_161 -> V_137 ;
break;
case V_162 :
V_148 = ( const union V_147 * )
V_10 -> V_163 . V_164 [ 0 ] . V_165 -> V_137 ;
break;
case V_166 :
V_148 = ( const union V_147 * )
V_10 -> V_163 . V_164 [ 1 ] . V_165 -> V_137 ;
break;
default:
return 0 ;
}
if ( V_148 == NULL )
return 0 ;
return V_148 -> V_167 . V_168 ;
}
