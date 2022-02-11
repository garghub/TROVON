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
V_87 -> V_109 . V_110 . V_111 = V_2 -> V_4 -> V_112 ++ ;
V_87 -> V_109 . V_110 . V_113 = V_114 ;
F_21 ( & V_87 -> V_109 . V_110 . V_115 ) ;
F_22 ( & V_87 -> V_109 , V_116 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_107 * V_87 ,
unsigned char * V_117 ,
unsigned long V_118 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void * V_119 , * V_120 , * V_121 ;
int V_122 , V_123 , V_124 , V_125 , V_126 ;
int V_127 = V_4 -> V_73 << 1 ;
if ( V_87 -> V_128 + V_118 > V_87 -> V_129 )
V_118 = V_87 -> V_129 - V_87 -> V_128 ;
V_121 = V_117 ;
V_126 = V_118 ;
if ( V_4 -> V_130 || V_87 -> V_108 )
V_119 = V_87 -> V_131 ;
else
V_119 = V_87 -> V_131 + V_127 ;
V_122 = V_87 -> V_128 / V_127 ;
V_123 = V_87 -> V_128 % V_127 ;
if ( V_4 -> V_130 )
V_124 = V_122 * V_127 + V_123 ;
else
V_124 = V_122 * V_127 * 2 + V_123 ;
V_120 = V_119 + V_124 ;
V_125 = V_127 - V_123 ;
V_125 = V_125 > V_126 ? V_126 : V_125 ;
if ( ( char * ) V_120 + V_125 > ( char * ) V_87 -> V_131 + V_87 -> V_129 ) {
F_20 ( L_8 ,
( ( char * ) V_120 + V_125 ) -
( ( char * ) V_87 -> V_131 + V_87 -> V_129 ) ) ;
V_126 = ( char * ) V_87 -> V_131 + V_87 -> V_129 -
( char * ) V_120 ;
V_125 = V_126 ;
}
if ( V_125 <= 0 )
return;
memcpy ( V_120 , V_121 , V_125 ) ;
V_126 -= V_125 ;
while ( V_126 > 0 ) {
if ( V_4 -> V_130 )
V_120 += V_125 ;
else
V_120 += V_125 + V_127 ;
V_121 += V_125 ;
if ( V_127 > V_126 )
V_125 = V_126 ;
else
V_125 = V_127 ;
if ( ( char * ) V_120 + V_125 > ( char * ) V_87 -> V_131 +
V_87 -> V_129 ) {
F_20 ( L_9
L_10 ,
( ( char * ) V_120 + V_125 ) -
( ( char * ) V_87 -> V_131 + V_87 -> V_129 ) ) ;
V_125 = V_126 = ( char * ) V_87 -> V_131 + V_87 -> V_129 -
( char * ) V_120 ;
}
if ( V_125 <= 0 )
break;
memcpy ( V_120 , V_121 , V_125 ) ;
V_126 -= V_125 ;
}
V_87 -> V_128 += V_118 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_107 * V_87 ,
unsigned char * V_117 ,
unsigned long V_118 )
{
unsigned int V_124 ;
if ( V_87 -> V_128 + V_118 > V_87 -> V_129 )
V_118 = V_87 -> V_129 - V_87 -> V_128 ;
V_124 = V_87 -> V_128 ;
if ( V_87 -> V_108 == 0 )
V_124 += V_2 -> V_4 -> V_57 * V_2 -> V_4 -> V_59 ;
memcpy ( V_87 -> V_131 + V_124 , V_117 , V_118 ) ;
V_87 -> V_128 += V_118 ;
}
static inline void F_25 ( struct V_1 * V_2 ,
int V_132 , int V_133 )
{
char * V_134 = L_11 ;
switch ( V_133 ) {
case - V_135 :
V_134 = L_12 ;
break;
case - V_136 :
V_134 = L_13 ;
break;
case - V_137 :
V_134 = L_14 ;
break;
case - V_138 :
V_134 = L_15 ;
break;
case - V_139 :
V_134 = L_16 ;
break;
case - V_140 :
V_134 = L_17 ;
break;
case - V_141 :
V_134 = L_18 ;
break;
case - V_142 :
V_134 = L_19 ;
break;
}
if ( V_132 < 0 ) {
F_20 ( L_20 , V_133 , V_134 ) ;
} else {
F_20 ( L_21 ,
V_132 , V_133 , V_134 ) ;
}
}
static inline struct V_107 * F_26 ( struct V_1 * V_2 ,
struct V_143 * V_144 )
{
struct V_107 * V_87 ;
if ( F_27 ( & V_144 -> V_145 ) ) {
F_20 ( L_22 ) ;
return NULL ;
}
V_87 = F_28 ( V_144 -> V_145 . V_146 , struct V_107 , V_147 ) ;
F_29 ( & V_87 -> V_147 ) ;
V_87 -> V_128 = 0 ;
V_87 -> V_131 = V_87 -> V_148 ;
return V_87 ;
}
static struct V_107 *
F_30 ( struct V_1 * V_2 ,
struct V_107 * V_87 ,
struct V_143 * V_144 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_130 || V_4 -> V_108 ) {
if ( V_87 != NULL )
F_19 ( V_2 , V_87 ) ;
V_87 = F_26 ( V_2 , V_144 ) ;
}
if ( V_87 != NULL ) {
V_87 -> V_108 = V_4 -> V_108 ;
V_87 -> V_128 = 0 ;
}
return V_87 ;
}
static inline void F_31 ( struct V_1 * V_2 ,
unsigned char * V_149 ,
unsigned int V_150 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_107 * V_87 = V_2 -> V_151 . V_152 ;
struct V_107 * V_153 = V_2 -> V_151 . V_153 ;
struct V_143 * V_144 = & V_2 -> V_154 ;
struct V_143 * V_155 = & V_2 -> V_156 ;
if ( V_150 >= 4 ) {
if ( V_149 [ 0 ] == 0x88 && V_149 [ 1 ] == 0x88 &&
V_149 [ 2 ] == 0x88 && V_149 [ 3 ] == 0x88 ) {
V_149 += 4 ;
V_150 -= 4 ;
} else if ( V_149 [ 0 ] == 0x33 && V_149 [ 1 ] == 0x95 ) {
V_4 -> V_157 = 0 ;
V_4 -> V_158 = 0 ;
F_20 ( L_23 ) ;
V_4 -> V_108 = ! ( V_149 [ 2 ] & 1 ) ;
V_149 += 4 ;
V_150 -= 4 ;
} else if ( V_149 [ 0 ] == 0x22 && V_149 [ 1 ] == 0x5a ) {
V_4 -> V_157 = 2 ;
F_20 ( L_24 ) ;
V_4 -> V_108 = ! ( V_149 [ 2 ] & 1 ) ;
V_149 += 4 ;
V_150 -= 4 ;
}
}
if ( V_4 -> V_157 == 0 ) {
V_153 = F_30 ( V_2 , V_153 , V_155 ) ;
V_2 -> V_151 . V_153 = V_153 ;
V_4 -> V_157 = 1 ;
}
if ( V_4 -> V_157 == 1 ) {
int V_159 = V_4 -> V_57 * V_4 -> V_59 ;
int V_160 = ( ( V_4 -> V_158 + V_150 ) > V_159 ) ?
( V_159 - V_4 -> V_158 ) : V_150 ;
if ( V_153 != NULL )
F_24 ( V_2 , V_153 , V_149 , V_160 ) ;
V_4 -> V_158 += V_160 ;
if ( V_160 < V_150 ) {
V_4 -> V_157 = 2 ;
V_149 += V_160 ;
V_150 -= V_160 ;
}
}
if ( V_4 -> V_157 == 2 ) {
V_87 = F_30 ( V_2 , V_87 , V_144 ) ;
V_2 -> V_151 . V_152 = V_87 ;
V_4 -> V_157 = 3 ;
}
if ( V_4 -> V_157 == 3 && V_87 != NULL && V_150 > 0 )
F_23 ( V_2 , V_87 , V_149 , V_150 ) ;
}
static inline void F_32 ( struct V_1 * V_2 ,
unsigned char * V_149 ,
unsigned int V_150 )
{
struct V_107 * V_87 = V_2 -> V_151 . V_152 ;
struct V_143 * V_161 = & V_2 -> V_154 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_162 = 0 ;
if ( V_150 >= 2 ) {
if ( ( V_149 [ 0 ] == V_163 ) &&
( ( V_149 [ 1 ] & ~ V_164 ) == 0x00 ) ) {
V_4 -> V_108 = ! ( V_149 [ 1 ] &
V_165 ) ;
V_162 = V_149 [ 1 ] &
V_166 ;
V_149 += 2 ;
V_150 -= 2 ;
}
if ( V_2 -> V_99 && V_162 ) {
V_87 = F_30 ( V_2 , V_87 , V_161 ) ;
V_2 -> V_151 . V_152 = V_87 ;
}
}
if ( V_87 != NULL && V_150 > 0 )
F_23 ( V_2 , V_87 , V_149 , V_150 ) ;
if ( ! V_2 -> V_99 && V_162 ) {
V_87 = F_30 ( V_2 , V_87 , V_161 ) ;
V_2 -> V_151 . V_152 = V_87 ;
}
}
static inline int F_33 ( struct V_1 * V_2 , struct V_167 * V_167 )
{
int V_168 , V_169 , V_94 ;
unsigned char * V_170 ;
unsigned int V_171 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_172 )
return 0 ;
if ( V_167 -> V_133 < 0 )
F_25 ( V_2 , - 1 , V_167 -> V_133 ) ;
V_168 = F_34 ( V_167 -> V_173 ) ;
if ( V_168 )
V_169 = 1 ;
else
V_169 = V_167 -> V_174 ;
for ( V_94 = 0 ; V_94 < V_169 ; V_94 ++ ) {
if ( V_168 ) {
V_171 = V_167 -> V_175 ;
V_170 = V_167 -> V_176 ;
} else {
if ( V_167 -> V_177 [ V_94 ] . V_133 < 0 ) {
F_25 ( V_2 , V_94 ,
V_167 -> V_177 [ V_94 ] . V_133 ) ;
if ( V_167 -> V_177 [ V_94 ] . V_133 != - V_140 )
continue;
}
V_171 = V_167 -> V_177 [ V_94 ] . V_175 ;
if ( V_171 > V_2 -> V_101 ) {
F_20 ( L_25 ) ;
continue;
}
V_170 = V_167 -> V_176 +
V_167 -> V_177 [ V_94 ] . V_124 ;
}
if ( V_171 == 0 ) {
continue;
}
if ( V_2 -> V_49 )
F_32 ( V_2 ,
V_170 , V_171 ) ;
else
F_31 ( V_2 ,
V_170 , V_171 ) ;
}
return 1 ;
}
static int F_35 ( enum V_178 V_179 )
{
switch ( V_179 ) {
case V_180 :
return V_181 ;
case V_182 :
return V_183 ;
default:
F_36 () ;
return 0 ;
}
}
static int F_37 ( struct V_1 * V_2 , enum V_178 V_179 )
{
int V_184 = F_35 ( V_179 ) ;
if ( V_2 -> V_185 & V_184 ) {
return - V_186 ;
}
V_2 -> V_185 |= V_184 ;
F_11 ( L_26 , V_184 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , enum V_178 V_179 )
{
int V_184 = F_35 ( V_179 ) ;
V_2 -> V_185 &= ~ V_184 ;
F_11 ( L_27 , V_184 ) ;
}
static int F_39 ( struct V_187 * V_188 , const struct V_189 * V_45 ,
unsigned int * V_190 , unsigned int * V_191 ,
unsigned int V_192 [] , void * V_193 [] )
{
struct V_1 * V_2 = F_40 ( V_188 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_194 ;
if ( V_45 )
V_194 = V_45 -> V_45 . V_195 . V_196 ;
else
V_194 =
( V_4 -> V_73 * V_4 -> V_74 * V_4 -> V_47 -> V_197 + 7 ) >> 3 ;
if ( V_194 == 0 )
return - V_198 ;
if ( 0 == * V_190 )
* V_190 = 32 ;
* V_191 = 1 ;
V_192 [ 0 ] = V_194 ;
return 0 ;
}
static int
F_41 ( struct V_199 * V_109 )
{
struct V_1 * V_2 = F_40 ( V_109 -> V_187 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_107 * V_87 = F_42 ( V_109 , struct V_107 , V_109 ) ;
unsigned long V_194 ;
F_11 ( L_28 , V_200 , V_109 -> V_110 . V_113 ) ;
V_194 = ( V_4 -> V_73 * V_4 -> V_74 * V_4 -> V_47 -> V_197 + 7 ) >> 3 ;
if ( F_43 ( V_109 , 0 ) < V_194 ) {
F_11 ( L_29 ,
V_200 , F_43 ( V_109 , 0 ) , V_194 ) ;
return - V_198 ;
}
F_44 ( & V_87 -> V_109 , 0 , V_194 ) ;
return 0 ;
}
int F_45 ( struct V_187 * V_188 , unsigned int V_201 )
{
struct V_1 * V_2 = F_40 ( V_188 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_202 V_203 ;
int V_204 = 0 ;
F_11 ( L_30 , V_200 ) ;
V_204 = F_37 ( V_2 , V_188 -> type ) ;
if ( V_204 )
return V_204 ;
if ( V_4 -> V_205 == 0 ) {
F_16 ( V_2 ) ;
F_4 ( V_2 ) ;
V_4 -> V_157 = - 1 ;
V_204 = F_46 ( V_2 , V_206 ,
V_2 -> V_99 ,
V_207 ,
V_2 -> V_101 ,
V_2 -> V_102 ,
F_33 ) ;
if ( V_204 < 0 )
return V_204 ;
memset ( & V_203 , 0 , sizeof( V_203 ) ) ;
V_203 . V_208 = V_4 -> V_208 ;
if ( V_188 -> V_209 && V_188 -> V_209 -> V_210 -> V_211 == V_212 )
V_203 . type = V_213 ;
else
V_203 . type = V_214 ;
F_5 ( & V_4 -> V_17 ,
0 , V_215 , V_216 , & V_203 ) ;
}
V_4 -> V_205 ++ ;
return V_204 ;
}
static void F_47 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_40 ( V_188 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_143 * V_154 = & V_2 -> V_154 ;
unsigned long V_217 = 0 ;
F_11 ( L_30 , V_200 ) ;
F_38 ( V_2 , V_188 -> type ) ;
if ( V_4 -> V_205 -- == 1 ) {
F_48 ( V_2 , V_206 ) ;
}
F_49 ( & V_2 -> V_218 , V_217 ) ;
while ( ! F_27 ( & V_154 -> V_145 ) ) {
struct V_107 * V_87 ;
V_87 = F_28 ( V_154 -> V_145 . V_146 , struct V_107 , V_147 ) ;
F_29 ( & V_87 -> V_147 ) ;
F_22 ( & V_87 -> V_109 , V_219 ) ;
}
V_2 -> V_151 . V_152 = NULL ;
F_50 ( & V_2 -> V_218 , V_217 ) ;
}
void F_51 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_40 ( V_188 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_143 * V_156 = & V_2 -> V_156 ;
unsigned long V_217 = 0 ;
F_11 ( L_30 , V_200 ) ;
F_38 ( V_2 , V_188 -> type ) ;
if ( V_4 -> V_205 -- == 1 ) {
F_48 ( V_2 , V_206 ) ;
}
F_49 ( & V_2 -> V_218 , V_217 ) ;
while ( ! F_27 ( & V_156 -> V_145 ) ) {
struct V_107 * V_87 ;
V_87 = F_28 ( V_156 -> V_145 . V_146 , struct V_107 , V_147 ) ;
F_29 ( & V_87 -> V_147 ) ;
F_22 ( & V_87 -> V_109 , V_219 ) ;
}
V_2 -> V_151 . V_153 = NULL ;
F_50 ( & V_2 -> V_218 , V_217 ) ;
}
static void
F_52 ( struct V_199 * V_109 )
{
struct V_1 * V_2 = F_40 ( V_109 -> V_187 ) ;
struct V_107 * V_87 = F_42 ( V_109 , struct V_107 , V_109 ) ;
struct V_143 * V_154 = & V_2 -> V_154 ;
unsigned long V_217 = 0 ;
F_11 ( L_30 , V_200 ) ;
V_87 -> V_148 = F_53 ( V_109 , 0 ) ;
V_87 -> V_129 = F_43 ( V_109 , 0 ) ;
F_49 ( & V_2 -> V_218 , V_217 ) ;
F_54 ( & V_87 -> V_147 , & V_154 -> V_145 ) ;
F_50 ( & V_2 -> V_218 , V_217 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_204 ;
struct V_187 * V_220 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_220 = & V_4 -> V_221 ;
V_220 -> type = V_180 ;
V_220 -> V_222 = V_223 | V_224 | V_225 | V_226 ;
V_220 -> V_227 = V_228 ;
V_220 -> V_229 = V_2 ;
V_220 -> V_230 = sizeof( struct V_107 ) ;
V_220 -> V_231 = & V_232 ;
V_220 -> V_233 = & V_234 ;
V_204 = F_56 ( V_220 ) ;
if ( V_204 < 0 )
return V_204 ;
V_220 = & V_4 -> V_235 ;
V_220 -> type = V_182 ;
V_220 -> V_222 = V_223 | V_224 | V_225 ;
V_220 -> V_227 = V_228 ;
V_220 -> V_229 = V_2 ;
V_220 -> V_230 = sizeof( struct V_107 ) ;
V_220 -> V_231 = & V_236 ;
V_220 -> V_233 = & V_234 ;
V_204 = F_56 ( V_220 ) ;
if ( V_204 < 0 )
return V_204 ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , int V_237 )
{
struct V_16 * V_17 = & V_2 -> V_4 -> V_17 ;
V_2 -> V_22 = V_237 ;
V_2 -> V_238 = F_6 ( V_237 ) -> V_239 ;
V_2 -> V_240 = F_6 ( V_237 ) -> V_241 ;
if ( ! V_2 -> V_240 )
V_2 -> V_240 = V_242 ;
F_5 ( V_17 , 0 , V_20 , V_21 ,
F_6 ( V_237 ) -> V_23 , 0 , 0 ) ;
if ( V_2 -> V_5 . V_243 ) {
if ( V_2 -> V_244 ) {
F_5 ( V_17 , 0 , V_245 ,
V_246 , V_2 -> V_244 ) ;
}
F_5 ( V_17 , 0 , V_245 , V_21 ,
V_2 -> V_238 , F_58 ( V_247 ) , 0 ) ;
}
if ( V_2 -> V_5 . V_248 != V_249 ) {
F_5 ( V_17 , 0 , V_245 , V_21 ,
V_2 -> V_238 , V_2 -> V_240 , 0 ) ;
}
F_59 ( V_2 ) ;
}
static void F_60 ( struct V_250 * V_251 , void * V_252 )
{
struct V_1 * V_2 = V_252 ;
switch ( V_251 -> V_253 ) {
case V_254 :
V_2 -> V_255 = V_251 -> V_256 ;
F_59 ( V_2 ) ;
break;
case V_257 :
V_2 -> V_258 = V_251 -> V_256 ;
F_59 ( V_2 ) ;
break;
}
}
static int F_61 ( struct V_250 * V_251 )
{
struct V_3 * V_4 =
F_42 ( V_251 -> V_259 , struct V_3 , V_260 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_44 = - V_198 ;
switch ( V_251 -> V_253 ) {
case V_254 :
V_2 -> V_255 = V_251 -> V_256 ;
V_44 = F_59 ( V_2 ) ;
break;
case V_257 :
V_2 -> V_258 = V_251 -> V_256 ;
V_44 = F_59 ( V_2 ) ;
break;
case V_261 :
V_44 = F_8 ( V_2 , V_25 , V_251 -> V_256 ) ;
break;
case V_262 :
V_44 = F_8 ( V_2 , V_27 , V_251 -> V_256 ) ;
break;
case V_263 :
V_44 = F_8 ( V_2 , V_29 , V_251 -> V_256 ) ;
break;
case V_264 :
V_44 = F_8 ( V_2 , V_31 , V_251 -> V_256 ) ;
break;
case V_265 :
V_44 = F_8 ( V_2 , V_33 , V_251 -> V_256 ) ;
break;
case V_266 :
V_44 = F_8 ( V_2 , V_35 , V_251 -> V_256 ) ;
break;
}
return ( V_44 < 0 ) ? V_44 : 0 ;
}
static void F_62 ( struct V_1 * V_2 ,
unsigned int V_73 , unsigned int V_74 ,
unsigned int * V_91 , unsigned int * V_92 )
{
unsigned int V_267 = F_1 ( V_2 ) ;
unsigned int V_268 = F_2 ( V_2 ) ;
* V_91 = ( ( ( unsigned long ) V_267 ) << 12 ) / V_73 - 4096L ;
if ( * V_91 > V_269 )
* V_91 = V_269 ;
* V_92 = ( ( ( unsigned long ) V_268 ) << 12 ) / V_74 - 4096L ;
if ( * V_92 > V_269 )
* V_92 = V_269 ;
}
static void F_63 ( struct V_1 * V_2 ,
unsigned int V_91 , unsigned int V_92 ,
unsigned int * V_73 , unsigned int * V_74 )
{
unsigned int V_267 = F_1 ( V_2 ) ;
unsigned int V_268 = F_2 ( V_2 ) ;
* V_73 = ( ( ( unsigned long ) V_267 ) << 12 ) / ( V_91 + 4096L ) ;
* V_74 = ( ( ( unsigned long ) V_268 ) << 12 ) / ( V_92 + 4096L ) ;
}
static int F_64 ( struct V_270 * V_270 , void * V_252 ,
struct V_189 * V_203 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_203 -> V_45 . V_195 . V_73 = V_4 -> V_73 ;
V_203 -> V_45 . V_195 . V_74 = V_4 -> V_74 ;
V_203 -> V_45 . V_195 . V_273 = V_4 -> V_47 -> V_274 ;
V_203 -> V_45 . V_195 . V_127 = ( V_4 -> V_73 * V_4 -> V_47 -> V_197 + 7 ) >> 3 ;
V_203 -> V_45 . V_195 . V_196 = V_203 -> V_45 . V_195 . V_127 * V_4 -> V_74 ;
V_203 -> V_45 . V_195 . V_275 = V_276 ;
if ( V_4 -> V_130 )
V_203 -> V_45 . V_195 . V_113 = V_277 ;
else
V_203 -> V_45 . V_195 . V_113 = V_4 -> V_278 ?
V_114 : V_279 ;
return 0 ;
}
static struct V_280 * F_65 ( unsigned int V_274 )
{
unsigned int V_94 ;
for ( V_94 = 0 ; V_94 < F_66 ( V_47 ) ; V_94 ++ )
if ( V_47 [ V_94 ] . V_274 == V_274 )
return & V_47 [ V_94 ] ;
return NULL ;
}
static int F_67 ( struct V_270 * V_270 , void * V_252 ,
struct V_189 * V_203 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_73 = V_203 -> V_45 . V_195 . V_73 ;
unsigned int V_74 = V_203 -> V_45 . V_195 . V_74 ;
unsigned int V_267 = F_1 ( V_2 ) ;
unsigned int V_268 = F_2 ( V_2 ) ;
unsigned int V_91 , V_92 ;
struct V_280 * V_45 ;
V_45 = F_65 ( V_203 -> V_45 . V_195 . V_273 ) ;
if ( ! V_45 ) {
F_11 ( L_31 ,
V_203 -> V_45 . V_195 . V_273 ) ;
return - V_198 ;
}
if ( V_2 -> V_5 . V_86 ) {
V_74 = V_74 > ( 3 * V_268 / 4 ) ? V_268 : V_268 / 2 ;
V_73 = V_73 > ( 3 * V_267 / 4 ) ? V_267 : V_267 / 2 ;
if ( V_73 == V_267 && V_74 == V_268 )
V_73 /= 2 ;
} else {
F_68 ( & V_73 , 48 , V_267 , 1 , & V_74 , 32 , V_268 ,
1 , 0 ) ;
}
F_62 ( V_2 , V_73 , V_74 , & V_91 , & V_92 ) ;
F_63 ( V_2 , V_91 , V_92 , & V_73 , & V_74 ) ;
V_203 -> V_45 . V_195 . V_73 = V_73 ;
V_203 -> V_45 . V_195 . V_74 = V_74 ;
V_203 -> V_45 . V_195 . V_273 = V_45 -> V_274 ;
V_203 -> V_45 . V_195 . V_127 = ( V_73 * V_45 -> V_197 + 7 ) >> 3 ;
V_203 -> V_45 . V_195 . V_196 = V_203 -> V_45 . V_195 . V_127 * V_74 ;
V_203 -> V_45 . V_195 . V_275 = V_276 ;
if ( V_4 -> V_130 )
V_203 -> V_45 . V_195 . V_113 = V_277 ;
else
V_203 -> V_45 . V_195 . V_113 = V_4 -> V_278 ?
V_114 : V_279 ;
V_203 -> V_45 . V_195 . V_252 = 0 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , unsigned int V_274 ,
unsigned V_73 , unsigned V_74 )
{
struct V_280 * V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_45 = F_65 ( V_274 ) ;
if ( ! V_45 )
return - V_198 ;
V_4 -> V_47 = V_45 ;
V_4 -> V_73 = V_73 ;
V_4 -> V_74 = V_74 ;
F_62 ( V_2 , V_4 -> V_73 , V_4 -> V_74 ,
& V_4 -> V_91 , & V_4 -> V_92 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_270 * V_270 , void * V_252 ,
struct V_189 * V_203 )
{
struct V_1 * V_2 = F_71 ( V_270 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_205 > 0 )
return - V_186 ;
F_67 ( V_270 , V_252 , V_203 ) ;
return F_69 ( V_2 , V_203 -> V_45 . V_195 . V_273 ,
V_203 -> V_45 . V_195 . V_73 , V_203 -> V_45 . V_195 . V_74 ) ;
}
static int F_72 ( struct V_270 * V_270 , void * V_252 , T_3 * V_10 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
* V_10 = V_2 -> V_4 -> V_10 ;
return 0 ;
}
static int F_73 ( struct V_270 * V_270 , void * V_252 , T_3 * V_10 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_20 , V_281 , V_10 ) ;
return 0 ;
}
static int F_74 ( struct V_270 * V_270 , void * V_252 , T_3 V_10 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_189 V_203 ;
if ( V_10 == V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_205 > 0 )
return - V_186 ;
V_4 -> V_10 = V_10 ;
V_203 . V_45 . V_195 . V_73 = 720 ;
V_203 . V_45 . V_195 . V_74 = ( V_10 & V_60 ) ? 480 : 576 ;
F_67 ( V_270 , V_252 , & V_203 ) ;
V_4 -> V_73 = V_203 . V_45 . V_195 . V_73 ;
V_4 -> V_74 = V_203 . V_45 . V_195 . V_74 ;
F_62 ( V_2 , V_4 -> V_73 , V_4 -> V_74 ,
& V_4 -> V_91 , & V_4 -> V_92 ) ;
F_15 ( V_2 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_282 , V_4 -> V_10 ) ;
return 0 ;
}
static int F_75 ( struct V_270 * V_270 , void * V_252 ,
struct V_283 * V_284 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_204 = 0 ;
V_284 -> V_285 . V_286 . V_287 = V_288 ;
if ( V_2 -> V_5 . V_6 )
V_204 = F_76 ( & V_4 -> V_17 , 0 ,
V_20 , V_289 , V_284 ) ;
else
F_77 ( V_4 -> V_10 ,
& V_284 -> V_285 . V_286 . V_290 ) ;
return V_204 ;
}
static int F_78 ( struct V_270 * V_270 , void * V_252 ,
struct V_283 * V_284 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
V_284 -> V_285 . V_286 . V_287 = V_288 ;
return F_76 ( & V_2 -> V_4 -> V_17 ,
0 , V_20 , V_291 , V_284 ) ;
}
static int F_79 ( struct V_270 * V_270 , void * V_252 ,
struct V_292 * V_94 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
unsigned int V_293 ;
V_293 = V_94 -> V_237 ;
if ( V_293 >= V_294 )
return - V_198 ;
if ( 0 == F_6 ( V_293 ) -> type )
return - V_198 ;
V_94 -> V_237 = V_293 ;
V_94 -> type = V_295 ;
strcpy ( V_94 -> V_296 , V_297 [ F_6 ( V_293 ) -> type ] ) ;
if ( ( V_298 == F_6 ( V_293 ) -> type ) ||
( V_299 == F_6 ( V_293 ) -> type ) )
V_94 -> type = V_300 ;
V_94 -> V_301 = V_2 -> V_4 -> V_210 -> V_302 ;
if ( V_2 -> V_5 . V_6 )
V_94 -> V_303 = 0 ;
return 0 ;
}
static int F_80 ( struct V_270 * V_270 , void * V_252 , unsigned int * V_94 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
* V_94 = V_2 -> V_22 ;
return 0 ;
}
static int F_81 ( struct V_270 * V_270 , void * V_252 , unsigned int V_94 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
if ( V_94 >= V_294 )
return - V_198 ;
if ( 0 == F_6 ( V_94 ) -> type )
return - V_198 ;
F_57 ( V_2 , V_94 ) ;
return 0 ;
}
static int F_82 ( struct V_270 * V_270 , void * V_252 , struct V_304 * V_305 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
switch ( V_305 -> V_237 ) {
case V_306 :
strcpy ( V_305 -> V_296 , L_32 ) ;
break;
case V_307 :
strcpy ( V_305 -> V_296 , L_33 ) ;
break;
case V_308 :
strcpy ( V_305 -> V_296 , L_34 ) ;
break;
case V_309 :
strcpy ( V_305 -> V_296 , L_35 ) ;
break;
case V_310 :
strcpy ( V_305 -> V_296 , L_36 ) ;
break;
case V_311 :
strcpy ( V_305 -> V_296 , L_37 ) ;
break;
case V_312 :
strcpy ( V_305 -> V_296 , L_38 ) ;
break;
case V_313 :
strcpy ( V_305 -> V_296 , L_39 ) ;
break;
default:
return - V_198 ;
}
V_305 -> V_237 = V_2 -> V_238 ;
V_305 -> V_314 = V_315 ;
return 0 ;
}
static int F_83 ( struct V_270 * V_270 , void * V_252 , const struct V_304 * V_305 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
if ( V_305 -> V_237 >= V_294 )
return - V_198 ;
if ( 0 == F_6 ( V_305 -> V_237 ) -> type )
return - V_198 ;
V_2 -> V_238 = F_6 ( V_305 -> V_237 ) -> V_239 ;
V_2 -> V_240 = F_6 ( V_305 -> V_237 ) -> V_241 ;
if ( ! V_2 -> V_240 )
V_2 -> V_240 = V_242 ;
return 0 ;
}
static int F_84 ( struct V_270 * V_270 , void * V_252 ,
struct V_316 * V_317 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
if ( 0 != V_317 -> V_237 )
return - V_198 ;
strcpy ( V_317 -> V_296 , L_40 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_215 , V_318 , V_317 ) ;
return 0 ;
}
static int F_85 ( struct V_270 * V_270 , void * V_252 ,
const struct V_316 * V_317 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
if ( 0 != V_317 -> V_237 )
return - V_198 ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_215 , V_319 , V_317 ) ;
return 0 ;
}
static int F_86 ( struct V_270 * V_270 , void * V_252 ,
struct V_202 * V_203 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_203 -> V_215 )
return - V_198 ;
V_203 -> V_208 = V_4 -> V_208 ;
return 0 ;
}
static int F_87 ( struct V_270 * V_270 , void * V_252 ,
const struct V_202 * V_203 )
{
struct V_202 V_320 = * V_203 ;
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_203 -> V_215 )
return - V_198 ;
F_5 ( & V_4 -> V_17 , 0 , V_215 , V_216 , V_203 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_215 , V_321 , & V_320 ) ;
V_4 -> V_208 = V_320 . V_208 ;
return 0 ;
}
static int F_88 ( struct V_270 * V_270 , void * V_252 ,
struct V_322 * V_323 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
if ( V_323 -> V_324 . V_325 > 1 )
return - V_198 ;
if ( V_323 -> V_324 . V_325 == 1 )
F_89 ( V_323 -> V_296 , L_41 , sizeof( V_323 -> V_296 ) ) ;
else
F_89 ( V_323 -> V_296 ,
V_2 -> V_4 -> V_17 . V_296 , sizeof( V_323 -> V_296 ) ) ;
return 0 ;
}
static int F_90 ( int V_48 )
{
switch ( V_48 ) {
case V_326 :
case V_88 :
case V_89 :
return 2 ;
default:
return 1 ;
}
}
static int F_91 ( struct V_270 * V_270 , void * V_252 ,
struct V_327 * V_48 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
int V_44 ;
if ( V_48 -> V_324 . V_325 > 1 )
return - V_198 ;
if ( V_48 -> V_324 . V_325 ) {
V_44 = F_92 ( V_2 , V_48 -> V_48 ) ;
if ( V_44 < 0 )
return V_44 ;
V_48 -> V_256 = V_44 ;
V_48 -> V_194 = 1 ;
return 0 ;
}
V_48 -> V_194 = F_90 ( V_48 -> V_48 ) ;
if ( V_48 -> V_194 == 1 ) {
V_44 = F_93 ( V_2 , V_48 -> V_48 ) ;
if ( V_44 < 0 )
return V_44 ;
V_48 -> V_256 = V_44 ;
} else {
T_4 V_256 = 0 ;
V_44 = V_2 -> V_328 ( V_2 , V_329 ,
V_48 -> V_48 , ( char * ) & V_256 , 2 ) ;
if ( V_44 < 0 )
return V_44 ;
V_48 -> V_256 = F_94 ( V_256 ) ;
}
return 0 ;
}
static int F_95 ( struct V_270 * V_270 , void * V_252 ,
const struct V_327 * V_48 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
T_4 V_87 ;
if ( V_48 -> V_324 . V_325 > 1 )
return - V_198 ;
if ( V_48 -> V_324 . V_325 )
return F_96 ( V_2 , V_48 -> V_48 , V_48 -> V_256 ) ;
V_87 = F_97 ( V_48 -> V_256 ) ;
return F_12 ( V_2 , V_48 -> V_48 , ( char * ) & V_87 ,
F_90 ( V_48 -> V_48 ) ) ;
}
static int F_98 ( struct V_270 * V_270 , void * V_252 ,
struct V_330 * V_331 )
{
struct V_332 * V_210 = F_99 ( V_270 ) ;
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_89 ( V_331 -> V_333 , L_42 , sizeof( V_331 -> V_333 ) ) ;
F_89 ( V_331 -> V_334 , V_335 [ V_2 -> V_336 ] . V_296 , sizeof( V_331 -> V_334 ) ) ;
F_100 ( V_2 -> V_105 , V_331 -> V_337 , sizeof( V_331 -> V_337 ) ) ;
if ( V_210 -> V_211 == V_338 )
V_331 -> V_339 = V_340 |
V_341 | V_342 ;
else if ( V_210 -> V_211 == V_212 )
V_331 -> V_339 = V_343 ;
else
V_331 -> V_339 = V_340 | V_344 ;
if ( V_2 -> V_345 . V_346 )
V_331 -> V_339 |= V_347 ;
if ( V_2 -> V_348 != V_349 )
V_331 -> V_339 |= V_350 ;
V_331 -> V_303 = V_331 -> V_339 | V_351 |
V_340 | V_341 | V_342 ;
if ( V_4 -> V_352 )
V_331 -> V_303 |= V_344 ;
if ( V_4 -> V_353 )
V_331 -> V_303 |= V_343 ;
return 0 ;
}
static int F_101 ( struct V_270 * V_270 , void * V_252 ,
struct V_354 * V_203 )
{
if ( F_102 ( V_203 -> V_237 >= F_66 ( V_47 ) ) )
return - V_198 ;
F_89 ( V_203 -> V_355 , V_47 [ V_203 -> V_237 ] . V_296 , sizeof( V_203 -> V_355 ) ) ;
V_203 -> V_273 = V_47 [ V_203 -> V_237 ] . V_274 ;
return 0 ;
}
static int F_103 ( struct V_270 * V_270 , void * V_252 ,
struct V_356 * V_357 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_280 * V_45 ;
unsigned int V_267 = F_1 ( V_2 ) ;
unsigned int V_268 = F_2 ( V_2 ) ;
V_45 = F_65 ( V_357 -> V_358 ) ;
if ( ! V_45 ) {
F_11 ( L_31 ,
V_357 -> V_358 ) ;
return - V_198 ;
}
if ( V_2 -> V_5 . V_86 ) {
if ( V_357 -> V_237 > 1 )
return - V_198 ;
V_357 -> type = V_359 ;
V_357 -> V_360 . V_73 = V_267 / ( 1 + V_357 -> V_237 ) ;
V_357 -> V_360 . V_74 = V_268 / ( 1 + V_357 -> V_237 ) ;
return 0 ;
}
if ( V_357 -> V_237 != 0 )
return - V_198 ;
V_357 -> type = V_361 ;
F_63 ( V_2 , V_269 , V_269 ,
& V_357 -> V_362 . V_363 , & V_357 -> V_362 . V_364 ) ;
if ( V_357 -> V_362 . V_363 < 48 )
V_357 -> V_362 . V_363 = 48 ;
if ( V_357 -> V_362 . V_364 < 38 )
V_357 -> V_362 . V_364 = 38 ;
V_357 -> V_362 . V_365 = V_267 ;
V_357 -> V_362 . V_366 = V_268 ;
V_357 -> V_362 . V_367 = 1 ;
V_357 -> V_362 . V_368 = 1 ;
return 0 ;
}
static int F_104 ( struct V_270 * V_270 , void * V_252 ,
struct V_189 * V_47 )
{
struct V_271 * V_272 = V_252 ;
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_47 -> V_45 . V_369 . V_370 = V_4 -> V_57 ;
V_47 -> V_45 . V_369 . V_371 = V_372 ;
V_47 -> V_45 . V_369 . V_124 = 0 ;
V_47 -> V_45 . V_369 . V_217 = 0 ;
V_47 -> V_45 . V_369 . V_373 = 6750000 * 4 / 2 ;
V_47 -> V_45 . V_369 . V_201 [ 0 ] = V_4 -> V_59 ;
V_47 -> V_45 . V_369 . V_201 [ 1 ] = V_4 -> V_59 ;
memset ( V_47 -> V_45 . V_369 . V_374 , 0 , sizeof( V_47 -> V_45 . V_369 . V_374 ) ) ;
if ( V_4 -> V_10 & V_60 ) {
V_47 -> V_45 . V_369 . V_375 [ 0 ] = 10 ;
V_47 -> V_45 . V_369 . V_375 [ 1 ] = 273 ;
} else if ( V_4 -> V_10 & V_11 ) {
V_47 -> V_45 . V_369 . V_375 [ 0 ] = 6 ;
V_47 -> V_45 . V_369 . V_375 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_105 ( struct V_270 * V_270 , void * V_252 ,
struct V_316 * V_317 )
{
struct V_1 * V_2 = ( (struct V_271 * ) V_252 ) -> V_2 ;
if ( F_102 ( V_317 -> V_237 > 0 ) )
return - V_198 ;
strcpy ( V_317 -> V_296 , L_43 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_215 , V_318 , V_317 ) ;
return 0 ;
}
static int F_106 ( struct V_270 * V_270 , void * V_252 ,
const struct V_316 * V_317 )
{
struct V_1 * V_2 = ( (struct V_271 * ) V_252 ) -> V_2 ;
if ( 0 != V_317 -> V_237 )
return - V_198 ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_215 , V_319 , V_317 ) ;
return 0 ;
}
static void F_107 ( struct V_376 * V_377 )
{
struct V_3 * V_4 = F_42 ( V_377 , struct V_3 , V_377 ) ;
V_4 -> V_2 -> V_4 = NULL ;
F_108 ( V_4 ) ;
}
static int F_109 ( struct V_270 * V_378 )
{
struct V_332 * V_210 = F_99 ( V_378 ) ;
struct V_1 * V_2 = F_71 ( V_378 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
enum V_178 V_379 = 0 ;
struct V_271 * V_272 ;
switch ( V_210 -> V_211 ) {
case V_338 :
V_379 = V_180 ;
break;
case V_380 :
V_379 = V_182 ;
break;
case V_212 :
break;
default:
return - V_198 ;
}
F_11 ( L_44 ,
F_110 ( V_210 ) , V_381 [ V_379 ] ,
V_4 -> V_382 ) ;
if ( F_111 ( & V_2 -> V_383 ) )
return - V_384 ;
V_272 = F_112 ( sizeof( struct V_271 ) , V_385 ) ;
if ( ! V_272 ) {
F_18 ( L_45 ) ;
F_113 ( & V_2 -> V_383 ) ;
return - V_386 ;
}
F_114 ( & V_272 -> V_272 , V_210 ) ;
V_272 -> V_2 = V_2 ;
V_272 -> type = V_379 ;
V_378 -> V_387 = V_272 ;
if ( V_4 -> V_382 == 0 ) {
F_115 ( V_2 , V_206 ) ;
if ( V_210 -> V_211 != V_212 )
F_15 ( V_2 ) ;
F_4 ( V_2 ) ;
}
if ( V_210 -> V_211 == V_212 ) {
F_11 ( L_46 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_215 , V_388 ) ;
}
F_116 ( & V_2 -> V_377 ) ;
F_116 ( & V_4 -> V_377 ) ;
V_4 -> V_382 ++ ;
F_113 ( & V_2 -> V_383 ) ;
F_117 ( & V_272 -> V_272 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_389 ) {
return 0 ;
}
if ( ! V_2 -> V_390 ) {
return 0 ;
}
if ( V_4 == NULL )
return 0 ;
F_119 ( L_47 ) ;
F_120 ( & V_2 -> V_383 ) ;
F_121 ( & V_4 -> V_17 ) ;
F_48 ( V_2 , V_206 ) ;
if ( V_4 -> V_353 ) {
F_119 ( L_48 ,
F_110 ( V_4 -> V_353 ) ) ;
F_122 ( V_4 -> V_353 ) ;
}
if ( V_4 -> V_352 ) {
F_119 ( L_48 ,
F_110 ( V_4 -> V_352 ) ) ;
F_122 ( V_4 -> V_352 ) ;
}
if ( V_4 -> V_210 ) {
F_119 ( L_48 ,
F_110 ( V_4 -> V_210 ) ) ;
F_122 ( V_4 -> V_210 ) ;
}
F_123 ( & V_4 -> V_260 ) ;
F_124 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_391 ) {
F_125 ( V_4 -> V_391 ) ;
V_4 -> V_391 = NULL ;
}
F_126 ( & V_4 -> V_377 , F_107 ) ;
F_113 ( & V_2 -> V_383 ) ;
F_126 ( & V_2 -> V_377 , V_392 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
if ( V_2 -> V_389 )
return 0 ;
if ( ! V_2 -> V_390 )
return 0 ;
F_119 ( L_49 ) ;
F_128 ( V_2 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 )
{
if ( V_2 -> V_389 )
return 0 ;
if ( ! V_2 -> V_390 )
return 0 ;
F_119 ( L_50 ) ;
return 0 ;
}
static int F_130 ( struct V_270 * V_378 )
{
struct V_271 * V_272 = V_378 -> V_387 ;
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_93 ;
F_11 ( L_51 , V_4 -> V_382 ) ;
F_131 ( V_378 ) ;
F_120 ( & V_2 -> V_383 ) ;
if ( V_4 -> V_382 == 1 ) {
if ( V_2 -> V_172 )
goto exit;
F_5 ( & V_4 -> V_17 , 0 , V_18 , V_393 , 0 ) ;
F_115 ( V_2 , V_394 ) ;
V_2 -> V_96 = 0 ;
F_11 ( L_52 ) ;
V_93 = F_17 ( V_2 -> V_105 , 0 , 0 ) ;
if ( V_93 < 0 ) {
F_18 ( L_53
L_54 , V_93 ) ;
}
}
exit:
V_4 -> V_382 -- ;
F_126 ( & V_4 -> V_377 , F_107 ) ;
F_113 ( & V_2 -> V_383 ) ;
F_126 ( & V_2 -> V_377 , V_392 ) ;
return 0 ;
}
static struct V_332 * F_132 ( struct V_1 * V_2 ,
const struct V_332 * V_395 ,
const char * V_396 )
{
struct V_332 * V_397 ;
V_397 = F_133 () ;
if ( NULL == V_397 )
return NULL ;
* V_397 = * V_395 ;
V_397 -> V_17 = & V_2 -> V_4 -> V_17 ;
V_397 -> V_398 = V_399 ;
V_397 -> V_383 = & V_2 -> V_383 ;
F_134 ( V_400 , & V_397 -> V_217 ) ;
if ( V_2 -> V_5 . V_6 )
V_397 -> V_302 = 0 ;
snprintf ( V_397 -> V_296 , sizeof( V_397 -> V_296 ) , L_55 ,
V_2 -> V_296 , V_396 ) ;
F_135 ( V_397 , V_2 ) ;
return V_397 ;
}
static void F_136 ( struct V_1 * V_2 , unsigned short V_401 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_16 * V_17 = & V_4 -> V_17 ;
struct V_402 V_403 ;
struct V_202 V_203 ;
memset ( & V_403 , 0 , sizeof( V_403 ) ) ;
V_403 . V_404 = V_405 | V_406 ;
V_403 . V_407 = V_408 ;
if ( V_2 -> V_5 . V_409 . type ) {
V_403 . type = V_2 -> V_5 . V_409 . type ;
V_403 . V_325 = V_2 -> V_5 . V_410 ;
F_5 ( V_17 ,
0 , V_215 , V_411 , & V_403 ) ;
}
if ( ( V_2 -> V_348 != V_349 ) && ( V_2 -> V_348 ) ) {
V_403 . type = V_2 -> V_348 ;
V_403 . V_325 = V_401 ;
F_5 ( V_17 ,
0 , V_215 , V_411 , & V_403 ) ;
}
if ( V_2 -> V_5 . V_412 ) {
struct V_413 V_414 ;
V_414 . V_215 = V_415 ;
V_414 . V_252 = & V_2 -> V_5 . V_412 ;
F_5 ( V_17 ,
0 , V_215 , V_416 , & V_414 ) ;
}
if ( V_2 -> V_348 == V_417 ) {
struct V_413 V_418 ;
struct V_419 V_420 ;
memset ( & V_418 , 0 , sizeof( V_418 ) ) ;
memset ( & V_420 , 0 , sizeof( V_420 ) ) ;
F_137 ( V_2 , & V_420 ) ;
V_418 . V_215 = V_417 ;
V_418 . V_252 = & V_420 ;
F_5 ( V_17 , 0 , V_215 , V_416 , & V_418 ) ;
}
V_203 . V_215 = 0 ;
V_203 . type = V_214 ;
V_203 . V_208 = 9076 ;
V_4 -> V_208 = V_203 . V_208 ;
F_5 ( V_17 , 0 , V_215 , V_216 , & V_203 ) ;
}
static int F_138 ( struct V_1 * V_2 )
{
T_1 V_256 ;
int V_44 ;
unsigned int V_267 ;
struct V_421 * V_422 ;
struct V_3 * V_4 ;
if ( V_2 -> V_389 ) {
return 0 ;
}
if ( ! V_2 -> V_390 ) {
return 0 ;
}
F_119 ( L_56 ) ;
F_120 ( & V_2 -> V_383 ) ;
V_4 = F_112 ( sizeof( struct V_3 ) , V_385 ) ;
if ( V_4 == NULL ) {
F_119 ( L_57 ) ;
F_113 ( & V_2 -> V_383 ) ;
return - V_386 ;
}
F_139 ( & V_4 -> V_377 ) ;
V_4 -> V_2 = V_2 ;
V_2 -> V_4 = V_4 ;
V_44 = F_140 ( & V_2 -> V_105 -> V_2 , & V_4 -> V_17 ) ;
if ( V_44 < 0 ) {
F_18 ( L_58 ) ;
goto V_423;
}
V_422 = & V_4 -> V_260 ;
F_141 ( V_422 , 8 ) ;
V_4 -> V_17 . V_260 = V_422 ;
if ( V_2 -> V_5 . V_6 )
V_4 -> V_130 = 1 ;
V_4 -> V_52 = 0x10 ;
V_4 -> V_53 = V_424 |
V_425 ;
if ( V_2 -> V_5 . V_243 )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_426 [ V_2 -> V_427 ] ,
L_59 , 0 , V_428 ) ;
if ( V_2 -> V_5 . V_429 == V_430 )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_426 [ V_2 -> V_427 ] ,
L_60 , 0 , V_431 ) ;
if ( V_2 -> V_5 . V_429 == V_432 )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_426 [ V_2 -> V_427 ] ,
L_61 , 0 , V_433 ) ;
if ( V_2 -> V_5 . V_248 == V_434 )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_426 [ V_2 -> V_427 ] ,
L_62 , V_2 -> V_5 . V_435 , NULL ) ;
if ( V_2 -> V_5 . V_348 != V_349 ) {
unsigned short V_401 = V_2 -> V_5 . V_401 ;
int V_436 = ( V_2 -> V_5 . V_412 & V_437 ) ;
if ( V_2 -> V_5 . V_409 . type )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_426 [ V_2 -> V_427 ] ,
L_63 , V_2 -> V_5 . V_410 , NULL ) ;
if ( V_436 )
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_426 [ V_2 -> V_427 ] , L_63 ,
0 , F_143 ( V_438 ) ) ;
if ( V_401 == 0 ) {
enum V_439 type =
V_436 ? V_440 : V_441 ;
struct V_442 * V_443 ;
V_443 = F_142 ( & V_4 -> V_17 ,
& V_2 -> V_426 [ V_2 -> V_427 ] , L_63 ,
0 , F_143 ( type ) ) ;
if ( V_443 )
V_401 = F_144 ( V_443 ) ;
} else {
F_142 ( & V_4 -> V_17 ,
& V_2 -> V_426 [ V_2 -> V_427 ] ,
L_63 , V_401 , NULL ) ;
}
F_136 ( V_2 , V_401 ) ;
}
if ( V_2 -> V_444 != V_445 )
F_145 ( V_2 ) ;
V_44 = F_146 ( V_2 ) ;
if ( V_44 < 0 ) {
F_18 ( L_64 ,
V_200 , V_44 ) ;
goto V_446;
}
if ( V_2 -> V_345 . V_447 != V_448 ) {
F_147 ( V_422 , & V_449 ,
V_254 , 0 , 1 , 1 , 1 ) ;
F_147 ( V_422 , & V_449 ,
V_257 , 0 , 0x1f , 1 , 0x1f ) ;
} else {
F_148 ( F_149 ( V_422 , V_254 ) ,
F_60 , V_2 ) ;
F_148 ( F_149 ( V_422 , V_257 ) ,
F_60 , V_2 ) ;
}
F_4 ( V_2 ) ;
F_150 ( & V_2 -> V_154 . V_145 ) ;
F_150 ( & V_2 -> V_156 . V_145 ) ;
if ( V_2 -> V_5 . V_243 ) {
V_44 = F_8 ( V_2 , V_450 , 0xf7 ) ;
if ( V_44 < 0 ) {
F_18 ( L_65 ,
V_200 , V_44 ) ;
goto V_446;
}
F_151 ( 3 ) ;
V_44 = F_8 ( V_2 , V_450 , 0xff ) ;
if ( V_44 < 0 ) {
F_18 ( L_66 ,
V_200 , V_44 ) ;
goto V_446;
}
F_151 ( 3 ) ;
}
V_4 -> V_10 = V_451 ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_282 , V_4 -> V_10 ) ;
V_4 -> V_278 = V_452 ;
V_4 -> V_47 = & V_47 [ 0 ] ;
V_267 = F_1 ( V_2 ) ;
if ( V_2 -> V_5 . V_86 )
V_267 /= 2 ;
F_69 ( V_2 , V_47 [ 0 ] . V_274 ,
V_267 , F_2 ( V_2 ) ) ;
F_57 ( V_2 , 0 ) ;
V_2 -> V_255 = 1 ;
V_2 -> V_258 = 0x1f ;
V_256 = ( T_1 ) F_93 ( V_2 , V_453 ) ;
F_8 ( V_2 , V_453 ,
( V_454 | V_256 ) ) ;
F_9 ( V_2 ) ;
if ( NULL == F_149 ( V_422 , V_261 ) )
F_147 ( V_422 , & V_449 ,
V_261 ,
0 , 0x1f , 1 , V_26 ) ;
if ( NULL == F_149 ( V_422 , V_262 ) )
F_147 ( V_422 , & V_449 ,
V_262 ,
- 0x80 , 0x7f , 1 , V_28 ) ;
if ( NULL == F_149 ( V_422 , V_263 ) )
F_147 ( V_422 , & V_449 ,
V_263 ,
0 , 0x1f , 1 , V_30 ) ;
if ( NULL == F_149 ( V_422 , V_264 ) )
F_147 ( V_422 , & V_449 ,
V_264 ,
- 0x30 , 0x30 , 1 , V_32 ) ;
if ( NULL == F_149 ( V_422 , V_265 ) )
F_147 ( V_422 , & V_449 ,
V_265 ,
- 0x30 , 0x30 , 1 , V_34 ) ;
if ( NULL == F_149 ( V_422 , V_266 ) )
F_147 ( V_422 , & V_449 ,
V_266 ,
0 , 0x0f , 1 , V_36 ) ;
F_7 ( V_2 ) ;
F_152 ( V_422 ) ;
V_44 = V_422 -> error ;
if ( V_44 )
goto V_446;
V_4 -> V_210 = F_132 ( V_2 , & V_455 , L_67 ) ;
if ( ! V_4 -> V_210 ) {
F_18 ( L_68 ) ;
V_44 = - V_456 ;
goto V_446;
}
F_153 ( & V_4 -> V_457 ) ;
F_153 ( & V_4 -> V_458 ) ;
V_4 -> V_210 -> V_459 = & V_4 -> V_221 ;
V_4 -> V_210 -> V_459 -> V_383 = & V_4 -> V_457 ;
if ( V_2 -> V_5 . V_6 ) {
F_154 ( V_4 -> V_210 , V_460 ) ;
F_154 ( V_4 -> V_210 , V_461 ) ;
F_154 ( V_4 -> V_210 , V_462 ) ;
} else {
F_154 ( V_4 -> V_210 , V_463 ) ;
}
if ( V_2 -> V_348 == V_349 ) {
F_154 ( V_4 -> V_210 , V_464 ) ;
F_154 ( V_4 -> V_210 , V_465 ) ;
F_154 ( V_4 -> V_210 , V_466 ) ;
F_154 ( V_4 -> V_210 , V_467 ) ;
}
if ( ! V_2 -> V_345 . V_346 ) {
F_154 ( V_4 -> V_210 , V_468 ) ;
F_154 ( V_4 -> V_210 , V_469 ) ;
}
V_44 = F_155 ( V_4 -> V_210 , V_338 ,
V_470 [ V_2 -> V_471 ] ) ;
if ( V_44 ) {
F_18 ( L_69 ,
V_44 ) ;
goto V_446;
}
if ( F_3 ( V_2 ) == 1 ) {
V_4 -> V_352 = F_132 ( V_2 , & V_455 ,
L_70 ) ;
V_4 -> V_352 -> V_459 = & V_4 -> V_235 ;
V_4 -> V_352 -> V_459 -> V_383 = & V_4 -> V_458 ;
F_154 ( V_4 -> V_210 , V_463 ) ;
if ( V_2 -> V_348 == V_349 ) {
F_154 ( V_4 -> V_352 , V_464 ) ;
F_154 ( V_4 -> V_352 , V_465 ) ;
F_154 ( V_4 -> V_352 , V_466 ) ;
F_154 ( V_4 -> V_352 , V_467 ) ;
}
if ( ! V_2 -> V_345 . V_346 ) {
F_154 ( V_4 -> V_352 , V_468 ) ;
F_154 ( V_4 -> V_352 , V_469 ) ;
}
V_44 = F_155 ( V_4 -> V_352 , V_380 ,
V_472 [ V_2 -> V_471 ] ) ;
if ( V_44 < 0 ) {
F_18 ( L_71 ) ;
goto V_446;
}
}
if ( V_335 [ V_2 -> V_336 ] . V_409 . type == V_473 ) {
V_4 -> V_353 = F_132 ( V_2 , & V_474 ,
L_72 ) ;
if ( ! V_4 -> V_353 ) {
F_18 ( L_68 ) ;
V_44 = - V_456 ;
goto V_446;
}
V_44 = F_155 ( V_4 -> V_353 , V_212 ,
V_475 [ V_2 -> V_471 ] ) ;
if ( V_44 < 0 ) {
F_18 ( L_73 ) ;
goto V_446;
}
F_119 ( L_74 ,
F_110 ( V_4 -> V_353 ) ) ;
}
F_119 ( L_75 ,
F_110 ( V_4 -> V_210 ) ) ;
if ( V_4 -> V_352 )
F_119 ( L_76 ,
F_110 ( V_4 -> V_352 ) ) ;
F_5 ( & V_4 -> V_17 , 0 , V_18 , V_393 , 0 ) ;
F_55 ( V_2 ) ;
F_119 ( L_77 ) ;
F_116 ( & V_2 -> V_377 ) ;
F_113 ( & V_2 -> V_383 ) ;
return 0 ;
V_446:
F_123 ( & V_4 -> V_260 ) ;
F_124 ( & V_4 -> V_17 ) ;
V_423:
V_2 -> V_4 = NULL ;
F_126 ( & V_4 -> V_377 , F_107 ) ;
F_113 ( & V_2 -> V_383 ) ;
return V_44 ;
}
static int T_5 F_156 ( void )
{
return F_157 ( & V_476 ) ;
}
static void T_6 F_158 ( void )
{
F_159 ( & V_476 ) ;
}
