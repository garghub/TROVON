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
}
return L_28 ;
}
static void F_19 ( struct V_15 * V_30 ,
struct V_50 * V_51 ,
struct V_52 * V_2 )
{
if ( ! V_2 -> V_53 )
return;
F_15 ( V_30 , L_29 , V_2 -> V_54 ) ;
F_15 ( V_30 , L_30 , V_2 -> V_55 ) ;
F_15 ( V_30 , L_31 , V_2 -> V_56 ) ;
F_15 ( V_30 , L_32 , V_2 -> V_57 ) ;
F_15 ( V_30 , L_33 , ( V_58 ) ( V_2 -> V_59 >> 32 ) , ( V_58 ) V_2 -> V_59 ) ;
F_15 ( V_30 , L_34 , V_2 -> V_60 ) ;
F_15 ( V_30 , L_35 , V_2 -> V_61 ) ;
F_15 ( V_30 , L_36 , V_2 -> V_62 ) ;
if ( F_20 ( V_51 ) -> V_63 >= 4 ) {
F_15 ( V_30 , L_37 , ( V_58 ) ( V_2 -> V_64 >> 32 ) , ( V_58 ) V_2 -> V_64 ) ;
F_15 ( V_30 , L_38 , V_2 -> V_65 ) ;
F_15 ( V_30 , L_39 , V_2 -> V_66 ) ;
}
F_15 ( V_30 , L_40 , V_2 -> V_67 ) ;
F_15 ( V_30 , L_41 , F_21 ( V_2 -> V_68 ) ,
F_22 ( V_2 -> V_68 ) ) ;
if ( F_20 ( V_51 ) -> V_63 >= 6 ) {
F_15 ( V_30 , L_42 , V_2 -> V_69 ) ;
F_15 ( V_30 , L_43 , V_2 -> V_70 ) ;
F_15 ( V_30 , L_44 ,
V_2 -> V_71 [ 0 ] ,
V_2 -> V_72 [ 0 ] ) ;
F_15 ( V_30 , L_45 ,
V_2 -> V_71 [ 1 ] ,
V_2 -> V_72 [ 1 ] ) ;
if ( F_23 ( V_51 ) ) {
F_15 ( V_30 , L_46 ,
V_2 -> V_71 [ 2 ] ,
V_2 -> V_72 [ 2 ] ) ;
}
}
if ( F_24 ( V_51 ) ) {
F_15 ( V_30 , L_47 , V_2 -> V_73 . V_74 ) ;
if ( F_20 ( V_51 ) -> V_63 >= 8 ) {
int V_75 ;
for ( V_75 = 0 ; V_75 < 4 ; V_75 ++ )
F_15 ( V_30 , L_48 ,
V_75 , V_2 -> V_73 . V_76 [ V_75 ] ) ;
} else {
F_15 ( V_30 , L_49 ,
V_2 -> V_73 . V_77 ) ;
}
}
F_15 ( V_30 , L_50 , V_2 -> V_78 ) ;
F_15 ( V_30 , L_51 , F_1 ( V_2 -> V_79 ) ) ;
F_15 ( V_30 , L_52 , V_2 -> V_80 ) ;
F_15 ( V_30 , L_53 , V_2 -> V_81 ) ;
F_15 ( V_30 , L_54 ,
F_18 ( V_2 -> V_82 ) ,
V_2 -> V_83 ) ;
}
void F_25 ( struct V_15 * V_16 , const char * V_27 , ... )
{
T_2 args ;
va_start ( args , V_27 ) ;
F_11 ( V_16 , V_27 , args ) ;
va_end ( args ) ;
}
static void F_26 ( struct V_15 * V_30 ,
struct V_84 * V_85 )
{
int V_86 , V_87 , V_88 ;
for ( V_86 = V_87 = 0 ; V_86 < V_85 -> V_89 ; V_86 ++ ) {
for ( V_88 = 0 ; V_88 < V_90 / 4 ; V_88 ++ ) {
F_15 ( V_30 , L_55 , V_87 ,
V_85 -> V_91 [ V_86 ] [ V_88 ] ) ;
V_87 += 4 ;
}
}
}
int F_27 ( struct V_15 * V_30 ,
const struct V_92 * V_93 )
{
struct V_50 * V_51 = V_93 -> V_51 ;
struct V_94 * V_95 = V_51 -> V_96 ;
struct V_97 * error = V_93 -> error ;
int V_75 , V_98 , V_87 , V_88 ;
int V_99 ;
if ( ! error ) {
F_15 ( V_30 , L_56 ) ;
goto V_100;
}
F_15 ( V_30 , L_57 , error -> V_101 ) ;
F_15 ( V_30 , L_58 , error -> time . V_102 ,
error -> time . V_103 ) ;
F_15 ( V_30 , L_59 V_104 L_22 ) ;
V_99 = 0 ;
for ( V_75 = 0 ; V_75 < F_28 ( error -> V_2 ) ; V_75 ++ ) {
if ( error -> V_2 [ V_75 ] . V_83 > V_99 )
V_99 = error -> V_2 [ V_75 ] . V_83 ;
}
for ( V_75 = 0 ; V_75 < F_28 ( error -> V_2 ) ; V_75 ++ ) {
if ( error -> V_2 [ V_75 ] . V_83 == V_99 &&
error -> V_2 [ V_75 ] . V_105 != - 1 ) {
F_15 ( V_30 , L_60 ,
F_2 ( V_75 ) ,
error -> V_2 [ V_75 ] . V_106 ,
error -> V_2 [ V_75 ] . V_105 ) ;
}
}
F_15 ( V_30 , L_61 , error -> V_107 ) ;
F_15 ( V_30 , L_62 , error -> V_108 ) ;
F_15 ( V_30 , L_63 , V_51 -> V_109 -> V_110 ) ;
F_15 ( V_30 , L_64 , error -> V_111 ) ;
F_15 ( V_30 , L_65 , error -> V_112 ) ;
F_15 ( V_30 , L_66 , error -> V_113 ) ;
F_15 ( V_30 , L_67 , error -> V_114 ) ;
F_15 ( V_30 , L_68 , error -> V_115 ) ;
F_15 ( V_30 , L_69 , error -> V_116 ) ;
F_15 ( V_30 , L_70 , V_95 -> V_117 . V_118 ) ;
for ( V_75 = 0 ; V_75 < V_95 -> V_119 ; V_75 ++ )
F_15 ( V_30 , L_71 , V_75 , error -> V_120 [ V_75 ] ) ;
for ( V_75 = 0 ; V_75 < F_28 ( error -> V_121 ) ; V_75 ++ )
F_15 ( V_30 , L_72 , V_75 ,
error -> V_121 [ V_75 ] ) ;
if ( F_20 ( V_51 ) -> V_63 >= 6 ) {
F_15 ( V_30 , L_73 , error -> error ) ;
F_15 ( V_30 , L_74 , error -> V_122 ) ;
}
if ( F_20 ( V_51 ) -> V_63 == 7 )
F_15 ( V_30 , L_75 , error -> V_123 ) ;
for ( V_75 = 0 ; V_75 < F_28 ( error -> V_2 ) ; V_75 ++ ) {
F_15 ( V_30 , L_76 , F_2 ( V_75 ) ) ;
F_19 ( V_30 , V_51 , & error -> V_2 [ V_75 ] ) ;
}
if ( error -> V_124 )
F_14 ( V_30 , L_77 ,
error -> V_124 [ 0 ] ,
error -> V_125 [ 0 ] ) ;
if ( error -> V_126 )
F_14 ( V_30 , L_78 ,
error -> V_126 [ 0 ] ,
error -> V_127 [ 0 ] ) ;
for ( V_75 = 0 ; V_75 < F_28 ( error -> V_2 ) ; V_75 ++ ) {
struct V_84 * V_85 ;
V_85 = error -> V_2 [ V_75 ] . V_128 ;
if ( V_85 ) {
F_16 ( V_30 , V_95 -> V_2 [ V_75 ] . V_31 ) ;
if ( error -> V_2 [ V_75 ] . V_105 != - 1 )
F_15 ( V_30 , L_79 ,
error -> V_2 [ V_75 ] . V_106 ,
error -> V_2 [ V_75 ] . V_105 ) ;
F_15 ( V_30 , L_80 ,
V_85 -> V_34 ) ;
F_26 ( V_30 , V_85 ) ;
}
V_85 = error -> V_2 [ V_75 ] . V_129 ;
if ( V_85 ) {
F_15 ( V_30 , L_81 ,
V_95 -> V_2 [ V_75 ] . V_31 , V_85 -> V_34 ) ;
F_26 ( V_30 , V_85 ) ;
}
if ( error -> V_2 [ V_75 ] . V_130 ) {
F_15 ( V_30 , L_82 ,
V_95 -> V_2 [ V_75 ] . V_31 ,
error -> V_2 [ V_75 ] . V_130 ) ;
for ( V_98 = 0 ; V_98 < error -> V_2 [ V_75 ] . V_130 ; V_98 ++ ) {
F_15 ( V_30 , L_83 ,
error -> V_2 [ V_75 ] . V_131 [ V_98 ] . V_78 ,
error -> V_2 [ V_75 ] . V_131 [ V_98 ] . V_132 ,
error -> V_2 [ V_75 ] . V_131 [ V_98 ] . V_55 ) ;
}
}
if ( ( V_85 = error -> V_2 [ V_75 ] . V_133 ) ) {
F_15 ( V_30 , L_84 ,
V_95 -> V_2 [ V_75 ] . V_31 ,
V_85 -> V_34 ) ;
F_26 ( V_30 , V_85 ) ;
}
if ( ( V_85 = error -> V_2 [ V_75 ] . V_134 ) ) {
F_15 ( V_30 , L_85 ,
V_95 -> V_2 [ V_75 ] . V_31 ,
V_85 -> V_34 ) ;
V_87 = 0 ;
for ( V_88 = 0 ; V_88 < V_90 / 16 ; V_88 += 4 ) {
F_15 ( V_30 , L_86 ,
V_87 ,
V_85 -> V_91 [ 0 ] [ V_88 ] ,
V_85 -> V_91 [ 0 ] [ V_88 + 1 ] ,
V_85 -> V_91 [ 0 ] [ V_88 + 2 ] ,
V_85 -> V_91 [ 0 ] [ V_88 + 3 ] ) ;
V_87 += 16 ;
}
}
if ( ( V_85 = error -> V_2 [ V_75 ] . V_135 ) ) {
F_15 ( V_30 , L_87 ,
V_95 -> V_2 [ V_75 ] . V_31 ,
V_85 -> V_34 ) ;
F_26 ( V_30 , V_85 ) ;
}
}
if ( error -> V_136 )
F_29 ( V_30 , error -> V_136 ) ;
if ( error -> V_137 )
F_30 ( V_30 , V_51 , error -> V_137 ) ;
V_100:
if ( V_30 -> V_18 == 0 && V_30 -> V_17 )
return V_30 -> V_17 ;
return 0 ;
}
int F_31 ( struct V_15 * V_138 ,
T_1 V_33 , T_3 V_22 )
{
memset ( V_138 , 0 , sizeof( * V_138 ) ) ;
V_138 -> V_19 = V_33 + 1 > V_90 ? V_33 + 1 : V_90 ;
V_138 -> V_26 = F_32 ( V_138 -> V_19 ,
V_139 | V_140 | V_141 ) ;
if ( V_138 -> V_26 == NULL ) {
V_138 -> V_19 = V_90 ;
V_138 -> V_26 = F_32 ( V_138 -> V_19 , V_139 ) ;
}
if ( V_138 -> V_26 == NULL ) {
V_138 -> V_19 = 128 ;
V_138 -> V_26 = F_32 ( V_138 -> V_19 , V_139 ) ;
}
if ( V_138 -> V_26 == NULL )
return - V_142 ;
V_138 -> V_23 = V_22 ;
return 0 ;
}
static void F_33 ( struct V_84 * V_85 )
{
int V_86 ;
if ( V_85 == NULL )
return;
for ( V_86 = 0 ; V_86 < V_85 -> V_89 ; V_86 ++ )
F_34 ( V_85 -> V_91 [ V_86 ] ) ;
F_34 ( V_85 ) ;
}
static void F_35 ( struct V_143 * V_144 )
{
struct V_97 * error = F_36 ( V_144 ,
F_37 ( * error ) , V_145 ) ;
int V_75 ;
for ( V_75 = 0 ; V_75 < F_28 ( error -> V_2 ) ; V_75 ++ ) {
F_33 ( error -> V_2 [ V_75 ] . V_128 ) ;
F_33 ( error -> V_2 [ V_75 ] . V_133 ) ;
F_33 ( error -> V_2 [ V_75 ] . V_134 ) ;
F_33 ( error -> V_2 [ V_75 ] . V_135 ) ;
F_34 ( error -> V_2 [ V_75 ] . V_131 ) ;
}
F_34 ( error -> V_124 ) ;
F_34 ( error -> V_136 ) ;
F_34 ( error -> V_137 ) ;
F_34 ( error ) ;
}
static struct V_84 *
F_38 ( struct V_94 * V_95 ,
struct V_146 * V_147 ,
struct V_148 * V_149 ,
const int V_150 )
{
struct V_84 * V_151 ;
int V_75 ;
V_58 V_152 ;
if ( V_147 == NULL || V_147 -> V_91 == NULL )
return NULL ;
V_151 = F_32 ( sizeof( * V_151 ) + V_150 * sizeof( V_58 * ) , V_153 ) ;
if ( V_151 == NULL )
return NULL ;
V_152 = V_151 -> V_34 = F_39 ( V_147 , V_149 ) ;
for ( V_75 = 0 ; V_75 < V_150 ; V_75 ++ ) {
unsigned long V_154 ;
void * V_155 ;
V_155 = F_32 ( V_90 , V_153 ) ;
if ( V_155 == NULL )
goto V_156;
F_40 ( V_154 ) ;
if ( V_147 -> V_40 == V_157 &&
V_152 < V_95 -> V_158 . V_159 &&
V_147 -> V_160 &&
F_41 ( V_149 ) ) {
void T_4 * V_161 ;
V_161 = F_42 ( V_95 -> V_158 . V_162 ,
V_152 ) ;
F_43 ( V_155 , V_161 , V_90 ) ;
F_44 ( V_161 ) ;
} else if ( V_147 -> V_163 ) {
unsigned long V_87 ;
V_87 = V_95 -> V_164 . V_165 ;
V_87 += V_147 -> V_163 -> V_23 ;
V_87 += V_75 << V_166 ;
F_43 ( V_155 , ( void T_4 * ) V_87 , V_90 ) ;
} else {
struct V_86 * V_86 ;
void * V_161 ;
V_86 = F_45 ( V_147 , V_75 ) ;
F_46 ( & V_86 , 1 ) ;
V_161 = F_47 ( V_86 ) ;
memcpy ( V_155 , V_161 , V_90 ) ;
F_48 ( V_161 ) ;
F_46 ( & V_86 , 1 ) ;
}
F_49 ( V_154 ) ;
V_151 -> V_91 [ V_75 ] = V_155 ;
V_152 += V_90 ;
}
V_151 -> V_89 = V_150 ;
return V_151 ;
V_156:
while ( V_75 -- )
F_34 ( V_151 -> V_91 [ V_75 ] ) ;
F_34 ( V_151 ) ;
return NULL ;
}
static void F_50 ( struct V_32 * V_17 ,
struct V_146 * V_85 )
{
V_17 -> V_19 = V_85 -> V_167 . V_19 ;
V_17 -> V_31 = V_85 -> V_167 . V_31 ;
V_17 -> V_37 = V_85 -> V_168 ;
V_17 -> V_38 = V_85 -> V_169 ;
V_17 -> V_34 = F_51 ( V_85 ) ;
V_17 -> V_35 = V_85 -> V_167 . V_35 ;
V_17 -> V_36 = V_85 -> V_167 . V_36 ;
V_17 -> V_41 = V_85 -> V_41 ;
V_17 -> V_8 = 0 ;
if ( F_52 ( V_85 ) )
V_17 -> V_8 = 1 ;
if ( V_85 -> V_170 > 0 )
V_17 -> V_8 = - 1 ;
V_17 -> V_9 = V_85 -> V_171 ;
V_17 -> V_13 = V_85 -> V_13 ;
V_17 -> V_14 = V_85 -> V_172 != V_173 ;
V_17 -> V_39 = V_85 -> V_39 . V_164 != NULL ;
V_17 -> V_2 = V_85 -> V_2 ? V_85 -> V_2 -> V_174 : - 1 ;
V_17 -> V_40 = V_85 -> V_40 ;
}
static V_58 F_53 ( struct V_32 * V_17 ,
int V_33 , struct V_175 * V_54 )
{
struct V_176 * V_177 ;
int V_75 = 0 ;
F_54 (vma, head, mm_list) {
F_50 ( V_17 ++ , V_177 -> V_85 ) ;
if ( ++ V_75 == V_33 )
break;
}
return V_75 ;
}
static V_58 F_55 ( struct V_32 * V_17 ,
int V_33 , struct V_175 * V_54 )
{
struct V_146 * V_85 ;
int V_75 = 0 ;
F_54 (obj, head, global_list) {
if ( ! F_52 ( V_85 ) )
continue;
F_50 ( V_17 ++ , V_85 ) ;
if ( ++ V_75 == V_33 )
break;
}
return V_75 ;
}
static T_5 F_56 ( struct V_94 * V_95 ,
struct V_97 * error ,
int * V_178 )
{
T_5 V_179 = 0 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_180 ; V_75 ++ ) {
if ( error -> V_2 [ V_75 ] . V_82 == V_49 ) {
if ( V_178 )
* V_178 = V_75 ;
return error -> V_2 [ V_75 ] . V_61 ^ error -> V_2 [ V_75 ] . V_62 ;
}
}
return V_179 ;
}
static void F_57 ( struct V_50 * V_51 ,
struct V_97 * error )
{
struct V_94 * V_95 = V_51 -> V_96 ;
int V_75 ;
switch ( F_20 ( V_51 ) -> V_63 ) {
case 8 :
case 7 :
case 6 :
for ( V_75 = 0 ; V_75 < V_95 -> V_119 ; V_75 ++ )
error -> V_120 [ V_75 ] = F_58 ( V_181 + ( V_75 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_75 = 0 ; V_75 < 16 ; V_75 ++ )
error -> V_120 [ V_75 ] = F_58 ( V_182 + ( V_75 * 8 ) ) ;
break;
case 3 :
if ( F_59 ( V_51 ) || F_60 ( V_51 ) || F_61 ( V_51 ) )
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ )
error -> V_120 [ V_75 + 8 ] = F_62 ( V_183 + ( V_75 * 4 ) ) ;
case 2 :
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ )
error -> V_120 [ V_75 ] = F_62 ( V_184 + ( V_75 * 4 ) ) ;
break;
default:
F_63 () ;
}
}
static void F_64 ( struct V_50 * V_51 ,
struct V_185 * V_2 ,
struct V_52 * V_186 )
{
struct V_94 * V_95 = V_51 -> V_96 ;
if ( F_20 ( V_51 ) -> V_63 >= 6 ) {
V_186 -> V_69 = F_62 ( V_2 -> V_187 + 0x50 ) ;
V_186 -> V_70 = F_62 ( F_65 ( V_2 ) ) ;
V_186 -> V_71 [ 0 ]
= F_62 ( F_66 ( V_2 -> V_187 ) ) ;
V_186 -> V_71 [ 1 ]
= F_62 ( F_67 ( V_2 -> V_187 ) ) ;
V_186 -> V_72 [ 0 ] = V_2 -> V_188 . V_189 [ 0 ] ;
V_186 -> V_72 [ 1 ] = V_2 -> V_188 . V_189 [ 1 ] ;
}
if ( F_23 ( V_51 ) ) {
V_186 -> V_71 [ 2 ] =
F_62 ( F_68 ( V_2 -> V_187 ) ) ;
V_186 -> V_72 [ 2 ] = V_2 -> V_188 . V_189 [ 2 ] ;
}
if ( F_20 ( V_51 ) -> V_63 >= 4 ) {
V_186 -> V_68 = F_62 ( F_69 ( V_2 -> V_187 ) ) ;
V_186 -> V_60 = F_62 ( F_70 ( V_2 -> V_187 ) ) ;
V_186 -> V_61 = F_62 ( F_71 ( V_2 -> V_187 ) ) ;
V_186 -> V_62 = F_62 ( F_72 ( V_2 -> V_187 ) ) ;
V_186 -> V_66 = F_62 ( F_73 ( V_2 -> V_187 ) ) ;
V_186 -> V_64 = F_62 ( F_74 ( V_2 -> V_187 ) ) ;
if ( F_20 ( V_51 ) -> V_63 >= 8 ) {
V_186 -> V_68 |= ( V_190 ) F_62 ( F_75 ( V_2 -> V_187 ) ) << 32 ;
V_186 -> V_64 |= ( V_190 ) F_62 ( F_76 ( V_2 -> V_187 ) ) << 32 ;
}
V_186 -> V_65 = F_62 ( F_77 ( V_2 -> V_187 ) ) ;
} else {
V_186 -> V_68 = F_62 ( V_191 ) ;
V_186 -> V_60 = F_62 ( V_192 ) ;
V_186 -> V_61 = F_62 ( V_193 ) ;
V_186 -> V_62 = F_62 ( V_194 ) ;
}
V_186 -> V_79 = F_78 ( & V_2 -> V_195 ) ;
V_186 -> V_67 = F_62 ( F_79 ( V_2 -> V_187 ) ) ;
V_186 -> V_78 = V_2 -> V_196 ( V_2 , false ) ;
V_186 -> V_59 = F_80 ( V_2 ) ;
V_186 -> V_54 = F_81 ( V_2 ) ;
V_186 -> V_55 = F_82 ( V_2 ) ;
V_186 -> V_56 = F_83 ( V_2 ) ;
if ( F_84 ( V_51 ) ) {
int V_197 ;
if ( F_85 ( V_51 ) ) {
switch ( V_2 -> V_174 ) {
default:
case V_3 :
V_197 = V_198 ;
break;
case V_5 :
V_197 = V_199 ;
break;
case V_4 :
V_197 = V_200 ;
break;
case V_6 :
V_197 = V_201 ;
break;
}
} else if ( F_86 ( V_2 -> V_51 ) ) {
V_197 = F_87 ( V_2 -> V_187 ) ;
} else {
V_197 = F_88 ( V_2 -> V_187 ) ;
}
V_186 -> V_57 = F_62 ( V_197 ) ;
}
V_186 -> V_80 = V_2 -> V_202 -> V_54 ;
V_186 -> V_81 = V_2 -> V_202 -> V_55 ;
V_186 -> V_83 = V_2 -> V_203 . V_204 ;
V_186 -> V_82 = V_2 -> V_203 . V_205 ;
if ( F_24 ( V_51 ) ) {
int V_75 ;
V_186 -> V_73 . V_74 = F_62 ( F_89 ( V_2 ) ) ;
switch ( F_20 ( V_51 ) -> V_63 ) {
case 8 :
for ( V_75 = 0 ; V_75 < 4 ; V_75 ++ ) {
V_186 -> V_73 . V_76 [ V_75 ] =
F_62 ( F_90 ( V_2 , V_75 ) ) ;
V_186 -> V_73 . V_76 [ V_75 ] <<= 32 ;
V_186 -> V_73 . V_76 [ V_75 ] |=
F_62 ( F_91 ( V_2 , V_75 ) ) ;
}
break;
case 7 :
V_186 -> V_73 . V_77 =
F_62 ( F_92 ( V_2 ) ) ;
break;
case 6 :
V_186 -> V_73 . V_77 =
F_62 ( F_93 ( V_2 ) ) ;
break;
}
}
}
static void F_94 ( struct V_185 * V_2 ,
struct V_97 * error ,
struct V_52 * V_186 )
{
struct V_94 * V_95 = V_2 -> V_51 -> V_96 ;
struct V_146 * V_85 ;
if ( V_2 -> V_174 != V_3 || ! error -> V_116 )
return;
F_54 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ( error -> V_116 & V_206 ) == F_51 ( V_85 ) ) {
V_186 -> V_135 = F_95 ( V_95 , V_85 ) ;
break;
}
}
}
static void F_96 ( struct V_50 * V_51 ,
struct V_97 * error )
{
struct V_94 * V_95 = V_51 -> V_96 ;
struct V_207 * V_208 ;
int V_75 , V_33 ;
for ( V_75 = 0 ; V_75 < V_180 ; V_75 ++ ) {
struct V_185 * V_2 = & V_95 -> V_2 [ V_75 ] ;
error -> V_2 [ V_75 ] . V_105 = - 1 ;
if ( V_2 -> V_51 == NULL )
continue;
error -> V_2 [ V_75 ] . V_53 = true ;
F_64 ( V_51 , V_2 , & error -> V_2 [ V_75 ] ) ;
V_208 = F_97 ( V_2 ) ;
if ( V_208 ) {
error -> V_2 [ V_75 ] . V_128 =
F_98 ( V_95 ,
V_208 -> V_209 ,
V_208 -> V_135 ?
V_208 -> V_135 -> V_149 :
& V_95 -> V_158 . V_167 ) ;
if ( F_99 ( V_95 -> V_51 ) &&
V_2 -> V_210 . V_85 )
error -> V_2 [ V_75 ] . V_129 =
F_95 ( V_95 ,
V_2 -> V_210 . V_85 ) ;
if ( V_208 -> V_211 ) {
struct V_212 * V_213 ;
F_100 () ;
V_213 = F_101 ( V_208 -> V_211 -> V_214 -> V_105 ,
V_215 ) ;
if ( V_213 ) {
strcpy ( error -> V_2 [ V_75 ] . V_106 , V_213 -> V_106 ) ;
error -> V_2 [ V_75 ] . V_105 = V_213 -> V_105 ;
}
F_102 () ;
}
}
error -> V_2 [ V_75 ] . V_133 =
F_95 ( V_95 , V_2 -> V_202 -> V_85 ) ;
if ( V_2 -> V_216 . V_85 )
error -> V_2 [ V_75 ] . V_134 =
F_95 ( V_95 , V_2 -> V_216 . V_85 ) ;
F_94 ( V_2 , error , & error -> V_2 [ V_75 ] ) ;
V_33 = 0 ;
F_54 (request, &ring->request_list, list)
V_33 ++ ;
error -> V_2 [ V_75 ] . V_130 = V_33 ;
error -> V_2 [ V_75 ] . V_131 =
F_103 ( V_33 , sizeof( * error -> V_2 [ V_75 ] . V_131 ) ,
V_153 ) ;
if ( error -> V_2 [ V_75 ] . V_131 == NULL ) {
error -> V_2 [ V_75 ] . V_130 = 0 ;
continue;
}
V_33 = 0 ;
F_54 (request, &ring->request_list, list) {
struct V_217 * V_218 ;
V_218 = & error -> V_2 [ V_75 ] . V_131 [ V_33 ++ ] ;
V_218 -> V_78 = V_208 -> V_78 ;
V_218 -> V_132 = V_208 -> V_219 ;
V_218 -> V_55 = V_208 -> V_55 ;
}
}
}
static void F_104 ( struct V_94 * V_95 ,
struct V_97 * error ,
struct V_148 * V_149 ,
const int V_220 )
{
struct V_32 * V_124 = NULL , * V_126 = NULL ;
struct V_146 * V_85 ;
struct V_176 * V_177 ;
int V_75 ;
V_75 = 0 ;
F_54 (vma, &vm->active_list, mm_list)
V_75 ++ ;
error -> V_125 [ V_220 ] = V_75 ;
F_54 (obj, &dev_priv->mm.bound_list, global_list)
if ( F_52 ( V_85 ) )
V_75 ++ ;
error -> V_127 [ V_220 ] = V_75 - error -> V_125 [ V_220 ] ;
if ( V_75 ) {
V_124 = F_103 ( V_75 , sizeof( * V_124 ) , V_153 ) ;
if ( V_124 )
V_126 = V_124 + error -> V_125 [ V_220 ] ;
}
if ( V_124 )
error -> V_125 [ V_220 ] =
F_53 ( V_124 ,
error -> V_125 [ V_220 ] ,
& V_149 -> V_221 ) ;
if ( V_126 )
error -> V_127 [ V_220 ] =
F_55 ( V_126 ,
error -> V_127 [ V_220 ] ,
& V_95 -> V_164 . V_222 ) ;
error -> V_124 [ V_220 ] = V_124 ;
error -> V_126 [ V_220 ] = V_126 ;
}
static void F_105 ( struct V_94 * V_95 ,
struct V_97 * error )
{
struct V_148 * V_149 ;
int V_223 = 0 , V_75 = 0 ;
F_54 (vm, &dev_priv->vm_list, global_link)
V_223 ++ ;
error -> V_124 = F_103 ( V_223 , sizeof( * error -> V_124 ) , V_153 ) ;
error -> V_126 = F_103 ( V_223 , sizeof( * error -> V_126 ) , V_153 ) ;
error -> V_125 = F_103 ( V_223 , sizeof( * error -> V_125 ) ,
V_153 ) ;
error -> V_127 = F_103 ( V_223 , sizeof( * error -> V_127 ) ,
V_153 ) ;
F_54 (vm, &dev_priv->vm_list, global_link)
F_104 ( V_95 , error , V_149 , V_75 ++ ) ;
}
static void F_106 ( struct V_94 * V_95 ,
struct V_97 * error )
{
struct V_50 * V_51 = V_95 -> V_51 ;
if ( F_107 ( V_51 ) ) {
error -> V_112 = F_62 ( V_224 ) | F_62 ( V_225 ) ;
error -> V_114 = F_62 ( V_226 ) ;
}
if ( F_85 ( V_51 ) )
error -> V_123 = F_62 ( V_227 ) ;
if ( F_86 ( V_51 ) ) {
error -> V_114 = F_62 ( V_228 ) ;
error -> V_229 = F_62 ( V_230 ) ;
error -> V_74 = F_62 ( V_231 ) ;
}
if ( F_20 ( V_51 ) -> V_63 >= 7 )
error -> V_114 = F_62 ( V_232 ) ;
if ( F_20 ( V_51 ) -> V_63 >= 6 ) {
error -> V_115 = F_62 ( V_233 ) ;
error -> error = F_62 ( V_234 ) ;
error -> V_122 = F_62 ( V_235 ) ;
}
if ( F_86 ( V_51 ) || F_85 ( V_51 ) ) {
error -> V_236 = F_62 ( V_237 ) ;
error -> V_238 = F_62 ( V_239 ) ;
}
if ( F_108 ( V_51 ) )
error -> V_116 = F_62 ( V_240 ) ;
if ( F_109 ( V_51 ) )
error -> V_112 = F_62 ( V_241 ) | F_62 ( V_224 ) ;
else {
if ( F_110 ( V_51 ) )
error -> V_112 = F_111 ( V_242 ) ;
else
error -> V_112 = F_62 ( V_242 ) ;
}
error -> V_111 = F_62 ( V_243 ) ;
error -> V_113 = F_62 ( V_244 ) ;
F_112 ( V_51 , error -> V_121 ) ;
}
static void F_113 ( struct V_50 * V_51 ,
struct V_97 * error ,
bool V_245 ,
const char * V_101 )
{
struct V_94 * V_95 = V_51 -> V_96 ;
V_58 V_246 ;
int V_178 = - 1 , V_21 ;
V_246 = F_56 ( V_95 , error , & V_178 ) ;
V_21 = F_114 ( error -> V_101 , sizeof( error -> V_101 ) ,
L_88 , V_178 , V_246 ) ;
if ( V_178 != - 1 && error -> V_2 [ V_178 ] . V_105 != - 1 )
V_21 += F_114 ( error -> V_101 + V_21 ,
sizeof( error -> V_101 ) - V_21 ,
L_89 ,
error -> V_2 [ V_178 ] . V_106 ,
error -> V_2 [ V_178 ] . V_105 ) ;
F_114 ( error -> V_101 + V_21 , sizeof( error -> V_101 ) - V_21 ,
L_90 ,
V_101 ,
V_245 ? L_91 : L_92 ) ;
}
static void F_115 ( struct V_94 * V_95 ,
struct V_97 * error )
{
error -> V_107 = F_116 ( & V_95 -> V_117 ) ;
error -> V_108 = V_95 -> V_108 ;
}
void F_117 ( struct V_50 * V_51 , bool V_245 ,
const char * V_101 )
{
static bool V_247 ;
struct V_94 * V_95 = V_51 -> V_96 ;
struct V_97 * error ;
unsigned long V_154 ;
error = F_118 ( sizeof( * error ) , V_153 ) ;
if ( ! error ) {
F_119 ( L_93 ) ;
return;
}
F_120 ( & error -> V_145 ) ;
F_115 ( V_95 , error ) ;
F_106 ( V_95 , error ) ;
F_105 ( V_95 , error ) ;
F_57 ( V_51 , error ) ;
F_96 ( V_51 , error ) ;
F_121 ( & error -> time ) ;
error -> V_136 = F_122 ( V_51 ) ;
error -> V_137 = F_123 ( V_51 ) ;
F_113 ( V_51 , error , V_245 , V_101 ) ;
F_124 ( L_57 , error -> V_101 ) ;
F_125 ( & V_95 -> V_117 . V_248 , V_154 ) ;
if ( V_95 -> V_117 . V_249 == NULL ) {
V_95 -> V_117 . V_249 = error ;
error = NULL ;
}
F_126 ( & V_95 -> V_117 . V_248 , V_154 ) ;
if ( error ) {
F_35 ( & error -> V_145 ) ;
return;
}
if ( ! V_247 ) {
F_124 ( L_94 ) ;
F_124 ( L_95 ) ;
F_124 ( L_96 ) ;
F_124 ( L_97 ) ;
F_124 ( L_98 , V_51 -> V_250 -> V_251 ) ;
V_247 = true ;
}
}
void F_127 ( struct V_50 * V_51 ,
struct V_92 * V_93 )
{
struct V_94 * V_95 = V_51 -> V_96 ;
unsigned long V_154 ;
F_125 ( & V_95 -> V_117 . V_248 , V_154 ) ;
V_93 -> error = V_95 -> V_117 . V_249 ;
if ( V_93 -> error )
F_128 ( & V_93 -> error -> V_145 ) ;
F_126 ( & V_95 -> V_117 . V_248 , V_154 ) ;
}
void F_129 ( struct V_92 * V_93 )
{
if ( V_93 -> error )
F_130 ( & V_93 -> error -> V_145 , F_35 ) ;
}
void F_131 ( struct V_50 * V_51 )
{
struct V_94 * V_95 = V_51 -> V_96 ;
struct V_97 * error ;
unsigned long V_154 ;
F_125 ( & V_95 -> V_117 . V_248 , V_154 ) ;
error = V_95 -> V_117 . V_249 ;
V_95 -> V_117 . V_249 = NULL ;
F_126 ( & V_95 -> V_117 . V_248 , V_154 ) ;
if ( error )
F_130 ( & error -> V_145 , F_35 ) ;
}
const char * F_17 ( int type )
{
switch ( type ) {
case V_157 : return L_99 ;
case V_252 : return L_100 ;
case V_253 : return L_101 ;
case V_254 : return L_102 ;
default: return L_8 ;
}
}
void F_112 ( struct V_50 * V_51 , T_5 * V_62 )
{
struct V_94 * V_95 = V_51 -> V_96 ;
memset ( V_62 , 0 , sizeof( * V_62 ) * V_255 ) ;
switch ( F_20 ( V_51 ) -> V_63 ) {
case 2 :
case 3 :
V_62 [ 0 ] = F_62 ( V_194 ) ;
break;
case 4 :
case 5 :
case 6 :
V_62 [ 0 ] = F_62 ( V_256 ) ;
V_62 [ 1 ] = F_62 ( V_257 ) ;
break;
default:
F_132 ( 1 , L_103 ) ;
case 7 :
case 8 :
V_62 [ 0 ] = F_62 ( V_258 ) ;
V_62 [ 1 ] = F_62 ( V_259 ) ;
V_62 [ 2 ] = F_62 ( V_260 ) ;
V_62 [ 3 ] = F_62 ( V_261 ) ;
break;
}
}
