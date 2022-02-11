static inline unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_5 . V_6 )
return V_4 -> V_7 ;
if ( V_2 -> V_5 . V_8 )
return 640 ;
return 720 ;
}
static inline unsigned int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_5 . V_6 )
return V_4 -> V_9 ;
if ( V_2 -> V_5 . V_8 )
return 480 ;
return ( V_4 -> V_10 & V_11 ) ? 576 : 480 ;
}
static int F_3 ( struct V_1 * V_2 )
{
if ( V_12 == 1 )
return 0 ;
if ( V_2 -> V_5 . V_6 )
return 0 ;
if ( V_2 -> V_13 == V_14 ||
V_2 -> V_13 == V_15 )
return 1 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_4 -> V_17 ;
F_5 ( V_17 , 0 , V_18 , V_19 , 0 ) ;
F_5 ( V_17 , 0 , V_20 , V_21 ,
F_6 ( V_2 -> V_22 ) -> V_23 , 0 , 0 ) ;
F_5 ( V_17 , 0 , V_20 , V_24 , 0 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_25 , V_26 ) ;
F_8 ( V_2 , V_27 , V_28 ) ;
F_8 ( V_2 , V_29 , V_30 ) ;
F_8 ( V_2 , V_31 , V_32 ) ;
F_8 ( V_2 , V_33 , V_34 ) ;
F_8 ( V_2 , V_35 , V_36 ) ;
F_8 ( V_2 , V_37 , 0x20 ) ;
F_8 ( V_2 , V_38 , 0x20 ) ;
F_8 ( V_2 , V_39 , 0x20 ) ;
F_8 ( V_2 , V_40 , 0x20 ) ;
F_8 ( V_2 , V_41 , 0x00 ) ;
F_8 ( V_2 , V_42 , 0x00 ) ;
return F_8 ( V_2 , V_43 , 0x00 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_44 ;
T_1 V_45 , V_46 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_45 = V_4 -> V_47 -> V_48 ;
if ( ! V_2 -> V_49 )
V_45 |= 0x20 ;
V_44 = F_8 ( V_2 , V_50 , V_45 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_8 ( V_2 , V_51 , V_4 -> V_52 ) ;
if ( V_44 < 0 )
return V_44 ;
V_46 = V_4 -> V_53 ;
if ( F_3 ( V_2 ) == 1 ) {
V_46 |= V_54 ;
F_8 ( V_2 , V_55 , 0x00 ) ;
F_8 ( V_2 , V_56 , V_4 -> V_57 / 4 ) ;
F_8 ( V_2 , V_58 , V_4 -> V_59 ) ;
if ( V_4 -> V_10 & V_60 ) {
F_8 ( V_2 , V_61 , 0x09 ) ;
} else if ( V_4 -> V_10 & V_11 ) {
F_8 ( V_2 , V_61 , 0x07 ) ;
}
}
return F_8 ( V_2 , V_62 , V_46 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_63 , T_1 V_64 ,
T_1 V_65 , T_1 V_66 )
{
F_11 ( L_1 ,
V_63 , V_65 , V_64 , V_66 ) ;
F_12 ( V_2 , V_67 , & V_63 , 1 ) ;
F_12 ( V_2 , V_68 , & V_64 , 1 ) ;
F_12 ( V_2 , V_69 , & V_65 , 1 ) ;
return F_12 ( V_2 , V_70 , & V_66 , 1 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_71 , T_1 V_72 ,
T_2 V_73 , T_2 V_74 )
{
T_1 V_75 = V_73 >> 2 ;
T_1 V_76 = V_74 >> 2 ;
T_1 V_77 = ( V_74 >> 9 & 0x02 ) | ( V_73 >> 10 & 0x01 ) ;
F_11 ( L_2 ,
V_71 , V_72 ,
( ( V_77 & 2 ) << 9 | V_75 << 2 ) ,
( ( V_77 & 1 ) << 10 | V_76 << 2 ) ) ;
F_12 ( V_2 , V_78 , & V_71 , 1 ) ;
F_12 ( V_2 , V_79 , & V_72 , 1 ) ;
F_12 ( V_2 , V_80 , & V_75 , 1 ) ;
F_12 ( V_2 , V_81 , & V_76 , 1 ) ;
F_12 ( V_2 , V_82 , & V_77 , 1 ) ;
if ( V_2 -> V_49 ) {
F_8 ( V_2 , 0x34 , V_73 >> 4 ) ;
F_8 ( V_2 , 0x35 , V_74 >> 4 ) ;
}
}
static int F_14 ( struct V_1 * V_2 , T_2 V_83 , T_2 V_84 )
{
T_1 V_85 = 0x00 ;
if ( V_2 -> V_5 . V_86 ) {
V_85 = ( V_84 ? 0x20 : 0x00 ) | ( V_83 ? 0x10 : 0x00 ) ;
} else {
T_1 V_87 [ 2 ] ;
V_87 [ 0 ] = V_83 ;
V_87 [ 1 ] = V_83 >> 8 ;
F_12 ( V_2 , V_88 , ( char * ) V_87 , 2 ) ;
V_87 [ 0 ] = V_84 ;
V_87 [ 1 ] = V_84 >> 8 ;
F_12 ( V_2 , V_89 , ( char * ) V_87 , 2 ) ;
V_85 = ( V_83 || V_84 ) ? 0x30 : 0x00 ;
}
return F_8 ( V_2 , V_90 , V_85 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_73 = F_1 ( V_2 ) ;
int V_74 = F_2 ( V_2 ) ;
V_4 -> V_57 = 720 ;
if ( V_4 -> V_10 & V_60 )
V_4 -> V_59 = 12 ;
else
V_4 -> V_59 = 18 ;
F_9 ( V_2 ) ;
F_10 ( V_2 , 1 , ( V_73 - 4 ) >> 2 , 1 , ( V_74 - 4 ) >> 2 ) ;
if ( F_3 ( V_2 ) == 1 )
F_13 ( V_2 , 0 , 2 , V_73 , V_74 ) ;
else
F_13 ( V_2 , 0 , 0 , V_73 , V_74 ) ;
return F_14 ( V_2 , V_4 -> V_91 , V_4 -> V_92 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_93 ;
int V_94 ;
unsigned int V_95 = V_4 -> V_73 * 2 + 4 ;
V_2 -> V_96 = 0 ;
if ( ( V_96 > 0 ) && ( V_96 < V_2 -> V_97 ) ) {
F_11 ( L_3 , V_2 -> V_96 ) ;
V_2 -> V_96 = V_96 ;
goto V_98;
}
if ( V_2 -> V_99 )
goto V_98;
if ( V_4 -> V_73 * 2 * V_4 -> V_74 > 720 * 240 * 2 )
V_95 *= 2 ;
for ( V_94 = 0 ; V_94 < V_2 -> V_97 ; V_94 ++ ) {
if ( V_2 -> V_100 [ V_94 ] >= V_95 ) {
V_2 -> V_96 = V_94 ;
break;
} else if ( V_2 -> V_100 [ V_94 ] >
V_2 -> V_100 [ V_2 -> V_96 ] )
V_2 -> V_96 = V_94 ;
}
V_98:
if ( V_2 -> V_99 ) {
V_2 -> V_101 = 512 ;
V_2 -> V_102 = V_103 ;
} else {
F_11 ( L_4 ,
V_95 , V_2 -> V_96 ) ;
V_2 -> V_101 =
V_2 -> V_100 [ V_2 -> V_96 ] ;
V_2 -> V_102 = V_104 ;
}
F_11 ( L_5 ,
V_2 -> V_96 , V_2 -> V_101 ) ;
V_93 = F_17 ( V_2 -> V_105 , V_2 -> V_106 , V_2 -> V_96 ) ;
if ( V_93 < 0 ) {
F_18 ( L_6 ,
V_2 -> V_96 , V_93 ) ;
return V_93 ;
}
return 0 ;
}
static inline void F_19 ( struct V_1 * V_2 ,
struct V_107 * V_87 )
{
F_20 ( L_7 , V_87 , V_87 -> V_108 ) ;
V_87 -> V_109 . V_110 = V_2 -> V_4 -> V_111 ++ ;
if ( V_2 -> V_4 -> V_112 )
V_87 -> V_109 . V_113 = V_114 ;
else
V_87 -> V_109 . V_113 = V_115 ;
F_21 ( & V_87 -> V_109 . V_116 ) ;
F_22 ( & V_87 -> V_109 . V_117 , V_118 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_107 * V_87 ,
unsigned char * V_119 ,
unsigned long V_120 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void * V_121 , * V_122 , * V_123 ;
int V_124 , V_125 , V_126 , V_127 , V_128 ;
int V_129 = V_4 -> V_73 << 1 ;
if ( V_87 -> V_130 + V_120 > V_87 -> V_131 )
V_120 = V_87 -> V_131 - V_87 -> V_130 ;
V_123 = V_119 ;
V_128 = V_120 ;
if ( V_4 -> V_112 || V_87 -> V_108 )
V_121 = V_87 -> V_132 ;
else
V_121 = V_87 -> V_132 + V_129 ;
V_124 = V_87 -> V_130 / V_129 ;
V_125 = V_87 -> V_130 % V_129 ;
if ( V_4 -> V_112 )
V_126 = V_124 * V_129 + V_125 ;
else
V_126 = V_124 * V_129 * 2 + V_125 ;
V_122 = V_121 + V_126 ;
V_127 = V_129 - V_125 ;
V_127 = V_127 > V_128 ? V_128 : V_127 ;
if ( ( char * ) V_122 + V_127 > ( char * ) V_87 -> V_132 + V_87 -> V_131 ) {
F_20 ( L_8 ,
( ( char * ) V_122 + V_127 ) -
( ( char * ) V_87 -> V_132 + V_87 -> V_131 ) ) ;
V_128 = ( char * ) V_87 -> V_132 + V_87 -> V_131 -
( char * ) V_122 ;
V_127 = V_128 ;
}
if ( V_127 <= 0 )
return;
memcpy ( V_122 , V_123 , V_127 ) ;
V_128 -= V_127 ;
while ( V_128 > 0 ) {
if ( V_4 -> V_112 )
V_122 += V_127 ;
else
V_122 += V_127 + V_129 ;
V_123 += V_127 ;
if ( V_129 > V_128 )
V_127 = V_128 ;
else
V_127 = V_129 ;
if ( ( char * ) V_122 + V_127 > ( char * ) V_87 -> V_132 +
V_87 -> V_131 ) {
F_20 ( L_9
L_10 ,
( ( char * ) V_122 + V_127 ) -
( ( char * ) V_87 -> V_132 + V_87 -> V_131 ) ) ;
V_127 = V_128 = ( char * ) V_87 -> V_132 + V_87 -> V_131 -
( char * ) V_122 ;
}
if ( V_127 <= 0 )
break;
memcpy ( V_122 , V_123 , V_127 ) ;
V_128 -= V_127 ;
}
V_87 -> V_130 += V_120 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_107 * V_87 ,
unsigned char * V_119 ,
unsigned long V_120 )
{
unsigned int V_126 ;
if ( V_87 -> V_130 + V_120 > V_87 -> V_131 )
V_120 = V_87 -> V_131 - V_87 -> V_130 ;
V_126 = V_87 -> V_130 ;
if ( V_87 -> V_108 == 0 )
V_126 += V_2 -> V_4 -> V_57 * V_2 -> V_4 -> V_59 ;
memcpy ( V_87 -> V_132 + V_126 , V_119 , V_120 ) ;
V_87 -> V_130 += V_120 ;
}
static inline void F_25 ( struct V_1 * V_2 ,
int V_133 , int V_134 )
{
char * V_135 = L_11 ;
switch ( V_134 ) {
case - V_136 :
V_135 = L_12 ;
break;
case - V_137 :
V_135 = L_13 ;
break;
case - V_138 :
V_135 = L_14 ;
break;
case - V_139 :
V_135 = L_15 ;
break;
case - V_140 :
V_135 = L_16 ;
break;
case - V_141 :
V_135 = L_17 ;
break;
case - V_142 :
V_135 = L_18 ;
break;
case - V_143 :
V_135 = L_19 ;
break;
}
if ( V_133 < 0 ) {
F_20 ( L_20 , V_134 , V_135 ) ;
} else {
F_20 ( L_21 ,
V_133 , V_134 , V_135 ) ;
}
}
static inline struct V_107 * F_26 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
struct V_107 * V_87 ;
if ( F_27 ( & V_145 -> V_146 ) ) {
F_20 ( L_22 ) ;
return NULL ;
}
V_87 = F_28 ( V_145 -> V_146 . V_147 , struct V_107 , V_148 ) ;
F_29 ( & V_87 -> V_148 ) ;
V_87 -> V_130 = 0 ;
V_87 -> V_132 = V_87 -> V_149 ;
return V_87 ;
}
static struct V_107 *
F_30 ( struct V_1 * V_2 ,
struct V_107 * V_87 ,
struct V_144 * V_145 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_112 || V_4 -> V_108 ) {
if ( V_87 != NULL )
F_19 ( V_2 , V_87 ) ;
V_87 = F_26 ( V_2 , V_145 ) ;
}
if ( V_87 != NULL ) {
V_87 -> V_108 = V_4 -> V_108 ;
V_87 -> V_130 = 0 ;
}
return V_87 ;
}
static inline void F_31 ( struct V_1 * V_2 ,
unsigned char * V_150 ,
unsigned int V_151 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_107 * V_87 = V_2 -> V_152 . V_153 ;
struct V_107 * V_154 = V_2 -> V_152 . V_154 ;
struct V_144 * V_145 = & V_2 -> V_155 ;
struct V_144 * V_156 = & V_2 -> V_157 ;
if ( V_151 >= 4 ) {
if ( V_150 [ 0 ] == 0x88 && V_150 [ 1 ] == 0x88 &&
V_150 [ 2 ] == 0x88 && V_150 [ 3 ] == 0x88 ) {
V_150 += 4 ;
V_151 -= 4 ;
} else if ( V_150 [ 0 ] == 0x33 && V_150 [ 1 ] == 0x95 ) {
V_4 -> V_158 = 0 ;
V_4 -> V_159 = 0 ;
F_20 ( L_23 ) ;
V_4 -> V_108 = ! ( V_150 [ 2 ] & 1 ) ;
V_150 += 4 ;
V_151 -= 4 ;
} else if ( V_150 [ 0 ] == 0x22 && V_150 [ 1 ] == 0x5a ) {
V_4 -> V_158 = 2 ;
F_20 ( L_24 ) ;
V_4 -> V_108 = ! ( V_150 [ 2 ] & 1 ) ;
V_150 += 4 ;
V_151 -= 4 ;
}
}
if ( V_4 -> V_158 == 0 ) {
V_154 = F_30 ( V_2 , V_154 , V_156 ) ;
V_2 -> V_152 . V_154 = V_154 ;
V_4 -> V_158 = 1 ;
}
if ( V_4 -> V_158 == 1 ) {
int V_160 = V_4 -> V_57 * V_4 -> V_59 ;
int V_161 = ( ( V_4 -> V_159 + V_151 ) > V_160 ) ?
( V_160 - V_4 -> V_159 ) : V_151 ;
if ( V_154 != NULL )
F_24 ( V_2 , V_154 , V_150 , V_161 ) ;
V_4 -> V_159 += V_161 ;
if ( V_161 < V_151 ) {
V_4 -> V_158 = 2 ;
V_150 += V_161 ;
V_151 -= V_161 ;
}
}
if ( V_4 -> V_158 == 2 ) {
V_87 = F_30 ( V_2 , V_87 , V_145 ) ;
V_2 -> V_152 . V_153 = V_87 ;
V_4 -> V_158 = 3 ;
}
if ( V_4 -> V_158 == 3 && V_87 != NULL && V_151 > 0 )
F_23 ( V_2 , V_87 , V_150 , V_151 ) ;
}
static inline void F_32 ( struct V_1 * V_2 ,
unsigned char * V_150 ,
unsigned int V_151 )
{
struct V_107 * V_87 = V_2 -> V_152 . V_153 ;
struct V_144 * V_162 = & V_2 -> V_155 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_163 = false ;
if ( V_151 >= 2 ) {
if ( ( V_150 [ 0 ] == V_164 ) &&
( ( V_150 [ 1 ] & ~ V_165 ) == 0x00 ) ) {
V_4 -> V_108 = ! ( V_150 [ 1 ] &
V_166 ) ;
V_163 = V_150 [ 1 ] &
V_167 ;
V_150 += 2 ;
V_151 -= 2 ;
}
if ( V_2 -> V_99 && V_163 ) {
V_87 = F_30 ( V_2 , V_87 , V_162 ) ;
V_2 -> V_152 . V_153 = V_87 ;
}
}
if ( V_87 != NULL && V_151 > 0 )
F_23 ( V_2 , V_87 , V_150 , V_151 ) ;
if ( ! V_2 -> V_99 && V_163 ) {
V_87 = F_30 ( V_2 , V_87 , V_162 ) ;
V_2 -> V_152 . V_153 = V_87 ;
}
}
static inline int F_33 ( struct V_1 * V_2 , struct V_168 * V_168 )
{
int V_169 , V_170 , V_94 ;
unsigned char * V_171 ;
unsigned int V_172 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_173 )
return 0 ;
if ( V_168 -> V_134 < 0 )
F_25 ( V_2 , - 1 , V_168 -> V_134 ) ;
V_169 = F_34 ( V_168 -> V_174 ) ;
if ( V_169 )
V_170 = 1 ;
else
V_170 = V_168 -> V_175 ;
for ( V_94 = 0 ; V_94 < V_170 ; V_94 ++ ) {
if ( V_169 ) {
V_172 = V_168 -> V_176 ;
V_171 = V_168 -> V_177 ;
} else {
if ( V_168 -> V_178 [ V_94 ] . V_134 < 0 ) {
F_25 ( V_2 , V_94 ,
V_168 -> V_178 [ V_94 ] . V_134 ) ;
if ( V_168 -> V_178 [ V_94 ] . V_134 != - V_141 )
continue;
}
V_172 = V_168 -> V_178 [ V_94 ] . V_176 ;
if ( V_172 > V_2 -> V_101 ) {
F_20 ( L_25 ) ;
continue;
}
V_171 = V_168 -> V_177 +
V_168 -> V_178 [ V_94 ] . V_126 ;
}
if ( V_172 == 0 ) {
continue;
}
if ( V_2 -> V_49 )
F_32 ( V_2 ,
V_171 , V_172 ) ;
else
F_31 ( V_2 ,
V_171 , V_172 ) ;
}
return 1 ;
}
static int F_35 ( enum V_179 V_180 )
{
switch ( V_180 ) {
case V_181 :
return V_182 ;
case V_183 :
return V_184 ;
default:
F_36 () ;
}
}
static int F_37 ( struct V_1 * V_2 , enum V_179 V_180 )
{
int V_185 = F_35 ( V_180 ) ;
if ( V_2 -> V_186 & V_185 ) {
return - V_187 ;
}
V_2 -> V_186 |= V_185 ;
F_11 ( L_26 , V_185 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , enum V_179 V_180 )
{
int V_185 = F_35 ( V_180 ) ;
V_2 -> V_186 &= ~ V_185 ;
F_11 ( L_27 , V_185 ) ;
}
static int F_39 ( struct V_188 * V_189 , const void * V_190 ,
unsigned int * V_191 , unsigned int * V_192 ,
unsigned int V_193 [] , void * V_194 [] )
{
const struct V_195 * V_45 = V_190 ;
struct V_1 * V_2 = F_40 ( V_189 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_196 ;
if ( V_45 )
V_196 = V_45 -> V_45 . V_197 . V_198 ;
else
V_196 =
( V_4 -> V_73 * V_4 -> V_74 * V_4 -> V_47 -> V_199 + 7 ) >> 3 ;
if ( V_196 == 0 )
return - V_200 ;
if ( 0 == * V_191 )
* V_191 = 32 ;
* V_192 = 1 ;
V_193 [ 0 ] = V_196 ;
return 0 ;
}
static int
F_41 ( struct V_201 * V_109 )
{
struct V_202 * V_203 = F_42 ( V_109 ) ;
struct V_1 * V_2 = F_40 ( V_109 -> V_188 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_196 ;
F_11 ( L_28 , V_204 , V_203 -> V_113 ) ;
V_196 = ( V_4 -> V_73 * V_4 -> V_74 * V_4 -> V_47 -> V_199 + 7 ) >> 3 ;
if ( F_43 ( V_109 , 0 ) < V_196 ) {
F_11 ( L_29 ,
V_204 , F_43 ( V_109 , 0 ) , V_196 ) ;
return - V_200 ;
}
F_44 ( V_109 , 0 , V_196 ) ;
return 0 ;
}
int F_45 ( struct V_188 * V_189 , unsigned int V_205 )
{
struct V_1 * V_2 = F_40 ( V_189 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_206 V_207 ;
struct V_208 * V_209 ;
int V_210 = 0 ;
F_11 ( L_30 , V_204 ) ;
V_210 = F_37 ( V_2 , V_189 -> type ) ;
if ( V_210 )
return V_210 ;
if ( V_4 -> V_211 == 0 ) {
F_16 ( V_2 ) ;
F_4 ( V_2 ) ;
V_4 -> V_158 = - 1 ;
V_210 = F_46 ( V_2 , V_212 ,
V_2 -> V_99 ,
V_213 ,
V_2 -> V_101 ,
V_2 -> V_102 ,
F_33 ) ;
if ( V_210 < 0 )
return V_210 ;
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
V_207 . V_214 = V_4 -> V_214 ;
V_209 = (struct V_208 * ) V_189 -> V_209 ;
if ( V_209 && V_209 -> V_215 -> V_216 == V_217 )
V_207 . type = V_218 ;
else
V_207 . type = V_219 ;
F_5 ( & V_4 -> V_17 ,
0 , V_220 , V_221 , & V_207 ) ;
}
V_4 -> V_211 ++ ;
return V_210 ;
}
static void F_47 ( struct V_188 * V_189 )
{
struct V_1 * V_2 = F_40 ( V_189 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_144 * V_155 = & V_2 -> V_155 ;
unsigned long V_222 = 0 ;
F_11 ( L_30 , V_204 ) ;
F_38 ( V_2 , V_189 -> type ) ;
if ( V_4 -> V_211 -- == 1 ) {
F_48 ( V_2 , V_212 ) ;
}
F_49 ( & V_2 -> V_223 , V_222 ) ;
if ( V_2 -> V_152 . V_153 != NULL ) {
F_22 ( & V_2 -> V_152 . V_153 -> V_109 . V_117 ,
V_224 ) ;
V_2 -> V_152 . V_153 = NULL ;
}
while ( ! F_27 ( & V_155 -> V_146 ) ) {
struct V_107 * V_87 ;
V_87 = F_28 ( V_155 -> V_146 . V_147 , struct V_107 , V_148 ) ;
F_29 ( & V_87 -> V_148 ) ;
F_22 ( & V_87 -> V_109 . V_117 , V_224 ) ;
}
F_50 ( & V_2 -> V_223 , V_222 ) ;
}
void F_51 ( struct V_188 * V_189 )
{
struct V_1 * V_2 = F_40 ( V_189 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_144 * V_157 = & V_2 -> V_157 ;
unsigned long V_222 = 0 ;
F_11 ( L_30 , V_204 ) ;
F_38 ( V_2 , V_189 -> type ) ;
if ( V_4 -> V_211 -- == 1 ) {
F_48 ( V_2 , V_212 ) ;
}
F_49 ( & V_2 -> V_223 , V_222 ) ;
if ( V_2 -> V_152 . V_154 != NULL ) {
F_22 ( & V_2 -> V_152 . V_154 -> V_109 . V_117 ,
V_224 ) ;
V_2 -> V_152 . V_154 = NULL ;
}
while ( ! F_27 ( & V_157 -> V_146 ) ) {
struct V_107 * V_87 ;
V_87 = F_28 ( V_157 -> V_146 . V_147 , struct V_107 , V_148 ) ;
F_29 ( & V_87 -> V_148 ) ;
F_22 ( & V_87 -> V_109 . V_117 , V_224 ) ;
}
F_50 ( & V_2 -> V_223 , V_222 ) ;
}
static void
F_52 ( struct V_201 * V_109 )
{
struct V_202 * V_203 = F_42 ( V_109 ) ;
struct V_1 * V_2 = F_40 ( V_109 -> V_188 ) ;
struct V_107 * V_87 =
F_53 ( V_203 , struct V_107 , V_109 ) ;
struct V_144 * V_155 = & V_2 -> V_155 ;
unsigned long V_222 = 0 ;
F_11 ( L_30 , V_204 ) ;
V_87 -> V_149 = F_54 ( V_109 , 0 ) ;
V_87 -> V_131 = F_43 ( V_109 , 0 ) ;
F_49 ( & V_2 -> V_223 , V_222 ) ;
F_55 ( & V_87 -> V_148 , & V_155 -> V_146 ) ;
F_50 ( & V_2 -> V_223 , V_222 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_210 ;
struct V_188 * V_225 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_225 = & V_4 -> V_226 ;
V_225 -> type = V_181 ;
V_225 -> V_227 = V_228 | V_229 | V_230 | V_231 ;
V_225 -> V_232 = V_233 ;
V_225 -> V_234 = V_2 ;
V_225 -> V_235 = sizeof( struct V_107 ) ;
V_225 -> V_236 = & V_237 ;
V_225 -> V_238 = & V_239 ;
V_210 = F_57 ( V_225 ) ;
if ( V_210 < 0 )
return V_210 ;
V_225 = & V_4 -> V_240 ;
V_225 -> type = V_183 ;
V_225 -> V_227 = V_228 | V_229 | V_230 ;
V_225 -> V_232 = V_233 ;
V_225 -> V_234 = V_2 ;
V_225 -> V_235 = sizeof( struct V_107 ) ;
V_225 -> V_236 = & V_241 ;
V_225 -> V_238 = & V_239 ;
V_210 = F_57 ( V_225 ) ;
if ( V_210 < 0 )
return V_210 ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 , int V_242 )
{
struct V_16 * V_17 = & V_2 -> V_4 -> V_17 ;
V_2 -> V_22 = V_242 ;
V_2 -> V_243 = F_6 ( V_242 ) -> V_244 ;
V_2 -> V_245 = F_6 ( V_242 ) -> V_246 ;
if ( ! V_2 -> V_245 )
V_2 -> V_245 = V_247 ;
F_5 ( V_17 , 0 , V_20 , V_21 ,
F_6 ( V_242 ) -> V_23 , 0 , 0 ) ;
if ( V_2 -> V_5 . V_248 ) {
if ( V_2 -> V_249 ) {
F_5 ( V_17 , 0 , V_250 ,
V_251 , V_2 -> V_249 ) ;
}
F_5 ( V_17 , 0 , V_250 , V_21 ,
V_2 -> V_243 ,
F_59 ( V_252 ) , 0 ) ;
}
if ( V_2 -> V_5 . V_253 != V_254 ) {
F_5 ( V_17 , 0 , V_250 , V_21 ,
V_2 -> V_243 , V_2 -> V_245 , 0 ) ;
}
F_60 ( V_2 ) ;
}
static void F_61 ( struct V_255 * V_256 , void * V_257 )
{
struct V_1 * V_2 = V_257 ;
switch ( V_256 -> V_258 ) {
case V_259 :
V_2 -> V_260 = V_256 -> V_261 ;
F_60 ( V_2 ) ;
break;
case V_262 :
V_2 -> V_263 = V_256 -> V_261 ;
F_60 ( V_2 ) ;
break;
}
}
static int F_62 ( struct V_255 * V_256 )
{
struct V_3 * V_4 =
F_53 ( V_256 -> V_264 , struct V_3 , V_265 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_44 = - V_200 ;
switch ( V_256 -> V_258 ) {
case V_259 :
V_2 -> V_260 = V_256 -> V_261 ;
V_44 = F_60 ( V_2 ) ;
break;
case V_262 :
V_2 -> V_263 = V_256 -> V_261 ;
V_44 = F_60 ( V_2 ) ;
break;
case V_266 :
V_44 = F_8 ( V_2 , V_25 , V_256 -> V_261 ) ;
break;
case V_267 :
V_44 = F_8 ( V_2 , V_27 , V_256 -> V_261 ) ;
break;
case V_268 :
V_44 = F_8 ( V_2 , V_29 , V_256 -> V_261 ) ;
break;
case V_269 :
V_44 = F_8 ( V_2 , V_31 , V_256 -> V_261 ) ;
break;
case V_270 :
V_44 = F_8 ( V_2 , V_33 , V_256 -> V_261 ) ;
break;
case V_271 :
V_44 = F_8 ( V_2 , V_35 , V_256 -> V_261 ) ;
break;
}
return ( V_44 < 0 ) ? V_44 : 0 ;
}
static void F_63 ( struct V_1 * V_2 ,
unsigned int V_73 , unsigned int V_74 ,
unsigned int * V_91 , unsigned int * V_92 )
{
unsigned int V_272 = F_1 ( V_2 ) ;
unsigned int V_273 = F_2 ( V_2 ) ;
* V_91 = ( ( ( unsigned long ) V_272 ) << 12 ) / V_73 - 4096L ;
if ( * V_91 > V_274 )
* V_91 = V_274 ;
* V_92 = ( ( ( unsigned long ) V_273 ) << 12 ) / V_74 - 4096L ;
if ( * V_92 > V_274 )
* V_92 = V_274 ;
}
static void F_64 ( struct V_1 * V_2 ,
unsigned int V_91 , unsigned int V_92 ,
unsigned int * V_73 , unsigned int * V_74 )
{
unsigned int V_272 = F_1 ( V_2 ) ;
unsigned int V_273 = F_2 ( V_2 ) ;
* V_73 = ( ( ( unsigned long ) V_272 ) << 12 ) / ( V_91 + 4096L ) ;
* V_74 = ( ( ( unsigned long ) V_273 ) << 12 ) / ( V_92 + 4096L ) ;
}
static int F_65 ( struct V_275 * V_275 , void * V_257 ,
struct V_195 * V_207 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_207 -> V_45 . V_197 . V_73 = V_4 -> V_73 ;
V_207 -> V_45 . V_197 . V_74 = V_4 -> V_74 ;
V_207 -> V_45 . V_197 . V_276 = V_4 -> V_47 -> V_277 ;
V_207 -> V_45 . V_197 . V_129 = ( V_4 -> V_73 * V_4 -> V_47 -> V_199 + 7 ) >> 3 ;
V_207 -> V_45 . V_197 . V_198 = V_207 -> V_45 . V_197 . V_129 * V_4 -> V_74 ;
V_207 -> V_45 . V_197 . V_278 = V_279 ;
if ( V_4 -> V_112 )
V_207 -> V_45 . V_197 . V_113 = V_114 ;
else
V_207 -> V_45 . V_197 . V_113 = V_4 -> V_280 ?
V_115 : V_281 ;
return 0 ;
}
static struct V_282 * F_67 ( unsigned int V_277 )
{
unsigned int V_94 ;
for ( V_94 = 0 ; V_94 < F_68 ( V_47 ) ; V_94 ++ )
if ( V_47 [ V_94 ] . V_277 == V_277 )
return & V_47 [ V_94 ] ;
return NULL ;
}
static int F_69 ( struct V_275 * V_275 , void * V_257 ,
struct V_195 * V_207 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_73 = V_207 -> V_45 . V_197 . V_73 ;
unsigned int V_74 = V_207 -> V_45 . V_197 . V_74 ;
unsigned int V_272 = F_1 ( V_2 ) ;
unsigned int V_273 = F_2 ( V_2 ) ;
unsigned int V_91 , V_92 ;
struct V_282 * V_45 ;
V_45 = F_67 ( V_207 -> V_45 . V_197 . V_276 ) ;
if ( ! V_45 ) {
F_11 ( L_31 ,
V_207 -> V_45 . V_197 . V_276 ) ;
return - V_200 ;
}
if ( V_2 -> V_5 . V_86 ) {
V_74 = V_74 > ( 3 * V_273 / 4 ) ? V_273 : V_273 / 2 ;
V_73 = V_73 > ( 3 * V_272 / 4 ) ? V_272 : V_272 / 2 ;
if ( V_73 == V_272 && V_74 == V_273 )
V_73 /= 2 ;
} else {
F_70 ( & V_73 , 48 , V_272 , 1 , & V_74 , 32 , V_273 ,
1 , 0 ) ;
}
F_63 ( V_2 , V_73 , V_74 , & V_91 , & V_92 ) ;
F_64 ( V_2 , V_91 , V_92 , & V_73 , & V_74 ) ;
V_207 -> V_45 . V_197 . V_73 = V_73 ;
V_207 -> V_45 . V_197 . V_74 = V_74 ;
V_207 -> V_45 . V_197 . V_276 = V_45 -> V_277 ;
V_207 -> V_45 . V_197 . V_129 = ( V_73 * V_45 -> V_199 + 7 ) >> 3 ;
V_207 -> V_45 . V_197 . V_198 = V_207 -> V_45 . V_197 . V_129 * V_74 ;
V_207 -> V_45 . V_197 . V_278 = V_279 ;
if ( V_4 -> V_112 )
V_207 -> V_45 . V_197 . V_113 = V_114 ;
else
V_207 -> V_45 . V_197 . V_113 = V_4 -> V_280 ?
V_115 : V_281 ;
V_207 -> V_45 . V_197 . V_257 = 0 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned int V_277 ,
unsigned V_73 , unsigned V_74 )
{
struct V_282 * V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_45 = F_67 ( V_277 ) ;
if ( ! V_45 )
return - V_200 ;
V_4 -> V_47 = V_45 ;
V_4 -> V_73 = V_73 ;
V_4 -> V_74 = V_74 ;
F_63 ( V_2 , V_4 -> V_73 , V_4 -> V_74 ,
& V_4 -> V_91 , & V_4 -> V_92 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_72 ( struct V_275 * V_275 , void * V_257 ,
struct V_195 * V_207 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_73 ( & V_4 -> V_226 ) )
return - V_187 ;
F_69 ( V_275 , V_257 , V_207 ) ;
return F_71 ( V_2 , V_207 -> V_45 . V_197 . V_276 ,
V_207 -> V_45 . V_197 . V_73 , V_207 -> V_45 . V_197 . V_74 ) ;
}
static int F_74 ( struct V_275 * V_275 , void * V_257 , T_3 * V_10 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
* V_10 = V_2 -> V_4 -> V_10 ;
return 0 ;
}
static int F_75 ( struct V_275 * V_275 , void * V_257 , T_3 * V_10 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_20 , V_283 , V_10 ) ;
return 0 ;
}
static int F_76 ( struct V_275 * V_275 , void * V_257 , T_3 V_10 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_195 V_207 ;
if ( V_10 == V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_211 > 0 )
return - V_187 ;
V_4 -> V_10 = V_10 ;
V_207 . V_45 . V_197 . V_73 = 720 ;
V_207 . V_45 . V_197 . V_74 = ( V_10 & V_60 ) ? 480 : 576 ;
F_69 ( V_275 , V_257 , & V_207 ) ;
V_4 -> V_73 = V_207 . V_45 . V_197 . V_73 ;
V_4 -> V_74 = V_207 . V_45 . V_197 . V_74 ;
F_63 ( V_2 , V_4 -> V_73 , V_4 -> V_74 ,
& V_4 -> V_91 , & V_4 -> V_92 ) ;
F_15 ( V_2 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_284 , V_4 -> V_10 ) ;
return 0 ;
}
static int F_77 ( struct V_275 * V_275 , void * V_257 ,
struct V_285 * V_286 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_210 = 0 ;
V_286 -> V_287 . V_288 . V_289 = V_290 ;
if ( V_2 -> V_5 . V_6 )
V_210 = F_78 ( & V_4 -> V_17 , 0 ,
V_20 , V_291 , V_286 ) ;
else
F_79 ( V_4 -> V_10 ,
& V_286 -> V_287 . V_288 . V_292 ) ;
return V_210 ;
}
static int F_80 ( struct V_275 * V_275 , void * V_257 ,
struct V_285 * V_286 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
V_286 -> V_287 . V_288 . V_289 = V_290 ;
return F_78 ( & V_2 -> V_4 -> V_17 ,
0 , V_20 , V_293 , V_286 ) ;
}
static int F_81 ( struct V_275 * V_275 , void * V_257 ,
struct V_294 * V_94 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
unsigned int V_295 ;
V_295 = V_94 -> V_242 ;
if ( V_295 >= V_296 )
return - V_200 ;
if ( 0 == F_6 ( V_295 ) -> type )
return - V_200 ;
V_94 -> V_242 = V_295 ;
V_94 -> type = V_297 ;
strcpy ( V_94 -> V_298 , V_299 [ F_6 ( V_295 ) -> type ] ) ;
if ( ( V_300 == F_6 ( V_295 ) -> type ) ||
( V_301 == F_6 ( V_295 ) -> type ) )
V_94 -> type = V_302 ;
V_94 -> V_303 = V_2 -> V_4 -> V_215 . V_304 ;
if ( V_2 -> V_5 . V_6 )
V_94 -> V_305 = 0 ;
return 0 ;
}
static int F_82 ( struct V_275 * V_275 , void * V_257 , unsigned int * V_94 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
* V_94 = V_2 -> V_22 ;
return 0 ;
}
static int F_83 ( struct V_275 * V_275 , void * V_257 , unsigned int V_94 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
if ( V_94 >= V_296 )
return - V_200 ;
if ( 0 == F_6 ( V_94 ) -> type )
return - V_200 ;
F_58 ( V_2 , V_94 ) ;
return 0 ;
}
static int F_84 ( struct V_275 * V_275 , void * V_257 , struct V_306 * V_307 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
switch ( V_307 -> V_242 ) {
case V_308 :
strcpy ( V_307 -> V_298 , L_32 ) ;
break;
case V_309 :
strcpy ( V_307 -> V_298 , L_33 ) ;
break;
case V_310 :
strcpy ( V_307 -> V_298 , L_34 ) ;
break;
case V_311 :
strcpy ( V_307 -> V_298 , L_35 ) ;
break;
case V_312 :
strcpy ( V_307 -> V_298 , L_36 ) ;
break;
case V_313 :
strcpy ( V_307 -> V_298 , L_37 ) ;
break;
case V_314 :
strcpy ( V_307 -> V_298 , L_38 ) ;
break;
case V_315 :
strcpy ( V_307 -> V_298 , L_39 ) ;
break;
default:
return - V_200 ;
}
V_307 -> V_242 = V_2 -> V_243 ;
V_307 -> V_316 = V_317 ;
return 0 ;
}
static int F_85 ( struct V_275 * V_275 , void * V_257 , const struct V_306 * V_307 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
if ( V_307 -> V_242 >= V_296 )
return - V_200 ;
if ( 0 == F_6 ( V_307 -> V_242 ) -> type )
return - V_200 ;
V_2 -> V_243 = F_6 ( V_307 -> V_242 ) -> V_244 ;
V_2 -> V_245 = F_6 ( V_307 -> V_242 ) -> V_246 ;
if ( ! V_2 -> V_245 )
V_2 -> V_245 = V_247 ;
return 0 ;
}
static int F_86 ( struct V_275 * V_275 , void * V_257 ,
struct V_318 * V_319 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
if ( 0 != V_319 -> V_242 )
return - V_200 ;
strcpy ( V_319 -> V_298 , L_40 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_220 , V_320 , V_319 ) ;
return 0 ;
}
static int F_87 ( struct V_275 * V_275 , void * V_257 ,
const struct V_318 * V_319 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
if ( 0 != V_319 -> V_242 )
return - V_200 ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_220 , V_321 , V_319 ) ;
return 0 ;
}
static int F_88 ( struct V_275 * V_275 , void * V_257 ,
struct V_206 * V_207 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_207 -> V_220 )
return - V_200 ;
V_207 -> V_214 = V_4 -> V_214 ;
return 0 ;
}
static int F_89 ( struct V_275 * V_275 , void * V_257 ,
const struct V_206 * V_207 )
{
struct V_206 V_322 = * V_207 ;
struct V_1 * V_2 = F_66 ( V_275 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_207 -> V_220 )
return - V_200 ;
F_5 ( & V_4 -> V_17 , 0 , V_220 , V_221 , V_207 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_220 , V_323 , & V_322 ) ;
V_4 -> V_214 = V_322 . V_214 ;
return 0 ;
}
static int F_90 ( struct V_275 * V_275 , void * V_257 ,
struct V_324 * V_325 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
if ( V_325 -> V_326 . V_327 > 1 )
return - V_200 ;
if ( V_325 -> V_326 . V_327 == 1 )
F_91 ( V_325 -> V_298 , L_41 , sizeof( V_325 -> V_298 ) ) ;
else
F_91 ( V_325 -> V_298 ,
V_2 -> V_4 -> V_17 . V_298 , sizeof( V_325 -> V_298 ) ) ;
return 0 ;
}
static int F_92 ( int V_48 )
{
switch ( V_48 ) {
case V_328 :
case V_88 :
case V_89 :
return 2 ;
default:
return 1 ;
}
}
static int F_93 ( struct V_275 * V_275 , void * V_257 ,
struct V_329 * V_48 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
int V_44 ;
if ( V_48 -> V_326 . V_327 > 1 )
return - V_200 ;
if ( V_48 -> V_326 . V_327 ) {
V_44 = F_94 ( V_2 , V_48 -> V_48 ) ;
if ( V_44 < 0 )
return V_44 ;
V_48 -> V_261 = V_44 ;
V_48 -> V_196 = 1 ;
return 0 ;
}
V_48 -> V_196 = F_92 ( V_48 -> V_48 ) ;
if ( V_48 -> V_196 == 1 ) {
V_44 = F_95 ( V_2 , V_48 -> V_48 ) ;
if ( V_44 < 0 )
return V_44 ;
V_48 -> V_261 = V_44 ;
} else {
T_4 V_261 = 0 ;
V_44 = V_2 -> V_330 ( V_2 , V_331 ,
V_48 -> V_48 , ( char * ) & V_261 , 2 ) ;
if ( V_44 < 0 )
return V_44 ;
V_48 -> V_261 = F_96 ( V_261 ) ;
}
return 0 ;
}
static int F_97 ( struct V_275 * V_275 , void * V_257 ,
const struct V_329 * V_48 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
T_4 V_87 ;
if ( V_48 -> V_326 . V_327 > 1 )
return - V_200 ;
if ( V_48 -> V_326 . V_327 )
return F_98 ( V_2 , V_48 -> V_48 , V_48 -> V_261 ) ;
V_87 = F_99 ( V_48 -> V_261 ) ;
return F_12 ( V_2 , V_48 -> V_48 , ( char * ) & V_87 ,
F_92 ( V_48 -> V_48 ) ) ;
}
static int F_100 ( struct V_275 * V_275 , void * V_257 ,
struct V_332 * V_333 )
{
struct V_334 * V_215 = F_101 ( V_275 ) ;
struct V_1 * V_2 = F_66 ( V_275 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_91 ( V_333 -> V_335 , L_42 , sizeof( V_333 -> V_335 ) ) ;
F_91 ( V_333 -> V_336 , V_337 [ V_2 -> V_338 ] . V_298 , sizeof( V_333 -> V_336 ) ) ;
F_102 ( V_2 -> V_105 , V_333 -> V_339 , sizeof( V_333 -> V_339 ) ) ;
if ( V_215 -> V_216 == V_340 )
V_333 -> V_341 = V_342 |
V_343 | V_344 ;
else if ( V_215 -> V_216 == V_217 )
V_333 -> V_341 = V_345 ;
else
V_333 -> V_341 = V_342 | V_346 ;
if ( V_2 -> V_347 != V_348 )
V_333 -> V_341 |= V_349 ;
if ( V_2 -> V_350 != V_351 )
V_333 -> V_341 |= V_352 ;
V_333 -> V_305 = V_333 -> V_341 | V_353 |
V_342 | V_343 | V_344 ;
if ( F_103 ( & V_4 -> V_354 ) )
V_333 -> V_305 |= V_346 ;
if ( F_103 ( & V_4 -> V_355 ) )
V_333 -> V_305 |= V_345 ;
return 0 ;
}
static int F_104 ( struct V_275 * V_275 , void * V_257 ,
struct V_356 * V_207 )
{
if ( F_105 ( V_207 -> V_242 >= F_68 ( V_47 ) ) )
return - V_200 ;
F_91 ( V_207 -> V_357 , V_47 [ V_207 -> V_242 ] . V_298 , sizeof( V_207 -> V_357 ) ) ;
V_207 -> V_276 = V_47 [ V_207 -> V_242 ] . V_277 ;
return 0 ;
}
static int F_106 ( struct V_275 * V_275 , void * V_257 ,
struct V_358 * V_359 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
struct V_282 * V_45 ;
unsigned int V_272 = F_1 ( V_2 ) ;
unsigned int V_273 = F_2 ( V_2 ) ;
V_45 = F_67 ( V_359 -> V_360 ) ;
if ( ! V_45 ) {
F_11 ( L_31 ,
V_359 -> V_360 ) ;
return - V_200 ;
}
if ( V_2 -> V_5 . V_86 ) {
if ( V_359 -> V_242 > 1 )
return - V_200 ;
V_359 -> type = V_361 ;
V_359 -> V_362 . V_73 = V_272 / ( 1 + V_359 -> V_242 ) ;
V_359 -> V_362 . V_74 = V_273 / ( 1 + V_359 -> V_242 ) ;
return 0 ;
}
if ( V_359 -> V_242 != 0 )
return - V_200 ;
V_359 -> type = V_363 ;
F_64 ( V_2 , V_274 , V_274 ,
& V_359 -> V_364 . V_365 , & V_359 -> V_364 . V_366 ) ;
if ( V_359 -> V_364 . V_365 < 48 )
V_359 -> V_364 . V_365 = 48 ;
if ( V_359 -> V_364 . V_366 < 38 )
V_359 -> V_364 . V_366 = 38 ;
V_359 -> V_364 . V_367 = V_272 ;
V_359 -> V_364 . V_368 = V_273 ;
V_359 -> V_364 . V_369 = 1 ;
V_359 -> V_364 . V_370 = 1 ;
return 0 ;
}
static int F_107 ( struct V_275 * V_275 , void * V_257 ,
struct V_195 * V_47 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_47 -> V_45 . V_371 . V_372 = V_4 -> V_57 ;
V_47 -> V_45 . V_371 . V_373 = V_374 ;
V_47 -> V_45 . V_371 . V_126 = 0 ;
V_47 -> V_45 . V_371 . V_222 = 0 ;
V_47 -> V_45 . V_371 . V_375 = 6750000 * 4 / 2 ;
V_47 -> V_45 . V_371 . V_205 [ 0 ] = V_4 -> V_59 ;
V_47 -> V_45 . V_371 . V_205 [ 1 ] = V_4 -> V_59 ;
memset ( V_47 -> V_45 . V_371 . V_376 , 0 , sizeof( V_47 -> V_45 . V_371 . V_376 ) ) ;
if ( V_4 -> V_10 & V_60 ) {
V_47 -> V_45 . V_371 . V_377 [ 0 ] = 10 ;
V_47 -> V_45 . V_371 . V_377 [ 1 ] = 273 ;
} else if ( V_4 -> V_10 & V_11 ) {
V_47 -> V_45 . V_371 . V_377 [ 0 ] = 6 ;
V_47 -> V_45 . V_371 . V_377 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_108 ( struct V_275 * V_275 , void * V_257 ,
struct V_318 * V_319 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
if ( F_105 ( V_319 -> V_242 > 0 ) )
return - V_200 ;
strcpy ( V_319 -> V_298 , L_43 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_220 , V_320 , V_319 ) ;
return 0 ;
}
static int F_109 ( struct V_275 * V_275 , void * V_257 ,
const struct V_318 * V_319 )
{
struct V_1 * V_2 = F_66 ( V_275 ) ;
if ( 0 != V_319 -> V_242 )
return - V_200 ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_220 , V_321 , V_319 ) ;
return 0 ;
}
static void F_110 ( struct V_378 * V_379 )
{
struct V_3 * V_4 = F_53 ( V_379 , struct V_3 , V_379 ) ;
V_4 -> V_2 -> V_4 = NULL ;
F_111 ( V_4 ) ;
}
static int F_112 ( struct V_275 * V_380 )
{
struct V_334 * V_215 = F_101 ( V_380 ) ;
struct V_1 * V_2 = F_66 ( V_380 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
enum V_179 V_381 = 0 ;
int V_44 ;
switch ( V_215 -> V_216 ) {
case V_340 :
V_381 = V_181 ;
break;
case V_382 :
V_381 = V_183 ;
break;
case V_217 :
break;
default:
return - V_200 ;
}
F_11 ( L_44 ,
F_113 ( V_215 ) , V_383 [ V_381 ] ,
V_4 -> V_384 ) ;
if ( F_114 ( & V_2 -> V_385 ) )
return - V_386 ;
V_44 = F_115 ( V_380 ) ;
if ( V_44 ) {
F_18 ( L_45 ,
V_204 , V_44 ) ;
F_116 ( & V_2 -> V_385 ) ;
return V_44 ;
}
if ( V_4 -> V_384 == 0 ) {
F_117 ( V_2 , V_212 ) ;
if ( V_215 -> V_216 != V_217 )
F_15 ( V_2 ) ;
F_4 ( V_2 ) ;
}
if ( V_215 -> V_216 == V_217 ) {
F_11 ( L_46 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_220 , V_387 ) ;
}
F_118 ( & V_2 -> V_379 ) ;
F_118 ( & V_4 -> V_379 ) ;
V_4 -> V_384 ++ ;
F_116 ( & V_2 -> V_385 ) ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_388 ) {
return 0 ;
}
if ( ! V_2 -> V_389 ) {
return 0 ;
}
if ( V_4 == NULL )
return 0 ;
F_120 ( L_47 ) ;
F_121 ( & V_2 -> V_385 ) ;
F_122 ( & V_4 -> V_17 ) ;
F_48 ( V_2 , V_212 ) ;
if ( F_103 ( & V_4 -> V_355 ) ) {
F_120 ( L_48 ,
F_113 ( & V_4 -> V_355 ) ) ;
F_123 ( & V_4 -> V_355 ) ;
}
if ( F_103 ( & V_4 -> V_354 ) ) {
F_120 ( L_48 ,
F_113 ( & V_4 -> V_354 ) ) ;
F_123 ( & V_4 -> V_354 ) ;
}
if ( F_103 ( & V_4 -> V_215 ) ) {
F_120 ( L_48 ,
F_113 ( & V_4 -> V_215 ) ) ;
F_123 ( & V_4 -> V_215 ) ;
}
F_124 ( & V_4 -> V_265 ) ;
F_125 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_390 ) {
F_126 ( V_4 -> V_390 ) ;
V_4 -> V_390 = NULL ;
}
F_127 ( & V_4 -> V_379 , F_110 ) ;
F_116 ( & V_2 -> V_385 ) ;
F_127 ( & V_2 -> V_379 , V_391 ) ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 )
{
if ( V_2 -> V_388 )
return 0 ;
if ( ! V_2 -> V_389 )
return 0 ;
F_120 ( L_49 ) ;
F_129 ( V_2 ) ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 )
{
if ( V_2 -> V_388 )
return 0 ;
if ( ! V_2 -> V_389 )
return 0 ;
F_120 ( L_50 ) ;
return 0 ;
}
static int F_131 ( struct V_275 * V_380 )
{
struct V_1 * V_2 = F_66 ( V_380 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_93 ;
F_11 ( L_51 , V_4 -> V_384 ) ;
F_132 ( V_380 ) ;
F_121 ( & V_2 -> V_385 ) ;
if ( V_4 -> V_384 == 1 ) {
if ( V_2 -> V_173 )
goto exit;
F_5 ( & V_4 -> V_17 , 0 , V_18 , V_392 , 0 ) ;
F_117 ( V_2 , V_393 ) ;
V_2 -> V_96 = 0 ;
F_11 ( L_52 ) ;
V_93 = F_17 ( V_2 -> V_105 , 0 , 0 ) ;
if ( V_93 < 0 ) {
F_18 ( L_53
L_54 , V_93 ) ;
}
}
exit:
V_4 -> V_384 -- ;
F_127 ( & V_4 -> V_379 , F_110 ) ;
F_116 ( & V_2 -> V_385 ) ;
F_127 ( & V_2 -> V_379 , V_391 ) ;
return 0 ;
}
static void F_133 ( struct V_1 * V_2 ,
struct V_334 * V_394 ,
const struct V_334 * V_395 ,
const char * V_396 )
{
* V_394 = * V_395 ;
V_394 -> V_17 = & V_2 -> V_4 -> V_17 ;
V_394 -> V_385 = & V_2 -> V_385 ;
if ( V_2 -> V_5 . V_6 )
V_394 -> V_304 = 0 ;
snprintf ( V_394 -> V_298 , sizeof( V_394 -> V_298 ) , L_55 ,
V_2 -> V_298 , V_396 ) ;
F_134 ( V_394 , V_2 ) ;
}
static void F_135 ( struct V_1 * V_2 , unsigned short V_397 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_16 * V_17 = & V_4 -> V_17 ;
struct V_398 V_399 ;
struct V_206 V_207 ;
memset ( & V_399 , 0 , sizeof( V_399 ) ) ;
V_399 . V_400 = V_401 | V_402 ;
V_399 . V_403 = V_404 ;
if ( V_2 -> V_5 . V_405 . type ) {
V_399 . type = V_2 -> V_5 . V_405 . type ;
V_399 . V_327 = V_2 -> V_5 . V_406 ;
F_5 ( V_17 ,
0 , V_220 , V_407 , & V_399 ) ;
}
if ( ( V_2 -> V_350 != V_351 ) && ( V_2 -> V_350 ) ) {
V_399 . type = V_2 -> V_350 ;
V_399 . V_327 = V_397 ;
F_5 ( V_17 ,
0 , V_220 , V_407 , & V_399 ) ;
}
if ( V_2 -> V_5 . V_408 ) {
struct V_409 V_410 ;
V_410 . V_220 = V_411 ;
V_410 . V_257 = & V_2 -> V_5 . V_408 ;
F_5 ( V_17 ,
0 , V_220 , V_412 , & V_410 ) ;
}
if ( V_2 -> V_350 == V_413 ) {
struct V_409 V_414 ;
struct V_415 V_416 ;
memset ( & V_414 , 0 , sizeof( V_414 ) ) ;
memset ( & V_416 , 0 , sizeof( V_416 ) ) ;
F_136 ( V_2 , & V_416 ) ;
V_414 . V_220 = V_413 ;
V_414 . V_257 = & V_416 ;
F_5 ( V_17 , 0 , V_220 , V_412 , & V_414 ) ;
}
V_207 . V_220 = 0 ;
V_207 . type = V_219 ;
V_207 . V_214 = 9076 ;
V_4 -> V_214 = V_207 . V_214 ;
F_5 ( V_17 , 0 , V_220 , V_221 , & V_207 ) ;
}
static int F_137 ( struct V_1 * V_2 )
{
T_1 V_261 ;
int V_44 ;
unsigned int V_272 ;
struct V_417 * V_418 ;
struct V_3 * V_4 ;
if ( V_2 -> V_388 ) {
return 0 ;
}
if ( ! V_2 -> V_389 ) {
return 0 ;
}
F_120 ( L_56 ) ;
F_121 ( & V_2 -> V_385 ) ;
V_4 = F_138 ( sizeof( struct V_3 ) , V_419 ) ;
if ( V_4 == NULL ) {
F_120 ( L_57 ) ;
F_116 ( & V_2 -> V_385 ) ;
return - V_420 ;
}
F_139 ( & V_4 -> V_379 ) ;
V_4 -> V_2 = V_2 ;
V_2 -> V_4 = V_4 ;
V_44 = F_140 ( & V_2 -> V_105 -> V_2 , & V_4 -> V_17 ) ;
if ( V_44 < 0 ) {
F_18 ( L_58 ) ;
goto V_421;
}
V_418 = & V_4 -> V_265 ;
F_141 ( V_418 , 8 ) ;
V_4 -> V_17 . V_265 = V_418 ;
if ( V_2 -> V_5 . V_6 )
V_4 -> V_112 = true ;
V_4 -> V_52 = 0x10 ;
V_4 -> V_53 = V_422 |
V_423 ;
if ( V_2 -> V_5 . V_248 )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_424 [ V_2 -> V_425 ] ,
L_59 , 0 , V_426 ) ;
if ( V_2 -> V_5 . V_427 == V_428 )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_424 [ V_2 -> V_425 ] ,
L_60 , 0 , V_429 ) ;
if ( V_2 -> V_5 . V_427 == V_430 )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_424 [ V_2 -> V_425 ] ,
L_61 , 0 , V_431 ) ;
if ( V_2 -> V_5 . V_253 == V_432 )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_424 [ V_2 -> V_425 ] ,
L_62 , V_2 -> V_5 . V_433 , NULL ) ;
if ( V_2 -> V_5 . V_350 != V_351 ) {
unsigned short V_397 = V_2 -> V_5 . V_397 ;
int V_434 = ( V_2 -> V_5 . V_408 & V_435 ) ;
if ( V_2 -> V_5 . V_405 . type )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_424 [ V_2 -> V_425 ] ,
L_63 , V_2 -> V_5 . V_406 ,
NULL ) ;
if ( V_434 )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_424 [ V_2 -> V_425 ] ,
L_63 , 0 ,
F_143 ( V_436 ) ) ;
if ( V_397 == 0 ) {
enum V_437 type =
V_434 ? V_438 : V_439 ;
struct V_440 * V_441 ;
V_441 = F_142 ( & V_4 -> V_17 ,
& V_2 -> V_424 [ V_2 -> V_425 ] ,
L_63 , 0 ,
F_143 ( type ) ) ;
if ( V_441 )
V_397 = F_144 ( V_441 ) ;
} else {
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_424 [ V_2 -> V_425 ] ,
L_63 , V_397 , NULL ) ;
}
F_135 ( V_2 , V_397 ) ;
}
if ( V_2 -> V_442 != V_443 )
F_145 ( V_2 ) ;
V_44 = F_146 ( V_2 ) ;
if ( V_44 < 0 ) {
F_18 ( L_64 ,
V_204 , V_44 ) ;
goto V_444;
}
if ( V_2 -> V_445 . V_446 != V_447 ) {
F_147 ( V_418 , & V_448 ,
V_259 , 0 , 1 , 1 , 1 ) ;
F_147 ( V_418 , & V_448 ,
V_262 , 0 , 0x1f , 1 , 0x1f ) ;
} else {
F_148 ( F_149 ( V_418 , V_259 ) ,
F_61 , V_2 ) ;
F_148 ( F_149 ( V_418 , V_262 ) ,
F_61 , V_2 ) ;
}
F_4 ( V_2 ) ;
F_150 ( & V_2 -> V_155 . V_146 ) ;
F_150 ( & V_2 -> V_157 . V_146 ) ;
if ( V_2 -> V_5 . V_248 ) {
V_44 = F_8 ( V_2 , V_449 , 0xf7 ) ;
if ( V_44 < 0 ) {
F_18 ( L_65 ,
V_204 , V_44 ) ;
goto V_444;
}
F_151 ( 3 ) ;
V_44 = F_8 ( V_2 , V_449 , 0xff ) ;
if ( V_44 < 0 ) {
F_18 ( L_66 ,
V_204 , V_44 ) ;
goto V_444;
}
F_151 ( 3 ) ;
}
V_4 -> V_10 = V_450 ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_284 , V_4 -> V_10 ) ;
V_4 -> V_280 = V_451 ;
V_4 -> V_47 = & V_47 [ 0 ] ;
V_272 = F_1 ( V_2 ) ;
if ( V_2 -> V_5 . V_86 )
V_272 /= 2 ;
F_71 ( V_2 , V_47 [ 0 ] . V_277 ,
V_272 , F_2 ( V_2 ) ) ;
F_58 ( V_2 , 0 ) ;
V_2 -> V_260 = 1 ;
V_2 -> V_263 = 0x1f ;
V_261 = ( T_1 ) F_95 ( V_2 , V_452 ) ;
F_8 ( V_2 , V_452 ,
( V_453 | V_261 ) ) ;
F_9 ( V_2 ) ;
if ( NULL == F_149 ( V_418 , V_266 ) )
F_147 ( V_418 , & V_448 ,
V_266 ,
0 , 0x1f , 1 , V_26 ) ;
if ( NULL == F_149 ( V_418 , V_267 ) )
F_147 ( V_418 , & V_448 ,
V_267 ,
- 0x80 , 0x7f , 1 , V_28 ) ;
if ( NULL == F_149 ( V_418 , V_268 ) )
F_147 ( V_418 , & V_448 ,
V_268 ,
0 , 0x1f , 1 , V_30 ) ;
if ( NULL == F_149 ( V_418 , V_269 ) )
F_147 ( V_418 , & V_448 ,
V_269 ,
- 0x30 , 0x30 , 1 , V_32 ) ;
if ( NULL == F_149 ( V_418 , V_270 ) )
F_147 ( V_418 , & V_448 ,
V_270 ,
- 0x30 , 0x30 , 1 , V_34 ) ;
if ( NULL == F_149 ( V_418 , V_271 ) )
F_147 ( V_418 , & V_448 ,
V_271 ,
0 , 0x0f , 1 , V_36 ) ;
F_7 ( V_2 ) ;
F_152 ( V_418 ) ;
V_44 = V_418 -> error ;
if ( V_44 )
goto V_444;
F_133 ( V_2 , & V_4 -> V_215 , & V_454 , L_67 ) ;
F_153 ( & V_4 -> V_455 ) ;
F_153 ( & V_4 -> V_456 ) ;
V_4 -> V_215 . V_457 = & V_4 -> V_226 ;
V_4 -> V_215 . V_457 -> V_385 = & V_4 -> V_455 ;
if ( V_2 -> V_5 . V_6 ) {
F_154 ( & V_4 -> V_215 , V_458 ) ;
F_154 ( & V_4 -> V_215 , V_459 ) ;
F_154 ( & V_4 -> V_215 , V_460 ) ;
} else {
F_154 ( & V_4 -> V_215 , V_461 ) ;
}
if ( V_2 -> V_350 == V_351 ) {
F_154 ( & V_4 -> V_215 , V_462 ) ;
F_154 ( & V_4 -> V_215 , V_463 ) ;
F_154 ( & V_4 -> V_215 , V_464 ) ;
F_154 ( & V_4 -> V_215 , V_465 ) ;
}
if ( V_2 -> V_347 == V_348 ) {
F_154 ( & V_4 -> V_215 , V_466 ) ;
F_154 ( & V_4 -> V_215 , V_467 ) ;
}
V_44 = F_155 ( & V_4 -> V_215 , V_340 ,
V_468 [ V_2 -> V_469 ] ) ;
if ( V_44 ) {
F_18 ( L_68 ,
V_44 ) ;
goto V_444;
}
if ( F_3 ( V_2 ) == 1 ) {
F_133 ( V_2 , & V_4 -> V_354 , & V_454 ,
L_69 ) ;
V_4 -> V_354 . V_457 = & V_4 -> V_240 ;
V_4 -> V_354 . V_457 -> V_385 = & V_4 -> V_456 ;
F_154 ( & V_4 -> V_354 , V_461 ) ;
if ( V_2 -> V_350 == V_351 ) {
F_154 ( & V_4 -> V_354 , V_462 ) ;
F_154 ( & V_4 -> V_354 , V_463 ) ;
F_154 ( & V_4 -> V_354 , V_464 ) ;
F_154 ( & V_4 -> V_354 , V_465 ) ;
}
if ( V_2 -> V_347 == V_348 ) {
F_154 ( & V_4 -> V_354 , V_466 ) ;
F_154 ( & V_4 -> V_354 , V_467 ) ;
}
V_44 = F_155 ( & V_4 -> V_354 , V_382 ,
V_470 [ V_2 -> V_469 ] ) ;
if ( V_44 < 0 ) {
F_18 ( L_70 ) ;
goto V_444;
}
}
if ( V_337 [ V_2 -> V_338 ] . V_405 . type == V_471 ) {
F_133 ( V_2 , & V_4 -> V_355 , & V_472 ,
L_71 ) ;
V_44 = F_155 ( & V_4 -> V_355 , V_217 ,
V_473 [ V_2 -> V_469 ] ) ;
if ( V_44 < 0 ) {
F_18 ( L_72 ) ;
goto V_444;
}
F_120 ( L_73 ,
F_113 ( & V_4 -> V_355 ) ) ;
}
F_120 ( L_74 ,
F_113 ( & V_4 -> V_215 ) ) ;
if ( F_103 ( & V_4 -> V_354 ) )
F_120 ( L_75 ,
F_113 ( & V_4 -> V_354 ) ) ;
F_5 ( & V_4 -> V_17 , 0 , V_18 , V_392 , 0 ) ;
F_56 ( V_2 ) ;
F_120 ( L_76 ) ;
F_118 ( & V_2 -> V_379 ) ;
F_116 ( & V_2 -> V_385 ) ;
return 0 ;
V_444:
F_124 ( & V_4 -> V_265 ) ;
F_125 ( & V_4 -> V_17 ) ;
V_421:
V_2 -> V_4 = NULL ;
F_127 ( & V_4 -> V_379 , F_110 ) ;
F_116 ( & V_2 -> V_385 ) ;
return V_44 ;
}
static int T_5 F_156 ( void )
{
return F_157 ( & V_474 ) ;
}
static void T_6 F_158 ( void )
{
F_159 ( & V_474 ) ;
}
