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
static int F_48 ( struct V_40 * V_61 ,
int V_74 , int V_78 )
{
struct V_4 * V_13 = V_61 -> V_5 ;
struct V_42 * V_43 = V_61 -> V_43 ;
unsigned long V_79 = V_61 -> V_54 ;
int V_25 = 0 ;
int V_80 ;
switch ( V_74 ) {
case 0 :
if ( V_78 ) {
if ( F_49 ( & V_61 -> V_81 ) > 0 )
break;
V_80 = V_61 -> V_54 & V_82 ;
F_45 ( V_83 , & V_61 -> V_54 ) ;
} else
V_80 = ! ( V_61 -> V_54 & V_84 ) ;
if ( V_80 && ( V_61 -> V_54 & V_76 ) ) {
F_45 ( V_85 , & V_61 -> V_54 ) ;
if ( V_61 -> V_54 & V_86 ) {
F_44 () ;
F_45 ( V_77 , & V_61 -> V_54 ) ;
}
V_13 -> V_6 -> V_87 ( V_13 , V_66 , V_61 ) ;
}
if ( V_61 -> V_54 & V_84 )
F_43 ( V_88 , & V_61 -> V_54 ) ;
else
F_45 ( V_88 , & V_61 -> V_54 ) ;
break;
case 1 :
if ( ! V_78 )
F_45 ( V_88 , & V_61 -> V_54 ) ;
else {
if ( F_50 ( & V_61 -> V_81 ) > 1 )
break;
F_43 ( V_83 , & V_61 -> V_54 ) ;
}
if ( ! ( V_61 -> V_54 & V_76 ) ) {
if ( V_78 )
F_43 ( V_88 , & V_61 -> V_54 ) ;
if ( V_43 -> V_89 & V_90 ) {
F_42 () ;
F_43 ( V_77 , & V_61 -> V_54 ) ;
}
V_25 = V_13 -> V_6 -> V_87 ( V_13 , V_63 , V_61 ) ;
if ( V_25 ) {
F_44 () ;
F_51 ( L_1
L_2 , F_52 ( V_13 ) ) ;
break;
}
F_43 ( V_85 , & V_61 -> V_54 ) ;
V_13 -> V_54 |= V_91 ;
}
break;
}
if ( ( V_79 & V_82 ) !=
( V_61 -> V_54 & V_82 ) ) {
if ( V_61 -> V_54 & V_82 )
F_53 () ;
else
F_54 () ;
}
return V_25 ;
}
int F_55 ( struct V_40 * V_61 ,
int V_74 , int V_78 )
{
return F_48 ( V_61 , V_74 , V_78 ) ;
}
static int F_56 ( struct V_40 * V_61 ,
int V_74 )
{
return F_48 ( V_61 , V_74 , 0 ) ;
}
static void F_57 ( struct V_42 * V_43 )
{
struct V_40 * V_61 ;
F_40 ( & V_75 ) ;
F_6 (file, &tr->events, list) {
F_56 ( V_61 , 0 ) ;
}
F_47 ( & V_75 ) ;
}
static void
F_58 ( void * V_45 , struct V_92 * V_93 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_45 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_59 ( V_47 , NULL , V_93 ) ;
}
static void
F_60 ( void * V_45 ,
struct V_92 * V_94 ,
struct V_92 * V_93 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_45 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_59 ( V_47 , V_94 , V_93 ) ;
}
void F_61 ( struct V_42 * V_43 , bool V_74 )
{
if ( V_74 ) {
F_62 ( F_60 ,
V_43 , V_95 ) ;
F_63 ( F_58 ,
V_43 , V_96 ) ;
} else {
F_64 ( F_60 ,
V_43 ) ;
F_65 ( F_58 ,
V_43 ) ;
}
}
static void
F_66 ( void * V_45 , bool V_97 ,
struct V_92 * V_98 , struct V_92 * V_35 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_67 ( V_43 -> V_49 . V_45 -> V_50 ,
F_68 ( V_47 , V_98 ) &&
F_68 ( V_47 , V_35 ) ) ;
}
static void
F_69 ( void * V_45 , bool V_97 ,
struct V_92 * V_98 , struct V_92 * V_35 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_67 ( V_43 -> V_49 . V_45 -> V_50 ,
F_68 ( V_47 , V_35 ) ) ;
}
static void
F_70 ( void * V_45 , struct V_92 * V_93 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
if ( ! F_71 ( V_43 -> V_49 . V_45 -> V_50 ) )
return;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_67 ( V_43 -> V_49 . V_45 -> V_50 ,
F_68 ( V_47 , V_93 ) ) ;
}
static void
F_72 ( void * V_45 , struct V_92 * V_93 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
if ( F_71 ( V_43 -> V_49 . V_45 -> V_50 ) )
return;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_67 ( V_43 -> V_49 . V_45 -> V_50 ,
F_68 ( V_47 , V_99 ) ) ;
}
static void F_73 ( struct V_42 * V_43 )
{
struct V_46 * V_47 ;
struct V_40 * V_61 ;
int V_28 ;
V_47 = F_74 ( V_43 -> V_48 ,
F_75 ( & V_75 ) ) ;
if ( ! V_47 )
return;
F_76 ( F_66 , V_43 ) ;
F_76 ( F_69 , V_43 ) ;
F_77 ( F_70 , V_43 ) ;
F_77 ( F_72 , V_43 ) ;
F_78 ( F_70 , V_43 ) ;
F_78 ( F_72 , V_43 ) ;
F_79 ( F_70 , V_43 ) ;
F_79 ( F_72 , V_43 ) ;
F_6 (file, &tr->events, list) {
F_45 ( V_100 , & V_61 -> V_54 ) ;
}
F_80 (cpu)
F_81 ( V_43 -> V_49 . V_45 , V_28 ) -> V_50 = false ;
F_82 ( V_43 -> V_48 , NULL ) ;
F_83 () ;
F_84 ( V_47 ) ;
}
static void F_85 ( struct V_42 * V_43 )
{
F_40 ( & V_75 ) ;
F_73 ( V_43 ) ;
F_47 ( & V_75 ) ;
}
static void F_86 ( struct V_1 * system )
{
struct V_101 * V_102 = system -> V_102 ;
F_87 ( F_1 ( system ) == 0 ) ;
if ( F_3 ( system ) )
return;
F_20 ( & system -> V_103 ) ;
if ( V_102 ) {
F_88 ( V_102 -> V_104 ) ;
F_88 ( V_102 ) ;
}
F_89 ( system -> V_11 ) ;
F_88 ( system ) ;
}
static void F_90 ( struct V_1 * system )
{
F_87 ( F_1 ( system ) == 0 ) ;
F_2 ( system ) ;
}
static void F_91 ( struct V_105 * V_106 )
{
F_87 ( V_106 -> V_2 == 0 ) ;
V_106 -> V_2 ++ ;
F_90 ( V_106 -> V_107 ) ;
}
static void F_92 ( struct V_105 * V_106 )
{
F_87 ( V_106 -> V_2 == 0 ) ;
F_87 ( F_1 ( V_106 -> V_107 ) == 1 && V_106 -> V_2 != 1 ) ;
F_86 ( V_106 -> V_107 ) ;
if ( ! -- V_106 -> V_2 )
F_88 ( V_106 ) ;
}
static void F_93 ( struct V_105 * V_106 )
{
F_40 ( & V_75 ) ;
F_92 ( V_106 ) ;
F_47 ( & V_75 ) ;
}
static void F_94 ( struct V_105 * V_106 )
{
if ( ! V_106 )
return;
if ( ! -- V_106 -> V_108 ) {
F_95 ( V_106 -> V_59 ) ;
F_20 ( & V_106 -> V_103 ) ;
F_92 ( V_106 ) ;
}
}
static void F_96 ( struct V_40 * V_61 )
{
struct V_109 * V_106 = V_61 -> V_106 ;
struct V_109 * V_110 ;
if ( V_106 ) {
F_97 ( & V_106 -> V_111 ) ;
F_6 (child, &dir->d_subdirs, d_child) {
if ( F_98 ( V_110 ) )
F_99 ( V_110 ) -> V_112 = NULL ;
}
F_100 ( & V_106 -> V_111 ) ;
F_95 ( V_106 ) ;
}
F_20 ( & V_61 -> V_103 ) ;
F_94 ( V_61 -> system ) ;
F_101 ( V_61 -> V_102 ) ;
F_21 ( V_113 , V_61 ) ;
}
static int
F_102 ( struct V_42 * V_43 , const char * V_114 ,
const char * V_115 , const char * V_38 , int V_116 )
{
struct V_40 * V_61 ;
struct V_4 * V_13 ;
const char * V_11 ;
int V_25 = - V_117 ;
int V_118 = 0 ;
F_6 (file, &tr->events, list) {
V_13 = V_61 -> V_5 ;
V_11 = F_52 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_87 )
continue;
if ( V_13 -> V_54 & V_119 )
continue;
if ( V_114 &&
strcmp ( V_114 , V_11 ) != 0 &&
strcmp ( V_114 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_115 && strcmp ( V_115 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_38 && strcmp ( V_38 , V_11 ) != 0 )
continue;
V_25 = F_56 ( V_61 , V_116 ) ;
if ( V_25 && ! V_118 )
V_118 = V_25 ;
V_25 = V_118 ;
}
return V_25 ;
}
static int F_103 ( struct V_42 * V_43 , const char * V_114 ,
const char * V_115 , const char * V_38 , int V_116 )
{
int V_25 ;
F_40 ( & V_75 ) ;
V_25 = F_102 ( V_43 , V_114 , V_115 , V_38 , V_116 ) ;
F_47 ( & V_75 ) ;
return V_25 ;
}
static int F_104 ( struct V_42 * V_43 , char * V_120 , int V_116 )
{
char * V_38 = NULL , * V_115 = NULL , * V_114 ;
int V_25 ;
V_114 = F_105 ( & V_120 , L_3 ) ;
if ( V_120 ) {
V_115 = V_114 ;
V_38 = V_120 ;
V_114 = NULL ;
if ( ! strlen ( V_115 ) || strcmp ( V_115 , L_4 ) == 0 )
V_115 = NULL ;
if ( ! strlen ( V_38 ) || strcmp ( V_38 , L_4 ) == 0 )
V_38 = NULL ;
}
V_25 = F_103 ( V_43 , V_114 , V_115 , V_38 , V_116 ) ;
if ( V_120 )
* ( V_120 - 1 ) = ':' ;
return V_25 ;
}
int F_106 ( const char * system , const char * V_38 , int V_116 )
{
struct V_42 * V_43 = F_107 () ;
if ( ! V_43 )
return - V_39 ;
return F_103 ( V_43 , NULL , system , V_38 , V_116 ) ;
}
static T_1
F_108 ( struct V_61 * V_61 , const char T_2 * V_121 ,
T_3 V_122 , T_4 * V_123 )
{
struct V_124 V_125 ;
struct V_126 * V_127 = V_61 -> V_128 ;
struct V_42 * V_43 = V_127 -> V_129 ;
T_1 V_130 , V_25 ;
if ( ! V_122 )
return 0 ;
V_25 = F_109 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_110 ( & V_125 , V_131 + 1 ) )
return - V_22 ;
V_130 = F_111 ( & V_125 , V_121 , V_122 , V_123 ) ;
if ( V_130 >= 0 && F_112 ( ( & V_125 ) ) ) {
int V_116 = 1 ;
if ( * V_125 . V_58 == '!' )
V_116 = 0 ;
V_125 . V_58 [ V_125 . V_132 ] = 0 ;
V_25 = F_104 ( V_43 , V_125 . V_58 + ! V_116 , V_116 ) ;
if ( V_25 )
goto V_133;
}
V_25 = V_130 ;
V_133:
F_113 ( & V_125 ) ;
return V_25 ;
}
static void *
F_114 ( struct V_126 * V_127 , void * V_134 , T_4 * V_135 )
{
struct V_40 * V_61 = V_134 ;
struct V_4 * V_13 ;
struct V_42 * V_43 = V_127 -> V_129 ;
( * V_135 ) ++ ;
F_115 (file, &tr->events, list) {
V_13 = V_61 -> V_5 ;
if ( V_13 -> V_6 && V_13 -> V_6 -> V_87 &&
! ( V_13 -> V_54 & V_119 ) )
return V_61 ;
}
return NULL ;
}
static void * F_116 ( struct V_126 * V_127 , T_4 * V_135 )
{
struct V_40 * V_61 ;
struct V_42 * V_43 = V_127 -> V_129 ;
T_4 V_136 ;
F_40 ( & V_75 ) ;
V_61 = F_117 ( & V_43 -> V_137 , struct V_40 , V_103 ) ;
for ( V_136 = 0 ; V_136 <= * V_135 ; ) {
V_61 = F_114 ( V_127 , V_61 , & V_136 ) ;
if ( ! V_61 )
break;
}
return V_61 ;
}
static void *
F_118 ( struct V_126 * V_127 , void * V_134 , T_4 * V_135 )
{
struct V_40 * V_61 = V_134 ;
struct V_42 * V_43 = V_127 -> V_129 ;
( * V_135 ) ++ ;
F_115 (file, &tr->events, list) {
if ( V_61 -> V_54 & V_76 )
return V_61 ;
}
return NULL ;
}
static void * F_119 ( struct V_126 * V_127 , T_4 * V_135 )
{
struct V_40 * V_61 ;
struct V_42 * V_43 = V_127 -> V_129 ;
T_4 V_136 ;
F_40 ( & V_75 ) ;
V_61 = F_117 ( & V_43 -> V_137 , struct V_40 , V_103 ) ;
for ( V_136 = 0 ; V_136 <= * V_135 ; ) {
V_61 = F_118 ( V_127 , V_61 , & V_136 ) ;
if ( ! V_61 )
break;
}
return V_61 ;
}
static int F_120 ( struct V_126 * V_127 , void * V_134 )
{
struct V_40 * V_61 = V_134 ;
struct V_4 * V_13 = V_61 -> V_5 ;
if ( strcmp ( V_13 -> V_6 -> system , V_138 ) != 0 )
F_121 ( V_127 , L_5 , V_13 -> V_6 -> system ) ;
F_121 ( V_127 , L_2 , F_52 ( V_13 ) ) ;
return 0 ;
}
static void F_122 ( struct V_126 * V_127 , void * V_139 )
{
F_47 ( & V_75 ) ;
}
static void *
F_123 ( struct V_126 * V_127 , void * V_134 , T_4 * V_135 )
{
struct V_42 * V_43 = V_127 -> V_129 ;
struct V_46 * V_47 = F_27 ( V_43 -> V_48 ) ;
return F_124 ( V_47 , V_134 , V_135 ) ;
}
static void * F_125 ( struct V_126 * V_127 , T_4 * V_135 )
__acquires( T_5 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_127 -> V_129 ;
F_40 ( & V_75 ) ;
F_126 () ;
V_47 = F_27 ( V_43 -> V_48 ) ;
if ( ! V_47 )
return NULL ;
return F_127 ( V_47 , V_135 ) ;
}
static void F_128 ( struct V_126 * V_127 , void * V_139 )
__releases( T_5 )
{
F_129 () ;
F_47 ( & V_75 ) ;
}
static T_1
F_130 ( struct V_61 * V_140 , char T_2 * V_121 , T_3 V_122 ,
T_4 * V_123 )
{
struct V_40 * V_61 ;
unsigned long V_54 ;
char V_120 [ 4 ] = L_6 ;
F_40 ( & V_75 ) ;
V_61 = F_131 ( V_140 ) ;
if ( F_132 ( V_61 ) )
V_54 = V_61 -> V_54 ;
F_47 ( & V_75 ) ;
if ( ! V_61 )
return - V_39 ;
if ( V_54 & V_76 &&
! ( V_54 & V_82 ) )
strcpy ( V_120 , L_7 ) ;
if ( V_54 & V_82 ||
V_54 & V_84 )
strcat ( V_120 , L_4 ) ;
strcat ( V_120 , L_8 ) ;
return F_133 ( V_121 , V_122 , V_123 , V_120 , strlen ( V_120 ) ) ;
}
static T_1
F_134 ( struct V_61 * V_140 , const char T_2 * V_121 , T_3 V_122 ,
T_4 * V_123 )
{
struct V_40 * V_61 ;
unsigned long V_141 ;
int V_25 ;
V_25 = F_135 ( V_121 , V_122 , 10 , & V_141 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_109 () ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_141 ) {
case 0 :
case 1 :
V_25 = - V_39 ;
F_40 ( & V_75 ) ;
V_61 = F_131 ( V_140 ) ;
if ( F_132 ( V_61 ) )
V_25 = F_56 ( V_61 , V_141 ) ;
F_47 ( & V_75 ) ;
break;
default:
return - V_117 ;
}
* V_123 += V_122 ;
return V_25 ? V_25 : V_122 ;
}
static T_1
F_136 ( struct V_61 * V_140 , char T_2 * V_121 , T_3 V_122 ,
T_4 * V_123 )
{
const char V_142 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_105 * V_106 = V_140 -> V_128 ;
struct V_1 * system = V_106 -> V_107 ;
struct V_4 * V_13 ;
struct V_40 * V_61 ;
struct V_42 * V_43 = V_106 -> V_43 ;
char V_120 [ 2 ] ;
int V_116 = 0 ;
int V_25 ;
F_40 ( & V_75 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_61 -> V_5 ;
if ( ! F_52 ( V_13 ) || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_87 )
continue;
if ( system && strcmp ( V_13 -> V_6 -> system , system -> V_11 ) != 0 )
continue;
V_116 |= ( 1 << ! ! ( V_61 -> V_54 & V_76 ) ) ;
if ( V_116 == 3 )
break;
}
F_47 ( & V_75 ) ;
V_120 [ 0 ] = V_142 [ V_116 ] ;
V_120 [ 1 ] = '\n' ;
V_25 = F_133 ( V_121 , V_122 , V_123 , V_120 , 2 ) ;
return V_25 ;
}
static T_1
F_137 ( struct V_61 * V_140 , const char T_2 * V_121 , T_3 V_122 ,
T_4 * V_123 )
{
struct V_105 * V_106 = V_140 -> V_128 ;
struct V_1 * system = V_106 -> V_107 ;
const char * V_11 = NULL ;
unsigned long V_141 ;
T_1 V_25 ;
V_25 = F_135 ( V_121 , V_122 , 10 , & V_141 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_109 () ;
if ( V_25 < 0 )
return V_25 ;
if ( V_141 != 0 && V_141 != 1 )
return - V_117 ;
if ( system )
V_11 = system -> V_11 ;
V_25 = F_103 ( V_106 -> V_43 , NULL , V_11 , NULL , V_141 ) ;
if ( V_25 )
goto V_143;
V_25 = V_122 ;
V_143:
* V_123 += V_122 ;
return V_25 ;
}
static void * F_138 ( struct V_126 * V_127 , void * V_134 , T_4 * V_135 )
{
struct V_4 * V_13 = F_131 ( V_127 -> V_129 ) ;
struct V_3 * V_144 = & V_15 ;
struct V_3 * V_10 = F_4 ( V_13 ) ;
struct V_3 * V_145 = V_134 ;
( * V_135 ) ++ ;
switch ( ( unsigned long ) V_134 ) {
case V_146 :
V_145 = V_144 ;
break;
case V_147 :
V_145 = V_10 ;
break;
case V_148 :
return NULL ;
}
V_145 = V_145 -> V_98 ;
if ( V_145 == V_144 )
return ( void * ) V_147 ;
else if ( V_145 == V_10 )
return ( void * ) V_148 ;
else
return V_145 ;
}
static int F_139 ( struct V_126 * V_127 , void * V_134 )
{
struct V_4 * V_13 = F_131 ( V_127 -> V_129 ) ;
struct V_9 * V_12 ;
const char * V_149 ;
switch ( ( unsigned long ) V_134 ) {
case V_146 :
F_121 ( V_127 , L_9 , F_52 ( V_13 ) ) ;
F_121 ( V_127 , L_10 , V_13 -> V_38 . type ) ;
F_140 ( V_127 , L_11 ) ;
return 0 ;
case V_147 :
F_141 ( V_127 , '\n' ) ;
return 0 ;
case V_148 :
F_121 ( V_127 , L_12 ,
V_13 -> V_150 ) ;
return 0 ;
}
V_12 = F_117 ( V_134 , struct V_9 , V_24 ) ;
V_149 = strchr ( V_12 -> type , '[' ) ;
if ( ! strncmp ( V_12 -> type , L_13 , 10 ) )
V_149 = NULL ;
if ( ! V_149 )
F_121 ( V_127 , L_14 ,
V_12 -> type , V_12 -> V_11 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
else
F_121 ( V_127 , L_15 ,
( int ) ( V_149 - V_12 -> type ) ,
V_12 -> type , V_12 -> V_11 ,
V_149 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
return 0 ;
}
static void * F_142 ( struct V_126 * V_127 , T_4 * V_135 )
{
void * V_139 = ( void * ) V_146 ;
T_4 V_136 = 0 ;
F_40 ( & V_75 ) ;
if ( ! F_131 ( V_127 -> V_129 ) )
return F_143 ( - V_39 ) ;
while ( V_136 < * V_135 && V_139 )
V_139 = F_138 ( V_127 , V_139 , & V_136 ) ;
return V_139 ;
}
static void F_144 ( struct V_126 * V_127 , void * V_139 )
{
F_47 ( & V_75 ) ;
}
static int F_145 ( struct V_151 * V_151 , struct V_61 * V_61 )
{
struct V_126 * V_127 ;
int V_25 ;
V_25 = F_146 ( V_61 , & V_152 ) ;
if ( V_25 < 0 )
return V_25 ;
V_127 = V_61 -> V_128 ;
V_127 -> V_129 = V_61 ;
return 0 ;
}
static T_1
F_147 ( struct V_61 * V_140 , char T_2 * V_121 , T_3 V_122 , T_4 * V_123 )
{
int V_37 = ( long ) F_131 ( V_140 ) ;
char V_120 [ 32 ] ;
int V_53 ;
if ( * V_123 )
return 0 ;
if ( F_148 ( ! V_37 ) )
return - V_39 ;
V_53 = sprintf ( V_120 , L_16 , V_37 ) ;
return F_133 ( V_121 , V_122 , V_123 , V_120 , V_53 ) ;
}
static T_1
F_149 ( struct V_61 * V_140 , char T_2 * V_121 , T_3 V_122 ,
T_4 * V_123 )
{
struct V_40 * V_61 ;
struct V_153 * V_154 ;
int V_155 = - V_39 ;
if ( * V_123 )
return 0 ;
V_154 = F_150 ( sizeof( * V_154 ) , V_156 ) ;
if ( ! V_154 )
return - V_22 ;
F_151 ( V_154 ) ;
F_40 ( & V_75 ) ;
V_61 = F_131 ( V_140 ) ;
if ( V_61 )
F_152 ( V_61 , V_154 ) ;
F_47 ( & V_75 ) ;
if ( V_61 )
V_155 = F_133 ( V_121 , V_122 , V_123 ,
V_154 -> V_58 , F_153 ( V_154 ) ) ;
F_88 ( V_154 ) ;
return V_155 ;
}
static T_1
F_154 ( struct V_61 * V_140 , const char T_2 * V_121 , T_3 V_122 ,
T_4 * V_123 )
{
struct V_40 * V_61 ;
char * V_120 ;
int V_157 = - V_39 ;
if ( V_122 >= V_158 )
return - V_117 ;
V_120 = F_155 ( V_121 , V_122 ) ;
if ( F_156 ( V_120 ) )
return F_157 ( V_120 ) ;
F_40 ( & V_75 ) ;
V_61 = F_131 ( V_140 ) ;
if ( V_61 )
V_157 = F_158 ( V_61 , V_120 ) ;
F_47 ( & V_75 ) ;
F_88 ( V_120 ) ;
if ( V_157 < 0 )
return V_157 ;
* V_123 += V_122 ;
return V_122 ;
}
static int F_159 ( struct V_151 * V_151 , struct V_61 * V_140 )
{
struct V_1 * system = NULL ;
struct V_105 * V_106 = NULL ;
struct V_42 * V_43 ;
int V_25 ;
if ( F_160 () )
return - V_39 ;
F_40 ( & V_159 ) ;
F_40 ( & V_75 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_106 == V_151 -> V_112 ) {
if ( V_106 -> V_108 ) {
F_91 ( V_106 ) ;
system = V_106 -> V_107 ;
}
goto V_160;
}
}
}
V_160:
F_47 ( & V_75 ) ;
F_47 ( & V_159 ) ;
if ( ! system )
return - V_39 ;
F_13 ( ! V_106 ) ;
if ( F_161 ( V_43 ) < 0 ) {
F_93 ( V_106 ) ;
return - V_39 ;
}
V_25 = F_162 ( V_151 , V_140 ) ;
if ( V_25 < 0 ) {
F_163 ( V_43 ) ;
F_93 ( V_106 ) ;
}
return V_25 ;
}
static int F_164 ( struct V_151 * V_151 , struct V_61 * V_140 )
{
struct V_105 * V_106 ;
struct V_42 * V_43 = V_151 -> V_112 ;
int V_25 ;
if ( F_160 () )
return - V_39 ;
if ( F_161 ( V_43 ) < 0 )
return - V_39 ;
V_106 = F_165 ( sizeof( * V_106 ) , V_156 ) ;
if ( ! V_106 ) {
F_163 ( V_43 ) ;
return - V_22 ;
}
V_106 -> V_43 = V_43 ;
V_25 = F_162 ( V_151 , V_140 ) ;
if ( V_25 < 0 ) {
F_163 ( V_43 ) ;
F_88 ( V_106 ) ;
return V_25 ;
}
V_140 -> V_128 = V_106 ;
return 0 ;
}
static int F_166 ( struct V_151 * V_151 , struct V_61 * V_61 )
{
struct V_105 * V_106 = V_61 -> V_128 ;
F_163 ( V_106 -> V_43 ) ;
if ( V_106 -> V_107 )
F_93 ( V_106 ) ;
else
F_88 ( V_106 ) ;
return 0 ;
}
static T_1
F_167 ( struct V_61 * V_140 , char T_2 * V_121 , T_3 V_122 ,
T_4 * V_123 )
{
struct V_105 * V_106 = V_140 -> V_128 ;
struct V_1 * system = V_106 -> V_107 ;
struct V_153 * V_154 ;
int V_155 ;
if ( * V_123 )
return 0 ;
V_154 = F_150 ( sizeof( * V_154 ) , V_156 ) ;
if ( ! V_154 )
return - V_22 ;
F_151 ( V_154 ) ;
F_168 ( system , V_154 ) ;
V_155 = F_133 ( V_121 , V_122 , V_123 ,
V_154 -> V_58 , F_153 ( V_154 ) ) ;
F_88 ( V_154 ) ;
return V_155 ;
}
static T_1
F_169 ( struct V_61 * V_140 , const char T_2 * V_121 , T_3 V_122 ,
T_4 * V_123 )
{
struct V_105 * V_106 = V_140 -> V_128 ;
char * V_120 ;
int V_157 ;
if ( V_122 >= V_158 )
return - V_117 ;
V_120 = F_155 ( V_121 , V_122 ) ;
if ( F_156 ( V_120 ) )
return F_157 ( V_120 ) ;
V_157 = F_170 ( V_106 , V_120 ) ;
F_88 ( V_120 ) ;
if ( V_157 < 0 )
return V_157 ;
* V_123 += V_122 ;
return V_122 ;
}
static T_1
F_171 ( struct V_61 * V_140 , char T_2 * V_121 , T_3 V_122 , T_4 * V_123 )
{
int (* F_172)( struct V_153 * V_154 ) = V_140 -> V_128 ;
struct V_153 * V_154 ;
int V_155 ;
if ( * V_123 )
return 0 ;
V_154 = F_150 ( sizeof( * V_154 ) , V_156 ) ;
if ( ! V_154 )
return - V_22 ;
F_151 ( V_154 ) ;
F_172 ( V_154 ) ;
V_155 = F_133 ( V_121 , V_122 , V_123 ,
V_154 -> V_58 , F_153 ( V_154 ) ) ;
F_88 ( V_154 ) ;
return V_155 ;
}
static void F_173 ( void * V_45 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_74 ( V_43 -> V_48 ,
F_174 ( & V_75 ) ) ;
F_67 ( V_43 -> V_49 . V_45 -> V_50 ,
F_68 ( V_47 , V_99 ) ) ;
}
static T_1
F_175 ( struct V_61 * V_140 , const char T_2 * V_121 ,
T_3 V_122 , T_4 * V_123 )
{
struct V_126 * V_127 = V_140 -> V_128 ;
struct V_42 * V_43 = V_127 -> V_129 ;
struct V_46 * V_48 = NULL ;
struct V_46 * V_47 ;
struct V_40 * V_61 ;
T_1 V_25 ;
if ( ! V_122 )
return 0 ;
V_25 = F_109 () ;
if ( V_25 < 0 )
return V_25 ;
F_40 ( & V_75 ) ;
V_48 = F_74 ( V_43 -> V_48 ,
F_75 ( & V_75 ) ) ;
V_25 = F_176 ( V_48 , & V_47 , V_121 , V_122 ) ;
if ( V_25 < 0 )
goto V_143;
F_82 ( V_43 -> V_48 , V_47 ) ;
F_6 (file, &tr->events, list) {
F_43 ( V_100 , & V_61 -> V_54 ) ;
}
if ( V_48 ) {
F_83 () ;
F_84 ( V_48 ) ;
} else if ( V_47 ) {
F_177 ( F_66 ,
V_43 , V_96 ) ;
F_177 ( F_69 ,
V_43 , 0 ) ;
F_178 ( F_70 ,
V_43 , V_96 ) ;
F_178 ( F_72 ,
V_43 , 0 ) ;
F_179 ( F_70 ,
V_43 , V_96 ) ;
F_179 ( F_72 ,
V_43 , 0 ) ;
F_180 ( F_70 ,
V_43 , V_96 ) ;
F_180 ( F_72 ,
V_43 , 0 ) ;
}
F_181 ( F_173 , V_43 , 1 ) ;
V_143:
F_47 ( & V_75 ) ;
if ( V_25 > 0 )
* V_123 += V_25 ;
return V_25 ;
}
static int
F_182 ( struct V_151 * V_151 , struct V_61 * V_61 ,
const struct V_161 * V_162 )
{
struct V_126 * V_127 ;
int V_25 ;
V_25 = F_146 ( V_61 , V_162 ) ;
if ( V_25 < 0 )
return V_25 ;
V_127 = V_61 -> V_128 ;
V_127 -> V_129 = V_151 -> V_112 ;
return V_25 ;
}
static int F_183 ( struct V_151 * V_151 , struct V_61 * V_61 )
{
struct V_42 * V_43 = V_151 -> V_112 ;
F_163 ( V_43 ) ;
return F_184 ( V_151 , V_61 ) ;
}
static int
F_185 ( struct V_151 * V_151 , struct V_61 * V_61 )
{
const struct V_161 * V_162 = & V_163 ;
return F_182 ( V_151 , V_61 , V_162 ) ;
}
static int
F_186 ( struct V_151 * V_151 , struct V_61 * V_61 )
{
const struct V_161 * V_162 = & V_164 ;
struct V_42 * V_43 = V_151 -> V_112 ;
int V_25 ;
if ( F_161 ( V_43 ) < 0 )
return - V_39 ;
if ( ( V_61 -> V_165 & V_166 ) &&
( V_61 -> V_167 & V_168 ) )
F_57 ( V_43 ) ;
V_25 = F_182 ( V_151 , V_61 , V_162 ) ;
if ( V_25 < 0 )
F_163 ( V_43 ) ;
return V_25 ;
}
static int
F_187 ( struct V_151 * V_151 , struct V_61 * V_61 )
{
const struct V_161 * V_162 = & V_169 ;
struct V_42 * V_43 = V_151 -> V_112 ;
int V_25 ;
if ( F_161 ( V_43 ) < 0 )
return - V_39 ;
if ( ( V_61 -> V_165 & V_166 ) &&
( V_61 -> V_167 & V_168 ) )
F_85 ( V_43 ) ;
V_25 = F_182 ( V_151 , V_61 , V_162 ) ;
if ( V_25 < 0 )
F_163 ( V_43 ) ;
return V_25 ;
}
static struct V_1 *
F_188 ( const char * V_11 )
{
struct V_1 * system ;
system = F_150 ( sizeof( * system ) , V_156 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
system -> V_11 = F_189 ( V_11 , V_156 ) ;
if ( ! system -> V_11 )
goto V_170;
system -> V_102 = NULL ;
system -> V_102 = F_165 ( sizeof( struct V_101 ) , V_156 ) ;
if ( ! system -> V_102 )
goto V_170;
F_11 ( & system -> V_103 , & V_171 ) ;
return system ;
V_170:
F_89 ( system -> V_11 ) ;
F_88 ( system ) ;
return NULL ;
}
static struct V_109 *
F_190 ( struct V_42 * V_43 , const char * V_11 ,
struct V_40 * V_61 , struct V_109 * V_172 )
{
struct V_105 * V_106 ;
struct V_1 * system ;
struct V_109 * V_59 ;
F_6 (dir, &tr->systems, list) {
system = V_106 -> V_107 ;
if ( strcmp ( system -> V_11 , V_11 ) == 0 ) {
V_106 -> V_108 ++ ;
V_61 -> system = V_106 ;
return V_106 -> V_59 ;
}
}
F_6 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_11 , V_11 ) == 0 )
break;
}
if ( & system -> V_103 == & V_171 )
system = NULL ;
V_106 = F_150 ( sizeof( * V_106 ) , V_156 ) ;
if ( ! V_106 )
goto V_173;
if ( ! system ) {
system = F_188 ( V_11 ) ;
if ( ! system )
goto V_170;
} else
F_90 ( system ) ;
V_106 -> V_59 = F_191 ( V_11 , V_172 ) ;
if ( ! V_106 -> V_59 ) {
F_192 ( L_17 , V_11 ) ;
F_86 ( system ) ;
goto V_170;
}
V_106 -> V_43 = V_43 ;
V_106 -> V_2 = 1 ;
V_106 -> V_108 = 1 ;
V_106 -> V_107 = system ;
V_61 -> system = V_106 ;
V_59 = F_193 ( L_18 , 0644 , V_106 -> V_59 , V_106 ,
& V_174 ) ;
if ( ! V_59 ) {
F_88 ( system -> V_102 ) ;
system -> V_102 = NULL ;
F_192 ( L_19 , V_11 ) ;
}
F_194 ( L_20 , 0644 , V_106 -> V_59 , V_106 ,
& V_175 ) ;
F_11 ( & V_106 -> V_103 , & V_43 -> V_176 ) ;
return V_106 -> V_59 ;
V_170:
F_88 ( V_106 ) ;
V_173:
if ( ! V_106 || ! system )
F_192 ( L_21 , V_11 ) ;
return NULL ;
}
static int
F_195 ( struct V_109 * V_172 , struct V_40 * V_61 )
{
struct V_4 * V_13 = V_61 -> V_5 ;
struct V_42 * V_43 = V_61 -> V_43 ;
struct V_3 * V_10 ;
struct V_109 * V_177 ;
const char * V_11 ;
int V_25 ;
if ( strcmp ( V_13 -> V_6 -> system , V_138 ) != 0 ) {
V_177 = F_190 ( V_43 , V_13 -> V_6 -> system , V_61 , V_172 ) ;
if ( ! V_177 )
return - V_22 ;
} else
V_177 = V_172 ;
V_11 = F_52 ( V_13 ) ;
V_61 -> V_106 = F_191 ( V_11 , V_177 ) ;
if ( ! V_61 -> V_106 ) {
F_192 ( L_22 , V_11 ) ;
return - 1 ;
}
if ( V_13 -> V_6 -> V_87 && ! ( V_13 -> V_54 & V_119 ) )
F_194 ( L_20 , 0644 , V_61 -> V_106 , V_61 ,
& V_178 ) ;
#ifdef F_38
if ( V_13 -> V_38 . type && V_13 -> V_6 -> V_87 )
F_194 ( L_23 , 0444 , V_61 -> V_106 ,
( void * ) ( long ) V_13 -> V_38 . type ,
& V_179 ) ;
#endif
V_10 = F_4 ( V_13 ) ;
if ( F_196 ( V_10 ) ) {
V_25 = V_13 -> V_6 -> V_180 ( V_13 ) ;
if ( V_25 < 0 ) {
F_192 ( L_24 ,
V_11 ) ;
return - 1 ;
}
}
F_194 ( L_18 , 0644 , V_61 -> V_106 , V_61 ,
& V_181 ) ;
if ( ! ( V_13 -> V_54 & V_119 ) )
F_194 ( L_25 , 0644 , V_61 -> V_106 , V_61 ,
& V_182 ) ;
#ifdef F_197
F_194 ( L_26 , 0444 , V_61 -> V_106 , V_61 ,
& V_183 ) ;
#endif
F_194 ( L_27 , 0444 , V_61 -> V_106 , V_13 ,
& V_184 ) ;
return 0 ;
}
static void F_198 ( struct V_4 * V_13 )
{
struct V_40 * V_61 ;
struct V_42 * V_43 ;
F_199 (tr, file) {
if ( V_61 -> V_5 != V_13 )
continue;
F_96 ( V_61 ) ;
break;
} F_46 () ;
}
static void F_200 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
struct V_40 * V_61 ;
F_41 (tr, file) {
if ( V_61 -> V_5 != V_13 )
continue;
F_56 ( V_61 , 0 ) ;
break;
} F_46 () ;
if ( V_13 -> V_38 . V_185 )
F_201 ( & V_13 -> V_38 ) ;
F_198 ( V_13 ) ;
F_20 ( & V_13 -> V_103 ) ;
}
static int F_202 ( struct V_4 * V_13 )
{
int V_25 = 0 ;
const char * V_11 ;
V_11 = F_52 ( V_13 ) ;
if ( F_13 ( ! V_11 ) )
return - V_117 ;
if ( V_13 -> V_6 -> V_186 ) {
V_25 = V_13 -> V_6 -> V_186 ( V_13 ) ;
if ( V_25 < 0 && V_25 != - V_187 )
F_192 ( L_28 , V_11 ) ;
}
return V_25 ;
}
static int
F_203 ( struct V_4 * V_13 , struct V_188 * V_189 )
{
int V_25 ;
V_25 = F_202 ( V_13 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_13 -> V_103 , & V_190 ) ;
V_13 -> V_189 = V_189 ;
return 0 ;
}
static char * F_204 ( char * V_191 , struct V_192 * V_193 , int V_53 )
{
int V_194 ;
int V_195 ;
V_195 = snprintf ( V_191 , 0 , L_29 , V_193 -> V_196 ) ;
if ( V_53 < V_195 )
return NULL ;
snprintf ( V_191 , V_195 + 1 , L_29 , V_193 -> V_196 ) ;
V_194 = strlen ( V_191 + V_53 ) ;
memmove ( V_191 + V_195 , V_191 + V_53 , V_194 ) ;
V_191 [ V_195 + V_194 ] = 0 ;
return V_191 + V_195 ;
}
static void F_205 ( struct V_4 * V_13 ,
struct V_192 * V_193 )
{
char * V_191 ;
int V_197 = 0 ;
int V_53 = strlen ( V_193 -> V_198 ) ;
for ( V_191 = V_13 -> V_150 ; * V_191 ; V_191 ++ ) {
if ( * V_191 == '\\' ) {
V_191 ++ ;
if ( ! * V_191 )
break;
continue;
}
if ( * V_191 == '"' ) {
V_197 ^= 1 ;
continue;
}
if ( V_197 )
continue;
if ( isdigit ( * V_191 ) ) {
do {
V_191 ++ ;
} while ( isalnum ( * V_191 ) );
if ( ! * V_191 )
break;
continue;
}
if ( isalpha ( * V_191 ) || * V_191 == '_' ) {
if ( strncmp ( V_193 -> V_198 , V_191 , V_53 ) == 0 &&
! isalnum ( V_191 [ V_53 ] ) && V_191 [ V_53 ] != '_' ) {
V_191 = F_204 ( V_191 , V_193 , V_53 ) ;
if ( F_87 ( ! V_191 ) )
return;
continue;
}
V_199:
do {
V_191 ++ ;
} while ( isalnum ( * V_191 ) || * V_191 == '_' );
if ( ! * V_191 )
break;
if ( * V_191 == '.' || ( V_191 [ 0 ] == '-' && V_191 [ 1 ] == '>' ) ) {
V_191 += * V_191 == '.' ? 1 : 2 ;
if ( ! * V_191 )
break;
goto V_199;
}
continue;
}
}
}
void F_206 ( struct V_192 * * V_193 , int V_53 )
{
struct V_4 * V_13 , * V_139 ;
const char * V_200 = NULL ;
int V_201 ;
int V_202 ;
F_207 ( & V_203 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( ! V_200 || V_13 -> V_6 -> system != V_200 ) {
V_201 = 0 ;
V_200 = V_13 -> V_6 -> system ;
}
for ( V_202 = V_201 ; V_202 < V_53 ; V_202 ++ ) {
if ( V_13 -> V_6 -> system == V_193 [ V_202 ] -> system ) {
if ( ! V_201 )
V_201 = V_202 ;
F_205 ( V_13 , V_193 [ V_202 ] ) ;
}
}
}
F_208 ( & V_203 ) ;
}
static struct V_40 *
F_209 ( struct V_4 * V_13 ,
struct V_42 * V_43 )
{
struct V_40 * V_61 ;
V_61 = F_9 ( V_113 , V_21 ) ;
if ( ! V_61 )
return NULL ;
V_61 -> V_5 = V_13 ;
V_61 -> V_43 = V_43 ;
F_210 ( & V_61 -> V_81 , 0 ) ;
F_210 ( & V_61 -> V_204 , 0 ) ;
F_211 ( & V_61 -> V_205 ) ;
F_11 ( & V_61 -> V_103 , & V_43 -> V_137 ) ;
return V_61 ;
}
static int
F_212 ( struct V_4 * V_13 , struct V_42 * V_43 )
{
struct V_40 * V_61 ;
V_61 = F_209 ( V_13 , V_43 ) ;
if ( ! V_61 )
return - V_22 ;
return F_195 ( V_43 -> V_206 , V_61 ) ;
}
static T_6 int
F_213 ( struct V_4 * V_13 ,
struct V_42 * V_43 )
{
struct V_40 * V_61 ;
V_61 = F_209 ( V_13 , V_43 ) ;
if ( ! V_61 )
return - V_22 ;
return 0 ;
}
int F_214 ( struct V_4 * V_13 )
{
int V_25 ;
F_40 ( & V_159 ) ;
F_40 ( & V_75 ) ;
V_25 = F_203 ( V_13 , NULL ) ;
if ( V_25 >= 0 )
F_215 ( V_13 ) ;
F_47 ( & V_75 ) ;
F_47 ( & V_159 ) ;
return V_25 ;
}
static void F_216 ( struct V_4 * V_13 )
{
F_200 ( V_13 ) ;
F_18 ( V_13 ) ;
F_101 ( V_13 -> V_102 ) ;
V_13 -> V_102 = NULL ;
}
static int F_217 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
struct V_40 * V_61 ;
#ifdef F_38
if ( V_13 -> V_207 )
return - V_208 ;
#endif
F_41 (tr, file) {
if ( V_61 -> V_5 != V_13 )
continue;
if ( V_61 -> V_54 & V_76 )
return - V_208 ;
break;
} F_46 () ;
F_216 ( V_13 ) ;
return 0 ;
}
int F_218 ( struct V_4 * V_13 )
{
int V_25 ;
F_40 ( & V_159 ) ;
F_40 ( & V_75 ) ;
F_207 ( & V_203 ) ;
V_25 = F_217 ( V_13 ) ;
F_208 ( & V_203 ) ;
F_47 ( & V_75 ) ;
F_47 ( & V_159 ) ;
return V_25 ;
}
static void F_219 ( struct V_188 * V_189 )
{
struct V_4 * * V_13 , * * V_209 , * * V_210 ;
if ( ! V_189 -> V_211 )
return;
if ( F_220 ( V_189 ) ) {
F_221 ( L_30 ,
V_189 -> V_11 ) ;
return;
}
V_209 = V_189 -> V_212 ;
V_210 = V_189 -> V_212 + V_189 -> V_211 ;
F_222 (call, start, end) {
F_203 ( * V_13 , V_189 ) ;
F_215 ( * V_13 ) ;
}
}
static void F_223 ( struct V_188 * V_189 )
{
struct V_4 * V_13 , * V_139 ;
bool V_213 = false ;
F_207 ( & V_203 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( V_13 -> V_189 == V_189 ) {
if ( V_13 -> V_54 & V_91 )
V_213 = true ;
F_216 ( V_13 ) ;
}
}
F_208 ( & V_203 ) ;
if ( V_213 )
F_224 () ;
}
static int F_225 ( struct V_214 * V_94 ,
unsigned long V_141 , void * V_45 )
{
struct V_188 * V_189 = V_45 ;
F_40 ( & V_159 ) ;
F_40 ( & V_75 ) ;
switch ( V_141 ) {
case V_215 :
F_219 ( V_189 ) ;
break;
case V_216 :
F_223 ( V_189 ) ;
break;
}
F_47 ( & V_75 ) ;
F_47 ( & V_159 ) ;
return 0 ;
}
static void
F_226 ( struct V_42 * V_43 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
V_25 = F_212 ( V_13 , V_43 ) ;
if ( V_25 < 0 )
F_192 ( L_31 ,
F_52 ( V_13 ) ) ;
}
}
struct V_40 *
F_227 ( struct V_42 * V_43 , const char * system , const char * V_38 )
{
struct V_40 * V_61 ;
struct V_4 * V_13 ;
const char * V_11 ;
F_6 (file, &tr->events, list) {
V_13 = V_61 -> V_5 ;
V_11 = F_52 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_87 )
continue;
if ( V_13 -> V_54 & V_119 )
continue;
if ( strcmp ( V_38 , V_11 ) == 0 &&
strcmp ( system , V_13 -> V_6 -> system ) == 0 )
return V_61 ;
}
return NULL ;
}
static void F_228 ( struct V_217 * V_45 )
{
if ( V_45 -> V_74 )
F_45 ( V_88 , & V_45 -> V_61 -> V_54 ) ;
else
F_43 ( V_88 , & V_45 -> V_61 -> V_54 ) ;
}
static void
F_229 ( unsigned long V_218 , unsigned long V_219 ,
struct V_42 * V_43 , struct V_220 * V_221 ,
void * V_45 )
{
struct V_222 * V_223 = V_45 ;
struct V_217 * V_224 ;
void * * V_225 ;
V_225 = F_230 ( V_223 , V_218 ) ;
if ( ! V_225 || ! * V_225 )
return;
V_224 = * V_225 ;
F_228 ( V_224 ) ;
}
static void
F_231 ( unsigned long V_218 , unsigned long V_219 ,
struct V_42 * V_43 , struct V_220 * V_221 ,
void * V_45 )
{
struct V_222 * V_223 = V_45 ;
struct V_217 * V_224 ;
void * * V_225 ;
V_225 = F_230 ( V_223 , V_218 ) ;
if ( ! V_225 || ! * V_225 )
return;
V_224 = * V_225 ;
if ( ! V_224 -> V_226 )
return;
if ( V_224 -> V_74 == ! ( V_224 -> V_61 -> V_54 & V_82 ) )
return;
if ( V_224 -> V_226 != - 1 )
( V_224 -> V_226 ) -- ;
F_228 ( V_224 ) ;
}
static int
F_232 ( struct V_126 * V_127 , unsigned long V_218 ,
struct V_220 * V_221 , void * V_45 )
{
struct V_222 * V_223 = V_45 ;
struct V_217 * V_224 ;
void * * V_225 ;
V_225 = F_230 ( V_223 , V_218 ) ;
if ( F_87 ( ! V_225 || ! * V_225 ) )
return 0 ;
V_224 = * V_225 ;
F_121 ( V_127 , L_32 , ( void * ) V_218 ) ;
F_121 ( V_127 , L_33 ,
V_224 -> V_74 ? V_227 : V_228 ,
V_224 -> V_61 -> V_5 -> V_6 -> system ,
F_52 ( V_224 -> V_61 -> V_5 ) ) ;
if ( V_224 -> V_226 == - 1 )
F_140 ( V_127 , L_34 ) ;
else
F_121 ( V_127 , L_35 , V_224 -> V_226 ) ;
return 0 ;
}
static int
F_233 ( struct V_220 * V_221 , struct V_42 * V_43 ,
unsigned long V_218 , void * V_229 , void * * V_45 )
{
struct V_222 * V_223 = * V_45 ;
struct V_217 * V_224 = V_229 ;
int V_25 ;
if ( ! V_223 ) {
V_223 = F_234 () ;
if ( ! V_223 )
return - V_39 ;
* V_45 = V_223 ;
}
V_25 = F_235 ( V_223 , V_218 , V_224 ) ;
if ( V_25 < 0 )
return V_25 ;
V_224 -> V_230 ++ ;
return 0 ;
}
static int F_236 ( void * V_45 )
{
struct V_217 * V_224 = V_45 ;
V_224 -> V_230 -- ;
if ( ! V_224 -> V_230 ) {
F_48 ( V_224 -> V_61 , 0 , 1 ) ;
F_237 ( V_224 -> V_61 -> V_5 -> V_189 ) ;
F_88 ( V_224 ) ;
}
return 0 ;
}
static void
F_238 ( struct V_220 * V_221 , struct V_42 * V_43 ,
unsigned long V_218 , void * V_45 )
{
struct V_222 * V_223 = V_45 ;
struct V_217 * V_224 ;
if ( ! V_218 ) {
if ( ! V_223 )
return;
F_239 ( V_223 , F_236 ) ;
return;
}
V_224 = F_240 ( V_223 , V_218 ) ;
if ( F_87 ( ! V_224 ) )
return;
if ( F_87 ( V_224 -> V_230 <= 0 ) )
return;
F_236 ( V_224 ) ;
}
static int
F_241 ( struct V_42 * V_43 , struct V_231 * V_232 ,
char * V_233 , char * V_234 , char * V_235 , int V_236 )
{
struct V_40 * V_61 ;
struct V_220 * V_221 ;
struct V_217 * V_45 ;
const char * system ;
const char * V_38 ;
char * V_237 ;
bool V_74 ;
int V_25 ;
if ( ! V_43 )
return - V_39 ;
if ( ! V_236 || ! V_235 )
return - V_117 ;
system = F_105 ( & V_235 , L_3 ) ;
if ( ! V_235 )
return - V_117 ;
V_38 = F_105 ( & V_235 , L_3 ) ;
F_40 ( & V_75 ) ;
V_25 = - V_117 ;
V_61 = F_227 ( V_43 , system , V_38 ) ;
if ( ! V_61 )
goto V_143;
V_74 = strcmp ( V_234 , V_227 ) == 0 ;
if ( V_74 )
V_221 = V_235 ? & V_238 : & V_239 ;
else
V_221 = V_235 ? & V_240 : & V_241 ;
if ( V_233 [ 0 ] == '!' ) {
V_25 = F_242 ( V_233 + 1 , V_43 , V_221 ) ;
goto V_143;
}
V_25 = - V_22 ;
V_45 = F_165 ( sizeof( * V_45 ) , V_156 ) ;
if ( ! V_45 )
goto V_143;
V_45 -> V_74 = V_74 ;
V_45 -> V_226 = - 1 ;
V_45 -> V_61 = V_61 ;
if ( ! V_235 )
goto V_242;
V_237 = F_105 ( & V_235 , L_3 ) ;
V_25 = - V_117 ;
if ( ! strlen ( V_237 ) )
goto V_170;
V_25 = F_243 ( V_237 , 0 , & V_45 -> V_226 ) ;
if ( V_25 )
goto V_170;
V_242:
V_25 = F_244 ( V_61 -> V_5 -> V_189 ) ;
if ( ! V_25 ) {
V_25 = - V_208 ;
goto V_170;
}
V_25 = F_48 ( V_61 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_133;
V_25 = F_245 ( V_233 , V_43 , V_221 , V_45 ) ;
if ( ! V_25 ) {
V_25 = - V_243 ;
goto V_244;
} else if ( V_25 < 0 )
goto V_244;
V_25 = 0 ;
V_143:
F_47 ( & V_75 ) ;
return V_25 ;
V_244:
F_48 ( V_61 , 0 , 1 ) ;
V_133:
F_237 ( V_61 -> V_5 -> V_189 ) ;
V_170:
F_88 ( V_45 ) ;
goto V_143;
}
static T_6 int F_246 ( void )
{
int V_25 ;
V_25 = F_247 ( & V_245 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_247 ( & V_246 ) ;
if ( F_13 ( V_25 < 0 ) )
F_248 ( & V_245 ) ;
return V_25 ;
}
static inline int F_246 ( void ) { return 0 ; }
static T_6 void
F_249 ( struct V_42 * V_43 )
{
struct V_40 * V_61 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_195 ( V_43 -> V_206 , V_61 ) ;
if ( V_25 < 0 )
F_192 ( L_31 ,
F_52 ( V_61 -> V_5 ) ) ;
}
}
static T_6 void
F_250 ( struct V_42 * V_43 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_87 ( V_13 -> V_189 ) )
continue;
V_25 = F_213 ( V_13 , V_43 ) ;
if ( V_25 < 0 )
F_192 ( L_36 ,
F_52 ( V_13 ) ) ;
}
}
static void
F_251 ( struct V_42 * V_43 )
{
struct V_40 * V_61 , * V_35 ;
F_19 (file, next, &tr->events, list)
F_96 ( V_61 ) ;
}
static void F_215 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_212 ( V_13 , V_43 ) ;
}
static T_6 int F_252 ( char * V_247 )
{
F_253 ( V_248 , V_247 , V_249 ) ;
V_250 = true ;
V_251 = true ;
return 1 ;
}
static int
F_254 ( struct V_109 * V_172 , struct V_42 * V_43 )
{
struct V_109 * V_177 ;
struct V_109 * V_59 ;
V_59 = F_193 ( L_37 , 0644 , V_172 ,
V_43 , & V_252 ) ;
if ( ! V_59 ) {
F_192 ( L_38 ) ;
return - V_22 ;
}
V_177 = F_191 ( L_39 , V_172 ) ;
if ( ! V_177 ) {
F_192 ( L_40 ) ;
return - V_22 ;
}
V_59 = F_194 ( L_20 , 0644 , V_177 ,
V_43 , & V_253 ) ;
if ( ! V_59 ) {
F_192 ( L_41 ) ;
return - V_22 ;
}
V_59 = F_193 ( L_42 , 0644 , V_172 ,
V_43 , & V_254 ) ;
if ( ! V_59 )
F_192 ( L_43 ) ;
V_59 = F_194 ( L_44 , 0444 , V_177 ,
V_255 ,
& V_256 ) ;
if ( ! V_59 )
F_192 ( L_45 ) ;
V_59 = F_194 ( L_46 , 0444 , V_177 ,
V_257 ,
& V_256 ) ;
if ( ! V_59 )
F_192 ( L_47 ) ;
V_43 -> V_206 = V_177 ;
return 0 ;
}
int F_255 ( struct V_109 * V_172 , struct V_42 * V_43 )
{
int V_25 ;
F_40 ( & V_75 ) ;
V_25 = F_254 ( V_172 , V_43 ) ;
if ( V_25 )
goto V_258;
F_207 ( & V_203 ) ;
F_226 ( V_43 ) ;
F_208 ( & V_203 ) ;
V_258:
F_47 ( & V_75 ) ;
return V_25 ;
}
static T_6 int
F_256 ( struct V_109 * V_172 , struct V_42 * V_43 )
{
int V_25 ;
F_40 ( & V_75 ) ;
V_25 = F_254 ( V_172 , V_43 ) ;
if ( V_25 )
goto V_258;
F_207 ( & V_203 ) ;
F_249 ( V_43 ) ;
F_208 ( & V_203 ) ;
V_258:
F_47 ( & V_75 ) ;
return V_25 ;
}
int F_257 ( struct V_42 * V_43 )
{
F_40 ( & V_75 ) ;
F_258 ( V_43 ) ;
F_73 ( V_43 ) ;
F_102 ( V_43 , NULL , NULL , NULL , 0 ) ;
F_83 () ;
F_207 ( & V_203 ) ;
F_251 ( V_43 ) ;
F_95 ( V_43 -> V_206 ) ;
F_208 ( & V_203 ) ;
V_43 -> V_206 = NULL ;
F_47 ( & V_75 ) ;
return 0 ;
}
static T_6 int F_259 ( void )
{
V_20 = F_260 ( V_9 , V_259 ) ;
V_113 = F_260 ( V_40 , V_259 ) ;
return 0 ;
}
static T_6 void
F_261 ( struct V_42 * V_43 , bool V_260 )
{
char * V_120 = V_248 ;
char * V_261 ;
int V_25 ;
while ( true ) {
V_261 = F_105 ( & V_120 , L_48 ) ;
if ( ! V_261 )
break;
if ( * V_261 ) {
if ( V_260 )
F_104 ( V_43 , V_261 , 0 ) ;
V_25 = F_104 ( V_43 , V_261 , 1 ) ;
if ( V_25 )
F_192 ( L_49 , V_261 ) ;
}
if ( V_120 )
* ( V_120 - 1 ) = ',' ;
}
}
static T_6 int F_262 ( void )
{
struct V_42 * V_43 = F_107 () ;
struct V_4 * * V_262 , * V_13 ;
int V_25 ;
if ( ! V_43 )
return - V_39 ;
F_222 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_13 = * V_262 ;
V_25 = F_202 ( V_13 ) ;
if ( ! V_25 )
F_11 ( & V_13 -> V_103 , & V_190 ) ;
}
F_250 ( V_43 ) ;
F_261 ( V_43 , false ) ;
F_263 () ;
F_246 () ;
F_264 () ;
return 0 ;
}
static T_6 int F_265 ( void )
{
struct V_42 * V_43 ;
V_43 = F_107 () ;
if ( ! V_43 )
return - V_39 ;
F_261 ( V_43 , true ) ;
return 0 ;
}
static T_6 int F_266 ( void )
{
struct V_42 * V_43 ;
struct V_109 * V_263 ;
struct V_109 * V_59 ;
int V_25 ;
V_43 = F_107 () ;
if ( ! V_43 )
return - V_39 ;
V_263 = F_267 () ;
if ( F_156 ( V_263 ) )
return 0 ;
V_59 = F_193 ( L_50 , 0444 , V_263 ,
V_43 , & V_264 ) ;
if ( ! V_59 )
F_192 ( L_51 ) ;
if ( F_14 () )
F_192 ( L_52 ) ;
if ( F_16 () )
F_192 ( L_53 ) ;
V_25 = F_256 ( V_263 , V_43 ) ;
if ( V_25 )
return V_25 ;
#ifdef F_268
V_25 = F_269 ( & V_265 ) ;
if ( V_25 )
F_192 ( L_54 ) ;
#endif
return 0 ;
}
void T_6 F_270 ( void )
{
F_259 () ;
F_271 () ;
F_262 () ;
}
static T_6 void F_272 ( struct V_266 * V_267 )
{
F_97 ( & V_268 ) ;
F_273 ( & V_269 ) ;
F_274 ( 1 ) ;
F_275 ( & V_269 ) ;
F_100 ( & V_268 ) ;
F_40 ( & V_270 ) ;
F_276 ( 1 ) ;
F_47 ( & V_270 ) ;
}
static T_6 int F_277 ( void * V_271 )
{
void * V_272 ;
V_272 = F_150 ( 1234 , V_156 ) ;
if ( ! V_272 )
F_51 ( L_55 ) ;
F_278 ( F_272 ) ;
F_88 ( V_272 ) ;
F_279 ( V_273 ) ;
while ( ! F_280 () ) {
F_281 () ;
F_279 ( V_273 ) ;
}
F_282 ( V_274 ) ;
return 0 ;
}
static T_6 void F_283 ( void )
{
struct V_92 * V_275 ;
V_275 = F_284 ( F_277 , NULL , L_56 ) ;
F_276 ( 1 ) ;
F_285 ( V_275 ) ;
}
static T_6 void F_286 ( void )
{
struct V_105 * V_106 ;
struct V_40 * V_61 ;
struct V_4 * V_13 ;
struct V_1 * system ;
struct V_42 * V_43 ;
int V_25 ;
V_43 = F_107 () ;
if ( ! V_43 )
return;
F_51 ( L_57 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_61 -> V_5 ;
if ( ! V_13 -> V_6 || ! V_13 -> V_6 -> V_65 )
continue;
#ifndef F_287
if ( V_13 -> V_6 -> system &&
strcmp ( V_13 -> V_6 -> system , L_58 ) == 0 )
continue;
#endif
F_51 ( L_59 , F_52 ( V_13 ) ) ;
if ( V_61 -> V_54 & V_76 ) {
F_192 ( L_60 ) ;
F_87 ( 1 ) ;
continue;
}
F_56 ( V_61 , 1 ) ;
F_283 () ;
F_56 ( V_61 , 0 ) ;
F_288 ( L_61 ) ;
}
F_51 ( L_62 ) ;
F_6 (dir, &tr->systems, list) {
system = V_106 -> V_107 ;
if ( strcmp ( system -> V_11 , L_63 ) == 0 )
continue;
F_51 ( L_64 , system -> V_11 ) ;
V_25 = F_103 ( V_43 , NULL , system -> V_11 , NULL , 1 ) ;
if ( F_87 ( V_25 ) ) {
F_192 ( L_65 ,
system -> V_11 ) ;
continue;
}
F_283 () ;
V_25 = F_103 ( V_43 , NULL , system -> V_11 , NULL , 0 ) ;
if ( F_87 ( V_25 ) ) {
F_192 ( L_66 ,
system -> V_11 ) ;
continue;
}
F_288 ( L_61 ) ;
}
F_51 ( L_67 ) ;
F_51 ( L_68 ) ;
V_25 = F_103 ( V_43 , NULL , NULL , NULL , 1 ) ;
if ( F_87 ( V_25 ) ) {
F_192 ( L_69 ) ;
return;
}
F_283 () ;
V_25 = F_103 ( V_43 , NULL , NULL , NULL , 0 ) ;
if ( F_87 ( V_25 ) ) {
F_192 ( L_70 ) ;
return;
}
F_288 ( L_61 ) ;
}
static void T_6
F_289 ( unsigned long V_218 , unsigned long V_219 ,
struct V_276 * V_277 , struct V_278 * V_278 )
{
struct V_279 * V_38 ;
struct V_280 * V_58 ;
struct V_281 * V_59 ;
unsigned long V_54 ;
long V_282 ;
int V_28 ;
int V_56 ;
V_56 = F_31 () ;
F_290 () ;
V_28 = F_291 () ;
V_282 = F_50 ( & F_292 ( V_283 , V_28 ) ) ;
if ( V_282 != 1 )
goto V_143;
F_30 ( V_54 ) ;
V_38 = F_33 ( & V_58 , & V_284 ,
V_285 , sizeof( * V_59 ) ,
V_54 , V_56 ) ;
if ( ! V_38 )
goto V_143;
V_59 = F_34 ( V_38 ) ;
V_59 -> V_218 = V_218 ;
V_59 -> V_219 = V_219 ;
F_293 ( & V_284 , V_58 , V_38 ,
V_59 , V_54 , V_56 ) ;
V_143:
F_294 ( & F_292 ( V_283 , V_28 ) ) ;
F_295 () ;
}
static T_6 void F_296 ( void )
{
int V_25 ;
V_284 . V_43 = F_107 () ;
if ( F_13 ( ! V_284 . V_43 ) )
return;
V_25 = F_297 ( & V_286 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_51 ( L_71 ) ;
return;
}
F_51 ( L_72 ) ;
F_286 () ;
F_298 ( & V_286 ) ;
}
static T_6 void F_296 ( void )
{
}
static T_6 int F_299 ( void )
{
if ( ! V_251 ) {
F_286 () ;
F_296 () ;
}
return 0 ;
}
