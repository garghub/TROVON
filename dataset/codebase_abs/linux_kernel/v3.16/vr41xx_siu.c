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
if ( V_3 -> line == 1 && V_3 -> V_32 )
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
T_2 V_34 , V_73 ;
char V_74 ;
int V_75 = V_76 ;
V_34 = * V_72 ;
do {
V_73 = F_3 ( V_3 , V_77 ) ;
V_3 -> V_78 . V_79 ++ ;
V_74 = V_80 ;
#ifdef F_21
V_34 |= V_81 [ V_3 -> line ] ;
V_81 [ V_3 -> line ] = 0 ;
#endif
if ( F_22 ( V_34 & ( V_82 | V_83 |
V_84 | V_85 ) ) ) {
if ( V_34 & V_82 ) {
V_34 &= ~ ( V_83 | V_84 ) ;
V_3 -> V_78 . V_86 ++ ;
if ( F_23 ( V_3 ) )
goto V_87;
}
if ( V_34 & V_83 )
V_3 -> V_78 . V_88 ++ ;
if ( V_34 & V_84 )
V_3 -> V_78 . V_89 ++ ;
if ( V_34 & V_85 )
V_3 -> V_78 . V_90 ++ ;
V_34 &= V_3 -> V_65 ;
if ( V_34 & V_82 )
V_74 = V_91 ;
if ( V_34 & V_83 )
V_74 = V_92 ;
if ( V_34 & V_84 )
V_74 = V_93 ;
}
if ( F_24 ( V_3 , V_73 ) )
goto V_87;
F_25 ( V_3 , V_34 , V_85 , V_73 , V_74 ) ;
V_87:
V_34 = F_3 ( V_3 , V_35 ) ;
} while ( ( V_34 & V_66 ) && ( V_75 -- > 0 ) );
F_26 ( & V_3 -> V_94 -> V_3 ) ;
* V_72 = V_34 ;
}
static inline void F_27 ( struct V_2 * V_3 )
{
T_2 V_51 ;
V_51 = F_3 ( V_3 , V_52 ) ;
if ( ( V_51 & V_95 ) == 0 )
return;
if ( V_51 & V_96 )
F_28 ( V_3 , V_51 & V_53 ) ;
if ( V_51 & V_97 )
V_3 -> V_78 . V_98 ++ ;
if ( V_51 & V_99 )
V_3 -> V_78 . V_100 ++ ;
if ( V_51 & V_101 )
F_29 ( V_3 , V_51 & V_59 ) ;
F_30 ( & V_3 -> V_94 -> V_3 . V_102 ) ;
}
static inline void F_31 ( struct V_2 * V_3 )
{
struct V_103 * V_104 ;
int V_75 = V_105 ;
V_104 = & V_3 -> V_94 -> V_104 ;
if ( V_3 -> V_106 ) {
F_4 ( V_3 , V_107 , V_3 -> V_106 ) ;
V_3 -> V_78 . V_108 ++ ;
V_3 -> V_106 = 0 ;
return;
}
if ( F_32 ( V_104 ) || F_33 ( V_3 ) ) {
F_15 ( V_3 ) ;
return;
}
do {
F_4 ( V_3 , V_107 , V_104 -> V_109 [ V_104 -> V_110 ] ) ;
V_104 -> V_110 = ( V_104 -> V_110 + 1 ) & ( V_111 - 1 ) ;
V_3 -> V_78 . V_108 ++ ;
if ( F_32 ( V_104 ) )
break;
} while ( V_75 -- > 0 );
if ( F_34 ( V_104 ) < V_112 )
F_35 ( V_3 ) ;
if ( F_32 ( V_104 ) )
F_15 ( V_3 ) ;
}
static T_6 F_36 ( int V_32 , void * V_113 )
{
struct V_2 * V_3 ;
T_2 V_114 , V_34 ;
V_3 = (struct V_2 * ) V_113 ;
V_114 = F_3 ( V_3 , V_115 ) ;
if ( V_114 & V_116 )
return V_117 ;
V_34 = F_3 ( V_3 , V_35 ) ;
if ( V_34 & V_66 )
F_20 ( V_3 , & V_34 ) ;
F_27 ( V_3 ) ;
if ( V_34 & V_118 )
F_31 ( V_3 ) ;
return V_119 ;
}
static int F_37 ( struct V_2 * V_3 )
{
int V_120 ;
if ( V_3 -> V_121 == NULL )
return - V_122 ;
F_8 ( V_3 ) ;
( void ) F_3 ( V_3 , V_35 ) ;
( void ) F_3 ( V_3 , V_77 ) ;
( void ) F_3 ( V_3 , V_115 ) ;
( void ) F_3 ( V_3 , V_52 ) ;
if ( F_3 ( V_3 , V_35 ) == 0xff )
return - V_122 ;
V_120 = F_38 ( V_3 -> V_32 , F_36 , 0 , F_11 ( V_3 ) , V_3 ) ;
if ( V_120 )
return V_120 ;
if ( V_3 -> type == V_31 )
F_39 ( V_123 ) ;
F_4 ( V_3 , V_70 , V_124 ) ;
F_40 ( & V_3 -> V_7 ) ;
F_13 ( V_3 , V_3 -> V_38 ) ;
F_41 ( & V_3 -> V_7 ) ;
F_4 ( V_3 , V_62 , V_64 | V_125 ) ;
( void ) F_3 ( V_3 , V_35 ) ;
( void ) F_3 ( V_3 , V_77 ) ;
( void ) F_3 ( V_3 , V_115 ) ;
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
( void ) F_3 ( V_3 , V_77 ) ;
if ( V_3 -> type == V_31 )
F_43 ( V_123 ) ;
F_44 ( V_3 -> V_32 , V_3 ) ;
}
static void F_45 ( struct V_2 * V_3 , struct V_126 * V_127 ,
struct V_126 * V_128 )
{
T_7 V_129 , V_130 ;
T_2 V_69 , V_131 , V_61 ;
unsigned int V_132 , V_133 ;
unsigned long V_4 ;
V_129 = V_127 -> V_129 ;
switch ( V_129 & V_134 ) {
case V_135 :
V_69 = V_136 ;
break;
case V_137 :
V_69 = V_138 ;
break;
case V_139 :
V_69 = V_140 ;
break;
default:
V_69 = V_124 ;
break;
}
if ( V_129 & V_141 )
V_69 |= V_142 ;
if ( V_129 & V_143 )
V_69 |= V_144 ;
if ( ( V_129 & V_145 ) != V_145 )
V_69 |= V_146 ;
if ( V_129 & V_147 )
V_69 |= V_148 ;
V_132 = F_46 ( V_3 , V_127 , V_128 , 0 , V_3 -> V_149 / 16 ) ;
V_133 = F_47 ( V_3 , V_132 ) ;
V_131 = V_27 | V_150 ;
F_2 ( & V_3 -> V_7 , V_4 ) ;
F_48 ( V_3 , V_129 , V_132 ) ;
V_130 = V_127 -> V_130 ;
V_3 -> V_65 = V_118 | V_85 | V_66 ;
if ( V_130 & V_151 )
V_3 -> V_65 |= V_83 | V_84 ;
if ( V_130 & ( V_152 | V_153 | V_154 ) )
V_3 -> V_65 |= V_82 ;
V_3 -> V_155 = 0 ;
if ( V_130 & V_156 )
V_3 -> V_155 |= V_83 | V_84 ;
if ( V_130 & V_152 ) {
V_3 -> V_155 |= V_82 ;
if ( V_130 & V_156 )
V_3 -> V_155 |= V_85 ;
}
if ( ( V_129 & V_157 ) == 0 )
V_3 -> V_155 |= V_66 ;
V_61 = F_3 ( V_3 , V_62 ) ;
V_61 &= ~ V_67 ;
if ( F_49 ( V_3 , V_129 ) )
V_61 |= V_67 ;
F_4 ( V_3 , V_62 , V_61 ) ;
F_4 ( V_3 , V_70 , V_69 | V_158 ) ;
F_4 ( V_3 , V_159 , ( T_2 ) V_133 ) ;
F_4 ( V_3 , V_160 , ( T_2 ) ( V_133 >> 8 ) ) ;
F_4 ( V_3 , V_70 , V_69 ) ;
F_4 ( V_3 , V_26 , V_131 ) ;
F_13 ( V_3 , V_3 -> V_38 ) ;
F_5 ( & V_3 -> V_7 , V_4 ) ;
}
static void F_50 ( struct V_2 * V_3 , unsigned int V_94 , unsigned int V_161 )
{
switch ( V_94 ) {
case 0 :
switch ( V_3 -> type ) {
case V_30 :
F_51 ( V_162 ) ;
break;
case V_31 :
F_51 ( V_163 ) ;
break;
}
break;
case 3 :
switch ( V_3 -> type ) {
case V_30 :
F_52 ( V_162 ) ;
break;
case V_31 :
F_52 ( V_163 ) ;
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
unsigned long V_164 ;
if ( V_3 -> V_4 & V_165 ) {
F_55 ( V_3 -> V_121 ) ;
V_3 -> V_121 = NULL ;
}
V_164 = F_9 ( V_3 ) ;
F_56 ( V_3 -> V_166 , V_164 ) ;
}
static int F_57 ( struct V_2 * V_3 )
{
unsigned long V_164 ;
struct V_167 * V_168 ;
V_164 = F_9 ( V_3 ) ;
V_168 = F_58 ( V_3 -> V_166 , V_164 , F_11 ( V_3 ) ) ;
if ( V_168 == NULL )
return - V_169 ;
if ( V_3 -> V_4 & V_165 ) {
V_3 -> V_121 = F_59 ( V_3 -> V_166 , V_164 ) ;
if ( V_3 -> V_121 == NULL ) {
F_60 ( V_168 ) ;
return - V_170 ;
}
}
return 0 ;
}
static void F_61 ( struct V_2 * V_3 , int V_4 )
{
if ( V_4 & V_171 ) {
V_3 -> type = F_10 ( V_3 ) ;
( void ) F_57 ( V_3 ) ;
}
}
static int F_62 ( struct V_2 * V_3 , struct V_172 * V_173 )
{
if ( V_3 -> type != V_30 && V_3 -> type != V_31 )
return - V_174 ;
if ( V_3 -> V_32 != V_173 -> V_32 )
return - V_174 ;
if ( V_3 -> V_175 != V_173 -> V_176 )
return - V_174 ;
if ( V_3 -> V_166 != ( unsigned long ) V_173 -> V_177 )
return - V_174 ;
return 0 ;
}
static int F_63 ( struct V_178 * V_179 )
{
struct V_2 * V_3 ;
struct V_167 * V_168 ;
int * type = F_64 ( & V_179 -> V_180 ) ;
int V_181 ;
if ( ! type )
return 0 ;
V_3 = V_6 ;
for ( V_181 = 0 ; V_181 < V_182 ; V_181 ++ ) {
V_3 -> type = type [ V_181 ] ;
if ( V_3 -> type == V_33 )
continue;
V_3 -> V_32 = F_65 ( V_179 , V_181 ) ;
V_3 -> V_149 = V_183 * 16 ;
V_3 -> V_184 = 16 ;
V_3 -> V_185 = 0 ;
V_3 -> V_175 = V_186 ;
V_3 -> V_4 = V_165 | V_187 ;
V_3 -> line = V_181 ;
V_168 = F_66 ( V_179 , V_188 , V_181 ) ;
V_3 -> V_166 = V_168 -> V_189 ;
V_3 ++ ;
}
return V_181 ;
}
static void F_67 ( struct V_2 * V_3 )
{
int V_190 = 10000 ;
T_2 V_34 , V_51 ;
do {
V_34 = F_3 ( V_3 , V_35 ) ;
if ( V_34 & V_82 )
V_81 [ V_3 -> line ] = V_82 ;
if ( ( V_34 & V_191 ) == V_191 )
break;
} while ( V_190 -- > 0 );
if ( V_3 -> V_4 & V_192 ) {
V_190 = 1000000 ;
do {
V_51 = F_3 ( V_3 , V_52 ) ;
if ( ( V_51 & V_59 ) != 0 )
break;
} while ( V_190 -- > 0 );
}
}
static void F_68 ( struct V_2 * V_3 , int V_73 )
{
F_67 ( V_3 ) ;
F_4 ( V_3 , V_107 , V_73 ) ;
}
static void F_69 ( struct V_193 * V_194 , const char * V_195 , unsigned V_196 )
{
struct V_2 * V_3 ;
T_2 V_61 ;
V_3 = & V_6 [ V_194 -> V_197 ] ;
V_61 = F_3 ( V_3 , V_62 ) ;
F_4 ( V_3 , V_62 , 0 ) ;
F_70 ( V_3 , V_195 , V_196 , F_68 ) ;
F_67 ( V_3 ) ;
F_4 ( V_3 , V_62 , V_61 ) ;
}
static int T_8 F_71 ( struct V_193 * V_194 , char * V_198 )
{
struct V_2 * V_3 ;
int V_132 = 9600 ;
int V_89 = 'n' ;
int V_199 = 8 ;
int V_200 = 'n' ;
if ( V_194 -> V_197 >= V_182 )
V_194 -> V_197 = 0 ;
V_3 = & V_6 [ V_194 -> V_197 ] ;
if ( V_3 -> V_121 == NULL ) {
if ( V_3 -> V_166 == 0 )
return - V_122 ;
V_3 -> V_121 = F_59 ( V_3 -> V_166 , F_9 ( V_3 ) ) ;
}
if ( V_3 -> type == V_30 )
F_1 ( V_201 ) ;
if ( V_198 != NULL )
F_72 ( V_198 , & V_132 , & V_89 , & V_199 , & V_200 ) ;
return F_73 ( V_3 , V_194 , V_132 , V_89 , V_199 , V_200 ) ;
}
static int F_74 ( void )
{
struct V_2 * V_3 ;
int V_181 ;
for ( V_181 = 0 ; V_181 < V_182 ; V_181 ++ ) {
V_3 = & V_6 [ V_181 ] ;
V_3 -> V_202 = & V_203 ;
}
F_75 ( & V_204 ) ;
return 0 ;
}
void T_8 F_76 ( struct V_2 * V_3 )
{
if ( V_3 -> type == V_33 )
return;
V_6 [ V_3 -> line ] . line = V_3 -> line ;
V_6 [ V_3 -> line ] . type = V_3 -> type ;
V_6 [ V_3 -> line ] . V_149 = V_183 * 16 ;
V_6 [ V_3 -> line ] . V_166 = V_3 -> V_166 ;
V_6 [ V_3 -> line ] . V_166 = V_3 -> V_166 ;
V_6 [ V_3 -> line ] . V_202 = & V_203 ;
}
static int F_77 ( struct V_178 * V_180 )
{
struct V_2 * V_3 ;
int V_205 , V_181 , V_120 ;
V_205 = F_63 ( V_180 ) ;
if ( V_205 <= 0 )
return - V_122 ;
V_206 . V_207 = V_205 ;
V_120 = F_78 ( & V_206 ) ;
if ( V_120 )
return V_120 ;
for ( V_181 = 0 ; V_181 < V_205 ; V_181 ++ ) {
V_3 = & V_6 [ V_181 ] ;
V_3 -> V_202 = & V_203 ;
V_3 -> V_180 = & V_180 -> V_180 ;
V_120 = F_79 ( & V_206 , V_3 ) ;
if ( V_120 < 0 ) {
V_3 -> V_180 = NULL ;
break;
}
}
if ( V_181 == 0 && V_120 < 0 ) {
F_80 ( & V_206 ) ;
return V_120 ;
}
return 0 ;
}
static int F_81 ( struct V_178 * V_180 )
{
struct V_2 * V_3 ;
int V_181 ;
for ( V_181 = 0 ; V_181 < V_206 . V_207 ; V_181 ++ ) {
V_3 = & V_6 [ V_181 ] ;
if ( V_3 -> V_180 == & V_180 -> V_180 ) {
F_82 ( & V_206 , V_3 ) ;
V_3 -> V_180 = NULL ;
}
}
F_80 ( & V_206 ) ;
return 0 ;
}
static int F_83 ( struct V_178 * V_180 , T_9 V_94 )
{
struct V_2 * V_3 ;
int V_181 ;
for ( V_181 = 0 ; V_181 < V_206 . V_207 ; V_181 ++ ) {
V_3 = & V_6 [ V_181 ] ;
if ( ( V_3 -> type == V_30 ||
V_3 -> type == V_31 ) && V_3 -> V_180 == & V_180 -> V_180 )
F_84 ( & V_206 , V_3 ) ;
}
return 0 ;
}
static int F_85 ( struct V_178 * V_180 )
{
struct V_2 * V_3 ;
int V_181 ;
for ( V_181 = 0 ; V_181 < V_206 . V_207 ; V_181 ++ ) {
V_3 = & V_6 [ V_181 ] ;
if ( ( V_3 -> type == V_30 ||
V_3 -> type == V_31 ) && V_3 -> V_180 == & V_180 -> V_180 )
F_86 ( & V_206 , V_3 ) ;
}
return 0 ;
}
