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
int * V_17 , char * V_18 , char * V_19 , ... )
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
* V_17 = V_29 . integer . V_38 ;
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
return F_39 ( V_94 , F_37 , F_40 ( V_93 ) ) ;
}
static T_8 F_41 ( struct V_94 * V_94 ,
const char T_9 * V_95 ,
T_10 V_35 , T_11 * V_96 )
{
struct V_64 * V_65 = F_40 ( F_42 ( V_94 ) ) ;
char * V_97 ;
int V_98 ;
if ( ! V_65 || ! V_65 -> V_99 )
return - V_92 ;
if ( V_35 > V_100 - 2 )
return - V_92 ;
V_97 = F_43 ( V_35 + 2 , V_81 ) ;
if ( ! V_97 )
return - V_82 ;
if ( F_44 ( V_97 , V_95 , V_35 ) ) {
F_36 ( V_97 ) ;
return - V_101 ;
}
V_97 [ V_35 ] = 0 ;
strcat ( V_97 , L_26 ) ;
V_98 = V_65 -> V_99 ( V_97 ) ;
if ( V_98 == 0 )
V_98 = V_35 ;
F_36 ( V_97 ) ;
return V_98 ;
}
static char * F_45 ( char * * V_102 )
{
char * V_103 = * V_102 ;
char * V_104 ;
while ( ( V_104 = strchr ( V_103 , ',' ) ) && V_104 == V_103 )
V_103 = V_104 + 1 ;
if ( ! V_104 )
return NULL ;
* V_104 = 0 ;
* V_102 = V_104 + 1 ;
return V_103 ;
}
static int F_46 ( struct V_71 * V_105 )
{
struct V_64 * V_65 , * V_106 ;
F_47 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if ( V_65 -> V_107 )
( V_65 -> V_107 ) ( ) ;
}
return 0 ;
}
static int F_48 ( struct V_71 * V_105 )
{
struct V_64 * V_65 , * V_106 ;
F_47 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if ( V_65 -> V_108 )
( V_65 -> V_108 ) ( ) ;
}
return 0 ;
}
static void F_49 ( struct V_109 * V_110 )
{
struct V_64 * V_65 , * V_106 ;
F_47 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if ( V_65 -> V_111 )
( V_65 -> V_111 ) ( ) ;
}
}
static struct V_112 * F_50 ( unsigned int V_113 ,
const char * V_51 )
{
struct V_114 * V_115 ;
if ( V_113 == 0 )
return NULL ;
V_115 = F_34 ( sizeof( struct V_114 ) +
V_113 * sizeof( struct V_116 * ) ,
V_81 ) ;
if ( ! V_115 )
return NULL ;
V_115 -> V_117 . V_113 = V_113 ;
V_115 -> V_117 . V_118 . V_119 = & V_115 -> V_120 ;
V_115 -> V_117 . V_118 . V_51 = V_51 ;
return & V_115 -> V_117 ;
}
static int F_51 ( struct V_112 * V_117 , struct V_116 * V_121 )
{
if ( ! V_117 || ! V_121 )
return - V_92 ;
if ( V_117 -> V_122 >= V_117 -> V_113 )
return - V_82 ;
V_117 -> V_118 . V_119 [ V_117 -> V_122 ] = V_121 ;
V_117 -> V_122 ++ ;
return 0 ;
}
static int F_52 ( struct V_112 * V_117 ,
struct V_116 * * V_121 ,
unsigned int V_35 )
{
int V_42 , V_17 ;
for ( V_42 = 0 ; V_42 < V_35 ; V_42 ++ ) {
V_17 = F_51 ( V_117 , V_121 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static void F_53 ( struct V_112 * V_117 , struct V_123 * V_124 )
{
F_54 ( V_124 , & V_117 -> V_118 ) ;
F_55 ( V_117 ) ;
}
static int F_56 ( const char * V_125 ,
unsigned long V_126 , unsigned long * V_38 )
{
char * V_127 ;
* V_38 = F_57 ( F_58 ( V_125 ) , & V_127 , 0 ) ;
V_127 = F_58 ( V_127 ) ;
if ( * V_127 || * V_38 > V_126 )
return - V_92 ;
return 0 ;
}
static void F_59 ( void )
{
if ( F_7 ( V_128 , NULL , L_27 , L_28 , 0 ) )
F_31 ( L_29 ) ;
}
static void F_60 ( const char * const V_2 ,
const char * const V_129 )
{
F_2 ( L_30 ) ;
F_61 ( L_31
L_32 ,
V_2 , V_129 ) ;
}
static int F_62 ( const struct V_130 * V_131 )
{
int V_30 ;
if ( ! V_131 )
return - V_72 ;
V_30 = ( V_131 -> V_85 -> V_132 ) ( ) ;
if ( V_30 < 0 )
return V_30 ;
F_63 ( V_131 -> V_133 ,
( V_30 == V_134 ) ) ;
return V_30 ;
}
static void F_64 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_135 ; V_42 ++ )
F_62 ( V_136 [ V_42 ] ) ;
}
static void F_65 ( bool V_137 )
{
unsigned int V_42 ;
struct V_130 * V_131 ;
for ( V_42 = 0 ; V_42 < V_135 ; V_42 ++ ) {
V_131 = V_136 [ V_42 ] ;
if ( V_131 ) {
if ( F_66 ( V_131 -> V_133 ,
V_137 ) ) {
}
}
}
}
static bool F_67 ( void )
{
int V_17 = F_68 () ;
int V_138 ;
if ( V_17 < 0 )
return false ;
V_138 = ( V_17 == V_134 ) ;
F_65 ( V_138 ) ;
return V_138 ;
}
static int F_69 ( void * V_63 , bool V_137 )
{
struct V_130 * V_131 = V_63 ;
int V_17 ;
F_20 ( V_139 ,
L_33 ,
V_137 ? L_34 : L_35 ) ;
V_17 = ( V_131 -> V_85 -> V_140 ) ( V_137 ?
V_134 : V_141 ) ;
F_62 ( V_131 ) ;
return ( V_17 < 0 ) ? V_17 : 0 ;
}
static int T_1 F_70 ( const enum V_142 V_143 ,
const struct V_144 * V_145 ,
const enum V_146 V_147 ,
const char * V_51 ,
const bool V_148 )
{
struct V_130 * V_149 ;
int V_17 ;
bool V_150 = false ;
bool V_151 ;
int V_152 ;
F_23 ( V_143 >= V_135 || V_136 [ V_143 ] ) ;
V_149 = F_34 ( sizeof( struct V_130 ) , V_81 ) ;
if ( V_149 )
V_149 -> V_133 = F_71 ( V_51 ,
& V_153 -> V_105 ,
V_147 ,
& V_154 ,
V_149 ) ;
if ( ! V_149 || ! V_149 -> V_133 ) {
F_8 ( L_36 ) ;
F_36 ( V_149 ) ;
return - V_82 ;
}
V_149 -> V_143 = V_143 ;
V_149 -> V_85 = V_145 ;
V_152 = ( V_145 -> V_132 ) ( ) ;
if ( V_152 < 0 ) {
F_8 ( L_37 ,
V_51 , V_152 ) ;
} else {
V_150 = ( V_152 == V_134 ) ;
if ( V_148 ) {
F_72 ( V_149 -> V_133 , V_150 ) ;
}
}
V_151 = F_67 () ;
F_66 ( V_149 -> V_133 , V_151 ) ;
V_17 = F_73 ( V_149 -> V_133 ) ;
if ( V_17 < 0 ) {
F_8 ( L_38 , V_51 , V_17 ) ;
F_74 ( V_149 -> V_133 ) ;
F_36 ( V_149 ) ;
return V_17 ;
}
V_136 [ V_143 ] = V_149 ;
F_75 ( L_39 ,
V_51 , ( V_150 || V_151 ) ? L_1 : L_40 ) ;
return 0 ;
}
static void F_76 ( const enum V_142 V_143 )
{
struct V_130 * V_131 ;
F_23 ( V_143 >= V_135 ) ;
V_131 = V_136 [ V_143 ] ;
if ( V_131 ) {
F_77 ( V_131 -> V_133 ) ;
F_74 ( V_131 -> V_133 ) ;
V_136 [ V_143 ] = NULL ;
F_36 ( V_131 ) ;
}
}
static void F_78 ( const char * const V_2 )
{
F_60 ( V_2 ,
L_41 ) ;
}
static T_8 F_79 ( const enum V_142 V_143 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_30 ;
F_78 ( V_121 -> V_121 . V_51 ) ;
if ( F_67 () ) {
V_30 = V_134 ;
} else {
V_30 = F_62 ( V_136 [ V_143 ] ) ;
if ( V_30 < 0 )
return V_30 ;
}
return snprintf ( V_125 , V_100 , L_42 ,
( V_30 == V_141 ) ? 1 : 0 ) ;
}
static T_8 F_80 ( const enum V_142 V_143 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
int V_17 ;
F_78 ( V_121 -> V_121 . V_51 ) ;
if ( F_56 ( V_125 , 1 , & V_156 ) )
return - V_92 ;
F_81 ( V_121 -> V_121 . V_51 , L_43 , V_156 ) ;
if ( F_67 () && ! ! V_156 )
return - V_157 ;
V_17 = V_136 [ V_143 ] -> V_85 -> V_140 ( ( ! ! V_156 ) ?
V_141 : V_134 ) ;
F_62 ( V_136 [ V_143 ] ) ;
return ( V_17 < 0 ) ? V_17 : V_35 ;
}
static int F_82 ( const enum V_142 V_143 , struct V_88 * V_89 )
{
if ( V_143 >= V_135 )
F_83 ( V_89 , L_44 ) ;
else {
int V_30 ;
if ( F_67 () ) {
V_30 = V_134 ;
} else {
V_30 = F_62 (
V_136 [ V_143 ] ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_83 ( V_89 , L_45 ,
( V_30 == V_141 ) ?
L_46 : L_47 ) ;
F_83 ( V_89 , L_48 ) ;
}
return 0 ;
}
static int F_84 ( const enum V_142 V_143 , char * V_125 )
{
char * V_158 ;
int V_30 = - 1 ;
int V_17 = 0 ;
if ( V_143 >= V_135 )
return - V_72 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( F_85 ( V_158 , L_49 ) == 0 )
V_30 = V_141 ;
else if ( F_85 ( V_158 , L_50 ) == 0 )
V_30 = V_134 ;
else
return - V_92 ;
}
if ( V_30 != - 1 ) {
F_81 ( L_51 , L_52 ,
( V_30 == V_141 ) ?
L_49 : L_50 ,
V_159 [ V_143 ] ) ;
V_17 = ( V_136 [ V_143 ] -> V_85 -> V_140 ) ( V_30 ) ;
F_62 ( V_136 [ V_143 ] ) ;
}
return V_17 ;
}
static T_8 F_86 (
struct V_160 * V_161 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_53 , V_162 ) ;
}
static T_8 F_87 ( struct V_160 * V_161 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_54 , V_163 ) ;
}
static T_8 F_88 ( struct V_160 * V_161 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
if ( F_56 ( V_125 , 0xffff , & V_156 ) )
return - V_92 ;
V_163 = V_156 ;
return V_35 ;
}
static T_8 F_89 ( struct V_160 * V_161 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_55 ,
V_164 , V_165 ) ;
}
static T_8 F_90 ( struct V_160 * V_161 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_42 , ! ! V_166 ) ;
}
static T_8 F_91 ( struct V_160 * V_161 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
if ( F_56 ( V_125 , 1 , & V_156 ) )
return - V_92 ;
if ( V_166 != ! ! V_156 ) {
V_166 = ! ! V_156 ;
F_65 ( ! V_156 ) ;
}
return V_35 ;
}
static T_8 F_92 (
struct V_160 * V_161 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_42 , ! ! V_167 ) ;
}
static T_8 F_93 (
struct V_160 * V_161 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
if ( F_56 ( V_125 , 1 , & V_156 ) )
return - V_92 ;
V_167 = ! ! V_156 ;
return V_35 ;
}
static T_8 F_94 (
struct V_160 * V_161 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_42 , ! ! V_168 ) ;
}
static T_8 F_95 (
struct V_160 * V_161 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
if ( F_56 ( V_125 , 1 , & V_156 ) )
return - V_92 ;
V_168 = ! ! V_156 ;
return V_35 ;
}
static T_8 F_96 (
struct V_160 * V_161 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_42 , ! ! V_169 ) ;
}
static T_8 F_97 (
struct V_160 * V_161 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
if ( F_56 ( V_125 , 1 , & V_156 ) )
return - V_92 ;
V_169 = ! ! V_156 ;
return V_35 ;
}
static int T_1 F_98 ( struct V_160 * V_161 )
{
int V_42 , V_17 ;
V_42 = 0 ;
V_17 = 0 ;
while ( ! V_17 && V_42 < F_99 ( V_170 ) ) {
V_17 = F_100 ( V_161 , V_170 [ V_42 ] ) ;
V_42 ++ ;
}
#ifdef F_101
if ( ! V_17 && V_171 )
V_17 = F_100 ( V_161 , & V_172 ) ;
if ( ! V_17 && V_173 )
V_17 = F_100 ( V_161 , & V_174 ) ;
if ( ! V_17 && V_175 )
V_17 = F_100 ( V_161 , & V_176 ) ;
if ( ! V_17 && V_177 )
V_17 = F_100 ( V_161 , & V_178 ) ;
#endif
return V_17 ;
}
static void F_102 ( struct V_160 * V_161 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_99 ( V_170 ) ; V_42 ++ )
F_103 ( V_161 , V_170 [ V_42 ] ) ;
#ifdef F_104
F_103 ( V_161 , & V_172 ) ;
F_103 ( V_161 , & V_174 ) ;
F_103 ( V_161 , & V_176 ) ;
F_103 ( V_161 , & V_178 ) ;
#endif
}
static void T_1 F_105 ( void )
{
unsigned long V_179 ;
T_12 V_180 , V_181 ;
V_179 = F_4 ( V_182 ,
F_99 ( V_182 ) ) ;
if ( ! V_179 )
return;
V_181 = V_179 & 0xffffU ;
V_180 = ( V_179 >> 16 ) & 0xffffU ;
if ( ( V_181 > V_7 . V_183 ) ||
( V_180 > V_7 . V_184 &&
V_180 != V_8 ) ) {
F_61 ( L_56 ) ;
F_61 ( L_57
L_58 ) ;
}
}
static bool T_1 F_106 ( void )
{
return F_4 ( V_182 ,
F_99 ( V_182 ) ) != 0 ;
}
static int F_107 ( struct V_88 * V_89 )
{
F_83 ( V_89 , L_59 , V_164 ) ;
F_83 ( V_89 , L_60 , V_165 ) ;
return 0 ;
}
static int F_68 ( void )
{
int V_30 ;
if ( ! V_185 . V_186 )
return - V_72 ;
#ifdef F_101
if ( V_171 )
return ( V_166 ) ?
V_141 : V_134 ;
#endif
if ( ! F_7 ( V_128 , & V_30 , L_61 , L_62 ) )
return - V_50 ;
return ( V_30 ) ? V_141 : V_134 ;
}
static int F_108 ( int * V_30 )
{
int V_117 ;
if ( ! F_7 ( V_128 , & V_117 , L_63 , L_62 ) )
return - V_50 ;
* V_30 = ( ( V_117 & V_187 ) != 0 ) ;
return 0 ;
}
static int F_109 ( void )
{
if ( V_185 . V_188 ) {
T_7 V_89 = 0 ;
if ( ! F_7 ( V_128 , & V_89 , L_64 , L_62 ) )
return - V_50 ;
V_189 = V_89 ;
} else {
V_189 = V_190 ;
}
V_191 &= ( V_189 | V_192 ) ;
return 0 ;
}
void static F_110 ( void )
{
const T_7 V_193 = V_194 &
~ ( V_189 | V_192 ) &
( V_190 | V_195 ) ;
if ( V_193 )
F_31 ( L_65 , V_193 ) ;
}
static int F_111 ( T_7 V_196 )
{
int V_42 ;
int V_70 = 0 ;
const T_7 V_197 = V_196 & ~ V_192 ;
if ( V_185 . V_188 ) {
for ( V_42 = 0 ; V_42 < 32 ; V_42 ++ ) {
if ( ! F_7 ( V_128 ,
NULL , L_66 , L_8 , V_42 + 1 ,
! ! ( V_196 & ( 1 << V_42 ) ) ) ) {
V_70 = - V_50 ;
break;
}
}
}
if ( ! F_109 () && ! V_70 && ( V_197 & ~ V_189 ) ) {
F_31 ( L_67
L_68 ,
V_197 , V_189 ) ;
}
if ( V_66 != V_198 )
F_110 () ;
return V_70 ;
}
static int F_112 ( const T_7 V_196 )
{
int V_70 ;
if ( ! V_199 . V_200 &&
( V_196 == 0xffff || V_196 == 0xffffff ||
V_196 == 0xffffffff ) ) {
V_199 . V_200 = 1 ;
F_31 ( L_69
L_70 , V_196 ) ;
F_31 ( L_71
L_72
L_73 ) ;
}
V_70 = F_111 ( ( V_196 | V_194 ) & ~ V_192 ) ;
V_191 = V_196 & ( V_189 | V_192 ) ;
return V_70 ;
}
static int F_113 ( const T_7 V_196 )
{
int V_70 ;
if ( ! V_185 . V_201 ) {
V_194 = V_196 ;
return 0 ;
}
F_114 ( & V_202 ) ;
T_13
V_194 = V_196 ;
#ifdef F_115
V_192 |= ( V_196 & ~ V_190 ) ;
#endif
T_14
V_70 = F_111 ( ( V_189 | V_194 ) &
~ V_192 ) ;
F_116 ( true ) ;
F_117 ( & V_202 ) ;
return V_70 ;
}
static int F_118 ( int * V_30 )
{
if ( ! F_7 ( V_128 , V_30 , L_74 , L_62 ) )
return - V_50 ;
return 0 ;
}
static int F_119 ( bool V_203 )
{
if ( ! F_7 ( V_128 , NULL , L_75 , L_9 , V_203 ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static void F_120 ( void )
{
int V_204 ;
if ( V_185 . V_205 &&
! F_108 ( & V_204 ) ) {
F_114 ( & V_206 ) ;
F_121 ( V_207 ,
V_208 , ! ! V_204 ) ;
F_122 ( V_207 ) ;
F_117 ( & V_206 ) ;
}
}
static void F_123 ( const unsigned int V_209 )
{
const unsigned int V_210 = V_211 [ V_209 ] ;
if ( V_210 != V_212 ) {
F_114 ( & V_206 ) ;
F_124 ( V_207 , V_213 , V_214 , V_209 ) ;
F_125 ( V_207 , V_210 , 1 ) ;
F_122 ( V_207 ) ;
F_124 ( V_207 , V_213 , V_214 , V_209 ) ;
F_125 ( V_207 , V_210 , 0 ) ;
F_122 ( V_207 ) ;
F_117 ( & V_206 ) ;
}
}
static void F_126 ( const unsigned int V_209 )
{
F_127 ( V_209 ) ;
if ( V_191 & ( 1 << V_209 ) )
F_123 ( V_209 ) ;
}
static void F_128 ( unsigned int V_209 )
{
F_126 ( V_209 ) ;
if ( V_215 < 2 ) {
F_129 ( V_216 . V_71 ,
0x80 , V_217 + V_209 ) ;
}
}
static void F_130 ( struct V_218 * V_219 , const T_7 V_89 )
{
T_6 V_220 ;
if ( V_89 & V_221 ) {
V_220 = F_131 ( V_222 ) ;
V_219 -> V_223 = ! ! ( V_220 & V_224 ) ;
V_219 -> V_225 = ! ! ( V_220 & V_226 ) ;
V_219 -> V_227 = ! ! ( V_220 & V_228 ) ;
V_219 -> V_229 = ! ! ( V_220 & V_230 ) ;
}
if ( V_89 & V_231 ) {
V_220 = F_131 ( V_232 ) ;
V_219 -> V_233 = ! ! ( V_220 & V_234 ) ;
}
if ( V_89 & V_235 ) {
V_220 = F_131 ( V_236 ) ;
V_219 -> V_237 =
! ! ( V_220 & V_238 ) ;
}
if ( V_89 & V_239 ) {
V_220 = F_131 ( V_240 ) ;
V_219 -> V_241 = ( V_220 & V_242 )
>> V_243 ;
V_219 -> V_244 =
! ! ( V_220 & V_245 ) ;
}
if ( V_89 & V_246 ) {
V_220 = F_131 ( V_247 ) ;
V_219 -> V_248 = ( V_220 & V_249 )
>> V_250 ;
V_219 -> V_251 = ! ! ( V_220 & V_252 ) ;
V_219 -> V_253 = ! ! ( V_220 & V_254 ) ;
}
}
void F_132 ( const unsigned int V_255 ,
const unsigned int V_256 )
{
unsigned int V_42 = V_255 ;
while ( V_42 > V_256 ) {
F_133 ( V_257 ) ;
V_42 -- ;
}
while ( V_42 < V_256 ) {
F_133 ( V_258 ) ;
V_42 ++ ;
}
}
void F_134 ( const unsigned int V_259 ,
const unsigned int V_260 )
{
unsigned int V_42 = V_259 ;
while ( V_42 > V_260 ) {
F_133 ( V_261 ) ;
V_42 -- ;
}
while ( V_42 < V_260 ) {
F_133 ( V_262 ) ;
V_42 ++ ;
}
}
static int F_135 ( void * V_63 )
{
struct V_218 V_117 [ 2 ] ;
T_7 V_263 , V_264 ;
unsigned int V_265 , V_266 ;
unsigned long V_156 ;
unsigned int V_267 ;
unsigned int V_268 ;
bool V_269 ;
if ( V_66 == V_198 )
goto exit;
F_136 () ;
V_266 = 0 ;
V_265 = 1 ;
V_156 = 0 ;
F_114 ( & V_270 ) ;
V_267 = V_271 ;
V_263 = V_192 ;
V_264 = V_192 &
( V_194 | V_191 ) ;
V_268 = V_272 ;
F_117 ( & V_270 ) ;
F_130 ( & V_117 [ V_266 ] , V_263 ) ;
while ( ! F_137 () ) {
if ( V_156 == 0 ) {
if ( F_138 ( V_268 ) )
V_156 = 1000 / V_268 ;
else
V_156 = 100 ;
}
V_156 = F_139 ( V_156 ) ;
if ( F_140 ( F_141 ( & V_269 ) ) )
break;
if ( V_156 > 0 && ! V_269 )
continue;
F_114 ( & V_270 ) ;
if ( V_269 || V_271 != V_267 ) {
V_265 = V_266 ;
V_156 = 0 ;
V_267 = V_271 ;
}
V_263 = V_192 ;
V_264 = V_192 &
( V_194 | V_191 ) ;
V_268 = V_272 ;
F_117 ( & V_270 ) ;
if ( F_138 ( V_263 ) ) {
F_130 ( & V_117 [ V_265 ] , V_263 ) ;
if ( F_138 ( V_265 != V_266 ) ) {
F_142 ( & V_117 [ V_266 ] , & V_117 [ V_265 ] ,
V_264 ) ;
}
}
V_266 = V_265 ;
V_265 ^= 1 ;
}
exit:
return 0 ;
}
static void F_143 ( void )
{
if ( V_273 ) {
F_144 ( V_273 ) ;
V_273 = NULL ;
}
}
static void F_116 ( const bool V_274 )
{
const T_7 V_275 = V_194 & V_192 ;
const T_7 V_276 = V_191 & V_192 ;
if ( V_272 > 0 &&
( V_275 ||
( V_276 && V_207 -> V_277 > 0 ) ) ) {
if ( ! V_273 ) {
V_273 = F_145 ( F_135 ,
NULL , V_278 ) ;
if ( F_146 ( V_273 ) ) {
V_273 = NULL ;
F_8 ( L_76
L_77 ) ;
}
}
} else {
F_143 () ;
if ( V_274 && ( V_275 || V_276 ) &&
V_272 == 0 ) {
F_31 ( L_78
L_79
L_80 ,
V_276 , V_275 ) ;
}
}
}
static void F_147 ( const bool V_274 )
{
F_114 ( & V_202 ) ;
F_116 ( V_274 ) ;
F_117 ( & V_202 ) ;
}
static void F_148 ( unsigned int V_279 )
{
if ( ! V_279 )
F_143 () ;
V_272 = V_279 ;
}
static void F_116 ( const bool V_280 )
{
}
static void F_147 ( const bool V_280 )
{
}
static int F_149 ( struct V_281 * V_105 )
{
switch ( V_66 ) {
case V_282 :
case V_67 :
F_147 ( false ) ;
return 0 ;
case V_198 :
return - V_283 ;
}
F_150 () ;
return - V_283 ;
}
static void F_151 ( struct V_281 * V_105 )
{
if ( V_66 != V_198 &&
! ( V_192 & V_194 ) )
F_147 ( false ) ;
}
static T_8 F_152 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 , V_30 ;
F_60 ( L_81 ,
L_82 ) ;
V_17 = F_118 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
return snprintf ( V_125 , V_100 , L_42 , V_30 ) ;
}
static T_8 F_153 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
F_60 ( L_81 ,
L_83 ) ;
if ( F_56 ( V_125 , 1 , & V_156 ) )
return - V_92 ;
if ( V_156 == 0 )
return - V_157 ;
return V_35 ;
}
static T_8 F_154 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_53 , V_191 ) ;
}
static T_8 F_155 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
int V_17 ;
if ( F_56 ( V_125 , 0xffffffffUL , & V_156 ) )
return - V_92 ;
if ( F_156 ( & V_202 ) )
return - V_284 ;
V_17 = F_112 ( V_156 ) ;
#ifdef F_115
F_116 ( true ) ;
#endif
F_117 ( & V_202 ) ;
F_81 ( L_84 , L_85 , V_156 ) ;
return ( V_17 ) ? V_17 : V_35 ;
}
static T_8 F_157 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return sprintf ( V_125 , L_86 ) ;
}
static T_8 F_158 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
F_60 ( L_87 ,
L_88 ) ;
return snprintf ( V_125 , V_100 , L_53 , V_285 ) ;
}
static T_8 F_159 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_53 ,
V_190 | V_192 ) ;
}
static T_8 F_160 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_53 ,
( V_190 | V_192 )
& ~ V_286 ) ;
}
static T_8 F_161 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_53 , V_192 ) ;
}
static T_8 F_162 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
T_7 V_287 ;
int V_70 ;
if ( F_56 ( V_125 , 0xffffffffUL , & V_156 ) ||
( ( V_156 & ~ V_195 ) != 0 ) )
return - V_92 ;
if ( F_156 ( & V_202 ) )
return - V_284 ;
T_13
V_192 = V_156 ;
T_14
V_70 = F_111 ( ( V_191 | V_194 ) &
~ V_192 ) ;
F_116 ( true ) ;
V_287 = V_194 & ~ ( V_189 & V_190 )
& ~ V_192 & V_195 ;
F_117 ( & V_202 ) ;
if ( V_70 < 0 )
F_8 ( L_89
L_90 ) ;
if ( V_287 )
F_31 ( L_89
L_91 ,
V_287 ) ;
F_81 ( L_92 , L_85 , V_156 ) ;
return ( V_70 < 0 ) ? V_70 : V_35 ;
}
static T_8 F_163 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_42 , V_272 ) ;
}
static T_8 F_164 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
if ( F_56 ( V_125 , 25 , & V_156 ) )
return - V_92 ;
if ( F_156 ( & V_202 ) )
return - V_284 ;
F_148 ( V_156 ) ;
F_116 ( true ) ;
F_117 ( & V_202 ) ;
F_81 ( L_93 , L_94 , V_156 ) ;
return V_35 ;
}
static T_8 F_165 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 ;
V_17 = F_68 () ;
if ( V_17 < 0 )
return V_17 ;
F_65 ( ( V_17 == V_134 ) ) ;
return snprintf ( V_125 , V_100 , L_42 ,
( V_17 == V_134 ) ? 0 : 1 ) ;
}
static void F_166 ( void )
{
if ( V_185 . V_186 )
F_167 ( & V_153 -> V_105 . V_124 , NULL ,
L_95 ) ;
}
static T_8 F_168 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 , V_117 ;
V_17 = F_108 ( & V_117 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_125 , V_100 , L_42 , ! ! V_117 ) ;
}
static void F_169 ( void )
{
if ( V_185 . V_205 )
F_167 ( & V_153 -> V_105 . V_124 , NULL ,
L_96 ) ;
}
static T_8 F_170 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_42 ,
( V_215 != 0 ) ? V_215 : 1 ) ;
}
static T_8 F_171 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_42 , V_288 ) ;
}
static void F_172 ( void )
{
F_167 ( & V_153 -> V_105 . V_124 , NULL ,
L_97 ) ;
}
static T_8 F_173 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_42 , V_289 ) ;
}
static void F_174 ( void )
{
F_167 ( & V_153 -> V_105 . V_124 , NULL ,
L_98 ) ;
}
static void F_175 ( void )
{
int V_290 ;
V_290 = F_68 () ;
if ( V_290 == V_134 )
F_65 ( true ) ;
F_64 () ;
if ( V_290 == V_141 )
F_65 ( false ) ;
if ( ! ( V_290 < 0 ) ) {
F_114 ( & V_206 ) ;
F_121 ( V_207 ,
V_291 , ( V_290 > 0 ) ) ;
F_122 ( V_207 ) ;
F_117 ( & V_206 ) ;
}
F_166 () ;
}
static void F_176 ( void )
{
#ifdef F_115
F_114 ( & V_202 ) ;
F_143 () ;
F_117 ( & V_202 ) ;
#endif
if ( V_292 )
F_53 ( V_292 , & V_153 -> V_105 . V_124 ) ;
F_20 ( V_293 | V_294 ,
L_99 ) ;
if ( ( ( V_185 . V_188 &&
F_111 ( V_285 ) ) |
F_119 ( false ) ) != 0 )
F_8 ( L_100
L_101 ) ;
}
static void T_1 F_177 ( const unsigned int V_209 )
{
if ( V_211 [ V_209 ] != V_212 ) {
F_178 ( V_211 [ V_209 ] ,
V_207 -> V_295 ) ;
V_211 [ V_209 ] = V_212 ;
}
}
static int T_1 F_179 ( struct V_296 * V_297 )
{
enum T_15 {
V_298 = 0 ,
V_299 ,
};
static const T_16 V_300 [] V_301 = {
[ V_298 ] = {
V_302 , V_303 , V_304 , V_305 ,
V_306 , V_307 , V_308 , V_309 ,
V_310 , V_311 , V_312 , V_313 ,
V_314 ,
V_314 ,
V_314 ,
V_212 ,
V_212 ,
V_212 ,
V_314 ,
V_315 ,
V_212 ,
V_212 ,
V_212 ,
V_316 ,
V_314 , V_314 , V_314 , V_314 ,
V_314 , V_314 , V_314 , V_314 ,
} ,
[ V_299 ] = {
V_302 , V_304 , V_303 , V_305 ,
V_306 , V_317 , V_308 , V_309 ,
V_310 , V_311 , V_312 , V_313 ,
V_314 ,
V_314 ,
V_314 ,
V_318 ,
V_319 ,
V_212 ,
V_314 ,
V_315 ,
V_212 ,
V_212 ,
V_212 ,
V_316 ,
V_314 , V_314 ,
V_320 ,
V_314 , V_314 , V_314 , V_314 ,
V_314 ,
} ,
} ;
static const struct V_3 V_321 [] V_301 = {
{
. V_6 = V_15 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_298 ,
} ,
{
. V_6 = V_14 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_299 ,
} ,
} ;
#define F_180 sizeof(tpacpi_keymap_t)
#define F_181 sizeof(tpacpi_keymap_entry_t)
int V_17 , V_42 ;
int V_30 ;
int V_322 ;
bool V_323 = false ;
bool V_324 = false ;
unsigned long V_13 ;
unsigned long V_325 ;
F_17 ( V_55 | V_294 ,
L_102 ) ;
F_23 ( ! V_207 ) ;
F_23 ( V_207 -> V_326 != NULL ||
V_207 -> V_327 != NULL ) ;
F_182 ( V_328 ) ;
F_183 ( & V_202 ) ;
#ifdef F_115
F_183 ( & V_270 ) ;
#endif
V_185 . V_201 = V_128 != NULL ;
F_17 ( V_55 | V_294 ,
L_103 ,
F_1 ( V_185 . V_201 ) ) ;
if ( ! V_185 . V_201 )
return 1 ;
V_13 = F_4 ( V_329 ,
F_99 ( V_329 ) ) ;
F_59 () ;
V_292 = F_50 (
F_99 ( V_330 ) + 2 ,
NULL ) ;
if ( ! V_292 )
return - V_82 ;
V_17 = F_52 ( V_292 ,
V_330 ,
F_99 ( V_330 ) ) ;
if ( V_17 )
goto V_331;
if ( F_7 ( V_128 , & V_322 , L_104 , L_105 ) ) {
if ( ( V_322 >> 8 ) != 1 ) {
F_8 ( L_106 ,
V_322 ) ;
F_8 ( L_107 , V_332 ) ;
} else {
F_17 ( V_55 | V_294 ,
L_108 ,
V_322 ) ;
if ( ! F_7 ( V_128 , & V_190 ,
L_109 , L_105 ) ) {
F_8 ( L_110
L_107 ,
V_332 ) ;
V_190 = 0x080cU ;
} else {
V_185 . V_188 = 1 ;
}
}
}
F_17 ( V_55 | V_294 ,
L_111 ,
F_1 ( V_185 . V_188 ) ) ;
if ( ! V_185 . V_188 && ! V_190 &&
( V_13 & V_333 ) )
V_190 = 0x080cU ;
if ( V_185 . V_188 ) {
V_17 = F_109 () ;
if ( V_17 )
goto V_331;
V_285 = V_189 ;
} else {
V_285 = V_190 ;
V_189 = V_190 ;
}
#ifdef F_101
if ( V_171 ) {
V_185 . V_186 = 1 ;
V_323 = ! ! V_166 ;
F_75 ( L_112 ) ;
} else
#endif
if ( F_7 ( V_128 , & V_30 , L_61 , L_105 ) ) {
V_185 . V_186 = 1 ;
V_323 = ! ! V_30 ;
F_75 ( L_113 ,
F_184 ( V_30 , 0 ) ) ;
}
if ( V_185 . V_186 )
V_17 = F_51 ( V_292 ,
& V_334 . V_121 ) ;
if ( ! V_17 && F_7 ( V_128 , & V_30 , L_63 , L_105 ) ) {
V_185 . V_205 = 1 ;
V_324 = ! ! ( V_30 & V_187 ) ;
F_75 ( L_114
L_115 ,
( V_324 ) ? L_116 : L_117 ) ;
V_17 = F_51 ( V_292 ,
& V_335 . V_121 ) ;
}
if ( ! V_17 )
V_17 = F_185 (
V_292 ,
& V_153 -> V_105 . V_124 ) ;
if ( V_17 )
goto V_331;
V_211 = F_43 ( F_180 ,
V_81 ) ;
if ( ! V_211 ) {
F_8 ( L_118 ) ;
V_17 = - V_82 ;
goto V_331;
}
V_325 = F_4 ( V_321 ,
F_99 ( V_321 ) ) ;
F_23 ( V_325 >= F_99 ( V_300 ) ) ;
F_20 ( V_55 | V_294 ,
L_119 , V_325 ) ;
memcpy ( V_211 , & V_300 [ V_325 ] ,
F_180 ) ;
F_186 ( V_207 , V_213 , V_214 ) ;
V_207 -> V_336 = F_181 ;
V_207 -> V_337 = V_338 ;
V_207 -> V_210 = V_211 ;
for ( V_42 = 0 ; V_42 < V_338 ; V_42 ++ ) {
if ( V_211 [ V_42 ] != V_212 ) {
F_186 ( V_207 , V_339 ,
V_211 [ V_42 ] ) ;
} else {
if ( V_42 < sizeof( V_286 ) * 8 )
V_286 |= 1 << V_42 ;
}
}
if ( V_185 . V_186 ) {
F_186 ( V_207 , V_340 , V_291 ) ;
F_121 ( V_207 ,
V_291 , V_323 ) ;
}
if ( V_185 . V_205 ) {
F_186 ( V_207 , V_340 , V_208 ) ;
F_121 ( V_207 ,
V_208 , V_324 ) ;
}
if ( F_187 () ) {
F_75 ( L_120
L_121
L_122 ) ;
F_31 ( L_123
L_124 ) ;
V_286 |=
( 1 << V_262 )
| ( 1 << V_261 ) ;
F_177 ( V_262 ) ;
F_177 ( V_261 ) ;
}
#ifdef F_115
V_192 = V_341
& ~ V_190
& ~ V_286 ;
F_17 ( V_55 | V_294 ,
L_125 ,
V_192 , V_272 ) ;
#endif
F_20 ( V_55 | V_294 ,
L_126 ) ;
V_17 = F_119 ( true ) ;
if ( V_17 ) {
F_176 () ;
return V_17 ;
}
V_17 = F_111 ( ( ( V_190 & ~ V_286 )
| V_194 )
& ~ V_192 ) ;
if ( V_17 < 0 && V_17 != - V_49 ) {
F_176 () ;
return V_17 ;
}
V_191 = ( V_189 | V_192 )
& ~ V_286 ;
F_17 ( V_55 | V_294 ,
L_127 ,
V_191 , V_189 , V_192 ) ;
F_20 ( V_55 | V_294 ,
L_128 ,
( V_215 < 2 ) ?
L_46 : L_47 ) ;
V_207 -> V_326 = & F_149 ;
V_207 -> V_327 = & F_151 ;
F_147 ( true ) ;
return 0 ;
V_331:
F_53 ( V_292 , & V_153 -> V_105 . V_124 ) ;
V_292 = NULL ;
return ( V_17 < 0 ) ? V_17 : 1 ;
}
static bool F_188 ( const T_7 V_328 ,
bool * V_342 ,
bool * V_343 )
{
unsigned int V_209 = V_328 & 0xfff ;
* V_342 = true ;
* V_343 = false ;
if ( V_209 > 0 && V_209 <= V_338 ) {
V_209 -- ;
if ( ! ( V_192 & ( 1 << V_209 ) ) ) {
F_126 ( V_209 ) ;
* V_342 = false ;
} else {
* V_343 = true ;
}
return true ;
}
return false ;
}
static bool F_189 ( const T_7 V_328 ,
bool * V_342 ,
bool * V_343 )
{
* V_342 = true ;
* V_343 = false ;
switch ( V_328 ) {
case V_344 :
case V_345 :
V_288 = V_346 ;
* V_343 = true ;
break;
case V_347 :
case V_348 :
V_288 = V_349 ;
* V_343 = true ;
break;
case V_350 :
case V_351 :
F_190 ( L_129 ) ;
break;
default:
return false ;
}
if ( V_288 != V_352 ) {
F_75 ( L_130 ) ;
F_172 () ;
}
return true ;
}
static bool F_191 ( const T_7 V_328 ,
bool * V_342 ,
bool * V_343 )
{
* V_342 = true ;
* V_343 = false ;
switch ( V_328 ) {
case V_353 :
V_289 = 1 ;
F_75 ( L_131 ) ;
F_174 () ;
return true ;
case V_354 :
F_75 ( L_132 ) ;
return true ;
case V_355 :
F_75 ( L_133 ) ;
return true ;
default:
return false ;
}
}
static bool F_192 ( const T_7 V_328 ,
bool * V_342 ,
bool * V_343 )
{
* V_342 = true ;
* V_343 = false ;
switch ( V_328 ) {
case V_356 :
case V_357 :
return true ;
case V_358 :
case V_359 :
F_120 () ;
F_169 () ;
* V_342 = false ;
return true ;
case V_360 :
case V_361 :
case V_362 :
* V_343 = true ;
return true ;
default:
return false ;
}
}
static bool F_193 ( const T_7 V_328 ,
bool * V_342 ,
bool * V_343 )
{
bool V_363 = true ;
* V_342 = true ;
* V_343 = false ;
switch ( V_328 ) {
case V_364 :
F_75 ( L_134 ) ;
return true ;
case V_365 :
F_194 ( L_135 ) ;
break;
case V_366 :
F_190 ( L_136 ) ;
break;
case V_367 :
F_194 ( L_137
L_138 ) ;
break;
case V_368 :
F_190 ( L_139
L_140 ) ;
break;
case V_369 :
case V_370 :
case V_371 :
* V_342 = false ;
* V_343 = true ;
return true ;
default:
F_61 ( L_141 ) ;
V_363 = false ;
}
F_195 () ;
return V_363 ;
}
static void F_196 ( struct V_64 * V_65 , T_7 V_62 )
{
T_7 V_328 ;
bool V_342 ;
bool V_343 ;
bool V_372 ;
if ( V_62 != 0x80 ) {
F_8 ( L_142 , V_62 ) ;
F_197 (
V_65 -> V_68 -> V_71 -> V_373 . V_374 ,
F_198 ( & V_65 -> V_68 -> V_71 -> V_105 ) ,
V_62 , 0 ) ;
return;
}
while ( 1 ) {
if ( ! F_7 ( V_128 , & V_328 , L_143 , L_62 ) ) {
F_8 ( L_144 ) ;
return;
}
if ( V_328 == 0 ) {
return;
}
V_342 = true ;
V_343 = false ;
switch ( V_328 >> 12 ) {
case 1 :
V_372 = F_188 ( V_328 , & V_342 ,
& V_343 ) ;
break;
case 2 :
V_372 = F_189 ( V_328 , & V_342 ,
& V_343 ) ;
break;
case 3 :
switch ( V_328 ) {
case V_375 :
V_289 = 1 ;
F_75 ( L_145 ) ;
F_174 () ;
V_372 = true ;
break;
case V_376 :
V_372 = true ;
break;
default:
V_372 = false ;
}
break;
case 4 :
V_372 = F_191 ( V_328 , & V_342 ,
& V_343 ) ;
break;
case 5 :
V_372 = F_192 ( V_328 , & V_342 ,
& V_343 ) ;
break;
case 6 :
V_372 = F_193 ( V_328 , & V_342 ,
& V_343 ) ;
break;
case 7 :
if ( V_185 . V_186 &&
V_328 == V_377 ) {
F_175 () ;
V_342 = 0 ;
V_372 = true ;
break;
}
default:
V_372 = false ;
}
if ( ! V_372 ) {
F_31 ( L_146 , V_328 ) ;
F_31 ( L_147
L_148 , V_332 ) ;
}
if ( ! V_343 &&
( V_342 || V_215 < 2 ) ) {
F_129 ( V_65 -> V_68 -> V_71 ,
V_62 , V_328 ) ;
}
if ( ! V_343 && V_342 ) {
F_197 (
V_65 -> V_68 -> V_71 -> V_373 . V_374 ,
F_198 ( & V_65 -> V_68 -> V_71 -> V_105 ) ,
V_62 , V_328 ) ;
}
}
}
static void F_199 ( void )
{
V_288 = V_352 ;
V_289 = 0 ;
}
static void F_200 ( void )
{
F_59 () ;
if ( F_119 ( true ) < 0 ||
F_111 ( V_189 ) < 0 )
F_8 ( L_149
L_150 ) ;
F_175 () ;
F_169 () ;
F_172 () ;
F_174 () ;
F_147 ( false ) ;
}
static int F_201 ( struct V_88 * V_89 )
{
int V_17 , V_30 ;
if ( ! V_185 . V_201 ) {
F_83 ( V_89 , L_44 ) ;
return 0 ;
}
if ( F_156 ( & V_202 ) )
return - V_284 ;
V_17 = F_118 ( & V_30 ) ;
if ( ! V_17 )
V_17 = F_109 () ;
F_117 ( & V_202 ) ;
if ( V_17 )
return V_17 ;
F_83 ( V_89 , L_45 , F_184 ( V_30 , 0 ) ) ;
if ( V_190 ) {
F_83 ( V_89 , L_151 , V_191 ) ;
F_83 ( V_89 , L_152 ) ;
} else {
F_83 ( V_89 , L_153 ) ;
F_83 ( V_89 , L_154 ) ;
}
return 0 ;
}
static void F_202 ( bool V_203 )
{
F_2 ( L_155 ) ;
if ( ! F_203 ( ( V_66 == V_67 || ! V_203 ) ,
F_204 ( L_156
L_157
L_158 ) ) )
F_8 ( L_159
L_160
L_158 ) ;
}
static int F_205 ( char * V_125 )
{
int V_17 ;
T_7 V_196 ;
char * V_158 ;
if ( ! V_185 . V_201 )
return - V_72 ;
if ( F_156 ( & V_202 ) )
return - V_284 ;
V_196 = V_191 ;
V_17 = 0 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( F_85 ( V_158 , L_49 ) == 0 ) {
F_202 ( 1 ) ;
} else if ( F_85 ( V_158 , L_50 ) == 0 ) {
F_202 ( 0 ) ;
V_17 = - V_157 ;
} else if ( F_85 ( V_158 , L_161 ) == 0 ) {
V_196 = ( V_190 | V_192 )
& ~ V_286 ;
} else if ( sscanf ( V_158 , L_162 , & V_196 ) == 1 ) {
} else if ( sscanf ( V_158 , L_163 , & V_196 ) == 1 ) {
} else {
V_17 = - V_92 ;
goto V_378;
}
}
if ( ! V_17 ) {
F_81 ( L_164 ,
L_165 , V_196 ) ;
V_17 = F_112 ( V_196 ) ;
}
V_378:
F_117 ( & V_202 ) ;
return V_17 ;
}
static int F_206 ( void )
{
int V_30 ;
#ifdef F_101
if ( V_173 )
return ( V_167 ) ?
V_141 : V_134 ;
#endif
if ( ! F_7 ( V_128 , & V_30 , L_166 , L_62 ) )
return - V_50 ;
return ( ( V_30 & V_379 ) != 0 ) ?
V_141 : V_134 ;
}
static int F_207 ( enum V_380 V_204 )
{
int V_30 ;
F_17 ( V_139 ,
L_167 ,
( V_204 == V_141 ) ? L_49 : L_50 ) ;
#ifdef F_101
if ( V_173 ) {
V_167 = ( V_204 == V_141 ) ;
return 0 ;
}
#endif
if ( V_204 == V_141 )
V_30 = V_379
| V_381 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_128 , NULL , L_168 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_208 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return F_79 ( V_382 ,
V_121 , V_125 ) ;
}
static T_8 F_209 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
return F_80 ( V_382 ,
V_121 , V_125 , V_35 ) ;
}
static void F_210 ( void )
{
if ( ! F_7 ( NULL , NULL , L_169 , L_9 ,
V_383 ) )
F_31 ( L_170 ) ;
else
F_17 ( V_139 ,
L_171 ) ;
}
static void F_211 ( void )
{
F_54 ( & V_153 -> V_105 . V_124 ,
& V_384 ) ;
F_76 ( V_382 ) ;
F_210 () ;
}
static int T_1 F_212 ( struct V_296 * V_297 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_139 ,
L_172 ) ;
F_182 ( V_328 ) ;
V_185 . V_385 = V_128 &&
F_7 ( V_128 , & V_30 , L_166 , L_105 ) ;
F_17 ( V_55 | V_139 ,
L_173 ,
F_1 ( V_185 . V_385 ) ,
V_30 ) ;
#ifdef F_101
if ( V_173 ) {
V_185 . V_385 = 1 ;
F_75 ( L_174 ) ;
} else
#endif
if ( V_185 . V_385 &&
! ( V_30 & V_386 ) ) {
V_185 . V_385 = 0 ;
F_20 ( V_55 | V_139 ,
L_175 ) ;
}
if ( ! V_185 . V_385 )
return 1 ;
V_17 = F_70 ( V_382 ,
& V_387 ,
V_388 ,
V_389 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_213 ( & V_153 -> V_105 . V_124 ,
& V_384 ) ;
if ( V_17 ) {
F_76 ( V_382 ) ;
return V_17 ;
}
return 0 ;
}
static int F_214 ( struct V_88 * V_89 )
{
return F_82 ( V_382 , V_89 ) ;
}
static int F_215 ( char * V_125 )
{
return F_84 ( V_382 , V_125 ) ;
}
static int F_216 ( void )
{
int V_30 ;
#ifdef F_101
if ( V_175 )
return ( V_168 ) ?
V_141 : V_134 ;
#endif
if ( ! F_7 ( V_128 , & V_30 , L_176 , L_62 ) )
return - V_50 ;
return ( ( V_30 & V_390 ) != 0 ) ?
V_141 : V_134 ;
}
static int F_217 ( enum V_380 V_204 )
{
int V_30 ;
F_17 ( V_139 ,
L_177 ,
( V_204 == V_141 ) ? L_49 : L_50 ) ;
#ifdef F_101
if ( V_175 ) {
V_168 = ( V_204 == V_141 ) ;
return 0 ;
}
#endif
if ( V_204 == V_141 )
V_30 = V_390
| V_391 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_128 , NULL , L_178 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_218 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return F_79 ( V_392 ,
V_121 , V_125 ) ;
}
static T_8 F_219 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
return F_80 ( V_392 ,
V_121 , V_125 , V_35 ) ;
}
static void F_220 ( void )
{
if ( ! F_7 ( NULL , NULL , L_179 , L_9 ,
V_393 ) )
F_31 ( L_180 ) ;
else
F_17 ( V_139 ,
L_181 ) ;
}
static void F_221 ( void )
{
F_54 ( & V_153 -> V_105 . V_124 ,
& V_394 ) ;
F_76 ( V_392 ) ;
F_220 () ;
}
static int T_1 F_222 ( struct V_296 * V_297 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_139 ,
L_182 ) ;
F_182 ( V_328 ) ;
V_185 . V_395 = V_128 &&
F_7 ( V_128 , & V_30 , L_176 , L_105 ) ;
F_17 ( V_55 | V_139 ,
L_183 ,
F_1 ( V_185 . V_395 ) ,
V_30 ) ;
#ifdef F_101
if ( V_175 ) {
V_185 . V_395 = 1 ;
F_75 ( L_184 ) ;
} else
#endif
if ( V_185 . V_395 &&
! ( V_30 & V_396 ) ) {
V_185 . V_395 = 0 ;
F_20 ( V_55 | V_139 ,
L_185 ) ;
}
if ( ! V_185 . V_395 )
return 1 ;
V_17 = F_70 ( V_392 ,
& V_397 ,
V_398 ,
V_399 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_213 ( & V_153 -> V_105 . V_124 ,
& V_394 ) ;
if ( V_17 ) {
F_76 ( V_392 ) ;
return V_17 ;
}
return 0 ;
}
static int F_223 ( struct V_88 * V_89 )
{
return F_82 ( V_392 , V_89 ) ;
}
static int F_224 ( char * V_125 )
{
return F_84 ( V_392 , V_125 ) ;
}
static int F_225 ( void )
{
int V_30 ;
#ifdef F_101
if ( V_177 )
return ( V_169 ) ?
V_141 : V_134 ;
#endif
if ( ! F_7 ( V_128 , & V_30 , L_186 , L_62 ) )
return - V_50 ;
return ( ( V_30 & V_400 ) != 0 ) ?
V_141 : V_134 ;
}
static int F_226 ( enum V_380 V_204 )
{
int V_30 ;
F_17 ( V_139 ,
L_187 ,
( V_204 == V_141 ) ? L_49 : L_50 ) ;
#ifdef F_101
if ( V_177 ) {
V_169 = ( V_204 == V_141 ) ;
return 0 ;
}
#endif
if ( V_204 == V_141 )
V_30 = V_400 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_128 , NULL , L_188 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static void F_227 ( void )
{
F_76 ( V_401 ) ;
}
static int T_1 F_228 ( struct V_296 * V_297 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_139 ,
L_189 ) ;
F_182 ( V_328 ) ;
V_185 . V_402 = V_128 &&
F_7 ( V_128 , & V_30 , L_186 , L_105 ) ;
F_17 ( V_55 | V_139 ,
L_190 ,
F_1 ( V_185 . V_402 ) ,
V_30 ) ;
#ifdef F_101
if ( V_177 ) {
V_185 . V_402 = 1 ;
F_75 ( L_191 ) ;
} else
#endif
if ( V_185 . V_402 &&
! ( V_30 & V_403 ) ) {
V_185 . V_402 = 0 ;
F_20 ( V_55 ,
L_192 ) ;
}
if ( ! V_185 . V_402 )
return 1 ;
V_17 = F_70 ( V_401 ,
& V_404 ,
V_405 ,
V_406 ,
false ) ;
return V_17 ;
}
static int T_1 F_229 ( struct V_296 * V_297 )
{
int V_407 ;
F_17 ( V_55 , L_193 ) ;
F_182 ( V_408 ) ;
if ( F_6 () )
F_182 ( V_409 ) ;
if ( V_410 && F_7 ( NULL , & V_407 , L_194 , L_62 ) && V_407 )
V_411 = V_410 ;
if ( ! V_411 )
V_412 = V_413 ;
else if ( F_6 () &&
F_7 ( V_411 , & V_414 , L_195 , L_105 ) )
V_412 = V_415 ;
else if ( F_6 () &&
F_7 ( V_411 , & V_414 , L_196 , L_105 ) )
V_412 = V_416 ;
else
V_412 = V_417 ;
F_17 ( V_55 , L_197 ,
F_1 ( V_412 != V_413 ) ,
V_412 ) ;
return ( V_412 != V_413 ) ? 0 : 1 ;
}
static void F_230 ( void )
{
F_20 ( V_293 ,
L_198 ) ;
if ( F_231 ( V_414 ) )
F_8 ( L_199
L_200 ) ;
}
static int F_232 ( void )
{
int V_30 = 0 ;
int V_42 ;
switch ( V_412 ) {
case V_415 :
if ( ! F_7 ( NULL , & V_42 , L_201 , L_7 ,
V_418 ) )
return - V_50 ;
V_30 = V_42 & V_419 ;
break;
case V_416 :
if ( ! F_7 ( NULL , & V_42 , L_202 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_420 ;
if ( ! F_7 ( NULL , & V_42 , L_203 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_421 ;
break;
case V_417 :
if ( ! F_7 ( NULL , NULL , L_204 , L_9 , 1 ) ||
! F_7 ( NULL , & V_42 , L_203 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_421 ;
if ( ! F_7 ( NULL , NULL , L_204 , L_9 , 0 ) ||
! F_7 ( NULL , & V_42 , L_202 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_420 ;
if ( ! F_7 ( NULL , & V_42 , L_205 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_422 ;
break;
default:
return - V_423 ;
}
return V_30 ;
}
static int F_233 ( int V_30 )
{
int V_424 ;
int V_17 = 0 ;
switch ( V_412 ) {
case V_415 :
V_17 = F_7 ( NULL , NULL ,
L_206 , L_8 ,
V_425 ,
V_30 | V_426 ) ;
break;
case V_416 :
V_424 = F_234 () ;
if ( V_424 < 0 )
return V_424 ;
V_17 = F_231 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_411 , NULL ,
L_207 , L_8 , V_30 * 0x100 , 0 ) ;
if ( ! V_424 && F_231 ( V_424 ) ) {
F_8 ( L_208 ) ;
return - V_50 ;
}
break;
case V_417 :
V_17 = F_7 ( NULL , NULL , L_204 , L_9 , 0x80 ) &&
F_7 ( NULL , NULL , L_209 , L_8 , V_30 , 1 ) ;
break;
default:
return - V_423 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_234 ( void )
{
int V_424 = 0 ;
switch ( V_412 ) {
case V_415 :
if ( ! F_7 ( V_411 , & V_424 , L_195 , L_62 ) )
return - V_50 ;
break;
case V_416 :
case V_417 :
if ( ! F_7 ( V_411 , & V_424 , L_210 , L_62 ) )
return - V_50 ;
break;
default:
return - V_423 ;
}
return V_424 & 1 ;
}
static int F_231 ( int V_203 )
{
if ( ! F_7 ( V_411 , NULL , L_211 , L_9 , ( V_203 ) ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static int F_235 ( void )
{
int V_424 = F_234 () ;
int V_17 ;
if ( V_424 < 0 )
return V_424 ;
switch ( V_412 ) {
case V_415 :
V_17 = F_231 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_427 , NULL , L_212 , L_213 ) ;
break;
case V_416 :
case V_417 :
V_17 = F_231 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_411 , NULL , L_214 , L_213 ) ;
break;
default:
return - V_423 ;
}
if ( ! V_424 && F_231 ( V_424 ) ) {
F_8 ( L_208 ) ;
return - V_50 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_236 ( void )
{
switch ( V_412 ) {
case V_415 :
return F_7 ( V_427 , NULL , L_215 , L_213 ) ?
0 : - V_50 ;
case V_416 :
return F_7 ( V_411 , NULL , L_216 , L_213 ) ?
0 : - V_50 ;
case V_417 :
return F_7 ( NULL , NULL , L_217 , L_213 ) ?
0 : - V_50 ;
default:
return - V_423 ;
}
}
static int F_237 ( struct V_88 * V_89 )
{
int V_30 , V_424 ;
if ( V_412 == V_413 ) {
F_83 ( V_89 , L_44 ) ;
return 0 ;
}
if ( ! F_238 ( V_428 ) )
return - V_157 ;
V_30 = F_232 () ;
if ( V_30 < 0 )
return V_30 ;
V_424 = F_234 () ;
if ( V_424 < 0 )
return V_424 ;
F_83 ( V_89 , L_218 ) ;
F_83 ( V_89 , L_219 , F_184 ( V_30 , 0 ) ) ;
F_83 ( V_89 , L_220 , F_184 ( V_30 , 1 ) ) ;
if ( V_412 == V_417 )
F_83 ( V_89 , L_221 , F_184 ( V_30 , 3 ) ) ;
F_83 ( V_89 , L_222 , F_184 ( V_424 , 0 ) ) ;
F_83 ( V_89 , L_223 ) ;
F_83 ( V_89 , L_224 ) ;
if ( V_412 == V_417 )
F_83 ( V_89 , L_225 ) ;
F_83 ( V_89 , L_226 ) ;
F_83 ( V_89 , L_227 ) ;
return 0 ;
}
static int F_239 ( char * V_125 )
{
char * V_158 ;
int V_203 , V_429 , V_30 ;
int V_17 ;
if ( V_412 == V_413 )
return - V_72 ;
if ( ! F_238 ( V_428 ) )
return - V_157 ;
V_203 = 0 ;
V_429 = 0 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( F_85 ( V_158 , L_228 ) == 0 ) {
V_203 |= V_420 ;
} else if ( F_85 ( V_158 , L_229 ) == 0 ) {
V_429 |= V_420 ;
} else if ( F_85 ( V_158 , L_230 ) == 0 ) {
V_203 |= V_421 ;
} else if ( F_85 ( V_158 , L_231 ) == 0 ) {
V_429 |= V_421 ;
} else if ( V_412 == V_417 &&
F_85 ( V_158 , L_232 ) == 0 ) {
V_203 |= V_422 ;
} else if ( V_412 == V_417 &&
F_85 ( V_158 , L_233 ) == 0 ) {
V_429 |= V_422 ;
} else if ( F_85 ( V_158 , L_234 ) == 0 ) {
V_17 = F_231 ( 1 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_85 ( V_158 , L_235 ) == 0 ) {
V_17 = F_231 ( 0 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_85 ( V_158 , L_236 ) == 0 ) {
V_17 = F_235 () ;
if ( V_17 )
return V_17 ;
} else if ( F_85 ( V_158 , L_237 ) == 0 ) {
V_17 = F_236 () ;
if ( V_17 )
return V_17 ;
} else
return - V_92 ;
}
if ( V_203 || V_429 ) {
V_30 = F_232 () ;
if ( V_30 < 0 )
return V_30 ;
V_17 = F_233 ( ( V_30 & ~ V_429 ) | V_203 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_240 ( void )
{
int V_30 = 0 ;
if ( V_185 . V_430 ) {
if ( ! F_7 ( V_427 , & V_30 , L_238 , L_62 ) )
return - V_50 ;
return ( ! ! V_30 ) ;
}
return - V_49 ;
}
static int F_241 ( int V_30 )
{
int V_70 ;
if ( V_185 . V_431 ) {
if ( V_48 ) {
V_70 = F_7 ( V_48 , NULL , NULL , L_9 ,
( V_30 ) ?
V_432 :
V_433 ) ;
} else {
V_70 = F_7 ( V_434 , NULL , NULL , L_9 ,
( V_30 ) ? 1 : 0 ) ;
}
return ( V_70 ) ? 0 : - V_50 ;
}
return - V_49 ;
}
static void F_242 ( struct V_435 * V_436 )
{
struct V_437 * V_63 =
F_243 ( V_436 , struct V_437 , V_436 ) ;
if ( F_138 ( V_66 == V_67 ) )
F_241 ( ( V_63 -> V_438 != V_439 ) ) ;
}
static void F_244 ( struct V_440 * V_441 ,
enum V_442 V_443 )
{
struct V_437 * V_63 =
F_243 ( V_441 ,
struct V_437 ,
V_440 ) ;
V_63 -> V_438 = ( V_443 != V_444 ) ?
V_445 : V_439 ;
F_245 ( V_446 , & V_63 -> V_436 ) ;
}
static enum V_442 F_246 ( struct V_440 * V_441 )
{
return ( F_240 () == 1 ) ? V_447 : V_444 ;
}
static int T_1 F_247 ( struct V_296 * V_297 )
{
int V_70 ;
F_17 ( V_55 , L_239 ) ;
if ( F_6 () ) {
F_182 ( V_448 ) ;
F_182 ( V_449 ) ;
}
F_182 ( V_450 ) ;
F_248 ( & V_451 . V_436 , F_242 ) ;
V_185 . V_431 = ( V_48 || V_434 ) && ! V_452 ;
if ( V_185 . V_431 )
V_185 . V_430 =
F_7 ( V_427 , NULL , L_238 , L_240 ) ;
F_17 ( V_55 , L_241 ,
F_1 ( V_185 . V_431 ) ,
F_1 ( V_185 . V_430 ) ) ;
if ( ! V_185 . V_431 )
return 1 ;
V_70 = F_249 ( & V_153 -> V_105 ,
& V_451 . V_440 ) ;
if ( V_70 < 0 ) {
V_185 . V_431 = 0 ;
V_185 . V_430 = 0 ;
} else {
V_70 = 0 ;
}
return V_70 ;
}
static void F_250 ( void )
{
F_251 ( & V_451 . V_440 ) ;
F_252 ( V_446 ) ;
}
static int F_253 ( struct V_88 * V_89 )
{
int V_30 ;
if ( ! V_185 . V_431 ) {
F_83 ( V_89 , L_44 ) ;
} else if ( ! V_185 . V_430 ) {
F_83 ( V_89 , L_242 ) ;
F_83 ( V_89 , L_243 ) ;
} else {
V_30 = F_240 () ;
if ( V_30 < 0 )
return V_30 ;
F_83 ( V_89 , L_45 , F_254 ( V_30 , 0 ) ) ;
F_83 ( V_89 , L_243 ) ;
}
return 0 ;
}
static int F_255 ( char * V_125 )
{
char * V_158 ;
int V_453 = 0 ;
if ( ! V_185 . V_431 )
return - V_72 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( F_85 ( V_158 , L_244 ) == 0 ) {
V_453 = 1 ;
} else if ( F_85 ( V_158 , L_245 ) == 0 ) {
V_453 = 0 ;
} else
return - V_92 ;
}
return F_241 ( V_453 ) ;
}
static T_8 F_256 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_47 ;
int V_17 ;
if ( F_56 ( V_125 , 21 , & V_47 ) )
return - V_92 ;
V_17 = F_15 ( V_47 ) ;
return ( V_17 ) ? V_17 : V_35 ;
}
static int T_1 F_257 ( struct V_296 * V_297 )
{
int V_17 ;
F_17 ( V_55 ,
L_246 ) ;
F_182 ( V_450 ) ;
F_17 ( V_55 , L_247 ,
F_1 ( V_48 != NULL ) ) ;
V_17 = F_258 ( & V_153 -> V_105 , & V_454 ) ;
if ( V_17 )
return V_17 ;
return ( V_48 ) ? 0 : 1 ;
}
static void F_259 ( void )
{
F_260 ( & V_153 -> V_105 , & V_454 ) ;
}
static int F_261 ( struct V_88 * V_89 )
{
if ( ! V_48 )
F_83 ( V_89 , L_44 ) ;
else {
F_83 ( V_89 , L_218 ) ;
F_83 ( V_89 , L_248 ) ;
}
return 0 ;
}
static int F_262 ( char * V_125 )
{
char * V_158 ;
int V_47 , V_17 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( sscanf ( V_158 , L_249 , & V_47 ) == 1 &&
V_47 >= 0 && V_47 <= 21 ) {
} else
return - V_92 ;
V_17 = F_15 ( V_47 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static inline bool F_263 ( const unsigned int V_455 )
{
#ifdef F_264
return false ;
#else
return ( 1U & ( V_456 >> V_455 ) ) == 0 ;
#endif
}
static int F_265 ( const unsigned int V_455 )
{
int V_30 ;
enum V_457 V_458 ;
switch ( V_459 ) {
case V_460 :
if ( ! F_7 ( V_427 ,
& V_30 , L_250 , L_7 , 1 << V_455 ) )
return - V_50 ;
V_458 = ( V_30 == 0 ) ?
V_439 :
( ( V_30 == 1 ) ?
V_445 :
V_461 ) ;
V_462 [ V_455 ] = V_458 ;
return V_458 ;
default:
return - V_49 ;
}
}
static int F_266 ( const unsigned int V_455 ,
const enum V_457 V_463 )
{
static const unsigned int V_464 [] = { 0 , 1 , 3 } ;
static const unsigned int V_465 [] = { 0 , 0x80 , 0xc0 } ;
int V_70 = 0 ;
switch ( V_459 ) {
case V_460 :
if ( F_140 ( V_455 > 7 ) )
return - V_92 ;
if ( F_140 ( F_263 ( V_455 ) ) )
return - V_157 ;
if ( ! F_7 ( V_466 , NULL , NULL , L_8 ,
( 1 << V_455 ) , V_464 [ V_463 ] ) )
V_70 = - V_50 ;
break;
case V_467 :
if ( F_140 ( V_455 > 7 ) )
return - V_92 ;
if ( F_140 ( F_263 ( V_455 ) ) )
return - V_157 ;
V_70 = F_14 ( V_468 , ( 1 << V_455 ) ) ;
if ( V_70 >= 0 )
V_70 = F_14 ( V_469 ,
( V_463 == V_461 ) << V_455 ) ;
if ( V_70 >= 0 )
V_70 = F_14 ( V_470 ,
( V_463 != V_439 ) << V_455 ) ;
break;
case V_471 :
if ( F_140 ( V_455 >= V_472 ) )
return - V_92 ;
if ( F_140 ( F_263 ( V_455 ) ) )
return - V_157 ;
if ( ! F_7 ( V_466 , NULL , NULL , L_8 ,
V_455 , V_465 [ V_463 ] ) )
V_70 = - V_50 ;
break;
default:
V_70 = - V_49 ;
}
if ( ! V_70 )
V_462 [ V_455 ] = V_463 ;
return V_70 ;
}
static void F_267 ( struct V_435 * V_436 )
{
struct V_437 * V_63 =
F_243 ( V_436 , struct V_437 , V_436 ) ;
if ( F_138 ( V_66 == V_67 ) )
F_266 ( V_63 -> V_455 , V_63 -> V_438 ) ;
}
static void F_268 ( struct V_440 * V_441 ,
enum V_442 V_443 )
{
struct V_437 * V_63 = F_243 ( V_441 ,
struct V_437 , V_440 ) ;
if ( V_443 == V_444 )
V_63 -> V_438 = V_439 ;
else if ( V_462 [ V_63 -> V_455 ] != V_461 )
V_63 -> V_438 = V_445 ;
else
V_63 -> V_438 = V_461 ;
F_245 ( V_446 , & V_63 -> V_436 ) ;
}
static int F_269 ( struct V_440 * V_441 ,
unsigned long * V_473 , unsigned long * V_474 )
{
struct V_437 * V_63 = F_243 ( V_441 ,
struct V_437 , V_440 ) ;
if ( * V_473 == 0 && * V_474 == 0 ) {
* V_473 = 500 ;
* V_474 = 500 ;
} else if ( ( * V_473 != 500 ) || ( * V_474 != 500 ) )
return - V_92 ;
V_63 -> V_438 = V_461 ;
F_245 ( V_446 , & V_63 -> V_436 ) ;
return 0 ;
}
static enum V_442 F_270 ( struct V_440 * V_441 )
{
int V_70 ;
struct V_437 * V_63 = F_243 ( V_441 ,
struct V_437 , V_440 ) ;
V_70 = F_265 ( V_63 -> V_455 ) ;
if ( V_70 == V_439 || V_70 < 0 )
V_70 = V_444 ;
else
V_70 = V_447 ;
return V_70 ;
}
static void F_271 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_472 ; V_42 ++ ) {
if ( V_475 [ V_42 ] . V_440 . V_51 )
F_251 ( & V_475 [ V_42 ] . V_440 ) ;
}
F_252 ( V_446 ) ;
F_36 ( V_475 ) ;
}
static int T_1 F_272 ( unsigned int V_455 )
{
int V_70 ;
V_475 [ V_455 ] . V_455 = V_455 ;
if ( ! V_476 [ V_455 ] )
return 0 ;
V_475 [ V_455 ] . V_440 . V_477 = & F_268 ;
V_475 [ V_455 ] . V_440 . V_478 = & F_269 ;
if ( V_459 == V_460 )
V_475 [ V_455 ] . V_440 . V_479 =
& F_270 ;
V_475 [ V_455 ] . V_440 . V_51 = V_476 [ V_455 ] ;
F_248 ( & V_475 [ V_455 ] . V_436 , F_267 ) ;
V_70 = F_249 ( & V_153 -> V_105 ,
& V_475 [ V_455 ] . V_440 ) ;
if ( V_70 < 0 )
V_475 [ V_455 ] . V_440 . V_51 = NULL ;
return V_70 ;
}
static enum V_480 T_1 F_273 ( void )
{
T_4 V_30 ;
if ( F_6 () ) {
V_30 = F_18 ( V_427 , L_251 , & V_466 ) ;
if ( F_19 ( V_30 ) )
return V_460 ;
V_30 = F_18 ( V_427 , L_252 , & V_466 ) ;
if ( F_19 ( V_30 ) )
return V_467 ;
}
V_30 = F_18 ( V_427 , L_253 , & V_466 ) ;
if ( F_19 ( V_30 ) )
return V_471 ;
V_466 = NULL ;
return V_481 ;
}
static int T_1 F_274 ( struct V_296 * V_297 )
{
unsigned int V_42 ;
int V_70 ;
unsigned long V_482 ;
F_17 ( V_55 , L_254 ) ;
V_459 = F_273 () ;
F_17 ( V_55 , L_255 ,
F_1 ( V_459 ) , V_459 ) ;
if ( V_459 == V_481 )
return 1 ;
V_475 = F_34 ( sizeof( * V_475 ) * V_472 ,
V_81 ) ;
if ( ! V_475 ) {
F_8 ( L_256 ) ;
return - V_82 ;
}
V_482 = F_4 ( V_483 ,
F_99 ( V_483 ) ) ;
for ( V_42 = 0 ; V_42 < V_472 ; V_42 ++ ) {
if ( ! F_263 ( V_42 ) &&
F_275 ( V_42 , & V_482 ) ) {
V_70 = F_272 ( V_42 ) ;
if ( V_70 < 0 ) {
F_271 () ;
return V_70 ;
}
}
}
#ifdef F_264
F_31 ( L_257
L_258 ) ;
#endif
return 0 ;
}
static int F_276 ( struct V_88 * V_89 )
{
if ( ! V_459 ) {
F_83 ( V_89 , L_44 ) ;
return 0 ;
}
F_83 ( V_89 , L_218 ) ;
if ( V_459 == V_460 ) {
int V_42 , V_30 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_30 = F_265 ( V_42 ) ;
if ( V_30 < 0 )
return - V_50 ;
F_83 ( V_89 , L_259 ,
V_42 , F_277 ( V_30 ) ) ;
}
}
F_83 ( V_89 , L_260
L_261 ) ;
return 0 ;
}
static int F_278 ( char * V_125 )
{
char * V_158 ;
int V_455 , V_70 ;
enum V_457 V_117 ;
if ( ! V_459 )
return - V_72 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( sscanf ( V_158 , L_262 , & V_455 ) != 1 || V_455 < 0 || V_455 > 15 )
return - V_92 ;
if ( strstr ( V_158 , L_245 ) ) {
V_117 = V_439 ;
} else if ( strstr ( V_158 , L_244 ) ) {
V_117 = V_445 ;
} else if ( strstr ( V_158 , L_263 ) ) {
V_117 = V_461 ;
} else {
return - V_92 ;
}
V_70 = F_266 ( V_455 , V_117 ) ;
if ( V_70 < 0 )
return V_70 ;
}
return 0 ;
}
static int T_1 F_279 ( struct V_296 * V_297 )
{
unsigned long V_13 ;
F_17 ( V_55 , L_264 ) ;
F_182 ( V_484 ) ;
F_17 ( V_55 , L_265 ,
F_1 ( V_485 != NULL ) ) ;
V_13 = F_4 ( V_486 ,
F_99 ( V_486 ) ) ;
V_185 . V_487 = ! ! ( V_13 & V_488 ) ;
return ( V_485 ) ? 0 : 1 ;
}
static int F_280 ( struct V_88 * V_89 )
{
if ( ! V_485 )
F_83 ( V_89 , L_44 ) ;
else {
F_83 ( V_89 , L_218 ) ;
F_83 ( V_89 , L_266 ) ;
}
return 0 ;
}
static int F_281 ( char * V_125 )
{
char * V_158 ;
int V_489 ;
if ( ! V_485 )
return - V_72 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( sscanf ( V_158 , L_249 , & V_489 ) == 1 &&
V_489 >= 0 && V_489 <= 17 ) {
} else
return - V_92 ;
if ( V_185 . V_487 ) {
if ( ! F_7 ( V_485 , NULL , NULL , L_8 ,
V_489 , 0 ) )
return - V_50 ;
} else {
if ( ! F_7 ( V_485 , NULL , NULL , L_9 ,
V_489 ) )
return - V_50 ;
}
}
return 0 ;
}
static int F_282 ( int V_490 , T_17 * V_38 )
{
int V_156 ;
T_18 V_491 ;
char V_492 [ 5 ] ;
V_156 = V_493 ;
switch ( V_494 ) {
#if V_495 >= 16
case V_496 :
if ( V_490 >= 8 && V_490 <= 15 ) {
V_156 = V_497 ;
V_490 -= 8 ;
}
#endif
case V_498 :
if ( V_490 <= 7 ) {
if ( ! F_11 ( V_156 + V_490 , & V_491 ) )
return - V_50 ;
* V_38 = V_491 * 1000 ;
return 0 ;
}
break;
case V_499 :
if ( V_490 <= 7 ) {
snprintf ( V_492 , sizeof( V_492 ) , L_267 , '0' + V_490 ) ;
if ( ! F_7 ( V_427 , NULL , L_268 , L_213 ) )
return - V_50 ;
if ( ! F_7 ( V_427 , & V_156 , V_492 , L_62 ) )
return - V_50 ;
* V_38 = ( V_156 - 2732 ) * 100 ;
return 0 ;
}
break;
case V_500 :
if ( V_490 <= 7 ) {
snprintf ( V_492 , sizeof( V_492 ) , L_267 , '0' + V_490 ) ;
if ( ! F_7 ( V_427 , & V_156 , V_492 , L_62 ) )
return - V_50 ;
if ( V_156 > 127 || V_156 < - 127 )
V_156 = V_501 ;
* V_38 = V_156 * 1000 ;
return 0 ;
}
break;
case V_502 :
default:
return - V_423 ;
}
return - V_92 ;
}
static int F_283 ( struct V_503 * V_117 )
{
int V_17 , V_42 ;
int V_219 ;
V_219 = 8 ;
V_42 = 0 ;
if ( ! V_117 )
return - V_92 ;
if ( V_494 == V_496 )
V_219 = 16 ;
for ( V_42 = 0 ; V_42 < V_219 ; V_42 ++ ) {
V_17 = F_282 ( V_42 , & V_117 -> V_504 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return V_219 ;
}
static void F_195 ( void )
{
int V_219 , V_42 ;
struct V_503 V_156 ;
V_219 = F_283 ( & V_156 ) ;
if ( V_219 <= 0 )
return;
F_31 ( L_269 ) ;
for ( V_42 = 0 ; V_42 < V_219 ; V_42 ++ ) {
if ( V_156 . V_504 [ V_42 ] != V_505 )
F_284 ( L_270 , ( int ) ( V_156 . V_504 [ V_42 ] / 1000 ) ) ;
else
F_284 ( L_271 ) ;
}
F_284 ( L_272 ) ;
}
static T_8 F_285 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
struct V_506 * V_507 =
F_286 ( V_121 ) ;
int V_490 = V_507 -> V_508 ;
T_17 V_38 ;
int V_17 ;
V_17 = F_282 ( V_490 , & V_38 ) ;
if ( V_17 )
return V_17 ;
if ( V_38 == V_505 )
return - V_49 ;
return snprintf ( V_125 , V_100 , L_42 , V_38 ) ;
}
static int T_1 F_287 ( struct V_296 * V_297 )
{
T_6 V_156 , V_509 , V_510 ;
int V_42 ;
int V_511 ;
int V_17 ;
F_17 ( V_55 , L_273 ) ;
V_511 = F_7 ( V_427 , NULL , L_274 , L_240 ) ;
if ( V_7 . V_12 ) {
V_509 = V_510 = 0 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( F_11 ( V_493 + V_42 , & V_156 ) ) {
V_509 |= V_156 ;
} else {
V_509 = 0 ;
break;
}
if ( F_11 ( V_497 + V_42 , & V_156 ) ) {
V_510 |= V_156 ;
} else {
V_509 = 0 ;
break;
}
}
if ( V_509 == 0 ) {
if ( V_511 ) {
F_8 ( L_275
L_276
L_277 ) ;
V_494 = V_500 ;
} else {
F_8 ( L_275
L_278 ) ;
V_494 = V_502 ;
}
} else {
V_494 =
( V_510 != 0 ) ?
V_496 : V_498 ;
}
} else if ( V_511 ) {
if ( F_6 () &&
F_7 ( V_427 , NULL , L_268 , L_240 ) ) {
V_494 = V_499 ;
} else {
V_494 = V_500 ;
}
} else {
V_494 = V_502 ;
}
F_17 ( V_55 , L_279 ,
F_1 ( V_494 != V_502 ) ,
V_494 ) ;
switch ( V_494 ) {
case V_496 :
V_17 = F_213 ( & V_512 -> V_105 . V_124 ,
& V_513 ) ;
if ( V_17 )
return V_17 ;
break;
case V_498 :
case V_500 :
case V_499 :
V_17 = F_213 ( & V_512 -> V_105 . V_124 ,
& V_514 ) ;
if ( V_17 )
return V_17 ;
break;
case V_502 :
default:
return 1 ;
}
return 0 ;
}
static void F_288 ( void )
{
switch ( V_494 ) {
case V_496 :
F_54 ( & V_512 -> V_105 . V_124 ,
& V_513 ) ;
break;
case V_498 :
case V_500 :
case V_499 :
F_54 ( & V_512 -> V_105 . V_124 ,
& V_514 ) ;
break;
case V_502 :
default:
break;
}
}
static int F_289 ( struct V_88 * V_89 )
{
int V_219 , V_42 ;
struct V_503 V_156 ;
V_219 = F_283 ( & V_156 ) ;
if ( F_140 ( V_219 < 0 ) )
return V_219 ;
F_83 ( V_89 , L_280 ) ;
if ( V_219 > 0 ) {
for ( V_42 = 0 ; V_42 < ( V_219 - 1 ) ; V_42 ++ )
F_83 ( V_89 , L_281 , V_156 . V_504 [ V_42 ] / 1000 ) ;
F_83 ( V_89 , L_42 , V_156 . V_504 [ V_42 ] / 1000 ) ;
} else
F_83 ( V_89 , L_282 ) ;
return 0 ;
}
static unsigned int F_290 ( void )
{
T_6 V_515 ;
V_515 = ( F_131 ( V_240 )
& V_242 )
>> V_243 ;
V_515 &= V_516 ;
return V_515 ;
}
static void F_291 ( void )
{
T_6 V_517 = 0 ;
T_6 V_518 ;
if ( V_519 != V_520 )
return;
F_17 ( V_521 ,
L_283 ) ;
if ( F_156 ( & V_522 ) < 0 )
return;
if ( F_140 ( ! F_11 ( V_523 , & V_517 ) ) )
goto V_524;
V_517 &= V_525 ;
V_518 = F_131 ( V_240 ) ;
if ( V_517 != ( ( V_518 & V_242 )
>> V_243 ) ) {
V_518 &= ~ ( V_242 <<
V_243 ) ;
V_518 |= V_517 ;
F_292 ( V_518 , V_240 ) ;
F_20 ( V_521 ,
L_284 ,
( unsigned int ) V_517 , ( unsigned int ) V_518 ) ;
} else
F_17 ( V_521 ,
L_285 ,
( unsigned int ) V_517 , ( unsigned int ) V_518 ) ;
V_524:
F_117 ( & V_522 ) ;
}
static int F_293 ( int * V_30 )
{
T_6 V_517 = 0 ;
switch ( V_519 ) {
case V_526 :
* V_30 = F_290 () ;
return 0 ;
case V_527 :
case V_520 :
if ( F_140 ( ! F_11 ( V_523 , & V_517 ) ) )
return - V_50 ;
* V_30 = V_517 ;
return 0 ;
default:
return - V_49 ;
}
}
static int F_294 ( unsigned int V_38 )
{
T_6 V_517 = 0 ;
if ( F_140 ( ! F_11 ( V_523 , & V_517 ) ) )
return - V_50 ;
if ( F_140 ( ! F_13 ( V_523 ,
( V_517 & V_528 ) |
( V_38 & V_525 ) ) ) )
return - V_50 ;
return 0 ;
}
static int F_295 ( unsigned int V_38 )
{
int V_47 , V_529 ;
unsigned int V_530 , V_42 ;
V_530 = F_290 () ;
if ( V_38 == V_530 )
return 0 ;
V_47 = ( V_38 > V_530 ) ?
V_531 :
V_532 ;
V_529 = ( V_38 > V_530 ) ? 1 : - 1 ;
for ( V_42 = V_530 ; V_42 != V_38 ; V_42 += V_529 )
if ( F_15 ( V_47 ) )
return - V_50 ;
return 0 ;
}
static int V_477 ( unsigned int V_38 )
{
int V_17 ;
if ( V_38 > V_516 || V_38 < 0 )
return - V_92 ;
F_17 ( V_521 ,
L_286 , V_38 ) ;
V_17 = F_156 ( & V_522 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_519 ) {
case V_527 :
case V_520 :
V_17 = F_294 ( V_38 ) ;
break;
case V_526 :
V_17 = F_295 ( V_38 ) ;
break;
default:
V_17 = - V_49 ;
}
F_117 ( & V_522 ) ;
return V_17 ;
}
static int F_296 ( struct V_533 * V_534 )
{
unsigned int V_56 =
( V_534 -> V_535 . V_536 == V_537 &&
V_534 -> V_535 . V_538 == V_537 ) ?
V_534 -> V_535 . V_443 : 0 ;
F_20 ( V_521 ,
L_287 ,
V_56 ) ;
return V_477 ( V_56 ) ;
}
static int V_479 ( struct V_533 * V_534 )
{
int V_30 , V_17 ;
V_17 = F_156 ( & V_522 ) ;
if ( V_17 < 0 )
return 0 ;
V_17 = F_293 ( & V_30 ) ;
F_117 ( & V_522 ) ;
if ( V_17 < 0 )
return 0 ;
return V_30 & V_525 ;
}
static void F_297 ( void )
{
F_298 ( V_539 ,
V_540 ) ;
}
static int T_1 F_299 ( T_3 V_16 )
{
struct V_26 V_541 = { V_542 , NULL } ;
union V_23 * V_543 ;
int V_70 ;
if ( F_19 ( F_9 ( V_16 , L_288 , NULL , & V_541 ) ) ) {
V_543 = (union V_23 * ) V_541 . V_36 ;
if ( ! V_543 || ( V_543 -> type != V_544 ) ) {
F_8 ( L_289 ,
V_332 ) ;
V_70 = 0 ;
} else {
V_70 = V_543 -> V_545 . V_35 ;
}
} else {
return 0 ;
}
F_36 ( V_541 . V_36 ) ;
return V_70 ;
}
static unsigned int T_1 F_300 ( void )
{
T_3 V_546 ;
int V_547 = 0 ;
F_22 ( L_290 , V_548 , & V_546 ) ;
if ( V_546 )
V_547 = F_299 ( V_546 ) ;
V_185 . V_549 = ( V_547 > 0 ) ;
return ( V_547 > 2 ) ? ( V_547 - 2 ) : 0 ;
}
static void T_1 F_301 ( void )
{
unsigned int V_550 ;
F_17 ( V_55 ,
L_291 ) ;
V_550 = F_300 () ;
switch ( V_550 ) {
case 16 :
V_516 = 15 ;
F_75 ( L_292 ) ;
break;
case 8 :
case 0 :
V_516 = 7 ;
F_75 ( L_293 ) ;
break;
default:
F_8 ( L_294
L_295 , V_332 ) ;
V_185 . V_551 = 1 ;
V_516 = V_550 - 1 ;
}
}
static int T_1 F_302 ( struct V_296 * V_297 )
{
struct V_552 V_535 ;
int V_550 ;
unsigned long V_13 ;
F_17 ( V_55 , L_296 ) ;
F_183 ( & V_522 ) ;
V_13 = F_4 ( V_553 ,
F_99 ( V_553 ) ) ;
if ( V_185 . V_551 )
return 1 ;
if ( ! V_554 ) {
F_20 ( V_55 | V_521 ,
L_297
L_298 ) ;
return 1 ;
}
if ( F_187 () ) {
if ( V_554 > 1 ) {
F_75 ( L_299
L_300 ) ;
return 1 ;
} else if ( V_554 == 1 ) {
F_61 ( L_301
L_302
L_303 ) ;
return 1 ;
}
} else if ( V_185 . V_549 && V_554 > 1 ) {
F_31 ( L_304
L_305
L_306 ) ;
}
if ( V_519 > V_555 )
return - V_92 ;
if ( V_519 == V_556 ||
V_519 == V_555 ) {
if ( V_13 & V_557 )
V_519 = V_520 ;
else
V_519 = V_526 ;
F_20 ( V_521 ,
L_307 ,
V_519 ) ;
}
if ( ! F_6 () &&
( V_519 == V_520 ||
V_519 == V_527 ) )
return - V_92 ;
if ( F_293 ( & V_550 ) < 0 )
return 1 ;
memset ( & V_535 , 0 , sizeof( struct V_552 ) ) ;
V_535 . type = V_558 ;
V_535 . V_559 = V_516 ;
V_535 . V_443 = V_550 & V_525 ;
V_539 = F_303 ( V_560 ,
NULL , NULL ,
& V_561 ,
& V_535 ) ;
if ( F_146 ( V_539 ) ) {
int V_70 = F_304 ( V_539 ) ;
V_539 = NULL ;
F_8 ( L_308 ) ;
return V_70 ;
}
F_17 ( V_55 | V_521 ,
L_309 ) ;
if ( V_13 & V_562 ) {
F_31 ( L_310
L_311 , V_519 ) ;
F_31 ( L_312
L_313 , V_332 ) ;
}
F_305 ( V_539 ) ;
F_17 ( V_55 | V_521 ,
L_314
L_315 ) ;
F_113 ( V_194
| V_563
| V_564 ) ;
return 0 ;
}
static void F_306 ( void )
{
F_291 () ;
}
static void F_307 ( void )
{
F_291 () ;
}
static void F_308 ( void )
{
if ( V_539 ) {
F_17 ( V_293 | V_521 ,
L_316 ) ;
F_309 ( V_539 ) ;
}
F_291 () ;
}
static int F_310 ( struct V_88 * V_89 )
{
int V_56 ;
V_56 = V_479 ( NULL ) ;
if ( V_56 < 0 ) {
F_83 ( V_89 , L_317 ) ;
} else {
F_83 ( V_89 , L_318 , V_56 ) ;
F_83 ( V_89 , L_319 ) ;
F_83 ( V_89 , L_320 ,
V_516 ) ;
}
return 0 ;
}
static int F_311 ( char * V_125 )
{
int V_56 ;
int V_70 ;
char * V_158 ;
V_56 = V_479 ( NULL ) ;
if ( V_56 < 0 )
return V_56 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( F_85 ( V_158 , L_321 ) == 0 ) {
if ( V_56 < V_516 )
V_56 ++ ;
} else if ( F_85 ( V_158 , L_322 ) == 0 ) {
if ( V_56 > 0 )
V_56 -- ;
} else if ( sscanf ( V_158 , L_323 , & V_56 ) == 1 &&
V_56 >= 0 && V_56 <= V_516 ) {
} else
return - V_92 ;
}
F_81 ( L_324 ,
L_325 , V_56 ) ;
V_70 = V_477 ( V_56 ) ;
if ( ! V_70 && V_539 )
F_298 ( V_539 ,
V_565 ) ;
return ( V_70 == - V_566 ) ? - V_284 : V_70 ;
}
static void F_312 ( void )
{
T_6 V_517 = 0 ;
T_6 V_518 ;
T_6 V_567 ;
if ( V_568 != V_569 )
return;
if ( ! V_570 )
return;
F_17 ( V_571 ,
L_326 ) ;
if ( V_185 . V_572 )
V_567 = V_573 ;
else
V_567 = V_573 | V_574 ;
if ( F_156 ( & V_575 ) < 0 )
return;
if ( F_140 ( ! F_11 ( V_576 , & V_517 ) ) )
goto V_524;
V_517 &= V_567 ;
V_518 = F_131 ( V_247 ) ;
if ( V_517 != ( V_518 & V_567 ) ) {
V_518 &= ~ V_567 ;
V_518 |= V_517 ;
F_292 ( V_518 , V_247 ) ;
F_20 ( V_571 ,
L_327 ,
( unsigned int ) V_517 , ( unsigned int ) V_518 ) ;
} else {
F_17 ( V_571 ,
L_328 ,
( unsigned int ) V_517 , ( unsigned int ) V_518 ) ;
}
V_524:
F_117 ( & V_575 ) ;
}
static int F_313 ( T_6 * V_30 )
{
T_6 V_117 ;
if ( ! F_11 ( V_576 , & V_117 ) )
return - V_50 ;
* V_30 = V_117 ;
F_20 ( V_571 , L_329 , V_117 ) ;
return 0 ;
}
static int F_314 ( T_6 * V_30 )
{
return F_313 ( V_30 ) ;
}
static int F_315 ( const T_6 V_30 )
{
if ( ! F_13 ( V_576 , V_30 ) )
return - V_50 ;
F_20 ( V_571 , L_330 , V_30 ) ;
return 0 ;
}
static int F_316 ( const T_6 V_30 )
{
return F_315 ( V_30 ) ;
}
static int F_317 ( const bool V_251 )
{
int V_70 ;
T_6 V_117 , V_219 ;
if ( F_156 ( & V_575 ) < 0 )
return - V_566 ;
V_70 = F_313 ( & V_117 ) ;
if ( V_70 )
goto V_524;
V_219 = ( V_251 ) ? V_117 | V_573 :
V_117 & ~ V_573 ;
if ( V_219 != V_117 ) {
V_70 = F_315 ( V_219 ) ;
if ( ! V_70 )
V_70 = 1 ;
}
V_524:
F_117 ( & V_575 ) ;
return V_70 ;
}
static int F_318 ( const bool V_251 )
{
F_20 ( V_571 , L_331 ,
( V_251 ) ? L_1 : L_40 ) ;
return F_317 ( V_251 ) ;
}
static int F_319 ( const bool V_251 )
{
int V_70 ;
F_20 ( V_571 , L_332 ,
( V_251 ) ? L_1 : L_40 ) ;
V_70 = F_317 ( V_251 ) ;
return ( V_70 < 0 ) ? V_70 : 0 ;
}
static int F_320 ( const T_6 V_577 )
{
int V_70 ;
T_6 V_117 , V_219 ;
if ( V_577 > V_578 )
return - V_92 ;
if ( F_156 ( & V_575 ) < 0 )
return - V_566 ;
V_70 = F_313 ( & V_117 ) ;
if ( V_70 )
goto V_524;
V_219 = ( V_117 & ~ V_574 ) | V_577 ;
if ( V_219 != V_117 ) {
V_70 = F_315 ( V_219 ) ;
if ( ! V_70 )
V_70 = 1 ;
}
V_524:
F_117 ( & V_575 ) ;
return V_70 ;
}
static int F_321 ( const T_6 V_577 )
{
F_20 ( V_571 ,
L_333 , V_577 ) ;
return F_320 ( V_577 ) ;
}
static void F_322 ( void )
{
struct V_579 * V_220 ;
if ( V_580 && V_580 -> V_581 ) {
V_220 = V_580 -> V_581 ;
if ( V_220 -> V_582 )
F_323 ( V_580 ,
V_583 ,
V_220 -> V_582 ) ;
if ( V_220 -> V_584 )
F_323 ( V_580 ,
V_583 ,
V_220 -> V_584 ) ;
}
}
static int F_324 ( struct V_585 * V_586 ,
struct V_587 * V_588 )
{
V_588 -> type = V_589 ;
V_588 -> V_35 = 1 ;
V_588 -> V_38 . integer . V_590 = 0 ;
V_588 -> V_38 . integer . V_126 = V_578 ;
return 0 ;
}
static int F_325 ( struct V_585 * V_586 ,
struct V_591 * V_592 )
{
T_6 V_117 ;
int V_70 ;
V_70 = F_314 ( & V_117 ) ;
if ( V_70 < 0 )
return V_70 ;
V_592 -> V_38 . integer . V_38 [ 0 ] = V_117 & V_574 ;
return 0 ;
}
static int F_326 ( struct V_585 * V_586 ,
struct V_591 * V_592 )
{
F_81 ( L_334 , L_335 ,
V_592 -> V_38 . integer . V_38 [ 0 ] ) ;
return F_321 ( V_592 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static int F_327 ( struct V_585 * V_586 ,
struct V_591 * V_592 )
{
T_6 V_117 ;
int V_70 ;
V_70 = F_314 ( & V_117 ) ;
if ( V_70 < 0 )
return V_70 ;
V_592 -> V_38 . integer . V_38 [ 0 ] =
( V_117 & V_573 ) ? 0 : 1 ;
return 0 ;
}
static int F_328 ( struct V_585 * V_586 ,
struct V_591 * V_592 )
{
F_81 ( L_334 , L_336 ,
V_592 -> V_38 . integer . V_38 [ 0 ] ?
L_40 : L_1 ) ;
return F_318 ( ! V_592 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static void F_329 ( void )
{
F_312 () ;
}
static void F_330 ( void )
{
F_322 () ;
}
static void F_331 ( void )
{
F_312 () ;
}
static void F_332 ( void )
{
if ( V_580 ) {
F_333 ( V_580 ) ;
V_580 = NULL ;
}
F_312 () ;
}
static int T_1 F_334 ( void )
{
struct V_593 * V_594 ;
struct V_579 * V_63 ;
struct V_585 * V_595 ;
struct V_585 * V_596 ;
int V_70 ;
V_70 = F_335 ( V_597 , V_598 , V_599 ,
sizeof( struct V_579 ) , & V_594 ) ;
if ( V_70 < 0 || ! V_594 ) {
F_8 ( L_337 , V_70 ) ;
return 1 ;
}
F_23 ( ! V_594 -> V_581 ) ;
V_63 = V_594 -> V_581 ;
V_63 -> V_594 = V_594 ;
F_336 ( V_594 -> V_79 , V_600 ,
sizeof( V_594 -> V_79 ) ) ;
F_336 ( V_594 -> V_601 , V_602 ,
sizeof( V_594 -> V_601 ) ) ;
snprintf ( V_594 -> V_603 , sizeof( V_594 -> V_603 ) , L_338 ,
( V_7 . V_604 ) ?
V_7 . V_604 : L_339 ) ;
snprintf ( V_594 -> V_605 , sizeof( V_594 -> V_605 ) ,
L_340 , V_594 -> V_601 , V_576 ,
( V_7 . V_604 ) ?
V_7 . V_604 : L_341 ) ;
if ( V_570 ) {
V_606 . V_607 = F_326 ;
V_606 . V_608 =
V_609 ;
V_610 . V_607 = F_328 ;
V_610 . V_608 =
V_609 ;
}
if ( ! V_185 . V_572 ) {
V_595 = F_337 ( & V_606 , NULL ) ;
V_70 = F_338 ( V_594 , V_595 ) ;
if ( V_70 < 0 ) {
F_8 ( L_342 ,
V_70 ) ;
goto V_331;
}
V_63 -> V_584 = & V_595 -> V_143 ;
}
V_596 = F_337 ( & V_610 , NULL ) ;
V_70 = F_338 ( V_594 , V_596 ) ;
if ( V_70 < 0 ) {
F_8 ( L_343 , V_70 ) ;
goto V_331;
}
V_63 -> V_582 = & V_596 -> V_143 ;
F_339 ( V_594 , & V_153 -> V_105 ) ;
V_70 = F_340 ( V_594 ) ;
if ( V_70 < 0 ) {
F_8 ( L_344 , V_70 ) ;
goto V_331;
}
V_580 = V_594 ;
return 0 ;
V_331:
F_333 ( V_594 ) ;
return 1 ;
}
static int T_1 F_341 ( struct V_296 * V_297 )
{
unsigned long V_13 ;
int V_70 ;
F_17 ( V_55 , L_345 ) ;
F_183 ( & V_575 ) ;
if ( V_568 > V_611 )
return - V_92 ;
if ( V_568 == V_612 ) {
F_8 ( L_346
L_295 , V_332 ) ;
return 1 ;
}
if ( V_613 >= V_614 )
return - V_92 ;
if ( ! V_615 ) {
F_17 ( V_55 | V_571 ,
L_347
L_348 ) ;
return 1 ;
}
V_13 = F_4 ( V_616 ,
F_99 ( V_616 ) ) ;
switch ( V_613 ) {
case V_617 :
if ( V_13 & V_618 )
V_185 . V_572 = 1 ;
else if ( V_13 & V_619 )
V_185 . V_572 = 0 ;
else
return 1 ;
break;
case V_620 :
V_185 . V_572 = 0 ;
break;
case V_621 :
V_185 . V_572 = 1 ;
break;
default:
return 1 ;
}
if ( V_613 != V_617 )
F_20 ( V_55 | V_571 ,
L_349 ,
V_613 ) ;
if ( V_568 == V_622 ||
V_568 == V_611 ) {
V_568 = V_569 ;
F_20 ( V_55 | V_571 ,
L_350 ,
V_568 ) ;
} else {
F_20 ( V_55 | V_571 ,
L_351 ,
V_568 ) ;
}
F_17 ( V_55 | V_571 ,
L_352 ,
F_1 ( ! V_185 . V_572 ) ) ;
V_70 = F_334 () ;
if ( V_70 ) {
F_8 ( L_353 ) ;
return V_70 ;
}
F_75 ( L_354 ,
( V_570 ) ?
L_355 :
L_356 ) ;
F_17 ( V_55 | V_571 ,
L_357 ) ;
F_113 ( V_194
| V_623
| V_624
| V_625 ) ;
return 0 ;
}
static int F_342 ( struct V_88 * V_89 )
{
T_6 V_30 ;
if ( F_314 ( & V_30 ) < 0 ) {
F_83 ( V_89 , L_317 ) ;
} else {
if ( V_185 . V_572 )
F_83 ( V_89 , L_358 ) ;
else
F_83 ( V_89 , L_318 ,
V_30 & V_574 ) ;
F_83 ( V_89 , L_359 ,
F_254 ( V_30 , V_626 ) ) ;
if ( V_570 ) {
F_83 ( V_89 , L_360 ) ;
if ( ! V_185 . V_572 ) {
F_83 ( V_89 ,
L_319 ) ;
F_83 ( V_89 ,
L_361
L_362 ,
V_578 ) ;
}
}
}
return 0 ;
}
static int F_343 ( char * V_125 )
{
T_6 V_117 ;
T_6 V_627 , V_628 ;
int V_629 ;
char * V_158 ;
int V_70 ;
if ( ! V_570 && V_66 != V_282 ) {
if ( F_140 ( ! V_199 . V_630 ) ) {
V_199 . V_630 = 1 ;
F_31 ( L_363
L_364 ) ;
F_31 ( L_365
L_366 ) ;
}
return - V_157 ;
}
V_70 = F_314 ( & V_117 ) ;
if ( V_70 < 0 )
return V_70 ;
V_627 = V_117 & V_574 ;
V_628 = V_117 & V_573 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( ! V_185 . V_572 ) {
if ( F_85 ( V_158 , L_321 ) == 0 ) {
if ( V_628 )
V_628 = 0 ;
else if ( V_627 < V_578 )
V_627 ++ ;
continue;
} else if ( F_85 ( V_158 , L_322 ) == 0 ) {
if ( V_628 )
V_628 = 0 ;
else if ( V_627 > 0 )
V_627 -- ;
continue;
} else if ( sscanf ( V_158 , L_367 , & V_629 ) == 1 &&
V_629 >= 0 && V_629 <= V_578 ) {
V_627 = V_629 ;
continue;
}
}
if ( F_85 ( V_158 , L_368 ) == 0 )
V_628 = V_573 ;
else if ( F_85 ( V_158 , L_369 ) == 0 )
V_628 = 0 ;
else
return - V_92 ;
}
if ( V_185 . V_572 ) {
F_81 ( L_370 , L_336 ,
V_628 ? L_1 : L_40 ) ;
V_70 = F_319 ( ! ! V_628 ) ;
} else {
F_81 ( L_370 ,
L_371 ,
V_628 ? L_1 : L_40 , V_627 ) ;
V_70 = F_316 ( V_628 | V_627 ) ;
}
F_322 () ;
return ( V_70 == - V_566 ) ? - V_284 : V_70 ;
}
static void inline F_322 ( void )
{
}
static int T_1 F_341 ( struct V_296 * V_297 )
{
F_75 ( L_372 ) ;
return 1 ;
}
static void F_344 ( void )
{
if ( V_631 == 0x07 ) {
F_31 ( L_373
L_374 ) ;
V_185 . V_632 = 1 ;
}
}
static void F_345 ( T_6 * V_633 )
{
if ( F_140 ( V_185 . V_632 ) ) {
if ( * V_633 != V_631 ) {
V_185 . V_632 = 0 ;
} else {
* V_633 = V_634 ;
}
}
}
static bool F_346 ( void )
{
if ( V_185 . V_635 ) {
T_6 V_636 ;
if ( F_12 ( V_637 , & V_636 ) < 0 )
return false ;
V_636 &= 0xFEU ;
if ( F_14 ( V_637 , V_636 ) < 0 )
return false ;
}
return true ;
}
static bool F_347 ( void )
{
T_6 V_636 ;
if ( ! V_185 . V_635 )
return false ;
if ( F_12 ( V_637 , & V_636 ) < 0 )
return false ;
V_636 |= 0x01U ;
if ( F_14 ( V_637 , V_636 ) < 0 )
return false ;
return true ;
}
static void F_348 ( T_6 V_30 )
{
if ( ( V_30 &
( V_634 | V_638 ) ) == 0 ) {
if ( V_30 > 7 )
V_639 = 7 ;
else
V_639 = V_30 ;
}
}
static int F_349 ( T_6 * V_30 )
{
T_6 V_117 ;
switch ( V_640 ) {
case V_641 : {
int V_17 ;
if ( F_140 ( ! F_7 ( V_642 , & V_17 , NULL , L_62 ) ) )
return - V_50 ;
if ( F_138 ( V_30 ) )
* V_30 = V_17 & 0x07 ;
break;
}
case V_643 :
if ( F_140 ( ! F_11 ( V_644 , & V_117 ) ) )
return - V_50 ;
if ( F_138 ( V_30 ) ) {
* V_30 = V_117 ;
F_345 ( V_30 ) ;
}
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_350 ( T_6 * V_30 )
{
int V_70 ;
T_6 V_117 ;
if ( F_156 ( & V_645 ) )
return - V_284 ;
V_70 = F_349 ( & V_117 ) ;
if ( ! V_70 )
F_348 ( V_117 ) ;
F_117 ( & V_645 ) ;
if ( V_30 )
* V_30 = V_117 ;
return V_70 ;
}
static int F_351 ( unsigned int * V_646 )
{
T_6 V_647 , V_648 ;
switch ( V_640 ) {
case V_643 :
if ( F_140 ( ! F_346 () ) )
return - V_50 ;
if ( F_140 ( ! F_11 ( V_649 , & V_648 ) ||
! F_11 ( V_649 + 1 , & V_647 ) ) )
return - V_50 ;
if ( F_138 ( V_646 ) )
* V_646 = ( V_647 << 8 ) | V_648 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_352 ( unsigned int * V_646 )
{
T_6 V_647 , V_648 ;
bool V_70 ;
switch ( V_640 ) {
case V_643 :
if ( F_140 ( ! F_347 () ) )
return - V_50 ;
V_70 = ! F_11 ( V_649 , & V_648 ) ||
! F_11 ( V_649 + 1 , & V_647 ) ;
F_346 () ;
if ( V_70 )
return - V_50 ;
if ( F_138 ( V_646 ) )
* V_646 = ( V_647 << 8 ) | V_648 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_353 ( int V_56 )
{
if ( ! V_650 )
return - V_157 ;
switch ( V_651 ) {
case V_652 :
if ( V_56 >= 0 && V_56 <= 7 ) {
if ( ! F_7 ( V_653 , NULL , NULL , L_9 , V_56 ) )
return - V_50 ;
} else
return - V_92 ;
break;
case V_654 :
case V_655 :
if ( ! ( V_56 & V_634 ) &&
! ( V_56 & V_638 ) &&
( ( V_56 < 0 ) || ( V_56 > 7 ) ) )
return - V_92 ;
if ( V_56 & V_638 )
V_56 |= 7 ;
else if ( V_56 & V_634 )
V_56 |= 4 ;
if ( ! F_13 ( V_644 , V_56 ) )
return - V_50 ;
else
V_185 . V_632 = 0 ;
break;
default:
return - V_49 ;
}
F_17 ( V_656 ,
L_375 , V_56 ) ;
return 0 ;
}
static int F_354 ( int V_56 )
{
int V_70 ;
if ( ! V_650 )
return - V_157 ;
if ( F_156 ( & V_645 ) )
return - V_284 ;
if ( V_56 == V_657 )
V_56 = V_639 ;
V_70 = F_353 ( V_56 ) ;
if ( ! V_70 )
F_348 ( V_56 ) ;
F_117 ( & V_645 ) ;
return V_70 ;
}
static int F_355 ( void )
{
T_6 V_117 ;
int V_70 ;
if ( ! V_650 )
return - V_157 ;
if ( F_156 ( & V_645 ) )
return - V_284 ;
switch ( V_651 ) {
case V_654 :
case V_655 :
V_70 = F_349 ( & V_117 ) ;
if ( V_70 < 0 )
break;
if ( V_117 != 7 ) {
V_117 &= 0x07 ;
V_117 |= V_634 | 4 ;
}
if ( ! F_13 ( V_644 , V_117 ) )
V_70 = - V_50 ;
else {
V_185 . V_632 = 0 ;
V_70 = 0 ;
}
break;
case V_652 :
V_70 = F_349 ( & V_117 ) ;
if ( V_70 < 0 )
break;
V_117 &= 0x07 ;
V_117 |= 4 ;
if ( ! F_7 ( V_653 , NULL , NULL , L_9 , V_117 ) )
V_70 = - V_50 ;
else
V_70 = 0 ;
break;
default:
V_70 = - V_49 ;
}
F_117 ( & V_645 ) ;
if ( ! V_70 )
F_17 ( V_656 ,
L_375 ,
V_117 ) ;
return V_70 ;
}
static int F_356 ( void )
{
int V_70 ;
if ( ! V_650 )
return - V_157 ;
if ( F_156 ( & V_645 ) )
return - V_284 ;
V_70 = 0 ;
switch ( V_651 ) {
case V_654 :
case V_655 :
if ( ! F_13 ( V_644 , 0x00 ) )
V_70 = - V_50 ;
else {
V_639 = 0 ;
V_185 . V_632 = 0 ;
}
break;
case V_652 :
if ( ! F_7 ( V_653 , NULL , NULL , L_9 , 0x00 ) )
V_70 = - V_50 ;
else
V_639 = 0 ;
break;
default:
V_70 = - V_49 ;
}
if ( ! V_70 )
F_17 ( V_656 ,
L_376 ) ;
F_117 ( & V_645 ) ;
return V_70 ;
}
static int F_357 ( int V_646 )
{
int V_70 ;
if ( ! V_650 )
return - V_157 ;
if ( F_156 ( & V_645 ) )
return - V_284 ;
V_70 = 0 ;
switch ( V_651 ) {
case V_654 :
if ( V_646 >= 0 && V_646 <= 65535 ) {
if ( ! F_7 ( V_658 , NULL , NULL , L_377 ,
V_646 , V_646 , V_646 ) )
V_70 = - V_50 ;
} else
V_70 = - V_92 ;
break;
default:
V_70 = - V_49 ;
}
F_117 ( & V_645 ) ;
return V_70 ;
}
static void F_358 ( void )
{
if ( V_651 == V_659 )
return;
if ( V_660 > 0 &&
V_66 != V_198 )
F_359 ( V_446 , & V_661 ,
F_360 ( V_660 * 1000 ) ) ;
else
F_361 ( & V_661 ) ;
}
static void F_362 ( struct V_435 * V_662 )
{
int V_70 ;
if ( V_66 != V_67 )
return;
F_31 ( L_378 ) ;
V_70 = F_355 () ;
if ( V_70 < 0 ) {
F_8 ( L_379
L_380 , - V_70 ) ;
F_358 () ;
}
}
static T_8 F_363 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 , V_663 ;
T_6 V_30 ;
V_17 = F_350 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 & V_638 ) {
V_663 = 0 ;
} else if ( V_30 & V_634 ) {
V_663 = 2 ;
} else
V_663 = 1 ;
return snprintf ( V_125 , V_100 , L_42 , V_663 ) ;
}
static T_8 F_364 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
int V_17 , V_56 ;
if ( F_56 ( V_125 , 2 , & V_156 ) )
return - V_92 ;
F_81 ( L_381 ,
L_382 , V_156 ) ;
switch ( V_156 ) {
case 0 :
V_56 = V_638 ;
break;
case 1 :
V_56 = V_657 ;
break;
case 2 :
V_56 = V_634 ;
break;
case 3 :
return - V_423 ;
default:
return - V_92 ;
}
V_17 = F_354 ( V_56 ) ;
if ( V_17 == - V_49 )
return - V_92 ;
else if ( V_17 < 0 )
return V_17 ;
F_358 () ;
return V_35 ;
}
static T_8 F_365 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 ;
T_6 V_30 ;
V_17 = F_350 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_30 &
( V_634 | V_638 ) ) != 0 )
V_30 = V_639 ;
if ( V_30 > 7 )
V_30 = 7 ;
return snprintf ( V_125 , V_100 , L_383 , ( V_30 * 255 ) / 7 ) ;
}
static T_8 F_366 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_117 ;
int V_70 ;
T_6 V_30 , V_664 ;
if ( F_56 ( V_125 , 255 , & V_117 ) )
return - V_92 ;
F_81 ( L_384 ,
L_385 , V_117 ) ;
V_664 = ( V_117 >> 5 ) & 0x07 ;
if ( F_156 ( & V_645 ) )
return - V_284 ;
V_70 = F_349 ( & V_30 ) ;
if ( ! V_70 && ( V_30 &
( V_634 | V_638 ) ) == 0 ) {
V_70 = F_353 ( V_664 ) ;
if ( V_70 == - V_49 )
V_70 = - V_92 ;
else if ( ! V_70 ) {
F_348 ( V_664 ) ;
F_358 () ;
}
}
F_117 ( & V_645 ) ;
return ( V_70 ) ? V_70 : V_35 ;
}
static T_8 F_367 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 ;
unsigned int V_646 ;
V_17 = F_351 ( & V_646 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_125 , V_100 , L_383 , V_646 ) ;
}
static T_8 F_368 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 ;
unsigned int V_646 ;
V_17 = F_352 ( & V_646 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_125 , V_100 , L_383 , V_646 ) ;
}
static T_8 F_369 ( struct V_160 * V_161 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_383 , V_660 ) ;
}
static T_8 F_370 ( struct V_160 * V_161 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
if ( F_56 ( V_125 , 120 , & V_156 ) )
return - V_92 ;
if ( ! V_650 )
return - V_157 ;
V_660 = V_156 ;
F_358 () ;
F_81 ( L_386 , L_94 , V_156 ) ;
return V_35 ;
}
static int T_1 F_371 ( struct V_296 * V_297 )
{
int V_70 ;
unsigned long V_13 ;
F_17 ( V_55 | V_656 ,
L_387 ) ;
F_183 ( & V_645 ) ;
V_640 = V_665 ;
V_651 = V_659 ;
V_666 = 0 ;
V_660 = 0 ;
V_185 . V_632 = 0 ;
V_185 . V_635 = 0 ;
V_639 = 7 ;
if ( F_6 () ) {
F_182 ( V_667 ) ;
F_182 ( V_668 ) ;
F_182 ( V_669 ) ;
}
V_13 = F_4 ( V_670 ,
F_99 ( V_670 ) ) ;
if ( V_642 ) {
V_640 = V_641 ;
} else {
if ( F_138 ( F_11 ( V_644 ,
& V_631 ) ) ) {
V_640 = V_643 ;
if ( V_13 & V_671 )
F_344 () ;
if ( V_13 & V_672 ) {
V_185 . V_635 = 1 ;
F_20 ( V_55 | V_656 ,
L_388 ) ;
}
} else {
F_8 ( L_275
L_389 ) ;
return 1 ;
}
}
if ( V_653 ) {
V_651 = V_652 ;
V_666 |=
V_673 | V_674 ;
} else {
if ( ! V_642 ) {
if ( V_658 ) {
V_651 =
V_654 ;
V_666 |=
V_675 |
V_673 |
V_674 ;
} else {
V_651 = V_655 ;
V_666 |=
V_673 |
V_674 ;
}
}
}
F_17 ( V_55 | V_656 ,
L_390 ,
F_1 ( V_640 != V_665 ||
V_651 != V_659 ) ,
V_640 , V_651 ) ;
if ( ! V_650 ) {
V_651 = V_659 ;
V_666 = 0 ;
F_20 ( V_55 | V_656 ,
L_391 ) ;
}
if ( V_640 != V_665 )
F_350 ( NULL ) ;
if ( V_640 != V_665 ||
V_651 != V_659 ) {
if ( V_185 . V_635 ) {
V_676 [ F_99 ( V_676 ) - 2 ] =
& V_677 . V_121 ;
}
V_70 = F_213 ( & V_512 -> V_105 . V_124 ,
& V_678 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_100 ( & V_679 . V_79 ,
& V_680 ) ;
if ( V_70 < 0 ) {
F_54 ( & V_512 -> V_105 . V_124 ,
& V_678 ) ;
return V_70 ;
}
return 0 ;
} else
return 1 ;
}
static void F_372 ( void )
{
F_17 ( V_293 | V_656 ,
L_392 ) ;
F_54 ( & V_512 -> V_105 . V_124 , & V_678 ) ;
F_103 ( & V_679 . V_79 ,
& V_680 ) ;
F_361 ( & V_661 ) ;
F_252 ( V_446 ) ;
}
static void F_373 ( void )
{
int V_70 ;
if ( ! V_650 )
return;
V_681 = 0 ;
V_70 = F_350 ( & V_681 ) ;
if ( V_70 < 0 )
F_31 ( L_393
L_394 , V_70 ) ;
if ( V_185 . V_632 )
V_681 = 0 ;
}
static void F_374 ( void )
{
T_6 V_682 = 7 ;
bool V_683 = false ;
int V_70 ;
V_185 . V_632 = 0 ;
if ( ! V_650 ||
! V_681 ||
( F_350 ( & V_682 ) < 0 ) )
return;
switch ( V_651 ) {
case V_652 :
V_683 = ( V_681 > V_682 ) ;
break;
case V_654 :
case V_655 :
if ( V_681 != 7 &&
! ( V_681 & V_638 ) )
return;
else
V_683 = ! ( V_682 & V_638 ) &&
( V_682 != V_681 ) ;
break;
default:
return;
}
if ( V_683 ) {
F_31 ( L_395 ,
V_681 ) ;
V_70 = F_354 ( V_681 ) ;
if ( V_70 < 0 )
F_31 ( L_396 , V_70 ) ;
}
}
static int F_375 ( struct V_88 * V_89 )
{
int V_70 ;
T_6 V_30 ;
unsigned int V_646 = 0 ;
switch ( V_640 ) {
case V_641 :
V_70 = F_350 ( & V_30 ) ;
if ( V_70 < 0 )
return V_70 ;
F_83 ( V_89 , L_45
L_318 ,
( V_30 != 0 ) ? L_46 : L_47 , V_30 ) ;
break;
case V_643 :
V_70 = F_350 ( & V_30 ) ;
if ( V_70 < 0 )
return V_70 ;
F_83 ( V_89 , L_45 ,
( V_30 != 0 ) ? L_46 : L_47 ) ;
V_70 = F_351 ( & V_646 ) ;
if ( V_70 < 0 )
return V_70 ;
F_83 ( V_89 , L_397 , V_646 ) ;
if ( V_30 & V_638 )
F_83 ( V_89 , L_398 ) ;
else if ( V_30 & V_634 )
F_83 ( V_89 , L_399 ) ;
else
F_83 ( V_89 , L_318 , V_30 ) ;
break;
case V_665 :
default:
F_83 ( V_89 , L_44 ) ;
}
if ( V_666 & V_673 ) {
F_83 ( V_89 , L_361 ) ;
switch ( V_651 ) {
case V_652 :
F_83 ( V_89 , L_400 ) ;
break;
default:
F_83 ( V_89 , L_401
L_402 ) ;
break;
}
}
if ( V_666 & V_674 )
F_83 ( V_89 , L_48
L_403
L_404 ) ;
if ( V_666 & V_675 )
F_83 ( V_89 , L_405
L_406 ) ;
return 0 ;
}
static int F_376 ( const char * V_158 , int * V_70 )
{
int V_56 ;
if ( F_85 ( V_158 , L_407 ) == 0 )
V_56 = V_634 ;
else if ( ( F_85 ( V_158 , L_408 ) == 0 ) |
( F_85 ( V_158 , L_409 ) == 0 ) )
V_56 = V_638 ;
else if ( sscanf ( V_158 , L_323 , & V_56 ) != 1 )
return 0 ;
* V_70 = F_354 ( V_56 ) ;
if ( * V_70 == - V_49 )
F_8 ( L_410 ,
V_651 ) ;
else if ( ! * V_70 )
F_81 ( L_411 ,
L_325 , V_56 ) ;
return 1 ;
}
static int F_377 ( const char * V_158 , int * V_70 )
{
if ( F_85 ( V_158 , L_49 ) != 0 )
return 0 ;
* V_70 = F_355 () ;
if ( * V_70 == - V_49 )
F_8 ( L_412 ,
V_651 ) ;
else if ( ! * V_70 )
F_81 ( L_411 , L_413 ) ;
return 1 ;
}
static int F_378 ( const char * V_158 , int * V_70 )
{
if ( F_85 ( V_158 , L_50 ) != 0 )
return 0 ;
* V_70 = F_356 () ;
if ( * V_70 == - V_49 )
F_8 ( L_414 ,
V_651 ) ;
else if ( ! * V_70 )
F_81 ( L_411 , L_415 ) ;
return 1 ;
}
static int F_379 ( const char * V_158 , int * V_70 )
{
int V_646 ;
if ( sscanf ( V_158 , L_416 , & V_646 ) != 1 )
return 0 ;
* V_70 = F_357 ( V_646 ) ;
if ( * V_70 == - V_49 )
F_8 ( L_417 ,
V_651 ) ;
else if ( ! * V_70 )
F_81 ( L_411 ,
L_418 , V_646 ) ;
return 1 ;
}
static int F_380 ( const char * V_158 , int * V_70 )
{
int V_684 ;
if ( sscanf ( V_158 , L_419 , & V_684 ) != 1 )
return 0 ;
if ( V_684 < 0 || V_684 > 120 )
* V_70 = - V_92 ;
else {
V_660 = V_684 ;
F_81 ( L_411 ,
L_420 ,
V_684 ) ;
}
return 1 ;
}
static int F_381 ( char * V_125 )
{
char * V_158 ;
int V_70 = 0 ;
while ( ! V_70 && ( V_158 = F_45 ( & V_125 ) ) ) {
if ( ! ( ( V_666 & V_673 ) &&
F_376 ( V_158 , & V_70 ) ) &&
! ( ( V_666 & V_674 ) &&
( F_377 ( V_158 , & V_70 ) ||
F_378 ( V_158 , & V_70 ) ||
F_380 ( V_158 , & V_70 ) ) ) &&
! ( ( V_666 & V_675 ) &&
F_379 ( V_158 , & V_70 ) )
)
V_70 = - V_92 ;
else if ( ! V_70 )
F_358 () ;
}
return V_70 ;
}
static void F_382 ( const unsigned int V_685 )
{
if ( V_539 ) {
switch ( V_685 ) {
case V_686 :
case V_687 :
F_297 () ;
}
}
if ( V_580 ) {
switch ( V_685 ) {
case V_688 :
case V_689 :
case V_690 :
F_322 () ;
}
}
}
static void F_127 ( const unsigned int V_209 )
{
F_382 ( V_217 + V_209 ) ;
}
static T_8 F_383 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_421 , V_83 ) ;
}
static const char * T_1 F_1 ( int V_1 )
{
static char V_691 [] V_692 = L_422 ;
return ( V_1 ) ? & V_691 [ 4 ] : & V_691 [ 0 ] ;
}
static void F_384 ( struct V_64 * V_65 )
{
F_20 ( V_293 , L_423 , V_65 -> V_51 ) ;
F_385 ( & V_65 -> V_693 ) ;
if ( V_65 -> V_76 . V_77 ) {
F_20 ( V_293 ,
L_424 , V_65 -> V_51 ) ;
F_23 ( ! V_65 -> V_68 ) ;
F_386 ( * V_65 -> V_68 -> V_16 ,
V_65 -> V_68 -> type ,
F_25 ) ;
V_65 -> V_76 . V_77 = 0 ;
}
if ( V_65 -> V_76 . V_694 ) {
F_20 ( V_293 ,
L_425 , V_65 -> V_51 ) ;
F_387 ( V_65 -> V_51 , V_695 ) ;
V_65 -> V_76 . V_694 = 0 ;
}
if ( V_65 -> V_76 . V_87 ) {
F_20 ( V_293 ,
L_426 , V_65 -> V_51 ) ;
F_23 ( ! V_65 -> V_68 ) ;
F_388 ( V_65 -> V_68 -> V_79 ) ;
F_36 ( V_65 -> V_68 -> V_79 ) ;
V_65 -> V_68 -> V_79 = NULL ;
V_65 -> V_76 . V_87 = 0 ;
}
if ( V_65 -> V_76 . V_696 && V_65 -> exit ) {
V_65 -> exit () ;
V_65 -> V_76 . V_696 = 0 ;
}
F_20 ( V_55 , L_427 , V_65 -> V_51 ) ;
}
static int T_1 F_389 ( struct V_296 * V_297 )
{
int V_98 ;
struct V_64 * V_65 = V_297 -> V_63 ;
struct V_697 * V_698 ;
F_23 ( V_65 == NULL ) ;
F_390 ( & V_65 -> V_693 ) ;
if ( V_65 -> V_76 . V_699 && ! V_699 )
return 0 ;
F_20 ( V_55 ,
L_428 , V_65 -> V_51 ) ;
if ( V_297 -> V_700 ) {
V_98 = V_297 -> V_700 ( V_297 ) ;
if ( V_98 > 0 )
return 0 ;
if ( V_98 )
return V_98 ;
V_65 -> V_76 . V_696 = 1 ;
}
if ( V_65 -> V_68 ) {
if ( V_65 -> V_68 -> V_60 ) {
V_98 = F_33 ( V_65 ) ;
if ( V_98 )
goto V_701;
}
if ( V_65 -> V_68 -> V_69 ) {
V_98 = F_26 ( V_65 ) ;
if ( V_98 == - V_72 ) {
F_31 ( L_429 ,
V_65 -> V_51 ) ;
V_98 = 0 ;
goto V_701;
}
if ( V_98 < 0 )
goto V_701;
}
}
F_20 ( V_55 ,
L_430 , V_65 -> V_51 ) ;
if ( V_65 -> V_91 ) {
T_19 V_663 = V_297 -> V_702 ;
if ( ! V_663 )
V_663 = V_703 ;
if ( V_65 -> V_99 )
V_663 |= V_704 ;
V_698 = F_391 ( V_65 -> V_51 , V_663 , V_695 ,
& V_705 , V_65 ) ;
if ( ! V_698 ) {
F_8 ( L_431 , V_65 -> V_51 ) ;
V_98 = - V_72 ;
goto V_701;
}
V_65 -> V_76 . V_694 = 1 ;
}
F_392 ( & V_65 -> V_693 , & V_706 ) ;
return 0 ;
V_701:
F_20 ( V_55 ,
L_432 ,
V_65 -> V_51 , V_98 ) ;
F_384 ( V_65 ) ;
return ( V_98 < 0 ) ? V_98 : 0 ;
}
static bool T_2 T_1 F_393 ( const char V_37 )
{
return ( V_37 >= '0' && V_37 <= '9' ) || ( V_37 >= 'A' && V_37 <= 'Z' ) ;
}
static bool T_2 T_1 F_394 ( const char * const V_117 ,
const char V_156 )
{
return V_117 && strlen ( V_117 ) >= 8 &&
F_393 ( V_117 [ 0 ] ) &&
F_393 ( V_117 [ 1 ] ) &&
V_117 [ 2 ] == V_156 &&
( V_117 [ 3 ] == 'T' || V_117 [ 3 ] == 'N' ) &&
F_393 ( V_117 [ 4 ] ) &&
F_393 ( V_117 [ 5 ] ) ;
}
static int T_20 T_1 F_395 (
struct V_707 * V_708 )
{
const struct V_709 * V_105 = NULL ;
char V_710 [ 18 ] ;
char const * V_117 ;
if ( ! V_708 )
return - V_92 ;
memset ( V_708 , 0 , sizeof( * V_708 ) ) ;
if ( F_396 ( L_433 ) )
V_708 -> V_6 = V_15 ;
else if ( F_396 ( L_434 ) )
V_708 -> V_6 = V_14 ;
else
return 0 ;
V_117 = F_397 ( V_711 ) ;
V_708 -> V_712 = F_398 ( V_117 , V_81 ) ;
if ( V_117 && ! V_708 -> V_712 )
return - V_82 ;
if ( ! ( F_394 ( V_708 -> V_712 , 'E' ) ||
F_394 ( V_708 -> V_712 , 'C' ) ) )
return 0 ;
V_708 -> V_10 = V_708 -> V_712 [ 0 ]
| ( V_708 -> V_712 [ 1 ] << 8 ) ;
V_708 -> V_183 = ( V_708 -> V_712 [ 4 ] << 8 )
| V_708 -> V_712 [ 5 ] ;
while ( ( V_105 = F_399 ( V_713 , NULL , V_105 ) ) ) {
if ( sscanf ( V_105 -> V_51 ,
L_435 ,
V_710 ) == 1 ) {
V_710 [ sizeof( V_710 ) - 1 ] = 0 ;
V_710 [ strcspn ( V_710 , L_436 ) ] = 0 ;
V_708 -> V_604 = F_398 ( V_710 , V_81 ) ;
if ( ! V_708 -> V_604 )
return - V_82 ;
if ( F_394 ( V_710 , 'H' ) ) {
V_708 -> V_12 = V_710 [ 0 ]
| ( V_710 [ 1 ] << 8 ) ;
V_708 -> V_184 = ( V_710 [ 4 ] << 8 )
| V_710 [ 5 ] ;
} else {
F_31 ( L_437
L_438 ,
V_710 ) ;
F_31 ( L_107 ,
V_332 ) ;
}
break;
}
}
V_117 = F_397 ( V_714 ) ;
if ( V_117 && ! ( F_400 ( V_117 , L_439 , 8 ) && F_400 ( V_117 , L_440 , 6 ) ) ) {
V_708 -> V_715 = F_398 ( V_117 , V_81 ) ;
if ( ! V_708 -> V_715 )
return - V_82 ;
} else {
V_117 = F_397 ( V_716 ) ;
if ( V_117 && ! ( F_400 ( V_117 , L_440 , 6 ) ) ) {
V_708 -> V_715 = F_398 ( V_117 , V_81 ) ;
if ( ! V_708 -> V_715 )
return - V_82 ;
}
}
V_117 = F_397 ( V_717 ) ;
V_708 -> V_718 = F_398 ( V_117 , V_81 ) ;
if ( V_117 && ! V_708 -> V_718 )
return - V_82 ;
return 0 ;
}
static int T_1 F_401 ( void )
{
int V_719 ;
if ( V_720 )
return - V_72 ;
if ( ! F_6 () && ! F_5 () )
return - V_72 ;
V_719 = ( V_7 . V_715 != NULL ) ||
( V_7 . V_12 != 0 ) ||
F_106 () ;
F_22 ( L_441 , V_721 , & V_427 ) ;
if ( ! V_427 ) {
if ( V_719 )
F_8 ( L_442 ) ;
return - V_72 ;
}
if ( ! V_719 && ! V_722 )
return - V_72 ;
return 0 ;
}
static void T_1 F_402 ( void )
{
F_75 ( L_55 , V_164 , V_165 ) ;
F_75 ( L_421 , V_723 ) ;
F_75 ( L_443 ,
( V_7 . V_712 ) ?
V_7 . V_712 : L_341 ,
( V_7 . V_604 ) ?
V_7 . V_604 : L_341 ) ;
F_23 ( ! V_7 . V_6 ) ;
if ( V_7 . V_715 )
F_75 ( L_444 ,
( V_7 . V_6 == V_15 ) ?
L_433 : ( ( V_7 . V_6 ==
V_14 ) ?
L_440 : L_445 ) ,
V_7 . V_715 ,
( V_7 . V_718 ) ?
V_7 . V_718 : L_341 ) ;
}
static int T_1 F_403 ( const char * V_636 , struct V_724 * V_725 )
{
unsigned int V_42 ;
struct V_64 * V_65 ;
if ( ! V_725 || ! V_725 -> V_51 || ! V_636 )
return - V_92 ;
for ( V_42 = 0 ; V_42 < F_99 ( V_726 ) ; V_42 ++ ) {
V_65 = V_726 [ V_42 ] . V_63 ;
F_404 ( V_65 == NULL ) ;
if ( ! V_65 || ! V_65 -> V_51 )
continue;
if ( strcmp ( V_65 -> V_51 , V_725 -> V_51 ) == 0 && V_65 -> V_99 ) {
if ( strlen ( V_636 ) > sizeof( V_726 [ V_42 ] . V_727 ) - 2 )
return - V_728 ;
strcpy ( V_726 [ V_42 ] . V_727 , V_636 ) ;
strcat ( V_726 [ V_42 ] . V_727 , L_26 ) ;
return 0 ;
}
}
return - V_92 ;
}
static void F_405 ( void )
{
struct V_64 * V_65 , * V_106 ;
V_66 = V_198 ;
F_406 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
F_384 ( V_65 ) ;
}
F_20 ( V_55 , L_446 ) ;
if ( V_207 ) {
if ( V_185 . V_729 )
F_407 ( V_207 ) ;
else
F_408 ( V_207 ) ;
F_36 ( V_211 ) ;
}
if ( V_730 )
F_409 ( V_730 ) ;
if ( V_185 . V_731 )
F_260 ( & V_512 -> V_105 ,
& V_732 ) ;
if ( V_512 )
F_410 ( V_512 ) ;
if ( V_153 )
F_410 ( V_153 ) ;
if ( V_185 . V_733 )
F_102 ( & V_679 . V_79 ) ;
if ( V_185 . V_734 )
F_102 ( & V_735 . V_79 ) ;
if ( V_185 . V_736 )
F_411 ( & V_679 ) ;
if ( V_185 . V_737 )
F_411 ( & V_735 ) ;
if ( V_695 )
F_387 ( V_738 , V_739 ) ;
if ( V_446 )
F_412 ( V_446 ) ;
F_36 ( V_7 . V_712 ) ;
F_36 ( V_7 . V_604 ) ;
F_36 ( V_7 . V_715 ) ;
F_36 ( V_7 . V_718 ) ;
}
static int T_1 F_413 ( void )
{
int V_98 , V_42 ;
V_66 = V_282 ;
if ( V_215 > 2 )
return - V_92 ;
V_98 = F_395 ( & V_7 ) ;
if ( V_98 ) {
F_8 ( L_447 , V_98 ) ;
F_405 () ;
return V_98 ;
}
V_98 = F_401 () ;
if ( V_98 ) {
F_405 () ;
return V_98 ;
}
F_402 () ;
F_105 () ;
F_182 ( V_740 ) ;
F_182 ( V_741 ) ;
V_446 = F_414 ( V_742 ) ;
if ( ! V_446 ) {
F_405 () ;
return - V_82 ;
}
V_695 = F_415 ( V_738 , V_739 ) ;
if ( ! V_695 ) {
F_8 ( L_448 V_738 L_272 ) ;
F_405 () ;
return - V_72 ;
}
V_98 = F_416 ( & V_735 ) ;
if ( V_98 ) {
F_8 ( L_449 ) ;
F_405 () ;
return V_98 ;
}
V_185 . V_737 = 1 ;
V_98 = F_416 ( & V_679 ) ;
if ( V_98 ) {
F_8 ( L_450 ) ;
F_405 () ;
return V_98 ;
}
V_185 . V_736 = 1 ;
V_98 = F_98 ( & V_735 . V_79 ) ;
if ( ! V_98 ) {
V_185 . V_734 = 1 ;
V_98 = F_98 (
& V_679 . V_79 ) ;
}
if ( V_98 ) {
F_8 ( L_451 ) ;
F_405 () ;
return V_98 ;
}
V_185 . V_733 = 1 ;
V_153 = F_417 ( V_743 , - 1 ,
NULL , 0 ) ;
if ( F_146 ( V_153 ) ) {
V_98 = F_304 ( V_153 ) ;
V_153 = NULL ;
F_8 ( L_452 ) ;
F_405 () ;
return V_98 ;
}
V_512 = F_417 (
V_744 ,
- 1 , NULL , 0 ) ;
if ( F_146 ( V_512 ) ) {
V_98 = F_304 ( V_512 ) ;
V_512 = NULL ;
F_8 ( L_453 ) ;
F_405 () ;
return V_98 ;
}
V_98 = F_258 ( & V_512 -> V_105 ,
& V_732 ) ;
if ( V_98 ) {
F_8 ( L_454 ) ;
F_405 () ;
return V_98 ;
}
V_185 . V_731 = 1 ;
V_730 = F_418 ( & V_512 -> V_105 ) ;
if ( F_146 ( V_730 ) ) {
V_98 = F_304 ( V_730 ) ;
V_730 = NULL ;
F_8 ( L_455 ) ;
F_405 () ;
return V_98 ;
}
F_183 ( & V_206 ) ;
V_207 = F_419 () ;
if ( ! V_207 ) {
F_8 ( L_456 ) ;
F_405 () ;
return - V_82 ;
} else {
V_207 -> V_51 = L_457 ;
V_207 -> V_745 = V_743 L_458 ;
V_207 -> V_143 . V_746 = V_747 ;
V_207 -> V_143 . V_6 = V_7 . V_6 ;
V_207 -> V_143 . V_748 = V_749 ;
V_207 -> V_143 . V_750 = V_751 ;
V_207 -> V_105 . V_52 = & V_153 -> V_105 ;
}
F_301 () ;
for ( V_42 = 0 ; V_42 < F_99 ( V_726 ) ; V_42 ++ ) {
V_98 = F_389 ( & V_726 [ V_42 ] ) ;
if ( V_98 >= 0 && * V_726 [ V_42 ] . V_727 )
V_98 = V_726 [ V_42 ] . V_63 -> V_99 ( V_726 [ V_42 ] . V_727 ) ;
if ( V_98 < 0 ) {
F_405 () ;
return V_98 ;
}
}
V_66 = V_67 ;
V_98 = F_420 ( V_207 ) ;
if ( V_98 < 0 ) {
F_8 ( L_459 ) ;
F_405 () ;
return V_98 ;
} else {
V_185 . V_729 = 1 ;
}
return 0 ;
}
