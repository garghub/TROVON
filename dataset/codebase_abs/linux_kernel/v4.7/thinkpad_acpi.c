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
V_296 | V_193 ) ;
}
static T_8 F_162 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 ,
( V_191 | V_193 )
& ~ V_297 ) ;
}
static T_8 F_163 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_55 , V_193 ) ;
}
static T_8 F_164 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
T_7 V_298 ;
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
V_298 = V_195 & ~ ( V_190 & V_191 )
& ~ V_193 & V_196 ;
F_118 ( & V_203 ) ;
if ( V_73 < 0 )
F_8 ( L_91
L_92 ) ;
if ( V_298 )
F_32 ( L_91
L_93 ,
V_298 ) ;
F_82 ( L_94 , L_87 , V_157 ) ;
return ( V_73 < 0 ) ? V_73 : V_35 ;
}
static T_8 F_165 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_282 ) ;
}
static T_8 F_166 ( struct V_74 * V_60 ,
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
L_97 ) ;
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
if ( V_186 . V_206 )
F_169 ( & V_154 -> V_60 . V_125 , NULL ,
L_98 ) ;
}
static T_8 F_172 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_299 ) ;
}
static void F_173 ( void )
{
F_169 ( & V_154 -> V_60 . V_125 , NULL ,
L_99 ) ;
}
static T_8 F_174 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_44 , V_300 ) ;
}
static void F_175 ( void )
{
F_169 ( & V_154 -> V_60 . V_125 , NULL ,
L_100 ) ;
}
static T_8 F_176 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_301 ;
V_301 = F_177 () ;
if ( V_301 < 0 )
return V_301 ;
return snprintf ( V_126 , V_102 , L_44 , V_301 ) ;
}
static T_8 F_178 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 ;
if ( F_57 ( V_126 , V_302 , & V_157 ) )
return - V_94 ;
V_17 = F_179 ( V_157 ) ;
return ( V_17 < 0 ) ? V_17 : V_35 ;
}
static void F_180 ( void )
{
int V_303 ;
V_303 = F_69 () ;
if ( V_303 == V_135 )
F_66 ( true ) ;
F_65 () ;
if ( V_303 == V_142 )
F_66 ( false ) ;
if ( ! ( V_303 < 0 ) ) {
F_115 ( & V_207 ) ;
F_122 ( V_208 ,
V_304 , ( V_303 > 0 ) ) ;
F_123 ( V_208 ) ;
F_118 ( & V_207 ) ;
}
F_168 () ;
}
static void F_181 ( void )
{
#ifdef F_116
F_115 ( & V_203 ) ;
F_144 () ;
F_118 ( & V_203 ) ;
#endif
if ( V_305 )
F_54 ( V_305 , & V_154 -> V_60 . V_125 ) ;
F_20 ( V_306 | V_307 ,
L_101 ) ;
if ( ( ( V_186 . V_189 &&
F_112 ( V_295 ) ) |
F_120 ( false ) ) != 0 )
F_8 ( L_102
L_103 ) ;
}
static void T_1 F_182 ( const unsigned int V_210 )
{
if ( V_212 [ V_210 ] != V_213 ) {
F_183 ( V_212 [ V_210 ] ,
V_208 -> V_308 ) ;
V_212 [ V_210 ] = V_213 ;
}
}
static int T_1 F_184 ( struct V_309 * V_310 )
{
enum T_15 {
V_311 = 0 ,
V_312 ,
};
static const T_16 V_313 [] V_314 = {
[ V_311 ] = {
V_315 , V_316 , V_317 , V_318 ,
V_319 , V_320 , V_321 , V_322 ,
V_323 , V_324 , V_325 , V_326 ,
V_327 ,
V_327 ,
V_327 ,
V_213 ,
V_213 ,
V_213 ,
V_327 ,
V_328 ,
V_213 ,
V_213 ,
V_213 ,
V_329 ,
V_327 , V_327 , V_327 , V_327 ,
V_327 , V_327 , V_327 , V_327 ,
V_327 , V_327 , V_327 , V_327 ,
V_327 , V_327 , V_327 , V_327 ,
V_327 , V_327 , V_327 , V_327 ,
V_327 , V_327 , V_327 , V_327 ,
V_327 , V_327 , V_327 ,
} ,
[ V_312 ] = {
V_315 , V_317 , V_316 , V_318 ,
V_319 , V_330 , V_321 , V_322 ,
V_323 , V_324 , V_325 , V_326 ,
V_327 ,
V_327 ,
V_327 ,
V_331 ,
V_332 ,
V_213 ,
V_327 ,
V_328 ,
V_213 ,
V_213 ,
V_213 ,
V_329 ,
V_327 , V_327 ,
V_333 ,
V_327 ,
V_334 , V_335 , V_336 , V_337 ,
V_213 ,
V_338 ,
V_213 ,
V_213 ,
V_213 ,
V_339 ,
V_213 ,
V_213 ,
V_213 ,
V_213 ,
V_213 ,
V_334 ,
V_213 ,
V_340 ,
V_341 ,
V_213 ,
V_213 ,
V_213 ,
V_213 ,
V_213 ,
} ,
} ;
static const struct V_3 V_342 [] V_314 = {
{
. V_6 = V_15 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_311 ,
} ,
{
. V_6 = V_14 ,
. V_9 = V_8 , . V_11 = V_8 ,
. V_13 = V_312 ,
} ,
} ;
#define F_185 sizeof(tpacpi_keymap_t)
#define F_186 sizeof(tpacpi_keymap_entry_t)
int V_17 , V_42 ;
int V_30 ;
int V_343 ;
bool V_344 = false ;
bool V_345 = false ;
unsigned long V_13 ;
unsigned long V_346 ;
F_17 ( V_55 | V_307 ,
L_104 ) ;
F_25 ( ! V_208 ) ;
F_25 ( V_208 -> V_347 != NULL ||
V_208 -> V_348 != NULL ) ;
F_187 ( V_349 ) ;
F_188 ( & V_203 ) ;
#ifdef F_116
F_188 ( & V_280 ) ;
#endif
V_186 . V_202 = V_129 != NULL ;
F_17 ( V_55 | V_307 ,
L_105 ,
F_1 ( V_186 . V_202 ) ) ;
if ( ! V_186 . V_202 )
return 1 ;
V_13 = F_4 ( V_350 ,
F_100 ( V_350 ) ) ;
F_60 () ;
V_305 = F_51 (
F_100 ( V_351 ) + 2 ,
NULL ) ;
if ( ! V_305 )
return - V_84 ;
V_17 = F_53 ( V_305 ,
V_351 ,
F_100 ( V_351 ) ) ;
if ( V_17 )
goto V_352;
if ( F_7 ( V_129 , & V_343 , L_106 , L_107 ) ) {
F_17 ( V_55 | V_307 ,
L_108 ,
V_343 ) ;
switch ( V_343 >> 8 ) {
case 1 :
if ( ! F_7 ( V_129 , & V_191 ,
L_109 , L_107 ) ) {
F_8 ( L_110 ,
V_353 ) ;
V_191 = 0x080cU ;
} else {
V_186 . V_189 = 1 ;
}
break;
case 2 :
if ( ! F_7 ( V_129 , & V_191 ,
L_109 , L_7 , 1 ) ) {
F_8 ( L_110 ,
V_353 ) ;
V_191 = 0x080cU ;
} else {
V_186 . V_189 = 1 ;
}
if ( F_7 ( V_129 , & V_296 ,
L_109 , L_7 , 2 ) ) {
if ( V_296 != 0 ) {
V_186 . V_354 = true ;
V_17 = F_189 (
& V_154 -> V_60 . V_125 ,
& V_355 ) ;
if ( V_17 )
goto V_352;
}
} else {
V_186 . V_354 = false ;
V_296 = 0x0U ;
}
break;
default:
F_8 ( L_111 ,
V_343 ) ;
F_8 ( L_112 , V_353 ) ;
break;
}
}
F_17 ( V_55 | V_307 ,
L_113 ,
F_1 ( V_186 . V_189 ) ) ;
if ( ! V_186 . V_189 && ! V_191 &&
( V_13 & V_356 ) )
V_191 = 0x080cU ;
if ( V_186 . V_189 ) {
V_17 = F_110 () ;
if ( V_17 )
goto V_352;
V_295 = V_190 ;
} else {
V_295 = V_191 ;
V_190 = V_191 ;
}
#ifdef F_102
if ( V_172 ) {
V_186 . V_187 = 1 ;
V_344 = ! ! V_167 ;
F_76 ( L_114 ) ;
} else
#endif
if ( F_7 ( V_129 , & V_30 , L_63 , L_107 ) ) {
V_186 . V_187 = 1 ;
V_344 = ! ! V_30 ;
F_76 ( L_115 ,
F_190 ( V_30 , 0 ) ) ;
}
if ( V_186 . V_187 )
V_17 = F_52 ( V_305 ,
& V_357 . V_122 ) ;
if ( ! V_17 && F_7 ( V_129 , & V_30 , L_65 , L_107 ) ) {
V_186 . V_206 = 1 ;
V_345 = ! ! ( V_30 & V_188 ) ;
F_76 ( L_116
L_117 ,
( V_345 ) ? L_118 : L_119 ) ;
V_17 = F_52 ( V_305 ,
& V_358 . V_122 ) ;
}
if ( ! V_17 )
V_17 = F_191 (
V_305 ,
& V_154 -> V_60 . V_125 ) ;
if ( V_17 )
goto V_352;
V_212 = F_44 ( F_185 ,
V_83 ) ;
if ( ! V_212 ) {
F_8 ( L_120 ) ;
V_17 = - V_84 ;
goto V_352;
}
V_346 = F_4 ( V_342 ,
F_100 ( V_342 ) ) ;
F_25 ( V_346 >= F_100 ( V_313 ) ) ;
F_20 ( V_55 | V_307 ,
L_121 , V_346 ) ;
memcpy ( V_212 , & V_313 [ V_346 ] ,
F_185 ) ;
F_192 ( V_208 , V_214 , V_215 ) ;
V_208 -> V_359 = F_186 ;
V_208 -> V_360 = V_361 ;
V_208 -> V_211 = V_212 ;
for ( V_42 = 0 ; V_42 < V_361 ; V_42 ++ ) {
if ( V_212 [ V_42 ] != V_213 ) {
F_192 ( V_208 , V_362 ,
V_212 [ V_42 ] ) ;
} else {
if ( V_42 < sizeof( V_297 ) * 8 )
V_297 |= 1 << V_42 ;
}
}
if ( V_186 . V_187 ) {
F_192 ( V_208 , V_363 , V_304 ) ;
F_122 ( V_208 ,
V_304 , V_344 ) ;
}
if ( V_186 . V_206 ) {
F_192 ( V_208 , V_363 , V_209 ) ;
F_122 ( V_208 ,
V_209 , V_345 ) ;
}
if ( F_193 () != V_364 ) {
F_76 ( L_122
L_123
L_124 ) ;
F_32 ( L_125
L_126 ) ;
V_297 |=
( 1 << V_261 )
| ( 1 << V_260 ) ;
F_182 ( V_261 ) ;
F_182 ( V_260 ) ;
}
#ifdef F_116
V_193 = V_365
& ~ V_191
& ~ V_297 ;
F_17 ( V_55 | V_307 ,
L_127 ,
V_193 , V_282 ) ;
#endif
F_20 ( V_55 | V_307 ,
L_128 ) ;
V_17 = F_120 ( true ) ;
if ( V_17 ) {
F_181 () ;
return V_17 ;
}
V_17 = F_112 ( ( ( V_191 & ~ V_297 )
| V_195 )
& ~ V_193 ) ;
if ( V_17 < 0 && V_17 != - V_49 ) {
F_181 () ;
return V_17 ;
}
V_192 = ( V_190 | V_193 )
& ~ V_297 ;
F_17 ( V_55 | V_307 ,
L_129 ,
V_192 , V_190 , V_193 ) ;
V_208 -> V_347 = & F_150 ;
V_208 -> V_348 = & F_152 ;
F_148 ( true ) ;
return 0 ;
V_352:
F_54 ( V_305 , & V_154 -> V_60 . V_125 ) ;
F_55 ( & V_154 -> V_60 . V_125 ,
& V_355 ) ;
V_305 = NULL ;
return ( V_17 < 0 ) ? V_17 : 1 ;
}
static int F_177 ( void )
{
int V_366 = 0 ;
if ( ! F_7 ( V_129 , & V_366 , L_130 , L_7 , 0 ) ) {
F_8 ( L_131 ) ;
return - V_50 ;
}
return V_366 ;
}
static int F_179 ( int V_367 )
{
if ( V_367 < 0 ||
V_367 > V_302 )
return - V_94 ;
if ( ! F_7 ( V_129 , NULL , L_132 , L_9 , V_367 ) ) {
F_8 ( L_133 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_194 ( int V_366 )
{
T_10 V_42 ;
T_10 V_368 = F_100 ( V_369 ) - 1 ;
for ( V_42 = 0 ; V_42 <= V_368 ; V_42 ++ ) {
if ( V_369 [ V_42 ] == V_366 )
break;
}
if ( V_42 >= V_368 )
V_42 = 0 ;
else
V_42 ++ ;
return V_369 [ V_42 ] ;
}
static bool F_195 ( unsigned int V_210 )
{
int V_301 = 0 ;
int V_367 = 0 ;
int V_211 ;
switch ( V_210 ) {
case V_370 :
if ( V_371 ) {
V_367 = V_372 ;
V_371 = false ;
} else {
V_301 = F_177 () ;
if ( V_301 < 0 )
return false ;
V_367 = F_194 (
V_301 ) ;
}
if ( F_179 ( V_367 ) < 0 )
return false ;
return true ;
case V_373 :
V_301 = F_177 () ;
if ( V_301 < 0 )
return false ;
V_372 = V_301 ;
V_371 = true ;
if ( F_179 ( V_374 ) < 0 )
return false ;
return true ;
default:
if ( V_210 < V_375 ||
V_210 >= V_375 + V_361 -
V_376 ) {
F_76 ( L_134 ,
V_210 ) ;
return false ;
}
V_211 = V_212 [ V_210 - V_375 + V_376 ] ;
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
static bool F_196 ( const T_7 V_349 ,
bool * V_377 ,
bool * V_378 )
{
unsigned int V_210 = V_349 & 0xfff ;
* V_377 = true ;
* V_378 = false ;
if ( V_210 > 0 && V_210 <= V_361 ) {
V_210 -- ;
if ( ! ( V_193 & ( 1 << V_210 ) ) ) {
F_127 ( V_210 ) ;
* V_377 = false ;
} else {
* V_378 = true ;
}
return true ;
} else {
return F_195 ( V_210 ) ;
}
return false ;
}
static bool F_197 ( const T_7 V_349 ,
bool * V_377 ,
bool * V_378 )
{
* V_377 = true ;
* V_378 = false ;
switch ( V_349 ) {
case V_379 :
case V_380 :
V_299 = V_381 ;
* V_378 = true ;
break;
case V_382 :
case V_383 :
V_299 = V_384 ;
* V_378 = true ;
break;
case V_385 :
case V_386 :
F_198 ( L_135 ) ;
break;
default:
return false ;
}
if ( V_299 != V_387 ) {
F_76 ( L_136 ) ;
F_173 () ;
}
return true ;
}
static bool F_199 ( const T_7 V_349 ,
bool * V_377 ,
bool * V_378 )
{
* V_377 = true ;
* V_378 = false ;
switch ( V_349 ) {
case V_388 :
V_300 = 1 ;
F_76 ( L_137 ) ;
F_175 () ;
return true ;
case V_389 :
F_76 ( L_138 ) ;
return true ;
case V_390 :
F_76 ( L_139 ) ;
return true ;
default:
return false ;
}
}
static bool F_200 ( const T_7 V_349 ,
bool * V_377 ,
bool * V_378 )
{
* V_377 = true ;
* V_378 = false ;
switch ( V_349 ) {
case V_391 :
case V_392 :
return true ;
case V_393 :
case V_394 :
F_121 () ;
F_171 () ;
* V_377 = false ;
return true ;
case V_395 :
case V_396 :
case V_397 :
* V_378 = true ;
return true ;
default:
return false ;
}
}
static bool F_201 ( const T_7 V_349 ,
bool * V_377 ,
bool * V_378 )
{
bool V_398 = true ;
* V_377 = true ;
* V_378 = false ;
switch ( V_349 ) {
case V_399 :
F_76 ( L_140 ) ;
return true ;
case V_400 :
F_202 ( L_141 ) ;
break;
case V_401 :
F_198 ( L_142 ) ;
break;
case V_402 :
F_202 ( L_143
L_144 ) ;
break;
case V_403 :
F_198 ( L_145
L_146 ) ;
break;
case V_404 :
case V_405 :
case V_406 :
case V_407 :
* V_377 = false ;
* V_378 = true ;
return true ;
default:
F_62 ( L_147 ) ;
V_398 = false ;
}
F_203 () ;
return V_398 ;
}
static void F_204 ( struct V_67 * V_68 , T_7 V_65 )
{
T_7 V_349 ;
bool V_377 ;
bool V_378 ;
bool V_408 ;
if ( V_65 != 0x80 ) {
F_8 ( L_148 , V_65 ) ;
F_205 (
V_68 -> V_71 -> V_74 -> V_409 . V_410 ,
F_206 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , 0 ) ;
return;
}
while ( 1 ) {
if ( ! F_7 ( V_129 , & V_349 , L_149 , L_64 ) ) {
F_8 ( L_150 ) ;
return;
}
if ( V_349 == 0 ) {
return;
}
V_377 = true ;
V_378 = false ;
switch ( V_349 >> 12 ) {
case 1 :
V_408 = F_196 ( V_349 , & V_377 ,
& V_378 ) ;
break;
case 2 :
V_408 = F_197 ( V_349 , & V_377 ,
& V_378 ) ;
break;
case 3 :
switch ( V_349 ) {
case V_411 :
V_300 = 1 ;
F_76 ( L_151 ) ;
F_175 () ;
V_408 = true ;
break;
case V_412 :
V_408 = true ;
break;
default:
V_408 = false ;
}
break;
case 4 :
V_408 = F_199 ( V_349 , & V_377 ,
& V_378 ) ;
break;
case 5 :
V_408 = F_200 ( V_349 , & V_377 ,
& V_378 ) ;
break;
case 6 :
V_408 = F_201 ( V_349 , & V_377 ,
& V_378 ) ;
break;
case 7 :
if ( V_186 . V_187 &&
V_349 == V_413 ) {
F_180 () ;
V_377 = 0 ;
V_408 = true ;
break;
}
default:
V_408 = false ;
}
if ( ! V_408 ) {
F_32 ( L_152 , V_349 ) ;
F_32 ( L_153
L_154 , V_353 ) ;
}
if ( ! V_378 && V_377 ) {
F_205 (
V_68 -> V_71 -> V_74 -> V_409 . V_410 ,
F_206 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , V_349 ) ;
}
}
}
static void F_207 ( void )
{
V_299 = V_387 ;
V_300 = 0 ;
if ( V_186 . V_354 ) {
if ( ! F_7 ( V_129 , & V_372 ,
L_130 , L_7 , 0 ) ) {
F_8 ( L_155 ) ;
}
}
}
static void F_208 ( void )
{
F_60 () ;
if ( F_120 ( true ) < 0 ||
F_112 ( V_190 ) < 0 )
F_8 ( L_156
L_157 ) ;
F_180 () ;
F_171 () ;
F_173 () ;
F_175 () ;
F_148 ( false ) ;
if ( V_186 . V_354 ) {
if ( ! F_7 ( V_129 , NULL , L_132 , L_9 ,
V_372 ) ) {
F_8 ( L_158 ) ;
}
}
}
static int F_209 ( struct V_90 * V_91 )
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
F_84 ( V_91 , L_47 , F_190 ( V_30 , 0 ) ) ;
if ( V_191 ) {
F_84 ( V_91 , L_159 , V_192 ) ;
F_84 ( V_91 , L_160 ) ;
} else {
F_84 ( V_91 , L_161 ) ;
F_84 ( V_91 , L_162 ) ;
}
return 0 ;
}
static void F_210 ( bool V_204 )
{
F_2 ( L_163 ) ;
if ( ! F_211 ( ( V_69 == V_70 || ! V_204 ) ,
F_212 ( L_164
L_165
L_166 ) ) )
F_8 ( L_167
L_168
L_166 ) ;
}
static int F_213 ( char * V_126 )
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
F_210 ( 1 ) ;
} else if ( F_86 ( V_159 , L_52 ) == 0 ) {
F_210 ( 0 ) ;
V_17 = - V_158 ;
} else if ( F_86 ( V_159 , L_169 ) == 0 ) {
V_197 = ( V_191 | V_193 )
& ~ V_297 ;
} else if ( sscanf ( V_159 , L_170 , & V_197 ) == 1 ) {
} else if ( sscanf ( V_159 , L_171 , & V_197 ) == 1 ) {
} else {
V_17 = - V_94 ;
goto V_414;
}
}
if ( ! V_17 ) {
F_82 ( L_172 ,
L_173 , V_197 ) ;
V_17 = F_113 ( V_197 ) ;
}
V_414:
F_118 ( & V_203 ) ;
return V_17 ;
}
static int F_214 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_174 )
return ( V_168 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_174 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_415 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_215 ( enum V_416 V_205 )
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
V_30 = V_415
| V_417 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_176 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_216 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_418 ,
V_122 , V_126 ) ;
}
static T_8 F_217 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_418 ,
V_122 , V_126 , V_35 ) ;
}
static void F_218 ( void )
{
if ( ! F_7 ( NULL , NULL , L_177 , L_9 ,
V_419 ) )
F_32 ( L_178 ) ;
else
F_17 ( V_140 ,
L_179 ) ;
}
static void F_219 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_420 ) ;
F_77 ( V_418 ) ;
F_218 () ;
}
static int T_1 F_220 ( struct V_309 * V_310 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_180 ) ;
F_187 ( V_349 ) ;
V_186 . V_421 = V_129 &&
F_7 ( V_129 , & V_30 , L_174 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_181 ,
F_1 ( V_186 . V_421 ) ,
V_30 ) ;
#ifdef F_102
if ( V_174 ) {
V_186 . V_421 = 1 ;
F_76 ( L_182 ) ;
} else
#endif
if ( V_186 . V_421 &&
! ( V_30 & V_422 ) ) {
V_186 . V_421 = 0 ;
F_20 ( V_55 | V_140 ,
L_183 ) ;
}
if ( ! V_186 . V_421 )
return 1 ;
V_17 = F_71 ( V_418 ,
& V_423 ,
V_424 ,
V_425 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_189 ( & V_154 -> V_60 . V_125 ,
& V_420 ) ;
if ( V_17 ) {
F_77 ( V_418 ) ;
return V_17 ;
}
return 0 ;
}
static int F_221 ( struct V_90 * V_91 )
{
return F_83 ( V_418 , V_91 ) ;
}
static int F_222 ( char * V_126 )
{
return F_85 ( V_418 , V_126 ) ;
}
static int F_223 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_176 )
return ( V_169 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_184 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_426 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_224 ( enum V_416 V_205 )
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
V_30 = V_426
| V_427 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_186 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_225 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_428 ,
V_122 , V_126 ) ;
}
static T_8 F_226 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_428 ,
V_122 , V_126 , V_35 ) ;
}
static void F_227 ( void )
{
if ( ! F_7 ( NULL , NULL , L_187 , L_9 ,
V_429 ) )
F_32 ( L_188 ) ;
else
F_17 ( V_140 ,
L_189 ) ;
}
static void F_228 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_430 ) ;
F_77 ( V_428 ) ;
F_227 () ;
}
static int T_1 F_229 ( struct V_309 * V_310 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_190 ) ;
F_187 ( V_349 ) ;
V_186 . V_431 = V_129 &&
F_7 ( V_129 , & V_30 , L_184 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_191 ,
F_1 ( V_186 . V_431 ) ,
V_30 ) ;
#ifdef F_102
if ( V_176 ) {
V_186 . V_431 = 1 ;
F_76 ( L_192 ) ;
} else
#endif
if ( V_186 . V_431 &&
! ( V_30 & V_432 ) ) {
V_186 . V_431 = 0 ;
F_20 ( V_55 | V_140 ,
L_193 ) ;
}
if ( ! V_186 . V_431 )
return 1 ;
V_17 = F_71 ( V_428 ,
& V_433 ,
V_434 ,
V_435 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_189 ( & V_154 -> V_60 . V_125 ,
& V_430 ) ;
if ( V_17 ) {
F_77 ( V_428 ) ;
return V_17 ;
}
return 0 ;
}
static int F_230 ( struct V_90 * V_91 )
{
return F_83 ( V_428 , V_91 ) ;
}
static int F_231 ( char * V_126 )
{
return F_85 ( V_428 , V_126 ) ;
}
static int F_232 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_178 )
return ( V_170 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_194 , L_64 ) )
return - V_50 ;
return ( ( V_30 & V_436 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_233 ( enum V_416 V_205 )
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
V_30 = V_436 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_196 , L_9 , V_30 ) )
return - V_50 ;
return 0 ;
}
static void F_234 ( void )
{
F_77 ( V_437 ) ;
}
static int T_1 F_235 ( struct V_309 * V_310 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_197 ) ;
F_187 ( V_349 ) ;
V_186 . V_438 = V_129 &&
F_7 ( V_129 , & V_30 , L_194 , L_107 ) ;
F_17 ( V_55 | V_140 ,
L_198 ,
F_1 ( V_186 . V_438 ) ,
V_30 ) ;
#ifdef F_102
if ( V_178 ) {
V_186 . V_438 = 1 ;
F_76 ( L_199 ) ;
} else
#endif
if ( V_186 . V_438 &&
! ( V_30 & V_439 ) ) {
V_186 . V_438 = 0 ;
F_20 ( V_55 ,
L_200 ) ;
}
if ( ! V_186 . V_438 )
return 1 ;
V_17 = F_71 ( V_437 ,
& V_440 ,
V_441 ,
V_442 ,
false ) ;
return V_17 ;
}
static int T_1 F_236 ( struct V_309 * V_310 )
{
int V_443 ;
F_17 ( V_55 , L_201 ) ;
F_187 ( V_444 ) ;
if ( F_6 () )
F_187 ( V_445 ) ;
if ( V_446 && F_7 ( NULL , & V_443 , L_202 , L_64 ) && V_443 )
V_447 = V_446 ;
if ( ! V_447 )
V_448 = V_449 ;
else if ( F_6 () &&
F_7 ( V_447 , & V_450 , L_203 , L_107 ) )
V_448 = V_451 ;
else if ( F_6 () &&
F_7 ( V_447 , & V_450 , L_204 , L_107 ) )
V_448 = V_452 ;
else
V_448 = V_453 ;
F_17 ( V_55 , L_205 ,
F_1 ( V_448 != V_449 ) ,
V_448 ) ;
return ( V_448 != V_449 ) ? 0 : 1 ;
}
static void F_237 ( void )
{
F_20 ( V_306 ,
L_206 ) ;
if ( F_238 ( V_450 ) )
F_8 ( L_207
L_208 ) ;
}
static int F_239 ( void )
{
int V_30 = 0 ;
int V_42 ;
switch ( V_448 ) {
case V_451 :
if ( ! F_7 ( NULL , & V_42 , L_209 , L_7 ,
V_454 ) )
return - V_50 ;
V_30 = V_42 & V_455 ;
break;
case V_452 :
if ( ! F_7 ( NULL , & V_42 , L_210 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_456 ;
if ( ! F_7 ( NULL , & V_42 , L_211 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_457 ;
break;
case V_453 :
if ( ! F_7 ( NULL , NULL , L_212 , L_9 , 1 ) ||
! F_7 ( NULL , & V_42 , L_211 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_457 ;
if ( ! F_7 ( NULL , NULL , L_212 , L_9 , 0 ) ||
! F_7 ( NULL , & V_42 , L_210 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_456 ;
if ( ! F_7 ( NULL , & V_42 , L_213 , L_64 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_458 ;
break;
default:
return - V_459 ;
}
return V_30 ;
}
static int F_240 ( int V_30 )
{
int V_460 ;
int V_17 = 0 ;
switch ( V_448 ) {
case V_451 :
V_17 = F_7 ( NULL , NULL ,
L_214 , L_8 ,
V_461 ,
V_30 | V_462 ) ;
break;
case V_452 :
V_460 = F_241 () ;
if ( V_460 < 0 )
return V_460 ;
V_17 = F_238 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_447 , NULL ,
L_215 , L_8 , V_30 * 0x100 , 0 ) ;
if ( ! V_460 && F_238 ( V_460 ) ) {
F_8 ( L_216 ) ;
return - V_50 ;
}
break;
case V_453 :
V_17 = F_7 ( NULL , NULL , L_212 , L_9 , 0x80 ) &&
F_7 ( NULL , NULL , L_217 , L_8 , V_30 , 1 ) ;
break;
default:
return - V_459 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_241 ( void )
{
int V_460 = 0 ;
switch ( V_448 ) {
case V_451 :
if ( ! F_7 ( V_447 , & V_460 , L_203 , L_64 ) )
return - V_50 ;
break;
case V_452 :
case V_453 :
if ( ! F_7 ( V_447 , & V_460 , L_218 , L_64 ) )
return - V_50 ;
break;
default:
return - V_459 ;
}
return V_460 & 1 ;
}
static int F_238 ( int V_204 )
{
if ( ! F_7 ( V_447 , NULL , L_219 , L_9 , ( V_204 ) ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static int F_242 ( void )
{
int V_460 = F_241 () ;
int V_17 ;
if ( V_460 < 0 )
return V_460 ;
switch ( V_448 ) {
case V_451 :
V_17 = F_238 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_463 , NULL , L_220 , L_221 ) ;
break;
case V_452 :
case V_453 :
V_17 = F_238 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_447 , NULL , L_222 , L_221 ) ;
break;
default:
return - V_459 ;
}
if ( ! V_460 && F_238 ( V_460 ) ) {
F_8 ( L_216 ) ;
return - V_50 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_243 ( void )
{
switch ( V_448 ) {
case V_451 :
return F_7 ( V_463 , NULL , L_223 , L_221 ) ?
0 : - V_50 ;
case V_452 :
return F_7 ( V_447 , NULL , L_224 , L_221 ) ?
0 : - V_50 ;
case V_453 :
return F_7 ( NULL , NULL , L_225 , L_221 ) ?
0 : - V_50 ;
default:
return - V_459 ;
}
}
static int F_244 ( struct V_90 * V_91 )
{
int V_30 , V_460 ;
if ( V_448 == V_449 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
if ( ! F_245 ( V_464 ) )
return - V_158 ;
V_30 = F_239 () ;
if ( V_30 < 0 )
return V_30 ;
V_460 = F_241 () ;
if ( V_460 < 0 )
return V_460 ;
F_84 ( V_91 , L_226 ) ;
F_84 ( V_91 , L_227 , F_190 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_228 , F_190 ( V_30 , 1 ) ) ;
if ( V_448 == V_453 )
F_84 ( V_91 , L_229 , F_190 ( V_30 , 3 ) ) ;
F_84 ( V_91 , L_230 , F_190 ( V_460 , 0 ) ) ;
F_84 ( V_91 , L_231 ) ;
F_84 ( V_91 , L_232 ) ;
if ( V_448 == V_453 )
F_84 ( V_91 , L_233 ) ;
F_84 ( V_91 , L_234 ) ;
F_84 ( V_91 , L_235 ) ;
return 0 ;
}
static int F_246 ( char * V_126 )
{
char * V_159 ;
int V_204 , V_465 , V_30 ;
int V_17 ;
if ( V_448 == V_449 )
return - V_75 ;
if ( ! F_245 ( V_464 ) )
return - V_158 ;
V_204 = 0 ;
V_465 = 0 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_236 ) == 0 ) {
V_204 |= V_456 ;
} else if ( F_86 ( V_159 , L_237 ) == 0 ) {
V_465 |= V_456 ;
} else if ( F_86 ( V_159 , L_238 ) == 0 ) {
V_204 |= V_457 ;
} else if ( F_86 ( V_159 , L_239 ) == 0 ) {
V_465 |= V_457 ;
} else if ( V_448 == V_453 &&
F_86 ( V_159 , L_240 ) == 0 ) {
V_204 |= V_458 ;
} else if ( V_448 == V_453 &&
F_86 ( V_159 , L_241 ) == 0 ) {
V_465 |= V_458 ;
} else if ( F_86 ( V_159 , L_242 ) == 0 ) {
V_17 = F_238 ( 1 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_243 ) == 0 ) {
V_17 = F_238 ( 0 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_244 ) == 0 ) {
V_17 = F_242 () ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_245 ) == 0 ) {
V_17 = F_243 () ;
if ( V_17 )
return V_17 ;
} else
return - V_94 ;
}
if ( V_204 || V_465 ) {
V_30 = F_239 () ;
if ( V_30 < 0 )
return V_30 ;
V_17 = F_240 ( ( V_30 & ~ V_465 ) | V_204 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_247 ( int V_56 )
{
if ( ! V_129 )
return - V_49 ;
if ( ! F_7 ( V_129 , NULL , L_246 , L_7 , V_56 ) )
return - V_50 ;
return 0 ;
}
static int F_248 ( void )
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
static bool F_249 ( void )
{
int V_30 = 0 ;
if ( ! V_129 )
return false ;
if ( ! F_250 ( V_129 , L_247 ) ) {
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
return V_30 & F_251 ( 9 ) ;
}
static void F_252 ( struct V_466 * V_467 )
{
struct V_468 * V_66 =
F_253 ( V_467 , struct V_468 , V_467 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_254 ( V_66 -> V_469 ) ;
}
static void F_255 ( struct V_470 * V_471 ,
enum V_472 V_473 )
{
struct V_468 * V_66 =
F_253 ( V_471 ,
struct V_468 ,
V_470 ) ;
V_66 -> V_469 = V_473 ;
F_256 ( V_474 , & V_66 -> V_467 ) ;
}
static enum V_472 F_257 ( struct V_470 * V_471 )
{
int V_56 ;
V_56 = F_248 () ;
if ( V_56 < 0 )
return 0 ;
return V_56 ;
}
static int T_1 F_258 ( struct V_309 * V_310 )
{
int V_73 ;
F_17 ( V_55 , L_253 ) ;
F_187 ( V_349 ) ;
F_259 ( & V_475 . V_467 , F_252 ) ;
if ( ! F_249 () ) {
V_186 . V_476 = 0 ;
F_17 ( V_55 , L_254 ) ;
return 1 ;
}
V_186 . V_476 = 1 ;
V_73 = F_260 ( & V_154 -> V_60 ,
& V_475 . V_470 ) ;
if ( V_73 < 0 ) {
V_186 . V_476 = 0 ;
return V_73 ;
}
return 0 ;
}
static void F_261 ( void )
{
if ( V_186 . V_476 )
F_262 ( & V_475 . V_470 ) ;
F_263 ( V_474 ) ;
}
static int F_254 ( int V_56 )
{
int V_100 ;
struct V_470 * V_471 ;
V_100 = F_247 ( V_56 ) ;
V_471 = & V_475 . V_470 ;
if ( V_100 == 0 && ! ( V_471 -> V_79 & V_477 ) )
V_471 -> V_473 = V_56 ;
return V_100 ;
}
static int F_264 ( struct V_90 * V_91 )
{
int V_56 ;
if ( ! V_186 . V_476 ) {
F_84 ( V_91 , L_46 ) ;
} else {
V_56 = F_248 () ;
if ( V_56 < 0 )
F_84 ( V_91 , L_255 , V_56 ) ;
else
F_84 ( V_91 , L_256 , V_56 ) ;
F_84 ( V_91 , L_257 ) ;
}
return 0 ;
}
static int F_265 ( char * V_126 )
{
char * V_159 ;
int V_56 = - 1 ;
if ( ! V_186 . V_476 )
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
return F_254 ( V_56 ) ;
}
static void F_266 ( void )
{
struct V_470 * V_471 ;
if ( ! V_186 . V_476 )
return;
V_471 = & V_475 . V_470 ;
F_267 ( V_471 ) ;
F_268 ( V_471 ) ;
}
static void F_269 ( void )
{
if ( ! V_186 . V_476 )
return;
F_270 ( & V_475 . V_470 ) ;
}
static int F_271 ( void )
{
int V_30 = 0 ;
if ( V_186 . V_478 ) {
if ( ! F_7 ( V_463 , & V_30 , L_261 , L_64 ) )
return - V_50 ;
return ( ! ! V_30 ) ;
}
return - V_49 ;
}
static int F_272 ( int V_30 )
{
int V_73 ;
if ( V_186 . V_479 ) {
if ( V_48 ) {
V_73 = F_7 ( V_48 , NULL , NULL , L_9 ,
( V_30 ) ?
V_480 :
V_481 ) ;
} else {
V_73 = F_7 ( V_482 , NULL , NULL , L_9 ,
( V_30 ) ? 1 : 0 ) ;
}
return ( V_73 ) ? 0 : - V_50 ;
}
return - V_49 ;
}
static void F_273 ( struct V_466 * V_467 )
{
struct V_468 * V_66 =
F_253 ( V_467 , struct V_468 , V_467 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_272 ( ( V_66 -> V_469 != V_483 ) ) ;
}
static void F_274 ( struct V_470 * V_471 ,
enum V_472 V_473 )
{
struct V_468 * V_66 =
F_253 ( V_471 ,
struct V_468 ,
V_470 ) ;
V_66 -> V_469 = ( V_473 != V_484 ) ?
V_485 : V_483 ;
F_256 ( V_474 , & V_66 -> V_467 ) ;
}
static enum V_472 F_275 ( struct V_470 * V_471 )
{
return ( F_271 () == 1 ) ? V_486 : V_484 ;
}
static int T_1 F_276 ( struct V_309 * V_310 )
{
int V_73 ;
F_17 ( V_55 , L_262 ) ;
if ( F_6 () ) {
F_187 ( V_487 ) ;
F_187 ( V_488 ) ;
}
F_187 ( V_489 ) ;
F_259 ( & V_490 . V_467 , F_273 ) ;
V_186 . V_479 = ( V_48 || V_482 ) && ! V_491 ;
if ( V_186 . V_479 )
V_186 . V_478 =
F_7 ( V_463 , NULL , L_261 , L_263 ) ;
F_17 ( V_55 , L_264 ,
F_1 ( V_186 . V_479 ) ,
F_1 ( V_186 . V_478 ) ) ;
if ( ! V_186 . V_479 )
return 1 ;
V_73 = F_260 ( & V_154 -> V_60 ,
& V_490 . V_470 ) ;
if ( V_73 < 0 ) {
V_186 . V_479 = 0 ;
V_186 . V_478 = 0 ;
} else {
V_73 = 0 ;
}
return V_73 ;
}
static void F_277 ( void )
{
F_262 ( & V_490 . V_470 ) ;
F_263 ( V_474 ) ;
}
static int F_278 ( struct V_90 * V_91 )
{
int V_30 ;
if ( ! V_186 . V_479 ) {
F_84 ( V_91 , L_46 ) ;
} else if ( ! V_186 . V_478 ) {
F_84 ( V_91 , L_265 ) ;
F_84 ( V_91 , L_266 ) ;
} else {
V_30 = F_271 () ;
if ( V_30 < 0 )
return V_30 ;
F_84 ( V_91 , L_47 , F_279 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_266 ) ;
}
return 0 ;
}
static int F_280 ( char * V_126 )
{
char * V_159 ;
int V_492 = 0 ;
if ( ! V_186 . V_479 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_267 ) == 0 ) {
V_492 = 1 ;
} else if ( F_86 ( V_159 , L_268 ) == 0 ) {
V_492 = 0 ;
} else
return - V_94 ;
}
return F_272 ( V_492 ) ;
}
static T_8 F_281 ( struct V_74 * V_60 ,
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
static int T_1 F_282 ( struct V_309 * V_310 )
{
int V_17 ;
F_17 ( V_55 ,
L_269 ) ;
F_187 ( V_489 ) ;
F_17 ( V_55 , L_270 ,
F_1 ( V_48 != NULL ) ) ;
V_17 = F_283 ( & V_154 -> V_60 , & V_493 ) ;
if ( V_17 )
return V_17 ;
return ( V_48 ) ? 0 : 1 ;
}
static void F_284 ( void )
{
F_285 ( & V_154 -> V_60 , & V_493 ) ;
}
static int F_286 ( struct V_90 * V_91 )
{
if ( ! V_48 )
F_84 ( V_91 , L_46 ) ;
else {
F_84 ( V_91 , L_226 ) ;
F_84 ( V_91 , L_271 ) ;
}
return 0 ;
}
static int F_287 ( char * V_126 )
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
static inline bool F_288 ( const unsigned int V_494 )
{
#ifdef F_289
return false ;
#else
return ( 1U & ( V_495 >> V_494 ) ) == 0 ;
#endif
}
static int F_290 ( const unsigned int V_494 )
{
int V_30 ;
enum V_496 V_497 ;
switch ( V_498 ) {
case V_499 :
if ( ! F_7 ( V_463 ,
& V_30 , L_273 , L_7 , 1 << V_494 ) )
return - V_50 ;
V_497 = ( V_30 == 0 ) ?
V_483 :
( ( V_30 == 1 ) ?
V_485 :
V_500 ) ;
V_501 [ V_494 ] = V_497 ;
return V_497 ;
default:
return - V_49 ;
}
}
static int F_291 ( const unsigned int V_494 ,
const enum V_496 V_502 )
{
static const unsigned int V_503 [] = { 0 , 1 , 3 } ;
static const unsigned int V_504 [] = { 0 , 0x80 , 0xc0 } ;
int V_73 = 0 ;
switch ( V_498 ) {
case V_499 :
if ( F_142 ( V_494 > 7 ) )
return - V_94 ;
if ( F_142 ( F_288 ( V_494 ) ) )
return - V_158 ;
if ( ! F_7 ( V_505 , NULL , NULL , L_8 ,
( 1 << V_494 ) , V_503 [ V_502 ] ) )
V_73 = - V_50 ;
break;
case V_506 :
if ( F_142 ( V_494 > 7 ) )
return - V_94 ;
if ( F_142 ( F_288 ( V_494 ) ) )
return - V_158 ;
V_73 = F_14 ( V_507 , ( 1 << V_494 ) ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_508 ,
( V_502 == V_500 ) << V_494 ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_509 ,
( V_502 != V_483 ) << V_494 ) ;
break;
case V_510 :
if ( F_142 ( V_494 >= V_511 ) )
return - V_94 ;
if ( F_142 ( F_288 ( V_494 ) ) )
return - V_158 ;
if ( ! F_7 ( V_505 , NULL , NULL , L_8 ,
V_494 , V_504 [ V_502 ] ) )
V_73 = - V_50 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
V_501 [ V_494 ] = V_502 ;
return V_73 ;
}
static void F_292 ( struct V_466 * V_467 )
{
struct V_468 * V_66 =
F_253 ( V_467 , struct V_468 , V_467 ) ;
if ( F_140 ( V_69 == V_70 ) )
F_291 ( V_66 -> V_494 , V_66 -> V_469 ) ;
}
static void F_293 ( struct V_470 * V_471 ,
enum V_472 V_473 )
{
struct V_468 * V_66 = F_253 ( V_471 ,
struct V_468 , V_470 ) ;
if ( V_473 == V_484 )
V_66 -> V_469 = V_483 ;
else if ( V_501 [ V_66 -> V_494 ] != V_500 )
V_66 -> V_469 = V_485 ;
else
V_66 -> V_469 = V_500 ;
F_256 ( V_474 , & V_66 -> V_467 ) ;
}
static int F_294 ( struct V_470 * V_471 ,
unsigned long * V_512 , unsigned long * V_513 )
{
struct V_468 * V_66 = F_253 ( V_471 ,
struct V_468 , V_470 ) ;
if ( * V_512 == 0 && * V_513 == 0 ) {
* V_512 = 500 ;
* V_513 = 500 ;
} else if ( ( * V_512 != 500 ) || ( * V_513 != 500 ) )
return - V_94 ;
V_66 -> V_469 = V_500 ;
F_256 ( V_474 , & V_66 -> V_467 ) ;
return 0 ;
}
static enum V_472 F_295 ( struct V_470 * V_471 )
{
int V_73 ;
struct V_468 * V_66 = F_253 ( V_471 ,
struct V_468 , V_470 ) ;
V_73 = F_290 ( V_66 -> V_494 ) ;
if ( V_73 == V_483 || V_73 < 0 )
V_73 = V_484 ;
else
V_73 = V_486 ;
return V_73 ;
}
static void F_296 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_511 ; V_42 ++ ) {
if ( V_514 [ V_42 ] . V_470 . V_51 )
F_262 ( & V_514 [ V_42 ] . V_470 ) ;
}
F_263 ( V_474 ) ;
F_37 ( V_514 ) ;
}
static int T_1 F_297 ( unsigned int V_494 )
{
int V_73 ;
V_514 [ V_494 ] . V_494 = V_494 ;
if ( ! V_515 [ V_494 ] )
return 0 ;
V_514 [ V_494 ] . V_470 . V_516 = & F_293 ;
V_514 [ V_494 ] . V_470 . V_517 = & F_294 ;
if ( V_498 == V_499 )
V_514 [ V_494 ] . V_470 . V_518 =
& F_295 ;
V_514 [ V_494 ] . V_470 . V_51 = V_515 [ V_494 ] ;
F_259 ( & V_514 [ V_494 ] . V_467 , F_292 ) ;
V_73 = F_260 ( & V_154 -> V_60 ,
& V_514 [ V_494 ] . V_470 ) ;
if ( V_73 < 0 )
V_514 [ V_494 ] . V_470 . V_51 = NULL ;
return V_73 ;
}
static enum V_519 T_1 F_298 ( void )
{
T_4 V_30 ;
if ( F_6 () ) {
V_30 = F_18 ( V_463 , L_274 , & V_505 ) ;
if ( F_19 ( V_30 ) )
return V_499 ;
V_30 = F_18 ( V_463 , L_275 , & V_505 ) ;
if ( F_19 ( V_30 ) )
return V_506 ;
}
V_30 = F_18 ( V_463 , L_276 , & V_505 ) ;
if ( F_19 ( V_30 ) )
return V_510 ;
V_505 = NULL ;
return V_520 ;
}
static int T_1 F_299 ( struct V_309 * V_310 )
{
unsigned int V_42 ;
int V_73 ;
unsigned long V_521 ;
F_17 ( V_55 , L_277 ) ;
V_498 = F_298 () ;
if ( V_498 != V_520 ) {
V_521 = F_4 ( V_522 ,
F_100 ( V_522 ) ) ;
if ( ! V_521 ) {
V_505 = NULL ;
V_498 = V_520 ;
}
}
F_17 ( V_55 , L_278 ,
F_1 ( V_498 ) , V_498 ) ;
if ( V_498 == V_520 )
return 1 ;
V_514 = F_35 ( sizeof( * V_514 ) * V_511 ,
V_83 ) ;
if ( ! V_514 ) {
F_8 ( L_279 ) ;
return - V_84 ;
}
for ( V_42 = 0 ; V_42 < V_511 ; V_42 ++ ) {
V_514 [ V_42 ] . V_494 = - 1 ;
if ( ! F_288 ( V_42 ) &&
F_300 ( V_42 , & V_521 ) ) {
V_73 = F_297 ( V_42 ) ;
if ( V_73 < 0 ) {
F_296 () ;
return V_73 ;
}
}
}
#ifdef F_289
F_32 ( L_280
L_281 ) ;
#endif
return 0 ;
}
static int F_301 ( struct V_90 * V_91 )
{
if ( ! V_498 ) {
F_84 ( V_91 , L_46 ) ;
return 0 ;
}
F_84 ( V_91 , L_226 ) ;
if ( V_498 == V_499 ) {
int V_42 , V_30 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_30 = F_290 ( V_42 ) ;
if ( V_30 < 0 )
return - V_50 ;
F_84 ( V_91 , L_282 ,
V_42 , F_302 ( V_30 ) ) ;
}
}
F_84 ( V_91 , L_283
L_284 ) ;
return 0 ;
}
static int F_303 ( char * V_126 )
{
char * V_159 ;
int V_494 , V_73 ;
enum V_496 V_118 ;
if ( ! V_498 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_285 , & V_494 ) != 1 )
return - V_94 ;
if ( V_494 < 0 || V_494 > ( V_511 - 1 ) ||
V_514 [ V_494 ] . V_494 < 0 )
return - V_75 ;
if ( strstr ( V_159 , L_268 ) ) {
V_118 = V_483 ;
} else if ( strstr ( V_159 , L_267 ) ) {
V_118 = V_485 ;
} else if ( strstr ( V_159 , L_286 ) ) {
V_118 = V_500 ;
} else {
return - V_94 ;
}
V_73 = F_291 ( V_494 , V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
static int T_1 F_304 ( struct V_309 * V_310 )
{
unsigned long V_13 ;
F_17 ( V_55 , L_287 ) ;
F_187 ( V_523 ) ;
F_17 ( V_55 , L_288 ,
F_1 ( V_524 != NULL ) ) ;
V_13 = F_4 ( V_525 ,
F_100 ( V_525 ) ) ;
V_186 . V_526 = ! ! ( V_13 & V_527 ) ;
return ( V_524 ) ? 0 : 1 ;
}
static int F_305 ( struct V_90 * V_91 )
{
if ( ! V_524 )
F_84 ( V_91 , L_46 ) ;
else {
F_84 ( V_91 , L_226 ) ;
F_84 ( V_91 , L_289 ) ;
}
return 0 ;
}
static int F_306 ( char * V_126 )
{
char * V_159 ;
int V_528 ;
if ( ! V_524 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_272 , & V_528 ) == 1 &&
V_528 >= 0 && V_528 <= 17 ) {
} else
return - V_94 ;
if ( V_186 . V_526 ) {
if ( ! F_7 ( V_524 , NULL , NULL , L_8 ,
V_528 , 0 ) )
return - V_50 ;
} else {
if ( ! F_7 ( V_524 , NULL , NULL , L_9 ,
V_528 ) )
return - V_50 ;
}
}
return 0 ;
}
static int F_307 ( int V_529 , T_17 * V_38 )
{
int V_157 ;
T_18 V_530 ;
char V_531 [ 5 ] ;
V_157 = V_532 ;
switch ( V_533 ) {
#if V_534 >= 16
case V_535 :
if ( V_529 >= 8 && V_529 <= 15 ) {
V_157 = V_536 ;
V_529 -= 8 ;
}
#endif
case V_537 :
if ( V_529 <= 7 ) {
if ( ! F_11 ( V_157 + V_529 , & V_530 ) )
return - V_50 ;
* V_38 = V_530 * 1000 ;
return 0 ;
}
break;
case V_538 :
if ( V_529 <= 7 ) {
snprintf ( V_531 , sizeof( V_531 ) , L_290 , '0' + V_529 ) ;
if ( ! F_7 ( V_463 , NULL , L_291 , L_221 ) )
return - V_50 ;
if ( ! F_7 ( V_463 , & V_157 , V_531 , L_64 ) )
return - V_50 ;
* V_38 = ( V_157 - 2732 ) * 100 ;
return 0 ;
}
break;
case V_539 :
if ( V_529 <= 7 ) {
snprintf ( V_531 , sizeof( V_531 ) , L_290 , '0' + V_529 ) ;
if ( ! F_7 ( V_463 , & V_157 , V_531 , L_64 ) )
return - V_50 ;
if ( V_157 > 127 || V_157 < - 127 )
V_157 = V_540 ;
* V_38 = V_157 * 1000 ;
return 0 ;
}
break;
case V_541 :
default:
return - V_459 ;
}
return - V_94 ;
}
static int F_308 ( struct V_542 * V_118 )
{
int V_17 , V_42 ;
int V_217 ;
V_217 = 8 ;
V_42 = 0 ;
if ( ! V_118 )
return - V_94 ;
if ( V_533 == V_535 )
V_217 = 16 ;
for ( V_42 = 0 ; V_42 < V_217 ; V_42 ++ ) {
V_17 = F_307 ( V_42 , & V_118 -> V_543 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return V_217 ;
}
static void F_203 ( void )
{
int V_217 , V_42 ;
struct V_542 V_157 ;
V_217 = F_308 ( & V_157 ) ;
if ( V_217 <= 0 )
return;
F_32 ( L_292 ) ;
for ( V_42 = 0 ; V_42 < V_217 ; V_42 ++ ) {
if ( V_157 . V_543 [ V_42 ] != V_544 )
F_309 ( L_293 , ( int ) ( V_157 . V_543 [ V_42 ] / 1000 ) ) ;
else
F_309 ( L_294 ) ;
}
F_309 ( L_295 ) ;
}
static T_8 F_310 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
struct V_545 * V_546 =
F_311 ( V_122 ) ;
int V_529 = V_546 -> V_547 ;
T_17 V_38 ;
int V_17 ;
V_17 = F_307 ( V_529 , & V_38 ) ;
if ( V_17 )
return V_17 ;
if ( V_38 == V_544 )
return - V_49 ;
return snprintf ( V_126 , V_102 , L_44 , V_38 ) ;
}
static int T_1 F_312 ( struct V_309 * V_310 )
{
T_6 V_157 , V_548 , V_549 ;
int V_42 ;
int V_550 ;
int V_17 ;
F_17 ( V_55 , L_296 ) ;
V_550 = F_7 ( V_463 , NULL , L_297 , L_263 ) ;
if ( V_7 . V_12 ) {
V_548 = V_549 = 0 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( F_11 ( V_532 + V_42 , & V_157 ) ) {
V_548 |= V_157 ;
} else {
V_548 = 0 ;
break;
}
if ( F_11 ( V_536 + V_42 , & V_157 ) ) {
V_549 |= V_157 ;
} else {
V_548 = 0 ;
break;
}
}
if ( V_548 == 0 ) {
if ( V_550 ) {
F_8 ( L_298
L_299
L_300 ) ;
V_533 = V_539 ;
} else {
F_8 ( L_298
L_301 ) ;
V_533 = V_541 ;
}
} else {
V_533 =
( V_549 != 0 ) ?
V_535 : V_537 ;
}
} else if ( V_550 ) {
if ( F_6 () &&
F_7 ( V_463 , NULL , L_291 , L_263 ) ) {
V_533 = V_538 ;
} else {
V_533 = V_539 ;
}
} else {
V_533 = V_541 ;
}
F_17 ( V_55 , L_302 ,
F_1 ( V_533 != V_541 ) ,
V_533 ) ;
switch ( V_533 ) {
case V_535 :
V_17 = F_189 ( & V_551 -> V_60 . V_125 ,
& V_552 ) ;
if ( V_17 )
return V_17 ;
break;
case V_537 :
case V_539 :
case V_538 :
V_17 = F_189 ( & V_551 -> V_60 . V_125 ,
& V_553 ) ;
if ( V_17 )
return V_17 ;
break;
case V_541 :
default:
return 1 ;
}
return 0 ;
}
static void F_313 ( void )
{
switch ( V_533 ) {
case V_535 :
F_55 ( & V_551 -> V_60 . V_125 ,
& V_552 ) ;
break;
case V_537 :
case V_539 :
case V_538 :
F_55 ( & V_551 -> V_60 . V_125 ,
& V_553 ) ;
break;
case V_541 :
default:
break;
}
}
static int F_314 ( struct V_90 * V_91 )
{
int V_217 , V_42 ;
struct V_542 V_157 ;
V_217 = F_308 ( & V_157 ) ;
if ( F_142 ( V_217 < 0 ) )
return V_217 ;
F_84 ( V_91 , L_303 ) ;
if ( V_217 > 0 ) {
for ( V_42 = 0 ; V_42 < ( V_217 - 1 ) ; V_42 ++ )
F_84 ( V_91 , L_304 , V_157 . V_543 [ V_42 ] / 1000 ) ;
F_84 ( V_91 , L_44 , V_157 . V_543 [ V_42 ] / 1000 ) ;
} else
F_84 ( V_91 , L_305 ) ;
return 0 ;
}
static unsigned int F_315 ( void )
{
T_6 V_554 ;
V_554 = ( F_131 ( V_238 )
& V_240 )
>> V_241 ;
V_554 &= V_272 ;
return V_554 ;
}
static void F_316 ( void )
{
T_6 V_555 = 0 ;
T_6 V_556 ;
if ( V_557 != V_558 )
return;
F_17 ( V_559 ,
L_306 ) ;
if ( F_157 ( & V_560 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_561 , & V_555 ) ) )
goto V_562;
V_555 &= V_563 ;
V_556 = F_131 ( V_238 ) ;
if ( V_555 != ( ( V_556 & V_240 )
>> V_241 ) ) {
V_556 &= ~ ( V_240 <<
V_241 ) ;
V_556 |= V_555 ;
F_317 ( V_556 , V_238 ) ;
F_20 ( V_559 ,
L_307 ,
( unsigned int ) V_555 , ( unsigned int ) V_556 ) ;
} else
F_17 ( V_559 ,
L_308 ,
( unsigned int ) V_555 , ( unsigned int ) V_556 ) ;
V_562:
F_118 ( & V_560 ) ;
}
static int F_318 ( int * V_30 )
{
T_6 V_555 = 0 ;
switch ( V_557 ) {
case V_564 :
* V_30 = F_315 () ;
return 0 ;
case V_565 :
case V_558 :
if ( F_142 ( ! F_11 ( V_561 , & V_555 ) ) )
return - V_50 ;
* V_30 = V_555 ;
return 0 ;
default:
return - V_49 ;
}
}
static int F_319 ( unsigned int V_38 )
{
T_6 V_555 = 0 ;
if ( F_142 ( ! F_11 ( V_561 , & V_555 ) ) )
return - V_50 ;
if ( F_142 ( ! F_13 ( V_561 ,
( V_555 & V_566 ) |
( V_38 & V_563 ) ) ) )
return - V_50 ;
return 0 ;
}
static int F_320 ( unsigned int V_38 )
{
int V_47 , V_567 ;
unsigned int V_568 , V_42 ;
V_568 = F_315 () ;
if ( V_38 == V_568 )
return 0 ;
V_47 = ( V_38 > V_568 ) ?
V_569 :
V_570 ;
V_567 = ( V_38 > V_568 ) ? 1 : - 1 ;
for ( V_42 = V_568 ; V_42 != V_38 ; V_42 += V_567 )
if ( F_15 ( V_47 ) )
return - V_50 ;
return 0 ;
}
static int V_516 ( unsigned int V_38 )
{
int V_17 ;
if ( V_38 > V_272 )
return - V_94 ;
F_17 ( V_559 ,
L_309 , V_38 ) ;
V_17 = F_157 ( & V_560 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_557 ) {
case V_565 :
case V_558 :
V_17 = F_319 ( V_38 ) ;
break;
case V_564 :
V_17 = F_320 ( V_38 ) ;
break;
default:
V_17 = - V_49 ;
}
F_118 ( & V_560 ) ;
return V_17 ;
}
static int F_321 ( struct V_571 * V_572 )
{
unsigned int V_56 =
( V_572 -> V_573 . V_574 == V_575 &&
V_572 -> V_573 . V_576 == V_575 ) ?
V_572 -> V_573 . V_473 : 0 ;
F_20 ( V_559 ,
L_310 ,
V_56 ) ;
return V_516 ( V_56 ) ;
}
static int V_518 ( struct V_571 * V_572 )
{
int V_30 , V_17 ;
V_17 = F_157 ( & V_560 ) ;
if ( V_17 < 0 )
return 0 ;
V_17 = F_318 ( & V_30 ) ;
F_118 ( & V_560 ) ;
if ( V_17 < 0 )
return 0 ;
return V_30 & V_563 ;
}
static void F_322 ( void )
{
F_323 ( V_577 ,
V_578 ) ;
}
static int T_1 F_324 ( T_3 V_16 )
{
struct V_26 V_579 = { V_580 , NULL } ;
union V_23 * V_581 ;
struct V_59 * V_74 , * V_582 ;
int V_73 ;
if ( F_22 ( V_16 , & V_74 ) )
return 0 ;
V_73 = 0 ;
F_325 (child, &device->children, node) {
T_4 V_30 = F_9 ( V_582 -> V_16 , L_311 ,
NULL , & V_579 ) ;
if ( F_31 ( V_30 ) )
continue;
V_581 = (union V_23 * ) V_579 . V_36 ;
if ( ! V_581 || ( V_581 -> type != V_583 ) ) {
F_8 ( L_312 ,
V_353 ) ;
V_73 = 0 ;
} else {
V_73 = V_581 -> V_584 . V_35 ;
}
break;
}
F_37 ( V_579 . V_36 ) ;
return V_73 ;
}
static unsigned int T_1 F_326 ( void )
{
T_3 V_585 ;
int V_586 = 0 ;
F_24 ( L_13 , NULL , & V_585 ) ;
if ( V_585 )
V_586 = F_324 ( V_585 ) ;
V_186 . V_587 = ( V_586 > 0 ) ;
return ( V_586 > 2 ) ? ( V_586 - 2 ) : 0 ;
}
static void T_1 F_327 ( void )
{
unsigned int V_588 ;
F_17 ( V_55 ,
L_313 ) ;
V_588 = F_326 () ;
switch ( V_588 ) {
case 16 :
V_272 = 15 ;
break;
case 8 :
case 0 :
V_272 = 7 ;
break;
default:
V_186 . V_273 = 1 ;
V_272 = V_588 - 1 ;
}
F_328 ( L_314 , V_272 + 1 ) ;
}
static int T_1 F_329 ( struct V_309 * V_310 )
{
struct V_589 V_573 ;
int V_588 ;
unsigned long V_13 ;
F_17 ( V_55 , L_315 ) ;
F_188 ( & V_560 ) ;
V_13 = F_4 ( V_590 ,
F_100 ( V_590 ) ) ;
if ( V_186 . V_273 )
return 1 ;
if ( ! V_591 ) {
F_20 ( V_55 | V_559 ,
L_316
L_317 ) ;
return 1 ;
}
if ( F_193 () != V_364 ) {
if ( V_591 > 1 ) {
F_76 ( L_318
L_319 ) ;
return 1 ;
} else if ( V_591 == 1 ) {
F_62 ( L_320
L_321
L_322 ) ;
return 1 ;
}
} else if ( V_186 . V_587 && V_591 > 1 ) {
F_32 ( L_323
L_324
L_325 ) ;
}
if ( V_557 > V_592 )
return - V_94 ;
if ( V_557 == V_593 ||
V_557 == V_592 ) {
if ( V_13 & V_594 )
V_557 = V_558 ;
else
V_557 = V_564 ;
F_20 ( V_559 ,
L_326 ,
V_557 ) ;
}
if ( ! F_6 () &&
( V_557 == V_558 ||
V_557 == V_565 ) )
return - V_94 ;
if ( F_318 ( & V_588 ) < 0 )
return 1 ;
memset ( & V_573 , 0 , sizeof( struct V_589 ) ) ;
V_573 . type = V_595 ;
V_573 . V_596 = V_272 ;
V_573 . V_473 = V_588 & V_563 ;
V_577 = F_330 ( V_597 ,
NULL , NULL ,
& V_598 ,
& V_573 ) ;
if ( F_147 ( V_577 ) ) {
int V_73 = F_331 ( V_577 ) ;
V_577 = NULL ;
F_8 ( L_327 ) ;
return V_73 ;
}
F_17 ( V_55 | V_559 ,
L_328 ) ;
if ( V_13 & V_599 ) {
F_32 ( L_329
L_330 , V_557 ) ;
F_32 ( L_331
L_332 , V_353 ) ;
}
F_332 ( V_577 ) ;
F_17 ( V_55 | V_559 ,
L_333
L_334 ) ;
F_114 ( V_195
| V_600
| V_601 ) ;
return 0 ;
}
static void F_333 ( void )
{
F_316 () ;
}
static void F_334 ( void )
{
F_316 () ;
}
static void F_335 ( void )
{
if ( V_577 ) {
F_17 ( V_306 | V_559 ,
L_335 ) ;
F_336 ( V_577 ) ;
}
F_316 () ;
}
static int F_337 ( struct V_90 * V_91 )
{
int V_56 ;
V_56 = V_518 ( NULL ) ;
if ( V_56 < 0 ) {
F_84 ( V_91 , L_336 ) ;
} else {
F_84 ( V_91 , L_337 , V_56 ) ;
F_84 ( V_91 , L_338 ) ;
F_84 ( V_91 , L_339 ,
V_272 ) ;
}
return 0 ;
}
static int F_338 ( char * V_126 )
{
int V_56 ;
int V_73 ;
char * V_159 ;
V_56 = V_518 ( NULL ) ;
if ( V_56 < 0 )
return V_56 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_340 ) == 0 ) {
if ( V_56 < V_272 )
V_56 ++ ;
} else if ( F_86 ( V_159 , L_341 ) == 0 ) {
if ( V_56 > 0 )
V_56 -- ;
} else if ( sscanf ( V_159 , L_342 , & V_56 ) == 1 &&
V_56 >= 0 && V_56 <= V_272 ) {
} else
return - V_94 ;
}
F_82 ( L_343 ,
L_344 , V_56 ) ;
V_73 = V_516 ( V_56 ) ;
if ( ! V_73 && V_577 )
F_323 ( V_577 ,
V_602 ) ;
return ( V_73 == - V_603 ) ? - V_294 : V_73 ;
}
static void F_339 ( void )
{
T_6 V_555 = 0 ;
T_6 V_556 ;
T_6 V_604 ;
if ( V_605 != V_606 )
return;
if ( ! V_607 )
return;
if ( V_608 )
return;
F_17 ( V_609 ,
L_345 ) ;
if ( V_186 . V_610 )
V_604 = V_611 ;
else
V_604 = V_611 | V_612 ;
if ( F_157 ( & V_613 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_614 , & V_555 ) ) )
goto V_562;
V_555 &= V_604 ;
V_556 = F_131 ( V_245 ) ;
if ( V_555 != ( V_556 & V_604 ) ) {
V_556 &= ~ V_604 ;
V_556 |= V_555 ;
F_317 ( V_556 , V_245 ) ;
F_20 ( V_609 ,
L_346 ,
( unsigned int ) V_555 , ( unsigned int ) V_556 ) ;
} else {
F_17 ( V_609 ,
L_347 ,
( unsigned int ) V_555 , ( unsigned int ) V_556 ) ;
}
V_562:
F_118 ( & V_613 ) ;
}
static int F_340 ( T_6 * V_30 )
{
T_6 V_118 ;
if ( ! F_11 ( V_614 , & V_118 ) )
return - V_50 ;
* V_30 = V_118 ;
F_20 ( V_609 , L_348 , V_118 ) ;
return 0 ;
}
static int F_341 ( T_6 * V_30 )
{
return F_340 ( V_30 ) ;
}
static int F_342 ( const T_6 V_30 )
{
if ( ! F_13 ( V_614 , V_30 ) )
return - V_50 ;
F_20 ( V_609 , L_349 , V_30 ) ;
F_343 ( 1 ) ;
return 0 ;
}
static int F_344 ( const T_6 V_30 )
{
return F_342 ( V_30 ) ;
}
static int F_345 ( const bool V_249 )
{
int V_73 ;
T_6 V_118 , V_217 ;
if ( F_157 ( & V_613 ) < 0 )
return - V_603 ;
V_73 = F_340 ( & V_118 ) ;
if ( V_73 )
goto V_562;
V_217 = ( V_249 ) ? V_118 | V_611 :
V_118 & ~ V_611 ;
if ( V_217 != V_118 ) {
V_73 = F_342 ( V_217 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_562:
F_118 ( & V_613 ) ;
return V_73 ;
}
static int F_346 ( const bool V_249 )
{
F_20 ( V_609 , L_350 ,
( V_249 ) ? L_1 : L_42 ) ;
return F_345 ( V_249 ) ;
}
static int F_347 ( const bool V_249 )
{
int V_73 ;
F_20 ( V_609 , L_351 ,
( V_249 ) ? L_1 : L_42 ) ;
V_73 = F_345 ( V_249 ) ;
return ( V_73 < 0 ) ? V_73 : 0 ;
}
static int F_348 ( const T_6 V_615 )
{
int V_73 ;
T_6 V_118 , V_217 ;
if ( V_615 > V_616 )
return - V_94 ;
if ( F_157 ( & V_613 ) < 0 )
return - V_603 ;
V_73 = F_340 ( & V_118 ) ;
if ( V_73 )
goto V_562;
V_217 = ( V_118 & ~ V_612 ) | V_615 ;
if ( V_217 != V_118 ) {
V_73 = F_342 ( V_217 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_562:
F_118 ( & V_613 ) ;
return V_73 ;
}
static int F_349 ( bool V_617 )
{
int V_27 ;
if ( ! F_5 () )
return - V_75 ;
if ( V_617 ) {
if ( ! F_7 ( V_463 , & V_618 ,
L_352 , L_107 ) )
return - V_50 ;
F_20 ( V_55 | V_609 ,
L_353 ,
V_618 ) ;
}
if ( ! F_7 ( V_463 , & V_27 , L_354 , L_249 ,
( int ) V_619 ) )
return - V_50 ;
if ( V_27 != V_619 )
F_62 ( L_355 ,
V_27 ) ;
if ( V_186 . V_610 )
V_27 = F_347 ( false ) ;
else
V_27 = F_344 ( V_616 ) ;
if ( V_27 != 0 )
F_62 ( L_356 ) ;
return 0 ;
}
static void F_350 ( void )
{
int V_620 ;
if ( ! F_7 ( V_463 , & V_620 , L_354 , L_249 , V_618 )
|| V_620 != V_618 )
F_62 ( L_357 ) ;
}
static int F_351 ( const T_6 V_615 )
{
F_20 ( V_609 ,
L_358 , V_615 ) ;
return F_348 ( V_615 ) ;
}
static void F_352 ( void )
{
struct V_621 * V_218 ;
if ( V_622 && V_622 -> V_623 ) {
V_218 = V_622 -> V_623 ;
if ( V_218 -> V_624 )
F_353 ( V_622 ,
V_625 ,
V_218 -> V_624 ) ;
if ( V_218 -> V_626 )
F_353 ( V_622 ,
V_625 ,
V_218 -> V_626 ) ;
}
}
static int F_354 ( struct V_627 * V_628 ,
struct V_629 * V_630 )
{
V_630 -> type = V_631 ;
V_630 -> V_35 = 1 ;
V_630 -> V_38 . integer . V_632 = 0 ;
V_630 -> V_38 . integer . V_127 = V_616 ;
return 0 ;
}
static int F_355 ( struct V_627 * V_628 ,
struct V_633 * V_634 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_341 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_634 -> V_38 . integer . V_38 [ 0 ] = V_118 & V_612 ;
return 0 ;
}
static int F_356 ( struct V_627 * V_628 ,
struct V_633 * V_634 )
{
F_82 ( L_359 , L_360 ,
V_634 -> V_38 . integer . V_38 [ 0 ] ) ;
return F_351 ( V_634 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static int F_357 ( struct V_627 * V_628 ,
struct V_633 * V_634 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_341 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_634 -> V_38 . integer . V_38 [ 0 ] =
( V_118 & V_611 ) ? 0 : 1 ;
return 0 ;
}
static int F_358 ( struct V_627 * V_628 ,
struct V_633 * V_634 )
{
F_82 ( L_359 , L_361 ,
V_634 -> V_38 . integer . V_38 [ 0 ] ?
L_42 : L_1 ) ;
return F_346 ( ! V_634 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static void F_359 ( void )
{
F_339 () ;
}
static void F_360 ( void )
{
if ( V_608 ) {
if ( F_349 ( false ) < 0 )
F_62 ( L_362 ) ;
} else {
F_352 () ;
}
}
static void F_361 ( void )
{
F_339 () ;
}
static void F_362 ( void )
{
if ( V_622 ) {
F_363 ( V_622 ) ;
V_622 = NULL ;
}
F_339 () ;
if ( V_608 )
F_350 () ;
}
static int T_1 F_364 ( void )
{
struct V_635 * V_636 ;
struct V_621 * V_66 ;
struct V_627 * V_637 ;
struct V_627 * V_638 ;
int V_73 ;
V_73 = F_365 ( & V_154 -> V_60 ,
V_639 , V_640 , V_641 ,
sizeof( struct V_621 ) , & V_636 ) ;
if ( V_73 < 0 || ! V_636 ) {
F_8 ( L_363 , V_73 ) ;
return 1 ;
}
F_25 ( ! V_636 -> V_623 ) ;
V_66 = V_636 -> V_623 ;
V_66 -> V_636 = V_636 ;
F_366 ( V_636 -> V_81 , V_642 ,
sizeof( V_636 -> V_81 ) ) ;
F_366 ( V_636 -> V_643 , V_644 ,
sizeof( V_636 -> V_643 ) ) ;
snprintf ( V_636 -> V_645 , sizeof( V_636 -> V_645 ) , L_364 ,
( V_7 . V_646 ) ?
V_7 . V_646 : L_365 ) ;
snprintf ( V_636 -> V_647 , sizeof( V_636 -> V_647 ) ,
L_366 , V_636 -> V_643 , V_614 ,
( V_7 . V_646 ) ?
V_7 . V_646 : L_367 ) ;
if ( V_607 ) {
V_648 . V_649 = F_356 ;
V_648 . V_650 =
V_651 ;
V_652 . V_649 = F_358 ;
V_652 . V_650 =
V_651 ;
}
if ( ! V_186 . V_610 ) {
V_637 = F_367 ( & V_648 , NULL ) ;
V_73 = F_368 ( V_636 , V_637 ) ;
if ( V_73 < 0 ) {
F_8 ( L_368 ,
V_73 ) ;
goto V_352;
}
V_66 -> V_626 = & V_637 -> V_144 ;
}
V_638 = F_367 ( & V_652 , NULL ) ;
V_73 = F_368 ( V_636 , V_638 ) ;
if ( V_73 < 0 ) {
F_8 ( L_369 , V_73 ) ;
goto V_352;
}
V_66 -> V_624 = & V_638 -> V_144 ;
V_73 = F_369 ( V_636 ) ;
if ( V_73 < 0 ) {
F_8 ( L_370 , V_73 ) ;
goto V_352;
}
V_622 = V_636 ;
return 0 ;
V_352:
F_363 ( V_636 ) ;
return 1 ;
}
static int T_1 F_370 ( struct V_309 * V_310 )
{
unsigned long V_13 ;
int V_73 ;
F_17 ( V_55 , L_371 ) ;
F_188 ( & V_613 ) ;
if ( V_605 > V_653 )
return - V_94 ;
if ( V_605 == V_654 ) {
F_8 ( L_372
L_373 , V_353 ) ;
return 1 ;
}
if ( V_655 >= V_656 )
return - V_94 ;
if ( ! V_657 ) {
F_17 ( V_55 | V_609 ,
L_374
L_375 ) ;
return 1 ;
}
V_13 = F_4 ( V_658 ,
F_100 ( V_658 ) ) ;
switch ( V_655 ) {
case V_659 :
if ( V_13 & V_660 )
V_186 . V_610 = 1 ;
else if ( V_13 & V_661 )
V_186 . V_610 = 0 ;
else
return 1 ;
break;
case V_662 :
V_186 . V_610 = 0 ;
break;
case V_663 :
V_186 . V_610 = 1 ;
break;
default:
return 1 ;
}
if ( V_655 != V_659 )
F_20 ( V_55 | V_609 ,
L_376 ,
V_655 ) ;
if ( V_605 == V_664 ||
V_605 == V_653 ) {
V_605 = V_606 ;
F_20 ( V_55 | V_609 ,
L_377 ,
V_605 ) ;
} else {
F_20 ( V_55 | V_609 ,
L_378 ,
V_605 ) ;
}
F_17 ( V_55 | V_609 ,
L_379 ,
F_1 ( ! V_186 . V_610 ) ) ;
if ( V_665 && F_349 ( true ) == 0 ) {
V_608 = true ;
} else {
V_73 = F_364 () ;
if ( V_73 ) {
F_8 ( L_380 ) ;
return V_73 ;
}
F_76 ( L_381 ,
( V_607 ) ?
L_382 :
L_383 ) ;
}
F_17 ( V_55 | V_609 ,
L_384 ) ;
F_114 ( V_195
| V_666
| V_667
| V_668 ) ;
return 0 ;
}
static int F_371 ( struct V_90 * V_91 )
{
T_6 V_30 ;
if ( F_341 ( & V_30 ) < 0 ) {
F_84 ( V_91 , L_336 ) ;
} else {
if ( V_186 . V_610 )
F_84 ( V_91 , L_385 ) ;
else
F_84 ( V_91 , L_337 ,
V_30 & V_612 ) ;
F_84 ( V_91 , L_386 ,
F_279 ( V_30 , V_669 ) ) ;
if ( V_607 ) {
F_84 ( V_91 , L_387 ) ;
if ( ! V_186 . V_610 ) {
F_84 ( V_91 ,
L_338 ) ;
F_84 ( V_91 ,
L_388
L_389 ,
V_616 ) ;
}
}
}
return 0 ;
}
static int F_372 ( char * V_126 )
{
T_6 V_118 ;
T_6 V_670 , V_671 ;
int V_672 ;
char * V_159 ;
int V_73 ;
if ( ! V_607 && V_69 != V_292 ) {
if ( F_142 ( ! V_200 . V_673 ) ) {
V_200 . V_673 = 1 ;
F_32 ( L_390
L_391 ) ;
F_32 ( L_392
L_393 ) ;
}
return - V_158 ;
}
V_73 = F_341 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_670 = V_118 & V_612 ;
V_671 = V_118 & V_611 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! V_186 . V_610 ) {
if ( F_86 ( V_159 , L_340 ) == 0 ) {
if ( V_671 )
V_671 = 0 ;
else if ( V_670 < V_616 )
V_670 ++ ;
continue;
} else if ( F_86 ( V_159 , L_341 ) == 0 ) {
if ( V_671 )
V_671 = 0 ;
else if ( V_670 > 0 )
V_670 -- ;
continue;
} else if ( sscanf ( V_159 , L_394 , & V_672 ) == 1 &&
V_672 >= 0 && V_672 <= V_616 ) {
V_670 = V_672 ;
continue;
}
}
if ( F_86 ( V_159 , L_395 ) == 0 )
V_671 = V_611 ;
else if ( F_86 ( V_159 , L_396 ) == 0 )
V_671 = 0 ;
else
return - V_94 ;
}
if ( V_186 . V_610 ) {
F_82 ( L_397 , L_361 ,
V_671 ? L_1 : L_42 ) ;
V_73 = F_347 ( ! ! V_671 ) ;
} else {
F_82 ( L_397 ,
L_398 ,
V_671 ? L_1 : L_42 , V_670 ) ;
V_73 = F_344 ( V_671 | V_670 ) ;
}
F_352 () ;
return ( V_73 == - V_603 ) ? - V_294 : V_73 ;
}
static void inline F_352 ( void )
{
}
static int T_1 F_370 ( struct V_309 * V_310 )
{
F_76 ( L_399 ) ;
return 1 ;
}
static void F_373 ( void )
{
if ( V_674 == 0x07 ) {
F_32 ( L_400
L_401 ) ;
V_186 . V_675 = 1 ;
}
}
static void F_374 ( T_6 * V_676 )
{
if ( F_142 ( V_186 . V_675 ) ) {
if ( * V_676 != V_674 ) {
V_186 . V_675 = 0 ;
} else {
* V_676 = V_677 ;
}
}
}
static bool F_375 ( void )
{
if ( V_186 . V_678 ) {
T_6 V_679 ;
if ( F_12 ( V_680 , & V_679 ) < 0 )
return false ;
V_679 &= 0xFEU ;
if ( F_14 ( V_680 , V_679 ) < 0 )
return false ;
}
return true ;
}
static bool F_376 ( void )
{
T_6 V_679 ;
if ( ! V_186 . V_678 )
return false ;
if ( F_12 ( V_680 , & V_679 ) < 0 )
return false ;
V_679 |= 0x01U ;
if ( F_14 ( V_680 , V_679 ) < 0 )
return false ;
return true ;
}
static void F_377 ( T_6 V_30 )
{
if ( ( V_30 &
( V_677 | V_681 ) ) == 0 ) {
if ( V_30 > 7 )
V_682 = 7 ;
else
V_682 = V_30 ;
}
}
static int F_378 ( T_6 * V_30 )
{
T_6 V_118 ;
switch ( V_683 ) {
case V_684 : {
int V_17 ;
if ( F_142 ( ! F_7 ( V_685 , & V_17 , NULL , L_64 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) )
* V_30 = V_17 & 0x07 ;
break;
}
case V_686 :
if ( F_142 ( ! F_11 ( V_687 , & V_118 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) ) {
* V_30 = V_118 ;
F_374 ( V_30 ) ;
}
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_379 ( T_6 * V_30 )
{
int V_73 ;
T_6 V_118 ;
if ( F_157 ( & V_688 ) )
return - V_294 ;
V_73 = F_378 ( & V_118 ) ;
if ( ! V_73 )
F_377 ( V_118 ) ;
F_118 ( & V_688 ) ;
if ( V_73 )
return V_73 ;
if ( V_30 )
* V_30 = V_118 ;
return 0 ;
}
static int F_380 ( unsigned int * V_689 )
{
T_6 V_690 , V_691 ;
switch ( V_683 ) {
case V_686 :
if ( F_142 ( ! F_375 () ) )
return - V_50 ;
if ( F_142 ( ! F_11 ( V_692 , & V_691 ) ||
! F_11 ( V_692 + 1 , & V_690 ) ) )
return - V_50 ;
if ( F_140 ( V_689 ) )
* V_689 = ( V_690 << 8 ) | V_691 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_381 ( unsigned int * V_689 )
{
T_6 V_690 , V_691 ;
bool V_73 ;
switch ( V_683 ) {
case V_686 :
if ( F_142 ( ! F_376 () ) )
return - V_50 ;
V_73 = ! F_11 ( V_692 , & V_691 ) ||
! F_11 ( V_692 + 1 , & V_690 ) ;
F_375 () ;
if ( V_73 )
return - V_50 ;
if ( F_140 ( V_689 ) )
* V_689 = ( V_690 << 8 ) | V_691 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_382 ( int V_56 )
{
if ( ! V_693 )
return - V_158 ;
switch ( V_694 ) {
case V_695 :
if ( V_56 >= 0 && V_56 <= 7 ) {
if ( ! F_7 ( V_696 , NULL , NULL , L_9 , V_56 ) )
return - V_50 ;
} else
return - V_94 ;
break;
case V_697 :
case V_698 :
if ( ! ( V_56 & V_677 ) &&
! ( V_56 & V_681 ) &&
( ( V_56 < 0 ) || ( V_56 > 7 ) ) )
return - V_94 ;
if ( V_56 & V_681 )
V_56 |= 7 ;
else if ( V_56 & V_677 )
V_56 |= 4 ;
if ( ! F_13 ( V_687 , V_56 ) )
return - V_50 ;
else
V_186 . V_675 = 0 ;
break;
default:
return - V_49 ;
}
F_17 ( V_699 ,
L_402 , V_56 ) ;
return 0 ;
}
static int F_383 ( int V_56 )
{
int V_73 ;
if ( ! V_693 )
return - V_158 ;
if ( F_157 ( & V_688 ) )
return - V_294 ;
if ( V_56 == V_700 )
V_56 = V_682 ;
V_73 = F_382 ( V_56 ) ;
if ( ! V_73 )
F_377 ( V_56 ) ;
F_118 ( & V_688 ) ;
return V_73 ;
}
static int F_384 ( void )
{
T_6 V_118 ;
int V_73 ;
if ( ! V_693 )
return - V_158 ;
if ( F_157 ( & V_688 ) )
return - V_294 ;
switch ( V_694 ) {
case V_697 :
case V_698 :
V_73 = F_378 ( & V_118 ) ;
if ( V_73 < 0 )
break;
if ( V_118 != 7 ) {
V_118 &= 0x07 ;
V_118 |= V_677 | 4 ;
}
if ( ! F_13 ( V_687 , V_118 ) )
V_73 = - V_50 ;
else {
V_186 . V_675 = 0 ;
V_73 = 0 ;
}
break;
case V_695 :
V_73 = F_378 ( & V_118 ) ;
if ( V_73 < 0 )
break;
V_118 &= 0x07 ;
V_118 |= 4 ;
if ( ! F_7 ( V_696 , NULL , NULL , L_9 , V_118 ) )
V_73 = - V_50 ;
else
V_73 = 0 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_688 ) ;
if ( ! V_73 )
F_17 ( V_699 ,
L_402 ,
V_118 ) ;
return V_73 ;
}
static int F_385 ( void )
{
int V_73 ;
if ( ! V_693 )
return - V_158 ;
if ( F_157 ( & V_688 ) )
return - V_294 ;
V_73 = 0 ;
switch ( V_694 ) {
case V_697 :
case V_698 :
if ( ! F_13 ( V_687 , 0x00 ) )
V_73 = - V_50 ;
else {
V_682 = 0 ;
V_186 . V_675 = 0 ;
}
break;
case V_695 :
if ( ! F_7 ( V_696 , NULL , NULL , L_9 , 0x00 ) )
V_73 = - V_50 ;
else
V_682 = 0 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
F_17 ( V_699 ,
L_403 ) ;
F_118 ( & V_688 ) ;
return V_73 ;
}
static int F_386 ( int V_689 )
{
int V_73 ;
if ( ! V_693 )
return - V_158 ;
if ( F_157 ( & V_688 ) )
return - V_294 ;
V_73 = 0 ;
switch ( V_694 ) {
case V_697 :
if ( V_689 >= 0 && V_689 <= 65535 ) {
if ( ! F_7 ( V_701 , NULL , NULL , L_404 ,
V_689 , V_689 , V_689 ) )
V_73 = - V_50 ;
} else
V_73 = - V_94 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_688 ) ;
return V_73 ;
}
static void F_387 ( void )
{
if ( V_694 == V_702 )
return;
if ( V_703 > 0 &&
V_69 != V_199 )
F_388 ( V_474 , & V_704 ,
F_389 ( V_703 * 1000 ) ) ;
else
F_390 ( & V_704 ) ;
}
static void F_391 ( struct V_466 * V_705 )
{
int V_73 ;
if ( V_69 != V_70 )
return;
F_32 ( L_405 ) ;
V_73 = F_384 () ;
if ( V_73 < 0 ) {
F_8 ( L_406
L_407 , - V_73 ) ;
F_387 () ;
}
}
static T_8 F_392 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_366 ;
T_6 V_30 ;
V_17 = F_379 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 & V_681 ) {
V_366 = 0 ;
} else if ( V_30 & V_677 ) {
V_366 = 2 ;
} else
V_366 = 1 ;
return snprintf ( V_126 , V_102 , L_44 , V_366 ) ;
}
static T_8 F_393 ( struct V_74 * V_60 ,
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
V_56 = V_681 ;
break;
case 1 :
V_56 = V_700 ;
break;
case 2 :
V_56 = V_677 ;
break;
case 3 :
return - V_459 ;
default:
return - V_94 ;
}
V_17 = F_383 ( V_56 ) ;
if ( V_17 == - V_49 )
return - V_94 ;
else if ( V_17 < 0 )
return V_17 ;
F_387 () ;
return V_35 ;
}
static T_8 F_394 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
T_6 V_30 ;
V_17 = F_379 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_30 &
( V_677 | V_681 ) ) != 0 )
V_30 = V_682 ;
if ( V_30 > 7 )
V_30 = 7 ;
return snprintf ( V_126 , V_102 , L_410 , ( V_30 * 255 ) / 7 ) ;
}
static T_8 F_395 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_118 ;
int V_73 ;
T_6 V_30 , V_706 ;
if ( F_57 ( V_126 , 255 , & V_118 ) )
return - V_94 ;
F_82 ( L_411 ,
L_412 , V_118 ) ;
V_706 = ( V_118 >> 5 ) & 0x07 ;
if ( F_157 ( & V_688 ) )
return - V_294 ;
V_73 = F_378 ( & V_30 ) ;
if ( ! V_73 && ( V_30 &
( V_677 | V_681 ) ) == 0 ) {
V_73 = F_382 ( V_706 ) ;
if ( V_73 == - V_49 )
V_73 = - V_94 ;
else if ( ! V_73 ) {
F_377 ( V_706 ) ;
F_387 () ;
}
}
F_118 ( & V_688 ) ;
return ( V_73 ) ? V_73 : V_35 ;
}
static T_8 F_396 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_689 ;
V_17 = F_380 ( & V_689 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_410 , V_689 ) ;
}
static T_8 F_397 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_689 ;
V_17 = F_381 ( & V_689 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_410 , V_689 ) ;
}
static T_8 F_398 ( struct V_161 * V_162 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_410 , V_703 ) ;
}
static T_8 F_399 ( struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 120 , & V_157 ) )
return - V_94 ;
if ( ! V_693 )
return - V_158 ;
V_703 = V_157 ;
F_387 () ;
F_82 ( L_413 , L_96 , V_157 ) ;
return V_35 ;
}
static int T_1 F_400 ( struct V_309 * V_310 )
{
int V_73 ;
unsigned long V_13 ;
F_17 ( V_55 | V_699 ,
L_414 ) ;
F_188 ( & V_688 ) ;
V_683 = V_707 ;
V_694 = V_702 ;
V_708 = 0 ;
V_703 = 0 ;
V_186 . V_675 = 0 ;
V_186 . V_678 = 0 ;
V_682 = 7 ;
if ( F_6 () ) {
F_187 ( V_709 ) ;
F_187 ( V_710 ) ;
F_187 ( V_711 ) ;
}
V_13 = F_4 ( V_712 ,
F_100 ( V_712 ) ) ;
if ( V_685 ) {
V_683 = V_684 ;
} else {
if ( F_140 ( F_11 ( V_687 ,
& V_674 ) ) ) {
V_683 = V_686 ;
if ( V_13 & V_713 )
F_373 () ;
if ( V_13 & V_714 ) {
V_186 . V_678 = 1 ;
F_20 ( V_55 | V_699 ,
L_415 ) ;
}
} else {
F_8 ( L_298
L_416 ) ;
return 1 ;
}
}
if ( V_696 ) {
V_694 = V_695 ;
V_708 |=
V_715 | V_716 ;
} else {
if ( ! V_685 ) {
if ( V_701 ) {
V_694 =
V_697 ;
V_708 |=
V_717 |
V_715 |
V_716 ;
} else {
V_694 = V_698 ;
V_708 |=
V_715 |
V_716 ;
}
}
}
F_17 ( V_55 | V_699 ,
L_417 ,
F_1 ( V_683 != V_707 ||
V_694 != V_702 ) ,
V_683 , V_694 ) ;
if ( ! V_693 ) {
V_694 = V_702 ;
V_708 = 0 ;
F_20 ( V_55 | V_699 ,
L_418 ) ;
}
if ( V_683 != V_707 )
F_379 ( NULL ) ;
if ( V_683 != V_707 ||
V_694 != V_702 ) {
if ( V_186 . V_678 ) {
V_718 [ F_100 ( V_718 ) - 2 ] =
& V_719 . V_122 ;
}
V_73 = F_189 ( & V_551 -> V_60 . V_125 ,
& V_720 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_101 ( & V_721 . V_81 ,
& V_722 ) ;
if ( V_73 < 0 ) {
F_55 ( & V_551 -> V_60 . V_125 ,
& V_720 ) ;
return V_73 ;
}
return 0 ;
} else
return 1 ;
}
static void F_401 ( void )
{
F_17 ( V_306 | V_699 ,
L_419 ) ;
F_55 ( & V_551 -> V_60 . V_125 , & V_720 ) ;
F_104 ( & V_721 . V_81 ,
& V_722 ) ;
F_390 ( & V_704 ) ;
F_263 ( V_474 ) ;
}
static void F_402 ( void )
{
int V_73 ;
if ( ! V_693 )
return;
V_723 = 0 ;
V_73 = F_379 ( & V_723 ) ;
if ( V_73 < 0 )
F_32 ( L_420
L_421 , V_73 ) ;
if ( V_186 . V_675 )
V_723 = 0 ;
}
static void F_403 ( void )
{
T_6 V_724 = 7 ;
bool V_725 = false ;
int V_73 ;
V_186 . V_675 = 0 ;
if ( ! V_693 ||
! V_723 ||
( F_379 ( & V_724 ) < 0 ) )
return;
switch ( V_694 ) {
case V_695 :
V_725 = ( V_723 > V_724 ) ;
break;
case V_697 :
case V_698 :
if ( V_723 != 7 &&
! ( V_723 & V_681 ) )
return;
else
V_725 = ! ( V_724 & V_681 ) &&
( V_724 != V_723 ) ;
break;
default:
return;
}
if ( V_725 ) {
F_32 ( L_422 ,
V_723 ) ;
V_73 = F_383 ( V_723 ) ;
if ( V_73 < 0 )
F_32 ( L_423 , V_73 ) ;
}
}
static int F_404 ( struct V_90 * V_91 )
{
int V_73 ;
T_6 V_30 ;
unsigned int V_689 = 0 ;
switch ( V_683 ) {
case V_684 :
V_73 = F_379 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47
L_337 ,
( V_30 != 0 ) ? L_48 : L_49 , V_30 ) ;
break;
case V_686 :
V_73 = F_379 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_47 ,
( V_30 != 0 ) ? L_48 : L_49 ) ;
V_73 = F_380 ( & V_689 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_424 , V_689 ) ;
if ( V_30 & V_681 )
F_84 ( V_91 , L_425 ) ;
else if ( V_30 & V_677 )
F_84 ( V_91 , L_426 ) ;
else
F_84 ( V_91 , L_337 , V_30 ) ;
break;
case V_707 :
default:
F_84 ( V_91 , L_46 ) ;
}
if ( V_708 & V_715 ) {
F_84 ( V_91 , L_388 ) ;
switch ( V_694 ) {
case V_695 :
F_84 ( V_91 , L_427 ) ;
break;
default:
F_84 ( V_91 , L_428
L_429 ) ;
break;
}
}
if ( V_708 & V_716 )
F_84 ( V_91 , L_50
L_430
L_431 ) ;
if ( V_708 & V_717 )
F_84 ( V_91 , L_432
L_433 ) ;
return 0 ;
}
static int F_405 ( const char * V_159 , int * V_73 )
{
int V_56 ;
if ( F_86 ( V_159 , L_434 ) == 0 )
V_56 = V_677 ;
else if ( ( F_86 ( V_159 , L_435 ) == 0 ) |
( F_86 ( V_159 , L_436 ) == 0 ) )
V_56 = V_681 ;
else if ( sscanf ( V_159 , L_342 , & V_56 ) != 1 )
return 0 ;
* V_73 = F_383 ( V_56 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_437 ,
V_694 ) ;
else if ( ! * V_73 )
F_82 ( L_438 ,
L_344 , V_56 ) ;
return 1 ;
}
static int F_406 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_51 ) != 0 )
return 0 ;
* V_73 = F_384 () ;
if ( * V_73 == - V_49 )
F_8 ( L_439 ,
V_694 ) ;
else if ( ! * V_73 )
F_82 ( L_438 , L_440 ) ;
return 1 ;
}
static int F_407 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_52 ) != 0 )
return 0 ;
* V_73 = F_385 () ;
if ( * V_73 == - V_49 )
F_8 ( L_441 ,
V_694 ) ;
else if ( ! * V_73 )
F_82 ( L_438 , L_442 ) ;
return 1 ;
}
static int F_408 ( const char * V_159 , int * V_73 )
{
int V_689 ;
if ( sscanf ( V_159 , L_443 , & V_689 ) != 1 )
return 0 ;
* V_73 = F_386 ( V_689 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_444 ,
V_694 ) ;
else if ( ! * V_73 )
F_82 ( L_438 ,
L_445 , V_689 ) ;
return 1 ;
}
static int F_409 ( const char * V_159 , int * V_73 )
{
int V_726 ;
if ( sscanf ( V_159 , L_446 , & V_726 ) != 1 )
return 0 ;
if ( V_726 < 0 || V_726 > 120 )
* V_73 = - V_94 ;
else {
V_703 = V_726 ;
F_82 ( L_438 ,
L_447 ,
V_726 ) ;
}
return 1 ;
}
static int F_410 ( char * V_126 )
{
char * V_159 ;
int V_73 = 0 ;
while ( ! V_73 && ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! ( ( V_708 & V_715 ) &&
F_405 ( V_159 , & V_73 ) ) &&
! ( ( V_708 & V_716 ) &&
( F_406 ( V_159 , & V_73 ) ||
F_407 ( V_159 , & V_73 ) ||
F_409 ( V_159 , & V_73 ) ) ) &&
! ( ( V_708 & V_717 ) &&
F_408 ( V_159 , & V_73 ) )
)
V_73 = - V_94 ;
else if ( ! V_73 )
F_387 () ;
}
return V_73 ;
}
static int F_411 ( struct V_727 * V_157 , bool V_205 )
{
T_3 V_543 ;
int V_728 ;
if ( ! F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_543 ) ) ) {
F_62 ( L_448 , V_157 -> V_51 ) ;
return - V_50 ;
}
if ( ! F_7 ( V_129 , & V_728 , V_157 -> V_51 , L_7 ,
V_205 ? V_157 -> V_729 : V_157 -> V_730 ) )
return - V_50 ;
V_157 -> V_205 = V_205 ;
return V_205 ;
}
int F_412 ( int V_731 , bool V_732 )
{
struct V_727 * V_157 ;
if ( V_731 < 0 || V_731 >= V_733 )
return - V_94 ;
V_157 = & V_734 [ V_731 ] ;
if ( V_157 -> V_205 < 0 || V_157 -> V_205 == V_732 )
return V_157 -> V_205 ;
return F_411 ( V_157 , V_732 ) ;
}
static int F_413 ( struct V_309 * V_310 )
{
T_3 V_543 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_733 ; V_42 ++ ) {
struct V_727 * V_157 = & V_734 [ V_42 ] ;
if ( F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_543 ) ) )
F_411 ( V_157 , false ) ;
else
V_157 -> V_205 = - V_75 ;
}
return 0 ;
}
static void F_414 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_733 ; V_42 ++ )
F_412 ( V_42 , false ) ;
}
static void F_415 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_733 ; V_42 ++ ) {
struct V_727 * V_157 = & V_734 [ V_42 ] ;
if ( V_157 -> V_205 >= 0 )
F_411 ( V_157 , V_157 -> V_205 ) ;
}
}
static void F_416 ( const unsigned int V_735 )
{
if ( V_577 ) {
switch ( V_735 ) {
case V_736 :
case V_737 :
F_322 () ;
}
}
if ( V_622 ) {
switch ( V_735 ) {
case V_738 :
case V_739 :
case V_740 :
F_352 () ;
}
}
}
static void F_128 ( const unsigned int V_210 )
{
F_416 ( V_741 + V_210 ) ;
}
static T_8 F_417 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_449 , V_85 ) ;
}
static const char * T_1 F_1 ( int V_1 )
{
static char V_742 [] V_743 = L_450 ;
return ( V_1 ) ? & V_742 [ 4 ] : & V_742 [ 0 ] ;
}
static void F_418 ( struct V_67 * V_68 )
{
F_20 ( V_306 , L_451 , V_68 -> V_51 ) ;
F_419 ( & V_68 -> V_744 ) ;
if ( V_68 -> V_79 . V_80 ) {
F_20 ( V_306 ,
L_452 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_420 ( * V_68 -> V_71 -> V_16 ,
V_68 -> V_71 -> type ,
F_27 ) ;
V_68 -> V_79 . V_80 = 0 ;
}
if ( V_68 -> V_79 . V_745 ) {
F_20 ( V_306 ,
L_453 , V_68 -> V_51 ) ;
F_421 ( V_68 -> V_51 , V_746 ) ;
V_68 -> V_79 . V_745 = 0 ;
}
if ( V_68 -> V_79 . V_89 ) {
F_20 ( V_306 ,
L_454 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_422 ( V_68 -> V_71 -> V_81 ) ;
F_37 ( V_68 -> V_71 -> V_81 ) ;
V_68 -> V_71 -> V_81 = NULL ;
V_68 -> V_79 . V_89 = 0 ;
}
if ( V_68 -> V_79 . V_747 && V_68 -> exit ) {
V_68 -> exit () ;
V_68 -> V_79 . V_747 = 0 ;
}
F_20 ( V_55 , L_455 , V_68 -> V_51 ) ;
}
static int T_1 F_423 ( struct V_309 * V_310 )
{
int V_100 ;
struct V_67 * V_68 = V_310 -> V_66 ;
struct V_748 * V_749 ;
F_25 ( V_68 == NULL ) ;
F_424 ( & V_68 -> V_744 ) ;
if ( V_68 -> V_79 . V_750 && ! V_750 )
return 0 ;
F_20 ( V_55 ,
L_456 , V_68 -> V_51 ) ;
if ( V_310 -> V_751 ) {
V_100 = V_310 -> V_751 ( V_310 ) ;
if ( V_100 > 0 )
return 0 ;
if ( V_100 )
return V_100 ;
V_68 -> V_79 . V_747 = 1 ;
}
if ( V_68 -> V_71 ) {
if ( V_68 -> V_71 -> V_63 ) {
V_100 = F_34 ( V_68 ) ;
if ( V_100 )
goto V_752;
}
if ( V_68 -> V_71 -> V_72 ) {
V_100 = F_28 ( V_68 ) ;
if ( V_100 == - V_75 ) {
F_32 ( L_457 ,
V_68 -> V_51 ) ;
V_100 = 0 ;
goto V_752;
}
if ( V_100 < 0 )
goto V_752;
}
}
F_20 ( V_55 ,
L_458 , V_68 -> V_51 ) ;
if ( V_68 -> V_93 ) {
T_19 V_366 = V_310 -> V_753 ;
if ( ! V_366 )
V_366 = V_754 ;
if ( V_68 -> V_101 )
V_366 |= V_755 ;
V_749 = F_425 ( V_68 -> V_51 , V_366 , V_746 ,
& V_756 , V_68 ) ;
if ( ! V_749 ) {
F_8 ( L_459 , V_68 -> V_51 ) ;
V_100 = - V_75 ;
goto V_752;
}
V_68 -> V_79 . V_745 = 1 ;
}
F_426 ( & V_68 -> V_744 , & V_757 ) ;
return 0 ;
V_752:
F_20 ( V_55 ,
L_460 ,
V_68 -> V_51 , V_100 ) ;
F_418 ( V_68 ) ;
return ( V_100 < 0 ) ? V_100 : 0 ;
}
static bool T_2 T_1 F_427 ( const char V_37 )
{
return ( V_37 >= '0' && V_37 <= '9' ) || ( V_37 >= 'A' && V_37 <= 'Z' ) ;
}
static bool T_2 T_1 F_428 ( const char * const V_118 ,
const char V_157 )
{
if ( V_118 && strlen ( V_118 ) >= 8 &&
F_427 ( V_118 [ 0 ] ) &&
F_427 ( V_118 [ 1 ] ) &&
V_118 [ 2 ] == V_157 &&
( V_118 [ 3 ] == 'T' || V_118 [ 3 ] == 'N' ) &&
F_427 ( V_118 [ 4 ] ) &&
F_427 ( V_118 [ 5 ] ) )
return true ;
return V_118 && strlen ( V_118 ) >= 8 &&
F_427 ( V_118 [ 0 ] ) &&
F_427 ( V_118 [ 1 ] ) &&
F_427 ( V_118 [ 2 ] ) &&
V_118 [ 3 ] == V_157 &&
( V_118 [ 4 ] == 'T' || V_118 [ 4 ] == 'N' ) &&
F_427 ( V_118 [ 5 ] ) &&
F_427 ( V_118 [ 6 ] ) ;
}
static int T_20 T_1 F_429 (
struct V_758 * V_759 )
{
const struct V_760 * V_60 = NULL ;
char V_761 [ 18 ] ;
char const * V_118 ;
if ( ! V_759 )
return - V_94 ;
memset ( V_759 , 0 , sizeof( * V_759 ) ) ;
if ( F_430 ( L_461 ) )
V_759 -> V_6 = V_15 ;
else if ( F_430 ( L_462 ) )
V_759 -> V_6 = V_14 ;
else
return 0 ;
V_118 = F_431 ( V_762 ) ;
V_759 -> V_763 = F_432 ( V_118 , V_83 ) ;
if ( V_118 && ! V_759 -> V_763 )
return - V_84 ;
if ( ! ( F_428 ( V_759 -> V_763 , 'E' ) ||
F_428 ( V_759 -> V_763 , 'C' ) ) )
return 0 ;
V_759 -> V_10 = V_759 -> V_763 [ 0 ]
| ( V_759 -> V_763 [ 1 ] << 8 ) ;
V_759 -> V_184 = ( V_759 -> V_763 [ 4 ] << 8 )
| V_759 -> V_763 [ 5 ] ;
while ( ( V_60 = F_433 ( V_764 , NULL , V_60 ) ) ) {
if ( sscanf ( V_60 -> V_51 ,
L_463 ,
V_761 ) == 1 ) {
V_761 [ sizeof( V_761 ) - 1 ] = 0 ;
V_761 [ strcspn ( V_761 , L_464 ) ] = 0 ;
V_759 -> V_646 = F_432 ( V_761 , V_83 ) ;
if ( ! V_759 -> V_646 )
return - V_84 ;
if ( F_428 ( V_761 , 'H' ) ) {
V_759 -> V_12 = V_761 [ 0 ]
| ( V_761 [ 1 ] << 8 ) ;
V_759 -> V_185 = ( V_761 [ 4 ] << 8 )
| V_761 [ 5 ] ;
} else {
F_32 ( L_465
L_466 ,
V_761 ) ;
F_32 ( L_112 ,
V_353 ) ;
}
break;
}
}
V_118 = F_431 ( V_765 ) ;
if ( V_118 && ! ( strncasecmp ( V_118 , L_467 , 8 ) && strncasecmp ( V_118 , L_468 , 6 ) ) ) {
V_759 -> V_766 = F_432 ( V_118 , V_83 ) ;
if ( ! V_759 -> V_766 )
return - V_84 ;
} else {
V_118 = F_431 ( V_767 ) ;
if ( V_118 && ! ( strncasecmp ( V_118 , L_468 , 6 ) ) ) {
V_759 -> V_766 = F_432 ( V_118 , V_83 ) ;
if ( ! V_759 -> V_766 )
return - V_84 ;
}
}
V_118 = F_431 ( V_768 ) ;
V_759 -> V_769 = F_432 ( V_118 , V_83 ) ;
if ( V_118 && ! V_759 -> V_769 )
return - V_84 ;
return 0 ;
}
static int T_1 F_434 ( void )
{
int V_770 ;
if ( V_771 )
return - V_75 ;
if ( ! F_6 () && ! F_5 () )
return - V_75 ;
V_770 = ( V_7 . V_766 != NULL ) ||
( V_7 . V_12 != 0 ) ||
F_107 () ;
F_24 ( L_469 , V_772 , & V_463 ) ;
if ( ! V_463 ) {
if ( V_770 )
F_8 ( L_470 ) ;
return - V_75 ;
}
if ( ! V_770 && ! V_773 )
return - V_75 ;
return 0 ;
}
static void T_1 F_435 ( void )
{
F_76 ( L_57 , V_165 , V_166 ) ;
F_76 ( L_449 , V_774 ) ;
F_76 ( L_471 ,
( V_7 . V_763 ) ?
V_7 . V_763 : L_367 ,
( V_7 . V_646 ) ?
V_7 . V_646 : L_367 ) ;
F_25 ( ! V_7 . V_6 ) ;
if ( V_7 . V_766 )
F_76 ( L_472 ,
( V_7 . V_6 == V_15 ) ?
L_461 : ( ( V_7 . V_6 ==
V_14 ) ?
L_468 : L_473 ) ,
V_7 . V_766 ,
( V_7 . V_769 ) ?
V_7 . V_769 : L_367 ) ;
}
static int T_1 F_436 ( const char * V_679 , struct V_775 * V_776 )
{
unsigned int V_42 ;
struct V_67 * V_68 ;
if ( ! V_776 || ! V_776 -> V_51 || ! V_679 )
return - V_94 ;
for ( V_42 = 0 ; V_42 < F_100 ( V_777 ) ; V_42 ++ ) {
V_68 = V_777 [ V_42 ] . V_66 ;
F_437 ( V_68 == NULL ) ;
if ( ! V_68 || ! V_68 -> V_51 )
continue;
if ( strcmp ( V_68 -> V_51 , V_776 -> V_51 ) == 0 && V_68 -> V_101 ) {
if ( strlen ( V_679 ) > sizeof( V_777 [ V_42 ] . V_778 ) - 2 )
return - V_779 ;
strcpy ( V_777 [ V_42 ] . V_778 , V_679 ) ;
strcat ( V_777 [ V_42 ] . V_778 , L_28 ) ;
return 0 ;
}
}
return - V_94 ;
}
static void F_438 ( void )
{
struct V_67 * V_68 , * V_107 ;
V_69 = V_199 ;
F_439 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
F_418 ( V_68 ) ;
}
F_20 ( V_55 , L_474 ) ;
if ( V_208 ) {
if ( V_186 . V_780 )
F_440 ( V_208 ) ;
else
F_441 ( V_208 ) ;
F_37 ( V_212 ) ;
}
if ( V_781 )
F_442 ( V_781 ) ;
if ( V_186 . V_782 )
F_285 ( & V_551 -> V_60 , & V_783 ) ;
if ( V_551 )
F_443 ( V_551 ) ;
if ( V_154 )
F_443 ( V_154 ) ;
if ( V_186 . V_784 )
F_103 ( & V_721 . V_81 ) ;
if ( V_186 . V_785 )
F_103 ( & V_786 . V_81 ) ;
if ( V_186 . V_787 )
F_444 ( & V_721 ) ;
if ( V_186 . V_788 )
F_444 ( & V_786 ) ;
if ( V_746 )
F_421 ( V_789 , V_790 ) ;
if ( V_474 )
F_445 ( V_474 ) ;
F_37 ( V_7 . V_763 ) ;
F_37 ( V_7 . V_646 ) ;
F_37 ( V_7 . V_766 ) ;
F_37 ( V_7 . V_769 ) ;
}
static int T_1 F_446 ( void )
{
int V_100 , V_42 ;
V_69 = V_292 ;
V_100 = F_429 ( & V_7 ) ;
if ( V_100 ) {
F_8 ( L_475 , V_100 ) ;
F_438 () ;
return V_100 ;
}
V_100 = F_434 () ;
if ( V_100 ) {
F_438 () ;
return V_100 ;
}
F_435 () ;
F_106 () ;
F_187 ( V_791 ) ;
F_187 ( V_792 ) ;
V_474 = F_447 ( V_793 ) ;
if ( ! V_474 ) {
F_438 () ;
return - V_84 ;
}
V_746 = F_448 ( V_789 , V_790 ) ;
if ( ! V_746 ) {
F_8 ( L_476 V_789 L_295 ) ;
F_438 () ;
return - V_75 ;
}
V_100 = F_449 ( & V_786 ) ;
if ( V_100 ) {
F_8 ( L_477 ) ;
F_438 () ;
return V_100 ;
}
V_186 . V_788 = 1 ;
V_100 = F_449 ( & V_721 ) ;
if ( V_100 ) {
F_8 ( L_478 ) ;
F_438 () ;
return V_100 ;
}
V_186 . V_787 = 1 ;
V_100 = F_99 ( & V_786 . V_81 ) ;
if ( ! V_100 ) {
V_186 . V_785 = 1 ;
V_100 = F_99 (
& V_721 . V_81 ) ;
}
if ( V_100 ) {
F_8 ( L_479 ) ;
F_438 () ;
return V_100 ;
}
V_186 . V_784 = 1 ;
V_154 = F_450 ( V_794 , - 1 ,
NULL , 0 ) ;
if ( F_147 ( V_154 ) ) {
V_100 = F_331 ( V_154 ) ;
V_154 = NULL ;
F_8 ( L_480 ) ;
F_438 () ;
return V_100 ;
}
V_551 = F_450 (
V_795 ,
- 1 , NULL , 0 ) ;
if ( F_147 ( V_551 ) ) {
V_100 = F_331 ( V_551 ) ;
V_551 = NULL ;
F_8 ( L_481 ) ;
F_438 () ;
return V_100 ;
}
V_100 = F_283 ( & V_551 -> V_60 , & V_783 ) ;
if ( V_100 ) {
F_8 ( L_482 ) ;
F_438 () ;
return V_100 ;
}
V_186 . V_782 = 1 ;
V_781 = F_451 ( & V_551 -> V_60 ) ;
if ( F_147 ( V_781 ) ) {
V_100 = F_331 ( V_781 ) ;
V_781 = NULL ;
F_8 ( L_483 ) ;
F_438 () ;
return V_100 ;
}
F_188 ( & V_207 ) ;
V_208 = F_452 () ;
if ( ! V_208 ) {
F_438 () ;
return - V_84 ;
} else {
V_208 -> V_51 = L_484 ;
V_208 -> V_796 = V_794 L_485 ;
V_208 -> V_144 . V_797 = V_798 ;
V_208 -> V_144 . V_6 = V_7 . V_6 ;
V_208 -> V_144 . V_799 = V_800 ;
V_208 -> V_144 . V_801 = V_802 ;
V_208 -> V_60 . V_52 = & V_154 -> V_60 ;
}
F_327 () ;
for ( V_42 = 0 ; V_42 < F_100 ( V_777 ) ; V_42 ++ ) {
V_100 = F_423 ( & V_777 [ V_42 ] ) ;
if ( V_100 >= 0 && * V_777 [ V_42 ] . V_778 )
V_100 = V_777 [ V_42 ] . V_66 -> V_101 ( V_777 [ V_42 ] . V_778 ) ;
if ( V_100 < 0 ) {
F_438 () ;
return V_100 ;
}
}
V_69 = V_70 ;
V_100 = F_453 ( V_208 ) ;
if ( V_100 < 0 ) {
F_8 ( L_486 ) ;
F_438 () ;
return V_100 ;
} else {
V_186 . V_780 = 1 ;
}
return 0 ;
}
