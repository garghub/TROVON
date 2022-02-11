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
struct V_98 * V_99 = F_28 ( V_53 ) ;
struct V_54 * error = V_97 -> error ;
struct V_88 * V_89 ;
int V_33 , V_100 , V_91 , V_92 ;
int V_101 ;
if ( ! error ) {
F_14 ( V_29 , L_59 ) ;
goto V_102;
}
F_14 ( V_29 , L_60 , error -> V_103 ) ;
F_14 ( V_29 , L_61 , error -> time . V_104 ,
error -> time . V_105 ) ;
F_14 ( V_29 , L_62 V_106 L_22 ) ;
V_101 = 0 ;
for ( V_33 = 0 ; V_33 < F_29 ( error -> V_1 ) ; V_33 ++ ) {
if ( error -> V_1 [ V_33 ] . V_87 > V_101 )
V_101 = error -> V_1 [ V_33 ] . V_87 ;
}
for ( V_33 = 0 ; V_33 < F_29 ( error -> V_1 ) ; V_33 ++ ) {
if ( error -> V_1 [ V_33 ] . V_87 == V_101 &&
error -> V_1 [ V_33 ] . V_107 != - 1 ) {
F_14 ( V_29 , L_63 ,
F_1 ( V_33 ) ,
error -> V_1 [ V_33 ] . V_108 ,
error -> V_1 [ V_33 ] . V_107 ) ;
}
}
F_14 ( V_29 , L_64 , error -> V_109 ) ;
F_14 ( V_29 , L_65 , error -> V_110 ) ;
F_14 ( V_29 , L_66 , V_53 -> V_111 -> V_112 ) ;
F_14 ( V_29 , L_67 , V_53 -> V_111 -> V_113 ) ;
F_14 ( V_29 , L_68 ,
V_53 -> V_111 -> V_114 ,
V_53 -> V_111 -> V_115 ) ;
F_14 ( V_29 , L_69 , error -> V_116 ) ;
if ( F_30 ( V_53 ) ) {
struct V_117 * V_118 = & V_99 -> V_118 ;
F_14 ( V_29 , L_70 ,
F_24 ( V_118 -> V_119 != NULL ) ) ;
F_14 ( V_29 , L_71 ,
F_31 ( V_118 -> V_120 ) ,
F_32 ( V_118 -> V_120 ) ) ;
}
F_14 ( V_29 , L_72 , error -> V_121 ) ;
F_14 ( V_29 , L_73 , error -> V_122 ) ;
if ( F_21 ( V_53 ) -> V_67 >= 8 ) {
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
F_14 ( V_29 , L_74 , V_33 ,
error -> V_123 [ V_33 ] ) ;
} else if ( F_33 ( V_53 ) || F_34 ( V_53 ) )
F_14 ( V_29 , L_75 , error -> V_123 [ 0 ] ) ;
F_14 ( V_29 , L_76 , error -> V_124 ) ;
F_14 ( V_29 , L_77 , error -> V_125 ) ;
F_14 ( V_29 , L_78 , error -> V_126 ) ;
F_14 ( V_29 , L_79 , error -> V_127 ) ;
F_14 ( V_29 , L_80 , V_99 -> V_128 . V_129 ) ;
for ( V_33 = 0 ; V_33 < V_99 -> V_130 ; V_33 ++ )
F_14 ( V_29 , L_81 , V_33 , error -> V_131 [ V_33 ] ) ;
for ( V_33 = 0 ; V_33 < F_29 ( error -> V_132 ) ; V_33 ++ )
F_14 ( V_29 , L_82 , V_33 ,
error -> V_132 [ V_33 ] ) ;
if ( F_21 ( V_53 ) -> V_67 >= 6 ) {
F_14 ( V_29 , L_83 , error -> error ) ;
if ( F_21 ( V_53 ) -> V_67 >= 8 )
F_14 ( V_29 , L_84 ,
error -> V_133 , error -> V_134 ) ;
F_14 ( V_29 , L_85 , error -> V_135 ) ;
}
if ( F_35 ( V_53 ) )
F_14 ( V_29 , L_86 , error -> V_136 ) ;
for ( V_33 = 0 ; V_33 < F_29 ( error -> V_1 ) ; V_33 ++ )
F_20 ( V_29 , V_53 , error , V_33 ) ;
for ( V_33 = 0 ; V_33 < error -> V_137 ; V_33 ++ ) {
F_14 ( V_29 , L_87 , V_33 ) ;
F_13 ( V_29 , L_88 ,
error -> V_138 [ V_33 ] ,
error -> V_139 [ V_33 ] ) ;
F_13 ( V_29 , L_89 ,
error -> V_140 [ V_33 ] ,
error -> V_141 [ V_33 ] ) ;
}
for ( V_33 = 0 ; V_33 < F_29 ( error -> V_1 ) ; V_33 ++ ) {
V_89 = error -> V_1 [ V_33 ] . V_142 ;
if ( V_89 ) {
F_17 ( V_29 , V_99 -> V_143 [ V_33 ] . V_30 ) ;
if ( error -> V_1 [ V_33 ] . V_107 != - 1 )
F_14 ( V_29 , L_90 ,
error -> V_1 [ V_33 ] . V_108 ,
error -> V_1 [ V_33 ] . V_107 ) ;
F_14 ( V_29 , L_91 ,
F_15 ( V_89 -> V_34 ) ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
V_89 = error -> V_1 [ V_33 ] . V_144 ;
if ( V_89 ) {
F_14 ( V_29 , L_92 ,
V_99 -> V_143 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
if ( error -> V_1 [ V_33 ] . V_145 ) {
F_14 ( V_29 , L_93 ,
V_99 -> V_143 [ V_33 ] . V_30 ,
error -> V_1 [ V_33 ] . V_145 ) ;
for ( V_100 = 0 ; V_100 < error -> V_1 [ V_33 ] . V_145 ; V_100 ++ ) {
F_14 ( V_29 , L_94 ,
error -> V_1 [ V_33 ] . V_146 [ V_100 ] . V_81 ,
error -> V_1 [ V_33 ] . V_146 [ V_100 ] . V_147 ,
error -> V_1 [ V_33 ] . V_146 [ V_100 ] . V_59 ) ;
}
}
if ( error -> V_1 [ V_33 ] . V_148 ) {
F_14 ( V_29 , L_95 ,
V_99 -> V_143 [ V_33 ] . V_30 ,
error -> V_1 [ V_33 ] . V_148 ) ;
for ( V_100 = 0 ; V_100 < error -> V_1 [ V_33 ] . V_148 ; V_100 ++ ) {
F_14 ( V_29 , L_96 ,
error -> V_1 [ V_33 ] . V_149 [ V_100 ] . V_81 ,
error -> V_1 [ V_33 ] . V_149 [ V_100 ] . V_108 ,
error -> V_1 [ V_33 ] . V_149 [ V_100 ] . V_107 ) ;
}
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_150 ) ) {
F_14 ( V_29 , L_97 ,
V_99 -> V_143 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_151 ) ) {
T_3 V_152 = V_89 -> V_34 ;
V_62 * V_151 = & V_89 -> V_95 [ 0 ] [ 0 ] ;
if ( V_41 . V_153 ) {
V_152 += V_154 * V_94 ;
V_151 = & V_89 -> V_95 [ V_154 ] [ 0 ] ;
}
F_14 ( V_29 , L_98 ,
V_99 -> V_143 [ V_33 ] . V_30 , V_152 ) ;
V_91 = 0 ;
for ( V_92 = 0 ; V_92 < V_94 / 16 ; V_92 += 4 ) {
F_14 ( V_29 , L_99 ,
V_91 ,
V_151 [ V_92 ] ,
V_151 [ V_92 + 1 ] ,
V_151 [ V_92 + 2 ] ,
V_151 [ V_92 + 3 ] ) ;
V_91 += 16 ;
}
}
V_89 = error -> V_1 [ V_33 ] . V_155 ;
if ( V_89 ) {
T_3 V_156 = V_89 -> V_34 ;
V_62 * V_157 = & V_89 -> V_95 [ 0 ] [ 0 ] ;
struct V_158 * V_143 = & V_99 -> V_143 [ V_2 ] ;
V_62 V_159 = ( V_143 -> V_155 . V_160 . V_18 +
V_143 -> V_155 . V_161 . V_18 ) ;
F_14 ( V_29 , L_100 ,
V_99 -> V_143 [ V_33 ] . V_30 , V_156 ) ;
V_91 = 0 ;
for ( V_92 = 0 ; V_92 < V_159 ; V_92 += 4 ) {
F_14 ( V_29 , L_99 ,
V_91 ,
V_157 [ V_92 + 0 ] ,
V_157 [ V_92 + 1 ] ,
V_157 [ V_92 + 2 ] ,
V_157 [ V_92 + 3 ] ) ;
V_91 += 16 ;
}
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_162 ) ) {
F_14 ( V_29 , L_101 ,
V_99 -> V_143 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
}
if ( ( V_89 = error -> V_163 ) ) {
F_14 ( V_29 , L_102 ,
F_16 ( V_89 -> V_34 ) ) ;
for ( V_92 = 0 ; V_92 < V_94 / 16 ; V_92 += 4 ) {
F_14 ( V_29 , L_99 ,
V_92 * 4 ,
V_89 -> V_95 [ 0 ] [ V_92 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 1 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 2 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 3 ] ) ;
}
}
if ( error -> V_164 )
F_36 ( V_29 , error -> V_164 ) ;
if ( error -> V_165 )
F_37 ( V_29 , V_53 , error -> V_165 ) ;
V_102:
if ( V_29 -> V_17 == 0 && V_29 -> V_16 )
return V_29 -> V_16 ;
return 0 ;
}
int F_38 ( struct V_14 * V_166 ,
struct V_98 * V_41 ,
T_1 V_32 , T_4 V_21 )
{
memset ( V_166 , 0 , sizeof( * V_166 ) ) ;
V_166 -> V_41 = V_41 ;
V_166 -> V_18 = V_32 + 1 > V_94 ? V_32 + 1 : V_94 ;
V_166 -> V_25 = F_39 ( V_166 -> V_18 ,
V_167 | V_168 | V_169 ) ;
if ( V_166 -> V_25 == NULL ) {
V_166 -> V_18 = V_94 ;
V_166 -> V_25 = F_39 ( V_166 -> V_18 , V_167 ) ;
}
if ( V_166 -> V_25 == NULL ) {
V_166 -> V_18 = 128 ;
V_166 -> V_25 = F_39 ( V_166 -> V_18 , V_167 ) ;
}
if ( V_166 -> V_25 == NULL )
return - V_170 ;
V_166 -> V_22 = V_21 ;
return 0 ;
}
static void F_40 ( struct V_88 * V_89 )
{
int V_90 ;
if ( V_89 == NULL )
return;
for ( V_90 = 0 ; V_90 < V_89 -> V_93 ; V_90 ++ )
F_41 ( V_89 -> V_95 [ V_90 ] ) ;
F_41 ( V_89 ) ;
}
static void F_42 ( struct V_171 * V_172 )
{
struct V_54 * error = F_43 ( V_172 ,
F_44 ( * error ) , V_173 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < F_29 ( error -> V_1 ) ; V_33 ++ ) {
F_40 ( error -> V_1 [ V_33 ] . V_142 ) ;
F_40 ( error -> V_1 [ V_33 ] . V_144 ) ;
F_40 ( error -> V_1 [ V_33 ] . V_150 ) ;
F_40 ( error -> V_1 [ V_33 ] . V_151 ) ;
F_40 ( error -> V_1 [ V_33 ] . V_162 ) ;
F_40 ( error -> V_1 [ V_33 ] . V_155 ) ;
F_41 ( error -> V_1 [ V_33 ] . V_146 ) ;
F_41 ( error -> V_1 [ V_33 ] . V_149 ) ;
}
F_40 ( error -> V_163 ) ;
for ( V_33 = 0 ; V_33 < error -> V_137 ; V_33 ++ )
F_41 ( error -> V_138 [ V_33 ] ) ;
F_41 ( error -> V_138 ) ;
F_41 ( error -> V_139 ) ;
F_41 ( error -> V_140 ) ;
F_41 ( error -> V_141 ) ;
F_41 ( error -> V_164 ) ;
F_41 ( error -> V_165 ) ;
F_41 ( error ) ;
}
static struct V_88 *
F_45 ( struct V_98 * V_99 ,
struct V_174 * V_175 ,
struct V_176 * V_177 )
{
struct V_178 * V_179 = & V_99 -> V_179 ;
struct V_88 * V_180 ;
struct V_181 * V_182 = NULL ;
int V_183 ;
bool V_184 ;
int V_33 = 0 ;
T_3 V_185 ;
if ( V_175 == NULL || V_175 -> V_95 == NULL )
return NULL ;
V_183 = V_175 -> V_186 . V_18 >> V_187 ;
V_180 = F_39 ( sizeof( * V_180 ) + V_183 * sizeof( V_62 * ) , V_188 ) ;
if ( V_180 == NULL )
return NULL ;
if ( F_46 ( V_175 , V_177 ) )
V_180 -> V_34 = F_47 ( V_175 , V_177 ) ;
else
V_180 -> V_34 = - 1 ;
V_185 = V_180 -> V_34 ;
if ( F_48 ( V_177 ) )
V_182 = F_49 ( V_175 ) ;
V_184 = ( V_175 -> V_42 == V_189 &&
V_182 && ( V_182 -> V_190 & V_191 ) &&
V_185 + V_183 * V_94 <= V_179 -> V_192 ) ;
if ( V_175 -> V_193 ) {
V_184 = true ;
if ( ! ( V_182 && V_182 -> V_190 & V_191 ) )
goto V_194;
V_185 = F_50 ( V_175 ) ;
if ( V_185 + V_183 * V_94 > V_179 -> V_192 )
goto V_194;
}
if ( V_184 && V_175 -> V_42 != V_189 &&
! F_51 ( V_99 ) )
goto V_194;
V_180 -> V_93 = V_183 ;
while ( V_183 -- ) {
unsigned long V_195 ;
void * V_196 ;
V_196 = F_39 ( V_94 , V_188 ) ;
if ( V_196 == NULL )
goto V_194;
F_52 ( V_195 ) ;
if ( V_184 ) {
void T_5 * V_197 ;
V_197 = F_53 ( V_179 -> V_198 ,
V_185 ) ;
F_54 ( V_196 , V_197 , V_94 ) ;
F_55 ( V_197 ) ;
} else {
struct V_90 * V_90 ;
void * V_197 ;
V_90 = F_56 ( V_175 , V_33 ) ;
F_57 ( & V_90 , 1 ) ;
V_197 = F_58 ( V_90 ) ;
memcpy ( V_196 , V_197 , V_94 ) ;
F_59 ( V_197 ) ;
F_57 ( & V_90 , 1 ) ;
}
F_60 ( V_195 ) ;
V_180 -> V_95 [ V_33 ++ ] = V_196 ;
V_185 += V_94 ;
}
return V_180 ;
V_194:
while ( V_33 -- )
F_41 ( V_180 -> V_95 [ V_33 ] ) ;
F_41 ( V_180 ) ;
return NULL ;
}
static void F_61 ( struct V_31 * V_16 ,
struct V_181 * V_182 )
{
struct V_174 * V_89 = V_182 -> V_89 ;
int V_33 ;
V_16 -> V_18 = V_89 -> V_186 . V_18 ;
V_16 -> V_30 = V_89 -> V_186 . V_30 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ )
V_16 -> V_38 [ V_33 ] = F_62 ( V_89 -> V_199 [ V_33 ] ) ;
V_16 -> V_39 = F_62 ( V_89 -> V_200 ) ;
V_16 -> V_34 = V_182 -> V_201 . V_22 ;
V_16 -> V_35 = V_89 -> V_186 . V_35 ;
V_16 -> V_36 = V_89 -> V_186 . V_36 ;
V_16 -> V_43 = V_89 -> V_43 ;
V_16 -> V_7 = 0 ;
if ( F_63 ( V_89 ) )
V_16 -> V_7 = 1 ;
V_16 -> V_8 = V_89 -> V_202 ;
V_16 -> V_12 = V_89 -> V_12 ;
V_16 -> V_13 = V_89 -> V_203 != V_204 ;
V_16 -> V_40 = V_89 -> V_40 . V_205 != NULL ;
V_16 -> V_1 = V_89 -> V_200 ?
F_64 ( V_89 -> V_200 ) -> V_206 : - 1 ;
V_16 -> V_42 = V_89 -> V_42 ;
}
static V_62 F_65 ( struct V_31 * V_16 ,
int V_32 , struct V_207 * V_58 )
{
struct V_181 * V_182 ;
int V_33 = 0 ;
F_66 (vma, head, vm_link) {
F_61 ( V_16 ++ , V_182 ) ;
if ( ++ V_33 == V_32 )
break;
}
return V_33 ;
}
static V_62 F_67 ( struct V_31 * V_16 ,
int V_32 , struct V_207 * V_58 ,
struct V_176 * V_177 )
{
struct V_174 * V_89 ;
struct V_31 * const V_208 = V_16 ;
struct V_31 * const V_209 = V_16 + V_32 ;
F_66 (obj, head, global_list) {
struct V_181 * V_182 ;
if ( V_16 == V_209 )
break;
F_66 (vma, &obj->vma_list, obj_link)
if ( V_182 -> V_177 == V_177 && V_182 -> V_210 > 0 )
F_61 ( V_16 ++ , V_182 ) ;
}
return V_16 - V_208 ;
}
static T_6 F_68 ( struct V_98 * V_99 ,
struct V_54 * error ,
int * V_211 )
{
T_6 V_212 = 0 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
if ( error -> V_1 [ V_33 ] . V_86 == V_51 ) {
if ( V_211 )
* V_211 = V_33 ;
return error -> V_1 [ V_33 ] . V_65 ^ error -> V_1 [ V_33 ] . V_66 ;
}
}
return V_212 ;
}
static void F_69 ( struct V_98 * V_99 ,
struct V_54 * error )
{
int V_33 ;
if ( F_70 ( V_99 ) || F_71 ( V_99 ) ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_130 ; V_33 ++ )
error -> V_131 [ V_33 ] = F_72 ( F_73 ( V_33 ) ) ;
} else if ( F_74 ( V_99 ) || F_75 ( V_99 ) ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_130 ; V_33 ++ )
error -> V_131 [ V_33 ] = F_76 ( F_77 ( V_33 ) ) ;
} else if ( F_78 ( V_99 ) >= 6 ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_130 ; V_33 ++ )
error -> V_131 [ V_33 ] = F_76 ( F_79 ( V_33 ) ) ;
}
}
static void F_80 ( struct V_98 * V_99 ,
struct V_54 * error ,
struct V_158 * V_143 ,
struct V_56 * V_213 )
{
struct V_158 * V_214 ;
enum V_215 V_206 ;
if ( ! F_81 ( V_99 ) )
return;
if ( ! error -> V_163 )
error -> V_163 =
F_82 ( V_99 ,
V_99 -> V_163 ) ;
F_83 (to, dev_priv, id) {
int V_216 ;
T_7 V_217 ;
V_62 * V_27 ;
if ( V_143 == V_214 )
continue;
V_217 = ( F_84 ( V_143 , V_206 ) & ( V_94 - 1 ) )
/ 4 ;
V_27 = error -> V_163 -> V_95 [ 0 ] ;
V_216 = F_85 ( V_143 , V_214 ) ;
V_213 -> V_75 [ V_216 ] = V_27 [ V_217 ] ;
V_213 -> V_76 [ V_216 ] = V_143 -> V_218 . V_219 [ V_216 ] ;
}
}
static void F_86 ( struct V_98 * V_99 ,
struct V_158 * V_143 ,
struct V_56 * V_213 )
{
V_213 -> V_75 [ 0 ] = F_72 ( F_87 ( V_143 -> V_220 ) ) ;
V_213 -> V_75 [ 1 ] = F_72 ( F_88 ( V_143 -> V_220 ) ) ;
V_213 -> V_76 [ 0 ] = V_143 -> V_218 . V_219 [ 0 ] ;
V_213 -> V_76 [ 1 ] = V_143 -> V_218 . V_219 [ 1 ] ;
if ( F_22 ( V_99 ) ) {
V_213 -> V_75 [ 2 ] =
F_72 ( F_89 ( V_143 -> V_220 ) ) ;
V_213 -> V_76 [ 2 ] = V_143 -> V_218 . V_219 [ 2 ] ;
}
}
static void F_90 ( struct V_158 * V_143 ,
struct V_56 * V_213 )
{
struct V_221 * V_222 = & V_143 -> V_223 ;
struct V_224 * V_225 ;
struct V_226 * V_227 ;
int V_32 ;
V_213 -> V_148 = 0 ;
V_213 -> V_149 = NULL ;
F_91 ( & V_222 -> V_228 ) ;
V_32 = 0 ;
for ( V_227 = F_92 ( & V_222 -> V_149 ) ; V_227 != NULL ; V_227 = F_93 ( V_227 ) )
V_32 ++ ;
F_94 ( & V_222 -> V_228 ) ;
V_225 = NULL ;
if ( V_32 )
V_225 = F_95 ( V_32 ,
sizeof( struct V_224 ) ,
V_188 ) ;
if ( ! V_225 )
return;
V_213 -> V_149 = V_225 ;
F_91 ( & V_222 -> V_228 ) ;
for ( V_227 = F_92 ( & V_222 -> V_149 ) ; V_227 ; V_227 = F_93 ( V_227 ) ) {
struct V_229 * V_230 = F_43 ( V_227 , F_44 ( * V_230 ) , V_201 ) ;
strcpy ( V_225 -> V_108 , V_230 -> V_231 -> V_108 ) ;
V_225 -> V_107 = V_230 -> V_231 -> V_107 ;
V_225 -> V_81 = V_230 -> V_81 ;
V_225 ++ ;
if ( ++ V_213 -> V_148 == V_32 )
break;
}
F_94 ( & V_222 -> V_228 ) ;
}
static void F_96 ( struct V_98 * V_99 ,
struct V_54 * error ,
struct V_158 * V_143 ,
struct V_56 * V_213 )
{
if ( F_78 ( V_99 ) >= 6 ) {
V_213 -> V_73 = F_72 ( F_97 ( V_143 -> V_220 ) ) ;
V_213 -> V_74 = F_72 ( F_98 ( V_143 ) ) ;
if ( F_78 ( V_99 ) >= 8 )
F_80 ( V_99 , error , V_143 ,
V_213 ) ;
else
F_86 ( V_99 , V_143 , V_213 ) ;
}
if ( F_78 ( V_99 ) >= 4 ) {
V_213 -> V_72 = F_72 ( F_99 ( V_143 -> V_220 ) ) ;
V_213 -> V_64 = F_72 ( F_100 ( V_143 -> V_220 ) ) ;
V_213 -> V_65 = F_72 ( F_101 ( V_143 -> V_220 ) ) ;
V_213 -> V_66 = F_72 ( F_102 ( V_143 -> V_220 ) ) ;
V_213 -> V_70 = F_72 ( F_103 ( V_143 -> V_220 ) ) ;
V_213 -> V_68 = F_72 ( F_104 ( V_143 -> V_220 ) ) ;
if ( F_78 ( V_99 ) >= 8 ) {
V_213 -> V_72 |= ( T_3 ) F_72 ( F_105 ( V_143 -> V_220 ) ) << 32 ;
V_213 -> V_68 |= ( T_3 ) F_72 ( F_106 ( V_143 -> V_220 ) ) << 32 ;
}
V_213 -> V_69 = F_72 ( F_107 ( V_143 -> V_220 ) ) ;
} else {
V_213 -> V_72 = F_72 ( V_232 ) ;
V_213 -> V_64 = F_72 ( V_233 ) ;
V_213 -> V_65 = F_72 ( V_234 ) ;
V_213 -> V_66 = F_72 ( V_235 ) ;
}
V_213 -> V_83 = F_108 ( V_143 ) ;
V_213 -> V_71 = F_72 ( F_109 ( V_143 -> V_220 ) ) ;
V_213 -> V_63 = F_110 ( V_143 ) ;
V_213 -> V_81 = F_111 ( V_143 ) ;
V_213 -> V_82 = V_143 -> V_236 ;
V_213 -> V_22 = F_112 ( V_143 ) ;
V_213 -> V_58 = F_113 ( V_143 ) ;
V_213 -> V_59 = F_114 ( V_143 ) ;
V_213 -> V_60 = F_115 ( V_143 ) ;
if ( F_116 ( V_99 ) ) {
T_8 V_237 ;
if ( F_35 ( V_99 ) ) {
switch ( V_143 -> V_206 ) {
default:
case V_2 :
V_237 = V_238 ;
break;
case V_4 :
V_237 = V_239 ;
break;
case V_3 :
V_237 = V_240 ;
break;
case V_5 :
V_237 = V_241 ;
break;
}
} else if ( F_117 ( V_143 -> V_41 ) ) {
V_237 = F_118 ( V_143 -> V_220 ) ;
} else {
V_237 = F_119 ( V_143 -> V_220 ) ;
}
V_213 -> V_61 = F_72 ( V_237 ) ;
}
V_213 -> V_87 = V_143 -> V_242 . V_243 ;
V_213 -> V_86 = V_143 -> V_242 . V_244 ;
if ( F_23 ( V_99 ) ) {
int V_33 ;
V_213 -> V_77 . V_78 = F_72 ( F_120 ( V_143 ) ) ;
if ( F_117 ( V_99 ) )
V_213 -> V_77 . V_80 =
F_72 ( F_121 ( V_143 ) ) ;
else if ( F_35 ( V_99 ) )
V_213 -> V_77 . V_80 =
F_72 ( F_122 ( V_143 ) ) ;
else if ( F_78 ( V_99 ) >= 8 )
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ ) {
V_213 -> V_77 . V_79 [ V_33 ] =
F_72 ( F_123 ( V_143 , V_33 ) ) ;
V_213 -> V_77 . V_79 [ V_33 ] <<= 32 ;
V_213 -> V_77 . V_79 [ V_33 ] |=
F_72 ( F_124 ( V_143 , V_33 ) ) ;
}
}
}
static void F_125 ( struct V_158 * V_143 ,
struct V_54 * error ,
struct V_56 * V_213 )
{
struct V_98 * V_99 = V_143 -> V_41 ;
struct V_174 * V_89 ;
if ( V_143 -> V_206 != V_2 || ! error -> V_127 )
return;
F_66 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_126 ( V_89 ) )
continue;
if ( ( error -> V_127 & V_245 ) == F_50 ( V_89 ) ) {
V_213 -> V_162 = F_82 ( V_99 , V_89 ) ;
break;
}
}
}
static void F_127 ( struct V_98 * V_99 ,
struct V_54 * error )
{
struct V_178 * V_179 = & V_99 -> V_179 ;
struct V_246 * V_247 ;
int V_33 , V_32 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
struct V_158 * V_143 = & V_99 -> V_143 [ V_33 ] ;
error -> V_1 [ V_33 ] . V_107 = - 1 ;
if ( ! F_128 ( V_143 ) )
continue;
error -> V_1 [ V_33 ] . V_57 = true ;
F_96 ( V_99 , error , V_143 , & error -> V_1 [ V_33 ] ) ;
F_90 ( V_143 , & error -> V_1 [ V_33 ] ) ;
V_247 = F_129 ( V_143 ) ;
if ( V_247 ) {
struct V_176 * V_177 ;
struct V_248 * V_227 ;
V_177 = V_247 -> V_162 -> V_249 ?
& V_247 -> V_162 -> V_249 -> V_186 : & V_179 -> V_186 ;
error -> V_1 [ V_33 ] . V_142 =
F_45 ( V_99 ,
V_247 -> V_250 ,
V_177 ) ;
if ( F_130 ( V_99 ) )
error -> V_1 [ V_33 ] . V_144 =
F_82 ( V_99 ,
V_143 -> V_251 . V_89 ) ;
if ( V_247 -> V_107 ) {
struct V_252 * V_253 ;
F_131 () ;
V_253 = F_132 ( V_247 -> V_107 , V_254 ) ;
if ( V_253 ) {
strcpy ( error -> V_1 [ V_33 ] . V_108 , V_253 -> V_108 ) ;
error -> V_1 [ V_33 ] . V_107 = V_253 -> V_107 ;
}
F_133 () ;
}
error -> V_255 |=
V_247 -> V_162 -> V_195 & V_256 ;
V_227 = V_247 -> V_257 ;
error -> V_1 [ V_33 ] . V_84 = V_227 -> V_58 ;
error -> V_1 [ V_33 ] . V_85 = V_227 -> V_59 ;
error -> V_1 [ V_33 ] . V_150 =
F_82 ( V_99 ,
V_227 -> V_89 ) ;
}
error -> V_1 [ V_33 ] . V_151 =
F_82 ( V_99 ,
V_143 -> V_258 . V_89 ) ;
if ( V_143 -> V_155 . V_89 ) {
error -> V_1 [ V_33 ] . V_155 =
F_82 ( V_99 ,
V_143 -> V_155 . V_89 ) ;
}
F_125 ( V_143 , error , & error -> V_1 [ V_33 ] ) ;
V_32 = 0 ;
F_66 (request, &engine->request_list, list)
V_32 ++ ;
error -> V_1 [ V_33 ] . V_145 = V_32 ;
error -> V_1 [ V_33 ] . V_146 =
F_134 ( V_32 , sizeof( * error -> V_1 [ V_33 ] . V_146 ) ,
V_188 ) ;
if ( error -> V_1 [ V_33 ] . V_146 == NULL ) {
error -> V_1 [ V_33 ] . V_145 = 0 ;
continue;
}
V_32 = 0 ;
F_66 (request, &engine->request_list, list) {
struct V_259 * V_260 ;
if ( V_32 >= error -> V_1 [ V_33 ] . V_145 ) {
break;
}
V_260 = & error -> V_1 [ V_33 ] . V_146 [ V_32 ++ ] ;
V_260 -> V_81 = V_247 -> V_81 ;
V_260 -> V_147 = V_247 -> V_261 ;
V_260 -> V_59 = V_247 -> V_262 ;
}
}
}
static void F_135 ( struct V_98 * V_99 ,
struct V_54 * error ,
struct V_176 * V_177 ,
const int V_263 )
{
struct V_31 * V_138 = NULL , * V_140 = NULL ;
struct V_174 * V_89 ;
struct V_181 * V_182 ;
int V_33 ;
V_33 = 0 ;
F_66 (vma, &vm->active_list, vm_link)
V_33 ++ ;
error -> V_139 [ V_263 ] = V_33 ;
F_66 (obj, &dev_priv->mm.bound_list, global_list) {
F_66 (vma, &obj->vma_list, obj_link)
if ( V_182 -> V_177 == V_177 && V_182 -> V_210 > 0 )
V_33 ++ ;
}
error -> V_141 [ V_263 ] = V_33 - error -> V_139 [ V_263 ] ;
if ( V_33 ) {
V_138 = F_134 ( V_33 , sizeof( * V_138 ) , V_188 ) ;
if ( V_138 )
V_140 = V_138 + error -> V_139 [ V_263 ] ;
}
if ( V_138 )
error -> V_139 [ V_263 ] =
F_65 ( V_138 ,
error -> V_139 [ V_263 ] ,
& V_177 -> V_264 ) ;
if ( V_140 )
error -> V_141 [ V_263 ] =
F_67 ( V_140 ,
error -> V_141 [ V_263 ] ,
& V_99 -> V_205 . V_265 , V_177 ) ;
error -> V_138 [ V_263 ] = V_138 ;
error -> V_140 [ V_263 ] = V_140 ;
}
static void F_136 ( struct V_98 * V_99 ,
struct V_54 * error )
{
struct V_176 * V_177 ;
int V_266 = 0 , V_33 = 0 ;
F_66 (vm, &dev_priv->vm_list, global_link)
V_266 ++ ;
error -> V_138 = F_134 ( V_266 , sizeof( * error -> V_138 ) , V_188 ) ;
error -> V_140 = F_134 ( V_266 , sizeof( * error -> V_140 ) , V_188 ) ;
error -> V_139 = F_134 ( V_266 , sizeof( * error -> V_139 ) ,
V_188 ) ;
error -> V_141 = F_134 ( V_266 , sizeof( * error -> V_141 ) ,
V_188 ) ;
if ( error -> V_138 == NULL ||
error -> V_140 == NULL ||
error -> V_139 == NULL ||
error -> V_141 == NULL ) {
F_41 ( error -> V_138 ) ;
F_41 ( error -> V_139 ) ;
F_41 ( error -> V_140 ) ;
F_41 ( error -> V_141 ) ;
error -> V_138 = NULL ;
error -> V_139 = NULL ;
error -> V_140 = NULL ;
error -> V_141 = NULL ;
} else {
F_66 (vm, &dev_priv->vm_list, global_link)
F_135 ( V_99 , error , V_177 , V_33 ++ ) ;
error -> V_137 = V_266 ;
}
}
static void F_137 ( struct V_98 * V_99 ,
struct V_54 * error )
{
struct V_52 * V_53 = & V_99 -> V_267 ;
int V_33 ;
if ( F_34 ( V_53 ) ) {
error -> V_123 [ 0 ] = F_72 ( V_268 ) ;
error -> V_122 = F_72 ( V_269 ) ;
error -> V_125 = F_138 ( V_270 ) ;
}
if ( F_35 ( V_53 ) )
error -> V_136 = F_72 ( V_271 ) ;
if ( F_21 ( V_53 ) -> V_67 >= 8 ) {
error -> V_134 = F_72 ( V_272 ) ;
error -> V_133 = F_72 ( V_273 ) ;
}
if ( F_117 ( V_53 ) ) {
error -> V_125 = F_138 ( V_274 ) ;
error -> V_275 = F_72 ( V_276 ) ;
error -> V_78 = F_72 ( V_277 ) ;
}
if ( F_21 ( V_53 ) -> V_67 >= 7 )
error -> V_125 = F_138 ( V_278 ) ;
if ( F_21 ( V_53 ) -> V_67 >= 6 ) {
error -> V_126 = F_72 ( V_279 ) ;
error -> error = F_72 ( V_280 ) ;
error -> V_135 = F_72 ( V_281 ) ;
}
if ( F_117 ( V_53 ) || F_35 ( V_53 ) ) {
error -> V_282 = F_72 ( V_283 ) ;
error -> V_284 = F_72 ( V_285 ) ;
}
if ( F_139 ( V_53 ) )
error -> V_127 = F_72 ( V_286 ) ;
if ( F_21 ( V_53 ) -> V_67 >= 8 ) {
error -> V_122 = F_72 ( V_287 ) ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
error -> V_123 [ V_33 ] = F_72 ( F_140 ( V_33 ) ) ;
} else if ( F_33 ( V_53 ) ) {
error -> V_122 = F_72 ( V_288 ) ;
error -> V_123 [ 0 ] = F_72 ( V_268 ) ;
} else if ( F_71 ( V_53 ) ) {
error -> V_122 = F_141 ( V_289 ) ;
} else if ( ! F_34 ( V_53 ) ) {
error -> V_122 = F_72 ( V_289 ) ;
}
error -> V_121 = F_72 ( V_290 ) ;
error -> V_124 = F_72 ( V_291 ) ;
F_142 ( V_99 , error -> V_132 ) ;
}
static void F_143 ( struct V_98 * V_99 ,
struct V_54 * error ,
V_62 V_292 ,
const char * V_103 )
{
V_62 V_293 ;
int V_211 = - 1 , V_20 ;
V_293 = F_68 ( V_99 , error , & V_211 ) ;
V_20 = F_144 ( error -> V_103 , sizeof( error -> V_103 ) ,
L_103 ,
F_78 ( V_99 ) , V_211 , V_293 ) ;
if ( V_211 != - 1 && error -> V_1 [ V_211 ] . V_107 != - 1 )
V_20 += F_144 ( error -> V_103 + V_20 ,
sizeof( error -> V_103 ) - V_20 ,
L_104 ,
error -> V_1 [ V_211 ] . V_108 ,
error -> V_1 [ V_211 ] . V_107 ) ;
F_144 ( error -> V_103 + V_20 , sizeof( error -> V_103 ) - V_20 ,
L_105 ,
V_103 ,
V_292 ? L_106 : L_107 ) ;
}
static void F_145 ( struct V_98 * V_99 ,
struct V_54 * error )
{
error -> V_116 = - 1 ;
#ifdef F_146
error -> V_116 = V_294 ;
#endif
error -> V_109 = F_147 ( & V_99 -> V_128 ) ;
error -> V_110 = V_99 -> V_110 ;
}
void F_148 ( struct V_98 * V_99 ,
V_62 V_292 ,
const char * V_103 )
{
static bool V_295 ;
struct V_54 * error ;
unsigned long V_195 ;
if ( F_149 ( V_99 -> V_128 . V_296 ) )
return;
error = F_150 ( sizeof( * error ) , V_188 ) ;
if ( ! error ) {
F_151 ( L_108 ) ;
return;
}
F_152 ( & error -> V_173 ) ;
F_145 ( V_99 , error ) ;
F_137 ( V_99 , error ) ;
F_136 ( V_99 , error ) ;
F_69 ( V_99 , error ) ;
F_127 ( V_99 , error ) ;
F_153 ( & error -> time ) ;
error -> V_164 = F_154 ( V_99 ) ;
error -> V_165 = F_155 ( V_99 ) ;
F_143 ( V_99 , error , V_292 , V_103 ) ;
F_156 ( L_60 , error -> V_103 ) ;
if ( ! error -> V_255 ) {
F_157 ( & V_99 -> V_128 . V_228 , V_195 ) ;
if ( ! V_99 -> V_128 . V_296 ) {
V_99 -> V_128 . V_296 = error ;
error = NULL ;
}
F_158 ( & V_99 -> V_128 . V_228 , V_195 ) ;
}
if ( error ) {
F_42 ( & error -> V_173 ) ;
return;
}
if ( ! V_295 ) {
F_156 ( L_109 ) ;
F_156 ( L_110 ) ;
F_156 ( L_111 ) ;
F_156 ( L_112 ) ;
F_156 ( L_113 ,
V_99 -> V_267 . V_297 -> V_298 ) ;
V_295 = true ;
}
}
void F_159 ( struct V_52 * V_53 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = F_28 ( V_53 ) ;
F_160 ( & V_99 -> V_128 . V_228 ) ;
V_97 -> error = V_99 -> V_128 . V_296 ;
if ( V_97 -> error )
F_161 ( & V_97 -> error -> V_173 ) ;
F_162 ( & V_99 -> V_128 . V_228 ) ;
}
void F_163 ( struct V_96 * V_97 )
{
if ( V_97 -> error )
F_164 ( & V_97 -> error -> V_173 , F_42 ) ;
}
void F_165 ( struct V_52 * V_53 )
{
struct V_98 * V_99 = F_28 ( V_53 ) ;
struct V_54 * error ;
F_160 ( & V_99 -> V_128 . V_228 ) ;
error = V_99 -> V_128 . V_296 ;
V_99 -> V_128 . V_296 = NULL ;
F_162 ( & V_99 -> V_128 . V_228 ) ;
if ( error )
F_164 ( & error -> V_173 , F_42 ) ;
}
const char * F_18 ( struct V_98 * V_41 , int type )
{
switch ( type ) {
case V_189 : return L_114 ;
case V_299 : return F_51 ( V_41 ) ? L_115 : L_116 ;
case V_300 : return L_117 ;
case V_301 : return L_118 ;
default: return L_6 ;
}
}
void F_142 ( struct V_98 * V_99 ,
T_6 * V_66 )
{
memset ( V_66 , 0 , sizeof( * V_66 ) * V_302 ) ;
if ( F_71 ( V_99 ) || F_70 ( V_99 ) )
V_66 [ 0 ] = F_72 ( V_235 ) ;
else if ( F_75 ( V_99 ) || F_74 ( V_99 ) || F_117 ( V_99 ) ) {
V_66 [ 0 ] = F_72 ( F_102 ( V_303 ) ) ;
V_66 [ 1 ] = F_72 ( V_304 ) ;
} else if ( F_78 ( V_99 ) >= 7 ) {
V_66 [ 0 ] = F_72 ( F_102 ( V_303 ) ) ;
V_66 [ 1 ] = F_72 ( V_305 ) ;
V_66 [ 2 ] = F_72 ( V_306 ) ;
V_66 [ 3 ] = F_72 ( V_307 ) ;
}
}
