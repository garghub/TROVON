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
}
static void F_129 ( struct V_215 * V_216 , const T_7 V_89 )
{
T_6 V_217 ;
if ( V_89 & V_218 ) {
V_217 = F_130 ( V_219 ) ;
V_216 -> V_220 = ! ! ( V_217 & V_221 ) ;
V_216 -> V_222 = ! ! ( V_217 & V_223 ) ;
V_216 -> V_224 = ! ! ( V_217 & V_225 ) ;
V_216 -> V_226 = ! ! ( V_217 & V_227 ) ;
}
if ( V_89 & V_228 ) {
V_217 = F_130 ( V_229 ) ;
V_216 -> V_230 = ! ! ( V_217 & V_231 ) ;
}
if ( V_89 & V_232 ) {
V_217 = F_130 ( V_233 ) ;
V_216 -> V_234 =
! ! ( V_217 & V_235 ) ;
}
if ( V_89 & V_236 ) {
V_217 = F_130 ( V_237 ) ;
V_216 -> V_238 = ( V_217 & V_239 )
>> V_240 ;
V_216 -> V_241 =
! ! ( V_217 & V_242 ) ;
}
if ( V_89 & V_243 ) {
V_217 = F_130 ( V_244 ) ;
V_216 -> V_245 = ( V_217 & V_246 )
>> V_247 ;
V_216 -> V_248 = ! ! ( V_217 & V_249 ) ;
V_216 -> V_250 = ! ! ( V_217 & V_251 ) ;
}
}
void F_131 ( const unsigned int V_252 ,
const unsigned int V_253 )
{
unsigned int V_42 = V_252 ;
while ( V_42 > V_253 ) {
F_132 ( V_254 ) ;
V_42 -- ;
}
while ( V_42 < V_253 ) {
F_132 ( V_255 ) ;
V_42 ++ ;
}
}
void F_133 ( const unsigned int V_256 ,
const unsigned int V_257 )
{
unsigned int V_42 = V_256 ;
while ( V_42 > V_257 ) {
F_132 ( V_258 ) ;
V_42 -- ;
}
while ( V_42 < V_257 ) {
F_132 ( V_259 ) ;
V_42 ++ ;
}
}
static int F_134 ( void * V_63 )
{
struct V_215 V_117 [ 2 ] ;
T_7 V_260 , V_261 ;
unsigned int V_262 , V_263 ;
unsigned long V_156 ;
unsigned int V_264 ;
unsigned int V_265 ;
bool V_266 ;
if ( V_66 == V_198 )
goto exit;
F_135 () ;
V_263 = 0 ;
V_262 = 1 ;
V_156 = 0 ;
F_114 ( & V_267 ) ;
V_264 = V_268 ;
V_260 = V_192 ;
V_261 = V_192 &
( V_194 | V_191 ) ;
V_265 = V_269 ;
F_117 ( & V_267 ) ;
F_129 ( & V_117 [ V_263 ] , V_260 ) ;
while ( ! F_136 () ) {
if ( V_156 == 0 ) {
if ( F_137 ( V_265 ) )
V_156 = 1000 / V_265 ;
else
V_156 = 100 ;
}
V_156 = F_138 ( V_156 ) ;
if ( F_139 ( F_140 ( & V_266 ) ) )
break;
if ( V_156 > 0 && ! V_266 )
continue;
F_114 ( & V_267 ) ;
if ( V_266 || V_268 != V_264 ) {
V_262 = V_263 ;
V_156 = 0 ;
V_264 = V_268 ;
}
V_260 = V_192 ;
V_261 = V_192 &
( V_194 | V_191 ) ;
V_265 = V_269 ;
F_117 ( & V_267 ) ;
if ( F_137 ( V_260 ) ) {
F_129 ( & V_117 [ V_262 ] , V_260 ) ;
if ( F_137 ( V_262 != V_263 ) ) {
F_141 ( & V_117 [ V_263 ] , & V_117 [ V_262 ] ,
V_261 ) ;
}
}
V_263 = V_262 ;
V_262 ^= 1 ;
}
exit:
return 0 ;
}
static void F_142 ( void )
{
if ( V_270 ) {
F_143 ( V_270 ) ;
V_270 = NULL ;
}
}
static void F_116 ( const bool V_271 )
{
const T_7 V_272 = V_194 & V_192 ;
const T_7 V_273 = V_191 & V_192 ;
if ( V_269 > 0 &&
( V_272 ||
( V_273 && V_207 -> V_274 > 0 ) ) ) {
if ( ! V_270 ) {
V_270 = F_144 ( F_134 ,
NULL , V_275 ) ;
if ( F_145 ( V_270 ) ) {
V_270 = NULL ;
F_8 ( L_76
L_77 ) ;
}
}
} else {
F_142 () ;
if ( V_271 && ( V_272 || V_273 ) &&
V_269 == 0 ) {
F_31 ( L_78
L_79
L_80 ,
V_273 , V_272 ) ;
}
}
}
static void F_146 ( const bool V_271 )
{
F_114 ( & V_202 ) ;
F_116 ( V_271 ) ;
F_117 ( & V_202 ) ;
}
static void F_147 ( unsigned int V_276 )
{
if ( ! V_276 )
F_142 () ;
V_269 = V_276 ;
}
static void F_116 ( const bool V_277 )
{
}
static void F_146 ( const bool V_277 )
{
}
static int F_148 ( struct V_278 * V_105 )
{
switch ( V_66 ) {
case V_279 :
case V_67 :
F_146 ( false ) ;
return 0 ;
case V_198 :
return - V_280 ;
}
F_149 () ;
return - V_280 ;
}
static void F_150 ( struct V_278 * V_105 )
{
if ( V_66 != V_198 &&
! ( V_192 & V_194 ) )
F_146 ( false ) ;
}
static T_8 F_151 ( struct V_71 * V_105 ,
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
static T_8 F_152 ( struct V_71 * V_105 ,
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
static T_8 F_153 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_53 , V_191 ) ;
}
static T_8 F_154 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
int V_17 ;
if ( F_56 ( V_125 , 0xffffffffUL , & V_156 ) )
return - V_92 ;
if ( F_155 ( & V_202 ) )
return - V_281 ;
V_17 = F_112 ( V_156 ) ;
#ifdef F_115
F_116 ( true ) ;
#endif
F_117 ( & V_202 ) ;
F_81 ( L_84 , L_85 , V_156 ) ;
return ( V_17 ) ? V_17 : V_35 ;
}
static T_8 F_156 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return sprintf ( V_125 , L_86 ) ;
}
static T_8 F_157 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
F_60 ( L_87 ,
L_88 ) ;
return snprintf ( V_125 , V_100 , L_53 , V_282 ) ;
}
static T_8 F_158 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_53 ,
V_190 | V_192 ) ;
}
static T_8 F_159 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_53 ,
( V_190 | V_192 )
& ~ V_283 ) ;
}
static T_8 F_160 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_53 , V_192 ) ;
}
static T_8 F_161 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
T_7 V_284 ;
int V_70 ;
if ( F_56 ( V_125 , 0xffffffffUL , & V_156 ) ||
( ( V_156 & ~ V_195 ) != 0 ) )
return - V_92 ;
if ( F_155 ( & V_202 ) )
return - V_281 ;
T_13
V_192 = V_156 ;
T_14
V_70 = F_111 ( ( V_191 | V_194 ) &
~ V_192 ) ;
F_116 ( true ) ;
V_284 = V_194 & ~ ( V_189 & V_190 )
& ~ V_192 & V_195 ;
F_117 ( & V_202 ) ;
if ( V_70 < 0 )
F_8 ( L_89
L_90 ) ;
if ( V_284 )
F_31 ( L_89
L_91 ,
V_284 ) ;
F_81 ( L_92 , L_85 , V_156 ) ;
return ( V_70 < 0 ) ? V_70 : V_35 ;
}
static T_8 F_162 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_42 , V_269 ) ;
}
static T_8 F_163 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
if ( F_56 ( V_125 , 25 , & V_156 ) )
return - V_92 ;
if ( F_155 ( & V_202 ) )
return - V_281 ;
F_147 ( V_156 ) ;
F_116 ( true ) ;
F_117 ( & V_202 ) ;
F_81 ( L_93 , L_94 , V_156 ) ;
return V_35 ;
}
static T_8 F_164 ( struct V_71 * V_105 ,
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
static void F_165 ( void )
{
if ( V_185 . V_186 )
F_166 ( & V_153 -> V_105 . V_124 , NULL ,
L_95 ) ;
}
static T_8 F_167 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 , V_117 ;
V_17 = F_108 ( & V_117 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_125 , V_100 , L_42 , ! ! V_117 ) ;
}
static void F_168 ( void )
{
if ( V_185 . V_205 )
F_166 ( & V_153 -> V_105 . V_124 , NULL ,
L_96 ) ;
}
static T_8 F_169 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_42 , V_285 ) ;
}
static void F_170 ( void )
{
F_166 ( & V_153 -> V_105 . V_124 , NULL ,
L_97 ) ;
}
static T_8 F_171 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_42 , V_286 ) ;
}
static void F_172 ( void )
{
F_166 ( & V_153 -> V_105 . V_124 , NULL ,
L_98 ) ;
}
static void F_173 ( void )
{
int V_287 ;
V_287 = F_68 () ;
if ( V_287 == V_134 )
F_65 ( true ) ;
F_64 () ;
if ( V_287 == V_141 )
F_65 ( false ) ;
if ( ! ( V_287 < 0 ) ) {
F_114 ( & V_206 ) ;
F_121 ( V_207 ,
V_288 , ( V_287 > 0 ) ) ;
F_122 ( V_207 ) ;
F_117 ( & V_206 ) ;
}
F_165 () ;
}
static void F_174 ( void )
{
#ifdef F_115
F_114 ( & V_202 ) ;
F_142 () ;
F_117 ( & V_202 ) ;
#endif
if ( V_289 )
F_53 ( V_289 , & V_153 -> V_105 . V_124 ) ;
F_20 ( V_290 | V_291 ,
L_99 ) ;
if ( ( ( V_185 . V_188 &&
F_111 ( V_282 ) ) |
F_119 ( false ) ) != 0 )
F_8 ( L_100
L_101 ) ;
}
static void T_1 F_175 ( const unsigned int V_209 )
{
if ( V_211 [ V_209 ] != V_212 ) {
F_176 ( V_211 [ V_209 ] ,
V_207 -> V_292 ) ;
V_211 [ V_209 ] = V_212 ;
}
}
static int T_1 F_177 ( struct V_293 * V_294 )
{
enum T_15 {
V_295 = 0 ,
V_296 ,
};
static const T_16 V_297 [] V_298 = {
[ V_295 ] = {
V_299 , V_300 , V_301 , V_302 ,
V_303 , V_304 , V_305 , V_306 ,
V_307 , V_308 , V_309 , V_310 ,
V_311 ,
V_311 ,
V_311 ,
V_212 ,
V_212 ,
V_212 ,
V_311 ,
V_312 ,
V_212 ,
V_212 ,
V_212 ,
V_313 ,
V_311 , V_311 , V_311 , V_311 ,
V_311 , V_311 , V_311 , V_311 ,
} ,
[ V_296 ] = {
V_299 , V_301 , V_300 , V_302 ,
V_303 , V_314 , V_305 , V_306 ,
V_307 , V_308 , V_309 , V_310 ,
V_311 ,
V_311 ,
V_311 ,
V_315 ,
V_316 ,
V_212 ,
V_311 ,
V_312 ,
V_212 ,
V_212 ,
V_212 ,
V_313 ,
V_311 , V_311 ,
V_317 ,
V_311 , V_311 , V_311 , V_311 ,
V_311 ,
} ,
} ;
static const struct V_3 V_318 [] V_298 = {
{
. V_6 = V_15 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_295 ,
} ,
{
. V_6 = V_14 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_296 ,
} ,
} ;
#define F_178 sizeof(tpacpi_keymap_t)
#define F_179 sizeof(tpacpi_keymap_entry_t)
int V_17 , V_42 ;
int V_30 ;
int V_319 ;
bool V_320 = false ;
bool V_321 = false ;
unsigned long V_13 ;
unsigned long V_322 ;
F_17 ( V_55 | V_291 ,
L_102 ) ;
F_23 ( ! V_207 ) ;
F_23 ( V_207 -> V_323 != NULL ||
V_207 -> V_324 != NULL ) ;
F_180 ( V_325 ) ;
F_181 ( & V_202 ) ;
#ifdef F_115
F_181 ( & V_267 ) ;
#endif
V_185 . V_201 = V_128 != NULL ;
F_17 ( V_55 | V_291 ,
L_103 ,
F_1 ( V_185 . V_201 ) ) ;
if ( ! V_185 . V_201 )
return 1 ;
V_13 = F_4 ( V_326 ,
F_99 ( V_326 ) ) ;
F_59 () ;
V_289 = F_50 (
F_99 ( V_327 ) + 2 ,
NULL ) ;
if ( ! V_289 )
return - V_82 ;
V_17 = F_52 ( V_289 ,
V_327 ,
F_99 ( V_327 ) ) ;
if ( V_17 )
goto V_328;
if ( F_7 ( V_128 , & V_319 , L_104 , L_105 ) ) {
if ( ( V_319 >> 8 ) != 1 ) {
F_8 ( L_106 ,
V_319 ) ;
F_8 ( L_107 , V_329 ) ;
} else {
F_17 ( V_55 | V_291 ,
L_108 ,
V_319 ) ;
if ( ! F_7 ( V_128 , & V_190 ,
L_109 , L_105 ) ) {
F_8 ( L_110
L_107 ,
V_329 ) ;
V_190 = 0x080cU ;
} else {
V_185 . V_188 = 1 ;
}
}
}
F_17 ( V_55 | V_291 ,
L_111 ,
F_1 ( V_185 . V_188 ) ) ;
if ( ! V_185 . V_188 && ! V_190 &&
( V_13 & V_330 ) )
V_190 = 0x080cU ;
if ( V_185 . V_188 ) {
V_17 = F_109 () ;
if ( V_17 )
goto V_328;
V_282 = V_189 ;
} else {
V_282 = V_190 ;
V_189 = V_190 ;
}
#ifdef F_101
if ( V_171 ) {
V_185 . V_186 = 1 ;
V_320 = ! ! V_166 ;
F_75 ( L_112 ) ;
} else
#endif
if ( F_7 ( V_128 , & V_30 , L_61 , L_105 ) ) {
V_185 . V_186 = 1 ;
V_320 = ! ! V_30 ;
F_75 ( L_113 ,
F_182 ( V_30 , 0 ) ) ;
}
if ( V_185 . V_186 )
V_17 = F_51 ( V_289 ,
& V_331 . V_121 ) ;
if ( ! V_17 && F_7 ( V_128 , & V_30 , L_63 , L_105 ) ) {
V_185 . V_205 = 1 ;
V_321 = ! ! ( V_30 & V_187 ) ;
F_75 ( L_114
L_115 ,
( V_321 ) ? L_116 : L_117 ) ;
V_17 = F_51 ( V_289 ,
& V_332 . V_121 ) ;
}
if ( ! V_17 )
V_17 = F_183 (
V_289 ,
& V_153 -> V_105 . V_124 ) ;
if ( V_17 )
goto V_328;
V_211 = F_43 ( F_178 ,
V_81 ) ;
if ( ! V_211 ) {
F_8 ( L_118 ) ;
V_17 = - V_82 ;
goto V_328;
}
V_322 = F_4 ( V_318 ,
F_99 ( V_318 ) ) ;
F_23 ( V_322 >= F_99 ( V_297 ) ) ;
F_20 ( V_55 | V_291 ,
L_119 , V_322 ) ;
memcpy ( V_211 , & V_297 [ V_322 ] ,
F_178 ) ;
F_184 ( V_207 , V_213 , V_214 ) ;
V_207 -> V_333 = F_179 ;
V_207 -> V_334 = V_335 ;
V_207 -> V_210 = V_211 ;
for ( V_42 = 0 ; V_42 < V_335 ; V_42 ++ ) {
if ( V_211 [ V_42 ] != V_212 ) {
F_184 ( V_207 , V_336 ,
V_211 [ V_42 ] ) ;
} else {
if ( V_42 < sizeof( V_283 ) * 8 )
V_283 |= 1 << V_42 ;
}
}
if ( V_185 . V_186 ) {
F_184 ( V_207 , V_337 , V_288 ) ;
F_121 ( V_207 ,
V_288 , V_320 ) ;
}
if ( V_185 . V_205 ) {
F_184 ( V_207 , V_337 , V_208 ) ;
F_121 ( V_207 ,
V_208 , V_321 ) ;
}
if ( F_185 () ) {
F_75 ( L_120
L_121
L_122 ) ;
F_31 ( L_123
L_124 ) ;
V_283 |=
( 1 << V_259 )
| ( 1 << V_258 ) ;
F_175 ( V_259 ) ;
F_175 ( V_258 ) ;
}
#ifdef F_115
V_192 = V_338
& ~ V_190
& ~ V_283 ;
F_17 ( V_55 | V_291 ,
L_125 ,
V_192 , V_269 ) ;
#endif
F_20 ( V_55 | V_291 ,
L_126 ) ;
V_17 = F_119 ( true ) ;
if ( V_17 ) {
F_174 () ;
return V_17 ;
}
V_17 = F_111 ( ( ( V_190 & ~ V_283 )
| V_194 )
& ~ V_192 ) ;
if ( V_17 < 0 && V_17 != - V_49 ) {
F_174 () ;
return V_17 ;
}
V_191 = ( V_189 | V_192 )
& ~ V_283 ;
F_17 ( V_55 | V_291 ,
L_127 ,
V_191 , V_189 , V_192 ) ;
V_207 -> V_323 = & F_148 ;
V_207 -> V_324 = & F_150 ;
F_146 ( true ) ;
return 0 ;
V_328:
F_53 ( V_289 , & V_153 -> V_105 . V_124 ) ;
V_289 = NULL ;
return ( V_17 < 0 ) ? V_17 : 1 ;
}
static bool F_186 ( const T_7 V_325 ,
bool * V_339 ,
bool * V_340 )
{
unsigned int V_209 = V_325 & 0xfff ;
* V_339 = true ;
* V_340 = false ;
if ( V_209 > 0 && V_209 <= V_335 ) {
V_209 -- ;
if ( ! ( V_192 & ( 1 << V_209 ) ) ) {
F_126 ( V_209 ) ;
* V_339 = false ;
} else {
* V_340 = true ;
}
return true ;
}
return false ;
}
static bool F_187 ( const T_7 V_325 ,
bool * V_339 ,
bool * V_340 )
{
* V_339 = true ;
* V_340 = false ;
switch ( V_325 ) {
case V_341 :
case V_342 :
V_285 = V_343 ;
* V_340 = true ;
break;
case V_344 :
case V_345 :
V_285 = V_346 ;
* V_340 = true ;
break;
case V_347 :
case V_348 :
F_188 ( L_128 ) ;
break;
default:
return false ;
}
if ( V_285 != V_349 ) {
F_75 ( L_129 ) ;
F_170 () ;
}
return true ;
}
static bool F_189 ( const T_7 V_325 ,
bool * V_339 ,
bool * V_340 )
{
* V_339 = true ;
* V_340 = false ;
switch ( V_325 ) {
case V_350 :
V_286 = 1 ;
F_75 ( L_130 ) ;
F_172 () ;
return true ;
case V_351 :
F_75 ( L_131 ) ;
return true ;
case V_352 :
F_75 ( L_132 ) ;
return true ;
default:
return false ;
}
}
static bool F_190 ( const T_7 V_325 ,
bool * V_339 ,
bool * V_340 )
{
* V_339 = true ;
* V_340 = false ;
switch ( V_325 ) {
case V_353 :
case V_354 :
return true ;
case V_355 :
case V_356 :
F_120 () ;
F_168 () ;
* V_339 = false ;
return true ;
case V_357 :
case V_358 :
case V_359 :
* V_340 = true ;
return true ;
default:
return false ;
}
}
static bool F_191 ( const T_7 V_325 ,
bool * V_339 ,
bool * V_340 )
{
bool V_360 = true ;
* V_339 = true ;
* V_340 = false ;
switch ( V_325 ) {
case V_361 :
F_75 ( L_133 ) ;
return true ;
case V_362 :
F_192 ( L_134 ) ;
break;
case V_363 :
F_188 ( L_135 ) ;
break;
case V_364 :
F_192 ( L_136
L_137 ) ;
break;
case V_365 :
F_188 ( L_138
L_139 ) ;
break;
case V_366 :
case V_367 :
case V_368 :
* V_339 = false ;
* V_340 = true ;
return true ;
default:
F_61 ( L_140 ) ;
V_360 = false ;
}
F_193 () ;
return V_360 ;
}
static void F_194 ( struct V_64 * V_65 , T_7 V_62 )
{
T_7 V_325 ;
bool V_339 ;
bool V_340 ;
bool V_369 ;
if ( V_62 != 0x80 ) {
F_8 ( L_141 , V_62 ) ;
F_195 (
V_65 -> V_68 -> V_71 -> V_370 . V_371 ,
F_196 ( & V_65 -> V_68 -> V_71 -> V_105 ) ,
V_62 , 0 ) ;
return;
}
while ( 1 ) {
if ( ! F_7 ( V_128 , & V_325 , L_142 , L_62 ) ) {
F_8 ( L_143 ) ;
return;
}
if ( V_325 == 0 ) {
return;
}
V_339 = true ;
V_340 = false ;
switch ( V_325 >> 12 ) {
case 1 :
V_369 = F_186 ( V_325 , & V_339 ,
& V_340 ) ;
break;
case 2 :
V_369 = F_187 ( V_325 , & V_339 ,
& V_340 ) ;
break;
case 3 :
switch ( V_325 ) {
case V_372 :
V_286 = 1 ;
F_75 ( L_144 ) ;
F_172 () ;
V_369 = true ;
break;
case V_373 :
V_369 = true ;
break;
default:
V_369 = false ;
}
break;
case 4 :
V_369 = F_189 ( V_325 , & V_339 ,
& V_340 ) ;
break;
case 5 :
V_369 = F_190 ( V_325 , & V_339 ,
& V_340 ) ;
break;
case 6 :
V_369 = F_191 ( V_325 , & V_339 ,
& V_340 ) ;
break;
case 7 :
if ( V_185 . V_186 &&
V_325 == V_374 ) {
F_173 () ;
V_339 = 0 ;
V_369 = true ;
break;
}
default:
V_369 = false ;
}
if ( ! V_369 ) {
F_31 ( L_145 , V_325 ) ;
F_31 ( L_146
L_147 , V_329 ) ;
}
if ( ! V_340 && V_339 ) {
F_195 (
V_65 -> V_68 -> V_71 -> V_370 . V_371 ,
F_196 ( & V_65 -> V_68 -> V_71 -> V_105 ) ,
V_62 , V_325 ) ;
}
}
}
static void F_197 ( void )
{
V_285 = V_349 ;
V_286 = 0 ;
}
static void F_198 ( void )
{
F_59 () ;
if ( F_119 ( true ) < 0 ||
F_111 ( V_189 ) < 0 )
F_8 ( L_148
L_149 ) ;
F_173 () ;
F_168 () ;
F_170 () ;
F_172 () ;
F_146 ( false ) ;
}
static int F_199 ( struct V_88 * V_89 )
{
int V_17 , V_30 ;
if ( ! V_185 . V_201 ) {
F_83 ( V_89 , L_44 ) ;
return 0 ;
}
if ( F_155 ( & V_202 ) )
return - V_281 ;
V_17 = F_118 ( & V_30 ) ;
if ( ! V_17 )
V_17 = F_109 () ;
F_117 ( & V_202 ) ;
if ( V_17 )
return V_17 ;
F_83 ( V_89 , L_45 , F_182 ( V_30 , 0 ) ) ;
if ( V_190 ) {
F_83 ( V_89 , L_150 , V_191 ) ;
F_83 ( V_89 , L_151 ) ;
} else {
F_83 ( V_89 , L_152 ) ;
F_83 ( V_89 , L_153 ) ;
}
return 0 ;
}
static void F_200 ( bool V_203 )
{
F_2 ( L_154 ) ;
if ( ! F_201 ( ( V_66 == V_67 || ! V_203 ) ,
F_202 ( L_155
L_156
L_157 ) ) )
F_8 ( L_158
L_159
L_157 ) ;
}
static int F_203 ( char * V_125 )
{
int V_17 ;
T_7 V_196 ;
char * V_158 ;
if ( ! V_185 . V_201 )
return - V_72 ;
if ( F_155 ( & V_202 ) )
return - V_281 ;
V_196 = V_191 ;
V_17 = 0 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( F_85 ( V_158 , L_49 ) == 0 ) {
F_200 ( 1 ) ;
} else if ( F_85 ( V_158 , L_50 ) == 0 ) {
F_200 ( 0 ) ;
V_17 = - V_157 ;
} else if ( F_85 ( V_158 , L_160 ) == 0 ) {
V_196 = ( V_190 | V_192 )
& ~ V_283 ;
} else if ( sscanf ( V_158 , L_161 , & V_196 ) == 1 ) {
} else if ( sscanf ( V_158 , L_162 , & V_196 ) == 1 ) {
} else {
V_17 = - V_92 ;
goto V_375;
}
}
if ( ! V_17 ) {
F_81 ( L_163 ,
L_164 , V_196 ) ;
V_17 = F_112 ( V_196 ) ;
}
V_375:
F_117 ( & V_202 ) ;
return V_17 ;
}
static int F_204 ( void )
{
int V_30 ;
#ifdef F_101
if ( V_173 )
return ( V_167 ) ?
V_141 : V_134 ;
#endif
if ( ! F_7 ( V_128 , & V_30 , L_165 , L_62 ) )
return - V_50 ;
return ( ( V_30 & V_376 ) != 0 ) ?
V_141 : V_134 ;
}
static int F_205 ( enum V_377 V_204 )
{
int V_30 ;
F_17 ( V_139 ,
L_166 ,
( V_204 == V_141 ) ? L_49 : L_50 ) ;
#ifdef F_101
if ( V_173 ) {
V_167 = ( V_204 == V_141 ) ;
return 0 ;
}
#endif
if ( V_204 == V_141 )
V_30 = V_376
| V_378 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_128 , NULL , L_167 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_206 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return F_79 ( V_379 ,
V_121 , V_125 ) ;
}
static T_8 F_207 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
return F_80 ( V_379 ,
V_121 , V_125 , V_35 ) ;
}
static void F_208 ( void )
{
if ( ! F_7 ( NULL , NULL , L_168 , L_9 ,
V_380 ) )
F_31 ( L_169 ) ;
else
F_17 ( V_139 ,
L_170 ) ;
}
static void F_209 ( void )
{
F_54 ( & V_153 -> V_105 . V_124 ,
& V_381 ) ;
F_76 ( V_379 ) ;
F_208 () ;
}
static int T_1 F_210 ( struct V_293 * V_294 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_139 ,
L_171 ) ;
F_180 ( V_325 ) ;
V_185 . V_382 = V_128 &&
F_7 ( V_128 , & V_30 , L_165 , L_105 ) ;
F_17 ( V_55 | V_139 ,
L_172 ,
F_1 ( V_185 . V_382 ) ,
V_30 ) ;
#ifdef F_101
if ( V_173 ) {
V_185 . V_382 = 1 ;
F_75 ( L_173 ) ;
} else
#endif
if ( V_185 . V_382 &&
! ( V_30 & V_383 ) ) {
V_185 . V_382 = 0 ;
F_20 ( V_55 | V_139 ,
L_174 ) ;
}
if ( ! V_185 . V_382 )
return 1 ;
V_17 = F_70 ( V_379 ,
& V_384 ,
V_385 ,
V_386 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_211 ( & V_153 -> V_105 . V_124 ,
& V_381 ) ;
if ( V_17 ) {
F_76 ( V_379 ) ;
return V_17 ;
}
return 0 ;
}
static int F_212 ( struct V_88 * V_89 )
{
return F_82 ( V_379 , V_89 ) ;
}
static int F_213 ( char * V_125 )
{
return F_84 ( V_379 , V_125 ) ;
}
static int F_214 ( void )
{
int V_30 ;
#ifdef F_101
if ( V_175 )
return ( V_168 ) ?
V_141 : V_134 ;
#endif
if ( ! F_7 ( V_128 , & V_30 , L_175 , L_62 ) )
return - V_50 ;
return ( ( V_30 & V_387 ) != 0 ) ?
V_141 : V_134 ;
}
static int F_215 ( enum V_377 V_204 )
{
int V_30 ;
F_17 ( V_139 ,
L_176 ,
( V_204 == V_141 ) ? L_49 : L_50 ) ;
#ifdef F_101
if ( V_175 ) {
V_168 = ( V_204 == V_141 ) ;
return 0 ;
}
#endif
if ( V_204 == V_141 )
V_30 = V_387
| V_388 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_128 , NULL , L_177 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_216 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return F_79 ( V_389 ,
V_121 , V_125 ) ;
}
static T_8 F_217 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
return F_80 ( V_389 ,
V_121 , V_125 , V_35 ) ;
}
static void F_218 ( void )
{
if ( ! F_7 ( NULL , NULL , L_178 , L_9 ,
V_390 ) )
F_31 ( L_179 ) ;
else
F_17 ( V_139 ,
L_180 ) ;
}
static void F_219 ( void )
{
F_54 ( & V_153 -> V_105 . V_124 ,
& V_391 ) ;
F_76 ( V_389 ) ;
F_218 () ;
}
static int T_1 F_220 ( struct V_293 * V_294 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_139 ,
L_181 ) ;
F_180 ( V_325 ) ;
V_185 . V_392 = V_128 &&
F_7 ( V_128 , & V_30 , L_175 , L_105 ) ;
F_17 ( V_55 | V_139 ,
L_182 ,
F_1 ( V_185 . V_392 ) ,
V_30 ) ;
#ifdef F_101
if ( V_175 ) {
V_185 . V_392 = 1 ;
F_75 ( L_183 ) ;
} else
#endif
if ( V_185 . V_392 &&
! ( V_30 & V_393 ) ) {
V_185 . V_392 = 0 ;
F_20 ( V_55 | V_139 ,
L_184 ) ;
}
if ( ! V_185 . V_392 )
return 1 ;
V_17 = F_70 ( V_389 ,
& V_394 ,
V_395 ,
V_396 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_211 ( & V_153 -> V_105 . V_124 ,
& V_391 ) ;
if ( V_17 ) {
F_76 ( V_389 ) ;
return V_17 ;
}
return 0 ;
}
static int F_221 ( struct V_88 * V_89 )
{
return F_82 ( V_389 , V_89 ) ;
}
static int F_222 ( char * V_125 )
{
return F_84 ( V_389 , V_125 ) ;
}
static int F_223 ( void )
{
int V_30 ;
#ifdef F_101
if ( V_177 )
return ( V_169 ) ?
V_141 : V_134 ;
#endif
if ( ! F_7 ( V_128 , & V_30 , L_185 , L_62 ) )
return - V_50 ;
return ( ( V_30 & V_397 ) != 0 ) ?
V_141 : V_134 ;
}
static int F_224 ( enum V_377 V_204 )
{
int V_30 ;
F_17 ( V_139 ,
L_186 ,
( V_204 == V_141 ) ? L_49 : L_50 ) ;
#ifdef F_101
if ( V_177 ) {
V_169 = ( V_204 == V_141 ) ;
return 0 ;
}
#endif
if ( V_204 == V_141 )
V_30 = V_397 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_128 , NULL , L_187 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static void F_225 ( void )
{
F_76 ( V_398 ) ;
}
static int T_1 F_226 ( struct V_293 * V_294 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_139 ,
L_188 ) ;
F_180 ( V_325 ) ;
V_185 . V_399 = V_128 &&
F_7 ( V_128 , & V_30 , L_185 , L_105 ) ;
F_17 ( V_55 | V_139 ,
L_189 ,
F_1 ( V_185 . V_399 ) ,
V_30 ) ;
#ifdef F_101
if ( V_177 ) {
V_185 . V_399 = 1 ;
F_75 ( L_190 ) ;
} else
#endif
if ( V_185 . V_399 &&
! ( V_30 & V_400 ) ) {
V_185 . V_399 = 0 ;
F_20 ( V_55 ,
L_191 ) ;
}
if ( ! V_185 . V_399 )
return 1 ;
V_17 = F_70 ( V_398 ,
& V_401 ,
V_402 ,
V_403 ,
false ) ;
return V_17 ;
}
static int T_1 F_227 ( struct V_293 * V_294 )
{
int V_404 ;
F_17 ( V_55 , L_192 ) ;
F_180 ( V_405 ) ;
if ( F_6 () )
F_180 ( V_406 ) ;
if ( V_407 && F_7 ( NULL , & V_404 , L_193 , L_62 ) && V_404 )
V_408 = V_407 ;
if ( ! V_408 )
V_409 = V_410 ;
else if ( F_6 () &&
F_7 ( V_408 , & V_411 , L_194 , L_105 ) )
V_409 = V_412 ;
else if ( F_6 () &&
F_7 ( V_408 , & V_411 , L_195 , L_105 ) )
V_409 = V_413 ;
else
V_409 = V_414 ;
F_17 ( V_55 , L_196 ,
F_1 ( V_409 != V_410 ) ,
V_409 ) ;
return ( V_409 != V_410 ) ? 0 : 1 ;
}
static void F_228 ( void )
{
F_20 ( V_290 ,
L_197 ) ;
if ( F_229 ( V_411 ) )
F_8 ( L_198
L_199 ) ;
}
static int F_230 ( void )
{
int V_30 = 0 ;
int V_42 ;
switch ( V_409 ) {
case V_412 :
if ( ! F_7 ( NULL , & V_42 , L_200 , L_7 ,
V_415 ) )
return - V_50 ;
V_30 = V_42 & V_416 ;
break;
case V_413 :
if ( ! F_7 ( NULL , & V_42 , L_201 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_417 ;
if ( ! F_7 ( NULL , & V_42 , L_202 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_418 ;
break;
case V_414 :
if ( ! F_7 ( NULL , NULL , L_203 , L_9 , 1 ) ||
! F_7 ( NULL , & V_42 , L_202 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_418 ;
if ( ! F_7 ( NULL , NULL , L_203 , L_9 , 0 ) ||
! F_7 ( NULL , & V_42 , L_201 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_417 ;
if ( ! F_7 ( NULL , & V_42 , L_204 , L_62 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_419 ;
break;
default:
return - V_420 ;
}
return V_30 ;
}
static int F_231 ( int V_30 )
{
int V_421 ;
int V_17 = 0 ;
switch ( V_409 ) {
case V_412 :
V_17 = F_7 ( NULL , NULL ,
L_205 , L_8 ,
V_422 ,
V_30 | V_423 ) ;
break;
case V_413 :
V_421 = F_232 () ;
if ( V_421 < 0 )
return V_421 ;
V_17 = F_229 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_408 , NULL ,
L_206 , L_8 , V_30 * 0x100 , 0 ) ;
if ( ! V_421 && F_229 ( V_421 ) ) {
F_8 ( L_207 ) ;
return - V_50 ;
}
break;
case V_414 :
V_17 = F_7 ( NULL , NULL , L_203 , L_9 , 0x80 ) &&
F_7 ( NULL , NULL , L_208 , L_8 , V_30 , 1 ) ;
break;
default:
return - V_420 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_232 ( void )
{
int V_421 = 0 ;
switch ( V_409 ) {
case V_412 :
if ( ! F_7 ( V_408 , & V_421 , L_194 , L_62 ) )
return - V_50 ;
break;
case V_413 :
case V_414 :
if ( ! F_7 ( V_408 , & V_421 , L_209 , L_62 ) )
return - V_50 ;
break;
default:
return - V_420 ;
}
return V_421 & 1 ;
}
static int F_229 ( int V_203 )
{
if ( ! F_7 ( V_408 , NULL , L_210 , L_9 , ( V_203 ) ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static int F_233 ( void )
{
int V_421 = F_232 () ;
int V_17 ;
if ( V_421 < 0 )
return V_421 ;
switch ( V_409 ) {
case V_412 :
V_17 = F_229 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_424 , NULL , L_211 , L_212 ) ;
break;
case V_413 :
case V_414 :
V_17 = F_229 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_408 , NULL , L_213 , L_212 ) ;
break;
default:
return - V_420 ;
}
if ( ! V_421 && F_229 ( V_421 ) ) {
F_8 ( L_207 ) ;
return - V_50 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_234 ( void )
{
switch ( V_409 ) {
case V_412 :
return F_7 ( V_424 , NULL , L_214 , L_212 ) ?
0 : - V_50 ;
case V_413 :
return F_7 ( V_408 , NULL , L_215 , L_212 ) ?
0 : - V_50 ;
case V_414 :
return F_7 ( NULL , NULL , L_216 , L_212 ) ?
0 : - V_50 ;
default:
return - V_420 ;
}
}
static int F_235 ( struct V_88 * V_89 )
{
int V_30 , V_421 ;
if ( V_409 == V_410 ) {
F_83 ( V_89 , L_44 ) ;
return 0 ;
}
if ( ! F_236 ( V_425 ) )
return - V_157 ;
V_30 = F_230 () ;
if ( V_30 < 0 )
return V_30 ;
V_421 = F_232 () ;
if ( V_421 < 0 )
return V_421 ;
F_83 ( V_89 , L_217 ) ;
F_83 ( V_89 , L_218 , F_182 ( V_30 , 0 ) ) ;
F_83 ( V_89 , L_219 , F_182 ( V_30 , 1 ) ) ;
if ( V_409 == V_414 )
F_83 ( V_89 , L_220 , F_182 ( V_30 , 3 ) ) ;
F_83 ( V_89 , L_221 , F_182 ( V_421 , 0 ) ) ;
F_83 ( V_89 , L_222 ) ;
F_83 ( V_89 , L_223 ) ;
if ( V_409 == V_414 )
F_83 ( V_89 , L_224 ) ;
F_83 ( V_89 , L_225 ) ;
F_83 ( V_89 , L_226 ) ;
return 0 ;
}
static int F_237 ( char * V_125 )
{
char * V_158 ;
int V_203 , V_426 , V_30 ;
int V_17 ;
if ( V_409 == V_410 )
return - V_72 ;
if ( ! F_236 ( V_425 ) )
return - V_157 ;
V_203 = 0 ;
V_426 = 0 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( F_85 ( V_158 , L_227 ) == 0 ) {
V_203 |= V_417 ;
} else if ( F_85 ( V_158 , L_228 ) == 0 ) {
V_426 |= V_417 ;
} else if ( F_85 ( V_158 , L_229 ) == 0 ) {
V_203 |= V_418 ;
} else if ( F_85 ( V_158 , L_230 ) == 0 ) {
V_426 |= V_418 ;
} else if ( V_409 == V_414 &&
F_85 ( V_158 , L_231 ) == 0 ) {
V_203 |= V_419 ;
} else if ( V_409 == V_414 &&
F_85 ( V_158 , L_232 ) == 0 ) {
V_426 |= V_419 ;
} else if ( F_85 ( V_158 , L_233 ) == 0 ) {
V_17 = F_229 ( 1 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_85 ( V_158 , L_234 ) == 0 ) {
V_17 = F_229 ( 0 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_85 ( V_158 , L_235 ) == 0 ) {
V_17 = F_233 () ;
if ( V_17 )
return V_17 ;
} else if ( F_85 ( V_158 , L_236 ) == 0 ) {
V_17 = F_234 () ;
if ( V_17 )
return V_17 ;
} else
return - V_92 ;
}
if ( V_203 || V_426 ) {
V_30 = F_230 () ;
if ( V_30 < 0 )
return V_30 ;
V_17 = F_231 ( ( V_30 & ~ V_426 ) | V_203 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_238 ( void )
{
int V_30 = 0 ;
if ( V_185 . V_427 ) {
if ( ! F_7 ( V_424 , & V_30 , L_237 , L_62 ) )
return - V_50 ;
return ( ! ! V_30 ) ;
}
return - V_49 ;
}
static int F_239 ( int V_30 )
{
int V_70 ;
if ( V_185 . V_428 ) {
if ( V_48 ) {
V_70 = F_7 ( V_48 , NULL , NULL , L_9 ,
( V_30 ) ?
V_429 :
V_430 ) ;
} else {
V_70 = F_7 ( V_431 , NULL , NULL , L_9 ,
( V_30 ) ? 1 : 0 ) ;
}
return ( V_70 ) ? 0 : - V_50 ;
}
return - V_49 ;
}
static void F_240 ( struct V_432 * V_433 )
{
struct V_434 * V_63 =
F_241 ( V_433 , struct V_434 , V_433 ) ;
if ( F_137 ( V_66 == V_67 ) )
F_239 ( ( V_63 -> V_435 != V_436 ) ) ;
}
static void F_242 ( struct V_437 * V_438 ,
enum V_439 V_440 )
{
struct V_434 * V_63 =
F_241 ( V_438 ,
struct V_434 ,
V_437 ) ;
V_63 -> V_435 = ( V_440 != V_441 ) ?
V_442 : V_436 ;
F_243 ( V_443 , & V_63 -> V_433 ) ;
}
static enum V_439 F_244 ( struct V_437 * V_438 )
{
return ( F_238 () == 1 ) ? V_444 : V_441 ;
}
static int T_1 F_245 ( struct V_293 * V_294 )
{
int V_70 ;
F_17 ( V_55 , L_238 ) ;
if ( F_6 () ) {
F_180 ( V_445 ) ;
F_180 ( V_446 ) ;
}
F_180 ( V_447 ) ;
F_246 ( & V_448 . V_433 , F_240 ) ;
V_185 . V_428 = ( V_48 || V_431 ) && ! V_449 ;
if ( V_185 . V_428 )
V_185 . V_427 =
F_7 ( V_424 , NULL , L_237 , L_239 ) ;
F_17 ( V_55 , L_240 ,
F_1 ( V_185 . V_428 ) ,
F_1 ( V_185 . V_427 ) ) ;
if ( ! V_185 . V_428 )
return 1 ;
V_70 = F_247 ( & V_153 -> V_105 ,
& V_448 . V_437 ) ;
if ( V_70 < 0 ) {
V_185 . V_428 = 0 ;
V_185 . V_427 = 0 ;
} else {
V_70 = 0 ;
}
return V_70 ;
}
static void F_248 ( void )
{
F_249 ( & V_448 . V_437 ) ;
F_250 ( V_443 ) ;
}
static int F_251 ( struct V_88 * V_89 )
{
int V_30 ;
if ( ! V_185 . V_428 ) {
F_83 ( V_89 , L_44 ) ;
} else if ( ! V_185 . V_427 ) {
F_83 ( V_89 , L_241 ) ;
F_83 ( V_89 , L_242 ) ;
} else {
V_30 = F_238 () ;
if ( V_30 < 0 )
return V_30 ;
F_83 ( V_89 , L_45 , F_252 ( V_30 , 0 ) ) ;
F_83 ( V_89 , L_242 ) ;
}
return 0 ;
}
static int F_253 ( char * V_125 )
{
char * V_158 ;
int V_450 = 0 ;
if ( ! V_185 . V_428 )
return - V_72 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( F_85 ( V_158 , L_243 ) == 0 ) {
V_450 = 1 ;
} else if ( F_85 ( V_158 , L_244 ) == 0 ) {
V_450 = 0 ;
} else
return - V_92 ;
}
return F_239 ( V_450 ) ;
}
static T_8 F_254 ( struct V_71 * V_105 ,
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
static int T_1 F_255 ( struct V_293 * V_294 )
{
int V_17 ;
F_17 ( V_55 ,
L_245 ) ;
F_180 ( V_447 ) ;
F_17 ( V_55 , L_246 ,
F_1 ( V_48 != NULL ) ) ;
V_17 = F_256 ( & V_153 -> V_105 , & V_451 ) ;
if ( V_17 )
return V_17 ;
return ( V_48 ) ? 0 : 1 ;
}
static void F_257 ( void )
{
F_258 ( & V_153 -> V_105 , & V_451 ) ;
}
static int F_259 ( struct V_88 * V_89 )
{
if ( ! V_48 )
F_83 ( V_89 , L_44 ) ;
else {
F_83 ( V_89 , L_217 ) ;
F_83 ( V_89 , L_247 ) ;
}
return 0 ;
}
static int F_260 ( char * V_125 )
{
char * V_158 ;
int V_47 , V_17 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( sscanf ( V_158 , L_248 , & V_47 ) == 1 &&
V_47 >= 0 && V_47 <= 21 ) {
} else
return - V_92 ;
V_17 = F_15 ( V_47 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static inline bool F_261 ( const unsigned int V_452 )
{
#ifdef F_262
return false ;
#else
return ( 1U & ( V_453 >> V_452 ) ) == 0 ;
#endif
}
static int F_263 ( const unsigned int V_452 )
{
int V_30 ;
enum V_454 V_455 ;
switch ( V_456 ) {
case V_457 :
if ( ! F_7 ( V_424 ,
& V_30 , L_249 , L_7 , 1 << V_452 ) )
return - V_50 ;
V_455 = ( V_30 == 0 ) ?
V_436 :
( ( V_30 == 1 ) ?
V_442 :
V_458 ) ;
V_459 [ V_452 ] = V_455 ;
return V_455 ;
default:
return - V_49 ;
}
}
static int F_264 ( const unsigned int V_452 ,
const enum V_454 V_460 )
{
static const unsigned int V_461 [] = { 0 , 1 , 3 } ;
static const unsigned int V_462 [] = { 0 , 0x80 , 0xc0 } ;
int V_70 = 0 ;
switch ( V_456 ) {
case V_457 :
if ( F_139 ( V_452 > 7 ) )
return - V_92 ;
if ( F_139 ( F_261 ( V_452 ) ) )
return - V_157 ;
if ( ! F_7 ( V_463 , NULL , NULL , L_8 ,
( 1 << V_452 ) , V_461 [ V_460 ] ) )
V_70 = - V_50 ;
break;
case V_464 :
if ( F_139 ( V_452 > 7 ) )
return - V_92 ;
if ( F_139 ( F_261 ( V_452 ) ) )
return - V_157 ;
V_70 = F_14 ( V_465 , ( 1 << V_452 ) ) ;
if ( V_70 >= 0 )
V_70 = F_14 ( V_466 ,
( V_460 == V_458 ) << V_452 ) ;
if ( V_70 >= 0 )
V_70 = F_14 ( V_467 ,
( V_460 != V_436 ) << V_452 ) ;
break;
case V_468 :
if ( F_139 ( V_452 >= V_469 ) )
return - V_92 ;
if ( F_139 ( F_261 ( V_452 ) ) )
return - V_157 ;
if ( ! F_7 ( V_463 , NULL , NULL , L_8 ,
V_452 , V_462 [ V_460 ] ) )
V_70 = - V_50 ;
break;
default:
V_70 = - V_49 ;
}
if ( ! V_70 )
V_459 [ V_452 ] = V_460 ;
return V_70 ;
}
static void F_265 ( struct V_432 * V_433 )
{
struct V_434 * V_63 =
F_241 ( V_433 , struct V_434 , V_433 ) ;
if ( F_137 ( V_66 == V_67 ) )
F_264 ( V_63 -> V_452 , V_63 -> V_435 ) ;
}
static void F_266 ( struct V_437 * V_438 ,
enum V_439 V_440 )
{
struct V_434 * V_63 = F_241 ( V_438 ,
struct V_434 , V_437 ) ;
if ( V_440 == V_441 )
V_63 -> V_435 = V_436 ;
else if ( V_459 [ V_63 -> V_452 ] != V_458 )
V_63 -> V_435 = V_442 ;
else
V_63 -> V_435 = V_458 ;
F_243 ( V_443 , & V_63 -> V_433 ) ;
}
static int F_267 ( struct V_437 * V_438 ,
unsigned long * V_470 , unsigned long * V_471 )
{
struct V_434 * V_63 = F_241 ( V_438 ,
struct V_434 , V_437 ) ;
if ( * V_470 == 0 && * V_471 == 0 ) {
* V_470 = 500 ;
* V_471 = 500 ;
} else if ( ( * V_470 != 500 ) || ( * V_471 != 500 ) )
return - V_92 ;
V_63 -> V_435 = V_458 ;
F_243 ( V_443 , & V_63 -> V_433 ) ;
return 0 ;
}
static enum V_439 F_268 ( struct V_437 * V_438 )
{
int V_70 ;
struct V_434 * V_63 = F_241 ( V_438 ,
struct V_434 , V_437 ) ;
V_70 = F_263 ( V_63 -> V_452 ) ;
if ( V_70 == V_436 || V_70 < 0 )
V_70 = V_441 ;
else
V_70 = V_444 ;
return V_70 ;
}
static void F_269 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_469 ; V_42 ++ ) {
if ( V_472 [ V_42 ] . V_437 . V_51 )
F_249 ( & V_472 [ V_42 ] . V_437 ) ;
}
F_250 ( V_443 ) ;
F_36 ( V_472 ) ;
}
static int T_1 F_270 ( unsigned int V_452 )
{
int V_70 ;
V_472 [ V_452 ] . V_452 = V_452 ;
if ( ! V_473 [ V_452 ] )
return 0 ;
V_472 [ V_452 ] . V_437 . V_474 = & F_266 ;
V_472 [ V_452 ] . V_437 . V_475 = & F_267 ;
if ( V_456 == V_457 )
V_472 [ V_452 ] . V_437 . V_476 =
& F_268 ;
V_472 [ V_452 ] . V_437 . V_51 = V_473 [ V_452 ] ;
F_246 ( & V_472 [ V_452 ] . V_433 , F_265 ) ;
V_70 = F_247 ( & V_153 -> V_105 ,
& V_472 [ V_452 ] . V_437 ) ;
if ( V_70 < 0 )
V_472 [ V_452 ] . V_437 . V_51 = NULL ;
return V_70 ;
}
static enum V_477 T_1 F_271 ( void )
{
T_4 V_30 ;
if ( F_6 () ) {
V_30 = F_18 ( V_424 , L_250 , & V_463 ) ;
if ( F_19 ( V_30 ) )
return V_457 ;
V_30 = F_18 ( V_424 , L_251 , & V_463 ) ;
if ( F_19 ( V_30 ) )
return V_464 ;
}
V_30 = F_18 ( V_424 , L_252 , & V_463 ) ;
if ( F_19 ( V_30 ) )
return V_468 ;
V_463 = NULL ;
return V_478 ;
}
static int T_1 F_272 ( struct V_293 * V_294 )
{
unsigned int V_42 ;
int V_70 ;
unsigned long V_479 ;
F_17 ( V_55 , L_253 ) ;
V_456 = F_271 () ;
if ( V_456 != V_478 ) {
V_479 = F_4 ( V_480 ,
F_99 ( V_480 ) ) ;
if ( ! V_479 ) {
V_463 = NULL ;
V_456 = V_478 ;
}
}
F_17 ( V_55 , L_254 ,
F_1 ( V_456 ) , V_456 ) ;
if ( V_456 == V_478 )
return 1 ;
V_472 = F_34 ( sizeof( * V_472 ) * V_469 ,
V_81 ) ;
if ( ! V_472 ) {
F_8 ( L_255 ) ;
return - V_82 ;
}
for ( V_42 = 0 ; V_42 < V_469 ; V_42 ++ ) {
V_472 [ V_42 ] . V_452 = - 1 ;
if ( ! F_261 ( V_42 ) &&
F_273 ( V_42 , & V_479 ) ) {
V_70 = F_270 ( V_42 ) ;
if ( V_70 < 0 ) {
F_269 () ;
return V_70 ;
}
}
}
#ifdef F_262
F_31 ( L_256
L_257 ) ;
#endif
return 0 ;
}
static int F_274 ( struct V_88 * V_89 )
{
if ( ! V_456 ) {
F_83 ( V_89 , L_44 ) ;
return 0 ;
}
F_83 ( V_89 , L_217 ) ;
if ( V_456 == V_457 ) {
int V_42 , V_30 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_30 = F_263 ( V_42 ) ;
if ( V_30 < 0 )
return - V_50 ;
F_83 ( V_89 , L_258 ,
V_42 , F_275 ( V_30 ) ) ;
}
}
F_83 ( V_89 , L_259
L_260 ) ;
return 0 ;
}
static int F_276 ( char * V_125 )
{
char * V_158 ;
int V_452 , V_70 ;
enum V_454 V_117 ;
if ( ! V_456 )
return - V_72 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( sscanf ( V_158 , L_261 , & V_452 ) != 1 )
return - V_92 ;
if ( V_452 < 0 || V_452 > ( V_469 - 1 ) ||
V_472 [ V_452 ] . V_452 < 0 )
return - V_72 ;
if ( strstr ( V_158 , L_244 ) ) {
V_117 = V_436 ;
} else if ( strstr ( V_158 , L_243 ) ) {
V_117 = V_442 ;
} else if ( strstr ( V_158 , L_262 ) ) {
V_117 = V_458 ;
} else {
return - V_92 ;
}
V_70 = F_264 ( V_452 , V_117 ) ;
if ( V_70 < 0 )
return V_70 ;
}
return 0 ;
}
static int T_1 F_277 ( struct V_293 * V_294 )
{
unsigned long V_13 ;
F_17 ( V_55 , L_263 ) ;
F_180 ( V_481 ) ;
F_17 ( V_55 , L_264 ,
F_1 ( V_482 != NULL ) ) ;
V_13 = F_4 ( V_483 ,
F_99 ( V_483 ) ) ;
V_185 . V_484 = ! ! ( V_13 & V_485 ) ;
return ( V_482 ) ? 0 : 1 ;
}
static int F_278 ( struct V_88 * V_89 )
{
if ( ! V_482 )
F_83 ( V_89 , L_44 ) ;
else {
F_83 ( V_89 , L_217 ) ;
F_83 ( V_89 , L_265 ) ;
}
return 0 ;
}
static int F_279 ( char * V_125 )
{
char * V_158 ;
int V_486 ;
if ( ! V_482 )
return - V_72 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( sscanf ( V_158 , L_248 , & V_486 ) == 1 &&
V_486 >= 0 && V_486 <= 17 ) {
} else
return - V_92 ;
if ( V_185 . V_484 ) {
if ( ! F_7 ( V_482 , NULL , NULL , L_8 ,
V_486 , 0 ) )
return - V_50 ;
} else {
if ( ! F_7 ( V_482 , NULL , NULL , L_9 ,
V_486 ) )
return - V_50 ;
}
}
return 0 ;
}
static int F_280 ( int V_487 , T_17 * V_38 )
{
int V_156 ;
T_18 V_488 ;
char V_489 [ 5 ] ;
V_156 = V_490 ;
switch ( V_491 ) {
#if V_492 >= 16
case V_493 :
if ( V_487 >= 8 && V_487 <= 15 ) {
V_156 = V_494 ;
V_487 -= 8 ;
}
#endif
case V_495 :
if ( V_487 <= 7 ) {
if ( ! F_11 ( V_156 + V_487 , & V_488 ) )
return - V_50 ;
* V_38 = V_488 * 1000 ;
return 0 ;
}
break;
case V_496 :
if ( V_487 <= 7 ) {
snprintf ( V_489 , sizeof( V_489 ) , L_266 , '0' + V_487 ) ;
if ( ! F_7 ( V_424 , NULL , L_267 , L_212 ) )
return - V_50 ;
if ( ! F_7 ( V_424 , & V_156 , V_489 , L_62 ) )
return - V_50 ;
* V_38 = ( V_156 - 2732 ) * 100 ;
return 0 ;
}
break;
case V_497 :
if ( V_487 <= 7 ) {
snprintf ( V_489 , sizeof( V_489 ) , L_266 , '0' + V_487 ) ;
if ( ! F_7 ( V_424 , & V_156 , V_489 , L_62 ) )
return - V_50 ;
if ( V_156 > 127 || V_156 < - 127 )
V_156 = V_498 ;
* V_38 = V_156 * 1000 ;
return 0 ;
}
break;
case V_499 :
default:
return - V_420 ;
}
return - V_92 ;
}
static int F_281 ( struct V_500 * V_117 )
{
int V_17 , V_42 ;
int V_216 ;
V_216 = 8 ;
V_42 = 0 ;
if ( ! V_117 )
return - V_92 ;
if ( V_491 == V_493 )
V_216 = 16 ;
for ( V_42 = 0 ; V_42 < V_216 ; V_42 ++ ) {
V_17 = F_280 ( V_42 , & V_117 -> V_501 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return V_216 ;
}
static void F_193 ( void )
{
int V_216 , V_42 ;
struct V_500 V_156 ;
V_216 = F_281 ( & V_156 ) ;
if ( V_216 <= 0 )
return;
F_31 ( L_268 ) ;
for ( V_42 = 0 ; V_42 < V_216 ; V_42 ++ ) {
if ( V_156 . V_501 [ V_42 ] != V_502 )
F_282 ( L_269 , ( int ) ( V_156 . V_501 [ V_42 ] / 1000 ) ) ;
else
F_282 ( L_270 ) ;
}
F_282 ( L_271 ) ;
}
static T_8 F_283 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
struct V_503 * V_504 =
F_284 ( V_121 ) ;
int V_487 = V_504 -> V_505 ;
T_17 V_38 ;
int V_17 ;
V_17 = F_280 ( V_487 , & V_38 ) ;
if ( V_17 )
return V_17 ;
if ( V_38 == V_502 )
return - V_49 ;
return snprintf ( V_125 , V_100 , L_42 , V_38 ) ;
}
static int T_1 F_285 ( struct V_293 * V_294 )
{
T_6 V_156 , V_506 , V_507 ;
int V_42 ;
int V_508 ;
int V_17 ;
F_17 ( V_55 , L_272 ) ;
V_508 = F_7 ( V_424 , NULL , L_273 , L_239 ) ;
if ( V_7 . V_12 ) {
V_506 = V_507 = 0 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( F_11 ( V_490 + V_42 , & V_156 ) ) {
V_506 |= V_156 ;
} else {
V_506 = 0 ;
break;
}
if ( F_11 ( V_494 + V_42 , & V_156 ) ) {
V_507 |= V_156 ;
} else {
V_506 = 0 ;
break;
}
}
if ( V_506 == 0 ) {
if ( V_508 ) {
F_8 ( L_274
L_275
L_276 ) ;
V_491 = V_497 ;
} else {
F_8 ( L_274
L_277 ) ;
V_491 = V_499 ;
}
} else {
V_491 =
( V_507 != 0 ) ?
V_493 : V_495 ;
}
} else if ( V_508 ) {
if ( F_6 () &&
F_7 ( V_424 , NULL , L_267 , L_239 ) ) {
V_491 = V_496 ;
} else {
V_491 = V_497 ;
}
} else {
V_491 = V_499 ;
}
F_17 ( V_55 , L_278 ,
F_1 ( V_491 != V_499 ) ,
V_491 ) ;
switch ( V_491 ) {
case V_493 :
V_17 = F_211 ( & V_509 -> V_105 . V_124 ,
& V_510 ) ;
if ( V_17 )
return V_17 ;
break;
case V_495 :
case V_497 :
case V_496 :
V_17 = F_211 ( & V_509 -> V_105 . V_124 ,
& V_511 ) ;
if ( V_17 )
return V_17 ;
break;
case V_499 :
default:
return 1 ;
}
return 0 ;
}
static void F_286 ( void )
{
switch ( V_491 ) {
case V_493 :
F_54 ( & V_509 -> V_105 . V_124 ,
& V_510 ) ;
break;
case V_495 :
case V_497 :
case V_496 :
F_54 ( & V_509 -> V_105 . V_124 ,
& V_511 ) ;
break;
case V_499 :
default:
break;
}
}
static int F_287 ( struct V_88 * V_89 )
{
int V_216 , V_42 ;
struct V_500 V_156 ;
V_216 = F_281 ( & V_156 ) ;
if ( F_139 ( V_216 < 0 ) )
return V_216 ;
F_83 ( V_89 , L_279 ) ;
if ( V_216 > 0 ) {
for ( V_42 = 0 ; V_42 < ( V_216 - 1 ) ; V_42 ++ )
F_83 ( V_89 , L_280 , V_156 . V_501 [ V_42 ] / 1000 ) ;
F_83 ( V_89 , L_42 , V_156 . V_501 [ V_42 ] / 1000 ) ;
} else
F_83 ( V_89 , L_281 ) ;
return 0 ;
}
static unsigned int F_288 ( void )
{
T_6 V_512 ;
V_512 = ( F_130 ( V_237 )
& V_239 )
>> V_240 ;
V_512 &= V_513 ;
return V_512 ;
}
static void F_289 ( void )
{
T_6 V_514 = 0 ;
T_6 V_515 ;
if ( V_516 != V_517 )
return;
F_17 ( V_518 ,
L_282 ) ;
if ( F_155 ( & V_519 ) < 0 )
return;
if ( F_139 ( ! F_11 ( V_520 , & V_514 ) ) )
goto V_521;
V_514 &= V_522 ;
V_515 = F_130 ( V_237 ) ;
if ( V_514 != ( ( V_515 & V_239 )
>> V_240 ) ) {
V_515 &= ~ ( V_239 <<
V_240 ) ;
V_515 |= V_514 ;
F_290 ( V_515 , V_237 ) ;
F_20 ( V_518 ,
L_283 ,
( unsigned int ) V_514 , ( unsigned int ) V_515 ) ;
} else
F_17 ( V_518 ,
L_284 ,
( unsigned int ) V_514 , ( unsigned int ) V_515 ) ;
V_521:
F_117 ( & V_519 ) ;
}
static int F_291 ( int * V_30 )
{
T_6 V_514 = 0 ;
switch ( V_516 ) {
case V_523 :
* V_30 = F_288 () ;
return 0 ;
case V_524 :
case V_517 :
if ( F_139 ( ! F_11 ( V_520 , & V_514 ) ) )
return - V_50 ;
* V_30 = V_514 ;
return 0 ;
default:
return - V_49 ;
}
}
static int F_292 ( unsigned int V_38 )
{
T_6 V_514 = 0 ;
if ( F_139 ( ! F_11 ( V_520 , & V_514 ) ) )
return - V_50 ;
if ( F_139 ( ! F_13 ( V_520 ,
( V_514 & V_525 ) |
( V_38 & V_522 ) ) ) )
return - V_50 ;
return 0 ;
}
static int F_293 ( unsigned int V_38 )
{
int V_47 , V_526 ;
unsigned int V_527 , V_42 ;
V_527 = F_288 () ;
if ( V_38 == V_527 )
return 0 ;
V_47 = ( V_38 > V_527 ) ?
V_528 :
V_529 ;
V_526 = ( V_38 > V_527 ) ? 1 : - 1 ;
for ( V_42 = V_527 ; V_42 != V_38 ; V_42 += V_526 )
if ( F_15 ( V_47 ) )
return - V_50 ;
return 0 ;
}
static int V_474 ( unsigned int V_38 )
{
int V_17 ;
if ( V_38 > V_513 || V_38 < 0 )
return - V_92 ;
F_17 ( V_518 ,
L_285 , V_38 ) ;
V_17 = F_155 ( & V_519 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_516 ) {
case V_524 :
case V_517 :
V_17 = F_292 ( V_38 ) ;
break;
case V_523 :
V_17 = F_293 ( V_38 ) ;
break;
default:
V_17 = - V_49 ;
}
F_117 ( & V_519 ) ;
return V_17 ;
}
static int F_294 ( struct V_530 * V_531 )
{
unsigned int V_56 =
( V_531 -> V_532 . V_533 == V_534 &&
V_531 -> V_532 . V_535 == V_534 ) ?
V_531 -> V_532 . V_440 : 0 ;
F_20 ( V_518 ,
L_286 ,
V_56 ) ;
return V_474 ( V_56 ) ;
}
static int V_476 ( struct V_530 * V_531 )
{
int V_30 , V_17 ;
V_17 = F_155 ( & V_519 ) ;
if ( V_17 < 0 )
return 0 ;
V_17 = F_291 ( & V_30 ) ;
F_117 ( & V_519 ) ;
if ( V_17 < 0 )
return 0 ;
return V_30 & V_522 ;
}
static void F_295 ( void )
{
F_296 ( V_536 ,
V_537 ) ;
}
static int T_1 F_297 ( T_3 V_16 )
{
struct V_26 V_538 = { V_539 , NULL } ;
union V_23 * V_540 ;
int V_70 ;
if ( F_19 ( F_9 ( V_16 , L_287 , NULL , & V_538 ) ) ) {
V_540 = (union V_23 * ) V_538 . V_36 ;
if ( ! V_540 || ( V_540 -> type != V_541 ) ) {
F_8 ( L_288 ,
V_329 ) ;
V_70 = 0 ;
} else {
V_70 = V_540 -> V_542 . V_35 ;
}
} else {
return 0 ;
}
F_36 ( V_538 . V_36 ) ;
return V_70 ;
}
static unsigned int T_1 F_298 ( void )
{
T_3 V_543 ;
int V_544 = 0 ;
F_22 ( L_289 , V_545 , & V_543 ) ;
if ( V_543 )
V_544 = F_297 ( V_543 ) ;
V_185 . V_546 = ( V_544 > 0 ) ;
return ( V_544 > 2 ) ? ( V_544 - 2 ) : 0 ;
}
static void T_1 F_299 ( void )
{
unsigned int V_547 ;
F_17 ( V_55 ,
L_290 ) ;
V_547 = F_298 () ;
switch ( V_547 ) {
case 16 :
V_513 = 15 ;
F_75 ( L_291 ) ;
break;
case 8 :
case 0 :
V_513 = 7 ;
F_75 ( L_292 ) ;
break;
default:
F_8 ( L_293
L_294 , V_329 ) ;
V_185 . V_548 = 1 ;
V_513 = V_547 - 1 ;
}
}
static int T_1 F_300 ( struct V_293 * V_294 )
{
struct V_549 V_532 ;
int V_547 ;
unsigned long V_13 ;
F_17 ( V_55 , L_295 ) ;
F_181 ( & V_519 ) ;
V_13 = F_4 ( V_550 ,
F_99 ( V_550 ) ) ;
if ( V_185 . V_548 )
return 1 ;
if ( ! V_551 ) {
F_20 ( V_55 | V_518 ,
L_296
L_297 ) ;
return 1 ;
}
if ( F_185 () ) {
if ( V_551 > 1 ) {
F_75 ( L_298
L_299 ) ;
return 1 ;
} else if ( V_551 == 1 ) {
F_61 ( L_300
L_301
L_302 ) ;
return 1 ;
}
} else if ( V_185 . V_546 && V_551 > 1 ) {
F_31 ( L_303
L_304
L_305 ) ;
}
if ( V_516 > V_552 )
return - V_92 ;
if ( V_516 == V_553 ||
V_516 == V_552 ) {
if ( V_13 & V_554 )
V_516 = V_517 ;
else
V_516 = V_523 ;
F_20 ( V_518 ,
L_306 ,
V_516 ) ;
}
if ( ! F_6 () &&
( V_516 == V_517 ||
V_516 == V_524 ) )
return - V_92 ;
if ( F_291 ( & V_547 ) < 0 )
return 1 ;
memset ( & V_532 , 0 , sizeof( struct V_549 ) ) ;
V_532 . type = V_555 ;
V_532 . V_556 = V_513 ;
V_532 . V_440 = V_547 & V_522 ;
V_536 = F_301 ( V_557 ,
NULL , NULL ,
& V_558 ,
& V_532 ) ;
if ( F_145 ( V_536 ) ) {
int V_70 = F_302 ( V_536 ) ;
V_536 = NULL ;
F_8 ( L_307 ) ;
return V_70 ;
}
F_17 ( V_55 | V_518 ,
L_308 ) ;
if ( V_13 & V_559 ) {
F_31 ( L_309
L_310 , V_516 ) ;
F_31 ( L_311
L_312 , V_329 ) ;
}
F_303 ( V_536 ) ;
F_17 ( V_55 | V_518 ,
L_313
L_314 ) ;
F_113 ( V_194
| V_560
| V_561 ) ;
return 0 ;
}
static void F_304 ( void )
{
F_289 () ;
}
static void F_305 ( void )
{
F_289 () ;
}
static void F_306 ( void )
{
if ( V_536 ) {
F_17 ( V_290 | V_518 ,
L_315 ) ;
F_307 ( V_536 ) ;
}
F_289 () ;
}
static int F_308 ( struct V_88 * V_89 )
{
int V_56 ;
V_56 = V_476 ( NULL ) ;
if ( V_56 < 0 ) {
F_83 ( V_89 , L_316 ) ;
} else {
F_83 ( V_89 , L_317 , V_56 ) ;
F_83 ( V_89 , L_318 ) ;
F_83 ( V_89 , L_319 ,
V_513 ) ;
}
return 0 ;
}
static int F_309 ( char * V_125 )
{
int V_56 ;
int V_70 ;
char * V_158 ;
V_56 = V_476 ( NULL ) ;
if ( V_56 < 0 )
return V_56 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( F_85 ( V_158 , L_320 ) == 0 ) {
if ( V_56 < V_513 )
V_56 ++ ;
} else if ( F_85 ( V_158 , L_321 ) == 0 ) {
if ( V_56 > 0 )
V_56 -- ;
} else if ( sscanf ( V_158 , L_322 , & V_56 ) == 1 &&
V_56 >= 0 && V_56 <= V_513 ) {
} else
return - V_92 ;
}
F_81 ( L_323 ,
L_324 , V_56 ) ;
V_70 = V_474 ( V_56 ) ;
if ( ! V_70 && V_536 )
F_296 ( V_536 ,
V_562 ) ;
return ( V_70 == - V_563 ) ? - V_281 : V_70 ;
}
static void F_310 ( void )
{
T_6 V_514 = 0 ;
T_6 V_515 ;
T_6 V_564 ;
if ( V_565 != V_566 )
return;
if ( ! V_567 )
return;
F_17 ( V_568 ,
L_325 ) ;
if ( V_185 . V_569 )
V_564 = V_570 ;
else
V_564 = V_570 | V_571 ;
if ( F_155 ( & V_572 ) < 0 )
return;
if ( F_139 ( ! F_11 ( V_573 , & V_514 ) ) )
goto V_521;
V_514 &= V_564 ;
V_515 = F_130 ( V_244 ) ;
if ( V_514 != ( V_515 & V_564 ) ) {
V_515 &= ~ V_564 ;
V_515 |= V_514 ;
F_290 ( V_515 , V_244 ) ;
F_20 ( V_568 ,
L_326 ,
( unsigned int ) V_514 , ( unsigned int ) V_515 ) ;
} else {
F_17 ( V_568 ,
L_327 ,
( unsigned int ) V_514 , ( unsigned int ) V_515 ) ;
}
V_521:
F_117 ( & V_572 ) ;
}
static int F_311 ( T_6 * V_30 )
{
T_6 V_117 ;
if ( ! F_11 ( V_573 , & V_117 ) )
return - V_50 ;
* V_30 = V_117 ;
F_20 ( V_568 , L_328 , V_117 ) ;
return 0 ;
}
static int F_312 ( T_6 * V_30 )
{
return F_311 ( V_30 ) ;
}
static int F_313 ( const T_6 V_30 )
{
if ( ! F_13 ( V_573 , V_30 ) )
return - V_50 ;
F_20 ( V_568 , L_329 , V_30 ) ;
return 0 ;
}
static int F_314 ( const T_6 V_30 )
{
return F_313 ( V_30 ) ;
}
static int F_315 ( const bool V_248 )
{
int V_70 ;
T_6 V_117 , V_216 ;
if ( F_155 ( & V_572 ) < 0 )
return - V_563 ;
V_70 = F_311 ( & V_117 ) ;
if ( V_70 )
goto V_521;
V_216 = ( V_248 ) ? V_117 | V_570 :
V_117 & ~ V_570 ;
if ( V_216 != V_117 ) {
V_70 = F_313 ( V_216 ) ;
if ( ! V_70 )
V_70 = 1 ;
}
V_521:
F_117 ( & V_572 ) ;
return V_70 ;
}
static int F_316 ( const bool V_248 )
{
F_20 ( V_568 , L_330 ,
( V_248 ) ? L_1 : L_40 ) ;
return F_315 ( V_248 ) ;
}
static int F_317 ( const bool V_248 )
{
int V_70 ;
F_20 ( V_568 , L_331 ,
( V_248 ) ? L_1 : L_40 ) ;
V_70 = F_315 ( V_248 ) ;
return ( V_70 < 0 ) ? V_70 : 0 ;
}
static int F_318 ( const T_6 V_574 )
{
int V_70 ;
T_6 V_117 , V_216 ;
if ( V_574 > V_575 )
return - V_92 ;
if ( F_155 ( & V_572 ) < 0 )
return - V_563 ;
V_70 = F_311 ( & V_117 ) ;
if ( V_70 )
goto V_521;
V_216 = ( V_117 & ~ V_571 ) | V_574 ;
if ( V_216 != V_117 ) {
V_70 = F_313 ( V_216 ) ;
if ( ! V_70 )
V_70 = 1 ;
}
V_521:
F_117 ( & V_572 ) ;
return V_70 ;
}
static int F_319 ( const T_6 V_574 )
{
F_20 ( V_568 ,
L_332 , V_574 ) ;
return F_318 ( V_574 ) ;
}
static void F_320 ( void )
{
struct V_576 * V_217 ;
if ( V_577 && V_577 -> V_578 ) {
V_217 = V_577 -> V_578 ;
if ( V_217 -> V_579 )
F_321 ( V_577 ,
V_580 ,
V_217 -> V_579 ) ;
if ( V_217 -> V_581 )
F_321 ( V_577 ,
V_580 ,
V_217 -> V_581 ) ;
}
}
static int F_322 ( struct V_582 * V_583 ,
struct V_584 * V_585 )
{
V_585 -> type = V_586 ;
V_585 -> V_35 = 1 ;
V_585 -> V_38 . integer . V_587 = 0 ;
V_585 -> V_38 . integer . V_126 = V_575 ;
return 0 ;
}
static int F_323 ( struct V_582 * V_583 ,
struct V_588 * V_589 )
{
T_6 V_117 ;
int V_70 ;
V_70 = F_312 ( & V_117 ) ;
if ( V_70 < 0 )
return V_70 ;
V_589 -> V_38 . integer . V_38 [ 0 ] = V_117 & V_571 ;
return 0 ;
}
static int F_324 ( struct V_582 * V_583 ,
struct V_588 * V_589 )
{
F_81 ( L_333 , L_334 ,
V_589 -> V_38 . integer . V_38 [ 0 ] ) ;
return F_319 ( V_589 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static int F_325 ( struct V_582 * V_583 ,
struct V_588 * V_589 )
{
T_6 V_117 ;
int V_70 ;
V_70 = F_312 ( & V_117 ) ;
if ( V_70 < 0 )
return V_70 ;
V_589 -> V_38 . integer . V_38 [ 0 ] =
( V_117 & V_570 ) ? 0 : 1 ;
return 0 ;
}
static int F_326 ( struct V_582 * V_583 ,
struct V_588 * V_589 )
{
F_81 ( L_333 , L_335 ,
V_589 -> V_38 . integer . V_38 [ 0 ] ?
L_40 : L_1 ) ;
return F_316 ( ! V_589 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static void F_327 ( void )
{
F_310 () ;
}
static void F_328 ( void )
{
F_320 () ;
}
static void F_329 ( void )
{
F_310 () ;
}
static void F_330 ( void )
{
if ( V_577 ) {
F_331 ( V_577 ) ;
V_577 = NULL ;
}
F_310 () ;
}
static int T_1 F_332 ( void )
{
struct V_590 * V_591 ;
struct V_576 * V_63 ;
struct V_582 * V_592 ;
struct V_582 * V_593 ;
int V_70 ;
V_70 = F_333 ( V_594 , V_595 , V_596 ,
sizeof( struct V_576 ) , & V_591 ) ;
if ( V_70 < 0 || ! V_591 ) {
F_8 ( L_336 , V_70 ) ;
return 1 ;
}
F_23 ( ! V_591 -> V_578 ) ;
V_63 = V_591 -> V_578 ;
V_63 -> V_591 = V_591 ;
F_334 ( V_591 -> V_79 , V_597 ,
sizeof( V_591 -> V_79 ) ) ;
F_334 ( V_591 -> V_598 , V_599 ,
sizeof( V_591 -> V_598 ) ) ;
snprintf ( V_591 -> V_600 , sizeof( V_591 -> V_600 ) , L_337 ,
( V_7 . V_601 ) ?
V_7 . V_601 : L_338 ) ;
snprintf ( V_591 -> V_602 , sizeof( V_591 -> V_602 ) ,
L_339 , V_591 -> V_598 , V_573 ,
( V_7 . V_601 ) ?
V_7 . V_601 : L_340 ) ;
if ( V_567 ) {
V_603 . V_604 = F_324 ;
V_603 . V_605 =
V_606 ;
V_607 . V_604 = F_326 ;
V_607 . V_605 =
V_606 ;
}
if ( ! V_185 . V_569 ) {
V_592 = F_335 ( & V_603 , NULL ) ;
V_70 = F_336 ( V_591 , V_592 ) ;
if ( V_70 < 0 ) {
F_8 ( L_341 ,
V_70 ) ;
goto V_328;
}
V_63 -> V_581 = & V_592 -> V_143 ;
}
V_593 = F_335 ( & V_607 , NULL ) ;
V_70 = F_336 ( V_591 , V_593 ) ;
if ( V_70 < 0 ) {
F_8 ( L_342 , V_70 ) ;
goto V_328;
}
V_63 -> V_579 = & V_593 -> V_143 ;
F_337 ( V_591 , & V_153 -> V_105 ) ;
V_70 = F_338 ( V_591 ) ;
if ( V_70 < 0 ) {
F_8 ( L_343 , V_70 ) ;
goto V_328;
}
V_577 = V_591 ;
return 0 ;
V_328:
F_331 ( V_591 ) ;
return 1 ;
}
static int T_1 F_339 ( struct V_293 * V_294 )
{
unsigned long V_13 ;
int V_70 ;
F_17 ( V_55 , L_344 ) ;
F_181 ( & V_572 ) ;
if ( V_565 > V_608 )
return - V_92 ;
if ( V_565 == V_609 ) {
F_8 ( L_345
L_294 , V_329 ) ;
return 1 ;
}
if ( V_610 >= V_611 )
return - V_92 ;
if ( ! V_612 ) {
F_17 ( V_55 | V_568 ,
L_346
L_347 ) ;
return 1 ;
}
V_13 = F_4 ( V_613 ,
F_99 ( V_613 ) ) ;
switch ( V_610 ) {
case V_614 :
if ( V_13 & V_615 )
V_185 . V_569 = 1 ;
else if ( V_13 & V_616 )
V_185 . V_569 = 0 ;
else
return 1 ;
break;
case V_617 :
V_185 . V_569 = 0 ;
break;
case V_618 :
V_185 . V_569 = 1 ;
break;
default:
return 1 ;
}
if ( V_610 != V_614 )
F_20 ( V_55 | V_568 ,
L_348 ,
V_610 ) ;
if ( V_565 == V_619 ||
V_565 == V_608 ) {
V_565 = V_566 ;
F_20 ( V_55 | V_568 ,
L_349 ,
V_565 ) ;
} else {
F_20 ( V_55 | V_568 ,
L_350 ,
V_565 ) ;
}
F_17 ( V_55 | V_568 ,
L_351 ,
F_1 ( ! V_185 . V_569 ) ) ;
V_70 = F_332 () ;
if ( V_70 ) {
F_8 ( L_352 ) ;
return V_70 ;
}
F_75 ( L_353 ,
( V_567 ) ?
L_354 :
L_355 ) ;
F_17 ( V_55 | V_568 ,
L_356 ) ;
F_113 ( V_194
| V_620
| V_621
| V_622 ) ;
return 0 ;
}
static int F_340 ( struct V_88 * V_89 )
{
T_6 V_30 ;
if ( F_312 ( & V_30 ) < 0 ) {
F_83 ( V_89 , L_316 ) ;
} else {
if ( V_185 . V_569 )
F_83 ( V_89 , L_357 ) ;
else
F_83 ( V_89 , L_317 ,
V_30 & V_571 ) ;
F_83 ( V_89 , L_358 ,
F_252 ( V_30 , V_623 ) ) ;
if ( V_567 ) {
F_83 ( V_89 , L_359 ) ;
if ( ! V_185 . V_569 ) {
F_83 ( V_89 ,
L_318 ) ;
F_83 ( V_89 ,
L_360
L_361 ,
V_575 ) ;
}
}
}
return 0 ;
}
static int F_341 ( char * V_125 )
{
T_6 V_117 ;
T_6 V_624 , V_625 ;
int V_626 ;
char * V_158 ;
int V_70 ;
if ( ! V_567 && V_66 != V_279 ) {
if ( F_139 ( ! V_199 . V_627 ) ) {
V_199 . V_627 = 1 ;
F_31 ( L_362
L_363 ) ;
F_31 ( L_364
L_365 ) ;
}
return - V_157 ;
}
V_70 = F_312 ( & V_117 ) ;
if ( V_70 < 0 )
return V_70 ;
V_624 = V_117 & V_571 ;
V_625 = V_117 & V_570 ;
while ( ( V_158 = F_45 ( & V_125 ) ) ) {
if ( ! V_185 . V_569 ) {
if ( F_85 ( V_158 , L_320 ) == 0 ) {
if ( V_625 )
V_625 = 0 ;
else if ( V_624 < V_575 )
V_624 ++ ;
continue;
} else if ( F_85 ( V_158 , L_321 ) == 0 ) {
if ( V_625 )
V_625 = 0 ;
else if ( V_624 > 0 )
V_624 -- ;
continue;
} else if ( sscanf ( V_158 , L_366 , & V_626 ) == 1 &&
V_626 >= 0 && V_626 <= V_575 ) {
V_624 = V_626 ;
continue;
}
}
if ( F_85 ( V_158 , L_367 ) == 0 )
V_625 = V_570 ;
else if ( F_85 ( V_158 , L_368 ) == 0 )
V_625 = 0 ;
else
return - V_92 ;
}
if ( V_185 . V_569 ) {
F_81 ( L_369 , L_335 ,
V_625 ? L_1 : L_40 ) ;
V_70 = F_317 ( ! ! V_625 ) ;
} else {
F_81 ( L_369 ,
L_370 ,
V_625 ? L_1 : L_40 , V_624 ) ;
V_70 = F_314 ( V_625 | V_624 ) ;
}
F_320 () ;
return ( V_70 == - V_563 ) ? - V_281 : V_70 ;
}
static void inline F_320 ( void )
{
}
static int T_1 F_339 ( struct V_293 * V_294 )
{
F_75 ( L_371 ) ;
return 1 ;
}
static void F_342 ( void )
{
if ( V_628 == 0x07 ) {
F_31 ( L_372
L_373 ) ;
V_185 . V_629 = 1 ;
}
}
static void F_343 ( T_6 * V_630 )
{
if ( F_139 ( V_185 . V_629 ) ) {
if ( * V_630 != V_628 ) {
V_185 . V_629 = 0 ;
} else {
* V_630 = V_631 ;
}
}
}
static bool F_344 ( void )
{
if ( V_185 . V_632 ) {
T_6 V_633 ;
if ( F_12 ( V_634 , & V_633 ) < 0 )
return false ;
V_633 &= 0xFEU ;
if ( F_14 ( V_634 , V_633 ) < 0 )
return false ;
}
return true ;
}
static bool F_345 ( void )
{
T_6 V_633 ;
if ( ! V_185 . V_632 )
return false ;
if ( F_12 ( V_634 , & V_633 ) < 0 )
return false ;
V_633 |= 0x01U ;
if ( F_14 ( V_634 , V_633 ) < 0 )
return false ;
return true ;
}
static void F_346 ( T_6 V_30 )
{
if ( ( V_30 &
( V_631 | V_635 ) ) == 0 ) {
if ( V_30 > 7 )
V_636 = 7 ;
else
V_636 = V_30 ;
}
}
static int F_347 ( T_6 * V_30 )
{
T_6 V_117 ;
switch ( V_637 ) {
case V_638 : {
int V_17 ;
if ( F_139 ( ! F_7 ( V_639 , & V_17 , NULL , L_62 ) ) )
return - V_50 ;
if ( F_137 ( V_30 ) )
* V_30 = V_17 & 0x07 ;
break;
}
case V_640 :
if ( F_139 ( ! F_11 ( V_641 , & V_117 ) ) )
return - V_50 ;
if ( F_137 ( V_30 ) ) {
* V_30 = V_117 ;
F_343 ( V_30 ) ;
}
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_348 ( T_6 * V_30 )
{
int V_70 ;
T_6 V_117 ;
if ( F_155 ( & V_642 ) )
return - V_281 ;
V_70 = F_347 ( & V_117 ) ;
if ( ! V_70 )
F_346 ( V_117 ) ;
F_117 ( & V_642 ) ;
if ( V_30 )
* V_30 = V_117 ;
return V_70 ;
}
static int F_349 ( unsigned int * V_643 )
{
T_6 V_644 , V_645 ;
switch ( V_637 ) {
case V_640 :
if ( F_139 ( ! F_344 () ) )
return - V_50 ;
if ( F_139 ( ! F_11 ( V_646 , & V_645 ) ||
! F_11 ( V_646 + 1 , & V_644 ) ) )
return - V_50 ;
if ( F_137 ( V_643 ) )
* V_643 = ( V_644 << 8 ) | V_645 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_350 ( unsigned int * V_643 )
{
T_6 V_644 , V_645 ;
bool V_70 ;
switch ( V_637 ) {
case V_640 :
if ( F_139 ( ! F_345 () ) )
return - V_50 ;
V_70 = ! F_11 ( V_646 , & V_645 ) ||
! F_11 ( V_646 + 1 , & V_644 ) ;
F_344 () ;
if ( V_70 )
return - V_50 ;
if ( F_137 ( V_643 ) )
* V_643 = ( V_644 << 8 ) | V_645 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_351 ( int V_56 )
{
if ( ! V_647 )
return - V_157 ;
switch ( V_648 ) {
case V_649 :
if ( V_56 >= 0 && V_56 <= 7 ) {
if ( ! F_7 ( V_650 , NULL , NULL , L_9 , V_56 ) )
return - V_50 ;
} else
return - V_92 ;
break;
case V_651 :
case V_652 :
if ( ! ( V_56 & V_631 ) &&
! ( V_56 & V_635 ) &&
( ( V_56 < 0 ) || ( V_56 > 7 ) ) )
return - V_92 ;
if ( V_56 & V_635 )
V_56 |= 7 ;
else if ( V_56 & V_631 )
V_56 |= 4 ;
if ( ! F_13 ( V_641 , V_56 ) )
return - V_50 ;
else
V_185 . V_629 = 0 ;
break;
default:
return - V_49 ;
}
F_17 ( V_653 ,
L_374 , V_56 ) ;
return 0 ;
}
static int F_352 ( int V_56 )
{
int V_70 ;
if ( ! V_647 )
return - V_157 ;
if ( F_155 ( & V_642 ) )
return - V_281 ;
if ( V_56 == V_654 )
V_56 = V_636 ;
V_70 = F_351 ( V_56 ) ;
if ( ! V_70 )
F_346 ( V_56 ) ;
F_117 ( & V_642 ) ;
return V_70 ;
}
static int F_353 ( void )
{
T_6 V_117 ;
int V_70 ;
if ( ! V_647 )
return - V_157 ;
if ( F_155 ( & V_642 ) )
return - V_281 ;
switch ( V_648 ) {
case V_651 :
case V_652 :
V_70 = F_347 ( & V_117 ) ;
if ( V_70 < 0 )
break;
if ( V_117 != 7 ) {
V_117 &= 0x07 ;
V_117 |= V_631 | 4 ;
}
if ( ! F_13 ( V_641 , V_117 ) )
V_70 = - V_50 ;
else {
V_185 . V_629 = 0 ;
V_70 = 0 ;
}
break;
case V_649 :
V_70 = F_347 ( & V_117 ) ;
if ( V_70 < 0 )
break;
V_117 &= 0x07 ;
V_117 |= 4 ;
if ( ! F_7 ( V_650 , NULL , NULL , L_9 , V_117 ) )
V_70 = - V_50 ;
else
V_70 = 0 ;
break;
default:
V_70 = - V_49 ;
}
F_117 ( & V_642 ) ;
if ( ! V_70 )
F_17 ( V_653 ,
L_374 ,
V_117 ) ;
return V_70 ;
}
static int F_354 ( void )
{
int V_70 ;
if ( ! V_647 )
return - V_157 ;
if ( F_155 ( & V_642 ) )
return - V_281 ;
V_70 = 0 ;
switch ( V_648 ) {
case V_651 :
case V_652 :
if ( ! F_13 ( V_641 , 0x00 ) )
V_70 = - V_50 ;
else {
V_636 = 0 ;
V_185 . V_629 = 0 ;
}
break;
case V_649 :
if ( ! F_7 ( V_650 , NULL , NULL , L_9 , 0x00 ) )
V_70 = - V_50 ;
else
V_636 = 0 ;
break;
default:
V_70 = - V_49 ;
}
if ( ! V_70 )
F_17 ( V_653 ,
L_375 ) ;
F_117 ( & V_642 ) ;
return V_70 ;
}
static int F_355 ( int V_643 )
{
int V_70 ;
if ( ! V_647 )
return - V_157 ;
if ( F_155 ( & V_642 ) )
return - V_281 ;
V_70 = 0 ;
switch ( V_648 ) {
case V_651 :
if ( V_643 >= 0 && V_643 <= 65535 ) {
if ( ! F_7 ( V_655 , NULL , NULL , L_376 ,
V_643 , V_643 , V_643 ) )
V_70 = - V_50 ;
} else
V_70 = - V_92 ;
break;
default:
V_70 = - V_49 ;
}
F_117 ( & V_642 ) ;
return V_70 ;
}
static void F_356 ( void )
{
if ( V_648 == V_656 )
return;
if ( V_657 > 0 &&
V_66 != V_198 )
F_357 ( V_443 , & V_658 ,
F_358 ( V_657 * 1000 ) ) ;
else
F_359 ( & V_658 ) ;
}
static void F_360 ( struct V_432 * V_659 )
{
int V_70 ;
if ( V_66 != V_67 )
return;
F_31 ( L_377 ) ;
V_70 = F_353 () ;
if ( V_70 < 0 ) {
F_8 ( L_378
L_379 , - V_70 ) ;
F_356 () ;
}
}
static T_8 F_361 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 , V_660 ;
T_6 V_30 ;
V_17 = F_348 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 & V_635 ) {
V_660 = 0 ;
} else if ( V_30 & V_631 ) {
V_660 = 2 ;
} else
V_660 = 1 ;
return snprintf ( V_125 , V_100 , L_42 , V_660 ) ;
}
static T_8 F_362 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
int V_17 , V_56 ;
if ( F_56 ( V_125 , 2 , & V_156 ) )
return - V_92 ;
F_81 ( L_380 ,
L_381 , V_156 ) ;
switch ( V_156 ) {
case 0 :
V_56 = V_635 ;
break;
case 1 :
V_56 = V_654 ;
break;
case 2 :
V_56 = V_631 ;
break;
case 3 :
return - V_420 ;
default:
return - V_92 ;
}
V_17 = F_352 ( V_56 ) ;
if ( V_17 == - V_49 )
return - V_92 ;
else if ( V_17 < 0 )
return V_17 ;
F_356 () ;
return V_35 ;
}
static T_8 F_363 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 ;
T_6 V_30 ;
V_17 = F_348 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_30 &
( V_631 | V_635 ) ) != 0 )
V_30 = V_636 ;
if ( V_30 > 7 )
V_30 = 7 ;
return snprintf ( V_125 , V_100 , L_382 , ( V_30 * 255 ) / 7 ) ;
}
static T_8 F_364 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_117 ;
int V_70 ;
T_6 V_30 , V_661 ;
if ( F_56 ( V_125 , 255 , & V_117 ) )
return - V_92 ;
F_81 ( L_383 ,
L_384 , V_117 ) ;
V_661 = ( V_117 >> 5 ) & 0x07 ;
if ( F_155 ( & V_642 ) )
return - V_281 ;
V_70 = F_347 ( & V_30 ) ;
if ( ! V_70 && ( V_30 &
( V_631 | V_635 ) ) == 0 ) {
V_70 = F_351 ( V_661 ) ;
if ( V_70 == - V_49 )
V_70 = - V_92 ;
else if ( ! V_70 ) {
F_346 ( V_661 ) ;
F_356 () ;
}
}
F_117 ( & V_642 ) ;
return ( V_70 ) ? V_70 : V_35 ;
}
static T_8 F_365 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 ;
unsigned int V_643 ;
V_17 = F_349 ( & V_643 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_125 , V_100 , L_382 , V_643 ) ;
}
static T_8 F_366 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
int V_17 ;
unsigned int V_643 ;
V_17 = F_350 ( & V_643 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_125 , V_100 , L_382 , V_643 ) ;
}
static T_8 F_367 ( struct V_160 * V_161 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_382 , V_657 ) ;
}
static T_8 F_368 ( struct V_160 * V_161 ,
const char * V_125 , T_10 V_35 )
{
unsigned long V_156 ;
if ( F_56 ( V_125 , 120 , & V_156 ) )
return - V_92 ;
if ( ! V_647 )
return - V_157 ;
V_657 = V_156 ;
F_356 () ;
F_81 ( L_385 , L_94 , V_156 ) ;
return V_35 ;
}
static int T_1 F_369 ( struct V_293 * V_294 )
{
int V_70 ;
unsigned long V_13 ;
F_17 ( V_55 | V_653 ,
L_386 ) ;
F_181 ( & V_642 ) ;
V_637 = V_662 ;
V_648 = V_656 ;
V_663 = 0 ;
V_657 = 0 ;
V_185 . V_629 = 0 ;
V_185 . V_632 = 0 ;
V_636 = 7 ;
if ( F_6 () ) {
F_180 ( V_664 ) ;
F_180 ( V_665 ) ;
F_180 ( V_666 ) ;
}
V_13 = F_4 ( V_667 ,
F_99 ( V_667 ) ) ;
if ( V_639 ) {
V_637 = V_638 ;
} else {
if ( F_137 ( F_11 ( V_641 ,
& V_628 ) ) ) {
V_637 = V_640 ;
if ( V_13 & V_668 )
F_342 () ;
if ( V_13 & V_669 ) {
V_185 . V_632 = 1 ;
F_20 ( V_55 | V_653 ,
L_387 ) ;
}
} else {
F_8 ( L_274
L_388 ) ;
return 1 ;
}
}
if ( V_650 ) {
V_648 = V_649 ;
V_663 |=
V_670 | V_671 ;
} else {
if ( ! V_639 ) {
if ( V_655 ) {
V_648 =
V_651 ;
V_663 |=
V_672 |
V_670 |
V_671 ;
} else {
V_648 = V_652 ;
V_663 |=
V_670 |
V_671 ;
}
}
}
F_17 ( V_55 | V_653 ,
L_389 ,
F_1 ( V_637 != V_662 ||
V_648 != V_656 ) ,
V_637 , V_648 ) ;
if ( ! V_647 ) {
V_648 = V_656 ;
V_663 = 0 ;
F_20 ( V_55 | V_653 ,
L_390 ) ;
}
if ( V_637 != V_662 )
F_348 ( NULL ) ;
if ( V_637 != V_662 ||
V_648 != V_656 ) {
if ( V_185 . V_632 ) {
V_673 [ F_99 ( V_673 ) - 2 ] =
& V_674 . V_121 ;
}
V_70 = F_211 ( & V_509 -> V_105 . V_124 ,
& V_675 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_100 ( & V_676 . V_79 ,
& V_677 ) ;
if ( V_70 < 0 ) {
F_54 ( & V_509 -> V_105 . V_124 ,
& V_675 ) ;
return V_70 ;
}
return 0 ;
} else
return 1 ;
}
static void F_370 ( void )
{
F_17 ( V_290 | V_653 ,
L_391 ) ;
F_54 ( & V_509 -> V_105 . V_124 , & V_675 ) ;
F_103 ( & V_676 . V_79 ,
& V_677 ) ;
F_359 ( & V_658 ) ;
F_250 ( V_443 ) ;
}
static void F_371 ( void )
{
int V_70 ;
if ( ! V_647 )
return;
V_678 = 0 ;
V_70 = F_348 ( & V_678 ) ;
if ( V_70 < 0 )
F_31 ( L_392
L_393 , V_70 ) ;
if ( V_185 . V_629 )
V_678 = 0 ;
}
static void F_372 ( void )
{
T_6 V_679 = 7 ;
bool V_680 = false ;
int V_70 ;
V_185 . V_629 = 0 ;
if ( ! V_647 ||
! V_678 ||
( F_348 ( & V_679 ) < 0 ) )
return;
switch ( V_648 ) {
case V_649 :
V_680 = ( V_678 > V_679 ) ;
break;
case V_651 :
case V_652 :
if ( V_678 != 7 &&
! ( V_678 & V_635 ) )
return;
else
V_680 = ! ( V_679 & V_635 ) &&
( V_679 != V_678 ) ;
break;
default:
return;
}
if ( V_680 ) {
F_31 ( L_394 ,
V_678 ) ;
V_70 = F_352 ( V_678 ) ;
if ( V_70 < 0 )
F_31 ( L_395 , V_70 ) ;
}
}
static int F_373 ( struct V_88 * V_89 )
{
int V_70 ;
T_6 V_30 ;
unsigned int V_643 = 0 ;
switch ( V_637 ) {
case V_638 :
V_70 = F_348 ( & V_30 ) ;
if ( V_70 < 0 )
return V_70 ;
F_83 ( V_89 , L_45
L_317 ,
( V_30 != 0 ) ? L_46 : L_47 , V_30 ) ;
break;
case V_640 :
V_70 = F_348 ( & V_30 ) ;
if ( V_70 < 0 )
return V_70 ;
F_83 ( V_89 , L_45 ,
( V_30 != 0 ) ? L_46 : L_47 ) ;
V_70 = F_349 ( & V_643 ) ;
if ( V_70 < 0 )
return V_70 ;
F_83 ( V_89 , L_396 , V_643 ) ;
if ( V_30 & V_635 )
F_83 ( V_89 , L_397 ) ;
else if ( V_30 & V_631 )
F_83 ( V_89 , L_398 ) ;
else
F_83 ( V_89 , L_317 , V_30 ) ;
break;
case V_662 :
default:
F_83 ( V_89 , L_44 ) ;
}
if ( V_663 & V_670 ) {
F_83 ( V_89 , L_360 ) ;
switch ( V_648 ) {
case V_649 :
F_83 ( V_89 , L_399 ) ;
break;
default:
F_83 ( V_89 , L_400
L_401 ) ;
break;
}
}
if ( V_663 & V_671 )
F_83 ( V_89 , L_48
L_402
L_403 ) ;
if ( V_663 & V_672 )
F_83 ( V_89 , L_404
L_405 ) ;
return 0 ;
}
static int F_374 ( const char * V_158 , int * V_70 )
{
int V_56 ;
if ( F_85 ( V_158 , L_406 ) == 0 )
V_56 = V_631 ;
else if ( ( F_85 ( V_158 , L_407 ) == 0 ) |
( F_85 ( V_158 , L_408 ) == 0 ) )
V_56 = V_635 ;
else if ( sscanf ( V_158 , L_322 , & V_56 ) != 1 )
return 0 ;
* V_70 = F_352 ( V_56 ) ;
if ( * V_70 == - V_49 )
F_8 ( L_409 ,
V_648 ) ;
else if ( ! * V_70 )
F_81 ( L_410 ,
L_324 , V_56 ) ;
return 1 ;
}
static int F_375 ( const char * V_158 , int * V_70 )
{
if ( F_85 ( V_158 , L_49 ) != 0 )
return 0 ;
* V_70 = F_353 () ;
if ( * V_70 == - V_49 )
F_8 ( L_411 ,
V_648 ) ;
else if ( ! * V_70 )
F_81 ( L_410 , L_412 ) ;
return 1 ;
}
static int F_376 ( const char * V_158 , int * V_70 )
{
if ( F_85 ( V_158 , L_50 ) != 0 )
return 0 ;
* V_70 = F_354 () ;
if ( * V_70 == - V_49 )
F_8 ( L_413 ,
V_648 ) ;
else if ( ! * V_70 )
F_81 ( L_410 , L_414 ) ;
return 1 ;
}
static int F_377 ( const char * V_158 , int * V_70 )
{
int V_643 ;
if ( sscanf ( V_158 , L_415 , & V_643 ) != 1 )
return 0 ;
* V_70 = F_355 ( V_643 ) ;
if ( * V_70 == - V_49 )
F_8 ( L_416 ,
V_648 ) ;
else if ( ! * V_70 )
F_81 ( L_410 ,
L_417 , V_643 ) ;
return 1 ;
}
static int F_378 ( const char * V_158 , int * V_70 )
{
int V_681 ;
if ( sscanf ( V_158 , L_418 , & V_681 ) != 1 )
return 0 ;
if ( V_681 < 0 || V_681 > 120 )
* V_70 = - V_92 ;
else {
V_657 = V_681 ;
F_81 ( L_410 ,
L_419 ,
V_681 ) ;
}
return 1 ;
}
static int F_379 ( char * V_125 )
{
char * V_158 ;
int V_70 = 0 ;
while ( ! V_70 && ( V_158 = F_45 ( & V_125 ) ) ) {
if ( ! ( ( V_663 & V_670 ) &&
F_374 ( V_158 , & V_70 ) ) &&
! ( ( V_663 & V_671 ) &&
( F_375 ( V_158 , & V_70 ) ||
F_376 ( V_158 , & V_70 ) ||
F_378 ( V_158 , & V_70 ) ) ) &&
! ( ( V_663 & V_672 ) &&
F_377 ( V_158 , & V_70 ) )
)
V_70 = - V_92 ;
else if ( ! V_70 )
F_356 () ;
}
return V_70 ;
}
static void F_380 ( const unsigned int V_682 )
{
if ( V_536 ) {
switch ( V_682 ) {
case V_683 :
case V_684 :
F_295 () ;
}
}
if ( V_577 ) {
switch ( V_682 ) {
case V_685 :
case V_686 :
case V_687 :
F_320 () ;
}
}
}
static void F_127 ( const unsigned int V_209 )
{
F_380 ( V_688 + V_209 ) ;
}
static T_8 F_381 ( struct V_71 * V_105 ,
struct V_155 * V_121 ,
char * V_125 )
{
return snprintf ( V_125 , V_100 , L_420 , V_83 ) ;
}
static const char * T_1 F_1 ( int V_1 )
{
static char V_689 [] V_690 = L_421 ;
return ( V_1 ) ? & V_689 [ 4 ] : & V_689 [ 0 ] ;
}
static void F_382 ( struct V_64 * V_65 )
{
F_20 ( V_290 , L_422 , V_65 -> V_51 ) ;
F_383 ( & V_65 -> V_691 ) ;
if ( V_65 -> V_76 . V_77 ) {
F_20 ( V_290 ,
L_423 , V_65 -> V_51 ) ;
F_23 ( ! V_65 -> V_68 ) ;
F_384 ( * V_65 -> V_68 -> V_16 ,
V_65 -> V_68 -> type ,
F_25 ) ;
V_65 -> V_76 . V_77 = 0 ;
}
if ( V_65 -> V_76 . V_692 ) {
F_20 ( V_290 ,
L_424 , V_65 -> V_51 ) ;
F_385 ( V_65 -> V_51 , V_693 ) ;
V_65 -> V_76 . V_692 = 0 ;
}
if ( V_65 -> V_76 . V_87 ) {
F_20 ( V_290 ,
L_425 , V_65 -> V_51 ) ;
F_23 ( ! V_65 -> V_68 ) ;
F_386 ( V_65 -> V_68 -> V_79 ) ;
F_36 ( V_65 -> V_68 -> V_79 ) ;
V_65 -> V_68 -> V_79 = NULL ;
V_65 -> V_76 . V_87 = 0 ;
}
if ( V_65 -> V_76 . V_694 && V_65 -> exit ) {
V_65 -> exit () ;
V_65 -> V_76 . V_694 = 0 ;
}
F_20 ( V_55 , L_426 , V_65 -> V_51 ) ;
}
static int T_1 F_387 ( struct V_293 * V_294 )
{
int V_98 ;
struct V_64 * V_65 = V_294 -> V_63 ;
struct V_695 * V_696 ;
F_23 ( V_65 == NULL ) ;
F_388 ( & V_65 -> V_691 ) ;
if ( V_65 -> V_76 . V_697 && ! V_697 )
return 0 ;
F_20 ( V_55 ,
L_427 , V_65 -> V_51 ) ;
if ( V_294 -> V_698 ) {
V_98 = V_294 -> V_698 ( V_294 ) ;
if ( V_98 > 0 )
return 0 ;
if ( V_98 )
return V_98 ;
V_65 -> V_76 . V_694 = 1 ;
}
if ( V_65 -> V_68 ) {
if ( V_65 -> V_68 -> V_60 ) {
V_98 = F_33 ( V_65 ) ;
if ( V_98 )
goto V_699;
}
if ( V_65 -> V_68 -> V_69 ) {
V_98 = F_26 ( V_65 ) ;
if ( V_98 == - V_72 ) {
F_31 ( L_428 ,
V_65 -> V_51 ) ;
V_98 = 0 ;
goto V_699;
}
if ( V_98 < 0 )
goto V_699;
}
}
F_20 ( V_55 ,
L_429 , V_65 -> V_51 ) ;
if ( V_65 -> V_91 ) {
T_19 V_660 = V_294 -> V_700 ;
if ( ! V_660 )
V_660 = V_701 ;
if ( V_65 -> V_99 )
V_660 |= V_702 ;
V_696 = F_389 ( V_65 -> V_51 , V_660 , V_693 ,
& V_703 , V_65 ) ;
if ( ! V_696 ) {
F_8 ( L_430 , V_65 -> V_51 ) ;
V_98 = - V_72 ;
goto V_699;
}
V_65 -> V_76 . V_692 = 1 ;
}
F_390 ( & V_65 -> V_691 , & V_704 ) ;
return 0 ;
V_699:
F_20 ( V_55 ,
L_431 ,
V_65 -> V_51 , V_98 ) ;
F_382 ( V_65 ) ;
return ( V_98 < 0 ) ? V_98 : 0 ;
}
static bool T_2 T_1 F_391 ( const char V_37 )
{
return ( V_37 >= '0' && V_37 <= '9' ) || ( V_37 >= 'A' && V_37 <= 'Z' ) ;
}
static bool T_2 T_1 F_392 ( const char * const V_117 ,
const char V_156 )
{
return V_117 && strlen ( V_117 ) >= 8 &&
F_391 ( V_117 [ 0 ] ) &&
F_391 ( V_117 [ 1 ] ) &&
V_117 [ 2 ] == V_156 &&
( V_117 [ 3 ] == 'T' || V_117 [ 3 ] == 'N' ) &&
F_391 ( V_117 [ 4 ] ) &&
F_391 ( V_117 [ 5 ] ) ;
}
static int T_20 T_1 F_393 (
struct V_705 * V_706 )
{
const struct V_707 * V_105 = NULL ;
char V_708 [ 18 ] ;
char const * V_117 ;
if ( ! V_706 )
return - V_92 ;
memset ( V_706 , 0 , sizeof( * V_706 ) ) ;
if ( F_394 ( L_432 ) )
V_706 -> V_6 = V_15 ;
else if ( F_394 ( L_433 ) )
V_706 -> V_6 = V_14 ;
else
return 0 ;
V_117 = F_395 ( V_709 ) ;
V_706 -> V_710 = F_396 ( V_117 , V_81 ) ;
if ( V_117 && ! V_706 -> V_710 )
return - V_82 ;
if ( ! ( F_392 ( V_706 -> V_710 , 'E' ) ||
F_392 ( V_706 -> V_710 , 'C' ) ) )
return 0 ;
V_706 -> V_10 = V_706 -> V_710 [ 0 ]
| ( V_706 -> V_710 [ 1 ] << 8 ) ;
V_706 -> V_183 = ( V_706 -> V_710 [ 4 ] << 8 )
| V_706 -> V_710 [ 5 ] ;
while ( ( V_105 = F_397 ( V_711 , NULL , V_105 ) ) ) {
if ( sscanf ( V_105 -> V_51 ,
L_434 ,
V_708 ) == 1 ) {
V_708 [ sizeof( V_708 ) - 1 ] = 0 ;
V_708 [ strcspn ( V_708 , L_435 ) ] = 0 ;
V_706 -> V_601 = F_396 ( V_708 , V_81 ) ;
if ( ! V_706 -> V_601 )
return - V_82 ;
if ( F_392 ( V_708 , 'H' ) ) {
V_706 -> V_12 = V_708 [ 0 ]
| ( V_708 [ 1 ] << 8 ) ;
V_706 -> V_184 = ( V_708 [ 4 ] << 8 )
| V_708 [ 5 ] ;
} else {
F_31 ( L_436
L_437 ,
V_708 ) ;
F_31 ( L_107 ,
V_329 ) ;
}
break;
}
}
V_117 = F_395 ( V_712 ) ;
if ( V_117 && ! ( F_398 ( V_117 , L_438 , 8 ) && F_398 ( V_117 , L_439 , 6 ) ) ) {
V_706 -> V_713 = F_396 ( V_117 , V_81 ) ;
if ( ! V_706 -> V_713 )
return - V_82 ;
} else {
V_117 = F_395 ( V_714 ) ;
if ( V_117 && ! ( F_398 ( V_117 , L_439 , 6 ) ) ) {
V_706 -> V_713 = F_396 ( V_117 , V_81 ) ;
if ( ! V_706 -> V_713 )
return - V_82 ;
}
}
V_117 = F_395 ( V_715 ) ;
V_706 -> V_716 = F_396 ( V_117 , V_81 ) ;
if ( V_117 && ! V_706 -> V_716 )
return - V_82 ;
return 0 ;
}
static int T_1 F_399 ( void )
{
int V_717 ;
if ( V_718 )
return - V_72 ;
if ( ! F_6 () && ! F_5 () )
return - V_72 ;
V_717 = ( V_7 . V_713 != NULL ) ||
( V_7 . V_12 != 0 ) ||
F_106 () ;
F_22 ( L_440 , V_719 , & V_424 ) ;
if ( ! V_424 ) {
if ( V_717 )
F_8 ( L_441 ) ;
return - V_72 ;
}
if ( ! V_717 && ! V_720 )
return - V_72 ;
return 0 ;
}
static void T_1 F_400 ( void )
{
F_75 ( L_55 , V_164 , V_165 ) ;
F_75 ( L_420 , V_721 ) ;
F_75 ( L_442 ,
( V_7 . V_710 ) ?
V_7 . V_710 : L_340 ,
( V_7 . V_601 ) ?
V_7 . V_601 : L_340 ) ;
F_23 ( ! V_7 . V_6 ) ;
if ( V_7 . V_713 )
F_75 ( L_443 ,
( V_7 . V_6 == V_15 ) ?
L_432 : ( ( V_7 . V_6 ==
V_14 ) ?
L_439 : L_444 ) ,
V_7 . V_713 ,
( V_7 . V_716 ) ?
V_7 . V_716 : L_340 ) ;
}
static int T_1 F_401 ( const char * V_633 , struct V_722 * V_723 )
{
unsigned int V_42 ;
struct V_64 * V_65 ;
if ( ! V_723 || ! V_723 -> V_51 || ! V_633 )
return - V_92 ;
for ( V_42 = 0 ; V_42 < F_99 ( V_724 ) ; V_42 ++ ) {
V_65 = V_724 [ V_42 ] . V_63 ;
F_402 ( V_65 == NULL ) ;
if ( ! V_65 || ! V_65 -> V_51 )
continue;
if ( strcmp ( V_65 -> V_51 , V_723 -> V_51 ) == 0 && V_65 -> V_99 ) {
if ( strlen ( V_633 ) > sizeof( V_724 [ V_42 ] . V_725 ) - 2 )
return - V_726 ;
strcpy ( V_724 [ V_42 ] . V_725 , V_633 ) ;
strcat ( V_724 [ V_42 ] . V_725 , L_26 ) ;
return 0 ;
}
}
return - V_92 ;
}
static void F_403 ( void )
{
struct V_64 * V_65 , * V_106 ;
V_66 = V_198 ;
F_404 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
F_382 ( V_65 ) ;
}
F_20 ( V_55 , L_445 ) ;
if ( V_207 ) {
if ( V_185 . V_727 )
F_405 ( V_207 ) ;
else
F_406 ( V_207 ) ;
F_36 ( V_211 ) ;
}
if ( V_728 )
F_407 ( V_728 ) ;
if ( V_185 . V_729 )
F_258 ( & V_509 -> V_105 ,
& V_730 ) ;
if ( V_509 )
F_408 ( V_509 ) ;
if ( V_153 )
F_408 ( V_153 ) ;
if ( V_185 . V_731 )
F_102 ( & V_676 . V_79 ) ;
if ( V_185 . V_732 )
F_102 ( & V_733 . V_79 ) ;
if ( V_185 . V_734 )
F_409 ( & V_676 ) ;
if ( V_185 . V_735 )
F_409 ( & V_733 ) ;
if ( V_693 )
F_385 ( V_736 , V_737 ) ;
if ( V_443 )
F_410 ( V_443 ) ;
F_36 ( V_7 . V_710 ) ;
F_36 ( V_7 . V_601 ) ;
F_36 ( V_7 . V_713 ) ;
F_36 ( V_7 . V_716 ) ;
}
static int T_1 F_411 ( void )
{
int V_98 , V_42 ;
V_66 = V_279 ;
V_98 = F_393 ( & V_7 ) ;
if ( V_98 ) {
F_8 ( L_446 , V_98 ) ;
F_403 () ;
return V_98 ;
}
V_98 = F_399 () ;
if ( V_98 ) {
F_403 () ;
return V_98 ;
}
F_400 () ;
F_105 () ;
F_180 ( V_738 ) ;
F_180 ( V_739 ) ;
V_443 = F_412 ( V_740 ) ;
if ( ! V_443 ) {
F_403 () ;
return - V_82 ;
}
V_693 = F_413 ( V_736 , V_737 ) ;
if ( ! V_693 ) {
F_8 ( L_447 V_736 L_271 ) ;
F_403 () ;
return - V_72 ;
}
V_98 = F_414 ( & V_733 ) ;
if ( V_98 ) {
F_8 ( L_448 ) ;
F_403 () ;
return V_98 ;
}
V_185 . V_735 = 1 ;
V_98 = F_414 ( & V_676 ) ;
if ( V_98 ) {
F_8 ( L_449 ) ;
F_403 () ;
return V_98 ;
}
V_185 . V_734 = 1 ;
V_98 = F_98 ( & V_733 . V_79 ) ;
if ( ! V_98 ) {
V_185 . V_732 = 1 ;
V_98 = F_98 (
& V_676 . V_79 ) ;
}
if ( V_98 ) {
F_8 ( L_450 ) ;
F_403 () ;
return V_98 ;
}
V_185 . V_731 = 1 ;
V_153 = F_415 ( V_741 , - 1 ,
NULL , 0 ) ;
if ( F_145 ( V_153 ) ) {
V_98 = F_302 ( V_153 ) ;
V_153 = NULL ;
F_8 ( L_451 ) ;
F_403 () ;
return V_98 ;
}
V_509 = F_415 (
V_742 ,
- 1 , NULL , 0 ) ;
if ( F_145 ( V_509 ) ) {
V_98 = F_302 ( V_509 ) ;
V_509 = NULL ;
F_8 ( L_452 ) ;
F_403 () ;
return V_98 ;
}
V_98 = F_256 ( & V_509 -> V_105 ,
& V_730 ) ;
if ( V_98 ) {
F_8 ( L_453 ) ;
F_403 () ;
return V_98 ;
}
V_185 . V_729 = 1 ;
V_728 = F_416 ( & V_509 -> V_105 ) ;
if ( F_145 ( V_728 ) ) {
V_98 = F_302 ( V_728 ) ;
V_728 = NULL ;
F_8 ( L_454 ) ;
F_403 () ;
return V_98 ;
}
F_181 ( & V_206 ) ;
V_207 = F_417 () ;
if ( ! V_207 ) {
F_8 ( L_455 ) ;
F_403 () ;
return - V_82 ;
} else {
V_207 -> V_51 = L_456 ;
V_207 -> V_743 = V_741 L_457 ;
V_207 -> V_143 . V_744 = V_745 ;
V_207 -> V_143 . V_6 = V_7 . V_6 ;
V_207 -> V_143 . V_746 = V_747 ;
V_207 -> V_143 . V_748 = V_749 ;
V_207 -> V_105 . V_52 = & V_153 -> V_105 ;
}
F_299 () ;
for ( V_42 = 0 ; V_42 < F_99 ( V_724 ) ; V_42 ++ ) {
V_98 = F_387 ( & V_724 [ V_42 ] ) ;
if ( V_98 >= 0 && * V_724 [ V_42 ] . V_725 )
V_98 = V_724 [ V_42 ] . V_63 -> V_99 ( V_724 [ V_42 ] . V_725 ) ;
if ( V_98 < 0 ) {
F_403 () ;
return V_98 ;
}
}
V_66 = V_67 ;
V_98 = F_418 ( V_207 ) ;
if ( V_98 < 0 ) {
F_8 ( L_458 ) ;
F_403 () ;
return V_98 ;
} else {
V_185 . V_727 = 1 ;
}
return 0 ;
}
