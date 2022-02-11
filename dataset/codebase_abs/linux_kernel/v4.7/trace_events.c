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
V_52 -> V_41 = V_41 ;
V_52 -> V_38 =
F_32 ( & V_52 -> V_57 , V_41 ,
V_5 -> V_38 . type , V_53 ,
V_52 -> V_54 , V_52 -> V_56 ) ;
if ( ! V_52 -> V_38 )
return NULL ;
V_52 -> V_58 = F_33 ( V_52 -> V_38 ) ;
return V_52 -> V_58 ;
}
static void F_34 ( struct V_51 * V_52 )
{
struct V_4 * V_5 ;
struct V_59 * V_38 ;
unsigned long V_54 ;
struct V_60 * V_61 = V_62 ;
if ( ! V_61 )
return;
V_5 = V_52 -> V_41 -> V_5 ;
if ( ! V_5 || ! V_5 -> V_38 . V_63 ||
! V_5 -> V_38 . V_63 -> V_64 )
return;
V_38 = & V_52 -> V_41 -> V_5 -> V_38 ;
F_35 ( & V_65 , V_54 ) ;
F_36 ( & V_61 -> V_66 ) ;
V_61 -> V_33 = V_52 -> V_58 ;
V_5 -> V_38 . V_63 -> V_64 ( V_61 , 0 , V_38 ) ;
F_37 ( & V_61 -> V_66 , 0 ) ;
F_38 ( L_1 , V_61 -> V_66 . V_57 ) ;
F_39 ( & V_65 , V_54 ) ;
}
void F_40 ( struct V_51 * V_52 )
{
if ( V_67 )
F_34 ( V_52 ) ;
F_41 ( V_52 -> V_41 , V_52 -> V_57 ,
V_52 -> V_38 , V_52 -> V_58 ,
V_52 -> V_54 , V_52 -> V_56 ) ;
}
int F_42 ( struct V_4 * V_13 ,
enum V_68 type , void * V_45 )
{
struct V_40 * V_69 = V_45 ;
F_13 ( ! ( V_13 -> V_54 & V_70 ) ) ;
switch ( type ) {
case V_71 :
return F_43 ( V_13 -> V_72 ,
V_13 -> V_6 -> V_73 ,
V_69 ) ;
case V_74 :
F_44 ( V_13 -> V_72 ,
V_13 -> V_6 -> V_73 ,
V_69 ) ;
return 0 ;
#ifdef F_45
case V_75 :
return F_43 ( V_13 -> V_72 ,
V_13 -> V_6 -> V_76 ,
V_13 ) ;
case V_77 :
F_44 ( V_13 -> V_72 ,
V_13 -> V_6 -> V_76 ,
V_13 ) ;
return 0 ;
case V_78 :
case V_79 :
case V_80 :
case V_81 :
return 0 ;
#endif
}
return 0 ;
}
void F_46 ( bool V_82 )
{
struct V_40 * V_69 ;
struct V_42 * V_43 ;
F_47 ( & V_83 ) ;
F_48 (tr, file) {
if ( ! ( V_69 -> V_54 & V_84 ) )
continue;
if ( V_82 ) {
F_49 () ;
F_50 ( V_85 , & V_69 -> V_54 ) ;
} else {
F_51 () ;
F_52 ( V_85 , & V_69 -> V_54 ) ;
}
} F_53 () ;
F_54 ( & V_83 ) ;
}
static int F_55 ( struct V_40 * V_69 ,
int V_82 , int V_86 )
{
struct V_4 * V_13 = V_69 -> V_5 ;
struct V_42 * V_43 = V_69 -> V_43 ;
unsigned long V_87 = V_69 -> V_54 ;
int V_25 = 0 ;
int V_88 ;
switch ( V_82 ) {
case 0 :
if ( V_86 ) {
if ( F_56 ( & V_69 -> V_89 ) > 0 )
break;
V_88 = V_69 -> V_54 & V_90 ;
F_52 ( V_91 , & V_69 -> V_54 ) ;
} else
V_88 = ! ( V_69 -> V_54 & V_92 ) ;
if ( V_88 && ( V_69 -> V_54 & V_84 ) ) {
F_52 ( V_93 , & V_69 -> V_54 ) ;
if ( V_69 -> V_54 & V_94 ) {
F_51 () ;
F_52 ( V_85 , & V_69 -> V_54 ) ;
}
V_13 -> V_6 -> V_95 ( V_13 , V_74 , V_69 ) ;
}
if ( V_69 -> V_54 & V_92 )
F_50 ( V_96 , & V_69 -> V_54 ) ;
else
F_52 ( V_96 , & V_69 -> V_54 ) ;
break;
case 1 :
if ( ! V_86 )
F_52 ( V_96 , & V_69 -> V_54 ) ;
else {
if ( F_57 ( & V_69 -> V_89 ) > 1 )
break;
F_50 ( V_91 , & V_69 -> V_54 ) ;
}
if ( ! ( V_69 -> V_54 & V_84 ) ) {
if ( V_86 )
F_50 ( V_96 , & V_69 -> V_54 ) ;
if ( V_43 -> V_97 & V_98 ) {
F_49 () ;
F_50 ( V_85 , & V_69 -> V_54 ) ;
}
V_25 = V_13 -> V_6 -> V_95 ( V_13 , V_71 , V_69 ) ;
if ( V_25 ) {
F_51 () ;
F_58 ( L_2
L_3 , F_59 ( V_13 ) ) ;
break;
}
F_50 ( V_93 , & V_69 -> V_54 ) ;
V_13 -> V_54 |= V_99 ;
}
break;
}
if ( ( V_87 & V_90 ) !=
( V_69 -> V_54 & V_90 ) ) {
if ( V_69 -> V_54 & V_90 )
F_60 () ;
else
F_61 () ;
}
return V_25 ;
}
int F_62 ( struct V_40 * V_69 ,
int V_82 , int V_86 )
{
return F_55 ( V_69 , V_82 , V_86 ) ;
}
static int F_63 ( struct V_40 * V_69 ,
int V_82 )
{
return F_55 ( V_69 , V_82 , 0 ) ;
}
static void F_64 ( struct V_42 * V_43 )
{
struct V_40 * V_69 ;
F_47 ( & V_83 ) ;
F_6 (file, &tr->events, list) {
F_63 ( V_69 , 0 ) ;
}
F_54 ( & V_83 ) ;
}
static bool
F_65 ( struct V_46 * V_48 , T_1 V_100 )
{
if ( V_100 >= V_48 -> V_101 )
return false ;
return F_66 ( V_100 , V_48 -> V_102 ) ;
}
static bool
F_67 ( struct V_46 * V_48 , struct V_103 * V_104 )
{
if ( ! V_48 )
return false ;
return ! F_65 ( V_48 , V_104 -> V_34 ) ;
}
static void F_68 ( struct V_46 * V_47 ,
struct V_103 * V_105 ,
struct V_103 * V_104 )
{
if ( ! V_47 )
return;
if ( V_105 ) {
if ( ! F_65 ( V_47 , V_105 -> V_34 ) )
return;
}
if ( V_104 -> V_34 >= V_47 -> V_101 )
return;
if ( V_105 )
F_50 ( V_104 -> V_34 , V_47 -> V_102 ) ;
else
F_52 ( V_104 -> V_34 , V_47 -> V_102 ) ;
}
static void
F_69 ( void * V_45 , struct V_103 * V_104 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_45 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_68 ( V_47 , NULL , V_104 ) ;
}
static void
F_70 ( void * V_45 ,
struct V_103 * V_105 ,
struct V_103 * V_104 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_45 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_68 ( V_47 , V_105 , V_104 ) ;
}
void F_71 ( struct V_42 * V_43 , bool V_82 )
{
if ( V_82 ) {
F_72 ( F_70 ,
V_43 , V_106 ) ;
F_73 ( F_69 ,
V_43 , V_107 ) ;
} else {
F_74 ( F_70 ,
V_43 ) ;
F_75 ( F_69 ,
V_43 ) ;
}
}
static void
F_76 ( void * V_45 , bool V_108 ,
struct V_103 * V_109 , struct V_103 * V_35 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_77 ( V_43 -> V_49 . V_45 -> V_50 ,
F_67 ( V_47 , V_109 ) &&
F_67 ( V_47 , V_35 ) ) ;
}
static void
F_78 ( void * V_45 , bool V_108 ,
struct V_103 * V_109 , struct V_103 * V_35 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_77 ( V_43 -> V_49 . V_45 -> V_50 ,
F_67 ( V_47 , V_35 ) ) ;
}
static void
F_79 ( void * V_45 , struct V_103 * V_104 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
if ( ! F_80 ( V_43 -> V_49 . V_45 -> V_50 ) )
return;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_77 ( V_43 -> V_49 . V_45 -> V_50 ,
F_67 ( V_47 , V_104 ) ) ;
}
static void
F_81 ( void * V_45 , struct V_103 * V_104 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
if ( F_80 ( V_43 -> V_49 . V_45 -> V_50 ) )
return;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_77 ( V_43 -> V_49 . V_45 -> V_50 ,
F_67 ( V_47 , V_110 ) ) ;
}
static void F_82 ( struct V_42 * V_43 )
{
struct V_46 * V_47 ;
struct V_40 * V_69 ;
int V_28 ;
V_47 = F_83 ( V_43 -> V_48 ,
F_84 ( & V_83 ) ) ;
if ( ! V_47 )
return;
F_85 ( F_76 , V_43 ) ;
F_85 ( F_78 , V_43 ) ;
F_86 ( F_79 , V_43 ) ;
F_86 ( F_81 , V_43 ) ;
F_87 ( F_79 , V_43 ) ;
F_87 ( F_81 , V_43 ) ;
F_88 ( F_79 , V_43 ) ;
F_88 ( F_81 , V_43 ) ;
F_6 (file, &tr->events, list) {
F_52 ( V_111 , & V_69 -> V_54 ) ;
}
F_89 (cpu)
F_90 ( V_43 -> V_49 . V_45 , V_28 ) -> V_50 = false ;
F_91 ( V_43 -> V_48 , NULL ) ;
F_92 () ;
F_93 ( V_47 -> V_102 ) ;
F_94 ( V_47 ) ;
}
static void F_95 ( struct V_42 * V_43 )
{
F_47 ( & V_83 ) ;
F_82 ( V_43 ) ;
F_54 ( & V_83 ) ;
}
static void F_96 ( struct V_1 * system )
{
struct V_112 * V_113 = system -> V_113 ;
F_97 ( F_1 ( system ) == 0 ) ;
if ( F_3 ( system ) )
return;
F_20 ( & system -> V_114 ) ;
if ( V_113 ) {
F_94 ( V_113 -> V_115 ) ;
F_94 ( V_113 ) ;
}
F_98 ( system -> V_11 ) ;
F_94 ( system ) ;
}
static void F_99 ( struct V_1 * system )
{
F_97 ( F_1 ( system ) == 0 ) ;
F_2 ( system ) ;
}
static void F_100 ( struct V_116 * V_117 )
{
F_97 ( V_117 -> V_2 == 0 ) ;
V_117 -> V_2 ++ ;
F_99 ( V_117 -> V_118 ) ;
}
static void F_101 ( struct V_116 * V_117 )
{
F_97 ( V_117 -> V_2 == 0 ) ;
F_97 ( F_1 ( V_117 -> V_118 ) == 1 && V_117 -> V_2 != 1 ) ;
F_96 ( V_117 -> V_118 ) ;
if ( ! -- V_117 -> V_2 )
F_94 ( V_117 ) ;
}
static void F_102 ( struct V_116 * V_117 )
{
F_47 ( & V_83 ) ;
F_101 ( V_117 ) ;
F_54 ( & V_83 ) ;
}
static void F_103 ( struct V_116 * V_117 )
{
if ( ! V_117 )
return;
if ( ! -- V_117 -> V_119 ) {
F_104 ( V_117 -> V_58 ) ;
F_20 ( & V_117 -> V_114 ) ;
F_101 ( V_117 ) ;
}
}
static void F_105 ( struct V_40 * V_69 )
{
struct V_120 * V_117 = V_69 -> V_117 ;
struct V_120 * V_121 ;
if ( V_117 ) {
F_106 ( & V_117 -> V_122 ) ;
F_6 (child, &dir->d_subdirs, d_child) {
if ( F_107 ( V_121 ) )
F_108 ( V_121 ) -> V_123 = NULL ;
}
F_109 ( & V_117 -> V_122 ) ;
F_104 ( V_117 ) ;
}
F_20 ( & V_69 -> V_114 ) ;
F_103 ( V_69 -> system ) ;
F_110 ( V_69 -> V_113 ) ;
F_21 ( V_124 , V_69 ) ;
}
static int
F_111 ( struct V_42 * V_43 , const char * V_125 ,
const char * V_126 , const char * V_38 , int V_127 )
{
struct V_40 * V_69 ;
struct V_4 * V_13 ;
const char * V_11 ;
int V_25 = - V_128 ;
F_6 (file, &tr->events, list) {
V_13 = V_69 -> V_5 ;
V_11 = F_59 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_95 )
continue;
if ( V_13 -> V_54 & V_129 )
continue;
if ( V_125 &&
strcmp ( V_125 , V_11 ) != 0 &&
strcmp ( V_125 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_126 && strcmp ( V_126 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_38 && strcmp ( V_38 , V_11 ) != 0 )
continue;
F_63 ( V_69 , V_127 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static int F_112 ( struct V_42 * V_43 , const char * V_125 ,
const char * V_126 , const char * V_38 , int V_127 )
{
int V_25 ;
F_47 ( & V_83 ) ;
V_25 = F_111 ( V_43 , V_125 , V_126 , V_38 , V_127 ) ;
F_54 ( & V_83 ) ;
return V_25 ;
}
static int F_113 ( struct V_42 * V_43 , char * V_130 , int V_127 )
{
char * V_38 = NULL , * V_126 = NULL , * V_125 ;
int V_25 ;
V_125 = F_114 ( & V_130 , L_4 ) ;
if ( V_130 ) {
V_126 = V_125 ;
V_38 = V_130 ;
V_125 = NULL ;
if ( ! strlen ( V_126 ) || strcmp ( V_126 , L_5 ) == 0 )
V_126 = NULL ;
if ( ! strlen ( V_38 ) || strcmp ( V_38 , L_5 ) == 0 )
V_38 = NULL ;
}
V_25 = F_112 ( V_43 , V_125 , V_126 , V_38 , V_127 ) ;
if ( V_130 )
* ( V_130 - 1 ) = ':' ;
return V_25 ;
}
int F_115 ( const char * system , const char * V_38 , int V_127 )
{
struct V_42 * V_43 = F_116 () ;
if ( ! V_43 )
return - V_39 ;
return F_112 ( V_43 , NULL , system , V_38 , V_127 ) ;
}
static T_2
F_117 ( struct V_69 * V_69 , const char T_3 * V_131 ,
T_4 V_132 , T_5 * V_133 )
{
struct V_134 V_135 ;
struct V_136 * V_137 = V_69 -> V_138 ;
struct V_42 * V_43 = V_137 -> V_139 ;
T_2 V_140 , V_25 ;
if ( ! V_132 )
return 0 ;
V_25 = F_118 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_119 ( & V_135 , V_141 + 1 ) )
return - V_22 ;
V_140 = F_120 ( & V_135 , V_131 , V_132 , V_133 ) ;
if ( V_140 >= 0 && F_121 ( ( & V_135 ) ) ) {
int V_127 = 1 ;
if ( * V_135 . V_57 == '!' )
V_127 = 0 ;
V_135 . V_57 [ V_135 . V_142 ] = 0 ;
V_25 = F_113 ( V_43 , V_135 . V_57 + ! V_127 , V_127 ) ;
if ( V_25 )
goto V_143;
}
V_25 = V_140 ;
V_143:
F_122 ( & V_135 ) ;
return V_25 ;
}
static void *
F_123 ( struct V_136 * V_137 , void * V_144 , T_5 * V_145 )
{
struct V_40 * V_69 = V_144 ;
struct V_4 * V_13 ;
struct V_42 * V_43 = V_137 -> V_139 ;
( * V_145 ) ++ ;
F_124 (file, &tr->events, list) {
V_13 = V_69 -> V_5 ;
if ( V_13 -> V_6 && V_13 -> V_6 -> V_95 &&
! ( V_13 -> V_54 & V_129 ) )
return V_69 ;
}
return NULL ;
}
static void * F_125 ( struct V_136 * V_137 , T_5 * V_145 )
{
struct V_40 * V_69 ;
struct V_42 * V_43 = V_137 -> V_139 ;
T_5 V_146 ;
F_47 ( & V_83 ) ;
V_69 = F_126 ( & V_43 -> V_147 , struct V_40 , V_114 ) ;
for ( V_146 = 0 ; V_146 <= * V_145 ; ) {
V_69 = F_123 ( V_137 , V_69 , & V_146 ) ;
if ( ! V_69 )
break;
}
return V_69 ;
}
static void *
F_127 ( struct V_136 * V_137 , void * V_144 , T_5 * V_145 )
{
struct V_40 * V_69 = V_144 ;
struct V_42 * V_43 = V_137 -> V_139 ;
( * V_145 ) ++ ;
F_124 (file, &tr->events, list) {
if ( V_69 -> V_54 & V_84 )
return V_69 ;
}
return NULL ;
}
static void * F_128 ( struct V_136 * V_137 , T_5 * V_145 )
{
struct V_40 * V_69 ;
struct V_42 * V_43 = V_137 -> V_139 ;
T_5 V_146 ;
F_47 ( & V_83 ) ;
V_69 = F_126 ( & V_43 -> V_147 , struct V_40 , V_114 ) ;
for ( V_146 = 0 ; V_146 <= * V_145 ; ) {
V_69 = F_127 ( V_137 , V_69 , & V_146 ) ;
if ( ! V_69 )
break;
}
return V_69 ;
}
static int F_129 ( struct V_136 * V_137 , void * V_144 )
{
struct V_40 * V_69 = V_144 ;
struct V_4 * V_13 = V_69 -> V_5 ;
if ( strcmp ( V_13 -> V_6 -> system , V_148 ) != 0 )
F_130 ( V_137 , L_6 , V_13 -> V_6 -> system ) ;
F_130 ( V_137 , L_3 , F_59 ( V_13 ) ) ;
return 0 ;
}
static void F_131 ( struct V_136 * V_137 , void * V_149 )
{
F_54 ( & V_83 ) ;
}
static void *
F_132 ( struct V_136 * V_137 , void * V_144 , T_5 * V_145 )
{
struct V_42 * V_43 = V_137 -> V_139 ;
struct V_46 * V_47 = F_27 ( V_43 -> V_48 ) ;
unsigned long V_34 = ( unsigned long ) V_144 ;
( * V_145 ) ++ ;
V_34 = F_133 ( V_47 -> V_102 , V_47 -> V_101 , V_34 ) ;
if ( V_34 < V_47 -> V_101 )
return ( void * ) ( V_34 + 1 ) ;
return NULL ;
}
static void * F_134 ( struct V_136 * V_137 , T_5 * V_145 )
__acquires( T_6 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_137 -> V_139 ;
unsigned long V_34 ;
T_5 V_146 = 0 ;
F_47 ( & V_83 ) ;
F_135 () ;
V_47 = F_27 ( V_43 -> V_48 ) ;
if ( ! V_47 )
return NULL ;
V_34 = F_136 ( V_47 -> V_102 , V_47 -> V_101 ) ;
if ( V_34 >= V_47 -> V_101 )
return NULL ;
for ( V_34 ++ ; V_34 && V_146 < * V_145 ;
V_34 = ( unsigned long ) F_132 ( V_137 , ( void * ) V_34 , & V_146 ) )
;
return ( void * ) V_34 ;
}
static void F_137 ( struct V_136 * V_137 , void * V_149 )
__releases( T_6 )
{
F_138 () ;
F_54 ( & V_83 ) ;
}
static int F_139 ( struct V_136 * V_137 , void * V_144 )
{
unsigned long V_34 = ( unsigned long ) V_144 - 1 ;
F_130 ( V_137 , L_7 , V_34 ) ;
return 0 ;
}
static T_2
F_140 ( struct V_69 * V_150 , char T_3 * V_131 , T_4 V_132 ,
T_5 * V_133 )
{
struct V_40 * V_69 ;
unsigned long V_54 ;
char V_130 [ 4 ] = L_8 ;
F_47 ( & V_83 ) ;
V_69 = F_141 ( V_150 ) ;
if ( F_142 ( V_69 ) )
V_54 = V_69 -> V_54 ;
F_54 ( & V_83 ) ;
if ( ! V_69 )
return - V_39 ;
if ( V_54 & V_84 &&
! ( V_54 & V_90 ) )
strcpy ( V_130 , L_9 ) ;
if ( V_54 & V_90 ||
V_54 & V_92 )
strcat ( V_130 , L_5 ) ;
strcat ( V_130 , L_10 ) ;
return F_143 ( V_131 , V_132 , V_133 , V_130 , strlen ( V_130 ) ) ;
}
static T_2
F_144 ( struct V_69 * V_150 , const char T_3 * V_131 , T_4 V_132 ,
T_5 * V_133 )
{
struct V_40 * V_69 ;
unsigned long V_151 ;
int V_25 ;
V_25 = F_145 ( V_131 , V_132 , 10 , & V_151 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_118 () ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_151 ) {
case 0 :
case 1 :
V_25 = - V_39 ;
F_47 ( & V_83 ) ;
V_69 = F_141 ( V_150 ) ;
if ( F_142 ( V_69 ) )
V_25 = F_63 ( V_69 , V_151 ) ;
F_54 ( & V_83 ) ;
break;
default:
return - V_128 ;
}
* V_133 += V_132 ;
return V_25 ? V_25 : V_132 ;
}
static T_2
F_146 ( struct V_69 * V_150 , char T_3 * V_131 , T_4 V_132 ,
T_5 * V_133 )
{
const char V_152 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_116 * V_117 = V_150 -> V_138 ;
struct V_1 * system = V_117 -> V_118 ;
struct V_4 * V_13 ;
struct V_40 * V_69 ;
struct V_42 * V_43 = V_117 -> V_43 ;
char V_130 [ 2 ] ;
int V_127 = 0 ;
int V_25 ;
F_47 ( & V_83 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_69 -> V_5 ;
if ( ! F_59 ( V_13 ) || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_95 )
continue;
if ( system && strcmp ( V_13 -> V_6 -> system , system -> V_11 ) != 0 )
continue;
V_127 |= ( 1 << ! ! ( V_69 -> V_54 & V_84 ) ) ;
if ( V_127 == 3 )
break;
}
F_54 ( & V_83 ) ;
V_130 [ 0 ] = V_152 [ V_127 ] ;
V_130 [ 1 ] = '\n' ;
V_25 = F_143 ( V_131 , V_132 , V_133 , V_130 , 2 ) ;
return V_25 ;
}
static T_2
F_147 ( struct V_69 * V_150 , const char T_3 * V_131 , T_4 V_132 ,
T_5 * V_133 )
{
struct V_116 * V_117 = V_150 -> V_138 ;
struct V_1 * system = V_117 -> V_118 ;
const char * V_11 = NULL ;
unsigned long V_151 ;
T_2 V_25 ;
V_25 = F_145 ( V_131 , V_132 , 10 , & V_151 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_118 () ;
if ( V_25 < 0 )
return V_25 ;
if ( V_151 != 0 && V_151 != 1 )
return - V_128 ;
if ( system )
V_11 = system -> V_11 ;
V_25 = F_112 ( V_117 -> V_43 , NULL , V_11 , NULL , V_151 ) ;
if ( V_25 )
goto V_153;
V_25 = V_132 ;
V_153:
* V_133 += V_132 ;
return V_25 ;
}
static void * F_148 ( struct V_136 * V_137 , void * V_144 , T_5 * V_145 )
{
struct V_4 * V_13 = F_141 ( V_137 -> V_139 ) ;
struct V_3 * V_154 = & V_15 ;
struct V_3 * V_10 = F_4 ( V_13 ) ;
struct V_3 * V_155 = V_144 ;
( * V_145 ) ++ ;
switch ( ( unsigned long ) V_144 ) {
case V_156 :
V_155 = V_154 ;
break;
case V_157 :
V_155 = V_10 ;
break;
case V_158 :
return NULL ;
}
V_155 = V_155 -> V_109 ;
if ( V_155 == V_154 )
return ( void * ) V_157 ;
else if ( V_155 == V_10 )
return ( void * ) V_158 ;
else
return V_155 ;
}
static int F_149 ( struct V_136 * V_137 , void * V_144 )
{
struct V_4 * V_13 = F_141 ( V_137 -> V_139 ) ;
struct V_9 * V_12 ;
const char * V_159 ;
switch ( ( unsigned long ) V_144 ) {
case V_156 :
F_130 ( V_137 , L_11 , F_59 ( V_13 ) ) ;
F_130 ( V_137 , L_12 , V_13 -> V_38 . type ) ;
F_150 ( V_137 , L_13 ) ;
return 0 ;
case V_157 :
F_151 ( V_137 , '\n' ) ;
return 0 ;
case V_158 :
F_130 ( V_137 , L_14 ,
V_13 -> V_160 ) ;
return 0 ;
}
V_12 = F_126 ( V_144 , struct V_9 , V_24 ) ;
V_159 = strchr ( V_12 -> type , '[' ) ;
if ( ! strncmp ( V_12 -> type , L_15 , 10 ) )
V_159 = NULL ;
if ( ! V_159 )
F_130 ( V_137 , L_16 ,
V_12 -> type , V_12 -> V_11 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
else
F_130 ( V_137 , L_17 ,
( int ) ( V_159 - V_12 -> type ) ,
V_12 -> type , V_12 -> V_11 ,
V_159 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
return 0 ;
}
static void * F_152 ( struct V_136 * V_137 , T_5 * V_145 )
{
void * V_149 = ( void * ) V_156 ;
T_5 V_146 = 0 ;
F_47 ( & V_83 ) ;
if ( ! F_141 ( V_137 -> V_139 ) )
return F_153 ( - V_39 ) ;
while ( V_146 < * V_145 && V_149 )
V_149 = F_148 ( V_137 , V_149 , & V_146 ) ;
return V_149 ;
}
static void F_154 ( struct V_136 * V_137 , void * V_149 )
{
F_54 ( & V_83 ) ;
}
static int F_155 ( struct V_161 * V_161 , struct V_69 * V_69 )
{
struct V_136 * V_137 ;
int V_25 ;
V_25 = F_156 ( V_69 , & V_162 ) ;
if ( V_25 < 0 )
return V_25 ;
V_137 = V_69 -> V_138 ;
V_137 -> V_139 = V_69 ;
return 0 ;
}
static T_2
F_157 ( struct V_69 * V_150 , char T_3 * V_131 , T_4 V_132 , T_5 * V_133 )
{
int V_37 = ( long ) F_141 ( V_150 ) ;
char V_130 [ 32 ] ;
int V_53 ;
if ( * V_133 )
return 0 ;
if ( F_158 ( ! V_37 ) )
return - V_39 ;
V_53 = sprintf ( V_130 , L_18 , V_37 ) ;
return F_143 ( V_131 , V_132 , V_133 , V_130 , V_53 ) ;
}
static T_2
F_159 ( struct V_69 * V_150 , char T_3 * V_131 , T_4 V_132 ,
T_5 * V_133 )
{
struct V_40 * V_69 ;
struct V_163 * V_164 ;
int V_165 = - V_39 ;
if ( * V_133 )
return 0 ;
V_164 = F_160 ( sizeof( * V_164 ) , V_166 ) ;
if ( ! V_164 )
return - V_22 ;
F_36 ( V_164 ) ;
F_47 ( & V_83 ) ;
V_69 = F_141 ( V_150 ) ;
if ( V_69 )
F_161 ( V_69 , V_164 ) ;
F_54 ( & V_83 ) ;
if ( V_69 )
V_165 = F_143 ( V_131 , V_132 , V_133 ,
V_164 -> V_57 , F_162 ( V_164 ) ) ;
F_94 ( V_164 ) ;
return V_165 ;
}
static T_2
F_163 ( struct V_69 * V_150 , const char T_3 * V_131 , T_4 V_132 ,
T_5 * V_133 )
{
struct V_40 * V_69 ;
char * V_130 ;
int V_167 = - V_39 ;
if ( V_132 >= V_168 )
return - V_128 ;
V_130 = F_164 ( V_131 , V_132 ) ;
if ( F_165 ( V_130 ) )
return F_166 ( V_130 ) ;
F_47 ( & V_83 ) ;
V_69 = F_141 ( V_150 ) ;
if ( V_69 )
V_167 = F_167 ( V_69 , V_130 ) ;
F_54 ( & V_83 ) ;
F_94 ( V_130 ) ;
if ( V_167 < 0 )
return V_167 ;
* V_133 += V_132 ;
return V_132 ;
}
static int F_168 ( struct V_161 * V_161 , struct V_69 * V_150 )
{
struct V_1 * system = NULL ;
struct V_116 * V_117 = NULL ;
struct V_42 * V_43 ;
int V_25 ;
if ( F_169 () )
return - V_39 ;
F_47 ( & V_169 ) ;
F_47 ( & V_83 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_117 == V_161 -> V_123 ) {
if ( V_117 -> V_119 ) {
F_100 ( V_117 ) ;
system = V_117 -> V_118 ;
}
goto V_170;
}
}
}
V_170:
F_54 ( & V_83 ) ;
F_54 ( & V_169 ) ;
if ( ! system )
return - V_39 ;
F_13 ( ! V_117 ) ;
if ( F_170 ( V_43 ) < 0 ) {
F_102 ( V_117 ) ;
return - V_39 ;
}
V_25 = F_171 ( V_161 , V_150 ) ;
if ( V_25 < 0 ) {
F_172 ( V_43 ) ;
F_102 ( V_117 ) ;
}
return V_25 ;
}
static int F_173 ( struct V_161 * V_161 , struct V_69 * V_150 )
{
struct V_116 * V_117 ;
struct V_42 * V_43 = V_161 -> V_123 ;
int V_25 ;
if ( F_169 () )
return - V_39 ;
if ( F_170 ( V_43 ) < 0 )
return - V_39 ;
V_117 = F_174 ( sizeof( * V_117 ) , V_166 ) ;
if ( ! V_117 ) {
F_172 ( V_43 ) ;
return - V_22 ;
}
V_117 -> V_43 = V_43 ;
V_25 = F_171 ( V_161 , V_150 ) ;
if ( V_25 < 0 ) {
F_172 ( V_43 ) ;
F_94 ( V_117 ) ;
return V_25 ;
}
V_150 -> V_138 = V_117 ;
return 0 ;
}
static int F_175 ( struct V_161 * V_161 , struct V_69 * V_69 )
{
struct V_116 * V_117 = V_69 -> V_138 ;
F_172 ( V_117 -> V_43 ) ;
if ( V_117 -> V_118 )
F_102 ( V_117 ) ;
else
F_94 ( V_117 ) ;
return 0 ;
}
static T_2
F_176 ( struct V_69 * V_150 , char T_3 * V_131 , T_4 V_132 ,
T_5 * V_133 )
{
struct V_116 * V_117 = V_150 -> V_138 ;
struct V_1 * system = V_117 -> V_118 ;
struct V_163 * V_164 ;
int V_165 ;
if ( * V_133 )
return 0 ;
V_164 = F_160 ( sizeof( * V_164 ) , V_166 ) ;
if ( ! V_164 )
return - V_22 ;
F_36 ( V_164 ) ;
F_177 ( system , V_164 ) ;
V_165 = F_143 ( V_131 , V_132 , V_133 ,
V_164 -> V_57 , F_162 ( V_164 ) ) ;
F_94 ( V_164 ) ;
return V_165 ;
}
static T_2
F_178 ( struct V_69 * V_150 , const char T_3 * V_131 , T_4 V_132 ,
T_5 * V_133 )
{
struct V_116 * V_117 = V_150 -> V_138 ;
char * V_130 ;
int V_167 ;
if ( V_132 >= V_168 )
return - V_128 ;
V_130 = F_164 ( V_131 , V_132 ) ;
if ( F_165 ( V_130 ) )
return F_166 ( V_130 ) ;
V_167 = F_179 ( V_117 , V_130 ) ;
F_94 ( V_130 ) ;
if ( V_167 < 0 )
return V_167 ;
* V_133 += V_132 ;
return V_132 ;
}
static T_2
F_180 ( struct V_69 * V_150 , char T_3 * V_131 , T_4 V_132 , T_5 * V_133 )
{
int (* F_181)( struct V_163 * V_164 ) = V_150 -> V_138 ;
struct V_163 * V_164 ;
int V_165 ;
if ( * V_133 )
return 0 ;
V_164 = F_160 ( sizeof( * V_164 ) , V_166 ) ;
if ( ! V_164 )
return - V_22 ;
F_36 ( V_164 ) ;
F_181 ( V_164 ) ;
V_165 = F_143 ( V_131 , V_132 , V_133 ,
V_164 -> V_57 , F_162 ( V_164 ) ) ;
F_94 ( V_164 ) ;
return V_165 ;
}
static void F_182 ( void * V_45 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_83 ( V_43 -> V_48 ,
F_183 ( & V_83 ) ) ;
F_77 ( V_43 -> V_49 . V_45 -> V_50 ,
F_67 ( V_47 , V_110 ) ) ;
}
static T_2
F_184 ( struct V_69 * V_150 , const char T_3 * V_131 ,
T_4 V_132 , T_5 * V_133 )
{
struct V_136 * V_137 = V_150 -> V_138 ;
struct V_42 * V_43 = V_137 -> V_139 ;
struct V_46 * V_48 = NULL ;
struct V_46 * V_47 ;
struct V_40 * V_69 ;
struct V_134 V_135 ;
unsigned long V_151 ;
T_5 V_171 ;
T_2 V_140 = 0 ;
T_2 V_25 = 0 ;
T_1 V_34 ;
int V_172 = 0 ;
if ( ! V_132 )
return 0 ;
V_25 = F_118 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_119 ( & V_135 , V_141 + 1 ) )
return - V_22 ;
F_47 ( & V_83 ) ;
V_48 = F_83 ( V_43 -> V_48 ,
F_84 ( & V_83 ) ) ;
V_47 = F_160 ( sizeof( * V_47 ) , V_166 ) ;
if ( ! V_47 ) {
V_140 = - V_22 ;
goto V_153;
}
V_47 -> V_101 = F_185 ( V_101 ) ;
if ( V_48 && V_48 -> V_101 > V_47 -> V_101 )
V_47 -> V_101 = V_48 -> V_101 ;
V_47 -> V_102 = F_186 ( ( V_47 -> V_101 + 7 ) >> 3 ) ;
if ( ! V_47 -> V_102 ) {
F_94 ( V_47 ) ;
V_140 = - V_22 ;
goto V_153;
}
if ( V_48 ) {
V_34 = F_136 ( V_48 -> V_102 ,
V_48 -> V_101 ) ;
while ( V_34 < V_48 -> V_101 ) {
F_50 ( V_34 , V_47 -> V_102 ) ;
V_34 = F_133 ( V_48 -> V_102 ,
V_48 -> V_101 ,
V_34 + 1 ) ;
V_172 ++ ;
}
}
while ( V_132 > 0 ) {
V_171 = 0 ;
V_25 = F_120 ( & V_135 , V_131 , V_132 , & V_171 ) ;
if ( V_25 < 0 || ! F_121 ( & V_135 ) )
break;
V_140 += V_25 ;
V_131 += V_25 ;
V_132 -= V_25 ;
V_135 . V_57 [ V_135 . V_142 ] = 0 ;
V_25 = - V_128 ;
if ( F_187 ( V_135 . V_57 , 0 , & V_151 ) )
break;
if ( V_151 >= V_47 -> V_101 )
break;
V_34 = ( T_1 ) V_151 ;
F_50 ( V_34 , V_47 -> V_102 ) ;
V_172 ++ ;
F_188 ( & V_135 ) ;
V_25 = 0 ;
}
F_122 ( & V_135 ) ;
if ( V_25 < 0 ) {
F_93 ( V_47 -> V_102 ) ;
F_94 ( V_47 ) ;
V_140 = V_25 ;
goto V_153;
}
if ( ! V_172 ) {
F_93 ( V_47 -> V_102 ) ;
F_94 ( V_47 ) ;
V_140 = V_25 ;
if ( ! V_48 )
goto V_153;
V_47 = NULL ;
}
F_91 ( V_43 -> V_48 , V_47 ) ;
F_6 (file, &tr->events, list) {
F_50 ( V_111 , & V_69 -> V_54 ) ;
}
if ( V_48 ) {
F_92 () ;
F_93 ( V_48 -> V_102 ) ;
F_94 ( V_48 ) ;
} else {
F_189 ( F_76 ,
V_43 , V_107 ) ;
F_189 ( F_78 ,
V_43 , 0 ) ;
F_190 ( F_79 ,
V_43 , V_107 ) ;
F_190 ( F_81 ,
V_43 , 0 ) ;
F_191 ( F_79 ,
V_43 , V_107 ) ;
F_191 ( F_81 ,
V_43 , 0 ) ;
F_192 ( F_79 ,
V_43 , V_107 ) ;
F_192 ( F_81 ,
V_43 , 0 ) ;
}
F_193 ( F_182 , V_43 , 1 ) ;
V_153:
F_54 ( & V_83 ) ;
V_25 = V_140 ;
if ( V_140 > 0 )
* V_133 += V_140 ;
return V_25 ;
}
static int
F_194 ( struct V_161 * V_161 , struct V_69 * V_69 ,
const struct V_173 * V_174 )
{
struct V_136 * V_137 ;
int V_25 ;
V_25 = F_156 ( V_69 , V_174 ) ;
if ( V_25 < 0 )
return V_25 ;
V_137 = V_69 -> V_138 ;
V_137 -> V_139 = V_161 -> V_123 ;
return V_25 ;
}
static int F_195 ( struct V_161 * V_161 , struct V_69 * V_69 )
{
struct V_42 * V_43 = V_161 -> V_123 ;
F_172 ( V_43 ) ;
return F_196 ( V_161 , V_69 ) ;
}
static int
F_197 ( struct V_161 * V_161 , struct V_69 * V_69 )
{
const struct V_173 * V_174 = & V_175 ;
return F_194 ( V_161 , V_69 , V_174 ) ;
}
static int
F_198 ( struct V_161 * V_161 , struct V_69 * V_69 )
{
const struct V_173 * V_174 = & V_176 ;
struct V_42 * V_43 = V_161 -> V_123 ;
int V_25 ;
if ( F_170 ( V_43 ) < 0 )
return - V_39 ;
if ( ( V_69 -> V_177 & V_178 ) &&
( V_69 -> V_179 & V_180 ) )
F_64 ( V_43 ) ;
V_25 = F_194 ( V_161 , V_69 , V_174 ) ;
if ( V_25 < 0 )
F_172 ( V_43 ) ;
return V_25 ;
}
static int
F_199 ( struct V_161 * V_161 , struct V_69 * V_69 )
{
const struct V_173 * V_174 = & V_181 ;
struct V_42 * V_43 = V_161 -> V_123 ;
int V_25 ;
if ( F_170 ( V_43 ) < 0 )
return - V_39 ;
if ( ( V_69 -> V_177 & V_178 ) &&
( V_69 -> V_179 & V_180 ) )
F_95 ( V_43 ) ;
V_25 = F_194 ( V_161 , V_69 , V_174 ) ;
if ( V_25 < 0 )
F_172 ( V_43 ) ;
return V_25 ;
}
static struct V_1 *
F_200 ( const char * V_11 )
{
struct V_1 * system ;
system = F_160 ( sizeof( * system ) , V_166 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
system -> V_11 = F_201 ( V_11 , V_166 ) ;
if ( ! system -> V_11 )
goto V_182;
system -> V_113 = NULL ;
system -> V_113 = F_174 ( sizeof( struct V_112 ) , V_166 ) ;
if ( ! system -> V_113 )
goto V_182;
F_11 ( & system -> V_114 , & V_183 ) ;
return system ;
V_182:
F_98 ( system -> V_11 ) ;
F_94 ( system ) ;
return NULL ;
}
static struct V_120 *
F_202 ( struct V_42 * V_43 , const char * V_11 ,
struct V_40 * V_69 , struct V_120 * V_184 )
{
struct V_116 * V_117 ;
struct V_1 * system ;
struct V_120 * V_58 ;
F_6 (dir, &tr->systems, list) {
system = V_117 -> V_118 ;
if ( strcmp ( system -> V_11 , V_11 ) == 0 ) {
V_117 -> V_119 ++ ;
V_69 -> system = V_117 ;
return V_117 -> V_58 ;
}
}
F_6 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_11 , V_11 ) == 0 )
break;
}
if ( & system -> V_114 == & V_183 )
system = NULL ;
V_117 = F_160 ( sizeof( * V_117 ) , V_166 ) ;
if ( ! V_117 )
goto V_185;
if ( ! system ) {
system = F_200 ( V_11 ) ;
if ( ! system )
goto V_182;
} else
F_99 ( system ) ;
V_117 -> V_58 = F_203 ( V_11 , V_184 ) ;
if ( ! V_117 -> V_58 ) {
F_204 ( L_19 , V_11 ) ;
F_96 ( system ) ;
goto V_182;
}
V_117 -> V_43 = V_43 ;
V_117 -> V_2 = 1 ;
V_117 -> V_119 = 1 ;
V_117 -> V_118 = system ;
V_69 -> system = V_117 ;
V_58 = F_205 ( L_20 , 0644 , V_117 -> V_58 , V_117 ,
& V_186 ) ;
if ( ! V_58 ) {
F_94 ( system -> V_113 ) ;
system -> V_113 = NULL ;
F_204 ( L_21 , V_11 ) ;
}
F_206 ( L_22 , 0644 , V_117 -> V_58 , V_117 ,
& V_187 ) ;
F_11 ( & V_117 -> V_114 , & V_43 -> V_188 ) ;
return V_117 -> V_58 ;
V_182:
F_94 ( V_117 ) ;
V_185:
if ( ! V_117 || ! system )
F_204 ( L_23 , V_11 ) ;
return NULL ;
}
static int
F_207 ( struct V_120 * V_184 , struct V_40 * V_69 )
{
struct V_4 * V_13 = V_69 -> V_5 ;
struct V_42 * V_43 = V_69 -> V_43 ;
struct V_3 * V_10 ;
struct V_120 * V_189 ;
const char * V_11 ;
int V_25 ;
if ( strcmp ( V_13 -> V_6 -> system , V_148 ) != 0 ) {
V_189 = F_202 ( V_43 , V_13 -> V_6 -> system , V_69 , V_184 ) ;
if ( ! V_189 )
return - V_22 ;
} else
V_189 = V_184 ;
V_11 = F_59 ( V_13 ) ;
V_69 -> V_117 = F_203 ( V_11 , V_189 ) ;
if ( ! V_69 -> V_117 ) {
F_204 ( L_24 , V_11 ) ;
return - 1 ;
}
if ( V_13 -> V_6 -> V_95 && ! ( V_13 -> V_54 & V_129 ) )
F_206 ( L_22 , 0644 , V_69 -> V_117 , V_69 ,
& V_190 ) ;
#ifdef F_45
if ( V_13 -> V_38 . type && V_13 -> V_6 -> V_95 )
F_206 ( L_25 , 0444 , V_69 -> V_117 ,
( void * ) ( long ) V_13 -> V_38 . type ,
& V_191 ) ;
#endif
V_10 = F_4 ( V_13 ) ;
if ( F_208 ( V_10 ) ) {
V_25 = V_13 -> V_6 -> V_192 ( V_13 ) ;
if ( V_25 < 0 ) {
F_204 ( L_26 ,
V_11 ) ;
return - 1 ;
}
}
F_206 ( L_20 , 0644 , V_69 -> V_117 , V_69 ,
& V_193 ) ;
if ( ! ( V_13 -> V_54 & V_129 ) )
F_206 ( L_27 , 0644 , V_69 -> V_117 , V_69 ,
& V_194 ) ;
#ifdef F_209
F_206 ( L_28 , 0444 , V_69 -> V_117 , V_69 ,
& V_195 ) ;
#endif
F_206 ( L_29 , 0444 , V_69 -> V_117 , V_13 ,
& V_196 ) ;
return 0 ;
}
static void F_210 ( struct V_4 * V_13 )
{
struct V_40 * V_69 ;
struct V_42 * V_43 ;
F_211 (tr, file) {
if ( V_69 -> V_5 != V_13 )
continue;
F_105 ( V_69 ) ;
break;
} F_53 () ;
}
static void F_212 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
struct V_40 * V_69 ;
F_48 (tr, file) {
if ( V_69 -> V_5 != V_13 )
continue;
F_63 ( V_69 , 0 ) ;
break;
} F_53 () ;
if ( V_13 -> V_38 . V_63 )
F_213 ( & V_13 -> V_38 ) ;
F_210 ( V_13 ) ;
F_20 ( & V_13 -> V_114 ) ;
}
static int F_214 ( struct V_4 * V_13 )
{
int V_25 = 0 ;
const char * V_11 ;
V_11 = F_59 ( V_13 ) ;
if ( F_13 ( ! V_11 ) )
return - V_128 ;
if ( V_13 -> V_6 -> V_197 ) {
V_25 = V_13 -> V_6 -> V_197 ( V_13 ) ;
if ( V_25 < 0 && V_25 != - V_198 )
F_204 ( L_30 , V_11 ) ;
}
return V_25 ;
}
static int
F_215 ( struct V_4 * V_13 , struct V_199 * V_200 )
{
int V_25 ;
V_25 = F_214 ( V_13 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_13 -> V_114 , & V_201 ) ;
V_13 -> V_200 = V_200 ;
return 0 ;
}
static char * F_216 ( char * V_202 , struct V_203 * V_204 , int V_53 )
{
int V_205 ;
int V_206 ;
V_206 = snprintf ( V_202 , 0 , L_31 , V_204 -> V_207 ) ;
if ( V_53 < V_206 )
return NULL ;
snprintf ( V_202 , V_206 + 1 , L_31 , V_204 -> V_207 ) ;
V_205 = strlen ( V_202 + V_53 ) ;
memmove ( V_202 + V_206 , V_202 + V_53 , V_205 ) ;
V_202 [ V_206 + V_205 ] = 0 ;
return V_202 + V_206 ;
}
static void F_217 ( struct V_4 * V_13 ,
struct V_203 * V_204 )
{
char * V_202 ;
int V_208 = 0 ;
int V_53 = strlen ( V_204 -> V_209 ) ;
for ( V_202 = V_13 -> V_160 ; * V_202 ; V_202 ++ ) {
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
if ( strncmp ( V_204 -> V_209 , V_202 , V_53 ) == 0 &&
! isalnum ( V_202 [ V_53 ] ) && V_202 [ V_53 ] != '_' ) {
V_202 = F_216 ( V_202 , V_204 , V_53 ) ;
if ( F_97 ( ! V_202 ) )
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
void F_218 ( struct V_203 * * V_204 , int V_53 )
{
struct V_4 * V_13 , * V_149 ;
const char * V_211 = NULL ;
int V_212 ;
int V_213 ;
F_219 ( & V_214 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( ! V_211 || V_13 -> V_6 -> system != V_211 ) {
V_212 = 0 ;
V_211 = V_13 -> V_6 -> system ;
}
for ( V_213 = V_212 ; V_213 < V_53 ; V_213 ++ ) {
if ( V_13 -> V_6 -> system == V_204 [ V_213 ] -> system ) {
if ( ! V_212 )
V_212 = V_213 ;
F_217 ( V_13 , V_204 [ V_213 ] ) ;
}
}
}
F_220 ( & V_214 ) ;
}
static struct V_40 *
F_221 ( struct V_4 * V_13 ,
struct V_42 * V_43 )
{
struct V_40 * V_69 ;
V_69 = F_9 ( V_124 , V_21 ) ;
if ( ! V_69 )
return NULL ;
V_69 -> V_5 = V_13 ;
V_69 -> V_43 = V_43 ;
F_222 ( & V_69 -> V_89 , 0 ) ;
F_222 ( & V_69 -> V_215 , 0 ) ;
F_223 ( & V_69 -> V_216 ) ;
F_11 ( & V_69 -> V_114 , & V_43 -> V_147 ) ;
return V_69 ;
}
static int
F_224 ( struct V_4 * V_13 , struct V_42 * V_43 )
{
struct V_40 * V_69 ;
V_69 = F_221 ( V_13 , V_43 ) ;
if ( ! V_69 )
return - V_22 ;
return F_207 ( V_43 -> V_217 , V_69 ) ;
}
static T_7 int
F_225 ( struct V_4 * V_13 ,
struct V_42 * V_43 )
{
struct V_40 * V_69 ;
V_69 = F_221 ( V_13 , V_43 ) ;
if ( ! V_69 )
return - V_22 ;
return 0 ;
}
int F_226 ( struct V_4 * V_13 )
{
int V_25 ;
F_47 ( & V_169 ) ;
F_47 ( & V_83 ) ;
V_25 = F_215 ( V_13 , NULL ) ;
if ( V_25 >= 0 )
F_227 ( V_13 ) ;
F_54 ( & V_83 ) ;
F_54 ( & V_169 ) ;
return V_25 ;
}
static void F_228 ( struct V_4 * V_13 )
{
F_212 ( V_13 ) ;
F_18 ( V_13 ) ;
F_110 ( V_13 -> V_113 ) ;
V_13 -> V_113 = NULL ;
}
static int F_229 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
struct V_40 * V_69 ;
#ifdef F_45
if ( V_13 -> V_218 )
return - V_219 ;
#endif
F_48 (tr, file) {
if ( V_69 -> V_5 != V_13 )
continue;
if ( V_69 -> V_54 & V_84 )
return - V_219 ;
break;
} F_53 () ;
F_228 ( V_13 ) ;
return 0 ;
}
int F_230 ( struct V_4 * V_13 )
{
int V_25 ;
F_47 ( & V_169 ) ;
F_47 ( & V_83 ) ;
F_219 ( & V_214 ) ;
V_25 = F_229 ( V_13 ) ;
F_220 ( & V_214 ) ;
F_54 ( & V_83 ) ;
F_54 ( & V_169 ) ;
return V_25 ;
}
static void F_231 ( struct V_199 * V_200 )
{
struct V_4 * * V_13 , * * V_220 , * * V_221 ;
if ( ! V_200 -> V_222 )
return;
if ( F_232 ( V_200 ) ) {
F_233 ( L_32 ,
V_200 -> V_11 ) ;
return;
}
V_220 = V_200 -> V_223 ;
V_221 = V_200 -> V_223 + V_200 -> V_222 ;
F_234 (call, start, end) {
F_215 ( * V_13 , V_200 ) ;
F_227 ( * V_13 ) ;
}
}
static void F_235 ( struct V_199 * V_200 )
{
struct V_4 * V_13 , * V_149 ;
bool V_224 = false ;
F_219 ( & V_214 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( V_13 -> V_200 == V_200 ) {
if ( V_13 -> V_54 & V_99 )
V_224 = true ;
F_228 ( V_13 ) ;
}
}
F_220 ( & V_214 ) ;
if ( V_224 )
F_236 () ;
}
static int F_237 ( struct V_225 * V_105 ,
unsigned long V_151 , void * V_45 )
{
struct V_199 * V_200 = V_45 ;
F_47 ( & V_169 ) ;
F_47 ( & V_83 ) ;
switch ( V_151 ) {
case V_226 :
F_231 ( V_200 ) ;
break;
case V_227 :
F_235 ( V_200 ) ;
break;
}
F_54 ( & V_83 ) ;
F_54 ( & V_169 ) ;
return 0 ;
}
static void
F_238 ( struct V_42 * V_43 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
V_25 = F_224 ( V_13 , V_43 ) ;
if ( V_25 < 0 )
F_204 ( L_33 ,
F_59 ( V_13 ) ) ;
}
}
struct V_40 *
F_239 ( struct V_42 * V_43 , const char * system , const char * V_38 )
{
struct V_40 * V_69 ;
struct V_4 * V_13 ;
const char * V_11 ;
F_6 (file, &tr->events, list) {
V_13 = V_69 -> V_5 ;
V_11 = F_59 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_95 )
continue;
if ( V_13 -> V_54 & V_129 )
continue;
if ( strcmp ( V_38 , V_11 ) == 0 &&
strcmp ( system , V_13 -> V_6 -> system ) == 0 )
return V_69 ;
}
return NULL ;
}
static void
F_240 ( unsigned long V_228 , unsigned long V_229 , void * * V_230 )
{
struct V_231 * * V_232 = (struct V_231 * * ) V_230 ;
struct V_231 * V_45 = * V_232 ;
if ( ! V_45 )
return;
if ( V_45 -> V_82 )
F_52 ( V_96 , & V_45 -> V_69 -> V_54 ) ;
else
F_50 ( V_96 , & V_45 -> V_69 -> V_54 ) ;
}
static void
F_241 ( unsigned long V_228 , unsigned long V_229 , void * * V_230 )
{
struct V_231 * * V_232 = (struct V_231 * * ) V_230 ;
struct V_231 * V_45 = * V_232 ;
if ( ! V_45 )
return;
if ( ! V_45 -> V_233 )
return;
if ( V_45 -> V_82 == ! ( V_45 -> V_69 -> V_54 & V_90 ) )
return;
if ( V_45 -> V_233 != - 1 )
( V_45 -> V_233 ) -- ;
F_240 ( V_228 , V_229 , V_230 ) ;
}
static int
F_242 ( struct V_136 * V_137 , unsigned long V_228 ,
struct V_234 * V_235 , void * V_230 )
{
struct V_231 * V_45 = V_230 ;
F_130 ( V_137 , L_34 , ( void * ) V_228 ) ;
F_130 ( V_137 , L_35 ,
V_45 -> V_82 ? V_236 : V_237 ,
V_45 -> V_69 -> V_5 -> V_6 -> system ,
F_59 ( V_45 -> V_69 -> V_5 ) ) ;
if ( V_45 -> V_233 == - 1 )
F_150 ( V_137 , L_36 ) ;
else
F_130 ( V_137 , L_37 , V_45 -> V_233 ) ;
return 0 ;
}
static int
F_243 ( struct V_234 * V_235 , unsigned long V_228 ,
void * * V_230 )
{
struct V_231 * * V_232 = (struct V_231 * * ) V_230 ;
struct V_231 * V_45 = * V_232 ;
V_45 -> V_238 ++ ;
return 0 ;
}
static void
F_244 ( struct V_234 * V_235 , unsigned long V_228 ,
void * * V_230 )
{
struct V_231 * * V_232 = (struct V_231 * * ) V_230 ;
struct V_231 * V_45 = * V_232 ;
if ( F_97 ( V_45 -> V_238 <= 0 ) )
return;
V_45 -> V_238 -- ;
if ( ! V_45 -> V_238 ) {
F_55 ( V_45 -> V_69 , 0 , 1 ) ;
F_245 ( V_45 -> V_69 -> V_5 -> V_200 ) ;
F_94 ( V_45 ) ;
}
* V_232 = NULL ;
}
static int
F_246 ( struct V_239 * V_240 ,
char * V_241 , char * V_242 , char * V_243 , int V_244 )
{
struct V_42 * V_43 = F_116 () ;
struct V_40 * V_69 ;
struct V_234 * V_235 ;
struct V_231 * V_45 ;
const char * system ;
const char * V_38 ;
char * V_245 ;
bool V_82 ;
int V_25 ;
if ( ! V_43 )
return - V_39 ;
if ( ! V_244 || ! V_243 )
return - V_128 ;
system = F_114 ( & V_243 , L_4 ) ;
if ( ! V_243 )
return - V_128 ;
V_38 = F_114 ( & V_243 , L_4 ) ;
F_47 ( & V_83 ) ;
V_25 = - V_128 ;
V_69 = F_239 ( V_43 , system , V_38 ) ;
if ( ! V_69 )
goto V_153;
V_82 = strcmp ( V_242 , V_236 ) == 0 ;
if ( V_82 )
V_235 = V_243 ? & V_246 : & V_247 ;
else
V_235 = V_243 ? & V_248 : & V_249 ;
if ( V_241 [ 0 ] == '!' ) {
F_247 ( V_241 + 1 , V_235 ) ;
V_25 = 0 ;
goto V_153;
}
V_25 = - V_22 ;
V_45 = F_174 ( sizeof( * V_45 ) , V_166 ) ;
if ( ! V_45 )
goto V_153;
V_45 -> V_82 = V_82 ;
V_45 -> V_233 = - 1 ;
V_45 -> V_69 = V_69 ;
if ( ! V_243 )
goto V_250;
V_245 = F_114 ( & V_243 , L_4 ) ;
V_25 = - V_128 ;
if ( ! strlen ( V_245 ) )
goto V_182;
V_25 = F_187 ( V_245 , 0 , & V_45 -> V_233 ) ;
if ( V_25 )
goto V_182;
V_250:
V_25 = F_248 ( V_69 -> V_5 -> V_200 ) ;
if ( ! V_25 ) {
V_25 = - V_219 ;
goto V_182;
}
V_25 = F_55 ( V_69 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_143;
V_25 = F_249 ( V_241 , V_235 , V_45 ) ;
if ( ! V_25 ) {
V_25 = - V_251 ;
goto V_252;
} else if ( V_25 < 0 )
goto V_252;
V_25 = 0 ;
V_153:
F_54 ( & V_83 ) ;
return V_25 ;
V_252:
F_55 ( V_69 , 0 , 1 ) ;
V_143:
F_245 ( V_69 -> V_5 -> V_200 ) ;
V_182:
F_94 ( V_45 ) ;
goto V_153;
}
static T_7 int F_250 ( void )
{
int V_25 ;
V_25 = F_251 ( & V_253 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_251 ( & V_254 ) ;
if ( F_13 ( V_25 < 0 ) )
F_252 ( & V_253 ) ;
return V_25 ;
}
static inline int F_250 ( void ) { return 0 ; }
static T_7 void
F_253 ( struct V_42 * V_43 )
{
struct V_40 * V_69 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_207 ( V_43 -> V_217 , V_69 ) ;
if ( V_25 < 0 )
F_204 ( L_33 ,
F_59 ( V_69 -> V_5 ) ) ;
}
}
static T_7 void
F_254 ( struct V_42 * V_43 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_97 ( V_13 -> V_200 ) )
continue;
V_25 = F_225 ( V_13 , V_43 ) ;
if ( V_25 < 0 )
F_204 ( L_38 ,
F_59 ( V_13 ) ) ;
}
}
static void
F_255 ( struct V_42 * V_43 )
{
struct V_40 * V_69 , * V_35 ;
F_19 (file, next, &tr->events, list)
F_105 ( V_69 ) ;
}
static void F_227 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_224 ( V_13 , V_43 ) ;
}
static T_7 int F_256 ( char * V_255 )
{
F_257 ( V_256 , V_255 , V_257 ) ;
V_258 = true ;
V_259 = true ;
return 1 ;
}
static int
F_258 ( struct V_120 * V_184 , struct V_42 * V_43 )
{
struct V_120 * V_189 ;
struct V_120 * V_58 ;
V_58 = F_205 ( L_39 , 0644 , V_184 ,
V_43 , & V_260 ) ;
if ( ! V_58 ) {
F_204 ( L_40 ) ;
return - V_22 ;
}
V_189 = F_203 ( L_41 , V_184 ) ;
if ( ! V_189 ) {
F_204 ( L_42 ) ;
return - V_22 ;
}
V_58 = F_205 ( L_43 , 0644 , V_184 ,
V_43 , & V_261 ) ;
F_206 ( L_44 , 0444 , V_189 ,
V_262 ,
& V_263 ) ;
F_206 ( L_45 , 0444 , V_189 ,
V_264 ,
& V_263 ) ;
F_206 ( L_22 , 0644 , V_189 ,
V_43 , & V_265 ) ;
V_43 -> V_217 = V_189 ;
return 0 ;
}
int F_259 ( struct V_120 * V_184 , struct V_42 * V_43 )
{
int V_25 ;
F_47 ( & V_83 ) ;
V_25 = F_258 ( V_184 , V_43 ) ;
if ( V_25 )
goto V_266;
F_219 ( & V_214 ) ;
F_238 ( V_43 ) ;
F_220 ( & V_214 ) ;
V_266:
F_54 ( & V_83 ) ;
return V_25 ;
}
static T_7 int
F_260 ( struct V_120 * V_184 , struct V_42 * V_43 )
{
int V_25 ;
F_47 ( & V_83 ) ;
V_25 = F_258 ( V_184 , V_43 ) ;
if ( V_25 )
goto V_266;
F_219 ( & V_214 ) ;
F_253 ( V_43 ) ;
F_220 ( & V_214 ) ;
V_266:
F_54 ( & V_83 ) ;
return V_25 ;
}
int F_261 ( struct V_42 * V_43 )
{
F_47 ( & V_83 ) ;
F_262 ( V_43 ) ;
F_82 ( V_43 ) ;
F_111 ( V_43 , NULL , NULL , NULL , 0 ) ;
F_92 () ;
F_219 ( & V_214 ) ;
F_255 ( V_43 ) ;
F_104 ( V_43 -> V_217 ) ;
F_220 ( & V_214 ) ;
V_43 -> V_217 = NULL ;
F_54 ( & V_83 ) ;
return 0 ;
}
static T_7 int F_263 ( void )
{
V_20 = F_264 ( V_9 , V_267 ) ;
V_124 = F_264 ( V_40 , V_267 ) ;
return 0 ;
}
static T_7 void
F_265 ( struct V_42 * V_43 , bool V_268 )
{
char * V_130 = V_256 ;
char * V_269 ;
int V_25 ;
while ( true ) {
V_269 = F_114 ( & V_130 , L_46 ) ;
if ( ! V_269 )
break;
if ( * V_269 ) {
if ( V_268 )
F_113 ( V_43 , V_269 , 0 ) ;
V_25 = F_113 ( V_43 , V_269 , 1 ) ;
if ( V_25 )
F_204 ( L_47 , V_269 ) ;
}
if ( V_130 )
* ( V_130 - 1 ) = ',' ;
}
}
static T_7 int F_266 ( void )
{
struct V_42 * V_43 = F_116 () ;
struct V_4 * * V_61 , * V_13 ;
int V_25 ;
if ( ! V_43 )
return - V_39 ;
F_234 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_13 = * V_61 ;
V_25 = F_214 ( V_13 ) ;
if ( ! V_25 )
F_11 ( & V_13 -> V_114 , & V_201 ) ;
}
F_254 ( V_43 ) ;
F_265 ( V_43 , false ) ;
F_267 () ;
F_250 () ;
F_268 () ;
return 0 ;
}
static T_7 int F_269 ( void )
{
struct V_42 * V_43 ;
V_43 = F_116 () ;
if ( ! V_43 )
return - V_39 ;
F_265 ( V_43 , true ) ;
return 0 ;
}
static T_7 int F_270 ( void )
{
struct V_42 * V_43 ;
struct V_120 * V_270 ;
struct V_120 * V_58 ;
int V_25 ;
V_43 = F_116 () ;
if ( ! V_43 )
return - V_39 ;
V_270 = F_271 () ;
if ( F_165 ( V_270 ) )
return 0 ;
V_58 = F_205 ( L_48 , 0444 , V_270 ,
V_43 , & V_271 ) ;
if ( ! V_58 )
F_204 ( L_49 ) ;
if ( F_14 () )
F_204 ( L_50 ) ;
if ( F_16 () )
F_204 ( L_51 ) ;
V_25 = F_260 ( V_270 , V_43 ) ;
if ( V_25 )
return V_25 ;
#ifdef F_272
V_25 = F_273 ( & V_272 ) ;
if ( V_25 )
F_204 ( L_52 ) ;
#endif
return 0 ;
}
void T_7 F_274 ( void )
{
F_263 () ;
F_275 () ;
F_266 () ;
}
static T_7 void F_276 ( struct V_273 * V_274 )
{
F_106 ( & V_275 ) ;
F_277 ( & V_276 ) ;
F_278 ( 1 ) ;
F_279 ( & V_276 ) ;
F_109 ( & V_275 ) ;
F_47 ( & V_277 ) ;
F_280 ( 1 ) ;
F_54 ( & V_277 ) ;
}
static T_7 int F_281 ( void * V_278 )
{
void * V_279 ;
V_279 = F_160 ( 1234 , V_166 ) ;
if ( ! V_279 )
F_58 ( L_53 ) ;
F_282 ( F_276 ) ;
F_94 ( V_279 ) ;
F_283 ( V_280 ) ;
while ( ! F_284 () ) {
F_285 () ;
F_283 ( V_280 ) ;
}
F_286 ( V_281 ) ;
return 0 ;
}
static T_7 void F_287 ( void )
{
struct V_103 * V_282 ;
V_282 = F_288 ( F_281 , NULL , L_54 ) ;
F_280 ( 1 ) ;
F_289 ( V_282 ) ;
}
static T_7 void F_290 ( void )
{
struct V_116 * V_117 ;
struct V_40 * V_69 ;
struct V_4 * V_13 ;
struct V_1 * system ;
struct V_42 * V_43 ;
int V_25 ;
V_43 = F_116 () ;
if ( ! V_43 )
return;
F_58 ( L_55 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_69 -> V_5 ;
if ( ! V_13 -> V_6 || ! V_13 -> V_6 -> V_73 )
continue;
#ifndef F_291
if ( V_13 -> V_6 -> system &&
strcmp ( V_13 -> V_6 -> system , L_56 ) == 0 )
continue;
#endif
F_58 ( L_57 , F_59 ( V_13 ) ) ;
if ( V_69 -> V_54 & V_84 ) {
F_204 ( L_58 ) ;
F_97 ( 1 ) ;
continue;
}
F_63 ( V_69 , 1 ) ;
F_287 () ;
F_63 ( V_69 , 0 ) ;
F_292 ( L_59 ) ;
}
F_58 ( L_60 ) ;
F_6 (dir, &tr->systems, list) {
system = V_117 -> V_118 ;
if ( strcmp ( system -> V_11 , L_61 ) == 0 )
continue;
F_58 ( L_62 , system -> V_11 ) ;
V_25 = F_112 ( V_43 , NULL , system -> V_11 , NULL , 1 ) ;
if ( F_97 ( V_25 ) ) {
F_204 ( L_63 ,
system -> V_11 ) ;
continue;
}
F_287 () ;
V_25 = F_112 ( V_43 , NULL , system -> V_11 , NULL , 0 ) ;
if ( F_97 ( V_25 ) ) {
F_204 ( L_64 ,
system -> V_11 ) ;
continue;
}
F_292 ( L_59 ) ;
}
F_58 ( L_65 ) ;
F_58 ( L_66 ) ;
V_25 = F_112 ( V_43 , NULL , NULL , NULL , 1 ) ;
if ( F_97 ( V_25 ) ) {
F_204 ( L_67 ) ;
return;
}
F_287 () ;
V_25 = F_112 ( V_43 , NULL , NULL , NULL , 0 ) ;
if ( F_97 ( V_25 ) ) {
F_204 ( L_68 ) ;
return;
}
F_292 ( L_59 ) ;
}
static void T_7
F_293 ( unsigned long V_228 , unsigned long V_229 ,
struct V_283 * V_284 , struct V_285 * V_285 )
{
struct V_286 * V_38 ;
struct V_287 * V_57 ;
struct V_288 * V_58 ;
unsigned long V_54 ;
long V_289 ;
int V_28 ;
int V_56 ;
V_56 = F_31 () ;
F_294 () ;
V_28 = F_295 () ;
V_289 = F_57 ( & F_296 ( V_290 , V_28 ) ) ;
if ( V_289 != 1 )
goto V_153;
F_30 ( V_54 ) ;
V_38 = F_32 ( & V_57 , & V_291 ,
V_292 , sizeof( * V_58 ) ,
V_54 , V_56 ) ;
if ( ! V_38 )
goto V_153;
V_58 = F_33 ( V_38 ) ;
V_58 -> V_228 = V_228 ;
V_58 -> V_229 = V_229 ;
F_41 ( & V_291 , V_57 , V_38 ,
V_58 , V_54 , V_56 ) ;
V_153:
F_297 ( & F_296 ( V_290 , V_28 ) ) ;
F_298 () ;
}
static T_7 void F_299 ( void )
{
int V_25 ;
V_291 . V_43 = F_116 () ;
if ( F_13 ( ! V_291 . V_43 ) )
return;
V_25 = F_300 ( & V_293 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_58 ( L_69 ) ;
return;
}
F_58 ( L_70 ) ;
F_290 () ;
F_301 ( & V_293 ) ;
}
static T_7 void F_299 ( void )
{
}
static T_7 int F_302 ( void )
{
if ( ! V_259 ) {
F_290 () ;
F_299 () ;
}
return 0 ;
}
