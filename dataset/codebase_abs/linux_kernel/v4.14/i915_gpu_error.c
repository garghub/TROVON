static const char * F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 : return L_1 ;
case V_3 : return L_2 ;
case V_4 : return L_3 ;
case V_5 : return L_4 ;
case V_6 : return L_5 ;
default: return L_6 ;
}
}
static const char * F_2 ( int V_7 )
{
switch ( V_7 ) {
default:
case V_8 : return L_6 ;
case V_9 : return L_7 ;
case V_10 : return L_8 ;
}
}
static const char * F_3 ( int V_11 )
{
return V_11 ? L_9 : L_6 ;
}
static const char * F_4 ( int V_12 )
{
return V_12 ? L_10 : L_6 ;
}
static bool F_5 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_15 && F_6 ( V_14 -> V_16 > ( V_14 -> V_17 - 1 ) , L_11 ) ) {
V_14 -> V_15 = - V_18 ;
return false ;
}
if ( V_14 -> V_16 == V_14 -> V_17 - 1 || V_14 -> V_15 )
return false ;
return true ;
}
static bool F_7 ( struct V_13 * V_14 ,
unsigned V_19 )
{
if ( V_14 -> V_20 + V_19 <= V_14 -> V_21 ) {
V_14 -> V_20 += V_19 ;
return false ;
}
if ( V_19 >= V_14 -> V_17 ) {
V_14 -> V_15 = - V_22 ;
return false ;
}
return true ;
}
static void F_8 ( struct V_13 * V_14 ,
unsigned V_19 )
{
if ( V_14 -> V_20 < V_14 -> V_21 ) {
const T_1 V_23 = V_14 -> V_21 - V_14 -> V_20 ;
if ( V_23 > V_19 || V_14 -> V_16 ) {
V_14 -> V_15 = - V_22 ;
return;
}
memmove ( V_14 -> V_24 , V_14 -> V_24 + V_23 , V_19 - V_23 ) ;
V_14 -> V_16 = V_19 - V_23 ;
V_14 -> V_20 = V_14 -> V_21 ;
return;
}
V_14 -> V_16 += V_19 ;
V_14 -> V_20 += V_19 ;
}
static void F_9 ( struct V_13 * V_14 ,
const char * V_25 , T_2 args )
{
unsigned V_19 ;
if ( ! F_5 ( V_14 ) )
return;
if ( V_14 -> V_20 < V_14 -> V_21 ) {
T_2 V_26 ;
F_10 ( V_26 , args ) ;
V_19 = vsnprintf ( NULL , 0 , V_25 , V_26 ) ;
va_end ( V_26 ) ;
if ( ! F_7 ( V_14 , V_19 ) )
return;
}
V_19 = vsnprintf ( V_14 -> V_24 + V_14 -> V_16 , V_14 -> V_17 - V_14 -> V_16 , V_25 , args ) ;
if ( V_19 >= V_14 -> V_17 - V_14 -> V_16 )
V_19 = V_14 -> V_17 - V_14 -> V_16 - 1 ;
F_8 ( V_14 , V_19 ) ;
}
static void F_11 ( struct V_13 * V_14 ,
const char * V_27 )
{
unsigned V_19 ;
if ( ! F_5 ( V_14 ) )
return;
V_19 = strlen ( V_27 ) ;
if ( V_14 -> V_20 < V_14 -> V_21 ) {
if ( ! F_7 ( V_14 , V_19 ) )
return;
}
if ( V_19 >= V_14 -> V_17 - V_14 -> V_16 )
V_19 = V_14 -> V_17 - V_14 -> V_16 - 1 ;
memcpy ( V_14 -> V_24 + V_14 -> V_16 , V_27 , V_19 ) ;
F_8 ( V_14 , V_19 ) ;
}
static bool F_12 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = memset ( & V_29 -> V_31 , 0 , sizeof( V_29 -> V_31 ) ) ;
V_31 -> V_32 =
F_13 ( F_14 ( V_33 , V_34 ) ,
V_35 | V_36 ) ;
if ( ! V_31 -> V_32 )
return false ;
if ( F_15 ( V_31 , V_37 ) != V_38 ) {
F_16 ( V_31 -> V_32 ) ;
return false ;
}
V_29 -> V_26 = NULL ;
if ( F_17 () )
V_29 -> V_26 = ( void * ) F_18 ( V_35 | V_36 ) ;
return true ;
}
static int F_19 ( struct V_28 * V_29 ,
void * V_39 ,
struct V_40 * V_41 )
{
struct V_30 * V_31 = & V_29 -> V_31 ;
V_31 -> V_42 = V_39 ;
if ( V_29 -> V_26 && F_20 ( V_29 -> V_26 , V_39 , V_43 ) )
V_31 -> V_42 = V_29 -> V_26 ;
V_31 -> V_44 = V_43 ;
do {
if ( V_31 -> V_45 == 0 ) {
unsigned long V_46 ;
V_46 = F_18 ( V_35 | V_36 ) ;
if ( ! V_46 )
return - V_47 ;
V_41 -> V_48 [ V_41 -> V_49 ++ ] = ( void * ) V_46 ;
V_31 -> V_50 = ( void * ) V_46 ;
V_31 -> V_45 = V_43 ;
}
if ( F_21 ( V_31 , V_51 ) != V_38 )
return - V_22 ;
} while ( V_31 -> V_44 );
if ( 0 && V_31 -> V_52 > V_31 -> V_53 )
return - V_54 ;
return 0 ;
}
static void F_22 ( struct V_28 * V_29 ,
struct V_40 * V_41 )
{
struct V_30 * V_31 = & V_29 -> V_31 ;
if ( V_41 ) {
F_21 ( V_31 , V_55 ) ;
V_41 -> V_56 = V_31 -> V_45 ;
}
F_23 ( V_31 ) ;
F_16 ( V_31 -> V_32 ) ;
if ( V_29 -> V_26 )
F_24 ( ( unsigned long ) V_29 -> V_26 ) ;
}
static void F_25 ( struct V_13 * V_57 )
{
F_26 ( V_57 , L_12 ) ;
}
static bool F_12 ( struct V_28 * V_29 )
{
return true ;
}
static int F_19 ( struct V_28 * V_29 ,
void * V_39 ,
struct V_40 * V_41 )
{
unsigned long V_46 ;
void * V_58 ;
V_46 = F_18 ( V_35 | V_36 ) ;
if ( ! V_46 )
return - V_47 ;
V_58 = ( void * ) V_46 ;
if ( ! F_20 ( V_58 , V_39 , V_43 ) )
memcpy ( V_58 , V_39 , V_43 ) ;
V_41 -> V_48 [ V_41 -> V_49 ++ ] = V_58 ;
return 0 ;
}
static void F_22 ( struct V_28 * V_29 ,
struct V_40 * V_41 )
{
}
static void F_25 ( struct V_13 * V_57 )
{
F_26 ( V_57 , L_13 ) ;
}
static void F_27 ( struct V_13 * V_57 ,
const char * V_59 ,
struct V_60 * V_15 ,
int V_61 )
{
int V_62 ;
F_28 ( V_57 , L_14 , V_59 , V_61 ) ;
while ( V_61 -- ) {
F_28 ( V_57 , L_15 ,
F_29 ( V_15 -> V_63 ) ,
F_30 ( V_15 -> V_63 ) ,
V_15 -> V_17 ,
V_15 -> V_64 ,
V_15 -> V_65 ) ;
for ( V_62 = 0 ; V_62 < V_66 ; V_62 ++ )
F_28 ( V_57 , L_16 , V_15 -> V_67 [ V_62 ] ) ;
F_28 ( V_57 , L_17 , V_15 -> V_68 ) ;
F_26 ( V_57 , F_2 ( V_15 -> V_7 ) ) ;
F_26 ( V_57 , F_3 ( V_15 -> V_11 ) ) ;
F_26 ( V_57 , F_4 ( V_15 -> V_12 ) ) ;
F_26 ( V_57 , V_15 -> V_69 ? L_18 : L_6 ) ;
F_26 ( V_57 , V_15 -> V_1 != - 1 ? L_19 : L_6 ) ;
F_26 ( V_57 , F_1 ( V_15 -> V_1 ) ) ;
F_26 ( V_57 , F_31 ( V_57 -> V_70 , V_15 -> V_71 ) ) ;
if ( V_15 -> V_59 )
F_28 ( V_57 , L_20 , V_15 -> V_59 ) ;
if ( V_15 -> V_72 != V_73 )
F_28 ( V_57 , L_21 , V_15 -> V_72 ) ;
F_26 ( V_57 , L_22 ) ;
V_15 ++ ;
}
}
static void F_32 ( struct V_13 * V_57 ,
const struct V_74 * V_75 )
{
int V_76 ;
int V_77 ;
F_28 ( V_57 , L_23 ,
V_75 -> V_78 . V_78 ) ;
if ( V_75 -> V_79 != V_2 || F_33 ( V_57 -> V_70 ) <= 3 )
return;
F_28 ( V_57 , L_24 ,
V_75 -> V_78 . V_80 ) ;
if ( F_33 ( V_57 -> V_70 ) <= 6 )
return;
F_34 (m->i915, slice, subslice)
F_28 ( V_57 , L_25 ,
V_76 , V_77 ,
V_75 -> V_78 . V_81 [ V_76 ] [ V_77 ] ) ;
F_34 (m->i915, slice, subslice)
F_28 ( V_57 , L_26 ,
V_76 , V_77 ,
V_75 -> V_78 . V_82 [ V_76 ] [ V_77 ] ) ;
}
static void F_35 ( struct V_13 * V_57 ,
const char * V_83 ,
const struct V_84 * V_85 )
{
if ( ! V_85 -> V_86 )
return;
F_28 ( V_57 , L_27 ,
V_83 , V_85 -> V_87 , V_85 -> V_88 ,
V_85 -> V_89 , V_85 -> V_86 ,
F_36 ( V_90 - V_85 -> V_90 ) ,
V_85 -> V_91 , V_85 -> V_92 ) ;
}
static void F_37 ( struct V_13 * V_57 ,
const char * V_93 ,
const struct V_94 * V_95 )
{
F_28 ( V_57 , L_28 ,
V_93 , V_95 -> V_96 , V_95 -> V_87 , V_95 -> V_97 , V_95 -> V_98 ,
V_95 -> V_88 , V_95 -> V_99 , V_95 -> V_100 ) ;
}
static void F_38 ( struct V_13 * V_57 ,
const struct V_74 * V_75 )
{
F_28 ( V_57 , L_29 , F_1 ( V_75 -> V_79 ) ) ;
F_28 ( V_57 , L_30 , V_75 -> V_21 ) ;
F_28 ( V_57 , L_31 , V_75 -> V_91 , V_75 -> V_101 ) ;
F_28 ( V_57 , L_32 ,
V_75 -> V_92 , V_75 -> V_102 , V_75 -> V_103 ) ;
F_28 ( V_57 , L_33 , V_75 -> V_104 ) ;
F_28 ( V_57 , L_34 , V_75 -> V_105 ) ;
F_28 ( V_57 , L_35 , V_75 -> V_106 ) ;
F_28 ( V_57 , L_36 ,
( V_107 ) ( V_75 -> V_108 >> 32 ) , ( V_107 ) V_75 -> V_108 ) ;
F_28 ( V_57 , L_37 , V_75 -> V_109 ) ;
F_28 ( V_57 , L_38 , V_75 -> V_110 ) ;
F_32 ( V_57 , V_75 ) ;
if ( V_75 -> V_111 ) {
T_3 V_21 = V_75 -> V_111 -> V_63 ;
T_3 V_112 = V_21 + V_75 -> V_111 -> V_113 ;
F_28 ( V_57 , L_39 ,
F_29 ( V_21 ) , F_30 ( V_21 ) ,
F_29 ( V_112 ) , F_30 ( V_112 ) ) ;
}
if ( F_33 ( V_57 -> V_70 ) >= 4 ) {
F_28 ( V_57 , L_40 ,
( V_107 ) ( V_75 -> V_114 >> 32 ) , ( V_107 ) V_75 -> V_114 ) ;
F_28 ( V_57 , L_41 , V_75 -> V_115 ) ;
F_28 ( V_57 , L_42 , V_75 -> V_116 ) ;
}
F_28 ( V_57 , L_43 , V_75 -> V_117 ) ;
F_28 ( V_57 , L_44 , F_29 ( V_75 -> V_118 ) ,
F_30 ( V_75 -> V_118 ) ) ;
if ( F_33 ( V_57 -> V_70 ) >= 6 ) {
F_28 ( V_57 , L_45 , V_75 -> V_119 ) ;
F_28 ( V_57 , L_46 , V_75 -> V_120 ) ;
F_28 ( V_57 , L_47 ,
V_75 -> V_121 [ 0 ] ) ;
F_28 ( V_57 , L_48 ,
V_75 -> V_121 [ 1 ] ) ;
if ( F_39 ( V_57 -> V_70 ) )
F_28 ( V_57 , L_49 ,
V_75 -> V_121 [ 2 ] ) ;
}
if ( F_40 ( V_57 -> V_70 ) ) {
F_28 ( V_57 , L_50 , V_75 -> V_122 . V_123 ) ;
if ( F_33 ( V_57 -> V_70 ) >= 8 ) {
int V_62 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ )
F_28 ( V_57 , L_51 ,
V_62 , V_75 -> V_122 . V_124 [ V_62 ] ) ;
} else {
F_28 ( V_57 , L_52 ,
V_75 -> V_122 . V_125 ) ;
}
}
F_28 ( V_57 , L_53 , V_75 -> V_86 ) ;
F_28 ( V_57 , L_54 , V_75 -> V_126 ) ;
F_28 ( V_57 , L_55 , F_41 ( V_75 -> V_127 ) ) ;
F_28 ( V_57 , L_56 , V_75 -> V_128 ) ;
F_28 ( V_57 , L_57 , V_75 -> V_129 ) ;
F_28 ( V_57 , L_58 , F_41 ( V_75 -> V_130 ) ) ;
F_28 ( V_57 , L_59 ,
F_42 ( V_75 -> V_131 ) ) ;
F_28 ( V_57 , L_60 ,
V_75 -> V_132 ,
F_36 ( V_90 - V_75 -> V_132 ) ) ;
F_28 ( V_57 , L_61 , V_75 -> V_133 ) ;
F_35 ( V_57 , L_62 , & V_75 -> V_134 [ 0 ] ) ;
F_35 ( V_57 , L_63 , & V_75 -> V_134 [ 1 ] ) ;
F_37 ( V_57 , L_64 , & V_75 -> V_89 ) ;
}
void F_43 ( struct V_13 * V_14 , const char * V_25 , ... )
{
T_2 args ;
va_start ( args , V_25 ) ;
F_9 ( V_14 , V_25 , args ) ;
va_end ( args ) ;
}
static int
F_44 ( int V_19 )
{
return F_45 ( V_19 , 4 ) ;
}
static bool
F_46 ( V_107 V_135 , char * V_136 )
{
int V_62 ;
if ( V_135 == 0 )
return false ;
V_136 [ 5 ] = '\0' ;
for ( V_62 = 5 ; V_62 -- ; ) {
V_136 [ V_62 ] = '!' + V_135 % 85 ;
V_135 /= 85 ;
}
return true ;
}
static void F_47 ( struct V_13 * V_57 ,
struct V_137 * V_1 ,
const char * V_59 ,
struct V_40 * V_138 )
{
char V_136 [ 6 ] ;
int V_46 ;
if ( ! V_138 )
return;
if ( V_59 ) {
F_28 ( V_57 , L_65 ,
V_1 ? V_1 -> V_59 : L_66 , V_59 ,
F_29 ( V_138 -> V_63 ) ,
F_30 ( V_138 -> V_63 ) ) ;
}
F_25 ( V_57 ) ;
for ( V_46 = 0 ; V_46 < V_138 -> V_49 ; V_46 ++ ) {
int V_62 , V_19 ;
V_19 = V_43 ;
if ( V_46 == V_138 -> V_49 - 1 )
V_19 -= V_138 -> V_56 ;
V_19 = F_44 ( V_19 ) ;
for ( V_62 = 0 ; V_62 < V_19 ; V_62 ++ ) {
if ( F_46 ( V_138 -> V_48 [ V_46 ] [ V_62 ] , V_136 ) )
F_26 ( V_57 , V_136 ) ;
else
F_26 ( V_57 , L_67 ) ;
}
}
F_26 ( V_57 , L_22 ) ;
}
static void F_48 ( struct V_13 * V_57 ,
const struct V_139 * V_140 )
{
#define F_49 ( T_4 ) err_printf(m, #x ": %s\n", yesno(info->x))
F_50 ( F_49 ) ;
#undef F_49
}
static T_5 void F_51 ( struct V_13 * V_57 ,
const char * V_59 ,
const char * type ,
const void * T_4 )
{
if ( ! F_52 ( type , L_68 ) )
F_28 ( V_57 , L_69 , V_59 , F_41 ( * ( const bool * ) T_4 ) ) ;
else if ( ! F_52 ( type , L_70 ) )
F_28 ( V_57 , L_71 , V_59 , * ( const int * ) T_4 ) ;
else if ( ! F_52 ( type , L_72 ) )
F_28 ( V_57 , L_73 , V_59 , * ( const unsigned int * ) T_4 ) ;
else if ( ! F_52 ( type , L_74 ) )
F_28 ( V_57 , L_69 , V_59 , * ( const char * * ) T_4 ) ;
else
F_53 () ;
}
static void F_54 ( struct V_13 * V_57 ,
const struct V_141 * V_142 )
{
#define F_55 ( T_6 , T_4 ) err_print_param(m, #x, #T, &p->x);
F_56 ( F_55 ) ;
#undef F_55
}
static void F_57 ( struct V_13 * V_57 ,
struct V_143 * V_70 )
{
struct V_144 * V_145 = V_70 -> V_146 . V_145 ;
F_28 ( V_57 , L_75 , V_145 -> V_147 ) ;
F_28 ( V_57 , L_76 , V_145 -> V_148 ) ;
F_28 ( V_57 , L_77 ,
V_145 -> V_149 ,
V_145 -> V_150 ) ;
}
int F_58 ( struct V_13 * V_57 ,
const struct V_151 * error )
{
struct V_143 * V_152 = V_57 -> V_70 ;
struct V_40 * V_138 ;
int V_62 , V_153 ;
if ( ! error ) {
F_28 ( V_57 , L_78 ) ;
return 0 ;
}
if ( * error -> V_154 )
F_28 ( V_57 , L_79 , error -> V_154 ) ;
F_28 ( V_57 , L_80 V_155 L_22 ) ;
F_28 ( V_57 , L_81 ,
error -> time . V_156 , error -> time . V_157 ) ;
F_28 ( V_57 , L_82 ,
error -> V_158 . V_156 , error -> V_158 . V_157 ) ;
F_28 ( V_57 , L_83 ,
error -> V_159 . V_156 , error -> V_159 . V_157 ) ;
for ( V_62 = 0 ; V_62 < F_59 ( error -> V_1 ) ; V_62 ++ ) {
if ( error -> V_1 [ V_62 ] . V_130 &&
error -> V_1 [ V_62 ] . V_89 . V_87 ) {
F_28 ( V_57 , L_84 ,
F_1 ( V_62 ) ,
error -> V_1 [ V_62 ] . V_89 . V_96 ,
error -> V_1 [ V_62 ] . V_89 . V_87 ,
error -> V_1 [ V_62 ] . V_89 . V_88 ) ;
}
}
F_28 ( V_57 , L_85 , error -> V_133 ) ;
F_28 ( V_57 , L_86 , error -> V_160 ) ;
F_28 ( V_57 , L_87 , F_60 ( error -> V_161 . V_162 ) ) ;
F_57 ( V_57 , error -> V_70 ) ;
F_28 ( V_57 , L_88 , error -> V_163 ) ;
if ( F_61 ( V_152 ) ) {
struct V_164 * V_165 = & V_152 -> V_165 ;
F_28 ( V_57 , L_89 ,
F_41 ( V_165 -> V_166 != NULL ) ) ;
F_28 ( V_57 , L_90 ,
F_62 ( V_165 -> V_167 ) ,
F_63 ( V_165 -> V_167 ) ) ;
}
F_28 ( V_57 , L_91 , F_41 ( error -> V_168 ) ) ;
F_28 ( V_57 , L_92 , F_41 ( error -> V_169 ) ) ;
F_28 ( V_57 , L_93 , F_41 ( error -> V_170 ) ) ;
F_28 ( V_57 , L_94 , error -> V_171 ) ;
F_28 ( V_57 , L_95 , error -> V_172 ) ;
for ( V_62 = 0 ; V_62 < error -> V_173 ; V_62 ++ )
F_28 ( V_57 , L_96 , V_62 , error -> V_174 [ V_62 ] ) ;
F_28 ( V_57 , L_97 , error -> V_175 ) ;
F_28 ( V_57 , L_98 , error -> V_176 ) ;
F_28 ( V_57 , L_99 , error -> V_177 ) ;
F_28 ( V_57 , L_100 , error -> V_178 ) ;
F_28 ( V_57 , L_101 , V_152 -> V_179 . V_180 ) ;
for ( V_62 = 0 ; V_62 < error -> V_181 ; V_62 ++ )
F_28 ( V_57 , L_102 , V_62 , error -> V_182 [ V_62 ] ) ;
if ( F_33 ( V_152 ) >= 6 ) {
F_28 ( V_57 , L_103 , error -> error ) ;
if ( F_33 ( V_152 ) >= 8 )
F_28 ( V_57 , L_104 ,
error -> V_183 , error -> V_184 ) ;
F_28 ( V_57 , L_105 , error -> V_185 ) ;
}
if ( F_64 ( V_152 ) )
F_28 ( V_57 , L_106 , error -> V_186 ) ;
for ( V_62 = 0 ; V_62 < F_59 ( error -> V_1 ) ; V_62 ++ ) {
if ( error -> V_1 [ V_62 ] . V_79 != - 1 )
F_38 ( V_57 , & error -> V_1 [ V_62 ] ) ;
}
for ( V_62 = 0 ; V_62 < F_59 ( error -> V_187 ) ; V_62 ++ ) {
char V_24 [ 128 ] ;
int V_19 , V_188 = 1 ;
if ( ! error -> V_187 [ V_62 ] )
break;
V_19 = F_65 ( V_24 , sizeof( V_24 ) , L_107 ) ;
for ( V_153 = 0 ; V_153 < F_59 ( error -> V_1 ) ; V_153 ++ ) {
if ( error -> V_1 [ V_153 ] . V_189 != error -> V_187 [ V_62 ] )
continue;
V_19 += F_65 ( V_24 + V_19 , sizeof( V_24 ) , L_108 ,
V_188 ? L_6 : L_109 ,
V_152 -> V_1 [ V_153 ] -> V_59 ) ;
V_188 = 0 ;
}
F_65 ( V_24 + V_19 , sizeof( V_24 ) , L_110 ) ;
F_27 ( V_57 , V_24 ,
error -> V_190 [ V_62 ] ,
error -> V_191 [ V_62 ] ) ;
}
F_27 ( V_57 , L_111 ,
error -> V_192 ,
error -> V_193 ) ;
for ( V_62 = 0 ; V_62 < F_59 ( error -> V_1 ) ; V_62 ++ ) {
const struct V_74 * V_75 = & error -> V_1 [ V_62 ] ;
V_138 = V_75 -> V_111 ;
if ( V_138 ) {
F_26 ( V_57 , V_152 -> V_1 [ V_62 ] -> V_59 ) ;
if ( V_75 -> V_89 . V_87 )
F_28 ( V_57 , L_112 ,
V_75 -> V_89 . V_96 ,
V_75 -> V_89 . V_87 ,
V_75 -> V_89 . V_97 ,
V_75 -> V_89 . V_98 ,
V_75 -> V_89 . V_88 ) ;
F_28 ( V_57 , L_113 ,
F_29 ( V_138 -> V_63 ) ,
F_30 ( V_138 -> V_63 ) ) ;
F_47 ( V_57 , V_152 -> V_1 [ V_62 ] , NULL , V_138 ) ;
}
for ( V_153 = 0 ; V_153 < V_75 -> V_194 ; V_153 ++ )
F_47 ( V_57 , V_152 -> V_1 [ V_62 ] ,
L_114 , V_75 -> V_195 [ V_153 ] ) ;
if ( V_75 -> V_196 ) {
F_28 ( V_57 , L_115 ,
V_152 -> V_1 [ V_62 ] -> V_59 ,
V_75 -> V_196 ) ;
for ( V_153 = 0 ; V_153 < V_75 -> V_196 ; V_153 ++ )
F_35 ( V_57 , L_19 , & V_75 -> V_197 [ V_153 ] ) ;
}
if ( F_66 ( V_75 -> V_198 ) ) {
F_28 ( V_57 , L_116 ,
V_152 -> V_1 [ V_62 ] -> V_59 ) ;
} else if ( V_75 -> V_199 ) {
F_28 ( V_57 , L_117 ,
V_152 -> V_1 [ V_62 ] -> V_59 ,
V_75 -> V_199 ) ;
for ( V_153 = 0 ; V_153 < V_75 -> V_199 ; V_153 ++ ) {
F_28 ( V_57 , L_118 ,
V_75 -> V_198 [ V_153 ] . V_86 ,
V_75 -> V_198 [ V_153 ] . V_96 ,
V_75 -> V_198 [ V_153 ] . V_87 ) ;
}
}
F_47 ( V_57 , V_152 -> V_1 [ V_62 ] ,
L_119 , V_75 -> V_200 ) ;
F_47 ( V_57 , V_152 -> V_1 [ V_62 ] ,
L_120 , V_75 -> V_201 ) ;
F_47 ( V_57 , V_152 -> V_1 [ V_62 ] ,
L_121 , V_75 -> V_95 ) ;
F_47 ( V_57 , V_152 -> V_1 [ V_62 ] ,
L_122 , V_75 -> V_202 ) ;
F_47 ( V_57 , V_152 -> V_1 [ V_62 ] ,
L_123 , V_75 -> V_203 ) ;
}
F_47 ( V_57 , NULL , L_124 , error -> V_204 ) ;
F_47 ( V_57 , NULL , L_125 , error -> V_205 ) ;
if ( error -> V_206 )
F_67 ( V_57 , error -> V_206 ) ;
if ( error -> V_207 )
F_68 ( V_57 , error -> V_207 ) ;
F_48 ( V_57 , & error -> V_161 ) ;
F_54 ( V_57 , & error -> V_208 ) ;
if ( V_57 -> V_16 == 0 && V_57 -> V_15 )
return V_57 -> V_15 ;
return 0 ;
}
int F_69 ( struct V_13 * V_209 ,
struct V_143 * V_70 ,
T_1 V_61 , T_7 V_20 )
{
memset ( V_209 , 0 , sizeof( * V_209 ) ) ;
V_209 -> V_70 = V_70 ;
V_209 -> V_17 = V_61 + 1 > V_43 ? V_61 + 1 : V_43 ;
V_209 -> V_24 = F_13 ( V_209 -> V_17 ,
V_210 | V_211 | V_36 ) ;
if ( V_209 -> V_24 == NULL ) {
V_209 -> V_17 = V_43 ;
V_209 -> V_24 = F_13 ( V_209 -> V_17 , V_210 ) ;
}
if ( V_209 -> V_24 == NULL ) {
V_209 -> V_17 = 128 ;
V_209 -> V_24 = F_13 ( V_209 -> V_17 , V_210 ) ;
}
if ( V_209 -> V_24 == NULL )
return - V_47 ;
V_209 -> V_21 = V_20 ;
return 0 ;
}
static void F_70 ( struct V_40 * V_138 )
{
int V_46 ;
if ( V_138 == NULL )
return;
for ( V_46 = 0 ; V_46 < V_138 -> V_49 ; V_46 ++ )
F_24 ( ( unsigned long ) V_138 -> V_48 [ V_46 ] ) ;
F_16 ( V_138 ) ;
}
static T_5 void F_71 ( const char * type , void * T_4 )
{
if ( ! F_52 ( type , L_74 ) )
F_16 ( * ( void * * ) T_4 ) ;
}
void F_72 ( struct V_212 * V_213 )
{
struct V_151 * error =
F_73 ( V_213 , F_74 ( * error ) , V_214 ) ;
long V_62 , V_153 ;
for ( V_62 = 0 ; V_62 < F_59 ( error -> V_1 ) ; V_62 ++ ) {
struct V_74 * V_75 = & error -> V_1 [ V_62 ] ;
for ( V_153 = 0 ; V_153 < V_75 -> V_194 ; V_153 ++ )
F_70 ( V_75 -> V_195 [ V_153 ] ) ;
F_16 ( V_75 -> V_195 ) ;
F_70 ( V_75 -> V_111 ) ;
F_70 ( V_75 -> V_203 ) ;
F_70 ( V_75 -> V_200 ) ;
F_70 ( V_75 -> V_201 ) ;
F_70 ( V_75 -> V_95 ) ;
F_70 ( V_75 -> V_202 ) ;
F_16 ( V_75 -> V_197 ) ;
if ( ! F_75 ( V_75 -> V_198 ) )
F_16 ( V_75 -> V_198 ) ;
}
F_70 ( error -> V_204 ) ;
F_70 ( error -> V_205 ) ;
for ( V_62 = 0 ; V_62 < F_59 ( error -> V_190 ) ; V_62 ++ )
F_16 ( error -> V_190 [ V_62 ] ) ;
F_16 ( error -> V_192 ) ;
F_16 ( error -> V_206 ) ;
F_16 ( error -> V_207 ) ;
#define FREE ( T_6 , T_4 ) free_param(#T, &error->params.x);
F_56 ( FREE ) ;
#undef FREE
F_16 ( error ) ;
}
static struct V_40 *
F_76 ( struct V_143 * V_70 ,
struct V_215 * V_216 )
{
struct V_217 * V_218 = & V_70 -> V_218 ;
const T_3 V_219 = V_218 -> V_220 . V_21 ;
struct V_40 * V_41 ;
struct V_28 V_28 ;
unsigned long V_221 ;
struct V_222 V_223 ;
T_8 V_224 ;
if ( ! V_216 )
return NULL ;
V_221 = F_77 ( T_3 , V_216 -> V_17 , V_216 -> V_138 -> V_225 . V_17 ) >> V_226 ;
V_221 = F_45 ( 10 * V_221 , 8 ) ;
V_41 = F_13 ( sizeof( * V_41 ) + V_221 * sizeof( V_107 * ) ,
V_35 | V_36 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_63 = V_216 -> V_227 . V_21 ;
V_41 -> V_113 = V_216 -> V_227 . V_17 ;
V_41 -> V_49 = 0 ;
V_41 -> V_56 = 0 ;
if ( ! F_12 ( & V_28 ) ) {
F_16 ( V_41 ) ;
return NULL ;
}
F_78 (dma, iter, vma->pages) {
void T_9 * V_228 ;
int V_229 ;
V_218 -> V_225 . V_230 ( & V_218 -> V_225 , V_224 , V_219 ,
V_231 , 0 ) ;
V_228 = F_79 ( & V_218 -> V_232 , V_219 ) ;
V_229 = F_19 ( & V_28 , ( void V_233 * ) V_228 , V_41 ) ;
F_80 ( V_228 ) ;
if ( V_229 )
goto V_234;
}
goto V_136;
V_234:
while ( V_41 -> V_49 -- )
F_24 ( ( unsigned long ) V_41 -> V_48 [ V_41 -> V_49 ] ) ;
F_16 ( V_41 ) ;
V_41 = NULL ;
V_136:
F_22 ( & V_28 , V_41 ) ;
V_218 -> V_225 . V_235 ( & V_218 -> V_225 , V_219 , V_43 ) ;
return V_41 ;
}
static inline T_10
F_81 ( struct V_236 * V_100 )
{
struct V_237 * V_238 ;
V_238 = F_82 ( V_100 ) ;
return V_238 ? V_238 -> V_239 : 0 ;
}
static inline int
F_83 ( struct V_236 * V_100 )
{
struct V_237 * V_238 ;
V_238 = F_82 ( V_100 ) ;
return V_238 ? V_238 -> V_1 -> V_240 : - 1 ;
}
static void F_84 ( struct V_60 * V_15 ,
struct V_215 * V_216 )
{
struct V_241 * V_138 = V_216 -> V_138 ;
int V_62 ;
V_15 -> V_17 = V_138 -> V_225 . V_17 ;
V_15 -> V_59 = V_138 -> V_225 . V_59 ;
for ( V_62 = 0 ; V_62 < V_66 ; V_62 ++ )
V_15 -> V_67 [ V_62 ] = F_81 ( & V_216 -> V_242 [ V_62 ] ) ;
V_15 -> V_68 = F_81 ( & V_138 -> V_243 ) ;
V_15 -> V_1 = F_83 ( & V_138 -> V_243 ) ;
V_15 -> V_63 = V_216 -> V_227 . V_21 ;
V_15 -> V_64 = V_138 -> V_225 . V_64 ;
V_15 -> V_65 = V_138 -> V_225 . V_65 ;
V_15 -> V_72 = V_216 -> V_182 ? V_216 -> V_182 -> V_240 : - 1 ;
V_15 -> V_7 = F_85 ( V_138 ) ;
V_15 -> V_11 = V_138 -> V_244 . V_11 ;
V_15 -> V_12 = V_138 -> V_244 . V_245 != V_246 ;
V_15 -> V_69 = V_138 -> V_69 . V_244 != NULL ;
V_15 -> V_71 = V_138 -> V_71 ;
}
static V_107 F_86 ( struct V_60 * V_15 ,
int V_61 , struct V_247 * V_91 ,
bool V_248 )
{
struct V_215 * V_216 ;
int V_62 = 0 ;
F_87 (vma, head, vm_link) {
if ( V_248 && ! F_88 ( V_216 ) )
continue;
F_84 ( V_15 ++ , V_216 ) ;
if ( ++ V_62 == V_61 )
break;
}
return V_62 ;
}
static T_10 F_89 ( struct V_143 * V_152 ,
struct V_151 * error ,
int * V_79 )
{
T_10 V_249 = 0 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_66 ; V_62 ++ ) {
if ( error -> V_1 [ V_62 ] . V_130 ) {
if ( V_79 )
* V_79 = V_62 ;
return error -> V_1 [ V_62 ] . V_110 ^
error -> V_1 [ V_62 ] . V_78 . V_78 ;
}
}
return V_249 ;
}
static void F_90 ( struct V_143 * V_152 ,
struct V_151 * error )
{
int V_62 ;
if ( F_33 ( V_152 ) >= 6 ) {
for ( V_62 = 0 ; V_62 < V_152 -> V_250 ; V_62 ++ )
error -> V_182 [ V_62 ] = F_91 ( F_92 ( V_62 ) ) ;
} else if ( F_33 ( V_152 ) >= 4 ) {
for ( V_62 = 0 ; V_62 < V_152 -> V_250 ; V_62 ++ )
error -> V_182 [ V_62 ] = F_91 ( F_93 ( V_62 ) ) ;
} else {
for ( V_62 = 0 ; V_62 < V_152 -> V_250 ; V_62 ++ )
error -> V_182 [ V_62 ] = F_94 ( F_95 ( V_62 ) ) ;
}
error -> V_181 = V_62 ;
}
static inline V_107
F_96 ( struct V_137 * V_1 ,
struct V_137 * V_251 )
{
int V_252 ;
V_252 = ( V_251 - V_1 ) - 1 ;
if ( V_252 < 0 )
V_252 += V_66 ;
return V_252 ;
}
static void F_97 ( struct V_151 * error ,
struct V_137 * V_1 ,
struct V_74 * V_75 )
{
struct V_143 * V_152 = V_1 -> V_70 ;
struct V_137 * V_253 ;
enum V_254 V_240 ;
if ( ! error -> V_204 )
return;
F_98 (to, dev_priv, id) {
int V_252 ;
T_11 V_255 ;
V_107 * V_26 ;
if ( V_1 == V_253 )
continue;
V_255 =
( F_99 ( V_1 , V_240 ) & ( V_43 - 1 ) ) / 4 ;
V_26 = error -> V_204 -> V_48 [ 0 ] ;
V_252 = F_96 ( V_1 , V_253 ) ;
V_75 -> V_121 [ V_252 ] = V_26 [ V_255 ] ;
}
}
static void F_100 ( struct V_137 * V_1 ,
struct V_74 * V_75 )
{
struct V_143 * V_152 = V_1 -> V_70 ;
V_75 -> V_121 [ 0 ] = F_94 ( F_101 ( V_1 -> V_256 ) ) ;
V_75 -> V_121 [ 1 ] = F_94 ( F_102 ( V_1 -> V_256 ) ) ;
if ( F_39 ( V_152 ) )
V_75 -> V_121 [ 2 ] =
F_94 ( F_103 ( V_1 -> V_256 ) ) ;
}
static void F_104 ( struct V_137 * V_1 ,
struct V_74 * V_75 )
{
struct V_257 * V_258 = & V_1 -> V_259 ;
struct V_260 * V_261 ;
struct V_262 * V_263 ;
int V_61 ;
V_75 -> V_199 = 0 ;
V_75 -> V_198 = NULL ;
if ( F_105 ( & V_258 -> V_198 ) )
return;
if ( ! F_106 ( & V_258 -> V_264 ) ) {
V_75 -> V_198 = F_107 ( - V_265 ) ;
return;
}
V_61 = 0 ;
for ( V_263 = F_108 ( & V_258 -> V_198 ) ; V_263 != NULL ; V_263 = F_109 ( V_263 ) )
V_61 ++ ;
F_110 ( & V_258 -> V_264 ) ;
V_261 = NULL ;
if ( V_61 )
V_261 = F_111 ( V_61 ,
sizeof( struct V_260 ) ,
V_35 ) ;
if ( ! V_261 )
return;
if ( ! F_106 ( & V_258 -> V_264 ) ) {
F_16 ( V_261 ) ;
V_75 -> V_198 = F_107 ( - V_265 ) ;
return;
}
V_75 -> V_198 = V_261 ;
for ( V_263 = F_108 ( & V_258 -> V_198 ) ; V_263 ; V_263 = F_109 ( V_263 ) ) {
struct V_266 * V_267 = F_112 ( V_263 , F_74 ( * V_267 ) , V_227 ) ;
strcpy ( V_261 -> V_96 , V_267 -> V_268 -> V_96 ) ;
V_261 -> V_87 = V_267 -> V_268 -> V_87 ;
V_261 -> V_86 = V_267 -> V_86 ;
V_261 ++ ;
if ( ++ V_75 -> V_199 == V_61 )
break;
}
F_110 ( & V_258 -> V_264 ) ;
}
static void F_113 ( struct V_151 * error ,
struct V_137 * V_1 ,
struct V_74 * V_75 )
{
struct V_143 * V_152 = V_1 -> V_70 ;
if ( F_33 ( V_152 ) >= 6 ) {
V_75 -> V_119 = F_94 ( F_114 ( V_1 -> V_256 ) ) ;
V_75 -> V_120 = F_94 ( F_115 ( V_1 ) ) ;
if ( F_33 ( V_152 ) >= 8 )
F_97 ( error , V_1 , V_75 ) ;
else
F_100 ( V_1 , V_75 ) ;
}
if ( F_33 ( V_152 ) >= 4 ) {
V_75 -> V_118 = F_94 ( F_116 ( V_1 -> V_256 ) ) ;
V_75 -> V_109 = F_94 ( F_117 ( V_1 -> V_256 ) ) ;
V_75 -> V_110 = F_94 ( F_118 ( V_1 -> V_256 ) ) ;
V_75 -> V_116 = F_94 ( F_119 ( V_1 -> V_256 ) ) ;
V_75 -> V_114 = F_94 ( F_120 ( V_1 -> V_256 ) ) ;
if ( F_33 ( V_152 ) >= 8 ) {
V_75 -> V_118 |= ( T_3 ) F_94 ( F_121 ( V_1 -> V_256 ) ) << 32 ;
V_75 -> V_114 |= ( T_3 ) F_94 ( F_122 ( V_1 -> V_256 ) ) << 32 ;
}
V_75 -> V_115 = F_94 ( F_123 ( V_1 -> V_256 ) ) ;
} else {
V_75 -> V_118 = F_94 ( V_269 ) ;
V_75 -> V_109 = F_94 ( V_270 ) ;
V_75 -> V_110 = F_94 ( V_271 ) ;
}
F_124 ( V_1 , & V_75 -> V_78 ) ;
V_75 -> V_127 = F_125 ( V_1 ) ;
V_75 -> V_117 = F_94 ( F_126 ( V_1 -> V_256 ) ) ;
V_75 -> V_108 = F_127 ( V_1 ) ;
V_75 -> V_86 = F_128 ( V_1 ) ;
V_75 -> V_126 = F_129 ( V_1 ) ;
V_75 -> V_21 = F_130 ( V_1 ) ;
V_75 -> V_91 = F_131 ( V_1 ) ;
V_75 -> V_92 = F_132 ( V_1 ) ;
V_75 -> V_104 = F_133 ( V_1 ) ;
if ( F_33 ( V_152 ) > 2 )
V_75 -> V_105 = F_134 ( V_1 ) ;
if ( ! F_135 ( V_152 ) ) {
T_12 V_272 ;
if ( F_64 ( V_152 ) ) {
switch ( V_1 -> V_240 ) {
default:
case V_2 :
V_272 = V_273 ;
break;
case V_4 :
V_272 = V_274 ;
break;
case V_3 :
V_272 = V_275 ;
break;
case V_5 :
V_272 = V_276 ;
break;
}
} else if ( F_136 ( V_1 -> V_70 ) ) {
V_272 = F_137 ( V_1 -> V_256 ) ;
} else {
V_272 = F_138 ( V_1 -> V_256 ) ;
}
V_75 -> V_106 = F_94 ( V_272 ) ;
}
V_75 -> V_132 = V_1 -> V_277 . V_278 ;
V_75 -> V_131 = V_1 -> V_277 . V_279 ;
V_75 -> V_130 = V_1 -> V_277 . V_280 ;
V_75 -> V_133 = F_139 ( & V_152 -> V_179 ,
V_1 ) ;
if ( F_40 ( V_152 ) ) {
int V_62 ;
V_75 -> V_122 . V_123 = F_94 ( F_140 ( V_1 ) ) ;
if ( F_136 ( V_152 ) )
V_75 -> V_122 . V_125 =
F_94 ( F_141 ( V_1 ) ) ;
else if ( F_64 ( V_152 ) )
V_75 -> V_122 . V_125 =
F_94 ( F_142 ( V_1 ) ) ;
else if ( F_33 ( V_152 ) >= 8 )
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
V_75 -> V_122 . V_124 [ V_62 ] =
F_94 ( F_143 ( V_1 , V_62 ) ) ;
V_75 -> V_122 . V_124 [ V_62 ] <<= 32 ;
V_75 -> V_122 . V_124 [ V_62 ] |=
F_94 ( F_144 ( V_1 , V_62 ) ) ;
}
}
}
static void F_145 ( struct V_237 * V_238 ,
struct V_84 * V_85 )
{
V_85 -> V_89 = V_238 -> V_95 -> V_98 ;
V_85 -> V_88 = F_146 ( & V_238 -> V_95 -> V_88 ) ;
V_85 -> V_86 = V_238 -> V_239 ;
V_85 -> V_90 = V_238 -> V_281 ;
V_85 -> V_91 = V_238 -> V_91 ;
V_85 -> V_92 = V_238 -> V_92 ;
F_147 () ;
V_85 -> V_87 = V_238 -> V_95 -> V_87 ? F_148 ( V_238 -> V_95 -> V_87 ) : 0 ;
F_149 () ;
}
static void F_150 ( struct V_137 * V_1 ,
struct V_237 * V_188 ,
struct V_74 * V_75 )
{
struct V_237 * V_238 ;
int V_61 ;
V_61 = 0 ;
V_238 = V_188 ;
F_151 (request, &engine->timeline->requests, link)
V_61 ++ ;
if ( ! V_61 )
return;
V_75 -> V_197 = F_152 ( V_61 , sizeof( * V_75 -> V_197 ) , V_35 ) ;
if ( ! V_75 -> V_197 )
return;
V_75 -> V_196 = V_61 ;
V_61 = 0 ;
V_238 = V_188 ;
F_151 (request, &engine->timeline->requests, link) {
if ( V_61 >= V_75 -> V_196 ) {
break;
}
F_145 ( V_238 , & V_75 -> V_197 [ V_61 ++ ] ) ;
}
V_75 -> V_196 = V_61 ;
}
static void F_153 ( struct V_137 * V_1 ,
struct V_74 * V_75 )
{
const struct V_282 * V_283 = V_1 -> V_282 ;
unsigned int V_284 ;
for ( V_284 = 0 ; V_284 < F_59 ( V_1 -> V_282 ) ; V_284 ++ ) {
struct V_237 * V_285 = F_154 ( & V_283 [ V_284 ] ) ;
if ( ! V_285 )
break;
F_145 ( V_285 , & V_75 -> V_134 [ V_284 ] ) ;
}
}
static void F_155 ( struct V_94 * V_14 ,
struct V_286 * V_95 )
{
if ( V_95 -> V_87 ) {
struct V_287 * V_288 ;
F_147 () ;
V_288 = F_156 ( V_95 -> V_87 , V_289 ) ;
if ( V_288 ) {
strcpy ( V_14 -> V_96 , V_288 -> V_96 ) ;
V_14 -> V_87 = V_288 -> V_87 ;
}
F_149 () ;
}
V_14 -> V_97 = V_95 -> V_290 ;
V_14 -> V_98 = V_95 -> V_98 ;
V_14 -> V_88 = F_146 ( & V_95 -> V_88 ) ;
V_14 -> V_99 = F_146 ( & V_95 -> V_291 ) ;
V_14 -> V_100 = F_146 ( & V_95 -> V_292 ) ;
}
static void F_157 ( struct V_237 * V_238 ,
struct V_74 * V_75 )
{
struct V_293 * V_29 ;
struct V_40 * * V_294 ;
long V_61 ;
V_61 = 0 ;
for ( V_29 = V_238 -> V_295 ; V_29 ; V_29 = V_29 -> V_296 )
V_61 ++ ;
V_294 = NULL ;
if ( V_61 )
V_294 = F_152 ( V_61 , sizeof( * V_294 ) , V_35 ) ;
if ( ! V_294 )
return;
V_61 = 0 ;
for ( V_29 = V_238 -> V_295 ; V_29 ; V_29 = V_29 -> V_296 ) {
V_294 [ V_61 ] = F_76 ( V_238 -> V_70 , V_29 -> V_216 ) ;
if ( ! V_294 [ V_61 ] )
break;
V_61 ++ ;
}
V_75 -> V_195 = V_294 ;
V_75 -> V_194 = V_61 ;
}
static void F_158 ( struct V_143 * V_152 ,
struct V_151 * error )
{
struct V_217 * V_218 = & V_152 -> V_218 ;
int V_62 ;
error -> V_204 =
F_76 ( V_152 , V_152 -> V_204 ) ;
for ( V_62 = 0 ; V_62 < V_66 ; V_62 ++ ) {
struct V_137 * V_1 = V_152 -> V_1 [ V_62 ] ;
struct V_74 * V_75 = & error -> V_1 [ V_62 ] ;
struct V_237 * V_238 ;
V_75 -> V_79 = - 1 ;
if ( ! V_1 )
continue;
V_75 -> V_79 = V_62 ;
F_113 ( error , V_1 , V_75 ) ;
F_104 ( V_1 , V_75 ) ;
F_153 ( V_1 , V_75 ) ;
V_238 = F_159 ( V_1 ) ;
if ( V_238 ) {
struct V_297 * V_298 ;
V_75 -> V_189 = V_238 -> V_95 -> V_299 ?
& V_238 -> V_95 -> V_299 -> V_225 : & V_218 -> V_225 ;
F_155 ( & V_75 -> V_89 , V_238 -> V_95 ) ;
V_75 -> V_111 =
F_76 ( V_152 ,
V_238 -> V_300 ) ;
if ( F_160 ( V_152 ) )
V_75 -> V_203 =
F_76 ( V_152 ,
V_1 -> V_301 ) ;
F_157 ( V_238 , V_75 ) ;
V_75 -> V_95 =
F_76 ( V_152 ,
V_238 -> V_95 -> V_1 [ V_62 ] . V_302 ) ;
error -> V_303 |=
F_161 ( V_238 -> V_95 ) ;
V_75 -> V_101 = V_238 -> V_91 ;
V_75 -> V_102 = V_238 -> V_304 ;
V_75 -> V_103 = V_238 -> V_92 ;
V_298 = V_238 -> V_298 ;
V_75 -> V_128 = V_298 -> V_91 ;
V_75 -> V_129 = V_298 -> V_92 ;
V_75 -> V_200 =
F_76 ( V_152 , V_298 -> V_216 ) ;
F_150 ( V_1 , V_238 , V_75 ) ;
}
V_75 -> V_201 =
F_76 ( V_152 ,
V_1 -> V_305 . V_216 ) ;
V_75 -> V_202 =
F_76 ( V_152 , V_1 -> V_202 . V_216 ) ;
}
}
static void F_162 ( struct V_143 * V_152 ,
struct V_151 * error ,
struct V_306 * V_189 ,
int V_252 )
{
struct V_60 * V_190 ;
struct V_215 * V_216 ;
int V_61 ;
V_61 = 0 ;
F_87 (vma, &vm->active_list, vm_link)
V_61 ++ ;
V_190 = NULL ;
if ( V_61 )
V_190 = F_152 ( V_61 , sizeof( * V_190 ) , V_35 ) ;
if ( V_190 )
V_61 = F_86 ( V_190 , V_61 , & V_189 -> V_307 , false ) ;
else
V_61 = 0 ;
error -> V_187 [ V_252 ] = V_189 ;
error -> V_190 [ V_252 ] = V_190 ;
error -> V_191 [ V_252 ] = V_61 ;
}
static void F_163 ( struct V_143 * V_152 ,
struct V_151 * error )
{
int V_308 = 0 , V_62 , V_153 ;
F_164 ( F_59 ( error -> V_1 ) > F_59 ( error -> V_190 ) ) ;
F_164 ( F_59 ( error -> V_190 ) != F_59 ( error -> V_187 ) ) ;
F_164 ( F_59 ( error -> V_190 ) != F_59 ( error -> V_191 ) ) ;
for ( V_62 = 0 ; V_62 < F_59 ( error -> V_1 ) ; V_62 ++ ) {
struct V_74 * V_75 = & error -> V_1 [ V_62 ] ;
bool V_309 ;
if ( ! V_75 -> V_189 )
continue;
V_309 = false ;
for ( V_153 = 0 ; V_153 < V_62 && ! V_309 ; V_153 ++ )
V_309 = error -> V_1 [ V_153 ] . V_189 == V_75 -> V_189 ;
if ( ! V_309 )
F_162 ( V_152 , error , V_75 -> V_189 , V_308 ++ ) ;
}
}
static void F_165 ( struct V_143 * V_152 ,
struct V_151 * error )
{
struct V_306 * V_189 = & V_152 -> V_218 . V_225 ;
struct V_60 * V_294 ;
struct V_215 * V_216 ;
int V_310 , V_311 ;
V_310 = 0 ;
F_87 (vma, &vm->active_list, vm_link)
V_310 ++ ;
V_311 = 0 ;
F_87 (vma, &vm->inactive_list, vm_link)
V_311 ++ ;
V_294 = NULL ;
if ( V_310 + V_311 )
V_294 = F_152 ( V_310 + V_311 ,
sizeof( * V_294 ) , V_35 ) ;
if ( ! V_294 )
return;
V_310 = F_86 ( V_294 , V_310 ,
& V_189 -> V_307 , true ) ;
V_311 = F_86 ( V_294 + V_310 , V_311 ,
& V_189 -> V_312 , true ) ;
error -> V_193 = V_310 + V_311 ;
error -> V_192 = V_294 ;
}
static void F_166 ( struct V_143 * V_152 ,
struct V_151 * error )
{
if ( ! V_152 -> V_313 . log . V_216 || ( V_70 . V_314 < 0 ) )
return;
error -> V_205 = F_76 ( V_152 ,
V_152 -> V_313 . log . V_216 ) ;
}
static void F_167 ( struct V_143 * V_152 ,
struct V_151 * error )
{
int V_62 ;
if ( F_168 ( V_152 ) ) {
error -> V_174 [ 0 ] = F_94 ( V_315 ) ;
error -> V_172 = F_94 ( V_316 ) ;
error -> V_176 = F_169 ( V_317 ) ;
}
if ( F_64 ( V_152 ) )
error -> V_186 = F_94 ( V_318 ) ;
if ( F_33 ( V_152 ) >= 8 ) {
error -> V_184 = F_94 ( V_319 ) ;
error -> V_183 = F_94 ( V_320 ) ;
}
if ( F_136 ( V_152 ) ) {
error -> V_176 = F_169 ( V_321 ) ;
error -> V_322 = F_94 ( V_323 ) ;
error -> V_123 = F_94 ( V_324 ) ;
}
if ( F_33 ( V_152 ) >= 7 )
error -> V_176 = F_169 ( V_325 ) ;
if ( F_33 ( V_152 ) >= 6 ) {
error -> V_177 = F_94 ( V_326 ) ;
error -> error = F_94 ( V_327 ) ;
error -> V_185 = F_94 ( V_328 ) ;
}
if ( F_33 ( V_152 ) >= 5 )
error -> V_178 = F_94 ( V_329 ) ;
if ( F_136 ( V_152 ) || F_64 ( V_152 ) ) {
error -> V_330 = F_94 ( V_331 ) ;
error -> V_332 = F_94 ( V_333 ) ;
}
if ( F_33 ( V_152 ) >= 8 ) {
error -> V_172 = F_94 ( V_334 ) ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ )
error -> V_174 [ V_62 ] = F_94 ( F_170 ( V_62 ) ) ;
error -> V_173 = 4 ;
} else if ( F_171 ( V_152 ) ) {
error -> V_172 = F_94 ( V_335 ) ;
error -> V_174 [ 0 ] = F_94 ( V_315 ) ;
error -> V_173 = 1 ;
} else if ( F_172 ( V_152 ) ) {
error -> V_172 = F_173 ( V_336 ) ;
} else if ( ! F_168 ( V_152 ) ) {
error -> V_172 = F_94 ( V_336 ) ;
}
error -> V_171 = F_94 ( V_337 ) ;
error -> V_175 = F_94 ( V_338 ) ;
}
static void F_174 ( struct V_143 * V_152 ,
struct V_151 * error ,
V_107 V_339 ,
const char * V_154 )
{
V_107 V_340 ;
int V_79 = - 1 , V_19 ;
V_340 = F_89 ( V_152 , error , & V_79 ) ;
V_19 = F_65 ( error -> V_154 , sizeof( error -> V_154 ) ,
L_126 ,
F_33 ( V_152 ) , V_79 , V_340 ) ;
if ( V_79 != - 1 && error -> V_1 [ V_79 ] . V_89 . V_87 )
V_19 += F_65 ( error -> V_154 + V_19 ,
sizeof( error -> V_154 ) - V_19 ,
L_127 ,
error -> V_1 [ V_79 ] . V_89 . V_96 ,
error -> V_1 [ V_79 ] . V_89 . V_87 ) ;
F_65 ( error -> V_154 + V_19 , sizeof( error -> V_154 ) - V_19 ,
L_128 ,
V_154 ,
V_339 ? L_129 : L_130 ) ;
}
static void F_175 ( struct V_143 * V_152 ,
struct V_151 * error )
{
error -> V_168 = V_152 -> V_341 . V_168 ;
error -> V_169 = F_146 ( & V_152 -> V_342 . V_343 ) ;
error -> V_170 = V_152 -> V_342 . V_170 ;
error -> V_163 = - 1 ;
#ifdef F_176
error -> V_163 = V_344 ;
#endif
error -> V_133 = F_177 ( & V_152 -> V_179 ) ;
error -> V_160 = V_152 -> V_160 ;
memcpy ( & error -> V_161 ,
F_178 ( V_152 ) ,
sizeof( error -> V_161 ) ) ;
}
static T_5 void F_179 ( const char * type , void * T_4 )
{
if ( ! F_52 ( type , L_74 ) )
* ( void * * ) T_4 = F_180 ( * ( void * * ) T_4 , V_35 ) ;
}
static int F_181 ( void * V_345 )
{
struct V_151 * error = V_345 ;
F_182 ( & error -> time ) ;
error -> V_158 = F_183 ( F_184 () ) ;
error -> V_159 =
F_183 ( F_185 ( F_186 () ,
error -> V_70 -> V_341 . V_346 ) ) ;
error -> V_208 = V_70 ;
#define F_187 ( T_6 , T_4 ) dup_param(#T, &error->params.x);
F_56 ( F_187 ) ;
#undef F_187
F_175 ( error -> V_70 , error ) ;
F_167 ( error -> V_70 , error ) ;
F_90 ( error -> V_70 , error ) ;
F_158 ( error -> V_70 , error ) ;
F_163 ( error -> V_70 , error ) ;
F_165 ( error -> V_70 , error ) ;
F_166 ( error -> V_70 , error ) ;
error -> V_206 = F_188 ( error -> V_70 ) ;
error -> V_207 = F_189 ( error -> V_70 ) ;
return 0 ;
}
struct V_151 *
F_190 ( struct V_143 * V_70 )
{
struct V_151 * error ;
error = F_191 ( sizeof( * error ) , V_35 ) ;
if ( ! error )
return NULL ;
F_192 ( & error -> V_214 ) ;
error -> V_70 = V_70 ;
F_193 ( F_181 , error , NULL ) ;
return error ;
}
void F_194 ( struct V_143 * V_152 ,
V_107 V_339 ,
const char * V_154 )
{
static bool V_347 ;
struct V_151 * error ;
unsigned long V_348 ;
if ( ! V_70 . V_220 )
return;
if ( F_195 ( V_152 -> V_179 . V_349 ) )
return;
error = F_190 ( V_152 ) ;
if ( ! error ) {
F_196 ( L_131 ) ;
return;
}
F_174 ( V_152 , error , V_339 , V_154 ) ;
F_197 ( L_79 , error -> V_154 ) ;
if ( ! error -> V_303 ) {
F_198 ( & V_152 -> V_179 . V_350 , V_348 ) ;
if ( ! V_152 -> V_179 . V_349 ) {
V_152 -> V_179 . V_349 = error ;
error = NULL ;
}
F_199 ( & V_152 -> V_179 . V_350 , V_348 ) ;
}
if ( error ) {
F_72 ( & error -> V_214 ) ;
return;
}
if ( ! V_347 &&
F_200 () - V_351 < F_201 ( 180 ) ) {
F_197 ( L_132 ) ;
F_197 ( L_133 ) ;
F_197 ( L_134 ) ;
F_197 ( L_135 ) ;
F_197 ( L_136 ,
V_152 -> V_146 . V_352 -> V_353 ) ;
V_347 = true ;
}
}
struct V_151 *
F_202 ( struct V_143 * V_70 )
{
struct V_151 * error ;
F_203 ( & V_70 -> V_179 . V_350 ) ;
error = V_70 -> V_179 . V_349 ;
if ( error )
F_204 ( error ) ;
F_110 ( & V_70 -> V_179 . V_350 ) ;
return error ;
}
void F_205 ( struct V_143 * V_70 )
{
struct V_151 * error ;
F_203 ( & V_70 -> V_179 . V_350 ) ;
error = V_70 -> V_179 . V_349 ;
V_70 -> V_179 . V_349 = NULL ;
F_110 ( & V_70 -> V_179 . V_350 ) ;
F_206 ( error ) ;
}
