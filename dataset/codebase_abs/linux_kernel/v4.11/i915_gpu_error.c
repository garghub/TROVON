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
struct V_74 * V_75 )
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
struct V_84 * V_85 )
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
struct V_74 * V_75 )
{
F_28 ( V_57 , L_28 , F_1 ( V_75 -> V_79 ) ) ;
F_28 ( V_57 , L_29 , V_75 -> V_21 ) ;
F_28 ( V_57 , L_30 , V_75 -> V_91 , V_75 -> V_93 ) ;
F_28 ( V_57 , L_31 ,
V_75 -> V_92 , V_75 -> V_94 , V_75 -> V_95 ) ;
F_28 ( V_57 , L_32 , V_75 -> V_96 ) ;
F_28 ( V_57 , L_33 , V_75 -> V_97 ) ;
F_28 ( V_57 , L_34 , V_75 -> V_98 ) ;
F_28 ( V_57 , L_35 ,
( V_99 ) ( V_75 -> V_100 >> 32 ) , ( V_99 ) V_75 -> V_100 ) ;
F_28 ( V_57 , L_36 , V_75 -> V_101 ) ;
F_28 ( V_57 , L_37 , V_75 -> V_102 ) ;
F_32 ( V_57 , V_75 ) ;
if ( V_75 -> V_103 ) {
T_3 V_21 = V_75 -> V_103 -> V_63 ;
T_3 V_104 = V_21 + V_75 -> V_103 -> V_105 ;
F_28 ( V_57 , L_38 ,
F_29 ( V_21 ) , F_30 ( V_21 ) ,
F_29 ( V_104 ) , F_30 ( V_104 ) ) ;
}
if ( F_33 ( V_57 -> V_70 ) >= 4 ) {
F_28 ( V_57 , L_39 ,
( V_99 ) ( V_75 -> V_106 >> 32 ) , ( V_99 ) V_75 -> V_106 ) ;
F_28 ( V_57 , L_40 , V_75 -> V_107 ) ;
F_28 ( V_57 , L_41 , V_75 -> V_108 ) ;
}
F_28 ( V_57 , L_42 , V_75 -> V_109 ) ;
F_28 ( V_57 , L_43 , F_29 ( V_75 -> V_110 ) ,
F_30 ( V_75 -> V_110 ) ) ;
if ( F_33 ( V_57 -> V_70 ) >= 6 ) {
F_28 ( V_57 , L_44 , V_75 -> V_111 ) ;
F_28 ( V_57 , L_45 , V_75 -> V_112 ) ;
F_28 ( V_57 , L_46 ,
V_75 -> V_113 [ 0 ] ) ;
F_28 ( V_57 , L_47 ,
V_75 -> V_113 [ 1 ] ) ;
if ( F_38 ( V_57 -> V_70 ) )
F_28 ( V_57 , L_48 ,
V_75 -> V_113 [ 2 ] ) ;
}
if ( F_39 ( V_57 -> V_70 ) ) {
F_28 ( V_57 , L_49 , V_75 -> V_114 . V_115 ) ;
if ( F_33 ( V_57 -> V_70 ) >= 8 ) {
int V_62 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ )
F_28 ( V_57 , L_50 ,
V_62 , V_75 -> V_114 . V_116 [ V_62 ] ) ;
} else {
F_28 ( V_57 , L_51 ,
V_75 -> V_114 . V_117 ) ;
}
}
F_28 ( V_57 , L_52 , V_75 -> V_86 ) ;
F_28 ( V_57 , L_53 , V_75 -> V_118 ) ;
F_28 ( V_57 , L_54 , F_40 ( V_75 -> V_119 ) ) ;
F_28 ( V_57 , L_55 , V_75 -> V_120 ) ;
F_28 ( V_57 , L_56 , V_75 -> V_121 ) ;
F_28 ( V_57 , L_57 , F_40 ( V_75 -> V_122 ) ) ;
F_28 ( V_57 , L_58 ,
F_41 ( V_75 -> V_123 ) ) ;
F_28 ( V_57 , L_59 ,
V_75 -> V_124 ,
F_36 ( V_90 - V_75 -> V_124 ) ) ;
F_35 ( V_57 , L_60 , & V_75 -> V_125 [ 0 ] ) ;
F_35 ( V_57 , L_61 , & V_75 -> V_125 [ 1 ] ) ;
}
void F_42 ( struct V_13 * V_14 , const char * V_25 , ... )
{
T_2 args ;
va_start ( args , V_25 ) ;
F_9 ( V_14 , V_25 , args ) ;
va_end ( args ) ;
}
static int
F_43 ( int V_19 )
{
return F_44 ( V_19 , 4 ) ;
}
static bool
F_45 ( V_99 V_126 , char * V_127 )
{
int V_62 ;
if ( V_126 == 0 )
return false ;
V_127 [ 5 ] = '\0' ;
for ( V_62 = 5 ; V_62 -- ; ) {
V_127 [ V_62 ] = '!' + V_126 % 85 ;
V_126 /= 85 ;
}
return true ;
}
static void F_46 ( struct V_13 * V_57 ,
struct V_128 * V_1 ,
const char * V_59 ,
struct V_40 * V_129 )
{
char V_127 [ 6 ] ;
int V_46 ;
if ( ! V_129 )
return;
if ( V_59 ) {
F_28 ( V_57 , L_62 ,
V_1 ? V_1 -> V_59 : L_63 , V_59 ,
F_29 ( V_129 -> V_63 ) ,
F_30 ( V_129 -> V_63 ) ) ;
}
F_25 ( V_57 ) ;
for ( V_46 = 0 ; V_46 < V_129 -> V_49 ; V_46 ++ ) {
int V_62 , V_19 ;
V_19 = V_43 ;
if ( V_46 == V_129 -> V_49 - 1 )
V_19 -= V_129 -> V_56 ;
V_19 = F_43 ( V_19 ) ;
for ( V_62 = 0 ; V_62 < V_19 ; V_62 ++ ) {
if ( F_45 ( V_129 -> V_48 [ V_46 ] [ V_62 ] , V_127 ) )
F_26 ( V_57 , V_127 ) ;
else
F_26 ( V_57 , L_64 ) ;
}
}
F_26 ( V_57 , L_22 ) ;
}
static void F_47 ( struct V_13 * V_57 ,
const struct V_130 * V_131 )
{
#define F_48 ( T_4 ) err_printf(m, #x ": %s\n", yesno(info->x))
F_49 ( F_48 ) ;
#undef F_48
}
int F_50 ( struct V_13 * V_57 ,
const struct V_132 * V_133 )
{
struct V_134 * V_135 = V_133 -> V_70 ;
struct V_136 * V_137 = V_135 -> V_138 . V_137 ;
struct V_139 * error = V_133 -> error ;
struct V_40 * V_129 ;
int V_62 , V_140 ;
if ( ! error ) {
F_28 ( V_57 , L_65 ) ;
goto V_127;
}
F_28 ( V_57 , L_66 , error -> V_141 ) ;
F_28 ( V_57 , L_67 V_142 L_22 ) ;
F_28 ( V_57 , L_68 ,
error -> time . V_143 , error -> time . V_144 ) ;
F_28 ( V_57 , L_69 ,
error -> V_145 . V_143 , error -> V_145 . V_144 ) ;
F_28 ( V_57 , L_70 ,
error -> V_146 . V_143 , error -> V_146 . V_144 ) ;
F_47 ( V_57 , & error -> V_147 ) ;
for ( V_62 = 0 ; V_62 < F_51 ( error -> V_1 ) ; V_62 ++ ) {
if ( error -> V_1 [ V_62 ] . V_122 &&
error -> V_1 [ V_62 ] . V_87 != - 1 ) {
F_28 ( V_57 , L_71 ,
F_1 ( V_62 ) ,
error -> V_1 [ V_62 ] . V_148 ,
error -> V_1 [ V_62 ] . V_87 ,
error -> V_1 [ V_62 ] . V_149 ) ;
}
}
F_28 ( V_57 , L_72 , error -> V_150 ) ;
F_28 ( V_57 , L_73 , error -> V_151 ) ;
F_28 ( V_57 , L_74 , F_52 ( error -> V_147 . V_152 ) ) ;
F_28 ( V_57 , L_75 , V_137 -> V_153 ) ;
F_28 ( V_57 , L_76 , V_137 -> V_154 ) ;
F_28 ( V_57 , L_77 ,
V_137 -> V_155 ,
V_137 -> V_156 ) ;
F_28 ( V_57 , L_78 , error -> V_157 ) ;
if ( F_53 ( V_135 ) ) {
struct V_158 * V_159 = & V_135 -> V_159 ;
F_28 ( V_57 , L_79 ,
F_40 ( V_159 -> V_160 != NULL ) ) ;
F_28 ( V_57 , L_80 ,
F_54 ( V_159 -> V_161 ) ,
F_55 ( V_159 -> V_161 ) ) ;
}
F_28 ( V_57 , L_81 , error -> V_162 ) ;
F_28 ( V_57 , L_82 , error -> V_163 ) ;
if ( F_33 ( V_135 ) >= 8 ) {
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ )
F_28 ( V_57 , L_83 , V_62 ,
error -> V_164 [ V_62 ] ) ;
} else if ( F_56 ( V_135 ) || F_57 ( V_135 ) )
F_28 ( V_57 , L_84 , error -> V_164 [ 0 ] ) ;
F_28 ( V_57 , L_85 , error -> V_165 ) ;
F_28 ( V_57 , L_86 , error -> V_166 ) ;
F_28 ( V_57 , L_87 , error -> V_167 ) ;
F_28 ( V_57 , L_88 , error -> V_168 ) ;
F_28 ( V_57 , L_89 , V_135 -> V_169 . V_170 ) ;
for ( V_62 = 0 ; V_62 < V_135 -> V_171 ; V_62 ++ )
F_28 ( V_57 , L_90 , V_62 , error -> V_172 [ V_62 ] ) ;
if ( F_33 ( V_135 ) >= 6 ) {
F_28 ( V_57 , L_91 , error -> error ) ;
if ( F_33 ( V_135 ) >= 8 )
F_28 ( V_57 , L_92 ,
error -> V_173 , error -> V_174 ) ;
F_28 ( V_57 , L_93 , error -> V_175 ) ;
}
if ( F_58 ( V_135 ) )
F_28 ( V_57 , L_94 , error -> V_176 ) ;
for ( V_62 = 0 ; V_62 < F_51 ( error -> V_1 ) ; V_62 ++ ) {
if ( error -> V_1 [ V_62 ] . V_79 != - 1 )
F_37 ( V_57 , & error -> V_1 [ V_62 ] ) ;
}
for ( V_62 = 0 ; V_62 < F_51 ( error -> V_177 ) ; V_62 ++ ) {
char V_24 [ 128 ] ;
int V_19 , V_178 = 1 ;
if ( ! error -> V_177 [ V_62 ] )
break;
V_19 = F_59 ( V_24 , sizeof( V_24 ) , L_95 ) ;
for ( V_140 = 0 ; V_140 < F_51 ( error -> V_1 ) ; V_140 ++ ) {
if ( error -> V_1 [ V_140 ] . V_179 != error -> V_177 [ V_62 ] )
continue;
V_19 += F_59 ( V_24 + V_19 , sizeof( V_24 ) , L_96 ,
V_178 ? L_6 : L_97 ,
V_135 -> V_1 [ V_140 ] -> V_59 ) ;
V_178 = 0 ;
}
F_59 ( V_24 + V_19 , sizeof( V_24 ) , L_98 ) ;
F_27 ( V_57 , V_24 ,
error -> V_180 [ V_62 ] ,
error -> V_181 [ V_62 ] ) ;
}
F_27 ( V_57 , L_99 ,
error -> V_182 ,
error -> V_183 ) ;
for ( V_62 = 0 ; V_62 < F_51 ( error -> V_1 ) ; V_62 ++ ) {
struct V_74 * V_75 = & error -> V_1 [ V_62 ] ;
V_129 = V_75 -> V_103 ;
if ( V_129 ) {
F_26 ( V_57 , V_135 -> V_1 [ V_62 ] -> V_59 ) ;
if ( V_75 -> V_87 != - 1 )
F_28 ( V_57 , L_100 ,
V_75 -> V_148 ,
V_75 -> V_87 ,
V_75 -> V_149 ) ;
F_28 ( V_57 , L_101 ,
F_29 ( V_129 -> V_63 ) ,
F_30 ( V_129 -> V_63 ) ) ;
F_46 ( V_57 , V_135 -> V_1 [ V_62 ] , NULL , V_129 ) ;
}
if ( V_75 -> V_184 ) {
F_28 ( V_57 , L_102 ,
V_135 -> V_1 [ V_62 ] -> V_59 ,
V_75 -> V_184 ) ;
for ( V_140 = 0 ; V_140 < V_75 -> V_184 ; V_140 ++ )
F_35 ( V_57 , L_19 , & V_75 -> V_185 [ V_140 ] ) ;
}
if ( F_60 ( V_75 -> V_186 ) ) {
F_28 ( V_57 , L_103 ,
V_135 -> V_1 [ V_62 ] -> V_59 ) ;
} else if ( V_75 -> V_187 ) {
F_28 ( V_57 , L_104 ,
V_135 -> V_1 [ V_62 ] -> V_59 ,
V_75 -> V_187 ) ;
for ( V_140 = 0 ; V_140 < V_75 -> V_187 ; V_140 ++ ) {
F_28 ( V_57 , L_105 ,
V_75 -> V_186 [ V_140 ] . V_86 ,
V_75 -> V_186 [ V_140 ] . V_148 ,
V_75 -> V_186 [ V_140 ] . V_87 ) ;
}
}
F_46 ( V_57 , V_135 -> V_1 [ V_62 ] ,
L_106 , V_75 -> V_188 ) ;
F_46 ( V_57 , V_135 -> V_1 [ V_62 ] ,
L_107 , V_75 -> V_189 ) ;
F_46 ( V_57 , V_135 -> V_1 [ V_62 ] ,
L_108 , V_75 -> V_190 ) ;
F_46 ( V_57 , V_135 -> V_1 [ V_62 ] ,
L_109 , V_75 -> V_191 ) ;
F_46 ( V_57 , V_135 -> V_1 [ V_62 ] ,
L_110 , V_75 -> V_192 ) ;
}
F_46 ( V_57 , NULL , L_111 , error -> V_193 ) ;
F_46 ( V_57 , NULL , L_112 , error -> V_194 ) ;
if ( error -> V_195 )
F_61 ( V_57 , error -> V_195 ) ;
if ( error -> V_196 )
F_62 ( V_57 , V_135 , error -> V_196 ) ;
V_127:
if ( V_57 -> V_16 == 0 && V_57 -> V_15 )
return V_57 -> V_15 ;
return 0 ;
}
int F_63 ( struct V_13 * V_197 ,
struct V_134 * V_70 ,
T_1 V_61 , T_5 V_20 )
{
memset ( V_197 , 0 , sizeof( * V_197 ) ) ;
V_197 -> V_70 = V_70 ;
V_197 -> V_17 = V_61 + 1 > V_43 ? V_61 + 1 : V_43 ;
V_197 -> V_24 = F_13 ( V_197 -> V_17 ,
V_198 | V_199 | V_36 ) ;
if ( V_197 -> V_24 == NULL ) {
V_197 -> V_17 = V_43 ;
V_197 -> V_24 = F_13 ( V_197 -> V_17 , V_198 ) ;
}
if ( V_197 -> V_24 == NULL ) {
V_197 -> V_17 = 128 ;
V_197 -> V_24 = F_13 ( V_197 -> V_17 , V_198 ) ;
}
if ( V_197 -> V_24 == NULL )
return - V_47 ;
V_197 -> V_21 = V_20 ;
return 0 ;
}
static void F_64 ( struct V_40 * V_129 )
{
int V_46 ;
if ( V_129 == NULL )
return;
for ( V_46 = 0 ; V_46 < V_129 -> V_49 ; V_46 ++ )
F_24 ( ( unsigned long ) V_129 -> V_48 [ V_46 ] ) ;
F_16 ( V_129 ) ;
}
static void F_65 ( struct V_200 * V_201 )
{
struct V_139 * error = F_66 ( V_201 ,
F_67 ( * error ) , V_202 ) ;
int V_62 ;
for ( V_62 = 0 ; V_62 < F_51 ( error -> V_1 ) ; V_62 ++ ) {
struct V_74 * V_75 = & error -> V_1 [ V_62 ] ;
F_64 ( V_75 -> V_103 ) ;
F_64 ( V_75 -> V_192 ) ;
F_64 ( V_75 -> V_188 ) ;
F_64 ( V_75 -> V_189 ) ;
F_64 ( V_75 -> V_190 ) ;
F_64 ( V_75 -> V_191 ) ;
F_16 ( V_75 -> V_185 ) ;
if ( ! F_68 ( V_75 -> V_186 ) )
F_16 ( V_75 -> V_186 ) ;
}
F_64 ( error -> V_193 ) ;
F_64 ( error -> V_194 ) ;
for ( V_62 = 0 ; V_62 < F_51 ( error -> V_180 ) ; V_62 ++ )
F_16 ( error -> V_180 [ V_62 ] ) ;
F_16 ( error -> V_182 ) ;
F_16 ( error -> V_195 ) ;
F_16 ( error -> V_196 ) ;
F_16 ( error ) ;
}
static struct V_40 *
F_69 ( struct V_134 * V_70 ,
struct V_203 * V_204 )
{
struct V_205 * V_206 = & V_70 -> V_206 ;
const T_3 V_207 = V_206 -> V_208 . V_21 ;
struct V_40 * V_41 ;
struct V_28 V_28 ;
unsigned long V_209 ;
struct V_210 V_211 ;
T_6 V_212 ;
if ( ! V_204 )
return NULL ;
V_209 = F_70 ( T_3 , V_204 -> V_17 , V_204 -> V_129 -> V_213 . V_17 ) >> V_214 ;
V_209 = F_44 ( 10 * V_209 , 8 ) ;
V_41 = F_13 ( sizeof( * V_41 ) + V_209 * sizeof( V_99 * ) ,
V_35 | V_36 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_63 = V_204 -> V_215 . V_21 ;
V_41 -> V_105 = V_204 -> V_215 . V_17 ;
V_41 -> V_49 = 0 ;
V_41 -> V_56 = 0 ;
if ( ! F_12 ( & V_28 ) ) {
F_16 ( V_41 ) ;
return NULL ;
}
F_71 (dma, iter, vma->pages) {
void T_7 * V_216 ;
int V_217 ;
V_206 -> V_213 . V_218 ( & V_206 -> V_213 , V_212 , V_207 ,
V_219 , 0 ) ;
V_216 = F_72 ( & V_206 -> V_220 , V_207 ) ;
V_217 = F_19 ( & V_28 , ( void V_221 * ) V_216 , V_41 ) ;
F_73 ( V_216 ) ;
if ( V_217 )
goto V_222;
}
goto V_127;
V_222:
while ( V_41 -> V_49 -- )
F_24 ( ( unsigned long ) V_41 -> V_48 [ V_41 -> V_49 ] ) ;
F_16 ( V_41 ) ;
V_41 = NULL ;
V_127:
F_22 ( & V_28 , V_41 ) ;
V_206 -> V_213 . V_223 ( & V_206 -> V_213 , V_207 , V_43 ) ;
return V_41 ;
}
static inline T_8
F_74 ( struct V_224 * V_225 )
{
struct V_226 * V_227 ;
V_227 = F_75 ( V_225 ) ;
return V_227 ? V_227 -> V_228 : 0 ;
}
static inline int
F_76 ( struct V_224 * V_225 )
{
struct V_226 * V_227 ;
V_227 = F_75 ( V_225 ) ;
return V_227 ? V_227 -> V_1 -> V_229 : - 1 ;
}
static void F_77 ( struct V_60 * V_15 ,
struct V_203 * V_204 )
{
struct V_230 * V_129 = V_204 -> V_129 ;
int V_62 ;
V_15 -> V_17 = V_129 -> V_213 . V_17 ;
V_15 -> V_59 = V_129 -> V_213 . V_59 ;
for ( V_62 = 0 ; V_62 < V_66 ; V_62 ++ )
V_15 -> V_67 [ V_62 ] = F_74 ( & V_204 -> V_231 [ V_62 ] ) ;
V_15 -> V_68 = F_74 ( & V_129 -> V_232 ) ;
V_15 -> V_1 = F_76 ( & V_129 -> V_232 ) ;
V_15 -> V_63 = V_204 -> V_215 . V_21 ;
V_15 -> V_64 = V_129 -> V_213 . V_64 ;
V_15 -> V_65 = V_129 -> V_213 . V_65 ;
V_15 -> V_72 = V_204 -> V_172 ? V_204 -> V_172 -> V_229 : - 1 ;
V_15 -> V_7 = F_78 ( V_129 ) ;
V_15 -> V_11 = V_129 -> V_233 . V_11 ;
V_15 -> V_12 = V_129 -> V_233 . V_234 != V_235 ;
V_15 -> V_69 = V_129 -> V_69 . V_233 != NULL ;
V_15 -> V_71 = V_129 -> V_71 ;
}
static V_99 F_79 ( struct V_60 * V_15 ,
int V_61 , struct V_236 * V_91 ,
bool V_237 )
{
struct V_203 * V_204 ;
int V_62 = 0 ;
F_80 (vma, head, vm_link) {
if ( V_237 && ! F_81 ( V_204 ) )
continue;
F_77 ( V_15 ++ , V_204 ) ;
if ( ++ V_62 == V_61 )
break;
}
return V_62 ;
}
static T_8 F_82 ( struct V_134 * V_135 ,
struct V_139 * error ,
int * V_79 )
{
T_8 V_238 = 0 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_66 ; V_62 ++ ) {
if ( error -> V_1 [ V_62 ] . V_122 ) {
if ( V_79 )
* V_79 = V_62 ;
return error -> V_1 [ V_62 ] . V_102 ^
error -> V_1 [ V_62 ] . V_78 . V_78 ;
}
}
return V_238 ;
}
static void F_83 ( struct V_134 * V_135 ,
struct V_139 * error )
{
int V_62 ;
if ( F_84 ( V_135 ) || F_85 ( V_135 ) ) {
for ( V_62 = 0 ; V_62 < V_135 -> V_171 ; V_62 ++ )
error -> V_172 [ V_62 ] = F_86 ( F_87 ( V_62 ) ) ;
} else if ( F_88 ( V_135 ) || F_89 ( V_135 ) ) {
for ( V_62 = 0 ; V_62 < V_135 -> V_171 ; V_62 ++ )
error -> V_172 [ V_62 ] = F_90 ( F_91 ( V_62 ) ) ;
} else if ( F_33 ( V_135 ) >= 6 ) {
for ( V_62 = 0 ; V_62 < V_135 -> V_171 ; V_62 ++ )
error -> V_172 [ V_62 ] = F_90 ( F_92 ( V_62 ) ) ;
}
}
static inline V_99
F_93 ( struct V_128 * V_1 ,
struct V_128 * V_239 )
{
int V_240 ;
V_240 = ( V_239 - V_1 ) - 1 ;
if ( V_240 < 0 )
V_240 += V_66 ;
return V_240 ;
}
static void F_94 ( struct V_139 * error ,
struct V_128 * V_1 ,
struct V_74 * V_75 )
{
struct V_134 * V_135 = V_1 -> V_70 ;
struct V_128 * V_241 ;
enum V_242 V_229 ;
if ( ! error -> V_193 )
return;
F_95 (to, dev_priv, id) {
int V_240 ;
T_9 V_243 ;
V_99 * V_26 ;
if ( V_1 == V_241 )
continue;
V_243 =
( F_96 ( V_1 , V_229 ) & ( V_43 - 1 ) ) / 4 ;
V_26 = error -> V_193 -> V_48 [ 0 ] ;
V_240 = F_93 ( V_1 , V_241 ) ;
V_75 -> V_113 [ V_240 ] = V_26 [ V_243 ] ;
}
}
static void F_97 ( struct V_128 * V_1 ,
struct V_74 * V_75 )
{
struct V_134 * V_135 = V_1 -> V_70 ;
V_75 -> V_113 [ 0 ] = F_86 ( F_98 ( V_1 -> V_244 ) ) ;
V_75 -> V_113 [ 1 ] = F_86 ( F_99 ( V_1 -> V_244 ) ) ;
if ( F_38 ( V_135 ) )
V_75 -> V_113 [ 2 ] =
F_86 ( F_100 ( V_1 -> V_244 ) ) ;
}
static void F_101 ( struct V_128 * V_1 ,
struct V_74 * V_75 )
{
struct V_245 * V_246 = & V_1 -> V_247 ;
struct V_248 * V_249 ;
struct V_250 * V_251 ;
int V_61 ;
V_75 -> V_187 = 0 ;
V_75 -> V_186 = NULL ;
if ( F_102 ( & V_246 -> V_186 ) )
return;
if ( ! F_103 ( & V_246 -> V_252 ) ) {
V_75 -> V_186 = F_104 ( - V_253 ) ;
return;
}
V_61 = 0 ;
for ( V_251 = F_105 ( & V_246 -> V_186 ) ; V_251 != NULL ; V_251 = F_106 ( V_251 ) )
V_61 ++ ;
F_107 ( & V_246 -> V_252 ) ;
V_249 = NULL ;
if ( V_61 )
V_249 = F_108 ( V_61 ,
sizeof( struct V_248 ) ,
V_35 ) ;
if ( ! V_249 )
return;
if ( ! F_103 ( & V_246 -> V_252 ) ) {
F_16 ( V_249 ) ;
V_75 -> V_186 = F_104 ( - V_253 ) ;
return;
}
V_75 -> V_186 = V_249 ;
for ( V_251 = F_105 ( & V_246 -> V_186 ) ; V_251 ; V_251 = F_106 ( V_251 ) ) {
struct V_254 * V_255 = F_66 ( V_251 , F_67 ( * V_255 ) , V_215 ) ;
strcpy ( V_249 -> V_148 , V_255 -> V_256 -> V_148 ) ;
V_249 -> V_87 = V_255 -> V_256 -> V_87 ;
V_249 -> V_86 = V_255 -> V_86 ;
V_249 ++ ;
if ( ++ V_75 -> V_187 == V_61 )
break;
}
F_107 ( & V_246 -> V_252 ) ;
}
static void F_109 ( struct V_139 * error ,
struct V_128 * V_1 ,
struct V_74 * V_75 )
{
struct V_134 * V_135 = V_1 -> V_70 ;
if ( F_33 ( V_135 ) >= 6 ) {
V_75 -> V_111 = F_86 ( F_110 ( V_1 -> V_244 ) ) ;
V_75 -> V_112 = F_86 ( F_111 ( V_1 ) ) ;
if ( F_33 ( V_135 ) >= 8 )
F_94 ( error , V_1 , V_75 ) ;
else
F_97 ( V_1 , V_75 ) ;
}
if ( F_33 ( V_135 ) >= 4 ) {
V_75 -> V_110 = F_86 ( F_112 ( V_1 -> V_244 ) ) ;
V_75 -> V_101 = F_86 ( F_113 ( V_1 -> V_244 ) ) ;
V_75 -> V_102 = F_86 ( F_114 ( V_1 -> V_244 ) ) ;
V_75 -> V_108 = F_86 ( F_115 ( V_1 -> V_244 ) ) ;
V_75 -> V_106 = F_86 ( F_116 ( V_1 -> V_244 ) ) ;
if ( F_33 ( V_135 ) >= 8 ) {
V_75 -> V_110 |= ( T_3 ) F_86 ( F_117 ( V_1 -> V_244 ) ) << 32 ;
V_75 -> V_106 |= ( T_3 ) F_86 ( F_118 ( V_1 -> V_244 ) ) << 32 ;
}
V_75 -> V_107 = F_86 ( F_119 ( V_1 -> V_244 ) ) ;
} else {
V_75 -> V_110 = F_86 ( V_257 ) ;
V_75 -> V_101 = F_86 ( V_258 ) ;
V_75 -> V_102 = F_86 ( V_259 ) ;
}
F_120 ( V_1 , & V_75 -> V_78 ) ;
V_75 -> V_119 = F_121 ( V_1 ) ;
V_75 -> V_109 = F_86 ( F_122 ( V_1 -> V_244 ) ) ;
V_75 -> V_100 = F_123 ( V_1 ) ;
V_75 -> V_86 = F_124 ( V_1 ) ;
V_75 -> V_118 = F_125 ( V_1 ) ;
V_75 -> V_21 = F_126 ( V_1 ) ;
V_75 -> V_91 = F_127 ( V_1 ) ;
V_75 -> V_92 = F_128 ( V_1 ) ;
V_75 -> V_96 = F_129 ( V_1 ) ;
if ( F_33 ( V_135 ) > 2 )
V_75 -> V_97 = F_130 ( V_1 ) ;
if ( ! F_131 ( V_135 ) ) {
T_10 V_260 ;
if ( F_58 ( V_135 ) ) {
switch ( V_1 -> V_229 ) {
default:
case V_2 :
V_260 = V_261 ;
break;
case V_4 :
V_260 = V_262 ;
break;
case V_3 :
V_260 = V_263 ;
break;
case V_5 :
V_260 = V_264 ;
break;
}
} else if ( F_132 ( V_1 -> V_70 ) ) {
V_260 = F_133 ( V_1 -> V_244 ) ;
} else {
V_260 = F_134 ( V_1 -> V_244 ) ;
}
V_75 -> V_98 = F_86 ( V_260 ) ;
}
V_75 -> V_124 = V_1 -> V_265 . V_266 ;
V_75 -> V_123 = V_1 -> V_265 . V_267 ;
V_75 -> V_122 = V_1 -> V_265 . V_268 ;
if ( F_39 ( V_135 ) ) {
int V_62 ;
V_75 -> V_114 . V_115 = F_86 ( F_135 ( V_1 ) ) ;
if ( F_132 ( V_135 ) )
V_75 -> V_114 . V_117 =
F_86 ( F_136 ( V_1 ) ) ;
else if ( F_58 ( V_135 ) )
V_75 -> V_114 . V_117 =
F_86 ( F_137 ( V_1 ) ) ;
else if ( F_33 ( V_135 ) >= 8 )
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
V_75 -> V_114 . V_116 [ V_62 ] =
F_86 ( F_138 ( V_1 , V_62 ) ) ;
V_75 -> V_114 . V_116 [ V_62 ] <<= 32 ;
V_75 -> V_114 . V_116 [ V_62 ] |=
F_86 ( F_139 ( V_1 , V_62 ) ) ;
}
}
}
static void F_140 ( struct V_226 * V_227 ,
struct V_84 * V_85 )
{
V_85 -> V_89 = V_227 -> V_190 -> V_269 ;
V_85 -> V_88 = V_227 -> V_190 -> V_88 ;
V_85 -> V_86 = V_227 -> V_228 ;
V_85 -> V_90 = V_227 -> V_270 ;
V_85 -> V_91 = V_227 -> V_91 ;
V_85 -> V_92 = V_227 -> V_92 ;
F_141 () ;
V_85 -> V_87 = V_227 -> V_190 -> V_87 ? F_142 ( V_227 -> V_190 -> V_87 ) : 0 ;
F_143 () ;
}
static void F_144 ( struct V_128 * V_1 ,
struct V_226 * V_178 ,
struct V_74 * V_75 )
{
struct V_226 * V_227 ;
int V_61 ;
V_61 = 0 ;
V_227 = V_178 ;
F_145 (request, &engine->timeline->requests, link)
V_61 ++ ;
if ( ! V_61 )
return;
V_75 -> V_185 = F_146 ( V_61 , sizeof( * V_75 -> V_185 ) , V_35 ) ;
if ( ! V_75 -> V_185 )
return;
V_75 -> V_184 = V_61 ;
V_61 = 0 ;
V_227 = V_178 ;
F_145 (request, &engine->timeline->requests, link) {
if ( V_61 >= V_75 -> V_184 ) {
break;
}
F_140 ( V_227 , & V_75 -> V_185 [ V_61 ++ ] ) ;
}
V_75 -> V_184 = V_61 ;
}
static void F_147 ( struct V_128 * V_1 ,
struct V_74 * V_75 )
{
unsigned int V_271 ;
for ( V_271 = 0 ; V_271 < F_51 ( V_1 -> V_272 ) ; V_271 ++ )
if ( V_1 -> V_272 [ V_271 ] . V_227 )
F_140 ( V_1 -> V_272 [ V_271 ] . V_227 ,
& V_75 -> V_125 [ V_271 ] ) ;
}
static void F_148 ( struct V_134 * V_135 ,
struct V_139 * error )
{
struct V_205 * V_206 = & V_135 -> V_206 ;
int V_62 ;
error -> V_193 =
F_69 ( V_135 , V_135 -> V_193 ) ;
for ( V_62 = 0 ; V_62 < V_66 ; V_62 ++ ) {
struct V_128 * V_1 = V_135 -> V_1 [ V_62 ] ;
struct V_74 * V_75 = & error -> V_1 [ V_62 ] ;
struct V_226 * V_227 ;
V_75 -> V_87 = - 1 ;
V_75 -> V_79 = - 1 ;
if ( ! V_1 )
continue;
V_75 -> V_79 = V_62 ;
F_109 ( error , V_1 , V_75 ) ;
F_101 ( V_1 , V_75 ) ;
F_147 ( V_1 , V_75 ) ;
V_227 = F_149 ( V_1 ) ;
if ( V_227 ) {
struct V_273 * V_274 ;
struct V_87 * V_87 ;
V_75 -> V_179 = V_227 -> V_190 -> V_275 ?
& V_227 -> V_190 -> V_275 -> V_213 : & V_206 -> V_213 ;
V_75 -> V_103 =
F_69 ( V_135 ,
V_227 -> V_276 ) ;
if ( F_150 ( V_135 ) )
V_75 -> V_192 =
F_69 ( V_135 ,
V_1 -> V_277 ) ;
V_75 -> V_190 =
F_69 ( V_135 ,
V_227 -> V_190 -> V_1 [ V_62 ] . V_278 ) ;
V_87 = V_227 -> V_190 -> V_87 ;
if ( V_87 ) {
struct V_279 * V_280 ;
F_141 () ;
V_280 = F_151 ( V_87 , V_281 ) ;
if ( V_280 ) {
strcpy ( V_75 -> V_148 , V_280 -> V_148 ) ;
V_75 -> V_87 = V_280 -> V_87 ;
}
F_143 () ;
}
error -> V_282 |=
F_152 ( V_227 -> V_190 ) ;
V_75 -> V_93 = V_227 -> V_91 ;
V_75 -> V_94 = V_227 -> V_283 ;
V_75 -> V_95 = V_227 -> V_92 ;
V_274 = V_227 -> V_274 ;
V_75 -> V_120 = V_274 -> V_91 ;
V_75 -> V_121 = V_274 -> V_92 ;
V_75 -> V_188 =
F_69 ( V_135 , V_274 -> V_204 ) ;
F_144 ( V_1 , V_227 , V_75 ) ;
}
V_75 -> V_189 =
F_69 ( V_135 ,
V_1 -> V_284 . V_204 ) ;
V_75 -> V_191 =
F_69 ( V_135 , V_1 -> V_191 . V_204 ) ;
}
}
static void F_153 ( struct V_134 * V_135 ,
struct V_139 * error ,
struct V_285 * V_179 ,
int V_240 )
{
struct V_60 * V_180 ;
struct V_203 * V_204 ;
int V_61 ;
V_61 = 0 ;
F_80 (vma, &vm->active_list, vm_link)
V_61 ++ ;
V_180 = NULL ;
if ( V_61 )
V_180 = F_146 ( V_61 , sizeof( * V_180 ) , V_35 ) ;
if ( V_180 )
V_61 = F_79 ( V_180 , V_61 , & V_179 -> V_286 , false ) ;
else
V_61 = 0 ;
error -> V_177 [ V_240 ] = V_179 ;
error -> V_180 [ V_240 ] = V_180 ;
error -> V_181 [ V_240 ] = V_61 ;
}
static void F_154 ( struct V_134 * V_135 ,
struct V_139 * error )
{
int V_287 = 0 , V_62 , V_140 ;
F_155 ( F_51 ( error -> V_1 ) > F_51 ( error -> V_180 ) ) ;
F_155 ( F_51 ( error -> V_180 ) != F_51 ( error -> V_177 ) ) ;
F_155 ( F_51 ( error -> V_180 ) != F_51 ( error -> V_181 ) ) ;
for ( V_62 = 0 ; V_62 < F_51 ( error -> V_1 ) ; V_62 ++ ) {
struct V_74 * V_75 = & error -> V_1 [ V_62 ] ;
bool V_288 ;
if ( ! V_75 -> V_179 )
continue;
V_288 = false ;
for ( V_140 = 0 ; V_140 < V_62 && ! V_288 ; V_140 ++ )
V_288 = error -> V_1 [ V_140 ] . V_179 == V_75 -> V_179 ;
if ( ! V_288 )
F_153 ( V_135 , error , V_75 -> V_179 , V_287 ++ ) ;
}
}
static void F_156 ( struct V_134 * V_135 ,
struct V_139 * error )
{
struct V_285 * V_179 = & V_135 -> V_206 . V_213 ;
struct V_60 * V_289 ;
struct V_203 * V_204 ;
int V_290 , V_291 ;
V_290 = 0 ;
F_80 (vma, &vm->active_list, vm_link)
V_290 ++ ;
V_291 = 0 ;
F_80 (vma, &vm->inactive_list, vm_link)
V_291 ++ ;
V_289 = NULL ;
if ( V_290 + V_291 )
V_289 = F_146 ( V_290 + V_291 ,
sizeof( * V_289 ) , V_35 ) ;
if ( ! V_289 )
return;
V_290 = F_79 ( V_289 , V_290 ,
& V_179 -> V_286 , true ) ;
V_291 = F_79 ( V_289 + V_290 , V_291 ,
& V_179 -> V_292 , true ) ;
error -> V_183 = V_290 + V_291 ;
error -> V_182 = V_289 ;
}
static void F_157 ( struct V_134 * V_135 ,
struct V_139 * error )
{
if ( ! V_135 -> V_293 . log . V_204 || ( V_70 . V_294 < 0 ) )
return;
error -> V_194 = F_69 ( V_135 ,
V_135 -> V_293 . log . V_204 ) ;
}
static void F_158 ( struct V_134 * V_135 ,
struct V_139 * error )
{
int V_62 ;
if ( F_57 ( V_135 ) ) {
error -> V_164 [ 0 ] = F_86 ( V_295 ) ;
error -> V_163 = F_86 ( V_296 ) ;
error -> V_166 = F_159 ( V_297 ) ;
}
if ( F_58 ( V_135 ) )
error -> V_176 = F_86 ( V_298 ) ;
if ( F_33 ( V_135 ) >= 8 ) {
error -> V_174 = F_86 ( V_299 ) ;
error -> V_173 = F_86 ( V_300 ) ;
}
if ( F_132 ( V_135 ) ) {
error -> V_166 = F_159 ( V_301 ) ;
error -> V_302 = F_86 ( V_303 ) ;
error -> V_115 = F_86 ( V_304 ) ;
}
if ( F_33 ( V_135 ) >= 7 )
error -> V_166 = F_159 ( V_305 ) ;
if ( F_33 ( V_135 ) >= 6 ) {
error -> V_167 = F_86 ( V_306 ) ;
error -> error = F_86 ( V_307 ) ;
error -> V_175 = F_86 ( V_308 ) ;
}
if ( F_132 ( V_135 ) || F_58 ( V_135 ) ) {
error -> V_309 = F_86 ( V_310 ) ;
error -> V_311 = F_86 ( V_312 ) ;
}
if ( F_160 ( V_135 ) )
error -> V_168 = F_86 ( V_313 ) ;
if ( F_33 ( V_135 ) >= 8 ) {
error -> V_163 = F_86 ( V_314 ) ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ )
error -> V_164 [ V_62 ] = F_86 ( F_161 ( V_62 ) ) ;
} else if ( F_56 ( V_135 ) ) {
error -> V_163 = F_86 ( V_315 ) ;
error -> V_164 [ 0 ] = F_86 ( V_295 ) ;
} else if ( F_85 ( V_135 ) ) {
error -> V_163 = F_162 ( V_316 ) ;
} else if ( ! F_57 ( V_135 ) ) {
error -> V_163 = F_86 ( V_316 ) ;
}
error -> V_162 = F_86 ( V_317 ) ;
error -> V_165 = F_86 ( V_318 ) ;
}
static void F_163 ( struct V_134 * V_135 ,
struct V_139 * error ,
V_99 V_319 ,
const char * V_141 )
{
V_99 V_320 ;
int V_79 = - 1 , V_19 ;
V_320 = F_82 ( V_135 , error , & V_79 ) ;
V_19 = F_59 ( error -> V_141 , sizeof( error -> V_141 ) ,
L_113 ,
F_33 ( V_135 ) , V_79 , V_320 ) ;
if ( V_79 != - 1 && error -> V_1 [ V_79 ] . V_87 != - 1 )
V_19 += F_59 ( error -> V_141 + V_19 ,
sizeof( error -> V_141 ) - V_19 ,
L_114 ,
error -> V_1 [ V_79 ] . V_148 ,
error -> V_1 [ V_79 ] . V_87 ) ;
F_59 ( error -> V_141 + V_19 , sizeof( error -> V_141 ) - V_19 ,
L_115 ,
V_141 ,
V_319 ? L_116 : L_117 ) ;
}
static void F_164 ( struct V_134 * V_135 ,
struct V_139 * error )
{
error -> V_157 = - 1 ;
#ifdef F_165
error -> V_157 = V_321 ;
#endif
error -> V_150 = F_166 ( & V_135 -> V_169 ) ;
error -> V_151 = V_135 -> V_151 ;
memcpy ( & error -> V_147 ,
F_167 ( V_135 ) ,
sizeof( error -> V_147 ) ) ;
}
static int F_168 ( void * V_322 )
{
struct V_139 * error = V_322 ;
F_164 ( error -> V_70 , error ) ;
F_158 ( error -> V_70 , error ) ;
F_83 ( error -> V_70 , error ) ;
F_148 ( error -> V_70 , error ) ;
F_154 ( error -> V_70 , error ) ;
F_156 ( error -> V_70 , error ) ;
F_157 ( error -> V_70 , error ) ;
F_169 ( & error -> time ) ;
error -> V_145 = F_170 ( F_171 () ) ;
error -> V_146 =
F_170 ( F_172 ( F_173 () ,
error -> V_70 -> V_323 . V_324 ) ) ;
error -> V_195 = F_174 ( error -> V_70 ) ;
error -> V_196 = F_175 ( error -> V_70 ) ;
return 0 ;
}
void F_176 ( struct V_134 * V_135 ,
V_99 V_319 ,
const char * V_141 )
{
static bool V_325 ;
struct V_139 * error ;
unsigned long V_326 ;
if ( ! V_70 . V_208 )
return;
if ( F_177 ( V_135 -> V_169 . V_327 ) )
return;
error = F_178 ( sizeof( * error ) , V_35 ) ;
if ( ! error ) {
F_179 ( L_118 ) ;
return;
}
F_180 ( & error -> V_202 ) ;
error -> V_70 = V_135 ;
F_181 ( F_168 , error , NULL ) ;
F_163 ( V_135 , error , V_319 , V_141 ) ;
F_182 ( L_66 , error -> V_141 ) ;
if ( ! error -> V_282 ) {
F_183 ( & V_135 -> V_169 . V_252 , V_326 ) ;
if ( ! V_135 -> V_169 . V_327 ) {
V_135 -> V_169 . V_327 = error ;
error = NULL ;
}
F_184 ( & V_135 -> V_169 . V_252 , V_326 ) ;
}
if ( error ) {
F_65 ( & error -> V_202 ) ;
return;
}
if ( ! V_325 &&
F_185 () - V_328 < F_186 ( 180 ) ) {
F_182 ( L_119 ) ;
F_182 ( L_120 ) ;
F_182 ( L_121 ) ;
F_182 ( L_122 ) ;
F_182 ( L_123 ,
V_135 -> V_138 . V_329 -> V_330 ) ;
V_325 = true ;
}
}
void F_187 ( struct V_331 * V_332 ,
struct V_132 * V_133 )
{
struct V_134 * V_135 = F_188 ( V_332 ) ;
F_189 ( & V_135 -> V_169 . V_252 ) ;
V_133 -> error = V_135 -> V_169 . V_327 ;
if ( V_133 -> error )
F_190 ( & V_133 -> error -> V_202 ) ;
F_107 ( & V_135 -> V_169 . V_252 ) ;
}
void F_191 ( struct V_132 * V_133 )
{
if ( V_133 -> error )
F_192 ( & V_133 -> error -> V_202 , F_65 ) ;
}
void F_193 ( struct V_134 * V_135 )
{
struct V_139 * error ;
F_189 ( & V_135 -> V_169 . V_252 ) ;
error = V_135 -> V_169 . V_327 ;
V_135 -> V_169 . V_327 = NULL ;
F_107 ( & V_135 -> V_169 . V_252 ) ;
if ( error )
F_192 ( & error -> V_202 , F_65 ) ;
}
