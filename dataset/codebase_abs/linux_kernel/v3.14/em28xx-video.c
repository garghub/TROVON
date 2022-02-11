static int F_1 ( struct V_1 * V_2 )
{
if ( V_3 == 1 )
return 0 ;
if ( V_2 -> V_4 . V_5 )
return 0 ;
if ( V_2 -> V_6 == V_7 ||
V_2 -> V_6 == V_8 )
return 1 ;
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_9 , 0 , V_10 , V_11 , 0 ) ;
F_3 ( & V_2 -> V_9 , 0 , V_12 , V_13 ,
F_4 ( V_2 -> V_14 ) -> V_15 , 0 , 0 ) ;
F_3 ( & V_2 -> V_9 , 0 , V_12 , V_16 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_17 , V_18 ) ;
F_6 ( V_2 , V_19 , V_20 ) ;
F_6 ( V_2 , V_21 , V_22 ) ;
F_6 ( V_2 , V_23 , V_24 ) ;
F_6 ( V_2 , V_25 , V_26 ) ;
F_6 ( V_2 , V_27 , V_28 ) ;
F_6 ( V_2 , V_29 , 0x20 ) ;
F_6 ( V_2 , V_30 , 0x20 ) ;
F_6 ( V_2 , V_31 , 0x20 ) ;
F_6 ( V_2 , V_32 , 0x20 ) ;
F_6 ( V_2 , V_33 , 0x00 ) ;
F_6 ( V_2 , V_34 , 0x00 ) ;
return F_6 ( V_2 , V_35 , 0x00 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_36 ;
T_1 V_37 , V_38 ;
V_37 = V_2 -> V_39 -> V_40 ;
if ( ! V_2 -> V_41 )
V_37 |= 0x20 ;
V_36 = F_6 ( V_2 , V_42 , V_37 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_6 ( V_2 , V_43 , V_2 -> V_44 ) ;
if ( V_36 < 0 )
return V_36 ;
V_38 = V_2 -> V_45 ;
if ( F_1 ( V_2 ) == 1 ) {
V_38 |= V_46 ;
F_6 ( V_2 , V_47 , 0x00 ) ;
F_6 ( V_2 , V_48 , V_2 -> V_49 / 4 ) ;
F_6 ( V_2 , V_50 , V_2 -> V_51 ) ;
if ( V_2 -> V_52 & V_53 ) {
F_6 ( V_2 , V_54 , 0x09 ) ;
} else if ( V_2 -> V_52 & V_55 ) {
F_6 ( V_2 , V_54 , 0x07 ) ;
}
}
return F_6 ( V_2 , V_56 , V_38 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_57 , T_1 V_58 ,
T_1 V_59 , T_1 V_60 )
{
F_9 ( L_1 ,
V_57 , V_59 , V_58 , V_60 ) ;
F_10 ( V_2 , V_61 , & V_57 , 1 ) ;
F_10 ( V_2 , V_62 , & V_58 , 1 ) ;
F_10 ( V_2 , V_63 , & V_59 , 1 ) ;
return F_10 ( V_2 , V_64 , & V_60 , 1 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_65 , T_1 V_66 ,
T_2 V_67 , T_2 V_68 )
{
T_1 V_69 = V_67 >> 2 ;
T_1 V_70 = V_68 >> 2 ;
T_1 V_71 = ( V_68 >> 9 & 0x02 ) | ( V_67 >> 10 & 0x01 ) ;
F_9 ( L_2 ,
V_65 , V_66 ,
( ( V_71 & 2 ) << 9 | V_69 << 2 ) ,
( ( V_71 & 1 ) << 10 | V_70 << 2 ) ) ;
F_10 ( V_2 , V_72 , & V_65 , 1 ) ;
F_10 ( V_2 , V_73 , & V_66 , 1 ) ;
F_10 ( V_2 , V_74 , & V_69 , 1 ) ;
F_10 ( V_2 , V_75 , & V_70 , 1 ) ;
F_10 ( V_2 , V_76 , & V_71 , 1 ) ;
if ( V_2 -> V_41 ) {
F_6 ( V_2 , 0x34 , V_67 >> 4 ) ;
F_6 ( V_2 , 0x35 , V_68 >> 4 ) ;
}
}
static int F_12 ( struct V_1 * V_2 , T_2 V_77 , T_2 V_78 )
{
T_1 V_79 ;
if ( V_2 -> V_4 . V_80 ) {
V_79 = ( V_78 ? 0x20 : 0x00 ) | ( V_77 ? 0x10 : 0x00 ) ;
} else {
T_1 V_81 [ 2 ] ;
V_81 [ 0 ] = V_77 ;
V_81 [ 1 ] = V_77 >> 8 ;
F_10 ( V_2 , V_82 , ( char * ) V_81 , 2 ) ;
V_81 [ 0 ] = V_78 ;
V_81 [ 1 ] = V_78 >> 8 ;
F_10 ( V_2 , V_83 , ( char * ) V_81 , 2 ) ;
V_79 = ( V_77 || V_78 ) ? 0x30 : 0x00 ;
}
return F_13 ( V_2 , V_84 , V_79 , 0x30 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_67 , V_68 ;
V_67 = F_15 ( V_2 ) ;
V_68 = F_16 ( V_2 ) ;
V_2 -> V_49 = 720 ;
if ( V_2 -> V_52 & V_53 )
V_2 -> V_51 = 12 ;
else
V_2 -> V_51 = 18 ;
F_7 ( V_2 ) ;
F_8 ( V_2 , 1 , ( V_67 - 4 ) >> 2 , 1 , ( V_68 - 4 ) >> 2 ) ;
if ( F_1 ( V_2 ) == 1 )
F_11 ( V_2 , 0 , 2 , V_67 , V_68 ) ;
else
F_11 ( V_2 , 0 , 0 , V_67 , V_68 ) ;
return F_12 ( V_2 , V_2 -> V_85 , V_2 -> V_86 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_87 ;
int V_88 ;
unsigned int V_89 = V_2 -> V_67 * 2 + 4 ;
V_2 -> V_90 = 0 ;
if ( ( V_90 > 0 ) && ( V_90 < V_2 -> V_91 ) ) {
F_9 ( L_3 , V_2 -> V_90 ) ;
V_2 -> V_90 = V_90 ;
goto V_92;
}
if ( V_2 -> V_93 )
goto V_92;
if ( V_2 -> V_67 * 2 * V_2 -> V_68 > 720 * 240 * 2 )
V_89 *= 2 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_91 ; V_88 ++ ) {
if ( V_2 -> V_94 [ V_88 ] >= V_89 ) {
V_2 -> V_90 = V_88 ;
break;
} else if ( V_2 -> V_94 [ V_88 ] >
V_2 -> V_94 [ V_2 -> V_90 ] )
V_2 -> V_90 = V_88 ;
}
V_92:
if ( V_2 -> V_93 ) {
V_2 -> V_95 = 512 ;
V_2 -> V_96 = V_97 ;
} else {
F_9 ( L_4 ,
V_89 , V_2 -> V_90 ) ;
V_2 -> V_95 =
V_2 -> V_94 [ V_2 -> V_90 ] ;
V_2 -> V_96 = V_98 ;
}
F_9 ( L_5 ,
V_2 -> V_90 , V_2 -> V_95 ) ;
V_87 = F_18 ( V_2 -> V_99 , V_2 -> V_100 , V_2 -> V_90 ) ;
if ( V_87 < 0 ) {
F_19 ( L_6 ,
V_2 -> V_90 , V_87 ) ;
return V_87 ;
}
return 0 ;
}
static inline void F_20 ( struct V_1 * V_2 ,
struct V_101 * V_81 )
{
F_21 ( L_7 , V_81 , V_81 -> V_102 ) ;
V_81 -> V_103 . V_104 . V_105 = V_2 -> V_106 ++ ;
V_81 -> V_103 . V_104 . V_107 = V_108 ;
F_22 ( & V_81 -> V_103 . V_104 . V_109 ) ;
F_23 ( & V_81 -> V_103 , V_110 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_101 * V_81 ,
unsigned char * V_111 ,
unsigned long V_112 )
{
void * V_113 , * V_114 , * V_115 ;
int V_116 , V_117 , V_118 , V_119 , V_120 ;
int V_121 = V_2 -> V_67 << 1 ;
if ( V_81 -> V_122 + V_112 > V_81 -> V_123 )
V_112 = V_81 -> V_123 - V_81 -> V_122 ;
V_115 = V_111 ;
V_120 = V_112 ;
if ( V_2 -> V_124 || V_81 -> V_102 )
V_113 = V_81 -> V_125 ;
else
V_113 = V_81 -> V_125 + V_121 ;
V_116 = V_81 -> V_122 / V_121 ;
V_117 = V_81 -> V_122 % V_121 ;
if ( V_2 -> V_124 )
V_118 = V_116 * V_121 + V_117 ;
else
V_118 = V_116 * V_121 * 2 + V_117 ;
V_114 = V_113 + V_118 ;
V_119 = V_121 - V_117 ;
V_119 = V_119 > V_120 ? V_120 : V_119 ;
if ( ( char * ) V_114 + V_119 > ( char * ) V_81 -> V_125 + V_81 -> V_123 ) {
F_21 ( L_8 ,
( ( char * ) V_114 + V_119 ) -
( ( char * ) V_81 -> V_125 + V_81 -> V_123 ) ) ;
V_120 = ( char * ) V_81 -> V_125 + V_81 -> V_123 -
( char * ) V_114 ;
V_119 = V_120 ;
}
if ( V_119 <= 0 )
return;
memcpy ( V_114 , V_115 , V_119 ) ;
V_120 -= V_119 ;
while ( V_120 > 0 ) {
if ( V_2 -> V_124 )
V_114 += V_119 ;
else
V_114 += V_119 + V_121 ;
V_115 += V_119 ;
if ( V_121 > V_120 )
V_119 = V_120 ;
else
V_119 = V_121 ;
if ( ( char * ) V_114 + V_119 > ( char * ) V_81 -> V_125 +
V_81 -> V_123 ) {
F_21 ( L_9
L_10 ,
( ( char * ) V_114 + V_119 ) -
( ( char * ) V_81 -> V_125 + V_81 -> V_123 ) ) ;
V_119 = V_120 = ( char * ) V_81 -> V_125 + V_81 -> V_123 -
( char * ) V_114 ;
}
if ( V_119 <= 0 )
break;
memcpy ( V_114 , V_115 , V_119 ) ;
V_120 -= V_119 ;
}
V_81 -> V_122 += V_112 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_101 * V_81 ,
unsigned char * V_111 ,
unsigned long V_112 )
{
unsigned int V_118 ;
if ( V_81 -> V_122 + V_112 > V_81 -> V_123 )
V_112 = V_81 -> V_123 - V_81 -> V_122 ;
V_118 = V_81 -> V_122 ;
if ( V_81 -> V_102 == 0 )
V_118 += V_2 -> V_49 * V_2 -> V_51 ;
memcpy ( V_81 -> V_125 + V_118 , V_111 , V_112 ) ;
V_81 -> V_122 += V_112 ;
}
static inline void F_26 ( struct V_1 * V_2 ,
int V_126 , int V_127 )
{
char * V_128 = L_11 ;
switch ( V_127 ) {
case - V_129 :
V_128 = L_12 ;
break;
case - V_130 :
V_128 = L_13 ;
break;
case - V_131 :
V_128 = L_14 ;
break;
case - V_132 :
V_128 = L_15 ;
break;
case - V_133 :
V_128 = L_16 ;
break;
case - V_134 :
V_128 = L_17 ;
break;
case - V_135 :
V_128 = L_18 ;
break;
case - V_136 :
V_128 = L_19 ;
break;
}
if ( V_126 < 0 ) {
F_21 ( L_20 , V_127 , V_128 ) ;
} else {
F_21 ( L_21 ,
V_126 , V_127 , V_128 ) ;
}
}
static inline struct V_101 * F_27 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
struct V_101 * V_81 ;
if ( F_28 ( & V_138 -> V_139 ) ) {
F_21 ( L_22 ) ;
return NULL ;
}
V_81 = F_29 ( V_138 -> V_139 . V_140 , struct V_101 , V_141 ) ;
F_30 ( & V_81 -> V_141 ) ;
V_81 -> V_122 = 0 ;
V_81 -> V_125 = V_81 -> V_142 ;
return V_81 ;
}
static struct V_101 *
F_31 ( struct V_1 * V_2 ,
struct V_101 * V_81 ,
struct V_137 * V_138 )
{
if ( V_2 -> V_124 || V_2 -> V_102 ) {
if ( V_81 != NULL )
F_20 ( V_2 , V_81 ) ;
V_81 = F_27 ( V_2 , V_138 ) ;
}
if ( V_81 != NULL ) {
V_81 -> V_102 = V_2 -> V_102 ;
V_81 -> V_122 = 0 ;
}
return V_81 ;
}
static inline void F_32 ( struct V_1 * V_2 ,
unsigned char * V_143 ,
unsigned int V_144 )
{
struct V_101 * V_81 = V_2 -> V_145 . V_146 ;
struct V_101 * V_147 = V_2 -> V_145 . V_147 ;
struct V_137 * V_138 = & V_2 -> V_148 ;
struct V_137 * V_149 = & V_2 -> V_150 ;
if ( V_144 >= 4 ) {
if ( V_143 [ 0 ] == 0x88 && V_143 [ 1 ] == 0x88 &&
V_143 [ 2 ] == 0x88 && V_143 [ 3 ] == 0x88 ) {
V_143 += 4 ;
V_144 -= 4 ;
} else if ( V_143 [ 0 ] == 0x33 && V_143 [ 1 ] == 0x95 ) {
V_2 -> V_151 = 0 ;
V_2 -> V_152 = 0 ;
F_21 ( L_23 ) ;
V_2 -> V_102 = ! ( V_143 [ 2 ] & 1 ) ;
V_143 += 4 ;
V_144 -= 4 ;
} else if ( V_143 [ 0 ] == 0x22 && V_143 [ 1 ] == 0x5a ) {
V_2 -> V_151 = 2 ;
F_21 ( L_24 ) ;
V_2 -> V_102 = ! ( V_143 [ 2 ] & 1 ) ;
V_143 += 4 ;
V_144 -= 4 ;
}
}
if ( V_2 -> V_151 == 0 ) {
V_147 = F_31 ( V_2 , V_147 , V_149 ) ;
V_2 -> V_145 . V_147 = V_147 ;
V_2 -> V_151 = 1 ;
}
if ( V_2 -> V_151 == 1 ) {
int V_153 = V_2 -> V_49 * V_2 -> V_51 ;
int V_154 = ( ( V_2 -> V_152 + V_144 ) > V_153 ) ?
( V_153 - V_2 -> V_152 ) : V_144 ;
if ( V_147 != NULL )
F_25 ( V_2 , V_147 , V_143 , V_154 ) ;
V_2 -> V_152 += V_154 ;
if ( V_154 < V_144 ) {
V_2 -> V_151 = 2 ;
V_143 += V_154 ;
V_144 -= V_154 ;
}
}
if ( V_2 -> V_151 == 2 ) {
V_81 = F_31 ( V_2 , V_81 , V_138 ) ;
V_2 -> V_145 . V_146 = V_81 ;
V_2 -> V_151 = 3 ;
}
if ( V_2 -> V_151 == 3 && V_81 != NULL && V_144 > 0 )
F_24 ( V_2 , V_81 , V_143 , V_144 ) ;
}
static inline void F_33 ( struct V_1 * V_2 ,
unsigned char * V_143 ,
unsigned int V_144 )
{
struct V_101 * V_81 = V_2 -> V_145 . V_146 ;
struct V_137 * V_155 = & V_2 -> V_148 ;
bool V_156 = 0 ;
if ( V_144 >= 2 ) {
if ( ( V_143 [ 0 ] == V_157 ) &&
( ( V_143 [ 1 ] & ~ V_158 ) == 0x00 ) ) {
V_2 -> V_102 = ! ( V_143 [ 1 ] &
V_159 ) ;
V_156 = V_143 [ 1 ] &
V_160 ;
V_143 += 2 ;
V_144 -= 2 ;
}
if ( V_2 -> V_93 && V_156 ) {
V_81 = F_31 ( V_2 , V_81 , V_155 ) ;
V_2 -> V_145 . V_146 = V_81 ;
}
}
if ( V_81 != NULL && V_144 > 0 )
F_24 ( V_2 , V_81 , V_143 , V_144 ) ;
if ( ! V_2 -> V_93 && V_156 ) {
V_81 = F_31 ( V_2 , V_81 , V_155 ) ;
V_2 -> V_145 . V_146 = V_81 ;
}
}
static inline int F_34 ( struct V_1 * V_2 , struct V_161 * V_161 )
{
int V_162 , V_163 , V_88 ;
unsigned char * V_164 ;
unsigned int V_165 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_166 )
return 0 ;
if ( V_161 -> V_127 < 0 )
F_26 ( V_2 , - 1 , V_161 -> V_127 ) ;
V_162 = F_35 ( V_161 -> V_167 ) ;
if ( V_162 )
V_163 = 1 ;
else
V_163 = V_161 -> V_168 ;
for ( V_88 = 0 ; V_88 < V_163 ; V_88 ++ ) {
if ( V_162 ) {
V_165 = V_161 -> V_169 ;
V_164 = V_161 -> V_170 ;
} else {
if ( V_161 -> V_171 [ V_88 ] . V_127 < 0 ) {
F_26 ( V_2 , V_88 ,
V_161 -> V_171 [ V_88 ] . V_127 ) ;
if ( V_161 -> V_171 [ V_88 ] . V_127 != - V_134 )
continue;
}
V_165 = V_161 -> V_171 [ V_88 ] . V_169 ;
if ( V_165 > V_2 -> V_95 ) {
F_21 ( L_25 ) ;
continue;
}
V_164 = V_161 -> V_170 +
V_161 -> V_171 [ V_88 ] . V_118 ;
}
if ( V_165 == 0 ) {
continue;
}
if ( V_2 -> V_41 )
F_33 ( V_2 ,
V_164 , V_165 ) ;
else
F_32 ( V_2 ,
V_164 , V_165 ) ;
}
return 1 ;
}
static int F_36 ( enum V_172 V_173 )
{
switch ( V_173 ) {
case V_174 :
return V_175 ;
case V_176 :
return V_177 ;
default:
F_37 () ;
return 0 ;
}
}
static int F_38 ( struct V_1 * V_2 , enum V_172 V_173 )
{
int V_178 = F_36 ( V_173 ) ;
if ( V_2 -> V_179 & V_178 ) {
return - V_180 ;
}
V_2 -> V_179 |= V_178 ;
F_9 ( L_26 , V_178 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , enum V_172 V_173 )
{
int V_178 = F_36 ( V_173 ) ;
V_2 -> V_179 &= ~ V_178 ;
F_9 ( L_27 , V_178 ) ;
}
static int F_40 ( struct V_181 * V_182 , const struct V_183 * V_37 ,
unsigned int * V_184 , unsigned int * V_185 ,
unsigned int V_186 [] , void * V_187 [] )
{
struct V_1 * V_2 = F_41 ( V_182 ) ;
unsigned long V_188 ;
if ( V_37 )
V_188 = V_37 -> V_37 . V_189 . V_190 ;
else
V_188 = ( V_2 -> V_67 * V_2 -> V_68 * V_2 -> V_39 -> V_191 + 7 ) >> 3 ;
if ( V_188 == 0 )
return - V_192 ;
if ( 0 == * V_184 )
* V_184 = 32 ;
* V_185 = 1 ;
V_186 [ 0 ] = V_188 ;
return 0 ;
}
static int
F_42 ( struct V_193 * V_103 )
{
struct V_1 * V_2 = F_41 ( V_103 -> V_181 ) ;
struct V_101 * V_81 = F_43 ( V_103 , struct V_101 , V_103 ) ;
unsigned long V_188 ;
F_9 ( L_28 , V_194 , V_103 -> V_104 . V_107 ) ;
V_188 = ( V_2 -> V_67 * V_2 -> V_68 * V_2 -> V_39 -> V_191 + 7 ) >> 3 ;
if ( F_44 ( V_103 , 0 ) < V_188 ) {
F_9 ( L_29 ,
V_194 , F_44 ( V_103 , 0 ) , V_188 ) ;
return - V_192 ;
}
F_45 ( & V_81 -> V_103 , 0 , V_188 ) ;
return 0 ;
}
int F_46 ( struct V_181 * V_182 , unsigned int V_195 )
{
struct V_1 * V_2 = F_41 ( V_182 ) ;
struct V_196 V_197 ;
int V_198 = 0 ;
F_9 ( L_30 , V_194 ) ;
V_198 = F_38 ( V_2 , V_182 -> type ) ;
if ( V_198 )
return V_198 ;
if ( V_2 -> V_199 == 0 ) {
F_17 ( V_2 ) ;
F_2 ( V_2 ) ;
V_2 -> V_151 = - 1 ;
V_198 = F_47 ( V_2 , V_200 ,
V_2 -> V_93 ,
V_201 ,
V_2 -> V_95 ,
V_2 -> V_96 ,
F_34 ) ;
if ( V_198 < 0 )
return V_198 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_197 . V_202 = V_2 -> V_203 ;
if ( V_182 -> V_204 && V_182 -> V_204 -> V_205 -> V_206 == V_207 )
V_197 . type = V_208 ;
else
V_197 . type = V_209 ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_211 , & V_197 ) ;
}
V_2 -> V_199 ++ ;
return V_198 ;
}
static int F_48 ( struct V_181 * V_182 )
{
struct V_1 * V_2 = F_41 ( V_182 ) ;
struct V_137 * V_148 = & V_2 -> V_148 ;
unsigned long V_212 = 0 ;
F_9 ( L_30 , V_194 ) ;
F_39 ( V_2 , V_182 -> type ) ;
if ( V_2 -> V_199 -- == 1 ) {
F_49 ( V_2 , V_200 ) ;
}
F_50 ( & V_2 -> V_213 , V_212 ) ;
while ( ! F_28 ( & V_148 -> V_139 ) ) {
struct V_101 * V_81 ;
V_81 = F_29 ( V_148 -> V_139 . V_140 , struct V_101 , V_141 ) ;
F_30 ( & V_81 -> V_141 ) ;
F_23 ( & V_81 -> V_103 , V_214 ) ;
}
V_2 -> V_145 . V_146 = NULL ;
F_51 ( & V_2 -> V_213 , V_212 ) ;
return 0 ;
}
int F_52 ( struct V_181 * V_182 )
{
struct V_1 * V_2 = F_41 ( V_182 ) ;
struct V_137 * V_150 = & V_2 -> V_150 ;
unsigned long V_212 = 0 ;
F_9 ( L_30 , V_194 ) ;
F_39 ( V_2 , V_182 -> type ) ;
if ( V_2 -> V_199 -- == 1 ) {
F_49 ( V_2 , V_200 ) ;
}
F_50 ( & V_2 -> V_213 , V_212 ) ;
while ( ! F_28 ( & V_150 -> V_139 ) ) {
struct V_101 * V_81 ;
V_81 = F_29 ( V_150 -> V_139 . V_140 , struct V_101 , V_141 ) ;
F_30 ( & V_81 -> V_141 ) ;
F_23 ( & V_81 -> V_103 , V_214 ) ;
}
V_2 -> V_145 . V_147 = NULL ;
F_51 ( & V_2 -> V_213 , V_212 ) ;
return 0 ;
}
static void
F_53 ( struct V_193 * V_103 )
{
struct V_1 * V_2 = F_41 ( V_103 -> V_181 ) ;
struct V_101 * V_81 = F_43 ( V_103 , struct V_101 , V_103 ) ;
struct V_137 * V_148 = & V_2 -> V_148 ;
unsigned long V_212 = 0 ;
F_9 ( L_30 , V_194 ) ;
V_81 -> V_142 = F_54 ( V_103 , 0 ) ;
V_81 -> V_123 = F_44 ( V_103 , 0 ) ;
F_50 ( & V_2 -> V_213 , V_212 ) ;
F_55 ( & V_81 -> V_141 , & V_148 -> V_139 ) ;
F_51 ( & V_2 -> V_213 , V_212 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_198 ;
struct V_181 * V_215 ;
V_215 = & V_2 -> V_216 ;
V_215 -> type = V_174 ;
V_215 -> V_217 = V_218 | V_219 | V_220 | V_221 ;
V_215 -> V_222 = V_223 ;
V_215 -> V_224 = V_2 ;
V_215 -> V_225 = sizeof( struct V_101 ) ;
V_215 -> V_226 = & V_227 ;
V_215 -> V_228 = & V_229 ;
V_198 = F_57 ( V_215 ) ;
if ( V_198 < 0 )
return V_198 ;
V_215 = & V_2 -> V_230 ;
V_215 -> type = V_176 ;
V_215 -> V_217 = V_218 | V_219 | V_220 ;
V_215 -> V_222 = V_223 ;
V_215 -> V_224 = V_2 ;
V_215 -> V_225 = sizeof( struct V_101 ) ;
V_215 -> V_226 = & V_231 ;
V_215 -> V_228 = & V_229 ;
V_198 = F_57 ( V_215 ) ;
if ( V_198 < 0 )
return V_198 ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 , int V_232 )
{
V_2 -> V_14 = V_232 ;
V_2 -> V_233 = F_4 ( V_232 ) -> V_234 ;
V_2 -> V_235 = F_4 ( V_232 ) -> V_236 ;
if ( ! V_2 -> V_235 )
V_2 -> V_235 = V_237 ;
F_3 ( & V_2 -> V_9 , 0 , V_12 , V_13 ,
F_4 ( V_232 ) -> V_15 , 0 , 0 ) ;
if ( V_2 -> V_4 . V_238 ) {
if ( V_2 -> V_239 ) {
F_3 ( & V_2 -> V_9 , 0 , V_240 ,
V_241 , V_2 -> V_239 ) ;
}
F_3 ( & V_2 -> V_9 , 0 , V_240 , V_13 ,
V_2 -> V_233 , F_59 ( V_242 ) , 0 ) ;
}
if ( V_2 -> V_4 . V_243 != V_244 ) {
F_3 ( & V_2 -> V_9 , 0 , V_240 , V_13 ,
V_2 -> V_233 , V_2 -> V_235 , 0 ) ;
}
F_60 ( V_2 ) ;
}
static void F_61 ( struct V_245 * V_246 , void * V_247 )
{
struct V_1 * V_2 = V_247 ;
switch ( V_246 -> V_248 ) {
case V_249 :
V_2 -> V_250 = V_246 -> V_251 ;
F_60 ( V_2 ) ;
break;
case V_252 :
V_2 -> V_253 = V_246 -> V_251 ;
F_60 ( V_2 ) ;
break;
}
}
static int F_62 ( struct V_245 * V_246 )
{
struct V_1 * V_2 = F_43 ( V_246 -> V_254 , struct V_1 , V_255 ) ;
int V_36 = - V_192 ;
switch ( V_246 -> V_248 ) {
case V_249 :
V_2 -> V_250 = V_246 -> V_251 ;
V_36 = F_60 ( V_2 ) ;
break;
case V_252 :
V_2 -> V_253 = V_246 -> V_251 ;
V_36 = F_60 ( V_2 ) ;
break;
case V_256 :
V_36 = F_6 ( V_2 , V_17 , V_246 -> V_251 ) ;
break;
case V_257 :
V_36 = F_6 ( V_2 , V_19 , V_246 -> V_251 ) ;
break;
case V_258 :
V_36 = F_6 ( V_2 , V_21 , V_246 -> V_251 ) ;
break;
case V_259 :
V_36 = F_6 ( V_2 , V_23 , V_246 -> V_251 ) ;
break;
case V_260 :
V_36 = F_6 ( V_2 , V_25 , V_246 -> V_251 ) ;
break;
case V_261 :
V_36 = F_6 ( V_2 , V_27 , V_246 -> V_251 ) ;
break;
}
return ( V_36 < 0 ) ? V_36 : 0 ;
}
static void F_63 ( struct V_1 * V_2 ,
unsigned int V_67 , unsigned int V_68 ,
unsigned int * V_85 , unsigned int * V_86 )
{
unsigned int V_262 = F_15 ( V_2 ) ;
unsigned int V_263 = F_16 ( V_2 ) ;
* V_85 = ( ( ( unsigned long ) V_262 ) << 12 ) / V_67 - 4096L ;
if ( * V_85 > V_264 )
* V_85 = V_264 ;
* V_86 = ( ( ( unsigned long ) V_263 ) << 12 ) / V_68 - 4096L ;
if ( * V_86 > V_264 )
* V_86 = V_264 ;
}
static void F_64 ( struct V_1 * V_2 ,
unsigned int V_85 , unsigned int V_86 ,
unsigned int * V_67 , unsigned int * V_68 )
{
unsigned int V_262 = F_15 ( V_2 ) ;
unsigned int V_263 = F_16 ( V_2 ) ;
* V_67 = ( ( ( unsigned long ) V_262 ) << 12 ) / ( V_85 + 4096L ) ;
* V_68 = ( ( ( unsigned long ) V_263 ) << 12 ) / ( V_86 + 4096L ) ;
}
static int F_65 ( struct V_265 * V_265 , void * V_247 ,
struct V_183 * V_197 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
V_197 -> V_37 . V_189 . V_67 = V_2 -> V_67 ;
V_197 -> V_37 . V_189 . V_68 = V_2 -> V_68 ;
V_197 -> V_37 . V_189 . V_268 = V_2 -> V_39 -> V_269 ;
V_197 -> V_37 . V_189 . V_121 = ( V_2 -> V_67 * V_2 -> V_39 -> V_191 + 7 ) >> 3 ;
V_197 -> V_37 . V_189 . V_190 = V_197 -> V_37 . V_189 . V_121 * V_2 -> V_68 ;
V_197 -> V_37 . V_189 . V_270 = V_271 ;
if ( V_2 -> V_124 )
V_197 -> V_37 . V_189 . V_107 = V_272 ;
else
V_197 -> V_37 . V_189 . V_107 = V_2 -> V_273 ?
V_108 : V_274 ;
return 0 ;
}
static struct V_275 * F_66 ( unsigned int V_269 )
{
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < F_67 ( V_39 ) ; V_88 ++ )
if ( V_39 [ V_88 ] . V_269 == V_269 )
return & V_39 [ V_88 ] ;
return NULL ;
}
static int F_68 ( struct V_265 * V_265 , void * V_247 ,
struct V_183 * V_197 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
unsigned int V_67 = V_197 -> V_37 . V_189 . V_67 ;
unsigned int V_68 = V_197 -> V_37 . V_189 . V_68 ;
unsigned int V_262 = F_15 ( V_2 ) ;
unsigned int V_263 = F_16 ( V_2 ) ;
unsigned int V_85 , V_86 ;
struct V_275 * V_37 ;
V_37 = F_66 ( V_197 -> V_37 . V_189 . V_268 ) ;
if ( ! V_37 ) {
F_9 ( L_31 ,
V_197 -> V_37 . V_189 . V_268 ) ;
return - V_192 ;
}
if ( V_2 -> V_4 . V_80 ) {
V_68 = V_68 > ( 3 * V_263 / 4 ) ? V_263 : V_263 / 2 ;
V_67 = V_67 > ( 3 * V_262 / 4 ) ? V_262 : V_262 / 2 ;
if ( V_67 == V_262 && V_68 == V_263 )
V_67 /= 2 ;
} else {
F_69 ( & V_67 , 48 , V_262 , 1 , & V_68 , 32 , V_263 ,
1 , 0 ) ;
}
F_63 ( V_2 , V_67 , V_68 , & V_85 , & V_86 ) ;
F_64 ( V_2 , V_85 , V_86 , & V_67 , & V_68 ) ;
V_197 -> V_37 . V_189 . V_67 = V_67 ;
V_197 -> V_37 . V_189 . V_68 = V_68 ;
V_197 -> V_37 . V_189 . V_268 = V_37 -> V_269 ;
V_197 -> V_37 . V_189 . V_121 = ( V_67 * V_37 -> V_191 + 7 ) >> 3 ;
V_197 -> V_37 . V_189 . V_190 = V_197 -> V_37 . V_189 . V_121 * V_68 ;
V_197 -> V_37 . V_189 . V_270 = V_271 ;
if ( V_2 -> V_124 )
V_197 -> V_37 . V_189 . V_107 = V_272 ;
else
V_197 -> V_37 . V_189 . V_107 = V_2 -> V_273 ?
V_108 : V_274 ;
V_197 -> V_37 . V_189 . V_247 = 0 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , unsigned int V_269 ,
unsigned V_67 , unsigned V_68 )
{
struct V_275 * V_37 ;
V_37 = F_66 ( V_269 ) ;
if ( ! V_37 )
return - V_192 ;
V_2 -> V_39 = V_37 ;
V_2 -> V_67 = V_67 ;
V_2 -> V_68 = V_68 ;
F_63 ( V_2 , V_2 -> V_67 , V_2 -> V_68 , & V_2 -> V_85 , & V_2 -> V_86 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_71 ( struct V_265 * V_265 , void * V_247 ,
struct V_183 * V_197 )
{
struct V_1 * V_2 = F_72 ( V_265 ) ;
if ( V_2 -> V_199 > 0 )
return - V_180 ;
F_68 ( V_265 , V_247 , V_197 ) ;
return F_70 ( V_2 , V_197 -> V_37 . V_189 . V_268 ,
V_197 -> V_37 . V_189 . V_67 , V_197 -> V_37 . V_189 . V_68 ) ;
}
static int F_73 ( struct V_265 * V_265 , void * V_247 , T_3 * V_52 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
* V_52 = V_2 -> V_52 ;
return 0 ;
}
static int F_74 ( struct V_265 * V_265 , void * V_247 , T_3 * V_52 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
F_3 ( & V_2 -> V_9 , 0 , V_12 , V_276 , V_52 ) ;
return 0 ;
}
static int F_75 ( struct V_265 * V_265 , void * V_247 , T_3 V_52 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
struct V_183 V_197 ;
if ( V_52 == V_2 -> V_52 )
return 0 ;
if ( V_2 -> V_199 > 0 )
return - V_180 ;
V_2 -> V_52 = V_52 ;
V_197 . V_37 . V_189 . V_67 = 720 ;
V_197 . V_37 . V_189 . V_68 = ( V_52 & V_53 ) ? 480 : 576 ;
F_68 ( V_265 , V_247 , & V_197 ) ;
V_2 -> V_67 = V_197 . V_37 . V_189 . V_67 ;
V_2 -> V_68 = V_197 . V_37 . V_189 . V_68 ;
F_63 ( V_2 , V_2 -> V_67 , V_2 -> V_68 , & V_2 -> V_85 , & V_2 -> V_86 ) ;
F_14 ( V_2 ) ;
F_3 ( & V_2 -> V_9 , 0 , V_10 , V_277 , V_2 -> V_52 ) ;
return 0 ;
}
static int F_76 ( struct V_265 * V_265 , void * V_247 ,
struct V_278 * V_279 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
int V_198 = 0 ;
V_279 -> V_280 . V_281 . V_282 = V_283 ;
if ( V_2 -> V_4 . V_5 )
V_198 = F_77 ( & V_2 -> V_9 , 0 ,
V_12 , V_284 , V_279 ) ;
else
F_78 ( V_2 -> V_52 ,
& V_279 -> V_280 . V_281 . V_285 ) ;
return V_198 ;
}
static int F_79 ( struct V_265 * V_265 , void * V_247 ,
struct V_278 * V_279 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
V_279 -> V_280 . V_281 . V_282 = V_283 ;
return F_77 ( & V_2 -> V_9 , 0 , V_12 , V_286 , V_279 ) ;
}
static int F_80 ( struct V_265 * V_265 , void * V_247 ,
struct V_287 * V_88 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
unsigned int V_288 ;
V_288 = V_88 -> V_232 ;
if ( V_288 >= V_289 )
return - V_192 ;
if ( 0 == F_4 ( V_288 ) -> type )
return - V_192 ;
V_88 -> V_232 = V_288 ;
V_88 -> type = V_290 ;
strcpy ( V_88 -> V_291 , V_292 [ F_4 ( V_288 ) -> type ] ) ;
if ( ( V_293 == F_4 ( V_288 ) -> type ) ||
( V_294 == F_4 ( V_288 ) -> type ) )
V_88 -> type = V_295 ;
V_88 -> V_296 = V_2 -> V_205 -> V_297 ;
if ( V_2 -> V_4 . V_5 )
V_88 -> V_298 = 0 ;
return 0 ;
}
static int F_81 ( struct V_265 * V_265 , void * V_247 , unsigned int * V_88 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
* V_88 = V_2 -> V_14 ;
return 0 ;
}
static int F_82 ( struct V_265 * V_265 , void * V_247 , unsigned int V_88 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
if ( V_88 >= V_289 )
return - V_192 ;
if ( 0 == F_4 ( V_88 ) -> type )
return - V_192 ;
F_58 ( V_2 , V_88 ) ;
return 0 ;
}
static int F_83 ( struct V_265 * V_265 , void * V_247 , struct V_299 * V_300 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
switch ( V_300 -> V_232 ) {
case V_301 :
strcpy ( V_300 -> V_291 , L_32 ) ;
break;
case V_302 :
strcpy ( V_300 -> V_291 , L_33 ) ;
break;
case V_303 :
strcpy ( V_300 -> V_291 , L_34 ) ;
break;
case V_304 :
strcpy ( V_300 -> V_291 , L_35 ) ;
break;
case V_305 :
strcpy ( V_300 -> V_291 , L_36 ) ;
break;
case V_306 :
strcpy ( V_300 -> V_291 , L_37 ) ;
break;
case V_307 :
strcpy ( V_300 -> V_291 , L_38 ) ;
break;
case V_308 :
strcpy ( V_300 -> V_291 , L_39 ) ;
break;
default:
return - V_192 ;
}
V_300 -> V_232 = V_2 -> V_233 ;
V_300 -> V_309 = V_310 ;
return 0 ;
}
static int F_84 ( struct V_265 * V_265 , void * V_247 , const struct V_299 * V_300 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
if ( V_300 -> V_232 >= V_289 )
return - V_192 ;
if ( 0 == F_4 ( V_300 -> V_232 ) -> type )
return - V_192 ;
V_2 -> V_233 = F_4 ( V_300 -> V_232 ) -> V_234 ;
V_2 -> V_235 = F_4 ( V_300 -> V_232 ) -> V_236 ;
if ( ! V_2 -> V_235 )
V_2 -> V_235 = V_237 ;
return 0 ;
}
static int F_85 ( struct V_265 * V_265 , void * V_247 ,
struct V_311 * V_312 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
if ( 0 != V_312 -> V_232 )
return - V_192 ;
strcpy ( V_312 -> V_291 , L_40 ) ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_313 , V_312 ) ;
return 0 ;
}
static int F_86 ( struct V_265 * V_265 , void * V_247 ,
const struct V_311 * V_312 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
if ( 0 != V_312 -> V_232 )
return - V_192 ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_314 , V_312 ) ;
return 0 ;
}
static int F_87 ( struct V_265 * V_265 , void * V_247 ,
struct V_196 * V_197 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
if ( 0 != V_197 -> V_210 )
return - V_192 ;
V_197 -> V_202 = V_2 -> V_203 ;
return 0 ;
}
static int F_88 ( struct V_265 * V_265 , void * V_247 ,
const struct V_196 * V_197 )
{
struct V_196 V_315 = * V_197 ;
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
if ( 0 != V_197 -> V_210 )
return - V_192 ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_211 , V_197 ) ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_316 , & V_315 ) ;
V_2 -> V_203 = V_315 . V_202 ;
return 0 ;
}
static int F_89 ( struct V_265 * V_265 , void * V_247 ,
struct V_317 * V_318 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
if ( V_318 -> V_319 . V_320 > 1 )
return - V_192 ;
if ( V_318 -> V_319 . V_320 == 1 )
F_90 ( V_318 -> V_291 , L_41 , sizeof( V_318 -> V_291 ) ) ;
else
F_90 ( V_318 -> V_291 , V_2 -> V_9 . V_291 , sizeof( V_318 -> V_291 ) ) ;
return 0 ;
}
static int F_91 ( int V_40 )
{
switch ( V_40 ) {
case V_321 :
case V_82 :
case V_83 :
return 2 ;
default:
return 1 ;
}
}
static int F_92 ( struct V_265 * V_265 , void * V_247 ,
struct V_322 * V_40 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
int V_36 ;
if ( V_40 -> V_319 . V_320 > 1 )
return - V_192 ;
if ( V_40 -> V_319 . V_320 ) {
V_36 = F_93 ( V_2 , V_40 -> V_40 ) ;
if ( V_36 < 0 )
return V_36 ;
V_40 -> V_251 = V_36 ;
V_40 -> V_188 = 1 ;
return 0 ;
}
V_40 -> V_188 = F_91 ( V_40 -> V_40 ) ;
if ( V_40 -> V_188 == 1 ) {
V_36 = F_94 ( V_2 , V_40 -> V_40 ) ;
if ( V_36 < 0 )
return V_36 ;
V_40 -> V_251 = V_36 ;
} else {
T_4 V_251 = 0 ;
V_36 = V_2 -> V_323 ( V_2 , V_324 ,
V_40 -> V_40 , ( char * ) & V_251 , 2 ) ;
if ( V_36 < 0 )
return V_36 ;
V_40 -> V_251 = F_95 ( V_251 ) ;
}
return 0 ;
}
static int F_96 ( struct V_265 * V_265 , void * V_247 ,
const struct V_322 * V_40 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
T_4 V_81 ;
if ( V_40 -> V_319 . V_320 > 1 )
return - V_192 ;
if ( V_40 -> V_319 . V_320 )
return F_97 ( V_2 , V_40 -> V_40 , V_40 -> V_251 ) ;
V_81 = F_98 ( V_40 -> V_251 ) ;
return F_10 ( V_2 , V_40 -> V_40 , ( char * ) & V_81 ,
F_91 ( V_40 -> V_40 ) ) ;
}
static int F_99 ( struct V_265 * V_265 , void * V_247 ,
struct V_325 * V_326 )
{
struct V_327 * V_205 = F_100 ( V_265 ) ;
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
F_90 ( V_326 -> V_328 , L_42 , sizeof( V_326 -> V_328 ) ) ;
F_90 ( V_326 -> V_329 , V_330 [ V_2 -> V_331 ] . V_291 , sizeof( V_326 -> V_329 ) ) ;
F_101 ( V_2 -> V_99 , V_326 -> V_332 , sizeof( V_326 -> V_332 ) ) ;
if ( V_205 -> V_206 == V_333 )
V_326 -> V_334 = V_335 |
V_336 | V_337 ;
else if ( V_205 -> V_206 == V_207 )
V_326 -> V_334 = V_338 ;
else
V_326 -> V_334 = V_335 | V_339 ;
if ( V_2 -> V_340 . V_341 )
V_326 -> V_334 |= V_342 ;
if ( V_2 -> V_343 != V_344 )
V_326 -> V_334 |= V_345 ;
V_326 -> V_298 = V_326 -> V_334 | V_346 |
V_335 | V_336 | V_337 ;
if ( V_2 -> V_347 )
V_326 -> V_298 |= V_339 ;
if ( V_2 -> V_348 )
V_326 -> V_298 |= V_338 ;
return 0 ;
}
static int F_102 ( struct V_265 * V_265 , void * V_247 ,
struct V_349 * V_197 )
{
if ( F_103 ( V_197 -> V_232 >= F_67 ( V_39 ) ) )
return - V_192 ;
F_90 ( V_197 -> V_350 , V_39 [ V_197 -> V_232 ] . V_291 , sizeof( V_197 -> V_350 ) ) ;
V_197 -> V_268 = V_39 [ V_197 -> V_232 ] . V_269 ;
return 0 ;
}
static int F_104 ( struct V_265 * V_265 , void * V_247 ,
struct V_351 * V_352 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
struct V_275 * V_37 ;
unsigned int V_262 = F_15 ( V_2 ) ;
unsigned int V_263 = F_16 ( V_2 ) ;
V_37 = F_66 ( V_352 -> V_353 ) ;
if ( ! V_37 ) {
F_9 ( L_31 ,
V_352 -> V_353 ) ;
return - V_192 ;
}
if ( V_2 -> V_4 . V_80 ) {
if ( V_352 -> V_232 > 1 )
return - V_192 ;
V_352 -> type = V_354 ;
V_352 -> V_355 . V_67 = V_262 / ( 1 + V_352 -> V_232 ) ;
V_352 -> V_355 . V_68 = V_263 / ( 1 + V_352 -> V_232 ) ;
return 0 ;
}
if ( V_352 -> V_232 != 0 )
return - V_192 ;
V_352 -> type = V_356 ;
F_64 ( V_2 , V_264 , V_264 ,
& V_352 -> V_357 . V_358 , & V_352 -> V_357 . V_359 ) ;
if ( V_352 -> V_357 . V_358 < 48 )
V_352 -> V_357 . V_358 = 48 ;
if ( V_352 -> V_357 . V_359 < 38 )
V_352 -> V_357 . V_359 = 38 ;
V_352 -> V_357 . V_360 = V_262 ;
V_352 -> V_357 . V_361 = V_263 ;
V_352 -> V_357 . V_362 = 1 ;
V_352 -> V_357 . V_363 = 1 ;
return 0 ;
}
static int F_105 ( struct V_265 * V_265 , void * V_247 ,
struct V_183 * V_39 )
{
struct V_266 * V_267 = V_247 ;
struct V_1 * V_2 = V_267 -> V_2 ;
V_39 -> V_37 . V_364 . V_365 = V_2 -> V_49 ;
V_39 -> V_37 . V_364 . V_366 = V_367 ;
V_39 -> V_37 . V_364 . V_118 = 0 ;
V_39 -> V_37 . V_364 . V_212 = 0 ;
V_39 -> V_37 . V_364 . V_368 = 6750000 * 4 / 2 ;
V_39 -> V_37 . V_364 . V_195 [ 0 ] = V_2 -> V_51 ;
V_39 -> V_37 . V_364 . V_195 [ 1 ] = V_2 -> V_51 ;
memset ( V_39 -> V_37 . V_364 . V_369 , 0 , sizeof( V_39 -> V_37 . V_364 . V_369 ) ) ;
if ( V_2 -> V_52 & V_53 ) {
V_39 -> V_37 . V_364 . V_370 [ 0 ] = 10 ;
V_39 -> V_37 . V_364 . V_370 [ 1 ] = 273 ;
} else if ( V_2 -> V_52 & V_55 ) {
V_39 -> V_37 . V_364 . V_370 [ 0 ] = 6 ;
V_39 -> V_37 . V_364 . V_370 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_106 ( struct V_265 * V_265 , void * V_247 ,
struct V_311 * V_312 )
{
struct V_1 * V_2 = ( (struct V_266 * ) V_247 ) -> V_2 ;
if ( F_103 ( V_312 -> V_232 > 0 ) )
return - V_192 ;
strcpy ( V_312 -> V_291 , L_43 ) ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_313 , V_312 ) ;
return 0 ;
}
static int F_107 ( struct V_265 * V_265 , void * V_247 ,
const struct V_311 * V_312 )
{
struct V_1 * V_2 = ( (struct V_266 * ) V_247 ) -> V_2 ;
if ( 0 != V_312 -> V_232 )
return - V_192 ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_314 , V_312 ) ;
return 0 ;
}
static int F_108 ( struct V_265 * V_371 )
{
struct V_327 * V_205 = F_100 ( V_371 ) ;
struct V_1 * V_2 = F_72 ( V_371 ) ;
enum V_172 V_372 = 0 ;
struct V_266 * V_267 ;
switch ( V_205 -> V_206 ) {
case V_333 :
V_372 = V_174 ;
break;
case V_373 :
V_372 = V_176 ;
break;
case V_207 :
break;
default:
return - V_192 ;
}
F_9 ( L_44 ,
F_109 ( V_205 ) , V_374 [ V_372 ] ,
V_2 -> V_375 ) ;
if ( F_110 ( & V_2 -> V_376 ) )
return - V_377 ;
V_267 = F_111 ( sizeof( struct V_266 ) , V_378 ) ;
if ( ! V_267 ) {
F_19 ( L_45 ) ;
F_112 ( & V_2 -> V_376 ) ;
return - V_379 ;
}
F_113 ( & V_267 -> V_267 , V_205 ) ;
V_267 -> V_2 = V_2 ;
V_267 -> type = V_372 ;
V_371 -> V_380 = V_267 ;
if ( V_2 -> V_375 == 0 ) {
F_114 ( V_2 , V_200 ) ;
if ( V_205 -> V_206 != V_207 )
F_14 ( V_2 ) ;
F_2 ( V_2 ) ;
}
if ( V_205 -> V_206 == V_207 ) {
F_9 ( L_46 ) ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_381 ) ;
}
V_2 -> V_375 ++ ;
F_112 ( & V_2 -> V_376 ) ;
F_115 ( & V_267 -> V_267 ) ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 )
{
if ( V_2 -> V_382 ) {
return 0 ;
}
if ( ! V_2 -> V_383 ) {
return 0 ;
}
F_117 ( L_47 ) ;
F_118 ( & V_2 -> V_376 ) ;
F_119 ( & V_2 -> V_9 ) ;
F_49 ( V_2 , V_200 ) ;
if ( V_2 -> V_348 ) {
F_117 ( L_48 ,
F_109 ( V_2 -> V_348 ) ) ;
F_120 ( V_2 -> V_348 ) ;
}
if ( V_2 -> V_347 ) {
F_117 ( L_48 ,
F_109 ( V_2 -> V_347 ) ) ;
F_120 ( V_2 -> V_347 ) ;
}
if ( V_2 -> V_205 ) {
F_117 ( L_48 ,
F_109 ( V_2 -> V_205 ) ) ;
F_120 ( V_2 -> V_205 ) ;
}
if ( V_2 -> V_384 ) {
F_121 ( V_2 -> V_384 ) ;
V_2 -> V_384 = NULL ;
}
F_122 ( & V_2 -> V_255 ) ;
F_123 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_375 )
F_124 ( L_49 ) ;
F_112 ( & V_2 -> V_376 ) ;
return 0 ;
}
static int F_125 ( struct V_265 * V_371 )
{
struct V_266 * V_267 = V_371 -> V_380 ;
struct V_1 * V_2 = V_267 -> V_2 ;
int V_87 ;
F_9 ( L_50 , V_2 -> V_375 ) ;
F_126 ( V_371 ) ;
F_118 ( & V_2 -> V_376 ) ;
if ( V_2 -> V_375 == 1 ) {
if ( V_2 -> V_166 ) {
F_127 ( V_2 -> V_94 ) ;
goto exit;
}
F_3 ( & V_2 -> V_9 , 0 , V_10 , V_385 , 0 ) ;
F_114 ( V_2 , V_386 ) ;
V_2 -> V_90 = 0 ;
F_9 ( L_51 ) ;
V_87 = F_18 ( V_2 -> V_99 , 0 , 0 ) ;
if ( V_87 < 0 ) {
F_19 ( L_52
L_53 , V_87 ) ;
}
}
exit:
V_2 -> V_375 -- ;
F_112 ( & V_2 -> V_376 ) ;
return 0 ;
}
static void F_128 ( struct V_327 * V_205 )
{
struct V_1 * V_2 = F_129 ( V_205 ) ;
F_130 ( V_205 ) ;
if ( V_205 == V_2 -> V_205 )
V_2 -> V_205 = NULL ;
else if ( V_205 == V_2 -> V_347 )
V_2 -> V_347 = NULL ;
else if ( V_205 == V_2 -> V_348 )
V_2 -> V_348 = NULL ;
}
static struct V_327 * F_131 ( struct V_1 * V_2 ,
const struct V_327 * V_387 ,
const char * V_388 )
{
struct V_327 * V_389 ;
V_389 = F_132 () ;
if ( NULL == V_389 )
return NULL ;
* V_389 = * V_387 ;
V_389 -> V_9 = & V_2 -> V_9 ;
V_389 -> V_390 = V_391 ;
V_389 -> V_376 = & V_2 -> V_376 ;
F_133 ( V_392 , & V_389 -> V_212 ) ;
if ( V_2 -> V_4 . V_5 )
V_389 -> V_297 = 0 ;
snprintf ( V_389 -> V_291 , sizeof( V_389 -> V_291 ) , L_54 ,
V_2 -> V_291 , V_388 ) ;
F_134 ( V_389 , V_2 ) ;
return V_389 ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_393 V_394 ;
struct V_196 V_197 ;
if ( V_2 -> V_343 == V_344 )
return;
memset ( & V_394 , 0 , sizeof( V_394 ) ) ;
V_394 . V_395 = V_396 | V_397 ;
V_394 . V_398 = V_399 ;
if ( V_2 -> V_4 . V_400 . type ) {
V_394 . type = V_2 -> V_4 . V_400 . type ;
V_394 . V_320 = V_2 -> V_4 . V_401 ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_402 , & V_394 ) ;
}
if ( ( V_2 -> V_343 != V_344 ) && ( V_2 -> V_343 ) ) {
V_394 . type = V_2 -> V_343 ;
V_394 . V_320 = V_2 -> V_403 ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_402 , & V_394 ) ;
}
if ( V_2 -> V_404 ) {
struct V_405 V_406 ;
V_406 . V_210 = V_407 ;
V_406 . V_247 = & V_2 -> V_404 ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_408 , & V_406 ) ;
}
if ( V_2 -> V_343 == V_409 ) {
struct V_405 V_410 ;
struct V_411 V_412 ;
memset ( & V_410 , 0 , sizeof( V_410 ) ) ;
memset ( & V_412 , 0 , sizeof( V_412 ) ) ;
F_136 ( V_2 , & V_412 ) ;
V_410 . V_210 = V_409 ;
V_410 . V_247 = & V_412 ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_408 , & V_410 ) ;
}
V_197 . V_210 = 0 ;
V_197 . type = V_209 ;
V_197 . V_202 = 9076 ;
V_2 -> V_203 = V_197 . V_202 ;
F_3 ( & V_2 -> V_9 , 0 , V_210 , V_211 , & V_197 ) ;
}
static int F_137 ( struct V_1 * V_2 )
{
T_1 V_251 ;
int V_36 ;
unsigned int V_262 ;
struct V_413 * V_414 = & V_2 -> V_255 ;
if ( V_2 -> V_382 ) {
return 0 ;
}
if ( ! V_2 -> V_383 ) {
return 0 ;
}
F_117 ( L_55 ) ;
F_118 ( & V_2 -> V_376 ) ;
V_36 = F_138 ( & V_2 -> V_99 -> V_2 , & V_2 -> V_9 ) ;
if ( V_36 < 0 ) {
F_19 ( L_56 ) ;
goto V_415;
}
F_139 ( V_414 , 8 ) ;
V_2 -> V_9 . V_255 = V_414 ;
V_2 -> V_44 = 0x10 ;
V_2 -> V_45 = V_416 |
V_417 ;
if ( V_2 -> V_4 . V_238 )
F_140 ( & V_2 -> V_9 , & V_2 -> V_418 [ V_2 -> V_419 ] ,
L_57 , 0 , V_420 ) ;
if ( V_2 -> V_4 . V_421 == V_422 )
F_140 ( & V_2 -> V_9 , & V_2 -> V_418 [ V_2 -> V_419 ] ,
L_58 , 0 , V_423 ) ;
if ( V_2 -> V_4 . V_421 == V_424 )
F_140 ( & V_2 -> V_9 , & V_2 -> V_418 [ V_2 -> V_419 ] ,
L_59 , 0 , V_425 ) ;
if ( V_2 -> V_4 . V_243 == V_426 )
F_140 ( & V_2 -> V_9 , & V_2 -> V_418 [ V_2 -> V_419 ] ,
L_60 , V_2 -> V_4 . V_427 , NULL ) ;
if ( V_2 -> V_4 . V_343 != V_344 ) {
int V_428 = ( V_2 -> V_404 & V_429 ) ;
if ( V_2 -> V_4 . V_400 . type )
F_140 ( & V_2 -> V_9 , & V_2 -> V_418 [ V_2 -> V_419 ] ,
L_61 , V_2 -> V_4 . V_401 , NULL ) ;
if ( V_428 )
F_140 ( & V_2 -> V_9 ,
& V_2 -> V_418 [ V_2 -> V_419 ] , L_61 ,
0 , F_141 ( V_430 ) ) ;
if ( V_2 -> V_403 == 0 ) {
enum V_431 type =
V_428 ? V_432 : V_433 ;
struct V_434 * V_435 ;
V_435 = F_140 ( & V_2 -> V_9 ,
& V_2 -> V_418 [ V_2 -> V_419 ] , L_61 ,
0 , F_141 ( type ) ) ;
if ( V_435 )
V_2 -> V_403 = F_142 ( V_435 ) ;
} else {
F_140 ( & V_2 -> V_9 , & V_2 -> V_418 [ V_2 -> V_419 ] ,
L_61 , V_2 -> V_403 , NULL ) ;
}
}
F_135 ( V_2 ) ;
F_143 ( V_2 ) ;
V_36 = F_144 ( V_2 ) ;
if ( V_36 < 0 ) {
F_19 ( L_62 ,
V_194 , V_36 ) ;
goto V_436;
}
if ( V_2 -> V_340 . V_437 != V_438 ) {
F_145 ( V_414 , & V_439 ,
V_249 , 0 , 1 , 1 , 1 ) ;
F_145 ( V_414 , & V_439 ,
V_252 , 0 , 0x1f , 1 , 0x1f ) ;
} else {
F_146 ( F_147 ( V_414 , V_249 ) ,
F_61 , V_2 ) ;
F_146 ( F_147 ( V_414 , V_252 ) ,
F_61 , V_2 ) ;
}
F_2 ( V_2 ) ;
F_148 ( & V_2 -> V_148 . V_139 ) ;
F_148 ( & V_2 -> V_150 . V_139 ) ;
if ( V_2 -> V_4 . V_238 ) {
V_36 = F_6 ( V_2 , V_440 , 0xf7 ) ;
if ( V_36 < 0 ) {
F_19 ( L_63 ,
V_194 , V_36 ) ;
goto V_436;
}
F_149 ( 3 ) ;
V_36 = F_6 ( V_2 , V_440 , 0xff ) ;
if ( V_36 < 0 ) {
F_19 ( L_64 ,
V_194 , V_36 ) ;
goto V_436;
}
F_149 ( 3 ) ;
}
V_2 -> V_52 = V_441 ;
F_3 ( & V_2 -> V_9 , 0 , V_10 , V_277 , V_2 -> V_52 ) ;
V_2 -> V_273 = V_442 ;
V_2 -> V_39 = & V_39 [ 0 ] ;
V_262 = F_15 ( V_2 ) ;
if ( V_2 -> V_4 . V_80 )
V_262 /= 2 ;
F_70 ( V_2 , V_39 [ 0 ] . V_269 ,
V_262 , F_16 ( V_2 ) ) ;
F_58 ( V_2 , 0 ) ;
V_2 -> V_250 = 1 ;
V_2 -> V_253 = 0x1f ;
V_251 = ( T_1 ) F_94 ( V_2 , V_443 ) ;
F_6 ( V_2 , V_443 ,
( V_444 | V_251 ) ) ;
F_7 ( V_2 ) ;
F_150 ( V_2 ) ;
if ( NULL == F_147 ( & V_2 -> V_255 , V_256 ) )
F_145 ( & V_2 -> V_255 , & V_439 ,
V_256 ,
0 , 0x1f , 1 , V_18 ) ;
if ( NULL == F_147 ( & V_2 -> V_255 , V_257 ) )
F_145 ( & V_2 -> V_255 , & V_439 ,
V_257 ,
- 0x80 , 0x7f , 1 , V_20 ) ;
if ( NULL == F_147 ( & V_2 -> V_255 , V_258 ) )
F_145 ( & V_2 -> V_255 , & V_439 ,
V_258 ,
0 , 0x1f , 1 , V_22 ) ;
if ( NULL == F_147 ( & V_2 -> V_255 , V_259 ) )
F_145 ( & V_2 -> V_255 , & V_439 ,
V_259 ,
- 0x30 , 0x30 , 1 , V_24 ) ;
if ( NULL == F_147 ( & V_2 -> V_255 , V_260 ) )
F_145 ( & V_2 -> V_255 , & V_439 ,
V_260 ,
- 0x30 , 0x30 , 1 , V_26 ) ;
if ( NULL == F_147 ( & V_2 -> V_255 , V_261 ) )
F_145 ( & V_2 -> V_255 , & V_439 ,
V_261 ,
0 , 0x0f , 1 , V_28 ) ;
F_5 ( V_2 ) ;
F_151 ( & V_2 -> V_255 ) ;
V_36 = V_2 -> V_255 . error ;
if ( V_36 )
goto V_436;
V_2 -> V_205 = F_131 ( V_2 , & V_445 , L_65 ) ;
if ( ! V_2 -> V_205 ) {
F_19 ( L_66 ) ;
V_36 = - V_446 ;
goto V_436;
}
V_2 -> V_205 -> V_447 = & V_2 -> V_216 ;
V_2 -> V_205 -> V_447 -> V_376 = & V_2 -> V_448 ;
if ( V_2 -> V_4 . V_5 ) {
F_152 ( V_2 -> V_205 , V_449 ) ;
F_152 ( V_2 -> V_205 , V_450 ) ;
F_152 ( V_2 -> V_205 , V_451 ) ;
} else {
F_152 ( V_2 -> V_205 , V_452 ) ;
}
if ( V_2 -> V_343 == V_344 ) {
F_152 ( V_2 -> V_205 , V_453 ) ;
F_152 ( V_2 -> V_205 , V_454 ) ;
F_152 ( V_2 -> V_205 , V_455 ) ;
F_152 ( V_2 -> V_205 , V_456 ) ;
}
if ( ! V_2 -> V_340 . V_341 ) {
F_152 ( V_2 -> V_205 , V_457 ) ;
F_152 ( V_2 -> V_205 , V_458 ) ;
}
V_36 = F_153 ( V_2 -> V_205 , V_333 ,
V_459 [ V_2 -> V_460 ] ) ;
if ( V_36 ) {
F_19 ( L_67 ,
V_36 ) ;
goto V_436;
}
if ( F_1 ( V_2 ) == 1 ) {
V_2 -> V_347 = F_131 ( V_2 , & V_445 ,
L_68 ) ;
V_2 -> V_347 -> V_447 = & V_2 -> V_230 ;
V_2 -> V_347 -> V_447 -> V_376 = & V_2 -> V_461 ;
F_152 ( V_2 -> V_205 , V_452 ) ;
if ( V_2 -> V_343 == V_344 ) {
F_152 ( V_2 -> V_347 , V_453 ) ;
F_152 ( V_2 -> V_347 , V_454 ) ;
F_152 ( V_2 -> V_347 , V_455 ) ;
F_152 ( V_2 -> V_347 , V_456 ) ;
}
if ( ! V_2 -> V_340 . V_341 ) {
F_152 ( V_2 -> V_347 , V_457 ) ;
F_152 ( V_2 -> V_347 , V_458 ) ;
}
V_36 = F_153 ( V_2 -> V_347 , V_373 ,
V_462 [ V_2 -> V_460 ] ) ;
if ( V_36 < 0 ) {
F_19 ( L_69 ) ;
goto V_436;
}
}
if ( V_330 [ V_2 -> V_331 ] . V_400 . type == V_463 ) {
V_2 -> V_348 = F_131 ( V_2 , & V_464 ,
L_70 ) ;
if ( ! V_2 -> V_348 ) {
F_19 ( L_66 ) ;
V_36 = - V_446 ;
goto V_436;
}
V_36 = F_153 ( V_2 -> V_348 , V_207 ,
V_465 [ V_2 -> V_460 ] ) ;
if ( V_36 < 0 ) {
F_19 ( L_71 ) ;
goto V_436;
}
F_117 ( L_72 ,
F_109 ( V_2 -> V_348 ) ) ;
}
F_117 ( L_73 ,
F_109 ( V_2 -> V_205 ) ) ;
if ( V_2 -> V_347 )
F_117 ( L_74 ,
F_109 ( V_2 -> V_347 ) ) ;
F_3 ( & V_2 -> V_9 , 0 , V_10 , V_385 , 0 ) ;
F_56 ( V_2 ) ;
F_117 ( L_75 ) ;
F_112 ( & V_2 -> V_376 ) ;
return 0 ;
V_436:
F_122 ( & V_2 -> V_255 ) ;
F_123 ( & V_2 -> V_9 ) ;
V_415:
F_112 ( & V_2 -> V_376 ) ;
return V_36 ;
}
static int T_5 F_154 ( void )
{
return F_155 ( & V_466 ) ;
}
static void T_6 F_156 ( void )
{
F_157 ( & V_466 ) ;
}
