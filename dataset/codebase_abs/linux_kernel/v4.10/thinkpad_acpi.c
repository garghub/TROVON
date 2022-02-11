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
switch ( V_186 . V_188 ) {
case V_189 :
if ( ! F_7 ( V_129 , & V_118 , L_65 , L_64 ) )
return - V_50 ;
* V_30 = ( ( V_118 & V_190 ) != 0 ) ;
break;
case V_191 :
if ( ! F_7 ( V_192 , & V_118 , L_66 , L_64 ) )
return - V_50 ;
* V_30 = ( V_118 == V_193 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_110 ( void )
{
if ( V_186 . V_194 ) {
T_7 V_91 = 0 ;
if ( ! F_7 ( V_129 , & V_91 , L_67 , L_64 ) )
return - V_50 ;
V_195 = V_91 ;
} else {
V_195 = V_196 ;
}
V_197 &= ( V_195 | V_198 ) ;
return 0 ;
}
static void F_111 ( void )
{
const T_7 V_199 = V_200 &
~ ( V_195 | V_198 ) &
( V_196 | V_201 ) ;
if ( V_199 )
F_32 ( L_68 , V_199 ) ;
}
static int F_112 ( T_7 V_202 )
{
int V_42 ;
int V_73 = 0 ;
const T_7 V_203 = V_202 & ~ V_198 ;
if ( V_186 . V_194 ) {
for ( V_42 = 0 ; V_42 < 32 ; V_42 ++ ) {
if ( ! F_7 ( V_129 ,
NULL , L_69 , L_8 , V_42 + 1 ,
! ! ( V_202 & ( 1 << V_42 ) ) ) ) {
V_73 = - V_50 ;
break;
}
}
}
if ( ! F_110 () && ! V_73 && ( V_203 & ~ V_195 ) ) {
F_32 ( L_70
L_71 ,
V_203 , V_195 ) ;
}
if ( V_69 != V_204 )
F_111 () ;
return V_73 ;
}
static int F_113 ( const T_7 V_202 )
{
int V_73 ;
if ( ! V_205 . V_206 &&
( V_202 == 0xffff || V_202 == 0xffffff ||
V_202 == 0xffffffff ) ) {
V_205 . V_206 = 1 ;
F_32 ( L_72
L_73 , V_202 ) ;
F_32 ( L_74
L_75
L_76 ) ;
}
V_73 = F_112 ( ( V_202 | V_200 ) & ~ V_198 ) ;
V_197 = V_202 & ( V_195 | V_198 ) ;
return V_73 ;
}
static int F_114 ( const T_7 V_202 )
{
int V_73 ;
if ( ! V_186 . V_207 ) {
V_200 = V_202 ;
return 0 ;
}
F_115 ( & V_208 ) ;
T_13
V_200 = V_202 ;
#ifdef F_116
V_198 |= ( V_202 & ~ V_196 ) ;
#endif
T_14
V_73 = F_112 ( ( V_195 | V_200 ) &
~ V_198 ) ;
F_117 ( true ) ;
F_118 ( & V_208 ) ;
return V_73 ;
}
static int F_119 ( int * V_30 )
{
if ( ! F_7 ( V_129 , V_30 , L_77 , L_64 ) )
return - V_50 ;
return 0 ;
}
static int F_120 ( bool V_209 )
{
if ( ! F_7 ( V_129 , NULL , L_78 , L_9 , V_209 ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static void F_121 ( void )
{
int V_210 ;
if ( V_186 . V_188 &&
! F_109 ( & V_210 ) ) {
F_115 ( & V_211 ) ;
F_122 ( V_212 ,
V_213 , ! ! V_210 ) ;
F_123 ( V_212 ) ;
F_118 ( & V_211 ) ;
}
}
static void F_124 ( const unsigned int V_214 )
{
const unsigned int V_215 = V_216 [ V_214 ] ;
if ( V_215 != V_217 ) {
F_115 ( & V_211 ) ;
F_125 ( V_212 , V_218 , V_219 , V_214 ) ;
F_126 ( V_212 , V_215 , 1 ) ;
F_123 ( V_212 ) ;
F_125 ( V_212 , V_218 , V_219 , V_214 ) ;
F_126 ( V_212 , V_215 , 0 ) ;
F_123 ( V_212 ) ;
F_118 ( & V_211 ) ;
}
}
static void F_127 ( const unsigned int V_214 )
{
F_128 ( V_214 ) ;
if ( V_197 & ( 1 << V_214 ) )
F_124 ( V_214 ) ;
}
static void F_129 ( unsigned int V_214 )
{
F_127 ( V_214 ) ;
}
static void F_130 ( struct V_220 * V_221 , const T_7 V_91 )
{
T_6 V_222 ;
if ( V_91 & V_223 ) {
V_222 = F_131 ( V_224 ) ;
V_221 -> V_225 = ! ! ( V_222 & V_226 ) ;
V_221 -> V_227 = ! ! ( V_222 & V_228 ) ;
V_221 -> V_229 = ! ! ( V_222 & V_230 ) ;
V_221 -> V_231 = ! ! ( V_222 & V_232 ) ;
}
if ( V_91 & V_233 ) {
V_222 = F_131 ( V_234 ) ;
V_221 -> V_235 = ! ! ( V_222 & V_236 ) ;
}
if ( V_91 & V_237 ) {
V_222 = F_131 ( V_238 ) ;
V_221 -> V_239 =
! ! ( V_222 & V_240 ) ;
}
if ( V_91 & V_241 ) {
V_222 = F_131 ( V_242 ) ;
V_221 -> V_243 = ( V_222 & V_244 )
>> V_245 ;
V_221 -> V_246 =
! ! ( V_222 & V_247 ) ;
}
if ( V_91 & V_248 ) {
V_222 = F_131 ( V_249 ) ;
V_221 -> V_250 = ( V_222 & V_251 )
>> V_252 ;
V_221 -> V_253 = ! ! ( V_222 & V_254 ) ;
V_221 -> V_255 = ! ! ( V_222 & V_256 ) ;
}
}
static void F_132 ( const unsigned int V_257 ,
const unsigned int V_258 ,
const T_7 V_259 )
{
unsigned int V_42 = V_257 ;
while ( V_42 > V_258 ) {
F_133 ( V_260 ) ;
V_42 -- ;
}
while ( V_42 < V_258 ) {
F_133 ( V_261 ) ;
V_42 ++ ;
}
}
static void F_134 ( const unsigned int V_262 ,
const unsigned int V_263 ,
const T_7 V_259 )
{
unsigned int V_42 = V_262 ;
while ( V_42 > V_263 ) {
F_133 ( V_264 ) ;
V_42 -- ;
}
while ( V_42 < V_263 ) {
F_133 ( V_265 ) ;
V_42 ++ ;
}
}
static void F_135 ( struct V_220 * V_266 ,
struct V_220 * V_267 ,
const T_7 V_259 )
{
F_136 ( V_268 , V_225 ) ;
F_136 ( V_269 , V_227 ) ;
F_136 ( V_270 , V_229 ) ;
F_136 ( V_271 , V_231 ) ;
F_136 ( V_272 , V_235 ) ;
F_136 ( V_273 , V_239 ) ;
if ( V_267 -> V_253 ) {
if ( ! V_266 -> V_253 ||
V_266 -> V_255 != V_267 -> V_255 ||
V_266 -> V_250 != V_267 -> V_250 ) {
F_132 ( V_266 -> V_250 , V_267 -> V_250 ,
V_259 ) ;
F_133 ( V_274 ) ;
}
} else {
if ( V_266 -> V_253 ) {
F_133 ( V_261 ) ;
}
if ( V_266 -> V_250 != V_267 -> V_250 ) {
F_132 ( V_266 -> V_250 , V_267 -> V_250 ,
V_259 ) ;
} else if ( V_266 -> V_255 != V_267 -> V_255 ) {
if ( V_267 -> V_250 == 0 )
F_133 ( V_260 ) ;
else if ( V_267 -> V_250 >= V_275 )
F_133 ( V_261 ) ;
}
}
if ( V_266 -> V_243 != V_267 -> V_243 ) {
F_134 ( V_266 -> V_243 ,
V_267 -> V_243 , V_259 ) ;
} else if ( V_266 -> V_246 != V_267 -> V_246 ) {
if ( V_267 -> V_243 == 0 )
F_133 ( V_264 ) ;
else if ( V_267 -> V_243 >= V_276
&& ! V_186 . V_277 )
F_133 ( V_265 ) ;
}
#undef F_136
#undef F_133
}
static int F_137 ( void * V_66 )
{
struct V_220 V_118 [ 2 ] ;
T_7 V_278 , V_259 ;
unsigned int V_279 , V_280 ;
unsigned long V_157 ;
unsigned int V_281 ;
unsigned int V_282 ;
bool V_283 ;
if ( V_69 == V_204 )
goto exit;
F_138 () ;
V_280 = 0 ;
V_279 = 1 ;
V_157 = 0 ;
F_115 ( & V_284 ) ;
V_281 = V_285 ;
V_278 = V_198 ;
V_259 = V_198 &
( V_200 | V_197 ) ;
V_282 = V_286 ;
F_118 ( & V_284 ) ;
F_130 ( & V_118 [ V_280 ] , V_278 ) ;
while ( ! F_139 () ) {
if ( V_157 == 0 ) {
if ( F_140 ( V_282 ) )
V_157 = 1000 / V_282 ;
else
V_157 = 100 ;
}
V_157 = F_141 ( V_157 ) ;
if ( F_142 ( F_143 ( & V_283 ) ) )
break;
if ( V_157 > 0 && ! V_283 )
continue;
F_115 ( & V_284 ) ;
if ( V_283 || V_285 != V_281 ) {
V_279 = V_280 ;
V_157 = 0 ;
V_281 = V_285 ;
}
V_278 = V_198 ;
V_259 = V_198 &
( V_200 | V_197 ) ;
V_282 = V_286 ;
F_118 ( & V_284 ) ;
if ( F_140 ( V_278 ) ) {
F_130 ( & V_118 [ V_279 ] , V_278 ) ;
if ( F_140 ( V_279 != V_280 ) ) {
F_135 ( & V_118 [ V_280 ] , & V_118 [ V_279 ] ,
V_259 ) ;
}
}
V_280 = V_279 ;
V_279 ^= 1 ;
}
exit:
return 0 ;
}
static void F_144 ( void )
{
if ( V_287 ) {
F_145 ( V_287 ) ;
V_287 = NULL ;
}
}
static void F_117 ( const bool V_288 )
{
const T_7 V_289 = V_200 & V_198 ;
const T_7 V_290 = V_197 & V_198 ;
if ( V_286 > 0 &&
( V_289 ||
( V_290 && V_212 -> V_291 > 0 ) ) ) {
if ( ! V_287 ) {
V_287 = F_146 ( F_137 ,
NULL , V_292 ) ;
if ( F_147 ( V_287 ) ) {
V_287 = NULL ;
F_8 ( L_79
L_80 ) ;
}
}
} else {
F_144 () ;
if ( V_288 && ( V_289 || V_290 ) &&
V_286 == 0 ) {
F_32 ( L_81
L_82
L_83 ,
V_290 , V_289 ) ;
}
}
}
static void F_148 ( const bool V_288 )
{
F_115 ( & V_208 ) ;
F_117 ( V_288 ) ;
F_118 ( & V_208 ) ;
}
static void F_149 ( unsigned int V_293 )
{
if ( ! V_293 )
F_144 () ;
V_286 = V_293 ;
}
static void F_117 ( const bool V_294 )
{
}
static void F_148 ( const bool V_294 )
{
}
static int F_150 ( struct V_295 * V_60 )
{
switch ( V_69 ) {
case V_296 :
case V_70 :
F_148 ( false ) ;
return 0 ;
case V_204 :
return - V_297 ;
}
F_151 () ;
return - V_297 ;
}
static void F_152 ( struct V_295 * V_60 )
{
if ( V_69 != V_204 &&
! ( V_198 & V_200 ) )
F_148 ( false ) ;
}
static T_8 F_153 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_30 ;
F_61 ( L_84 ,
L_85 ) ;
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
F_61 ( L_84 ,
L_86 ) ;
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
return snprintf ( V_126 , V_102 , L_55 , V_197 ) ;
}
static T_8 F_156 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 ;
if ( F_57 ( V_126 , 0xffffffffUL , & V_157 ) )
return - V_94 ;
if ( F_157 ( & V_208 ) )
return - V_298 ;
V_17 = F_113 ( V_157 ) ;
#ifdef F_116
F_117 ( true ) ;
#endif
F_118 ( & V_208 ) ;
F_82 ( L_87 , L_88 , V_157 ) ;
return ( V_17 ) ? V_17 : V_35 ;
}
static T_8 F_158 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return sprintf ( V_126 , L_89 ) ;
}
static T_8 F_159 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
F_61 ( L_90 ,
L_91 ) ;
return snprintf ( V_126 , V_102 , L_55 , V_299 ) ;
}
static T_8 F_160 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 ,
V_196 | V_198 ) ;
}
static T_8 F_161 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 ,
V_300 | V_198 ) ;
}
static T_8 F_162 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 ,
( V_196 | V_198 )
& ~ V_301 ) ;
}
static T_8 F_163 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 , V_198 ) ;
}
static T_8 F_164 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
T_7 V_302 ;
int V_73 ;
if ( F_57 ( V_126 , 0xffffffffUL , & V_157 ) ||
( ( V_157 & ~ V_201 ) != 0 ) )
return - V_94 ;
if ( F_157 ( & V_208 ) )
return - V_298 ;
T_13
V_198 = V_157 ;
T_14
V_73 = F_112 ( ( V_197 | V_200 ) &
~ V_198 ) ;
F_117 ( true ) ;
V_302 = V_200 & ~ ( V_195 & V_196 )
& ~ V_198 & V_201 ;
F_118 ( & V_208 ) ;
if ( V_73 < 0 )
F_8 ( L_92
L_93 ) ;
if ( V_302 )
F_32 ( L_92
L_94 ,
V_302 ) ;
F_82 ( L_95 , L_88 , V_157 ) ;
return ( V_73 < 0 ) ? V_73 : V_35 ;
}
static T_8 F_165 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_286 ) ;
}
static T_8 F_166 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 25 , & V_157 ) )
return - V_94 ;
if ( F_157 ( & V_208 ) )
return - V_298 ;
F_149 ( V_157 ) ;
F_117 ( true ) ;
F_118 ( & V_208 ) ;
F_82 ( L_96 , L_97 , V_157 ) ;
return V_35 ;
}
static T_8 F_167 ( struct V_74 * V_60 ,
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
static void F_168 ( void )
{
if ( V_186 . V_187 )
F_169 ( & V_154 -> V_60 . V_125 , NULL ,
L_98 ) ;
}
static T_8 F_170 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_118 ;
V_17 = F_109 ( & V_118 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_44 , ! ! V_118 ) ;
}
static void F_171 ( void )
{
if ( V_186 . V_188 )
F_169 ( & V_154 -> V_60 . V_125 , NULL ,
L_99 ) ;
}
static T_8 F_172 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_303 ) ;
}
static void F_173 ( void )
{
F_169 ( & V_154 -> V_60 . V_125 , NULL ,
L_100 ) ;
}
static T_8 F_174 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_304 ) ;
}
static void F_175 ( void )
{
F_169 ( & V_154 -> V_60 . V_125 , NULL ,
L_101 ) ;
}
static T_8 F_176 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_305 ;
V_305 = F_177 () ;
if ( V_305 < 0 )
return V_305 ;
return snprintf ( V_126 , V_102 , L_44 , V_305 ) ;
}
static T_8 F_178 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 ;
if ( F_57 ( V_126 , V_306 , & V_157 ) )
return - V_94 ;
V_17 = F_179 ( V_157 ) ;
return ( V_17 < 0 ) ? V_17 : V_35 ;
}
static void F_180 ( void )
{
int V_307 ;
V_307 = F_69 () ;
if ( V_307 == V_135 )
F_66 ( true ) ;
F_65 () ;
if ( V_307 == V_142 )
F_66 ( false ) ;
if ( ! ( V_307 < 0 ) ) {
F_115 ( & V_211 ) ;
F_122 ( V_212 ,
V_308 , ( V_307 > 0 ) ) ;
F_123 ( V_212 ) ;
F_118 ( & V_211 ) ;
}
F_168 () ;
}
static void F_181 ( void )
{
#ifdef F_116
F_115 ( & V_208 ) ;
F_144 () ;
F_118 ( & V_208 ) ;
#endif
if ( V_309 )
F_54 ( V_309 , & V_154 -> V_60 . V_125 ) ;
F_20 ( V_310 | V_311 ,
L_102 ) ;
if ( ( ( V_186 . V_194 &&
F_112 ( V_299 ) ) |
F_120 ( false ) ) != 0 )
F_8 ( L_103
L_104 ) ;
}
static void T_1 F_182 ( const unsigned int V_214 )
{
if ( V_216 [ V_214 ] != V_217 ) {
F_183 ( V_216 [ V_214 ] ,
V_212 -> V_312 ) ;
V_216 [ V_214 ] = V_217 ;
}
}
static int F_184 ( void )
{
int V_313 = 0 , V_17 ;
char * type = NULL ;
if ( F_7 ( V_129 , & V_17 , L_65 , L_105 ) ) {
V_186 . V_188 = V_189 ;
V_313 = ! ! ( V_17 & V_190 ) ;
type = L_65 ;
} else if ( F_7 ( V_192 , & V_17 , L_66 , L_105 ) ) {
V_186 . V_188 = V_191 ;
V_313 = V_17 == V_193 ;
type = L_66 ;
}
if ( ! V_186 . V_188 )
return 0 ;
F_76 ( L_106 ,
type , V_313 ? L_107 : L_108 ) ;
V_17 = F_52 ( V_309 ,
& V_314 . V_122 ) ;
if ( V_17 )
return - 1 ;
return V_313 ;
}
static int T_1 F_185 ( struct V_315 * V_316 )
{
enum T_15 {
V_317 = 0 ,
V_318 ,
};
static const T_16 V_319 [] V_320 = {
[ V_317 ] = {
V_321 , V_322 , V_323 , V_324 ,
V_325 , V_326 , V_327 , V_328 ,
V_329 , V_330 , V_331 , V_332 ,
V_333 ,
V_333 ,
V_333 ,
V_217 ,
V_217 ,
V_217 ,
V_333 ,
V_334 ,
V_217 ,
V_217 ,
V_217 ,
V_335 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 ,
} ,
[ V_318 ] = {
V_321 , V_323 , V_322 , V_324 ,
V_325 , V_336 , V_327 , V_328 ,
V_329 , V_330 , V_331 , V_332 ,
V_333 ,
V_333 ,
V_333 ,
V_337 ,
V_338 ,
V_217 ,
V_333 ,
V_334 ,
V_217 ,
V_217 ,
V_217 ,
V_335 ,
V_333 , V_333 ,
V_339 ,
V_333 ,
V_340 , V_341 , V_342 , V_343 ,
V_217 ,
V_344 ,
V_217 ,
V_217 ,
V_217 ,
V_345 ,
V_217 ,
V_217 ,
V_217 ,
V_217 ,
V_217 ,
V_340 ,
V_217 ,
V_346 ,
V_347 ,
V_217 ,
V_217 ,
V_217 ,
V_217 ,
V_217 ,
} ,
} ;
static const struct V_3 V_348 [] V_320 = {
{
. V_6 = V_15 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_317 ,
} ,
{
. V_6 = V_14 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_318 ,
} ,
} ;
#define F_186 sizeof(tpacpi_keymap_t)
#define F_187 sizeof(tpacpi_keymap_entry_t)
int V_17 , V_42 ;
int V_30 ;
int V_349 ;
bool V_350 = false ;
bool V_351 = false ;
unsigned long V_13 ;
unsigned long V_352 ;
F_17 ( V_55 | V_311 ,
L_109 ) ;
F_25 ( ! V_212 ) ;
F_25 ( V_212 -> V_353 != NULL ||
V_212 -> V_354 != NULL ) ;
F_188 ( V_355 ) ;
F_189 ( & V_208 ) ;
#ifdef F_116
F_189 ( & V_284 ) ;
#endif
V_186 . V_207 = V_129 != NULL ;
F_17 ( V_55 | V_311 ,
L_110 ,
F_1 ( V_186 . V_207 ) ) ;
if ( ! V_186 . V_207 )
return 1 ;
V_13 = F_4 ( V_356 ,
F_100 ( V_356 ) ) ;
F_60 () ;
V_309 = F_51 (
F_100 ( V_357 ) + 2 ,
NULL ) ;
if ( ! V_309 )
return - V_84 ;
V_17 = F_53 ( V_309 ,
V_357 ,
F_100 ( V_357 ) ) ;
if ( V_17 )
goto V_358;
if ( F_7 ( V_129 , & V_349 , L_111 , L_105 ) ) {
F_17 ( V_55 | V_311 ,
L_112 ,
V_349 ) ;
switch ( V_349 >> 8 ) {
case 1 :
if ( ! F_7 ( V_129 , & V_196 ,
L_113 , L_105 ) ) {
F_8 ( L_114 ,
V_359 ) ;
V_196 = 0x080cU ;
} else {
V_186 . V_194 = 1 ;
}
break;
case 2 :
if ( ! F_7 ( V_129 , & V_196 ,
L_113 , L_7 , 1 ) ) {
F_8 ( L_114 ,
V_359 ) ;
V_196 = 0x080cU ;
} else {
V_186 . V_194 = 1 ;
}
if ( F_7 ( V_129 , & V_300 ,
L_113 , L_7 , 2 ) ) {
if ( V_300 != 0 ) {
V_186 . V_360 = true ;
V_17 = F_190 (
& V_154 -> V_60 . V_125 ,
& V_361 ) ;
if ( V_17 )
goto V_358;
}
} else {
V_186 . V_360 = false ;
V_300 = 0x0U ;
}
break;
default:
F_8 ( L_115 ,
V_349 ) ;
F_8 ( L_116 , V_359 ) ;
break;
}
}
F_17 ( V_55 | V_311 ,
L_117 ,
F_1 ( V_186 . V_194 ) ) ;
if ( ! V_186 . V_194 && ! V_196 &&
( V_13 & V_362 ) )
V_196 = 0x080cU ;
if ( V_186 . V_194 ) {
V_17 = F_110 () ;
if ( V_17 )
goto V_358;
V_299 = V_195 ;
} else {
V_299 = V_196 ;
V_195 = V_196 ;
}
#ifdef F_102
if ( V_172 ) {
V_186 . V_187 = 1 ;
V_350 = ! ! V_167 ;
F_76 ( L_118 ) ;
} else
#endif
if ( F_7 ( V_129 , & V_30 , L_63 , L_105 ) ) {
V_186 . V_187 = 1 ;
V_350 = ! ! V_30 ;
F_76 ( L_119 ,
F_191 ( V_30 , 0 ) ) ;
}
if ( V_186 . V_187 )
V_17 = F_52 ( V_309 ,
& V_363 . V_122 ) ;
V_17 = F_184 () ;
if ( V_17 < 0 )
goto V_358;
V_351 = V_17 ;
V_17 = F_192 ( V_309 ,
& V_154 -> V_60 . V_125 ) ;
if ( V_17 )
goto V_358;
V_216 = F_44 ( F_186 ,
V_83 ) ;
if ( ! V_216 ) {
F_8 ( L_120 ) ;
V_17 = - V_84 ;
goto V_358;
}
V_352 = F_4 ( V_348 ,
F_100 ( V_348 ) ) ;
F_25 ( V_352 >= F_100 ( V_319 ) ) ;
F_20 ( V_55 | V_311 ,
L_121 , V_352 ) ;
memcpy ( V_216 , & V_319 [ V_352 ] ,
F_186 ) ;
F_193 ( V_212 , V_218 , V_219 ) ;
V_212 -> V_364 = F_187 ;
V_212 -> V_365 = V_366 ;
V_212 -> V_215 = V_216 ;
for ( V_42 = 0 ; V_42 < V_366 ; V_42 ++ ) {
if ( V_216 [ V_42 ] != V_217 ) {
F_193 ( V_212 , V_367 ,
V_216 [ V_42 ] ) ;
} else {
if ( V_42 < sizeof( V_301 ) * 8 )
V_301 |= 1 << V_42 ;
}
}
if ( V_186 . V_187 ) {
F_193 ( V_212 , V_368 , V_308 ) ;
F_122 ( V_212 ,
V_308 , V_350 ) ;
}
if ( V_186 . V_188 ) {
F_193 ( V_212 , V_368 , V_213 ) ;
F_122 ( V_212 ,
V_213 , V_351 ) ;
}
if ( F_194 () != V_369 ) {
F_76 ( L_122
L_123
L_124 ) ;
F_32 ( L_125
L_126 ) ;
V_301 |=
( 1 << V_265 )
| ( 1 << V_264 ) ;
F_182 ( V_265 ) ;
F_182 ( V_264 ) ;
}
#ifdef F_116
V_198 = V_370
& ~ V_196
& ~ V_301 ;
F_17 ( V_55 | V_311 ,
L_127 ,
V_198 , V_286 ) ;
#endif
F_20 ( V_55 | V_311 ,
L_128 ) ;
V_17 = F_120 ( true ) ;
if ( V_17 ) {
F_181 () ;
return V_17 ;
}
V_17 = F_112 ( ( ( V_196 & ~ V_301 )
| V_200 )
& ~ V_198 ) ;
if ( V_17 < 0 && V_17 != - V_49 ) {
F_181 () ;
return V_17 ;
}
V_197 = ( V_195 | V_198 )
& ~ V_301 ;
F_17 ( V_55 | V_311 ,
L_129 ,
V_197 , V_195 , V_198 ) ;
V_212 -> V_353 = & F_150 ;
V_212 -> V_354 = & F_152 ;
F_148 ( true ) ;
return 0 ;
V_358:
F_54 ( V_309 , & V_154 -> V_60 . V_125 ) ;
F_55 ( & V_154 -> V_60 . V_125 ,
& V_361 ) ;
V_309 = NULL ;
return ( V_17 < 0 ) ? V_17 : 1 ;
}
static int F_177 ( void )
{
int V_371 = 0 ;
if ( ! F_7 ( V_129 , & V_371 , L_130 , L_7 , 0 ) ) {
F_8 ( L_131 ) ;
return - V_50 ;
}
return V_371 ;
}
static int F_179 ( int V_372 )
{
if ( V_372 < 0 ||
V_372 > V_306 )
return - V_94 ;
if ( ! F_7 ( V_129 , NULL , L_132 , L_9 , V_372 ) ) {
F_8 ( L_133 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_195 ( int V_371 )
{
T_10 V_42 ;
T_10 V_373 = F_100 ( V_374 ) - 1 ;
for ( V_42 = 0 ; V_42 <= V_373 ; V_42 ++ ) {
if ( V_374 [ V_42 ] == V_371 )
break;
}
if ( V_42 >= V_373 )
V_42 = 0 ;
else
V_42 ++ ;
return V_374 [ V_42 ] ;
}
static bool F_196 ( unsigned int V_214 )
{
int V_305 = 0 ;
int V_372 = 0 ;
int V_215 ;
switch ( V_214 ) {
case V_375 :
if ( V_376 ) {
V_372 = V_377 ;
V_376 = false ;
} else {
V_305 = F_177 () ;
if ( V_305 < 0 )
return false ;
V_372 = F_195 (
V_305 ) ;
}
if ( F_179 ( V_372 ) < 0 )
return false ;
return true ;
case V_378 :
V_305 = F_177 () ;
if ( V_305 < 0 )
return false ;
V_377 = V_305 ;
V_376 = true ;
if ( F_179 ( V_379 ) < 0 )
return false ;
return true ;
default:
if ( V_214 < V_380 ||
V_214 >= V_380 + V_366 -
V_381 ) {
F_76 ( L_134 ,
V_214 ) ;
return false ;
}
V_215 = V_216 [ V_214 - V_380 + V_381 ] ;
if ( V_215 != V_217 ) {
F_115 ( & V_211 ) ;
F_126 ( V_212 , V_215 , 1 ) ;
F_123 ( V_212 ) ;
F_126 ( V_212 , V_215 , 0 ) ;
F_123 ( V_212 ) ;
F_118 ( & V_211 ) ;
}
return true ;
}
}
static bool F_197 ( const T_7 V_355 ,
bool * V_382 ,
bool * V_383 )
{
unsigned int V_214 = V_355 & 0xfff ;
* V_382 = true ;
* V_383 = false ;
if ( V_214 > 0 && V_214 <= V_366 ) {
V_214 -- ;
if ( ! ( V_198 & ( 1 << V_214 ) ) ) {
F_127 ( V_214 ) ;
* V_382 = false ;
} else {
* V_383 = true ;
}
return true ;
} else {
return F_196 ( V_214 ) ;
}
return false ;
}
static bool F_198 ( const T_7 V_355 ,
bool * V_382 ,
bool * V_383 )
{
* V_382 = true ;
* V_383 = false ;
switch ( V_355 ) {
case V_384 :
case V_385 :
V_303 = V_386 ;
* V_383 = true ;
break;
case V_387 :
case V_388 :
V_303 = V_389 ;
* V_383 = true ;
break;
case V_390 :
case V_391 :
F_199 ( L_135 ) ;
break;
default:
return false ;
}
if ( V_303 != V_392 ) {
F_76 ( L_136 ) ;
F_173 () ;
}
return true ;
}
static bool F_200 ( const T_7 V_355 ,
bool * V_382 ,
bool * V_383 )
{
* V_382 = true ;
* V_383 = false ;
switch ( V_355 ) {
case V_393 :
V_304 = 1 ;
F_76 ( L_137 ) ;
F_175 () ;
return true ;
case V_394 :
F_76 ( L_138 ) ;
return true ;
case V_395 :
F_76 ( L_139 ) ;
return true ;
default:
return false ;
}
}
static bool F_201 ( const T_7 V_355 ,
bool * V_382 ,
bool * V_383 )
{
* V_382 = true ;
* V_383 = false ;
switch ( V_355 ) {
case V_396 :
case V_397 :
return true ;
case V_398 :
case V_399 :
F_121 () ;
F_171 () ;
* V_382 = false ;
return true ;
case V_400 :
case V_401 :
case V_402 :
* V_383 = true ;
return true ;
default:
return false ;
}
}
static bool F_202 ( const T_7 V_355 ,
bool * V_382 ,
bool * V_383 )
{
bool V_403 = true ;
* V_382 = true ;
* V_383 = false ;
switch ( V_355 ) {
case V_404 :
F_76 ( L_140 ) ;
return true ;
case V_405 :
F_203 ( L_141 ) ;
break;
case V_406 :
F_199 ( L_142 ) ;
break;
case V_407 :
F_203 ( L_143
L_144 ) ;
break;
case V_408 :
F_199 ( L_145
L_146 ) ;
break;
case V_409 :
case V_410 :
case V_411 :
case V_412 :
* V_382 = false ;
* V_383 = true ;
return true ;
case V_413 :
F_121 () ;
F_171 () ;
* V_382 = false ;
break;
default:
F_62 ( L_147 ) ;
V_403 = false ;
}
F_204 () ;
return V_403 ;
}
static void F_205 ( struct V_67 * V_68 , T_7 V_65 )
{
T_7 V_355 ;
bool V_382 ;
bool V_383 ;
bool V_414 ;
if ( V_65 != 0x80 ) {
F_8 ( L_148 , V_65 ) ;
F_206 (
V_68 -> V_71 -> V_74 -> V_415 . V_416 ,
F_207 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , 0 ) ;
return;
}
while ( 1 ) {
if ( ! F_7 ( V_129 , & V_355 , L_149 , L_64 ) ) {
F_8 ( L_150 ) ;
return;
}
if ( V_355 == 0 ) {
return;
}
V_382 = true ;
V_383 = false ;
switch ( V_355 >> 12 ) {
case 1 :
V_414 = F_197 ( V_355 , & V_382 ,
& V_383 ) ;
break;
case 2 :
V_414 = F_198 ( V_355 , & V_382 ,
& V_383 ) ;
break;
case 3 :
switch ( V_355 ) {
case V_417 :
V_304 = 1 ;
F_76 ( L_151 ) ;
F_175 () ;
V_414 = true ;
break;
case V_418 :
V_414 = true ;
break;
default:
V_414 = false ;
}
break;
case 4 :
V_414 = F_200 ( V_355 , & V_382 ,
& V_383 ) ;
break;
case 5 :
V_414 = F_201 ( V_355 , & V_382 ,
& V_383 ) ;
break;
case 6 :
V_414 = F_202 ( V_355 , & V_382 ,
& V_383 ) ;
break;
case 7 :
if ( V_186 . V_187 &&
V_355 == V_419 ) {
F_180 () ;
V_382 = 0 ;
V_414 = true ;
break;
}
default:
V_414 = false ;
}
if ( ! V_414 ) {
F_32 ( L_152 , V_355 ) ;
F_32 ( L_153
L_154 , V_359 ) ;
}
if ( ! V_383 && V_382 ) {
F_206 (
V_68 -> V_71 -> V_74 -> V_415 . V_416 ,
F_207 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , V_355 ) ;
}
}
}
static void F_208 ( void )
{
V_303 = V_392 ;
V_304 = 0 ;
if ( V_186 . V_360 ) {
if ( ! F_7 ( V_129 , & V_377 ,
L_130 , L_7 , 0 ) ) {
F_8 ( L_155 ) ;
}
}
}
static void F_209 ( void )
{
F_60 () ;
if ( F_120 ( true ) < 0 ||
F_112 ( V_195 ) < 0 )
F_8 ( L_156
L_157 ) ;
F_180 () ;
F_171 () ;
F_173 () ;
F_175 () ;
F_148 ( false ) ;
if ( V_186 . V_360 ) {
if ( ! F_7 ( V_129 , NULL , L_132 , L_9 ,
V_377 ) ) {
F_8 ( L_158 ) ;
}
}
}
static int F_210 ( struct V_90 * V_91 )
{
int V_17 , V_30 ;
if ( ! V_186 . V_207 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
if ( F_157 ( & V_208 ) )
return - V_298 ;
V_17 = F_119 ( & V_30 ) ;
if ( ! V_17 )
V_17 = F_110 () ;
F_118 ( & V_208 ) ;
if ( V_17 )
return V_17 ;
F_84 ( V_91 , L_47 , F_191 ( V_30 , 0 ) ) ;
if ( V_196 ) {
F_84 ( V_91 , L_159 , V_197 ) ;
F_84 ( V_91 , L_160 ) ;
} else {
F_84 ( V_91 , L_161 ) ;
F_84 ( V_91 , L_162 ) ;
}
return 0 ;
}
static void F_211 ( bool V_209 )
{
F_2 ( L_163 ) ;
if ( ! F_212 ( ( V_69 == V_70 || ! V_209 ) ,
F_213 ( L_164
L_165
L_166 ) ) )
F_8 ( L_167
L_168
L_166 ) ;
}
static int F_214 ( char * V_126 )
{
int V_17 ;
T_7 V_202 ;
char * V_159 ;
if ( ! V_186 . V_207 )
return - V_75 ;
if ( F_157 ( & V_208 ) )
return - V_298 ;
V_202 = V_197 ;
V_17 = 0 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_51 ) == 0 ) {
F_211 ( 1 ) ;
} else if ( F_86 ( V_159 , L_52 ) == 0 ) {
F_211 ( 0 ) ;
V_17 = - V_158 ;
} else if ( F_86 ( V_159 , L_169 ) == 0 ) {
V_202 = ( V_196 | V_198 )
& ~ V_301 ;
} else if ( sscanf ( V_159 , L_170 , & V_202 ) == 1 ) {
} else if ( sscanf ( V_159 , L_171 , & V_202 ) == 1 ) {
} else {
V_17 = - V_94 ;
goto V_420;
}
}
if ( ! V_17 ) {
F_82 ( L_172 ,
L_173 , V_202 ) ;
V_17 = F_113 ( V_202 ) ;
}
V_420:
F_118 ( & V_208 ) ;
return V_17 ;
}
static int F_215 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_174 )
return ( V_168 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_174 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_421 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_216 ( enum V_422 V_210 )
{
int V_30 ;
F_17 ( V_140 ,
L_175 ,
( V_210 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_174 ) {
V_168 = ( V_210 == V_142 ) ;
return 0 ;
}
#endif
if ( V_210 == V_142 )
V_30 = V_421
| V_423 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_176 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_217 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_424 ,
V_122 , V_126 ) ;
}
static T_8 F_218 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_424 ,
V_122 , V_126 , V_35 ) ;
}
static void F_219 ( void )
{
if ( ! F_7 ( NULL , NULL , L_177 , L_9 ,
V_425 ) )
F_32 ( L_178 ) ;
else
F_17 ( V_140 ,
L_179 ) ;
}
static void F_220 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_426 ) ;
F_77 ( V_424 ) ;
F_219 () ;
}
static int T_1 F_221 ( struct V_315 * V_316 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_180 ) ;
F_188 ( V_355 ) ;
V_186 . V_427 = V_129 &&
F_7 ( V_129 , & V_30 , L_174 , L_105 ) ;
F_17 ( V_55 | V_140 ,
L_181 ,
F_1 ( V_186 . V_427 ) ,
V_30 ) ;
#ifdef F_102
if ( V_174 ) {
V_186 . V_427 = 1 ;
F_76 ( L_182 ) ;
} else
#endif
if ( V_186 . V_427 &&
! ( V_30 & V_428 ) ) {
V_186 . V_427 = 0 ;
F_20 ( V_55 | V_140 ,
L_183 ) ;
}
if ( ! V_186 . V_427 )
return 1 ;
V_17 = F_71 ( V_424 ,
& V_429 ,
V_430 ,
V_431 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_190 ( & V_154 -> V_60 . V_125 ,
& V_426 ) ;
if ( V_17 ) {
F_77 ( V_424 ) ;
return V_17 ;
}
return 0 ;
}
static int F_222 ( struct V_90 * V_91 )
{
return F_83 ( V_424 , V_91 ) ;
}
static int F_223 ( char * V_126 )
{
return F_85 ( V_424 , V_126 ) ;
}
static int F_224 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_176 )
return ( V_169 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_184 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_432 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_225 ( enum V_422 V_210 )
{
int V_30 ;
F_17 ( V_140 ,
L_185 ,
( V_210 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_176 ) {
V_169 = ( V_210 == V_142 ) ;
return 0 ;
}
#endif
if ( V_210 == V_142 )
V_30 = V_432
| V_433 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_186 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_226 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_434 ,
V_122 , V_126 ) ;
}
static T_8 F_227 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_434 ,
V_122 , V_126 , V_35 ) ;
}
static void F_228 ( void )
{
if ( ! F_7 ( NULL , NULL , L_187 , L_9 ,
V_435 ) )
F_32 ( L_188 ) ;
else
F_17 ( V_140 ,
L_189 ) ;
}
static void F_229 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_436 ) ;
F_77 ( V_434 ) ;
F_228 () ;
}
static int T_1 F_230 ( struct V_315 * V_316 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_190 ) ;
F_188 ( V_355 ) ;
V_186 . V_437 = V_129 &&
F_7 ( V_129 , & V_30 , L_184 , L_105 ) ;
F_17 ( V_55 | V_140 ,
L_191 ,
F_1 ( V_186 . V_437 ) ,
V_30 ) ;
#ifdef F_102
if ( V_176 ) {
V_186 . V_437 = 1 ;
F_76 ( L_192 ) ;
} else
#endif
if ( V_186 . V_437 &&
! ( V_30 & V_438 ) ) {
V_186 . V_437 = 0 ;
F_20 ( V_55 | V_140 ,
L_193 ) ;
}
if ( ! V_186 . V_437 )
return 1 ;
V_17 = F_71 ( V_434 ,
& V_439 ,
V_440 ,
V_441 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_190 ( & V_154 -> V_60 . V_125 ,
& V_436 ) ;
if ( V_17 ) {
F_77 ( V_434 ) ;
return V_17 ;
}
return 0 ;
}
static int F_231 ( struct V_90 * V_91 )
{
return F_83 ( V_434 , V_91 ) ;
}
static int F_232 ( char * V_126 )
{
return F_85 ( V_434 , V_126 ) ;
}
static int F_233 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_178 )
return ( V_170 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_194 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_442 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_234 ( enum V_422 V_210 )
{
int V_30 ;
F_17 ( V_140 ,
L_195 ,
( V_210 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_178 ) {
V_170 = ( V_210 == V_142 ) ;
return 0 ;
}
#endif
if ( V_210 == V_142 )
V_30 = V_442 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_196 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static void F_235 ( void )
{
F_77 ( V_443 ) ;
}
static int T_1 F_236 ( struct V_315 * V_316 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_197 ) ;
F_188 ( V_355 ) ;
V_186 . V_444 = V_129 &&
F_7 ( V_129 , & V_30 , L_194 , L_105 ) ;
F_17 ( V_55 | V_140 ,
L_198 ,
F_1 ( V_186 . V_444 ) ,
V_30 ) ;
#ifdef F_102
if ( V_178 ) {
V_186 . V_444 = 1 ;
F_76 ( L_199 ) ;
} else
#endif
if ( V_186 . V_444 &&
! ( V_30 & V_445 ) ) {
V_186 . V_444 = 0 ;
F_20 ( V_55 ,
L_200 ) ;
}
if ( ! V_186 . V_444 )
return 1 ;
V_17 = F_71 ( V_443 ,
& V_446 ,
V_447 ,
V_448 ,
false ) ;
return V_17 ;
}
static int T_1 F_237 ( struct V_315 * V_316 )
{
int V_449 ;
F_17 ( V_55 , L_201 ) ;
F_188 ( V_450 ) ;
if ( F_6 () )
F_188 ( V_451 ) ;
if ( V_452 && F_7 ( NULL , & V_449 , L_202 , L_64 ) && V_449 )
V_453 = V_452 ;
if ( ! V_453 )
V_454 = V_455 ;
else if ( F_6 () &&
F_7 ( V_453 , & V_456 , L_203 , L_105 ) )
V_454 = V_457 ;
else if ( F_6 () &&
F_7 ( V_453 , & V_456 , L_204 , L_105 ) )
V_454 = V_458 ;
else
V_454 = V_459 ;
F_17 ( V_55 , L_205 ,
F_1 ( V_454 != V_455 ) ,
V_454 ) ;
return ( V_454 != V_455 ) ? 0 : 1 ;
}
static void F_238 ( void )
{
F_20 ( V_310 ,
L_206 ) ;
if ( F_239 ( V_456 ) )
F_8 ( L_207
L_208 ) ;
}
static int F_240 ( void )
{
int V_30 = 0 ;
int V_42 ;
switch ( V_454 ) {
case V_457 :
if ( ! F_7 ( NULL , & V_42 , L_209 , L_7 ,
V_460 ) )
return - V_50 ;
V_30 = V_42 & V_461 ;
break;
case V_458 :
if ( ! F_7 ( NULL , & V_42 , L_210 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_462 ;
if ( ! F_7 ( NULL , & V_42 , L_211 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_463 ;
break;
case V_459 :
if ( ! F_7 ( NULL , NULL , L_212 , L_9 , 1 ) ||
! F_7 ( NULL , & V_42 , L_211 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_463 ;
if ( ! F_7 ( NULL , NULL , L_212 , L_9 , 0 ) ||
! F_7 ( NULL , & V_42 , L_210 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_462 ;
if ( ! F_7 ( NULL , & V_42 , L_213 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_464 ;
break;
default:
return - V_465 ;
}
return V_30 ;
}
static int F_241 ( int V_30 )
{
int V_466 ;
int V_17 = 0 ;
switch ( V_454 ) {
case V_457 :
V_17 = F_7 ( NULL , NULL ,
L_214 , L_8 ,
V_467 ,
V_30 | V_468 ) ;
break;
case V_458 :
V_466 = F_242 () ;
if ( V_466 < 0 )
return V_466 ;
V_17 = F_239 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_453 , NULL ,
L_215 , L_8 , V_30 * 0x100 , 0 ) ;
if ( ! V_466 && F_239 ( V_466 ) ) {
F_8 ( L_216 ) ;
return - V_50 ;
}
break;
case V_459 :
V_17 = F_7 ( NULL , NULL , L_212 , L_9 , 0x80 ) &&
F_7 ( NULL , NULL , L_217 , L_8 , V_30 , 1 ) ;
break;
default:
return - V_465 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_242 ( void )
{
int V_466 = 0 ;
switch ( V_454 ) {
case V_457 :
if ( ! F_7 ( V_453 , & V_466 , L_203 , L_64 ) )
return - V_50 ;
break;
case V_458 :
case V_459 :
if ( ! F_7 ( V_453 , & V_466 , L_218 , L_64 ) )
return - V_50 ;
break;
default:
return - V_465 ;
}
return V_466 & 1 ;
}
static int F_239 ( int V_209 )
{
if ( ! F_7 ( V_453 , NULL , L_219 , L_9 , ( V_209 ) ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static int F_243 ( void )
{
int V_466 = F_242 () ;
int V_17 ;
if ( V_466 < 0 )
return V_466 ;
switch ( V_454 ) {
case V_457 :
V_17 = F_239 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_192 , NULL , L_220 , L_221 ) ;
break;
case V_458 :
case V_459 :
V_17 = F_239 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_453 , NULL , L_222 , L_221 ) ;
break;
default:
return - V_465 ;
}
if ( ! V_466 && F_239 ( V_466 ) ) {
F_8 ( L_216 ) ;
return - V_50 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_244 ( void )
{
switch ( V_454 ) {
case V_457 :
return F_7 ( V_192 , NULL , L_223 , L_221 ) ?
0 : - V_50 ;
case V_458 :
return F_7 ( V_453 , NULL , L_224 , L_221 ) ?
0 : - V_50 ;
case V_459 :
return F_7 ( NULL , NULL , L_225 , L_221 ) ?
0 : - V_50 ;
default:
return - V_465 ;
}
}
static int F_245 ( struct V_90 * V_91 )
{
int V_30 , V_466 ;
if ( V_454 == V_455 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
if ( ! F_246 ( V_469 ) )
return - V_158 ;
V_30 = F_240 () ;
if ( V_30 < 0 )
return V_30 ;
V_466 = F_242 () ;
if ( V_466 < 0 )
return V_466 ;
F_84 ( V_91 , L_226 ) ;
F_84 ( V_91 , L_227 , F_191 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_228 , F_191 ( V_30 , 1 ) ) ;
if ( V_454 == V_459 )
F_84 ( V_91 , L_229 , F_191 ( V_30 , 3 ) ) ;
F_84 ( V_91 , L_230 , F_191 ( V_466 , 0 ) ) ;
F_84 ( V_91 , L_231 ) ;
F_84 ( V_91 , L_232 ) ;
if ( V_454 == V_459 )
F_84 ( V_91 , L_233 ) ;
F_84 ( V_91 , L_234 ) ;
F_84 ( V_91 , L_235 ) ;
return 0 ;
}
static int F_247 ( char * V_126 )
{
char * V_159 ;
int V_209 , V_470 , V_30 ;
int V_17 ;
if ( V_454 == V_455 )
return - V_75 ;
if ( ! F_246 ( V_469 ) )
return - V_158 ;
V_209 = 0 ;
V_470 = 0 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_236 ) == 0 ) {
V_209 |= V_462 ;
} else if ( F_86 ( V_159 , L_237 ) == 0 ) {
V_470 |= V_462 ;
} else if ( F_86 ( V_159 , L_238 ) == 0 ) {
V_209 |= V_463 ;
} else if ( F_86 ( V_159 , L_239 ) == 0 ) {
V_470 |= V_463 ;
} else if ( V_454 == V_459 &&
F_86 ( V_159 , L_240 ) == 0 ) {
V_209 |= V_464 ;
} else if ( V_454 == V_459 &&
F_86 ( V_159 , L_241 ) == 0 ) {
V_470 |= V_464 ;
} else if ( F_86 ( V_159 , L_242 ) == 0 ) {
V_17 = F_239 ( 1 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_243 ) == 0 ) {
V_17 = F_239 ( 0 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_244 ) == 0 ) {
V_17 = F_243 () ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_245 ) == 0 ) {
V_17 = F_244 () ;
if ( V_17 )
return V_17 ;
} else
return - V_94 ;
}
if ( V_209 || V_470 ) {
V_30 = F_240 () ;
if ( V_30 < 0 )
return V_30 ;
V_17 = F_241 ( ( V_30 & ~ V_470 ) | V_209 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_248 ( int V_56 )
{
if ( ! V_129 )
return - V_49 ;
if ( ! F_7 ( V_129 , NULL , L_246 , L_7 , V_56 ) )
return - V_50 ;
return 0 ;
}
static int F_249 ( void )
{
int V_30 = 0 ;
if ( ! V_129 )
return - V_49 ;
if ( ! F_7 ( V_129 , & V_30 , L_247 , L_7 , 0 ) )
return - V_50 ;
if ( V_30 < 0 )
return V_30 ;
return V_30 & 0x3 ;
}
static bool F_250 ( void )
{
int V_30 = 0 ;
if ( ! V_129 )
return false ;
if ( ! F_251 ( V_129 , L_247 ) ) {
F_17 ( V_55 , L_248 ) ;
return false ;
}
if ( ! F_7 ( V_129 , & V_30 , L_247 , L_249 , 0 ) ) {
F_17 ( V_55 , L_250 ) ;
return false ;
}
if ( V_30 < 0 ) {
F_17 ( V_55 , L_251 , V_30 ) ;
return false ;
}
F_17 ( V_55 , L_252 , V_30 ) ;
return V_30 & F_252 ( 9 ) ;
}
static void F_253 ( struct V_471 * V_472 )
{
struct V_473 * V_66 =
F_254 ( V_472 , struct V_473 , V_472 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_255 ( V_66 -> V_474 ) ;
}
static void F_256 ( struct V_475 * V_476 ,
enum V_477 V_478 )
{
struct V_473 * V_66 =
F_254 ( V_476 ,
struct V_473 ,
V_475 ) ;
V_66 -> V_474 = V_478 ;
F_257 ( V_479 , & V_66 -> V_472 ) ;
}
static enum V_477 F_258 ( struct V_475 * V_476 )
{
int V_56 ;
V_56 = F_249 () ;
if ( V_56 < 0 )
return 0 ;
return V_56 ;
}
static int T_1 F_259 ( struct V_315 * V_316 )
{
int V_73 ;
F_17 ( V_55 , L_253 ) ;
F_188 ( V_355 ) ;
F_260 ( & V_480 . V_472 , F_253 ) ;
if ( ! F_250 () ) {
V_186 . V_481 = 0 ;
F_17 ( V_55 , L_254 ) ;
return 1 ;
}
V_186 . V_481 = 1 ;
V_73 = F_261 ( & V_154 -> V_60 ,
& V_480 . V_475 ) ;
if ( V_73 < 0 ) {
V_186 . V_481 = 0 ;
return V_73 ;
}
return 0 ;
}
static void F_262 ( void )
{
if ( V_186 . V_481 )
F_263 ( & V_480 . V_475 ) ;
F_264 ( V_479 ) ;
}
static int F_255 ( int V_56 )
{
int V_100 ;
struct V_475 * V_476 ;
V_100 = F_248 ( V_56 ) ;
V_476 = & V_480 . V_475 ;
if ( V_100 == 0 && ! ( V_476 -> V_79 & V_482 ) )
V_476 -> V_478 = V_56 ;
return V_100 ;
}
static int F_265 ( struct V_90 * V_91 )
{
int V_56 ;
if ( ! V_186 . V_481 ) {
F_84 ( V_91 , L_46 ) ;
} else {
V_56 = F_249 () ;
if ( V_56 < 0 )
F_84 ( V_91 , L_255 , V_56 ) ;
else
F_84 ( V_91 , L_256 , V_56 ) ;
F_84 ( V_91 , L_257 ) ;
}
return 0 ;
}
static int F_266 ( char * V_126 )
{
char * V_159 ;
int V_56 = - 1 ;
if ( ! V_186 . V_481 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_258 ) == 0 )
V_56 = 0 ;
else if ( F_86 ( V_159 , L_259 ) == 0 )
V_56 = 1 ;
else if ( F_86 ( V_159 , L_260 ) == 0 )
V_56 = 2 ;
else
return - V_94 ;
}
if ( V_56 == - 1 )
return - V_94 ;
return F_255 ( V_56 ) ;
}
static void F_267 ( void )
{
struct V_475 * V_476 ;
if ( ! V_186 . V_481 )
return;
V_476 = & V_480 . V_475 ;
F_268 ( V_476 ) ;
F_269 ( V_476 ) ;
}
static void F_270 ( void )
{
if ( ! V_186 . V_481 )
return;
F_271 ( & V_480 . V_475 ) ;
}
static int F_272 ( void )
{
int V_30 = 0 ;
if ( V_186 . V_483 ) {
if ( ! F_7 ( V_192 , & V_30 , L_261 , L_64 ) )
return - V_50 ;
return ( ! ! V_30 ) ;
}
return - V_49 ;
}
static int F_273 ( int V_30 )
{
int V_73 ;
if ( V_186 . V_484 ) {
if ( V_48 ) {
V_73 = F_7 ( V_48 , NULL , NULL , L_9 ,
( V_30 ) ?
V_485 :
V_486 ) ;
} else {
V_73 = F_7 ( V_487 , NULL , NULL , L_9 ,
( V_30 ) ? 1 : 0 ) ;
}
return ( V_73 ) ? 0 : - V_50 ;
}
return - V_49 ;
}
static void F_274 ( struct V_471 * V_472 )
{
struct V_473 * V_66 =
F_254 ( V_472 , struct V_473 , V_472 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_273 ( ( V_66 -> V_474 != V_488 ) ) ;
}
static void F_275 ( struct V_475 * V_476 ,
enum V_477 V_478 )
{
struct V_473 * V_66 =
F_254 ( V_476 ,
struct V_473 ,
V_475 ) ;
V_66 -> V_474 = ( V_478 != V_489 ) ?
V_490 : V_488 ;
F_257 ( V_479 , & V_66 -> V_472 ) ;
}
static enum V_477 F_276 ( struct V_475 * V_476 )
{
return ( F_272 () == 1 ) ? V_491 : V_489 ;
}
static int T_1 F_277 ( struct V_315 * V_316 )
{
int V_73 ;
F_17 ( V_55 , L_262 ) ;
if ( F_6 () ) {
F_188 ( V_492 ) ;
F_188 ( V_493 ) ;
}
F_188 ( V_494 ) ;
F_260 ( & V_495 . V_472 , F_274 ) ;
V_186 . V_484 = ( V_48 || V_487 ) && ! V_496 ;
if ( V_186 . V_484 )
V_186 . V_483 =
F_7 ( V_192 , NULL , L_261 , L_263 ) ;
F_17 ( V_55 , L_264 ,
F_1 ( V_186 . V_484 ) ,
F_1 ( V_186 . V_483 ) ) ;
if ( ! V_186 . V_484 )
return 1 ;
V_73 = F_261 ( & V_154 -> V_60 ,
& V_495 . V_475 ) ;
if ( V_73 < 0 ) {
V_186 . V_484 = 0 ;
V_186 . V_483 = 0 ;
} else {
V_73 = 0 ;
}
return V_73 ;
}
static void F_278 ( void )
{
F_263 ( & V_495 . V_475 ) ;
F_264 ( V_479 ) ;
}
static int F_279 ( struct V_90 * V_91 )
{
int V_30 ;
if ( ! V_186 . V_484 ) {
F_84 ( V_91 , L_46 ) ;
} else if ( ! V_186 . V_483 ) {
F_84 ( V_91 , L_265 ) ;
F_84 ( V_91 , L_266 ) ;
} else {
V_30 = F_272 () ;
if ( V_30 < 0 )
return V_30 ;
F_84 ( V_91 , L_47 , F_280 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_266 ) ;
}
return 0 ;
}
static int F_281 ( char * V_126 )
{
char * V_159 ;
int V_497 = 0 ;
if ( ! V_186 . V_484 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_267 ) == 0 ) {
V_497 = 1 ;
} else if ( F_86 ( V_159 , L_268 ) == 0 ) {
V_497 = 0 ;
} else
return - V_94 ;
}
return F_273 ( V_497 ) ;
}
static T_8 F_282 ( struct V_74 * V_60 ,
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
static int T_1 F_283 ( struct V_315 * V_316 )
{
int V_17 ;
F_17 ( V_55 ,
L_269 ) ;
F_188 ( V_494 ) ;
F_17 ( V_55 , L_270 ,
F_1 ( V_48 != NULL ) ) ;
V_17 = F_284 ( & V_154 -> V_60 , & V_498 ) ;
if ( V_17 )
return V_17 ;
return ( V_48 ) ? 0 : 1 ;
}
static void F_285 ( void )
{
F_286 ( & V_154 -> V_60 , & V_498 ) ;
}
static int F_287 ( struct V_90 * V_91 )
{
if ( ! V_48 )
F_84 ( V_91 , L_46 ) ;
else {
F_84 ( V_91 , L_226 ) ;
F_84 ( V_91 , L_271 ) ;
}
return 0 ;
}
static int F_288 ( char * V_126 )
{
char * V_159 ;
int V_47 , V_17 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_272 , & V_47 ) == 1 &&
V_47 >= 0 && V_47 <= 21 ) {
} else
return - V_94 ;
V_17 = F_15 ( V_47 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static inline bool F_289 ( const unsigned int V_499 )
{
#ifdef F_290
return false ;
#else
return ( 1U & ( V_500 >> V_499 ) ) == 0 ;
#endif
}
static int F_291 ( const unsigned int V_499 )
{
int V_30 ;
enum V_501 V_502 ;
switch ( V_503 ) {
case V_504 :
if ( ! F_7 ( V_192 ,
& V_30 , L_273 , L_7 , 1 << V_499 ) )
return - V_50 ;
V_502 = ( V_30 == 0 ) ?
V_488 :
( ( V_30 == 1 ) ?
V_490 :
V_505 ) ;
V_506 [ V_499 ] = V_502 ;
return V_502 ;
default:
return - V_49 ;
}
}
static int F_292 ( const unsigned int V_499 ,
const enum V_501 V_507 )
{
static const unsigned int V_508 [] = { 0 , 1 , 3 } ;
static const unsigned int V_509 [] = { 0 , 0x80 , 0xc0 } ;
int V_73 = 0 ;
switch ( V_503 ) {
case V_504 :
if ( F_142 ( V_499 > 7 ) )
return - V_94 ;
if ( F_142 ( F_289 ( V_499 ) ) )
return - V_158 ;
if ( ! F_7 ( V_510 , NULL , NULL , L_8 ,
( 1 << V_499 ) , V_508 [ V_507 ] ) )
V_73 = - V_50 ;
break;
case V_511 :
if ( F_142 ( V_499 > 7 ) )
return - V_94 ;
if ( F_142 ( F_289 ( V_499 ) ) )
return - V_158 ;
V_73 = F_14 ( V_512 , ( 1 << V_499 ) ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_513 ,
( V_507 == V_505 ) << V_499 ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_514 ,
( V_507 != V_488 ) << V_499 ) ;
break;
case V_515 :
if ( F_142 ( V_499 >= V_516 ) )
return - V_94 ;
if ( F_142 ( F_289 ( V_499 ) ) )
return - V_158 ;
if ( ! F_7 ( V_510 , NULL , NULL , L_8 ,
V_499 , V_509 [ V_507 ] ) )
V_73 = - V_50 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
V_506 [ V_499 ] = V_507 ;
return V_73 ;
}
static void F_293 ( struct V_471 * V_472 )
{
struct V_473 * V_66 =
F_254 ( V_472 , struct V_473 , V_472 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_292 ( V_66 -> V_499 , V_66 -> V_474 ) ;
}
static void F_294 ( struct V_475 * V_476 ,
enum V_477 V_478 )
{
struct V_473 * V_66 = F_254 ( V_476 ,
struct V_473 , V_475 ) ;
if ( V_478 == V_489 )
V_66 -> V_474 = V_488 ;
else if ( V_506 [ V_66 -> V_499 ] != V_505 )
V_66 -> V_474 = V_490 ;
else
V_66 -> V_474 = V_505 ;
F_257 ( V_479 , & V_66 -> V_472 ) ;
}
static int F_295 ( struct V_475 * V_476 ,
unsigned long * V_517 , unsigned long * V_518 )
{
struct V_473 * V_66 = F_254 ( V_476 ,
struct V_473 , V_475 ) ;
if ( * V_517 == 0 && * V_518 == 0 ) {
* V_517 = 500 ;
* V_518 = 500 ;
} else if ( ( * V_517 != 500 ) || ( * V_518 != 500 ) )
return - V_94 ;
V_66 -> V_474 = V_505 ;
F_257 ( V_479 , & V_66 -> V_472 ) ;
return 0 ;
}
static enum V_477 F_296 ( struct V_475 * V_476 )
{
int V_73 ;
struct V_473 * V_66 = F_254 ( V_476 ,
struct V_473 , V_475 ) ;
V_73 = F_291 ( V_66 -> V_499 ) ;
if ( V_73 == V_488 || V_73 < 0 )
V_73 = V_489 ;
else
V_73 = V_491 ;
return V_73 ;
}
static void F_297 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_516 ; V_42 ++ ) {
if ( V_519 [ V_42 ] . V_475 . V_51 )
F_263 ( & V_519 [ V_42 ] . V_475 ) ;
}
F_264 ( V_479 ) ;
F_37 ( V_519 ) ;
}
static int T_1 F_298 ( unsigned int V_499 )
{
int V_73 ;
V_519 [ V_499 ] . V_499 = V_499 ;
if ( ! V_520 [ V_499 ] )
return 0 ;
V_519 [ V_499 ] . V_475 . V_521 = & F_294 ;
V_519 [ V_499 ] . V_475 . V_522 = & F_295 ;
if ( V_503 == V_504 )
V_519 [ V_499 ] . V_475 . V_523 =
& F_296 ;
V_519 [ V_499 ] . V_475 . V_51 = V_520 [ V_499 ] ;
F_260 ( & V_519 [ V_499 ] . V_472 , F_293 ) ;
V_73 = F_261 ( & V_154 -> V_60 ,
& V_519 [ V_499 ] . V_475 ) ;
if ( V_73 < 0 )
V_519 [ V_499 ] . V_475 . V_51 = NULL ;
return V_73 ;
}
static enum V_524 T_1 F_299 ( void )
{
T_4 V_30 ;
if ( F_6 () ) {
V_30 = F_18 ( V_192 , L_274 , & V_510 ) ;
if ( F_19 ( V_30 ) )
return V_504 ;
V_30 = F_18 ( V_192 , L_275 , & V_510 ) ;
if ( F_19 ( V_30 ) )
return V_511 ;
}
V_30 = F_18 ( V_192 , L_276 , & V_510 ) ;
if ( F_19 ( V_30 ) )
return V_515 ;
V_510 = NULL ;
return V_525 ;
}
static int T_1 F_300 ( struct V_315 * V_316 )
{
unsigned int V_42 ;
int V_73 ;
unsigned long V_526 ;
F_17 ( V_55 , L_277 ) ;
V_503 = F_299 () ;
if ( V_503 != V_525 ) {
V_526 = F_4 ( V_527 ,
F_100 ( V_527 ) ) ;
if ( ! V_526 ) {
V_510 = NULL ;
V_503 = V_525 ;
}
}
F_17 ( V_55 , L_278 ,
F_1 ( V_503 ) , V_503 ) ;
if ( V_503 == V_525 )
return 1 ;
V_519 = F_35 ( sizeof( * V_519 ) * V_516 ,
V_83 ) ;
if ( ! V_519 ) {
F_8 ( L_279 ) ;
return - V_84 ;
}
for ( V_42 = 0 ; V_42 < V_516 ; V_42 ++ ) {
V_519 [ V_42 ] . V_499 = - 1 ;
if ( ! F_289 ( V_42 ) &&
F_301 ( V_42 , & V_526 ) ) {
V_73 = F_298 ( V_42 ) ;
if ( V_73 < 0 ) {
F_297 () ;
return V_73 ;
}
}
}
#ifdef F_290
F_32 ( L_280
L_281 ) ;
#endif
return 0 ;
}
static int F_302 ( struct V_90 * V_91 )
{
if ( ! V_503 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
F_84 ( V_91 , L_226 ) ;
if ( V_503 == V_504 ) {
int V_42 , V_30 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_30 = F_291 ( V_42 ) ;
if ( V_30 < 0 )
return - V_50 ;
F_84 ( V_91 , L_282 ,
V_42 , F_303 ( V_30 ) ) ;
}
}
F_84 ( V_91 , L_283
L_284 ) ;
return 0 ;
}
static int F_304 ( char * V_126 )
{
char * V_159 ;
int V_499 , V_73 ;
enum V_501 V_118 ;
if ( ! V_503 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_285 , & V_499 ) != 1 )
return - V_94 ;
if ( V_499 < 0 || V_499 > ( V_516 - 1 ) ||
V_519 [ V_499 ] . V_499 < 0 )
return - V_75 ;
if ( strstr ( V_159 , L_268 ) ) {
V_118 = V_488 ;
} else if ( strstr ( V_159 , L_267 ) ) {
V_118 = V_490 ;
} else if ( strstr ( V_159 , L_286 ) ) {
V_118 = V_505 ;
} else {
return - V_94 ;
}
V_73 = F_292 ( V_499 , V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
static int T_1 F_305 ( struct V_315 * V_316 )
{
unsigned long V_13 ;
F_17 ( V_55 , L_287 ) ;
F_188 ( V_528 ) ;
F_17 ( V_55 , L_288 ,
F_1 ( V_529 != NULL ) ) ;
V_13 = F_4 ( V_530 ,
F_100 ( V_530 ) ) ;
V_186 . V_531 = ! ! ( V_13 & V_532 ) ;
return ( V_529 ) ? 0 : 1 ;
}
static int F_306 ( struct V_90 * V_91 )
{
if ( ! V_529 )
F_84 ( V_91 , L_46 ) ;
else {
F_84 ( V_91 , L_226 ) ;
F_84 ( V_91 , L_289 ) ;
}
return 0 ;
}
static int F_307 ( char * V_126 )
{
char * V_159 ;
int V_533 ;
if ( ! V_529 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_272 , & V_533 ) == 1 &&
V_533 >= 0 && V_533 <= 17 ) {
} else
return - V_94 ;
if ( V_186 . V_531 ) {
if ( ! F_7 ( V_529 , NULL , NULL , L_8 ,
V_533 , 0 ) )
return - V_50 ;
} else {
if ( ! F_7 ( V_529 , NULL , NULL , L_9 ,
V_533 ) )
return - V_50 ;
}
}
return 0 ;
}
static int F_308 ( int V_534 , T_17 * V_38 )
{
int V_157 ;
T_18 V_535 ;
char V_536 [ 5 ] ;
V_157 = V_537 ;
switch ( V_538 ) {
#if V_539 >= 16
case V_540 :
if ( V_534 >= 8 && V_534 <= 15 ) {
V_157 = V_541 ;
V_534 -= 8 ;
}
#endif
case V_542 :
if ( V_534 <= 7 ) {
if ( ! F_11 ( V_157 + V_534 , & V_535 ) )
return - V_50 ;
* V_38 = V_535 * 1000 ;
return 0 ;
}
break;
case V_543 :
if ( V_534 <= 7 ) {
snprintf ( V_536 , sizeof( V_536 ) , L_290 , '0' + V_534 ) ;
if ( ! F_7 ( V_192 , NULL , L_291 , L_221 ) )
return - V_50 ;
if ( ! F_7 ( V_192 , & V_157 , V_536 , L_64 ) )
return - V_50 ;
* V_38 = ( V_157 - 2732 ) * 100 ;
return 0 ;
}
break;
case V_544 :
if ( V_534 <= 7 ) {
snprintf ( V_536 , sizeof( V_536 ) , L_290 , '0' + V_534 ) ;
if ( ! F_7 ( V_192 , & V_157 , V_536 , L_64 ) )
return - V_50 ;
if ( V_157 > 127 || V_157 < - 127 )
V_157 = V_545 ;
* V_38 = V_157 * 1000 ;
return 0 ;
}
break;
case V_546 :
default:
return - V_465 ;
}
return - V_94 ;
}
static int F_309 ( struct V_547 * V_118 )
{
int V_17 , V_42 ;
int V_221 ;
V_221 = 8 ;
V_42 = 0 ;
if ( ! V_118 )
return - V_94 ;
if ( V_538 == V_540 )
V_221 = 16 ;
for ( V_42 = 0 ; V_42 < V_221 ; V_42 ++ ) {
V_17 = F_308 ( V_42 , & V_118 -> V_548 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return V_221 ;
}
static void F_204 ( void )
{
int V_221 , V_42 ;
struct V_547 V_157 ;
V_221 = F_309 ( & V_157 ) ;
if ( V_221 <= 0 )
return;
F_32 ( L_292 ) ;
for ( V_42 = 0 ; V_42 < V_221 ; V_42 ++ ) {
if ( V_157 . V_548 [ V_42 ] != V_549 )
F_310 ( L_293 , ( int ) ( V_157 . V_548 [ V_42 ] / 1000 ) ) ;
else
F_310 ( L_294 ) ;
}
F_310 ( L_295 ) ;
}
static T_8 F_311 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
struct V_550 * V_551 =
F_312 ( V_122 ) ;
int V_534 = V_551 -> V_552 ;
T_17 V_38 ;
int V_17 ;
V_17 = F_308 ( V_534 , & V_38 ) ;
if ( V_17 )
return V_17 ;
if ( V_38 == V_549 )
return - V_49 ;
return snprintf ( V_126 , V_102 , L_44 , V_38 ) ;
}
static int T_1 F_313 ( struct V_315 * V_316 )
{
T_6 V_157 , V_553 , V_554 ;
int V_42 ;
int V_555 ;
int V_17 ;
F_17 ( V_55 , L_296 ) ;
V_555 = F_7 ( V_192 , NULL , L_297 , L_263 ) ;
if ( V_7 . V_12 ) {
V_553 = V_554 = 0 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( F_11 ( V_537 + V_42 , & V_157 ) ) {
V_553 |= V_157 ;
} else {
V_553 = 0 ;
break;
}
if ( F_11 ( V_541 + V_42 , & V_157 ) ) {
V_554 |= V_157 ;
} else {
V_553 = 0 ;
break;
}
}
if ( V_553 == 0 ) {
if ( V_555 ) {
F_8 ( L_298
L_299
L_300 ) ;
V_538 = V_544 ;
} else {
F_8 ( L_298
L_301 ) ;
V_538 = V_546 ;
}
} else {
V_538 =
( V_554 != 0 ) ?
V_540 : V_542 ;
}
} else if ( V_555 ) {
if ( F_6 () &&
F_7 ( V_192 , NULL , L_291 , L_263 ) ) {
V_538 = V_543 ;
} else {
V_538 = V_544 ;
}
} else {
V_538 = V_546 ;
}
F_17 ( V_55 , L_302 ,
F_1 ( V_538 != V_546 ) ,
V_538 ) ;
switch ( V_538 ) {
case V_540 :
V_17 = F_190 ( & V_556 -> V_60 . V_125 ,
& V_557 ) ;
if ( V_17 )
return V_17 ;
break;
case V_542 :
case V_544 :
case V_543 :
V_17 = F_190 ( & V_556 -> V_60 . V_125 ,
& V_558 ) ;
if ( V_17 )
return V_17 ;
break;
case V_546 :
default:
return 1 ;
}
return 0 ;
}
static void F_314 ( void )
{
switch ( V_538 ) {
case V_540 :
F_55 ( & V_556 -> V_60 . V_125 ,
& V_557 ) ;
break;
case V_542 :
case V_544 :
case V_543 :
F_55 ( & V_556 -> V_60 . V_125 ,
& V_558 ) ;
break;
case V_546 :
default:
break;
}
}
static int F_315 ( struct V_90 * V_91 )
{
int V_221 , V_42 ;
struct V_547 V_157 ;
V_221 = F_309 ( & V_157 ) ;
if ( F_142 ( V_221 < 0 ) )
return V_221 ;
F_84 ( V_91 , L_303 ) ;
if ( V_221 > 0 ) {
for ( V_42 = 0 ; V_42 < ( V_221 - 1 ) ; V_42 ++ )
F_84 ( V_91 , L_304 , V_157 . V_548 [ V_42 ] / 1000 ) ;
F_84 ( V_91 , L_44 , V_157 . V_548 [ V_42 ] / 1000 ) ;
} else
F_84 ( V_91 , L_305 ) ;
return 0 ;
}
static unsigned int F_316 ( void )
{
T_6 V_559 ;
V_559 = ( F_131 ( V_242 )
& V_244 )
>> V_245 ;
V_559 &= V_276 ;
return V_559 ;
}
static void F_317 ( void )
{
T_6 V_560 = 0 ;
T_6 V_561 ;
if ( V_562 != V_563 )
return;
F_17 ( V_564 ,
L_306 ) ;
if ( F_157 ( & V_565 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_566 , & V_560 ) ) )
goto V_567;
V_560 &= V_568 ;
V_561 = F_131 ( V_242 ) ;
if ( V_560 != ( ( V_561 & V_244 )
>> V_245 ) ) {
V_561 &= ~ ( V_244 <<
V_245 ) ;
V_561 |= V_560 ;
F_318 ( V_561 , V_242 ) ;
F_20 ( V_564 ,
L_307 ,
( unsigned int ) V_560 , ( unsigned int ) V_561 ) ;
} else
F_17 ( V_564 ,
L_308 ,
( unsigned int ) V_560 , ( unsigned int ) V_561 ) ;
V_567:
F_118 ( & V_565 ) ;
}
static int F_319 ( int * V_30 )
{
T_6 V_560 = 0 ;
switch ( V_562 ) {
case V_569 :
* V_30 = F_316 () ;
return 0 ;
case V_570 :
case V_563 :
if ( F_142 ( ! F_11 ( V_566 , & V_560 ) ) )
return - V_50 ;
* V_30 = V_560 ;
return 0 ;
default:
return - V_49 ;
}
}
static int F_320 ( unsigned int V_38 )
{
T_6 V_560 = 0 ;
if ( F_142 ( ! F_11 ( V_566 , & V_560 ) ) )
return - V_50 ;
if ( F_142 ( ! F_13 ( V_566 ,
( V_560 & V_571 ) |
( V_38 & V_568 ) ) ) )
return - V_50 ;
return 0 ;
}
static int F_321 ( unsigned int V_38 )
{
int V_47 , V_572 ;
unsigned int V_573 , V_42 ;
V_573 = F_316 () ;
if ( V_38 == V_573 )
return 0 ;
V_47 = ( V_38 > V_573 ) ?
V_574 :
V_575 ;
V_572 = ( V_38 > V_573 ) ? 1 : - 1 ;
for ( V_42 = V_573 ; V_42 != V_38 ; V_42 += V_572 )
if ( F_15 ( V_47 ) )
return - V_50 ;
return 0 ;
}
static int V_521 ( unsigned int V_38 )
{
int V_17 ;
if ( V_38 > V_276 )
return - V_94 ;
F_17 ( V_564 ,
L_309 , V_38 ) ;
V_17 = F_157 ( & V_565 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_562 ) {
case V_570 :
case V_563 :
V_17 = F_320 ( V_38 ) ;
break;
case V_569 :
V_17 = F_321 ( V_38 ) ;
break;
default:
V_17 = - V_49 ;
}
F_118 ( & V_565 ) ;
return V_17 ;
}
static int F_322 ( struct V_576 * V_577 )
{
unsigned int V_56 =
( V_577 -> V_578 . V_579 == V_580 &&
V_577 -> V_578 . V_581 == V_580 ) ?
V_577 -> V_578 . V_478 : 0 ;
F_20 ( V_564 ,
L_310 ,
V_56 ) ;
return V_521 ( V_56 ) ;
}
static int V_523 ( struct V_576 * V_577 )
{
int V_30 , V_17 ;
V_17 = F_157 ( & V_565 ) ;
if ( V_17 < 0 )
return 0 ;
V_17 = F_319 ( & V_30 ) ;
F_118 ( & V_565 ) ;
if ( V_17 < 0 )
return 0 ;
return V_30 & V_568 ;
}
static void F_323 ( void )
{
F_324 ( V_582 ,
V_583 ) ;
}
static int T_1 F_325 ( T_3 V_16 )
{
struct V_26 V_584 = { V_585 , NULL } ;
union V_23 * V_586 ;
struct V_59 * V_74 , * V_587 ;
int V_73 ;
if ( F_22 ( V_16 , & V_74 ) )
return 0 ;
V_73 = 0 ;
F_326 (child, &device->children, node) {
T_4 V_30 = F_9 ( V_587 -> V_16 , L_311 ,
NULL , & V_584 ) ;
if ( F_31 ( V_30 ) )
continue;
V_586 = (union V_23 * ) V_584 . V_36 ;
if ( ! V_586 || ( V_586 -> type != V_588 ) ) {
F_8 ( L_312 ,
V_359 ) ;
V_73 = 0 ;
} else {
V_73 = V_586 -> V_589 . V_35 ;
}
break;
}
F_37 ( V_584 . V_36 ) ;
return V_73 ;
}
static unsigned int T_1 F_327 ( void )
{
T_3 V_590 ;
int V_591 = 0 ;
F_24 ( L_13 , NULL , & V_590 ) ;
if ( V_590 )
V_591 = F_325 ( V_590 ) ;
V_186 . V_592 = ( V_591 > 0 ) ;
return ( V_591 > 2 ) ? ( V_591 - 2 ) : 0 ;
}
static void T_1 F_328 ( void )
{
unsigned int V_593 ;
F_17 ( V_55 ,
L_313 ) ;
V_593 = F_327 () ;
switch ( V_593 ) {
case 16 :
V_276 = 15 ;
break;
case 8 :
case 0 :
V_276 = 7 ;
break;
default:
V_186 . V_277 = 1 ;
V_276 = V_593 - 1 ;
}
F_329 ( L_314 , V_276 + 1 ) ;
}
static int T_1 F_330 ( struct V_315 * V_316 )
{
struct V_594 V_578 ;
int V_593 ;
unsigned long V_13 ;
F_17 ( V_55 , L_315 ) ;
F_189 ( & V_565 ) ;
V_13 = F_4 ( V_595 ,
F_100 ( V_595 ) ) ;
if ( V_186 . V_277 )
return 1 ;
if ( ! V_596 ) {
F_20 ( V_55 | V_564 ,
L_316
L_317 ) ;
return 1 ;
}
if ( F_194 () != V_369 ) {
if ( V_596 > 1 ) {
F_76 ( L_318
L_319 ) ;
return 1 ;
} else if ( V_596 == 1 ) {
F_62 ( L_320
L_321
L_322 ) ;
return 1 ;
}
} else if ( V_186 . V_592 && V_596 > 1 ) {
F_32 ( L_323
L_324
L_325 ) ;
}
if ( V_562 > V_597 )
return - V_94 ;
if ( V_562 == V_598 ||
V_562 == V_597 ) {
if ( V_13 & V_599 )
V_562 = V_563 ;
else
V_562 = V_569 ;
F_20 ( V_564 ,
L_326 ,
V_562 ) ;
}
if ( ! F_6 () &&
( V_562 == V_563 ||
V_562 == V_570 ) )
return - V_94 ;
if ( F_319 ( & V_593 ) < 0 )
return 1 ;
memset ( & V_578 , 0 , sizeof( struct V_594 ) ) ;
V_578 . type = V_600 ;
V_578 . V_601 = V_276 ;
V_578 . V_478 = V_593 & V_568 ;
V_582 = F_331 ( V_602 ,
NULL , NULL ,
& V_603 ,
& V_578 ) ;
if ( F_147 ( V_582 ) ) {
int V_73 = F_332 ( V_582 ) ;
V_582 = NULL ;
F_8 ( L_327 ) ;
return V_73 ;
}
F_17 ( V_55 | V_564 ,
L_328 ) ;
if ( V_13 & V_604 ) {
F_32 ( L_329
L_330 , V_562 ) ;
F_32 ( L_331
L_332 , V_359 ) ;
}
F_333 ( V_582 ) ;
F_17 ( V_55 | V_564 ,
L_333
L_334 ) ;
F_114 ( V_200
| V_605
| V_606 ) ;
return 0 ;
}
static void F_334 ( void )
{
F_317 () ;
}
static void F_335 ( void )
{
F_317 () ;
}
static void F_336 ( void )
{
if ( V_582 ) {
F_17 ( V_310 | V_564 ,
L_335 ) ;
F_337 ( V_582 ) ;
}
F_317 () ;
}
static int F_338 ( struct V_90 * V_91 )
{
int V_56 ;
V_56 = V_523 ( NULL ) ;
if ( V_56 < 0 ) {
F_84 ( V_91 , L_336 ) ;
} else {
F_84 ( V_91 , L_337 , V_56 ) ;
F_84 ( V_91 , L_338 ) ;
F_84 ( V_91 , L_339 ,
V_276 ) ;
}
return 0 ;
}
static int F_339 ( char * V_126 )
{
int V_56 ;
int V_73 ;
char * V_159 ;
V_56 = V_523 ( NULL ) ;
if ( V_56 < 0 )
return V_56 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_340 ) == 0 ) {
if ( V_56 < V_276 )
V_56 ++ ;
} else if ( F_86 ( V_159 , L_341 ) == 0 ) {
if ( V_56 > 0 )
V_56 -- ;
} else if ( sscanf ( V_159 , L_342 , & V_56 ) == 1 &&
V_56 >= 0 && V_56 <= V_276 ) {
} else
return - V_94 ;
}
F_82 ( L_343 ,
L_344 , V_56 ) ;
V_73 = V_521 ( V_56 ) ;
if ( ! V_73 && V_582 )
F_324 ( V_582 ,
V_607 ) ;
return ( V_73 == - V_608 ) ? - V_298 : V_73 ;
}
static void F_340 ( void )
{
T_6 V_560 = 0 ;
T_6 V_561 ;
T_6 V_609 ;
if ( V_610 != V_611 )
return;
if ( ! V_612 )
return;
if ( V_613 )
return;
F_17 ( V_614 ,
L_345 ) ;
if ( V_186 . V_615 )
V_609 = V_616 ;
else
V_609 = V_616 | V_617 ;
if ( F_157 ( & V_618 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_619 , & V_560 ) ) )
goto V_567;
V_560 &= V_609 ;
V_561 = F_131 ( V_249 ) ;
if ( V_560 != ( V_561 & V_609 ) ) {
V_561 &= ~ V_609 ;
V_561 |= V_560 ;
F_318 ( V_561 , V_249 ) ;
F_20 ( V_614 ,
L_346 ,
( unsigned int ) V_560 , ( unsigned int ) V_561 ) ;
} else {
F_17 ( V_614 ,
L_347 ,
( unsigned int ) V_560 , ( unsigned int ) V_561 ) ;
}
V_567:
F_118 ( & V_618 ) ;
}
static int F_341 ( T_6 * V_30 )
{
T_6 V_118 ;
if ( ! F_11 ( V_619 , & V_118 ) )
return - V_50 ;
* V_30 = V_118 ;
F_20 ( V_614 , L_348 , V_118 ) ;
return 0 ;
}
static int F_342 ( T_6 * V_30 )
{
return F_341 ( V_30 ) ;
}
static int F_343 ( const T_6 V_30 )
{
if ( ! F_13 ( V_619 , V_30 ) )
return - V_50 ;
F_20 ( V_614 , L_349 , V_30 ) ;
F_344 ( 1 ) ;
return 0 ;
}
static int F_345 ( const T_6 V_30 )
{
return F_343 ( V_30 ) ;
}
static int F_346 ( const bool V_253 )
{
int V_73 ;
T_6 V_118 , V_221 ;
if ( F_157 ( & V_618 ) < 0 )
return - V_608 ;
V_73 = F_341 ( & V_118 ) ;
if ( V_73 )
goto V_567;
V_221 = ( V_253 ) ? V_118 | V_616 :
V_118 & ~ V_616 ;
if ( V_221 != V_118 ) {
V_73 = F_343 ( V_221 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_567:
F_118 ( & V_618 ) ;
return V_73 ;
}
static int F_347 ( const bool V_253 )
{
F_20 ( V_614 , L_350 ,
( V_253 ) ? L_1 : L_42 ) ;
return F_346 ( V_253 ) ;
}
static int F_348 ( const bool V_253 )
{
int V_73 ;
F_20 ( V_614 , L_351 ,
( V_253 ) ? L_1 : L_42 ) ;
V_73 = F_346 ( V_253 ) ;
return ( V_73 < 0 ) ? V_73 : 0 ;
}
static int F_349 ( const T_6 V_620 )
{
int V_73 ;
T_6 V_118 , V_221 ;
if ( V_620 > V_621 )
return - V_94 ;
if ( F_157 ( & V_618 ) < 0 )
return - V_608 ;
V_73 = F_341 ( & V_118 ) ;
if ( V_73 )
goto V_567;
V_221 = ( V_118 & ~ V_617 ) | V_620 ;
if ( V_221 != V_118 ) {
V_73 = F_343 ( V_221 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_567:
F_118 ( & V_618 ) ;
return V_73 ;
}
static int F_350 ( bool V_622 )
{
int V_27 ;
if ( ! F_5 () )
return - V_75 ;
if ( V_622 ) {
if ( ! F_7 ( V_192 , & V_623 ,
L_352 , L_105 ) )
return - V_50 ;
F_20 ( V_55 | V_614 ,
L_353 ,
V_623 ) ;
}
if ( ! F_7 ( V_192 , & V_27 , L_354 , L_249 ,
( int ) V_624 ) )
return - V_50 ;
if ( V_27 != V_624 )
F_62 ( L_355 ,
V_27 ) ;
if ( V_186 . V_615 )
V_27 = F_348 ( false ) ;
else
V_27 = F_345 ( V_621 ) ;
if ( V_27 != 0 )
F_62 ( L_356 ) ;
return 0 ;
}
static void F_351 ( void )
{
int V_625 ;
if ( ! F_7 ( V_192 , & V_625 , L_354 , L_249 , V_623 )
|| V_625 != V_623 )
F_62 ( L_357 ) ;
}
static int F_352 ( const T_6 V_620 )
{
F_20 ( V_614 ,
L_358 , V_620 ) ;
return F_349 ( V_620 ) ;
}
static void F_353 ( void )
{
struct V_626 * V_222 ;
if ( V_627 && V_627 -> V_628 ) {
V_222 = V_627 -> V_628 ;
if ( V_222 -> V_629 )
F_354 ( V_627 ,
V_630 ,
V_222 -> V_629 ) ;
if ( V_222 -> V_631 )
F_354 ( V_627 ,
V_630 ,
V_222 -> V_631 ) ;
}
}
static int F_355 ( struct V_632 * V_633 ,
struct V_634 * V_635 )
{
V_635 -> type = V_636 ;
V_635 -> V_35 = 1 ;
V_635 -> V_38 . integer . V_637 = 0 ;
V_635 -> V_38 . integer . V_127 = V_621 ;
return 0 ;
}
static int F_356 ( struct V_632 * V_633 ,
struct V_638 * V_639 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_342 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_639 -> V_38 . integer . V_38 [ 0 ] = V_118 & V_617 ;
return 0 ;
}
static int F_357 ( struct V_632 * V_633 ,
struct V_638 * V_639 )
{
F_82 ( L_359 , L_360 ,
V_639 -> V_38 . integer . V_38 [ 0 ] ) ;
return F_352 ( V_639 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static int F_358 ( struct V_632 * V_633 ,
struct V_638 * V_639 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_342 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_639 -> V_38 . integer . V_38 [ 0 ] =
( V_118 & V_616 ) ? 0 : 1 ;
return 0 ;
}
static int F_359 ( struct V_632 * V_633 ,
struct V_638 * V_639 )
{
F_82 ( L_359 , L_361 ,
V_639 -> V_38 . integer . V_38 [ 0 ] ?
L_42 : L_1 ) ;
return F_347 ( ! V_639 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static void F_360 ( void )
{
F_340 () ;
}
static void F_361 ( void )
{
if ( V_613 ) {
if ( F_350 ( false ) < 0 )
F_62 ( L_362 ) ;
} else {
F_353 () ;
}
}
static void F_362 ( void )
{
F_340 () ;
}
static void F_363 ( void )
{
if ( V_627 ) {
F_364 ( V_627 ) ;
V_627 = NULL ;
}
F_340 () ;
if ( V_613 )
F_351 () ;
}
static int T_1 F_365 ( void )
{
struct V_640 * V_641 ;
struct V_626 * V_66 ;
struct V_632 * V_642 ;
struct V_632 * V_643 ;
int V_73 ;
V_73 = F_366 ( & V_154 -> V_60 ,
V_644 , V_645 , V_646 ,
sizeof( struct V_626 ) , & V_641 ) ;
if ( V_73 < 0 || ! V_641 ) {
F_8 ( L_363 , V_73 ) ;
return 1 ;
}
F_25 ( ! V_641 -> V_628 ) ;
V_66 = V_641 -> V_628 ;
V_66 -> V_641 = V_641 ;
F_367 ( V_641 -> V_81 , V_647 ,
sizeof( V_641 -> V_81 ) ) ;
F_367 ( V_641 -> V_648 , V_649 ,
sizeof( V_641 -> V_648 ) ) ;
snprintf ( V_641 -> V_650 , sizeof( V_641 -> V_650 ) , L_364 ,
( V_7 . V_651 ) ?
V_7 . V_651 : L_365 ) ;
snprintf ( V_641 -> V_652 , sizeof( V_641 -> V_652 ) ,
L_366 , V_641 -> V_648 , V_619 ,
( V_7 . V_651 ) ?
V_7 . V_651 : L_367 ) ;
if ( V_612 ) {
V_653 . V_654 = F_357 ;
V_653 . V_655 =
V_656 ;
V_657 . V_654 = F_359 ;
V_657 . V_655 =
V_656 ;
}
if ( ! V_186 . V_615 ) {
V_642 = F_368 ( & V_653 , NULL ) ;
V_73 = F_369 ( V_641 , V_642 ) ;
if ( V_73 < 0 ) {
F_8 ( L_368 ,
V_73 ) ;
goto V_358;
}
V_66 -> V_631 = & V_642 -> V_144 ;
}
V_643 = F_368 ( & V_657 , NULL ) ;
V_73 = F_369 ( V_641 , V_643 ) ;
if ( V_73 < 0 ) {
F_8 ( L_369 , V_73 ) ;
goto V_358;
}
V_66 -> V_629 = & V_643 -> V_144 ;
V_73 = F_370 ( V_641 ) ;
if ( V_73 < 0 ) {
F_8 ( L_370 , V_73 ) ;
goto V_358;
}
V_627 = V_641 ;
return 0 ;
V_358:
F_364 ( V_641 ) ;
return 1 ;
}
static int T_1 F_371 ( struct V_315 * V_316 )
{
unsigned long V_13 ;
int V_73 ;
F_17 ( V_55 , L_371 ) ;
F_189 ( & V_618 ) ;
if ( V_610 > V_658 )
return - V_94 ;
if ( V_610 == V_659 ) {
F_8 ( L_372
L_373 , V_359 ) ;
return 1 ;
}
if ( V_660 >= V_661 )
return - V_94 ;
if ( ! V_662 ) {
F_17 ( V_55 | V_614 ,
L_374
L_375 ) ;
return 1 ;
}
V_13 = F_4 ( V_663 ,
F_100 ( V_663 ) ) ;
switch ( V_660 ) {
case V_664 :
if ( V_13 & V_665 )
V_186 . V_615 = 1 ;
else if ( V_13 & V_666 )
V_186 . V_615 = 0 ;
else
return 1 ;
break;
case V_667 :
V_186 . V_615 = 0 ;
break;
case V_668 :
V_186 . V_615 = 1 ;
break;
default:
return 1 ;
}
if ( V_660 != V_664 )
F_20 ( V_55 | V_614 ,
L_376 ,
V_660 ) ;
if ( V_610 == V_669 ||
V_610 == V_658 ) {
V_610 = V_611 ;
F_20 ( V_55 | V_614 ,
L_377 ,
V_610 ) ;
} else {
F_20 ( V_55 | V_614 ,
L_378 ,
V_610 ) ;
}
F_17 ( V_55 | V_614 ,
L_379 ,
F_1 ( ! V_186 . V_615 ) ) ;
if ( V_670 && F_350 ( true ) == 0 ) {
V_613 = true ;
} else {
V_73 = F_365 () ;
if ( V_73 ) {
F_8 ( L_380 ) ;
return V_73 ;
}
F_76 ( L_381 ,
( V_612 ) ?
L_382 :
L_383 ) ;
}
F_17 ( V_55 | V_614 ,
L_384 ) ;
F_114 ( V_200
| V_671
| V_672
| V_673 ) ;
return 0 ;
}
static int F_372 ( struct V_90 * V_91 )
{
T_6 V_30 ;
if ( F_342 ( & V_30 ) < 0 ) {
F_84 ( V_91 , L_336 ) ;
} else {
if ( V_186 . V_615 )
F_84 ( V_91 , L_385 ) ;
else
F_84 ( V_91 , L_337 ,
V_30 & V_617 ) ;
F_84 ( V_91 , L_386 ,
F_280 ( V_30 , V_674 ) ) ;
if ( V_612 ) {
F_84 ( V_91 , L_387 ) ;
if ( ! V_186 . V_615 ) {
F_84 ( V_91 ,
L_338 ) ;
F_84 ( V_91 ,
L_388
L_389 ,
V_621 ) ;
}
}
}
return 0 ;
}
static int F_373 ( char * V_126 )
{
T_6 V_118 ;
T_6 V_675 , V_676 ;
int V_677 ;
char * V_159 ;
int V_73 ;
if ( ! V_612 && V_69 != V_296 ) {
if ( F_142 ( ! V_205 . V_678 ) ) {
V_205 . V_678 = 1 ;
F_32 ( L_390
L_391 ) ;
F_32 ( L_392
L_393 ) ;
}
return - V_158 ;
}
V_73 = F_342 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_675 = V_118 & V_617 ;
V_676 = V_118 & V_616 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! V_186 . V_615 ) {
if ( F_86 ( V_159 , L_340 ) == 0 ) {
if ( V_676 )
V_676 = 0 ;
else if ( V_675 < V_621 )
V_675 ++ ;
continue;
} else if ( F_86 ( V_159 , L_341 ) == 0 ) {
if ( V_676 )
V_676 = 0 ;
else if ( V_675 > 0 )
V_675 -- ;
continue;
} else if ( sscanf ( V_159 , L_394 , & V_677 ) == 1 &&
V_677 >= 0 && V_677 <= V_621 ) {
V_675 = V_677 ;
continue;
}
}
if ( F_86 ( V_159 , L_395 ) == 0 )
V_676 = V_616 ;
else if ( F_86 ( V_159 , L_396 ) == 0 )
V_676 = 0 ;
else
return - V_94 ;
}
if ( V_186 . V_615 ) {
F_82 ( L_397 , L_361 ,
V_676 ? L_1 : L_42 ) ;
V_73 = F_348 ( ! ! V_676 ) ;
} else {
F_82 ( L_397 ,
L_398 ,
V_676 ? L_1 : L_42 , V_675 ) ;
V_73 = F_345 ( V_676 | V_675 ) ;
}
F_353 () ;
return ( V_73 == - V_608 ) ? - V_298 : V_73 ;
}
static inline void F_353 ( void )
{
}
static int T_1 F_371 ( struct V_315 * V_316 )
{
F_76 ( L_399 ) ;
return 1 ;
}
static void F_374 ( void )
{
if ( V_679 == 0x07 ) {
F_32 ( L_400
L_401 ) ;
V_186 . V_680 = 1 ;
}
}
static void F_375 ( T_6 * V_681 )
{
if ( F_142 ( V_186 . V_680 ) ) {
if ( * V_681 != V_679 ) {
V_186 . V_680 = 0 ;
} else {
* V_681 = V_682 ;
}
}
}
static bool F_376 ( void )
{
if ( V_186 . V_683 ) {
T_6 V_684 ;
if ( F_12 ( V_685 , & V_684 ) < 0 )
return false ;
V_684 &= 0xFEU ;
if ( F_14 ( V_685 , V_684 ) < 0 )
return false ;
}
return true ;
}
static bool F_377 ( void )
{
T_6 V_684 ;
if ( ! V_186 . V_683 )
return false ;
if ( F_12 ( V_685 , & V_684 ) < 0 )
return false ;
V_684 |= 0x01U ;
if ( F_14 ( V_685 , V_684 ) < 0 )
return false ;
return true ;
}
static void F_378 ( T_6 V_30 )
{
if ( ( V_30 &
( V_682 | V_686 ) ) == 0 ) {
if ( V_30 > 7 )
V_687 = 7 ;
else
V_687 = V_30 ;
}
}
static int F_379 ( T_6 * V_30 )
{
T_6 V_118 ;
switch ( V_688 ) {
case V_689 : {
int V_17 ;
if ( F_142 ( ! F_7 ( V_690 , & V_17 , NULL , L_64 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) )
* V_30 = V_17 & 0x07 ;
break;
}
case V_691 :
if ( F_142 ( ! F_11 ( V_692 , & V_118 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) ) {
* V_30 = V_118 ;
F_375 ( V_30 ) ;
}
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_380 ( T_6 * V_30 )
{
int V_73 ;
T_6 V_118 ;
if ( F_157 ( & V_693 ) )
return - V_298 ;
V_73 = F_379 ( & V_118 ) ;
if ( ! V_73 )
F_378 ( V_118 ) ;
F_118 ( & V_693 ) ;
if ( V_73 )
return V_73 ;
if ( V_30 )
* V_30 = V_118 ;
return 0 ;
}
static int F_381 ( unsigned int * V_694 )
{
T_6 V_695 , V_696 ;
switch ( V_688 ) {
case V_691 :
if ( F_142 ( ! F_376 () ) )
return - V_50 ;
if ( F_142 ( ! F_11 ( V_697 , & V_696 ) ||
! F_11 ( V_697 + 1 , & V_695 ) ) )
return - V_50 ;
if ( F_140 ( V_694 ) )
* V_694 = ( V_695 << 8 ) | V_696 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_382 ( unsigned int * V_694 )
{
T_6 V_695 , V_696 ;
bool V_73 ;
switch ( V_688 ) {
case V_691 :
if ( F_142 ( ! F_377 () ) )
return - V_50 ;
V_73 = ! F_11 ( V_697 , & V_696 ) ||
! F_11 ( V_697 + 1 , & V_695 ) ;
F_376 () ;
if ( V_73 )
return - V_50 ;
if ( F_140 ( V_694 ) )
* V_694 = ( V_695 << 8 ) | V_696 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_383 ( int V_56 )
{
if ( ! V_698 )
return - V_158 ;
switch ( V_699 ) {
case V_700 :
if ( V_56 >= 0 && V_56 <= 7 ) {
if ( ! F_7 ( V_701 , NULL , NULL , L_9 , V_56 ) )
return - V_50 ;
} else
return - V_94 ;
break;
case V_702 :
case V_703 :
if ( ! ( V_56 & V_682 ) &&
! ( V_56 & V_686 ) &&
( ( V_56 < 0 ) || ( V_56 > 7 ) ) )
return - V_94 ;
if ( V_56 & V_686 )
V_56 |= 7 ;
else if ( V_56 & V_682 )
V_56 |= 4 ;
if ( ! F_13 ( V_692 , V_56 ) )
return - V_50 ;
else
V_186 . V_680 = 0 ;
break;
default:
return - V_49 ;
}
F_17 ( V_704 ,
L_402 , V_56 ) ;
return 0 ;
}
static int F_384 ( int V_56 )
{
int V_73 ;
if ( ! V_698 )
return - V_158 ;
if ( F_157 ( & V_693 ) )
return - V_298 ;
if ( V_56 == V_705 )
V_56 = V_687 ;
V_73 = F_383 ( V_56 ) ;
if ( ! V_73 )
F_378 ( V_56 ) ;
F_118 ( & V_693 ) ;
return V_73 ;
}
static int F_385 ( void )
{
T_6 V_118 ;
int V_73 ;
if ( ! V_698 )
return - V_158 ;
if ( F_157 ( & V_693 ) )
return - V_298 ;
switch ( V_699 ) {
case V_702 :
case V_703 :
V_73 = F_379 ( & V_118 ) ;
if ( V_73 < 0 )
break;
if ( V_118 != 7 ) {
V_118 &= 0x07 ;
V_118 |= V_682 | 4 ;
}
if ( ! F_13 ( V_692 , V_118 ) )
V_73 = - V_50 ;
else {
V_186 . V_680 = 0 ;
V_73 = 0 ;
}
break;
case V_700 :
V_73 = F_379 ( & V_118 ) ;
if ( V_73 < 0 )
break;
V_118 &= 0x07 ;
V_118 |= 4 ;
if ( ! F_7 ( V_701 , NULL , NULL , L_9 , V_118 ) )
V_73 = - V_50 ;
else
V_73 = 0 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_693 ) ;
if ( ! V_73 )
F_17 ( V_704 ,
L_402 ,
V_118 ) ;
return V_73 ;
}
static int F_386 ( void )
{
int V_73 ;
if ( ! V_698 )
return - V_158 ;
if ( F_157 ( & V_693 ) )
return - V_298 ;
V_73 = 0 ;
switch ( V_699 ) {
case V_702 :
case V_703 :
if ( ! F_13 ( V_692 , 0x00 ) )
V_73 = - V_50 ;
else {
V_687 = 0 ;
V_186 . V_680 = 0 ;
}
break;
case V_700 :
if ( ! F_7 ( V_701 , NULL , NULL , L_9 , 0x00 ) )
V_73 = - V_50 ;
else
V_687 = 0 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
F_17 ( V_704 ,
L_403 ) ;
F_118 ( & V_693 ) ;
return V_73 ;
}
static int F_387 ( int V_694 )
{
int V_73 ;
if ( ! V_698 )
return - V_158 ;
if ( F_157 ( & V_693 ) )
return - V_298 ;
V_73 = 0 ;
switch ( V_699 ) {
case V_702 :
if ( V_694 >= 0 && V_694 <= 65535 ) {
if ( ! F_7 ( V_706 , NULL , NULL , L_404 ,
V_694 , V_694 , V_694 ) )
V_73 = - V_50 ;
} else
V_73 = - V_94 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_693 ) ;
return V_73 ;
}
static void F_388 ( void )
{
if ( V_699 == V_707 )
return;
if ( V_708 > 0 &&
V_69 != V_204 )
F_389 ( V_479 , & V_709 ,
F_390 ( V_708 * 1000 ) ) ;
else
F_391 ( & V_709 ) ;
}
static void F_392 ( struct V_471 * V_710 )
{
int V_73 ;
if ( V_69 != V_70 )
return;
F_32 ( L_405 ) ;
V_73 = F_385 () ;
if ( V_73 < 0 ) {
F_8 ( L_406
L_407 , - V_73 ) ;
F_388 () ;
}
}
static T_8 F_393 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_371 ;
T_6 V_30 ;
V_17 = F_380 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 & V_686 ) {
V_371 = 0 ;
} else if ( V_30 & V_682 ) {
V_371 = 2 ;
} else
V_371 = 1 ;
return snprintf ( V_126 , V_102 , L_44 , V_371 ) ;
}
static T_8 F_394 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 , V_56 ;
if ( F_57 ( V_126 , 2 , & V_157 ) )
return - V_94 ;
F_82 ( L_408 ,
L_409 , V_157 ) ;
switch ( V_157 ) {
case 0 :
V_56 = V_686 ;
break;
case 1 :
V_56 = V_705 ;
break;
case 2 :
V_56 = V_682 ;
break;
case 3 :
return - V_465 ;
default:
return - V_94 ;
}
V_17 = F_384 ( V_56 ) ;
if ( V_17 == - V_49 )
return - V_94 ;
else if ( V_17 < 0 )
return V_17 ;
F_388 () ;
return V_35 ;
}
static T_8 F_395 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
T_6 V_30 ;
V_17 = F_380 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_30 &
( V_682 | V_686 ) ) != 0 )
V_30 = V_687 ;
if ( V_30 > 7 )
V_30 = 7 ;
return snprintf ( V_126 , V_102 , L_410 , ( V_30 * 255 ) / 7 ) ;
}
static T_8 F_396 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_118 ;
int V_73 ;
T_6 V_30 , V_711 ;
if ( F_57 ( V_126 , 255 , & V_118 ) )
return - V_94 ;
F_82 ( L_411 ,
L_412 , V_118 ) ;
V_711 = ( V_118 >> 5 ) & 0x07 ;
if ( F_157 ( & V_693 ) )
return - V_298 ;
V_73 = F_379 ( & V_30 ) ;
if ( ! V_73 && ( V_30 &
( V_682 | V_686 ) ) == 0 ) {
V_73 = F_383 ( V_711 ) ;
if ( V_73 == - V_49 )
V_73 = - V_94 ;
else if ( ! V_73 ) {
F_378 ( V_711 ) ;
F_388 () ;
}
}
F_118 ( & V_693 ) ;
return ( V_73 ) ? V_73 : V_35 ;
}
static T_8 F_397 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_694 ;
V_17 = F_381 ( & V_694 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_410 , V_694 ) ;
}
static T_8 F_398 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_694 ;
V_17 = F_382 ( & V_694 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_410 , V_694 ) ;
}
static T_8 F_399 ( struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_410 , V_708 ) ;
}
static T_8 F_400 ( struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 120 , & V_157 ) )
return - V_94 ;
if ( ! V_698 )
return - V_158 ;
V_708 = V_157 ;
F_388 () ;
F_82 ( L_413 , L_97 , V_157 ) ;
return V_35 ;
}
static int T_1 F_401 ( struct V_315 * V_316 )
{
int V_73 ;
unsigned long V_13 ;
F_17 ( V_55 | V_704 ,
L_414 ) ;
F_189 ( & V_693 ) ;
V_688 = V_712 ;
V_699 = V_707 ;
V_713 = 0 ;
V_708 = 0 ;
V_186 . V_680 = 0 ;
V_186 . V_683 = 0 ;
V_687 = 7 ;
if ( F_6 () ) {
F_188 ( V_714 ) ;
F_188 ( V_715 ) ;
F_188 ( V_716 ) ;
}
V_13 = F_4 ( V_717 ,
F_100 ( V_717 ) ) ;
if ( V_690 ) {
V_688 = V_689 ;
} else {
if ( F_140 ( F_11 ( V_692 ,
& V_679 ) ) ) {
V_688 = V_691 ;
if ( V_13 & V_718 )
F_374 () ;
if ( V_13 & V_719 ) {
V_186 . V_683 = 1 ;
F_20 ( V_55 | V_704 ,
L_415 ) ;
}
} else {
F_8 ( L_298
L_416 ) ;
return 1 ;
}
}
if ( V_701 ) {
V_699 = V_700 ;
V_713 |=
V_720 | V_721 ;
} else {
if ( ! V_690 ) {
if ( V_706 ) {
V_699 =
V_702 ;
V_713 |=
V_722 |
V_720 |
V_721 ;
} else {
V_699 = V_703 ;
V_713 |=
V_720 |
V_721 ;
}
}
}
F_17 ( V_55 | V_704 ,
L_417 ,
F_1 ( V_688 != V_712 ||
V_699 != V_707 ) ,
V_688 , V_699 ) ;
if ( ! V_698 ) {
V_699 = V_707 ;
V_713 = 0 ;
F_20 ( V_55 | V_704 ,
L_418 ) ;
}
if ( V_688 != V_712 )
F_380 ( NULL ) ;
if ( V_688 != V_712 ||
V_699 != V_707 ) {
if ( V_186 . V_683 ) {
V_723 [ F_100 ( V_723 ) - 2 ] =
& V_724 . V_122 ;
}
V_73 = F_190 ( & V_556 -> V_60 . V_125 ,
& V_725 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_101 ( & V_726 . V_81 ,
& V_727 ) ;
if ( V_73 < 0 ) {
F_55 ( & V_556 -> V_60 . V_125 ,
& V_725 ) ;
return V_73 ;
}
return 0 ;
} else
return 1 ;
}
static void F_402 ( void )
{
F_17 ( V_310 | V_704 ,
L_419 ) ;
F_55 ( & V_556 -> V_60 . V_125 , & V_725 ) ;
F_104 ( & V_726 . V_81 ,
& V_727 ) ;
F_391 ( & V_709 ) ;
F_264 ( V_479 ) ;
}
static void F_403 ( void )
{
int V_73 ;
if ( ! V_698 )
return;
V_728 = 0 ;
V_73 = F_380 ( & V_728 ) ;
if ( V_73 < 0 )
F_32 ( L_420
L_421 , V_73 ) ;
if ( V_186 . V_680 )
V_728 = 0 ;
}
static void F_404 ( void )
{
T_6 V_729 = 7 ;
bool V_730 = false ;
int V_73 ;
V_186 . V_680 = 0 ;
if ( ! V_698 ||
! V_728 ||
( F_380 ( & V_729 ) < 0 ) )
return;
switch ( V_699 ) {
case V_700 :
V_730 = ( V_728 > V_729 ) ;
break;
case V_702 :
case V_703 :
if ( V_728 != 7 &&
! ( V_728 & V_686 ) )
return;
else
V_730 = ! ( V_729 & V_686 ) &&
( V_729 != V_728 ) ;
break;
default:
return;
}
if ( V_730 ) {
F_32 ( L_422 ,
V_728 ) ;
V_73 = F_384 ( V_728 ) ;
if ( V_73 < 0 )
F_32 ( L_423 , V_73 ) ;
}
}
static int F_405 ( struct V_90 * V_91 )
{
int V_73 ;
T_6 V_30 ;
unsigned int V_694 = 0 ;
switch ( V_688 ) {
case V_689 :
V_73 = F_380 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47
L_337 ,
( V_30 != 0 ) ? L_48 : L_49 , V_30 ) ;
break;
case V_691 :
V_73 = F_380 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47 ,
( V_30 != 0 ) ? L_48 : L_49 ) ;
V_73 = F_381 ( & V_694 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_424 , V_694 ) ;
if ( V_30 & V_686 )
F_84 ( V_91 , L_425 ) ;
else if ( V_30 & V_682 )
F_84 ( V_91 , L_426 ) ;
else
F_84 ( V_91 , L_337 , V_30 ) ;
break;
case V_712 :
default:
F_84 ( V_91 , L_46 ) ;
}
if ( V_713 & V_720 ) {
F_84 ( V_91 , L_388 ) ;
switch ( V_699 ) {
case V_700 :
F_84 ( V_91 , L_427 ) ;
break;
default:
F_84 ( V_91 , L_428
L_429 ) ;
break;
}
}
if ( V_713 & V_721 )
F_84 ( V_91 , L_50
L_430
L_431 ) ;
if ( V_713 & V_722 )
F_84 ( V_91 , L_432
L_433 ) ;
return 0 ;
}
static int F_406 ( const char * V_159 , int * V_73 )
{
int V_56 ;
if ( F_86 ( V_159 , L_434 ) == 0 )
V_56 = V_682 ;
else if ( ( F_86 ( V_159 , L_435 ) == 0 ) |
( F_86 ( V_159 , L_436 ) == 0 ) )
V_56 = V_686 ;
else if ( sscanf ( V_159 , L_342 , & V_56 ) != 1 )
return 0 ;
* V_73 = F_384 ( V_56 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_437 ,
V_699 ) ;
else if ( ! * V_73 )
F_82 ( L_438 ,
L_344 , V_56 ) ;
return 1 ;
}
static int F_407 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_51 ) != 0 )
return 0 ;
* V_73 = F_385 () ;
if ( * V_73 == - V_49 )
F_8 ( L_439 ,
V_699 ) ;
else if ( ! * V_73 )
F_82 ( L_438 , L_440 ) ;
return 1 ;
}
static int F_408 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_52 ) != 0 )
return 0 ;
* V_73 = F_386 () ;
if ( * V_73 == - V_49 )
F_8 ( L_441 ,
V_699 ) ;
else if ( ! * V_73 )
F_82 ( L_438 , L_442 ) ;
return 1 ;
}
static int F_409 ( const char * V_159 , int * V_73 )
{
int V_694 ;
if ( sscanf ( V_159 , L_443 , & V_694 ) != 1 )
return 0 ;
* V_73 = F_387 ( V_694 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_444 ,
V_699 ) ;
else if ( ! * V_73 )
F_82 ( L_438 ,
L_445 , V_694 ) ;
return 1 ;
}
static int F_410 ( const char * V_159 , int * V_73 )
{
int V_731 ;
if ( sscanf ( V_159 , L_446 , & V_731 ) != 1 )
return 0 ;
if ( V_731 < 0 || V_731 > 120 )
* V_73 = - V_94 ;
else {
V_708 = V_731 ;
F_82 ( L_438 ,
L_447 ,
V_731 ) ;
}
return 1 ;
}
static int F_411 ( char * V_126 )
{
char * V_159 ;
int V_73 = 0 ;
while ( ! V_73 && ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! ( ( V_713 & V_720 ) &&
F_406 ( V_159 , & V_73 ) ) &&
! ( ( V_713 & V_721 ) &&
( F_407 ( V_159 , & V_73 ) ||
F_408 ( V_159 , & V_73 ) ||
F_410 ( V_159 , & V_73 ) ) ) &&
! ( ( V_713 & V_722 ) &&
F_409 ( V_159 , & V_73 ) )
)
V_73 = - V_94 ;
else if ( ! V_73 )
F_388 () ;
}
return V_73 ;
}
static int F_412 ( struct V_732 * V_157 , bool V_210 )
{
T_3 V_548 ;
int V_733 ;
if ( F_31 ( F_18 ( V_129 , V_157 -> V_51 , & V_548 ) ) ) {
F_62 ( L_448 , V_157 -> V_51 ) ;
return - V_50 ;
}
if ( ! F_7 ( V_129 , & V_733 , V_157 -> V_51 , L_7 ,
V_210 ? V_157 -> V_734 : V_157 -> V_735 ) )
return - V_50 ;
V_157 -> V_210 = V_210 ;
return V_210 ;
}
int F_413 ( int V_736 , bool V_737 )
{
struct V_732 * V_157 ;
if ( V_736 < 0 || V_736 >= V_738 )
return - V_94 ;
V_157 = & V_739 [ V_736 ] ;
if ( V_157 -> V_210 < 0 || V_157 -> V_210 == V_737 )
return V_157 -> V_210 ;
return F_412 ( V_157 , V_737 ) ;
}
static int F_414 ( struct V_315 * V_316 )
{
T_3 V_548 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_738 ; V_42 ++ ) {
struct V_732 * V_157 = & V_739 [ V_42 ] ;
if ( F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_548 ) ) )
F_412 ( V_157 , false ) ;
else
V_157 -> V_210 = - V_75 ;
}
return 0 ;
}
static void F_415 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_738 ; V_42 ++ )
F_413 ( V_42 , false ) ;
}
static void F_416 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_738 ; V_42 ++ ) {
struct V_732 * V_157 = & V_739 [ V_42 ] ;
if ( V_157 -> V_210 >= 0 )
F_412 ( V_157 , V_157 -> V_210 ) ;
}
}
static void F_417 ( const unsigned int V_740 )
{
if ( V_582 ) {
switch ( V_740 ) {
case V_741 :
case V_742 :
F_323 () ;
}
}
if ( V_627 ) {
switch ( V_740 ) {
case V_743 :
case V_744 :
case V_745 :
F_353 () ;
}
}
}
static void F_128 ( const unsigned int V_214 )
{
F_417 ( V_746 + V_214 ) ;
}
static T_8 F_418 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_449 , V_85 ) ;
}
static const char * T_1 F_1 ( int V_1 )
{
static char V_747 [] V_748 = L_450 ;
return ( V_1 ) ? & V_747 [ 4 ] : & V_747 [ 0 ] ;
}
static void F_419 ( struct V_67 * V_68 )
{
F_20 ( V_310 , L_451 , V_68 -> V_51 ) ;
F_420 ( & V_68 -> V_749 ) ;
if ( V_68 -> V_79 . V_80 ) {
F_20 ( V_310 ,
L_452 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_421 ( * V_68 -> V_71 -> V_16 ,
V_68 -> V_71 -> type ,
F_27 ) ;
V_68 -> V_79 . V_80 = 0 ;
}
if ( V_68 -> V_79 . V_750 ) {
F_20 ( V_310 ,
L_453 , V_68 -> V_51 ) ;
F_422 ( V_68 -> V_51 , V_751 ) ;
V_68 -> V_79 . V_750 = 0 ;
}
if ( V_68 -> V_79 . V_89 ) {
F_20 ( V_310 ,
L_454 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_423 ( V_68 -> V_71 -> V_81 ) ;
F_37 ( V_68 -> V_71 -> V_81 ) ;
V_68 -> V_71 -> V_81 = NULL ;
V_68 -> V_79 . V_89 = 0 ;
}
if ( V_68 -> V_79 . V_752 && V_68 -> exit ) {
V_68 -> exit () ;
V_68 -> V_79 . V_752 = 0 ;
}
F_20 ( V_55 , L_455 , V_68 -> V_51 ) ;
}
static int T_1 F_424 ( struct V_315 * V_316 )
{
int V_100 ;
struct V_67 * V_68 = V_316 -> V_66 ;
struct V_753 * V_754 ;
F_25 ( V_68 == NULL ) ;
F_425 ( & V_68 -> V_749 ) ;
if ( V_68 -> V_79 . V_755 && ! V_755 )
return 0 ;
F_20 ( V_55 ,
L_456 , V_68 -> V_51 ) ;
if ( V_316 -> V_756 ) {
V_100 = V_316 -> V_756 ( V_316 ) ;
if ( V_100 > 0 )
return 0 ;
if ( V_100 )
return V_100 ;
V_68 -> V_79 . V_752 = 1 ;
}
if ( V_68 -> V_71 ) {
if ( V_68 -> V_71 -> V_63 ) {
V_100 = F_34 ( V_68 ) ;
if ( V_100 )
goto V_757;
}
if ( V_68 -> V_71 -> V_72 ) {
V_100 = F_28 ( V_68 ) ;
if ( V_100 == - V_75 ) {
F_32 ( L_457 ,
V_68 -> V_51 ) ;
V_100 = 0 ;
goto V_757;
}
if ( V_100 < 0 )
goto V_757;
}
}
F_20 ( V_55 ,
L_458 , V_68 -> V_51 ) ;
if ( V_68 -> V_93 ) {
T_19 V_371 = V_316 -> V_758 ;
if ( ! V_371 )
V_371 = V_759 ;
if ( V_68 -> V_101 )
V_371 |= V_760 ;
V_754 = F_426 ( V_68 -> V_51 , V_371 , V_751 ,
& V_761 , V_68 ) ;
if ( ! V_754 ) {
F_8 ( L_459 , V_68 -> V_51 ) ;
V_100 = - V_75 ;
goto V_757;
}
V_68 -> V_79 . V_750 = 1 ;
}
F_427 ( & V_68 -> V_749 , & V_762 ) ;
return 0 ;
V_757:
F_20 ( V_55 ,
L_460 ,
V_68 -> V_51 , V_100 ) ;
F_419 ( V_68 ) ;
return ( V_100 < 0 ) ? V_100 : 0 ;
}
static bool T_2 T_1 F_428 ( const char V_37 )
{
return ( V_37 >= '0' && V_37 <= '9' ) || ( V_37 >= 'A' && V_37 <= 'Z' ) ;
}
static bool T_2 T_1 F_429 ( const char * const V_118 ,
const char V_157 )
{
if ( V_118 && strlen ( V_118 ) >= 8 &&
F_428 ( V_118 [ 0 ] ) &&
F_428 ( V_118 [ 1 ] ) &&
V_118 [ 2 ] == V_157 &&
( V_118 [ 3 ] == 'T' || V_118 [ 3 ] == 'N' ) &&
F_428 ( V_118 [ 4 ] ) &&
F_428 ( V_118 [ 5 ] ) )
return true ;
return V_118 && strlen ( V_118 ) >= 8 &&
F_428 ( V_118 [ 0 ] ) &&
F_428 ( V_118 [ 1 ] ) &&
F_428 ( V_118 [ 2 ] ) &&
V_118 [ 3 ] == V_157 &&
( V_118 [ 4 ] == 'T' || V_118 [ 4 ] == 'N' ) &&
F_428 ( V_118 [ 5 ] ) &&
F_428 ( V_118 [ 6 ] ) ;
}
static int T_20 T_1 F_430 (
struct V_763 * V_764 )
{
const struct V_765 * V_60 = NULL ;
char V_766 [ 18 ] ;
char const * V_118 ;
if ( ! V_764 )
return - V_94 ;
memset ( V_764 , 0 , sizeof( * V_764 ) ) ;
if ( F_431 ( L_461 ) )
V_764 -> V_6 = V_15 ;
else if ( F_431 ( L_462 ) )
V_764 -> V_6 = V_14 ;
else
return 0 ;
V_118 = F_432 ( V_767 ) ;
V_764 -> V_768 = F_433 ( V_118 , V_83 ) ;
if ( V_118 && ! V_764 -> V_768 )
return - V_84 ;
if ( ! ( F_429 ( V_764 -> V_768 , 'E' ) ||
F_429 ( V_764 -> V_768 , 'C' ) ) )
return 0 ;
V_764 -> V_10 = V_764 -> V_768 [ 0 ]
| ( V_764 -> V_768 [ 1 ] << 8 ) ;
V_764 -> V_184 = ( V_764 -> V_768 [ 4 ] << 8 )
| V_764 -> V_768 [ 5 ] ;
while ( ( V_60 = F_434 ( V_769 , NULL , V_60 ) ) ) {
if ( sscanf ( V_60 -> V_51 ,
L_463 ,
V_766 ) == 1 ) {
V_766 [ sizeof( V_766 ) - 1 ] = 0 ;
V_766 [ strcspn ( V_766 , L_464 ) ] = 0 ;
V_764 -> V_651 = F_433 ( V_766 , V_83 ) ;
if ( ! V_764 -> V_651 )
return - V_84 ;
if ( F_429 ( V_766 , 'H' ) ) {
V_764 -> V_12 = V_766 [ 0 ]
| ( V_766 [ 1 ] << 8 ) ;
V_764 -> V_185 = ( V_766 [ 4 ] << 8 )
| V_766 [ 5 ] ;
} else {
F_32 ( L_465
L_466 ,
V_766 ) ;
F_32 ( L_116 ,
V_359 ) ;
}
break;
}
}
V_118 = F_432 ( V_770 ) ;
if ( V_118 && ! ( strncasecmp ( V_118 , L_467 , 8 ) && strncasecmp ( V_118 , L_468 , 6 ) ) ) {
V_764 -> V_771 = F_433 ( V_118 , V_83 ) ;
if ( ! V_764 -> V_771 )
return - V_84 ;
} else {
V_118 = F_432 ( V_772 ) ;
if ( V_118 && ! ( strncasecmp ( V_118 , L_468 , 6 ) ) ) {
V_764 -> V_771 = F_433 ( V_118 , V_83 ) ;
if ( ! V_764 -> V_771 )
return - V_84 ;
}
}
V_118 = F_432 ( V_773 ) ;
V_764 -> V_774 = F_433 ( V_118 , V_83 ) ;
if ( V_118 && ! V_764 -> V_774 )
return - V_84 ;
return 0 ;
}
static int T_1 F_435 ( void )
{
int V_775 ;
if ( V_776 )
return - V_75 ;
if ( ! F_6 () && ! F_5 () )
return - V_75 ;
V_775 = ( V_7 . V_771 != NULL ) ||
( V_7 . V_12 != 0 ) ||
F_107 () ;
F_24 ( L_469 , V_777 , & V_192 ) ;
if ( ! V_192 ) {
if ( V_775 )
F_8 ( L_470 ) ;
return - V_75 ;
}
if ( ! V_775 && ! V_778 )
return - V_75 ;
return 0 ;
}
static void T_1 F_436 ( void )
{
F_76 ( L_57 , V_165 , V_166 ) ;
F_76 ( L_449 , V_779 ) ;
F_76 ( L_471 ,
( V_7 . V_768 ) ?
V_7 . V_768 : L_367 ,
( V_7 . V_651 ) ?
V_7 . V_651 : L_367 ) ;
F_25 ( ! V_7 . V_6 ) ;
if ( V_7 . V_771 )
F_76 ( L_472 ,
( V_7 . V_6 == V_15 ) ?
L_461 : ( ( V_7 . V_6 ==
V_14 ) ?
L_468 : L_473 ) ,
V_7 . V_771 ,
( V_7 . V_774 ) ?
V_7 . V_774 : L_367 ) ;
}
static int T_1 F_437 ( const char * V_684 , struct V_780 * V_781 )
{
unsigned int V_42 ;
struct V_67 * V_68 ;
if ( ! V_781 || ! V_781 -> V_51 || ! V_684 )
return - V_94 ;
for ( V_42 = 0 ; V_42 < F_100 ( V_782 ) ; V_42 ++ ) {
V_68 = V_782 [ V_42 ] . V_66 ;
F_438 ( V_68 == NULL ) ;
if ( ! V_68 || ! V_68 -> V_51 )
continue;
if ( strcmp ( V_68 -> V_51 , V_781 -> V_51 ) == 0 && V_68 -> V_101 ) {
if ( strlen ( V_684 ) > sizeof( V_782 [ V_42 ] . V_783 ) - 2 )
return - V_784 ;
strcpy ( V_782 [ V_42 ] . V_783 , V_684 ) ;
strcat ( V_782 [ V_42 ] . V_783 , L_28 ) ;
return 0 ;
}
}
return - V_94 ;
}
static void F_439 ( void )
{
struct V_67 * V_68 , * V_107 ;
V_69 = V_204 ;
F_440 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
F_419 ( V_68 ) ;
}
F_20 ( V_55 , L_474 ) ;
if ( V_212 ) {
if ( V_186 . V_785 )
F_441 ( V_212 ) ;
else
F_442 ( V_212 ) ;
F_37 ( V_216 ) ;
}
if ( V_786 )
F_443 ( V_786 ) ;
if ( V_186 . V_787 )
F_286 ( & V_556 -> V_60 , & V_788 ) ;
if ( V_556 )
F_444 ( V_556 ) ;
if ( V_154 )
F_444 ( V_154 ) ;
if ( V_186 . V_789 )
F_103 ( & V_726 . V_81 ) ;
if ( V_186 . V_790 )
F_103 ( & V_791 . V_81 ) ;
if ( V_186 . V_792 )
F_445 ( & V_726 ) ;
if ( V_186 . V_793 )
F_445 ( & V_791 ) ;
if ( V_751 )
F_422 ( V_794 , V_795 ) ;
if ( V_479 )
F_446 ( V_479 ) ;
F_37 ( V_7 . V_768 ) ;
F_37 ( V_7 . V_651 ) ;
F_37 ( V_7 . V_771 ) ;
F_37 ( V_7 . V_774 ) ;
}
static int T_1 F_447 ( void )
{
int V_100 , V_42 ;
V_69 = V_296 ;
V_100 = F_430 ( & V_7 ) ;
if ( V_100 ) {
F_8 ( L_475 , V_100 ) ;
F_439 () ;
return V_100 ;
}
V_100 = F_435 () ;
if ( V_100 ) {
F_439 () ;
return V_100 ;
}
F_436 () ;
F_106 () ;
F_188 ( V_796 ) ;
F_188 ( V_797 ) ;
V_479 = F_448 ( V_798 ) ;
if ( ! V_479 ) {
F_439 () ;
return - V_84 ;
}
V_751 = F_449 ( V_794 , V_795 ) ;
if ( ! V_751 ) {
F_8 ( L_476 V_794 L_295 ) ;
F_439 () ;
return - V_75 ;
}
V_100 = F_450 ( & V_791 ) ;
if ( V_100 ) {
F_8 ( L_477 ) ;
F_439 () ;
return V_100 ;
}
V_186 . V_793 = 1 ;
V_100 = F_450 ( & V_726 ) ;
if ( V_100 ) {
F_8 ( L_478 ) ;
F_439 () ;
return V_100 ;
}
V_186 . V_792 = 1 ;
V_100 = F_99 ( & V_791 . V_81 ) ;
if ( ! V_100 ) {
V_186 . V_790 = 1 ;
V_100 = F_99 (
& V_726 . V_81 ) ;
}
if ( V_100 ) {
F_8 ( L_479 ) ;
F_439 () ;
return V_100 ;
}
V_186 . V_789 = 1 ;
V_154 = F_451 ( V_799 , - 1 ,
NULL , 0 ) ;
if ( F_147 ( V_154 ) ) {
V_100 = F_332 ( V_154 ) ;
V_154 = NULL ;
F_8 ( L_480 ) ;
F_439 () ;
return V_100 ;
}
V_556 = F_451 (
V_800 ,
- 1 , NULL , 0 ) ;
if ( F_147 ( V_556 ) ) {
V_100 = F_332 ( V_556 ) ;
V_556 = NULL ;
F_8 ( L_481 ) ;
F_439 () ;
return V_100 ;
}
V_100 = F_284 ( & V_556 -> V_60 , & V_788 ) ;
if ( V_100 ) {
F_8 ( L_482 ) ;
F_439 () ;
return V_100 ;
}
V_186 . V_787 = 1 ;
V_786 = F_452 ( & V_556 -> V_60 ) ;
if ( F_147 ( V_786 ) ) {
V_100 = F_332 ( V_786 ) ;
V_786 = NULL ;
F_8 ( L_483 ) ;
F_439 () ;
return V_100 ;
}
F_189 ( & V_211 ) ;
V_212 = F_453 () ;
if ( ! V_212 ) {
F_439 () ;
return - V_84 ;
} else {
V_212 -> V_51 = L_484 ;
V_212 -> V_801 = V_799 L_485 ;
V_212 -> V_144 . V_802 = V_803 ;
V_212 -> V_144 . V_6 = V_7 . V_6 ;
V_212 -> V_144 . V_804 = V_805 ;
V_212 -> V_144 . V_806 = V_807 ;
V_212 -> V_60 . V_52 = & V_154 -> V_60 ;
}
F_328 () ;
for ( V_42 = 0 ; V_42 < F_100 ( V_782 ) ; V_42 ++ ) {
V_100 = F_424 ( & V_782 [ V_42 ] ) ;
if ( V_100 >= 0 && * V_782 [ V_42 ] . V_783 )
V_100 = V_782 [ V_42 ] . V_66 -> V_101 ( V_782 [ V_42 ] . V_783 ) ;
if ( V_100 < 0 ) {
F_439 () ;
return V_100 ;
}
}
V_69 = V_70 ;
V_100 = F_454 ( V_212 ) ;
if ( V_100 < 0 ) {
F_8 ( L_486 ) ;
F_439 () ;
return V_100 ;
} else {
V_186 . V_785 = 1 ;
}
return 0 ;
}
