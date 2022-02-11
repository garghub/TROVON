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
V_11 = F_4 ( V_14 ) ;
return F_5 ( V_11 , V_12 ) ;
}
static int F_8 ( struct V_4 * V_11 , const char * type ,
const char * V_12 , int V_16 , int V_17 ,
int V_18 , int V_19 )
{
struct V_10 * V_13 ;
V_13 = F_9 ( V_20 , V_21 ) ;
if ( ! V_13 )
return - V_22 ;
V_13 -> V_12 = V_12 ;
V_13 -> type = type ;
if ( V_19 == V_23 )
V_13 -> V_19 = F_10 ( type ) ;
else
V_13 -> V_19 = V_19 ;
V_13 -> V_16 = V_16 ;
V_13 -> V_17 = V_17 ;
V_13 -> V_18 = V_18 ;
F_11 ( & V_13 -> V_24 , V_11 ) ;
return 0 ;
}
int F_12 ( struct V_5 * V_14 , const char * type ,
const char * V_12 , int V_16 , int V_17 , int V_18 ,
int V_19 )
{
struct V_4 * V_11 ;
if ( F_13 ( ! V_14 -> V_7 ) )
return 0 ;
V_11 = F_4 ( V_14 ) ;
return F_8 ( V_11 , type , V_12 , V_16 , V_17 ,
V_18 , V_19 ) ;
}
static int F_14 ( void )
{
int V_25 ;
struct V_26 V_27 ;
F_15 (unsigned short, type) ;
F_15 (unsigned char, flags) ;
F_15 (unsigned char, preempt_count) ;
F_15 ( int , V_28 ) ;
return V_25 ;
}
static void F_16 ( struct V_5 * V_14 )
{
struct V_10 * V_13 , * V_29 ;
struct V_4 * V_11 ;
V_11 = F_4 ( V_14 ) ;
F_17 (field, next, head, link) {
F_18 ( & V_13 -> V_24 ) ;
F_19 ( V_20 , V_13 ) ;
}
}
int F_20 ( struct V_5 * V_14 )
{
int V_30 ;
V_30 = F_21 ( & V_14 -> V_31 ) ;
if ( ! V_30 )
return - V_32 ;
return 0 ;
}
void * F_22 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
unsigned long V_37 )
{
struct V_5 * V_6 = V_36 -> V_6 ;
F_23 ( V_34 -> V_38 ) ;
V_34 -> V_39 = F_24 () ;
V_34 -> V_36 = V_36 ;
V_34 -> V_31 =
F_25 ( & V_34 -> V_40 , V_36 ,
V_6 -> V_31 . type , V_37 ,
V_34 -> V_38 , V_34 -> V_39 ) ;
if ( ! V_34 -> V_31 )
return NULL ;
V_34 -> V_41 = F_26 ( V_34 -> V_31 ) ;
return V_34 -> V_41 ;
}
static void F_27 ( struct V_33 * V_34 )
{
struct V_5 * V_6 ;
struct V_42 * V_31 ;
unsigned long V_38 ;
struct V_43 * V_44 = V_45 ;
if ( ! V_44 )
return;
V_6 = V_34 -> V_36 -> V_6 ;
if ( ! V_6 || ! V_6 -> V_31 . V_46 ||
! V_6 -> V_31 . V_46 -> V_47 )
return;
V_31 = & V_34 -> V_36 -> V_6 -> V_31 ;
F_28 ( & V_48 , V_38 ) ;
F_29 ( & V_44 -> V_49 ) ;
V_44 -> V_27 = V_34 -> V_41 ;
V_6 -> V_31 . V_46 -> V_47 ( V_44 , 0 , V_31 ) ;
F_30 ( & V_44 -> V_49 , 0 ) ;
F_31 ( L_1 , V_44 -> V_49 . V_40 ) ;
F_32 ( & V_48 , V_38 ) ;
}
void F_33 ( struct V_33 * V_34 )
{
if ( V_50 )
F_27 ( V_34 ) ;
F_34 ( V_34 -> V_36 , V_34 -> V_40 ,
V_34 -> V_31 , V_34 -> V_41 ,
V_34 -> V_38 , V_34 -> V_39 ) ;
}
int F_35 ( struct V_5 * V_14 ,
enum V_51 type , void * V_52 )
{
struct V_35 * V_53 = V_52 ;
F_13 ( ! ( V_14 -> V_38 & V_54 ) ) ;
switch ( type ) {
case V_55 :
return F_36 ( V_14 -> V_56 ,
V_14 -> V_7 -> V_57 ,
V_53 ) ;
case V_58 :
F_37 ( V_14 -> V_56 ,
V_14 -> V_7 -> V_57 ,
V_53 ) ;
return 0 ;
#ifdef F_38
case V_59 :
return F_36 ( V_14 -> V_56 ,
V_14 -> V_7 -> V_60 ,
V_14 ) ;
case V_61 :
F_37 ( V_14 -> V_56 ,
V_14 -> V_7 -> V_60 ,
V_14 ) ;
return 0 ;
case V_62 :
case V_63 :
case V_64 :
case V_65 :
return 0 ;
#endif
}
return 0 ;
}
void F_39 ( bool V_66 )
{
struct V_35 * V_53 ;
struct V_67 * V_68 ;
F_40 ( & V_69 ) ;
F_41 (tr, file) {
if ( ! ( V_53 -> V_38 & V_70 ) )
continue;
if ( V_66 ) {
F_42 () ;
F_43 ( V_71 , & V_53 -> V_38 ) ;
} else {
F_44 () ;
F_45 ( V_71 , & V_53 -> V_38 ) ;
}
} F_46 () ;
F_47 ( & V_69 ) ;
}
static int F_48 ( struct V_35 * V_53 ,
int V_66 , int V_72 )
{
struct V_5 * V_14 = V_53 -> V_6 ;
int V_25 = 0 ;
int V_73 ;
switch ( V_66 ) {
case 0 :
if ( V_72 ) {
if ( F_49 ( & V_53 -> V_74 ) > 0 )
break;
V_73 = V_53 -> V_38 & V_75 ;
F_45 ( V_76 , & V_53 -> V_38 ) ;
} else
V_73 = ! ( V_53 -> V_38 & V_77 ) ;
if ( V_73 && ( V_53 -> V_38 & V_70 ) ) {
F_45 ( V_78 , & V_53 -> V_38 ) ;
if ( V_53 -> V_38 & V_79 ) {
F_44 () ;
F_45 ( V_71 , & V_53 -> V_38 ) ;
}
V_14 -> V_7 -> V_80 ( V_14 , V_58 , V_53 ) ;
}
if ( V_53 -> V_38 & V_77 )
F_43 ( V_81 , & V_53 -> V_38 ) ;
else
F_45 ( V_81 , & V_53 -> V_38 ) ;
break;
case 1 :
if ( ! V_72 )
F_45 ( V_81 , & V_53 -> V_38 ) ;
else {
if ( F_50 ( & V_53 -> V_74 ) > 1 )
break;
F_43 ( V_76 , & V_53 -> V_38 ) ;
}
if ( ! ( V_53 -> V_38 & V_70 ) ) {
if ( V_72 )
F_43 ( V_81 , & V_53 -> V_38 ) ;
if ( V_82 & V_83 ) {
F_42 () ;
F_43 ( V_71 , & V_53 -> V_38 ) ;
}
V_25 = V_14 -> V_7 -> V_80 ( V_14 , V_55 , V_53 ) ;
if ( V_25 ) {
F_44 () ;
F_51 ( L_2
L_3 , F_52 ( V_14 ) ) ;
break;
}
F_43 ( V_78 , & V_53 -> V_38 ) ;
V_14 -> V_38 |= V_84 ;
}
break;
}
return V_25 ;
}
int F_53 ( struct V_35 * V_53 ,
int V_66 , int V_72 )
{
return F_48 ( V_53 , V_66 , V_72 ) ;
}
static int F_54 ( struct V_35 * V_53 ,
int V_66 )
{
return F_48 ( V_53 , V_66 , 0 ) ;
}
static void F_55 ( struct V_67 * V_68 )
{
struct V_35 * V_53 ;
F_40 ( & V_69 ) ;
F_6 (file, &tr->events, list) {
F_54 ( V_53 , 0 ) ;
}
F_47 ( & V_69 ) ;
}
static void F_56 ( struct V_1 * system )
{
struct V_85 * V_86 = system -> V_86 ;
F_57 ( F_1 ( system ) == 0 ) ;
if ( F_3 ( system ) )
return;
F_18 ( & system -> V_87 ) ;
if ( V_86 ) {
F_58 ( V_86 -> V_88 ) ;
F_58 ( V_86 ) ;
}
if ( system -> V_2 & V_3 )
F_58 ( system -> V_12 ) ;
F_58 ( system ) ;
}
static void F_59 ( struct V_1 * system )
{
F_57 ( F_1 ( system ) == 0 ) ;
F_2 ( system ) ;
}
static void F_60 ( struct V_89 * V_90 )
{
F_57 ( V_90 -> V_2 == 0 ) ;
V_90 -> V_2 ++ ;
F_59 ( V_90 -> V_91 ) ;
}
static void F_61 ( struct V_89 * V_90 )
{
F_57 ( V_90 -> V_2 == 0 ) ;
F_57 ( F_1 ( V_90 -> V_91 ) == 1 && V_90 -> V_2 != 1 ) ;
F_56 ( V_90 -> V_91 ) ;
if ( ! -- V_90 -> V_2 )
F_58 ( V_90 ) ;
}
static void F_62 ( struct V_89 * V_90 )
{
F_40 ( & V_69 ) ;
F_61 ( V_90 ) ;
F_47 ( & V_69 ) ;
}
static void F_63 ( struct V_89 * V_90 )
{
if ( ! V_90 )
return;
if ( ! -- V_90 -> V_92 ) {
F_64 ( V_90 -> V_41 ) ;
F_18 ( & V_90 -> V_87 ) ;
F_61 ( V_90 ) ;
}
}
static void F_65 ( struct V_35 * V_53 )
{
struct V_93 * V_90 = V_53 -> V_90 ;
struct V_93 * V_94 ;
if ( V_90 ) {
F_66 ( & V_90 -> V_95 ) ;
F_6 (child, &dir->d_subdirs, d_child) {
if ( V_94 -> V_96 )
V_94 -> V_96 -> V_97 = NULL ;
}
F_67 ( & V_90 -> V_95 ) ;
F_64 ( V_90 ) ;
}
F_18 ( & V_53 -> V_87 ) ;
F_63 ( V_53 -> system ) ;
F_68 ( V_53 -> V_86 ) ;
F_19 ( V_98 , V_53 ) ;
}
static int
F_69 ( struct V_67 * V_68 , const char * V_99 ,
const char * V_100 , const char * V_31 , int V_101 )
{
struct V_35 * V_53 ;
struct V_5 * V_14 ;
const char * V_12 ;
int V_25 = - V_102 ;
F_6 (file, &tr->events, list) {
V_14 = V_53 -> V_6 ;
V_12 = F_52 ( V_14 ) ;
if ( ! V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_80 )
continue;
if ( V_14 -> V_38 & V_103 )
continue;
if ( V_99 &&
strcmp ( V_99 , V_12 ) != 0 &&
strcmp ( V_99 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_100 && strcmp ( V_100 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_31 && strcmp ( V_31 , V_12 ) != 0 )
continue;
F_54 ( V_53 , V_101 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static int F_70 ( struct V_67 * V_68 , const char * V_99 ,
const char * V_100 , const char * V_31 , int V_101 )
{
int V_25 ;
F_40 ( & V_69 ) ;
V_25 = F_69 ( V_68 , V_99 , V_100 , V_31 , V_101 ) ;
F_47 ( & V_69 ) ;
return V_25 ;
}
static int F_71 ( struct V_67 * V_68 , char * V_104 , int V_101 )
{
char * V_31 = NULL , * V_100 = NULL , * V_99 ;
V_99 = F_72 ( & V_104 , L_4 ) ;
if ( V_104 ) {
V_100 = V_99 ;
V_31 = V_104 ;
V_99 = NULL ;
if ( ! strlen ( V_100 ) || strcmp ( V_100 , L_5 ) == 0 )
V_100 = NULL ;
if ( ! strlen ( V_31 ) || strcmp ( V_31 , L_5 ) == 0 )
V_31 = NULL ;
}
return F_70 ( V_68 , V_99 , V_100 , V_31 , V_101 ) ;
}
int F_73 ( const char * system , const char * V_31 , int V_101 )
{
struct V_67 * V_68 = F_74 () ;
if ( ! V_68 )
return - V_32 ;
return F_70 ( V_68 , NULL , system , V_31 , V_101 ) ;
}
static T_1
F_75 ( struct V_53 * V_53 , const char T_2 * V_105 ,
T_3 V_106 , T_4 * V_107 )
{
struct V_108 V_109 ;
struct V_110 * V_111 = V_53 -> V_112 ;
struct V_67 * V_68 = V_111 -> V_113 ;
T_1 V_114 , V_25 ;
if ( ! V_106 )
return 0 ;
V_25 = F_76 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_77 ( & V_109 , V_115 + 1 ) )
return - V_22 ;
V_114 = F_78 ( & V_109 , V_105 , V_106 , V_107 ) ;
if ( V_114 >= 0 && F_79 ( ( & V_109 ) ) ) {
int V_101 = 1 ;
if ( * V_109 . V_40 == '!' )
V_101 = 0 ;
V_109 . V_40 [ V_109 . V_116 ] = 0 ;
V_25 = F_71 ( V_68 , V_109 . V_40 + ! V_101 , V_101 ) ;
if ( V_25 )
goto V_117;
}
V_25 = V_114 ;
V_117:
F_80 ( & V_109 ) ;
return V_25 ;
}
static void *
F_81 ( struct V_110 * V_111 , void * V_118 , T_4 * V_119 )
{
struct V_35 * V_53 = V_118 ;
struct V_5 * V_14 ;
struct V_67 * V_68 = V_111 -> V_113 ;
( * V_119 ) ++ ;
F_82 (file, &tr->events, list) {
V_14 = V_53 -> V_6 ;
if ( V_14 -> V_7 && V_14 -> V_7 -> V_80 )
return V_53 ;
}
return NULL ;
}
static void * F_83 ( struct V_110 * V_111 , T_4 * V_119 )
{
struct V_35 * V_53 ;
struct V_67 * V_68 = V_111 -> V_113 ;
T_4 V_120 ;
F_40 ( & V_69 ) ;
V_53 = F_84 ( & V_68 -> V_121 , struct V_35 , V_87 ) ;
for ( V_120 = 0 ; V_120 <= * V_119 ; ) {
V_53 = F_81 ( V_111 , V_53 , & V_120 ) ;
if ( ! V_53 )
break;
}
return V_53 ;
}
static void *
F_85 ( struct V_110 * V_111 , void * V_118 , T_4 * V_119 )
{
struct V_35 * V_53 = V_118 ;
struct V_67 * V_68 = V_111 -> V_113 ;
( * V_119 ) ++ ;
F_82 (file, &tr->events, list) {
if ( V_53 -> V_38 & V_70 )
return V_53 ;
}
return NULL ;
}
static void * F_86 ( struct V_110 * V_111 , T_4 * V_119 )
{
struct V_35 * V_53 ;
struct V_67 * V_68 = V_111 -> V_113 ;
T_4 V_120 ;
F_40 ( & V_69 ) ;
V_53 = F_84 ( & V_68 -> V_121 , struct V_35 , V_87 ) ;
for ( V_120 = 0 ; V_120 <= * V_119 ; ) {
V_53 = F_85 ( V_111 , V_53 , & V_120 ) ;
if ( ! V_53 )
break;
}
return V_53 ;
}
static int F_87 ( struct V_110 * V_111 , void * V_118 )
{
struct V_35 * V_53 = V_118 ;
struct V_5 * V_14 = V_53 -> V_6 ;
if ( strcmp ( V_14 -> V_7 -> system , V_122 ) != 0 )
F_88 ( V_111 , L_6 , V_14 -> V_7 -> system ) ;
F_88 ( V_111 , L_3 , F_52 ( V_14 ) ) ;
return 0 ;
}
static void F_89 ( struct V_110 * V_111 , void * V_123 )
{
F_47 ( & V_69 ) ;
}
static T_1
F_90 ( struct V_53 * V_124 , char T_2 * V_105 , T_3 V_106 ,
T_4 * V_107 )
{
struct V_35 * V_53 ;
unsigned long V_38 ;
char V_104 [ 4 ] = L_7 ;
F_40 ( & V_69 ) ;
V_53 = F_91 ( V_124 ) ;
if ( F_92 ( V_53 ) )
V_38 = V_53 -> V_38 ;
F_47 ( & V_69 ) ;
if ( ! V_53 )
return - V_32 ;
if ( V_38 & V_70 &&
! ( V_38 & V_75 ) )
strcpy ( V_104 , L_8 ) ;
if ( V_38 & V_75 ||
V_38 & V_77 )
strcat ( V_104 , L_5 ) ;
strcat ( V_104 , L_9 ) ;
return F_93 ( V_105 , V_106 , V_107 , V_104 , strlen ( V_104 ) ) ;
}
static T_1
F_94 ( struct V_53 * V_124 , const char T_2 * V_105 , T_3 V_106 ,
T_4 * V_107 )
{
struct V_35 * V_53 ;
unsigned long V_125 ;
int V_25 ;
V_25 = F_95 ( V_105 , V_106 , 10 , & V_125 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_76 () ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_125 ) {
case 0 :
case 1 :
V_25 = - V_32 ;
F_40 ( & V_69 ) ;
V_53 = F_91 ( V_124 ) ;
if ( F_92 ( V_53 ) )
V_25 = F_54 ( V_53 , V_125 ) ;
F_47 ( & V_69 ) ;
break;
default:
return - V_102 ;
}
* V_107 += V_106 ;
return V_25 ? V_25 : V_106 ;
}
static T_1
F_96 ( struct V_53 * V_124 , char T_2 * V_105 , T_3 V_106 ,
T_4 * V_107 )
{
const char V_126 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_89 * V_90 = V_124 -> V_112 ;
struct V_1 * system = V_90 -> V_91 ;
struct V_5 * V_14 ;
struct V_35 * V_53 ;
struct V_67 * V_68 = V_90 -> V_68 ;
char V_104 [ 2 ] ;
int V_101 = 0 ;
int V_25 ;
F_40 ( & V_69 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_53 -> V_6 ;
if ( ! F_52 ( V_14 ) || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_80 )
continue;
if ( system && strcmp ( V_14 -> V_7 -> system , system -> V_12 ) != 0 )
continue;
V_101 |= ( 1 << ! ! ( V_53 -> V_38 & V_70 ) ) ;
if ( V_101 == 3 )
break;
}
F_47 ( & V_69 ) ;
V_104 [ 0 ] = V_126 [ V_101 ] ;
V_104 [ 1 ] = '\n' ;
V_25 = F_93 ( V_105 , V_106 , V_107 , V_104 , 2 ) ;
return V_25 ;
}
static T_1
F_97 ( struct V_53 * V_124 , const char T_2 * V_105 , T_3 V_106 ,
T_4 * V_107 )
{
struct V_89 * V_90 = V_124 -> V_112 ;
struct V_1 * system = V_90 -> V_91 ;
const char * V_12 = NULL ;
unsigned long V_125 ;
T_1 V_25 ;
V_25 = F_95 ( V_105 , V_106 , 10 , & V_125 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_76 () ;
if ( V_25 < 0 )
return V_25 ;
if ( V_125 != 0 && V_125 != 1 )
return - V_102 ;
if ( system )
V_12 = system -> V_12 ;
V_25 = F_70 ( V_90 -> V_68 , NULL , V_12 , NULL , V_125 ) ;
if ( V_25 )
goto V_127;
V_25 = V_106 ;
V_127:
* V_107 += V_106 ;
return V_25 ;
}
static void * F_98 ( struct V_110 * V_111 , void * V_118 , T_4 * V_119 )
{
struct V_5 * V_14 = F_91 ( V_111 -> V_113 ) ;
struct V_4 * V_128 = & V_15 ;
struct V_4 * V_11 = F_4 ( V_14 ) ;
struct V_4 * V_129 = V_118 ;
( * V_119 ) ++ ;
switch ( ( unsigned long ) V_118 ) {
case V_130 :
V_129 = V_128 ;
break;
case V_131 :
V_129 = V_11 ;
break;
case V_132 :
return NULL ;
}
V_129 = V_129 -> V_133 ;
if ( V_129 == V_128 )
return ( void * ) V_131 ;
else if ( V_129 == V_11 )
return ( void * ) V_132 ;
else
return V_129 ;
}
static int F_99 ( struct V_110 * V_111 , void * V_118 )
{
struct V_5 * V_14 = F_91 ( V_111 -> V_113 ) ;
struct V_10 * V_13 ;
const char * V_134 ;
switch ( ( unsigned long ) V_118 ) {
case V_130 :
F_88 ( V_111 , L_10 , F_52 ( V_14 ) ) ;
F_88 ( V_111 , L_11 , V_14 -> V_31 . type ) ;
F_100 ( V_111 , L_12 ) ;
return 0 ;
case V_131 :
F_101 ( V_111 , '\n' ) ;
return 0 ;
case V_132 :
F_88 ( V_111 , L_13 ,
V_14 -> V_135 ) ;
return 0 ;
}
V_13 = F_84 ( V_118 , struct V_10 , V_24 ) ;
V_134 = strchr ( V_13 -> type , '[' ) ;
if ( ! strncmp ( V_13 -> type , L_14 , 10 ) )
V_134 = NULL ;
if ( ! V_134 )
F_88 ( V_111 , L_15 ,
V_13 -> type , V_13 -> V_12 , V_13 -> V_16 ,
V_13 -> V_17 , ! ! V_13 -> V_18 ) ;
else
F_88 ( V_111 , L_16 ,
( int ) ( V_134 - V_13 -> type ) ,
V_13 -> type , V_13 -> V_12 ,
V_134 , V_13 -> V_16 ,
V_13 -> V_17 , ! ! V_13 -> V_18 ) ;
return 0 ;
}
static void * F_102 ( struct V_110 * V_111 , T_4 * V_119 )
{
void * V_123 = ( void * ) V_130 ;
T_4 V_120 = 0 ;
F_40 ( & V_69 ) ;
if ( ! F_91 ( V_111 -> V_113 ) )
return F_103 ( - V_32 ) ;
while ( V_120 < * V_119 && V_123 )
V_123 = F_98 ( V_111 , V_123 , & V_120 ) ;
return V_123 ;
}
static void F_104 ( struct V_110 * V_111 , void * V_123 )
{
F_47 ( & V_69 ) ;
}
static int F_105 ( struct V_136 * V_136 , struct V_53 * V_53 )
{
struct V_110 * V_111 ;
int V_25 ;
V_25 = F_106 ( V_53 , & V_137 ) ;
if ( V_25 < 0 )
return V_25 ;
V_111 = V_53 -> V_112 ;
V_111 -> V_113 = V_53 ;
return 0 ;
}
static T_1
F_107 ( struct V_53 * V_124 , char T_2 * V_105 , T_3 V_106 , T_4 * V_107 )
{
int V_30 = ( long ) F_91 ( V_124 ) ;
char V_104 [ 32 ] ;
int V_37 ;
if ( * V_107 )
return 0 ;
if ( F_108 ( ! V_30 ) )
return - V_32 ;
V_37 = sprintf ( V_104 , L_17 , V_30 ) ;
return F_93 ( V_105 , V_106 , V_107 , V_104 , V_37 ) ;
}
static T_1
F_109 ( struct V_53 * V_124 , char T_2 * V_105 , T_3 V_106 ,
T_4 * V_107 )
{
struct V_35 * V_53 ;
struct V_138 * V_139 ;
int V_140 = - V_32 ;
if ( * V_107 )
return 0 ;
V_139 = F_110 ( sizeof( * V_139 ) , V_141 ) ;
if ( ! V_139 )
return - V_22 ;
F_29 ( V_139 ) ;
F_40 ( & V_69 ) ;
V_53 = F_91 ( V_124 ) ;
if ( V_53 )
F_111 ( V_53 , V_139 ) ;
F_47 ( & V_69 ) ;
if ( V_53 )
V_140 = F_93 ( V_105 , V_106 , V_107 ,
V_139 -> V_40 , F_112 ( V_139 ) ) ;
F_58 ( V_139 ) ;
return V_140 ;
}
static T_1
F_113 ( struct V_53 * V_124 , const char T_2 * V_105 , T_3 V_106 ,
T_4 * V_107 )
{
struct V_35 * V_53 ;
char * V_104 ;
int V_142 = - V_32 ;
if ( V_106 >= V_143 )
return - V_102 ;
V_104 = ( char * ) F_114 ( V_144 ) ;
if ( ! V_104 )
return - V_22 ;
if ( F_115 ( V_104 , V_105 , V_106 ) ) {
F_116 ( ( unsigned long ) V_104 ) ;
return - V_145 ;
}
V_104 [ V_106 ] = '\0' ;
F_40 ( & V_69 ) ;
V_53 = F_91 ( V_124 ) ;
if ( V_53 )
V_142 = F_117 ( V_53 , V_104 ) ;
F_47 ( & V_69 ) ;
F_116 ( ( unsigned long ) V_104 ) ;
if ( V_142 < 0 )
return V_142 ;
* V_107 += V_106 ;
return V_106 ;
}
static int F_118 ( struct V_136 * V_136 , struct V_53 * V_124 )
{
struct V_1 * system = NULL ;
struct V_89 * V_90 = NULL ;
struct V_67 * V_68 ;
int V_25 ;
if ( F_119 () )
return - V_32 ;
F_40 ( & V_146 ) ;
F_40 ( & V_69 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_90 == V_136 -> V_97 ) {
if ( V_90 -> V_92 ) {
F_60 ( V_90 ) ;
system = V_90 -> V_91 ;
}
goto V_147;
}
}
}
V_147:
F_47 ( & V_69 ) ;
F_47 ( & V_146 ) ;
if ( ! system )
return - V_32 ;
F_13 ( ! V_90 ) ;
if ( F_120 ( V_68 ) < 0 ) {
F_62 ( V_90 ) ;
return - V_32 ;
}
V_25 = F_121 ( V_136 , V_124 ) ;
if ( V_25 < 0 ) {
F_122 ( V_68 ) ;
F_62 ( V_90 ) ;
}
return V_25 ;
}
static int F_123 ( struct V_136 * V_136 , struct V_53 * V_124 )
{
struct V_89 * V_90 ;
struct V_67 * V_68 = V_136 -> V_97 ;
int V_25 ;
if ( F_119 () )
return - V_32 ;
if ( F_120 ( V_68 ) < 0 )
return - V_32 ;
V_90 = F_124 ( sizeof( * V_90 ) , V_141 ) ;
if ( ! V_90 ) {
F_122 ( V_68 ) ;
return - V_22 ;
}
V_90 -> V_68 = V_68 ;
V_25 = F_121 ( V_136 , V_124 ) ;
if ( V_25 < 0 ) {
F_122 ( V_68 ) ;
F_58 ( V_90 ) ;
return V_25 ;
}
V_124 -> V_112 = V_90 ;
return 0 ;
}
static int F_125 ( struct V_136 * V_136 , struct V_53 * V_53 )
{
struct V_89 * V_90 = V_53 -> V_112 ;
F_122 ( V_90 -> V_68 ) ;
if ( V_90 -> V_91 )
F_62 ( V_90 ) ;
else
F_58 ( V_90 ) ;
return 0 ;
}
static T_1
F_126 ( struct V_53 * V_124 , char T_2 * V_105 , T_3 V_106 ,
T_4 * V_107 )
{
struct V_89 * V_90 = V_124 -> V_112 ;
struct V_1 * system = V_90 -> V_91 ;
struct V_138 * V_139 ;
int V_140 ;
if ( * V_107 )
return 0 ;
V_139 = F_110 ( sizeof( * V_139 ) , V_141 ) ;
if ( ! V_139 )
return - V_22 ;
F_29 ( V_139 ) ;
F_127 ( system , V_139 ) ;
V_140 = F_93 ( V_105 , V_106 , V_107 ,
V_139 -> V_40 , F_112 ( V_139 ) ) ;
F_58 ( V_139 ) ;
return V_140 ;
}
static T_1
F_128 ( struct V_53 * V_124 , const char T_2 * V_105 , T_3 V_106 ,
T_4 * V_107 )
{
struct V_89 * V_90 = V_124 -> V_112 ;
char * V_104 ;
int V_142 ;
if ( V_106 >= V_143 )
return - V_102 ;
V_104 = ( char * ) F_114 ( V_144 ) ;
if ( ! V_104 )
return - V_22 ;
if ( F_115 ( V_104 , V_105 , V_106 ) ) {
F_116 ( ( unsigned long ) V_104 ) ;
return - V_145 ;
}
V_104 [ V_106 ] = '\0' ;
V_142 = F_129 ( V_90 , V_104 ) ;
F_116 ( ( unsigned long ) V_104 ) ;
if ( V_142 < 0 )
return V_142 ;
* V_107 += V_106 ;
return V_106 ;
}
static T_1
F_130 ( struct V_53 * V_124 , char T_2 * V_105 , T_3 V_106 , T_4 * V_107 )
{
int (* F_131)( struct V_138 * V_139 ) = V_124 -> V_112 ;
struct V_138 * V_139 ;
int V_140 ;
if ( * V_107 )
return 0 ;
V_139 = F_110 ( sizeof( * V_139 ) , V_141 ) ;
if ( ! V_139 )
return - V_22 ;
F_29 ( V_139 ) ;
F_131 ( V_139 ) ;
V_140 = F_93 ( V_105 , V_106 , V_107 ,
V_139 -> V_40 , F_112 ( V_139 ) ) ;
F_58 ( V_139 ) ;
return V_140 ;
}
static int
F_132 ( struct V_136 * V_136 , struct V_53 * V_53 ,
const struct V_148 * V_149 )
{
struct V_110 * V_111 ;
int V_25 ;
V_25 = F_106 ( V_53 , V_149 ) ;
if ( V_25 < 0 )
return V_25 ;
V_111 = V_53 -> V_112 ;
V_111 -> V_113 = V_136 -> V_97 ;
return V_25 ;
}
static int F_133 ( struct V_136 * V_136 , struct V_53 * V_53 )
{
struct V_67 * V_68 = V_136 -> V_97 ;
F_122 ( V_68 ) ;
return F_134 ( V_136 , V_53 ) ;
}
static int
F_135 ( struct V_136 * V_136 , struct V_53 * V_53 )
{
const struct V_148 * V_149 = & V_150 ;
return F_132 ( V_136 , V_53 , V_149 ) ;
}
static int
F_136 ( struct V_136 * V_136 , struct V_53 * V_53 )
{
const struct V_148 * V_149 = & V_151 ;
struct V_67 * V_68 = V_136 -> V_97 ;
int V_25 ;
if ( F_120 ( V_68 ) < 0 )
return - V_32 ;
if ( ( V_53 -> V_152 & V_153 ) &&
( V_53 -> V_154 & V_155 ) )
F_55 ( V_68 ) ;
V_25 = F_132 ( V_136 , V_53 , V_149 ) ;
if ( V_25 < 0 )
F_122 ( V_68 ) ;
return V_25 ;
}
static struct V_1 *
F_137 ( const char * V_12 )
{
struct V_1 * system ;
system = F_110 ( sizeof( * system ) , V_141 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
if ( ! F_138 ( ( unsigned long ) V_12 ) ) {
system -> V_2 |= V_3 ;
system -> V_12 = F_139 ( V_12 , V_141 ) ;
if ( ! system -> V_12 )
goto V_156;
} else
system -> V_12 = V_12 ;
system -> V_86 = NULL ;
system -> V_86 = F_124 ( sizeof( struct V_85 ) , V_141 ) ;
if ( ! system -> V_86 )
goto V_156;
F_11 ( & system -> V_87 , & V_157 ) ;
return system ;
V_156:
if ( system -> V_2 & V_3 )
F_58 ( system -> V_12 ) ;
F_58 ( system ) ;
return NULL ;
}
static struct V_93 *
F_140 ( struct V_67 * V_68 , const char * V_12 ,
struct V_35 * V_53 , struct V_93 * V_158 )
{
struct V_89 * V_90 ;
struct V_1 * system ;
struct V_93 * V_41 ;
F_6 (dir, &tr->systems, list) {
system = V_90 -> V_91 ;
if ( strcmp ( system -> V_12 , V_12 ) == 0 ) {
V_90 -> V_92 ++ ;
V_53 -> system = V_90 ;
return V_90 -> V_41 ;
}
}
F_6 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_12 , V_12 ) == 0 )
break;
}
if ( & system -> V_87 == & V_157 )
system = NULL ;
V_90 = F_110 ( sizeof( * V_90 ) , V_141 ) ;
if ( ! V_90 )
goto V_159;
if ( ! system ) {
system = F_137 ( V_12 ) ;
if ( ! system )
goto V_156;
} else
F_59 ( system ) ;
V_90 -> V_41 = F_141 ( V_12 , V_158 ) ;
if ( ! V_90 -> V_41 ) {
F_142 ( L_18 , V_12 ) ;
F_56 ( system ) ;
goto V_156;
}
V_90 -> V_68 = V_68 ;
V_90 -> V_2 = 1 ;
V_90 -> V_92 = 1 ;
V_90 -> V_91 = system ;
V_53 -> system = V_90 ;
V_41 = F_143 ( L_19 , 0644 , V_90 -> V_41 , V_90 ,
& V_160 ) ;
if ( ! V_41 ) {
F_58 ( system -> V_86 ) ;
system -> V_86 = NULL ;
F_142 ( L_20 , V_12 ) ;
}
F_144 ( L_21 , 0644 , V_90 -> V_41 , V_90 ,
& V_161 ) ;
F_11 ( & V_90 -> V_87 , & V_68 -> V_162 ) ;
return V_90 -> V_41 ;
V_156:
F_58 ( V_90 ) ;
V_159:
if ( ! V_90 || ! system )
F_142 ( L_22 , V_12 ) ;
return NULL ;
}
static int
F_145 ( struct V_93 * V_158 , struct V_35 * V_53 )
{
struct V_5 * V_14 = V_53 -> V_6 ;
struct V_67 * V_68 = V_53 -> V_68 ;
struct V_4 * V_11 ;
struct V_93 * V_163 ;
const char * V_12 ;
int V_25 ;
if ( strcmp ( V_14 -> V_7 -> system , V_122 ) != 0 ) {
V_163 = F_140 ( V_68 , V_14 -> V_7 -> system , V_53 , V_158 ) ;
if ( ! V_163 )
return - V_22 ;
} else
V_163 = V_158 ;
V_12 = F_52 ( V_14 ) ;
V_53 -> V_90 = F_141 ( V_12 , V_163 ) ;
if ( ! V_53 -> V_90 ) {
F_142 ( L_23 , V_12 ) ;
return - 1 ;
}
if ( V_14 -> V_7 -> V_80 && ! ( V_14 -> V_38 & V_103 ) )
F_144 ( L_21 , 0644 , V_53 -> V_90 , V_53 ,
& V_164 ) ;
#ifdef F_38
if ( V_14 -> V_31 . type && V_14 -> V_7 -> V_80 )
F_144 ( L_24 , 0444 , V_53 -> V_90 ,
( void * ) ( long ) V_14 -> V_31 . type ,
& V_165 ) ;
#endif
V_11 = F_4 ( V_14 ) ;
if ( F_146 ( V_11 ) ) {
V_25 = V_14 -> V_7 -> V_166 ( V_14 ) ;
if ( V_25 < 0 ) {
F_142 ( L_25 ,
V_12 ) ;
return - 1 ;
}
}
F_144 ( L_19 , 0644 , V_53 -> V_90 , V_53 ,
& V_167 ) ;
F_144 ( L_26 , 0644 , V_53 -> V_90 , V_53 ,
& V_168 ) ;
F_144 ( L_27 , 0444 , V_53 -> V_90 , V_14 ,
& V_169 ) ;
return 0 ;
}
static void F_147 ( struct V_5 * V_14 )
{
struct V_35 * V_53 ;
struct V_67 * V_68 ;
F_148 (tr, file) {
if ( V_53 -> V_6 != V_14 )
continue;
F_65 ( V_53 ) ;
break;
} F_46 () ;
}
static void F_149 ( struct V_5 * V_14 )
{
struct V_67 * V_68 ;
struct V_35 * V_53 ;
F_41 (tr, file) {
if ( V_53 -> V_6 != V_14 )
continue;
F_54 ( V_53 , 0 ) ;
break;
} F_46 () ;
if ( V_14 -> V_31 . V_46 )
F_150 ( & V_14 -> V_31 ) ;
F_147 ( V_14 ) ;
F_18 ( & V_14 -> V_87 ) ;
}
static int F_151 ( struct V_5 * V_14 )
{
int V_25 = 0 ;
const char * V_12 ;
V_12 = F_52 ( V_14 ) ;
if ( F_13 ( ! V_12 ) )
return - V_102 ;
if ( V_14 -> V_7 -> V_170 ) {
V_25 = V_14 -> V_7 -> V_170 ( V_14 ) ;
if ( V_25 < 0 && V_25 != - V_171 )
F_142 ( L_28 , V_12 ) ;
}
return V_25 ;
}
static int
F_152 ( struct V_5 * V_14 , struct V_172 * V_173 )
{
int V_25 ;
V_25 = F_151 ( V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_14 -> V_87 , & V_174 ) ;
V_14 -> V_173 = V_173 ;
return 0 ;
}
static struct V_35 *
F_153 ( struct V_5 * V_14 ,
struct V_67 * V_68 )
{
struct V_35 * V_53 ;
V_53 = F_9 ( V_98 , V_21 ) ;
if ( ! V_53 )
return NULL ;
V_53 -> V_6 = V_14 ;
V_53 -> V_68 = V_68 ;
F_154 ( & V_53 -> V_74 , 0 ) ;
F_154 ( & V_53 -> V_175 , 0 ) ;
F_155 ( & V_53 -> V_176 ) ;
F_11 ( & V_53 -> V_87 , & V_68 -> V_121 ) ;
return V_53 ;
}
static int
F_156 ( struct V_5 * V_14 , struct V_67 * V_68 )
{
struct V_35 * V_53 ;
V_53 = F_153 ( V_14 , V_68 ) ;
if ( ! V_53 )
return - V_22 ;
return F_145 ( V_68 -> V_177 , V_53 ) ;
}
static T_5 int
F_157 ( struct V_5 * V_14 ,
struct V_67 * V_68 )
{
struct V_35 * V_53 ;
V_53 = F_153 ( V_14 , V_68 ) ;
if ( ! V_53 )
return - V_22 ;
return 0 ;
}
int F_158 ( struct V_5 * V_14 )
{
int V_25 ;
F_40 ( & V_146 ) ;
F_40 ( & V_69 ) ;
V_25 = F_152 ( V_14 , NULL ) ;
if ( V_25 >= 0 )
F_159 ( V_14 ) ;
F_47 ( & V_69 ) ;
F_47 ( & V_146 ) ;
return V_25 ;
}
static void F_160 ( struct V_5 * V_14 )
{
F_149 ( V_14 ) ;
F_16 ( V_14 ) ;
F_68 ( V_14 -> V_86 ) ;
V_14 -> V_86 = NULL ;
}
static int F_161 ( struct V_5 * V_14 )
{
struct V_67 * V_68 ;
struct V_35 * V_53 ;
#ifdef F_38
if ( V_14 -> V_178 )
return - V_179 ;
#endif
F_41 (tr, file) {
if ( V_53 -> V_6 != V_14 )
continue;
if ( V_53 -> V_38 & V_70 )
return - V_179 ;
break;
} F_46 () ;
F_160 ( V_14 ) ;
return 0 ;
}
int F_162 ( struct V_5 * V_14 )
{
int V_25 ;
F_40 ( & V_146 ) ;
F_40 ( & V_69 ) ;
F_163 ( & V_180 ) ;
V_25 = F_161 ( V_14 ) ;
F_164 ( & V_180 ) ;
F_47 ( & V_69 ) ;
F_47 ( & V_146 ) ;
return V_25 ;
}
static void F_165 ( struct V_172 * V_173 )
{
struct V_5 * * V_14 , * * V_181 , * * V_182 ;
if ( ! V_173 -> V_183 )
return;
if ( F_166 ( V_173 ) ) {
F_167 ( L_29 ,
V_173 -> V_12 ) ;
return;
}
V_181 = V_173 -> V_184 ;
V_182 = V_173 -> V_184 + V_173 -> V_183 ;
F_168 (call, start, end) {
F_152 ( * V_14 , V_173 ) ;
F_159 ( * V_14 ) ;
}
}
static void F_169 ( struct V_172 * V_173 )
{
struct V_5 * V_14 , * V_123 ;
bool V_185 = false ;
F_163 ( & V_180 ) ;
F_17 (call, p, &ftrace_events, list) {
if ( V_14 -> V_173 == V_173 ) {
if ( V_14 -> V_38 & V_84 )
V_185 = true ;
F_160 ( V_14 ) ;
}
}
F_164 ( & V_180 ) ;
if ( V_185 )
F_170 () ;
}
static int F_171 ( struct V_186 * V_187 ,
unsigned long V_125 , void * V_52 )
{
struct V_172 * V_173 = V_52 ;
F_40 ( & V_146 ) ;
F_40 ( & V_69 ) ;
switch ( V_125 ) {
case V_188 :
F_165 ( V_173 ) ;
break;
case V_189 :
F_169 ( V_173 ) ;
break;
}
F_47 ( & V_69 ) ;
F_47 ( & V_146 ) ;
return 0 ;
}
static void
F_172 ( struct V_67 * V_68 )
{
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
V_25 = F_156 ( V_14 , V_68 ) ;
if ( V_25 < 0 )
F_142 ( L_30 ,
F_52 ( V_14 ) ) ;
}
}
struct V_35 *
F_173 ( struct V_67 * V_68 , const char * system , const char * V_31 )
{
struct V_35 * V_53 ;
struct V_5 * V_14 ;
const char * V_12 ;
F_6 (file, &tr->events, list) {
V_14 = V_53 -> V_6 ;
V_12 = F_52 ( V_14 ) ;
if ( ! V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_80 )
continue;
if ( V_14 -> V_38 & V_103 )
continue;
if ( strcmp ( V_31 , V_12 ) == 0 &&
strcmp ( system , V_14 -> V_7 -> system ) == 0 )
return V_53 ;
}
return NULL ;
}
static void
F_174 ( unsigned long V_190 , unsigned long V_191 , void * * V_192 )
{
struct V_193 * * V_194 = (struct V_193 * * ) V_192 ;
struct V_193 * V_52 = * V_194 ;
if ( ! V_52 )
return;
if ( V_52 -> V_66 )
F_45 ( V_81 , & V_52 -> V_53 -> V_38 ) ;
else
F_43 ( V_81 , & V_52 -> V_53 -> V_38 ) ;
}
static void
F_175 ( unsigned long V_190 , unsigned long V_191 , void * * V_192 )
{
struct V_193 * * V_194 = (struct V_193 * * ) V_192 ;
struct V_193 * V_52 = * V_194 ;
if ( ! V_52 )
return;
if ( ! V_52 -> V_195 )
return;
if ( V_52 -> V_66 == ! ( V_52 -> V_53 -> V_38 & V_75 ) )
return;
if ( V_52 -> V_195 != - 1 )
( V_52 -> V_195 ) -- ;
F_174 ( V_190 , V_191 , V_192 ) ;
}
static int
F_176 ( struct V_110 * V_111 , unsigned long V_190 ,
struct V_196 * V_197 , void * V_192 )
{
struct V_193 * V_52 = V_192 ;
F_88 ( V_111 , L_31 , ( void * ) V_190 ) ;
F_88 ( V_111 , L_32 ,
V_52 -> V_66 ? V_198 : V_199 ,
V_52 -> V_53 -> V_6 -> V_7 -> system ,
F_52 ( V_52 -> V_53 -> V_6 ) ) ;
if ( V_52 -> V_195 == - 1 )
F_100 ( V_111 , L_33 ) ;
else
F_88 ( V_111 , L_34 , V_52 -> V_195 ) ;
return 0 ;
}
static int
F_177 ( struct V_196 * V_197 , unsigned long V_190 ,
void * * V_192 )
{
struct V_193 * * V_194 = (struct V_193 * * ) V_192 ;
struct V_193 * V_52 = * V_194 ;
V_52 -> V_200 ++ ;
return 0 ;
}
static void
F_178 ( struct V_196 * V_197 , unsigned long V_190 ,
void * * V_192 )
{
struct V_193 * * V_194 = (struct V_193 * * ) V_192 ;
struct V_193 * V_52 = * V_194 ;
if ( F_57 ( V_52 -> V_200 <= 0 ) )
return;
V_52 -> V_200 -- ;
if ( ! V_52 -> V_200 ) {
F_48 ( V_52 -> V_53 , 0 , 1 ) ;
F_179 ( V_52 -> V_53 -> V_6 -> V_173 ) ;
F_58 ( V_52 ) ;
}
* V_194 = NULL ;
}
static int
F_180 ( struct V_201 * V_202 ,
char * V_203 , char * V_204 , char * V_205 , int V_206 )
{
struct V_67 * V_68 = F_74 () ;
struct V_35 * V_53 ;
struct V_196 * V_197 ;
struct V_193 * V_52 ;
const char * system ;
const char * V_31 ;
char * V_207 ;
bool V_66 ;
int V_25 ;
if ( ! V_68 )
return - V_32 ;
if ( ! V_206 || ! V_205 )
return - V_102 ;
system = F_72 ( & V_205 , L_4 ) ;
if ( ! V_205 )
return - V_102 ;
V_31 = F_72 ( & V_205 , L_4 ) ;
F_40 ( & V_69 ) ;
V_25 = - V_102 ;
V_53 = F_173 ( V_68 , system , V_31 ) ;
if ( ! V_53 )
goto V_127;
V_66 = strcmp ( V_204 , V_198 ) == 0 ;
if ( V_66 )
V_197 = V_205 ? & V_208 : & V_209 ;
else
V_197 = V_205 ? & V_210 : & V_211 ;
if ( V_203 [ 0 ] == '!' ) {
F_181 ( V_203 + 1 , V_197 ) ;
V_25 = 0 ;
goto V_127;
}
V_25 = - V_22 ;
V_52 = F_124 ( sizeof( * V_52 ) , V_141 ) ;
if ( ! V_52 )
goto V_127;
V_52 -> V_66 = V_66 ;
V_52 -> V_195 = - 1 ;
V_52 -> V_53 = V_53 ;
if ( ! V_205 )
goto V_212;
V_207 = F_72 ( & V_205 , L_4 ) ;
V_25 = - V_102 ;
if ( ! strlen ( V_207 ) )
goto V_156;
V_25 = F_182 ( V_207 , 0 , & V_52 -> V_195 ) ;
if ( V_25 )
goto V_156;
V_212:
V_25 = F_183 ( V_53 -> V_6 -> V_173 ) ;
if ( ! V_25 ) {
V_25 = - V_179 ;
goto V_156;
}
V_25 = F_48 ( V_53 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_117;
V_25 = F_184 ( V_203 , V_197 , V_52 ) ;
if ( ! V_25 ) {
V_25 = - V_213 ;
goto V_214;
} else if ( V_25 < 0 )
goto V_214;
V_25 = 0 ;
V_127:
F_47 ( & V_69 ) ;
return V_25 ;
V_214:
F_48 ( V_53 , 0 , 1 ) ;
V_117:
F_179 ( V_53 -> V_6 -> V_173 ) ;
V_156:
F_58 ( V_52 ) ;
goto V_127;
}
static T_5 int F_185 ( void )
{
int V_25 ;
V_25 = F_186 ( & V_215 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_186 ( & V_216 ) ;
if ( F_13 ( V_25 < 0 ) )
F_187 ( & V_215 ) ;
return V_25 ;
}
static inline int F_185 ( void ) { return 0 ; }
static T_5 void
F_188 ( struct V_67 * V_68 )
{
struct V_35 * V_53 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_145 ( V_68 -> V_177 , V_53 ) ;
if ( V_25 < 0 )
F_142 ( L_30 ,
F_52 ( V_53 -> V_6 ) ) ;
}
}
static T_5 void
F_189 ( struct V_67 * V_68 )
{
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_57 ( V_14 -> V_173 ) )
continue;
V_25 = F_157 ( V_14 , V_68 ) ;
if ( V_25 < 0 )
F_142 ( L_35 ,
F_52 ( V_14 ) ) ;
}
}
static void
F_190 ( struct V_67 * V_68 )
{
struct V_35 * V_53 , * V_29 ;
F_17 (file, next, &tr->events, list)
F_65 ( V_53 ) ;
}
static void F_159 ( struct V_5 * V_14 )
{
struct V_67 * V_68 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_156 ( V_14 , V_68 ) ;
}
static T_5 int F_191 ( char * V_217 )
{
F_192 ( V_218 , V_217 , V_219 ) ;
V_220 = true ;
V_221 = true ;
return 1 ;
}
static int
F_193 ( struct V_93 * V_158 , struct V_67 * V_68 )
{
struct V_93 * V_163 ;
struct V_93 * V_41 ;
V_41 = F_143 ( L_36 , 0644 , V_158 ,
V_68 , & V_222 ) ;
if ( ! V_41 ) {
F_142 ( L_37 ) ;
return - V_22 ;
}
V_163 = F_141 ( L_38 , V_158 ) ;
if ( ! V_163 ) {
F_142 ( L_39 ) ;
return - V_22 ;
}
F_144 ( L_40 , 0444 , V_163 ,
V_223 ,
& V_224 ) ;
F_144 ( L_41 , 0444 , V_163 ,
V_225 ,
& V_224 ) ;
F_144 ( L_21 , 0644 , V_163 ,
V_68 , & V_226 ) ;
V_68 -> V_177 = V_163 ;
return 0 ;
}
int F_194 ( struct V_93 * V_158 , struct V_67 * V_68 )
{
int V_25 ;
F_40 ( & V_69 ) ;
V_25 = F_193 ( V_158 , V_68 ) ;
if ( V_25 )
goto V_227;
F_163 ( & V_180 ) ;
F_172 ( V_68 ) ;
F_164 ( & V_180 ) ;
V_227:
F_47 ( & V_69 ) ;
return V_25 ;
}
static T_5 int
F_195 ( struct V_93 * V_158 , struct V_67 * V_68 )
{
int V_25 ;
F_40 ( & V_69 ) ;
V_25 = F_193 ( V_158 , V_68 ) ;
if ( V_25 )
goto V_227;
F_163 ( & V_180 ) ;
F_188 ( V_68 ) ;
F_164 ( & V_180 ) ;
V_227:
F_47 ( & V_69 ) ;
return V_25 ;
}
int F_196 ( struct V_67 * V_68 )
{
F_40 ( & V_69 ) ;
F_197 ( V_68 ) ;
F_69 ( V_68 , NULL , NULL , NULL , 0 ) ;
F_198 () ;
F_163 ( & V_180 ) ;
F_190 ( V_68 ) ;
F_64 ( V_68 -> V_177 ) ;
F_164 ( & V_180 ) ;
V_68 -> V_177 = NULL ;
F_47 ( & V_69 ) ;
return 0 ;
}
static T_5 int F_199 ( void )
{
V_20 = F_200 ( V_10 , V_228 ) ;
V_98 = F_200 ( V_35 , V_228 ) ;
return 0 ;
}
static T_5 void
F_201 ( struct V_67 * V_68 , bool V_229 )
{
char * V_104 = V_218 ;
char * V_230 ;
int V_25 ;
while ( true ) {
V_230 = F_72 ( & V_104 , L_42 ) ;
if ( ! V_230 )
break;
if ( ! * V_230 )
continue;
if ( V_229 )
F_71 ( V_68 , V_230 , 0 ) ;
V_25 = F_71 ( V_68 , V_230 , 1 ) ;
if ( V_25 )
F_142 ( L_43 , V_230 ) ;
if ( V_104 )
* ( V_104 - 1 ) = ',' ;
}
}
static T_5 int F_202 ( void )
{
struct V_67 * V_68 = F_74 () ;
struct V_5 * * V_44 , * V_14 ;
int V_25 ;
if ( ! V_68 )
return - V_32 ;
F_168 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_14 = * V_44 ;
V_25 = F_151 ( V_14 ) ;
if ( ! V_25 )
F_11 ( & V_14 -> V_87 , & V_174 ) ;
}
F_189 ( V_68 ) ;
F_201 ( V_68 , false ) ;
F_203 () ;
F_185 () ;
F_204 () ;
return 0 ;
}
static T_5 int F_205 ( void )
{
struct V_67 * V_68 ;
V_68 = F_74 () ;
if ( ! V_68 )
return - V_32 ;
F_201 ( V_68 , true ) ;
return 0 ;
}
static T_5 int F_206 ( void )
{
struct V_67 * V_68 ;
struct V_93 * V_231 ;
struct V_93 * V_41 ;
int V_25 ;
V_68 = F_74 () ;
if ( ! V_68 )
return - V_32 ;
V_231 = F_207 () ;
if ( F_208 ( V_231 ) )
return 0 ;
V_41 = F_143 ( L_44 , 0444 , V_231 ,
V_68 , & V_232 ) ;
if ( ! V_41 )
F_142 ( L_45 ) ;
if ( F_14 () )
F_142 ( L_46 ) ;
V_25 = F_195 ( V_231 , V_68 ) ;
if ( V_25 )
return V_25 ;
#ifdef F_209
V_25 = F_210 ( & V_233 ) ;
if ( V_25 )
F_142 ( L_47 ) ;
#endif
return 0 ;
}
void T_5 F_211 ( void )
{
F_199 () ;
F_212 () ;
F_202 () ;
}
static T_5 void F_213 ( struct V_234 * V_235 )
{
F_66 ( & V_236 ) ;
F_214 ( & V_237 ) ;
F_215 ( 1 ) ;
F_216 ( & V_237 ) ;
F_67 ( & V_236 ) ;
F_40 ( & V_238 ) ;
F_217 ( 1 ) ;
F_47 ( & V_238 ) ;
}
static T_5 int F_218 ( void * V_239 )
{
void * V_240 ;
V_240 = F_110 ( 1234 , V_141 ) ;
if ( ! V_240 )
F_51 ( L_48 ) ;
F_219 ( F_213 ) ;
F_58 ( V_240 ) ;
F_220 ( V_241 ) ;
while ( ! F_221 () ) {
F_222 () ;
F_220 ( V_241 ) ;
}
F_223 ( V_242 ) ;
return 0 ;
}
static T_5 void F_224 ( void )
{
struct V_243 * V_244 ;
V_244 = F_225 ( F_218 , NULL , L_49 ) ;
F_217 ( 1 ) ;
F_226 ( V_244 ) ;
}
static T_5 void F_227 ( void )
{
struct V_89 * V_90 ;
struct V_35 * V_53 ;
struct V_5 * V_14 ;
struct V_1 * system ;
struct V_67 * V_68 ;
int V_25 ;
V_68 = F_74 () ;
if ( ! V_68 )
return;
F_51 ( L_50 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_53 -> V_6 ;
if ( ! V_14 -> V_7 || ! V_14 -> V_7 -> V_57 )
continue;
#ifndef F_228
if ( V_14 -> V_7 -> system &&
strcmp ( V_14 -> V_7 -> system , L_51 ) == 0 )
continue;
#endif
F_51 ( L_52 , F_52 ( V_14 ) ) ;
if ( V_53 -> V_38 & V_70 ) {
F_142 ( L_53 ) ;
F_57 ( 1 ) ;
continue;
}
F_54 ( V_53 , 1 ) ;
F_224 () ;
F_54 ( V_53 , 0 ) ;
F_229 ( L_54 ) ;
}
F_51 ( L_55 ) ;
F_6 (dir, &tr->systems, list) {
system = V_90 -> V_91 ;
if ( strcmp ( system -> V_12 , L_56 ) == 0 )
continue;
F_51 ( L_57 , system -> V_12 ) ;
V_25 = F_70 ( V_68 , NULL , system -> V_12 , NULL , 1 ) ;
if ( F_57 ( V_25 ) ) {
F_142 ( L_58 ,
system -> V_12 ) ;
continue;
}
F_224 () ;
V_25 = F_70 ( V_68 , NULL , system -> V_12 , NULL , 0 ) ;
if ( F_57 ( V_25 ) ) {
F_142 ( L_59 ,
system -> V_12 ) ;
continue;
}
F_229 ( L_54 ) ;
}
F_51 ( L_60 ) ;
F_51 ( L_61 ) ;
V_25 = F_70 ( V_68 , NULL , NULL , NULL , 1 ) ;
if ( F_57 ( V_25 ) ) {
F_142 ( L_62 ) ;
return;
}
F_224 () ;
V_25 = F_70 ( V_68 , NULL , NULL , NULL , 0 ) ;
if ( F_57 ( V_25 ) ) {
F_142 ( L_63 ) ;
return;
}
F_229 ( L_54 ) ;
}
static void
F_230 ( unsigned long V_190 , unsigned long V_191 ,
struct V_245 * V_246 , struct V_247 * V_247 )
{
struct V_248 * V_31 ;
struct V_249 * V_40 ;
struct V_250 * V_41 ;
unsigned long V_38 ;
long V_251 ;
int V_252 ;
int V_39 ;
V_39 = F_24 () ;
F_231 () ;
V_252 = F_232 () ;
V_251 = F_50 ( & F_233 ( V_253 , V_252 ) ) ;
if ( V_251 != 1 )
goto V_127;
F_23 ( V_38 ) ;
V_31 = F_234 ( & V_40 ,
V_254 , sizeof( * V_41 ) ,
V_38 , V_39 ) ;
if ( ! V_31 )
goto V_127;
V_41 = F_26 ( V_31 ) ;
V_41 -> V_190 = V_190 ;
V_41 -> V_191 = V_191 ;
F_235 ( V_40 , V_31 , V_38 , V_39 ) ;
V_127:
F_236 ( & F_233 ( V_253 , V_252 ) ) ;
F_237 () ;
}
static T_5 void F_238 ( void )
{
int V_25 ;
V_25 = F_239 ( & V_255 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_51 ( L_64 ) ;
return;
}
F_51 ( L_65 ) ;
F_227 () ;
F_240 ( & V_255 ) ;
}
static T_5 void F_238 ( void )
{
}
static T_5 int F_241 ( void )
{
if ( ! V_221 ) {
F_227 () ;
F_238 () ;
}
return 0 ;
}
