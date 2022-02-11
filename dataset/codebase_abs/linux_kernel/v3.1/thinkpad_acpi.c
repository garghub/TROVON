static inline const char * F_1 ( int V_1 ) { return L_1 ; }
static void F_2 ( const char * const V_2 )
{
F_3 (KERN_DEBUG pr_fmt(L_2),
what, task_tgid_vnr(current)) ;
}
static unsigned long T_1 F_4 (
const struct V_3 * V_4 ,
unsigned int V_5 )
{
while ( V_5 ) {
if ( ( V_4 -> V_6 == V_7 . V_6 ||
V_4 -> V_6 == V_8 ) &&
( V_4 -> V_9 == V_7 . V_10 ||
V_4 -> V_9 == V_8 ) &&
( V_4 -> V_11 == V_7 . V_12 ||
V_4 -> V_11 == V_8 ) )
return V_4 -> V_13 ;
V_5 -- ;
V_4 ++ ;
}
return 0 ;
}
static inline bool T_2 T_1 F_5 ( void )
{
return V_7 . V_6 == V_14 ;
}
static inline bool T_2 T_1 F_6 ( void )
{
return V_7 . V_6 == V_15 ;
}
static int F_7 ( T_3 V_16 ,
void * V_17 , char * V_18 , char * V_19 , ... )
{
char * V_20 = V_19 ;
struct V_21 V_22 ;
union V_23 V_24 [ V_25 ] ;
struct V_26 V_27 , * V_28 ;
union V_23 V_29 ;
T_4 V_30 ;
T_5 V_31 ;
char V_32 ;
int V_33 ;
int V_34 ;
if ( ! * V_19 ) {
F_8 ( L_3 ) ;
return 0 ;
}
if ( * V_19 == 'q' ) {
V_34 = 1 ;
V_19 ++ ;
} else
V_34 = 0 ;
V_32 = * ( V_19 ++ ) ;
V_22 . V_35 = 0 ;
V_22 . V_36 = & V_24 [ 0 ] ;
va_start ( V_31 , V_19 ) ;
while ( * V_19 ) {
char V_37 = * ( V_19 ++ ) ;
switch ( V_37 ) {
case 'd' :
V_24 [ V_22 . V_35 ] . integer . V_38 = va_arg ( V_31 , int ) ;
V_24 [ V_22 . V_35 ++ ] . type = V_39 ;
break;
default:
F_8 ( L_4
L_5 , V_37 ) ;
va_end ( V_31 ) ;
return 0 ;
}
}
va_end ( V_31 ) ;
if ( V_32 != 'v' ) {
V_27 . V_40 = sizeof( V_29 ) ;
V_27 . V_36 = & V_29 ;
V_28 = & V_27 ;
} else
V_28 = NULL ;
V_30 = F_9 ( V_16 , V_18 , & V_22 , V_28 ) ;
switch ( V_32 ) {
case 'd' :
V_33 = ( V_30 == V_41 &&
V_29 . type == V_39 ) ;
if ( V_33 && V_17 )
* ( int * ) V_17 = V_29 . integer . V_38 ;
break;
case 'v' :
V_33 = V_30 == V_41 ;
break;
default:
F_8 ( L_4
L_5 , V_32 ) ;
return 0 ;
}
if ( ! V_33 && ! V_34 )
F_8 ( L_6 ,
V_18 , V_20 , F_10 ( V_30 ) ) ;
return V_33 ;
}
static int F_11 ( int V_42 , T_6 * V_43 )
{
int V_44 ;
if ( V_45 ) {
if ( ! F_7 ( V_45 , & V_44 , NULL , L_7 , V_42 ) )
return 0 ;
* V_43 = V_44 ;
} else {
if ( F_12 ( V_42 , V_43 ) < 0 )
return 0 ;
}
return 1 ;
}
static int F_13 ( int V_42 , T_6 V_44 )
{
if ( V_46 ) {
if ( ! F_7 ( V_46 , NULL , NULL , L_8 , V_42 , V_44 ) )
return 0 ;
} else {
if ( F_14 ( V_42 , V_44 ) < 0 )
return 0 ;
}
return 1 ;
}
static int F_15 ( int V_47 )
{
if ( ! V_48 )
return - V_49 ;
if ( ! F_7 ( V_48 , NULL , NULL , L_9 , V_47 ) )
return - V_50 ;
return 0 ;
}
static void T_1 F_16 ( const char * V_51 ,
T_3 * V_16 , const T_3 V_52 ,
char * * V_53 , const int V_54 )
{
int V_42 ;
T_4 V_30 ;
F_17 ( V_55 , L_10 ,
V_51 ) ;
for ( V_42 = 0 ; V_42 < V_54 ; V_42 ++ ) {
V_30 = F_18 ( V_52 , V_53 [ V_42 ] , V_16 ) ;
if ( F_19 ( V_30 ) ) {
F_20 ( V_55 ,
L_11 ,
V_53 [ V_42 ] , V_51 ) ;
return;
}
}
F_17 ( V_55 , L_12 ,
V_51 ) ;
* V_16 = NULL ;
}
static T_4 T_1 F_21 ( T_3 V_16 ,
T_7 V_56 , void * V_57 , void * * V_58 )
{
* ( T_3 * ) V_58 = V_16 ;
return V_59 ;
}
static void T_1 F_22 ( const char * V_51 ,
const char * V_60 ,
T_3 * V_16 )
{
T_4 V_30 ;
T_3 V_61 ;
F_23 ( ! V_51 || ! V_60 || ! V_16 ) ;
F_17 ( V_55 ,
L_13 ,
V_51 , V_60 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_30 = F_24 ( V_60 , F_21 ,
( void * ) V_51 , & V_61 ) ;
* V_16 = NULL ;
if ( F_19 ( V_30 ) ) {
* V_16 = V_61 ;
F_20 ( V_55 ,
L_14 , V_51 ) ;
} else {
F_17 ( V_55 ,
L_15 ,
V_51 , F_10 ( V_30 ) ) ;
}
}
static void F_25 ( T_3 V_16 , T_7 V_62 , void * V_63 )
{
struct V_64 * V_65 = V_63 ;
if ( V_66 != V_67 )
return;
if ( ! V_65 || ! V_65 -> V_68 || ! V_65 -> V_68 -> V_69 )
return;
V_65 -> V_68 -> V_69 ( V_65 , V_62 ) ;
}
static int T_1 F_26 ( struct V_64 * V_65 )
{
T_4 V_30 ;
int V_70 ;
F_23 ( ! V_65 -> V_68 ) ;
if ( ! * V_65 -> V_68 -> V_16 )
return 0 ;
F_17 ( V_55 ,
L_16 , V_65 -> V_51 ) ;
V_70 = F_27 ( * V_65 -> V_68 -> V_16 , & V_65 -> V_68 -> V_71 ) ;
if ( V_70 < 0 ) {
F_8 ( L_17 , V_65 -> V_51 , V_70 ) ;
return - V_72 ;
}
V_65 -> V_68 -> V_71 -> V_73 = V_65 ;
sprintf ( F_28 ( V_65 -> V_68 -> V_71 ) , L_18 ,
V_74 ,
V_65 -> V_51 ) ;
V_30 = F_29 ( * V_65 -> V_68 -> V_16 ,
V_65 -> V_68 -> type , F_25 , V_65 ) ;
if ( F_30 ( V_30 ) ) {
if ( V_30 == V_75 ) {
F_31 ( L_19
L_20 , V_65 -> V_51 ) ;
} else {
F_8 ( L_21 ,
V_65 -> V_51 , F_10 ( V_30 ) ) ;
}
return - V_72 ;
}
V_65 -> V_76 . V_77 = 1 ;
return 0 ;
}
static int T_1 F_32 ( struct V_78 * V_71 )
{
return 0 ;
}
static int T_1 F_33 ( struct V_64 * V_65 )
{
int V_70 ;
F_20 ( V_55 ,
L_22 , V_65 -> V_51 ) ;
F_23 ( ! V_65 -> V_68 ) ;
V_65 -> V_68 -> V_79 = F_34 ( sizeof( struct V_80 ) , V_81 ) ;
if ( ! V_65 -> V_68 -> V_79 ) {
F_8 ( L_23 ) ;
return - V_82 ;
}
sprintf ( V_65 -> V_68 -> V_79 -> V_51 , L_24 , V_83 , V_65 -> V_51 ) ;
V_65 -> V_68 -> V_79 -> V_84 = V_65 -> V_68 -> V_60 ;
V_65 -> V_68 -> V_79 -> V_85 . V_86 = & F_32 ;
V_70 = F_35 ( V_65 -> V_68 -> V_79 ) ;
if ( V_70 < 0 ) {
F_8 ( L_25 ,
V_65 -> V_51 , V_70 ) ;
F_36 ( V_65 -> V_68 -> V_79 ) ;
V_65 -> V_68 -> V_79 = NULL ;
} else if ( ! V_70 )
V_65 -> V_76 . V_87 = 1 ;
return V_70 ;
}
static int F_37 ( struct V_88 * V_89 , void * V_44 )
{
struct V_64 * V_65 = V_89 -> V_90 ;
if ( ! V_65 || ! V_65 -> V_91 )
return - V_92 ;
return V_65 -> V_91 ( V_89 ) ;
}
static int F_38 ( struct V_93 * V_93 , struct V_94 * V_94 )
{
return F_39 ( V_94 , F_37 , F_40 ( V_93 ) -> V_63 ) ;
}
static T_8 F_41 ( struct V_94 * V_94 ,
const char T_9 * V_95 ,
T_10 V_35 , T_11 * V_96 )
{
struct V_64 * V_65 = F_40 ( V_94 -> V_97 . V_98 -> V_99 ) -> V_63 ;
char * V_100 ;
int V_101 ;
if ( ! V_65 || ! V_65 -> V_102 )
return - V_92 ;
if ( V_35 > V_103 - 2 )
return - V_92 ;
V_100 = F_42 ( V_35 + 2 , V_81 ) ;
if ( ! V_100 )
return - V_82 ;
if ( F_43 ( V_100 , V_95 , V_35 ) ) {
F_36 ( V_100 ) ;
return - V_104 ;
}
V_100 [ V_35 ] = 0 ;
strcat ( V_100 , L_26 ) ;
V_101 = V_65 -> V_102 ( V_100 ) ;
if ( V_101 == 0 )
V_101 = V_35 ;
F_36 ( V_100 ) ;
return V_101 ;
}
static char * F_44 ( char * * V_105 )
{
char * V_106 = * V_105 ;
char * V_107 ;
while ( ( V_107 = strchr ( V_106 , ',' ) ) && V_107 == V_106 )
V_106 = V_107 + 1 ;
if ( ! V_107 )
return NULL ;
* V_107 = 0 ;
* V_105 = V_107 + 1 ;
return V_106 ;
}
static int F_45 ( struct V_108 * V_109 ,
T_12 V_110 )
{
struct V_64 * V_65 , * V_111 ;
F_46 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if ( V_65 -> V_112 )
( V_65 -> V_112 ) ( V_110 ) ;
}
return 0 ;
}
static int F_47 ( struct V_108 * V_109 )
{
struct V_64 * V_65 , * V_111 ;
F_46 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if ( V_65 -> V_113 )
( V_65 -> V_113 ) ( ) ;
}
return 0 ;
}
static void F_48 ( struct V_108 * V_109 )
{
struct V_64 * V_65 , * V_111 ;
F_46 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if ( V_65 -> V_114 )
( V_65 -> V_114 ) ( ) ;
}
}
static struct V_115 * F_49 ( unsigned int V_116 ,
const char * V_51 )
{
struct V_117 * V_118 ;
if ( V_116 == 0 )
return NULL ;
V_118 = F_34 ( sizeof( struct V_117 ) +
V_116 * sizeof( struct V_119 * ) ,
V_81 ) ;
if ( ! V_118 )
return NULL ;
V_118 -> V_120 . V_116 = V_116 ;
V_118 -> V_120 . V_121 . V_122 = & V_118 -> V_123 ;
V_118 -> V_120 . V_121 . V_51 = V_51 ;
return & V_118 -> V_120 ;
}
static int F_50 ( struct V_115 * V_120 , struct V_119 * V_124 )
{
if ( ! V_120 || ! V_124 )
return - V_92 ;
if ( V_120 -> V_125 >= V_120 -> V_116 )
return - V_82 ;
V_120 -> V_121 . V_122 [ V_120 -> V_125 ] = V_124 ;
V_120 -> V_125 ++ ;
return 0 ;
}
static int F_51 ( struct V_115 * V_120 ,
struct V_119 * * V_124 ,
unsigned int V_35 )
{
int V_42 , V_17 ;
for ( V_42 = 0 ; V_42 < V_35 ; V_42 ++ ) {
V_17 = F_50 ( V_120 , V_124 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static void F_52 ( struct V_115 * V_120 , struct V_126 * V_127 )
{
F_53 ( V_127 , & V_120 -> V_121 ) ;
F_54 ( V_120 ) ;
}
static int F_55 ( const char * V_128 ,
unsigned long V_129 , unsigned long * V_38 )
{
char * V_130 ;
* V_38 = F_56 ( F_57 ( V_128 ) , & V_130 , 0 ) ;
V_130 = F_57 ( V_130 ) ;
if ( * V_130 || * V_38 > V_129 )
return - V_92 ;
return 0 ;
}
static void F_58 ( void )
{
if ( F_7 ( V_131 , NULL , L_27 , L_28 , 0 ) )
F_31 ( L_29 ) ;
}
static void F_59 ( const char * const V_2 ,
const char * const V_132 )
{
F_2 ( L_30 ) ;
F_60 ( L_31
L_32 ,
V_2 , V_132 ) ;
}
static int F_61 ( const struct V_133 * V_134 )
{
int V_30 ;
if ( ! V_134 )
return - V_72 ;
V_30 = ( V_134 -> V_85 -> V_135 ) ( ) ;
if ( V_30 < 0 )
return V_30 ;
F_62 ( V_134 -> V_136 ,
( V_30 == V_137 ) ) ;
return V_30 ;
}
static void F_63 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_138 ; V_42 ++ )
F_61 ( V_139 [ V_42 ] ) ;
}
static void F_64 ( bool V_140 )
{
unsigned int V_42 ;
struct V_133 * V_134 ;
for ( V_42 = 0 ; V_42 < V_138 ; V_42 ++ ) {
V_134 = V_139 [ V_42 ] ;
if ( V_134 ) {
if ( F_65 ( V_134 -> V_136 ,
V_140 ) ) {
}
}
}
}
static bool F_66 ( void )
{
int V_17 = F_67 () ;
int V_141 ;
if ( V_17 < 0 )
return false ;
V_141 = ( V_17 == V_137 ) ;
F_64 ( V_141 ) ;
return V_141 ;
}
static int F_68 ( void * V_63 , bool V_140 )
{
struct V_133 * V_134 = V_63 ;
int V_17 ;
F_20 ( V_142 ,
L_33 ,
V_140 ? L_34 : L_35 ) ;
V_17 = ( V_134 -> V_85 -> V_143 ) ( V_140 ?
V_137 : V_144 ) ;
F_61 ( V_134 ) ;
return ( V_17 < 0 ) ? V_17 : 0 ;
}
static int T_1 F_69 ( const enum V_145 V_146 ,
const struct V_147 * V_148 ,
const enum V_149 V_150 ,
const char * V_51 ,
const bool V_151 )
{
struct V_133 * V_152 ;
int V_17 ;
bool V_153 = false ;
bool V_154 ;
int V_155 ;
F_23 ( V_146 >= V_138 || V_139 [ V_146 ] ) ;
V_152 = F_34 ( sizeof( struct V_133 ) , V_81 ) ;
if ( V_152 )
V_152 -> V_136 = F_70 ( V_51 ,
& V_156 -> V_157 ,
V_150 ,
& V_158 ,
V_152 ) ;
if ( ! V_152 || ! V_152 -> V_136 ) {
F_8 ( L_36 ) ;
F_36 ( V_152 ) ;
return - V_82 ;
}
V_152 -> V_146 = V_146 ;
V_152 -> V_85 = V_148 ;
V_155 = ( V_148 -> V_135 ) ( ) ;
if ( V_155 < 0 ) {
F_8 ( L_37 ,
V_51 , V_155 ) ;
} else {
V_153 = ( V_155 == V_137 ) ;
if ( V_151 ) {
F_71 ( V_152 -> V_136 , V_153 ) ;
}
}
V_154 = F_66 () ;
F_65 ( V_152 -> V_136 , V_154 ) ;
V_17 = F_72 ( V_152 -> V_136 ) ;
if ( V_17 < 0 ) {
F_8 ( L_38 , V_51 , V_17 ) ;
F_73 ( V_152 -> V_136 ) ;
F_36 ( V_152 ) ;
return V_17 ;
}
V_139 [ V_146 ] = V_152 ;
F_74 ( L_39 ,
V_51 , ( V_153 || V_154 ) ? L_1 : L_40 ) ;
return 0 ;
}
static void F_75 ( const enum V_145 V_146 )
{
struct V_133 * V_134 ;
F_23 ( V_146 >= V_138 ) ;
V_134 = V_139 [ V_146 ] ;
if ( V_134 ) {
F_76 ( V_134 -> V_136 ) ;
F_73 ( V_134 -> V_136 ) ;
V_139 [ V_146 ] = NULL ;
F_36 ( V_134 ) ;
}
}
static void F_77 ( const char * const V_2 )
{
F_59 ( V_2 ,
L_41 ) ;
}
static T_8 F_78 ( const enum V_145 V_146 ,
struct V_159 * V_124 ,
char * V_128 )
{
int V_30 ;
F_77 ( V_124 -> V_124 . V_51 ) ;
if ( F_66 () ) {
V_30 = V_137 ;
} else {
V_30 = F_61 ( V_139 [ V_146 ] ) ;
if ( V_30 < 0 )
return V_30 ;
}
return snprintf ( V_128 , V_103 , L_42 ,
( V_30 == V_144 ) ? 1 : 0 ) ;
}
static T_8 F_79 ( const enum V_145 V_146 ,
struct V_159 * V_124 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
int V_17 ;
F_77 ( V_124 -> V_124 . V_51 ) ;
if ( F_55 ( V_128 , 1 , & V_160 ) )
return - V_92 ;
F_80 ( V_124 -> V_124 . V_51 , L_43 , V_160 ) ;
if ( F_66 () && ! ! V_160 )
return - V_161 ;
V_17 = V_139 [ V_146 ] -> V_85 -> V_143 ( ( ! ! V_160 ) ?
V_144 : V_137 ) ;
F_61 ( V_139 [ V_146 ] ) ;
return ( V_17 < 0 ) ? V_17 : V_35 ;
}
static int F_81 ( const enum V_145 V_146 , struct V_88 * V_89 )
{
if ( V_146 >= V_138 )
F_82 ( V_89 , L_44 ) ;
else {
int V_30 ;
if ( F_66 () ) {
V_30 = V_137 ;
} else {
V_30 = F_61 (
V_139 [ V_146 ] ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_82 ( V_89 , L_45 ,
( V_30 == V_144 ) ?
L_46 : L_47 ) ;
F_82 ( V_89 , L_48 ) ;
}
return 0 ;
}
static int F_83 ( const enum V_145 V_146 , char * V_128 )
{
char * V_162 ;
int V_30 = - 1 ;
int V_17 = 0 ;
if ( V_146 >= V_138 )
return - V_72 ;
while ( ( V_162 = F_44 ( & V_128 ) ) ) {
if ( F_84 ( V_162 , L_49 ) == 0 )
V_30 = V_144 ;
else if ( F_84 ( V_162 , L_50 ) == 0 )
V_30 = V_137 ;
else
return - V_92 ;
}
if ( V_30 != - 1 ) {
F_80 ( L_51 , L_52 ,
( V_30 == V_144 ) ?
L_49 : L_50 ,
V_163 [ V_146 ] ) ;
V_17 = ( V_139 [ V_146 ] -> V_85 -> V_143 ) ( V_30 ) ;
F_61 ( V_139 [ V_146 ] ) ;
}
return V_17 ;
}
static T_8 F_85 (
struct V_164 * V_165 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_53 , V_166 ) ;
}
static T_8 F_86 ( struct V_164 * V_165 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_54 , V_167 ) ;
}
static T_8 F_87 ( struct V_164 * V_165 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
if ( F_55 ( V_128 , 0xffff , & V_160 ) )
return - V_92 ;
V_167 = V_160 ;
return V_35 ;
}
static T_8 F_88 ( struct V_164 * V_165 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_55 ,
V_168 , V_169 ) ;
}
static T_8 F_89 ( struct V_164 * V_165 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_42 , ! ! V_170 ) ;
}
static T_8 F_90 ( struct V_164 * V_165 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
if ( F_55 ( V_128 , 1 , & V_160 ) )
return - V_92 ;
if ( V_170 != ! ! V_160 ) {
V_170 = ! ! V_160 ;
F_64 ( ! V_160 ) ;
}
return V_35 ;
}
static T_8 F_91 (
struct V_164 * V_165 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_42 , ! ! V_171 ) ;
}
static T_8 F_92 (
struct V_164 * V_165 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
if ( F_55 ( V_128 , 1 , & V_160 ) )
return - V_92 ;
V_171 = ! ! V_160 ;
return V_35 ;
}
static T_8 F_93 (
struct V_164 * V_165 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_42 , ! ! V_172 ) ;
}
static T_8 F_94 (
struct V_164 * V_165 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
if ( F_55 ( V_128 , 1 , & V_160 ) )
return - V_92 ;
V_172 = ! ! V_160 ;
return V_35 ;
}
static T_8 F_95 (
struct V_164 * V_165 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_42 , ! ! V_173 ) ;
}
static T_8 F_96 (
struct V_164 * V_165 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
if ( F_55 ( V_128 , 1 , & V_160 ) )
return - V_92 ;
V_173 = ! ! V_160 ;
return V_35 ;
}
static int T_1 F_97 ( struct V_164 * V_165 )
{
int V_42 , V_17 ;
V_42 = 0 ;
V_17 = 0 ;
while ( ! V_17 && V_42 < F_98 ( V_174 ) ) {
V_17 = F_99 ( V_165 , V_174 [ V_42 ] ) ;
V_42 ++ ;
}
#ifdef F_100
if ( ! V_17 && V_175 )
V_17 = F_99 ( V_165 , & V_176 ) ;
if ( ! V_17 && V_177 )
V_17 = F_99 ( V_165 , & V_178 ) ;
if ( ! V_17 && V_179 )
V_17 = F_99 ( V_165 , & V_180 ) ;
if ( ! V_17 && V_181 )
V_17 = F_99 ( V_165 , & V_182 ) ;
#endif
return V_17 ;
}
static void F_101 ( struct V_164 * V_165 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_98 ( V_174 ) ; V_42 ++ )
F_102 ( V_165 , V_174 [ V_42 ] ) ;
#ifdef F_103
F_102 ( V_165 , & V_176 ) ;
F_102 ( V_165 , & V_178 ) ;
F_102 ( V_165 , & V_180 ) ;
F_102 ( V_165 , & V_182 ) ;
#endif
}
static void T_1 F_104 ( void )
{
unsigned long V_183 ;
T_13 V_184 , V_185 ;
V_183 = F_4 ( V_186 ,
F_98 ( V_186 ) ) ;
if ( ! V_183 )
return;
V_185 = V_183 & 0xffffU ;
V_184 = ( V_183 >> 16 ) & 0xffffU ;
if ( ( V_185 > V_7 . V_187 ) ||
( V_184 > V_7 . V_188 &&
V_184 != V_8 ) ) {
F_60 ( L_56 ) ;
F_60 ( L_57
L_58 ) ;
}
}
static bool T_1 F_105 ( void )
{
return F_4 ( V_186 ,
F_98 ( V_186 ) ) != 0 ;
}
static int F_106 ( struct V_88 * V_89 )
{
F_82 ( V_89 , L_59 , V_168 ) ;
F_82 ( V_89 , L_60 , V_169 ) ;
return 0 ;
}
static int F_67 ( void )
{
int V_30 ;
if ( ! V_189 . V_190 )
return - V_72 ;
#ifdef F_100
if ( V_175 )
return ( V_170 ) ?
V_144 : V_137 ;
#endif
if ( ! F_7 ( V_131 , & V_30 , L_61 , L_62 ) )
return - V_50 ;
return ( V_30 ) ? V_144 : V_137 ;
}
static int F_107 ( int * V_30 )
{
int V_120 ;
if ( ! F_7 ( V_131 , & V_120 , L_63 , L_62 ) )
return - V_50 ;
* V_30 = ( ( V_120 & V_191 ) != 0 ) ;
return 0 ;
}
static int F_108 ( void )
{
if ( V_189 . V_192 ) {
T_7 V_89 = 0 ;
if ( ! F_7 ( V_131 , & V_89 , L_64 , L_62 ) )
return - V_50 ;
V_193 = V_89 ;
} else {
V_193 = V_194 ;
}
V_195 &= ( V_193 | V_196 ) ;
return 0 ;
}
void static F_109 ( void )
{
const T_7 V_197 = V_198 &
~ ( V_193 | V_196 ) &
( V_194 | V_199 ) ;
if ( V_197 )
F_31 ( L_65 , V_197 ) ;
}
static int F_110 ( T_7 V_200 )
{
int V_42 ;
int V_70 = 0 ;
const T_7 V_201 = V_200 & ~ V_196 ;
if ( V_189 . V_192 ) {
for ( V_42 = 0 ; V_42 < 32 ; V_42 ++ ) {
if ( ! F_7 ( V_131 ,
NULL , L_66 , L_8 , V_42 + 1 ,
! ! ( V_200 & ( 1 << V_42 ) ) ) ) {
V_70 = - V_50 ;
break;
}
}
}
if ( ! F_108 () && ! V_70 && ( V_201 & ~ V_193 ) ) {
F_31 ( L_67
L_68 ,
V_201 , V_193 ) ;
}
if ( V_66 != V_202 )
F_109 () ;
return V_70 ;
}
static int F_111 ( const T_7 V_200 )
{
int V_70 ;
if ( ! V_203 . V_204 &&
( V_200 == 0xffff || V_200 == 0xffffff ||
V_200 == 0xffffffff ) ) {
V_203 . V_204 = 1 ;
F_31 ( L_69
L_70 , V_200 ) ;
F_31 ( L_71
L_72
L_73 ) ;
}
V_70 = F_110 ( ( V_200 | V_198 ) & ~ V_196 ) ;
V_195 = V_200 & ( V_193 | V_196 ) ;
return V_70 ;
}
static int F_112 ( const T_7 V_200 )
{
int V_70 ;
if ( ! V_189 . V_205 ) {
V_198 = V_200 ;
return 0 ;
}
F_113 ( & V_206 ) ;
T_14
V_198 = V_200 ;
#ifdef F_114
V_196 |= ( V_200 & ~ V_194 ) ;
#endif
T_15
V_70 = F_110 ( ( V_193 | V_198 ) &
~ V_196 ) ;
F_115 ( true ) ;
F_116 ( & V_206 ) ;
return V_70 ;
}
static int F_117 ( int * V_30 )
{
if ( ! F_7 ( V_131 , V_30 , L_74 , L_62 ) )
return - V_50 ;
return 0 ;
}
static int F_118 ( bool V_207 )
{
if ( ! F_7 ( V_131 , NULL , L_75 , L_9 , V_207 ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static void F_119 ( void )
{
int V_110 ;
if ( V_189 . V_208 &&
! F_107 ( & V_110 ) ) {
F_113 ( & V_209 ) ;
F_120 ( V_210 ,
V_211 , ! ! V_110 ) ;
F_121 ( V_210 ) ;
F_116 ( & V_209 ) ;
}
}
static void F_122 ( const unsigned int V_212 )
{
const unsigned int V_213 = V_214 [ V_212 ] ;
if ( V_213 != V_215 ) {
F_113 ( & V_209 ) ;
F_123 ( V_210 , V_216 , V_217 , V_212 ) ;
F_124 ( V_210 , V_213 , 1 ) ;
F_121 ( V_210 ) ;
F_123 ( V_210 , V_216 , V_217 , V_212 ) ;
F_124 ( V_210 , V_213 , 0 ) ;
F_121 ( V_210 ) ;
F_116 ( & V_209 ) ;
}
}
static void F_125 ( const unsigned int V_212 )
{
F_126 ( V_212 ) ;
if ( V_195 & ( 1 << V_212 ) )
F_122 ( V_212 ) ;
}
static void F_127 ( unsigned int V_212 )
{
F_125 ( V_212 ) ;
if ( V_218 < 2 ) {
F_128 ( V_219 . V_71 ,
0x80 , V_220 + V_212 ) ;
}
}
static void F_129 ( struct V_221 * V_222 , const T_7 V_89 )
{
T_6 V_223 ;
if ( V_89 & V_224 ) {
V_223 = F_130 ( V_225 ) ;
V_222 -> V_226 = ! ! ( V_223 & V_227 ) ;
V_222 -> V_228 = ! ! ( V_223 & V_229 ) ;
V_222 -> V_230 = ! ! ( V_223 & V_231 ) ;
V_222 -> V_232 = ! ! ( V_223 & V_233 ) ;
}
if ( V_89 & V_234 ) {
V_223 = F_130 ( V_235 ) ;
V_222 -> V_236 = ! ! ( V_223 & V_237 ) ;
}
if ( V_89 & V_238 ) {
V_223 = F_130 ( V_239 ) ;
V_222 -> V_240 =
! ! ( V_223 & V_241 ) ;
}
if ( V_89 & V_242 ) {
V_223 = F_130 ( V_243 ) ;
V_222 -> V_244 = ( V_223 & V_245 )
>> V_246 ;
V_222 -> V_247 =
! ! ( V_223 & V_248 ) ;
}
if ( V_89 & V_249 ) {
V_223 = F_130 ( V_250 ) ;
V_222 -> V_251 = ( V_223 & V_252 )
>> V_253 ;
V_222 -> V_254 = ! ! ( V_223 & V_255 ) ;
V_222 -> V_256 = ! ! ( V_223 & V_257 ) ;
}
}
void F_131 ( const unsigned int V_258 ,
const unsigned int V_259 )
{
unsigned int V_42 = V_258 ;
while ( V_42 > V_259 ) {
F_132 ( V_260 ) ;
V_42 -- ;
}
while ( V_42 < V_259 ) {
F_132 ( V_261 ) ;
V_42 ++ ;
}
}
void F_133 ( const unsigned int V_262 ,
const unsigned int V_263 )
{
unsigned int V_42 = V_262 ;
while ( V_42 > V_263 ) {
F_132 ( V_264 ) ;
V_42 -- ;
}
while ( V_42 < V_263 ) {
F_132 ( V_265 ) ;
V_42 ++ ;
}
}
static int F_134 ( void * V_63 )
{
struct V_221 V_120 [ 2 ] ;
T_7 V_266 , V_267 ;
unsigned int V_268 , V_269 ;
unsigned long V_160 ;
unsigned int V_270 , V_271 ;
unsigned int V_272 ;
F_113 ( & V_273 ) ;
if ( V_66 == V_202 )
goto exit;
F_135 () ;
V_269 = 0 ;
V_268 = 1 ;
V_160 = 0 ;
F_113 ( & V_274 ) ;
V_270 = V_275 ;
V_266 = V_196 ;
V_267 = V_196 &
( V_198 | V_195 ) ;
V_272 = V_276 ;
F_116 ( & V_274 ) ;
F_129 ( & V_120 [ V_269 ] , V_266 ) ;
while ( ! F_136 () ) {
if ( V_160 == 0 ) {
if ( F_137 ( V_272 ) )
V_160 = 1000 / V_272 ;
else
V_160 = 100 ;
}
V_160 = F_138 ( V_160 ) ;
if ( F_139 ( F_136 () ) )
break;
V_271 = F_140 () ;
if ( V_160 > 0 && ! V_271 )
continue;
F_113 ( & V_274 ) ;
if ( V_271 || V_275 != V_270 ) {
V_268 = V_269 ;
V_160 = 0 ;
V_270 = V_275 ;
}
V_266 = V_196 ;
V_267 = V_196 &
( V_198 | V_195 ) ;
V_272 = V_276 ;
F_116 ( & V_274 ) ;
if ( F_137 ( V_266 ) ) {
F_129 ( & V_120 [ V_268 ] , V_266 ) ;
if ( F_137 ( V_268 != V_269 ) ) {
F_141 ( & V_120 [ V_269 ] , & V_120 [ V_268 ] ,
V_267 ) ;
}
}
V_269 = V_268 ;
V_268 ^= 1 ;
}
exit:
F_116 ( & V_273 ) ;
return 0 ;
}
static void F_142 ( void )
{
if ( V_277 ) {
if ( F_143 ( V_277 ) ||
F_144 ( V_277 ) )
F_145 ( V_277 ) ;
F_146 ( V_277 ) ;
V_277 = NULL ;
F_113 ( & V_273 ) ;
F_116 ( & V_273 ) ;
}
}
static void F_115 ( const bool V_278 )
{
const T_7 V_279 = V_198 & V_196 ;
const T_7 V_280 = V_195 & V_196 ;
if ( V_276 > 0 &&
( V_279 ||
( V_280 && V_210 -> V_281 > 0 ) ) ) {
if ( ! V_277 ) {
V_277 = F_147 ( F_134 ,
NULL , V_282 ) ;
if ( F_148 ( V_277 ) ) {
V_277 = NULL ;
F_8 ( L_76
L_77 ) ;
}
}
} else {
F_142 () ;
if ( V_278 && ( V_279 || V_280 ) &&
V_276 == 0 ) {
F_31 ( L_78
L_79
L_80 ,
V_280 , V_279 ) ;
}
}
}
static void F_149 ( const bool V_278 )
{
F_113 ( & V_206 ) ;
F_115 ( V_278 ) ;
F_116 ( & V_206 ) ;
}
static void F_150 ( unsigned int V_283 )
{
if ( ! V_283 )
F_142 () ;
V_276 = V_283 ;
}
static void F_115 ( const bool V_284 )
{
}
static void F_149 ( const bool V_284 )
{
}
static int F_151 ( struct V_285 * V_157 )
{
switch ( V_66 ) {
case V_286 :
case V_67 :
F_149 ( false ) ;
return 0 ;
case V_202 :
return - V_287 ;
}
F_152 () ;
return - V_287 ;
}
static void F_153 ( struct V_285 * V_157 )
{
if ( V_66 != V_202 &&
! ( V_196 & V_198 ) )
F_149 ( false ) ;
}
static T_8 F_154 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
int V_17 , V_30 ;
F_59 ( L_81 ,
L_82 ) ;
V_17 = F_117 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
return snprintf ( V_128 , V_103 , L_42 , V_30 ) ;
}
static T_8 F_155 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
F_59 ( L_81 ,
L_83 ) ;
if ( F_55 ( V_128 , 1 , & V_160 ) )
return - V_92 ;
if ( V_160 == 0 )
return - V_161 ;
return V_35 ;
}
static T_8 F_156 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_53 , V_195 ) ;
}
static T_8 F_157 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
int V_17 ;
if ( F_55 ( V_128 , 0xffffffffUL , & V_160 ) )
return - V_92 ;
if ( F_158 ( & V_206 ) )
return - V_288 ;
V_17 = F_111 ( V_160 ) ;
#ifdef F_114
F_115 ( true ) ;
#endif
F_116 ( & V_206 ) ;
F_80 ( L_84 , L_85 , V_160 ) ;
return ( V_17 ) ? V_17 : V_35 ;
}
static T_8 F_159 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return sprintf ( V_128 , L_86 ) ;
}
static T_8 F_160 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
F_59 ( L_87 ,
L_88 ) ;
return snprintf ( V_128 , V_103 , L_53 , V_289 ) ;
}
static T_8 F_161 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_53 ,
V_194 | V_196 ) ;
}
static T_8 F_162 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_53 ,
( V_194 | V_196 )
& ~ V_290 ) ;
}
static T_8 F_163 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_53 , V_196 ) ;
}
static T_8 F_164 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
T_7 V_291 ;
int V_70 ;
if ( F_55 ( V_128 , 0xffffffffUL , & V_160 ) ||
( ( V_160 & ~ V_199 ) != 0 ) )
return - V_92 ;
if ( F_158 ( & V_206 ) )
return - V_288 ;
T_14
V_196 = V_160 ;
T_15
V_70 = F_110 ( ( V_195 | V_198 ) &
~ V_196 ) ;
F_115 ( true ) ;
V_291 = V_198 & ~ ( V_193 & V_194 )
& ~ V_196 & V_199 ;
F_116 ( & V_206 ) ;
if ( V_70 < 0 )
F_8 ( L_89
L_90 ) ;
if ( V_291 )
F_31 ( L_89
L_91 ,
V_291 ) ;
F_80 ( L_92 , L_85 , V_160 ) ;
return ( V_70 < 0 ) ? V_70 : V_35 ;
}
static T_8 F_165 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_42 , V_276 ) ;
}
static T_8 F_166 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
if ( F_55 ( V_128 , 25 , & V_160 ) )
return - V_92 ;
if ( F_158 ( & V_206 ) )
return - V_288 ;
F_150 ( V_160 ) ;
F_115 ( true ) ;
F_116 ( & V_206 ) ;
F_80 ( L_93 , L_94 , V_160 ) ;
return V_35 ;
}
static T_8 F_167 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
int V_17 ;
V_17 = F_67 () ;
if ( V_17 < 0 )
return V_17 ;
F_64 ( ( V_17 == V_137 ) ) ;
return snprintf ( V_128 , V_103 , L_42 ,
( V_17 == V_137 ) ? 0 : 1 ) ;
}
static void F_168 ( void )
{
if ( V_189 . V_190 )
F_169 ( & V_156 -> V_157 . V_127 , NULL ,
L_95 ) ;
}
static T_8 F_170 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
int V_17 , V_120 ;
V_17 = F_107 ( & V_120 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_128 , V_103 , L_42 , ! ! V_120 ) ;
}
static void F_171 ( void )
{
if ( V_189 . V_208 )
F_169 ( & V_156 -> V_157 . V_127 , NULL ,
L_96 ) ;
}
static T_8 F_172 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_42 ,
( V_218 != 0 ) ? V_218 : 1 ) ;
}
static T_8 F_173 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_42 , V_292 ) ;
}
static void F_174 ( void )
{
F_169 ( & V_156 -> V_157 . V_127 , NULL ,
L_97 ) ;
}
static T_8 F_175 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_42 , V_293 ) ;
}
static void F_176 ( void )
{
F_169 ( & V_156 -> V_157 . V_127 , NULL ,
L_98 ) ;
}
static void F_177 ( void )
{
int V_294 ;
V_294 = F_67 () ;
if ( V_294 == V_137 )
F_64 ( true ) ;
F_63 () ;
if ( V_294 == V_144 )
F_64 ( false ) ;
if ( ! ( V_294 < 0 ) ) {
F_113 ( & V_209 ) ;
F_120 ( V_210 ,
V_295 , ( V_294 > 0 ) ) ;
F_121 ( V_210 ) ;
F_116 ( & V_209 ) ;
}
F_168 () ;
}
static void F_178 ( void )
{
#ifdef F_114
F_113 ( & V_206 ) ;
F_142 () ;
F_116 ( & V_206 ) ;
#endif
if ( V_296 )
F_52 ( V_296 , & V_156 -> V_157 . V_127 ) ;
F_36 ( V_214 ) ;
F_20 ( V_297 | V_298 ,
L_99 ) ;
if ( ( ( V_189 . V_192 &&
F_110 ( V_289 ) ) |
F_118 ( false ) ) != 0 )
F_8 ( L_100
L_101 ) ;
}
static void T_1 F_179 ( const unsigned int V_212 )
{
if ( V_214 [ V_212 ] != V_215 ) {
F_180 ( V_214 [ V_212 ] ,
V_210 -> V_299 ) ;
V_214 [ V_212 ] = V_215 ;
}
}
static int T_1 F_181 ( struct V_300 * V_301 )
{
enum T_16 {
V_302 = 0 ,
V_303 ,
};
static const T_17 V_304 [] V_305 = {
[ V_302 ] = {
V_306 , V_307 , V_308 , V_309 ,
V_310 , V_311 , V_312 , V_313 ,
V_314 , V_315 , V_316 , V_317 ,
V_318 ,
V_318 ,
V_318 ,
V_215 ,
V_215 ,
V_215 ,
V_318 ,
V_319 ,
V_215 ,
V_215 ,
V_215 ,
V_320 ,
V_318 , V_318 , V_318 , V_318 ,
V_318 , V_318 , V_318 , V_318 ,
} ,
[ V_303 ] = {
V_306 , V_308 , V_307 , V_309 ,
V_310 , V_321 , V_312 , V_313 ,
V_314 , V_315 , V_316 , V_317 ,
V_318 ,
V_318 ,
V_318 ,
V_322 ,
V_323 ,
V_215 ,
V_318 ,
V_319 ,
V_215 ,
V_215 ,
V_215 ,
V_320 ,
V_318 , V_318 ,
V_324 ,
V_318 , V_318 , V_318 , V_318 ,
V_318 ,
} ,
} ;
static const struct V_3 V_325 [] V_305 = {
{
. V_6 = V_15 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_302 ,
} ,
{
. V_6 = V_14 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_303 ,
} ,
} ;
#define F_182 sizeof(tpacpi_keymap_t)
#define F_183 sizeof(tpacpi_keymap_entry_t)
int V_17 , V_42 ;
int V_30 ;
int V_326 ;
bool V_327 = false ;
bool V_328 = false ;
unsigned long V_13 ;
unsigned long V_329 ;
F_17 ( V_55 | V_298 ,
L_102 ) ;
F_23 ( ! V_210 ) ;
F_23 ( V_210 -> V_330 != NULL ||
V_210 -> V_331 != NULL ) ;
F_184 ( V_332 ) ;
F_185 ( & V_206 ) ;
#ifdef F_114
F_185 ( & V_273 ) ;
F_185 ( & V_274 ) ;
#endif
V_189 . V_205 = V_131 != NULL ;
F_17 ( V_55 | V_298 ,
L_103 ,
F_1 ( V_189 . V_205 ) ) ;
if ( ! V_189 . V_205 )
return 1 ;
V_13 = F_4 ( V_333 ,
F_98 ( V_333 ) ) ;
F_58 () ;
V_296 = F_49 (
F_98 ( V_334 ) + 2 ,
NULL ) ;
if ( ! V_296 )
return - V_82 ;
V_17 = F_51 ( V_296 ,
V_334 ,
F_98 ( V_334 ) ) ;
if ( V_17 )
goto V_335;
if ( F_7 ( V_131 , & V_326 , L_104 , L_105 ) ) {
if ( ( V_326 >> 8 ) != 1 ) {
F_8 ( L_106 ,
V_326 ) ;
F_8 ( L_107 , V_336 ) ;
} else {
F_17 ( V_55 | V_298 ,
L_108 ,
V_326 ) ;
if ( ! F_7 ( V_131 , & V_194 ,
L_109 , L_105 ) ) {
F_8 ( L_110
L_107 ,
V_336 ) ;
V_194 = 0x080cU ;
} else {
V_189 . V_192 = 1 ;
}
}
}
F_17 ( V_55 | V_298 ,
L_111 ,
F_1 ( V_189 . V_192 ) ) ;
if ( ! V_189 . V_192 && ! V_194 &&
( V_13 & V_337 ) )
V_194 = 0x080cU ;
if ( V_189 . V_192 ) {
V_17 = F_108 () ;
if ( V_17 )
goto V_335;
V_289 = V_193 ;
} else {
V_289 = V_194 ;
V_193 = V_194 ;
}
#ifdef F_100
if ( V_175 ) {
V_189 . V_190 = 1 ;
V_327 = ! ! V_170 ;
F_74 ( L_112 ) ;
} else
#endif
if ( F_7 ( V_131 , & V_30 , L_61 , L_105 ) ) {
V_189 . V_190 = 1 ;
V_327 = ! ! V_30 ;
F_74 ( L_113 ,
F_186 ( V_30 , 0 ) ) ;
}
if ( V_189 . V_190 )
V_17 = F_50 ( V_296 ,
& V_338 . V_124 ) ;
if ( ! V_17 && F_7 ( V_131 , & V_30 , L_63 , L_105 ) ) {
V_189 . V_208 = 1 ;
V_328 = ! ! ( V_30 & V_191 ) ;
F_74 ( L_114
L_115 ,
( V_328 ) ? L_116 : L_117 ) ;
V_17 = F_50 ( V_296 ,
& V_339 . V_124 ) ;
}
if ( ! V_17 )
V_17 = F_187 (
V_296 ,
& V_156 -> V_157 . V_127 ) ;
if ( V_17 )
goto V_335;
V_214 = F_42 ( F_182 ,
V_81 ) ;
if ( ! V_214 ) {
F_8 ( L_118 ) ;
V_17 = - V_82 ;
goto V_335;
}
V_329 = F_4 ( V_325 ,
F_98 ( V_325 ) ) ;
F_23 ( V_329 >= F_98 ( V_304 ) ) ;
F_20 ( V_55 | V_298 ,
L_119 , V_329 ) ;
memcpy ( V_214 , & V_304 [ V_329 ] ,
F_182 ) ;
F_188 ( V_210 , V_216 , V_217 ) ;
V_210 -> V_340 = F_183 ;
V_210 -> V_341 = V_342 ;
V_210 -> V_213 = V_214 ;
for ( V_42 = 0 ; V_42 < V_342 ; V_42 ++ ) {
if ( V_214 [ V_42 ] != V_215 ) {
F_188 ( V_210 , V_343 ,
V_214 [ V_42 ] ) ;
} else {
if ( V_42 < sizeof( V_290 ) * 8 )
V_290 |= 1 << V_42 ;
}
}
if ( V_189 . V_190 ) {
F_188 ( V_210 , V_344 , V_295 ) ;
F_120 ( V_210 ,
V_295 , V_327 ) ;
}
if ( V_189 . V_208 ) {
F_188 ( V_210 , V_344 , V_211 ) ;
F_120 ( V_210 ,
V_211 , V_328 ) ;
}
if ( V_189 . V_345 && F_189 () ) {
F_74 ( L_120
L_121
L_122 ) ;
F_31 ( L_123
L_124 ) ;
V_290 |=
( 1 << V_265 )
| ( 1 << V_264 ) ;
F_179 ( V_265 ) ;
F_179 ( V_264 ) ;
}
#ifdef F_114
V_196 = V_346
& ~ V_194
& ~ V_290 ;
F_17 ( V_55 | V_298 ,
L_125 ,
V_196 , V_276 ) ;
#endif
F_20 ( V_55 | V_298 ,
L_126 ) ;
V_17 = F_118 ( true ) ;
if ( V_17 ) {
F_178 () ;
return V_17 ;
}
V_17 = F_110 ( ( ( V_194 & ~ V_290 )
| V_198 )
& ~ V_196 ) ;
if ( V_17 < 0 && V_17 != - V_49 ) {
F_178 () ;
return V_17 ;
}
V_195 = ( V_193 | V_196 )
& ~ V_290 ;
F_17 ( V_55 | V_298 ,
L_127 ,
V_195 , V_193 , V_196 ) ;
F_20 ( V_55 | V_298 ,
L_128 ,
( V_218 < 2 ) ?
L_46 : L_47 ) ;
V_210 -> V_330 = & F_151 ;
V_210 -> V_331 = & F_153 ;
F_149 ( true ) ;
return 0 ;
V_335:
F_52 ( V_296 , & V_156 -> V_157 . V_127 ) ;
V_296 = NULL ;
return ( V_17 < 0 ) ? V_17 : 1 ;
}
static bool F_190 ( const T_7 V_332 ,
bool * V_347 ,
bool * V_348 )
{
unsigned int V_212 = V_332 & 0xfff ;
* V_347 = true ;
* V_348 = false ;
if ( V_212 > 0 && V_212 <= V_342 ) {
V_212 -- ;
if ( ! ( V_196 & ( 1 << V_212 ) ) ) {
F_125 ( V_212 ) ;
* V_347 = false ;
} else {
* V_348 = true ;
}
return true ;
}
return false ;
}
static bool F_191 ( const T_7 V_332 ,
bool * V_347 ,
bool * V_348 )
{
* V_347 = true ;
* V_348 = false ;
switch ( V_332 ) {
case V_349 :
case V_350 :
V_292 = V_351 ;
* V_348 = true ;
break;
case V_352 :
case V_353 :
V_292 = V_354 ;
* V_348 = true ;
break;
case V_355 :
case V_356 :
F_192 ( L_129 ) ;
break;
default:
return false ;
}
if ( V_292 != V_357 ) {
F_74 ( L_130 ) ;
F_174 () ;
}
return true ;
}
static bool F_193 ( const T_7 V_332 ,
bool * V_347 ,
bool * V_348 )
{
* V_347 = true ;
* V_348 = false ;
switch ( V_332 ) {
case V_358 :
V_293 = 1 ;
F_74 ( L_131 ) ;
F_176 () ;
return true ;
case V_359 :
F_74 ( L_132 ) ;
return true ;
case V_360 :
F_74 ( L_133 ) ;
return true ;
default:
return false ;
}
}
static bool F_194 ( const T_7 V_332 ,
bool * V_347 ,
bool * V_348 )
{
* V_347 = true ;
* V_348 = false ;
switch ( V_332 ) {
case V_361 :
case V_362 :
return true ;
case V_363 :
case V_364 :
F_119 () ;
F_171 () ;
* V_347 = false ;
return true ;
case V_365 :
case V_366 :
case V_367 :
* V_348 = true ;
return true ;
default:
return false ;
}
}
static bool F_195 ( const T_7 V_332 ,
bool * V_347 ,
bool * V_348 )
{
bool V_368 = true ;
* V_347 = true ;
* V_348 = false ;
switch ( V_332 ) {
case V_369 :
F_74 ( L_134 ) ;
return true ;
case V_370 :
F_196 ( L_135 ) ;
break;
case V_371 :
F_192 ( L_136 ) ;
break;
case V_372 :
F_196 ( L_137
L_138 ) ;
break;
case V_373 :
F_192 ( L_139
L_140 ) ;
break;
case V_374 :
case V_375 :
* V_347 = false ;
* V_348 = true ;
return true ;
default:
F_60 ( L_141 ) ;
V_368 = false ;
}
F_197 () ;
return V_368 ;
}
static void F_198 ( struct V_64 * V_65 , T_7 V_62 )
{
T_7 V_332 ;
bool V_347 ;
bool V_348 ;
bool V_376 ;
if ( V_62 != 0x80 ) {
F_8 ( L_142 , V_62 ) ;
F_199 (
V_65 -> V_68 -> V_71 -> V_377 . V_378 ,
F_200 ( & V_65 -> V_68 -> V_71 -> V_157 ) ,
V_62 , 0 ) ;
return;
}
while ( 1 ) {
if ( ! F_7 ( V_131 , & V_332 , L_143 , L_62 ) ) {
F_8 ( L_144 ) ;
return;
}
if ( V_332 == 0 ) {
return;
}
V_347 = true ;
V_348 = false ;
switch ( V_332 >> 12 ) {
case 1 :
V_376 = F_190 ( V_332 , & V_347 ,
& V_348 ) ;
break;
case 2 :
V_376 = F_191 ( V_332 , & V_347 ,
& V_348 ) ;
break;
case 3 :
switch ( V_332 ) {
case V_379 :
V_293 = 1 ;
F_74 ( L_145 ) ;
F_176 () ;
V_376 = true ;
break;
case V_380 :
V_376 = true ;
break;
default:
V_376 = false ;
}
break;
case 4 :
V_376 = F_193 ( V_332 , & V_347 ,
& V_348 ) ;
break;
case 5 :
V_376 = F_194 ( V_332 , & V_347 ,
& V_348 ) ;
break;
case 6 :
V_376 = F_195 ( V_332 , & V_347 ,
& V_348 ) ;
break;
case 7 :
if ( V_189 . V_190 &&
V_332 == V_381 ) {
F_177 () ;
V_347 = 0 ;
V_376 = true ;
break;
}
default:
V_376 = false ;
}
if ( ! V_376 ) {
F_31 ( L_146 , V_332 ) ;
F_31 ( L_147
L_148 , V_336 ) ;
}
if ( ! V_348 &&
( V_347 || V_218 < 2 ) ) {
F_128 ( V_65 -> V_68 -> V_71 ,
V_62 , V_332 ) ;
}
if ( ! V_348 && V_347 ) {
F_199 (
V_65 -> V_68 -> V_71 -> V_377 . V_378 ,
F_200 ( & V_65 -> V_68 -> V_71 -> V_157 ) ,
V_62 , V_332 ) ;
}
}
}
static void F_201 ( T_12 V_110 )
{
V_292 = V_357 ;
V_293 = 0 ;
}
static void F_202 ( void )
{
F_58 () ;
if ( F_118 ( true ) < 0 ||
F_110 ( V_193 ) < 0 )
F_8 ( L_149
L_150 ) ;
F_177 () ;
F_171 () ;
F_174 () ;
F_176 () ;
F_149 ( false ) ;
}
static int F_203 ( struct V_88 * V_89 )
{
int V_17 , V_30 ;
if ( ! V_189 . V_205 ) {
F_82 ( V_89 , L_44 ) ;
return 0 ;
}
if ( F_158 ( & V_206 ) )
return - V_288 ;
V_17 = F_117 ( & V_30 ) ;
if ( ! V_17 )
V_17 = F_108 () ;
F_116 ( & V_206 ) ;
if ( V_17 )
return V_17 ;
F_82 ( V_89 , L_45 , F_186 ( V_30 , 0 ) ) ;
if ( V_194 ) {
F_82 ( V_89 , L_151 , V_195 ) ;
F_82 ( V_89 , L_152 ) ;
} else {
F_82 ( V_89 , L_153 ) ;
F_82 ( V_89 , L_154 ) ;
}
return 0 ;
}
static void F_204 ( bool V_207 )
{
F_2 ( L_155 ) ;
if ( ! F_205 ( ( V_66 == V_67 || ! V_207 ) ,
F_206 ( L_156
L_157
L_158 ) ) )
F_8 ( L_159
L_160
L_158 ) ;
}
static int F_207 ( char * V_128 )
{
int V_17 ;
T_7 V_200 ;
char * V_162 ;
if ( ! V_189 . V_205 )
return - V_72 ;
if ( F_158 ( & V_206 ) )
return - V_288 ;
V_200 = V_195 ;
V_17 = 0 ;
while ( ( V_162 = F_44 ( & V_128 ) ) ) {
if ( F_84 ( V_162 , L_49 ) == 0 ) {
F_204 ( 1 ) ;
} else if ( F_84 ( V_162 , L_50 ) == 0 ) {
F_204 ( 0 ) ;
V_17 = - V_161 ;
} else if ( F_84 ( V_162 , L_161 ) == 0 ) {
V_200 = ( V_194 | V_196 )
& ~ V_290 ;
} else if ( sscanf ( V_162 , L_162 , & V_200 ) == 1 ) {
} else if ( sscanf ( V_162 , L_163 , & V_200 ) == 1 ) {
} else {
V_17 = - V_92 ;
goto V_382;
}
}
if ( ! V_17 ) {
F_80 ( L_164 ,
L_165 , V_200 ) ;
V_17 = F_111 ( V_200 ) ;
}
V_382:
F_116 ( & V_206 ) ;
return V_17 ;
}
static int F_208 ( void )
{
int V_30 ;
#ifdef F_100
if ( V_177 )
return ( V_171 ) ?
V_144 : V_137 ;
#endif
if ( ! F_7 ( V_131 , & V_30 , L_166 , L_62 ) )
return - V_50 ;
return ( ( V_30 & V_383 ) != 0 ) ?
V_144 : V_137 ;
}
static int F_209 ( enum V_384 V_110 )
{
int V_30 ;
F_17 ( V_142 ,
L_167 ,
( V_110 == V_144 ) ? L_49 : L_50 ) ;
#ifdef F_100
if ( V_177 ) {
V_171 = ( V_110 == V_144 ) ;
return 0 ;
}
#endif
if ( V_110 == V_144 )
V_30 = V_383
| V_385 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_131 , NULL , L_168 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_210 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return F_78 ( V_386 ,
V_124 , V_128 ) ;
}
static T_8 F_211 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
const char * V_128 , T_10 V_35 )
{
return F_79 ( V_386 ,
V_124 , V_128 , V_35 ) ;
}
static void F_212 ( void )
{
if ( ! F_7 ( NULL , NULL , L_169 , L_9 ,
V_387 ) )
F_31 ( L_170 ) ;
else
F_17 ( V_142 ,
L_171 ) ;
}
static void F_213 ( void )
{
F_53 ( & V_156 -> V_157 . V_127 ,
& V_388 ) ;
F_75 ( V_386 ) ;
F_212 () ;
}
static int T_1 F_214 ( struct V_300 * V_301 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_142 ,
L_172 ) ;
F_184 ( V_332 ) ;
V_189 . V_389 = V_131 &&
F_7 ( V_131 , & V_30 , L_166 , L_105 ) ;
F_17 ( V_55 | V_142 ,
L_173 ,
F_1 ( V_189 . V_389 ) ,
V_30 ) ;
#ifdef F_100
if ( V_177 ) {
V_189 . V_389 = 1 ;
F_74 ( L_174 ) ;
} else
#endif
if ( V_189 . V_389 &&
! ( V_30 & V_390 ) ) {
V_189 . V_389 = 0 ;
F_20 ( V_55 | V_142 ,
L_175 ) ;
}
if ( ! V_189 . V_389 )
return 1 ;
V_17 = F_69 ( V_386 ,
& V_391 ,
V_392 ,
V_393 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_215 ( & V_156 -> V_157 . V_127 ,
& V_388 ) ;
if ( V_17 ) {
F_75 ( V_386 ) ;
return V_17 ;
}
return 0 ;
}
static int F_216 ( struct V_88 * V_89 )
{
return F_81 ( V_386 , V_89 ) ;
}
static int F_217 ( char * V_128 )
{
return F_83 ( V_386 , V_128 ) ;
}
static int F_218 ( void )
{
int V_30 ;
#ifdef F_100
if ( V_179 )
return ( V_172 ) ?
V_144 : V_137 ;
#endif
if ( ! F_7 ( V_131 , & V_30 , L_176 , L_62 ) )
return - V_50 ;
return ( ( V_30 & V_394 ) != 0 ) ?
V_144 : V_137 ;
}
static int F_219 ( enum V_384 V_110 )
{
int V_30 ;
F_17 ( V_142 ,
L_177 ,
( V_110 == V_144 ) ? L_49 : L_50 ) ;
#ifdef F_100
if ( V_179 ) {
V_172 = ( V_110 == V_144 ) ;
return 0 ;
}
#endif
if ( V_110 == V_144 )
V_30 = V_394
| V_395 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_131 , NULL , L_178 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_220 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return F_78 ( V_396 ,
V_124 , V_128 ) ;
}
static T_8 F_221 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
const char * V_128 , T_10 V_35 )
{
return F_79 ( V_396 ,
V_124 , V_128 , V_35 ) ;
}
static void F_222 ( void )
{
if ( ! F_7 ( NULL , NULL , L_179 , L_9 ,
V_397 ) )
F_31 ( L_180 ) ;
else
F_17 ( V_142 ,
L_181 ) ;
}
static void F_223 ( void )
{
F_53 ( & V_156 -> V_157 . V_127 ,
& V_398 ) ;
F_75 ( V_396 ) ;
F_222 () ;
}
static int T_1 F_224 ( struct V_300 * V_301 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_142 ,
L_182 ) ;
F_184 ( V_332 ) ;
V_189 . V_399 = V_131 &&
F_7 ( V_131 , & V_30 , L_176 , L_105 ) ;
F_17 ( V_55 | V_142 ,
L_183 ,
F_1 ( V_189 . V_399 ) ,
V_30 ) ;
#ifdef F_100
if ( V_179 ) {
V_189 . V_399 = 1 ;
F_74 ( L_184 ) ;
} else
#endif
if ( V_189 . V_399 &&
! ( V_30 & V_400 ) ) {
V_189 . V_399 = 0 ;
F_20 ( V_55 | V_142 ,
L_185 ) ;
}
if ( ! V_189 . V_399 )
return 1 ;
V_17 = F_69 ( V_396 ,
& V_401 ,
V_402 ,
V_403 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_215 ( & V_156 -> V_157 . V_127 ,
& V_398 ) ;
if ( V_17 ) {
F_75 ( V_396 ) ;
return V_17 ;
}
return 0 ;
}
static int F_225 ( struct V_88 * V_89 )
{
return F_81 ( V_396 , V_89 ) ;
}
static int F_226 ( char * V_128 )
{
return F_83 ( V_396 , V_128 ) ;
}
static int F_227 ( void )
{
int V_30 ;
#ifdef F_100
if ( V_181 )
return ( V_173 ) ?
V_144 : V_137 ;
#endif
if ( ! F_7 ( V_131 , & V_30 , L_186 , L_62 ) )
return - V_50 ;
return ( ( V_30 & V_404 ) != 0 ) ?
V_144 : V_137 ;
}
static int F_228 ( enum V_384 V_110 )
{
int V_30 ;
F_17 ( V_142 ,
L_187 ,
( V_110 == V_144 ) ? L_49 : L_50 ) ;
#ifdef F_100
if ( V_181 ) {
V_173 = ( V_110 == V_144 ) ;
return 0 ;
}
#endif
if ( V_110 == V_144 )
V_30 = V_404 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_131 , NULL , L_188 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static void F_229 ( void )
{
F_75 ( V_405 ) ;
}
static int T_1 F_230 ( struct V_300 * V_301 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_142 ,
L_189 ) ;
F_184 ( V_332 ) ;
V_189 . V_406 = V_131 &&
F_7 ( V_131 , & V_30 , L_186 , L_105 ) ;
F_17 ( V_55 | V_142 ,
L_190 ,
F_1 ( V_189 . V_406 ) ,
V_30 ) ;
#ifdef F_100
if ( V_181 ) {
V_189 . V_406 = 1 ;
F_74 ( L_191 ) ;
} else
#endif
if ( V_189 . V_406 &&
! ( V_30 & V_407 ) ) {
V_189 . V_406 = 0 ;
F_20 ( V_55 ,
L_192 ) ;
}
if ( ! V_189 . V_406 )
return 1 ;
V_17 = F_69 ( V_405 ,
& V_408 ,
V_409 ,
V_410 ,
false ) ;
return V_17 ;
}
static int T_1 F_231 ( struct V_300 * V_301 )
{
int V_411 ;
F_17 ( V_55 , L_193 ) ;
F_184 ( V_412 ) ;
if ( F_6 () )
F_184 ( V_413 ) ;
if ( V_414 && F_7 ( NULL , & V_411 , L_194 , L_62 ) && V_411 )
V_415 = V_414 ;
if ( ! V_415 )
V_416 = V_417 ;
else if ( F_6 () &&
F_7 ( V_415 , & V_418 , L_195 , L_105 ) )
V_416 = V_419 ;
else if ( F_6 () &&
F_7 ( V_415 , & V_418 , L_196 , L_105 ) )
V_416 = V_420 ;
else
V_416 = V_421 ;
F_17 ( V_55 , L_197 ,
F_1 ( V_416 != V_417 ) ,
V_416 ) ;
return ( V_416 != V_417 ) ? 0 : 1 ;
}
static void F_232 ( void )
{
F_20 ( V_297 ,
L_198 ) ;
if ( F_233 ( V_418 ) )
F_8 ( L_199
L_200 ) ;
}
static int F_234 ( void )
{
int V_30 = 0 ;
int V_42 ;
switch ( V_416 ) {
case V_419 :
if ( ! F_7 ( NULL , & V_42 , L_201 , L_7 ,
V_422 ) )
return - V_50 ;
V_30 = V_42 & V_423 ;
break;
case V_420 :
if ( ! F_7 ( NULL , & V_42 , L_202 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_424 ;
if ( ! F_7 ( NULL , & V_42 , L_203 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_425 ;
break;
case V_421 :
if ( ! F_7 ( NULL , NULL , L_204 , L_9 , 1 ) ||
! F_7 ( NULL , & V_42 , L_203 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_425 ;
if ( ! F_7 ( NULL , NULL , L_204 , L_9 , 0 ) ||
! F_7 ( NULL , & V_42 , L_202 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_424 ;
if ( ! F_7 ( NULL , & V_42 , L_205 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_426 ;
break;
default:
return - V_427 ;
}
return V_30 ;
}
static int F_235 ( int V_30 )
{
int V_428 ;
int V_17 = 0 ;
switch ( V_416 ) {
case V_419 :
V_17 = F_7 ( NULL , NULL ,
L_206 , L_8 ,
V_429 ,
V_30 | V_430 ) ;
break;
case V_420 :
V_428 = F_236 () ;
if ( V_428 < 0 )
return V_428 ;
V_17 = F_233 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_415 , NULL ,
L_207 , L_8 , V_30 * 0x100 , 0 ) ;
if ( ! V_428 && F_233 ( V_428 ) ) {
F_8 ( L_208 ) ;
return - V_50 ;
}
break;
case V_421 :
V_17 = F_7 ( NULL , NULL , L_204 , L_9 , 0x80 ) &&
F_7 ( NULL , NULL , L_209 , L_8 , V_30 , 1 ) ;
break;
default:
return - V_427 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_236 ( void )
{
int V_428 = 0 ;
switch ( V_416 ) {
case V_419 :
if ( ! F_7 ( V_415 , & V_428 , L_195 , L_62 ) )
return - V_50 ;
break;
case V_420 :
case V_421 :
if ( ! F_7 ( V_415 , & V_428 , L_210 , L_62 ) )
return - V_50 ;
break;
default:
return - V_427 ;
}
return V_428 & 1 ;
}
static int F_233 ( int V_207 )
{
if ( ! F_7 ( V_415 , NULL , L_211 , L_9 , ( V_207 ) ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static int F_237 ( void )
{
int V_428 = F_236 () ;
int V_17 ;
if ( V_428 < 0 )
return V_428 ;
switch ( V_416 ) {
case V_419 :
V_17 = F_233 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_431 , NULL , L_212 , L_213 ) ;
break;
case V_420 :
case V_421 :
V_17 = F_233 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_415 , NULL , L_214 , L_213 ) ;
break;
default:
return - V_427 ;
}
if ( ! V_428 && F_233 ( V_428 ) ) {
F_8 ( L_208 ) ;
return - V_50 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_238 ( void )
{
switch ( V_416 ) {
case V_419 :
return F_7 ( V_431 , NULL , L_215 , L_213 ) ?
0 : - V_50 ;
case V_420 :
return F_7 ( V_415 , NULL , L_216 , L_213 ) ?
0 : - V_50 ;
case V_421 :
return F_7 ( NULL , NULL , L_217 , L_213 ) ?
0 : - V_50 ;
default:
return - V_427 ;
}
}
static int F_239 ( struct V_88 * V_89 )
{
int V_30 , V_428 ;
if ( V_416 == V_417 ) {
F_82 ( V_89 , L_44 ) ;
return 0 ;
}
if ( ! F_240 ( V_432 ) )
return - V_161 ;
V_30 = F_234 () ;
if ( V_30 < 0 )
return V_30 ;
V_428 = F_236 () ;
if ( V_428 < 0 )
return V_428 ;
F_82 ( V_89 , L_218 ) ;
F_82 ( V_89 , L_219 , F_186 ( V_30 , 0 ) ) ;
F_82 ( V_89 , L_220 , F_186 ( V_30 , 1 ) ) ;
if ( V_416 == V_421 )
F_82 ( V_89 , L_221 , F_186 ( V_30 , 3 ) ) ;
F_82 ( V_89 , L_222 , F_186 ( V_428 , 0 ) ) ;
F_82 ( V_89 , L_223 ) ;
F_82 ( V_89 , L_224 ) ;
if ( V_416 == V_421 )
F_82 ( V_89 , L_225 ) ;
F_82 ( V_89 , L_226 ) ;
F_82 ( V_89 , L_227 ) ;
return 0 ;
}
static int F_241 ( char * V_128 )
{
char * V_162 ;
int V_207 , V_433 , V_30 ;
int V_17 ;
if ( V_416 == V_417 )
return - V_72 ;
if ( ! F_240 ( V_432 ) )
return - V_161 ;
V_207 = 0 ;
V_433 = 0 ;
while ( ( V_162 = F_44 ( & V_128 ) ) ) {
if ( F_84 ( V_162 , L_228 ) == 0 ) {
V_207 |= V_424 ;
} else if ( F_84 ( V_162 , L_229 ) == 0 ) {
V_433 |= V_424 ;
} else if ( F_84 ( V_162 , L_230 ) == 0 ) {
V_207 |= V_425 ;
} else if ( F_84 ( V_162 , L_231 ) == 0 ) {
V_433 |= V_425 ;
} else if ( V_416 == V_421 &&
F_84 ( V_162 , L_232 ) == 0 ) {
V_207 |= V_426 ;
} else if ( V_416 == V_421 &&
F_84 ( V_162 , L_233 ) == 0 ) {
V_433 |= V_426 ;
} else if ( F_84 ( V_162 , L_234 ) == 0 ) {
V_17 = F_233 ( 1 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_84 ( V_162 , L_235 ) == 0 ) {
V_17 = F_233 ( 0 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_84 ( V_162 , L_236 ) == 0 ) {
V_17 = F_237 () ;
if ( V_17 )
return V_17 ;
} else if ( F_84 ( V_162 , L_237 ) == 0 ) {
V_17 = F_238 () ;
if ( V_17 )
return V_17 ;
} else
return - V_92 ;
}
if ( V_207 || V_433 ) {
V_30 = F_234 () ;
if ( V_30 < 0 )
return V_30 ;
V_17 = F_235 ( ( V_30 & ~ V_433 ) | V_207 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_242 ( void )
{
int V_30 = 0 ;
if ( V_189 . V_434 ) {
if ( ! F_7 ( V_431 , & V_30 , L_238 , L_62 ) )
return - V_50 ;
return ( ! ! V_30 ) ;
}
return - V_49 ;
}
static int F_243 ( int V_30 )
{
int V_70 ;
if ( V_189 . V_435 ) {
if ( V_48 ) {
V_70 = F_7 ( V_48 , NULL , NULL , L_9 ,
( V_30 ) ?
V_436 :
V_437 ) ;
} else {
V_70 = F_7 ( V_438 , NULL , NULL , L_9 ,
( V_30 ) ? 1 : 0 ) ;
}
return ( V_70 ) ? 0 : - V_50 ;
}
return - V_49 ;
}
static void F_244 ( struct V_439 * V_440 )
{
struct V_441 * V_63 =
F_245 ( V_440 , struct V_441 , V_440 ) ;
if ( F_137 ( V_66 == V_67 ) )
F_243 ( ( V_63 -> V_442 != V_443 ) ) ;
}
static void F_246 ( struct V_444 * V_445 ,
enum V_446 V_447 )
{
struct V_441 * V_63 =
F_245 ( V_445 ,
struct V_441 ,
V_444 ) ;
V_63 -> V_442 = ( V_447 != V_448 ) ?
V_449 : V_443 ;
F_247 ( V_450 , & V_63 -> V_440 ) ;
}
static enum V_446 F_248 ( struct V_444 * V_445 )
{
return ( F_242 () == 1 ) ? V_451 : V_448 ;
}
static int T_1 F_249 ( struct V_300 * V_301 )
{
int V_70 ;
F_17 ( V_55 , L_239 ) ;
if ( F_6 () ) {
F_184 ( V_452 ) ;
F_184 ( V_453 ) ;
}
F_184 ( V_454 ) ;
F_250 ( & V_455 . V_440 , F_244 ) ;
V_189 . V_435 = ( V_48 || V_438 ) && ! V_456 ;
if ( V_189 . V_435 )
V_189 . V_434 =
F_7 ( V_431 , NULL , L_238 , L_240 ) ;
F_17 ( V_55 , L_241 ,
F_1 ( V_189 . V_435 ) ,
F_1 ( V_189 . V_434 ) ) ;
if ( ! V_189 . V_435 )
return 1 ;
V_70 = F_251 ( & V_156 -> V_157 ,
& V_455 . V_444 ) ;
if ( V_70 < 0 ) {
V_189 . V_435 = 0 ;
V_189 . V_434 = 0 ;
} else {
V_70 = 0 ;
}
return V_70 ;
}
static void F_252 ( void )
{
F_253 ( & V_455 . V_444 ) ;
if ( F_254 ( & V_455 . V_440 ) )
F_255 ( V_450 ) ;
}
static int F_256 ( struct V_88 * V_89 )
{
int V_30 ;
if ( ! V_189 . V_435 ) {
F_82 ( V_89 , L_44 ) ;
} else if ( ! V_189 . V_434 ) {
F_82 ( V_89 , L_242 ) ;
F_82 ( V_89 , L_243 ) ;
} else {
V_30 = F_242 () ;
if ( V_30 < 0 )
return V_30 ;
F_82 ( V_89 , L_45 , F_257 ( V_30 , 0 ) ) ;
F_82 ( V_89 , L_243 ) ;
}
return 0 ;
}
static int F_258 ( char * V_128 )
{
char * V_162 ;
int V_457 = 0 ;
if ( ! V_189 . V_435 )
return - V_72 ;
while ( ( V_162 = F_44 ( & V_128 ) ) ) {
if ( F_84 ( V_162 , L_244 ) == 0 ) {
V_457 = 1 ;
} else if ( F_84 ( V_162 , L_245 ) == 0 ) {
V_457 = 0 ;
} else
return - V_92 ;
}
return F_243 ( V_457 ) ;
}
static T_8 F_259 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_47 ;
int V_17 ;
if ( F_55 ( V_128 , 21 , & V_47 ) )
return - V_92 ;
V_17 = F_15 ( V_47 ) ;
return ( V_17 ) ? V_17 : V_35 ;
}
static int T_1 F_260 ( struct V_300 * V_301 )
{
int V_17 ;
F_17 ( V_55 ,
L_246 ) ;
F_184 ( V_454 ) ;
F_17 ( V_55 , L_247 ,
F_1 ( V_48 != NULL ) ) ;
V_17 = F_261 ( & V_156 -> V_157 , & V_458 ) ;
if ( V_17 )
return V_17 ;
return ( V_48 ) ? 0 : 1 ;
}
static void F_262 ( void )
{
F_263 ( & V_156 -> V_157 , & V_458 ) ;
}
static int F_264 ( struct V_88 * V_89 )
{
if ( ! V_48 )
F_82 ( V_89 , L_44 ) ;
else {
F_82 ( V_89 , L_218 ) ;
F_82 ( V_89 , L_248 ) ;
}
return 0 ;
}
static int F_265 ( char * V_128 )
{
char * V_162 ;
int V_47 , V_17 ;
while ( ( V_162 = F_44 ( & V_128 ) ) ) {
if ( sscanf ( V_162 , L_249 , & V_47 ) == 1 &&
V_47 >= 0 && V_47 <= 21 ) {
} else
return - V_92 ;
V_17 = F_15 ( V_47 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static inline bool F_266 ( const unsigned int V_459 )
{
#ifdef F_267
return false ;
#else
return ( 1U & ( V_460 >> V_459 ) ) == 0 ;
#endif
}
static int F_268 ( const unsigned int V_459 )
{
int V_30 ;
enum V_461 V_462 ;
switch ( V_463 ) {
case V_464 :
if ( ! F_7 ( V_431 ,
& V_30 , L_250 , L_7 , 1 << V_459 ) )
return - V_50 ;
V_462 = ( V_30 == 0 ) ?
V_443 :
( ( V_30 == 1 ) ?
V_449 :
V_465 ) ;
V_466 [ V_459 ] = V_462 ;
return V_462 ;
default:
return - V_49 ;
}
}
static int F_269 ( const unsigned int V_459 ,
const enum V_461 V_467 )
{
static const unsigned int V_468 [] = { 0 , 1 , 3 } ;
static const unsigned int V_469 [] = { 0 , 0x80 , 0xc0 } ;
int V_70 = 0 ;
switch ( V_463 ) {
case V_464 :
if ( F_139 ( V_459 > 7 ) )
return - V_92 ;
if ( F_139 ( F_266 ( V_459 ) ) )
return - V_161 ;
if ( ! F_7 ( V_470 , NULL , NULL , L_8 ,
( 1 << V_459 ) , V_468 [ V_467 ] ) )
V_70 = - V_50 ;
break;
case V_471 :
if ( F_139 ( V_459 > 7 ) )
return - V_92 ;
if ( F_139 ( F_266 ( V_459 ) ) )
return - V_161 ;
V_70 = F_14 ( V_472 , ( 1 << V_459 ) ) ;
if ( V_70 >= 0 )
V_70 = F_14 ( V_473 ,
( V_467 == V_465 ) << V_459 ) ;
if ( V_70 >= 0 )
V_70 = F_14 ( V_474 ,
( V_467 != V_443 ) << V_459 ) ;
break;
case V_475 :
if ( F_139 ( V_459 >= V_476 ) )
return - V_92 ;
if ( F_139 ( F_266 ( V_459 ) ) )
return - V_161 ;
if ( ! F_7 ( V_470 , NULL , NULL , L_8 ,
V_459 , V_469 [ V_467 ] ) )
V_70 = - V_50 ;
break;
default:
V_70 = - V_49 ;
}
if ( ! V_70 )
V_466 [ V_459 ] = V_467 ;
return V_70 ;
}
static void F_270 ( struct V_439 * V_440 )
{
struct V_441 * V_63 =
F_245 ( V_440 , struct V_441 , V_440 ) ;
if ( F_137 ( V_66 == V_67 ) )
F_269 ( V_63 -> V_459 , V_63 -> V_442 ) ;
}
static void F_271 ( struct V_444 * V_445 ,
enum V_446 V_447 )
{
struct V_441 * V_63 = F_245 ( V_445 ,
struct V_441 , V_444 ) ;
if ( V_447 == V_448 )
V_63 -> V_442 = V_443 ;
else if ( V_466 [ V_63 -> V_459 ] != V_465 )
V_63 -> V_442 = V_449 ;
else
V_63 -> V_442 = V_465 ;
F_247 ( V_450 , & V_63 -> V_440 ) ;
}
static int F_272 ( struct V_444 * V_445 ,
unsigned long * V_477 , unsigned long * V_478 )
{
struct V_441 * V_63 = F_245 ( V_445 ,
struct V_441 , V_444 ) ;
if ( * V_477 == 0 && * V_478 == 0 ) {
* V_477 = 500 ;
* V_478 = 500 ;
} else if ( ( * V_477 != 500 ) || ( * V_478 != 500 ) )
return - V_92 ;
V_63 -> V_442 = V_465 ;
F_247 ( V_450 , & V_63 -> V_440 ) ;
return 0 ;
}
static enum V_446 F_273 ( struct V_444 * V_445 )
{
int V_70 ;
struct V_441 * V_63 = F_245 ( V_445 ,
struct V_441 , V_444 ) ;
V_70 = F_268 ( V_63 -> V_459 ) ;
if ( V_70 == V_443 || V_70 < 0 )
V_70 = V_448 ;
else
V_70 = V_451 ;
return V_70 ;
}
static void F_274 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_476 ; V_42 ++ ) {
if ( V_479 [ V_42 ] . V_444 . V_51 )
F_253 ( & V_479 [ V_42 ] . V_444 ) ;
}
F_36 ( V_479 ) ;
}
static int T_1 F_275 ( unsigned int V_459 )
{
int V_70 ;
V_479 [ V_459 ] . V_459 = V_459 ;
if ( ! V_480 [ V_459 ] )
return 0 ;
V_479 [ V_459 ] . V_444 . V_481 = & F_271 ;
V_479 [ V_459 ] . V_444 . V_482 = & F_272 ;
if ( V_463 == V_464 )
V_479 [ V_459 ] . V_444 . V_483 =
& F_273 ;
V_479 [ V_459 ] . V_444 . V_51 = V_480 [ V_459 ] ;
F_250 ( & V_479 [ V_459 ] . V_440 , F_270 ) ;
V_70 = F_251 ( & V_156 -> V_157 ,
& V_479 [ V_459 ] . V_444 ) ;
if ( V_70 < 0 )
V_479 [ V_459 ] . V_444 . V_51 = NULL ;
return V_70 ;
}
static enum V_484 T_1 F_276 ( void )
{
T_4 V_30 ;
if ( F_6 () ) {
V_30 = F_18 ( V_431 , L_251 , & V_470 ) ;
if ( F_19 ( V_30 ) )
return V_464 ;
V_30 = F_18 ( V_431 , L_252 , & V_470 ) ;
if ( F_19 ( V_30 ) )
return V_471 ;
}
V_30 = F_18 ( V_431 , L_253 , & V_470 ) ;
if ( F_19 ( V_30 ) )
return V_475 ;
V_470 = NULL ;
return V_485 ;
}
static int T_1 F_277 ( struct V_300 * V_301 )
{
unsigned int V_42 ;
int V_70 ;
unsigned long V_486 ;
F_17 ( V_55 , L_254 ) ;
V_463 = F_276 () ;
F_17 ( V_55 , L_255 ,
F_1 ( V_463 ) , V_463 ) ;
if ( V_463 == V_485 )
return 1 ;
V_479 = F_34 ( sizeof( * V_479 ) * V_476 ,
V_81 ) ;
if ( ! V_479 ) {
F_8 ( L_256 ) ;
return - V_82 ;
}
V_486 = F_4 ( V_487 ,
F_98 ( V_487 ) ) ;
for ( V_42 = 0 ; V_42 < V_476 ; V_42 ++ ) {
if ( ! F_266 ( V_42 ) &&
F_278 ( V_42 , & V_486 ) ) {
V_70 = F_275 ( V_42 ) ;
if ( V_70 < 0 ) {
F_274 () ;
return V_70 ;
}
}
}
#ifdef F_267
F_31 ( L_257
L_258 ) ;
#endif
return 0 ;
}
static int F_279 ( struct V_88 * V_89 )
{
if ( ! V_463 ) {
F_82 ( V_89 , L_44 ) ;
return 0 ;
}
F_82 ( V_89 , L_218 ) ;
if ( V_463 == V_464 ) {
int V_42 , V_30 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_30 = F_268 ( V_42 ) ;
if ( V_30 < 0 )
return - V_50 ;
F_82 ( V_89 , L_259 ,
V_42 , F_280 ( V_30 ) ) ;
}
}
F_82 ( V_89 , L_260
L_261 ) ;
return 0 ;
}
static int F_281 ( char * V_128 )
{
char * V_162 ;
int V_459 , V_70 ;
enum V_461 V_120 ;
if ( ! V_463 )
return - V_72 ;
while ( ( V_162 = F_44 ( & V_128 ) ) ) {
if ( sscanf ( V_162 , L_262 , & V_459 ) != 1 || V_459 < 0 || V_459 > 15 )
return - V_92 ;
if ( strstr ( V_162 , L_245 ) ) {
V_120 = V_443 ;
} else if ( strstr ( V_162 , L_244 ) ) {
V_120 = V_449 ;
} else if ( strstr ( V_162 , L_263 ) ) {
V_120 = V_465 ;
} else {
return - V_92 ;
}
V_70 = F_269 ( V_459 , V_120 ) ;
if ( V_70 < 0 )
return V_70 ;
}
return 0 ;
}
static int T_1 F_282 ( struct V_300 * V_301 )
{
unsigned long V_13 ;
F_17 ( V_55 , L_264 ) ;
F_184 ( V_488 ) ;
F_17 ( V_55 , L_265 ,
F_1 ( V_489 != NULL ) ) ;
V_13 = F_4 ( V_490 ,
F_98 ( V_490 ) ) ;
V_189 . V_491 = ! ! ( V_13 & V_492 ) ;
return ( V_489 ) ? 0 : 1 ;
}
static int F_283 ( struct V_88 * V_89 )
{
if ( ! V_489 )
F_82 ( V_89 , L_44 ) ;
else {
F_82 ( V_89 , L_218 ) ;
F_82 ( V_89 , L_266 ) ;
}
return 0 ;
}
static int F_284 ( char * V_128 )
{
char * V_162 ;
int V_493 ;
if ( ! V_489 )
return - V_72 ;
while ( ( V_162 = F_44 ( & V_128 ) ) ) {
if ( sscanf ( V_162 , L_249 , & V_493 ) == 1 &&
V_493 >= 0 && V_493 <= 17 ) {
} else
return - V_92 ;
if ( V_189 . V_491 ) {
if ( ! F_7 ( V_489 , NULL , NULL , L_8 ,
V_493 , 0 ) )
return - V_50 ;
} else {
if ( ! F_7 ( V_489 , NULL , NULL , L_9 ,
V_493 ) )
return - V_50 ;
}
}
return 0 ;
}
static int F_285 ( int V_494 , T_18 * V_38 )
{
int V_160 ;
T_19 V_495 ;
char V_496 [ 5 ] ;
V_160 = V_497 ;
switch ( V_498 ) {
#if V_499 >= 16
case V_500 :
if ( V_494 >= 8 && V_494 <= 15 ) {
V_160 = V_501 ;
V_494 -= 8 ;
}
#endif
case V_502 :
if ( V_494 <= 7 ) {
if ( ! F_11 ( V_160 + V_494 , & V_495 ) )
return - V_50 ;
* V_38 = V_495 * 1000 ;
return 0 ;
}
break;
case V_503 :
if ( V_494 <= 7 ) {
snprintf ( V_496 , sizeof( V_496 ) , L_267 , '0' + V_494 ) ;
if ( ! F_7 ( V_431 , NULL , L_268 , L_213 ) )
return - V_50 ;
if ( ! F_7 ( V_431 , & V_160 , V_496 , L_62 ) )
return - V_50 ;
* V_38 = ( V_160 - 2732 ) * 100 ;
return 0 ;
}
break;
case V_504 :
if ( V_494 <= 7 ) {
snprintf ( V_496 , sizeof( V_496 ) , L_267 , '0' + V_494 ) ;
if ( ! F_7 ( V_431 , & V_160 , V_496 , L_62 ) )
return - V_50 ;
if ( V_160 > 127 || V_160 < - 127 )
V_160 = V_505 ;
* V_38 = V_160 * 1000 ;
return 0 ;
}
break;
case V_506 :
default:
return - V_427 ;
}
return - V_92 ;
}
static int F_286 ( struct V_507 * V_120 )
{
int V_17 , V_42 ;
int V_222 ;
V_222 = 8 ;
V_42 = 0 ;
if ( ! V_120 )
return - V_92 ;
if ( V_498 == V_500 )
V_222 = 16 ;
for ( V_42 = 0 ; V_42 < V_222 ; V_42 ++ ) {
V_17 = F_285 ( V_42 , & V_120 -> V_508 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return V_222 ;
}
static void F_197 ( void )
{
int V_222 , V_42 ;
struct V_507 V_160 ;
V_222 = F_286 ( & V_160 ) ;
if ( V_222 <= 0 )
return;
F_31 ( L_269 ) ;
for ( V_42 = 0 ; V_42 < V_222 ; V_42 ++ ) {
if ( V_160 . V_508 [ V_42 ] != V_509 )
F_287 ( L_270 , ( int ) ( V_160 . V_508 [ V_42 ] / 1000 ) ) ;
else
F_287 ( L_271 ) ;
}
F_287 ( L_272 ) ;
}
static T_8 F_288 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
struct V_510 * V_511 =
F_289 ( V_124 ) ;
int V_494 = V_511 -> V_512 ;
T_18 V_38 ;
int V_17 ;
V_17 = F_285 ( V_494 , & V_38 ) ;
if ( V_17 )
return V_17 ;
if ( V_38 == V_509 )
return - V_49 ;
return snprintf ( V_128 , V_103 , L_42 , V_38 ) ;
}
static int T_1 F_290 ( struct V_300 * V_301 )
{
T_6 V_160 , V_513 , V_514 ;
int V_42 ;
int V_515 ;
int V_17 ;
F_17 ( V_55 , L_273 ) ;
V_515 = F_7 ( V_431 , NULL , L_274 , L_240 ) ;
if ( V_7 . V_12 ) {
V_513 = V_514 = 0 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( F_11 ( V_497 + V_42 , & V_160 ) ) {
V_513 |= V_160 ;
} else {
V_513 = 0 ;
break;
}
if ( F_11 ( V_501 + V_42 , & V_160 ) ) {
V_514 |= V_160 ;
} else {
V_513 = 0 ;
break;
}
}
if ( V_513 == 0 ) {
if ( V_515 ) {
F_8 ( L_275
L_276
L_277 ) ;
V_498 = V_504 ;
} else {
F_8 ( L_275
L_278 ) ;
V_498 = V_506 ;
}
} else {
V_498 =
( V_514 != 0 ) ?
V_500 : V_502 ;
}
} else if ( V_515 ) {
if ( F_6 () &&
F_7 ( V_431 , NULL , L_268 , L_240 ) ) {
V_498 = V_503 ;
} else {
V_498 = V_504 ;
}
} else {
V_498 = V_506 ;
}
F_17 ( V_55 , L_279 ,
F_1 ( V_498 != V_506 ) ,
V_498 ) ;
switch ( V_498 ) {
case V_500 :
V_17 = F_215 ( & V_516 -> V_157 . V_127 ,
& V_517 ) ;
if ( V_17 )
return V_17 ;
break;
case V_502 :
case V_504 :
case V_503 :
V_17 = F_215 ( & V_516 -> V_157 . V_127 ,
& V_518 ) ;
if ( V_17 )
return V_17 ;
break;
case V_506 :
default:
return 1 ;
}
return 0 ;
}
static void F_291 ( void )
{
switch ( V_498 ) {
case V_500 :
F_53 ( & V_516 -> V_157 . V_127 ,
& V_517 ) ;
break;
case V_502 :
case V_504 :
case V_503 :
F_53 ( & V_516 -> V_157 . V_127 ,
& V_518 ) ;
break;
case V_506 :
default:
break;
}
}
static int F_292 ( struct V_88 * V_89 )
{
int V_222 , V_42 ;
struct V_507 V_160 ;
V_222 = F_286 ( & V_160 ) ;
if ( F_139 ( V_222 < 0 ) )
return V_222 ;
F_82 ( V_89 , L_280 ) ;
if ( V_222 > 0 ) {
for ( V_42 = 0 ; V_42 < ( V_222 - 1 ) ; V_42 ++ )
F_82 ( V_89 , L_281 , V_160 . V_508 [ V_42 ] / 1000 ) ;
F_82 ( V_89 , L_42 , V_160 . V_508 [ V_42 ] / 1000 ) ;
} else
F_82 ( V_89 , L_282 ) ;
return 0 ;
}
static unsigned int F_293 ( void )
{
T_6 V_519 ;
V_519 = ( F_130 ( V_243 )
& V_245 )
>> V_246 ;
V_519 &= V_520 ;
return V_519 ;
}
static void F_294 ( void )
{
T_6 V_521 = 0 ;
T_6 V_522 ;
if ( V_523 != V_524 )
return;
F_17 ( V_525 ,
L_283 ) ;
if ( F_158 ( & V_526 ) < 0 )
return;
if ( F_139 ( ! F_11 ( V_527 , & V_521 ) ) )
goto V_528;
V_521 &= V_529 ;
V_522 = F_130 ( V_243 ) ;
if ( V_521 != ( ( V_522 & V_245 )
>> V_246 ) ) {
V_522 &= ~ ( V_245 <<
V_246 ) ;
V_522 |= V_521 ;
F_295 ( V_522 , V_243 ) ;
F_20 ( V_525 ,
L_284 ,
( unsigned int ) V_521 , ( unsigned int ) V_522 ) ;
} else
F_17 ( V_525 ,
L_285 ,
( unsigned int ) V_521 , ( unsigned int ) V_522 ) ;
V_528:
F_116 ( & V_526 ) ;
}
static int F_296 ( int * V_30 )
{
T_6 V_521 = 0 ;
switch ( V_523 ) {
case V_530 :
* V_30 = F_293 () ;
return 0 ;
case V_531 :
case V_524 :
if ( F_139 ( ! F_11 ( V_527 , & V_521 ) ) )
return - V_50 ;
* V_30 = V_521 ;
return 0 ;
default:
return - V_49 ;
}
}
static int F_297 ( unsigned int V_38 )
{
T_6 V_521 = 0 ;
if ( F_139 ( ! F_11 ( V_527 , & V_521 ) ) )
return - V_50 ;
if ( F_139 ( ! F_13 ( V_527 ,
( V_521 & V_532 ) |
( V_38 & V_529 ) ) ) )
return - V_50 ;
return 0 ;
}
static int F_298 ( unsigned int V_38 )
{
int V_47 , V_533 ;
unsigned int V_534 , V_42 ;
V_534 = F_293 () ;
if ( V_38 == V_534 )
return 0 ;
V_47 = ( V_38 > V_534 ) ?
V_535 :
V_536 ;
V_533 = ( V_38 > V_534 ) ? 1 : - 1 ;
for ( V_42 = V_534 ; V_42 != V_38 ; V_42 += V_533 )
if ( F_15 ( V_47 ) )
return - V_50 ;
return 0 ;
}
static int V_481 ( unsigned int V_38 )
{
int V_17 ;
if ( V_38 > V_520 || V_38 < 0 )
return - V_92 ;
F_17 ( V_525 ,
L_286 , V_38 ) ;
V_17 = F_158 ( & V_526 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_523 ) {
case V_531 :
case V_524 :
V_17 = F_297 ( V_38 ) ;
break;
case V_530 :
V_17 = F_298 ( V_38 ) ;
break;
default:
V_17 = - V_49 ;
}
F_116 ( & V_526 ) ;
return V_17 ;
}
static int F_299 ( struct V_537 * V_538 )
{
unsigned int V_56 =
( V_538 -> V_539 . V_540 == V_541 &&
V_538 -> V_539 . V_542 == V_541 ) ?
V_538 -> V_539 . V_447 : 0 ;
F_20 ( V_525 ,
L_287 ,
V_56 ) ;
return V_481 ( V_56 ) ;
}
static int V_483 ( struct V_537 * V_538 )
{
int V_30 , V_17 ;
V_17 = F_158 ( & V_526 ) ;
if ( V_17 < 0 )
return 0 ;
V_17 = F_296 ( & V_30 ) ;
F_116 ( & V_526 ) ;
if ( V_17 < 0 )
return 0 ;
return V_30 & V_529 ;
}
static void F_300 ( void )
{
F_301 ( V_543 ,
V_544 ) ;
}
static int T_1 F_302 ( T_3 V_16 )
{
struct V_26 V_545 = { V_546 , NULL } ;
union V_23 * V_547 ;
int V_70 ;
if ( F_19 ( F_9 ( V_16 , L_288 , NULL , & V_545 ) ) ) {
V_547 = (union V_23 * ) V_545 . V_36 ;
if ( ! V_547 || ( V_547 -> type != V_548 ) ) {
F_8 ( L_289 ,
V_336 ) ;
V_70 = 0 ;
} else {
V_70 = V_547 -> V_549 . V_35 ;
}
} else {
return 0 ;
}
F_36 ( V_545 . V_36 ) ;
return V_70 ;
}
static unsigned int T_1 F_303 ( void )
{
T_3 V_550 ;
int V_551 = 0 ;
F_22 ( L_290 , V_552 , & V_550 ) ;
if ( V_550 )
V_551 = F_302 ( V_550 ) ;
V_189 . V_345 = ( V_551 > 0 ) ;
return ( V_551 > 2 ) ? ( V_551 - 2 ) : 0 ;
}
static void T_1 F_304 ( void )
{
unsigned int V_553 ;
F_17 ( V_55 ,
L_291 ) ;
V_553 = F_303 () ;
switch ( V_553 ) {
case 16 :
V_520 = 15 ;
F_74 ( L_292 ) ;
break;
case 8 :
case 0 :
V_520 = 7 ;
F_74 ( L_293 ) ;
break;
default:
F_8 ( L_294
L_295 , V_336 ) ;
V_189 . V_554 = 1 ;
V_520 = V_553 - 1 ;
}
}
static int T_1 F_305 ( struct V_300 * V_301 )
{
struct V_555 V_539 ;
int V_553 ;
unsigned long V_13 ;
F_17 ( V_55 , L_296 ) ;
F_185 ( & V_526 ) ;
V_13 = F_4 ( V_556 ,
F_98 ( V_556 ) ) ;
if ( V_189 . V_554 )
return 1 ;
if ( ! V_557 ) {
F_20 ( V_55 | V_525 ,
L_297
L_298 ) ;
return 1 ;
}
if ( F_189 () ) {
if ( V_557 > 1 ) {
F_74 ( L_299
L_300 ) ;
return 1 ;
} else if ( V_557 == 1 ) {
F_60 ( L_301
L_302
L_303 ) ;
return 1 ;
}
} else if ( V_189 . V_345 && V_557 > 1 ) {
F_31 ( L_304
L_305
L_306 ) ;
}
if ( V_523 > V_558 )
return - V_92 ;
if ( V_523 == V_559 ||
V_523 == V_558 ) {
if ( V_13 & V_560 )
V_523 = V_524 ;
else
V_523 = V_530 ;
F_20 ( V_525 ,
L_307 ,
V_523 ) ;
}
if ( ! F_6 () &&
( V_523 == V_524 ||
V_523 == V_531 ) )
return - V_92 ;
if ( F_296 ( & V_553 ) < 0 )
return 1 ;
memset ( & V_539 , 0 , sizeof( struct V_555 ) ) ;
V_539 . type = V_561 ;
V_539 . V_562 = V_520 ;
V_539 . V_447 = V_553 & V_529 ;
V_543 = F_306 ( V_563 ,
NULL , NULL ,
& V_564 ,
& V_539 ) ;
if ( F_148 ( V_543 ) ) {
int V_70 = F_307 ( V_543 ) ;
V_543 = NULL ;
F_8 ( L_308 ) ;
return V_70 ;
}
F_17 ( V_55 | V_525 ,
L_309 ) ;
if ( V_13 & V_565 ) {
F_31 ( L_310
L_311 , V_523 ) ;
F_31 ( L_312
L_313 , V_336 ) ;
}
F_308 ( V_543 ) ;
F_17 ( V_55 | V_525 ,
L_314
L_315 ) ;
F_112 ( V_198
| V_566
| V_567 ) ;
return 0 ;
}
static void F_309 ( T_12 V_110 )
{
F_294 () ;
}
static void F_310 ( void )
{
F_294 () ;
}
static void F_311 ( void )
{
if ( V_543 ) {
F_17 ( V_297 | V_525 ,
L_316 ) ;
F_312 ( V_543 ) ;
}
F_294 () ;
}
static int F_313 ( struct V_88 * V_89 )
{
int V_56 ;
V_56 = V_483 ( NULL ) ;
if ( V_56 < 0 ) {
F_82 ( V_89 , L_317 ) ;
} else {
F_82 ( V_89 , L_318 , V_56 ) ;
F_82 ( V_89 , L_319 ) ;
F_82 ( V_89 , L_320 ,
V_520 ) ;
}
return 0 ;
}
static int F_314 ( char * V_128 )
{
int V_56 ;
int V_70 ;
char * V_162 ;
V_56 = V_483 ( NULL ) ;
if ( V_56 < 0 )
return V_56 ;
while ( ( V_162 = F_44 ( & V_128 ) ) ) {
if ( F_84 ( V_162 , L_321 ) == 0 ) {
if ( V_56 < V_520 )
V_56 ++ ;
} else if ( F_84 ( V_162 , L_322 ) == 0 ) {
if ( V_56 > 0 )
V_56 -- ;
} else if ( sscanf ( V_162 , L_323 , & V_56 ) == 1 &&
V_56 >= 0 && V_56 <= V_520 ) {
} else
return - V_92 ;
}
F_80 ( L_324 ,
L_325 , V_56 ) ;
V_70 = V_481 ( V_56 ) ;
if ( ! V_70 && V_543 )
F_301 ( V_543 ,
V_568 ) ;
return ( V_70 == - V_569 ) ? - V_288 : V_70 ;
}
static void F_315 ( void )
{
T_6 V_521 = 0 ;
T_6 V_522 ;
T_6 V_570 ;
if ( V_571 != V_572 )
return;
if ( ! V_573 )
return;
F_17 ( V_574 ,
L_326 ) ;
if ( V_189 . V_575 )
V_570 = V_576 ;
else
V_570 = V_576 | V_577 ;
if ( F_158 ( & V_578 ) < 0 )
return;
if ( F_139 ( ! F_11 ( V_579 , & V_521 ) ) )
goto V_528;
V_521 &= V_570 ;
V_522 = F_130 ( V_250 ) ;
if ( V_521 != ( V_522 & V_570 ) ) {
V_522 &= ~ V_570 ;
V_522 |= V_521 ;
F_295 ( V_522 , V_250 ) ;
F_20 ( V_574 ,
L_327 ,
( unsigned int ) V_521 , ( unsigned int ) V_522 ) ;
} else {
F_17 ( V_574 ,
L_328 ,
( unsigned int ) V_521 , ( unsigned int ) V_522 ) ;
}
V_528:
F_116 ( & V_578 ) ;
}
static int F_316 ( T_6 * V_30 )
{
T_6 V_120 ;
if ( ! F_11 ( V_579 , & V_120 ) )
return - V_50 ;
* V_30 = V_120 ;
F_20 ( V_574 , L_329 , V_120 ) ;
return 0 ;
}
static int F_317 ( T_6 * V_30 )
{
return F_316 ( V_30 ) ;
}
static int F_318 ( const T_6 V_30 )
{
if ( ! F_13 ( V_579 , V_30 ) )
return - V_50 ;
F_20 ( V_574 , L_330 , V_30 ) ;
return 0 ;
}
static int F_319 ( const T_6 V_30 )
{
return F_318 ( V_30 ) ;
}
static int F_320 ( const bool V_254 )
{
int V_70 ;
T_6 V_120 , V_222 ;
if ( F_158 ( & V_578 ) < 0 )
return - V_569 ;
V_70 = F_316 ( & V_120 ) ;
if ( V_70 )
goto V_528;
V_222 = ( V_254 ) ? V_120 | V_576 :
V_120 & ~ V_576 ;
if ( V_222 != V_120 ) {
V_70 = F_318 ( V_222 ) ;
if ( ! V_70 )
V_70 = 1 ;
}
V_528:
F_116 ( & V_578 ) ;
return V_70 ;
}
static int F_321 ( const bool V_254 )
{
F_20 ( V_574 , L_331 ,
( V_254 ) ? L_1 : L_40 ) ;
return F_320 ( V_254 ) ;
}
static int F_322 ( const bool V_254 )
{
int V_70 ;
F_20 ( V_574 , L_332 ,
( V_254 ) ? L_1 : L_40 ) ;
V_70 = F_320 ( V_254 ) ;
return ( V_70 < 0 ) ? V_70 : 0 ;
}
static int F_323 ( const T_6 V_580 )
{
int V_70 ;
T_6 V_120 , V_222 ;
if ( V_580 > V_581 )
return - V_92 ;
if ( F_158 ( & V_578 ) < 0 )
return - V_569 ;
V_70 = F_316 ( & V_120 ) ;
if ( V_70 )
goto V_528;
V_222 = ( V_120 & ~ V_577 ) | V_580 ;
if ( V_222 != V_120 ) {
V_70 = F_318 ( V_222 ) ;
if ( ! V_70 )
V_70 = 1 ;
}
V_528:
F_116 ( & V_578 ) ;
return V_70 ;
}
static int F_324 ( const T_6 V_580 )
{
F_20 ( V_574 ,
L_333 , V_580 ) ;
return F_323 ( V_580 ) ;
}
static void F_325 ( void )
{
struct V_582 * V_223 ;
if ( V_583 && V_583 -> V_584 ) {
V_223 = V_583 -> V_584 ;
if ( V_223 -> V_585 )
F_326 ( V_583 ,
V_586 ,
V_223 -> V_585 ) ;
if ( V_223 -> V_587 )
F_326 ( V_583 ,
V_586 ,
V_223 -> V_587 ) ;
}
}
static int F_327 ( struct V_588 * V_589 ,
struct V_590 * V_591 )
{
V_591 -> type = V_592 ;
V_591 -> V_35 = 1 ;
V_591 -> V_38 . integer . V_593 = 0 ;
V_591 -> V_38 . integer . V_129 = V_581 ;
return 0 ;
}
static int F_328 ( struct V_588 * V_589 ,
struct V_594 * V_595 )
{
T_6 V_120 ;
int V_70 ;
V_70 = F_317 ( & V_120 ) ;
if ( V_70 < 0 )
return V_70 ;
V_595 -> V_38 . integer . V_38 [ 0 ] = V_120 & V_577 ;
return 0 ;
}
static int F_329 ( struct V_588 * V_589 ,
struct V_594 * V_595 )
{
F_80 ( L_334 , L_335 ,
V_595 -> V_38 . integer . V_38 [ 0 ] ) ;
return F_324 ( V_595 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static int F_330 ( struct V_588 * V_589 ,
struct V_594 * V_595 )
{
T_6 V_120 ;
int V_70 ;
V_70 = F_317 ( & V_120 ) ;
if ( V_70 < 0 )
return V_70 ;
V_595 -> V_38 . integer . V_38 [ 0 ] =
( V_120 & V_576 ) ? 0 : 1 ;
return 0 ;
}
static int F_331 ( struct V_588 * V_589 ,
struct V_594 * V_595 )
{
F_80 ( L_334 , L_336 ,
V_595 -> V_38 . integer . V_38 [ 0 ] ?
L_40 : L_1 ) ;
return F_321 ( ! V_595 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static void F_332 ( T_12 V_110 )
{
F_315 () ;
}
static void F_333 ( void )
{
F_325 () ;
}
static void F_334 ( void )
{
F_315 () ;
}
static void F_335 ( void )
{
if ( V_583 ) {
F_336 ( V_583 ) ;
V_583 = NULL ;
}
F_315 () ;
}
static int T_1 F_337 ( void )
{
struct V_596 * V_597 ;
struct V_582 * V_63 ;
struct V_588 * V_598 ;
struct V_588 * V_599 ;
int V_70 ;
V_70 = F_338 ( V_600 , V_601 , V_602 ,
sizeof( struct V_582 ) , & V_597 ) ;
if ( V_70 < 0 || ! V_597 ) {
F_8 ( L_337 , V_70 ) ;
return 1 ;
}
F_23 ( ! V_597 -> V_584 ) ;
V_63 = V_597 -> V_584 ;
V_63 -> V_597 = V_597 ;
F_339 ( V_597 -> V_79 , V_603 ,
sizeof( V_597 -> V_79 ) ) ;
F_339 ( V_597 -> V_604 , V_605 ,
sizeof( V_597 -> V_604 ) ) ;
snprintf ( V_597 -> V_606 , sizeof( V_597 -> V_606 ) , L_338 ,
( V_7 . V_607 ) ?
V_7 . V_607 : L_339 ) ;
snprintf ( V_597 -> V_608 , sizeof( V_597 -> V_608 ) ,
L_340 , V_597 -> V_604 , V_579 ,
( V_7 . V_607 ) ?
V_7 . V_607 : L_341 ) ;
if ( V_573 ) {
V_609 . V_610 = F_329 ;
V_609 . V_611 =
V_612 ;
V_613 . V_610 = F_331 ;
V_613 . V_611 =
V_612 ;
}
if ( ! V_189 . V_575 ) {
V_598 = F_340 ( & V_609 , NULL ) ;
V_70 = F_341 ( V_597 , V_598 ) ;
if ( V_70 < 0 ) {
F_8 ( L_342 ,
V_70 ) ;
goto V_335;
}
V_63 -> V_587 = & V_598 -> V_146 ;
}
V_599 = F_340 ( & V_613 , NULL ) ;
V_70 = F_341 ( V_597 , V_599 ) ;
if ( V_70 < 0 ) {
F_8 ( L_343 , V_70 ) ;
goto V_335;
}
V_63 -> V_585 = & V_599 -> V_146 ;
F_342 ( V_597 , & V_156 -> V_157 ) ;
V_70 = F_343 ( V_597 ) ;
if ( V_70 < 0 ) {
F_8 ( L_344 , V_70 ) ;
goto V_335;
}
V_583 = V_597 ;
return 0 ;
V_335:
F_336 ( V_597 ) ;
return 1 ;
}
static int T_1 F_344 ( struct V_300 * V_301 )
{
unsigned long V_13 ;
int V_70 ;
F_17 ( V_55 , L_345 ) ;
F_185 ( & V_578 ) ;
if ( V_571 > V_614 )
return - V_92 ;
if ( V_571 == V_615 ) {
F_8 ( L_346
L_295 , V_336 ) ;
return 1 ;
}
if ( V_616 >= V_617 )
return - V_92 ;
if ( ! V_618 ) {
F_17 ( V_55 | V_574 ,
L_347
L_348 ) ;
return 1 ;
}
V_13 = F_4 ( V_619 ,
F_98 ( V_619 ) ) ;
switch ( V_616 ) {
case V_620 :
if ( V_13 & V_621 )
V_189 . V_575 = 1 ;
else if ( V_13 & V_622 )
V_189 . V_575 = 0 ;
else
return 1 ;
break;
case V_623 :
V_189 . V_575 = 0 ;
break;
case V_624 :
V_189 . V_575 = 1 ;
break;
default:
return 1 ;
}
if ( V_616 != V_620 )
F_20 ( V_55 | V_574 ,
L_349 ,
V_616 ) ;
if ( V_571 == V_625 ||
V_571 == V_614 ) {
V_571 = V_572 ;
F_20 ( V_55 | V_574 ,
L_350 ,
V_571 ) ;
} else {
F_20 ( V_55 | V_574 ,
L_351 ,
V_571 ) ;
}
F_17 ( V_55 | V_574 ,
L_352 ,
F_1 ( ! V_189 . V_575 ) ) ;
V_70 = F_337 () ;
if ( V_70 ) {
F_8 ( L_353 ) ;
return V_70 ;
}
F_74 ( L_354 ,
( V_573 ) ?
L_355 :
L_356 ) ;
F_17 ( V_55 | V_574 ,
L_357 ) ;
F_112 ( V_198
| V_626
| V_627
| V_628 ) ;
return 0 ;
}
static int F_345 ( struct V_88 * V_89 )
{
T_6 V_30 ;
if ( F_317 ( & V_30 ) < 0 ) {
F_82 ( V_89 , L_317 ) ;
} else {
if ( V_189 . V_575 )
F_82 ( V_89 , L_358 ) ;
else
F_82 ( V_89 , L_318 ,
V_30 & V_577 ) ;
F_82 ( V_89 , L_359 ,
F_257 ( V_30 , V_629 ) ) ;
if ( V_573 ) {
F_82 ( V_89 , L_360 ) ;
if ( ! V_189 . V_575 ) {
F_82 ( V_89 ,
L_319 ) ;
F_82 ( V_89 ,
L_361
L_362 ,
V_581 ) ;
}
}
}
return 0 ;
}
static int F_346 ( char * V_128 )
{
T_6 V_120 ;
T_6 V_630 , V_631 ;
int V_632 ;
char * V_162 ;
int V_70 ;
if ( ! V_573 && V_66 != V_286 ) {
if ( F_139 ( ! V_203 . V_633 ) ) {
V_203 . V_633 = 1 ;
F_31 ( L_363
L_364 ) ;
F_31 ( L_365
L_366 ) ;
}
return - V_161 ;
}
V_70 = F_317 ( & V_120 ) ;
if ( V_70 < 0 )
return V_70 ;
V_630 = V_120 & V_577 ;
V_631 = V_120 & V_576 ;
while ( ( V_162 = F_44 ( & V_128 ) ) ) {
if ( ! V_189 . V_575 ) {
if ( F_84 ( V_162 , L_321 ) == 0 ) {
if ( V_631 )
V_631 = 0 ;
else if ( V_630 < V_581 )
V_630 ++ ;
continue;
} else if ( F_84 ( V_162 , L_322 ) == 0 ) {
if ( V_631 )
V_631 = 0 ;
else if ( V_630 > 0 )
V_630 -- ;
continue;
} else if ( sscanf ( V_162 , L_367 , & V_632 ) == 1 &&
V_632 >= 0 && V_632 <= V_581 ) {
V_630 = V_632 ;
continue;
}
}
if ( F_84 ( V_162 , L_368 ) == 0 )
V_631 = V_576 ;
else if ( F_84 ( V_162 , L_369 ) == 0 )
V_631 = 0 ;
else
return - V_92 ;
}
if ( V_189 . V_575 ) {
F_80 ( L_370 , L_336 ,
V_631 ? L_1 : L_40 ) ;
V_70 = F_322 ( ! ! V_631 ) ;
} else {
F_80 ( L_370 ,
L_371 ,
V_631 ? L_1 : L_40 , V_630 ) ;
V_70 = F_319 ( V_631 | V_630 ) ;
}
F_325 () ;
return ( V_70 == - V_569 ) ? - V_288 : V_70 ;
}
static void inline F_325 ( void )
{
}
static int T_1 F_344 ( struct V_300 * V_301 )
{
F_74 ( L_372 ) ;
return 1 ;
}
static void F_347 ( void )
{
if ( V_634 == 0x07 ) {
F_31 ( L_373
L_374 ) ;
V_189 . V_635 = 1 ;
}
}
static void F_348 ( T_6 * V_636 )
{
if ( F_139 ( V_189 . V_635 ) ) {
if ( * V_636 != V_634 ) {
V_189 . V_635 = 0 ;
} else {
* V_636 = V_637 ;
}
}
}
static bool F_349 ( void )
{
if ( V_189 . V_638 ) {
T_6 V_639 ;
if ( F_12 ( V_640 , & V_639 ) < 0 )
return false ;
V_639 &= 0xFEU ;
if ( F_14 ( V_640 , V_639 ) < 0 )
return false ;
}
return true ;
}
static bool F_350 ( void )
{
T_6 V_639 ;
if ( ! V_189 . V_638 )
return false ;
if ( F_12 ( V_640 , & V_639 ) < 0 )
return false ;
V_639 |= 0x01U ;
if ( F_14 ( V_640 , V_639 ) < 0 )
return false ;
return true ;
}
static void F_351 ( T_6 V_30 )
{
if ( ( V_30 &
( V_637 | V_641 ) ) == 0 ) {
if ( V_30 > 7 )
V_642 = 7 ;
else
V_642 = V_30 ;
}
}
static int F_352 ( T_6 * V_30 )
{
T_6 V_120 ;
switch ( V_643 ) {
case V_644 :
if ( F_139 ( ! F_7 ( V_645 , & V_120 , NULL , L_62 ) ) )
return - V_50 ;
if ( F_137 ( V_30 ) )
* V_30 = V_120 & 0x07 ;
break;
case V_646 :
if ( F_139 ( ! F_11 ( V_647 , & V_120 ) ) )
return - V_50 ;
if ( F_137 ( V_30 ) ) {
* V_30 = V_120 ;
F_348 ( V_30 ) ;
}
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_353 ( T_6 * V_30 )
{
int V_70 ;
T_6 V_120 ;
if ( F_158 ( & V_648 ) )
return - V_288 ;
V_70 = F_352 ( & V_120 ) ;
if ( ! V_70 )
F_351 ( V_120 ) ;
F_116 ( & V_648 ) ;
if ( V_30 )
* V_30 = V_120 ;
return V_70 ;
}
static int F_354 ( unsigned int * V_649 )
{
T_6 V_650 , V_651 ;
switch ( V_643 ) {
case V_646 :
if ( F_139 ( ! F_349 () ) )
return - V_50 ;
if ( F_139 ( ! F_11 ( V_652 , & V_651 ) ||
! F_11 ( V_652 + 1 , & V_650 ) ) )
return - V_50 ;
if ( F_137 ( V_649 ) )
* V_649 = ( V_650 << 8 ) | V_651 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_355 ( unsigned int * V_649 )
{
T_6 V_650 , V_651 ;
bool V_70 ;
switch ( V_643 ) {
case V_646 :
if ( F_139 ( ! F_350 () ) )
return - V_50 ;
V_70 = ! F_11 ( V_652 , & V_651 ) ||
! F_11 ( V_652 + 1 , & V_650 ) ;
F_349 () ;
if ( V_70 )
return - V_50 ;
if ( F_137 ( V_649 ) )
* V_649 = ( V_650 << 8 ) | V_651 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_356 ( int V_56 )
{
if ( ! V_653 )
return - V_161 ;
switch ( V_654 ) {
case V_655 :
if ( V_56 >= 0 && V_56 <= 7 ) {
if ( ! F_7 ( V_656 , NULL , NULL , L_9 , V_56 ) )
return - V_50 ;
} else
return - V_92 ;
break;
case V_657 :
case V_658 :
if ( ! ( V_56 & V_637 ) &&
! ( V_56 & V_641 ) &&
( ( V_56 < 0 ) || ( V_56 > 7 ) ) )
return - V_92 ;
if ( V_56 & V_641 )
V_56 |= 7 ;
else if ( V_56 & V_637 )
V_56 |= 4 ;
if ( ! F_13 ( V_647 , V_56 ) )
return - V_50 ;
else
V_189 . V_635 = 0 ;
break;
default:
return - V_49 ;
}
F_17 ( V_659 ,
L_375 , V_56 ) ;
return 0 ;
}
static int F_357 ( int V_56 )
{
int V_70 ;
if ( ! V_653 )
return - V_161 ;
if ( F_158 ( & V_648 ) )
return - V_288 ;
if ( V_56 == V_660 )
V_56 = V_642 ;
V_70 = F_356 ( V_56 ) ;
if ( ! V_70 )
F_351 ( V_56 ) ;
F_116 ( & V_648 ) ;
return V_70 ;
}
static int F_358 ( void )
{
T_6 V_120 ;
int V_70 ;
if ( ! V_653 )
return - V_161 ;
if ( F_158 ( & V_648 ) )
return - V_288 ;
switch ( V_654 ) {
case V_657 :
case V_658 :
V_70 = F_352 ( & V_120 ) ;
if ( V_70 < 0 )
break;
if ( V_120 != 7 ) {
V_120 &= 0x07 ;
V_120 |= V_637 | 4 ;
}
if ( ! F_13 ( V_647 , V_120 ) )
V_70 = - V_50 ;
else {
V_189 . V_635 = 0 ;
V_70 = 0 ;
}
break;
case V_655 :
V_70 = F_352 ( & V_120 ) ;
if ( V_70 < 0 )
break;
V_120 &= 0x07 ;
V_120 |= 4 ;
if ( ! F_7 ( V_656 , NULL , NULL , L_9 , V_120 ) )
V_70 = - V_50 ;
else
V_70 = 0 ;
break;
default:
V_70 = - V_49 ;
}
F_116 ( & V_648 ) ;
if ( ! V_70 )
F_17 ( V_659 ,
L_375 ,
V_120 ) ;
return V_70 ;
}
static int F_359 ( void )
{
int V_70 ;
if ( ! V_653 )
return - V_161 ;
if ( F_158 ( & V_648 ) )
return - V_288 ;
V_70 = 0 ;
switch ( V_654 ) {
case V_657 :
case V_658 :
if ( ! F_13 ( V_647 , 0x00 ) )
V_70 = - V_50 ;
else {
V_642 = 0 ;
V_189 . V_635 = 0 ;
}
break;
case V_655 :
if ( ! F_7 ( V_656 , NULL , NULL , L_9 , 0x00 ) )
V_70 = - V_50 ;
else
V_642 = 0 ;
break;
default:
V_70 = - V_49 ;
}
if ( ! V_70 )
F_17 ( V_659 ,
L_376 ) ;
F_116 ( & V_648 ) ;
return V_70 ;
}
static int F_360 ( int V_649 )
{
int V_70 ;
if ( ! V_653 )
return - V_161 ;
if ( F_158 ( & V_648 ) )
return - V_288 ;
V_70 = 0 ;
switch ( V_654 ) {
case V_657 :
if ( V_649 >= 0 && V_649 <= 65535 ) {
if ( ! F_7 ( V_661 , NULL , NULL , L_377 ,
V_649 , V_649 , V_649 ) )
V_70 = - V_50 ;
} else
V_70 = - V_92 ;
break;
default:
V_70 = - V_49 ;
}
F_116 ( & V_648 ) ;
return V_70 ;
}
static void F_361 ( void )
{
static int V_662 ;
if ( V_654 == V_663 )
return;
if ( V_662 )
F_362 ( & V_664 ) ;
if ( V_665 > 0 &&
V_66 != V_202 ) {
V_662 = 1 ;
if ( ! F_363 ( V_450 , & V_664 ,
F_364 ( V_665
* 1000 ) ) ) {
F_8 ( L_378
L_379 ) ;
}
} else
V_662 = 0 ;
}
static void F_365 ( struct V_439 * V_666 )
{
int V_70 ;
if ( V_66 != V_67 )
return;
F_31 ( L_380 ) ;
V_70 = F_358 () ;
if ( V_70 < 0 ) {
F_8 ( L_381
L_382 , - V_70 ) ;
F_361 () ;
}
}
static T_8 F_366 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
int V_17 , V_667 ;
T_6 V_30 ;
V_17 = F_353 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 & V_641 ) {
V_667 = 0 ;
} else if ( V_30 & V_637 ) {
V_667 = 2 ;
} else
V_667 = 1 ;
return snprintf ( V_128 , V_103 , L_42 , V_667 ) ;
}
static T_8 F_367 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
int V_17 , V_56 ;
if ( F_55 ( V_128 , 2 , & V_160 ) )
return - V_92 ;
F_80 ( L_383 ,
L_384 , V_160 ) ;
switch ( V_160 ) {
case 0 :
V_56 = V_641 ;
break;
case 1 :
V_56 = V_660 ;
break;
case 2 :
V_56 = V_637 ;
break;
case 3 :
return - V_427 ;
default:
return - V_92 ;
}
V_17 = F_357 ( V_56 ) ;
if ( V_17 == - V_49 )
return - V_92 ;
else if ( V_17 < 0 )
return V_17 ;
F_361 () ;
return V_35 ;
}
static T_8 F_368 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
int V_17 ;
T_6 V_30 ;
V_17 = F_353 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_30 &
( V_637 | V_641 ) ) != 0 )
V_30 = V_642 ;
if ( V_30 > 7 )
V_30 = 7 ;
return snprintf ( V_128 , V_103 , L_385 , ( V_30 * 255 ) / 7 ) ;
}
static T_8 F_369 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_120 ;
int V_70 ;
T_6 V_30 , V_668 ;
if ( F_55 ( V_128 , 255 , & V_120 ) )
return - V_92 ;
F_80 ( L_386 ,
L_387 , V_120 ) ;
V_668 = ( V_120 >> 5 ) & 0x07 ;
if ( F_158 ( & V_648 ) )
return - V_288 ;
V_70 = F_352 ( & V_30 ) ;
if ( ! V_70 && ( V_30 &
( V_637 | V_641 ) ) == 0 ) {
V_70 = F_356 ( V_668 ) ;
if ( V_70 == - V_49 )
V_70 = - V_92 ;
else if ( ! V_70 ) {
F_351 ( V_668 ) ;
F_361 () ;
}
}
F_116 ( & V_648 ) ;
return ( V_70 ) ? V_70 : V_35 ;
}
static T_8 F_370 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
int V_17 ;
unsigned int V_649 ;
V_17 = F_354 ( & V_649 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_128 , V_103 , L_385 , V_649 ) ;
}
static T_8 F_371 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
int V_17 ;
unsigned int V_649 ;
V_17 = F_355 ( & V_649 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_128 , V_103 , L_385 , V_649 ) ;
}
static T_8 F_372 ( struct V_164 * V_165 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_385 , V_665 ) ;
}
static T_8 F_373 ( struct V_164 * V_165 ,
const char * V_128 , T_10 V_35 )
{
unsigned long V_160 ;
if ( F_55 ( V_128 , 120 , & V_160 ) )
return - V_92 ;
if ( ! V_653 )
return - V_161 ;
V_665 = V_160 ;
F_361 () ;
F_80 ( L_388 , L_94 , V_160 ) ;
return V_35 ;
}
static int T_1 F_374 ( struct V_300 * V_301 )
{
int V_70 ;
unsigned long V_13 ;
F_17 ( V_55 | V_659 ,
L_389 ) ;
F_185 ( & V_648 ) ;
V_643 = V_669 ;
V_654 = V_663 ;
V_670 = 0 ;
V_665 = 0 ;
V_189 . V_635 = 0 ;
V_189 . V_638 = 0 ;
V_642 = 7 ;
if ( F_6 () ) {
F_184 ( V_671 ) ;
F_184 ( V_672 ) ;
F_184 ( V_673 ) ;
}
V_13 = F_4 ( V_674 ,
F_98 ( V_674 ) ) ;
if ( V_645 ) {
V_643 = V_644 ;
} else {
if ( F_137 ( F_11 ( V_647 ,
& V_634 ) ) ) {
V_643 = V_646 ;
if ( V_13 & V_675 )
F_347 () ;
if ( V_13 & V_676 ) {
V_189 . V_638 = 1 ;
F_20 ( V_55 | V_659 ,
L_390 ) ;
}
} else {
F_8 ( L_275
L_391 ) ;
return 1 ;
}
}
if ( V_656 ) {
V_654 = V_655 ;
V_670 |=
V_677 | V_678 ;
} else {
if ( ! V_645 ) {
if ( V_661 ) {
V_654 =
V_657 ;
V_670 |=
V_679 |
V_677 |
V_678 ;
} else {
V_654 = V_658 ;
V_670 |=
V_677 |
V_678 ;
}
}
}
F_17 ( V_55 | V_659 ,
L_392 ,
F_1 ( V_643 != V_669 ||
V_654 != V_663 ) ,
V_643 , V_654 ) ;
if ( ! V_653 ) {
V_654 = V_663 ;
V_670 = 0 ;
F_20 ( V_55 | V_659 ,
L_393 ) ;
}
if ( V_643 != V_669 )
F_353 ( NULL ) ;
if ( V_643 != V_669 ||
V_654 != V_663 ) {
if ( V_189 . V_638 ) {
V_680 [ F_98 ( V_680 ) - 2 ] =
& V_681 . V_124 ;
}
V_70 = F_215 ( & V_516 -> V_157 . V_127 ,
& V_682 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_99 ( & V_683 . V_79 ,
& V_684 ) ;
if ( V_70 < 0 ) {
F_53 ( & V_516 -> V_157 . V_127 ,
& V_682 ) ;
return V_70 ;
}
return 0 ;
} else
return 1 ;
}
static void F_375 ( void )
{
F_17 ( V_297 | V_659 ,
L_394 ) ;
F_53 ( & V_516 -> V_157 . V_127 , & V_682 ) ;
F_102 ( & V_683 . V_79 ,
& V_684 ) ;
F_362 ( & V_664 ) ;
F_255 ( V_450 ) ;
}
static void F_376 ( T_12 V_110 )
{
int V_70 ;
if ( ! V_653 )
return;
V_685 = 0 ;
V_70 = F_353 ( & V_685 ) ;
if ( V_70 < 0 )
F_31 ( L_395
L_396 , V_70 ) ;
if ( V_189 . V_635 )
V_685 = 0 ;
}
static void F_377 ( void )
{
T_6 V_686 = 7 ;
bool V_687 = false ;
int V_70 ;
V_189 . V_635 = 0 ;
if ( ! V_653 ||
! V_685 ||
( F_353 ( & V_686 ) < 0 ) )
return;
switch ( V_654 ) {
case V_655 :
V_687 = ( V_685 > V_686 ) ;
break;
case V_657 :
case V_658 :
if ( V_685 != 7 &&
! ( V_685 & V_641 ) )
return;
else
V_687 = ! ( V_686 & V_641 ) &&
( V_686 != V_685 ) ;
break;
default:
return;
}
if ( V_687 ) {
F_31 ( L_397 ,
V_685 ) ;
V_70 = F_357 ( V_685 ) ;
if ( V_70 < 0 )
F_31 ( L_398 , V_70 ) ;
}
}
static int F_378 ( struct V_88 * V_89 )
{
int V_70 ;
T_6 V_30 ;
unsigned int V_649 = 0 ;
switch ( V_643 ) {
case V_644 :
V_70 = F_353 ( & V_30 ) ;
if ( V_70 < 0 )
return V_70 ;
F_82 ( V_89 , L_45
L_318 ,
( V_30 != 0 ) ? L_46 : L_47 , V_30 ) ;
break;
case V_646 :
V_70 = F_353 ( & V_30 ) ;
if ( V_70 < 0 )
return V_70 ;
F_82 ( V_89 , L_45 ,
( V_30 != 0 ) ? L_46 : L_47 ) ;
V_70 = F_354 ( & V_649 ) ;
if ( V_70 < 0 )
return V_70 ;
F_82 ( V_89 , L_399 , V_649 ) ;
if ( V_30 & V_641 )
F_82 ( V_89 , L_400 ) ;
else if ( V_30 & V_637 )
F_82 ( V_89 , L_401 ) ;
else
F_82 ( V_89 , L_318 , V_30 ) ;
break;
case V_669 :
default:
F_82 ( V_89 , L_44 ) ;
}
if ( V_670 & V_677 ) {
F_82 ( V_89 , L_361 ) ;
switch ( V_654 ) {
case V_655 :
F_82 ( V_89 , L_402 ) ;
break;
default:
F_82 ( V_89 , L_403
L_404 ) ;
break;
}
}
if ( V_670 & V_678 )
F_82 ( V_89 , L_48
L_405
L_406 ) ;
if ( V_670 & V_679 )
F_82 ( V_89 , L_407
L_408 ) ;
return 0 ;
}
static int F_379 ( const char * V_162 , int * V_70 )
{
int V_56 ;
if ( F_84 ( V_162 , L_409 ) == 0 )
V_56 = V_637 ;
else if ( ( F_84 ( V_162 , L_410 ) == 0 ) |
( F_84 ( V_162 , L_411 ) == 0 ) )
V_56 = V_641 ;
else if ( sscanf ( V_162 , L_323 , & V_56 ) != 1 )
return 0 ;
* V_70 = F_357 ( V_56 ) ;
if ( * V_70 == - V_49 )
F_8 ( L_412 ,
V_654 ) ;
else if ( ! * V_70 )
F_80 ( L_413 ,
L_325 , V_56 ) ;
return 1 ;
}
static int F_380 ( const char * V_162 , int * V_70 )
{
if ( F_84 ( V_162 , L_49 ) != 0 )
return 0 ;
* V_70 = F_358 () ;
if ( * V_70 == - V_49 )
F_8 ( L_414 ,
V_654 ) ;
else if ( ! * V_70 )
F_80 ( L_413 , L_415 ) ;
return 1 ;
}
static int F_381 ( const char * V_162 , int * V_70 )
{
if ( F_84 ( V_162 , L_50 ) != 0 )
return 0 ;
* V_70 = F_359 () ;
if ( * V_70 == - V_49 )
F_8 ( L_416 ,
V_654 ) ;
else if ( ! * V_70 )
F_80 ( L_413 , L_417 ) ;
return 1 ;
}
static int F_382 ( const char * V_162 , int * V_70 )
{
int V_649 ;
if ( sscanf ( V_162 , L_418 , & V_649 ) != 1 )
return 0 ;
* V_70 = F_360 ( V_649 ) ;
if ( * V_70 == - V_49 )
F_8 ( L_419 ,
V_654 ) ;
else if ( ! * V_70 )
F_80 ( L_413 ,
L_420 , V_649 ) ;
return 1 ;
}
static int F_383 ( const char * V_162 , int * V_70 )
{
int V_688 ;
if ( sscanf ( V_162 , L_421 , & V_688 ) != 1 )
return 0 ;
if ( V_688 < 0 || V_688 > 120 )
* V_70 = - V_92 ;
else {
V_665 = V_688 ;
F_80 ( L_413 ,
L_422 ,
V_688 ) ;
}
return 1 ;
}
static int F_384 ( char * V_128 )
{
char * V_162 ;
int V_70 = 0 ;
while ( ! V_70 && ( V_162 = F_44 ( & V_128 ) ) ) {
if ( ! ( ( V_670 & V_677 ) &&
F_379 ( V_162 , & V_70 ) ) &&
! ( ( V_670 & V_678 ) &&
( F_380 ( V_162 , & V_70 ) ||
F_381 ( V_162 , & V_70 ) ||
F_383 ( V_162 , & V_70 ) ) ) &&
! ( ( V_670 & V_679 ) &&
F_382 ( V_162 , & V_70 ) )
)
V_70 = - V_92 ;
else if ( ! V_70 )
F_361 () ;
}
return V_70 ;
}
static void F_385 ( const unsigned int V_689 )
{
if ( V_543 ) {
switch ( V_689 ) {
case V_690 :
case V_691 :
F_300 () ;
}
}
if ( V_583 ) {
switch ( V_689 ) {
case V_692 :
case V_693 :
case V_694 :
F_325 () ;
}
}
}
static void F_126 ( const unsigned int V_212 )
{
F_385 ( V_220 + V_212 ) ;
}
static T_8 F_386 ( struct V_71 * V_157 ,
struct V_159 * V_124 ,
char * V_128 )
{
return snprintf ( V_128 , V_103 , L_423 , V_83 ) ;
}
static const char * T_1 F_1 ( int V_1 )
{
static char V_695 [] V_696 = L_424 ;
return ( V_1 ) ? & V_695 [ 4 ] : & V_695 [ 0 ] ;
}
static void F_387 ( struct V_64 * V_65 )
{
F_20 ( V_297 , L_425 , V_65 -> V_51 ) ;
F_388 ( & V_65 -> V_697 ) ;
if ( V_65 -> V_76 . V_77 ) {
F_20 ( V_297 ,
L_426 , V_65 -> V_51 ) ;
F_23 ( ! V_65 -> V_68 ) ;
F_389 ( * V_65 -> V_68 -> V_16 ,
V_65 -> V_68 -> type ,
F_25 ) ;
V_65 -> V_76 . V_77 = 0 ;
}
if ( V_65 -> V_76 . V_698 ) {
F_20 ( V_297 ,
L_427 , V_65 -> V_51 ) ;
F_390 ( V_65 -> V_51 , V_699 ) ;
V_65 -> V_76 . V_698 = 0 ;
}
if ( V_65 -> V_76 . V_87 ) {
F_20 ( V_297 ,
L_428 , V_65 -> V_51 ) ;
F_23 ( ! V_65 -> V_68 ) ;
F_391 ( V_65 -> V_68 -> V_79 ) ;
F_36 ( V_65 -> V_68 -> V_79 ) ;
V_65 -> V_68 -> V_79 = NULL ;
V_65 -> V_76 . V_87 = 0 ;
}
if ( V_65 -> V_76 . V_700 && V_65 -> exit ) {
V_65 -> exit () ;
V_65 -> V_76 . V_700 = 0 ;
}
F_20 ( V_55 , L_429 , V_65 -> V_51 ) ;
}
static int T_1 F_392 ( struct V_300 * V_301 )
{
int V_101 ;
struct V_64 * V_65 = V_301 -> V_63 ;
struct V_701 * V_702 ;
F_23 ( V_65 == NULL ) ;
F_393 ( & V_65 -> V_697 ) ;
if ( V_65 -> V_76 . V_703 && ! V_703 )
return 0 ;
F_20 ( V_55 ,
L_430 , V_65 -> V_51 ) ;
if ( V_301 -> V_704 ) {
V_101 = V_301 -> V_704 ( V_301 ) ;
if ( V_101 > 0 )
return 0 ;
if ( V_101 )
return V_101 ;
V_65 -> V_76 . V_700 = 1 ;
}
if ( V_65 -> V_68 ) {
if ( V_65 -> V_68 -> V_60 ) {
V_101 = F_33 ( V_65 ) ;
if ( V_101 )
goto V_705;
}
if ( V_65 -> V_68 -> V_69 ) {
V_101 = F_26 ( V_65 ) ;
if ( V_101 == - V_72 ) {
F_31 ( L_431 ,
V_65 -> V_51 ) ;
V_101 = 0 ;
goto V_705;
}
if ( V_101 < 0 )
goto V_705;
}
}
F_20 ( V_55 ,
L_432 , V_65 -> V_51 ) ;
if ( V_65 -> V_91 ) {
T_20 V_667 = V_301 -> V_706 ;
if ( ! V_667 )
V_667 = V_707 ;
if ( V_65 -> V_102 )
V_667 |= V_708 ;
V_702 = F_394 ( V_65 -> V_51 , V_667 , V_699 ,
& V_709 , V_65 ) ;
if ( ! V_702 ) {
F_8 ( L_433 , V_65 -> V_51 ) ;
V_101 = - V_72 ;
goto V_705;
}
V_65 -> V_76 . V_698 = 1 ;
}
F_395 ( & V_65 -> V_697 , & V_710 ) ;
return 0 ;
V_705:
F_20 ( V_55 ,
L_434 ,
V_65 -> V_51 , V_101 ) ;
F_387 ( V_65 ) ;
return ( V_101 < 0 ) ? V_101 : 0 ;
}
static bool T_2 T_1 F_396 ( const char V_37 )
{
return ( V_37 >= '0' && V_37 <= '9' ) || ( V_37 >= 'A' && V_37 <= 'Z' ) ;
}
static bool T_2 T_1 F_397 ( const char * const V_120 ,
const char V_160 )
{
return V_120 && strlen ( V_120 ) >= 8 &&
F_396 ( V_120 [ 0 ] ) &&
F_396 ( V_120 [ 1 ] ) &&
V_120 [ 2 ] == V_160 && V_120 [ 3 ] == 'T' &&
F_396 ( V_120 [ 4 ] ) &&
F_396 ( V_120 [ 5 ] ) ;
}
static int T_21 T_1 F_398 (
struct V_711 * V_712 )
{
const struct V_713 * V_157 = NULL ;
char V_714 [ 18 ] ;
char const * V_120 ;
if ( ! V_712 )
return - V_92 ;
memset ( V_712 , 0 , sizeof( * V_712 ) ) ;
if ( F_399 ( L_435 ) )
V_712 -> V_6 = V_15 ;
else if ( F_399 ( L_436 ) )
V_712 -> V_6 = V_14 ;
else
return 0 ;
V_120 = F_400 ( V_715 ) ;
V_712 -> V_716 = F_401 ( V_120 , V_81 ) ;
if ( V_120 && ! V_712 -> V_716 )
return - V_82 ;
if ( ! F_397 ( V_712 -> V_716 , 'E' ) )
return 0 ;
V_712 -> V_10 = V_712 -> V_716 [ 0 ]
| ( V_712 -> V_716 [ 1 ] << 8 ) ;
V_712 -> V_187 = ( V_712 -> V_716 [ 4 ] << 8 )
| V_712 -> V_716 [ 5 ] ;
while ( ( V_157 = F_402 ( V_717 , NULL , V_157 ) ) ) {
if ( sscanf ( V_157 -> V_51 ,
L_437 ,
V_714 ) == 1 ) {
V_714 [ sizeof( V_714 ) - 1 ] = 0 ;
V_714 [ strcspn ( V_714 , L_438 ) ] = 0 ;
V_712 -> V_607 = F_401 ( V_714 , V_81 ) ;
if ( ! V_712 -> V_607 )
return - V_82 ;
if ( F_397 ( V_714 , 'H' ) ) {
V_712 -> V_12 = V_714 [ 0 ]
| ( V_714 [ 1 ] << 8 ) ;
V_712 -> V_188 = ( V_714 [ 4 ] << 8 )
| V_714 [ 5 ] ;
} else {
F_31 ( L_439
L_440 ,
V_714 ) ;
F_31 ( L_107 ,
V_336 ) ;
}
break;
}
}
V_120 = F_400 ( V_718 ) ;
if ( V_120 && ! F_403 ( V_120 , L_441 , 8 ) ) {
V_712 -> V_719 = F_401 ( V_120 , V_81 ) ;
if ( ! V_712 -> V_719 )
return - V_82 ;
}
V_120 = F_400 ( V_720 ) ;
V_712 -> V_721 = F_401 ( V_120 , V_81 ) ;
if ( V_120 && ! V_712 -> V_721 )
return - V_82 ;
return 0 ;
}
static int T_1 F_404 ( void )
{
int V_722 ;
if ( V_723 )
return - V_72 ;
if ( ! F_6 () && ! F_5 () )
return - V_72 ;
V_722 = ( V_7 . V_719 != NULL ) ||
( V_7 . V_12 != 0 ) ||
F_105 () ;
F_22 ( L_442 , V_724 , & V_431 ) ;
if ( ! V_431 ) {
if ( V_722 )
F_8 ( L_443 ) ;
return - V_72 ;
}
if ( ! V_722 && ! V_725 )
return - V_72 ;
return 0 ;
}
static void T_1 F_405 ( void )
{
F_74 ( L_55 , V_168 , V_169 ) ;
F_74 ( L_423 , V_726 ) ;
F_74 ( L_444 ,
( V_7 . V_716 ) ?
V_7 . V_716 : L_341 ,
( V_7 . V_607 ) ?
V_7 . V_607 : L_341 ) ;
F_23 ( ! V_7 . V_6 ) ;
if ( V_7 . V_719 )
F_74 ( L_445 ,
( V_7 . V_6 == V_15 ) ?
L_435 : ( ( V_7 . V_6 ==
V_14 ) ?
L_446 : L_447 ) ,
V_7 . V_719 ,
( V_7 . V_721 ) ?
V_7 . V_721 : L_341 ) ;
}
static int T_1 F_406 ( const char * V_639 , struct V_727 * V_728 )
{
unsigned int V_42 ;
struct V_64 * V_65 ;
if ( ! V_728 || ! V_728 -> V_51 || ! V_639 )
return - V_92 ;
for ( V_42 = 0 ; V_42 < F_98 ( V_729 ) ; V_42 ++ ) {
V_65 = V_729 [ V_42 ] . V_63 ;
F_407 ( V_65 == NULL ) ;
if ( ! V_65 || ! V_65 -> V_51 )
continue;
if ( strcmp ( V_65 -> V_51 , V_728 -> V_51 ) == 0 && V_65 -> V_102 ) {
if ( strlen ( V_639 ) > sizeof( V_729 [ V_42 ] . V_730 ) - 2 )
return - V_731 ;
strcpy ( V_729 [ V_42 ] . V_730 , V_639 ) ;
strcat ( V_729 [ V_42 ] . V_730 , L_26 ) ;
return 0 ;
}
}
return - V_92 ;
}
static void F_408 ( void )
{
struct V_64 * V_65 , * V_111 ;
V_66 = V_202 ;
F_409 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
F_387 ( V_65 ) ;
}
F_20 ( V_55 , L_448 ) ;
if ( V_210 ) {
if ( V_189 . V_732 )
F_410 ( V_210 ) ;
else
F_411 ( V_210 ) ;
}
if ( V_733 )
F_412 ( V_733 ) ;
if ( V_189 . V_734 )
F_263 ( & V_516 -> V_157 ,
& V_735 ) ;
if ( V_516 )
F_413 ( V_516 ) ;
if ( V_156 )
F_413 ( V_156 ) ;
if ( V_189 . V_736 )
F_101 ( & V_683 . V_79 ) ;
if ( V_189 . V_737 )
F_101 ( & V_738 . V_79 ) ;
if ( V_189 . V_739 )
F_414 ( & V_683 ) ;
if ( V_189 . V_740 )
F_414 ( & V_738 ) ;
if ( V_699 )
F_390 ( V_741 , V_742 ) ;
if ( V_450 )
F_415 ( V_450 ) ;
F_36 ( V_7 . V_716 ) ;
F_36 ( V_7 . V_607 ) ;
F_36 ( V_7 . V_719 ) ;
}
static int T_1 F_416 ( void )
{
int V_101 , V_42 ;
V_66 = V_286 ;
if ( V_218 > 2 )
return - V_92 ;
V_101 = F_398 ( & V_7 ) ;
if ( V_101 ) {
F_8 ( L_449 , V_101 ) ;
F_408 () ;
return V_101 ;
}
V_101 = F_404 () ;
if ( V_101 ) {
F_408 () ;
return V_101 ;
}
F_405 () ;
F_104 () ;
F_184 ( V_743 ) ;
F_184 ( V_744 ) ;
V_450 = F_417 ( V_745 ) ;
if ( ! V_450 ) {
F_408 () ;
return - V_82 ;
}
V_699 = F_418 ( V_741 , V_742 ) ;
if ( ! V_699 ) {
F_8 ( L_450 V_741 L_272 ) ;
F_408 () ;
return - V_72 ;
}
V_101 = F_419 ( & V_738 ) ;
if ( V_101 ) {
F_8 ( L_451 ) ;
F_408 () ;
return V_101 ;
}
V_189 . V_740 = 1 ;
V_101 = F_419 ( & V_683 ) ;
if ( V_101 ) {
F_8 ( L_452 ) ;
F_408 () ;
return V_101 ;
}
V_189 . V_739 = 1 ;
V_101 = F_97 ( & V_738 . V_79 ) ;
if ( ! V_101 ) {
V_189 . V_737 = 1 ;
V_101 = F_97 (
& V_683 . V_79 ) ;
}
if ( V_101 ) {
F_8 ( L_453 ) ;
F_408 () ;
return V_101 ;
}
V_189 . V_736 = 1 ;
V_156 = F_420 ( V_746 , - 1 ,
NULL , 0 ) ;
if ( F_148 ( V_156 ) ) {
V_101 = F_307 ( V_156 ) ;
V_156 = NULL ;
F_8 ( L_454 ) ;
F_408 () ;
return V_101 ;
}
V_516 = F_420 (
V_747 ,
- 1 , NULL , 0 ) ;
if ( F_148 ( V_516 ) ) {
V_101 = F_307 ( V_516 ) ;
V_516 = NULL ;
F_8 ( L_455 ) ;
F_408 () ;
return V_101 ;
}
V_101 = F_261 ( & V_516 -> V_157 ,
& V_735 ) ;
if ( V_101 ) {
F_8 ( L_456 ) ;
F_408 () ;
return V_101 ;
}
V_189 . V_734 = 1 ;
V_733 = F_421 ( & V_516 -> V_157 ) ;
if ( F_148 ( V_733 ) ) {
V_101 = F_307 ( V_733 ) ;
V_733 = NULL ;
F_8 ( L_457 ) ;
F_408 () ;
return V_101 ;
}
F_185 ( & V_209 ) ;
V_210 = F_422 () ;
if ( ! V_210 ) {
F_8 ( L_458 ) ;
F_408 () ;
return - V_82 ;
} else {
V_210 -> V_51 = L_459 ;
V_210 -> V_748 = V_746 L_460 ;
V_210 -> V_146 . V_749 = V_750 ;
V_210 -> V_146 . V_6 = V_7 . V_6 ;
V_210 -> V_146 . V_751 = V_752 ;
V_210 -> V_146 . V_753 = V_754 ;
V_210 -> V_157 . V_52 = & V_156 -> V_157 ;
}
F_304 () ;
for ( V_42 = 0 ; V_42 < F_98 ( V_729 ) ; V_42 ++ ) {
V_101 = F_392 ( & V_729 [ V_42 ] ) ;
if ( V_101 >= 0 && * V_729 [ V_42 ] . V_730 )
V_101 = V_729 [ V_42 ] . V_63 -> V_102 ( V_729 [ V_42 ] . V_730 ) ;
if ( V_101 < 0 ) {
F_408 () ;
return V_101 ;
}
}
V_66 = V_67 ;
V_101 = F_423 ( V_210 ) ;
if ( V_101 < 0 ) {
F_8 ( L_461 ) ;
F_408 () ;
return V_101 ;
} else {
V_189 . V_732 = 1 ;
}
return 0 ;
}
