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
V_46 -> V_64 = V_46 -> V_65 = 1 ;
V_46 -> V_66 = V_67 ;
F_21 ( V_16 ) ;
F_22 ( & V_46 -> V_20 ) ;
if ( F_23 ( V_44 ) )
return F_24 ( V_16 ) ;
return 0 ;
}
void F_25 ( struct V_15 * V_16 )
{
struct V_45 * V_46 = F_8 ( V_16 ) ;
if ( V_16 -> V_68 != NULL ) {
F_26 ( V_16 -> V_68 ) ;
V_16 -> V_68 = NULL ;
}
if ( F_9 ( V_16 ) -> V_24 != NULL )
F_10 ( V_16 ) ;
F_27 ( V_46 -> V_69 ) ;
V_46 -> V_69 = NULL ;
if ( V_46 -> V_70 != NULL ) {
F_28 ( V_46 -> V_70 ) ;
V_46 -> V_70 = NULL ;
}
F_29 ( V_46 -> V_71 , V_16 ) ;
F_30 ( V_46 -> V_72 , V_16 ) ;
V_46 -> V_71 = V_46 -> V_72 = NULL ;
F_7 ( & V_46 -> V_20 ) ;
}
static inline int F_31 ( struct V_15 * V_16 , int V_73 )
{
struct V_45 * V_46 = F_8 ( V_16 ) ;
V_46 -> V_60 = V_74 ;
if ( F_32 ( V_46 ) )
return - V_75 ;
return F_33 ( V_16 , V_73 ) ;
}
static inline int F_34 ( int V_1 )
{
return V_1 != V_13 && V_1 != V_6 &&
V_1 != V_4 ;
}
int F_35 ( struct V_15 * V_16 , int V_76 )
{
struct V_47 * V_48 = F_9 ( V_16 ) ;
struct V_77 * V_78 = F_36 ( V_16 ) ;
int V_79 = 0 ;
const int V_80 = V_16 -> V_18 ;
if ( V_80 != V_13 )
F_2 ( V_16 , V_13 ) ;
if ( V_80 == V_6 ) {
F_37 ( V_16 ) ;
} else if ( F_34 ( V_80 ) ) {
F_13 ( V_16 , V_81 ) ;
V_16 -> V_82 = V_83 ;
} else if ( V_80 == V_4 )
V_16 -> V_82 = V_83 ;
F_16 ( V_16 ) ;
F_38 ( & V_16 -> V_84 ) ;
F_38 ( & V_16 -> V_85 ) ;
if ( V_16 -> V_68 != NULL ) {
F_39 ( V_16 -> V_68 ) ;
V_16 -> V_68 = NULL ;
}
V_78 -> V_86 = 0 ;
if ( ! ( V_16 -> V_25 & V_87 ) )
F_40 ( V_16 ) ;
V_16 -> V_28 = 0 ;
F_41 ( V_16 , V_88 ) ;
V_48 -> V_89 = 0 ;
F_42 ( V_16 ) ;
F_43 ( V_16 ) ;
F_5 ( V_78 -> V_90 && ! V_48 -> V_24 ) ;
V_16 -> V_91 ( V_16 ) ;
return V_79 ;
}
unsigned int F_44 ( struct V_92 * V_92 , struct V_93 * V_15 ,
T_2 * V_94 )
{
unsigned int V_95 ;
struct V_15 * V_16 = V_15 -> V_16 ;
F_45 ( V_92 , F_46 ( V_16 ) , V_94 ) ;
if ( V_16 -> V_18 == V_6 )
return F_47 ( V_16 ) ;
V_95 = 0 ;
if ( V_16 -> V_82 )
V_95 = V_96 ;
if ( V_16 -> V_28 == V_29 || V_16 -> V_18 == V_13 )
V_95 |= V_97 ;
if ( V_16 -> V_28 & V_98 )
V_95 |= V_99 | V_100 | V_101 ;
if ( ( 1 << V_16 -> V_18 ) & ~ ( V_102 | V_103 ) ) {
if ( F_48 ( & V_16 -> V_104 ) > 0 )
V_95 |= V_99 | V_100 ;
if ( ! ( V_16 -> V_28 & V_105 ) ) {
if ( F_49 ( V_16 ) >= F_50 ( V_16 ) ) {
V_95 |= V_106 | V_107 ;
} else {
F_51 ( V_108 ,
& V_16 -> V_109 -> V_76 ) ;
F_51 ( V_110 , & V_16 -> V_109 -> V_76 ) ;
if ( F_49 ( V_16 ) >= F_50 ( V_16 ) )
V_95 |= V_106 | V_107 ;
}
}
}
return V_95 ;
}
int F_52 ( struct V_15 * V_16 , int V_111 , unsigned long V_112 )
{
int V_113 = - V_114 ;
F_53 ( V_16 ) ;
if ( V_16 -> V_18 == V_6 )
goto V_115;
switch ( V_111 ) {
case V_116 : {
struct V_117 * V_118 ;
unsigned long V_119 = 0 ;
V_118 = F_54 ( & V_16 -> V_84 ) ;
if ( V_118 != NULL ) {
V_119 = V_118 -> V_120 ;
}
V_113 = F_55 ( V_119 , ( int V_121 * ) V_112 ) ;
}
break;
default:
V_113 = - V_122 ;
break;
}
V_115:
F_56 ( V_16 ) ;
return V_113 ;
}
static int F_57 ( struct V_15 * V_16 , const T_3 V_123 ,
char V_121 * V_124 , unsigned int V_125 )
{
struct V_45 * V_46 = F_8 ( V_16 ) ;
struct V_126 * V_127 = NULL ;
if ( V_123 == V_128 ||
V_125 > V_129 * sizeof( V_130 ) )
return - V_131 ;
if ( V_125 > sizeof( V_123 ) ) {
V_127 = F_58 ( V_125 , V_132 ) ;
if ( V_127 == NULL )
return - V_133 ;
V_127 -> V_134 = V_125 / sizeof( V_130 ) - 1 ;
if ( F_59 ( V_127 -> V_135 ,
V_124 + sizeof( V_123 ) ,
V_125 - sizeof( V_123 ) ) ||
F_60 ( V_127 , V_128 ) ) {
F_27 ( V_127 ) ;
return - V_136 ;
}
}
F_53 ( V_16 ) ;
V_46 -> V_62 = V_123 ;
F_27 ( V_46 -> V_69 ) ;
V_46 -> V_69 = V_127 ;
F_56 ( V_16 ) ;
return 0 ;
}
static int F_61 ( struct V_15 * V_16 , int V_137 , bool V_138 )
{
T_4 * V_139 , V_120 ;
int V_140 , V_113 ;
if ( V_137 < 0 || V_137 > 15 )
return - V_131 ;
if ( V_137 == 0 )
return 0 ;
V_120 = 16 - V_137 ;
V_139 = F_58 ( V_120 , V_132 ) ;
if ( V_139 == NULL )
return - V_141 ;
for ( V_140 = 0 ; V_140 < V_120 ; V_140 ++ )
V_139 [ V_140 ] = V_137 ++ ;
V_113 = F_62 ( V_16 , V_142 , V_138 , V_139 , V_120 ) ;
if ( V_113 == 0 ) {
if ( V_138 )
F_8 ( V_16 ) -> V_143 = V_137 ;
else
F_8 ( V_16 ) -> V_144 = V_137 ;
}
F_27 ( V_139 ) ;
return V_113 ;
}
static int F_63 ( struct V_15 * V_16 , int type ,
char V_121 * V_124 , unsigned int V_125 )
{
T_4 * V_145 ;
int V_113 = 0 ;
if ( V_125 < 1 || V_125 > V_146 )
return - V_131 ;
V_145 = F_64 ( V_124 , V_125 ) ;
if ( F_65 ( V_145 ) )
return F_66 ( V_145 ) ;
F_53 ( V_16 ) ;
if ( type == V_147 || type == V_148 )
V_113 = F_62 ( V_16 , V_149 , 1 , V_145 , V_125 ) ;
if ( ! V_113 && ( type == V_150 || type == V_148 ) )
V_113 = F_62 ( V_16 , V_149 , 0 , V_145 , V_125 ) ;
F_56 ( V_16 ) ;
F_27 ( V_145 ) ;
return V_113 ;
}
static int F_67 ( struct V_15 * V_16 , int V_151 , int V_152 ,
char V_121 * V_124 , unsigned int V_125 )
{
struct V_45 * V_46 = F_8 ( V_16 ) ;
int V_145 , V_79 = 0 ;
switch ( V_152 ) {
case V_153 :
F_68 ( L_24 ) ;
return 0 ;
case V_154 :
case V_155 :
F_68 ( L_25 ) ;
return 0 ;
case V_148 :
case V_150 :
case V_147 :
return F_63 ( V_16 , V_152 , V_124 , V_125 ) ;
}
if ( V_125 < ( int ) sizeof( int ) )
return - V_131 ;
if ( F_69 ( V_145 , ( int V_121 * ) V_124 ) )
return - V_136 ;
if ( V_152 == V_156 )
return F_57 ( V_16 , V_145 , V_124 , V_125 ) ;
F_53 ( V_16 ) ;
switch ( V_152 ) {
case V_157 :
if ( V_46 -> V_60 != V_158 )
V_79 = - V_159 ;
else
V_46 -> V_160 = ( V_145 != 0 ) ;
break;
case V_161 :
V_79 = F_61 ( V_16 , V_145 , false ) ;
break;
case V_162 :
V_79 = F_61 ( V_16 , V_145 , true ) ;
break;
case V_163 :
if ( V_16 -> V_18 != V_13 )
V_79 = - V_164 ;
else if ( V_145 < 0 || V_145 >= V_165 )
V_79 = - V_131 ;
else
V_46 -> V_166 = V_145 ;
break;
case V_167 :
if ( V_145 < 0 )
V_79 = - V_131 ;
else
V_46 -> V_66 = V_145 ;
break;
default:
V_79 = - V_168 ;
break;
}
F_56 ( V_16 ) ;
return V_79 ;
}
int F_70 ( struct V_15 * V_16 , int V_151 , int V_152 ,
char V_121 * V_124 , unsigned int V_125 )
{
if ( V_151 != V_169 )
return F_9 ( V_16 ) -> V_170 -> V_171 ( V_16 , V_151 ,
V_152 , V_124 ,
V_125 ) ;
return F_67 ( V_16 , V_151 , V_152 , V_124 , V_125 ) ;
}
int F_71 ( struct V_15 * V_16 , int V_151 , int V_152 ,
char V_121 * V_124 , unsigned int V_125 )
{
if ( V_151 != V_169 )
return F_72 ( V_16 , V_151 , V_152 ,
V_124 , V_125 ) ;
return F_67 ( V_16 , V_151 , V_152 , V_124 , V_125 ) ;
}
static int F_73 ( struct V_15 * V_16 , int V_120 ,
T_3 V_121 * V_124 ,
int V_121 * V_125 )
{
const struct V_45 * V_46 = F_8 ( V_16 ) ;
const struct V_126 * V_127 ;
int V_79 = - V_172 , V_173 = 0 , V_174 = sizeof( V_130 ) ;
F_53 ( V_16 ) ;
if ( ( V_127 = V_46 -> V_69 ) != NULL ) {
V_173 = V_127 -> V_134 * sizeof( V_130 ) ;
V_174 += V_173 ;
}
V_79 = - V_131 ;
if ( V_174 > V_120 )
goto V_115;
V_79 = 0 ;
if ( F_55 ( V_174 , V_125 ) ||
F_55 ( V_46 -> V_62 , V_124 ) ||
( V_127 != NULL && F_74 ( V_124 + 1 , V_127 -> V_135 , V_173 ) ) )
V_79 = - V_136 ;
V_115:
F_56 ( V_16 ) ;
return V_79 ;
}
static int F_75 ( struct V_15 * V_16 , int V_151 , int V_152 ,
char V_121 * V_124 , int V_121 * V_125 )
{
struct V_45 * V_46 ;
int V_145 , V_120 ;
if ( F_69 ( V_120 , V_125 ) )
return - V_136 ;
if ( V_120 < ( int ) sizeof( int ) )
return - V_131 ;
V_46 = F_8 ( V_16 ) ;
switch ( V_152 ) {
case V_153 :
F_68 ( L_24 ) ;
return 0 ;
case V_156 :
return F_73 ( V_16 , V_120 ,
( T_3 V_121 * ) V_124 , V_125 ) ;
case V_175 :
V_145 = V_46 -> V_57 ;
break;
case V_176 :
return F_76 ( V_16 , V_120 , V_124 , V_125 ) ;
case V_147 :
V_145 = F_77 ( V_46 ) ;
if ( V_145 < 0 )
return - V_168 ;
break;
case V_150 :
V_145 = F_78 ( V_46 ) ;
if ( V_145 < 0 )
return - V_168 ;
break;
case V_157 :
V_145 = V_46 -> V_160 ;
break;
case V_161 :
V_145 = V_46 -> V_144 ;
break;
case V_162 :
V_145 = V_46 -> V_143 ;
break;
case V_163 :
V_145 = V_46 -> V_166 ;
break;
case V_167 :
V_145 = V_46 -> V_66 ;
break;
case 128 ... 191 :
return F_79 ( V_46 -> V_71 , V_16 , V_152 ,
V_120 , ( V_130 V_121 * ) V_124 , V_125 ) ;
case 192 ... 255 :
return F_80 ( V_46 -> V_72 , V_16 , V_152 ,
V_120 , ( V_130 V_121 * ) V_124 , V_125 ) ;
default:
return - V_168 ;
}
V_120 = sizeof( V_145 ) ;
if ( F_55 ( V_120 , V_125 ) || F_74 ( V_124 , & V_145 , V_120 ) )
return - V_136 ;
return 0 ;
}
int F_81 ( struct V_15 * V_16 , int V_151 , int V_152 ,
char V_121 * V_124 , int V_121 * V_125 )
{
if ( V_151 != V_169 )
return F_9 ( V_16 ) -> V_170 -> V_177 ( V_16 , V_151 ,
V_152 , V_124 ,
V_125 ) ;
return F_75 ( V_16 , V_151 , V_152 , V_124 , V_125 ) ;
}
int F_82 ( struct V_15 * V_16 , int V_151 , int V_152 ,
char V_121 * V_124 , int V_121 * V_125 )
{
if ( V_151 != V_169 )
return F_83 ( V_16 , V_151 , V_152 ,
V_124 , V_125 ) ;
return F_75 ( V_16 , V_151 , V_152 , V_124 , V_125 ) ;
}
static int F_84 ( struct V_178 * V_179 , struct V_117 * V_118 )
{
struct V_180 * V_181 = F_85 ( V_179 ) ;
V_118 -> V_182 = 0 ;
for (; V_181 != NULL ; V_181 = F_86 ( V_179 , V_181 ) ) {
if ( ! F_87 ( V_179 , V_181 ) )
return - V_131 ;
if ( V_181 -> V_183 != V_169 )
continue;
if ( V_181 -> V_184 <= V_185 &&
! F_88 ( V_118 -> V_16 , V_181 -> V_184 ) )
return - V_131 ;
switch ( V_181 -> V_184 ) {
case V_186 :
if ( V_181 -> V_187 != F_89 ( sizeof( V_188 ) ) )
return - V_131 ;
V_118 -> V_182 = * ( V_188 * ) F_90 ( V_181 ) ;
break;
default:
return - V_131 ;
}
}
return 0 ;
}
int F_91 ( struct V_189 * V_190 , struct V_15 * V_16 , struct V_178 * V_179 ,
T_5 V_120 )
{
const struct V_45 * V_46 = F_8 ( V_16 ) ;
const int V_76 = V_179 -> V_191 ;
const int V_192 = V_76 & V_193 ;
struct V_117 * V_118 ;
int V_113 , V_194 ;
long V_195 ;
if ( V_120 > V_46 -> V_57 )
return - V_196 ;
F_53 ( V_16 ) ;
if ( F_92 ( V_16 ) ) {
V_113 = - V_197 ;
goto V_198;
}
V_195 = F_93 ( V_16 , V_192 ) ;
if ( ( 1 << V_16 -> V_18 ) & ~ ( V_199 | V_200 ) )
if ( ( V_113 = F_94 ( V_16 , & V_195 ) ) != 0 )
goto V_198;
V_194 = V_16 -> V_22 -> V_201 + V_120 ;
F_56 ( V_16 ) ;
V_118 = F_95 ( V_16 , V_194 , V_192 , & V_113 ) ;
F_53 ( V_16 ) ;
if ( V_118 == NULL )
goto V_198;
F_96 ( V_118 , V_16 -> V_22 -> V_201 ) ;
V_113 = F_97 ( F_98 ( V_118 , V_120 ) , V_179 -> V_202 , V_120 ) ;
if ( V_113 != 0 )
goto V_203;
V_113 = F_84 ( V_179 , V_118 ) ;
if ( V_113 != 0 )
goto V_203;
F_99 ( V_16 , V_118 ) ;
if ( ! F_100 ( & V_46 -> V_204 ) )
F_101 ( V_16 ) ;
V_198:
F_56 ( V_16 ) ;
return V_113 ? : V_120 ;
V_203:
F_26 ( V_118 ) ;
goto V_198;
}
int F_102 ( struct V_189 * V_190 , struct V_15 * V_16 , struct V_178 * V_179 ,
T_5 V_120 , int V_205 , int V_76 , int * V_206 )
{
const struct V_207 * V_208 ;
long V_195 ;
F_53 ( V_16 ) ;
if ( V_16 -> V_18 == V_6 ) {
V_120 = - V_114 ;
goto V_115;
}
V_195 = F_103 ( V_16 , V_205 ) ;
do {
struct V_117 * V_118 = F_54 ( & V_16 -> V_84 ) ;
if ( V_118 == NULL )
goto V_209;
V_208 = V_207 ( V_118 ) ;
switch ( V_208 -> V_210 ) {
case V_35 :
case V_37 :
goto V_211;
case V_39 :
case V_38 :
if ( ! ( V_76 & V_212 ) )
F_12 ( V_16 ) ;
case V_40 :
F_3 ( L_26 ,
F_19 ( V_208 -> V_210 ) ) ;
V_120 = 0 ;
goto V_213;
default:
F_3 ( L_27 ,
F_19 ( V_208 -> V_210 ) ) ;
F_104 ( V_16 , V_118 , 0 ) ;
}
V_209:
if ( F_17 ( V_16 , V_88 ) ) {
V_120 = 0 ;
break;
}
if ( V_16 -> V_82 ) {
V_120 = F_105 ( V_16 ) ;
break;
}
if ( V_16 -> V_28 & V_98 ) {
V_120 = 0 ;
break;
}
if ( V_16 -> V_18 == V_13 ) {
if ( ! F_17 ( V_16 , V_88 ) ) {
V_120 = - V_114 ;
break;
}
V_120 = 0 ;
break;
}
if ( ! V_195 ) {
V_120 = - V_197 ;
break;
}
if ( F_106 ( V_214 ) ) {
V_120 = F_107 ( V_195 ) ;
break;
}
F_108 ( V_16 , & V_195 ) ;
continue;
V_211:
if ( V_120 > V_118 -> V_120 )
V_120 = V_118 -> V_120 ;
else if ( V_120 < V_118 -> V_120 )
V_179 -> V_191 |= V_215 ;
if ( F_109 ( V_118 , 0 , V_179 -> V_202 , V_120 ) ) {
V_120 = - V_136 ;
break;
}
if ( V_76 & V_215 )
V_120 = V_118 -> V_120 ;
V_213:
if ( ! ( V_76 & V_212 ) )
F_104 ( V_16 , V_118 , 0 ) ;
break;
} while ( 1 );
V_115:
F_56 ( V_16 ) ;
return V_120 ;
}
int F_110 ( struct V_93 * V_15 , int V_73 )
{
struct V_15 * V_16 = V_15 -> V_16 ;
unsigned char V_80 ;
int V_79 ;
F_53 ( V_16 ) ;
V_79 = - V_131 ;
if ( V_15 -> V_1 != V_216 || V_15 -> type != V_217 )
goto V_115;
V_80 = V_16 -> V_18 ;
if ( ! ( ( 1 << V_80 ) & ( V_218 | V_219 ) ) )
goto V_115;
if ( V_80 != V_6 ) {
V_79 = F_31 ( V_16 , V_73 ) ;
if ( V_79 )
goto V_115;
}
V_16 -> V_220 = V_73 ;
V_79 = 0 ;
V_115:
F_56 ( V_16 ) ;
return V_79 ;
}
static void F_111 ( struct V_15 * V_16 )
{
T_4 V_221 = V_13 ;
switch ( V_16 -> V_18 ) {
case V_10 :
case V_11 :
F_12 ( V_16 ) ;
break;
case V_5 :
F_3 ( L_28 , V_16 ) ;
F_112 ( V_16 , V_222 ) ;
case V_3 :
F_14 ( V_16 , 1 ) ;
if ( F_8 ( V_16 ) -> V_60 == V_158 &&
! F_8 ( V_16 ) -> V_160 )
V_221 = V_9 ;
else
V_221 = V_8 ;
default:
F_2 ( V_16 , V_221 ) ;
}
}
void F_113 ( struct V_15 * V_16 , long V_223 )
{
struct V_45 * V_46 = F_8 ( V_16 ) ;
struct V_117 * V_118 ;
V_130 V_224 = 0 ;
int V_1 ;
F_53 ( V_16 ) ;
V_16 -> V_28 = V_29 ;
if ( V_16 -> V_18 == V_6 ) {
F_2 ( V_16 , V_13 ) ;
F_37 ( V_16 ) ;
goto V_225;
}
F_114 ( V_16 , & V_46 -> V_204 ) ;
while ( ( V_118 = F_115 ( & V_16 -> V_84 ) ) != NULL ) {
V_224 += V_118 -> V_120 ;
F_39 ( V_118 ) ;
}
if ( V_224 ) {
F_68 ( L_29 , V_224 ) ;
F_13 ( V_16 , V_81 ) ;
F_2 ( V_16 , V_13 ) ;
} else if ( F_17 ( V_16 , V_226 ) && ! V_16 -> V_227 ) {
V_16 -> V_22 -> V_228 ( V_16 , 0 ) ;
} else if ( V_16 -> V_18 != V_13 ) {
F_116 ( V_16 , & V_223 ) ;
F_111 ( V_16 ) ;
}
F_38 ( & V_16 -> V_85 ) ;
F_117 ( V_16 , V_223 ) ;
V_225:
V_1 = V_16 -> V_18 ;
F_118 ( V_16 ) ;
F_119 ( V_16 ) ;
F_56 ( V_16 ) ;
F_120 () ;
F_121 ( V_16 ) ;
F_5 ( F_122 ( V_16 ) ) ;
F_123 ( V_16 -> V_22 -> V_229 ) ;
if ( V_1 != V_13 && V_16 -> V_18 == V_13 )
goto V_115;
if ( V_16 -> V_18 == V_13 )
F_18 ( V_16 ) ;
V_115:
F_124 ( V_16 ) ;
F_125 () ;
F_126 ( V_16 ) ;
}
void F_127 ( struct V_15 * V_16 , int V_230 )
{
F_3 ( L_30 , V_230 ) ;
}
static inline int F_128 ( void )
{
return F_129 ( ( void V_231 * * ) V_232 ,
sizeof( struct V_233 ) ,
F_130 ( struct V_233 ) ) ;
}
static inline void F_131 ( void )
{
F_132 ( ( void V_231 * * ) V_232 ) ;
}
static int T_6 F_133 ( void )
{
unsigned long V_234 ;
int V_235 , V_236 , V_140 ;
int V_113 ;
F_134 ( sizeof( struct V_237 ) >
F_135 ( struct V_117 , V_238 ) ) ;
V_113 = F_136 ( & V_239 , 0 ) ;
if ( V_113 )
goto V_240;
V_113 = - V_141 ;
F_137 ( & V_241 ) ;
V_241 . V_242 =
F_138 ( L_31 ,
sizeof( struct V_243 ) , 0 ,
V_244 , NULL ) ;
if ( ! V_241 . V_242 )
goto V_245;
if ( V_246 >= ( 128 * 1024 ) )
V_234 = V_246 >> ( 21 - V_247 ) ;
else
V_234 = V_246 >> ( 23 - V_247 ) ;
if ( V_248 )
V_234 = ( V_248 *
sizeof( struct V_249 ) ) >> V_247 ;
for ( V_235 = 0 ; ( 1UL << V_235 ) < V_234 ; V_235 ++ )
;
do {
unsigned long V_250 = ( 1UL << V_235 ) * V_251 /
sizeof( struct V_249 ) ;
while ( V_250 & ( V_250 - 1 ) )
V_250 -- ;
V_241 . V_252 = V_250 - 1 ;
V_241 . V_253 = (struct V_249 * )
F_139 ( V_254 | V_255 , V_235 ) ;
} while ( ! V_241 . V_253 && -- V_235 > 0 );
if ( ! V_241 . V_253 ) {
F_140 ( L_32 ) ;
goto V_256;
}
for ( V_140 = 0 ; V_140 <= V_241 . V_252 ; V_140 ++ ) {
F_141 ( & V_241 . V_253 [ V_140 ] . V_257 , V_140 ) ;
F_141 ( & V_241 . V_253 [ V_140 ] . V_258 , V_140 ) ;
}
if ( F_142 ( & V_241 ) )
goto V_259;
V_236 = V_235 ;
do {
V_241 . V_260 = ( 1UL << V_236 ) * V_251 /
sizeof( struct V_261 ) ;
if ( ( V_241 . V_260 > ( 64 * 1024 ) ) &&
V_236 > 0 )
continue;
V_241 . V_262 = (struct V_261 * )
F_139 ( V_254 | V_255 , V_236 ) ;
} while ( ! V_241 . V_262 && -- V_236 >= 0 );
if ( ! V_241 . V_262 ) {
F_140 ( L_33 ) ;
goto V_263;
}
for ( V_140 = 0 ; V_140 < V_241 . V_260 ; V_140 ++ ) {
F_143 ( & V_241 . V_262 [ V_140 ] . V_264 ) ;
F_144 ( & V_241 . V_262 [ V_140 ] . V_257 ) ;
}
V_113 = F_128 () ;
if ( V_113 )
goto V_265;
V_113 = F_145 () ;
if ( V_113 )
goto V_266;
V_113 = F_146 () ;
if ( V_113 )
goto V_267;
V_113 = F_147 () ;
if ( V_113 )
goto V_268;
F_148 () ;
return 0 ;
V_268:
F_149 () ;
V_267:
F_150 () ;
V_266:
F_131 () ;
V_265:
F_151 ( ( unsigned long ) V_241 . V_262 , V_236 ) ;
V_263:
F_152 ( & V_241 ) ;
V_259:
F_151 ( ( unsigned long ) V_241 . V_253 , V_235 ) ;
V_256:
F_153 ( V_241 . V_242 ) ;
V_245:
F_154 ( & V_239 ) ;
V_240:
V_241 . V_262 = NULL ;
V_241 . V_253 = NULL ;
V_241 . V_242 = NULL ;
return V_113 ;
}
static void T_7 F_155 ( void )
{
F_156 () ;
F_131 () ;
F_151 ( ( unsigned long ) V_241 . V_262 ,
F_157 ( V_241 . V_260 *
sizeof( struct V_261 ) ) ) ;
F_151 ( ( unsigned long ) V_241 . V_253 ,
F_157 ( ( V_241 . V_252 + 1 ) *
sizeof( struct V_249 ) ) ) ;
F_152 ( & V_241 ) ;
F_153 ( V_241 . V_242 ) ;
F_150 () ;
F_149 () ;
F_154 ( & V_239 ) ;
}
