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
default: return L_7 ;
}
}
static const char * F_3 ( int V_7 )
{
if ( V_7 > 0 )
return L_8 ;
else if ( V_7 < 0 )
return L_9 ;
else
return L_7 ;
}
static const char * F_4 ( int V_8 )
{
switch ( V_8 ) {
default:
case V_9 : return L_7 ;
case V_10 : return L_10 ;
case V_11 : return L_11 ;
}
}
static const char * F_5 ( int V_12 )
{
return V_12 ? L_12 : L_7 ;
}
static const char * F_6 ( int V_13 )
{
return V_13 ? L_13 : L_7 ;
}
static bool F_7 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_16 && F_8 ( V_15 -> V_17 > ( V_15 -> V_18 - 1 ) , L_14 ) ) {
V_15 -> V_16 = - V_19 ;
return false ;
}
if ( V_15 -> V_17 == V_15 -> V_18 - 1 || V_15 -> V_16 )
return false ;
return true ;
}
static bool F_9 ( struct V_14 * V_15 ,
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
static void F_10 ( struct V_14 * V_15 ,
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
static void F_11 ( struct V_14 * V_15 ,
const char * V_26 , T_2 args )
{
unsigned V_20 ;
if ( ! F_7 ( V_15 ) )
return;
if ( V_15 -> V_21 < V_15 -> V_22 ) {
T_2 V_27 ;
F_12 ( V_27 , args ) ;
V_20 = vsnprintf ( NULL , 0 , V_26 , V_27 ) ;
va_end ( V_27 ) ;
if ( ! F_9 ( V_15 , V_20 ) )
return;
}
V_20 = vsnprintf ( V_15 -> V_25 + V_15 -> V_17 , V_15 -> V_18 - V_15 -> V_17 , V_26 , args ) ;
if ( V_20 >= V_15 -> V_18 - V_15 -> V_17 )
V_20 = V_15 -> V_18 - V_15 -> V_17 - 1 ;
F_10 ( V_15 , V_20 ) ;
}
static void F_13 ( struct V_14 * V_15 ,
const char * V_28 )
{
unsigned V_20 ;
if ( ! F_7 ( V_15 ) )
return;
V_20 = strlen ( V_28 ) ;
if ( V_15 -> V_21 < V_15 -> V_22 ) {
if ( ! F_9 ( V_15 , V_20 ) )
return;
}
if ( V_20 >= V_15 -> V_18 - V_15 -> V_17 )
V_20 = V_15 -> V_18 - V_15 -> V_17 - 1 ;
memcpy ( V_15 -> V_25 + V_15 -> V_17 , V_28 , V_20 ) ;
F_10 ( V_15 , V_20 ) ;
}
static void F_14 ( struct V_14 * V_29 ,
const char * V_30 ,
struct V_31 * V_16 ,
int V_32 )
{
F_15 ( V_29 , L_15 , V_30 , V_32 ) ;
while ( V_32 -- ) {
F_15 ( V_29 , L_16 ,
V_16 -> V_33 ,
V_16 -> V_18 ,
V_16 -> V_34 ,
V_16 -> V_35 ,
V_16 -> V_36 , V_16 -> V_37 ) ;
F_16 ( V_29 , F_3 ( V_16 -> V_7 ) ) ;
F_16 ( V_29 , F_4 ( V_16 -> V_8 ) ) ;
F_16 ( V_29 , F_5 ( V_16 -> V_12 ) ) ;
F_16 ( V_29 , F_6 ( V_16 -> V_13 ) ) ;
F_16 ( V_29 , V_16 -> V_2 != - 1 ? L_17 : L_7 ) ;
F_16 ( V_29 , F_2 ( V_16 -> V_2 ) ) ;
F_16 ( V_29 , F_17 ( V_16 -> V_38 ) ) ;
if ( V_16 -> V_30 )
F_15 ( V_29 , L_18 , V_16 -> V_30 ) ;
if ( V_16 -> V_39 != V_40 )
F_15 ( V_29 , L_19 , V_16 -> V_39 ) ;
F_16 ( V_29 , L_20 ) ;
V_16 ++ ;
}
}
static const char * F_18 ( enum V_41 V_42 )
{
switch ( V_42 ) {
case V_43 :
return L_21 ;
case V_44 :
return L_22 ;
case V_45 :
return L_23 ;
case V_46 :
return L_24 ;
case V_47 :
return L_25 ;
}
return L_26 ;
}
static void F_19 ( struct V_14 * V_29 ,
struct V_48 * V_49 ,
struct V_50 * V_2 )
{
if ( ! V_2 -> V_51 )
return;
F_15 ( V_29 , L_27 , V_2 -> V_52 ) ;
F_15 ( V_29 , L_28 , V_2 -> V_53 ) ;
F_15 ( V_29 , L_29 , V_2 -> V_54 ) ;
F_15 ( V_29 , L_30 , V_2 -> V_55 ) ;
F_15 ( V_29 , L_31 , ( V_56 ) ( V_2 -> V_57 >> 32 ) , ( V_56 ) V_2 -> V_57 ) ;
F_15 ( V_29 , L_32 , V_2 -> V_58 ) ;
F_15 ( V_29 , L_33 , V_2 -> V_59 ) ;
F_15 ( V_29 , L_34 , V_2 -> V_60 ) ;
if ( F_20 ( V_49 ) -> V_61 >= 4 ) {
F_15 ( V_29 , L_35 , ( V_56 ) ( V_2 -> V_62 >> 32 ) , ( V_56 ) V_2 -> V_62 ) ;
F_15 ( V_29 , L_36 , V_2 -> V_63 ) ;
F_15 ( V_29 , L_37 , V_2 -> V_64 ) ;
}
F_15 ( V_29 , L_38 , V_2 -> V_65 ) ;
F_15 ( V_29 , L_39 , V_2 -> V_66 ) ;
if ( F_20 ( V_49 ) -> V_61 >= 6 ) {
F_15 ( V_29 , L_40 , V_2 -> V_67 ) ;
F_15 ( V_29 , L_41 , V_2 -> V_68 ) ;
F_15 ( V_29 , L_42 ,
V_2 -> V_69 [ 0 ] ,
V_2 -> V_70 [ 0 ] ) ;
F_15 ( V_29 , L_43 ,
V_2 -> V_69 [ 1 ] ,
V_2 -> V_70 [ 1 ] ) ;
if ( F_21 ( V_49 ) ) {
F_15 ( V_29 , L_44 ,
V_2 -> V_69 [ 2 ] ,
V_2 -> V_70 [ 2 ] ) ;
}
}
if ( F_22 ( V_49 ) ) {
F_15 ( V_29 , L_45 , V_2 -> V_71 . V_72 ) ;
if ( F_20 ( V_49 ) -> V_61 >= 8 ) {
int V_73 ;
for ( V_73 = 0 ; V_73 < 4 ; V_73 ++ )
F_15 ( V_29 , L_46 ,
V_73 , V_2 -> V_71 . V_74 [ V_73 ] ) ;
} else {
F_15 ( V_29 , L_47 ,
V_2 -> V_71 . V_75 ) ;
}
}
F_15 ( V_29 , L_48 , V_2 -> V_76 ) ;
F_15 ( V_29 , L_49 , F_1 ( V_2 -> V_77 ) ) ;
F_15 ( V_29 , L_50 , V_2 -> V_78 ) ;
F_15 ( V_29 , L_51 , V_2 -> V_79 ) ;
F_15 ( V_29 , L_52 ,
F_18 ( V_2 -> V_80 ) ,
V_2 -> V_81 ) ;
}
void F_23 ( struct V_14 * V_15 , const char * V_26 , ... )
{
T_2 args ;
va_start ( args , V_26 ) ;
F_11 ( V_15 , V_26 , args ) ;
va_end ( args ) ;
}
static void F_24 ( struct V_14 * V_29 ,
struct V_82 * V_83 )
{
int V_84 , V_85 , V_86 ;
for ( V_84 = V_85 = 0 ; V_84 < V_83 -> V_87 ; V_84 ++ ) {
for ( V_86 = 0 ; V_86 < V_88 / 4 ; V_86 ++ ) {
F_15 ( V_29 , L_53 , V_85 ,
V_83 -> V_89 [ V_84 ] [ V_86 ] ) ;
V_85 += 4 ;
}
}
}
int F_25 ( struct V_14 * V_29 ,
const struct V_90 * V_91 )
{
struct V_48 * V_49 = V_91 -> V_49 ;
struct V_92 * V_93 = V_49 -> V_94 ;
struct V_95 * error = V_91 -> error ;
int V_73 , V_96 , V_85 , V_86 ;
int V_97 ;
if ( ! error ) {
F_15 ( V_29 , L_54 ) ;
goto V_98;
}
F_15 ( V_29 , L_55 , error -> V_99 ) ;
F_15 ( V_29 , L_56 , error -> time . V_100 ,
error -> time . V_101 ) ;
F_15 ( V_29 , L_57 V_102 L_20 ) ;
V_97 = 0 ;
for ( V_73 = 0 ; V_73 < F_26 ( error -> V_2 ) ; V_73 ++ ) {
if ( error -> V_2 [ V_73 ] . V_81 > V_97 )
V_97 = error -> V_2 [ V_73 ] . V_81 ;
}
for ( V_73 = 0 ; V_73 < F_26 ( error -> V_2 ) ; V_73 ++ ) {
if ( error -> V_2 [ V_73 ] . V_81 == V_97 &&
error -> V_2 [ V_73 ] . V_103 != - 1 ) {
F_15 ( V_29 , L_58 ,
F_2 ( V_73 ) ,
error -> V_2 [ V_73 ] . V_104 ,
error -> V_2 [ V_73 ] . V_103 ) ;
}
}
F_15 ( V_29 , L_59 , error -> V_105 ) ;
F_15 ( V_29 , L_60 , error -> V_106 ) ;
F_15 ( V_29 , L_61 , V_49 -> V_107 -> V_108 ) ;
F_15 ( V_29 , L_62 , error -> V_109 ) ;
F_15 ( V_29 , L_63 , error -> V_110 ) ;
F_15 ( V_29 , L_64 , error -> V_111 ) ;
F_15 ( V_29 , L_65 , error -> V_112 ) ;
F_15 ( V_29 , L_66 , error -> V_113 ) ;
F_15 ( V_29 , L_67 , error -> V_114 ) ;
F_15 ( V_29 , L_68 , V_93 -> V_115 . V_116 ) ;
for ( V_73 = 0 ; V_73 < V_93 -> V_117 ; V_73 ++ )
F_15 ( V_29 , L_69 , V_73 , error -> V_118 [ V_73 ] ) ;
for ( V_73 = 0 ; V_73 < F_26 ( error -> V_119 ) ; V_73 ++ )
F_15 ( V_29 , L_70 , V_73 ,
error -> V_119 [ V_73 ] ) ;
if ( F_20 ( V_49 ) -> V_61 >= 6 ) {
F_15 ( V_29 , L_71 , error -> error ) ;
F_15 ( V_29 , L_72 , error -> V_120 ) ;
}
if ( F_20 ( V_49 ) -> V_61 == 7 )
F_15 ( V_29 , L_73 , error -> V_121 ) ;
for ( V_73 = 0 ; V_73 < F_26 ( error -> V_2 ) ; V_73 ++ ) {
F_15 ( V_29 , L_74 , F_2 ( V_73 ) ) ;
F_19 ( V_29 , V_49 , & error -> V_2 [ V_73 ] ) ;
}
if ( error -> V_122 )
F_14 ( V_29 , L_75 ,
error -> V_122 [ 0 ] ,
error -> V_123 [ 0 ] ) ;
if ( error -> V_124 )
F_14 ( V_29 , L_76 ,
error -> V_124 [ 0 ] ,
error -> V_125 [ 0 ] ) ;
for ( V_73 = 0 ; V_73 < F_26 ( error -> V_2 ) ; V_73 ++ ) {
struct V_82 * V_83 ;
V_83 = error -> V_2 [ V_73 ] . V_126 ;
if ( V_83 ) {
F_16 ( V_29 , V_93 -> V_2 [ V_73 ] . V_30 ) ;
if ( error -> V_2 [ V_73 ] . V_103 != - 1 )
F_15 ( V_29 , L_77 ,
error -> V_2 [ V_73 ] . V_104 ,
error -> V_2 [ V_73 ] . V_103 ) ;
F_15 ( V_29 , L_78 ,
V_83 -> V_33 ) ;
F_24 ( V_29 , V_83 ) ;
}
V_83 = error -> V_2 [ V_73 ] . V_127 ;
if ( V_83 ) {
F_15 ( V_29 , L_79 ,
V_93 -> V_2 [ V_73 ] . V_30 , V_83 -> V_33 ) ;
F_24 ( V_29 , V_83 ) ;
}
if ( error -> V_2 [ V_73 ] . V_128 ) {
F_15 ( V_29 , L_80 ,
V_93 -> V_2 [ V_73 ] . V_30 ,
error -> V_2 [ V_73 ] . V_128 ) ;
for ( V_96 = 0 ; V_96 < error -> V_2 [ V_73 ] . V_128 ; V_96 ++ ) {
F_15 ( V_29 , L_81 ,
error -> V_2 [ V_73 ] . V_129 [ V_96 ] . V_76 ,
error -> V_2 [ V_73 ] . V_129 [ V_96 ] . V_130 ,
error -> V_2 [ V_73 ] . V_129 [ V_96 ] . V_53 ) ;
}
}
if ( ( V_83 = error -> V_2 [ V_73 ] . V_131 ) ) {
F_15 ( V_29 , L_82 ,
V_93 -> V_2 [ V_73 ] . V_30 ,
V_83 -> V_33 ) ;
F_24 ( V_29 , V_83 ) ;
}
if ( ( V_83 = error -> V_2 [ V_73 ] . V_132 ) ) {
F_15 ( V_29 , L_83 ,
V_93 -> V_2 [ V_73 ] . V_30 ,
V_83 -> V_33 ) ;
V_85 = 0 ;
for ( V_86 = 0 ; V_86 < V_88 / 16 ; V_86 += 4 ) {
F_15 ( V_29 , L_84 ,
V_85 ,
V_83 -> V_89 [ 0 ] [ V_86 ] ,
V_83 -> V_89 [ 0 ] [ V_86 + 1 ] ,
V_83 -> V_89 [ 0 ] [ V_86 + 2 ] ,
V_83 -> V_89 [ 0 ] [ V_86 + 3 ] ) ;
V_85 += 16 ;
}
}
if ( ( V_83 = error -> V_2 [ V_73 ] . V_133 ) ) {
F_15 ( V_29 , L_85 ,
V_93 -> V_2 [ V_73 ] . V_30 ,
V_83 -> V_33 ) ;
V_85 = 0 ;
for ( V_86 = 0 ; V_86 < V_88 / 16 ; V_86 += 4 ) {
F_15 ( V_29 , L_84 ,
V_85 ,
V_83 -> V_89 [ 0 ] [ V_86 ] ,
V_83 -> V_89 [ 0 ] [ V_86 + 1 ] ,
V_83 -> V_89 [ 0 ] [ V_86 + 2 ] ,
V_83 -> V_89 [ 0 ] [ V_86 + 3 ] ) ;
V_85 += 16 ;
}
}
}
if ( error -> V_134 )
F_27 ( V_29 , error -> V_134 ) ;
if ( error -> V_135 )
F_28 ( V_29 , V_49 , error -> V_135 ) ;
V_98:
if ( V_29 -> V_17 == 0 && V_29 -> V_16 )
return V_29 -> V_16 ;
return 0 ;
}
int F_29 ( struct V_14 * V_136 ,
T_1 V_32 , T_3 V_21 )
{
memset ( V_136 , 0 , sizeof( * V_136 ) ) ;
V_136 -> V_18 = V_32 + 1 > V_88 ? V_32 + 1 : V_88 ;
V_136 -> V_25 = F_30 ( V_136 -> V_18 ,
V_137 | V_138 | V_139 ) ;
if ( V_136 -> V_25 == NULL ) {
V_136 -> V_18 = V_88 ;
V_136 -> V_25 = F_30 ( V_136 -> V_18 , V_137 ) ;
}
if ( V_136 -> V_25 == NULL ) {
V_136 -> V_18 = 128 ;
V_136 -> V_25 = F_30 ( V_136 -> V_18 , V_137 ) ;
}
if ( V_136 -> V_25 == NULL )
return - V_140 ;
V_136 -> V_22 = V_21 ;
return 0 ;
}
static void F_31 ( struct V_82 * V_83 )
{
int V_84 ;
if ( V_83 == NULL )
return;
for ( V_84 = 0 ; V_84 < V_83 -> V_87 ; V_84 ++ )
F_32 ( V_83 -> V_89 [ V_84 ] ) ;
F_32 ( V_83 ) ;
}
static void F_33 ( struct V_141 * V_142 )
{
struct V_95 * error = F_34 ( V_142 ,
F_35 ( * error ) , V_143 ) ;
int V_73 ;
for ( V_73 = 0 ; V_73 < F_26 ( error -> V_2 ) ; V_73 ++ ) {
F_31 ( error -> V_2 [ V_73 ] . V_126 ) ;
F_31 ( error -> V_2 [ V_73 ] . V_131 ) ;
F_31 ( error -> V_2 [ V_73 ] . V_132 ) ;
F_31 ( error -> V_2 [ V_73 ] . V_133 ) ;
F_32 ( error -> V_2 [ V_73 ] . V_129 ) ;
}
F_32 ( error -> V_122 ) ;
F_32 ( error -> V_134 ) ;
F_32 ( error -> V_135 ) ;
F_32 ( error ) ;
}
static struct V_82 *
F_36 ( struct V_92 * V_93 ,
struct V_144 * V_145 ,
struct V_146 * V_147 ,
const int V_148 )
{
struct V_82 * V_149 ;
int V_73 ;
V_56 V_150 ;
if ( V_145 == NULL || V_145 -> V_89 == NULL )
return NULL ;
V_149 = F_30 ( sizeof( * V_149 ) + V_148 * sizeof( V_56 * ) , V_151 ) ;
if ( V_149 == NULL )
return NULL ;
V_150 = V_149 -> V_33 = F_37 ( V_145 , V_147 ) ;
for ( V_73 = 0 ; V_73 < V_148 ; V_73 ++ ) {
unsigned long V_152 ;
void * V_153 ;
V_153 = F_30 ( V_88 , V_151 ) ;
if ( V_153 == NULL )
goto V_154;
F_38 ( V_152 ) ;
if ( V_145 -> V_38 == V_155 &&
V_150 < V_93 -> V_156 . V_157 &&
V_145 -> V_158 &&
F_39 ( V_147 ) ) {
void T_4 * V_159 ;
V_159 = F_40 ( V_93 -> V_156 . V_160 ,
V_150 ) ;
F_41 ( V_153 , V_159 , V_88 ) ;
F_42 ( V_159 ) ;
} else if ( V_145 -> V_161 ) {
unsigned long V_85 ;
V_85 = V_93 -> V_162 . V_163 ;
V_85 += V_145 -> V_161 -> V_22 ;
V_85 += V_73 << V_164 ;
F_41 ( V_153 , ( void T_4 * ) V_85 , V_88 ) ;
} else {
struct V_84 * V_84 ;
void * V_159 ;
V_84 = F_43 ( V_145 , V_73 ) ;
F_44 ( & V_84 , 1 ) ;
V_159 = F_45 ( V_84 ) ;
memcpy ( V_153 , V_159 , V_88 ) ;
F_46 ( V_159 ) ;
F_44 ( & V_84 , 1 ) ;
}
F_47 ( V_152 ) ;
V_149 -> V_89 [ V_73 ] = V_153 ;
V_150 += V_88 ;
}
V_149 -> V_87 = V_148 ;
return V_149 ;
V_154:
while ( V_73 -- )
F_32 ( V_149 -> V_89 [ V_73 ] ) ;
F_32 ( V_149 ) ;
return NULL ;
}
static void F_48 ( struct V_31 * V_16 ,
struct V_144 * V_83 )
{
V_16 -> V_18 = V_83 -> V_165 . V_18 ;
V_16 -> V_30 = V_83 -> V_165 . V_30 ;
V_16 -> V_36 = V_83 -> V_166 ;
V_16 -> V_37 = V_83 -> V_167 ;
V_16 -> V_33 = F_49 ( V_83 ) ;
V_16 -> V_34 = V_83 -> V_165 . V_34 ;
V_16 -> V_35 = V_83 -> V_165 . V_35 ;
V_16 -> V_39 = V_83 -> V_39 ;
V_16 -> V_7 = 0 ;
if ( F_50 ( V_83 ) )
V_16 -> V_7 = 1 ;
if ( V_83 -> V_168 > 0 )
V_16 -> V_7 = - 1 ;
V_16 -> V_8 = V_83 -> V_169 ;
V_16 -> V_12 = V_83 -> V_12 ;
V_16 -> V_13 = V_83 -> V_170 != V_171 ;
V_16 -> V_2 = V_83 -> V_2 ? V_83 -> V_2 -> V_172 : - 1 ;
V_16 -> V_38 = V_83 -> V_38 ;
}
static V_56 F_51 ( struct V_31 * V_16 ,
int V_32 , struct V_173 * V_52 )
{
struct V_174 * V_175 ;
int V_73 = 0 ;
F_52 (vma, head, mm_list) {
F_48 ( V_16 ++ , V_175 -> V_83 ) ;
if ( ++ V_73 == V_32 )
break;
}
return V_73 ;
}
static V_56 F_53 ( struct V_31 * V_16 ,
int V_32 , struct V_173 * V_52 )
{
struct V_144 * V_83 ;
int V_73 = 0 ;
F_52 (obj, head, global_list) {
if ( ! F_50 ( V_83 ) )
continue;
F_48 ( V_16 ++ , V_83 ) ;
if ( ++ V_73 == V_32 )
break;
}
return V_73 ;
}
static T_5 F_54 ( struct V_92 * V_93 ,
struct V_95 * error ,
int * V_176 )
{
T_5 V_177 = 0 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_178 ; V_73 ++ ) {
if ( error -> V_2 [ V_73 ] . V_80 == V_47 ) {
if ( V_176 )
* V_176 = V_73 ;
return error -> V_2 [ V_73 ] . V_59 ^ error -> V_2 [ V_73 ] . V_60 ;
}
}
return V_177 ;
}
static void F_55 ( struct V_48 * V_49 ,
struct V_95 * error )
{
struct V_92 * V_93 = V_49 -> V_94 ;
int V_73 ;
switch ( F_20 ( V_49 ) -> V_61 ) {
case 8 :
case 7 :
case 6 :
for ( V_73 = 0 ; V_73 < V_93 -> V_117 ; V_73 ++ )
error -> V_118 [ V_73 ] = F_56 ( V_179 + ( V_73 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_73 = 0 ; V_73 < 16 ; V_73 ++ )
error -> V_118 [ V_73 ] = F_56 ( V_180 + ( V_73 * 8 ) ) ;
break;
case 3 :
if ( F_57 ( V_49 ) || F_58 ( V_49 ) || F_59 ( V_49 ) )
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ )
error -> V_118 [ V_73 + 8 ] = F_60 ( V_181 + ( V_73 * 4 ) ) ;
case 2 :
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ )
error -> V_118 [ V_73 ] = F_60 ( V_182 + ( V_73 * 4 ) ) ;
break;
default:
F_61 () ;
}
}
static void F_62 ( struct V_48 * V_49 ,
struct V_183 * V_2 ,
struct V_50 * V_184 )
{
struct V_92 * V_93 = V_49 -> V_94 ;
if ( F_20 ( V_49 ) -> V_61 >= 6 ) {
V_184 -> V_67 = F_60 ( V_2 -> V_185 + 0x50 ) ;
V_184 -> V_68 = F_60 ( F_63 ( V_2 ) ) ;
V_184 -> V_69 [ 0 ]
= F_60 ( F_64 ( V_2 -> V_185 ) ) ;
V_184 -> V_69 [ 1 ]
= F_60 ( F_65 ( V_2 -> V_185 ) ) ;
V_184 -> V_70 [ 0 ] = V_2 -> V_186 [ 0 ] ;
V_184 -> V_70 [ 1 ] = V_2 -> V_186 [ 1 ] ;
}
if ( F_21 ( V_49 ) ) {
V_184 -> V_69 [ 2 ] =
F_60 ( F_66 ( V_2 -> V_185 ) ) ;
V_184 -> V_70 [ 2 ] = V_2 -> V_186 [ 2 ] ;
}
if ( F_20 ( V_49 ) -> V_61 >= 4 ) {
V_184 -> V_66 = F_60 ( F_67 ( V_2 -> V_185 ) ) ;
V_184 -> V_58 = F_60 ( F_68 ( V_2 -> V_185 ) ) ;
V_184 -> V_59 = F_60 ( F_69 ( V_2 -> V_185 ) ) ;
V_184 -> V_60 = F_60 ( F_70 ( V_2 -> V_185 ) ) ;
V_184 -> V_64 = F_60 ( F_71 ( V_2 -> V_185 ) ) ;
V_184 -> V_62 = F_60 ( F_72 ( V_2 -> V_185 ) ) ;
if ( F_20 ( V_49 ) -> V_61 >= 8 )
V_184 -> V_62 |= ( V_187 ) F_60 ( F_73 ( V_2 -> V_185 ) ) << 32 ;
V_184 -> V_63 = F_60 ( F_74 ( V_2 -> V_185 ) ) ;
} else {
V_184 -> V_66 = F_60 ( V_188 ) ;
V_184 -> V_58 = F_60 ( V_189 ) ;
V_184 -> V_59 = F_60 ( V_190 ) ;
V_184 -> V_60 = F_60 ( V_191 ) ;
}
V_184 -> V_77 = F_75 ( & V_2 -> V_192 ) ;
V_184 -> V_65 = F_60 ( F_76 ( V_2 -> V_185 ) ) ;
V_184 -> V_76 = V_2 -> V_193 ( V_2 , false ) ;
V_184 -> V_57 = F_77 ( V_2 ) ;
V_184 -> V_52 = F_78 ( V_2 ) ;
V_184 -> V_53 = F_79 ( V_2 ) ;
V_184 -> V_54 = F_80 ( V_2 ) ;
if ( F_81 ( V_49 ) ) {
int V_194 ;
if ( F_82 ( V_49 ) ) {
switch ( V_2 -> V_172 ) {
default:
case V_3 :
V_194 = V_195 ;
break;
case V_5 :
V_194 = V_196 ;
break;
case V_4 :
V_194 = V_197 ;
break;
case V_6 :
V_194 = V_198 ;
break;
}
} else if ( F_83 ( V_2 -> V_49 ) ) {
V_194 = F_84 ( V_2 -> V_185 ) ;
} else {
V_194 = F_85 ( V_2 -> V_185 ) ;
}
V_184 -> V_55 = F_60 ( V_194 ) ;
}
V_184 -> V_78 = V_2 -> V_52 ;
V_184 -> V_79 = V_2 -> V_53 ;
V_184 -> V_81 = V_2 -> V_199 . V_200 ;
V_184 -> V_80 = V_2 -> V_199 . V_201 ;
if ( F_22 ( V_49 ) ) {
int V_73 ;
V_184 -> V_71 . V_72 = F_60 ( F_86 ( V_2 ) ) ;
switch ( F_20 ( V_49 ) -> V_61 ) {
case 8 :
for ( V_73 = 0 ; V_73 < 4 ; V_73 ++ ) {
V_184 -> V_71 . V_74 [ V_73 ] =
F_60 ( F_87 ( V_2 , V_73 ) ) ;
V_184 -> V_71 . V_74 [ V_73 ] <<= 32 ;
V_184 -> V_71 . V_74 [ V_73 ] |=
F_60 ( F_88 ( V_2 , V_73 ) ) ;
}
break;
case 7 :
V_184 -> V_71 . V_75 =
F_60 ( F_89 ( V_2 ) ) ;
break;
case 6 :
V_184 -> V_71 . V_75 =
F_60 ( F_90 ( V_2 ) ) ;
break;
}
}
}
static void F_91 ( struct V_183 * V_2 ,
struct V_95 * error ,
struct V_50 * V_184 )
{
struct V_92 * V_93 = V_2 -> V_49 -> V_94 ;
struct V_144 * V_83 ;
if ( V_2 -> V_172 != V_3 || ! error -> V_114 )
return;
F_52 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ( error -> V_114 & V_202 ) == F_49 ( V_83 ) ) {
V_184 -> V_133 = F_36 ( V_93 ,
V_83 ,
& V_93 -> V_156 . V_165 ,
1 ) ;
break;
}
}
}
static void F_92 ( struct V_48 * V_49 ,
struct V_95 * error )
{
struct V_92 * V_93 = V_49 -> V_94 ;
struct V_203 * V_204 ;
int V_73 , V_32 ;
for ( V_73 = 0 ; V_73 < V_178 ; V_73 ++ ) {
struct V_183 * V_2 = & V_93 -> V_2 [ V_73 ] ;
if ( V_2 -> V_49 == NULL )
continue;
error -> V_2 [ V_73 ] . V_51 = true ;
F_62 ( V_49 , V_2 , & error -> V_2 [ V_73 ] ) ;
error -> V_2 [ V_73 ] . V_103 = - 1 ;
V_204 = F_93 ( V_2 ) ;
if ( V_204 ) {
error -> V_2 [ V_73 ] . V_126 =
F_94 ( V_93 ,
V_204 -> V_205 ,
V_204 -> V_133 ?
V_204 -> V_133 -> V_147 :
& V_93 -> V_156 . V_165 ) ;
if ( F_95 ( V_93 -> V_49 ) &&
V_2 -> V_206 . V_83 )
error -> V_2 [ V_73 ] . V_127 =
F_96 ( V_93 ,
V_2 -> V_206 . V_83 ) ;
if ( V_204 -> V_207 ) {
struct V_208 * V_209 ;
F_97 () ;
V_209 = F_98 ( V_204 -> V_207 -> V_210 -> V_103 ,
V_211 ) ;
if ( V_209 ) {
strcpy ( error -> V_2 [ V_73 ] . V_104 , V_209 -> V_104 ) ;
error -> V_2 [ V_73 ] . V_103 = V_209 -> V_103 ;
}
F_99 () ;
}
}
error -> V_2 [ V_73 ] . V_131 =
F_96 ( V_93 , V_2 -> V_83 ) ;
if ( V_2 -> V_212 . V_83 )
error -> V_2 [ V_73 ] . V_132 =
F_96 ( V_93 , V_2 -> V_212 . V_83 ) ;
F_91 ( V_2 , error , & error -> V_2 [ V_73 ] ) ;
V_32 = 0 ;
F_52 (request, &ring->request_list, list)
V_32 ++ ;
error -> V_2 [ V_73 ] . V_128 = V_32 ;
error -> V_2 [ V_73 ] . V_129 =
F_100 ( V_32 , sizeof( * error -> V_2 [ V_73 ] . V_129 ) ,
V_151 ) ;
if ( error -> V_2 [ V_73 ] . V_129 == NULL ) {
error -> V_2 [ V_73 ] . V_128 = 0 ;
continue;
}
V_32 = 0 ;
F_52 (request, &ring->request_list, list) {
struct V_213 * V_214 ;
V_214 = & error -> V_2 [ V_73 ] . V_129 [ V_32 ++ ] ;
V_214 -> V_76 = V_204 -> V_76 ;
V_214 -> V_130 = V_204 -> V_215 ;
V_214 -> V_53 = V_204 -> V_53 ;
}
}
}
static void F_101 ( struct V_92 * V_93 ,
struct V_95 * error ,
struct V_146 * V_147 ,
const int V_216 )
{
struct V_31 * V_122 = NULL , * V_124 = NULL ;
struct V_144 * V_83 ;
struct V_174 * V_175 ;
int V_73 ;
V_73 = 0 ;
F_52 (vma, &vm->active_list, mm_list)
V_73 ++ ;
error -> V_123 [ V_216 ] = V_73 ;
F_52 (obj, &dev_priv->mm.bound_list, global_list)
if ( F_50 ( V_83 ) )
V_73 ++ ;
error -> V_125 [ V_216 ] = V_73 - error -> V_123 [ V_216 ] ;
if ( V_73 ) {
V_122 = F_100 ( V_73 , sizeof( * V_122 ) , V_151 ) ;
if ( V_122 )
V_124 = V_122 + error -> V_123 [ V_216 ] ;
}
if ( V_122 )
error -> V_123 [ V_216 ] =
F_51 ( V_122 ,
error -> V_123 [ V_216 ] ,
& V_147 -> V_217 ) ;
if ( V_124 )
error -> V_125 [ V_216 ] =
F_53 ( V_124 ,
error -> V_125 [ V_216 ] ,
& V_93 -> V_162 . V_218 ) ;
error -> V_122 [ V_216 ] = V_122 ;
error -> V_124 [ V_216 ] = V_124 ;
}
static void F_102 ( struct V_92 * V_93 ,
struct V_95 * error )
{
struct V_146 * V_147 ;
int V_219 = 0 , V_73 = 0 ;
F_52 (vm, &dev_priv->vm_list, global_link)
V_219 ++ ;
error -> V_122 = F_100 ( V_219 , sizeof( * error -> V_122 ) , V_151 ) ;
error -> V_124 = F_100 ( V_219 , sizeof( * error -> V_124 ) , V_151 ) ;
error -> V_123 = F_100 ( V_219 , sizeof( * error -> V_123 ) ,
V_151 ) ;
error -> V_125 = F_100 ( V_219 , sizeof( * error -> V_125 ) ,
V_151 ) ;
F_52 (vm, &dev_priv->vm_list, global_link)
F_101 ( V_93 , error , V_147 , V_73 ++ ) ;
}
static void F_103 ( struct V_92 * V_93 ,
struct V_95 * error )
{
struct V_48 * V_49 = V_93 -> V_49 ;
int V_220 ;
if ( F_104 ( V_49 ) ) {
error -> V_110 = F_60 ( V_221 ) | F_60 ( V_222 ) ;
error -> V_112 = F_60 ( V_223 ) ;
}
if ( F_82 ( V_49 ) )
error -> V_121 = F_60 ( V_224 ) ;
if ( F_83 ( V_49 ) ) {
error -> V_112 = F_60 ( V_225 ) ;
error -> V_226 = F_60 ( V_227 ) ;
error -> V_72 = F_60 ( V_228 ) ;
}
if ( F_105 ( V_49 ) )
error -> V_110 = F_106 ( V_229 ) ;
if ( F_20 ( V_49 ) -> V_61 >= 7 )
error -> V_112 = F_60 ( V_230 ) ;
if ( F_20 ( V_49 ) -> V_61 >= 6 ) {
error -> V_113 = F_60 ( V_231 ) ;
error -> error = F_60 ( V_232 ) ;
error -> V_120 = F_60 ( V_233 ) ;
}
if ( F_83 ( V_49 ) || F_82 ( V_49 ) ) {
error -> V_234 = F_60 ( V_235 ) ;
error -> V_236 = F_60 ( V_237 ) ;
}
if ( F_107 ( V_49 ) )
error -> V_114 = F_60 ( V_238 ) ;
if ( F_108 ( V_49 ) )
error -> V_110 = F_60 ( V_239 ) | F_60 ( V_221 ) ;
else {
error -> V_110 = F_60 ( V_229 ) ;
F_109 ( V_220 )
error -> V_240 [ V_220 ] = F_60 ( F_110 ( V_220 ) ) ;
}
error -> V_109 = F_60 ( V_241 ) ;
error -> V_111 = F_60 ( V_242 ) ;
F_111 ( V_49 , error -> V_119 ) ;
}
static void F_112 ( struct V_48 * V_49 ,
struct V_95 * error ,
bool V_243 ,
const char * V_99 )
{
struct V_92 * V_93 = V_49 -> V_94 ;
V_56 V_244 ;
int V_176 = - 1 , V_20 ;
V_244 = F_54 ( V_93 , error , & V_176 ) ;
V_20 = F_113 ( error -> V_99 , sizeof( error -> V_99 ) ,
L_86 , V_176 , V_244 ) ;
if ( V_176 != - 1 && error -> V_2 [ V_176 ] . V_103 != - 1 )
V_20 += F_113 ( error -> V_99 + V_20 ,
sizeof( error -> V_99 ) - V_20 ,
L_87 ,
error -> V_2 [ V_176 ] . V_104 ,
error -> V_2 [ V_176 ] . V_103 ) ;
F_113 ( error -> V_99 + V_20 , sizeof( error -> V_99 ) - V_20 ,
L_88 ,
V_99 ,
V_243 ? L_89 : L_90 ) ;
}
static void F_114 ( struct V_92 * V_93 ,
struct V_95 * error )
{
error -> V_105 = F_115 ( & V_93 -> V_115 ) ;
error -> V_106 = V_93 -> V_106 ;
}
void F_116 ( struct V_48 * V_49 , bool V_243 ,
const char * V_99 )
{
static bool V_245 ;
struct V_92 * V_93 = V_49 -> V_94 ;
struct V_95 * error ;
unsigned long V_152 ;
error = F_117 ( sizeof( * error ) , V_151 ) ;
if ( ! error ) {
F_118 ( L_91 ) ;
return;
}
F_119 ( & error -> V_143 ) ;
F_114 ( V_93 , error ) ;
F_103 ( V_93 , error ) ;
F_102 ( V_93 , error ) ;
F_55 ( V_49 , error ) ;
F_92 ( V_49 , error ) ;
F_120 ( & error -> time ) ;
error -> V_134 = F_121 ( V_49 ) ;
error -> V_135 = F_122 ( V_49 ) ;
F_112 ( V_49 , error , V_243 , V_99 ) ;
F_123 ( L_55 , error -> V_99 ) ;
F_124 ( & V_93 -> V_115 . V_246 , V_152 ) ;
if ( V_93 -> V_115 . V_247 == NULL ) {
V_93 -> V_115 . V_247 = error ;
error = NULL ;
}
F_125 ( & V_93 -> V_115 . V_246 , V_152 ) ;
if ( error ) {
F_33 ( & error -> V_143 ) ;
return;
}
if ( ! V_245 ) {
F_123 ( L_92 ) ;
F_123 ( L_93 ) ;
F_123 ( L_94 ) ;
F_123 ( L_95 ) ;
F_123 ( L_96 , V_49 -> V_248 -> V_249 ) ;
V_245 = true ;
}
}
void F_126 ( struct V_48 * V_49 ,
struct V_90 * V_91 )
{
struct V_92 * V_93 = V_49 -> V_94 ;
unsigned long V_152 ;
F_124 ( & V_93 -> V_115 . V_246 , V_152 ) ;
V_91 -> error = V_93 -> V_115 . V_247 ;
if ( V_91 -> error )
F_127 ( & V_91 -> error -> V_143 ) ;
F_125 ( & V_93 -> V_115 . V_246 , V_152 ) ;
}
void F_128 ( struct V_90 * V_91 )
{
if ( V_91 -> error )
F_129 ( & V_91 -> error -> V_143 , F_33 ) ;
}
void F_130 ( struct V_48 * V_49 )
{
struct V_92 * V_93 = V_49 -> V_94 ;
struct V_95 * error ;
unsigned long V_152 ;
F_124 ( & V_93 -> V_115 . V_246 , V_152 ) ;
error = V_93 -> V_115 . V_247 ;
V_93 -> V_115 . V_247 = NULL ;
F_125 ( & V_93 -> V_115 . V_246 , V_152 ) ;
if ( error )
F_129 ( & error -> V_143 , F_33 ) ;
}
const char * F_17 ( int type )
{
switch ( type ) {
case V_155 : return L_97 ;
case V_250 : return L_98 ;
case V_251 : return L_99 ;
case V_252 : return L_100 ;
default: return L_7 ;
}
}
void F_111 ( struct V_48 * V_49 , T_5 * V_60 )
{
struct V_92 * V_93 = V_49 -> V_94 ;
memset ( V_60 , 0 , sizeof( * V_60 ) * V_253 ) ;
switch ( F_20 ( V_49 ) -> V_61 ) {
case 2 :
case 3 :
V_60 [ 0 ] = F_60 ( V_191 ) ;
break;
case 4 :
case 5 :
case 6 :
V_60 [ 0 ] = F_60 ( V_254 ) ;
V_60 [ 1 ] = F_60 ( V_255 ) ;
break;
default:
F_131 ( 1 , L_101 ) ;
case 7 :
case 8 :
V_60 [ 0 ] = F_60 ( V_256 ) ;
V_60 [ 1 ] = F_60 ( V_257 ) ;
V_60 [ 2 ] = F_60 ( V_258 ) ;
V_60 [ 3 ] = F_60 ( V_259 ) ;
break;
}
}
