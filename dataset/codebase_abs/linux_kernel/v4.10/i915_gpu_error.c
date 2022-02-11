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
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_30 =
F_13 ( F_14 ( V_31 , V_32 ) ,
V_33 | V_34 ) ;
if ( ! V_29 -> V_30 )
return false ;
if ( F_15 ( V_29 , V_35 ) != V_36 ) {
F_16 ( V_29 -> V_30 ) ;
return false ;
}
return true ;
}
static int F_17 ( struct V_28 * V_29 ,
void * V_37 ,
struct V_38 * V_39 )
{
V_29 -> V_40 = V_37 ;
V_29 -> V_41 = V_42 ;
do {
if ( V_29 -> V_43 == 0 ) {
unsigned long V_44 ;
V_44 = F_18 ( V_33 | V_34 ) ;
if ( ! V_44 )
return - V_45 ;
V_39 -> V_46 [ V_39 -> V_47 ++ ] = ( void * ) V_44 ;
V_29 -> V_48 = ( void * ) V_44 ;
V_29 -> V_43 = V_42 ;
}
if ( F_19 ( V_29 , V_49 ) != V_36 )
return - V_22 ;
} while ( V_29 -> V_41 );
if ( 0 && V_29 -> V_50 > V_29 -> V_51 )
return - V_52 ;
return 0 ;
}
static void F_20 ( struct V_28 * V_29 ,
struct V_38 * V_39 )
{
if ( V_39 ) {
F_19 ( V_29 , V_53 ) ;
V_39 -> V_54 = V_29 -> V_43 ;
}
F_21 ( V_29 ) ;
F_16 ( V_29 -> V_30 ) ;
}
static void F_22 ( struct V_13 * V_55 )
{
F_23 ( V_55 , L_12 ) ;
}
static bool F_12 ( struct V_28 * V_29 )
{
return true ;
}
static int F_17 ( struct V_28 * V_29 ,
void * V_37 ,
struct V_38 * V_39 )
{
unsigned long V_44 ;
V_44 = F_18 ( V_33 | V_34 ) ;
if ( ! V_44 )
return - V_45 ;
V_39 -> V_46 [ V_39 -> V_47 ++ ] =
memcpy ( ( void * ) V_44 , V_37 , V_42 ) ;
return 0 ;
}
static void F_20 ( struct V_28 * V_29 ,
struct V_38 * V_39 )
{
}
static void F_22 ( struct V_13 * V_55 )
{
F_23 ( V_55 , L_13 ) ;
}
static void F_24 ( struct V_13 * V_55 ,
const char * V_56 ,
struct V_57 * V_15 ,
int V_58 )
{
int V_59 ;
F_25 ( V_55 , L_14 , V_56 , V_58 ) ;
while ( V_58 -- ) {
F_25 ( V_55 , L_15 ,
F_26 ( V_15 -> V_60 ) ,
F_27 ( V_15 -> V_60 ) ,
V_15 -> V_17 ,
V_15 -> V_61 ,
V_15 -> V_62 ) ;
for ( V_59 = 0 ; V_59 < V_63 ; V_59 ++ )
F_25 ( V_55 , L_16 , V_15 -> V_64 [ V_59 ] ) ;
F_25 ( V_55 , L_17 , V_15 -> V_65 ) ;
F_23 ( V_55 , F_2 ( V_15 -> V_7 ) ) ;
F_23 ( V_55 , F_3 ( V_15 -> V_11 ) ) ;
F_23 ( V_55 , F_4 ( V_15 -> V_12 ) ) ;
F_23 ( V_55 , V_15 -> V_66 ? L_18 : L_6 ) ;
F_23 ( V_55 , V_15 -> V_1 != - 1 ? L_19 : L_6 ) ;
F_23 ( V_55 , F_1 ( V_15 -> V_1 ) ) ;
F_23 ( V_55 , F_28 ( V_55 -> V_67 , V_15 -> V_68 ) ) ;
if ( V_15 -> V_56 )
F_25 ( V_55 , L_20 , V_15 -> V_56 ) ;
if ( V_15 -> V_69 != V_70 )
F_25 ( V_55 , L_21 , V_15 -> V_69 ) ;
F_23 ( V_55 , L_22 ) ;
V_15 ++ ;
}
}
static const char * F_29 ( enum V_71 V_72 )
{
switch ( V_72 ) {
case V_73 :
return L_23 ;
case V_74 :
return L_24 ;
case V_75 :
return L_25 ;
case V_76 :
return L_26 ;
case V_77 :
return L_27 ;
}
return L_28 ;
}
static void F_30 ( struct V_13 * V_55 ,
struct V_78 * V_79 )
{
int V_80 ;
int V_81 ;
F_25 ( V_55 , L_29 ,
V_79 -> V_82 . V_82 ) ;
if ( V_79 -> V_83 != V_2 || F_31 ( V_55 -> V_67 ) <= 3 )
return;
F_25 ( V_55 , L_30 ,
V_79 -> V_82 . V_84 ) ;
if ( F_31 ( V_55 -> V_67 ) <= 6 )
return;
F_32 (m->i915, slice, subslice)
F_25 ( V_55 , L_31 ,
V_80 , V_81 ,
V_79 -> V_82 . V_85 [ V_80 ] [ V_81 ] ) ;
F_32 (m->i915, slice, subslice)
F_25 ( V_55 , L_32 ,
V_80 , V_81 ,
V_79 -> V_82 . V_86 [ V_80 ] [ V_81 ] ) ;
}
static void F_33 ( struct V_13 * V_55 ,
const char * V_87 ,
struct V_88 * V_89 )
{
if ( ! V_89 -> V_90 )
return;
F_25 ( V_55 , L_33 ,
V_87 , V_89 -> V_91 ,
V_89 -> V_92 , V_89 -> V_90 ,
F_34 ( V_93 - V_89 -> V_93 ) ,
V_89 -> V_94 , V_89 -> V_95 ) ;
}
static void F_35 ( struct V_13 * V_55 ,
struct V_78 * V_79 )
{
F_25 ( V_55 , L_34 , F_1 ( V_79 -> V_83 ) ) ;
F_25 ( V_55 , L_35 , V_79 -> V_21 ) ;
F_25 ( V_55 , L_36 , V_79 -> V_94 , V_79 -> V_96 ) ;
F_25 ( V_55 , L_37 ,
V_79 -> V_95 , V_79 -> V_97 , V_79 -> V_98 ) ;
F_25 ( V_55 , L_38 , V_79 -> V_99 ) ;
F_25 ( V_55 , L_39 , V_79 -> V_100 ) ;
F_25 ( V_55 , L_40 , V_79 -> V_101 ) ;
F_25 ( V_55 , L_41 ,
( V_102 ) ( V_79 -> V_103 >> 32 ) , ( V_102 ) V_79 -> V_103 ) ;
F_25 ( V_55 , L_42 , V_79 -> V_104 ) ;
F_25 ( V_55 , L_43 , V_79 -> V_105 ) ;
F_30 ( V_55 , V_79 ) ;
if ( V_79 -> V_106 ) {
T_3 V_21 = V_79 -> V_106 -> V_60 ;
T_3 V_107 = V_21 + V_79 -> V_106 -> V_108 ;
F_25 ( V_55 , L_44 ,
F_26 ( V_21 ) , F_27 ( V_21 ) ,
F_26 ( V_107 ) , F_27 ( V_107 ) ) ;
}
if ( F_31 ( V_55 -> V_67 ) >= 4 ) {
F_25 ( V_55 , L_45 ,
( V_102 ) ( V_79 -> V_109 >> 32 ) , ( V_102 ) V_79 -> V_109 ) ;
F_25 ( V_55 , L_46 , V_79 -> V_110 ) ;
F_25 ( V_55 , L_47 , V_79 -> V_111 ) ;
}
F_25 ( V_55 , L_48 , V_79 -> V_112 ) ;
F_25 ( V_55 , L_49 , F_26 ( V_79 -> V_113 ) ,
F_27 ( V_79 -> V_113 ) ) ;
if ( F_31 ( V_55 -> V_67 ) >= 6 ) {
F_25 ( V_55 , L_50 , V_79 -> V_114 ) ;
F_25 ( V_55 , L_51 , V_79 -> V_115 ) ;
F_25 ( V_55 , L_52 ,
V_79 -> V_116 [ 0 ] ) ;
F_25 ( V_55 , L_53 ,
V_79 -> V_116 [ 1 ] ) ;
if ( F_36 ( V_55 -> V_67 ) )
F_25 ( V_55 , L_54 ,
V_79 -> V_116 [ 2 ] ) ;
}
if ( F_37 ( V_55 -> V_67 ) ) {
F_25 ( V_55 , L_55 , V_79 -> V_117 . V_118 ) ;
if ( F_31 ( V_55 -> V_67 ) >= 8 ) {
int V_59 ;
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ )
F_25 ( V_55 , L_56 ,
V_59 , V_79 -> V_117 . V_119 [ V_59 ] ) ;
} else {
F_25 ( V_55 , L_57 ,
V_79 -> V_117 . V_120 ) ;
}
}
F_25 ( V_55 , L_58 , V_79 -> V_90 ) ;
F_25 ( V_55 , L_59 , V_79 -> V_121 ) ;
F_25 ( V_55 , L_60 , F_38 ( V_79 -> V_122 ) ) ;
F_25 ( V_55 , L_61 , V_79 -> V_123 ) ;
F_25 ( V_55 , L_62 , V_79 -> V_124 ) ;
F_25 ( V_55 , L_63 ,
F_29 ( V_79 -> V_125 ) ,
V_79 -> V_126 ) ;
F_33 ( V_55 , L_64 , & V_79 -> V_127 [ 0 ] ) ;
F_33 ( V_55 , L_65 , & V_79 -> V_127 [ 1 ] ) ;
}
void F_39 ( struct V_13 * V_14 , const char * V_25 , ... )
{
T_2 args ;
va_start ( args , V_25 ) ;
F_9 ( V_14 , V_25 , args ) ;
va_end ( args ) ;
}
static int
F_40 ( int V_19 )
{
return F_41 ( V_19 , 4 ) ;
}
static bool
F_42 ( V_102 V_128 , char * V_129 )
{
int V_59 ;
if ( V_128 == 0 )
return false ;
V_129 [ 5 ] = '\0' ;
for ( V_59 = 5 ; V_59 -- ; ) {
V_129 [ V_59 ] = '!' + V_128 % 85 ;
V_128 /= 85 ;
}
return true ;
}
static void F_43 ( struct V_13 * V_55 ,
struct V_130 * V_1 ,
const char * V_56 ,
struct V_38 * V_131 )
{
char V_129 [ 6 ] ;
int V_44 ;
if ( ! V_131 )
return;
if ( V_56 ) {
F_25 ( V_55 , L_66 ,
V_1 ? V_1 -> V_56 : L_67 , V_56 ,
F_26 ( V_131 -> V_60 ) ,
F_27 ( V_131 -> V_60 ) ) ;
}
F_22 ( V_55 ) ;
for ( V_44 = 0 ; V_44 < V_131 -> V_47 ; V_44 ++ ) {
int V_59 , V_19 ;
V_19 = V_42 ;
if ( V_44 == V_131 -> V_47 - 1 )
V_19 -= V_131 -> V_54 ;
V_19 = F_40 ( V_19 ) ;
for ( V_59 = 0 ; V_59 < V_19 ; V_59 ++ ) {
if ( F_42 ( V_131 -> V_46 [ V_44 ] [ V_59 ] , V_129 ) )
F_23 ( V_55 , V_129 ) ;
else
F_23 ( V_55 , L_68 ) ;
}
}
F_23 ( V_55 , L_22 ) ;
}
static void F_44 ( struct V_13 * V_55 ,
const struct V_132 * V_133 )
{
#define F_45 ( T_4 ) err_printf(m, #x ": %s\n", yesno(info->x))
F_46 ( F_45 ) ;
#undef F_45
}
int F_47 ( struct V_13 * V_55 ,
const struct V_134 * V_135 )
{
struct V_136 * V_137 = F_48 ( V_135 -> V_138 ) ;
struct V_139 * V_140 = V_137 -> V_141 . V_140 ;
struct V_142 * error = V_135 -> error ;
struct V_38 * V_131 ;
int V_143 ;
int V_59 , V_144 ;
if ( ! error ) {
F_25 ( V_55 , L_69 ) ;
goto V_129;
}
F_25 ( V_55 , L_70 , error -> V_145 ) ;
F_25 ( V_55 , L_71 V_146 L_22 ) ;
F_25 ( V_55 , L_72 ,
error -> time . V_147 , error -> time . V_148 ) ;
F_25 ( V_55 , L_73 ,
error -> V_149 . V_147 , error -> V_149 . V_148 ) ;
F_25 ( V_55 , L_74 ,
error -> V_150 . V_147 , error -> V_150 . V_148 ) ;
F_44 ( V_55 , & error -> V_151 ) ;
V_143 = 0 ;
for ( V_59 = 0 ; V_59 < F_49 ( error -> V_1 ) ; V_59 ++ ) {
if ( error -> V_1 [ V_59 ] . V_126 > V_143 )
V_143 = error -> V_1 [ V_59 ] . V_126 ;
}
for ( V_59 = 0 ; V_59 < F_49 ( error -> V_1 ) ; V_59 ++ ) {
if ( error -> V_1 [ V_59 ] . V_126 == V_143 &&
error -> V_1 [ V_59 ] . V_91 != - 1 ) {
F_25 ( V_55 , L_75 ,
F_1 ( V_59 ) ,
error -> V_1 [ V_59 ] . V_152 ,
error -> V_1 [ V_59 ] . V_91 ) ;
}
}
F_25 ( V_55 , L_76 , error -> V_153 ) ;
F_25 ( V_55 , L_77 , error -> V_154 ) ;
F_25 ( V_55 , L_78 , V_140 -> V_155 ) ;
F_25 ( V_55 , L_79 , V_140 -> V_156 ) ;
F_25 ( V_55 , L_80 ,
V_140 -> V_157 ,
V_140 -> V_158 ) ;
F_25 ( V_55 , L_81 , error -> V_159 ) ;
if ( F_50 ( V_137 ) ) {
struct V_160 * V_161 = & V_137 -> V_161 ;
F_25 ( V_55 , L_82 ,
F_38 ( V_161 -> V_162 != NULL ) ) ;
F_25 ( V_55 , L_83 ,
F_51 ( V_161 -> V_163 ) ,
F_52 ( V_161 -> V_163 ) ) ;
}
F_25 ( V_55 , L_84 , error -> V_164 ) ;
F_25 ( V_55 , L_85 , error -> V_165 ) ;
if ( F_31 ( V_137 ) >= 8 ) {
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ )
F_25 ( V_55 , L_86 , V_59 ,
error -> V_166 [ V_59 ] ) ;
} else if ( F_53 ( V_137 ) || F_54 ( V_137 ) )
F_25 ( V_55 , L_87 , error -> V_166 [ 0 ] ) ;
F_25 ( V_55 , L_88 , error -> V_167 ) ;
F_25 ( V_55 , L_89 , error -> V_168 ) ;
F_25 ( V_55 , L_90 , error -> V_169 ) ;
F_25 ( V_55 , L_91 , error -> V_170 ) ;
F_25 ( V_55 , L_92 , V_137 -> V_171 . V_172 ) ;
for ( V_59 = 0 ; V_59 < V_137 -> V_173 ; V_59 ++ )
F_25 ( V_55 , L_93 , V_59 , error -> V_174 [ V_59 ] ) ;
if ( F_31 ( V_137 ) >= 6 ) {
F_25 ( V_55 , L_94 , error -> error ) ;
if ( F_31 ( V_137 ) >= 8 )
F_25 ( V_55 , L_95 ,
error -> V_175 , error -> V_176 ) ;
F_25 ( V_55 , L_96 , error -> V_177 ) ;
}
if ( F_55 ( V_137 ) )
F_25 ( V_55 , L_97 , error -> V_178 ) ;
for ( V_59 = 0 ; V_59 < F_49 ( error -> V_1 ) ; V_59 ++ ) {
if ( error -> V_1 [ V_59 ] . V_83 != - 1 )
F_35 ( V_55 , & error -> V_1 [ V_59 ] ) ;
}
for ( V_59 = 0 ; V_59 < F_49 ( error -> V_179 ) ; V_59 ++ ) {
char V_24 [ 128 ] ;
int V_19 , V_180 = 1 ;
if ( ! error -> V_179 [ V_59 ] )
break;
V_19 = F_56 ( V_24 , sizeof( V_24 ) , L_98 ) ;
for ( V_144 = 0 ; V_144 < F_49 ( error -> V_1 ) ; V_144 ++ ) {
if ( error -> V_1 [ V_144 ] . V_181 != error -> V_179 [ V_59 ] )
continue;
V_19 += F_56 ( V_24 + V_19 , sizeof( V_24 ) , L_99 ,
V_180 ? L_6 : L_100 ,
V_137 -> V_1 [ V_144 ] -> V_56 ) ;
V_180 = 0 ;
}
F_56 ( V_24 + V_19 , sizeof( V_24 ) , L_101 ) ;
F_24 ( V_55 , V_24 ,
error -> V_182 [ V_59 ] ,
error -> V_183 [ V_59 ] ) ;
}
F_24 ( V_55 , L_102 ,
error -> V_184 ,
error -> V_185 ) ;
for ( V_59 = 0 ; V_59 < F_49 ( error -> V_1 ) ; V_59 ++ ) {
struct V_78 * V_79 = & error -> V_1 [ V_59 ] ;
V_131 = V_79 -> V_106 ;
if ( V_131 ) {
F_23 ( V_55 , V_137 -> V_1 [ V_59 ] -> V_56 ) ;
if ( V_79 -> V_91 != - 1 )
F_25 ( V_55 , L_103 ,
V_79 -> V_152 ,
V_79 -> V_91 ) ;
F_25 ( V_55 , L_104 ,
F_26 ( V_131 -> V_60 ) ,
F_27 ( V_131 -> V_60 ) ) ;
F_43 ( V_55 , V_137 -> V_1 [ V_59 ] , NULL , V_131 ) ;
}
if ( V_79 -> V_186 ) {
F_25 ( V_55 , L_105 ,
V_137 -> V_1 [ V_59 ] -> V_56 ,
V_79 -> V_186 ) ;
for ( V_144 = 0 ; V_144 < V_79 -> V_186 ; V_144 ++ )
F_33 ( V_55 , L_19 , & V_79 -> V_187 [ V_144 ] ) ;
}
if ( F_57 ( V_79 -> V_188 ) ) {
F_25 ( V_55 , L_106 ,
V_137 -> V_1 [ V_59 ] -> V_56 ) ;
} else if ( V_79 -> V_189 ) {
F_25 ( V_55 , L_107 ,
V_137 -> V_1 [ V_59 ] -> V_56 ,
V_79 -> V_189 ) ;
for ( V_144 = 0 ; V_144 < V_79 -> V_189 ; V_144 ++ ) {
F_25 ( V_55 , L_108 ,
V_79 -> V_188 [ V_144 ] . V_90 ,
V_79 -> V_188 [ V_144 ] . V_152 ,
V_79 -> V_188 [ V_144 ] . V_91 ) ;
}
}
F_43 ( V_55 , V_137 -> V_1 [ V_59 ] ,
L_109 , V_79 -> V_190 ) ;
F_43 ( V_55 , V_137 -> V_1 [ V_59 ] ,
L_110 , V_79 -> V_191 ) ;
F_43 ( V_55 , V_137 -> V_1 [ V_59 ] ,
L_111 , V_79 -> V_192 ) ;
F_43 ( V_55 , V_137 -> V_1 [ V_59 ] ,
L_112 , V_79 -> V_193 ) ;
F_43 ( V_55 , V_137 -> V_1 [ V_59 ] ,
L_113 , V_79 -> V_194 ) ;
}
F_43 ( V_55 , NULL , L_114 , error -> V_195 ) ;
F_43 ( V_55 , NULL , L_115 , error -> V_196 ) ;
if ( error -> V_197 )
F_58 ( V_55 , error -> V_197 ) ;
if ( error -> V_198 )
F_59 ( V_55 , V_137 , error -> V_198 ) ;
V_129:
if ( V_55 -> V_16 == 0 && V_55 -> V_15 )
return V_55 -> V_15 ;
return 0 ;
}
int F_60 ( struct V_13 * V_199 ,
struct V_136 * V_67 ,
T_1 V_58 , T_5 V_20 )
{
memset ( V_199 , 0 , sizeof( * V_199 ) ) ;
V_199 -> V_67 = V_67 ;
V_199 -> V_17 = V_58 + 1 > V_42 ? V_58 + 1 : V_42 ;
V_199 -> V_24 = F_13 ( V_199 -> V_17 ,
V_200 | V_201 | V_34 ) ;
if ( V_199 -> V_24 == NULL ) {
V_199 -> V_17 = V_42 ;
V_199 -> V_24 = F_13 ( V_199 -> V_17 , V_200 ) ;
}
if ( V_199 -> V_24 == NULL ) {
V_199 -> V_17 = 128 ;
V_199 -> V_24 = F_13 ( V_199 -> V_17 , V_200 ) ;
}
if ( V_199 -> V_24 == NULL )
return - V_45 ;
V_199 -> V_21 = V_20 ;
return 0 ;
}
static void F_61 ( struct V_38 * V_131 )
{
int V_44 ;
if ( V_131 == NULL )
return;
for ( V_44 = 0 ; V_44 < V_131 -> V_47 ; V_44 ++ )
F_62 ( ( unsigned long ) V_131 -> V_46 [ V_44 ] ) ;
F_16 ( V_131 ) ;
}
static void F_63 ( struct V_202 * V_203 )
{
struct V_142 * error = F_64 ( V_203 ,
F_65 ( * error ) , V_204 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < F_49 ( error -> V_1 ) ; V_59 ++ ) {
struct V_78 * V_79 = & error -> V_1 [ V_59 ] ;
F_61 ( V_79 -> V_106 ) ;
F_61 ( V_79 -> V_194 ) ;
F_61 ( V_79 -> V_190 ) ;
F_61 ( V_79 -> V_191 ) ;
F_61 ( V_79 -> V_192 ) ;
F_61 ( V_79 -> V_193 ) ;
F_16 ( V_79 -> V_187 ) ;
if ( ! F_66 ( V_79 -> V_188 ) )
F_16 ( V_79 -> V_188 ) ;
}
F_61 ( error -> V_195 ) ;
F_61 ( error -> V_196 ) ;
for ( V_59 = 0 ; V_59 < F_49 ( error -> V_182 ) ; V_59 ++ )
F_16 ( error -> V_182 [ V_59 ] ) ;
F_16 ( error -> V_184 ) ;
F_16 ( error -> V_197 ) ;
F_16 ( error -> V_198 ) ;
F_16 ( error ) ;
}
static struct V_38 *
F_67 ( struct V_136 * V_67 ,
struct V_205 * V_206 )
{
struct V_207 * V_208 = & V_67 -> V_208 ;
const T_3 V_209 = V_208 -> V_210 . V_21 ;
struct V_38 * V_39 ;
struct V_28 V_29 ;
unsigned long V_211 ;
struct V_212 V_213 ;
T_6 V_214 ;
if ( ! V_206 )
return NULL ;
V_211 = F_68 ( T_3 , V_206 -> V_17 , V_206 -> V_131 -> V_215 . V_17 ) >> V_216 ;
V_211 = F_41 ( 10 * V_211 , 8 ) ;
V_39 = F_13 ( sizeof( * V_39 ) + V_211 * sizeof( V_102 * ) ,
V_33 | V_34 ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_60 = V_206 -> V_217 . V_21 ;
V_39 -> V_108 = V_206 -> V_217 . V_17 ;
V_39 -> V_47 = 0 ;
V_39 -> V_54 = 0 ;
if ( ! F_12 ( & V_29 ) ) {
F_16 ( V_39 ) ;
return NULL ;
}
F_69 (dma, iter, vma->pages) {
void T_7 * V_218 ;
int V_219 ;
V_208 -> V_215 . V_220 ( & V_208 -> V_215 , V_214 , V_209 ,
V_221 , 0 ) ;
V_218 = F_70 ( & V_208 -> V_222 , V_209 ) ;
V_219 = F_17 ( & V_29 , ( void V_223 * ) V_218 , V_39 ) ;
F_71 ( V_218 ) ;
if ( V_219 )
goto V_224;
}
goto V_129;
V_224:
while ( V_39 -> V_47 -- )
F_62 ( ( unsigned long ) V_39 -> V_46 [ V_39 -> V_47 ] ) ;
F_16 ( V_39 ) ;
V_39 = NULL ;
V_129:
F_20 ( & V_29 , V_39 ) ;
V_208 -> V_215 . V_225 ( & V_208 -> V_215 , V_209 , V_42 ) ;
return V_39 ;
}
static inline T_8
F_72 ( struct V_226 * V_227 )
{
struct V_228 * V_229 ;
V_229 = F_73 ( V_227 ) ;
return V_229 ? V_229 -> V_230 : 0 ;
}
static inline int
F_74 ( struct V_226 * V_227 )
{
struct V_228 * V_229 ;
V_229 = F_73 ( V_227 ) ;
return V_229 ? V_229 -> V_1 -> V_231 : - 1 ;
}
static void F_75 ( struct V_57 * V_15 ,
struct V_205 * V_206 )
{
struct V_232 * V_131 = V_206 -> V_131 ;
int V_59 ;
V_15 -> V_17 = V_131 -> V_215 . V_17 ;
V_15 -> V_56 = V_131 -> V_215 . V_56 ;
for ( V_59 = 0 ; V_59 < V_63 ; V_59 ++ )
V_15 -> V_64 [ V_59 ] = F_72 ( & V_206 -> V_233 [ V_59 ] ) ;
V_15 -> V_65 = F_72 ( & V_131 -> V_234 ) ;
V_15 -> V_1 = F_74 ( & V_131 -> V_234 ) ;
V_15 -> V_60 = V_206 -> V_217 . V_21 ;
V_15 -> V_61 = V_131 -> V_215 . V_61 ;
V_15 -> V_62 = V_131 -> V_215 . V_62 ;
V_15 -> V_69 = V_206 -> V_174 ? V_206 -> V_174 -> V_231 : - 1 ;
V_15 -> V_7 = F_76 ( V_131 ) ;
V_15 -> V_11 = V_131 -> V_235 . V_11 ;
V_15 -> V_12 = V_131 -> V_235 . V_236 != V_237 ;
V_15 -> V_66 = V_131 -> V_66 . V_235 != NULL ;
V_15 -> V_68 = V_131 -> V_68 ;
}
static V_102 F_77 ( struct V_57 * V_15 ,
int V_58 , struct V_238 * V_94 ,
bool V_239 )
{
struct V_205 * V_206 ;
int V_59 = 0 ;
F_78 (vma, head, vm_link) {
if ( V_239 && ! F_79 ( V_206 ) )
continue;
F_75 ( V_15 ++ , V_206 ) ;
if ( ++ V_59 == V_58 )
break;
}
return V_59 ;
}
static T_8 F_80 ( struct V_136 * V_137 ,
struct V_142 * error ,
int * V_83 )
{
T_8 V_240 = 0 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_63 ; V_59 ++ ) {
if ( error -> V_1 [ V_59 ] . V_125 == V_77 ) {
if ( V_83 )
* V_83 = V_59 ;
return error -> V_1 [ V_59 ] . V_105 ^
error -> V_1 [ V_59 ] . V_82 . V_82 ;
}
}
return V_240 ;
}
static void F_81 ( struct V_136 * V_137 ,
struct V_142 * error )
{
int V_59 ;
if ( F_82 ( V_137 ) || F_83 ( V_137 ) ) {
for ( V_59 = 0 ; V_59 < V_137 -> V_173 ; V_59 ++ )
error -> V_174 [ V_59 ] = F_84 ( F_85 ( V_59 ) ) ;
} else if ( F_86 ( V_137 ) || F_87 ( V_137 ) ) {
for ( V_59 = 0 ; V_59 < V_137 -> V_173 ; V_59 ++ )
error -> V_174 [ V_59 ] = F_88 ( F_89 ( V_59 ) ) ;
} else if ( F_31 ( V_137 ) >= 6 ) {
for ( V_59 = 0 ; V_59 < V_137 -> V_173 ; V_59 ++ )
error -> V_174 [ V_59 ] = F_88 ( F_90 ( V_59 ) ) ;
}
}
static inline V_102
F_91 ( struct V_130 * V_1 ,
struct V_130 * V_241 )
{
int V_242 ;
V_242 = ( V_241 - V_1 ) - 1 ;
if ( V_242 < 0 )
V_242 += V_63 ;
return V_242 ;
}
static void F_92 ( struct V_142 * error ,
struct V_130 * V_1 ,
struct V_78 * V_79 )
{
struct V_136 * V_137 = V_1 -> V_67 ;
struct V_130 * V_243 ;
enum V_244 V_231 ;
if ( ! error -> V_195 )
return;
F_93 (to, dev_priv, id) {
int V_242 ;
T_9 V_245 ;
V_102 * V_26 ;
if ( V_1 == V_243 )
continue;
V_245 =
( F_94 ( V_1 , V_231 ) & ( V_42 - 1 ) ) / 4 ;
V_26 = error -> V_195 -> V_46 [ 0 ] ;
V_242 = F_91 ( V_1 , V_243 ) ;
V_79 -> V_116 [ V_242 ] = V_26 [ V_245 ] ;
}
}
static void F_95 ( struct V_130 * V_1 ,
struct V_78 * V_79 )
{
struct V_136 * V_137 = V_1 -> V_67 ;
V_79 -> V_116 [ 0 ] = F_84 ( F_96 ( V_1 -> V_246 ) ) ;
V_79 -> V_116 [ 1 ] = F_84 ( F_97 ( V_1 -> V_246 ) ) ;
if ( F_36 ( V_137 ) )
V_79 -> V_116 [ 2 ] =
F_84 ( F_98 ( V_1 -> V_246 ) ) ;
}
static void F_99 ( struct V_130 * V_1 ,
struct V_78 * V_79 )
{
struct V_247 * V_248 = & V_1 -> V_249 ;
struct V_250 * V_251 ;
struct V_252 * V_253 ;
int V_58 ;
V_79 -> V_189 = 0 ;
V_79 -> V_188 = NULL ;
if ( F_100 ( & V_248 -> V_188 ) )
return;
if ( ! F_101 ( & V_248 -> V_254 ) ) {
V_79 -> V_188 = F_102 ( - V_255 ) ;
return;
}
V_58 = 0 ;
for ( V_253 = F_103 ( & V_248 -> V_188 ) ; V_253 != NULL ; V_253 = F_104 ( V_253 ) )
V_58 ++ ;
F_105 ( & V_248 -> V_254 ) ;
V_251 = NULL ;
if ( V_58 )
V_251 = F_106 ( V_58 ,
sizeof( struct V_250 ) ,
V_33 ) ;
if ( ! V_251 )
return;
if ( ! F_101 ( & V_248 -> V_254 ) ) {
F_16 ( V_251 ) ;
V_79 -> V_188 = F_102 ( - V_255 ) ;
return;
}
V_79 -> V_188 = V_251 ;
for ( V_253 = F_103 ( & V_248 -> V_188 ) ; V_253 ; V_253 = F_104 ( V_253 ) ) {
struct V_256 * V_257 = F_64 ( V_253 , F_65 ( * V_257 ) , V_217 ) ;
strcpy ( V_251 -> V_152 , V_257 -> V_258 -> V_152 ) ;
V_251 -> V_91 = V_257 -> V_258 -> V_91 ;
V_251 -> V_90 = V_257 -> V_90 ;
V_251 ++ ;
if ( ++ V_79 -> V_189 == V_58 )
break;
}
F_105 ( & V_248 -> V_254 ) ;
}
static void F_107 ( struct V_142 * error ,
struct V_130 * V_1 ,
struct V_78 * V_79 )
{
struct V_136 * V_137 = V_1 -> V_67 ;
if ( F_31 ( V_137 ) >= 6 ) {
V_79 -> V_114 = F_84 ( F_108 ( V_1 -> V_246 ) ) ;
V_79 -> V_115 = F_84 ( F_109 ( V_1 ) ) ;
if ( F_31 ( V_137 ) >= 8 )
F_92 ( error , V_1 , V_79 ) ;
else
F_95 ( V_1 , V_79 ) ;
}
if ( F_31 ( V_137 ) >= 4 ) {
V_79 -> V_113 = F_84 ( F_110 ( V_1 -> V_246 ) ) ;
V_79 -> V_104 = F_84 ( F_111 ( V_1 -> V_246 ) ) ;
V_79 -> V_105 = F_84 ( F_112 ( V_1 -> V_246 ) ) ;
V_79 -> V_111 = F_84 ( F_113 ( V_1 -> V_246 ) ) ;
V_79 -> V_109 = F_84 ( F_114 ( V_1 -> V_246 ) ) ;
if ( F_31 ( V_137 ) >= 8 ) {
V_79 -> V_113 |= ( T_3 ) F_84 ( F_115 ( V_1 -> V_246 ) ) << 32 ;
V_79 -> V_109 |= ( T_3 ) F_84 ( F_116 ( V_1 -> V_246 ) ) << 32 ;
}
V_79 -> V_110 = F_84 ( F_117 ( V_1 -> V_246 ) ) ;
} else {
V_79 -> V_113 = F_84 ( V_259 ) ;
V_79 -> V_104 = F_84 ( V_260 ) ;
V_79 -> V_105 = F_84 ( V_261 ) ;
}
F_118 ( V_1 , & V_79 -> V_82 ) ;
V_79 -> V_122 = F_119 ( V_1 ) ;
V_79 -> V_112 = F_84 ( F_120 ( V_1 -> V_246 ) ) ;
V_79 -> V_103 = F_121 ( V_1 ) ;
V_79 -> V_90 = F_122 ( V_1 ) ;
V_79 -> V_121 = F_123 ( V_1 ) ;
V_79 -> V_21 = F_124 ( V_1 ) ;
V_79 -> V_94 = F_125 ( V_1 ) ;
V_79 -> V_95 = F_126 ( V_1 ) ;
V_79 -> V_99 = F_127 ( V_1 ) ;
if ( F_31 ( V_137 ) > 2 )
V_79 -> V_100 = F_128 ( V_1 ) ;
if ( ! F_129 ( V_137 ) ) {
T_10 V_262 ;
if ( F_55 ( V_137 ) ) {
switch ( V_1 -> V_231 ) {
default:
case V_2 :
V_262 = V_263 ;
break;
case V_4 :
V_262 = V_264 ;
break;
case V_3 :
V_262 = V_265 ;
break;
case V_5 :
V_262 = V_266 ;
break;
}
} else if ( F_130 ( V_1 -> V_67 ) ) {
V_262 = F_131 ( V_1 -> V_246 ) ;
} else {
V_262 = F_132 ( V_1 -> V_246 ) ;
}
V_79 -> V_101 = F_84 ( V_262 ) ;
}
V_79 -> V_126 = V_1 -> V_267 . V_268 ;
V_79 -> V_125 = V_1 -> V_267 . V_269 ;
if ( F_37 ( V_137 ) ) {
int V_59 ;
V_79 -> V_117 . V_118 = F_84 ( F_133 ( V_1 ) ) ;
if ( F_130 ( V_137 ) )
V_79 -> V_117 . V_120 =
F_84 ( F_134 ( V_1 ) ) ;
else if ( F_55 ( V_137 ) )
V_79 -> V_117 . V_120 =
F_84 ( F_135 ( V_1 ) ) ;
else if ( F_31 ( V_137 ) >= 8 )
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ ) {
V_79 -> V_117 . V_119 [ V_59 ] =
F_84 ( F_136 ( V_1 , V_59 ) ) ;
V_79 -> V_117 . V_119 [ V_59 ] <<= 32 ;
V_79 -> V_117 . V_119 [ V_59 ] |=
F_84 ( F_137 ( V_1 , V_59 ) ) ;
}
}
}
static void F_138 ( struct V_228 * V_229 ,
struct V_88 * V_89 )
{
V_89 -> V_92 = V_229 -> V_192 -> V_270 ;
V_89 -> V_90 = V_229 -> V_230 ;
V_89 -> V_93 = V_229 -> V_271 ;
V_89 -> V_94 = V_229 -> V_94 ;
V_89 -> V_95 = V_229 -> V_95 ;
F_139 () ;
V_89 -> V_91 = V_229 -> V_192 -> V_91 ? F_140 ( V_229 -> V_192 -> V_91 ) : 0 ;
F_141 () ;
}
static void F_142 ( struct V_130 * V_1 ,
struct V_228 * V_180 ,
struct V_78 * V_79 )
{
struct V_228 * V_229 ;
int V_58 ;
V_58 = 0 ;
V_229 = V_180 ;
F_143 (request, &engine->timeline->requests, link)
V_58 ++ ;
if ( ! V_58 )
return;
V_79 -> V_187 = F_144 ( V_58 , sizeof( * V_79 -> V_187 ) , V_33 ) ;
if ( ! V_79 -> V_187 )
return;
V_79 -> V_186 = V_58 ;
V_58 = 0 ;
V_229 = V_180 ;
F_143 (request, &engine->timeline->requests, link) {
if ( V_58 >= V_79 -> V_186 ) {
break;
}
F_138 ( V_229 , & V_79 -> V_187 [ V_58 ++ ] ) ;
}
V_79 -> V_186 = V_58 ;
}
static void F_145 ( struct V_130 * V_1 ,
struct V_78 * V_79 )
{
unsigned int V_272 ;
for ( V_272 = 0 ; V_272 < F_49 ( V_1 -> V_273 ) ; V_272 ++ )
if ( V_1 -> V_273 [ V_272 ] . V_229 )
F_138 ( V_1 -> V_273 [ V_272 ] . V_229 ,
& V_79 -> V_127 [ V_272 ] ) ;
}
static void F_146 ( struct V_136 * V_137 ,
struct V_142 * error )
{
struct V_207 * V_208 = & V_137 -> V_208 ;
int V_59 ;
error -> V_195 =
F_67 ( V_137 , V_137 -> V_195 ) ;
for ( V_59 = 0 ; V_59 < V_63 ; V_59 ++ ) {
struct V_130 * V_1 = V_137 -> V_1 [ V_59 ] ;
struct V_78 * V_79 = & error -> V_1 [ V_59 ] ;
struct V_228 * V_229 ;
V_79 -> V_91 = - 1 ;
V_79 -> V_83 = - 1 ;
if ( ! V_1 )
continue;
V_79 -> V_83 = V_59 ;
F_107 ( error , V_1 , V_79 ) ;
F_99 ( V_1 , V_79 ) ;
F_145 ( V_1 , V_79 ) ;
V_229 = F_147 ( V_1 ) ;
if ( V_229 ) {
struct V_274 * V_275 ;
struct V_91 * V_91 ;
V_79 -> V_181 = V_229 -> V_192 -> V_276 ?
& V_229 -> V_192 -> V_276 -> V_215 : & V_208 -> V_215 ;
V_79 -> V_106 =
F_67 ( V_137 ,
V_229 -> V_277 ) ;
if ( F_148 ( V_137 ) )
V_79 -> V_194 =
F_67 ( V_137 ,
V_1 -> V_278 ) ;
V_79 -> V_192 =
F_67 ( V_137 ,
V_229 -> V_192 -> V_1 [ V_59 ] . V_279 ) ;
V_91 = V_229 -> V_192 -> V_91 ;
if ( V_91 ) {
struct V_280 * V_281 ;
F_139 () ;
V_281 = F_149 ( V_91 , V_282 ) ;
if ( V_281 ) {
strcpy ( V_79 -> V_152 , V_281 -> V_152 ) ;
V_79 -> V_91 = V_281 -> V_91 ;
}
F_141 () ;
}
error -> V_283 |=
V_229 -> V_192 -> V_284 & V_285 ;
V_79 -> V_96 = V_229 -> V_94 ;
V_79 -> V_97 = V_229 -> V_286 ;
V_79 -> V_98 = V_229 -> V_95 ;
V_275 = V_229 -> V_275 ;
V_79 -> V_123 = V_275 -> V_94 ;
V_79 -> V_124 = V_275 -> V_95 ;
V_79 -> V_190 =
F_67 ( V_137 , V_275 -> V_206 ) ;
F_142 ( V_1 , V_229 , V_79 ) ;
}
V_79 -> V_191 =
F_67 ( V_137 ,
V_1 -> V_287 . V_206 ) ;
V_79 -> V_193 =
F_67 ( V_137 , V_1 -> V_193 . V_206 ) ;
}
}
static void F_150 ( struct V_136 * V_137 ,
struct V_142 * error ,
struct V_288 * V_181 ,
int V_242 )
{
struct V_57 * V_182 ;
struct V_205 * V_206 ;
int V_58 ;
V_58 = 0 ;
F_78 (vma, &vm->active_list, vm_link)
V_58 ++ ;
V_182 = NULL ;
if ( V_58 )
V_182 = F_144 ( V_58 , sizeof( * V_182 ) , V_33 ) ;
if ( V_182 )
V_58 = F_77 ( V_182 , V_58 , & V_181 -> V_289 , false ) ;
else
V_58 = 0 ;
error -> V_179 [ V_242 ] = V_181 ;
error -> V_182 [ V_242 ] = V_182 ;
error -> V_183 [ V_242 ] = V_58 ;
}
static void F_151 ( struct V_136 * V_137 ,
struct V_142 * error )
{
int V_290 = 0 , V_59 , V_144 ;
F_152 ( F_49 ( error -> V_1 ) > F_49 ( error -> V_182 ) ) ;
F_152 ( F_49 ( error -> V_182 ) != F_49 ( error -> V_179 ) ) ;
F_152 ( F_49 ( error -> V_182 ) != F_49 ( error -> V_183 ) ) ;
for ( V_59 = 0 ; V_59 < F_49 ( error -> V_1 ) ; V_59 ++ ) {
struct V_78 * V_79 = & error -> V_1 [ V_59 ] ;
bool V_291 ;
if ( ! V_79 -> V_181 )
continue;
V_291 = false ;
for ( V_144 = 0 ; V_144 < V_59 && ! V_291 ; V_144 ++ )
V_291 = error -> V_1 [ V_144 ] . V_181 == V_79 -> V_181 ;
if ( ! V_291 )
F_150 ( V_137 , error , V_79 -> V_181 , V_290 ++ ) ;
}
}
static void F_153 ( struct V_136 * V_137 ,
struct V_142 * error )
{
struct V_288 * V_181 = & V_137 -> V_208 . V_215 ;
struct V_57 * V_292 ;
struct V_205 * V_206 ;
int V_293 , V_294 ;
V_293 = 0 ;
F_78 (vma, &vm->active_list, vm_link)
V_293 ++ ;
V_294 = 0 ;
F_78 (vma, &vm->inactive_list, vm_link)
V_294 ++ ;
V_292 = NULL ;
if ( V_293 + V_294 )
V_292 = F_144 ( V_293 + V_294 ,
sizeof( * V_292 ) , V_33 ) ;
if ( ! V_292 )
return;
V_293 = F_77 ( V_292 , V_293 ,
& V_181 -> V_289 , true ) ;
V_294 = F_77 ( V_292 + V_293 , V_294 ,
& V_181 -> V_295 , true ) ;
error -> V_185 = V_293 + V_294 ;
error -> V_184 = V_292 ;
}
static void F_154 ( struct V_136 * V_137 ,
struct V_142 * error )
{
if ( ! V_137 -> V_296 . log . V_206 || ( V_67 . V_297 < 0 ) )
return;
error -> V_196 = F_67 ( V_137 ,
V_137 -> V_296 . log . V_206 ) ;
}
static void F_155 ( struct V_136 * V_137 ,
struct V_142 * error )
{
int V_59 ;
if ( F_54 ( V_137 ) ) {
error -> V_166 [ 0 ] = F_84 ( V_298 ) ;
error -> V_165 = F_84 ( V_299 ) ;
error -> V_168 = F_156 ( V_300 ) ;
}
if ( F_55 ( V_137 ) )
error -> V_178 = F_84 ( V_301 ) ;
if ( F_31 ( V_137 ) >= 8 ) {
error -> V_176 = F_84 ( V_302 ) ;
error -> V_175 = F_84 ( V_303 ) ;
}
if ( F_130 ( V_137 ) ) {
error -> V_168 = F_156 ( V_304 ) ;
error -> V_305 = F_84 ( V_306 ) ;
error -> V_118 = F_84 ( V_307 ) ;
}
if ( F_31 ( V_137 ) >= 7 )
error -> V_168 = F_156 ( V_308 ) ;
if ( F_31 ( V_137 ) >= 6 ) {
error -> V_169 = F_84 ( V_309 ) ;
error -> error = F_84 ( V_310 ) ;
error -> V_177 = F_84 ( V_311 ) ;
}
if ( F_130 ( V_137 ) || F_55 ( V_137 ) ) {
error -> V_312 = F_84 ( V_313 ) ;
error -> V_314 = F_84 ( V_315 ) ;
}
if ( F_157 ( V_137 ) )
error -> V_170 = F_84 ( V_316 ) ;
if ( F_31 ( V_137 ) >= 8 ) {
error -> V_165 = F_84 ( V_317 ) ;
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ )
error -> V_166 [ V_59 ] = F_84 ( F_158 ( V_59 ) ) ;
} else if ( F_53 ( V_137 ) ) {
error -> V_165 = F_84 ( V_318 ) ;
error -> V_166 [ 0 ] = F_84 ( V_298 ) ;
} else if ( F_83 ( V_137 ) ) {
error -> V_165 = F_159 ( V_319 ) ;
} else if ( ! F_54 ( V_137 ) ) {
error -> V_165 = F_84 ( V_319 ) ;
}
error -> V_164 = F_84 ( V_320 ) ;
error -> V_167 = F_84 ( V_321 ) ;
}
static void F_160 ( struct V_136 * V_137 ,
struct V_142 * error ,
V_102 V_322 ,
const char * V_145 )
{
V_102 V_323 ;
int V_83 = - 1 , V_19 ;
V_323 = F_80 ( V_137 , error , & V_83 ) ;
V_19 = F_56 ( error -> V_145 , sizeof( error -> V_145 ) ,
L_116 ,
F_31 ( V_137 ) , V_83 , V_323 ) ;
if ( V_83 != - 1 && error -> V_1 [ V_83 ] . V_91 != - 1 )
V_19 += F_56 ( error -> V_145 + V_19 ,
sizeof( error -> V_145 ) - V_19 ,
L_117 ,
error -> V_1 [ V_83 ] . V_152 ,
error -> V_1 [ V_83 ] . V_91 ) ;
F_56 ( error -> V_145 + V_19 , sizeof( error -> V_145 ) - V_19 ,
L_118 ,
V_145 ,
V_322 ? L_119 : L_120 ) ;
}
static void F_161 ( struct V_136 * V_137 ,
struct V_142 * error )
{
error -> V_159 = - 1 ;
#ifdef F_162
error -> V_159 = V_324 ;
#endif
error -> V_153 = F_163 ( & V_137 -> V_171 ) ;
error -> V_154 = V_137 -> V_154 ;
memcpy ( & error -> V_151 ,
F_164 ( V_137 ) ,
sizeof( error -> V_151 ) ) ;
}
static int F_165 ( void * V_325 )
{
struct V_142 * error = V_325 ;
F_161 ( error -> V_67 , error ) ;
F_155 ( error -> V_67 , error ) ;
F_81 ( error -> V_67 , error ) ;
F_146 ( error -> V_67 , error ) ;
F_151 ( error -> V_67 , error ) ;
F_153 ( error -> V_67 , error ) ;
F_154 ( error -> V_67 , error ) ;
F_166 ( & error -> time ) ;
error -> V_149 = F_167 ( F_168 () ) ;
error -> V_150 =
F_167 ( F_169 ( F_170 () ,
error -> V_67 -> V_326 . V_327 ) ) ;
error -> V_197 = F_171 ( error -> V_67 ) ;
error -> V_198 = F_172 ( error -> V_67 ) ;
return 0 ;
}
void F_173 ( struct V_136 * V_137 ,
V_102 V_322 ,
const char * V_145 )
{
static bool V_328 ;
struct V_142 * error ;
unsigned long V_284 ;
if ( ! V_67 . V_210 )
return;
if ( F_174 ( V_137 -> V_171 . V_329 ) )
return;
error = F_175 ( sizeof( * error ) , V_33 ) ;
if ( ! error ) {
F_176 ( L_121 ) ;
return;
}
F_177 ( & error -> V_204 ) ;
error -> V_67 = V_137 ;
F_178 ( F_165 , error , NULL ) ;
F_160 ( V_137 , error , V_322 , V_145 ) ;
F_179 ( L_70 , error -> V_145 ) ;
if ( ! error -> V_283 ) {
F_180 ( & V_137 -> V_171 . V_254 , V_284 ) ;
if ( ! V_137 -> V_171 . V_329 ) {
V_137 -> V_171 . V_329 = error ;
error = NULL ;
}
F_181 ( & V_137 -> V_171 . V_254 , V_284 ) ;
}
if ( error ) {
F_63 ( & error -> V_204 ) ;
return;
}
if ( ! V_328 &&
F_182 () - V_330 < F_183 ( 180 ) ) {
F_179 ( L_122 ) ;
F_179 ( L_123 ) ;
F_179 ( L_124 ) ;
F_179 ( L_125 ) ;
F_179 ( L_126 ,
V_137 -> V_141 . V_331 -> V_332 ) ;
V_328 = true ;
}
}
void F_184 ( struct V_333 * V_138 ,
struct V_134 * V_135 )
{
struct V_136 * V_137 = F_48 ( V_138 ) ;
F_185 ( & V_137 -> V_171 . V_254 ) ;
V_135 -> error = V_137 -> V_171 . V_329 ;
if ( V_135 -> error )
F_186 ( & V_135 -> error -> V_204 ) ;
F_105 ( & V_137 -> V_171 . V_254 ) ;
}
void F_187 ( struct V_134 * V_135 )
{
if ( V_135 -> error )
F_188 ( & V_135 -> error -> V_204 , F_63 ) ;
}
void F_189 ( struct V_333 * V_138 )
{
struct V_136 * V_137 = F_48 ( V_138 ) ;
struct V_142 * error ;
F_185 ( & V_137 -> V_171 . V_254 ) ;
error = V_137 -> V_171 . V_329 ;
V_137 -> V_171 . V_329 = NULL ;
F_105 ( & V_137 -> V_171 . V_254 ) ;
if ( error )
F_188 ( & error -> V_204 , F_63 ) ;
}
