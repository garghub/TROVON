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
int V_34 ;
F_15 ( V_30 , L_16 , V_31 , V_33 ) ;
while ( V_33 -- ) {
F_15 ( V_30 , L_17 ,
V_17 -> V_35 ,
V_17 -> V_19 ,
V_17 -> V_36 ,
V_17 -> V_37 ) ;
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ )
F_15 ( V_30 , L_18 , V_17 -> V_39 [ V_34 ] ) ;
F_15 ( V_30 , L_19 , V_17 -> V_40 ) ;
F_16 ( V_30 , F_3 ( V_17 -> V_8 ) ) ;
F_16 ( V_30 , F_4 ( V_17 -> V_9 ) ) ;
F_16 ( V_30 , F_5 ( V_17 -> V_13 ) ) ;
F_16 ( V_30 , F_6 ( V_17 -> V_14 ) ) ;
F_16 ( V_30 , V_17 -> V_41 ? L_20 : L_8 ) ;
F_16 ( V_30 , V_17 -> V_2 != - 1 ? L_21 : L_8 ) ;
F_16 ( V_30 , F_2 ( V_17 -> V_2 ) ) ;
F_16 ( V_30 , F_17 ( V_30 -> V_42 , V_17 -> V_43 ) ) ;
if ( V_17 -> V_31 )
F_15 ( V_30 , L_22 , V_17 -> V_31 ) ;
if ( V_17 -> V_44 != V_45 )
F_15 ( V_30 , L_23 , V_17 -> V_44 ) ;
F_16 ( V_30 , L_24 ) ;
V_17 ++ ;
}
}
static const char * F_18 ( enum V_46 V_47 )
{
switch ( V_47 ) {
case V_48 :
return L_25 ;
case V_49 :
return L_26 ;
case V_50 :
return L_27 ;
case V_51 :
return L_28 ;
case V_52 :
return L_29 ;
case V_53 :
return L_30 ;
}
return L_31 ;
}
static void F_19 ( struct V_15 * V_30 ,
struct V_54 * V_55 ,
struct V_56 * error ,
int V_57 )
{
struct V_58 * V_2 = & error -> V_2 [ V_57 ] ;
if ( ! V_2 -> V_59 )
return;
F_15 ( V_30 , L_32 , F_2 ( V_57 ) ) ;
F_15 ( V_30 , L_33 , V_2 -> V_23 ) ;
F_15 ( V_30 , L_34 , V_2 -> V_60 ) ;
F_15 ( V_30 , L_35 , V_2 -> V_61 ) ;
F_15 ( V_30 , L_36 , V_2 -> V_62 ) ;
F_15 ( V_30 , L_37 , V_2 -> V_63 ) ;
F_15 ( V_30 , L_38 , ( V_64 ) ( V_2 -> V_65 >> 32 ) , ( V_64 ) V_2 -> V_65 ) ;
F_15 ( V_30 , L_39 , V_2 -> V_66 ) ;
F_15 ( V_30 , L_40 , V_2 -> V_67 ) ;
F_15 ( V_30 , L_41 , V_2 -> V_68 ) ;
if ( F_20 ( V_55 ) -> V_69 >= 4 ) {
F_15 ( V_30 , L_42 , ( V_64 ) ( V_2 -> V_70 >> 32 ) , ( V_64 ) V_2 -> V_70 ) ;
F_15 ( V_30 , L_43 , V_2 -> V_71 ) ;
F_15 ( V_30 , L_44 , V_2 -> V_72 ) ;
}
F_15 ( V_30 , L_45 , V_2 -> V_73 ) ;
F_15 ( V_30 , L_46 , F_21 ( V_2 -> V_74 ) ,
F_22 ( V_2 -> V_74 ) ) ;
if ( F_20 ( V_55 ) -> V_69 >= 6 ) {
F_15 ( V_30 , L_47 , V_2 -> V_75 ) ;
F_15 ( V_30 , L_48 , V_2 -> V_76 ) ;
F_15 ( V_30 , L_49 ,
V_2 -> V_77 [ 0 ] ,
V_2 -> V_78 [ 0 ] ) ;
F_15 ( V_30 , L_50 ,
V_2 -> V_77 [ 1 ] ,
V_2 -> V_78 [ 1 ] ) ;
if ( F_23 ( V_55 ) ) {
F_15 ( V_30 , L_51 ,
V_2 -> V_77 [ 2 ] ,
V_2 -> V_78 [ 2 ] ) ;
}
}
if ( F_24 ( V_55 ) ) {
F_15 ( V_30 , L_52 , V_2 -> V_79 . V_80 ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 ) {
int V_34 ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ )
F_15 ( V_30 , L_53 ,
V_34 , V_2 -> V_79 . V_81 [ V_34 ] ) ;
} else {
F_15 ( V_30 , L_54 ,
V_2 -> V_79 . V_82 ) ;
}
}
F_15 ( V_30 , L_55 , V_2 -> V_83 ) ;
F_15 ( V_30 , L_56 , F_1 ( V_2 -> V_84 ) ) ;
F_15 ( V_30 , L_57 , V_2 -> V_85 ) ;
F_15 ( V_30 , L_58 , V_2 -> V_86 ) ;
F_15 ( V_30 , L_59 ,
F_18 ( V_2 -> V_87 ) ,
V_2 -> V_88 ) ;
}
void F_25 ( struct V_15 * V_16 , const char * V_27 , ... )
{
T_2 args ;
va_start ( args , V_27 ) ;
F_11 ( V_16 , V_27 , args ) ;
va_end ( args ) ;
}
static void F_26 ( struct V_15 * V_30 ,
struct V_89 * V_90 )
{
int V_91 , V_92 , V_93 ;
for ( V_91 = V_92 = 0 ; V_91 < V_90 -> V_94 ; V_91 ++ ) {
for ( V_93 = 0 ; V_93 < V_95 / 4 ; V_93 ++ ) {
F_15 ( V_30 , L_60 , V_92 ,
V_90 -> V_96 [ V_91 ] [ V_93 ] ) ;
V_92 += 4 ;
}
}
}
int F_27 ( struct V_15 * V_30 ,
const struct V_97 * V_98 )
{
struct V_54 * V_55 = V_98 -> V_55 ;
struct V_99 * V_100 = V_55 -> V_101 ;
struct V_56 * error = V_98 -> error ;
struct V_89 * V_90 ;
int V_34 , V_102 , V_92 , V_93 ;
int V_103 ;
if ( ! error ) {
F_15 ( V_30 , L_61 ) ;
goto V_104;
}
F_15 ( V_30 , L_62 , error -> V_105 ) ;
F_15 ( V_30 , L_63 , error -> time . V_106 ,
error -> time . V_107 ) ;
F_15 ( V_30 , L_64 V_108 L_24 ) ;
V_103 = 0 ;
for ( V_34 = 0 ; V_34 < F_28 ( error -> V_2 ) ; V_34 ++ ) {
if ( error -> V_2 [ V_34 ] . V_88 > V_103 )
V_103 = error -> V_2 [ V_34 ] . V_88 ;
}
for ( V_34 = 0 ; V_34 < F_28 ( error -> V_2 ) ; V_34 ++ ) {
if ( error -> V_2 [ V_34 ] . V_88 == V_103 &&
error -> V_2 [ V_34 ] . V_109 != - 1 ) {
F_15 ( V_30 , L_65 ,
F_2 ( V_34 ) ,
error -> V_2 [ V_34 ] . V_110 ,
error -> V_2 [ V_34 ] . V_109 ) ;
}
}
F_15 ( V_30 , L_66 , error -> V_111 ) ;
F_15 ( V_30 , L_67 , error -> V_112 ) ;
F_15 ( V_30 , L_68 , V_55 -> V_113 -> V_114 ) ;
F_15 ( V_30 , L_69 , error -> V_115 ) ;
F_15 ( V_30 , L_70 , error -> V_116 ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 ) {
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ )
F_15 ( V_30 , L_71 , V_34 ,
error -> V_117 [ V_34 ] ) ;
} else if ( F_29 ( V_55 ) || F_30 ( V_55 ) )
F_15 ( V_30 , L_72 , error -> V_117 [ 0 ] ) ;
F_15 ( V_30 , L_73 , error -> V_118 ) ;
F_15 ( V_30 , L_74 , error -> V_119 ) ;
F_15 ( V_30 , L_75 , error -> V_120 ) ;
F_15 ( V_30 , L_76 , error -> V_121 ) ;
F_15 ( V_30 , L_77 , V_100 -> V_122 . V_123 ) ;
for ( V_34 = 0 ; V_34 < V_100 -> V_124 ; V_34 ++ )
F_15 ( V_30 , L_78 , V_34 , error -> V_125 [ V_34 ] ) ;
for ( V_34 = 0 ; V_34 < F_28 ( error -> V_126 ) ; V_34 ++ )
F_15 ( V_30 , L_79 , V_34 ,
error -> V_126 [ V_34 ] ) ;
if ( F_20 ( V_55 ) -> V_69 >= 6 ) {
F_15 ( V_30 , L_80 , error -> error ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 )
F_15 ( V_30 , L_81 ,
error -> V_127 , error -> V_128 ) ;
F_15 ( V_30 , L_82 , error -> V_129 ) ;
}
if ( F_20 ( V_55 ) -> V_69 == 7 )
F_15 ( V_30 , L_83 , error -> V_130 ) ;
for ( V_34 = 0 ; V_34 < F_28 ( error -> V_2 ) ; V_34 ++ )
F_19 ( V_30 , V_55 , error , V_34 ) ;
for ( V_34 = 0 ; V_34 < error -> V_131 ; V_34 ++ ) {
F_15 ( V_30 , L_84 , V_34 ) ;
F_14 ( V_30 , L_85 ,
error -> V_132 [ V_34 ] ,
error -> V_133 [ V_34 ] ) ;
F_14 ( V_30 , L_86 ,
error -> V_134 [ V_34 ] ,
error -> V_135 [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_28 ( error -> V_2 ) ; V_34 ++ ) {
V_90 = error -> V_2 [ V_34 ] . V_136 ;
if ( V_90 ) {
F_16 ( V_30 , V_100 -> V_2 [ V_34 ] . V_31 ) ;
if ( error -> V_2 [ V_34 ] . V_109 != - 1 )
F_15 ( V_30 , L_87 ,
error -> V_2 [ V_34 ] . V_110 ,
error -> V_2 [ V_34 ] . V_109 ) ;
F_15 ( V_30 , L_88 ,
V_90 -> V_35 ) ;
F_26 ( V_30 , V_90 ) ;
}
V_90 = error -> V_2 [ V_34 ] . V_137 ;
if ( V_90 ) {
F_15 ( V_30 , L_89 ,
V_100 -> V_2 [ V_34 ] . V_31 , V_90 -> V_35 ) ;
F_26 ( V_30 , V_90 ) ;
}
if ( error -> V_2 [ V_34 ] . V_138 ) {
F_15 ( V_30 , L_90 ,
V_100 -> V_2 [ V_34 ] . V_31 ,
error -> V_2 [ V_34 ] . V_138 ) ;
for ( V_102 = 0 ; V_102 < error -> V_2 [ V_34 ] . V_138 ; V_102 ++ ) {
F_15 ( V_30 , L_91 ,
error -> V_2 [ V_34 ] . V_139 [ V_102 ] . V_83 ,
error -> V_2 [ V_34 ] . V_139 [ V_102 ] . V_140 ,
error -> V_2 [ V_34 ] . V_139 [ V_102 ] . V_61 ) ;
}
}
if ( ( V_90 = error -> V_2 [ V_34 ] . V_141 ) ) {
F_15 ( V_30 , L_92 ,
V_100 -> V_2 [ V_34 ] . V_31 ,
V_90 -> V_35 ) ;
F_26 ( V_30 , V_90 ) ;
}
if ( ( V_90 = error -> V_2 [ V_34 ] . V_142 ) ) {
F_15 ( V_30 , L_93 ,
V_100 -> V_2 [ V_34 ] . V_31 ,
V_90 -> V_35 ) ;
V_92 = 0 ;
for ( V_93 = 0 ; V_93 < V_95 / 16 ; V_93 += 4 ) {
F_15 ( V_30 , L_94 ,
V_92 ,
V_90 -> V_96 [ 0 ] [ V_93 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 1 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 2 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 3 ] ) ;
V_92 += 16 ;
}
}
if ( ( V_90 = error -> V_2 [ V_34 ] . V_143 ) ) {
F_15 ( V_30 , L_95 ,
V_100 -> V_2 [ V_34 ] . V_31 ,
V_90 -> V_35 ) ;
F_26 ( V_30 , V_90 ) ;
}
}
if ( ( V_90 = error -> V_144 ) ) {
F_15 ( V_30 , L_96 , V_90 -> V_35 ) ;
for ( V_93 = 0 ; V_93 < V_95 / 16 ; V_93 += 4 ) {
F_15 ( V_30 , L_94 ,
V_93 * 4 ,
V_90 -> V_96 [ 0 ] [ V_93 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 1 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 2 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 3 ] ) ;
}
}
if ( error -> V_145 )
F_31 ( V_30 , error -> V_145 ) ;
if ( error -> V_146 )
F_32 ( V_30 , V_55 , error -> V_146 ) ;
V_104:
if ( V_30 -> V_18 == 0 && V_30 -> V_17 )
return V_30 -> V_17 ;
return 0 ;
}
int F_33 ( struct V_15 * V_147 ,
struct V_99 * V_42 ,
T_1 V_33 , T_3 V_22 )
{
memset ( V_147 , 0 , sizeof( * V_147 ) ) ;
V_147 -> V_42 = V_42 ;
V_147 -> V_19 = V_33 + 1 > V_95 ? V_33 + 1 : V_95 ;
V_147 -> V_26 = F_34 ( V_147 -> V_19 ,
V_148 | V_149 | V_150 ) ;
if ( V_147 -> V_26 == NULL ) {
V_147 -> V_19 = V_95 ;
V_147 -> V_26 = F_34 ( V_147 -> V_19 , V_148 ) ;
}
if ( V_147 -> V_26 == NULL ) {
V_147 -> V_19 = 128 ;
V_147 -> V_26 = F_34 ( V_147 -> V_19 , V_148 ) ;
}
if ( V_147 -> V_26 == NULL )
return - V_151 ;
V_147 -> V_23 = V_22 ;
return 0 ;
}
static void F_35 ( struct V_89 * V_90 )
{
int V_91 ;
if ( V_90 == NULL )
return;
for ( V_91 = 0 ; V_91 < V_90 -> V_94 ; V_91 ++ )
F_36 ( V_90 -> V_96 [ V_91 ] ) ;
F_36 ( V_90 ) ;
}
static void F_37 ( struct V_152 * V_153 )
{
struct V_56 * error = F_38 ( V_153 ,
F_39 ( * error ) , V_154 ) ;
int V_34 ;
for ( V_34 = 0 ; V_34 < F_28 ( error -> V_2 ) ; V_34 ++ ) {
F_35 ( error -> V_2 [ V_34 ] . V_136 ) ;
F_35 ( error -> V_2 [ V_34 ] . V_137 ) ;
F_35 ( error -> V_2 [ V_34 ] . V_141 ) ;
F_35 ( error -> V_2 [ V_34 ] . V_142 ) ;
F_35 ( error -> V_2 [ V_34 ] . V_143 ) ;
F_36 ( error -> V_2 [ V_34 ] . V_139 ) ;
}
F_35 ( error -> V_144 ) ;
for ( V_34 = 0 ; V_34 < error -> V_131 ; V_34 ++ )
F_36 ( error -> V_132 [ V_34 ] ) ;
F_36 ( error -> V_132 ) ;
F_36 ( error -> V_133 ) ;
F_36 ( error -> V_134 ) ;
F_36 ( error -> V_135 ) ;
F_36 ( error -> V_145 ) ;
F_36 ( error -> V_146 ) ;
F_36 ( error ) ;
}
static struct V_89 *
F_40 ( struct V_99 * V_100 ,
struct V_155 * V_156 ,
struct V_157 * V_158 )
{
struct V_89 * V_159 ;
struct V_160 * V_161 = NULL ;
int V_162 ;
bool V_163 ;
int V_34 = 0 ;
V_64 V_164 ;
if ( V_156 == NULL || V_156 -> V_96 == NULL )
return NULL ;
V_162 = V_156 -> V_165 . V_19 >> V_166 ;
V_159 = F_34 ( sizeof( * V_159 ) + V_162 * sizeof( V_64 * ) , V_167 ) ;
if ( V_159 == NULL )
return NULL ;
if ( F_41 ( V_156 , V_158 ) )
V_159 -> V_35 = F_42 ( V_156 , V_158 ) ;
else
V_159 -> V_35 = - 1 ;
V_164 = V_159 -> V_35 ;
if ( F_43 ( V_158 ) )
V_161 = F_44 ( V_156 ) ;
V_163 = ( V_156 -> V_43 == V_168 &&
V_161 && ( V_161 -> V_169 & V_170 ) &&
V_164 + V_162 * V_95 <= V_100 -> V_171 . V_172 ) ;
if ( V_156 -> V_173 ) {
V_163 = true ;
if ( ! ( V_161 && V_161 -> V_169 & V_170 ) )
goto V_174;
V_164 = F_45 ( V_156 ) ;
if ( V_164 + V_162 * V_95 > V_100 -> V_171 . V_172 )
goto V_174;
}
if ( V_163 && V_156 -> V_43 != V_168 && ! F_46 ( V_100 -> V_55 ) )
goto V_174;
V_159 -> V_94 = V_162 ;
while ( V_162 -- ) {
unsigned long V_175 ;
void * V_176 ;
V_176 = F_34 ( V_95 , V_167 ) ;
if ( V_176 == NULL )
goto V_174;
F_47 ( V_175 ) ;
if ( V_163 ) {
void T_4 * V_177 ;
V_177 = F_48 ( V_100 -> V_171 . V_178 ,
V_164 ) ;
F_49 ( V_176 , V_177 , V_95 ) ;
F_50 ( V_177 ) ;
} else {
struct V_91 * V_91 ;
void * V_177 ;
V_91 = F_51 ( V_156 , V_34 ) ;
F_52 ( & V_91 , 1 ) ;
V_177 = F_53 ( V_91 ) ;
memcpy ( V_176 , V_177 , V_95 ) ;
F_54 ( V_177 ) ;
F_52 ( & V_91 , 1 ) ;
}
F_55 ( V_175 ) ;
V_159 -> V_96 [ V_34 ++ ] = V_176 ;
V_164 += V_95 ;
}
return V_159 ;
V_174:
while ( V_34 -- )
F_36 ( V_159 -> V_96 [ V_34 ] ) ;
F_36 ( V_159 ) ;
return NULL ;
}
static void F_56 ( struct V_32 * V_17 ,
struct V_160 * V_161 )
{
struct V_155 * V_90 = V_161 -> V_90 ;
int V_34 ;
V_17 -> V_19 = V_90 -> V_165 . V_19 ;
V_17 -> V_31 = V_90 -> V_165 . V_31 ;
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ )
V_17 -> V_39 [ V_34 ] = F_57 ( V_90 -> V_179 [ V_34 ] ) ;
V_17 -> V_40 = F_57 ( V_90 -> V_180 ) ;
V_17 -> V_35 = V_161 -> V_181 . V_23 ;
V_17 -> V_36 = V_90 -> V_165 . V_36 ;
V_17 -> V_37 = V_90 -> V_165 . V_37 ;
V_17 -> V_44 = V_90 -> V_44 ;
V_17 -> V_8 = 0 ;
if ( F_58 ( V_90 ) )
V_17 -> V_8 = 1 ;
V_17 -> V_9 = V_90 -> V_182 ;
V_17 -> V_13 = V_90 -> V_13 ;
V_17 -> V_14 = V_90 -> V_183 != V_184 ;
V_17 -> V_41 = V_90 -> V_41 . V_185 != NULL ;
V_17 -> V_2 = V_90 -> V_180 ?
F_59 ( V_90 -> V_180 ) -> V_186 : - 1 ;
V_17 -> V_43 = V_90 -> V_43 ;
}
static V_64 F_60 ( struct V_32 * V_17 ,
int V_33 , struct V_187 * V_60 )
{
struct V_160 * V_161 ;
int V_34 = 0 ;
F_61 (vma, head, mm_list) {
F_56 ( V_17 ++ , V_161 ) ;
if ( ++ V_34 == V_33 )
break;
}
return V_34 ;
}
static V_64 F_62 ( struct V_32 * V_17 ,
int V_33 , struct V_187 * V_60 ,
struct V_157 * V_158 )
{
struct V_155 * V_90 ;
struct V_32 * const V_188 = V_17 ;
struct V_32 * const V_189 = V_17 + V_33 ;
F_61 (obj, head, global_list) {
struct V_160 * V_161 ;
if ( V_17 == V_189 )
break;
F_61 (vma, &obj->vma_list, vma_link)
if ( V_161 -> V_158 == V_158 && V_161 -> V_190 > 0 )
F_56 ( V_17 ++ , V_161 ) ;
}
return V_17 - V_188 ;
}
static T_5 F_63 ( struct V_99 * V_100 ,
struct V_56 * error ,
int * V_191 )
{
T_5 V_192 = 0 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ ) {
if ( error -> V_2 [ V_34 ] . V_87 == V_53 ) {
if ( V_191 )
* V_191 = V_34 ;
return error -> V_2 [ V_34 ] . V_67 ^ error -> V_2 [ V_34 ] . V_68 ;
}
}
return V_192 ;
}
static void F_64 ( struct V_54 * V_55 ,
struct V_56 * error )
{
struct V_99 * V_100 = V_55 -> V_101 ;
int V_34 ;
if ( F_65 ( V_55 ) || F_66 ( V_55 ) ) {
for ( V_34 = 0 ; V_34 < 8 ; V_34 ++ )
error -> V_125 [ V_34 ] = F_67 ( V_193 + ( V_34 * 4 ) ) ;
if ( F_68 ( V_55 ) || F_69 ( V_55 ) || F_70 ( V_55 ) )
for ( V_34 = 0 ; V_34 < 8 ; V_34 ++ )
error -> V_125 [ V_34 + 8 ] = F_67 ( V_194 +
( V_34 * 4 ) ) ;
} else if ( F_71 ( V_55 ) || F_72 ( V_55 ) )
for ( V_34 = 0 ; V_34 < 16 ; V_34 ++ )
error -> V_125 [ V_34 ] = F_73 ( V_195 +
( V_34 * 8 ) ) ;
else if ( F_20 ( V_55 ) -> V_69 >= 6 )
for ( V_34 = 0 ; V_34 < V_100 -> V_124 ; V_34 ++ )
error -> V_125 [ V_34 ] = F_73 ( V_196 +
( V_34 * 8 ) ) ;
}
static void F_74 ( struct V_99 * V_100 ,
struct V_56 * error ,
struct V_197 * V_2 ,
struct V_58 * V_198 )
{
struct V_197 * V_199 ;
int V_34 ;
if ( ! F_75 ( V_100 -> V_55 ) )
return;
if ( ! error -> V_144 )
error -> V_144 =
F_76 ( V_100 ,
V_100 -> V_144 ) ;
F_77 (to, dev_priv, i) {
int V_200 ;
T_6 V_201 ;
V_64 * V_28 ;
if ( V_2 == V_199 )
continue;
V_201 = ( F_78 ( V_2 , V_34 ) & ( V_95 - 1 ) )
/ 4 ;
V_28 = error -> V_144 -> V_96 [ 0 ] ;
V_200 = F_79 ( V_2 , V_199 ) ;
V_198 -> V_77 [ V_200 ] = V_28 [ V_201 ] ;
V_198 -> V_78 [ V_200 ] = V_2 -> V_202 . V_203 [ V_200 ] ;
}
}
static void F_80 ( struct V_99 * V_100 ,
struct V_197 * V_2 ,
struct V_58 * V_198 )
{
V_198 -> V_77 [ 0 ] = F_67 ( F_81 ( V_2 -> V_204 ) ) ;
V_198 -> V_77 [ 1 ] = F_67 ( F_82 ( V_2 -> V_204 ) ) ;
V_198 -> V_78 [ 0 ] = V_2 -> V_202 . V_203 [ 0 ] ;
V_198 -> V_78 [ 1 ] = V_2 -> V_202 . V_203 [ 1 ] ;
if ( F_23 ( V_100 -> V_55 ) ) {
V_198 -> V_77 [ 2 ] =
F_67 ( F_83 ( V_2 -> V_204 ) ) ;
V_198 -> V_78 [ 2 ] = V_2 -> V_202 . V_203 [ 2 ] ;
}
}
static void F_84 ( struct V_54 * V_55 ,
struct V_56 * error ,
struct V_197 * V_2 ,
struct V_58 * V_198 )
{
struct V_99 * V_100 = V_55 -> V_101 ;
if ( F_20 ( V_55 ) -> V_69 >= 6 ) {
V_198 -> V_75 = F_67 ( V_2 -> V_204 + 0x50 ) ;
V_198 -> V_76 = F_67 ( F_85 ( V_2 ) ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 )
F_74 ( V_100 , error , V_2 , V_198 ) ;
else
F_80 ( V_100 , V_2 , V_198 ) ;
}
if ( F_20 ( V_55 ) -> V_69 >= 4 ) {
V_198 -> V_74 = F_67 ( F_86 ( V_2 -> V_204 ) ) ;
V_198 -> V_66 = F_67 ( F_87 ( V_2 -> V_204 ) ) ;
V_198 -> V_67 = F_67 ( F_88 ( V_2 -> V_204 ) ) ;
V_198 -> V_68 = F_67 ( F_89 ( V_2 -> V_204 ) ) ;
V_198 -> V_72 = F_67 ( F_90 ( V_2 -> V_204 ) ) ;
V_198 -> V_70 = F_67 ( F_91 ( V_2 -> V_204 ) ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 ) {
V_198 -> V_74 |= ( V_205 ) F_67 ( F_92 ( V_2 -> V_204 ) ) << 32 ;
V_198 -> V_70 |= ( V_205 ) F_67 ( F_93 ( V_2 -> V_204 ) ) << 32 ;
}
V_198 -> V_71 = F_67 ( F_94 ( V_2 -> V_204 ) ) ;
} else {
V_198 -> V_74 = F_67 ( V_206 ) ;
V_198 -> V_66 = F_67 ( V_207 ) ;
V_198 -> V_67 = F_67 ( V_208 ) ;
V_198 -> V_68 = F_67 ( V_209 ) ;
}
V_198 -> V_84 = F_95 ( & V_2 -> V_210 ) ;
V_198 -> V_73 = F_67 ( F_96 ( V_2 -> V_204 ) ) ;
V_198 -> V_83 = V_2 -> V_211 ( V_2 , false ) ;
V_198 -> V_65 = F_97 ( V_2 ) ;
V_198 -> V_23 = F_98 ( V_2 ) ;
V_198 -> V_60 = F_99 ( V_2 ) ;
V_198 -> V_61 = F_100 ( V_2 ) ;
V_198 -> V_62 = F_101 ( V_2 ) ;
if ( F_102 ( V_55 ) ) {
int V_212 ;
if ( F_103 ( V_55 ) ) {
switch ( V_2 -> V_186 ) {
default:
case V_3 :
V_212 = V_213 ;
break;
case V_5 :
V_212 = V_214 ;
break;
case V_4 :
V_212 = V_215 ;
break;
case V_6 :
V_212 = V_216 ;
break;
}
} else if ( F_104 ( V_2 -> V_55 ) ) {
V_212 = F_105 ( V_2 -> V_204 ) ;
} else {
V_212 = F_106 ( V_2 -> V_204 ) ;
}
V_198 -> V_63 = F_67 ( V_212 ) ;
}
V_198 -> V_88 = V_2 -> V_217 . V_218 ;
V_198 -> V_87 = V_2 -> V_217 . V_219 ;
if ( F_24 ( V_55 ) ) {
int V_34 ;
V_198 -> V_79 . V_80 = F_67 ( F_107 ( V_2 ) ) ;
if ( F_104 ( V_55 ) )
V_198 -> V_79 . V_82 =
F_67 ( F_108 ( V_2 ) ) ;
else if ( F_103 ( V_55 ) )
V_198 -> V_79 . V_82 =
F_67 ( F_109 ( V_2 ) ) ;
else if ( F_20 ( V_55 ) -> V_69 >= 8 )
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_198 -> V_79 . V_81 [ V_34 ] =
F_67 ( F_110 ( V_2 , V_34 ) ) ;
V_198 -> V_79 . V_81 [ V_34 ] <<= 32 ;
V_198 -> V_79 . V_81 [ V_34 ] |=
F_67 ( F_111 ( V_2 , V_34 ) ) ;
}
}
}
static void F_112 ( struct V_197 * V_2 ,
struct V_56 * error ,
struct V_58 * V_198 )
{
struct V_99 * V_100 = V_2 -> V_55 -> V_101 ;
struct V_155 * V_90 ;
if ( V_2 -> V_186 != V_3 || ! error -> V_121 )
return;
F_61 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_113 ( V_90 ) )
continue;
if ( ( error -> V_121 & V_220 ) == F_45 ( V_90 ) ) {
V_198 -> V_143 = F_76 ( V_100 , V_90 ) ;
break;
}
}
}
static void F_114 ( struct V_54 * V_55 ,
struct V_56 * error )
{
struct V_99 * V_100 = V_55 -> V_101 ;
struct V_221 * V_222 ;
int V_34 , V_33 ;
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ ) {
struct V_197 * V_2 = & V_100 -> V_2 [ V_34 ] ;
struct V_223 * V_224 ;
error -> V_2 [ V_34 ] . V_109 = - 1 ;
if ( V_2 -> V_55 == NULL )
continue;
error -> V_2 [ V_34 ] . V_59 = true ;
F_84 ( V_55 , error , V_2 , & error -> V_2 [ V_34 ] ) ;
V_222 = F_115 ( V_2 ) ;
if ( V_222 ) {
struct V_157 * V_158 ;
V_158 = V_222 -> V_143 && V_222 -> V_143 -> V_225 ?
& V_222 -> V_143 -> V_225 -> V_165 :
& V_100 -> V_171 . V_165 ;
error -> V_2 [ V_34 ] . V_136 =
F_40 ( V_100 ,
V_222 -> V_226 ,
V_158 ) ;
if ( F_116 ( V_100 -> V_55 ) )
error -> V_2 [ V_34 ] . V_137 =
F_76 ( V_100 ,
V_2 -> V_227 . V_90 ) ;
if ( V_222 -> V_109 ) {
struct V_228 * V_229 ;
F_117 () ;
V_229 = F_118 ( V_222 -> V_109 , V_230 ) ;
if ( V_229 ) {
strcpy ( error -> V_2 [ V_34 ] . V_110 , V_229 -> V_110 ) ;
error -> V_2 [ V_34 ] . V_109 = V_229 -> V_109 ;
}
F_119 () ;
}
}
if ( V_42 . V_231 ) {
if ( V_222 )
V_224 = V_222 -> V_143 -> V_232 [ V_2 -> V_186 ] . V_233 ;
else
V_224 = V_2 -> V_234 -> V_232 [ V_2 -> V_186 ] . V_233 ;
} else
V_224 = V_2 -> V_235 ;
error -> V_2 [ V_34 ] . V_85 = V_224 -> V_60 ;
error -> V_2 [ V_34 ] . V_86 = V_224 -> V_61 ;
error -> V_2 [ V_34 ] . V_141 =
F_76 ( V_100 , V_224 -> V_90 ) ;
error -> V_2 [ V_34 ] . V_142 =
F_76 ( V_100 , V_2 -> V_236 . V_90 ) ;
F_112 ( V_2 , error , & error -> V_2 [ V_34 ] ) ;
V_33 = 0 ;
F_61 (request, &ring->request_list, list)
V_33 ++ ;
error -> V_2 [ V_34 ] . V_138 = V_33 ;
error -> V_2 [ V_34 ] . V_139 =
F_120 ( V_33 , sizeof( * error -> V_2 [ V_34 ] . V_139 ) ,
V_167 ) ;
if ( error -> V_2 [ V_34 ] . V_139 == NULL ) {
error -> V_2 [ V_34 ] . V_138 = 0 ;
continue;
}
V_33 = 0 ;
F_61 (request, &ring->request_list, list) {
struct V_237 * V_238 ;
V_238 = & error -> V_2 [ V_34 ] . V_139 [ V_33 ++ ] ;
V_238 -> V_83 = V_222 -> V_83 ;
V_238 -> V_140 = V_222 -> V_239 ;
V_238 -> V_61 = V_222 -> V_240 ;
}
}
}
static void F_121 ( struct V_99 * V_100 ,
struct V_56 * error ,
struct V_157 * V_158 ,
const int V_241 )
{
struct V_32 * V_132 = NULL , * V_134 = NULL ;
struct V_155 * V_90 ;
struct V_160 * V_161 ;
int V_34 ;
V_34 = 0 ;
F_61 (vma, &vm->active_list, mm_list)
V_34 ++ ;
error -> V_133 [ V_241 ] = V_34 ;
F_61 (obj, &dev_priv->mm.bound_list, global_list) {
F_61 (vma, &obj->vma_list, vma_link)
if ( V_161 -> V_158 == V_158 && V_161 -> V_190 > 0 )
V_34 ++ ;
}
error -> V_135 [ V_241 ] = V_34 - error -> V_133 [ V_241 ] ;
if ( V_34 ) {
V_132 = F_120 ( V_34 , sizeof( * V_132 ) , V_167 ) ;
if ( V_132 )
V_134 = V_132 + error -> V_133 [ V_241 ] ;
}
if ( V_132 )
error -> V_133 [ V_241 ] =
F_60 ( V_132 ,
error -> V_133 [ V_241 ] ,
& V_158 -> V_242 ) ;
if ( V_134 )
error -> V_135 [ V_241 ] =
F_62 ( V_134 ,
error -> V_135 [ V_241 ] ,
& V_100 -> V_185 . V_243 , V_158 ) ;
error -> V_132 [ V_241 ] = V_132 ;
error -> V_134 [ V_241 ] = V_134 ;
}
static void F_122 ( struct V_99 * V_100 ,
struct V_56 * error )
{
struct V_157 * V_158 ;
int V_244 = 0 , V_34 = 0 ;
F_61 (vm, &dev_priv->vm_list, global_link)
V_244 ++ ;
error -> V_132 = F_120 ( V_244 , sizeof( * error -> V_132 ) , V_167 ) ;
error -> V_134 = F_120 ( V_244 , sizeof( * error -> V_134 ) , V_167 ) ;
error -> V_133 = F_120 ( V_244 , sizeof( * error -> V_133 ) ,
V_167 ) ;
error -> V_135 = F_120 ( V_244 , sizeof( * error -> V_135 ) ,
V_167 ) ;
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
F_121 ( V_100 , error , V_158 , V_34 ++ ) ;
error -> V_131 = V_244 ;
}
}
static void F_123 ( struct V_99 * V_100 ,
struct V_56 * error )
{
struct V_54 * V_55 = V_100 -> V_55 ;
int V_34 ;
if ( F_30 ( V_55 ) ) {
error -> V_117 [ 0 ] = F_67 ( V_245 ) ;
error -> V_116 = F_67 ( V_246 ) ;
error -> V_119 = F_67 ( V_247 ) ;
}
if ( F_103 ( V_55 ) )
error -> V_130 = F_67 ( V_248 ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 ) {
error -> V_128 = F_67 ( V_249 ) ;
error -> V_127 = F_67 ( V_250 ) ;
}
if ( F_104 ( V_55 ) ) {
error -> V_119 = F_67 ( V_251 ) ;
error -> V_252 = F_67 ( V_253 ) ;
error -> V_80 = F_67 ( V_254 ) ;
}
if ( F_20 ( V_55 ) -> V_69 >= 7 )
error -> V_119 = F_67 ( V_255 ) ;
if ( F_20 ( V_55 ) -> V_69 >= 6 ) {
error -> V_120 = F_67 ( V_256 ) ;
error -> error = F_67 ( V_257 ) ;
error -> V_129 = F_67 ( V_258 ) ;
}
if ( F_104 ( V_55 ) || F_103 ( V_55 ) ) {
error -> V_259 = F_67 ( V_260 ) ;
error -> V_261 = F_67 ( V_262 ) ;
}
if ( F_124 ( V_55 ) )
error -> V_121 = F_67 ( V_263 ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 ) {
error -> V_116 = F_67 ( V_264 ) ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ )
error -> V_117 [ V_34 ] = F_67 ( F_125 ( V_34 ) ) ;
} else if ( F_29 ( V_55 ) ) {
error -> V_116 = F_67 ( V_265 ) ;
error -> V_117 [ 0 ] = F_67 ( V_245 ) ;
} else if ( F_66 ( V_55 ) ) {
error -> V_116 = F_126 ( V_266 ) ;
} else if ( ! F_30 ( V_55 ) ) {
error -> V_116 = F_67 ( V_266 ) ;
}
error -> V_115 = F_67 ( V_267 ) ;
error -> V_118 = F_67 ( V_268 ) ;
F_127 ( V_55 , error -> V_126 ) ;
}
static void F_128 ( struct V_54 * V_55 ,
struct V_56 * error ,
bool V_269 ,
const char * V_105 )
{
struct V_99 * V_100 = V_55 -> V_101 ;
V_64 V_270 ;
int V_191 = - 1 , V_21 ;
V_270 = F_63 ( V_100 , error , & V_191 ) ;
V_21 = F_129 ( error -> V_105 , sizeof( error -> V_105 ) ,
L_97 ,
F_20 ( V_55 ) -> V_69 , V_191 , V_270 ) ;
if ( V_191 != - 1 && error -> V_2 [ V_191 ] . V_109 != - 1 )
V_21 += F_129 ( error -> V_105 + V_21 ,
sizeof( error -> V_105 ) - V_21 ,
L_98 ,
error -> V_2 [ V_191 ] . V_110 ,
error -> V_2 [ V_191 ] . V_109 ) ;
F_129 ( error -> V_105 + V_21 , sizeof( error -> V_105 ) - V_21 ,
L_99 ,
V_105 ,
V_269 ? L_100 : L_101 ) ;
}
static void F_130 ( struct V_99 * V_100 ,
struct V_56 * error )
{
error -> V_111 = F_131 ( & V_100 -> V_122 ) ;
error -> V_112 = V_100 -> V_112 ;
}
void F_132 ( struct V_54 * V_55 , bool V_269 ,
const char * V_105 )
{
static bool V_271 ;
struct V_99 * V_100 = V_55 -> V_101 ;
struct V_56 * error ;
unsigned long V_175 ;
error = F_133 ( sizeof( * error ) , V_167 ) ;
if ( ! error ) {
F_134 ( L_102 ) ;
return;
}
F_135 ( & error -> V_154 ) ;
F_130 ( V_100 , error ) ;
F_123 ( V_100 , error ) ;
F_122 ( V_100 , error ) ;
F_64 ( V_55 , error ) ;
F_114 ( V_55 , error ) ;
F_136 ( & error -> time ) ;
error -> V_145 = F_137 ( V_55 ) ;
error -> V_146 = F_138 ( V_55 ) ;
F_128 ( V_55 , error , V_269 , V_105 ) ;
F_139 ( L_62 , error -> V_105 ) ;
F_140 ( & V_100 -> V_122 . V_272 , V_175 ) ;
if ( V_100 -> V_122 . V_273 == NULL ) {
V_100 -> V_122 . V_273 = error ;
error = NULL ;
}
F_141 ( & V_100 -> V_122 . V_272 , V_175 ) ;
if ( error ) {
F_37 ( & error -> V_154 ) ;
return;
}
if ( ! V_271 ) {
F_139 ( L_103 ) ;
F_139 ( L_104 ) ;
F_139 ( L_105 ) ;
F_139 ( L_106 ) ;
F_139 ( L_107 , V_55 -> V_274 -> V_275 ) ;
V_271 = true ;
}
}
void F_142 ( struct V_54 * V_55 ,
struct V_97 * V_98 )
{
struct V_99 * V_100 = V_55 -> V_101 ;
F_143 ( & V_100 -> V_122 . V_272 ) ;
V_98 -> error = V_100 -> V_122 . V_273 ;
if ( V_98 -> error )
F_144 ( & V_98 -> error -> V_154 ) ;
F_145 ( & V_100 -> V_122 . V_272 ) ;
}
void F_146 ( struct V_97 * V_98 )
{
if ( V_98 -> error )
F_147 ( & V_98 -> error -> V_154 , F_37 ) ;
}
void F_148 ( struct V_54 * V_55 )
{
struct V_99 * V_100 = V_55 -> V_101 ;
struct V_56 * error ;
F_143 ( & V_100 -> V_122 . V_272 ) ;
error = V_100 -> V_122 . V_273 ;
V_100 -> V_122 . V_273 = NULL ;
F_145 ( & V_100 -> V_122 . V_272 ) ;
if ( error )
F_147 ( & error -> V_154 , F_37 ) ;
}
const char * F_17 ( struct V_99 * V_42 , int type )
{
switch ( type ) {
case V_168 : return L_108 ;
case V_276 : return F_46 ( V_42 ) ? L_109 : L_110 ;
case V_277 : return L_111 ;
case V_278 : return L_112 ;
default: return L_8 ;
}
}
void F_127 ( struct V_54 * V_55 , T_5 * V_68 )
{
struct V_99 * V_100 = V_55 -> V_101 ;
memset ( V_68 , 0 , sizeof( * V_68 ) * V_279 ) ;
if ( F_66 ( V_55 ) || F_65 ( V_55 ) )
V_68 [ 0 ] = F_67 ( V_209 ) ;
else if ( F_72 ( V_55 ) || F_71 ( V_55 ) || F_104 ( V_55 ) ) {
V_68 [ 0 ] = F_67 ( V_280 ) ;
V_68 [ 1 ] = F_67 ( V_281 ) ;
} else if ( F_20 ( V_55 ) -> V_69 >= 7 ) {
V_68 [ 0 ] = F_67 ( V_282 ) ;
V_68 [ 1 ] = F_67 ( V_283 ) ;
V_68 [ 2 ] = F_67 ( V_284 ) ;
V_68 [ 3 ] = F_67 ( V_285 ) ;
}
}
