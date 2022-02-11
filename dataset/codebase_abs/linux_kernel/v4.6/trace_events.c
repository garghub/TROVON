static inline int F_1 ( struct V_1 * system )
{
return system -> V_2 ;
}
static int F_2 ( struct V_1 * system )
{
return system -> V_2 ++ ;
}
static int F_3 ( struct V_1 * system )
{
return -- system -> V_2 ;
}
static struct V_3 *
F_4 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_6 -> V_7 )
return & V_5 -> V_6 -> V_8 ;
return V_5 -> V_6 -> V_7 ( V_5 ) ;
}
static struct V_9 *
F_5 ( struct V_3 * V_10 , char * V_11 )
{
struct V_9 * V_12 ;
F_6 (field, head, link) {
if ( ! strcmp ( V_12 -> V_11 , V_11 ) )
return V_12 ;
}
return NULL ;
}
struct V_9 *
F_7 ( struct V_4 * V_13 , char * V_11 )
{
struct V_9 * V_12 ;
struct V_3 * V_10 ;
V_10 = F_4 ( V_13 ) ;
V_12 = F_5 ( V_10 , V_11 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_5 ( & V_14 , V_11 ) ;
if ( V_12 )
return V_12 ;
return F_5 ( & V_15 , V_11 ) ;
}
static int F_8 ( struct V_3 * V_10 , const char * type ,
const char * V_11 , int V_16 , int V_17 ,
int V_18 , int V_19 )
{
struct V_9 * V_12 ;
V_12 = F_9 ( V_20 , V_21 ) ;
if ( ! V_12 )
return - V_22 ;
V_12 -> V_11 = V_11 ;
V_12 -> type = type ;
if ( V_19 == V_23 )
V_12 -> V_19 = F_10 ( type ) ;
else
V_12 -> V_19 = V_19 ;
V_12 -> V_16 = V_16 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_18 = V_18 ;
F_11 ( & V_12 -> V_24 , V_10 ) ;
return 0 ;
}
int F_12 ( struct V_4 * V_13 , const char * type ,
const char * V_11 , int V_16 , int V_17 , int V_18 ,
int V_19 )
{
struct V_3 * V_10 ;
if ( F_13 ( ! V_13 -> V_6 ) )
return 0 ;
V_10 = F_4 ( V_13 ) ;
return F_8 ( V_10 , type , V_11 , V_16 , V_17 ,
V_18 , V_19 ) ;
}
static int F_14 ( void )
{
int V_25 ;
F_15 ( int , V_26 , V_27 ) ;
F_15 ( int , V_28 , V_27 ) ;
F_15 ( char * , V_29 , V_30 ) ;
F_15 ( char * , V_31 , V_30 ) ;
return V_25 ;
}
static int F_16 ( void )
{
int V_25 ;
struct V_32 V_33 ;
F_17 (unsigned short, type) ;
F_17 (unsigned char, flags) ;
F_17 (unsigned char, preempt_count) ;
F_17 ( int , V_34 ) ;
return V_25 ;
}
static void F_18 ( struct V_4 * V_13 )
{
struct V_9 * V_12 , * V_35 ;
struct V_3 * V_10 ;
V_10 = F_4 ( V_13 ) ;
F_19 (field, next, head, link) {
F_20 ( & V_12 -> V_24 ) ;
F_21 ( V_20 , V_12 ) ;
}
}
int F_22 ( struct V_4 * V_13 )
{
int V_36 ;
V_36 = F_23 ( & V_13 -> V_37 ) ;
if ( ! V_36 )
return - V_38 ;
return 0 ;
}
bool F_24 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
V_46 = F_25 ( V_42 -> V_47 ) ;
if ( ! V_46 )
return false ;
V_44 = F_26 ( V_42 -> V_48 . V_44 ) ;
return V_44 -> V_49 ;
}
void * F_27 ( struct V_50 * V_51 ,
struct V_39 * V_40 ,
unsigned long V_52 )
{
struct V_4 * V_5 = V_40 -> V_5 ;
if ( ( V_40 -> V_53 & V_54 ) &&
F_24 ( V_40 ) )
return NULL ;
F_28 ( V_51 -> V_53 ) ;
V_51 -> V_55 = F_29 () ;
V_51 -> V_40 = V_40 ;
V_51 -> V_37 =
F_30 ( & V_51 -> V_56 , V_40 ,
V_5 -> V_37 . type , V_52 ,
V_51 -> V_53 , V_51 -> V_55 ) ;
if ( ! V_51 -> V_37 )
return NULL ;
V_51 -> V_57 = F_31 ( V_51 -> V_37 ) ;
return V_51 -> V_57 ;
}
static void F_32 ( struct V_50 * V_51 )
{
struct V_4 * V_5 ;
struct V_58 * V_37 ;
unsigned long V_53 ;
struct V_59 * V_60 = V_61 ;
if ( ! V_60 )
return;
V_5 = V_51 -> V_40 -> V_5 ;
if ( ! V_5 || ! V_5 -> V_37 . V_62 ||
! V_5 -> V_37 . V_62 -> V_63 )
return;
V_37 = & V_51 -> V_40 -> V_5 -> V_37 ;
F_33 ( & V_64 , V_53 ) ;
F_34 ( & V_60 -> V_65 ) ;
V_60 -> V_33 = V_51 -> V_57 ;
V_5 -> V_37 . V_62 -> V_63 ( V_60 , 0 , V_37 ) ;
F_35 ( & V_60 -> V_65 , 0 ) ;
F_36 ( L_1 , V_60 -> V_65 . V_56 ) ;
F_37 ( & V_64 , V_53 ) ;
}
void F_38 ( struct V_50 * V_51 )
{
if ( V_66 )
F_32 ( V_51 ) ;
F_39 ( V_51 -> V_40 , V_51 -> V_56 ,
V_51 -> V_37 , V_51 -> V_57 ,
V_51 -> V_53 , V_51 -> V_55 ) ;
}
int F_40 ( struct V_4 * V_13 ,
enum V_67 type , void * V_44 )
{
struct V_39 * V_68 = V_44 ;
F_13 ( ! ( V_13 -> V_53 & V_69 ) ) ;
switch ( type ) {
case V_70 :
return F_41 ( V_13 -> V_71 ,
V_13 -> V_6 -> V_72 ,
V_68 ) ;
case V_73 :
F_42 ( V_13 -> V_71 ,
V_13 -> V_6 -> V_72 ,
V_68 ) ;
return 0 ;
#ifdef F_43
case V_74 :
return F_41 ( V_13 -> V_71 ,
V_13 -> V_6 -> V_75 ,
V_13 ) ;
case V_76 :
F_42 ( V_13 -> V_71 ,
V_13 -> V_6 -> V_75 ,
V_13 ) ;
return 0 ;
case V_77 :
case V_78 :
case V_79 :
case V_80 :
return 0 ;
#endif
}
return 0 ;
}
void F_44 ( bool V_81 )
{
struct V_39 * V_68 ;
struct V_41 * V_42 ;
F_45 ( & V_82 ) ;
F_46 (tr, file) {
if ( ! ( V_68 -> V_53 & V_83 ) )
continue;
if ( V_81 ) {
F_47 () ;
F_48 ( V_84 , & V_68 -> V_53 ) ;
} else {
F_49 () ;
F_50 ( V_84 , & V_68 -> V_53 ) ;
}
} F_51 () ;
F_52 ( & V_82 ) ;
}
static int F_53 ( struct V_39 * V_68 ,
int V_81 , int V_85 )
{
struct V_4 * V_13 = V_68 -> V_5 ;
struct V_41 * V_42 = V_68 -> V_42 ;
int V_25 = 0 ;
int V_86 ;
switch ( V_81 ) {
case 0 :
if ( V_85 ) {
if ( F_54 ( & V_68 -> V_87 ) > 0 )
break;
V_86 = V_68 -> V_53 & V_88 ;
F_50 ( V_89 , & V_68 -> V_53 ) ;
} else
V_86 = ! ( V_68 -> V_53 & V_90 ) ;
if ( V_86 && ( V_68 -> V_53 & V_83 ) ) {
F_50 ( V_91 , & V_68 -> V_53 ) ;
if ( V_68 -> V_53 & V_92 ) {
F_49 () ;
F_50 ( V_84 , & V_68 -> V_53 ) ;
}
V_13 -> V_6 -> V_93 ( V_13 , V_73 , V_68 ) ;
}
if ( V_68 -> V_53 & V_90 )
F_48 ( V_94 , & V_68 -> V_53 ) ;
else
F_50 ( V_94 , & V_68 -> V_53 ) ;
break;
case 1 :
if ( ! V_85 )
F_50 ( V_94 , & V_68 -> V_53 ) ;
else {
if ( F_55 ( & V_68 -> V_87 ) > 1 )
break;
F_48 ( V_89 , & V_68 -> V_53 ) ;
}
if ( ! ( V_68 -> V_53 & V_83 ) ) {
if ( V_85 )
F_48 ( V_94 , & V_68 -> V_53 ) ;
if ( V_42 -> V_95 & V_96 ) {
F_47 () ;
F_48 ( V_84 , & V_68 -> V_53 ) ;
}
V_25 = V_13 -> V_6 -> V_93 ( V_13 , V_70 , V_68 ) ;
if ( V_25 ) {
F_49 () ;
F_56 ( L_2
L_3 , F_57 ( V_13 ) ) ;
break;
}
F_48 ( V_91 , & V_68 -> V_53 ) ;
V_13 -> V_53 |= V_97 ;
}
break;
}
return V_25 ;
}
int F_58 ( struct V_39 * V_68 ,
int V_81 , int V_85 )
{
return F_53 ( V_68 , V_81 , V_85 ) ;
}
static int F_59 ( struct V_39 * V_68 ,
int V_81 )
{
return F_53 ( V_68 , V_81 , 0 ) ;
}
static void F_60 ( struct V_41 * V_42 )
{
struct V_39 * V_68 ;
F_45 ( & V_82 ) ;
F_6 (file, &tr->events, list) {
F_59 ( V_68 , 0 ) ;
}
F_52 ( & V_82 ) ;
}
static int F_61 ( const void * V_98 , const void * V_99 )
{
const T_1 * V_100 = V_98 ;
const T_1 * V_34 = V_99 ;
if ( * V_100 == * V_34 )
return 0 ;
if ( * V_100 < * V_34 )
return - 1 ;
return 1 ;
}
static bool
F_62 ( struct V_45 * V_47 , struct V_101 * V_102 )
{
T_1 V_100 ;
T_1 * V_34 ;
if ( ! V_47 )
return false ;
V_100 = V_102 -> V_34 ;
V_34 = bsearch ( & V_100 , V_47 -> V_103 ,
V_47 -> V_104 , sizeof( T_1 ) ,
F_61 ) ;
if ( ! V_34 )
return true ;
return false ;
}
static void
F_63 ( void * V_44 , bool V_105 ,
struct V_101 * V_106 , struct V_101 * V_35 )
{
struct V_41 * V_42 = V_44 ;
struct V_45 * V_46 ;
V_46 = F_25 ( V_42 -> V_47 ) ;
F_64 ( V_42 -> V_48 . V_44 -> V_49 ,
F_62 ( V_46 , V_106 ) &&
F_62 ( V_46 , V_35 ) ) ;
}
static void
F_65 ( void * V_44 , bool V_105 ,
struct V_101 * V_106 , struct V_101 * V_35 )
{
struct V_41 * V_42 = V_44 ;
struct V_45 * V_46 ;
V_46 = F_25 ( V_42 -> V_47 ) ;
F_64 ( V_42 -> V_48 . V_44 -> V_49 ,
F_62 ( V_46 , V_35 ) ) ;
}
static void
F_66 ( void * V_44 , struct V_101 * V_102 )
{
struct V_41 * V_42 = V_44 ;
struct V_45 * V_46 ;
if ( ! F_67 ( V_42 -> V_48 . V_44 -> V_49 ) )
return;
V_46 = F_25 ( V_42 -> V_47 ) ;
F_64 ( V_42 -> V_48 . V_44 -> V_49 ,
F_62 ( V_46 , V_102 ) ) ;
}
static void
F_68 ( void * V_44 , struct V_101 * V_102 )
{
struct V_41 * V_42 = V_44 ;
struct V_45 * V_46 ;
if ( F_67 ( V_42 -> V_48 . V_44 -> V_49 ) )
return;
V_46 = F_25 ( V_42 -> V_47 ) ;
F_64 ( V_42 -> V_48 . V_44 -> V_49 ,
F_62 ( V_46 , V_107 ) ) ;
}
static void F_69 ( struct V_41 * V_42 )
{
struct V_45 * V_46 ;
struct V_39 * V_68 ;
int V_28 ;
V_46 = F_70 ( V_42 -> V_47 ,
F_71 ( & V_82 ) ) ;
if ( ! V_46 )
return;
F_72 ( F_63 , V_42 ) ;
F_72 ( F_65 , V_42 ) ;
F_73 ( F_66 , V_42 ) ;
F_73 ( F_68 , V_42 ) ;
F_74 ( F_66 , V_42 ) ;
F_74 ( F_68 , V_42 ) ;
F_75 ( F_66 , V_42 ) ;
F_75 ( F_68 , V_42 ) ;
F_6 (file, &tr->events, list) {
F_50 ( V_108 , & V_68 -> V_53 ) ;
}
F_76 (cpu)
F_77 ( V_42 -> V_48 . V_44 , V_28 ) -> V_49 = false ;
F_78 ( V_42 -> V_47 , NULL ) ;
F_79 () ;
F_80 ( ( unsigned long ) V_46 -> V_103 , V_46 -> V_109 ) ;
F_81 ( V_46 ) ;
}
static void F_82 ( struct V_41 * V_42 )
{
F_45 ( & V_82 ) ;
F_69 ( V_42 ) ;
F_52 ( & V_82 ) ;
}
static void F_83 ( struct V_1 * system )
{
struct V_110 * V_111 = system -> V_111 ;
F_84 ( F_1 ( system ) == 0 ) ;
if ( F_3 ( system ) )
return;
F_20 ( & system -> V_112 ) ;
if ( V_111 ) {
F_81 ( V_111 -> V_113 ) ;
F_81 ( V_111 ) ;
}
F_85 ( system -> V_11 ) ;
F_81 ( system ) ;
}
static void F_86 ( struct V_1 * system )
{
F_84 ( F_1 ( system ) == 0 ) ;
F_2 ( system ) ;
}
static void F_87 ( struct V_114 * V_115 )
{
F_84 ( V_115 -> V_2 == 0 ) ;
V_115 -> V_2 ++ ;
F_86 ( V_115 -> V_116 ) ;
}
static void F_88 ( struct V_114 * V_115 )
{
F_84 ( V_115 -> V_2 == 0 ) ;
F_84 ( F_1 ( V_115 -> V_116 ) == 1 && V_115 -> V_2 != 1 ) ;
F_83 ( V_115 -> V_116 ) ;
if ( ! -- V_115 -> V_2 )
F_81 ( V_115 ) ;
}
static void F_89 ( struct V_114 * V_115 )
{
F_45 ( & V_82 ) ;
F_88 ( V_115 ) ;
F_52 ( & V_82 ) ;
}
static void F_90 ( struct V_114 * V_115 )
{
if ( ! V_115 )
return;
if ( ! -- V_115 -> V_117 ) {
F_91 ( V_115 -> V_57 ) ;
F_20 ( & V_115 -> V_112 ) ;
F_88 ( V_115 ) ;
}
}
static void F_92 ( struct V_39 * V_68 )
{
struct V_118 * V_115 = V_68 -> V_115 ;
struct V_118 * V_119 ;
if ( V_115 ) {
F_93 ( & V_115 -> V_120 ) ;
F_6 (child, &dir->d_subdirs, d_child) {
if ( F_94 ( V_119 ) )
F_95 ( V_119 ) -> V_121 = NULL ;
}
F_96 ( & V_115 -> V_120 ) ;
F_91 ( V_115 ) ;
}
F_20 ( & V_68 -> V_112 ) ;
F_90 ( V_68 -> system ) ;
F_97 ( V_68 -> V_111 ) ;
F_21 ( V_122 , V_68 ) ;
}
static int
F_98 ( struct V_41 * V_42 , const char * V_123 ,
const char * V_124 , const char * V_37 , int V_125 )
{
struct V_39 * V_68 ;
struct V_4 * V_13 ;
const char * V_11 ;
int V_25 = - V_126 ;
F_6 (file, &tr->events, list) {
V_13 = V_68 -> V_5 ;
V_11 = F_57 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_93 )
continue;
if ( V_13 -> V_53 & V_127 )
continue;
if ( V_123 &&
strcmp ( V_123 , V_11 ) != 0 &&
strcmp ( V_123 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_124 && strcmp ( V_124 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_37 && strcmp ( V_37 , V_11 ) != 0 )
continue;
F_59 ( V_68 , V_125 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static int F_99 ( struct V_41 * V_42 , const char * V_123 ,
const char * V_124 , const char * V_37 , int V_125 )
{
int V_25 ;
F_45 ( & V_82 ) ;
V_25 = F_98 ( V_42 , V_123 , V_124 , V_37 , V_125 ) ;
F_52 ( & V_82 ) ;
return V_25 ;
}
static int F_100 ( struct V_41 * V_42 , char * V_128 , int V_125 )
{
char * V_37 = NULL , * V_124 = NULL , * V_123 ;
int V_25 ;
V_123 = F_101 ( & V_128 , L_4 ) ;
if ( V_128 ) {
V_124 = V_123 ;
V_37 = V_128 ;
V_123 = NULL ;
if ( ! strlen ( V_124 ) || strcmp ( V_124 , L_5 ) == 0 )
V_124 = NULL ;
if ( ! strlen ( V_37 ) || strcmp ( V_37 , L_5 ) == 0 )
V_37 = NULL ;
}
V_25 = F_99 ( V_42 , V_123 , V_124 , V_37 , V_125 ) ;
if ( V_128 )
* ( V_128 - 1 ) = ':' ;
return V_25 ;
}
int F_102 ( const char * system , const char * V_37 , int V_125 )
{
struct V_41 * V_42 = F_103 () ;
if ( ! V_42 )
return - V_38 ;
return F_99 ( V_42 , NULL , system , V_37 , V_125 ) ;
}
static T_2
F_104 ( struct V_68 * V_68 , const char T_3 * V_129 ,
T_4 V_130 , T_5 * V_131 )
{
struct V_132 V_133 ;
struct V_134 * V_135 = V_68 -> V_136 ;
struct V_41 * V_42 = V_135 -> V_137 ;
T_2 V_138 , V_25 ;
if ( ! V_130 )
return 0 ;
V_25 = F_105 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_106 ( & V_133 , V_139 + 1 ) )
return - V_22 ;
V_138 = F_107 ( & V_133 , V_129 , V_130 , V_131 ) ;
if ( V_138 >= 0 && F_108 ( ( & V_133 ) ) ) {
int V_125 = 1 ;
if ( * V_133 . V_56 == '!' )
V_125 = 0 ;
V_133 . V_56 [ V_133 . V_140 ] = 0 ;
V_25 = F_100 ( V_42 , V_133 . V_56 + ! V_125 , V_125 ) ;
if ( V_25 )
goto V_141;
}
V_25 = V_138 ;
V_141:
F_109 ( & V_133 ) ;
return V_25 ;
}
static void *
F_110 ( struct V_134 * V_135 , void * V_142 , T_5 * V_143 )
{
struct V_39 * V_68 = V_142 ;
struct V_4 * V_13 ;
struct V_41 * V_42 = V_135 -> V_137 ;
( * V_143 ) ++ ;
F_111 (file, &tr->events, list) {
V_13 = V_68 -> V_5 ;
if ( V_13 -> V_6 && V_13 -> V_6 -> V_93 &&
! ( V_13 -> V_53 & V_127 ) )
return V_68 ;
}
return NULL ;
}
static void * F_112 ( struct V_134 * V_135 , T_5 * V_143 )
{
struct V_39 * V_68 ;
struct V_41 * V_42 = V_135 -> V_137 ;
T_5 V_144 ;
F_45 ( & V_82 ) ;
V_68 = F_113 ( & V_42 -> V_145 , struct V_39 , V_112 ) ;
for ( V_144 = 0 ; V_144 <= * V_143 ; ) {
V_68 = F_110 ( V_135 , V_68 , & V_144 ) ;
if ( ! V_68 )
break;
}
return V_68 ;
}
static void *
F_114 ( struct V_134 * V_135 , void * V_142 , T_5 * V_143 )
{
struct V_39 * V_68 = V_142 ;
struct V_41 * V_42 = V_135 -> V_137 ;
( * V_143 ) ++ ;
F_111 (file, &tr->events, list) {
if ( V_68 -> V_53 & V_83 )
return V_68 ;
}
return NULL ;
}
static void * F_115 ( struct V_134 * V_135 , T_5 * V_143 )
{
struct V_39 * V_68 ;
struct V_41 * V_42 = V_135 -> V_137 ;
T_5 V_144 ;
F_45 ( & V_82 ) ;
V_68 = F_113 ( & V_42 -> V_145 , struct V_39 , V_112 ) ;
for ( V_144 = 0 ; V_144 <= * V_143 ; ) {
V_68 = F_114 ( V_135 , V_68 , & V_144 ) ;
if ( ! V_68 )
break;
}
return V_68 ;
}
static int F_116 ( struct V_134 * V_135 , void * V_142 )
{
struct V_39 * V_68 = V_142 ;
struct V_4 * V_13 = V_68 -> V_5 ;
if ( strcmp ( V_13 -> V_6 -> system , V_146 ) != 0 )
F_117 ( V_135 , L_6 , V_13 -> V_6 -> system ) ;
F_117 ( V_135 , L_3 , F_57 ( V_13 ) ) ;
return 0 ;
}
static void F_118 ( struct V_134 * V_135 , void * V_147 )
{
F_52 ( & V_82 ) ;
}
static void * F_119 ( struct V_134 * V_135 , T_5 * V_143 )
__acquires( T_6 )
{
struct V_45 * V_46 ;
struct V_41 * V_42 = V_135 -> V_137 ;
F_45 ( & V_82 ) ;
F_120 () ;
V_46 = F_25 ( V_42 -> V_47 ) ;
if ( ! V_46 || * V_143 >= V_46 -> V_104 )
return NULL ;
return ( void * ) & V_46 -> V_103 [ * V_143 ] ;
}
static void F_121 ( struct V_134 * V_135 , void * V_147 )
__releases( T_6 )
{
F_122 () ;
F_52 ( & V_82 ) ;
}
static void *
F_123 ( struct V_134 * V_135 , void * V_142 , T_5 * V_143 )
{
struct V_41 * V_42 = V_135 -> V_137 ;
struct V_45 * V_46 = F_25 ( V_42 -> V_47 ) ;
( * V_143 ) ++ ;
if ( * V_143 >= V_46 -> V_104 )
return NULL ;
return ( void * ) & V_46 -> V_103 [ * V_143 ] ;
}
static int F_124 ( struct V_134 * V_135 , void * V_142 )
{
T_1 * V_34 = V_142 ;
F_117 ( V_135 , L_7 , * V_34 ) ;
return 0 ;
}
static T_2
F_125 ( struct V_68 * V_148 , char T_3 * V_129 , T_4 V_130 ,
T_5 * V_131 )
{
struct V_39 * V_68 ;
unsigned long V_53 ;
char V_128 [ 4 ] = L_8 ;
F_45 ( & V_82 ) ;
V_68 = F_126 ( V_148 ) ;
if ( F_127 ( V_68 ) )
V_53 = V_68 -> V_53 ;
F_52 ( & V_82 ) ;
if ( ! V_68 )
return - V_38 ;
if ( V_53 & V_83 &&
! ( V_53 & V_88 ) )
strcpy ( V_128 , L_9 ) ;
if ( V_53 & V_88 ||
V_53 & V_90 )
strcat ( V_128 , L_5 ) ;
strcat ( V_128 , L_10 ) ;
return F_128 ( V_129 , V_130 , V_131 , V_128 , strlen ( V_128 ) ) ;
}
static T_2
F_129 ( struct V_68 * V_148 , const char T_3 * V_129 , T_4 V_130 ,
T_5 * V_131 )
{
struct V_39 * V_68 ;
unsigned long V_149 ;
int V_25 ;
V_25 = F_130 ( V_129 , V_130 , 10 , & V_149 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_105 () ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_149 ) {
case 0 :
case 1 :
V_25 = - V_38 ;
F_45 ( & V_82 ) ;
V_68 = F_126 ( V_148 ) ;
if ( F_127 ( V_68 ) )
V_25 = F_59 ( V_68 , V_149 ) ;
F_52 ( & V_82 ) ;
break;
default:
return - V_126 ;
}
* V_131 += V_130 ;
return V_25 ? V_25 : V_130 ;
}
static T_2
F_131 ( struct V_68 * V_148 , char T_3 * V_129 , T_4 V_130 ,
T_5 * V_131 )
{
const char V_150 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_114 * V_115 = V_148 -> V_136 ;
struct V_1 * system = V_115 -> V_116 ;
struct V_4 * V_13 ;
struct V_39 * V_68 ;
struct V_41 * V_42 = V_115 -> V_42 ;
char V_128 [ 2 ] ;
int V_125 = 0 ;
int V_25 ;
F_45 ( & V_82 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_68 -> V_5 ;
if ( ! F_57 ( V_13 ) || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_93 )
continue;
if ( system && strcmp ( V_13 -> V_6 -> system , system -> V_11 ) != 0 )
continue;
V_125 |= ( 1 << ! ! ( V_68 -> V_53 & V_83 ) ) ;
if ( V_125 == 3 )
break;
}
F_52 ( & V_82 ) ;
V_128 [ 0 ] = V_150 [ V_125 ] ;
V_128 [ 1 ] = '\n' ;
V_25 = F_128 ( V_129 , V_130 , V_131 , V_128 , 2 ) ;
return V_25 ;
}
static T_2
F_132 ( struct V_68 * V_148 , const char T_3 * V_129 , T_4 V_130 ,
T_5 * V_131 )
{
struct V_114 * V_115 = V_148 -> V_136 ;
struct V_1 * system = V_115 -> V_116 ;
const char * V_11 = NULL ;
unsigned long V_149 ;
T_2 V_25 ;
V_25 = F_130 ( V_129 , V_130 , 10 , & V_149 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_105 () ;
if ( V_25 < 0 )
return V_25 ;
if ( V_149 != 0 && V_149 != 1 )
return - V_126 ;
if ( system )
V_11 = system -> V_11 ;
V_25 = F_99 ( V_115 -> V_42 , NULL , V_11 , NULL , V_149 ) ;
if ( V_25 )
goto V_151;
V_25 = V_130 ;
V_151:
* V_131 += V_130 ;
return V_25 ;
}
static void * F_133 ( struct V_134 * V_135 , void * V_142 , T_5 * V_143 )
{
struct V_4 * V_13 = F_126 ( V_135 -> V_137 ) ;
struct V_3 * V_152 = & V_15 ;
struct V_3 * V_10 = F_4 ( V_13 ) ;
struct V_3 * V_153 = V_142 ;
( * V_143 ) ++ ;
switch ( ( unsigned long ) V_142 ) {
case V_154 :
V_153 = V_152 ;
break;
case V_155 :
V_153 = V_10 ;
break;
case V_156 :
return NULL ;
}
V_153 = V_153 -> V_106 ;
if ( V_153 == V_152 )
return ( void * ) V_155 ;
else if ( V_153 == V_10 )
return ( void * ) V_156 ;
else
return V_153 ;
}
static int F_134 ( struct V_134 * V_135 , void * V_142 )
{
struct V_4 * V_13 = F_126 ( V_135 -> V_137 ) ;
struct V_9 * V_12 ;
const char * V_157 ;
switch ( ( unsigned long ) V_142 ) {
case V_154 :
F_117 ( V_135 , L_11 , F_57 ( V_13 ) ) ;
F_117 ( V_135 , L_12 , V_13 -> V_37 . type ) ;
F_135 ( V_135 , L_13 ) ;
return 0 ;
case V_155 :
F_136 ( V_135 , '\n' ) ;
return 0 ;
case V_156 :
F_117 ( V_135 , L_14 ,
V_13 -> V_158 ) ;
return 0 ;
}
V_12 = F_113 ( V_142 , struct V_9 , V_24 ) ;
V_157 = strchr ( V_12 -> type , '[' ) ;
if ( ! strncmp ( V_12 -> type , L_15 , 10 ) )
V_157 = NULL ;
if ( ! V_157 )
F_117 ( V_135 , L_16 ,
V_12 -> type , V_12 -> V_11 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
else
F_117 ( V_135 , L_17 ,
( int ) ( V_157 - V_12 -> type ) ,
V_12 -> type , V_12 -> V_11 ,
V_157 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
return 0 ;
}
static void * F_137 ( struct V_134 * V_135 , T_5 * V_143 )
{
void * V_147 = ( void * ) V_154 ;
T_5 V_144 = 0 ;
F_45 ( & V_82 ) ;
if ( ! F_126 ( V_135 -> V_137 ) )
return F_138 ( - V_38 ) ;
while ( V_144 < * V_143 && V_147 )
V_147 = F_133 ( V_135 , V_147 , & V_144 ) ;
return V_147 ;
}
static void F_139 ( struct V_134 * V_135 , void * V_147 )
{
F_52 ( & V_82 ) ;
}
static int F_140 ( struct V_159 * V_159 , struct V_68 * V_68 )
{
struct V_134 * V_135 ;
int V_25 ;
V_25 = F_141 ( V_68 , & V_160 ) ;
if ( V_25 < 0 )
return V_25 ;
V_135 = V_68 -> V_136 ;
V_135 -> V_137 = V_68 ;
return 0 ;
}
static T_2
F_142 ( struct V_68 * V_148 , char T_3 * V_129 , T_4 V_130 , T_5 * V_131 )
{
int V_36 = ( long ) F_126 ( V_148 ) ;
char V_128 [ 32 ] ;
int V_52 ;
if ( * V_131 )
return 0 ;
if ( F_143 ( ! V_36 ) )
return - V_38 ;
V_52 = sprintf ( V_128 , L_7 , V_36 ) ;
return F_128 ( V_129 , V_130 , V_131 , V_128 , V_52 ) ;
}
static T_2
F_144 ( struct V_68 * V_148 , char T_3 * V_129 , T_4 V_130 ,
T_5 * V_131 )
{
struct V_39 * V_68 ;
struct V_161 * V_162 ;
int V_163 = - V_38 ;
if ( * V_131 )
return 0 ;
V_162 = F_145 ( sizeof( * V_162 ) , V_164 ) ;
if ( ! V_162 )
return - V_22 ;
F_34 ( V_162 ) ;
F_45 ( & V_82 ) ;
V_68 = F_126 ( V_148 ) ;
if ( V_68 )
F_146 ( V_68 , V_162 ) ;
F_52 ( & V_82 ) ;
if ( V_68 )
V_163 = F_128 ( V_129 , V_130 , V_131 ,
V_162 -> V_56 , F_147 ( V_162 ) ) ;
F_81 ( V_162 ) ;
return V_163 ;
}
static T_2
F_148 ( struct V_68 * V_148 , const char T_3 * V_129 , T_4 V_130 ,
T_5 * V_131 )
{
struct V_39 * V_68 ;
char * V_128 ;
int V_165 = - V_38 ;
if ( V_130 >= V_166 )
return - V_126 ;
V_128 = F_149 ( V_129 , V_130 ) ;
if ( F_150 ( V_128 ) )
return F_151 ( V_128 ) ;
F_45 ( & V_82 ) ;
V_68 = F_126 ( V_148 ) ;
if ( V_68 )
V_165 = F_152 ( V_68 , V_128 ) ;
F_52 ( & V_82 ) ;
F_81 ( V_128 ) ;
if ( V_165 < 0 )
return V_165 ;
* V_131 += V_130 ;
return V_130 ;
}
static int F_153 ( struct V_159 * V_159 , struct V_68 * V_148 )
{
struct V_1 * system = NULL ;
struct V_114 * V_115 = NULL ;
struct V_41 * V_42 ;
int V_25 ;
if ( F_154 () )
return - V_38 ;
F_45 ( & V_167 ) ;
F_45 ( & V_82 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_115 == V_159 -> V_121 ) {
if ( V_115 -> V_117 ) {
F_87 ( V_115 ) ;
system = V_115 -> V_116 ;
}
goto V_168;
}
}
}
V_168:
F_52 ( & V_82 ) ;
F_52 ( & V_167 ) ;
if ( ! system )
return - V_38 ;
F_13 ( ! V_115 ) ;
if ( F_155 ( V_42 ) < 0 ) {
F_89 ( V_115 ) ;
return - V_38 ;
}
V_25 = F_156 ( V_159 , V_148 ) ;
if ( V_25 < 0 ) {
F_157 ( V_42 ) ;
F_89 ( V_115 ) ;
}
return V_25 ;
}
static int F_158 ( struct V_159 * V_159 , struct V_68 * V_148 )
{
struct V_114 * V_115 ;
struct V_41 * V_42 = V_159 -> V_121 ;
int V_25 ;
if ( F_154 () )
return - V_38 ;
if ( F_155 ( V_42 ) < 0 )
return - V_38 ;
V_115 = F_159 ( sizeof( * V_115 ) , V_164 ) ;
if ( ! V_115 ) {
F_157 ( V_42 ) ;
return - V_22 ;
}
V_115 -> V_42 = V_42 ;
V_25 = F_156 ( V_159 , V_148 ) ;
if ( V_25 < 0 ) {
F_157 ( V_42 ) ;
F_81 ( V_115 ) ;
return V_25 ;
}
V_148 -> V_136 = V_115 ;
return 0 ;
}
static int F_160 ( struct V_159 * V_159 , struct V_68 * V_68 )
{
struct V_114 * V_115 = V_68 -> V_136 ;
F_157 ( V_115 -> V_42 ) ;
if ( V_115 -> V_116 )
F_89 ( V_115 ) ;
else
F_81 ( V_115 ) ;
return 0 ;
}
static T_2
F_161 ( struct V_68 * V_148 , char T_3 * V_129 , T_4 V_130 ,
T_5 * V_131 )
{
struct V_114 * V_115 = V_148 -> V_136 ;
struct V_1 * system = V_115 -> V_116 ;
struct V_161 * V_162 ;
int V_163 ;
if ( * V_131 )
return 0 ;
V_162 = F_145 ( sizeof( * V_162 ) , V_164 ) ;
if ( ! V_162 )
return - V_22 ;
F_34 ( V_162 ) ;
F_162 ( system , V_162 ) ;
V_163 = F_128 ( V_129 , V_130 , V_131 ,
V_162 -> V_56 , F_147 ( V_162 ) ) ;
F_81 ( V_162 ) ;
return V_163 ;
}
static T_2
F_163 ( struct V_68 * V_148 , const char T_3 * V_129 , T_4 V_130 ,
T_5 * V_131 )
{
struct V_114 * V_115 = V_148 -> V_136 ;
char * V_128 ;
int V_165 ;
if ( V_130 >= V_166 )
return - V_126 ;
V_128 = F_149 ( V_129 , V_130 ) ;
if ( F_150 ( V_128 ) )
return F_151 ( V_128 ) ;
V_165 = F_164 ( V_115 , V_128 ) ;
F_81 ( V_128 ) ;
if ( V_165 < 0 )
return V_165 ;
* V_131 += V_130 ;
return V_130 ;
}
static T_2
F_165 ( struct V_68 * V_148 , char T_3 * V_129 , T_4 V_130 , T_5 * V_131 )
{
int (* F_166)( struct V_161 * V_162 ) = V_148 -> V_136 ;
struct V_161 * V_162 ;
int V_163 ;
if ( * V_131 )
return 0 ;
V_162 = F_145 ( sizeof( * V_162 ) , V_164 ) ;
if ( ! V_162 )
return - V_22 ;
F_34 ( V_162 ) ;
F_166 ( V_162 ) ;
V_163 = F_128 ( V_129 , V_130 , V_131 ,
V_162 -> V_56 , F_147 ( V_162 ) ) ;
F_81 ( V_162 ) ;
return V_163 ;
}
static int F_167 ( struct V_45 * V_46 )
{
return ( V_166 << V_46 -> V_109 ) / sizeof( T_1 ) ;
}
static void F_168 ( void * V_44 )
{
struct V_41 * V_42 = V_44 ;
struct V_45 * V_46 ;
V_46 = F_70 ( V_42 -> V_47 ,
F_169 ( & V_82 ) ) ;
F_64 ( V_42 -> V_48 . V_44 -> V_49 ,
F_62 ( V_46 , V_107 ) ) ;
}
static T_2
F_170 ( struct V_68 * V_148 , const char T_3 * V_129 ,
T_4 V_130 , T_5 * V_131 )
{
struct V_134 * V_135 = V_148 -> V_136 ;
struct V_41 * V_42 = V_135 -> V_137 ;
struct V_45 * V_47 = NULL ;
struct V_45 * V_46 = NULL ;
struct V_39 * V_68 ;
struct V_132 V_133 ;
unsigned long V_149 ;
T_5 V_169 ;
T_2 V_138 = 0 ;
T_2 V_25 = 0 ;
T_1 V_34 ;
int V_170 ;
if ( ! V_130 )
return 0 ;
V_25 = F_105 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_106 ( & V_133 , V_139 + 1 ) )
return - V_22 ;
F_45 ( & V_82 ) ;
while ( V_130 > 0 ) {
V_169 = 0 ;
V_25 = F_107 ( & V_133 , V_129 , V_130 , & V_169 ) ;
if ( V_25 < 0 || ! F_108 ( & V_133 ) )
break;
V_138 += V_25 ;
V_129 += V_25 ;
V_130 -= V_25 ;
V_133 . V_56 [ V_133 . V_140 ] = 0 ;
V_25 = - V_126 ;
if ( F_171 ( V_133 . V_56 , 0 , & V_149 ) )
break;
if ( V_149 > V_171 )
break;
V_34 = ( T_1 ) V_149 ;
V_25 = - V_22 ;
if ( ! V_46 ) {
V_46 = F_145 ( sizeof( * V_46 ) , V_164 ) ;
if ( ! V_46 )
break;
V_47 = F_70 ( V_42 -> V_47 ,
F_71 ( & V_82 ) ) ;
if ( V_47 )
V_46 -> V_109 = V_47 -> V_109 ;
else
V_46 -> V_109 = 0 ;
V_46 -> V_103 = ( void * ) F_172 ( V_164 ,
V_46 -> V_109 ) ;
if ( ! V_46 -> V_103 )
break;
if ( V_47 ) {
V_46 -> V_104 = V_47 -> V_104 ;
memcpy ( V_46 -> V_103 , V_47 -> V_103 ,
V_46 -> V_104 * sizeof( T_1 ) ) ;
} else
V_46 -> V_104 = 0 ;
}
if ( V_46 -> V_104 >= F_167 ( V_46 ) ) {
T_1 * V_172 ;
V_172 = ( void * ) F_172 ( V_164 ,
V_46 -> V_109 + 1 ) ;
if ( ! V_172 )
break;
memcpy ( V_172 , V_46 -> V_103 ,
V_46 -> V_104 * sizeof( T_1 ) ) ;
F_80 ( ( unsigned long ) V_46 -> V_103 , V_46 -> V_109 ) ;
V_46 -> V_109 ++ ;
V_46 -> V_103 = V_172 ;
}
V_46 -> V_103 [ V_46 -> V_104 ++ ] = V_34 ;
F_173 ( & V_133 ) ;
V_25 = 0 ;
}
F_109 ( & V_133 ) ;
if ( V_25 < 0 ) {
if ( V_46 )
F_80 ( ( unsigned long ) V_46 -> V_103 , V_46 -> V_109 ) ;
F_81 ( V_46 ) ;
F_52 ( & V_82 ) ;
return V_25 ;
}
if ( ! V_46 ) {
F_52 ( & V_82 ) ;
return V_25 ;
}
F_174 ( V_46 -> V_103 , V_46 -> V_104 , sizeof( T_1 ) , F_61 , NULL ) ;
for ( V_170 = 1 ; V_170 < V_46 -> V_104 ; V_170 ++ ) {
int V_173 = V_170 ;
while ( V_170 < V_46 -> V_104 &&
V_46 -> V_103 [ V_170 - 1 ] == V_46 -> V_103 [ V_170 ] )
V_170 ++ ;
if ( V_173 != V_170 ) {
if ( V_170 < V_46 -> V_104 ) {
memmove ( & V_46 -> V_103 [ V_173 ] , & V_46 -> V_103 [ V_170 ] ,
( V_46 -> V_104 - V_170 ) * sizeof( T_1 ) ) ;
V_46 -> V_104 -= V_170 - V_173 ;
V_170 = V_173 ;
} else
V_46 -> V_104 = V_173 ;
}
}
F_78 ( V_42 -> V_47 , V_46 ) ;
F_6 (file, &tr->events, list) {
F_48 ( V_108 , & V_68 -> V_53 ) ;
}
if ( V_47 ) {
F_79 () ;
F_80 ( ( unsigned long ) V_47 -> V_103 , V_47 -> V_109 ) ;
F_81 ( V_47 ) ;
} else {
F_175 ( F_63 ,
V_42 , V_171 ) ;
F_175 ( F_65 ,
V_42 , 0 ) ;
F_176 ( F_66 ,
V_42 , V_171 ) ;
F_176 ( F_68 ,
V_42 , 0 ) ;
F_177 ( F_66 ,
V_42 , V_171 ) ;
F_177 ( F_68 ,
V_42 , 0 ) ;
F_178 ( F_66 ,
V_42 , V_171 ) ;
F_178 ( F_68 ,
V_42 , 0 ) ;
}
F_179 ( F_168 , V_42 , 1 ) ;
F_52 ( & V_82 ) ;
V_25 = V_138 ;
* V_131 += V_138 ;
return V_25 ;
}
static int
F_180 ( struct V_159 * V_159 , struct V_68 * V_68 ,
const struct V_174 * V_175 )
{
struct V_134 * V_135 ;
int V_25 ;
V_25 = F_141 ( V_68 , V_175 ) ;
if ( V_25 < 0 )
return V_25 ;
V_135 = V_68 -> V_136 ;
V_135 -> V_137 = V_159 -> V_121 ;
return V_25 ;
}
static int F_181 ( struct V_159 * V_159 , struct V_68 * V_68 )
{
struct V_41 * V_42 = V_159 -> V_121 ;
F_157 ( V_42 ) ;
return F_182 ( V_159 , V_68 ) ;
}
static int
F_183 ( struct V_159 * V_159 , struct V_68 * V_68 )
{
const struct V_174 * V_175 = & V_176 ;
return F_180 ( V_159 , V_68 , V_175 ) ;
}
static int
F_184 ( struct V_159 * V_159 , struct V_68 * V_68 )
{
const struct V_174 * V_175 = & V_177 ;
struct V_41 * V_42 = V_159 -> V_121 ;
int V_25 ;
if ( F_155 ( V_42 ) < 0 )
return - V_38 ;
if ( ( V_68 -> V_178 & V_179 ) &&
( V_68 -> V_180 & V_181 ) )
F_60 ( V_42 ) ;
V_25 = F_180 ( V_159 , V_68 , V_175 ) ;
if ( V_25 < 0 )
F_157 ( V_42 ) ;
return V_25 ;
}
static int
F_185 ( struct V_159 * V_159 , struct V_68 * V_68 )
{
const struct V_174 * V_175 = & V_182 ;
struct V_41 * V_42 = V_159 -> V_121 ;
int V_25 ;
if ( F_155 ( V_42 ) < 0 )
return - V_38 ;
if ( ( V_68 -> V_178 & V_179 ) &&
( V_68 -> V_180 & V_181 ) )
F_82 ( V_42 ) ;
V_25 = F_180 ( V_159 , V_68 , V_175 ) ;
if ( V_25 < 0 )
F_157 ( V_42 ) ;
return V_25 ;
}
static struct V_1 *
F_186 ( const char * V_11 )
{
struct V_1 * system ;
system = F_145 ( sizeof( * system ) , V_164 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
system -> V_11 = F_187 ( V_11 , V_164 ) ;
if ( ! system -> V_11 )
goto V_183;
system -> V_111 = NULL ;
system -> V_111 = F_159 ( sizeof( struct V_110 ) , V_164 ) ;
if ( ! system -> V_111 )
goto V_183;
F_11 ( & system -> V_112 , & V_184 ) ;
return system ;
V_183:
F_85 ( system -> V_11 ) ;
F_81 ( system ) ;
return NULL ;
}
static struct V_118 *
F_188 ( struct V_41 * V_42 , const char * V_11 ,
struct V_39 * V_68 , struct V_118 * V_185 )
{
struct V_114 * V_115 ;
struct V_1 * system ;
struct V_118 * V_57 ;
F_6 (dir, &tr->systems, list) {
system = V_115 -> V_116 ;
if ( strcmp ( system -> V_11 , V_11 ) == 0 ) {
V_115 -> V_117 ++ ;
V_68 -> system = V_115 ;
return V_115 -> V_57 ;
}
}
F_6 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_11 , V_11 ) == 0 )
break;
}
if ( & system -> V_112 == & V_184 )
system = NULL ;
V_115 = F_145 ( sizeof( * V_115 ) , V_164 ) ;
if ( ! V_115 )
goto V_186;
if ( ! system ) {
system = F_186 ( V_11 ) ;
if ( ! system )
goto V_183;
} else
F_86 ( system ) ;
V_115 -> V_57 = F_189 ( V_11 , V_185 ) ;
if ( ! V_115 -> V_57 ) {
F_190 ( L_18 , V_11 ) ;
F_83 ( system ) ;
goto V_183;
}
V_115 -> V_42 = V_42 ;
V_115 -> V_2 = 1 ;
V_115 -> V_117 = 1 ;
V_115 -> V_116 = system ;
V_68 -> system = V_115 ;
V_57 = F_191 ( L_19 , 0644 , V_115 -> V_57 , V_115 ,
& V_187 ) ;
if ( ! V_57 ) {
F_81 ( system -> V_111 ) ;
system -> V_111 = NULL ;
F_190 ( L_20 , V_11 ) ;
}
F_192 ( L_21 , 0644 , V_115 -> V_57 , V_115 ,
& V_188 ) ;
F_11 ( & V_115 -> V_112 , & V_42 -> V_189 ) ;
return V_115 -> V_57 ;
V_183:
F_81 ( V_115 ) ;
V_186:
if ( ! V_115 || ! system )
F_190 ( L_22 , V_11 ) ;
return NULL ;
}
static int
F_193 ( struct V_118 * V_185 , struct V_39 * V_68 )
{
struct V_4 * V_13 = V_68 -> V_5 ;
struct V_41 * V_42 = V_68 -> V_42 ;
struct V_3 * V_10 ;
struct V_118 * V_190 ;
const char * V_11 ;
int V_25 ;
if ( strcmp ( V_13 -> V_6 -> system , V_146 ) != 0 ) {
V_190 = F_188 ( V_42 , V_13 -> V_6 -> system , V_68 , V_185 ) ;
if ( ! V_190 )
return - V_22 ;
} else
V_190 = V_185 ;
V_11 = F_57 ( V_13 ) ;
V_68 -> V_115 = F_189 ( V_11 , V_190 ) ;
if ( ! V_68 -> V_115 ) {
F_190 ( L_23 , V_11 ) ;
return - 1 ;
}
if ( V_13 -> V_6 -> V_93 && ! ( V_13 -> V_53 & V_127 ) )
F_192 ( L_21 , 0644 , V_68 -> V_115 , V_68 ,
& V_191 ) ;
#ifdef F_43
if ( V_13 -> V_37 . type && V_13 -> V_6 -> V_93 )
F_192 ( L_24 , 0444 , V_68 -> V_115 ,
( void * ) ( long ) V_13 -> V_37 . type ,
& V_192 ) ;
#endif
V_10 = F_4 ( V_13 ) ;
if ( F_194 ( V_10 ) ) {
V_25 = V_13 -> V_6 -> V_193 ( V_13 ) ;
if ( V_25 < 0 ) {
F_190 ( L_25 ,
V_11 ) ;
return - 1 ;
}
}
F_192 ( L_19 , 0644 , V_68 -> V_115 , V_68 ,
& V_194 ) ;
if ( ! ( V_13 -> V_53 & V_127 ) )
F_192 ( L_26 , 0644 , V_68 -> V_115 , V_68 ,
& V_195 ) ;
F_192 ( L_27 , 0444 , V_68 -> V_115 , V_13 ,
& V_196 ) ;
return 0 ;
}
static void F_195 ( struct V_4 * V_13 )
{
struct V_39 * V_68 ;
struct V_41 * V_42 ;
F_196 (tr, file) {
if ( V_68 -> V_5 != V_13 )
continue;
F_92 ( V_68 ) ;
break;
} F_51 () ;
}
static void F_197 ( struct V_4 * V_13 )
{
struct V_41 * V_42 ;
struct V_39 * V_68 ;
F_46 (tr, file) {
if ( V_68 -> V_5 != V_13 )
continue;
F_59 ( V_68 , 0 ) ;
break;
} F_51 () ;
if ( V_13 -> V_37 . V_62 )
F_198 ( & V_13 -> V_37 ) ;
F_195 ( V_13 ) ;
F_20 ( & V_13 -> V_112 ) ;
}
static int F_199 ( struct V_4 * V_13 )
{
int V_25 = 0 ;
const char * V_11 ;
V_11 = F_57 ( V_13 ) ;
if ( F_13 ( ! V_11 ) )
return - V_126 ;
if ( V_13 -> V_6 -> V_197 ) {
V_25 = V_13 -> V_6 -> V_197 ( V_13 ) ;
if ( V_25 < 0 && V_25 != - V_198 )
F_190 ( L_28 , V_11 ) ;
}
return V_25 ;
}
static int
F_200 ( struct V_4 * V_13 , struct V_199 * V_200 )
{
int V_25 ;
V_25 = F_199 ( V_13 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_13 -> V_112 , & V_201 ) ;
V_13 -> V_200 = V_200 ;
return 0 ;
}
static char * F_201 ( char * V_202 , struct V_203 * V_204 , int V_52 )
{
int V_205 ;
int V_206 ;
V_206 = snprintf ( V_202 , 0 , L_29 , V_204 -> V_207 ) ;
if ( V_52 < V_206 )
return NULL ;
snprintf ( V_202 , V_206 + 1 , L_29 , V_204 -> V_207 ) ;
V_205 = strlen ( V_202 + V_52 ) ;
memmove ( V_202 + V_206 , V_202 + V_52 , V_205 ) ;
V_202 [ V_206 + V_205 ] = 0 ;
return V_202 + V_206 ;
}
static void F_202 ( struct V_4 * V_13 ,
struct V_203 * V_204 )
{
char * V_202 ;
int V_208 = 0 ;
int V_52 = strlen ( V_204 -> V_209 ) ;
for ( V_202 = V_13 -> V_158 ; * V_202 ; V_202 ++ ) {
if ( * V_202 == '\\' ) {
V_202 ++ ;
if ( ! * V_202 )
break;
continue;
}
if ( * V_202 == '"' ) {
V_208 ^= 1 ;
continue;
}
if ( V_208 )
continue;
if ( isdigit ( * V_202 ) ) {
do {
V_202 ++ ;
} while ( isalnum ( * V_202 ) );
if ( ! * V_202 )
break;
continue;
}
if ( isalpha ( * V_202 ) || * V_202 == '_' ) {
if ( strncmp ( V_204 -> V_209 , V_202 , V_52 ) == 0 &&
! isalnum ( V_202 [ V_52 ] ) && V_202 [ V_52 ] != '_' ) {
V_202 = F_201 ( V_202 , V_204 , V_52 ) ;
if ( F_84 ( ! V_202 ) )
return;
continue;
}
V_210:
do {
V_202 ++ ;
} while ( isalnum ( * V_202 ) || * V_202 == '_' );
if ( ! * V_202 )
break;
if ( * V_202 == '.' || ( V_202 [ 0 ] == '-' && V_202 [ 1 ] == '>' ) ) {
V_202 += * V_202 == '.' ? 1 : 2 ;
if ( ! * V_202 )
break;
goto V_210;
}
continue;
}
}
}
void F_203 ( struct V_203 * * V_204 , int V_52 )
{
struct V_4 * V_13 , * V_147 ;
const char * V_211 = NULL ;
int V_212 ;
int V_170 ;
F_204 ( & V_213 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( ! V_211 || V_13 -> V_6 -> system != V_211 ) {
V_212 = 0 ;
V_211 = V_13 -> V_6 -> system ;
}
for ( V_170 = V_212 ; V_170 < V_52 ; V_170 ++ ) {
if ( V_13 -> V_6 -> system == V_204 [ V_170 ] -> system ) {
if ( ! V_212 )
V_212 = V_170 ;
F_202 ( V_13 , V_204 [ V_170 ] ) ;
}
}
}
F_205 ( & V_213 ) ;
}
static struct V_39 *
F_206 ( struct V_4 * V_13 ,
struct V_41 * V_42 )
{
struct V_39 * V_68 ;
V_68 = F_9 ( V_122 , V_21 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> V_5 = V_13 ;
V_68 -> V_42 = V_42 ;
F_207 ( & V_68 -> V_87 , 0 ) ;
F_207 ( & V_68 -> V_214 , 0 ) ;
F_208 ( & V_68 -> V_215 ) ;
F_11 ( & V_68 -> V_112 , & V_42 -> V_145 ) ;
return V_68 ;
}
static int
F_209 ( struct V_4 * V_13 , struct V_41 * V_42 )
{
struct V_39 * V_68 ;
V_68 = F_206 ( V_13 , V_42 ) ;
if ( ! V_68 )
return - V_22 ;
return F_193 ( V_42 -> V_216 , V_68 ) ;
}
static T_7 int
F_210 ( struct V_4 * V_13 ,
struct V_41 * V_42 )
{
struct V_39 * V_68 ;
V_68 = F_206 ( V_13 , V_42 ) ;
if ( ! V_68 )
return - V_22 ;
return 0 ;
}
int F_211 ( struct V_4 * V_13 )
{
int V_25 ;
F_45 ( & V_167 ) ;
F_45 ( & V_82 ) ;
V_25 = F_200 ( V_13 , NULL ) ;
if ( V_25 >= 0 )
F_212 ( V_13 ) ;
F_52 ( & V_82 ) ;
F_52 ( & V_167 ) ;
return V_25 ;
}
static void F_213 ( struct V_4 * V_13 )
{
F_197 ( V_13 ) ;
F_18 ( V_13 ) ;
F_97 ( V_13 -> V_111 ) ;
V_13 -> V_111 = NULL ;
}
static int F_214 ( struct V_4 * V_13 )
{
struct V_41 * V_42 ;
struct V_39 * V_68 ;
#ifdef F_43
if ( V_13 -> V_217 )
return - V_218 ;
#endif
F_46 (tr, file) {
if ( V_68 -> V_5 != V_13 )
continue;
if ( V_68 -> V_53 & V_83 )
return - V_218 ;
break;
} F_51 () ;
F_213 ( V_13 ) ;
return 0 ;
}
int F_215 ( struct V_4 * V_13 )
{
int V_25 ;
F_45 ( & V_167 ) ;
F_45 ( & V_82 ) ;
F_204 ( & V_213 ) ;
V_25 = F_214 ( V_13 ) ;
F_205 ( & V_213 ) ;
F_52 ( & V_82 ) ;
F_52 ( & V_167 ) ;
return V_25 ;
}
static void F_216 ( struct V_199 * V_200 )
{
struct V_4 * * V_13 , * * V_173 , * * V_219 ;
if ( ! V_200 -> V_220 )
return;
if ( F_217 ( V_200 ) ) {
F_218 ( L_30 ,
V_200 -> V_11 ) ;
return;
}
V_173 = V_200 -> V_221 ;
V_219 = V_200 -> V_221 + V_200 -> V_220 ;
F_219 (call, start, end) {
F_200 ( * V_13 , V_200 ) ;
F_212 ( * V_13 ) ;
}
}
static void F_220 ( struct V_199 * V_200 )
{
struct V_4 * V_13 , * V_147 ;
bool V_222 = false ;
F_204 ( & V_213 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( V_13 -> V_200 == V_200 ) {
if ( V_13 -> V_53 & V_97 )
V_222 = true ;
F_213 ( V_13 ) ;
}
}
F_205 ( & V_213 ) ;
if ( V_222 )
F_221 () ;
}
static int F_222 ( struct V_223 * V_224 ,
unsigned long V_149 , void * V_44 )
{
struct V_199 * V_200 = V_44 ;
F_45 ( & V_167 ) ;
F_45 ( & V_82 ) ;
switch ( V_149 ) {
case V_225 :
F_216 ( V_200 ) ;
break;
case V_226 :
F_220 ( V_200 ) ;
break;
}
F_52 ( & V_82 ) ;
F_52 ( & V_167 ) ;
return 0 ;
}
static void
F_223 ( struct V_41 * V_42 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
V_25 = F_209 ( V_13 , V_42 ) ;
if ( V_25 < 0 )
F_190 ( L_31 ,
F_57 ( V_13 ) ) ;
}
}
struct V_39 *
F_224 ( struct V_41 * V_42 , const char * system , const char * V_37 )
{
struct V_39 * V_68 ;
struct V_4 * V_13 ;
const char * V_11 ;
F_6 (file, &tr->events, list) {
V_13 = V_68 -> V_5 ;
V_11 = F_57 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_93 )
continue;
if ( V_13 -> V_53 & V_127 )
continue;
if ( strcmp ( V_37 , V_11 ) == 0 &&
strcmp ( system , V_13 -> V_6 -> system ) == 0 )
return V_68 ;
}
return NULL ;
}
static void
F_225 ( unsigned long V_227 , unsigned long V_228 , void * * V_229 )
{
struct V_230 * * V_231 = (struct V_230 * * ) V_229 ;
struct V_230 * V_44 = * V_231 ;
if ( ! V_44 )
return;
if ( V_44 -> V_81 )
F_50 ( V_94 , & V_44 -> V_68 -> V_53 ) ;
else
F_48 ( V_94 , & V_44 -> V_68 -> V_53 ) ;
}
static void
F_226 ( unsigned long V_227 , unsigned long V_228 , void * * V_229 )
{
struct V_230 * * V_231 = (struct V_230 * * ) V_229 ;
struct V_230 * V_44 = * V_231 ;
if ( ! V_44 )
return;
if ( ! V_44 -> V_232 )
return;
if ( V_44 -> V_81 == ! ( V_44 -> V_68 -> V_53 & V_88 ) )
return;
if ( V_44 -> V_232 != - 1 )
( V_44 -> V_232 ) -- ;
F_225 ( V_227 , V_228 , V_229 ) ;
}
static int
F_227 ( struct V_134 * V_135 , unsigned long V_227 ,
struct V_233 * V_234 , void * V_229 )
{
struct V_230 * V_44 = V_229 ;
F_117 ( V_135 , L_32 , ( void * ) V_227 ) ;
F_117 ( V_135 , L_33 ,
V_44 -> V_81 ? V_235 : V_236 ,
V_44 -> V_68 -> V_5 -> V_6 -> system ,
F_57 ( V_44 -> V_68 -> V_5 ) ) ;
if ( V_44 -> V_232 == - 1 )
F_135 ( V_135 , L_34 ) ;
else
F_117 ( V_135 , L_35 , V_44 -> V_232 ) ;
return 0 ;
}
static int
F_228 ( struct V_233 * V_234 , unsigned long V_227 ,
void * * V_229 )
{
struct V_230 * * V_231 = (struct V_230 * * ) V_229 ;
struct V_230 * V_44 = * V_231 ;
V_44 -> V_237 ++ ;
return 0 ;
}
static void
F_229 ( struct V_233 * V_234 , unsigned long V_227 ,
void * * V_229 )
{
struct V_230 * * V_231 = (struct V_230 * * ) V_229 ;
struct V_230 * V_44 = * V_231 ;
if ( F_84 ( V_44 -> V_237 <= 0 ) )
return;
V_44 -> V_237 -- ;
if ( ! V_44 -> V_237 ) {
F_53 ( V_44 -> V_68 , 0 , 1 ) ;
F_230 ( V_44 -> V_68 -> V_5 -> V_200 ) ;
F_81 ( V_44 ) ;
}
* V_231 = NULL ;
}
static int
F_231 ( struct V_238 * V_239 ,
char * V_240 , char * V_241 , char * V_242 , int V_243 )
{
struct V_41 * V_42 = F_103 () ;
struct V_39 * V_68 ;
struct V_233 * V_234 ;
struct V_230 * V_44 ;
const char * system ;
const char * V_37 ;
char * V_244 ;
bool V_81 ;
int V_25 ;
if ( ! V_42 )
return - V_38 ;
if ( ! V_243 || ! V_242 )
return - V_126 ;
system = F_101 ( & V_242 , L_4 ) ;
if ( ! V_242 )
return - V_126 ;
V_37 = F_101 ( & V_242 , L_4 ) ;
F_45 ( & V_82 ) ;
V_25 = - V_126 ;
V_68 = F_224 ( V_42 , system , V_37 ) ;
if ( ! V_68 )
goto V_151;
V_81 = strcmp ( V_241 , V_235 ) == 0 ;
if ( V_81 )
V_234 = V_242 ? & V_245 : & V_246 ;
else
V_234 = V_242 ? & V_247 : & V_248 ;
if ( V_240 [ 0 ] == '!' ) {
F_232 ( V_240 + 1 , V_234 ) ;
V_25 = 0 ;
goto V_151;
}
V_25 = - V_22 ;
V_44 = F_159 ( sizeof( * V_44 ) , V_164 ) ;
if ( ! V_44 )
goto V_151;
V_44 -> V_81 = V_81 ;
V_44 -> V_232 = - 1 ;
V_44 -> V_68 = V_68 ;
if ( ! V_242 )
goto V_249;
V_244 = F_101 ( & V_242 , L_4 ) ;
V_25 = - V_126 ;
if ( ! strlen ( V_244 ) )
goto V_183;
V_25 = F_171 ( V_244 , 0 , & V_44 -> V_232 ) ;
if ( V_25 )
goto V_183;
V_249:
V_25 = F_233 ( V_68 -> V_5 -> V_200 ) ;
if ( ! V_25 ) {
V_25 = - V_218 ;
goto V_183;
}
V_25 = F_53 ( V_68 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_141;
V_25 = F_234 ( V_240 , V_234 , V_44 ) ;
if ( ! V_25 ) {
V_25 = - V_250 ;
goto V_251;
} else if ( V_25 < 0 )
goto V_251;
V_25 = 0 ;
V_151:
F_52 ( & V_82 ) ;
return V_25 ;
V_251:
F_53 ( V_68 , 0 , 1 ) ;
V_141:
F_230 ( V_68 -> V_5 -> V_200 ) ;
V_183:
F_81 ( V_44 ) ;
goto V_151;
}
static T_7 int F_235 ( void )
{
int V_25 ;
V_25 = F_236 ( & V_252 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_236 ( & V_253 ) ;
if ( F_13 ( V_25 < 0 ) )
F_237 ( & V_252 ) ;
return V_25 ;
}
static inline int F_235 ( void ) { return 0 ; }
static T_7 void
F_238 ( struct V_41 * V_42 )
{
struct V_39 * V_68 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_193 ( V_42 -> V_216 , V_68 ) ;
if ( V_25 < 0 )
F_190 ( L_31 ,
F_57 ( V_68 -> V_5 ) ) ;
}
}
static T_7 void
F_239 ( struct V_41 * V_42 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_84 ( V_13 -> V_200 ) )
continue;
V_25 = F_210 ( V_13 , V_42 ) ;
if ( V_25 < 0 )
F_190 ( L_36 ,
F_57 ( V_13 ) ) ;
}
}
static void
F_240 ( struct V_41 * V_42 )
{
struct V_39 * V_68 , * V_35 ;
F_19 (file, next, &tr->events, list)
F_92 ( V_68 ) ;
}
static void F_212 ( struct V_4 * V_13 )
{
struct V_41 * V_42 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_209 ( V_13 , V_42 ) ;
}
static T_7 int F_241 ( char * V_254 )
{
F_242 ( V_255 , V_254 , V_256 ) ;
V_257 = true ;
V_258 = true ;
return 1 ;
}
static int
F_243 ( struct V_118 * V_185 , struct V_41 * V_42 )
{
struct V_118 * V_190 ;
struct V_118 * V_57 ;
V_57 = F_191 ( L_37 , 0644 , V_185 ,
V_42 , & V_259 ) ;
if ( ! V_57 ) {
F_190 ( L_38 ) ;
return - V_22 ;
}
V_190 = F_189 ( L_39 , V_185 ) ;
if ( ! V_190 ) {
F_190 ( L_40 ) ;
return - V_22 ;
}
V_57 = F_191 ( L_41 , 0644 , V_185 ,
V_42 , & V_260 ) ;
F_192 ( L_42 , 0444 , V_190 ,
V_261 ,
& V_262 ) ;
F_192 ( L_43 , 0444 , V_190 ,
V_263 ,
& V_262 ) ;
F_192 ( L_21 , 0644 , V_190 ,
V_42 , & V_264 ) ;
V_42 -> V_216 = V_190 ;
return 0 ;
}
int F_244 ( struct V_118 * V_185 , struct V_41 * V_42 )
{
int V_25 ;
F_45 ( & V_82 ) ;
V_25 = F_243 ( V_185 , V_42 ) ;
if ( V_25 )
goto V_265;
F_204 ( & V_213 ) ;
F_223 ( V_42 ) ;
F_205 ( & V_213 ) ;
V_265:
F_52 ( & V_82 ) ;
return V_25 ;
}
static T_7 int
F_245 ( struct V_118 * V_185 , struct V_41 * V_42 )
{
int V_25 ;
F_45 ( & V_82 ) ;
V_25 = F_243 ( V_185 , V_42 ) ;
if ( V_25 )
goto V_265;
F_204 ( & V_213 ) ;
F_238 ( V_42 ) ;
F_205 ( & V_213 ) ;
V_265:
F_52 ( & V_82 ) ;
return V_25 ;
}
int F_246 ( struct V_41 * V_42 )
{
F_45 ( & V_82 ) ;
F_247 ( V_42 ) ;
F_69 ( V_42 ) ;
F_98 ( V_42 , NULL , NULL , NULL , 0 ) ;
F_79 () ;
F_204 ( & V_213 ) ;
F_240 ( V_42 ) ;
F_91 ( V_42 -> V_216 ) ;
F_205 ( & V_213 ) ;
V_42 -> V_216 = NULL ;
F_52 ( & V_82 ) ;
return 0 ;
}
static T_7 int F_248 ( void )
{
V_20 = F_249 ( V_9 , V_266 ) ;
V_122 = F_249 ( V_39 , V_266 ) ;
return 0 ;
}
static T_7 void
F_250 ( struct V_41 * V_42 , bool V_267 )
{
char * V_128 = V_255 ;
char * V_268 ;
int V_25 ;
while ( true ) {
V_268 = F_101 ( & V_128 , L_44 ) ;
if ( ! V_268 )
break;
if ( * V_268 ) {
if ( V_267 )
F_100 ( V_42 , V_268 , 0 ) ;
V_25 = F_100 ( V_42 , V_268 , 1 ) ;
if ( V_25 )
F_190 ( L_45 , V_268 ) ;
}
if ( V_128 )
* ( V_128 - 1 ) = ',' ;
}
}
static T_7 int F_251 ( void )
{
struct V_41 * V_42 = F_103 () ;
struct V_4 * * V_60 , * V_13 ;
int V_25 ;
if ( ! V_42 )
return - V_38 ;
F_219 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_13 = * V_60 ;
V_25 = F_199 ( V_13 ) ;
if ( ! V_25 )
F_11 ( & V_13 -> V_112 , & V_201 ) ;
}
F_239 ( V_42 ) ;
F_250 ( V_42 , false ) ;
F_252 () ;
F_235 () ;
F_253 () ;
return 0 ;
}
static T_7 int F_254 ( void )
{
struct V_41 * V_42 ;
V_42 = F_103 () ;
if ( ! V_42 )
return - V_38 ;
F_250 ( V_42 , true ) ;
return 0 ;
}
static T_7 int F_255 ( void )
{
struct V_41 * V_42 ;
struct V_118 * V_269 ;
struct V_118 * V_57 ;
int V_25 ;
V_42 = F_103 () ;
if ( ! V_42 )
return - V_38 ;
V_269 = F_256 () ;
if ( F_150 ( V_269 ) )
return 0 ;
V_57 = F_191 ( L_46 , 0444 , V_269 ,
V_42 , & V_270 ) ;
if ( ! V_57 )
F_190 ( L_47 ) ;
if ( F_14 () )
F_190 ( L_48 ) ;
if ( F_16 () )
F_190 ( L_49 ) ;
V_25 = F_245 ( V_269 , V_42 ) ;
if ( V_25 )
return V_25 ;
#ifdef F_257
V_25 = F_258 ( & V_271 ) ;
if ( V_25 )
F_190 ( L_50 ) ;
#endif
return 0 ;
}
void T_7 F_259 ( void )
{
F_248 () ;
F_260 () ;
F_251 () ;
}
static T_7 void F_261 ( struct V_272 * V_273 )
{
F_93 ( & V_274 ) ;
F_262 ( & V_275 ) ;
F_263 ( 1 ) ;
F_264 ( & V_275 ) ;
F_96 ( & V_274 ) ;
F_45 ( & V_276 ) ;
F_265 ( 1 ) ;
F_52 ( & V_276 ) ;
}
static T_7 int F_266 ( void * V_277 )
{
void * V_278 ;
V_278 = F_145 ( 1234 , V_164 ) ;
if ( ! V_278 )
F_56 ( L_51 ) ;
F_267 ( F_261 ) ;
F_81 ( V_278 ) ;
F_268 ( V_279 ) ;
while ( ! F_269 () ) {
F_270 () ;
F_268 ( V_279 ) ;
}
F_271 ( V_280 ) ;
return 0 ;
}
static T_7 void F_272 ( void )
{
struct V_101 * V_281 ;
V_281 = F_273 ( F_266 , NULL , L_52 ) ;
F_265 ( 1 ) ;
F_274 ( V_281 ) ;
}
static T_7 void F_275 ( void )
{
struct V_114 * V_115 ;
struct V_39 * V_68 ;
struct V_4 * V_13 ;
struct V_1 * system ;
struct V_41 * V_42 ;
int V_25 ;
V_42 = F_103 () ;
if ( ! V_42 )
return;
F_56 ( L_53 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_68 -> V_5 ;
if ( ! V_13 -> V_6 || ! V_13 -> V_6 -> V_72 )
continue;
#ifndef F_276
if ( V_13 -> V_6 -> system &&
strcmp ( V_13 -> V_6 -> system , L_54 ) == 0 )
continue;
#endif
F_56 ( L_55 , F_57 ( V_13 ) ) ;
if ( V_68 -> V_53 & V_83 ) {
F_190 ( L_56 ) ;
F_84 ( 1 ) ;
continue;
}
F_59 ( V_68 , 1 ) ;
F_272 () ;
F_59 ( V_68 , 0 ) ;
F_277 ( L_57 ) ;
}
F_56 ( L_58 ) ;
F_6 (dir, &tr->systems, list) {
system = V_115 -> V_116 ;
if ( strcmp ( system -> V_11 , L_59 ) == 0 )
continue;
F_56 ( L_60 , system -> V_11 ) ;
V_25 = F_99 ( V_42 , NULL , system -> V_11 , NULL , 1 ) ;
if ( F_84 ( V_25 ) ) {
F_190 ( L_61 ,
system -> V_11 ) ;
continue;
}
F_272 () ;
V_25 = F_99 ( V_42 , NULL , system -> V_11 , NULL , 0 ) ;
if ( F_84 ( V_25 ) ) {
F_190 ( L_62 ,
system -> V_11 ) ;
continue;
}
F_277 ( L_57 ) ;
}
F_56 ( L_63 ) ;
F_56 ( L_64 ) ;
V_25 = F_99 ( V_42 , NULL , NULL , NULL , 1 ) ;
if ( F_84 ( V_25 ) ) {
F_190 ( L_65 ) ;
return;
}
F_272 () ;
V_25 = F_99 ( V_42 , NULL , NULL , NULL , 0 ) ;
if ( F_84 ( V_25 ) ) {
F_190 ( L_66 ) ;
return;
}
F_277 ( L_57 ) ;
}
static void T_7
F_278 ( unsigned long V_227 , unsigned long V_228 ,
struct V_282 * V_283 , struct V_284 * V_284 )
{
struct V_285 * V_37 ;
struct V_286 * V_56 ;
struct V_287 * V_57 ;
unsigned long V_53 ;
long V_288 ;
int V_28 ;
int V_55 ;
V_55 = F_29 () ;
F_279 () ;
V_28 = F_280 () ;
V_288 = F_55 ( & F_281 ( V_289 , V_28 ) ) ;
if ( V_288 != 1 )
goto V_151;
F_28 ( V_53 ) ;
V_37 = F_282 ( & V_56 ,
V_290 , sizeof( * V_57 ) ,
V_53 , V_55 ) ;
if ( ! V_37 )
goto V_151;
V_57 = F_31 ( V_37 ) ;
V_57 -> V_227 = V_227 ;
V_57 -> V_228 = V_228 ;
F_283 ( V_291 , V_56 , V_37 , V_53 , V_55 ) ;
V_151:
F_284 ( & F_281 ( V_289 , V_28 ) ) ;
F_285 () ;
}
static T_7 void F_286 ( void )
{
int V_25 ;
V_291 = F_103 () ;
if ( F_13 ( ! V_291 ) )
return;
V_25 = F_287 ( & V_292 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_56 ( L_67 ) ;
return;
}
F_56 ( L_68 ) ;
F_275 () ;
F_288 ( & V_292 ) ;
}
static T_7 void F_286 ( void )
{
}
static T_7 int F_289 ( void )
{
if ( ! V_258 ) {
F_275 () ;
F_286 () ;
}
return 0 ;
}
