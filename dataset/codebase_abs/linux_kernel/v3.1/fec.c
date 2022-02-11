static void * F_1 ( void * V_1 , int V_2 )
{
int V_3 ;
unsigned int * V_4 = V_1 ;
for ( V_3 = 0 ; V_3 < ( V_2 + 3 ) / 4 ; V_3 ++ , V_4 ++ )
* V_4 = F_2 ( * V_4 ) ;
return V_1 ;
}
static T_1
F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
const struct V_11 * V_12 =
F_5 ( V_10 -> V_13 ) ;
struct V_14 * V_15 ;
void * V_1 ;
unsigned short V_16 ;
unsigned long V_17 ;
if ( ! V_10 -> V_18 ) {
return V_19 ;
}
F_6 ( & V_10 -> V_20 , V_17 ) ;
V_15 = V_10 -> V_21 ;
V_16 = V_15 -> V_22 ;
if ( V_16 & V_23 ) {
F_7 ( L_1 , V_8 -> V_24 ) ;
F_8 ( & V_10 -> V_20 , V_17 ) ;
return V_19 ;
}
V_16 &= ~ V_25 ;
V_1 = V_6 -> V_26 ;
V_15 -> V_27 = V_6 -> V_2 ;
if ( ( ( unsigned long ) V_1 ) & V_28 ) {
unsigned int V_29 ;
V_29 = V_15 - V_10 -> V_30 ;
memcpy ( V_10 -> V_31 [ V_29 ] , V_6 -> V_26 , V_6 -> V_2 ) ;
V_1 = V_10 -> V_31 [ V_29 ] ;
}
if ( V_12 -> V_32 & V_33 )
F_1 ( V_1 , V_6 -> V_2 ) ;
V_10 -> V_34 [ V_10 -> V_35 ] = V_6 ;
V_8 -> V_36 . V_37 += V_6 -> V_2 ;
V_10 -> V_35 = ( V_10 -> V_35 + 1 ) & V_38 ;
V_15 -> V_39 = F_9 ( & V_10 -> V_13 -> V_40 , V_1 ,
V_41 , V_42 ) ;
V_16 |= ( V_23 | V_43
| V_44 | V_45 ) ;
V_15 -> V_22 = V_16 ;
F_10 ( 0 , V_10 -> V_46 + V_47 ) ;
if ( V_16 & V_48 )
V_15 = V_10 -> V_30 ;
else
V_15 ++ ;
if ( V_15 == V_10 -> V_49 ) {
V_10 -> V_50 = 1 ;
F_11 ( V_8 ) ;
}
V_10 -> V_21 = V_15 ;
F_12 ( V_6 ) ;
F_8 ( & V_10 -> V_20 , V_17 ) ;
return V_51 ;
}
static void
F_13 ( struct V_7 * V_8 , int V_52 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
const struct V_11 * V_12 =
F_5 ( V_10 -> V_13 ) ;
int V_3 ;
T_2 V_53 [ 2 ] ;
T_2 V_54 = V_55 | 0x04 ;
F_10 ( 1 , V_10 -> V_46 + V_56 ) ;
F_14 ( 10 ) ;
if ( V_12 -> V_32 & V_57 ) {
memcpy ( & V_53 , V_8 -> V_58 , V_59 ) ;
F_10 ( F_2 ( V_53 [ 0 ] ) , V_10 -> V_46 + V_60 ) ;
F_10 ( F_2 ( V_53 [ 1 ] ) , V_10 -> V_46 + V_61 ) ;
}
F_10 ( 0xffc00000 , V_10 -> V_46 + V_62 ) ;
F_10 ( 0 , V_10 -> V_46 + V_63 ) ;
F_10 ( 0 , V_10 -> V_46 + V_64 ) ;
#ifndef F_15
F_10 ( 0 , V_10 -> V_46 + V_65 ) ;
F_10 ( 0 , V_10 -> V_46 + V_66 ) ;
#endif
F_10 ( V_67 , V_10 -> V_46 + V_68 ) ;
F_10 ( V_10 -> V_69 , V_10 -> V_46 + V_70 ) ;
F_10 ( ( unsigned long ) V_10 -> V_69 + sizeof( struct V_14 ) * V_71 ,
V_10 -> V_46 + V_72 ) ;
V_10 -> V_49 = V_10 -> V_21 = V_10 -> V_30 ;
V_10 -> V_73 = V_10 -> V_74 ;
V_10 -> V_35 = V_10 -> V_75 = 0 ;
for ( V_3 = 0 ; V_3 <= V_38 ; V_3 ++ ) {
if ( V_10 -> V_34 [ V_3 ] ) {
F_16 ( V_10 -> V_34 [ V_3 ] ) ;
V_10 -> V_34 [ V_3 ] = NULL ;
}
}
if ( V_52 ) {
F_10 ( 0x04 , V_10 -> V_46 + V_76 ) ;
} else {
V_54 |= 0x02 ;
F_10 ( 0x0 , V_10 -> V_46 + V_76 ) ;
}
V_10 -> V_77 = V_52 ;
F_10 ( V_10 -> V_78 , V_10 -> V_46 + V_79 ) ;
if ( V_12 -> V_32 & V_57 ) {
V_54 |= 0x40000000 | 0x00000020 ;
if ( V_10 -> V_80 == V_81 )
V_54 |= ( 1 << 8 ) ;
else
V_54 &= ~ ( 1 << 8 ) ;
if ( V_10 -> V_82 && V_10 -> V_82 -> V_83 == V_84 )
V_54 &= ~ ( 1 << 9 ) ;
else
V_54 |= ( 1 << 9 ) ;
} else {
#ifdef F_17
if ( V_12 -> V_32 & V_85 ) {
F_10 ( 0 , V_10 -> V_46 + F_17 ) ;
while ( F_18 ( V_10 -> V_46 + F_17 ) & 4 )
F_14 ( 1 ) ;
F_10 ( ( V_10 -> V_80 == V_81 ) ?
1 : 0 , V_10 -> V_46 + V_86 ) ;
F_10 ( 2 , V_10 -> V_46 + F_17 ) ;
}
#endif
}
F_10 ( V_54 , V_10 -> V_46 + V_87 ) ;
F_10 ( 2 , V_10 -> V_46 + V_56 ) ;
F_10 ( 0 , V_10 -> V_46 + V_88 ) ;
F_10 ( V_89 , V_10 -> V_46 + V_90 ) ;
}
static void
F_19 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
if ( V_10 -> V_18 ) {
F_10 ( 1 , V_10 -> V_46 + V_76 ) ;
F_14 ( 10 ) ;
if ( ! ( F_18 ( V_10 -> V_46 + V_62 ) & V_91 ) )
F_7 ( L_2 ) ;
}
F_10 ( 1 , V_10 -> V_46 + V_56 ) ;
F_14 ( 10 ) ;
F_10 ( V_10 -> V_78 , V_10 -> V_46 + V_79 ) ;
F_10 ( V_89 , V_10 -> V_46 + V_90 ) ;
}
static void
F_20 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
V_8 -> V_36 . V_92 ++ ;
F_13 ( V_8 , V_10 -> V_77 ) ;
F_21 ( V_8 ) ;
}
static void
F_22 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 ;
unsigned short V_16 ;
struct V_5 * V_6 ;
V_10 = F_4 ( V_8 ) ;
F_23 ( & V_10 -> V_20 ) ;
V_15 = V_10 -> V_49 ;
while ( ( ( V_16 = V_15 -> V_22 ) & V_23 ) == 0 ) {
if ( V_15 == V_10 -> V_21 && V_10 -> V_50 == 0 )
break;
F_24 ( & V_10 -> V_13 -> V_40 , V_15 -> V_39 ,
V_41 , V_42 ) ;
V_15 -> V_39 = 0 ;
V_6 = V_10 -> V_34 [ V_10 -> V_75 ] ;
if ( V_16 & ( V_93 | V_94 |
V_95 | V_96 |
V_97 ) ) {
V_8 -> V_36 . V_92 ++ ;
if ( V_16 & V_93 )
V_8 -> V_36 . V_98 ++ ;
if ( V_16 & V_94 )
V_8 -> V_36 . V_99 ++ ;
if ( V_16 & V_95 )
V_8 -> V_36 . V_100 ++ ;
if ( V_16 & V_96 )
V_8 -> V_36 . V_101 ++ ;
if ( V_16 & V_97 )
V_8 -> V_36 . V_102 ++ ;
} else {
V_8 -> V_36 . V_103 ++ ;
}
if ( V_16 & V_23 )
F_7 ( L_3 ) ;
if ( V_16 & V_104 )
V_8 -> V_36 . V_105 ++ ;
F_16 ( V_6 ) ;
V_10 -> V_34 [ V_10 -> V_75 ] = NULL ;
V_10 -> V_75 = ( V_10 -> V_75 + 1 ) & V_38 ;
if ( V_16 & V_48 )
V_15 = V_10 -> V_30 ;
else
V_15 ++ ;
if ( V_10 -> V_50 ) {
V_10 -> V_50 = 0 ;
if ( F_25 ( V_8 ) )
F_21 ( V_8 ) ;
}
}
V_10 -> V_49 = V_15 ;
F_26 ( & V_10 -> V_20 ) ;
}
static void
F_27 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
const struct V_11 * V_12 =
F_5 ( V_10 -> V_13 ) ;
struct V_14 * V_15 ;
unsigned short V_16 ;
struct V_5 * V_6 ;
T_3 V_106 ;
T_4 * V_26 ;
#ifdef F_28
F_29 () ;
#endif
F_23 ( & V_10 -> V_20 ) ;
V_15 = V_10 -> V_73 ;
while ( ! ( ( V_16 = V_15 -> V_22 ) & V_107 ) ) {
if ( ( V_16 & V_108 ) == 0 )
F_7 ( L_4 ) ;
if ( ! V_10 -> V_109 )
goto V_110;
if ( V_16 & ( V_111 | V_112 | V_113 |
V_114 | V_115 ) ) {
V_8 -> V_36 . V_116 ++ ;
if ( V_16 & ( V_111 | V_112 ) ) {
V_8 -> V_36 . V_117 ++ ;
}
if ( V_16 & V_113 )
V_8 -> V_36 . V_118 ++ ;
if ( V_16 & V_114 )
V_8 -> V_36 . V_119 ++ ;
if ( V_16 & V_115 )
V_8 -> V_36 . V_120 ++ ;
}
if ( V_16 & V_121 ) {
V_8 -> V_36 . V_116 ++ ;
V_8 -> V_36 . V_118 ++ ;
goto V_110;
}
V_8 -> V_36 . V_122 ++ ;
V_106 = V_15 -> V_27 ;
V_8 -> V_36 . V_123 += V_106 ;
V_26 = ( T_4 * ) F_30 ( V_15 -> V_39 ) ;
F_24 ( & V_10 -> V_13 -> V_40 , V_15 -> V_39 ,
V_41 , V_124 ) ;
if ( V_12 -> V_32 & V_33 )
F_1 ( V_26 , V_106 ) ;
V_6 = F_31 ( V_106 - 4 + V_125 ) ;
if ( F_32 ( ! V_6 ) ) {
F_7 ( L_5 ,
V_8 -> V_24 ) ;
V_8 -> V_36 . V_126 ++ ;
} else {
F_33 ( V_6 , V_125 ) ;
F_34 ( V_6 , V_106 - 4 ) ;
F_35 ( V_6 , V_26 , V_106 - 4 ) ;
V_6 -> V_127 = F_36 ( V_6 , V_8 ) ;
if ( ! F_37 ( V_6 ) )
F_38 ( V_6 ) ;
}
V_15 -> V_39 = F_9 ( & V_10 -> V_13 -> V_40 , V_26 ,
V_41 , V_124 ) ;
V_110:
V_16 &= ~ V_128 ;
V_16 |= V_107 ;
V_15 -> V_22 = V_16 ;
if ( V_16 & V_129 )
V_15 = V_10 -> V_74 ;
else
V_15 ++ ;
F_10 ( 0 , V_10 -> V_46 + V_88 ) ;
}
V_10 -> V_73 = V_15 ;
F_26 ( & V_10 -> V_20 ) ;
}
static T_5
F_39 ( int V_130 , void * V_131 )
{
struct V_7 * V_8 = V_131 ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
T_6 V_132 ;
T_5 V_133 = V_134 ;
do {
V_132 = F_18 ( V_10 -> V_46 + V_62 ) ;
F_10 ( V_132 , V_10 -> V_46 + V_62 ) ;
if ( V_132 & V_135 ) {
V_133 = V_136 ;
F_27 ( V_8 ) ;
}
if ( V_132 & V_137 ) {
V_133 = V_136 ;
F_22 ( V_8 ) ;
}
if ( V_132 & V_138 ) {
V_133 = V_136 ;
F_40 ( & V_10 -> V_139 ) ;
}
} while ( V_132 );
return V_133 ;
}
static void T_7 F_41 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_140 * V_141 = V_10 -> V_13 -> V_40 . V_142 ;
unsigned char * V_143 , V_144 [ V_59 ] ;
V_143 = V_145 ;
#ifdef F_42
if ( ! F_43 ( V_143 ) ) {
struct V_146 * V_147 = V_10 -> V_13 -> V_40 . V_148 ;
if ( V_147 ) {
const char * V_149 = F_44 ( V_147 ) ;
if ( V_149 )
V_143 = ( unsigned char * ) V_149 ;
}
}
#endif
if ( ! F_43 ( V_143 ) ) {
#ifdef F_15
if ( V_150 )
V_143 = ( unsigned char * ) V_150 ;
#else
if ( V_141 )
memcpy ( V_143 , V_141 -> V_149 , V_59 ) ;
#endif
}
if ( ! F_43 ( V_143 ) ) {
* ( ( unsigned long * ) & V_144 [ 0 ] ) =
F_45 ( F_18 ( V_10 -> V_46 + V_60 ) ) ;
* ( ( unsigned short * ) & V_144 [ 4 ] ) =
F_46 ( F_18 ( V_10 -> V_46 + V_61 ) >> 16 ) ;
V_143 = & V_144 [ 0 ] ;
}
memcpy ( V_8 -> V_58 , V_143 , V_59 ) ;
if ( V_143 == V_145 )
V_8 -> V_58 [ V_59 - 1 ] = V_145 [ V_59 - 1 ] + V_10 -> V_13 -> V_151 ;
}
static void F_47 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_152 * V_82 = V_10 -> V_82 ;
unsigned long V_17 ;
int V_153 = 0 ;
F_6 ( & V_10 -> V_20 , V_17 ) ;
if ( V_10 -> V_154 && V_82 -> V_155 == V_156 ) {
V_82 -> V_155 = V_157 ;
goto F_26;
}
if ( V_82 -> V_18 ) {
if ( V_10 -> V_77 != V_82 -> V_52 ) {
F_13 ( V_8 , V_82 -> V_52 ) ;
V_153 = 1 ;
}
}
if ( V_82 -> V_18 != V_10 -> V_18 ) {
V_10 -> V_18 = V_82 -> V_18 ;
if ( V_82 -> V_18 )
F_13 ( V_8 , V_82 -> V_52 ) ;
else
F_19 ( V_8 ) ;
V_153 = 1 ;
}
F_26:
F_8 ( & V_10 -> V_20 , V_17 ) ;
if ( V_153 )
F_48 ( V_82 ) ;
}
static int F_49 ( struct V_158 * V_159 , int V_160 , int V_161 )
{
struct V_9 * V_10 = V_159 -> V_162 ;
unsigned long V_163 ;
V_10 -> V_154 = 0 ;
F_50 ( & V_10 -> V_139 ) ;
F_10 ( V_164 | V_165 |
F_51 ( V_160 ) | F_52 ( V_161 ) |
V_166 , V_10 -> V_46 + V_167 ) ;
V_163 = F_53 ( & V_10 -> V_139 ,
F_54 ( V_168 ) ) ;
if ( V_163 == 0 ) {
V_10 -> V_154 = 1 ;
F_7 ( V_169 L_6 ) ;
return - V_170 ;
}
return F_55 ( F_18 ( V_10 -> V_46 + V_167 ) ) ;
}
static int F_56 ( struct V_158 * V_159 , int V_160 , int V_161 ,
T_8 V_171 )
{
struct V_9 * V_10 = V_159 -> V_162 ;
unsigned long V_163 ;
V_10 -> V_154 = 0 ;
F_50 ( & V_10 -> V_139 ) ;
F_10 ( V_164 | V_172 |
F_51 ( V_160 ) | F_52 ( V_161 ) |
V_166 | F_55 ( V_171 ) ,
V_10 -> V_46 + V_167 ) ;
V_163 = F_53 ( & V_10 -> V_139 ,
F_54 ( V_168 ) ) ;
if ( V_163 == 0 ) {
V_10 -> V_154 = 1 ;
F_7 ( V_169 L_7 ) ;
return - V_170 ;
}
return 0 ;
}
static int F_57 ( struct V_158 * V_159 )
{
return 0 ;
}
static int F_58 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_152 * V_82 = NULL ;
char V_173 [ V_174 ] ;
char V_175 [ V_174 + 3 ] ;
int V_176 ;
int V_131 = V_10 -> V_13 -> V_151 ;
V_10 -> V_82 = NULL ;
for ( V_176 = 0 ; ( V_176 < V_177 ) ; V_176 ++ ) {
if ( ( V_10 -> V_158 -> V_178 & ( 1 << V_176 ) ) )
continue;
if ( V_10 -> V_158 -> V_179 [ V_176 ] == NULL )
continue;
if ( V_10 -> V_158 -> V_179 [ V_176 ] -> V_176 == 0 )
continue;
if ( V_131 -- )
continue;
strncpy ( V_173 , V_10 -> V_158 -> V_151 , V_174 ) ;
break;
}
if ( V_176 >= V_177 ) {
F_7 ( V_180 L_8
L_9 , V_8 -> V_24 ) ;
strncpy ( V_173 , L_10 , V_174 ) ;
V_176 = 0 ;
}
snprintf ( V_175 , V_174 , V_181 , V_173 , V_176 ) ;
V_82 = F_59 ( V_8 , V_175 , & F_47 , 0 ,
V_182 ) ;
if ( F_60 ( V_82 ) ) {
F_7 ( V_169 L_11 , V_8 -> V_24 ) ;
return F_61 ( V_82 ) ;
}
V_82 -> V_183 &= V_184 ;
V_82 -> V_185 = V_82 -> V_183 ;
V_10 -> V_82 = V_82 ;
V_10 -> V_18 = 0 ;
V_10 -> V_77 = 0 ;
F_7 ( V_180 L_12
L_13 , V_8 -> V_24 ,
V_10 -> V_82 -> V_186 -> V_24 , F_62 ( & V_10 -> V_82 -> V_40 ) ,
V_10 -> V_82 -> V_130 ) ;
return 0 ;
}
static int F_63 ( struct V_187 * V_13 )
{
static struct V_158 * V_188 ;
struct V_7 * V_8 = F_64 ( V_13 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
const struct V_11 * V_12 =
F_5 ( V_10 -> V_13 ) ;
int V_189 = - V_190 , V_3 ;
if ( ( V_12 -> V_32 & V_57 ) && V_13 -> V_151 ) {
V_10 -> V_158 = V_188 ;
return 0 ;
}
V_10 -> V_154 = 0 ;
V_10 -> V_78 = F_65 ( F_66 ( V_10 -> V_191 ) , 5000000 ) << 1 ;
F_10 ( V_10 -> V_78 , V_10 -> V_46 + V_79 ) ;
V_10 -> V_158 = F_67 () ;
if ( V_10 -> V_158 == NULL ) {
V_189 = - V_192 ;
goto V_193;
}
V_10 -> V_158 -> V_24 = L_14 ;
V_10 -> V_158 -> V_194 = F_49 ;
V_10 -> V_158 -> V_195 = F_56 ;
V_10 -> V_158 -> V_196 = F_57 ;
snprintf ( V_10 -> V_158 -> V_151 , V_174 , L_15 , V_13 -> V_151 + 1 ) ;
V_10 -> V_158 -> V_162 = V_10 ;
V_10 -> V_158 -> V_197 = & V_13 -> V_40 ;
V_10 -> V_158 -> V_130 = F_68 ( sizeof( int ) * V_177 , V_198 ) ;
if ( ! V_10 -> V_158 -> V_130 ) {
V_189 = - V_192 ;
goto V_199;
}
for ( V_3 = 0 ; V_3 < V_177 ; V_3 ++ )
V_10 -> V_158 -> V_130 [ V_3 ] = V_200 ;
if ( F_69 ( V_10 -> V_158 ) )
goto V_201;
if ( V_12 -> V_32 & V_57 )
V_188 = V_10 -> V_158 ;
return 0 ;
V_201:
F_70 ( V_10 -> V_158 -> V_130 ) ;
V_199:
F_71 ( V_10 -> V_158 ) ;
V_193:
return V_189 ;
}
static void F_72 ( struct V_9 * V_10 )
{
if ( V_10 -> V_82 )
F_73 ( V_10 -> V_82 ) ;
F_74 ( V_10 -> V_158 ) ;
F_70 ( V_10 -> V_158 -> V_130 ) ;
F_71 ( V_10 -> V_158 ) ;
}
static int F_75 ( struct V_7 * V_8 ,
struct V_202 * V_203 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_152 * V_204 = V_10 -> V_82 ;
if ( ! V_204 )
return - V_205 ;
return F_76 ( V_204 , V_203 ) ;
}
static int F_77 ( struct V_7 * V_8 ,
struct V_202 * V_203 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_152 * V_204 = V_10 -> V_82 ;
if ( ! V_204 )
return - V_205 ;
return F_78 ( V_204 , V_203 ) ;
}
static void F_79 ( struct V_7 * V_8 ,
struct V_206 * V_207 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
strcpy ( V_207 -> V_208 , V_10 -> V_13 -> V_40 . V_208 -> V_24 ) ;
strcpy ( V_207 -> V_209 , L_16 ) ;
strcpy ( V_207 -> V_210 , F_62 ( & V_8 -> V_40 ) ) ;
}
static int F_80 ( struct V_7 * V_8 , struct V_211 * V_212 , int V_203 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_152 * V_204 = V_10 -> V_82 ;
if ( ! F_81 ( V_8 ) )
return - V_213 ;
if ( ! V_204 )
return - V_205 ;
return F_82 ( V_204 , V_212 , V_203 ) ;
}
static void F_83 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
int V_3 ;
struct V_5 * V_6 ;
struct V_14 * V_15 ;
V_15 = V_10 -> V_74 ;
for ( V_3 = 0 ; V_3 < V_71 ; V_3 ++ ) {
V_6 = V_10 -> V_214 [ V_3 ] ;
if ( V_15 -> V_39 )
F_24 ( & V_10 -> V_13 -> V_40 , V_15 -> V_39 ,
V_215 , V_124 ) ;
if ( V_6 )
F_84 ( V_6 ) ;
V_15 ++ ;
}
V_15 = V_10 -> V_30 ;
for ( V_3 = 0 ; V_3 < V_216 ; V_3 ++ )
F_70 ( V_10 -> V_31 [ V_3 ] ) ;
}
static int F_85 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
int V_3 ;
struct V_5 * V_6 ;
struct V_14 * V_15 ;
V_15 = V_10 -> V_74 ;
for ( V_3 = 0 ; V_3 < V_71 ; V_3 ++ ) {
V_6 = F_31 ( V_215 ) ;
if ( ! V_6 ) {
F_83 ( V_8 ) ;
return - V_192 ;
}
V_10 -> V_214 [ V_3 ] = V_6 ;
V_15 -> V_39 = F_9 ( & V_10 -> V_13 -> V_40 , V_6 -> V_26 ,
V_215 , V_124 ) ;
V_15 -> V_22 = V_107 ;
V_15 ++ ;
}
V_15 -- ;
V_15 -> V_22 |= V_217 ;
V_15 = V_10 -> V_30 ;
for ( V_3 = 0 ; V_3 < V_216 ; V_3 ++ ) {
V_10 -> V_31 [ V_3 ] = F_68 ( V_41 , V_198 ) ;
V_15 -> V_22 = 0 ;
V_15 -> V_39 = 0 ;
V_15 ++ ;
}
V_15 -- ;
V_15 -> V_22 |= V_217 ;
return 0 ;
}
static int
F_86 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
int V_133 ;
V_133 = F_85 ( V_8 ) ;
if ( V_133 )
return V_133 ;
V_133 = F_58 ( V_8 ) ;
if ( V_133 ) {
F_83 ( V_8 ) ;
return V_133 ;
}
F_87 ( V_10 -> V_82 ) ;
F_88 ( V_8 ) ;
V_10 -> V_109 = 1 ;
return 0 ;
}
static int
F_89 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
V_10 -> V_109 = 0 ;
F_11 ( V_8 ) ;
F_19 ( V_8 ) ;
if ( V_10 -> V_82 ) {
F_90 ( V_10 -> V_82 ) ;
F_73 ( V_10 -> V_82 ) ;
}
F_83 ( V_8 ) ;
return 0 ;
}
static void F_91 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_218 * V_219 ;
unsigned int V_3 , V_220 , V_26 , V_221 , V_222 ;
unsigned char V_223 ;
if ( V_8 -> V_17 & V_224 ) {
V_222 = F_18 ( V_10 -> V_46 + V_87 ) ;
V_222 |= 0x8 ;
F_10 ( V_222 , V_10 -> V_46 + V_87 ) ;
return;
}
V_222 = F_18 ( V_10 -> V_46 + V_87 ) ;
V_222 &= ~ 0x8 ;
F_10 ( V_222 , V_10 -> V_46 + V_87 ) ;
if ( V_8 -> V_17 & V_225 ) {
F_10 ( 0xffffffff , V_10 -> V_46 + V_63 ) ;
F_10 ( 0xffffffff , V_10 -> V_46 + V_64 ) ;
return;
}
F_10 ( 0 , V_10 -> V_46 + V_63 ) ;
F_10 ( 0 , V_10 -> V_46 + V_64 ) ;
F_92 (ha, ndev) {
V_221 = 0xffffffff ;
for ( V_3 = 0 ; V_3 < V_8 -> V_226 ; V_3 ++ ) {
V_26 = V_219 -> V_227 [ V_3 ] ;
for ( V_220 = 0 ; V_220 < 8 ; V_220 ++ , V_26 >>= 1 ) {
V_221 = ( V_221 >> 1 ) ^
( ( ( V_221 ^ V_26 ) & 1 ) ? V_228 : 0 ) ;
}
}
V_223 = ( V_221 >> ( 32 - V_229 ) ) & 0x3f ;
if ( V_223 > 31 ) {
V_222 = F_18 ( V_10 -> V_46 + V_63 ) ;
V_222 |= 1 << ( V_223 - 32 ) ;
F_10 ( V_222 , V_10 -> V_46 + V_63 ) ;
} else {
V_222 = F_18 ( V_10 -> V_46 + V_64 ) ;
V_222 |= 1 << V_223 ;
F_10 ( V_222 , V_10 -> V_46 + V_64 ) ;
}
}
}
static int
F_93 ( struct V_7 * V_8 , void * V_230 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_231 * V_227 = V_230 ;
if ( ! F_43 ( V_227 -> V_232 ) )
return - V_233 ;
memcpy ( V_8 -> V_58 , V_227 -> V_232 , V_8 -> V_226 ) ;
F_10 ( V_8 -> V_58 [ 3 ] | ( V_8 -> V_58 [ 2 ] << 8 ) |
( V_8 -> V_58 [ 1 ] << 16 ) | ( V_8 -> V_58 [ 0 ] << 24 ) ,
V_10 -> V_46 + V_60 ) ;
F_10 ( ( V_8 -> V_58 [ 5 ] << 16 ) | ( V_8 -> V_58 [ 4 ] << 24 ) ,
V_10 -> V_46 + V_61 ) ;
return 0 ;
}
static int F_94 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_14 * V_234 ;
struct V_14 * V_15 ;
int V_3 ;
V_234 = F_95 ( NULL , V_235 , & V_10 -> V_69 ,
V_198 ) ;
if ( ! V_234 ) {
F_7 ( L_17 ) ;
return - V_192 ;
}
F_96 ( & V_10 -> V_20 ) ;
V_10 -> V_236 = V_8 ;
F_41 ( V_8 ) ;
V_10 -> V_74 = V_234 ;
V_10 -> V_30 = V_234 + V_71 ;
V_8 -> V_237 = V_238 ;
V_8 -> V_239 = & V_240 ;
V_8 -> V_241 = & V_242 ;
V_15 = V_10 -> V_74 ;
for ( V_3 = 0 ; V_3 < V_71 ; V_3 ++ ) {
V_15 -> V_22 = 0 ;
V_15 ++ ;
}
V_15 -- ;
V_15 -> V_22 |= V_217 ;
V_15 = V_10 -> V_30 ;
for ( V_3 = 0 ; V_3 < V_216 ; V_3 ++ ) {
V_15 -> V_22 = 0 ;
V_15 -> V_39 = 0 ;
V_15 ++ ;
}
V_15 -- ;
V_15 -> V_22 |= V_217 ;
F_13 ( V_8 , 0 ) ;
return 0 ;
}
static int T_9 F_97 ( struct V_187 * V_13 )
{
struct V_146 * V_147 = V_13 -> V_40 . V_148 ;
if ( V_147 )
return F_98 ( V_147 ) ;
return - V_205 ;
}
static int T_9 F_99 ( struct V_187 * V_13 )
{
int V_189 , V_243 ;
struct V_146 * V_147 = V_13 -> V_40 . V_148 ;
if ( ! V_147 )
return - V_205 ;
V_243 = F_100 ( V_147 , L_18 , 0 ) ;
V_189 = F_101 ( V_243 , V_244 , L_19 ) ;
if ( V_189 ) {
F_102 ( L_20 , V_189 ) ;
return V_189 ;
}
F_103 ( 1 ) ;
F_104 ( V_243 , 1 ) ;
return 0 ;
}
static inline int F_97 ( struct V_187 * V_13 )
{
return - V_205 ;
}
static inline int F_99 ( struct V_187 * V_13 )
{
return 0 ;
}
static int T_9
F_105 ( struct V_187 * V_13 )
{
struct V_9 * V_10 ;
struct V_140 * V_141 ;
struct V_7 * V_8 ;
int V_3 , V_130 , V_133 = 0 ;
struct V_245 * V_246 ;
const struct V_247 * V_248 ;
V_248 = F_106 ( V_249 , & V_13 -> V_40 ) ;
if ( V_248 )
V_13 -> V_12 = V_248 -> V_26 ;
V_246 = F_107 ( V_13 , V_250 , 0 ) ;
if ( ! V_246 )
return - V_190 ;
V_246 = F_108 ( V_246 -> V_251 , F_109 ( V_246 ) , V_13 -> V_24 ) ;
if ( ! V_246 )
return - V_252 ;
V_8 = F_110 ( sizeof( struct V_9 ) ) ;
if ( ! V_8 ) {
V_133 = - V_192 ;
goto V_253;
}
F_111 ( V_8 , & V_13 -> V_40 ) ;
V_10 = F_4 ( V_8 ) ;
V_10 -> V_46 = F_112 ( V_246 -> V_251 , F_109 ( V_246 ) ) ;
V_10 -> V_13 = V_13 ;
if ( ! V_10 -> V_46 ) {
V_133 = - V_192 ;
goto V_254;
}
F_113 ( V_13 , V_8 ) ;
V_133 = F_97 ( V_13 ) ;
if ( V_133 < 0 ) {
V_141 = V_13 -> V_40 . V_142 ;
if ( V_141 )
V_10 -> V_80 = V_141 -> V_255 ;
else
V_10 -> V_80 = V_182 ;
} else {
V_10 -> V_80 = V_133 ;
}
F_99 ( V_13 ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_130 = F_114 ( V_13 , V_3 ) ;
if ( V_3 && V_130 < 0 )
break;
V_133 = F_115 ( V_130 , F_39 , V_256 , V_13 -> V_24 , V_8 ) ;
if ( V_133 ) {
while ( -- V_3 >= 0 ) {
V_130 = F_114 ( V_13 , V_3 ) ;
F_116 ( V_130 , V_8 ) ;
}
goto V_257;
}
}
V_10 -> V_191 = F_117 ( & V_13 -> V_40 , L_21 ) ;
if ( F_60 ( V_10 -> V_191 ) ) {
V_133 = F_61 ( V_10 -> V_191 ) ;
goto V_258;
}
F_118 ( V_10 -> V_191 ) ;
V_133 = F_94 ( V_8 ) ;
if ( V_133 )
goto V_259;
V_133 = F_63 ( V_13 ) ;
if ( V_133 )
goto V_260;
F_119 ( V_8 ) ;
V_133 = F_120 ( V_8 ) ;
if ( V_133 )
goto V_261;
return 0 ;
V_261:
F_72 ( V_10 ) ;
V_260:
V_259:
F_121 ( V_10 -> V_191 ) ;
F_122 ( V_10 -> V_191 ) ;
V_258:
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_130 = F_114 ( V_13 , V_3 ) ;
if ( V_130 > 0 )
F_116 ( V_130 , V_8 ) ;
}
V_257:
F_123 ( V_10 -> V_46 ) ;
V_254:
F_124 ( V_8 ) ;
V_253:
F_125 ( V_246 -> V_251 , F_109 ( V_246 ) ) ;
return V_133 ;
}
static int T_10
F_126 ( struct V_187 * V_13 )
{
struct V_7 * V_8 = F_64 ( V_13 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_245 * V_246 ;
F_19 ( V_8 ) ;
F_72 ( V_10 ) ;
F_121 ( V_10 -> V_191 ) ;
F_122 ( V_10 -> V_191 ) ;
F_123 ( V_10 -> V_46 ) ;
F_127 ( V_8 ) ;
F_124 ( V_8 ) ;
V_246 = F_107 ( V_13 , V_250 , 0 ) ;
F_128 ( ! V_246 ) ;
F_125 ( V_246 -> V_251 , F_109 ( V_246 ) ) ;
F_113 ( V_13 , NULL ) ;
return 0 ;
}
static int
F_129 ( struct V_262 * V_40 )
{
struct V_7 * V_8 = F_130 ( V_40 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
if ( F_81 ( V_8 ) ) {
F_19 ( V_8 ) ;
F_131 ( V_8 ) ;
}
F_121 ( V_10 -> V_191 ) ;
return 0 ;
}
static int
F_132 ( struct V_262 * V_40 )
{
struct V_7 * V_8 = F_130 ( V_40 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
F_118 ( V_10 -> V_191 ) ;
if ( F_81 ( V_8 ) ) {
F_13 ( V_8 , V_10 -> V_77 ) ;
F_133 ( V_8 ) ;
}
return 0 ;
}
static int T_11
F_134 ( void )
{
F_7 ( V_180 L_22 ) ;
return F_135 ( & V_263 ) ;
}
static void T_12
F_136 ( void )
{
F_137 ( & V_263 ) ;
}
