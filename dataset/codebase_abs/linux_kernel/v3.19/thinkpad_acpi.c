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
V_324 ,
V_331 , V_332 , V_333 , V_334 ,
} ,
} ;
static const struct V_3 V_335 [] V_311 = {
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
int V_336 ;
bool V_337 = false ;
bool V_338 = false ;
unsigned long V_13 ;
unsigned long V_339 ;
F_17 ( V_55 | V_304 ,
L_104 ) ;
F_25 ( ! V_208 ) ;
F_25 ( V_208 -> V_340 != NULL ||
V_208 -> V_341 != NULL ) ;
F_182 ( V_342 ) ;
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
V_13 = F_4 ( V_343 ,
F_100 ( V_343 ) ) ;
F_60 () ;
V_302 = F_51 (
F_100 ( V_344 ) + 2 ,
NULL ) ;
if ( ! V_302 )
return - V_84 ;
V_17 = F_53 ( V_302 ,
V_344 ,
F_100 ( V_344 ) ) ;
if ( V_17 )
goto V_345;
if ( F_7 ( V_129 , & V_336 , L_106 , L_107 ) ) {
if ( ( V_336 >> 8 ) != 1 ) {
F_8 ( L_108 ,
V_336 ) ;
F_8 ( L_109 , V_346 ) ;
} else {
F_17 ( V_55 | V_304 ,
L_110 ,
V_336 ) ;
if ( ! F_7 ( V_129 , & V_191 ,
L_111 , L_107 ) ) {
F_8 ( L_112
L_109 ,
V_346 ) ;
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
( V_13 & V_347 ) )
V_191 = 0x080cU ;
if ( V_186 . V_189 ) {
V_17 = F_110 () ;
if ( V_17 )
goto V_345;
V_295 = V_190 ;
} else {
V_295 = V_191 ;
V_190 = V_191 ;
}
#ifdef F_102
if ( V_172 ) {
V_186 . V_187 = 1 ;
V_337 = ! ! V_167 ;
F_76 ( L_114 ) ;
} else
#endif
if ( F_7 ( V_129 , & V_30 , L_63 , L_107 ) ) {
V_186 . V_187 = 1 ;
V_337 = ! ! V_30 ;
F_76 ( L_115 ,
F_184 ( V_30 , 0 ) ) ;
}
if ( V_186 . V_187 )
V_17 = F_52 ( V_302 ,
& V_348 . V_122 ) ;
if ( ! V_17 && F_7 ( V_129 , & V_30 , L_65 , L_107 ) ) {
V_186 . V_206 = 1 ;
V_338 = ! ! ( V_30 & V_188 ) ;
F_76 ( L_116
L_117 ,
( V_338 ) ? L_118 : L_119 ) ;
V_17 = F_52 ( V_302 ,
& V_349 . V_122 ) ;
}
if ( ! V_17 )
V_17 = F_185 (
V_302 ,
& V_154 -> V_60 . V_125 ) ;
if ( V_17 )
goto V_345;
V_212 = F_44 ( F_180 ,
V_83 ) ;
if ( ! V_212 ) {
F_8 ( L_120 ) ;
V_17 = - V_84 ;
goto V_345;
}
V_339 = F_4 ( V_335 ,
F_100 ( V_335 ) ) ;
F_25 ( V_339 >= F_100 ( V_310 ) ) ;
F_20 ( V_55 | V_304 ,
L_121 , V_339 ) ;
memcpy ( V_212 , & V_310 [ V_339 ] ,
F_180 ) ;
F_186 ( V_208 , V_214 , V_215 ) ;
V_208 -> V_350 = F_181 ;
V_208 -> V_351 = V_352 ;
V_208 -> V_211 = V_212 ;
for ( V_42 = 0 ; V_42 < V_352 ; V_42 ++ ) {
if ( V_212 [ V_42 ] != V_213 ) {
F_186 ( V_208 , V_353 ,
V_212 [ V_42 ] ) ;
} else {
if ( V_42 < sizeof( V_296 ) * 8 )
V_296 |= 1 << V_42 ;
}
}
if ( V_186 . V_187 ) {
F_186 ( V_208 , V_354 , V_301 ) ;
F_122 ( V_208 ,
V_301 , V_337 ) ;
}
if ( V_186 . V_206 ) {
F_186 ( V_208 , V_354 , V_209 ) ;
F_122 ( V_208 ,
V_209 , V_338 ) ;
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
V_193 = V_355
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
V_208 -> V_340 = & F_150 ;
V_208 -> V_341 = & F_152 ;
F_148 ( true ) ;
return 0 ;
V_345:
F_54 ( V_302 , & V_154 -> V_60 . V_125 ) ;
V_302 = NULL ;
return ( V_17 < 0 ) ? V_17 : 1 ;
}
static int F_188 ( int V_356 )
{
T_10 V_42 ;
T_10 V_357 = F_100 ( V_358 ) - 1 ;
for ( V_42 = 0 ; V_42 <= V_357 ; V_42 ++ ) {
if ( V_358 [ V_42 ] == V_356 )
break;
}
if ( V_42 >= V_357 )
V_42 = 0 ;
else
V_42 ++ ;
return V_358 [ V_42 ] ;
}
static bool F_189 ( unsigned int V_210 )
{
T_7 V_359 = 0 ;
int V_360 = 0 ;
switch ( V_210 ) {
case V_361 :
if ( V_362 ) {
V_360 = V_363 ;
V_362 = false ;
} else {
if ( ! F_7 (
V_129 , & V_359 ,
L_130 , L_7 , 0 ) ) {
F_8 ( L_131 ) ;
return false ;
} else {
V_360 = F_188 (
V_359 ) ;
}
}
if ( ! F_7 ( V_129 , NULL , L_132 , L_9 , V_360 ) ) {
F_8 ( L_133 ) ;
return false ;
}
return true ;
case V_364 :
if ( ! F_7 ( V_129 ,
& V_363 ,
L_130 , L_7 , 0 ) ) {
F_8 ( L_131 ) ;
return false ;
} else {
V_362 = true ;
if ( ! F_7 ( V_129 ,
NULL , L_132 , L_9 , V_365 ) ) {
F_8 ( L_133 ) ;
return false ;
}
}
return true ;
default:
return false ;
}
}
static bool F_190 ( const T_7 V_342 ,
bool * V_366 ,
bool * V_367 )
{
unsigned int V_210 = V_342 & 0xfff ;
* V_366 = true ;
* V_367 = false ;
if ( V_210 > 0 && V_210 <= V_352 ) {
V_210 -- ;
if ( ! ( V_193 & ( 1 << V_210 ) ) ) {
F_127 ( V_210 ) ;
* V_366 = false ;
} else {
* V_367 = true ;
}
return true ;
} else {
return F_189 ( V_210 ) ;
}
return false ;
}
static bool F_191 ( const T_7 V_342 ,
bool * V_366 ,
bool * V_367 )
{
* V_366 = true ;
* V_367 = false ;
switch ( V_342 ) {
case V_368 :
case V_369 :
V_298 = V_370 ;
* V_367 = true ;
break;
case V_371 :
case V_372 :
V_298 = V_373 ;
* V_367 = true ;
break;
case V_374 :
case V_375 :
F_192 ( L_134 ) ;
break;
default:
return false ;
}
if ( V_298 != V_376 ) {
F_76 ( L_135 ) ;
F_172 () ;
}
return true ;
}
static bool F_193 ( const T_7 V_342 ,
bool * V_366 ,
bool * V_367 )
{
* V_366 = true ;
* V_367 = false ;
switch ( V_342 ) {
case V_377 :
V_299 = 1 ;
F_76 ( L_136 ) ;
F_174 () ;
return true ;
case V_378 :
F_76 ( L_137 ) ;
return true ;
case V_379 :
F_76 ( L_138 ) ;
return true ;
default:
return false ;
}
}
static bool F_194 ( const T_7 V_342 ,
bool * V_366 ,
bool * V_367 )
{
* V_366 = true ;
* V_367 = false ;
switch ( V_342 ) {
case V_380 :
case V_381 :
return true ;
case V_382 :
case V_383 :
F_121 () ;
F_170 () ;
* V_366 = false ;
return true ;
case V_384 :
case V_385 :
case V_386 :
* V_367 = true ;
return true ;
default:
return false ;
}
}
static bool F_195 ( const T_7 V_342 ,
bool * V_366 ,
bool * V_367 )
{
bool V_387 = true ;
* V_366 = true ;
* V_367 = false ;
switch ( V_342 ) {
case V_388 :
F_76 ( L_139 ) ;
return true ;
case V_389 :
F_196 ( L_140 ) ;
break;
case V_390 :
F_192 ( L_141 ) ;
break;
case V_391 :
F_196 ( L_142
L_143 ) ;
break;
case V_392 :
F_192 ( L_144
L_145 ) ;
break;
case V_393 :
case V_394 :
case V_395 :
* V_366 = false ;
* V_367 = true ;
return true ;
default:
F_62 ( L_146 ) ;
V_387 = false ;
}
F_197 () ;
return V_387 ;
}
static void F_198 ( struct V_67 * V_68 , T_7 V_65 )
{
T_7 V_342 ;
bool V_366 ;
bool V_367 ;
bool V_396 ;
if ( V_65 != 0x80 ) {
F_8 ( L_147 , V_65 ) ;
F_199 (
V_68 -> V_71 -> V_74 -> V_397 . V_398 ,
F_200 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , 0 ) ;
return;
}
while ( 1 ) {
if ( ! F_7 ( V_129 , & V_342 , L_148 , L_64 ) ) {
F_8 ( L_149 ) ;
return;
}
if ( V_342 == 0 ) {
return;
}
V_366 = true ;
V_367 = false ;
switch ( V_342 >> 12 ) {
case 1 :
V_396 = F_190 ( V_342 , & V_366 ,
& V_367 ) ;
break;
case 2 :
V_396 = F_191 ( V_342 , & V_366 ,
& V_367 ) ;
break;
case 3 :
switch ( V_342 ) {
case V_399 :
V_299 = 1 ;
F_76 ( L_150 ) ;
F_174 () ;
V_396 = true ;
break;
case V_400 :
V_396 = true ;
break;
default:
V_396 = false ;
}
break;
case 4 :
V_396 = F_193 ( V_342 , & V_366 ,
& V_367 ) ;
break;
case 5 :
V_396 = F_194 ( V_342 , & V_366 ,
& V_367 ) ;
break;
case 6 :
V_396 = F_195 ( V_342 , & V_366 ,
& V_367 ) ;
break;
case 7 :
if ( V_186 . V_187 &&
V_342 == V_401 ) {
F_175 () ;
V_366 = 0 ;
V_396 = true ;
break;
}
default:
V_396 = false ;
}
if ( ! V_396 ) {
F_32 ( L_151 , V_342 ) ;
F_32 ( L_152
L_153 , V_346 ) ;
}
if ( ! V_367 && V_366 ) {
F_199 (
V_68 -> V_71 -> V_74 -> V_397 . V_398 ,
F_200 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , V_342 ) ;
}
}
}
static void F_201 ( void )
{
int V_336 ;
V_298 = V_376 ;
V_299 = 0 ;
if ( F_7 ( V_129 , & V_336 , L_106 , L_107 ) ) {
if ( ( V_336 >> 8 ) == 2 ) {
if ( ! F_7 ( V_129 ,
& V_363 ,
L_130 , L_7 , 0 ) ) {
F_8 ( L_154 ) ;
}
}
}
}
static void F_202 ( void )
{
int V_336 ;
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
if ( F_7 ( V_129 , & V_336 , L_106 , L_107 ) ) {
if ( ( V_336 >> 8 ) == 2 ) {
if ( ! F_7 ( V_129 ,
NULL ,
L_132 , L_9 ,
V_363 ) ) {
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
goto V_402;
}
}
if ( ! V_17 ) {
F_82 ( L_171 ,
L_172 , V_197 ) ;
V_17 = F_113 ( V_197 ) ;
}
V_402:
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
return ( ( V_30 & V_403 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_209 ( enum V_404 V_205 )
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
V_30 = V_403
| V_405 ;
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
return F_80 ( V_406 ,
V_122 , V_126 ) ;
}
static T_8 F_211 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_406 ,
V_122 , V_126 , V_35 ) ;
}
static void F_212 ( void )
{
if ( ! F_7 ( NULL , NULL , L_176 , L_9 ,
V_407 ) )
F_32 ( L_177 ) ;
else
F_17 ( V_140 ,
L_178 ) ;
}
static void F_213 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_408 ) ;
F_77 ( V_406 ) ;
F_212 () ;
}
static int T_1 F_214 ( struct V_306 * V_307 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_179 ) ;
F_182 ( V_342 ) ;
V_186 . V_409 = V_129 &&
F_7 ( V_129 , & V_30 , L_173 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_180 ,
F_1 ( V_186 . V_409 ) ,
V_30 ) ;
#ifdef F_102
if ( V_174 ) {
V_186 . V_409 = 1 ;
F_76 ( L_181 ) ;
} else
#endif
if ( V_186 . V_409 &&
! ( V_30 & V_410 ) ) {
V_186 . V_409 = 0 ;
F_20 ( V_55 | V_140 ,
L_182 ) ;
}
if ( ! V_186 . V_409 )
return 1 ;
V_17 = F_71 ( V_406 ,
& V_411 ,
V_412 ,
V_413 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_215 ( & V_154 -> V_60 . V_125 ,
& V_408 ) ;
if ( V_17 ) {
F_77 ( V_406 ) ;
return V_17 ;
}
return 0 ;
}
static int F_216 ( struct V_90 * V_91 )
{
return F_83 ( V_406 , V_91 ) ;
}
static int F_217 ( char * V_126 )
{
return F_85 ( V_406 , V_126 ) ;
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
return ( ( V_30 & V_414 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_219 ( enum V_404 V_205 )
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
V_30 = V_414
| V_415 ;
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
return F_80 ( V_416 ,
V_122 , V_126 ) ;
}
static T_8 F_221 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_416 ,
V_122 , V_126 , V_35 ) ;
}
static void F_222 ( void )
{
if ( ! F_7 ( NULL , NULL , L_186 , L_9 ,
V_417 ) )
F_32 ( L_187 ) ;
else
F_17 ( V_140 ,
L_188 ) ;
}
static void F_223 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_418 ) ;
F_77 ( V_416 ) ;
F_222 () ;
}
static int T_1 F_224 ( struct V_306 * V_307 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_189 ) ;
F_182 ( V_342 ) ;
V_186 . V_419 = V_129 &&
F_7 ( V_129 , & V_30 , L_183 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_190 ,
F_1 ( V_186 . V_419 ) ,
V_30 ) ;
#ifdef F_102
if ( V_176 ) {
V_186 . V_419 = 1 ;
F_76 ( L_191 ) ;
} else
#endif
if ( V_186 . V_419 &&
! ( V_30 & V_420 ) ) {
V_186 . V_419 = 0 ;
F_20 ( V_55 | V_140 ,
L_192 ) ;
}
if ( ! V_186 . V_419 )
return 1 ;
V_17 = F_71 ( V_416 ,
& V_421 ,
V_422 ,
V_423 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_215 ( & V_154 -> V_60 . V_125 ,
& V_418 ) ;
if ( V_17 ) {
F_77 ( V_416 ) ;
return V_17 ;
}
return 0 ;
}
static int F_225 ( struct V_90 * V_91 )
{
return F_83 ( V_416 , V_91 ) ;
}
static int F_226 ( char * V_126 )
{
return F_85 ( V_416 , V_126 ) ;
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
return ( ( V_30 & V_424 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_228 ( enum V_404 V_205 )
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
V_30 = V_424 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_195 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static void F_229 ( void )
{
F_77 ( V_425 ) ;
}
static int T_1 F_230 ( struct V_306 * V_307 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_196 ) ;
F_182 ( V_342 ) ;
V_186 . V_426 = V_129 &&
F_7 ( V_129 , & V_30 , L_193 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_197 ,
F_1 ( V_186 . V_426 ) ,
V_30 ) ;
#ifdef F_102
if ( V_178 ) {
V_186 . V_426 = 1 ;
F_76 ( L_198 ) ;
} else
#endif
if ( V_186 . V_426 &&
! ( V_30 & V_427 ) ) {
V_186 . V_426 = 0 ;
F_20 ( V_55 ,
L_199 ) ;
}
if ( ! V_186 . V_426 )
return 1 ;
V_17 = F_71 ( V_425 ,
& V_428 ,
V_429 ,
V_430 ,
false ) ;
return V_17 ;
}
static int T_1 F_231 ( struct V_306 * V_307 )
{
int V_431 ;
F_17 ( V_55 , L_200 ) ;
F_182 ( V_432 ) ;
if ( F_6 () )
F_182 ( V_433 ) ;
if ( V_434 && F_7 ( NULL , & V_431 , L_201 , L_64 ) && V_431 )
V_435 = V_434 ;
if ( ! V_435 )
V_436 = V_437 ;
else if ( F_6 () &&
F_7 ( V_435 , & V_438 , L_202 , L_107 ) )
V_436 = V_439 ;
else if ( F_6 () &&
F_7 ( V_435 , & V_438 , L_203 , L_107 ) )
V_436 = V_440 ;
else
V_436 = V_441 ;
F_17 ( V_55 , L_204 ,
F_1 ( V_436 != V_437 ) ,
V_436 ) ;
return ( V_436 != V_437 ) ? 0 : 1 ;
}
static void F_232 ( void )
{
F_20 ( V_303 ,
L_205 ) ;
if ( F_233 ( V_438 ) )
F_8 ( L_206
L_207 ) ;
}
static int F_234 ( void )
{
int V_30 = 0 ;
int V_42 ;
switch ( V_436 ) {
case V_439 :
if ( ! F_7 ( NULL , & V_42 , L_208 , L_7 ,
V_442 ) )
return - V_50 ;
V_30 = V_42 & V_443 ;
break;
case V_440 :
if ( ! F_7 ( NULL , & V_42 , L_209 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_444 ;
if ( ! F_7 ( NULL , & V_42 , L_210 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_445 ;
break;
case V_441 :
if ( ! F_7 ( NULL , NULL , L_211 , L_9 , 1 ) ||
! F_7 ( NULL , & V_42 , L_210 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_445 ;
if ( ! F_7 ( NULL , NULL , L_211 , L_9 , 0 ) ||
! F_7 ( NULL , & V_42 , L_209 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_444 ;
if ( ! F_7 ( NULL , & V_42 , L_212 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_446 ;
break;
default:
return - V_447 ;
}
return V_30 ;
}
static int F_235 ( int V_30 )
{
int V_448 ;
int V_17 = 0 ;
switch ( V_436 ) {
case V_439 :
V_17 = F_7 ( NULL , NULL ,
L_213 , L_8 ,
V_449 ,
V_30 | V_450 ) ;
break;
case V_440 :
V_448 = F_236 () ;
if ( V_448 < 0 )
return V_448 ;
V_17 = F_233 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_435 , NULL ,
L_214 , L_8 , V_30 * 0x100 , 0 ) ;
if ( ! V_448 && F_233 ( V_448 ) ) {
F_8 ( L_215 ) ;
return - V_50 ;
}
break;
case V_441 :
V_17 = F_7 ( NULL , NULL , L_211 , L_9 , 0x80 ) &&
F_7 ( NULL , NULL , L_216 , L_8 , V_30 , 1 ) ;
break;
default:
return - V_447 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_236 ( void )
{
int V_448 = 0 ;
switch ( V_436 ) {
case V_439 :
if ( ! F_7 ( V_435 , & V_448 , L_202 , L_64 ) )
return - V_50 ;
break;
case V_440 :
case V_441 :
if ( ! F_7 ( V_435 , & V_448 , L_217 , L_64 ) )
return - V_50 ;
break;
default:
return - V_447 ;
}
return V_448 & 1 ;
}
static int F_233 ( int V_204 )
{
if ( ! F_7 ( V_435 , NULL , L_218 , L_9 , ( V_204 ) ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static int F_237 ( void )
{
int V_448 = F_236 () ;
int V_17 ;
if ( V_448 < 0 )
return V_448 ;
switch ( V_436 ) {
case V_439 :
V_17 = F_233 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_451 , NULL , L_219 , L_220 ) ;
break;
case V_440 :
case V_441 :
V_17 = F_233 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_435 , NULL , L_221 , L_220 ) ;
break;
default:
return - V_447 ;
}
if ( ! V_448 && F_233 ( V_448 ) ) {
F_8 ( L_215 ) ;
return - V_50 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_238 ( void )
{
switch ( V_436 ) {
case V_439 :
return F_7 ( V_451 , NULL , L_222 , L_220 ) ?
0 : - V_50 ;
case V_440 :
return F_7 ( V_435 , NULL , L_223 , L_220 ) ?
0 : - V_50 ;
case V_441 :
return F_7 ( NULL , NULL , L_224 , L_220 ) ?
0 : - V_50 ;
default:
return - V_447 ;
}
}
static int F_239 ( struct V_90 * V_91 )
{
int V_30 , V_448 ;
if ( V_436 == V_437 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
if ( ! F_240 ( V_452 ) )
return - V_158 ;
V_30 = F_234 () ;
if ( V_30 < 0 )
return V_30 ;
V_448 = F_236 () ;
if ( V_448 < 0 )
return V_448 ;
F_84 ( V_91 , L_225 ) ;
F_84 ( V_91 , L_226 , F_184 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_227 , F_184 ( V_30 , 1 ) ) ;
if ( V_436 == V_441 )
F_84 ( V_91 , L_228 , F_184 ( V_30 , 3 ) ) ;
F_84 ( V_91 , L_229 , F_184 ( V_448 , 0 ) ) ;
F_84 ( V_91 , L_230 ) ;
F_84 ( V_91 , L_231 ) ;
if ( V_436 == V_441 )
F_84 ( V_91 , L_232 ) ;
F_84 ( V_91 , L_233 ) ;
F_84 ( V_91 , L_234 ) ;
return 0 ;
}
static int F_241 ( char * V_126 )
{
char * V_159 ;
int V_204 , V_453 , V_30 ;
int V_17 ;
if ( V_436 == V_437 )
return - V_75 ;
if ( ! F_240 ( V_452 ) )
return - V_158 ;
V_204 = 0 ;
V_453 = 0 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_235 ) == 0 ) {
V_204 |= V_444 ;
} else if ( F_86 ( V_159 , L_236 ) == 0 ) {
V_453 |= V_444 ;
} else if ( F_86 ( V_159 , L_237 ) == 0 ) {
V_204 |= V_445 ;
} else if ( F_86 ( V_159 , L_238 ) == 0 ) {
V_453 |= V_445 ;
} else if ( V_436 == V_441 &&
F_86 ( V_159 , L_239 ) == 0 ) {
V_204 |= V_446 ;
} else if ( V_436 == V_441 &&
F_86 ( V_159 , L_240 ) == 0 ) {
V_453 |= V_446 ;
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
if ( V_204 || V_453 ) {
V_30 = F_234 () ;
if ( V_30 < 0 )
return V_30 ;
V_17 = F_235 ( ( V_30 & ~ V_453 ) | V_204 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_242 ( void )
{
int V_30 = 0 ;
if ( V_186 . V_454 ) {
if ( ! F_7 ( V_451 , & V_30 , L_245 , L_64 ) )
return - V_50 ;
return ( ! ! V_30 ) ;
}
return - V_49 ;
}
static int F_243 ( int V_30 )
{
int V_73 ;
if ( V_186 . V_455 ) {
if ( V_48 ) {
V_73 = F_7 ( V_48 , NULL , NULL , L_9 ,
( V_30 ) ?
V_456 :
V_457 ) ;
} else {
V_73 = F_7 ( V_458 , NULL , NULL , L_9 ,
( V_30 ) ? 1 : 0 ) ;
}
return ( V_73 ) ? 0 : - V_50 ;
}
return - V_49 ;
}
static void F_244 ( struct V_459 * V_460 )
{
struct V_461 * V_66 =
F_245 ( V_460 , struct V_461 , V_460 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_243 ( ( V_66 -> V_462 != V_463 ) ) ;
}
static void F_246 ( struct V_464 * V_465 ,
enum V_466 V_467 )
{
struct V_461 * V_66 =
F_245 ( V_465 ,
struct V_461 ,
V_464 ) ;
V_66 -> V_462 = ( V_467 != V_468 ) ?
V_469 : V_463 ;
F_247 ( V_470 , & V_66 -> V_460 ) ;
}
static enum V_466 F_248 ( struct V_464 * V_465 )
{
return ( F_242 () == 1 ) ? V_471 : V_468 ;
}
static int T_1 F_249 ( struct V_306 * V_307 )
{
int V_73 ;
F_17 ( V_55 , L_246 ) ;
if ( F_6 () ) {
F_182 ( V_472 ) ;
F_182 ( V_473 ) ;
}
F_182 ( V_474 ) ;
F_250 ( & V_475 . V_460 , F_244 ) ;
V_186 . V_455 = ( V_48 || V_458 ) && ! V_476 ;
if ( V_186 . V_455 )
V_186 . V_454 =
F_7 ( V_451 , NULL , L_245 , L_247 ) ;
F_17 ( V_55 , L_248 ,
F_1 ( V_186 . V_455 ) ,
F_1 ( V_186 . V_454 ) ) ;
if ( ! V_186 . V_455 )
return 1 ;
V_73 = F_251 ( & V_154 -> V_60 ,
& V_475 . V_464 ) ;
if ( V_73 < 0 ) {
V_186 . V_455 = 0 ;
V_186 . V_454 = 0 ;
} else {
V_73 = 0 ;
}
return V_73 ;
}
static void F_252 ( void )
{
F_253 ( & V_475 . V_464 ) ;
F_254 ( V_470 ) ;
}
static int F_255 ( struct V_90 * V_91 )
{
int V_30 ;
if ( ! V_186 . V_455 ) {
F_84 ( V_91 , L_46 ) ;
} else if ( ! V_186 . V_454 ) {
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
int V_477 = 0 ;
if ( ! V_186 . V_455 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_251 ) == 0 ) {
V_477 = 1 ;
} else if ( F_86 ( V_159 , L_252 ) == 0 ) {
V_477 = 0 ;
} else
return - V_94 ;
}
return F_243 ( V_477 ) ;
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
F_182 ( V_474 ) ;
F_17 ( V_55 , L_254 ,
F_1 ( V_48 != NULL ) ) ;
V_17 = F_260 ( & V_154 -> V_60 , & V_478 ) ;
if ( V_17 )
return V_17 ;
return ( V_48 ) ? 0 : 1 ;
}
static void F_261 ( void )
{
F_262 ( & V_154 -> V_60 , & V_478 ) ;
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
static inline bool F_265 ( const unsigned int V_479 )
{
#ifdef F_266
return false ;
#else
return ( 1U & ( V_480 >> V_479 ) ) == 0 ;
#endif
}
static int F_267 ( const unsigned int V_479 )
{
int V_30 ;
enum V_481 V_482 ;
switch ( V_483 ) {
case V_484 :
if ( ! F_7 ( V_451 ,
& V_30 , L_257 , L_7 , 1 << V_479 ) )
return - V_50 ;
V_482 = ( V_30 == 0 ) ?
V_463 :
( ( V_30 == 1 ) ?
V_469 :
V_485 ) ;
V_486 [ V_479 ] = V_482 ;
return V_482 ;
default:
return - V_49 ;
}
}
static int F_268 ( const unsigned int V_479 ,
const enum V_481 V_487 )
{
static const unsigned int V_488 [] = { 0 , 1 , 3 } ;
static const unsigned int V_489 [] = { 0 , 0x80 , 0xc0 } ;
int V_73 = 0 ;
switch ( V_483 ) {
case V_484 :
if ( F_142 ( V_479 > 7 ) )
return - V_94 ;
if ( F_142 ( F_265 ( V_479 ) ) )
return - V_158 ;
if ( ! F_7 ( V_490 , NULL , NULL , L_8 ,
( 1 << V_479 ) , V_488 [ V_487 ] ) )
V_73 = - V_50 ;
break;
case V_491 :
if ( F_142 ( V_479 > 7 ) )
return - V_94 ;
if ( F_142 ( F_265 ( V_479 ) ) )
return - V_158 ;
V_73 = F_14 ( V_492 , ( 1 << V_479 ) ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_493 ,
( V_487 == V_485 ) << V_479 ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_494 ,
( V_487 != V_463 ) << V_479 ) ;
break;
case V_495 :
if ( F_142 ( V_479 >= V_496 ) )
return - V_94 ;
if ( F_142 ( F_265 ( V_479 ) ) )
return - V_158 ;
if ( ! F_7 ( V_490 , NULL , NULL , L_8 ,
V_479 , V_489 [ V_487 ] ) )
V_73 = - V_50 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
V_486 [ V_479 ] = V_487 ;
return V_73 ;
}
static void F_269 ( struct V_459 * V_460 )
{
struct V_461 * V_66 =
F_245 ( V_460 , struct V_461 , V_460 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_268 ( V_66 -> V_479 , V_66 -> V_462 ) ;
}
static void F_270 ( struct V_464 * V_465 ,
enum V_466 V_467 )
{
struct V_461 * V_66 = F_245 ( V_465 ,
struct V_461 , V_464 ) ;
if ( V_467 == V_468 )
V_66 -> V_462 = V_463 ;
else if ( V_486 [ V_66 -> V_479 ] != V_485 )
V_66 -> V_462 = V_469 ;
else
V_66 -> V_462 = V_485 ;
F_247 ( V_470 , & V_66 -> V_460 ) ;
}
static int F_271 ( struct V_464 * V_465 ,
unsigned long * V_497 , unsigned long * V_498 )
{
struct V_461 * V_66 = F_245 ( V_465 ,
struct V_461 , V_464 ) ;
if ( * V_497 == 0 && * V_498 == 0 ) {
* V_497 = 500 ;
* V_498 = 500 ;
} else if ( ( * V_497 != 500 ) || ( * V_498 != 500 ) )
return - V_94 ;
V_66 -> V_462 = V_485 ;
F_247 ( V_470 , & V_66 -> V_460 ) ;
return 0 ;
}
static enum V_466 F_272 ( struct V_464 * V_465 )
{
int V_73 ;
struct V_461 * V_66 = F_245 ( V_465 ,
struct V_461 , V_464 ) ;
V_73 = F_267 ( V_66 -> V_479 ) ;
if ( V_73 == V_463 || V_73 < 0 )
V_73 = V_468 ;
else
V_73 = V_471 ;
return V_73 ;
}
static void F_273 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_496 ; V_42 ++ ) {
if ( V_499 [ V_42 ] . V_464 . V_51 )
F_253 ( & V_499 [ V_42 ] . V_464 ) ;
}
F_254 ( V_470 ) ;
F_37 ( V_499 ) ;
}
static int T_1 F_274 ( unsigned int V_479 )
{
int V_73 ;
V_499 [ V_479 ] . V_479 = V_479 ;
if ( ! V_500 [ V_479 ] )
return 0 ;
V_499 [ V_479 ] . V_464 . V_501 = & F_270 ;
V_499 [ V_479 ] . V_464 . V_502 = & F_271 ;
if ( V_483 == V_484 )
V_499 [ V_479 ] . V_464 . V_503 =
& F_272 ;
V_499 [ V_479 ] . V_464 . V_51 = V_500 [ V_479 ] ;
F_250 ( & V_499 [ V_479 ] . V_460 , F_269 ) ;
V_73 = F_251 ( & V_154 -> V_60 ,
& V_499 [ V_479 ] . V_464 ) ;
if ( V_73 < 0 )
V_499 [ V_479 ] . V_464 . V_51 = NULL ;
return V_73 ;
}
static enum V_504 T_1 F_275 ( void )
{
T_4 V_30 ;
if ( F_6 () ) {
V_30 = F_18 ( V_451 , L_258 , & V_490 ) ;
if ( F_19 ( V_30 ) )
return V_484 ;
V_30 = F_18 ( V_451 , L_259 , & V_490 ) ;
if ( F_19 ( V_30 ) )
return V_491 ;
}
V_30 = F_18 ( V_451 , L_260 , & V_490 ) ;
if ( F_19 ( V_30 ) )
return V_495 ;
V_490 = NULL ;
return V_505 ;
}
static int T_1 F_276 ( struct V_306 * V_307 )
{
unsigned int V_42 ;
int V_73 ;
unsigned long V_506 ;
F_17 ( V_55 , L_261 ) ;
V_483 = F_275 () ;
if ( V_483 != V_505 ) {
V_506 = F_4 ( V_507 ,
F_100 ( V_507 ) ) ;
if ( ! V_506 ) {
V_490 = NULL ;
V_483 = V_505 ;
}
}
F_17 ( V_55 , L_262 ,
F_1 ( V_483 ) , V_483 ) ;
if ( V_483 == V_505 )
return 1 ;
V_499 = F_35 ( sizeof( * V_499 ) * V_496 ,
V_83 ) ;
if ( ! V_499 ) {
F_8 ( L_263 ) ;
return - V_84 ;
}
for ( V_42 = 0 ; V_42 < V_496 ; V_42 ++ ) {
V_499 [ V_42 ] . V_479 = - 1 ;
if ( ! F_265 ( V_42 ) &&
F_277 ( V_42 , & V_506 ) ) {
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
if ( ! V_483 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
F_84 ( V_91 , L_225 ) ;
if ( V_483 == V_484 ) {
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
int V_479 , V_73 ;
enum V_481 V_118 ;
if ( ! V_483 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_269 , & V_479 ) != 1 )
return - V_94 ;
if ( V_479 < 0 || V_479 > ( V_496 - 1 ) ||
V_499 [ V_479 ] . V_479 < 0 )
return - V_75 ;
if ( strstr ( V_159 , L_252 ) ) {
V_118 = V_463 ;
} else if ( strstr ( V_159 , L_251 ) ) {
V_118 = V_469 ;
} else if ( strstr ( V_159 , L_270 ) ) {
V_118 = V_485 ;
} else {
return - V_94 ;
}
V_73 = F_268 ( V_479 , V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
static int T_1 F_281 ( struct V_306 * V_307 )
{
unsigned long V_13 ;
F_17 ( V_55 , L_271 ) ;
F_182 ( V_508 ) ;
F_17 ( V_55 , L_272 ,
F_1 ( V_509 != NULL ) ) ;
V_13 = F_4 ( V_510 ,
F_100 ( V_510 ) ) ;
V_186 . V_511 = ! ! ( V_13 & V_512 ) ;
return ( V_509 ) ? 0 : 1 ;
}
static int F_282 ( struct V_90 * V_91 )
{
if ( ! V_509 )
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
int V_513 ;
if ( ! V_509 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_256 , & V_513 ) == 1 &&
V_513 >= 0 && V_513 <= 17 ) {
} else
return - V_94 ;
if ( V_186 . V_511 ) {
if ( ! F_7 ( V_509 , NULL , NULL , L_8 ,
V_513 , 0 ) )
return - V_50 ;
} else {
if ( ! F_7 ( V_509 , NULL , NULL , L_9 ,
V_513 ) )
return - V_50 ;
}
}
return 0 ;
}
static int F_284 ( int V_514 , T_17 * V_38 )
{
int V_157 ;
T_18 V_515 ;
char V_516 [ 5 ] ;
V_157 = V_517 ;
switch ( V_518 ) {
#if V_519 >= 16
case V_520 :
if ( V_514 >= 8 && V_514 <= 15 ) {
V_157 = V_521 ;
V_514 -= 8 ;
}
#endif
case V_522 :
if ( V_514 <= 7 ) {
if ( ! F_11 ( V_157 + V_514 , & V_515 ) )
return - V_50 ;
* V_38 = V_515 * 1000 ;
return 0 ;
}
break;
case V_523 :
if ( V_514 <= 7 ) {
snprintf ( V_516 , sizeof( V_516 ) , L_274 , '0' + V_514 ) ;
if ( ! F_7 ( V_451 , NULL , L_275 , L_220 ) )
return - V_50 ;
if ( ! F_7 ( V_451 , & V_157 , V_516 , L_64 ) )
return - V_50 ;
* V_38 = ( V_157 - 2732 ) * 100 ;
return 0 ;
}
break;
case V_524 :
if ( V_514 <= 7 ) {
snprintf ( V_516 , sizeof( V_516 ) , L_274 , '0' + V_514 ) ;
if ( ! F_7 ( V_451 , & V_157 , V_516 , L_64 ) )
return - V_50 ;
if ( V_157 > 127 || V_157 < - 127 )
V_157 = V_525 ;
* V_38 = V_157 * 1000 ;
return 0 ;
}
break;
case V_526 :
default:
return - V_447 ;
}
return - V_94 ;
}
static int F_285 ( struct V_527 * V_118 )
{
int V_17 , V_42 ;
int V_217 ;
V_217 = 8 ;
V_42 = 0 ;
if ( ! V_118 )
return - V_94 ;
if ( V_518 == V_520 )
V_217 = 16 ;
for ( V_42 = 0 ; V_42 < V_217 ; V_42 ++ ) {
V_17 = F_284 ( V_42 , & V_118 -> V_528 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return V_217 ;
}
static void F_197 ( void )
{
int V_217 , V_42 ;
struct V_527 V_157 ;
V_217 = F_285 ( & V_157 ) ;
if ( V_217 <= 0 )
return;
F_32 ( L_276 ) ;
for ( V_42 = 0 ; V_42 < V_217 ; V_42 ++ ) {
if ( V_157 . V_528 [ V_42 ] != V_529 )
F_286 ( L_277 , ( int ) ( V_157 . V_528 [ V_42 ] / 1000 ) ) ;
else
F_286 ( L_278 ) ;
}
F_286 ( L_279 ) ;
}
static T_8 F_287 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
struct V_530 * V_531 =
F_288 ( V_122 ) ;
int V_514 = V_531 -> V_532 ;
T_17 V_38 ;
int V_17 ;
V_17 = F_284 ( V_514 , & V_38 ) ;
if ( V_17 )
return V_17 ;
if ( V_38 == V_529 )
return - V_49 ;
return snprintf ( V_126 , V_102 , L_44 , V_38 ) ;
}
static int T_1 F_289 ( struct V_306 * V_307 )
{
T_6 V_157 , V_533 , V_534 ;
int V_42 ;
int V_535 ;
int V_17 ;
F_17 ( V_55 , L_280 ) ;
V_535 = F_7 ( V_451 , NULL , L_281 , L_247 ) ;
if ( V_7 . V_12 ) {
V_533 = V_534 = 0 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( F_11 ( V_517 + V_42 , & V_157 ) ) {
V_533 |= V_157 ;
} else {
V_533 = 0 ;
break;
}
if ( F_11 ( V_521 + V_42 , & V_157 ) ) {
V_534 |= V_157 ;
} else {
V_533 = 0 ;
break;
}
}
if ( V_533 == 0 ) {
if ( V_535 ) {
F_8 ( L_282
L_283
L_284 ) ;
V_518 = V_524 ;
} else {
F_8 ( L_282
L_285 ) ;
V_518 = V_526 ;
}
} else {
V_518 =
( V_534 != 0 ) ?
V_520 : V_522 ;
}
} else if ( V_535 ) {
if ( F_6 () &&
F_7 ( V_451 , NULL , L_275 , L_247 ) ) {
V_518 = V_523 ;
} else {
V_518 = V_524 ;
}
} else {
V_518 = V_526 ;
}
F_17 ( V_55 , L_286 ,
F_1 ( V_518 != V_526 ) ,
V_518 ) ;
switch ( V_518 ) {
case V_520 :
V_17 = F_215 ( & V_536 -> V_60 . V_125 ,
& V_537 ) ;
if ( V_17 )
return V_17 ;
break;
case V_522 :
case V_524 :
case V_523 :
V_17 = F_215 ( & V_536 -> V_60 . V_125 ,
& V_538 ) ;
if ( V_17 )
return V_17 ;
break;
case V_526 :
default:
return 1 ;
}
return 0 ;
}
static void F_290 ( void )
{
switch ( V_518 ) {
case V_520 :
F_55 ( & V_536 -> V_60 . V_125 ,
& V_537 ) ;
break;
case V_522 :
case V_524 :
case V_523 :
F_55 ( & V_536 -> V_60 . V_125 ,
& V_538 ) ;
break;
case V_526 :
default:
break;
}
}
static int F_291 ( struct V_90 * V_91 )
{
int V_217 , V_42 ;
struct V_527 V_157 ;
V_217 = F_285 ( & V_157 ) ;
if ( F_142 ( V_217 < 0 ) )
return V_217 ;
F_84 ( V_91 , L_287 ) ;
if ( V_217 > 0 ) {
for ( V_42 = 0 ; V_42 < ( V_217 - 1 ) ; V_42 ++ )
F_84 ( V_91 , L_288 , V_157 . V_528 [ V_42 ] / 1000 ) ;
F_84 ( V_91 , L_44 , V_157 . V_528 [ V_42 ] / 1000 ) ;
} else
F_84 ( V_91 , L_289 ) ;
return 0 ;
}
static unsigned int F_292 ( void )
{
T_6 V_539 ;
V_539 = ( F_131 ( V_238 )
& V_240 )
>> V_241 ;
V_539 &= V_272 ;
return V_539 ;
}
static void F_293 ( void )
{
T_6 V_540 = 0 ;
T_6 V_541 ;
if ( V_542 != V_543 )
return;
F_17 ( V_544 ,
L_290 ) ;
if ( F_157 ( & V_545 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_546 , & V_540 ) ) )
goto V_547;
V_540 &= V_548 ;
V_541 = F_131 ( V_238 ) ;
if ( V_540 != ( ( V_541 & V_240 )
>> V_241 ) ) {
V_541 &= ~ ( V_240 <<
V_241 ) ;
V_541 |= V_540 ;
F_294 ( V_541 , V_238 ) ;
F_20 ( V_544 ,
L_291 ,
( unsigned int ) V_540 , ( unsigned int ) V_541 ) ;
} else
F_17 ( V_544 ,
L_292 ,
( unsigned int ) V_540 , ( unsigned int ) V_541 ) ;
V_547:
F_118 ( & V_545 ) ;
}
static int F_295 ( int * V_30 )
{
T_6 V_540 = 0 ;
switch ( V_542 ) {
case V_549 :
* V_30 = F_292 () ;
return 0 ;
case V_550 :
case V_543 :
if ( F_142 ( ! F_11 ( V_546 , & V_540 ) ) )
return - V_50 ;
* V_30 = V_540 ;
return 0 ;
default:
return - V_49 ;
}
}
static int F_296 ( unsigned int V_38 )
{
T_6 V_540 = 0 ;
if ( F_142 ( ! F_11 ( V_546 , & V_540 ) ) )
return - V_50 ;
if ( F_142 ( ! F_13 ( V_546 ,
( V_540 & V_551 ) |
( V_38 & V_548 ) ) ) )
return - V_50 ;
return 0 ;
}
static int F_297 ( unsigned int V_38 )
{
int V_47 , V_552 ;
unsigned int V_553 , V_42 ;
V_553 = F_292 () ;
if ( V_38 == V_553 )
return 0 ;
V_47 = ( V_38 > V_553 ) ?
V_554 :
V_555 ;
V_552 = ( V_38 > V_553 ) ? 1 : - 1 ;
for ( V_42 = V_553 ; V_42 != V_38 ; V_42 += V_552 )
if ( F_15 ( V_47 ) )
return - V_50 ;
return 0 ;
}
static int V_501 ( unsigned int V_38 )
{
int V_17 ;
if ( V_38 > V_272 )
return - V_94 ;
F_17 ( V_544 ,
L_293 , V_38 ) ;
V_17 = F_157 ( & V_545 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_542 ) {
case V_550 :
case V_543 :
V_17 = F_296 ( V_38 ) ;
break;
case V_549 :
V_17 = F_297 ( V_38 ) ;
break;
default:
V_17 = - V_49 ;
}
F_118 ( & V_545 ) ;
return V_17 ;
}
static int F_298 ( struct V_556 * V_557 )
{
unsigned int V_56 =
( V_557 -> V_558 . V_559 == V_560 &&
V_557 -> V_558 . V_561 == V_560 ) ?
V_557 -> V_558 . V_467 : 0 ;
F_20 ( V_544 ,
L_294 ,
V_56 ) ;
return V_501 ( V_56 ) ;
}
static int V_503 ( struct V_556 * V_557 )
{
int V_30 , V_17 ;
V_17 = F_157 ( & V_545 ) ;
if ( V_17 < 0 )
return 0 ;
V_17 = F_295 ( & V_30 ) ;
F_118 ( & V_545 ) ;
if ( V_17 < 0 )
return 0 ;
return V_30 & V_548 ;
}
static void F_299 ( void )
{
F_300 ( V_562 ,
V_563 ) ;
}
static int T_1 F_301 ( T_3 V_16 )
{
struct V_26 V_564 = { V_565 , NULL } ;
union V_23 * V_566 ;
struct V_59 * V_74 , * V_567 ;
int V_73 ;
if ( F_22 ( V_16 , & V_74 ) )
return 0 ;
V_73 = 0 ;
F_302 (child, &device->children, node) {
T_4 V_30 = F_9 ( V_567 -> V_16 , L_295 ,
NULL , & V_564 ) ;
if ( F_31 ( V_30 ) )
continue;
V_566 = (union V_23 * ) V_564 . V_36 ;
if ( ! V_566 || ( V_566 -> type != V_568 ) ) {
F_8 ( L_296 ,
V_346 ) ;
V_73 = 0 ;
} else {
V_73 = V_566 -> V_569 . V_35 ;
}
break;
}
F_37 ( V_564 . V_36 ) ;
return V_73 ;
}
static unsigned int T_1 F_303 ( void )
{
T_3 V_570 ;
int V_571 = 0 ;
F_24 ( L_13 , NULL , & V_570 ) ;
if ( V_570 )
V_571 = F_301 ( V_570 ) ;
V_186 . V_572 = ( V_571 > 0 ) ;
return ( V_571 > 2 ) ? ( V_571 - 2 ) : 0 ;
}
static void T_1 F_304 ( void )
{
unsigned int V_573 ;
F_17 ( V_55 ,
L_297 ) ;
V_573 = F_303 () ;
switch ( V_573 ) {
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
L_301 , V_346 ) ;
V_186 . V_273 = 1 ;
V_272 = V_573 - 1 ;
}
}
static int T_1 F_305 ( struct V_306 * V_307 )
{
struct V_574 V_558 ;
int V_573 ;
unsigned long V_13 ;
F_17 ( V_55 , L_302 ) ;
F_183 ( & V_545 ) ;
V_13 = F_4 ( V_575 ,
F_100 ( V_575 ) ) ;
if ( V_186 . V_273 )
return 1 ;
if ( ! V_576 ) {
F_20 ( V_55 | V_544 ,
L_303
L_304 ) ;
return 1 ;
}
if ( F_187 () ) {
if ( V_576 > 1 ) {
F_76 ( L_305
L_306 ) ;
return 1 ;
} else if ( V_576 == 1 ) {
F_62 ( L_307
L_308
L_309 ) ;
return 1 ;
}
} else if ( V_186 . V_572 && V_576 > 1 ) {
F_32 ( L_310
L_311
L_312 ) ;
}
if ( V_542 > V_577 )
return - V_94 ;
if ( V_542 == V_578 ||
V_542 == V_577 ) {
if ( V_13 & V_579 )
V_542 = V_543 ;
else
V_542 = V_549 ;
F_20 ( V_544 ,
L_313 ,
V_542 ) ;
}
if ( ! F_6 () &&
( V_542 == V_543 ||
V_542 == V_550 ) )
return - V_94 ;
if ( F_295 ( & V_573 ) < 0 )
return 1 ;
memset ( & V_558 , 0 , sizeof( struct V_574 ) ) ;
V_558 . type = V_580 ;
V_558 . V_581 = V_272 ;
V_558 . V_467 = V_573 & V_548 ;
V_562 = F_306 ( V_582 ,
NULL , NULL ,
& V_583 ,
& V_558 ) ;
if ( F_147 ( V_562 ) ) {
int V_73 = F_307 ( V_562 ) ;
V_562 = NULL ;
F_8 ( L_314 ) ;
return V_73 ;
}
F_17 ( V_55 | V_544 ,
L_315 ) ;
if ( V_13 & V_584 ) {
F_32 ( L_316
L_317 , V_542 ) ;
F_32 ( L_318
L_319 , V_346 ) ;
}
F_308 ( V_562 ) ;
F_17 ( V_55 | V_544 ,
L_320
L_321 ) ;
F_114 ( V_195
| V_585
| V_586 ) ;
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
if ( V_562 ) {
F_17 ( V_303 | V_544 ,
L_322 ) ;
F_312 ( V_562 ) ;
}
F_293 () ;
}
static int F_313 ( struct V_90 * V_91 )
{
int V_56 ;
V_56 = V_503 ( NULL ) ;
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
V_56 = V_503 ( NULL ) ;
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
V_73 = V_501 ( V_56 ) ;
if ( ! V_73 && V_562 )
F_300 ( V_562 ,
V_587 ) ;
return ( V_73 == - V_588 ) ? - V_294 : V_73 ;
}
static void F_315 ( void )
{
T_6 V_540 = 0 ;
T_6 V_541 ;
T_6 V_589 ;
if ( V_590 != V_591 )
return;
if ( ! V_592 )
return;
if ( V_593 )
return;
F_17 ( V_594 ,
L_332 ) ;
if ( V_186 . V_595 )
V_589 = V_596 ;
else
V_589 = V_596 | V_597 ;
if ( F_157 ( & V_598 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_599 , & V_540 ) ) )
goto V_547;
V_540 &= V_589 ;
V_541 = F_131 ( V_245 ) ;
if ( V_540 != ( V_541 & V_589 ) ) {
V_541 &= ~ V_589 ;
V_541 |= V_540 ;
F_294 ( V_541 , V_245 ) ;
F_20 ( V_594 ,
L_333 ,
( unsigned int ) V_540 , ( unsigned int ) V_541 ) ;
} else {
F_17 ( V_594 ,
L_334 ,
( unsigned int ) V_540 , ( unsigned int ) V_541 ) ;
}
V_547:
F_118 ( & V_598 ) ;
}
static int F_316 ( T_6 * V_30 )
{
T_6 V_118 ;
if ( ! F_11 ( V_599 , & V_118 ) )
return - V_50 ;
* V_30 = V_118 ;
F_20 ( V_594 , L_335 , V_118 ) ;
return 0 ;
}
static int F_317 ( T_6 * V_30 )
{
return F_316 ( V_30 ) ;
}
static int F_318 ( const T_6 V_30 )
{
if ( ! F_13 ( V_599 , V_30 ) )
return - V_50 ;
F_20 ( V_594 , L_336 , V_30 ) ;
F_319 ( 1 ) ;
return 0 ;
}
static int F_320 ( const T_6 V_30 )
{
return F_318 ( V_30 ) ;
}
static int F_321 ( const bool V_249 )
{
int V_73 ;
T_6 V_118 , V_217 ;
if ( F_157 ( & V_598 ) < 0 )
return - V_588 ;
V_73 = F_316 ( & V_118 ) ;
if ( V_73 )
goto V_547;
V_217 = ( V_249 ) ? V_118 | V_596 :
V_118 & ~ V_596 ;
if ( V_217 != V_118 ) {
V_73 = F_318 ( V_217 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_547:
F_118 ( & V_598 ) ;
return V_73 ;
}
static int F_322 ( const bool V_249 )
{
F_20 ( V_594 , L_337 ,
( V_249 ) ? L_1 : L_42 ) ;
return F_321 ( V_249 ) ;
}
static int F_323 ( const bool V_249 )
{
int V_73 ;
F_20 ( V_594 , L_338 ,
( V_249 ) ? L_1 : L_42 ) ;
V_73 = F_321 ( V_249 ) ;
return ( V_73 < 0 ) ? V_73 : 0 ;
}
static int F_324 ( const T_6 V_600 )
{
int V_73 ;
T_6 V_118 , V_217 ;
if ( V_600 > V_601 )
return - V_94 ;
if ( F_157 ( & V_598 ) < 0 )
return - V_588 ;
V_73 = F_316 ( & V_118 ) ;
if ( V_73 )
goto V_547;
V_217 = ( V_118 & ~ V_597 ) | V_600 ;
if ( V_217 != V_118 ) {
V_73 = F_318 ( V_217 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_547:
F_118 ( & V_598 ) ;
return V_73 ;
}
static int F_325 ( bool V_602 )
{
int V_27 ;
if ( ! F_5 () )
return - V_75 ;
if ( V_602 ) {
if ( ! F_7 ( V_451 , & V_603 ,
L_339 , L_107 ) )
return - V_50 ;
F_20 ( V_55 | V_594 ,
L_340 ,
V_603 ) ;
}
if ( ! F_7 ( V_451 , & V_27 , L_341 , L_342 ,
( int ) V_604 ) )
return - V_50 ;
if ( V_27 != V_604 )
F_62 ( L_343 ,
V_27 ) ;
if ( V_186 . V_595 )
V_27 = F_323 ( false ) ;
else
V_27 = F_320 ( V_601 ) ;
if ( V_27 != 0 )
F_62 ( L_344 ) ;
return 0 ;
}
static void F_326 ( void )
{
int V_605 ;
if ( ! F_7 ( V_451 , & V_605 , L_341 , L_342 , V_603 )
|| V_605 != V_603 )
F_62 ( L_345 ) ;
}
static int F_327 ( const T_6 V_600 )
{
F_20 ( V_594 ,
L_346 , V_600 ) ;
return F_324 ( V_600 ) ;
}
static void F_328 ( void )
{
struct V_606 * V_218 ;
if ( V_607 && V_607 -> V_608 ) {
V_218 = V_607 -> V_608 ;
if ( V_218 -> V_609 )
F_329 ( V_607 ,
V_610 ,
V_218 -> V_609 ) ;
if ( V_218 -> V_611 )
F_329 ( V_607 ,
V_610 ,
V_218 -> V_611 ) ;
}
}
static int F_330 ( struct V_612 * V_613 ,
struct V_614 * V_615 )
{
V_615 -> type = V_616 ;
V_615 -> V_35 = 1 ;
V_615 -> V_38 . integer . V_617 = 0 ;
V_615 -> V_38 . integer . V_127 = V_601 ;
return 0 ;
}
static int F_331 ( struct V_612 * V_613 ,
struct V_618 * V_619 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_317 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_619 -> V_38 . integer . V_38 [ 0 ] = V_118 & V_597 ;
return 0 ;
}
static int F_332 ( struct V_612 * V_613 ,
struct V_618 * V_619 )
{
F_82 ( L_347 , L_348 ,
V_619 -> V_38 . integer . V_38 [ 0 ] ) ;
return F_327 ( V_619 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static int F_333 ( struct V_612 * V_613 ,
struct V_618 * V_619 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_317 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_619 -> V_38 . integer . V_38 [ 0 ] =
( V_118 & V_596 ) ? 0 : 1 ;
return 0 ;
}
static int F_334 ( struct V_612 * V_613 ,
struct V_618 * V_619 )
{
F_82 ( L_347 , L_349 ,
V_619 -> V_38 . integer . V_38 [ 0 ] ?
L_42 : L_1 ) ;
return F_322 ( ! V_619 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static void F_335 ( void )
{
F_315 () ;
}
static void F_336 ( void )
{
if ( V_593 ) {
if ( F_325 ( false ) < 0 )
F_62 ( L_350 ) ;
} else {
F_328 () ;
}
}
static void F_337 ( void )
{
F_315 () ;
}
static void F_338 ( void )
{
if ( V_607 ) {
F_339 ( V_607 ) ;
V_607 = NULL ;
}
F_315 () ;
if ( V_593 )
F_326 () ;
}
static int T_1 F_340 ( void )
{
struct V_620 * V_621 ;
struct V_606 * V_66 ;
struct V_612 * V_622 ;
struct V_612 * V_623 ;
int V_73 ;
V_73 = F_341 ( & V_154 -> V_60 ,
V_624 , V_625 , V_626 ,
sizeof( struct V_606 ) , & V_621 ) ;
if ( V_73 < 0 || ! V_621 ) {
F_8 ( L_351 , V_73 ) ;
return 1 ;
}
F_25 ( ! V_621 -> V_608 ) ;
V_66 = V_621 -> V_608 ;
V_66 -> V_621 = V_621 ;
F_342 ( V_621 -> V_81 , V_627 ,
sizeof( V_621 -> V_81 ) ) ;
F_342 ( V_621 -> V_628 , V_629 ,
sizeof( V_621 -> V_628 ) ) ;
snprintf ( V_621 -> V_630 , sizeof( V_621 -> V_630 ) , L_352 ,
( V_7 . V_631 ) ?
V_7 . V_631 : L_353 ) ;
snprintf ( V_621 -> V_632 , sizeof( V_621 -> V_632 ) ,
L_354 , V_621 -> V_628 , V_599 ,
( V_7 . V_631 ) ?
V_7 . V_631 : L_355 ) ;
if ( V_592 ) {
V_633 . V_634 = F_332 ;
V_633 . V_635 =
V_636 ;
V_637 . V_634 = F_334 ;
V_637 . V_635 =
V_636 ;
}
if ( ! V_186 . V_595 ) {
V_622 = F_343 ( & V_633 , NULL ) ;
V_73 = F_344 ( V_621 , V_622 ) ;
if ( V_73 < 0 ) {
F_8 ( L_356 ,
V_73 ) ;
goto V_345;
}
V_66 -> V_611 = & V_622 -> V_144 ;
}
V_623 = F_343 ( & V_637 , NULL ) ;
V_73 = F_344 ( V_621 , V_623 ) ;
if ( V_73 < 0 ) {
F_8 ( L_357 , V_73 ) ;
goto V_345;
}
V_66 -> V_609 = & V_623 -> V_144 ;
V_73 = F_345 ( V_621 ) ;
if ( V_73 < 0 ) {
F_8 ( L_358 , V_73 ) ;
goto V_345;
}
V_607 = V_621 ;
return 0 ;
V_345:
F_339 ( V_621 ) ;
return 1 ;
}
static int T_1 F_346 ( struct V_306 * V_307 )
{
unsigned long V_13 ;
int V_73 ;
F_17 ( V_55 , L_359 ) ;
F_183 ( & V_598 ) ;
if ( V_590 > V_638 )
return - V_94 ;
if ( V_590 == V_639 ) {
F_8 ( L_360
L_301 , V_346 ) ;
return 1 ;
}
if ( V_640 >= V_641 )
return - V_94 ;
if ( ! V_642 ) {
F_17 ( V_55 | V_594 ,
L_361
L_362 ) ;
return 1 ;
}
V_13 = F_4 ( V_643 ,
F_100 ( V_643 ) ) ;
switch ( V_640 ) {
case V_644 :
if ( V_13 & V_645 )
V_186 . V_595 = 1 ;
else if ( V_13 & V_646 )
V_186 . V_595 = 0 ;
else
return 1 ;
break;
case V_647 :
V_186 . V_595 = 0 ;
break;
case V_648 :
V_186 . V_595 = 1 ;
break;
default:
return 1 ;
}
if ( V_640 != V_644 )
F_20 ( V_55 | V_594 ,
L_363 ,
V_640 ) ;
if ( V_590 == V_649 ||
V_590 == V_638 ) {
V_590 = V_591 ;
F_20 ( V_55 | V_594 ,
L_364 ,
V_590 ) ;
} else {
F_20 ( V_55 | V_594 ,
L_365 ,
V_590 ) ;
}
F_17 ( V_55 | V_594 ,
L_366 ,
F_1 ( ! V_186 . V_595 ) ) ;
if ( V_650 && F_325 ( true ) == 0 ) {
V_593 = true ;
} else {
V_73 = F_340 () ;
if ( V_73 ) {
F_8 ( L_367 ) ;
return V_73 ;
}
F_76 ( L_368 ,
( V_592 ) ?
L_369 :
L_370 ) ;
}
F_17 ( V_55 | V_594 ,
L_371 ) ;
F_114 ( V_195
| V_651
| V_652
| V_653 ) ;
return 0 ;
}
static int F_347 ( struct V_90 * V_91 )
{
T_6 V_30 ;
if ( F_317 ( & V_30 ) < 0 ) {
F_84 ( V_91 , L_323 ) ;
} else {
if ( V_186 . V_595 )
F_84 ( V_91 , L_372 ) ;
else
F_84 ( V_91 , L_324 ,
V_30 & V_597 ) ;
F_84 ( V_91 , L_373 ,
F_256 ( V_30 , V_654 ) ) ;
if ( V_592 ) {
F_84 ( V_91 , L_374 ) ;
if ( ! V_186 . V_595 ) {
F_84 ( V_91 ,
L_325 ) ;
F_84 ( V_91 ,
L_375
L_376 ,
V_601 ) ;
}
}
}
return 0 ;
}
static int F_348 ( char * V_126 )
{
T_6 V_118 ;
T_6 V_655 , V_656 ;
int V_657 ;
char * V_159 ;
int V_73 ;
if ( ! V_592 && V_69 != V_292 ) {
if ( F_142 ( ! V_200 . V_658 ) ) {
V_200 . V_658 = 1 ;
F_32 ( L_377
L_378 ) ;
F_32 ( L_379
L_380 ) ;
}
return - V_158 ;
}
V_73 = F_317 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_655 = V_118 & V_597 ;
V_656 = V_118 & V_596 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! V_186 . V_595 ) {
if ( F_86 ( V_159 , L_327 ) == 0 ) {
if ( V_656 )
V_656 = 0 ;
else if ( V_655 < V_601 )
V_655 ++ ;
continue;
} else if ( F_86 ( V_159 , L_328 ) == 0 ) {
if ( V_656 )
V_656 = 0 ;
else if ( V_655 > 0 )
V_655 -- ;
continue;
} else if ( sscanf ( V_159 , L_381 , & V_657 ) == 1 &&
V_657 >= 0 && V_657 <= V_601 ) {
V_655 = V_657 ;
continue;
}
}
if ( F_86 ( V_159 , L_382 ) == 0 )
V_656 = V_596 ;
else if ( F_86 ( V_159 , L_383 ) == 0 )
V_656 = 0 ;
else
return - V_94 ;
}
if ( V_186 . V_595 ) {
F_82 ( L_384 , L_349 ,
V_656 ? L_1 : L_42 ) ;
V_73 = F_323 ( ! ! V_656 ) ;
} else {
F_82 ( L_384 ,
L_385 ,
V_656 ? L_1 : L_42 , V_655 ) ;
V_73 = F_320 ( V_656 | V_655 ) ;
}
F_328 () ;
return ( V_73 == - V_588 ) ? - V_294 : V_73 ;
}
static void inline F_328 ( void )
{
}
static int T_1 F_346 ( struct V_306 * V_307 )
{
F_76 ( L_386 ) ;
return 1 ;
}
static void F_349 ( void )
{
if ( V_659 == 0x07 ) {
F_32 ( L_387
L_388 ) ;
V_186 . V_660 = 1 ;
}
}
static void F_350 ( T_6 * V_661 )
{
if ( F_142 ( V_186 . V_660 ) ) {
if ( * V_661 != V_659 ) {
V_186 . V_660 = 0 ;
} else {
* V_661 = V_662 ;
}
}
}
static bool F_351 ( void )
{
if ( V_186 . V_663 ) {
T_6 V_664 ;
if ( F_12 ( V_665 , & V_664 ) < 0 )
return false ;
V_664 &= 0xFEU ;
if ( F_14 ( V_665 , V_664 ) < 0 )
return false ;
}
return true ;
}
static bool F_352 ( void )
{
T_6 V_664 ;
if ( ! V_186 . V_663 )
return false ;
if ( F_12 ( V_665 , & V_664 ) < 0 )
return false ;
V_664 |= 0x01U ;
if ( F_14 ( V_665 , V_664 ) < 0 )
return false ;
return true ;
}
static void F_353 ( T_6 V_30 )
{
if ( ( V_30 &
( V_662 | V_666 ) ) == 0 ) {
if ( V_30 > 7 )
V_667 = 7 ;
else
V_667 = V_30 ;
}
}
static int F_354 ( T_6 * V_30 )
{
T_6 V_118 ;
switch ( V_668 ) {
case V_669 : {
int V_17 ;
if ( F_142 ( ! F_7 ( V_670 , & V_17 , NULL , L_64 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) )
* V_30 = V_17 & 0x07 ;
break;
}
case V_671 :
if ( F_142 ( ! F_11 ( V_672 , & V_118 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) ) {
* V_30 = V_118 ;
F_350 ( V_30 ) ;
}
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_355 ( T_6 * V_30 )
{
int V_73 ;
T_6 V_118 ;
if ( F_157 ( & V_673 ) )
return - V_294 ;
V_73 = F_354 ( & V_118 ) ;
if ( ! V_73 )
F_353 ( V_118 ) ;
F_118 ( & V_673 ) ;
if ( V_30 )
* V_30 = V_118 ;
return V_73 ;
}
static int F_356 ( unsigned int * V_674 )
{
T_6 V_675 , V_676 ;
switch ( V_668 ) {
case V_671 :
if ( F_142 ( ! F_351 () ) )
return - V_50 ;
if ( F_142 ( ! F_11 ( V_677 , & V_676 ) ||
! F_11 ( V_677 + 1 , & V_675 ) ) )
return - V_50 ;
if ( F_140 ( V_674 ) )
* V_674 = ( V_675 << 8 ) | V_676 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_357 ( unsigned int * V_674 )
{
T_6 V_675 , V_676 ;
bool V_73 ;
switch ( V_668 ) {
case V_671 :
if ( F_142 ( ! F_352 () ) )
return - V_50 ;
V_73 = ! F_11 ( V_677 , & V_676 ) ||
! F_11 ( V_677 + 1 , & V_675 ) ;
F_351 () ;
if ( V_73 )
return - V_50 ;
if ( F_140 ( V_674 ) )
* V_674 = ( V_675 << 8 ) | V_676 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_358 ( int V_56 )
{
if ( ! V_678 )
return - V_158 ;
switch ( V_679 ) {
case V_680 :
if ( V_56 >= 0 && V_56 <= 7 ) {
if ( ! F_7 ( V_681 , NULL , NULL , L_9 , V_56 ) )
return - V_50 ;
} else
return - V_94 ;
break;
case V_682 :
case V_683 :
if ( ! ( V_56 & V_662 ) &&
! ( V_56 & V_666 ) &&
( ( V_56 < 0 ) || ( V_56 > 7 ) ) )
return - V_94 ;
if ( V_56 & V_666 )
V_56 |= 7 ;
else if ( V_56 & V_662 )
V_56 |= 4 ;
if ( ! F_13 ( V_672 , V_56 ) )
return - V_50 ;
else
V_186 . V_660 = 0 ;
break;
default:
return - V_49 ;
}
F_17 ( V_684 ,
L_389 , V_56 ) ;
return 0 ;
}
static int F_359 ( int V_56 )
{
int V_73 ;
if ( ! V_678 )
return - V_158 ;
if ( F_157 ( & V_673 ) )
return - V_294 ;
if ( V_56 == V_685 )
V_56 = V_667 ;
V_73 = F_358 ( V_56 ) ;
if ( ! V_73 )
F_353 ( V_56 ) ;
F_118 ( & V_673 ) ;
return V_73 ;
}
static int F_360 ( void )
{
T_6 V_118 ;
int V_73 ;
if ( ! V_678 )
return - V_158 ;
if ( F_157 ( & V_673 ) )
return - V_294 ;
switch ( V_679 ) {
case V_682 :
case V_683 :
V_73 = F_354 ( & V_118 ) ;
if ( V_73 < 0 )
break;
if ( V_118 != 7 ) {
V_118 &= 0x07 ;
V_118 |= V_662 | 4 ;
}
if ( ! F_13 ( V_672 , V_118 ) )
V_73 = - V_50 ;
else {
V_186 . V_660 = 0 ;
V_73 = 0 ;
}
break;
case V_680 :
V_73 = F_354 ( & V_118 ) ;
if ( V_73 < 0 )
break;
V_118 &= 0x07 ;
V_118 |= 4 ;
if ( ! F_7 ( V_681 , NULL , NULL , L_9 , V_118 ) )
V_73 = - V_50 ;
else
V_73 = 0 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_673 ) ;
if ( ! V_73 )
F_17 ( V_684 ,
L_389 ,
V_118 ) ;
return V_73 ;
}
static int F_361 ( void )
{
int V_73 ;
if ( ! V_678 )
return - V_158 ;
if ( F_157 ( & V_673 ) )
return - V_294 ;
V_73 = 0 ;
switch ( V_679 ) {
case V_682 :
case V_683 :
if ( ! F_13 ( V_672 , 0x00 ) )
V_73 = - V_50 ;
else {
V_667 = 0 ;
V_186 . V_660 = 0 ;
}
break;
case V_680 :
if ( ! F_7 ( V_681 , NULL , NULL , L_9 , 0x00 ) )
V_73 = - V_50 ;
else
V_667 = 0 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
F_17 ( V_684 ,
L_390 ) ;
F_118 ( & V_673 ) ;
return V_73 ;
}
static int F_362 ( int V_674 )
{
int V_73 ;
if ( ! V_678 )
return - V_158 ;
if ( F_157 ( & V_673 ) )
return - V_294 ;
V_73 = 0 ;
switch ( V_679 ) {
case V_682 :
if ( V_674 >= 0 && V_674 <= 65535 ) {
if ( ! F_7 ( V_686 , NULL , NULL , L_391 ,
V_674 , V_674 , V_674 ) )
V_73 = - V_50 ;
} else
V_73 = - V_94 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_673 ) ;
return V_73 ;
}
static void F_363 ( void )
{
if ( V_679 == V_687 )
return;
if ( V_688 > 0 &&
V_69 != V_199 )
F_364 ( V_470 , & V_689 ,
F_365 ( V_688 * 1000 ) ) ;
else
F_366 ( & V_689 ) ;
}
static void F_367 ( struct V_459 * V_690 )
{
int V_73 ;
if ( V_69 != V_70 )
return;
F_32 ( L_392 ) ;
V_73 = F_360 () ;
if ( V_73 < 0 ) {
F_8 ( L_393
L_394 , - V_73 ) ;
F_363 () ;
}
}
static T_8 F_368 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_356 ;
T_6 V_30 ;
V_17 = F_355 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 & V_666 ) {
V_356 = 0 ;
} else if ( V_30 & V_662 ) {
V_356 = 2 ;
} else
V_356 = 1 ;
return snprintf ( V_126 , V_102 , L_44 , V_356 ) ;
}
static T_8 F_369 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 , V_56 ;
if ( F_57 ( V_126 , 2 , & V_157 ) )
return - V_94 ;
F_82 ( L_395 ,
L_396 , V_157 ) ;
switch ( V_157 ) {
case 0 :
V_56 = V_666 ;
break;
case 1 :
V_56 = V_685 ;
break;
case 2 :
V_56 = V_662 ;
break;
case 3 :
return - V_447 ;
default:
return - V_94 ;
}
V_17 = F_359 ( V_56 ) ;
if ( V_17 == - V_49 )
return - V_94 ;
else if ( V_17 < 0 )
return V_17 ;
F_363 () ;
return V_35 ;
}
static T_8 F_370 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
T_6 V_30 ;
V_17 = F_355 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_30 &
( V_662 | V_666 ) ) != 0 )
V_30 = V_667 ;
if ( V_30 > 7 )
V_30 = 7 ;
return snprintf ( V_126 , V_102 , L_397 , ( V_30 * 255 ) / 7 ) ;
}
static T_8 F_371 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_118 ;
int V_73 ;
T_6 V_30 , V_691 ;
if ( F_57 ( V_126 , 255 , & V_118 ) )
return - V_94 ;
F_82 ( L_398 ,
L_399 , V_118 ) ;
V_691 = ( V_118 >> 5 ) & 0x07 ;
if ( F_157 ( & V_673 ) )
return - V_294 ;
V_73 = F_354 ( & V_30 ) ;
if ( ! V_73 && ( V_30 &
( V_662 | V_666 ) ) == 0 ) {
V_73 = F_358 ( V_691 ) ;
if ( V_73 == - V_49 )
V_73 = - V_94 ;
else if ( ! V_73 ) {
F_353 ( V_691 ) ;
F_363 () ;
}
}
F_118 ( & V_673 ) ;
return ( V_73 ) ? V_73 : V_35 ;
}
static T_8 F_372 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_674 ;
V_17 = F_356 ( & V_674 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_397 , V_674 ) ;
}
static T_8 F_373 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_674 ;
V_17 = F_357 ( & V_674 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_397 , V_674 ) ;
}
static T_8 F_374 ( struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_397 , V_688 ) ;
}
static T_8 F_375 ( struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 120 , & V_157 ) )
return - V_94 ;
if ( ! V_678 )
return - V_158 ;
V_688 = V_157 ;
F_363 () ;
F_82 ( L_400 , L_96 , V_157 ) ;
return V_35 ;
}
static int T_1 F_376 ( struct V_306 * V_307 )
{
int V_73 ;
unsigned long V_13 ;
F_17 ( V_55 | V_684 ,
L_401 ) ;
F_183 ( & V_673 ) ;
V_668 = V_692 ;
V_679 = V_687 ;
V_693 = 0 ;
V_688 = 0 ;
V_186 . V_660 = 0 ;
V_186 . V_663 = 0 ;
V_667 = 7 ;
if ( F_6 () ) {
F_182 ( V_694 ) ;
F_182 ( V_695 ) ;
F_182 ( V_696 ) ;
}
V_13 = F_4 ( V_697 ,
F_100 ( V_697 ) ) ;
if ( V_670 ) {
V_668 = V_669 ;
} else {
if ( F_140 ( F_11 ( V_672 ,
& V_659 ) ) ) {
V_668 = V_671 ;
if ( V_13 & V_698 )
F_349 () ;
if ( V_13 & V_699 ) {
V_186 . V_663 = 1 ;
F_20 ( V_55 | V_684 ,
L_402 ) ;
}
} else {
F_8 ( L_282
L_403 ) ;
return 1 ;
}
}
if ( V_681 ) {
V_679 = V_680 ;
V_693 |=
V_700 | V_701 ;
} else {
if ( ! V_670 ) {
if ( V_686 ) {
V_679 =
V_682 ;
V_693 |=
V_702 |
V_700 |
V_701 ;
} else {
V_679 = V_683 ;
V_693 |=
V_700 |
V_701 ;
}
}
}
F_17 ( V_55 | V_684 ,
L_404 ,
F_1 ( V_668 != V_692 ||
V_679 != V_687 ) ,
V_668 , V_679 ) ;
if ( ! V_678 ) {
V_679 = V_687 ;
V_693 = 0 ;
F_20 ( V_55 | V_684 ,
L_405 ) ;
}
if ( V_668 != V_692 )
F_355 ( NULL ) ;
if ( V_668 != V_692 ||
V_679 != V_687 ) {
if ( V_186 . V_663 ) {
V_703 [ F_100 ( V_703 ) - 2 ] =
& V_704 . V_122 ;
}
V_73 = F_215 ( & V_536 -> V_60 . V_125 ,
& V_705 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_101 ( & V_706 . V_81 ,
& V_707 ) ;
if ( V_73 < 0 ) {
F_55 ( & V_536 -> V_60 . V_125 ,
& V_705 ) ;
return V_73 ;
}
return 0 ;
} else
return 1 ;
}
static void F_377 ( void )
{
F_17 ( V_303 | V_684 ,
L_406 ) ;
F_55 ( & V_536 -> V_60 . V_125 , & V_705 ) ;
F_104 ( & V_706 . V_81 ,
& V_707 ) ;
F_366 ( & V_689 ) ;
F_254 ( V_470 ) ;
}
static void F_378 ( void )
{
int V_73 ;
if ( ! V_678 )
return;
V_708 = 0 ;
V_73 = F_355 ( & V_708 ) ;
if ( V_73 < 0 )
F_32 ( L_407
L_408 , V_73 ) ;
if ( V_186 . V_660 )
V_708 = 0 ;
}
static void F_379 ( void )
{
T_6 V_709 = 7 ;
bool V_710 = false ;
int V_73 ;
V_186 . V_660 = 0 ;
if ( ! V_678 ||
! V_708 ||
( F_355 ( & V_709 ) < 0 ) )
return;
switch ( V_679 ) {
case V_680 :
V_710 = ( V_708 > V_709 ) ;
break;
case V_682 :
case V_683 :
if ( V_708 != 7 &&
! ( V_708 & V_666 ) )
return;
else
V_710 = ! ( V_709 & V_666 ) &&
( V_709 != V_708 ) ;
break;
default:
return;
}
if ( V_710 ) {
F_32 ( L_409 ,
V_708 ) ;
V_73 = F_359 ( V_708 ) ;
if ( V_73 < 0 )
F_32 ( L_410 , V_73 ) ;
}
}
static int F_380 ( struct V_90 * V_91 )
{
int V_73 ;
T_6 V_30 ;
unsigned int V_674 = 0 ;
switch ( V_668 ) {
case V_669 :
V_73 = F_355 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47
L_324 ,
( V_30 != 0 ) ? L_48 : L_49 , V_30 ) ;
break;
case V_671 :
V_73 = F_355 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47 ,
( V_30 != 0 ) ? L_48 : L_49 ) ;
V_73 = F_356 ( & V_674 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_411 , V_674 ) ;
if ( V_30 & V_666 )
F_84 ( V_91 , L_412 ) ;
else if ( V_30 & V_662 )
F_84 ( V_91 , L_413 ) ;
else
F_84 ( V_91 , L_324 , V_30 ) ;
break;
case V_692 :
default:
F_84 ( V_91 , L_46 ) ;
}
if ( V_693 & V_700 ) {
F_84 ( V_91 , L_375 ) ;
switch ( V_679 ) {
case V_680 :
F_84 ( V_91 , L_414 ) ;
break;
default:
F_84 ( V_91 , L_415
L_416 ) ;
break;
}
}
if ( V_693 & V_701 )
F_84 ( V_91 , L_50
L_417
L_418 ) ;
if ( V_693 & V_702 )
F_84 ( V_91 , L_419
L_420 ) ;
return 0 ;
}
static int F_381 ( const char * V_159 , int * V_73 )
{
int V_56 ;
if ( F_86 ( V_159 , L_421 ) == 0 )
V_56 = V_662 ;
else if ( ( F_86 ( V_159 , L_422 ) == 0 ) |
( F_86 ( V_159 , L_423 ) == 0 ) )
V_56 = V_666 ;
else if ( sscanf ( V_159 , L_329 , & V_56 ) != 1 )
return 0 ;
* V_73 = F_359 ( V_56 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_424 ,
V_679 ) ;
else if ( ! * V_73 )
F_82 ( L_425 ,
L_331 , V_56 ) ;
return 1 ;
}
static int F_382 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_51 ) != 0 )
return 0 ;
* V_73 = F_360 () ;
if ( * V_73 == - V_49 )
F_8 ( L_426 ,
V_679 ) ;
else if ( ! * V_73 )
F_82 ( L_425 , L_427 ) ;
return 1 ;
}
static int F_383 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_52 ) != 0 )
return 0 ;
* V_73 = F_361 () ;
if ( * V_73 == - V_49 )
F_8 ( L_428 ,
V_679 ) ;
else if ( ! * V_73 )
F_82 ( L_425 , L_429 ) ;
return 1 ;
}
static int F_384 ( const char * V_159 , int * V_73 )
{
int V_674 ;
if ( sscanf ( V_159 , L_430 , & V_674 ) != 1 )
return 0 ;
* V_73 = F_362 ( V_674 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_431 ,
V_679 ) ;
else if ( ! * V_73 )
F_82 ( L_425 ,
L_432 , V_674 ) ;
return 1 ;
}
static int F_385 ( const char * V_159 , int * V_73 )
{
int V_711 ;
if ( sscanf ( V_159 , L_433 , & V_711 ) != 1 )
return 0 ;
if ( V_711 < 0 || V_711 > 120 )
* V_73 = - V_94 ;
else {
V_688 = V_711 ;
F_82 ( L_425 ,
L_434 ,
V_711 ) ;
}
return 1 ;
}
static int F_386 ( char * V_126 )
{
char * V_159 ;
int V_73 = 0 ;
while ( ! V_73 && ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! ( ( V_693 & V_700 ) &&
F_381 ( V_159 , & V_73 ) ) &&
! ( ( V_693 & V_701 ) &&
( F_382 ( V_159 , & V_73 ) ||
F_383 ( V_159 , & V_73 ) ||
F_385 ( V_159 , & V_73 ) ) ) &&
! ( ( V_693 & V_702 ) &&
F_384 ( V_159 , & V_73 ) )
)
V_73 = - V_94 ;
else if ( ! V_73 )
F_363 () ;
}
return V_73 ;
}
static int F_387 ( struct V_712 * V_157 , bool V_205 )
{
T_3 V_528 ;
int V_713 ;
if ( ! F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_528 ) ) ) {
F_62 ( L_435 , V_157 -> V_51 ) ;
return - V_50 ;
}
if ( ! F_7 ( V_129 , & V_713 , V_157 -> V_51 , L_7 ,
V_205 ? V_157 -> V_714 : V_157 -> V_715 ) )
return - V_50 ;
V_157 -> V_205 = V_205 ;
return V_205 ;
}
int F_388 ( int V_716 , bool V_717 )
{
struct V_712 * V_157 ;
if ( V_716 < 0 || V_716 >= V_718 )
return - V_94 ;
V_157 = & V_719 [ V_716 ] ;
if ( V_157 -> V_205 < 0 || V_157 -> V_205 == V_717 )
return V_157 -> V_205 ;
return F_387 ( V_157 , V_717 ) ;
}
static int F_389 ( struct V_306 * V_307 )
{
T_3 V_528 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_718 ; V_42 ++ ) {
struct V_712 * V_157 = & V_719 [ V_42 ] ;
if ( F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_528 ) ) )
F_387 ( V_157 , false ) ;
else
V_157 -> V_205 = - V_75 ;
}
return 0 ;
}
static void F_390 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_718 ; V_42 ++ )
F_388 ( V_42 , false ) ;
}
static void F_391 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_718 ; V_42 ++ ) {
struct V_712 * V_157 = & V_719 [ V_42 ] ;
if ( V_157 -> V_205 >= 0 )
F_387 ( V_157 , V_157 -> V_205 ) ;
}
}
static void F_392 ( const unsigned int V_720 )
{
if ( V_562 ) {
switch ( V_720 ) {
case V_721 :
case V_722 :
F_299 () ;
}
}
if ( V_607 ) {
switch ( V_720 ) {
case V_723 :
case V_724 :
case V_725 :
F_328 () ;
}
}
}
static void F_128 ( const unsigned int V_210 )
{
F_392 ( V_726 + V_210 ) ;
}
static T_8 F_393 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_436 , V_85 ) ;
}
static const char * T_1 F_1 ( int V_1 )
{
static char V_727 [] V_728 = L_437 ;
return ( V_1 ) ? & V_727 [ 4 ] : & V_727 [ 0 ] ;
}
static void F_394 ( struct V_67 * V_68 )
{
F_20 ( V_303 , L_438 , V_68 -> V_51 ) ;
F_395 ( & V_68 -> V_729 ) ;
if ( V_68 -> V_79 . V_80 ) {
F_20 ( V_303 ,
L_439 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_396 ( * V_68 -> V_71 -> V_16 ,
V_68 -> V_71 -> type ,
F_27 ) ;
V_68 -> V_79 . V_80 = 0 ;
}
if ( V_68 -> V_79 . V_730 ) {
F_20 ( V_303 ,
L_440 , V_68 -> V_51 ) ;
F_397 ( V_68 -> V_51 , V_731 ) ;
V_68 -> V_79 . V_730 = 0 ;
}
if ( V_68 -> V_79 . V_89 ) {
F_20 ( V_303 ,
L_441 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_398 ( V_68 -> V_71 -> V_81 ) ;
F_37 ( V_68 -> V_71 -> V_81 ) ;
V_68 -> V_71 -> V_81 = NULL ;
V_68 -> V_79 . V_89 = 0 ;
}
if ( V_68 -> V_79 . V_732 && V_68 -> exit ) {
V_68 -> exit () ;
V_68 -> V_79 . V_732 = 0 ;
}
F_20 ( V_55 , L_442 , V_68 -> V_51 ) ;
}
static int T_1 F_399 ( struct V_306 * V_307 )
{
int V_100 ;
struct V_67 * V_68 = V_307 -> V_66 ;
struct V_733 * V_734 ;
F_25 ( V_68 == NULL ) ;
F_400 ( & V_68 -> V_729 ) ;
if ( V_68 -> V_79 . V_735 && ! V_735 )
return 0 ;
F_20 ( V_55 ,
L_443 , V_68 -> V_51 ) ;
if ( V_307 -> V_736 ) {
V_100 = V_307 -> V_736 ( V_307 ) ;
if ( V_100 > 0 )
return 0 ;
if ( V_100 )
return V_100 ;
V_68 -> V_79 . V_732 = 1 ;
}
if ( V_68 -> V_71 ) {
if ( V_68 -> V_71 -> V_63 ) {
V_100 = F_34 ( V_68 ) ;
if ( V_100 )
goto V_737;
}
if ( V_68 -> V_71 -> V_72 ) {
V_100 = F_28 ( V_68 ) ;
if ( V_100 == - V_75 ) {
F_32 ( L_444 ,
V_68 -> V_51 ) ;
V_100 = 0 ;
goto V_737;
}
if ( V_100 < 0 )
goto V_737;
}
}
F_20 ( V_55 ,
L_445 , V_68 -> V_51 ) ;
if ( V_68 -> V_93 ) {
T_19 V_356 = V_307 -> V_738 ;
if ( ! V_356 )
V_356 = V_739 ;
if ( V_68 -> V_101 )
V_356 |= V_740 ;
V_734 = F_401 ( V_68 -> V_51 , V_356 , V_731 ,
& V_741 , V_68 ) ;
if ( ! V_734 ) {
F_8 ( L_446 , V_68 -> V_51 ) ;
V_100 = - V_75 ;
goto V_737;
}
V_68 -> V_79 . V_730 = 1 ;
}
F_402 ( & V_68 -> V_729 , & V_742 ) ;
return 0 ;
V_737:
F_20 ( V_55 ,
L_447 ,
V_68 -> V_51 , V_100 ) ;
F_394 ( V_68 ) ;
return ( V_100 < 0 ) ? V_100 : 0 ;
}
static bool T_2 T_1 F_403 ( const char V_37 )
{
return ( V_37 >= '0' && V_37 <= '9' ) || ( V_37 >= 'A' && V_37 <= 'Z' ) ;
}
static bool T_2 T_1 F_404 ( const char * const V_118 ,
const char V_157 )
{
return V_118 && strlen ( V_118 ) >= 8 &&
F_403 ( V_118 [ 0 ] ) &&
F_403 ( V_118 [ 1 ] ) &&
V_118 [ 2 ] == V_157 &&
( V_118 [ 3 ] == 'T' || V_118 [ 3 ] == 'N' ) &&
F_403 ( V_118 [ 4 ] ) &&
F_403 ( V_118 [ 5 ] ) ;
}
static int T_20 T_1 F_405 (
struct V_743 * V_744 )
{
const struct V_745 * V_60 = NULL ;
char V_746 [ 18 ] ;
char const * V_118 ;
if ( ! V_744 )
return - V_94 ;
memset ( V_744 , 0 , sizeof( * V_744 ) ) ;
if ( F_406 ( L_448 ) )
V_744 -> V_6 = V_15 ;
else if ( F_406 ( L_449 ) )
V_744 -> V_6 = V_14 ;
else
return 0 ;
V_118 = F_407 ( V_747 ) ;
V_744 -> V_748 = F_408 ( V_118 , V_83 ) ;
if ( V_118 && ! V_744 -> V_748 )
return - V_84 ;
if ( ! ( F_404 ( V_744 -> V_748 , 'E' ) ||
F_404 ( V_744 -> V_748 , 'C' ) ) )
return 0 ;
V_744 -> V_10 = V_744 -> V_748 [ 0 ]
| ( V_744 -> V_748 [ 1 ] << 8 ) ;
V_744 -> V_184 = ( V_744 -> V_748 [ 4 ] << 8 )
| V_744 -> V_748 [ 5 ] ;
while ( ( V_60 = F_409 ( V_749 , NULL , V_60 ) ) ) {
if ( sscanf ( V_60 -> V_51 ,
L_450 ,
V_746 ) == 1 ) {
V_746 [ sizeof( V_746 ) - 1 ] = 0 ;
V_746 [ strcspn ( V_746 , L_451 ) ] = 0 ;
V_744 -> V_631 = F_408 ( V_746 , V_83 ) ;
if ( ! V_744 -> V_631 )
return - V_84 ;
if ( F_404 ( V_746 , 'H' ) ) {
V_744 -> V_12 = V_746 [ 0 ]
| ( V_746 [ 1 ] << 8 ) ;
V_744 -> V_185 = ( V_746 [ 4 ] << 8 )
| V_746 [ 5 ] ;
} else {
F_32 ( L_452
L_453 ,
V_746 ) ;
F_32 ( L_109 ,
V_346 ) ;
}
break;
}
}
V_118 = F_407 ( V_750 ) ;
if ( V_118 && ! ( strncasecmp ( V_118 , L_454 , 8 ) && strncasecmp ( V_118 , L_455 , 6 ) ) ) {
V_744 -> V_751 = F_408 ( V_118 , V_83 ) ;
if ( ! V_744 -> V_751 )
return - V_84 ;
} else {
V_118 = F_407 ( V_752 ) ;
if ( V_118 && ! ( strncasecmp ( V_118 , L_455 , 6 ) ) ) {
V_744 -> V_751 = F_408 ( V_118 , V_83 ) ;
if ( ! V_744 -> V_751 )
return - V_84 ;
}
}
V_118 = F_407 ( V_753 ) ;
V_744 -> V_754 = F_408 ( V_118 , V_83 ) ;
if ( V_118 && ! V_744 -> V_754 )
return - V_84 ;
return 0 ;
}
static int T_1 F_410 ( void )
{
int V_755 ;
if ( V_756 )
return - V_75 ;
if ( ! F_6 () && ! F_5 () )
return - V_75 ;
V_755 = ( V_7 . V_751 != NULL ) ||
( V_7 . V_12 != 0 ) ||
F_107 () ;
F_24 ( L_456 , V_757 , & V_451 ) ;
if ( ! V_451 ) {
if ( V_755 )
F_8 ( L_457 ) ;
return - V_75 ;
}
if ( ! V_755 && ! V_758 )
return - V_75 ;
return 0 ;
}
static void T_1 F_411 ( void )
{
F_76 ( L_57 , V_165 , V_166 ) ;
F_76 ( L_436 , V_759 ) ;
F_76 ( L_458 ,
( V_7 . V_748 ) ?
V_7 . V_748 : L_355 ,
( V_7 . V_631 ) ?
V_7 . V_631 : L_355 ) ;
F_25 ( ! V_7 . V_6 ) ;
if ( V_7 . V_751 )
F_76 ( L_459 ,
( V_7 . V_6 == V_15 ) ?
L_448 : ( ( V_7 . V_6 ==
V_14 ) ?
L_455 : L_460 ) ,
V_7 . V_751 ,
( V_7 . V_754 ) ?
V_7 . V_754 : L_355 ) ;
}
static int T_1 F_412 ( const char * V_664 , struct V_760 * V_761 )
{
unsigned int V_42 ;
struct V_67 * V_68 ;
if ( ! V_761 || ! V_761 -> V_51 || ! V_664 )
return - V_94 ;
for ( V_42 = 0 ; V_42 < F_100 ( V_762 ) ; V_42 ++ ) {
V_68 = V_762 [ V_42 ] . V_66 ;
F_413 ( V_68 == NULL ) ;
if ( ! V_68 || ! V_68 -> V_51 )
continue;
if ( strcmp ( V_68 -> V_51 , V_761 -> V_51 ) == 0 && V_68 -> V_101 ) {
if ( strlen ( V_664 ) > sizeof( V_762 [ V_42 ] . V_763 ) - 2 )
return - V_764 ;
strcpy ( V_762 [ V_42 ] . V_763 , V_664 ) ;
strcat ( V_762 [ V_42 ] . V_763 , L_28 ) ;
return 0 ;
}
}
return - V_94 ;
}
static void F_414 ( void )
{
struct V_67 * V_68 , * V_107 ;
V_69 = V_199 ;
F_415 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
F_394 ( V_68 ) ;
}
F_20 ( V_55 , L_461 ) ;
if ( V_208 ) {
if ( V_186 . V_765 )
F_416 ( V_208 ) ;
else
F_417 ( V_208 ) ;
F_37 ( V_212 ) ;
}
if ( V_766 )
F_418 ( V_766 ) ;
if ( V_186 . V_767 )
F_262 ( & V_536 -> V_60 ,
& V_768 ) ;
if ( V_536 )
F_419 ( V_536 ) ;
if ( V_154 )
F_419 ( V_154 ) ;
if ( V_186 . V_769 )
F_103 ( & V_706 . V_81 ) ;
if ( V_186 . V_770 )
F_103 ( & V_771 . V_81 ) ;
if ( V_186 . V_772 )
F_420 ( & V_706 ) ;
if ( V_186 . V_773 )
F_420 ( & V_771 ) ;
if ( V_731 )
F_397 ( V_774 , V_775 ) ;
if ( V_470 )
F_421 ( V_470 ) ;
F_37 ( V_7 . V_748 ) ;
F_37 ( V_7 . V_631 ) ;
F_37 ( V_7 . V_751 ) ;
F_37 ( V_7 . V_754 ) ;
}
static int T_1 F_422 ( void )
{
int V_100 , V_42 ;
V_69 = V_292 ;
V_100 = F_405 ( & V_7 ) ;
if ( V_100 ) {
F_8 ( L_462 , V_100 ) ;
F_414 () ;
return V_100 ;
}
V_100 = F_410 () ;
if ( V_100 ) {
F_414 () ;
return V_100 ;
}
F_411 () ;
F_106 () ;
F_182 ( V_776 ) ;
F_182 ( V_777 ) ;
V_470 = F_423 ( V_778 ) ;
if ( ! V_470 ) {
F_414 () ;
return - V_84 ;
}
V_731 = F_424 ( V_774 , V_775 ) ;
if ( ! V_731 ) {
F_8 ( L_463 V_774 L_279 ) ;
F_414 () ;
return - V_75 ;
}
V_100 = F_425 ( & V_771 ) ;
if ( V_100 ) {
F_8 ( L_464 ) ;
F_414 () ;
return V_100 ;
}
V_186 . V_773 = 1 ;
V_100 = F_425 ( & V_706 ) ;
if ( V_100 ) {
F_8 ( L_465 ) ;
F_414 () ;
return V_100 ;
}
V_186 . V_772 = 1 ;
V_100 = F_99 ( & V_771 . V_81 ) ;
if ( ! V_100 ) {
V_186 . V_770 = 1 ;
V_100 = F_99 (
& V_706 . V_81 ) ;
}
if ( V_100 ) {
F_8 ( L_466 ) ;
F_414 () ;
return V_100 ;
}
V_186 . V_769 = 1 ;
V_154 = F_426 ( V_779 , - 1 ,
NULL , 0 ) ;
if ( F_147 ( V_154 ) ) {
V_100 = F_307 ( V_154 ) ;
V_154 = NULL ;
F_8 ( L_467 ) ;
F_414 () ;
return V_100 ;
}
V_536 = F_426 (
V_780 ,
- 1 , NULL , 0 ) ;
if ( F_147 ( V_536 ) ) {
V_100 = F_307 ( V_536 ) ;
V_536 = NULL ;
F_8 ( L_468 ) ;
F_414 () ;
return V_100 ;
}
V_100 = F_260 ( & V_536 -> V_60 ,
& V_768 ) ;
if ( V_100 ) {
F_8 ( L_469 ) ;
F_414 () ;
return V_100 ;
}
V_186 . V_767 = 1 ;
V_766 = F_427 ( & V_536 -> V_60 ) ;
if ( F_147 ( V_766 ) ) {
V_100 = F_307 ( V_766 ) ;
V_766 = NULL ;
F_8 ( L_470 ) ;
F_414 () ;
return V_100 ;
}
F_183 ( & V_207 ) ;
V_208 = F_428 () ;
if ( ! V_208 ) {
F_414 () ;
return - V_84 ;
} else {
V_208 -> V_51 = L_471 ;
V_208 -> V_781 = V_779 L_472 ;
V_208 -> V_144 . V_782 = V_783 ;
V_208 -> V_144 . V_6 = V_7 . V_6 ;
V_208 -> V_144 . V_784 = V_785 ;
V_208 -> V_144 . V_786 = V_787 ;
V_208 -> V_60 . V_52 = & V_154 -> V_60 ;
}
F_304 () ;
for ( V_42 = 0 ; V_42 < F_100 ( V_762 ) ; V_42 ++ ) {
V_100 = F_399 ( & V_762 [ V_42 ] ) ;
if ( V_100 >= 0 && * V_762 [ V_42 ] . V_763 )
V_100 = V_762 [ V_42 ] . V_66 -> V_101 ( V_762 [ V_42 ] . V_763 ) ;
if ( V_100 < 0 ) {
F_414 () ;
return V_100 ;
}
}
V_69 = V_70 ;
V_100 = F_429 ( V_208 ) ;
if ( V_100 < 0 ) {
F_8 ( L_473 ) ;
F_414 () ;
return V_100 ;
} else {
V_186 . V_765 = 1 ;
}
return 0 ;
}
