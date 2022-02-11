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
struct V_1 * V_2 = F_65 ( V_270 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_203 -> V_45 . V_195 . V_73 = V_4 -> V_73 ;
V_203 -> V_45 . V_195 . V_74 = V_4 -> V_74 ;
V_203 -> V_45 . V_195 . V_271 = V_4 -> V_47 -> V_272 ;
V_203 -> V_45 . V_195 . V_127 = ( V_4 -> V_73 * V_4 -> V_47 -> V_197 + 7 ) >> 3 ;
V_203 -> V_45 . V_195 . V_196 = V_203 -> V_45 . V_195 . V_127 * V_4 -> V_74 ;
V_203 -> V_45 . V_195 . V_273 = V_274 ;
if ( V_4 -> V_130 )
V_203 -> V_45 . V_195 . V_113 = V_275 ;
else
V_203 -> V_45 . V_195 . V_113 = V_4 -> V_276 ?
V_114 : V_277 ;
return 0 ;
}
static struct V_278 * F_66 ( unsigned int V_272 )
{
unsigned int V_94 ;
for ( V_94 = 0 ; V_94 < F_67 ( V_47 ) ; V_94 ++ )
if ( V_47 [ V_94 ] . V_272 == V_272 )
return & V_47 [ V_94 ] ;
return NULL ;
}
static int F_68 ( struct V_270 * V_270 , void * V_252 ,
struct V_189 * V_203 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_73 = V_203 -> V_45 . V_195 . V_73 ;
unsigned int V_74 = V_203 -> V_45 . V_195 . V_74 ;
unsigned int V_267 = F_1 ( V_2 ) ;
unsigned int V_268 = F_2 ( V_2 ) ;
unsigned int V_91 , V_92 ;
struct V_278 * V_45 ;
V_45 = F_66 ( V_203 -> V_45 . V_195 . V_271 ) ;
if ( ! V_45 ) {
F_11 ( L_31 ,
V_203 -> V_45 . V_195 . V_271 ) ;
return - V_198 ;
}
if ( V_2 -> V_5 . V_86 ) {
V_74 = V_74 > ( 3 * V_268 / 4 ) ? V_268 : V_268 / 2 ;
V_73 = V_73 > ( 3 * V_267 / 4 ) ? V_267 : V_267 / 2 ;
if ( V_73 == V_267 && V_74 == V_268 )
V_73 /= 2 ;
} else {
F_69 ( & V_73 , 48 , V_267 , 1 , & V_74 , 32 , V_268 ,
1 , 0 ) ;
}
F_62 ( V_2 , V_73 , V_74 , & V_91 , & V_92 ) ;
F_63 ( V_2 , V_91 , V_92 , & V_73 , & V_74 ) ;
V_203 -> V_45 . V_195 . V_73 = V_73 ;
V_203 -> V_45 . V_195 . V_74 = V_74 ;
V_203 -> V_45 . V_195 . V_271 = V_45 -> V_272 ;
V_203 -> V_45 . V_195 . V_127 = ( V_73 * V_45 -> V_197 + 7 ) >> 3 ;
V_203 -> V_45 . V_195 . V_196 = V_203 -> V_45 . V_195 . V_127 * V_74 ;
V_203 -> V_45 . V_195 . V_273 = V_274 ;
if ( V_4 -> V_130 )
V_203 -> V_45 . V_195 . V_113 = V_275 ;
else
V_203 -> V_45 . V_195 . V_113 = V_4 -> V_276 ?
V_114 : V_277 ;
V_203 -> V_45 . V_195 . V_252 = 0 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , unsigned int V_272 ,
unsigned V_73 , unsigned V_74 )
{
struct V_278 * V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_45 = F_66 ( V_272 ) ;
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
static int F_71 ( struct V_270 * V_270 , void * V_252 ,
struct V_189 * V_203 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_72 ( & V_4 -> V_221 ) )
return - V_186 ;
F_68 ( V_270 , V_252 , V_203 ) ;
return F_70 ( V_2 , V_203 -> V_45 . V_195 . V_271 ,
V_203 -> V_45 . V_195 . V_73 , V_203 -> V_45 . V_195 . V_74 ) ;
}
static int F_73 ( struct V_270 * V_270 , void * V_252 , T_3 * V_10 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
* V_10 = V_2 -> V_4 -> V_10 ;
return 0 ;
}
static int F_74 ( struct V_270 * V_270 , void * V_252 , T_3 * V_10 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_20 , V_279 , V_10 ) ;
return 0 ;
}
static int F_75 ( struct V_270 * V_270 , void * V_252 , T_3 V_10 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_189 V_203 ;
if ( V_10 == V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_205 > 0 )
return - V_186 ;
V_4 -> V_10 = V_10 ;
V_203 . V_45 . V_195 . V_73 = 720 ;
V_203 . V_45 . V_195 . V_74 = ( V_10 & V_60 ) ? 480 : 576 ;
F_68 ( V_270 , V_252 , & V_203 ) ;
V_4 -> V_73 = V_203 . V_45 . V_195 . V_73 ;
V_4 -> V_74 = V_203 . V_45 . V_195 . V_74 ;
F_62 ( V_2 , V_4 -> V_73 , V_4 -> V_74 ,
& V_4 -> V_91 , & V_4 -> V_92 ) ;
F_15 ( V_2 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_280 , V_4 -> V_10 ) ;
return 0 ;
}
static int F_76 ( struct V_270 * V_270 , void * V_252 ,
struct V_281 * V_282 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_204 = 0 ;
V_282 -> V_283 . V_284 . V_285 = V_286 ;
if ( V_2 -> V_5 . V_6 )
V_204 = F_77 ( & V_4 -> V_17 , 0 ,
V_20 , V_287 , V_282 ) ;
else
F_78 ( V_4 -> V_10 ,
& V_282 -> V_283 . V_284 . V_288 ) ;
return V_204 ;
}
static int F_79 ( struct V_270 * V_270 , void * V_252 ,
struct V_281 * V_282 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
V_282 -> V_283 . V_284 . V_285 = V_286 ;
return F_77 ( & V_2 -> V_4 -> V_17 ,
0 , V_20 , V_289 , V_282 ) ;
}
static int F_80 ( struct V_270 * V_270 , void * V_252 ,
struct V_290 * V_94 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
unsigned int V_291 ;
V_291 = V_94 -> V_237 ;
if ( V_291 >= V_292 )
return - V_198 ;
if ( 0 == F_6 ( V_291 ) -> type )
return - V_198 ;
V_94 -> V_237 = V_291 ;
V_94 -> type = V_293 ;
strcpy ( V_94 -> V_294 , V_295 [ F_6 ( V_291 ) -> type ] ) ;
if ( ( V_296 == F_6 ( V_291 ) -> type ) ||
( V_297 == F_6 ( V_291 ) -> type ) )
V_94 -> type = V_298 ;
V_94 -> V_299 = V_2 -> V_4 -> V_210 -> V_300 ;
if ( V_2 -> V_5 . V_6 )
V_94 -> V_301 = 0 ;
return 0 ;
}
static int F_81 ( struct V_270 * V_270 , void * V_252 , unsigned int * V_94 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
* V_94 = V_2 -> V_22 ;
return 0 ;
}
static int F_82 ( struct V_270 * V_270 , void * V_252 , unsigned int V_94 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
if ( V_94 >= V_292 )
return - V_198 ;
if ( 0 == F_6 ( V_94 ) -> type )
return - V_198 ;
F_57 ( V_2 , V_94 ) ;
return 0 ;
}
static int F_83 ( struct V_270 * V_270 , void * V_252 , struct V_302 * V_303 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
switch ( V_303 -> V_237 ) {
case V_304 :
strcpy ( V_303 -> V_294 , L_32 ) ;
break;
case V_305 :
strcpy ( V_303 -> V_294 , L_33 ) ;
break;
case V_306 :
strcpy ( V_303 -> V_294 , L_34 ) ;
break;
case V_307 :
strcpy ( V_303 -> V_294 , L_35 ) ;
break;
case V_308 :
strcpy ( V_303 -> V_294 , L_36 ) ;
break;
case V_309 :
strcpy ( V_303 -> V_294 , L_37 ) ;
break;
case V_310 :
strcpy ( V_303 -> V_294 , L_38 ) ;
break;
case V_311 :
strcpy ( V_303 -> V_294 , L_39 ) ;
break;
default:
return - V_198 ;
}
V_303 -> V_237 = V_2 -> V_238 ;
V_303 -> V_312 = V_313 ;
return 0 ;
}
static int F_84 ( struct V_270 * V_270 , void * V_252 , const struct V_302 * V_303 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
if ( V_303 -> V_237 >= V_292 )
return - V_198 ;
if ( 0 == F_6 ( V_303 -> V_237 ) -> type )
return - V_198 ;
V_2 -> V_238 = F_6 ( V_303 -> V_237 ) -> V_239 ;
V_2 -> V_240 = F_6 ( V_303 -> V_237 ) -> V_241 ;
if ( ! V_2 -> V_240 )
V_2 -> V_240 = V_242 ;
return 0 ;
}
static int F_85 ( struct V_270 * V_270 , void * V_252 ,
struct V_314 * V_315 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
if ( 0 != V_315 -> V_237 )
return - V_198 ;
strcpy ( V_315 -> V_294 , L_40 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_215 , V_316 , V_315 ) ;
return 0 ;
}
static int F_86 ( struct V_270 * V_270 , void * V_252 ,
const struct V_314 * V_315 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
if ( 0 != V_315 -> V_237 )
return - V_198 ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_215 , V_317 , V_315 ) ;
return 0 ;
}
static int F_87 ( struct V_270 * V_270 , void * V_252 ,
struct V_202 * V_203 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_203 -> V_215 )
return - V_198 ;
V_203 -> V_208 = V_4 -> V_208 ;
return 0 ;
}
static int F_88 ( struct V_270 * V_270 , void * V_252 ,
const struct V_202 * V_203 )
{
struct V_202 V_318 = * V_203 ;
struct V_1 * V_2 = F_65 ( V_270 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_203 -> V_215 )
return - V_198 ;
F_5 ( & V_4 -> V_17 , 0 , V_215 , V_216 , V_203 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_215 , V_319 , & V_318 ) ;
V_4 -> V_208 = V_318 . V_208 ;
return 0 ;
}
static int F_89 ( struct V_270 * V_270 , void * V_252 ,
struct V_320 * V_321 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
if ( V_321 -> V_322 . V_323 > 1 )
return - V_198 ;
if ( V_321 -> V_322 . V_323 == 1 )
F_90 ( V_321 -> V_294 , L_41 , sizeof( V_321 -> V_294 ) ) ;
else
F_90 ( V_321 -> V_294 ,
V_2 -> V_4 -> V_17 . V_294 , sizeof( V_321 -> V_294 ) ) ;
return 0 ;
}
static int F_91 ( int V_48 )
{
switch ( V_48 ) {
case V_324 :
case V_88 :
case V_89 :
return 2 ;
default:
return 1 ;
}
}
static int F_92 ( struct V_270 * V_270 , void * V_252 ,
struct V_325 * V_48 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
int V_44 ;
if ( V_48 -> V_322 . V_323 > 1 )
return - V_198 ;
if ( V_48 -> V_322 . V_323 ) {
V_44 = F_93 ( V_2 , V_48 -> V_48 ) ;
if ( V_44 < 0 )
return V_44 ;
V_48 -> V_256 = V_44 ;
V_48 -> V_194 = 1 ;
return 0 ;
}
V_48 -> V_194 = F_91 ( V_48 -> V_48 ) ;
if ( V_48 -> V_194 == 1 ) {
V_44 = F_94 ( V_2 , V_48 -> V_48 ) ;
if ( V_44 < 0 )
return V_44 ;
V_48 -> V_256 = V_44 ;
} else {
T_4 V_256 = 0 ;
V_44 = V_2 -> V_326 ( V_2 , V_327 ,
V_48 -> V_48 , ( char * ) & V_256 , 2 ) ;
if ( V_44 < 0 )
return V_44 ;
V_48 -> V_256 = F_95 ( V_256 ) ;
}
return 0 ;
}
static int F_96 ( struct V_270 * V_270 , void * V_252 ,
const struct V_325 * V_48 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
T_4 V_87 ;
if ( V_48 -> V_322 . V_323 > 1 )
return - V_198 ;
if ( V_48 -> V_322 . V_323 )
return F_97 ( V_2 , V_48 -> V_48 , V_48 -> V_256 ) ;
V_87 = F_98 ( V_48 -> V_256 ) ;
return F_12 ( V_2 , V_48 -> V_48 , ( char * ) & V_87 ,
F_91 ( V_48 -> V_48 ) ) ;
}
static int F_99 ( struct V_270 * V_270 , void * V_252 ,
struct V_328 * V_329 )
{
struct V_330 * V_210 = F_100 ( V_270 ) ;
struct V_1 * V_2 = F_65 ( V_270 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_90 ( V_329 -> V_331 , L_42 , sizeof( V_329 -> V_331 ) ) ;
F_90 ( V_329 -> V_332 , V_333 [ V_2 -> V_334 ] . V_294 , sizeof( V_329 -> V_332 ) ) ;
F_101 ( V_2 -> V_105 , V_329 -> V_335 , sizeof( V_329 -> V_335 ) ) ;
if ( V_210 -> V_211 == V_336 )
V_329 -> V_337 = V_338 |
V_339 | V_340 ;
else if ( V_210 -> V_211 == V_212 )
V_329 -> V_337 = V_341 ;
else
V_329 -> V_337 = V_338 | V_342 ;
if ( V_2 -> V_343 . V_344 )
V_329 -> V_337 |= V_345 ;
if ( V_2 -> V_346 != V_347 )
V_329 -> V_337 |= V_348 ;
V_329 -> V_301 = V_329 -> V_337 | V_349 |
V_338 | V_339 | V_340 ;
if ( V_4 -> V_350 )
V_329 -> V_301 |= V_342 ;
if ( V_4 -> V_351 )
V_329 -> V_301 |= V_341 ;
return 0 ;
}
static int F_102 ( struct V_270 * V_270 , void * V_252 ,
struct V_352 * V_203 )
{
if ( F_103 ( V_203 -> V_237 >= F_67 ( V_47 ) ) )
return - V_198 ;
F_90 ( V_203 -> V_353 , V_47 [ V_203 -> V_237 ] . V_294 , sizeof( V_203 -> V_353 ) ) ;
V_203 -> V_271 = V_47 [ V_203 -> V_237 ] . V_272 ;
return 0 ;
}
static int F_104 ( struct V_270 * V_270 , void * V_252 ,
struct V_354 * V_355 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
struct V_278 * V_45 ;
unsigned int V_267 = F_1 ( V_2 ) ;
unsigned int V_268 = F_2 ( V_2 ) ;
V_45 = F_66 ( V_355 -> V_356 ) ;
if ( ! V_45 ) {
F_11 ( L_31 ,
V_355 -> V_356 ) ;
return - V_198 ;
}
if ( V_2 -> V_5 . V_86 ) {
if ( V_355 -> V_237 > 1 )
return - V_198 ;
V_355 -> type = V_357 ;
V_355 -> V_358 . V_73 = V_267 / ( 1 + V_355 -> V_237 ) ;
V_355 -> V_358 . V_74 = V_268 / ( 1 + V_355 -> V_237 ) ;
return 0 ;
}
if ( V_355 -> V_237 != 0 )
return - V_198 ;
V_355 -> type = V_359 ;
F_63 ( V_2 , V_269 , V_269 ,
& V_355 -> V_360 . V_361 , & V_355 -> V_360 . V_362 ) ;
if ( V_355 -> V_360 . V_361 < 48 )
V_355 -> V_360 . V_361 = 48 ;
if ( V_355 -> V_360 . V_362 < 38 )
V_355 -> V_360 . V_362 = 38 ;
V_355 -> V_360 . V_363 = V_267 ;
V_355 -> V_360 . V_364 = V_268 ;
V_355 -> V_360 . V_365 = 1 ;
V_355 -> V_360 . V_366 = 1 ;
return 0 ;
}
static int F_105 ( struct V_270 * V_270 , void * V_252 ,
struct V_189 * V_47 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_47 -> V_45 . V_367 . V_368 = V_4 -> V_57 ;
V_47 -> V_45 . V_367 . V_369 = V_370 ;
V_47 -> V_45 . V_367 . V_124 = 0 ;
V_47 -> V_45 . V_367 . V_217 = 0 ;
V_47 -> V_45 . V_367 . V_371 = 6750000 * 4 / 2 ;
V_47 -> V_45 . V_367 . V_201 [ 0 ] = V_4 -> V_59 ;
V_47 -> V_45 . V_367 . V_201 [ 1 ] = V_4 -> V_59 ;
memset ( V_47 -> V_45 . V_367 . V_372 , 0 , sizeof( V_47 -> V_45 . V_367 . V_372 ) ) ;
if ( V_4 -> V_10 & V_60 ) {
V_47 -> V_45 . V_367 . V_373 [ 0 ] = 10 ;
V_47 -> V_45 . V_367 . V_373 [ 1 ] = 273 ;
} else if ( V_4 -> V_10 & V_11 ) {
V_47 -> V_45 . V_367 . V_373 [ 0 ] = 6 ;
V_47 -> V_45 . V_367 . V_373 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_106 ( struct V_270 * V_270 , void * V_252 ,
struct V_314 * V_315 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
if ( F_103 ( V_315 -> V_237 > 0 ) )
return - V_198 ;
strcpy ( V_315 -> V_294 , L_43 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_215 , V_316 , V_315 ) ;
return 0 ;
}
static int F_107 ( struct V_270 * V_270 , void * V_252 ,
const struct V_314 * V_315 )
{
struct V_1 * V_2 = F_65 ( V_270 ) ;
if ( 0 != V_315 -> V_237 )
return - V_198 ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_215 , V_317 , V_315 ) ;
return 0 ;
}
static void F_108 ( struct V_374 * V_375 )
{
struct V_3 * V_4 = F_42 ( V_375 , struct V_3 , V_375 ) ;
V_4 -> V_2 -> V_4 = NULL ;
F_109 ( V_4 ) ;
}
static int F_110 ( struct V_270 * V_376 )
{
struct V_330 * V_210 = F_100 ( V_376 ) ;
struct V_1 * V_2 = F_65 ( V_376 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
enum V_178 V_377 = 0 ;
int V_44 ;
switch ( V_210 -> V_211 ) {
case V_336 :
V_377 = V_180 ;
break;
case V_378 :
V_377 = V_182 ;
break;
case V_212 :
break;
default:
return - V_198 ;
}
F_11 ( L_44 ,
F_111 ( V_210 ) , V_379 [ V_377 ] ,
V_4 -> V_380 ) ;
if ( F_112 ( & V_2 -> V_381 ) )
return - V_382 ;
V_44 = F_113 ( V_376 ) ;
if ( V_44 ) {
F_18 ( L_45 ,
V_200 , V_44 ) ;
F_114 ( & V_2 -> V_381 ) ;
return V_44 ;
}
if ( V_4 -> V_380 == 0 ) {
F_115 ( V_2 , V_206 ) ;
if ( V_210 -> V_211 != V_212 )
F_15 ( V_2 ) ;
F_4 ( V_2 ) ;
}
if ( V_210 -> V_211 == V_212 ) {
F_11 ( L_46 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_215 , V_383 ) ;
}
F_116 ( & V_2 -> V_375 ) ;
F_116 ( & V_4 -> V_375 ) ;
V_4 -> V_380 ++ ;
F_114 ( & V_2 -> V_381 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_384 ) {
return 0 ;
}
if ( ! V_2 -> V_385 ) {
return 0 ;
}
if ( V_4 == NULL )
return 0 ;
F_118 ( L_47 ) ;
F_119 ( & V_2 -> V_381 ) ;
F_120 ( & V_4 -> V_17 ) ;
F_48 ( V_2 , V_206 ) ;
if ( V_4 -> V_351 ) {
F_118 ( L_48 ,
F_111 ( V_4 -> V_351 ) ) ;
F_121 ( V_4 -> V_351 ) ;
}
if ( V_4 -> V_350 ) {
F_118 ( L_48 ,
F_111 ( V_4 -> V_350 ) ) ;
F_121 ( V_4 -> V_350 ) ;
}
if ( V_4 -> V_210 ) {
F_118 ( L_48 ,
F_111 ( V_4 -> V_210 ) ) ;
F_121 ( V_4 -> V_210 ) ;
}
F_122 ( & V_4 -> V_260 ) ;
F_123 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_386 ) {
F_124 ( V_4 -> V_386 ) ;
V_4 -> V_386 = NULL ;
}
F_125 ( & V_4 -> V_375 , F_108 ) ;
F_114 ( & V_2 -> V_381 ) ;
F_125 ( & V_2 -> V_375 , V_387 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 )
{
if ( V_2 -> V_384 )
return 0 ;
if ( ! V_2 -> V_385 )
return 0 ;
F_118 ( L_49 ) ;
F_127 ( V_2 ) ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 )
{
if ( V_2 -> V_384 )
return 0 ;
if ( ! V_2 -> V_385 )
return 0 ;
F_118 ( L_50 ) ;
return 0 ;
}
static int F_129 ( struct V_270 * V_376 )
{
struct V_1 * V_2 = F_65 ( V_376 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_93 ;
F_11 ( L_51 , V_4 -> V_380 ) ;
F_130 ( V_376 ) ;
F_119 ( & V_2 -> V_381 ) ;
if ( V_4 -> V_380 == 1 ) {
if ( V_2 -> V_172 )
goto exit;
F_5 ( & V_4 -> V_17 , 0 , V_18 , V_388 , 0 ) ;
F_115 ( V_2 , V_389 ) ;
V_2 -> V_96 = 0 ;
F_11 ( L_52 ) ;
V_93 = F_17 ( V_2 -> V_105 , 0 , 0 ) ;
if ( V_93 < 0 ) {
F_18 ( L_53
L_54 , V_93 ) ;
}
}
exit:
V_4 -> V_380 -- ;
F_125 ( & V_4 -> V_375 , F_108 ) ;
F_114 ( & V_2 -> V_381 ) ;
F_125 ( & V_2 -> V_375 , V_387 ) ;
return 0 ;
}
static struct V_330 * F_131 ( struct V_1 * V_2 ,
const struct V_330 * V_390 ,
const char * V_391 )
{
struct V_330 * V_392 ;
V_392 = F_132 () ;
if ( NULL == V_392 )
return NULL ;
* V_392 = * V_390 ;
V_392 -> V_17 = & V_2 -> V_4 -> V_17 ;
V_392 -> V_393 = V_394 ;
V_392 -> V_381 = & V_2 -> V_381 ;
if ( V_2 -> V_5 . V_6 )
V_392 -> V_300 = 0 ;
snprintf ( V_392 -> V_294 , sizeof( V_392 -> V_294 ) , L_55 ,
V_2 -> V_294 , V_391 ) ;
F_133 ( V_392 , V_2 ) ;
return V_392 ;
}
static void F_134 ( struct V_1 * V_2 , unsigned short V_395 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_16 * V_17 = & V_4 -> V_17 ;
struct V_396 V_397 ;
struct V_202 V_203 ;
memset ( & V_397 , 0 , sizeof( V_397 ) ) ;
V_397 . V_398 = V_399 | V_400 ;
V_397 . V_401 = V_402 ;
if ( V_2 -> V_5 . V_403 . type ) {
V_397 . type = V_2 -> V_5 . V_403 . type ;
V_397 . V_323 = V_2 -> V_5 . V_404 ;
F_5 ( V_17 ,
0 , V_215 , V_405 , & V_397 ) ;
}
if ( ( V_2 -> V_346 != V_347 ) && ( V_2 -> V_346 ) ) {
V_397 . type = V_2 -> V_346 ;
V_397 . V_323 = V_395 ;
F_5 ( V_17 ,
0 , V_215 , V_405 , & V_397 ) ;
}
if ( V_2 -> V_5 . V_406 ) {
struct V_407 V_408 ;
V_408 . V_215 = V_409 ;
V_408 . V_252 = & V_2 -> V_5 . V_406 ;
F_5 ( V_17 ,
0 , V_215 , V_410 , & V_408 ) ;
}
if ( V_2 -> V_346 == V_411 ) {
struct V_407 V_412 ;
struct V_413 V_414 ;
memset ( & V_412 , 0 , sizeof( V_412 ) ) ;
memset ( & V_414 , 0 , sizeof( V_414 ) ) ;
F_135 ( V_2 , & V_414 ) ;
V_412 . V_215 = V_411 ;
V_412 . V_252 = & V_414 ;
F_5 ( V_17 , 0 , V_215 , V_410 , & V_412 ) ;
}
V_203 . V_215 = 0 ;
V_203 . type = V_214 ;
V_203 . V_208 = 9076 ;
V_4 -> V_208 = V_203 . V_208 ;
F_5 ( V_17 , 0 , V_215 , V_216 , & V_203 ) ;
}
static int F_136 ( struct V_1 * V_2 )
{
T_1 V_256 ;
int V_44 ;
unsigned int V_267 ;
struct V_415 * V_416 ;
struct V_3 * V_4 ;
if ( V_2 -> V_384 ) {
return 0 ;
}
if ( ! V_2 -> V_385 ) {
return 0 ;
}
F_118 ( L_56 ) ;
F_119 ( & V_2 -> V_381 ) ;
V_4 = F_137 ( sizeof( struct V_3 ) , V_417 ) ;
if ( V_4 == NULL ) {
F_118 ( L_57 ) ;
F_114 ( & V_2 -> V_381 ) ;
return - V_418 ;
}
F_138 ( & V_4 -> V_375 ) ;
V_4 -> V_2 = V_2 ;
V_2 -> V_4 = V_4 ;
V_44 = F_139 ( & V_2 -> V_105 -> V_2 , & V_4 -> V_17 ) ;
if ( V_44 < 0 ) {
F_18 ( L_58 ) ;
goto V_419;
}
V_416 = & V_4 -> V_260 ;
F_140 ( V_416 , 8 ) ;
V_4 -> V_17 . V_260 = V_416 ;
if ( V_2 -> V_5 . V_6 )
V_4 -> V_130 = 1 ;
V_4 -> V_52 = 0x10 ;
V_4 -> V_53 = V_420 |
V_421 ;
if ( V_2 -> V_5 . V_243 )
F_141 ( & V_4 -> V_17 ,
& V_2 -> V_422 [ V_2 -> V_423 ] ,
L_59 , 0 , V_424 ) ;
if ( V_2 -> V_5 . V_425 == V_426 )
F_141 ( & V_4 -> V_17 ,
& V_2 -> V_422 [ V_2 -> V_423 ] ,
L_60 , 0 , V_427 ) ;
if ( V_2 -> V_5 . V_425 == V_428 )
F_141 ( & V_4 -> V_17 ,
& V_2 -> V_422 [ V_2 -> V_423 ] ,
L_61 , 0 , V_429 ) ;
if ( V_2 -> V_5 . V_248 == V_430 )
F_141 ( & V_4 -> V_17 ,
& V_2 -> V_422 [ V_2 -> V_423 ] ,
L_62 , V_2 -> V_5 . V_431 , NULL ) ;
if ( V_2 -> V_5 . V_346 != V_347 ) {
unsigned short V_395 = V_2 -> V_5 . V_395 ;
int V_432 = ( V_2 -> V_5 . V_406 & V_433 ) ;
if ( V_2 -> V_5 . V_403 . type )
F_141 ( & V_4 -> V_17 ,
& V_2 -> V_422 [ V_2 -> V_423 ] ,
L_63 , V_2 -> V_5 . V_404 , NULL ) ;
if ( V_432 )
F_141 ( & V_4 -> V_17 ,
& V_2 -> V_422 [ V_2 -> V_423 ] , L_63 ,
0 , F_142 ( V_434 ) ) ;
if ( V_395 == 0 ) {
enum V_435 type =
V_432 ? V_436 : V_437 ;
struct V_438 * V_439 ;
V_439 = F_141 ( & V_4 -> V_17 ,
& V_2 -> V_422 [ V_2 -> V_423 ] , L_63 ,
0 , F_142 ( type ) ) ;
if ( V_439 )
V_395 = F_143 ( V_439 ) ;
} else {
F_141 ( & V_4 -> V_17 ,
& V_2 -> V_422 [ V_2 -> V_423 ] ,
L_63 , V_395 , NULL ) ;
}
F_134 ( V_2 , V_395 ) ;
}
if ( V_2 -> V_440 != V_441 )
F_144 ( V_2 ) ;
V_44 = F_145 ( V_2 ) ;
if ( V_44 < 0 ) {
F_18 ( L_64 ,
V_200 , V_44 ) ;
goto V_442;
}
if ( V_2 -> V_343 . V_443 != V_444 ) {
F_146 ( V_416 , & V_445 ,
V_254 , 0 , 1 , 1 , 1 ) ;
F_146 ( V_416 , & V_445 ,
V_257 , 0 , 0x1f , 1 , 0x1f ) ;
} else {
F_147 ( F_148 ( V_416 , V_254 ) ,
F_60 , V_2 ) ;
F_147 ( F_148 ( V_416 , V_257 ) ,
F_60 , V_2 ) ;
}
F_4 ( V_2 ) ;
F_149 ( & V_2 -> V_154 . V_145 ) ;
F_149 ( & V_2 -> V_156 . V_145 ) ;
if ( V_2 -> V_5 . V_243 ) {
V_44 = F_8 ( V_2 , V_446 , 0xf7 ) ;
if ( V_44 < 0 ) {
F_18 ( L_65 ,
V_200 , V_44 ) ;
goto V_442;
}
F_150 ( 3 ) ;
V_44 = F_8 ( V_2 , V_446 , 0xff ) ;
if ( V_44 < 0 ) {
F_18 ( L_66 ,
V_200 , V_44 ) ;
goto V_442;
}
F_150 ( 3 ) ;
}
V_4 -> V_10 = V_447 ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_280 , V_4 -> V_10 ) ;
V_4 -> V_276 = V_448 ;
V_4 -> V_47 = & V_47 [ 0 ] ;
V_267 = F_1 ( V_2 ) ;
if ( V_2 -> V_5 . V_86 )
V_267 /= 2 ;
F_70 ( V_2 , V_47 [ 0 ] . V_272 ,
V_267 , F_2 ( V_2 ) ) ;
F_57 ( V_2 , 0 ) ;
V_2 -> V_255 = 1 ;
V_2 -> V_258 = 0x1f ;
V_256 = ( T_1 ) F_94 ( V_2 , V_449 ) ;
F_8 ( V_2 , V_449 ,
( V_450 | V_256 ) ) ;
F_9 ( V_2 ) ;
if ( NULL == F_148 ( V_416 , V_261 ) )
F_146 ( V_416 , & V_445 ,
V_261 ,
0 , 0x1f , 1 , V_26 ) ;
if ( NULL == F_148 ( V_416 , V_262 ) )
F_146 ( V_416 , & V_445 ,
V_262 ,
- 0x80 , 0x7f , 1 , V_28 ) ;
if ( NULL == F_148 ( V_416 , V_263 ) )
F_146 ( V_416 , & V_445 ,
V_263 ,
0 , 0x1f , 1 , V_30 ) ;
if ( NULL == F_148 ( V_416 , V_264 ) )
F_146 ( V_416 , & V_445 ,
V_264 ,
- 0x30 , 0x30 , 1 , V_32 ) ;
if ( NULL == F_148 ( V_416 , V_265 ) )
F_146 ( V_416 , & V_445 ,
V_265 ,
- 0x30 , 0x30 , 1 , V_34 ) ;
if ( NULL == F_148 ( V_416 , V_266 ) )
F_146 ( V_416 , & V_445 ,
V_266 ,
0 , 0x0f , 1 , V_36 ) ;
F_7 ( V_2 ) ;
F_151 ( V_416 ) ;
V_44 = V_416 -> error ;
if ( V_44 )
goto V_442;
V_4 -> V_210 = F_131 ( V_2 , & V_451 , L_67 ) ;
if ( ! V_4 -> V_210 ) {
F_18 ( L_68 ) ;
V_44 = - V_452 ;
goto V_442;
}
F_152 ( & V_4 -> V_453 ) ;
F_152 ( & V_4 -> V_454 ) ;
V_4 -> V_210 -> V_455 = & V_4 -> V_221 ;
V_4 -> V_210 -> V_455 -> V_381 = & V_4 -> V_453 ;
if ( V_2 -> V_5 . V_6 ) {
F_153 ( V_4 -> V_210 , V_456 ) ;
F_153 ( V_4 -> V_210 , V_457 ) ;
F_153 ( V_4 -> V_210 , V_458 ) ;
} else {
F_153 ( V_4 -> V_210 , V_459 ) ;
}
if ( V_2 -> V_346 == V_347 ) {
F_153 ( V_4 -> V_210 , V_460 ) ;
F_153 ( V_4 -> V_210 , V_461 ) ;
F_153 ( V_4 -> V_210 , V_462 ) ;
F_153 ( V_4 -> V_210 , V_463 ) ;
}
if ( ! V_2 -> V_343 . V_344 ) {
F_153 ( V_4 -> V_210 , V_464 ) ;
F_153 ( V_4 -> V_210 , V_465 ) ;
}
V_44 = F_154 ( V_4 -> V_210 , V_336 ,
V_466 [ V_2 -> V_467 ] ) ;
if ( V_44 ) {
F_18 ( L_69 ,
V_44 ) ;
goto V_442;
}
if ( F_3 ( V_2 ) == 1 ) {
V_4 -> V_350 = F_131 ( V_2 , & V_451 ,
L_70 ) ;
V_4 -> V_350 -> V_455 = & V_4 -> V_235 ;
V_4 -> V_350 -> V_455 -> V_381 = & V_4 -> V_454 ;
F_153 ( V_4 -> V_350 , V_459 ) ;
if ( V_2 -> V_346 == V_347 ) {
F_153 ( V_4 -> V_350 , V_460 ) ;
F_153 ( V_4 -> V_350 , V_461 ) ;
F_153 ( V_4 -> V_350 , V_462 ) ;
F_153 ( V_4 -> V_350 , V_463 ) ;
}
if ( ! V_2 -> V_343 . V_344 ) {
F_153 ( V_4 -> V_350 , V_464 ) ;
F_153 ( V_4 -> V_350 , V_465 ) ;
}
V_44 = F_154 ( V_4 -> V_350 , V_378 ,
V_468 [ V_2 -> V_467 ] ) ;
if ( V_44 < 0 ) {
F_18 ( L_71 ) ;
goto V_442;
}
}
if ( V_333 [ V_2 -> V_334 ] . V_403 . type == V_469 ) {
V_4 -> V_351 = F_131 ( V_2 , & V_470 ,
L_72 ) ;
if ( ! V_4 -> V_351 ) {
F_18 ( L_68 ) ;
V_44 = - V_452 ;
goto V_442;
}
V_44 = F_154 ( V_4 -> V_351 , V_212 ,
V_471 [ V_2 -> V_467 ] ) ;
if ( V_44 < 0 ) {
F_18 ( L_73 ) ;
goto V_442;
}
F_118 ( L_74 ,
F_111 ( V_4 -> V_351 ) ) ;
}
F_118 ( L_75 ,
F_111 ( V_4 -> V_210 ) ) ;
if ( V_4 -> V_350 )
F_118 ( L_76 ,
F_111 ( V_4 -> V_350 ) ) ;
F_5 ( & V_4 -> V_17 , 0 , V_18 , V_388 , 0 ) ;
F_55 ( V_2 ) ;
F_118 ( L_77 ) ;
F_116 ( & V_2 -> V_375 ) ;
F_114 ( & V_2 -> V_381 ) ;
return 0 ;
V_442:
F_122 ( & V_4 -> V_260 ) ;
F_123 ( & V_4 -> V_17 ) ;
V_419:
V_2 -> V_4 = NULL ;
F_125 ( & V_4 -> V_375 , F_108 ) ;
F_114 ( & V_2 -> V_381 ) ;
return V_44 ;
}
static int T_5 F_155 ( void )
{
return F_156 ( & V_472 ) ;
}
static void T_6 F_157 ( void )
{
F_158 ( & V_472 ) ;
}
