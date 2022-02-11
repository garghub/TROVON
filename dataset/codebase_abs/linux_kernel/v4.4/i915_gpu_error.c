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
case V_52 :
return L_28 ;
}
return L_29 ;
}
static void F_20 ( struct V_14 * V_29 ,
struct V_53 * V_54 ,
struct V_55 * error ,
int V_56 )
{
struct V_57 * V_1 = & error -> V_1 [ V_56 ] ;
if ( ! V_1 -> V_58 )
return;
F_14 ( V_29 , L_30 , F_1 ( V_56 ) ) ;
F_14 ( V_29 , L_31 , V_1 -> V_22 ) ;
F_14 ( V_29 , L_32 , V_1 -> V_59 ) ;
F_14 ( V_29 , L_33 , V_1 -> V_60 ) ;
F_14 ( V_29 , L_34 , V_1 -> V_61 ) ;
F_14 ( V_29 , L_35 , V_1 -> V_62 ) ;
F_14 ( V_29 , L_36 , ( V_63 ) ( V_1 -> V_64 >> 32 ) , ( V_63 ) V_1 -> V_64 ) ;
F_14 ( V_29 , L_37 , V_1 -> V_65 ) ;
F_14 ( V_29 , L_38 , V_1 -> V_66 ) ;
F_14 ( V_29 , L_39 , V_1 -> V_67 ) ;
if ( F_21 ( V_54 ) -> V_68 >= 4 ) {
F_14 ( V_29 , L_40 , ( V_63 ) ( V_1 -> V_69 >> 32 ) , ( V_63 ) V_1 -> V_69 ) ;
F_14 ( V_29 , L_41 , V_1 -> V_70 ) ;
F_14 ( V_29 , L_42 , V_1 -> V_71 ) ;
}
F_14 ( V_29 , L_43 , V_1 -> V_72 ) ;
F_14 ( V_29 , L_44 , F_15 ( V_1 -> V_73 ) ,
F_16 ( V_1 -> V_73 ) ) ;
if ( F_21 ( V_54 ) -> V_68 >= 6 ) {
F_14 ( V_29 , L_45 , V_1 -> V_74 ) ;
F_14 ( V_29 , L_46 , V_1 -> V_75 ) ;
F_14 ( V_29 , L_47 ,
V_1 -> V_76 [ 0 ] ,
V_1 -> V_77 [ 0 ] ) ;
F_14 ( V_29 , L_48 ,
V_1 -> V_76 [ 1 ] ,
V_1 -> V_77 [ 1 ] ) ;
if ( F_22 ( V_54 ) ) {
F_14 ( V_29 , L_49 ,
V_1 -> V_76 [ 2 ] ,
V_1 -> V_77 [ 2 ] ) ;
}
}
if ( F_23 ( V_54 ) ) {
F_14 ( V_29 , L_50 , V_1 -> V_78 . V_79 ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 ) {
int V_33 ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
F_14 ( V_29 , L_51 ,
V_33 , V_1 -> V_78 . V_80 [ V_33 ] ) ;
} else {
F_14 ( V_29 , L_52 ,
V_1 -> V_78 . V_81 ) ;
}
}
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
struct V_53 * V_54 = V_97 -> V_54 ;
struct V_98 * V_99 = V_54 -> V_100 ;
struct V_55 * error = V_97 -> error ;
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
F_14 ( V_29 , L_66 , V_54 -> V_112 -> V_113 ) ;
F_14 ( V_29 , L_67 , error -> V_114 ) ;
F_14 ( V_29 , L_68 , error -> V_115 ) ;
F_14 ( V_29 , L_69 , error -> V_116 ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 ) {
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
F_14 ( V_29 , L_70 , V_33 ,
error -> V_117 [ V_33 ] ) ;
} else if ( F_29 ( V_54 ) || F_30 ( V_54 ) )
F_14 ( V_29 , L_71 , error -> V_117 [ 0 ] ) ;
F_14 ( V_29 , L_72 , error -> V_118 ) ;
F_14 ( V_29 , L_73 , error -> V_119 ) ;
F_14 ( V_29 , L_74 , error -> V_120 ) ;
F_14 ( V_29 , L_75 , error -> V_121 ) ;
F_14 ( V_29 , L_76 , V_99 -> V_122 . V_123 ) ;
for ( V_33 = 0 ; V_33 < V_99 -> V_124 ; V_33 ++ )
F_14 ( V_29 , L_77 , V_33 , error -> V_125 [ V_33 ] ) ;
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_126 ) ; V_33 ++ )
F_14 ( V_29 , L_78 , V_33 ,
error -> V_126 [ V_33 ] ) ;
if ( F_21 ( V_54 ) -> V_68 >= 6 ) {
F_14 ( V_29 , L_79 , error -> error ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 )
F_14 ( V_29 , L_80 ,
error -> V_127 , error -> V_128 ) ;
F_14 ( V_29 , L_81 , error -> V_129 ) ;
}
if ( F_21 ( V_54 ) -> V_68 == 7 )
F_14 ( V_29 , L_82 , error -> V_130 ) ;
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_1 ) ; V_33 ++ )
F_20 ( V_29 , V_54 , error , V_33 ) ;
for ( V_33 = 0 ; V_33 < error -> V_131 ; V_33 ++ ) {
F_14 ( V_29 , L_83 , V_33 ) ;
F_13 ( V_29 , L_84 ,
error -> V_132 [ V_33 ] ,
error -> V_133 [ V_33 ] ) ;
F_13 ( V_29 , L_85 ,
error -> V_134 [ V_33 ] ,
error -> V_135 [ V_33 ] ) ;
}
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_1 ) ; V_33 ++ ) {
V_89 = error -> V_1 [ V_33 ] . V_136 ;
if ( V_89 ) {
F_17 ( V_29 , V_99 -> V_1 [ V_33 ] . V_30 ) ;
if ( error -> V_1 [ V_33 ] . V_108 != - 1 )
F_14 ( V_29 , L_86 ,
error -> V_1 [ V_33 ] . V_109 ,
error -> V_1 [ V_33 ] . V_108 ) ;
F_14 ( V_29 , L_87 ,
F_15 ( V_89 -> V_34 ) ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
V_89 = error -> V_1 [ V_33 ] . V_137 ;
if ( V_89 ) {
F_14 ( V_29 , L_88 ,
V_99 -> V_1 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
if ( error -> V_1 [ V_33 ] . V_138 ) {
F_14 ( V_29 , L_89 ,
V_99 -> V_1 [ V_33 ] . V_30 ,
error -> V_1 [ V_33 ] . V_138 ) ;
for ( V_101 = 0 ; V_101 < error -> V_1 [ V_33 ] . V_138 ; V_101 ++ ) {
F_14 ( V_29 , L_90 ,
error -> V_1 [ V_33 ] . V_139 [ V_101 ] . V_82 ,
error -> V_1 [ V_33 ] . V_139 [ V_101 ] . V_140 ,
error -> V_1 [ V_33 ] . V_139 [ V_101 ] . V_60 ) ;
}
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_141 ) ) {
F_14 ( V_29 , L_91 ,
V_99 -> V_1 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_142 ) ) {
T_3 V_143 = V_89 -> V_34 ;
V_63 * V_142 = & V_89 -> V_95 [ 0 ] [ 0 ] ;
if ( V_41 . V_144 ) {
V_143 += V_145 * V_94 ;
V_142 = & V_89 -> V_95 [ V_145 ] [ 0 ] ;
}
F_14 ( V_29 , L_92 ,
V_99 -> V_1 [ V_33 ] . V_30 , V_143 ) ;
V_91 = 0 ;
for ( V_92 = 0 ; V_92 < V_94 / 16 ; V_92 += 4 ) {
F_14 ( V_29 , L_93 ,
V_91 ,
V_142 [ V_92 ] ,
V_142 [ V_92 + 1 ] ,
V_142 [ V_92 + 2 ] ,
V_142 [ V_92 + 3 ] ) ;
V_91 += 16 ;
}
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_146 ) ) {
F_14 ( V_29 , L_94 ,
V_99 -> V_1 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
}
if ( ( V_89 = error -> V_147 ) ) {
F_14 ( V_29 , L_95 ,
F_16 ( V_89 -> V_34 ) ) ;
for ( V_92 = 0 ; V_92 < V_94 / 16 ; V_92 += 4 ) {
F_14 ( V_29 , L_93 ,
V_92 * 4 ,
V_89 -> V_95 [ 0 ] [ V_92 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 1 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 2 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 3 ] ) ;
}
}
if ( error -> V_148 )
F_31 ( V_29 , error -> V_148 ) ;
if ( error -> V_149 )
F_32 ( V_29 , V_54 , error -> V_149 ) ;
V_103:
if ( V_29 -> V_17 == 0 && V_29 -> V_16 )
return V_29 -> V_16 ;
return 0 ;
}
int F_33 ( struct V_14 * V_150 ,
struct V_98 * V_41 ,
T_1 V_32 , T_4 V_21 )
{
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> V_41 = V_41 ;
V_150 -> V_18 = V_32 + 1 > V_94 ? V_32 + 1 : V_94 ;
V_150 -> V_25 = F_34 ( V_150 -> V_18 ,
V_151 | V_152 | V_153 ) ;
if ( V_150 -> V_25 == NULL ) {
V_150 -> V_18 = V_94 ;
V_150 -> V_25 = F_34 ( V_150 -> V_18 , V_151 ) ;
}
if ( V_150 -> V_25 == NULL ) {
V_150 -> V_18 = 128 ;
V_150 -> V_25 = F_34 ( V_150 -> V_18 , V_151 ) ;
}
if ( V_150 -> V_25 == NULL )
return - V_154 ;
V_150 -> V_22 = V_21 ;
return 0 ;
}
static void F_35 ( struct V_88 * V_89 )
{
int V_90 ;
if ( V_89 == NULL )
return;
for ( V_90 = 0 ; V_90 < V_89 -> V_93 ; V_90 ++ )
F_36 ( V_89 -> V_95 [ V_90 ] ) ;
F_36 ( V_89 ) ;
}
static void F_37 ( struct V_155 * V_156 )
{
struct V_55 * error = F_38 ( V_156 ,
F_39 ( * error ) , V_157 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_1 ) ; V_33 ++ ) {
F_35 ( error -> V_1 [ V_33 ] . V_136 ) ;
F_35 ( error -> V_1 [ V_33 ] . V_137 ) ;
F_35 ( error -> V_1 [ V_33 ] . V_141 ) ;
F_35 ( error -> V_1 [ V_33 ] . V_142 ) ;
F_35 ( error -> V_1 [ V_33 ] . V_146 ) ;
F_36 ( error -> V_1 [ V_33 ] . V_139 ) ;
}
F_35 ( error -> V_147 ) ;
for ( V_33 = 0 ; V_33 < error -> V_131 ; V_33 ++ )
F_36 ( error -> V_132 [ V_33 ] ) ;
F_36 ( error -> V_132 ) ;
F_36 ( error -> V_133 ) ;
F_36 ( error -> V_134 ) ;
F_36 ( error -> V_135 ) ;
F_36 ( error -> V_148 ) ;
F_36 ( error -> V_149 ) ;
F_36 ( error ) ;
}
static struct V_88 *
F_40 ( struct V_98 * V_99 ,
struct V_158 * V_159 ,
struct V_160 * V_161 )
{
struct V_88 * V_162 ;
struct V_163 * V_164 = NULL ;
int V_165 ;
bool V_166 ;
int V_33 = 0 ;
T_3 V_167 ;
if ( V_159 == NULL || V_159 -> V_95 == NULL )
return NULL ;
V_165 = V_159 -> V_168 . V_18 >> V_169 ;
V_162 = F_34 ( sizeof( * V_162 ) + V_165 * sizeof( V_63 * ) , V_170 ) ;
if ( V_162 == NULL )
return NULL ;
if ( F_41 ( V_159 , V_161 ) )
V_162 -> V_34 = F_42 ( V_159 , V_161 ) ;
else
V_162 -> V_34 = - 1 ;
V_167 = V_162 -> V_34 ;
if ( F_43 ( V_161 ) )
V_164 = F_44 ( V_159 ) ;
V_166 = ( V_159 -> V_42 == V_171 &&
V_164 && ( V_164 -> V_172 & V_173 ) &&
V_167 + V_165 * V_94 <= V_99 -> V_174 . V_175 ) ;
if ( V_159 -> V_176 ) {
V_166 = true ;
if ( ! ( V_164 && V_164 -> V_172 & V_173 ) )
goto V_177;
V_167 = F_45 ( V_159 ) ;
if ( V_167 + V_165 * V_94 > V_99 -> V_174 . V_175 )
goto V_177;
}
if ( V_166 && V_159 -> V_42 != V_171 && ! F_46 ( V_99 -> V_54 ) )
goto V_177;
V_162 -> V_93 = V_165 ;
while ( V_165 -- ) {
unsigned long V_178 ;
void * V_179 ;
V_179 = F_34 ( V_94 , V_170 ) ;
if ( V_179 == NULL )
goto V_177;
F_47 ( V_178 ) ;
if ( V_166 ) {
void T_5 * V_180 ;
V_180 = F_48 ( V_99 -> V_174 . V_181 ,
V_167 ) ;
F_49 ( V_179 , V_180 , V_94 ) ;
F_50 ( V_180 ) ;
} else {
struct V_90 * V_90 ;
void * V_180 ;
V_90 = F_51 ( V_159 , V_33 ) ;
F_52 ( & V_90 , 1 ) ;
V_180 = F_53 ( V_90 ) ;
memcpy ( V_179 , V_180 , V_94 ) ;
F_54 ( V_180 ) ;
F_52 ( & V_90 , 1 ) ;
}
F_55 ( V_178 ) ;
V_162 -> V_95 [ V_33 ++ ] = V_179 ;
V_167 += V_94 ;
}
return V_162 ;
V_177:
while ( V_33 -- )
F_36 ( V_162 -> V_95 [ V_33 ] ) ;
F_36 ( V_162 ) ;
return NULL ;
}
static void F_56 ( struct V_31 * V_16 ,
struct V_163 * V_164 )
{
struct V_158 * V_89 = V_164 -> V_89 ;
int V_33 ;
V_16 -> V_18 = V_89 -> V_168 . V_18 ;
V_16 -> V_30 = V_89 -> V_168 . V_30 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ )
V_16 -> V_38 [ V_33 ] = F_57 ( V_89 -> V_182 [ V_33 ] ) ;
V_16 -> V_39 = F_57 ( V_89 -> V_183 ) ;
V_16 -> V_34 = V_164 -> V_184 . V_22 ;
V_16 -> V_35 = V_89 -> V_168 . V_35 ;
V_16 -> V_36 = V_89 -> V_168 . V_36 ;
V_16 -> V_43 = V_89 -> V_43 ;
V_16 -> V_7 = 0 ;
if ( F_58 ( V_89 ) )
V_16 -> V_7 = 1 ;
V_16 -> V_8 = V_89 -> V_185 ;
V_16 -> V_12 = V_89 -> V_12 ;
V_16 -> V_13 = V_89 -> V_186 != V_187 ;
V_16 -> V_40 = V_89 -> V_40 . V_188 != NULL ;
V_16 -> V_1 = V_89 -> V_183 ?
F_59 ( V_89 -> V_183 ) -> V_189 : - 1 ;
V_16 -> V_42 = V_89 -> V_42 ;
}
static V_63 F_60 ( struct V_31 * V_16 ,
int V_32 , struct V_190 * V_59 )
{
struct V_163 * V_164 ;
int V_33 = 0 ;
F_61 (vma, head, mm_list) {
F_56 ( V_16 ++ , V_164 ) ;
if ( ++ V_33 == V_32 )
break;
}
return V_33 ;
}
static V_63 F_62 ( struct V_31 * V_16 ,
int V_32 , struct V_190 * V_59 ,
struct V_160 * V_161 )
{
struct V_158 * V_89 ;
struct V_31 * const V_191 = V_16 ;
struct V_31 * const V_192 = V_16 + V_32 ;
F_61 (obj, head, global_list) {
struct V_163 * V_164 ;
if ( V_16 == V_192 )
break;
F_61 (vma, &obj->vma_list, vma_link)
if ( V_164 -> V_161 == V_161 && V_164 -> V_193 > 0 )
F_56 ( V_16 ++ , V_164 ) ;
}
return V_16 - V_191 ;
}
static T_6 F_63 ( struct V_98 * V_99 ,
struct V_55 * error ,
int * V_194 )
{
T_6 V_195 = 0 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
if ( error -> V_1 [ V_33 ] . V_86 == V_52 ) {
if ( V_194 )
* V_194 = V_33 ;
return error -> V_1 [ V_33 ] . V_66 ^ error -> V_1 [ V_33 ] . V_67 ;
}
}
return V_195 ;
}
static void F_64 ( struct V_53 * V_54 ,
struct V_55 * error )
{
struct V_98 * V_99 = V_54 -> V_100 ;
int V_33 ;
if ( F_65 ( V_54 ) || F_66 ( V_54 ) ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_124 ; V_33 ++ )
error -> V_125 [ V_33 ] = F_67 ( F_68 ( V_33 ) ) ;
} else if ( F_69 ( V_54 ) || F_70 ( V_54 ) ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_124 ; V_33 ++ )
error -> V_125 [ V_33 ] = F_71 ( F_72 ( V_33 ) ) ;
} else if ( F_21 ( V_54 ) -> V_68 >= 6 ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_124 ; V_33 ++ )
error -> V_125 [ V_33 ] = F_71 ( F_73 ( V_33 ) ) ;
}
}
static void F_74 ( struct V_98 * V_99 ,
struct V_55 * error ,
struct V_196 * V_1 ,
struct V_57 * V_197 )
{
struct V_196 * V_198 ;
int V_33 ;
if ( ! F_75 ( V_99 -> V_54 ) )
return;
if ( ! error -> V_147 )
error -> V_147 =
F_76 ( V_99 ,
V_99 -> V_147 ) ;
F_77 (to, dev_priv, i) {
int V_199 ;
T_7 V_200 ;
V_63 * V_27 ;
if ( V_1 == V_198 )
continue;
V_200 = ( F_78 ( V_1 , V_33 ) & ( V_94 - 1 ) )
/ 4 ;
V_27 = error -> V_147 -> V_95 [ 0 ] ;
V_199 = F_79 ( V_1 , V_198 ) ;
V_197 -> V_76 [ V_199 ] = V_27 [ V_200 ] ;
V_197 -> V_77 [ V_199 ] = V_1 -> V_201 . V_202 [ V_199 ] ;
}
}
static void F_80 ( struct V_98 * V_99 ,
struct V_196 * V_1 ,
struct V_57 * V_197 )
{
V_197 -> V_76 [ 0 ] = F_67 ( F_81 ( V_1 -> V_203 ) ) ;
V_197 -> V_76 [ 1 ] = F_67 ( F_82 ( V_1 -> V_203 ) ) ;
V_197 -> V_77 [ 0 ] = V_1 -> V_201 . V_202 [ 0 ] ;
V_197 -> V_77 [ 1 ] = V_1 -> V_201 . V_202 [ 1 ] ;
if ( F_22 ( V_99 -> V_54 ) ) {
V_197 -> V_76 [ 2 ] =
F_67 ( F_83 ( V_1 -> V_203 ) ) ;
V_197 -> V_77 [ 2 ] = V_1 -> V_201 . V_202 [ 2 ] ;
}
}
static void F_84 ( struct V_53 * V_54 ,
struct V_55 * error ,
struct V_196 * V_1 ,
struct V_57 * V_197 )
{
struct V_98 * V_99 = V_54 -> V_100 ;
if ( F_21 ( V_54 ) -> V_68 >= 6 ) {
V_197 -> V_74 = F_67 ( V_1 -> V_203 + 0x50 ) ;
V_197 -> V_75 = F_67 ( F_85 ( V_1 ) ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 )
F_74 ( V_99 , error , V_1 , V_197 ) ;
else
F_80 ( V_99 , V_1 , V_197 ) ;
}
if ( F_21 ( V_54 ) -> V_68 >= 4 ) {
V_197 -> V_73 = F_67 ( F_86 ( V_1 -> V_203 ) ) ;
V_197 -> V_65 = F_67 ( F_87 ( V_1 -> V_203 ) ) ;
V_197 -> V_66 = F_67 ( F_88 ( V_1 -> V_203 ) ) ;
V_197 -> V_67 = F_67 ( F_89 ( V_1 -> V_203 ) ) ;
V_197 -> V_71 = F_67 ( F_90 ( V_1 -> V_203 ) ) ;
V_197 -> V_69 = F_67 ( F_91 ( V_1 -> V_203 ) ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 ) {
V_197 -> V_73 |= ( T_3 ) F_67 ( F_92 ( V_1 -> V_203 ) ) << 32 ;
V_197 -> V_69 |= ( T_3 ) F_67 ( F_93 ( V_1 -> V_203 ) ) << 32 ;
}
V_197 -> V_70 = F_67 ( F_94 ( V_1 -> V_203 ) ) ;
} else {
V_197 -> V_73 = F_67 ( V_204 ) ;
V_197 -> V_65 = F_67 ( V_205 ) ;
V_197 -> V_66 = F_67 ( V_206 ) ;
V_197 -> V_67 = F_67 ( V_207 ) ;
}
V_197 -> V_83 = F_95 ( & V_1 -> V_208 ) ;
V_197 -> V_72 = F_67 ( F_96 ( V_1 -> V_203 ) ) ;
V_197 -> V_82 = V_1 -> V_209 ( V_1 , false ) ;
V_197 -> V_64 = F_97 ( V_1 ) ;
V_197 -> V_22 = F_98 ( V_1 ) ;
V_197 -> V_59 = F_99 ( V_1 ) ;
V_197 -> V_60 = F_100 ( V_1 ) ;
V_197 -> V_61 = F_101 ( V_1 ) ;
if ( F_102 ( V_54 ) ) {
int V_210 ;
if ( F_103 ( V_54 ) ) {
switch ( V_1 -> V_189 ) {
default:
case V_2 :
V_210 = V_211 ;
break;
case V_4 :
V_210 = V_212 ;
break;
case V_3 :
V_210 = V_213 ;
break;
case V_5 :
V_210 = V_214 ;
break;
}
} else if ( F_104 ( V_1 -> V_54 ) ) {
V_210 = F_105 ( V_1 -> V_203 ) ;
} else {
V_210 = F_106 ( V_1 -> V_203 ) ;
}
V_197 -> V_62 = F_67 ( V_210 ) ;
}
V_197 -> V_87 = V_1 -> V_215 . V_216 ;
V_197 -> V_86 = V_1 -> V_215 . V_217 ;
if ( F_23 ( V_54 ) ) {
int V_33 ;
V_197 -> V_78 . V_79 = F_67 ( F_107 ( V_1 ) ) ;
if ( F_104 ( V_54 ) )
V_197 -> V_78 . V_81 =
F_67 ( F_108 ( V_1 ) ) ;
else if ( F_103 ( V_54 ) )
V_197 -> V_78 . V_81 =
F_67 ( F_109 ( V_1 ) ) ;
else if ( F_21 ( V_54 ) -> V_68 >= 8 )
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ ) {
V_197 -> V_78 . V_80 [ V_33 ] =
F_67 ( F_110 ( V_1 , V_33 ) ) ;
V_197 -> V_78 . V_80 [ V_33 ] <<= 32 ;
V_197 -> V_78 . V_80 [ V_33 ] |=
F_67 ( F_111 ( V_1 , V_33 ) ) ;
}
}
}
static void F_112 ( struct V_196 * V_1 ,
struct V_55 * error ,
struct V_57 * V_197 )
{
struct V_98 * V_99 = V_1 -> V_54 -> V_100 ;
struct V_158 * V_89 ;
if ( V_1 -> V_189 != V_2 || ! error -> V_121 )
return;
F_61 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_113 ( V_89 ) )
continue;
if ( ( error -> V_121 & V_218 ) == F_45 ( V_89 ) ) {
V_197 -> V_146 = F_76 ( V_99 , V_89 ) ;
break;
}
}
}
static void F_114 ( struct V_53 * V_54 ,
struct V_55 * error )
{
struct V_98 * V_99 = V_54 -> V_100 ;
struct V_219 * V_220 ;
int V_33 , V_32 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
struct V_196 * V_1 = & V_99 -> V_1 [ V_33 ] ;
struct V_221 * V_222 ;
error -> V_1 [ V_33 ] . V_108 = - 1 ;
if ( V_1 -> V_54 == NULL )
continue;
error -> V_1 [ V_33 ] . V_58 = true ;
F_84 ( V_54 , error , V_1 , & error -> V_1 [ V_33 ] ) ;
V_220 = F_115 ( V_1 ) ;
if ( V_220 ) {
struct V_160 * V_161 ;
V_161 = V_220 -> V_146 && V_220 -> V_146 -> V_223 ?
& V_220 -> V_146 -> V_223 -> V_168 :
& V_99 -> V_174 . V_168 ;
error -> V_1 [ V_33 ] . V_136 =
F_40 ( V_99 ,
V_220 -> V_224 ,
V_161 ) ;
if ( F_116 ( V_99 -> V_54 ) )
error -> V_1 [ V_33 ] . V_137 =
F_76 ( V_99 ,
V_1 -> V_225 . V_89 ) ;
if ( V_220 -> V_108 ) {
struct V_226 * V_227 ;
F_117 () ;
V_227 = F_118 ( V_220 -> V_108 , V_228 ) ;
if ( V_227 ) {
strcpy ( error -> V_1 [ V_33 ] . V_109 , V_227 -> V_109 ) ;
error -> V_1 [ V_33 ] . V_108 = V_227 -> V_108 ;
}
F_119 () ;
}
}
if ( V_41 . V_144 ) {
if ( V_220 )
V_222 = V_220 -> V_146 -> V_229 [ V_1 -> V_189 ] . V_230 ;
else
V_222 = V_1 -> V_231 -> V_229 [ V_1 -> V_189 ] . V_230 ;
} else
V_222 = V_1 -> V_232 ;
error -> V_1 [ V_33 ] . V_84 = V_222 -> V_59 ;
error -> V_1 [ V_33 ] . V_85 = V_222 -> V_60 ;
error -> V_1 [ V_33 ] . V_141 =
F_76 ( V_99 , V_222 -> V_89 ) ;
error -> V_1 [ V_33 ] . V_142 =
F_76 ( V_99 , V_1 -> V_233 . V_89 ) ;
F_112 ( V_1 , error , & error -> V_1 [ V_33 ] ) ;
V_32 = 0 ;
F_61 (request, &ring->request_list, list)
V_32 ++ ;
error -> V_1 [ V_33 ] . V_138 = V_32 ;
error -> V_1 [ V_33 ] . V_139 =
F_120 ( V_32 , sizeof( * error -> V_1 [ V_33 ] . V_139 ) ,
V_170 ) ;
if ( error -> V_1 [ V_33 ] . V_139 == NULL ) {
error -> V_1 [ V_33 ] . V_138 = 0 ;
continue;
}
V_32 = 0 ;
F_61 (request, &ring->request_list, list) {
struct V_234 * V_235 ;
V_235 = & error -> V_1 [ V_33 ] . V_139 [ V_32 ++ ] ;
V_235 -> V_82 = V_220 -> V_82 ;
V_235 -> V_140 = V_220 -> V_236 ;
V_235 -> V_60 = V_220 -> V_237 ;
}
}
}
static void F_121 ( struct V_98 * V_99 ,
struct V_55 * error ,
struct V_160 * V_161 ,
const int V_238 )
{
struct V_31 * V_132 = NULL , * V_134 = NULL ;
struct V_158 * V_89 ;
struct V_163 * V_164 ;
int V_33 ;
V_33 = 0 ;
F_61 (vma, &vm->active_list, mm_list)
V_33 ++ ;
error -> V_133 [ V_238 ] = V_33 ;
F_61 (obj, &dev_priv->mm.bound_list, global_list) {
F_61 (vma, &obj->vma_list, vma_link)
if ( V_164 -> V_161 == V_161 && V_164 -> V_193 > 0 )
V_33 ++ ;
}
error -> V_135 [ V_238 ] = V_33 - error -> V_133 [ V_238 ] ;
if ( V_33 ) {
V_132 = F_120 ( V_33 , sizeof( * V_132 ) , V_170 ) ;
if ( V_132 )
V_134 = V_132 + error -> V_133 [ V_238 ] ;
}
if ( V_132 )
error -> V_133 [ V_238 ] =
F_60 ( V_132 ,
error -> V_133 [ V_238 ] ,
& V_161 -> V_239 ) ;
if ( V_134 )
error -> V_135 [ V_238 ] =
F_62 ( V_134 ,
error -> V_135 [ V_238 ] ,
& V_99 -> V_188 . V_240 , V_161 ) ;
error -> V_132 [ V_238 ] = V_132 ;
error -> V_134 [ V_238 ] = V_134 ;
}
static void F_122 ( struct V_98 * V_99 ,
struct V_55 * error )
{
struct V_160 * V_161 ;
int V_241 = 0 , V_33 = 0 ;
F_61 (vm, &dev_priv->vm_list, global_link)
V_241 ++ ;
error -> V_132 = F_120 ( V_241 , sizeof( * error -> V_132 ) , V_170 ) ;
error -> V_134 = F_120 ( V_241 , sizeof( * error -> V_134 ) , V_170 ) ;
error -> V_133 = F_120 ( V_241 , sizeof( * error -> V_133 ) ,
V_170 ) ;
error -> V_135 = F_120 ( V_241 , sizeof( * error -> V_135 ) ,
V_170 ) ;
if ( error -> V_132 == NULL ||
error -> V_134 == NULL ||
error -> V_133 == NULL ||
error -> V_135 == NULL ) {
F_36 ( error -> V_132 ) ;
F_36 ( error -> V_133 ) ;
F_36 ( error -> V_134 ) ;
F_36 ( error -> V_135 ) ;
error -> V_132 = NULL ;
error -> V_133 = NULL ;
error -> V_134 = NULL ;
error -> V_135 = NULL ;
} else {
F_61 (vm, &dev_priv->vm_list, global_link)
F_121 ( V_99 , error , V_161 , V_33 ++ ) ;
error -> V_131 = V_241 ;
}
}
static void F_123 ( struct V_98 * V_99 ,
struct V_55 * error )
{
struct V_53 * V_54 = V_99 -> V_54 ;
int V_33 ;
if ( F_30 ( V_54 ) ) {
error -> V_117 [ 0 ] = F_67 ( V_242 ) ;
error -> V_116 = F_67 ( V_243 ) ;
error -> V_119 = F_67 ( V_244 ) ;
}
if ( F_103 ( V_54 ) )
error -> V_130 = F_67 ( V_245 ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 ) {
error -> V_128 = F_67 ( V_246 ) ;
error -> V_127 = F_67 ( V_247 ) ;
}
if ( F_104 ( V_54 ) ) {
error -> V_119 = F_67 ( V_248 ) ;
error -> V_249 = F_67 ( V_250 ) ;
error -> V_79 = F_67 ( V_251 ) ;
}
if ( F_21 ( V_54 ) -> V_68 >= 7 )
error -> V_119 = F_67 ( V_252 ) ;
if ( F_21 ( V_54 ) -> V_68 >= 6 ) {
error -> V_120 = F_67 ( V_253 ) ;
error -> error = F_67 ( V_254 ) ;
error -> V_129 = F_67 ( V_255 ) ;
}
if ( F_104 ( V_54 ) || F_103 ( V_54 ) ) {
error -> V_256 = F_67 ( V_257 ) ;
error -> V_258 = F_67 ( V_259 ) ;
}
if ( F_124 ( V_54 ) )
error -> V_121 = F_67 ( V_260 ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 ) {
error -> V_116 = F_67 ( V_261 ) ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
error -> V_117 [ V_33 ] = F_67 ( F_125 ( V_33 ) ) ;
} else if ( F_29 ( V_54 ) ) {
error -> V_116 = F_67 ( V_262 ) ;
error -> V_117 [ 0 ] = F_67 ( V_242 ) ;
} else if ( F_66 ( V_54 ) ) {
error -> V_116 = F_126 ( V_263 ) ;
} else if ( ! F_30 ( V_54 ) ) {
error -> V_116 = F_67 ( V_263 ) ;
}
error -> V_115 = F_67 ( V_264 ) ;
error -> V_118 = F_67 ( V_265 ) ;
F_127 ( V_54 , error -> V_126 ) ;
}
static void F_128 ( struct V_53 * V_54 ,
struct V_55 * error ,
bool V_266 ,
const char * V_104 )
{
struct V_98 * V_99 = V_54 -> V_100 ;
V_63 V_267 ;
int V_194 = - 1 , V_20 ;
V_267 = F_63 ( V_99 , error , & V_194 ) ;
V_20 = F_129 ( error -> V_104 , sizeof( error -> V_104 ) ,
L_96 ,
F_21 ( V_54 ) -> V_68 , V_194 , V_267 ) ;
if ( V_194 != - 1 && error -> V_1 [ V_194 ] . V_108 != - 1 )
V_20 += F_129 ( error -> V_104 + V_20 ,
sizeof( error -> V_104 ) - V_20 ,
L_97 ,
error -> V_1 [ V_194 ] . V_109 ,
error -> V_1 [ V_194 ] . V_108 ) ;
F_129 ( error -> V_104 + V_20 , sizeof( error -> V_104 ) - V_20 ,
L_98 ,
V_104 ,
V_266 ? L_99 : L_100 ) ;
}
static void F_130 ( struct V_98 * V_99 ,
struct V_55 * error )
{
error -> V_114 = - 1 ;
#ifdef F_131
error -> V_114 = V_268 ;
#endif
error -> V_110 = F_132 ( & V_99 -> V_122 ) ;
error -> V_111 = V_99 -> V_111 ;
}
void F_133 ( struct V_53 * V_54 , bool V_266 ,
const char * V_104 )
{
static bool V_269 ;
struct V_98 * V_99 = V_54 -> V_100 ;
struct V_55 * error ;
unsigned long V_178 ;
error = F_134 ( sizeof( * error ) , V_170 ) ;
if ( ! error ) {
F_135 ( L_101 ) ;
return;
}
F_136 ( & error -> V_157 ) ;
F_130 ( V_99 , error ) ;
F_123 ( V_99 , error ) ;
F_122 ( V_99 , error ) ;
F_64 ( V_54 , error ) ;
F_114 ( V_54 , error ) ;
F_137 ( & error -> time ) ;
error -> V_148 = F_138 ( V_54 ) ;
error -> V_149 = F_139 ( V_54 ) ;
F_128 ( V_54 , error , V_266 , V_104 ) ;
F_140 ( L_60 , error -> V_104 ) ;
F_141 ( & V_99 -> V_122 . V_270 , V_178 ) ;
if ( V_99 -> V_122 . V_271 == NULL ) {
V_99 -> V_122 . V_271 = error ;
error = NULL ;
}
F_142 ( & V_99 -> V_122 . V_270 , V_178 ) ;
if ( error ) {
F_37 ( & error -> V_157 ) ;
return;
}
if ( ! V_269 ) {
F_140 ( L_102 ) ;
F_140 ( L_103 ) ;
F_140 ( L_104 ) ;
F_140 ( L_105 ) ;
F_140 ( L_106 , V_54 -> V_272 -> V_273 ) ;
V_269 = true ;
}
}
void F_143 ( struct V_53 * V_54 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = V_54 -> V_100 ;
F_144 ( & V_99 -> V_122 . V_270 ) ;
V_97 -> error = V_99 -> V_122 . V_271 ;
if ( V_97 -> error )
F_145 ( & V_97 -> error -> V_157 ) ;
F_146 ( & V_99 -> V_122 . V_270 ) ;
}
void F_147 ( struct V_96 * V_97 )
{
if ( V_97 -> error )
F_148 ( & V_97 -> error -> V_157 , F_37 ) ;
}
void F_149 ( struct V_53 * V_54 )
{
struct V_98 * V_99 = V_54 -> V_100 ;
struct V_55 * error ;
F_144 ( & V_99 -> V_122 . V_270 ) ;
error = V_99 -> V_122 . V_271 ;
V_99 -> V_122 . V_271 = NULL ;
F_146 ( & V_99 -> V_122 . V_270 ) ;
if ( error )
F_148 ( & error -> V_157 , F_37 ) ;
}
const char * F_18 ( struct V_98 * V_41 , int type )
{
switch ( type ) {
case V_171 : return L_107 ;
case V_274 : return F_46 ( V_41 ) ? L_108 : L_109 ;
case V_275 : return L_110 ;
case V_276 : return L_111 ;
default: return L_6 ;
}
}
void F_127 ( struct V_53 * V_54 , T_6 * V_67 )
{
struct V_98 * V_99 = V_54 -> V_100 ;
memset ( V_67 , 0 , sizeof( * V_67 ) * V_277 ) ;
if ( F_66 ( V_54 ) || F_65 ( V_54 ) )
V_67 [ 0 ] = F_67 ( V_207 ) ;
else if ( F_70 ( V_54 ) || F_69 ( V_54 ) || F_104 ( V_54 ) ) {
V_67 [ 0 ] = F_67 ( F_89 ( V_278 ) ) ;
V_67 [ 1 ] = F_67 ( V_279 ) ;
} else if ( F_21 ( V_54 ) -> V_68 >= 7 ) {
V_67 [ 0 ] = F_67 ( F_89 ( V_278 ) ) ;
V_67 [ 1 ] = F_67 ( V_280 ) ;
V_67 [ 2 ] = F_67 ( V_281 ) ;
V_67 [ 3 ] = F_67 ( V_282 ) ;
}
}
