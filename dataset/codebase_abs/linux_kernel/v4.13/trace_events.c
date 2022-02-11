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
struct V_9 * V_36 ;
struct V_3 * V_10 ;
V_10 = F_4 ( V_13 ) ;
V_36 = F_23 ( V_10 , struct V_9 , V_24 ) ;
return V_36 -> V_16 + V_36 -> V_17 ;
}
int F_24 ( struct V_4 * V_13 )
{
int V_37 ;
V_37 = F_25 ( & V_13 -> V_38 ) ;
if ( ! V_37 )
return - V_39 ;
return 0 ;
}
bool F_26 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
if ( ! V_47 )
return false ;
V_45 = F_28 ( V_43 -> V_49 . V_45 ) ;
return V_45 -> V_50 ;
}
void * F_29 ( struct V_51 * V_52 ,
struct V_40 * V_41 ,
unsigned long V_53 )
{
struct V_4 * V_5 = V_41 -> V_5 ;
if ( ( V_41 -> V_54 & V_55 ) &&
F_26 ( V_41 ) )
return NULL ;
F_30 ( V_52 -> V_54 ) ;
V_52 -> V_56 = F_31 () ;
if ( F_32 ( V_57 ) )
V_52 -> V_56 -- ;
V_52 -> V_41 = V_41 ;
V_52 -> V_38 =
F_33 ( & V_52 -> V_58 , V_41 ,
V_5 -> V_38 . type , V_53 ,
V_52 -> V_54 , V_52 -> V_56 ) ;
if ( ! V_52 -> V_38 )
return NULL ;
V_52 -> V_59 = F_34 ( V_52 -> V_38 ) ;
return V_52 -> V_59 ;
}
int F_35 ( struct V_4 * V_13 ,
enum V_60 type , void * V_45 )
{
struct V_40 * V_61 = V_45 ;
F_13 ( ! ( V_13 -> V_54 & V_62 ) ) ;
switch ( type ) {
case V_63 :
return F_36 ( V_13 -> V_64 ,
V_13 -> V_6 -> V_65 ,
V_61 ) ;
case V_66 :
F_37 ( V_13 -> V_64 ,
V_13 -> V_6 -> V_65 ,
V_61 ) ;
return 0 ;
#ifdef F_38
case V_67 :
return F_36 ( V_13 -> V_64 ,
V_13 -> V_6 -> V_68 ,
V_13 ) ;
case V_69 :
F_37 ( V_13 -> V_64 ,
V_13 -> V_6 -> V_68 ,
V_13 ) ;
return 0 ;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
return 0 ;
#endif
}
return 0 ;
}
void F_39 ( bool V_74 )
{
struct V_40 * V_61 ;
struct V_42 * V_43 ;
F_40 ( & V_75 ) ;
F_41 (tr, file) {
if ( ! ( V_61 -> V_54 & V_76 ) )
continue;
if ( V_74 ) {
F_42 () ;
F_43 ( V_77 , & V_61 -> V_54 ) ;
} else {
F_44 () ;
F_45 ( V_77 , & V_61 -> V_54 ) ;
}
} F_46 () ;
F_47 ( & V_75 ) ;
}
void F_48 ( bool V_74 )
{
struct V_40 * V_61 ;
struct V_42 * V_43 ;
F_40 ( & V_75 ) ;
F_41 (tr, file) {
if ( ! ( V_61 -> V_54 & V_76 ) )
continue;
if ( V_74 ) {
F_49 () ;
F_43 ( V_78 , & V_61 -> V_54 ) ;
} else {
F_50 () ;
F_45 ( V_78 ,
& V_61 -> V_54 ) ;
}
} F_46 () ;
F_47 ( & V_75 ) ;
}
static int F_51 ( struct V_40 * V_61 ,
int V_74 , int V_79 )
{
struct V_4 * V_13 = V_61 -> V_5 ;
struct V_42 * V_43 = V_61 -> V_43 ;
unsigned long V_80 = V_61 -> V_54 ;
int V_25 = 0 ;
int V_81 ;
switch ( V_74 ) {
case 0 :
if ( V_79 ) {
if ( F_52 ( & V_61 -> V_82 ) > 0 )
break;
V_81 = V_61 -> V_54 & V_83 ;
F_45 ( V_84 , & V_61 -> V_54 ) ;
} else
V_81 = ! ( V_61 -> V_54 & V_85 ) ;
if ( V_81 && ( V_61 -> V_54 & V_76 ) ) {
F_45 ( V_86 , & V_61 -> V_54 ) ;
if ( V_61 -> V_54 & V_87 ) {
F_44 () ;
F_45 ( V_77 , & V_61 -> V_54 ) ;
}
if ( V_61 -> V_54 & V_88 ) {
F_50 () ;
F_45 ( V_77 , & V_61 -> V_54 ) ;
}
V_13 -> V_6 -> V_89 ( V_13 , V_66 , V_61 ) ;
}
if ( V_61 -> V_54 & V_85 )
F_43 ( V_90 , & V_61 -> V_54 ) ;
else
F_45 ( V_90 , & V_61 -> V_54 ) ;
break;
case 1 :
if ( ! V_79 )
F_45 ( V_90 , & V_61 -> V_54 ) ;
else {
if ( F_53 ( & V_61 -> V_82 ) > 1 )
break;
F_43 ( V_84 , & V_61 -> V_54 ) ;
}
if ( ! ( V_61 -> V_54 & V_76 ) ) {
bool V_91 = false , V_92 = false ;
if ( V_79 )
F_43 ( V_90 , & V_61 -> V_54 ) ;
if ( V_43 -> V_93 & V_94 ) {
V_91 = true ;
F_42 () ;
F_43 ( V_77 , & V_61 -> V_54 ) ;
}
if ( V_43 -> V_93 & V_95 ) {
V_92 = true ;
F_49 () ;
F_43 ( V_78 , & V_61 -> V_54 ) ;
}
V_25 = V_13 -> V_6 -> V_89 ( V_13 , V_63 , V_61 ) ;
if ( V_25 ) {
if ( V_91 )
F_44 () ;
if ( V_92 )
F_50 () ;
F_54 ( L_1
L_2 , F_55 ( V_13 ) ) ;
break;
}
F_43 ( V_86 , & V_61 -> V_54 ) ;
V_13 -> V_54 |= V_96 ;
}
break;
}
if ( ( V_80 & V_83 ) !=
( V_61 -> V_54 & V_83 ) ) {
if ( V_61 -> V_54 & V_83 )
F_56 () ;
else
F_57 () ;
}
return V_25 ;
}
int F_58 ( struct V_40 * V_61 ,
int V_74 , int V_79 )
{
return F_51 ( V_61 , V_74 , V_79 ) ;
}
static int F_59 ( struct V_40 * V_61 ,
int V_74 )
{
return F_51 ( V_61 , V_74 , 0 ) ;
}
static void F_60 ( struct V_42 * V_43 )
{
struct V_40 * V_61 ;
F_40 ( & V_75 ) ;
F_6 (file, &tr->events, list) {
F_59 ( V_61 , 0 ) ;
}
F_47 ( & V_75 ) ;
}
static void
F_61 ( void * V_45 , struct V_97 * V_98 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_45 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_62 ( V_47 , NULL , V_98 ) ;
}
static void
F_63 ( void * V_45 ,
struct V_97 * V_99 ,
struct V_97 * V_98 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_45 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_62 ( V_47 , V_99 , V_98 ) ;
}
void F_64 ( struct V_42 * V_43 , bool V_74 )
{
if ( V_74 ) {
F_65 ( F_63 ,
V_43 , V_100 ) ;
F_66 ( F_61 ,
V_43 , V_101 ) ;
} else {
F_67 ( F_63 ,
V_43 ) ;
F_68 ( F_61 ,
V_43 ) ;
}
}
static void
F_69 ( void * V_45 , bool V_102 ,
struct V_97 * V_103 , struct V_97 * V_35 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_70 ( V_43 -> V_49 . V_45 -> V_50 ,
F_71 ( V_47 , V_103 ) &&
F_71 ( V_47 , V_35 ) ) ;
}
static void
F_72 ( void * V_45 , bool V_102 ,
struct V_97 * V_103 , struct V_97 * V_35 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_70 ( V_43 -> V_49 . V_45 -> V_50 ,
F_71 ( V_47 , V_35 ) ) ;
}
static void
F_73 ( void * V_45 , struct V_97 * V_98 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
if ( ! F_74 ( V_43 -> V_49 . V_45 -> V_50 ) )
return;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_70 ( V_43 -> V_49 . V_45 -> V_50 ,
F_71 ( V_47 , V_98 ) ) ;
}
static void
F_75 ( void * V_45 , struct V_97 * V_98 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
if ( F_74 ( V_43 -> V_49 . V_45 -> V_50 ) )
return;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_70 ( V_43 -> V_49 . V_45 -> V_50 ,
F_71 ( V_47 , V_104 ) ) ;
}
static void F_76 ( struct V_42 * V_43 )
{
struct V_46 * V_47 ;
struct V_40 * V_61 ;
int V_28 ;
V_47 = F_77 ( V_43 -> V_48 ,
F_78 ( & V_75 ) ) ;
if ( ! V_47 )
return;
F_79 ( F_69 , V_43 ) ;
F_79 ( F_72 , V_43 ) ;
F_80 ( F_73 , V_43 ) ;
F_80 ( F_75 , V_43 ) ;
F_81 ( F_73 , V_43 ) ;
F_81 ( F_75 , V_43 ) ;
F_82 ( F_73 , V_43 ) ;
F_82 ( F_75 , V_43 ) ;
F_6 (file, &tr->events, list) {
F_45 ( V_105 , & V_61 -> V_54 ) ;
}
F_83 (cpu)
F_84 ( V_43 -> V_49 . V_45 , V_28 ) -> V_50 = false ;
F_85 ( V_43 -> V_48 , NULL ) ;
F_86 () ;
F_87 ( V_47 ) ;
}
static void F_88 ( struct V_42 * V_43 )
{
F_40 ( & V_75 ) ;
F_76 ( V_43 ) ;
F_47 ( & V_75 ) ;
}
static void F_89 ( struct V_1 * system )
{
struct V_106 * V_107 = system -> V_107 ;
F_90 ( F_1 ( system ) == 0 ) ;
if ( F_3 ( system ) )
return;
F_20 ( & system -> V_108 ) ;
if ( V_107 ) {
F_91 ( V_107 -> V_109 ) ;
F_91 ( V_107 ) ;
}
F_92 ( system -> V_11 ) ;
F_91 ( system ) ;
}
static void F_93 ( struct V_1 * system )
{
F_90 ( F_1 ( system ) == 0 ) ;
F_2 ( system ) ;
}
static void F_94 ( struct V_110 * V_111 )
{
F_90 ( V_111 -> V_2 == 0 ) ;
V_111 -> V_2 ++ ;
F_93 ( V_111 -> V_112 ) ;
}
static void F_95 ( struct V_110 * V_111 )
{
F_90 ( V_111 -> V_2 == 0 ) ;
F_90 ( F_1 ( V_111 -> V_112 ) == 1 && V_111 -> V_2 != 1 ) ;
F_89 ( V_111 -> V_112 ) ;
if ( ! -- V_111 -> V_2 )
F_91 ( V_111 ) ;
}
static void F_96 ( struct V_110 * V_111 )
{
F_40 ( & V_75 ) ;
F_95 ( V_111 ) ;
F_47 ( & V_75 ) ;
}
static void F_97 ( struct V_110 * V_111 )
{
if ( ! V_111 )
return;
if ( ! -- V_111 -> V_113 ) {
F_98 ( V_111 -> V_59 ) ;
F_20 ( & V_111 -> V_108 ) ;
F_95 ( V_111 ) ;
}
}
static void F_99 ( struct V_40 * V_61 )
{
struct V_114 * V_111 = V_61 -> V_111 ;
struct V_114 * V_115 ;
if ( V_111 ) {
F_100 ( & V_111 -> V_116 ) ;
F_6 (child, &dir->d_subdirs, d_child) {
if ( F_101 ( V_115 ) )
F_102 ( V_115 ) -> V_117 = NULL ;
}
F_103 ( & V_111 -> V_116 ) ;
F_98 ( V_111 ) ;
}
F_20 ( & V_61 -> V_108 ) ;
F_97 ( V_61 -> system ) ;
F_104 ( V_61 -> V_107 ) ;
F_21 ( V_118 , V_61 ) ;
}
static int
F_105 ( struct V_42 * V_43 , const char * V_119 ,
const char * V_120 , const char * V_38 , int V_121 )
{
struct V_40 * V_61 ;
struct V_4 * V_13 ;
const char * V_11 ;
int V_25 = - V_122 ;
int V_123 = 0 ;
F_6 (file, &tr->events, list) {
V_13 = V_61 -> V_5 ;
V_11 = F_55 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_89 )
continue;
if ( V_13 -> V_54 & V_124 )
continue;
if ( V_119 &&
strcmp ( V_119 , V_11 ) != 0 &&
strcmp ( V_119 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_120 && strcmp ( V_120 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_38 && strcmp ( V_38 , V_11 ) != 0 )
continue;
V_25 = F_59 ( V_61 , V_121 ) ;
if ( V_25 && ! V_123 )
V_123 = V_25 ;
V_25 = V_123 ;
}
return V_25 ;
}
static int F_106 ( struct V_42 * V_43 , const char * V_119 ,
const char * V_120 , const char * V_38 , int V_121 )
{
int V_25 ;
F_40 ( & V_75 ) ;
V_25 = F_105 ( V_43 , V_119 , V_120 , V_38 , V_121 ) ;
F_47 ( & V_75 ) ;
return V_25 ;
}
static int F_107 ( struct V_42 * V_43 , char * V_125 , int V_121 )
{
char * V_38 = NULL , * V_120 = NULL , * V_119 ;
int V_25 ;
V_119 = F_108 ( & V_125 , L_3 ) ;
if ( V_125 ) {
V_120 = V_119 ;
V_38 = V_125 ;
V_119 = NULL ;
if ( ! strlen ( V_120 ) || strcmp ( V_120 , L_4 ) == 0 )
V_120 = NULL ;
if ( ! strlen ( V_38 ) || strcmp ( V_38 , L_4 ) == 0 )
V_38 = NULL ;
}
V_25 = F_106 ( V_43 , V_119 , V_120 , V_38 , V_121 ) ;
if ( V_125 )
* ( V_125 - 1 ) = ':' ;
return V_25 ;
}
int F_109 ( const char * system , const char * V_38 , int V_121 )
{
struct V_42 * V_43 = F_110 () ;
if ( ! V_43 )
return - V_39 ;
return F_106 ( V_43 , NULL , system , V_38 , V_121 ) ;
}
static T_1
F_111 ( struct V_61 * V_61 , const char T_2 * V_126 ,
T_3 V_127 , T_4 * V_128 )
{
struct V_129 V_130 ;
struct V_131 * V_132 = V_61 -> V_133 ;
struct V_42 * V_43 = V_132 -> V_134 ;
T_1 V_135 , V_25 ;
if ( ! V_127 )
return 0 ;
V_25 = F_112 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_113 ( & V_130 , V_136 + 1 ) )
return - V_22 ;
V_135 = F_114 ( & V_130 , V_126 , V_127 , V_128 ) ;
if ( V_135 >= 0 && F_115 ( ( & V_130 ) ) ) {
int V_121 = 1 ;
if ( * V_130 . V_58 == '!' )
V_121 = 0 ;
V_130 . V_58 [ V_130 . V_137 ] = 0 ;
V_25 = F_107 ( V_43 , V_130 . V_58 + ! V_121 , V_121 ) ;
if ( V_25 )
goto V_138;
}
V_25 = V_135 ;
V_138:
F_116 ( & V_130 ) ;
return V_25 ;
}
static void *
F_117 ( struct V_131 * V_132 , void * V_139 , T_4 * V_140 )
{
struct V_40 * V_61 = V_139 ;
struct V_4 * V_13 ;
struct V_42 * V_43 = V_132 -> V_134 ;
( * V_140 ) ++ ;
F_118 (file, &tr->events, list) {
V_13 = V_61 -> V_5 ;
if ( V_13 -> V_6 && V_13 -> V_6 -> V_89 &&
! ( V_13 -> V_54 & V_124 ) )
return V_61 ;
}
return NULL ;
}
static void * F_119 ( struct V_131 * V_132 , T_4 * V_140 )
{
struct V_40 * V_61 ;
struct V_42 * V_43 = V_132 -> V_134 ;
T_4 V_141 ;
F_40 ( & V_75 ) ;
V_61 = F_120 ( & V_43 -> V_142 , struct V_40 , V_108 ) ;
for ( V_141 = 0 ; V_141 <= * V_140 ; ) {
V_61 = F_117 ( V_132 , V_61 , & V_141 ) ;
if ( ! V_61 )
break;
}
return V_61 ;
}
static void *
F_121 ( struct V_131 * V_132 , void * V_139 , T_4 * V_140 )
{
struct V_40 * V_61 = V_139 ;
struct V_42 * V_43 = V_132 -> V_134 ;
( * V_140 ) ++ ;
F_118 (file, &tr->events, list) {
if ( V_61 -> V_54 & V_76 )
return V_61 ;
}
return NULL ;
}
static void * F_122 ( struct V_131 * V_132 , T_4 * V_140 )
{
struct V_40 * V_61 ;
struct V_42 * V_43 = V_132 -> V_134 ;
T_4 V_141 ;
F_40 ( & V_75 ) ;
V_61 = F_120 ( & V_43 -> V_142 , struct V_40 , V_108 ) ;
for ( V_141 = 0 ; V_141 <= * V_140 ; ) {
V_61 = F_121 ( V_132 , V_61 , & V_141 ) ;
if ( ! V_61 )
break;
}
return V_61 ;
}
static int F_123 ( struct V_131 * V_132 , void * V_139 )
{
struct V_40 * V_61 = V_139 ;
struct V_4 * V_13 = V_61 -> V_5 ;
if ( strcmp ( V_13 -> V_6 -> system , V_143 ) != 0 )
F_124 ( V_132 , L_5 , V_13 -> V_6 -> system ) ;
F_124 ( V_132 , L_2 , F_55 ( V_13 ) ) ;
return 0 ;
}
static void F_125 ( struct V_131 * V_132 , void * V_144 )
{
F_47 ( & V_75 ) ;
}
static void *
F_126 ( struct V_131 * V_132 , void * V_139 , T_4 * V_140 )
{
struct V_42 * V_43 = V_132 -> V_134 ;
struct V_46 * V_47 = F_27 ( V_43 -> V_48 ) ;
return F_127 ( V_47 , V_139 , V_140 ) ;
}
static void * F_128 ( struct V_131 * V_132 , T_4 * V_140 )
__acquires( T_5 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_132 -> V_134 ;
F_40 ( & V_75 ) ;
F_129 () ;
V_47 = F_27 ( V_43 -> V_48 ) ;
if ( ! V_47 )
return NULL ;
return F_130 ( V_47 , V_140 ) ;
}
static void F_131 ( struct V_131 * V_132 , void * V_144 )
__releases( T_5 )
{
F_132 () ;
F_47 ( & V_75 ) ;
}
static T_1
F_133 ( struct V_61 * V_145 , char T_2 * V_126 , T_3 V_127 ,
T_4 * V_128 )
{
struct V_40 * V_61 ;
unsigned long V_54 ;
char V_125 [ 4 ] = L_6 ;
F_40 ( & V_75 ) ;
V_61 = F_134 ( V_145 ) ;
if ( F_135 ( V_61 ) )
V_54 = V_61 -> V_54 ;
F_47 ( & V_75 ) ;
if ( ! V_61 )
return - V_39 ;
if ( V_54 & V_76 &&
! ( V_54 & V_83 ) )
strcpy ( V_125 , L_7 ) ;
if ( V_54 & V_83 ||
V_54 & V_85 )
strcat ( V_125 , L_4 ) ;
strcat ( V_125 , L_8 ) ;
return F_136 ( V_126 , V_127 , V_128 , V_125 , strlen ( V_125 ) ) ;
}
static T_1
F_137 ( struct V_61 * V_145 , const char T_2 * V_126 , T_3 V_127 ,
T_4 * V_128 )
{
struct V_40 * V_61 ;
unsigned long V_146 ;
int V_25 ;
V_25 = F_138 ( V_126 , V_127 , 10 , & V_146 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_112 () ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_146 ) {
case 0 :
case 1 :
V_25 = - V_39 ;
F_40 ( & V_75 ) ;
V_61 = F_134 ( V_145 ) ;
if ( F_135 ( V_61 ) )
V_25 = F_59 ( V_61 , V_146 ) ;
F_47 ( & V_75 ) ;
break;
default:
return - V_122 ;
}
* V_128 += V_127 ;
return V_25 ? V_25 : V_127 ;
}
static T_1
F_139 ( struct V_61 * V_145 , char T_2 * V_126 , T_3 V_127 ,
T_4 * V_128 )
{
const char V_147 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_110 * V_111 = V_145 -> V_133 ;
struct V_1 * system = V_111 -> V_112 ;
struct V_4 * V_13 ;
struct V_40 * V_61 ;
struct V_42 * V_43 = V_111 -> V_43 ;
char V_125 [ 2 ] ;
int V_121 = 0 ;
int V_25 ;
F_40 ( & V_75 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_61 -> V_5 ;
if ( ! F_55 ( V_13 ) || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_89 )
continue;
if ( system && strcmp ( V_13 -> V_6 -> system , system -> V_11 ) != 0 )
continue;
V_121 |= ( 1 << ! ! ( V_61 -> V_54 & V_76 ) ) ;
if ( V_121 == 3 )
break;
}
F_47 ( & V_75 ) ;
V_125 [ 0 ] = V_147 [ V_121 ] ;
V_125 [ 1 ] = '\n' ;
V_25 = F_136 ( V_126 , V_127 , V_128 , V_125 , 2 ) ;
return V_25 ;
}
static T_1
F_140 ( struct V_61 * V_145 , const char T_2 * V_126 , T_3 V_127 ,
T_4 * V_128 )
{
struct V_110 * V_111 = V_145 -> V_133 ;
struct V_1 * system = V_111 -> V_112 ;
const char * V_11 = NULL ;
unsigned long V_146 ;
T_1 V_25 ;
V_25 = F_138 ( V_126 , V_127 , 10 , & V_146 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_112 () ;
if ( V_25 < 0 )
return V_25 ;
if ( V_146 != 0 && V_146 != 1 )
return - V_122 ;
if ( system )
V_11 = system -> V_11 ;
V_25 = F_106 ( V_111 -> V_43 , NULL , V_11 , NULL , V_146 ) ;
if ( V_25 )
goto V_148;
V_25 = V_127 ;
V_148:
* V_128 += V_127 ;
return V_25 ;
}
static void * F_141 ( struct V_131 * V_132 , void * V_139 , T_4 * V_140 )
{
struct V_4 * V_13 = F_134 ( V_132 -> V_134 ) ;
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
static int F_142 ( struct V_131 * V_132 , void * V_139 )
{
struct V_4 * V_13 = F_134 ( V_132 -> V_134 ) ;
struct V_9 * V_12 ;
const char * V_154 ;
switch ( ( unsigned long ) V_139 ) {
case V_151 :
F_124 ( V_132 , L_9 , F_55 ( V_13 ) ) ;
F_124 ( V_132 , L_10 , V_13 -> V_38 . type ) ;
F_143 ( V_132 , L_11 ) ;
return 0 ;
case V_152 :
F_144 ( V_132 , '\n' ) ;
return 0 ;
case V_153 :
F_124 ( V_132 , L_12 ,
V_13 -> V_155 ) ;
return 0 ;
}
V_12 = F_120 ( V_139 , struct V_9 , V_24 ) ;
V_154 = strchr ( V_12 -> type , '[' ) ;
if ( ! strncmp ( V_12 -> type , L_13 , 10 ) )
V_154 = NULL ;
if ( ! V_154 )
F_124 ( V_132 , L_14 ,
V_12 -> type , V_12 -> V_11 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
else
F_124 ( V_132 , L_15 ,
( int ) ( V_154 - V_12 -> type ) ,
V_12 -> type , V_12 -> V_11 ,
V_154 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
return 0 ;
}
static void * F_145 ( struct V_131 * V_132 , T_4 * V_140 )
{
void * V_144 = ( void * ) V_151 ;
T_4 V_141 = 0 ;
F_40 ( & V_75 ) ;
if ( ! F_134 ( V_132 -> V_134 ) )
return F_146 ( - V_39 ) ;
while ( V_141 < * V_140 && V_144 )
V_144 = F_141 ( V_132 , V_144 , & V_141 ) ;
return V_144 ;
}
static void F_147 ( struct V_131 * V_132 , void * V_144 )
{
F_47 ( & V_75 ) ;
}
static int F_148 ( struct V_156 * V_156 , struct V_61 * V_61 )
{
struct V_131 * V_132 ;
int V_25 ;
V_25 = F_149 ( V_61 , & V_157 ) ;
if ( V_25 < 0 )
return V_25 ;
V_132 = V_61 -> V_133 ;
V_132 -> V_134 = V_61 ;
return 0 ;
}
static T_1
F_150 ( struct V_61 * V_145 , char T_2 * V_126 , T_3 V_127 , T_4 * V_128 )
{
int V_37 = ( long ) F_134 ( V_145 ) ;
char V_125 [ 32 ] ;
int V_53 ;
if ( * V_128 )
return 0 ;
if ( F_151 ( ! V_37 ) )
return - V_39 ;
V_53 = sprintf ( V_125 , L_16 , V_37 ) ;
return F_136 ( V_126 , V_127 , V_128 , V_125 , V_53 ) ;
}
static T_1
F_152 ( struct V_61 * V_145 , char T_2 * V_126 , T_3 V_127 ,
T_4 * V_128 )
{
struct V_40 * V_61 ;
struct V_158 * V_159 ;
int V_160 = - V_39 ;
if ( * V_128 )
return 0 ;
V_159 = F_153 ( sizeof( * V_159 ) , V_161 ) ;
if ( ! V_159 )
return - V_22 ;
F_154 ( V_159 ) ;
F_40 ( & V_75 ) ;
V_61 = F_134 ( V_145 ) ;
if ( V_61 )
F_155 ( V_61 , V_159 ) ;
F_47 ( & V_75 ) ;
if ( V_61 )
V_160 = F_136 ( V_126 , V_127 , V_128 ,
V_159 -> V_58 , F_156 ( V_159 ) ) ;
F_91 ( V_159 ) ;
return V_160 ;
}
static T_1
F_157 ( struct V_61 * V_145 , const char T_2 * V_126 , T_3 V_127 ,
T_4 * V_128 )
{
struct V_40 * V_61 ;
char * V_125 ;
int V_162 = - V_39 ;
if ( V_127 >= V_163 )
return - V_122 ;
V_125 = F_158 ( V_126 , V_127 ) ;
if ( F_159 ( V_125 ) )
return F_160 ( V_125 ) ;
F_40 ( & V_75 ) ;
V_61 = F_134 ( V_145 ) ;
if ( V_61 )
V_162 = F_161 ( V_61 , V_125 ) ;
F_47 ( & V_75 ) ;
F_91 ( V_125 ) ;
if ( V_162 < 0 )
return V_162 ;
* V_128 += V_127 ;
return V_127 ;
}
static int F_162 ( struct V_156 * V_156 , struct V_61 * V_145 )
{
struct V_1 * system = NULL ;
struct V_110 * V_111 = NULL ;
struct V_42 * V_43 ;
int V_25 ;
if ( F_163 () )
return - V_39 ;
F_40 ( & V_164 ) ;
F_40 ( & V_75 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_111 == V_156 -> V_117 ) {
if ( V_111 -> V_113 ) {
F_94 ( V_111 ) ;
system = V_111 -> V_112 ;
}
goto V_165;
}
}
}
V_165:
F_47 ( & V_75 ) ;
F_47 ( & V_164 ) ;
if ( ! system )
return - V_39 ;
F_13 ( ! V_111 ) ;
if ( F_164 ( V_43 ) < 0 ) {
F_96 ( V_111 ) ;
return - V_39 ;
}
V_25 = F_165 ( V_156 , V_145 ) ;
if ( V_25 < 0 ) {
F_166 ( V_43 ) ;
F_96 ( V_111 ) ;
}
return V_25 ;
}
static int F_167 ( struct V_156 * V_156 , struct V_61 * V_145 )
{
struct V_110 * V_111 ;
struct V_42 * V_43 = V_156 -> V_117 ;
int V_25 ;
if ( F_163 () )
return - V_39 ;
if ( F_164 ( V_43 ) < 0 )
return - V_39 ;
V_111 = F_168 ( sizeof( * V_111 ) , V_161 ) ;
if ( ! V_111 ) {
F_166 ( V_43 ) ;
return - V_22 ;
}
V_111 -> V_43 = V_43 ;
V_25 = F_165 ( V_156 , V_145 ) ;
if ( V_25 < 0 ) {
F_166 ( V_43 ) ;
F_91 ( V_111 ) ;
return V_25 ;
}
V_145 -> V_133 = V_111 ;
return 0 ;
}
static int F_169 ( struct V_156 * V_156 , struct V_61 * V_61 )
{
struct V_110 * V_111 = V_61 -> V_133 ;
F_166 ( V_111 -> V_43 ) ;
if ( V_111 -> V_112 )
F_96 ( V_111 ) ;
else
F_91 ( V_111 ) ;
return 0 ;
}
static T_1
F_170 ( struct V_61 * V_145 , char T_2 * V_126 , T_3 V_127 ,
T_4 * V_128 )
{
struct V_110 * V_111 = V_145 -> V_133 ;
struct V_1 * system = V_111 -> V_112 ;
struct V_158 * V_159 ;
int V_160 ;
if ( * V_128 )
return 0 ;
V_159 = F_153 ( sizeof( * V_159 ) , V_161 ) ;
if ( ! V_159 )
return - V_22 ;
F_154 ( V_159 ) ;
F_171 ( system , V_159 ) ;
V_160 = F_136 ( V_126 , V_127 , V_128 ,
V_159 -> V_58 , F_156 ( V_159 ) ) ;
F_91 ( V_159 ) ;
return V_160 ;
}
static T_1
F_172 ( struct V_61 * V_145 , const char T_2 * V_126 , T_3 V_127 ,
T_4 * V_128 )
{
struct V_110 * V_111 = V_145 -> V_133 ;
char * V_125 ;
int V_162 ;
if ( V_127 >= V_163 )
return - V_122 ;
V_125 = F_158 ( V_126 , V_127 ) ;
if ( F_159 ( V_125 ) )
return F_160 ( V_125 ) ;
V_162 = F_173 ( V_111 , V_125 ) ;
F_91 ( V_125 ) ;
if ( V_162 < 0 )
return V_162 ;
* V_128 += V_127 ;
return V_127 ;
}
static T_1
F_174 ( struct V_61 * V_145 , char T_2 * V_126 , T_3 V_127 , T_4 * V_128 )
{
int (* F_175)( struct V_158 * V_159 ) = V_145 -> V_133 ;
struct V_158 * V_159 ;
int V_160 ;
if ( * V_128 )
return 0 ;
V_159 = F_153 ( sizeof( * V_159 ) , V_161 ) ;
if ( ! V_159 )
return - V_22 ;
F_154 ( V_159 ) ;
F_175 ( V_159 ) ;
V_160 = F_136 ( V_126 , V_127 , V_128 ,
V_159 -> V_58 , F_156 ( V_159 ) ) ;
F_91 ( V_159 ) ;
return V_160 ;
}
static void F_176 ( void * V_45 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_77 ( V_43 -> V_48 ,
F_177 ( & V_75 ) ) ;
F_70 ( V_43 -> V_49 . V_45 -> V_50 ,
F_71 ( V_47 , V_104 ) ) ;
}
static T_1
F_178 ( struct V_61 * V_145 , const char T_2 * V_126 ,
T_3 V_127 , T_4 * V_128 )
{
struct V_131 * V_132 = V_145 -> V_133 ;
struct V_42 * V_43 = V_132 -> V_134 ;
struct V_46 * V_48 = NULL ;
struct V_46 * V_47 ;
struct V_40 * V_61 ;
T_1 V_25 ;
if ( ! V_127 )
return 0 ;
V_25 = F_112 () ;
if ( V_25 < 0 )
return V_25 ;
F_40 ( & V_75 ) ;
V_48 = F_77 ( V_43 -> V_48 ,
F_78 ( & V_75 ) ) ;
V_25 = F_179 ( V_48 , & V_47 , V_126 , V_127 ) ;
if ( V_25 < 0 )
goto V_148;
F_85 ( V_43 -> V_48 , V_47 ) ;
F_6 (file, &tr->events, list) {
F_43 ( V_105 , & V_61 -> V_54 ) ;
}
if ( V_48 ) {
F_86 () ;
F_87 ( V_48 ) ;
} else if ( V_47 ) {
F_180 ( F_69 ,
V_43 , V_101 ) ;
F_180 ( F_72 ,
V_43 , 0 ) ;
F_181 ( F_73 ,
V_43 , V_101 ) ;
F_181 ( F_75 ,
V_43 , 0 ) ;
F_182 ( F_73 ,
V_43 , V_101 ) ;
F_182 ( F_75 ,
V_43 , 0 ) ;
F_183 ( F_73 ,
V_43 , V_101 ) ;
F_183 ( F_75 ,
V_43 , 0 ) ;
}
F_184 ( F_176 , V_43 , 1 ) ;
V_148:
F_47 ( & V_75 ) ;
if ( V_25 > 0 )
* V_128 += V_25 ;
return V_25 ;
}
static int
F_185 ( struct V_156 * V_156 , struct V_61 * V_61 ,
const struct V_166 * V_167 )
{
struct V_131 * V_132 ;
int V_25 ;
V_25 = F_149 ( V_61 , V_167 ) ;
if ( V_25 < 0 )
return V_25 ;
V_132 = V_61 -> V_133 ;
V_132 -> V_134 = V_156 -> V_117 ;
return V_25 ;
}
static int F_186 ( struct V_156 * V_156 , struct V_61 * V_61 )
{
struct V_42 * V_43 = V_156 -> V_117 ;
F_166 ( V_43 ) ;
return F_187 ( V_156 , V_61 ) ;
}
static int
F_188 ( struct V_156 * V_156 , struct V_61 * V_61 )
{
const struct V_166 * V_167 = & V_168 ;
return F_185 ( V_156 , V_61 , V_167 ) ;
}
static int
F_189 ( struct V_156 * V_156 , struct V_61 * V_61 )
{
const struct V_166 * V_167 = & V_169 ;
struct V_42 * V_43 = V_156 -> V_117 ;
int V_25 ;
if ( F_164 ( V_43 ) < 0 )
return - V_39 ;
if ( ( V_61 -> V_170 & V_171 ) &&
( V_61 -> V_172 & V_173 ) )
F_60 ( V_43 ) ;
V_25 = F_185 ( V_156 , V_61 , V_167 ) ;
if ( V_25 < 0 )
F_166 ( V_43 ) ;
return V_25 ;
}
static int
F_190 ( struct V_156 * V_156 , struct V_61 * V_61 )
{
const struct V_166 * V_167 = & V_174 ;
struct V_42 * V_43 = V_156 -> V_117 ;
int V_25 ;
if ( F_164 ( V_43 ) < 0 )
return - V_39 ;
if ( ( V_61 -> V_170 & V_171 ) &&
( V_61 -> V_172 & V_173 ) )
F_88 ( V_43 ) ;
V_25 = F_185 ( V_156 , V_61 , V_167 ) ;
if ( V_25 < 0 )
F_166 ( V_43 ) ;
return V_25 ;
}
static struct V_1 *
F_191 ( const char * V_11 )
{
struct V_1 * system ;
system = F_153 ( sizeof( * system ) , V_161 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
system -> V_11 = F_192 ( V_11 , V_161 ) ;
if ( ! system -> V_11 )
goto V_175;
system -> V_107 = NULL ;
system -> V_107 = F_168 ( sizeof( struct V_106 ) , V_161 ) ;
if ( ! system -> V_107 )
goto V_175;
F_11 ( & system -> V_108 , & V_176 ) ;
return system ;
V_175:
F_92 ( system -> V_11 ) ;
F_91 ( system ) ;
return NULL ;
}
static struct V_114 *
F_193 ( struct V_42 * V_43 , const char * V_11 ,
struct V_40 * V_61 , struct V_114 * V_177 )
{
struct V_110 * V_111 ;
struct V_1 * system ;
struct V_114 * V_59 ;
F_6 (dir, &tr->systems, list) {
system = V_111 -> V_112 ;
if ( strcmp ( system -> V_11 , V_11 ) == 0 ) {
V_111 -> V_113 ++ ;
V_61 -> system = V_111 ;
return V_111 -> V_59 ;
}
}
F_6 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_11 , V_11 ) == 0 )
break;
}
if ( & system -> V_108 == & V_176 )
system = NULL ;
V_111 = F_153 ( sizeof( * V_111 ) , V_161 ) ;
if ( ! V_111 )
goto V_178;
if ( ! system ) {
system = F_191 ( V_11 ) ;
if ( ! system )
goto V_175;
} else
F_93 ( system ) ;
V_111 -> V_59 = F_194 ( V_11 , V_177 ) ;
if ( ! V_111 -> V_59 ) {
F_195 ( L_17 , V_11 ) ;
F_89 ( system ) ;
goto V_175;
}
V_111 -> V_43 = V_43 ;
V_111 -> V_2 = 1 ;
V_111 -> V_113 = 1 ;
V_111 -> V_112 = system ;
V_61 -> system = V_111 ;
V_59 = F_196 ( L_18 , 0644 , V_111 -> V_59 , V_111 ,
& V_179 ) ;
if ( ! V_59 ) {
F_91 ( system -> V_107 ) ;
system -> V_107 = NULL ;
F_195 ( L_19 , V_11 ) ;
}
F_197 ( L_20 , 0644 , V_111 -> V_59 , V_111 ,
& V_180 ) ;
F_11 ( & V_111 -> V_108 , & V_43 -> V_181 ) ;
return V_111 -> V_59 ;
V_175:
F_91 ( V_111 ) ;
V_178:
if ( ! V_111 || ! system )
F_195 ( L_21 , V_11 ) ;
return NULL ;
}
static int
F_198 ( struct V_114 * V_177 , struct V_40 * V_61 )
{
struct V_4 * V_13 = V_61 -> V_5 ;
struct V_42 * V_43 = V_61 -> V_43 ;
struct V_3 * V_10 ;
struct V_114 * V_182 ;
const char * V_11 ;
int V_25 ;
if ( strcmp ( V_13 -> V_6 -> system , V_143 ) != 0 ) {
V_182 = F_193 ( V_43 , V_13 -> V_6 -> system , V_61 , V_177 ) ;
if ( ! V_182 )
return - V_22 ;
} else
V_182 = V_177 ;
V_11 = F_55 ( V_13 ) ;
V_61 -> V_111 = F_194 ( V_11 , V_182 ) ;
if ( ! V_61 -> V_111 ) {
F_195 ( L_22 , V_11 ) ;
return - 1 ;
}
if ( V_13 -> V_6 -> V_89 && ! ( V_13 -> V_54 & V_124 ) )
F_197 ( L_20 , 0644 , V_61 -> V_111 , V_61 ,
& V_183 ) ;
#ifdef F_38
if ( V_13 -> V_38 . type && V_13 -> V_6 -> V_89 )
F_197 ( L_23 , 0444 , V_61 -> V_111 ,
( void * ) ( long ) V_13 -> V_38 . type ,
& V_184 ) ;
#endif
V_10 = F_4 ( V_13 ) ;
if ( F_199 ( V_10 ) ) {
V_25 = V_13 -> V_6 -> V_185 ( V_13 ) ;
if ( V_25 < 0 ) {
F_195 ( L_24 ,
V_11 ) ;
return - 1 ;
}
}
F_197 ( L_18 , 0644 , V_61 -> V_111 , V_61 ,
& V_186 ) ;
if ( ! ( V_13 -> V_54 & V_124 ) )
F_197 ( L_25 , 0644 , V_61 -> V_111 , V_61 ,
& V_187 ) ;
#ifdef F_200
F_197 ( L_26 , 0444 , V_61 -> V_111 , V_61 ,
& V_188 ) ;
#endif
F_197 ( L_27 , 0444 , V_61 -> V_111 , V_13 ,
& V_189 ) ;
return 0 ;
}
static void F_201 ( struct V_4 * V_13 )
{
struct V_40 * V_61 ;
struct V_42 * V_43 ;
F_202 (tr, file) {
if ( V_61 -> V_5 != V_13 )
continue;
F_99 ( V_61 ) ;
break;
} F_46 () ;
}
static void F_203 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
struct V_40 * V_61 ;
F_41 (tr, file) {
if ( V_61 -> V_5 != V_13 )
continue;
F_59 ( V_61 , 0 ) ;
break;
} F_46 () ;
if ( V_13 -> V_38 . V_190 )
F_204 ( & V_13 -> V_38 ) ;
F_201 ( V_13 ) ;
F_20 ( & V_13 -> V_108 ) ;
}
static int F_205 ( struct V_4 * V_13 )
{
int V_25 = 0 ;
const char * V_11 ;
V_11 = F_55 ( V_13 ) ;
if ( F_13 ( ! V_11 ) )
return - V_122 ;
if ( V_13 -> V_6 -> V_191 ) {
V_25 = V_13 -> V_6 -> V_191 ( V_13 ) ;
if ( V_25 < 0 && V_25 != - V_192 )
F_195 ( L_28 , V_11 ) ;
}
return V_25 ;
}
static int
F_206 ( struct V_4 * V_13 , struct V_193 * V_194 )
{
int V_25 ;
V_25 = F_205 ( V_13 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_13 -> V_108 , & V_195 ) ;
V_13 -> V_194 = V_194 ;
return 0 ;
}
static char * F_207 ( char * V_196 , struct V_197 * V_198 , int V_53 )
{
int V_199 ;
int V_200 ;
V_200 = snprintf ( V_196 , 0 , L_29 , V_198 -> V_201 ) ;
if ( V_53 < V_200 )
return NULL ;
snprintf ( V_196 , V_200 + 1 , L_29 , V_198 -> V_201 ) ;
V_199 = strlen ( V_196 + V_53 ) ;
memmove ( V_196 + V_200 , V_196 + V_53 , V_199 ) ;
V_196 [ V_200 + V_199 ] = 0 ;
return V_196 + V_200 ;
}
static void F_208 ( struct V_4 * V_13 ,
struct V_197 * V_198 )
{
char * V_196 ;
int V_202 = 0 ;
int V_53 = strlen ( V_198 -> V_203 ) ;
for ( V_196 = V_13 -> V_155 ; * V_196 ; V_196 ++ ) {
if ( * V_196 == '\\' ) {
V_196 ++ ;
if ( ! * V_196 )
break;
continue;
}
if ( * V_196 == '"' ) {
V_202 ^= 1 ;
continue;
}
if ( V_202 )
continue;
if ( isdigit ( * V_196 ) ) {
do {
V_196 ++ ;
} while ( isalnum ( * V_196 ) );
if ( ! * V_196 )
break;
continue;
}
if ( isalpha ( * V_196 ) || * V_196 == '_' ) {
if ( strncmp ( V_198 -> V_203 , V_196 , V_53 ) == 0 &&
! isalnum ( V_196 [ V_53 ] ) && V_196 [ V_53 ] != '_' ) {
V_196 = F_207 ( V_196 , V_198 , V_53 ) ;
if ( F_90 ( ! V_196 ) )
return;
continue;
}
V_204:
do {
V_196 ++ ;
} while ( isalnum ( * V_196 ) || * V_196 == '_' );
if ( ! * V_196 )
break;
if ( * V_196 == '.' || ( V_196 [ 0 ] == '-' && V_196 [ 1 ] == '>' ) ) {
V_196 += * V_196 == '.' ? 1 : 2 ;
if ( ! * V_196 )
break;
goto V_204;
}
continue;
}
}
}
void F_209 ( struct V_197 * * V_198 , int V_53 )
{
struct V_4 * V_13 , * V_144 ;
const char * V_205 = NULL ;
int V_206 ;
int V_207 ;
F_210 ( & V_208 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( ! V_205 || V_13 -> V_6 -> system != V_205 ) {
V_206 = 0 ;
V_205 = V_13 -> V_6 -> system ;
}
for ( V_207 = V_206 ; V_207 < V_53 ; V_207 ++ ) {
if ( V_13 -> V_6 -> system == V_198 [ V_207 ] -> system ) {
if ( ! V_206 )
V_206 = V_207 ;
F_208 ( V_13 , V_198 [ V_207 ] ) ;
}
}
}
F_211 ( & V_208 ) ;
}
static struct V_40 *
F_212 ( struct V_4 * V_13 ,
struct V_42 * V_43 )
{
struct V_40 * V_61 ;
V_61 = F_9 ( V_118 , V_21 ) ;
if ( ! V_61 )
return NULL ;
V_61 -> V_5 = V_13 ;
V_61 -> V_43 = V_43 ;
F_213 ( & V_61 -> V_82 , 0 ) ;
F_213 ( & V_61 -> V_209 , 0 ) ;
F_214 ( & V_61 -> V_210 ) ;
F_11 ( & V_61 -> V_108 , & V_43 -> V_142 ) ;
return V_61 ;
}
static int
F_215 ( struct V_4 * V_13 , struct V_42 * V_43 )
{
struct V_40 * V_61 ;
V_61 = F_212 ( V_13 , V_43 ) ;
if ( ! V_61 )
return - V_22 ;
return F_198 ( V_43 -> V_211 , V_61 ) ;
}
static T_6 int
F_216 ( struct V_4 * V_13 ,
struct V_42 * V_43 )
{
struct V_40 * V_61 ;
V_61 = F_212 ( V_13 , V_43 ) ;
if ( ! V_61 )
return - V_22 ;
return 0 ;
}
int F_217 ( struct V_4 * V_13 )
{
int V_25 ;
F_40 ( & V_164 ) ;
F_40 ( & V_75 ) ;
V_25 = F_206 ( V_13 , NULL ) ;
if ( V_25 >= 0 )
F_218 ( V_13 ) ;
F_47 ( & V_75 ) ;
F_47 ( & V_164 ) ;
return V_25 ;
}
static void F_219 ( struct V_4 * V_13 )
{
F_203 ( V_13 ) ;
F_18 ( V_13 ) ;
F_104 ( V_13 -> V_107 ) ;
V_13 -> V_107 = NULL ;
}
static int F_220 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
struct V_40 * V_61 ;
#ifdef F_38
if ( V_13 -> V_212 )
return - V_213 ;
#endif
F_41 (tr, file) {
if ( V_61 -> V_5 != V_13 )
continue;
if ( V_61 -> V_54 & V_76 )
return - V_213 ;
break;
} F_46 () ;
F_219 ( V_13 ) ;
return 0 ;
}
int F_221 ( struct V_4 * V_13 )
{
int V_25 ;
F_40 ( & V_164 ) ;
F_40 ( & V_75 ) ;
F_210 ( & V_208 ) ;
V_25 = F_220 ( V_13 ) ;
F_211 ( & V_208 ) ;
F_47 ( & V_75 ) ;
F_47 ( & V_164 ) ;
return V_25 ;
}
static void F_222 ( struct V_193 * V_194 )
{
struct V_4 * * V_13 , * * V_214 , * * V_215 ;
if ( ! V_194 -> V_216 )
return;
if ( F_223 ( V_194 ) ) {
F_224 ( L_30 ,
V_194 -> V_11 ) ;
return;
}
V_214 = V_194 -> V_217 ;
V_215 = V_194 -> V_217 + V_194 -> V_216 ;
F_225 (call, start, end) {
F_206 ( * V_13 , V_194 ) ;
F_218 ( * V_13 ) ;
}
}
static void F_226 ( struct V_193 * V_194 )
{
struct V_4 * V_13 , * V_144 ;
bool V_218 = false ;
F_210 ( & V_208 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( V_13 -> V_194 == V_194 ) {
if ( V_13 -> V_54 & V_96 )
V_218 = true ;
F_219 ( V_13 ) ;
}
}
F_211 ( & V_208 ) ;
if ( V_218 )
F_227 () ;
}
static int F_228 ( struct V_219 * V_99 ,
unsigned long V_146 , void * V_45 )
{
struct V_193 * V_194 = V_45 ;
F_40 ( & V_164 ) ;
F_40 ( & V_75 ) ;
switch ( V_146 ) {
case V_220 :
F_222 ( V_194 ) ;
break;
case V_221 :
F_226 ( V_194 ) ;
break;
}
F_47 ( & V_75 ) ;
F_47 ( & V_164 ) ;
return 0 ;
}
static void
F_229 ( struct V_42 * V_43 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
V_25 = F_215 ( V_13 , V_43 ) ;
if ( V_25 < 0 )
F_195 ( L_31 ,
F_55 ( V_13 ) ) ;
}
}
struct V_40 *
F_230 ( struct V_42 * V_43 , const char * system , const char * V_38 )
{
struct V_40 * V_61 ;
struct V_4 * V_13 ;
const char * V_11 ;
F_6 (file, &tr->events, list) {
V_13 = V_61 -> V_5 ;
V_11 = F_55 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_89 )
continue;
if ( V_13 -> V_54 & V_124 )
continue;
if ( strcmp ( V_38 , V_11 ) == 0 &&
strcmp ( system , V_13 -> V_6 -> system ) == 0 )
return V_61 ;
}
return NULL ;
}
static void F_231 ( struct V_222 * V_45 )
{
if ( V_45 -> V_74 )
F_45 ( V_90 , & V_45 -> V_61 -> V_54 ) ;
else
F_43 ( V_90 , & V_45 -> V_61 -> V_54 ) ;
}
static void
F_232 ( unsigned long V_223 , unsigned long V_224 ,
struct V_42 * V_43 , struct V_225 * V_226 ,
void * V_45 )
{
struct V_227 * V_228 = V_45 ;
struct V_222 * V_229 ;
void * * V_230 ;
V_230 = F_233 ( V_228 , V_223 ) ;
if ( ! V_230 || ! * V_230 )
return;
V_229 = * V_230 ;
F_231 ( V_229 ) ;
}
static void
F_234 ( unsigned long V_223 , unsigned long V_224 ,
struct V_42 * V_43 , struct V_225 * V_226 ,
void * V_45 )
{
struct V_227 * V_228 = V_45 ;
struct V_222 * V_229 ;
void * * V_230 ;
V_230 = F_233 ( V_228 , V_223 ) ;
if ( ! V_230 || ! * V_230 )
return;
V_229 = * V_230 ;
if ( ! V_229 -> V_231 )
return;
if ( V_229 -> V_74 == ! ( V_229 -> V_61 -> V_54 & V_83 ) )
return;
if ( V_229 -> V_231 != - 1 )
( V_229 -> V_231 ) -- ;
F_231 ( V_229 ) ;
}
static int
F_235 ( struct V_131 * V_132 , unsigned long V_223 ,
struct V_225 * V_226 , void * V_45 )
{
struct V_227 * V_228 = V_45 ;
struct V_222 * V_229 ;
void * * V_230 ;
V_230 = F_233 ( V_228 , V_223 ) ;
if ( F_90 ( ! V_230 || ! * V_230 ) )
return 0 ;
V_229 = * V_230 ;
F_124 ( V_132 , L_32 , ( void * ) V_223 ) ;
F_124 ( V_132 , L_33 ,
V_229 -> V_74 ? V_232 : V_233 ,
V_229 -> V_61 -> V_5 -> V_6 -> system ,
F_55 ( V_229 -> V_61 -> V_5 ) ) ;
if ( V_229 -> V_231 == - 1 )
F_143 ( V_132 , L_34 ) ;
else
F_124 ( V_132 , L_35 , V_229 -> V_231 ) ;
return 0 ;
}
static int
F_236 ( struct V_225 * V_226 , struct V_42 * V_43 ,
unsigned long V_223 , void * V_234 , void * * V_45 )
{
struct V_227 * V_228 = * V_45 ;
struct V_222 * V_229 = V_234 ;
int V_25 ;
if ( ! V_228 ) {
V_228 = F_237 () ;
if ( ! V_228 )
return - V_39 ;
* V_45 = V_228 ;
}
V_25 = F_238 ( V_228 , V_223 , V_229 ) ;
if ( V_25 < 0 )
return V_25 ;
V_229 -> V_235 ++ ;
return 0 ;
}
static int F_239 ( void * V_45 )
{
struct V_222 * V_229 = V_45 ;
V_229 -> V_235 -- ;
if ( ! V_229 -> V_235 ) {
F_51 ( V_229 -> V_61 , 0 , 1 ) ;
F_240 ( V_229 -> V_61 -> V_5 -> V_194 ) ;
F_91 ( V_229 ) ;
}
return 0 ;
}
static void
F_241 ( struct V_225 * V_226 , struct V_42 * V_43 ,
unsigned long V_223 , void * V_45 )
{
struct V_227 * V_228 = V_45 ;
struct V_222 * V_229 ;
if ( ! V_223 ) {
if ( ! V_228 )
return;
F_242 ( V_228 , F_239 ) ;
return;
}
V_229 = F_243 ( V_228 , V_223 ) ;
if ( F_90 ( ! V_229 ) )
return;
if ( F_90 ( V_229 -> V_235 <= 0 ) )
return;
F_239 ( V_229 ) ;
}
static int
F_244 ( struct V_42 * V_43 , struct V_236 * V_237 ,
char * V_238 , char * V_91 , char * V_239 , int V_240 )
{
struct V_40 * V_61 ;
struct V_225 * V_226 ;
struct V_222 * V_45 ;
const char * system ;
const char * V_38 ;
char * V_241 ;
bool V_74 ;
int V_25 ;
if ( ! V_43 )
return - V_39 ;
if ( ! V_240 || ! V_239 )
return - V_122 ;
system = F_108 ( & V_239 , L_3 ) ;
if ( ! V_239 )
return - V_122 ;
V_38 = F_108 ( & V_239 , L_3 ) ;
F_40 ( & V_75 ) ;
V_25 = - V_122 ;
V_61 = F_230 ( V_43 , system , V_38 ) ;
if ( ! V_61 )
goto V_148;
V_74 = strcmp ( V_91 , V_232 ) == 0 ;
if ( V_74 )
V_226 = V_239 ? & V_242 : & V_243 ;
else
V_226 = V_239 ? & V_244 : & V_245 ;
if ( V_238 [ 0 ] == '!' ) {
V_25 = F_245 ( V_238 + 1 , V_43 , V_226 ) ;
goto V_148;
}
V_25 = - V_22 ;
V_45 = F_168 ( sizeof( * V_45 ) , V_161 ) ;
if ( ! V_45 )
goto V_148;
V_45 -> V_74 = V_74 ;
V_45 -> V_231 = - 1 ;
V_45 -> V_61 = V_61 ;
if ( ! V_239 )
goto V_246;
V_241 = F_108 ( & V_239 , L_3 ) ;
V_25 = - V_122 ;
if ( ! strlen ( V_241 ) )
goto V_175;
V_25 = F_246 ( V_241 , 0 , & V_45 -> V_231 ) ;
if ( V_25 )
goto V_175;
V_246:
V_25 = F_247 ( V_61 -> V_5 -> V_194 ) ;
if ( ! V_25 ) {
V_25 = - V_213 ;
goto V_175;
}
V_25 = F_51 ( V_61 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_138;
V_25 = F_248 ( V_238 , V_43 , V_226 , V_45 ) ;
if ( ! V_25 ) {
V_25 = - V_247 ;
goto V_248;
} else if ( V_25 < 0 )
goto V_248;
V_25 = 0 ;
V_148:
F_47 ( & V_75 ) ;
return V_25 ;
V_248:
F_51 ( V_61 , 0 , 1 ) ;
V_138:
F_240 ( V_61 -> V_5 -> V_194 ) ;
V_175:
F_91 ( V_45 ) ;
goto V_148;
}
static T_6 int F_249 ( void )
{
int V_25 ;
V_25 = F_250 ( & V_249 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_250 ( & V_250 ) ;
if ( F_13 ( V_25 < 0 ) )
F_251 ( & V_249 ) ;
return V_25 ;
}
static inline int F_249 ( void ) { return 0 ; }
static T_6 void
F_252 ( struct V_42 * V_43 )
{
struct V_40 * V_61 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_198 ( V_43 -> V_211 , V_61 ) ;
if ( V_25 < 0 )
F_195 ( L_31 ,
F_55 ( V_61 -> V_5 ) ) ;
}
}
static T_6 void
F_253 ( struct V_42 * V_43 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_90 ( V_13 -> V_194 ) )
continue;
V_25 = F_216 ( V_13 , V_43 ) ;
if ( V_25 < 0 )
F_195 ( L_36 ,
F_55 ( V_13 ) ) ;
}
}
static void
F_254 ( struct V_42 * V_43 )
{
struct V_40 * V_61 , * V_35 ;
F_19 (file, next, &tr->events, list)
F_99 ( V_61 ) ;
}
static void F_218 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_215 ( V_13 , V_43 ) ;
}
static T_6 int F_255 ( char * V_251 )
{
F_256 ( V_252 , V_251 , V_253 ) ;
V_254 = true ;
V_255 = true ;
return 1 ;
}
static int
F_257 ( struct V_114 * V_177 , struct V_42 * V_43 )
{
struct V_114 * V_182 ;
struct V_114 * V_59 ;
V_59 = F_196 ( L_37 , 0644 , V_177 ,
V_43 , & V_256 ) ;
if ( ! V_59 ) {
F_195 ( L_38 ) ;
return - V_22 ;
}
V_182 = F_194 ( L_39 , V_177 ) ;
if ( ! V_182 ) {
F_195 ( L_40 ) ;
return - V_22 ;
}
V_59 = F_197 ( L_20 , 0644 , V_182 ,
V_43 , & V_257 ) ;
if ( ! V_59 ) {
F_195 ( L_41 ) ;
return - V_22 ;
}
V_59 = F_196 ( L_42 , 0644 , V_177 ,
V_43 , & V_258 ) ;
if ( ! V_59 )
F_195 ( L_43 ) ;
V_59 = F_197 ( L_44 , 0444 , V_182 ,
V_259 ,
& V_260 ) ;
if ( ! V_59 )
F_195 ( L_45 ) ;
V_59 = F_197 ( L_46 , 0444 , V_182 ,
V_261 ,
& V_260 ) ;
if ( ! V_59 )
F_195 ( L_47 ) ;
V_43 -> V_211 = V_182 ;
return 0 ;
}
int F_258 ( struct V_114 * V_177 , struct V_42 * V_43 )
{
int V_25 ;
F_40 ( & V_75 ) ;
V_25 = F_257 ( V_177 , V_43 ) ;
if ( V_25 )
goto V_262;
F_210 ( & V_208 ) ;
F_229 ( V_43 ) ;
F_211 ( & V_208 ) ;
V_262:
F_47 ( & V_75 ) ;
return V_25 ;
}
static T_6 int
F_259 ( struct V_114 * V_177 , struct V_42 * V_43 )
{
int V_25 ;
F_40 ( & V_75 ) ;
V_25 = F_257 ( V_177 , V_43 ) ;
if ( V_25 )
goto V_262;
F_210 ( & V_208 ) ;
F_252 ( V_43 ) ;
F_211 ( & V_208 ) ;
V_262:
F_47 ( & V_75 ) ;
return V_25 ;
}
int F_260 ( struct V_42 * V_43 )
{
F_40 ( & V_75 ) ;
F_261 ( V_43 ) ;
F_76 ( V_43 ) ;
F_105 ( V_43 , NULL , NULL , NULL , 0 ) ;
F_86 () ;
F_210 ( & V_208 ) ;
F_254 ( V_43 ) ;
F_98 ( V_43 -> V_211 ) ;
F_211 ( & V_208 ) ;
V_43 -> V_211 = NULL ;
F_47 ( & V_75 ) ;
return 0 ;
}
static T_6 int F_262 ( void )
{
V_20 = F_263 ( V_9 , V_263 ) ;
V_118 = F_263 ( V_40 , V_263 ) ;
return 0 ;
}
static T_6 void
F_264 ( struct V_42 * V_43 , bool V_264 )
{
char * V_125 = V_252 ;
char * V_265 ;
int V_25 ;
while ( true ) {
V_265 = F_108 ( & V_125 , L_48 ) ;
if ( ! V_265 )
break;
if ( * V_265 ) {
if ( V_264 )
F_107 ( V_43 , V_265 , 0 ) ;
V_25 = F_107 ( V_43 , V_265 , 1 ) ;
if ( V_25 )
F_195 ( L_49 , V_265 ) ;
}
if ( V_125 )
* ( V_125 - 1 ) = ',' ;
}
}
static T_6 int F_265 ( void )
{
struct V_42 * V_43 = F_110 () ;
struct V_4 * * V_266 , * V_13 ;
int V_25 ;
if ( ! V_43 )
return - V_39 ;
F_225 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_13 = * V_266 ;
V_25 = F_205 ( V_13 ) ;
if ( ! V_25 )
F_11 ( & V_13 -> V_108 , & V_195 ) ;
}
F_253 ( V_43 ) ;
F_264 ( V_43 , false ) ;
F_266 () ;
F_249 () ;
F_267 () ;
return 0 ;
}
static T_6 int F_268 ( void )
{
struct V_42 * V_43 ;
V_43 = F_110 () ;
if ( ! V_43 )
return - V_39 ;
F_264 ( V_43 , true ) ;
return 0 ;
}
static T_6 int F_269 ( void )
{
struct V_42 * V_43 ;
struct V_114 * V_267 ;
struct V_114 * V_59 ;
int V_25 ;
V_43 = F_110 () ;
if ( ! V_43 )
return - V_39 ;
V_267 = F_270 () ;
if ( F_159 ( V_267 ) )
return 0 ;
V_59 = F_196 ( L_50 , 0444 , V_267 ,
V_43 , & V_268 ) ;
if ( ! V_59 )
F_195 ( L_51 ) ;
if ( F_14 () )
F_195 ( L_52 ) ;
if ( F_16 () )
F_195 ( L_53 ) ;
V_25 = F_259 ( V_267 , V_43 ) ;
if ( V_25 )
return V_25 ;
#ifdef F_271
V_25 = F_272 ( & V_269 ) ;
if ( V_25 )
F_195 ( L_54 ) ;
#endif
return 0 ;
}
void T_6 F_273 ( void )
{
F_262 () ;
F_274 () ;
F_265 () ;
}
static T_6 void F_275 ( struct V_270 * V_271 )
{
F_100 ( & V_272 ) ;
F_276 ( & V_273 ) ;
F_277 ( 1 ) ;
F_278 ( & V_273 ) ;
F_103 ( & V_272 ) ;
F_40 ( & V_274 ) ;
F_279 ( 1 ) ;
F_47 ( & V_274 ) ;
}
static T_6 int F_280 ( void * V_275 )
{
void * V_276 ;
V_276 = F_153 ( 1234 , V_161 ) ;
if ( ! V_276 )
F_54 ( L_55 ) ;
F_281 ( F_275 ) ;
F_91 ( V_276 ) ;
F_282 ( V_277 ) ;
while ( ! F_283 () ) {
F_284 () ;
F_282 ( V_277 ) ;
}
F_285 ( V_278 ) ;
return 0 ;
}
static T_6 void F_286 ( void )
{
struct V_97 * V_279 ;
V_279 = F_287 ( F_280 , NULL , L_56 ) ;
F_279 ( 1 ) ;
F_288 ( V_279 ) ;
}
static T_6 void F_289 ( void )
{
struct V_110 * V_111 ;
struct V_40 * V_61 ;
struct V_4 * V_13 ;
struct V_1 * system ;
struct V_42 * V_43 ;
int V_25 ;
V_43 = F_110 () ;
if ( ! V_43 )
return;
F_54 ( L_57 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_61 -> V_5 ;
if ( ! V_13 -> V_6 || ! V_13 -> V_6 -> V_65 )
continue;
#ifndef F_290
if ( V_13 -> V_6 -> system &&
strcmp ( V_13 -> V_6 -> system , L_58 ) == 0 )
continue;
#endif
F_54 ( L_59 , F_55 ( V_13 ) ) ;
if ( V_61 -> V_54 & V_76 ) {
F_195 ( L_60 ) ;
F_90 ( 1 ) ;
continue;
}
F_59 ( V_61 , 1 ) ;
F_286 () ;
F_59 ( V_61 , 0 ) ;
F_291 ( L_61 ) ;
}
F_54 ( L_62 ) ;
F_6 (dir, &tr->systems, list) {
system = V_111 -> V_112 ;
if ( strcmp ( system -> V_11 , L_63 ) == 0 )
continue;
F_54 ( L_64 , system -> V_11 ) ;
V_25 = F_106 ( V_43 , NULL , system -> V_11 , NULL , 1 ) ;
if ( F_90 ( V_25 ) ) {
F_195 ( L_65 ,
system -> V_11 ) ;
continue;
}
F_286 () ;
V_25 = F_106 ( V_43 , NULL , system -> V_11 , NULL , 0 ) ;
if ( F_90 ( V_25 ) ) {
F_195 ( L_66 ,
system -> V_11 ) ;
continue;
}
F_291 ( L_61 ) ;
}
F_54 ( L_67 ) ;
F_54 ( L_68 ) ;
V_25 = F_106 ( V_43 , NULL , NULL , NULL , 1 ) ;
if ( F_90 ( V_25 ) ) {
F_195 ( L_69 ) ;
return;
}
F_286 () ;
V_25 = F_106 ( V_43 , NULL , NULL , NULL , 0 ) ;
if ( F_90 ( V_25 ) ) {
F_195 ( L_70 ) ;
return;
}
F_291 ( L_61 ) ;
}
static void T_6
F_292 ( unsigned long V_223 , unsigned long V_224 ,
struct V_280 * V_281 , struct V_282 * V_282 )
{
struct V_283 * V_38 ;
struct V_284 * V_58 ;
struct V_285 * V_59 ;
unsigned long V_54 ;
long V_286 ;
int V_28 ;
int V_56 ;
V_56 = F_31 () ;
F_293 () ;
V_28 = F_294 () ;
V_286 = F_53 ( & F_295 ( V_287 , V_28 ) ) ;
if ( V_286 != 1 )
goto V_148;
F_30 ( V_54 ) ;
V_38 = F_33 ( & V_58 , & V_288 ,
V_289 , sizeof( * V_59 ) ,
V_54 , V_56 ) ;
if ( ! V_38 )
goto V_148;
V_59 = F_34 ( V_38 ) ;
V_59 -> V_223 = V_223 ;
V_59 -> V_224 = V_224 ;
F_296 ( & V_288 , V_58 , V_38 ,
V_59 , V_54 , V_56 ) ;
V_148:
F_297 ( & F_295 ( V_287 , V_28 ) ) ;
F_298 () ;
}
static T_6 void F_299 ( void )
{
int V_25 ;
V_288 . V_43 = F_110 () ;
if ( F_13 ( ! V_288 . V_43 ) )
return;
V_25 = F_300 ( & V_290 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_54 ( L_71 ) ;
return;
}
F_54 ( L_72 ) ;
F_289 () ;
F_301 ( & V_290 ) ;
}
static T_6 void F_299 ( void )
{
}
static T_6 int F_302 ( void )
{
if ( ! V_255 ) {
F_289 () ;
F_299 () ;
}
return 0 ;
}
