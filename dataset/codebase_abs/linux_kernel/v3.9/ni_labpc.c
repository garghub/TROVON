static inline unsigned int F_1 ( unsigned long V_1 )
{
return F_2 ( V_1 ) ;
}
static inline void F_3 ( unsigned int V_2 , unsigned long V_1 )
{
F_4 ( V_2 , V_1 ) ;
}
static inline unsigned int F_5 ( unsigned long V_1 )
{
return F_6 ( ( void V_3 * ) V_1 ) ;
}
static inline void F_7 ( unsigned int V_2 , unsigned long V_1 )
{
F_8 ( V_2 , ( void V_3 * ) V_1 ) ;
}
static inline int F_9 ( struct V_4 * V_5 ,
unsigned long V_6 ,
unsigned int V_7 ,
unsigned int V_8 , unsigned int V_9 )
{
if ( V_10 -> V_11 )
return F_10 ( ( void V_3 * ) V_6 , 0 ,
V_7 , V_8 , V_9 ) ;
else
return F_11 ( V_6 , 0 , V_7 , V_8 , V_9 ) ;
}
int F_12 ( struct V_4 * V_5 , unsigned long V_12 ,
unsigned int V_13 , unsigned int V_14 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_18 * V_19 ;
int V_20 ;
unsigned long V_21 ;
#ifdef F_13
unsigned long V_22 ;
#endif
short V_23 , V_24 ;
int V_25 ;
F_14 ( V_5 -> V_26 , L_1 , V_10 -> V_27 ) ;
if ( V_12 == 0 ) {
F_15 ( V_5 -> V_26 , L_2 ) ;
return - V_28 ;
}
if ( V_10 -> V_29 == V_30 ) {
if ( ! F_16 ( V_12 , V_31 , V_32 ) ) {
F_15 ( V_5 -> V_26 , L_3 ) ;
return - V_33 ;
}
}
V_5 -> V_12 = V_12 ;
if ( V_10 -> V_11 ) {
V_16 -> V_34 = F_5 ;
V_16 -> V_35 = F_7 ;
} else {
V_16 -> V_34 = F_1 ;
V_16 -> V_35 = F_3 ;
}
V_16 -> V_35 ( V_16 -> V_36 , V_5 -> V_12 + V_37 ) ;
V_16 -> V_35 ( V_16 -> V_38 , V_5 -> V_12 + V_39 ) ;
V_16 -> V_35 ( V_16 -> V_40 , V_5 -> V_12 + V_41 ) ;
V_16 -> V_35 ( V_16 -> V_42 , V_5 -> V_12 + V_43 ) ;
if ( V_10 -> V_44 == V_45 ) {
V_16 -> V_35 ( V_16 -> V_46 ,
V_5 -> V_12 + V_47 ) ;
V_16 -> V_35 ( V_16 -> V_48 ,
V_5 -> V_12 + V_49 ) ;
}
if ( V_13 ) {
V_21 = 0 ;
if ( V_10 -> V_29 == V_50
|| V_10 -> V_29 == V_51 )
V_21 |= V_52 ;
if ( F_17 ( V_13 , V_53 , V_21 ,
V_32 , V_5 ) ) {
F_15 ( V_5 -> V_26 , L_4 ,
V_13 ) ;
return - V_28 ;
}
}
V_5 -> V_13 = V_13 ;
#ifdef F_13
if ( V_14 > 3 ) {
F_15 ( V_5 -> V_26 , L_5 , V_14 ) ;
return - V_28 ;
} else if ( V_14 ) {
V_16 -> V_54 = F_18 ( V_55 ,
V_56 | V_57 ) ;
if ( V_16 -> V_54 == NULL )
return - V_58 ;
if ( F_19 ( V_14 , V_32 ) ) {
F_15 ( V_5 -> V_26 ,
L_6 ,
V_14 ) ;
return - V_28 ;
}
V_16 -> V_14 = V_14 ;
V_22 = F_20 () ;
F_21 ( V_16 -> V_14 ) ;
F_22 ( V_16 -> V_14 , V_59 ) ;
F_23 ( V_22 ) ;
}
#endif
V_5 -> V_60 = V_10 -> V_27 ;
V_25 = F_24 ( V_5 , 5 ) ;
if ( V_25 )
return V_25 ;
V_19 = & V_5 -> V_61 [ 0 ] ;
V_5 -> V_62 = V_19 ;
V_19 -> type = V_63 ;
V_19 -> V_64 =
V_65 | V_66 | V_67 | V_68 | V_69 ;
V_19 -> V_70 = 8 ;
V_19 -> V_71 = 8 ;
V_19 -> V_72 = ( 1 << 12 ) - 1 ;
V_19 -> V_73 = V_10 -> V_74 ;
V_19 -> V_75 = V_76 ;
V_19 -> V_77 = V_78 ;
V_19 -> V_79 = V_80 ;
V_19 -> V_81 = V_82 ;
V_19 = & V_5 -> V_61 [ 1 ] ;
if ( V_10 -> V_83 ) {
V_19 -> type = V_84 ;
V_19 -> V_64 = V_65 | V_85 | V_66 ;
V_19 -> V_70 = V_86 ;
V_19 -> V_72 = ( 1 << 12 ) - 1 ;
V_19 -> V_73 = & V_87 ;
V_19 -> V_79 = V_88 ;
V_19 -> V_89 = V_90 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_70 ; V_20 ++ ) {
V_16 -> V_91 [ V_20 ] = V_19 -> V_72 / 2 ;
V_23 = V_16 -> V_91 [ V_20 ] & 0xff ;
V_24 = ( V_16 -> V_91 [ V_20 ] >> 8 ) & 0xff ;
V_16 -> V_35 ( V_23 , V_5 -> V_12 + F_25 ( V_20 ) ) ;
V_16 -> V_35 ( V_24 , V_5 -> V_12 + F_26 ( V_20 ) ) ;
}
} else {
V_19 -> type = V_92 ;
}
V_19 = & V_5 -> V_61 [ 2 ] ;
if ( V_10 -> V_11 )
F_27 ( V_5 , V_19 , V_93 ,
( unsigned long ) ( V_5 -> V_12 + V_94 ) ) ;
else
F_27 ( V_5 , V_19 , NULL , V_5 -> V_12 + V_94 ) ;
V_19 = & V_5 -> V_61 [ 3 ] ;
if ( V_10 -> V_44 == V_45 ) {
V_19 -> type = V_95 ;
V_19 -> V_64 = V_65 | V_85 | V_96 ;
V_19 -> V_70 = 16 ;
V_19 -> V_72 = 0xff ;
V_19 -> V_79 = V_97 ;
V_19 -> V_89 = V_98 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_70 ; V_20 ++ )
F_28 ( V_5 , V_20 , V_19 -> V_72 / 2 ) ;
} else
V_19 -> type = V_92 ;
V_19 = & V_5 -> V_61 [ 4 ] ;
if ( V_10 -> V_44 == V_45 ) {
V_19 -> type = V_99 ;
V_19 -> V_64 = V_65 | V_85 | V_96 ;
V_19 -> V_70 = V_100 ;
V_19 -> V_72 = 0xff ;
V_19 -> V_79 = V_101 ;
V_19 -> V_89 = V_102 ;
for ( V_20 = 0 ; V_20 < V_100 ; V_20 ++ )
V_16 -> V_103 [ V_20 ] = F_29 ( V_5 , V_20 ) ;
} else
V_19 -> type = V_92 ;
return 0 ;
}
static const struct V_104 *
F_30 ( struct V_105 * V_106 )
{
unsigned int V_107 = V_106 -> V_108 ;
unsigned int V_109 ;
for ( V_109 = 0 ; V_109 < F_31 ( V_110 ) ; V_109 ++ ) {
const struct V_104 * V_111 = & V_110 [ V_109 ] ;
if ( V_111 -> V_29 == V_50 &&
V_111 -> V_107 == V_107 )
return V_111 ;
}
return NULL ;
}
static int F_32 ( struct V_4 * V_5 ,
unsigned long V_112 )
{
struct V_105 * V_106 = F_33 ( V_5 ) ;
struct V_15 * V_16 ;
unsigned long V_12 ;
unsigned int V_13 ;
int V_25 ;
if ( ! F_34 ( V_113 ) )
return - V_114 ;
V_16 = F_35 ( sizeof( * V_16 ) , V_56 ) ;
if ( ! V_16 )
return - V_58 ;
V_5 -> V_17 = V_16 ;
V_5 -> V_115 = F_30 ( V_106 ) ;
if ( ! V_5 -> V_115 )
return - V_114 ;
V_16 -> V_116 = F_36 ( V_106 ) ;
if ( ! V_16 -> V_116 )
return - V_58 ;
V_25 = F_37 ( V_16 -> V_116 ) ;
if ( V_25 < 0 )
return V_25 ;
V_12 = ( unsigned long ) V_16 -> V_116 -> V_117 ;
V_13 = F_38 ( V_16 -> V_116 ) ;
return F_12 ( V_5 , V_12 , V_13 , 0 ) ;
}
static int F_39 ( struct V_4 * V_5 , struct V_118 * V_119 )
{
struct V_15 * V_16 ;
unsigned long V_12 = 0 ;
unsigned int V_13 = 0 ;
unsigned int V_14 = 0 ;
V_16 = F_35 ( sizeof( * V_16 ) , V_56 ) ;
if ( ! V_16 )
return - V_58 ;
V_5 -> V_17 = V_16 ;
switch ( V_10 -> V_29 ) {
case V_30 :
#ifdef F_13
V_12 = V_119 -> V_120 [ 0 ] ;
V_13 = V_119 -> V_120 [ 1 ] ;
V_14 = V_119 -> V_120 [ 2 ] ;
#else
F_15 ( V_5 -> V_26 ,
L_7 ) ;
return - V_28 ;
#endif
break;
case V_50 :
#ifdef V_113
F_15 ( V_5 -> V_26 ,
L_8 ,
V_10 -> V_27 ) ;
return - V_28 ;
#else
F_15 ( V_5 -> V_26 ,
L_9 ) ;
return - V_28 ;
#endif
break;
default:
F_15 ( V_5 -> V_26 ,
L_10 ) ;
return - V_28 ;
break;
}
return F_12 ( V_5 , V_12 , V_13 , V_14 ) ;
}
void F_40 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_18 * V_19 ;
if ( ! V_10 )
return;
if ( V_5 -> V_61 ) {
V_19 = & V_5 -> V_61 [ 2 ] ;
F_41 ( V_5 , V_19 ) ;
}
#ifdef F_13
F_42 ( V_16 -> V_54 ) ;
if ( V_16 -> V_14 )
F_43 ( V_16 -> V_14 ) ;
#endif
if ( V_5 -> V_13 )
F_44 ( V_5 -> V_13 , V_5 ) ;
if ( V_10 -> V_29 == V_30 && V_5 -> V_12 )
F_45 ( V_5 -> V_12 , V_31 ) ;
#ifdef V_113
if ( V_16 -> V_116 ) {
F_46 ( V_16 -> V_116 ) ;
F_47 ( V_16 -> V_116 ) ;
}
#endif
}
static void F_48 ( const struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
V_16 -> V_35 ( 0x1 , V_5 -> V_12 + V_121 ) ;
V_16 -> V_34 ( V_5 -> V_12 + V_122 ) ;
V_16 -> V_34 ( V_5 -> V_12 + V_122 ) ;
}
static int V_82 ( struct V_4 * V_5 , struct V_18 * V_19 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned long V_123 ;
F_49 ( & V_5 -> V_124 , V_123 ) ;
V_16 -> V_38 &= ~ V_125 & ~ V_126 & ~ V_127 ;
V_16 -> V_35 ( V_16 -> V_38 , V_5 -> V_12 + V_39 ) ;
F_50 ( & V_5 -> V_124 , V_123 ) ;
V_16 -> V_40 = 0 ;
V_16 -> V_35 ( V_16 -> V_40 , V_5 -> V_12 + V_41 ) ;
return 0 ;
}
static enum V_128 F_51 ( const struct V_129 * V_130 )
{
if ( V_130 -> V_131 == 1 )
return V_132 ;
if ( V_130 -> V_133 == NULL )
return V_134 ;
if ( F_52 ( V_130 -> V_133 [ 0 ] ) == F_52 ( V_130 -> V_133 [ 1 ] ) )
return V_135 ;
if ( F_52 ( V_130 -> V_133 [ 0 ] ) < F_52 ( V_130 -> V_133 [ 1 ] ) )
return V_134 ;
if ( F_52 ( V_130 -> V_133 [ 0 ] ) > F_52 ( V_130 -> V_133 [ 1 ] ) )
return V_136 ;
F_53 ( L_11 ) ;
return 0 ;
}
static int F_54 ( const struct V_4 * V_5 ,
const struct V_129 * V_130 ,
enum V_128 V_9 )
{
int V_137 , V_138 , V_139 , V_20 ;
if ( V_130 -> V_133 == NULL )
return 0 ;
if ( V_9 == V_132 )
return 0 ;
if ( V_9 == V_135 ) {
if ( V_130 -> V_131 > 0xff ) {
F_55 ( V_5 ,
L_12 ) ;
return 1 ;
}
}
V_137 = F_52 ( V_130 -> V_133 [ 0 ] ) ;
V_138 = F_56 ( V_130 -> V_133 [ 0 ] ) ;
V_139 = F_57 ( V_130 -> V_133 [ 0 ] ) ;
for ( V_20 = 0 ; V_20 < V_130 -> V_131 ; V_20 ++ ) {
switch ( V_9 ) {
case V_135 :
if ( F_52 ( V_130 -> V_133 [ V_20 ] ) != V_137 ) {
F_55 ( V_5 ,
L_13 ) ;
return 1 ;
}
break;
case V_134 :
if ( F_52 ( V_130 -> V_133 [ V_20 ] ) != V_20 ) {
F_55 ( V_5 ,
L_13 ) ;
return 1 ;
}
break;
case V_136 :
if ( F_52 ( V_130 -> V_133 [ V_20 ] ) !=
V_130 -> V_131 - V_20 - 1 ) {
F_55 ( V_5 ,
L_13 ) ;
return 1 ;
}
break;
default:
F_15 ( V_5 -> V_26 ,
L_14 ) ;
return 1 ;
break;
}
if ( F_56 ( V_130 -> V_133 [ V_20 ] ) != V_138 ) {
F_55 ( V_5 ,
L_15 ) ;
return 1 ;
}
if ( F_57 ( V_130 -> V_133 [ V_20 ] ) != V_139 ) {
F_55 ( V_5 ,
L_16 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_58 ( const struct V_129 * V_130 ,
enum V_128 V_9 )
{
if ( V_9 == V_132 )
return 1 ;
if ( V_130 -> V_140 == V_141 )
return 1 ;
return 0 ;
}
static unsigned int F_59 ( const struct V_129 * V_130 ,
enum V_128 V_9 )
{
if ( V_130 -> V_142 != V_143 )
return 0 ;
if ( V_9 == V_132 && V_130 -> V_140 == V_143 )
return V_130 -> V_144 ;
return V_130 -> V_145 ;
}
static void F_60 ( struct V_129 * V_130 ,
enum V_128 V_9 , unsigned int V_146 )
{
if ( V_130 -> V_142 != V_143 )
return;
if ( V_9 == V_132 &&
V_130 -> V_140 == V_143 ) {
V_130 -> V_144 = V_146 ;
if ( V_130 -> V_145 > V_130 -> V_144 )
V_130 -> V_145 = V_130 -> V_144 ;
} else
V_130 -> V_145 = V_146 ;
}
static unsigned int F_61 ( const struct V_129 * V_130 ,
enum V_128 V_9 )
{
if ( V_130 -> V_140 != V_143 )
return 0 ;
if ( V_9 == V_132 && V_130 -> V_142 == V_143 )
return 0 ;
return V_130 -> V_144 ;
}
static void F_62 ( struct V_129 * V_130 ,
enum V_128 V_9 , unsigned int V_146 )
{
if ( V_130 -> V_140 != V_143 )
return;
if ( V_9 == V_132 && V_130 -> V_142 == V_143 )
return;
V_130 -> V_144 = V_146 ;
}
static int V_78 ( struct V_4 * V_5 ,
struct V_18 * V_19 , struct V_129 * V_130 )
{
int V_147 = 0 ;
int V_148 , V_149 ;
unsigned int V_150 ;
enum V_128 V_9 ;
V_147 |= F_63 ( & V_130 -> V_151 , V_152 | V_153 ) ;
V_147 |= F_63 ( & V_130 -> V_140 ,
V_143 | V_141 | V_153 ) ;
V_147 |= F_63 ( & V_130 -> V_142 , V_143 | V_153 ) ;
V_147 |= F_63 ( & V_130 -> V_154 , V_155 ) ;
V_150 = V_155 | V_156 ;
if ( V_10 -> V_44 == V_45 )
V_150 |= V_153 ;
V_147 |= F_63 ( & V_130 -> V_157 , V_150 ) ;
if ( V_147 )
return 1 ;
V_147 |= F_64 ( V_130 -> V_151 ) ;
V_147 |= F_64 ( V_130 -> V_140 ) ;
V_147 |= F_64 ( V_130 -> V_142 ) ;
V_147 |= F_64 ( V_130 -> V_157 ) ;
if ( V_130 -> V_151 == V_153 && V_130 -> V_157 == V_153 )
V_147 ++ ;
if ( V_147 )
return 2 ;
if ( V_130 -> V_158 == V_152 )
V_147 |= F_65 ( & V_130 -> V_158 , 0 ) ;
if ( ! V_130 -> V_131 )
V_147 |= - V_28 ;
V_147 |= F_65 ( & V_130 -> V_159 , V_130 -> V_131 ) ;
if ( V_130 -> V_142 == V_143 )
V_147 |= F_66 ( & V_130 -> V_145 ,
V_10 -> V_160 ) ;
if ( V_130 -> V_140 == V_143 ) {
if ( V_130 -> V_142 == V_143 )
V_147 |= F_66 ( & V_130 -> V_144 ,
V_130 -> V_145 * V_130 -> V_131 ) ;
V_147 |= F_66 ( & V_130 -> V_144 ,
V_10 -> V_160 * V_130 -> V_131 ) ;
}
switch ( V_130 -> V_157 ) {
case V_155 :
V_147 |= F_66 ( & V_130 -> V_161 , 1 ) ;
break;
case V_156 :
V_147 |= F_65 ( & V_130 -> V_161 , 0 ) ;
break;
default:
break;
}
if ( V_147 )
return 3 ;
V_148 = V_130 -> V_145 ;
V_149 = V_130 -> V_144 ;
V_9 = F_51 ( V_130 ) ;
F_67 ( V_5 , V_130 , V_9 ) ;
if ( V_148 != V_130 -> V_145 || V_149 != V_130 -> V_144 )
V_147 ++ ;
if ( V_147 )
return 4 ;
if ( F_54 ( V_5 , V_130 , V_9 ) )
return 5 ;
return 0 ;
}
static int V_76 ( struct V_4 * V_5 , struct V_18 * V_19 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
int V_137 , V_138 , V_139 ;
#ifdef F_13
unsigned long V_162 ;
#endif
int V_25 ;
struct V_163 * V_164 = V_19 -> V_164 ;
struct V_129 * V_130 = & V_164 -> V_130 ;
enum V_165 V_166 ;
enum V_128 V_9 ;
unsigned long V_123 ;
if ( ! V_5 -> V_13 ) {
F_55 ( V_5 , L_17 ) ;
return - 1 ;
}
V_138 = F_56 ( V_130 -> V_133 [ 0 ] ) ;
V_139 = F_57 ( V_130 -> V_133 [ 0 ] ) ;
F_49 ( & V_5 -> V_124 , V_123 ) ;
V_16 -> V_38 &= ~ V_125 & ~ V_126 & ~ V_127 ;
V_16 -> V_35 ( V_16 -> V_38 , V_5 -> V_12 + V_39 ) ;
F_50 ( & V_5 -> V_124 , V_123 ) ;
V_16 -> V_40 = 0 ;
V_16 -> V_35 ( V_16 -> V_40 , V_5 -> V_12 + V_41 ) ;
if ( V_130 -> V_157 == V_155 )
V_16 -> V_8 = V_130 -> V_161 * V_130 -> V_131 ;
if ( V_130 -> V_157 == V_153 ) {
V_25 = F_9 ( V_5 , V_5 -> V_12 + V_167 ,
1 , 3 , 0 ) ;
if ( V_25 < 0 ) {
F_55 ( V_5 , L_18 ) ;
return - 1 ;
}
} else
V_16 -> V_35 ( V_168 ,
V_5 -> V_12 + V_169 ) ;
#ifdef F_13
if ( V_16 -> V_14 &&
( V_130 -> V_123 & ( V_170 | V_171 ) ) == 0 &&
V_10 -> V_29 == V_30 ) {
V_166 = V_172 ;
} else
#endif
if ( V_10 -> V_44 == V_45 &&
( V_130 -> V_123 & V_170 ) == 0 &&
( V_130 -> V_157 != V_155 || V_16 -> V_8 > 256 ) ) {
V_166 = V_173 ;
} else
V_166 = V_174 ;
V_16 -> V_175 = V_166 ;
V_9 = F_51 ( V_130 ) ;
if ( V_10 -> V_44 == V_45 ) {
if ( V_139 != V_176 )
V_16 -> V_48 |= V_177 ;
else
V_16 -> V_48 &= ~ V_177 ;
if ( V_10 -> V_178 [ V_138 ] )
V_16 -> V_48 |= V_179 ;
else
V_16 -> V_48 &= ~ V_179 ;
if ( V_166 == V_173 )
V_16 -> V_48 |= V_180 ;
else
V_16 -> V_48 &= ~ V_180 ;
if ( V_130 -> V_157 == V_153 )
V_16 -> V_48 |= V_181 ;
else
V_16 -> V_48 &= ~ V_181 ;
if ( V_9 == V_134 )
V_16 -> V_48 |= V_182 ;
else
V_16 -> V_48 &= ~ V_182 ;
V_16 -> V_35 ( V_16 -> V_48 ,
V_5 -> V_12 + V_49 ) ;
}
V_16 -> V_36 = 0 ;
if ( V_9 == V_134 )
V_137 = F_52 ( V_130 -> V_133 [ V_130 -> V_131 - 1 ] ) ;
else
V_137 = F_52 ( V_130 -> V_133 [ 0 ] ) ;
if ( ( V_9 == V_132 || V_9 == V_135 ) &&
V_139 == V_183 )
V_137 *= 2 ;
V_16 -> V_36 |= F_68 ( V_137 ) ;
V_16 -> V_36 |= V_10 -> V_184 [ V_138 ] ;
V_16 -> V_35 ( V_16 -> V_36 , V_5 -> V_12 + V_37 ) ;
if ( V_9 == V_134 || V_9 == V_136 ) {
V_16 -> V_36 |= V_185 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_36 ,
V_5 -> V_12 + V_37 ) ;
}
V_16 -> V_35 ( V_130 -> V_131 ,
V_5 -> V_12 + V_186 ) ;
V_16 -> V_35 ( V_187 ,
V_5 -> V_12 + V_188 ) ;
if ( V_130 -> V_142 == V_143 || V_130 -> V_140 == V_143 ) {
F_67 ( V_5 , V_130 , V_9 ) ;
V_25 = F_9 ( V_5 , V_5 -> V_12 + V_189 ,
0 , V_16 -> V_190 , 3 ) ;
if ( V_25 < 0 ) {
F_55 ( V_5 , L_19 ) ;
return - 1 ;
}
}
if ( F_59 ( V_130 , V_9 ) ) {
V_25 = F_9 ( V_5 , V_5 -> V_12 + V_167 ,
0 , V_16 -> V_191 , 2 ) ;
if ( V_25 < 0 ) {
F_55 ( V_5 , L_20 ) ;
return - 1 ;
}
} else
V_16 -> V_35 ( V_192 ,
V_5 -> V_12 + V_169 ) ;
if ( F_61 ( V_130 , V_9 ) ) {
V_25 = F_9 ( V_5 , V_5 -> V_12 + V_189 ,
1 , V_16 -> V_193 , 2 ) ;
if ( V_25 < 0 ) {
F_55 ( V_5 , L_21 ) ;
return - 1 ;
}
}
F_48 ( V_5 ) ;
#ifdef F_13
if ( V_166 == V_172 ) {
V_162 = F_20 () ;
F_21 ( V_16 -> V_14 ) ;
F_70 ( V_16 -> V_14 ) ;
F_71 ( V_16 -> V_14 ,
F_72 ( V_16 -> V_54 ) ) ;
V_16 -> V_194 = F_73 ( V_130 ) ;
if ( V_130 -> V_157 == V_155 &&
V_16 -> V_8 * V_195 < V_16 -> V_194 ) {
V_16 -> V_194 =
V_16 -> V_8 * V_195 ;
}
F_74 ( V_16 -> V_14 , V_16 -> V_194 ) ;
F_75 ( V_16 -> V_14 ) ;
F_23 ( V_162 ) ;
V_16 -> V_40 |= V_196 | V_197 ;
} else
V_16 -> V_40 &= ~ V_196 & ~ V_197 ;
#endif
V_16 -> V_40 |= V_198 ;
if ( V_166 == V_174 )
V_16 -> V_40 |= V_199 ;
else
V_16 -> V_40 &= ~ V_199 ;
V_16 -> V_35 ( V_16 -> V_40 , V_5 -> V_12 + V_41 ) ;
V_16 -> V_42 = 0 ;
if ( V_130 -> V_142 != V_153 )
V_16 -> V_42 |= V_200 ;
if ( F_58 ( V_130 , V_9 ) == 0 ) {
V_16 -> V_42 |= V_201 ;
if ( V_130 -> V_140 == V_153 )
V_16 -> V_42 |= V_202 ;
}
if ( V_139 == V_183 )
V_16 -> V_42 |= V_203 ;
V_16 -> V_35 ( V_16 -> V_42 , V_5 -> V_12 + V_43 ) ;
F_49 ( & V_5 -> V_124 , V_123 ) ;
V_16 -> V_38 |= V_204 ;
switch ( V_130 -> V_151 ) {
case V_153 :
V_16 -> V_38 |= V_126 ;
V_16 -> V_38 &= ~ V_127 & ~ V_125 ;
break;
case V_152 :
V_16 -> V_38 |= V_125 ;
V_16 -> V_38 &= ~ V_127 & ~ V_126 ;
break;
default:
F_55 ( V_5 , L_22 ) ;
F_50 ( & V_5 -> V_124 , V_123 ) ;
return - 1 ;
break;
}
switch ( V_130 -> V_157 ) {
case V_153 :
V_16 -> V_38 |= V_126 | V_127 ;
break;
case V_155 :
case V_156 :
break;
default:
F_55 ( V_5 , L_23 ) ;
F_50 ( & V_5 -> V_124 , V_123 ) ;
return - 1 ;
}
V_16 -> V_35 ( V_16 -> V_38 , V_5 -> V_12 + V_39 ) ;
F_50 ( & V_5 -> V_124 , V_123 ) ;
return 0 ;
}
static T_1 V_53 ( int V_13 , void * V_205 )
{
struct V_4 * V_5 = V_205 ;
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_18 * V_19 = V_5 -> V_62 ;
struct V_163 * V_164 ;
struct V_129 * V_130 ;
if ( V_5 -> V_206 == 0 ) {
F_55 ( V_5 , L_24 ) ;
return V_207 ;
}
V_164 = V_19 -> V_164 ;
V_130 = & V_164 -> V_130 ;
V_164 -> V_208 = 0 ;
V_16 -> V_209 = V_16 -> V_34 ( V_5 -> V_12 + V_210 ) ;
if ( V_10 -> V_44 == V_45 )
V_16 -> V_211 =
V_16 -> V_34 ( V_5 -> V_12 + V_212 ) ;
if ( ( V_16 -> V_209 & ( V_213 | V_214 | V_215 |
V_216 | V_217 ) ) == 0
&& ( V_16 -> V_211 & V_218 ) == 0
&& ( V_16 -> V_211 & V_219 ) ) {
return V_220 ;
}
if ( V_16 -> V_209 & V_216 ) {
V_16 -> V_35 ( 0x1 , V_5 -> V_12 + V_121 ) ;
V_164 -> V_208 |= V_221 | V_222 ;
F_76 ( V_5 , V_19 ) ;
F_55 ( V_5 , L_25 ) ;
return V_207 ;
}
#ifdef F_13
if ( V_16 -> V_175 == V_172 ) {
if ( V_16 -> V_209 & V_213 ||
( V_10 -> V_44 == V_45
&& V_16 -> V_211 & V_218 ) ) {
F_77 ( V_5 ) ;
}
} else
#endif
F_78 ( V_5 ) ;
if ( V_16 -> V_209 & V_214 ) {
F_55 ( V_5 , L_26 ) ;
V_16 -> V_35 ( 0x1 , V_5 -> V_12 + V_223 ) ;
}
if ( V_16 -> V_209 & V_215 ) {
V_16 -> V_35 ( 0x1 , V_5 -> V_12 + V_121 ) ;
V_164 -> V_208 |= V_221 | V_222 ;
F_76 ( V_5 , V_19 ) ;
F_55 ( V_5 , L_27 ) ;
return V_207 ;
}
if ( V_130 -> V_157 == V_153 ) {
if ( V_16 -> V_211 & V_218 ) {
F_79 ( V_5 ) ;
V_82 ( V_5 , V_19 ) ;
V_164 -> V_208 |= V_222 ;
}
}
if ( V_130 -> V_157 == V_155 ) {
if ( V_16 -> V_8 == 0 ) {
V_82 ( V_5 , V_19 ) ;
V_164 -> V_208 |= V_222 ;
}
}
F_76 ( V_5 , V_19 ) ;
return V_207 ;
}
static int F_78 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_23 , V_24 ;
short V_224 ;
struct V_163 * V_164 = V_5 -> V_62 -> V_164 ;
const int V_225 = 10000 ;
unsigned int V_20 ;
V_16 -> V_209 = V_16 -> V_34 ( V_5 -> V_12 + V_210 ) ;
for ( V_20 = 0 ; ( V_16 -> V_209 & V_217 ) && V_20 < V_225 ;
V_20 ++ ) {
if ( V_164 -> V_130 . V_157 == V_155 ) {
if ( V_16 -> V_8 == 0 )
break;
V_16 -> V_8 -- ;
}
V_23 = V_16 -> V_34 ( V_5 -> V_12 + V_122 ) ;
V_24 = V_16 -> V_34 ( V_5 -> V_12 + V_122 ) ;
V_224 = ( V_24 << 8 ) | V_23 ;
F_80 ( V_5 -> V_62 , V_224 ) ;
V_16 -> V_209 =
V_16 -> V_34 ( V_5 -> V_12 + V_210 ) ;
}
if ( V_20 == V_225 ) {
F_55 ( V_5 , L_28 ) ;
V_164 -> V_208 |= V_221 | V_222 ;
return - 1 ;
}
return 0 ;
}
static void F_81 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_18 * V_19 = V_5 -> V_62 ;
struct V_163 * V_164 = V_19 -> V_164 ;
int V_226 ;
unsigned long V_123 ;
unsigned int V_227 , V_228 , V_229 , V_230 ;
int V_20 ;
V_226 = V_16 -> V_209 ;
V_123 = F_20 () ;
F_21 ( V_16 -> V_14 ) ;
F_70 ( V_16 -> V_14 ) ;
V_227 = V_16 -> V_194 / V_195 ;
V_229 = F_82 ( V_16 -> V_14 ) / V_195 ;
V_228 = V_227 - V_229 ;
if ( V_16 -> V_8 < V_228 && V_164 -> V_130 . V_157 == V_155 )
V_228 = V_16 -> V_8 ;
V_230 = 0 ;
if ( V_164 -> V_130 . V_157 != V_155 ) {
V_230 = V_16 -> V_194 / V_195 ;
} else if ( V_16 -> V_8 > V_228 ) {
V_230 = V_16 -> V_8 - V_228 ;
if ( V_230 > V_227 )
V_230 = V_227 ;
}
for ( V_20 = 0 ; V_20 < V_228 ; V_20 ++ )
F_80 ( V_19 , V_16 -> V_54 [ V_20 ] ) ;
if ( V_164 -> V_130 . V_157 == V_155 )
V_16 -> V_8 -= V_228 ;
F_71 ( V_16 -> V_14 , F_72 ( V_16 -> V_54 ) ) ;
F_74 ( V_16 -> V_14 , V_230 * V_195 ) ;
F_23 ( V_123 ) ;
V_164 -> V_208 |= V_231 ;
}
static void F_77 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
F_81 ( V_5 ) ;
F_75 ( V_16 -> V_14 ) ;
V_16 -> V_35 ( 0x1 , V_5 -> V_12 + V_232 ) ;
}
static void F_79 ( struct V_4 * V_5 )
{
#ifdef F_13
struct V_15 * V_16 = V_5 -> V_17 ;
if ( V_16 -> V_175 == V_172 )
F_81 ( V_5 ) ;
#endif
F_78 ( V_5 ) ;
}
static int V_80 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_233 * V_234 , unsigned int * V_224 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
int V_20 , V_109 ;
int V_235 , V_138 ;
int V_23 , V_24 ;
int V_225 = 1000 ;
unsigned long V_123 ;
F_49 ( & V_5 -> V_124 , V_123 ) ;
V_16 -> V_38 &= ~ V_125 & ~ V_126 & ~ V_127 ;
V_16 -> V_35 ( V_16 -> V_38 , V_5 -> V_12 + V_39 ) ;
F_50 ( & V_5 -> V_124 , V_123 ) ;
V_16 -> V_40 = 0 ;
V_16 -> V_35 ( V_16 -> V_40 , V_5 -> V_12 + V_41 ) ;
V_16 -> V_36 = 0 ;
V_235 = F_52 ( V_234 -> V_236 ) ;
V_138 = F_56 ( V_234 -> V_236 ) ;
V_16 -> V_36 |= V_10 -> V_184 [ V_138 ] ;
if ( F_57 ( V_234 -> V_236 ) == V_183 )
V_235 *= 2 ;
V_16 -> V_36 |= F_68 ( V_235 ) ;
V_16 -> V_35 ( V_16 -> V_36 , V_5 -> V_12 + V_37 ) ;
if ( V_10 -> V_44 == V_45 ) {
if ( F_57 ( V_234 -> V_236 ) != V_176 )
V_16 -> V_48 |= V_177 ;
else
V_16 -> V_48 &= ~ V_177 ;
if ( V_10 -> V_178 [ V_138 ] )
V_16 -> V_48 |= V_179 ;
else
V_16 -> V_48 &= ~ V_179 ;
V_16 -> V_48 &= ~ V_180 ;
V_16 -> V_48 &= ~ V_181 ;
V_16 -> V_35 ( V_16 -> V_48 ,
V_5 -> V_12 + V_49 ) ;
}
V_16 -> V_42 = 0 ;
V_16 -> V_42 |= V_200 ;
if ( F_57 ( V_234 -> V_236 ) == V_183 )
V_16 -> V_42 |= V_203 ;
V_16 -> V_35 ( V_16 -> V_42 , V_5 -> V_12 + V_43 ) ;
V_16 -> V_35 ( V_192 , V_5 -> V_12 + V_169 ) ;
F_48 ( V_5 ) ;
for ( V_109 = 0 ; V_109 < V_234 -> V_109 ; V_109 ++ ) {
V_16 -> V_35 ( 0x1 , V_5 -> V_12 + V_237 ) ;
for ( V_20 = 0 ; V_20 < V_225 ; V_20 ++ ) {
if ( V_16 -> V_34 ( V_5 -> V_12 +
V_210 ) & V_217 )
break;
F_69 ( 1 ) ;
}
if ( V_20 == V_225 ) {
F_55 ( V_5 , L_29 ) ;
return - V_238 ;
}
V_23 = V_16 -> V_34 ( V_5 -> V_12 + V_122 ) ;
V_24 = V_16 -> V_34 ( V_5 -> V_12 + V_122 ) ;
V_224 [ V_109 ] = ( V_24 << 8 ) | V_23 ;
}
return V_109 ;
}
static int V_90 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_233 * V_234 , unsigned int * V_224 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
int V_137 , V_138 ;
unsigned long V_123 ;
int V_23 , V_24 ;
V_137 = F_52 ( V_234 -> V_236 ) ;
F_49 ( & V_5 -> V_124 , V_123 ) ;
V_16 -> V_38 &= ~ F_83 ( V_137 ) ;
V_16 -> V_35 ( V_16 -> V_38 , V_5 -> V_12 + V_39 ) ;
F_50 ( & V_5 -> V_124 , V_123 ) ;
if ( V_10 -> V_44 == V_45 ) {
V_138 = F_56 ( V_234 -> V_236 ) ;
if ( V_138 & V_239 )
V_16 -> V_48 |= F_84 ( V_137 ) ;
else
V_16 -> V_48 &= ~ F_84 ( V_137 ) ;
V_16 -> V_35 ( V_16 -> V_48 ,
V_5 -> V_12 + V_49 ) ;
}
V_23 = V_224 [ 0 ] & 0xff ;
V_24 = ( V_224 [ 0 ] >> 8 ) & 0xff ;
V_16 -> V_35 ( V_23 , V_5 -> V_12 + F_25 ( V_137 ) ) ;
V_16 -> V_35 ( V_24 , V_5 -> V_12 + F_26 ( V_137 ) ) ;
V_16 -> V_91 [ V_137 ] = V_224 [ 0 ] ;
return 1 ;
}
static int V_88 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_233 * V_234 , unsigned int * V_224 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
V_224 [ 0 ] = V_16 -> V_91 [ F_52 ( V_234 -> V_236 ) ] ;
return 1 ;
}
static int V_97 ( struct V_4 * V_5 ,
struct V_18 * V_19 ,
struct V_233 * V_234 , unsigned int * V_224 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
V_224 [ 0 ] = V_16 -> V_240 [ F_52 ( V_234 -> V_236 ) ] ;
return 1 ;
}
static int V_98 ( struct V_4 * V_5 ,
struct V_18 * V_19 ,
struct V_233 * V_234 , unsigned int * V_224 )
{
int V_137 = F_52 ( V_234 -> V_236 ) ;
F_28 ( V_5 , V_137 , V_224 [ 0 ] ) ;
return 1 ;
}
static int V_101 ( struct V_4 * V_5 ,
struct V_18 * V_19 ,
struct V_233 * V_234 , unsigned int * V_224 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
V_224 [ 0 ] = V_16 -> V_103 [ F_52 ( V_234 -> V_236 ) ] ;
return 1 ;
}
static int V_102 ( struct V_4 * V_5 ,
struct V_18 * V_19 ,
struct V_233 * V_234 , unsigned int * V_224 )
{
int V_137 = F_52 ( V_234 -> V_236 ) ;
int V_25 ;
if ( V_137 < 16 || V_137 > 127 ) {
F_85 ( V_5 -> V_26 ,
L_30 ) ;
return - V_28 ;
}
V_25 = F_86 ( V_5 , V_137 , V_224 [ 0 ] ) ;
if ( V_25 < 0 )
return V_25 ;
return 1 ;
}
static unsigned int F_73 ( const struct V_129 * V_130 )
{
unsigned int V_241 ;
unsigned int V_242 ;
if ( V_130 -> V_142 == V_143 )
V_242 = 1000000000 / V_130 -> V_145 ;
else
V_242 = 0xffffffff ;
V_241 = ( V_242 / 3 ) * V_195 ;
if ( V_241 > V_55 )
V_241 = V_55 - V_55 % V_195 ;
else if ( V_241 < V_195 )
V_241 = V_195 ;
return V_241 ;
}
static void F_67 ( struct V_4 * V_5 , struct V_129 * V_130 ,
enum V_128 V_9 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
const int V_243 = 0x10000 ;
const int V_244 = 2 ;
unsigned int V_245 ;
unsigned int V_246 ;
unsigned int V_247 ;
V_247 = F_59 ( V_130 , V_9 ) ;
V_246 = F_61 ( V_130 , V_9 ) ;
if ( V_247 && V_246 ) {
V_16 -> V_190 = ( V_246 - 1 ) /
( V_248 * V_243 ) + 1 ;
if ( V_16 -> V_190 < V_244 )
V_16 -> V_190 = V_244 ;
if ( V_16 -> V_190 > V_243 )
V_16 -> V_190 = V_243 ;
V_245 = V_248 * V_16 -> V_190 ;
switch ( V_130 -> V_123 & V_249 ) {
default:
case V_250 :
V_16 -> V_191 =
( V_247 + ( V_245 / 2 ) ) / V_245 ;
V_16 -> V_193 =
( V_246 + ( V_245 / 2 ) ) / V_245 ;
break;
case V_251 :
V_16 -> V_191 =
( V_247 + ( V_245 - 1 ) ) / V_245 ;
V_16 -> V_193 =
( V_246 + ( V_245 - 1 ) ) / V_245 ;
break;
case V_252 :
V_16 -> V_191 = V_247 / V_245 ;
V_16 -> V_193 = V_246 / V_245 ;
break;
}
if ( V_16 -> V_191 < V_244 )
V_16 -> V_191 = V_244 ;
if ( V_16 -> V_191 > V_243 )
V_16 -> V_191 = V_243 ;
if ( V_16 -> V_193 < V_244 )
V_16 -> V_193 = V_244 ;
if ( V_16 -> V_193 > V_243 )
V_16 -> V_193 = V_243 ;
F_60 ( V_130 , V_9 ,
V_245 * V_16 -> V_191 ) ;
F_62 ( V_130 , V_9 ,
V_245 * V_16 -> V_193 ) ;
} else if ( V_246 ) {
F_87 ( V_248 ,
& ( V_16 -> V_193 ) ,
& ( V_16 -> V_190 ) ,
& V_246 ,
V_130 -> V_123 & V_249 ) ;
F_62 ( V_130 , V_9 , V_246 ) ;
} else if ( V_247 ) {
F_87 ( V_248 ,
& ( V_16 -> V_191 ) ,
& ( V_16 -> V_190 ) ,
& V_247 ,
V_130 -> V_123 & V_249 ) ;
F_60 ( V_130 , V_9 , V_247 ) ;
}
}
static int V_93 ( int V_253 , int V_254 , int V_224 ,
unsigned long V_12 )
{
if ( V_253 ) {
F_8 ( V_224 , ( void V_3 * ) ( V_12 + V_254 ) ) ;
return 0 ;
} else {
return F_6 ( ( void V_3 * ) ( V_12 + V_254 ) ) ;
}
}
static void F_88 ( struct V_4 * V_5 , unsigned int V_255 ,
unsigned int V_256 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
int V_20 ;
for ( V_20 = 1 ; V_20 <= V_256 ; V_20 ++ ) {
V_16 -> V_46 &= ~ V_257 ;
if ( V_255 & ( 1 << ( V_256 - V_20 ) ) )
V_16 -> V_46 |= V_258 ;
else
V_16 -> V_46 &= ~ V_258 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 ,
V_5 -> V_12 + V_47 ) ;
V_16 -> V_46 |= V_257 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 ,
V_5 -> V_12 + V_47 ) ;
}
}
static unsigned int F_89 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_255 = 0 ;
int V_20 ;
const int V_256 = 8 ;
for ( V_20 = 1 ; V_20 <= V_256 ; V_20 ++ ) {
V_16 -> V_46 |= V_257 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 ,
V_5 -> V_12 + V_47 ) ;
V_16 -> V_46 &= ~ V_257 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 ,
V_5 -> V_12 + V_47 ) ;
F_69 ( 1 ) ;
V_16 -> V_211 =
V_16 -> V_34 ( V_5 -> V_12 + V_212 ) ;
if ( V_16 -> V_211 & V_259 )
V_255 |= 1 << ( V_256 - V_20 ) ;
}
return V_255 ;
}
static unsigned int F_29 ( struct V_4 * V_5 ,
unsigned int V_1 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_255 ;
const int V_260 = 0x3 ;
const int V_261 = 8 ;
V_16 -> V_46 &= ~ V_262 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
V_16 -> V_46 |= V_262 | V_263 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
F_88 ( V_5 , V_260 , V_261 ) ;
F_88 ( V_5 , V_1 , V_261 ) ;
V_255 = F_89 ( V_5 ) ;
V_16 -> V_46 &= ~ V_262 & ~ V_263 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
return V_255 ;
}
static int F_86 ( struct V_4 * V_5 ,
unsigned int V_1 , unsigned int V_255 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
const int V_264 = 0x6 ;
const int V_265 = 0x2 ;
const int V_261 = 8 ;
const int V_266 = 0x1 ;
const int V_225 = 10000 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_225 ; V_20 ++ ) {
if ( ( F_90 ( V_5 ) & V_266 ) ==
0 )
break;
}
if ( V_20 == V_225 ) {
F_55 ( V_5 , L_31 ) ;
return - V_238 ;
}
V_16 -> V_103 [ V_1 ] = V_255 ;
V_16 -> V_46 &= ~ V_262 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
V_16 -> V_46 |= V_262 | V_263 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
F_88 ( V_5 , V_264 , V_261 ) ;
V_16 -> V_46 &= ~ V_262 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
V_16 -> V_46 |= V_262 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
F_88 ( V_5 , V_265 , V_261 ) ;
F_88 ( V_5 , V_1 , V_261 ) ;
F_88 ( V_5 , V_255 , V_261 ) ;
V_16 -> V_46 &= ~ V_262 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
V_16 -> V_46 &= ~ V_262 & ~ V_263 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
return 0 ;
}
static unsigned int F_90 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_255 ;
const int V_267 = 0x5 ;
const int V_261 = 8 ;
V_16 -> V_46 &= ~ V_262 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
V_16 -> V_46 |= V_262 | V_263 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
F_88 ( V_5 , V_267 , V_261 ) ;
V_255 = F_89 ( V_5 ) ;
V_16 -> V_46 &= ~ V_262 & ~ V_263 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
return V_255 ;
}
static void F_28 ( struct V_4 * V_5 , unsigned int V_137 ,
unsigned int V_255 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
if ( V_255 == V_16 -> V_240 [ V_137 ] )
return;
V_16 -> V_240 [ V_137 ] = V_255 ;
V_16 -> V_46 &=
~ V_268 & ~ V_262 & ~ V_263 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
F_88 ( V_5 , V_137 , 4 ) ;
F_88 ( V_5 , V_255 , 8 ) ;
V_16 -> V_46 |= V_268 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
V_16 -> V_46 &= ~ V_268 ;
F_69 ( 1 ) ;
V_16 -> V_35 ( V_16 -> V_46 , V_5 -> V_12 + V_47 ) ;
}
static int F_91 ( struct V_105 * V_5 ,
const struct V_269 * V_270 )
{
return F_92 ( V_5 , & V_271 ) ;
}
