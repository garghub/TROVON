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
F_8 ( L_4 ,
V_37 ) ;
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
F_8 ( L_4 ,
V_32 ) ;
return 0 ;
}
if ( ! V_33 && ! V_34 )
F_8 ( L_5 ,
V_18 , V_20 , F_10 ( V_30 ) ) ;
return V_33 ;
}
static int F_11 ( int V_42 , T_6 * V_43 )
{
int V_44 ;
if ( V_45 ) {
if ( ! F_7 ( V_45 , & V_44 , NULL , L_6 , V_42 ) )
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
if ( ! F_7 ( V_46 , NULL , NULL , L_7 , V_42 , V_44 ) )
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
if ( ! F_7 ( V_48 , NULL , NULL , L_8 , V_47 ) )
return - V_50 ;
return 0 ;
}
static void T_1 F_16 ( const char * V_51 ,
T_3 * V_16 , const T_3 V_52 ,
char * * V_53 , const int V_54 )
{
int V_42 ;
T_4 V_30 ;
F_17 ( V_55 , L_9 ,
V_51 ) ;
for ( V_42 = 0 ; V_42 < V_54 ; V_42 ++ ) {
V_30 = F_18 ( V_52 , V_53 [ V_42 ] , V_16 ) ;
if ( F_19 ( V_30 ) ) {
F_20 ( V_55 ,
L_10 ,
V_53 [ V_42 ] , V_51 ) ;
return;
}
}
F_17 ( V_55 , L_11 ,
V_51 ) ;
* V_16 = NULL ;
}
static T_4 T_1 F_21 ( T_3 V_16 ,
T_7 V_56 , void * V_57 , void * * V_58 )
{
struct V_59 * V_60 ;
if ( ! strcmp ( V_57 , L_12 ) ) {
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
L_13 ,
V_51 , V_63 ? V_63 : L_14 ) ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_30 = F_26 ( V_63 , F_21 ,
( void * ) V_51 , & V_64 ) ;
* V_16 = NULL ;
if ( F_19 ( V_30 ) ) {
* V_16 = V_64 ;
F_20 ( V_55 ,
L_15 , V_51 ) ;
} else {
F_17 ( V_55 ,
L_16 ,
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
L_17 , V_68 -> V_51 ) ;
V_73 = F_22 ( * V_68 -> V_71 -> V_16 , & V_68 -> V_71 -> V_74 ) ;
if ( V_73 < 0 ) {
F_8 ( L_18 , V_68 -> V_51 , V_73 ) ;
return - V_75 ;
}
V_68 -> V_71 -> V_74 -> V_76 = V_68 ;
sprintf ( F_29 ( V_68 -> V_71 -> V_74 ) , L_19 ,
V_77 ,
V_68 -> V_51 ) ;
V_30 = F_30 ( * V_68 -> V_71 -> V_16 ,
V_68 -> V_71 -> type , F_27 , V_68 ) ;
if ( F_31 ( V_30 ) ) {
if ( V_30 == V_78 ) {
F_32 ( L_20 ,
V_68 -> V_51 ) ;
} else {
F_8 ( L_21 ,
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
L_22 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
V_68 -> V_71 -> V_81 = F_35 ( sizeof( struct V_82 ) , V_83 ) ;
if ( ! V_68 -> V_71 -> V_81 ) {
F_8 ( L_23 ) ;
return - V_84 ;
}
sprintf ( V_68 -> V_71 -> V_81 -> V_51 , L_24 , V_85 , V_68 -> V_51 ) ;
V_68 -> V_71 -> V_81 -> V_86 = V_68 -> V_71 -> V_63 ;
V_68 -> V_71 -> V_81 -> V_87 . V_88 = & F_33 ;
V_73 = F_36 ( V_68 -> V_71 -> V_81 ) ;
if ( V_73 < 0 ) {
F_8 ( L_25 ,
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
strcat ( V_99 , L_26 ) ;
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
if ( F_7 ( V_129 , NULL , L_27 , L_28 , 0 ) )
F_32 ( L_29 ) ;
}
static void F_61 ( const char * const V_2 ,
const char * const V_130 )
{
F_2 ( L_30 ) ;
F_62 ( L_31 ,
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
L_32 ,
V_138 ? L_33 : L_34 ) ;
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
F_8 ( L_35 ) ;
F_37 ( V_150 ) ;
return - V_84 ;
}
V_150 -> V_144 = V_144 ;
V_150 -> V_87 = V_146 ;
V_153 = ( V_146 -> V_133 ) ( ) ;
if ( V_153 < 0 ) {
F_8 ( L_36 ,
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
F_8 ( L_37 , V_51 , V_17 ) ;
F_75 ( V_150 -> V_134 ) ;
F_37 ( V_150 ) ;
return V_17 ;
}
V_137 [ V_144 ] = V_150 ;
F_76 ( L_38 ,
V_51 , ( V_151 || V_152 ) ? L_1 : L_39 ) ;
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
L_40 ) ;
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
return snprintf ( V_126 , V_102 , L_41 ,
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
F_82 ( V_122 -> V_122 . V_51 , L_42 , V_157 ) ;
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
F_84 ( V_91 , L_43 ) ;
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
F_84 ( V_91 , L_44 ,
( V_30 == V_142 ) ?
L_45 : L_46 ) ;
F_84 ( V_91 , L_47 ) ;
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
if ( F_86 ( V_159 , L_48 ) == 0 )
V_30 = V_142 ;
else if ( F_86 ( V_159 , L_49 ) == 0 )
V_30 = V_135 ;
else
return - V_94 ;
}
if ( V_30 != - 1 ) {
F_82 ( L_50 , L_51 ,
( V_30 == V_142 ) ?
L_48 : L_49 ,
V_160 [ V_144 ] ) ;
V_17 = ( V_137 [ V_144 ] -> V_87 -> V_141 ) ( V_30 ) ;
F_63 ( V_137 [ V_144 ] ) ;
}
return V_17 ;
}
static T_8 F_87 ( struct V_161 * V_162 , char * V_126 )
{
return snprintf ( V_126 , V_102 , L_52 , V_163 ) ;
}
static T_8 F_88 ( struct V_161 * V_162 , char * V_126 )
{
return snprintf ( V_126 , V_102 , L_53 , V_164 ) ;
}
static T_8 F_89 ( struct V_161 * V_162 , const char * V_126 ,
T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 0xffff , & V_157 ) )
return - V_94 ;
V_164 = V_157 ;
return V_35 ;
}
static T_8 F_90 ( struct V_161 * V_162 , char * V_126 )
{
return snprintf ( V_126 , V_102 , L_54 ,
V_165 , V_166 ) ;
}
static T_8 F_91 ( struct V_161 * V_162 , char * V_126 )
{
return snprintf ( V_126 , V_102 , L_41 , ! ! V_167 ) ;
}
static T_8 F_92 ( struct V_161 * V_162 , const char * V_126 ,
T_10 V_35 )
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
static T_8 F_93 ( struct V_161 * V_162 , char * V_126 )
{
return snprintf ( V_126 , V_102 , L_41 , ! ! V_168 ) ;
}
static T_8 F_94 ( struct V_161 * V_162 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 1 , & V_157 ) )
return - V_94 ;
V_168 = ! ! V_157 ;
return V_35 ;
}
static T_8 F_95 ( struct V_161 * V_162 , char * V_126 )
{
return snprintf ( V_126 , V_102 , L_41 , ! ! V_169 ) ;
}
static T_8 F_96 ( struct V_161 * V_162 , const char * V_126 ,
T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 1 , & V_157 ) )
return - V_94 ;
V_169 = ! ! V_157 ;
return V_35 ;
}
static T_8 F_97 ( struct V_161 * V_162 , char * V_126 )
{
return snprintf ( V_126 , V_102 , L_41 , ! ! V_170 ) ;
}
static T_8 F_98 ( struct V_161 * V_162 , const char * V_126 ,
T_10 V_35 )
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
F_62 ( L_55 ) ;
F_62 ( L_56 ) ;
}
}
static bool T_1 F_107 ( void )
{
return F_4 ( V_183 ,
F_100 ( V_183 ) ) != 0 ;
}
static int F_108 ( struct V_90 * V_91 )
{
F_84 ( V_91 , L_57 , V_165 ) ;
F_84 ( V_91 , L_58 , V_166 ) ;
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
if ( ! F_7 ( V_129 , & V_30 , L_59 , L_60 ) )
return - V_50 ;
return ( V_30 ) ? V_142 : V_135 ;
}
static int F_109 ( int * V_30 )
{
int V_118 ;
switch ( V_186 . V_188 ) {
case V_189 :
if ( ! F_7 ( V_129 , & V_118 , L_61 , L_60 ) )
return - V_50 ;
* V_30 = ( ( V_118 & V_190 ) != 0 ) ;
break;
case V_191 :
if ( ! F_7 ( V_192 , & V_118 , L_62 , L_60 ) )
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
if ( ! F_7 ( V_129 , & V_91 , L_63 , L_60 ) )
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
F_32 ( L_64 , V_199 ) ;
}
static int F_112 ( T_7 V_202 )
{
int V_42 ;
int V_73 = 0 ;
const T_7 V_203 = V_202 & ~ V_198 ;
if ( V_186 . V_194 ) {
for ( V_42 = 0 ; V_42 < 32 ; V_42 ++ ) {
if ( ! F_7 ( V_129 ,
NULL , L_65 , L_7 , V_42 + 1 ,
! ! ( V_202 & ( 1 << V_42 ) ) ) ) {
V_73 = - V_50 ;
break;
}
}
}
if ( ! F_110 () && ! V_73 && ( V_203 & ~ V_195 ) ) {
F_32 ( L_66 ,
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
F_32 ( L_67 ,
V_202 ) ;
F_32 ( L_68 ) ;
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
if ( ! F_7 ( V_129 , V_30 , L_69 , L_60 ) )
return - V_50 ;
return 0 ;
}
static int F_120 ( bool V_209 )
{
if ( ! F_7 ( V_129 , NULL , L_70 , L_8 , V_209 ? 1 : 0 ) )
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
F_8 ( L_71 ) ;
}
}
} else {
F_144 () ;
if ( V_288 && ( V_289 || V_290 ) &&
V_286 == 0 ) {
F_32 ( L_72 ,
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
F_61 ( L_73 ,
L_74 ) ;
V_17 = F_119 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_41 , V_30 ) ;
}
static T_8 F_154 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
F_61 ( L_73 ,
L_75 ) ;
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
return snprintf ( V_126 , V_102 , L_52 , V_197 ) ;
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
F_82 ( L_76 , L_77 , V_157 ) ;
return ( V_17 ) ? V_17 : V_35 ;
}
static T_8 F_158 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return sprintf ( V_126 , L_78 ) ;
}
static T_8 F_159 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
F_61 ( L_79 ,
L_80 ) ;
return snprintf ( V_126 , V_102 , L_52 , V_299 ) ;
}
static T_8 F_160 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_52 ,
V_196 | V_198 ) ;
}
static T_8 F_161 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_52 ,
V_300 | V_198 ) ;
}
static T_8 F_162 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_52 ,
( V_196 | V_198 )
& ~ V_301 ) ;
}
static T_8 F_163 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_52 , V_198 ) ;
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
F_8 ( L_81 ) ;
if ( V_302 )
F_32 ( L_82 ,
V_302 ) ;
F_82 ( L_83 , L_77 , V_157 ) ;
return ( V_73 < 0 ) ? V_73 : V_35 ;
}
static T_8 F_165 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_41 , V_286 ) ;
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
F_82 ( L_84 , L_85 , V_157 ) ;
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
return snprintf ( V_126 , V_102 , L_41 ,
( V_17 == V_135 ) ? 0 : 1 ) ;
}
static void F_168 ( void )
{
if ( V_186 . V_187 )
F_169 ( & V_154 -> V_60 . V_125 , NULL ,
L_86 ) ;
}
static T_8 F_170 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_118 ;
V_17 = F_109 ( & V_118 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_41 , ! ! V_118 ) ;
}
static void F_171 ( void )
{
if ( V_186 . V_188 )
F_169 ( & V_154 -> V_60 . V_125 , NULL ,
L_87 ) ;
}
static T_8 F_172 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_41 , V_303 ) ;
}
static void F_173 ( void )
{
F_169 ( & V_154 -> V_60 . V_125 , NULL ,
L_88 ) ;
}
static T_8 F_174 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_41 , V_304 ) ;
}
static void F_175 ( void )
{
F_169 ( & V_154 -> V_60 . V_125 , NULL ,
L_89 ) ;
}
static T_8 F_176 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_305 ;
V_305 = F_177 () ;
if ( V_305 < 0 )
return V_305 ;
return snprintf ( V_126 , V_102 , L_41 , V_305 ) ;
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
L_90 ) ;
if ( ( ( V_186 . V_194 &&
F_112 ( V_299 ) ) |
F_120 ( false ) ) != 0 )
F_8 ( L_91 ) ;
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
if ( F_7 ( V_129 , & V_17 , L_61 , L_92 ) ) {
V_186 . V_188 = V_189 ;
V_313 = ! ! ( V_17 & V_190 ) ;
type = L_61 ;
} else if ( F_7 ( V_192 , & V_17 , L_62 , L_92 ) ) {
V_186 . V_188 = V_191 ;
V_313 = V_17 == V_193 ;
type = L_62 ;
}
if ( ! V_186 . V_188 )
return 0 ;
F_76 ( L_93 ,
type , V_313 ? L_94 : L_95 ) ;
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
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333
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
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 , V_333 , V_333 , V_333 ,
V_333 ,
V_348 ,
V_217 ,
V_217 ,
V_349 ,
V_350
} ,
} ;
static const struct V_3 V_351 [] V_320 = {
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
int V_352 ;
bool V_353 = false ;
bool V_354 = false ;
unsigned long V_13 ;
unsigned long V_355 ;
F_17 ( V_55 | V_311 ,
L_96 ) ;
F_25 ( ! V_212 ) ;
F_25 ( V_212 -> V_356 != NULL ||
V_212 -> V_357 != NULL ) ;
F_188 ( V_358 ) ;
F_189 ( & V_208 ) ;
#ifdef F_116
F_189 ( & V_284 ) ;
#endif
V_186 . V_207 = V_129 != NULL ;
F_17 ( V_55 | V_311 ,
L_97 ,
F_1 ( V_186 . V_207 ) ) ;
if ( ! V_186 . V_207 )
return 1 ;
V_13 = F_4 ( V_359 ,
F_100 ( V_359 ) ) ;
F_60 () ;
V_309 = F_51 (
F_100 ( V_360 ) + 2 ,
NULL ) ;
if ( ! V_309 )
return - V_84 ;
V_17 = F_53 ( V_309 ,
V_360 ,
F_100 ( V_360 ) ) ;
if ( V_17 )
goto V_361;
if ( F_7 ( V_129 , & V_352 , L_98 , L_92 ) ) {
F_17 ( V_55 | V_311 ,
L_99 ,
V_352 ) ;
switch ( V_352 >> 8 ) {
case 1 :
if ( ! F_7 ( V_129 , & V_196 ,
L_100 , L_92 ) ) {
F_8 ( L_101 ,
V_362 ) ;
V_196 = 0x080cU ;
} else {
V_186 . V_194 = 1 ;
}
break;
case 2 :
if ( ! F_7 ( V_129 , & V_196 ,
L_100 , L_6 , 1 ) ) {
F_8 ( L_101 ,
V_362 ) ;
V_196 = 0x080cU ;
} else {
V_186 . V_194 = 1 ;
}
if ( F_7 ( V_129 , & V_300 ,
L_100 , L_6 , 2 ) ) {
if ( V_300 != 0 ) {
V_186 . V_363 = true ;
V_17 = F_190 (
& V_154 -> V_60 . V_125 ,
& V_364 ) ;
if ( V_17 )
goto V_361;
}
} else {
V_186 . V_363 = false ;
V_300 = 0x0U ;
}
break;
default:
F_8 ( L_102 ,
V_352 ) ;
F_8 ( L_103 , V_362 ) ;
break;
}
}
F_17 ( V_55 | V_311 ,
L_104 ,
F_1 ( V_186 . V_194 ) ) ;
if ( ! V_186 . V_194 && ! V_196 &&
( V_13 & V_365 ) )
V_196 = 0x080cU ;
if ( V_186 . V_194 ) {
V_17 = F_110 () ;
if ( V_17 )
goto V_361;
V_299 = V_195 ;
} else {
V_299 = V_196 ;
V_195 = V_196 ;
}
#ifdef F_102
if ( V_172 ) {
V_186 . V_187 = 1 ;
V_353 = ! ! V_167 ;
F_76 ( L_105 ) ;
} else
#endif
if ( F_7 ( V_129 , & V_30 , L_59 , L_92 ) ) {
V_186 . V_187 = 1 ;
V_353 = ! ! V_30 ;
F_76 ( L_106 ,
F_191 ( V_30 , 0 ) ) ;
}
if ( V_186 . V_187 )
V_17 = F_52 ( V_309 ,
& V_366 . V_122 ) ;
V_17 = F_184 () ;
if ( V_17 < 0 )
goto V_361;
V_354 = V_17 ;
V_17 = F_192 ( V_309 ,
& V_154 -> V_60 . V_125 ) ;
if ( V_17 )
goto V_361;
V_216 = F_44 ( F_186 ,
V_83 ) ;
if ( ! V_216 ) {
F_8 ( L_107 ) ;
V_17 = - V_84 ;
goto V_361;
}
V_355 = F_4 ( V_351 ,
F_100 ( V_351 ) ) ;
F_25 ( V_355 >= F_100 ( V_319 ) ) ;
F_20 ( V_55 | V_311 ,
L_108 , V_355 ) ;
memcpy ( V_216 , & V_319 [ V_355 ] ,
F_186 ) ;
F_193 ( V_212 , V_218 , V_219 ) ;
V_212 -> V_367 = F_187 ;
V_212 -> V_368 = V_369 ;
V_212 -> V_215 = V_216 ;
for ( V_42 = 0 ; V_42 < V_369 ; V_42 ++ ) {
if ( V_216 [ V_42 ] != V_217 ) {
F_193 ( V_212 , V_370 ,
V_216 [ V_42 ] ) ;
} else {
if ( V_42 < sizeof( V_301 ) * 8 )
V_301 |= 1 << V_42 ;
}
}
if ( V_186 . V_187 ) {
F_193 ( V_212 , V_371 , V_308 ) ;
F_122 ( V_212 ,
V_308 , V_353 ) ;
}
if ( V_186 . V_188 ) {
F_193 ( V_212 , V_371 , V_213 ) ;
F_122 ( V_212 ,
V_213 , V_354 ) ;
}
if ( F_194 () != V_372 ) {
F_76 ( L_109 ) ;
F_32 ( L_110 ) ;
V_301 |=
( 1 << V_265 )
| ( 1 << V_264 ) ;
F_182 ( V_265 ) ;
F_182 ( V_264 ) ;
}
#ifdef F_116
V_198 = V_373
& ~ V_196
& ~ V_301 ;
F_17 ( V_55 | V_311 ,
L_111 ,
V_198 , V_286 ) ;
#endif
F_20 ( V_55 | V_311 ,
L_112 ) ;
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
L_113 ,
V_197 , V_195 , V_198 ) ;
V_212 -> V_356 = & F_150 ;
V_212 -> V_357 = & F_152 ;
F_148 ( true ) ;
return 0 ;
V_361:
F_54 ( V_309 , & V_154 -> V_60 . V_125 ) ;
F_55 ( & V_154 -> V_60 . V_125 ,
& V_364 ) ;
V_309 = NULL ;
return ( V_17 < 0 ) ? V_17 : 1 ;
}
static int F_177 ( void )
{
int V_374 = 0 ;
if ( ! F_7 ( V_129 , & V_374 , L_114 , L_6 , 0 ) ) {
F_8 ( L_115 ) ;
return - V_50 ;
}
return V_374 ;
}
static int F_179 ( int V_375 )
{
if ( V_375 < 0 ||
V_375 > V_306 )
return - V_94 ;
if ( ! F_7 ( V_129 , NULL , L_116 , L_8 , V_375 ) ) {
F_8 ( L_117 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_195 ( int V_374 )
{
T_10 V_42 ;
T_10 V_376 = F_100 ( V_377 ) - 1 ;
for ( V_42 = 0 ; V_42 <= V_376 ; V_42 ++ ) {
if ( V_377 [ V_42 ] == V_374 )
break;
}
if ( V_42 >= V_376 )
V_42 = 0 ;
else
V_42 ++ ;
return V_377 [ V_42 ] ;
}
static bool F_196 ( unsigned int V_214 )
{
int V_305 = 0 ;
int V_375 = 0 ;
int V_215 ;
switch ( V_214 ) {
case V_378 :
if ( V_379 ) {
V_375 = V_380 ;
V_379 = false ;
} else {
V_305 = F_177 () ;
if ( V_305 < 0 )
return false ;
V_375 = F_195 (
V_305 ) ;
}
if ( F_179 ( V_375 ) < 0 )
return false ;
return true ;
case V_381 :
V_305 = F_177 () ;
if ( V_305 < 0 )
return false ;
V_380 = V_305 ;
V_379 = true ;
if ( F_179 ( V_382 ) < 0 )
return false ;
return true ;
default:
if ( V_214 < V_383 ||
V_214 >= V_383 +
V_384 -
V_385 ) {
F_76 ( L_118 ,
V_214 ) ;
return false ;
}
V_215 = V_216 [ V_214 - V_383 +
V_385 ] ;
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
static bool F_197 ( const T_7 V_358 ,
bool * V_386 ,
bool * V_387 )
{
unsigned int V_214 = V_358 & 0xfff ;
* V_386 = true ;
* V_387 = false ;
switch ( ( V_358 >> 8 ) & 0xf ) {
case 0 :
if ( V_214 > 0 &&
V_214 <= V_385 ) {
V_214 -- ;
if ( ! ( V_198 & ( 1 << V_214 ) ) ) {
F_127 ( V_214 ) ;
* V_386 = false ;
} else {
* V_387 = true ;
}
return true ;
}
break;
case 1 :
return F_196 ( V_214 ) ;
case 3 :
V_214 -= ( 0x300 - V_384 ) ;
if ( V_214 >= V_384 &&
V_214 < V_369 ) {
F_124 ( V_214 ) ;
return true ;
}
break;
}
return false ;
}
static bool F_198 ( const T_7 V_358 ,
bool * V_386 ,
bool * V_387 )
{
* V_386 = true ;
* V_387 = false ;
switch ( V_358 ) {
case V_388 :
case V_389 :
V_303 = V_390 ;
* V_387 = true ;
break;
case V_391 :
case V_392 :
V_303 = V_393 ;
* V_387 = true ;
break;
case V_394 :
case V_395 :
F_199 ( L_119 ) ;
break;
default:
return false ;
}
if ( V_303 != V_396 ) {
F_76 ( L_120 ) ;
F_173 () ;
}
return true ;
}
static bool F_200 ( const T_7 V_358 ,
bool * V_386 ,
bool * V_387 )
{
* V_386 = true ;
* V_387 = false ;
switch ( V_358 ) {
case V_397 :
V_304 = 1 ;
F_76 ( L_121 ) ;
F_175 () ;
return true ;
case V_398 :
F_76 ( L_122 ) ;
return true ;
case V_399 :
F_76 ( L_123 ) ;
return true ;
default:
return false ;
}
}
static bool F_201 ( const T_7 V_358 ,
bool * V_386 ,
bool * V_387 )
{
* V_386 = true ;
* V_387 = false ;
switch ( V_358 ) {
case V_400 :
case V_401 :
return true ;
case V_402 :
case V_403 :
F_121 () ;
F_171 () ;
* V_386 = false ;
return true ;
case V_404 :
case V_405 :
case V_406 :
* V_387 = true ;
return true ;
default:
return false ;
}
}
static bool F_202 ( const T_7 V_358 ,
bool * V_386 ,
bool * V_387 )
{
bool V_407 = true ;
* V_386 = true ;
* V_387 = false ;
switch ( V_358 ) {
case V_408 :
F_76 ( L_124 ) ;
return true ;
case V_409 :
F_203 ( L_125 ) ;
break;
case V_410 :
F_199 ( L_126 ) ;
break;
case V_411 :
F_203 ( L_127 ) ;
break;
case V_412 :
F_199 ( L_128 ) ;
break;
case V_413 :
case V_414 :
case V_415 :
case V_416 :
* V_386 = false ;
* V_387 = true ;
return true ;
case V_417 :
F_121 () ;
F_171 () ;
* V_386 = false ;
break;
default:
F_62 ( L_129 ) ;
V_407 = false ;
}
F_204 () ;
return V_407 ;
}
static void F_205 ( struct V_67 * V_68 , T_7 V_65 )
{
T_7 V_358 ;
bool V_386 ;
bool V_387 ;
bool V_418 ;
if ( V_65 != 0x80 ) {
F_8 ( L_130 , V_65 ) ;
F_206 (
V_68 -> V_71 -> V_74 -> V_419 . V_420 ,
F_207 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , 0 ) ;
return;
}
while ( 1 ) {
if ( ! F_7 ( V_129 , & V_358 , L_131 , L_60 ) ) {
F_8 ( L_132 ) ;
return;
}
if ( V_358 == 0 ) {
return;
}
V_386 = true ;
V_387 = false ;
switch ( V_358 >> 12 ) {
case 1 :
V_418 = F_197 ( V_358 , & V_386 ,
& V_387 ) ;
break;
case 2 :
V_418 = F_198 ( V_358 , & V_386 ,
& V_387 ) ;
break;
case 3 :
switch ( V_358 ) {
case V_421 :
V_304 = 1 ;
F_76 ( L_133 ) ;
F_175 () ;
V_418 = true ;
break;
case V_422 :
V_418 = true ;
break;
default:
V_418 = false ;
}
break;
case 4 :
V_418 = F_200 ( V_358 , & V_386 ,
& V_387 ) ;
break;
case 5 :
V_418 = F_201 ( V_358 , & V_386 ,
& V_387 ) ;
break;
case 6 :
V_418 = F_202 ( V_358 , & V_386 ,
& V_387 ) ;
break;
case 7 :
if ( V_186 . V_187 &&
V_358 == V_423 ) {
F_180 () ;
V_386 = 0 ;
V_418 = true ;
break;
}
default:
V_418 = false ;
}
if ( ! V_418 ) {
F_32 ( L_134 , V_358 ) ;
F_32 ( L_135 ,
V_362 ) ;
}
if ( ! V_387 && V_386 ) {
F_206 (
V_68 -> V_71 -> V_74 -> V_419 . V_420 ,
F_207 ( & V_68 -> V_71 -> V_74 -> V_60 ) ,
V_65 , V_358 ) ;
}
}
}
static void F_208 ( void )
{
V_303 = V_396 ;
V_304 = 0 ;
if ( V_186 . V_363 ) {
if ( ! F_7 ( V_129 , & V_380 ,
L_114 , L_6 , 0 ) ) {
F_8 ( L_136 ) ;
}
}
}
static void F_209 ( void )
{
F_60 () ;
if ( F_120 ( true ) < 0 ||
F_112 ( V_195 ) < 0 )
F_8 ( L_137 ) ;
F_180 () ;
F_171 () ;
F_173 () ;
F_175 () ;
F_148 ( false ) ;
if ( V_186 . V_363 ) {
if ( ! F_7 ( V_129 , NULL , L_116 , L_8 ,
V_380 ) ) {
F_8 ( L_138 ) ;
}
}
}
static int F_210 ( struct V_90 * V_91 )
{
int V_17 , V_30 ;
if ( ! V_186 . V_207 ) {
F_84 ( V_91 , L_43 ) ;
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
F_84 ( V_91 , L_44 , F_191 ( V_30 , 0 ) ) ;
if ( V_196 ) {
F_84 ( V_91 , L_139 , V_197 ) ;
F_84 ( V_91 , L_140 ) ;
} else {
F_84 ( V_91 , L_141 ) ;
F_84 ( V_91 , L_142 ) ;
}
return 0 ;
}
static void F_211 ( bool V_209 )
{
F_2 ( L_143 ) ;
if ( ! F_212 ( ( V_69 == V_70 || ! V_209 ) ,
F_213 ( L_144 ) ) )
F_8 ( L_145 ) ;
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
if ( F_86 ( V_159 , L_48 ) == 0 ) {
F_211 ( 1 ) ;
} else if ( F_86 ( V_159 , L_49 ) == 0 ) {
F_211 ( 0 ) ;
V_17 = - V_158 ;
} else if ( F_86 ( V_159 , L_146 ) == 0 ) {
V_202 = ( V_196 | V_198 )
& ~ V_301 ;
} else if ( sscanf ( V_159 , L_147 , & V_202 ) == 1 ) {
} else if ( sscanf ( V_159 , L_148 , & V_202 ) == 1 ) {
} else {
V_17 = - V_94 ;
goto V_424;
}
}
if ( ! V_17 ) {
F_82 ( L_149 ,
L_150 , V_202 ) ;
V_17 = F_113 ( V_202 ) ;
}
V_424:
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
if ( ! F_7 ( V_129 , & V_30 , L_151 , L_60 ) )
return - V_50 ;
return ( ( V_30 & V_425 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_216 ( enum V_426 V_210 )
{
int V_30 ;
F_17 ( V_140 ,
L_152 ,
( V_210 == V_142 ) ? L_48 : L_49 ) ;
#ifdef F_102
if ( V_174 ) {
V_168 = ( V_210 == V_142 ) ;
return 0 ;
}
#endif
if ( V_210 == V_142 )
V_30 = V_425
| V_427 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_153 , L_8 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_217 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_428 ,
V_122 , V_126 ) ;
}
static T_8 F_218 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_428 ,
V_122 , V_126 , V_35 ) ;
}
static void F_219 ( void )
{
if ( ! F_7 ( NULL , NULL , L_154 , L_8 ,
V_429 ) )
F_32 ( L_155 ) ;
else
F_17 ( V_140 ,
L_156 ) ;
}
static void F_220 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_430 ) ;
F_77 ( V_428 ) ;
F_219 () ;
}
static int T_1 F_221 ( struct V_315 * V_316 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_157 ) ;
F_188 ( V_358 ) ;
V_186 . V_431 = V_129 &&
F_7 ( V_129 , & V_30 , L_151 , L_92 ) ;
F_17 ( V_55 | V_140 ,
L_158 ,
F_1 ( V_186 . V_431 ) ,
V_30 ) ;
#ifdef F_102
if ( V_174 ) {
V_186 . V_431 = 1 ;
F_76 ( L_159 ) ;
} else
#endif
if ( V_186 . V_431 &&
! ( V_30 & V_432 ) ) {
V_186 . V_431 = 0 ;
F_20 ( V_55 | V_140 ,
L_160 ) ;
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
V_17 = F_190 ( & V_154 -> V_60 . V_125 ,
& V_430 ) ;
if ( V_17 ) {
F_77 ( V_428 ) ;
return V_17 ;
}
return 0 ;
}
static int F_222 ( struct V_90 * V_91 )
{
return F_83 ( V_428 , V_91 ) ;
}
static int F_223 ( char * V_126 )
{
return F_85 ( V_428 , V_126 ) ;
}
static int F_224 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_176 )
return ( V_169 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_161 , L_60 ) )
return - V_50 ;
return ( ( V_30 & V_436 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_225 ( enum V_426 V_210 )
{
int V_30 ;
F_17 ( V_140 ,
L_162 ,
( V_210 == V_142 ) ? L_48 : L_49 ) ;
#ifdef F_102
if ( V_176 ) {
V_169 = ( V_210 == V_142 ) ;
return 0 ;
}
#endif
if ( V_210 == V_142 )
V_30 = V_436
| V_437 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_163 , L_8 , V_30 ) )
return - V_50 ;
return 0 ;
}
static T_8 F_226 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return F_80 ( V_438 ,
V_122 , V_126 ) ;
}
static T_8 F_227 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
return F_81 ( V_438 ,
V_122 , V_126 , V_35 ) ;
}
static void F_228 ( void )
{
if ( ! F_7 ( NULL , NULL , L_164 , L_8 ,
V_439 ) )
F_32 ( L_165 ) ;
else
F_17 ( V_140 ,
L_166 ) ;
}
static void F_229 ( void )
{
F_55 ( & V_154 -> V_60 . V_125 ,
& V_440 ) ;
F_77 ( V_438 ) ;
F_228 () ;
}
static int T_1 F_230 ( struct V_315 * V_316 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_167 ) ;
F_188 ( V_358 ) ;
V_186 . V_441 = V_129 &&
F_7 ( V_129 , & V_30 , L_161 , L_92 ) ;
F_17 ( V_55 | V_140 ,
L_168 ,
F_1 ( V_186 . V_441 ) ,
V_30 ) ;
#ifdef F_102
if ( V_176 ) {
V_186 . V_441 = 1 ;
F_76 ( L_169 ) ;
} else
#endif
if ( V_186 . V_441 &&
! ( V_30 & V_442 ) ) {
V_186 . V_441 = 0 ;
F_20 ( V_55 | V_140 ,
L_170 ) ;
}
if ( ! V_186 . V_441 )
return 1 ;
V_17 = F_71 ( V_438 ,
& V_443 ,
V_444 ,
V_445 ,
true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_190 ( & V_154 -> V_60 . V_125 ,
& V_440 ) ;
if ( V_17 ) {
F_77 ( V_438 ) ;
return V_17 ;
}
return 0 ;
}
static int F_231 ( struct V_90 * V_91 )
{
return F_83 ( V_438 , V_91 ) ;
}
static int F_232 ( char * V_126 )
{
return F_85 ( V_438 , V_126 ) ;
}
static int F_233 ( void )
{
int V_30 ;
#ifdef F_102
if ( V_178 )
return ( V_170 ) ?
V_142 : V_135 ;
#endif
if ( ! F_7 ( V_129 , & V_30 , L_171 , L_60 ) )
return - V_50 ;
return ( ( V_30 & V_446 ) != 0 ) ?
V_142 : V_135 ;
}
static int F_234 ( enum V_426 V_210 )
{
int V_30 ;
F_17 ( V_140 ,
L_172 ,
( V_210 == V_142 ) ? L_48 : L_49 ) ;
#ifdef F_102
if ( V_178 ) {
V_170 = ( V_210 == V_142 ) ;
return 0 ;
}
#endif
if ( V_210 == V_142 )
V_30 = V_446 ;
else
V_30 = 0 ;
if ( ! F_7 ( V_129 , NULL , L_173 , L_8 , V_30 ) )
return - V_50 ;
return 0 ;
}
static void F_235 ( void )
{
F_77 ( V_447 ) ;
}
static int T_1 F_236 ( struct V_315 * V_316 )
{
int V_17 ;
int V_30 = 0 ;
F_17 ( V_55 | V_140 ,
L_174 ) ;
F_188 ( V_358 ) ;
V_186 . V_448 = V_129 &&
F_7 ( V_129 , & V_30 , L_171 , L_92 ) ;
F_17 ( V_55 | V_140 ,
L_175 ,
F_1 ( V_186 . V_448 ) ,
V_30 ) ;
#ifdef F_102
if ( V_178 ) {
V_186 . V_448 = 1 ;
F_76 ( L_176 ) ;
} else
#endif
if ( V_186 . V_448 &&
! ( V_30 & V_449 ) ) {
V_186 . V_448 = 0 ;
F_20 ( V_55 ,
L_177 ) ;
}
if ( ! V_186 . V_448 )
return 1 ;
V_17 = F_71 ( V_447 ,
& V_450 ,
V_451 ,
V_452 ,
false ) ;
return V_17 ;
}
static int T_1 F_237 ( struct V_315 * V_316 )
{
int V_453 ;
F_17 ( V_55 , L_178 ) ;
F_188 ( V_454 ) ;
if ( F_6 () )
F_188 ( V_455 ) ;
if ( V_456 && F_7 ( NULL , & V_453 , L_179 , L_60 ) && V_453 )
V_457 = V_456 ;
if ( ! V_457 )
V_458 = V_459 ;
else if ( F_6 () &&
F_7 ( V_457 , & V_460 , L_180 , L_92 ) )
V_458 = V_461 ;
else if ( F_6 () &&
F_7 ( V_457 , & V_460 , L_181 , L_92 ) )
V_458 = V_462 ;
else
V_458 = V_463 ;
F_17 ( V_55 , L_182 ,
F_1 ( V_458 != V_459 ) ,
V_458 ) ;
return ( V_458 != V_459 ) ? 0 : 1 ;
}
static void F_238 ( void )
{
F_20 ( V_310 ,
L_183 ) ;
if ( F_239 ( V_460 ) )
F_8 ( L_184 ) ;
}
static int F_240 ( void )
{
int V_30 = 0 ;
int V_42 ;
switch ( V_458 ) {
case V_461 :
if ( ! F_7 ( NULL , & V_42 , L_185 , L_6 ,
V_464 ) )
return - V_50 ;
V_30 = V_42 & V_465 ;
break;
case V_462 :
if ( ! F_7 ( NULL , & V_42 , L_186 , L_60 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_466 ;
if ( ! F_7 ( NULL , & V_42 , L_187 , L_60 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_467 ;
break;
case V_463 :
if ( ! F_7 ( NULL , NULL , L_188 , L_8 , 1 ) ||
! F_7 ( NULL , & V_42 , L_187 , L_60 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_467 ;
if ( ! F_7 ( NULL , NULL , L_188 , L_8 , 0 ) ||
! F_7 ( NULL , & V_42 , L_186 , L_60 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_466 ;
if ( ! F_7 ( NULL , & V_42 , L_189 , L_60 ) )
return - V_50 ;
if ( V_42 )
V_30 |= V_468 ;
break;
default:
return - V_469 ;
}
return V_30 ;
}
static int F_241 ( int V_30 )
{
int V_470 ;
int V_17 = 0 ;
switch ( V_458 ) {
case V_461 :
V_17 = F_7 ( NULL , NULL ,
L_190 , L_7 ,
V_471 ,
V_30 | V_472 ) ;
break;
case V_462 :
V_470 = F_242 () ;
if ( V_470 < 0 )
return V_470 ;
V_17 = F_239 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_457 , NULL ,
L_191 , L_7 , V_30 * 0x100 , 0 ) ;
if ( ! V_470 && F_239 ( V_470 ) ) {
F_8 ( L_192 ) ;
return - V_50 ;
}
break;
case V_463 :
V_17 = F_7 ( NULL , NULL , L_188 , L_8 , 0x80 ) &&
F_7 ( NULL , NULL , L_193 , L_7 , V_30 , 1 ) ;
break;
default:
return - V_469 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_242 ( void )
{
int V_470 = 0 ;
switch ( V_458 ) {
case V_461 :
if ( ! F_7 ( V_457 , & V_470 , L_180 , L_60 ) )
return - V_50 ;
break;
case V_462 :
case V_463 :
if ( ! F_7 ( V_457 , & V_470 , L_194 , L_60 ) )
return - V_50 ;
break;
default:
return - V_469 ;
}
return V_470 & 1 ;
}
static int F_239 ( int V_209 )
{
if ( ! F_7 ( V_457 , NULL , L_195 , L_8 , ( V_209 ) ? 1 : 0 ) )
return - V_50 ;
return 0 ;
}
static int F_243 ( void )
{
int V_470 = F_242 () ;
int V_17 ;
if ( V_470 < 0 )
return V_470 ;
switch ( V_458 ) {
case V_461 :
V_17 = F_239 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_192 , NULL , L_196 , L_197 ) ;
break;
case V_462 :
case V_463 :
V_17 = F_239 ( 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( V_457 , NULL , L_198 , L_197 ) ;
break;
default:
return - V_469 ;
}
if ( ! V_470 && F_239 ( V_470 ) ) {
F_8 ( L_192 ) ;
return - V_50 ;
}
return ( V_17 ) ? 0 : - V_50 ;
}
static int F_244 ( void )
{
switch ( V_458 ) {
case V_461 :
return F_7 ( V_192 , NULL , L_199 , L_197 ) ?
0 : - V_50 ;
case V_462 :
return F_7 ( V_457 , NULL , L_200 , L_197 ) ?
0 : - V_50 ;
case V_463 :
return F_7 ( NULL , NULL , L_201 , L_197 ) ?
0 : - V_50 ;
default:
return - V_469 ;
}
}
static int F_245 ( struct V_90 * V_91 )
{
int V_30 , V_470 ;
if ( V_458 == V_459 ) {
F_84 ( V_91 , L_43 ) ;
return 0 ;
}
if ( ! F_246 ( V_473 ) )
return - V_158 ;
V_30 = F_240 () ;
if ( V_30 < 0 )
return V_30 ;
V_470 = F_242 () ;
if ( V_470 < 0 )
return V_470 ;
F_84 ( V_91 , L_202 ) ;
F_84 ( V_91 , L_203 , F_191 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_204 , F_191 ( V_30 , 1 ) ) ;
if ( V_458 == V_463 )
F_84 ( V_91 , L_205 , F_191 ( V_30 , 3 ) ) ;
F_84 ( V_91 , L_206 , F_191 ( V_470 , 0 ) ) ;
F_84 ( V_91 , L_207 ) ;
F_84 ( V_91 , L_208 ) ;
if ( V_458 == V_463 )
F_84 ( V_91 , L_209 ) ;
F_84 ( V_91 , L_210 ) ;
F_84 ( V_91 , L_211 ) ;
return 0 ;
}
static int F_247 ( char * V_126 )
{
char * V_159 ;
int V_209 , V_474 , V_30 ;
int V_17 ;
if ( V_458 == V_459 )
return - V_75 ;
if ( ! F_246 ( V_473 ) )
return - V_158 ;
V_209 = 0 ;
V_474 = 0 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_212 ) == 0 ) {
V_209 |= V_466 ;
} else if ( F_86 ( V_159 , L_213 ) == 0 ) {
V_474 |= V_466 ;
} else if ( F_86 ( V_159 , L_214 ) == 0 ) {
V_209 |= V_467 ;
} else if ( F_86 ( V_159 , L_215 ) == 0 ) {
V_474 |= V_467 ;
} else if ( V_458 == V_463 &&
F_86 ( V_159 , L_216 ) == 0 ) {
V_209 |= V_468 ;
} else if ( V_458 == V_463 &&
F_86 ( V_159 , L_217 ) == 0 ) {
V_474 |= V_468 ;
} else if ( F_86 ( V_159 , L_218 ) == 0 ) {
V_17 = F_239 ( 1 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_219 ) == 0 ) {
V_17 = F_239 ( 0 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_220 ) == 0 ) {
V_17 = F_243 () ;
if ( V_17 )
return V_17 ;
} else if ( F_86 ( V_159 , L_221 ) == 0 ) {
V_17 = F_244 () ;
if ( V_17 )
return V_17 ;
} else
return - V_94 ;
}
if ( V_209 || V_474 ) {
V_30 = F_240 () ;
if ( V_30 < 0 )
return V_30 ;
V_17 = F_241 ( ( V_30 & ~ V_474 ) | V_209 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_248 ( int V_56 )
{
int V_100 = 0 ;
if ( ! V_129 )
return - V_49 ;
F_115 ( & V_475 ) ;
if ( ! F_7 ( V_129 , NULL , L_222 , L_6 , V_56 ) )
V_100 = - V_50 ;
else
V_476 = V_56 ;
F_118 ( & V_475 ) ;
return V_100 ;
}
static int F_249 ( void )
{
int V_30 = 0 ;
if ( ! V_129 )
return - V_49 ;
if ( ! F_7 ( V_129 , & V_30 , L_223 , L_6 , 0 ) )
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
if ( ! F_251 ( V_129 , L_223 ) ) {
F_17 ( V_55 , L_224 ) ;
return false ;
}
if ( ! F_7 ( V_129 , & V_30 , L_223 , L_225 , 0 ) ) {
F_17 ( V_55 , L_226 ) ;
return false ;
}
if ( V_30 < 0 ) {
F_17 ( V_55 , L_227 , V_30 ) ;
return false ;
}
F_17 ( V_55 , L_228 , V_30 ) ;
return V_30 & F_252 ( 9 ) ;
}
static int F_253 ( struct V_477 * V_478 ,
enum V_479 V_480 )
{
return F_248 ( V_480 ) ;
}
static enum V_479 F_254 ( struct V_477 * V_478 )
{
int V_56 ;
V_56 = F_249 () ;
if ( V_56 < 0 )
return 0 ;
return V_56 ;
}
static int T_1 F_255 ( struct V_315 * V_316 )
{
int V_73 ;
F_17 ( V_55 , L_229 ) ;
F_188 ( V_358 ) ;
if ( ! F_250 () ) {
V_186 . V_481 = 0 ;
F_17 ( V_55 , L_230 ) ;
return 1 ;
}
V_476 = F_254 ( NULL ) ;
V_186 . V_481 = 1 ;
V_73 = F_256 ( & V_154 -> V_60 ,
& V_482 . V_477 ) ;
if ( V_73 < 0 ) {
V_186 . V_481 = 0 ;
return V_73 ;
}
F_114 ( V_200 |
V_233 ) ;
return 0 ;
}
static void F_257 ( void )
{
if ( V_186 . V_481 )
F_258 ( & V_482 . V_477 ) ;
}
static int F_259 ( int V_56 )
{
int V_100 ;
struct V_477 * V_478 ;
V_100 = F_248 ( V_56 ) ;
V_478 = & V_482 . V_477 ;
if ( V_100 == 0 && ! ( V_478 -> V_79 & V_483 ) )
V_478 -> V_480 = V_56 ;
return V_100 ;
}
static int F_260 ( struct V_90 * V_91 )
{
int V_56 ;
if ( ! V_186 . V_481 ) {
F_84 ( V_91 , L_43 ) ;
} else {
V_56 = F_249 () ;
if ( V_56 < 0 )
F_84 ( V_91 , L_231 , V_56 ) ;
else
F_84 ( V_91 , L_232 , V_56 ) ;
F_84 ( V_91 , L_233 ) ;
}
return 0 ;
}
static int F_261 ( char * V_126 )
{
char * V_159 ;
int V_56 = - 1 ;
if ( ! V_186 . V_481 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_234 ) == 0 )
V_56 = 0 ;
else if ( F_86 ( V_159 , L_235 ) == 0 )
V_56 = 1 ;
else if ( F_86 ( V_159 , L_236 ) == 0 )
V_56 = 2 ;
else
return - V_94 ;
}
if ( V_56 == - 1 )
return - V_94 ;
return F_259 ( V_56 ) ;
}
static void F_262 ( void )
{
struct V_477 * V_478 ;
if ( ! V_186 . V_481 )
return;
V_478 = & V_482 . V_477 ;
F_263 ( V_478 ) ;
F_264 ( V_478 ) ;
}
static void F_265 ( void )
{
if ( ! V_186 . V_481 )
return;
F_266 ( & V_482 . V_477 ) ;
}
static int F_267 ( void )
{
int V_30 = 0 ;
if ( V_186 . V_484 ) {
if ( ! F_7 ( V_192 , & V_30 , L_237 , L_60 ) )
return - V_50 ;
return ( ! ! V_30 ) ;
}
return - V_49 ;
}
static int F_268 ( int V_30 )
{
int V_73 ;
if ( V_186 . V_485 ) {
if ( V_48 ) {
V_73 = F_7 ( V_48 , NULL , NULL , L_8 ,
( V_30 ) ?
V_486 :
V_487 ) ;
} else {
V_73 = F_7 ( V_488 , NULL , NULL , L_8 ,
( V_30 ) ? 1 : 0 ) ;
}
return ( V_73 ) ? 0 : - V_50 ;
}
return - V_49 ;
}
static int F_269 ( struct V_477 * V_478 ,
enum V_479 V_480 )
{
return F_268 ( ( V_480 != V_489 ) ?
V_490 : V_491 ) ;
}
static enum V_479 F_270 ( struct V_477 * V_478 )
{
return ( F_267 () == 1 ) ? V_492 : V_489 ;
}
static int T_1 F_271 ( struct V_315 * V_316 )
{
int V_73 ;
F_17 ( V_55 , L_238 ) ;
if ( F_6 () ) {
F_188 ( V_493 ) ;
F_188 ( V_494 ) ;
}
F_188 ( V_495 ) ;
V_186 . V_485 = ( V_48 || V_488 ) && ! V_496 ;
if ( V_186 . V_485 )
V_186 . V_484 =
F_7 ( V_192 , NULL , L_237 , L_239 ) ;
F_17 ( V_55 , L_240 ,
F_1 ( V_186 . V_485 ) ,
F_1 ( V_186 . V_484 ) ) ;
if ( ! V_186 . V_485 )
return 1 ;
V_73 = F_256 ( & V_154 -> V_60 ,
& V_497 . V_477 ) ;
if ( V_73 < 0 ) {
V_186 . V_485 = 0 ;
V_186 . V_484 = 0 ;
} else {
V_73 = 0 ;
}
return V_73 ;
}
static void F_272 ( void )
{
F_258 ( & V_497 . V_477 ) ;
}
static int F_273 ( struct V_90 * V_91 )
{
int V_30 ;
if ( ! V_186 . V_485 ) {
F_84 ( V_91 , L_43 ) ;
} else if ( ! V_186 . V_484 ) {
F_84 ( V_91 , L_241 ) ;
F_84 ( V_91 , L_242 ) ;
} else {
V_30 = F_267 () ;
if ( V_30 < 0 )
return V_30 ;
F_84 ( V_91 , L_44 , F_274 ( V_30 , 0 ) ) ;
F_84 ( V_91 , L_242 ) ;
}
return 0 ;
}
static int F_275 ( char * V_126 )
{
char * V_159 ;
int V_498 = 0 ;
if ( ! V_186 . V_485 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_243 ) == 0 ) {
V_498 = 1 ;
} else if ( F_86 ( V_159 , L_244 ) == 0 ) {
V_498 = 0 ;
} else
return - V_94 ;
}
return F_268 ( V_498 ) ;
}
static T_8 F_276 ( struct V_74 * V_60 ,
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
static int T_1 F_277 ( struct V_315 * V_316 )
{
int V_17 ;
F_17 ( V_55 ,
L_245 ) ;
F_188 ( V_495 ) ;
F_17 ( V_55 , L_246 ,
F_1 ( V_48 != NULL ) ) ;
V_17 = F_278 ( & V_154 -> V_60 , & V_499 ) ;
if ( V_17 )
return V_17 ;
return ( V_48 ) ? 0 : 1 ;
}
static void F_279 ( void )
{
F_280 ( & V_154 -> V_60 , & V_499 ) ;
}
static int F_281 ( struct V_90 * V_91 )
{
if ( ! V_48 )
F_84 ( V_91 , L_43 ) ;
else {
F_84 ( V_91 , L_202 ) ;
F_84 ( V_91 , L_247 ) ;
}
return 0 ;
}
static int F_282 ( char * V_126 )
{
char * V_159 ;
int V_47 , V_17 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_248 , & V_47 ) == 1 &&
V_47 >= 0 && V_47 <= 21 ) {
} else
return - V_94 ;
V_17 = F_15 ( V_47 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static inline bool F_283 ( const unsigned int V_500 )
{
#ifdef F_284
return false ;
#else
return ( 1U & ( V_501 >> V_500 ) ) == 0 ;
#endif
}
static int F_285 ( const unsigned int V_500 )
{
int V_30 ;
enum V_502 V_503 ;
switch ( V_504 ) {
case V_505 :
if ( ! F_7 ( V_192 ,
& V_30 , L_249 , L_6 , 1 << V_500 ) )
return - V_50 ;
V_503 = ( V_30 == 0 ) ?
V_491 :
( ( V_30 == 1 ) ?
V_490 :
V_506 ) ;
V_507 [ V_500 ] = V_503 ;
return V_503 ;
default:
return - V_49 ;
}
}
static int F_286 ( const unsigned int V_500 ,
const enum V_502 V_508 )
{
static const unsigned int V_509 [] = { 0 , 1 , 3 } ;
static const unsigned int V_510 [] = { 0 , 0x80 , 0xc0 } ;
int V_73 = 0 ;
switch ( V_504 ) {
case V_505 :
if ( F_142 ( V_500 > 7 ) )
return - V_94 ;
if ( F_142 ( F_283 ( V_500 ) ) )
return - V_158 ;
if ( ! F_7 ( V_511 , NULL , NULL , L_7 ,
( 1 << V_500 ) , V_509 [ V_508 ] ) )
V_73 = - V_50 ;
break;
case V_512 :
if ( F_142 ( V_500 > 7 ) )
return - V_94 ;
if ( F_142 ( F_283 ( V_500 ) ) )
return - V_158 ;
V_73 = F_14 ( V_513 , ( 1 << V_500 ) ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_514 ,
( V_508 == V_506 ) << V_500 ) ;
if ( V_73 >= 0 )
V_73 = F_14 ( V_515 ,
( V_508 != V_491 ) << V_500 ) ;
break;
case V_516 :
if ( F_142 ( V_500 >= V_517 ) )
return - V_94 ;
if ( F_142 ( F_283 ( V_500 ) ) )
return - V_158 ;
if ( ! F_7 ( V_511 , NULL , NULL , L_7 ,
V_500 , V_510 [ V_508 ] ) )
V_73 = - V_50 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
V_507 [ V_500 ] = V_508 ;
return V_73 ;
}
static int F_287 ( struct V_477 * V_478 ,
enum V_479 V_480 )
{
struct V_518 * V_66 = F_288 ( V_478 ,
struct V_518 , V_477 ) ;
enum V_502 V_519 ;
if ( V_480 == V_489 )
V_519 = V_491 ;
else if ( V_507 [ V_66 -> V_500 ] != V_506 )
V_519 = V_490 ;
else
V_519 = V_506 ;
return F_286 ( V_66 -> V_500 , V_519 ) ;
}
static int F_289 ( struct V_477 * V_478 ,
unsigned long * V_520 , unsigned long * V_521 )
{
struct V_518 * V_66 = F_288 ( V_478 ,
struct V_518 , V_477 ) ;
if ( * V_520 == 0 && * V_521 == 0 ) {
* V_520 = 500 ;
* V_521 = 500 ;
} else if ( ( * V_520 != 500 ) || ( * V_521 != 500 ) )
return - V_94 ;
return F_286 ( V_66 -> V_500 , V_506 ) ;
}
static enum V_479 F_290 ( struct V_477 * V_478 )
{
int V_73 ;
struct V_518 * V_66 = F_288 ( V_478 ,
struct V_518 , V_477 ) ;
V_73 = F_285 ( V_66 -> V_500 ) ;
if ( V_73 == V_491 || V_73 < 0 )
V_73 = V_489 ;
else
V_73 = V_492 ;
return V_73 ;
}
static void F_291 ( void )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_517 ; V_42 ++ ) {
if ( V_522 [ V_42 ] . V_477 . V_51 )
F_258 ( & V_522 [ V_42 ] . V_477 ) ;
}
F_37 ( V_522 ) ;
}
static int T_1 F_292 ( unsigned int V_500 )
{
int V_73 ;
V_522 [ V_500 ] . V_500 = V_500 ;
if ( ! V_523 [ V_500 ] )
return 0 ;
V_522 [ V_500 ] . V_477 . V_524 = & F_287 ;
V_522 [ V_500 ] . V_477 . V_525 = & F_289 ;
if ( V_504 == V_505 )
V_522 [ V_500 ] . V_477 . V_526 =
& F_290 ;
V_522 [ V_500 ] . V_477 . V_51 = V_523 [ V_500 ] ;
V_73 = F_256 ( & V_154 -> V_60 ,
& V_522 [ V_500 ] . V_477 ) ;
if ( V_73 < 0 )
V_522 [ V_500 ] . V_477 . V_51 = NULL ;
return V_73 ;
}
static enum V_527 T_1 F_293 ( void )
{
T_4 V_30 ;
if ( F_6 () ) {
V_30 = F_18 ( V_192 , L_250 , & V_511 ) ;
if ( F_19 ( V_30 ) )
return V_505 ;
V_30 = F_18 ( V_192 , L_251 , & V_511 ) ;
if ( F_19 ( V_30 ) )
return V_512 ;
}
V_30 = F_18 ( V_192 , L_252 , & V_511 ) ;
if ( F_19 ( V_30 ) )
return V_516 ;
V_511 = NULL ;
return V_528 ;
}
static int T_1 F_294 ( struct V_315 * V_316 )
{
unsigned int V_42 ;
int V_73 ;
unsigned long V_529 ;
F_17 ( V_55 , L_253 ) ;
V_504 = F_293 () ;
if ( V_504 != V_528 ) {
V_529 = F_4 ( V_530 ,
F_100 ( V_530 ) ) ;
if ( ! V_529 ) {
V_511 = NULL ;
V_504 = V_528 ;
}
}
F_17 ( V_55 , L_254 ,
F_1 ( V_504 ) , V_504 ) ;
if ( V_504 == V_528 )
return 1 ;
V_522 = F_35 ( sizeof( * V_522 ) * V_517 ,
V_83 ) ;
if ( ! V_522 ) {
F_8 ( L_255 ) ;
return - V_84 ;
}
for ( V_42 = 0 ; V_42 < V_517 ; V_42 ++ ) {
V_522 [ V_42 ] . V_500 = - 1 ;
if ( ! F_283 ( V_42 ) &&
F_295 ( V_42 , & V_529 ) ) {
V_73 = F_292 ( V_42 ) ;
if ( V_73 < 0 ) {
F_291 () ;
return V_73 ;
}
}
}
#ifdef F_284
F_32 ( L_256 ) ;
#endif
return 0 ;
}
static int F_296 ( struct V_90 * V_91 )
{
if ( ! V_504 ) {
F_84 ( V_91 , L_43 ) ;
return 0 ;
}
F_84 ( V_91 , L_202 ) ;
if ( V_504 == V_505 ) {
int V_42 , V_30 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_30 = F_285 ( V_42 ) ;
if ( V_30 < 0 )
return - V_50 ;
F_84 ( V_91 , L_257 ,
V_42 , F_297 ( V_30 ) ) ;
}
}
F_84 ( V_91 , L_258 ) ;
return 0 ;
}
static int F_298 ( char * V_126 )
{
char * V_159 ;
int V_500 , V_73 ;
enum V_502 V_118 ;
if ( ! V_504 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_259 , & V_500 ) != 1 )
return - V_94 ;
if ( V_500 < 0 || V_500 > ( V_517 - 1 ) ||
V_522 [ V_500 ] . V_500 < 0 )
return - V_75 ;
if ( strstr ( V_159 , L_244 ) ) {
V_118 = V_491 ;
} else if ( strstr ( V_159 , L_243 ) ) {
V_118 = V_490 ;
} else if ( strstr ( V_159 , L_260 ) ) {
V_118 = V_506 ;
} else {
return - V_94 ;
}
V_73 = F_286 ( V_500 , V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
static int T_1 F_299 ( struct V_315 * V_316 )
{
unsigned long V_13 ;
F_17 ( V_55 , L_261 ) ;
F_188 ( V_531 ) ;
F_17 ( V_55 , L_262 ,
F_1 ( V_532 != NULL ) ) ;
V_13 = F_4 ( V_533 ,
F_100 ( V_533 ) ) ;
V_186 . V_534 = ! ! ( V_13 & V_535 ) ;
return ( V_532 ) ? 0 : 1 ;
}
static int F_300 ( struct V_90 * V_91 )
{
if ( ! V_532 )
F_84 ( V_91 , L_43 ) ;
else {
F_84 ( V_91 , L_202 ) ;
F_84 ( V_91 , L_263 ) ;
}
return 0 ;
}
static int F_301 ( char * V_126 )
{
char * V_159 ;
int V_536 ;
if ( ! V_532 )
return - V_75 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( sscanf ( V_159 , L_248 , & V_536 ) == 1 &&
V_536 >= 0 && V_536 <= 17 ) {
} else
return - V_94 ;
if ( V_186 . V_534 ) {
if ( ! F_7 ( V_532 , NULL , NULL , L_7 ,
V_536 , 0 ) )
return - V_50 ;
} else {
if ( ! F_7 ( V_532 , NULL , NULL , L_8 ,
V_536 ) )
return - V_50 ;
}
}
return 0 ;
}
static int F_302 ( int V_537 , T_17 * V_38 )
{
int V_157 ;
T_18 V_538 ;
char V_539 [ 5 ] ;
V_157 = V_540 ;
switch ( V_541 ) {
#if V_542 >= 16
case V_543 :
if ( V_537 >= 8 && V_537 <= 15 ) {
V_157 = V_544 ;
V_537 -= 8 ;
}
#endif
case V_545 :
if ( V_537 <= 7 ) {
if ( ! F_11 ( V_157 + V_537 , & V_538 ) )
return - V_50 ;
* V_38 = V_538 * 1000 ;
return 0 ;
}
break;
case V_546 :
if ( V_537 <= 7 ) {
snprintf ( V_539 , sizeof( V_539 ) , L_264 , '0' + V_537 ) ;
if ( ! F_7 ( V_192 , NULL , L_265 , L_197 ) )
return - V_50 ;
if ( ! F_7 ( V_192 , & V_157 , V_539 , L_60 ) )
return - V_50 ;
* V_38 = ( V_157 - 2732 ) * 100 ;
return 0 ;
}
break;
case V_547 :
if ( V_537 <= 7 ) {
snprintf ( V_539 , sizeof( V_539 ) , L_264 , '0' + V_537 ) ;
if ( ! F_7 ( V_192 , & V_157 , V_539 , L_60 ) )
return - V_50 ;
if ( V_157 > 127 || V_157 < - 127 )
V_157 = V_548 ;
* V_38 = V_157 * 1000 ;
return 0 ;
}
break;
case V_549 :
default:
return - V_469 ;
}
return - V_94 ;
}
static int F_303 ( struct V_550 * V_118 )
{
int V_17 , V_42 ;
int V_221 ;
V_221 = 8 ;
V_42 = 0 ;
if ( ! V_118 )
return - V_94 ;
if ( V_541 == V_543 )
V_221 = 16 ;
for ( V_42 = 0 ; V_42 < V_221 ; V_42 ++ ) {
V_17 = F_302 ( V_42 , & V_118 -> V_551 [ V_42 ] ) ;
if ( V_17 )
return V_17 ;
}
return V_221 ;
}
static void F_204 ( void )
{
int V_221 , V_42 ;
struct V_550 V_157 ;
V_221 = F_303 ( & V_157 ) ;
if ( V_221 <= 0 )
return;
F_32 ( L_266 ) ;
for ( V_42 = 0 ; V_42 < V_221 ; V_42 ++ ) {
if ( V_157 . V_551 [ V_42 ] != V_552 )
F_304 ( L_267 , ( int ) ( V_157 . V_551 [ V_42 ] / 1000 ) ) ;
else
F_304 ( L_268 ) ;
}
F_304 ( L_269 ) ;
}
static T_8 F_305 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
struct V_553 * V_554 =
F_306 ( V_122 ) ;
int V_537 = V_554 -> V_555 ;
T_17 V_38 ;
int V_17 ;
V_17 = F_302 ( V_537 , & V_38 ) ;
if ( V_17 )
return V_17 ;
if ( V_38 == V_552 )
return - V_49 ;
return snprintf ( V_126 , V_102 , L_41 , V_38 ) ;
}
static int T_1 F_307 ( struct V_315 * V_316 )
{
T_6 V_157 , V_556 , V_557 ;
int V_42 ;
int V_558 ;
int V_17 ;
F_17 ( V_55 , L_270 ) ;
V_558 = F_7 ( V_192 , NULL , L_271 , L_239 ) ;
if ( V_7 . V_12 ) {
V_556 = V_557 = 0 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( F_11 ( V_540 + V_42 , & V_157 ) ) {
V_556 |= V_157 ;
} else {
V_556 = 0 ;
break;
}
if ( F_11 ( V_544 + V_42 , & V_157 ) ) {
V_557 |= V_157 ;
} else {
V_556 = 0 ;
break;
}
}
if ( V_556 == 0 ) {
if ( V_558 ) {
F_8 ( L_272 ) ;
V_541 = V_547 ;
} else {
F_8 ( L_273 ) ;
V_541 = V_549 ;
}
} else {
V_541 =
( V_557 != 0 ) ?
V_543 : V_545 ;
}
} else if ( V_558 ) {
if ( F_6 () &&
F_7 ( V_192 , NULL , L_265 , L_239 ) ) {
V_541 = V_546 ;
} else {
V_541 = V_547 ;
}
} else {
V_541 = V_549 ;
}
F_17 ( V_55 , L_274 ,
F_1 ( V_541 != V_549 ) ,
V_541 ) ;
switch ( V_541 ) {
case V_543 :
V_17 = F_190 ( & V_559 -> V_60 . V_125 ,
& V_560 ) ;
if ( V_17 )
return V_17 ;
break;
case V_545 :
case V_547 :
case V_546 :
V_17 = F_190 ( & V_559 -> V_60 . V_125 ,
& V_561 ) ;
if ( V_17 )
return V_17 ;
break;
case V_549 :
default:
return 1 ;
}
return 0 ;
}
static void F_308 ( void )
{
switch ( V_541 ) {
case V_543 :
F_55 ( & V_559 -> V_60 . V_125 ,
& V_560 ) ;
break;
case V_545 :
case V_547 :
case V_546 :
F_55 ( & V_559 -> V_60 . V_125 ,
& V_561 ) ;
break;
case V_549 :
default:
break;
}
}
static int F_309 ( struct V_90 * V_91 )
{
int V_221 , V_42 ;
struct V_550 V_157 ;
V_221 = F_303 ( & V_157 ) ;
if ( F_142 ( V_221 < 0 ) )
return V_221 ;
F_84 ( V_91 , L_275 ) ;
if ( V_221 > 0 ) {
for ( V_42 = 0 ; V_42 < ( V_221 - 1 ) ; V_42 ++ )
F_84 ( V_91 , L_276 , V_157 . V_551 [ V_42 ] / 1000 ) ;
F_84 ( V_91 , L_41 , V_157 . V_551 [ V_42 ] / 1000 ) ;
} else
F_84 ( V_91 , L_277 ) ;
return 0 ;
}
static unsigned int F_310 ( void )
{
T_6 V_562 ;
V_562 = ( F_131 ( V_242 )
& V_244 )
>> V_245 ;
V_562 &= V_276 ;
return V_562 ;
}
static void F_311 ( void )
{
T_6 V_563 = 0 ;
T_6 V_564 ;
if ( V_565 != V_566 )
return;
F_17 ( V_567 ,
L_278 ) ;
if ( F_157 ( & V_568 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_569 , & V_563 ) ) )
goto V_570;
V_563 &= V_571 ;
V_564 = F_131 ( V_242 ) ;
if ( V_563 != ( ( V_564 & V_244 )
>> V_245 ) ) {
V_564 &= ~ ( V_244 <<
V_245 ) ;
V_564 |= V_563 ;
F_312 ( V_564 , V_242 ) ;
F_20 ( V_567 ,
L_279 ,
( unsigned int ) V_563 , ( unsigned int ) V_564 ) ;
} else
F_17 ( V_567 ,
L_280 ,
( unsigned int ) V_563 , ( unsigned int ) V_564 ) ;
V_570:
F_118 ( & V_568 ) ;
}
static int F_313 ( int * V_30 )
{
T_6 V_563 = 0 ;
switch ( V_565 ) {
case V_572 :
* V_30 = F_310 () ;
return 0 ;
case V_573 :
case V_566 :
if ( F_142 ( ! F_11 ( V_569 , & V_563 ) ) )
return - V_50 ;
* V_30 = V_563 ;
return 0 ;
default:
return - V_49 ;
}
}
static int F_314 ( unsigned int V_38 )
{
T_6 V_563 = 0 ;
if ( F_142 ( ! F_11 ( V_569 , & V_563 ) ) )
return - V_50 ;
if ( F_142 ( ! F_13 ( V_569 ,
( V_563 & V_574 ) |
( V_38 & V_571 ) ) ) )
return - V_50 ;
return 0 ;
}
static int F_315 ( unsigned int V_38 )
{
int V_47 , V_575 ;
unsigned int V_576 , V_42 ;
V_576 = F_310 () ;
if ( V_38 == V_576 )
return 0 ;
V_47 = ( V_38 > V_576 ) ?
V_577 :
V_578 ;
V_575 = ( V_38 > V_576 ) ? 1 : - 1 ;
for ( V_42 = V_576 ; V_42 != V_38 ; V_42 += V_575 )
if ( F_15 ( V_47 ) )
return - V_50 ;
return 0 ;
}
static int F_316 ( unsigned int V_38 )
{
int V_17 ;
if ( V_38 > V_276 )
return - V_94 ;
F_17 ( V_567 ,
L_281 , V_38 ) ;
V_17 = F_157 ( & V_568 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_565 ) {
case V_573 :
case V_566 :
V_17 = F_314 ( V_38 ) ;
break;
case V_572 :
V_17 = F_315 ( V_38 ) ;
break;
default:
V_17 = - V_49 ;
}
F_118 ( & V_568 ) ;
return V_17 ;
}
static int F_317 ( struct V_579 * V_580 )
{
unsigned int V_56 =
( V_580 -> V_581 . V_582 == V_583 &&
V_580 -> V_581 . V_584 == V_583 ) ?
V_580 -> V_581 . V_480 : 0 ;
F_20 ( V_567 ,
L_282 ,
V_56 ) ;
return F_316 ( V_56 ) ;
}
static int V_526 ( struct V_579 * V_580 )
{
int V_30 , V_17 ;
V_17 = F_157 ( & V_568 ) ;
if ( V_17 < 0 )
return 0 ;
V_17 = F_313 ( & V_30 ) ;
F_118 ( & V_568 ) ;
if ( V_17 < 0 )
return 0 ;
return V_30 & V_571 ;
}
static void F_318 ( void )
{
F_319 ( V_585 ,
V_586 ) ;
}
static int T_1 F_320 ( T_3 V_16 )
{
struct V_26 V_587 = { V_588 , NULL } ;
union V_23 * V_589 ;
struct V_59 * V_74 , * V_590 ;
int V_73 ;
if ( F_22 ( V_16 , & V_74 ) )
return 0 ;
V_73 = 0 ;
F_321 (child, &device->children, node) {
T_4 V_30 = F_9 ( V_590 -> V_16 , L_283 ,
NULL , & V_587 ) ;
if ( F_31 ( V_30 ) )
continue;
V_589 = (union V_23 * ) V_587 . V_36 ;
if ( ! V_589 || ( V_589 -> type != V_591 ) ) {
F_8 ( L_284 ,
V_362 ) ;
V_73 = 0 ;
} else {
V_73 = V_589 -> V_592 . V_35 ;
}
break;
}
F_37 ( V_587 . V_36 ) ;
return V_73 ;
}
static unsigned int T_1 F_322 ( void )
{
T_3 V_593 ;
int V_594 = 0 ;
F_24 ( L_12 , NULL , & V_593 ) ;
if ( V_593 )
V_594 = F_320 ( V_593 ) ;
V_186 . V_595 = ( V_594 > 0 ) ;
return ( V_594 > 2 ) ? ( V_594 - 2 ) : 0 ;
}
static void T_1 F_323 ( void )
{
unsigned int V_596 ;
F_17 ( V_55 ,
L_285 ) ;
V_596 = F_322 () ;
switch ( V_596 ) {
case 16 :
V_276 = 15 ;
break;
case 8 :
case 0 :
V_276 = 7 ;
break;
default:
V_186 . V_277 = 1 ;
V_276 = V_596 - 1 ;
}
F_324 ( L_286 , V_276 + 1 ) ;
}
static int T_1 F_325 ( struct V_315 * V_316 )
{
struct V_597 V_581 ;
int V_596 ;
unsigned long V_13 ;
F_17 ( V_55 , L_287 ) ;
F_189 ( & V_568 ) ;
V_13 = F_4 ( V_598 ,
F_100 ( V_598 ) ) ;
if ( V_186 . V_277 )
return 1 ;
if ( ! V_599 ) {
F_20 ( V_55 | V_567 ,
L_288 ) ;
return 1 ;
}
if ( F_194 () != V_372 ) {
if ( V_599 > 1 ) {
F_76 ( L_289 ) ;
return 1 ;
} else if ( V_599 == 1 ) {
F_62 ( L_290 ) ;
return 1 ;
}
} else if ( V_186 . V_595 && V_599 > 1 ) {
F_32 ( L_291 ) ;
}
if ( V_565 > V_600 )
return - V_94 ;
if ( V_565 == V_601 ||
V_565 == V_600 ) {
if ( V_13 & V_602 )
V_565 = V_566 ;
else
V_565 = V_572 ;
F_20 ( V_567 ,
L_292 ,
V_565 ) ;
}
if ( ! F_6 () &&
( V_565 == V_566 ||
V_565 == V_573 ) )
return - V_94 ;
if ( F_313 ( & V_596 ) < 0 )
return 1 ;
memset ( & V_581 , 0 , sizeof( struct V_597 ) ) ;
V_581 . type = V_603 ;
V_581 . V_604 = V_276 ;
V_581 . V_480 = V_596 & V_571 ;
V_585 = F_326 ( V_605 ,
NULL , NULL ,
& V_606 ,
& V_581 ) ;
if ( F_147 ( V_585 ) ) {
int V_73 = F_327 ( V_585 ) ;
V_585 = NULL ;
F_8 ( L_293 ) ;
return V_73 ;
}
F_17 ( V_55 | V_567 ,
L_294 ) ;
if ( V_13 & V_607 ) {
F_32 ( L_295 ,
V_565 ) ;
F_32 ( L_296 ,
V_362 ) ;
}
F_328 ( V_585 ) ;
F_17 ( V_55 | V_567 ,
L_297 ) ;
F_114 ( V_200
| V_608
| V_609 ) ;
return 0 ;
}
static void F_329 ( void )
{
F_311 () ;
}
static void F_330 ( void )
{
F_311 () ;
}
static void F_331 ( void )
{
if ( V_585 ) {
F_17 ( V_310 | V_567 ,
L_298 ) ;
F_332 ( V_585 ) ;
}
F_311 () ;
}
static int F_333 ( struct V_90 * V_91 )
{
int V_56 ;
V_56 = V_526 ( NULL ) ;
if ( V_56 < 0 ) {
F_84 ( V_91 , L_299 ) ;
} else {
F_84 ( V_91 , L_300 , V_56 ) ;
F_84 ( V_91 , L_301 ) ;
F_84 ( V_91 , L_302 ,
V_276 ) ;
}
return 0 ;
}
static int F_334 ( char * V_126 )
{
int V_56 ;
int V_73 ;
char * V_159 ;
V_56 = V_526 ( NULL ) ;
if ( V_56 < 0 )
return V_56 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( F_86 ( V_159 , L_303 ) == 0 ) {
if ( V_56 < V_276 )
V_56 ++ ;
} else if ( F_86 ( V_159 , L_304 ) == 0 ) {
if ( V_56 > 0 )
V_56 -- ;
} else if ( sscanf ( V_159 , L_305 , & V_56 ) == 1 &&
V_56 >= 0 && V_56 <= V_276 ) {
} else
return - V_94 ;
}
F_82 ( L_306 ,
L_307 , V_56 ) ;
V_73 = F_316 ( V_56 ) ;
if ( ! V_73 && V_585 )
F_319 ( V_585 ,
V_610 ) ;
return ( V_73 == - V_611 ) ? - V_298 : V_73 ;
}
static void F_335 ( void )
{
T_6 V_563 = 0 ;
T_6 V_564 ;
T_6 V_612 ;
if ( V_613 != V_614 )
return;
if ( ! V_615 )
return;
if ( V_616 )
return;
F_17 ( V_617 ,
L_308 ) ;
if ( V_186 . V_618 )
V_612 = V_619 ;
else
V_612 = V_619 | V_620 ;
if ( F_157 ( & V_621 ) < 0 )
return;
if ( F_142 ( ! F_11 ( V_622 , & V_563 ) ) )
goto V_570;
V_563 &= V_612 ;
V_564 = F_131 ( V_249 ) ;
if ( V_563 != ( V_564 & V_612 ) ) {
V_564 &= ~ V_612 ;
V_564 |= V_563 ;
F_312 ( V_564 , V_249 ) ;
F_20 ( V_617 ,
L_309 ,
( unsigned int ) V_563 , ( unsigned int ) V_564 ) ;
} else {
F_17 ( V_617 ,
L_310 ,
( unsigned int ) V_563 , ( unsigned int ) V_564 ) ;
}
V_570:
F_118 ( & V_621 ) ;
}
static int F_336 ( T_6 * V_30 )
{
T_6 V_118 ;
if ( ! F_11 ( V_622 , & V_118 ) )
return - V_50 ;
* V_30 = V_118 ;
F_20 ( V_617 , L_311 , V_118 ) ;
return 0 ;
}
static int F_337 ( T_6 * V_30 )
{
return F_336 ( V_30 ) ;
}
static int F_338 ( const T_6 V_30 )
{
if ( ! F_13 ( V_622 , V_30 ) )
return - V_50 ;
F_20 ( V_617 , L_312 , V_30 ) ;
F_339 ( 1 ) ;
return 0 ;
}
static int F_340 ( const T_6 V_30 )
{
return F_338 ( V_30 ) ;
}
static int F_341 ( const bool V_253 )
{
int V_73 ;
T_6 V_118 , V_221 ;
if ( F_157 ( & V_621 ) < 0 )
return - V_611 ;
V_73 = F_336 ( & V_118 ) ;
if ( V_73 )
goto V_570;
V_221 = ( V_253 ) ? V_118 | V_619 :
V_118 & ~ V_619 ;
if ( V_221 != V_118 ) {
V_73 = F_338 ( V_221 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_570:
F_118 ( & V_621 ) ;
return V_73 ;
}
static int F_342 ( const bool V_253 )
{
F_20 ( V_617 , L_313 ,
( V_253 ) ? L_1 : L_39 ) ;
return F_341 ( V_253 ) ;
}
static int F_343 ( const bool V_253 )
{
int V_73 ;
F_20 ( V_617 , L_314 ,
( V_253 ) ? L_1 : L_39 ) ;
V_73 = F_341 ( V_253 ) ;
return ( V_73 < 0 ) ? V_73 : 0 ;
}
static int F_344 ( const T_6 V_623 )
{
int V_73 ;
T_6 V_118 , V_221 ;
if ( V_623 > V_624 )
return - V_94 ;
if ( F_157 ( & V_621 ) < 0 )
return - V_611 ;
V_73 = F_336 ( & V_118 ) ;
if ( V_73 )
goto V_570;
V_221 = ( V_118 & ~ V_620 ) | V_623 ;
if ( V_221 != V_118 ) {
V_73 = F_338 ( V_221 ) ;
if ( ! V_73 )
V_73 = 1 ;
}
V_570:
F_118 ( & V_621 ) ;
return V_73 ;
}
static int F_345 ( bool V_625 )
{
int V_27 ;
if ( ! F_5 () )
return - V_75 ;
if ( V_625 ) {
if ( ! F_7 ( V_192 , & V_626 ,
L_315 , L_92 ) )
return - V_50 ;
F_20 ( V_55 | V_617 ,
L_316 ,
V_626 ) ;
}
if ( ! F_7 ( V_192 , & V_27 , L_317 , L_225 ,
( int ) V_627 ) )
return - V_50 ;
if ( V_27 != V_627 )
F_62 ( L_318 ,
V_27 ) ;
if ( V_186 . V_618 )
V_27 = F_343 ( false ) ;
else
V_27 = F_340 ( V_624 ) ;
if ( V_27 != 0 )
F_62 ( L_319 ) ;
return 0 ;
}
static void F_346 ( void )
{
int V_628 ;
if ( ! F_7 ( V_192 , & V_628 , L_317 , L_225 , V_626 )
|| V_628 != V_626 )
F_62 ( L_320 ) ;
}
static int F_347 ( const T_6 V_623 )
{
F_20 ( V_617 ,
L_321 , V_623 ) ;
return F_344 ( V_623 ) ;
}
static void F_348 ( void )
{
struct V_629 * V_222 ;
if ( V_630 && V_630 -> V_631 ) {
V_222 = V_630 -> V_631 ;
if ( V_222 -> V_632 )
F_349 ( V_630 ,
V_633 ,
V_222 -> V_632 ) ;
if ( V_222 -> V_634 )
F_349 ( V_630 ,
V_633 ,
V_222 -> V_634 ) ;
}
}
static int F_350 ( struct V_635 * V_636 ,
struct V_637 * V_638 )
{
V_638 -> type = V_639 ;
V_638 -> V_35 = 1 ;
V_638 -> V_38 . integer . V_640 = 0 ;
V_638 -> V_38 . integer . V_127 = V_624 ;
return 0 ;
}
static int F_351 ( struct V_635 * V_636 ,
struct V_641 * V_642 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_337 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_642 -> V_38 . integer . V_38 [ 0 ] = V_118 & V_620 ;
return 0 ;
}
static int F_352 ( struct V_635 * V_636 ,
struct V_641 * V_642 )
{
F_82 ( L_322 , L_323 ,
V_642 -> V_38 . integer . V_38 [ 0 ] ) ;
return F_347 ( V_642 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static int F_353 ( struct V_635 * V_636 ,
struct V_641 * V_642 )
{
T_6 V_118 ;
int V_73 ;
V_73 = F_337 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_642 -> V_38 . integer . V_38 [ 0 ] =
( V_118 & V_619 ) ? 0 : 1 ;
return 0 ;
}
static int F_354 ( struct V_635 * V_636 ,
struct V_641 * V_642 )
{
F_82 ( L_322 , L_324 ,
V_642 -> V_38 . integer . V_38 [ 0 ] ?
L_39 : L_1 ) ;
return F_342 ( ! V_642 -> V_38 . integer . V_38 [ 0 ] ) ;
}
static void F_355 ( void )
{
F_335 () ;
}
static void F_356 ( void )
{
if ( V_616 ) {
if ( F_345 ( false ) < 0 )
F_62 ( L_325 ) ;
} else {
F_348 () ;
}
}
static void F_357 ( void )
{
F_335 () ;
}
static void F_358 ( void )
{
if ( V_630 ) {
F_359 ( V_630 ) ;
V_630 = NULL ;
}
F_335 () ;
if ( V_616 )
F_346 () ;
}
static int T_1 F_360 ( void )
{
struct V_643 * V_644 ;
struct V_629 * V_66 ;
struct V_635 * V_645 ;
struct V_635 * V_646 ;
int V_73 ;
V_73 = F_361 ( & V_154 -> V_60 ,
V_647 , V_648 , V_649 ,
sizeof( struct V_629 ) , & V_644 ) ;
if ( V_73 < 0 || ! V_644 ) {
F_8 ( L_326 , V_73 ) ;
return 1 ;
}
F_25 ( ! V_644 -> V_631 ) ;
V_66 = V_644 -> V_631 ;
V_66 -> V_644 = V_644 ;
F_362 ( V_644 -> V_81 , V_650 ,
sizeof( V_644 -> V_81 ) ) ;
F_362 ( V_644 -> V_651 , V_652 ,
sizeof( V_644 -> V_651 ) ) ;
snprintf ( V_644 -> V_653 , sizeof( V_644 -> V_653 ) , L_327 ,
( V_7 . V_654 ) ?
V_7 . V_654 : L_328 ) ;
snprintf ( V_644 -> V_655 , sizeof( V_644 -> V_655 ) ,
L_329 , V_644 -> V_651 , V_622 ,
( V_7 . V_654 ) ?
V_7 . V_654 : L_330 ) ;
if ( V_615 ) {
V_656 . V_657 = F_352 ;
V_656 . V_658 =
V_659 ;
V_660 . V_657 = F_354 ;
V_660 . V_658 =
V_659 ;
}
if ( ! V_186 . V_618 ) {
V_645 = F_363 ( & V_656 , NULL ) ;
V_73 = F_364 ( V_644 , V_645 ) ;
if ( V_73 < 0 ) {
F_8 ( L_331 ,
V_73 ) ;
goto V_361;
}
V_66 -> V_634 = & V_645 -> V_144 ;
}
V_646 = F_363 ( & V_660 , NULL ) ;
V_73 = F_364 ( V_644 , V_646 ) ;
if ( V_73 < 0 ) {
F_8 ( L_332 , V_73 ) ;
goto V_361;
}
V_66 -> V_632 = & V_646 -> V_144 ;
V_73 = F_365 ( V_644 ) ;
if ( V_73 < 0 ) {
F_8 ( L_333 , V_73 ) ;
goto V_361;
}
V_630 = V_644 ;
return 0 ;
V_361:
F_359 ( V_644 ) ;
return 1 ;
}
static int T_1 F_366 ( struct V_315 * V_316 )
{
unsigned long V_13 ;
int V_73 ;
F_17 ( V_55 , L_334 ) ;
F_189 ( & V_621 ) ;
if ( V_613 > V_661 )
return - V_94 ;
if ( V_613 == V_662 ) {
F_8 ( L_335 ,
V_362 ) ;
return 1 ;
}
if ( V_663 >= V_664 )
return - V_94 ;
if ( ! V_665 ) {
F_17 ( V_55 | V_617 ,
L_336 ) ;
return 1 ;
}
V_13 = F_4 ( V_666 ,
F_100 ( V_666 ) ) ;
switch ( V_663 ) {
case V_667 :
if ( V_13 & V_668 )
V_186 . V_618 = 1 ;
else if ( V_13 & V_669 )
V_186 . V_618 = 0 ;
else
return 1 ;
break;
case V_670 :
V_186 . V_618 = 0 ;
break;
case V_671 :
V_186 . V_618 = 1 ;
break;
default:
return 1 ;
}
if ( V_663 != V_667 )
F_20 ( V_55 | V_617 ,
L_337 ,
V_663 ) ;
if ( V_613 == V_672 ||
V_613 == V_661 ) {
V_613 = V_614 ;
F_20 ( V_55 | V_617 ,
L_338 ,
V_613 ) ;
} else {
F_20 ( V_55 | V_617 ,
L_339 ,
V_613 ) ;
}
F_17 ( V_55 | V_617 ,
L_340 ,
F_1 ( ! V_186 . V_618 ) ) ;
if ( V_673 && F_345 ( true ) == 0 ) {
V_616 = true ;
} else {
V_73 = F_360 () ;
if ( V_73 ) {
F_8 ( L_341 ) ;
return V_73 ;
}
F_76 ( L_342 ,
( V_615 ) ?
L_343 :
L_344 ) ;
}
F_17 ( V_55 | V_617 ,
L_345 ) ;
F_114 ( V_200
| V_674
| V_675
| V_676 ) ;
return 0 ;
}
static int F_367 ( struct V_90 * V_91 )
{
T_6 V_30 ;
if ( F_337 ( & V_30 ) < 0 ) {
F_84 ( V_91 , L_299 ) ;
} else {
if ( V_186 . V_618 )
F_84 ( V_91 , L_346 ) ;
else
F_84 ( V_91 , L_300 ,
V_30 & V_620 ) ;
F_84 ( V_91 , L_347 ,
F_274 ( V_30 , V_677 ) ) ;
if ( V_615 ) {
F_84 ( V_91 , L_348 ) ;
if ( ! V_186 . V_618 ) {
F_84 ( V_91 , L_301 ) ;
F_84 ( V_91 , L_302 ,
V_624 ) ;
}
}
}
return 0 ;
}
static int F_368 ( char * V_126 )
{
T_6 V_118 ;
T_6 V_678 , V_679 ;
int V_680 ;
char * V_159 ;
int V_73 ;
if ( ! V_615 && V_69 != V_296 ) {
if ( F_142 ( ! V_205 . V_681 ) ) {
V_205 . V_681 = 1 ;
F_32 ( L_349 ) ;
F_32 ( L_350 ) ;
}
return - V_158 ;
}
V_73 = F_337 ( & V_118 ) ;
if ( V_73 < 0 )
return V_73 ;
V_678 = V_118 & V_620 ;
V_679 = V_118 & V_619 ;
while ( ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! V_186 . V_618 ) {
if ( F_86 ( V_159 , L_303 ) == 0 ) {
if ( V_679 )
V_679 = 0 ;
else if ( V_678 < V_624 )
V_678 ++ ;
continue;
} else if ( F_86 ( V_159 , L_304 ) == 0 ) {
if ( V_679 )
V_679 = 0 ;
else if ( V_678 > 0 )
V_678 -- ;
continue;
} else if ( sscanf ( V_159 , L_351 , & V_680 ) == 1 &&
V_680 >= 0 && V_680 <= V_624 ) {
V_678 = V_680 ;
continue;
}
}
if ( F_86 ( V_159 , L_352 ) == 0 )
V_679 = V_619 ;
else if ( F_86 ( V_159 , L_353 ) == 0 )
V_679 = 0 ;
else
return - V_94 ;
}
if ( V_186 . V_618 ) {
F_82 ( L_354 , L_324 ,
V_679 ? L_1 : L_39 ) ;
V_73 = F_343 ( ! ! V_679 ) ;
} else {
F_82 ( L_354 ,
L_355 ,
V_679 ? L_1 : L_39 , V_678 ) ;
V_73 = F_340 ( V_679 | V_678 ) ;
}
F_348 () ;
return ( V_73 == - V_611 ) ? - V_298 : V_73 ;
}
static inline void F_348 ( void )
{
}
static int T_1 F_366 ( struct V_315 * V_316 )
{
F_76 ( L_356 ) ;
return 1 ;
}
static void F_369 ( void )
{
if ( V_682 == 0x07 ) {
F_32 ( L_357 ) ;
V_186 . V_683 = 1 ;
}
}
static void F_370 ( T_6 * V_684 )
{
if ( F_142 ( V_186 . V_683 ) ) {
if ( * V_684 != V_682 ) {
V_186 . V_683 = 0 ;
} else {
* V_684 = V_685 ;
}
}
}
static bool F_371 ( void )
{
if ( V_186 . V_686 ) {
T_6 V_687 ;
if ( F_12 ( V_688 , & V_687 ) < 0 )
return false ;
V_687 &= 0xFEU ;
if ( F_14 ( V_688 , V_687 ) < 0 )
return false ;
}
return true ;
}
static bool F_372 ( void )
{
T_6 V_687 ;
if ( ! V_186 . V_686 )
return false ;
if ( F_12 ( V_688 , & V_687 ) < 0 )
return false ;
V_687 |= 0x01U ;
if ( F_14 ( V_688 , V_687 ) < 0 )
return false ;
return true ;
}
static void F_373 ( T_6 V_30 )
{
if ( ( V_30 &
( V_685 | V_689 ) ) == 0 ) {
if ( V_30 > 7 )
V_690 = 7 ;
else
V_690 = V_30 ;
}
}
static int F_374 ( T_6 * V_30 )
{
T_6 V_118 ;
switch ( V_691 ) {
case V_692 : {
int V_17 ;
if ( F_142 ( ! F_7 ( V_693 , & V_17 , NULL , L_60 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) )
* V_30 = V_17 & 0x07 ;
break;
}
case V_694 :
if ( F_142 ( ! F_11 ( V_695 , & V_118 ) ) )
return - V_50 ;
if ( F_140 ( V_30 ) ) {
* V_30 = V_118 ;
F_370 ( V_30 ) ;
}
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_375 ( T_6 * V_30 )
{
int V_73 ;
T_6 V_118 ;
if ( F_157 ( & V_696 ) )
return - V_298 ;
V_73 = F_374 ( & V_118 ) ;
if ( ! V_73 )
F_373 ( V_118 ) ;
F_118 ( & V_696 ) ;
if ( V_73 )
return V_73 ;
if ( V_30 )
* V_30 = V_118 ;
return 0 ;
}
static int F_376 ( unsigned int * V_697 )
{
T_6 V_698 , V_699 ;
switch ( V_691 ) {
case V_694 :
if ( F_142 ( ! F_371 () ) )
return - V_50 ;
if ( F_142 ( ! F_11 ( V_700 , & V_699 ) ||
! F_11 ( V_700 + 1 , & V_698 ) ) )
return - V_50 ;
if ( F_140 ( V_697 ) )
* V_697 = ( V_698 << 8 ) | V_699 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_377 ( unsigned int * V_697 )
{
T_6 V_698 , V_699 ;
bool V_73 ;
switch ( V_691 ) {
case V_694 :
if ( F_142 ( ! F_372 () ) )
return - V_50 ;
V_73 = ! F_11 ( V_700 , & V_699 ) ||
! F_11 ( V_700 + 1 , & V_698 ) ;
F_371 () ;
if ( V_73 )
return - V_50 ;
if ( F_140 ( V_697 ) )
* V_697 = ( V_698 << 8 ) | V_699 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_378 ( int V_56 )
{
if ( ! V_701 )
return - V_158 ;
switch ( V_702 ) {
case V_703 :
if ( V_56 >= 0 && V_56 <= 7 ) {
if ( ! F_7 ( V_704 , NULL , NULL , L_8 , V_56 ) )
return - V_50 ;
} else
return - V_94 ;
break;
case V_705 :
case V_706 :
if ( ! ( V_56 & V_685 ) &&
! ( V_56 & V_689 ) &&
( ( V_56 < 0 ) || ( V_56 > 7 ) ) )
return - V_94 ;
if ( V_56 & V_689 )
V_56 |= 7 ;
else if ( V_56 & V_685 )
V_56 |= 4 ;
if ( ! F_13 ( V_695 , V_56 ) )
return - V_50 ;
else
V_186 . V_683 = 0 ;
break;
default:
return - V_49 ;
}
F_17 ( V_707 ,
L_358 , V_56 ) ;
return 0 ;
}
static int F_379 ( int V_56 )
{
int V_73 ;
if ( ! V_701 )
return - V_158 ;
if ( F_157 ( & V_696 ) )
return - V_298 ;
if ( V_56 == V_708 )
V_56 = V_690 ;
V_73 = F_378 ( V_56 ) ;
if ( ! V_73 )
F_373 ( V_56 ) ;
F_118 ( & V_696 ) ;
return V_73 ;
}
static int F_380 ( void )
{
T_6 V_118 ;
int V_73 ;
if ( ! V_701 )
return - V_158 ;
if ( F_157 ( & V_696 ) )
return - V_298 ;
switch ( V_702 ) {
case V_705 :
case V_706 :
V_73 = F_374 ( & V_118 ) ;
if ( V_73 < 0 )
break;
if ( V_118 != 7 ) {
V_118 &= 0x07 ;
V_118 |= V_685 | 4 ;
}
if ( ! F_13 ( V_695 , V_118 ) )
V_73 = - V_50 ;
else {
V_186 . V_683 = 0 ;
V_73 = 0 ;
}
break;
case V_703 :
V_73 = F_374 ( & V_118 ) ;
if ( V_73 < 0 )
break;
V_118 &= 0x07 ;
V_118 |= 4 ;
if ( ! F_7 ( V_704 , NULL , NULL , L_8 , V_118 ) )
V_73 = - V_50 ;
else
V_73 = 0 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_696 ) ;
if ( ! V_73 )
F_17 ( V_707 ,
L_358 ,
V_118 ) ;
return V_73 ;
}
static int F_381 ( void )
{
int V_73 ;
if ( ! V_701 )
return - V_158 ;
if ( F_157 ( & V_696 ) )
return - V_298 ;
V_73 = 0 ;
switch ( V_702 ) {
case V_705 :
case V_706 :
if ( ! F_13 ( V_695 , 0x00 ) )
V_73 = - V_50 ;
else {
V_690 = 0 ;
V_186 . V_683 = 0 ;
}
break;
case V_703 :
if ( ! F_7 ( V_704 , NULL , NULL , L_8 , 0x00 ) )
V_73 = - V_50 ;
else
V_690 = 0 ;
break;
default:
V_73 = - V_49 ;
}
if ( ! V_73 )
F_17 ( V_707 ,
L_359 ) ;
F_118 ( & V_696 ) ;
return V_73 ;
}
static int F_382 ( int V_697 )
{
int V_73 ;
if ( ! V_701 )
return - V_158 ;
if ( F_157 ( & V_696 ) )
return - V_298 ;
V_73 = 0 ;
switch ( V_702 ) {
case V_705 :
if ( V_697 >= 0 && V_697 <= 65535 ) {
if ( ! F_7 ( V_709 , NULL , NULL , L_360 ,
V_697 , V_697 , V_697 ) )
V_73 = - V_50 ;
} else
V_73 = - V_94 ;
break;
default:
V_73 = - V_49 ;
}
F_118 ( & V_696 ) ;
return V_73 ;
}
static void F_383 ( void )
{
if ( V_702 == V_710 )
return;
if ( V_711 > 0 &&
V_69 != V_204 )
F_384 ( V_712 , & V_713 ,
F_385 ( V_711 * 1000 ) ) ;
else
F_386 ( & V_713 ) ;
}
static void F_387 ( struct V_714 * V_715 )
{
int V_73 ;
if ( V_69 != V_70 )
return;
F_32 ( L_361 ) ;
V_73 = F_380 () ;
if ( V_73 < 0 ) {
F_8 ( L_362 ,
V_73 ) ;
F_383 () ;
}
}
static T_8 F_388 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 , V_374 ;
T_6 V_30 ;
V_17 = F_375 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 & V_689 ) {
V_374 = 0 ;
} else if ( V_30 & V_685 ) {
V_374 = 2 ;
} else
V_374 = 1 ;
return snprintf ( V_126 , V_102 , L_41 , V_374 ) ;
}
static T_8 F_389 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_157 ;
int V_17 , V_56 ;
if ( F_57 ( V_126 , 2 , & V_157 ) )
return - V_94 ;
F_82 ( L_363 ,
L_364 , V_157 ) ;
switch ( V_157 ) {
case 0 :
V_56 = V_689 ;
break;
case 1 :
V_56 = V_708 ;
break;
case 2 :
V_56 = V_685 ;
break;
case 3 :
return - V_469 ;
default:
return - V_94 ;
}
V_17 = F_379 ( V_56 ) ;
if ( V_17 == - V_49 )
return - V_94 ;
else if ( V_17 < 0 )
return V_17 ;
F_383 () ;
return V_35 ;
}
static T_8 F_390 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
T_6 V_30 ;
V_17 = F_375 ( & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_30 &
( V_685 | V_689 ) ) != 0 )
V_30 = V_690 ;
if ( V_30 > 7 )
V_30 = 7 ;
return snprintf ( V_126 , V_102 , L_365 , ( V_30 * 255 ) / 7 ) ;
}
static T_8 F_391 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
const char * V_126 , T_10 V_35 )
{
unsigned long V_118 ;
int V_73 ;
T_6 V_30 , V_716 ;
if ( F_57 ( V_126 , 255 , & V_118 ) )
return - V_94 ;
F_82 ( L_366 ,
L_367 , V_118 ) ;
V_716 = ( V_118 >> 5 ) & 0x07 ;
if ( F_157 ( & V_696 ) )
return - V_298 ;
V_73 = F_374 ( & V_30 ) ;
if ( ! V_73 && ( V_30 &
( V_685 | V_689 ) ) == 0 ) {
V_73 = F_378 ( V_716 ) ;
if ( V_73 == - V_49 )
V_73 = - V_94 ;
else if ( ! V_73 ) {
F_373 ( V_716 ) ;
F_383 () ;
}
}
F_118 ( & V_696 ) ;
return ( V_73 ) ? V_73 : V_35 ;
}
static T_8 F_392 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_697 ;
V_17 = F_376 ( & V_697 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_365 , V_697 ) ;
}
static T_8 F_393 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
int V_17 ;
unsigned int V_697 ;
V_17 = F_377 ( & V_697 ) ;
if ( V_17 < 0 )
return V_17 ;
return snprintf ( V_126 , V_102 , L_365 , V_697 ) ;
}
static T_8 F_394 ( struct V_161 * V_162 , char * V_126 )
{
return snprintf ( V_126 , V_102 , L_365 , V_711 ) ;
}
static T_8 F_395 ( struct V_161 * V_162 , const char * V_126 ,
T_10 V_35 )
{
unsigned long V_157 ;
if ( F_57 ( V_126 , 120 , & V_157 ) )
return - V_94 ;
if ( ! V_701 )
return - V_158 ;
V_711 = V_157 ;
F_383 () ;
F_82 ( L_368 , L_85 , V_157 ) ;
return V_35 ;
}
static int T_1 F_396 ( struct V_315 * V_316 )
{
int V_73 ;
unsigned long V_13 ;
F_17 ( V_55 | V_707 ,
L_369 ) ;
F_189 ( & V_696 ) ;
V_691 = V_717 ;
V_702 = V_710 ;
V_718 = 0 ;
V_711 = 0 ;
V_186 . V_683 = 0 ;
V_186 . V_686 = 0 ;
V_690 = 7 ;
if ( F_6 () ) {
F_188 ( V_719 ) ;
F_188 ( V_720 ) ;
F_188 ( V_721 ) ;
}
V_13 = F_4 ( V_722 ,
F_100 ( V_722 ) ) ;
if ( V_693 ) {
V_691 = V_692 ;
} else {
if ( F_140 ( F_11 ( V_695 ,
& V_682 ) ) ) {
V_691 = V_694 ;
if ( V_13 & V_723 )
F_369 () ;
if ( V_13 & V_724 ) {
V_186 . V_686 = 1 ;
F_20 ( V_55 | V_707 ,
L_370 ) ;
}
} else {
F_8 ( L_371 ) ;
return 1 ;
}
}
if ( V_704 ) {
V_702 = V_703 ;
V_718 |=
V_725 | V_726 ;
} else {
if ( ! V_693 ) {
if ( V_709 ) {
V_702 =
V_705 ;
V_718 |=
V_727 |
V_725 |
V_726 ;
} else {
V_702 = V_706 ;
V_718 |=
V_725 |
V_726 ;
}
}
}
F_17 ( V_55 | V_707 ,
L_372 ,
F_1 ( V_691 != V_717 ||
V_702 != V_710 ) ,
V_691 , V_702 ) ;
if ( ! V_701 ) {
V_702 = V_710 ;
V_718 = 0 ;
F_20 ( V_55 | V_707 ,
L_373 ) ;
}
if ( V_691 != V_717 )
F_375 ( NULL ) ;
if ( V_691 != V_717 ||
V_702 != V_710 ) {
if ( V_186 . V_686 ) {
V_728 [ F_100 ( V_728 ) - 2 ] =
& V_729 . V_122 ;
}
V_73 = F_190 ( & V_559 -> V_60 . V_125 ,
& V_730 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_101 ( & V_731 . V_81 ,
& V_732 ) ;
if ( V_73 < 0 ) {
F_55 ( & V_559 -> V_60 . V_125 ,
& V_730 ) ;
return V_73 ;
}
return 0 ;
} else
return 1 ;
}
static void F_397 ( void )
{
F_17 ( V_310 | V_707 ,
L_374 ) ;
F_55 ( & V_559 -> V_60 . V_125 , & V_730 ) ;
F_104 ( & V_731 . V_81 ,
& V_732 ) ;
F_386 ( & V_713 ) ;
F_398 ( V_712 ) ;
}
static void F_399 ( void )
{
int V_73 ;
if ( ! V_701 )
return;
V_733 = 0 ;
V_73 = F_375 ( & V_733 ) ;
if ( V_73 < 0 )
F_32 ( L_375 ,
V_73 ) ;
if ( V_186 . V_683 )
V_733 = 0 ;
}
static void F_400 ( void )
{
T_6 V_734 = 7 ;
bool V_735 = false ;
int V_73 ;
V_186 . V_683 = 0 ;
if ( ! V_701 ||
! V_733 ||
( F_375 ( & V_734 ) < 0 ) )
return;
switch ( V_702 ) {
case V_703 :
V_735 = ( V_733 > V_734 ) ;
break;
case V_705 :
case V_706 :
if ( V_733 != 7 &&
! ( V_733 & V_689 ) )
return;
else
V_735 = ! ( V_734 & V_689 ) &&
( V_734 != V_733 ) ;
break;
default:
return;
}
if ( V_735 ) {
F_32 ( L_376 ,
V_733 ) ;
V_73 = F_379 ( V_733 ) ;
if ( V_73 < 0 )
F_32 ( L_377 , V_73 ) ;
}
}
static int F_401 ( struct V_90 * V_91 )
{
int V_73 ;
T_6 V_30 ;
unsigned int V_697 = 0 ;
switch ( V_691 ) {
case V_692 :
V_73 = F_375 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_44
L_300 ,
( V_30 != 0 ) ? L_45 : L_46 , V_30 ) ;
break;
case V_694 :
V_73 = F_375 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_44 ,
( V_30 != 0 ) ? L_45 : L_46 ) ;
V_73 = F_376 ( & V_697 ) ;
if ( V_73 < 0 )
return V_73 ;
F_84 ( V_91 , L_378 , V_697 ) ;
if ( V_30 & V_689 )
F_84 ( V_91 , L_379 ) ;
else if ( V_30 & V_685 )
F_84 ( V_91 , L_380 ) ;
else
F_84 ( V_91 , L_300 , V_30 ) ;
break;
case V_717 :
default:
F_84 ( V_91 , L_43 ) ;
}
if ( V_718 & V_725 ) {
F_84 ( V_91 , L_381 ) ;
switch ( V_702 ) {
case V_703 :
F_84 ( V_91 , L_382 ) ;
break;
default:
F_84 ( V_91 , L_383 ) ;
break;
}
}
if ( V_718 & V_726 )
F_84 ( V_91 , L_47
L_384 ) ;
if ( V_718 & V_727 )
F_84 ( V_91 , L_385 ) ;
return 0 ;
}
static int F_402 ( const char * V_159 , int * V_73 )
{
int V_56 ;
if ( F_86 ( V_159 , L_386 ) == 0 )
V_56 = V_685 ;
else if ( ( F_86 ( V_159 , L_387 ) == 0 ) |
( F_86 ( V_159 , L_388 ) == 0 ) )
V_56 = V_689 ;
else if ( sscanf ( V_159 , L_305 , & V_56 ) != 1 )
return 0 ;
* V_73 = F_379 ( V_56 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_389 ,
V_702 ) ;
else if ( ! * V_73 )
F_82 ( L_390 ,
L_307 , V_56 ) ;
return 1 ;
}
static int F_403 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_48 ) != 0 )
return 0 ;
* V_73 = F_380 () ;
if ( * V_73 == - V_49 )
F_8 ( L_391 ,
V_702 ) ;
else if ( ! * V_73 )
F_82 ( L_390 , L_392 ) ;
return 1 ;
}
static int F_404 ( const char * V_159 , int * V_73 )
{
if ( F_86 ( V_159 , L_49 ) != 0 )
return 0 ;
* V_73 = F_381 () ;
if ( * V_73 == - V_49 )
F_8 ( L_393 ,
V_702 ) ;
else if ( ! * V_73 )
F_82 ( L_390 , L_394 ) ;
return 1 ;
}
static int F_405 ( const char * V_159 , int * V_73 )
{
int V_697 ;
if ( sscanf ( V_159 , L_395 , & V_697 ) != 1 )
return 0 ;
* V_73 = F_382 ( V_697 ) ;
if ( * V_73 == - V_49 )
F_8 ( L_396 ,
V_702 ) ;
else if ( ! * V_73 )
F_82 ( L_390 ,
L_397 , V_697 ) ;
return 1 ;
}
static int F_406 ( const char * V_159 , int * V_73 )
{
int V_736 ;
if ( sscanf ( V_159 , L_398 , & V_736 ) != 1 )
return 0 ;
if ( V_736 < 0 || V_736 > 120 )
* V_73 = - V_94 ;
else {
V_711 = V_736 ;
F_82 ( L_390 ,
L_399 ,
V_736 ) ;
}
return 1 ;
}
static int F_407 ( char * V_126 )
{
char * V_159 ;
int V_73 = 0 ;
while ( ! V_73 && ( V_159 = F_46 ( & V_126 ) ) ) {
if ( ! ( ( V_718 & V_725 ) &&
F_402 ( V_159 , & V_73 ) ) &&
! ( ( V_718 & V_726 ) &&
( F_403 ( V_159 , & V_73 ) ||
F_404 ( V_159 , & V_73 ) ||
F_406 ( V_159 , & V_73 ) ) ) &&
! ( ( V_718 & V_727 ) &&
F_405 ( V_159 , & V_73 ) )
)
V_73 = - V_94 ;
else if ( ! V_73 )
F_383 () ;
}
return V_73 ;
}
static int F_408 ( struct V_737 * V_157 , bool V_210 )
{
T_3 V_551 ;
int V_738 ;
if ( F_31 ( F_18 ( V_129 , V_157 -> V_51 , & V_551 ) ) ) {
F_62 ( L_400 , V_157 -> V_51 ) ;
return - V_50 ;
}
if ( ! F_7 ( V_129 , & V_738 , V_157 -> V_51 , L_6 ,
V_210 ? V_157 -> V_739 : V_157 -> V_740 ) )
return - V_50 ;
V_157 -> V_210 = V_210 ;
return V_210 ;
}
int F_409 ( int V_741 , bool V_742 )
{
struct V_737 * V_157 ;
if ( V_741 < 0 || V_741 >= V_743 )
return - V_94 ;
V_157 = & V_744 [ V_741 ] ;
if ( V_157 -> V_210 < 0 || V_157 -> V_210 == V_742 )
return V_157 -> V_210 ;
return F_408 ( V_157 , V_742 ) ;
}
static int F_410 ( struct V_315 * V_316 )
{
T_3 V_551 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_743 ; V_42 ++ ) {
struct V_737 * V_157 = & V_744 [ V_42 ] ;
if ( F_19 ( F_18 ( V_129 , V_157 -> V_51 , & V_551 ) ) )
F_408 ( V_157 , false ) ;
else
V_157 -> V_210 = - V_75 ;
}
return 0 ;
}
static void F_411 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_743 ; V_42 ++ )
F_409 ( V_42 , false ) ;
}
static void F_412 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_743 ; V_42 ++ ) {
struct V_737 * V_157 = & V_744 [ V_42 ] ;
if ( V_157 -> V_210 >= 0 )
F_408 ( V_157 , V_157 -> V_210 ) ;
}
}
static void F_413 ( const unsigned int V_745 )
{
if ( V_585 ) {
switch ( V_745 ) {
case V_746 :
case V_747 :
F_318 () ;
}
}
if ( V_630 ) {
switch ( V_745 ) {
case V_748 :
case V_749 :
case V_750 :
F_348 () ;
}
}
if ( V_186 . V_481 && V_745 == V_751 ) {
enum V_479 V_480 ;
F_115 ( & V_475 ) ;
V_480 = F_254 ( NULL ) ;
if ( V_476 != V_480 ) {
V_476 = V_480 ;
F_414 (
& V_482 . V_477 , V_480 ) ;
}
F_118 ( & V_475 ) ;
}
}
static void F_128 ( const unsigned int V_214 )
{
F_413 ( V_752 + V_214 ) ;
}
static T_8 F_415 ( struct V_74 * V_60 ,
struct V_156 * V_122 ,
char * V_126 )
{
return snprintf ( V_126 , V_102 , L_401 , V_85 ) ;
}
static const char * T_1 F_1 ( int V_1 )
{
static char V_753 [] V_754 = L_402 ;
return ( V_1 ) ? & V_753 [ 4 ] : & V_753 [ 0 ] ;
}
static void F_416 ( struct V_67 * V_68 )
{
F_20 ( V_310 , L_403 , V_68 -> V_51 ) ;
F_417 ( & V_68 -> V_755 ) ;
if ( V_68 -> V_79 . V_80 ) {
F_20 ( V_310 ,
L_404 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_418 ( * V_68 -> V_71 -> V_16 ,
V_68 -> V_71 -> type ,
F_27 ) ;
V_68 -> V_79 . V_80 = 0 ;
}
if ( V_68 -> V_79 . V_756 ) {
F_20 ( V_310 ,
L_405 , V_68 -> V_51 ) ;
F_419 ( V_68 -> V_51 , V_757 ) ;
V_68 -> V_79 . V_756 = 0 ;
}
if ( V_68 -> V_79 . V_89 ) {
F_20 ( V_310 ,
L_406 , V_68 -> V_51 ) ;
F_25 ( ! V_68 -> V_71 ) ;
F_420 ( V_68 -> V_71 -> V_81 ) ;
F_37 ( V_68 -> V_71 -> V_81 ) ;
V_68 -> V_71 -> V_81 = NULL ;
V_68 -> V_79 . V_89 = 0 ;
}
if ( V_68 -> V_79 . V_758 && V_68 -> exit ) {
V_68 -> exit () ;
V_68 -> V_79 . V_758 = 0 ;
}
F_20 ( V_55 , L_407 , V_68 -> V_51 ) ;
}
static int T_1 F_421 ( struct V_315 * V_316 )
{
int V_100 ;
struct V_67 * V_68 = V_316 -> V_66 ;
struct V_759 * V_760 ;
F_25 ( V_68 == NULL ) ;
F_422 ( & V_68 -> V_755 ) ;
if ( V_68 -> V_79 . V_761 && ! V_761 )
return 0 ;
F_20 ( V_55 ,
L_408 , V_68 -> V_51 ) ;
if ( V_316 -> V_762 ) {
V_100 = V_316 -> V_762 ( V_316 ) ;
if ( V_100 > 0 )
return 0 ;
if ( V_100 )
return V_100 ;
V_68 -> V_79 . V_758 = 1 ;
}
if ( V_68 -> V_71 ) {
if ( V_68 -> V_71 -> V_63 ) {
V_100 = F_34 ( V_68 ) ;
if ( V_100 )
goto V_763;
}
if ( V_68 -> V_71 -> V_72 ) {
V_100 = F_28 ( V_68 ) ;
if ( V_100 == - V_75 ) {
F_32 ( L_409 ,
V_68 -> V_51 ) ;
V_100 = 0 ;
goto V_763;
}
if ( V_100 < 0 )
goto V_763;
}
}
F_20 ( V_55 ,
L_410 , V_68 -> V_51 ) ;
if ( V_68 -> V_93 ) {
T_19 V_374 = V_316 -> V_764 ;
if ( ! V_374 )
V_374 = V_765 ;
if ( V_68 -> V_101 )
V_374 |= V_766 ;
V_760 = F_423 ( V_68 -> V_51 , V_374 , V_757 ,
& V_767 , V_68 ) ;
if ( ! V_760 ) {
F_8 ( L_411 , V_68 -> V_51 ) ;
V_100 = - V_75 ;
goto V_763;
}
V_68 -> V_79 . V_756 = 1 ;
}
F_424 ( & V_68 -> V_755 , & V_768 ) ;
return 0 ;
V_763:
F_20 ( V_55 ,
L_412 ,
V_68 -> V_51 , V_100 ) ;
F_416 ( V_68 ) ;
return ( V_100 < 0 ) ? V_100 : 0 ;
}
static bool T_2 T_1 F_425 ( const char V_37 )
{
return ( V_37 >= '0' && V_37 <= '9' ) || ( V_37 >= 'A' && V_37 <= 'Z' ) ;
}
static bool T_2 T_1 F_426 ( const char * const V_118 ,
const char V_157 )
{
if ( V_118 && strlen ( V_118 ) >= 8 &&
F_425 ( V_118 [ 0 ] ) &&
F_425 ( V_118 [ 1 ] ) &&
V_118 [ 2 ] == V_157 &&
( V_118 [ 3 ] == 'T' || V_118 [ 3 ] == 'N' ) &&
F_425 ( V_118 [ 4 ] ) &&
F_425 ( V_118 [ 5 ] ) )
return true ;
return V_118 && strlen ( V_118 ) >= 8 &&
F_425 ( V_118 [ 0 ] ) &&
F_425 ( V_118 [ 1 ] ) &&
F_425 ( V_118 [ 2 ] ) &&
V_118 [ 3 ] == V_157 &&
( V_118 [ 4 ] == 'T' || V_118 [ 4 ] == 'N' ) &&
F_425 ( V_118 [ 5 ] ) &&
F_425 ( V_118 [ 6 ] ) ;
}
static int T_20 T_1 F_427 (
struct V_769 * V_770 )
{
const struct V_771 * V_60 = NULL ;
char V_772 [ 18 ] ;
char const * V_118 ;
if ( ! V_770 )
return - V_94 ;
memset ( V_770 , 0 , sizeof( * V_770 ) ) ;
if ( F_428 ( L_413 ) )
V_770 -> V_6 = V_15 ;
else if ( F_428 ( L_414 ) )
V_770 -> V_6 = V_14 ;
else
return 0 ;
V_118 = F_429 ( V_773 ) ;
V_770 -> V_774 = F_430 ( V_118 , V_83 ) ;
if ( V_118 && ! V_770 -> V_774 )
return - V_84 ;
if ( ! ( F_426 ( V_770 -> V_774 , 'E' ) ||
F_426 ( V_770 -> V_774 , 'C' ) ) )
return 0 ;
V_770 -> V_10 = V_770 -> V_774 [ 0 ]
| ( V_770 -> V_774 [ 1 ] << 8 ) ;
V_770 -> V_184 = ( V_770 -> V_774 [ 4 ] << 8 )
| V_770 -> V_774 [ 5 ] ;
while ( ( V_60 = F_431 ( V_775 , NULL , V_60 ) ) ) {
if ( sscanf ( V_60 -> V_51 ,
L_415 ,
V_772 ) == 1 ) {
V_772 [ sizeof( V_772 ) - 1 ] = 0 ;
V_772 [ strcspn ( V_772 , L_416 ) ] = 0 ;
V_770 -> V_654 = F_430 ( V_772 , V_83 ) ;
if ( ! V_770 -> V_654 )
return - V_84 ;
if ( F_426 ( V_772 , 'H' ) ) {
V_770 -> V_12 = V_772 [ 0 ]
| ( V_772 [ 1 ] << 8 ) ;
V_770 -> V_185 = ( V_772 [ 4 ] << 8 )
| V_772 [ 5 ] ;
} else {
F_32 ( L_417 ,
V_772 ) ;
F_32 ( L_103 ,
V_362 ) ;
}
break;
}
}
V_118 = F_429 ( V_776 ) ;
if ( V_118 && ! ( strncasecmp ( V_118 , L_418 , 8 ) && strncasecmp ( V_118 , L_419 , 6 ) ) ) {
V_770 -> V_777 = F_430 ( V_118 , V_83 ) ;
if ( ! V_770 -> V_777 )
return - V_84 ;
} else {
V_118 = F_429 ( V_778 ) ;
if ( V_118 && ! ( strncasecmp ( V_118 , L_419 , 6 ) ) ) {
V_770 -> V_777 = F_430 ( V_118 , V_83 ) ;
if ( ! V_770 -> V_777 )
return - V_84 ;
}
}
V_118 = F_429 ( V_779 ) ;
V_770 -> V_780 = F_430 ( V_118 , V_83 ) ;
if ( V_118 && ! V_770 -> V_780 )
return - V_84 ;
return 0 ;
}
static int T_1 F_432 ( void )
{
int V_781 ;
if ( V_782 )
return - V_75 ;
if ( ! F_6 () && ! F_5 () )
return - V_75 ;
V_781 = ( V_7 . V_777 != NULL ) ||
( V_7 . V_12 != 0 ) ||
F_107 () ;
F_24 ( L_420 , V_783 , & V_192 ) ;
if ( ! V_192 ) {
if ( V_781 )
F_8 ( L_421 ) ;
return - V_75 ;
}
if ( ! V_781 && ! V_784 )
return - V_75 ;
return 0 ;
}
static void T_1 F_433 ( void )
{
F_76 ( L_54 , V_165 , V_166 ) ;
F_76 ( L_401 , V_785 ) ;
F_76 ( L_422 ,
( V_7 . V_774 ) ?
V_7 . V_774 : L_330 ,
( V_7 . V_654 ) ?
V_7 . V_654 : L_330 ) ;
F_25 ( ! V_7 . V_6 ) ;
if ( V_7 . V_777 )
F_76 ( L_423 ,
( V_7 . V_6 == V_15 ) ?
L_413 : ( ( V_7 . V_6 ==
V_14 ) ?
L_419 : L_424 ) ,
V_7 . V_777 ,
( V_7 . V_780 ) ?
V_7 . V_780 : L_330 ) ;
}
static int T_1 F_434 ( const char * V_687 , struct V_786 * V_787 )
{
unsigned int V_42 ;
struct V_67 * V_68 ;
if ( ! V_787 || ! V_787 -> V_51 || ! V_687 )
return - V_94 ;
for ( V_42 = 0 ; V_42 < F_100 ( V_788 ) ; V_42 ++ ) {
V_68 = V_788 [ V_42 ] . V_66 ;
F_435 ( V_68 == NULL ) ;
if ( ! V_68 || ! V_68 -> V_51 )
continue;
if ( strcmp ( V_68 -> V_51 , V_787 -> V_51 ) == 0 && V_68 -> V_101 ) {
if ( strlen ( V_687 ) > sizeof( V_788 [ V_42 ] . V_789 ) - 2 )
return - V_790 ;
strcpy ( V_788 [ V_42 ] . V_789 , V_687 ) ;
strcat ( V_788 [ V_42 ] . V_789 , L_26 ) ;
return 0 ;
}
}
return - V_94 ;
}
static void F_436 ( void )
{
struct V_67 * V_68 , * V_107 ;
V_69 = V_204 ;
F_437 (ibm, itmp,
&tpacpi_all_drivers,
all_drivers) {
F_416 ( V_68 ) ;
}
F_20 ( V_55 , L_425 ) ;
if ( V_212 ) {
if ( V_186 . V_791 )
F_438 ( V_212 ) ;
else
F_439 ( V_212 ) ;
F_37 ( V_216 ) ;
}
if ( V_792 )
F_440 ( V_792 ) ;
if ( V_186 . V_793 )
F_280 ( & V_559 -> V_60 , & V_794 ) ;
if ( V_559 )
F_441 ( V_559 ) ;
if ( V_154 )
F_441 ( V_154 ) ;
if ( V_186 . V_795 )
F_103 ( & V_731 . V_81 ) ;
if ( V_186 . V_796 )
F_103 ( & V_797 . V_81 ) ;
if ( V_186 . V_798 )
F_442 ( & V_731 ) ;
if ( V_186 . V_799 )
F_442 ( & V_797 ) ;
if ( V_757 )
F_419 ( V_800 , V_801 ) ;
if ( V_712 )
F_443 ( V_712 ) ;
F_37 ( V_7 . V_774 ) ;
F_37 ( V_7 . V_654 ) ;
F_37 ( V_7 . V_777 ) ;
F_37 ( V_7 . V_780 ) ;
}
static int T_1 F_444 ( void )
{
int V_100 , V_42 ;
V_69 = V_296 ;
V_100 = F_427 ( & V_7 ) ;
if ( V_100 ) {
F_8 ( L_426 , V_100 ) ;
F_436 () ;
return V_100 ;
}
V_100 = F_432 () ;
if ( V_100 ) {
F_436 () ;
return V_100 ;
}
F_433 () ;
F_106 () ;
F_188 ( V_802 ) ;
F_188 ( V_803 ) ;
V_712 = F_445 ( V_804 ) ;
if ( ! V_712 ) {
F_436 () ;
return - V_84 ;
}
V_757 = F_446 ( V_800 , V_801 ) ;
if ( ! V_757 ) {
F_8 ( L_427 V_800 L_269 ) ;
F_436 () ;
return - V_75 ;
}
V_100 = F_447 ( & V_797 ) ;
if ( V_100 ) {
F_8 ( L_428 ) ;
F_436 () ;
return V_100 ;
}
V_186 . V_799 = 1 ;
V_100 = F_447 ( & V_731 ) ;
if ( V_100 ) {
F_8 ( L_429 ) ;
F_436 () ;
return V_100 ;
}
V_186 . V_798 = 1 ;
V_100 = F_99 ( & V_797 . V_81 ) ;
if ( ! V_100 ) {
V_186 . V_796 = 1 ;
V_100 = F_99 (
& V_731 . V_81 ) ;
}
if ( V_100 ) {
F_8 ( L_430 ) ;
F_436 () ;
return V_100 ;
}
V_186 . V_795 = 1 ;
V_154 = F_448 ( V_805 , - 1 ,
NULL , 0 ) ;
if ( F_147 ( V_154 ) ) {
V_100 = F_327 ( V_154 ) ;
V_154 = NULL ;
F_8 ( L_431 ) ;
F_436 () ;
return V_100 ;
}
V_559 = F_448 (
V_806 ,
- 1 , NULL , 0 ) ;
if ( F_147 ( V_559 ) ) {
V_100 = F_327 ( V_559 ) ;
V_559 = NULL ;
F_8 ( L_432 ) ;
F_436 () ;
return V_100 ;
}
V_100 = F_278 ( & V_559 -> V_60 , & V_794 ) ;
if ( V_100 ) {
F_8 ( L_433 ) ;
F_436 () ;
return V_100 ;
}
V_186 . V_793 = 1 ;
V_792 = F_449 ( & V_559 -> V_60 ) ;
if ( F_147 ( V_792 ) ) {
V_100 = F_327 ( V_792 ) ;
V_792 = NULL ;
F_8 ( L_434 ) ;
F_436 () ;
return V_100 ;
}
F_189 ( & V_211 ) ;
V_212 = F_450 () ;
if ( ! V_212 ) {
F_436 () ;
return - V_84 ;
} else {
V_212 -> V_51 = L_435 ;
V_212 -> V_807 = V_805 L_436 ;
V_212 -> V_144 . V_808 = V_809 ;
V_212 -> V_144 . V_6 = V_7 . V_6 ;
V_212 -> V_144 . V_810 = V_811 ;
V_212 -> V_144 . V_812 = V_813 ;
V_212 -> V_60 . V_52 = & V_154 -> V_60 ;
}
F_323 () ;
for ( V_42 = 0 ; V_42 < F_100 ( V_788 ) ; V_42 ++ ) {
V_100 = F_421 ( & V_788 [ V_42 ] ) ;
if ( V_100 >= 0 && * V_788 [ V_42 ] . V_789 )
V_100 = V_788 [ V_42 ] . V_66 -> V_101 ( V_788 [ V_42 ] . V_789 ) ;
if ( V_100 < 0 ) {
F_436 () ;
return V_100 ;
}
}
V_69 = V_70 ;
V_100 = F_451 ( V_212 ) ;
if ( V_100 < 0 ) {
F_8 ( L_437 ) ;
F_436 () ;
return V_100 ;
} else {
V_186 . V_791 = 1 ;
}
return 0 ;
}
