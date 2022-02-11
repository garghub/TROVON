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
if ( V_7 > 0 )
return L_7 ;
else if ( V_7 < 0 )
return L_8 ;
else
return L_6 ;
}
static const char * F_3 ( int V_8 )
{
switch ( V_8 ) {
default:
case V_9 : return L_6 ;
case V_10 : return L_9 ;
case V_11 : return L_10 ;
}
}
static const char * F_4 ( int V_12 )
{
return V_12 ? L_11 : L_6 ;
}
static const char * F_5 ( int V_13 )
{
return V_13 ? L_12 : L_6 ;
}
static bool F_6 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_16 && F_7 ( V_15 -> V_17 > ( V_15 -> V_18 - 1 ) , L_13 ) ) {
V_15 -> V_16 = - V_19 ;
return false ;
}
if ( V_15 -> V_17 == V_15 -> V_18 - 1 || V_15 -> V_16 )
return false ;
return true ;
}
static bool F_8 ( struct V_14 * V_15 ,
unsigned V_20 )
{
if ( V_15 -> V_21 + V_20 <= V_15 -> V_22 ) {
V_15 -> V_21 += V_20 ;
return false ;
}
if ( V_20 >= V_15 -> V_18 ) {
V_15 -> V_16 = - V_23 ;
return false ;
}
return true ;
}
static void F_9 ( struct V_14 * V_15 ,
unsigned V_20 )
{
if ( V_15 -> V_21 < V_15 -> V_22 ) {
const T_1 V_24 = V_15 -> V_22 - V_15 -> V_21 ;
if ( V_24 > V_20 || V_15 -> V_17 ) {
V_15 -> V_16 = - V_23 ;
return;
}
memmove ( V_15 -> V_25 , V_15 -> V_25 + V_24 , V_20 - V_24 ) ;
V_15 -> V_17 = V_20 - V_24 ;
V_15 -> V_21 = V_15 -> V_22 ;
return;
}
V_15 -> V_17 += V_20 ;
V_15 -> V_21 += V_20 ;
}
static void F_10 ( struct V_14 * V_15 ,
const char * V_26 , T_2 args )
{
unsigned V_20 ;
if ( ! F_6 ( V_15 ) )
return;
if ( V_15 -> V_21 < V_15 -> V_22 ) {
T_2 V_27 ;
F_11 ( V_27 , args ) ;
V_20 = vsnprintf ( NULL , 0 , V_26 , V_27 ) ;
va_end ( V_27 ) ;
if ( ! F_8 ( V_15 , V_20 ) )
return;
}
V_20 = vsnprintf ( V_15 -> V_25 + V_15 -> V_17 , V_15 -> V_18 - V_15 -> V_17 , V_26 , args ) ;
if ( V_20 >= V_15 -> V_18 - V_15 -> V_17 )
V_20 = V_15 -> V_18 - V_15 -> V_17 - 1 ;
F_9 ( V_15 , V_20 ) ;
}
static void F_12 ( struct V_14 * V_15 ,
const char * V_28 )
{
unsigned V_20 ;
if ( ! F_6 ( V_15 ) )
return;
V_20 = strlen ( V_28 ) ;
if ( V_15 -> V_21 < V_15 -> V_22 ) {
if ( ! F_8 ( V_15 , V_20 ) )
return;
}
if ( V_20 >= V_15 -> V_18 - V_15 -> V_17 )
V_20 = V_15 -> V_18 - V_15 -> V_17 - 1 ;
memcpy ( V_15 -> V_25 + V_15 -> V_17 , V_28 , V_20 ) ;
F_9 ( V_15 , V_20 ) ;
}
static void F_13 ( struct V_14 * V_29 ,
const char * V_30 ,
struct V_31 * V_16 ,
int V_32 )
{
int V_33 ;
F_14 ( V_29 , L_14 , V_30 , V_32 ) ;
while ( V_32 -- ) {
F_14 ( V_29 , L_15 ,
F_15 ( V_16 -> V_34 ) ,
F_16 ( V_16 -> V_34 ) ,
V_16 -> V_18 ,
V_16 -> V_35 ,
V_16 -> V_36 ) ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ )
F_14 ( V_29 , L_16 , V_16 -> V_38 [ V_33 ] ) ;
F_14 ( V_29 , L_17 , V_16 -> V_39 ) ;
F_17 ( V_29 , F_2 ( V_16 -> V_7 ) ) ;
F_17 ( V_29 , F_3 ( V_16 -> V_8 ) ) ;
F_17 ( V_29 , F_4 ( V_16 -> V_12 ) ) ;
F_17 ( V_29 , F_5 ( V_16 -> V_13 ) ) ;
F_17 ( V_29 , V_16 -> V_40 ? L_18 : L_6 ) ;
F_17 ( V_29 , V_16 -> V_1 != - 1 ? L_19 : L_6 ) ;
F_17 ( V_29 , F_1 ( V_16 -> V_1 ) ) ;
F_17 ( V_29 , F_18 ( V_29 -> V_41 , V_16 -> V_42 ) ) ;
if ( V_16 -> V_30 )
F_14 ( V_29 , L_20 , V_16 -> V_30 ) ;
if ( V_16 -> V_43 != V_44 )
F_14 ( V_29 , L_21 , V_16 -> V_43 ) ;
F_17 ( V_29 , L_22 ) ;
V_16 ++ ;
}
}
static const char * F_19 ( enum V_45 V_46 )
{
switch ( V_46 ) {
case V_47 :
return L_23 ;
case V_48 :
return L_24 ;
case V_49 :
return L_25 ;
case V_50 :
return L_26 ;
case V_51 :
return L_27 ;
}
return L_28 ;
}
static void F_20 ( struct V_14 * V_29 ,
struct V_52 * V_53 ,
struct V_54 * error ,
int V_55 )
{
struct V_56 * V_1 = & error -> V_1 [ V_55 ] ;
if ( ! V_1 -> V_57 )
return;
F_14 ( V_29 , L_29 , F_1 ( V_55 ) ) ;
F_14 ( V_29 , L_30 , V_1 -> V_22 ) ;
F_14 ( V_29 , L_31 , V_1 -> V_58 ) ;
F_14 ( V_29 , L_32 , V_1 -> V_59 ) ;
F_14 ( V_29 , L_33 , V_1 -> V_60 ) ;
F_14 ( V_29 , L_34 , V_1 -> V_61 ) ;
F_14 ( V_29 , L_35 , ( V_62 ) ( V_1 -> V_63 >> 32 ) , ( V_62 ) V_1 -> V_63 ) ;
F_14 ( V_29 , L_36 , V_1 -> V_64 ) ;
F_14 ( V_29 , L_37 , V_1 -> V_65 ) ;
F_14 ( V_29 , L_38 , V_1 -> V_66 ) ;
if ( F_21 ( V_53 ) -> V_67 >= 4 ) {
F_14 ( V_29 , L_39 , ( V_62 ) ( V_1 -> V_68 >> 32 ) , ( V_62 ) V_1 -> V_68 ) ;
F_14 ( V_29 , L_40 , V_1 -> V_69 ) ;
F_14 ( V_29 , L_41 , V_1 -> V_70 ) ;
}
F_14 ( V_29 , L_42 , V_1 -> V_71 ) ;
F_14 ( V_29 , L_43 , F_15 ( V_1 -> V_72 ) ,
F_16 ( V_1 -> V_72 ) ) ;
if ( F_21 ( V_53 ) -> V_67 >= 6 ) {
F_14 ( V_29 , L_44 , V_1 -> V_73 ) ;
F_14 ( V_29 , L_45 , V_1 -> V_74 ) ;
F_14 ( V_29 , L_46 ,
V_1 -> V_75 [ 0 ] ,
V_1 -> V_76 [ 0 ] ) ;
F_14 ( V_29 , L_47 ,
V_1 -> V_75 [ 1 ] ,
V_1 -> V_76 [ 1 ] ) ;
if ( F_22 ( V_53 ) ) {
F_14 ( V_29 , L_48 ,
V_1 -> V_75 [ 2 ] ,
V_1 -> V_76 [ 2 ] ) ;
}
}
if ( F_23 ( V_53 ) ) {
F_14 ( V_29 , L_49 , V_1 -> V_77 . V_78 ) ;
if ( F_21 ( V_53 ) -> V_67 >= 8 ) {
int V_33 ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
F_14 ( V_29 , L_50 ,
V_33 , V_1 -> V_77 . V_79 [ V_33 ] ) ;
} else {
F_14 ( V_29 , L_51 ,
V_1 -> V_77 . V_80 ) ;
}
}
F_14 ( V_29 , L_52 , V_1 -> V_81 ) ;
F_14 ( V_29 , L_53 , V_1 -> V_82 ) ;
F_14 ( V_29 , L_54 , F_24 ( V_1 -> V_83 ) ) ;
F_14 ( V_29 , L_55 , V_1 -> V_84 ) ;
F_14 ( V_29 , L_56 , V_1 -> V_85 ) ;
F_14 ( V_29 , L_57 ,
F_19 ( V_1 -> V_86 ) ,
V_1 -> V_87 ) ;
}
void F_25 ( struct V_14 * V_15 , const char * V_26 , ... )
{
T_2 args ;
va_start ( args , V_26 ) ;
F_10 ( V_15 , V_26 , args ) ;
va_end ( args ) ;
}
static void F_26 ( struct V_14 * V_29 ,
struct V_88 * V_89 )
{
int V_90 , V_91 , V_92 ;
for ( V_90 = V_91 = 0 ; V_90 < V_89 -> V_93 ; V_90 ++ ) {
for ( V_92 = 0 ; V_92 < V_94 / 4 ; V_92 ++ ) {
F_14 ( V_29 , L_58 , V_91 ,
V_89 -> V_95 [ V_90 ] [ V_92 ] ) ;
V_91 += 4 ;
}
}
}
int F_27 ( struct V_14 * V_29 ,
const struct V_96 * V_97 )
{
struct V_52 * V_53 = V_97 -> V_53 ;
struct V_98 * V_99 = V_53 -> V_100 ;
struct V_54 * error = V_97 -> error ;
struct V_88 * V_89 ;
int V_33 , V_101 , V_91 , V_92 ;
int V_102 ;
if ( ! error ) {
F_14 ( V_29 , L_59 ) ;
goto V_103;
}
F_14 ( V_29 , L_60 , error -> V_104 ) ;
F_14 ( V_29 , L_61 , error -> time . V_105 ,
error -> time . V_106 ) ;
F_14 ( V_29 , L_62 V_107 L_22 ) ;
V_102 = 0 ;
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_1 ) ; V_33 ++ ) {
if ( error -> V_1 [ V_33 ] . V_87 > V_102 )
V_102 = error -> V_1 [ V_33 ] . V_87 ;
}
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_1 ) ; V_33 ++ ) {
if ( error -> V_1 [ V_33 ] . V_87 == V_102 &&
error -> V_1 [ V_33 ] . V_108 != - 1 ) {
F_14 ( V_29 , L_63 ,
F_1 ( V_33 ) ,
error -> V_1 [ V_33 ] . V_109 ,
error -> V_1 [ V_33 ] . V_108 ) ;
}
}
F_14 ( V_29 , L_64 , error -> V_110 ) ;
F_14 ( V_29 , L_65 , error -> V_111 ) ;
F_14 ( V_29 , L_66 , V_53 -> V_112 -> V_113 ) ;
F_14 ( V_29 , L_67 , V_53 -> V_112 -> V_114 ) ;
F_14 ( V_29 , L_68 ,
V_53 -> V_112 -> V_115 ,
V_53 -> V_112 -> V_116 ) ;
F_14 ( V_29 , L_69 , error -> V_117 ) ;
if ( F_29 ( V_53 ) ) {
struct V_118 * V_119 = & V_99 -> V_119 ;
F_14 ( V_29 , L_70 ,
F_24 ( V_119 -> V_120 != NULL ) ) ;
F_14 ( V_29 , L_71 ,
F_30 ( V_119 -> V_121 ) ,
F_31 ( V_119 -> V_121 ) ) ;
}
F_14 ( V_29 , L_72 , error -> V_122 ) ;
F_14 ( V_29 , L_73 , error -> V_123 ) ;
if ( F_21 ( V_53 ) -> V_67 >= 8 ) {
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
F_14 ( V_29 , L_74 , V_33 ,
error -> V_124 [ V_33 ] ) ;
} else if ( F_32 ( V_53 ) || F_33 ( V_53 ) )
F_14 ( V_29 , L_75 , error -> V_124 [ 0 ] ) ;
F_14 ( V_29 , L_76 , error -> V_125 ) ;
F_14 ( V_29 , L_77 , error -> V_126 ) ;
F_14 ( V_29 , L_78 , error -> V_127 ) ;
F_14 ( V_29 , L_79 , error -> V_128 ) ;
F_14 ( V_29 , L_80 , V_99 -> V_129 . V_130 ) ;
for ( V_33 = 0 ; V_33 < V_99 -> V_131 ; V_33 ++ )
F_14 ( V_29 , L_81 , V_33 , error -> V_132 [ V_33 ] ) ;
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_133 ) ; V_33 ++ )
F_14 ( V_29 , L_82 , V_33 ,
error -> V_133 [ V_33 ] ) ;
if ( F_21 ( V_53 ) -> V_67 >= 6 ) {
F_14 ( V_29 , L_83 , error -> error ) ;
if ( F_21 ( V_53 ) -> V_67 >= 8 )
F_14 ( V_29 , L_84 ,
error -> V_134 , error -> V_135 ) ;
F_14 ( V_29 , L_85 , error -> V_136 ) ;
}
if ( F_21 ( V_53 ) -> V_67 == 7 )
F_14 ( V_29 , L_86 , error -> V_137 ) ;
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_1 ) ; V_33 ++ )
F_20 ( V_29 , V_53 , error , V_33 ) ;
for ( V_33 = 0 ; V_33 < error -> V_138 ; V_33 ++ ) {
F_14 ( V_29 , L_87 , V_33 ) ;
F_13 ( V_29 , L_88 ,
error -> V_139 [ V_33 ] ,
error -> V_140 [ V_33 ] ) ;
F_13 ( V_29 , L_89 ,
error -> V_141 [ V_33 ] ,
error -> V_142 [ V_33 ] ) ;
}
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_1 ) ; V_33 ++ ) {
V_89 = error -> V_1 [ V_33 ] . V_143 ;
if ( V_89 ) {
F_17 ( V_29 , V_99 -> V_144 [ V_33 ] . V_30 ) ;
if ( error -> V_1 [ V_33 ] . V_108 != - 1 )
F_14 ( V_29 , L_90 ,
error -> V_1 [ V_33 ] . V_109 ,
error -> V_1 [ V_33 ] . V_108 ) ;
F_14 ( V_29 , L_91 ,
F_15 ( V_89 -> V_34 ) ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
V_89 = error -> V_1 [ V_33 ] . V_145 ;
if ( V_89 ) {
F_14 ( V_29 , L_92 ,
V_99 -> V_144 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
if ( error -> V_1 [ V_33 ] . V_146 ) {
F_14 ( V_29 , L_93 ,
V_99 -> V_144 [ V_33 ] . V_30 ,
error -> V_1 [ V_33 ] . V_146 ) ;
for ( V_101 = 0 ; V_101 < error -> V_1 [ V_33 ] . V_146 ; V_101 ++ ) {
F_14 ( V_29 , L_94 ,
error -> V_1 [ V_33 ] . V_147 [ V_101 ] . V_81 ,
error -> V_1 [ V_33 ] . V_147 [ V_101 ] . V_148 ,
error -> V_1 [ V_33 ] . V_147 [ V_101 ] . V_59 ) ;
}
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_149 ) ) {
F_14 ( V_29 , L_95 ,
V_99 -> V_144 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_150 ) ) {
T_3 V_151 = V_89 -> V_34 ;
V_62 * V_150 = & V_89 -> V_95 [ 0 ] [ 0 ] ;
if ( V_41 . V_152 ) {
V_151 += V_153 * V_94 ;
V_150 = & V_89 -> V_95 [ V_153 ] [ 0 ] ;
}
F_14 ( V_29 , L_96 ,
V_99 -> V_144 [ V_33 ] . V_30 , V_151 ) ;
V_91 = 0 ;
for ( V_92 = 0 ; V_92 < V_94 / 16 ; V_92 += 4 ) {
F_14 ( V_29 , L_97 ,
V_91 ,
V_150 [ V_92 ] ,
V_150 [ V_92 + 1 ] ,
V_150 [ V_92 + 2 ] ,
V_150 [ V_92 + 3 ] ) ;
V_91 += 16 ;
}
}
V_89 = error -> V_1 [ V_33 ] . V_154 ;
if ( V_89 ) {
T_3 V_155 = V_89 -> V_34 ;
V_62 * V_156 = & V_89 -> V_95 [ 0 ] [ 0 ] ;
struct V_157 * V_144 = & V_99 -> V_144 [ V_2 ] ;
V_62 V_158 = ( V_144 -> V_154 . V_159 . V_18 +
V_144 -> V_154 . V_160 . V_18 ) ;
F_14 ( V_29 , L_98 ,
V_99 -> V_144 [ V_33 ] . V_30 , V_155 ) ;
V_91 = 0 ;
for ( V_92 = 0 ; V_92 < V_158 ; V_92 += 4 ) {
F_14 ( V_29 , L_97 ,
V_91 ,
V_156 [ V_92 + 0 ] ,
V_156 [ V_92 + 1 ] ,
V_156 [ V_92 + 2 ] ,
V_156 [ V_92 + 3 ] ) ;
V_91 += 16 ;
}
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_161 ) ) {
F_14 ( V_29 , L_99 ,
V_99 -> V_144 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
}
if ( ( V_89 = error -> V_162 ) ) {
F_14 ( V_29 , L_100 ,
F_16 ( V_89 -> V_34 ) ) ;
for ( V_92 = 0 ; V_92 < V_94 / 16 ; V_92 += 4 ) {
F_14 ( V_29 , L_97 ,
V_92 * 4 ,
V_89 -> V_95 [ 0 ] [ V_92 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 1 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 2 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 3 ] ) ;
}
}
if ( error -> V_163 )
F_34 ( V_29 , error -> V_163 ) ;
if ( error -> V_164 )
F_35 ( V_29 , V_53 , error -> V_164 ) ;
V_103:
if ( V_29 -> V_17 == 0 && V_29 -> V_16 )
return V_29 -> V_16 ;
return 0 ;
}
int F_36 ( struct V_14 * V_165 ,
struct V_98 * V_41 ,
T_1 V_32 , T_4 V_21 )
{
memset ( V_165 , 0 , sizeof( * V_165 ) ) ;
V_165 -> V_41 = V_41 ;
V_165 -> V_18 = V_32 + 1 > V_94 ? V_32 + 1 : V_94 ;
V_165 -> V_25 = F_37 ( V_165 -> V_18 ,
V_166 | V_167 | V_168 ) ;
if ( V_165 -> V_25 == NULL ) {
V_165 -> V_18 = V_94 ;
V_165 -> V_25 = F_37 ( V_165 -> V_18 , V_166 ) ;
}
if ( V_165 -> V_25 == NULL ) {
V_165 -> V_18 = 128 ;
V_165 -> V_25 = F_37 ( V_165 -> V_18 , V_166 ) ;
}
if ( V_165 -> V_25 == NULL )
return - V_169 ;
V_165 -> V_22 = V_21 ;
return 0 ;
}
static void F_38 ( struct V_88 * V_89 )
{
int V_90 ;
if ( V_89 == NULL )
return;
for ( V_90 = 0 ; V_90 < V_89 -> V_93 ; V_90 ++ )
F_39 ( V_89 -> V_95 [ V_90 ] ) ;
F_39 ( V_89 ) ;
}
static void F_40 ( struct V_170 * V_171 )
{
struct V_54 * error = F_41 ( V_171 ,
F_42 ( * error ) , V_172 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_1 ) ; V_33 ++ ) {
F_38 ( error -> V_1 [ V_33 ] . V_143 ) ;
F_38 ( error -> V_1 [ V_33 ] . V_145 ) ;
F_38 ( error -> V_1 [ V_33 ] . V_149 ) ;
F_38 ( error -> V_1 [ V_33 ] . V_150 ) ;
F_38 ( error -> V_1 [ V_33 ] . V_161 ) ;
F_39 ( error -> V_1 [ V_33 ] . V_147 ) ;
F_38 ( error -> V_1 [ V_33 ] . V_154 ) ;
}
F_38 ( error -> V_162 ) ;
for ( V_33 = 0 ; V_33 < error -> V_138 ; V_33 ++ )
F_39 ( error -> V_139 [ V_33 ] ) ;
F_39 ( error -> V_139 ) ;
F_39 ( error -> V_140 ) ;
F_39 ( error -> V_141 ) ;
F_39 ( error -> V_142 ) ;
F_39 ( error -> V_163 ) ;
F_39 ( error -> V_164 ) ;
F_39 ( error ) ;
}
static struct V_88 *
F_43 ( struct V_98 * V_99 ,
struct V_173 * V_174 ,
struct V_175 * V_176 )
{
struct V_177 * V_178 = & V_99 -> V_178 ;
struct V_88 * V_179 ;
struct V_180 * V_181 = NULL ;
int V_182 ;
bool V_183 ;
int V_33 = 0 ;
T_3 V_184 ;
if ( V_174 == NULL || V_174 -> V_95 == NULL )
return NULL ;
V_182 = V_174 -> V_185 . V_18 >> V_186 ;
V_179 = F_37 ( sizeof( * V_179 ) + V_182 * sizeof( V_62 * ) , V_187 ) ;
if ( V_179 == NULL )
return NULL ;
if ( F_44 ( V_174 , V_176 ) )
V_179 -> V_34 = F_45 ( V_174 , V_176 ) ;
else
V_179 -> V_34 = - 1 ;
V_184 = V_179 -> V_34 ;
if ( F_46 ( V_176 ) )
V_181 = F_47 ( V_174 ) ;
V_183 = ( V_174 -> V_42 == V_188 &&
V_181 && ( V_181 -> V_189 & V_190 ) &&
V_184 + V_182 * V_94 <= V_178 -> V_191 ) ;
if ( V_174 -> V_192 ) {
V_183 = true ;
if ( ! ( V_181 && V_181 -> V_189 & V_190 ) )
goto V_193;
V_184 = F_48 ( V_174 ) ;
if ( V_184 + V_182 * V_94 > V_178 -> V_191 )
goto V_193;
}
if ( V_183 && V_174 -> V_42 != V_188 &&
! F_49 ( V_99 ) )
goto V_193;
V_179 -> V_93 = V_182 ;
while ( V_182 -- ) {
unsigned long V_194 ;
void * V_195 ;
V_195 = F_37 ( V_94 , V_187 ) ;
if ( V_195 == NULL )
goto V_193;
F_50 ( V_194 ) ;
if ( V_183 ) {
void T_5 * V_196 ;
V_196 = F_51 ( V_178 -> V_197 ,
V_184 ) ;
F_52 ( V_195 , V_196 , V_94 ) ;
F_53 ( V_196 ) ;
} else {
struct V_90 * V_90 ;
void * V_196 ;
V_90 = F_54 ( V_174 , V_33 ) ;
F_55 ( & V_90 , 1 ) ;
V_196 = F_56 ( V_90 ) ;
memcpy ( V_195 , V_196 , V_94 ) ;
F_57 ( V_196 ) ;
F_55 ( & V_90 , 1 ) ;
}
F_58 ( V_194 ) ;
V_179 -> V_95 [ V_33 ++ ] = V_195 ;
V_184 += V_94 ;
}
return V_179 ;
V_193:
while ( V_33 -- )
F_39 ( V_179 -> V_95 [ V_33 ] ) ;
F_39 ( V_179 ) ;
return NULL ;
}
static void F_59 ( struct V_31 * V_16 ,
struct V_180 * V_181 )
{
struct V_173 * V_89 = V_181 -> V_89 ;
int V_33 ;
V_16 -> V_18 = V_89 -> V_185 . V_18 ;
V_16 -> V_30 = V_89 -> V_185 . V_30 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ )
V_16 -> V_38 [ V_33 ] = F_60 ( V_89 -> V_198 [ V_33 ] ) ;
V_16 -> V_39 = F_60 ( V_89 -> V_199 ) ;
V_16 -> V_34 = V_181 -> V_200 . V_22 ;
V_16 -> V_35 = V_89 -> V_185 . V_35 ;
V_16 -> V_36 = V_89 -> V_185 . V_36 ;
V_16 -> V_43 = V_89 -> V_43 ;
V_16 -> V_7 = 0 ;
if ( F_61 ( V_89 ) )
V_16 -> V_7 = 1 ;
V_16 -> V_8 = V_89 -> V_201 ;
V_16 -> V_12 = V_89 -> V_12 ;
V_16 -> V_13 = V_89 -> V_202 != V_203 ;
V_16 -> V_40 = V_89 -> V_40 . V_204 != NULL ;
V_16 -> V_1 = V_89 -> V_199 ?
F_62 ( V_89 -> V_199 ) -> V_205 : - 1 ;
V_16 -> V_42 = V_89 -> V_42 ;
}
static V_62 F_63 ( struct V_31 * V_16 ,
int V_32 , struct V_206 * V_58 )
{
struct V_180 * V_181 ;
int V_33 = 0 ;
F_64 (vma, head, vm_link) {
F_59 ( V_16 ++ , V_181 ) ;
if ( ++ V_33 == V_32 )
break;
}
return V_33 ;
}
static V_62 F_65 ( struct V_31 * V_16 ,
int V_32 , struct V_206 * V_58 ,
struct V_175 * V_176 )
{
struct V_173 * V_89 ;
struct V_31 * const V_207 = V_16 ;
struct V_31 * const V_208 = V_16 + V_32 ;
F_64 (obj, head, global_list) {
struct V_180 * V_181 ;
if ( V_16 == V_208 )
break;
F_64 (vma, &obj->vma_list, obj_link)
if ( V_181 -> V_176 == V_176 && V_181 -> V_209 > 0 )
F_59 ( V_16 ++ , V_181 ) ;
}
return V_16 - V_207 ;
}
static T_6 F_66 ( struct V_98 * V_99 ,
struct V_54 * error ,
int * V_210 )
{
T_6 V_211 = 0 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
if ( error -> V_1 [ V_33 ] . V_86 == V_51 ) {
if ( V_210 )
* V_210 = V_33 ;
return error -> V_1 [ V_33 ] . V_65 ^ error -> V_1 [ V_33 ] . V_66 ;
}
}
return V_211 ;
}
static void F_67 ( struct V_52 * V_53 ,
struct V_54 * error )
{
struct V_98 * V_99 = V_53 -> V_100 ;
int V_33 ;
if ( F_68 ( V_53 ) || F_69 ( V_53 ) ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_131 ; V_33 ++ )
error -> V_132 [ V_33 ] = F_70 ( F_71 ( V_33 ) ) ;
} else if ( F_72 ( V_53 ) || F_73 ( V_53 ) ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_131 ; V_33 ++ )
error -> V_132 [ V_33 ] = F_74 ( F_75 ( V_33 ) ) ;
} else if ( F_21 ( V_53 ) -> V_67 >= 6 ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_131 ; V_33 ++ )
error -> V_132 [ V_33 ] = F_74 ( F_76 ( V_33 ) ) ;
}
}
static void F_77 ( struct V_98 * V_99 ,
struct V_54 * error ,
struct V_157 * V_144 ,
struct V_56 * V_212 )
{
struct V_157 * V_213 ;
enum V_214 V_205 ;
if ( ! F_78 ( V_99 -> V_53 ) )
return;
if ( ! error -> V_162 )
error -> V_162 =
F_79 ( V_99 ,
V_99 -> V_162 ) ;
F_80 (to, dev_priv, id) {
int V_215 ;
T_7 V_216 ;
V_62 * V_27 ;
if ( V_144 == V_213 )
continue;
V_216 = ( F_81 ( V_144 , V_205 ) & ( V_94 - 1 ) )
/ 4 ;
V_27 = error -> V_162 -> V_95 [ 0 ] ;
V_215 = F_82 ( V_144 , V_213 ) ;
V_212 -> V_75 [ V_215 ] = V_27 [ V_216 ] ;
V_212 -> V_76 [ V_215 ] = V_144 -> V_217 . V_218 [ V_215 ] ;
}
}
static void F_83 ( struct V_98 * V_99 ,
struct V_157 * V_144 ,
struct V_56 * V_212 )
{
V_212 -> V_75 [ 0 ] = F_70 ( F_84 ( V_144 -> V_219 ) ) ;
V_212 -> V_75 [ 1 ] = F_70 ( F_85 ( V_144 -> V_219 ) ) ;
V_212 -> V_76 [ 0 ] = V_144 -> V_217 . V_218 [ 0 ] ;
V_212 -> V_76 [ 1 ] = V_144 -> V_217 . V_218 [ 1 ] ;
if ( F_22 ( V_99 ) ) {
V_212 -> V_75 [ 2 ] =
F_70 ( F_86 ( V_144 -> V_219 ) ) ;
V_212 -> V_76 [ 2 ] = V_144 -> V_217 . V_218 [ 2 ] ;
}
}
static void F_87 ( struct V_52 * V_53 ,
struct V_54 * error ,
struct V_157 * V_144 ,
struct V_56 * V_212 )
{
struct V_98 * V_99 = V_53 -> V_100 ;
if ( F_21 ( V_53 ) -> V_67 >= 6 ) {
V_212 -> V_73 = F_70 ( F_88 ( V_144 -> V_219 ) ) ;
V_212 -> V_74 = F_70 ( F_89 ( V_144 ) ) ;
if ( F_21 ( V_53 ) -> V_67 >= 8 )
F_77 ( V_99 , error , V_144 ,
V_212 ) ;
else
F_83 ( V_99 , V_144 , V_212 ) ;
}
if ( F_21 ( V_53 ) -> V_67 >= 4 ) {
V_212 -> V_72 = F_70 ( F_90 ( V_144 -> V_219 ) ) ;
V_212 -> V_64 = F_70 ( F_91 ( V_144 -> V_219 ) ) ;
V_212 -> V_65 = F_70 ( F_92 ( V_144 -> V_219 ) ) ;
V_212 -> V_66 = F_70 ( F_93 ( V_144 -> V_219 ) ) ;
V_212 -> V_70 = F_70 ( F_94 ( V_144 -> V_219 ) ) ;
V_212 -> V_68 = F_70 ( F_95 ( V_144 -> V_219 ) ) ;
if ( F_21 ( V_53 ) -> V_67 >= 8 ) {
V_212 -> V_72 |= ( T_3 ) F_70 ( F_96 ( V_144 -> V_219 ) ) << 32 ;
V_212 -> V_68 |= ( T_3 ) F_70 ( F_97 ( V_144 -> V_219 ) ) << 32 ;
}
V_212 -> V_69 = F_70 ( F_98 ( V_144 -> V_219 ) ) ;
} else {
V_212 -> V_72 = F_70 ( V_220 ) ;
V_212 -> V_64 = F_70 ( V_221 ) ;
V_212 -> V_65 = F_70 ( V_222 ) ;
V_212 -> V_66 = F_70 ( V_223 ) ;
}
V_212 -> V_83 = F_99 ( & V_144 -> V_224 ) ;
V_212 -> V_71 = F_70 ( F_100 ( V_144 -> V_219 ) ) ;
V_212 -> V_63 = F_101 ( V_144 ) ;
V_212 -> V_81 = V_144 -> V_225 ( V_144 ) ;
V_212 -> V_82 = V_144 -> V_226 ;
V_212 -> V_22 = F_102 ( V_144 ) ;
V_212 -> V_58 = F_103 ( V_144 ) ;
V_212 -> V_59 = F_104 ( V_144 ) ;
V_212 -> V_60 = F_105 ( V_144 ) ;
if ( F_106 ( V_53 ) ) {
T_8 V_227 ;
if ( F_107 ( V_53 ) ) {
switch ( V_144 -> V_205 ) {
default:
case V_2 :
V_227 = V_228 ;
break;
case V_4 :
V_227 = V_229 ;
break;
case V_3 :
V_227 = V_230 ;
break;
case V_5 :
V_227 = V_231 ;
break;
}
} else if ( F_108 ( V_144 -> V_53 ) ) {
V_227 = F_109 ( V_144 -> V_219 ) ;
} else {
V_227 = F_110 ( V_144 -> V_219 ) ;
}
V_212 -> V_61 = F_70 ( V_227 ) ;
}
V_212 -> V_87 = V_144 -> V_232 . V_233 ;
V_212 -> V_86 = V_144 -> V_232 . V_234 ;
if ( F_23 ( V_53 ) ) {
int V_33 ;
V_212 -> V_77 . V_78 = F_70 ( F_111 ( V_144 ) ) ;
if ( F_108 ( V_53 ) )
V_212 -> V_77 . V_80 =
F_70 ( F_112 ( V_144 ) ) ;
else if ( F_107 ( V_53 ) )
V_212 -> V_77 . V_80 =
F_70 ( F_113 ( V_144 ) ) ;
else if ( F_21 ( V_53 ) -> V_67 >= 8 )
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ ) {
V_212 -> V_77 . V_79 [ V_33 ] =
F_70 ( F_114 ( V_144 , V_33 ) ) ;
V_212 -> V_77 . V_79 [ V_33 ] <<= 32 ;
V_212 -> V_77 . V_79 [ V_33 ] |=
F_70 ( F_115 ( V_144 , V_33 ) ) ;
}
}
}
static void F_116 ( struct V_157 * V_144 ,
struct V_54 * error ,
struct V_56 * V_212 )
{
struct V_98 * V_99 = V_144 -> V_53 -> V_100 ;
struct V_173 * V_89 ;
if ( V_144 -> V_205 != V_2 || ! error -> V_128 )
return;
F_64 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_117 ( V_89 ) )
continue;
if ( ( error -> V_128 & V_235 ) == F_48 ( V_89 ) ) {
V_212 -> V_161 = F_79 ( V_99 , V_89 ) ;
break;
}
}
}
static void F_118 ( struct V_52 * V_53 ,
struct V_54 * error )
{
struct V_98 * V_99 = F_119 ( V_53 ) ;
struct V_177 * V_178 = & V_99 -> V_178 ;
struct V_236 * V_237 ;
int V_33 , V_32 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
struct V_157 * V_144 = & V_99 -> V_144 [ V_33 ] ;
struct V_238 * V_239 ;
error -> V_1 [ V_33 ] . V_108 = - 1 ;
if ( V_144 -> V_53 == NULL )
continue;
error -> V_1 [ V_33 ] . V_57 = true ;
F_87 ( V_53 , error , V_144 , & error -> V_1 [ V_33 ] ) ;
V_237 = F_120 ( V_144 ) ;
if ( V_237 ) {
struct V_175 * V_176 ;
V_176 = V_237 -> V_161 && V_237 -> V_161 -> V_240 ?
& V_237 -> V_161 -> V_240 -> V_185 :
& V_178 -> V_185 ;
error -> V_1 [ V_33 ] . V_143 =
F_43 ( V_99 ,
V_237 -> V_241 ,
V_176 ) ;
if ( F_121 ( V_99 ) )
error -> V_1 [ V_33 ] . V_145 =
F_79 ( V_99 ,
V_144 -> V_242 . V_89 ) ;
if ( V_237 -> V_108 ) {
struct V_243 * V_244 ;
F_122 () ;
V_244 = F_123 ( V_237 -> V_108 , V_245 ) ;
if ( V_244 ) {
strcpy ( error -> V_1 [ V_33 ] . V_109 , V_244 -> V_109 ) ;
error -> V_1 [ V_33 ] . V_108 = V_244 -> V_108 ;
}
F_124 () ;
}
}
if ( V_41 . V_152 ) {
if ( V_237 )
V_239 = V_237 -> V_161 -> V_144 [ V_144 -> V_205 ] . V_246 ;
else
V_239 = V_99 -> V_247 -> V_144 [ V_144 -> V_205 ] . V_246 ;
} else
V_239 = V_144 -> V_248 ;
error -> V_1 [ V_33 ] . V_84 = V_239 -> V_58 ;
error -> V_1 [ V_33 ] . V_85 = V_239 -> V_59 ;
error -> V_1 [ V_33 ] . V_149 =
F_79 ( V_99 , V_239 -> V_89 ) ;
error -> V_1 [ V_33 ] . V_150 =
F_79 ( V_99 ,
V_144 -> V_249 . V_89 ) ;
if ( V_144 -> V_154 . V_89 ) {
error -> V_1 [ V_33 ] . V_154 =
F_79 ( V_99 ,
V_144 -> V_154 . V_89 ) ;
}
F_116 ( V_144 , error , & error -> V_1 [ V_33 ] ) ;
V_32 = 0 ;
F_64 (request, &engine->request_list, list)
V_32 ++ ;
error -> V_1 [ V_33 ] . V_146 = V_32 ;
error -> V_1 [ V_33 ] . V_147 =
F_125 ( V_32 , sizeof( * error -> V_1 [ V_33 ] . V_147 ) ,
V_187 ) ;
if ( error -> V_1 [ V_33 ] . V_147 == NULL ) {
error -> V_1 [ V_33 ] . V_146 = 0 ;
continue;
}
V_32 = 0 ;
F_64 (request, &engine->request_list, list) {
struct V_250 * V_251 ;
if ( V_32 >= error -> V_1 [ V_33 ] . V_146 ) {
break;
}
V_251 = & error -> V_1 [ V_33 ] . V_147 [ V_32 ++ ] ;
V_251 -> V_81 = V_237 -> V_81 ;
V_251 -> V_148 = V_237 -> V_252 ;
V_251 -> V_59 = V_237 -> V_253 ;
}
}
}
static void F_126 ( struct V_98 * V_99 ,
struct V_54 * error ,
struct V_175 * V_176 ,
const int V_254 )
{
struct V_31 * V_139 = NULL , * V_141 = NULL ;
struct V_173 * V_89 ;
struct V_180 * V_181 ;
int V_33 ;
V_33 = 0 ;
F_64 (vma, &vm->active_list, vm_link)
V_33 ++ ;
error -> V_140 [ V_254 ] = V_33 ;
F_64 (obj, &dev_priv->mm.bound_list, global_list) {
F_64 (vma, &obj->vma_list, obj_link)
if ( V_181 -> V_176 == V_176 && V_181 -> V_209 > 0 )
V_33 ++ ;
}
error -> V_142 [ V_254 ] = V_33 - error -> V_140 [ V_254 ] ;
if ( V_33 ) {
V_139 = F_125 ( V_33 , sizeof( * V_139 ) , V_187 ) ;
if ( V_139 )
V_141 = V_139 + error -> V_140 [ V_254 ] ;
}
if ( V_139 )
error -> V_140 [ V_254 ] =
F_63 ( V_139 ,
error -> V_140 [ V_254 ] ,
& V_176 -> V_255 ) ;
if ( V_141 )
error -> V_142 [ V_254 ] =
F_65 ( V_141 ,
error -> V_142 [ V_254 ] ,
& V_99 -> V_204 . V_256 , V_176 ) ;
error -> V_139 [ V_254 ] = V_139 ;
error -> V_141 [ V_254 ] = V_141 ;
}
static void F_127 ( struct V_98 * V_99 ,
struct V_54 * error )
{
struct V_175 * V_176 ;
int V_257 = 0 , V_33 = 0 ;
F_64 (vm, &dev_priv->vm_list, global_link)
V_257 ++ ;
error -> V_139 = F_125 ( V_257 , sizeof( * error -> V_139 ) , V_187 ) ;
error -> V_141 = F_125 ( V_257 , sizeof( * error -> V_141 ) , V_187 ) ;
error -> V_140 = F_125 ( V_257 , sizeof( * error -> V_140 ) ,
V_187 ) ;
error -> V_142 = F_125 ( V_257 , sizeof( * error -> V_142 ) ,
V_187 ) ;
if ( error -> V_139 == NULL ||
error -> V_141 == NULL ||
error -> V_140 == NULL ||
error -> V_142 == NULL ) {
F_39 ( error -> V_139 ) ;
F_39 ( error -> V_140 ) ;
F_39 ( error -> V_141 ) ;
F_39 ( error -> V_142 ) ;
error -> V_139 = NULL ;
error -> V_140 = NULL ;
error -> V_141 = NULL ;
error -> V_142 = NULL ;
} else {
F_64 (vm, &dev_priv->vm_list, global_link)
F_126 ( V_99 , error , V_176 , V_33 ++ ) ;
error -> V_138 = V_257 ;
}
}
static void F_128 ( struct V_98 * V_99 ,
struct V_54 * error )
{
struct V_52 * V_53 = V_99 -> V_53 ;
int V_33 ;
if ( F_33 ( V_53 ) ) {
error -> V_124 [ 0 ] = F_70 ( V_258 ) ;
error -> V_123 = F_70 ( V_259 ) ;
error -> V_126 = F_129 ( V_260 ) ;
}
if ( F_107 ( V_53 ) )
error -> V_137 = F_70 ( V_261 ) ;
if ( F_21 ( V_53 ) -> V_67 >= 8 ) {
error -> V_135 = F_70 ( V_262 ) ;
error -> V_134 = F_70 ( V_263 ) ;
}
if ( F_108 ( V_53 ) ) {
error -> V_126 = F_129 ( V_264 ) ;
error -> V_265 = F_70 ( V_266 ) ;
error -> V_78 = F_70 ( V_267 ) ;
}
if ( F_21 ( V_53 ) -> V_67 >= 7 )
error -> V_126 = F_129 ( V_268 ) ;
if ( F_21 ( V_53 ) -> V_67 >= 6 ) {
error -> V_127 = F_70 ( V_269 ) ;
error -> error = F_70 ( V_270 ) ;
error -> V_136 = F_70 ( V_271 ) ;
}
if ( F_108 ( V_53 ) || F_107 ( V_53 ) ) {
error -> V_272 = F_70 ( V_273 ) ;
error -> V_274 = F_70 ( V_275 ) ;
}
if ( F_130 ( V_53 ) )
error -> V_128 = F_70 ( V_276 ) ;
if ( F_21 ( V_53 ) -> V_67 >= 8 ) {
error -> V_123 = F_70 ( V_277 ) ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
error -> V_124 [ V_33 ] = F_70 ( F_131 ( V_33 ) ) ;
} else if ( F_32 ( V_53 ) ) {
error -> V_123 = F_70 ( V_278 ) ;
error -> V_124 [ 0 ] = F_70 ( V_258 ) ;
} else if ( F_69 ( V_53 ) ) {
error -> V_123 = F_132 ( V_279 ) ;
} else if ( ! F_33 ( V_53 ) ) {
error -> V_123 = F_70 ( V_279 ) ;
}
error -> V_122 = F_70 ( V_280 ) ;
error -> V_125 = F_70 ( V_281 ) ;
F_133 ( V_53 , error -> V_133 ) ;
}
static void F_134 ( struct V_52 * V_53 ,
struct V_54 * error ,
V_62 V_282 ,
const char * V_104 )
{
struct V_98 * V_99 = V_53 -> V_100 ;
V_62 V_283 ;
int V_210 = - 1 , V_20 ;
V_283 = F_66 ( V_99 , error , & V_210 ) ;
V_20 = F_135 ( error -> V_104 , sizeof( error -> V_104 ) ,
L_101 ,
F_21 ( V_53 ) -> V_67 , V_210 , V_283 ) ;
if ( V_210 != - 1 && error -> V_1 [ V_210 ] . V_108 != - 1 )
V_20 += F_135 ( error -> V_104 + V_20 ,
sizeof( error -> V_104 ) - V_20 ,
L_102 ,
error -> V_1 [ V_210 ] . V_109 ,
error -> V_1 [ V_210 ] . V_108 ) ;
F_135 ( error -> V_104 + V_20 , sizeof( error -> V_104 ) - V_20 ,
L_103 ,
V_104 ,
V_282 ? L_104 : L_105 ) ;
}
static void F_136 ( struct V_98 * V_99 ,
struct V_54 * error )
{
error -> V_117 = - 1 ;
#ifdef F_137
error -> V_117 = V_284 ;
#endif
error -> V_110 = F_138 ( & V_99 -> V_129 ) ;
error -> V_111 = V_99 -> V_111 ;
}
void F_139 ( struct V_52 * V_53 , V_62 V_282 ,
const char * V_104 )
{
static bool V_285 ;
struct V_98 * V_99 = V_53 -> V_100 ;
struct V_54 * error ;
unsigned long V_194 ;
error = F_140 ( sizeof( * error ) , V_187 ) ;
if ( ! error ) {
F_141 ( L_106 ) ;
return;
}
F_142 ( & error -> V_172 ) ;
F_136 ( V_99 , error ) ;
F_128 ( V_99 , error ) ;
F_127 ( V_99 , error ) ;
F_67 ( V_53 , error ) ;
F_118 ( V_53 , error ) ;
F_143 ( & error -> time ) ;
error -> V_163 = F_144 ( V_53 ) ;
error -> V_164 = F_145 ( V_53 ) ;
F_134 ( V_53 , error , V_282 , V_104 ) ;
F_146 ( L_60 , error -> V_104 ) ;
F_147 ( & V_99 -> V_129 . V_286 , V_194 ) ;
if ( V_99 -> V_129 . V_287 == NULL ) {
V_99 -> V_129 . V_287 = error ;
error = NULL ;
}
F_148 ( & V_99 -> V_129 . V_286 , V_194 ) ;
if ( error ) {
F_40 ( & error -> V_172 ) ;
return;
}
if ( ! V_285 ) {
F_146 ( L_107 ) ;
F_146 ( L_108 ) ;
F_146 ( L_109 ) ;
F_146 ( L_110 ) ;
F_146 ( L_111 , V_53 -> V_288 -> V_289 ) ;
V_285 = true ;
}
}
void F_149 ( struct V_52 * V_53 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = V_53 -> V_100 ;
F_150 ( & V_99 -> V_129 . V_286 ) ;
V_97 -> error = V_99 -> V_129 . V_287 ;
if ( V_97 -> error )
F_151 ( & V_97 -> error -> V_172 ) ;
F_152 ( & V_99 -> V_129 . V_286 ) ;
}
void F_153 ( struct V_96 * V_97 )
{
if ( V_97 -> error )
F_154 ( & V_97 -> error -> V_172 , F_40 ) ;
}
void F_155 ( struct V_52 * V_53 )
{
struct V_98 * V_99 = V_53 -> V_100 ;
struct V_54 * error ;
F_150 ( & V_99 -> V_129 . V_286 ) ;
error = V_99 -> V_129 . V_287 ;
V_99 -> V_129 . V_287 = NULL ;
F_152 ( & V_99 -> V_129 . V_286 ) ;
if ( error )
F_154 ( & error -> V_172 , F_40 ) ;
}
const char * F_18 ( struct V_98 * V_41 , int type )
{
switch ( type ) {
case V_188 : return L_112 ;
case V_290 : return F_49 ( V_41 ) ? L_113 : L_114 ;
case V_291 : return L_115 ;
case V_292 : return L_116 ;
default: return L_6 ;
}
}
void F_133 ( struct V_52 * V_53 , T_6 * V_66 )
{
struct V_98 * V_99 = V_53 -> V_100 ;
memset ( V_66 , 0 , sizeof( * V_66 ) * V_293 ) ;
if ( F_69 ( V_53 ) || F_68 ( V_53 ) )
V_66 [ 0 ] = F_70 ( V_223 ) ;
else if ( F_73 ( V_53 ) || F_72 ( V_53 ) || F_108 ( V_53 ) ) {
V_66 [ 0 ] = F_70 ( F_93 ( V_294 ) ) ;
V_66 [ 1 ] = F_70 ( V_295 ) ;
} else if ( F_21 ( V_53 ) -> V_67 >= 7 ) {
V_66 [ 0 ] = F_70 ( F_93 ( V_294 ) ) ;
V_66 [ 1 ] = F_70 ( V_296 ) ;
V_66 [ 2 ] = F_70 ( V_297 ) ;
V_66 [ 3 ] = F_70 ( V_298 ) ;
}
}
