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
V_12 = F_5 ( & V_14 , V_11 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_5 ( & V_15 , V_11 ) ;
if ( V_12 )
return V_12 ;
V_10 = F_4 ( V_13 ) ;
return F_5 ( V_10 , V_11 ) ;
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
F_15 ( int , V_26 , V_23 ) ;
F_15 ( char * , V_27 , V_28 ) ;
return V_25 ;
}
static int F_16 ( void )
{
int V_25 ;
struct V_29 V_30 ;
F_17 (unsigned short, type) ;
F_17 (unsigned char, flags) ;
F_17 (unsigned char, preempt_count) ;
F_17 ( int , V_31 ) ;
return V_25 ;
}
static void F_18 ( struct V_4 * V_13 )
{
struct V_9 * V_12 , * V_32 ;
struct V_3 * V_10 ;
V_10 = F_4 ( V_13 ) ;
F_19 (field, next, head, link) {
F_20 ( & V_12 -> V_24 ) ;
F_21 ( V_20 , V_12 ) ;
}
}
int F_22 ( struct V_4 * V_13 )
{
int V_33 ;
V_33 = F_23 ( & V_13 -> V_34 ) ;
if ( ! V_33 )
return - V_35 ;
return 0 ;
}
bool F_24 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
V_43 = F_25 ( V_39 -> V_44 ) ;
if ( ! V_43 )
return false ;
V_41 = F_26 ( V_39 -> V_45 . V_41 ) ;
return V_41 -> V_46 ;
}
void * F_27 ( struct V_47 * V_48 ,
struct V_36 * V_37 ,
unsigned long V_49 )
{
struct V_4 * V_5 = V_37 -> V_5 ;
if ( ( V_37 -> V_50 & V_51 ) &&
F_24 ( V_37 ) )
return NULL ;
F_28 ( V_48 -> V_50 ) ;
V_48 -> V_52 = F_29 () ;
V_48 -> V_37 = V_37 ;
V_48 -> V_34 =
F_30 ( & V_48 -> V_53 , V_37 ,
V_5 -> V_34 . type , V_49 ,
V_48 -> V_50 , V_48 -> V_52 ) ;
if ( ! V_48 -> V_34 )
return NULL ;
V_48 -> V_54 = F_31 ( V_48 -> V_34 ) ;
return V_48 -> V_54 ;
}
static void F_32 ( struct V_47 * V_48 )
{
struct V_4 * V_5 ;
struct V_55 * V_34 ;
unsigned long V_50 ;
struct V_56 * V_57 = V_58 ;
if ( ! V_57 )
return;
V_5 = V_48 -> V_37 -> V_5 ;
if ( ! V_5 || ! V_5 -> V_34 . V_59 ||
! V_5 -> V_34 . V_59 -> V_60 )
return;
V_34 = & V_48 -> V_37 -> V_5 -> V_34 ;
F_33 ( & V_61 , V_50 ) ;
F_34 ( & V_57 -> V_62 ) ;
V_57 -> V_30 = V_48 -> V_54 ;
V_5 -> V_34 . V_59 -> V_60 ( V_57 , 0 , V_34 ) ;
F_35 ( & V_57 -> V_62 , 0 ) ;
F_36 ( L_1 , V_57 -> V_62 . V_53 ) ;
F_37 ( & V_61 , V_50 ) ;
}
void F_38 ( struct V_47 * V_48 )
{
if ( V_63 )
F_32 ( V_48 ) ;
F_39 ( V_48 -> V_37 , V_48 -> V_53 ,
V_48 -> V_34 , V_48 -> V_54 ,
V_48 -> V_50 , V_48 -> V_52 ) ;
}
int F_40 ( struct V_4 * V_13 ,
enum V_64 type , void * V_41 )
{
struct V_36 * V_65 = V_41 ;
F_13 ( ! ( V_13 -> V_50 & V_66 ) ) ;
switch ( type ) {
case V_67 :
return F_41 ( V_13 -> V_68 ,
V_13 -> V_6 -> V_69 ,
V_65 ) ;
case V_70 :
F_42 ( V_13 -> V_68 ,
V_13 -> V_6 -> V_69 ,
V_65 ) ;
return 0 ;
#ifdef F_43
case V_71 :
return F_41 ( V_13 -> V_68 ,
V_13 -> V_6 -> V_72 ,
V_13 ) ;
case V_73 :
F_42 ( V_13 -> V_68 ,
V_13 -> V_6 -> V_72 ,
V_13 ) ;
return 0 ;
case V_74 :
case V_75 :
case V_76 :
case V_77 :
return 0 ;
#endif
}
return 0 ;
}
void F_44 ( bool V_78 )
{
struct V_36 * V_65 ;
struct V_38 * V_39 ;
F_45 ( & V_79 ) ;
F_46 (tr, file) {
if ( ! ( V_65 -> V_50 & V_80 ) )
continue;
if ( V_78 ) {
F_47 () ;
F_48 ( V_81 , & V_65 -> V_50 ) ;
} else {
F_49 () ;
F_50 ( V_81 , & V_65 -> V_50 ) ;
}
} F_51 () ;
F_52 ( & V_79 ) ;
}
static int F_53 ( struct V_36 * V_65 ,
int V_78 , int V_82 )
{
struct V_4 * V_13 = V_65 -> V_5 ;
struct V_38 * V_39 = V_65 -> V_39 ;
int V_25 = 0 ;
int V_83 ;
switch ( V_78 ) {
case 0 :
if ( V_82 ) {
if ( F_54 ( & V_65 -> V_84 ) > 0 )
break;
V_83 = V_65 -> V_50 & V_85 ;
F_50 ( V_86 , & V_65 -> V_50 ) ;
} else
V_83 = ! ( V_65 -> V_50 & V_87 ) ;
if ( V_83 && ( V_65 -> V_50 & V_80 ) ) {
F_50 ( V_88 , & V_65 -> V_50 ) ;
if ( V_65 -> V_50 & V_89 ) {
F_49 () ;
F_50 ( V_81 , & V_65 -> V_50 ) ;
}
V_13 -> V_6 -> V_90 ( V_13 , V_70 , V_65 ) ;
}
if ( V_65 -> V_50 & V_87 )
F_48 ( V_91 , & V_65 -> V_50 ) ;
else
F_50 ( V_91 , & V_65 -> V_50 ) ;
break;
case 1 :
if ( ! V_82 )
F_50 ( V_91 , & V_65 -> V_50 ) ;
else {
if ( F_55 ( & V_65 -> V_84 ) > 1 )
break;
F_48 ( V_86 , & V_65 -> V_50 ) ;
}
if ( ! ( V_65 -> V_50 & V_80 ) ) {
if ( V_82 )
F_48 ( V_91 , & V_65 -> V_50 ) ;
if ( V_39 -> V_92 & V_93 ) {
F_47 () ;
F_48 ( V_81 , & V_65 -> V_50 ) ;
}
V_25 = V_13 -> V_6 -> V_90 ( V_13 , V_67 , V_65 ) ;
if ( V_25 ) {
F_49 () ;
F_56 ( L_2
L_3 , F_57 ( V_13 ) ) ;
break;
}
F_48 ( V_88 , & V_65 -> V_50 ) ;
V_13 -> V_50 |= V_94 ;
}
break;
}
return V_25 ;
}
int F_58 ( struct V_36 * V_65 ,
int V_78 , int V_82 )
{
return F_53 ( V_65 , V_78 , V_82 ) ;
}
static int F_59 ( struct V_36 * V_65 ,
int V_78 )
{
return F_53 ( V_65 , V_78 , 0 ) ;
}
static void F_60 ( struct V_38 * V_39 )
{
struct V_36 * V_65 ;
F_45 ( & V_79 ) ;
F_6 (file, &tr->events, list) {
F_59 ( V_65 , 0 ) ;
}
F_52 ( & V_79 ) ;
}
static int F_61 ( const void * V_95 , const void * V_96 )
{
const T_1 * V_97 = V_95 ;
const T_1 * V_31 = V_96 ;
if ( * V_97 == * V_31 )
return 0 ;
if ( * V_97 < * V_31 )
return - 1 ;
return 1 ;
}
static bool
F_62 ( struct V_42 * V_44 , struct V_98 * V_99 )
{
T_1 V_97 ;
T_1 * V_31 ;
if ( ! V_44 )
return false ;
V_97 = V_99 -> V_31 ;
V_31 = bsearch ( & V_97 , V_44 -> V_100 ,
V_44 -> V_101 , sizeof( T_1 ) ,
F_61 ) ;
if ( ! V_31 )
return true ;
return false ;
}
static void
F_63 ( void * V_41 , bool V_102 ,
struct V_98 * V_103 , struct V_98 * V_32 )
{
struct V_38 * V_39 = V_41 ;
struct V_42 * V_43 ;
V_43 = F_25 ( V_39 -> V_44 ) ;
F_64 ( V_39 -> V_45 . V_41 -> V_46 ,
F_62 ( V_43 , V_103 ) &&
F_62 ( V_43 , V_32 ) ) ;
}
static void
F_65 ( void * V_41 , bool V_102 ,
struct V_98 * V_103 , struct V_98 * V_32 )
{
struct V_38 * V_39 = V_41 ;
struct V_42 * V_43 ;
V_43 = F_25 ( V_39 -> V_44 ) ;
F_64 ( V_39 -> V_45 . V_41 -> V_46 ,
F_62 ( V_43 , V_32 ) ) ;
}
static void
F_66 ( void * V_41 , struct V_98 * V_99 )
{
struct V_38 * V_39 = V_41 ;
struct V_42 * V_43 ;
if ( ! F_67 ( V_39 -> V_45 . V_41 -> V_46 ) )
return;
V_43 = F_25 ( V_39 -> V_44 ) ;
F_64 ( V_39 -> V_45 . V_41 -> V_46 ,
F_62 ( V_43 , V_99 ) ) ;
}
static void
F_68 ( void * V_41 , struct V_98 * V_99 )
{
struct V_38 * V_39 = V_41 ;
struct V_42 * V_43 ;
if ( F_67 ( V_39 -> V_45 . V_41 -> V_46 ) )
return;
V_43 = F_25 ( V_39 -> V_44 ) ;
F_64 ( V_39 -> V_45 . V_41 -> V_46 ,
F_62 ( V_43 , V_104 ) ) ;
}
static void F_69 ( struct V_38 * V_39 )
{
struct V_42 * V_43 ;
struct V_36 * V_65 ;
int V_26 ;
V_43 = F_70 ( V_39 -> V_44 ,
F_71 ( & V_79 ) ) ;
if ( ! V_43 )
return;
F_72 ( F_63 , V_39 ) ;
F_72 ( F_65 , V_39 ) ;
F_73 ( F_66 , V_39 ) ;
F_73 ( F_68 , V_39 ) ;
F_74 ( F_66 , V_39 ) ;
F_74 ( F_68 , V_39 ) ;
F_75 ( F_66 , V_39 ) ;
F_75 ( F_68 , V_39 ) ;
F_6 (file, &tr->events, list) {
F_50 ( V_105 , & V_65 -> V_50 ) ;
}
F_76 (cpu)
F_77 ( V_39 -> V_45 . V_41 , V_26 ) -> V_46 = false ;
F_78 ( V_39 -> V_44 , NULL ) ;
F_79 () ;
F_80 ( ( unsigned long ) V_43 -> V_100 , V_43 -> V_106 ) ;
F_81 ( V_43 ) ;
}
static void F_82 ( struct V_38 * V_39 )
{
F_45 ( & V_79 ) ;
F_69 ( V_39 ) ;
F_52 ( & V_79 ) ;
}
static void F_83 ( struct V_1 * system )
{
struct V_107 * V_108 = system -> V_108 ;
F_84 ( F_1 ( system ) == 0 ) ;
if ( F_3 ( system ) )
return;
F_20 ( & system -> V_109 ) ;
if ( V_108 ) {
F_81 ( V_108 -> V_110 ) ;
F_81 ( V_108 ) ;
}
F_85 ( system -> V_11 ) ;
F_81 ( system ) ;
}
static void F_86 ( struct V_1 * system )
{
F_84 ( F_1 ( system ) == 0 ) ;
F_2 ( system ) ;
}
static void F_87 ( struct V_111 * V_112 )
{
F_84 ( V_112 -> V_2 == 0 ) ;
V_112 -> V_2 ++ ;
F_86 ( V_112 -> V_113 ) ;
}
static void F_88 ( struct V_111 * V_112 )
{
F_84 ( V_112 -> V_2 == 0 ) ;
F_84 ( F_1 ( V_112 -> V_113 ) == 1 && V_112 -> V_2 != 1 ) ;
F_83 ( V_112 -> V_113 ) ;
if ( ! -- V_112 -> V_2 )
F_81 ( V_112 ) ;
}
static void F_89 ( struct V_111 * V_112 )
{
F_45 ( & V_79 ) ;
F_88 ( V_112 ) ;
F_52 ( & V_79 ) ;
}
static void F_90 ( struct V_111 * V_112 )
{
if ( ! V_112 )
return;
if ( ! -- V_112 -> V_114 ) {
F_91 ( V_112 -> V_54 ) ;
F_20 ( & V_112 -> V_109 ) ;
F_88 ( V_112 ) ;
}
}
static void F_92 ( struct V_36 * V_65 )
{
struct V_115 * V_112 = V_65 -> V_112 ;
struct V_115 * V_116 ;
if ( V_112 ) {
F_93 ( & V_112 -> V_117 ) ;
F_6 (child, &dir->d_subdirs, d_child) {
if ( F_94 ( V_116 ) )
F_95 ( V_116 ) -> V_118 = NULL ;
}
F_96 ( & V_112 -> V_117 ) ;
F_91 ( V_112 ) ;
}
F_20 ( & V_65 -> V_109 ) ;
F_90 ( V_65 -> system ) ;
F_97 ( V_65 -> V_108 ) ;
F_21 ( V_119 , V_65 ) ;
}
static int
F_98 ( struct V_38 * V_39 , const char * V_120 ,
const char * V_121 , const char * V_34 , int V_122 )
{
struct V_36 * V_65 ;
struct V_4 * V_13 ;
const char * V_11 ;
int V_25 = - V_123 ;
F_6 (file, &tr->events, list) {
V_13 = V_65 -> V_5 ;
V_11 = F_57 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_90 )
continue;
if ( V_13 -> V_50 & V_124 )
continue;
if ( V_120 &&
strcmp ( V_120 , V_11 ) != 0 &&
strcmp ( V_120 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_121 && strcmp ( V_121 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_34 && strcmp ( V_34 , V_11 ) != 0 )
continue;
F_59 ( V_65 , V_122 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static int F_99 ( struct V_38 * V_39 , const char * V_120 ,
const char * V_121 , const char * V_34 , int V_122 )
{
int V_25 ;
F_45 ( & V_79 ) ;
V_25 = F_98 ( V_39 , V_120 , V_121 , V_34 , V_122 ) ;
F_52 ( & V_79 ) ;
return V_25 ;
}
static int F_100 ( struct V_38 * V_39 , char * V_125 , int V_122 )
{
char * V_34 = NULL , * V_121 = NULL , * V_120 ;
int V_25 ;
V_120 = F_101 ( & V_125 , L_4 ) ;
if ( V_125 ) {
V_121 = V_120 ;
V_34 = V_125 ;
V_120 = NULL ;
if ( ! strlen ( V_121 ) || strcmp ( V_121 , L_5 ) == 0 )
V_121 = NULL ;
if ( ! strlen ( V_34 ) || strcmp ( V_34 , L_5 ) == 0 )
V_34 = NULL ;
}
V_25 = F_99 ( V_39 , V_120 , V_121 , V_34 , V_122 ) ;
if ( V_125 )
* ( V_125 - 1 ) = ':' ;
return V_25 ;
}
int F_102 ( const char * system , const char * V_34 , int V_122 )
{
struct V_38 * V_39 = F_103 () ;
if ( ! V_39 )
return - V_35 ;
return F_99 ( V_39 , NULL , system , V_34 , V_122 ) ;
}
static T_2
F_104 ( struct V_65 * V_65 , const char T_3 * V_126 ,
T_4 V_127 , T_5 * V_128 )
{
struct V_129 V_130 ;
struct V_131 * V_132 = V_65 -> V_133 ;
struct V_38 * V_39 = V_132 -> V_134 ;
T_2 V_135 , V_25 ;
if ( ! V_127 )
return 0 ;
V_25 = F_105 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_106 ( & V_130 , V_136 + 1 ) )
return - V_22 ;
V_135 = F_107 ( & V_130 , V_126 , V_127 , V_128 ) ;
if ( V_135 >= 0 && F_108 ( ( & V_130 ) ) ) {
int V_122 = 1 ;
if ( * V_130 . V_53 == '!' )
V_122 = 0 ;
V_130 . V_53 [ V_130 . V_137 ] = 0 ;
V_25 = F_100 ( V_39 , V_130 . V_53 + ! V_122 , V_122 ) ;
if ( V_25 )
goto V_138;
}
V_25 = V_135 ;
V_138:
F_109 ( & V_130 ) ;
return V_25 ;
}
static void *
F_110 ( struct V_131 * V_132 , void * V_139 , T_5 * V_140 )
{
struct V_36 * V_65 = V_139 ;
struct V_4 * V_13 ;
struct V_38 * V_39 = V_132 -> V_134 ;
( * V_140 ) ++ ;
F_111 (file, &tr->events, list) {
V_13 = V_65 -> V_5 ;
if ( V_13 -> V_6 && V_13 -> V_6 -> V_90 )
return V_65 ;
}
return NULL ;
}
static void * F_112 ( struct V_131 * V_132 , T_5 * V_140 )
{
struct V_36 * V_65 ;
struct V_38 * V_39 = V_132 -> V_134 ;
T_5 V_141 ;
F_45 ( & V_79 ) ;
V_65 = F_113 ( & V_39 -> V_142 , struct V_36 , V_109 ) ;
for ( V_141 = 0 ; V_141 <= * V_140 ; ) {
V_65 = F_110 ( V_132 , V_65 , & V_141 ) ;
if ( ! V_65 )
break;
}
return V_65 ;
}
static void *
F_114 ( struct V_131 * V_132 , void * V_139 , T_5 * V_140 )
{
struct V_36 * V_65 = V_139 ;
struct V_38 * V_39 = V_132 -> V_134 ;
( * V_140 ) ++ ;
F_111 (file, &tr->events, list) {
if ( V_65 -> V_50 & V_80 )
return V_65 ;
}
return NULL ;
}
static void * F_115 ( struct V_131 * V_132 , T_5 * V_140 )
{
struct V_36 * V_65 ;
struct V_38 * V_39 = V_132 -> V_134 ;
T_5 V_141 ;
F_45 ( & V_79 ) ;
V_65 = F_113 ( & V_39 -> V_142 , struct V_36 , V_109 ) ;
for ( V_141 = 0 ; V_141 <= * V_140 ; ) {
V_65 = F_114 ( V_132 , V_65 , & V_141 ) ;
if ( ! V_65 )
break;
}
return V_65 ;
}
static int F_116 ( struct V_131 * V_132 , void * V_139 )
{
struct V_36 * V_65 = V_139 ;
struct V_4 * V_13 = V_65 -> V_5 ;
if ( strcmp ( V_13 -> V_6 -> system , V_143 ) != 0 )
F_117 ( V_132 , L_6 , V_13 -> V_6 -> system ) ;
F_117 ( V_132 , L_3 , F_57 ( V_13 ) ) ;
return 0 ;
}
static void F_118 ( struct V_131 * V_132 , void * V_144 )
{
F_52 ( & V_79 ) ;
}
static void * F_119 ( struct V_131 * V_132 , T_5 * V_140 )
__acquires( T_6 )
{
struct V_42 * V_43 ;
struct V_38 * V_39 = V_132 -> V_134 ;
F_45 ( & V_79 ) ;
F_120 () ;
V_43 = F_25 ( V_39 -> V_44 ) ;
if ( ! V_43 || * V_140 >= V_43 -> V_101 )
return NULL ;
return ( void * ) & V_43 -> V_100 [ * V_140 ] ;
}
static void F_121 ( struct V_131 * V_132 , void * V_144 )
__releases( T_6 )
{
F_122 () ;
F_52 ( & V_79 ) ;
}
static void *
F_123 ( struct V_131 * V_132 , void * V_139 , T_5 * V_140 )
{
struct V_38 * V_39 = V_132 -> V_134 ;
struct V_42 * V_43 = F_25 ( V_39 -> V_44 ) ;
( * V_140 ) ++ ;
if ( * V_140 >= V_43 -> V_101 )
return NULL ;
return ( void * ) & V_43 -> V_100 [ * V_140 ] ;
}
static int F_124 ( struct V_131 * V_132 , void * V_139 )
{
T_1 * V_31 = V_139 ;
F_117 ( V_132 , L_7 , * V_31 ) ;
return 0 ;
}
static T_2
F_125 ( struct V_65 * V_145 , char T_3 * V_126 , T_4 V_127 ,
T_5 * V_128 )
{
struct V_36 * V_65 ;
unsigned long V_50 ;
char V_125 [ 4 ] = L_8 ;
F_45 ( & V_79 ) ;
V_65 = F_126 ( V_145 ) ;
if ( F_127 ( V_65 ) )
V_50 = V_65 -> V_50 ;
F_52 ( & V_79 ) ;
if ( ! V_65 )
return - V_35 ;
if ( V_50 & V_80 &&
! ( V_50 & V_85 ) )
strcpy ( V_125 , L_9 ) ;
if ( V_50 & V_85 ||
V_50 & V_87 )
strcat ( V_125 , L_5 ) ;
strcat ( V_125 , L_10 ) ;
return F_128 ( V_126 , V_127 , V_128 , V_125 , strlen ( V_125 ) ) ;
}
static T_2
F_129 ( struct V_65 * V_145 , const char T_3 * V_126 , T_4 V_127 ,
T_5 * V_128 )
{
struct V_36 * V_65 ;
unsigned long V_146 ;
int V_25 ;
V_25 = F_130 ( V_126 , V_127 , 10 , & V_146 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_105 () ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_146 ) {
case 0 :
case 1 :
V_25 = - V_35 ;
F_45 ( & V_79 ) ;
V_65 = F_126 ( V_145 ) ;
if ( F_127 ( V_65 ) )
V_25 = F_59 ( V_65 , V_146 ) ;
F_52 ( & V_79 ) ;
break;
default:
return - V_123 ;
}
* V_128 += V_127 ;
return V_25 ? V_25 : V_127 ;
}
static T_2
F_131 ( struct V_65 * V_145 , char T_3 * V_126 , T_4 V_127 ,
T_5 * V_128 )
{
const char V_147 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_111 * V_112 = V_145 -> V_133 ;
struct V_1 * system = V_112 -> V_113 ;
struct V_4 * V_13 ;
struct V_36 * V_65 ;
struct V_38 * V_39 = V_112 -> V_39 ;
char V_125 [ 2 ] ;
int V_122 = 0 ;
int V_25 ;
F_45 ( & V_79 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_65 -> V_5 ;
if ( ! F_57 ( V_13 ) || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_90 )
continue;
if ( system && strcmp ( V_13 -> V_6 -> system , system -> V_11 ) != 0 )
continue;
V_122 |= ( 1 << ! ! ( V_65 -> V_50 & V_80 ) ) ;
if ( V_122 == 3 )
break;
}
F_52 ( & V_79 ) ;
V_125 [ 0 ] = V_147 [ V_122 ] ;
V_125 [ 1 ] = '\n' ;
V_25 = F_128 ( V_126 , V_127 , V_128 , V_125 , 2 ) ;
return V_25 ;
}
static T_2
F_132 ( struct V_65 * V_145 , const char T_3 * V_126 , T_4 V_127 ,
T_5 * V_128 )
{
struct V_111 * V_112 = V_145 -> V_133 ;
struct V_1 * system = V_112 -> V_113 ;
const char * V_11 = NULL ;
unsigned long V_146 ;
T_2 V_25 ;
V_25 = F_130 ( V_126 , V_127 , 10 , & V_146 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_105 () ;
if ( V_25 < 0 )
return V_25 ;
if ( V_146 != 0 && V_146 != 1 )
return - V_123 ;
if ( system )
V_11 = system -> V_11 ;
V_25 = F_99 ( V_112 -> V_39 , NULL , V_11 , NULL , V_146 ) ;
if ( V_25 )
goto V_148;
V_25 = V_127 ;
V_148:
* V_128 += V_127 ;
return V_25 ;
}
static void * F_133 ( struct V_131 * V_132 , void * V_139 , T_5 * V_140 )
{
struct V_4 * V_13 = F_126 ( V_132 -> V_134 ) ;
struct V_3 * V_149 = & V_15 ;
struct V_3 * V_10 = F_4 ( V_13 ) ;
struct V_3 * V_150 = V_139 ;
( * V_140 ) ++ ;
switch ( ( unsigned long ) V_139 ) {
case V_151 :
V_150 = V_149 ;
break;
case V_152 :
V_150 = V_10 ;
break;
case V_153 :
return NULL ;
}
V_150 = V_150 -> V_103 ;
if ( V_150 == V_149 )
return ( void * ) V_152 ;
else if ( V_150 == V_10 )
return ( void * ) V_153 ;
else
return V_150 ;
}
static int F_134 ( struct V_131 * V_132 , void * V_139 )
{
struct V_4 * V_13 = F_126 ( V_132 -> V_134 ) ;
struct V_9 * V_12 ;
const char * V_154 ;
switch ( ( unsigned long ) V_139 ) {
case V_151 :
F_117 ( V_132 , L_11 , F_57 ( V_13 ) ) ;
F_117 ( V_132 , L_12 , V_13 -> V_34 . type ) ;
F_135 ( V_132 , L_13 ) ;
return 0 ;
case V_152 :
F_136 ( V_132 , '\n' ) ;
return 0 ;
case V_153 :
F_117 ( V_132 , L_14 ,
V_13 -> V_155 ) ;
return 0 ;
}
V_12 = F_113 ( V_139 , struct V_9 , V_24 ) ;
V_154 = strchr ( V_12 -> type , '[' ) ;
if ( ! strncmp ( V_12 -> type , L_15 , 10 ) )
V_154 = NULL ;
if ( ! V_154 )
F_117 ( V_132 , L_16 ,
V_12 -> type , V_12 -> V_11 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
else
F_117 ( V_132 , L_17 ,
( int ) ( V_154 - V_12 -> type ) ,
V_12 -> type , V_12 -> V_11 ,
V_154 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
return 0 ;
}
static void * F_137 ( struct V_131 * V_132 , T_5 * V_140 )
{
void * V_144 = ( void * ) V_151 ;
T_5 V_141 = 0 ;
F_45 ( & V_79 ) ;
if ( ! F_126 ( V_132 -> V_134 ) )
return F_138 ( - V_35 ) ;
while ( V_141 < * V_140 && V_144 )
V_144 = F_133 ( V_132 , V_144 , & V_141 ) ;
return V_144 ;
}
static void F_139 ( struct V_131 * V_132 , void * V_144 )
{
F_52 ( & V_79 ) ;
}
static int F_140 ( struct V_156 * V_156 , struct V_65 * V_65 )
{
struct V_131 * V_132 ;
int V_25 ;
V_25 = F_141 ( V_65 , & V_157 ) ;
if ( V_25 < 0 )
return V_25 ;
V_132 = V_65 -> V_133 ;
V_132 -> V_134 = V_65 ;
return 0 ;
}
static T_2
F_142 ( struct V_65 * V_145 , char T_3 * V_126 , T_4 V_127 , T_5 * V_128 )
{
int V_33 = ( long ) F_126 ( V_145 ) ;
char V_125 [ 32 ] ;
int V_49 ;
if ( * V_128 )
return 0 ;
if ( F_143 ( ! V_33 ) )
return - V_35 ;
V_49 = sprintf ( V_125 , L_7 , V_33 ) ;
return F_128 ( V_126 , V_127 , V_128 , V_125 , V_49 ) ;
}
static T_2
F_144 ( struct V_65 * V_145 , char T_3 * V_126 , T_4 V_127 ,
T_5 * V_128 )
{
struct V_36 * V_65 ;
struct V_158 * V_159 ;
int V_160 = - V_35 ;
if ( * V_128 )
return 0 ;
V_159 = F_145 ( sizeof( * V_159 ) , V_161 ) ;
if ( ! V_159 )
return - V_22 ;
F_34 ( V_159 ) ;
F_45 ( & V_79 ) ;
V_65 = F_126 ( V_145 ) ;
if ( V_65 )
F_146 ( V_65 , V_159 ) ;
F_52 ( & V_79 ) ;
if ( V_65 )
V_160 = F_128 ( V_126 , V_127 , V_128 ,
V_159 -> V_53 , F_147 ( V_159 ) ) ;
F_81 ( V_159 ) ;
return V_160 ;
}
static T_2
F_148 ( struct V_65 * V_145 , const char T_3 * V_126 , T_4 V_127 ,
T_5 * V_128 )
{
struct V_36 * V_65 ;
char * V_125 ;
int V_162 = - V_35 ;
if ( V_127 >= V_163 )
return - V_123 ;
V_125 = ( char * ) F_149 ( V_164 ) ;
if ( ! V_125 )
return - V_22 ;
if ( F_150 ( V_125 , V_126 , V_127 ) ) {
F_151 ( ( unsigned long ) V_125 ) ;
return - V_165 ;
}
V_125 [ V_127 ] = '\0' ;
F_45 ( & V_79 ) ;
V_65 = F_126 ( V_145 ) ;
if ( V_65 )
V_162 = F_152 ( V_65 , V_125 ) ;
F_52 ( & V_79 ) ;
F_151 ( ( unsigned long ) V_125 ) ;
if ( V_162 < 0 )
return V_162 ;
* V_128 += V_127 ;
return V_127 ;
}
static int F_153 ( struct V_156 * V_156 , struct V_65 * V_145 )
{
struct V_1 * system = NULL ;
struct V_111 * V_112 = NULL ;
struct V_38 * V_39 ;
int V_25 ;
if ( F_154 () )
return - V_35 ;
F_45 ( & V_166 ) ;
F_45 ( & V_79 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_112 == V_156 -> V_118 ) {
if ( V_112 -> V_114 ) {
F_87 ( V_112 ) ;
system = V_112 -> V_113 ;
}
goto V_167;
}
}
}
V_167:
F_52 ( & V_79 ) ;
F_52 ( & V_166 ) ;
if ( ! system )
return - V_35 ;
F_13 ( ! V_112 ) ;
if ( F_155 ( V_39 ) < 0 ) {
F_89 ( V_112 ) ;
return - V_35 ;
}
V_25 = F_156 ( V_156 , V_145 ) ;
if ( V_25 < 0 ) {
F_157 ( V_39 ) ;
F_89 ( V_112 ) ;
}
return V_25 ;
}
static int F_158 ( struct V_156 * V_156 , struct V_65 * V_145 )
{
struct V_111 * V_112 ;
struct V_38 * V_39 = V_156 -> V_118 ;
int V_25 ;
if ( F_154 () )
return - V_35 ;
if ( F_155 ( V_39 ) < 0 )
return - V_35 ;
V_112 = F_159 ( sizeof( * V_112 ) , V_161 ) ;
if ( ! V_112 ) {
F_157 ( V_39 ) ;
return - V_22 ;
}
V_112 -> V_39 = V_39 ;
V_25 = F_156 ( V_156 , V_145 ) ;
if ( V_25 < 0 ) {
F_157 ( V_39 ) ;
F_81 ( V_112 ) ;
return V_25 ;
}
V_145 -> V_133 = V_112 ;
return 0 ;
}
static int F_160 ( struct V_156 * V_156 , struct V_65 * V_65 )
{
struct V_111 * V_112 = V_65 -> V_133 ;
F_157 ( V_112 -> V_39 ) ;
if ( V_112 -> V_113 )
F_89 ( V_112 ) ;
else
F_81 ( V_112 ) ;
return 0 ;
}
static T_2
F_161 ( struct V_65 * V_145 , char T_3 * V_126 , T_4 V_127 ,
T_5 * V_128 )
{
struct V_111 * V_112 = V_145 -> V_133 ;
struct V_1 * system = V_112 -> V_113 ;
struct V_158 * V_159 ;
int V_160 ;
if ( * V_128 )
return 0 ;
V_159 = F_145 ( sizeof( * V_159 ) , V_161 ) ;
if ( ! V_159 )
return - V_22 ;
F_34 ( V_159 ) ;
F_162 ( system , V_159 ) ;
V_160 = F_128 ( V_126 , V_127 , V_128 ,
V_159 -> V_53 , F_147 ( V_159 ) ) ;
F_81 ( V_159 ) ;
return V_160 ;
}
static T_2
F_163 ( struct V_65 * V_145 , const char T_3 * V_126 , T_4 V_127 ,
T_5 * V_128 )
{
struct V_111 * V_112 = V_145 -> V_133 ;
char * V_125 ;
int V_162 ;
if ( V_127 >= V_163 )
return - V_123 ;
V_125 = ( char * ) F_149 ( V_164 ) ;
if ( ! V_125 )
return - V_22 ;
if ( F_150 ( V_125 , V_126 , V_127 ) ) {
F_151 ( ( unsigned long ) V_125 ) ;
return - V_165 ;
}
V_125 [ V_127 ] = '\0' ;
V_162 = F_164 ( V_112 , V_125 ) ;
F_151 ( ( unsigned long ) V_125 ) ;
if ( V_162 < 0 )
return V_162 ;
* V_128 += V_127 ;
return V_127 ;
}
static T_2
F_165 ( struct V_65 * V_145 , char T_3 * V_126 , T_4 V_127 , T_5 * V_128 )
{
int (* F_166)( struct V_158 * V_159 ) = V_145 -> V_133 ;
struct V_158 * V_159 ;
int V_160 ;
if ( * V_128 )
return 0 ;
V_159 = F_145 ( sizeof( * V_159 ) , V_161 ) ;
if ( ! V_159 )
return - V_22 ;
F_34 ( V_159 ) ;
F_166 ( V_159 ) ;
V_160 = F_128 ( V_126 , V_127 , V_128 ,
V_159 -> V_53 , F_147 ( V_159 ) ) ;
F_81 ( V_159 ) ;
return V_160 ;
}
static int F_167 ( struct V_42 * V_43 )
{
return ( V_163 << V_43 -> V_106 ) / sizeof( T_1 ) ;
}
static void F_168 ( void * V_41 )
{
struct V_38 * V_39 = V_41 ;
struct V_42 * V_43 ;
V_43 = F_70 ( V_39 -> V_44 ,
F_169 ( & V_79 ) ) ;
F_64 ( V_39 -> V_45 . V_41 -> V_46 ,
F_62 ( V_43 , V_104 ) ) ;
}
static T_2
F_170 ( struct V_65 * V_145 , const char T_3 * V_126 ,
T_4 V_127 , T_5 * V_128 )
{
struct V_131 * V_132 = V_145 -> V_133 ;
struct V_38 * V_39 = V_132 -> V_134 ;
struct V_42 * V_44 = NULL ;
struct V_42 * V_43 = NULL ;
struct V_36 * V_65 ;
struct V_129 V_130 ;
unsigned long V_146 ;
T_5 V_168 ;
T_2 V_135 = 0 ;
T_2 V_25 = 0 ;
T_1 V_31 ;
int V_169 ;
if ( ! V_127 )
return 0 ;
V_25 = F_105 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_106 ( & V_130 , V_136 + 1 ) )
return - V_22 ;
F_45 ( & V_79 ) ;
while ( V_127 > 0 ) {
V_168 = 0 ;
V_25 = F_107 ( & V_130 , V_126 , V_127 , & V_168 ) ;
if ( V_25 < 0 || ! F_108 ( & V_130 ) )
break;
V_135 += V_25 ;
V_126 += V_25 ;
V_127 -= V_25 ;
V_130 . V_53 [ V_130 . V_137 ] = 0 ;
V_25 = - V_123 ;
if ( F_171 ( V_130 . V_53 , 0 , & V_146 ) )
break;
if ( V_146 > V_170 )
break;
V_31 = ( T_1 ) V_146 ;
V_25 = - V_22 ;
if ( ! V_43 ) {
V_43 = F_145 ( sizeof( * V_43 ) , V_161 ) ;
if ( ! V_43 )
break;
V_44 = F_70 ( V_39 -> V_44 ,
F_71 ( & V_79 ) ) ;
if ( V_44 )
V_43 -> V_106 = V_44 -> V_106 ;
else
V_43 -> V_106 = 0 ;
V_43 -> V_100 = ( void * ) F_172 ( V_161 ,
V_43 -> V_106 ) ;
if ( ! V_43 -> V_100 )
break;
if ( V_44 ) {
V_43 -> V_101 = V_44 -> V_101 ;
memcpy ( V_43 -> V_100 , V_44 -> V_100 ,
V_43 -> V_101 * sizeof( T_1 ) ) ;
} else
V_43 -> V_101 = 0 ;
}
if ( V_43 -> V_101 >= F_167 ( V_43 ) ) {
T_1 * V_171 ;
V_171 = ( void * ) F_172 ( V_161 ,
V_43 -> V_106 + 1 ) ;
if ( ! V_171 )
break;
memcpy ( V_171 , V_43 -> V_100 ,
V_43 -> V_101 * sizeof( T_1 ) ) ;
F_80 ( ( unsigned long ) V_43 -> V_100 , V_43 -> V_106 ) ;
V_43 -> V_106 ++ ;
V_43 -> V_100 = V_171 ;
}
V_43 -> V_100 [ V_43 -> V_101 ++ ] = V_31 ;
F_173 ( & V_130 ) ;
V_25 = 0 ;
}
F_109 ( & V_130 ) ;
if ( V_25 < 0 ) {
if ( V_43 )
F_80 ( ( unsigned long ) V_43 -> V_100 , V_43 -> V_106 ) ;
F_81 ( V_43 ) ;
F_52 ( & V_79 ) ;
return V_25 ;
}
if ( ! V_43 ) {
F_52 ( & V_79 ) ;
return V_25 ;
}
F_174 ( V_43 -> V_100 , V_43 -> V_101 , sizeof( T_1 ) , F_61 , NULL ) ;
for ( V_169 = 1 ; V_169 < V_43 -> V_101 ; V_169 ++ ) {
int V_172 = V_169 ;
while ( V_169 < V_43 -> V_101 &&
V_43 -> V_100 [ V_169 - 1 ] == V_43 -> V_100 [ V_169 ] )
V_169 ++ ;
if ( V_172 != V_169 ) {
if ( V_169 < V_43 -> V_101 ) {
memmove ( & V_43 -> V_100 [ V_172 ] , & V_43 -> V_100 [ V_169 ] ,
( V_43 -> V_101 - V_169 ) * sizeof( T_1 ) ) ;
V_43 -> V_101 -= V_169 - V_172 ;
V_169 = V_172 ;
} else
V_43 -> V_101 = V_172 ;
}
}
F_78 ( V_39 -> V_44 , V_43 ) ;
F_6 (file, &tr->events, list) {
F_48 ( V_105 , & V_65 -> V_50 ) ;
}
if ( V_44 ) {
F_79 () ;
F_80 ( ( unsigned long ) V_44 -> V_100 , V_44 -> V_106 ) ;
F_81 ( V_44 ) ;
} else {
F_175 ( F_63 ,
V_39 , V_170 ) ;
F_175 ( F_65 ,
V_39 , 0 ) ;
F_176 ( F_66 ,
V_39 , V_170 ) ;
F_176 ( F_68 ,
V_39 , 0 ) ;
F_177 ( F_66 ,
V_39 , V_170 ) ;
F_177 ( F_68 ,
V_39 , 0 ) ;
F_178 ( F_66 ,
V_39 , V_170 ) ;
F_178 ( F_68 ,
V_39 , 0 ) ;
}
F_179 ( F_168 , V_39 , 1 ) ;
F_52 ( & V_79 ) ;
V_25 = V_135 ;
* V_128 += V_135 ;
return V_25 ;
}
static int
F_180 ( struct V_156 * V_156 , struct V_65 * V_65 ,
const struct V_173 * V_174 )
{
struct V_131 * V_132 ;
int V_25 ;
V_25 = F_141 ( V_65 , V_174 ) ;
if ( V_25 < 0 )
return V_25 ;
V_132 = V_65 -> V_133 ;
V_132 -> V_134 = V_156 -> V_118 ;
return V_25 ;
}
static int F_181 ( struct V_156 * V_156 , struct V_65 * V_65 )
{
struct V_38 * V_39 = V_156 -> V_118 ;
F_157 ( V_39 ) ;
return F_182 ( V_156 , V_65 ) ;
}
static int
F_183 ( struct V_156 * V_156 , struct V_65 * V_65 )
{
const struct V_173 * V_174 = & V_175 ;
return F_180 ( V_156 , V_65 , V_174 ) ;
}
static int
F_184 ( struct V_156 * V_156 , struct V_65 * V_65 )
{
const struct V_173 * V_174 = & V_176 ;
struct V_38 * V_39 = V_156 -> V_118 ;
int V_25 ;
if ( F_155 ( V_39 ) < 0 )
return - V_35 ;
if ( ( V_65 -> V_177 & V_178 ) &&
( V_65 -> V_179 & V_180 ) )
F_60 ( V_39 ) ;
V_25 = F_180 ( V_156 , V_65 , V_174 ) ;
if ( V_25 < 0 )
F_157 ( V_39 ) ;
return V_25 ;
}
static int
F_185 ( struct V_156 * V_156 , struct V_65 * V_65 )
{
const struct V_173 * V_174 = & V_181 ;
struct V_38 * V_39 = V_156 -> V_118 ;
int V_25 ;
if ( F_155 ( V_39 ) < 0 )
return - V_35 ;
if ( ( V_65 -> V_177 & V_178 ) &&
( V_65 -> V_179 & V_180 ) )
F_82 ( V_39 ) ;
V_25 = F_180 ( V_156 , V_65 , V_174 ) ;
if ( V_25 < 0 )
F_157 ( V_39 ) ;
return V_25 ;
}
static struct V_1 *
F_186 ( const char * V_11 )
{
struct V_1 * system ;
system = F_145 ( sizeof( * system ) , V_161 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
system -> V_11 = F_187 ( V_11 , V_161 ) ;
if ( ! system -> V_11 )
goto V_182;
system -> V_108 = NULL ;
system -> V_108 = F_159 ( sizeof( struct V_107 ) , V_161 ) ;
if ( ! system -> V_108 )
goto V_182;
F_11 ( & system -> V_109 , & V_183 ) ;
return system ;
V_182:
F_85 ( system -> V_11 ) ;
F_81 ( system ) ;
return NULL ;
}
static struct V_115 *
F_188 ( struct V_38 * V_39 , const char * V_11 ,
struct V_36 * V_65 , struct V_115 * V_184 )
{
struct V_111 * V_112 ;
struct V_1 * system ;
struct V_115 * V_54 ;
F_6 (dir, &tr->systems, list) {
system = V_112 -> V_113 ;
if ( strcmp ( system -> V_11 , V_11 ) == 0 ) {
V_112 -> V_114 ++ ;
V_65 -> system = V_112 ;
return V_112 -> V_54 ;
}
}
F_6 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_11 , V_11 ) == 0 )
break;
}
if ( & system -> V_109 == & V_183 )
system = NULL ;
V_112 = F_145 ( sizeof( * V_112 ) , V_161 ) ;
if ( ! V_112 )
goto V_185;
if ( ! system ) {
system = F_186 ( V_11 ) ;
if ( ! system )
goto V_182;
} else
F_86 ( system ) ;
V_112 -> V_54 = F_189 ( V_11 , V_184 ) ;
if ( ! V_112 -> V_54 ) {
F_190 ( L_18 , V_11 ) ;
F_83 ( system ) ;
goto V_182;
}
V_112 -> V_39 = V_39 ;
V_112 -> V_2 = 1 ;
V_112 -> V_114 = 1 ;
V_112 -> V_113 = system ;
V_65 -> system = V_112 ;
V_54 = F_191 ( L_19 , 0644 , V_112 -> V_54 , V_112 ,
& V_186 ) ;
if ( ! V_54 ) {
F_81 ( system -> V_108 ) ;
system -> V_108 = NULL ;
F_190 ( L_20 , V_11 ) ;
}
F_192 ( L_21 , 0644 , V_112 -> V_54 , V_112 ,
& V_187 ) ;
F_11 ( & V_112 -> V_109 , & V_39 -> V_188 ) ;
return V_112 -> V_54 ;
V_182:
F_81 ( V_112 ) ;
V_185:
if ( ! V_112 || ! system )
F_190 ( L_22 , V_11 ) ;
return NULL ;
}
static int
F_193 ( struct V_115 * V_184 , struct V_36 * V_65 )
{
struct V_4 * V_13 = V_65 -> V_5 ;
struct V_38 * V_39 = V_65 -> V_39 ;
struct V_3 * V_10 ;
struct V_115 * V_189 ;
const char * V_11 ;
int V_25 ;
if ( strcmp ( V_13 -> V_6 -> system , V_143 ) != 0 ) {
V_189 = F_188 ( V_39 , V_13 -> V_6 -> system , V_65 , V_184 ) ;
if ( ! V_189 )
return - V_22 ;
} else
V_189 = V_184 ;
V_11 = F_57 ( V_13 ) ;
V_65 -> V_112 = F_189 ( V_11 , V_189 ) ;
if ( ! V_65 -> V_112 ) {
F_190 ( L_23 , V_11 ) ;
return - 1 ;
}
if ( V_13 -> V_6 -> V_90 && ! ( V_13 -> V_50 & V_124 ) )
F_192 ( L_21 , 0644 , V_65 -> V_112 , V_65 ,
& V_190 ) ;
#ifdef F_43
if ( V_13 -> V_34 . type && V_13 -> V_6 -> V_90 )
F_192 ( L_24 , 0444 , V_65 -> V_112 ,
( void * ) ( long ) V_13 -> V_34 . type ,
& V_191 ) ;
#endif
V_10 = F_4 ( V_13 ) ;
if ( F_194 ( V_10 ) ) {
V_25 = V_13 -> V_6 -> V_192 ( V_13 ) ;
if ( V_25 < 0 ) {
F_190 ( L_25 ,
V_11 ) ;
return - 1 ;
}
}
F_192 ( L_19 , 0644 , V_65 -> V_112 , V_65 ,
& V_193 ) ;
F_192 ( L_26 , 0644 , V_65 -> V_112 , V_65 ,
& V_194 ) ;
F_192 ( L_27 , 0444 , V_65 -> V_112 , V_13 ,
& V_195 ) ;
return 0 ;
}
static void F_195 ( struct V_4 * V_13 )
{
struct V_36 * V_65 ;
struct V_38 * V_39 ;
F_196 (tr, file) {
if ( V_65 -> V_5 != V_13 )
continue;
F_92 ( V_65 ) ;
break;
} F_51 () ;
}
static void F_197 ( struct V_4 * V_13 )
{
struct V_38 * V_39 ;
struct V_36 * V_65 ;
F_46 (tr, file) {
if ( V_65 -> V_5 != V_13 )
continue;
F_59 ( V_65 , 0 ) ;
break;
} F_51 () ;
if ( V_13 -> V_34 . V_59 )
F_198 ( & V_13 -> V_34 ) ;
F_195 ( V_13 ) ;
F_20 ( & V_13 -> V_109 ) ;
}
static int F_199 ( struct V_4 * V_13 )
{
int V_25 = 0 ;
const char * V_11 ;
V_11 = F_57 ( V_13 ) ;
if ( F_13 ( ! V_11 ) )
return - V_123 ;
if ( V_13 -> V_6 -> V_196 ) {
V_25 = V_13 -> V_6 -> V_196 ( V_13 ) ;
if ( V_25 < 0 && V_25 != - V_197 )
F_190 ( L_28 , V_11 ) ;
}
return V_25 ;
}
static int
F_200 ( struct V_4 * V_13 , struct V_198 * V_199 )
{
int V_25 ;
V_25 = F_199 ( V_13 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_13 -> V_109 , & V_200 ) ;
V_13 -> V_199 = V_199 ;
return 0 ;
}
static char * F_201 ( char * V_201 , struct V_202 * V_203 , int V_49 )
{
int V_204 ;
int V_205 ;
V_205 = snprintf ( V_201 , 0 , L_29 , V_203 -> V_206 ) ;
if ( V_49 < V_205 )
return NULL ;
snprintf ( V_201 , V_205 + 1 , L_29 , V_203 -> V_206 ) ;
V_204 = strlen ( V_201 + V_49 ) ;
memmove ( V_201 + V_205 , V_201 + V_49 , V_204 ) ;
V_201 [ V_205 + V_204 ] = 0 ;
return V_201 + V_205 ;
}
static void F_202 ( struct V_4 * V_13 ,
struct V_202 * V_203 )
{
char * V_201 ;
int V_207 = 0 ;
int V_49 = strlen ( V_203 -> V_208 ) ;
for ( V_201 = V_13 -> V_155 ; * V_201 ; V_201 ++ ) {
if ( * V_201 == '\\' ) {
V_201 ++ ;
if ( ! * V_201 )
break;
continue;
}
if ( * V_201 == '"' ) {
V_207 ^= 1 ;
continue;
}
if ( V_207 )
continue;
if ( isdigit ( * V_201 ) ) {
do {
V_201 ++ ;
} while ( isalnum ( * V_201 ) );
if ( ! * V_201 )
break;
continue;
}
if ( isalpha ( * V_201 ) || * V_201 == '_' ) {
if ( strncmp ( V_203 -> V_208 , V_201 , V_49 ) == 0 &&
! isalnum ( V_201 [ V_49 ] ) && V_201 [ V_49 ] != '_' ) {
V_201 = F_201 ( V_201 , V_203 , V_49 ) ;
if ( F_84 ( ! V_201 ) )
return;
continue;
}
V_209:
do {
V_201 ++ ;
} while ( isalnum ( * V_201 ) || * V_201 == '_' );
if ( ! * V_201 )
break;
if ( * V_201 == '.' || ( V_201 [ 0 ] == '-' && V_201 [ 1 ] == '>' ) ) {
V_201 += * V_201 == '.' ? 1 : 2 ;
if ( ! * V_201 )
break;
goto V_209;
}
continue;
}
}
}
void F_203 ( struct V_202 * * V_203 , int V_49 )
{
struct V_4 * V_13 , * V_144 ;
const char * V_210 = NULL ;
int V_211 ;
int V_169 ;
F_204 ( & V_212 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( ! V_210 || V_13 -> V_6 -> system != V_210 ) {
V_211 = 0 ;
V_210 = V_13 -> V_6 -> system ;
}
for ( V_169 = V_211 ; V_169 < V_49 ; V_169 ++ ) {
if ( V_13 -> V_6 -> system == V_203 [ V_169 ] -> system ) {
if ( ! V_211 )
V_211 = V_169 ;
F_202 ( V_13 , V_203 [ V_169 ] ) ;
}
}
}
F_205 ( & V_212 ) ;
}
static struct V_36 *
F_206 ( struct V_4 * V_13 ,
struct V_38 * V_39 )
{
struct V_36 * V_65 ;
V_65 = F_9 ( V_119 , V_21 ) ;
if ( ! V_65 )
return NULL ;
V_65 -> V_5 = V_13 ;
V_65 -> V_39 = V_39 ;
F_207 ( & V_65 -> V_84 , 0 ) ;
F_207 ( & V_65 -> V_213 , 0 ) ;
F_208 ( & V_65 -> V_214 ) ;
F_11 ( & V_65 -> V_109 , & V_39 -> V_142 ) ;
return V_65 ;
}
static int
F_209 ( struct V_4 * V_13 , struct V_38 * V_39 )
{
struct V_36 * V_65 ;
V_65 = F_206 ( V_13 , V_39 ) ;
if ( ! V_65 )
return - V_22 ;
return F_193 ( V_39 -> V_215 , V_65 ) ;
}
static T_7 int
F_210 ( struct V_4 * V_13 ,
struct V_38 * V_39 )
{
struct V_36 * V_65 ;
V_65 = F_206 ( V_13 , V_39 ) ;
if ( ! V_65 )
return - V_22 ;
return 0 ;
}
int F_211 ( struct V_4 * V_13 )
{
int V_25 ;
F_45 ( & V_166 ) ;
F_45 ( & V_79 ) ;
V_25 = F_200 ( V_13 , NULL ) ;
if ( V_25 >= 0 )
F_212 ( V_13 ) ;
F_52 ( & V_79 ) ;
F_52 ( & V_166 ) ;
return V_25 ;
}
static void F_213 ( struct V_4 * V_13 )
{
F_197 ( V_13 ) ;
F_18 ( V_13 ) ;
F_97 ( V_13 -> V_108 ) ;
V_13 -> V_108 = NULL ;
}
static int F_214 ( struct V_4 * V_13 )
{
struct V_38 * V_39 ;
struct V_36 * V_65 ;
#ifdef F_43
if ( V_13 -> V_216 )
return - V_217 ;
#endif
F_46 (tr, file) {
if ( V_65 -> V_5 != V_13 )
continue;
if ( V_65 -> V_50 & V_80 )
return - V_217 ;
break;
} F_51 () ;
F_213 ( V_13 ) ;
return 0 ;
}
int F_215 ( struct V_4 * V_13 )
{
int V_25 ;
F_45 ( & V_166 ) ;
F_45 ( & V_79 ) ;
F_204 ( & V_212 ) ;
V_25 = F_214 ( V_13 ) ;
F_205 ( & V_212 ) ;
F_52 ( & V_79 ) ;
F_52 ( & V_166 ) ;
return V_25 ;
}
static void F_216 ( struct V_198 * V_199 )
{
struct V_4 * * V_13 , * * V_172 , * * V_218 ;
if ( ! V_199 -> V_219 )
return;
if ( F_217 ( V_199 ) ) {
F_218 ( L_30 ,
V_199 -> V_11 ) ;
return;
}
V_172 = V_199 -> V_220 ;
V_218 = V_199 -> V_220 + V_199 -> V_219 ;
F_219 (call, start, end) {
F_200 ( * V_13 , V_199 ) ;
F_212 ( * V_13 ) ;
}
}
static void F_220 ( struct V_198 * V_199 )
{
struct V_4 * V_13 , * V_144 ;
bool V_221 = false ;
F_204 ( & V_212 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( V_13 -> V_199 == V_199 ) {
if ( V_13 -> V_50 & V_94 )
V_221 = true ;
F_213 ( V_13 ) ;
}
}
F_205 ( & V_212 ) ;
if ( V_221 )
F_221 () ;
}
static int F_222 ( struct V_222 * V_223 ,
unsigned long V_146 , void * V_41 )
{
struct V_198 * V_199 = V_41 ;
F_45 ( & V_166 ) ;
F_45 ( & V_79 ) ;
switch ( V_146 ) {
case V_224 :
F_216 ( V_199 ) ;
break;
case V_225 :
F_220 ( V_199 ) ;
break;
}
F_52 ( & V_79 ) ;
F_52 ( & V_166 ) ;
return 0 ;
}
static void
F_223 ( struct V_38 * V_39 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
V_25 = F_209 ( V_13 , V_39 ) ;
if ( V_25 < 0 )
F_190 ( L_31 ,
F_57 ( V_13 ) ) ;
}
}
struct V_36 *
F_224 ( struct V_38 * V_39 , const char * system , const char * V_34 )
{
struct V_36 * V_65 ;
struct V_4 * V_13 ;
const char * V_11 ;
F_6 (file, &tr->events, list) {
V_13 = V_65 -> V_5 ;
V_11 = F_57 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_90 )
continue;
if ( V_13 -> V_50 & V_124 )
continue;
if ( strcmp ( V_34 , V_11 ) == 0 &&
strcmp ( system , V_13 -> V_6 -> system ) == 0 )
return V_65 ;
}
return NULL ;
}
static void
F_225 ( unsigned long V_226 , unsigned long V_227 , void * * V_228 )
{
struct V_229 * * V_230 = (struct V_229 * * ) V_228 ;
struct V_229 * V_41 = * V_230 ;
if ( ! V_41 )
return;
if ( V_41 -> V_78 )
F_50 ( V_91 , & V_41 -> V_65 -> V_50 ) ;
else
F_48 ( V_91 , & V_41 -> V_65 -> V_50 ) ;
}
static void
F_226 ( unsigned long V_226 , unsigned long V_227 , void * * V_228 )
{
struct V_229 * * V_230 = (struct V_229 * * ) V_228 ;
struct V_229 * V_41 = * V_230 ;
if ( ! V_41 )
return;
if ( ! V_41 -> V_231 )
return;
if ( V_41 -> V_78 == ! ( V_41 -> V_65 -> V_50 & V_85 ) )
return;
if ( V_41 -> V_231 != - 1 )
( V_41 -> V_231 ) -- ;
F_225 ( V_226 , V_227 , V_228 ) ;
}
static int
F_227 ( struct V_131 * V_132 , unsigned long V_226 ,
struct V_232 * V_233 , void * V_228 )
{
struct V_229 * V_41 = V_228 ;
F_117 ( V_132 , L_32 , ( void * ) V_226 ) ;
F_117 ( V_132 , L_33 ,
V_41 -> V_78 ? V_234 : V_235 ,
V_41 -> V_65 -> V_5 -> V_6 -> system ,
F_57 ( V_41 -> V_65 -> V_5 ) ) ;
if ( V_41 -> V_231 == - 1 )
F_135 ( V_132 , L_34 ) ;
else
F_117 ( V_132 , L_35 , V_41 -> V_231 ) ;
return 0 ;
}
static int
F_228 ( struct V_232 * V_233 , unsigned long V_226 ,
void * * V_228 )
{
struct V_229 * * V_230 = (struct V_229 * * ) V_228 ;
struct V_229 * V_41 = * V_230 ;
V_41 -> V_236 ++ ;
return 0 ;
}
static void
F_229 ( struct V_232 * V_233 , unsigned long V_226 ,
void * * V_228 )
{
struct V_229 * * V_230 = (struct V_229 * * ) V_228 ;
struct V_229 * V_41 = * V_230 ;
if ( F_84 ( V_41 -> V_236 <= 0 ) )
return;
V_41 -> V_236 -- ;
if ( ! V_41 -> V_236 ) {
F_53 ( V_41 -> V_65 , 0 , 1 ) ;
F_230 ( V_41 -> V_65 -> V_5 -> V_199 ) ;
F_81 ( V_41 ) ;
}
* V_230 = NULL ;
}
static int
F_231 ( struct V_237 * V_238 ,
char * V_239 , char * V_240 , char * V_241 , int V_242 )
{
struct V_38 * V_39 = F_103 () ;
struct V_36 * V_65 ;
struct V_232 * V_233 ;
struct V_229 * V_41 ;
const char * system ;
const char * V_34 ;
char * V_243 ;
bool V_78 ;
int V_25 ;
if ( ! V_39 )
return - V_35 ;
if ( ! V_242 || ! V_241 )
return - V_123 ;
system = F_101 ( & V_241 , L_4 ) ;
if ( ! V_241 )
return - V_123 ;
V_34 = F_101 ( & V_241 , L_4 ) ;
F_45 ( & V_79 ) ;
V_25 = - V_123 ;
V_65 = F_224 ( V_39 , system , V_34 ) ;
if ( ! V_65 )
goto V_148;
V_78 = strcmp ( V_240 , V_234 ) == 0 ;
if ( V_78 )
V_233 = V_241 ? & V_244 : & V_245 ;
else
V_233 = V_241 ? & V_246 : & V_247 ;
if ( V_239 [ 0 ] == '!' ) {
F_232 ( V_239 + 1 , V_233 ) ;
V_25 = 0 ;
goto V_148;
}
V_25 = - V_22 ;
V_41 = F_159 ( sizeof( * V_41 ) , V_161 ) ;
if ( ! V_41 )
goto V_148;
V_41 -> V_78 = V_78 ;
V_41 -> V_231 = - 1 ;
V_41 -> V_65 = V_65 ;
if ( ! V_241 )
goto V_248;
V_243 = F_101 ( & V_241 , L_4 ) ;
V_25 = - V_123 ;
if ( ! strlen ( V_243 ) )
goto V_182;
V_25 = F_171 ( V_243 , 0 , & V_41 -> V_231 ) ;
if ( V_25 )
goto V_182;
V_248:
V_25 = F_233 ( V_65 -> V_5 -> V_199 ) ;
if ( ! V_25 ) {
V_25 = - V_217 ;
goto V_182;
}
V_25 = F_53 ( V_65 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_138;
V_25 = F_234 ( V_239 , V_233 , V_41 ) ;
if ( ! V_25 ) {
V_25 = - V_249 ;
goto V_250;
} else if ( V_25 < 0 )
goto V_250;
V_25 = 0 ;
V_148:
F_52 ( & V_79 ) ;
return V_25 ;
V_250:
F_53 ( V_65 , 0 , 1 ) ;
V_138:
F_230 ( V_65 -> V_5 -> V_199 ) ;
V_182:
F_81 ( V_41 ) ;
goto V_148;
}
static T_7 int F_235 ( void )
{
int V_25 ;
V_25 = F_236 ( & V_251 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_236 ( & V_252 ) ;
if ( F_13 ( V_25 < 0 ) )
F_237 ( & V_251 ) ;
return V_25 ;
}
static inline int F_235 ( void ) { return 0 ; }
static T_7 void
F_238 ( struct V_38 * V_39 )
{
struct V_36 * V_65 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_193 ( V_39 -> V_215 , V_65 ) ;
if ( V_25 < 0 )
F_190 ( L_31 ,
F_57 ( V_65 -> V_5 ) ) ;
}
}
static T_7 void
F_239 ( struct V_38 * V_39 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_84 ( V_13 -> V_199 ) )
continue;
V_25 = F_210 ( V_13 , V_39 ) ;
if ( V_25 < 0 )
F_190 ( L_36 ,
F_57 ( V_13 ) ) ;
}
}
static void
F_240 ( struct V_38 * V_39 )
{
struct V_36 * V_65 , * V_32 ;
F_19 (file, next, &tr->events, list)
F_92 ( V_65 ) ;
}
static void F_212 ( struct V_4 * V_13 )
{
struct V_38 * V_39 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_209 ( V_13 , V_39 ) ;
}
static T_7 int F_241 ( char * V_253 )
{
F_242 ( V_254 , V_253 , V_255 ) ;
V_256 = true ;
V_257 = true ;
return 1 ;
}
static int
F_243 ( struct V_115 * V_184 , struct V_38 * V_39 )
{
struct V_115 * V_189 ;
struct V_115 * V_54 ;
V_54 = F_191 ( L_37 , 0644 , V_184 ,
V_39 , & V_258 ) ;
if ( ! V_54 ) {
F_190 ( L_38 ) ;
return - V_22 ;
}
V_189 = F_189 ( L_39 , V_184 ) ;
if ( ! V_189 ) {
F_190 ( L_40 ) ;
return - V_22 ;
}
V_54 = F_191 ( L_41 , 0644 , V_184 ,
V_39 , & V_259 ) ;
F_192 ( L_42 , 0444 , V_189 ,
V_260 ,
& V_261 ) ;
F_192 ( L_43 , 0444 , V_189 ,
V_262 ,
& V_261 ) ;
F_192 ( L_21 , 0644 , V_189 ,
V_39 , & V_263 ) ;
V_39 -> V_215 = V_189 ;
return 0 ;
}
int F_244 ( struct V_115 * V_184 , struct V_38 * V_39 )
{
int V_25 ;
F_45 ( & V_79 ) ;
V_25 = F_243 ( V_184 , V_39 ) ;
if ( V_25 )
goto V_264;
F_204 ( & V_212 ) ;
F_223 ( V_39 ) ;
F_205 ( & V_212 ) ;
V_264:
F_52 ( & V_79 ) ;
return V_25 ;
}
static T_7 int
F_245 ( struct V_115 * V_184 , struct V_38 * V_39 )
{
int V_25 ;
F_45 ( & V_79 ) ;
V_25 = F_243 ( V_184 , V_39 ) ;
if ( V_25 )
goto V_264;
F_204 ( & V_212 ) ;
F_238 ( V_39 ) ;
F_205 ( & V_212 ) ;
V_264:
F_52 ( & V_79 ) ;
return V_25 ;
}
int F_246 ( struct V_38 * V_39 )
{
F_45 ( & V_79 ) ;
F_247 ( V_39 ) ;
F_69 ( V_39 ) ;
F_98 ( V_39 , NULL , NULL , NULL , 0 ) ;
F_79 () ;
F_204 ( & V_212 ) ;
F_240 ( V_39 ) ;
F_91 ( V_39 -> V_215 ) ;
F_205 ( & V_212 ) ;
V_39 -> V_215 = NULL ;
F_52 ( & V_79 ) ;
return 0 ;
}
static T_7 int F_248 ( void )
{
V_20 = F_249 ( V_9 , V_265 ) ;
V_119 = F_249 ( V_36 , V_265 ) ;
return 0 ;
}
static T_7 void
F_250 ( struct V_38 * V_39 , bool V_266 )
{
char * V_125 = V_254 ;
char * V_267 ;
int V_25 ;
while ( true ) {
V_267 = F_101 ( & V_125 , L_44 ) ;
if ( ! V_267 )
break;
if ( * V_267 ) {
if ( V_266 )
F_100 ( V_39 , V_267 , 0 ) ;
V_25 = F_100 ( V_39 , V_267 , 1 ) ;
if ( V_25 )
F_190 ( L_45 , V_267 ) ;
}
if ( V_125 )
* ( V_125 - 1 ) = ',' ;
}
}
static T_7 int F_251 ( void )
{
struct V_38 * V_39 = F_103 () ;
struct V_4 * * V_57 , * V_13 ;
int V_25 ;
if ( ! V_39 )
return - V_35 ;
F_219 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_13 = * V_57 ;
V_25 = F_199 ( V_13 ) ;
if ( ! V_25 )
F_11 ( & V_13 -> V_109 , & V_200 ) ;
}
F_239 ( V_39 ) ;
F_250 ( V_39 , false ) ;
F_252 () ;
F_235 () ;
F_253 () ;
return 0 ;
}
static T_7 int F_254 ( void )
{
struct V_38 * V_39 ;
V_39 = F_103 () ;
if ( ! V_39 )
return - V_35 ;
F_250 ( V_39 , true ) ;
return 0 ;
}
static T_7 int F_255 ( void )
{
struct V_38 * V_39 ;
struct V_115 * V_268 ;
struct V_115 * V_54 ;
int V_25 ;
V_39 = F_103 () ;
if ( ! V_39 )
return - V_35 ;
V_268 = F_256 () ;
if ( F_257 ( V_268 ) )
return 0 ;
V_54 = F_191 ( L_46 , 0444 , V_268 ,
V_39 , & V_269 ) ;
if ( ! V_54 )
F_190 ( L_47 ) ;
if ( F_14 () )
F_190 ( L_48 ) ;
if ( F_16 () )
F_190 ( L_49 ) ;
V_25 = F_245 ( V_268 , V_39 ) ;
if ( V_25 )
return V_25 ;
#ifdef F_258
V_25 = F_259 ( & V_270 ) ;
if ( V_25 )
F_190 ( L_50 ) ;
#endif
return 0 ;
}
void T_7 F_260 ( void )
{
F_248 () ;
F_261 () ;
F_251 () ;
}
static T_7 void F_262 ( struct V_271 * V_272 )
{
F_93 ( & V_273 ) ;
F_263 ( & V_274 ) ;
F_264 ( 1 ) ;
F_265 ( & V_274 ) ;
F_96 ( & V_273 ) ;
F_45 ( & V_275 ) ;
F_266 ( 1 ) ;
F_52 ( & V_275 ) ;
}
static T_7 int F_267 ( void * V_276 )
{
void * V_277 ;
V_277 = F_145 ( 1234 , V_161 ) ;
if ( ! V_277 )
F_56 ( L_51 ) ;
F_268 ( F_262 ) ;
F_81 ( V_277 ) ;
F_269 ( V_278 ) ;
while ( ! F_270 () ) {
F_271 () ;
F_269 ( V_278 ) ;
}
F_272 ( V_279 ) ;
return 0 ;
}
static T_7 void F_273 ( void )
{
struct V_98 * V_280 ;
V_280 = F_274 ( F_267 , NULL , L_52 ) ;
F_266 ( 1 ) ;
F_275 ( V_280 ) ;
}
static T_7 void F_276 ( void )
{
struct V_111 * V_112 ;
struct V_36 * V_65 ;
struct V_4 * V_13 ;
struct V_1 * system ;
struct V_38 * V_39 ;
int V_25 ;
V_39 = F_103 () ;
if ( ! V_39 )
return;
F_56 ( L_53 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_65 -> V_5 ;
if ( ! V_13 -> V_6 || ! V_13 -> V_6 -> V_69 )
continue;
#ifndef F_277
if ( V_13 -> V_6 -> system &&
strcmp ( V_13 -> V_6 -> system , L_54 ) == 0 )
continue;
#endif
F_56 ( L_55 , F_57 ( V_13 ) ) ;
if ( V_65 -> V_50 & V_80 ) {
F_190 ( L_56 ) ;
F_84 ( 1 ) ;
continue;
}
F_59 ( V_65 , 1 ) ;
F_273 () ;
F_59 ( V_65 , 0 ) ;
F_278 ( L_57 ) ;
}
F_56 ( L_58 ) ;
F_6 (dir, &tr->systems, list) {
system = V_112 -> V_113 ;
if ( strcmp ( system -> V_11 , L_59 ) == 0 )
continue;
F_56 ( L_60 , system -> V_11 ) ;
V_25 = F_99 ( V_39 , NULL , system -> V_11 , NULL , 1 ) ;
if ( F_84 ( V_25 ) ) {
F_190 ( L_61 ,
system -> V_11 ) ;
continue;
}
F_273 () ;
V_25 = F_99 ( V_39 , NULL , system -> V_11 , NULL , 0 ) ;
if ( F_84 ( V_25 ) ) {
F_190 ( L_62 ,
system -> V_11 ) ;
continue;
}
F_278 ( L_57 ) ;
}
F_56 ( L_63 ) ;
F_56 ( L_64 ) ;
V_25 = F_99 ( V_39 , NULL , NULL , NULL , 1 ) ;
if ( F_84 ( V_25 ) ) {
F_190 ( L_65 ) ;
return;
}
F_273 () ;
V_25 = F_99 ( V_39 , NULL , NULL , NULL , 0 ) ;
if ( F_84 ( V_25 ) ) {
F_190 ( L_66 ) ;
return;
}
F_278 ( L_57 ) ;
}
static void T_7
F_279 ( unsigned long V_226 , unsigned long V_227 ,
struct V_281 * V_282 , struct V_283 * V_283 )
{
struct V_284 * V_34 ;
struct V_285 * V_53 ;
struct V_286 * V_54 ;
unsigned long V_50 ;
long V_287 ;
int V_26 ;
int V_52 ;
V_52 = F_29 () ;
F_280 () ;
V_26 = F_281 () ;
V_287 = F_55 ( & F_282 ( V_288 , V_26 ) ) ;
if ( V_287 != 1 )
goto V_148;
F_28 ( V_50 ) ;
V_34 = F_283 ( & V_53 ,
V_289 , sizeof( * V_54 ) ,
V_50 , V_52 ) ;
if ( ! V_34 )
goto V_148;
V_54 = F_31 ( V_34 ) ;
V_54 -> V_226 = V_226 ;
V_54 -> V_227 = V_227 ;
F_284 ( V_290 , V_53 , V_34 , V_50 , V_52 ) ;
V_148:
F_285 ( & F_282 ( V_288 , V_26 ) ) ;
F_286 () ;
}
static T_7 void F_287 ( void )
{
int V_25 ;
V_290 = F_103 () ;
if ( F_13 ( ! V_290 ) )
return;
V_25 = F_288 ( & V_291 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_56 ( L_67 ) ;
return;
}
F_56 ( L_68 ) ;
F_276 () ;
F_289 ( & V_291 ) ;
}
static T_7 void F_287 ( void )
{
}
static T_7 int F_290 ( void )
{
if ( ! V_257 ) {
F_276 () ;
F_287 () ;
}
return 0 ;
}
