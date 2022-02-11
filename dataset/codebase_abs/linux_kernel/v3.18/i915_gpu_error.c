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
F_16 ( V_30 , F_17 ( V_30 -> V_40 , V_17 -> V_41 ) ) ;
if ( V_17 -> V_31 )
F_15 ( V_30 , L_20 , V_17 -> V_31 ) ;
if ( V_17 -> V_42 != V_43 )
F_15 ( V_30 , L_21 , V_17 -> V_42 ) ;
F_16 ( V_30 , L_22 ) ;
V_17 ++ ;
}
}
static const char * F_18 ( enum V_44 V_45 )
{
switch ( V_45 ) {
case V_46 :
return L_23 ;
case V_47 :
return L_24 ;
case V_48 :
return L_25 ;
case V_49 :
return L_26 ;
case V_50 :
return L_27 ;
case V_51 :
return L_28 ;
}
return L_29 ;
}
static void F_19 ( struct V_15 * V_30 ,
struct V_52 * V_53 ,
struct V_54 * V_2 )
{
if ( ! V_2 -> V_55 )
return;
F_15 ( V_30 , L_30 , V_2 -> V_56 ) ;
F_15 ( V_30 , L_31 , V_2 -> V_57 ) ;
F_15 ( V_30 , L_32 , V_2 -> V_58 ) ;
F_15 ( V_30 , L_33 , V_2 -> V_59 ) ;
F_15 ( V_30 , L_34 , ( V_60 ) ( V_2 -> V_61 >> 32 ) , ( V_60 ) V_2 -> V_61 ) ;
F_15 ( V_30 , L_35 , V_2 -> V_62 ) ;
F_15 ( V_30 , L_36 , V_2 -> V_63 ) ;
F_15 ( V_30 , L_37 , V_2 -> V_64 ) ;
if ( F_20 ( V_53 ) -> V_65 >= 4 ) {
F_15 ( V_30 , L_38 , ( V_60 ) ( V_2 -> V_66 >> 32 ) , ( V_60 ) V_2 -> V_66 ) ;
F_15 ( V_30 , L_39 , V_2 -> V_67 ) ;
F_15 ( V_30 , L_40 , V_2 -> V_68 ) ;
}
F_15 ( V_30 , L_41 , V_2 -> V_69 ) ;
F_15 ( V_30 , L_42 , F_21 ( V_2 -> V_70 ) ,
F_22 ( V_2 -> V_70 ) ) ;
if ( F_20 ( V_53 ) -> V_65 >= 6 ) {
F_15 ( V_30 , L_43 , V_2 -> V_71 ) ;
F_15 ( V_30 , L_44 , V_2 -> V_72 ) ;
F_15 ( V_30 , L_45 ,
V_2 -> V_73 [ 0 ] ,
V_2 -> V_74 [ 0 ] ) ;
F_15 ( V_30 , L_46 ,
V_2 -> V_73 [ 1 ] ,
V_2 -> V_74 [ 1 ] ) ;
if ( F_23 ( V_53 ) ) {
F_15 ( V_30 , L_47 ,
V_2 -> V_73 [ 2 ] ,
V_2 -> V_74 [ 2 ] ) ;
}
}
if ( F_24 ( V_53 ) ) {
F_15 ( V_30 , L_48 , V_2 -> V_75 . V_76 ) ;
if ( F_20 ( V_53 ) -> V_65 >= 8 ) {
int V_77 ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ )
F_15 ( V_30 , L_49 ,
V_77 , V_2 -> V_75 . V_78 [ V_77 ] ) ;
} else {
F_15 ( V_30 , L_50 ,
V_2 -> V_75 . V_79 ) ;
}
}
F_15 ( V_30 , L_51 , V_2 -> V_80 ) ;
F_15 ( V_30 , L_52 , F_1 ( V_2 -> V_81 ) ) ;
F_15 ( V_30 , L_53 , V_2 -> V_82 ) ;
F_15 ( V_30 , L_54 , V_2 -> V_83 ) ;
F_15 ( V_30 , L_55 ,
F_18 ( V_2 -> V_84 ) ,
V_2 -> V_85 ) ;
}
void F_25 ( struct V_15 * V_16 , const char * V_27 , ... )
{
T_2 args ;
va_start ( args , V_27 ) ;
F_11 ( V_16 , V_27 , args ) ;
va_end ( args ) ;
}
static void F_26 ( struct V_15 * V_30 ,
struct V_86 * V_87 )
{
int V_88 , V_89 , V_90 ;
for ( V_88 = V_89 = 0 ; V_88 < V_87 -> V_91 ; V_88 ++ ) {
for ( V_90 = 0 ; V_90 < V_92 / 4 ; V_90 ++ ) {
F_15 ( V_30 , L_56 , V_89 ,
V_87 -> V_93 [ V_88 ] [ V_90 ] ) ;
V_89 += 4 ;
}
}
}
int F_27 ( struct V_15 * V_30 ,
const struct V_94 * V_95 )
{
struct V_52 * V_53 = V_95 -> V_53 ;
struct V_96 * V_97 = V_53 -> V_98 ;
struct V_99 * error = V_95 -> error ;
struct V_86 * V_87 ;
int V_77 , V_100 , V_89 , V_90 ;
int V_101 ;
if ( ! error ) {
F_15 ( V_30 , L_57 ) ;
goto V_102;
}
F_15 ( V_30 , L_58 , error -> V_103 ) ;
F_15 ( V_30 , L_59 , error -> time . V_104 ,
error -> time . V_105 ) ;
F_15 ( V_30 , L_60 V_106 L_22 ) ;
V_101 = 0 ;
for ( V_77 = 0 ; V_77 < F_28 ( error -> V_2 ) ; V_77 ++ ) {
if ( error -> V_2 [ V_77 ] . V_85 > V_101 )
V_101 = error -> V_2 [ V_77 ] . V_85 ;
}
for ( V_77 = 0 ; V_77 < F_28 ( error -> V_2 ) ; V_77 ++ ) {
if ( error -> V_2 [ V_77 ] . V_85 == V_101 &&
error -> V_2 [ V_77 ] . V_107 != - 1 ) {
F_15 ( V_30 , L_61 ,
F_2 ( V_77 ) ,
error -> V_2 [ V_77 ] . V_108 ,
error -> V_2 [ V_77 ] . V_107 ) ;
}
}
F_15 ( V_30 , L_62 , error -> V_109 ) ;
F_15 ( V_30 , L_63 , error -> V_110 ) ;
F_15 ( V_30 , L_64 , V_53 -> V_111 -> V_112 ) ;
F_15 ( V_30 , L_65 , error -> V_113 ) ;
F_15 ( V_30 , L_66 , error -> V_114 ) ;
if ( F_20 ( V_53 ) -> V_65 >= 8 ) {
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ )
F_15 ( V_30 , L_67 , V_77 ,
error -> V_115 [ V_77 ] ) ;
} else if ( F_29 ( V_53 ) || F_30 ( V_53 ) )
F_15 ( V_30 , L_68 , error -> V_115 [ 0 ] ) ;
F_15 ( V_30 , L_69 , error -> V_116 ) ;
F_15 ( V_30 , L_70 , error -> V_117 ) ;
F_15 ( V_30 , L_71 , error -> V_118 ) ;
F_15 ( V_30 , L_72 , error -> V_119 ) ;
F_15 ( V_30 , L_73 , V_97 -> V_120 . V_121 ) ;
for ( V_77 = 0 ; V_77 < V_97 -> V_122 ; V_77 ++ )
F_15 ( V_30 , L_74 , V_77 , error -> V_123 [ V_77 ] ) ;
for ( V_77 = 0 ; V_77 < F_28 ( error -> V_124 ) ; V_77 ++ )
F_15 ( V_30 , L_75 , V_77 ,
error -> V_124 [ V_77 ] ) ;
if ( F_20 ( V_53 ) -> V_65 >= 6 ) {
F_15 ( V_30 , L_76 , error -> error ) ;
F_15 ( V_30 , L_77 , error -> V_125 ) ;
}
if ( F_20 ( V_53 ) -> V_65 == 7 )
F_15 ( V_30 , L_78 , error -> V_126 ) ;
for ( V_77 = 0 ; V_77 < F_28 ( error -> V_2 ) ; V_77 ++ ) {
F_15 ( V_30 , L_79 , F_2 ( V_77 ) ) ;
F_19 ( V_30 , V_53 , & error -> V_2 [ V_77 ] ) ;
}
for ( V_77 = 0 ; V_77 < error -> V_127 ; V_77 ++ ) {
F_15 ( V_30 , L_80 , V_77 ) ;
F_14 ( V_30 , L_81 ,
error -> V_128 [ V_77 ] ,
error -> V_129 [ V_77 ] ) ;
F_14 ( V_30 , L_82 ,
error -> V_130 [ V_77 ] ,
error -> V_131 [ V_77 ] ) ;
}
for ( V_77 = 0 ; V_77 < F_28 ( error -> V_2 ) ; V_77 ++ ) {
V_87 = error -> V_2 [ V_77 ] . V_132 ;
if ( V_87 ) {
F_16 ( V_30 , V_97 -> V_2 [ V_77 ] . V_31 ) ;
if ( error -> V_2 [ V_77 ] . V_107 != - 1 )
F_15 ( V_30 , L_83 ,
error -> V_2 [ V_77 ] . V_108 ,
error -> V_2 [ V_77 ] . V_107 ) ;
F_15 ( V_30 , L_84 ,
V_87 -> V_34 ) ;
F_26 ( V_30 , V_87 ) ;
}
V_87 = error -> V_2 [ V_77 ] . V_133 ;
if ( V_87 ) {
F_15 ( V_30 , L_85 ,
V_97 -> V_2 [ V_77 ] . V_31 , V_87 -> V_34 ) ;
F_26 ( V_30 , V_87 ) ;
}
if ( error -> V_2 [ V_77 ] . V_134 ) {
F_15 ( V_30 , L_86 ,
V_97 -> V_2 [ V_77 ] . V_31 ,
error -> V_2 [ V_77 ] . V_134 ) ;
for ( V_100 = 0 ; V_100 < error -> V_2 [ V_77 ] . V_134 ; V_100 ++ ) {
F_15 ( V_30 , L_87 ,
error -> V_2 [ V_77 ] . V_135 [ V_100 ] . V_80 ,
error -> V_2 [ V_77 ] . V_135 [ V_100 ] . V_136 ,
error -> V_2 [ V_77 ] . V_135 [ V_100 ] . V_57 ) ;
}
}
if ( ( V_87 = error -> V_2 [ V_77 ] . V_137 ) ) {
F_15 ( V_30 , L_88 ,
V_97 -> V_2 [ V_77 ] . V_31 ,
V_87 -> V_34 ) ;
F_26 ( V_30 , V_87 ) ;
}
if ( ( V_87 = error -> V_2 [ V_77 ] . V_138 ) ) {
F_15 ( V_30 , L_89 ,
V_97 -> V_2 [ V_77 ] . V_31 ,
V_87 -> V_34 ) ;
V_89 = 0 ;
for ( V_90 = 0 ; V_90 < V_92 / 16 ; V_90 += 4 ) {
F_15 ( V_30 , L_90 ,
V_89 ,
V_87 -> V_93 [ 0 ] [ V_90 ] ,
V_87 -> V_93 [ 0 ] [ V_90 + 1 ] ,
V_87 -> V_93 [ 0 ] [ V_90 + 2 ] ,
V_87 -> V_93 [ 0 ] [ V_90 + 3 ] ) ;
V_89 += 16 ;
}
}
if ( ( V_87 = error -> V_2 [ V_77 ] . V_139 ) ) {
F_15 ( V_30 , L_91 ,
V_97 -> V_2 [ V_77 ] . V_31 ,
V_87 -> V_34 ) ;
F_26 ( V_30 , V_87 ) ;
}
}
if ( ( V_87 = error -> V_140 ) ) {
F_15 ( V_30 , L_92 , V_87 -> V_34 ) ;
for ( V_90 = 0 ; V_90 < V_92 / 16 ; V_90 += 4 ) {
F_15 ( V_30 , L_90 ,
V_90 * 4 ,
V_87 -> V_93 [ 0 ] [ V_90 ] ,
V_87 -> V_93 [ 0 ] [ V_90 + 1 ] ,
V_87 -> V_93 [ 0 ] [ V_90 + 2 ] ,
V_87 -> V_93 [ 0 ] [ V_90 + 3 ] ) ;
}
}
if ( error -> V_141 )
F_31 ( V_30 , error -> V_141 ) ;
if ( error -> V_142 )
F_32 ( V_30 , V_53 , error -> V_142 ) ;
V_102:
if ( V_30 -> V_18 == 0 && V_30 -> V_17 )
return V_30 -> V_17 ;
return 0 ;
}
int F_33 ( struct V_15 * V_143 ,
struct V_96 * V_40 ,
T_1 V_33 , T_3 V_22 )
{
memset ( V_143 , 0 , sizeof( * V_143 ) ) ;
V_143 -> V_40 = V_40 ;
V_143 -> V_19 = V_33 + 1 > V_92 ? V_33 + 1 : V_92 ;
V_143 -> V_26 = F_34 ( V_143 -> V_19 ,
V_144 | V_145 | V_146 ) ;
if ( V_143 -> V_26 == NULL ) {
V_143 -> V_19 = V_92 ;
V_143 -> V_26 = F_34 ( V_143 -> V_19 , V_144 ) ;
}
if ( V_143 -> V_26 == NULL ) {
V_143 -> V_19 = 128 ;
V_143 -> V_26 = F_34 ( V_143 -> V_19 , V_144 ) ;
}
if ( V_143 -> V_26 == NULL )
return - V_147 ;
V_143 -> V_23 = V_22 ;
return 0 ;
}
static void F_35 ( struct V_86 * V_87 )
{
int V_88 ;
if ( V_87 == NULL )
return;
for ( V_88 = 0 ; V_88 < V_87 -> V_91 ; V_88 ++ )
F_36 ( V_87 -> V_93 [ V_88 ] ) ;
F_36 ( V_87 ) ;
}
static void F_37 ( struct V_148 * V_149 )
{
struct V_99 * error = F_38 ( V_149 ,
F_39 ( * error ) , V_150 ) ;
int V_77 ;
for ( V_77 = 0 ; V_77 < F_28 ( error -> V_2 ) ; V_77 ++ ) {
F_35 ( error -> V_2 [ V_77 ] . V_132 ) ;
F_35 ( error -> V_2 [ V_77 ] . V_137 ) ;
F_35 ( error -> V_2 [ V_77 ] . V_138 ) ;
F_35 ( error -> V_2 [ V_77 ] . V_139 ) ;
F_36 ( error -> V_2 [ V_77 ] . V_135 ) ;
}
F_35 ( error -> V_140 ) ;
F_36 ( error -> V_128 ) ;
F_36 ( error -> V_141 ) ;
F_36 ( error -> V_142 ) ;
F_36 ( error ) ;
}
static struct V_86 *
F_40 ( struct V_96 * V_97 ,
struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_86 * V_155 ;
int V_156 ;
bool V_157 ;
int V_77 = 0 ;
V_60 V_158 ;
if ( V_152 == NULL || V_152 -> V_93 == NULL )
return NULL ;
V_156 = V_152 -> V_159 . V_19 >> V_160 ;
V_155 = F_34 ( sizeof( * V_155 ) + V_156 * sizeof( V_60 * ) , V_161 ) ;
if ( V_155 == NULL )
return NULL ;
if ( F_41 ( V_152 , V_154 ) )
V_155 -> V_34 = F_42 ( V_152 , V_154 ) ;
else
V_155 -> V_34 = - 1 ;
V_158 = V_155 -> V_34 ;
V_157 = ( V_152 -> V_41 == V_162 &&
F_43 ( V_154 ) &&
V_152 -> V_163 &&
V_158 + V_156 * V_92 <= V_97 -> V_164 . V_165 ) ;
if ( V_152 -> V_166 ) {
V_157 = true ;
if ( ! V_152 -> V_163 )
goto V_167;
V_158 = F_44 ( V_152 ) ;
if ( V_158 + V_156 * V_92 > V_97 -> V_164 . V_165 )
goto V_167;
}
if ( V_157 && V_152 -> V_41 != V_162 && ! F_45 ( V_97 -> V_53 ) )
goto V_167;
V_155 -> V_91 = V_156 ;
while ( V_156 -- ) {
unsigned long V_168 ;
void * V_169 ;
V_169 = F_34 ( V_92 , V_161 ) ;
if ( V_169 == NULL )
goto V_167;
F_46 ( V_168 ) ;
if ( V_157 ) {
void T_4 * V_170 ;
V_170 = F_47 ( V_97 -> V_164 . V_171 ,
V_158 ) ;
F_48 ( V_169 , V_170 , V_92 ) ;
F_49 ( V_170 ) ;
} else {
struct V_88 * V_88 ;
void * V_170 ;
V_88 = F_50 ( V_152 , V_77 ) ;
F_51 ( & V_88 , 1 ) ;
V_170 = F_52 ( V_88 ) ;
memcpy ( V_169 , V_170 , V_92 ) ;
F_53 ( V_170 ) ;
F_51 ( & V_88 , 1 ) ;
}
F_54 ( V_168 ) ;
V_155 -> V_93 [ V_77 ++ ] = V_169 ;
V_158 += V_92 ;
}
return V_155 ;
V_167:
while ( V_77 -- )
F_36 ( V_155 -> V_93 [ V_77 ] ) ;
F_36 ( V_155 ) ;
return NULL ;
}
static void F_55 ( struct V_32 * V_17 ,
struct V_172 * V_173 )
{
struct V_151 * V_87 = V_173 -> V_87 ;
V_17 -> V_19 = V_87 -> V_159 . V_19 ;
V_17 -> V_31 = V_87 -> V_159 . V_31 ;
V_17 -> V_37 = V_87 -> V_174 ;
V_17 -> V_38 = V_87 -> V_175 ;
V_17 -> V_34 = V_173 -> V_176 . V_23 ;
V_17 -> V_35 = V_87 -> V_159 . V_35 ;
V_17 -> V_36 = V_87 -> V_159 . V_36 ;
V_17 -> V_42 = V_87 -> V_42 ;
V_17 -> V_8 = 0 ;
if ( F_56 ( V_87 ) )
V_17 -> V_8 = 1 ;
if ( V_87 -> V_177 > 0 )
V_17 -> V_8 = - 1 ;
V_17 -> V_9 = V_87 -> V_178 ;
V_17 -> V_13 = V_87 -> V_13 ;
V_17 -> V_14 = V_87 -> V_179 != V_180 ;
V_17 -> V_39 = V_87 -> V_39 . V_181 != NULL ;
V_17 -> V_2 = V_87 -> V_2 ? V_87 -> V_2 -> V_182 : - 1 ;
V_17 -> V_41 = V_87 -> V_41 ;
}
static V_60 F_57 ( struct V_32 * V_17 ,
int V_33 , struct V_183 * V_56 )
{
struct V_172 * V_173 ;
int V_77 = 0 ;
F_58 (vma, head, mm_list) {
F_55 ( V_17 ++ , V_173 ) ;
if ( ++ V_77 == V_33 )
break;
}
return V_77 ;
}
static V_60 F_59 ( struct V_32 * V_17 ,
int V_33 , struct V_183 * V_56 ,
struct V_153 * V_154 )
{
struct V_151 * V_87 ;
struct V_32 * const V_184 = V_17 ;
struct V_32 * const V_185 = V_17 + V_33 ;
F_58 (obj, head, global_list) {
struct V_172 * V_173 ;
if ( V_17 == V_185 )
break;
F_58 (vma, &obj->vma_list, vma_link)
if ( V_173 -> V_154 == V_154 && V_173 -> V_186 > 0 ) {
F_55 ( V_17 ++ , V_173 ) ;
break;
}
}
return V_17 - V_184 ;
}
static T_5 F_60 ( struct V_96 * V_97 ,
struct V_99 * error ,
int * V_187 )
{
T_5 V_188 = 0 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_189 ; V_77 ++ ) {
if ( error -> V_2 [ V_77 ] . V_84 == V_51 ) {
if ( V_187 )
* V_187 = V_77 ;
return error -> V_2 [ V_77 ] . V_63 ^ error -> V_2 [ V_77 ] . V_64 ;
}
}
return V_188 ;
}
static void F_61 ( struct V_52 * V_53 ,
struct V_99 * error )
{
struct V_96 * V_97 = V_53 -> V_98 ;
int V_77 ;
switch ( F_20 ( V_53 ) -> V_65 ) {
case 8 :
case 7 :
case 6 :
for ( V_77 = 0 ; V_77 < V_97 -> V_122 ; V_77 ++ )
error -> V_123 [ V_77 ] = F_62 ( V_190 + ( V_77 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_77 = 0 ; V_77 < 16 ; V_77 ++ )
error -> V_123 [ V_77 ] = F_62 ( V_191 + ( V_77 * 8 ) ) ;
break;
case 3 :
if ( F_63 ( V_53 ) || F_64 ( V_53 ) || F_65 ( V_53 ) )
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ )
error -> V_123 [ V_77 + 8 ] = F_66 ( V_192 + ( V_77 * 4 ) ) ;
case 2 :
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ )
error -> V_123 [ V_77 ] = F_66 ( V_193 + ( V_77 * 4 ) ) ;
break;
default:
F_67 () ;
}
}
static void F_68 ( struct V_96 * V_97 ,
struct V_99 * error ,
struct V_194 * V_2 ,
struct V_54 * V_195 )
{
struct V_194 * V_196 ;
int V_77 ;
if ( ! F_69 ( V_97 -> V_53 ) )
return;
if ( ! error -> V_140 )
error -> V_140 =
F_40 ( V_97 ,
V_97 -> V_140 ,
& V_97 -> V_164 . V_159 ) ;
F_70 (to, dev_priv, i) {
int V_197 ;
T_6 V_198 ;
V_60 * V_28 ;
if ( V_2 == V_196 )
continue;
V_198 = ( F_71 ( V_2 , V_77 ) & ( V_92 - 1 ) )
/ 4 ;
V_28 = error -> V_140 -> V_93 [ 0 ] ;
V_197 = F_72 ( V_2 , V_196 ) ;
V_195 -> V_73 [ V_197 ] = V_28 [ V_198 ] ;
V_195 -> V_74 [ V_197 ] = V_2 -> V_199 . V_200 [ V_197 ] ;
}
}
static void F_73 ( struct V_96 * V_97 ,
struct V_194 * V_2 ,
struct V_54 * V_195 )
{
V_195 -> V_73 [ 0 ] = F_66 ( F_74 ( V_2 -> V_201 ) ) ;
V_195 -> V_73 [ 1 ] = F_66 ( F_75 ( V_2 -> V_201 ) ) ;
V_195 -> V_74 [ 0 ] = V_2 -> V_199 . V_200 [ 0 ] ;
V_195 -> V_74 [ 1 ] = V_2 -> V_199 . V_200 [ 1 ] ;
if ( F_23 ( V_97 -> V_53 ) ) {
V_195 -> V_73 [ 2 ] =
F_66 ( F_76 ( V_2 -> V_201 ) ) ;
V_195 -> V_74 [ 2 ] = V_2 -> V_199 . V_200 [ 2 ] ;
}
}
static void F_77 ( struct V_52 * V_53 ,
struct V_99 * error ,
struct V_194 * V_2 ,
struct V_54 * V_195 )
{
struct V_96 * V_97 = V_53 -> V_98 ;
if ( F_20 ( V_53 ) -> V_65 >= 6 ) {
V_195 -> V_71 = F_66 ( V_2 -> V_201 + 0x50 ) ;
V_195 -> V_72 = F_66 ( F_78 ( V_2 ) ) ;
if ( F_20 ( V_53 ) -> V_65 >= 8 )
F_68 ( V_97 , error , V_2 , V_195 ) ;
else
F_73 ( V_97 , V_2 , V_195 ) ;
}
if ( F_20 ( V_53 ) -> V_65 >= 4 ) {
V_195 -> V_70 = F_66 ( F_79 ( V_2 -> V_201 ) ) ;
V_195 -> V_62 = F_66 ( F_80 ( V_2 -> V_201 ) ) ;
V_195 -> V_63 = F_66 ( F_81 ( V_2 -> V_201 ) ) ;
V_195 -> V_64 = F_66 ( F_82 ( V_2 -> V_201 ) ) ;
V_195 -> V_68 = F_66 ( F_83 ( V_2 -> V_201 ) ) ;
V_195 -> V_66 = F_66 ( F_84 ( V_2 -> V_201 ) ) ;
if ( F_20 ( V_53 ) -> V_65 >= 8 ) {
V_195 -> V_70 |= ( V_202 ) F_66 ( F_85 ( V_2 -> V_201 ) ) << 32 ;
V_195 -> V_66 |= ( V_202 ) F_66 ( F_86 ( V_2 -> V_201 ) ) << 32 ;
}
V_195 -> V_67 = F_66 ( F_87 ( V_2 -> V_201 ) ) ;
} else {
V_195 -> V_70 = F_66 ( V_203 ) ;
V_195 -> V_62 = F_66 ( V_204 ) ;
V_195 -> V_63 = F_66 ( V_205 ) ;
V_195 -> V_64 = F_66 ( V_206 ) ;
}
V_195 -> V_81 = F_88 ( & V_2 -> V_207 ) ;
V_195 -> V_69 = F_66 ( F_89 ( V_2 -> V_201 ) ) ;
V_195 -> V_80 = V_2 -> V_208 ( V_2 , false ) ;
V_195 -> V_61 = F_90 ( V_2 ) ;
V_195 -> V_56 = F_91 ( V_2 ) ;
V_195 -> V_57 = F_92 ( V_2 ) ;
V_195 -> V_58 = F_93 ( V_2 ) ;
if ( F_94 ( V_53 ) ) {
int V_209 ;
if ( F_95 ( V_53 ) ) {
switch ( V_2 -> V_182 ) {
default:
case V_3 :
V_209 = V_210 ;
break;
case V_5 :
V_209 = V_211 ;
break;
case V_4 :
V_209 = V_212 ;
break;
case V_6 :
V_209 = V_213 ;
break;
}
} else if ( F_96 ( V_2 -> V_53 ) ) {
V_209 = F_97 ( V_2 -> V_201 ) ;
} else {
V_209 = F_98 ( V_2 -> V_201 ) ;
}
V_195 -> V_59 = F_66 ( V_209 ) ;
}
V_195 -> V_85 = V_2 -> V_214 . V_215 ;
V_195 -> V_84 = V_2 -> V_214 . V_216 ;
if ( F_24 ( V_53 ) ) {
int V_77 ;
V_195 -> V_75 . V_76 = F_66 ( F_99 ( V_2 ) ) ;
switch ( F_20 ( V_53 ) -> V_65 ) {
case 8 :
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
V_195 -> V_75 . V_78 [ V_77 ] =
F_66 ( F_100 ( V_2 , V_77 ) ) ;
V_195 -> V_75 . V_78 [ V_77 ] <<= 32 ;
V_195 -> V_75 . V_78 [ V_77 ] |=
F_66 ( F_101 ( V_2 , V_77 ) ) ;
}
break;
case 7 :
V_195 -> V_75 . V_79 =
F_66 ( F_102 ( V_2 ) ) ;
break;
case 6 :
V_195 -> V_75 . V_79 =
F_66 ( F_103 ( V_2 ) ) ;
break;
}
}
}
static void F_104 ( struct V_194 * V_2 ,
struct V_99 * error ,
struct V_54 * V_195 )
{
struct V_96 * V_97 = V_2 -> V_53 -> V_98 ;
struct V_151 * V_87 ;
if ( V_2 -> V_182 != V_3 || ! error -> V_119 )
return;
F_58 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_105 ( V_87 ) )
continue;
if ( ( error -> V_119 & V_217 ) == F_44 ( V_87 ) ) {
V_195 -> V_139 = F_106 ( V_97 , V_87 ) ;
break;
}
}
}
static void F_107 ( struct V_52 * V_53 ,
struct V_99 * error )
{
struct V_96 * V_97 = V_53 -> V_98 ;
struct V_218 * V_219 ;
int V_77 , V_33 ;
for ( V_77 = 0 ; V_77 < V_189 ; V_77 ++ ) {
struct V_194 * V_2 = & V_97 -> V_2 [ V_77 ] ;
struct V_220 * V_221 ;
error -> V_2 [ V_77 ] . V_107 = - 1 ;
if ( V_2 -> V_53 == NULL )
continue;
error -> V_2 [ V_77 ] . V_55 = true ;
F_77 ( V_53 , error , V_2 , & error -> V_2 [ V_77 ] ) ;
V_219 = F_108 ( V_2 ) ;
if ( V_219 ) {
struct V_153 * V_154 ;
V_154 = V_219 -> V_139 && V_219 -> V_139 -> V_222 ?
& V_219 -> V_139 -> V_222 -> V_159 :
& V_97 -> V_164 . V_159 ;
error -> V_2 [ V_77 ] . V_132 =
F_40 ( V_97 ,
V_219 -> V_223 ,
V_154 ) ;
if ( F_109 ( V_97 -> V_53 ) )
error -> V_2 [ V_77 ] . V_133 =
F_106 ( V_97 ,
V_2 -> V_224 . V_87 ) ;
if ( V_219 -> V_225 ) {
struct V_226 * V_227 ;
F_110 () ;
V_227 = F_111 ( V_219 -> V_225 -> V_228 -> V_107 ,
V_229 ) ;
if ( V_227 ) {
strcpy ( error -> V_2 [ V_77 ] . V_108 , V_227 -> V_108 ) ;
error -> V_2 [ V_77 ] . V_107 = V_227 -> V_107 ;
}
F_112 () ;
}
}
if ( V_40 . V_230 ) {
if ( V_219 )
V_221 = V_219 -> V_139 -> V_231 [ V_2 -> V_182 ] . V_232 ;
else
V_221 = V_2 -> V_233 -> V_231 [ V_2 -> V_182 ] . V_232 ;
} else
V_221 = V_2 -> V_234 ;
error -> V_2 [ V_77 ] . V_82 = V_221 -> V_56 ;
error -> V_2 [ V_77 ] . V_83 = V_221 -> V_57 ;
error -> V_2 [ V_77 ] . V_137 =
F_106 ( V_97 , V_221 -> V_87 ) ;
error -> V_2 [ V_77 ] . V_138 =
F_106 ( V_97 , V_2 -> V_235 . V_87 ) ;
F_104 ( V_2 , error , & error -> V_2 [ V_77 ] ) ;
V_33 = 0 ;
F_58 (request, &ring->request_list, list)
V_33 ++ ;
error -> V_2 [ V_77 ] . V_134 = V_33 ;
error -> V_2 [ V_77 ] . V_135 =
F_113 ( V_33 , sizeof( * error -> V_2 [ V_77 ] . V_135 ) ,
V_161 ) ;
if ( error -> V_2 [ V_77 ] . V_135 == NULL ) {
error -> V_2 [ V_77 ] . V_134 = 0 ;
continue;
}
V_33 = 0 ;
F_58 (request, &ring->request_list, list) {
struct V_236 * V_237 ;
V_237 = & error -> V_2 [ V_77 ] . V_135 [ V_33 ++ ] ;
V_237 -> V_80 = V_219 -> V_80 ;
V_237 -> V_136 = V_219 -> V_238 ;
V_237 -> V_57 = V_219 -> V_57 ;
}
}
}
static void F_114 ( struct V_96 * V_97 ,
struct V_99 * error ,
struct V_153 * V_154 ,
const int V_239 )
{
struct V_32 * V_128 = NULL , * V_130 = NULL ;
struct V_151 * V_87 ;
struct V_172 * V_173 ;
int V_77 ;
V_77 = 0 ;
F_58 (vma, &vm->active_list, mm_list)
V_77 ++ ;
error -> V_129 [ V_239 ] = V_77 ;
F_58 (obj, &dev_priv->mm.bound_list, global_list) {
F_58 (vma, &obj->vma_list, vma_link)
if ( V_173 -> V_154 == V_154 && V_173 -> V_186 > 0 ) {
V_77 ++ ;
break;
}
}
error -> V_131 [ V_239 ] = V_77 - error -> V_129 [ V_239 ] ;
if ( V_77 ) {
V_128 = F_113 ( V_77 , sizeof( * V_128 ) , V_161 ) ;
if ( V_128 )
V_130 = V_128 + error -> V_129 [ V_239 ] ;
}
if ( V_128 )
error -> V_129 [ V_239 ] =
F_57 ( V_128 ,
error -> V_129 [ V_239 ] ,
& V_154 -> V_240 ) ;
if ( V_130 )
error -> V_131 [ V_239 ] =
F_59 ( V_130 ,
error -> V_131 [ V_239 ] ,
& V_97 -> V_181 . V_241 , V_154 ) ;
error -> V_128 [ V_239 ] = V_128 ;
error -> V_130 [ V_239 ] = V_130 ;
}
static void F_115 ( struct V_96 * V_97 ,
struct V_99 * error )
{
struct V_153 * V_154 ;
int V_242 = 0 , V_77 = 0 ;
F_58 (vm, &dev_priv->vm_list, global_link)
V_242 ++ ;
error -> V_128 = F_113 ( V_242 , sizeof( * error -> V_128 ) , V_161 ) ;
error -> V_130 = F_113 ( V_242 , sizeof( * error -> V_130 ) , V_161 ) ;
error -> V_129 = F_113 ( V_242 , sizeof( * error -> V_129 ) ,
V_161 ) ;
error -> V_131 = F_113 ( V_242 , sizeof( * error -> V_131 ) ,
V_161 ) ;
if ( error -> V_128 == NULL ||
error -> V_130 == NULL ||
error -> V_129 == NULL ||
error -> V_131 == NULL ) {
F_36 ( error -> V_128 ) ;
F_36 ( error -> V_129 ) ;
F_36 ( error -> V_130 ) ;
F_36 ( error -> V_131 ) ;
error -> V_128 = NULL ;
error -> V_129 = NULL ;
error -> V_130 = NULL ;
error -> V_131 = NULL ;
} else {
F_58 (vm, &dev_priv->vm_list, global_link)
F_114 ( V_97 , error , V_154 , V_77 ++ ) ;
error -> V_127 = V_242 ;
}
}
static void F_116 ( struct V_96 * V_97 ,
struct V_99 * error )
{
struct V_52 * V_53 = V_97 -> V_53 ;
int V_77 ;
if ( F_30 ( V_53 ) ) {
error -> V_115 [ 0 ] = F_66 ( V_243 ) ;
error -> V_114 = F_66 ( V_244 ) ;
error -> V_117 = F_66 ( V_245 ) ;
}
if ( F_95 ( V_53 ) )
error -> V_126 = F_66 ( V_246 ) ;
if ( F_96 ( V_53 ) ) {
error -> V_117 = F_66 ( V_247 ) ;
error -> V_248 = F_66 ( V_249 ) ;
error -> V_76 = F_66 ( V_250 ) ;
}
if ( F_20 ( V_53 ) -> V_65 >= 7 )
error -> V_117 = F_66 ( V_251 ) ;
if ( F_20 ( V_53 ) -> V_65 >= 6 ) {
error -> V_118 = F_66 ( V_252 ) ;
error -> error = F_66 ( V_253 ) ;
error -> V_125 = F_66 ( V_254 ) ;
}
if ( F_96 ( V_53 ) || F_95 ( V_53 ) ) {
error -> V_255 = F_66 ( V_256 ) ;
error -> V_257 = F_66 ( V_258 ) ;
}
if ( F_117 ( V_53 ) )
error -> V_119 = F_66 ( V_259 ) ;
if ( F_20 ( V_53 ) -> V_65 >= 8 ) {
error -> V_114 = F_66 ( V_260 ) ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ )
error -> V_115 [ V_77 ] = F_66 ( F_118 ( V_77 ) ) ;
} else if ( F_29 ( V_53 ) ) {
error -> V_114 = F_66 ( V_261 ) ;
error -> V_115 [ 0 ] = F_66 ( V_243 ) ;
} else if ( F_119 ( V_53 ) ) {
error -> V_114 = F_120 ( V_262 ) ;
} else if ( ! F_30 ( V_53 ) ) {
error -> V_114 = F_66 ( V_262 ) ;
}
error -> V_113 = F_66 ( V_263 ) ;
error -> V_116 = F_66 ( V_264 ) ;
F_121 ( V_53 , error -> V_124 ) ;
}
static void F_122 ( struct V_52 * V_53 ,
struct V_99 * error ,
bool V_265 ,
const char * V_103 )
{
struct V_96 * V_97 = V_53 -> V_98 ;
V_60 V_266 ;
int V_187 = - 1 , V_21 ;
V_266 = F_60 ( V_97 , error , & V_187 ) ;
V_21 = F_123 ( error -> V_103 , sizeof( error -> V_103 ) ,
L_93 , V_187 , V_266 ) ;
if ( V_187 != - 1 && error -> V_2 [ V_187 ] . V_107 != - 1 )
V_21 += F_123 ( error -> V_103 + V_21 ,
sizeof( error -> V_103 ) - V_21 ,
L_94 ,
error -> V_2 [ V_187 ] . V_108 ,
error -> V_2 [ V_187 ] . V_107 ) ;
F_123 ( error -> V_103 + V_21 , sizeof( error -> V_103 ) - V_21 ,
L_95 ,
V_103 ,
V_265 ? L_96 : L_97 ) ;
}
static void F_124 ( struct V_96 * V_97 ,
struct V_99 * error )
{
error -> V_109 = F_125 ( & V_97 -> V_120 ) ;
error -> V_110 = V_97 -> V_110 ;
}
void F_126 ( struct V_52 * V_53 , bool V_265 ,
const char * V_103 )
{
static bool V_267 ;
struct V_96 * V_97 = V_53 -> V_98 ;
struct V_99 * error ;
unsigned long V_168 ;
error = F_127 ( sizeof( * error ) , V_161 ) ;
if ( ! error ) {
F_128 ( L_98 ) ;
return;
}
F_129 ( & error -> V_150 ) ;
F_124 ( V_97 , error ) ;
F_116 ( V_97 , error ) ;
F_115 ( V_97 , error ) ;
F_61 ( V_53 , error ) ;
F_107 ( V_53 , error ) ;
F_130 ( & error -> time ) ;
error -> V_141 = F_131 ( V_53 ) ;
error -> V_142 = F_132 ( V_53 ) ;
F_122 ( V_53 , error , V_265 , V_103 ) ;
F_133 ( L_58 , error -> V_103 ) ;
F_134 ( & V_97 -> V_120 . V_268 , V_168 ) ;
if ( V_97 -> V_120 . V_269 == NULL ) {
V_97 -> V_120 . V_269 = error ;
error = NULL ;
}
F_135 ( & V_97 -> V_120 . V_268 , V_168 ) ;
if ( error ) {
F_37 ( & error -> V_150 ) ;
return;
}
if ( ! V_267 ) {
F_133 ( L_99 ) ;
F_133 ( L_100 ) ;
F_133 ( L_101 ) ;
F_133 ( L_102 ) ;
F_133 ( L_103 , V_53 -> V_270 -> V_271 ) ;
V_267 = true ;
}
}
void F_136 ( struct V_52 * V_53 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 = V_53 -> V_98 ;
unsigned long V_168 ;
F_134 ( & V_97 -> V_120 . V_268 , V_168 ) ;
V_95 -> error = V_97 -> V_120 . V_269 ;
if ( V_95 -> error )
F_137 ( & V_95 -> error -> V_150 ) ;
F_135 ( & V_97 -> V_120 . V_268 , V_168 ) ;
}
void F_138 ( struct V_94 * V_95 )
{
if ( V_95 -> error )
F_139 ( & V_95 -> error -> V_150 , F_37 ) ;
}
void F_140 ( struct V_52 * V_53 )
{
struct V_96 * V_97 = V_53 -> V_98 ;
struct V_99 * error ;
unsigned long V_168 ;
F_134 ( & V_97 -> V_120 . V_268 , V_168 ) ;
error = V_97 -> V_120 . V_269 ;
V_97 -> V_120 . V_269 = NULL ;
F_135 ( & V_97 -> V_120 . V_268 , V_168 ) ;
if ( error )
F_139 ( & error -> V_150 , F_37 ) ;
}
const char * F_17 ( struct V_96 * V_40 , int type )
{
switch ( type ) {
case V_162 : return L_104 ;
case V_272 : return F_45 ( V_40 ) ? L_105 : L_106 ;
case V_273 : return L_107 ;
case V_274 : return L_108 ;
default: return L_8 ;
}
}
void F_121 ( struct V_52 * V_53 , T_5 * V_64 )
{
struct V_96 * V_97 = V_53 -> V_98 ;
memset ( V_64 , 0 , sizeof( * V_64 ) * V_275 ) ;
switch ( F_20 ( V_53 ) -> V_65 ) {
case 2 :
case 3 :
V_64 [ 0 ] = F_66 ( V_206 ) ;
break;
case 4 :
case 5 :
case 6 :
V_64 [ 0 ] = F_66 ( V_276 ) ;
V_64 [ 1 ] = F_66 ( V_277 ) ;
break;
default:
F_141 ( 1 , L_109 ) ;
case 7 :
case 8 :
V_64 [ 0 ] = F_66 ( V_278 ) ;
V_64 [ 1 ] = F_66 ( V_279 ) ;
V_64 [ 2 ] = F_66 ( V_280 ) ;
V_64 [ 3 ] = F_66 ( V_281 ) ;
break;
}
}
