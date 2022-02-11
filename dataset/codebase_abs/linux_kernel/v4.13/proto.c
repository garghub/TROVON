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
static void F_20 ( struct V_15 * V_16 )
{
struct V_44 * V_45 = F_8 ( V_16 ) ;
F_21 ( V_45 -> V_46 , V_16 ) ;
V_45 -> V_46 = NULL ;
F_22 ( V_16 ) ;
}
int F_23 ( struct V_15 * V_16 , const T_1 V_47 )
{
struct V_44 * V_45 = F_8 ( V_16 ) ;
struct V_48 * V_49 = F_9 ( V_16 ) ;
V_49 -> V_50 = V_51 ;
V_49 -> V_52 = V_53 ;
V_16 -> V_18 = V_13 ;
V_16 -> V_54 = V_55 ;
V_16 -> V_56 = F_20 ;
V_49 -> V_57 = V_58 ;
V_45 -> V_59 = 536 ;
V_45 -> V_60 = V_61 ;
V_45 -> V_62 = V_63 ;
V_45 -> V_64 = V_65 ;
V_45 -> V_66 = V_67 ;
F_24 ( V_16 ) ;
F_25 ( & V_45 -> V_20 ) ;
if ( F_26 ( V_47 ) )
return F_27 ( V_16 ) ;
return 0 ;
}
void F_28 ( struct V_15 * V_16 )
{
struct V_44 * V_45 = F_8 ( V_16 ) ;
F_29 ( & V_16 -> V_68 ) ;
if ( V_16 -> V_69 != NULL ) {
F_30 ( V_16 -> V_69 ) ;
V_16 -> V_69 = NULL ;
}
if ( F_9 ( V_16 ) -> V_24 != NULL )
F_10 ( V_16 ) ;
F_31 ( V_45 -> V_70 ) ;
V_45 -> V_70 = NULL ;
if ( V_45 -> V_71 != NULL ) {
F_32 ( V_45 -> V_71 ) ;
V_45 -> V_71 = NULL ;
}
F_33 ( V_45 -> V_72 , V_16 ) ;
V_45 -> V_72 = NULL ;
F_7 ( & V_45 -> V_20 ) ;
}
static inline int F_34 ( struct V_15 * V_16 , int V_73 )
{
struct V_44 * V_45 = F_8 ( V_16 ) ;
V_45 -> V_62 = V_74 ;
if ( F_35 ( V_45 ) )
return - V_75 ;
return F_36 ( V_16 , V_73 ) ;
}
static inline int F_37 ( int V_1 )
{
return V_1 != V_13 && V_1 != V_6 &&
V_1 != V_4 ;
}
int F_38 ( struct V_15 * V_16 , int V_76 )
{
struct V_48 * V_49 = F_9 ( V_16 ) ;
struct V_77 * V_78 = F_39 ( V_16 ) ;
int V_79 = 0 ;
const int V_80 = V_16 -> V_18 ;
if ( V_80 != V_13 )
F_2 ( V_16 , V_13 ) ;
if ( V_80 == V_6 ) {
F_40 ( V_16 ) ;
} else if ( F_37 ( V_80 ) ) {
F_13 ( V_16 , V_81 ) ;
V_16 -> V_82 = V_83 ;
} else if ( V_80 == V_4 )
V_16 -> V_82 = V_83 ;
F_16 ( V_16 ) ;
F_29 ( & V_16 -> V_84 ) ;
F_29 ( & V_16 -> V_68 ) ;
if ( V_16 -> V_69 != NULL ) {
F_41 ( V_16 -> V_69 ) ;
V_16 -> V_69 = NULL ;
}
V_78 -> V_85 = 0 ;
if ( ! ( V_16 -> V_25 & V_86 ) )
F_42 ( V_16 ) ;
V_16 -> V_28 = 0 ;
F_43 ( V_16 , V_87 ) ;
V_49 -> V_88 = 0 ;
F_44 ( V_16 ) ;
F_45 ( V_16 ) ;
F_5 ( V_78 -> V_89 && ! V_49 -> V_24 ) ;
V_16 -> V_90 ( V_16 ) ;
return V_79 ;
}
unsigned int F_46 ( struct V_91 * V_91 , struct V_92 * V_15 ,
T_2 * V_93 )
{
unsigned int V_94 ;
struct V_15 * V_16 = V_15 -> V_16 ;
F_47 ( V_91 , F_48 ( V_16 ) , V_93 ) ;
if ( V_16 -> V_18 == V_6 )
return F_49 ( V_16 ) ;
V_94 = 0 ;
if ( V_16 -> V_82 )
V_94 = V_95 ;
if ( V_16 -> V_28 == V_29 || V_16 -> V_18 == V_13 )
V_94 |= V_96 ;
if ( V_16 -> V_28 & V_97 )
V_94 |= V_98 | V_99 | V_100 ;
if ( ( 1 << V_16 -> V_18 ) & ~ ( V_101 | V_102 ) ) {
if ( F_50 ( & V_16 -> V_103 ) > 0 )
V_94 |= V_98 | V_99 ;
if ( ! ( V_16 -> V_28 & V_104 ) ) {
if ( F_51 ( V_16 ) ) {
V_94 |= V_105 | V_106 ;
} else {
F_52 ( V_107 , V_16 ) ;
F_53 ( V_108 , & V_16 -> V_109 -> V_76 ) ;
if ( F_51 ( V_16 ) )
V_94 |= V_105 | V_106 ;
}
}
}
return V_94 ;
}
int F_54 ( struct V_15 * V_16 , int V_110 , unsigned long V_111 )
{
int V_112 = - V_113 ;
F_55 ( V_16 ) ;
if ( V_16 -> V_18 == V_6 )
goto V_114;
switch ( V_110 ) {
case V_115 : {
struct V_116 * V_117 ;
unsigned long V_118 = 0 ;
V_117 = F_56 ( & V_16 -> V_84 ) ;
if ( V_117 != NULL ) {
V_118 = V_117 -> V_119 ;
}
V_112 = F_57 ( V_118 , ( int V_120 * ) V_111 ) ;
}
break;
default:
V_112 = - V_121 ;
break;
}
V_114:
F_58 ( V_16 ) ;
return V_112 ;
}
static int F_59 ( struct V_15 * V_16 , const T_3 V_122 ,
char V_120 * V_123 , unsigned int V_124 )
{
struct V_44 * V_45 = F_8 ( V_16 ) ;
struct V_125 * V_126 = NULL ;
if ( V_122 == V_127 ||
V_124 > V_128 * sizeof( V_129 ) )
return - V_130 ;
if ( V_124 > sizeof( V_122 ) ) {
V_126 = F_60 ( V_124 , V_131 ) ;
if ( V_126 == NULL )
return - V_132 ;
V_126 -> V_133 = V_124 / sizeof( V_129 ) - 1 ;
if ( F_61 ( V_126 -> V_134 ,
V_123 + sizeof( V_122 ) ,
V_124 - sizeof( V_122 ) ) ||
F_62 ( V_126 , V_127 ) ) {
F_31 ( V_126 ) ;
return - V_135 ;
}
}
F_55 ( V_16 ) ;
V_45 -> V_64 = V_122 ;
F_31 ( V_45 -> V_70 ) ;
V_45 -> V_70 = V_126 ;
F_58 ( V_16 ) ;
return 0 ;
}
static int F_63 ( struct V_15 * V_16 , int V_136 , bool V_137 )
{
T_4 * V_138 , V_119 ;
int V_139 , V_112 ;
if ( V_136 < 0 || V_136 > 15 )
return - V_130 ;
if ( V_136 == 0 )
return 0 ;
V_119 = 16 - V_136 ;
V_138 = F_60 ( V_119 , V_131 ) ;
if ( V_138 == NULL )
return - V_140 ;
for ( V_139 = 0 ; V_139 < V_119 ; V_139 ++ )
V_138 [ V_139 ] = V_136 ++ ;
V_112 = F_64 ( V_16 , V_141 , V_137 , V_138 , V_119 ) ;
if ( V_112 == 0 ) {
if ( V_137 )
F_8 ( V_16 ) -> V_142 = V_136 ;
else
F_8 ( V_16 ) -> V_143 = V_136 ;
}
F_31 ( V_138 ) ;
return V_112 ;
}
static int F_65 ( struct V_15 * V_16 , int type ,
char V_120 * V_123 , unsigned int V_124 )
{
T_4 * V_144 ;
int V_112 = 0 ;
if ( V_124 < 1 || V_124 > V_145 )
return - V_130 ;
V_144 = F_66 ( V_123 , V_124 ) ;
if ( F_67 ( V_144 ) )
return F_68 ( V_144 ) ;
F_55 ( V_16 ) ;
if ( type == V_146 || type == V_147 )
V_112 = F_64 ( V_16 , V_148 , 1 , V_144 , V_124 ) ;
if ( ! V_112 && ( type == V_149 || type == V_147 ) )
V_112 = F_64 ( V_16 , V_148 , 0 , V_144 , V_124 ) ;
F_58 ( V_16 ) ;
F_31 ( V_144 ) ;
return V_112 ;
}
static int F_69 ( struct V_15 * V_16 , int V_150 , int V_151 ,
char V_120 * V_123 , unsigned int V_124 )
{
struct V_44 * V_45 = F_8 ( V_16 ) ;
int V_144 , V_79 = 0 ;
switch ( V_151 ) {
case V_152 :
F_70 ( L_24 ) ;
return 0 ;
case V_153 :
case V_154 :
F_70 ( L_25 ) ;
return 0 ;
case V_147 :
case V_149 :
case V_146 :
return F_65 ( V_16 , V_151 , V_123 , V_124 ) ;
}
if ( V_124 < ( int ) sizeof( int ) )
return - V_130 ;
if ( F_71 ( V_144 , ( int V_120 * ) V_123 ) )
return - V_135 ;
if ( V_151 == V_155 )
return F_59 ( V_16 , V_144 , V_123 , V_124 ) ;
F_55 ( V_16 ) ;
switch ( V_151 ) {
case V_156 :
if ( V_45 -> V_62 != V_157 )
V_79 = - V_158 ;
else
V_45 -> V_159 = ( V_144 != 0 ) ;
break;
case V_160 :
V_79 = F_63 ( V_16 , V_144 , false ) ;
break;
case V_161 :
V_79 = F_63 ( V_16 , V_144 , true ) ;
break;
case V_162 :
if ( V_16 -> V_18 != V_13 )
V_79 = - V_163 ;
else if ( V_144 < 0 || V_144 >= V_164 )
V_79 = - V_130 ;
else
V_45 -> V_165 = V_144 ;
break;
case V_166 :
if ( V_144 < 0 )
V_79 = - V_130 ;
else
V_45 -> V_66 = V_144 ;
break;
default:
V_79 = - V_167 ;
break;
}
F_58 ( V_16 ) ;
return V_79 ;
}
int F_72 ( struct V_15 * V_16 , int V_150 , int V_151 ,
char V_120 * V_123 , unsigned int V_124 )
{
if ( V_150 != V_168 )
return F_9 ( V_16 ) -> V_169 -> V_170 ( V_16 , V_150 ,
V_151 , V_123 ,
V_124 ) ;
return F_69 ( V_16 , V_150 , V_151 , V_123 , V_124 ) ;
}
int F_73 ( struct V_15 * V_16 , int V_150 , int V_151 ,
char V_120 * V_123 , unsigned int V_124 )
{
if ( V_150 != V_168 )
return F_74 ( V_16 , V_150 , V_151 ,
V_123 , V_124 ) ;
return F_69 ( V_16 , V_150 , V_151 , V_123 , V_124 ) ;
}
static int F_75 ( struct V_15 * V_16 , int V_119 ,
T_3 V_120 * V_123 ,
int V_120 * V_124 )
{
const struct V_44 * V_45 = F_8 ( V_16 ) ;
const struct V_125 * V_126 ;
int V_79 = - V_171 , V_172 = 0 , V_173 = sizeof( V_129 ) ;
F_55 ( V_16 ) ;
if ( ( V_126 = V_45 -> V_70 ) != NULL ) {
V_172 = V_126 -> V_133 * sizeof( V_129 ) ;
V_173 += V_172 ;
}
V_79 = - V_130 ;
if ( V_173 > V_119 )
goto V_114;
V_79 = 0 ;
if ( F_57 ( V_173 , V_124 ) ||
F_57 ( V_45 -> V_64 , V_123 ) ||
( V_126 != NULL && F_76 ( V_123 + 1 , V_126 -> V_134 , V_172 ) ) )
V_79 = - V_135 ;
V_114:
F_58 ( V_16 ) ;
return V_79 ;
}
static int F_77 ( struct V_15 * V_16 , int V_150 , int V_151 ,
char V_120 * V_123 , int V_120 * V_124 )
{
struct V_44 * V_45 ;
int V_144 , V_119 ;
if ( F_71 ( V_119 , V_124 ) )
return - V_135 ;
if ( V_119 < ( int ) sizeof( int ) )
return - V_130 ;
V_45 = F_8 ( V_16 ) ;
switch ( V_151 ) {
case V_152 :
F_70 ( L_24 ) ;
return 0 ;
case V_155 :
return F_75 ( V_16 , V_119 ,
( T_3 V_120 * ) V_123 , V_124 ) ;
case V_174 :
V_144 = V_45 -> V_59 ;
break;
case V_175 :
return F_78 ( V_16 , V_119 , V_123 , V_124 ) ;
case V_146 :
V_144 = F_79 ( V_45 ) ;
if ( V_144 < 0 )
return - V_167 ;
break;
case V_149 :
V_144 = F_80 ( V_45 ) ;
if ( V_144 < 0 )
return - V_167 ;
break;
case V_156 :
V_144 = V_45 -> V_159 ;
break;
case V_160 :
V_144 = V_45 -> V_143 ;
break;
case V_161 :
V_144 = V_45 -> V_142 ;
break;
case V_162 :
V_144 = V_45 -> V_165 ;
break;
case V_166 :
V_144 = V_45 -> V_66 ;
break;
case 128 ... 191 :
return F_81 ( V_45 -> V_72 , V_16 , V_151 ,
V_119 , ( V_129 V_120 * ) V_123 , V_124 ) ;
case 192 ... 255 :
return F_82 ( V_45 -> V_46 , V_16 , V_151 ,
V_119 , ( V_129 V_120 * ) V_123 , V_124 ) ;
default:
return - V_167 ;
}
V_119 = sizeof( V_144 ) ;
if ( F_57 ( V_119 , V_124 ) || F_76 ( V_123 , & V_144 , V_119 ) )
return - V_135 ;
return 0 ;
}
int F_83 ( struct V_15 * V_16 , int V_150 , int V_151 ,
char V_120 * V_123 , int V_120 * V_124 )
{
if ( V_150 != V_168 )
return F_9 ( V_16 ) -> V_169 -> V_176 ( V_16 , V_150 ,
V_151 , V_123 ,
V_124 ) ;
return F_77 ( V_16 , V_150 , V_151 , V_123 , V_124 ) ;
}
int F_84 ( struct V_15 * V_16 , int V_150 , int V_151 ,
char V_120 * V_123 , int V_120 * V_124 )
{
if ( V_150 != V_168 )
return F_85 ( V_16 , V_150 , V_151 ,
V_123 , V_124 ) ;
return F_77 ( V_16 , V_150 , V_151 , V_123 , V_124 ) ;
}
static int F_86 ( struct V_177 * V_178 , struct V_116 * V_117 )
{
struct V_179 * V_180 ;
V_117 -> V_181 = 0 ;
F_87 (cmsg, msg) {
if ( ! F_88 ( V_178 , V_180 ) )
return - V_130 ;
if ( V_180 -> V_182 != V_168 )
continue;
if ( V_180 -> V_183 <= V_184 &&
! F_89 ( V_117 -> V_16 , V_180 -> V_183 ) )
return - V_130 ;
switch ( V_180 -> V_183 ) {
case V_185 :
if ( V_180 -> V_186 != F_90 ( sizeof( V_187 ) ) )
return - V_130 ;
V_117 -> V_181 = * ( V_187 * ) F_91 ( V_180 ) ;
break;
default:
return - V_130 ;
}
}
return 0 ;
}
int F_92 ( struct V_15 * V_16 , struct V_177 * V_178 , T_5 V_119 )
{
const struct V_44 * V_45 = F_8 ( V_16 ) ;
const int V_76 = V_178 -> V_188 ;
const int V_189 = V_76 & V_190 ;
struct V_116 * V_117 ;
int V_112 , V_191 ;
long V_192 ;
if ( V_119 > V_45 -> V_59 )
return - V_193 ;
F_55 ( V_16 ) ;
if ( F_93 ( V_16 ) ) {
V_112 = - V_194 ;
goto V_195;
}
V_192 = F_94 ( V_16 , V_189 ) ;
if ( ( 1 << V_16 -> V_18 ) & ~ ( V_196 | V_197 ) )
if ( ( V_112 = F_95 ( V_16 , & V_192 ) ) != 0 )
goto V_195;
V_191 = V_16 -> V_22 -> V_198 + V_119 ;
F_58 ( V_16 ) ;
V_117 = F_96 ( V_16 , V_191 , V_189 , & V_112 ) ;
F_55 ( V_16 ) ;
if ( V_117 == NULL )
goto V_195;
F_97 ( V_117 , V_16 -> V_22 -> V_198 ) ;
V_112 = F_98 ( F_99 ( V_117 , V_119 ) , V_178 , V_119 ) ;
if ( V_112 != 0 )
goto V_199;
V_112 = F_86 ( V_178 , V_117 ) ;
if ( V_112 != 0 )
goto V_199;
F_100 ( V_16 , V_117 ) ;
if ( ! F_101 ( & V_45 -> V_200 ) )
F_102 ( V_16 ) ;
V_195:
F_58 ( V_16 ) ;
return V_112 ? : V_119 ;
V_199:
F_30 ( V_117 ) ;
goto V_195;
}
int F_103 ( struct V_15 * V_16 , struct V_177 * V_178 , T_5 V_119 , int V_201 ,
int V_76 , int * V_202 )
{
const struct V_203 * V_204 ;
long V_192 ;
F_55 ( V_16 ) ;
if ( V_16 -> V_18 == V_6 ) {
V_119 = - V_113 ;
goto V_114;
}
V_192 = F_104 ( V_16 , V_201 ) ;
do {
struct V_116 * V_117 = F_56 ( & V_16 -> V_84 ) ;
if ( V_117 == NULL )
goto V_205;
V_204 = V_203 ( V_117 ) ;
switch ( V_204 -> V_206 ) {
case V_35 :
case V_37 :
goto V_207;
case V_39 :
case V_38 :
if ( ! ( V_76 & V_208 ) )
F_12 ( V_16 ) ;
case V_40 :
F_3 ( L_26 ,
F_19 ( V_204 -> V_206 ) ) ;
V_119 = 0 ;
goto V_209;
default:
F_3 ( L_27 ,
F_19 ( V_204 -> V_206 ) ) ;
F_105 ( V_16 , V_117 ) ;
}
V_205:
if ( F_17 ( V_16 , V_87 ) ) {
V_119 = 0 ;
break;
}
if ( V_16 -> V_82 ) {
V_119 = F_106 ( V_16 ) ;
break;
}
if ( V_16 -> V_28 & V_97 ) {
V_119 = 0 ;
break;
}
if ( V_16 -> V_18 == V_13 ) {
if ( ! F_17 ( V_16 , V_87 ) ) {
V_119 = - V_113 ;
break;
}
V_119 = 0 ;
break;
}
if ( ! V_192 ) {
V_119 = - V_194 ;
break;
}
if ( F_107 ( V_210 ) ) {
V_119 = F_108 ( V_192 ) ;
break;
}
F_109 ( V_16 , & V_192 , NULL ) ;
continue;
V_207:
if ( V_119 > V_117 -> V_119 )
V_119 = V_117 -> V_119 ;
else if ( V_119 < V_117 -> V_119 )
V_178 -> V_188 |= V_211 ;
if ( F_110 ( V_117 , 0 , V_178 , V_119 ) ) {
V_119 = - V_135 ;
break;
}
if ( V_76 & V_211 )
V_119 = V_117 -> V_119 ;
V_209:
if ( ! ( V_76 & V_208 ) )
F_105 ( V_16 , V_117 ) ;
break;
} while ( 1 );
V_114:
F_58 ( V_16 ) ;
return V_119 ;
}
int F_111 ( struct V_92 * V_15 , int V_73 )
{
struct V_15 * V_16 = V_15 -> V_16 ;
unsigned char V_80 ;
int V_79 ;
F_55 ( V_16 ) ;
V_79 = - V_130 ;
if ( V_15 -> V_1 != V_212 || V_15 -> type != V_213 )
goto V_114;
V_80 = V_16 -> V_18 ;
if ( ! ( ( 1 << V_80 ) & ( V_214 | V_215 ) ) )
goto V_114;
if ( V_80 != V_6 ) {
V_79 = F_34 ( V_16 , V_73 ) ;
if ( V_79 )
goto V_114;
}
V_16 -> V_216 = V_73 ;
V_79 = 0 ;
V_114:
F_58 ( V_16 ) ;
return V_79 ;
}
static void F_112 ( struct V_15 * V_16 )
{
T_4 V_217 = V_13 ;
switch ( V_16 -> V_18 ) {
case V_10 :
case V_11 :
F_12 ( V_16 ) ;
break;
case V_5 :
F_3 ( L_28 , V_16 ) ;
F_113 ( V_16 , V_218 ) ;
case V_3 :
F_14 ( V_16 , 1 ) ;
if ( F_8 ( V_16 ) -> V_62 == V_157 &&
! F_8 ( V_16 ) -> V_159 )
V_217 = V_9 ;
else
V_217 = V_8 ;
default:
F_2 ( V_16 , V_217 ) ;
}
}
void F_114 ( struct V_15 * V_16 , long V_219 )
{
struct V_44 * V_45 = F_8 ( V_16 ) ;
struct V_116 * V_117 ;
V_129 V_220 = 0 ;
int V_1 ;
F_55 ( V_16 ) ;
V_16 -> V_28 = V_29 ;
if ( V_16 -> V_18 == V_6 ) {
F_2 ( V_16 , V_13 ) ;
F_40 ( V_16 ) ;
goto V_221;
}
F_115 ( V_16 , & V_45 -> V_200 ) ;
while ( ( V_117 = F_116 ( & V_16 -> V_84 ) ) != NULL ) {
V_220 += V_117 -> V_119 ;
F_41 ( V_117 ) ;
}
if ( V_16 -> V_18 == V_13 )
goto V_221;
if ( V_220 ) {
F_70 ( L_29 , V_220 ) ;
F_13 ( V_16 , V_81 ) ;
F_2 ( V_16 , V_13 ) ;
} else if ( F_17 ( V_16 , V_222 ) && ! V_16 -> V_223 ) {
V_16 -> V_22 -> V_224 ( V_16 , 0 ) ;
} else if ( V_16 -> V_18 != V_13 ) {
F_117 ( V_16 , & V_219 ) ;
F_112 ( V_16 ) ;
}
F_29 ( & V_16 -> V_68 ) ;
F_118 ( V_16 , V_219 ) ;
V_221:
V_1 = V_16 -> V_18 ;
F_119 ( V_16 ) ;
F_120 ( V_16 ) ;
F_58 ( V_16 ) ;
F_121 () ;
F_122 ( V_16 ) ;
F_5 ( F_123 ( V_16 ) ) ;
F_124 ( V_16 -> V_22 -> V_225 ) ;
if ( V_1 != V_13 && V_16 -> V_18 == V_13 )
goto V_114;
if ( V_16 -> V_18 == V_13 )
F_18 ( V_16 ) ;
V_114:
F_125 ( V_16 ) ;
F_126 () ;
F_127 ( V_16 ) ;
}
void F_128 ( struct V_15 * V_16 , int V_226 )
{
F_3 ( L_30 , V_226 ) ;
}
static inline int T_6 F_129 ( void )
{
V_227 = F_130 ( struct V_228 ) ;
if ( ! V_227 )
return - V_132 ;
return 0 ;
}
static inline void F_131 ( void )
{
F_132 ( V_227 ) ;
}
static int T_6 F_133 ( void )
{
unsigned long V_229 ;
int V_230 , V_231 , V_139 ;
int V_112 ;
F_134 ( sizeof( struct V_232 ) >
F_135 ( struct V_116 , V_233 ) ) ;
V_112 = F_136 ( & V_234 , 0 , V_131 ) ;
if ( V_112 )
goto V_235;
V_112 = - V_140 ;
F_137 ( & V_236 ) ;
V_236 . V_237 =
F_138 ( L_31 ,
sizeof( struct V_238 ) , 0 ,
V_239 , NULL ) ;
if ( ! V_236 . V_237 )
goto V_240;
if ( V_241 >= ( 128 * 1024 ) )
V_229 = V_241 >> ( 21 - V_242 ) ;
else
V_229 = V_241 >> ( 23 - V_242 ) ;
if ( V_243 )
V_229 = ( V_243 *
sizeof( struct V_244 ) ) >> V_242 ;
for ( V_230 = 0 ; ( 1UL << V_230 ) < V_229 ; V_230 ++ )
;
do {
unsigned long V_245 = ( 1UL << V_230 ) * V_246 /
sizeof( struct V_244 ) ;
while ( V_245 & ( V_245 - 1 ) )
V_245 -- ;
V_236 . V_247 = V_245 - 1 ;
V_236 . V_248 = (struct V_244 * )
F_139 ( V_249 | V_250 , V_230 ) ;
} while ( ! V_236 . V_248 && -- V_230 > 0 );
if ( ! V_236 . V_248 ) {
F_140 ( L_32 ) ;
goto V_251;
}
for ( V_139 = 0 ; V_139 <= V_236 . V_247 ; V_139 ++ )
F_141 ( & V_236 . V_248 [ V_139 ] . V_252 , V_139 ) ;
if ( F_142 ( & V_236 ) )
goto V_253;
V_231 = V_230 ;
do {
V_236 . V_254 = ( 1UL << V_231 ) * V_246 /
sizeof( struct V_255 ) ;
if ( ( V_236 . V_254 > ( 64 * 1024 ) ) &&
V_231 > 0 )
continue;
V_236 . V_256 = (struct V_255 * )
F_139 ( V_249 | V_250 , V_231 ) ;
} while ( ! V_236 . V_256 && -- V_231 >= 0 );
if ( ! V_236 . V_256 ) {
F_140 ( L_33 ) ;
goto V_257;
}
for ( V_139 = 0 ; V_139 < V_236 . V_254 ; V_139 ++ ) {
F_143 ( & V_236 . V_256 [ V_139 ] . V_258 ) ;
F_144 ( & V_236 . V_256 [ V_139 ] . V_252 ) ;
}
V_112 = F_129 () ;
if ( V_112 )
goto V_259;
V_112 = F_145 () ;
if ( V_112 )
goto V_260;
V_112 = F_146 () ;
if ( V_112 )
goto V_261;
V_112 = F_147 () ;
if ( V_112 )
goto V_262;
F_148 () ;
return 0 ;
V_262:
F_149 () ;
V_261:
F_150 () ;
V_260:
F_131 () ;
V_259:
F_151 ( ( unsigned long ) V_236 . V_256 , V_231 ) ;
V_257:
F_152 ( & V_236 ) ;
V_253:
F_151 ( ( unsigned long ) V_236 . V_248 , V_230 ) ;
V_251:
F_153 ( V_236 . V_237 ) ;
V_240:
F_154 ( & V_234 ) ;
V_235:
V_236 . V_256 = NULL ;
V_236 . V_248 = NULL ;
V_236 . V_237 = NULL ;
return V_112 ;
}
static void T_7 F_155 ( void )
{
F_156 () ;
F_131 () ;
F_151 ( ( unsigned long ) V_236 . V_256 ,
F_157 ( V_236 . V_254 *
sizeof( struct V_255 ) ) ) ;
F_151 ( ( unsigned long ) V_236 . V_248 ,
F_157 ( ( V_236 . V_247 + 1 ) *
sizeof( struct V_244 ) ) ) ;
F_152 ( & V_236 ) ;
F_153 ( V_236 . V_237 ) ;
F_150 () ;
F_149 () ;
F_154 ( & V_234 ) ;
}
