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
static void F_35 ( struct V_51 * V_52 )
{
struct V_4 * V_5 ;
struct V_60 * V_38 ;
unsigned long V_54 ;
struct V_61 * V_62 = V_63 ;
if ( ! V_62 )
return;
V_5 = V_52 -> V_41 -> V_5 ;
if ( ! V_5 || ! V_5 -> V_38 . V_64 ||
! V_5 -> V_38 . V_64 -> V_65 )
return;
V_38 = & V_52 -> V_41 -> V_5 -> V_38 ;
F_36 ( & V_66 , V_54 ) ;
F_37 ( & V_62 -> V_67 ) ;
V_62 -> V_33 = V_52 -> V_59 ;
V_5 -> V_38 . V_64 -> V_65 ( V_62 , 0 , V_38 ) ;
F_38 ( & V_62 -> V_67 , 0 ) ;
F_39 ( L_1 , V_62 -> V_67 . V_58 ) ;
F_40 ( & V_66 , V_54 ) ;
}
void F_41 ( struct V_51 * V_52 )
{
if ( V_68 )
F_35 ( V_52 ) ;
F_42 ( V_52 -> V_41 , V_52 -> V_58 ,
V_52 -> V_38 , V_52 -> V_59 ,
V_52 -> V_54 , V_52 -> V_56 ) ;
}
int F_43 ( struct V_4 * V_13 ,
enum V_69 type , void * V_45 )
{
struct V_40 * V_70 = V_45 ;
F_13 ( ! ( V_13 -> V_54 & V_71 ) ) ;
switch ( type ) {
case V_72 :
return F_44 ( V_13 -> V_73 ,
V_13 -> V_6 -> V_74 ,
V_70 ) ;
case V_75 :
F_45 ( V_13 -> V_73 ,
V_13 -> V_6 -> V_74 ,
V_70 ) ;
return 0 ;
#ifdef F_46
case V_76 :
return F_44 ( V_13 -> V_73 ,
V_13 -> V_6 -> V_77 ,
V_13 ) ;
case V_78 :
F_45 ( V_13 -> V_73 ,
V_13 -> V_6 -> V_77 ,
V_13 ) ;
return 0 ;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
return 0 ;
#endif
}
return 0 ;
}
void F_47 ( bool V_83 )
{
struct V_40 * V_70 ;
struct V_42 * V_43 ;
F_48 ( & V_84 ) ;
F_49 (tr, file) {
if ( ! ( V_70 -> V_54 & V_85 ) )
continue;
if ( V_83 ) {
F_50 () ;
F_51 ( V_86 , & V_70 -> V_54 ) ;
} else {
F_52 () ;
F_53 ( V_86 , & V_70 -> V_54 ) ;
}
} F_54 () ;
F_55 ( & V_84 ) ;
}
static int F_56 ( struct V_40 * V_70 ,
int V_83 , int V_87 )
{
struct V_4 * V_13 = V_70 -> V_5 ;
struct V_42 * V_43 = V_70 -> V_43 ;
unsigned long V_88 = V_70 -> V_54 ;
int V_25 = 0 ;
int V_89 ;
switch ( V_83 ) {
case 0 :
if ( V_87 ) {
if ( F_57 ( & V_70 -> V_90 ) > 0 )
break;
V_89 = V_70 -> V_54 & V_91 ;
F_53 ( V_92 , & V_70 -> V_54 ) ;
} else
V_89 = ! ( V_70 -> V_54 & V_93 ) ;
if ( V_89 && ( V_70 -> V_54 & V_85 ) ) {
F_53 ( V_94 , & V_70 -> V_54 ) ;
if ( V_70 -> V_54 & V_95 ) {
F_52 () ;
F_53 ( V_86 , & V_70 -> V_54 ) ;
}
V_13 -> V_6 -> V_96 ( V_13 , V_75 , V_70 ) ;
}
if ( V_70 -> V_54 & V_93 )
F_51 ( V_97 , & V_70 -> V_54 ) ;
else
F_53 ( V_97 , & V_70 -> V_54 ) ;
break;
case 1 :
if ( ! V_87 )
F_53 ( V_97 , & V_70 -> V_54 ) ;
else {
if ( F_58 ( & V_70 -> V_90 ) > 1 )
break;
F_51 ( V_92 , & V_70 -> V_54 ) ;
}
if ( ! ( V_70 -> V_54 & V_85 ) ) {
if ( V_87 )
F_51 ( V_97 , & V_70 -> V_54 ) ;
if ( V_43 -> V_98 & V_99 ) {
F_50 () ;
F_51 ( V_86 , & V_70 -> V_54 ) ;
}
V_25 = V_13 -> V_6 -> V_96 ( V_13 , V_72 , V_70 ) ;
if ( V_25 ) {
F_52 () ;
F_59 ( L_2
L_3 , F_60 ( V_13 ) ) ;
break;
}
F_51 ( V_94 , & V_70 -> V_54 ) ;
V_13 -> V_54 |= V_100 ;
}
break;
}
if ( ( V_88 & V_91 ) !=
( V_70 -> V_54 & V_91 ) ) {
if ( V_70 -> V_54 & V_91 )
F_61 () ;
else
F_62 () ;
}
return V_25 ;
}
int F_63 ( struct V_40 * V_70 ,
int V_83 , int V_87 )
{
return F_56 ( V_70 , V_83 , V_87 ) ;
}
static int F_64 ( struct V_40 * V_70 ,
int V_83 )
{
return F_56 ( V_70 , V_83 , 0 ) ;
}
static void F_65 ( struct V_42 * V_43 )
{
struct V_40 * V_70 ;
F_48 ( & V_84 ) ;
F_6 (file, &tr->events, list) {
F_64 ( V_70 , 0 ) ;
}
F_55 ( & V_84 ) ;
}
static void
F_66 ( void * V_45 , struct V_101 * V_102 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_45 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_67 ( V_47 , NULL , V_102 ) ;
}
static void
F_68 ( void * V_45 ,
struct V_101 * V_103 ,
struct V_101 * V_102 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_45 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_67 ( V_47 , V_103 , V_102 ) ;
}
void F_69 ( struct V_42 * V_43 , bool V_83 )
{
if ( V_83 ) {
F_70 ( F_68 ,
V_43 , V_104 ) ;
F_71 ( F_66 ,
V_43 , V_105 ) ;
} else {
F_72 ( F_68 ,
V_43 ) ;
F_73 ( F_66 ,
V_43 ) ;
}
}
static void
F_74 ( void * V_45 , bool V_106 ,
struct V_101 * V_107 , struct V_101 * V_35 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_75 ( V_43 -> V_49 . V_45 -> V_50 ,
F_76 ( V_47 , V_107 ) &&
F_76 ( V_47 , V_35 ) ) ;
}
static void
F_77 ( void * V_45 , bool V_106 ,
struct V_101 * V_107 , struct V_101 * V_35 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_75 ( V_43 -> V_49 . V_45 -> V_50 ,
F_76 ( V_47 , V_35 ) ) ;
}
static void
F_78 ( void * V_45 , struct V_101 * V_102 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
if ( ! F_79 ( V_43 -> V_49 . V_45 -> V_50 ) )
return;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_75 ( V_43 -> V_49 . V_45 -> V_50 ,
F_76 ( V_47 , V_102 ) ) ;
}
static void
F_80 ( void * V_45 , struct V_101 * V_102 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
if ( F_79 ( V_43 -> V_49 . V_45 -> V_50 ) )
return;
V_47 = F_27 ( V_43 -> V_48 ) ;
F_75 ( V_43 -> V_49 . V_45 -> V_50 ,
F_76 ( V_47 , V_108 ) ) ;
}
static void F_81 ( struct V_42 * V_43 )
{
struct V_46 * V_47 ;
struct V_40 * V_70 ;
int V_28 ;
V_47 = F_82 ( V_43 -> V_48 ,
F_83 ( & V_84 ) ) ;
if ( ! V_47 )
return;
F_84 ( F_74 , V_43 ) ;
F_84 ( F_77 , V_43 ) ;
F_85 ( F_78 , V_43 ) ;
F_85 ( F_80 , V_43 ) ;
F_86 ( F_78 , V_43 ) ;
F_86 ( F_80 , V_43 ) ;
F_87 ( F_78 , V_43 ) ;
F_87 ( F_80 , V_43 ) ;
F_6 (file, &tr->events, list) {
F_53 ( V_109 , & V_70 -> V_54 ) ;
}
F_88 (cpu)
F_89 ( V_43 -> V_49 . V_45 , V_28 ) -> V_50 = false ;
F_90 ( V_43 -> V_48 , NULL ) ;
F_91 () ;
F_92 ( V_47 ) ;
}
static void F_93 ( struct V_42 * V_43 )
{
F_48 ( & V_84 ) ;
F_81 ( V_43 ) ;
F_55 ( & V_84 ) ;
}
static void F_94 ( struct V_1 * system )
{
struct V_110 * V_111 = system -> V_111 ;
F_95 ( F_1 ( system ) == 0 ) ;
if ( F_3 ( system ) )
return;
F_20 ( & system -> V_112 ) ;
if ( V_111 ) {
F_96 ( V_111 -> V_113 ) ;
F_96 ( V_111 ) ;
}
F_97 ( system -> V_11 ) ;
F_96 ( system ) ;
}
static void F_98 ( struct V_1 * system )
{
F_95 ( F_1 ( system ) == 0 ) ;
F_2 ( system ) ;
}
static void F_99 ( struct V_114 * V_115 )
{
F_95 ( V_115 -> V_2 == 0 ) ;
V_115 -> V_2 ++ ;
F_98 ( V_115 -> V_116 ) ;
}
static void F_100 ( struct V_114 * V_115 )
{
F_95 ( V_115 -> V_2 == 0 ) ;
F_95 ( F_1 ( V_115 -> V_116 ) == 1 && V_115 -> V_2 != 1 ) ;
F_94 ( V_115 -> V_116 ) ;
if ( ! -- V_115 -> V_2 )
F_96 ( V_115 ) ;
}
static void F_101 ( struct V_114 * V_115 )
{
F_48 ( & V_84 ) ;
F_100 ( V_115 ) ;
F_55 ( & V_84 ) ;
}
static void F_102 ( struct V_114 * V_115 )
{
if ( ! V_115 )
return;
if ( ! -- V_115 -> V_117 ) {
F_103 ( V_115 -> V_59 ) ;
F_20 ( & V_115 -> V_112 ) ;
F_100 ( V_115 ) ;
}
}
static void F_104 ( struct V_40 * V_70 )
{
struct V_118 * V_115 = V_70 -> V_115 ;
struct V_118 * V_119 ;
if ( V_115 ) {
F_105 ( & V_115 -> V_120 ) ;
F_6 (child, &dir->d_subdirs, d_child) {
if ( F_106 ( V_119 ) )
F_107 ( V_119 ) -> V_121 = NULL ;
}
F_108 ( & V_115 -> V_120 ) ;
F_103 ( V_115 ) ;
}
F_20 ( & V_70 -> V_112 ) ;
F_102 ( V_70 -> system ) ;
F_109 ( V_70 -> V_111 ) ;
F_21 ( V_122 , V_70 ) ;
}
static int
F_110 ( struct V_42 * V_43 , const char * V_123 ,
const char * V_124 , const char * V_38 , int V_125 )
{
struct V_40 * V_70 ;
struct V_4 * V_13 ;
const char * V_11 ;
int V_25 = - V_126 ;
F_6 (file, &tr->events, list) {
V_13 = V_70 -> V_5 ;
V_11 = F_60 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_96 )
continue;
if ( V_13 -> V_54 & V_127 )
continue;
if ( V_123 &&
strcmp ( V_123 , V_11 ) != 0 &&
strcmp ( V_123 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_124 && strcmp ( V_124 , V_13 -> V_6 -> system ) != 0 )
continue;
if ( V_38 && strcmp ( V_38 , V_11 ) != 0 )
continue;
F_64 ( V_70 , V_125 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static int F_111 ( struct V_42 * V_43 , const char * V_123 ,
const char * V_124 , const char * V_38 , int V_125 )
{
int V_25 ;
F_48 ( & V_84 ) ;
V_25 = F_110 ( V_43 , V_123 , V_124 , V_38 , V_125 ) ;
F_55 ( & V_84 ) ;
return V_25 ;
}
static int F_112 ( struct V_42 * V_43 , char * V_128 , int V_125 )
{
char * V_38 = NULL , * V_124 = NULL , * V_123 ;
int V_25 ;
V_123 = F_113 ( & V_128 , L_4 ) ;
if ( V_128 ) {
V_124 = V_123 ;
V_38 = V_128 ;
V_123 = NULL ;
if ( ! strlen ( V_124 ) || strcmp ( V_124 , L_5 ) == 0 )
V_124 = NULL ;
if ( ! strlen ( V_38 ) || strcmp ( V_38 , L_5 ) == 0 )
V_38 = NULL ;
}
V_25 = F_111 ( V_43 , V_123 , V_124 , V_38 , V_125 ) ;
if ( V_128 )
* ( V_128 - 1 ) = ':' ;
return V_25 ;
}
int F_114 ( const char * system , const char * V_38 , int V_125 )
{
struct V_42 * V_43 = F_115 () ;
if ( ! V_43 )
return - V_39 ;
return F_111 ( V_43 , NULL , system , V_38 , V_125 ) ;
}
static T_1
F_116 ( struct V_70 * V_70 , const char T_2 * V_129 ,
T_3 V_130 , T_4 * V_131 )
{
struct V_132 V_133 ;
struct V_134 * V_135 = V_70 -> V_136 ;
struct V_42 * V_43 = V_135 -> V_137 ;
T_1 V_138 , V_25 ;
if ( ! V_130 )
return 0 ;
V_25 = F_117 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_118 ( & V_133 , V_139 + 1 ) )
return - V_22 ;
V_138 = F_119 ( & V_133 , V_129 , V_130 , V_131 ) ;
if ( V_138 >= 0 && F_120 ( ( & V_133 ) ) ) {
int V_125 = 1 ;
if ( * V_133 . V_58 == '!' )
V_125 = 0 ;
V_133 . V_58 [ V_133 . V_140 ] = 0 ;
V_25 = F_112 ( V_43 , V_133 . V_58 + ! V_125 , V_125 ) ;
if ( V_25 )
goto V_141;
}
V_25 = V_138 ;
V_141:
F_121 ( & V_133 ) ;
return V_25 ;
}
static void *
F_122 ( struct V_134 * V_135 , void * V_142 , T_4 * V_143 )
{
struct V_40 * V_70 = V_142 ;
struct V_4 * V_13 ;
struct V_42 * V_43 = V_135 -> V_137 ;
( * V_143 ) ++ ;
F_123 (file, &tr->events, list) {
V_13 = V_70 -> V_5 ;
if ( V_13 -> V_6 && V_13 -> V_6 -> V_96 &&
! ( V_13 -> V_54 & V_127 ) )
return V_70 ;
}
return NULL ;
}
static void * F_124 ( struct V_134 * V_135 , T_4 * V_143 )
{
struct V_40 * V_70 ;
struct V_42 * V_43 = V_135 -> V_137 ;
T_4 V_144 ;
F_48 ( & V_84 ) ;
V_70 = F_125 ( & V_43 -> V_145 , struct V_40 , V_112 ) ;
for ( V_144 = 0 ; V_144 <= * V_143 ; ) {
V_70 = F_122 ( V_135 , V_70 , & V_144 ) ;
if ( ! V_70 )
break;
}
return V_70 ;
}
static void *
F_126 ( struct V_134 * V_135 , void * V_142 , T_4 * V_143 )
{
struct V_40 * V_70 = V_142 ;
struct V_42 * V_43 = V_135 -> V_137 ;
( * V_143 ) ++ ;
F_123 (file, &tr->events, list) {
if ( V_70 -> V_54 & V_85 )
return V_70 ;
}
return NULL ;
}
static void * F_127 ( struct V_134 * V_135 , T_4 * V_143 )
{
struct V_40 * V_70 ;
struct V_42 * V_43 = V_135 -> V_137 ;
T_4 V_144 ;
F_48 ( & V_84 ) ;
V_70 = F_125 ( & V_43 -> V_145 , struct V_40 , V_112 ) ;
for ( V_144 = 0 ; V_144 <= * V_143 ; ) {
V_70 = F_126 ( V_135 , V_70 , & V_144 ) ;
if ( ! V_70 )
break;
}
return V_70 ;
}
static int F_128 ( struct V_134 * V_135 , void * V_142 )
{
struct V_40 * V_70 = V_142 ;
struct V_4 * V_13 = V_70 -> V_5 ;
if ( strcmp ( V_13 -> V_6 -> system , V_146 ) != 0 )
F_129 ( V_135 , L_6 , V_13 -> V_6 -> system ) ;
F_129 ( V_135 , L_3 , F_60 ( V_13 ) ) ;
return 0 ;
}
static void F_130 ( struct V_134 * V_135 , void * V_147 )
{
F_55 ( & V_84 ) ;
}
static void *
F_131 ( struct V_134 * V_135 , void * V_142 , T_4 * V_143 )
{
struct V_42 * V_43 = V_135 -> V_137 ;
struct V_46 * V_47 = F_27 ( V_43 -> V_48 ) ;
return F_132 ( V_47 , V_142 , V_143 ) ;
}
static void * F_133 ( struct V_134 * V_135 , T_4 * V_143 )
__acquires( T_5 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 = V_135 -> V_137 ;
F_48 ( & V_84 ) ;
F_134 () ;
V_47 = F_27 ( V_43 -> V_48 ) ;
if ( ! V_47 )
return NULL ;
return F_135 ( V_47 , V_143 ) ;
}
static void F_136 ( struct V_134 * V_135 , void * V_147 )
__releases( T_5 )
{
F_137 () ;
F_55 ( & V_84 ) ;
}
static T_1
F_138 ( struct V_70 * V_148 , char T_2 * V_129 , T_3 V_130 ,
T_4 * V_131 )
{
struct V_40 * V_70 ;
unsigned long V_54 ;
char V_128 [ 4 ] = L_7 ;
F_48 ( & V_84 ) ;
V_70 = F_139 ( V_148 ) ;
if ( F_140 ( V_70 ) )
V_54 = V_70 -> V_54 ;
F_55 ( & V_84 ) ;
if ( ! V_70 )
return - V_39 ;
if ( V_54 & V_85 &&
! ( V_54 & V_91 ) )
strcpy ( V_128 , L_8 ) ;
if ( V_54 & V_91 ||
V_54 & V_93 )
strcat ( V_128 , L_5 ) ;
strcat ( V_128 , L_9 ) ;
return F_141 ( V_129 , V_130 , V_131 , V_128 , strlen ( V_128 ) ) ;
}
static T_1
F_142 ( struct V_70 * V_148 , const char T_2 * V_129 , T_3 V_130 ,
T_4 * V_131 )
{
struct V_40 * V_70 ;
unsigned long V_149 ;
int V_25 ;
V_25 = F_143 ( V_129 , V_130 , 10 , & V_149 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_117 () ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_149 ) {
case 0 :
case 1 :
V_25 = - V_39 ;
F_48 ( & V_84 ) ;
V_70 = F_139 ( V_148 ) ;
if ( F_140 ( V_70 ) )
V_25 = F_64 ( V_70 , V_149 ) ;
F_55 ( & V_84 ) ;
break;
default:
return - V_126 ;
}
* V_131 += V_130 ;
return V_25 ? V_25 : V_130 ;
}
static T_1
F_144 ( struct V_70 * V_148 , char T_2 * V_129 , T_3 V_130 ,
T_4 * V_131 )
{
const char V_150 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_114 * V_115 = V_148 -> V_136 ;
struct V_1 * system = V_115 -> V_116 ;
struct V_4 * V_13 ;
struct V_40 * V_70 ;
struct V_42 * V_43 = V_115 -> V_43 ;
char V_128 [ 2 ] ;
int V_125 = 0 ;
int V_25 ;
F_48 ( & V_84 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_70 -> V_5 ;
if ( ! F_60 ( V_13 ) || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_96 )
continue;
if ( system && strcmp ( V_13 -> V_6 -> system , system -> V_11 ) != 0 )
continue;
V_125 |= ( 1 << ! ! ( V_70 -> V_54 & V_85 ) ) ;
if ( V_125 == 3 )
break;
}
F_55 ( & V_84 ) ;
V_128 [ 0 ] = V_150 [ V_125 ] ;
V_128 [ 1 ] = '\n' ;
V_25 = F_141 ( V_129 , V_130 , V_131 , V_128 , 2 ) ;
return V_25 ;
}
static T_1
F_145 ( struct V_70 * V_148 , const char T_2 * V_129 , T_3 V_130 ,
T_4 * V_131 )
{
struct V_114 * V_115 = V_148 -> V_136 ;
struct V_1 * system = V_115 -> V_116 ;
const char * V_11 = NULL ;
unsigned long V_149 ;
T_1 V_25 ;
V_25 = F_143 ( V_129 , V_130 , 10 , & V_149 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_117 () ;
if ( V_25 < 0 )
return V_25 ;
if ( V_149 != 0 && V_149 != 1 )
return - V_126 ;
if ( system )
V_11 = system -> V_11 ;
V_25 = F_111 ( V_115 -> V_43 , NULL , V_11 , NULL , V_149 ) ;
if ( V_25 )
goto V_151;
V_25 = V_130 ;
V_151:
* V_131 += V_130 ;
return V_25 ;
}
static void * F_146 ( struct V_134 * V_135 , void * V_142 , T_4 * V_143 )
{
struct V_4 * V_13 = F_139 ( V_135 -> V_137 ) ;
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
V_153 = V_153 -> V_107 ;
if ( V_153 == V_152 )
return ( void * ) V_155 ;
else if ( V_153 == V_10 )
return ( void * ) V_156 ;
else
return V_153 ;
}
static int F_147 ( struct V_134 * V_135 , void * V_142 )
{
struct V_4 * V_13 = F_139 ( V_135 -> V_137 ) ;
struct V_9 * V_12 ;
const char * V_157 ;
switch ( ( unsigned long ) V_142 ) {
case V_154 :
F_129 ( V_135 , L_10 , F_60 ( V_13 ) ) ;
F_129 ( V_135 , L_11 , V_13 -> V_38 . type ) ;
F_148 ( V_135 , L_12 ) ;
return 0 ;
case V_155 :
F_149 ( V_135 , '\n' ) ;
return 0 ;
case V_156 :
F_129 ( V_135 , L_13 ,
V_13 -> V_158 ) ;
return 0 ;
}
V_12 = F_125 ( V_142 , struct V_9 , V_24 ) ;
V_157 = strchr ( V_12 -> type , '[' ) ;
if ( ! strncmp ( V_12 -> type , L_14 , 10 ) )
V_157 = NULL ;
if ( ! V_157 )
F_129 ( V_135 , L_15 ,
V_12 -> type , V_12 -> V_11 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
else
F_129 ( V_135 , L_16 ,
( int ) ( V_157 - V_12 -> type ) ,
V_12 -> type , V_12 -> V_11 ,
V_157 , V_12 -> V_16 ,
V_12 -> V_17 , ! ! V_12 -> V_18 ) ;
return 0 ;
}
static void * F_150 ( struct V_134 * V_135 , T_4 * V_143 )
{
void * V_147 = ( void * ) V_154 ;
T_4 V_144 = 0 ;
F_48 ( & V_84 ) ;
if ( ! F_139 ( V_135 -> V_137 ) )
return F_151 ( - V_39 ) ;
while ( V_144 < * V_143 && V_147 )
V_147 = F_146 ( V_135 , V_147 , & V_144 ) ;
return V_147 ;
}
static void F_152 ( struct V_134 * V_135 , void * V_147 )
{
F_55 ( & V_84 ) ;
}
static int F_153 ( struct V_159 * V_159 , struct V_70 * V_70 )
{
struct V_134 * V_135 ;
int V_25 ;
V_25 = F_154 ( V_70 , & V_160 ) ;
if ( V_25 < 0 )
return V_25 ;
V_135 = V_70 -> V_136 ;
V_135 -> V_137 = V_70 ;
return 0 ;
}
static T_1
F_155 ( struct V_70 * V_148 , char T_2 * V_129 , T_3 V_130 , T_4 * V_131 )
{
int V_37 = ( long ) F_139 ( V_148 ) ;
char V_128 [ 32 ] ;
int V_53 ;
if ( * V_131 )
return 0 ;
if ( F_156 ( ! V_37 ) )
return - V_39 ;
V_53 = sprintf ( V_128 , L_17 , V_37 ) ;
return F_141 ( V_129 , V_130 , V_131 , V_128 , V_53 ) ;
}
static T_1
F_157 ( struct V_70 * V_148 , char T_2 * V_129 , T_3 V_130 ,
T_4 * V_131 )
{
struct V_40 * V_70 ;
struct V_161 * V_162 ;
int V_163 = - V_39 ;
if ( * V_131 )
return 0 ;
V_162 = F_158 ( sizeof( * V_162 ) , V_164 ) ;
if ( ! V_162 )
return - V_22 ;
F_37 ( V_162 ) ;
F_48 ( & V_84 ) ;
V_70 = F_139 ( V_148 ) ;
if ( V_70 )
F_159 ( V_70 , V_162 ) ;
F_55 ( & V_84 ) ;
if ( V_70 )
V_163 = F_141 ( V_129 , V_130 , V_131 ,
V_162 -> V_58 , F_160 ( V_162 ) ) ;
F_96 ( V_162 ) ;
return V_163 ;
}
static T_1
F_161 ( struct V_70 * V_148 , const char T_2 * V_129 , T_3 V_130 ,
T_4 * V_131 )
{
struct V_40 * V_70 ;
char * V_128 ;
int V_165 = - V_39 ;
if ( V_130 >= V_166 )
return - V_126 ;
V_128 = F_162 ( V_129 , V_130 ) ;
if ( F_163 ( V_128 ) )
return F_164 ( V_128 ) ;
F_48 ( & V_84 ) ;
V_70 = F_139 ( V_148 ) ;
if ( V_70 )
V_165 = F_165 ( V_70 , V_128 ) ;
F_55 ( & V_84 ) ;
F_96 ( V_128 ) ;
if ( V_165 < 0 )
return V_165 ;
* V_131 += V_130 ;
return V_130 ;
}
static int F_166 ( struct V_159 * V_159 , struct V_70 * V_148 )
{
struct V_1 * system = NULL ;
struct V_114 * V_115 = NULL ;
struct V_42 * V_43 ;
int V_25 ;
if ( F_167 () )
return - V_39 ;
F_48 ( & V_167 ) ;
F_48 ( & V_84 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_115 == V_159 -> V_121 ) {
if ( V_115 -> V_117 ) {
F_99 ( V_115 ) ;
system = V_115 -> V_116 ;
}
goto V_168;
}
}
}
V_168:
F_55 ( & V_84 ) ;
F_55 ( & V_167 ) ;
if ( ! system )
return - V_39 ;
F_13 ( ! V_115 ) ;
if ( F_168 ( V_43 ) < 0 ) {
F_101 ( V_115 ) ;
return - V_39 ;
}
V_25 = F_169 ( V_159 , V_148 ) ;
if ( V_25 < 0 ) {
F_170 ( V_43 ) ;
F_101 ( V_115 ) ;
}
return V_25 ;
}
static int F_171 ( struct V_159 * V_159 , struct V_70 * V_148 )
{
struct V_114 * V_115 ;
struct V_42 * V_43 = V_159 -> V_121 ;
int V_25 ;
if ( F_167 () )
return - V_39 ;
if ( F_168 ( V_43 ) < 0 )
return - V_39 ;
V_115 = F_172 ( sizeof( * V_115 ) , V_164 ) ;
if ( ! V_115 ) {
F_170 ( V_43 ) ;
return - V_22 ;
}
V_115 -> V_43 = V_43 ;
V_25 = F_169 ( V_159 , V_148 ) ;
if ( V_25 < 0 ) {
F_170 ( V_43 ) ;
F_96 ( V_115 ) ;
return V_25 ;
}
V_148 -> V_136 = V_115 ;
return 0 ;
}
static int F_173 ( struct V_159 * V_159 , struct V_70 * V_70 )
{
struct V_114 * V_115 = V_70 -> V_136 ;
F_170 ( V_115 -> V_43 ) ;
if ( V_115 -> V_116 )
F_101 ( V_115 ) ;
else
F_96 ( V_115 ) ;
return 0 ;
}
static T_1
F_174 ( struct V_70 * V_148 , char T_2 * V_129 , T_3 V_130 ,
T_4 * V_131 )
{
struct V_114 * V_115 = V_148 -> V_136 ;
struct V_1 * system = V_115 -> V_116 ;
struct V_161 * V_162 ;
int V_163 ;
if ( * V_131 )
return 0 ;
V_162 = F_158 ( sizeof( * V_162 ) , V_164 ) ;
if ( ! V_162 )
return - V_22 ;
F_37 ( V_162 ) ;
F_175 ( system , V_162 ) ;
V_163 = F_141 ( V_129 , V_130 , V_131 ,
V_162 -> V_58 , F_160 ( V_162 ) ) ;
F_96 ( V_162 ) ;
return V_163 ;
}
static T_1
F_176 ( struct V_70 * V_148 , const char T_2 * V_129 , T_3 V_130 ,
T_4 * V_131 )
{
struct V_114 * V_115 = V_148 -> V_136 ;
char * V_128 ;
int V_165 ;
if ( V_130 >= V_166 )
return - V_126 ;
V_128 = F_162 ( V_129 , V_130 ) ;
if ( F_163 ( V_128 ) )
return F_164 ( V_128 ) ;
V_165 = F_177 ( V_115 , V_128 ) ;
F_96 ( V_128 ) ;
if ( V_165 < 0 )
return V_165 ;
* V_131 += V_130 ;
return V_130 ;
}
static T_1
F_178 ( struct V_70 * V_148 , char T_2 * V_129 , T_3 V_130 , T_4 * V_131 )
{
int (* F_179)( struct V_161 * V_162 ) = V_148 -> V_136 ;
struct V_161 * V_162 ;
int V_163 ;
if ( * V_131 )
return 0 ;
V_162 = F_158 ( sizeof( * V_162 ) , V_164 ) ;
if ( ! V_162 )
return - V_22 ;
F_37 ( V_162 ) ;
F_179 ( V_162 ) ;
V_163 = F_141 ( V_129 , V_130 , V_131 ,
V_162 -> V_58 , F_160 ( V_162 ) ) ;
F_96 ( V_162 ) ;
return V_163 ;
}
static void F_180 ( void * V_45 )
{
struct V_42 * V_43 = V_45 ;
struct V_46 * V_47 ;
V_47 = F_82 ( V_43 -> V_48 ,
F_181 ( & V_84 ) ) ;
F_75 ( V_43 -> V_49 . V_45 -> V_50 ,
F_76 ( V_47 , V_108 ) ) ;
}
static T_1
F_182 ( struct V_70 * V_148 , const char T_2 * V_129 ,
T_3 V_130 , T_4 * V_131 )
{
struct V_134 * V_135 = V_148 -> V_136 ;
struct V_42 * V_43 = V_135 -> V_137 ;
struct V_46 * V_48 = NULL ;
struct V_46 * V_47 ;
struct V_40 * V_70 ;
T_1 V_25 ;
if ( ! V_130 )
return 0 ;
V_25 = F_117 () ;
if ( V_25 < 0 )
return V_25 ;
F_48 ( & V_84 ) ;
V_48 = F_82 ( V_43 -> V_48 ,
F_83 ( & V_84 ) ) ;
V_25 = F_183 ( V_48 , & V_47 , V_129 , V_130 ) ;
if ( V_25 < 0 )
goto V_151;
F_90 ( V_43 -> V_48 , V_47 ) ;
F_6 (file, &tr->events, list) {
F_51 ( V_109 , & V_70 -> V_54 ) ;
}
if ( V_48 ) {
F_91 () ;
F_92 ( V_48 ) ;
} else if ( V_47 ) {
F_184 ( F_74 ,
V_43 , V_105 ) ;
F_184 ( F_77 ,
V_43 , 0 ) ;
F_185 ( F_78 ,
V_43 , V_105 ) ;
F_185 ( F_80 ,
V_43 , 0 ) ;
F_186 ( F_78 ,
V_43 , V_105 ) ;
F_186 ( F_80 ,
V_43 , 0 ) ;
F_187 ( F_78 ,
V_43 , V_105 ) ;
F_187 ( F_80 ,
V_43 , 0 ) ;
}
F_188 ( F_180 , V_43 , 1 ) ;
V_151:
F_55 ( & V_84 ) ;
if ( V_25 > 0 )
* V_131 += V_25 ;
return V_25 ;
}
static int
F_189 ( struct V_159 * V_159 , struct V_70 * V_70 ,
const struct V_169 * V_170 )
{
struct V_134 * V_135 ;
int V_25 ;
V_25 = F_154 ( V_70 , V_170 ) ;
if ( V_25 < 0 )
return V_25 ;
V_135 = V_70 -> V_136 ;
V_135 -> V_137 = V_159 -> V_121 ;
return V_25 ;
}
static int F_190 ( struct V_159 * V_159 , struct V_70 * V_70 )
{
struct V_42 * V_43 = V_159 -> V_121 ;
F_170 ( V_43 ) ;
return F_191 ( V_159 , V_70 ) ;
}
static int
F_192 ( struct V_159 * V_159 , struct V_70 * V_70 )
{
const struct V_169 * V_170 = & V_171 ;
return F_189 ( V_159 , V_70 , V_170 ) ;
}
static int
F_193 ( struct V_159 * V_159 , struct V_70 * V_70 )
{
const struct V_169 * V_170 = & V_172 ;
struct V_42 * V_43 = V_159 -> V_121 ;
int V_25 ;
if ( F_168 ( V_43 ) < 0 )
return - V_39 ;
if ( ( V_70 -> V_173 & V_174 ) &&
( V_70 -> V_175 & V_176 ) )
F_65 ( V_43 ) ;
V_25 = F_189 ( V_159 , V_70 , V_170 ) ;
if ( V_25 < 0 )
F_170 ( V_43 ) ;
return V_25 ;
}
static int
F_194 ( struct V_159 * V_159 , struct V_70 * V_70 )
{
const struct V_169 * V_170 = & V_177 ;
struct V_42 * V_43 = V_159 -> V_121 ;
int V_25 ;
if ( F_168 ( V_43 ) < 0 )
return - V_39 ;
if ( ( V_70 -> V_173 & V_174 ) &&
( V_70 -> V_175 & V_176 ) )
F_93 ( V_43 ) ;
V_25 = F_189 ( V_159 , V_70 , V_170 ) ;
if ( V_25 < 0 )
F_170 ( V_43 ) ;
return V_25 ;
}
static struct V_1 *
F_195 ( const char * V_11 )
{
struct V_1 * system ;
system = F_158 ( sizeof( * system ) , V_164 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
system -> V_11 = F_196 ( V_11 , V_164 ) ;
if ( ! system -> V_11 )
goto V_178;
system -> V_111 = NULL ;
system -> V_111 = F_172 ( sizeof( struct V_110 ) , V_164 ) ;
if ( ! system -> V_111 )
goto V_178;
F_11 ( & system -> V_112 , & V_179 ) ;
return system ;
V_178:
F_97 ( system -> V_11 ) ;
F_96 ( system ) ;
return NULL ;
}
static struct V_118 *
F_197 ( struct V_42 * V_43 , const char * V_11 ,
struct V_40 * V_70 , struct V_118 * V_180 )
{
struct V_114 * V_115 ;
struct V_1 * system ;
struct V_118 * V_59 ;
F_6 (dir, &tr->systems, list) {
system = V_115 -> V_116 ;
if ( strcmp ( system -> V_11 , V_11 ) == 0 ) {
V_115 -> V_117 ++ ;
V_70 -> system = V_115 ;
return V_115 -> V_59 ;
}
}
F_6 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_11 , V_11 ) == 0 )
break;
}
if ( & system -> V_112 == & V_179 )
system = NULL ;
V_115 = F_158 ( sizeof( * V_115 ) , V_164 ) ;
if ( ! V_115 )
goto V_181;
if ( ! system ) {
system = F_195 ( V_11 ) ;
if ( ! system )
goto V_178;
} else
F_98 ( system ) ;
V_115 -> V_59 = F_198 ( V_11 , V_180 ) ;
if ( ! V_115 -> V_59 ) {
F_199 ( L_18 , V_11 ) ;
F_94 ( system ) ;
goto V_178;
}
V_115 -> V_43 = V_43 ;
V_115 -> V_2 = 1 ;
V_115 -> V_117 = 1 ;
V_115 -> V_116 = system ;
V_70 -> system = V_115 ;
V_59 = F_200 ( L_19 , 0644 , V_115 -> V_59 , V_115 ,
& V_182 ) ;
if ( ! V_59 ) {
F_96 ( system -> V_111 ) ;
system -> V_111 = NULL ;
F_199 ( L_20 , V_11 ) ;
}
F_201 ( L_21 , 0644 , V_115 -> V_59 , V_115 ,
& V_183 ) ;
F_11 ( & V_115 -> V_112 , & V_43 -> V_184 ) ;
return V_115 -> V_59 ;
V_178:
F_96 ( V_115 ) ;
V_181:
if ( ! V_115 || ! system )
F_199 ( L_22 , V_11 ) ;
return NULL ;
}
static int
F_202 ( struct V_118 * V_180 , struct V_40 * V_70 )
{
struct V_4 * V_13 = V_70 -> V_5 ;
struct V_42 * V_43 = V_70 -> V_43 ;
struct V_3 * V_10 ;
struct V_118 * V_185 ;
const char * V_11 ;
int V_25 ;
if ( strcmp ( V_13 -> V_6 -> system , V_146 ) != 0 ) {
V_185 = F_197 ( V_43 , V_13 -> V_6 -> system , V_70 , V_180 ) ;
if ( ! V_185 )
return - V_22 ;
} else
V_185 = V_180 ;
V_11 = F_60 ( V_13 ) ;
V_70 -> V_115 = F_198 ( V_11 , V_185 ) ;
if ( ! V_70 -> V_115 ) {
F_199 ( L_23 , V_11 ) ;
return - 1 ;
}
if ( V_13 -> V_6 -> V_96 && ! ( V_13 -> V_54 & V_127 ) )
F_201 ( L_21 , 0644 , V_70 -> V_115 , V_70 ,
& V_186 ) ;
#ifdef F_46
if ( V_13 -> V_38 . type && V_13 -> V_6 -> V_96 )
F_201 ( L_24 , 0444 , V_70 -> V_115 ,
( void * ) ( long ) V_13 -> V_38 . type ,
& V_187 ) ;
#endif
V_10 = F_4 ( V_13 ) ;
if ( F_203 ( V_10 ) ) {
V_25 = V_13 -> V_6 -> V_188 ( V_13 ) ;
if ( V_25 < 0 ) {
F_199 ( L_25 ,
V_11 ) ;
return - 1 ;
}
}
F_201 ( L_19 , 0644 , V_70 -> V_115 , V_70 ,
& V_189 ) ;
if ( ! ( V_13 -> V_54 & V_127 ) )
F_201 ( L_26 , 0644 , V_70 -> V_115 , V_70 ,
& V_190 ) ;
#ifdef F_204
F_201 ( L_27 , 0444 , V_70 -> V_115 , V_70 ,
& V_191 ) ;
#endif
F_201 ( L_28 , 0444 , V_70 -> V_115 , V_13 ,
& V_192 ) ;
return 0 ;
}
static void F_205 ( struct V_4 * V_13 )
{
struct V_40 * V_70 ;
struct V_42 * V_43 ;
F_206 (tr, file) {
if ( V_70 -> V_5 != V_13 )
continue;
F_104 ( V_70 ) ;
break;
} F_54 () ;
}
static void F_207 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
struct V_40 * V_70 ;
F_49 (tr, file) {
if ( V_70 -> V_5 != V_13 )
continue;
F_64 ( V_70 , 0 ) ;
break;
} F_54 () ;
if ( V_13 -> V_38 . V_64 )
F_208 ( & V_13 -> V_38 ) ;
F_205 ( V_13 ) ;
F_20 ( & V_13 -> V_112 ) ;
}
static int F_209 ( struct V_4 * V_13 )
{
int V_25 = 0 ;
const char * V_11 ;
V_11 = F_60 ( V_13 ) ;
if ( F_13 ( ! V_11 ) )
return - V_126 ;
if ( V_13 -> V_6 -> V_193 ) {
V_25 = V_13 -> V_6 -> V_193 ( V_13 ) ;
if ( V_25 < 0 && V_25 != - V_194 )
F_199 ( L_29 , V_11 ) ;
}
return V_25 ;
}
static int
F_210 ( struct V_4 * V_13 , struct V_195 * V_196 )
{
int V_25 ;
V_25 = F_209 ( V_13 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_13 -> V_112 , & V_197 ) ;
V_13 -> V_196 = V_196 ;
return 0 ;
}
static char * F_211 ( char * V_198 , struct V_199 * V_200 , int V_53 )
{
int V_201 ;
int V_202 ;
V_202 = snprintf ( V_198 , 0 , L_30 , V_200 -> V_203 ) ;
if ( V_53 < V_202 )
return NULL ;
snprintf ( V_198 , V_202 + 1 , L_30 , V_200 -> V_203 ) ;
V_201 = strlen ( V_198 + V_53 ) ;
memmove ( V_198 + V_202 , V_198 + V_53 , V_201 ) ;
V_198 [ V_202 + V_201 ] = 0 ;
return V_198 + V_202 ;
}
static void F_212 ( struct V_4 * V_13 ,
struct V_199 * V_200 )
{
char * V_198 ;
int V_204 = 0 ;
int V_53 = strlen ( V_200 -> V_205 ) ;
for ( V_198 = V_13 -> V_158 ; * V_198 ; V_198 ++ ) {
if ( * V_198 == '\\' ) {
V_198 ++ ;
if ( ! * V_198 )
break;
continue;
}
if ( * V_198 == '"' ) {
V_204 ^= 1 ;
continue;
}
if ( V_204 )
continue;
if ( isdigit ( * V_198 ) ) {
do {
V_198 ++ ;
} while ( isalnum ( * V_198 ) );
if ( ! * V_198 )
break;
continue;
}
if ( isalpha ( * V_198 ) || * V_198 == '_' ) {
if ( strncmp ( V_200 -> V_205 , V_198 , V_53 ) == 0 &&
! isalnum ( V_198 [ V_53 ] ) && V_198 [ V_53 ] != '_' ) {
V_198 = F_211 ( V_198 , V_200 , V_53 ) ;
if ( F_95 ( ! V_198 ) )
return;
continue;
}
V_206:
do {
V_198 ++ ;
} while ( isalnum ( * V_198 ) || * V_198 == '_' );
if ( ! * V_198 )
break;
if ( * V_198 == '.' || ( V_198 [ 0 ] == '-' && V_198 [ 1 ] == '>' ) ) {
V_198 += * V_198 == '.' ? 1 : 2 ;
if ( ! * V_198 )
break;
goto V_206;
}
continue;
}
}
}
void F_213 ( struct V_199 * * V_200 , int V_53 )
{
struct V_4 * V_13 , * V_147 ;
const char * V_207 = NULL ;
int V_208 ;
int V_209 ;
F_214 ( & V_210 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( ! V_207 || V_13 -> V_6 -> system != V_207 ) {
V_208 = 0 ;
V_207 = V_13 -> V_6 -> system ;
}
for ( V_209 = V_208 ; V_209 < V_53 ; V_209 ++ ) {
if ( V_13 -> V_6 -> system == V_200 [ V_209 ] -> system ) {
if ( ! V_208 )
V_208 = V_209 ;
F_212 ( V_13 , V_200 [ V_209 ] ) ;
}
}
}
F_215 ( & V_210 ) ;
}
static struct V_40 *
F_216 ( struct V_4 * V_13 ,
struct V_42 * V_43 )
{
struct V_40 * V_70 ;
V_70 = F_9 ( V_122 , V_21 ) ;
if ( ! V_70 )
return NULL ;
V_70 -> V_5 = V_13 ;
V_70 -> V_43 = V_43 ;
F_217 ( & V_70 -> V_90 , 0 ) ;
F_217 ( & V_70 -> V_211 , 0 ) ;
F_218 ( & V_70 -> V_212 ) ;
F_11 ( & V_70 -> V_112 , & V_43 -> V_145 ) ;
return V_70 ;
}
static int
F_219 ( struct V_4 * V_13 , struct V_42 * V_43 )
{
struct V_40 * V_70 ;
V_70 = F_216 ( V_13 , V_43 ) ;
if ( ! V_70 )
return - V_22 ;
return F_202 ( V_43 -> V_213 , V_70 ) ;
}
static T_6 int
F_220 ( struct V_4 * V_13 ,
struct V_42 * V_43 )
{
struct V_40 * V_70 ;
V_70 = F_216 ( V_13 , V_43 ) ;
if ( ! V_70 )
return - V_22 ;
return 0 ;
}
int F_221 ( struct V_4 * V_13 )
{
int V_25 ;
F_48 ( & V_167 ) ;
F_48 ( & V_84 ) ;
V_25 = F_210 ( V_13 , NULL ) ;
if ( V_25 >= 0 )
F_222 ( V_13 ) ;
F_55 ( & V_84 ) ;
F_55 ( & V_167 ) ;
return V_25 ;
}
static void F_223 ( struct V_4 * V_13 )
{
F_207 ( V_13 ) ;
F_18 ( V_13 ) ;
F_109 ( V_13 -> V_111 ) ;
V_13 -> V_111 = NULL ;
}
static int F_224 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
struct V_40 * V_70 ;
#ifdef F_46
if ( V_13 -> V_214 )
return - V_215 ;
#endif
F_49 (tr, file) {
if ( V_70 -> V_5 != V_13 )
continue;
if ( V_70 -> V_54 & V_85 )
return - V_215 ;
break;
} F_54 () ;
F_223 ( V_13 ) ;
return 0 ;
}
int F_225 ( struct V_4 * V_13 )
{
int V_25 ;
F_48 ( & V_167 ) ;
F_48 ( & V_84 ) ;
F_214 ( & V_210 ) ;
V_25 = F_224 ( V_13 ) ;
F_215 ( & V_210 ) ;
F_55 ( & V_84 ) ;
F_55 ( & V_167 ) ;
return V_25 ;
}
static void F_226 ( struct V_195 * V_196 )
{
struct V_4 * * V_13 , * * V_216 , * * V_217 ;
if ( ! V_196 -> V_218 )
return;
if ( F_227 ( V_196 ) ) {
F_228 ( L_31 ,
V_196 -> V_11 ) ;
return;
}
V_216 = V_196 -> V_219 ;
V_217 = V_196 -> V_219 + V_196 -> V_218 ;
F_229 (call, start, end) {
F_210 ( * V_13 , V_196 ) ;
F_222 ( * V_13 ) ;
}
}
static void F_230 ( struct V_195 * V_196 )
{
struct V_4 * V_13 , * V_147 ;
bool V_220 = false ;
F_214 ( & V_210 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( V_13 -> V_196 == V_196 ) {
if ( V_13 -> V_54 & V_100 )
V_220 = true ;
F_223 ( V_13 ) ;
}
}
F_215 ( & V_210 ) ;
if ( V_220 )
F_231 () ;
}
static int F_232 ( struct V_221 * V_103 ,
unsigned long V_149 , void * V_45 )
{
struct V_195 * V_196 = V_45 ;
F_48 ( & V_167 ) ;
F_48 ( & V_84 ) ;
switch ( V_149 ) {
case V_222 :
F_226 ( V_196 ) ;
break;
case V_223 :
F_230 ( V_196 ) ;
break;
}
F_55 ( & V_84 ) ;
F_55 ( & V_167 ) ;
return 0 ;
}
static void
F_233 ( struct V_42 * V_43 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
V_25 = F_219 ( V_13 , V_43 ) ;
if ( V_25 < 0 )
F_199 ( L_32 ,
F_60 ( V_13 ) ) ;
}
}
struct V_40 *
F_234 ( struct V_42 * V_43 , const char * system , const char * V_38 )
{
struct V_40 * V_70 ;
struct V_4 * V_13 ;
const char * V_11 ;
F_6 (file, &tr->events, list) {
V_13 = V_70 -> V_5 ;
V_11 = F_60 ( V_13 ) ;
if ( ! V_11 || ! V_13 -> V_6 || ! V_13 -> V_6 -> V_96 )
continue;
if ( V_13 -> V_54 & V_127 )
continue;
if ( strcmp ( V_38 , V_11 ) == 0 &&
strcmp ( system , V_13 -> V_6 -> system ) == 0 )
return V_70 ;
}
return NULL ;
}
static void
F_235 ( unsigned long V_224 , unsigned long V_225 , void * * V_226 )
{
struct V_227 * * V_228 = (struct V_227 * * ) V_226 ;
struct V_227 * V_45 = * V_228 ;
if ( ! V_45 )
return;
if ( V_45 -> V_83 )
F_53 ( V_97 , & V_45 -> V_70 -> V_54 ) ;
else
F_51 ( V_97 , & V_45 -> V_70 -> V_54 ) ;
}
static void
F_236 ( unsigned long V_224 , unsigned long V_225 , void * * V_226 )
{
struct V_227 * * V_228 = (struct V_227 * * ) V_226 ;
struct V_227 * V_45 = * V_228 ;
if ( ! V_45 )
return;
if ( ! V_45 -> V_229 )
return;
if ( V_45 -> V_83 == ! ( V_45 -> V_70 -> V_54 & V_91 ) )
return;
if ( V_45 -> V_229 != - 1 )
( V_45 -> V_229 ) -- ;
F_235 ( V_224 , V_225 , V_226 ) ;
}
static int
F_237 ( struct V_134 * V_135 , unsigned long V_224 ,
struct V_230 * V_231 , void * V_226 )
{
struct V_227 * V_45 = V_226 ;
F_129 ( V_135 , L_33 , ( void * ) V_224 ) ;
F_129 ( V_135 , L_34 ,
V_45 -> V_83 ? V_232 : V_233 ,
V_45 -> V_70 -> V_5 -> V_6 -> system ,
F_60 ( V_45 -> V_70 -> V_5 ) ) ;
if ( V_45 -> V_229 == - 1 )
F_148 ( V_135 , L_35 ) ;
else
F_129 ( V_135 , L_36 , V_45 -> V_229 ) ;
return 0 ;
}
static int
F_238 ( struct V_230 * V_231 , unsigned long V_224 ,
void * * V_226 )
{
struct V_227 * * V_228 = (struct V_227 * * ) V_226 ;
struct V_227 * V_45 = * V_228 ;
V_45 -> V_234 ++ ;
return 0 ;
}
static void
F_239 ( struct V_230 * V_231 , unsigned long V_224 ,
void * * V_226 )
{
struct V_227 * * V_228 = (struct V_227 * * ) V_226 ;
struct V_227 * V_45 = * V_228 ;
if ( F_95 ( V_45 -> V_234 <= 0 ) )
return;
V_45 -> V_234 -- ;
if ( ! V_45 -> V_234 ) {
F_56 ( V_45 -> V_70 , 0 , 1 ) ;
F_240 ( V_45 -> V_70 -> V_5 -> V_196 ) ;
F_96 ( V_45 ) ;
}
* V_228 = NULL ;
}
static int
F_241 ( struct V_235 * V_236 ,
char * V_237 , char * V_238 , char * V_239 , int V_240 )
{
struct V_42 * V_43 = F_115 () ;
struct V_40 * V_70 ;
struct V_230 * V_231 ;
struct V_227 * V_45 ;
const char * system ;
const char * V_38 ;
char * V_241 ;
bool V_83 ;
int V_25 ;
if ( ! V_43 )
return - V_39 ;
if ( ! V_240 || ! V_239 )
return - V_126 ;
system = F_113 ( & V_239 , L_4 ) ;
if ( ! V_239 )
return - V_126 ;
V_38 = F_113 ( & V_239 , L_4 ) ;
F_48 ( & V_84 ) ;
V_25 = - V_126 ;
V_70 = F_234 ( V_43 , system , V_38 ) ;
if ( ! V_70 )
goto V_151;
V_83 = strcmp ( V_238 , V_232 ) == 0 ;
if ( V_83 )
V_231 = V_239 ? & V_242 : & V_243 ;
else
V_231 = V_239 ? & V_244 : & V_245 ;
if ( V_237 [ 0 ] == '!' ) {
F_242 ( V_237 + 1 , V_231 ) ;
V_25 = 0 ;
goto V_151;
}
V_25 = - V_22 ;
V_45 = F_172 ( sizeof( * V_45 ) , V_164 ) ;
if ( ! V_45 )
goto V_151;
V_45 -> V_83 = V_83 ;
V_45 -> V_229 = - 1 ;
V_45 -> V_70 = V_70 ;
if ( ! V_239 )
goto V_246;
V_241 = F_113 ( & V_239 , L_4 ) ;
V_25 = - V_126 ;
if ( ! strlen ( V_241 ) )
goto V_178;
V_25 = F_243 ( V_241 , 0 , & V_45 -> V_229 ) ;
if ( V_25 )
goto V_178;
V_246:
V_25 = F_244 ( V_70 -> V_5 -> V_196 ) ;
if ( ! V_25 ) {
V_25 = - V_215 ;
goto V_178;
}
V_25 = F_56 ( V_70 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_141;
V_25 = F_245 ( V_237 , V_231 , V_45 ) ;
if ( ! V_25 ) {
V_25 = - V_247 ;
goto V_248;
} else if ( V_25 < 0 )
goto V_248;
V_25 = 0 ;
V_151:
F_55 ( & V_84 ) ;
return V_25 ;
V_248:
F_56 ( V_70 , 0 , 1 ) ;
V_141:
F_240 ( V_70 -> V_5 -> V_196 ) ;
V_178:
F_96 ( V_45 ) ;
goto V_151;
}
static T_6 int F_246 ( void )
{
int V_25 ;
V_25 = F_247 ( & V_249 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_247 ( & V_250 ) ;
if ( F_13 ( V_25 < 0 ) )
F_248 ( & V_249 ) ;
return V_25 ;
}
static inline int F_246 ( void ) { return 0 ; }
static T_6 void
F_249 ( struct V_42 * V_43 )
{
struct V_40 * V_70 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_202 ( V_43 -> V_213 , V_70 ) ;
if ( V_25 < 0 )
F_199 ( L_32 ,
F_60 ( V_70 -> V_5 ) ) ;
}
}
static T_6 void
F_250 ( struct V_42 * V_43 )
{
struct V_4 * V_13 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_95 ( V_13 -> V_196 ) )
continue;
V_25 = F_220 ( V_13 , V_43 ) ;
if ( V_25 < 0 )
F_199 ( L_37 ,
F_60 ( V_13 ) ) ;
}
}
static void
F_251 ( struct V_42 * V_43 )
{
struct V_40 * V_70 , * V_35 ;
F_19 (file, next, &tr->events, list)
F_104 ( V_70 ) ;
}
static void F_222 ( struct V_4 * V_13 )
{
struct V_42 * V_43 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_219 ( V_13 , V_43 ) ;
}
static T_6 int F_252 ( char * V_251 )
{
F_253 ( V_252 , V_251 , V_253 ) ;
V_254 = true ;
V_255 = true ;
return 1 ;
}
static int
F_254 ( struct V_118 * V_180 , struct V_42 * V_43 )
{
struct V_118 * V_185 ;
struct V_118 * V_59 ;
V_59 = F_200 ( L_38 , 0644 , V_180 ,
V_43 , & V_256 ) ;
if ( ! V_59 ) {
F_199 ( L_39 ) ;
return - V_22 ;
}
V_185 = F_198 ( L_40 , V_180 ) ;
if ( ! V_185 ) {
F_199 ( L_41 ) ;
return - V_22 ;
}
V_59 = F_200 ( L_42 , 0644 , V_180 ,
V_43 , & V_257 ) ;
F_201 ( L_43 , 0444 , V_185 ,
V_258 ,
& V_259 ) ;
F_201 ( L_44 , 0444 , V_185 ,
V_260 ,
& V_259 ) ;
F_201 ( L_21 , 0644 , V_185 ,
V_43 , & V_261 ) ;
V_43 -> V_213 = V_185 ;
return 0 ;
}
int F_255 ( struct V_118 * V_180 , struct V_42 * V_43 )
{
int V_25 ;
F_48 ( & V_84 ) ;
V_25 = F_254 ( V_180 , V_43 ) ;
if ( V_25 )
goto V_262;
F_214 ( & V_210 ) ;
F_233 ( V_43 ) ;
F_215 ( & V_210 ) ;
V_262:
F_55 ( & V_84 ) ;
return V_25 ;
}
static T_6 int
F_256 ( struct V_118 * V_180 , struct V_42 * V_43 )
{
int V_25 ;
F_48 ( & V_84 ) ;
V_25 = F_254 ( V_180 , V_43 ) ;
if ( V_25 )
goto V_262;
F_214 ( & V_210 ) ;
F_249 ( V_43 ) ;
F_215 ( & V_210 ) ;
V_262:
F_55 ( & V_84 ) ;
return V_25 ;
}
int F_257 ( struct V_42 * V_43 )
{
F_48 ( & V_84 ) ;
F_258 ( V_43 ) ;
F_81 ( V_43 ) ;
F_110 ( V_43 , NULL , NULL , NULL , 0 ) ;
F_91 () ;
F_214 ( & V_210 ) ;
F_251 ( V_43 ) ;
F_103 ( V_43 -> V_213 ) ;
F_215 ( & V_210 ) ;
V_43 -> V_213 = NULL ;
F_55 ( & V_84 ) ;
return 0 ;
}
static T_6 int F_259 ( void )
{
V_20 = F_260 ( V_9 , V_263 ) ;
V_122 = F_260 ( V_40 , V_263 ) ;
return 0 ;
}
static T_6 void
F_261 ( struct V_42 * V_43 , bool V_264 )
{
char * V_128 = V_252 ;
char * V_265 ;
int V_25 ;
while ( true ) {
V_265 = F_113 ( & V_128 , L_45 ) ;
if ( ! V_265 )
break;
if ( * V_265 ) {
if ( V_264 )
F_112 ( V_43 , V_265 , 0 ) ;
V_25 = F_112 ( V_43 , V_265 , 1 ) ;
if ( V_25 )
F_199 ( L_46 , V_265 ) ;
}
if ( V_128 )
* ( V_128 - 1 ) = ',' ;
}
}
static T_6 int F_262 ( void )
{
struct V_42 * V_43 = F_115 () ;
struct V_4 * * V_62 , * V_13 ;
int V_25 ;
if ( ! V_43 )
return - V_39 ;
F_229 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_13 = * V_62 ;
V_25 = F_209 ( V_13 ) ;
if ( ! V_25 )
F_11 ( & V_13 -> V_112 , & V_197 ) ;
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
V_43 = F_115 () ;
if ( ! V_43 )
return - V_39 ;
F_261 ( V_43 , true ) ;
return 0 ;
}
static T_6 int F_266 ( void )
{
struct V_42 * V_43 ;
struct V_118 * V_266 ;
struct V_118 * V_59 ;
int V_25 ;
V_43 = F_115 () ;
if ( ! V_43 )
return - V_39 ;
V_266 = F_267 () ;
if ( F_163 ( V_266 ) )
return 0 ;
V_59 = F_200 ( L_47 , 0444 , V_266 ,
V_43 , & V_267 ) ;
if ( ! V_59 )
F_199 ( L_48 ) ;
if ( F_14 () )
F_199 ( L_49 ) ;
if ( F_16 () )
F_199 ( L_50 ) ;
V_25 = F_256 ( V_266 , V_43 ) ;
if ( V_25 )
return V_25 ;
#ifdef F_268
V_25 = F_269 ( & V_268 ) ;
if ( V_25 )
F_199 ( L_51 ) ;
#endif
return 0 ;
}
void T_6 F_270 ( void )
{
F_259 () ;
F_271 () ;
F_262 () ;
}
static T_6 void F_272 ( struct V_269 * V_270 )
{
F_105 ( & V_271 ) ;
F_273 ( & V_272 ) ;
F_274 ( 1 ) ;
F_275 ( & V_272 ) ;
F_108 ( & V_271 ) ;
F_48 ( & V_273 ) ;
F_276 ( 1 ) ;
F_55 ( & V_273 ) ;
}
static T_6 int F_277 ( void * V_274 )
{
void * V_275 ;
V_275 = F_158 ( 1234 , V_164 ) ;
if ( ! V_275 )
F_59 ( L_52 ) ;
F_278 ( F_272 ) ;
F_96 ( V_275 ) ;
F_279 ( V_276 ) ;
while ( ! F_280 () ) {
F_281 () ;
F_279 ( V_276 ) ;
}
F_282 ( V_277 ) ;
return 0 ;
}
static T_6 void F_283 ( void )
{
struct V_101 * V_278 ;
V_278 = F_284 ( F_277 , NULL , L_53 ) ;
F_276 ( 1 ) ;
F_285 ( V_278 ) ;
}
static T_6 void F_286 ( void )
{
struct V_114 * V_115 ;
struct V_40 * V_70 ;
struct V_4 * V_13 ;
struct V_1 * system ;
struct V_42 * V_43 ;
int V_25 ;
V_43 = F_115 () ;
if ( ! V_43 )
return;
F_59 ( L_54 ) ;
F_6 (file, &tr->events, list) {
V_13 = V_70 -> V_5 ;
if ( ! V_13 -> V_6 || ! V_13 -> V_6 -> V_74 )
continue;
#ifndef F_287
if ( V_13 -> V_6 -> system &&
strcmp ( V_13 -> V_6 -> system , L_55 ) == 0 )
continue;
#endif
F_59 ( L_56 , F_60 ( V_13 ) ) ;
if ( V_70 -> V_54 & V_85 ) {
F_199 ( L_57 ) ;
F_95 ( 1 ) ;
continue;
}
F_64 ( V_70 , 1 ) ;
F_283 () ;
F_64 ( V_70 , 0 ) ;
F_288 ( L_58 ) ;
}
F_59 ( L_59 ) ;
F_6 (dir, &tr->systems, list) {
system = V_115 -> V_116 ;
if ( strcmp ( system -> V_11 , L_60 ) == 0 )
continue;
F_59 ( L_61 , system -> V_11 ) ;
V_25 = F_111 ( V_43 , NULL , system -> V_11 , NULL , 1 ) ;
if ( F_95 ( V_25 ) ) {
F_199 ( L_62 ,
system -> V_11 ) ;
continue;
}
F_283 () ;
V_25 = F_111 ( V_43 , NULL , system -> V_11 , NULL , 0 ) ;
if ( F_95 ( V_25 ) ) {
F_199 ( L_63 ,
system -> V_11 ) ;
continue;
}
F_288 ( L_58 ) ;
}
F_59 ( L_64 ) ;
F_59 ( L_65 ) ;
V_25 = F_111 ( V_43 , NULL , NULL , NULL , 1 ) ;
if ( F_95 ( V_25 ) ) {
F_199 ( L_66 ) ;
return;
}
F_283 () ;
V_25 = F_111 ( V_43 , NULL , NULL , NULL , 0 ) ;
if ( F_95 ( V_25 ) ) {
F_199 ( L_67 ) ;
return;
}
F_288 ( L_58 ) ;
}
static void T_6
F_289 ( unsigned long V_224 , unsigned long V_225 ,
struct V_279 * V_280 , struct V_281 * V_281 )
{
struct V_282 * V_38 ;
struct V_283 * V_58 ;
struct V_284 * V_59 ;
unsigned long V_54 ;
long V_285 ;
int V_28 ;
int V_56 ;
V_56 = F_31 () ;
F_290 () ;
V_28 = F_291 () ;
V_285 = F_58 ( & F_292 ( V_286 , V_28 ) ) ;
if ( V_285 != 1 )
goto V_151;
F_30 ( V_54 ) ;
V_38 = F_33 ( & V_58 , & V_287 ,
V_288 , sizeof( * V_59 ) ,
V_54 , V_56 ) ;
if ( ! V_38 )
goto V_151;
V_59 = F_34 ( V_38 ) ;
V_59 -> V_224 = V_224 ;
V_59 -> V_225 = V_225 ;
F_42 ( & V_287 , V_58 , V_38 ,
V_59 , V_54 , V_56 ) ;
V_151:
F_293 ( & F_292 ( V_286 , V_28 ) ) ;
F_294 () ;
}
static T_6 void F_295 ( void )
{
int V_25 ;
V_287 . V_43 = F_115 () ;
if ( F_13 ( ! V_287 . V_43 ) )
return;
V_25 = F_296 ( & V_289 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_59 ( L_68 ) ;
return;
}
F_59 ( L_69 ) ;
F_286 () ;
F_297 ( & V_289 ) ;
}
static T_6 void F_295 ( void )
{
}
static T_6 int F_298 ( void )
{
if ( ! V_255 ) {
F_286 () ;
F_295 () ;
}
return 0 ;
}
