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
struct V_54 * error ,
int V_55 )
{
struct V_56 * V_2 = & error -> V_2 [ V_55 ] ;
if ( ! V_2 -> V_57 )
return;
F_15 ( V_30 , L_30 , F_2 ( V_55 ) ) ;
F_15 ( V_30 , L_31 , V_2 -> V_58 ) ;
F_15 ( V_30 , L_32 , V_2 -> V_59 ) ;
F_15 ( V_30 , L_33 , V_2 -> V_60 ) ;
F_15 ( V_30 , L_34 , V_2 -> V_61 ) ;
F_15 ( V_30 , L_35 , ( V_62 ) ( V_2 -> V_63 >> 32 ) , ( V_62 ) V_2 -> V_63 ) ;
F_15 ( V_30 , L_36 , V_2 -> V_64 ) ;
F_15 ( V_30 , L_37 , V_2 -> V_65 ) ;
F_15 ( V_30 , L_38 , V_2 -> V_66 ) ;
if ( F_20 ( V_53 ) -> V_67 >= 4 ) {
F_15 ( V_30 , L_39 , ( V_62 ) ( V_2 -> V_68 >> 32 ) , ( V_62 ) V_2 -> V_68 ) ;
F_15 ( V_30 , L_40 , V_2 -> V_69 ) ;
F_15 ( V_30 , L_41 , V_2 -> V_70 ) ;
}
F_15 ( V_30 , L_42 , V_2 -> V_71 ) ;
F_15 ( V_30 , L_43 , F_21 ( V_2 -> V_72 ) ,
F_22 ( V_2 -> V_72 ) ) ;
if ( F_20 ( V_53 ) -> V_67 >= 6 ) {
F_15 ( V_30 , L_44 , V_2 -> V_73 ) ;
F_15 ( V_30 , L_45 , V_2 -> V_74 ) ;
F_15 ( V_30 , L_46 ,
V_2 -> V_75 [ 0 ] ,
V_2 -> V_76 [ 0 ] ) ;
F_15 ( V_30 , L_47 ,
V_2 -> V_75 [ 1 ] ,
V_2 -> V_76 [ 1 ] ) ;
if ( F_23 ( V_53 ) ) {
F_15 ( V_30 , L_48 ,
V_2 -> V_75 [ 2 ] ,
V_2 -> V_76 [ 2 ] ) ;
}
}
if ( F_24 ( V_53 ) ) {
F_15 ( V_30 , L_49 , V_2 -> V_77 . V_78 ) ;
if ( F_20 ( V_53 ) -> V_67 >= 8 ) {
int V_79 ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ )
F_15 ( V_30 , L_50 ,
V_79 , V_2 -> V_77 . V_80 [ V_79 ] ) ;
} else {
F_15 ( V_30 , L_51 ,
V_2 -> V_77 . V_81 ) ;
}
}
F_15 ( V_30 , L_52 , V_2 -> V_82 ) ;
F_15 ( V_30 , L_53 , F_1 ( V_2 -> V_83 ) ) ;
F_15 ( V_30 , L_54 , V_2 -> V_84 ) ;
F_15 ( V_30 , L_55 , V_2 -> V_85 ) ;
F_15 ( V_30 , L_56 ,
F_18 ( V_2 -> V_86 ) ,
V_2 -> V_87 ) ;
}
void F_25 ( struct V_15 * V_16 , const char * V_27 , ... )
{
T_2 args ;
va_start ( args , V_27 ) ;
F_11 ( V_16 , V_27 , args ) ;
va_end ( args ) ;
}
static void F_26 ( struct V_15 * V_30 ,
struct V_88 * V_89 )
{
int V_90 , V_91 , V_92 ;
for ( V_90 = V_91 = 0 ; V_90 < V_89 -> V_93 ; V_90 ++ ) {
for ( V_92 = 0 ; V_92 < V_94 / 4 ; V_92 ++ ) {
F_15 ( V_30 , L_57 , V_91 ,
V_89 -> V_95 [ V_90 ] [ V_92 ] ) ;
V_91 += 4 ;
}
}
}
int F_27 ( struct V_15 * V_30 ,
const struct V_96 * V_97 )
{
struct V_52 * V_53 = V_97 -> V_53 ;
struct V_98 * V_99 = V_53 -> V_100 ;
struct V_54 * error = V_97 -> error ;
struct V_88 * V_89 ;
int V_79 , V_101 , V_91 , V_92 ;
int V_102 ;
if ( ! error ) {
F_15 ( V_30 , L_58 ) ;
goto V_103;
}
F_15 ( V_30 , L_59 , error -> V_104 ) ;
F_15 ( V_30 , L_60 , error -> time . V_105 ,
error -> time . V_106 ) ;
F_15 ( V_30 , L_61 V_107 L_22 ) ;
V_102 = 0 ;
for ( V_79 = 0 ; V_79 < F_28 ( error -> V_2 ) ; V_79 ++ ) {
if ( error -> V_2 [ V_79 ] . V_87 > V_102 )
V_102 = error -> V_2 [ V_79 ] . V_87 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( error -> V_2 ) ; V_79 ++ ) {
if ( error -> V_2 [ V_79 ] . V_87 == V_102 &&
error -> V_2 [ V_79 ] . V_108 != - 1 ) {
F_15 ( V_30 , L_62 ,
F_2 ( V_79 ) ,
error -> V_2 [ V_79 ] . V_109 ,
error -> V_2 [ V_79 ] . V_108 ) ;
}
}
F_15 ( V_30 , L_63 , error -> V_110 ) ;
F_15 ( V_30 , L_64 , error -> V_111 ) ;
F_15 ( V_30 , L_65 , V_53 -> V_112 -> V_113 ) ;
F_15 ( V_30 , L_66 , error -> V_114 ) ;
F_15 ( V_30 , L_67 , error -> V_115 ) ;
if ( F_20 ( V_53 ) -> V_67 >= 8 ) {
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ )
F_15 ( V_30 , L_68 , V_79 ,
error -> V_116 [ V_79 ] ) ;
} else if ( F_29 ( V_53 ) || F_30 ( V_53 ) )
F_15 ( V_30 , L_69 , error -> V_116 [ 0 ] ) ;
F_15 ( V_30 , L_70 , error -> V_117 ) ;
F_15 ( V_30 , L_71 , error -> V_118 ) ;
F_15 ( V_30 , L_72 , error -> V_119 ) ;
F_15 ( V_30 , L_73 , error -> V_120 ) ;
F_15 ( V_30 , L_74 , V_99 -> V_121 . V_122 ) ;
for ( V_79 = 0 ; V_79 < V_99 -> V_123 ; V_79 ++ )
F_15 ( V_30 , L_75 , V_79 , error -> V_124 [ V_79 ] ) ;
for ( V_79 = 0 ; V_79 < F_28 ( error -> V_125 ) ; V_79 ++ )
F_15 ( V_30 , L_76 , V_79 ,
error -> V_125 [ V_79 ] ) ;
if ( F_20 ( V_53 ) -> V_67 >= 6 ) {
F_15 ( V_30 , L_77 , error -> error ) ;
F_15 ( V_30 , L_78 , error -> V_126 ) ;
}
if ( F_20 ( V_53 ) -> V_67 == 7 )
F_15 ( V_30 , L_79 , error -> V_127 ) ;
for ( V_79 = 0 ; V_79 < F_28 ( error -> V_2 ) ; V_79 ++ )
F_19 ( V_30 , V_53 , error , V_79 ) ;
for ( V_79 = 0 ; V_79 < error -> V_128 ; V_79 ++ ) {
F_15 ( V_30 , L_80 , V_79 ) ;
F_14 ( V_30 , L_81 ,
error -> V_129 [ V_79 ] ,
error -> V_130 [ V_79 ] ) ;
F_14 ( V_30 , L_82 ,
error -> V_131 [ V_79 ] ,
error -> V_132 [ V_79 ] ) ;
}
for ( V_79 = 0 ; V_79 < F_28 ( error -> V_2 ) ; V_79 ++ ) {
V_89 = error -> V_2 [ V_79 ] . V_133 ;
if ( V_89 ) {
F_16 ( V_30 , V_99 -> V_2 [ V_79 ] . V_31 ) ;
if ( error -> V_2 [ V_79 ] . V_108 != - 1 )
F_15 ( V_30 , L_83 ,
error -> V_2 [ V_79 ] . V_109 ,
error -> V_2 [ V_79 ] . V_108 ) ;
F_15 ( V_30 , L_84 ,
V_89 -> V_34 ) ;
F_26 ( V_30 , V_89 ) ;
}
V_89 = error -> V_2 [ V_79 ] . V_134 ;
if ( V_89 ) {
F_15 ( V_30 , L_85 ,
V_99 -> V_2 [ V_79 ] . V_31 , V_89 -> V_34 ) ;
F_26 ( V_30 , V_89 ) ;
}
if ( error -> V_2 [ V_79 ] . V_135 ) {
F_15 ( V_30 , L_86 ,
V_99 -> V_2 [ V_79 ] . V_31 ,
error -> V_2 [ V_79 ] . V_135 ) ;
for ( V_101 = 0 ; V_101 < error -> V_2 [ V_79 ] . V_135 ; V_101 ++ ) {
F_15 ( V_30 , L_87 ,
error -> V_2 [ V_79 ] . V_136 [ V_101 ] . V_82 ,
error -> V_2 [ V_79 ] . V_136 [ V_101 ] . V_137 ,
error -> V_2 [ V_79 ] . V_136 [ V_101 ] . V_59 ) ;
}
}
if ( ( V_89 = error -> V_2 [ V_79 ] . V_138 ) ) {
F_15 ( V_30 , L_88 ,
V_99 -> V_2 [ V_79 ] . V_31 ,
V_89 -> V_34 ) ;
F_26 ( V_30 , V_89 ) ;
}
if ( ( V_89 = error -> V_2 [ V_79 ] . V_139 ) ) {
F_15 ( V_30 , L_89 ,
V_99 -> V_2 [ V_79 ] . V_31 ,
V_89 -> V_34 ) ;
V_91 = 0 ;
for ( V_92 = 0 ; V_92 < V_94 / 16 ; V_92 += 4 ) {
F_15 ( V_30 , L_90 ,
V_91 ,
V_89 -> V_95 [ 0 ] [ V_92 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 1 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 2 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 3 ] ) ;
V_91 += 16 ;
}
}
if ( ( V_89 = error -> V_2 [ V_79 ] . V_140 ) ) {
F_15 ( V_30 , L_91 ,
V_99 -> V_2 [ V_79 ] . V_31 ,
V_89 -> V_34 ) ;
F_26 ( V_30 , V_89 ) ;
}
}
if ( ( V_89 = error -> V_141 ) ) {
F_15 ( V_30 , L_92 , V_89 -> V_34 ) ;
for ( V_92 = 0 ; V_92 < V_94 / 16 ; V_92 += 4 ) {
F_15 ( V_30 , L_90 ,
V_92 * 4 ,
V_89 -> V_95 [ 0 ] [ V_92 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 1 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 2 ] ,
V_89 -> V_95 [ 0 ] [ V_92 + 3 ] ) ;
}
}
if ( error -> V_142 )
F_31 ( V_30 , error -> V_142 ) ;
if ( error -> V_143 )
F_32 ( V_30 , V_53 , error -> V_143 ) ;
V_103:
if ( V_30 -> V_18 == 0 && V_30 -> V_17 )
return V_30 -> V_17 ;
return 0 ;
}
int F_33 ( struct V_15 * V_144 ,
struct V_98 * V_40 ,
T_1 V_33 , T_3 V_22 )
{
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
V_144 -> V_40 = V_40 ;
V_144 -> V_19 = V_33 + 1 > V_94 ? V_33 + 1 : V_94 ;
V_144 -> V_26 = F_34 ( V_144 -> V_19 ,
V_145 | V_146 | V_147 ) ;
if ( V_144 -> V_26 == NULL ) {
V_144 -> V_19 = V_94 ;
V_144 -> V_26 = F_34 ( V_144 -> V_19 , V_145 ) ;
}
if ( V_144 -> V_26 == NULL ) {
V_144 -> V_19 = 128 ;
V_144 -> V_26 = F_34 ( V_144 -> V_19 , V_145 ) ;
}
if ( V_144 -> V_26 == NULL )
return - V_148 ;
V_144 -> V_23 = V_22 ;
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
static void F_37 ( struct V_149 * V_150 )
{
struct V_54 * error = F_38 ( V_150 ,
F_39 ( * error ) , V_151 ) ;
int V_79 ;
for ( V_79 = 0 ; V_79 < F_28 ( error -> V_2 ) ; V_79 ++ ) {
F_35 ( error -> V_2 [ V_79 ] . V_133 ) ;
F_35 ( error -> V_2 [ V_79 ] . V_138 ) ;
F_35 ( error -> V_2 [ V_79 ] . V_139 ) ;
F_35 ( error -> V_2 [ V_79 ] . V_140 ) ;
F_36 ( error -> V_2 [ V_79 ] . V_136 ) ;
}
F_35 ( error -> V_141 ) ;
F_36 ( error -> V_129 ) ;
F_36 ( error -> V_142 ) ;
F_36 ( error -> V_143 ) ;
F_36 ( error ) ;
}
static struct V_88 *
F_40 ( struct V_98 * V_99 ,
struct V_152 * V_153 ,
struct V_154 * V_155 )
{
struct V_88 * V_156 ;
struct V_157 * V_158 = NULL ;
int V_159 ;
bool V_160 ;
int V_79 = 0 ;
V_62 V_161 ;
if ( V_153 == NULL || V_153 -> V_95 == NULL )
return NULL ;
V_159 = V_153 -> V_162 . V_19 >> V_163 ;
V_156 = F_34 ( sizeof( * V_156 ) + V_159 * sizeof( V_62 * ) , V_164 ) ;
if ( V_156 == NULL )
return NULL ;
if ( F_41 ( V_153 , V_155 ) )
V_156 -> V_34 = F_42 ( V_153 , V_155 ) ;
else
V_156 -> V_34 = - 1 ;
V_161 = V_156 -> V_34 ;
if ( F_43 ( V_155 ) )
V_158 = F_44 ( V_153 ) ;
V_160 = ( V_153 -> V_41 == V_165 &&
V_158 && ( V_158 -> V_166 & V_167 ) &&
V_161 + V_159 * V_94 <= V_99 -> V_168 . V_169 ) ;
if ( V_153 -> V_170 ) {
V_160 = true ;
if ( ! ( V_158 && V_158 -> V_166 & V_167 ) )
goto V_171;
V_161 = F_45 ( V_153 ) ;
if ( V_161 + V_159 * V_94 > V_99 -> V_168 . V_169 )
goto V_171;
}
if ( V_160 && V_153 -> V_41 != V_165 && ! F_46 ( V_99 -> V_53 ) )
goto V_171;
V_156 -> V_93 = V_159 ;
while ( V_159 -- ) {
unsigned long V_172 ;
void * V_173 ;
V_173 = F_34 ( V_94 , V_164 ) ;
if ( V_173 == NULL )
goto V_171;
F_47 ( V_172 ) ;
if ( V_160 ) {
void T_4 * V_174 ;
V_174 = F_48 ( V_99 -> V_168 . V_175 ,
V_161 ) ;
F_49 ( V_173 , V_174 , V_94 ) ;
F_50 ( V_174 ) ;
} else {
struct V_90 * V_90 ;
void * V_174 ;
V_90 = F_51 ( V_153 , V_79 ) ;
F_52 ( & V_90 , 1 ) ;
V_174 = F_53 ( V_90 ) ;
memcpy ( V_173 , V_174 , V_94 ) ;
F_54 ( V_174 ) ;
F_52 ( & V_90 , 1 ) ;
}
F_55 ( V_172 ) ;
V_156 -> V_95 [ V_79 ++ ] = V_173 ;
V_161 += V_94 ;
}
return V_156 ;
V_171:
while ( V_79 -- )
F_36 ( V_156 -> V_95 [ V_79 ] ) ;
F_36 ( V_156 ) ;
return NULL ;
}
static void F_56 ( struct V_32 * V_17 ,
struct V_157 * V_158 )
{
struct V_152 * V_89 = V_158 -> V_89 ;
V_17 -> V_19 = V_89 -> V_162 . V_19 ;
V_17 -> V_31 = V_89 -> V_162 . V_31 ;
V_17 -> V_37 = V_89 -> V_176 ;
V_17 -> V_38 = V_89 -> V_177 ;
V_17 -> V_34 = V_158 -> V_178 . V_23 ;
V_17 -> V_35 = V_89 -> V_162 . V_35 ;
V_17 -> V_36 = V_89 -> V_162 . V_36 ;
V_17 -> V_42 = V_89 -> V_42 ;
V_17 -> V_8 = 0 ;
if ( F_57 ( V_89 ) )
V_17 -> V_8 = 1 ;
if ( V_89 -> V_179 > 0 )
V_17 -> V_8 = - 1 ;
V_17 -> V_9 = V_89 -> V_180 ;
V_17 -> V_13 = V_89 -> V_13 ;
V_17 -> V_14 = V_89 -> V_181 != V_182 ;
V_17 -> V_39 = V_89 -> V_39 . V_183 != NULL ;
V_17 -> V_2 = V_89 -> V_2 ? V_89 -> V_2 -> V_184 : - 1 ;
V_17 -> V_41 = V_89 -> V_41 ;
}
static V_62 F_58 ( struct V_32 * V_17 ,
int V_33 , struct V_185 * V_58 )
{
struct V_157 * V_158 ;
int V_79 = 0 ;
F_59 (vma, head, mm_list) {
F_56 ( V_17 ++ , V_158 ) ;
if ( ++ V_79 == V_33 )
break;
}
return V_79 ;
}
static V_62 F_60 ( struct V_32 * V_17 ,
int V_33 , struct V_185 * V_58 ,
struct V_154 * V_155 )
{
struct V_152 * V_89 ;
struct V_32 * const V_186 = V_17 ;
struct V_32 * const V_187 = V_17 + V_33 ;
F_59 (obj, head, global_list) {
struct V_157 * V_158 ;
if ( V_17 == V_187 )
break;
F_59 (vma, &obj->vma_list, vma_link)
if ( V_158 -> V_155 == V_155 && V_158 -> V_188 > 0 ) {
F_56 ( V_17 ++ , V_158 ) ;
break;
}
}
return V_17 - V_186 ;
}
static T_5 F_61 ( struct V_98 * V_99 ,
struct V_54 * error ,
int * V_189 )
{
T_5 V_190 = 0 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_191 ; V_79 ++ ) {
if ( error -> V_2 [ V_79 ] . V_86 == V_51 ) {
if ( V_189 )
* V_189 = V_79 ;
return error -> V_2 [ V_79 ] . V_65 ^ error -> V_2 [ V_79 ] . V_66 ;
}
}
return V_190 ;
}
static void F_62 ( struct V_52 * V_53 ,
struct V_54 * error )
{
struct V_98 * V_99 = V_53 -> V_100 ;
int V_79 ;
switch ( F_20 ( V_53 ) -> V_67 ) {
case 9 :
case 8 :
case 7 :
case 6 :
for ( V_79 = 0 ; V_79 < V_99 -> V_123 ; V_79 ++ )
error -> V_124 [ V_79 ] = F_63 ( V_192 + ( V_79 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_79 = 0 ; V_79 < 16 ; V_79 ++ )
error -> V_124 [ V_79 ] = F_63 ( V_193 + ( V_79 * 8 ) ) ;
break;
case 3 :
if ( F_64 ( V_53 ) || F_65 ( V_53 ) || F_66 ( V_53 ) )
for ( V_79 = 0 ; V_79 < 8 ; V_79 ++ )
error -> V_124 [ V_79 + 8 ] = F_67 ( V_194 + ( V_79 * 4 ) ) ;
case 2 :
for ( V_79 = 0 ; V_79 < 8 ; V_79 ++ )
error -> V_124 [ V_79 ] = F_67 ( V_195 + ( V_79 * 4 ) ) ;
break;
default:
F_68 () ;
}
}
static void F_69 ( struct V_98 * V_99 ,
struct V_54 * error ,
struct V_196 * V_2 ,
struct V_56 * V_197 )
{
struct V_196 * V_198 ;
int V_79 ;
if ( ! F_70 ( V_99 -> V_53 ) )
return;
if ( ! error -> V_141 )
error -> V_141 =
F_71 ( V_99 ,
V_99 -> V_141 ) ;
F_72 (to, dev_priv, i) {
int V_199 ;
T_6 V_200 ;
V_62 * V_28 ;
if ( V_2 == V_198 )
continue;
V_200 = ( F_73 ( V_2 , V_79 ) & ( V_94 - 1 ) )
/ 4 ;
V_28 = error -> V_141 -> V_95 [ 0 ] ;
V_199 = F_74 ( V_2 , V_198 ) ;
V_197 -> V_75 [ V_199 ] = V_28 [ V_200 ] ;
V_197 -> V_76 [ V_199 ] = V_2 -> V_201 . V_202 [ V_199 ] ;
}
}
static void F_75 ( struct V_98 * V_99 ,
struct V_196 * V_2 ,
struct V_56 * V_197 )
{
V_197 -> V_75 [ 0 ] = F_67 ( F_76 ( V_2 -> V_203 ) ) ;
V_197 -> V_75 [ 1 ] = F_67 ( F_77 ( V_2 -> V_203 ) ) ;
V_197 -> V_76 [ 0 ] = V_2 -> V_201 . V_202 [ 0 ] ;
V_197 -> V_76 [ 1 ] = V_2 -> V_201 . V_202 [ 1 ] ;
if ( F_23 ( V_99 -> V_53 ) ) {
V_197 -> V_75 [ 2 ] =
F_67 ( F_78 ( V_2 -> V_203 ) ) ;
V_197 -> V_76 [ 2 ] = V_2 -> V_201 . V_202 [ 2 ] ;
}
}
static void F_79 ( struct V_52 * V_53 ,
struct V_54 * error ,
struct V_196 * V_2 ,
struct V_56 * V_197 )
{
struct V_98 * V_99 = V_53 -> V_100 ;
if ( F_20 ( V_53 ) -> V_67 >= 6 ) {
V_197 -> V_73 = F_67 ( V_2 -> V_203 + 0x50 ) ;
V_197 -> V_74 = F_67 ( F_80 ( V_2 ) ) ;
if ( F_20 ( V_53 ) -> V_67 >= 8 )
F_69 ( V_99 , error , V_2 , V_197 ) ;
else
F_75 ( V_99 , V_2 , V_197 ) ;
}
if ( F_20 ( V_53 ) -> V_67 >= 4 ) {
V_197 -> V_72 = F_67 ( F_81 ( V_2 -> V_203 ) ) ;
V_197 -> V_64 = F_67 ( F_82 ( V_2 -> V_203 ) ) ;
V_197 -> V_65 = F_67 ( F_83 ( V_2 -> V_203 ) ) ;
V_197 -> V_66 = F_67 ( F_84 ( V_2 -> V_203 ) ) ;
V_197 -> V_70 = F_67 ( F_85 ( V_2 -> V_203 ) ) ;
V_197 -> V_68 = F_67 ( F_86 ( V_2 -> V_203 ) ) ;
if ( F_20 ( V_53 ) -> V_67 >= 8 ) {
V_197 -> V_72 |= ( V_204 ) F_67 ( F_87 ( V_2 -> V_203 ) ) << 32 ;
V_197 -> V_68 |= ( V_204 ) F_67 ( F_88 ( V_2 -> V_203 ) ) << 32 ;
}
V_197 -> V_69 = F_67 ( F_89 ( V_2 -> V_203 ) ) ;
} else {
V_197 -> V_72 = F_67 ( V_205 ) ;
V_197 -> V_64 = F_67 ( V_206 ) ;
V_197 -> V_65 = F_67 ( V_207 ) ;
V_197 -> V_66 = F_67 ( V_208 ) ;
}
V_197 -> V_83 = F_90 ( & V_2 -> V_209 ) ;
V_197 -> V_71 = F_67 ( F_91 ( V_2 -> V_203 ) ) ;
V_197 -> V_82 = V_2 -> V_210 ( V_2 , false ) ;
V_197 -> V_63 = F_92 ( V_2 ) ;
V_197 -> V_58 = F_93 ( V_2 ) ;
V_197 -> V_59 = F_94 ( V_2 ) ;
V_197 -> V_60 = F_95 ( V_2 ) ;
if ( F_96 ( V_53 ) ) {
int V_211 ;
if ( F_97 ( V_53 ) ) {
switch ( V_2 -> V_184 ) {
default:
case V_3 :
V_211 = V_212 ;
break;
case V_5 :
V_211 = V_213 ;
break;
case V_4 :
V_211 = V_214 ;
break;
case V_6 :
V_211 = V_215 ;
break;
}
} else if ( F_98 ( V_2 -> V_53 ) ) {
V_211 = F_99 ( V_2 -> V_203 ) ;
} else {
V_211 = F_100 ( V_2 -> V_203 ) ;
}
V_197 -> V_61 = F_67 ( V_211 ) ;
}
V_197 -> V_87 = V_2 -> V_216 . V_217 ;
V_197 -> V_86 = V_2 -> V_216 . V_218 ;
if ( F_24 ( V_53 ) ) {
int V_79 ;
V_197 -> V_77 . V_78 = F_67 ( F_101 ( V_2 ) ) ;
switch ( F_20 ( V_53 ) -> V_67 ) {
case 9 :
case 8 :
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ ) {
V_197 -> V_77 . V_80 [ V_79 ] =
F_67 ( F_102 ( V_2 , V_79 ) ) ;
V_197 -> V_77 . V_80 [ V_79 ] <<= 32 ;
V_197 -> V_77 . V_80 [ V_79 ] |=
F_67 ( F_103 ( V_2 , V_79 ) ) ;
}
break;
case 7 :
V_197 -> V_77 . V_81 =
F_67 ( F_104 ( V_2 ) ) ;
break;
case 6 :
V_197 -> V_77 . V_81 =
F_67 ( F_105 ( V_2 ) ) ;
break;
}
}
}
static void F_106 ( struct V_196 * V_2 ,
struct V_54 * error ,
struct V_56 * V_197 )
{
struct V_98 * V_99 = V_2 -> V_53 -> V_100 ;
struct V_152 * V_89 ;
if ( V_2 -> V_184 != V_3 || ! error -> V_120 )
return;
F_59 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_107 ( V_89 ) )
continue;
if ( ( error -> V_120 & V_219 ) == F_45 ( V_89 ) ) {
V_197 -> V_140 = F_71 ( V_99 , V_89 ) ;
break;
}
}
}
static void F_108 ( struct V_52 * V_53 ,
struct V_54 * error )
{
struct V_98 * V_99 = V_53 -> V_100 ;
struct V_220 * V_221 ;
int V_79 , V_33 ;
for ( V_79 = 0 ; V_79 < V_191 ; V_79 ++ ) {
struct V_196 * V_2 = & V_99 -> V_2 [ V_79 ] ;
struct V_222 * V_223 ;
error -> V_2 [ V_79 ] . V_108 = - 1 ;
if ( V_2 -> V_53 == NULL )
continue;
error -> V_2 [ V_79 ] . V_57 = true ;
F_79 ( V_53 , error , V_2 , & error -> V_2 [ V_79 ] ) ;
V_221 = F_109 ( V_2 ) ;
if ( V_221 ) {
struct V_154 * V_155 ;
V_155 = V_221 -> V_140 && V_221 -> V_140 -> V_224 ?
& V_221 -> V_140 -> V_224 -> V_162 :
& V_99 -> V_168 . V_162 ;
error -> V_2 [ V_79 ] . V_133 =
F_40 ( V_99 ,
V_221 -> V_225 ,
V_155 ) ;
if ( F_110 ( V_99 -> V_53 ) )
error -> V_2 [ V_79 ] . V_134 =
F_71 ( V_99 ,
V_2 -> V_226 . V_89 ) ;
if ( V_221 -> V_227 ) {
struct V_228 * V_229 ;
F_111 () ;
V_229 = F_112 ( V_221 -> V_227 -> V_230 -> V_108 ,
V_231 ) ;
if ( V_229 ) {
strcpy ( error -> V_2 [ V_79 ] . V_109 , V_229 -> V_109 ) ;
error -> V_2 [ V_79 ] . V_108 = V_229 -> V_108 ;
}
F_113 () ;
}
}
if ( V_40 . V_232 ) {
if ( V_221 )
V_223 = V_221 -> V_140 -> V_233 [ V_2 -> V_184 ] . V_234 ;
else
V_223 = V_2 -> V_235 -> V_233 [ V_2 -> V_184 ] . V_234 ;
} else
V_223 = V_2 -> V_236 ;
error -> V_2 [ V_79 ] . V_84 = V_223 -> V_58 ;
error -> V_2 [ V_79 ] . V_85 = V_223 -> V_59 ;
error -> V_2 [ V_79 ] . V_138 =
F_71 ( V_99 , V_223 -> V_89 ) ;
error -> V_2 [ V_79 ] . V_139 =
F_71 ( V_99 , V_2 -> V_237 . V_89 ) ;
F_106 ( V_2 , error , & error -> V_2 [ V_79 ] ) ;
V_33 = 0 ;
F_59 (request, &ring->request_list, list)
V_33 ++ ;
error -> V_2 [ V_79 ] . V_135 = V_33 ;
error -> V_2 [ V_79 ] . V_136 =
F_114 ( V_33 , sizeof( * error -> V_2 [ V_79 ] . V_136 ) ,
V_164 ) ;
if ( error -> V_2 [ V_79 ] . V_136 == NULL ) {
error -> V_2 [ V_79 ] . V_135 = 0 ;
continue;
}
V_33 = 0 ;
F_59 (request, &ring->request_list, list) {
struct V_238 * V_239 ;
V_239 = & error -> V_2 [ V_79 ] . V_136 [ V_33 ++ ] ;
V_239 -> V_82 = V_221 -> V_82 ;
V_239 -> V_137 = V_221 -> V_240 ;
V_239 -> V_59 = V_221 -> V_59 ;
}
}
}
static void F_115 ( struct V_98 * V_99 ,
struct V_54 * error ,
struct V_154 * V_155 ,
const int V_241 )
{
struct V_32 * V_129 = NULL , * V_131 = NULL ;
struct V_152 * V_89 ;
struct V_157 * V_158 ;
int V_79 ;
V_79 = 0 ;
F_59 (vma, &vm->active_list, mm_list)
V_79 ++ ;
error -> V_130 [ V_241 ] = V_79 ;
F_59 (obj, &dev_priv->mm.bound_list, global_list) {
F_59 (vma, &obj->vma_list, vma_link)
if ( V_158 -> V_155 == V_155 && V_158 -> V_188 > 0 ) {
V_79 ++ ;
break;
}
}
error -> V_132 [ V_241 ] = V_79 - error -> V_130 [ V_241 ] ;
if ( V_79 ) {
V_129 = F_114 ( V_79 , sizeof( * V_129 ) , V_164 ) ;
if ( V_129 )
V_131 = V_129 + error -> V_130 [ V_241 ] ;
}
if ( V_129 )
error -> V_130 [ V_241 ] =
F_58 ( V_129 ,
error -> V_130 [ V_241 ] ,
& V_155 -> V_242 ) ;
if ( V_131 )
error -> V_132 [ V_241 ] =
F_60 ( V_131 ,
error -> V_132 [ V_241 ] ,
& V_99 -> V_183 . V_243 , V_155 ) ;
error -> V_129 [ V_241 ] = V_129 ;
error -> V_131 [ V_241 ] = V_131 ;
}
static void F_116 ( struct V_98 * V_99 ,
struct V_54 * error )
{
struct V_154 * V_155 ;
int V_244 = 0 , V_79 = 0 ;
F_59 (vm, &dev_priv->vm_list, global_link)
V_244 ++ ;
error -> V_129 = F_114 ( V_244 , sizeof( * error -> V_129 ) , V_164 ) ;
error -> V_131 = F_114 ( V_244 , sizeof( * error -> V_131 ) , V_164 ) ;
error -> V_130 = F_114 ( V_244 , sizeof( * error -> V_130 ) ,
V_164 ) ;
error -> V_132 = F_114 ( V_244 , sizeof( * error -> V_132 ) ,
V_164 ) ;
if ( error -> V_129 == NULL ||
error -> V_131 == NULL ||
error -> V_130 == NULL ||
error -> V_132 == NULL ) {
F_36 ( error -> V_129 ) ;
F_36 ( error -> V_130 ) ;
F_36 ( error -> V_131 ) ;
F_36 ( error -> V_132 ) ;
error -> V_129 = NULL ;
error -> V_130 = NULL ;
error -> V_131 = NULL ;
error -> V_132 = NULL ;
} else {
F_59 (vm, &dev_priv->vm_list, global_link)
F_115 ( V_99 , error , V_155 , V_79 ++ ) ;
error -> V_128 = V_244 ;
}
}
static void F_117 ( struct V_98 * V_99 ,
struct V_54 * error )
{
struct V_52 * V_53 = V_99 -> V_53 ;
int V_79 ;
if ( F_30 ( V_53 ) ) {
error -> V_116 [ 0 ] = F_67 ( V_245 ) ;
error -> V_115 = F_67 ( V_246 ) ;
error -> V_118 = F_67 ( V_247 ) ;
}
if ( F_97 ( V_53 ) )
error -> V_127 = F_67 ( V_248 ) ;
if ( F_98 ( V_53 ) ) {
error -> V_118 = F_67 ( V_249 ) ;
error -> V_250 = F_67 ( V_251 ) ;
error -> V_78 = F_67 ( V_252 ) ;
}
if ( F_20 ( V_53 ) -> V_67 >= 7 )
error -> V_118 = F_67 ( V_253 ) ;
if ( F_20 ( V_53 ) -> V_67 >= 6 ) {
error -> V_119 = F_67 ( V_254 ) ;
error -> error = F_67 ( V_255 ) ;
error -> V_126 = F_67 ( V_256 ) ;
}
if ( F_98 ( V_53 ) || F_97 ( V_53 ) ) {
error -> V_257 = F_67 ( V_258 ) ;
error -> V_259 = F_67 ( V_260 ) ;
}
if ( F_118 ( V_53 ) )
error -> V_120 = F_67 ( V_261 ) ;
if ( F_20 ( V_53 ) -> V_67 >= 8 ) {
error -> V_115 = F_67 ( V_262 ) ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ )
error -> V_116 [ V_79 ] = F_67 ( F_119 ( V_79 ) ) ;
} else if ( F_29 ( V_53 ) ) {
error -> V_115 = F_67 ( V_263 ) ;
error -> V_116 [ 0 ] = F_67 ( V_245 ) ;
} else if ( F_120 ( V_53 ) ) {
error -> V_115 = F_121 ( V_264 ) ;
} else if ( ! F_30 ( V_53 ) ) {
error -> V_115 = F_67 ( V_264 ) ;
}
error -> V_114 = F_67 ( V_265 ) ;
error -> V_117 = F_67 ( V_266 ) ;
F_122 ( V_53 , error -> V_125 ) ;
}
static void F_123 ( struct V_52 * V_53 ,
struct V_54 * error ,
bool V_267 ,
const char * V_104 )
{
struct V_98 * V_99 = V_53 -> V_100 ;
V_62 V_268 ;
int V_189 = - 1 , V_21 ;
V_268 = F_61 ( V_99 , error , & V_189 ) ;
V_21 = F_124 ( error -> V_104 , sizeof( error -> V_104 ) ,
L_93 ,
F_20 ( V_53 ) -> V_67 , V_189 , V_268 ) ;
if ( V_189 != - 1 && error -> V_2 [ V_189 ] . V_108 != - 1 )
V_21 += F_124 ( error -> V_104 + V_21 ,
sizeof( error -> V_104 ) - V_21 ,
L_94 ,
error -> V_2 [ V_189 ] . V_109 ,
error -> V_2 [ V_189 ] . V_108 ) ;
F_124 ( error -> V_104 + V_21 , sizeof( error -> V_104 ) - V_21 ,
L_95 ,
V_104 ,
V_267 ? L_96 : L_97 ) ;
}
static void F_125 ( struct V_98 * V_99 ,
struct V_54 * error )
{
error -> V_110 = F_126 ( & V_99 -> V_121 ) ;
error -> V_111 = V_99 -> V_111 ;
}
void F_127 ( struct V_52 * V_53 , bool V_267 ,
const char * V_104 )
{
static bool V_269 ;
struct V_98 * V_99 = V_53 -> V_100 ;
struct V_54 * error ;
unsigned long V_172 ;
error = F_128 ( sizeof( * error ) , V_164 ) ;
if ( ! error ) {
F_129 ( L_98 ) ;
return;
}
F_130 ( & error -> V_151 ) ;
F_125 ( V_99 , error ) ;
F_117 ( V_99 , error ) ;
F_116 ( V_99 , error ) ;
F_62 ( V_53 , error ) ;
F_108 ( V_53 , error ) ;
F_131 ( & error -> time ) ;
error -> V_142 = F_132 ( V_53 ) ;
error -> V_143 = F_133 ( V_53 ) ;
F_123 ( V_53 , error , V_267 , V_104 ) ;
F_134 ( L_59 , error -> V_104 ) ;
F_135 ( & V_99 -> V_121 . V_270 , V_172 ) ;
if ( V_99 -> V_121 . V_271 == NULL ) {
V_99 -> V_121 . V_271 = error ;
error = NULL ;
}
F_136 ( & V_99 -> V_121 . V_270 , V_172 ) ;
if ( error ) {
F_37 ( & error -> V_151 ) ;
return;
}
if ( ! V_269 ) {
F_134 ( L_99 ) ;
F_134 ( L_100 ) ;
F_134 ( L_101 ) ;
F_134 ( L_102 ) ;
F_134 ( L_103 , V_53 -> V_272 -> V_273 ) ;
V_269 = true ;
}
}
void F_137 ( struct V_52 * V_53 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = V_53 -> V_100 ;
F_138 ( & V_99 -> V_121 . V_270 ) ;
V_97 -> error = V_99 -> V_121 . V_271 ;
if ( V_97 -> error )
F_139 ( & V_97 -> error -> V_151 ) ;
F_140 ( & V_99 -> V_121 . V_270 ) ;
}
void F_141 ( struct V_96 * V_97 )
{
if ( V_97 -> error )
F_142 ( & V_97 -> error -> V_151 , F_37 ) ;
}
void F_143 ( struct V_52 * V_53 )
{
struct V_98 * V_99 = V_53 -> V_100 ;
struct V_54 * error ;
F_138 ( & V_99 -> V_121 . V_270 ) ;
error = V_99 -> V_121 . V_271 ;
V_99 -> V_121 . V_271 = NULL ;
F_140 ( & V_99 -> V_121 . V_270 ) ;
if ( error )
F_142 ( & error -> V_151 , F_37 ) ;
}
const char * F_17 ( struct V_98 * V_40 , int type )
{
switch ( type ) {
case V_165 : return L_104 ;
case V_274 : return F_46 ( V_40 ) ? L_105 : L_106 ;
case V_275 : return L_107 ;
case V_276 : return L_108 ;
default: return L_8 ;
}
}
void F_122 ( struct V_52 * V_53 , T_5 * V_66 )
{
struct V_98 * V_99 = V_53 -> V_100 ;
memset ( V_66 , 0 , sizeof( * V_66 ) * V_277 ) ;
switch ( F_20 ( V_53 ) -> V_67 ) {
case 2 :
case 3 :
V_66 [ 0 ] = F_67 ( V_208 ) ;
break;
case 4 :
case 5 :
case 6 :
V_66 [ 0 ] = F_67 ( V_278 ) ;
V_66 [ 1 ] = F_67 ( V_279 ) ;
break;
default:
F_144 ( 1 , L_109 ) ;
case 7 :
case 8 :
case 9 :
V_66 [ 0 ] = F_67 ( V_280 ) ;
V_66 [ 1 ] = F_67 ( V_281 ) ;
V_66 [ 2 ] = F_67 ( V_282 ) ;
V_66 [ 3 ] = F_67 ( V_283 ) ;
break;
}
}
