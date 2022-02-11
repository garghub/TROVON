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
static void F_132 ( const unsigned int V_253 ,
const unsigned int V_254 ,
const T_7 V_255 )
{
unsigned int V_42 = V_253 ;
while ( V_42 > V_254 ) {
F_133 ( V_256 ) ;
V_42 -- ;
}
while ( V_42 < V_254 ) {
F_133 ( V_257 ) ;
V_42 ++ ;
}
}
static void F_134 ( const unsigned int V_258 ,
const unsigned int V_259 ,
const T_7 V_255 )
{
unsigned int V_42 = V_258 ;
while ( V_42 > V_259 ) {
F_133 ( V_260 ) ;
V_42 -- ;
}
while ( V_42 < V_259 ) {
F_133 ( V_261 ) ;
V_42 ++ ;
}
}
static void F_135 ( struct V_216 * V_262 ,
struct V_216 * V_263 ,
const T_7 V_255 )
{
F_136 ( V_264 , V_221 ) ;
F_136 ( V_265 , V_223 ) ;
F_136 ( V_266 , V_225 ) ;
F_136 ( V_267 , V_227 ) ;
F_136 ( V_268 , V_231 ) ;
F_136 ( V_269 , V_235 ) ;
if ( V_263 -> V_249 ) {
if ( ! V_262 -> V_249 ||
V_262 -> V_251 != V_263 -> V_251 ||
V_262 -> V_246 != V_263 -> V_246 ) {
F_132 ( V_262 -> V_246 , V_263 -> V_246 ,
V_255 ) ;
F_133 ( V_270 ) ;
}
} else {
if ( V_262 -> V_249 ) {
F_133 ( V_257 ) ;
}
if ( V_262 -> V_246 != V_263 -> V_246 ) {
F_132 ( V_262 -> V_246 , V_263 -> V_246 ,
V_255 ) ;
} else if ( V_262 -> V_251 != V_263 -> V_251 ) {
if ( V_263 -> V_246 == 0 )
F_133 ( V_256 ) ;
else if ( V_263 -> V_246 >= V_271 )
F_133 ( V_257 ) ;
}
}
if ( V_262 -> V_239 != V_263 -> V_239 ) {
F_134 ( V_262 -> V_239 ,
V_263 -> V_239 , V_255 ) ;
} else if ( V_262 -> V_242 != V_263 -> V_242 ) {
if ( V_263 -> V_239 == 0 )
F_133 ( V_260 ) ;
else if ( V_263 -> V_239 >= V_272
&& ! V_186 . V_273 )
F_133 ( V_261 ) ;
}
#undef F_136
#undef F_133
}
static int F_137 ( void * V_66 )
{
struct V_216 V_118 [ 2 ] ;
T_7 V_274 , V_255 ;
unsigned int V_275 , V_276 ;
unsigned long V_157 ;
unsigned int V_277 ;
unsigned int V_278 ;
bool V_279 ;
if ( V_69 == V_199 )
goto exit;
F_138 () ;
V_276 = 0 ;
V_275 = 1 ;
V_157 = 0 ;
F_115 ( & V_280 ) ;
V_277 = V_281 ;
V_274 = V_193 ;
V_255 = V_193 &
( V_195 | V_192 ) ;
V_278 = V_282 ;
F_118 ( & V_280 ) ;
F_130 ( & V_118 [ V_276 ] , V_274 ) ;
while ( ! F_139 () ) {
if ( V_157 == 0 ) {
if ( F_140 ( V_278 ) )
V_157 = 1000 / V_278 ;
else
V_157 = 100 ;
}
V_157 = F_141 ( V_157 ) ;
if ( F_142 ( F_143 ( & V_279 ) ) )
break;
if ( V_157 > 0 && ! V_279 )
continue;
F_115 ( & V_280 ) ;
if ( V_279 || V_281 != V_277 ) {
V_275 = V_276 ;
V_157 = 0 ;
V_277 = V_281 ;
}
V_274 = V_193 ;
V_255 = V_193 &
( V_195 | V_192 ) ;
V_278 = V_282 ;
F_118 ( & V_280 ) ;
if ( F_140 ( V_274 ) ) {
F_130 ( & V_118 [ V_275 ] , V_274 ) ;
if ( F_140 ( V_275 != V_276 ) ) {
F_135 ( & V_118 [ V_276 ] , & V_118 [ V_275 ] ,
V_255 ) ;
}
}
V_276 = V_275 ;
V_275 ^= 1 ;
}
exit:
return 0 ;
}
static void F_144 ( void )
{
if ( V_283 ) {
F_145 ( V_283 ) ;
V_283 = NULL ;
}
}
static void F_117 ( const bool V_284 )
{
const T_7 V_285 = V_195 & V_193 ;
const T_7 V_286 = V_192 & V_193 ;
if ( V_282 > 0 &&
( V_285 ||
( V_286 && V_208 -> V_287 > 0 ) ) ) {
if ( ! V_283 ) {
V_283 = F_146 ( F_137 ,
NULL , V_288 ) ;
if ( F_147 ( V_283 ) ) {
V_283 = NULL ;
F_8 ( L_78
L_79 ) ;
}
}
} else {
F_144 () ;
if ( V_284 && ( V_285 || V_286 ) &&
V_282 == 0 ) {
F_32 ( L_80
L_81
L_82 ,
V_286 , V_285 ) ;
}
}
}
static void F_148 ( const bool V_284 )
{
F_115 ( & V_203 ) ;
F_117 ( V_284 ) ;
F_118 ( & V_203 ) ;
}
static void F_149 ( unsigned int V_289 )
{
if ( ! V_289 )
F_144 () ;
V_282 = V_289 ;
}
static void F_117 ( const bool V_290 )
{
}
static void F_148 ( const bool V_290 )
{
}
static int F_150 ( struct V_291 * V_60 )
{
switch ( V_69 ) {
case V_292 :
case V_70 :
F_148 ( false ) ;
return 0 ;
case V_199 :
return - V_293 ;
}
F_151 () ;
return - V_293 ;
}
static void F_152 ( struct V_291 * V_60 )
{
if ( V_69 != V_199 &&
! ( V_193 & V_195 ) )
F_148 ( false ) ;
}
static T_8 F_153 ( struct V_74 * V_60 ,
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
static T_8 F_154 ( struct V_74 * V_60 ,
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
static T_8 F_155 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 , V_192 ) ;
}
static T_8 F_156 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 ;
if ( F_57 ( V_126 , 0xffffffffUL , & V_157 ) )
return - V_94 ;
if ( F_157 ( & V_203 ) )
return - V_294 ;
V_17 = F_113 ( V_157 ) ;
#ifdef F_116
F_117 ( true ) ;
#endif
F_118 ( & V_203 ) ;
F_82 ( L_86 , L_87 , V_157 ) ;
return ( V_17 ) ? V_17 : V_35 ;
}
static T_8 F_158 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return sprintf ( V_126 , L_88 ) ;
}
static T_8 F_159 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
F_61 ( L_89 ,
L_90 ) ;
return snprintf ( V_126 , V_102 , L_55 , V_295 ) ;
}
static T_8 F_160 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 ,
V_191 | V_193 ) ;
}
static T_8 F_161 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 ,
( V_191 | V_193 )
& ~ V_296 ) ;
}
static T_8 F_162 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 , V_193 ) ;
}
static T_8 F_163 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
T_7 V_297 ;
int V_73 ;
if ( F_57 ( V_126 , 0xffffffffUL , & V_157 ) ||
( ( V_157 & ~ V_196 ) != 0 ) )
return - V_94 ;
if ( F_157 ( & V_203 ) )
return - V_294 ;
T_13
V_193 = V_157 ;
T_14
V_73 = F_112 ( ( V_192 | V_195 ) &
~ V_193 ) ;
F_117 ( true ) ;
V_297 = V_195 & ~ ( V_190 & V_191 )
& ~ V_193 & V_196 ;
F_118 ( & V_203 ) ;
if ( V_73 < 0 )
F_8 ( L_91
L_92 ) ;
if ( V_297 )
F_32 ( L_91
L_93 ,
V_297 ) ;
F_82 ( L_94 , L_87 , V_157 ) ;
return ( V_73 < 0 ) ? V_73 : V_35 ;
}
static T_8 F_164 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_282 ) ;
}
static T_8 F_165 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 25 , & V_157 ) )
return - V_94 ;
if ( F_157 ( & V_203 ) )
return - V_294 ;
F_149 ( V_157 ) ;
F_117 ( true ) ;
F_118 ( & V_203 ) ;
F_82 ( L_95 , L_96 , V_157 ) ;
return V_35 ;
}
static T_8 F_166 ( struct V_74 * V_60 ,
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
static void F_167 ( void )
{
if ( V_186 . V_187 )
F_168 ( & V_154 -> V_60 . V_125 , NULL ,
L_97 ) ;
}
static T_8 F_169 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_118 ;
V_17 = F_109 ( & V_118 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_44 , ! ! V_118 ) ;
}
static void F_170 ( void )
{
if ( V_186 . V_206 )
F_168 ( & V_154 -> V_60 . V_125 , NULL ,
L_98 ) ;
}
static T_8 F_171 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_298 ) ;
}
static void F_172 ( void )
{
F_168 ( & V_154 -> V_60 . V_125 , NULL ,
L_99 ) ;
}
static T_8 F_173 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_299 ) ;
}
static void F_174 ( void )
{
F_168 ( & V_154 -> V_60 . V_125 , NULL ,
L_100 ) ;
}
static void F_175 ( void )
{
int V_300 ;
V_300 = F_69 () ;
if ( V_300 == V_135 )
F_66 ( true ) ;
F_65 () ;
if ( V_300 == V_142 )
F_66 ( false ) ;
if ( ! ( V_300 < 0 ) ) {
F_115 ( & V_207 ) ;
F_122 ( V_208 ,
V_301 , ( V_300 > 0 ) ) ;
F_123 ( V_208 ) ;
F_118 ( & V_207 ) ;
}
F_167 () ;
}
static void F_176 ( void )
{
#ifdef F_116
F_115 ( & V_203 ) ;
F_144 () ;
F_118 ( & V_203 ) ;
#endif
if ( V_302 )
F_54 ( V_302 , & V_154 -> V_60 . V_125 ) ;
F_20 ( V_303 | V_304 ,
L_101 ) ;
if ( ( ( V_186 . V_189 &&
F_112 ( V_295 ) ) |
F_120 ( false ) ) != 0 )
F_8 ( L_102
L_103 ) ;
}
static void T_1 F_177 ( const unsigned int V_210 )
{
if ( V_212 [ V_210 ] != V_213 ) {
F_178 ( V_212 [ V_210 ] ,
V_208 -> V_305 ) ;
V_212 [ V_210 ] = V_213 ;
}
}
static int T_1 F_179 ( struct V_306 * V_307 )
{
enum T_15 {
V_308 = 0 ,
V_309 ,
};
static const T_16 V_310 [] V_311 = {
[ V_308 ] = {
V_312 , V_313 , V_314 , V_315 ,
V_316 , V_317 , V_318 , V_319 ,
V_320 , V_321 , V_322 , V_323 ,
V_324 ,
V_324 ,
V_324 ,
V_213 ,
V_213 ,
V_213 ,
V_324 ,
V_325 ,
V_213 ,
V_213 ,
V_213 ,
V_326 ,
V_324 , V_324 , V_324 , V_324 ,
V_324 , V_324 , V_324 , V_324 ,
} ,
[ V_309 ] = {
V_312 , V_314 , V_313 , V_315 ,
V_316 , V_327 , V_318 , V_319 ,
V_320 , V_321 , V_322 , V_323 ,
V_324 ,
V_324 ,
V_324 ,
V_328 ,
V_329 ,
V_213 ,
V_324 ,
V_325 ,
V_213 ,
V_213 ,
V_213 ,
V_326 ,
V_324 , V_324 ,
V_330 ,
V_324 , V_324 , V_324 , V_324 ,
V_324 ,
} ,
} ;
static const struct V_3 V_331 [] V_311 = {
{
. V_6 = V_15 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_308 ,
} ,
{
. V_6 = V_14 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_309 ,
} ,
} ;
#define F_180 sizeof(tpacpi_keymap_t)
#define F_181 sizeof(tpacpi_keymap_entry_t)
int V_17 , V_42 ;
int V_30 ;
int V_332 ;
bool V_333 = false ;
bool V_334 = false ;
unsigned long V_13 ;
unsigned long V_335 ;
F_17 ( V_55 | V_304 ,
L_104 ) ;
F_25 ( ! V_208 ) ;
F_25 ( V_208 -> V_336 != NULL ||
V_208 -> V_337 != NULL ) ;
F_182 ( V_338 ) ;
F_183 ( & V_203 ) ;
#ifdef F_116
F_183 ( & V_280 ) ;
#endif
V_186 . V_202 = V_129 != NULL ;
F_17 ( V_55 | V_304 ,
L_105 ,
F_1 ( V_186 . V_202 ) ) ;
if ( ! V_186 . V_202 )
return 1 ;
V_13 = F_4 ( V_339 ,
F_100 ( V_339 ) ) ;
F_60 () ;
V_302 = F_51 (
F_100 ( V_340 ) + 2 ,
NULL ) ;
if ( ! V_302 )
return - V_84 ;
V_17 = F_53 ( V_302 ,
V_340 ,
F_100 ( V_340 ) ) ;
if ( V_17 )
goto V_341;
if ( F_7 ( V_129 , & V_332 , L_106 , L_107 ) ) {
if ( ( V_332 >> 8 ) != 1 ) {
F_8 ( L_108 ,
V_332 ) ;
F_8 ( L_109 , V_342 ) ;
} else {
F_17 ( V_55 | V_304 ,
L_110 ,
V_332 ) ;
if ( ! F_7 ( V_129 , & V_191 ,
L_111 , L_107 ) ) {
F_8 ( L_112
L_109 ,
V_342 ) ;
V_191 = 0x080cU ;
} else {
V_186 . V_189 = 1 ;
}
}
}
F_17 ( V_55 | V_304 ,
L_113 ,
F_1 ( V_186 . V_189 ) ) ;
if ( ! V_186 . V_189 && ! V_191 &&
( V_13 & V_343 ) )
V_191 = 0x080cU ;
if ( V_186 . V_189 ) {
V_17 = F_110 () ;
if ( V_17 )
goto V_341;
V_295 = V_190 ;
} else {
V_295 = V_191 ;
V_190 = V_191 ;
}
#ifdef F_102
if ( V_172 ) {
V_186 . V_187 = 1 ;
V_333 = ! ! V_167 ;
F_76 ( L_114 ) ;
} else
#endif
if ( F_7 ( V_129 , & V_30 , L_63 , L_107 ) ) {
V_186 . V_187 = 1 ;
V_333 = ! ! V_30 ;
F_76 ( L_115 ,
F_184 ( V_30 , 0 ) ) ;
}
if ( V_186 . V_187 )
V_17 = F_52 ( V_302 ,
& V_344 . V_122 ) ;
if ( ! V_17 && F_7 ( V_129 , & V_30 , L_65 , L_107 ) ) {
V_186 . V_206 = 1 ;
V_334 = ! ! ( V_30 & V_188 ) ;
F_76 ( L_116
L_117 ,
( V_334 ) ? L_118 : L_119 ) ;
V_17 = F_52 ( V_302 ,
& V_345 . V_122 ) ;
}
if ( ! V_17 )
V_17 = F_185 (
V_302 ,
& V_154 -> V_60 . V_125 ) ;
if ( V_17 )
goto V_341;
V_212 = F_44 ( F_180 ,
V_83 ) ;
if ( ! V_212 ) {
F_8 ( L_120 ) ;
V_17 = - V_84 ;
goto V_341;
}
V_335 = F_4 ( V_331 ,
F_100 ( V_331 ) ) ;
F_25 ( V_335 >= F_100 ( V_310 ) ) ;
F_20 ( V_55 | V_304 ,
L_121 , V_335 ) ;
memcpy ( V_212 , & V_310 [ V_335 ] ,
F_180 ) ;
F_186 ( V_208 , V_214 , V_215 ) ;
V_208 -> V_346 = F_181 ;
V_208 -> V_347 = V_348 ;
V_208 -> V_211 = V_212 ;
for ( V_42 = 0 ; V_42 < V_348 ; V_42 ++ ) {
if ( V_212 [ V_42 ] != V_213 ) {
F_186 ( V_208 , V_349 ,
V_212 [ V_42 ] ) ;
} else {
if ( V_42 < sizeof( V_296 ) * 8 )
V_296 |= 1 << V_42 ;
}
}
if ( V_186 . V_187 ) {
F_186 ( V_208 , V_350 , V_301 ) ;
F_122 ( V_208 ,
V_301 , V_333 ) ;
}
if ( V_186 . V_206 ) {
F_186 ( V_208 , V_350 , V_209 ) ;
F_122 ( V_208 ,
V_209 , V_334 ) ;
}
if ( F_187 () ) {
F_76 ( L_122
L_123
L_124 ) ;
F_32 ( L_125
L_126 ) ;
V_296 |=
( 1 << V_261 )
| ( 1 << V_260 ) ;
F_177 ( V_261 ) ;
F_177 ( V_260 ) ;
}
#ifdef F_116
V_193 = V_351
& ~ V_191
& ~ V_296 ;
F_17 ( V_55 | V_304 ,
L_127 ,
V_193 , V_282 ) ;
#endif
F_20 ( V_55 | V_304 ,
L_128 ) ;
V_17 = F_120 ( true ) ;
if ( V_17 ) {
F_176 () ;
return V_17 ;
}
V_17 = F_112 ( ( ( V_191 & ~ V_296 )
| V_195 )
& ~ V_193 ) ;
if ( V_17 < 0 && V_17 != - V_49 ) {
F_176 () ;
return V_17 ;
}
V_192 = ( V_190 | V_193 )
& ~ V_296 ;
F_17 ( V_55 | V_304 ,
L_129 ,
V_192 , V_190 , V_193 ) ;
V_208 -> V_336 = & F_150 ;
V_208 -> V_337 = & F_152 ;
F_148 ( true ) ;
return 0 ;
V_341:
F_54 ( V_302 , & V_154 -> V_60 . V_125 ) ;
V_302 = NULL ;
return ( V_17 < 0 ) ? V_17 : 1 ;
}
static int F_188 ( int V_352 )
{
T_10 V_42 ;
T_10 V_353 = F_100 ( V_354 ) - 1 ;
for ( V_42 = 0 ; V_42 <= V_353 ; V_42 ++ ) {
if ( V_354 [ V_42 ] == V_352 )
break;
}
if ( V_42 >= V_353 )
V_42 = 0 ;
else
V_42 ++ ;
return V_354 [ V_42 ] ;
}
static bool F_189 ( unsigned int V_210 )
{
T_7 V_355 = 0 ;
int V_356 = 0 ;
switch ( V_210 ) {
case V_357 :
if ( V_358 ) {
V_356 = V_359 ;
V_358 = false ;
} else {
if ( ! F_7 (
V_129 , & V_355 ,
L_130 , L_7 , 0 ) ) {
F_8 ( L_131 ) ;
return false ;
} else {
V_356 = F_188 (
V_355 ) ;
}
}
if ( ! F_7 ( V_129 , NULL , L_132 , L_9 , V_356 ) ) {
F_8 ( L_133 ) ;
return false ;
}
return true ;
case V_360 :
if ( ! F_7 ( V_129 ,
& V_359 ,
L_130 , L_7 , 0 ) ) {
F_8 ( L_131 ) ;
return false ;
} else {
V_358 = true ;
if ( ! F_7 ( V_129 ,
NULL , L_132 , L_9 , V_361 ) ) {
F_8 ( L_133 ) ;
return false ;
}
}
return true ;
default:
return false ;
}
}
static bool F_190 ( const T_7 V_338 ,
bool * V_362 ,
bool * V_363 )
{
unsigned int V_210 = V_338 & 0xfff ;
* V_362 = true ;
* V_363 = false ;
if ( V_210 > 0 && V_210 <= V_348 ) {
V_210 -- ;
if ( ! ( V_193 & ( 1 << V_210 ) ) ) {
F_127 ( V_210 ) ;
* V_362 = false ;
} else {
* V_363 = true ;
}
return true ;
} else {
return F_189 ( V_210 ) ;
}
return false ;
}
static bool F_191 ( const T_7 V_338 ,
bool * V_362 ,
bool * V_363 )
{
* V_362 = true ;
* V_363 = false ;
switch ( V_338 ) {
case V_364 :
case V_365 :
V_298 = V_366 ;
* V_363 = true ;
break;
case V_367 :
case V_368 :
V_298 = V_369 ;
* V_363 = true ;
break;
case V_370 :
case V_371 :
F_192 ( L_134 ) ;
break;
default:
return false ;
}
if ( V_298 != V_372 ) {
F_76 ( L_135 ) ;
F_172 () ;
}
return true ;
}
static bool F_193 ( const T_7 V_338 ,
bool * V_362 ,
bool * V_363 )
{
* V_362 = true ;
* V_363 = false ;
switch ( V_338 ) {
case V_373 :
V_299 = 1 ;
F_76 ( L_136 ) ;
F_174 () ;
return true ;
case V_374 :
F_76 ( L_137 ) ;
return true ;
case V_375 :
F_76 ( L_138 ) ;
return true ;
default:
return false ;
}
}
static bool F_194 ( const T_7 V_338 ,
bool * V_362 ,
bool * V_363 )
{
* V_362 = true ;
* V_363 = false ;
switch ( V_338 ) {
case V_376 :
case V_377 :
return true ;
case V_378 :
case V_379 :
F_121 () ;
F_170 () ;
* V_362 = false ;
return true ;
case V_380 :
case V_381 :
case V_382 :
* V_363 = true ;
return true ;
default:
return false ;
}
}
static bool F_195 ( const T_7 V_338 ,
bool * V_362 ,
bool * V_363 )
{
bool V_383 = true ;
* V_362 = true ;
* V_363 = false ;
switch ( V_338 ) {
case V_384 :
F_76 ( L_139 ) ;
return true ;
case V_385 :
F_196 ( L_140 ) ;
break;
case V_386 :
F_192 ( L_141 ) ;
break;
case V_387 :
F_196 ( L_142
L_143 ) ;
break;
case V_388 :
F_192 ( L_144
L_145 ) ;
break;
case V_389 :
case V_390 :
case V_391 :
* V_362 = false ;
* V_363 = true ;
return true ;
default:
F_62 ( L_146 ) ;
V_383 = false ;
}
F_197 () ;
return V_383 ;
}
static void F_198 ( struct V_67 * V_68 , T_7 V_65 )
{
T_7 V_338 ;
bool V_362 ;
bool V_363 ;
bool V_392 ;
if ( V_65 != 0x80 ) {
F_8 ( L_147 , V_65 ) ;
F_199 (
V_68 -> V_71 -> V_74 -> V_393 . V_394 ,
F_200 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , 0 ) ;
return;
}
while ( 1 ) {
if ( ! F_7 ( V_129 , & V_338 , L_148 , L_64 ) ) {
F_8 ( L_149 ) ;
return;
}
if ( V_338 == 0 ) {
return;
}
V_362 = true ;
V_363 = false ;
switch ( V_338 >> 12 ) {
case 1 :
V_392 = F_190 ( V_338 , & V_362 ,
& V_363 ) ;
break;
case 2 :
V_392 = F_191 ( V_338 , & V_362 ,
& V_363 ) ;
break;
case 3 :
switch ( V_338 ) {
case V_395 :
V_299 = 1 ;
F_76 ( L_150 ) ;
F_174 () ;
V_392 = true ;
break;
case V_396 :
V_392 = true ;
break;
default:
V_392 = false ;
}
break;
case 4 :
V_392 = F_193 ( V_338 , & V_362 ,
& V_363 ) ;
break;
case 5 :
V_392 = F_194 ( V_338 , & V_362 ,
& V_363 ) ;
break;
case 6 :
V_392 = F_195 ( V_338 , & V_362 ,
& V_363 ) ;
break;
case 7 :
if ( V_186 . V_187 &&
V_338 == V_397 ) {
F_175 () ;
V_362 = 0 ;
V_392 = true ;
break;
}
default:
V_392 = false ;
}
if ( ! V_392 ) {
F_32 ( L_151 , V_338 ) ;
F_32 ( L_152
L_153 , V_342 ) ;
}
if ( ! V_363 && V_362 ) {
F_199 (
V_68 -> V_71 -> V_74 -> V_393 . V_394 ,
F_200 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , V_338 ) ;
}
}
}
static void F_201 ( void )
{
int V_332 ;
V_298 = V_372 ;
V_299 = 0 ;
if ( F_7 ( V_129 , & V_332 , L_106 , L_107 ) ) {
if ( ( V_332 >> 8 ) == 2 ) {
if ( ! F_7 ( V_129 ,
& V_359 ,
L_130 , L_7 , 0 ) ) {
F_8 ( L_154 ) ;
}
}
}
}
static void F_202 ( void )
{
int V_332 ;
F_60 () ;
if ( F_120 ( true ) < 0 ||
F_112 ( V_190 ) < 0 )
F_8 ( L_155
L_156 ) ;
F_175 () ;
F_170 () ;
F_172 () ;
F_174 () ;
F_148 ( false ) ;
if ( F_7 ( V_129 , & V_332 , L_106 , L_107 ) ) {
if ( ( V_332 >> 8 ) == 2 ) {
if ( ! F_7 ( V_129 ,
NULL ,
L_132 , L_9 ,
V_359 ) ) {
F_8 ( L_157 ) ;
}
}
}
}
static int F_203 ( struct V_90 * V_91 )
{
int V_17 , V_30 ;
if ( ! V_186 . V_202 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
if ( F_157 ( & V_203 ) )
return - V_294 ;
V_17 = F_119 ( & V_30 ) ;
if ( ! V_17 )
V_17 = F_110 () ;
F_118 ( & V_203 ) ;
if ( V_17 )
return V_17 ;
F_84 ( V_91 , L_47 , F_184 ( V_30 , 0 ) ) ;
if ( V_191 ) {
F_84 ( V_91 , L_158 , V_192 ) ;
F_84 ( V_91 , L_159 ) ;
} else {
F_84 ( V_91 , L_160 ) ;
F_84 ( V_91 , L_161 ) ;
}
return 0 ;
}
static void F_204 ( bool V_204 )
{
F_2 ( L_162 ) ;
if ( ! F_205 ( ( V_69 == V_70 || ! V_204 ) ,
F_206 ( L_163
L_164
L_165 ) ) )
F_8 ( L_166
L_167
L_165 ) ;
}
static int F_207 ( char * V_126 )
{
int V_17 ;
T_7 V_197 ;
char * V_159 ;
if ( ! V_186 . V_202 )
return - V_75 ;
if ( F_157 ( & V_203 ) )
return - V_294 ;
V_197 = V_192 ;
V_17 = 0 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_51 ) == 0 ) {
F_204 ( 1 ) ;
} else if ( F_86 ( V_159 , L_52 ) == 0 ) {
F_204 ( 0 ) ;
V_17 = - V_158 ;
} else if ( F_86 ( V_159 , L_168 ) == 0 ) {
V_197 = ( V_191 | V_193 )
& ~ V_296 ;
} else if ( sscanf ( V_159 , L_169 , & V_197 ) == 1 ) {
} else if ( sscanf ( V_159 , L_170 , & V_197 ) == 1 ) {
} else {
V_17 = - V_94 ;
goto V_398;
}
}
if ( ! V_17 ) {
F_82 ( L_171 ,
L_172 , V_197 ) ;
V_17 = F_113 ( V_197 ) ;
}
V_398:
F_118 ( & V_203 ) ;
return V_17 ;
}
static int F_208 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_174 )
return ( V_168 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_173 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_399 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_209 ( enum V_400 V_205 )
{
int V_30 ;
F_17 ( V_140 ,
L_174 ,
( V_205 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_174 ) {
V_168 = ( V_205 == V_142 ) ;
return 0 ;
}
#endif
if ( V_205 == V_142 )
V_30 = V_399
| V_401 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_175 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_210 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_402 ,
V_122 , V_126 ) ;
}
static T_8 F_211 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_402 ,
V_122 , V_126 , V_35 ) ;
}
static void F_212 ( void )
{
if ( ! F_7 ( NULL , NULL , L_176 , L_9 ,
V_403 ) )
F_32 ( L_177 ) ;
else
F_17 ( V_140 ,
L_178 ) ;
}
static void F_213 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_404 ) ;
F_77 ( V_402 ) ;
F_212 () ;
}
static int T_1 F_214 ( struct V_306 * V_307 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_179 ) ;
F_182 ( V_338 ) ;
V_186 . V_405 = V_129 &&
F_7 ( V_129 , & V_30 , L_173 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_180 ,
F_1 ( V_186 . V_405 ) ,
V_30 ) ;
#ifdef F_102
if ( V_174 ) {
V_186 . V_405 = 1 ;
F_76 ( L_181 ) ;
} else
#endif
if ( V_186 . V_405 &&
! ( V_30 & V_406 ) ) {
V_186 . V_405 = 0 ;
F_20 ( V_55 | V_140 ,
L_182 ) ;
}
if ( ! V_186 . V_405 )
return 1 ;
V_17 = F_71 ( V_402 ,
& V_407 ,
V_408 ,
V_409 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_215 ( & V_154 -> V_60 . V_125 ,
& V_404 ) ;
if ( V_17 ) {
F_77 ( V_402 ) ;
return V_17 ;
}
return 0 ;
}
static int F_216 ( struct V_90 * V_91 )
{
return F_83 ( V_402 , V_91 ) ;
}
static int F_217 ( char * V_126 )
{
return F_85 ( V_402 , V_126 ) ;
}
static int F_218 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_176 )
return ( V_169 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_183 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_410 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_219 ( enum V_400 V_205 )
{
int V_30 ;
F_17 ( V_140 ,
L_184 ,
( V_205 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_176 ) {
V_169 = ( V_205 == V_142 ) ;
return 0 ;
}
#endif
if ( V_205 == V_142 )
V_30 = V_410
| V_411 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_185 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_220 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_412 ,
V_122 , V_126 ) ;
}
static T_8 F_221 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_412 ,
V_122 , V_126 , V_35 ) ;
}
static void F_222 ( void )
{
if ( ! F_7 ( NULL , NULL , L_186 , L_9 ,
V_413 ) )
F_32 ( L_187 ) ;
else
F_17 ( V_140 ,
L_188 ) ;
}
static void F_223 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_414 ) ;
F_77 ( V_412 ) ;
F_222 () ;
}
static int T_1 F_224 ( struct V_306 * V_307 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_189 ) ;
F_182 ( V_338 ) ;
V_186 . V_415 = V_129 &&
F_7 ( V_129 , & V_30 , L_183 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_190 ,
F_1 ( V_186 . V_415 ) ,
V_30 ) ;
#ifdef F_102
if ( V_176 ) {
V_186 . V_415 = 1 ;
F_76 ( L_191 ) ;
} else
#endif
if ( V_186 . V_415 &&
! ( V_30 & V_416 ) ) {
V_186 . V_415 = 0 ;
F_20 ( V_55 | V_140 ,
L_192 ) ;
}
if ( ! V_186 . V_415 )
return 1 ;
V_17 = F_71 ( V_412 ,
& V_417 ,
V_418 ,
V_419 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_215 ( & V_154 -> V_60 . V_125 ,
& V_414 ) ;
if ( V_17 ) {
F_77 ( V_412 ) ;
return V_17 ;
}
return 0 ;
}
static int F_225 ( struct V_90 * V_91 )
{
return F_83 ( V_412 , V_91 ) ;
}
static int F_226 ( char * V_126 )
{
return F_85 ( V_412 , V_126 ) ;
}
static int F_227 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_178 )
return ( V_170 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_193 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_420 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_228 ( enum V_400 V_205 )
{
int V_30 ;
F_17 ( V_140 ,
L_194 ,
( V_205 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_178 ) {
V_170 = ( V_205 == V_142 ) ;
return 0 ;
}
#endif
if ( V_205 == V_142 )
V_30 = V_420 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_195 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static void F_229 ( void )
{
F_77 ( V_421 ) ;
}
static int T_1 F_230 ( struct V_306 * V_307 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_196 ) ;
F_182 ( V_338 ) ;
V_186 . V_422 = V_129 &&
F_7 ( V_129 , & V_30 , L_193 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_197 ,
F_1 ( V_186 . V_422 ) ,
V_30 ) ;
#ifdef F_102
if ( V_178 ) {
V_186 . V_422 = 1 ;
F_76 ( L_198 ) ;
} else
#endif
if ( V_186 . V_422 &&
! ( V_30 & V_423 ) ) {
V_186 . V_422 = 0 ;
F_20 ( V_55 ,
L_199 ) ;
}
if ( ! V_186 . V_422 )
return 1 ;
V_17 = F_71 ( V_421 ,
& V_424 ,
V_425 ,
V_426 ,
false ) ;
return V_17 ;
}
static int T_1 F_231 ( struct V_306 * V_307 )
{
int V_427 ;
F_17 ( V_55 , L_200 ) ;
F_182 ( V_428 ) ;
if ( F_6 () )
F_182 ( V_429 ) ;
if ( V_430 && F_7 ( NULL , & V_427 , L_201 , L_64 ) && V_427 )
V_431 = V_430 ;
if ( ! V_431 )
V_432 = V_433 ;
else if ( F_6 () &&
F_7 ( V_431 , & V_434 , L_202 , L_107 ) )
V_432 = V_435 ;
else if ( F_6 () &&
F_7 ( V_431 , & V_434 , L_203 , L_107 ) )
V_432 = V_436 ;
else
V_432 = V_437 ;
F_17 ( V_55 , L_204 ,
F_1 ( V_432 != V_433 ) ,
V_432 ) ;
return ( V_432 != V_433 ) ? 0 : 1 ;
}
static void F_232 ( void )
{
F_20 ( V_303 ,
L_205 ) ;
if ( F_233 ( V_434 ) )
F_8 ( L_206
L_207 ) ;
}
static int F_234 ( void )
{
int V_30 = 0 ;
int V_42 ;
switch ( V_432 ) {
case V_435 :
if ( ! F_7 ( NULL , & V_42 , L_208 , L_7 ,
V_438 ) )
return - V_50 ;
V_30 = V_42 & V_439 ;
break;
case V_436 :
if ( ! F_7 ( NULL , & V_42 , L_209 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_440 ;
if ( ! F_7 ( NULL , & V_42 , L_210 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_441 ;
break;
case V_437 :
if ( ! F_7 ( NULL , NULL , L_211 , L_9 , 1 ) ||
! F_7 ( NULL , & V_42 , L_210 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_441 ;
if ( ! F_7 ( NULL , NULL , L_211 , L_9 , 0 ) ||
! F_7 ( NULL , & V_42 , L_209 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_440 ;
if ( ! F_7 ( NULL , & V_42 , L_212 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_442 ;
break;
default:
return - V_443 ;
}
return V_30 ;
}
static int F_235 ( int V_30 )
{
int V_444 ;
int V_17 = 0 ;
switch ( V_432 ) {
case V_435 :
V_17 = F_7 ( NULL , NULL ,
L_213 , L_8 ,
V_445 ,
V_30 | V_446 ) ;
break;
case V_436 :
V_444 = F_236 () ;
if ( V_444 < 0 )
return V_444 ;
V_17 = F_233 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_431 , NULL ,
L_214 , L_8 , V_30 * 0x100 , 0 ) ;
if ( ! V_444 && F_233 ( V_444 ) ) {
F_8 ( L_215 ) ;
return - V_50 ;
}
break;
case V_437 :
V_17 = F_7 ( NULL , NULL , L_211 , L_9 , 0x80 ) &&
F_7 ( NULL , NULL , L_216 , L_8 , V_30 , 1 ) ;
break;
default:
return - V_443 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_236 ( void )
{
int V_444 = 0 ;
switch ( V_432 ) {
case V_435 :
if ( ! F_7 ( V_431 , & V_444 , L_202 , L_64 ) )
return - V_50 ;
break;
case V_436 :
case V_437 :
if ( ! F_7 ( V_431 , & V_444 , L_217 , L_64 ) )
return - V_50 ;
break;
default:
return - V_443 ;
}
return V_444 & 1 ;
}
static int F_233 ( int V_204 )
{
if ( ! F_7 ( V_431 , NULL , L_218 , L_9 , ( V_204 ) ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static int F_237 ( void )
{
int V_444 = F_236 () ;
int V_17 ;
if ( V_444 < 0 )
return V_444 ;
switch ( V_432 ) {
case V_435 :
V_17 = F_233 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_447 , NULL , L_219 , L_220 ) ;
break;
case V_436 :
case V_437 :
V_17 = F_233 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_431 , NULL , L_221 , L_220 ) ;
break;
default:
return - V_443 ;
}
if ( ! V_444 && F_233 ( V_444 ) ) {
F_8 ( L_215 ) ;
return - V_50 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_238 ( void )
{
switch ( V_432 ) {
case V_435 :
return F_7 ( V_447 , NULL , L_222 , L_220 ) ?
0 : - V_50 ;
case V_436 :
return F_7 ( V_431 , NULL , L_223 , L_220 ) ?
0 : - V_50 ;
case V_437 :
return F_7 ( NULL , NULL , L_224 , L_220 ) ?
0 : - V_50 ;
default:
return - V_443 ;
}
}
static int F_239 ( struct V_90 * V_91 )
{
int V_30 , V_444 ;
if ( V_432 == V_433 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
if ( ! F_240 ( V_448 ) )
return - V_158 ;
V_30 = F_234 () ;
if ( V_30 < 0 )
return V_30 ;
V_444 = F_236 () ;
if ( V_444 < 0 )
return V_444 ;
F_84 ( V_91 , L_225 ) ;
F_84 ( V_91 , L_226 , F_184 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_227 , F_184 ( V_30 , 1 ) ) ;
if ( V_432 == V_437 )
F_84 ( V_91 , L_228 , F_184 ( V_30 , 3 ) ) ;
F_84 ( V_91 , L_229 , F_184 ( V_444 , 0 ) ) ;
F_84 ( V_91 , L_230 ) ;
F_84 ( V_91 , L_231 ) ;
if ( V_432 == V_437 )
F_84 ( V_91 , L_232 ) ;
F_84 ( V_91 , L_233 ) ;
F_84 ( V_91 , L_234 ) ;
return 0 ;
}
static int F_241 ( char * V_126 )
{
char * V_159 ;
int V_204 , V_449 , V_30 ;
int V_17 ;
if ( V_432 == V_433 )
return - V_75 ;
if ( ! F_240 ( V_448 ) )
return - V_158 ;
V_204 = 0 ;
V_449 = 0 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_235 ) == 0 ) {
V_204 |= V_440 ;
} else if ( F_86 ( V_159 , L_236 ) == 0 ) {
V_449 |= V_440 ;
} else if ( F_86 ( V_159 , L_237 ) == 0 ) {
V_204 |= V_441 ;
} else if ( F_86 ( V_159 , L_238 ) == 0 ) {
V_449 |= V_441 ;
} else if ( V_432 == V_437 &&
F_86 ( V_159 , L_239 ) == 0 ) {
V_204 |= V_442 ;
} else if ( V_432 == V_437 &&
F_86 ( V_159 , L_240 ) == 0 ) {
V_449 |= V_442 ;
} else if ( F_86 ( V_159 , L_241 ) == 0 ) {
V_17 = F_233 ( 1 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_242 ) == 0 ) {
V_17 = F_233 ( 0 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_243 ) == 0 ) {
V_17 = F_237 () ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_244 ) == 0 ) {
V_17 = F_238 () ;
if ( V_17 )
return V_17 ;
} else
return - V_94 ;
}
if ( V_204 || V_449 ) {
V_30 = F_234 () ;
if ( V_30 < 0 )
return V_30 ;
V_17 = F_235 ( ( V_30 & ~ V_449 ) | V_204 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_242 ( void )
{
int V_30 = 0 ;
if ( V_186 . V_450 ) {
if ( ! F_7 ( V_447 , & V_30 , L_245 , L_64 ) )
return - V_50 ;
return ( ! ! V_30 ) ;
}
return - V_49 ;
}
static int F_243 ( int V_30 )
{
int V_73 ;
if ( V_186 . V_451 ) {
if ( V_48 ) {
V_73 = F_7 ( V_48 , NULL , NULL , L_9 ,
( V_30 ) ?
V_452 :
V_453 ) ;
} else {
V_73 = F_7 ( V_454 , NULL , NULL , L_9 ,
( V_30 ) ? 1 : 0 ) ;
}
return ( V_73 ) ? 0 : - V_50 ;
}
return - V_49 ;
}
static void F_244 ( struct V_455 * V_456 )
{
struct V_457 * V_66 =
F_245 ( V_456 , struct V_457 , V_456 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_243 ( ( V_66 -> V_458 != V_459 ) ) ;
}
static void F_246 ( struct V_460 * V_461 ,
enum V_462 V_463 )
{
struct V_457 * V_66 =
F_245 ( V_461 ,
struct V_457 ,
V_460 ) ;
V_66 -> V_458 = ( V_463 != V_464 ) ?
V_465 : V_459 ;
F_247 ( V_466 , & V_66 -> V_456 ) ;
}
static enum V_462 F_248 ( struct V_460 * V_461 )
{
return ( F_242 () == 1 ) ? V_467 : V_464 ;
}
static int T_1 F_249 ( struct V_306 * V_307 )
{
int V_73 ;
F_17 ( V_55 , L_246 ) ;
if ( F_6 () ) {
F_182 ( V_468 ) ;
F_182 ( V_469 ) ;
}
F_182 ( V_470 ) ;
F_250 ( & V_471 . V_456 , F_244 ) ;
V_186 . V_451 = ( V_48 || V_454 ) && ! V_472 ;
if ( V_186 . V_451 )
V_186 . V_450 =
F_7 ( V_447 , NULL , L_245 , L_247 ) ;
F_17 ( V_55 , L_248 ,
F_1 ( V_186 . V_451 ) ,
F_1 ( V_186 . V_450 ) ) ;
if ( ! V_186 . V_451 )
return 1 ;
V_73 = F_251 ( & V_154 -> V_60 ,
& V_471 . V_460 ) ;
if ( V_73 < 0 ) {
V_186 . V_451 = 0 ;
V_186 . V_450 = 0 ;
} else {
V_73 = 0 ;
}
return V_73 ;
}
static void F_252 ( void )
{
F_253 ( & V_471 . V_460 ) ;
F_254 ( V_466 ) ;
}
static int F_255 ( struct V_90 * V_91 )
{
int V_30 ;
if ( ! V_186 . V_451 ) {
F_84 ( V_91 , L_46 ) ;
} else if ( ! V_186 . V_450 ) {
F_84 ( V_91 , L_249 ) ;
F_84 ( V_91 , L_250 ) ;
} else {
V_30 = F_242 () ;
if ( V_30 < 0 )
return V_30 ;
F_84 ( V_91 , L_47 , F_256 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_250 ) ;
}
return 0 ;
}
static int F_257 ( char * V_126 )
{
char * V_159 ;
int V_473 = 0 ;
if ( ! V_186 . V_451 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_251 ) == 0 ) {
V_473 = 1 ;
} else if ( F_86 ( V_159 , L_252 ) == 0 ) {
V_473 = 0 ;
} else
return - V_94 ;
}
return F_243 ( V_473 ) ;
}
static T_8 F_258 ( struct V_74 * V_60 ,
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
static int T_1 F_259 ( struct V_306 * V_307 )
{
int V_17 ;
F_17 ( V_55 ,
L_253 ) ;
F_182 ( V_470 ) ;
F_17 ( V_55 , L_254 ,
F_1 ( V_48 != NULL ) ) ;
V_17 = F_260 ( & V_154 -> V_60 , & V_474 ) ;
if ( V_17 )
return V_17 ;
return ( V_48 ) ? 0 : 1 ;
}
static void F_261 ( void )
{
F_262 ( & V_154 -> V_60 , & V_474 ) ;
}
static int F_263 ( struct V_90 * V_91 )
{
if ( ! V_48 )
F_84 ( V_91 , L_46 ) ;
else {
F_84 ( V_91 , L_225 ) ;
F_84 ( V_91 , L_255 ) ;
}
return 0 ;
}
static int F_264 ( char * V_126 )
{
char * V_159 ;
int V_47 , V_17 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_256 , & V_47 ) == 1 &&
V_47 >= 0 && V_47 <= 21 ) {
} else
return - V_94 ;
V_17 = F_15 ( V_47 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static inline bool F_265 ( const unsigned int V_475 )
{
#ifdef F_266
return false ;
#else
return ( 1U & ( V_476 >> V_475 ) ) == 0 ;
#endif
}
static int F_267 ( const unsigned int V_475 )
{
int V_30 ;
enum V_477 V_478 ;
switch ( V_479 ) {
case V_480 :
if ( ! F_7 ( V_447 ,
& V_30 , L_257 , L_7 , 1 << V_475 ) )
return - V_50 ;
V_478 = ( V_30 == 0 ) ?
V_459 :
( ( V_30 == 1 ) ?
V_465 :
V_481 ) ;
V_482 [ V_475 ] = V_478 ;
return V_478 ;
default:
return - V_49 ;
}
}
static int F_268 ( const unsigned int V_475 ,
const enum V_477 V_483 )
{
static const unsigned int V_484 [] = { 0 , 1 , 3 } ;
static const unsigned int V_485 [] = { 0 , 0x80 , 0xc0 } ;
int V_73 = 0 ;
switch ( V_479 ) {
case V_480 :
if ( F_142 ( V_475 > 7 ) )
return - V_94 ;
if ( F_142 ( F_265 ( V_475 ) ) )
return - V_158 ;
if ( ! F_7 ( V_486 , NULL , NULL , L_8 ,
( 1 << V_475 ) , V_484 [ V_483 ] ) )
V_73 = - V_50 ;
break;
case V_487 :
if ( F_142 ( V_475 > 7 ) )
return - V_94 ;
if ( F_142 ( F_265 ( V_475 ) ) )
return - V_158 ;
V_73 = F_14 ( V_488 , ( 1 << V_475 ) ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_489 ,
( V_483 == V_481 ) << V_475 ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_490 ,
( V_483 != V_459 ) << V_475 ) ;
break;
case V_491 :
if ( F_142 ( V_475 >= V_492 ) )
return - V_94 ;
if ( F_142 ( F_265 ( V_475 ) ) )
return - V_158 ;
if ( ! F_7 ( V_486 , NULL , NULL , L_8 ,
V_475 , V_485 [ V_483 ] ) )
V_73 = - V_50 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
V_482 [ V_475 ] = V_483 ;
return V_73 ;
}
static void F_269 ( struct V_455 * V_456 )
{
struct V_457 * V_66 =
F_245 ( V_456 , struct V_457 , V_456 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_268 ( V_66 -> V_475 , V_66 -> V_458 ) ;
}
static void F_270 ( struct V_460 * V_461 ,
enum V_462 V_463 )
{
struct V_457 * V_66 = F_245 ( V_461 ,
struct V_457 , V_460 ) ;
if ( V_463 == V_464 )
V_66 -> V_458 = V_459 ;
else if ( V_482 [ V_66 -> V_475 ] != V_481 )
V_66 -> V_458 = V_465 ;
else
V_66 -> V_458 = V_481 ;
F_247 ( V_466 , & V_66 -> V_456 ) ;
}
static int F_271 ( struct V_460 * V_461 ,
unsigned long * V_493 , unsigned long * V_494 )
{
struct V_457 * V_66 = F_245 ( V_461 ,
struct V_457 , V_460 ) ;
if ( * V_493 == 0 && * V_494 == 0 ) {
* V_493 = 500 ;
* V_494 = 500 ;
} else if ( ( * V_493 != 500 ) || ( * V_494 != 500 ) )
return - V_94 ;
V_66 -> V_458 = V_481 ;
F_247 ( V_466 , & V_66 -> V_456 ) ;
return 0 ;
}
static enum V_462 F_272 ( struct V_460 * V_461 )
{
int V_73 ;
struct V_457 * V_66 = F_245 ( V_461 ,
struct V_457 , V_460 ) ;
V_73 = F_267 ( V_66 -> V_475 ) ;
if ( V_73 == V_459 || V_73 < 0 )
V_73 = V_464 ;
else
V_73 = V_467 ;
return V_73 ;
}
static void F_273 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_492 ; V_42 ++ ) {
if ( V_495 [ V_42 ] . V_460 . V_51 )
F_253 ( & V_495 [ V_42 ] . V_460 ) ;
}
F_254 ( V_466 ) ;
F_37 ( V_495 ) ;
}
static int T_1 F_274 ( unsigned int V_475 )
{
int V_73 ;
V_495 [ V_475 ] . V_475 = V_475 ;
if ( ! V_496 [ V_475 ] )
return 0 ;
V_495 [ V_475 ] . V_460 . V_497 = & F_270 ;
V_495 [ V_475 ] . V_460 . V_498 = & F_271 ;
if ( V_479 == V_480 )
V_495 [ V_475 ] . V_460 . V_499 =
& F_272 ;
V_495 [ V_475 ] . V_460 . V_51 = V_496 [ V_475 ] ;
F_250 ( & V_495 [ V_475 ] . V_456 , F_269 ) ;
V_73 = F_251 ( & V_154 -> V_60 ,
& V_495 [ V_475 ] . V_460 ) ;
if ( V_73 < 0 )
V_495 [ V_475 ] . V_460 . V_51 = NULL ;
return V_73 ;
}
static enum V_500 T_1 F_275 ( void )
{
T_4 V_30 ;
if ( F_6 () ) {
V_30 = F_18 ( V_447 , L_258 , & V_486 ) ;
if ( F_19 ( V_30 ) )
return V_480 ;
V_30 = F_18 ( V_447 , L_259 , & V_486 ) ;
if ( F_19 ( V_30 ) )
return V_487 ;
}
V_30 = F_18 ( V_447 , L_260 , & V_486 ) ;
if ( F_19 ( V_30 ) )
return V_491 ;
V_486 = NULL ;
return V_501 ;
}
static int T_1 F_276 ( struct V_306 * V_307 )
{
unsigned int V_42 ;
int V_73 ;
unsigned long V_502 ;
F_17 ( V_55 , L_261 ) ;
V_479 = F_275 () ;
if ( V_479 != V_501 ) {
V_502 = F_4 ( V_503 ,
F_100 ( V_503 ) ) ;
if ( ! V_502 ) {
V_486 = NULL ;
V_479 = V_501 ;
}
}
F_17 ( V_55 , L_262 ,
F_1 ( V_479 ) , V_479 ) ;
if ( V_479 == V_501 )
return 1 ;
V_495 = F_35 ( sizeof( * V_495 ) * V_492 ,
V_83 ) ;
if ( ! V_495 ) {
F_8 ( L_263 ) ;
return - V_84 ;
}
for ( V_42 = 0 ; V_42 < V_492 ; V_42 ++ ) {
V_495 [ V_42 ] . V_475 = - 1 ;
if ( ! F_265 ( V_42 ) &&
F_277 ( V_42 , & V_502 ) ) {
V_73 = F_274 ( V_42 ) ;
if ( V_73 < 0 ) {
F_273 () ;
return V_73 ;
}
}
}
#ifdef F_266
F_32 ( L_264
L_265 ) ;
#endif
return 0 ;
}
static int F_278 ( struct V_90 * V_91 )
{
if ( ! V_479 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
F_84 ( V_91 , L_225 ) ;
if ( V_479 == V_480 ) {
int V_42 , V_30 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_30 = F_267 ( V_42 ) ;
if ( V_30 < 0 )
return - V_50 ;
F_84 ( V_91 , L_266 ,
V_42 , F_279 ( V_30 ) ) ;
}
}
F_84 ( V_91 , L_267
L_268 ) ;
return 0 ;
}
static int F_280 ( char * V_126 )
{
char * V_159 ;
int V_475 , V_73 ;
enum V_477 V_118 ;
if ( ! V_479 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_269 , & V_475 ) != 1 )
return - V_94 ;
if ( V_475 < 0 || V_475 > ( V_492 - 1 ) ||
V_495 [ V_475 ] . V_475 < 0 )
return - V_75 ;
if ( strstr ( V_159 , L_252 ) ) {
V_118 = V_459 ;
} else if ( strstr ( V_159 , L_251 ) ) {
V_118 = V_465 ;
} else if ( strstr ( V_159 , L_270 ) ) {
V_118 = V_481 ;
} else {
return - V_94 ;
}
V_73 = F_268 ( V_475 , V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
static int T_1 F_281 ( struct V_306 * V_307 )
{
unsigned long V_13 ;
F_17 ( V_55 , L_271 ) ;
F_182 ( V_504 ) ;
F_17 ( V_55 , L_272 ,
F_1 ( V_505 != NULL ) ) ;
V_13 = F_4 ( V_506 ,
F_100 ( V_506 ) ) ;
V_186 . V_507 = ! ! ( V_13 & V_508 ) ;
return ( V_505 ) ? 0 : 1 ;
}
static int F_282 ( struct V_90 * V_91 )
{
if ( ! V_505 )
F_84 ( V_91 , L_46 ) ;
else {
F_84 ( V_91 , L_225 ) ;
F_84 ( V_91 , L_273 ) ;
}
return 0 ;
}
static int F_283 ( char * V_126 )
{
char * V_159 ;
int V_509 ;
if ( ! V_505 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_256 , & V_509 ) == 1 &&
V_509 >= 0 && V_509 <= 17 ) {
} else
return - V_94 ;
if ( V_186 . V_507 ) {
if ( ! F_7 ( V_505 , NULL , NULL , L_8 ,
V_509 , 0 ) )
return - V_50 ;
} else {
if ( ! F_7 ( V_505 , NULL , NULL , L_9 ,
V_509 ) )
return - V_50 ;
}
}
return 0 ;
}
static int F_284 ( int V_510 , T_17 * V_38 )
{
int V_157 ;
T_18 V_511 ;
char V_512 [ 5 ] ;
V_157 = V_513 ;
switch ( V_514 ) {
#if V_515 >= 16
case V_516 :
if ( V_510 >= 8 && V_510 <= 15 ) {
V_157 = V_517 ;
V_510 -= 8 ;
}
#endif
case V_518 :
if ( V_510 <= 7 ) {
if ( ! F_11 ( V_157 + V_510 , & V_511 ) )
return - V_50 ;
* V_38 = V_511 * 1000 ;
return 0 ;
}
break;
case V_519 :
if ( V_510 <= 7 ) {
snprintf ( V_512 , sizeof( V_512 ) , L_274 , '0' + V_510 ) ;
if ( ! F_7 ( V_447 , NULL , L_275 , L_220 ) )
return - V_50 ;
if ( ! F_7 ( V_447 , & V_157 , V_512 , L_64 ) )
return - V_50 ;
* V_38 = ( V_157 - 2732 ) * 100 ;
return 0 ;
}
break;
case V_520 :
if ( V_510 <= 7 ) {
snprintf ( V_512 , sizeof( V_512 ) , L_274 , '0' + V_510 ) ;
if ( ! F_7 ( V_447 , & V_157 , V_512 , L_64 ) )
return - V_50 ;
if ( V_157 > 127 || V_157 < - 127 )
V_157 = V_521 ;
* V_38 = V_157 * 1000 ;
return 0 ;
}
break;
case V_522 :
default:
return - V_443 ;
}
return - V_94 ;
}
static int F_285 ( struct V_523 * V_118 )
{
int V_17 , V_42 ;
int V_217 ;
V_217 = 8 ;
V_42 = 0 ;
if ( ! V_118 )
return - V_94 ;
if ( V_514 == V_516 )
V_217 = 16 ;
for ( V_42 = 0 ; V_42 < V_217 ; V_42 ++ ) {
V_17 = F_284 ( V_42 , & V_118 -> V_524 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return V_217 ;
}
static void F_197 ( void )
{
int V_217 , V_42 ;
struct V_523 V_157 ;
V_217 = F_285 ( & V_157 ) ;
if ( V_217 <= 0 )
return;
F_32 ( L_276 ) ;
for ( V_42 = 0 ; V_42 < V_217 ; V_42 ++ ) {
if ( V_157 . V_524 [ V_42 ] != V_525 )
F_286 ( L_277 , ( int ) ( V_157 . V_524 [ V_42 ] / 1000 ) ) ;
else
F_286 ( L_278 ) ;
}
F_286 ( L_279 ) ;
}
static T_8 F_287 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
struct V_526 * V_527 =
F_288 ( V_122 ) ;
int V_510 = V_527 -> V_528 ;
T_17 V_38 ;
int V_17 ;
V_17 = F_284 ( V_510 , & V_38 ) ;
if ( V_17 )
return V_17 ;
if ( V_38 == V_525 )
return - V_49 ;
return snprintf ( V_126 , V_102 , L_44 , V_38 ) ;
}
static int T_1 F_289 ( struct V_306 * V_307 )
{
T_6 V_157 , V_529 , V_530 ;
int V_42 ;
int V_531 ;
int V_17 ;
F_17 ( V_55 , L_280 ) ;
V_531 = F_7 ( V_447 , NULL , L_281 , L_247 ) ;
if ( V_7 . V_12 ) {
V_529 = V_530 = 0 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( F_11 ( V_513 + V_42 , & V_157 ) ) {
V_529 |= V_157 ;
} else {
V_529 = 0 ;
break;
}
if ( F_11 ( V_517 + V_42 , & V_157 ) ) {
V_530 |= V_157 ;
} else {
V_529 = 0 ;
break;
}
}
if ( V_529 == 0 ) {
if ( V_531 ) {
F_8 ( L_282
L_283
L_284 ) ;
V_514 = V_520 ;
} else {
F_8 ( L_282
L_285 ) ;
V_514 = V_522 ;
}
} else {
V_514 =
( V_530 != 0 ) ?
V_516 : V_518 ;
}
} else if ( V_531 ) {
if ( F_6 () &&
F_7 ( V_447 , NULL , L_275 , L_247 ) ) {
V_514 = V_519 ;
} else {
V_514 = V_520 ;
}
} else {
V_514 = V_522 ;
}
F_17 ( V_55 , L_286 ,
F_1 ( V_514 != V_522 ) ,
V_514 ) ;
switch ( V_514 ) {
case V_516 :
V_17 = F_215 ( & V_532 -> V_60 . V_125 ,
& V_533 ) ;
if ( V_17 )
return V_17 ;
break;
case V_518 :
case V_520 :
case V_519 :
V_17 = F_215 ( & V_532 -> V_60 . V_125 ,
& V_534 ) ;
if ( V_17 )
return V_17 ;
break;
case V_522 :
default:
return 1 ;
}
return 0 ;
}
static void F_290 ( void )
{
switch ( V_514 ) {
case V_516 :
F_55 ( & V_532 -> V_60 . V_125 ,
& V_533 ) ;
break;
case V_518 :
case V_520 :
case V_519 :
F_55 ( & V_532 -> V_60 . V_125 ,
& V_534 ) ;
break;
case V_522 :
default:
break;
}
}
static int F_291 ( struct V_90 * V_91 )
{
int V_217 , V_42 ;
struct V_523 V_157 ;
V_217 = F_285 ( & V_157 ) ;
if ( F_142 ( V_217 < 0 ) )
return V_217 ;
F_84 ( V_91 , L_287 ) ;
if ( V_217 > 0 ) {
for ( V_42 = 0 ; V_42 < ( V_217 - 1 ) ; V_42 ++ )
F_84 ( V_91 , L_288 , V_157 . V_524 [ V_42 ] / 1000 ) ;
F_84 ( V_91 , L_44 , V_157 . V_524 [ V_42 ] / 1000 ) ;
} else
F_84 ( V_91 , L_289 ) ;
return 0 ;
}
static unsigned int F_292 ( void )
{
T_6 V_535 ;
V_535 = ( F_131 ( V_238 )
& V_240 )
>> V_241 ;
V_535 &= V_272 ;
return V_535 ;
}
static void F_293 ( void )
{
T_6 V_536 = 0 ;
T_6 V_537 ;
if ( V_538 != V_539 )
return;
F_17 ( V_540 ,
L_290 ) ;
if ( F_157 ( & V_541 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_542 , & V_536 ) ) )
goto V_543;
V_536 &= V_544 ;
V_537 = F_131 ( V_238 ) ;
if ( V_536 != ( ( V_537 & V_240 )
>> V_241 ) ) {
V_537 &= ~ ( V_240 <<
V_241 ) ;
V_537 |= V_536 ;
F_294 ( V_537 , V_238 ) ;
F_20 ( V_540 ,
L_291 ,
( unsigned int ) V_536 , ( unsigned int ) V_537 ) ;
} else
F_17 ( V_540 ,
L_292 ,
( unsigned int ) V_536 , ( unsigned int ) V_537 ) ;
V_543:
F_118 ( & V_541 ) ;
}
static int F_295 ( int * V_30 )
{
T_6 V_536 = 0 ;
switch ( V_538 ) {
case V_545 :
* V_30 = F_292 () ;
return 0 ;
case V_546 :
case V_539 :
if ( F_142 ( ! F_11 ( V_542 , & V_536 ) ) )
return - V_50 ;
* V_30 = V_536 ;
return 0 ;
default:
return - V_49 ;
}
}
static int F_296 ( unsigned int V_38 )
{
T_6 V_536 = 0 ;
if ( F_142 ( ! F_11 ( V_542 , & V_536 ) ) )
return - V_50 ;
if ( F_142 ( ! F_13 ( V_542 ,
( V_536 & V_547 ) |
( V_38 & V_544 ) ) ) )
return - V_50 ;
return 0 ;
}
static int F_297 ( unsigned int V_38 )
{
int V_47 , V_548 ;
unsigned int V_549 , V_42 ;
V_549 = F_292 () ;
if ( V_38 == V_549 )
return 0 ;
V_47 = ( V_38 > V_549 ) ?
V_550 :
V_551 ;
V_548 = ( V_38 > V_549 ) ? 1 : - 1 ;
for ( V_42 = V_549 ; V_42 != V_38 ; V_42 += V_548 )
if ( F_15 ( V_47 ) )
return - V_50 ;
return 0 ;
}
static int V_497 ( unsigned int V_38 )
{
int V_17 ;
if ( V_38 > V_272 || V_38 < 0 )
return - V_94 ;
F_17 ( V_540 ,
L_293 , V_38 ) ;
V_17 = F_157 ( & V_541 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_538 ) {
case V_546 :
case V_539 :
V_17 = F_296 ( V_38 ) ;
break;
case V_545 :
V_17 = F_297 ( V_38 ) ;
break;
default:
V_17 = - V_49 ;
}
F_118 ( & V_541 ) ;
return V_17 ;
}
static int F_298 ( struct V_552 * V_553 )
{
unsigned int V_56 =
( V_553 -> V_554 . V_555 == V_556 &&
V_553 -> V_554 . V_557 == V_556 ) ?
V_553 -> V_554 . V_463 : 0 ;
F_20 ( V_540 ,
L_294 ,
V_56 ) ;
return V_497 ( V_56 ) ;
}
static int V_499 ( struct V_552 * V_553 )
{
int V_30 , V_17 ;
V_17 = F_157 ( & V_541 ) ;
if ( V_17 < 0 )
return 0 ;
V_17 = F_295 ( & V_30 ) ;
F_118 ( & V_541 ) ;
if ( V_17 < 0 )
return 0 ;
return V_30 & V_544 ;
}
static void F_299 ( void )
{
F_300 ( V_558 ,
V_559 ) ;
}
static int T_1 F_301 ( T_3 V_16 )
{
struct V_26 V_560 = { V_561 , NULL } ;
union V_23 * V_562 ;
struct V_59 * V_74 , * V_563 ;
int V_73 ;
if ( F_22 ( V_16 , & V_74 ) )
return 0 ;
V_73 = 0 ;
F_302 (child, &device->children, node) {
T_4 V_30 = F_9 ( V_563 -> V_16 , L_295 ,
NULL , & V_560 ) ;
if ( F_31 ( V_30 ) )
continue;
V_562 = (union V_23 * ) V_560 . V_36 ;
if ( ! V_562 || ( V_562 -> type != V_564 ) ) {
F_8 ( L_296 ,
V_342 ) ;
V_73 = 0 ;
} else {
V_73 = V_562 -> V_565 . V_35 ;
}
break;
}
F_37 ( V_560 . V_36 ) ;
return V_73 ;
}
static unsigned int T_1 F_303 ( void )
{
T_3 V_566 ;
int V_567 = 0 ;
F_24 ( L_13 , NULL , & V_566 ) ;
if ( V_566 )
V_567 = F_301 ( V_566 ) ;
V_186 . V_568 = ( V_567 > 0 ) ;
return ( V_567 > 2 ) ? ( V_567 - 2 ) : 0 ;
}
static void T_1 F_304 ( void )
{
unsigned int V_569 ;
F_17 ( V_55 ,
L_297 ) ;
V_569 = F_303 () ;
switch ( V_569 ) {
case 16 :
V_272 = 15 ;
F_76 ( L_298 ) ;
break;
case 8 :
case 0 :
V_272 = 7 ;
F_76 ( L_299 ) ;
break;
default:
F_8 ( L_300
L_301 , V_342 ) ;
V_186 . V_273 = 1 ;
V_272 = V_569 - 1 ;
}
}
static int T_1 F_305 ( struct V_306 * V_307 )
{
struct V_570 V_554 ;
int V_569 ;
unsigned long V_13 ;
F_17 ( V_55 , L_302 ) ;
F_183 ( & V_541 ) ;
V_13 = F_4 ( V_571 ,
F_100 ( V_571 ) ) ;
if ( V_186 . V_273 )
return 1 ;
if ( ! V_572 ) {
F_20 ( V_55 | V_540 ,
L_303
L_304 ) ;
return 1 ;
}
if ( F_187 () ) {
if ( V_572 > 1 ) {
F_76 ( L_305
L_306 ) ;
return 1 ;
} else if ( V_572 == 1 ) {
F_62 ( L_307
L_308
L_309 ) ;
return 1 ;
}
} else if ( V_186 . V_568 && V_572 > 1 ) {
F_32 ( L_310
L_311
L_312 ) ;
}
if ( V_538 > V_573 )
return - V_94 ;
if ( V_538 == V_574 ||
V_538 == V_573 ) {
if ( V_13 & V_575 )
V_538 = V_539 ;
else
V_538 = V_545 ;
F_20 ( V_540 ,
L_313 ,
V_538 ) ;
}
if ( ! F_6 () &&
( V_538 == V_539 ||
V_538 == V_546 ) )
return - V_94 ;
if ( F_295 ( & V_569 ) < 0 )
return 1 ;
memset ( & V_554 , 0 , sizeof( struct V_570 ) ) ;
V_554 . type = V_576 ;
V_554 . V_577 = V_272 ;
V_554 . V_463 = V_569 & V_544 ;
V_558 = F_306 ( V_578 ,
NULL , NULL ,
& V_579 ,
& V_554 ) ;
if ( F_147 ( V_558 ) ) {
int V_73 = F_307 ( V_558 ) ;
V_558 = NULL ;
F_8 ( L_314 ) ;
return V_73 ;
}
F_17 ( V_55 | V_540 ,
L_315 ) ;
if ( V_13 & V_580 ) {
F_32 ( L_316
L_317 , V_538 ) ;
F_32 ( L_318
L_319 , V_342 ) ;
}
F_308 ( V_558 ) ;
F_17 ( V_55 | V_540 ,
L_320
L_321 ) ;
F_114 ( V_195
| V_581
| V_582 ) ;
return 0 ;
}
static void F_309 ( void )
{
F_293 () ;
}
static void F_310 ( void )
{
F_293 () ;
}
static void F_311 ( void )
{
if ( V_558 ) {
F_17 ( V_303 | V_540 ,
L_322 ) ;
F_312 ( V_558 ) ;
}
F_293 () ;
}
static int F_313 ( struct V_90 * V_91 )
{
int V_56 ;
V_56 = V_499 ( NULL ) ;
if ( V_56 < 0 ) {
F_84 ( V_91 , L_323 ) ;
} else {
F_84 ( V_91 , L_324 , V_56 ) ;
F_84 ( V_91 , L_325 ) ;
F_84 ( V_91 , L_326 ,
V_272 ) ;
}
return 0 ;
}
static int F_314 ( char * V_126 )
{
int V_56 ;
int V_73 ;
char * V_159 ;
V_56 = V_499 ( NULL ) ;
if ( V_56 < 0 )
return V_56 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_327 ) == 0 ) {
if ( V_56 < V_272 )
V_56 ++ ;
} else if ( F_86 ( V_159 , L_328 ) == 0 ) {
if ( V_56 > 0 )
V_56 -- ;
} else if ( sscanf ( V_159 , L_329 , & V_56 ) == 1 &&
V_56 >= 0 && V_56 <= V_272 ) {
} else
return - V_94 ;
}
F_82 ( L_330 ,
L_331 , V_56 ) ;
V_73 = V_497 ( V_56 ) ;
if ( ! V_73 && V_558 )
F_300 ( V_558 ,
V_583 ) ;
return ( V_73 == - V_584 ) ? - V_294 : V_73 ;
}
static void F_315 ( void )
{
T_6 V_536 = 0 ;
T_6 V_537 ;
T_6 V_585 ;
if ( V_586 != V_587 )
return;
if ( ! V_588 )
return;
F_17 ( V_589 ,
L_332 ) ;
if ( V_186 . V_590 )
V_585 = V_591 ;
else
V_585 = V_591 | V_592 ;
if ( F_157 ( & V_593 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_594 , & V_536 ) ) )
goto V_543;
V_536 &= V_585 ;
V_537 = F_131 ( V_245 ) ;
if ( V_536 != ( V_537 & V_585 ) ) {
V_537 &= ~ V_585 ;
V_537 |= V_536 ;
F_294 ( V_537 , V_245 ) ;
F_20 ( V_589 ,
L_333 ,
( unsigned int ) V_536 , ( unsigned int ) V_537 ) ;
} else {
F_17 ( V_589 ,
L_334 ,
( unsigned int ) V_536 , ( unsigned int ) V_537 ) ;
}
V_543:
F_118 ( & V_593 ) ;
}
static int F_316 ( T_6 * V_30 )
{
T_6 V_118 ;
if ( ! F_11 ( V_594 , & V_118 ) )
return - V_50 ;
* V_30 = V_118 ;
F_20 ( V_589 , L_335 , V_118 ) ;
return 0 ;
}
static int F_317 ( T_6 * V_30 )
{
return F_316 ( V_30 ) ;
}
static int F_318 ( const T_6 V_30 )
{
if ( ! F_13 ( V_594 , V_30 ) )
return - V_50 ;
F_20 ( V_589 , L_336 , V_30 ) ;
return 0 ;
}
static int F_319 ( const T_6 V_30 )
{
return F_318 ( V_30 ) ;
}
static int F_320 ( const bool V_249 )
{
int V_73 ;
T_6 V_118 , V_217 ;
if ( F_157 ( & V_593 ) < 0 )
return - V_584 ;
V_73 = F_316 ( & V_118 ) ;
if ( V_73 )
goto V_543;
V_217 = ( V_249 ) ? V_118 | V_591 :
V_118 & ~ V_591 ;
if ( V_217 != V_118 ) {
V_73 = F_318 ( V_217 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_543:
F_118 ( & V_593 ) ;
return V_73 ;
}
static int F_321 ( const bool V_249 )
{
F_20 ( V_589 , L_337 ,
( V_249 ) ? L_1 : L_42 ) ;
return F_320 ( V_249 ) ;
}
static int F_322 ( const bool V_249 )
{
int V_73 ;
F_20 ( V_589 , L_338 ,
( V_249 ) ? L_1 : L_42 ) ;
V_73 = F_320 ( V_249 ) ;
return ( V_73 < 0 ) ? V_73 : 0 ;
}
static int F_323 ( const T_6 V_595 )
{
int V_73 ;
T_6 V_118 , V_217 ;
if ( V_595 > V_596 )
return - V_94 ;
if ( F_157 ( & V_593 ) < 0 )
return - V_584 ;
V_73 = F_316 ( & V_118 ) ;
if ( V_73 )
goto V_543;
V_217 = ( V_118 & ~ V_592 ) | V_595 ;
if ( V_217 != V_118 ) {
V_73 = F_318 ( V_217 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_543:
F_118 ( & V_593 ) ;
return V_73 ;
}
static int F_324 ( const T_6 V_595 )
{
F_20 ( V_589 ,
L_339 , V_595 ) ;
return F_323 ( V_595 ) ;
}
static void F_325 ( void )
{
struct V_597 * V_218 ;
if ( V_598 && V_598 -> V_599 ) {
V_218 = V_598 -> V_599 ;
if ( V_218 -> V_600 )
F_326 ( V_598 ,
V_601 ,
V_218 -> V_600 ) ;
if ( V_218 -> V_602 )
F_326 ( V_598 ,
V_601 ,
V_218 -> V_602 ) ;
}
}
static int F_327 ( struct V_603 * V_604 ,
struct V_605 * V_606 )
{
V_606 -> type = V_607 ;
V_606 -> V_35 = 1 ;
V_606 -> V_38 . integer . V_608 = 0 ;
V_606 -> V_38 . integer . V_127 = V_596 ;
return 0 ;
}
static int F_328 ( struct V_603 * V_604 ,
struct V_609 * V_610 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_317 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_610 -> V_38 . integer . V_38 [ 0 ] = V_118 & V_592 ;
return 0 ;
}
static int F_329 ( struct V_603 * V_604 ,
struct V_609 * V_610 )
{
F_82 ( L_340 , L_341 ,
V_610 -> V_38 . integer . V_38 [ 0 ] ) ;
return F_324 ( V_610 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static int F_330 ( struct V_603 * V_604 ,
struct V_609 * V_610 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_317 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_610 -> V_38 . integer . V_38 [ 0 ] =
( V_118 & V_591 ) ? 0 : 1 ;
return 0 ;
}
static int F_331 ( struct V_603 * V_604 ,
struct V_609 * V_610 )
{
F_82 ( L_340 , L_342 ,
V_610 -> V_38 . integer . V_38 [ 0 ] ?
L_42 : L_1 ) ;
return F_321 ( ! V_610 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static void F_332 ( void )
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
if ( V_598 ) {
F_336 ( V_598 ) ;
V_598 = NULL ;
}
F_315 () ;
}
static int T_1 F_337 ( void )
{
struct V_611 * V_612 ;
struct V_597 * V_66 ;
struct V_603 * V_613 ;
struct V_603 * V_614 ;
int V_73 ;
V_73 = F_338 ( & V_154 -> V_60 ,
V_615 , V_616 , V_617 ,
sizeof( struct V_597 ) , & V_612 ) ;
if ( V_73 < 0 || ! V_612 ) {
F_8 ( L_343 , V_73 ) ;
return 1 ;
}
F_25 ( ! V_612 -> V_599 ) ;
V_66 = V_612 -> V_599 ;
V_66 -> V_612 = V_612 ;
F_339 ( V_612 -> V_81 , V_618 ,
sizeof( V_612 -> V_81 ) ) ;
F_339 ( V_612 -> V_619 , V_620 ,
sizeof( V_612 -> V_619 ) ) ;
snprintf ( V_612 -> V_621 , sizeof( V_612 -> V_621 ) , L_344 ,
( V_7 . V_622 ) ?
V_7 . V_622 : L_345 ) ;
snprintf ( V_612 -> V_623 , sizeof( V_612 -> V_623 ) ,
L_346 , V_612 -> V_619 , V_594 ,
( V_7 . V_622 ) ?
V_7 . V_622 : L_347 ) ;
if ( V_588 ) {
V_624 . V_625 = F_329 ;
V_624 . V_626 =
V_627 ;
V_628 . V_625 = F_331 ;
V_628 . V_626 =
V_627 ;
}
if ( ! V_186 . V_590 ) {
V_613 = F_340 ( & V_624 , NULL ) ;
V_73 = F_341 ( V_612 , V_613 ) ;
if ( V_73 < 0 ) {
F_8 ( L_348 ,
V_73 ) ;
goto V_341;
}
V_66 -> V_602 = & V_613 -> V_144 ;
}
V_614 = F_340 ( & V_628 , NULL ) ;
V_73 = F_341 ( V_612 , V_614 ) ;
if ( V_73 < 0 ) {
F_8 ( L_349 , V_73 ) ;
goto V_341;
}
V_66 -> V_600 = & V_614 -> V_144 ;
V_73 = F_342 ( V_612 ) ;
if ( V_73 < 0 ) {
F_8 ( L_350 , V_73 ) ;
goto V_341;
}
V_598 = V_612 ;
return 0 ;
V_341:
F_336 ( V_612 ) ;
return 1 ;
}
static int T_1 F_343 ( struct V_306 * V_307 )
{
unsigned long V_13 ;
int V_73 ;
F_17 ( V_55 , L_351 ) ;
F_183 ( & V_593 ) ;
if ( V_586 > V_629 )
return - V_94 ;
if ( V_586 == V_630 ) {
F_8 ( L_352
L_301 , V_342 ) ;
return 1 ;
}
if ( V_631 >= V_632 )
return - V_94 ;
if ( ! V_633 ) {
F_17 ( V_55 | V_589 ,
L_353
L_354 ) ;
return 1 ;
}
V_13 = F_4 ( V_634 ,
F_100 ( V_634 ) ) ;
switch ( V_631 ) {
case V_635 :
if ( V_13 & V_636 )
V_186 . V_590 = 1 ;
else if ( V_13 & V_637 )
V_186 . V_590 = 0 ;
else
return 1 ;
break;
case V_638 :
V_186 . V_590 = 0 ;
break;
case V_639 :
V_186 . V_590 = 1 ;
break;
default:
return 1 ;
}
if ( V_631 != V_635 )
F_20 ( V_55 | V_589 ,
L_355 ,
V_631 ) ;
if ( V_586 == V_640 ||
V_586 == V_629 ) {
V_586 = V_587 ;
F_20 ( V_55 | V_589 ,
L_356 ,
V_586 ) ;
} else {
F_20 ( V_55 | V_589 ,
L_357 ,
V_586 ) ;
}
F_17 ( V_55 | V_589 ,
L_358 ,
F_1 ( ! V_186 . V_590 ) ) ;
V_73 = F_337 () ;
if ( V_73 ) {
F_8 ( L_359 ) ;
return V_73 ;
}
F_76 ( L_360 ,
( V_588 ) ?
L_361 :
L_362 ) ;
F_17 ( V_55 | V_589 ,
L_363 ) ;
F_114 ( V_195
| V_641
| V_642
| V_643 ) ;
return 0 ;
}
static int F_344 ( struct V_90 * V_91 )
{
T_6 V_30 ;
if ( F_317 ( & V_30 ) < 0 ) {
F_84 ( V_91 , L_323 ) ;
} else {
if ( V_186 . V_590 )
F_84 ( V_91 , L_364 ) ;
else
F_84 ( V_91 , L_324 ,
V_30 & V_592 ) ;
F_84 ( V_91 , L_365 ,
F_256 ( V_30 , V_644 ) ) ;
if ( V_588 ) {
F_84 ( V_91 , L_366 ) ;
if ( ! V_186 . V_590 ) {
F_84 ( V_91 ,
L_325 ) ;
F_84 ( V_91 ,
L_367
L_368 ,
V_596 ) ;
}
}
}
return 0 ;
}
static int F_345 ( char * V_126 )
{
T_6 V_118 ;
T_6 V_645 , V_646 ;
int V_647 ;
char * V_159 ;
int V_73 ;
if ( ! V_588 && V_69 != V_292 ) {
if ( F_142 ( ! V_200 . V_648 ) ) {
V_200 . V_648 = 1 ;
F_32 ( L_369
L_370 ) ;
F_32 ( L_371
L_372 ) ;
}
return - V_158 ;
}
V_73 = F_317 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_645 = V_118 & V_592 ;
V_646 = V_118 & V_591 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! V_186 . V_590 ) {
if ( F_86 ( V_159 , L_327 ) == 0 ) {
if ( V_646 )
V_646 = 0 ;
else if ( V_645 < V_596 )
V_645 ++ ;
continue;
} else if ( F_86 ( V_159 , L_328 ) == 0 ) {
if ( V_646 )
V_646 = 0 ;
else if ( V_645 > 0 )
V_645 -- ;
continue;
} else if ( sscanf ( V_159 , L_373 , & V_647 ) == 1 &&
V_647 >= 0 && V_647 <= V_596 ) {
V_645 = V_647 ;
continue;
}
}
if ( F_86 ( V_159 , L_374 ) == 0 )
V_646 = V_591 ;
else if ( F_86 ( V_159 , L_375 ) == 0 )
V_646 = 0 ;
else
return - V_94 ;
}
if ( V_186 . V_590 ) {
F_82 ( L_376 , L_342 ,
V_646 ? L_1 : L_42 ) ;
V_73 = F_322 ( ! ! V_646 ) ;
} else {
F_82 ( L_376 ,
L_377 ,
V_646 ? L_1 : L_42 , V_645 ) ;
V_73 = F_319 ( V_646 | V_645 ) ;
}
F_325 () ;
return ( V_73 == - V_584 ) ? - V_294 : V_73 ;
}
static void inline F_325 ( void )
{
}
static int T_1 F_343 ( struct V_306 * V_307 )
{
F_76 ( L_378 ) ;
return 1 ;
}
static void F_346 ( void )
{
if ( V_649 == 0x07 ) {
F_32 ( L_379
L_380 ) ;
V_186 . V_650 = 1 ;
}
}
static void F_347 ( T_6 * V_651 )
{
if ( F_142 ( V_186 . V_650 ) ) {
if ( * V_651 != V_649 ) {
V_186 . V_650 = 0 ;
} else {
* V_651 = V_652 ;
}
}
}
static bool F_348 ( void )
{
if ( V_186 . V_653 ) {
T_6 V_654 ;
if ( F_12 ( V_655 , & V_654 ) < 0 )
return false ;
V_654 &= 0xFEU ;
if ( F_14 ( V_655 , V_654 ) < 0 )
return false ;
}
return true ;
}
static bool F_349 ( void )
{
T_6 V_654 ;
if ( ! V_186 . V_653 )
return false ;
if ( F_12 ( V_655 , & V_654 ) < 0 )
return false ;
V_654 |= 0x01U ;
if ( F_14 ( V_655 , V_654 ) < 0 )
return false ;
return true ;
}
static void F_350 ( T_6 V_30 )
{
if ( ( V_30 &
( V_652 | V_656 ) ) == 0 ) {
if ( V_30 > 7 )
V_657 = 7 ;
else
V_657 = V_30 ;
}
}
static int F_351 ( T_6 * V_30 )
{
T_6 V_118 ;
switch ( V_658 ) {
case V_659 : {
int V_17 ;
if ( F_142 ( ! F_7 ( V_660 , & V_17 , NULL , L_64 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) )
* V_30 = V_17 & 0x07 ;
break;
}
case V_661 :
if ( F_142 ( ! F_11 ( V_662 , & V_118 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) ) {
* V_30 = V_118 ;
F_347 ( V_30 ) ;
}
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_352 ( T_6 * V_30 )
{
int V_73 ;
T_6 V_118 ;
if ( F_157 ( & V_663 ) )
return - V_294 ;
V_73 = F_351 ( & V_118 ) ;
if ( ! V_73 )
F_350 ( V_118 ) ;
F_118 ( & V_663 ) ;
if ( V_30 )
* V_30 = V_118 ;
return V_73 ;
}
static int F_353 ( unsigned int * V_664 )
{
T_6 V_665 , V_666 ;
switch ( V_658 ) {
case V_661 :
if ( F_142 ( ! F_348 () ) )
return - V_50 ;
if ( F_142 ( ! F_11 ( V_667 , & V_666 ) ||
! F_11 ( V_667 + 1 , & V_665 ) ) )
return - V_50 ;
if ( F_140 ( V_664 ) )
* V_664 = ( V_665 << 8 ) | V_666 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_354 ( unsigned int * V_664 )
{
T_6 V_665 , V_666 ;
bool V_73 ;
switch ( V_658 ) {
case V_661 :
if ( F_142 ( ! F_349 () ) )
return - V_50 ;
V_73 = ! F_11 ( V_667 , & V_666 ) ||
! F_11 ( V_667 + 1 , & V_665 ) ;
F_348 () ;
if ( V_73 )
return - V_50 ;
if ( F_140 ( V_664 ) )
* V_664 = ( V_665 << 8 ) | V_666 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_355 ( int V_56 )
{
if ( ! V_668 )
return - V_158 ;
switch ( V_669 ) {
case V_670 :
if ( V_56 >= 0 && V_56 <= 7 ) {
if ( ! F_7 ( V_671 , NULL , NULL , L_9 , V_56 ) )
return - V_50 ;
} else
return - V_94 ;
break;
case V_672 :
case V_673 :
if ( ! ( V_56 & V_652 ) &&
! ( V_56 & V_656 ) &&
( ( V_56 < 0 ) || ( V_56 > 7 ) ) )
return - V_94 ;
if ( V_56 & V_656 )
V_56 |= 7 ;
else if ( V_56 & V_652 )
V_56 |= 4 ;
if ( ! F_13 ( V_662 , V_56 ) )
return - V_50 ;
else
V_186 . V_650 = 0 ;
break;
default:
return - V_49 ;
}
F_17 ( V_674 ,
L_381 , V_56 ) ;
return 0 ;
}
static int F_356 ( int V_56 )
{
int V_73 ;
if ( ! V_668 )
return - V_158 ;
if ( F_157 ( & V_663 ) )
return - V_294 ;
if ( V_56 == V_675 )
V_56 = V_657 ;
V_73 = F_355 ( V_56 ) ;
if ( ! V_73 )
F_350 ( V_56 ) ;
F_118 ( & V_663 ) ;
return V_73 ;
}
static int F_357 ( void )
{
T_6 V_118 ;
int V_73 ;
if ( ! V_668 )
return - V_158 ;
if ( F_157 ( & V_663 ) )
return - V_294 ;
switch ( V_669 ) {
case V_672 :
case V_673 :
V_73 = F_351 ( & V_118 ) ;
if ( V_73 < 0 )
break;
if ( V_118 != 7 ) {
V_118 &= 0x07 ;
V_118 |= V_652 | 4 ;
}
if ( ! F_13 ( V_662 , V_118 ) )
V_73 = - V_50 ;
else {
V_186 . V_650 = 0 ;
V_73 = 0 ;
}
break;
case V_670 :
V_73 = F_351 ( & V_118 ) ;
if ( V_73 < 0 )
break;
V_118 &= 0x07 ;
V_118 |= 4 ;
if ( ! F_7 ( V_671 , NULL , NULL , L_9 , V_118 ) )
V_73 = - V_50 ;
else
V_73 = 0 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_663 ) ;
if ( ! V_73 )
F_17 ( V_674 ,
L_381 ,
V_118 ) ;
return V_73 ;
}
static int F_358 ( void )
{
int V_73 ;
if ( ! V_668 )
return - V_158 ;
if ( F_157 ( & V_663 ) )
return - V_294 ;
V_73 = 0 ;
switch ( V_669 ) {
case V_672 :
case V_673 :
if ( ! F_13 ( V_662 , 0x00 ) )
V_73 = - V_50 ;
else {
V_657 = 0 ;
V_186 . V_650 = 0 ;
}
break;
case V_670 :
if ( ! F_7 ( V_671 , NULL , NULL , L_9 , 0x00 ) )
V_73 = - V_50 ;
else
V_657 = 0 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
F_17 ( V_674 ,
L_382 ) ;
F_118 ( & V_663 ) ;
return V_73 ;
}
static int F_359 ( int V_664 )
{
int V_73 ;
if ( ! V_668 )
return - V_158 ;
if ( F_157 ( & V_663 ) )
return - V_294 ;
V_73 = 0 ;
switch ( V_669 ) {
case V_672 :
if ( V_664 >= 0 && V_664 <= 65535 ) {
if ( ! F_7 ( V_676 , NULL , NULL , L_383 ,
V_664 , V_664 , V_664 ) )
V_73 = - V_50 ;
} else
V_73 = - V_94 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_663 ) ;
return V_73 ;
}
static void F_360 ( void )
{
if ( V_669 == V_677 )
return;
if ( V_678 > 0 &&
V_69 != V_199 )
F_361 ( V_466 , & V_679 ,
F_362 ( V_678 * 1000 ) ) ;
else
F_363 ( & V_679 ) ;
}
static void F_364 ( struct V_455 * V_680 )
{
int V_73 ;
if ( V_69 != V_70 )
return;
F_32 ( L_384 ) ;
V_73 = F_357 () ;
if ( V_73 < 0 ) {
F_8 ( L_385
L_386 , - V_73 ) ;
F_360 () ;
}
}
static T_8 F_365 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_352 ;
T_6 V_30 ;
V_17 = F_352 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 & V_656 ) {
V_352 = 0 ;
} else if ( V_30 & V_652 ) {
V_352 = 2 ;
} else
V_352 = 1 ;
return snprintf ( V_126 , V_102 , L_44 , V_352 ) ;
}
static T_8 F_366 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 , V_56 ;
if ( F_57 ( V_126 , 2 , & V_157 ) )
return - V_94 ;
F_82 ( L_387 ,
L_388 , V_157 ) ;
switch ( V_157 ) {
case 0 :
V_56 = V_656 ;
break;
case 1 :
V_56 = V_675 ;
break;
case 2 :
V_56 = V_652 ;
break;
case 3 :
return - V_443 ;
default:
return - V_94 ;
}
V_17 = F_356 ( V_56 ) ;
if ( V_17 == - V_49 )
return - V_94 ;
else if ( V_17 < 0 )
return V_17 ;
F_360 () ;
return V_35 ;
}
static T_8 F_367 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
T_6 V_30 ;
V_17 = F_352 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_30 &
( V_652 | V_656 ) ) != 0 )
V_30 = V_657 ;
if ( V_30 > 7 )
V_30 = 7 ;
return snprintf ( V_126 , V_102 , L_389 , ( V_30 * 255 ) / 7 ) ;
}
static T_8 F_368 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_118 ;
int V_73 ;
T_6 V_30 , V_681 ;
if ( F_57 ( V_126 , 255 , & V_118 ) )
return - V_94 ;
F_82 ( L_390 ,
L_391 , V_118 ) ;
V_681 = ( V_118 >> 5 ) & 0x07 ;
if ( F_157 ( & V_663 ) )
return - V_294 ;
V_73 = F_351 ( & V_30 ) ;
if ( ! V_73 && ( V_30 &
( V_652 | V_656 ) ) == 0 ) {
V_73 = F_355 ( V_681 ) ;
if ( V_73 == - V_49 )
V_73 = - V_94 ;
else if ( ! V_73 ) {
F_350 ( V_681 ) ;
F_360 () ;
}
}
F_118 ( & V_663 ) ;
return ( V_73 ) ? V_73 : V_35 ;
}
static T_8 F_369 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_664 ;
V_17 = F_353 ( & V_664 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_389 , V_664 ) ;
}
static T_8 F_370 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_664 ;
V_17 = F_354 ( & V_664 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_389 , V_664 ) ;
}
static T_8 F_371 ( struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_389 , V_678 ) ;
}
static T_8 F_372 ( struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 120 , & V_157 ) )
return - V_94 ;
if ( ! V_668 )
return - V_158 ;
V_678 = V_157 ;
F_360 () ;
F_82 ( L_392 , L_96 , V_157 ) ;
return V_35 ;
}
static int T_1 F_373 ( struct V_306 * V_307 )
{
int V_73 ;
unsigned long V_13 ;
F_17 ( V_55 | V_674 ,
L_393 ) ;
F_183 ( & V_663 ) ;
V_658 = V_682 ;
V_669 = V_677 ;
V_683 = 0 ;
V_678 = 0 ;
V_186 . V_650 = 0 ;
V_186 . V_653 = 0 ;
V_657 = 7 ;
if ( F_6 () ) {
F_182 ( V_684 ) ;
F_182 ( V_685 ) ;
F_182 ( V_686 ) ;
}
V_13 = F_4 ( V_687 ,
F_100 ( V_687 ) ) ;
if ( V_660 ) {
V_658 = V_659 ;
} else {
if ( F_140 ( F_11 ( V_662 ,
& V_649 ) ) ) {
V_658 = V_661 ;
if ( V_13 & V_688 )
F_346 () ;
if ( V_13 & V_689 ) {
V_186 . V_653 = 1 ;
F_20 ( V_55 | V_674 ,
L_394 ) ;
}
} else {
F_8 ( L_282
L_395 ) ;
return 1 ;
}
}
if ( V_671 ) {
V_669 = V_670 ;
V_683 |=
V_690 | V_691 ;
} else {
if ( ! V_660 ) {
if ( V_676 ) {
V_669 =
V_672 ;
V_683 |=
V_692 |
V_690 |
V_691 ;
} else {
V_669 = V_673 ;
V_683 |=
V_690 |
V_691 ;
}
}
}
F_17 ( V_55 | V_674 ,
L_396 ,
F_1 ( V_658 != V_682 ||
V_669 != V_677 ) ,
V_658 , V_669 ) ;
if ( ! V_668 ) {
V_669 = V_677 ;
V_683 = 0 ;
F_20 ( V_55 | V_674 ,
L_397 ) ;
}
if ( V_658 != V_682 )
F_352 ( NULL ) ;
if ( V_658 != V_682 ||
V_669 != V_677 ) {
if ( V_186 . V_653 ) {
V_693 [ F_100 ( V_693 ) - 2 ] =
& V_694 . V_122 ;
}
V_73 = F_215 ( & V_532 -> V_60 . V_125 ,
& V_695 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_101 ( & V_696 . V_81 ,
& V_697 ) ;
if ( V_73 < 0 ) {
F_55 ( & V_532 -> V_60 . V_125 ,
& V_695 ) ;
return V_73 ;
}
return 0 ;
} else
return 1 ;
}
static void F_374 ( void )
{
F_17 ( V_303 | V_674 ,
L_398 ) ;
F_55 ( & V_532 -> V_60 . V_125 , & V_695 ) ;
F_104 ( & V_696 . V_81 ,
& V_697 ) ;
F_363 ( & V_679 ) ;
F_254 ( V_466 ) ;
}
static void F_375 ( void )
{
int V_73 ;
if ( ! V_668 )
return;
V_698 = 0 ;
V_73 = F_352 ( & V_698 ) ;
if ( V_73 < 0 )
F_32 ( L_399
L_400 , V_73 ) ;
if ( V_186 . V_650 )
V_698 = 0 ;
}
static void F_376 ( void )
{
T_6 V_699 = 7 ;
bool V_700 = false ;
int V_73 ;
V_186 . V_650 = 0 ;
if ( ! V_668 ||
! V_698 ||
( F_352 ( & V_699 ) < 0 ) )
return;
switch ( V_669 ) {
case V_670 :
V_700 = ( V_698 > V_699 ) ;
break;
case V_672 :
case V_673 :
if ( V_698 != 7 &&
! ( V_698 & V_656 ) )
return;
else
V_700 = ! ( V_699 & V_656 ) &&
( V_699 != V_698 ) ;
break;
default:
return;
}
if ( V_700 ) {
F_32 ( L_401 ,
V_698 ) ;
V_73 = F_356 ( V_698 ) ;
if ( V_73 < 0 )
F_32 ( L_402 , V_73 ) ;
}
}
static int F_377 ( struct V_90 * V_91 )
{
int V_73 ;
T_6 V_30 ;
unsigned int V_664 = 0 ;
switch ( V_658 ) {
case V_659 :
V_73 = F_352 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47
L_324 ,
( V_30 != 0 ) ? L_48 : L_49 , V_30 ) ;
break;
case V_661 :
V_73 = F_352 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47 ,
( V_30 != 0 ) ? L_48 : L_49 ) ;
V_73 = F_353 ( & V_664 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_403 , V_664 ) ;
if ( V_30 & V_656 )
F_84 ( V_91 , L_404 ) ;
else if ( V_30 & V_652 )
F_84 ( V_91 , L_405 ) ;
else
F_84 ( V_91 , L_324 , V_30 ) ;
break;
case V_682 :
default:
F_84 ( V_91 , L_46 ) ;
}
if ( V_683 & V_690 ) {
F_84 ( V_91 , L_367 ) ;
switch ( V_669 ) {
case V_670 :
F_84 ( V_91 , L_406 ) ;
break;
default:
F_84 ( V_91 , L_407
L_408 ) ;
break;
}
}
if ( V_683 & V_691 )
F_84 ( V_91 , L_50
L_409
L_410 ) ;
if ( V_683 & V_692 )
F_84 ( V_91 , L_411
L_412 ) ;
return 0 ;
}
static int F_378 ( const char * V_159 , int * V_73 )
{
int V_56 ;
if ( F_86 ( V_159 , L_413 ) == 0 )
V_56 = V_652 ;
else if ( ( F_86 ( V_159 , L_414 ) == 0 ) |
( F_86 ( V_159 , L_415 ) == 0 ) )
V_56 = V_656 ;
else if ( sscanf ( V_159 , L_329 , & V_56 ) != 1 )
return 0 ;
* V_73 = F_356 ( V_56 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_416 ,
V_669 ) ;
else if ( ! * V_73 )
F_82 ( L_417 ,
L_331 , V_56 ) ;
return 1 ;
}
static int F_379 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_51 ) != 0 )
return 0 ;
* V_73 = F_357 () ;
if ( * V_73 == - V_49 )
F_8 ( L_418 ,
V_669 ) ;
else if ( ! * V_73 )
F_82 ( L_417 , L_419 ) ;
return 1 ;
}
static int F_380 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_52 ) != 0 )
return 0 ;
* V_73 = F_358 () ;
if ( * V_73 == - V_49 )
F_8 ( L_420 ,
V_669 ) ;
else if ( ! * V_73 )
F_82 ( L_417 , L_421 ) ;
return 1 ;
}
static int F_381 ( const char * V_159 , int * V_73 )
{
int V_664 ;
if ( sscanf ( V_159 , L_422 , & V_664 ) != 1 )
return 0 ;
* V_73 = F_359 ( V_664 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_423 ,
V_669 ) ;
else if ( ! * V_73 )
F_82 ( L_417 ,
L_424 , V_664 ) ;
return 1 ;
}
static int F_382 ( const char * V_159 , int * V_73 )
{
int V_701 ;
if ( sscanf ( V_159 , L_425 , & V_701 ) != 1 )
return 0 ;
if ( V_701 < 0 || V_701 > 120 )
* V_73 = - V_94 ;
else {
V_678 = V_701 ;
F_82 ( L_417 ,
L_426 ,
V_701 ) ;
}
return 1 ;
}
static int F_383 ( char * V_126 )
{
char * V_159 ;
int V_73 = 0 ;
while ( ! V_73 && ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! ( ( V_683 & V_690 ) &&
F_378 ( V_159 , & V_73 ) ) &&
! ( ( V_683 & V_691 ) &&
( F_379 ( V_159 , & V_73 ) ||
F_380 ( V_159 , & V_73 ) ||
F_382 ( V_159 , & V_73 ) ) ) &&
! ( ( V_683 & V_692 ) &&
F_381 ( V_159 , & V_73 ) )
)
V_73 = - V_94 ;
else if ( ! V_73 )
F_360 () ;
}
return V_73 ;
}
static int F_384 ( struct V_702 * V_157 , bool V_205 )
{
T_3 V_524 ;
int V_703 ;
if ( ! F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_524 ) ) ) {
F_62 ( L_427 , V_157 -> V_51 ) ;
return - V_50 ;
}
if ( ! F_7 ( V_129 , & V_703 , V_157 -> V_51 , L_7 ,
V_205 ? V_157 -> V_704 : V_157 -> V_705 ) )
return - V_50 ;
V_157 -> V_205 = V_205 ;
return V_205 ;
}
int F_385 ( int V_706 , bool V_707 )
{
struct V_702 * V_157 ;
if ( V_706 < 0 || V_706 >= V_708 )
return - V_94 ;
V_157 = & V_709 [ V_706 ] ;
if ( V_157 -> V_205 < 0 || V_157 -> V_205 == V_707 )
return V_157 -> V_205 ;
return F_384 ( V_157 , V_707 ) ;
}
static int F_386 ( struct V_306 * V_307 )
{
T_3 V_524 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_708 ; V_42 ++ ) {
struct V_702 * V_157 = & V_709 [ V_42 ] ;
if ( F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_524 ) ) )
F_384 ( V_157 , false ) ;
else
V_157 -> V_205 = - V_75 ;
}
return 0 ;
}
static void F_387 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_708 ; V_42 ++ )
F_385 ( V_42 , false ) ;
}
static void F_388 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_708 ; V_42 ++ ) {
struct V_702 * V_157 = & V_709 [ V_42 ] ;
if ( V_157 -> V_205 >= 0 )
F_384 ( V_157 , V_157 -> V_205 ) ;
}
}
static void F_389 ( const unsigned int V_710 )
{
if ( V_558 ) {
switch ( V_710 ) {
case V_711 :
case V_712 :
F_299 () ;
}
}
if ( V_598 ) {
switch ( V_710 ) {
case V_713 :
case V_714 :
case V_715 :
F_325 () ;
}
}
}
static void F_128 ( const unsigned int V_210 )
{
F_389 ( V_716 + V_210 ) ;
}
static T_8 F_390 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_428 , V_85 ) ;
}
static const char * T_1 F_1 ( int V_1 )
{
static char V_717 [] V_718 = L_429 ;
return ( V_1 ) ? & V_717 [ 4 ] : & V_717 [ 0 ] ;
}
static void F_391 ( struct V_67 * V_68 )
{
F_20 ( V_303 , L_430 , V_68 -> V_51 ) ;
F_392 ( & V_68 -> V_719 ) ;
if ( V_68 -> V_79 . V_80 ) {
F_20 ( V_303 ,
L_431 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_393 ( * V_68 -> V_71 -> V_16 ,
V_68 -> V_71 -> type ,
F_27 ) ;
V_68 -> V_79 . V_80 = 0 ;
}
if ( V_68 -> V_79 . V_720 ) {
F_20 ( V_303 ,
L_432 , V_68 -> V_51 ) ;
F_394 ( V_68 -> V_51 , V_721 ) ;
V_68 -> V_79 . V_720 = 0 ;
}
if ( V_68 -> V_79 . V_89 ) {
F_20 ( V_303 ,
L_433 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_395 ( V_68 -> V_71 -> V_81 ) ;
F_37 ( V_68 -> V_71 -> V_81 ) ;
V_68 -> V_71 -> V_81 = NULL ;
V_68 -> V_79 . V_89 = 0 ;
}
if ( V_68 -> V_79 . V_722 && V_68 -> exit ) {
V_68 -> exit () ;
V_68 -> V_79 . V_722 = 0 ;
}
F_20 ( V_55 , L_434 , V_68 -> V_51 ) ;
}
static int T_1 F_396 ( struct V_306 * V_307 )
{
int V_100 ;
struct V_67 * V_68 = V_307 -> V_66 ;
struct V_723 * V_724 ;
F_25 ( V_68 == NULL ) ;
F_397 ( & V_68 -> V_719 ) ;
if ( V_68 -> V_79 . V_725 && ! V_725 )
return 0 ;
F_20 ( V_55 ,
L_435 , V_68 -> V_51 ) ;
if ( V_307 -> V_726 ) {
V_100 = V_307 -> V_726 ( V_307 ) ;
if ( V_100 > 0 )
return 0 ;
if ( V_100 )
return V_100 ;
V_68 -> V_79 . V_722 = 1 ;
}
if ( V_68 -> V_71 ) {
if ( V_68 -> V_71 -> V_63 ) {
V_100 = F_34 ( V_68 ) ;
if ( V_100 )
goto V_727;
}
if ( V_68 -> V_71 -> V_72 ) {
V_100 = F_28 ( V_68 ) ;
if ( V_100 == - V_75 ) {
F_32 ( L_436 ,
V_68 -> V_51 ) ;
V_100 = 0 ;
goto V_727;
}
if ( V_100 < 0 )
goto V_727;
}
}
F_20 ( V_55 ,
L_437 , V_68 -> V_51 ) ;
if ( V_68 -> V_93 ) {
T_19 V_352 = V_307 -> V_728 ;
if ( ! V_352 )
V_352 = V_729 ;
if ( V_68 -> V_101 )
V_352 |= V_730 ;
V_724 = F_398 ( V_68 -> V_51 , V_352 , V_721 ,
& V_731 , V_68 ) ;
if ( ! V_724 ) {
F_8 ( L_438 , V_68 -> V_51 ) ;
V_100 = - V_75 ;
goto V_727;
}
V_68 -> V_79 . V_720 = 1 ;
}
F_399 ( & V_68 -> V_719 , & V_732 ) ;
return 0 ;
V_727:
F_20 ( V_55 ,
L_439 ,
V_68 -> V_51 , V_100 ) ;
F_391 ( V_68 ) ;
return ( V_100 < 0 ) ? V_100 : 0 ;
}
static bool T_2 T_1 F_400 ( const char V_37 )
{
return ( V_37 >= '0' && V_37 <= '9' ) || ( V_37 >= 'A' && V_37 <= 'Z' ) ;
}
static bool T_2 T_1 F_401 ( const char * const V_118 ,
const char V_157 )
{
return V_118 && strlen ( V_118 ) >= 8 &&
F_400 ( V_118 [ 0 ] ) &&
F_400 ( V_118 [ 1 ] ) &&
V_118 [ 2 ] == V_157 &&
( V_118 [ 3 ] == 'T' || V_118 [ 3 ] == 'N' ) &&
F_400 ( V_118 [ 4 ] ) &&
F_400 ( V_118 [ 5 ] ) ;
}
static int T_20 T_1 F_402 (
struct V_733 * V_734 )
{
const struct V_735 * V_60 = NULL ;
char V_736 [ 18 ] ;
char const * V_118 ;
if ( ! V_734 )
return - V_94 ;
memset ( V_734 , 0 , sizeof( * V_734 ) ) ;
if ( F_403 ( L_440 ) )
V_734 -> V_6 = V_15 ;
else if ( F_403 ( L_441 ) )
V_734 -> V_6 = V_14 ;
else
return 0 ;
V_118 = F_404 ( V_737 ) ;
V_734 -> V_738 = F_405 ( V_118 , V_83 ) ;
if ( V_118 && ! V_734 -> V_738 )
return - V_84 ;
if ( ! ( F_401 ( V_734 -> V_738 , 'E' ) ||
F_401 ( V_734 -> V_738 , 'C' ) ) )
return 0 ;
V_734 -> V_10 = V_734 -> V_738 [ 0 ]
| ( V_734 -> V_738 [ 1 ] << 8 ) ;
V_734 -> V_184 = ( V_734 -> V_738 [ 4 ] << 8 )
| V_734 -> V_738 [ 5 ] ;
while ( ( V_60 = F_406 ( V_739 , NULL , V_60 ) ) ) {
if ( sscanf ( V_60 -> V_51 ,
L_442 ,
V_736 ) == 1 ) {
V_736 [ sizeof( V_736 ) - 1 ] = 0 ;
V_736 [ strcspn ( V_736 , L_443 ) ] = 0 ;
V_734 -> V_622 = F_405 ( V_736 , V_83 ) ;
if ( ! V_734 -> V_622 )
return - V_84 ;
if ( F_401 ( V_736 , 'H' ) ) {
V_734 -> V_12 = V_736 [ 0 ]
| ( V_736 [ 1 ] << 8 ) ;
V_734 -> V_185 = ( V_736 [ 4 ] << 8 )
| V_736 [ 5 ] ;
} else {
F_32 ( L_444
L_445 ,
V_736 ) ;
F_32 ( L_109 ,
V_342 ) ;
}
break;
}
}
V_118 = F_404 ( V_740 ) ;
if ( V_118 && ! ( F_407 ( V_118 , L_446 , 8 ) && F_407 ( V_118 , L_447 , 6 ) ) ) {
V_734 -> V_741 = F_405 ( V_118 , V_83 ) ;
if ( ! V_734 -> V_741 )
return - V_84 ;
} else {
V_118 = F_404 ( V_742 ) ;
if ( V_118 && ! ( F_407 ( V_118 , L_447 , 6 ) ) ) {
V_734 -> V_741 = F_405 ( V_118 , V_83 ) ;
if ( ! V_734 -> V_741 )
return - V_84 ;
}
}
V_118 = F_404 ( V_743 ) ;
V_734 -> V_744 = F_405 ( V_118 , V_83 ) ;
if ( V_118 && ! V_734 -> V_744 )
return - V_84 ;
return 0 ;
}
static int T_1 F_408 ( void )
{
int V_745 ;
if ( V_746 )
return - V_75 ;
if ( ! F_6 () && ! F_5 () )
return - V_75 ;
V_745 = ( V_7 . V_741 != NULL ) ||
( V_7 . V_12 != 0 ) ||
F_107 () ;
F_24 ( L_448 , V_747 , & V_447 ) ;
if ( ! V_447 ) {
if ( V_745 )
F_8 ( L_449 ) ;
return - V_75 ;
}
if ( ! V_745 && ! V_748 )
return - V_75 ;
return 0 ;
}
static void T_1 F_409 ( void )
{
F_76 ( L_57 , V_165 , V_166 ) ;
F_76 ( L_428 , V_749 ) ;
F_76 ( L_450 ,
( V_7 . V_738 ) ?
V_7 . V_738 : L_347 ,
( V_7 . V_622 ) ?
V_7 . V_622 : L_347 ) ;
F_25 ( ! V_7 . V_6 ) ;
if ( V_7 . V_741 )
F_76 ( L_451 ,
( V_7 . V_6 == V_15 ) ?
L_440 : ( ( V_7 . V_6 ==
V_14 ) ?
L_447 : L_452 ) ,
V_7 . V_741 ,
( V_7 . V_744 ) ?
V_7 . V_744 : L_347 ) ;
}
static int T_1 F_410 ( const char * V_654 , struct V_750 * V_751 )
{
unsigned int V_42 ;
struct V_67 * V_68 ;
if ( ! V_751 || ! V_751 -> V_51 || ! V_654 )
return - V_94 ;
for ( V_42 = 0 ; V_42 < F_100 ( V_752 ) ; V_42 ++ ) {
V_68 = V_752 [ V_42 ] . V_66 ;
F_411 ( V_68 == NULL ) ;
if ( ! V_68 || ! V_68 -> V_51 )
continue;
if ( strcmp ( V_68 -> V_51 , V_751 -> V_51 ) == 0 && V_68 -> V_101 ) {
if ( strlen ( V_654 ) > sizeof( V_752 [ V_42 ] . V_753 ) - 2 )
return - V_754 ;
strcpy ( V_752 [ V_42 ] . V_753 , V_654 ) ;
strcat ( V_752 [ V_42 ] . V_753 , L_28 ) ;
return 0 ;
}
}
return - V_94 ;
}
static void F_412 ( void )
{
struct V_67 * V_68 , * V_107 ;
V_69 = V_199 ;
F_413 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
F_391 ( V_68 ) ;
}
F_20 ( V_55 , L_453 ) ;
if ( V_208 ) {
if ( V_186 . V_755 )
F_414 ( V_208 ) ;
else
F_415 ( V_208 ) ;
F_37 ( V_212 ) ;
}
if ( V_756 )
F_416 ( V_756 ) ;
if ( V_186 . V_757 )
F_262 ( & V_532 -> V_60 ,
& V_758 ) ;
if ( V_532 )
F_417 ( V_532 ) ;
if ( V_154 )
F_417 ( V_154 ) ;
if ( V_186 . V_759 )
F_103 ( & V_696 . V_81 ) ;
if ( V_186 . V_760 )
F_103 ( & V_761 . V_81 ) ;
if ( V_186 . V_762 )
F_418 ( & V_696 ) ;
if ( V_186 . V_763 )
F_418 ( & V_761 ) ;
if ( V_721 )
F_394 ( V_764 , V_765 ) ;
if ( V_466 )
F_419 ( V_466 ) ;
F_37 ( V_7 . V_738 ) ;
F_37 ( V_7 . V_622 ) ;
F_37 ( V_7 . V_741 ) ;
F_37 ( V_7 . V_744 ) ;
}
static int T_1 F_420 ( void )
{
int V_100 , V_42 ;
V_69 = V_292 ;
V_100 = F_402 ( & V_7 ) ;
if ( V_100 ) {
F_8 ( L_454 , V_100 ) ;
F_412 () ;
return V_100 ;
}
V_100 = F_408 () ;
if ( V_100 ) {
F_412 () ;
return V_100 ;
}
F_409 () ;
F_106 () ;
F_182 ( V_766 ) ;
F_182 ( V_767 ) ;
V_466 = F_421 ( V_768 ) ;
if ( ! V_466 ) {
F_412 () ;
return - V_84 ;
}
V_721 = F_422 ( V_764 , V_765 ) ;
if ( ! V_721 ) {
F_8 ( L_455 V_764 L_279 ) ;
F_412 () ;
return - V_75 ;
}
V_100 = F_423 ( & V_761 ) ;
if ( V_100 ) {
F_8 ( L_456 ) ;
F_412 () ;
return V_100 ;
}
V_186 . V_763 = 1 ;
V_100 = F_423 ( & V_696 ) ;
if ( V_100 ) {
F_8 ( L_457 ) ;
F_412 () ;
return V_100 ;
}
V_186 . V_762 = 1 ;
V_100 = F_99 ( & V_761 . V_81 ) ;
if ( ! V_100 ) {
V_186 . V_760 = 1 ;
V_100 = F_99 (
& V_696 . V_81 ) ;
}
if ( V_100 ) {
F_8 ( L_458 ) ;
F_412 () ;
return V_100 ;
}
V_186 . V_759 = 1 ;
V_154 = F_424 ( V_769 , - 1 ,
NULL , 0 ) ;
if ( F_147 ( V_154 ) ) {
V_100 = F_307 ( V_154 ) ;
V_154 = NULL ;
F_8 ( L_459 ) ;
F_412 () ;
return V_100 ;
}
V_532 = F_424 (
V_770 ,
- 1 , NULL , 0 ) ;
if ( F_147 ( V_532 ) ) {
V_100 = F_307 ( V_532 ) ;
V_532 = NULL ;
F_8 ( L_460 ) ;
F_412 () ;
return V_100 ;
}
V_100 = F_260 ( & V_532 -> V_60 ,
& V_758 ) ;
if ( V_100 ) {
F_8 ( L_461 ) ;
F_412 () ;
return V_100 ;
}
V_186 . V_757 = 1 ;
V_756 = F_425 ( & V_532 -> V_60 ) ;
if ( F_147 ( V_756 ) ) {
V_100 = F_307 ( V_756 ) ;
V_756 = NULL ;
F_8 ( L_462 ) ;
F_412 () ;
return V_100 ;
}
F_183 ( & V_207 ) ;
V_208 = F_426 () ;
if ( ! V_208 ) {
F_412 () ;
return - V_84 ;
} else {
V_208 -> V_51 = L_463 ;
V_208 -> V_771 = V_769 L_464 ;
V_208 -> V_144 . V_772 = V_773 ;
V_208 -> V_144 . V_6 = V_7 . V_6 ;
V_208 -> V_144 . V_774 = V_775 ;
V_208 -> V_144 . V_776 = V_777 ;
V_208 -> V_60 . V_52 = & V_154 -> V_60 ;
}
F_304 () ;
for ( V_42 = 0 ; V_42 < F_100 ( V_752 ) ; V_42 ++ ) {
V_100 = F_396 ( & V_752 [ V_42 ] ) ;
if ( V_100 >= 0 && * V_752 [ V_42 ] . V_753 )
V_100 = V_752 [ V_42 ] . V_66 -> V_101 ( V_752 [ V_42 ] . V_753 ) ;
if ( V_100 < 0 ) {
F_412 () ;
return V_100 ;
}
}
V_69 = V_70 ;
V_100 = F_427 ( V_208 ) ;
if ( V_100 < 0 ) {
F_8 ( L_465 ) ;
F_412 () ;
return V_100 ;
} else {
V_186 . V_755 = 1 ;
}
return 0 ;
}
