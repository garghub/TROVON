static inline T_1
F_1 ( const T_2 * V_1 , unsigned int V_2 )
{
return F_2 ( V_1 -> V_3 + V_4 ,
V_1 -> V_3 + V_5 ,
V_2 ) ;
}
static inline void
F_3 ( const T_2 * V_1 , unsigned int V_2 , T_1 V_6 )
{
return F_4 ( V_1 -> V_3 + V_4 ,
V_1 -> V_3 + V_5 ,
V_2 ,
V_6 ) ;
}
static bool
F_5 ( const struct V_7 * V_8 ,
unsigned int V_9 )
{
switch ( V_9 ) {
case 0 :
return V_8 -> V_10 & V_11 ;
case 1 :
return V_8 -> V_10 & V_12 ;
default:
return false ;
}
}
static int
F_6 ( const struct V_13 * V_14 ,
const struct V_7 * V_8 ,
char * V_15 ,
T_3 V_16 )
{
int V_17 , V_18 = 0 ;
unsigned int V_19 , V_20 ;
V_17 = snprintf ( V_15 , V_16 , L_1 , V_14 -> V_21 ) ;
if ( V_17 < 0 || V_17 >= V_16 )
goto V_22;
V_15 += V_17 ;
V_16 -= V_17 ;
V_18 += V_17 ;
for ( V_20 = 0 , V_19 = 0 ; V_19 < V_14 -> V_23 ; V_19 ++ ) {
if ( F_5 ( V_8 , V_19 ) ) {
V_17 = snprintf ( V_15 , V_16 , L_2 ,
( V_20 ++ ? L_3 : L_4 ) , V_19 ) ;
if ( V_17 < 0 || V_17 >= V_16 )
goto V_22;
V_15 += V_17 ;
V_16 -= V_17 ;
V_18 += V_17 ;
}
}
V_17 = snprintf ( V_15 , V_16 , L_5 , V_20 ? L_4 : L_6 ) ;
if ( V_17 < 0 || V_17 >= V_16 )
goto V_22;
V_15 += V_17 ;
V_16 -= V_17 ;
V_18 += V_17 ;
V_22:
return V_18 ;
}
static int
F_7 ( const struct V_13 * V_14 ,
const struct V_7 * V_8 ,
char * V_15 ,
T_3 V_16 )
{
const struct V_24 * V_25 = V_14 -> V_26 ;
const char * V_27 = NULL ;
switch ( V_8 -> V_10 & V_28 ) {
case V_29 :
V_27 = L_6 ;
break;
case V_30 :
V_27 = L_7 ;
break;
case V_31 :
switch ( F_1 ( & V_25 -> V_1 , V_32 ) &
V_33 ) {
case V_34 :
V_27 = L_7 ;
break;
case V_35 :
V_27 = L_8 ;
break;
default:
V_27 = L_9 ;
break;
}
break;
case V_36 :
V_27 = L_10 ;
break;
default:
V_27 = L_9 ;
break;
}
return snprintf ( V_15 , V_16 , L_11 , V_27 ) ;
}
static int
F_8 ( const struct V_13 * V_14 ,
const struct V_7 * V_8 ,
char * V_15 ,
T_3 V_16 )
{
int V_17 , V_18 = 0 ;
unsigned int V_37 , V_38 ;
const unsigned int V_39 = 0 ;
const unsigned int V_40 = 16 ;
V_17 = snprintf ( V_15 , V_16 , L_12 ) ;
if ( V_17 < 0 || V_17 >= V_16 )
goto V_22;
V_15 += V_17 ;
V_16 -= V_17 ;
V_18 += V_17 ;
for ( V_38 = 0 , V_37 = V_39 ; V_37 < V_40 ; V_37 ++ ) {
if ( ( V_8 -> V_10 & F_9 ( V_37 ) ) != 0 ) {
V_17 = snprintf ( V_15 , V_16 ,
L_2 ,
( V_38 ++ ? L_3 : L_4 ) , V_37 ) ;
if ( V_17 < 0 || V_17 >= V_16 )
goto V_22;
V_15 += V_17 ;
V_16 -= V_17 ;
V_18 += V_17 ;
}
}
V_17 = snprintf ( V_15 , V_16 , L_5 , V_38 ? L_4 : L_6 ) ;
if ( V_17 < 0 || V_17 >= V_16 )
goto V_22;
V_15 += V_17 ;
V_16 -= V_17 ;
V_18 += V_17 ;
V_22:
return V_18 ;
}
static int
F_10 ( const struct V_13 * V_14 ,
const struct V_7 * V_8 ,
char * V_15 ,
T_3 V_16 )
{
int V_17 , V_18 = 0 ;
V_17 = F_6 ( V_14 , V_8 , V_15 , V_16 ) ;
if ( V_17 < 0 || V_17 >= V_16 )
goto V_22;
V_15 += V_17 ;
V_16 -= V_17 ;
V_18 += V_17 ;
V_17 = F_7 ( V_14 , V_8 , V_15 , V_16 ) ;
if ( V_17 < 0 || V_17 >= V_16 )
goto V_22;
V_15 += V_17 ;
V_16 -= V_17 ;
V_18 += V_17 ;
V_17 = F_8 ( V_14 , V_8 , V_15 , V_16 ) ;
if ( V_17 < 0 || V_17 >= V_16 )
goto V_22;
V_15 += V_17 ;
V_16 -= V_17 ;
V_18 += V_17 ;
V_22:
return V_18 ;
}
static int
F_11 ( const struct V_13 * V_14 ,
const struct V_7 * V_8 ,
char * V_15 ,
T_3 V_16 )
{
unsigned int V_41 ;
bool V_42 ;
if ( ( V_8 -> V_43 & V_44 ) == 0 )
return 0 ;
if ( ( V_8 -> V_43 & V_45 ) == V_46 )
return 0 ;
V_42 = ( ( V_8 -> V_43 & V_47 ) == V_48 ) ;
V_41 = F_12 ( V_8 -> V_43 ) ;
return snprintf ( V_15 , V_16 ,
L_13 ,
( V_42 ? L_14 : L_15 ) ,
V_41 ,
( ( ( V_41 >= V_49 ) &&
( V_41 <= V_50 ) ) ?
V_51 [ V_41 ] : L_16 ) ) ;
}
static void
F_13 ( const struct V_13 * V_14 ,
const struct V_7 * V_8 ,
char * V_15 ,
T_3 V_16 )
{
int V_17 ;
if ( V_15 == NULL || V_16 == 0 )
return;
V_17 = F_10 ( V_14 , V_8 , V_15 , V_16 ) ;
if ( V_17 < 0 || V_17 >= V_16 )
return;
V_15 += V_17 ;
V_16 -= V_17 ;
F_11 ( V_14 , V_8 , V_15 , V_16 ) ;
}
static void
F_14 ( const struct V_13 * V_14 ,
const struct V_7 * V_8 )
{
char V_52 [ V_53 ] ;
F_13 ( V_14 , V_8 , V_52 , sizeof( V_52 ) ) ;
F_15 ( V_54 , V_14 ,
L_17
L_18
L_19
L_20
L_21
L_22 ,
V_8 -> V_10 ,
V_8 -> V_55 ,
V_8 -> V_43 ,
V_8 -> V_56 ,
V_8 -> V_57 ,
V_52 ) ;
}
static void
F_16 ( const struct V_13 * V_14 ,
struct V_7 * V_8 )
{
const struct V_24 * V_25 = V_14 -> V_26 ;
const T_2 * V_1 = & V_25 -> V_1 ;
V_8 -> V_10 = F_1 ( V_1 , V_58 ) & V_59 ;
V_8 -> V_55 = F_1 ( V_1 , V_60 ) & V_61 ;
V_8 -> V_43 = F_1 ( V_1 , V_62 ) & V_44 ;
V_8 -> V_57 = F_1 ( V_1 , V_63 ) ;
V_8 -> V_56 = F_1 ( V_1 , V_64 ) ;
}
static void
F_17 ( const struct V_13 * V_14 ,
const struct V_7 * V_8 )
{
const struct V_24 * V_25 = V_14 -> V_26 ;
const T_2 * V_1 = & V_25 -> V_1 ;
F_3 ( V_1 , V_58 , V_8 -> V_10 & V_59 ) ;
F_3 ( V_1 , V_60 , V_8 -> V_55 & V_61 ) ;
F_3 ( V_1 , V_62 , V_8 -> V_43 & V_44 ) ;
F_3 ( V_1 , V_63 , 0 ) ;
F_3 ( V_1 , V_64 , 0 ) ;
}
static void
F_18 ( struct V_13 * V_14 ,
const struct V_7 * V_8 )
{
int V_19 ;
char V_52 [ V_53 ] ;
F_13 ( V_14 , V_8 , V_52 , sizeof( V_52 ) ) ;
for ( V_19 = 0 ; V_19 < V_14 -> V_23 ; V_19 ++ )
if ( F_5 ( V_8 , V_19 ) )
F_19 ( V_65 , V_14 ,
0 , 0 , 0 ,
V_19 , 0 , - 1 ,
V_52 , L_4 , NULL ) ;
}
static void
F_20 ( struct V_13 * V_14 ,
const struct V_7 * V_8 )
{
const T_4 V_66 = ( ( T_4 ) V_8 -> V_56 << 32 | V_8 -> V_57 ) ;
const unsigned long V_67 = V_66 >> V_68 ;
const unsigned long V_69 = V_66 & ~ V_70 ;
int V_19 ;
char V_52 [ V_53 ] ;
F_13 ( V_14 , V_8 , V_52 , sizeof( V_52 ) ) ;
for ( V_19 = 0 ; V_19 < V_14 -> V_23 ; V_19 ++ )
if ( F_5 ( V_8 , V_19 ) )
F_19 ( V_71 , V_14 ,
V_67 , V_69 , 0 ,
V_19 , 0 , - 1 ,
V_52 , L_4 , NULL ) ;
}
static void
F_21 ( struct V_13 * V_14 )
{
#ifdef F_22
static unsigned int V_72 ;
#endif
struct V_7 V_8 ;
F_16 ( V_14 , & V_8 ) ;
#ifdef F_22
if ( V_72 ++ % 30 == 0 )
F_14 ( V_14 , & V_8 ) ;
#endif
if ( V_8 . V_10 & V_73 )
F_20 ( V_14 , & V_8 ) ;
if ( V_8 . V_10 & V_74 )
F_18 ( V_14 , & V_8 ) ;
F_17 ( V_14 , & V_8 ) ;
}
static T_5
F_23 ( int V_75 , void * V_76 )
{
struct V_13 * V_14 = V_76 ;
F_21 ( V_14 ) ;
return V_77 ;
}
static enum V_78 T_6
F_24 ( T_1 V_79 )
{
switch ( V_79 & V_33 ) {
case V_34 :
return V_80 ;
case V_35 :
return V_81 ;
default:
return V_82 ;
}
}
static enum V_83 T_6
F_25 ( T_1 V_79 )
{
bool V_84 = ( ( V_79 & V_85 ) == V_86 ) ;
switch ( V_79 & V_87 ) {
case V_88 :
return V_84 ? V_89 : V_90 ;
case V_91 :
return V_84 ? V_92 : V_93 ;
default:
return V_94 ;
}
}
static int T_6
F_26 ( struct V_13 * V_14 , T_1 V_79 )
{
const struct V_24 * V_25 = V_14 -> V_26 ;
int V_8 = 0 ;
enum V_83 V_95 ;
enum V_78 V_96 ;
enum V_97 V_98 ;
int V_19 , V_99 ;
T_1 V_100 , V_16 , V_101 ;
V_95 = F_25 ( V_79 ) ;
V_96 = F_24 ( V_79 ) ;
if ( V_14 -> V_102 & V_103 )
V_98 = V_104 ;
else if ( V_14 -> V_102 & V_105 )
V_98 = V_106 ;
else
V_98 = V_107 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_23 ; V_19 ++ ) {
struct V_108 * V_109 = & V_14 -> V_110 [ V_19 ] ;
V_100 = F_1 ( & V_25 -> V_1 , F_27 ( V_19 ) ) ;
if ( ( V_100 & V_111 ) != V_112 )
continue;
V_16 = V_100 & V_113 ;
switch ( V_16 ) {
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_101 = F_28 ( V_16 ) ;
break;
default:
F_15 ( V_126 , V_14 ,
L_23
L_24 ,
V_19 , F_29 ( V_16 ) ) ;
V_8 = - V_127 ;
goto V_128;
}
for ( V_99 = 0 ; V_99 < V_109 -> V_129 ; V_99 ++ ) {
struct V_130 * V_131 = V_109 -> V_132 [ V_99 ] . V_131 ;
V_131 -> V_101 = V_101 / V_109 -> V_129 ;
V_131 -> V_133 = 1 ;
V_131 -> V_95 = V_95 ;
V_131 -> V_96 = V_96 ;
V_131 -> V_98 = V_98 ;
}
}
V_128:
return V_8 ;
}
static int T_6
F_30 ( struct V_13 * V_14 ,
struct V_134 * V_135 ,
const T_2 * V_1 ,
T_1 V_79 )
{
int V_8 = 0 ;
const T_1 V_136 = ( V_79 & V_137 ) ;
struct V_24 * V_25 = NULL ;
const struct V_138 * V_139 = V_135 -> V_140 . V_141 ;
if ( F_31 ( V_142 , & V_135 -> V_140 ) == NULL )
return - V_127 ;
V_14 -> V_140 = & V_135 -> V_140 ;
F_32 ( V_14 -> V_140 , V_14 ) ;
V_25 = V_14 -> V_26 ;
V_25 -> V_1 = * V_1 ;
V_25 -> V_143 . V_144 = V_145 ;
V_25 -> V_143 . V_146 = V_145 ;
V_14 -> V_147 = ( V_148 | V_149 |
V_150 | V_151 ) ;
V_14 -> V_152 = ( V_153 |
V_105 |
V_103 ) ;
V_14 -> V_154 = V_155 ;
V_14 -> V_156 = V_155 ;
switch ( V_136 ) {
case V_157 :
V_14 -> V_102 = V_105 ;
break;
case V_158 :
V_14 -> V_102 = ( V_105 | V_103 ) ;
V_14 -> V_156 = V_159 ;
break;
default:
V_14 -> V_102 = V_153 ;
break;
}
V_14 -> V_160 = V_161 ;
V_14 -> V_162 = V_163 ;
V_14 -> V_164 = V_142 -> V_165 ,
V_14 -> V_21 = V_139 -> V_166 ;
V_14 -> V_167 = F_21 ;
V_14 -> V_168 = NULL ;
V_8 = F_26 ( V_14 , V_79 ) ;
if ( V_8 )
F_15 ( V_126 , V_14 ,
L_25 ) ;
return V_8 ;
}
static int T_6
F_33 ( struct V_134 * V_135 , struct V_13 * V_14 )
{
int V_8 = 0 ;
int V_169 , V_170 ;
struct V_24 * V_25 = V_14 -> V_26 ;
struct V_138 * V_139 = V_135 -> V_140 . V_141 ;
V_169 = F_34 ( V_139 , V_171 ) ;
V_170 = F_34 ( V_139 , V_172 ) ;
if ( V_169 == V_145 || V_170 == V_145 ) {
F_15 ( V_126 , V_14 ,
L_26 ) ;
V_8 = - V_173 ;
goto V_22;
}
V_8 = F_35 ( V_169 ,
F_23 ,
V_174 ,
L_27 ,
V_14 ) ;
if ( V_8 < 0 ) {
F_15 ( V_126 , V_14 ,
L_28 ,
V_169 ) ;
V_8 = - V_173 ;
goto V_175;
}
V_8 = F_35 ( V_170 ,
F_23 ,
V_174 ,
L_29 ,
V_14 ) ;
if ( V_8 < 0 ) {
F_15 ( V_126 , V_14 ,
L_30 ,
V_170 ) ;
V_8 = - V_173 ;
goto V_176;
}
F_15 ( V_54 , V_14 , L_31 , V_169 ) ;
F_15 ( V_54 , V_14 , L_32 , V_170 ) ;
V_25 -> V_143 . V_146 = V_169 ;
V_25 -> V_143 . V_144 = V_170 ;
return 0 ;
V_176:
F_36 ( V_170 , V_14 ) ;
V_175:
F_36 ( V_169 , V_14 ) ;
V_22:
return V_8 ;
}
static int T_6
F_37 ( const struct V_138 * V_139 , T_2 * V_1 )
{
unsigned int V_177 , V_178 ;
if ( V_139 == NULL || V_1 == NULL )
return - V_127 ;
V_177 = F_38 ( V_139 , 0 ) ;
V_178 = F_39 ( V_139 , 0 ) ;
if ( V_177 == 0 || V_178 == 0 ) {
F_40 ( V_126 ,
L_33 ) ;
return - V_173 ;
}
if ( V_178 != V_179 ) {
F_40 ( V_126 ,
L_34 ,
V_178 , V_179 ) ;
return - V_173 ;
}
* V_1 = F_41 ( V_139 , V_177 , V_178 ) ;
if ( ! F_42 ( * V_1 ) ) {
F_40 ( V_54 , L_35 ) ;
return - V_173 ;
}
return 0 ;
}
static int T_6 F_43 ( struct V_134 * V_135 )
{
int V_8 = 0 ;
T_1 V_79 , V_136 ;
T_2 V_1 ;
const struct V_138 * V_139 = V_135 -> V_140 . V_141 ;
struct V_13 * V_14 = NULL ;
struct V_180 V_181 [ 2 ] ;
static int V_182 ;
if ( ! F_44 ( V_139 , L_36 ) &&
! F_44 ( V_139 , L_37 ) ) {
F_40 ( V_183 ,
L_38 ) ;
return - V_173 ;
}
V_8 = F_37 ( V_139 , & V_1 ) ;
if ( V_8 )
return V_8 ;
V_79 = F_1 ( & V_1 , V_32 ) ;
V_136 = ( V_79 & V_137 ) ;
if ( V_136 == V_184 ) {
F_40 ( V_54 , L_39
L_40 , V_139 -> V_166 ) ;
V_8 = - V_173 ;
goto V_128;
}
V_181 [ 0 ] . type = V_185 ;
V_181 [ 0 ] . V_16 = V_186 ;
V_181 [ 0 ] . V_187 = true ;
V_181 [ 1 ] . type = V_188 ;
V_181 [ 1 ] . V_16 = V_189 ;
V_181 [ 1 ] . V_187 = false ;
V_14 = F_45 ( V_182 , F_46 ( V_181 ) , V_181 ,
sizeof( struct V_24 ) ) ;
if ( V_14 == NULL ) {
F_40 ( V_126 , L_41
L_42 ,
V_139 -> V_166 ) ;
V_8 = - V_190 ;
goto V_128;
}
V_8 = F_30 ( V_14 , V_135 , & V_1 , V_79 ) ;
if ( V_8 ) {
F_15 ( V_126 , V_14 ,
L_43 ) ;
goto V_22;
}
if ( F_47 ( V_14 ) ) {
F_15 ( V_126 , V_14 ,
L_44 ) ;
V_8 = - V_173 ;
goto V_22;
}
if ( V_191 == V_192 ) {
V_8 = F_33 ( V_135 , V_14 ) ;
if ( V_8 )
goto V_175;
}
V_182 ++ ;
return 0 ;
V_175:
F_48 ( V_14 -> V_140 ) ;
V_22:
F_49 ( V_14 ) ;
V_128:
return V_8 ;
}
static int
F_50 ( struct V_134 * V_135 )
{
struct V_13 * V_14 = F_51 ( & V_135 -> V_140 ) ;
struct V_24 * V_25 = V_14 -> V_26 ;
if ( V_191 == V_192 ) {
F_36 ( V_25 -> V_143 . V_144 , V_14 ) ;
F_36 ( V_25 -> V_143 . V_146 , V_14 ) ;
}
F_52 ( V_25 -> V_1 , V_179 ) ;
F_48 ( V_14 -> V_140 ) ;
F_49 ( V_14 ) ;
return 0 ;
}
static inline void T_7
F_53 ( void )
{
switch ( V_191 ) {
case V_193 :
case V_192 :
break;
default:
V_191 = V_192 ;
break;
}
F_40 ( V_54 , L_45 ,
( ( V_191 == V_193 ) ?
V_194 :
( ( V_191 == V_192 ) ?
V_195 :
V_196 ) ) ) ;
}
static int T_7
F_54 ( void )
{
F_40 ( V_54 , V_163 L_17 ) ;
F_53 () ;
return F_55 ( & V_197 ) ;
}
static void T_8
F_56 ( void )
{
F_57 ( & V_197 ) ;
}
