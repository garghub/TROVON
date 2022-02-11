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
struct V_59 * V_60 ;
if ( ! strcmp ( V_57 , L_13 ) ) {
if ( F_22 ( V_16 , & V_60 ) )
return V_41 ;
if ( strcmp ( V_61 , F_23 ( V_60 ) ) )
return V_41 ;
}
* ( T_3 * ) V_58 = V_16 ;
return V_62 ;
}
static void T_1 F_24 ( const char * V_51 ,
const char * V_63 ,
T_3 * V_16 )
{
T_4 V_30 ;
T_3 V_64 ;
F_25 ( ! V_51 || ! V_16 ) ;
F_17 ( V_55 ,
L_14 ,
V_51 , V_63 ? V_63 : L_15 ) ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_30 = F_26 ( V_63 , F_21 ,
( void * ) V_51 , & V_64 ) ;
* V_16 = NULL ;
if ( F_19 ( V_30 ) ) {
* V_16 = V_64 ;
F_20 ( V_55 ,
L_16 , V_51 ) ;
} else {
F_17 ( V_55 ,
L_17 ,
V_51 , F_10 ( V_30 ) ) ;
}
}
static void F_27 ( T_3 V_16 , T_7 V_65 , void * V_66 )
{
struct V_67 * V_68 = V_66 ;
if ( V_69 != V_70 )
return;
if ( ! V_68 || ! V_68 -> V_71 || ! V_68 -> V_71 -> V_72 )
return;
V_68 -> V_71 -> V_72 ( V_68 , V_65 ) ;
}
static int T_1 F_28 ( struct V_67 * V_68 )
{
T_4 V_30 ;
int V_73 ;
F_25 ( ! V_68 -> V_71 ) ;
if ( ! * V_68 -> V_71 -> V_16 )
return 0 ;
F_17 ( V_55 ,
L_18 , V_68 -> V_51 ) ;
V_73 = F_22 ( * V_68 -> V_71 -> V_16 , & V_68 -> V_71 -> V_74 ) ;
if ( V_73 < 0 ) {
F_8 ( L_19 , V_68 -> V_51 , V_73 ) ;
return - V_75 ;
}
V_68 -> V_71 -> V_74 -> V_76 = V_68 ;
sprintf ( F_29 ( V_68 -> V_71 -> V_74 ) , L_20 ,
V_77 ,
V_68 -> V_51 ) ;
V_30 = F_30 ( * V_68 -> V_71 -> V_16 ,
V_68 -> V_71 -> type , F_27 , V_68 ) ;
if ( F_31 ( V_30 ) ) {
if ( V_30 == V_78 ) {
F_32 ( L_21
L_22 , V_68 -> V_51 ) ;
} else {
F_8 ( L_23 ,
V_68 -> V_51 , F_10 ( V_30 ) ) ;
}
return - V_75 ;
}
V_68 -> V_79 . V_80 = 1 ;
return 0 ;
}
static int T_1 F_33 ( struct V_59 * V_74 )
{
return 0 ;
}
static int T_1 F_34 ( struct V_67 * V_68 )
{
int V_73 ;
F_20 ( V_55 ,
L_24 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
V_68 -> V_71 -> V_81 = F_35 ( sizeof( struct V_82 ) , V_83 ) ;
if ( ! V_68 -> V_71 -> V_81 ) {
F_8 ( L_25 ) ;
return - V_84 ;
}
sprintf ( V_68 -> V_71 -> V_81 -> V_51 , L_26 , V_85 , V_68 -> V_51 ) ;
V_68 -> V_71 -> V_81 -> V_86 = V_68 -> V_71 -> V_63 ;
V_68 -> V_71 -> V_81 -> V_87 . V_88 = & F_33 ;
V_73 = F_36 ( V_68 -> V_71 -> V_81 ) ;
if ( V_73 < 0 ) {
F_8 ( L_27 ,
V_68 -> V_51 , V_73 ) ;
F_37 ( V_68 -> V_71 -> V_81 ) ;
V_68 -> V_71 -> V_81 = NULL ;
} else if ( ! V_73 )
V_68 -> V_79 . V_89 = 1 ;
return V_73 ;
}
static int F_38 ( struct V_90 * V_91 , void * V_44 )
{
struct V_67 * V_68 = V_91 -> V_92 ;
if ( ! V_68 || ! V_68 -> V_93 )
return - V_94 ;
return V_68 -> V_93 ( V_91 ) ;
}
static int F_39 ( struct V_95 * V_95 , struct V_96 * V_96 )
{
return F_40 ( V_96 , F_38 , F_41 ( V_95 ) ) ;
}
static T_8 F_42 ( struct V_96 * V_96 ,
const char T_9 * V_97 ,
T_10 V_35 , T_11 * V_98 )
{
struct V_67 * V_68 = F_41 ( F_43 ( V_96 ) ) ;
char * V_99 ;
int V_100 ;
if ( ! V_68 || ! V_68 -> V_101 )
return - V_94 ;
if ( V_35 > V_102 - 2 )
return - V_94 ;
V_99 = F_44 ( V_35 + 2 , V_83 ) ;
if ( ! V_99 )
return - V_84 ;
if ( F_45 ( V_99 , V_97 , V_35 ) ) {
F_37 ( V_99 ) ;
return - V_103 ;
}
V_99 [ V_35 ] = 0 ;
strcat ( V_99 , L_28 ) ;
V_100 = V_68 -> V_101 ( V_99 ) ;
if ( V_100 == 0 )
V_100 = V_35 ;
F_37 ( V_99 ) ;
return V_100 ;
}
static char * F_46 ( char * * V_104 )
{
char * V_105 = * V_104 ;
char * V_106 ;
while ( ( V_106 = strchr ( V_105 , ',' ) ) && V_106 == V_105 )
V_105 = V_106 + 1 ;
if ( ! V_106 )
return NULL ;
* V_106 = 0 ;
* V_104 = V_106 + 1 ;
return V_105 ;
}
static int F_47 ( struct V_74 * V_60 )
{
struct V_67 * V_68 , * V_107 ;
F_48 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if ( V_68 -> V_108 )
( V_68 -> V_108 ) ( ) ;
}
return 0 ;
}
static int F_49 ( struct V_74 * V_60 )
{
struct V_67 * V_68 , * V_107 ;
F_48 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if ( V_68 -> V_109 )
( V_68 -> V_109 ) ( ) ;
}
return 0 ;
}
static void F_50 ( struct V_110 * V_111 )
{
struct V_67 * V_68 , * V_107 ;
F_48 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
if ( V_68 -> V_112 )
( V_68 -> V_112 ) ( ) ;
}
}
static struct V_113 * F_51 ( unsigned int V_114 ,
const char * V_51 )
{
struct V_115 * V_116 ;
if ( V_114 == 0 )
return NULL ;
V_116 = F_35 ( sizeof( struct V_115 ) +
V_114 * sizeof( struct V_117 * ) ,
V_83 ) ;
if ( ! V_116 )
return NULL ;
V_116 -> V_118 . V_114 = V_114 ;
V_116 -> V_118 . V_119 . V_120 = & V_116 -> V_121 ;
V_116 -> V_118 . V_119 . V_51 = V_51 ;
return & V_116 -> V_118 ;
}
static int F_52 ( struct V_113 * V_118 , struct V_117 * V_122 )
{
if ( ! V_118 || ! V_122 )
return - V_94 ;
if ( V_118 -> V_123 >= V_118 -> V_114 )
return - V_84 ;
V_118 -> V_119 . V_120 [ V_118 -> V_123 ] = V_122 ;
V_118 -> V_123 ++ ;
return 0 ;
}
static int F_53 ( struct V_113 * V_118 ,
struct V_117 * * V_122 ,
unsigned int V_35 )
{
int V_42 , V_17 ;
for ( V_42 = 0 ; V_42 < V_35 ; V_42 ++ ) {
V_17 = F_52 ( V_118 , V_122 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static void F_54 ( struct V_113 * V_118 , struct V_124 * V_125 )
{
F_55 ( V_125 , & V_118 -> V_119 ) ;
F_56 ( V_118 ) ;
}
static int F_57 ( const char * V_126 ,
unsigned long V_127 , unsigned long * V_38 )
{
char * V_128 ;
* V_38 = F_58 ( F_59 ( V_126 ) , & V_128 , 0 ) ;
V_128 = F_59 ( V_128 ) ;
if ( * V_128 || * V_38 > V_127 )
return - V_94 ;
return 0 ;
}
static void F_60 ( void )
{
if ( F_7 ( V_129 , NULL , L_29 , L_30 , 0 ) )
F_32 ( L_31 ) ;
}
static void F_61 ( const char * const V_2 ,
const char * const V_130 )
{
F_2 ( L_32 ) ;
F_62 ( L_33
L_34 ,
V_2 , V_130 ) ;
}
static int F_63 ( const struct V_131 * V_132 )
{
int V_30 ;
if ( ! V_132 )
return - V_75 ;
V_30 = ( V_132 -> V_87 -> V_133 ) ( ) ;
if ( V_30 < 0 )
return V_30 ;
F_64 ( V_132 -> V_134 ,
( V_30 == V_135 ) ) ;
return V_30 ;
}
static void F_65 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_136 ; V_42 ++ )
F_63 ( V_137 [ V_42 ] ) ;
}
static void F_66 ( bool V_138 )
{
unsigned int V_42 ;
struct V_131 * V_132 ;
for ( V_42 = 0 ; V_42 < V_136 ; V_42 ++ ) {
V_132 = V_137 [ V_42 ] ;
if ( V_132 ) {
if ( F_67 ( V_132 -> V_134 ,
V_138 ) ) {
}
}
}
}
static bool F_68 ( void )
{
int V_17 = F_69 () ;
int V_139 ;
if ( V_17 < 0 )
return false ;
V_139 = ( V_17 == V_135 ) ;
F_66 ( V_139 ) ;
return V_139 ;
}
static int F_70 ( void * V_66 , bool V_138 )
{
struct V_131 * V_132 = V_66 ;
int V_17 ;
F_20 ( V_140 ,
L_35 ,
V_138 ? L_36 : L_37 ) ;
V_17 = ( V_132 -> V_87 -> V_141 ) ( V_138 ?
V_135 : V_142 ) ;
F_63 ( V_132 ) ;
return ( V_17 < 0 ) ? V_17 : 0 ;
}
static int T_1 F_71 ( const enum V_143 V_144 ,
const struct V_145 * V_146 ,
const enum V_147 V_148 ,
const char * V_51 ,
const bool V_149 )
{
struct V_131 * V_150 ;
int V_17 ;
bool V_151 = false ;
bool V_152 ;
int V_153 ;
F_25 ( V_144 >= V_136 || V_137 [ V_144 ] ) ;
V_150 = F_35 ( sizeof( struct V_131 ) , V_83 ) ;
if ( V_150 )
V_150 -> V_134 = F_72 ( V_51 ,
& V_154 -> V_60 ,
V_148 ,
& V_155 ,
V_150 ) ;
if ( ! V_150 || ! V_150 -> V_134 ) {
F_8 ( L_38 ) ;
F_37 ( V_150 ) ;
return - V_84 ;
}
V_150 -> V_144 = V_144 ;
V_150 -> V_87 = V_146 ;
V_153 = ( V_146 -> V_133 ) ( ) ;
if ( V_153 < 0 ) {
F_8 ( L_39 ,
V_51 , V_153 ) ;
} else {
V_151 = ( V_153 == V_135 ) ;
if ( V_149 ) {
F_73 ( V_150 -> V_134 , V_151 ) ;
}
}
V_152 = F_68 () ;
F_67 ( V_150 -> V_134 , V_152 ) ;
V_17 = F_74 ( V_150 -> V_134 ) ;
if ( V_17 < 0 ) {
F_8 ( L_40 , V_51 , V_17 ) ;
F_75 ( V_150 -> V_134 ) ;
F_37 ( V_150 ) ;
return V_17 ;
}
V_137 [ V_144 ] = V_150 ;
F_76 ( L_41 ,
V_51 , ( V_151 || V_152 ) ? L_1 : L_42 ) ;
return 0 ;
}
static void F_77 ( const enum V_143 V_144 )
{
struct V_131 * V_132 ;
F_25 ( V_144 >= V_136 ) ;
V_132 = V_137 [ V_144 ] ;
if ( V_132 ) {
F_78 ( V_132 -> V_134 ) ;
F_75 ( V_132 -> V_134 ) ;
V_137 [ V_144 ] = NULL ;
F_37 ( V_132 ) ;
}
}
static void F_79 ( const char * const V_2 )
{
F_61 ( V_2 ,
L_43 ) ;
}
static T_8 F_80 ( const enum V_143 V_144 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_30 ;
F_79 ( V_122 -> V_122 . V_51 ) ;
if ( F_68 () ) {
V_30 = V_135 ;
} else {
V_30 = F_63 ( V_137 [ V_144 ] ) ;
if ( V_30 < 0 )
return V_30 ;
}
return snprintf ( V_126 , V_102 , L_44 ,
( V_30 == V_142 ) ? 1 : 0 ) ;
}
static T_8 F_81 ( const enum V_143 V_144 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 ;
F_79 ( V_122 -> V_122 . V_51 ) ;
if ( F_57 ( V_126 , 1 , & V_157 ) )
return - V_94 ;
F_82 ( V_122 -> V_122 . V_51 , L_45 , V_157 ) ;
if ( F_68 () && ! ! V_157 )
return - V_158 ;
V_17 = V_137 [ V_144 ] -> V_87 -> V_141 ( ( ! ! V_157 ) ?
V_142 : V_135 ) ;
F_63 ( V_137 [ V_144 ] ) ;
return ( V_17 < 0 ) ? V_17 : V_35 ;
}
static int F_83 ( const enum V_143 V_144 , struct V_90 * V_91 )
{
if ( V_144 >= V_136 )
F_84 ( V_91 , L_46 ) ;
else {
int V_30 ;
if ( F_68 () ) {
V_30 = V_135 ;
} else {
V_30 = F_63 (
V_137 [ V_144 ] ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_84 ( V_91 , L_47 ,
( V_30 == V_142 ) ?
L_48 : L_49 ) ;
F_84 ( V_91 , L_50 ) ;
}
return 0 ;
}
static int F_85 ( const enum V_143 V_144 , char * V_126 )
{
char * V_159 ;
int V_30 = - 1 ;
int V_17 = 0 ;
if ( V_144 >= V_136 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_51 ) == 0 )
V_30 = V_142 ;
else if ( F_86 ( V_159 , L_52 ) == 0 )
V_30 = V_135 ;
else
return - V_94 ;
}
if ( V_30 != - 1 ) {
F_82 ( L_53 , L_54 ,
( V_30 == V_142 ) ?
L_51 : L_52 ,
V_160 [ V_144 ] ) ;
V_17 = ( V_137 [ V_144 ] -> V_87 -> V_141 ) ( V_30 ) ;
F_63 ( V_137 [ V_144 ] ) ;
}
return V_17 ;
}
static T_8 F_87 (
struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 , V_163 ) ;
}
static T_8 F_88 ( struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_56 , V_164 ) ;
}
static T_8 F_89 ( struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 0xffff , & V_157 ) )
return - V_94 ;
V_164 = V_157 ;
return V_35 ;
}
static T_8 F_90 ( struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_57 ,
V_165 , V_166 ) ;
}
static T_8 F_91 ( struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , ! ! V_167 ) ;
}
static T_8 F_92 ( struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 1 , & V_157 ) )
return - V_94 ;
if ( V_167 != ! ! V_157 ) {
V_167 = ! ! V_157 ;
F_66 ( ! V_157 ) ;
}
return V_35 ;
}
static T_8 F_93 (
struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , ! ! V_168 ) ;
}
static T_8 F_94 (
struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 1 , & V_157 ) )
return - V_94 ;
V_168 = ! ! V_157 ;
return V_35 ;
}
static T_8 F_95 (
struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , ! ! V_169 ) ;
}
static T_8 F_96 (
struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 1 , & V_157 ) )
return - V_94 ;
V_169 = ! ! V_157 ;
return V_35 ;
}
static T_8 F_97 (
struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , ! ! V_170 ) ;
}
static T_8 F_98 (
struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 1 , & V_157 ) )
return - V_94 ;
V_170 = ! ! V_157 ;
return V_35 ;
}
static int T_1 F_99 ( struct V_161 * V_162 )
{
int V_42 , V_17 ;
V_42 = 0 ;
V_17 = 0 ;
while ( ! V_17 && V_42 < F_100 ( V_171 ) ) {
V_17 = F_101 ( V_162 , V_171 [ V_42 ] ) ;
V_42 ++ ;
}
#ifdef F_102
if ( ! V_17 && V_172 )
V_17 = F_101 ( V_162 , & V_173 ) ;
if ( ! V_17 && V_174 )
V_17 = F_101 ( V_162 , & V_175 ) ;
if ( ! V_17 && V_176 )
V_17 = F_101 ( V_162 , & V_177 ) ;
if ( ! V_17 && V_178 )
V_17 = F_101 ( V_162 , & V_179 ) ;
#endif
return V_17 ;
}
static void F_103 ( struct V_161 * V_162 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_100 ( V_171 ) ; V_42 ++ )
F_104 ( V_162 , V_171 [ V_42 ] ) ;
#ifdef F_105
F_104 ( V_162 , & V_173 ) ;
F_104 ( V_162 , & V_175 ) ;
F_104 ( V_162 , & V_177 ) ;
F_104 ( V_162 , & V_179 ) ;
#endif
}
static void T_1 F_106 ( void )
{
unsigned long V_180 ;
T_12 V_181 , V_182 ;
V_180 = F_4 ( V_183 ,
F_100 ( V_183 ) ) ;
if ( ! V_180 )
return;
V_182 = V_180 & 0xffffU ;
V_181 = ( V_180 >> 16 ) & 0xffffU ;
if ( ( V_182 > V_7 . V_184 ) ||
( V_181 > V_7 . V_185 &&
V_181 != V_8 ) ) {
F_62 ( L_58 ) ;
F_62 ( L_59
L_60 ) ;
}
}
static bool T_1 F_107 ( void )
{
return F_4 ( V_183 ,
F_100 ( V_183 ) ) != 0 ;
}
static int F_108 ( struct V_90 * V_91 )
{
F_84 ( V_91 , L_61 , V_165 ) ;
F_84 ( V_91 , L_62 , V_166 ) ;
return 0 ;
}
static int F_69 ( void )
{
int V_30 ;
if ( ! V_186 . V_187 )
return - V_75 ;
#ifdef F_102
if ( V_172 )
return ( V_167 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_63 , L_64 ) )
return - V_50 ;
return ( V_30 ) ? V_142 : V_135 ;
}
static int F_109 ( int * V_30 )
{
int V_118 ;
if ( ! F_7 ( V_129 , & V_118 , L_65 , L_64 ) )
return - V_50 ;
* V_30 = ( ( V_118 & V_188 ) != 0 ) ;
return 0 ;
}
static int F_110 ( void )
{
if ( V_186 . V_189 ) {
T_7 V_91 = 0 ;
if ( ! F_7 ( V_129 , & V_91 , L_66 , L_64 ) )
return - V_50 ;
V_190 = V_91 ;
} else {
V_190 = V_191 ;
}
V_192 &= ( V_190 | V_193 ) ;
return 0 ;
}
void static F_111 ( void )
{
const T_7 V_194 = V_195 &
~ ( V_190 | V_193 ) &
( V_191 | V_196 ) ;
if ( V_194 )
F_32 ( L_67 , V_194 ) ;
}
static int F_112 ( T_7 V_197 )
{
int V_42 ;
int V_73 = 0 ;
const T_7 V_198 = V_197 & ~ V_193 ;
if ( V_186 . V_189 ) {
for ( V_42 = 0 ; V_42 < 32 ; V_42 ++ ) {
if ( ! F_7 ( V_129 ,
NULL , L_68 , L_8 , V_42 + 1 ,
! ! ( V_197 & ( 1 << V_42 ) ) ) ) {
V_73 = - V_50 ;
break;
}
}
}
if ( ! F_110 () && ! V_73 && ( V_198 & ~ V_190 ) ) {
F_32 ( L_69
L_70 ,
V_198 , V_190 ) ;
}
if ( V_69 != V_199 )
F_111 () ;
return V_73 ;
}
static int F_113 ( const T_7 V_197 )
{
int V_73 ;
if ( ! V_200 . V_201 &&
( V_197 == 0xffff || V_197 == 0xffffff ||
V_197 == 0xffffffff ) ) {
V_200 . V_201 = 1 ;
F_32 ( L_71
L_72 , V_197 ) ;
F_32 ( L_73
L_74
L_75 ) ;
}
V_73 = F_112 ( ( V_197 | V_195 ) & ~ V_193 ) ;
V_192 = V_197 & ( V_190 | V_193 ) ;
return V_73 ;
}
static int F_114 ( const T_7 V_197 )
{
int V_73 ;
if ( ! V_186 . V_202 ) {
V_195 = V_197 ;
return 0 ;
}
F_115 ( & V_203 ) ;
T_13
V_195 = V_197 ;
#ifdef F_116
V_193 |= ( V_197 & ~ V_191 ) ;
#endif
T_14
V_73 = F_112 ( ( V_190 | V_195 ) &
~ V_193 ) ;
F_117 ( true ) ;
F_118 ( & V_203 ) ;
return V_73 ;
}
static int F_119 ( int * V_30 )
{
if ( ! F_7 ( V_129 , V_30 , L_76 , L_64 ) )
return - V_50 ;
return 0 ;
}
static int F_120 ( bool V_204 )
{
if ( ! F_7 ( V_129 , NULL , L_77 , L_9 , V_204 ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static void F_121 ( void )
{
int V_205 ;
if ( V_186 . V_206 &&
! F_109 ( & V_205 ) ) {
F_115 ( & V_207 ) ;
F_122 ( V_208 ,
V_209 , ! ! V_205 ) ;
F_123 ( V_208 ) ;
F_118 ( & V_207 ) ;
}
}
static void F_124 ( const unsigned int V_210 )
{
const unsigned int V_211 = V_212 [ V_210 ] ;
if ( V_211 != V_213 ) {
F_115 ( & V_207 ) ;
F_125 ( V_208 , V_214 , V_215 , V_210 ) ;
F_126 ( V_208 , V_211 , 1 ) ;
F_123 ( V_208 ) ;
F_125 ( V_208 , V_214 , V_215 , V_210 ) ;
F_126 ( V_208 , V_211 , 0 ) ;
F_123 ( V_208 ) ;
F_118 ( & V_207 ) ;
}
}
static void F_127 ( const unsigned int V_210 )
{
F_128 ( V_210 ) ;
if ( V_192 & ( 1 << V_210 ) )
F_124 ( V_210 ) ;
}
static void F_129 ( unsigned int V_210 )
{
F_127 ( V_210 ) ;
}
static void F_130 ( struct V_216 * V_217 , const T_7 V_91 )
{
T_6 V_218 ;
if ( V_91 & V_219 ) {
V_218 = F_131 ( V_220 ) ;
V_217 -> V_221 = ! ! ( V_218 & V_222 ) ;
V_217 -> V_223 = ! ! ( V_218 & V_224 ) ;
V_217 -> V_225 = ! ! ( V_218 & V_226 ) ;
V_217 -> V_227 = ! ! ( V_218 & V_228 ) ;
}
if ( V_91 & V_229 ) {
V_218 = F_131 ( V_230 ) ;
V_217 -> V_231 = ! ! ( V_218 & V_232 ) ;
}
if ( V_91 & V_233 ) {
V_218 = F_131 ( V_234 ) ;
V_217 -> V_235 =
! ! ( V_218 & V_236 ) ;
}
if ( V_91 & V_237 ) {
V_218 = F_131 ( V_238 ) ;
V_217 -> V_239 = ( V_218 & V_240 )
>> V_241 ;
V_217 -> V_242 =
! ! ( V_218 & V_243 ) ;
}
if ( V_91 & V_244 ) {
V_218 = F_131 ( V_245 ) ;
V_217 -> V_246 = ( V_218 & V_247 )
>> V_248 ;
V_217 -> V_249 = ! ! ( V_218 & V_250 ) ;
V_217 -> V_251 = ! ! ( V_218 & V_252 ) ;
}
}
void F_132 ( const unsigned int V_253 ,
const unsigned int V_254 )
{
unsigned int V_42 = V_253 ;
while ( V_42 > V_254 ) {
F_133 ( V_255 ) ;
V_42 -- ;
}
while ( V_42 < V_254 ) {
F_133 ( V_256 ) ;
V_42 ++ ;
}
}
void F_134 ( const unsigned int V_257 ,
const unsigned int V_258 )
{
unsigned int V_42 = V_257 ;
while ( V_42 > V_258 ) {
F_133 ( V_259 ) ;
V_42 -- ;
}
while ( V_42 < V_258 ) {
F_133 ( V_260 ) ;
V_42 ++ ;
}
}
static int F_135 ( void * V_66 )
{
struct V_216 V_118 [ 2 ] ;
T_7 V_261 , V_262 ;
unsigned int V_263 , V_264 ;
unsigned long V_157 ;
unsigned int V_265 ;
unsigned int V_266 ;
bool V_267 ;
if ( V_69 == V_199 )
goto exit;
F_136 () ;
V_264 = 0 ;
V_263 = 1 ;
V_157 = 0 ;
F_115 ( & V_268 ) ;
V_265 = V_269 ;
V_261 = V_193 ;
V_262 = V_193 &
( V_195 | V_192 ) ;
V_266 = V_270 ;
F_118 ( & V_268 ) ;
F_130 ( & V_118 [ V_264 ] , V_261 ) ;
while ( ! F_137 () ) {
if ( V_157 == 0 ) {
if ( F_138 ( V_266 ) )
V_157 = 1000 / V_266 ;
else
V_157 = 100 ;
}
V_157 = F_139 ( V_157 ) ;
if ( F_140 ( F_141 ( & V_267 ) ) )
break;
if ( V_157 > 0 && ! V_267 )
continue;
F_115 ( & V_268 ) ;
if ( V_267 || V_269 != V_265 ) {
V_263 = V_264 ;
V_157 = 0 ;
V_265 = V_269 ;
}
V_261 = V_193 ;
V_262 = V_193 &
( V_195 | V_192 ) ;
V_266 = V_270 ;
F_118 ( & V_268 ) ;
if ( F_138 ( V_261 ) ) {
F_130 ( & V_118 [ V_263 ] , V_261 ) ;
if ( F_138 ( V_263 != V_264 ) ) {
F_142 ( & V_118 [ V_264 ] , & V_118 [ V_263 ] ,
V_262 ) ;
}
}
V_264 = V_263 ;
V_263 ^= 1 ;
}
exit:
return 0 ;
}
static void F_143 ( void )
{
if ( V_271 ) {
F_144 ( V_271 ) ;
V_271 = NULL ;
}
}
static void F_117 ( const bool V_272 )
{
const T_7 V_273 = V_195 & V_193 ;
const T_7 V_274 = V_192 & V_193 ;
if ( V_270 > 0 &&
( V_273 ||
( V_274 && V_208 -> V_275 > 0 ) ) ) {
if ( ! V_271 ) {
V_271 = F_145 ( F_135 ,
NULL , V_276 ) ;
if ( F_146 ( V_271 ) ) {
V_271 = NULL ;
F_8 ( L_78
L_79 ) ;
}
}
} else {
F_143 () ;
if ( V_272 && ( V_273 || V_274 ) &&
V_270 == 0 ) {
F_32 ( L_80
L_81
L_82 ,
V_274 , V_273 ) ;
}
}
}
static void F_147 ( const bool V_272 )
{
F_115 ( & V_203 ) ;
F_117 ( V_272 ) ;
F_118 ( & V_203 ) ;
}
static void F_148 ( unsigned int V_277 )
{
if ( ! V_277 )
F_143 () ;
V_270 = V_277 ;
}
static void F_117 ( const bool V_278 )
{
}
static void F_147 ( const bool V_278 )
{
}
static int F_149 ( struct V_279 * V_60 )
{
switch ( V_69 ) {
case V_280 :
case V_70 :
F_147 ( false ) ;
return 0 ;
case V_199 :
return - V_281 ;
}
F_150 () ;
return - V_281 ;
}
static void F_151 ( struct V_279 * V_60 )
{
if ( V_69 != V_199 &&
! ( V_193 & V_195 ) )
F_147 ( false ) ;
}
static T_8 F_152 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_30 ;
F_61 ( L_83 ,
L_84 ) ;
V_17 = F_119 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_44 , V_30 ) ;
}
static T_8 F_153 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
F_61 ( L_83 ,
L_85 ) ;
if ( F_57 ( V_126 , 1 , & V_157 ) )
return - V_94 ;
if ( V_157 == 0 )
return - V_158 ;
return V_35 ;
}
static T_8 F_154 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 , V_192 ) ;
}
static T_8 F_155 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 ;
if ( F_57 ( V_126 , 0xffffffffUL , & V_157 ) )
return - V_94 ;
if ( F_156 ( & V_203 ) )
return - V_282 ;
V_17 = F_113 ( V_157 ) ;
#ifdef F_116
F_117 ( true ) ;
#endif
F_118 ( & V_203 ) ;
F_82 ( L_86 , L_87 , V_157 ) ;
return ( V_17 ) ? V_17 : V_35 ;
}
static T_8 F_157 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return sprintf ( V_126 , L_88 ) ;
}
static T_8 F_158 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
F_61 ( L_89 ,
L_90 ) ;
return snprintf ( V_126 , V_102 , L_55 , V_283 ) ;
}
static T_8 F_159 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 ,
V_191 | V_193 ) ;
}
static T_8 F_160 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 ,
( V_191 | V_193 )
& ~ V_284 ) ;
}
static T_8 F_161 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 , V_193 ) ;
}
static T_8 F_162 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
T_7 V_285 ;
int V_73 ;
if ( F_57 ( V_126 , 0xffffffffUL , & V_157 ) ||
( ( V_157 & ~ V_196 ) != 0 ) )
return - V_94 ;
if ( F_156 ( & V_203 ) )
return - V_282 ;
T_13
V_193 = V_157 ;
T_14
V_73 = F_112 ( ( V_192 | V_195 ) &
~ V_193 ) ;
F_117 ( true ) ;
V_285 = V_195 & ~ ( V_190 & V_191 )
& ~ V_193 & V_196 ;
F_118 ( & V_203 ) ;
if ( V_73 < 0 )
F_8 ( L_91
L_92 ) ;
if ( V_285 )
F_32 ( L_91
L_93 ,
V_285 ) ;
F_82 ( L_94 , L_87 , V_157 ) ;
return ( V_73 < 0 ) ? V_73 : V_35 ;
}
static T_8 F_163 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_270 ) ;
}
static T_8 F_164 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 25 , & V_157 ) )
return - V_94 ;
if ( F_156 ( & V_203 ) )
return - V_282 ;
F_148 ( V_157 ) ;
F_117 ( true ) ;
F_118 ( & V_203 ) ;
F_82 ( L_95 , L_96 , V_157 ) ;
return V_35 ;
}
static T_8 F_165 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
V_17 = F_69 () ;
if ( V_17 < 0 )
return V_17 ;
F_66 ( ( V_17 == V_135 ) ) ;
return snprintf ( V_126 , V_102 , L_44 ,
( V_17 == V_135 ) ? 0 : 1 ) ;
}
static void F_166 ( void )
{
if ( V_186 . V_187 )
F_167 ( & V_154 -> V_60 . V_125 , NULL ,
L_97 ) ;
}
static T_8 F_168 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_118 ;
V_17 = F_109 ( & V_118 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_44 , ! ! V_118 ) ;
}
static void F_169 ( void )
{
if ( V_186 . V_206 )
F_167 ( & V_154 -> V_60 . V_125 , NULL ,
L_98 ) ;
}
static T_8 F_170 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_286 ) ;
}
static void F_171 ( void )
{
F_167 ( & V_154 -> V_60 . V_125 , NULL ,
L_99 ) ;
}
static T_8 F_172 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_287 ) ;
}
static void F_173 ( void )
{
F_167 ( & V_154 -> V_60 . V_125 , NULL ,
L_100 ) ;
}
static void F_174 ( void )
{
int V_288 ;
V_288 = F_69 () ;
if ( V_288 == V_135 )
F_66 ( true ) ;
F_65 () ;
if ( V_288 == V_142 )
F_66 ( false ) ;
if ( ! ( V_288 < 0 ) ) {
F_115 ( & V_207 ) ;
F_122 ( V_208 ,
V_289 , ( V_288 > 0 ) ) ;
F_123 ( V_208 ) ;
F_118 ( & V_207 ) ;
}
F_166 () ;
}
static void F_175 ( void )
{
#ifdef F_116
F_115 ( & V_203 ) ;
F_143 () ;
F_118 ( & V_203 ) ;
#endif
if ( V_290 )
F_54 ( V_290 , & V_154 -> V_60 . V_125 ) ;
F_20 ( V_291 | V_292 ,
L_101 ) ;
if ( ( ( V_186 . V_189 &&
F_112 ( V_283 ) ) |
F_120 ( false ) ) != 0 )
F_8 ( L_102
L_103 ) ;
}
static void T_1 F_176 ( const unsigned int V_210 )
{
if ( V_212 [ V_210 ] != V_213 ) {
F_177 ( V_212 [ V_210 ] ,
V_208 -> V_293 ) ;
V_212 [ V_210 ] = V_213 ;
}
}
static int T_1 F_178 ( struct V_294 * V_295 )
{
enum T_15 {
V_296 = 0 ,
V_297 ,
};
static const T_16 V_298 [] V_299 = {
[ V_296 ] = {
V_300 , V_301 , V_302 , V_303 ,
V_304 , V_305 , V_306 , V_307 ,
V_308 , V_309 , V_310 , V_311 ,
V_312 ,
V_312 ,
V_312 ,
V_213 ,
V_213 ,
V_213 ,
V_312 ,
V_313 ,
V_213 ,
V_213 ,
V_213 ,
V_314 ,
V_312 , V_312 , V_312 , V_312 ,
V_312 , V_312 , V_312 , V_312 ,
} ,
[ V_297 ] = {
V_300 , V_302 , V_301 , V_303 ,
V_304 , V_315 , V_306 , V_307 ,
V_308 , V_309 , V_310 , V_311 ,
V_312 ,
V_312 ,
V_312 ,
V_316 ,
V_317 ,
V_213 ,
V_312 ,
V_313 ,
V_213 ,
V_213 ,
V_213 ,
V_314 ,
V_312 , V_312 ,
V_318 ,
V_312 , V_312 , V_312 , V_312 ,
V_312 ,
} ,
} ;
static const struct V_3 V_319 [] V_299 = {
{
. V_6 = V_15 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_296 ,
} ,
{
. V_6 = V_14 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_297 ,
} ,
} ;
#define F_179 sizeof(tpacpi_keymap_t)
#define F_180 sizeof(tpacpi_keymap_entry_t)
int V_17 , V_42 ;
int V_30 ;
int V_320 ;
bool V_321 = false ;
bool V_322 = false ;
unsigned long V_13 ;
unsigned long V_323 ;
F_17 ( V_55 | V_292 ,
L_104 ) ;
F_25 ( ! V_208 ) ;
F_25 ( V_208 -> V_324 != NULL ||
V_208 -> V_325 != NULL ) ;
F_181 ( V_326 ) ;
F_182 ( & V_203 ) ;
#ifdef F_116
F_182 ( & V_268 ) ;
#endif
V_186 . V_202 = V_129 != NULL ;
F_17 ( V_55 | V_292 ,
L_105 ,
F_1 ( V_186 . V_202 ) ) ;
if ( ! V_186 . V_202 )
return 1 ;
V_13 = F_4 ( V_327 ,
F_100 ( V_327 ) ) ;
F_60 () ;
V_290 = F_51 (
F_100 ( V_328 ) + 2 ,
NULL ) ;
if ( ! V_290 )
return - V_84 ;
V_17 = F_53 ( V_290 ,
V_328 ,
F_100 ( V_328 ) ) ;
if ( V_17 )
goto V_329;
if ( F_7 ( V_129 , & V_320 , L_106 , L_107 ) ) {
if ( ( V_320 >> 8 ) != 1 ) {
F_8 ( L_108 ,
V_320 ) ;
F_8 ( L_109 , V_330 ) ;
} else {
F_17 ( V_55 | V_292 ,
L_110 ,
V_320 ) ;
if ( ! F_7 ( V_129 , & V_191 ,
L_111 , L_107 ) ) {
F_8 ( L_112
L_109 ,
V_330 ) ;
V_191 = 0x080cU ;
} else {
V_186 . V_189 = 1 ;
}
}
}
F_17 ( V_55 | V_292 ,
L_113 ,
F_1 ( V_186 . V_189 ) ) ;
if ( ! V_186 . V_189 && ! V_191 &&
( V_13 & V_331 ) )
V_191 = 0x080cU ;
if ( V_186 . V_189 ) {
V_17 = F_110 () ;
if ( V_17 )
goto V_329;
V_283 = V_190 ;
} else {
V_283 = V_191 ;
V_190 = V_191 ;
}
#ifdef F_102
if ( V_172 ) {
V_186 . V_187 = 1 ;
V_321 = ! ! V_167 ;
F_76 ( L_114 ) ;
} else
#endif
if ( F_7 ( V_129 , & V_30 , L_63 , L_107 ) ) {
V_186 . V_187 = 1 ;
V_321 = ! ! V_30 ;
F_76 ( L_115 ,
F_183 ( V_30 , 0 ) ) ;
}
if ( V_186 . V_187 )
V_17 = F_52 ( V_290 ,
& V_332 . V_122 ) ;
if ( ! V_17 && F_7 ( V_129 , & V_30 , L_65 , L_107 ) ) {
V_186 . V_206 = 1 ;
V_322 = ! ! ( V_30 & V_188 ) ;
F_76 ( L_116
L_117 ,
( V_322 ) ? L_118 : L_119 ) ;
V_17 = F_52 ( V_290 ,
& V_333 . V_122 ) ;
}
if ( ! V_17 )
V_17 = F_184 (
V_290 ,
& V_154 -> V_60 . V_125 ) ;
if ( V_17 )
goto V_329;
V_212 = F_44 ( F_179 ,
V_83 ) ;
if ( ! V_212 ) {
F_8 ( L_120 ) ;
V_17 = - V_84 ;
goto V_329;
}
V_323 = F_4 ( V_319 ,
F_100 ( V_319 ) ) ;
F_25 ( V_323 >= F_100 ( V_298 ) ) ;
F_20 ( V_55 | V_292 ,
L_121 , V_323 ) ;
memcpy ( V_212 , & V_298 [ V_323 ] ,
F_179 ) ;
F_185 ( V_208 , V_214 , V_215 ) ;
V_208 -> V_334 = F_180 ;
V_208 -> V_335 = V_336 ;
V_208 -> V_211 = V_212 ;
for ( V_42 = 0 ; V_42 < V_336 ; V_42 ++ ) {
if ( V_212 [ V_42 ] != V_213 ) {
F_185 ( V_208 , V_337 ,
V_212 [ V_42 ] ) ;
} else {
if ( V_42 < sizeof( V_284 ) * 8 )
V_284 |= 1 << V_42 ;
}
}
if ( V_186 . V_187 ) {
F_185 ( V_208 , V_338 , V_289 ) ;
F_122 ( V_208 ,
V_289 , V_321 ) ;
}
if ( V_186 . V_206 ) {
F_185 ( V_208 , V_338 , V_209 ) ;
F_122 ( V_208 ,
V_209 , V_322 ) ;
}
if ( F_186 () ) {
F_76 ( L_122
L_123
L_124 ) ;
F_32 ( L_125
L_126 ) ;
V_284 |=
( 1 << V_260 )
| ( 1 << V_259 ) ;
F_176 ( V_260 ) ;
F_176 ( V_259 ) ;
}
#ifdef F_116
V_193 = V_339
& ~ V_191
& ~ V_284 ;
F_17 ( V_55 | V_292 ,
L_127 ,
V_193 , V_270 ) ;
#endif
F_20 ( V_55 | V_292 ,
L_128 ) ;
V_17 = F_120 ( true ) ;
if ( V_17 ) {
F_175 () ;
return V_17 ;
}
V_17 = F_112 ( ( ( V_191 & ~ V_284 )
| V_195 )
& ~ V_193 ) ;
if ( V_17 < 0 && V_17 != - V_49 ) {
F_175 () ;
return V_17 ;
}
V_192 = ( V_190 | V_193 )
& ~ V_284 ;
F_17 ( V_55 | V_292 ,
L_129 ,
V_192 , V_190 , V_193 ) ;
V_208 -> V_324 = & F_149 ;
V_208 -> V_325 = & F_151 ;
F_147 ( true ) ;
return 0 ;
V_329:
F_54 ( V_290 , & V_154 -> V_60 . V_125 ) ;
V_290 = NULL ;
return ( V_17 < 0 ) ? V_17 : 1 ;
}
static bool F_187 ( const T_7 V_326 ,
bool * V_340 ,
bool * V_341 )
{
unsigned int V_210 = V_326 & 0xfff ;
* V_340 = true ;
* V_341 = false ;
if ( V_210 > 0 && V_210 <= V_336 ) {
V_210 -- ;
if ( ! ( V_193 & ( 1 << V_210 ) ) ) {
F_127 ( V_210 ) ;
* V_340 = false ;
} else {
* V_341 = true ;
}
return true ;
}
return false ;
}
static bool F_188 ( const T_7 V_326 ,
bool * V_340 ,
bool * V_341 )
{
* V_340 = true ;
* V_341 = false ;
switch ( V_326 ) {
case V_342 :
case V_343 :
V_286 = V_344 ;
* V_341 = true ;
break;
case V_345 :
case V_346 :
V_286 = V_347 ;
* V_341 = true ;
break;
case V_348 :
case V_349 :
F_189 ( L_130 ) ;
break;
default:
return false ;
}
if ( V_286 != V_350 ) {
F_76 ( L_131 ) ;
F_171 () ;
}
return true ;
}
static bool F_190 ( const T_7 V_326 ,
bool * V_340 ,
bool * V_341 )
{
* V_340 = true ;
* V_341 = false ;
switch ( V_326 ) {
case V_351 :
V_287 = 1 ;
F_76 ( L_132 ) ;
F_173 () ;
return true ;
case V_352 :
F_76 ( L_133 ) ;
return true ;
case V_353 :
F_76 ( L_134 ) ;
return true ;
default:
return false ;
}
}
static bool F_191 ( const T_7 V_326 ,
bool * V_340 ,
bool * V_341 )
{
* V_340 = true ;
* V_341 = false ;
switch ( V_326 ) {
case V_354 :
case V_355 :
return true ;
case V_356 :
case V_357 :
F_121 () ;
F_169 () ;
* V_340 = false ;
return true ;
case V_358 :
case V_359 :
case V_360 :
* V_341 = true ;
return true ;
default:
return false ;
}
}
static bool F_192 ( const T_7 V_326 ,
bool * V_340 ,
bool * V_341 )
{
bool V_361 = true ;
* V_340 = true ;
* V_341 = false ;
switch ( V_326 ) {
case V_362 :
F_76 ( L_135 ) ;
return true ;
case V_363 :
F_193 ( L_136 ) ;
break;
case V_364 :
F_189 ( L_137 ) ;
break;
case V_365 :
F_193 ( L_138
L_139 ) ;
break;
case V_366 :
F_189 ( L_140
L_141 ) ;
break;
case V_367 :
case V_368 :
case V_369 :
* V_340 = false ;
* V_341 = true ;
return true ;
default:
F_62 ( L_142 ) ;
V_361 = false ;
}
F_194 () ;
return V_361 ;
}
static void F_195 ( struct V_67 * V_68 , T_7 V_65 )
{
T_7 V_326 ;
bool V_340 ;
bool V_341 ;
bool V_370 ;
if ( V_65 != 0x80 ) {
F_8 ( L_143 , V_65 ) ;
F_196 (
V_68 -> V_71 -> V_74 -> V_371 . V_372 ,
F_197 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , 0 ) ;
return;
}
while ( 1 ) {
if ( ! F_7 ( V_129 , & V_326 , L_144 , L_64 ) ) {
F_8 ( L_145 ) ;
return;
}
if ( V_326 == 0 ) {
return;
}
V_340 = true ;
V_341 = false ;
switch ( V_326 >> 12 ) {
case 1 :
V_370 = F_187 ( V_326 , & V_340 ,
& V_341 ) ;
break;
case 2 :
V_370 = F_188 ( V_326 , & V_340 ,
& V_341 ) ;
break;
case 3 :
switch ( V_326 ) {
case V_373 :
V_287 = 1 ;
F_76 ( L_146 ) ;
F_173 () ;
V_370 = true ;
break;
case V_374 :
V_370 = true ;
break;
default:
V_370 = false ;
}
break;
case 4 :
V_370 = F_190 ( V_326 , & V_340 ,
& V_341 ) ;
break;
case 5 :
V_370 = F_191 ( V_326 , & V_340 ,
& V_341 ) ;
break;
case 6 :
V_370 = F_192 ( V_326 , & V_340 ,
& V_341 ) ;
break;
case 7 :
if ( V_186 . V_187 &&
V_326 == V_375 ) {
F_174 () ;
V_340 = 0 ;
V_370 = true ;
break;
}
default:
V_370 = false ;
}
if ( ! V_370 ) {
F_32 ( L_147 , V_326 ) ;
F_32 ( L_148
L_149 , V_330 ) ;
}
if ( ! V_341 && V_340 ) {
F_196 (
V_68 -> V_71 -> V_74 -> V_371 . V_372 ,
F_197 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , V_326 ) ;
}
}
}
static void F_198 ( void )
{
V_286 = V_350 ;
V_287 = 0 ;
}
static void F_199 ( void )
{
F_60 () ;
if ( F_120 ( true ) < 0 ||
F_112 ( V_190 ) < 0 )
F_8 ( L_150
L_151 ) ;
F_174 () ;
F_169 () ;
F_171 () ;
F_173 () ;
F_147 ( false ) ;
}
static int F_200 ( struct V_90 * V_91 )
{
int V_17 , V_30 ;
if ( ! V_186 . V_202 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
if ( F_156 ( & V_203 ) )
return - V_282 ;
V_17 = F_119 ( & V_30 ) ;
if ( ! V_17 )
V_17 = F_110 () ;
F_118 ( & V_203 ) ;
if ( V_17 )
return V_17 ;
F_84 ( V_91 , L_47 , F_183 ( V_30 , 0 ) ) ;
if ( V_191 ) {
F_84 ( V_91 , L_152 , V_192 ) ;
F_84 ( V_91 , L_153 ) ;
} else {
F_84 ( V_91 , L_154 ) ;
F_84 ( V_91 , L_155 ) ;
}
return 0 ;
}
static void F_201 ( bool V_204 )
{
F_2 ( L_156 ) ;
if ( ! F_202 ( ( V_69 == V_70 || ! V_204 ) ,
F_203 ( L_157
L_158
L_159 ) ) )
F_8 ( L_160
L_161
L_159 ) ;
}
static int F_204 ( char * V_126 )
{
int V_17 ;
T_7 V_197 ;
char * V_159 ;
if ( ! V_186 . V_202 )
return - V_75 ;
if ( F_156 ( & V_203 ) )
return - V_282 ;
V_197 = V_192 ;
V_17 = 0 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_51 ) == 0 ) {
F_201 ( 1 ) ;
} else if ( F_86 ( V_159 , L_52 ) == 0 ) {
F_201 ( 0 ) ;
V_17 = - V_158 ;
} else if ( F_86 ( V_159 , L_162 ) == 0 ) {
V_197 = ( V_191 | V_193 )
& ~ V_284 ;
} else if ( sscanf ( V_159 , L_163 , & V_197 ) == 1 ) {
} else if ( sscanf ( V_159 , L_164 , & V_197 ) == 1 ) {
} else {
V_17 = - V_94 ;
goto V_376;
}
}
if ( ! V_17 ) {
F_82 ( L_165 ,
L_166 , V_197 ) ;
V_17 = F_113 ( V_197 ) ;
}
V_376:
F_118 ( & V_203 ) ;
return V_17 ;
}
static int F_205 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_174 )
return ( V_168 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_167 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_377 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_206 ( enum V_378 V_205 )
{
int V_30 ;
F_17 ( V_140 ,
L_168 ,
( V_205 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_174 ) {
V_168 = ( V_205 == V_142 ) ;
return 0 ;
}
#endif
if ( V_205 == V_142 )
V_30 = V_377
| V_379 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_169 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_207 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_380 ,
V_122 , V_126 ) ;
}
static T_8 F_208 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_380 ,
V_122 , V_126 , V_35 ) ;
}
static void F_209 ( void )
{
if ( ! F_7 ( NULL , NULL , L_170 , L_9 ,
V_381 ) )
F_32 ( L_171 ) ;
else
F_17 ( V_140 ,
L_172 ) ;
}
static void F_210 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_382 ) ;
F_77 ( V_380 ) ;
F_209 () ;
}
static int T_1 F_211 ( struct V_294 * V_295 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_173 ) ;
F_181 ( V_326 ) ;
V_186 . V_383 = V_129 &&
F_7 ( V_129 , & V_30 , L_167 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_174 ,
F_1 ( V_186 . V_383 ) ,
V_30 ) ;
#ifdef F_102
if ( V_174 ) {
V_186 . V_383 = 1 ;
F_76 ( L_175 ) ;
} else
#endif
if ( V_186 . V_383 &&
! ( V_30 & V_384 ) ) {
V_186 . V_383 = 0 ;
F_20 ( V_55 | V_140 ,
L_176 ) ;
}
if ( ! V_186 . V_383 )
return 1 ;
V_17 = F_71 ( V_380 ,
& V_385 ,
V_386 ,
V_387 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_212 ( & V_154 -> V_60 . V_125 ,
& V_382 ) ;
if ( V_17 ) {
F_77 ( V_380 ) ;
return V_17 ;
}
return 0 ;
}
static int F_213 ( struct V_90 * V_91 )
{
return F_83 ( V_380 , V_91 ) ;
}
static int F_214 ( char * V_126 )
{
return F_85 ( V_380 , V_126 ) ;
}
static int F_215 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_176 )
return ( V_169 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_177 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_388 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_216 ( enum V_378 V_205 )
{
int V_30 ;
F_17 ( V_140 ,
L_178 ,
( V_205 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_176 ) {
V_169 = ( V_205 == V_142 ) ;
return 0 ;
}
#endif
if ( V_205 == V_142 )
V_30 = V_388
| V_389 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_179 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_217 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_390 ,
V_122 , V_126 ) ;
}
static T_8 F_218 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_390 ,
V_122 , V_126 , V_35 ) ;
}
static void F_219 ( void )
{
if ( ! F_7 ( NULL , NULL , L_180 , L_9 ,
V_391 ) )
F_32 ( L_181 ) ;
else
F_17 ( V_140 ,
L_182 ) ;
}
static void F_220 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_392 ) ;
F_77 ( V_390 ) ;
F_219 () ;
}
static int T_1 F_221 ( struct V_294 * V_295 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_183 ) ;
F_181 ( V_326 ) ;
V_186 . V_393 = V_129 &&
F_7 ( V_129 , & V_30 , L_177 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_184 ,
F_1 ( V_186 . V_393 ) ,
V_30 ) ;
#ifdef F_102
if ( V_176 ) {
V_186 . V_393 = 1 ;
F_76 ( L_185 ) ;
} else
#endif
if ( V_186 . V_393 &&
! ( V_30 & V_394 ) ) {
V_186 . V_393 = 0 ;
F_20 ( V_55 | V_140 ,
L_186 ) ;
}
if ( ! V_186 . V_393 )
return 1 ;
V_17 = F_71 ( V_390 ,
& V_395 ,
V_396 ,
V_397 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_212 ( & V_154 -> V_60 . V_125 ,
& V_392 ) ;
if ( V_17 ) {
F_77 ( V_390 ) ;
return V_17 ;
}
return 0 ;
}
static int F_222 ( struct V_90 * V_91 )
{
return F_83 ( V_390 , V_91 ) ;
}
static int F_223 ( char * V_126 )
{
return F_85 ( V_390 , V_126 ) ;
}
static int F_224 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_178 )
return ( V_170 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_187 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_398 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_225 ( enum V_378 V_205 )
{
int V_30 ;
F_17 ( V_140 ,
L_188 ,
( V_205 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_178 ) {
V_170 = ( V_205 == V_142 ) ;
return 0 ;
}
#endif
if ( V_205 == V_142 )
V_30 = V_398 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_189 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static void F_226 ( void )
{
F_77 ( V_399 ) ;
}
static int T_1 F_227 ( struct V_294 * V_295 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_190 ) ;
F_181 ( V_326 ) ;
V_186 . V_400 = V_129 &&
F_7 ( V_129 , & V_30 , L_187 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_191 ,
F_1 ( V_186 . V_400 ) ,
V_30 ) ;
#ifdef F_102
if ( V_178 ) {
V_186 . V_400 = 1 ;
F_76 ( L_192 ) ;
} else
#endif
if ( V_186 . V_400 &&
! ( V_30 & V_401 ) ) {
V_186 . V_400 = 0 ;
F_20 ( V_55 ,
L_193 ) ;
}
if ( ! V_186 . V_400 )
return 1 ;
V_17 = F_71 ( V_399 ,
& V_402 ,
V_403 ,
V_404 ,
false ) ;
return V_17 ;
}
static int T_1 F_228 ( struct V_294 * V_295 )
{
int V_405 ;
F_17 ( V_55 , L_194 ) ;
F_181 ( V_406 ) ;
if ( F_6 () )
F_181 ( V_407 ) ;
if ( V_408 && F_7 ( NULL , & V_405 , L_195 , L_64 ) && V_405 )
V_409 = V_408 ;
if ( ! V_409 )
V_410 = V_411 ;
else if ( F_6 () &&
F_7 ( V_409 , & V_412 , L_196 , L_107 ) )
V_410 = V_413 ;
else if ( F_6 () &&
F_7 ( V_409 , & V_412 , L_197 , L_107 ) )
V_410 = V_414 ;
else
V_410 = V_415 ;
F_17 ( V_55 , L_198 ,
F_1 ( V_410 != V_411 ) ,
V_410 ) ;
return ( V_410 != V_411 ) ? 0 : 1 ;
}
static void F_229 ( void )
{
F_20 ( V_291 ,
L_199 ) ;
if ( F_230 ( V_412 ) )
F_8 ( L_200
L_201 ) ;
}
static int F_231 ( void )
{
int V_30 = 0 ;
int V_42 ;
switch ( V_410 ) {
case V_413 :
if ( ! F_7 ( NULL , & V_42 , L_202 , L_7 ,
V_416 ) )
return - V_50 ;
V_30 = V_42 & V_417 ;
break;
case V_414 :
if ( ! F_7 ( NULL , & V_42 , L_203 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_418 ;
if ( ! F_7 ( NULL , & V_42 , L_204 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_419 ;
break;
case V_415 :
if ( ! F_7 ( NULL , NULL , L_205 , L_9 , 1 ) ||
! F_7 ( NULL , & V_42 , L_204 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_419 ;
if ( ! F_7 ( NULL , NULL , L_205 , L_9 , 0 ) ||
! F_7 ( NULL , & V_42 , L_203 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_418 ;
if ( ! F_7 ( NULL , & V_42 , L_206 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_420 ;
break;
default:
return - V_421 ;
}
return V_30 ;
}
static int F_232 ( int V_30 )
{
int V_422 ;
int V_17 = 0 ;
switch ( V_410 ) {
case V_413 :
V_17 = F_7 ( NULL , NULL ,
L_207 , L_8 ,
V_423 ,
V_30 | V_424 ) ;
break;
case V_414 :
V_422 = F_233 () ;
if ( V_422 < 0 )
return V_422 ;
V_17 = F_230 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_409 , NULL ,
L_208 , L_8 , V_30 * 0x100 , 0 ) ;
if ( ! V_422 && F_230 ( V_422 ) ) {
F_8 ( L_209 ) ;
return - V_50 ;
}
break;
case V_415 :
V_17 = F_7 ( NULL , NULL , L_205 , L_9 , 0x80 ) &&
F_7 ( NULL , NULL , L_210 , L_8 , V_30 , 1 ) ;
break;
default:
return - V_421 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_233 ( void )
{
int V_422 = 0 ;
switch ( V_410 ) {
case V_413 :
if ( ! F_7 ( V_409 , & V_422 , L_196 , L_64 ) )
return - V_50 ;
break;
case V_414 :
case V_415 :
if ( ! F_7 ( V_409 , & V_422 , L_211 , L_64 ) )
return - V_50 ;
break;
default:
return - V_421 ;
}
return V_422 & 1 ;
}
static int F_230 ( int V_204 )
{
if ( ! F_7 ( V_409 , NULL , L_212 , L_9 , ( V_204 ) ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static int F_234 ( void )
{
int V_422 = F_233 () ;
int V_17 ;
if ( V_422 < 0 )
return V_422 ;
switch ( V_410 ) {
case V_413 :
V_17 = F_230 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_425 , NULL , L_213 , L_214 ) ;
break;
case V_414 :
case V_415 :
V_17 = F_230 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_409 , NULL , L_215 , L_214 ) ;
break;
default:
return - V_421 ;
}
if ( ! V_422 && F_230 ( V_422 ) ) {
F_8 ( L_209 ) ;
return - V_50 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_235 ( void )
{
switch ( V_410 ) {
case V_413 :
return F_7 ( V_425 , NULL , L_216 , L_214 ) ?
0 : - V_50 ;
case V_414 :
return F_7 ( V_409 , NULL , L_217 , L_214 ) ?
0 : - V_50 ;
case V_415 :
return F_7 ( NULL , NULL , L_218 , L_214 ) ?
0 : - V_50 ;
default:
return - V_421 ;
}
}
static int F_236 ( struct V_90 * V_91 )
{
int V_30 , V_422 ;
if ( V_410 == V_411 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
if ( ! F_237 ( V_426 ) )
return - V_158 ;
V_30 = F_231 () ;
if ( V_30 < 0 )
return V_30 ;
V_422 = F_233 () ;
if ( V_422 < 0 )
return V_422 ;
F_84 ( V_91 , L_219 ) ;
F_84 ( V_91 , L_220 , F_183 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_221 , F_183 ( V_30 , 1 ) ) ;
if ( V_410 == V_415 )
F_84 ( V_91 , L_222 , F_183 ( V_30 , 3 ) ) ;
F_84 ( V_91 , L_223 , F_183 ( V_422 , 0 ) ) ;
F_84 ( V_91 , L_224 ) ;
F_84 ( V_91 , L_225 ) ;
if ( V_410 == V_415 )
F_84 ( V_91 , L_226 ) ;
F_84 ( V_91 , L_227 ) ;
F_84 ( V_91 , L_228 ) ;
return 0 ;
}
static int F_238 ( char * V_126 )
{
char * V_159 ;
int V_204 , V_427 , V_30 ;
int V_17 ;
if ( V_410 == V_411 )
return - V_75 ;
if ( ! F_237 ( V_426 ) )
return - V_158 ;
V_204 = 0 ;
V_427 = 0 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_229 ) == 0 ) {
V_204 |= V_418 ;
} else if ( F_86 ( V_159 , L_230 ) == 0 ) {
V_427 |= V_418 ;
} else if ( F_86 ( V_159 , L_231 ) == 0 ) {
V_204 |= V_419 ;
} else if ( F_86 ( V_159 , L_232 ) == 0 ) {
V_427 |= V_419 ;
} else if ( V_410 == V_415 &&
F_86 ( V_159 , L_233 ) == 0 ) {
V_204 |= V_420 ;
} else if ( V_410 == V_415 &&
F_86 ( V_159 , L_234 ) == 0 ) {
V_427 |= V_420 ;
} else if ( F_86 ( V_159 , L_235 ) == 0 ) {
V_17 = F_230 ( 1 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_236 ) == 0 ) {
V_17 = F_230 ( 0 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_237 ) == 0 ) {
V_17 = F_234 () ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_238 ) == 0 ) {
V_17 = F_235 () ;
if ( V_17 )
return V_17 ;
} else
return - V_94 ;
}
if ( V_204 || V_427 ) {
V_30 = F_231 () ;
if ( V_30 < 0 )
return V_30 ;
V_17 = F_232 ( ( V_30 & ~ V_427 ) | V_204 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_239 ( void )
{
int V_30 = 0 ;
if ( V_186 . V_428 ) {
if ( ! F_7 ( V_425 , & V_30 , L_239 , L_64 ) )
return - V_50 ;
return ( ! ! V_30 ) ;
}
return - V_49 ;
}
static int F_240 ( int V_30 )
{
int V_73 ;
if ( V_186 . V_429 ) {
if ( V_48 ) {
V_73 = F_7 ( V_48 , NULL , NULL , L_9 ,
( V_30 ) ?
V_430 :
V_431 ) ;
} else {
V_73 = F_7 ( V_432 , NULL , NULL , L_9 ,
( V_30 ) ? 1 : 0 ) ;
}
return ( V_73 ) ? 0 : - V_50 ;
}
return - V_49 ;
}
static void F_241 ( struct V_433 * V_434 )
{
struct V_435 * V_66 =
F_242 ( V_434 , struct V_435 , V_434 ) ;
if ( F_138 ( V_69 == V_70 ) )
F_240 ( ( V_66 -> V_436 != V_437 ) ) ;
}
static void F_243 ( struct V_438 * V_439 ,
enum V_440 V_441 )
{
struct V_435 * V_66 =
F_242 ( V_439 ,
struct V_435 ,
V_438 ) ;
V_66 -> V_436 = ( V_441 != V_442 ) ?
V_443 : V_437 ;
F_244 ( V_444 , & V_66 -> V_434 ) ;
}
static enum V_440 F_245 ( struct V_438 * V_439 )
{
return ( F_239 () == 1 ) ? V_445 : V_442 ;
}
static int T_1 F_246 ( struct V_294 * V_295 )
{
int V_73 ;
F_17 ( V_55 , L_240 ) ;
if ( F_6 () ) {
F_181 ( V_446 ) ;
F_181 ( V_447 ) ;
}
F_181 ( V_448 ) ;
F_247 ( & V_449 . V_434 , F_241 ) ;
V_186 . V_429 = ( V_48 || V_432 ) && ! V_450 ;
if ( V_186 . V_429 )
V_186 . V_428 =
F_7 ( V_425 , NULL , L_239 , L_241 ) ;
F_17 ( V_55 , L_242 ,
F_1 ( V_186 . V_429 ) ,
F_1 ( V_186 . V_428 ) ) ;
if ( ! V_186 . V_429 )
return 1 ;
V_73 = F_248 ( & V_154 -> V_60 ,
& V_449 . V_438 ) ;
if ( V_73 < 0 ) {
V_186 . V_429 = 0 ;
V_186 . V_428 = 0 ;
} else {
V_73 = 0 ;
}
return V_73 ;
}
static void F_249 ( void )
{
F_250 ( & V_449 . V_438 ) ;
F_251 ( V_444 ) ;
}
static int F_252 ( struct V_90 * V_91 )
{
int V_30 ;
if ( ! V_186 . V_429 ) {
F_84 ( V_91 , L_46 ) ;
} else if ( ! V_186 . V_428 ) {
F_84 ( V_91 , L_243 ) ;
F_84 ( V_91 , L_244 ) ;
} else {
V_30 = F_239 () ;
if ( V_30 < 0 )
return V_30 ;
F_84 ( V_91 , L_47 , F_253 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_244 ) ;
}
return 0 ;
}
static int F_254 ( char * V_126 )
{
char * V_159 ;
int V_451 = 0 ;
if ( ! V_186 . V_429 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_245 ) == 0 ) {
V_451 = 1 ;
} else if ( F_86 ( V_159 , L_246 ) == 0 ) {
V_451 = 0 ;
} else
return - V_94 ;
}
return F_240 ( V_451 ) ;
}
static T_8 F_255 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_47 ;
int V_17 ;
if ( F_57 ( V_126 , 21 , & V_47 ) )
return - V_94 ;
V_17 = F_15 ( V_47 ) ;
return ( V_17 ) ? V_17 : V_35 ;
}
static int T_1 F_256 ( struct V_294 * V_295 )
{
int V_17 ;
F_17 ( V_55 ,
L_247 ) ;
F_181 ( V_448 ) ;
F_17 ( V_55 , L_248 ,
F_1 ( V_48 != NULL ) ) ;
V_17 = F_257 ( & V_154 -> V_60 , & V_452 ) ;
if ( V_17 )
return V_17 ;
return ( V_48 ) ? 0 : 1 ;
}
static void F_258 ( void )
{
F_259 ( & V_154 -> V_60 , & V_452 ) ;
}
static int F_260 ( struct V_90 * V_91 )
{
if ( ! V_48 )
F_84 ( V_91 , L_46 ) ;
else {
F_84 ( V_91 , L_219 ) ;
F_84 ( V_91 , L_249 ) ;
}
return 0 ;
}
static int F_261 ( char * V_126 )
{
char * V_159 ;
int V_47 , V_17 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_250 , & V_47 ) == 1 &&
V_47 >= 0 && V_47 <= 21 ) {
} else
return - V_94 ;
V_17 = F_15 ( V_47 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static inline bool F_262 ( const unsigned int V_453 )
{
#ifdef F_263
return false ;
#else
return ( 1U & ( V_454 >> V_453 ) ) == 0 ;
#endif
}
static int F_264 ( const unsigned int V_453 )
{
int V_30 ;
enum V_455 V_456 ;
switch ( V_457 ) {
case V_458 :
if ( ! F_7 ( V_425 ,
& V_30 , L_251 , L_7 , 1 << V_453 ) )
return - V_50 ;
V_456 = ( V_30 == 0 ) ?
V_437 :
( ( V_30 == 1 ) ?
V_443 :
V_459 ) ;
V_460 [ V_453 ] = V_456 ;
return V_456 ;
default:
return - V_49 ;
}
}
static int F_265 ( const unsigned int V_453 ,
const enum V_455 V_461 )
{
static const unsigned int V_462 [] = { 0 , 1 , 3 } ;
static const unsigned int V_463 [] = { 0 , 0x80 , 0xc0 } ;
int V_73 = 0 ;
switch ( V_457 ) {
case V_458 :
if ( F_140 ( V_453 > 7 ) )
return - V_94 ;
if ( F_140 ( F_262 ( V_453 ) ) )
return - V_158 ;
if ( ! F_7 ( V_464 , NULL , NULL , L_8 ,
( 1 << V_453 ) , V_462 [ V_461 ] ) )
V_73 = - V_50 ;
break;
case V_465 :
if ( F_140 ( V_453 > 7 ) )
return - V_94 ;
if ( F_140 ( F_262 ( V_453 ) ) )
return - V_158 ;
V_73 = F_14 ( V_466 , ( 1 << V_453 ) ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_467 ,
( V_461 == V_459 ) << V_453 ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_468 ,
( V_461 != V_437 ) << V_453 ) ;
break;
case V_469 :
if ( F_140 ( V_453 >= V_470 ) )
return - V_94 ;
if ( F_140 ( F_262 ( V_453 ) ) )
return - V_158 ;
if ( ! F_7 ( V_464 , NULL , NULL , L_8 ,
V_453 , V_463 [ V_461 ] ) )
V_73 = - V_50 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
V_460 [ V_453 ] = V_461 ;
return V_73 ;
}
static void F_266 ( struct V_433 * V_434 )
{
struct V_435 * V_66 =
F_242 ( V_434 , struct V_435 , V_434 ) ;
if ( F_138 ( V_69 == V_70 ) )
F_265 ( V_66 -> V_453 , V_66 -> V_436 ) ;
}
static void F_267 ( struct V_438 * V_439 ,
enum V_440 V_441 )
{
struct V_435 * V_66 = F_242 ( V_439 ,
struct V_435 , V_438 ) ;
if ( V_441 == V_442 )
V_66 -> V_436 = V_437 ;
else if ( V_460 [ V_66 -> V_453 ] != V_459 )
V_66 -> V_436 = V_443 ;
else
V_66 -> V_436 = V_459 ;
F_244 ( V_444 , & V_66 -> V_434 ) ;
}
static int F_268 ( struct V_438 * V_439 ,
unsigned long * V_471 , unsigned long * V_472 )
{
struct V_435 * V_66 = F_242 ( V_439 ,
struct V_435 , V_438 ) ;
if ( * V_471 == 0 && * V_472 == 0 ) {
* V_471 = 500 ;
* V_472 = 500 ;
} else if ( ( * V_471 != 500 ) || ( * V_472 != 500 ) )
return - V_94 ;
V_66 -> V_436 = V_459 ;
F_244 ( V_444 , & V_66 -> V_434 ) ;
return 0 ;
}
static enum V_440 F_269 ( struct V_438 * V_439 )
{
int V_73 ;
struct V_435 * V_66 = F_242 ( V_439 ,
struct V_435 , V_438 ) ;
V_73 = F_264 ( V_66 -> V_453 ) ;
if ( V_73 == V_437 || V_73 < 0 )
V_73 = V_442 ;
else
V_73 = V_445 ;
return V_73 ;
}
static void F_270 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_470 ; V_42 ++ ) {
if ( V_473 [ V_42 ] . V_438 . V_51 )
F_250 ( & V_473 [ V_42 ] . V_438 ) ;
}
F_251 ( V_444 ) ;
F_37 ( V_473 ) ;
}
static int T_1 F_271 ( unsigned int V_453 )
{
int V_73 ;
V_473 [ V_453 ] . V_453 = V_453 ;
if ( ! V_474 [ V_453 ] )
return 0 ;
V_473 [ V_453 ] . V_438 . V_475 = & F_267 ;
V_473 [ V_453 ] . V_438 . V_476 = & F_268 ;
if ( V_457 == V_458 )
V_473 [ V_453 ] . V_438 . V_477 =
& F_269 ;
V_473 [ V_453 ] . V_438 . V_51 = V_474 [ V_453 ] ;
F_247 ( & V_473 [ V_453 ] . V_434 , F_266 ) ;
V_73 = F_248 ( & V_154 -> V_60 ,
& V_473 [ V_453 ] . V_438 ) ;
if ( V_73 < 0 )
V_473 [ V_453 ] . V_438 . V_51 = NULL ;
return V_73 ;
}
static enum V_478 T_1 F_272 ( void )
{
T_4 V_30 ;
if ( F_6 () ) {
V_30 = F_18 ( V_425 , L_252 , & V_464 ) ;
if ( F_19 ( V_30 ) )
return V_458 ;
V_30 = F_18 ( V_425 , L_253 , & V_464 ) ;
if ( F_19 ( V_30 ) )
return V_465 ;
}
V_30 = F_18 ( V_425 , L_254 , & V_464 ) ;
if ( F_19 ( V_30 ) )
return V_469 ;
V_464 = NULL ;
return V_479 ;
}
static int T_1 F_273 ( struct V_294 * V_295 )
{
unsigned int V_42 ;
int V_73 ;
unsigned long V_480 ;
F_17 ( V_55 , L_255 ) ;
V_457 = F_272 () ;
if ( V_457 != V_479 ) {
V_480 = F_4 ( V_481 ,
F_100 ( V_481 ) ) ;
if ( ! V_480 ) {
V_464 = NULL ;
V_457 = V_479 ;
}
}
F_17 ( V_55 , L_256 ,
F_1 ( V_457 ) , V_457 ) ;
if ( V_457 == V_479 )
return 1 ;
V_473 = F_35 ( sizeof( * V_473 ) * V_470 ,
V_83 ) ;
if ( ! V_473 ) {
F_8 ( L_257 ) ;
return - V_84 ;
}
for ( V_42 = 0 ; V_42 < V_470 ; V_42 ++ ) {
V_473 [ V_42 ] . V_453 = - 1 ;
if ( ! F_262 ( V_42 ) &&
F_274 ( V_42 , & V_480 ) ) {
V_73 = F_271 ( V_42 ) ;
if ( V_73 < 0 ) {
F_270 () ;
return V_73 ;
}
}
}
#ifdef F_263
F_32 ( L_258
L_259 ) ;
#endif
return 0 ;
}
static int F_275 ( struct V_90 * V_91 )
{
if ( ! V_457 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
F_84 ( V_91 , L_219 ) ;
if ( V_457 == V_458 ) {
int V_42 , V_30 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_30 = F_264 ( V_42 ) ;
if ( V_30 < 0 )
return - V_50 ;
F_84 ( V_91 , L_260 ,
V_42 , F_276 ( V_30 ) ) ;
}
}
F_84 ( V_91 , L_261
L_262 ) ;
return 0 ;
}
static int F_277 ( char * V_126 )
{
char * V_159 ;
int V_453 , V_73 ;
enum V_455 V_118 ;
if ( ! V_457 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_263 , & V_453 ) != 1 )
return - V_94 ;
if ( V_453 < 0 || V_453 > ( V_470 - 1 ) ||
V_473 [ V_453 ] . V_453 < 0 )
return - V_75 ;
if ( strstr ( V_159 , L_246 ) ) {
V_118 = V_437 ;
} else if ( strstr ( V_159 , L_245 ) ) {
V_118 = V_443 ;
} else if ( strstr ( V_159 , L_264 ) ) {
V_118 = V_459 ;
} else {
return - V_94 ;
}
V_73 = F_265 ( V_453 , V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
static int T_1 F_278 ( struct V_294 * V_295 )
{
unsigned long V_13 ;
F_17 ( V_55 , L_265 ) ;
F_181 ( V_482 ) ;
F_17 ( V_55 , L_266 ,
F_1 ( V_483 != NULL ) ) ;
V_13 = F_4 ( V_484 ,
F_100 ( V_484 ) ) ;
V_186 . V_485 = ! ! ( V_13 & V_486 ) ;
return ( V_483 ) ? 0 : 1 ;
}
static int F_279 ( struct V_90 * V_91 )
{
if ( ! V_483 )
F_84 ( V_91 , L_46 ) ;
else {
F_84 ( V_91 , L_219 ) ;
F_84 ( V_91 , L_267 ) ;
}
return 0 ;
}
static int F_280 ( char * V_126 )
{
char * V_159 ;
int V_487 ;
if ( ! V_483 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_250 , & V_487 ) == 1 &&
V_487 >= 0 && V_487 <= 17 ) {
} else
return - V_94 ;
if ( V_186 . V_485 ) {
if ( ! F_7 ( V_483 , NULL , NULL , L_8 ,
V_487 , 0 ) )
return - V_50 ;
} else {
if ( ! F_7 ( V_483 , NULL , NULL , L_9 ,
V_487 ) )
return - V_50 ;
}
}
return 0 ;
}
static int F_281 ( int V_488 , T_17 * V_38 )
{
int V_157 ;
T_18 V_489 ;
char V_490 [ 5 ] ;
V_157 = V_491 ;
switch ( V_492 ) {
#if V_493 >= 16
case V_494 :
if ( V_488 >= 8 && V_488 <= 15 ) {
V_157 = V_495 ;
V_488 -= 8 ;
}
#endif
case V_496 :
if ( V_488 <= 7 ) {
if ( ! F_11 ( V_157 + V_488 , & V_489 ) )
return - V_50 ;
* V_38 = V_489 * 1000 ;
return 0 ;
}
break;
case V_497 :
if ( V_488 <= 7 ) {
snprintf ( V_490 , sizeof( V_490 ) , L_268 , '0' + V_488 ) ;
if ( ! F_7 ( V_425 , NULL , L_269 , L_214 ) )
return - V_50 ;
if ( ! F_7 ( V_425 , & V_157 , V_490 , L_64 ) )
return - V_50 ;
* V_38 = ( V_157 - 2732 ) * 100 ;
return 0 ;
}
break;
case V_498 :
if ( V_488 <= 7 ) {
snprintf ( V_490 , sizeof( V_490 ) , L_268 , '0' + V_488 ) ;
if ( ! F_7 ( V_425 , & V_157 , V_490 , L_64 ) )
return - V_50 ;
if ( V_157 > 127 || V_157 < - 127 )
V_157 = V_499 ;
* V_38 = V_157 * 1000 ;
return 0 ;
}
break;
case V_500 :
default:
return - V_421 ;
}
return - V_94 ;
}
static int F_282 ( struct V_501 * V_118 )
{
int V_17 , V_42 ;
int V_217 ;
V_217 = 8 ;
V_42 = 0 ;
if ( ! V_118 )
return - V_94 ;
if ( V_492 == V_494 )
V_217 = 16 ;
for ( V_42 = 0 ; V_42 < V_217 ; V_42 ++ ) {
V_17 = F_281 ( V_42 , & V_118 -> V_502 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return V_217 ;
}
static void F_194 ( void )
{
int V_217 , V_42 ;
struct V_501 V_157 ;
V_217 = F_282 ( & V_157 ) ;
if ( V_217 <= 0 )
return;
F_32 ( L_270 ) ;
for ( V_42 = 0 ; V_42 < V_217 ; V_42 ++ ) {
if ( V_157 . V_502 [ V_42 ] != V_503 )
F_283 ( L_271 , ( int ) ( V_157 . V_502 [ V_42 ] / 1000 ) ) ;
else
F_283 ( L_272 ) ;
}
F_283 ( L_273 ) ;
}
static T_8 F_284 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
struct V_504 * V_505 =
F_285 ( V_122 ) ;
int V_488 = V_505 -> V_506 ;
T_17 V_38 ;
int V_17 ;
V_17 = F_281 ( V_488 , & V_38 ) ;
if ( V_17 )
return V_17 ;
if ( V_38 == V_503 )
return - V_49 ;
return snprintf ( V_126 , V_102 , L_44 , V_38 ) ;
}
static int T_1 F_286 ( struct V_294 * V_295 )
{
T_6 V_157 , V_507 , V_508 ;
int V_42 ;
int V_509 ;
int V_17 ;
F_17 ( V_55 , L_274 ) ;
V_509 = F_7 ( V_425 , NULL , L_275 , L_241 ) ;
if ( V_7 . V_12 ) {
V_507 = V_508 = 0 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( F_11 ( V_491 + V_42 , & V_157 ) ) {
V_507 |= V_157 ;
} else {
V_507 = 0 ;
break;
}
if ( F_11 ( V_495 + V_42 , & V_157 ) ) {
V_508 |= V_157 ;
} else {
V_507 = 0 ;
break;
}
}
if ( V_507 == 0 ) {
if ( V_509 ) {
F_8 ( L_276
L_277
L_278 ) ;
V_492 = V_498 ;
} else {
F_8 ( L_276
L_279 ) ;
V_492 = V_500 ;
}
} else {
V_492 =
( V_508 != 0 ) ?
V_494 : V_496 ;
}
} else if ( V_509 ) {
if ( F_6 () &&
F_7 ( V_425 , NULL , L_269 , L_241 ) ) {
V_492 = V_497 ;
} else {
V_492 = V_498 ;
}
} else {
V_492 = V_500 ;
}
F_17 ( V_55 , L_280 ,
F_1 ( V_492 != V_500 ) ,
V_492 ) ;
switch ( V_492 ) {
case V_494 :
V_17 = F_212 ( & V_510 -> V_60 . V_125 ,
& V_511 ) ;
if ( V_17 )
return V_17 ;
break;
case V_496 :
case V_498 :
case V_497 :
V_17 = F_212 ( & V_510 -> V_60 . V_125 ,
& V_512 ) ;
if ( V_17 )
return V_17 ;
break;
case V_500 :
default:
return 1 ;
}
return 0 ;
}
static void F_287 ( void )
{
switch ( V_492 ) {
case V_494 :
F_55 ( & V_510 -> V_60 . V_125 ,
& V_511 ) ;
break;
case V_496 :
case V_498 :
case V_497 :
F_55 ( & V_510 -> V_60 . V_125 ,
& V_512 ) ;
break;
case V_500 :
default:
break;
}
}
static int F_288 ( struct V_90 * V_91 )
{
int V_217 , V_42 ;
struct V_501 V_157 ;
V_217 = F_282 ( & V_157 ) ;
if ( F_140 ( V_217 < 0 ) )
return V_217 ;
F_84 ( V_91 , L_281 ) ;
if ( V_217 > 0 ) {
for ( V_42 = 0 ; V_42 < ( V_217 - 1 ) ; V_42 ++ )
F_84 ( V_91 , L_282 , V_157 . V_502 [ V_42 ] / 1000 ) ;
F_84 ( V_91 , L_44 , V_157 . V_502 [ V_42 ] / 1000 ) ;
} else
F_84 ( V_91 , L_283 ) ;
return 0 ;
}
static unsigned int F_289 ( void )
{
T_6 V_513 ;
V_513 = ( F_131 ( V_238 )
& V_240 )
>> V_241 ;
V_513 &= V_514 ;
return V_513 ;
}
static void F_290 ( void )
{
T_6 V_515 = 0 ;
T_6 V_516 ;
if ( V_517 != V_518 )
return;
F_17 ( V_519 ,
L_284 ) ;
if ( F_156 ( & V_520 ) < 0 )
return;
if ( F_140 ( ! F_11 ( V_521 , & V_515 ) ) )
goto V_522;
V_515 &= V_523 ;
V_516 = F_131 ( V_238 ) ;
if ( V_515 != ( ( V_516 & V_240 )
>> V_241 ) ) {
V_516 &= ~ ( V_240 <<
V_241 ) ;
V_516 |= V_515 ;
F_291 ( V_516 , V_238 ) ;
F_20 ( V_519 ,
L_285 ,
( unsigned int ) V_515 , ( unsigned int ) V_516 ) ;
} else
F_17 ( V_519 ,
L_286 ,
( unsigned int ) V_515 , ( unsigned int ) V_516 ) ;
V_522:
F_118 ( & V_520 ) ;
}
static int F_292 ( int * V_30 )
{
T_6 V_515 = 0 ;
switch ( V_517 ) {
case V_524 :
* V_30 = F_289 () ;
return 0 ;
case V_525 :
case V_518 :
if ( F_140 ( ! F_11 ( V_521 , & V_515 ) ) )
return - V_50 ;
* V_30 = V_515 ;
return 0 ;
default:
return - V_49 ;
}
}
static int F_293 ( unsigned int V_38 )
{
T_6 V_515 = 0 ;
if ( F_140 ( ! F_11 ( V_521 , & V_515 ) ) )
return - V_50 ;
if ( F_140 ( ! F_13 ( V_521 ,
( V_515 & V_526 ) |
( V_38 & V_523 ) ) ) )
return - V_50 ;
return 0 ;
}
static int F_294 ( unsigned int V_38 )
{
int V_47 , V_527 ;
unsigned int V_528 , V_42 ;
V_528 = F_289 () ;
if ( V_38 == V_528 )
return 0 ;
V_47 = ( V_38 > V_528 ) ?
V_529 :
V_530 ;
V_527 = ( V_38 > V_528 ) ? 1 : - 1 ;
for ( V_42 = V_528 ; V_42 != V_38 ; V_42 += V_527 )
if ( F_15 ( V_47 ) )
return - V_50 ;
return 0 ;
}
static int V_475 ( unsigned int V_38 )
{
int V_17 ;
if ( V_38 > V_514 || V_38 < 0 )
return - V_94 ;
F_17 ( V_519 ,
L_287 , V_38 ) ;
V_17 = F_156 ( & V_520 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_517 ) {
case V_525 :
case V_518 :
V_17 = F_293 ( V_38 ) ;
break;
case V_524 :
V_17 = F_294 ( V_38 ) ;
break;
default:
V_17 = - V_49 ;
}
F_118 ( & V_520 ) ;
return V_17 ;
}
static int F_295 ( struct V_531 * V_532 )
{
unsigned int V_56 =
( V_532 -> V_533 . V_534 == V_535 &&
V_532 -> V_533 . V_536 == V_535 ) ?
V_532 -> V_533 . V_441 : 0 ;
F_20 ( V_519 ,
L_288 ,
V_56 ) ;
return V_475 ( V_56 ) ;
}
static int V_477 ( struct V_531 * V_532 )
{
int V_30 , V_17 ;
V_17 = F_156 ( & V_520 ) ;
if ( V_17 < 0 )
return 0 ;
V_17 = F_292 ( & V_30 ) ;
F_118 ( & V_520 ) ;
if ( V_17 < 0 )
return 0 ;
return V_30 & V_523 ;
}
static void F_296 ( void )
{
F_297 ( V_537 ,
V_538 ) ;
}
static int T_1 F_298 ( T_3 V_16 )
{
struct V_26 V_539 = { V_540 , NULL } ;
union V_23 * V_541 ;
struct V_59 * V_74 , * V_542 ;
int V_73 ;
if ( F_22 ( V_16 , & V_74 ) )
return 0 ;
V_73 = 0 ;
F_299 (child, &device->children, node) {
T_4 V_30 = F_9 ( V_542 -> V_16 , L_289 ,
NULL , & V_539 ) ;
if ( F_31 ( V_30 ) )
continue;
V_541 = (union V_23 * ) V_539 . V_36 ;
if ( ! V_541 || ( V_541 -> type != V_543 ) ) {
F_8 ( L_290 ,
V_330 ) ;
V_73 = 0 ;
} else {
V_73 = V_541 -> V_544 . V_35 ;
}
break;
}
F_37 ( V_539 . V_36 ) ;
return V_73 ;
}
static unsigned int T_1 F_300 ( void )
{
T_3 V_545 ;
int V_546 = 0 ;
F_24 ( L_13 , NULL , & V_545 ) ;
if ( V_545 )
V_546 = F_298 ( V_545 ) ;
V_186 . V_547 = ( V_546 > 0 ) ;
return ( V_546 > 2 ) ? ( V_546 - 2 ) : 0 ;
}
static void T_1 F_301 ( void )
{
unsigned int V_548 ;
F_17 ( V_55 ,
L_291 ) ;
V_548 = F_300 () ;
switch ( V_548 ) {
case 16 :
V_514 = 15 ;
F_76 ( L_292 ) ;
break;
case 8 :
case 0 :
V_514 = 7 ;
F_76 ( L_293 ) ;
break;
default:
F_8 ( L_294
L_295 , V_330 ) ;
V_186 . V_549 = 1 ;
V_514 = V_548 - 1 ;
}
}
static int T_1 F_302 ( struct V_294 * V_295 )
{
struct V_550 V_533 ;
int V_548 ;
unsigned long V_13 ;
F_17 ( V_55 , L_296 ) ;
F_182 ( & V_520 ) ;
V_13 = F_4 ( V_551 ,
F_100 ( V_551 ) ) ;
if ( V_186 . V_549 )
return 1 ;
if ( ! V_552 ) {
F_20 ( V_55 | V_519 ,
L_297
L_298 ) ;
return 1 ;
}
if ( F_186 () ) {
if ( V_552 > 1 ) {
F_76 ( L_299
L_300 ) ;
return 1 ;
} else if ( V_552 == 1 ) {
F_62 ( L_301
L_302
L_303 ) ;
return 1 ;
}
} else if ( V_186 . V_547 && V_552 > 1 ) {
F_32 ( L_304
L_305
L_306 ) ;
}
if ( V_517 > V_553 )
return - V_94 ;
if ( V_517 == V_554 ||
V_517 == V_553 ) {
if ( V_13 & V_555 )
V_517 = V_518 ;
else
V_517 = V_524 ;
F_20 ( V_519 ,
L_307 ,
V_517 ) ;
}
if ( ! F_6 () &&
( V_517 == V_518 ||
V_517 == V_525 ) )
return - V_94 ;
if ( F_292 ( & V_548 ) < 0 )
return 1 ;
memset ( & V_533 , 0 , sizeof( struct V_550 ) ) ;
V_533 . type = V_556 ;
V_533 . V_557 = V_514 ;
V_533 . V_441 = V_548 & V_523 ;
V_537 = F_303 ( V_558 ,
NULL , NULL ,
& V_559 ,
& V_533 ) ;
if ( F_146 ( V_537 ) ) {
int V_73 = F_304 ( V_537 ) ;
V_537 = NULL ;
F_8 ( L_308 ) ;
return V_73 ;
}
F_17 ( V_55 | V_519 ,
L_309 ) ;
if ( V_13 & V_560 ) {
F_32 ( L_310
L_311 , V_517 ) ;
F_32 ( L_312
L_313 , V_330 ) ;
}
F_305 ( V_537 ) ;
F_17 ( V_55 | V_519 ,
L_314
L_315 ) ;
F_114 ( V_195
| V_561
| V_562 ) ;
return 0 ;
}
static void F_306 ( void )
{
F_290 () ;
}
static void F_307 ( void )
{
F_290 () ;
}
static void F_308 ( void )
{
if ( V_537 ) {
F_17 ( V_291 | V_519 ,
L_316 ) ;
F_309 ( V_537 ) ;
}
F_290 () ;
}
static int F_310 ( struct V_90 * V_91 )
{
int V_56 ;
V_56 = V_477 ( NULL ) ;
if ( V_56 < 0 ) {
F_84 ( V_91 , L_317 ) ;
} else {
F_84 ( V_91 , L_318 , V_56 ) ;
F_84 ( V_91 , L_319 ) ;
F_84 ( V_91 , L_320 ,
V_514 ) ;
}
return 0 ;
}
static int F_311 ( char * V_126 )
{
int V_56 ;
int V_73 ;
char * V_159 ;
V_56 = V_477 ( NULL ) ;
if ( V_56 < 0 )
return V_56 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_321 ) == 0 ) {
if ( V_56 < V_514 )
V_56 ++ ;
} else if ( F_86 ( V_159 , L_322 ) == 0 ) {
if ( V_56 > 0 )
V_56 -- ;
} else if ( sscanf ( V_159 , L_323 , & V_56 ) == 1 &&
V_56 >= 0 && V_56 <= V_514 ) {
} else
return - V_94 ;
}
F_82 ( L_324 ,
L_325 , V_56 ) ;
V_73 = V_475 ( V_56 ) ;
if ( ! V_73 && V_537 )
F_297 ( V_537 ,
V_563 ) ;
return ( V_73 == - V_564 ) ? - V_282 : V_73 ;
}
static void F_312 ( void )
{
T_6 V_515 = 0 ;
T_6 V_516 ;
T_6 V_565 ;
if ( V_566 != V_567 )
return;
if ( ! V_568 )
return;
F_17 ( V_569 ,
L_326 ) ;
if ( V_186 . V_570 )
V_565 = V_571 ;
else
V_565 = V_571 | V_572 ;
if ( F_156 ( & V_573 ) < 0 )
return;
if ( F_140 ( ! F_11 ( V_574 , & V_515 ) ) )
goto V_522;
V_515 &= V_565 ;
V_516 = F_131 ( V_245 ) ;
if ( V_515 != ( V_516 & V_565 ) ) {
V_516 &= ~ V_565 ;
V_516 |= V_515 ;
F_291 ( V_516 , V_245 ) ;
F_20 ( V_569 ,
L_327 ,
( unsigned int ) V_515 , ( unsigned int ) V_516 ) ;
} else {
F_17 ( V_569 ,
L_328 ,
( unsigned int ) V_515 , ( unsigned int ) V_516 ) ;
}
V_522:
F_118 ( & V_573 ) ;
}
static int F_313 ( T_6 * V_30 )
{
T_6 V_118 ;
if ( ! F_11 ( V_574 , & V_118 ) )
return - V_50 ;
* V_30 = V_118 ;
F_20 ( V_569 , L_329 , V_118 ) ;
return 0 ;
}
static int F_314 ( T_6 * V_30 )
{
return F_313 ( V_30 ) ;
}
static int F_315 ( const T_6 V_30 )
{
if ( ! F_13 ( V_574 , V_30 ) )
return - V_50 ;
F_20 ( V_569 , L_330 , V_30 ) ;
return 0 ;
}
static int F_316 ( const T_6 V_30 )
{
return F_315 ( V_30 ) ;
}
static int F_317 ( const bool V_249 )
{
int V_73 ;
T_6 V_118 , V_217 ;
if ( F_156 ( & V_573 ) < 0 )
return - V_564 ;
V_73 = F_313 ( & V_118 ) ;
if ( V_73 )
goto V_522;
V_217 = ( V_249 ) ? V_118 | V_571 :
V_118 & ~ V_571 ;
if ( V_217 != V_118 ) {
V_73 = F_315 ( V_217 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_522:
F_118 ( & V_573 ) ;
return V_73 ;
}
static int F_318 ( const bool V_249 )
{
F_20 ( V_569 , L_331 ,
( V_249 ) ? L_1 : L_42 ) ;
return F_317 ( V_249 ) ;
}
static int F_319 ( const bool V_249 )
{
int V_73 ;
F_20 ( V_569 , L_332 ,
( V_249 ) ? L_1 : L_42 ) ;
V_73 = F_317 ( V_249 ) ;
return ( V_73 < 0 ) ? V_73 : 0 ;
}
static int F_320 ( const T_6 V_575 )
{
int V_73 ;
T_6 V_118 , V_217 ;
if ( V_575 > V_576 )
return - V_94 ;
if ( F_156 ( & V_573 ) < 0 )
return - V_564 ;
V_73 = F_313 ( & V_118 ) ;
if ( V_73 )
goto V_522;
V_217 = ( V_118 & ~ V_572 ) | V_575 ;
if ( V_217 != V_118 ) {
V_73 = F_315 ( V_217 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_522:
F_118 ( & V_573 ) ;
return V_73 ;
}
static int F_321 ( const T_6 V_575 )
{
F_20 ( V_569 ,
L_333 , V_575 ) ;
return F_320 ( V_575 ) ;
}
static void F_322 ( void )
{
struct V_577 * V_218 ;
if ( V_578 && V_578 -> V_579 ) {
V_218 = V_578 -> V_579 ;
if ( V_218 -> V_580 )
F_323 ( V_578 ,
V_581 ,
V_218 -> V_580 ) ;
if ( V_218 -> V_582 )
F_323 ( V_578 ,
V_581 ,
V_218 -> V_582 ) ;
}
}
static int F_324 ( struct V_583 * V_584 ,
struct V_585 * V_586 )
{
V_586 -> type = V_587 ;
V_586 -> V_35 = 1 ;
V_586 -> V_38 . integer . V_588 = 0 ;
V_586 -> V_38 . integer . V_127 = V_576 ;
return 0 ;
}
static int F_325 ( struct V_583 * V_584 ,
struct V_589 * V_590 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_314 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_590 -> V_38 . integer . V_38 [ 0 ] = V_118 & V_572 ;
return 0 ;
}
static int F_326 ( struct V_583 * V_584 ,
struct V_589 * V_590 )
{
F_82 ( L_334 , L_335 ,
V_590 -> V_38 . integer . V_38 [ 0 ] ) ;
return F_321 ( V_590 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static int F_327 ( struct V_583 * V_584 ,
struct V_589 * V_590 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_314 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_590 -> V_38 . integer . V_38 [ 0 ] =
( V_118 & V_571 ) ? 0 : 1 ;
return 0 ;
}
static int F_328 ( struct V_583 * V_584 ,
struct V_589 * V_590 )
{
F_82 ( L_334 , L_336 ,
V_590 -> V_38 . integer . V_38 [ 0 ] ?
L_42 : L_1 ) ;
return F_318 ( ! V_590 -> V_38 . integer . V_38 [ 0 ] ) ;
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
if ( V_578 ) {
F_333 ( V_578 ) ;
V_578 = NULL ;
}
F_312 () ;
}
static int T_1 F_334 ( void )
{
struct V_591 * V_592 ;
struct V_577 * V_66 ;
struct V_583 * V_593 ;
struct V_583 * V_594 ;
int V_73 ;
V_73 = F_335 ( V_595 , V_596 , V_597 ,
sizeof( struct V_577 ) , & V_592 ) ;
if ( V_73 < 0 || ! V_592 ) {
F_8 ( L_337 , V_73 ) ;
return 1 ;
}
F_25 ( ! V_592 -> V_579 ) ;
V_66 = V_592 -> V_579 ;
V_66 -> V_592 = V_592 ;
F_336 ( V_592 -> V_81 , V_598 ,
sizeof( V_592 -> V_81 ) ) ;
F_336 ( V_592 -> V_599 , V_600 ,
sizeof( V_592 -> V_599 ) ) ;
snprintf ( V_592 -> V_601 , sizeof( V_592 -> V_601 ) , L_338 ,
( V_7 . V_602 ) ?
V_7 . V_602 : L_339 ) ;
snprintf ( V_592 -> V_603 , sizeof( V_592 -> V_603 ) ,
L_340 , V_592 -> V_599 , V_574 ,
( V_7 . V_602 ) ?
V_7 . V_602 : L_341 ) ;
if ( V_568 ) {
V_604 . V_605 = F_326 ;
V_604 . V_606 =
V_607 ;
V_608 . V_605 = F_328 ;
V_608 . V_606 =
V_607 ;
}
if ( ! V_186 . V_570 ) {
V_593 = F_337 ( & V_604 , NULL ) ;
V_73 = F_338 ( V_592 , V_593 ) ;
if ( V_73 < 0 ) {
F_8 ( L_342 ,
V_73 ) ;
goto V_329;
}
V_66 -> V_582 = & V_593 -> V_144 ;
}
V_594 = F_337 ( & V_608 , NULL ) ;
V_73 = F_338 ( V_592 , V_594 ) ;
if ( V_73 < 0 ) {
F_8 ( L_343 , V_73 ) ;
goto V_329;
}
V_66 -> V_580 = & V_594 -> V_144 ;
F_339 ( V_592 , & V_154 -> V_60 ) ;
V_73 = F_340 ( V_592 ) ;
if ( V_73 < 0 ) {
F_8 ( L_344 , V_73 ) ;
goto V_329;
}
V_578 = V_592 ;
return 0 ;
V_329:
F_333 ( V_592 ) ;
return 1 ;
}
static int T_1 F_341 ( struct V_294 * V_295 )
{
unsigned long V_13 ;
int V_73 ;
F_17 ( V_55 , L_345 ) ;
F_182 ( & V_573 ) ;
if ( V_566 > V_609 )
return - V_94 ;
if ( V_566 == V_610 ) {
F_8 ( L_346
L_295 , V_330 ) ;
return 1 ;
}
if ( V_611 >= V_612 )
return - V_94 ;
if ( ! V_613 ) {
F_17 ( V_55 | V_569 ,
L_347
L_348 ) ;
return 1 ;
}
V_13 = F_4 ( V_614 ,
F_100 ( V_614 ) ) ;
switch ( V_611 ) {
case V_615 :
if ( V_13 & V_616 )
V_186 . V_570 = 1 ;
else if ( V_13 & V_617 )
V_186 . V_570 = 0 ;
else
return 1 ;
break;
case V_618 :
V_186 . V_570 = 0 ;
break;
case V_619 :
V_186 . V_570 = 1 ;
break;
default:
return 1 ;
}
if ( V_611 != V_615 )
F_20 ( V_55 | V_569 ,
L_349 ,
V_611 ) ;
if ( V_566 == V_620 ||
V_566 == V_609 ) {
V_566 = V_567 ;
F_20 ( V_55 | V_569 ,
L_350 ,
V_566 ) ;
} else {
F_20 ( V_55 | V_569 ,
L_351 ,
V_566 ) ;
}
F_17 ( V_55 | V_569 ,
L_352 ,
F_1 ( ! V_186 . V_570 ) ) ;
V_73 = F_334 () ;
if ( V_73 ) {
F_8 ( L_353 ) ;
return V_73 ;
}
F_76 ( L_354 ,
( V_568 ) ?
L_355 :
L_356 ) ;
F_17 ( V_55 | V_569 ,
L_357 ) ;
F_114 ( V_195
| V_621
| V_622
| V_623 ) ;
return 0 ;
}
static int F_342 ( struct V_90 * V_91 )
{
T_6 V_30 ;
if ( F_314 ( & V_30 ) < 0 ) {
F_84 ( V_91 , L_317 ) ;
} else {
if ( V_186 . V_570 )
F_84 ( V_91 , L_358 ) ;
else
F_84 ( V_91 , L_318 ,
V_30 & V_572 ) ;
F_84 ( V_91 , L_359 ,
F_253 ( V_30 , V_624 ) ) ;
if ( V_568 ) {
F_84 ( V_91 , L_360 ) ;
if ( ! V_186 . V_570 ) {
F_84 ( V_91 ,
L_319 ) ;
F_84 ( V_91 ,
L_361
L_362 ,
V_576 ) ;
}
}
}
return 0 ;
}
static int F_343 ( char * V_126 )
{
T_6 V_118 ;
T_6 V_625 , V_626 ;
int V_627 ;
char * V_159 ;
int V_73 ;
if ( ! V_568 && V_69 != V_280 ) {
if ( F_140 ( ! V_200 . V_628 ) ) {
V_200 . V_628 = 1 ;
F_32 ( L_363
L_364 ) ;
F_32 ( L_365
L_366 ) ;
}
return - V_158 ;
}
V_73 = F_314 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_625 = V_118 & V_572 ;
V_626 = V_118 & V_571 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! V_186 . V_570 ) {
if ( F_86 ( V_159 , L_321 ) == 0 ) {
if ( V_626 )
V_626 = 0 ;
else if ( V_625 < V_576 )
V_625 ++ ;
continue;
} else if ( F_86 ( V_159 , L_322 ) == 0 ) {
if ( V_626 )
V_626 = 0 ;
else if ( V_625 > 0 )
V_625 -- ;
continue;
} else if ( sscanf ( V_159 , L_367 , & V_627 ) == 1 &&
V_627 >= 0 && V_627 <= V_576 ) {
V_625 = V_627 ;
continue;
}
}
if ( F_86 ( V_159 , L_368 ) == 0 )
V_626 = V_571 ;
else if ( F_86 ( V_159 , L_369 ) == 0 )
V_626 = 0 ;
else
return - V_94 ;
}
if ( V_186 . V_570 ) {
F_82 ( L_370 , L_336 ,
V_626 ? L_1 : L_42 ) ;
V_73 = F_319 ( ! ! V_626 ) ;
} else {
F_82 ( L_370 ,
L_371 ,
V_626 ? L_1 : L_42 , V_625 ) ;
V_73 = F_316 ( V_626 | V_625 ) ;
}
F_322 () ;
return ( V_73 == - V_564 ) ? - V_282 : V_73 ;
}
static void inline F_322 ( void )
{
}
static int T_1 F_341 ( struct V_294 * V_295 )
{
F_76 ( L_372 ) ;
return 1 ;
}
static void F_344 ( void )
{
if ( V_629 == 0x07 ) {
F_32 ( L_373
L_374 ) ;
V_186 . V_630 = 1 ;
}
}
static void F_345 ( T_6 * V_631 )
{
if ( F_140 ( V_186 . V_630 ) ) {
if ( * V_631 != V_629 ) {
V_186 . V_630 = 0 ;
} else {
* V_631 = V_632 ;
}
}
}
static bool F_346 ( void )
{
if ( V_186 . V_633 ) {
T_6 V_634 ;
if ( F_12 ( V_635 , & V_634 ) < 0 )
return false ;
V_634 &= 0xFEU ;
if ( F_14 ( V_635 , V_634 ) < 0 )
return false ;
}
return true ;
}
static bool F_347 ( void )
{
T_6 V_634 ;
if ( ! V_186 . V_633 )
return false ;
if ( F_12 ( V_635 , & V_634 ) < 0 )
return false ;
V_634 |= 0x01U ;
if ( F_14 ( V_635 , V_634 ) < 0 )
return false ;
return true ;
}
static void F_348 ( T_6 V_30 )
{
if ( ( V_30 &
( V_632 | V_636 ) ) == 0 ) {
if ( V_30 > 7 )
V_637 = 7 ;
else
V_637 = V_30 ;
}
}
static int F_349 ( T_6 * V_30 )
{
T_6 V_118 ;
switch ( V_638 ) {
case V_639 : {
int V_17 ;
if ( F_140 ( ! F_7 ( V_640 , & V_17 , NULL , L_64 ) ) )
return - V_50 ;
if ( F_138 ( V_30 ) )
* V_30 = V_17 & 0x07 ;
break;
}
case V_641 :
if ( F_140 ( ! F_11 ( V_642 , & V_118 ) ) )
return - V_50 ;
if ( F_138 ( V_30 ) ) {
* V_30 = V_118 ;
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
int V_73 ;
T_6 V_118 ;
if ( F_156 ( & V_643 ) )
return - V_282 ;
V_73 = F_349 ( & V_118 ) ;
if ( ! V_73 )
F_348 ( V_118 ) ;
F_118 ( & V_643 ) ;
if ( V_30 )
* V_30 = V_118 ;
return V_73 ;
}
static int F_351 ( unsigned int * V_644 )
{
T_6 V_645 , V_646 ;
switch ( V_638 ) {
case V_641 :
if ( F_140 ( ! F_346 () ) )
return - V_50 ;
if ( F_140 ( ! F_11 ( V_647 , & V_646 ) ||
! F_11 ( V_647 + 1 , & V_645 ) ) )
return - V_50 ;
if ( F_138 ( V_644 ) )
* V_644 = ( V_645 << 8 ) | V_646 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_352 ( unsigned int * V_644 )
{
T_6 V_645 , V_646 ;
bool V_73 ;
switch ( V_638 ) {
case V_641 :
if ( F_140 ( ! F_347 () ) )
return - V_50 ;
V_73 = ! F_11 ( V_647 , & V_646 ) ||
! F_11 ( V_647 + 1 , & V_645 ) ;
F_346 () ;
if ( V_73 )
return - V_50 ;
if ( F_138 ( V_644 ) )
* V_644 = ( V_645 << 8 ) | V_646 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_353 ( int V_56 )
{
if ( ! V_648 )
return - V_158 ;
switch ( V_649 ) {
case V_650 :
if ( V_56 >= 0 && V_56 <= 7 ) {
if ( ! F_7 ( V_651 , NULL , NULL , L_9 , V_56 ) )
return - V_50 ;
} else
return - V_94 ;
break;
case V_652 :
case V_653 :
if ( ! ( V_56 & V_632 ) &&
! ( V_56 & V_636 ) &&
( ( V_56 < 0 ) || ( V_56 > 7 ) ) )
return - V_94 ;
if ( V_56 & V_636 )
V_56 |= 7 ;
else if ( V_56 & V_632 )
V_56 |= 4 ;
if ( ! F_13 ( V_642 , V_56 ) )
return - V_50 ;
else
V_186 . V_630 = 0 ;
break;
default:
return - V_49 ;
}
F_17 ( V_654 ,
L_375 , V_56 ) ;
return 0 ;
}
static int F_354 ( int V_56 )
{
int V_73 ;
if ( ! V_648 )
return - V_158 ;
if ( F_156 ( & V_643 ) )
return - V_282 ;
if ( V_56 == V_655 )
V_56 = V_637 ;
V_73 = F_353 ( V_56 ) ;
if ( ! V_73 )
F_348 ( V_56 ) ;
F_118 ( & V_643 ) ;
return V_73 ;
}
static int F_355 ( void )
{
T_6 V_118 ;
int V_73 ;
if ( ! V_648 )
return - V_158 ;
if ( F_156 ( & V_643 ) )
return - V_282 ;
switch ( V_649 ) {
case V_652 :
case V_653 :
V_73 = F_349 ( & V_118 ) ;
if ( V_73 < 0 )
break;
if ( V_118 != 7 ) {
V_118 &= 0x07 ;
V_118 |= V_632 | 4 ;
}
if ( ! F_13 ( V_642 , V_118 ) )
V_73 = - V_50 ;
else {
V_186 . V_630 = 0 ;
V_73 = 0 ;
}
break;
case V_650 :
V_73 = F_349 ( & V_118 ) ;
if ( V_73 < 0 )
break;
V_118 &= 0x07 ;
V_118 |= 4 ;
if ( ! F_7 ( V_651 , NULL , NULL , L_9 , V_118 ) )
V_73 = - V_50 ;
else
V_73 = 0 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_643 ) ;
if ( ! V_73 )
F_17 ( V_654 ,
L_375 ,
V_118 ) ;
return V_73 ;
}
static int F_356 ( void )
{
int V_73 ;
if ( ! V_648 )
return - V_158 ;
if ( F_156 ( & V_643 ) )
return - V_282 ;
V_73 = 0 ;
switch ( V_649 ) {
case V_652 :
case V_653 :
if ( ! F_13 ( V_642 , 0x00 ) )
V_73 = - V_50 ;
else {
V_637 = 0 ;
V_186 . V_630 = 0 ;
}
break;
case V_650 :
if ( ! F_7 ( V_651 , NULL , NULL , L_9 , 0x00 ) )
V_73 = - V_50 ;
else
V_637 = 0 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
F_17 ( V_654 ,
L_376 ) ;
F_118 ( & V_643 ) ;
return V_73 ;
}
static int F_357 ( int V_644 )
{
int V_73 ;
if ( ! V_648 )
return - V_158 ;
if ( F_156 ( & V_643 ) )
return - V_282 ;
V_73 = 0 ;
switch ( V_649 ) {
case V_652 :
if ( V_644 >= 0 && V_644 <= 65535 ) {
if ( ! F_7 ( V_656 , NULL , NULL , L_377 ,
V_644 , V_644 , V_644 ) )
V_73 = - V_50 ;
} else
V_73 = - V_94 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_643 ) ;
return V_73 ;
}
static void F_358 ( void )
{
if ( V_649 == V_657 )
return;
if ( V_658 > 0 &&
V_69 != V_199 )
F_359 ( V_444 , & V_659 ,
F_360 ( V_658 * 1000 ) ) ;
else
F_361 ( & V_659 ) ;
}
static void F_362 ( struct V_433 * V_660 )
{
int V_73 ;
if ( V_69 != V_70 )
return;
F_32 ( L_378 ) ;
V_73 = F_355 () ;
if ( V_73 < 0 ) {
F_8 ( L_379
L_380 , - V_73 ) ;
F_358 () ;
}
}
static T_8 F_363 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_661 ;
T_6 V_30 ;
V_17 = F_350 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 & V_636 ) {
V_661 = 0 ;
} else if ( V_30 & V_632 ) {
V_661 = 2 ;
} else
V_661 = 1 ;
return snprintf ( V_126 , V_102 , L_44 , V_661 ) ;
}
static T_8 F_364 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 , V_56 ;
if ( F_57 ( V_126 , 2 , & V_157 ) )
return - V_94 ;
F_82 ( L_381 ,
L_382 , V_157 ) ;
switch ( V_157 ) {
case 0 :
V_56 = V_636 ;
break;
case 1 :
V_56 = V_655 ;
break;
case 2 :
V_56 = V_632 ;
break;
case 3 :
return - V_421 ;
default:
return - V_94 ;
}
V_17 = F_354 ( V_56 ) ;
if ( V_17 == - V_49 )
return - V_94 ;
else if ( V_17 < 0 )
return V_17 ;
F_358 () ;
return V_35 ;
}
static T_8 F_365 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
T_6 V_30 ;
V_17 = F_350 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_30 &
( V_632 | V_636 ) ) != 0 )
V_30 = V_637 ;
if ( V_30 > 7 )
V_30 = 7 ;
return snprintf ( V_126 , V_102 , L_383 , ( V_30 * 255 ) / 7 ) ;
}
static T_8 F_366 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_118 ;
int V_73 ;
T_6 V_30 , V_662 ;
if ( F_57 ( V_126 , 255 , & V_118 ) )
return - V_94 ;
F_82 ( L_384 ,
L_385 , V_118 ) ;
V_662 = ( V_118 >> 5 ) & 0x07 ;
if ( F_156 ( & V_643 ) )
return - V_282 ;
V_73 = F_349 ( & V_30 ) ;
if ( ! V_73 && ( V_30 &
( V_632 | V_636 ) ) == 0 ) {
V_73 = F_353 ( V_662 ) ;
if ( V_73 == - V_49 )
V_73 = - V_94 ;
else if ( ! V_73 ) {
F_348 ( V_662 ) ;
F_358 () ;
}
}
F_118 ( & V_643 ) ;
return ( V_73 ) ? V_73 : V_35 ;
}
static T_8 F_367 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_644 ;
V_17 = F_351 ( & V_644 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_383 , V_644 ) ;
}
static T_8 F_368 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_644 ;
V_17 = F_352 ( & V_644 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_383 , V_644 ) ;
}
static T_8 F_369 ( struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_383 , V_658 ) ;
}
static T_8 F_370 ( struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 120 , & V_157 ) )
return - V_94 ;
if ( ! V_648 )
return - V_158 ;
V_658 = V_157 ;
F_358 () ;
F_82 ( L_386 , L_96 , V_157 ) ;
return V_35 ;
}
static int T_1 F_371 ( struct V_294 * V_295 )
{
int V_73 ;
unsigned long V_13 ;
F_17 ( V_55 | V_654 ,
L_387 ) ;
F_182 ( & V_643 ) ;
V_638 = V_663 ;
V_649 = V_657 ;
V_664 = 0 ;
V_658 = 0 ;
V_186 . V_630 = 0 ;
V_186 . V_633 = 0 ;
V_637 = 7 ;
if ( F_6 () ) {
F_181 ( V_665 ) ;
F_181 ( V_666 ) ;
F_181 ( V_667 ) ;
}
V_13 = F_4 ( V_668 ,
F_100 ( V_668 ) ) ;
if ( V_640 ) {
V_638 = V_639 ;
} else {
if ( F_138 ( F_11 ( V_642 ,
& V_629 ) ) ) {
V_638 = V_641 ;
if ( V_13 & V_669 )
F_344 () ;
if ( V_13 & V_670 ) {
V_186 . V_633 = 1 ;
F_20 ( V_55 | V_654 ,
L_388 ) ;
}
} else {
F_8 ( L_276
L_389 ) ;
return 1 ;
}
}
if ( V_651 ) {
V_649 = V_650 ;
V_664 |=
V_671 | V_672 ;
} else {
if ( ! V_640 ) {
if ( V_656 ) {
V_649 =
V_652 ;
V_664 |=
V_673 |
V_671 |
V_672 ;
} else {
V_649 = V_653 ;
V_664 |=
V_671 |
V_672 ;
}
}
}
F_17 ( V_55 | V_654 ,
L_390 ,
F_1 ( V_638 != V_663 ||
V_649 != V_657 ) ,
V_638 , V_649 ) ;
if ( ! V_648 ) {
V_649 = V_657 ;
V_664 = 0 ;
F_20 ( V_55 | V_654 ,
L_391 ) ;
}
if ( V_638 != V_663 )
F_350 ( NULL ) ;
if ( V_638 != V_663 ||
V_649 != V_657 ) {
if ( V_186 . V_633 ) {
V_674 [ F_100 ( V_674 ) - 2 ] =
& V_675 . V_122 ;
}
V_73 = F_212 ( & V_510 -> V_60 . V_125 ,
& V_676 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_101 ( & V_677 . V_81 ,
& V_678 ) ;
if ( V_73 < 0 ) {
F_55 ( & V_510 -> V_60 . V_125 ,
& V_676 ) ;
return V_73 ;
}
return 0 ;
} else
return 1 ;
}
static void F_372 ( void )
{
F_17 ( V_291 | V_654 ,
L_392 ) ;
F_55 ( & V_510 -> V_60 . V_125 , & V_676 ) ;
F_104 ( & V_677 . V_81 ,
& V_678 ) ;
F_361 ( & V_659 ) ;
F_251 ( V_444 ) ;
}
static void F_373 ( void )
{
int V_73 ;
if ( ! V_648 )
return;
V_679 = 0 ;
V_73 = F_350 ( & V_679 ) ;
if ( V_73 < 0 )
F_32 ( L_393
L_394 , V_73 ) ;
if ( V_186 . V_630 )
V_679 = 0 ;
}
static void F_374 ( void )
{
T_6 V_680 = 7 ;
bool V_681 = false ;
int V_73 ;
V_186 . V_630 = 0 ;
if ( ! V_648 ||
! V_679 ||
( F_350 ( & V_680 ) < 0 ) )
return;
switch ( V_649 ) {
case V_650 :
V_681 = ( V_679 > V_680 ) ;
break;
case V_652 :
case V_653 :
if ( V_679 != 7 &&
! ( V_679 & V_636 ) )
return;
else
V_681 = ! ( V_680 & V_636 ) &&
( V_680 != V_679 ) ;
break;
default:
return;
}
if ( V_681 ) {
F_32 ( L_395 ,
V_679 ) ;
V_73 = F_354 ( V_679 ) ;
if ( V_73 < 0 )
F_32 ( L_396 , V_73 ) ;
}
}
static int F_375 ( struct V_90 * V_91 )
{
int V_73 ;
T_6 V_30 ;
unsigned int V_644 = 0 ;
switch ( V_638 ) {
case V_639 :
V_73 = F_350 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47
L_318 ,
( V_30 != 0 ) ? L_48 : L_49 , V_30 ) ;
break;
case V_641 :
V_73 = F_350 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47 ,
( V_30 != 0 ) ? L_48 : L_49 ) ;
V_73 = F_351 ( & V_644 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_397 , V_644 ) ;
if ( V_30 & V_636 )
F_84 ( V_91 , L_398 ) ;
else if ( V_30 & V_632 )
F_84 ( V_91 , L_399 ) ;
else
F_84 ( V_91 , L_318 , V_30 ) ;
break;
case V_663 :
default:
F_84 ( V_91 , L_46 ) ;
}
if ( V_664 & V_671 ) {
F_84 ( V_91 , L_361 ) ;
switch ( V_649 ) {
case V_650 :
F_84 ( V_91 , L_400 ) ;
break;
default:
F_84 ( V_91 , L_401
L_402 ) ;
break;
}
}
if ( V_664 & V_672 )
F_84 ( V_91 , L_50
L_403
L_404 ) ;
if ( V_664 & V_673 )
F_84 ( V_91 , L_405
L_406 ) ;
return 0 ;
}
static int F_376 ( const char * V_159 , int * V_73 )
{
int V_56 ;
if ( F_86 ( V_159 , L_407 ) == 0 )
V_56 = V_632 ;
else if ( ( F_86 ( V_159 , L_408 ) == 0 ) |
( F_86 ( V_159 , L_409 ) == 0 ) )
V_56 = V_636 ;
else if ( sscanf ( V_159 , L_323 , & V_56 ) != 1 )
return 0 ;
* V_73 = F_354 ( V_56 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_410 ,
V_649 ) ;
else if ( ! * V_73 )
F_82 ( L_411 ,
L_325 , V_56 ) ;
return 1 ;
}
static int F_377 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_51 ) != 0 )
return 0 ;
* V_73 = F_355 () ;
if ( * V_73 == - V_49 )
F_8 ( L_412 ,
V_649 ) ;
else if ( ! * V_73 )
F_82 ( L_411 , L_413 ) ;
return 1 ;
}
static int F_378 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_52 ) != 0 )
return 0 ;
* V_73 = F_356 () ;
if ( * V_73 == - V_49 )
F_8 ( L_414 ,
V_649 ) ;
else if ( ! * V_73 )
F_82 ( L_411 , L_415 ) ;
return 1 ;
}
static int F_379 ( const char * V_159 , int * V_73 )
{
int V_644 ;
if ( sscanf ( V_159 , L_416 , & V_644 ) != 1 )
return 0 ;
* V_73 = F_357 ( V_644 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_417 ,
V_649 ) ;
else if ( ! * V_73 )
F_82 ( L_411 ,
L_418 , V_644 ) ;
return 1 ;
}
static int F_380 ( const char * V_159 , int * V_73 )
{
int V_682 ;
if ( sscanf ( V_159 , L_419 , & V_682 ) != 1 )
return 0 ;
if ( V_682 < 0 || V_682 > 120 )
* V_73 = - V_94 ;
else {
V_658 = V_682 ;
F_82 ( L_411 ,
L_420 ,
V_682 ) ;
}
return 1 ;
}
static int F_381 ( char * V_126 )
{
char * V_159 ;
int V_73 = 0 ;
while ( ! V_73 && ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! ( ( V_664 & V_671 ) &&
F_376 ( V_159 , & V_73 ) ) &&
! ( ( V_664 & V_672 ) &&
( F_377 ( V_159 , & V_73 ) ||
F_378 ( V_159 , & V_73 ) ||
F_380 ( V_159 , & V_73 ) ) ) &&
! ( ( V_664 & V_673 ) &&
F_379 ( V_159 , & V_73 ) )
)
V_73 = - V_94 ;
else if ( ! V_73 )
F_358 () ;
}
return V_73 ;
}
static int F_382 ( struct V_683 * V_157 , bool V_205 )
{
T_3 V_502 ;
int V_684 ;
if ( ! F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_502 ) ) ) {
F_62 ( L_421 , V_157 -> V_51 ) ;
return - V_50 ;
}
if ( ! F_7 ( V_129 , & V_684 , V_157 -> V_51 , L_7 ,
V_205 ? V_157 -> V_685 : V_157 -> V_686 ) )
return - V_50 ;
V_157 -> V_205 = V_205 ;
return V_205 ;
}
int F_383 ( int V_687 , bool V_688 )
{
struct V_683 * V_157 ;
if ( V_687 < 0 || V_687 >= V_689 )
return - V_94 ;
V_157 = & V_690 [ V_687 ] ;
if ( V_157 -> V_205 < 0 || V_157 -> V_205 == V_688 )
return V_157 -> V_205 ;
return F_382 ( V_157 , V_688 ) ;
}
static int F_384 ( struct V_294 * V_295 )
{
T_3 V_502 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_689 ; V_42 ++ ) {
struct V_683 * V_157 = & V_690 [ V_42 ] ;
if ( F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_502 ) ) )
F_382 ( V_157 , false ) ;
else
V_157 -> V_205 = - V_75 ;
}
return 0 ;
}
static void F_385 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_689 ; V_42 ++ )
F_383 ( V_42 , false ) ;
}
static void F_386 ( const unsigned int V_691 )
{
if ( V_537 ) {
switch ( V_691 ) {
case V_692 :
case V_693 :
F_296 () ;
}
}
if ( V_578 ) {
switch ( V_691 ) {
case V_694 :
case V_695 :
case V_696 :
F_322 () ;
}
}
}
static void F_128 ( const unsigned int V_210 )
{
F_386 ( V_697 + V_210 ) ;
}
static T_8 F_387 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_422 , V_85 ) ;
}
static const char * T_1 F_1 ( int V_1 )
{
static char V_698 [] V_699 = L_423 ;
return ( V_1 ) ? & V_698 [ 4 ] : & V_698 [ 0 ] ;
}
static void F_388 ( struct V_67 * V_68 )
{
F_20 ( V_291 , L_424 , V_68 -> V_51 ) ;
F_389 ( & V_68 -> V_700 ) ;
if ( V_68 -> V_79 . V_80 ) {
F_20 ( V_291 ,
L_425 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_390 ( * V_68 -> V_71 -> V_16 ,
V_68 -> V_71 -> type ,
F_27 ) ;
V_68 -> V_79 . V_80 = 0 ;
}
if ( V_68 -> V_79 . V_701 ) {
F_20 ( V_291 ,
L_426 , V_68 -> V_51 ) ;
F_391 ( V_68 -> V_51 , V_702 ) ;
V_68 -> V_79 . V_701 = 0 ;
}
if ( V_68 -> V_79 . V_89 ) {
F_20 ( V_291 ,
L_427 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_392 ( V_68 -> V_71 -> V_81 ) ;
F_37 ( V_68 -> V_71 -> V_81 ) ;
V_68 -> V_71 -> V_81 = NULL ;
V_68 -> V_79 . V_89 = 0 ;
}
if ( V_68 -> V_79 . V_703 && V_68 -> exit ) {
V_68 -> exit () ;
V_68 -> V_79 . V_703 = 0 ;
}
F_20 ( V_55 , L_428 , V_68 -> V_51 ) ;
}
static int T_1 F_393 ( struct V_294 * V_295 )
{
int V_100 ;
struct V_67 * V_68 = V_295 -> V_66 ;
struct V_704 * V_705 ;
F_25 ( V_68 == NULL ) ;
F_394 ( & V_68 -> V_700 ) ;
if ( V_68 -> V_79 . V_706 && ! V_706 )
return 0 ;
F_20 ( V_55 ,
L_429 , V_68 -> V_51 ) ;
if ( V_295 -> V_707 ) {
V_100 = V_295 -> V_707 ( V_295 ) ;
if ( V_100 > 0 )
return 0 ;
if ( V_100 )
return V_100 ;
V_68 -> V_79 . V_703 = 1 ;
}
if ( V_68 -> V_71 ) {
if ( V_68 -> V_71 -> V_63 ) {
V_100 = F_34 ( V_68 ) ;
if ( V_100 )
goto V_708;
}
if ( V_68 -> V_71 -> V_72 ) {
V_100 = F_28 ( V_68 ) ;
if ( V_100 == - V_75 ) {
F_32 ( L_430 ,
V_68 -> V_51 ) ;
V_100 = 0 ;
goto V_708;
}
if ( V_100 < 0 )
goto V_708;
}
}
F_20 ( V_55 ,
L_431 , V_68 -> V_51 ) ;
if ( V_68 -> V_93 ) {
T_19 V_661 = V_295 -> V_709 ;
if ( ! V_661 )
V_661 = V_710 ;
if ( V_68 -> V_101 )
V_661 |= V_711 ;
V_705 = F_395 ( V_68 -> V_51 , V_661 , V_702 ,
& V_712 , V_68 ) ;
if ( ! V_705 ) {
F_8 ( L_432 , V_68 -> V_51 ) ;
V_100 = - V_75 ;
goto V_708;
}
V_68 -> V_79 . V_701 = 1 ;
}
F_396 ( & V_68 -> V_700 , & V_713 ) ;
return 0 ;
V_708:
F_20 ( V_55 ,
L_433 ,
V_68 -> V_51 , V_100 ) ;
F_388 ( V_68 ) ;
return ( V_100 < 0 ) ? V_100 : 0 ;
}
static bool T_2 T_1 F_397 ( const char V_37 )
{
return ( V_37 >= '0' && V_37 <= '9' ) || ( V_37 >= 'A' && V_37 <= 'Z' ) ;
}
static bool T_2 T_1 F_398 ( const char * const V_118 ,
const char V_157 )
{
return V_118 && strlen ( V_118 ) >= 8 &&
F_397 ( V_118 [ 0 ] ) &&
F_397 ( V_118 [ 1 ] ) &&
V_118 [ 2 ] == V_157 &&
( V_118 [ 3 ] == 'T' || V_118 [ 3 ] == 'N' ) &&
F_397 ( V_118 [ 4 ] ) &&
F_397 ( V_118 [ 5 ] ) ;
}
static int T_20 T_1 F_399 (
struct V_714 * V_715 )
{
const struct V_716 * V_60 = NULL ;
char V_717 [ 18 ] ;
char const * V_118 ;
if ( ! V_715 )
return - V_94 ;
memset ( V_715 , 0 , sizeof( * V_715 ) ) ;
if ( F_400 ( L_434 ) )
V_715 -> V_6 = V_15 ;
else if ( F_400 ( L_435 ) )
V_715 -> V_6 = V_14 ;
else
return 0 ;
V_118 = F_401 ( V_718 ) ;
V_715 -> V_719 = F_402 ( V_118 , V_83 ) ;
if ( V_118 && ! V_715 -> V_719 )
return - V_84 ;
if ( ! ( F_398 ( V_715 -> V_719 , 'E' ) ||
F_398 ( V_715 -> V_719 , 'C' ) ) )
return 0 ;
V_715 -> V_10 = V_715 -> V_719 [ 0 ]
| ( V_715 -> V_719 [ 1 ] << 8 ) ;
V_715 -> V_184 = ( V_715 -> V_719 [ 4 ] << 8 )
| V_715 -> V_719 [ 5 ] ;
while ( ( V_60 = F_403 ( V_720 , NULL , V_60 ) ) ) {
if ( sscanf ( V_60 -> V_51 ,
L_436 ,
V_717 ) == 1 ) {
V_717 [ sizeof( V_717 ) - 1 ] = 0 ;
V_717 [ strcspn ( V_717 , L_437 ) ] = 0 ;
V_715 -> V_602 = F_402 ( V_717 , V_83 ) ;
if ( ! V_715 -> V_602 )
return - V_84 ;
if ( F_398 ( V_717 , 'H' ) ) {
V_715 -> V_12 = V_717 [ 0 ]
| ( V_717 [ 1 ] << 8 ) ;
V_715 -> V_185 = ( V_717 [ 4 ] << 8 )
| V_717 [ 5 ] ;
} else {
F_32 ( L_438
L_439 ,
V_717 ) ;
F_32 ( L_109 ,
V_330 ) ;
}
break;
}
}
V_118 = F_401 ( V_721 ) ;
if ( V_118 && ! ( F_404 ( V_118 , L_440 , 8 ) && F_404 ( V_118 , L_441 , 6 ) ) ) {
V_715 -> V_722 = F_402 ( V_118 , V_83 ) ;
if ( ! V_715 -> V_722 )
return - V_84 ;
} else {
V_118 = F_401 ( V_723 ) ;
if ( V_118 && ! ( F_404 ( V_118 , L_441 , 6 ) ) ) {
V_715 -> V_722 = F_402 ( V_118 , V_83 ) ;
if ( ! V_715 -> V_722 )
return - V_84 ;
}
}
V_118 = F_401 ( V_724 ) ;
V_715 -> V_725 = F_402 ( V_118 , V_83 ) ;
if ( V_118 && ! V_715 -> V_725 )
return - V_84 ;
return 0 ;
}
static int T_1 F_405 ( void )
{
int V_726 ;
if ( V_727 )
return - V_75 ;
if ( ! F_6 () && ! F_5 () )
return - V_75 ;
V_726 = ( V_7 . V_722 != NULL ) ||
( V_7 . V_12 != 0 ) ||
F_107 () ;
F_24 ( L_442 , V_728 , & V_425 ) ;
if ( ! V_425 ) {
if ( V_726 )
F_8 ( L_443 ) ;
return - V_75 ;
}
if ( ! V_726 && ! V_729 )
return - V_75 ;
return 0 ;
}
static void T_1 F_406 ( void )
{
F_76 ( L_57 , V_165 , V_166 ) ;
F_76 ( L_422 , V_730 ) ;
F_76 ( L_444 ,
( V_7 . V_719 ) ?
V_7 . V_719 : L_341 ,
( V_7 . V_602 ) ?
V_7 . V_602 : L_341 ) ;
F_25 ( ! V_7 . V_6 ) ;
if ( V_7 . V_722 )
F_76 ( L_445 ,
( V_7 . V_6 == V_15 ) ?
L_434 : ( ( V_7 . V_6 ==
V_14 ) ?
L_441 : L_446 ) ,
V_7 . V_722 ,
( V_7 . V_725 ) ?
V_7 . V_725 : L_341 ) ;
}
static int T_1 F_407 ( const char * V_634 , struct V_731 * V_732 )
{
unsigned int V_42 ;
struct V_67 * V_68 ;
if ( ! V_732 || ! V_732 -> V_51 || ! V_634 )
return - V_94 ;
for ( V_42 = 0 ; V_42 < F_100 ( V_733 ) ; V_42 ++ ) {
V_68 = V_733 [ V_42 ] . V_66 ;
F_408 ( V_68 == NULL ) ;
if ( ! V_68 || ! V_68 -> V_51 )
continue;
if ( strcmp ( V_68 -> V_51 , V_732 -> V_51 ) == 0 && V_68 -> V_101 ) {
if ( strlen ( V_634 ) > sizeof( V_733 [ V_42 ] . V_734 ) - 2 )
return - V_735 ;
strcpy ( V_733 [ V_42 ] . V_734 , V_634 ) ;
strcat ( V_733 [ V_42 ] . V_734 , L_28 ) ;
return 0 ;
}
}
return - V_94 ;
}
static void F_409 ( void )
{
struct V_67 * V_68 , * V_107 ;
V_69 = V_199 ;
F_410 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
F_388 ( V_68 ) ;
}
F_20 ( V_55 , L_447 ) ;
if ( V_208 ) {
if ( V_186 . V_736 )
F_411 ( V_208 ) ;
else
F_412 ( V_208 ) ;
F_37 ( V_212 ) ;
}
if ( V_737 )
F_413 ( V_737 ) ;
if ( V_186 . V_738 )
F_259 ( & V_510 -> V_60 ,
& V_739 ) ;
if ( V_510 )
F_414 ( V_510 ) ;
if ( V_154 )
F_414 ( V_154 ) ;
if ( V_186 . V_740 )
F_103 ( & V_677 . V_81 ) ;
if ( V_186 . V_741 )
F_103 ( & V_742 . V_81 ) ;
if ( V_186 . V_743 )
F_415 ( & V_677 ) ;
if ( V_186 . V_744 )
F_415 ( & V_742 ) ;
if ( V_702 )
F_391 ( V_745 , V_746 ) ;
if ( V_444 )
F_416 ( V_444 ) ;
F_37 ( V_7 . V_719 ) ;
F_37 ( V_7 . V_602 ) ;
F_37 ( V_7 . V_722 ) ;
F_37 ( V_7 . V_725 ) ;
}
static int T_1 F_417 ( void )
{
int V_100 , V_42 ;
V_69 = V_280 ;
V_100 = F_399 ( & V_7 ) ;
if ( V_100 ) {
F_8 ( L_448 , V_100 ) ;
F_409 () ;
return V_100 ;
}
V_100 = F_405 () ;
if ( V_100 ) {
F_409 () ;
return V_100 ;
}
F_406 () ;
F_106 () ;
F_181 ( V_747 ) ;
F_181 ( V_748 ) ;
V_444 = F_418 ( V_749 ) ;
if ( ! V_444 ) {
F_409 () ;
return - V_84 ;
}
V_702 = F_419 ( V_745 , V_746 ) ;
if ( ! V_702 ) {
F_8 ( L_449 V_745 L_273 ) ;
F_409 () ;
return - V_75 ;
}
V_100 = F_420 ( & V_742 ) ;
if ( V_100 ) {
F_8 ( L_450 ) ;
F_409 () ;
return V_100 ;
}
V_186 . V_744 = 1 ;
V_100 = F_420 ( & V_677 ) ;
if ( V_100 ) {
F_8 ( L_451 ) ;
F_409 () ;
return V_100 ;
}
V_186 . V_743 = 1 ;
V_100 = F_99 ( & V_742 . V_81 ) ;
if ( ! V_100 ) {
V_186 . V_741 = 1 ;
V_100 = F_99 (
& V_677 . V_81 ) ;
}
if ( V_100 ) {
F_8 ( L_452 ) ;
F_409 () ;
return V_100 ;
}
V_186 . V_740 = 1 ;
V_154 = F_421 ( V_750 , - 1 ,
NULL , 0 ) ;
if ( F_146 ( V_154 ) ) {
V_100 = F_304 ( V_154 ) ;
V_154 = NULL ;
F_8 ( L_453 ) ;
F_409 () ;
return V_100 ;
}
V_510 = F_421 (
V_751 ,
- 1 , NULL , 0 ) ;
if ( F_146 ( V_510 ) ) {
V_100 = F_304 ( V_510 ) ;
V_510 = NULL ;
F_8 ( L_454 ) ;
F_409 () ;
return V_100 ;
}
V_100 = F_257 ( & V_510 -> V_60 ,
& V_739 ) ;
if ( V_100 ) {
F_8 ( L_455 ) ;
F_409 () ;
return V_100 ;
}
V_186 . V_738 = 1 ;
V_737 = F_422 ( & V_510 -> V_60 ) ;
if ( F_146 ( V_737 ) ) {
V_100 = F_304 ( V_737 ) ;
V_737 = NULL ;
F_8 ( L_456 ) ;
F_409 () ;
return V_100 ;
}
F_182 ( & V_207 ) ;
V_208 = F_423 () ;
if ( ! V_208 ) {
F_409 () ;
return - V_84 ;
} else {
V_208 -> V_51 = L_457 ;
V_208 -> V_752 = V_750 L_458 ;
V_208 -> V_144 . V_753 = V_754 ;
V_208 -> V_144 . V_6 = V_7 . V_6 ;
V_208 -> V_144 . V_755 = V_756 ;
V_208 -> V_144 . V_757 = V_758 ;
V_208 -> V_60 . V_52 = & V_154 -> V_60 ;
}
F_301 () ;
for ( V_42 = 0 ; V_42 < F_100 ( V_733 ) ; V_42 ++ ) {
V_100 = F_393 ( & V_733 [ V_42 ] ) ;
if ( V_100 >= 0 && * V_733 [ V_42 ] . V_734 )
V_100 = V_733 [ V_42 ] . V_66 -> V_101 ( V_733 [ V_42 ] . V_734 ) ;
if ( V_100 < 0 ) {
F_409 () ;
return V_100 ;
}
}
V_69 = V_70 ;
V_100 = F_424 ( V_208 ) ;
if ( V_100 < 0 ) {
F_8 ( L_459 ) ;
F_409 () ;
return V_100 ;
} else {
V_186 . V_736 = 1 ;
}
return 0 ;
}
