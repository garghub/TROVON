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
F_19 ( V_14 , V_52 ) ;
}
static void
F_20 ( struct V_13 * V_14 ,
const struct V_7 * V_8 )
{
const T_4 V_65 = ( ( T_4 ) V_8 -> V_56 << 32 | V_8 -> V_57 ) ;
const unsigned long V_66 = V_65 >> V_67 ;
const unsigned long V_68 = V_65 & ~ V_69 ;
int V_19 ;
char V_52 [ V_53 ] ;
F_13 ( V_14 , V_8 , V_52 , sizeof( V_52 ) ) ;
for ( V_19 = 0 ; V_19 < V_14 -> V_23 ; V_19 ++ )
if ( F_5 ( V_8 , V_19 ) )
F_21 ( V_14 , V_66 , V_68 , V_19 , V_52 ) ;
}
static void
F_22 ( struct V_13 * V_14 )
{
#ifdef F_23
static unsigned int V_70 ;
#endif
struct V_7 V_8 ;
F_16 ( V_14 , & V_8 ) ;
#ifdef F_23
if ( V_70 ++ % 30 == 0 )
F_14 ( V_14 , & V_8 ) ;
#endif
if ( V_8 . V_10 & V_71 )
F_20 ( V_14 , & V_8 ) ;
if ( V_8 . V_10 & V_72 )
F_18 ( V_14 , & V_8 ) ;
F_17 ( V_14 , & V_8 ) ;
}
static T_5
F_24 ( int V_73 , void * V_74 )
{
struct V_13 * V_14 = V_74 ;
F_22 ( V_14 ) ;
return V_75 ;
}
static enum V_76 T_6
F_25 ( T_1 V_77 )
{
switch ( V_77 & V_33 ) {
case V_34 :
return V_78 ;
case V_35 :
return V_79 ;
default:
return V_80 ;
}
}
static enum V_81 T_6
F_26 ( T_1 V_77 )
{
bool V_82 = ( ( V_77 & V_83 ) == V_84 ) ;
switch ( V_77 & V_85 ) {
case V_86 :
return V_82 ? V_87 : V_88 ;
case V_89 :
return V_82 ? V_90 : V_91 ;
default:
return V_92 ;
}
}
static int T_6
F_27 ( struct V_13 * V_14 , T_1 V_77 )
{
const struct V_24 * V_25 = V_14 -> V_26 ;
int V_8 = 0 ;
enum V_81 V_93 ;
enum V_76 V_94 ;
enum V_95 V_96 ;
int V_19 ;
T_1 V_97 , V_16 ;
static T_1 V_98 ;
V_93 = F_26 ( V_77 ) ;
V_94 = F_25 ( V_77 ) ;
if ( V_14 -> V_99 & V_100 )
V_96 = V_101 ;
else if ( V_14 -> V_99 & V_102 )
V_96 = V_103 ;
else
V_96 = V_104 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_23 ; V_19 ++ ) {
struct V_105 * V_106 = & V_14 -> V_107 [ V_19 ] ;
V_97 = F_1 ( & V_25 -> V_1 , F_28 ( V_19 ) ) ;
if ( ( V_97 & V_108 ) != V_109 )
continue;
V_16 = V_97 & V_110 ;
switch ( V_16 ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
V_106 -> V_123 = F_29 ( V_16 ) ;
break;
default:
F_15 ( V_124 , V_14 ,
L_23
L_24 ,
V_19 , F_30 ( V_16 ) ) ;
V_8 = - V_125 ;
goto V_126;
}
V_106 -> V_127 = V_98 ;
V_106 -> V_128 = V_106 -> V_127 + V_106 -> V_123 - 1 ;
V_106 -> V_129 = 0 ;
V_106 -> V_130 = 1 ;
V_106 -> V_93 = V_93 ;
V_106 -> V_94 = V_94 ;
V_106 -> V_96 = V_96 ;
V_98 += V_106 -> V_123 ;
}
V_126:
return V_8 ;
}
static int T_6
F_31 ( struct V_13 * V_14 ,
struct V_131 * V_132 ,
const T_2 * V_1 ,
T_1 V_77 )
{
int V_8 = 0 ;
const T_1 V_133 = ( V_77 & V_134 ) ;
struct V_24 * V_25 = NULL ;
const struct V_135 * V_136 = V_132 -> V_137 . V_138 ;
if ( F_32 ( V_139 , & V_132 -> V_137 ) == NULL )
return - V_125 ;
V_14 -> V_137 = & V_132 -> V_137 ;
F_33 ( V_14 -> V_137 , V_14 ) ;
V_25 = V_14 -> V_26 ;
V_25 -> V_1 = * V_1 ;
V_25 -> V_140 . V_141 = V_142 ;
V_25 -> V_140 . V_143 = V_142 ;
V_14 -> V_144 = ( V_145 | V_146 |
V_147 | V_148 ) ;
V_14 -> V_149 = ( V_150 |
V_102 |
V_100 ) ;
V_14 -> V_151 = V_152 ;
V_14 -> V_153 = V_152 ;
switch ( V_133 ) {
case V_154 :
V_14 -> V_99 = V_102 ;
break;
case V_155 :
V_14 -> V_99 = ( V_102 | V_100 ) ;
V_14 -> V_153 = V_156 ;
break;
default:
V_14 -> V_99 = V_150 ;
break;
}
V_14 -> V_157 = V_158 ;
V_14 -> V_159 = V_160 ;
V_14 -> V_161 = V_139 -> V_162 ,
V_14 -> V_21 = V_136 -> V_163 ;
V_14 -> V_164 = F_22 ;
V_14 -> V_165 = NULL ;
V_8 = F_27 ( V_14 , V_77 ) ;
if ( V_8 )
F_15 ( V_124 , V_14 ,
L_25 ) ;
return V_8 ;
}
static int T_6
F_34 ( struct V_131 * V_132 , struct V_13 * V_14 )
{
int V_8 = 0 ;
int V_166 , V_167 ;
struct V_24 * V_25 = V_14 -> V_26 ;
struct V_135 * V_136 = V_132 -> V_137 . V_138 ;
V_166 = F_35 ( V_136 , V_168 ) ;
V_167 = F_35 ( V_136 , V_169 ) ;
if ( V_166 == V_142 || V_167 == V_142 ) {
F_15 ( V_124 , V_14 ,
L_26 ) ;
V_8 = - V_170 ;
goto V_22;
}
V_8 = F_36 ( V_166 ,
F_24 ,
V_171 ,
L_27 ,
V_14 ) ;
if ( V_8 < 0 ) {
F_15 ( V_124 , V_14 ,
L_28 ,
V_166 ) ;
V_8 = - V_170 ;
goto V_172;
}
V_8 = F_36 ( V_167 ,
F_24 ,
V_171 ,
L_29 ,
V_14 ) ;
if ( V_8 < 0 ) {
F_15 ( V_124 , V_14 ,
L_30 ,
V_167 ) ;
V_8 = - V_170 ;
goto V_173;
}
F_15 ( V_54 , V_14 , L_31 , V_166 ) ;
F_15 ( V_54 , V_14 , L_32 , V_167 ) ;
V_25 -> V_140 . V_143 = V_166 ;
V_25 -> V_140 . V_141 = V_167 ;
return 0 ;
V_173:
F_37 ( V_167 , V_14 ) ;
V_172:
F_37 ( V_166 , V_14 ) ;
V_22:
return V_8 ;
}
static int T_6
F_38 ( const struct V_135 * V_136 , T_2 * V_1 )
{
unsigned int V_174 , V_175 ;
if ( V_136 == NULL || V_1 == NULL )
return - V_125 ;
V_174 = F_39 ( V_136 , 0 ) ;
V_175 = F_40 ( V_136 , 0 ) ;
if ( V_174 == 0 || V_175 == 0 ) {
F_41 ( V_124 ,
L_33 ) ;
return - V_170 ;
}
if ( V_175 != V_176 ) {
F_41 ( V_124 ,
L_34 ,
V_175 , V_176 ) ;
return - V_170 ;
}
* V_1 = F_42 ( V_136 , V_174 , V_175 ) ;
if ( ! F_43 ( * V_1 ) ) {
F_41 ( V_54 , L_35 ) ;
return - V_170 ;
}
return 0 ;
}
static int T_6 F_44 ( struct V_131 * V_132 )
{
int V_8 = 0 ;
T_1 V_77 , V_133 ;
T_2 V_1 ;
const struct V_135 * V_136 = V_132 -> V_137 . V_138 ;
struct V_13 * V_14 = NULL ;
static int V_177 ;
if ( ! F_45 ( V_136 , L_36 ) &&
! F_45 ( V_136 , L_37 ) ) {
F_41 ( V_178 ,
L_38 ) ;
return - V_170 ;
}
V_8 = F_38 ( V_136 , & V_1 ) ;
if ( V_8 )
return V_8 ;
V_77 = F_1 ( & V_1 , V_32 ) ;
V_133 = ( V_77 & V_134 ) ;
if ( V_133 == V_179 ) {
F_41 ( V_54 , L_39
L_40 , V_136 -> V_163 ) ;
V_8 = - V_170 ;
goto V_126;
}
V_14 = F_46 ( sizeof( struct V_24 ) ,
V_180 ,
V_181 ,
V_177 ) ;
if ( V_14 == NULL ) {
F_41 ( V_124 , L_41
L_42 ,
V_136 -> V_163 ) ;
V_8 = - V_182 ;
goto V_126;
}
V_8 = F_31 ( V_14 , V_132 , & V_1 , V_77 ) ;
if ( V_8 ) {
F_15 ( V_124 , V_14 ,
L_43 ) ;
goto V_22;
}
if ( F_47 ( V_14 ) ) {
F_15 ( V_124 , V_14 ,
L_44 ) ;
V_8 = - V_170 ;
goto V_22;
}
if ( V_183 == V_184 ) {
V_8 = F_34 ( V_132 , V_14 ) ;
if ( V_8 )
goto V_172;
}
V_177 ++ ;
return 0 ;
V_172:
F_48 ( V_14 -> V_137 ) ;
V_22:
F_49 ( V_14 ) ;
V_126:
return V_8 ;
}
static int
F_50 ( struct V_131 * V_132 )
{
struct V_13 * V_14 = F_51 ( & V_132 -> V_137 ) ;
struct V_24 * V_25 = V_14 -> V_26 ;
if ( V_183 == V_184 ) {
F_37 ( V_25 -> V_140 . V_141 , V_14 ) ;
F_37 ( V_25 -> V_140 . V_143 , V_14 ) ;
}
F_52 ( V_25 -> V_1 , V_176 ) ;
F_48 ( V_14 -> V_137 ) ;
F_49 ( V_14 ) ;
return 0 ;
}
static inline void T_7
F_53 ( void )
{
switch ( V_183 ) {
case V_185 :
case V_184 :
break;
default:
V_183 = V_184 ;
break;
}
F_41 ( V_54 , L_45 ,
( ( V_183 == V_185 ) ?
V_186 :
( ( V_183 == V_184 ) ?
V_187 :
V_188 ) ) ) ;
}
static int T_7
F_54 ( void )
{
F_41 ( V_54 , V_160 L_17 ) ;
F_53 () ;
return F_55 ( & V_189 ) ;
}
static void T_8
F_56 ( void )
{
F_57 ( & V_189 ) ;
}
