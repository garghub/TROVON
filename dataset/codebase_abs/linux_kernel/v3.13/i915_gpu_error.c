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
if ( ! F_9 ( V_15 , vsnprintf ( NULL , 0 , V_26 , V_27 ) ) )
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
struct V_50 * error ,
unsigned V_2 )
{
F_20 ( V_2 >= V_51 ) ;
F_15 ( V_29 , L_27 , F_2 ( V_2 ) ) ;
F_15 ( V_29 , L_28 , error -> V_52 [ V_2 ] ) ;
F_15 ( V_29 , L_29 , error -> V_53 [ V_2 ] ) ;
F_15 ( V_29 , L_30 , error -> V_54 [ V_2 ] ) ;
F_15 ( V_29 , L_31 , error -> V_55 [ V_2 ] ) ;
F_15 ( V_29 , L_32 , error -> V_56 [ V_2 ] ) ;
F_15 ( V_29 , L_33 , error -> V_57 [ V_2 ] ) ;
F_15 ( V_29 , L_34 , error -> V_58 [ V_2 ] ) ;
if ( V_2 == V_3 && F_21 ( V_49 ) -> V_59 >= 4 )
F_15 ( V_29 , L_35 , error -> V_60 ) ;
if ( F_21 ( V_49 ) -> V_59 >= 4 )
F_15 ( V_29 , L_36 , error -> V_61 [ V_2 ] ) ;
if ( F_21 ( V_49 ) -> V_59 >= 4 )
F_15 ( V_29 , L_37 , error -> V_62 [ V_2 ] ) ;
F_15 ( V_29 , L_38 , error -> V_63 [ V_2 ] ) ;
F_15 ( V_29 , L_39 , error -> V_64 [ V_2 ] ) ;
if ( F_21 ( V_49 ) -> V_59 >= 6 ) {
F_15 ( V_29 , L_40 , error -> V_65 [ V_2 ] ) ;
F_15 ( V_29 , L_41 , error -> V_66 [ V_2 ] ) ;
F_15 ( V_29 , L_42 ,
error -> V_67 [ V_2 ] [ 0 ] ,
error -> V_68 [ V_2 ] [ 0 ] ) ;
F_15 ( V_29 , L_43 ,
error -> V_67 [ V_2 ] [ 1 ] ,
error -> V_68 [ V_2 ] [ 1 ] ) ;
if ( F_22 ( V_49 ) ) {
F_15 ( V_29 , L_44 ,
error -> V_67 [ V_2 ] [ 2 ] ,
error -> V_68 [ V_2 ] [ 2 ] ) ;
}
}
F_15 ( V_29 , L_45 , error -> V_69 [ V_2 ] ) ;
F_15 ( V_29 , L_46 , F_1 ( error -> V_70 [ V_2 ] ) ) ;
F_15 ( V_29 , L_47 , error -> V_71 [ V_2 ] ) ;
F_15 ( V_29 , L_48 , error -> V_72 [ V_2 ] ) ;
F_15 ( V_29 , L_49 ,
F_18 ( error -> V_73 [ V_2 ] ) ,
error -> V_74 [ V_2 ] ) ;
}
void F_23 ( struct V_14 * V_15 , const char * V_26 , ... )
{
T_2 args ;
va_start ( args , V_26 ) ;
F_11 ( V_15 , V_26 , args ) ;
va_end ( args ) ;
}
int F_24 ( struct V_14 * V_29 ,
const struct V_75 * V_76 )
{
struct V_48 * V_49 = V_76 -> V_49 ;
T_3 * V_77 = V_49 -> V_78 ;
struct V_50 * error = V_76 -> error ;
struct V_79 * V_2 ;
int V_80 , V_81 , V_82 , V_83 , V_84 ;
if ( ! error ) {
F_15 ( V_29 , L_50 ) ;
goto V_85;
}
F_15 ( V_29 , L_51 , error -> time . V_86 ,
error -> time . V_87 ) ;
F_15 ( V_29 , L_52 V_88 L_20 ) ;
F_15 ( V_29 , L_53 , V_49 -> V_89 -> V_90 ) ;
F_15 ( V_29 , L_54 , error -> V_91 ) ;
F_15 ( V_29 , L_55 , error -> V_92 ) ;
F_15 ( V_29 , L_56 , error -> V_93 ) ;
F_15 ( V_29 , L_57 , error -> V_94 ) ;
F_15 ( V_29 , L_58 , error -> V_95 ) ;
F_15 ( V_29 , L_59 , error -> V_96 ) ;
F_15 ( V_29 , L_60 , V_77 -> V_97 . V_98 ) ;
for ( V_80 = 0 ; V_80 < V_77 -> V_99 ; V_80 ++ )
F_15 ( V_29 , L_61 , V_80 , error -> V_100 [ V_80 ] ) ;
for ( V_80 = 0 ; V_80 < F_25 ( error -> V_101 ) ; V_80 ++ )
F_15 ( V_29 , L_62 , V_80 ,
error -> V_101 [ V_80 ] ) ;
if ( F_21 ( V_49 ) -> V_59 >= 6 ) {
F_15 ( V_29 , L_63 , error -> error ) ;
F_15 ( V_29 , L_64 , error -> V_102 ) ;
}
if ( F_21 ( V_49 ) -> V_59 == 7 )
F_15 ( V_29 , L_65 , error -> V_103 ) ;
F_26 (ring, dev_priv, i)
F_19 ( V_29 , V_49 , error , V_80 ) ;
if ( error -> V_104 )
F_14 ( V_29 , L_66 ,
error -> V_104 [ 0 ] ,
error -> V_105 [ 0 ] ) ;
if ( error -> V_106 )
F_14 ( V_29 , L_67 ,
error -> V_106 [ 0 ] ,
error -> V_107 [ 0 ] ) ;
for ( V_80 = 0 ; V_80 < F_25 ( error -> V_2 ) ; V_80 ++ ) {
struct V_108 * V_109 ;
if ( ( V_109 = error -> V_2 [ V_80 ] . V_110 ) ) {
F_15 ( V_29 , L_68 ,
V_77 -> V_2 [ V_80 ] . V_30 ,
V_109 -> V_33 ) ;
V_83 = 0 ;
for ( V_82 = 0 ; V_82 < V_109 -> V_111 ; V_82 ++ ) {
for ( V_84 = 0 ; V_84 < V_112 / 4 ; V_84 ++ ) {
F_15 ( V_29 , L_69 , V_83 ,
V_109 -> V_113 [ V_82 ] [ V_84 ] ) ;
V_83 += 4 ;
}
}
}
if ( error -> V_2 [ V_80 ] . V_114 ) {
F_15 ( V_29 , L_70 ,
V_77 -> V_2 [ V_80 ] . V_30 ,
error -> V_2 [ V_80 ] . V_114 ) ;
for ( V_81 = 0 ; V_81 < error -> V_2 [ V_80 ] . V_114 ; V_81 ++ ) {
F_15 ( V_29 , L_71 ,
error -> V_2 [ V_80 ] . V_115 [ V_81 ] . V_69 ,
error -> V_2 [ V_80 ] . V_115 [ V_81 ] . V_116 ,
error -> V_2 [ V_80 ] . V_115 [ V_81 ] . V_53 ) ;
}
}
if ( ( V_109 = error -> V_2 [ V_80 ] . V_117 ) ) {
F_15 ( V_29 , L_72 ,
V_77 -> V_2 [ V_80 ] . V_30 ,
V_109 -> V_33 ) ;
V_83 = 0 ;
for ( V_82 = 0 ; V_82 < V_109 -> V_111 ; V_82 ++ ) {
for ( V_84 = 0 ; V_84 < V_112 / 4 ; V_84 ++ ) {
F_15 ( V_29 , L_69 ,
V_83 ,
V_109 -> V_113 [ V_82 ] [ V_84 ] ) ;
V_83 += 4 ;
}
}
}
V_109 = error -> V_2 [ V_80 ] . V_118 ;
if ( V_109 ) {
F_15 ( V_29 , L_73 ,
V_77 -> V_2 [ V_80 ] . V_30 ,
V_109 -> V_33 ) ;
V_83 = 0 ;
for ( V_84 = 0 ; V_84 < V_112 / 16 ; V_84 += 4 ) {
F_15 ( V_29 , L_74 ,
V_83 ,
V_109 -> V_113 [ 0 ] [ V_84 ] ,
V_109 -> V_113 [ 0 ] [ V_84 + 1 ] ,
V_109 -> V_113 [ 0 ] [ V_84 + 2 ] ,
V_109 -> V_113 [ 0 ] [ V_84 + 3 ] ) ;
V_83 += 16 ;
}
}
}
if ( error -> V_119 )
F_27 ( V_29 , error -> V_119 ) ;
if ( error -> V_120 )
F_28 ( V_29 , V_49 , error -> V_120 ) ;
V_85:
if ( V_29 -> V_17 == 0 && V_29 -> V_16 )
return V_29 -> V_16 ;
return 0 ;
}
int F_29 ( struct V_14 * V_121 ,
T_1 V_32 , T_4 V_21 )
{
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
V_121 -> V_18 = V_32 + 1 > V_112 ? V_32 + 1 : V_112 ;
V_121 -> V_25 = F_30 ( V_121 -> V_18 ,
V_122 | V_123 | V_124 ) ;
if ( V_121 -> V_25 == NULL ) {
V_121 -> V_18 = V_112 ;
V_121 -> V_25 = F_30 ( V_121 -> V_18 , V_122 ) ;
}
if ( V_121 -> V_25 == NULL ) {
V_121 -> V_18 = 128 ;
V_121 -> V_25 = F_30 ( V_121 -> V_18 , V_122 ) ;
}
if ( V_121 -> V_25 == NULL )
return - V_125 ;
V_121 -> V_22 = V_21 ;
return 0 ;
}
static void F_31 ( struct V_108 * V_109 )
{
int V_82 ;
if ( V_109 == NULL )
return;
for ( V_82 = 0 ; V_82 < V_109 -> V_111 ; V_82 ++ )
F_32 ( V_109 -> V_113 [ V_82 ] ) ;
F_32 ( V_109 ) ;
}
static void F_33 ( struct V_126 * V_127 )
{
struct V_50 * error = F_34 ( V_127 ,
F_35 ( * error ) , V_128 ) ;
int V_80 ;
for ( V_80 = 0 ; V_80 < F_25 ( error -> V_2 ) ; V_80 ++ ) {
F_31 ( error -> V_2 [ V_80 ] . V_110 ) ;
F_31 ( error -> V_2 [ V_80 ] . V_117 ) ;
F_31 ( error -> V_2 [ V_80 ] . V_118 ) ;
F_32 ( error -> V_2 [ V_80 ] . V_115 ) ;
}
F_32 ( error -> V_104 ) ;
F_32 ( error -> V_119 ) ;
F_32 ( error -> V_120 ) ;
F_32 ( error ) ;
}
static struct V_108 *
F_36 ( struct V_129 * V_77 ,
struct V_130 * V_131 ,
const int V_132 )
{
struct V_108 * V_133 ;
int V_80 ;
T_5 V_134 ;
if ( V_131 == NULL || V_131 -> V_113 == NULL )
return NULL ;
V_133 = F_30 ( sizeof( * V_133 ) + V_132 * sizeof( T_5 * ) , V_135 ) ;
if ( V_133 == NULL )
return NULL ;
V_134 = V_133 -> V_33 = F_37 ( V_131 ) ;
for ( V_80 = 0 ; V_80 < V_132 ; V_80 ++ ) {
unsigned long V_136 ;
void * V_137 ;
V_137 = F_30 ( V_112 , V_135 ) ;
if ( V_137 == NULL )
goto V_138;
F_38 ( V_136 ) ;
if ( V_134 < V_77 -> V_139 . V_140 &&
V_131 -> V_141 ) {
void T_6 * V_142 ;
V_142 = F_39 ( V_77 -> V_139 . V_143 ,
V_134 ) ;
F_40 ( V_137 , V_142 , V_112 ) ;
F_41 ( V_142 ) ;
} else if ( V_131 -> V_144 ) {
unsigned long V_83 ;
V_83 = V_77 -> V_145 . V_146 ;
V_83 += V_131 -> V_144 -> V_22 ;
V_83 += V_80 << V_147 ;
F_40 ( V_137 , ( void T_6 * ) V_83 , V_112 ) ;
} else {
struct V_82 * V_82 ;
void * V_142 ;
V_82 = F_42 ( V_131 , V_80 ) ;
F_43 ( & V_82 , 1 ) ;
V_142 = F_44 ( V_82 ) ;
memcpy ( V_137 , V_142 , V_112 ) ;
F_45 ( V_142 ) ;
F_43 ( & V_82 , 1 ) ;
}
F_46 ( V_136 ) ;
V_133 -> V_113 [ V_80 ] = V_137 ;
V_134 += V_112 ;
}
V_133 -> V_111 = V_132 ;
return V_133 ;
V_138:
while ( V_80 -- )
F_32 ( V_133 -> V_113 [ V_80 ] ) ;
F_32 ( V_133 ) ;
return NULL ;
}
static void F_47 ( struct V_31 * V_16 ,
struct V_130 * V_109 )
{
V_16 -> V_18 = V_109 -> V_148 . V_18 ;
V_16 -> V_30 = V_109 -> V_148 . V_30 ;
V_16 -> V_36 = V_109 -> V_149 ;
V_16 -> V_37 = V_109 -> V_150 ;
V_16 -> V_33 = F_37 ( V_109 ) ;
V_16 -> V_34 = V_109 -> V_148 . V_34 ;
V_16 -> V_35 = V_109 -> V_148 . V_35 ;
V_16 -> V_39 = V_109 -> V_39 ;
V_16 -> V_7 = 0 ;
if ( V_109 -> V_151 > 0 )
V_16 -> V_7 = 1 ;
if ( V_109 -> V_152 > 0 )
V_16 -> V_7 = - 1 ;
V_16 -> V_8 = V_109 -> V_153 ;
V_16 -> V_12 = V_109 -> V_12 ;
V_16 -> V_13 = V_109 -> V_154 != V_155 ;
V_16 -> V_2 = V_109 -> V_2 ? V_109 -> V_2 -> V_156 : - 1 ;
V_16 -> V_38 = V_109 -> V_38 ;
}
static T_5 F_48 ( struct V_31 * V_16 ,
int V_32 , struct V_157 * V_52 )
{
struct V_158 * V_159 ;
int V_80 = 0 ;
F_49 (vma, head, mm_list) {
F_47 ( V_16 ++ , V_159 -> V_109 ) ;
if ( ++ V_80 == V_32 )
break;
}
return V_80 ;
}
static T_5 F_50 ( struct V_31 * V_16 ,
int V_32 , struct V_157 * V_52 )
{
struct V_130 * V_109 ;
int V_80 = 0 ;
F_49 (obj, head, global_list) {
if ( V_109 -> V_151 == 0 )
continue;
F_47 ( V_16 ++ , V_109 ) ;
if ( ++ V_80 == V_32 )
break;
}
return V_80 ;
}
static void F_51 ( struct V_48 * V_49 ,
struct V_50 * error )
{
struct V_129 * V_77 = V_49 -> V_78 ;
int V_80 ;
switch ( F_21 ( V_49 ) -> V_59 ) {
case 8 :
case 7 :
case 6 :
for ( V_80 = 0 ; V_80 < V_77 -> V_99 ; V_80 ++ )
error -> V_100 [ V_80 ] = F_52 ( V_160 + ( V_80 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_80 = 0 ; V_80 < 16 ; V_80 ++ )
error -> V_100 [ V_80 ] = F_52 ( V_161 + ( V_80 * 8 ) ) ;
break;
case 3 :
if ( F_53 ( V_49 ) || F_54 ( V_49 ) || F_55 ( V_49 ) )
for ( V_80 = 0 ; V_80 < 8 ; V_80 ++ )
error -> V_100 [ V_80 + 8 ] = F_56 ( V_162 + ( V_80 * 4 ) ) ;
case 2 :
for ( V_80 = 0 ; V_80 < 8 ; V_80 ++ )
error -> V_100 [ V_80 ] = F_56 ( V_163 + ( V_80 * 4 ) ) ;
break;
default:
F_57 () ;
}
}
static struct V_108 *
F_58 ( struct V_129 * V_77 ,
struct V_79 * V_2 )
{
struct V_164 * V_165 ;
struct V_158 * V_159 ;
struct V_130 * V_109 ;
T_5 V_69 ;
if ( ! V_2 -> V_166 )
return NULL ;
if ( F_59 ( V_77 -> V_49 ) ) {
T_5 V_55 = F_56 ( V_167 ) ;
if ( F_60 ( V_2 -> V_156 != V_3 ) )
return NULL ;
V_109 = V_2 -> V_168 . V_109 ;
if ( V_55 >= F_37 ( V_109 ) &&
V_55 < F_37 ( V_109 ) + V_109 -> V_148 . V_18 )
return F_61 ( V_77 , V_109 ) ;
}
V_69 = V_2 -> V_166 ( V_2 , false ) ;
F_49 (vm, &dev_priv->vm_list, global_link) {
F_49 (vma, &vm->active_list, mm_list) {
V_109 = V_159 -> V_109 ;
if ( V_109 -> V_2 != V_2 )
continue;
if ( F_62 ( V_69 , V_109 -> V_149 ) )
continue;
if ( ( V_109 -> V_148 . V_34 & V_169 ) == 0 )
continue;
return F_61 ( V_77 , V_109 ) ;
}
}
return NULL ;
}
static void F_63 ( struct V_48 * V_49 ,
struct V_50 * error ,
struct V_79 * V_2 )
{
struct V_129 * V_77 = V_49 -> V_78 ;
if ( F_21 ( V_49 ) -> V_59 >= 6 ) {
error -> V_65 [ V_2 -> V_156 ] = F_56 ( V_2 -> V_170 + 0x50 ) ;
error -> V_66 [ V_2 -> V_156 ] = F_56 ( F_64 ( V_2 ) ) ;
error -> V_67 [ V_2 -> V_156 ] [ 0 ]
= F_56 ( F_65 ( V_2 -> V_170 ) ) ;
error -> V_67 [ V_2 -> V_156 ] [ 1 ]
= F_56 ( F_66 ( V_2 -> V_170 ) ) ;
error -> V_68 [ V_2 -> V_156 ] [ 0 ] = V_2 -> V_171 [ 0 ] ;
error -> V_68 [ V_2 -> V_156 ] [ 1 ] = V_2 -> V_171 [ 1 ] ;
}
if ( F_22 ( V_49 ) ) {
error -> V_67 [ V_2 -> V_156 ] [ 2 ] =
F_56 ( F_67 ( V_2 -> V_170 ) ) ;
error -> V_68 [ V_2 -> V_156 ] [ 2 ] = V_2 -> V_171 [ 2 ] ;
}
if ( F_21 ( V_49 ) -> V_59 >= 4 ) {
error -> V_64 [ V_2 -> V_156 ] = F_56 ( F_68 ( V_2 -> V_170 ) ) ;
error -> V_56 [ V_2 -> V_156 ] = F_56 ( F_69 ( V_2 -> V_170 ) ) ;
error -> V_57 [ V_2 -> V_156 ] = F_56 ( F_70 ( V_2 -> V_170 ) ) ;
error -> V_58 [ V_2 -> V_156 ] = F_56 ( F_71 ( V_2 -> V_170 ) ) ;
error -> V_62 [ V_2 -> V_156 ] = F_56 ( F_72 ( V_2 -> V_170 ) ) ;
if ( V_2 -> V_156 == V_3 )
error -> V_60 = F_52 ( V_172 ) ;
error -> V_61 [ V_2 -> V_156 ] = F_56 ( F_73 ( V_2 -> V_170 ) ) ;
} else {
error -> V_64 [ V_2 -> V_156 ] = F_56 ( V_173 ) ;
error -> V_56 [ V_2 -> V_156 ] = F_56 ( V_174 ) ;
error -> V_57 [ V_2 -> V_156 ] = F_56 ( V_175 ) ;
error -> V_58 [ V_2 -> V_156 ] = F_56 ( V_176 ) ;
}
error -> V_70 [ V_2 -> V_156 ] = F_74 ( & V_2 -> V_177 ) ;
error -> V_63 [ V_2 -> V_156 ] = F_56 ( F_75 ( V_2 -> V_170 ) ) ;
error -> V_69 [ V_2 -> V_156 ] = V_2 -> V_166 ( V_2 , false ) ;
error -> V_55 [ V_2 -> V_156 ] = F_76 ( V_2 ) ;
error -> V_52 [ V_2 -> V_156 ] = F_77 ( V_2 ) ;
error -> V_53 [ V_2 -> V_156 ] = F_78 ( V_2 ) ;
error -> V_54 [ V_2 -> V_156 ] = F_79 ( V_2 ) ;
error -> V_71 [ V_2 -> V_156 ] = V_2 -> V_52 ;
error -> V_72 [ V_2 -> V_156 ] = V_2 -> V_53 ;
error -> V_74 [ V_2 -> V_156 ] = V_2 -> V_178 . V_179 ;
error -> V_73 [ V_2 -> V_156 ] = V_2 -> V_178 . V_180 ;
}
static void F_80 ( struct V_79 * V_2 ,
struct V_50 * error ,
struct V_181 * V_182 )
{
struct V_129 * V_77 = V_2 -> V_49 -> V_78 ;
struct V_130 * V_109 ;
if ( V_2 -> V_156 != V_3 || ! error -> V_96 )
return;
F_49 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ( error -> V_96 & V_183 ) == F_37 ( V_109 ) ) {
V_182 -> V_118 = F_36 ( V_77 ,
V_109 , 1 ) ;
break;
}
}
}
static void F_81 ( struct V_48 * V_49 ,
struct V_50 * error )
{
struct V_129 * V_77 = V_49 -> V_78 ;
struct V_79 * V_2 ;
struct V_184 * V_185 ;
int V_80 , V_32 ;
F_26 (ring, dev_priv, i) {
F_63 ( V_49 , error , V_2 ) ;
error -> V_2 [ V_80 ] . V_110 =
F_58 ( V_77 , V_2 ) ;
error -> V_2 [ V_80 ] . V_117 =
F_61 ( V_77 , V_2 -> V_109 ) ;
F_80 ( V_2 , error , & error -> V_2 [ V_80 ] ) ;
V_32 = 0 ;
F_49 (request, &ring->request_list, list)
V_32 ++ ;
error -> V_2 [ V_80 ] . V_114 = V_32 ;
error -> V_2 [ V_80 ] . V_115 =
F_82 ( V_32 , sizeof( * error -> V_2 [ V_80 ] . V_115 ) ,
V_135 ) ;
if ( error -> V_2 [ V_80 ] . V_115 == NULL ) {
error -> V_2 [ V_80 ] . V_114 = 0 ;
continue;
}
V_32 = 0 ;
F_49 (request, &ring->request_list, list) {
struct V_186 * V_187 ;
V_187 = & error -> V_2 [ V_80 ] . V_115 [ V_32 ++ ] ;
V_187 -> V_69 = V_185 -> V_69 ;
V_187 -> V_116 = V_185 -> V_188 ;
V_187 -> V_53 = V_185 -> V_53 ;
}
}
}
static void F_83 ( struct V_129 * V_77 ,
struct V_50 * error ,
struct V_164 * V_165 ,
const int V_189 )
{
struct V_31 * V_104 = NULL , * V_106 = NULL ;
struct V_130 * V_109 ;
struct V_158 * V_159 ;
int V_80 ;
V_80 = 0 ;
F_49 (vma, &vm->active_list, mm_list)
V_80 ++ ;
error -> V_105 [ V_189 ] = V_80 ;
F_49 (obj, &dev_priv->mm.bound_list, global_list)
if ( V_109 -> V_151 )
V_80 ++ ;
error -> V_107 [ V_189 ] = V_80 - error -> V_105 [ V_189 ] ;
if ( V_80 ) {
V_104 = F_82 ( V_80 , sizeof( * V_104 ) , V_135 ) ;
if ( V_104 )
V_106 = V_104 + error -> V_105 [ V_189 ] ;
}
if ( V_104 )
error -> V_105 [ V_189 ] =
F_48 ( V_104 ,
error -> V_105 [ V_189 ] ,
& V_165 -> V_190 ) ;
if ( V_106 )
error -> V_107 [ V_189 ] =
F_50 ( V_106 ,
error -> V_107 [ V_189 ] ,
& V_77 -> V_145 . V_191 ) ;
error -> V_104 [ V_189 ] = V_104 ;
error -> V_106 [ V_189 ] = V_106 ;
}
static void F_84 ( struct V_129 * V_77 ,
struct V_50 * error )
{
struct V_164 * V_165 ;
int V_192 = 0 , V_80 = 0 ;
F_49 (vm, &dev_priv->vm_list, global_link)
V_192 ++ ;
if ( F_8 ( V_192 > 1 , L_75 ) )
V_192 = 1 ;
V_165 = & V_77 -> V_139 . V_148 ;
error -> V_104 = F_82 ( V_192 , sizeof( * error -> V_104 ) , V_135 ) ;
error -> V_106 = F_82 ( V_192 , sizeof( * error -> V_106 ) , V_135 ) ;
error -> V_105 = F_82 ( V_192 , sizeof( * error -> V_105 ) ,
V_135 ) ;
error -> V_107 = F_82 ( V_192 , sizeof( * error -> V_107 ) ,
V_135 ) ;
F_49 (vm, &dev_priv->vm_list, global_link)
F_83 ( V_77 , error , V_165 , V_80 ++ ) ;
}
void F_85 ( struct V_48 * V_49 )
{
struct V_129 * V_77 = V_49 -> V_78 ;
struct V_50 * error ;
unsigned long V_136 ;
int V_193 ;
F_86 ( & V_77 -> V_97 . V_194 , V_136 ) ;
error = V_77 -> V_97 . V_195 ;
F_87 ( & V_77 -> V_97 . V_194 , V_136 ) ;
if ( error )
return;
error = F_88 ( sizeof( * error ) , V_135 ) ;
if ( ! error ) {
F_89 ( L_76 ) ;
return;
}
F_90 ( L_77 ,
V_49 -> V_196 -> V_197 ) ;
F_90 ( L_78 ) ;
F_90 ( L_79 ) ;
F_90 ( L_80 ) ;
F_90 ( L_81 ) ;
F_91 ( & error -> V_128 ) ;
error -> V_91 = F_56 ( V_198 ) ;
error -> V_93 = F_56 ( V_199 ) ;
if ( F_92 ( V_49 ) )
error -> V_96 = F_56 ( V_200 ) ;
if ( F_93 ( V_49 ) )
error -> V_92 = F_56 ( V_201 ) | F_56 ( V_202 ) ;
else if ( F_94 ( V_49 ) )
error -> V_92 = F_56 ( V_202 ) | F_56 ( V_203 ) ;
else if ( F_95 ( V_49 ) )
error -> V_92 = F_96 ( V_204 ) ;
else
error -> V_92 = F_56 ( V_204 ) ;
if ( F_21 ( V_49 ) -> V_59 >= 6 )
error -> V_95 = F_56 ( V_205 ) ;
if ( F_94 ( V_49 ) )
error -> V_94 = F_56 ( V_206 ) ;
else if ( F_21 ( V_49 ) -> V_59 >= 7 )
error -> V_94 = F_56 ( V_207 ) ;
else if ( F_21 ( V_49 ) -> V_59 == 6 )
error -> V_94 = F_56 ( V_208 ) ;
if ( ! F_93 ( V_49 ) )
F_97 ( V_193 )
error -> V_209 [ V_193 ] = F_56 ( F_98 ( V_193 ) ) ;
if ( F_21 ( V_49 ) -> V_59 >= 6 ) {
error -> error = F_56 ( V_210 ) ;
error -> V_102 = F_56 ( V_211 ) ;
}
if ( F_21 ( V_49 ) -> V_59 == 7 )
error -> V_103 = F_56 ( V_212 ) ;
F_99 ( V_49 , error -> V_101 ) ;
F_84 ( V_77 , error ) ;
F_51 ( V_49 , error ) ;
F_81 ( V_49 , error ) ;
F_100 ( & error -> time ) ;
error -> V_119 = F_101 ( V_49 ) ;
error -> V_120 = F_102 ( V_49 ) ;
F_86 ( & V_77 -> V_97 . V_194 , V_136 ) ;
if ( V_77 -> V_97 . V_195 == NULL ) {
V_77 -> V_97 . V_195 = error ;
error = NULL ;
}
F_87 ( & V_77 -> V_97 . V_194 , V_136 ) ;
if ( error )
F_33 ( & error -> V_128 ) ;
}
void F_103 ( struct V_48 * V_49 ,
struct V_75 * V_76 )
{
struct V_129 * V_77 = V_49 -> V_78 ;
unsigned long V_136 ;
F_86 ( & V_77 -> V_97 . V_194 , V_136 ) ;
V_76 -> error = V_77 -> V_97 . V_195 ;
if ( V_76 -> error )
F_104 ( & V_76 -> error -> V_128 ) ;
F_87 ( & V_77 -> V_97 . V_194 , V_136 ) ;
}
void F_105 ( struct V_75 * V_76 )
{
if ( V_76 -> error )
F_106 ( & V_76 -> error -> V_128 , F_33 ) ;
}
void F_107 ( struct V_48 * V_49 )
{
struct V_129 * V_77 = V_49 -> V_78 ;
struct V_50 * error ;
unsigned long V_136 ;
F_86 ( & V_77 -> V_97 . V_194 , V_136 ) ;
error = V_77 -> V_97 . V_195 ;
V_77 -> V_97 . V_195 = NULL ;
F_87 ( & V_77 -> V_97 . V_194 , V_136 ) ;
if ( error )
F_106 ( & error -> V_128 , F_33 ) ;
}
const char * F_17 ( int type )
{
switch ( type ) {
case V_213 : return L_82 ;
case V_214 : return L_83 ;
case V_215 : return L_84 ;
case V_216 : return L_85 ;
default: return L_7 ;
}
}
void F_99 ( struct V_48 * V_49 , T_7 * V_58 )
{
struct V_129 * V_77 = V_49 -> V_78 ;
memset ( V_58 , 0 , sizeof( * V_58 ) * V_217 ) ;
switch ( F_21 ( V_49 ) -> V_59 ) {
case 2 :
case 3 :
V_58 [ 0 ] = F_56 ( V_176 ) ;
break;
case 4 :
case 5 :
case 6 :
V_58 [ 0 ] = F_56 ( V_218 ) ;
V_58 [ 1 ] = F_56 ( V_219 ) ;
break;
default:
F_108 ( 1 , L_86 ) ;
case 7 :
case 8 :
V_58 [ 0 ] = F_56 ( V_220 ) ;
V_58 [ 1 ] = F_56 ( V_221 ) ;
V_58 [ 2 ] = F_56 ( V_222 ) ;
V_58 [ 3 ] = F_56 ( V_223 ) ;
break;
}
}
