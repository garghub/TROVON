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
static void F_18 ( struct V_14 * V_29 ,
struct V_41 * V_42 ,
struct V_43 * error ,
unsigned V_2 )
{
F_19 ( V_2 >= V_44 ) ;
F_15 ( V_29 , L_21 , F_2 ( V_2 ) ) ;
F_15 ( V_29 , L_22 , error -> V_45 [ V_2 ] ) ;
F_15 ( V_29 , L_23 , error -> V_46 [ V_2 ] ) ;
F_15 ( V_29 , L_24 , error -> V_47 [ V_2 ] ) ;
F_15 ( V_29 , L_25 , error -> V_48 [ V_2 ] ) ;
F_15 ( V_29 , L_26 , error -> V_49 [ V_2 ] ) ;
F_15 ( V_29 , L_27 , error -> V_50 [ V_2 ] ) ;
F_15 ( V_29 , L_28 , error -> V_51 [ V_2 ] ) ;
if ( V_2 == V_3 && F_20 ( V_42 ) -> V_52 >= 4 )
F_15 ( V_29 , L_29 , error -> V_53 ) ;
if ( F_20 ( V_42 ) -> V_52 >= 4 )
F_15 ( V_29 , L_30 , error -> V_54 [ V_2 ] ) ;
F_15 ( V_29 , L_31 , error -> V_55 [ V_2 ] ) ;
F_15 ( V_29 , L_32 , error -> V_56 [ V_2 ] ) ;
if ( F_20 ( V_42 ) -> V_52 >= 6 ) {
F_15 ( V_29 , L_33 , error -> V_57 [ V_2 ] ) ;
F_15 ( V_29 , L_34 , error -> V_58 [ V_2 ] ) ;
F_15 ( V_29 , L_35 ,
error -> V_59 [ V_2 ] [ 0 ] ,
error -> V_60 [ V_2 ] [ 0 ] ) ;
F_15 ( V_29 , L_36 ,
error -> V_59 [ V_2 ] [ 1 ] ,
error -> V_60 [ V_2 ] [ 1 ] ) ;
if ( F_21 ( V_42 ) ) {
F_15 ( V_29 , L_37 ,
error -> V_59 [ V_2 ] [ 2 ] ,
error -> V_60 [ V_2 ] [ 2 ] ) ;
}
}
F_15 ( V_29 , L_38 , error -> V_61 [ V_2 ] ) ;
F_15 ( V_29 , L_39 , F_1 ( error -> V_62 [ V_2 ] ) ) ;
F_15 ( V_29 , L_40 , error -> V_63 [ V_2 ] ) ;
F_15 ( V_29 , L_41 , error -> V_64 [ V_2 ] ) ;
}
void F_22 ( struct V_14 * V_15 , const char * V_26 , ... )
{
T_2 args ;
va_start ( args , V_26 ) ;
F_11 ( V_15 , V_26 , args ) ;
va_end ( args ) ;
}
int F_23 ( struct V_14 * V_29 ,
const struct V_65 * V_66 )
{
struct V_41 * V_42 = V_66 -> V_42 ;
T_3 * V_67 = V_42 -> V_68 ;
struct V_43 * error = V_66 -> error ;
struct V_69 * V_2 ;
int V_70 , V_71 , V_72 , V_73 , V_74 ;
if ( ! error ) {
F_15 ( V_29 , L_42 ) ;
goto V_75;
}
F_15 ( V_29 , L_43 , error -> time . V_76 ,
error -> time . V_77 ) ;
F_15 ( V_29 , L_44 V_78 L_20 ) ;
F_15 ( V_29 , L_45 , V_42 -> V_79 ) ;
F_15 ( V_29 , L_46 , error -> V_80 ) ;
F_15 ( V_29 , L_47 , error -> V_81 ) ;
F_15 ( V_29 , L_48 , error -> V_82 ) ;
F_15 ( V_29 , L_49 , error -> V_83 ) ;
F_15 ( V_29 , L_50 , error -> V_84 ) ;
F_15 ( V_29 , L_51 , error -> V_85 ) ;
for ( V_70 = 0 ; V_70 < V_67 -> V_86 ; V_70 ++ )
F_15 ( V_29 , L_52 , V_70 , error -> V_87 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < F_24 ( error -> V_88 ) ; V_70 ++ )
F_15 ( V_29 , L_53 , V_70 ,
error -> V_88 [ V_70 ] ) ;
if ( F_20 ( V_42 ) -> V_52 >= 6 ) {
F_15 ( V_29 , L_54 , error -> error ) ;
F_15 ( V_29 , L_55 , error -> V_89 ) ;
}
if ( F_20 ( V_42 ) -> V_52 == 7 )
F_15 ( V_29 , L_56 , error -> V_90 ) ;
F_25 (ring, dev_priv, i)
F_18 ( V_29 , V_42 , error , V_70 ) ;
if ( error -> V_91 )
F_14 ( V_29 , L_57 ,
error -> V_91 [ 0 ] ,
error -> V_92 [ 0 ] ) ;
if ( error -> V_93 )
F_14 ( V_29 , L_58 ,
error -> V_93 [ 0 ] ,
error -> V_94 [ 0 ] ) ;
for ( V_70 = 0 ; V_70 < F_24 ( error -> V_2 ) ; V_70 ++ ) {
struct V_95 * V_96 ;
if ( ( V_96 = error -> V_2 [ V_70 ] . V_97 ) ) {
F_15 ( V_29 , L_59 ,
V_67 -> V_2 [ V_70 ] . V_30 ,
V_96 -> V_33 ) ;
V_73 = 0 ;
for ( V_72 = 0 ; V_72 < V_96 -> V_98 ; V_72 ++ ) {
for ( V_74 = 0 ; V_74 < V_99 / 4 ; V_74 ++ ) {
F_15 ( V_29 , L_60 , V_73 ,
V_96 -> V_100 [ V_72 ] [ V_74 ] ) ;
V_73 += 4 ;
}
}
}
if ( error -> V_2 [ V_70 ] . V_101 ) {
F_15 ( V_29 , L_61 ,
V_67 -> V_2 [ V_70 ] . V_30 ,
error -> V_2 [ V_70 ] . V_101 ) ;
for ( V_71 = 0 ; V_71 < error -> V_2 [ V_70 ] . V_101 ; V_71 ++ ) {
F_15 ( V_29 , L_62 ,
error -> V_2 [ V_70 ] . V_102 [ V_71 ] . V_61 ,
error -> V_2 [ V_70 ] . V_102 [ V_71 ] . V_103 ,
error -> V_2 [ V_70 ] . V_102 [ V_71 ] . V_46 ) ;
}
}
if ( ( V_96 = error -> V_2 [ V_70 ] . V_104 ) ) {
F_15 ( V_29 , L_63 ,
V_67 -> V_2 [ V_70 ] . V_30 ,
V_96 -> V_33 ) ;
V_73 = 0 ;
for ( V_72 = 0 ; V_72 < V_96 -> V_98 ; V_72 ++ ) {
for ( V_74 = 0 ; V_74 < V_99 / 4 ; V_74 ++ ) {
F_15 ( V_29 , L_60 ,
V_73 ,
V_96 -> V_100 [ V_72 ] [ V_74 ] ) ;
V_73 += 4 ;
}
}
}
V_96 = error -> V_2 [ V_70 ] . V_105 ;
if ( V_96 ) {
F_15 ( V_29 , L_64 ,
V_67 -> V_2 [ V_70 ] . V_30 ,
V_96 -> V_33 ) ;
V_73 = 0 ;
for ( V_74 = 0 ; V_74 < V_99 / 16 ; V_74 += 4 ) {
F_15 ( V_29 , L_65 ,
V_73 ,
V_96 -> V_100 [ 0 ] [ V_74 ] ,
V_96 -> V_100 [ 0 ] [ V_74 + 1 ] ,
V_96 -> V_100 [ 0 ] [ V_74 + 2 ] ,
V_96 -> V_100 [ 0 ] [ V_74 + 3 ] ) ;
V_73 += 16 ;
}
}
}
if ( error -> V_106 )
F_26 ( V_29 , error -> V_106 ) ;
if ( error -> V_107 )
F_27 ( V_29 , V_42 , error -> V_107 ) ;
V_75:
if ( V_29 -> V_17 == 0 && V_29 -> V_16 )
return V_29 -> V_16 ;
return 0 ;
}
int F_28 ( struct V_14 * V_108 ,
T_1 V_32 , T_4 V_21 )
{
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_108 -> V_18 = V_32 + 1 > V_99 ? V_32 + 1 : V_99 ;
V_108 -> V_25 = F_29 ( V_108 -> V_18 ,
V_109 | V_110 | V_111 ) ;
if ( V_108 -> V_25 == NULL ) {
V_108 -> V_18 = V_99 ;
V_108 -> V_25 = F_29 ( V_108 -> V_18 , V_109 ) ;
}
if ( V_108 -> V_25 == NULL ) {
V_108 -> V_18 = 128 ;
V_108 -> V_25 = F_29 ( V_108 -> V_18 , V_109 ) ;
}
if ( V_108 -> V_25 == NULL )
return - V_112 ;
V_108 -> V_22 = V_21 ;
return 0 ;
}
static void F_30 ( struct V_95 * V_96 )
{
int V_72 ;
if ( V_96 == NULL )
return;
for ( V_72 = 0 ; V_72 < V_96 -> V_98 ; V_72 ++ )
F_31 ( V_96 -> V_100 [ V_72 ] ) ;
F_31 ( V_96 ) ;
}
static void F_32 ( struct V_113 * V_114 )
{
struct V_43 * error = F_33 ( V_114 ,
F_34 ( * error ) , V_115 ) ;
int V_70 ;
for ( V_70 = 0 ; V_70 < F_24 ( error -> V_2 ) ; V_70 ++ ) {
F_30 ( error -> V_2 [ V_70 ] . V_97 ) ;
F_30 ( error -> V_2 [ V_70 ] . V_104 ) ;
F_30 ( error -> V_2 [ V_70 ] . V_105 ) ;
F_31 ( error -> V_2 [ V_70 ] . V_102 ) ;
}
F_31 ( error -> V_91 ) ;
F_31 ( error -> V_106 ) ;
F_31 ( error -> V_107 ) ;
F_31 ( error ) ;
}
static struct V_95 *
F_35 ( struct V_116 * V_67 ,
struct V_117 * V_118 ,
const int V_119 )
{
struct V_95 * V_120 ;
int V_70 ;
T_5 V_121 ;
if ( V_118 == NULL || V_118 -> V_100 == NULL )
return NULL ;
V_120 = F_29 ( sizeof( * V_120 ) + V_119 * sizeof( T_5 * ) , V_122 ) ;
if ( V_120 == NULL )
return NULL ;
V_121 = V_120 -> V_33 = F_36 ( V_118 ) ;
for ( V_70 = 0 ; V_70 < V_119 ; V_70 ++ ) {
unsigned long V_123 ;
void * V_124 ;
V_124 = F_29 ( V_99 , V_122 ) ;
if ( V_124 == NULL )
goto V_125;
F_37 ( V_123 ) ;
if ( V_121 < V_67 -> V_126 . V_127 &&
V_118 -> V_128 ) {
void T_6 * V_129 ;
V_129 = F_38 ( V_67 -> V_126 . V_130 ,
V_121 ) ;
F_39 ( V_124 , V_129 , V_99 ) ;
F_40 ( V_129 ) ;
} else if ( V_118 -> V_131 ) {
unsigned long V_73 ;
V_73 = V_67 -> V_132 . V_133 ;
V_73 += V_118 -> V_131 -> V_22 ;
V_73 += V_70 << V_134 ;
F_39 ( V_124 , ( void T_6 * ) V_73 , V_99 ) ;
} else {
struct V_72 * V_72 ;
void * V_129 ;
V_72 = F_41 ( V_118 , V_70 ) ;
F_42 ( & V_72 , 1 ) ;
V_129 = F_43 ( V_72 ) ;
memcpy ( V_124 , V_129 , V_99 ) ;
F_44 ( V_129 ) ;
F_42 ( & V_72 , 1 ) ;
}
F_45 ( V_123 ) ;
V_120 -> V_100 [ V_70 ] = V_124 ;
V_121 += V_99 ;
}
V_120 -> V_98 = V_119 ;
return V_120 ;
V_125:
while ( V_70 -- )
F_31 ( V_120 -> V_100 [ V_70 ] ) ;
F_31 ( V_120 ) ;
return NULL ;
}
static void F_46 ( struct V_31 * V_16 ,
struct V_117 * V_96 )
{
V_16 -> V_18 = V_96 -> V_135 . V_18 ;
V_16 -> V_30 = V_96 -> V_135 . V_30 ;
V_16 -> V_36 = V_96 -> V_136 ;
V_16 -> V_37 = V_96 -> V_137 ;
V_16 -> V_33 = F_36 ( V_96 ) ;
V_16 -> V_34 = V_96 -> V_135 . V_34 ;
V_16 -> V_35 = V_96 -> V_135 . V_35 ;
V_16 -> V_39 = V_96 -> V_39 ;
V_16 -> V_7 = 0 ;
if ( V_96 -> V_138 > 0 )
V_16 -> V_7 = 1 ;
if ( V_96 -> V_139 > 0 )
V_16 -> V_7 = - 1 ;
V_16 -> V_8 = V_96 -> V_140 ;
V_16 -> V_12 = V_96 -> V_12 ;
V_16 -> V_13 = V_96 -> V_141 != V_142 ;
V_16 -> V_2 = V_96 -> V_2 ? V_96 -> V_2 -> V_143 : - 1 ;
V_16 -> V_38 = V_96 -> V_38 ;
}
static T_5 F_47 ( struct V_31 * V_16 ,
int V_32 , struct V_144 * V_45 )
{
struct V_145 * V_146 ;
int V_70 = 0 ;
F_48 (vma, head, mm_list) {
F_46 ( V_16 ++ , V_146 -> V_96 ) ;
if ( ++ V_70 == V_32 )
break;
}
return V_70 ;
}
static T_5 F_49 ( struct V_31 * V_16 ,
int V_32 , struct V_144 * V_45 )
{
struct V_117 * V_96 ;
int V_70 = 0 ;
F_48 (obj, head, global_list) {
if ( V_96 -> V_138 == 0 )
continue;
F_46 ( V_16 ++ , V_96 ) ;
if ( ++ V_70 == V_32 )
break;
}
return V_70 ;
}
static void F_50 ( struct V_41 * V_42 ,
struct V_43 * error )
{
struct V_116 * V_67 = V_42 -> V_68 ;
int V_70 ;
switch ( F_20 ( V_42 ) -> V_52 ) {
case 7 :
case 6 :
for ( V_70 = 0 ; V_70 < V_67 -> V_86 ; V_70 ++ )
error -> V_87 [ V_70 ] = F_51 ( V_147 + ( V_70 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_70 = 0 ; V_70 < 16 ; V_70 ++ )
error -> V_87 [ V_70 ] = F_51 ( V_148 + ( V_70 * 8 ) ) ;
break;
case 3 :
if ( F_52 ( V_42 ) || F_53 ( V_42 ) || F_54 ( V_42 ) )
for ( V_70 = 0 ; V_70 < 8 ; V_70 ++ )
error -> V_87 [ V_70 + 8 ] = F_55 ( V_149 + ( V_70 * 4 ) ) ;
case 2 :
for ( V_70 = 0 ; V_70 < 8 ; V_70 ++ )
error -> V_87 [ V_70 ] = F_55 ( V_150 + ( V_70 * 4 ) ) ;
break;
default:
F_56 () ;
}
}
static struct V_95 *
F_57 ( struct V_116 * V_67 ,
struct V_69 * V_2 )
{
struct V_151 * V_152 ;
struct V_145 * V_146 ;
struct V_117 * V_96 ;
T_5 V_61 ;
if ( ! V_2 -> V_153 )
return NULL ;
if ( F_58 ( V_67 -> V_42 ) ) {
T_5 V_48 = F_55 ( V_154 ) ;
if ( F_59 ( V_2 -> V_143 != V_3 ) )
return NULL ;
V_96 = V_2 -> V_155 . V_96 ;
if ( V_48 >= F_36 ( V_96 ) &&
V_48 < F_36 ( V_96 ) + V_96 -> V_135 . V_18 )
return F_60 ( V_67 , V_96 ) ;
}
V_61 = V_2 -> V_153 ( V_2 , false ) ;
F_48 (vm, &dev_priv->vm_list, global_link) {
F_48 (vma, &vm->active_list, mm_list) {
V_96 = V_146 -> V_96 ;
if ( V_96 -> V_2 != V_2 )
continue;
if ( F_61 ( V_61 , V_96 -> V_136 ) )
continue;
if ( ( V_96 -> V_135 . V_34 & V_156 ) == 0 )
continue;
return F_60 ( V_67 , V_96 ) ;
}
}
return NULL ;
}
static void F_62 ( struct V_41 * V_42 ,
struct V_43 * error ,
struct V_69 * V_2 )
{
struct V_116 * V_67 = V_42 -> V_68 ;
if ( F_20 ( V_42 ) -> V_52 >= 6 ) {
error -> V_57 [ V_2 -> V_143 ] = F_55 ( V_2 -> V_157 + 0x50 ) ;
error -> V_58 [ V_2 -> V_143 ] = F_55 ( F_63 ( V_2 ) ) ;
error -> V_59 [ V_2 -> V_143 ] [ 0 ]
= F_55 ( F_64 ( V_2 -> V_157 ) ) ;
error -> V_59 [ V_2 -> V_143 ] [ 1 ]
= F_55 ( F_65 ( V_2 -> V_157 ) ) ;
error -> V_60 [ V_2 -> V_143 ] [ 0 ] = V_2 -> V_158 [ 0 ] ;
error -> V_60 [ V_2 -> V_143 ] [ 1 ] = V_2 -> V_158 [ 1 ] ;
}
if ( F_21 ( V_42 ) ) {
error -> V_59 [ V_2 -> V_143 ] [ 2 ] =
F_55 ( F_66 ( V_2 -> V_157 ) ) ;
error -> V_60 [ V_2 -> V_143 ] [ 2 ] = V_2 -> V_158 [ 2 ] ;
}
if ( F_20 ( V_42 ) -> V_52 >= 4 ) {
error -> V_56 [ V_2 -> V_143 ] = F_55 ( F_67 ( V_2 -> V_157 ) ) ;
error -> V_49 [ V_2 -> V_143 ] = F_55 ( F_68 ( V_2 -> V_157 ) ) ;
error -> V_50 [ V_2 -> V_143 ] = F_55 ( F_69 ( V_2 -> V_157 ) ) ;
error -> V_51 [ V_2 -> V_143 ] = F_55 ( F_70 ( V_2 -> V_157 ) ) ;
error -> V_54 [ V_2 -> V_143 ] = F_55 ( F_71 ( V_2 -> V_157 ) ) ;
if ( V_2 -> V_143 == V_3 )
error -> V_53 = F_51 ( V_159 ) ;
} else {
error -> V_56 [ V_2 -> V_143 ] = F_55 ( V_160 ) ;
error -> V_49 [ V_2 -> V_143 ] = F_55 ( V_161 ) ;
error -> V_50 [ V_2 -> V_143 ] = F_55 ( V_162 ) ;
error -> V_51 [ V_2 -> V_143 ] = F_55 ( V_163 ) ;
}
error -> V_62 [ V_2 -> V_143 ] = F_72 ( & V_2 -> V_164 ) ;
error -> V_55 [ V_2 -> V_143 ] = F_55 ( F_73 ( V_2 -> V_157 ) ) ;
error -> V_61 [ V_2 -> V_143 ] = V_2 -> V_153 ( V_2 , false ) ;
error -> V_48 [ V_2 -> V_143 ] = F_74 ( V_2 ) ;
error -> V_45 [ V_2 -> V_143 ] = F_75 ( V_2 ) ;
error -> V_46 [ V_2 -> V_143 ] = F_76 ( V_2 ) ;
error -> V_47 [ V_2 -> V_143 ] = F_77 ( V_2 ) ;
error -> V_63 [ V_2 -> V_143 ] = V_2 -> V_45 ;
error -> V_64 [ V_2 -> V_143 ] = V_2 -> V_46 ;
}
static void F_78 ( struct V_69 * V_2 ,
struct V_43 * error ,
struct V_165 * V_166 )
{
struct V_116 * V_67 = V_2 -> V_42 -> V_68 ;
struct V_117 * V_96 ;
if ( V_2 -> V_143 != V_3 || ! error -> V_85 )
return;
F_48 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ( error -> V_85 & V_167 ) == F_36 ( V_96 ) ) {
V_166 -> V_105 = F_35 ( V_67 ,
V_96 , 1 ) ;
break;
}
}
}
static void F_79 ( struct V_41 * V_42 ,
struct V_43 * error )
{
struct V_116 * V_67 = V_42 -> V_68 ;
struct V_69 * V_2 ;
struct V_168 * V_169 ;
int V_70 , V_32 ;
F_25 (ring, dev_priv, i) {
F_62 ( V_42 , error , V_2 ) ;
error -> V_2 [ V_70 ] . V_97 =
F_57 ( V_67 , V_2 ) ;
error -> V_2 [ V_70 ] . V_104 =
F_60 ( V_67 , V_2 -> V_96 ) ;
F_78 ( V_2 , error , & error -> V_2 [ V_70 ] ) ;
V_32 = 0 ;
F_48 (request, &ring->request_list, list)
V_32 ++ ;
error -> V_2 [ V_70 ] . V_101 = V_32 ;
error -> V_2 [ V_70 ] . V_102 =
F_29 ( V_32 * sizeof( struct V_170 ) ,
V_122 ) ;
if ( error -> V_2 [ V_70 ] . V_102 == NULL ) {
error -> V_2 [ V_70 ] . V_101 = 0 ;
continue;
}
V_32 = 0 ;
F_48 (request, &ring->request_list, list) {
struct V_170 * V_171 ;
V_171 = & error -> V_2 [ V_70 ] . V_102 [ V_32 ++ ] ;
V_171 -> V_61 = V_169 -> V_61 ;
V_171 -> V_103 = V_169 -> V_172 ;
V_171 -> V_46 = V_169 -> V_46 ;
}
}
}
static void F_80 ( struct V_116 * V_67 ,
struct V_43 * error ,
struct V_151 * V_152 ,
const int V_173 )
{
struct V_31 * V_91 = NULL , * V_93 = NULL ;
struct V_117 * V_96 ;
struct V_145 * V_146 ;
int V_70 ;
V_70 = 0 ;
F_48 (vma, &vm->active_list, mm_list)
V_70 ++ ;
error -> V_92 [ V_173 ] = V_70 ;
F_48 (obj, &dev_priv->mm.bound_list, global_list)
if ( V_96 -> V_138 )
V_70 ++ ;
error -> V_94 [ V_173 ] = V_70 - error -> V_92 [ V_173 ] ;
if ( V_70 ) {
V_91 = F_29 ( sizeof( * V_91 ) * V_70 , V_122 ) ;
if ( V_91 )
V_93 = V_91 + error -> V_92 [ V_173 ] ;
}
if ( V_91 )
error -> V_92 [ V_173 ] =
F_47 ( V_91 ,
error -> V_92 [ V_173 ] ,
& V_152 -> V_174 ) ;
if ( V_93 )
error -> V_94 [ V_173 ] =
F_49 ( V_93 ,
error -> V_94 [ V_173 ] ,
& V_67 -> V_132 . V_175 ) ;
error -> V_91 [ V_173 ] = V_91 ;
error -> V_93 [ V_173 ] = V_93 ;
}
static void F_81 ( struct V_116 * V_67 ,
struct V_43 * error )
{
struct V_151 * V_152 ;
int V_176 = 0 , V_70 = 0 ;
F_48 (vm, &dev_priv->vm_list, global_link)
V_176 ++ ;
if ( F_8 ( V_176 > 1 , L_66 ) )
V_176 = 1 ;
V_152 = & V_67 -> V_126 . V_135 ;
error -> V_91 = F_82 ( V_176 , sizeof( * error -> V_91 ) , V_122 ) ;
error -> V_93 = F_82 ( V_176 , sizeof( * error -> V_93 ) , V_122 ) ;
error -> V_92 = F_82 ( V_176 , sizeof( * error -> V_92 ) ,
V_122 ) ;
error -> V_94 = F_82 ( V_176 , sizeof( * error -> V_94 ) ,
V_122 ) ;
F_48 (vm, &dev_priv->vm_list, global_link)
F_80 ( V_67 , error , V_152 , V_70 ++ ) ;
}
void F_83 ( struct V_41 * V_42 )
{
struct V_116 * V_67 = V_42 -> V_68 ;
struct V_43 * error ;
unsigned long V_123 ;
int V_177 ;
F_84 ( & V_67 -> V_178 . V_179 , V_123 ) ;
error = V_67 -> V_178 . V_180 ;
F_85 ( & V_67 -> V_178 . V_179 , V_123 ) ;
if ( error )
return;
error = F_86 ( sizeof( * error ) , V_122 ) ;
if ( ! error ) {
F_87 ( L_67 ) ;
return;
}
F_88 ( L_68
L_69 , V_42 -> V_181 -> V_182 ) ;
F_89 ( & error -> V_115 ) ;
error -> V_80 = F_55 ( V_183 ) ;
error -> V_82 = F_55 ( V_184 ) ;
if ( F_90 ( V_42 ) )
error -> V_85 = F_55 ( V_185 ) ;
if ( F_91 ( V_42 ) )
error -> V_81 = F_55 ( V_186 ) | F_55 ( V_187 ) ;
else if ( F_92 ( V_42 ) )
error -> V_81 = F_55 ( V_187 ) | F_55 ( V_188 ) ;
else if ( F_93 ( V_42 ) )
error -> V_81 = F_94 ( V_189 ) ;
else
error -> V_81 = F_55 ( V_189 ) ;
if ( F_20 ( V_42 ) -> V_52 >= 6 )
error -> V_84 = F_55 ( V_190 ) ;
if ( F_92 ( V_42 ) )
error -> V_83 = F_55 ( V_191 ) ;
else if ( F_20 ( V_42 ) -> V_52 >= 7 )
error -> V_83 = F_55 ( V_192 ) ;
else if ( F_20 ( V_42 ) -> V_52 == 6 )
error -> V_83 = F_55 ( V_193 ) ;
if ( ! F_91 ( V_42 ) )
F_95 ( V_177 )
error -> V_194 [ V_177 ] = F_55 ( F_96 ( V_177 ) ) ;
if ( F_20 ( V_42 ) -> V_52 >= 6 ) {
error -> error = F_55 ( V_195 ) ;
error -> V_89 = F_55 ( V_196 ) ;
}
if ( F_20 ( V_42 ) -> V_52 == 7 )
error -> V_90 = F_55 ( V_197 ) ;
F_97 ( V_42 , error -> V_88 ) ;
F_81 ( V_67 , error ) ;
F_50 ( V_42 , error ) ;
F_79 ( V_42 , error ) ;
F_98 ( & error -> time ) ;
error -> V_106 = F_99 ( V_42 ) ;
error -> V_107 = F_100 ( V_42 ) ;
F_84 ( & V_67 -> V_178 . V_179 , V_123 ) ;
if ( V_67 -> V_178 . V_180 == NULL ) {
V_67 -> V_178 . V_180 = error ;
error = NULL ;
}
F_85 ( & V_67 -> V_178 . V_179 , V_123 ) ;
if ( error )
F_32 ( & error -> V_115 ) ;
}
void F_101 ( struct V_41 * V_42 ,
struct V_65 * V_66 )
{
struct V_116 * V_67 = V_42 -> V_68 ;
unsigned long V_123 ;
F_84 ( & V_67 -> V_178 . V_179 , V_123 ) ;
V_66 -> error = V_67 -> V_178 . V_180 ;
if ( V_66 -> error )
F_102 ( & V_66 -> error -> V_115 ) ;
F_85 ( & V_67 -> V_178 . V_179 , V_123 ) ;
}
void F_103 ( struct V_65 * V_66 )
{
if ( V_66 -> error )
F_104 ( & V_66 -> error -> V_115 , F_32 ) ;
}
void F_105 ( struct V_41 * V_42 )
{
struct V_116 * V_67 = V_42 -> V_68 ;
struct V_43 * error ;
unsigned long V_123 ;
F_84 ( & V_67 -> V_178 . V_179 , V_123 ) ;
error = V_67 -> V_178 . V_180 ;
V_67 -> V_178 . V_180 = NULL ;
F_85 ( & V_67 -> V_178 . V_179 , V_123 ) ;
if ( error )
F_104 ( & error -> V_115 , F_32 ) ;
}
const char * F_17 ( int type )
{
switch ( type ) {
case V_198 : return L_70 ;
case V_199 : return L_71 ;
case V_200 : return L_72 ;
default: return L_7 ;
}
}
void F_97 ( struct V_41 * V_42 , T_7 * V_51 )
{
struct V_116 * V_67 = V_42 -> V_68 ;
memset ( V_51 , 0 , sizeof( * V_51 ) * V_201 ) ;
switch ( F_20 ( V_42 ) -> V_52 ) {
case 2 :
case 3 :
V_51 [ 0 ] = F_55 ( V_163 ) ;
break;
case 4 :
case 5 :
case 6 :
V_51 [ 0 ] = F_55 ( V_202 ) ;
V_51 [ 1 ] = F_55 ( V_203 ) ;
break;
default:
F_106 ( 1 , L_73 ) ;
case 7 :
V_51 [ 0 ] = F_55 ( V_204 ) ;
V_51 [ 1 ] = F_55 ( V_205 ) ;
V_51 [ 2 ] = F_55 ( V_206 ) ;
V_51 [ 3 ] = F_55 ( V_207 ) ;
break;
}
}
