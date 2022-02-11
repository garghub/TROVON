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
if ( F_29 ( V_54 ) ) {
struct V_115 * V_116 = & V_99 -> V_116 ;
F_14 ( V_29 , L_68 ,
F_24 ( V_116 -> V_117 != NULL ) ) ;
F_14 ( V_29 , L_69 ,
F_30 ( V_116 -> V_118 ) ,
F_31 ( V_116 -> V_118 ) ) ;
}
F_14 ( V_29 , L_70 , error -> V_119 ) ;
F_14 ( V_29 , L_71 , error -> V_120 ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 ) {
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
F_14 ( V_29 , L_72 , V_33 ,
error -> V_121 [ V_33 ] ) ;
} else if ( F_32 ( V_54 ) || F_33 ( V_54 ) )
F_14 ( V_29 , L_73 , error -> V_121 [ 0 ] ) ;
F_14 ( V_29 , L_74 , error -> V_122 ) ;
F_14 ( V_29 , L_75 , error -> V_123 ) ;
F_14 ( V_29 , L_76 , error -> V_124 ) ;
F_14 ( V_29 , L_77 , error -> V_125 ) ;
F_14 ( V_29 , L_78 , V_99 -> V_126 . V_127 ) ;
for ( V_33 = 0 ; V_33 < V_99 -> V_128 ; V_33 ++ )
F_14 ( V_29 , L_79 , V_33 , error -> V_129 [ V_33 ] ) ;
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_130 ) ; V_33 ++ )
F_14 ( V_29 , L_80 , V_33 ,
error -> V_130 [ V_33 ] ) ;
if ( F_21 ( V_54 ) -> V_68 >= 6 ) {
F_14 ( V_29 , L_81 , error -> error ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 )
F_14 ( V_29 , L_82 ,
error -> V_131 , error -> V_132 ) ;
F_14 ( V_29 , L_83 , error -> V_133 ) ;
}
if ( F_21 ( V_54 ) -> V_68 == 7 )
F_14 ( V_29 , L_84 , error -> V_134 ) ;
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_1 ) ; V_33 ++ )
F_20 ( V_29 , V_54 , error , V_33 ) ;
for ( V_33 = 0 ; V_33 < error -> V_135 ; V_33 ++ ) {
F_14 ( V_29 , L_85 , V_33 ) ;
F_13 ( V_29 , L_86 ,
error -> V_136 [ V_33 ] ,
error -> V_137 [ V_33 ] ) ;
F_13 ( V_29 , L_87 ,
error -> V_138 [ V_33 ] ,
error -> V_139 [ V_33 ] ) ;
}
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_1 ) ; V_33 ++ ) {
V_89 = error -> V_1 [ V_33 ] . V_140 ;
if ( V_89 ) {
F_17 ( V_29 , V_99 -> V_1 [ V_33 ] . V_30 ) ;
if ( error -> V_1 [ V_33 ] . V_108 != - 1 )
F_14 ( V_29 , L_88 ,
error -> V_1 [ V_33 ] . V_109 ,
error -> V_1 [ V_33 ] . V_108 ) ;
F_14 ( V_29 , L_89 ,
F_15 ( V_89 -> V_34 ) ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
V_89 = error -> V_1 [ V_33 ] . V_141 ;
if ( V_89 ) {
F_14 ( V_29 , L_90 ,
V_99 -> V_1 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
if ( error -> V_1 [ V_33 ] . V_142 ) {
F_14 ( V_29 , L_91 ,
V_99 -> V_1 [ V_33 ] . V_30 ,
error -> V_1 [ V_33 ] . V_142 ) ;
for ( V_101 = 0 ; V_101 < error -> V_1 [ V_33 ] . V_142 ; V_101 ++ ) {
F_14 ( V_29 , L_92 ,
error -> V_1 [ V_33 ] . V_143 [ V_101 ] . V_82 ,
error -> V_1 [ V_33 ] . V_143 [ V_101 ] . V_144 ,
error -> V_1 [ V_33 ] . V_143 [ V_101 ] . V_60 ) ;
}
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_145 ) ) {
F_14 ( V_29 , L_93 ,
V_99 -> V_1 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_146 ) ) {
T_3 V_147 = V_89 -> V_34 ;
V_63 * V_146 = & V_89 -> V_95 [ 0 ] [ 0 ] ;
if ( V_41 . V_148 ) {
V_147 += V_149 * V_94 ;
V_146 = & V_89 -> V_95 [ V_149 ] [ 0 ] ;
}
F_14 ( V_29 , L_94 ,
V_99 -> V_1 [ V_33 ] . V_30 , V_147 ) ;
V_91 = 0 ;
for ( V_92 = 0 ; V_92 < V_94 / 16 ; V_92 += 4 ) {
F_14 ( V_29 , L_95 ,
V_91 ,
V_146 [ V_92 ] ,
V_146 [ V_92 + 1 ] ,
V_146 [ V_92 + 2 ] ,
V_146 [ V_92 + 3 ] ) ;
V_91 += 16 ;
}
}
if ( ( V_89 = error -> V_1 [ V_33 ] . V_150 ) ) {
F_14 ( V_29 , L_96 ,
V_99 -> V_1 [ V_33 ] . V_30 ,
F_16 ( V_89 -> V_34 ) ) ;
F_26 ( V_29 , V_89 ) ;
}
}
if ( ( V_89 = error -> V_151 ) ) {
F_14 ( V_29 , L_97 ,
F_16 ( V_89 -> V_34 ) ) ;
for ( V_92 = 0 ; V_92 < V_94 / 16 ; V_92 += 4 ) {
F_14 ( V_29 , L_95 ,
V_92 * 4 ,
V_89 -> V_95 [ 0 ] [ V_92 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 1 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 2 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 3 ] ) ;
}
}
if ( error -> V_152 )
F_34 ( V_29 , error -> V_152 ) ;
if ( error -> V_153 )
F_35 ( V_29 , V_54 , error -> V_153 ) ;
V_103:
if ( V_29 -> V_17 == 0 && V_29 -> V_16 )
return V_29 -> V_16 ;
return 0 ;
}
int F_36 ( struct V_14 * V_154 ,
struct V_98 * V_41 ,
T_1 V_32 , T_4 V_21 )
{
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
V_154 -> V_41 = V_41 ;
V_154 -> V_18 = V_32 + 1 > V_94 ? V_32 + 1 : V_94 ;
V_154 -> V_25 = F_37 ( V_154 -> V_18 ,
V_155 | V_156 | V_157 ) ;
if ( V_154 -> V_25 == NULL ) {
V_154 -> V_18 = V_94 ;
V_154 -> V_25 = F_37 ( V_154 -> V_18 , V_155 ) ;
}
if ( V_154 -> V_25 == NULL ) {
V_154 -> V_18 = 128 ;
V_154 -> V_25 = F_37 ( V_154 -> V_18 , V_155 ) ;
}
if ( V_154 -> V_25 == NULL )
return - V_158 ;
V_154 -> V_22 = V_21 ;
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
static void F_40 ( struct V_159 * V_160 )
{
struct V_55 * error = F_41 ( V_160 ,
F_42 ( * error ) , V_161 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < F_28 ( error -> V_1 ) ; V_33 ++ ) {
F_38 ( error -> V_1 [ V_33 ] . V_140 ) ;
F_38 ( error -> V_1 [ V_33 ] . V_141 ) ;
F_38 ( error -> V_1 [ V_33 ] . V_145 ) ;
F_38 ( error -> V_1 [ V_33 ] . V_146 ) ;
F_38 ( error -> V_1 [ V_33 ] . V_150 ) ;
F_39 ( error -> V_1 [ V_33 ] . V_143 ) ;
}
F_38 ( error -> V_151 ) ;
for ( V_33 = 0 ; V_33 < error -> V_135 ; V_33 ++ )
F_39 ( error -> V_136 [ V_33 ] ) ;
F_39 ( error -> V_136 ) ;
F_39 ( error -> V_137 ) ;
F_39 ( error -> V_138 ) ;
F_39 ( error -> V_139 ) ;
F_39 ( error -> V_152 ) ;
F_39 ( error -> V_153 ) ;
F_39 ( error ) ;
}
static struct V_88 *
F_43 ( struct V_98 * V_99 ,
struct V_162 * V_163 ,
struct V_164 * V_165 )
{
struct V_88 * V_166 ;
struct V_167 * V_168 = NULL ;
int V_169 ;
bool V_170 ;
int V_33 = 0 ;
T_3 V_171 ;
if ( V_163 == NULL || V_163 -> V_95 == NULL )
return NULL ;
V_169 = V_163 -> V_172 . V_18 >> V_173 ;
V_166 = F_37 ( sizeof( * V_166 ) + V_169 * sizeof( V_63 * ) , V_174 ) ;
if ( V_166 == NULL )
return NULL ;
if ( F_44 ( V_163 , V_165 ) )
V_166 -> V_34 = F_45 ( V_163 , V_165 ) ;
else
V_166 -> V_34 = - 1 ;
V_171 = V_166 -> V_34 ;
if ( F_46 ( V_165 ) )
V_168 = F_47 ( V_163 ) ;
V_170 = ( V_163 -> V_42 == V_175 &&
V_168 && ( V_168 -> V_176 & V_177 ) &&
V_171 + V_169 * V_94 <= V_99 -> V_178 . V_179 ) ;
if ( V_163 -> V_180 ) {
V_170 = true ;
if ( ! ( V_168 && V_168 -> V_176 & V_177 ) )
goto V_181;
V_171 = F_48 ( V_163 ) ;
if ( V_171 + V_169 * V_94 > V_99 -> V_178 . V_179 )
goto V_181;
}
if ( V_170 && V_163 -> V_42 != V_175 && ! F_49 ( V_99 -> V_54 ) )
goto V_181;
V_166 -> V_93 = V_169 ;
while ( V_169 -- ) {
unsigned long V_182 ;
void * V_183 ;
V_183 = F_37 ( V_94 , V_174 ) ;
if ( V_183 == NULL )
goto V_181;
F_50 ( V_182 ) ;
if ( V_170 ) {
void T_5 * V_184 ;
V_184 = F_51 ( V_99 -> V_178 . V_185 ,
V_171 ) ;
F_52 ( V_183 , V_184 , V_94 ) ;
F_53 ( V_184 ) ;
} else {
struct V_90 * V_90 ;
void * V_184 ;
V_90 = F_54 ( V_163 , V_33 ) ;
F_55 ( & V_90 , 1 ) ;
V_184 = F_56 ( V_90 ) ;
memcpy ( V_183 , V_184 , V_94 ) ;
F_57 ( V_184 ) ;
F_55 ( & V_90 , 1 ) ;
}
F_58 ( V_182 ) ;
V_166 -> V_95 [ V_33 ++ ] = V_183 ;
V_171 += V_94 ;
}
return V_166 ;
V_181:
while ( V_33 -- )
F_39 ( V_166 -> V_95 [ V_33 ] ) ;
F_39 ( V_166 ) ;
return NULL ;
}
static void F_59 ( struct V_31 * V_16 ,
struct V_167 * V_168 )
{
struct V_162 * V_89 = V_168 -> V_89 ;
int V_33 ;
V_16 -> V_18 = V_89 -> V_172 . V_18 ;
V_16 -> V_30 = V_89 -> V_172 . V_30 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ )
V_16 -> V_38 [ V_33 ] = F_60 ( V_89 -> V_186 [ V_33 ] ) ;
V_16 -> V_39 = F_60 ( V_89 -> V_187 ) ;
V_16 -> V_34 = V_168 -> V_188 . V_22 ;
V_16 -> V_35 = V_89 -> V_172 . V_35 ;
V_16 -> V_36 = V_89 -> V_172 . V_36 ;
V_16 -> V_43 = V_89 -> V_43 ;
V_16 -> V_7 = 0 ;
if ( F_61 ( V_89 ) )
V_16 -> V_7 = 1 ;
V_16 -> V_8 = V_89 -> V_189 ;
V_16 -> V_12 = V_89 -> V_12 ;
V_16 -> V_13 = V_89 -> V_190 != V_191 ;
V_16 -> V_40 = V_89 -> V_40 . V_192 != NULL ;
V_16 -> V_1 = V_89 -> V_187 ?
F_62 ( V_89 -> V_187 ) -> V_193 : - 1 ;
V_16 -> V_42 = V_89 -> V_42 ;
}
static V_63 F_63 ( struct V_31 * V_16 ,
int V_32 , struct V_194 * V_59 )
{
struct V_167 * V_168 ;
int V_33 = 0 ;
F_64 (vma, head, mm_list) {
F_59 ( V_16 ++ , V_168 ) ;
if ( ++ V_33 == V_32 )
break;
}
return V_33 ;
}
static V_63 F_65 ( struct V_31 * V_16 ,
int V_32 , struct V_194 * V_59 ,
struct V_164 * V_165 )
{
struct V_162 * V_89 ;
struct V_31 * const V_195 = V_16 ;
struct V_31 * const V_196 = V_16 + V_32 ;
F_64 (obj, head, global_list) {
struct V_167 * V_168 ;
if ( V_16 == V_196 )
break;
F_64 (vma, &obj->vma_list, vma_link)
if ( V_168 -> V_165 == V_165 && V_168 -> V_197 > 0 )
F_59 ( V_16 ++ , V_168 ) ;
}
return V_16 - V_195 ;
}
static T_6 F_66 ( struct V_98 * V_99 ,
struct V_55 * error ,
int * V_198 )
{
T_6 V_199 = 0 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
if ( error -> V_1 [ V_33 ] . V_86 == V_52 ) {
if ( V_198 )
* V_198 = V_33 ;
return error -> V_1 [ V_33 ] . V_66 ^ error -> V_1 [ V_33 ] . V_67 ;
}
}
return V_199 ;
}
static void F_67 ( struct V_53 * V_54 ,
struct V_55 * error )
{
struct V_98 * V_99 = V_54 -> V_100 ;
int V_33 ;
if ( F_68 ( V_54 ) || F_69 ( V_54 ) ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_128 ; V_33 ++ )
error -> V_129 [ V_33 ] = F_70 ( F_71 ( V_33 ) ) ;
} else if ( F_72 ( V_54 ) || F_73 ( V_54 ) ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_128 ; V_33 ++ )
error -> V_129 [ V_33 ] = F_74 ( F_75 ( V_33 ) ) ;
} else if ( F_21 ( V_54 ) -> V_68 >= 6 ) {
for ( V_33 = 0 ; V_33 < V_99 -> V_128 ; V_33 ++ )
error -> V_129 [ V_33 ] = F_74 ( F_76 ( V_33 ) ) ;
}
}
static void F_77 ( struct V_98 * V_99 ,
struct V_55 * error ,
struct V_200 * V_1 ,
struct V_57 * V_201 )
{
struct V_200 * V_202 ;
int V_33 ;
if ( ! F_78 ( V_99 -> V_54 ) )
return;
if ( ! error -> V_151 )
error -> V_151 =
F_79 ( V_99 ,
V_99 -> V_151 ) ;
F_80 (to, dev_priv, i) {
int V_203 ;
T_7 V_204 ;
V_63 * V_27 ;
if ( V_1 == V_202 )
continue;
V_204 = ( F_81 ( V_1 , V_33 ) & ( V_94 - 1 ) )
/ 4 ;
V_27 = error -> V_151 -> V_95 [ 0 ] ;
V_203 = F_82 ( V_1 , V_202 ) ;
V_201 -> V_76 [ V_203 ] = V_27 [ V_204 ] ;
V_201 -> V_77 [ V_203 ] = V_1 -> V_205 . V_206 [ V_203 ] ;
}
}
static void F_83 ( struct V_98 * V_99 ,
struct V_200 * V_1 ,
struct V_57 * V_201 )
{
V_201 -> V_76 [ 0 ] = F_70 ( F_84 ( V_1 -> V_207 ) ) ;
V_201 -> V_76 [ 1 ] = F_70 ( F_85 ( V_1 -> V_207 ) ) ;
V_201 -> V_77 [ 0 ] = V_1 -> V_205 . V_206 [ 0 ] ;
V_201 -> V_77 [ 1 ] = V_1 -> V_205 . V_206 [ 1 ] ;
if ( F_22 ( V_99 -> V_54 ) ) {
V_201 -> V_76 [ 2 ] =
F_70 ( F_86 ( V_1 -> V_207 ) ) ;
V_201 -> V_77 [ 2 ] = V_1 -> V_205 . V_206 [ 2 ] ;
}
}
static void F_87 ( struct V_53 * V_54 ,
struct V_55 * error ,
struct V_200 * V_1 ,
struct V_57 * V_201 )
{
struct V_98 * V_99 = V_54 -> V_100 ;
if ( F_21 ( V_54 ) -> V_68 >= 6 ) {
V_201 -> V_74 = F_70 ( F_88 ( V_1 -> V_207 ) ) ;
V_201 -> V_75 = F_70 ( F_89 ( V_1 ) ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 )
F_77 ( V_99 , error , V_1 , V_201 ) ;
else
F_83 ( V_99 , V_1 , V_201 ) ;
}
if ( F_21 ( V_54 ) -> V_68 >= 4 ) {
V_201 -> V_73 = F_70 ( F_90 ( V_1 -> V_207 ) ) ;
V_201 -> V_65 = F_70 ( F_91 ( V_1 -> V_207 ) ) ;
V_201 -> V_66 = F_70 ( F_92 ( V_1 -> V_207 ) ) ;
V_201 -> V_67 = F_70 ( F_93 ( V_1 -> V_207 ) ) ;
V_201 -> V_71 = F_70 ( F_94 ( V_1 -> V_207 ) ) ;
V_201 -> V_69 = F_70 ( F_95 ( V_1 -> V_207 ) ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 ) {
V_201 -> V_73 |= ( T_3 ) F_70 ( F_96 ( V_1 -> V_207 ) ) << 32 ;
V_201 -> V_69 |= ( T_3 ) F_70 ( F_97 ( V_1 -> V_207 ) ) << 32 ;
}
V_201 -> V_70 = F_70 ( F_98 ( V_1 -> V_207 ) ) ;
} else {
V_201 -> V_73 = F_70 ( V_208 ) ;
V_201 -> V_65 = F_70 ( V_209 ) ;
V_201 -> V_66 = F_70 ( V_210 ) ;
V_201 -> V_67 = F_70 ( V_211 ) ;
}
V_201 -> V_83 = F_99 ( & V_1 -> V_212 ) ;
V_201 -> V_72 = F_70 ( F_100 ( V_1 -> V_207 ) ) ;
V_201 -> V_82 = V_1 -> V_213 ( V_1 , false ) ;
V_201 -> V_64 = F_101 ( V_1 ) ;
V_201 -> V_22 = F_102 ( V_1 ) ;
V_201 -> V_59 = F_103 ( V_1 ) ;
V_201 -> V_60 = F_104 ( V_1 ) ;
V_201 -> V_61 = F_105 ( V_1 ) ;
if ( F_106 ( V_54 ) ) {
T_8 V_214 ;
if ( F_107 ( V_54 ) ) {
switch ( V_1 -> V_193 ) {
default:
case V_2 :
V_214 = V_215 ;
break;
case V_4 :
V_214 = V_216 ;
break;
case V_3 :
V_214 = V_217 ;
break;
case V_5 :
V_214 = V_218 ;
break;
}
} else if ( F_108 ( V_1 -> V_54 ) ) {
V_214 = F_109 ( V_1 -> V_207 ) ;
} else {
V_214 = F_110 ( V_1 -> V_207 ) ;
}
V_201 -> V_62 = F_70 ( V_214 ) ;
}
V_201 -> V_87 = V_1 -> V_219 . V_220 ;
V_201 -> V_86 = V_1 -> V_219 . V_221 ;
if ( F_23 ( V_54 ) ) {
int V_33 ;
V_201 -> V_78 . V_79 = F_70 ( F_111 ( V_1 ) ) ;
if ( F_108 ( V_54 ) )
V_201 -> V_78 . V_81 =
F_70 ( F_112 ( V_1 ) ) ;
else if ( F_107 ( V_54 ) )
V_201 -> V_78 . V_81 =
F_70 ( F_113 ( V_1 ) ) ;
else if ( F_21 ( V_54 ) -> V_68 >= 8 )
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ ) {
V_201 -> V_78 . V_80 [ V_33 ] =
F_70 ( F_114 ( V_1 , V_33 ) ) ;
V_201 -> V_78 . V_80 [ V_33 ] <<= 32 ;
V_201 -> V_78 . V_80 [ V_33 ] |=
F_70 ( F_115 ( V_1 , V_33 ) ) ;
}
}
}
static void F_116 ( struct V_200 * V_1 ,
struct V_55 * error ,
struct V_57 * V_201 )
{
struct V_98 * V_99 = V_1 -> V_54 -> V_100 ;
struct V_162 * V_89 ;
if ( V_1 -> V_193 != V_2 || ! error -> V_125 )
return;
F_64 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_117 ( V_89 ) )
continue;
if ( ( error -> V_125 & V_222 ) == F_48 ( V_89 ) ) {
V_201 -> V_150 = F_79 ( V_99 , V_89 ) ;
break;
}
}
}
static void F_118 ( struct V_53 * V_54 ,
struct V_55 * error )
{
struct V_98 * V_99 = V_54 -> V_100 ;
struct V_223 * V_224 ;
int V_33 , V_32 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
struct V_200 * V_1 = & V_99 -> V_1 [ V_33 ] ;
struct V_225 * V_226 ;
error -> V_1 [ V_33 ] . V_108 = - 1 ;
if ( V_1 -> V_54 == NULL )
continue;
error -> V_1 [ V_33 ] . V_58 = true ;
F_87 ( V_54 , error , V_1 , & error -> V_1 [ V_33 ] ) ;
V_224 = F_119 ( V_1 ) ;
if ( V_224 ) {
struct V_164 * V_165 ;
V_165 = V_224 -> V_150 && V_224 -> V_150 -> V_227 ?
& V_224 -> V_150 -> V_227 -> V_172 :
& V_99 -> V_178 . V_172 ;
error -> V_1 [ V_33 ] . V_140 =
F_43 ( V_99 ,
V_224 -> V_228 ,
V_165 ) ;
if ( F_120 ( V_99 -> V_54 ) )
error -> V_1 [ V_33 ] . V_141 =
F_79 ( V_99 ,
V_1 -> V_229 . V_89 ) ;
if ( V_224 -> V_108 ) {
struct V_230 * V_231 ;
F_121 () ;
V_231 = F_122 ( V_224 -> V_108 , V_232 ) ;
if ( V_231 ) {
strcpy ( error -> V_1 [ V_33 ] . V_109 , V_231 -> V_109 ) ;
error -> V_1 [ V_33 ] . V_108 = V_231 -> V_108 ;
}
F_123 () ;
}
}
if ( V_41 . V_148 ) {
if ( V_224 )
V_226 = V_224 -> V_150 -> V_233 [ V_1 -> V_193 ] . V_234 ;
else
V_226 = V_1 -> V_235 -> V_233 [ V_1 -> V_193 ] . V_234 ;
} else
V_226 = V_1 -> V_236 ;
error -> V_1 [ V_33 ] . V_84 = V_226 -> V_59 ;
error -> V_1 [ V_33 ] . V_85 = V_226 -> V_60 ;
error -> V_1 [ V_33 ] . V_145 =
F_79 ( V_99 , V_226 -> V_89 ) ;
error -> V_1 [ V_33 ] . V_146 =
F_79 ( V_99 , V_1 -> V_237 . V_89 ) ;
F_116 ( V_1 , error , & error -> V_1 [ V_33 ] ) ;
V_32 = 0 ;
F_64 (request, &ring->request_list, list)
V_32 ++ ;
error -> V_1 [ V_33 ] . V_142 = V_32 ;
error -> V_1 [ V_33 ] . V_143 =
F_124 ( V_32 , sizeof( * error -> V_1 [ V_33 ] . V_143 ) ,
V_174 ) ;
if ( error -> V_1 [ V_33 ] . V_143 == NULL ) {
error -> V_1 [ V_33 ] . V_142 = 0 ;
continue;
}
V_32 = 0 ;
F_64 (request, &ring->request_list, list) {
struct V_238 * V_239 ;
if ( V_32 >= error -> V_1 [ V_33 ] . V_142 ) {
break;
}
V_239 = & error -> V_1 [ V_33 ] . V_143 [ V_32 ++ ] ;
V_239 -> V_82 = V_224 -> V_82 ;
V_239 -> V_144 = V_224 -> V_240 ;
V_239 -> V_60 = V_224 -> V_241 ;
}
}
}
static void F_125 ( struct V_98 * V_99 ,
struct V_55 * error ,
struct V_164 * V_165 ,
const int V_242 )
{
struct V_31 * V_136 = NULL , * V_138 = NULL ;
struct V_162 * V_89 ;
struct V_167 * V_168 ;
int V_33 ;
V_33 = 0 ;
F_64 (vma, &vm->active_list, mm_list)
V_33 ++ ;
error -> V_137 [ V_242 ] = V_33 ;
F_64 (obj, &dev_priv->mm.bound_list, global_list) {
F_64 (vma, &obj->vma_list, vma_link)
if ( V_168 -> V_165 == V_165 && V_168 -> V_197 > 0 )
V_33 ++ ;
}
error -> V_139 [ V_242 ] = V_33 - error -> V_137 [ V_242 ] ;
if ( V_33 ) {
V_136 = F_124 ( V_33 , sizeof( * V_136 ) , V_174 ) ;
if ( V_136 )
V_138 = V_136 + error -> V_137 [ V_242 ] ;
}
if ( V_136 )
error -> V_137 [ V_242 ] =
F_63 ( V_136 ,
error -> V_137 [ V_242 ] ,
& V_165 -> V_243 ) ;
if ( V_138 )
error -> V_139 [ V_242 ] =
F_65 ( V_138 ,
error -> V_139 [ V_242 ] ,
& V_99 -> V_192 . V_244 , V_165 ) ;
error -> V_136 [ V_242 ] = V_136 ;
error -> V_138 [ V_242 ] = V_138 ;
}
static void F_126 ( struct V_98 * V_99 ,
struct V_55 * error )
{
struct V_164 * V_165 ;
int V_245 = 0 , V_33 = 0 ;
F_64 (vm, &dev_priv->vm_list, global_link)
V_245 ++ ;
error -> V_136 = F_124 ( V_245 , sizeof( * error -> V_136 ) , V_174 ) ;
error -> V_138 = F_124 ( V_245 , sizeof( * error -> V_138 ) , V_174 ) ;
error -> V_137 = F_124 ( V_245 , sizeof( * error -> V_137 ) ,
V_174 ) ;
error -> V_139 = F_124 ( V_245 , sizeof( * error -> V_139 ) ,
V_174 ) ;
if ( error -> V_136 == NULL ||
error -> V_138 == NULL ||
error -> V_137 == NULL ||
error -> V_139 == NULL ) {
F_39 ( error -> V_136 ) ;
F_39 ( error -> V_137 ) ;
F_39 ( error -> V_138 ) ;
F_39 ( error -> V_139 ) ;
error -> V_136 = NULL ;
error -> V_137 = NULL ;
error -> V_138 = NULL ;
error -> V_139 = NULL ;
} else {
F_64 (vm, &dev_priv->vm_list, global_link)
F_125 ( V_99 , error , V_165 , V_33 ++ ) ;
error -> V_135 = V_245 ;
}
}
static void F_127 ( struct V_98 * V_99 ,
struct V_55 * error )
{
struct V_53 * V_54 = V_99 -> V_54 ;
int V_33 ;
if ( F_33 ( V_54 ) ) {
error -> V_121 [ 0 ] = F_70 ( V_246 ) ;
error -> V_120 = F_70 ( V_247 ) ;
error -> V_123 = F_128 ( V_248 ) ;
}
if ( F_107 ( V_54 ) )
error -> V_134 = F_70 ( V_249 ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 ) {
error -> V_132 = F_70 ( V_250 ) ;
error -> V_131 = F_70 ( V_251 ) ;
}
if ( F_108 ( V_54 ) ) {
error -> V_123 = F_128 ( V_252 ) ;
error -> V_253 = F_70 ( V_254 ) ;
error -> V_79 = F_70 ( V_255 ) ;
}
if ( F_21 ( V_54 ) -> V_68 >= 7 )
error -> V_123 = F_128 ( V_256 ) ;
if ( F_21 ( V_54 ) -> V_68 >= 6 ) {
error -> V_124 = F_70 ( V_257 ) ;
error -> error = F_70 ( V_258 ) ;
error -> V_133 = F_70 ( V_259 ) ;
}
if ( F_108 ( V_54 ) || F_107 ( V_54 ) ) {
error -> V_260 = F_70 ( V_261 ) ;
error -> V_262 = F_70 ( V_263 ) ;
}
if ( F_129 ( V_54 ) )
error -> V_125 = F_70 ( V_264 ) ;
if ( F_21 ( V_54 ) -> V_68 >= 8 ) {
error -> V_120 = F_70 ( V_265 ) ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
error -> V_121 [ V_33 ] = F_70 ( F_130 ( V_33 ) ) ;
} else if ( F_32 ( V_54 ) ) {
error -> V_120 = F_70 ( V_266 ) ;
error -> V_121 [ 0 ] = F_70 ( V_246 ) ;
} else if ( F_69 ( V_54 ) ) {
error -> V_120 = F_131 ( V_267 ) ;
} else if ( ! F_33 ( V_54 ) ) {
error -> V_120 = F_70 ( V_267 ) ;
}
error -> V_119 = F_70 ( V_268 ) ;
error -> V_122 = F_70 ( V_269 ) ;
F_132 ( V_54 , error -> V_130 ) ;
}
static void F_133 ( struct V_53 * V_54 ,
struct V_55 * error ,
bool V_270 ,
const char * V_104 )
{
struct V_98 * V_99 = V_54 -> V_100 ;
V_63 V_271 ;
int V_198 = - 1 , V_20 ;
V_271 = F_66 ( V_99 , error , & V_198 ) ;
V_20 = F_134 ( error -> V_104 , sizeof( error -> V_104 ) ,
L_98 ,
F_21 ( V_54 ) -> V_68 , V_198 , V_271 ) ;
if ( V_198 != - 1 && error -> V_1 [ V_198 ] . V_108 != - 1 )
V_20 += F_134 ( error -> V_104 + V_20 ,
sizeof( error -> V_104 ) - V_20 ,
L_99 ,
error -> V_1 [ V_198 ] . V_109 ,
error -> V_1 [ V_198 ] . V_108 ) ;
F_134 ( error -> V_104 + V_20 , sizeof( error -> V_104 ) - V_20 ,
L_100 ,
V_104 ,
V_270 ? L_101 : L_102 ) ;
}
static void F_135 ( struct V_98 * V_99 ,
struct V_55 * error )
{
error -> V_114 = - 1 ;
#ifdef F_136
error -> V_114 = V_272 ;
#endif
error -> V_110 = F_137 ( & V_99 -> V_126 ) ;
error -> V_111 = V_99 -> V_111 ;
}
void F_138 ( struct V_53 * V_54 , bool V_270 ,
const char * V_104 )
{
static bool V_273 ;
struct V_98 * V_99 = V_54 -> V_100 ;
struct V_55 * error ;
unsigned long V_182 ;
error = F_139 ( sizeof( * error ) , V_174 ) ;
if ( ! error ) {
F_140 ( L_103 ) ;
return;
}
F_141 ( & error -> V_161 ) ;
F_135 ( V_99 , error ) ;
F_127 ( V_99 , error ) ;
F_126 ( V_99 , error ) ;
F_67 ( V_54 , error ) ;
F_118 ( V_54 , error ) ;
F_142 ( & error -> time ) ;
error -> V_152 = F_143 ( V_54 ) ;
error -> V_153 = F_144 ( V_54 ) ;
F_133 ( V_54 , error , V_270 , V_104 ) ;
F_145 ( L_60 , error -> V_104 ) ;
F_146 ( & V_99 -> V_126 . V_274 , V_182 ) ;
if ( V_99 -> V_126 . V_275 == NULL ) {
V_99 -> V_126 . V_275 = error ;
error = NULL ;
}
F_147 ( & V_99 -> V_126 . V_274 , V_182 ) ;
if ( error ) {
F_40 ( & error -> V_161 ) ;
return;
}
if ( ! V_273 ) {
F_145 ( L_104 ) ;
F_145 ( L_105 ) ;
F_145 ( L_106 ) ;
F_145 ( L_107 ) ;
F_145 ( L_108 , V_54 -> V_276 -> V_277 ) ;
V_273 = true ;
}
}
void F_148 ( struct V_53 * V_54 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = V_54 -> V_100 ;
F_149 ( & V_99 -> V_126 . V_274 ) ;
V_97 -> error = V_99 -> V_126 . V_275 ;
if ( V_97 -> error )
F_150 ( & V_97 -> error -> V_161 ) ;
F_151 ( & V_99 -> V_126 . V_274 ) ;
}
void F_152 ( struct V_96 * V_97 )
{
if ( V_97 -> error )
F_153 ( & V_97 -> error -> V_161 , F_40 ) ;
}
void F_154 ( struct V_53 * V_54 )
{
struct V_98 * V_99 = V_54 -> V_100 ;
struct V_55 * error ;
F_149 ( & V_99 -> V_126 . V_274 ) ;
error = V_99 -> V_126 . V_275 ;
V_99 -> V_126 . V_275 = NULL ;
F_151 ( & V_99 -> V_126 . V_274 ) ;
if ( error )
F_153 ( & error -> V_161 , F_40 ) ;
}
const char * F_18 ( struct V_98 * V_41 , int type )
{
switch ( type ) {
case V_175 : return L_109 ;
case V_278 : return F_49 ( V_41 ) ? L_110 : L_111 ;
case V_279 : return L_112 ;
case V_280 : return L_113 ;
default: return L_6 ;
}
}
void F_132 ( struct V_53 * V_54 , T_6 * V_67 )
{
struct V_98 * V_99 = V_54 -> V_100 ;
memset ( V_67 , 0 , sizeof( * V_67 ) * V_281 ) ;
if ( F_69 ( V_54 ) || F_68 ( V_54 ) )
V_67 [ 0 ] = F_70 ( V_211 ) ;
else if ( F_73 ( V_54 ) || F_72 ( V_54 ) || F_108 ( V_54 ) ) {
V_67 [ 0 ] = F_70 ( F_93 ( V_282 ) ) ;
V_67 [ 1 ] = F_70 ( V_283 ) ;
} else if ( F_21 ( V_54 ) -> V_68 >= 7 ) {
V_67 [ 0 ] = F_70 ( F_93 ( V_282 ) ) ;
V_67 [ 1 ] = F_70 ( V_284 ) ;
V_67 [ 2 ] = F_70 ( V_285 ) ;
V_67 [ 3 ] = F_70 ( V_286 ) ;
}
}
