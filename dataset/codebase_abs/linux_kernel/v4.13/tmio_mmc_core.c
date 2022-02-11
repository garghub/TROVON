static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_6 ( V_2 , V_4 ) ;
}
static inline void F_2 ( struct V_1 * V_2 , bool V_7 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_7 ( V_2 , V_7 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
if ( V_2 -> V_5 ) {
V_2 -> V_5 -> V_10 ( V_2 , V_9 ) ;
} else {
V_2 -> V_11 = NULL ;
V_2 -> V_12 = NULL ;
}
}
static inline void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_13 ( V_2 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 -> abort ( V_2 ) ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_14 )
{
V_2 -> V_15 &= ~ ( V_14 & V_16 ) ;
F_7 ( V_2 , V_17 , V_2 -> V_15 ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_14 )
{
V_2 -> V_15 |= ( V_14 & V_16 ) ;
F_7 ( V_2 , V_17 , V_2 -> V_15 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_14 )
{
F_7 ( V_2 , V_18 , ~ V_14 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_19 = V_4 -> V_19 ;
V_2 -> V_20 = V_4 -> V_21 ;
V_2 -> V_22 = V_4 -> V_21 ;
V_2 -> V_23 = 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
V_2 -> V_20 = F_12 ( V_2 -> V_20 ) ;
V_2 -> V_23 = 0 ;
return -- V_2 -> V_19 ;
}
static void F_13 ( T_1 V_24 )
{
int V_14 = 0 ;
F_14 ( L_1 , V_24 ) ;
F_15 ( V_25 , V_24 , V_14 ) ;
F_15 ( V_26 , V_24 , V_14 ) ;
F_15 ( V_27 , V_24 , V_14 ) ;
F_15 ( V_28 , V_24 , V_14 ) ;
F_15 ( V_29 , V_24 , V_14 ) ;
F_15 ( V_30 , V_24 , V_14 ) ;
F_15 ( V_31 , V_24 , V_14 ) ;
F_15 ( V_32 , V_24 , V_14 ) ;
F_15 ( V_33 , V_24 , V_14 ) ;
F_15 ( V_34 , V_24 , V_14 ) ;
F_15 ( V_35 , V_24 , V_14 ) ;
F_15 ( V_36 , V_24 , V_14 ) ;
F_15 ( V_37 , V_24 , V_14 ) ;
F_15 ( V_38 , V_24 , V_14 ) ;
F_15 ( V_39 , V_24 , V_14 ) ;
F_15 ( V_40 , V_24 , V_14 ) ;
F_15 ( V_41 , V_24 , V_14 ) ;
F_15 ( V_42 , V_24 , V_14 ) ;
F_15 ( V_43 , V_24 , V_14 ) ;
F_15 ( V_44 , V_24 , V_14 ) ;
F_15 ( V_45 , V_24 , V_14 ) ;
F_16 ( L_2 ) ;
}
static void F_17 ( struct V_46 * V_47 , int V_7 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
if ( V_7 && ! V_2 -> V_48 ) {
T_2 V_49 ;
F_19 ( F_20 ( V_47 ) ) ;
V_2 -> V_48 = true ;
V_2 -> V_50 = V_51 & ~ V_52 ;
V_49 = F_21 ( V_2 , V_53 ) & ~ V_51 ;
if ( V_2 -> V_9 -> V_54 & V_55 )
V_49 |= V_56 ;
F_22 ( V_2 , V_53 , V_49 ) ;
F_22 ( V_2 , V_57 , V_2 -> V_50 ) ;
} else if ( ! V_7 && V_2 -> V_48 ) {
V_2 -> V_50 = V_51 ;
F_22 ( V_2 , V_57 , V_2 -> V_50 ) ;
V_2 -> V_48 = false ;
F_23 ( F_20 ( V_47 ) ) ;
F_24 ( F_20 ( V_47 ) ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_58 , V_59 |
F_21 ( V_2 , V_58 ) ) ;
F_26 ( V_2 -> V_9 -> V_54 & V_60 ? 1 : 10 ) ;
if ( V_2 -> V_9 -> V_54 & V_61 ) {
F_22 ( V_2 , V_62 , 0x0100 ) ;
F_26 ( 10 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 -> V_54 & V_61 ) {
F_22 ( V_2 , V_62 , 0x0000 ) ;
F_26 ( 10 ) ;
}
F_22 ( V_2 , V_58 , ~ V_59 &
F_21 ( V_2 , V_58 ) ) ;
F_26 ( V_2 -> V_9 -> V_54 & V_60 ? 5 : 10 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
unsigned int V_63 )
{
T_1 V_64 = 0 , clock ;
if ( V_63 == 0 ) {
F_27 ( V_2 ) ;
return;
}
if ( V_2 -> V_65 )
clock = V_2 -> V_65 ( V_2 , V_63 ) / 512 ;
else
clock = V_2 -> V_47 -> V_66 ;
for ( V_64 = 0x80000080 ; V_63 >= ( clock << 1 ) ; V_64 >>= 1 )
clock <<= 1 ;
if ( ( V_2 -> V_9 -> V_54 & V_67 ) && ( ( V_64 >> 22 ) & 0x1 ) )
V_64 |= 0xff ;
if ( V_2 -> V_68 )
V_2 -> V_68 ( V_2 -> V_69 , ( V_64 >> 22 ) & 1 ) ;
F_22 ( V_2 , V_58 , ~ V_59 &
F_21 ( V_2 , V_58 ) ) ;
F_22 ( V_2 , V_58 , V_64 & V_70 ) ;
if ( ! ( V_2 -> V_9 -> V_54 & V_60 ) )
F_26 ( 10 ) ;
F_25 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_71 , 0x0000 ) ;
if ( V_2 -> V_9 -> V_54 & V_61 )
F_22 ( V_2 , V_72 , 0x0000 ) ;
F_26 ( 10 ) ;
F_22 ( V_2 , V_71 , 0x0001 ) ;
if ( V_2 -> V_9 -> V_54 & V_61 )
F_22 ( V_2 , V_72 , 0x0001 ) ;
F_26 ( 10 ) ;
if ( V_2 -> V_9 -> V_54 & V_73 ) {
F_22 ( V_2 , V_57 , V_2 -> V_50 ) ;
F_22 ( V_2 , V_74 , 0x0001 ) ;
}
}
static void F_30 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_31 ( V_76 , struct V_1 ,
V_77 . V_76 ) ;
struct V_78 * V_79 ;
unsigned long V_54 ;
F_32 ( & V_2 -> V_80 , V_54 ) ;
V_79 = V_2 -> V_79 ;
if ( F_33 ( V_79 ) ||
F_34 ( V_2 -> V_81 +
F_35 ( V_82 ) ) ) {
F_36 ( & V_2 -> V_80 , V_54 ) ;
return;
}
F_37 ( & V_2 -> V_69 -> V_83 ,
L_3 ,
V_79 -> V_84 -> V_85 ) ;
if ( V_2 -> V_4 )
V_2 -> V_4 -> error = - V_86 ;
else if ( V_2 -> V_84 )
V_2 -> V_84 -> error = - V_86 ;
else
V_79 -> V_84 -> error = - V_86 ;
V_2 -> V_84 = NULL ;
V_2 -> V_4 = NULL ;
V_2 -> V_87 = false ;
F_36 ( & V_2 -> V_80 , V_54 ) ;
F_29 ( V_2 ) ;
V_2 -> V_79 = NULL ;
F_5 ( V_2 ) ;
F_38 ( V_2 -> V_47 , V_79 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_88 * V_84 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_89 = V_84 -> V_85 ;
T_1 V_90 = V_91 ;
if ( V_84 -> V_85 == V_92 && ! V_84 -> V_93 ) {
F_22 ( V_2 , V_94 , V_95 ) ;
return 0 ;
}
switch ( F_40 ( V_84 ) ) {
case V_96 : V_89 |= V_97 ; break;
case V_98 :
case V_99 :
V_89 |= V_100 ; break;
case V_101 : V_89 |= V_102 ; break;
case V_103 : V_89 |= V_104 ; break;
case V_105 : V_89 |= V_106 ; break;
default:
F_14 ( L_4 , F_40 ( V_84 ) ) ;
return - V_107 ;
}
V_2 -> V_84 = V_84 ;
if ( V_4 ) {
V_89 |= V_108 ;
if ( V_4 -> V_109 > 1 ) {
F_22 ( V_2 , V_94 , V_110 ) ;
V_89 |= V_111 ;
if ( ( V_2 -> V_9 -> V_54 & V_112 ) &&
( V_84 -> V_85 == V_113 || V_2 -> V_79 -> V_114 ) )
V_89 |= V_115 ;
}
if ( V_4 -> V_54 & V_116 )
V_89 |= V_117 ;
}
if ( ! V_2 -> V_118 )
V_90 &= ~ ( V_119 | V_120 ) ;
F_6 ( V_2 , V_90 ) ;
F_7 ( V_2 , V_121 , V_84 -> V_93 ) ;
F_22 ( V_2 , V_122 , V_89 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
unsigned short * V_123 ,
unsigned int V_124 )
{
int V_125 = V_2 -> V_4 -> V_54 & V_116 ;
T_3 * V_126 ;
if ( V_2 -> V_9 -> V_54 & V_127 ) {
T_1 V_4 = 0 ;
T_1 * V_128 = ( T_1 * ) V_123 ;
if ( V_125 )
F_42 ( V_2 , V_129 , V_128 ,
V_124 >> 2 ) ;
else
F_43 ( V_2 , V_129 , V_128 ,
V_124 >> 2 ) ;
if ( ! ( V_124 & 0x3 ) )
return;
V_128 += V_124 >> 2 ;
V_124 %= 4 ;
if ( V_125 ) {
F_42 ( V_2 , V_129 , & V_4 , 1 ) ;
memcpy ( V_128 , & V_4 , V_124 ) ;
} else {
memcpy ( & V_4 , V_128 , V_124 ) ;
F_43 ( V_2 , V_129 , & V_4 , 1 ) ;
}
return;
}
if ( V_125 )
F_44 ( V_2 , V_129 , V_123 , V_124 >> 1 ) ;
else
F_45 ( V_2 , V_129 , V_123 , V_124 >> 1 ) ;
if ( ! ( V_124 & 0x1 ) )
return;
V_126 = ( T_3 * ) ( V_123 + ( V_124 >> 1 ) ) ;
if ( V_125 )
* V_126 = F_21 ( V_2 , V_129 ) & 0xff ;
else
F_22 ( V_2 , V_129 , * V_126 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void * V_130 ;
unsigned short * V_123 ;
unsigned int V_124 ;
unsigned long V_54 ;
if ( ( V_2 -> V_11 || V_2 -> V_12 ) && ! V_2 -> V_87 ) {
F_47 ( L_5 ) ;
return;
} else if ( ! V_4 ) {
F_14 ( L_6 ) ;
return;
}
V_130 = F_48 ( V_2 -> V_20 , & V_54 ) ;
V_123 = ( unsigned short * ) ( V_130 + V_2 -> V_23 ) ;
V_124 = V_2 -> V_20 -> V_131 - V_2 -> V_23 ;
if ( V_124 > V_4 -> V_132 )
V_124 = V_4 -> V_132 ;
F_14 ( L_7 ,
V_124 , V_2 -> V_23 , V_4 -> V_54 ) ;
F_41 ( V_2 , V_123 , V_124 ) ;
V_2 -> V_23 += V_124 ;
F_49 ( V_2 -> V_20 , & V_54 , V_130 ) ;
if ( V_2 -> V_23 == V_2 -> V_20 -> V_131 )
F_11 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 == & V_2 -> V_133 ) {
unsigned long V_54 ;
void * V_134 = F_48 ( V_2 -> V_22 , & V_54 ) ;
memcpy ( V_134 , V_2 -> V_135 , V_2 -> V_133 . V_131 ) ;
F_49 ( V_2 -> V_22 , & V_54 , V_134 ) ;
}
}
void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_88 * V_136 ;
V_2 -> V_4 = NULL ;
if ( ! V_4 ) {
F_37 ( & V_2 -> V_69 -> V_83 , L_8 ) ;
return;
}
V_136 = V_4 -> V_136 ;
if ( ! V_4 -> error )
V_4 -> V_137 = V_4 -> V_109 * V_4 -> V_132 ;
else
V_4 -> V_137 = 0 ;
F_14 ( L_9 ) ;
if ( V_4 -> V_54 & V_116 ) {
if ( V_2 -> V_12 && ! V_2 -> V_87 )
F_50 ( V_2 ) ;
F_52 ( & V_2 -> V_69 -> V_83 , L_10 ,
V_2 -> V_79 ) ;
} else {
F_52 ( & V_2 -> V_69 -> V_83 , L_11 ,
V_2 -> V_79 ) ;
}
if ( V_136 && ! V_2 -> V_79 -> V_114 ) {
if ( V_136 -> V_85 != V_92 || V_136 -> V_93 )
F_53 ( & V_2 -> V_69 -> V_83 , L_12 ,
V_136 -> V_85 , V_136 -> V_93 ) ;
V_136 -> V_138 [ 0 ] = F_54 ( V_2 , V_139 ) ;
F_22 ( V_2 , V_94 , 0 ) ;
}
F_55 ( & V_2 -> V_140 ) ;
}
static void F_56 ( struct V_1 * V_2 , unsigned int V_141 )
{
struct V_3 * V_4 ;
F_57 ( & V_2 -> V_80 ) ;
V_4 = V_2 -> V_4 ;
if ( ! V_4 )
goto V_142;
if ( V_141 & V_143 || V_141 & V_144 ||
V_141 & V_145 )
V_4 -> error = - V_146 ;
if ( V_2 -> V_11 && ( V_4 -> V_54 & V_147 ) && ! V_2 -> V_87 ) {
T_1 V_24 = F_54 ( V_2 , V_18 ) ;
bool V_140 = false ;
if ( V_2 -> V_9 -> V_54 & V_148 ) {
if ( V_24 & V_149 )
V_140 = true ;
} else {
if ( ! ( V_24 & V_150 ) )
V_140 = true ;
}
if ( V_140 ) {
F_8 ( V_2 , V_151 ) ;
F_58 ( & V_2 -> V_152 ) ;
}
} else if ( V_2 -> V_12 && ( V_4 -> V_54 & V_116 ) && ! V_2 -> V_87 ) {
F_8 ( V_2 , V_151 ) ;
F_58 ( & V_2 -> V_152 ) ;
} else {
F_51 ( V_2 ) ;
F_8 ( V_2 , V_153 | V_154 ) ;
}
V_142:
F_59 ( & V_2 -> V_80 ) ;
}
static void F_60 ( struct V_1 * V_2 , unsigned int V_141 )
{
struct V_88 * V_84 = V_2 -> V_84 ;
int V_14 , V_155 ;
F_57 ( & V_2 -> V_80 ) ;
if ( ! V_2 -> V_84 ) {
F_14 ( L_13 ) ;
goto V_142;
}
for ( V_14 = 3 , V_155 = V_139 ; V_14 >= 0 ; V_14 -- , V_155 += 4 )
V_84 -> V_138 [ V_14 ] = F_54 ( V_2 , V_155 ) ;
if ( V_84 -> V_54 & V_156 ) {
V_84 -> V_138 [ 0 ] = ( V_84 -> V_138 [ 0 ] << 8 ) | ( V_84 -> V_138 [ 1 ] >> 24 ) ;
V_84 -> V_138 [ 1 ] = ( V_84 -> V_138 [ 1 ] << 8 ) | ( V_84 -> V_138 [ 2 ] >> 24 ) ;
V_84 -> V_138 [ 2 ] = ( V_84 -> V_138 [ 2 ] << 8 ) | ( V_84 -> V_138 [ 3 ] >> 24 ) ;
V_84 -> V_138 [ 3 ] <<= 8 ;
} else if ( V_84 -> V_54 & V_105 ) {
V_84 -> V_138 [ 0 ] = V_84 -> V_138 [ 3 ] ;
}
if ( V_141 & V_157 )
V_84 -> error = - V_86 ;
else if ( ( V_141 & V_143 && V_84 -> V_54 & V_158 ) ||
V_141 & V_144 ||
V_141 & V_159 )
V_84 -> error = - V_146 ;
if ( V_2 -> V_4 && ( ! V_84 -> error || V_84 -> error == - V_146 ) ) {
if ( V_2 -> V_4 -> V_54 & V_116 ) {
if ( V_2 -> V_87 || ! V_2 -> V_12 )
F_6 ( V_2 , V_153 ) ;
else
F_61 ( & V_2 -> V_160 ) ;
} else {
if ( V_2 -> V_87 || ! V_2 -> V_11 )
F_6 ( V_2 , V_154 ) ;
else
F_61 ( & V_2 -> V_160 ) ;
}
} else {
F_55 ( & V_2 -> V_140 ) ;
}
V_142:
F_59 ( & V_2 -> V_80 ) ;
}
static bool F_62 ( struct V_1 * V_2 ,
int V_161 , int V_24 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
if ( V_161 & ( V_120 | V_119 ) ) {
F_9 ( V_2 , V_120 |
V_119 ) ;
if ( ( ( ( V_161 & V_119 ) && V_47 -> V_162 ) ||
( ( V_161 & V_120 ) && ! V_47 -> V_162 ) ) &&
! F_63 ( & V_47 -> V_163 . V_76 ) )
F_64 ( V_2 -> V_47 , F_35 ( 100 ) ) ;
return true ;
}
return false ;
}
static bool F_65 ( struct V_1 * V_2 , int V_161 ,
int V_24 )
{
if ( V_161 & ( V_164 | V_157 ) ) {
F_9 ( V_2 , V_164 |
V_157 ) ;
F_60 ( V_2 , V_24 ) ;
return true ;
}
if ( V_161 & ( V_165 | V_166 ) ) {
F_9 ( V_2 , V_165 | V_166 ) ;
F_46 ( V_2 ) ;
return true ;
}
if ( V_161 & V_151 ) {
F_9 ( V_2 , V_151 ) ;
F_56 ( V_2 , V_24 ) ;
return true ;
}
return false ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned int V_161 , V_24 ;
unsigned int V_49 ;
if ( ! ( V_9 -> V_54 & V_73 ) )
return;
V_24 = F_21 ( V_2 , V_53 ) ;
V_161 = V_24 & V_51 & ~ V_2 -> V_50 ;
V_49 = V_24 & ~ V_51 ;
if ( V_9 -> V_54 & V_55 )
V_49 |= V_56 ;
F_22 ( V_2 , V_53 , V_49 ) ;
if ( V_47 -> V_167 & V_168 && V_161 & V_52 )
F_67 ( V_47 ) ;
}
T_4 F_68 ( int V_169 , void * V_170 )
{
struct V_1 * V_2 = V_170 ;
unsigned int V_161 , V_24 ;
V_24 = F_54 ( V_2 , V_18 ) ;
V_161 = V_24 & V_16 & ~ V_2 -> V_15 ;
F_13 ( V_24 ) ;
F_13 ( V_161 ) ;
F_7 ( V_2 , V_18 , V_16 ) ;
if ( F_62 ( V_2 , V_161 , V_24 ) )
return V_171 ;
if ( F_65 ( V_2 , V_161 , V_24 ) )
return V_171 ;
F_66 ( V_2 ) ;
return V_171 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
F_14 ( L_14 ,
V_4 -> V_132 , V_4 -> V_109 ) ;
if ( V_2 -> V_47 -> V_172 . V_173 == V_174 ||
V_2 -> V_47 -> V_172 . V_173 == V_175 ) {
int V_176 = V_9 -> V_54 & V_177 ;
if ( V_4 -> V_132 < 2 || ( V_4 -> V_132 < 4 && ! V_176 ) ) {
F_47 ( L_15 ,
F_70 ( V_2 -> V_47 ) , V_4 -> V_132 ) ;
return - V_107 ;
}
}
F_10 ( V_2 , V_4 ) ;
V_2 -> V_4 = V_4 ;
F_22 ( V_2 , V_178 , V_4 -> V_132 ) ;
F_22 ( V_2 , V_179 , V_4 -> V_109 ) ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_71 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
if ( V_2 -> V_180 )
V_2 -> V_180 ( V_2 ) ;
}
static int F_72 ( struct V_46 * V_47 , T_1 V_85 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
int V_14 , V_181 = 0 ;
if ( ! V_2 -> V_182 || ! V_2 -> V_183 )
goto V_142;
V_2 -> V_184 = V_2 -> V_182 ( V_2 ) ;
if ( ! V_2 -> V_184 )
goto V_142;
if ( V_2 -> V_184 * 2 >= sizeof( V_2 -> V_185 ) * V_186 ) {
F_73 ( & V_2 -> V_69 -> V_83 ,
L_16 ) ;
goto V_142;
}
F_74 ( V_2 -> V_185 , V_2 -> V_184 * 2 ) ;
for ( V_14 = 0 ; V_14 < 2 * V_2 -> V_184 ; V_14 ++ ) {
if ( V_2 -> V_187 )
V_2 -> V_187 ( V_2 , V_14 % V_2 -> V_184 ) ;
V_181 = F_75 ( V_47 , V_85 , NULL ) ;
if ( V_181 && V_181 != - V_146 )
goto V_142;
if ( V_181 == 0 )
F_76 ( V_14 , V_2 -> V_185 ) ;
F_77 ( 1 ) ;
}
V_181 = V_2 -> V_183 ( V_2 ) ;
V_142:
if ( V_181 < 0 ) {
F_37 ( & V_2 -> V_69 -> V_83 , L_17 ) ;
F_71 ( V_47 ) ;
}
return V_181 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_88 * V_84 ;
int V_181 ;
if ( V_79 -> V_114 && V_2 -> V_84 != V_79 -> V_114 ) {
V_84 = V_79 -> V_114 ;
} else {
V_84 = V_79 -> V_84 ;
if ( V_79 -> V_4 ) {
V_181 = F_69 ( V_2 , V_79 -> V_4 ) ;
if ( V_181 )
goto V_188;
}
}
V_181 = F_39 ( V_2 , V_84 ) ;
if ( V_181 )
goto V_188;
F_79 ( & V_2 -> V_77 ,
F_35 ( V_82 ) ) ;
return;
V_188:
V_2 -> V_87 = false ;
V_2 -> V_79 = NULL ;
V_79 -> V_84 -> error = V_181 ;
F_38 ( V_2 -> V_47 , V_79 ) ;
}
static void F_80 ( struct V_46 * V_47 , struct V_78 * V_79 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
unsigned long V_54 ;
F_32 ( & V_2 -> V_80 , V_54 ) ;
if ( V_2 -> V_79 ) {
F_14 ( L_18 ) ;
if ( F_81 ( V_2 -> V_79 ) ) {
F_36 ( & V_2 -> V_80 , V_54 ) ;
V_79 -> V_84 -> error = - V_189 ;
F_38 ( V_47 , V_79 ) ;
return;
}
}
V_2 -> V_81 = V_190 ;
F_82 () ;
V_2 -> V_79 = V_79 ;
F_36 ( & V_2 -> V_80 , V_54 ) ;
F_78 ( V_2 , V_79 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_78 * V_79 ;
unsigned long V_54 ;
F_32 ( & V_2 -> V_80 , V_54 ) ;
V_79 = V_2 -> V_79 ;
if ( F_33 ( V_79 ) ) {
F_36 ( & V_2 -> V_80 , V_54 ) ;
return;
}
if ( V_2 -> V_84 != V_79 -> V_114 ) {
V_2 -> V_84 = NULL ;
V_2 -> V_4 = NULL ;
V_2 -> V_87 = false ;
V_2 -> V_79 = NULL ;
}
F_84 ( & V_2 -> V_77 ) ;
F_36 ( & V_2 -> V_80 , V_54 ) ;
if ( V_79 -> V_84 -> error || ( V_79 -> V_4 && V_79 -> V_4 -> error ) )
F_5 ( V_2 ) ;
if ( V_2 -> V_191 )
V_2 -> V_191 ( V_2 ) ;
if ( V_2 -> V_79 ) {
F_78 ( V_2 , V_79 ) ;
return;
}
F_38 ( V_2 -> V_47 , V_79 ) ;
}
static void F_85 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_31 ( V_76 , struct V_1 ,
V_140 ) ;
F_83 ( V_2 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_192 )
return - V_193 ;
return V_2 -> V_192 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
if ( V_2 -> V_194 )
V_2 -> V_194 ( V_2 ) ;
}
static void F_88 ( struct V_1 * V_2 , unsigned short V_195 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
int V_181 = 0 ;
if ( V_2 -> V_196 )
V_2 -> V_196 ( V_2 -> V_69 , 1 ) ;
if ( ! F_81 ( V_47 -> V_197 . V_198 ) ) {
V_181 = F_89 ( V_47 , V_47 -> V_197 . V_198 , V_195 ) ;
F_90 ( 200 ) ;
}
if ( ! F_81 ( V_47 -> V_197 . V_199 ) && ! V_181 ) {
V_181 = F_91 ( V_47 -> V_197 . V_199 ) ;
F_90 ( 200 ) ;
}
if ( V_181 < 0 )
F_52 ( & V_2 -> V_69 -> V_83 , L_19 ,
V_181 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
if ( ! F_81 ( V_47 -> V_197 . V_199 ) )
F_93 ( V_47 -> V_197 . V_199 ) ;
if ( ! F_81 ( V_47 -> V_197 . V_198 ) )
F_89 ( V_47 , V_47 -> V_197 . V_198 , 0 ) ;
if ( V_2 -> V_196 )
V_2 -> V_196 ( V_2 -> V_69 , 0 ) ;
}
static void F_94 ( struct V_1 * V_2 ,
unsigned char V_173 )
{
T_2 V_200 = F_21 ( V_2 , V_201 )
& ~ ( V_202 | V_203 ) ;
if ( V_173 == V_204 )
V_200 |= V_202 ;
else if ( V_173 == V_175 )
V_200 |= V_203 ;
F_22 ( V_2 , V_201 , V_200 ) ;
}
static void F_95 ( struct V_46 * V_47 , struct V_205 * V_172 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
struct V_206 * V_83 = & V_2 -> V_69 -> V_83 ;
unsigned long V_54 ;
F_96 ( & V_2 -> V_207 ) ;
F_32 ( & V_2 -> V_80 , V_54 ) ;
if ( V_2 -> V_79 ) {
if ( F_81 ( V_2 -> V_79 ) ) {
F_52 ( V_83 ,
L_20 ,
V_208 -> V_209 , F_97 ( V_208 ) ,
V_172 -> clock , V_172 -> V_210 ) ;
V_2 -> V_79 = F_98 ( - V_211 ) ;
} else {
F_52 ( V_83 ,
L_21 ,
V_208 -> V_209 , F_97 ( V_208 ) ,
V_2 -> V_79 -> V_84 -> V_85 , V_2 -> V_81 ,
V_190 ) ;
}
F_36 ( & V_2 -> V_80 , V_54 ) ;
F_99 ( & V_2 -> V_207 ) ;
return;
}
V_2 -> V_79 = F_98 ( - V_212 ) ;
F_36 ( & V_2 -> V_80 , V_54 ) ;
switch ( V_172 -> V_210 ) {
case V_213 :
F_92 ( V_2 ) ;
F_27 ( V_2 ) ;
break;
case V_214 :
F_88 ( V_2 , V_172 -> V_195 ) ;
F_28 ( V_2 , V_172 -> clock ) ;
F_94 ( V_2 , V_172 -> V_173 ) ;
break;
case V_215 :
F_28 ( V_2 , V_172 -> clock ) ;
F_94 ( V_2 , V_172 -> V_173 ) ;
break;
}
F_90 ( 140 ) ;
if ( F_100 ( V_2 -> V_79 ) == - V_211 )
F_52 ( & V_2 -> V_69 -> V_83 ,
L_22 ,
V_208 -> V_209 , F_97 ( V_208 ) ,
V_172 -> clock , V_172 -> V_210 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_216 = V_172 -> clock ;
F_99 ( & V_2 -> V_207 ) ;
}
static int F_101 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_181 = F_102 ( V_47 ) ;
if ( V_181 >= 0 )
return V_181 ;
V_181 = ! ( ( V_9 -> V_54 & V_217 ) ||
( F_54 ( V_2 , V_18 ) & V_218 ) ) ;
return V_181 ;
}
static int F_103 ( struct V_219 * V_162 ,
unsigned int V_220 , int V_221 )
{
struct V_1 * V_2 = F_18 ( V_162 -> V_2 ) ;
if ( V_2 -> V_222 )
return V_2 -> V_222 ( V_162 , V_220 , V_221 ) ;
return V_221 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_46 * V_47 = V_2 -> V_47 ;
F_105 ( V_47 ) ;
if ( ! V_47 -> V_223 )
V_47 -> V_223 = V_9 -> V_224 ;
if ( ! V_47 -> V_223 )
return - V_225 ;
return 0 ;
}
static void F_106 ( struct V_226 * V_69 ,
struct V_8 * V_9 )
{
const struct V_227 * V_228 = V_69 -> V_83 . V_229 ;
if ( ! V_228 )
return;
if ( F_107 ( V_228 , L_23 , NULL ) )
V_9 -> V_54 |= V_217 ;
}
struct V_1 *
F_108 ( struct V_226 * V_69 )
{
struct V_1 * V_2 ;
struct V_46 * V_47 ;
V_47 = F_109 ( sizeof( struct V_1 ) , & V_69 -> V_83 ) ;
if ( ! V_47 )
return NULL ;
V_2 = F_18 ( V_47 ) ;
V_2 -> V_47 = V_47 ;
V_2 -> V_69 = V_69 ;
return V_2 ;
}
void F_110 ( struct V_1 * V_2 )
{
F_111 ( V_2 -> V_47 ) ;
}
int F_112 ( struct V_1 * V_230 ,
struct V_8 * V_9 ,
const struct V_231 * V_5 )
{
struct V_226 * V_69 = V_230 -> V_69 ;
struct V_46 * V_47 = V_230 -> V_47 ;
struct V_232 * V_233 ;
int V_181 ;
T_1 V_90 = V_91 ;
F_106 ( V_69 , V_9 ) ;
if ( ! ( V_9 -> V_54 & V_148 ) )
V_230 -> V_234 = NULL ;
V_233 = F_113 ( V_69 , V_235 , 0 ) ;
if ( ! V_233 )
return - V_107 ;
V_181 = F_114 ( V_47 ) ;
if ( V_181 < 0 )
return V_181 ;
V_230 -> V_9 = V_9 ;
F_115 ( V_69 , V_47 ) ;
V_230 -> V_196 = V_9 -> V_196 ;
V_230 -> V_68 = V_9 -> V_68 ;
V_181 = F_104 ( V_230 ) ;
if ( V_181 < 0 )
return V_181 ;
V_230 -> V_236 = F_116 ( & V_69 -> V_83 ,
V_233 -> V_6 , F_117 ( V_233 ) ) ;
if ( ! V_230 -> V_236 )
return - V_237 ;
V_238 . V_239 = V_230 -> V_239 ;
V_238 . V_240 =
V_230 -> V_240 ;
V_47 -> V_241 = & V_238 ;
V_47 -> V_167 |= V_242 | V_9 -> V_243 ;
V_47 -> V_244 |= V_9 -> V_245 ;
V_47 -> V_246 = 32 ;
V_47 -> V_247 = 512 ;
V_47 -> V_248 = ( V_249 / V_47 -> V_247 ) *
V_47 -> V_246 ;
V_47 -> V_250 = V_47 -> V_247 * V_47 -> V_248 ;
V_47 -> V_251 = V_47 -> V_250 ;
V_230 -> V_118 = ! ( V_9 -> V_54 & V_252 ||
V_47 -> V_167 & V_253 ||
! F_118 ( V_47 ) ) ;
if ( V_9 -> V_54 & V_60 )
V_230 -> V_118 = true ;
if ( F_86 ( V_230 ) < 0 ) {
V_47 -> V_254 = V_9 -> V_255 ;
V_47 -> V_66 = V_47 -> V_254 / 512 ;
}
if ( V_47 -> V_66 == 0 )
return - V_107 ;
if ( V_230 -> V_118 )
F_119 ( & V_69 -> V_83 ) ;
V_230 -> V_48 = false ;
if ( V_9 -> V_54 & V_73 )
V_230 -> V_50 = V_51 ;
F_27 ( V_230 ) ;
F_29 ( V_230 ) ;
V_230 -> V_15 = F_54 ( V_230 , V_17 ) ;
F_8 ( V_230 , V_256 ) ;
if ( ! V_230 -> V_12 )
V_90 |= V_153 ;
if ( ! V_230 -> V_11 )
V_90 |= V_154 ;
if ( ! V_230 -> V_118 )
V_90 &= ~ ( V_119 | V_120 ) ;
V_230 -> V_15 &= ~ V_90 ;
F_120 ( & V_230 -> V_80 ) ;
F_121 ( & V_230 -> V_207 ) ;
F_122 ( & V_230 -> V_77 , F_30 ) ;
F_123 ( & V_230 -> V_140 , F_85 ) ;
V_230 -> V_5 = V_5 ;
F_3 ( V_230 , V_9 ) ;
F_124 ( & V_69 -> V_83 ) ;
F_125 ( & V_69 -> V_83 , 50 ) ;
F_126 ( & V_69 -> V_83 ) ;
F_127 ( & V_69 -> V_83 ) ;
V_181 = F_128 ( V_47 ) ;
if ( V_181 < 0 ) {
F_129 ( V_230 ) ;
return V_181 ;
}
F_130 ( & V_69 -> V_83 , 100 ) ;
if ( V_9 -> V_54 & V_252 ) {
V_181 = F_131 ( V_47 , V_9 -> V_257 , 0 ) ;
if ( V_181 < 0 ) {
F_129 ( V_230 ) ;
return V_181 ;
}
F_132 ( V_47 ) ;
}
return 0 ;
}
void F_129 ( struct V_1 * V_2 )
{
struct V_226 * V_69 = V_2 -> V_69 ;
struct V_46 * V_47 = V_2 -> V_47 ;
if ( V_2 -> V_9 -> V_54 & V_73 )
F_22 ( V_2 , V_74 , 0x0000 ) ;
if ( ! V_2 -> V_118 )
F_19 ( & V_69 -> V_83 ) ;
F_133 ( & V_69 -> V_83 ) ;
F_134 ( V_47 ) ;
F_135 ( & V_2 -> V_140 ) ;
F_136 ( & V_2 -> V_77 ) ;
F_4 ( V_2 ) ;
F_137 ( & V_69 -> V_83 ) ;
F_138 ( & V_69 -> V_83 ) ;
F_87 ( V_2 ) ;
}
int F_139 ( struct V_206 * V_83 )
{
struct V_46 * V_47 = F_140 ( V_83 ) ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
F_8 ( V_2 , V_256 ) ;
if ( V_2 -> V_216 )
F_27 ( V_2 ) ;
F_87 ( V_2 ) ;
return 0 ;
}
static bool F_141 ( struct V_1 * V_2 )
{
return V_2 -> V_184 && F_142 ( V_2 -> V_47 ) ;
}
int F_143 ( struct V_206 * V_83 )
{
struct V_46 * V_47 = F_140 ( V_83 ) ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
F_29 ( V_2 ) ;
F_86 ( V_2 ) ;
if ( V_2 -> V_216 )
F_28 ( V_2 , V_2 -> V_216 ) ;
F_2 ( V_2 , true ) ;
if ( F_141 ( V_2 ) && V_2 -> V_183 ( V_2 ) )
F_37 ( & V_2 -> V_69 -> V_83 , L_24 ) ;
return 0 ;
}
