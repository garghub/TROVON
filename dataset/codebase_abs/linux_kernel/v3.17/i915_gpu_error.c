static const char * F_1 ( int V_1 )
{
return V_1 ? L_1 : L_2 ;
}
static const char * F_2 ( int V_2 )
{
switch ( V_2 ) {
case V_3 : return L_3 ;
case V_4 : return L_4 ;
case V_5 : return L_5 ;
case V_6 : return L_6 ;
case V_7 : return L_7 ;
default: return L_8 ;
}
}
static const char * F_3 ( int V_8 )
{
if ( V_8 > 0 )
return L_9 ;
else if ( V_8 < 0 )
return L_10 ;
else
return L_8 ;
}
static const char * F_4 ( int V_9 )
{
switch ( V_9 ) {
default:
case V_10 : return L_8 ;
case V_11 : return L_11 ;
case V_12 : return L_12 ;
}
}
static const char * F_5 ( int V_13 )
{
return V_13 ? L_13 : L_8 ;
}
static const char * F_6 ( int V_14 )
{
return V_14 ? L_14 : L_8 ;
}
static bool F_7 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_17 && F_8 ( V_16 -> V_18 > ( V_16 -> V_19 - 1 ) , L_15 ) ) {
V_16 -> V_17 = - V_20 ;
return false ;
}
if ( V_16 -> V_18 == V_16 -> V_19 - 1 || V_16 -> V_17 )
return false ;
return true ;
}
static bool F_9 ( struct V_15 * V_16 ,
unsigned V_21 )
{
if ( V_16 -> V_22 + V_21 <= V_16 -> V_23 ) {
V_16 -> V_22 += V_21 ;
return false ;
}
if ( V_21 >= V_16 -> V_19 ) {
V_16 -> V_17 = - V_24 ;
return false ;
}
return true ;
}
static void F_10 ( struct V_15 * V_16 ,
unsigned V_21 )
{
if ( V_16 -> V_22 < V_16 -> V_23 ) {
const T_1 V_25 = V_16 -> V_23 - V_16 -> V_22 ;
if ( V_25 > V_21 || V_16 -> V_18 ) {
V_16 -> V_17 = - V_24 ;
return;
}
memmove ( V_16 -> V_26 , V_16 -> V_26 + V_25 , V_21 - V_25 ) ;
V_16 -> V_18 = V_21 - V_25 ;
V_16 -> V_22 = V_16 -> V_23 ;
return;
}
V_16 -> V_18 += V_21 ;
V_16 -> V_22 += V_21 ;
}
static void F_11 ( struct V_15 * V_16 ,
const char * V_27 , T_2 args )
{
unsigned V_21 ;
if ( ! F_7 ( V_16 ) )
return;
if ( V_16 -> V_22 < V_16 -> V_23 ) {
T_2 V_28 ;
F_12 ( V_28 , args ) ;
V_21 = vsnprintf ( NULL , 0 , V_27 , V_28 ) ;
va_end ( V_28 ) ;
if ( ! F_9 ( V_16 , V_21 ) )
return;
}
V_21 = vsnprintf ( V_16 -> V_26 + V_16 -> V_18 , V_16 -> V_19 - V_16 -> V_18 , V_27 , args ) ;
if ( V_21 >= V_16 -> V_19 - V_16 -> V_18 )
V_21 = V_16 -> V_19 - V_16 -> V_18 - 1 ;
F_10 ( V_16 , V_21 ) ;
}
static void F_13 ( struct V_15 * V_16 ,
const char * V_29 )
{
unsigned V_21 ;
if ( ! F_7 ( V_16 ) )
return;
V_21 = strlen ( V_29 ) ;
if ( V_16 -> V_22 < V_16 -> V_23 ) {
if ( ! F_9 ( V_16 , V_21 ) )
return;
}
if ( V_21 >= V_16 -> V_19 - V_16 -> V_18 )
V_21 = V_16 -> V_19 - V_16 -> V_18 - 1 ;
memcpy ( V_16 -> V_26 + V_16 -> V_18 , V_29 , V_21 ) ;
F_10 ( V_16 , V_21 ) ;
}
static void F_14 ( struct V_15 * V_30 ,
const char * V_31 ,
struct V_32 * V_17 ,
int V_33 )
{
F_15 ( V_30 , L_16 , V_31 , V_33 ) ;
while ( V_33 -- ) {
F_15 ( V_30 , L_17 ,
V_17 -> V_34 ,
V_17 -> V_19 ,
V_17 -> V_35 ,
V_17 -> V_36 ,
V_17 -> V_37 , V_17 -> V_38 ) ;
F_16 ( V_30 , F_3 ( V_17 -> V_8 ) ) ;
F_16 ( V_30 , F_4 ( V_17 -> V_9 ) ) ;
F_16 ( V_30 , F_5 ( V_17 -> V_13 ) ) ;
F_16 ( V_30 , F_6 ( V_17 -> V_14 ) ) ;
F_16 ( V_30 , V_17 -> V_39 ? L_18 : L_8 ) ;
F_16 ( V_30 , V_17 -> V_2 != - 1 ? L_19 : L_8 ) ;
F_16 ( V_30 , F_2 ( V_17 -> V_2 ) ) ;
F_16 ( V_30 , F_17 ( V_17 -> V_40 ) ) ;
if ( V_17 -> V_31 )
F_15 ( V_30 , L_20 , V_17 -> V_31 ) ;
if ( V_17 -> V_41 != V_42 )
F_15 ( V_30 , L_21 , V_17 -> V_41 ) ;
F_16 ( V_30 , L_22 ) ;
V_17 ++ ;
}
}
static const char * F_18 ( enum V_43 V_44 )
{
switch ( V_44 ) {
case V_45 :
return L_23 ;
case V_46 :
return L_24 ;
case V_47 :
return L_25 ;
case V_48 :
return L_26 ;
case V_49 :
return L_27 ;
case V_50 :
return L_28 ;
}
return L_29 ;
}
static void F_19 ( struct V_15 * V_30 ,
struct V_51 * V_52 ,
struct V_53 * V_2 )
{
if ( ! V_2 -> V_54 )
return;
F_15 ( V_30 , L_30 , V_2 -> V_55 ) ;
F_15 ( V_30 , L_31 , V_2 -> V_56 ) ;
F_15 ( V_30 , L_32 , V_2 -> V_57 ) ;
F_15 ( V_30 , L_33 , V_2 -> V_58 ) ;
F_15 ( V_30 , L_34 , ( V_59 ) ( V_2 -> V_60 >> 32 ) , ( V_59 ) V_2 -> V_60 ) ;
F_15 ( V_30 , L_35 , V_2 -> V_61 ) ;
F_15 ( V_30 , L_36 , V_2 -> V_62 ) ;
F_15 ( V_30 , L_37 , V_2 -> V_63 ) ;
if ( F_20 ( V_52 ) -> V_64 >= 4 ) {
F_15 ( V_30 , L_38 , ( V_59 ) ( V_2 -> V_65 >> 32 ) , ( V_59 ) V_2 -> V_65 ) ;
F_15 ( V_30 , L_39 , V_2 -> V_66 ) ;
F_15 ( V_30 , L_40 , V_2 -> V_67 ) ;
}
F_15 ( V_30 , L_41 , V_2 -> V_68 ) ;
F_15 ( V_30 , L_42 , F_21 ( V_2 -> V_69 ) ,
F_22 ( V_2 -> V_69 ) ) ;
if ( F_20 ( V_52 ) -> V_64 >= 6 ) {
F_15 ( V_30 , L_43 , V_2 -> V_70 ) ;
F_15 ( V_30 , L_44 , V_2 -> V_71 ) ;
F_15 ( V_30 , L_45 ,
V_2 -> V_72 [ 0 ] ,
V_2 -> V_73 [ 0 ] ) ;
F_15 ( V_30 , L_46 ,
V_2 -> V_72 [ 1 ] ,
V_2 -> V_73 [ 1 ] ) ;
if ( F_23 ( V_52 ) ) {
F_15 ( V_30 , L_47 ,
V_2 -> V_72 [ 2 ] ,
V_2 -> V_73 [ 2 ] ) ;
}
}
if ( F_24 ( V_52 ) ) {
F_15 ( V_30 , L_48 , V_2 -> V_74 . V_75 ) ;
if ( F_20 ( V_52 ) -> V_64 >= 8 ) {
int V_76 ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ )
F_15 ( V_30 , L_49 ,
V_76 , V_2 -> V_74 . V_77 [ V_76 ] ) ;
} else {
F_15 ( V_30 , L_50 ,
V_2 -> V_74 . V_78 ) ;
}
}
F_15 ( V_30 , L_51 , V_2 -> V_79 ) ;
F_15 ( V_30 , L_52 , F_1 ( V_2 -> V_80 ) ) ;
F_15 ( V_30 , L_53 , V_2 -> V_81 ) ;
F_15 ( V_30 , L_54 , V_2 -> V_82 ) ;
F_15 ( V_30 , L_55 ,
F_18 ( V_2 -> V_83 ) ,
V_2 -> V_84 ) ;
}
void F_25 ( struct V_15 * V_16 , const char * V_27 , ... )
{
T_2 args ;
va_start ( args , V_27 ) ;
F_11 ( V_16 , V_27 , args ) ;
va_end ( args ) ;
}
static void F_26 ( struct V_15 * V_30 ,
struct V_85 * V_86 )
{
int V_87 , V_88 , V_89 ;
for ( V_87 = V_88 = 0 ; V_87 < V_86 -> V_90 ; V_87 ++ ) {
for ( V_89 = 0 ; V_89 < V_91 / 4 ; V_89 ++ ) {
F_15 ( V_30 , L_56 , V_88 ,
V_86 -> V_92 [ V_87 ] [ V_89 ] ) ;
V_88 += 4 ;
}
}
}
int F_27 ( struct V_15 * V_30 ,
const struct V_93 * V_94 )
{
struct V_51 * V_52 = V_94 -> V_52 ;
struct V_95 * V_96 = V_52 -> V_97 ;
struct V_98 * error = V_94 -> error ;
struct V_85 * V_86 ;
int V_76 , V_99 , V_88 , V_89 ;
int V_100 ;
if ( ! error ) {
F_15 ( V_30 , L_57 ) ;
goto V_101;
}
F_15 ( V_30 , L_58 , error -> V_102 ) ;
F_15 ( V_30 , L_59 , error -> time . V_103 ,
error -> time . V_104 ) ;
F_15 ( V_30 , L_60 V_105 L_22 ) ;
V_100 = 0 ;
for ( V_76 = 0 ; V_76 < F_28 ( error -> V_2 ) ; V_76 ++ ) {
if ( error -> V_2 [ V_76 ] . V_84 > V_100 )
V_100 = error -> V_2 [ V_76 ] . V_84 ;
}
for ( V_76 = 0 ; V_76 < F_28 ( error -> V_2 ) ; V_76 ++ ) {
if ( error -> V_2 [ V_76 ] . V_84 == V_100 &&
error -> V_2 [ V_76 ] . V_106 != - 1 ) {
F_15 ( V_30 , L_61 ,
F_2 ( V_76 ) ,
error -> V_2 [ V_76 ] . V_107 ,
error -> V_2 [ V_76 ] . V_106 ) ;
}
}
F_15 ( V_30 , L_62 , error -> V_108 ) ;
F_15 ( V_30 , L_63 , error -> V_109 ) ;
F_15 ( V_30 , L_64 , V_52 -> V_110 -> V_111 ) ;
F_15 ( V_30 , L_65 , error -> V_112 ) ;
F_15 ( V_30 , L_66 , error -> V_113 ) ;
if ( F_20 ( V_52 ) -> V_64 >= 8 ) {
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ )
F_15 ( V_30 , L_67 , V_76 ,
error -> V_114 [ V_76 ] ) ;
} else if ( F_29 ( V_52 ) || F_30 ( V_52 ) )
F_15 ( V_30 , L_68 , error -> V_114 [ 0 ] ) ;
F_15 ( V_30 , L_69 , error -> V_115 ) ;
F_15 ( V_30 , L_70 , error -> V_116 ) ;
F_15 ( V_30 , L_71 , error -> V_117 ) ;
F_15 ( V_30 , L_72 , error -> V_118 ) ;
F_15 ( V_30 , L_73 , V_96 -> V_119 . V_120 ) ;
for ( V_76 = 0 ; V_76 < V_96 -> V_121 ; V_76 ++ )
F_15 ( V_30 , L_74 , V_76 , error -> V_122 [ V_76 ] ) ;
for ( V_76 = 0 ; V_76 < F_28 ( error -> V_123 ) ; V_76 ++ )
F_15 ( V_30 , L_75 , V_76 ,
error -> V_123 [ V_76 ] ) ;
if ( F_20 ( V_52 ) -> V_64 >= 6 ) {
F_15 ( V_30 , L_76 , error -> error ) ;
F_15 ( V_30 , L_77 , error -> V_124 ) ;
}
if ( F_20 ( V_52 ) -> V_64 == 7 )
F_15 ( V_30 , L_78 , error -> V_125 ) ;
for ( V_76 = 0 ; V_76 < F_28 ( error -> V_2 ) ; V_76 ++ ) {
F_15 ( V_30 , L_79 , F_2 ( V_76 ) ) ;
F_19 ( V_30 , V_52 , & error -> V_2 [ V_76 ] ) ;
}
if ( error -> V_126 )
F_14 ( V_30 , L_80 ,
error -> V_126 [ 0 ] ,
error -> V_127 [ 0 ] ) ;
if ( error -> V_128 )
F_14 ( V_30 , L_81 ,
error -> V_128 [ 0 ] ,
error -> V_129 [ 0 ] ) ;
for ( V_76 = 0 ; V_76 < F_28 ( error -> V_2 ) ; V_76 ++ ) {
V_86 = error -> V_2 [ V_76 ] . V_130 ;
if ( V_86 ) {
F_16 ( V_30 , V_96 -> V_2 [ V_76 ] . V_31 ) ;
if ( error -> V_2 [ V_76 ] . V_106 != - 1 )
F_15 ( V_30 , L_82 ,
error -> V_2 [ V_76 ] . V_107 ,
error -> V_2 [ V_76 ] . V_106 ) ;
F_15 ( V_30 , L_83 ,
V_86 -> V_34 ) ;
F_26 ( V_30 , V_86 ) ;
}
V_86 = error -> V_2 [ V_76 ] . V_131 ;
if ( V_86 ) {
F_15 ( V_30 , L_84 ,
V_96 -> V_2 [ V_76 ] . V_31 , V_86 -> V_34 ) ;
F_26 ( V_30 , V_86 ) ;
}
if ( error -> V_2 [ V_76 ] . V_132 ) {
F_15 ( V_30 , L_85 ,
V_96 -> V_2 [ V_76 ] . V_31 ,
error -> V_2 [ V_76 ] . V_132 ) ;
for ( V_99 = 0 ; V_99 < error -> V_2 [ V_76 ] . V_132 ; V_99 ++ ) {
F_15 ( V_30 , L_86 ,
error -> V_2 [ V_76 ] . V_133 [ V_99 ] . V_79 ,
error -> V_2 [ V_76 ] . V_133 [ V_99 ] . V_134 ,
error -> V_2 [ V_76 ] . V_133 [ V_99 ] . V_56 ) ;
}
}
if ( ( V_86 = error -> V_2 [ V_76 ] . V_135 ) ) {
F_15 ( V_30 , L_87 ,
V_96 -> V_2 [ V_76 ] . V_31 ,
V_86 -> V_34 ) ;
F_26 ( V_30 , V_86 ) ;
}
if ( ( V_86 = error -> V_2 [ V_76 ] . V_136 ) ) {
F_15 ( V_30 , L_88 ,
V_96 -> V_2 [ V_76 ] . V_31 ,
V_86 -> V_34 ) ;
V_88 = 0 ;
for ( V_89 = 0 ; V_89 < V_91 / 16 ; V_89 += 4 ) {
F_15 ( V_30 , L_89 ,
V_88 ,
V_86 -> V_92 [ 0 ] [ V_89 ] ,
V_86 -> V_92 [ 0 ] [ V_89 + 1 ] ,
V_86 -> V_92 [ 0 ] [ V_89 + 2 ] ,
V_86 -> V_92 [ 0 ] [ V_89 + 3 ] ) ;
V_88 += 16 ;
}
}
if ( ( V_86 = error -> V_2 [ V_76 ] . V_137 ) ) {
F_15 ( V_30 , L_90 ,
V_96 -> V_2 [ V_76 ] . V_31 ,
V_86 -> V_34 ) ;
F_26 ( V_30 , V_86 ) ;
}
}
if ( ( V_86 = error -> V_138 ) ) {
F_15 ( V_30 , L_91 , V_86 -> V_34 ) ;
for ( V_89 = 0 ; V_89 < V_91 / 16 ; V_89 += 4 ) {
F_15 ( V_30 , L_89 ,
V_89 * 4 ,
V_86 -> V_92 [ 0 ] [ V_89 ] ,
V_86 -> V_92 [ 0 ] [ V_89 + 1 ] ,
V_86 -> V_92 [ 0 ] [ V_89 + 2 ] ,
V_86 -> V_92 [ 0 ] [ V_89 + 3 ] ) ;
}
}
if ( error -> V_139 )
F_31 ( V_30 , error -> V_139 ) ;
if ( error -> V_140 )
F_32 ( V_30 , V_52 , error -> V_140 ) ;
V_101:
if ( V_30 -> V_18 == 0 && V_30 -> V_17 )
return V_30 -> V_17 ;
return 0 ;
}
int F_33 ( struct V_15 * V_141 ,
T_1 V_33 , T_3 V_22 )
{
memset ( V_141 , 0 , sizeof( * V_141 ) ) ;
V_141 -> V_19 = V_33 + 1 > V_91 ? V_33 + 1 : V_91 ;
V_141 -> V_26 = F_34 ( V_141 -> V_19 ,
V_142 | V_143 | V_144 ) ;
if ( V_141 -> V_26 == NULL ) {
V_141 -> V_19 = V_91 ;
V_141 -> V_26 = F_34 ( V_141 -> V_19 , V_142 ) ;
}
if ( V_141 -> V_26 == NULL ) {
V_141 -> V_19 = 128 ;
V_141 -> V_26 = F_34 ( V_141 -> V_19 , V_142 ) ;
}
if ( V_141 -> V_26 == NULL )
return - V_145 ;
V_141 -> V_23 = V_22 ;
return 0 ;
}
static void F_35 ( struct V_85 * V_86 )
{
int V_87 ;
if ( V_86 == NULL )
return;
for ( V_87 = 0 ; V_87 < V_86 -> V_90 ; V_87 ++ )
F_36 ( V_86 -> V_92 [ V_87 ] ) ;
F_36 ( V_86 ) ;
}
static void F_37 ( struct V_146 * V_147 )
{
struct V_98 * error = F_38 ( V_147 ,
F_39 ( * error ) , V_148 ) ;
int V_76 ;
for ( V_76 = 0 ; V_76 < F_28 ( error -> V_2 ) ; V_76 ++ ) {
F_35 ( error -> V_2 [ V_76 ] . V_130 ) ;
F_35 ( error -> V_2 [ V_76 ] . V_135 ) ;
F_35 ( error -> V_2 [ V_76 ] . V_136 ) ;
F_35 ( error -> V_2 [ V_76 ] . V_137 ) ;
F_36 ( error -> V_2 [ V_76 ] . V_133 ) ;
}
F_35 ( error -> V_138 ) ;
F_36 ( error -> V_126 ) ;
F_36 ( error -> V_139 ) ;
F_36 ( error -> V_140 ) ;
F_36 ( error ) ;
}
static struct V_85 *
F_40 ( struct V_95 * V_96 ,
struct V_149 * V_150 ,
struct V_151 * V_152 ,
const int V_153 )
{
struct V_85 * V_154 ;
int V_76 ;
V_59 V_155 ;
if ( V_150 == NULL || V_150 -> V_92 == NULL )
return NULL ;
V_154 = F_34 ( sizeof( * V_154 ) + V_153 * sizeof( V_59 * ) , V_156 ) ;
if ( V_154 == NULL )
return NULL ;
V_155 = V_154 -> V_34 = F_41 ( V_150 , V_152 ) ;
for ( V_76 = 0 ; V_76 < V_153 ; V_76 ++ ) {
unsigned long V_157 ;
void * V_158 ;
V_158 = F_34 ( V_91 , V_156 ) ;
if ( V_158 == NULL )
goto V_159;
F_42 ( V_157 ) ;
if ( V_150 -> V_40 == V_160 &&
V_155 < V_96 -> V_161 . V_162 &&
V_150 -> V_163 &&
F_43 ( V_152 ) ) {
void T_4 * V_164 ;
V_164 = F_44 ( V_96 -> V_161 . V_165 ,
V_155 ) ;
F_45 ( V_158 , V_164 , V_91 ) ;
F_46 ( V_164 ) ;
} else if ( V_150 -> V_166 ) {
unsigned long V_88 ;
V_88 = V_96 -> V_167 . V_168 ;
V_88 += V_150 -> V_166 -> V_23 ;
V_88 += V_76 << V_169 ;
F_45 ( V_158 , ( void T_4 * ) V_88 , V_91 ) ;
} else {
struct V_87 * V_87 ;
void * V_164 ;
V_87 = F_47 ( V_150 , V_76 ) ;
F_48 ( & V_87 , 1 ) ;
V_164 = F_49 ( V_87 ) ;
memcpy ( V_158 , V_164 , V_91 ) ;
F_50 ( V_164 ) ;
F_48 ( & V_87 , 1 ) ;
}
F_51 ( V_157 ) ;
V_154 -> V_92 [ V_76 ] = V_158 ;
V_155 += V_91 ;
}
V_154 -> V_90 = V_153 ;
return V_154 ;
V_159:
while ( V_76 -- )
F_36 ( V_154 -> V_92 [ V_76 ] ) ;
F_36 ( V_154 ) ;
return NULL ;
}
static void F_52 ( struct V_32 * V_17 ,
struct V_149 * V_86 )
{
V_17 -> V_19 = V_86 -> V_170 . V_19 ;
V_17 -> V_31 = V_86 -> V_170 . V_31 ;
V_17 -> V_37 = V_86 -> V_171 ;
V_17 -> V_38 = V_86 -> V_172 ;
V_17 -> V_34 = F_53 ( V_86 ) ;
V_17 -> V_35 = V_86 -> V_170 . V_35 ;
V_17 -> V_36 = V_86 -> V_170 . V_36 ;
V_17 -> V_41 = V_86 -> V_41 ;
V_17 -> V_8 = 0 ;
if ( F_54 ( V_86 ) )
V_17 -> V_8 = 1 ;
if ( V_86 -> V_173 > 0 )
V_17 -> V_8 = - 1 ;
V_17 -> V_9 = V_86 -> V_174 ;
V_17 -> V_13 = V_86 -> V_13 ;
V_17 -> V_14 = V_86 -> V_175 != V_176 ;
V_17 -> V_39 = V_86 -> V_39 . V_167 != NULL ;
V_17 -> V_2 = V_86 -> V_2 ? V_86 -> V_2 -> V_177 : - 1 ;
V_17 -> V_40 = V_86 -> V_40 ;
}
static V_59 F_55 ( struct V_32 * V_17 ,
int V_33 , struct V_178 * V_55 )
{
struct V_179 * V_180 ;
int V_76 = 0 ;
F_56 (vma, head, mm_list) {
F_52 ( V_17 ++ , V_180 -> V_86 ) ;
if ( ++ V_76 == V_33 )
break;
}
return V_76 ;
}
static V_59 F_57 ( struct V_32 * V_17 ,
int V_33 , struct V_178 * V_55 )
{
struct V_149 * V_86 ;
int V_76 = 0 ;
F_56 (obj, head, global_list) {
if ( ! F_54 ( V_86 ) )
continue;
F_52 ( V_17 ++ , V_86 ) ;
if ( ++ V_76 == V_33 )
break;
}
return V_76 ;
}
static T_5 F_58 ( struct V_95 * V_96 ,
struct V_98 * error ,
int * V_181 )
{
T_5 V_182 = 0 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_183 ; V_76 ++ ) {
if ( error -> V_2 [ V_76 ] . V_83 == V_50 ) {
if ( V_181 )
* V_181 = V_76 ;
return error -> V_2 [ V_76 ] . V_62 ^ error -> V_2 [ V_76 ] . V_63 ;
}
}
return V_182 ;
}
static void F_59 ( struct V_51 * V_52 ,
struct V_98 * error )
{
struct V_95 * V_96 = V_52 -> V_97 ;
int V_76 ;
switch ( F_20 ( V_52 ) -> V_64 ) {
case 8 :
case 7 :
case 6 :
for ( V_76 = 0 ; V_76 < V_96 -> V_121 ; V_76 ++ )
error -> V_122 [ V_76 ] = F_60 ( V_184 + ( V_76 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_76 = 0 ; V_76 < 16 ; V_76 ++ )
error -> V_122 [ V_76 ] = F_60 ( V_185 + ( V_76 * 8 ) ) ;
break;
case 3 :
if ( F_61 ( V_52 ) || F_62 ( V_52 ) || F_63 ( V_52 ) )
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ )
error -> V_122 [ V_76 + 8 ] = F_64 ( V_186 + ( V_76 * 4 ) ) ;
case 2 :
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ )
error -> V_122 [ V_76 ] = F_64 ( V_187 + ( V_76 * 4 ) ) ;
break;
default:
F_65 () ;
}
}
static void F_66 ( struct V_95 * V_96 ,
struct V_98 * error ,
struct V_188 * V_2 ,
struct V_53 * V_189 )
{
struct V_188 * V_190 ;
int V_76 ;
if ( ! F_67 ( V_96 -> V_52 ) )
return;
if ( ! error -> V_138 )
error -> V_138 =
F_68 ( V_96 ,
V_96 -> V_138 ,
& V_96 -> V_161 . V_170 ) ;
F_69 (to, dev_priv, i) {
int V_191 ;
T_6 V_192 ;
V_59 * V_28 ;
if ( V_2 == V_190 )
continue;
V_192 = ( F_70 ( V_2 , V_76 ) & ( V_91 - 1 ) )
/ 4 ;
V_28 = error -> V_138 -> V_92 [ 0 ] ;
V_191 = F_71 ( V_2 , V_190 ) ;
V_189 -> V_72 [ V_191 ] = V_28 [ V_192 ] ;
V_189 -> V_73 [ V_191 ] = V_2 -> V_193 . V_194 [ V_191 ] ;
}
}
static void F_72 ( struct V_95 * V_96 ,
struct V_188 * V_2 ,
struct V_53 * V_189 )
{
V_189 -> V_72 [ 0 ] = F_64 ( F_73 ( V_2 -> V_195 ) ) ;
V_189 -> V_72 [ 1 ] = F_64 ( F_74 ( V_2 -> V_195 ) ) ;
V_189 -> V_73 [ 0 ] = V_2 -> V_193 . V_194 [ 0 ] ;
V_189 -> V_73 [ 1 ] = V_2 -> V_193 . V_194 [ 1 ] ;
if ( F_23 ( V_96 -> V_52 ) ) {
V_189 -> V_72 [ 2 ] =
F_64 ( F_75 ( V_2 -> V_195 ) ) ;
V_189 -> V_73 [ 2 ] = V_2 -> V_193 . V_194 [ 2 ] ;
}
}
static void F_76 ( struct V_51 * V_52 ,
struct V_98 * error ,
struct V_188 * V_2 ,
struct V_53 * V_189 )
{
struct V_95 * V_96 = V_52 -> V_97 ;
if ( F_20 ( V_52 ) -> V_64 >= 6 ) {
V_189 -> V_70 = F_64 ( V_2 -> V_195 + 0x50 ) ;
V_189 -> V_71 = F_64 ( F_77 ( V_2 ) ) ;
if ( F_20 ( V_52 ) -> V_64 >= 8 )
F_66 ( V_96 , error , V_2 , V_189 ) ;
else
F_72 ( V_96 , V_2 , V_189 ) ;
}
if ( F_20 ( V_52 ) -> V_64 >= 4 ) {
V_189 -> V_69 = F_64 ( F_78 ( V_2 -> V_195 ) ) ;
V_189 -> V_61 = F_64 ( F_79 ( V_2 -> V_195 ) ) ;
V_189 -> V_62 = F_64 ( F_80 ( V_2 -> V_195 ) ) ;
V_189 -> V_63 = F_64 ( F_81 ( V_2 -> V_195 ) ) ;
V_189 -> V_67 = F_64 ( F_82 ( V_2 -> V_195 ) ) ;
V_189 -> V_65 = F_64 ( F_83 ( V_2 -> V_195 ) ) ;
if ( F_20 ( V_52 ) -> V_64 >= 8 ) {
V_189 -> V_69 |= ( V_196 ) F_64 ( F_84 ( V_2 -> V_195 ) ) << 32 ;
V_189 -> V_65 |= ( V_196 ) F_64 ( F_85 ( V_2 -> V_195 ) ) << 32 ;
}
V_189 -> V_66 = F_64 ( F_86 ( V_2 -> V_195 ) ) ;
} else {
V_189 -> V_69 = F_64 ( V_197 ) ;
V_189 -> V_61 = F_64 ( V_198 ) ;
V_189 -> V_62 = F_64 ( V_199 ) ;
V_189 -> V_63 = F_64 ( V_200 ) ;
}
V_189 -> V_80 = F_87 ( & V_2 -> V_201 ) ;
V_189 -> V_68 = F_64 ( F_88 ( V_2 -> V_195 ) ) ;
V_189 -> V_79 = V_2 -> V_202 ( V_2 , false ) ;
V_189 -> V_60 = F_89 ( V_2 ) ;
V_189 -> V_55 = F_90 ( V_2 ) ;
V_189 -> V_56 = F_91 ( V_2 ) ;
V_189 -> V_57 = F_92 ( V_2 ) ;
if ( F_93 ( V_52 ) ) {
int V_203 ;
if ( F_94 ( V_52 ) ) {
switch ( V_2 -> V_177 ) {
default:
case V_3 :
V_203 = V_204 ;
break;
case V_5 :
V_203 = V_205 ;
break;
case V_4 :
V_203 = V_206 ;
break;
case V_6 :
V_203 = V_207 ;
break;
}
} else if ( F_95 ( V_2 -> V_52 ) ) {
V_203 = F_96 ( V_2 -> V_195 ) ;
} else {
V_203 = F_97 ( V_2 -> V_195 ) ;
}
V_189 -> V_58 = F_64 ( V_203 ) ;
}
V_189 -> V_81 = V_2 -> V_208 -> V_55 ;
V_189 -> V_82 = V_2 -> V_208 -> V_56 ;
V_189 -> V_84 = V_2 -> V_209 . V_210 ;
V_189 -> V_83 = V_2 -> V_209 . V_211 ;
if ( F_24 ( V_52 ) ) {
int V_76 ;
V_189 -> V_74 . V_75 = F_64 ( F_98 ( V_2 ) ) ;
switch ( F_20 ( V_52 ) -> V_64 ) {
case 8 :
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
V_189 -> V_74 . V_77 [ V_76 ] =
F_64 ( F_99 ( V_2 , V_76 ) ) ;
V_189 -> V_74 . V_77 [ V_76 ] <<= 32 ;
V_189 -> V_74 . V_77 [ V_76 ] |=
F_64 ( F_100 ( V_2 , V_76 ) ) ;
}
break;
case 7 :
V_189 -> V_74 . V_78 =
F_64 ( F_101 ( V_2 ) ) ;
break;
case 6 :
V_189 -> V_74 . V_78 =
F_64 ( F_102 ( V_2 ) ) ;
break;
}
}
}
static void F_103 ( struct V_188 * V_2 ,
struct V_98 * error ,
struct V_53 * V_189 )
{
struct V_95 * V_96 = V_2 -> V_52 -> V_97 ;
struct V_149 * V_86 ;
if ( V_2 -> V_177 != V_3 || ! error -> V_118 )
return;
F_56 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_104 ( V_86 ) )
continue;
if ( ( error -> V_118 & V_212 ) == F_53 ( V_86 ) ) {
V_189 -> V_137 = F_105 ( V_96 , V_86 ) ;
break;
}
}
}
static void F_106 ( struct V_51 * V_52 ,
struct V_98 * error )
{
struct V_95 * V_96 = V_52 -> V_97 ;
struct V_213 * V_214 ;
int V_76 , V_33 ;
for ( V_76 = 0 ; V_76 < V_183 ; V_76 ++ ) {
struct V_188 * V_2 = & V_96 -> V_2 [ V_76 ] ;
error -> V_2 [ V_76 ] . V_106 = - 1 ;
if ( V_2 -> V_52 == NULL )
continue;
error -> V_2 [ V_76 ] . V_54 = true ;
F_76 ( V_52 , error , V_2 , & error -> V_2 [ V_76 ] ) ;
V_214 = F_107 ( V_2 ) ;
if ( V_214 ) {
error -> V_2 [ V_76 ] . V_130 =
F_68 ( V_96 ,
V_214 -> V_215 ,
V_214 -> V_137 ?
V_214 -> V_137 -> V_152 :
& V_96 -> V_161 . V_170 ) ;
if ( F_108 ( V_96 -> V_52 ) &&
V_2 -> V_216 . V_86 )
error -> V_2 [ V_76 ] . V_131 =
F_105 ( V_96 ,
V_2 -> V_216 . V_86 ) ;
if ( V_214 -> V_217 ) {
struct V_218 * V_219 ;
F_109 () ;
V_219 = F_110 ( V_214 -> V_217 -> V_220 -> V_106 ,
V_221 ) ;
if ( V_219 ) {
strcpy ( error -> V_2 [ V_76 ] . V_107 , V_219 -> V_107 ) ;
error -> V_2 [ V_76 ] . V_106 = V_219 -> V_106 ;
}
F_111 () ;
}
}
error -> V_2 [ V_76 ] . V_135 =
F_105 ( V_96 , V_2 -> V_208 -> V_86 ) ;
if ( V_2 -> V_222 . V_86 )
error -> V_2 [ V_76 ] . V_136 =
F_105 ( V_96 , V_2 -> V_222 . V_86 ) ;
F_103 ( V_2 , error , & error -> V_2 [ V_76 ] ) ;
V_33 = 0 ;
F_56 (request, &ring->request_list, list)
V_33 ++ ;
error -> V_2 [ V_76 ] . V_132 = V_33 ;
error -> V_2 [ V_76 ] . V_133 =
F_112 ( V_33 , sizeof( * error -> V_2 [ V_76 ] . V_133 ) ,
V_156 ) ;
if ( error -> V_2 [ V_76 ] . V_133 == NULL ) {
error -> V_2 [ V_76 ] . V_132 = 0 ;
continue;
}
V_33 = 0 ;
F_56 (request, &ring->request_list, list) {
struct V_223 * V_224 ;
V_224 = & error -> V_2 [ V_76 ] . V_133 [ V_33 ++ ] ;
V_224 -> V_79 = V_214 -> V_79 ;
V_224 -> V_134 = V_214 -> V_225 ;
V_224 -> V_56 = V_214 -> V_56 ;
}
}
}
static void F_113 ( struct V_95 * V_96 ,
struct V_98 * error ,
struct V_151 * V_152 ,
const int V_226 )
{
struct V_32 * V_126 = NULL , * V_128 = NULL ;
struct V_149 * V_86 ;
struct V_179 * V_180 ;
int V_76 ;
V_76 = 0 ;
F_56 (vma, &vm->active_list, mm_list)
V_76 ++ ;
error -> V_127 [ V_226 ] = V_76 ;
F_56 (obj, &dev_priv->mm.bound_list, global_list)
if ( F_54 ( V_86 ) )
V_76 ++ ;
error -> V_129 [ V_226 ] = V_76 - error -> V_127 [ V_226 ] ;
if ( V_76 ) {
V_126 = F_112 ( V_76 , sizeof( * V_126 ) , V_156 ) ;
if ( V_126 )
V_128 = V_126 + error -> V_127 [ V_226 ] ;
}
if ( V_126 )
error -> V_127 [ V_226 ] =
F_55 ( V_126 ,
error -> V_127 [ V_226 ] ,
& V_152 -> V_227 ) ;
if ( V_128 )
error -> V_129 [ V_226 ] =
F_57 ( V_128 ,
error -> V_129 [ V_226 ] ,
& V_96 -> V_167 . V_228 ) ;
error -> V_126 [ V_226 ] = V_126 ;
error -> V_128 [ V_226 ] = V_128 ;
}
static void F_114 ( struct V_95 * V_96 ,
struct V_98 * error )
{
struct V_151 * V_152 ;
int V_229 = 0 , V_76 = 0 ;
F_56 (vm, &dev_priv->vm_list, global_link)
V_229 ++ ;
error -> V_126 = F_112 ( V_229 , sizeof( * error -> V_126 ) , V_156 ) ;
error -> V_128 = F_112 ( V_229 , sizeof( * error -> V_128 ) , V_156 ) ;
error -> V_127 = F_112 ( V_229 , sizeof( * error -> V_127 ) ,
V_156 ) ;
error -> V_129 = F_112 ( V_229 , sizeof( * error -> V_129 ) ,
V_156 ) ;
F_56 (vm, &dev_priv->vm_list, global_link)
F_113 ( V_96 , error , V_152 , V_76 ++ ) ;
}
static void F_115 ( struct V_95 * V_96 ,
struct V_98 * error )
{
struct V_51 * V_52 = V_96 -> V_52 ;
int V_76 ;
if ( F_30 ( V_52 ) ) {
error -> V_114 [ 0 ] = F_64 ( V_230 ) ;
error -> V_113 = F_64 ( V_231 ) ;
error -> V_116 = F_64 ( V_232 ) ;
}
if ( F_94 ( V_52 ) )
error -> V_125 = F_64 ( V_233 ) ;
if ( F_95 ( V_52 ) ) {
error -> V_116 = F_64 ( V_234 ) ;
error -> V_235 = F_64 ( V_236 ) ;
error -> V_75 = F_64 ( V_237 ) ;
}
if ( F_20 ( V_52 ) -> V_64 >= 7 )
error -> V_116 = F_64 ( V_238 ) ;
if ( F_20 ( V_52 ) -> V_64 >= 6 ) {
error -> V_117 = F_64 ( V_239 ) ;
error -> error = F_64 ( V_240 ) ;
error -> V_124 = F_64 ( V_241 ) ;
}
if ( F_95 ( V_52 ) || F_94 ( V_52 ) ) {
error -> V_242 = F_64 ( V_243 ) ;
error -> V_244 = F_64 ( V_245 ) ;
}
if ( F_116 ( V_52 ) )
error -> V_118 = F_64 ( V_246 ) ;
if ( F_20 ( V_52 ) -> V_64 >= 8 ) {
error -> V_113 = F_64 ( V_247 ) ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ )
error -> V_114 [ V_76 ] = F_64 ( F_117 ( V_76 ) ) ;
} else if ( F_29 ( V_52 ) ) {
error -> V_113 = F_64 ( V_248 ) ;
error -> V_114 [ 0 ] = F_64 ( V_230 ) ;
} else if ( F_118 ( V_52 ) ) {
error -> V_113 = F_119 ( V_249 ) ;
} else if ( ! F_30 ( V_52 ) ) {
error -> V_113 = F_64 ( V_249 ) ;
}
error -> V_112 = F_64 ( V_250 ) ;
error -> V_115 = F_64 ( V_251 ) ;
F_120 ( V_52 , error -> V_123 ) ;
}
static void F_121 ( struct V_51 * V_52 ,
struct V_98 * error ,
bool V_252 ,
const char * V_102 )
{
struct V_95 * V_96 = V_52 -> V_97 ;
V_59 V_253 ;
int V_181 = - 1 , V_21 ;
V_253 = F_58 ( V_96 , error , & V_181 ) ;
V_21 = F_122 ( error -> V_102 , sizeof( error -> V_102 ) ,
L_92 , V_181 , V_253 ) ;
if ( V_181 != - 1 && error -> V_2 [ V_181 ] . V_106 != - 1 )
V_21 += F_122 ( error -> V_102 + V_21 ,
sizeof( error -> V_102 ) - V_21 ,
L_93 ,
error -> V_2 [ V_181 ] . V_107 ,
error -> V_2 [ V_181 ] . V_106 ) ;
F_122 ( error -> V_102 + V_21 , sizeof( error -> V_102 ) - V_21 ,
L_94 ,
V_102 ,
V_252 ? L_95 : L_96 ) ;
}
static void F_123 ( struct V_95 * V_96 ,
struct V_98 * error )
{
error -> V_108 = F_124 ( & V_96 -> V_119 ) ;
error -> V_109 = V_96 -> V_109 ;
}
void F_125 ( struct V_51 * V_52 , bool V_252 ,
const char * V_102 )
{
static bool V_254 ;
struct V_95 * V_96 = V_52 -> V_97 ;
struct V_98 * error ;
unsigned long V_157 ;
error = F_126 ( sizeof( * error ) , V_156 ) ;
if ( ! error ) {
F_127 ( L_97 ) ;
return;
}
F_128 ( & error -> V_148 ) ;
F_123 ( V_96 , error ) ;
F_115 ( V_96 , error ) ;
F_114 ( V_96 , error ) ;
F_59 ( V_52 , error ) ;
F_106 ( V_52 , error ) ;
F_129 ( & error -> time ) ;
error -> V_139 = F_130 ( V_52 ) ;
error -> V_140 = F_131 ( V_52 ) ;
F_121 ( V_52 , error , V_252 , V_102 ) ;
F_132 ( L_58 , error -> V_102 ) ;
F_133 ( & V_96 -> V_119 . V_255 , V_157 ) ;
if ( V_96 -> V_119 . V_256 == NULL ) {
V_96 -> V_119 . V_256 = error ;
error = NULL ;
}
F_134 ( & V_96 -> V_119 . V_255 , V_157 ) ;
if ( error ) {
F_37 ( & error -> V_148 ) ;
return;
}
if ( ! V_254 ) {
F_132 ( L_98 ) ;
F_132 ( L_99 ) ;
F_132 ( L_100 ) ;
F_132 ( L_101 ) ;
F_132 ( L_102 , V_52 -> V_257 -> V_258 ) ;
V_254 = true ;
}
}
void F_135 ( struct V_51 * V_52 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 = V_52 -> V_97 ;
unsigned long V_157 ;
F_133 ( & V_96 -> V_119 . V_255 , V_157 ) ;
V_94 -> error = V_96 -> V_119 . V_256 ;
if ( V_94 -> error )
F_136 ( & V_94 -> error -> V_148 ) ;
F_134 ( & V_96 -> V_119 . V_255 , V_157 ) ;
}
void F_137 ( struct V_93 * V_94 )
{
if ( V_94 -> error )
F_138 ( & V_94 -> error -> V_148 , F_37 ) ;
}
void F_139 ( struct V_51 * V_52 )
{
struct V_95 * V_96 = V_52 -> V_97 ;
struct V_98 * error ;
unsigned long V_157 ;
F_133 ( & V_96 -> V_119 . V_255 , V_157 ) ;
error = V_96 -> V_119 . V_256 ;
V_96 -> V_119 . V_256 = NULL ;
F_134 ( & V_96 -> V_119 . V_255 , V_157 ) ;
if ( error )
F_138 ( & error -> V_148 , F_37 ) ;
}
const char * F_17 ( int type )
{
switch ( type ) {
case V_160 : return L_103 ;
case V_259 : return L_104 ;
case V_260 : return L_105 ;
case V_261 : return L_106 ;
default: return L_8 ;
}
}
void F_120 ( struct V_51 * V_52 , T_5 * V_63 )
{
struct V_95 * V_96 = V_52 -> V_97 ;
memset ( V_63 , 0 , sizeof( * V_63 ) * V_262 ) ;
switch ( F_20 ( V_52 ) -> V_64 ) {
case 2 :
case 3 :
V_63 [ 0 ] = F_64 ( V_200 ) ;
break;
case 4 :
case 5 :
case 6 :
V_63 [ 0 ] = F_64 ( V_263 ) ;
V_63 [ 1 ] = F_64 ( V_264 ) ;
break;
default:
F_140 ( 1 , L_107 ) ;
case 7 :
case 8 :
V_63 [ 0 ] = F_64 ( V_265 ) ;
V_63 [ 1 ] = F_64 ( V_266 ) ;
V_63 [ 2 ] = F_64 ( V_267 ) ;
V_63 [ 3 ] = F_64 ( V_268 ) ;
break;
}
}
