static inline int F_1 ( struct V_1 * system )
{
return system -> V_2 & ~ V_3 ;
}
static int F_2 ( struct V_1 * system )
{
return ( system -> V_2 ++ ) & ~ V_3 ;
}
static int F_3 ( struct V_1 * system )
{
return ( -- system -> V_2 ) & ~ V_3 ;
}
static struct V_4 *
F_4 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_7 -> V_8 )
return & V_6 -> V_7 -> V_9 ;
return V_6 -> V_7 -> V_8 ( V_6 ) ;
}
static struct V_10 *
F_5 ( struct V_4 * V_11 , char * V_12 )
{
struct V_10 * V_13 ;
F_6 (field, head, link) {
if ( ! strcmp ( V_13 -> V_12 , V_12 ) )
return V_13 ;
}
return NULL ;
}
struct V_10 *
F_7 ( struct V_5 * V_14 , char * V_12 )
{
struct V_10 * V_13 ;
struct V_4 * V_11 ;
V_13 = F_5 ( & V_15 , V_12 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 ( & V_16 , V_12 ) ;
if ( V_13 )
return V_13 ;
V_11 = F_4 ( V_14 ) ;
return F_5 ( V_11 , V_12 ) ;
}
static int F_8 ( struct V_4 * V_11 , const char * type ,
const char * V_12 , int V_17 , int V_18 ,
int V_19 , int V_20 )
{
struct V_10 * V_13 ;
V_13 = F_9 ( V_21 , V_22 ) ;
if ( ! V_13 )
return - V_23 ;
V_13 -> V_12 = V_12 ;
V_13 -> type = type ;
if ( V_20 == V_24 )
V_13 -> V_20 = F_10 ( type ) ;
else
V_13 -> V_20 = V_20 ;
V_13 -> V_17 = V_17 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_19 = V_19 ;
F_11 ( & V_13 -> V_25 , V_11 ) ;
return 0 ;
}
int F_12 ( struct V_5 * V_14 , const char * type ,
const char * V_12 , int V_17 , int V_18 , int V_19 ,
int V_20 )
{
struct V_4 * V_11 ;
if ( F_13 ( ! V_14 -> V_7 ) )
return 0 ;
V_11 = F_4 ( V_14 ) ;
return F_8 ( V_11 , type , V_12 , V_17 , V_18 ,
V_19 , V_20 ) ;
}
static int F_14 ( void )
{
int V_26 ;
F_15 ( int , V_27 , V_24 ) ;
F_15 ( char * , V_28 , V_29 ) ;
return V_26 ;
}
static int F_16 ( void )
{
int V_26 ;
struct V_30 V_31 ;
F_17 (unsigned short, type) ;
F_17 (unsigned char, flags) ;
F_17 (unsigned char, preempt_count) ;
F_17 ( int , V_32 ) ;
return V_26 ;
}
static void F_18 ( struct V_5 * V_14 )
{
struct V_10 * V_13 , * V_33 ;
struct V_4 * V_11 ;
V_11 = F_4 ( V_14 ) ;
F_19 (field, next, head, link) {
F_20 ( & V_13 -> V_25 ) ;
F_21 ( V_21 , V_13 ) ;
}
}
int F_22 ( struct V_5 * V_14 )
{
int V_34 ;
V_34 = F_23 ( & V_14 -> V_35 ) ;
if ( ! V_34 )
return - V_36 ;
return 0 ;
}
void * F_24 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
unsigned long V_41 )
{
struct V_5 * V_6 = V_40 -> V_6 ;
F_25 ( V_38 -> V_42 ) ;
V_38 -> V_43 = F_26 () ;
V_38 -> V_40 = V_40 ;
V_38 -> V_35 =
F_27 ( & V_38 -> V_44 , V_40 ,
V_6 -> V_35 . type , V_41 ,
V_38 -> V_42 , V_38 -> V_43 ) ;
if ( ! V_38 -> V_35 )
return NULL ;
V_38 -> V_45 = F_28 ( V_38 -> V_35 ) ;
return V_38 -> V_45 ;
}
static void F_29 ( struct V_37 * V_38 )
{
struct V_5 * V_6 ;
struct V_46 * V_35 ;
unsigned long V_42 ;
struct V_47 * V_48 = V_49 ;
if ( ! V_48 )
return;
V_6 = V_38 -> V_40 -> V_6 ;
if ( ! V_6 || ! V_6 -> V_35 . V_50 ||
! V_6 -> V_35 . V_50 -> V_51 )
return;
V_35 = & V_38 -> V_40 -> V_6 -> V_35 ;
F_30 ( & V_52 , V_42 ) ;
F_31 ( & V_48 -> V_53 ) ;
V_48 -> V_31 = V_38 -> V_45 ;
V_6 -> V_35 . V_50 -> V_51 ( V_48 , 0 , V_35 ) ;
F_32 ( & V_48 -> V_53 , 0 ) ;
F_33 ( L_1 , V_48 -> V_53 . V_44 ) ;
F_34 ( & V_52 , V_42 ) ;
}
void F_35 ( struct V_37 * V_38 )
{
if ( V_54 )
F_29 ( V_38 ) ;
F_36 ( V_38 -> V_40 , V_38 -> V_44 ,
V_38 -> V_35 , V_38 -> V_45 ,
V_38 -> V_42 , V_38 -> V_43 ) ;
}
int F_37 ( struct V_5 * V_14 ,
enum V_55 type , void * V_56 )
{
struct V_39 * V_57 = V_56 ;
F_13 ( ! ( V_14 -> V_42 & V_58 ) ) ;
switch ( type ) {
case V_59 :
return F_38 ( V_14 -> V_60 ,
V_14 -> V_7 -> V_61 ,
V_57 ) ;
case V_62 :
F_39 ( V_14 -> V_60 ,
V_14 -> V_7 -> V_61 ,
V_57 ) ;
return 0 ;
#ifdef F_40
case V_63 :
return F_38 ( V_14 -> V_60 ,
V_14 -> V_7 -> V_64 ,
V_14 ) ;
case V_65 :
F_39 ( V_14 -> V_60 ,
V_14 -> V_7 -> V_64 ,
V_14 ) ;
return 0 ;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
return 0 ;
#endif
}
return 0 ;
}
void F_41 ( bool V_70 )
{
struct V_39 * V_57 ;
struct V_71 * V_72 ;
F_42 ( & V_73 ) ;
F_43 (tr, file) {
if ( ! ( V_57 -> V_42 & V_74 ) )
continue;
if ( V_70 ) {
F_44 () ;
F_45 ( V_75 , & V_57 -> V_42 ) ;
} else {
F_46 () ;
F_47 ( V_75 , & V_57 -> V_42 ) ;
}
} F_48 () ;
F_49 ( & V_73 ) ;
}
static int F_50 ( struct V_39 * V_57 ,
int V_70 , int V_76 )
{
struct V_5 * V_14 = V_57 -> V_6 ;
int V_26 = 0 ;
int V_77 ;
switch ( V_70 ) {
case 0 :
if ( V_76 ) {
if ( F_51 ( & V_57 -> V_78 ) > 0 )
break;
V_77 = V_57 -> V_42 & V_79 ;
F_47 ( V_80 , & V_57 -> V_42 ) ;
} else
V_77 = ! ( V_57 -> V_42 & V_81 ) ;
if ( V_77 && ( V_57 -> V_42 & V_74 ) ) {
F_47 ( V_82 , & V_57 -> V_42 ) ;
if ( V_57 -> V_42 & V_83 ) {
F_46 () ;
F_47 ( V_75 , & V_57 -> V_42 ) ;
}
V_14 -> V_7 -> V_84 ( V_14 , V_62 , V_57 ) ;
}
if ( V_57 -> V_42 & V_81 )
F_45 ( V_85 , & V_57 -> V_42 ) ;
else
F_47 ( V_85 , & V_57 -> V_42 ) ;
break;
case 1 :
if ( ! V_76 )
F_47 ( V_85 , & V_57 -> V_42 ) ;
else {
if ( F_52 ( & V_57 -> V_78 ) > 1 )
break;
F_45 ( V_80 , & V_57 -> V_42 ) ;
}
if ( ! ( V_57 -> V_42 & V_74 ) ) {
if ( V_76 )
F_45 ( V_85 , & V_57 -> V_42 ) ;
if ( V_86 & V_87 ) {
F_44 () ;
F_45 ( V_75 , & V_57 -> V_42 ) ;
}
V_26 = V_14 -> V_7 -> V_84 ( V_14 , V_59 , V_57 ) ;
if ( V_26 ) {
F_46 () ;
F_53 ( L_2
L_3 , F_54 ( V_14 ) ) ;
break;
}
F_45 ( V_82 , & V_57 -> V_42 ) ;
V_14 -> V_42 |= V_88 ;
}
break;
}
return V_26 ;
}
int F_55 ( struct V_39 * V_57 ,
int V_70 , int V_76 )
{
return F_50 ( V_57 , V_70 , V_76 ) ;
}
static int F_56 ( struct V_39 * V_57 ,
int V_70 )
{
return F_50 ( V_57 , V_70 , 0 ) ;
}
static void F_57 ( struct V_71 * V_72 )
{
struct V_39 * V_57 ;
F_42 ( & V_73 ) ;
F_6 (file, &tr->events, list) {
F_56 ( V_57 , 0 ) ;
}
F_49 ( & V_73 ) ;
}
static void F_58 ( struct V_1 * system )
{
struct V_89 * V_90 = system -> V_90 ;
F_59 ( F_1 ( system ) == 0 ) ;
if ( F_3 ( system ) )
return;
F_20 ( & system -> V_91 ) ;
if ( V_90 ) {
F_60 ( V_90 -> V_92 ) ;
F_60 ( V_90 ) ;
}
if ( system -> V_2 & V_3 )
F_60 ( system -> V_12 ) ;
F_60 ( system ) ;
}
static void F_61 ( struct V_1 * system )
{
F_59 ( F_1 ( system ) == 0 ) ;
F_2 ( system ) ;
}
static void F_62 ( struct V_93 * V_94 )
{
F_59 ( V_94 -> V_2 == 0 ) ;
V_94 -> V_2 ++ ;
F_61 ( V_94 -> V_95 ) ;
}
static void F_63 ( struct V_93 * V_94 )
{
F_59 ( V_94 -> V_2 == 0 ) ;
F_59 ( F_1 ( V_94 -> V_95 ) == 1 && V_94 -> V_2 != 1 ) ;
F_58 ( V_94 -> V_95 ) ;
if ( ! -- V_94 -> V_2 )
F_60 ( V_94 ) ;
}
static void F_64 ( struct V_93 * V_94 )
{
F_42 ( & V_73 ) ;
F_63 ( V_94 ) ;
F_49 ( & V_73 ) ;
}
static void F_65 ( struct V_93 * V_94 )
{
if ( ! V_94 )
return;
if ( ! -- V_94 -> V_96 ) {
F_66 ( V_94 -> V_45 ) ;
F_20 ( & V_94 -> V_91 ) ;
F_63 ( V_94 ) ;
}
}
static void F_67 ( struct V_39 * V_57 )
{
struct V_97 * V_94 = V_57 -> V_94 ;
struct V_97 * V_98 ;
if ( V_94 ) {
F_68 ( & V_94 -> V_99 ) ;
F_6 (child, &dir->d_subdirs, d_child) {
if ( F_69 ( V_98 ) )
F_70 ( V_98 ) -> V_100 = NULL ;
}
F_71 ( & V_94 -> V_99 ) ;
F_66 ( V_94 ) ;
}
F_20 ( & V_57 -> V_91 ) ;
F_65 ( V_57 -> system ) ;
F_72 ( V_57 -> V_90 ) ;
F_21 ( V_101 , V_57 ) ;
}
static int
F_73 ( struct V_71 * V_72 , const char * V_102 ,
const char * V_103 , const char * V_35 , int V_104 )
{
struct V_39 * V_57 ;
struct V_5 * V_14 ;
const char * V_12 ;
int V_26 = - V_105 ;
F_6 (file, &tr->events, list) {
V_14 = V_57 -> V_6 ;
V_12 = F_54 ( V_14 ) ;
if ( ! V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_84 )
continue;
if ( V_14 -> V_42 & V_106 )
continue;
if ( V_102 &&
strcmp ( V_102 , V_12 ) != 0 &&
strcmp ( V_102 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_103 && strcmp ( V_103 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_35 && strcmp ( V_35 , V_12 ) != 0 )
continue;
F_56 ( V_57 , V_104 ) ;
V_26 = 0 ;
}
return V_26 ;
}
static int F_74 ( struct V_71 * V_72 , const char * V_102 ,
const char * V_103 , const char * V_35 , int V_104 )
{
int V_26 ;
F_42 ( & V_73 ) ;
V_26 = F_73 ( V_72 , V_102 , V_103 , V_35 , V_104 ) ;
F_49 ( & V_73 ) ;
return V_26 ;
}
static int F_75 ( struct V_71 * V_72 , char * V_107 , int V_104 )
{
char * V_35 = NULL , * V_103 = NULL , * V_102 ;
int V_26 ;
V_102 = F_76 ( & V_107 , L_4 ) ;
if ( V_107 ) {
V_103 = V_102 ;
V_35 = V_107 ;
V_102 = NULL ;
if ( ! strlen ( V_103 ) || strcmp ( V_103 , L_5 ) == 0 )
V_103 = NULL ;
if ( ! strlen ( V_35 ) || strcmp ( V_35 , L_5 ) == 0 )
V_35 = NULL ;
}
V_26 = F_74 ( V_72 , V_102 , V_103 , V_35 , V_104 ) ;
if ( V_107 )
* ( V_107 - 1 ) = ':' ;
return V_26 ;
}
int F_77 ( const char * system , const char * V_35 , int V_104 )
{
struct V_71 * V_72 = F_78 () ;
if ( ! V_72 )
return - V_36 ;
return F_74 ( V_72 , NULL , system , V_35 , V_104 ) ;
}
static T_1
F_79 ( struct V_57 * V_57 , const char T_2 * V_108 ,
T_3 V_109 , T_4 * V_110 )
{
struct V_111 V_112 ;
struct V_113 * V_114 = V_57 -> V_115 ;
struct V_71 * V_72 = V_114 -> V_116 ;
T_1 V_117 , V_26 ;
if ( ! V_109 )
return 0 ;
V_26 = F_80 () ;
if ( V_26 < 0 )
return V_26 ;
if ( F_81 ( & V_112 , V_118 + 1 ) )
return - V_23 ;
V_117 = F_82 ( & V_112 , V_108 , V_109 , V_110 ) ;
if ( V_117 >= 0 && F_83 ( ( & V_112 ) ) ) {
int V_104 = 1 ;
if ( * V_112 . V_44 == '!' )
V_104 = 0 ;
V_112 . V_44 [ V_112 . V_119 ] = 0 ;
V_26 = F_75 ( V_72 , V_112 . V_44 + ! V_104 , V_104 ) ;
if ( V_26 )
goto V_120;
}
V_26 = V_117 ;
V_120:
F_84 ( & V_112 ) ;
return V_26 ;
}
static void *
F_85 ( struct V_113 * V_114 , void * V_121 , T_4 * V_122 )
{
struct V_39 * V_57 = V_121 ;
struct V_5 * V_14 ;
struct V_71 * V_72 = V_114 -> V_116 ;
( * V_122 ) ++ ;
F_86 (file, &tr->events, list) {
V_14 = V_57 -> V_6 ;
if ( V_14 -> V_7 && V_14 -> V_7 -> V_84 )
return V_57 ;
}
return NULL ;
}
static void * F_87 ( struct V_113 * V_114 , T_4 * V_122 )
{
struct V_39 * V_57 ;
struct V_71 * V_72 = V_114 -> V_116 ;
T_4 V_123 ;
F_42 ( & V_73 ) ;
V_57 = F_88 ( & V_72 -> V_124 , struct V_39 , V_91 ) ;
for ( V_123 = 0 ; V_123 <= * V_122 ; ) {
V_57 = F_85 ( V_114 , V_57 , & V_123 ) ;
if ( ! V_57 )
break;
}
return V_57 ;
}
static void *
F_89 ( struct V_113 * V_114 , void * V_121 , T_4 * V_122 )
{
struct V_39 * V_57 = V_121 ;
struct V_71 * V_72 = V_114 -> V_116 ;
( * V_122 ) ++ ;
F_86 (file, &tr->events, list) {
if ( V_57 -> V_42 & V_74 )
return V_57 ;
}
return NULL ;
}
static void * F_90 ( struct V_113 * V_114 , T_4 * V_122 )
{
struct V_39 * V_57 ;
struct V_71 * V_72 = V_114 -> V_116 ;
T_4 V_123 ;
F_42 ( & V_73 ) ;
V_57 = F_88 ( & V_72 -> V_124 , struct V_39 , V_91 ) ;
for ( V_123 = 0 ; V_123 <= * V_122 ; ) {
V_57 = F_89 ( V_114 , V_57 , & V_123 ) ;
if ( ! V_57 )
break;
}
return V_57 ;
}
static int F_91 ( struct V_113 * V_114 , void * V_121 )
{
struct V_39 * V_57 = V_121 ;
struct V_5 * V_14 = V_57 -> V_6 ;
if ( strcmp ( V_14 -> V_7 -> system , V_125 ) != 0 )
F_92 ( V_114 , L_6 , V_14 -> V_7 -> system ) ;
F_92 ( V_114 , L_3 , F_54 ( V_14 ) ) ;
return 0 ;
}
static void F_93 ( struct V_113 * V_114 , void * V_126 )
{
F_49 ( & V_73 ) ;
}
static T_1
F_94 ( struct V_57 * V_127 , char T_2 * V_108 , T_3 V_109 ,
T_4 * V_110 )
{
struct V_39 * V_57 ;
unsigned long V_42 ;
char V_107 [ 4 ] = L_7 ;
F_42 ( & V_73 ) ;
V_57 = F_95 ( V_127 ) ;
if ( F_96 ( V_57 ) )
V_42 = V_57 -> V_42 ;
F_49 ( & V_73 ) ;
if ( ! V_57 )
return - V_36 ;
if ( V_42 & V_74 &&
! ( V_42 & V_79 ) )
strcpy ( V_107 , L_8 ) ;
if ( V_42 & V_79 ||
V_42 & V_81 )
strcat ( V_107 , L_5 ) ;
strcat ( V_107 , L_9 ) ;
return F_97 ( V_108 , V_109 , V_110 , V_107 , strlen ( V_107 ) ) ;
}
static T_1
F_98 ( struct V_57 * V_127 , const char T_2 * V_108 , T_3 V_109 ,
T_4 * V_110 )
{
struct V_39 * V_57 ;
unsigned long V_128 ;
int V_26 ;
V_26 = F_99 ( V_108 , V_109 , 10 , & V_128 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_80 () ;
if ( V_26 < 0 )
return V_26 ;
switch ( V_128 ) {
case 0 :
case 1 :
V_26 = - V_36 ;
F_42 ( & V_73 ) ;
V_57 = F_95 ( V_127 ) ;
if ( F_96 ( V_57 ) )
V_26 = F_56 ( V_57 , V_128 ) ;
F_49 ( & V_73 ) ;
break;
default:
return - V_105 ;
}
* V_110 += V_109 ;
return V_26 ? V_26 : V_109 ;
}
static T_1
F_100 ( struct V_57 * V_127 , char T_2 * V_108 , T_3 V_109 ,
T_4 * V_110 )
{
const char V_129 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_93 * V_94 = V_127 -> V_115 ;
struct V_1 * system = V_94 -> V_95 ;
struct V_5 * V_14 ;
struct V_39 * V_57 ;
struct V_71 * V_72 = V_94 -> V_72 ;
char V_107 [ 2 ] ;
int V_104 = 0 ;
int V_26 ;
F_42 ( & V_73 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_57 -> V_6 ;
if ( ! F_54 ( V_14 ) || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_84 )
continue;
if ( system && strcmp ( V_14 -> V_7 -> system , system -> V_12 ) != 0 )
continue;
V_104 |= ( 1 << ! ! ( V_57 -> V_42 & V_74 ) ) ;
if ( V_104 == 3 )
break;
}
F_49 ( & V_73 ) ;
V_107 [ 0 ] = V_129 [ V_104 ] ;
V_107 [ 1 ] = '\n' ;
V_26 = F_97 ( V_108 , V_109 , V_110 , V_107 , 2 ) ;
return V_26 ;
}
static T_1
F_101 ( struct V_57 * V_127 , const char T_2 * V_108 , T_3 V_109 ,
T_4 * V_110 )
{
struct V_93 * V_94 = V_127 -> V_115 ;
struct V_1 * system = V_94 -> V_95 ;
const char * V_12 = NULL ;
unsigned long V_128 ;
T_1 V_26 ;
V_26 = F_99 ( V_108 , V_109 , 10 , & V_128 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_80 () ;
if ( V_26 < 0 )
return V_26 ;
if ( V_128 != 0 && V_128 != 1 )
return - V_105 ;
if ( system )
V_12 = system -> V_12 ;
V_26 = F_74 ( V_94 -> V_72 , NULL , V_12 , NULL , V_128 ) ;
if ( V_26 )
goto V_130;
V_26 = V_109 ;
V_130:
* V_110 += V_109 ;
return V_26 ;
}
static void * F_102 ( struct V_113 * V_114 , void * V_121 , T_4 * V_122 )
{
struct V_5 * V_14 = F_95 ( V_114 -> V_116 ) ;
struct V_4 * V_131 = & V_16 ;
struct V_4 * V_11 = F_4 ( V_14 ) ;
struct V_4 * V_132 = V_121 ;
( * V_122 ) ++ ;
switch ( ( unsigned long ) V_121 ) {
case V_133 :
V_132 = V_131 ;
break;
case V_134 :
V_132 = V_11 ;
break;
case V_135 :
return NULL ;
}
V_132 = V_132 -> V_136 ;
if ( V_132 == V_131 )
return ( void * ) V_134 ;
else if ( V_132 == V_11 )
return ( void * ) V_135 ;
else
return V_132 ;
}
static int F_103 ( struct V_113 * V_114 , void * V_121 )
{
struct V_5 * V_14 = F_95 ( V_114 -> V_116 ) ;
struct V_10 * V_13 ;
const char * V_137 ;
switch ( ( unsigned long ) V_121 ) {
case V_133 :
F_92 ( V_114 , L_10 , F_54 ( V_14 ) ) ;
F_92 ( V_114 , L_11 , V_14 -> V_35 . type ) ;
F_104 ( V_114 , L_12 ) ;
return 0 ;
case V_134 :
F_105 ( V_114 , '\n' ) ;
return 0 ;
case V_135 :
F_92 ( V_114 , L_13 ,
V_14 -> V_138 ) ;
return 0 ;
}
V_13 = F_88 ( V_121 , struct V_10 , V_25 ) ;
V_137 = strchr ( V_13 -> type , '[' ) ;
if ( ! strncmp ( V_13 -> type , L_14 , 10 ) )
V_137 = NULL ;
if ( ! V_137 )
F_92 ( V_114 , L_15 ,
V_13 -> type , V_13 -> V_12 , V_13 -> V_17 ,
V_13 -> V_18 , ! ! V_13 -> V_19 ) ;
else
F_92 ( V_114 , L_16 ,
( int ) ( V_137 - V_13 -> type ) ,
V_13 -> type , V_13 -> V_12 ,
V_137 , V_13 -> V_17 ,
V_13 -> V_18 , ! ! V_13 -> V_19 ) ;
return 0 ;
}
static void * F_106 ( struct V_113 * V_114 , T_4 * V_122 )
{
void * V_126 = ( void * ) V_133 ;
T_4 V_123 = 0 ;
F_42 ( & V_73 ) ;
if ( ! F_95 ( V_114 -> V_116 ) )
return F_107 ( - V_36 ) ;
while ( V_123 < * V_122 && V_126 )
V_126 = F_102 ( V_114 , V_126 , & V_123 ) ;
return V_126 ;
}
static void F_108 ( struct V_113 * V_114 , void * V_126 )
{
F_49 ( & V_73 ) ;
}
static int F_109 ( struct V_139 * V_139 , struct V_57 * V_57 )
{
struct V_113 * V_114 ;
int V_26 ;
V_26 = F_110 ( V_57 , & V_140 ) ;
if ( V_26 < 0 )
return V_26 ;
V_114 = V_57 -> V_115 ;
V_114 -> V_116 = V_57 ;
return 0 ;
}
static T_1
F_111 ( struct V_57 * V_127 , char T_2 * V_108 , T_3 V_109 , T_4 * V_110 )
{
int V_34 = ( long ) F_95 ( V_127 ) ;
char V_107 [ 32 ] ;
int V_41 ;
if ( * V_110 )
return 0 ;
if ( F_112 ( ! V_34 ) )
return - V_36 ;
V_41 = sprintf ( V_107 , L_17 , V_34 ) ;
return F_97 ( V_108 , V_109 , V_110 , V_107 , V_41 ) ;
}
static T_1
F_113 ( struct V_57 * V_127 , char T_2 * V_108 , T_3 V_109 ,
T_4 * V_110 )
{
struct V_39 * V_57 ;
struct V_141 * V_142 ;
int V_143 = - V_36 ;
if ( * V_110 )
return 0 ;
V_142 = F_114 ( sizeof( * V_142 ) , V_144 ) ;
if ( ! V_142 )
return - V_23 ;
F_31 ( V_142 ) ;
F_42 ( & V_73 ) ;
V_57 = F_95 ( V_127 ) ;
if ( V_57 )
F_115 ( V_57 , V_142 ) ;
F_49 ( & V_73 ) ;
if ( V_57 )
V_143 = F_97 ( V_108 , V_109 , V_110 ,
V_142 -> V_44 , F_116 ( V_142 ) ) ;
F_60 ( V_142 ) ;
return V_143 ;
}
static T_1
F_117 ( struct V_57 * V_127 , const char T_2 * V_108 , T_3 V_109 ,
T_4 * V_110 )
{
struct V_39 * V_57 ;
char * V_107 ;
int V_145 = - V_36 ;
if ( V_109 >= V_146 )
return - V_105 ;
V_107 = ( char * ) F_118 ( V_147 ) ;
if ( ! V_107 )
return - V_23 ;
if ( F_119 ( V_107 , V_108 , V_109 ) ) {
F_120 ( ( unsigned long ) V_107 ) ;
return - V_148 ;
}
V_107 [ V_109 ] = '\0' ;
F_42 ( & V_73 ) ;
V_57 = F_95 ( V_127 ) ;
if ( V_57 )
V_145 = F_121 ( V_57 , V_107 ) ;
F_49 ( & V_73 ) ;
F_120 ( ( unsigned long ) V_107 ) ;
if ( V_145 < 0 )
return V_145 ;
* V_110 += V_109 ;
return V_109 ;
}
static int F_122 ( struct V_139 * V_139 , struct V_57 * V_127 )
{
struct V_1 * system = NULL ;
struct V_93 * V_94 = NULL ;
struct V_71 * V_72 ;
int V_26 ;
if ( F_123 () )
return - V_36 ;
F_42 ( & V_149 ) ;
F_42 ( & V_73 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_94 == V_139 -> V_100 ) {
if ( V_94 -> V_96 ) {
F_62 ( V_94 ) ;
system = V_94 -> V_95 ;
}
goto V_150;
}
}
}
V_150:
F_49 ( & V_73 ) ;
F_49 ( & V_149 ) ;
if ( ! system )
return - V_36 ;
F_13 ( ! V_94 ) ;
if ( F_124 ( V_72 ) < 0 ) {
F_64 ( V_94 ) ;
return - V_36 ;
}
V_26 = F_125 ( V_139 , V_127 ) ;
if ( V_26 < 0 ) {
F_126 ( V_72 ) ;
F_64 ( V_94 ) ;
}
return V_26 ;
}
static int F_127 ( struct V_139 * V_139 , struct V_57 * V_127 )
{
struct V_93 * V_94 ;
struct V_71 * V_72 = V_139 -> V_100 ;
int V_26 ;
if ( F_123 () )
return - V_36 ;
if ( F_124 ( V_72 ) < 0 )
return - V_36 ;
V_94 = F_128 ( sizeof( * V_94 ) , V_144 ) ;
if ( ! V_94 ) {
F_126 ( V_72 ) ;
return - V_23 ;
}
V_94 -> V_72 = V_72 ;
V_26 = F_125 ( V_139 , V_127 ) ;
if ( V_26 < 0 ) {
F_126 ( V_72 ) ;
F_60 ( V_94 ) ;
return V_26 ;
}
V_127 -> V_115 = V_94 ;
return 0 ;
}
static int F_129 ( struct V_139 * V_139 , struct V_57 * V_57 )
{
struct V_93 * V_94 = V_57 -> V_115 ;
F_126 ( V_94 -> V_72 ) ;
if ( V_94 -> V_95 )
F_64 ( V_94 ) ;
else
F_60 ( V_94 ) ;
return 0 ;
}
static T_1
F_130 ( struct V_57 * V_127 , char T_2 * V_108 , T_3 V_109 ,
T_4 * V_110 )
{
struct V_93 * V_94 = V_127 -> V_115 ;
struct V_1 * system = V_94 -> V_95 ;
struct V_141 * V_142 ;
int V_143 ;
if ( * V_110 )
return 0 ;
V_142 = F_114 ( sizeof( * V_142 ) , V_144 ) ;
if ( ! V_142 )
return - V_23 ;
F_31 ( V_142 ) ;
F_131 ( system , V_142 ) ;
V_143 = F_97 ( V_108 , V_109 , V_110 ,
V_142 -> V_44 , F_116 ( V_142 ) ) ;
F_60 ( V_142 ) ;
return V_143 ;
}
static T_1
F_132 ( struct V_57 * V_127 , const char T_2 * V_108 , T_3 V_109 ,
T_4 * V_110 )
{
struct V_93 * V_94 = V_127 -> V_115 ;
char * V_107 ;
int V_145 ;
if ( V_109 >= V_146 )
return - V_105 ;
V_107 = ( char * ) F_118 ( V_147 ) ;
if ( ! V_107 )
return - V_23 ;
if ( F_119 ( V_107 , V_108 , V_109 ) ) {
F_120 ( ( unsigned long ) V_107 ) ;
return - V_148 ;
}
V_107 [ V_109 ] = '\0' ;
V_145 = F_133 ( V_94 , V_107 ) ;
F_120 ( ( unsigned long ) V_107 ) ;
if ( V_145 < 0 )
return V_145 ;
* V_110 += V_109 ;
return V_109 ;
}
static T_1
F_134 ( struct V_57 * V_127 , char T_2 * V_108 , T_3 V_109 , T_4 * V_110 )
{
int (* F_135)( struct V_141 * V_142 ) = V_127 -> V_115 ;
struct V_141 * V_142 ;
int V_143 ;
if ( * V_110 )
return 0 ;
V_142 = F_114 ( sizeof( * V_142 ) , V_144 ) ;
if ( ! V_142 )
return - V_23 ;
F_31 ( V_142 ) ;
F_135 ( V_142 ) ;
V_143 = F_97 ( V_108 , V_109 , V_110 ,
V_142 -> V_44 , F_116 ( V_142 ) ) ;
F_60 ( V_142 ) ;
return V_143 ;
}
static int
F_136 ( struct V_139 * V_139 , struct V_57 * V_57 ,
const struct V_151 * V_152 )
{
struct V_113 * V_114 ;
int V_26 ;
V_26 = F_110 ( V_57 , V_152 ) ;
if ( V_26 < 0 )
return V_26 ;
V_114 = V_57 -> V_115 ;
V_114 -> V_116 = V_139 -> V_100 ;
return V_26 ;
}
static int F_137 ( struct V_139 * V_139 , struct V_57 * V_57 )
{
struct V_71 * V_72 = V_139 -> V_100 ;
F_126 ( V_72 ) ;
return F_138 ( V_139 , V_57 ) ;
}
static int
F_139 ( struct V_139 * V_139 , struct V_57 * V_57 )
{
const struct V_151 * V_152 = & V_153 ;
return F_136 ( V_139 , V_57 , V_152 ) ;
}
static int
F_140 ( struct V_139 * V_139 , struct V_57 * V_57 )
{
const struct V_151 * V_152 = & V_154 ;
struct V_71 * V_72 = V_139 -> V_100 ;
int V_26 ;
if ( F_124 ( V_72 ) < 0 )
return - V_36 ;
if ( ( V_57 -> V_155 & V_156 ) &&
( V_57 -> V_157 & V_158 ) )
F_57 ( V_72 ) ;
V_26 = F_136 ( V_139 , V_57 , V_152 ) ;
if ( V_26 < 0 )
F_126 ( V_72 ) ;
return V_26 ;
}
static struct V_1 *
F_141 ( const char * V_12 )
{
struct V_1 * system ;
system = F_114 ( sizeof( * system ) , V_144 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
if ( ! F_142 ( ( unsigned long ) V_12 ) ) {
system -> V_2 |= V_3 ;
system -> V_12 = F_143 ( V_12 , V_144 ) ;
if ( ! system -> V_12 )
goto V_159;
} else
system -> V_12 = V_12 ;
system -> V_90 = NULL ;
system -> V_90 = F_128 ( sizeof( struct V_89 ) , V_144 ) ;
if ( ! system -> V_90 )
goto V_159;
F_11 ( & system -> V_91 , & V_160 ) ;
return system ;
V_159:
if ( system -> V_2 & V_3 )
F_60 ( system -> V_12 ) ;
F_60 ( system ) ;
return NULL ;
}
static struct V_97 *
F_144 ( struct V_71 * V_72 , const char * V_12 ,
struct V_39 * V_57 , struct V_97 * V_161 )
{
struct V_93 * V_94 ;
struct V_1 * system ;
struct V_97 * V_45 ;
F_6 (dir, &tr->systems, list) {
system = V_94 -> V_95 ;
if ( strcmp ( system -> V_12 , V_12 ) == 0 ) {
V_94 -> V_96 ++ ;
V_57 -> system = V_94 ;
return V_94 -> V_45 ;
}
}
F_6 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_12 , V_12 ) == 0 )
break;
}
if ( & system -> V_91 == & V_160 )
system = NULL ;
V_94 = F_114 ( sizeof( * V_94 ) , V_144 ) ;
if ( ! V_94 )
goto V_162;
if ( ! system ) {
system = F_141 ( V_12 ) ;
if ( ! system )
goto V_159;
} else
F_61 ( system ) ;
V_94 -> V_45 = F_145 ( V_12 , V_161 ) ;
if ( ! V_94 -> V_45 ) {
F_146 ( L_18 , V_12 ) ;
F_58 ( system ) ;
goto V_159;
}
V_94 -> V_72 = V_72 ;
V_94 -> V_2 = 1 ;
V_94 -> V_96 = 1 ;
V_94 -> V_95 = system ;
V_57 -> system = V_94 ;
V_45 = F_147 ( L_19 , 0644 , V_94 -> V_45 , V_94 ,
& V_163 ) ;
if ( ! V_45 ) {
F_60 ( system -> V_90 ) ;
system -> V_90 = NULL ;
F_146 ( L_20 , V_12 ) ;
}
F_148 ( L_21 , 0644 , V_94 -> V_45 , V_94 ,
& V_164 ) ;
F_11 ( & V_94 -> V_91 , & V_72 -> V_165 ) ;
return V_94 -> V_45 ;
V_159:
F_60 ( V_94 ) ;
V_162:
if ( ! V_94 || ! system )
F_146 ( L_22 , V_12 ) ;
return NULL ;
}
static int
F_149 ( struct V_97 * V_161 , struct V_39 * V_57 )
{
struct V_5 * V_14 = V_57 -> V_6 ;
struct V_71 * V_72 = V_57 -> V_72 ;
struct V_4 * V_11 ;
struct V_97 * V_166 ;
const char * V_12 ;
int V_26 ;
if ( strcmp ( V_14 -> V_7 -> system , V_125 ) != 0 ) {
V_166 = F_144 ( V_72 , V_14 -> V_7 -> system , V_57 , V_161 ) ;
if ( ! V_166 )
return - V_23 ;
} else
V_166 = V_161 ;
V_12 = F_54 ( V_14 ) ;
V_57 -> V_94 = F_145 ( V_12 , V_166 ) ;
if ( ! V_57 -> V_94 ) {
F_146 ( L_23 , V_12 ) ;
return - 1 ;
}
if ( V_14 -> V_7 -> V_84 && ! ( V_14 -> V_42 & V_106 ) )
F_148 ( L_21 , 0644 , V_57 -> V_94 , V_57 ,
& V_167 ) ;
#ifdef F_40
if ( V_14 -> V_35 . type && V_14 -> V_7 -> V_84 )
F_148 ( L_24 , 0444 , V_57 -> V_94 ,
( void * ) ( long ) V_14 -> V_35 . type ,
& V_168 ) ;
#endif
V_11 = F_4 ( V_14 ) ;
if ( F_150 ( V_11 ) ) {
V_26 = V_14 -> V_7 -> V_169 ( V_14 ) ;
if ( V_26 < 0 ) {
F_146 ( L_25 ,
V_12 ) ;
return - 1 ;
}
}
F_148 ( L_19 , 0644 , V_57 -> V_94 , V_57 ,
& V_170 ) ;
F_148 ( L_26 , 0644 , V_57 -> V_94 , V_57 ,
& V_171 ) ;
F_148 ( L_27 , 0444 , V_57 -> V_94 , V_14 ,
& V_172 ) ;
return 0 ;
}
static void F_151 ( struct V_5 * V_14 )
{
struct V_39 * V_57 ;
struct V_71 * V_72 ;
F_152 (tr, file) {
if ( V_57 -> V_6 != V_14 )
continue;
F_67 ( V_57 ) ;
break;
} F_48 () ;
}
static void F_153 ( struct V_5 * V_14 )
{
struct V_71 * V_72 ;
struct V_39 * V_57 ;
F_43 (tr, file) {
if ( V_57 -> V_6 != V_14 )
continue;
F_56 ( V_57 , 0 ) ;
break;
} F_48 () ;
if ( V_14 -> V_35 . V_50 )
F_154 ( & V_14 -> V_35 ) ;
F_151 ( V_14 ) ;
F_20 ( & V_14 -> V_91 ) ;
}
static int F_155 ( struct V_5 * V_14 )
{
int V_26 = 0 ;
const char * V_12 ;
V_12 = F_54 ( V_14 ) ;
if ( F_13 ( ! V_12 ) )
return - V_105 ;
if ( V_14 -> V_7 -> V_173 ) {
V_26 = V_14 -> V_7 -> V_173 ( V_14 ) ;
if ( V_26 < 0 && V_26 != - V_174 )
F_146 ( L_28 , V_12 ) ;
}
return V_26 ;
}
static int
F_156 ( struct V_5 * V_14 , struct V_175 * V_176 )
{
int V_26 ;
V_26 = F_155 ( V_14 ) ;
if ( V_26 < 0 )
return V_26 ;
F_11 ( & V_14 -> V_91 , & V_177 ) ;
V_14 -> V_176 = V_176 ;
return 0 ;
}
static char * F_157 ( char * V_178 , struct V_179 * V_180 , int V_41 )
{
int V_181 ;
int V_182 ;
V_182 = snprintf ( V_178 , 0 , L_29 , V_180 -> V_183 ) ;
if ( V_41 < V_182 )
return NULL ;
snprintf ( V_178 , V_182 + 1 , L_29 , V_180 -> V_183 ) ;
V_181 = strlen ( V_178 + V_41 ) ;
memmove ( V_178 + V_182 , V_178 + V_41 , V_181 ) ;
V_178 [ V_182 + V_181 ] = 0 ;
return V_178 + V_182 ;
}
static void F_158 ( struct V_5 * V_14 ,
struct V_179 * V_180 )
{
char * V_178 ;
int V_184 = 0 ;
int V_41 = strlen ( V_180 -> V_185 ) ;
for ( V_178 = V_14 -> V_138 ; * V_178 ; V_178 ++ ) {
if ( * V_178 == '\\' ) {
V_178 ++ ;
if ( ! * V_178 )
break;
continue;
}
if ( * V_178 == '"' ) {
V_184 ^= 1 ;
continue;
}
if ( V_184 )
continue;
if ( isdigit ( * V_178 ) ) {
do {
V_178 ++ ;
} while ( isalnum ( * V_178 ) );
if ( ! * V_178 )
break;
continue;
}
if ( isalpha ( * V_178 ) || * V_178 == '_' ) {
if ( strncmp ( V_180 -> V_185 , V_178 , V_41 ) == 0 &&
! isalnum ( V_178 [ V_41 ] ) && V_178 [ V_41 ] != '_' ) {
V_178 = F_157 ( V_178 , V_180 , V_41 ) ;
if ( F_59 ( ! V_178 ) )
return;
continue;
}
V_186:
do {
V_178 ++ ;
} while ( isalnum ( * V_178 ) || * V_178 == '_' );
if ( ! * V_178 )
break;
if ( * V_178 == '.' || ( V_178 [ 0 ] == '-' && V_178 [ 1 ] == '>' ) ) {
V_178 += * V_178 == '.' ? 1 : 2 ;
if ( ! * V_178 )
break;
goto V_186;
}
continue;
}
}
}
void F_159 ( struct V_179 * * V_180 , int V_41 )
{
struct V_5 * V_14 , * V_126 ;
const char * V_187 = NULL ;
int V_188 ;
int V_189 ;
F_160 ( & V_190 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( ! V_187 || V_14 -> V_7 -> system != V_187 ) {
V_188 = 0 ;
V_187 = V_14 -> V_7 -> system ;
}
for ( V_189 = V_188 ; V_189 < V_41 ; V_189 ++ ) {
if ( V_14 -> V_7 -> system == V_180 [ V_189 ] -> system ) {
if ( ! V_188 )
V_188 = V_189 ;
F_158 ( V_14 , V_180 [ V_189 ] ) ;
}
}
}
F_161 ( & V_190 ) ;
}
static struct V_39 *
F_162 ( struct V_5 * V_14 ,
struct V_71 * V_72 )
{
struct V_39 * V_57 ;
V_57 = F_9 ( V_101 , V_22 ) ;
if ( ! V_57 )
return NULL ;
V_57 -> V_6 = V_14 ;
V_57 -> V_72 = V_72 ;
F_163 ( & V_57 -> V_78 , 0 ) ;
F_163 ( & V_57 -> V_191 , 0 ) ;
F_164 ( & V_57 -> V_192 ) ;
F_11 ( & V_57 -> V_91 , & V_72 -> V_124 ) ;
return V_57 ;
}
static int
F_165 ( struct V_5 * V_14 , struct V_71 * V_72 )
{
struct V_39 * V_57 ;
V_57 = F_162 ( V_14 , V_72 ) ;
if ( ! V_57 )
return - V_23 ;
return F_149 ( V_72 -> V_193 , V_57 ) ;
}
static T_5 int
F_166 ( struct V_5 * V_14 ,
struct V_71 * V_72 )
{
struct V_39 * V_57 ;
V_57 = F_162 ( V_14 , V_72 ) ;
if ( ! V_57 )
return - V_23 ;
return 0 ;
}
int F_167 ( struct V_5 * V_14 )
{
int V_26 ;
F_42 ( & V_149 ) ;
F_42 ( & V_73 ) ;
V_26 = F_156 ( V_14 , NULL ) ;
if ( V_26 >= 0 )
F_168 ( V_14 ) ;
F_49 ( & V_73 ) ;
F_49 ( & V_149 ) ;
return V_26 ;
}
static void F_169 ( struct V_5 * V_14 )
{
F_153 ( V_14 ) ;
F_18 ( V_14 ) ;
F_72 ( V_14 -> V_90 ) ;
V_14 -> V_90 = NULL ;
}
static int F_170 ( struct V_5 * V_14 )
{
struct V_71 * V_72 ;
struct V_39 * V_57 ;
#ifdef F_40
if ( V_14 -> V_194 )
return - V_195 ;
#endif
F_43 (tr, file) {
if ( V_57 -> V_6 != V_14 )
continue;
if ( V_57 -> V_42 & V_74 )
return - V_195 ;
break;
} F_48 () ;
F_169 ( V_14 ) ;
return 0 ;
}
int F_171 ( struct V_5 * V_14 )
{
int V_26 ;
F_42 ( & V_149 ) ;
F_42 ( & V_73 ) ;
F_160 ( & V_190 ) ;
V_26 = F_170 ( V_14 ) ;
F_161 ( & V_190 ) ;
F_49 ( & V_73 ) ;
F_49 ( & V_149 ) ;
return V_26 ;
}
static void F_172 ( struct V_175 * V_176 )
{
struct V_5 * * V_14 , * * V_196 , * * V_197 ;
if ( ! V_176 -> V_198 )
return;
if ( F_173 ( V_176 ) ) {
F_174 ( L_30 ,
V_176 -> V_12 ) ;
return;
}
V_196 = V_176 -> V_199 ;
V_197 = V_176 -> V_199 + V_176 -> V_198 ;
F_175 (call, start, end) {
F_156 ( * V_14 , V_176 ) ;
F_168 ( * V_14 ) ;
}
}
static void F_176 ( struct V_175 * V_176 )
{
struct V_5 * V_14 , * V_126 ;
bool V_200 = false ;
F_160 ( & V_190 ) ;
F_19 (call, p, &ftrace_events, list) {
if ( V_14 -> V_176 == V_176 ) {
if ( V_14 -> V_42 & V_88 )
V_200 = true ;
F_169 ( V_14 ) ;
}
}
F_161 ( & V_190 ) ;
if ( V_200 )
F_177 () ;
}
static int F_178 ( struct V_201 * V_202 ,
unsigned long V_128 , void * V_56 )
{
struct V_175 * V_176 = V_56 ;
F_42 ( & V_149 ) ;
F_42 ( & V_73 ) ;
switch ( V_128 ) {
case V_203 :
F_172 ( V_176 ) ;
break;
case V_204 :
F_176 ( V_176 ) ;
break;
}
F_49 ( & V_73 ) ;
F_49 ( & V_149 ) ;
return 0 ;
}
static void
F_179 ( struct V_71 * V_72 )
{
struct V_5 * V_14 ;
int V_26 ;
F_6 (call, &ftrace_events, list) {
V_26 = F_165 ( V_14 , V_72 ) ;
if ( V_26 < 0 )
F_146 ( L_31 ,
F_54 ( V_14 ) ) ;
}
}
struct V_39 *
F_180 ( struct V_71 * V_72 , const char * system , const char * V_35 )
{
struct V_39 * V_57 ;
struct V_5 * V_14 ;
const char * V_12 ;
F_6 (file, &tr->events, list) {
V_14 = V_57 -> V_6 ;
V_12 = F_54 ( V_14 ) ;
if ( ! V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_84 )
continue;
if ( V_14 -> V_42 & V_106 )
continue;
if ( strcmp ( V_35 , V_12 ) == 0 &&
strcmp ( system , V_14 -> V_7 -> system ) == 0 )
return V_57 ;
}
return NULL ;
}
static void
F_181 ( unsigned long V_205 , unsigned long V_206 , void * * V_207 )
{
struct V_208 * * V_209 = (struct V_208 * * ) V_207 ;
struct V_208 * V_56 = * V_209 ;
if ( ! V_56 )
return;
if ( V_56 -> V_70 )
F_47 ( V_85 , & V_56 -> V_57 -> V_42 ) ;
else
F_45 ( V_85 , & V_56 -> V_57 -> V_42 ) ;
}
static void
F_182 ( unsigned long V_205 , unsigned long V_206 , void * * V_207 )
{
struct V_208 * * V_209 = (struct V_208 * * ) V_207 ;
struct V_208 * V_56 = * V_209 ;
if ( ! V_56 )
return;
if ( ! V_56 -> V_210 )
return;
if ( V_56 -> V_70 == ! ( V_56 -> V_57 -> V_42 & V_79 ) )
return;
if ( V_56 -> V_210 != - 1 )
( V_56 -> V_210 ) -- ;
F_181 ( V_205 , V_206 , V_207 ) ;
}
static int
F_183 ( struct V_113 * V_114 , unsigned long V_205 ,
struct V_211 * V_212 , void * V_207 )
{
struct V_208 * V_56 = V_207 ;
F_92 ( V_114 , L_32 , ( void * ) V_205 ) ;
F_92 ( V_114 , L_33 ,
V_56 -> V_70 ? V_213 : V_214 ,
V_56 -> V_57 -> V_6 -> V_7 -> system ,
F_54 ( V_56 -> V_57 -> V_6 ) ) ;
if ( V_56 -> V_210 == - 1 )
F_104 ( V_114 , L_34 ) ;
else
F_92 ( V_114 , L_35 , V_56 -> V_210 ) ;
return 0 ;
}
static int
F_184 ( struct V_211 * V_212 , unsigned long V_205 ,
void * * V_207 )
{
struct V_208 * * V_209 = (struct V_208 * * ) V_207 ;
struct V_208 * V_56 = * V_209 ;
V_56 -> V_215 ++ ;
return 0 ;
}
static void
F_185 ( struct V_211 * V_212 , unsigned long V_205 ,
void * * V_207 )
{
struct V_208 * * V_209 = (struct V_208 * * ) V_207 ;
struct V_208 * V_56 = * V_209 ;
if ( F_59 ( V_56 -> V_215 <= 0 ) )
return;
V_56 -> V_215 -- ;
if ( ! V_56 -> V_215 ) {
F_50 ( V_56 -> V_57 , 0 , 1 ) ;
F_186 ( V_56 -> V_57 -> V_6 -> V_176 ) ;
F_60 ( V_56 ) ;
}
* V_209 = NULL ;
}
static int
F_187 ( struct V_216 * V_217 ,
char * V_218 , char * V_219 , char * V_220 , int V_221 )
{
struct V_71 * V_72 = F_78 () ;
struct V_39 * V_57 ;
struct V_211 * V_212 ;
struct V_208 * V_56 ;
const char * system ;
const char * V_35 ;
char * V_222 ;
bool V_70 ;
int V_26 ;
if ( ! V_72 )
return - V_36 ;
if ( ! V_221 || ! V_220 )
return - V_105 ;
system = F_76 ( & V_220 , L_4 ) ;
if ( ! V_220 )
return - V_105 ;
V_35 = F_76 ( & V_220 , L_4 ) ;
F_42 ( & V_73 ) ;
V_26 = - V_105 ;
V_57 = F_180 ( V_72 , system , V_35 ) ;
if ( ! V_57 )
goto V_130;
V_70 = strcmp ( V_219 , V_213 ) == 0 ;
if ( V_70 )
V_212 = V_220 ? & V_223 : & V_224 ;
else
V_212 = V_220 ? & V_225 : & V_226 ;
if ( V_218 [ 0 ] == '!' ) {
F_188 ( V_218 + 1 , V_212 ) ;
V_26 = 0 ;
goto V_130;
}
V_26 = - V_23 ;
V_56 = F_128 ( sizeof( * V_56 ) , V_144 ) ;
if ( ! V_56 )
goto V_130;
V_56 -> V_70 = V_70 ;
V_56 -> V_210 = - 1 ;
V_56 -> V_57 = V_57 ;
if ( ! V_220 )
goto V_227;
V_222 = F_76 ( & V_220 , L_4 ) ;
V_26 = - V_105 ;
if ( ! strlen ( V_222 ) )
goto V_159;
V_26 = F_189 ( V_222 , 0 , & V_56 -> V_210 ) ;
if ( V_26 )
goto V_159;
V_227:
V_26 = F_190 ( V_57 -> V_6 -> V_176 ) ;
if ( ! V_26 ) {
V_26 = - V_195 ;
goto V_159;
}
V_26 = F_50 ( V_57 , 1 , 1 ) ;
if ( V_26 < 0 )
goto V_120;
V_26 = F_191 ( V_218 , V_212 , V_56 ) ;
if ( ! V_26 ) {
V_26 = - V_228 ;
goto V_229;
} else if ( V_26 < 0 )
goto V_229;
V_26 = 0 ;
V_130:
F_49 ( & V_73 ) ;
return V_26 ;
V_229:
F_50 ( V_57 , 0 , 1 ) ;
V_120:
F_186 ( V_57 -> V_6 -> V_176 ) ;
V_159:
F_60 ( V_56 ) ;
goto V_130;
}
static T_5 int F_192 ( void )
{
int V_26 ;
V_26 = F_193 ( & V_230 ) ;
if ( F_13 ( V_26 < 0 ) )
return V_26 ;
V_26 = F_193 ( & V_231 ) ;
if ( F_13 ( V_26 < 0 ) )
F_194 ( & V_230 ) ;
return V_26 ;
}
static inline int F_192 ( void ) { return 0 ; }
static T_5 void
F_195 ( struct V_71 * V_72 )
{
struct V_39 * V_57 ;
int V_26 ;
F_6 (file, &tr->events, list) {
V_26 = F_149 ( V_72 -> V_193 , V_57 ) ;
if ( V_26 < 0 )
F_146 ( L_31 ,
F_54 ( V_57 -> V_6 ) ) ;
}
}
static T_5 void
F_196 ( struct V_71 * V_72 )
{
struct V_5 * V_14 ;
int V_26 ;
F_6 (call, &ftrace_events, list) {
if ( F_59 ( V_14 -> V_176 ) )
continue;
V_26 = F_166 ( V_14 , V_72 ) ;
if ( V_26 < 0 )
F_146 ( L_36 ,
F_54 ( V_14 ) ) ;
}
}
static void
F_197 ( struct V_71 * V_72 )
{
struct V_39 * V_57 , * V_33 ;
F_19 (file, next, &tr->events, list)
F_67 ( V_57 ) ;
}
static void F_168 ( struct V_5 * V_14 )
{
struct V_71 * V_72 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_165 ( V_14 , V_72 ) ;
}
static T_5 int F_198 ( char * V_232 )
{
F_199 ( V_233 , V_232 , V_234 ) ;
V_235 = true ;
V_236 = true ;
return 1 ;
}
static int
F_200 ( struct V_97 * V_161 , struct V_71 * V_72 )
{
struct V_97 * V_166 ;
struct V_97 * V_45 ;
V_45 = F_147 ( L_37 , 0644 , V_161 ,
V_72 , & V_237 ) ;
if ( ! V_45 ) {
F_146 ( L_38 ) ;
return - V_23 ;
}
V_166 = F_145 ( L_39 , V_161 ) ;
if ( ! V_166 ) {
F_146 ( L_40 ) ;
return - V_23 ;
}
F_148 ( L_41 , 0444 , V_166 ,
V_238 ,
& V_239 ) ;
F_148 ( L_42 , 0444 , V_166 ,
V_240 ,
& V_239 ) ;
F_148 ( L_21 , 0644 , V_166 ,
V_72 , & V_241 ) ;
V_72 -> V_193 = V_166 ;
return 0 ;
}
int F_201 ( struct V_97 * V_161 , struct V_71 * V_72 )
{
int V_26 ;
F_42 ( & V_73 ) ;
V_26 = F_200 ( V_161 , V_72 ) ;
if ( V_26 )
goto V_242;
F_160 ( & V_190 ) ;
F_179 ( V_72 ) ;
F_161 ( & V_190 ) ;
V_242:
F_49 ( & V_73 ) ;
return V_26 ;
}
static T_5 int
F_202 ( struct V_97 * V_161 , struct V_71 * V_72 )
{
int V_26 ;
F_42 ( & V_73 ) ;
V_26 = F_200 ( V_161 , V_72 ) ;
if ( V_26 )
goto V_242;
F_160 ( & V_190 ) ;
F_195 ( V_72 ) ;
F_161 ( & V_190 ) ;
V_242:
F_49 ( & V_73 ) ;
return V_26 ;
}
int F_203 ( struct V_71 * V_72 )
{
F_42 ( & V_73 ) ;
F_204 ( V_72 ) ;
F_73 ( V_72 , NULL , NULL , NULL , 0 ) ;
F_205 () ;
F_160 ( & V_190 ) ;
F_197 ( V_72 ) ;
F_66 ( V_72 -> V_193 ) ;
F_161 ( & V_190 ) ;
V_72 -> V_193 = NULL ;
F_49 ( & V_73 ) ;
return 0 ;
}
static T_5 int F_206 ( void )
{
V_21 = F_207 ( V_10 , V_243 ) ;
V_101 = F_207 ( V_39 , V_243 ) ;
return 0 ;
}
static T_5 void
F_208 ( struct V_71 * V_72 , bool V_244 )
{
char * V_107 = V_233 ;
char * V_245 ;
int V_26 ;
while ( true ) {
V_245 = F_76 ( & V_107 , L_43 ) ;
if ( ! V_245 )
break;
if ( ! * V_245 )
continue;
if ( V_244 )
F_75 ( V_72 , V_245 , 0 ) ;
V_26 = F_75 ( V_72 , V_245 , 1 ) ;
if ( V_26 )
F_146 ( L_44 , V_245 ) ;
if ( V_107 )
* ( V_107 - 1 ) = ',' ;
}
}
static T_5 int F_209 ( void )
{
struct V_71 * V_72 = F_78 () ;
struct V_5 * * V_48 , * V_14 ;
int V_26 ;
if ( ! V_72 )
return - V_36 ;
F_175 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_14 = * V_48 ;
V_26 = F_155 ( V_14 ) ;
if ( ! V_26 )
F_11 ( & V_14 -> V_91 , & V_177 ) ;
}
F_196 ( V_72 ) ;
F_208 ( V_72 , false ) ;
F_210 () ;
F_192 () ;
F_211 () ;
return 0 ;
}
static T_5 int F_212 ( void )
{
struct V_71 * V_72 ;
V_72 = F_78 () ;
if ( ! V_72 )
return - V_36 ;
F_208 ( V_72 , true ) ;
return 0 ;
}
static T_5 int F_213 ( void )
{
struct V_71 * V_72 ;
struct V_97 * V_246 ;
struct V_97 * V_45 ;
int V_26 ;
V_72 = F_78 () ;
if ( ! V_72 )
return - V_36 ;
V_246 = F_214 () ;
if ( F_215 ( V_246 ) )
return 0 ;
V_45 = F_147 ( L_45 , 0444 , V_246 ,
V_72 , & V_247 ) ;
if ( ! V_45 )
F_146 ( L_46 ) ;
if ( F_14 () )
F_146 ( L_47 ) ;
if ( F_16 () )
F_146 ( L_48 ) ;
V_26 = F_202 ( V_246 , V_72 ) ;
if ( V_26 )
return V_26 ;
#ifdef F_216
V_26 = F_217 ( & V_248 ) ;
if ( V_26 )
F_146 ( L_49 ) ;
#endif
return 0 ;
}
void T_5 F_218 ( void )
{
F_206 () ;
F_219 () ;
F_209 () ;
}
static T_5 void F_220 ( struct V_249 * V_250 )
{
F_68 ( & V_251 ) ;
F_221 ( & V_252 ) ;
F_222 ( 1 ) ;
F_223 ( & V_252 ) ;
F_71 ( & V_251 ) ;
F_42 ( & V_253 ) ;
F_224 ( 1 ) ;
F_49 ( & V_253 ) ;
}
static T_5 int F_225 ( void * V_254 )
{
void * V_255 ;
V_255 = F_114 ( 1234 , V_144 ) ;
if ( ! V_255 )
F_53 ( L_50 ) ;
F_226 ( F_220 ) ;
F_60 ( V_255 ) ;
F_227 ( V_256 ) ;
while ( ! F_228 () ) {
F_229 () ;
F_227 ( V_256 ) ;
}
F_230 ( V_257 ) ;
return 0 ;
}
static T_5 void F_231 ( void )
{
struct V_258 * V_259 ;
V_259 = F_232 ( F_225 , NULL , L_51 ) ;
F_224 ( 1 ) ;
F_233 ( V_259 ) ;
}
static T_5 void F_234 ( void )
{
struct V_93 * V_94 ;
struct V_39 * V_57 ;
struct V_5 * V_14 ;
struct V_1 * system ;
struct V_71 * V_72 ;
int V_26 ;
V_72 = F_78 () ;
if ( ! V_72 )
return;
F_53 ( L_52 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_57 -> V_6 ;
if ( ! V_14 -> V_7 || ! V_14 -> V_7 -> V_61 )
continue;
#ifndef F_235
if ( V_14 -> V_7 -> system &&
strcmp ( V_14 -> V_7 -> system , L_53 ) == 0 )
continue;
#endif
F_53 ( L_54 , F_54 ( V_14 ) ) ;
if ( V_57 -> V_42 & V_74 ) {
F_146 ( L_55 ) ;
F_59 ( 1 ) ;
continue;
}
F_56 ( V_57 , 1 ) ;
F_231 () ;
F_56 ( V_57 , 0 ) ;
F_236 ( L_56 ) ;
}
F_53 ( L_57 ) ;
F_6 (dir, &tr->systems, list) {
system = V_94 -> V_95 ;
if ( strcmp ( system -> V_12 , L_58 ) == 0 )
continue;
F_53 ( L_59 , system -> V_12 ) ;
V_26 = F_74 ( V_72 , NULL , system -> V_12 , NULL , 1 ) ;
if ( F_59 ( V_26 ) ) {
F_146 ( L_60 ,
system -> V_12 ) ;
continue;
}
F_231 () ;
V_26 = F_74 ( V_72 , NULL , system -> V_12 , NULL , 0 ) ;
if ( F_59 ( V_26 ) ) {
F_146 ( L_61 ,
system -> V_12 ) ;
continue;
}
F_236 ( L_56 ) ;
}
F_53 ( L_62 ) ;
F_53 ( L_63 ) ;
V_26 = F_74 ( V_72 , NULL , NULL , NULL , 1 ) ;
if ( F_59 ( V_26 ) ) {
F_146 ( L_64 ) ;
return;
}
F_231 () ;
V_26 = F_74 ( V_72 , NULL , NULL , NULL , 0 ) ;
if ( F_59 ( V_26 ) ) {
F_146 ( L_65 ) ;
return;
}
F_236 ( L_56 ) ;
}
static void
F_237 ( unsigned long V_205 , unsigned long V_206 ,
struct V_260 * V_261 , struct V_262 * V_262 )
{
struct V_263 * V_35 ;
struct V_264 * V_44 ;
struct V_265 * V_45 ;
unsigned long V_42 ;
long V_266 ;
int V_27 ;
int V_43 ;
V_43 = F_26 () ;
F_238 () ;
V_27 = F_239 () ;
V_266 = F_52 ( & F_240 ( V_267 , V_27 ) ) ;
if ( V_266 != 1 )
goto V_130;
F_25 ( V_42 ) ;
V_35 = F_241 ( & V_44 ,
V_268 , sizeof( * V_45 ) ,
V_42 , V_43 ) ;
if ( ! V_35 )
goto V_130;
V_45 = F_28 ( V_35 ) ;
V_45 -> V_205 = V_205 ;
V_45 -> V_206 = V_206 ;
F_242 ( V_44 , V_35 , V_42 , V_43 ) ;
V_130:
F_243 ( & F_240 ( V_267 , V_27 ) ) ;
F_244 () ;
}
static T_5 void F_245 ( void )
{
int V_26 ;
V_26 = F_246 ( & V_269 ) ;
if ( F_13 ( V_26 < 0 ) ) {
F_53 ( L_66 ) ;
return;
}
F_53 ( L_67 ) ;
F_234 () ;
F_247 ( & V_269 ) ;
}
static T_5 void F_245 ( void )
{
}
static T_5 int F_248 ( void )
{
if ( ! V_236 ) {
F_234 () ;
F_245 () ;
}
return 0 ;
}
