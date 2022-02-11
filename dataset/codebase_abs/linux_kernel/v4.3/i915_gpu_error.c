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
F_15 ( V_30 , L_71 , error -> V_117 ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 ) {
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ )
F_15 ( V_30 , L_72 , V_34 ,
error -> V_118 [ V_34 ] ) ;
} else if ( F_29 ( V_55 ) || F_30 ( V_55 ) )
F_15 ( V_30 , L_73 , error -> V_118 [ 0 ] ) ;
F_15 ( V_30 , L_74 , error -> V_119 ) ;
F_15 ( V_30 , L_75 , error -> V_120 ) ;
F_15 ( V_30 , L_76 , error -> V_121 ) ;
F_15 ( V_30 , L_77 , error -> V_122 ) ;
F_15 ( V_30 , L_78 , V_100 -> V_123 . V_124 ) ;
for ( V_34 = 0 ; V_34 < V_100 -> V_125 ; V_34 ++ )
F_15 ( V_30 , L_79 , V_34 , error -> V_126 [ V_34 ] ) ;
for ( V_34 = 0 ; V_34 < F_28 ( error -> V_127 ) ; V_34 ++ )
F_15 ( V_30 , L_80 , V_34 ,
error -> V_127 [ V_34 ] ) ;
if ( F_20 ( V_55 ) -> V_69 >= 6 ) {
F_15 ( V_30 , L_81 , error -> error ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 )
F_15 ( V_30 , L_82 ,
error -> V_128 , error -> V_129 ) ;
F_15 ( V_30 , L_83 , error -> V_130 ) ;
}
if ( F_20 ( V_55 ) -> V_69 == 7 )
F_15 ( V_30 , L_84 , error -> V_131 ) ;
for ( V_34 = 0 ; V_34 < F_28 ( error -> V_2 ) ; V_34 ++ )
F_19 ( V_30 , V_55 , error , V_34 ) ;
for ( V_34 = 0 ; V_34 < error -> V_132 ; V_34 ++ ) {
F_15 ( V_30 , L_85 , V_34 ) ;
F_14 ( V_30 , L_86 ,
error -> V_133 [ V_34 ] ,
error -> V_134 [ V_34 ] ) ;
F_14 ( V_30 , L_87 ,
error -> V_135 [ V_34 ] ,
error -> V_136 [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_28 ( error -> V_2 ) ; V_34 ++ ) {
V_90 = error -> V_2 [ V_34 ] . V_137 ;
if ( V_90 ) {
F_16 ( V_30 , V_100 -> V_2 [ V_34 ] . V_31 ) ;
if ( error -> V_2 [ V_34 ] . V_109 != - 1 )
F_15 ( V_30 , L_88 ,
error -> V_2 [ V_34 ] . V_110 ,
error -> V_2 [ V_34 ] . V_109 ) ;
F_15 ( V_30 , L_89 ,
V_90 -> V_35 ) ;
F_26 ( V_30 , V_90 ) ;
}
V_90 = error -> V_2 [ V_34 ] . V_138 ;
if ( V_90 ) {
F_15 ( V_30 , L_90 ,
V_100 -> V_2 [ V_34 ] . V_31 , V_90 -> V_35 ) ;
F_26 ( V_30 , V_90 ) ;
}
if ( error -> V_2 [ V_34 ] . V_139 ) {
F_15 ( V_30 , L_91 ,
V_100 -> V_2 [ V_34 ] . V_31 ,
error -> V_2 [ V_34 ] . V_139 ) ;
for ( V_102 = 0 ; V_102 < error -> V_2 [ V_34 ] . V_139 ; V_102 ++ ) {
F_15 ( V_30 , L_92 ,
error -> V_2 [ V_34 ] . V_140 [ V_102 ] . V_83 ,
error -> V_2 [ V_34 ] . V_140 [ V_102 ] . V_141 ,
error -> V_2 [ V_34 ] . V_140 [ V_102 ] . V_61 ) ;
}
}
if ( ( V_90 = error -> V_2 [ V_34 ] . V_142 ) ) {
F_15 ( V_30 , L_93 ,
V_100 -> V_2 [ V_34 ] . V_31 ,
V_90 -> V_35 ) ;
F_26 ( V_30 , V_90 ) ;
}
if ( ( V_90 = error -> V_2 [ V_34 ] . V_143 ) ) {
F_15 ( V_30 , L_94 ,
V_100 -> V_2 [ V_34 ] . V_31 ,
V_90 -> V_35 ) ;
V_92 = 0 ;
for ( V_93 = 0 ; V_93 < V_95 / 16 ; V_93 += 4 ) {
F_15 ( V_30 , L_95 ,
V_92 ,
V_90 -> V_96 [ 0 ] [ V_93 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 1 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 2 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 3 ] ) ;
V_92 += 16 ;
}
}
if ( ( V_90 = error -> V_2 [ V_34 ] . V_144 ) ) {
F_15 ( V_30 , L_96 ,
V_100 -> V_2 [ V_34 ] . V_31 ,
V_90 -> V_35 ) ;
F_26 ( V_30 , V_90 ) ;
}
}
if ( ( V_90 = error -> V_145 ) ) {
F_15 ( V_30 , L_97 , V_90 -> V_35 ) ;
for ( V_93 = 0 ; V_93 < V_95 / 16 ; V_93 += 4 ) {
F_15 ( V_30 , L_95 ,
V_93 * 4 ,
V_90 -> V_96 [ 0 ] [ V_93 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 1 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 2 ] ,
V_90 -> V_96 [ 0 ] [ V_93 + 3 ] ) ;
}
}
if ( error -> V_146 )
F_31 ( V_30 , error -> V_146 ) ;
if ( error -> V_147 )
F_32 ( V_30 , V_55 , error -> V_147 ) ;
V_104:
if ( V_30 -> V_18 == 0 && V_30 -> V_17 )
return V_30 -> V_17 ;
return 0 ;
}
int F_33 ( struct V_15 * V_148 ,
struct V_99 * V_42 ,
T_1 V_33 , T_3 V_22 )
{
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
V_148 -> V_42 = V_42 ;
V_148 -> V_19 = V_33 + 1 > V_95 ? V_33 + 1 : V_95 ;
V_148 -> V_26 = F_34 ( V_148 -> V_19 ,
V_149 | V_150 | V_151 ) ;
if ( V_148 -> V_26 == NULL ) {
V_148 -> V_19 = V_95 ;
V_148 -> V_26 = F_34 ( V_148 -> V_19 , V_149 ) ;
}
if ( V_148 -> V_26 == NULL ) {
V_148 -> V_19 = 128 ;
V_148 -> V_26 = F_34 ( V_148 -> V_19 , V_149 ) ;
}
if ( V_148 -> V_26 == NULL )
return - V_152 ;
V_148 -> V_23 = V_22 ;
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
static void F_37 ( struct V_153 * V_154 )
{
struct V_56 * error = F_38 ( V_154 ,
F_39 ( * error ) , V_155 ) ;
int V_34 ;
for ( V_34 = 0 ; V_34 < F_28 ( error -> V_2 ) ; V_34 ++ ) {
F_35 ( error -> V_2 [ V_34 ] . V_137 ) ;
F_35 ( error -> V_2 [ V_34 ] . V_138 ) ;
F_35 ( error -> V_2 [ V_34 ] . V_142 ) ;
F_35 ( error -> V_2 [ V_34 ] . V_143 ) ;
F_35 ( error -> V_2 [ V_34 ] . V_144 ) ;
F_36 ( error -> V_2 [ V_34 ] . V_140 ) ;
}
F_35 ( error -> V_145 ) ;
for ( V_34 = 0 ; V_34 < error -> V_132 ; V_34 ++ )
F_36 ( error -> V_133 [ V_34 ] ) ;
F_36 ( error -> V_133 ) ;
F_36 ( error -> V_134 ) ;
F_36 ( error -> V_135 ) ;
F_36 ( error -> V_136 ) ;
F_36 ( error -> V_146 ) ;
F_36 ( error -> V_147 ) ;
F_36 ( error ) ;
}
static struct V_89 *
F_40 ( struct V_99 * V_100 ,
struct V_156 * V_157 ,
struct V_158 * V_159 )
{
struct V_89 * V_160 ;
struct V_161 * V_162 = NULL ;
int V_163 ;
bool V_164 ;
int V_34 = 0 ;
V_64 V_165 ;
if ( V_157 == NULL || V_157 -> V_96 == NULL )
return NULL ;
V_163 = V_157 -> V_166 . V_19 >> V_167 ;
V_160 = F_34 ( sizeof( * V_160 ) + V_163 * sizeof( V_64 * ) , V_168 ) ;
if ( V_160 == NULL )
return NULL ;
if ( F_41 ( V_157 , V_159 ) )
V_160 -> V_35 = F_42 ( V_157 , V_159 ) ;
else
V_160 -> V_35 = - 1 ;
V_165 = V_160 -> V_35 ;
if ( F_43 ( V_159 ) )
V_162 = F_44 ( V_157 ) ;
V_164 = ( V_157 -> V_43 == V_169 &&
V_162 && ( V_162 -> V_170 & V_171 ) &&
V_165 + V_163 * V_95 <= V_100 -> V_172 . V_173 ) ;
if ( V_157 -> V_174 ) {
V_164 = true ;
if ( ! ( V_162 && V_162 -> V_170 & V_171 ) )
goto V_175;
V_165 = F_45 ( V_157 ) ;
if ( V_165 + V_163 * V_95 > V_100 -> V_172 . V_173 )
goto V_175;
}
if ( V_164 && V_157 -> V_43 != V_169 && ! F_46 ( V_100 -> V_55 ) )
goto V_175;
V_160 -> V_94 = V_163 ;
while ( V_163 -- ) {
unsigned long V_176 ;
void * V_177 ;
V_177 = F_34 ( V_95 , V_168 ) ;
if ( V_177 == NULL )
goto V_175;
F_47 ( V_176 ) ;
if ( V_164 ) {
void T_4 * V_178 ;
V_178 = F_48 ( V_100 -> V_172 . V_179 ,
V_165 ) ;
F_49 ( V_177 , V_178 , V_95 ) ;
F_50 ( V_178 ) ;
} else {
struct V_91 * V_91 ;
void * V_178 ;
V_91 = F_51 ( V_157 , V_34 ) ;
F_52 ( & V_91 , 1 ) ;
V_178 = F_53 ( V_91 ) ;
memcpy ( V_177 , V_178 , V_95 ) ;
F_54 ( V_178 ) ;
F_52 ( & V_91 , 1 ) ;
}
F_55 ( V_176 ) ;
V_160 -> V_96 [ V_34 ++ ] = V_177 ;
V_165 += V_95 ;
}
return V_160 ;
V_175:
while ( V_34 -- )
F_36 ( V_160 -> V_96 [ V_34 ] ) ;
F_36 ( V_160 ) ;
return NULL ;
}
static void F_56 ( struct V_32 * V_17 ,
struct V_161 * V_162 )
{
struct V_156 * V_90 = V_162 -> V_90 ;
int V_34 ;
V_17 -> V_19 = V_90 -> V_166 . V_19 ;
V_17 -> V_31 = V_90 -> V_166 . V_31 ;
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ )
V_17 -> V_39 [ V_34 ] = F_57 ( V_90 -> V_180 [ V_34 ] ) ;
V_17 -> V_40 = F_57 ( V_90 -> V_181 ) ;
V_17 -> V_35 = V_162 -> V_182 . V_23 ;
V_17 -> V_36 = V_90 -> V_166 . V_36 ;
V_17 -> V_37 = V_90 -> V_166 . V_37 ;
V_17 -> V_44 = V_90 -> V_44 ;
V_17 -> V_8 = 0 ;
if ( F_58 ( V_90 ) )
V_17 -> V_8 = 1 ;
V_17 -> V_9 = V_90 -> V_183 ;
V_17 -> V_13 = V_90 -> V_13 ;
V_17 -> V_14 = V_90 -> V_184 != V_185 ;
V_17 -> V_41 = V_90 -> V_41 . V_186 != NULL ;
V_17 -> V_2 = V_90 -> V_181 ?
F_59 ( V_90 -> V_181 ) -> V_187 : - 1 ;
V_17 -> V_43 = V_90 -> V_43 ;
}
static V_64 F_60 ( struct V_32 * V_17 ,
int V_33 , struct V_188 * V_60 )
{
struct V_161 * V_162 ;
int V_34 = 0 ;
F_61 (vma, head, mm_list) {
F_56 ( V_17 ++ , V_162 ) ;
if ( ++ V_34 == V_33 )
break;
}
return V_34 ;
}
static V_64 F_62 ( struct V_32 * V_17 ,
int V_33 , struct V_188 * V_60 ,
struct V_158 * V_159 )
{
struct V_156 * V_90 ;
struct V_32 * const V_189 = V_17 ;
struct V_32 * const V_190 = V_17 + V_33 ;
F_61 (obj, head, global_list) {
struct V_161 * V_162 ;
if ( V_17 == V_190 )
break;
F_61 (vma, &obj->vma_list, vma_link)
if ( V_162 -> V_159 == V_159 && V_162 -> V_191 > 0 )
F_56 ( V_17 ++ , V_162 ) ;
}
return V_17 - V_189 ;
}
static T_5 F_63 ( struct V_99 * V_100 ,
struct V_56 * error ,
int * V_192 )
{
T_5 V_193 = 0 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ ) {
if ( error -> V_2 [ V_34 ] . V_87 == V_53 ) {
if ( V_192 )
* V_192 = V_34 ;
return error -> V_2 [ V_34 ] . V_67 ^ error -> V_2 [ V_34 ] . V_68 ;
}
}
return V_193 ;
}
static void F_64 ( struct V_54 * V_55 ,
struct V_56 * error )
{
struct V_99 * V_100 = V_55 -> V_101 ;
int V_34 ;
if ( F_65 ( V_55 ) || F_66 ( V_55 ) ) {
for ( V_34 = 0 ; V_34 < 8 ; V_34 ++ )
error -> V_126 [ V_34 ] = F_67 ( V_194 + ( V_34 * 4 ) ) ;
if ( F_68 ( V_55 ) || F_69 ( V_55 ) || F_70 ( V_55 ) )
for ( V_34 = 0 ; V_34 < 8 ; V_34 ++ )
error -> V_126 [ V_34 + 8 ] = F_67 ( V_195 +
( V_34 * 4 ) ) ;
} else if ( F_71 ( V_55 ) || F_72 ( V_55 ) )
for ( V_34 = 0 ; V_34 < 16 ; V_34 ++ )
error -> V_126 [ V_34 ] = F_73 ( V_196 +
( V_34 * 8 ) ) ;
else if ( F_20 ( V_55 ) -> V_69 >= 6 )
for ( V_34 = 0 ; V_34 < V_100 -> V_125 ; V_34 ++ )
error -> V_126 [ V_34 ] = F_73 ( V_197 +
( V_34 * 8 ) ) ;
}
static void F_74 ( struct V_99 * V_100 ,
struct V_56 * error ,
struct V_198 * V_2 ,
struct V_58 * V_199 )
{
struct V_198 * V_200 ;
int V_34 ;
if ( ! F_75 ( V_100 -> V_55 ) )
return;
if ( ! error -> V_145 )
error -> V_145 =
F_76 ( V_100 ,
V_100 -> V_145 ) ;
F_77 (to, dev_priv, i) {
int V_201 ;
T_6 V_202 ;
V_64 * V_28 ;
if ( V_2 == V_200 )
continue;
V_202 = ( F_78 ( V_2 , V_34 ) & ( V_95 - 1 ) )
/ 4 ;
V_28 = error -> V_145 -> V_96 [ 0 ] ;
V_201 = F_79 ( V_2 , V_200 ) ;
V_199 -> V_77 [ V_201 ] = V_28 [ V_202 ] ;
V_199 -> V_78 [ V_201 ] = V_2 -> V_203 . V_204 [ V_201 ] ;
}
}
static void F_80 ( struct V_99 * V_100 ,
struct V_198 * V_2 ,
struct V_58 * V_199 )
{
V_199 -> V_77 [ 0 ] = F_67 ( F_81 ( V_2 -> V_205 ) ) ;
V_199 -> V_77 [ 1 ] = F_67 ( F_82 ( V_2 -> V_205 ) ) ;
V_199 -> V_78 [ 0 ] = V_2 -> V_203 . V_204 [ 0 ] ;
V_199 -> V_78 [ 1 ] = V_2 -> V_203 . V_204 [ 1 ] ;
if ( F_23 ( V_100 -> V_55 ) ) {
V_199 -> V_77 [ 2 ] =
F_67 ( F_83 ( V_2 -> V_205 ) ) ;
V_199 -> V_78 [ 2 ] = V_2 -> V_203 . V_204 [ 2 ] ;
}
}
static void F_84 ( struct V_54 * V_55 ,
struct V_56 * error ,
struct V_198 * V_2 ,
struct V_58 * V_199 )
{
struct V_99 * V_100 = V_55 -> V_101 ;
if ( F_20 ( V_55 ) -> V_69 >= 6 ) {
V_199 -> V_75 = F_67 ( V_2 -> V_205 + 0x50 ) ;
V_199 -> V_76 = F_67 ( F_85 ( V_2 ) ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 )
F_74 ( V_100 , error , V_2 , V_199 ) ;
else
F_80 ( V_100 , V_2 , V_199 ) ;
}
if ( F_20 ( V_55 ) -> V_69 >= 4 ) {
V_199 -> V_74 = F_67 ( F_86 ( V_2 -> V_205 ) ) ;
V_199 -> V_66 = F_67 ( F_87 ( V_2 -> V_205 ) ) ;
V_199 -> V_67 = F_67 ( F_88 ( V_2 -> V_205 ) ) ;
V_199 -> V_68 = F_67 ( F_89 ( V_2 -> V_205 ) ) ;
V_199 -> V_72 = F_67 ( F_90 ( V_2 -> V_205 ) ) ;
V_199 -> V_70 = F_67 ( F_91 ( V_2 -> V_205 ) ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 ) {
V_199 -> V_74 |= ( V_206 ) F_67 ( F_92 ( V_2 -> V_205 ) ) << 32 ;
V_199 -> V_70 |= ( V_206 ) F_67 ( F_93 ( V_2 -> V_205 ) ) << 32 ;
}
V_199 -> V_71 = F_67 ( F_94 ( V_2 -> V_205 ) ) ;
} else {
V_199 -> V_74 = F_67 ( V_207 ) ;
V_199 -> V_66 = F_67 ( V_208 ) ;
V_199 -> V_67 = F_67 ( V_209 ) ;
V_199 -> V_68 = F_67 ( V_210 ) ;
}
V_199 -> V_84 = F_95 ( & V_2 -> V_211 ) ;
V_199 -> V_73 = F_67 ( F_96 ( V_2 -> V_205 ) ) ;
V_199 -> V_83 = V_2 -> V_212 ( V_2 , false ) ;
V_199 -> V_65 = F_97 ( V_2 ) ;
V_199 -> V_23 = F_98 ( V_2 ) ;
V_199 -> V_60 = F_99 ( V_2 ) ;
V_199 -> V_61 = F_100 ( V_2 ) ;
V_199 -> V_62 = F_101 ( V_2 ) ;
if ( F_102 ( V_55 ) ) {
int V_213 ;
if ( F_103 ( V_55 ) ) {
switch ( V_2 -> V_187 ) {
default:
case V_3 :
V_213 = V_214 ;
break;
case V_5 :
V_213 = V_215 ;
break;
case V_4 :
V_213 = V_216 ;
break;
case V_6 :
V_213 = V_217 ;
break;
}
} else if ( F_104 ( V_2 -> V_55 ) ) {
V_213 = F_105 ( V_2 -> V_205 ) ;
} else {
V_213 = F_106 ( V_2 -> V_205 ) ;
}
V_199 -> V_63 = F_67 ( V_213 ) ;
}
V_199 -> V_88 = V_2 -> V_218 . V_219 ;
V_199 -> V_87 = V_2 -> V_218 . V_220 ;
if ( F_24 ( V_55 ) ) {
int V_34 ;
V_199 -> V_79 . V_80 = F_67 ( F_107 ( V_2 ) ) ;
if ( F_104 ( V_55 ) )
V_199 -> V_79 . V_82 =
F_67 ( F_108 ( V_2 ) ) ;
else if ( F_103 ( V_55 ) )
V_199 -> V_79 . V_82 =
F_67 ( F_109 ( V_2 ) ) ;
else if ( F_20 ( V_55 ) -> V_69 >= 8 )
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_199 -> V_79 . V_81 [ V_34 ] =
F_67 ( F_110 ( V_2 , V_34 ) ) ;
V_199 -> V_79 . V_81 [ V_34 ] <<= 32 ;
V_199 -> V_79 . V_81 [ V_34 ] |=
F_67 ( F_111 ( V_2 , V_34 ) ) ;
}
}
}
static void F_112 ( struct V_198 * V_2 ,
struct V_56 * error ,
struct V_58 * V_199 )
{
struct V_99 * V_100 = V_2 -> V_55 -> V_101 ;
struct V_156 * V_90 ;
if ( V_2 -> V_187 != V_3 || ! error -> V_122 )
return;
F_61 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ! F_113 ( V_90 ) )
continue;
if ( ( error -> V_122 & V_221 ) == F_45 ( V_90 ) ) {
V_199 -> V_144 = F_76 ( V_100 , V_90 ) ;
break;
}
}
}
static void F_114 ( struct V_54 * V_55 ,
struct V_56 * error )
{
struct V_99 * V_100 = V_55 -> V_101 ;
struct V_222 * V_223 ;
int V_34 , V_33 ;
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ ) {
struct V_198 * V_2 = & V_100 -> V_2 [ V_34 ] ;
struct V_224 * V_225 ;
error -> V_2 [ V_34 ] . V_109 = - 1 ;
if ( V_2 -> V_55 == NULL )
continue;
error -> V_2 [ V_34 ] . V_59 = true ;
F_84 ( V_55 , error , V_2 , & error -> V_2 [ V_34 ] ) ;
V_223 = F_115 ( V_2 ) ;
if ( V_223 ) {
struct V_158 * V_159 ;
V_159 = V_223 -> V_144 && V_223 -> V_144 -> V_226 ?
& V_223 -> V_144 -> V_226 -> V_166 :
& V_100 -> V_172 . V_166 ;
error -> V_2 [ V_34 ] . V_137 =
F_40 ( V_100 ,
V_223 -> V_227 ,
V_159 ) ;
if ( F_116 ( V_100 -> V_55 ) )
error -> V_2 [ V_34 ] . V_138 =
F_76 ( V_100 ,
V_2 -> V_228 . V_90 ) ;
if ( V_223 -> V_109 ) {
struct V_229 * V_230 ;
F_117 () ;
V_230 = F_118 ( V_223 -> V_109 , V_231 ) ;
if ( V_230 ) {
strcpy ( error -> V_2 [ V_34 ] . V_110 , V_230 -> V_110 ) ;
error -> V_2 [ V_34 ] . V_109 = V_230 -> V_109 ;
}
F_119 () ;
}
}
if ( V_42 . V_232 ) {
if ( V_223 )
V_225 = V_223 -> V_144 -> V_233 [ V_2 -> V_187 ] . V_234 ;
else
V_225 = V_2 -> V_235 -> V_233 [ V_2 -> V_187 ] . V_234 ;
} else
V_225 = V_2 -> V_236 ;
error -> V_2 [ V_34 ] . V_85 = V_225 -> V_60 ;
error -> V_2 [ V_34 ] . V_86 = V_225 -> V_61 ;
error -> V_2 [ V_34 ] . V_142 =
F_76 ( V_100 , V_225 -> V_90 ) ;
error -> V_2 [ V_34 ] . V_143 =
F_76 ( V_100 , V_2 -> V_237 . V_90 ) ;
F_112 ( V_2 , error , & error -> V_2 [ V_34 ] ) ;
V_33 = 0 ;
F_61 (request, &ring->request_list, list)
V_33 ++ ;
error -> V_2 [ V_34 ] . V_139 = V_33 ;
error -> V_2 [ V_34 ] . V_140 =
F_120 ( V_33 , sizeof( * error -> V_2 [ V_34 ] . V_140 ) ,
V_168 ) ;
if ( error -> V_2 [ V_34 ] . V_140 == NULL ) {
error -> V_2 [ V_34 ] . V_139 = 0 ;
continue;
}
V_33 = 0 ;
F_61 (request, &ring->request_list, list) {
struct V_238 * V_239 ;
V_239 = & error -> V_2 [ V_34 ] . V_140 [ V_33 ++ ] ;
V_239 -> V_83 = V_223 -> V_83 ;
V_239 -> V_141 = V_223 -> V_240 ;
V_239 -> V_61 = V_223 -> V_241 ;
}
}
}
static void F_121 ( struct V_99 * V_100 ,
struct V_56 * error ,
struct V_158 * V_159 ,
const int V_242 )
{
struct V_32 * V_133 = NULL , * V_135 = NULL ;
struct V_156 * V_90 ;
struct V_161 * V_162 ;
int V_34 ;
V_34 = 0 ;
F_61 (vma, &vm->active_list, mm_list)
V_34 ++ ;
error -> V_134 [ V_242 ] = V_34 ;
F_61 (obj, &dev_priv->mm.bound_list, global_list) {
F_61 (vma, &obj->vma_list, vma_link)
if ( V_162 -> V_159 == V_159 && V_162 -> V_191 > 0 )
V_34 ++ ;
}
error -> V_136 [ V_242 ] = V_34 - error -> V_134 [ V_242 ] ;
if ( V_34 ) {
V_133 = F_120 ( V_34 , sizeof( * V_133 ) , V_168 ) ;
if ( V_133 )
V_135 = V_133 + error -> V_134 [ V_242 ] ;
}
if ( V_133 )
error -> V_134 [ V_242 ] =
F_60 ( V_133 ,
error -> V_134 [ V_242 ] ,
& V_159 -> V_243 ) ;
if ( V_135 )
error -> V_136 [ V_242 ] =
F_62 ( V_135 ,
error -> V_136 [ V_242 ] ,
& V_100 -> V_186 . V_244 , V_159 ) ;
error -> V_133 [ V_242 ] = V_133 ;
error -> V_135 [ V_242 ] = V_135 ;
}
static void F_122 ( struct V_99 * V_100 ,
struct V_56 * error )
{
struct V_158 * V_159 ;
int V_245 = 0 , V_34 = 0 ;
F_61 (vm, &dev_priv->vm_list, global_link)
V_245 ++ ;
error -> V_133 = F_120 ( V_245 , sizeof( * error -> V_133 ) , V_168 ) ;
error -> V_135 = F_120 ( V_245 , sizeof( * error -> V_135 ) , V_168 ) ;
error -> V_134 = F_120 ( V_245 , sizeof( * error -> V_134 ) ,
V_168 ) ;
error -> V_136 = F_120 ( V_245 , sizeof( * error -> V_136 ) ,
V_168 ) ;
if ( error -> V_133 == NULL ||
error -> V_135 == NULL ||
error -> V_134 == NULL ||
error -> V_136 == NULL ) {
F_36 ( error -> V_133 ) ;
F_36 ( error -> V_134 ) ;
F_36 ( error -> V_135 ) ;
F_36 ( error -> V_136 ) ;
error -> V_133 = NULL ;
error -> V_134 = NULL ;
error -> V_135 = NULL ;
error -> V_136 = NULL ;
} else {
F_61 (vm, &dev_priv->vm_list, global_link)
F_121 ( V_100 , error , V_159 , V_34 ++ ) ;
error -> V_132 = V_245 ;
}
}
static void F_123 ( struct V_99 * V_100 ,
struct V_56 * error )
{
struct V_54 * V_55 = V_100 -> V_55 ;
int V_34 ;
if ( F_30 ( V_55 ) ) {
error -> V_118 [ 0 ] = F_67 ( V_246 ) ;
error -> V_117 = F_67 ( V_247 ) ;
error -> V_120 = F_67 ( V_248 ) ;
}
if ( F_103 ( V_55 ) )
error -> V_131 = F_67 ( V_249 ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 ) {
error -> V_129 = F_67 ( V_250 ) ;
error -> V_128 = F_67 ( V_251 ) ;
}
if ( F_104 ( V_55 ) ) {
error -> V_120 = F_67 ( V_252 ) ;
error -> V_253 = F_67 ( V_254 ) ;
error -> V_80 = F_67 ( V_255 ) ;
}
if ( F_20 ( V_55 ) -> V_69 >= 7 )
error -> V_120 = F_67 ( V_256 ) ;
if ( F_20 ( V_55 ) -> V_69 >= 6 ) {
error -> V_121 = F_67 ( V_257 ) ;
error -> error = F_67 ( V_258 ) ;
error -> V_130 = F_67 ( V_259 ) ;
}
if ( F_104 ( V_55 ) || F_103 ( V_55 ) ) {
error -> V_260 = F_67 ( V_261 ) ;
error -> V_262 = F_67 ( V_263 ) ;
}
if ( F_124 ( V_55 ) )
error -> V_122 = F_67 ( V_264 ) ;
if ( F_20 ( V_55 ) -> V_69 >= 8 ) {
error -> V_117 = F_67 ( V_265 ) ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ )
error -> V_118 [ V_34 ] = F_67 ( F_125 ( V_34 ) ) ;
} else if ( F_29 ( V_55 ) ) {
error -> V_117 = F_67 ( V_266 ) ;
error -> V_118 [ 0 ] = F_67 ( V_246 ) ;
} else if ( F_66 ( V_55 ) ) {
error -> V_117 = F_126 ( V_267 ) ;
} else if ( ! F_30 ( V_55 ) ) {
error -> V_117 = F_67 ( V_267 ) ;
}
error -> V_116 = F_67 ( V_268 ) ;
error -> V_119 = F_67 ( V_269 ) ;
F_127 ( V_55 , error -> V_127 ) ;
}
static void F_128 ( struct V_54 * V_55 ,
struct V_56 * error ,
bool V_270 ,
const char * V_105 )
{
struct V_99 * V_100 = V_55 -> V_101 ;
V_64 V_271 ;
int V_192 = - 1 , V_21 ;
V_271 = F_63 ( V_100 , error , & V_192 ) ;
V_21 = F_129 ( error -> V_105 , sizeof( error -> V_105 ) ,
L_98 ,
F_20 ( V_55 ) -> V_69 , V_192 , V_271 ) ;
if ( V_192 != - 1 && error -> V_2 [ V_192 ] . V_109 != - 1 )
V_21 += F_129 ( error -> V_105 + V_21 ,
sizeof( error -> V_105 ) - V_21 ,
L_99 ,
error -> V_2 [ V_192 ] . V_110 ,
error -> V_2 [ V_192 ] . V_109 ) ;
F_129 ( error -> V_105 + V_21 , sizeof( error -> V_105 ) - V_21 ,
L_100 ,
V_105 ,
V_270 ? L_101 : L_102 ) ;
}
static void F_130 ( struct V_99 * V_100 ,
struct V_56 * error )
{
error -> V_115 = - 1 ;
#ifdef F_131
error -> V_115 = V_272 ;
#endif
error -> V_111 = F_132 ( & V_100 -> V_123 ) ;
error -> V_112 = V_100 -> V_112 ;
}
void F_133 ( struct V_54 * V_55 , bool V_270 ,
const char * V_105 )
{
static bool V_273 ;
struct V_99 * V_100 = V_55 -> V_101 ;
struct V_56 * error ;
unsigned long V_176 ;
error = F_134 ( sizeof( * error ) , V_168 ) ;
if ( ! error ) {
F_135 ( L_103 ) ;
return;
}
F_136 ( & error -> V_155 ) ;
F_130 ( V_100 , error ) ;
F_123 ( V_100 , error ) ;
F_122 ( V_100 , error ) ;
F_64 ( V_55 , error ) ;
F_114 ( V_55 , error ) ;
F_137 ( & error -> time ) ;
error -> V_146 = F_138 ( V_55 ) ;
error -> V_147 = F_139 ( V_55 ) ;
F_128 ( V_55 , error , V_270 , V_105 ) ;
F_140 ( L_62 , error -> V_105 ) ;
F_141 ( & V_100 -> V_123 . V_274 , V_176 ) ;
if ( V_100 -> V_123 . V_275 == NULL ) {
V_100 -> V_123 . V_275 = error ;
error = NULL ;
}
F_142 ( & V_100 -> V_123 . V_274 , V_176 ) ;
if ( error ) {
F_37 ( & error -> V_155 ) ;
return;
}
if ( ! V_273 ) {
F_140 ( L_104 ) ;
F_140 ( L_105 ) ;
F_140 ( L_106 ) ;
F_140 ( L_107 ) ;
F_140 ( L_108 , V_55 -> V_276 -> V_277 ) ;
V_273 = true ;
}
}
void F_143 ( struct V_54 * V_55 ,
struct V_97 * V_98 )
{
struct V_99 * V_100 = V_55 -> V_101 ;
F_144 ( & V_100 -> V_123 . V_274 ) ;
V_98 -> error = V_100 -> V_123 . V_275 ;
if ( V_98 -> error )
F_145 ( & V_98 -> error -> V_155 ) ;
F_146 ( & V_100 -> V_123 . V_274 ) ;
}
void F_147 ( struct V_97 * V_98 )
{
if ( V_98 -> error )
F_148 ( & V_98 -> error -> V_155 , F_37 ) ;
}
void F_149 ( struct V_54 * V_55 )
{
struct V_99 * V_100 = V_55 -> V_101 ;
struct V_56 * error ;
F_144 ( & V_100 -> V_123 . V_274 ) ;
error = V_100 -> V_123 . V_275 ;
V_100 -> V_123 . V_275 = NULL ;
F_146 ( & V_100 -> V_123 . V_274 ) ;
if ( error )
F_148 ( & error -> V_155 , F_37 ) ;
}
const char * F_17 ( struct V_99 * V_42 , int type )
{
switch ( type ) {
case V_169 : return L_109 ;
case V_278 : return F_46 ( V_42 ) ? L_110 : L_111 ;
case V_279 : return L_112 ;
case V_280 : return L_113 ;
default: return L_8 ;
}
}
void F_127 ( struct V_54 * V_55 , T_5 * V_68 )
{
struct V_99 * V_100 = V_55 -> V_101 ;
memset ( V_68 , 0 , sizeof( * V_68 ) * V_281 ) ;
if ( F_66 ( V_55 ) || F_65 ( V_55 ) )
V_68 [ 0 ] = F_67 ( V_210 ) ;
else if ( F_72 ( V_55 ) || F_71 ( V_55 ) || F_104 ( V_55 ) ) {
V_68 [ 0 ] = F_67 ( V_282 ) ;
V_68 [ 1 ] = F_67 ( V_283 ) ;
} else if ( F_20 ( V_55 ) -> V_69 >= 7 ) {
V_68 [ 0 ] = F_67 ( V_284 ) ;
V_68 [ 1 ] = F_67 ( V_285 ) ;
V_68 [ 2 ] = F_67 ( V_286 ) ;
V_68 [ 3 ] = F_67 ( V_287 ) ;
}
}
