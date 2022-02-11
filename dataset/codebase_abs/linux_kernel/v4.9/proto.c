static const char * F_1 ( const int V_1 )
{
static const char * const V_2 [] = {
[ V_3 ] = L_1 ,
[ V_4 ] = L_2 ,
[ V_5 ] = L_3 ,
[ V_6 ] = L_4 ,
[ V_7 ] = L_5 ,
[ V_8 ] = L_6 ,
[ V_9 ] = L_7 ,
[ V_10 ] = L_8 ,
[ V_11 ] = L_9 ,
[ V_12 ] = L_10 ,
[ V_13 ] = L_11 ,
} ;
if ( V_1 >= V_14 )
return L_12 ;
else
return V_2 [ V_1 ] ;
}
void F_2 ( struct V_15 * V_16 , const int V_1 )
{
const int V_17 = V_16 -> V_18 ;
F_3 ( L_13 , F_4 ( V_16 ) , V_16 ,
F_1 ( V_17 ) , F_1 ( V_1 ) ) ;
F_5 ( V_1 == V_17 ) ;
switch ( V_1 ) {
case V_3 :
if ( V_17 != V_3 )
F_6 ( V_19 ) ;
if ( V_17 == V_5 )
F_7 ( & F_8 ( V_16 ) -> V_20 ) ;
break;
case V_13 :
if ( V_17 == V_3 || V_17 == V_9 ||
V_17 == V_8 )
F_6 ( V_21 ) ;
V_16 -> V_22 -> V_23 ( V_16 ) ;
if ( F_9 ( V_16 ) -> V_24 != NULL &&
! ( V_16 -> V_25 & V_26 ) )
F_10 ( V_16 ) ;
default:
if ( V_17 == V_3 )
F_11 ( V_19 ) ;
}
V_16 -> V_18 = V_1 ;
}
static void F_12 ( struct V_15 * V_16 )
{
switch ( V_16 -> V_18 ) {
case V_10 :
F_13 ( V_16 , V_27 ) ;
F_2 ( V_16 , V_13 ) ;
break;
case V_11 :
F_14 ( V_16 , 1 ) ;
F_2 ( V_16 , V_8 ) ;
}
}
void F_15 ( struct V_15 * V_16 )
{
F_2 ( V_16 , V_13 ) ;
F_16 ( V_16 ) ;
V_16 -> V_28 = V_29 ;
if ( ! F_17 ( V_16 , V_30 ) )
V_16 -> V_31 ( V_16 ) ;
else
F_18 ( V_16 ) ;
}
const char * F_19 ( const int type )
{
static const char * const V_32 [] = {
[ V_33 ] = L_14 ,
[ V_34 ] = L_15 ,
[ V_35 ] = L_16 ,
[ V_36 ] = L_17 ,
[ V_37 ] = L_18 ,
[ V_38 ] = L_7 ,
[ V_39 ] = L_19 ,
[ V_40 ] = L_20 ,
[ V_41 ] = L_21 ,
[ V_42 ] = L_22 ,
} ;
if ( type >= V_43 )
return L_23 ;
else
return V_32 [ type ] ;
}
int F_20 ( struct V_15 * V_16 , const T_1 V_44 )
{
struct V_45 * V_46 = F_8 ( V_16 ) ;
struct V_47 * V_48 = F_9 ( V_16 ) ;
V_48 -> V_49 = V_50 ;
V_48 -> V_51 = V_52 ;
V_16 -> V_18 = V_13 ;
V_16 -> V_53 = V_54 ;
V_48 -> V_55 = V_56 ;
V_46 -> V_57 = 536 ;
V_46 -> V_58 = V_59 ;
V_46 -> V_60 = V_61 ;
V_46 -> V_62 = V_63 ;
V_46 -> V_64 = V_65 ;
F_21 ( V_16 ) ;
F_22 ( & V_46 -> V_20 ) ;
if ( F_23 ( V_44 ) )
return F_24 ( V_16 ) ;
return 0 ;
}
void F_25 ( struct V_15 * V_16 )
{
struct V_45 * V_46 = F_8 ( V_16 ) ;
if ( V_16 -> V_66 != NULL ) {
F_26 ( V_16 -> V_66 ) ;
V_16 -> V_66 = NULL ;
}
if ( F_9 ( V_16 ) -> V_24 != NULL )
F_10 ( V_16 ) ;
F_27 ( V_46 -> V_67 ) ;
V_46 -> V_67 = NULL ;
if ( V_46 -> V_68 != NULL ) {
F_28 ( V_46 -> V_68 ) ;
V_46 -> V_68 = NULL ;
}
F_29 ( V_46 -> V_69 , V_16 ) ;
F_30 ( V_46 -> V_70 , V_16 ) ;
V_46 -> V_69 = V_46 -> V_70 = NULL ;
F_7 ( & V_46 -> V_20 ) ;
}
static inline int F_31 ( struct V_15 * V_16 , int V_71 )
{
struct V_45 * V_46 = F_8 ( V_16 ) ;
V_46 -> V_60 = V_72 ;
if ( F_32 ( V_46 ) )
return - V_73 ;
return F_33 ( V_16 , V_71 ) ;
}
static inline int F_34 ( int V_1 )
{
return V_1 != V_13 && V_1 != V_6 &&
V_1 != V_4 ;
}
int F_35 ( struct V_15 * V_16 , int V_74 )
{
struct V_47 * V_48 = F_9 ( V_16 ) ;
struct V_75 * V_76 = F_36 ( V_16 ) ;
int V_77 = 0 ;
const int V_78 = V_16 -> V_18 ;
if ( V_78 != V_13 )
F_2 ( V_16 , V_13 ) ;
if ( V_78 == V_6 ) {
F_37 ( V_16 ) ;
} else if ( F_34 ( V_78 ) ) {
F_13 ( V_16 , V_79 ) ;
V_16 -> V_80 = V_81 ;
} else if ( V_78 == V_4 )
V_16 -> V_80 = V_81 ;
F_16 ( V_16 ) ;
F_38 ( & V_16 -> V_82 ) ;
F_38 ( & V_16 -> V_83 ) ;
if ( V_16 -> V_66 != NULL ) {
F_39 ( V_16 -> V_66 ) ;
V_16 -> V_66 = NULL ;
}
V_76 -> V_84 = 0 ;
if ( ! ( V_16 -> V_25 & V_85 ) )
F_40 ( V_16 ) ;
V_16 -> V_28 = 0 ;
F_41 ( V_16 , V_86 ) ;
V_48 -> V_87 = 0 ;
F_42 ( V_16 ) ;
F_43 ( V_16 ) ;
F_5 ( V_76 -> V_88 && ! V_48 -> V_24 ) ;
V_16 -> V_89 ( V_16 ) ;
return V_77 ;
}
unsigned int F_44 ( struct V_90 * V_90 , struct V_91 * V_15 ,
T_2 * V_92 )
{
unsigned int V_93 ;
struct V_15 * V_16 = V_15 -> V_16 ;
F_45 ( V_90 , F_46 ( V_16 ) , V_92 ) ;
if ( V_16 -> V_18 == V_6 )
return F_47 ( V_16 ) ;
V_93 = 0 ;
if ( V_16 -> V_80 )
V_93 = V_94 ;
if ( V_16 -> V_28 == V_29 || V_16 -> V_18 == V_13 )
V_93 |= V_95 ;
if ( V_16 -> V_28 & V_96 )
V_93 |= V_97 | V_98 | V_99 ;
if ( ( 1 << V_16 -> V_18 ) & ~ ( V_100 | V_101 ) ) {
if ( F_48 ( & V_16 -> V_102 ) > 0 )
V_93 |= V_97 | V_98 ;
if ( ! ( V_16 -> V_28 & V_103 ) ) {
if ( F_49 ( V_16 ) ) {
V_93 |= V_104 | V_105 ;
} else {
F_50 ( V_106 , V_16 ) ;
F_51 ( V_107 , & V_16 -> V_108 -> V_74 ) ;
if ( F_49 ( V_16 ) )
V_93 |= V_104 | V_105 ;
}
}
}
return V_93 ;
}
int F_52 ( struct V_15 * V_16 , int V_109 , unsigned long V_110 )
{
int V_111 = - V_112 ;
F_53 ( V_16 ) ;
if ( V_16 -> V_18 == V_6 )
goto V_113;
switch ( V_109 ) {
case V_114 : {
struct V_115 * V_116 ;
unsigned long V_117 = 0 ;
V_116 = F_54 ( & V_16 -> V_82 ) ;
if ( V_116 != NULL ) {
V_117 = V_116 -> V_118 ;
}
V_111 = F_55 ( V_117 , ( int V_119 * ) V_110 ) ;
}
break;
default:
V_111 = - V_120 ;
break;
}
V_113:
F_56 ( V_16 ) ;
return V_111 ;
}
static int F_57 ( struct V_15 * V_16 , const T_3 V_121 ,
char V_119 * V_122 , unsigned int V_123 )
{
struct V_45 * V_46 = F_8 ( V_16 ) ;
struct V_124 * V_125 = NULL ;
if ( V_121 == V_126 ||
V_123 > V_127 * sizeof( V_128 ) )
return - V_129 ;
if ( V_123 > sizeof( V_121 ) ) {
V_125 = F_58 ( V_123 , V_130 ) ;
if ( V_125 == NULL )
return - V_131 ;
V_125 -> V_132 = V_123 / sizeof( V_128 ) - 1 ;
if ( F_59 ( V_125 -> V_133 ,
V_122 + sizeof( V_121 ) ,
V_123 - sizeof( V_121 ) ) ||
F_60 ( V_125 , V_126 ) ) {
F_27 ( V_125 ) ;
return - V_134 ;
}
}
F_53 ( V_16 ) ;
V_46 -> V_62 = V_121 ;
F_27 ( V_46 -> V_67 ) ;
V_46 -> V_67 = V_125 ;
F_56 ( V_16 ) ;
return 0 ;
}
static int F_61 ( struct V_15 * V_16 , int V_135 , bool V_136 )
{
T_4 * V_137 , V_118 ;
int V_138 , V_111 ;
if ( V_135 < 0 || V_135 > 15 )
return - V_129 ;
if ( V_135 == 0 )
return 0 ;
V_118 = 16 - V_135 ;
V_137 = F_58 ( V_118 , V_130 ) ;
if ( V_137 == NULL )
return - V_139 ;
for ( V_138 = 0 ; V_138 < V_118 ; V_138 ++ )
V_137 [ V_138 ] = V_135 ++ ;
V_111 = F_62 ( V_16 , V_140 , V_136 , V_137 , V_118 ) ;
if ( V_111 == 0 ) {
if ( V_136 )
F_8 ( V_16 ) -> V_141 = V_135 ;
else
F_8 ( V_16 ) -> V_142 = V_135 ;
}
F_27 ( V_137 ) ;
return V_111 ;
}
static int F_63 ( struct V_15 * V_16 , int type ,
char V_119 * V_122 , unsigned int V_123 )
{
T_4 * V_143 ;
int V_111 = 0 ;
if ( V_123 < 1 || V_123 > V_144 )
return - V_129 ;
V_143 = F_64 ( V_122 , V_123 ) ;
if ( F_65 ( V_143 ) )
return F_66 ( V_143 ) ;
F_53 ( V_16 ) ;
if ( type == V_145 || type == V_146 )
V_111 = F_62 ( V_16 , V_147 , 1 , V_143 , V_123 ) ;
if ( ! V_111 && ( type == V_148 || type == V_146 ) )
V_111 = F_62 ( V_16 , V_147 , 0 , V_143 , V_123 ) ;
F_56 ( V_16 ) ;
F_27 ( V_143 ) ;
return V_111 ;
}
static int F_67 ( struct V_15 * V_16 , int V_149 , int V_150 ,
char V_119 * V_122 , unsigned int V_123 )
{
struct V_45 * V_46 = F_8 ( V_16 ) ;
int V_143 , V_77 = 0 ;
switch ( V_150 ) {
case V_151 :
F_68 ( L_24 ) ;
return 0 ;
case V_152 :
case V_153 :
F_68 ( L_25 ) ;
return 0 ;
case V_146 :
case V_148 :
case V_145 :
return F_63 ( V_16 , V_150 , V_122 , V_123 ) ;
}
if ( V_123 < ( int ) sizeof( int ) )
return - V_129 ;
if ( F_69 ( V_143 , ( int V_119 * ) V_122 ) )
return - V_134 ;
if ( V_150 == V_154 )
return F_57 ( V_16 , V_143 , V_122 , V_123 ) ;
F_53 ( V_16 ) ;
switch ( V_150 ) {
case V_155 :
if ( V_46 -> V_60 != V_156 )
V_77 = - V_157 ;
else
V_46 -> V_158 = ( V_143 != 0 ) ;
break;
case V_159 :
V_77 = F_61 ( V_16 , V_143 , false ) ;
break;
case V_160 :
V_77 = F_61 ( V_16 , V_143 , true ) ;
break;
case V_161 :
if ( V_16 -> V_18 != V_13 )
V_77 = - V_162 ;
else if ( V_143 < 0 || V_143 >= V_163 )
V_77 = - V_129 ;
else
V_46 -> V_164 = V_143 ;
break;
case V_165 :
if ( V_143 < 0 )
V_77 = - V_129 ;
else
V_46 -> V_64 = V_143 ;
break;
default:
V_77 = - V_166 ;
break;
}
F_56 ( V_16 ) ;
return V_77 ;
}
int F_70 ( struct V_15 * V_16 , int V_149 , int V_150 ,
char V_119 * V_122 , unsigned int V_123 )
{
if ( V_149 != V_167 )
return F_9 ( V_16 ) -> V_168 -> V_169 ( V_16 , V_149 ,
V_150 , V_122 ,
V_123 ) ;
return F_67 ( V_16 , V_149 , V_150 , V_122 , V_123 ) ;
}
int F_71 ( struct V_15 * V_16 , int V_149 , int V_150 ,
char V_119 * V_122 , unsigned int V_123 )
{
if ( V_149 != V_167 )
return F_72 ( V_16 , V_149 , V_150 ,
V_122 , V_123 ) ;
return F_67 ( V_16 , V_149 , V_150 , V_122 , V_123 ) ;
}
static int F_73 ( struct V_15 * V_16 , int V_118 ,
T_3 V_119 * V_122 ,
int V_119 * V_123 )
{
const struct V_45 * V_46 = F_8 ( V_16 ) ;
const struct V_124 * V_125 ;
int V_77 = - V_170 , V_171 = 0 , V_172 = sizeof( V_128 ) ;
F_53 ( V_16 ) ;
if ( ( V_125 = V_46 -> V_67 ) != NULL ) {
V_171 = V_125 -> V_132 * sizeof( V_128 ) ;
V_172 += V_171 ;
}
V_77 = - V_129 ;
if ( V_172 > V_118 )
goto V_113;
V_77 = 0 ;
if ( F_55 ( V_172 , V_123 ) ||
F_55 ( V_46 -> V_62 , V_122 ) ||
( V_125 != NULL && F_74 ( V_122 + 1 , V_125 -> V_133 , V_171 ) ) )
V_77 = - V_134 ;
V_113:
F_56 ( V_16 ) ;
return V_77 ;
}
static int F_75 ( struct V_15 * V_16 , int V_149 , int V_150 ,
char V_119 * V_122 , int V_119 * V_123 )
{
struct V_45 * V_46 ;
int V_143 , V_118 ;
if ( F_69 ( V_118 , V_123 ) )
return - V_134 ;
if ( V_118 < ( int ) sizeof( int ) )
return - V_129 ;
V_46 = F_8 ( V_16 ) ;
switch ( V_150 ) {
case V_151 :
F_68 ( L_24 ) ;
return 0 ;
case V_154 :
return F_73 ( V_16 , V_118 ,
( T_3 V_119 * ) V_122 , V_123 ) ;
case V_173 :
V_143 = V_46 -> V_57 ;
break;
case V_174 :
return F_76 ( V_16 , V_118 , V_122 , V_123 ) ;
case V_145 :
V_143 = F_77 ( V_46 ) ;
if ( V_143 < 0 )
return - V_166 ;
break;
case V_148 :
V_143 = F_78 ( V_46 ) ;
if ( V_143 < 0 )
return - V_166 ;
break;
case V_155 :
V_143 = V_46 -> V_158 ;
break;
case V_159 :
V_143 = V_46 -> V_142 ;
break;
case V_160 :
V_143 = V_46 -> V_141 ;
break;
case V_161 :
V_143 = V_46 -> V_164 ;
break;
case V_165 :
V_143 = V_46 -> V_64 ;
break;
case 128 ... 191 :
return F_79 ( V_46 -> V_69 , V_16 , V_150 ,
V_118 , ( V_128 V_119 * ) V_122 , V_123 ) ;
case 192 ... 255 :
return F_80 ( V_46 -> V_70 , V_16 , V_150 ,
V_118 , ( V_128 V_119 * ) V_122 , V_123 ) ;
default:
return - V_166 ;
}
V_118 = sizeof( V_143 ) ;
if ( F_55 ( V_118 , V_123 ) || F_74 ( V_122 , & V_143 , V_118 ) )
return - V_134 ;
return 0 ;
}
int F_81 ( struct V_15 * V_16 , int V_149 , int V_150 ,
char V_119 * V_122 , int V_119 * V_123 )
{
if ( V_149 != V_167 )
return F_9 ( V_16 ) -> V_168 -> V_175 ( V_16 , V_149 ,
V_150 , V_122 ,
V_123 ) ;
return F_75 ( V_16 , V_149 , V_150 , V_122 , V_123 ) ;
}
int F_82 ( struct V_15 * V_16 , int V_149 , int V_150 ,
char V_119 * V_122 , int V_119 * V_123 )
{
if ( V_149 != V_167 )
return F_83 ( V_16 , V_149 , V_150 ,
V_122 , V_123 ) ;
return F_75 ( V_16 , V_149 , V_150 , V_122 , V_123 ) ;
}
static int F_84 ( struct V_176 * V_177 , struct V_115 * V_116 )
{
struct V_178 * V_179 ;
V_116 -> V_180 = 0 ;
F_85 (cmsg, msg) {
if ( ! F_86 ( V_177 , V_179 ) )
return - V_129 ;
if ( V_179 -> V_181 != V_167 )
continue;
if ( V_179 -> V_182 <= V_183 &&
! F_87 ( V_116 -> V_16 , V_179 -> V_182 ) )
return - V_129 ;
switch ( V_179 -> V_182 ) {
case V_184 :
if ( V_179 -> V_185 != F_88 ( sizeof( V_186 ) ) )
return - V_129 ;
V_116 -> V_180 = * ( V_186 * ) F_89 ( V_179 ) ;
break;
default:
return - V_129 ;
}
}
return 0 ;
}
int F_90 ( struct V_15 * V_16 , struct V_176 * V_177 , T_5 V_118 )
{
const struct V_45 * V_46 = F_8 ( V_16 ) ;
const int V_74 = V_177 -> V_187 ;
const int V_188 = V_74 & V_189 ;
struct V_115 * V_116 ;
int V_111 , V_190 ;
long V_191 ;
if ( V_118 > V_46 -> V_57 )
return - V_192 ;
F_53 ( V_16 ) ;
if ( F_91 ( V_16 ) ) {
V_111 = - V_193 ;
goto V_194;
}
V_191 = F_92 ( V_16 , V_188 ) ;
if ( ( 1 << V_16 -> V_18 ) & ~ ( V_195 | V_196 ) )
if ( ( V_111 = F_93 ( V_16 , & V_191 ) ) != 0 )
goto V_194;
V_190 = V_16 -> V_22 -> V_197 + V_118 ;
F_56 ( V_16 ) ;
V_116 = F_94 ( V_16 , V_190 , V_188 , & V_111 ) ;
F_53 ( V_16 ) ;
if ( V_116 == NULL )
goto V_194;
F_95 ( V_116 , V_16 -> V_22 -> V_197 ) ;
V_111 = F_96 ( F_97 ( V_116 , V_118 ) , V_177 , V_118 ) ;
if ( V_111 != 0 )
goto V_198;
V_111 = F_84 ( V_177 , V_116 ) ;
if ( V_111 != 0 )
goto V_198;
F_98 ( V_16 , V_116 ) ;
if ( ! F_99 ( & V_46 -> V_199 ) )
F_100 ( V_16 ) ;
V_194:
F_56 ( V_16 ) ;
return V_111 ? : V_118 ;
V_198:
F_26 ( V_116 ) ;
goto V_194;
}
int F_101 ( struct V_15 * V_16 , struct V_176 * V_177 , T_5 V_118 , int V_200 ,
int V_74 , int * V_201 )
{
const struct V_202 * V_203 ;
long V_191 ;
F_53 ( V_16 ) ;
if ( V_16 -> V_18 == V_6 ) {
V_118 = - V_112 ;
goto V_113;
}
V_191 = F_102 ( V_16 , V_200 ) ;
do {
struct V_115 * V_116 = F_54 ( & V_16 -> V_82 ) ;
if ( V_116 == NULL )
goto V_204;
V_203 = V_202 ( V_116 ) ;
switch ( V_203 -> V_205 ) {
case V_35 :
case V_37 :
goto V_206;
case V_39 :
case V_38 :
if ( ! ( V_74 & V_207 ) )
F_12 ( V_16 ) ;
case V_40 :
F_3 ( L_26 ,
F_19 ( V_203 -> V_205 ) ) ;
V_118 = 0 ;
goto V_208;
default:
F_3 ( L_27 ,
F_19 ( V_203 -> V_205 ) ) ;
F_103 ( V_16 , V_116 ) ;
}
V_204:
if ( F_17 ( V_16 , V_86 ) ) {
V_118 = 0 ;
break;
}
if ( V_16 -> V_80 ) {
V_118 = F_104 ( V_16 ) ;
break;
}
if ( V_16 -> V_28 & V_96 ) {
V_118 = 0 ;
break;
}
if ( V_16 -> V_18 == V_13 ) {
if ( ! F_17 ( V_16 , V_86 ) ) {
V_118 = - V_112 ;
break;
}
V_118 = 0 ;
break;
}
if ( ! V_191 ) {
V_118 = - V_193 ;
break;
}
if ( F_105 ( V_209 ) ) {
V_118 = F_106 ( V_191 ) ;
break;
}
F_107 ( V_16 , & V_191 , NULL ) ;
continue;
V_206:
if ( V_118 > V_116 -> V_118 )
V_118 = V_116 -> V_118 ;
else if ( V_118 < V_116 -> V_118 )
V_177 -> V_187 |= V_210 ;
if ( F_108 ( V_116 , 0 , V_177 , V_118 ) ) {
V_118 = - V_134 ;
break;
}
if ( V_74 & V_210 )
V_118 = V_116 -> V_118 ;
V_208:
if ( ! ( V_74 & V_207 ) )
F_103 ( V_16 , V_116 ) ;
break;
} while ( 1 );
V_113:
F_56 ( V_16 ) ;
return V_118 ;
}
int F_109 ( struct V_91 * V_15 , int V_71 )
{
struct V_15 * V_16 = V_15 -> V_16 ;
unsigned char V_78 ;
int V_77 ;
F_53 ( V_16 ) ;
V_77 = - V_129 ;
if ( V_15 -> V_1 != V_211 || V_15 -> type != V_212 )
goto V_113;
V_78 = V_16 -> V_18 ;
if ( ! ( ( 1 << V_78 ) & ( V_213 | V_214 ) ) )
goto V_113;
if ( V_78 != V_6 ) {
V_77 = F_31 ( V_16 , V_71 ) ;
if ( V_77 )
goto V_113;
}
V_16 -> V_215 = V_71 ;
V_77 = 0 ;
V_113:
F_56 ( V_16 ) ;
return V_77 ;
}
static void F_110 ( struct V_15 * V_16 )
{
T_4 V_216 = V_13 ;
switch ( V_16 -> V_18 ) {
case V_10 :
case V_11 :
F_12 ( V_16 ) ;
break;
case V_5 :
F_3 ( L_28 , V_16 ) ;
F_111 ( V_16 , V_217 ) ;
case V_3 :
F_14 ( V_16 , 1 ) ;
if ( F_8 ( V_16 ) -> V_60 == V_156 &&
! F_8 ( V_16 ) -> V_158 )
V_216 = V_9 ;
else
V_216 = V_8 ;
default:
F_2 ( V_16 , V_216 ) ;
}
}
void F_112 ( struct V_15 * V_16 , long V_218 )
{
struct V_45 * V_46 = F_8 ( V_16 ) ;
struct V_115 * V_116 ;
V_128 V_219 = 0 ;
int V_1 ;
F_53 ( V_16 ) ;
V_16 -> V_28 = V_29 ;
if ( V_16 -> V_18 == V_6 ) {
F_2 ( V_16 , V_13 ) ;
F_37 ( V_16 ) ;
goto V_220;
}
F_113 ( V_16 , & V_46 -> V_199 ) ;
while ( ( V_116 = F_114 ( & V_16 -> V_82 ) ) != NULL ) {
V_219 += V_116 -> V_118 ;
F_39 ( V_116 ) ;
}
if ( V_16 -> V_18 == V_13 )
goto V_220;
if ( V_219 ) {
F_68 ( L_29 , V_219 ) ;
F_13 ( V_16 , V_79 ) ;
F_2 ( V_16 , V_13 ) ;
} else if ( F_17 ( V_16 , V_221 ) && ! V_16 -> V_222 ) {
V_16 -> V_22 -> V_223 ( V_16 , 0 ) ;
} else if ( V_16 -> V_18 != V_13 ) {
F_115 ( V_16 , & V_218 ) ;
F_110 ( V_16 ) ;
}
F_38 ( & V_16 -> V_83 ) ;
F_116 ( V_16 , V_218 ) ;
V_220:
V_1 = V_16 -> V_18 ;
F_117 ( V_16 ) ;
F_118 ( V_16 ) ;
F_56 ( V_16 ) ;
F_119 () ;
F_120 ( V_16 ) ;
F_5 ( F_121 ( V_16 ) ) ;
F_122 ( V_16 -> V_22 -> V_224 ) ;
if ( V_1 != V_13 && V_16 -> V_18 == V_13 )
goto V_113;
if ( V_16 -> V_18 == V_13 )
F_18 ( V_16 ) ;
V_113:
F_123 ( V_16 ) ;
F_124 () ;
F_125 ( V_16 ) ;
}
void F_126 ( struct V_15 * V_16 , int V_225 )
{
F_3 ( L_30 , V_225 ) ;
}
static inline int T_6 F_127 ( void )
{
V_226 = F_128 ( struct V_227 ) ;
if ( ! V_226 )
return - V_131 ;
return 0 ;
}
static inline void F_129 ( void )
{
F_130 ( V_226 ) ;
}
static int T_6 F_131 ( void )
{
unsigned long V_228 ;
int V_229 , V_230 , V_138 ;
int V_111 ;
F_132 ( sizeof( struct V_231 ) >
F_133 ( struct V_115 , V_232 ) ) ;
V_111 = F_134 ( & V_233 , 0 , V_130 ) ;
if ( V_111 )
goto V_234;
V_111 = - V_139 ;
F_135 ( & V_235 ) ;
V_235 . V_236 =
F_136 ( L_31 ,
sizeof( struct V_237 ) , 0 ,
V_238 , NULL ) ;
if ( ! V_235 . V_236 )
goto V_239;
if ( V_240 >= ( 128 * 1024 ) )
V_228 = V_240 >> ( 21 - V_241 ) ;
else
V_228 = V_240 >> ( 23 - V_241 ) ;
if ( V_242 )
V_228 = ( V_242 *
sizeof( struct V_243 ) ) >> V_241 ;
for ( V_229 = 0 ; ( 1UL << V_229 ) < V_228 ; V_229 ++ )
;
do {
unsigned long V_244 = ( 1UL << V_229 ) * V_245 /
sizeof( struct V_243 ) ;
while ( V_244 & ( V_244 - 1 ) )
V_244 -- ;
V_235 . V_246 = V_244 - 1 ;
V_235 . V_247 = (struct V_243 * )
F_137 ( V_248 | V_249 , V_229 ) ;
} while ( ! V_235 . V_247 && -- V_229 > 0 );
if ( ! V_235 . V_247 ) {
F_138 ( L_32 ) ;
goto V_250;
}
for ( V_138 = 0 ; V_138 <= V_235 . V_246 ; V_138 ++ )
F_139 ( & V_235 . V_247 [ V_138 ] . V_251 , V_138 ) ;
if ( F_140 ( & V_235 ) )
goto V_252;
V_230 = V_229 ;
do {
V_235 . V_253 = ( 1UL << V_230 ) * V_245 /
sizeof( struct V_254 ) ;
if ( ( V_235 . V_253 > ( 64 * 1024 ) ) &&
V_230 > 0 )
continue;
V_235 . V_255 = (struct V_254 * )
F_137 ( V_248 | V_249 , V_230 ) ;
} while ( ! V_235 . V_255 && -- V_230 >= 0 );
if ( ! V_235 . V_255 ) {
F_138 ( L_33 ) ;
goto V_256;
}
for ( V_138 = 0 ; V_138 < V_235 . V_253 ; V_138 ++ ) {
F_141 ( & V_235 . V_255 [ V_138 ] . V_257 ) ;
F_142 ( & V_235 . V_255 [ V_138 ] . V_251 ) ;
}
V_111 = F_127 () ;
if ( V_111 )
goto V_258;
V_111 = F_143 () ;
if ( V_111 )
goto V_259;
V_111 = F_144 () ;
if ( V_111 )
goto V_260;
V_111 = F_145 () ;
if ( V_111 )
goto V_261;
F_146 () ;
return 0 ;
V_261:
F_147 () ;
V_260:
F_148 () ;
V_259:
F_129 () ;
V_258:
F_149 ( ( unsigned long ) V_235 . V_255 , V_230 ) ;
V_256:
F_150 ( & V_235 ) ;
V_252:
F_149 ( ( unsigned long ) V_235 . V_247 , V_229 ) ;
V_250:
F_151 ( V_235 . V_236 ) ;
V_239:
F_152 ( & V_233 ) ;
V_234:
V_235 . V_255 = NULL ;
V_235 . V_247 = NULL ;
V_235 . V_236 = NULL ;
return V_111 ;
}
static void T_7 F_153 ( void )
{
F_154 () ;
F_129 () ;
F_149 ( ( unsigned long ) V_235 . V_255 ,
F_155 ( V_235 . V_253 *
sizeof( struct V_254 ) ) ) ;
F_149 ( ( unsigned long ) V_235 . V_247 ,
F_155 ( ( V_235 . V_246 + 1 ) *
sizeof( struct V_243 ) ) ) ;
F_150 ( & V_235 ) ;
F_151 ( V_235 . V_236 ) ;
F_148 () ;
F_147 () ;
F_152 ( & V_233 ) ;
}
