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
static void F_111 ( void )
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
static T_8 F_175 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_300 ;
V_300 = F_176 () ;
if ( V_300 < 0 )
return V_300 ;
return snprintf ( V_126 , V_102 , L_44 , V_300 ) ;
}
static T_8 F_177 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 ;
if ( F_57 ( V_126 , V_301 , & V_157 ) )
return - V_94 ;
V_17 = F_178 ( V_157 ) ;
return ( V_17 < 0 ) ? V_17 : V_35 ;
}
static void F_179 ( void )
{
int V_302 ;
V_302 = F_69 () ;
if ( V_302 == V_135 )
F_66 ( true ) ;
F_65 () ;
if ( V_302 == V_142 )
F_66 ( false ) ;
if ( ! ( V_302 < 0 ) ) {
F_115 ( & V_207 ) ;
F_122 ( V_208 ,
V_303 , ( V_302 > 0 ) ) ;
F_123 ( V_208 ) ;
F_118 ( & V_207 ) ;
}
F_167 () ;
}
static void F_180 ( void )
{
#ifdef F_116
F_115 ( & V_203 ) ;
F_144 () ;
F_118 ( & V_203 ) ;
#endif
if ( V_304 )
F_54 ( V_304 , & V_154 -> V_60 . V_125 ) ;
F_20 ( V_305 | V_306 ,
L_101 ) ;
if ( ( ( V_186 . V_189 &&
F_112 ( V_295 ) ) |
F_120 ( false ) ) != 0 )
F_8 ( L_102
L_103 ) ;
}
static void T_1 F_181 ( const unsigned int V_210 )
{
if ( V_212 [ V_210 ] != V_213 ) {
F_182 ( V_212 [ V_210 ] ,
V_208 -> V_307 ) ;
V_212 [ V_210 ] = V_213 ;
}
}
static int T_1 F_183 ( struct V_308 * V_309 )
{
enum T_15 {
V_310 = 0 ,
V_311 ,
};
static const T_16 V_312 [] V_313 = {
[ V_310 ] = {
V_314 , V_315 , V_316 , V_317 ,
V_318 , V_319 , V_320 , V_321 ,
V_322 , V_323 , V_324 , V_325 ,
V_326 ,
V_326 ,
V_326 ,
V_213 ,
V_213 ,
V_213 ,
V_326 ,
V_327 ,
V_213 ,
V_213 ,
V_213 ,
V_328 ,
V_326 , V_326 , V_326 , V_326 ,
V_326 , V_326 , V_326 , V_326 ,
V_326 , V_326 , V_326 , V_326 ,
V_326 , V_326 , V_326 , V_326 ,
V_326 , V_326 , V_326 , V_326 ,
V_326 , V_326 , V_326 , V_326 ,
V_326 , V_326 , V_326 ,
} ,
[ V_311 ] = {
V_314 , V_316 , V_315 , V_317 ,
V_318 , V_329 , V_320 , V_321 ,
V_322 , V_323 , V_324 , V_325 ,
V_326 ,
V_326 ,
V_326 ,
V_330 ,
V_331 ,
V_213 ,
V_326 ,
V_327 ,
V_213 ,
V_213 ,
V_213 ,
V_328 ,
V_326 , V_326 ,
V_332 ,
V_326 ,
V_333 , V_334 , V_335 , V_336 ,
V_213 ,
V_337 ,
V_213 ,
V_213 ,
V_213 ,
V_338 ,
V_213 ,
V_213 ,
V_213 ,
V_213 ,
V_213 ,
V_333 ,
V_213 ,
V_339 ,
V_340 ,
V_213 ,
V_213 ,
V_213 ,
V_213 ,
V_213 ,
} ,
} ;
static const struct V_3 V_341 [] V_313 = {
{
. V_6 = V_15 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_310 ,
} ,
{
. V_6 = V_14 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_311 ,
} ,
} ;
#define F_184 sizeof(tpacpi_keymap_t)
#define F_185 sizeof(tpacpi_keymap_entry_t)
int V_17 , V_42 ;
int V_30 ;
int V_342 ;
bool V_343 = false ;
bool V_344 = false ;
unsigned long V_13 ;
unsigned long V_345 ;
F_17 ( V_55 | V_306 ,
L_104 ) ;
F_25 ( ! V_208 ) ;
F_25 ( V_208 -> V_346 != NULL ||
V_208 -> V_347 != NULL ) ;
F_186 ( V_348 ) ;
F_187 ( & V_203 ) ;
#ifdef F_116
F_187 ( & V_280 ) ;
#endif
V_186 . V_202 = V_129 != NULL ;
F_17 ( V_55 | V_306 ,
L_105 ,
F_1 ( V_186 . V_202 ) ) ;
if ( ! V_186 . V_202 )
return 1 ;
if ( F_7 ( V_129 , & V_342 , L_106 , L_107 ) ) {
if ( ( V_342 >> 8 ) == 2 ) {
V_186 . V_349 = true ;
V_17 = F_188 ( & V_154 -> V_60 . V_125 ,
& V_350 ) ;
if ( V_17 )
goto V_351;
}
}
V_13 = F_4 ( V_352 ,
F_100 ( V_352 ) ) ;
F_60 () ;
V_304 = F_51 (
F_100 ( V_353 ) + 2 ,
NULL ) ;
if ( ! V_304 )
return - V_84 ;
V_17 = F_53 ( V_304 ,
V_353 ,
F_100 ( V_353 ) ) ;
if ( V_17 )
goto V_351;
if ( F_7 ( V_129 , & V_342 , L_106 , L_107 ) ) {
if ( ( V_342 >> 8 ) != 1 ) {
F_8 ( L_108 ,
V_342 ) ;
F_8 ( L_109 , V_354 ) ;
} else {
F_17 ( V_55 | V_306 ,
L_110 ,
V_342 ) ;
if ( ! F_7 ( V_129 , & V_191 ,
L_111 , L_107 ) ) {
F_8 ( L_112
L_109 ,
V_354 ) ;
V_191 = 0x080cU ;
} else {
V_186 . V_189 = 1 ;
}
}
}
F_17 ( V_55 | V_306 ,
L_113 ,
F_1 ( V_186 . V_189 ) ) ;
if ( ! V_186 . V_189 && ! V_191 &&
( V_13 & V_355 ) )
V_191 = 0x080cU ;
if ( V_186 . V_189 ) {
V_17 = F_110 () ;
if ( V_17 )
goto V_351;
V_295 = V_190 ;
} else {
V_295 = V_191 ;
V_190 = V_191 ;
}
#ifdef F_102
if ( V_172 ) {
V_186 . V_187 = 1 ;
V_343 = ! ! V_167 ;
F_76 ( L_114 ) ;
} else
#endif
if ( F_7 ( V_129 , & V_30 , L_63 , L_107 ) ) {
V_186 . V_187 = 1 ;
V_343 = ! ! V_30 ;
F_76 ( L_115 ,
F_189 ( V_30 , 0 ) ) ;
}
if ( V_186 . V_187 )
V_17 = F_52 ( V_304 ,
& V_356 . V_122 ) ;
if ( ! V_17 && F_7 ( V_129 , & V_30 , L_65 , L_107 ) ) {
V_186 . V_206 = 1 ;
V_344 = ! ! ( V_30 & V_188 ) ;
F_76 ( L_116
L_117 ,
( V_344 ) ? L_118 : L_119 ) ;
V_17 = F_52 ( V_304 ,
& V_357 . V_122 ) ;
}
if ( ! V_17 )
V_17 = F_190 (
V_304 ,
& V_154 -> V_60 . V_125 ) ;
if ( V_17 )
goto V_351;
V_212 = F_44 ( F_184 ,
V_83 ) ;
if ( ! V_212 ) {
F_8 ( L_120 ) ;
V_17 = - V_84 ;
goto V_351;
}
V_345 = F_4 ( V_341 ,
F_100 ( V_341 ) ) ;
F_25 ( V_345 >= F_100 ( V_312 ) ) ;
F_20 ( V_55 | V_306 ,
L_121 , V_345 ) ;
memcpy ( V_212 , & V_312 [ V_345 ] ,
F_184 ) ;
F_191 ( V_208 , V_214 , V_215 ) ;
V_208 -> V_358 = F_185 ;
V_208 -> V_359 = V_360 ;
V_208 -> V_211 = V_212 ;
for ( V_42 = 0 ; V_42 < V_360 ; V_42 ++ ) {
if ( V_212 [ V_42 ] != V_213 ) {
F_191 ( V_208 , V_361 ,
V_212 [ V_42 ] ) ;
} else {
if ( V_42 < sizeof( V_296 ) * 8 )
V_296 |= 1 << V_42 ;
}
}
if ( V_186 . V_187 ) {
F_191 ( V_208 , V_362 , V_303 ) ;
F_122 ( V_208 ,
V_303 , V_343 ) ;
}
if ( V_186 . V_206 ) {
F_191 ( V_208 , V_362 , V_209 ) ;
F_122 ( V_208 ,
V_209 , V_344 ) ;
}
if ( F_192 () != V_363 ) {
F_76 ( L_122
L_123
L_124 ) ;
F_32 ( L_125
L_126 ) ;
V_296 |=
( 1 << V_261 )
| ( 1 << V_260 ) ;
F_181 ( V_261 ) ;
F_181 ( V_260 ) ;
}
#ifdef F_116
V_193 = V_364
& ~ V_191
& ~ V_296 ;
F_17 ( V_55 | V_306 ,
L_127 ,
V_193 , V_282 ) ;
#endif
F_20 ( V_55 | V_306 ,
L_128 ) ;
V_17 = F_120 ( true ) ;
if ( V_17 ) {
F_180 () ;
return V_17 ;
}
V_17 = F_112 ( ( ( V_191 & ~ V_296 )
| V_195 )
& ~ V_193 ) ;
if ( V_17 < 0 && V_17 != - V_49 ) {
F_180 () ;
return V_17 ;
}
V_192 = ( V_190 | V_193 )
& ~ V_296 ;
F_17 ( V_55 | V_306 ,
L_129 ,
V_192 , V_190 , V_193 ) ;
V_208 -> V_346 = & F_150 ;
V_208 -> V_347 = & F_152 ;
F_148 ( true ) ;
return 0 ;
V_351:
F_54 ( V_304 , & V_154 -> V_60 . V_125 ) ;
F_55 ( & V_154 -> V_60 . V_125 ,
& V_350 ) ;
V_304 = NULL ;
return ( V_17 < 0 ) ? V_17 : 1 ;
}
static int F_176 ( void )
{
int V_365 = 0 ;
if ( ! F_7 ( V_129 , & V_365 , L_130 , L_7 , 0 ) ) {
F_8 ( L_131 ) ;
return - V_50 ;
}
return V_365 ;
}
static int F_178 ( int V_366 )
{
if ( V_366 < 0 ||
V_366 > V_301 )
return - V_94 ;
if ( ! F_7 ( V_129 , NULL , L_132 , L_9 , V_366 ) ) {
F_8 ( L_133 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_193 ( int V_365 )
{
T_10 V_42 ;
T_10 V_367 = F_100 ( V_368 ) - 1 ;
for ( V_42 = 0 ; V_42 <= V_367 ; V_42 ++ ) {
if ( V_368 [ V_42 ] == V_365 )
break;
}
if ( V_42 >= V_367 )
V_42 = 0 ;
else
V_42 ++ ;
return V_368 [ V_42 ] ;
}
static bool F_194 ( unsigned int V_210 )
{
int V_300 = 0 ;
int V_366 = 0 ;
int V_211 ;
switch ( V_210 ) {
case V_369 :
if ( V_370 ) {
V_366 = V_371 ;
V_370 = false ;
} else {
V_300 = F_176 () ;
if ( V_300 < 0 )
return false ;
V_366 = F_193 (
V_300 ) ;
}
if ( F_178 ( V_366 ) < 0 )
return false ;
return true ;
case V_372 :
V_300 = F_176 () ;
if ( V_300 < 0 )
return false ;
V_371 = V_300 ;
V_370 = true ;
if ( F_178 ( V_373 ) < 0 )
return false ;
return true ;
default:
if ( V_210 < V_374 ||
V_210 >= V_374 + V_360 -
V_375 ) {
F_76 ( L_134 ,
V_210 ) ;
return false ;
}
V_211 = V_212 [ V_210 - V_374 + V_375 ] ;
if ( V_211 != V_213 ) {
F_115 ( & V_207 ) ;
F_126 ( V_208 , V_211 , 1 ) ;
F_123 ( V_208 ) ;
F_126 ( V_208 , V_211 , 0 ) ;
F_123 ( V_208 ) ;
F_118 ( & V_207 ) ;
}
return true ;
}
}
static bool F_195 ( const T_7 V_348 ,
bool * V_376 ,
bool * V_377 )
{
unsigned int V_210 = V_348 & 0xfff ;
* V_376 = true ;
* V_377 = false ;
if ( V_210 > 0 && V_210 <= V_360 ) {
V_210 -- ;
if ( ! ( V_193 & ( 1 << V_210 ) ) ) {
F_127 ( V_210 ) ;
* V_376 = false ;
} else {
* V_377 = true ;
}
return true ;
} else {
return F_194 ( V_210 ) ;
}
return false ;
}
static bool F_196 ( const T_7 V_348 ,
bool * V_376 ,
bool * V_377 )
{
* V_376 = true ;
* V_377 = false ;
switch ( V_348 ) {
case V_378 :
case V_379 :
V_298 = V_380 ;
* V_377 = true ;
break;
case V_381 :
case V_382 :
V_298 = V_383 ;
* V_377 = true ;
break;
case V_384 :
case V_385 :
F_197 ( L_135 ) ;
break;
default:
return false ;
}
if ( V_298 != V_386 ) {
F_76 ( L_136 ) ;
F_172 () ;
}
return true ;
}
static bool F_198 ( const T_7 V_348 ,
bool * V_376 ,
bool * V_377 )
{
* V_376 = true ;
* V_377 = false ;
switch ( V_348 ) {
case V_387 :
V_299 = 1 ;
F_76 ( L_137 ) ;
F_174 () ;
return true ;
case V_388 :
F_76 ( L_138 ) ;
return true ;
case V_389 :
F_76 ( L_139 ) ;
return true ;
default:
return false ;
}
}
static bool F_199 ( const T_7 V_348 ,
bool * V_376 ,
bool * V_377 )
{
* V_376 = true ;
* V_377 = false ;
switch ( V_348 ) {
case V_390 :
case V_391 :
return true ;
case V_392 :
case V_393 :
F_121 () ;
F_170 () ;
* V_376 = false ;
return true ;
case V_394 :
case V_395 :
case V_396 :
* V_377 = true ;
return true ;
default:
return false ;
}
}
static bool F_200 ( const T_7 V_348 ,
bool * V_376 ,
bool * V_377 )
{
bool V_397 = true ;
* V_376 = true ;
* V_377 = false ;
switch ( V_348 ) {
case V_398 :
F_76 ( L_140 ) ;
return true ;
case V_399 :
F_201 ( L_141 ) ;
break;
case V_400 :
F_197 ( L_142 ) ;
break;
case V_401 :
F_201 ( L_143
L_144 ) ;
break;
case V_402 :
F_197 ( L_145
L_146 ) ;
break;
case V_403 :
case V_404 :
case V_405 :
case V_406 :
* V_376 = false ;
* V_377 = true ;
return true ;
default:
F_62 ( L_147 ) ;
V_397 = false ;
}
F_202 () ;
return V_397 ;
}
static void F_203 ( struct V_67 * V_68 , T_7 V_65 )
{
T_7 V_348 ;
bool V_376 ;
bool V_377 ;
bool V_407 ;
if ( V_65 != 0x80 ) {
F_8 ( L_148 , V_65 ) ;
F_204 (
V_68 -> V_71 -> V_74 -> V_408 . V_409 ,
F_205 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , 0 ) ;
return;
}
while ( 1 ) {
if ( ! F_7 ( V_129 , & V_348 , L_149 , L_64 ) ) {
F_8 ( L_150 ) ;
return;
}
if ( V_348 == 0 ) {
return;
}
V_376 = true ;
V_377 = false ;
switch ( V_348 >> 12 ) {
case 1 :
V_407 = F_195 ( V_348 , & V_376 ,
& V_377 ) ;
break;
case 2 :
V_407 = F_196 ( V_348 , & V_376 ,
& V_377 ) ;
break;
case 3 :
switch ( V_348 ) {
case V_410 :
V_299 = 1 ;
F_76 ( L_151 ) ;
F_174 () ;
V_407 = true ;
break;
case V_411 :
V_407 = true ;
break;
default:
V_407 = false ;
}
break;
case 4 :
V_407 = F_198 ( V_348 , & V_376 ,
& V_377 ) ;
break;
case 5 :
V_407 = F_199 ( V_348 , & V_376 ,
& V_377 ) ;
break;
case 6 :
V_407 = F_200 ( V_348 , & V_376 ,
& V_377 ) ;
break;
case 7 :
if ( V_186 . V_187 &&
V_348 == V_412 ) {
F_179 () ;
V_376 = 0 ;
V_407 = true ;
break;
}
default:
V_407 = false ;
}
if ( ! V_407 ) {
F_32 ( L_152 , V_348 ) ;
F_32 ( L_153
L_154 , V_354 ) ;
}
if ( ! V_377 && V_376 ) {
F_204 (
V_68 -> V_71 -> V_74 -> V_408 . V_409 ,
F_205 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , V_348 ) ;
}
}
}
static void F_206 ( void )
{
V_298 = V_386 ;
V_299 = 0 ;
if ( V_186 . V_349 ) {
if ( ! F_7 ( V_129 , & V_371 ,
L_130 , L_7 , 0 ) ) {
F_8 ( L_155 ) ;
}
}
}
static void F_207 ( void )
{
F_60 () ;
if ( F_120 ( true ) < 0 ||
F_112 ( V_190 ) < 0 )
F_8 ( L_156
L_157 ) ;
F_179 () ;
F_170 () ;
F_172 () ;
F_174 () ;
F_148 ( false ) ;
if ( V_186 . V_349 ) {
if ( ! F_7 ( V_129 , NULL , L_132 , L_9 ,
V_371 ) ) {
F_8 ( L_158 ) ;
}
}
}
static int F_208 ( struct V_90 * V_91 )
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
F_84 ( V_91 , L_47 , F_189 ( V_30 , 0 ) ) ;
if ( V_191 ) {
F_84 ( V_91 , L_159 , V_192 ) ;
F_84 ( V_91 , L_160 ) ;
} else {
F_84 ( V_91 , L_161 ) ;
F_84 ( V_91 , L_162 ) ;
}
return 0 ;
}
static void F_209 ( bool V_204 )
{
F_2 ( L_163 ) ;
if ( ! F_210 ( ( V_69 == V_70 || ! V_204 ) ,
F_211 ( L_164
L_165
L_166 ) ) )
F_8 ( L_167
L_168
L_166 ) ;
}
static int F_212 ( char * V_126 )
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
F_209 ( 1 ) ;
} else if ( F_86 ( V_159 , L_52 ) == 0 ) {
F_209 ( 0 ) ;
V_17 = - V_158 ;
} else if ( F_86 ( V_159 , L_169 ) == 0 ) {
V_197 = ( V_191 | V_193 )
& ~ V_296 ;
} else if ( sscanf ( V_159 , L_170 , & V_197 ) == 1 ) {
} else if ( sscanf ( V_159 , L_171 , & V_197 ) == 1 ) {
} else {
V_17 = - V_94 ;
goto V_413;
}
}
if ( ! V_17 ) {
F_82 ( L_172 ,
L_173 , V_197 ) ;
V_17 = F_113 ( V_197 ) ;
}
V_413:
F_118 ( & V_203 ) ;
return V_17 ;
}
static int F_213 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_174 )
return ( V_168 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_174 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_414 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_214 ( enum V_415 V_205 )
{
int V_30 ;
F_17 ( V_140 ,
L_175 ,
( V_205 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_174 ) {
V_168 = ( V_205 == V_142 ) ;
return 0 ;
}
#endif
if ( V_205 == V_142 )
V_30 = V_414
| V_416 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_176 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_215 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_417 ,
V_122 , V_126 ) ;
}
static T_8 F_216 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_417 ,
V_122 , V_126 , V_35 ) ;
}
static void F_217 ( void )
{
if ( ! F_7 ( NULL , NULL , L_177 , L_9 ,
V_418 ) )
F_32 ( L_178 ) ;
else
F_17 ( V_140 ,
L_179 ) ;
}
static void F_218 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_419 ) ;
F_77 ( V_417 ) ;
F_217 () ;
}
static int T_1 F_219 ( struct V_308 * V_309 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_180 ) ;
F_186 ( V_348 ) ;
V_186 . V_420 = V_129 &&
F_7 ( V_129 , & V_30 , L_174 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_181 ,
F_1 ( V_186 . V_420 ) ,
V_30 ) ;
#ifdef F_102
if ( V_174 ) {
V_186 . V_420 = 1 ;
F_76 ( L_182 ) ;
} else
#endif
if ( V_186 . V_420 &&
! ( V_30 & V_421 ) ) {
V_186 . V_420 = 0 ;
F_20 ( V_55 | V_140 ,
L_183 ) ;
}
if ( ! V_186 . V_420 )
return 1 ;
V_17 = F_71 ( V_417 ,
& V_422 ,
V_423 ,
V_424 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_188 ( & V_154 -> V_60 . V_125 ,
& V_419 ) ;
if ( V_17 ) {
F_77 ( V_417 ) ;
return V_17 ;
}
return 0 ;
}
static int F_220 ( struct V_90 * V_91 )
{
return F_83 ( V_417 , V_91 ) ;
}
static int F_221 ( char * V_126 )
{
return F_85 ( V_417 , V_126 ) ;
}
static int F_222 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_176 )
return ( V_169 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_184 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_425 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_223 ( enum V_415 V_205 )
{
int V_30 ;
F_17 ( V_140 ,
L_185 ,
( V_205 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_176 ) {
V_169 = ( V_205 == V_142 ) ;
return 0 ;
}
#endif
if ( V_205 == V_142 )
V_30 = V_425
| V_426 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_186 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_224 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_427 ,
V_122 , V_126 ) ;
}
static T_8 F_225 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_427 ,
V_122 , V_126 , V_35 ) ;
}
static void F_226 ( void )
{
if ( ! F_7 ( NULL , NULL , L_187 , L_9 ,
V_428 ) )
F_32 ( L_188 ) ;
else
F_17 ( V_140 ,
L_189 ) ;
}
static void F_227 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_429 ) ;
F_77 ( V_427 ) ;
F_226 () ;
}
static int T_1 F_228 ( struct V_308 * V_309 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_190 ) ;
F_186 ( V_348 ) ;
V_186 . V_430 = V_129 &&
F_7 ( V_129 , & V_30 , L_184 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_191 ,
F_1 ( V_186 . V_430 ) ,
V_30 ) ;
#ifdef F_102
if ( V_176 ) {
V_186 . V_430 = 1 ;
F_76 ( L_192 ) ;
} else
#endif
if ( V_186 . V_430 &&
! ( V_30 & V_431 ) ) {
V_186 . V_430 = 0 ;
F_20 ( V_55 | V_140 ,
L_193 ) ;
}
if ( ! V_186 . V_430 )
return 1 ;
V_17 = F_71 ( V_427 ,
& V_432 ,
V_433 ,
V_434 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_188 ( & V_154 -> V_60 . V_125 ,
& V_429 ) ;
if ( V_17 ) {
F_77 ( V_427 ) ;
return V_17 ;
}
return 0 ;
}
static int F_229 ( struct V_90 * V_91 )
{
return F_83 ( V_427 , V_91 ) ;
}
static int F_230 ( char * V_126 )
{
return F_85 ( V_427 , V_126 ) ;
}
static int F_231 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_178 )
return ( V_170 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_194 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_435 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_232 ( enum V_415 V_205 )
{
int V_30 ;
F_17 ( V_140 ,
L_195 ,
( V_205 == V_142 ) ? L_51 : L_52 ) ;
#ifdef F_102
if ( V_178 ) {
V_170 = ( V_205 == V_142 ) ;
return 0 ;
}
#endif
if ( V_205 == V_142 )
V_30 = V_435 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_196 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static void F_233 ( void )
{
F_77 ( V_436 ) ;
}
static int T_1 F_234 ( struct V_308 * V_309 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_197 ) ;
F_186 ( V_348 ) ;
V_186 . V_437 = V_129 &&
F_7 ( V_129 , & V_30 , L_194 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_198 ,
F_1 ( V_186 . V_437 ) ,
V_30 ) ;
#ifdef F_102
if ( V_178 ) {
V_186 . V_437 = 1 ;
F_76 ( L_199 ) ;
} else
#endif
if ( V_186 . V_437 &&
! ( V_30 & V_438 ) ) {
V_186 . V_437 = 0 ;
F_20 ( V_55 ,
L_200 ) ;
}
if ( ! V_186 . V_437 )
return 1 ;
V_17 = F_71 ( V_436 ,
& V_439 ,
V_440 ,
V_441 ,
false ) ;
return V_17 ;
}
static int T_1 F_235 ( struct V_308 * V_309 )
{
int V_442 ;
F_17 ( V_55 , L_201 ) ;
F_186 ( V_443 ) ;
if ( F_6 () )
F_186 ( V_444 ) ;
if ( V_445 && F_7 ( NULL , & V_442 , L_202 , L_64 ) && V_442 )
V_446 = V_445 ;
if ( ! V_446 )
V_447 = V_448 ;
else if ( F_6 () &&
F_7 ( V_446 , & V_449 , L_203 , L_107 ) )
V_447 = V_450 ;
else if ( F_6 () &&
F_7 ( V_446 , & V_449 , L_204 , L_107 ) )
V_447 = V_451 ;
else
V_447 = V_452 ;
F_17 ( V_55 , L_205 ,
F_1 ( V_447 != V_448 ) ,
V_447 ) ;
return ( V_447 != V_448 ) ? 0 : 1 ;
}
static void F_236 ( void )
{
F_20 ( V_305 ,
L_206 ) ;
if ( F_237 ( V_449 ) )
F_8 ( L_207
L_208 ) ;
}
static int F_238 ( void )
{
int V_30 = 0 ;
int V_42 ;
switch ( V_447 ) {
case V_450 :
if ( ! F_7 ( NULL , & V_42 , L_209 , L_7 ,
V_453 ) )
return - V_50 ;
V_30 = V_42 & V_454 ;
break;
case V_451 :
if ( ! F_7 ( NULL , & V_42 , L_210 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_455 ;
if ( ! F_7 ( NULL , & V_42 , L_211 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_456 ;
break;
case V_452 :
if ( ! F_7 ( NULL , NULL , L_212 , L_9 , 1 ) ||
! F_7 ( NULL , & V_42 , L_211 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_456 ;
if ( ! F_7 ( NULL , NULL , L_212 , L_9 , 0 ) ||
! F_7 ( NULL , & V_42 , L_210 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_455 ;
if ( ! F_7 ( NULL , & V_42 , L_213 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_457 ;
break;
default:
return - V_458 ;
}
return V_30 ;
}
static int F_239 ( int V_30 )
{
int V_459 ;
int V_17 = 0 ;
switch ( V_447 ) {
case V_450 :
V_17 = F_7 ( NULL , NULL ,
L_214 , L_8 ,
V_460 ,
V_30 | V_461 ) ;
break;
case V_451 :
V_459 = F_240 () ;
if ( V_459 < 0 )
return V_459 ;
V_17 = F_237 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_446 , NULL ,
L_215 , L_8 , V_30 * 0x100 , 0 ) ;
if ( ! V_459 && F_237 ( V_459 ) ) {
F_8 ( L_216 ) ;
return - V_50 ;
}
break;
case V_452 :
V_17 = F_7 ( NULL , NULL , L_212 , L_9 , 0x80 ) &&
F_7 ( NULL , NULL , L_217 , L_8 , V_30 , 1 ) ;
break;
default:
return - V_458 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_240 ( void )
{
int V_459 = 0 ;
switch ( V_447 ) {
case V_450 :
if ( ! F_7 ( V_446 , & V_459 , L_203 , L_64 ) )
return - V_50 ;
break;
case V_451 :
case V_452 :
if ( ! F_7 ( V_446 , & V_459 , L_218 , L_64 ) )
return - V_50 ;
break;
default:
return - V_458 ;
}
return V_459 & 1 ;
}
static int F_237 ( int V_204 )
{
if ( ! F_7 ( V_446 , NULL , L_219 , L_9 , ( V_204 ) ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static int F_241 ( void )
{
int V_459 = F_240 () ;
int V_17 ;
if ( V_459 < 0 )
return V_459 ;
switch ( V_447 ) {
case V_450 :
V_17 = F_237 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_462 , NULL , L_220 , L_221 ) ;
break;
case V_451 :
case V_452 :
V_17 = F_237 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_446 , NULL , L_222 , L_221 ) ;
break;
default:
return - V_458 ;
}
if ( ! V_459 && F_237 ( V_459 ) ) {
F_8 ( L_216 ) ;
return - V_50 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_242 ( void )
{
switch ( V_447 ) {
case V_450 :
return F_7 ( V_462 , NULL , L_223 , L_221 ) ?
0 : - V_50 ;
case V_451 :
return F_7 ( V_446 , NULL , L_224 , L_221 ) ?
0 : - V_50 ;
case V_452 :
return F_7 ( NULL , NULL , L_225 , L_221 ) ?
0 : - V_50 ;
default:
return - V_458 ;
}
}
static int F_243 ( struct V_90 * V_91 )
{
int V_30 , V_459 ;
if ( V_447 == V_448 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
if ( ! F_244 ( V_463 ) )
return - V_158 ;
V_30 = F_238 () ;
if ( V_30 < 0 )
return V_30 ;
V_459 = F_240 () ;
if ( V_459 < 0 )
return V_459 ;
F_84 ( V_91 , L_226 ) ;
F_84 ( V_91 , L_227 , F_189 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_228 , F_189 ( V_30 , 1 ) ) ;
if ( V_447 == V_452 )
F_84 ( V_91 , L_229 , F_189 ( V_30 , 3 ) ) ;
F_84 ( V_91 , L_230 , F_189 ( V_459 , 0 ) ) ;
F_84 ( V_91 , L_231 ) ;
F_84 ( V_91 , L_232 ) ;
if ( V_447 == V_452 )
F_84 ( V_91 , L_233 ) ;
F_84 ( V_91 , L_234 ) ;
F_84 ( V_91 , L_235 ) ;
return 0 ;
}
static int F_245 ( char * V_126 )
{
char * V_159 ;
int V_204 , V_464 , V_30 ;
int V_17 ;
if ( V_447 == V_448 )
return - V_75 ;
if ( ! F_244 ( V_463 ) )
return - V_158 ;
V_204 = 0 ;
V_464 = 0 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_236 ) == 0 ) {
V_204 |= V_455 ;
} else if ( F_86 ( V_159 , L_237 ) == 0 ) {
V_464 |= V_455 ;
} else if ( F_86 ( V_159 , L_238 ) == 0 ) {
V_204 |= V_456 ;
} else if ( F_86 ( V_159 , L_239 ) == 0 ) {
V_464 |= V_456 ;
} else if ( V_447 == V_452 &&
F_86 ( V_159 , L_240 ) == 0 ) {
V_204 |= V_457 ;
} else if ( V_447 == V_452 &&
F_86 ( V_159 , L_241 ) == 0 ) {
V_464 |= V_457 ;
} else if ( F_86 ( V_159 , L_242 ) == 0 ) {
V_17 = F_237 ( 1 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_243 ) == 0 ) {
V_17 = F_237 ( 0 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_244 ) == 0 ) {
V_17 = F_241 () ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_245 ) == 0 ) {
V_17 = F_242 () ;
if ( V_17 )
return V_17 ;
} else
return - V_94 ;
}
if ( V_204 || V_464 ) {
V_30 = F_238 () ;
if ( V_30 < 0 )
return V_30 ;
V_17 = F_239 ( ( V_30 & ~ V_464 ) | V_204 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_246 ( void )
{
int V_30 = 0 ;
if ( V_186 . V_465 ) {
if ( ! F_7 ( V_462 , & V_30 , L_246 , L_64 ) )
return - V_50 ;
return ( ! ! V_30 ) ;
}
return - V_49 ;
}
static int F_247 ( int V_30 )
{
int V_73 ;
if ( V_186 . V_466 ) {
if ( V_48 ) {
V_73 = F_7 ( V_48 , NULL , NULL , L_9 ,
( V_30 ) ?
V_467 :
V_468 ) ;
} else {
V_73 = F_7 ( V_469 , NULL , NULL , L_9 ,
( V_30 ) ? 1 : 0 ) ;
}
return ( V_73 ) ? 0 : - V_50 ;
}
return - V_49 ;
}
static void F_248 ( struct V_470 * V_471 )
{
struct V_472 * V_66 =
F_249 ( V_471 , struct V_472 , V_471 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_247 ( ( V_66 -> V_473 != V_474 ) ) ;
}
static void F_250 ( struct V_475 * V_476 ,
enum V_477 V_478 )
{
struct V_472 * V_66 =
F_249 ( V_476 ,
struct V_472 ,
V_475 ) ;
V_66 -> V_473 = ( V_478 != V_479 ) ?
V_480 : V_474 ;
F_251 ( V_481 , & V_66 -> V_471 ) ;
}
static enum V_477 F_252 ( struct V_475 * V_476 )
{
return ( F_246 () == 1 ) ? V_482 : V_479 ;
}
static int T_1 F_253 ( struct V_308 * V_309 )
{
int V_73 ;
F_17 ( V_55 , L_247 ) ;
if ( F_6 () ) {
F_186 ( V_483 ) ;
F_186 ( V_484 ) ;
}
F_186 ( V_485 ) ;
F_254 ( & V_486 . V_471 , F_248 ) ;
V_186 . V_466 = ( V_48 || V_469 ) && ! V_487 ;
if ( V_186 . V_466 )
V_186 . V_465 =
F_7 ( V_462 , NULL , L_246 , L_248 ) ;
F_17 ( V_55 , L_249 ,
F_1 ( V_186 . V_466 ) ,
F_1 ( V_186 . V_465 ) ) ;
if ( ! V_186 . V_466 )
return 1 ;
V_73 = F_255 ( & V_154 -> V_60 ,
& V_486 . V_475 ) ;
if ( V_73 < 0 ) {
V_186 . V_466 = 0 ;
V_186 . V_465 = 0 ;
} else {
V_73 = 0 ;
}
return V_73 ;
}
static void F_256 ( void )
{
F_257 ( & V_486 . V_475 ) ;
F_258 ( V_481 ) ;
}
static int F_259 ( struct V_90 * V_91 )
{
int V_30 ;
if ( ! V_186 . V_466 ) {
F_84 ( V_91 , L_46 ) ;
} else if ( ! V_186 . V_465 ) {
F_84 ( V_91 , L_250 ) ;
F_84 ( V_91 , L_251 ) ;
} else {
V_30 = F_246 () ;
if ( V_30 < 0 )
return V_30 ;
F_84 ( V_91 , L_47 , F_260 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_251 ) ;
}
return 0 ;
}
static int F_261 ( char * V_126 )
{
char * V_159 ;
int V_488 = 0 ;
if ( ! V_186 . V_466 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_252 ) == 0 ) {
V_488 = 1 ;
} else if ( F_86 ( V_159 , L_253 ) == 0 ) {
V_488 = 0 ;
} else
return - V_94 ;
}
return F_247 ( V_488 ) ;
}
static T_8 F_262 ( struct V_74 * V_60 ,
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
static int T_1 F_263 ( struct V_308 * V_309 )
{
int V_17 ;
F_17 ( V_55 ,
L_254 ) ;
F_186 ( V_485 ) ;
F_17 ( V_55 , L_255 ,
F_1 ( V_48 != NULL ) ) ;
V_17 = F_264 ( & V_154 -> V_60 , & V_489 ) ;
if ( V_17 )
return V_17 ;
return ( V_48 ) ? 0 : 1 ;
}
static void F_265 ( void )
{
F_266 ( & V_154 -> V_60 , & V_489 ) ;
}
static int F_267 ( struct V_90 * V_91 )
{
if ( ! V_48 )
F_84 ( V_91 , L_46 ) ;
else {
F_84 ( V_91 , L_226 ) ;
F_84 ( V_91 , L_256 ) ;
}
return 0 ;
}
static int F_268 ( char * V_126 )
{
char * V_159 ;
int V_47 , V_17 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_257 , & V_47 ) == 1 &&
V_47 >= 0 && V_47 <= 21 ) {
} else
return - V_94 ;
V_17 = F_15 ( V_47 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static inline bool F_269 ( const unsigned int V_490 )
{
#ifdef F_270
return false ;
#else
return ( 1U & ( V_491 >> V_490 ) ) == 0 ;
#endif
}
static int F_271 ( const unsigned int V_490 )
{
int V_30 ;
enum V_492 V_493 ;
switch ( V_494 ) {
case V_495 :
if ( ! F_7 ( V_462 ,
& V_30 , L_258 , L_7 , 1 << V_490 ) )
return - V_50 ;
V_493 = ( V_30 == 0 ) ?
V_474 :
( ( V_30 == 1 ) ?
V_480 :
V_496 ) ;
V_497 [ V_490 ] = V_493 ;
return V_493 ;
default:
return - V_49 ;
}
}
static int F_272 ( const unsigned int V_490 ,
const enum V_492 V_498 )
{
static const unsigned int V_499 [] = { 0 , 1 , 3 } ;
static const unsigned int V_500 [] = { 0 , 0x80 , 0xc0 } ;
int V_73 = 0 ;
switch ( V_494 ) {
case V_495 :
if ( F_142 ( V_490 > 7 ) )
return - V_94 ;
if ( F_142 ( F_269 ( V_490 ) ) )
return - V_158 ;
if ( ! F_7 ( V_501 , NULL , NULL , L_8 ,
( 1 << V_490 ) , V_499 [ V_498 ] ) )
V_73 = - V_50 ;
break;
case V_502 :
if ( F_142 ( V_490 > 7 ) )
return - V_94 ;
if ( F_142 ( F_269 ( V_490 ) ) )
return - V_158 ;
V_73 = F_14 ( V_503 , ( 1 << V_490 ) ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_504 ,
( V_498 == V_496 ) << V_490 ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_505 ,
( V_498 != V_474 ) << V_490 ) ;
break;
case V_506 :
if ( F_142 ( V_490 >= V_507 ) )
return - V_94 ;
if ( F_142 ( F_269 ( V_490 ) ) )
return - V_158 ;
if ( ! F_7 ( V_501 , NULL , NULL , L_8 ,
V_490 , V_500 [ V_498 ] ) )
V_73 = - V_50 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
V_497 [ V_490 ] = V_498 ;
return V_73 ;
}
static void F_273 ( struct V_470 * V_471 )
{
struct V_472 * V_66 =
F_249 ( V_471 , struct V_472 , V_471 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_272 ( V_66 -> V_490 , V_66 -> V_473 ) ;
}
static void F_274 ( struct V_475 * V_476 ,
enum V_477 V_478 )
{
struct V_472 * V_66 = F_249 ( V_476 ,
struct V_472 , V_475 ) ;
if ( V_478 == V_479 )
V_66 -> V_473 = V_474 ;
else if ( V_497 [ V_66 -> V_490 ] != V_496 )
V_66 -> V_473 = V_480 ;
else
V_66 -> V_473 = V_496 ;
F_251 ( V_481 , & V_66 -> V_471 ) ;
}
static int F_275 ( struct V_475 * V_476 ,
unsigned long * V_508 , unsigned long * V_509 )
{
struct V_472 * V_66 = F_249 ( V_476 ,
struct V_472 , V_475 ) ;
if ( * V_508 == 0 && * V_509 == 0 ) {
* V_508 = 500 ;
* V_509 = 500 ;
} else if ( ( * V_508 != 500 ) || ( * V_509 != 500 ) )
return - V_94 ;
V_66 -> V_473 = V_496 ;
F_251 ( V_481 , & V_66 -> V_471 ) ;
return 0 ;
}
static enum V_477 F_276 ( struct V_475 * V_476 )
{
int V_73 ;
struct V_472 * V_66 = F_249 ( V_476 ,
struct V_472 , V_475 ) ;
V_73 = F_271 ( V_66 -> V_490 ) ;
if ( V_73 == V_474 || V_73 < 0 )
V_73 = V_479 ;
else
V_73 = V_482 ;
return V_73 ;
}
static void F_277 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_507 ; V_42 ++ ) {
if ( V_510 [ V_42 ] . V_475 . V_51 )
F_257 ( & V_510 [ V_42 ] . V_475 ) ;
}
F_258 ( V_481 ) ;
F_37 ( V_510 ) ;
}
static int T_1 F_278 ( unsigned int V_490 )
{
int V_73 ;
V_510 [ V_490 ] . V_490 = V_490 ;
if ( ! V_511 [ V_490 ] )
return 0 ;
V_510 [ V_490 ] . V_475 . V_512 = & F_274 ;
V_510 [ V_490 ] . V_475 . V_513 = & F_275 ;
if ( V_494 == V_495 )
V_510 [ V_490 ] . V_475 . V_514 =
& F_276 ;
V_510 [ V_490 ] . V_475 . V_51 = V_511 [ V_490 ] ;
F_254 ( & V_510 [ V_490 ] . V_471 , F_273 ) ;
V_73 = F_255 ( & V_154 -> V_60 ,
& V_510 [ V_490 ] . V_475 ) ;
if ( V_73 < 0 )
V_510 [ V_490 ] . V_475 . V_51 = NULL ;
return V_73 ;
}
static enum V_515 T_1 F_279 ( void )
{
T_4 V_30 ;
if ( F_6 () ) {
V_30 = F_18 ( V_462 , L_259 , & V_501 ) ;
if ( F_19 ( V_30 ) )
return V_495 ;
V_30 = F_18 ( V_462 , L_260 , & V_501 ) ;
if ( F_19 ( V_30 ) )
return V_502 ;
}
V_30 = F_18 ( V_462 , L_261 , & V_501 ) ;
if ( F_19 ( V_30 ) )
return V_506 ;
V_501 = NULL ;
return V_516 ;
}
static int T_1 F_280 ( struct V_308 * V_309 )
{
unsigned int V_42 ;
int V_73 ;
unsigned long V_517 ;
F_17 ( V_55 , L_262 ) ;
V_494 = F_279 () ;
if ( V_494 != V_516 ) {
V_517 = F_4 ( V_518 ,
F_100 ( V_518 ) ) ;
if ( ! V_517 ) {
V_501 = NULL ;
V_494 = V_516 ;
}
}
F_17 ( V_55 , L_263 ,
F_1 ( V_494 ) , V_494 ) ;
if ( V_494 == V_516 )
return 1 ;
V_510 = F_35 ( sizeof( * V_510 ) * V_507 ,
V_83 ) ;
if ( ! V_510 ) {
F_8 ( L_264 ) ;
return - V_84 ;
}
for ( V_42 = 0 ; V_42 < V_507 ; V_42 ++ ) {
V_510 [ V_42 ] . V_490 = - 1 ;
if ( ! F_269 ( V_42 ) &&
F_281 ( V_42 , & V_517 ) ) {
V_73 = F_278 ( V_42 ) ;
if ( V_73 < 0 ) {
F_277 () ;
return V_73 ;
}
}
}
#ifdef F_270
F_32 ( L_265
L_266 ) ;
#endif
return 0 ;
}
static int F_282 ( struct V_90 * V_91 )
{
if ( ! V_494 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
F_84 ( V_91 , L_226 ) ;
if ( V_494 == V_495 ) {
int V_42 , V_30 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_30 = F_271 ( V_42 ) ;
if ( V_30 < 0 )
return - V_50 ;
F_84 ( V_91 , L_267 ,
V_42 , F_283 ( V_30 ) ) ;
}
}
F_84 ( V_91 , L_268
L_269 ) ;
return 0 ;
}
static int F_284 ( char * V_126 )
{
char * V_159 ;
int V_490 , V_73 ;
enum V_492 V_118 ;
if ( ! V_494 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_270 , & V_490 ) != 1 )
return - V_94 ;
if ( V_490 < 0 || V_490 > ( V_507 - 1 ) ||
V_510 [ V_490 ] . V_490 < 0 )
return - V_75 ;
if ( strstr ( V_159 , L_253 ) ) {
V_118 = V_474 ;
} else if ( strstr ( V_159 , L_252 ) ) {
V_118 = V_480 ;
} else if ( strstr ( V_159 , L_271 ) ) {
V_118 = V_496 ;
} else {
return - V_94 ;
}
V_73 = F_272 ( V_490 , V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
static int T_1 F_285 ( struct V_308 * V_309 )
{
unsigned long V_13 ;
F_17 ( V_55 , L_272 ) ;
F_186 ( V_519 ) ;
F_17 ( V_55 , L_273 ,
F_1 ( V_520 != NULL ) ) ;
V_13 = F_4 ( V_521 ,
F_100 ( V_521 ) ) ;
V_186 . V_522 = ! ! ( V_13 & V_523 ) ;
return ( V_520 ) ? 0 : 1 ;
}
static int F_286 ( struct V_90 * V_91 )
{
if ( ! V_520 )
F_84 ( V_91 , L_46 ) ;
else {
F_84 ( V_91 , L_226 ) ;
F_84 ( V_91 , L_274 ) ;
}
return 0 ;
}
static int F_287 ( char * V_126 )
{
char * V_159 ;
int V_524 ;
if ( ! V_520 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_257 , & V_524 ) == 1 &&
V_524 >= 0 && V_524 <= 17 ) {
} else
return - V_94 ;
if ( V_186 . V_522 ) {
if ( ! F_7 ( V_520 , NULL , NULL , L_8 ,
V_524 , 0 ) )
return - V_50 ;
} else {
if ( ! F_7 ( V_520 , NULL , NULL , L_9 ,
V_524 ) )
return - V_50 ;
}
}
return 0 ;
}
static int F_288 ( int V_525 , T_17 * V_38 )
{
int V_157 ;
T_18 V_526 ;
char V_527 [ 5 ] ;
V_157 = V_528 ;
switch ( V_529 ) {
#if V_530 >= 16
case V_531 :
if ( V_525 >= 8 && V_525 <= 15 ) {
V_157 = V_532 ;
V_525 -= 8 ;
}
#endif
case V_533 :
if ( V_525 <= 7 ) {
if ( ! F_11 ( V_157 + V_525 , & V_526 ) )
return - V_50 ;
* V_38 = V_526 * 1000 ;
return 0 ;
}
break;
case V_534 :
if ( V_525 <= 7 ) {
snprintf ( V_527 , sizeof( V_527 ) , L_275 , '0' + V_525 ) ;
if ( ! F_7 ( V_462 , NULL , L_276 , L_221 ) )
return - V_50 ;
if ( ! F_7 ( V_462 , & V_157 , V_527 , L_64 ) )
return - V_50 ;
* V_38 = ( V_157 - 2732 ) * 100 ;
return 0 ;
}
break;
case V_535 :
if ( V_525 <= 7 ) {
snprintf ( V_527 , sizeof( V_527 ) , L_275 , '0' + V_525 ) ;
if ( ! F_7 ( V_462 , & V_157 , V_527 , L_64 ) )
return - V_50 ;
if ( V_157 > 127 || V_157 < - 127 )
V_157 = V_536 ;
* V_38 = V_157 * 1000 ;
return 0 ;
}
break;
case V_537 :
default:
return - V_458 ;
}
return - V_94 ;
}
static int F_289 ( struct V_538 * V_118 )
{
int V_17 , V_42 ;
int V_217 ;
V_217 = 8 ;
V_42 = 0 ;
if ( ! V_118 )
return - V_94 ;
if ( V_529 == V_531 )
V_217 = 16 ;
for ( V_42 = 0 ; V_42 < V_217 ; V_42 ++ ) {
V_17 = F_288 ( V_42 , & V_118 -> V_539 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return V_217 ;
}
static void F_202 ( void )
{
int V_217 , V_42 ;
struct V_538 V_157 ;
V_217 = F_289 ( & V_157 ) ;
if ( V_217 <= 0 )
return;
F_32 ( L_277 ) ;
for ( V_42 = 0 ; V_42 < V_217 ; V_42 ++ ) {
if ( V_157 . V_539 [ V_42 ] != V_540 )
F_290 ( L_278 , ( int ) ( V_157 . V_539 [ V_42 ] / 1000 ) ) ;
else
F_290 ( L_279 ) ;
}
F_290 ( L_280 ) ;
}
static T_8 F_291 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
struct V_541 * V_542 =
F_292 ( V_122 ) ;
int V_525 = V_542 -> V_543 ;
T_17 V_38 ;
int V_17 ;
V_17 = F_288 ( V_525 , & V_38 ) ;
if ( V_17 )
return V_17 ;
if ( V_38 == V_540 )
return - V_49 ;
return snprintf ( V_126 , V_102 , L_44 , V_38 ) ;
}
static int T_1 F_293 ( struct V_308 * V_309 )
{
T_6 V_157 , V_544 , V_545 ;
int V_42 ;
int V_546 ;
int V_17 ;
F_17 ( V_55 , L_281 ) ;
V_546 = F_7 ( V_462 , NULL , L_282 , L_248 ) ;
if ( V_7 . V_12 ) {
V_544 = V_545 = 0 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( F_11 ( V_528 + V_42 , & V_157 ) ) {
V_544 |= V_157 ;
} else {
V_544 = 0 ;
break;
}
if ( F_11 ( V_532 + V_42 , & V_157 ) ) {
V_545 |= V_157 ;
} else {
V_544 = 0 ;
break;
}
}
if ( V_544 == 0 ) {
if ( V_546 ) {
F_8 ( L_283
L_284
L_285 ) ;
V_529 = V_535 ;
} else {
F_8 ( L_283
L_286 ) ;
V_529 = V_537 ;
}
} else {
V_529 =
( V_545 != 0 ) ?
V_531 : V_533 ;
}
} else if ( V_546 ) {
if ( F_6 () &&
F_7 ( V_462 , NULL , L_276 , L_248 ) ) {
V_529 = V_534 ;
} else {
V_529 = V_535 ;
}
} else {
V_529 = V_537 ;
}
F_17 ( V_55 , L_287 ,
F_1 ( V_529 != V_537 ) ,
V_529 ) ;
switch ( V_529 ) {
case V_531 :
V_17 = F_188 ( & V_547 -> V_60 . V_125 ,
& V_548 ) ;
if ( V_17 )
return V_17 ;
break;
case V_533 :
case V_535 :
case V_534 :
V_17 = F_188 ( & V_547 -> V_60 . V_125 ,
& V_549 ) ;
if ( V_17 )
return V_17 ;
break;
case V_537 :
default:
return 1 ;
}
return 0 ;
}
static void F_294 ( void )
{
switch ( V_529 ) {
case V_531 :
F_55 ( & V_547 -> V_60 . V_125 ,
& V_548 ) ;
break;
case V_533 :
case V_535 :
case V_534 :
F_55 ( & V_547 -> V_60 . V_125 ,
& V_549 ) ;
break;
case V_537 :
default:
break;
}
}
static int F_295 ( struct V_90 * V_91 )
{
int V_217 , V_42 ;
struct V_538 V_157 ;
V_217 = F_289 ( & V_157 ) ;
if ( F_142 ( V_217 < 0 ) )
return V_217 ;
F_84 ( V_91 , L_288 ) ;
if ( V_217 > 0 ) {
for ( V_42 = 0 ; V_42 < ( V_217 - 1 ) ; V_42 ++ )
F_84 ( V_91 , L_289 , V_157 . V_539 [ V_42 ] / 1000 ) ;
F_84 ( V_91 , L_44 , V_157 . V_539 [ V_42 ] / 1000 ) ;
} else
F_84 ( V_91 , L_290 ) ;
return 0 ;
}
static unsigned int F_296 ( void )
{
T_6 V_550 ;
V_550 = ( F_131 ( V_238 )
& V_240 )
>> V_241 ;
V_550 &= V_272 ;
return V_550 ;
}
static void F_297 ( void )
{
T_6 V_551 = 0 ;
T_6 V_552 ;
if ( V_553 != V_554 )
return;
F_17 ( V_555 ,
L_291 ) ;
if ( F_157 ( & V_556 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_557 , & V_551 ) ) )
goto V_558;
V_551 &= V_559 ;
V_552 = F_131 ( V_238 ) ;
if ( V_551 != ( ( V_552 & V_240 )
>> V_241 ) ) {
V_552 &= ~ ( V_240 <<
V_241 ) ;
V_552 |= V_551 ;
F_298 ( V_552 , V_238 ) ;
F_20 ( V_555 ,
L_292 ,
( unsigned int ) V_551 , ( unsigned int ) V_552 ) ;
} else
F_17 ( V_555 ,
L_293 ,
( unsigned int ) V_551 , ( unsigned int ) V_552 ) ;
V_558:
F_118 ( & V_556 ) ;
}
static int F_299 ( int * V_30 )
{
T_6 V_551 = 0 ;
switch ( V_553 ) {
case V_560 :
* V_30 = F_296 () ;
return 0 ;
case V_561 :
case V_554 :
if ( F_142 ( ! F_11 ( V_557 , & V_551 ) ) )
return - V_50 ;
* V_30 = V_551 ;
return 0 ;
default:
return - V_49 ;
}
}
static int F_300 ( unsigned int V_38 )
{
T_6 V_551 = 0 ;
if ( F_142 ( ! F_11 ( V_557 , & V_551 ) ) )
return - V_50 ;
if ( F_142 ( ! F_13 ( V_557 ,
( V_551 & V_562 ) |
( V_38 & V_559 ) ) ) )
return - V_50 ;
return 0 ;
}
static int F_301 ( unsigned int V_38 )
{
int V_47 , V_563 ;
unsigned int V_564 , V_42 ;
V_564 = F_296 () ;
if ( V_38 == V_564 )
return 0 ;
V_47 = ( V_38 > V_564 ) ?
V_565 :
V_566 ;
V_563 = ( V_38 > V_564 ) ? 1 : - 1 ;
for ( V_42 = V_564 ; V_42 != V_38 ; V_42 += V_563 )
if ( F_15 ( V_47 ) )
return - V_50 ;
return 0 ;
}
static int V_512 ( unsigned int V_38 )
{
int V_17 ;
if ( V_38 > V_272 )
return - V_94 ;
F_17 ( V_555 ,
L_294 , V_38 ) ;
V_17 = F_157 ( & V_556 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_553 ) {
case V_561 :
case V_554 :
V_17 = F_300 ( V_38 ) ;
break;
case V_560 :
V_17 = F_301 ( V_38 ) ;
break;
default:
V_17 = - V_49 ;
}
F_118 ( & V_556 ) ;
return V_17 ;
}
static int F_302 ( struct V_567 * V_568 )
{
unsigned int V_56 =
( V_568 -> V_569 . V_570 == V_571 &&
V_568 -> V_569 . V_572 == V_571 ) ?
V_568 -> V_569 . V_478 : 0 ;
F_20 ( V_555 ,
L_295 ,
V_56 ) ;
return V_512 ( V_56 ) ;
}
static int V_514 ( struct V_567 * V_568 )
{
int V_30 , V_17 ;
V_17 = F_157 ( & V_556 ) ;
if ( V_17 < 0 )
return 0 ;
V_17 = F_299 ( & V_30 ) ;
F_118 ( & V_556 ) ;
if ( V_17 < 0 )
return 0 ;
return V_30 & V_559 ;
}
static void F_303 ( void )
{
F_304 ( V_573 ,
V_574 ) ;
}
static int T_1 F_305 ( T_3 V_16 )
{
struct V_26 V_575 = { V_576 , NULL } ;
union V_23 * V_577 ;
struct V_59 * V_74 , * V_578 ;
int V_73 ;
if ( F_22 ( V_16 , & V_74 ) )
return 0 ;
V_73 = 0 ;
F_306 (child, &device->children, node) {
T_4 V_30 = F_9 ( V_578 -> V_16 , L_296 ,
NULL , & V_575 ) ;
if ( F_31 ( V_30 ) )
continue;
V_577 = (union V_23 * ) V_575 . V_36 ;
if ( ! V_577 || ( V_577 -> type != V_579 ) ) {
F_8 ( L_297 ,
V_354 ) ;
V_73 = 0 ;
} else {
V_73 = V_577 -> V_580 . V_35 ;
}
break;
}
F_37 ( V_575 . V_36 ) ;
return V_73 ;
}
static unsigned int T_1 F_307 ( void )
{
T_3 V_581 ;
int V_582 = 0 ;
F_24 ( L_13 , NULL , & V_581 ) ;
if ( V_581 )
V_582 = F_305 ( V_581 ) ;
V_186 . V_583 = ( V_582 > 0 ) ;
return ( V_582 > 2 ) ? ( V_582 - 2 ) : 0 ;
}
static void T_1 F_308 ( void )
{
unsigned int V_584 ;
F_17 ( V_55 ,
L_298 ) ;
V_584 = F_307 () ;
switch ( V_584 ) {
case 16 :
V_272 = 15 ;
F_76 ( L_299 ) ;
break;
case 8 :
case 0 :
V_272 = 7 ;
F_76 ( L_300 ) ;
break;
default:
F_76 ( L_301 ) ;
V_186 . V_273 = 1 ;
V_272 = V_584 - 1 ;
}
}
static int T_1 F_309 ( struct V_308 * V_309 )
{
struct V_585 V_569 ;
int V_584 ;
unsigned long V_13 ;
F_17 ( V_55 , L_302 ) ;
F_187 ( & V_556 ) ;
V_13 = F_4 ( V_586 ,
F_100 ( V_586 ) ) ;
if ( V_186 . V_273 )
return 1 ;
if ( ! V_587 ) {
F_20 ( V_55 | V_555 ,
L_303
L_304 ) ;
return 1 ;
}
if ( F_192 () != V_363 ) {
if ( V_587 > 1 ) {
F_76 ( L_305
L_306 ) ;
return 1 ;
} else if ( V_587 == 1 ) {
F_62 ( L_307
L_308
L_309 ) ;
return 1 ;
}
} else if ( V_186 . V_583 && V_587 > 1 ) {
F_32 ( L_310
L_311
L_312 ) ;
}
if ( V_553 > V_588 )
return - V_94 ;
if ( V_553 == V_589 ||
V_553 == V_588 ) {
if ( V_13 & V_590 )
V_553 = V_554 ;
else
V_553 = V_560 ;
F_20 ( V_555 ,
L_313 ,
V_553 ) ;
}
if ( ! F_6 () &&
( V_553 == V_554 ||
V_553 == V_561 ) )
return - V_94 ;
if ( F_299 ( & V_584 ) < 0 )
return 1 ;
memset ( & V_569 , 0 , sizeof( struct V_585 ) ) ;
V_569 . type = V_591 ;
V_569 . V_592 = V_272 ;
V_569 . V_478 = V_584 & V_559 ;
V_573 = F_310 ( V_593 ,
NULL , NULL ,
& V_594 ,
& V_569 ) ;
if ( F_147 ( V_573 ) ) {
int V_73 = F_311 ( V_573 ) ;
V_573 = NULL ;
F_8 ( L_314 ) ;
return V_73 ;
}
F_17 ( V_55 | V_555 ,
L_315 ) ;
if ( V_13 & V_595 ) {
F_32 ( L_316
L_317 , V_553 ) ;
F_32 ( L_318
L_319 , V_354 ) ;
}
F_312 ( V_573 ) ;
F_17 ( V_55 | V_555 ,
L_320
L_321 ) ;
F_114 ( V_195
| V_596
| V_597 ) ;
return 0 ;
}
static void F_313 ( void )
{
F_297 () ;
}
static void F_314 ( void )
{
F_297 () ;
}
static void F_315 ( void )
{
if ( V_573 ) {
F_17 ( V_305 | V_555 ,
L_322 ) ;
F_316 ( V_573 ) ;
}
F_297 () ;
}
static int F_317 ( struct V_90 * V_91 )
{
int V_56 ;
V_56 = V_514 ( NULL ) ;
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
static int F_318 ( char * V_126 )
{
int V_56 ;
int V_73 ;
char * V_159 ;
V_56 = V_514 ( NULL ) ;
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
V_73 = V_512 ( V_56 ) ;
if ( ! V_73 && V_573 )
F_304 ( V_573 ,
V_598 ) ;
return ( V_73 == - V_599 ) ? - V_294 : V_73 ;
}
static void F_319 ( void )
{
T_6 V_551 = 0 ;
T_6 V_552 ;
T_6 V_600 ;
if ( V_601 != V_602 )
return;
if ( ! V_603 )
return;
if ( V_604 )
return;
F_17 ( V_605 ,
L_332 ) ;
if ( V_186 . V_606 )
V_600 = V_607 ;
else
V_600 = V_607 | V_608 ;
if ( F_157 ( & V_609 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_610 , & V_551 ) ) )
goto V_558;
V_551 &= V_600 ;
V_552 = F_131 ( V_245 ) ;
if ( V_551 != ( V_552 & V_600 ) ) {
V_552 &= ~ V_600 ;
V_552 |= V_551 ;
F_298 ( V_552 , V_245 ) ;
F_20 ( V_605 ,
L_333 ,
( unsigned int ) V_551 , ( unsigned int ) V_552 ) ;
} else {
F_17 ( V_605 ,
L_334 ,
( unsigned int ) V_551 , ( unsigned int ) V_552 ) ;
}
V_558:
F_118 ( & V_609 ) ;
}
static int F_320 ( T_6 * V_30 )
{
T_6 V_118 ;
if ( ! F_11 ( V_610 , & V_118 ) )
return - V_50 ;
* V_30 = V_118 ;
F_20 ( V_605 , L_335 , V_118 ) ;
return 0 ;
}
static int F_321 ( T_6 * V_30 )
{
return F_320 ( V_30 ) ;
}
static int F_322 ( const T_6 V_30 )
{
if ( ! F_13 ( V_610 , V_30 ) )
return - V_50 ;
F_20 ( V_605 , L_336 , V_30 ) ;
F_323 ( 1 ) ;
return 0 ;
}
static int F_324 ( const T_6 V_30 )
{
return F_322 ( V_30 ) ;
}
static int F_325 ( const bool V_249 )
{
int V_73 ;
T_6 V_118 , V_217 ;
if ( F_157 ( & V_609 ) < 0 )
return - V_599 ;
V_73 = F_320 ( & V_118 ) ;
if ( V_73 )
goto V_558;
V_217 = ( V_249 ) ? V_118 | V_607 :
V_118 & ~ V_607 ;
if ( V_217 != V_118 ) {
V_73 = F_322 ( V_217 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_558:
F_118 ( & V_609 ) ;
return V_73 ;
}
static int F_326 ( const bool V_249 )
{
F_20 ( V_605 , L_337 ,
( V_249 ) ? L_1 : L_42 ) ;
return F_325 ( V_249 ) ;
}
static int F_327 ( const bool V_249 )
{
int V_73 ;
F_20 ( V_605 , L_338 ,
( V_249 ) ? L_1 : L_42 ) ;
V_73 = F_325 ( V_249 ) ;
return ( V_73 < 0 ) ? V_73 : 0 ;
}
static int F_328 ( const T_6 V_611 )
{
int V_73 ;
T_6 V_118 , V_217 ;
if ( V_611 > V_612 )
return - V_94 ;
if ( F_157 ( & V_609 ) < 0 )
return - V_599 ;
V_73 = F_320 ( & V_118 ) ;
if ( V_73 )
goto V_558;
V_217 = ( V_118 & ~ V_608 ) | V_611 ;
if ( V_217 != V_118 ) {
V_73 = F_322 ( V_217 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_558:
F_118 ( & V_609 ) ;
return V_73 ;
}
static int F_329 ( bool V_613 )
{
int V_27 ;
if ( ! F_5 () )
return - V_75 ;
if ( V_613 ) {
if ( ! F_7 ( V_462 , & V_614 ,
L_339 , L_107 ) )
return - V_50 ;
F_20 ( V_55 | V_605 ,
L_340 ,
V_614 ) ;
}
if ( ! F_7 ( V_462 , & V_27 , L_341 , L_342 ,
( int ) V_615 ) )
return - V_50 ;
if ( V_27 != V_615 )
F_62 ( L_343 ,
V_27 ) ;
if ( V_186 . V_606 )
V_27 = F_327 ( false ) ;
else
V_27 = F_324 ( V_612 ) ;
if ( V_27 != 0 )
F_62 ( L_344 ) ;
return 0 ;
}
static void F_330 ( void )
{
int V_616 ;
if ( ! F_7 ( V_462 , & V_616 , L_341 , L_342 , V_614 )
|| V_616 != V_614 )
F_62 ( L_345 ) ;
}
static int F_331 ( const T_6 V_611 )
{
F_20 ( V_605 ,
L_346 , V_611 ) ;
return F_328 ( V_611 ) ;
}
static void F_332 ( void )
{
struct V_617 * V_218 ;
if ( V_618 && V_618 -> V_619 ) {
V_218 = V_618 -> V_619 ;
if ( V_218 -> V_620 )
F_333 ( V_618 ,
V_621 ,
V_218 -> V_620 ) ;
if ( V_218 -> V_622 )
F_333 ( V_618 ,
V_621 ,
V_218 -> V_622 ) ;
}
}
static int F_334 ( struct V_623 * V_624 ,
struct V_625 * V_626 )
{
V_626 -> type = V_627 ;
V_626 -> V_35 = 1 ;
V_626 -> V_38 . integer . V_628 = 0 ;
V_626 -> V_38 . integer . V_127 = V_612 ;
return 0 ;
}
static int F_335 ( struct V_623 * V_624 ,
struct V_629 * V_630 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_321 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_630 -> V_38 . integer . V_38 [ 0 ] = V_118 & V_608 ;
return 0 ;
}
static int F_336 ( struct V_623 * V_624 ,
struct V_629 * V_630 )
{
F_82 ( L_347 , L_348 ,
V_630 -> V_38 . integer . V_38 [ 0 ] ) ;
return F_331 ( V_630 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static int F_337 ( struct V_623 * V_624 ,
struct V_629 * V_630 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_321 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_630 -> V_38 . integer . V_38 [ 0 ] =
( V_118 & V_607 ) ? 0 : 1 ;
return 0 ;
}
static int F_338 ( struct V_623 * V_624 ,
struct V_629 * V_630 )
{
F_82 ( L_347 , L_349 ,
V_630 -> V_38 . integer . V_38 [ 0 ] ?
L_42 : L_1 ) ;
return F_326 ( ! V_630 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static void F_339 ( void )
{
F_319 () ;
}
static void F_340 ( void )
{
if ( V_604 ) {
if ( F_329 ( false ) < 0 )
F_62 ( L_350 ) ;
} else {
F_332 () ;
}
}
static void F_341 ( void )
{
F_319 () ;
}
static void F_342 ( void )
{
if ( V_618 ) {
F_343 ( V_618 ) ;
V_618 = NULL ;
}
F_319 () ;
if ( V_604 )
F_330 () ;
}
static int T_1 F_344 ( void )
{
struct V_631 * V_632 ;
struct V_617 * V_66 ;
struct V_623 * V_633 ;
struct V_623 * V_634 ;
int V_73 ;
V_73 = F_345 ( & V_154 -> V_60 ,
V_635 , V_636 , V_637 ,
sizeof( struct V_617 ) , & V_632 ) ;
if ( V_73 < 0 || ! V_632 ) {
F_8 ( L_351 , V_73 ) ;
return 1 ;
}
F_25 ( ! V_632 -> V_619 ) ;
V_66 = V_632 -> V_619 ;
V_66 -> V_632 = V_632 ;
F_346 ( V_632 -> V_81 , V_638 ,
sizeof( V_632 -> V_81 ) ) ;
F_346 ( V_632 -> V_639 , V_640 ,
sizeof( V_632 -> V_639 ) ) ;
snprintf ( V_632 -> V_641 , sizeof( V_632 -> V_641 ) , L_352 ,
( V_7 . V_642 ) ?
V_7 . V_642 : L_353 ) ;
snprintf ( V_632 -> V_643 , sizeof( V_632 -> V_643 ) ,
L_354 , V_632 -> V_639 , V_610 ,
( V_7 . V_642 ) ?
V_7 . V_642 : L_355 ) ;
if ( V_603 ) {
V_644 . V_645 = F_336 ;
V_644 . V_646 =
V_647 ;
V_648 . V_645 = F_338 ;
V_648 . V_646 =
V_647 ;
}
if ( ! V_186 . V_606 ) {
V_633 = F_347 ( & V_644 , NULL ) ;
V_73 = F_348 ( V_632 , V_633 ) ;
if ( V_73 < 0 ) {
F_8 ( L_356 ,
V_73 ) ;
goto V_351;
}
V_66 -> V_622 = & V_633 -> V_144 ;
}
V_634 = F_347 ( & V_648 , NULL ) ;
V_73 = F_348 ( V_632 , V_634 ) ;
if ( V_73 < 0 ) {
F_8 ( L_357 , V_73 ) ;
goto V_351;
}
V_66 -> V_620 = & V_634 -> V_144 ;
V_73 = F_349 ( V_632 ) ;
if ( V_73 < 0 ) {
F_8 ( L_358 , V_73 ) ;
goto V_351;
}
V_618 = V_632 ;
return 0 ;
V_351:
F_343 ( V_632 ) ;
return 1 ;
}
static int T_1 F_350 ( struct V_308 * V_309 )
{
unsigned long V_13 ;
int V_73 ;
F_17 ( V_55 , L_359 ) ;
F_187 ( & V_609 ) ;
if ( V_601 > V_649 )
return - V_94 ;
if ( V_601 == V_650 ) {
F_8 ( L_360
L_361 , V_354 ) ;
return 1 ;
}
if ( V_651 >= V_652 )
return - V_94 ;
if ( ! V_653 ) {
F_17 ( V_55 | V_605 ,
L_362
L_363 ) ;
return 1 ;
}
V_13 = F_4 ( V_654 ,
F_100 ( V_654 ) ) ;
switch ( V_651 ) {
case V_655 :
if ( V_13 & V_656 )
V_186 . V_606 = 1 ;
else if ( V_13 & V_657 )
V_186 . V_606 = 0 ;
else
return 1 ;
break;
case V_658 :
V_186 . V_606 = 0 ;
break;
case V_659 :
V_186 . V_606 = 1 ;
break;
default:
return 1 ;
}
if ( V_651 != V_655 )
F_20 ( V_55 | V_605 ,
L_364 ,
V_651 ) ;
if ( V_601 == V_660 ||
V_601 == V_649 ) {
V_601 = V_602 ;
F_20 ( V_55 | V_605 ,
L_365 ,
V_601 ) ;
} else {
F_20 ( V_55 | V_605 ,
L_366 ,
V_601 ) ;
}
F_17 ( V_55 | V_605 ,
L_367 ,
F_1 ( ! V_186 . V_606 ) ) ;
if ( V_661 && F_329 ( true ) == 0 ) {
V_604 = true ;
} else {
V_73 = F_344 () ;
if ( V_73 ) {
F_8 ( L_368 ) ;
return V_73 ;
}
F_76 ( L_369 ,
( V_603 ) ?
L_370 :
L_371 ) ;
}
F_17 ( V_55 | V_605 ,
L_372 ) ;
F_114 ( V_195
| V_662
| V_663
| V_664 ) ;
return 0 ;
}
static int F_351 ( struct V_90 * V_91 )
{
T_6 V_30 ;
if ( F_321 ( & V_30 ) < 0 ) {
F_84 ( V_91 , L_323 ) ;
} else {
if ( V_186 . V_606 )
F_84 ( V_91 , L_373 ) ;
else
F_84 ( V_91 , L_324 ,
V_30 & V_608 ) ;
F_84 ( V_91 , L_374 ,
F_260 ( V_30 , V_665 ) ) ;
if ( V_603 ) {
F_84 ( V_91 , L_375 ) ;
if ( ! V_186 . V_606 ) {
F_84 ( V_91 ,
L_325 ) ;
F_84 ( V_91 ,
L_376
L_377 ,
V_612 ) ;
}
}
}
return 0 ;
}
static int F_352 ( char * V_126 )
{
T_6 V_118 ;
T_6 V_666 , V_667 ;
int V_668 ;
char * V_159 ;
int V_73 ;
if ( ! V_603 && V_69 != V_292 ) {
if ( F_142 ( ! V_200 . V_669 ) ) {
V_200 . V_669 = 1 ;
F_32 ( L_378
L_379 ) ;
F_32 ( L_380
L_381 ) ;
}
return - V_158 ;
}
V_73 = F_321 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_666 = V_118 & V_608 ;
V_667 = V_118 & V_607 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! V_186 . V_606 ) {
if ( F_86 ( V_159 , L_327 ) == 0 ) {
if ( V_667 )
V_667 = 0 ;
else if ( V_666 < V_612 )
V_666 ++ ;
continue;
} else if ( F_86 ( V_159 , L_328 ) == 0 ) {
if ( V_667 )
V_667 = 0 ;
else if ( V_666 > 0 )
V_666 -- ;
continue;
} else if ( sscanf ( V_159 , L_382 , & V_668 ) == 1 &&
V_668 >= 0 && V_668 <= V_612 ) {
V_666 = V_668 ;
continue;
}
}
if ( F_86 ( V_159 , L_383 ) == 0 )
V_667 = V_607 ;
else if ( F_86 ( V_159 , L_384 ) == 0 )
V_667 = 0 ;
else
return - V_94 ;
}
if ( V_186 . V_606 ) {
F_82 ( L_385 , L_349 ,
V_667 ? L_1 : L_42 ) ;
V_73 = F_327 ( ! ! V_667 ) ;
} else {
F_82 ( L_385 ,
L_386 ,
V_667 ? L_1 : L_42 , V_666 ) ;
V_73 = F_324 ( V_667 | V_666 ) ;
}
F_332 () ;
return ( V_73 == - V_599 ) ? - V_294 : V_73 ;
}
static void inline F_332 ( void )
{
}
static int T_1 F_350 ( struct V_308 * V_309 )
{
F_76 ( L_387 ) ;
return 1 ;
}
static void F_353 ( void )
{
if ( V_670 == 0x07 ) {
F_32 ( L_388
L_389 ) ;
V_186 . V_671 = 1 ;
}
}
static void F_354 ( T_6 * V_672 )
{
if ( F_142 ( V_186 . V_671 ) ) {
if ( * V_672 != V_670 ) {
V_186 . V_671 = 0 ;
} else {
* V_672 = V_673 ;
}
}
}
static bool F_355 ( void )
{
if ( V_186 . V_674 ) {
T_6 V_675 ;
if ( F_12 ( V_676 , & V_675 ) < 0 )
return false ;
V_675 &= 0xFEU ;
if ( F_14 ( V_676 , V_675 ) < 0 )
return false ;
}
return true ;
}
static bool F_356 ( void )
{
T_6 V_675 ;
if ( ! V_186 . V_674 )
return false ;
if ( F_12 ( V_676 , & V_675 ) < 0 )
return false ;
V_675 |= 0x01U ;
if ( F_14 ( V_676 , V_675 ) < 0 )
return false ;
return true ;
}
static void F_357 ( T_6 V_30 )
{
if ( ( V_30 &
( V_673 | V_677 ) ) == 0 ) {
if ( V_30 > 7 )
V_678 = 7 ;
else
V_678 = V_30 ;
}
}
static int F_358 ( T_6 * V_30 )
{
T_6 V_118 ;
switch ( V_679 ) {
case V_680 : {
int V_17 ;
if ( F_142 ( ! F_7 ( V_681 , & V_17 , NULL , L_64 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) )
* V_30 = V_17 & 0x07 ;
break;
}
case V_682 :
if ( F_142 ( ! F_11 ( V_683 , & V_118 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) ) {
* V_30 = V_118 ;
F_354 ( V_30 ) ;
}
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_359 ( T_6 * V_30 )
{
int V_73 ;
T_6 V_118 ;
if ( F_157 ( & V_684 ) )
return - V_294 ;
V_73 = F_358 ( & V_118 ) ;
if ( ! V_73 )
F_357 ( V_118 ) ;
F_118 ( & V_684 ) ;
if ( V_30 )
* V_30 = V_118 ;
return V_73 ;
}
static int F_360 ( unsigned int * V_685 )
{
T_6 V_686 , V_687 ;
switch ( V_679 ) {
case V_682 :
if ( F_142 ( ! F_355 () ) )
return - V_50 ;
if ( F_142 ( ! F_11 ( V_688 , & V_687 ) ||
! F_11 ( V_688 + 1 , & V_686 ) ) )
return - V_50 ;
if ( F_140 ( V_685 ) )
* V_685 = ( V_686 << 8 ) | V_687 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_361 ( unsigned int * V_685 )
{
T_6 V_686 , V_687 ;
bool V_73 ;
switch ( V_679 ) {
case V_682 :
if ( F_142 ( ! F_356 () ) )
return - V_50 ;
V_73 = ! F_11 ( V_688 , & V_687 ) ||
! F_11 ( V_688 + 1 , & V_686 ) ;
F_355 () ;
if ( V_73 )
return - V_50 ;
if ( F_140 ( V_685 ) )
* V_685 = ( V_686 << 8 ) | V_687 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_362 ( int V_56 )
{
if ( ! V_689 )
return - V_158 ;
switch ( V_690 ) {
case V_691 :
if ( V_56 >= 0 && V_56 <= 7 ) {
if ( ! F_7 ( V_692 , NULL , NULL , L_9 , V_56 ) )
return - V_50 ;
} else
return - V_94 ;
break;
case V_693 :
case V_694 :
if ( ! ( V_56 & V_673 ) &&
! ( V_56 & V_677 ) &&
( ( V_56 < 0 ) || ( V_56 > 7 ) ) )
return - V_94 ;
if ( V_56 & V_677 )
V_56 |= 7 ;
else if ( V_56 & V_673 )
V_56 |= 4 ;
if ( ! F_13 ( V_683 , V_56 ) )
return - V_50 ;
else
V_186 . V_671 = 0 ;
break;
default:
return - V_49 ;
}
F_17 ( V_695 ,
L_390 , V_56 ) ;
return 0 ;
}
static int F_363 ( int V_56 )
{
int V_73 ;
if ( ! V_689 )
return - V_158 ;
if ( F_157 ( & V_684 ) )
return - V_294 ;
if ( V_56 == V_696 )
V_56 = V_678 ;
V_73 = F_362 ( V_56 ) ;
if ( ! V_73 )
F_357 ( V_56 ) ;
F_118 ( & V_684 ) ;
return V_73 ;
}
static int F_364 ( void )
{
T_6 V_118 ;
int V_73 ;
if ( ! V_689 )
return - V_158 ;
if ( F_157 ( & V_684 ) )
return - V_294 ;
switch ( V_690 ) {
case V_693 :
case V_694 :
V_73 = F_358 ( & V_118 ) ;
if ( V_73 < 0 )
break;
if ( V_118 != 7 ) {
V_118 &= 0x07 ;
V_118 |= V_673 | 4 ;
}
if ( ! F_13 ( V_683 , V_118 ) )
V_73 = - V_50 ;
else {
V_186 . V_671 = 0 ;
V_73 = 0 ;
}
break;
case V_691 :
V_73 = F_358 ( & V_118 ) ;
if ( V_73 < 0 )
break;
V_118 &= 0x07 ;
V_118 |= 4 ;
if ( ! F_7 ( V_692 , NULL , NULL , L_9 , V_118 ) )
V_73 = - V_50 ;
else
V_73 = 0 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_684 ) ;
if ( ! V_73 )
F_17 ( V_695 ,
L_390 ,
V_118 ) ;
return V_73 ;
}
static int F_365 ( void )
{
int V_73 ;
if ( ! V_689 )
return - V_158 ;
if ( F_157 ( & V_684 ) )
return - V_294 ;
V_73 = 0 ;
switch ( V_690 ) {
case V_693 :
case V_694 :
if ( ! F_13 ( V_683 , 0x00 ) )
V_73 = - V_50 ;
else {
V_678 = 0 ;
V_186 . V_671 = 0 ;
}
break;
case V_691 :
if ( ! F_7 ( V_692 , NULL , NULL , L_9 , 0x00 ) )
V_73 = - V_50 ;
else
V_678 = 0 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
F_17 ( V_695 ,
L_391 ) ;
F_118 ( & V_684 ) ;
return V_73 ;
}
static int F_366 ( int V_685 )
{
int V_73 ;
if ( ! V_689 )
return - V_158 ;
if ( F_157 ( & V_684 ) )
return - V_294 ;
V_73 = 0 ;
switch ( V_690 ) {
case V_693 :
if ( V_685 >= 0 && V_685 <= 65535 ) {
if ( ! F_7 ( V_697 , NULL , NULL , L_392 ,
V_685 , V_685 , V_685 ) )
V_73 = - V_50 ;
} else
V_73 = - V_94 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_684 ) ;
return V_73 ;
}
static void F_367 ( void )
{
if ( V_690 == V_698 )
return;
if ( V_699 > 0 &&
V_69 != V_199 )
F_368 ( V_481 , & V_700 ,
F_369 ( V_699 * 1000 ) ) ;
else
F_370 ( & V_700 ) ;
}
static void F_371 ( struct V_470 * V_701 )
{
int V_73 ;
if ( V_69 != V_70 )
return;
F_32 ( L_393 ) ;
V_73 = F_364 () ;
if ( V_73 < 0 ) {
F_8 ( L_394
L_395 , - V_73 ) ;
F_367 () ;
}
}
static T_8 F_372 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_365 ;
T_6 V_30 ;
V_17 = F_359 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 & V_677 ) {
V_365 = 0 ;
} else if ( V_30 & V_673 ) {
V_365 = 2 ;
} else
V_365 = 1 ;
return snprintf ( V_126 , V_102 , L_44 , V_365 ) ;
}
static T_8 F_373 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 , V_56 ;
if ( F_57 ( V_126 , 2 , & V_157 ) )
return - V_94 ;
F_82 ( L_396 ,
L_397 , V_157 ) ;
switch ( V_157 ) {
case 0 :
V_56 = V_677 ;
break;
case 1 :
V_56 = V_696 ;
break;
case 2 :
V_56 = V_673 ;
break;
case 3 :
return - V_458 ;
default:
return - V_94 ;
}
V_17 = F_363 ( V_56 ) ;
if ( V_17 == - V_49 )
return - V_94 ;
else if ( V_17 < 0 )
return V_17 ;
F_367 () ;
return V_35 ;
}
static T_8 F_374 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
T_6 V_30 ;
V_17 = F_359 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_30 &
( V_673 | V_677 ) ) != 0 )
V_30 = V_678 ;
if ( V_30 > 7 )
V_30 = 7 ;
return snprintf ( V_126 , V_102 , L_398 , ( V_30 * 255 ) / 7 ) ;
}
static T_8 F_375 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_118 ;
int V_73 ;
T_6 V_30 , V_702 ;
if ( F_57 ( V_126 , 255 , & V_118 ) )
return - V_94 ;
F_82 ( L_399 ,
L_400 , V_118 ) ;
V_702 = ( V_118 >> 5 ) & 0x07 ;
if ( F_157 ( & V_684 ) )
return - V_294 ;
V_73 = F_358 ( & V_30 ) ;
if ( ! V_73 && ( V_30 &
( V_673 | V_677 ) ) == 0 ) {
V_73 = F_362 ( V_702 ) ;
if ( V_73 == - V_49 )
V_73 = - V_94 ;
else if ( ! V_73 ) {
F_357 ( V_702 ) ;
F_367 () ;
}
}
F_118 ( & V_684 ) ;
return ( V_73 ) ? V_73 : V_35 ;
}
static T_8 F_376 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_685 ;
V_17 = F_360 ( & V_685 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_398 , V_685 ) ;
}
static T_8 F_377 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_685 ;
V_17 = F_361 ( & V_685 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_398 , V_685 ) ;
}
static T_8 F_378 ( struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_398 , V_699 ) ;
}
static T_8 F_379 ( struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 120 , & V_157 ) )
return - V_94 ;
if ( ! V_689 )
return - V_158 ;
V_699 = V_157 ;
F_367 () ;
F_82 ( L_401 , L_96 , V_157 ) ;
return V_35 ;
}
static int T_1 F_380 ( struct V_308 * V_309 )
{
int V_73 ;
unsigned long V_13 ;
F_17 ( V_55 | V_695 ,
L_402 ) ;
F_187 ( & V_684 ) ;
V_679 = V_703 ;
V_690 = V_698 ;
V_704 = 0 ;
V_699 = 0 ;
V_186 . V_671 = 0 ;
V_186 . V_674 = 0 ;
V_678 = 7 ;
if ( F_6 () ) {
F_186 ( V_705 ) ;
F_186 ( V_706 ) ;
F_186 ( V_707 ) ;
}
V_13 = F_4 ( V_708 ,
F_100 ( V_708 ) ) ;
if ( V_681 ) {
V_679 = V_680 ;
} else {
if ( F_140 ( F_11 ( V_683 ,
& V_670 ) ) ) {
V_679 = V_682 ;
if ( V_13 & V_709 )
F_353 () ;
if ( V_13 & V_710 ) {
V_186 . V_674 = 1 ;
F_20 ( V_55 | V_695 ,
L_403 ) ;
}
} else {
F_8 ( L_283
L_404 ) ;
return 1 ;
}
}
if ( V_692 ) {
V_690 = V_691 ;
V_704 |=
V_711 | V_712 ;
} else {
if ( ! V_681 ) {
if ( V_697 ) {
V_690 =
V_693 ;
V_704 |=
V_713 |
V_711 |
V_712 ;
} else {
V_690 = V_694 ;
V_704 |=
V_711 |
V_712 ;
}
}
}
F_17 ( V_55 | V_695 ,
L_405 ,
F_1 ( V_679 != V_703 ||
V_690 != V_698 ) ,
V_679 , V_690 ) ;
if ( ! V_689 ) {
V_690 = V_698 ;
V_704 = 0 ;
F_20 ( V_55 | V_695 ,
L_406 ) ;
}
if ( V_679 != V_703 )
F_359 ( NULL ) ;
if ( V_679 != V_703 ||
V_690 != V_698 ) {
if ( V_186 . V_674 ) {
V_714 [ F_100 ( V_714 ) - 2 ] =
& V_715 . V_122 ;
}
V_73 = F_188 ( & V_547 -> V_60 . V_125 ,
& V_716 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_101 ( & V_717 . V_81 ,
& V_718 ) ;
if ( V_73 < 0 ) {
F_55 ( & V_547 -> V_60 . V_125 ,
& V_716 ) ;
return V_73 ;
}
return 0 ;
} else
return 1 ;
}
static void F_381 ( void )
{
F_17 ( V_305 | V_695 ,
L_407 ) ;
F_55 ( & V_547 -> V_60 . V_125 , & V_716 ) ;
F_104 ( & V_717 . V_81 ,
& V_718 ) ;
F_370 ( & V_700 ) ;
F_258 ( V_481 ) ;
}
static void F_382 ( void )
{
int V_73 ;
if ( ! V_689 )
return;
V_719 = 0 ;
V_73 = F_359 ( & V_719 ) ;
if ( V_73 < 0 )
F_32 ( L_408
L_409 , V_73 ) ;
if ( V_186 . V_671 )
V_719 = 0 ;
}
static void F_383 ( void )
{
T_6 V_720 = 7 ;
bool V_721 = false ;
int V_73 ;
V_186 . V_671 = 0 ;
if ( ! V_689 ||
! V_719 ||
( F_359 ( & V_720 ) < 0 ) )
return;
switch ( V_690 ) {
case V_691 :
V_721 = ( V_719 > V_720 ) ;
break;
case V_693 :
case V_694 :
if ( V_719 != 7 &&
! ( V_719 & V_677 ) )
return;
else
V_721 = ! ( V_720 & V_677 ) &&
( V_720 != V_719 ) ;
break;
default:
return;
}
if ( V_721 ) {
F_32 ( L_410 ,
V_719 ) ;
V_73 = F_363 ( V_719 ) ;
if ( V_73 < 0 )
F_32 ( L_411 , V_73 ) ;
}
}
static int F_384 ( struct V_90 * V_91 )
{
int V_73 ;
T_6 V_30 ;
unsigned int V_685 = 0 ;
switch ( V_679 ) {
case V_680 :
V_73 = F_359 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47
L_324 ,
( V_30 != 0 ) ? L_48 : L_49 , V_30 ) ;
break;
case V_682 :
V_73 = F_359 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47 ,
( V_30 != 0 ) ? L_48 : L_49 ) ;
V_73 = F_360 ( & V_685 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_412 , V_685 ) ;
if ( V_30 & V_677 )
F_84 ( V_91 , L_413 ) ;
else if ( V_30 & V_673 )
F_84 ( V_91 , L_414 ) ;
else
F_84 ( V_91 , L_324 , V_30 ) ;
break;
case V_703 :
default:
F_84 ( V_91 , L_46 ) ;
}
if ( V_704 & V_711 ) {
F_84 ( V_91 , L_376 ) ;
switch ( V_690 ) {
case V_691 :
F_84 ( V_91 , L_415 ) ;
break;
default:
F_84 ( V_91 , L_416
L_417 ) ;
break;
}
}
if ( V_704 & V_712 )
F_84 ( V_91 , L_50
L_418
L_419 ) ;
if ( V_704 & V_713 )
F_84 ( V_91 , L_420
L_421 ) ;
return 0 ;
}
static int F_385 ( const char * V_159 , int * V_73 )
{
int V_56 ;
if ( F_86 ( V_159 , L_422 ) == 0 )
V_56 = V_673 ;
else if ( ( F_86 ( V_159 , L_423 ) == 0 ) |
( F_86 ( V_159 , L_424 ) == 0 ) )
V_56 = V_677 ;
else if ( sscanf ( V_159 , L_329 , & V_56 ) != 1 )
return 0 ;
* V_73 = F_363 ( V_56 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_425 ,
V_690 ) ;
else if ( ! * V_73 )
F_82 ( L_426 ,
L_331 , V_56 ) ;
return 1 ;
}
static int F_386 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_51 ) != 0 )
return 0 ;
* V_73 = F_364 () ;
if ( * V_73 == - V_49 )
F_8 ( L_427 ,
V_690 ) ;
else if ( ! * V_73 )
F_82 ( L_426 , L_428 ) ;
return 1 ;
}
static int F_387 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_52 ) != 0 )
return 0 ;
* V_73 = F_365 () ;
if ( * V_73 == - V_49 )
F_8 ( L_429 ,
V_690 ) ;
else if ( ! * V_73 )
F_82 ( L_426 , L_430 ) ;
return 1 ;
}
static int F_388 ( const char * V_159 , int * V_73 )
{
int V_685 ;
if ( sscanf ( V_159 , L_431 , & V_685 ) != 1 )
return 0 ;
* V_73 = F_366 ( V_685 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_432 ,
V_690 ) ;
else if ( ! * V_73 )
F_82 ( L_426 ,
L_433 , V_685 ) ;
return 1 ;
}
static int F_389 ( const char * V_159 , int * V_73 )
{
int V_722 ;
if ( sscanf ( V_159 , L_434 , & V_722 ) != 1 )
return 0 ;
if ( V_722 < 0 || V_722 > 120 )
* V_73 = - V_94 ;
else {
V_699 = V_722 ;
F_82 ( L_426 ,
L_435 ,
V_722 ) ;
}
return 1 ;
}
static int F_390 ( char * V_126 )
{
char * V_159 ;
int V_73 = 0 ;
while ( ! V_73 && ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! ( ( V_704 & V_711 ) &&
F_385 ( V_159 , & V_73 ) ) &&
! ( ( V_704 & V_712 ) &&
( F_386 ( V_159 , & V_73 ) ||
F_387 ( V_159 , & V_73 ) ||
F_389 ( V_159 , & V_73 ) ) ) &&
! ( ( V_704 & V_713 ) &&
F_388 ( V_159 , & V_73 ) )
)
V_73 = - V_94 ;
else if ( ! V_73 )
F_367 () ;
}
return V_73 ;
}
static int F_391 ( struct V_723 * V_157 , bool V_205 )
{
T_3 V_539 ;
int V_724 ;
if ( ! F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_539 ) ) ) {
F_62 ( L_436 , V_157 -> V_51 ) ;
return - V_50 ;
}
if ( ! F_7 ( V_129 , & V_724 , V_157 -> V_51 , L_7 ,
V_205 ? V_157 -> V_725 : V_157 -> V_726 ) )
return - V_50 ;
V_157 -> V_205 = V_205 ;
return V_205 ;
}
int F_392 ( int V_727 , bool V_728 )
{
struct V_723 * V_157 ;
if ( V_727 < 0 || V_727 >= V_729 )
return - V_94 ;
V_157 = & V_730 [ V_727 ] ;
if ( V_157 -> V_205 < 0 || V_157 -> V_205 == V_728 )
return V_157 -> V_205 ;
return F_391 ( V_157 , V_728 ) ;
}
static int F_393 ( struct V_308 * V_309 )
{
T_3 V_539 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_729 ; V_42 ++ ) {
struct V_723 * V_157 = & V_730 [ V_42 ] ;
if ( F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_539 ) ) )
F_391 ( V_157 , false ) ;
else
V_157 -> V_205 = - V_75 ;
}
return 0 ;
}
static void F_394 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_729 ; V_42 ++ )
F_392 ( V_42 , false ) ;
}
static void F_395 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_729 ; V_42 ++ ) {
struct V_723 * V_157 = & V_730 [ V_42 ] ;
if ( V_157 -> V_205 >= 0 )
F_391 ( V_157 , V_157 -> V_205 ) ;
}
}
static void F_396 ( const unsigned int V_731 )
{
if ( V_573 ) {
switch ( V_731 ) {
case V_732 :
case V_733 :
F_303 () ;
}
}
if ( V_618 ) {
switch ( V_731 ) {
case V_734 :
case V_735 :
case V_736 :
F_332 () ;
}
}
}
static void F_128 ( const unsigned int V_210 )
{
F_396 ( V_737 + V_210 ) ;
}
static T_8 F_397 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_437 , V_85 ) ;
}
static const char * T_1 F_1 ( int V_1 )
{
static char V_738 [] V_739 = L_438 ;
return ( V_1 ) ? & V_738 [ 4 ] : & V_738 [ 0 ] ;
}
static void F_398 ( struct V_67 * V_68 )
{
F_20 ( V_305 , L_439 , V_68 -> V_51 ) ;
F_399 ( & V_68 -> V_740 ) ;
if ( V_68 -> V_79 . V_80 ) {
F_20 ( V_305 ,
L_440 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_400 ( * V_68 -> V_71 -> V_16 ,
V_68 -> V_71 -> type ,
F_27 ) ;
V_68 -> V_79 . V_80 = 0 ;
}
if ( V_68 -> V_79 . V_741 ) {
F_20 ( V_305 ,
L_441 , V_68 -> V_51 ) ;
F_401 ( V_68 -> V_51 , V_742 ) ;
V_68 -> V_79 . V_741 = 0 ;
}
if ( V_68 -> V_79 . V_89 ) {
F_20 ( V_305 ,
L_442 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_402 ( V_68 -> V_71 -> V_81 ) ;
F_37 ( V_68 -> V_71 -> V_81 ) ;
V_68 -> V_71 -> V_81 = NULL ;
V_68 -> V_79 . V_89 = 0 ;
}
if ( V_68 -> V_79 . V_743 && V_68 -> exit ) {
V_68 -> exit () ;
V_68 -> V_79 . V_743 = 0 ;
}
F_20 ( V_55 , L_443 , V_68 -> V_51 ) ;
}
static int T_1 F_403 ( struct V_308 * V_309 )
{
int V_100 ;
struct V_67 * V_68 = V_309 -> V_66 ;
struct V_744 * V_745 ;
F_25 ( V_68 == NULL ) ;
F_404 ( & V_68 -> V_740 ) ;
if ( V_68 -> V_79 . V_746 && ! V_746 )
return 0 ;
F_20 ( V_55 ,
L_444 , V_68 -> V_51 ) ;
if ( V_309 -> V_747 ) {
V_100 = V_309 -> V_747 ( V_309 ) ;
if ( V_100 > 0 )
return 0 ;
if ( V_100 )
return V_100 ;
V_68 -> V_79 . V_743 = 1 ;
}
if ( V_68 -> V_71 ) {
if ( V_68 -> V_71 -> V_63 ) {
V_100 = F_34 ( V_68 ) ;
if ( V_100 )
goto V_748;
}
if ( V_68 -> V_71 -> V_72 ) {
V_100 = F_28 ( V_68 ) ;
if ( V_100 == - V_75 ) {
F_32 ( L_445 ,
V_68 -> V_51 ) ;
V_100 = 0 ;
goto V_748;
}
if ( V_100 < 0 )
goto V_748;
}
}
F_20 ( V_55 ,
L_446 , V_68 -> V_51 ) ;
if ( V_68 -> V_93 ) {
T_19 V_365 = V_309 -> V_749 ;
if ( ! V_365 )
V_365 = V_750 ;
if ( V_68 -> V_101 )
V_365 |= V_751 ;
V_745 = F_405 ( V_68 -> V_51 , V_365 , V_742 ,
& V_752 , V_68 ) ;
if ( ! V_745 ) {
F_8 ( L_447 , V_68 -> V_51 ) ;
V_100 = - V_75 ;
goto V_748;
}
V_68 -> V_79 . V_741 = 1 ;
}
F_406 ( & V_68 -> V_740 , & V_753 ) ;
return 0 ;
V_748:
F_20 ( V_55 ,
L_448 ,
V_68 -> V_51 , V_100 ) ;
F_398 ( V_68 ) ;
return ( V_100 < 0 ) ? V_100 : 0 ;
}
static bool T_2 T_1 F_407 ( const char V_37 )
{
return ( V_37 >= '0' && V_37 <= '9' ) || ( V_37 >= 'A' && V_37 <= 'Z' ) ;
}
static bool T_2 T_1 F_408 ( const char * const V_118 ,
const char V_157 )
{
if ( V_118 && strlen ( V_118 ) >= 8 &&
F_407 ( V_118 [ 0 ] ) &&
F_407 ( V_118 [ 1 ] ) &&
V_118 [ 2 ] == V_157 &&
( V_118 [ 3 ] == 'T' || V_118 [ 3 ] == 'N' ) &&
F_407 ( V_118 [ 4 ] ) &&
F_407 ( V_118 [ 5 ] ) )
return true ;
return V_118 && strlen ( V_118 ) >= 8 &&
F_407 ( V_118 [ 0 ] ) &&
F_407 ( V_118 [ 1 ] ) &&
F_407 ( V_118 [ 2 ] ) &&
V_118 [ 3 ] == V_157 &&
( V_118 [ 4 ] == 'T' || V_118 [ 4 ] == 'N' ) &&
F_407 ( V_118 [ 5 ] ) &&
F_407 ( V_118 [ 6 ] ) ;
}
static int T_20 T_1 F_409 (
struct V_754 * V_755 )
{
const struct V_756 * V_60 = NULL ;
char V_757 [ 18 ] ;
char const * V_118 ;
if ( ! V_755 )
return - V_94 ;
memset ( V_755 , 0 , sizeof( * V_755 ) ) ;
if ( F_410 ( L_449 ) )
V_755 -> V_6 = V_15 ;
else if ( F_410 ( L_450 ) )
V_755 -> V_6 = V_14 ;
else
return 0 ;
V_118 = F_411 ( V_758 ) ;
V_755 -> V_759 = F_412 ( V_118 , V_83 ) ;
if ( V_118 && ! V_755 -> V_759 )
return - V_84 ;
if ( ! ( F_408 ( V_755 -> V_759 , 'E' ) ||
F_408 ( V_755 -> V_759 , 'C' ) ) )
return 0 ;
V_755 -> V_10 = V_755 -> V_759 [ 0 ]
| ( V_755 -> V_759 [ 1 ] << 8 ) ;
V_755 -> V_184 = ( V_755 -> V_759 [ 4 ] << 8 )
| V_755 -> V_759 [ 5 ] ;
while ( ( V_60 = F_413 ( V_760 , NULL , V_60 ) ) ) {
if ( sscanf ( V_60 -> V_51 ,
L_451 ,
V_757 ) == 1 ) {
V_757 [ sizeof( V_757 ) - 1 ] = 0 ;
V_757 [ strcspn ( V_757 , L_452 ) ] = 0 ;
V_755 -> V_642 = F_412 ( V_757 , V_83 ) ;
if ( ! V_755 -> V_642 )
return - V_84 ;
if ( F_408 ( V_757 , 'H' ) ) {
V_755 -> V_12 = V_757 [ 0 ]
| ( V_757 [ 1 ] << 8 ) ;
V_755 -> V_185 = ( V_757 [ 4 ] << 8 )
| V_757 [ 5 ] ;
} else {
F_32 ( L_453
L_454 ,
V_757 ) ;
F_32 ( L_109 ,
V_354 ) ;
}
break;
}
}
V_118 = F_411 ( V_761 ) ;
if ( V_118 && ! ( strncasecmp ( V_118 , L_455 , 8 ) && strncasecmp ( V_118 , L_456 , 6 ) ) ) {
V_755 -> V_762 = F_412 ( V_118 , V_83 ) ;
if ( ! V_755 -> V_762 )
return - V_84 ;
} else {
V_118 = F_411 ( V_763 ) ;
if ( V_118 && ! ( strncasecmp ( V_118 , L_456 , 6 ) ) ) {
V_755 -> V_762 = F_412 ( V_118 , V_83 ) ;
if ( ! V_755 -> V_762 )
return - V_84 ;
}
}
V_118 = F_411 ( V_764 ) ;
V_755 -> V_765 = F_412 ( V_118 , V_83 ) ;
if ( V_118 && ! V_755 -> V_765 )
return - V_84 ;
return 0 ;
}
static int T_1 F_414 ( void )
{
int V_766 ;
if ( V_767 )
return - V_75 ;
if ( ! F_6 () && ! F_5 () )
return - V_75 ;
V_766 = ( V_7 . V_762 != NULL ) ||
( V_7 . V_12 != 0 ) ||
F_107 () ;
F_24 ( L_457 , V_768 , & V_462 ) ;
if ( ! V_462 ) {
if ( V_766 )
F_8 ( L_458 ) ;
return - V_75 ;
}
if ( ! V_766 && ! V_769 )
return - V_75 ;
return 0 ;
}
static void T_1 F_415 ( void )
{
F_76 ( L_57 , V_165 , V_166 ) ;
F_76 ( L_437 , V_770 ) ;
F_76 ( L_459 ,
( V_7 . V_759 ) ?
V_7 . V_759 : L_355 ,
( V_7 . V_642 ) ?
V_7 . V_642 : L_355 ) ;
F_25 ( ! V_7 . V_6 ) ;
if ( V_7 . V_762 )
F_76 ( L_460 ,
( V_7 . V_6 == V_15 ) ?
L_449 : ( ( V_7 . V_6 ==
V_14 ) ?
L_456 : L_461 ) ,
V_7 . V_762 ,
( V_7 . V_765 ) ?
V_7 . V_765 : L_355 ) ;
}
static int T_1 F_416 ( const char * V_675 , struct V_771 * V_772 )
{
unsigned int V_42 ;
struct V_67 * V_68 ;
if ( ! V_772 || ! V_772 -> V_51 || ! V_675 )
return - V_94 ;
for ( V_42 = 0 ; V_42 < F_100 ( V_773 ) ; V_42 ++ ) {
V_68 = V_773 [ V_42 ] . V_66 ;
F_417 ( V_68 == NULL ) ;
if ( ! V_68 || ! V_68 -> V_51 )
continue;
if ( strcmp ( V_68 -> V_51 , V_772 -> V_51 ) == 0 && V_68 -> V_101 ) {
if ( strlen ( V_675 ) > sizeof( V_773 [ V_42 ] . V_774 ) - 2 )
return - V_775 ;
strcpy ( V_773 [ V_42 ] . V_774 , V_675 ) ;
strcat ( V_773 [ V_42 ] . V_774 , L_28 ) ;
return 0 ;
}
}
return - V_94 ;
}
static void F_418 ( void )
{
struct V_67 * V_68 , * V_107 ;
V_69 = V_199 ;
F_419 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
F_398 ( V_68 ) ;
}
F_20 ( V_55 , L_462 ) ;
if ( V_208 ) {
if ( V_186 . V_776 )
F_420 ( V_208 ) ;
else
F_421 ( V_208 ) ;
F_37 ( V_212 ) ;
}
if ( V_777 )
F_422 ( V_777 ) ;
if ( V_186 . V_778 )
F_266 ( & V_547 -> V_60 , & V_779 ) ;
if ( V_547 )
F_423 ( V_547 ) ;
if ( V_154 )
F_423 ( V_154 ) ;
if ( V_186 . V_780 )
F_103 ( & V_717 . V_81 ) ;
if ( V_186 . V_781 )
F_103 ( & V_782 . V_81 ) ;
if ( V_186 . V_783 )
F_424 ( & V_717 ) ;
if ( V_186 . V_784 )
F_424 ( & V_782 ) ;
if ( V_742 )
F_401 ( V_785 , V_786 ) ;
if ( V_481 )
F_425 ( V_481 ) ;
F_37 ( V_7 . V_759 ) ;
F_37 ( V_7 . V_642 ) ;
F_37 ( V_7 . V_762 ) ;
F_37 ( V_7 . V_765 ) ;
}
static int T_1 F_426 ( void )
{
int V_100 , V_42 ;
V_69 = V_292 ;
V_100 = F_409 ( & V_7 ) ;
if ( V_100 ) {
F_8 ( L_463 , V_100 ) ;
F_418 () ;
return V_100 ;
}
V_100 = F_414 () ;
if ( V_100 ) {
F_418 () ;
return V_100 ;
}
F_415 () ;
F_106 () ;
F_186 ( V_787 ) ;
F_186 ( V_788 ) ;
V_481 = F_427 ( V_789 ) ;
if ( ! V_481 ) {
F_418 () ;
return - V_84 ;
}
V_742 = F_428 ( V_785 , V_786 ) ;
if ( ! V_742 ) {
F_8 ( L_464 V_785 L_280 ) ;
F_418 () ;
return - V_75 ;
}
V_100 = F_429 ( & V_782 ) ;
if ( V_100 ) {
F_8 ( L_465 ) ;
F_418 () ;
return V_100 ;
}
V_186 . V_784 = 1 ;
V_100 = F_429 ( & V_717 ) ;
if ( V_100 ) {
F_8 ( L_466 ) ;
F_418 () ;
return V_100 ;
}
V_186 . V_783 = 1 ;
V_100 = F_99 ( & V_782 . V_81 ) ;
if ( ! V_100 ) {
V_186 . V_781 = 1 ;
V_100 = F_99 (
& V_717 . V_81 ) ;
}
if ( V_100 ) {
F_8 ( L_467 ) ;
F_418 () ;
return V_100 ;
}
V_186 . V_780 = 1 ;
V_154 = F_430 ( V_790 , - 1 ,
NULL , 0 ) ;
if ( F_147 ( V_154 ) ) {
V_100 = F_311 ( V_154 ) ;
V_154 = NULL ;
F_8 ( L_468 ) ;
F_418 () ;
return V_100 ;
}
V_547 = F_430 (
V_791 ,
- 1 , NULL , 0 ) ;
if ( F_147 ( V_547 ) ) {
V_100 = F_311 ( V_547 ) ;
V_547 = NULL ;
F_8 ( L_469 ) ;
F_418 () ;
return V_100 ;
}
V_100 = F_264 ( & V_547 -> V_60 , & V_779 ) ;
if ( V_100 ) {
F_8 ( L_470 ) ;
F_418 () ;
return V_100 ;
}
V_186 . V_778 = 1 ;
V_777 = F_431 ( & V_547 -> V_60 ) ;
if ( F_147 ( V_777 ) ) {
V_100 = F_311 ( V_777 ) ;
V_777 = NULL ;
F_8 ( L_471 ) ;
F_418 () ;
return V_100 ;
}
F_187 ( & V_207 ) ;
V_208 = F_432 () ;
if ( ! V_208 ) {
F_418 () ;
return - V_84 ;
} else {
V_208 -> V_51 = L_472 ;
V_208 -> V_792 = V_790 L_473 ;
V_208 -> V_144 . V_793 = V_794 ;
V_208 -> V_144 . V_6 = V_7 . V_6 ;
V_208 -> V_144 . V_795 = V_796 ;
V_208 -> V_144 . V_797 = V_798 ;
V_208 -> V_60 . V_52 = & V_154 -> V_60 ;
}
F_308 () ;
for ( V_42 = 0 ; V_42 < F_100 ( V_773 ) ; V_42 ++ ) {
V_100 = F_403 ( & V_773 [ V_42 ] ) ;
if ( V_100 >= 0 && * V_773 [ V_42 ] . V_774 )
V_100 = V_773 [ V_42 ] . V_66 -> V_101 ( V_773 [ V_42 ] . V_774 ) ;
if ( V_100 < 0 ) {
F_418 () ;
return V_100 ;
}
}
V_69 = V_70 ;
V_100 = F_433 ( V_208 ) ;
if ( V_100 < 0 ) {
F_8 ( L_474 ) ;
F_418 () ;
return V_100 ;
} else {
V_186 . V_776 = 1 ;
}
return 0 ;
}
