void F_1 ( T_1 V_1 )
{
struct V_2 * V_3 ;
unsigned long V_4 ;
T_2 V_5 ;
V_3 = & V_6 [ 0 ] ;
F_2 ( & V_3 -> V_7 , V_4 ) ;
V_5 = F_3 ( V_3 , V_8 ) ;
if ( V_1 == V_9 )
V_5 |= V_10 ;
else
V_5 &= ~ V_10 ;
F_4 ( V_3 , V_8 , V_5 ) ;
F_5 ( & V_3 -> V_7 , V_4 ) ;
}
void F_6 ( T_3 V_11 )
{
struct V_2 * V_3 ;
unsigned long V_4 ;
T_2 V_5 ;
V_3 = & V_6 [ 0 ] ;
F_2 ( & V_3 -> V_7 , V_4 ) ;
V_5 = F_3 ( V_3 , V_8 ) ;
if ( V_11 == V_12 )
V_5 |= V_13 ;
else
V_5 &= ~ V_13 ;
F_4 ( V_3 , V_8 , V_5 ) ;
F_5 ( & V_3 -> V_7 , V_4 ) ;
}
void F_7 ( T_4 V_14 , T_5 V_15 )
{
struct V_2 * V_3 ;
unsigned long V_4 ;
T_2 V_5 ;
V_3 = & V_6 [ 0 ] ;
F_2 ( & V_3 -> V_7 , V_4 ) ;
V_5 = F_3 ( V_3 , V_8 ) ;
V_5 &= ~ ( V_16 | V_17 | V_18 ) ;
switch ( V_14 ) {
case V_19 :
V_5 |= V_20 ;
break;
case V_21 :
V_5 |= V_22 | V_18 ;
if ( V_15 == V_23 )
V_5 |= V_17 ;
break;
case V_24 :
V_5 |= V_25 ;
break;
default:
break;
}
F_4 ( V_3 , V_8 , V_5 ) ;
F_5 ( & V_3 -> V_7 , V_4 ) ;
}
static inline void F_8 ( struct V_2 * V_3 )
{
F_4 ( V_3 , V_26 , V_27 ) ;
F_4 ( V_3 , V_26 , V_27 | V_28 |
V_29 ) ;
F_4 ( V_3 , V_26 , 0 ) ;
}
static inline unsigned long F_9 ( struct V_2 * V_3 )
{
switch ( V_3 -> type ) {
case V_30 :
return 11UL ;
case V_31 :
return 8UL ;
}
return 0 ;
}
static inline unsigned int F_10 ( struct V_2 * V_3 )
{
if ( V_3 -> line == 0 )
return V_30 ;
if ( V_3 -> line == 1 && V_3 -> V_32 != - 1 )
return V_31 ;
return V_33 ;
}
static inline const char * F_11 ( struct V_2 * V_3 )
{
switch ( V_3 -> type ) {
case V_30 :
return L_1 ;
case V_31 :
return L_2 ;
}
return NULL ;
}
static unsigned int F_12 ( struct V_2 * V_3 )
{
T_2 V_34 ;
V_34 = F_3 ( V_3 , V_35 ) ;
if ( V_34 & V_36 )
return V_37 ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 , unsigned int V_38 )
{
T_2 V_39 = 0 ;
if ( V_38 & V_40 )
V_39 |= V_41 ;
if ( V_38 & V_42 )
V_39 |= V_43 ;
if ( V_38 & V_44 )
V_39 |= V_45 ;
if ( V_38 & V_46 )
V_39 |= V_47 ;
if ( V_38 & V_48 )
V_39 |= V_49 ;
F_4 ( V_3 , V_50 , V_39 ) ;
}
static unsigned int F_14 ( struct V_2 * V_3 )
{
T_2 V_51 ;
unsigned int V_38 = 0 ;
V_51 = F_3 ( V_3 , V_52 ) ;
if ( V_51 & V_53 )
V_38 |= V_54 ;
if ( V_51 & V_55 )
V_38 |= V_56 ;
if ( V_51 & V_57 )
V_38 |= V_58 ;
if ( V_51 & V_59 )
V_38 |= V_60 ;
return V_38 ;
}
static void F_15 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_2 V_61 ;
F_2 ( & V_3 -> V_7 , V_4 ) ;
V_61 = F_3 ( V_3 , V_62 ) ;
V_61 &= ~ V_63 ;
F_4 ( V_3 , V_62 , V_61 ) ;
F_5 ( & V_3 -> V_7 , V_4 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_2 V_61 ;
F_2 ( & V_3 -> V_7 , V_4 ) ;
V_61 = F_3 ( V_3 , V_62 ) ;
V_61 |= V_63 ;
F_4 ( V_3 , V_62 , V_61 ) ;
F_5 ( & V_3 -> V_7 , V_4 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_2 V_61 ;
F_2 ( & V_3 -> V_7 , V_4 ) ;
V_61 = F_3 ( V_3 , V_62 ) ;
V_61 &= ~ V_64 ;
F_4 ( V_3 , V_62 , V_61 ) ;
V_3 -> V_65 &= ~ V_66 ;
F_5 ( & V_3 -> V_7 , V_4 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_2 V_61 ;
F_2 ( & V_3 -> V_7 , V_4 ) ;
V_61 = F_3 ( V_3 , V_62 ) ;
V_61 |= V_67 ;
F_4 ( V_3 , V_62 , V_61 ) ;
F_5 ( & V_3 -> V_7 , V_4 ) ;
}
static void F_19 ( struct V_2 * V_3 , int V_68 )
{
unsigned long V_4 ;
T_2 V_69 ;
F_2 ( & V_3 -> V_7 , V_4 ) ;
V_69 = F_3 ( V_3 , V_70 ) ;
if ( V_68 == - 1 )
V_69 |= V_71 ;
else
V_69 &= ~ V_71 ;
F_4 ( V_3 , V_70 , V_69 ) ;
F_5 ( & V_3 -> V_7 , V_4 ) ;
}
static inline void F_20 ( struct V_2 * V_3 , T_2 * V_72 )
{
struct V_73 * V_74 ;
T_2 V_34 , V_75 ;
char V_76 ;
int V_77 = V_78 ;
V_74 = V_3 -> V_79 -> V_3 . V_74 ;
V_34 = * V_72 ;
do {
V_75 = F_3 ( V_3 , V_80 ) ;
V_3 -> V_81 . V_82 ++ ;
V_76 = V_83 ;
#ifdef F_21
V_34 |= V_84 [ V_3 -> line ] ;
V_84 [ V_3 -> line ] = 0 ;
#endif
if ( F_22 ( V_34 & ( V_85 | V_86 |
V_87 | V_88 ) ) ) {
if ( V_34 & V_85 ) {
V_34 &= ~ ( V_86 | V_87 ) ;
V_3 -> V_81 . V_89 ++ ;
if ( F_23 ( V_3 ) )
goto V_90;
}
if ( V_34 & V_86 )
V_3 -> V_81 . V_91 ++ ;
if ( V_34 & V_87 )
V_3 -> V_81 . V_92 ++ ;
if ( V_34 & V_88 )
V_3 -> V_81 . V_93 ++ ;
V_34 &= V_3 -> V_65 ;
if ( V_34 & V_85 )
V_76 = V_94 ;
if ( V_34 & V_86 )
V_76 = V_95 ;
if ( V_34 & V_87 )
V_76 = V_96 ;
}
if ( F_24 ( V_3 , V_75 ) )
goto V_90;
F_25 ( V_3 , V_34 , V_88 , V_75 , V_76 ) ;
V_90:
V_34 = F_3 ( V_3 , V_35 ) ;
} while ( ( V_34 & V_66 ) && ( V_77 -- > 0 ) );
F_26 ( V_74 ) ;
* V_72 = V_34 ;
}
static inline void F_27 ( struct V_2 * V_3 )
{
T_2 V_51 ;
V_51 = F_3 ( V_3 , V_52 ) ;
if ( ( V_51 & V_97 ) == 0 )
return;
if ( V_51 & V_98 )
F_28 ( V_3 , V_51 & V_53 ) ;
if ( V_51 & V_99 )
V_3 -> V_81 . V_100 ++ ;
if ( V_51 & V_101 )
V_3 -> V_81 . V_102 ++ ;
if ( V_51 & V_103 )
F_29 ( V_3 , V_51 & V_59 ) ;
F_30 ( & V_3 -> V_79 -> V_3 . V_104 ) ;
}
static inline void F_31 ( struct V_2 * V_3 )
{
struct V_105 * V_106 ;
int V_77 = V_107 ;
V_106 = & V_3 -> V_79 -> V_106 ;
if ( V_3 -> V_108 ) {
F_4 ( V_3 , V_109 , V_3 -> V_108 ) ;
V_3 -> V_81 . V_110 ++ ;
V_3 -> V_108 = 0 ;
return;
}
if ( F_32 ( V_106 ) || F_33 ( V_3 ) ) {
F_15 ( V_3 ) ;
return;
}
do {
F_4 ( V_3 , V_109 , V_106 -> V_111 [ V_106 -> V_112 ] ) ;
V_106 -> V_112 = ( V_106 -> V_112 + 1 ) & ( V_113 - 1 ) ;
V_3 -> V_81 . V_110 ++ ;
if ( F_32 ( V_106 ) )
break;
} while ( V_77 -- > 0 );
if ( F_34 ( V_106 ) < V_114 )
F_35 ( V_3 ) ;
if ( F_32 ( V_106 ) )
F_15 ( V_3 ) ;
}
static T_6 F_36 ( int V_32 , void * V_115 )
{
struct V_2 * V_3 ;
T_2 V_116 , V_34 ;
V_3 = (struct V_2 * ) V_115 ;
V_116 = F_3 ( V_3 , V_117 ) ;
if ( V_116 & V_118 )
return V_119 ;
V_34 = F_3 ( V_3 , V_35 ) ;
if ( V_34 & V_66 )
F_20 ( V_3 , & V_34 ) ;
F_27 ( V_3 ) ;
if ( V_34 & V_120 )
F_31 ( V_3 ) ;
return V_121 ;
}
static int F_37 ( struct V_2 * V_3 )
{
int V_122 ;
if ( V_3 -> V_123 == NULL )
return - V_124 ;
F_8 ( V_3 ) ;
( void ) F_3 ( V_3 , V_35 ) ;
( void ) F_3 ( V_3 , V_80 ) ;
( void ) F_3 ( V_3 , V_117 ) ;
( void ) F_3 ( V_3 , V_52 ) ;
if ( F_3 ( V_3 , V_35 ) == 0xff )
return - V_124 ;
V_122 = F_38 ( V_3 -> V_32 , F_36 , 0 , F_11 ( V_3 ) , V_3 ) ;
if ( V_122 )
return V_122 ;
if ( V_3 -> type == V_31 )
F_39 ( V_125 ) ;
F_4 ( V_3 , V_70 , V_126 ) ;
F_40 ( & V_3 -> V_7 ) ;
F_13 ( V_3 , V_3 -> V_38 ) ;
F_41 ( & V_3 -> V_7 ) ;
F_4 ( V_3 , V_62 , V_64 | V_127 ) ;
( void ) F_3 ( V_3 , V_35 ) ;
( void ) F_3 ( V_3 , V_80 ) ;
( void ) F_3 ( V_3 , V_117 ) ;
( void ) F_3 ( V_3 , V_52 ) ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_2 V_69 ;
F_4 ( V_3 , V_62 , 0 ) ;
F_2 ( & V_3 -> V_7 , V_4 ) ;
V_3 -> V_38 &= ~ V_46 ;
F_13 ( V_3 , V_3 -> V_38 ) ;
F_5 ( & V_3 -> V_7 , V_4 ) ;
V_69 = F_3 ( V_3 , V_70 ) ;
V_69 &= ~ V_71 ;
F_4 ( V_3 , V_70 , V_69 ) ;
F_8 ( V_3 ) ;
( void ) F_3 ( V_3 , V_80 ) ;
if ( V_3 -> type == V_31 )
F_43 ( V_125 ) ;
F_44 ( V_3 -> V_32 , V_3 ) ;
}
static void F_45 ( struct V_2 * V_3 , struct V_128 * V_129 ,
struct V_128 * V_130 )
{
T_7 V_131 , V_132 ;
T_2 V_69 , V_133 , V_61 ;
unsigned int V_134 , V_135 ;
unsigned long V_4 ;
V_131 = V_129 -> V_131 ;
switch ( V_131 & V_136 ) {
case V_137 :
V_69 = V_138 ;
break;
case V_139 :
V_69 = V_140 ;
break;
case V_141 :
V_69 = V_142 ;
break;
default:
V_69 = V_126 ;
break;
}
if ( V_131 & V_143 )
V_69 |= V_144 ;
if ( V_131 & V_145 )
V_69 |= V_146 ;
if ( ( V_131 & V_147 ) != V_147 )
V_69 |= V_148 ;
if ( V_131 & V_149 )
V_69 |= V_150 ;
V_134 = F_46 ( V_3 , V_129 , V_130 , 0 , V_3 -> V_151 / 16 ) ;
V_135 = F_47 ( V_3 , V_134 ) ;
V_133 = V_27 | V_152 ;
F_2 ( & V_3 -> V_7 , V_4 ) ;
F_48 ( V_3 , V_131 , V_134 ) ;
V_132 = V_129 -> V_132 ;
V_3 -> V_65 = V_120 | V_88 | V_66 ;
if ( V_132 & V_153 )
V_3 -> V_65 |= V_86 | V_87 ;
if ( V_132 & ( V_154 | V_155 ) )
V_3 -> V_65 |= V_85 ;
V_3 -> V_156 = 0 ;
if ( V_132 & V_157 )
V_3 -> V_156 |= V_86 | V_87 ;
if ( V_132 & V_158 ) {
V_3 -> V_156 |= V_85 ;
if ( V_132 & V_157 )
V_3 -> V_156 |= V_88 ;
}
if ( ( V_131 & V_159 ) == 0 )
V_3 -> V_156 |= V_66 ;
V_61 = F_3 ( V_3 , V_62 ) ;
V_61 &= ~ V_67 ;
if ( F_49 ( V_3 , V_131 ) )
V_61 |= V_67 ;
F_4 ( V_3 , V_62 , V_61 ) ;
F_4 ( V_3 , V_70 , V_69 | V_160 ) ;
F_4 ( V_3 , V_161 , ( T_2 ) V_135 ) ;
F_4 ( V_3 , V_162 , ( T_2 ) ( V_135 >> 8 ) ) ;
F_4 ( V_3 , V_70 , V_69 ) ;
F_4 ( V_3 , V_26 , V_133 ) ;
F_13 ( V_3 , V_3 -> V_38 ) ;
F_5 ( & V_3 -> V_7 , V_4 ) ;
}
static void F_50 ( struct V_2 * V_3 , unsigned int V_79 , unsigned int V_163 )
{
switch ( V_79 ) {
case 0 :
switch ( V_3 -> type ) {
case V_30 :
F_51 ( V_164 ) ;
break;
case V_31 :
F_51 ( V_165 ) ;
break;
}
break;
case 3 :
switch ( V_3 -> type ) {
case V_30 :
F_52 ( V_164 ) ;
break;
case V_31 :
F_52 ( V_165 ) ;
break;
}
break;
}
}
static const char * F_53 ( struct V_2 * V_3 )
{
return F_11 ( V_3 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
unsigned long V_166 ;
if ( V_3 -> V_4 & V_167 ) {
F_55 ( V_3 -> V_123 ) ;
V_3 -> V_123 = NULL ;
}
V_166 = F_9 ( V_3 ) ;
F_56 ( V_3 -> V_168 , V_166 ) ;
}
static int F_57 ( struct V_2 * V_3 )
{
unsigned long V_166 ;
struct V_169 * V_170 ;
V_166 = F_9 ( V_3 ) ;
V_170 = F_58 ( V_3 -> V_168 , V_166 , F_11 ( V_3 ) ) ;
if ( V_170 == NULL )
return - V_171 ;
if ( V_3 -> V_4 & V_167 ) {
V_3 -> V_123 = F_59 ( V_3 -> V_168 , V_166 ) ;
if ( V_3 -> V_123 == NULL ) {
F_60 ( V_170 ) ;
return - V_172 ;
}
}
return 0 ;
}
static void F_61 ( struct V_2 * V_3 , int V_4 )
{
if ( V_4 & V_173 ) {
V_3 -> type = F_10 ( V_3 ) ;
( void ) F_57 ( V_3 ) ;
}
}
static int F_62 ( struct V_2 * V_3 , struct V_174 * V_175 )
{
if ( V_3 -> type != V_30 && V_3 -> type != V_31 )
return - V_176 ;
if ( V_3 -> V_32 != V_175 -> V_32 )
return - V_176 ;
if ( V_3 -> V_177 != V_175 -> V_178 )
return - V_176 ;
if ( V_3 -> V_168 != ( unsigned long ) V_175 -> V_179 )
return - V_176 ;
return 0 ;
}
static int F_63 ( struct V_180 * V_181 )
{
struct V_2 * V_3 ;
struct V_169 * V_170 ;
int * type = V_181 -> V_182 . V_183 ;
int V_184 ;
if ( ! type )
return 0 ;
V_3 = V_6 ;
for ( V_184 = 0 ; V_184 < V_185 ; V_184 ++ ) {
V_3 -> type = type [ V_184 ] ;
if ( V_3 -> type == V_33 )
continue;
V_3 -> V_32 = F_64 ( V_181 , V_184 ) ;
V_3 -> V_151 = V_186 * 16 ;
V_3 -> V_187 = 16 ;
V_3 -> V_188 = 0 ;
V_3 -> V_177 = V_189 ;
V_3 -> V_4 = V_167 | V_190 ;
V_3 -> line = V_184 ;
V_170 = F_65 ( V_181 , V_191 , V_184 ) ;
V_3 -> V_168 = V_170 -> V_192 ;
V_3 ++ ;
}
return V_184 ;
}
static void F_66 ( struct V_2 * V_3 )
{
int V_193 = 10000 ;
T_2 V_34 , V_51 ;
do {
V_34 = F_3 ( V_3 , V_35 ) ;
if ( V_34 & V_85 )
V_84 [ V_3 -> line ] = V_85 ;
if ( ( V_34 & V_194 ) == V_194 )
break;
} while ( V_193 -- > 0 );
if ( V_3 -> V_4 & V_195 ) {
V_193 = 1000000 ;
do {
V_51 = F_3 ( V_3 , V_52 ) ;
if ( ( V_51 & V_59 ) != 0 )
break;
} while ( V_193 -- > 0 );
}
}
static void F_67 ( struct V_2 * V_3 , int V_75 )
{
F_66 ( V_3 ) ;
F_4 ( V_3 , V_109 , V_75 ) ;
}
static void F_68 ( struct V_196 * V_197 , const char * V_198 , unsigned V_199 )
{
struct V_2 * V_3 ;
T_2 V_61 ;
V_3 = & V_6 [ V_197 -> V_200 ] ;
V_61 = F_3 ( V_3 , V_62 ) ;
F_4 ( V_3 , V_62 , 0 ) ;
F_69 ( V_3 , V_198 , V_199 , F_67 ) ;
F_66 ( V_3 ) ;
F_4 ( V_3 , V_62 , V_61 ) ;
}
static int T_8 F_70 ( struct V_196 * V_197 , char * V_201 )
{
struct V_2 * V_3 ;
int V_134 = 9600 ;
int V_92 = 'n' ;
int V_202 = 8 ;
int V_203 = 'n' ;
if ( V_197 -> V_200 >= V_185 )
V_197 -> V_200 = 0 ;
V_3 = & V_6 [ V_197 -> V_200 ] ;
if ( V_3 -> V_123 == NULL ) {
if ( V_3 -> V_168 == 0 )
return - V_124 ;
V_3 -> V_123 = F_59 ( V_3 -> V_168 , F_9 ( V_3 ) ) ;
}
if ( V_3 -> type == V_30 )
F_1 ( V_204 ) ;
if ( V_201 != NULL )
F_71 ( V_201 , & V_134 , & V_92 , & V_202 , & V_203 ) ;
return F_72 ( V_3 , V_197 , V_134 , V_92 , V_202 , V_203 ) ;
}
static int T_9 F_73 ( void )
{
struct V_2 * V_3 ;
int V_184 ;
for ( V_184 = 0 ; V_184 < V_185 ; V_184 ++ ) {
V_3 = & V_6 [ V_184 ] ;
V_3 -> V_205 = & V_206 ;
}
F_74 ( & V_207 ) ;
return 0 ;
}
void T_8 F_75 ( struct V_2 * V_3 )
{
if ( V_3 -> type == V_33 )
return;
V_6 [ V_3 -> line ] . line = V_3 -> line ;
V_6 [ V_3 -> line ] . type = V_3 -> type ;
V_6 [ V_3 -> line ] . V_151 = V_186 * 16 ;
V_6 [ V_3 -> line ] . V_168 = V_3 -> V_168 ;
V_6 [ V_3 -> line ] . V_168 = V_3 -> V_168 ;
V_6 [ V_3 -> line ] . V_205 = & V_206 ;
}
static int T_9 F_76 ( struct V_180 * V_182 )
{
struct V_2 * V_3 ;
int V_208 , V_184 , V_122 ;
V_208 = F_63 ( V_182 ) ;
if ( V_208 <= 0 )
return - V_124 ;
V_209 . V_210 = V_208 ;
V_122 = F_77 ( & V_209 ) ;
if ( V_122 )
return V_122 ;
for ( V_184 = 0 ; V_184 < V_208 ; V_184 ++ ) {
V_3 = & V_6 [ V_184 ] ;
V_3 -> V_205 = & V_206 ;
V_3 -> V_182 = & V_182 -> V_182 ;
V_122 = F_78 ( & V_209 , V_3 ) ;
if ( V_122 < 0 ) {
V_3 -> V_182 = NULL ;
break;
}
}
if ( V_184 == 0 && V_122 < 0 ) {
F_79 ( & V_209 ) ;
return V_122 ;
}
return 0 ;
}
static int T_10 F_80 ( struct V_180 * V_182 )
{
struct V_2 * V_3 ;
int V_184 ;
for ( V_184 = 0 ; V_184 < V_209 . V_210 ; V_184 ++ ) {
V_3 = & V_6 [ V_184 ] ;
if ( V_3 -> V_182 == & V_182 -> V_182 ) {
F_81 ( & V_209 , V_3 ) ;
V_3 -> V_182 = NULL ;
}
}
F_79 ( & V_209 ) ;
return 0 ;
}
static int F_82 ( struct V_180 * V_182 , T_11 V_79 )
{
struct V_2 * V_3 ;
int V_184 ;
for ( V_184 = 0 ; V_184 < V_209 . V_210 ; V_184 ++ ) {
V_3 = & V_6 [ V_184 ] ;
if ( ( V_3 -> type == V_30 ||
V_3 -> type == V_31 ) && V_3 -> V_182 == & V_182 -> V_182 )
F_83 ( & V_209 , V_3 ) ;
}
return 0 ;
}
static int F_84 ( struct V_180 * V_182 )
{
struct V_2 * V_3 ;
int V_184 ;
for ( V_184 = 0 ; V_184 < V_209 . V_210 ; V_184 ++ ) {
V_3 = & V_6 [ V_184 ] ;
if ( ( V_3 -> type == V_30 ||
V_3 -> type == V_31 ) && V_3 -> V_182 == & V_182 -> V_182 )
F_85 ( & V_209 , V_3 ) ;
}
return 0 ;
}
