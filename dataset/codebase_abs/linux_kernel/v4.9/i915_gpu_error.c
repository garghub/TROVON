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
static void F_12 ( struct V_13 * V_28 ,
const char * V_29 ,
struct V_30 * V_15 ,
int V_31 )
{
int V_32 ;
F_13 ( V_28 , L_12 , V_29 , V_31 ) ;
while ( V_31 -- ) {
F_13 ( V_28 , L_13 ,
F_14 ( V_15 -> V_33 ) ,
F_15 ( V_15 -> V_33 ) ,
V_15 -> V_17 ,
V_15 -> V_34 ,
V_15 -> V_35 ) ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ )
F_13 ( V_28 , L_14 , V_15 -> V_37 [ V_32 ] ) ;
F_13 ( V_28 , L_15 , V_15 -> V_38 ) ;
F_16 ( V_28 , F_2 ( V_15 -> V_7 ) ) ;
F_16 ( V_28 , F_3 ( V_15 -> V_11 ) ) ;
F_16 ( V_28 , F_4 ( V_15 -> V_12 ) ) ;
F_16 ( V_28 , V_15 -> V_39 ? L_16 : L_6 ) ;
F_16 ( V_28 , V_15 -> V_1 != - 1 ? L_17 : L_6 ) ;
F_16 ( V_28 , F_1 ( V_15 -> V_1 ) ) ;
F_16 ( V_28 , F_17 ( V_28 -> V_40 , V_15 -> V_41 ) ) ;
if ( V_15 -> V_29 )
F_13 ( V_28 , L_18 , V_15 -> V_29 ) ;
if ( V_15 -> V_42 != V_43 )
F_13 ( V_28 , L_19 , V_15 -> V_42 ) ;
F_16 ( V_28 , L_20 ) ;
V_15 ++ ;
}
}
static const char * F_18 ( enum V_44 V_45 )
{
switch ( V_45 ) {
case V_46 :
return L_21 ;
case V_47 :
return L_22 ;
case V_48 :
return L_23 ;
case V_49 :
return L_24 ;
case V_50 :
return L_25 ;
}
return L_26 ;
}
static void F_19 ( struct V_13 * V_28 ,
struct V_51 * V_52 )
{
F_13 ( V_28 , L_27 , F_1 ( V_52 -> V_53 ) ) ;
F_13 ( V_28 , L_28 , V_52 -> V_21 ) ;
F_13 ( V_28 , L_29 , V_52 -> V_54 ) ;
F_13 ( V_28 , L_30 , V_52 -> V_55 ) ;
F_13 ( V_28 , L_31 , V_52 -> V_56 ) ;
F_13 ( V_28 , L_32 , V_52 -> V_57 ) ;
F_13 ( V_28 , L_33 , V_52 -> V_58 ) ;
F_13 ( V_28 , L_34 ,
( V_59 ) ( V_52 -> V_60 >> 32 ) , ( V_59 ) V_52 -> V_60 ) ;
F_13 ( V_28 , L_35 , V_52 -> V_61 ) ;
F_13 ( V_28 , L_36 , V_52 -> V_62 ) ;
F_13 ( V_28 , L_37 , V_52 -> V_63 ) ;
if ( V_52 -> V_64 ) {
T_3 V_21 = V_52 -> V_64 -> V_33 ;
T_3 V_65 = V_21 + V_52 -> V_64 -> V_66 ;
F_13 ( V_28 , L_38 ,
F_14 ( V_21 ) , F_15 ( V_21 ) ,
F_14 ( V_65 ) , F_15 ( V_65 ) ) ;
}
if ( F_20 ( V_28 -> V_40 ) >= 4 ) {
F_13 ( V_28 , L_39 ,
( V_59 ) ( V_52 -> V_67 >> 32 ) , ( V_59 ) V_52 -> V_67 ) ;
F_13 ( V_28 , L_40 , V_52 -> V_68 ) ;
F_13 ( V_28 , L_41 , V_52 -> V_69 ) ;
}
F_13 ( V_28 , L_42 , V_52 -> V_70 ) ;
F_13 ( V_28 , L_43 , F_14 ( V_52 -> V_71 ) ,
F_15 ( V_52 -> V_71 ) ) ;
if ( F_20 ( V_28 -> V_40 ) >= 6 ) {
F_13 ( V_28 , L_44 , V_52 -> V_72 ) ;
F_13 ( V_28 , L_45 , V_52 -> V_73 ) ;
F_13 ( V_28 , L_46 ,
V_52 -> V_74 [ 0 ] ,
V_52 -> V_75 [ 0 ] ) ;
F_13 ( V_28 , L_47 ,
V_52 -> V_74 [ 1 ] ,
V_52 -> V_75 [ 1 ] ) ;
if ( F_21 ( V_28 -> V_40 ) ) {
F_13 ( V_28 , L_48 ,
V_52 -> V_74 [ 2 ] ,
V_52 -> V_75 [ 2 ] ) ;
}
}
if ( F_22 ( V_28 -> V_40 ) ) {
F_13 ( V_28 , L_49 , V_52 -> V_76 . V_77 ) ;
if ( F_20 ( V_28 -> V_40 ) >= 8 ) {
int V_32 ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
F_13 ( V_28 , L_50 ,
V_32 , V_52 -> V_76 . V_78 [ V_32 ] ) ;
} else {
F_13 ( V_28 , L_51 ,
V_52 -> V_76 . V_79 ) ;
}
}
F_13 ( V_28 , L_52 , V_52 -> V_80 ) ;
F_13 ( V_28 , L_53 , V_52 -> V_81 ) ;
F_13 ( V_28 , L_54 , F_23 ( V_52 -> V_82 ) ) ;
F_13 ( V_28 , L_55 , V_52 -> V_83 ) ;
F_13 ( V_28 , L_56 , V_52 -> V_84 ) ;
F_13 ( V_28 , L_57 ,
F_18 ( V_52 -> V_85 ) ,
V_52 -> V_86 ) ;
}
void F_24 ( struct V_13 * V_14 , const char * V_25 , ... )
{
T_2 args ;
va_start ( args , V_25 ) ;
F_9 ( V_14 , V_25 , args ) ;
va_end ( args ) ;
}
static void F_25 ( struct V_13 * V_28 ,
struct V_87 * V_88 )
{
int V_89 , V_90 , V_91 ;
for ( V_89 = V_90 = 0 ; V_89 < V_88 -> V_92 ; V_89 ++ ) {
for ( V_91 = 0 ; V_91 < V_93 / 4 ; V_91 ++ ) {
F_13 ( V_28 , L_58 , V_90 ,
V_88 -> V_94 [ V_89 ] [ V_91 ] ) ;
V_90 += 4 ;
}
}
}
static void F_26 ( struct V_13 * V_28 ,
const struct V_95 * V_96 )
{
#define F_27 ( T_4 ) err_printf(m, #x ": %s\n", yesno(info->x))
#define F_28 ;
F_29 ( F_27 , F_28 ) ;
#undef F_27
#undef F_28
}
int F_30 ( struct V_13 * V_28 ,
const struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_100 ;
struct V_101 * V_102 = F_31 ( V_100 ) ;
struct V_103 * V_104 = V_102 -> V_105 . V_104 ;
struct V_106 * error = V_98 -> error ;
struct V_87 * V_88 ;
int V_32 , V_107 , V_90 , V_91 ;
int V_108 ;
if ( ! error ) {
F_13 ( V_28 , L_59 ) ;
goto V_109;
}
F_13 ( V_28 , L_60 , error -> V_110 ) ;
F_13 ( V_28 , L_61 , error -> time . V_111 ,
error -> time . V_112 ) ;
F_13 ( V_28 , L_62 V_113 L_20 ) ;
F_26 ( V_28 , & error -> V_114 ) ;
V_108 = 0 ;
for ( V_32 = 0 ; V_32 < F_32 ( error -> V_1 ) ; V_32 ++ ) {
if ( error -> V_1 [ V_32 ] . V_86 > V_108 )
V_108 = error -> V_1 [ V_32 ] . V_86 ;
}
for ( V_32 = 0 ; V_32 < F_32 ( error -> V_1 ) ; V_32 ++ ) {
if ( error -> V_1 [ V_32 ] . V_86 == V_108 &&
error -> V_1 [ V_32 ] . V_115 != - 1 ) {
F_13 ( V_28 , L_63 ,
F_1 ( V_32 ) ,
error -> V_1 [ V_32 ] . V_116 ,
error -> V_1 [ V_32 ] . V_115 ) ;
}
}
F_13 ( V_28 , L_64 , error -> V_117 ) ;
F_13 ( V_28 , L_65 , error -> V_118 ) ;
F_13 ( V_28 , L_66 , V_104 -> V_119 ) ;
F_13 ( V_28 , L_67 , V_104 -> V_120 ) ;
F_13 ( V_28 , L_68 ,
V_104 -> V_121 ,
V_104 -> V_122 ) ;
F_13 ( V_28 , L_69 , error -> V_123 ) ;
if ( F_33 ( V_100 ) ) {
struct V_124 * V_125 = & V_102 -> V_125 ;
F_13 ( V_28 , L_70 ,
F_23 ( V_125 -> V_126 != NULL ) ) ;
F_13 ( V_28 , L_71 ,
F_34 ( V_125 -> V_127 ) ,
F_35 ( V_125 -> V_127 ) ) ;
}
F_13 ( V_28 , L_72 , error -> V_128 ) ;
F_13 ( V_28 , L_73 , error -> V_129 ) ;
if ( F_36 ( V_100 ) -> V_130 >= 8 ) {
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
F_13 ( V_28 , L_74 , V_32 ,
error -> V_131 [ V_32 ] ) ;
} else if ( F_37 ( V_100 ) || F_38 ( V_100 ) )
F_13 ( V_28 , L_75 , error -> V_131 [ 0 ] ) ;
F_13 ( V_28 , L_76 , error -> V_132 ) ;
F_13 ( V_28 , L_77 , error -> V_133 ) ;
F_13 ( V_28 , L_78 , error -> V_134 ) ;
F_13 ( V_28 , L_79 , error -> V_135 ) ;
F_13 ( V_28 , L_80 , V_102 -> V_136 . V_137 ) ;
for ( V_32 = 0 ; V_32 < V_102 -> V_138 ; V_32 ++ )
F_13 ( V_28 , L_81 , V_32 , error -> V_139 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < F_32 ( error -> V_140 ) ; V_32 ++ )
F_13 ( V_28 , L_82 , V_32 ,
error -> V_140 [ V_32 ] ) ;
if ( F_36 ( V_100 ) -> V_130 >= 6 ) {
F_13 ( V_28 , L_83 , error -> error ) ;
if ( F_36 ( V_100 ) -> V_130 >= 8 )
F_13 ( V_28 , L_84 ,
error -> V_141 , error -> V_142 ) ;
F_13 ( V_28 , L_85 , error -> V_143 ) ;
}
if ( F_39 ( V_100 ) )
F_13 ( V_28 , L_86 , error -> V_144 ) ;
for ( V_32 = 0 ; V_32 < F_32 ( error -> V_1 ) ; V_32 ++ ) {
if ( error -> V_1 [ V_32 ] . V_53 != - 1 )
F_19 ( V_28 , & error -> V_1 [ V_32 ] ) ;
}
for ( V_32 = 0 ; V_32 < F_32 ( error -> V_145 ) ; V_32 ++ ) {
char V_24 [ 128 ] ;
int V_19 , V_146 = 1 ;
if ( ! error -> V_145 [ V_32 ] )
break;
V_19 = F_40 ( V_24 , sizeof( V_24 ) , L_87 ) ;
for ( V_107 = 0 ; V_107 < F_32 ( error -> V_1 ) ; V_107 ++ ) {
if ( error -> V_1 [ V_107 ] . V_147 != error -> V_145 [ V_32 ] )
continue;
V_19 += F_40 ( V_24 + V_19 , sizeof( V_24 ) , L_88 ,
V_146 ? L_6 : L_89 ,
V_102 -> V_1 [ V_107 ] . V_29 ) ;
V_146 = 0 ;
}
F_40 ( V_24 + V_19 , sizeof( V_24 ) , L_90 ) ;
F_12 ( V_28 , V_24 ,
error -> V_148 [ V_32 ] ,
error -> V_149 [ V_32 ] ) ;
}
F_12 ( V_28 , L_91 ,
error -> V_150 ,
error -> V_151 ) ;
for ( V_32 = 0 ; V_32 < F_32 ( error -> V_1 ) ; V_32 ++ ) {
struct V_51 * V_52 = & error -> V_1 [ V_32 ] ;
V_88 = V_52 -> V_64 ;
if ( V_88 ) {
F_16 ( V_28 , V_102 -> V_1 [ V_32 ] . V_29 ) ;
if ( V_52 -> V_115 != - 1 )
F_13 ( V_28 , L_92 ,
V_52 -> V_116 ,
V_52 -> V_115 ) ;
F_13 ( V_28 , L_93 ,
F_14 ( V_88 -> V_33 ) ,
F_15 ( V_88 -> V_33 ) ) ;
F_25 ( V_28 , V_88 ) ;
}
V_88 = V_52 -> V_152 ;
if ( V_88 ) {
F_13 ( V_28 , L_94 ,
V_102 -> V_1 [ V_32 ] . V_29 ,
F_15 ( V_88 -> V_33 ) ) ;
F_25 ( V_28 , V_88 ) ;
}
if ( V_52 -> V_153 ) {
F_13 ( V_28 , L_95 ,
V_102 -> V_1 [ V_32 ] . V_29 ,
V_52 -> V_153 ) ;
for ( V_107 = 0 ; V_107 < V_52 -> V_153 ; V_107 ++ ) {
F_13 ( V_28 , L_96 ,
V_52 -> V_154 [ V_107 ] . V_115 ,
V_52 -> V_154 [ V_107 ] . V_80 ,
V_52 -> V_154 [ V_107 ] . V_155 ,
V_52 -> V_154 [ V_107 ] . V_54 ,
V_52 -> V_154 [ V_107 ] . V_55 ) ;
}
}
if ( F_41 ( V_52 -> V_156 ) ) {
F_13 ( V_28 , L_97 ,
V_102 -> V_1 [ V_32 ] . V_29 ) ;
} else if ( V_52 -> V_157 ) {
F_13 ( V_28 , L_98 ,
V_102 -> V_1 [ V_32 ] . V_29 ,
V_52 -> V_157 ) ;
for ( V_107 = 0 ; V_107 < V_52 -> V_157 ; V_107 ++ ) {
F_13 ( V_28 , L_99 ,
V_52 -> V_156 [ V_107 ] . V_80 ,
V_52 -> V_156 [ V_107 ] . V_116 ,
V_52 -> V_156 [ V_107 ] . V_115 ) ;
}
}
if ( ( V_88 = V_52 -> V_158 ) ) {
F_13 ( V_28 , L_100 ,
V_102 -> V_1 [ V_32 ] . V_29 ,
F_15 ( V_88 -> V_33 ) ) ;
F_25 ( V_28 , V_88 ) ;
}
if ( ( V_88 = V_52 -> V_159 ) ) {
T_3 V_160 = V_88 -> V_33 ;
V_59 * V_159 = & V_88 -> V_94 [ 0 ] [ 0 ] ;
if ( V_40 . V_161 ) {
V_160 += V_162 * V_93 ;
V_159 = & V_88 -> V_94 [ V_162 ] [ 0 ] ;
}
F_13 ( V_28 , L_101 ,
V_102 -> V_1 [ V_32 ] . V_29 , V_160 ) ;
V_90 = 0 ;
for ( V_91 = 0 ; V_91 < V_93 / 16 ; V_91 += 4 ) {
F_13 ( V_28 , L_102 ,
V_90 ,
V_159 [ V_91 ] ,
V_159 [ V_91 + 1 ] ,
V_159 [ V_91 + 2 ] ,
V_159 [ V_91 + 3 ] ) ;
V_90 += 16 ;
}
}
V_88 = V_52 -> V_163 ;
if ( V_88 ) {
T_3 V_164 = V_88 -> V_33 ;
V_59 * V_165 = & V_88 -> V_94 [ 0 ] [ 0 ] ;
struct V_166 * V_1 = & V_102 -> V_1 [ V_2 ] ;
V_59 V_167 = ( V_1 -> V_163 . V_168 . V_17 +
V_1 -> V_163 . V_169 . V_17 ) ;
F_13 ( V_28 , L_103 ,
V_102 -> V_1 [ V_32 ] . V_29 , V_164 ) ;
V_90 = 0 ;
for ( V_91 = 0 ; V_91 < V_167 ; V_91 += 4 ) {
F_13 ( V_28 , L_102 ,
V_90 ,
V_165 [ V_91 + 0 ] ,
V_165 [ V_91 + 1 ] ,
V_165 [ V_91 + 2 ] ,
V_165 [ V_91 + 3 ] ) ;
V_90 += 16 ;
}
}
if ( ( V_88 = V_52 -> V_170 ) ) {
F_13 ( V_28 , L_104 ,
V_102 -> V_1 [ V_32 ] . V_29 ,
F_15 ( V_88 -> V_33 ) ) ;
F_25 ( V_28 , V_88 ) ;
}
}
if ( ( V_88 = error -> V_171 ) ) {
F_13 ( V_28 , L_105 ,
F_15 ( V_88 -> V_33 ) ) ;
for ( V_91 = 0 ; V_91 < V_93 / 16 ; V_91 += 4 ) {
F_13 ( V_28 , L_102 ,
V_91 * 4 ,
V_88 -> V_94 [ 0 ] [ V_91 ] ,
V_88 -> V_94 [ 0 ] [ V_91 + 1 ] ,
V_88 -> V_94 [ 0 ] [ V_91 + 2 ] ,
V_88 -> V_94 [ 0 ] [ V_91 + 3 ] ) ;
}
}
if ( error -> V_172 )
F_42 ( V_28 , error -> V_172 ) ;
if ( error -> V_173 )
F_43 ( V_28 , V_100 , error -> V_173 ) ;
V_109:
if ( V_28 -> V_16 == 0 && V_28 -> V_15 )
return V_28 -> V_15 ;
return 0 ;
}
int F_44 ( struct V_13 * V_174 ,
struct V_101 * V_40 ,
T_1 V_31 , T_5 V_20 )
{
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
V_174 -> V_40 = V_40 ;
V_174 -> V_17 = V_31 + 1 > V_93 ? V_31 + 1 : V_93 ;
V_174 -> V_24 = F_45 ( V_174 -> V_17 ,
V_175 | V_176 | V_177 ) ;
if ( V_174 -> V_24 == NULL ) {
V_174 -> V_17 = V_93 ;
V_174 -> V_24 = F_45 ( V_174 -> V_17 , V_175 ) ;
}
if ( V_174 -> V_24 == NULL ) {
V_174 -> V_17 = 128 ;
V_174 -> V_24 = F_45 ( V_174 -> V_17 , V_175 ) ;
}
if ( V_174 -> V_24 == NULL )
return - V_178 ;
V_174 -> V_21 = V_20 ;
return 0 ;
}
static void F_46 ( struct V_87 * V_88 )
{
int V_89 ;
if ( V_88 == NULL )
return;
for ( V_89 = 0 ; V_89 < V_88 -> V_92 ; V_89 ++ )
F_47 ( V_88 -> V_94 [ V_89 ] ) ;
F_47 ( V_88 ) ;
}
static void F_48 ( struct V_179 * V_180 )
{
struct V_106 * error = F_49 ( V_180 ,
F_50 ( * error ) , V_181 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_32 ( error -> V_1 ) ; V_32 ++ ) {
struct V_51 * V_52 = & error -> V_1 [ V_32 ] ;
F_46 ( V_52 -> V_64 ) ;
F_46 ( V_52 -> V_152 ) ;
F_46 ( V_52 -> V_158 ) ;
F_46 ( V_52 -> V_159 ) ;
F_46 ( V_52 -> V_170 ) ;
F_46 ( V_52 -> V_163 ) ;
F_47 ( V_52 -> V_154 ) ;
if ( ! F_51 ( V_52 -> V_156 ) )
F_47 ( V_52 -> V_156 ) ;
}
F_46 ( error -> V_171 ) ;
for ( V_32 = 0 ; V_32 < F_32 ( error -> V_148 ) ; V_32 ++ )
F_47 ( error -> V_148 [ V_32 ] ) ;
F_47 ( error -> V_150 ) ;
F_47 ( error -> V_172 ) ;
F_47 ( error -> V_173 ) ;
F_47 ( error ) ;
}
static struct V_87 *
F_52 ( struct V_101 * V_102 ,
struct V_182 * V_183 )
{
struct V_184 * V_185 = & V_102 -> V_185 ;
struct V_186 * V_187 ;
struct V_87 * V_188 ;
int V_189 ;
bool V_190 ;
int V_32 = 0 ;
T_3 V_191 ;
if ( ! V_183 )
return NULL ;
V_187 = V_183 -> V_88 ;
if ( ! V_187 -> V_94 )
return NULL ;
V_189 = V_187 -> V_192 . V_17 >> V_193 ;
V_188 = F_45 ( sizeof( * V_188 ) + V_189 * sizeof( V_59 * ) , V_194 ) ;
if ( ! V_188 )
return NULL ;
V_188 -> V_33 = V_183 -> V_195 . V_21 ;
V_188 -> V_66 = V_183 -> V_195 . V_17 ;
V_191 = V_188 -> V_33 ;
V_190 = ( V_187 -> V_41 == V_196 &&
( V_183 -> V_197 & V_198 ) &&
V_191 + V_189 * V_93 <= V_185 -> V_199 ) ;
if ( V_187 -> V_200 ) {
V_190 = true ;
if ( ! ( V_183 -> V_197 & V_198 ) )
goto V_201;
V_191 = V_183 -> V_195 . V_21 ;
if ( V_191 + V_189 * V_93 > V_185 -> V_199 )
goto V_201;
}
if ( V_190 && V_187 -> V_41 != V_196 &&
! F_53 ( V_102 ) )
goto V_201;
V_188 -> V_92 = V_189 ;
while ( V_189 -- ) {
unsigned long V_197 ;
void * V_202 ;
V_202 = F_45 ( V_93 , V_194 ) ;
if ( V_202 == NULL )
goto V_201;
F_54 ( V_197 ) ;
if ( V_190 ) {
void T_6 * V_203 ;
V_203 = F_55 ( & V_185 -> V_204 ,
V_191 ) ;
F_56 ( V_202 , V_203 , V_93 ) ;
F_57 ( V_203 ) ;
} else {
struct V_89 * V_89 ;
void * V_203 ;
V_89 = F_58 ( V_187 , V_32 ) ;
F_59 ( & V_89 , 1 ) ;
V_203 = F_60 ( V_89 ) ;
memcpy ( V_202 , V_203 , V_93 ) ;
F_61 ( V_203 ) ;
F_59 ( & V_89 , 1 ) ;
}
F_62 ( V_197 ) ;
V_188 -> V_94 [ V_32 ++ ] = V_202 ;
V_191 += V_93 ;
}
return V_188 ;
V_201:
while ( V_32 -- )
F_47 ( V_188 -> V_94 [ V_32 ] ) ;
F_47 ( V_188 ) ;
return NULL ;
}
static inline T_7
F_63 ( struct V_205 * V_206 )
{
return F_64 ( F_65 ( V_206 ) ) ;
}
static inline int
F_66 ( struct V_205 * V_206 )
{
struct V_166 * V_1 ;
V_1 = F_67 ( F_65 ( V_206 ) ) ;
return V_1 ? V_1 -> V_207 : - 1 ;
}
static void F_68 ( struct V_30 * V_15 ,
struct V_182 * V_183 )
{
struct V_186 * V_88 = V_183 -> V_88 ;
int V_32 ;
V_15 -> V_17 = V_88 -> V_192 . V_17 ;
V_15 -> V_29 = V_88 -> V_192 . V_29 ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ )
V_15 -> V_37 [ V_32 ] = F_63 ( & V_88 -> V_208 [ V_32 ] ) ;
V_15 -> V_38 = F_63 ( & V_88 -> V_209 ) ;
V_15 -> V_1 = F_66 ( & V_88 -> V_209 ) ;
V_15 -> V_33 = V_183 -> V_195 . V_21 ;
V_15 -> V_34 = V_88 -> V_192 . V_34 ;
V_15 -> V_35 = V_88 -> V_192 . V_35 ;
V_15 -> V_42 = V_183 -> V_139 ? V_183 -> V_139 -> V_207 : - 1 ;
V_15 -> V_7 = F_69 ( V_88 ) ;
V_15 -> V_11 = V_88 -> V_11 ;
V_15 -> V_12 = V_88 -> V_210 != V_211 ;
V_15 -> V_39 = V_88 -> V_39 . V_212 != NULL ;
V_15 -> V_41 = V_88 -> V_41 ;
}
static V_59 F_70 ( struct V_30 * V_15 ,
int V_31 , struct V_213 * V_54 ,
bool V_214 )
{
struct V_182 * V_183 ;
int V_32 = 0 ;
F_71 (vma, head, vm_link) {
if ( V_214 && ! F_72 ( V_183 ) )
continue;
F_68 ( V_15 ++ , V_183 ) ;
if ( ++ V_32 == V_31 )
break;
}
return V_32 ;
}
static T_7 F_73 ( struct V_101 * V_102 ,
struct V_106 * error ,
int * V_53 )
{
T_7 V_215 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ ) {
if ( error -> V_1 [ V_32 ] . V_85 == V_50 ) {
if ( V_53 )
* V_53 = V_32 ;
return error -> V_1 [ V_32 ] . V_62 ^ error -> V_1 [ V_32 ] . V_63 ;
}
}
return V_215 ;
}
static void F_74 ( struct V_101 * V_102 ,
struct V_106 * error )
{
int V_32 ;
if ( F_75 ( V_102 ) || F_76 ( V_102 ) ) {
for ( V_32 = 0 ; V_32 < V_102 -> V_138 ; V_32 ++ )
error -> V_139 [ V_32 ] = F_77 ( F_78 ( V_32 ) ) ;
} else if ( F_79 ( V_102 ) || F_80 ( V_102 ) ) {
for ( V_32 = 0 ; V_32 < V_102 -> V_138 ; V_32 ++ )
error -> V_139 [ V_32 ] = F_81 ( F_82 ( V_32 ) ) ;
} else if ( F_20 ( V_102 ) >= 6 ) {
for ( V_32 = 0 ; V_32 < V_102 -> V_138 ; V_32 ++ )
error -> V_139 [ V_32 ] = F_81 ( F_83 ( V_32 ) ) ;
}
}
static void F_84 ( struct V_106 * error ,
struct V_166 * V_1 ,
struct V_51 * V_52 )
{
struct V_101 * V_102 = V_1 -> V_40 ;
struct V_166 * V_216 ;
enum V_217 V_207 ;
if ( ! error -> V_171 )
return;
F_85 (to, dev_priv, id) {
int V_218 ;
T_8 V_219 ;
V_59 * V_26 ;
if ( V_1 == V_216 )
continue;
V_219 =
( F_86 ( V_1 , V_207 ) & ( V_93 - 1 ) ) / 4 ;
V_26 = error -> V_171 -> V_94 [ 0 ] ;
V_218 = F_87 ( V_1 , V_216 ) ;
V_52 -> V_74 [ V_218 ] = V_26 [ V_219 ] ;
V_52 -> V_75 [ V_218 ] = V_1 -> V_171 . V_220 [ V_218 ] ;
}
}
static void F_88 ( struct V_166 * V_1 ,
struct V_51 * V_52 )
{
struct V_101 * V_102 = V_1 -> V_40 ;
V_52 -> V_74 [ 0 ] = F_77 ( F_89 ( V_1 -> V_221 ) ) ;
V_52 -> V_74 [ 1 ] = F_77 ( F_90 ( V_1 -> V_221 ) ) ;
V_52 -> V_75 [ 0 ] = V_1 -> V_171 . V_220 [ 0 ] ;
V_52 -> V_75 [ 1 ] = V_1 -> V_171 . V_220 [ 1 ] ;
if ( F_21 ( V_102 ) ) {
V_52 -> V_74 [ 2 ] =
F_77 ( F_91 ( V_1 -> V_221 ) ) ;
V_52 -> V_75 [ 2 ] = V_1 -> V_171 . V_220 [ 2 ] ;
}
}
static void F_92 ( struct V_166 * V_1 ,
struct V_51 * V_52 )
{
struct V_222 * V_223 = & V_1 -> V_224 ;
struct V_225 * V_226 ;
struct V_227 * V_228 ;
int V_31 ;
V_52 -> V_157 = 0 ;
V_52 -> V_156 = NULL ;
if ( F_93 ( & V_223 -> V_156 ) )
return;
if ( ! F_94 ( & V_223 -> V_229 ) ) {
V_52 -> V_156 = F_95 ( - V_230 ) ;
return;
}
V_31 = 0 ;
for ( V_228 = F_96 ( & V_223 -> V_156 ) ; V_228 != NULL ; V_228 = F_97 ( V_228 ) )
V_31 ++ ;
F_98 ( & V_223 -> V_229 ) ;
V_226 = NULL ;
if ( V_31 )
V_226 = F_99 ( V_31 ,
sizeof( struct V_225 ) ,
V_194 ) ;
if ( ! V_226 )
return;
if ( ! F_94 ( & V_223 -> V_229 ) ) {
F_47 ( V_226 ) ;
V_52 -> V_156 = F_95 ( - V_230 ) ;
return;
}
V_52 -> V_156 = V_226 ;
for ( V_228 = F_96 ( & V_223 -> V_156 ) ; V_228 ; V_228 = F_97 ( V_228 ) ) {
struct V_231 * V_232 = F_49 ( V_228 , F_50 ( * V_232 ) , V_195 ) ;
strcpy ( V_226 -> V_116 , V_232 -> V_233 -> V_116 ) ;
V_226 -> V_115 = V_232 -> V_233 -> V_115 ;
V_226 -> V_80 = V_232 -> V_80 ;
V_226 ++ ;
if ( ++ V_52 -> V_157 == V_31 )
break;
}
F_98 ( & V_223 -> V_229 ) ;
}
static void F_100 ( struct V_106 * error ,
struct V_166 * V_1 ,
struct V_51 * V_52 )
{
struct V_101 * V_102 = V_1 -> V_40 ;
if ( F_20 ( V_102 ) >= 6 ) {
V_52 -> V_72 = F_77 ( F_101 ( V_1 -> V_221 ) ) ;
V_52 -> V_73 = F_77 ( F_102 ( V_1 ) ) ;
if ( F_20 ( V_102 ) >= 8 )
F_84 ( error , V_1 , V_52 ) ;
else
F_88 ( V_1 , V_52 ) ;
}
if ( F_20 ( V_102 ) >= 4 ) {
V_52 -> V_71 = F_77 ( F_103 ( V_1 -> V_221 ) ) ;
V_52 -> V_61 = F_77 ( F_104 ( V_1 -> V_221 ) ) ;
V_52 -> V_62 = F_77 ( F_105 ( V_1 -> V_221 ) ) ;
V_52 -> V_63 = F_77 ( F_106 ( V_1 -> V_221 ) ) ;
V_52 -> V_69 = F_77 ( F_107 ( V_1 -> V_221 ) ) ;
V_52 -> V_67 = F_77 ( F_108 ( V_1 -> V_221 ) ) ;
if ( F_20 ( V_102 ) >= 8 ) {
V_52 -> V_71 |= ( T_3 ) F_77 ( F_109 ( V_1 -> V_221 ) ) << 32 ;
V_52 -> V_67 |= ( T_3 ) F_77 ( F_110 ( V_1 -> V_221 ) ) << 32 ;
}
V_52 -> V_68 = F_77 ( F_111 ( V_1 -> V_221 ) ) ;
} else {
V_52 -> V_71 = F_77 ( V_234 ) ;
V_52 -> V_61 = F_77 ( V_235 ) ;
V_52 -> V_62 = F_77 ( V_236 ) ;
V_52 -> V_63 = F_77 ( V_237 ) ;
}
V_52 -> V_82 = F_112 ( V_1 ) ;
V_52 -> V_70 = F_77 ( F_113 ( V_1 -> V_221 ) ) ;
V_52 -> V_60 = F_114 ( V_1 ) ;
V_52 -> V_80 = F_115 ( V_1 ) ;
V_52 -> V_81 = V_1 -> V_238 ;
V_52 -> V_21 = F_116 ( V_1 ) ;
V_52 -> V_54 = F_117 ( V_1 ) ;
V_52 -> V_55 = F_118 ( V_1 ) ;
V_52 -> V_56 = F_119 ( V_1 ) ;
if ( F_20 ( V_102 ) > 2 )
V_52 -> V_57 = F_120 ( V_1 ) ;
if ( ! F_121 ( V_102 ) ) {
T_9 V_239 ;
if ( F_39 ( V_102 ) ) {
switch ( V_1 -> V_207 ) {
default:
case V_2 :
V_239 = V_240 ;
break;
case V_4 :
V_239 = V_241 ;
break;
case V_3 :
V_239 = V_242 ;
break;
case V_5 :
V_239 = V_243 ;
break;
}
} else if ( F_122 ( V_1 -> V_40 ) ) {
V_239 = F_123 ( V_1 -> V_221 ) ;
} else {
V_239 = F_124 ( V_1 -> V_221 ) ;
}
V_52 -> V_58 = F_77 ( V_239 ) ;
}
V_52 -> V_86 = V_1 -> V_244 . V_245 ;
V_52 -> V_85 = V_1 -> V_244 . V_246 ;
if ( F_22 ( V_102 ) ) {
int V_32 ;
V_52 -> V_76 . V_77 = F_77 ( F_125 ( V_1 ) ) ;
if ( F_122 ( V_102 ) )
V_52 -> V_76 . V_79 =
F_77 ( F_126 ( V_1 ) ) ;
else if ( F_39 ( V_102 ) )
V_52 -> V_76 . V_79 =
F_77 ( F_127 ( V_1 ) ) ;
else if ( F_20 ( V_102 ) >= 8 )
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
V_52 -> V_76 . V_78 [ V_32 ] =
F_77 ( F_128 ( V_1 , V_32 ) ) ;
V_52 -> V_76 . V_78 [ V_32 ] <<= 32 ;
V_52 -> V_76 . V_78 [ V_32 ] |=
F_77 ( F_129 ( V_1 , V_32 ) ) ;
}
}
}
static void F_130 ( struct V_166 * V_1 ,
struct V_247 * V_146 ,
struct V_51 * V_52 )
{
struct V_247 * V_248 ;
int V_31 ;
V_31 = 0 ;
V_248 = V_146 ;
F_131 (request, &engine->request_list, link)
V_31 ++ ;
if ( ! V_31 )
return;
V_52 -> V_154 = F_132 ( V_31 , sizeof( * V_52 -> V_154 ) , V_194 ) ;
if ( ! V_52 -> V_154 )
return;
V_52 -> V_153 = V_31 ;
V_31 = 0 ;
V_248 = V_146 ;
F_131 (request, &engine->request_list, link) {
struct V_249 * V_250 ;
if ( V_31 >= V_52 -> V_153 ) {
break;
}
V_250 = & V_52 -> V_154 [ V_31 ++ ] ;
V_250 -> V_80 = V_248 -> V_139 . V_80 ;
V_250 -> V_155 = V_248 -> V_251 ;
V_250 -> V_54 = V_248 -> V_54 ;
V_250 -> V_55 = V_248 -> V_55 ;
F_133 () ;
V_250 -> V_115 = V_248 -> V_170 -> V_115 ? F_134 ( V_248 -> V_170 -> V_115 ) : 0 ;
F_135 () ;
}
V_52 -> V_153 = V_31 ;
}
static void F_136 ( struct V_101 * V_102 ,
struct V_106 * error )
{
struct V_184 * V_185 = & V_102 -> V_185 ;
int V_32 ;
error -> V_171 =
F_52 ( V_102 , V_102 -> V_171 ) ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ ) {
struct V_166 * V_1 = & V_102 -> V_1 [ V_32 ] ;
struct V_51 * V_52 = & error -> V_1 [ V_32 ] ;
struct V_247 * V_248 ;
V_52 -> V_115 = - 1 ;
V_52 -> V_53 = - 1 ;
if ( ! F_137 ( V_1 ) )
continue;
V_52 -> V_53 = V_32 ;
F_100 ( error , V_1 , V_52 ) ;
F_92 ( V_1 , V_52 ) ;
V_248 = F_138 ( V_1 ) ;
if ( V_248 ) {
struct V_252 * V_253 ;
struct V_115 * V_115 ;
V_52 -> V_147 = V_248 -> V_170 -> V_254 ?
& V_248 -> V_170 -> V_254 -> V_192 : & V_185 -> V_192 ;
V_52 -> V_64 =
F_52 ( V_102 ,
V_248 -> V_255 ) ;
if ( F_139 ( V_102 ) )
V_52 -> V_152 =
F_52 ( V_102 ,
V_1 -> V_256 ) ;
V_52 -> V_170 =
F_52 ( V_102 ,
V_248 -> V_170 -> V_1 [ V_32 ] . V_257 ) ;
V_115 = V_248 -> V_170 -> V_115 ;
if ( V_115 ) {
struct V_258 * V_259 ;
F_133 () ;
V_259 = F_140 ( V_115 , V_260 ) ;
if ( V_259 ) {
strcpy ( V_52 -> V_116 , V_259 -> V_116 ) ;
V_52 -> V_115 = V_259 -> V_115 ;
}
F_135 () ;
}
error -> V_261 |=
V_248 -> V_170 -> V_197 & V_262 ;
V_253 = V_248 -> V_253 ;
V_52 -> V_83 = V_253 -> V_54 ;
V_52 -> V_84 = V_253 -> V_55 ;
V_52 -> V_158 =
F_52 ( V_102 , V_253 -> V_183 ) ;
F_130 ( V_1 , V_248 , V_52 ) ;
}
V_52 -> V_159 =
F_52 ( V_102 ,
V_1 -> V_263 . V_183 ) ;
V_52 -> V_163 =
F_52 ( V_102 , V_1 -> V_163 . V_183 ) ;
}
}
static void F_141 ( struct V_101 * V_102 ,
struct V_106 * error ,
struct V_264 * V_147 ,
int V_218 )
{
struct V_30 * V_148 ;
struct V_182 * V_183 ;
int V_31 ;
V_31 = 0 ;
F_71 (vma, &vm->active_list, vm_link)
V_31 ++ ;
V_148 = NULL ;
if ( V_31 )
V_148 = F_132 ( V_31 , sizeof( * V_148 ) , V_194 ) ;
if ( V_148 )
V_31 = F_70 ( V_148 , V_31 , & V_147 -> V_265 , false ) ;
else
V_31 = 0 ;
error -> V_145 [ V_218 ] = V_147 ;
error -> V_148 [ V_218 ] = V_148 ;
error -> V_149 [ V_218 ] = V_31 ;
}
static void F_142 ( struct V_101 * V_102 ,
struct V_106 * error )
{
int V_266 = 0 , V_32 , V_107 ;
F_143 ( F_32 ( error -> V_1 ) > F_32 ( error -> V_148 ) ) ;
F_143 ( F_32 ( error -> V_148 ) != F_32 ( error -> V_145 ) ) ;
F_143 ( F_32 ( error -> V_148 ) != F_32 ( error -> V_149 ) ) ;
for ( V_32 = 0 ; V_32 < F_32 ( error -> V_1 ) ; V_32 ++ ) {
struct V_51 * V_52 = & error -> V_1 [ V_32 ] ;
bool V_267 ;
if ( ! V_52 -> V_147 )
continue;
V_267 = false ;
for ( V_107 = 0 ; V_107 < V_32 && ! V_267 ; V_107 ++ )
V_267 = error -> V_1 [ V_107 ] . V_147 == V_52 -> V_147 ;
if ( ! V_267 )
F_141 ( V_102 , error , V_52 -> V_147 , V_266 ++ ) ;
}
}
static void F_144 ( struct V_101 * V_102 ,
struct V_106 * error )
{
struct V_264 * V_147 = & V_102 -> V_185 . V_192 ;
struct V_30 * V_268 ;
struct V_182 * V_183 ;
int V_269 , V_270 ;
V_269 = 0 ;
F_71 (vma, &vm->active_list, vm_link)
V_269 ++ ;
V_270 = 0 ;
F_71 (vma, &vm->inactive_list, vm_link)
V_270 ++ ;
V_268 = NULL ;
if ( V_269 + V_270 )
V_268 = F_132 ( V_269 + V_270 ,
sizeof( * V_268 ) , V_194 ) ;
if ( ! V_268 )
return;
V_269 = F_70 ( V_268 , V_269 ,
& V_147 -> V_265 , true ) ;
V_270 = F_70 ( V_268 + V_269 , V_270 ,
& V_147 -> V_271 , true ) ;
error -> V_151 = V_269 + V_270 ;
error -> V_150 = V_268 ;
}
static void F_145 ( struct V_101 * V_102 ,
struct V_106 * error )
{
struct V_99 * V_100 = & V_102 -> V_105 ;
int V_32 ;
if ( F_38 ( V_100 ) ) {
error -> V_131 [ 0 ] = F_77 ( V_272 ) ;
error -> V_129 = F_77 ( V_273 ) ;
error -> V_133 = F_146 ( V_274 ) ;
}
if ( F_39 ( V_100 ) )
error -> V_144 = F_77 ( V_275 ) ;
if ( F_36 ( V_100 ) -> V_130 >= 8 ) {
error -> V_142 = F_77 ( V_276 ) ;
error -> V_141 = F_77 ( V_277 ) ;
}
if ( F_122 ( V_100 ) ) {
error -> V_133 = F_146 ( V_278 ) ;
error -> V_279 = F_77 ( V_280 ) ;
error -> V_77 = F_77 ( V_281 ) ;
}
if ( F_36 ( V_100 ) -> V_130 >= 7 )
error -> V_133 = F_146 ( V_282 ) ;
if ( F_36 ( V_100 ) -> V_130 >= 6 ) {
error -> V_134 = F_77 ( V_283 ) ;
error -> error = F_77 ( V_284 ) ;
error -> V_143 = F_77 ( V_285 ) ;
}
if ( F_122 ( V_100 ) || F_39 ( V_100 ) ) {
error -> V_286 = F_77 ( V_287 ) ;
error -> V_288 = F_77 ( V_289 ) ;
}
if ( F_147 ( V_100 ) )
error -> V_135 = F_77 ( V_290 ) ;
if ( F_36 ( V_100 ) -> V_130 >= 8 ) {
error -> V_129 = F_77 ( V_291 ) ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
error -> V_131 [ V_32 ] = F_77 ( F_148 ( V_32 ) ) ;
} else if ( F_37 ( V_100 ) ) {
error -> V_129 = F_77 ( V_292 ) ;
error -> V_131 [ 0 ] = F_77 ( V_272 ) ;
} else if ( F_76 ( V_100 ) ) {
error -> V_129 = F_149 ( V_293 ) ;
} else if ( ! F_38 ( V_100 ) ) {
error -> V_129 = F_77 ( V_293 ) ;
}
error -> V_128 = F_77 ( V_294 ) ;
error -> V_132 = F_77 ( V_295 ) ;
F_150 ( V_102 , error -> V_140 ) ;
}
static void F_151 ( struct V_101 * V_102 ,
struct V_106 * error ,
V_59 V_296 ,
const char * V_110 )
{
V_59 V_297 ;
int V_53 = - 1 , V_19 ;
V_297 = F_73 ( V_102 , error , & V_53 ) ;
V_19 = F_40 ( error -> V_110 , sizeof( error -> V_110 ) ,
L_106 ,
F_20 ( V_102 ) , V_53 , V_297 ) ;
if ( V_53 != - 1 && error -> V_1 [ V_53 ] . V_115 != - 1 )
V_19 += F_40 ( error -> V_110 + V_19 ,
sizeof( error -> V_110 ) - V_19 ,
L_107 ,
error -> V_1 [ V_53 ] . V_116 ,
error -> V_1 [ V_53 ] . V_115 ) ;
F_40 ( error -> V_110 + V_19 , sizeof( error -> V_110 ) - V_19 ,
L_108 ,
V_110 ,
V_296 ? L_109 : L_110 ) ;
}
static void F_152 ( struct V_101 * V_102 ,
struct V_106 * error )
{
error -> V_123 = - 1 ;
#ifdef F_153
error -> V_123 = V_298 ;
#endif
error -> V_117 = F_154 ( & V_102 -> V_136 ) ;
error -> V_118 = V_102 -> V_118 ;
memcpy ( & error -> V_114 ,
F_36 ( V_102 ) ,
sizeof( error -> V_114 ) ) ;
}
void F_155 ( struct V_101 * V_102 ,
V_59 V_296 ,
const char * V_110 )
{
static bool V_299 ;
struct V_106 * error ;
unsigned long V_197 ;
if ( F_156 ( V_102 -> V_136 . V_300 ) )
return;
error = F_157 ( sizeof( * error ) , V_194 ) ;
if ( ! error ) {
F_158 ( L_111 ) ;
return;
}
F_159 ( & error -> V_181 ) ;
F_152 ( V_102 , error ) ;
F_145 ( V_102 , error ) ;
F_74 ( V_102 , error ) ;
F_136 ( V_102 , error ) ;
F_142 ( V_102 , error ) ;
F_144 ( V_102 , error ) ;
F_160 ( & error -> time ) ;
error -> V_172 = F_161 ( V_102 ) ;
error -> V_173 = F_162 ( V_102 ) ;
F_151 ( V_102 , error , V_296 , V_110 ) ;
F_163 ( L_60 , error -> V_110 ) ;
if ( ! error -> V_261 ) {
F_164 ( & V_102 -> V_136 . V_229 , V_197 ) ;
if ( ! V_102 -> V_136 . V_300 ) {
V_102 -> V_136 . V_300 = error ;
error = NULL ;
}
F_165 ( & V_102 -> V_136 . V_229 , V_197 ) ;
}
if ( error ) {
F_48 ( & error -> V_181 ) ;
return;
}
if ( ! V_299 ) {
F_163 ( L_112 ) ;
F_163 ( L_113 ) ;
F_163 ( L_114 ) ;
F_163 ( L_115 ) ;
F_163 ( L_116 ,
V_102 -> V_105 . V_301 -> V_302 ) ;
V_299 = true ;
}
}
void F_166 ( struct V_99 * V_100 ,
struct V_97 * V_98 )
{
struct V_101 * V_102 = F_31 ( V_100 ) ;
F_167 ( & V_102 -> V_136 . V_229 ) ;
V_98 -> error = V_102 -> V_136 . V_300 ;
if ( V_98 -> error )
F_168 ( & V_98 -> error -> V_181 ) ;
F_169 ( & V_102 -> V_136 . V_229 ) ;
}
void F_170 ( struct V_97 * V_98 )
{
if ( V_98 -> error )
F_171 ( & V_98 -> error -> V_181 , F_48 ) ;
}
void F_172 ( struct V_99 * V_100 )
{
struct V_101 * V_102 = F_31 ( V_100 ) ;
struct V_106 * error ;
F_167 ( & V_102 -> V_136 . V_229 ) ;
error = V_102 -> V_136 . V_300 ;
V_102 -> V_136 . V_300 = NULL ;
F_169 ( & V_102 -> V_136 . V_229 ) ;
if ( error )
F_171 ( & error -> V_181 , F_48 ) ;
}
const char * F_17 ( struct V_101 * V_40 , int type )
{
switch ( type ) {
case V_196 : return L_117 ;
case V_303 : return F_53 ( V_40 ) ? L_118 : L_119 ;
case V_304 : return L_120 ;
case V_305 : return L_121 ;
default: return L_6 ;
}
}
void F_150 ( struct V_101 * V_102 ,
T_7 * V_63 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) * V_306 ) ;
if ( F_76 ( V_102 ) || F_75 ( V_102 ) )
V_63 [ 0 ] = F_77 ( V_237 ) ;
else if ( F_80 ( V_102 ) || F_79 ( V_102 ) || F_122 ( V_102 ) ) {
V_63 [ 0 ] = F_77 ( F_106 ( V_307 ) ) ;
V_63 [ 1 ] = F_77 ( V_308 ) ;
} else if ( F_20 ( V_102 ) >= 7 ) {
V_63 [ 0 ] = F_77 ( F_106 ( V_307 ) ) ;
V_63 [ 1 ] = F_77 ( V_309 ) ;
V_63 [ 2 ] = F_77 ( V_310 ) ;
V_63 [ 3 ] = F_77 ( V_311 ) ;
}
}
