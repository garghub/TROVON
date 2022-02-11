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
if ( F_67 ( V_94 ) )
F_68 ( V_94 ) -> V_96 = NULL ;
}
F_69 ( & V_90 -> V_95 ) ;
F_64 ( V_90 ) ;
}
F_18 ( & V_53 -> V_87 ) ;
F_63 ( V_53 -> system ) ;
F_70 ( V_53 -> V_86 ) ;
F_19 ( V_97 , V_53 ) ;
}
static int
F_71 ( struct V_67 * V_68 , const char * V_98 ,
const char * V_99 , const char * V_31 , int V_100 )
{
struct V_35 * V_53 ;
struct V_5 * V_14 ;
const char * V_12 ;
int V_25 = - V_101 ;
F_6 (file, &tr->events, list) {
V_14 = V_53 -> V_6 ;
V_12 = F_52 ( V_14 ) ;
if ( ! V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_80 )
continue;
if ( V_14 -> V_38 & V_102 )
continue;
if ( V_98 &&
strcmp ( V_98 , V_12 ) != 0 &&
strcmp ( V_98 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_99 && strcmp ( V_99 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_31 && strcmp ( V_31 , V_12 ) != 0 )
continue;
F_54 ( V_53 , V_100 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static int F_72 ( struct V_67 * V_68 , const char * V_98 ,
const char * V_99 , const char * V_31 , int V_100 )
{
int V_25 ;
F_40 ( & V_69 ) ;
V_25 = F_71 ( V_68 , V_98 , V_99 , V_31 , V_100 ) ;
F_47 ( & V_69 ) ;
return V_25 ;
}
static int F_73 ( struct V_67 * V_68 , char * V_103 , int V_100 )
{
char * V_31 = NULL , * V_99 = NULL , * V_98 ;
int V_25 ;
V_98 = F_74 ( & V_103 , L_4 ) ;
if ( V_103 ) {
V_99 = V_98 ;
V_31 = V_103 ;
V_98 = NULL ;
if ( ! strlen ( V_99 ) || strcmp ( V_99 , L_5 ) == 0 )
V_99 = NULL ;
if ( ! strlen ( V_31 ) || strcmp ( V_31 , L_5 ) == 0 )
V_31 = NULL ;
}
V_25 = F_72 ( V_68 , V_98 , V_99 , V_31 , V_100 ) ;
if ( V_103 )
* ( V_103 - 1 ) = ':' ;
return V_25 ;
}
int F_75 ( const char * system , const char * V_31 , int V_100 )
{
struct V_67 * V_68 = F_76 () ;
if ( ! V_68 )
return - V_32 ;
return F_72 ( V_68 , NULL , system , V_31 , V_100 ) ;
}
static T_1
F_77 ( struct V_53 * V_53 , const char T_2 * V_104 ,
T_3 V_105 , T_4 * V_106 )
{
struct V_107 V_108 ;
struct V_109 * V_110 = V_53 -> V_111 ;
struct V_67 * V_68 = V_110 -> V_112 ;
T_1 V_113 , V_25 ;
if ( ! V_105 )
return 0 ;
V_25 = F_78 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_79 ( & V_108 , V_114 + 1 ) )
return - V_22 ;
V_113 = F_80 ( & V_108 , V_104 , V_105 , V_106 ) ;
if ( V_113 >= 0 && F_81 ( ( & V_108 ) ) ) {
int V_100 = 1 ;
if ( * V_108 . V_40 == '!' )
V_100 = 0 ;
V_108 . V_40 [ V_108 . V_115 ] = 0 ;
V_25 = F_73 ( V_68 , V_108 . V_40 + ! V_100 , V_100 ) ;
if ( V_25 )
goto V_116;
}
V_25 = V_113 ;
V_116:
F_82 ( & V_108 ) ;
return V_25 ;
}
static void *
F_83 ( struct V_109 * V_110 , void * V_117 , T_4 * V_118 )
{
struct V_35 * V_53 = V_117 ;
struct V_5 * V_14 ;
struct V_67 * V_68 = V_110 -> V_112 ;
( * V_118 ) ++ ;
F_84 (file, &tr->events, list) {
V_14 = V_53 -> V_6 ;
if ( V_14 -> V_7 && V_14 -> V_7 -> V_80 )
return V_53 ;
}
return NULL ;
}
static void * F_85 ( struct V_109 * V_110 , T_4 * V_118 )
{
struct V_35 * V_53 ;
struct V_67 * V_68 = V_110 -> V_112 ;
T_4 V_119 ;
F_40 ( & V_69 ) ;
V_53 = F_86 ( & V_68 -> V_120 , struct V_35 , V_87 ) ;
for ( V_119 = 0 ; V_119 <= * V_118 ; ) {
V_53 = F_83 ( V_110 , V_53 , & V_119 ) ;
if ( ! V_53 )
break;
}
return V_53 ;
}
static void *
F_87 ( struct V_109 * V_110 , void * V_117 , T_4 * V_118 )
{
struct V_35 * V_53 = V_117 ;
struct V_67 * V_68 = V_110 -> V_112 ;
( * V_118 ) ++ ;
F_84 (file, &tr->events, list) {
if ( V_53 -> V_38 & V_70 )
return V_53 ;
}
return NULL ;
}
static void * F_88 ( struct V_109 * V_110 , T_4 * V_118 )
{
struct V_35 * V_53 ;
struct V_67 * V_68 = V_110 -> V_112 ;
T_4 V_119 ;
F_40 ( & V_69 ) ;
V_53 = F_86 ( & V_68 -> V_120 , struct V_35 , V_87 ) ;
for ( V_119 = 0 ; V_119 <= * V_118 ; ) {
V_53 = F_87 ( V_110 , V_53 , & V_119 ) ;
if ( ! V_53 )
break;
}
return V_53 ;
}
static int F_89 ( struct V_109 * V_110 , void * V_117 )
{
struct V_35 * V_53 = V_117 ;
struct V_5 * V_14 = V_53 -> V_6 ;
if ( strcmp ( V_14 -> V_7 -> system , V_121 ) != 0 )
F_90 ( V_110 , L_6 , V_14 -> V_7 -> system ) ;
F_90 ( V_110 , L_3 , F_52 ( V_14 ) ) ;
return 0 ;
}
static void F_91 ( struct V_109 * V_110 , void * V_122 )
{
F_47 ( & V_69 ) ;
}
static T_1
F_92 ( struct V_53 * V_123 , char T_2 * V_104 , T_3 V_105 ,
T_4 * V_106 )
{
struct V_35 * V_53 ;
unsigned long V_38 ;
char V_103 [ 4 ] = L_7 ;
F_40 ( & V_69 ) ;
V_53 = F_93 ( V_123 ) ;
if ( F_94 ( V_53 ) )
V_38 = V_53 -> V_38 ;
F_47 ( & V_69 ) ;
if ( ! V_53 )
return - V_32 ;
if ( V_38 & V_70 &&
! ( V_38 & V_75 ) )
strcpy ( V_103 , L_8 ) ;
if ( V_38 & V_75 ||
V_38 & V_77 )
strcat ( V_103 , L_5 ) ;
strcat ( V_103 , L_9 ) ;
return F_95 ( V_104 , V_105 , V_106 , V_103 , strlen ( V_103 ) ) ;
}
static T_1
F_96 ( struct V_53 * V_123 , const char T_2 * V_104 , T_3 V_105 ,
T_4 * V_106 )
{
struct V_35 * V_53 ;
unsigned long V_124 ;
int V_25 ;
V_25 = F_97 ( V_104 , V_105 , 10 , & V_124 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_78 () ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_124 ) {
case 0 :
case 1 :
V_25 = - V_32 ;
F_40 ( & V_69 ) ;
V_53 = F_93 ( V_123 ) ;
if ( F_94 ( V_53 ) )
V_25 = F_54 ( V_53 , V_124 ) ;
F_47 ( & V_69 ) ;
break;
default:
return - V_101 ;
}
* V_106 += V_105 ;
return V_25 ? V_25 : V_105 ;
}
static T_1
F_98 ( struct V_53 * V_123 , char T_2 * V_104 , T_3 V_105 ,
T_4 * V_106 )
{
const char V_125 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_89 * V_90 = V_123 -> V_111 ;
struct V_1 * system = V_90 -> V_91 ;
struct V_5 * V_14 ;
struct V_35 * V_53 ;
struct V_67 * V_68 = V_90 -> V_68 ;
char V_103 [ 2 ] ;
int V_100 = 0 ;
int V_25 ;
F_40 ( & V_69 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_53 -> V_6 ;
if ( ! F_52 ( V_14 ) || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_80 )
continue;
if ( system && strcmp ( V_14 -> V_7 -> system , system -> V_12 ) != 0 )
continue;
V_100 |= ( 1 << ! ! ( V_53 -> V_38 & V_70 ) ) ;
if ( V_100 == 3 )
break;
}
F_47 ( & V_69 ) ;
V_103 [ 0 ] = V_125 [ V_100 ] ;
V_103 [ 1 ] = '\n' ;
V_25 = F_95 ( V_104 , V_105 , V_106 , V_103 , 2 ) ;
return V_25 ;
}
static T_1
F_99 ( struct V_53 * V_123 , const char T_2 * V_104 , T_3 V_105 ,
T_4 * V_106 )
{
struct V_89 * V_90 = V_123 -> V_111 ;
struct V_1 * system = V_90 -> V_91 ;
const char * V_12 = NULL ;
unsigned long V_124 ;
T_1 V_25 ;
V_25 = F_97 ( V_104 , V_105 , 10 , & V_124 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_78 () ;
if ( V_25 < 0 )
return V_25 ;
if ( V_124 != 0 && V_124 != 1 )
return - V_101 ;
if ( system )
V_12 = system -> V_12 ;
V_25 = F_72 ( V_90 -> V_68 , NULL , V_12 , NULL , V_124 ) ;
if ( V_25 )
goto V_126;
V_25 = V_105 ;
V_126:
* V_106 += V_105 ;
return V_25 ;
}
static void * F_100 ( struct V_109 * V_110 , void * V_117 , T_4 * V_118 )
{
struct V_5 * V_14 = F_93 ( V_110 -> V_112 ) ;
struct V_4 * V_127 = & V_15 ;
struct V_4 * V_11 = F_4 ( V_14 ) ;
struct V_4 * V_128 = V_117 ;
( * V_118 ) ++ ;
switch ( ( unsigned long ) V_117 ) {
case V_129 :
V_128 = V_127 ;
break;
case V_130 :
V_128 = V_11 ;
break;
case V_131 :
return NULL ;
}
V_128 = V_128 -> V_132 ;
if ( V_128 == V_127 )
return ( void * ) V_130 ;
else if ( V_128 == V_11 )
return ( void * ) V_131 ;
else
return V_128 ;
}
static int F_101 ( struct V_109 * V_110 , void * V_117 )
{
struct V_5 * V_14 = F_93 ( V_110 -> V_112 ) ;
struct V_10 * V_13 ;
const char * V_133 ;
switch ( ( unsigned long ) V_117 ) {
case V_129 :
F_90 ( V_110 , L_10 , F_52 ( V_14 ) ) ;
F_90 ( V_110 , L_11 , V_14 -> V_31 . type ) ;
F_102 ( V_110 , L_12 ) ;
return 0 ;
case V_130 :
F_103 ( V_110 , '\n' ) ;
return 0 ;
case V_131 :
F_90 ( V_110 , L_13 ,
V_14 -> V_134 ) ;
return 0 ;
}
V_13 = F_86 ( V_117 , struct V_10 , V_24 ) ;
V_133 = strchr ( V_13 -> type , '[' ) ;
if ( ! strncmp ( V_13 -> type , L_14 , 10 ) )
V_133 = NULL ;
if ( ! V_133 )
F_90 ( V_110 , L_15 ,
V_13 -> type , V_13 -> V_12 , V_13 -> V_16 ,
V_13 -> V_17 , ! ! V_13 -> V_18 ) ;
else
F_90 ( V_110 , L_16 ,
( int ) ( V_133 - V_13 -> type ) ,
V_13 -> type , V_13 -> V_12 ,
V_133 , V_13 -> V_16 ,
V_13 -> V_17 , ! ! V_13 -> V_18 ) ;
return 0 ;
}
static void * F_104 ( struct V_109 * V_110 , T_4 * V_118 )
{
void * V_122 = ( void * ) V_129 ;
T_4 V_119 = 0 ;
F_40 ( & V_69 ) ;
if ( ! F_93 ( V_110 -> V_112 ) )
return F_105 ( - V_32 ) ;
while ( V_119 < * V_118 && V_122 )
V_122 = F_100 ( V_110 , V_122 , & V_119 ) ;
return V_122 ;
}
static void F_106 ( struct V_109 * V_110 , void * V_122 )
{
F_47 ( & V_69 ) ;
}
static int F_107 ( struct V_135 * V_135 , struct V_53 * V_53 )
{
struct V_109 * V_110 ;
int V_25 ;
V_25 = F_108 ( V_53 , & V_136 ) ;
if ( V_25 < 0 )
return V_25 ;
V_110 = V_53 -> V_111 ;
V_110 -> V_112 = V_53 ;
return 0 ;
}
static T_1
F_109 ( struct V_53 * V_123 , char T_2 * V_104 , T_3 V_105 , T_4 * V_106 )
{
int V_30 = ( long ) F_93 ( V_123 ) ;
char V_103 [ 32 ] ;
int V_37 ;
if ( * V_106 )
return 0 ;
if ( F_110 ( ! V_30 ) )
return - V_32 ;
V_37 = sprintf ( V_103 , L_17 , V_30 ) ;
return F_95 ( V_104 , V_105 , V_106 , V_103 , V_37 ) ;
}
static T_1
F_111 ( struct V_53 * V_123 , char T_2 * V_104 , T_3 V_105 ,
T_4 * V_106 )
{
struct V_35 * V_53 ;
struct V_137 * V_138 ;
int V_139 = - V_32 ;
if ( * V_106 )
return 0 ;
V_138 = F_112 ( sizeof( * V_138 ) , V_140 ) ;
if ( ! V_138 )
return - V_22 ;
F_29 ( V_138 ) ;
F_40 ( & V_69 ) ;
V_53 = F_93 ( V_123 ) ;
if ( V_53 )
F_113 ( V_53 , V_138 ) ;
F_47 ( & V_69 ) ;
if ( V_53 )
V_139 = F_95 ( V_104 , V_105 , V_106 ,
V_138 -> V_40 , F_114 ( V_138 ) ) ;
F_58 ( V_138 ) ;
return V_139 ;
}
static T_1
F_115 ( struct V_53 * V_123 , const char T_2 * V_104 , T_3 V_105 ,
T_4 * V_106 )
{
struct V_35 * V_53 ;
char * V_103 ;
int V_141 = - V_32 ;
if ( V_105 >= V_142 )
return - V_101 ;
V_103 = ( char * ) F_116 ( V_143 ) ;
if ( ! V_103 )
return - V_22 ;
if ( F_117 ( V_103 , V_104 , V_105 ) ) {
F_118 ( ( unsigned long ) V_103 ) ;
return - V_144 ;
}
V_103 [ V_105 ] = '\0' ;
F_40 ( & V_69 ) ;
V_53 = F_93 ( V_123 ) ;
if ( V_53 )
V_141 = F_119 ( V_53 , V_103 ) ;
F_47 ( & V_69 ) ;
F_118 ( ( unsigned long ) V_103 ) ;
if ( V_141 < 0 )
return V_141 ;
* V_106 += V_105 ;
return V_105 ;
}
static int F_120 ( struct V_135 * V_135 , struct V_53 * V_123 )
{
struct V_1 * system = NULL ;
struct V_89 * V_90 = NULL ;
struct V_67 * V_68 ;
int V_25 ;
if ( F_121 () )
return - V_32 ;
F_40 ( & V_145 ) ;
F_40 ( & V_69 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_90 == V_135 -> V_96 ) {
if ( V_90 -> V_92 ) {
F_60 ( V_90 ) ;
system = V_90 -> V_91 ;
}
goto V_146;
}
}
}
V_146:
F_47 ( & V_69 ) ;
F_47 ( & V_145 ) ;
if ( ! system )
return - V_32 ;
F_13 ( ! V_90 ) ;
if ( F_122 ( V_68 ) < 0 ) {
F_62 ( V_90 ) ;
return - V_32 ;
}
V_25 = F_123 ( V_135 , V_123 ) ;
if ( V_25 < 0 ) {
F_124 ( V_68 ) ;
F_62 ( V_90 ) ;
}
return V_25 ;
}
static int F_125 ( struct V_135 * V_135 , struct V_53 * V_123 )
{
struct V_89 * V_90 ;
struct V_67 * V_68 = V_135 -> V_96 ;
int V_25 ;
if ( F_121 () )
return - V_32 ;
if ( F_122 ( V_68 ) < 0 )
return - V_32 ;
V_90 = F_126 ( sizeof( * V_90 ) , V_140 ) ;
if ( ! V_90 ) {
F_124 ( V_68 ) ;
return - V_22 ;
}
V_90 -> V_68 = V_68 ;
V_25 = F_123 ( V_135 , V_123 ) ;
if ( V_25 < 0 ) {
F_124 ( V_68 ) ;
F_58 ( V_90 ) ;
return V_25 ;
}
V_123 -> V_111 = V_90 ;
return 0 ;
}
static int F_127 ( struct V_135 * V_135 , struct V_53 * V_53 )
{
struct V_89 * V_90 = V_53 -> V_111 ;
F_124 ( V_90 -> V_68 ) ;
if ( V_90 -> V_91 )
F_62 ( V_90 ) ;
else
F_58 ( V_90 ) ;
return 0 ;
}
static T_1
F_128 ( struct V_53 * V_123 , char T_2 * V_104 , T_3 V_105 ,
T_4 * V_106 )
{
struct V_89 * V_90 = V_123 -> V_111 ;
struct V_1 * system = V_90 -> V_91 ;
struct V_137 * V_138 ;
int V_139 ;
if ( * V_106 )
return 0 ;
V_138 = F_112 ( sizeof( * V_138 ) , V_140 ) ;
if ( ! V_138 )
return - V_22 ;
F_29 ( V_138 ) ;
F_129 ( system , V_138 ) ;
V_139 = F_95 ( V_104 , V_105 , V_106 ,
V_138 -> V_40 , F_114 ( V_138 ) ) ;
F_58 ( V_138 ) ;
return V_139 ;
}
static T_1
F_130 ( struct V_53 * V_123 , const char T_2 * V_104 , T_3 V_105 ,
T_4 * V_106 )
{
struct V_89 * V_90 = V_123 -> V_111 ;
char * V_103 ;
int V_141 ;
if ( V_105 >= V_142 )
return - V_101 ;
V_103 = ( char * ) F_116 ( V_143 ) ;
if ( ! V_103 )
return - V_22 ;
if ( F_117 ( V_103 , V_104 , V_105 ) ) {
F_118 ( ( unsigned long ) V_103 ) ;
return - V_144 ;
}
V_103 [ V_105 ] = '\0' ;
V_141 = F_131 ( V_90 , V_103 ) ;
F_118 ( ( unsigned long ) V_103 ) ;
if ( V_141 < 0 )
return V_141 ;
* V_106 += V_105 ;
return V_105 ;
}
static T_1
F_132 ( struct V_53 * V_123 , char T_2 * V_104 , T_3 V_105 , T_4 * V_106 )
{
int (* F_133)( struct V_137 * V_138 ) = V_123 -> V_111 ;
struct V_137 * V_138 ;
int V_139 ;
if ( * V_106 )
return 0 ;
V_138 = F_112 ( sizeof( * V_138 ) , V_140 ) ;
if ( ! V_138 )
return - V_22 ;
F_29 ( V_138 ) ;
F_133 ( V_138 ) ;
V_139 = F_95 ( V_104 , V_105 , V_106 ,
V_138 -> V_40 , F_114 ( V_138 ) ) ;
F_58 ( V_138 ) ;
return V_139 ;
}
static int
F_134 ( struct V_135 * V_135 , struct V_53 * V_53 ,
const struct V_147 * V_148 )
{
struct V_109 * V_110 ;
int V_25 ;
V_25 = F_108 ( V_53 , V_148 ) ;
if ( V_25 < 0 )
return V_25 ;
V_110 = V_53 -> V_111 ;
V_110 -> V_112 = V_135 -> V_96 ;
return V_25 ;
}
static int F_135 ( struct V_135 * V_135 , struct V_53 * V_53 )
{
struct V_67 * V_68 = V_135 -> V_96 ;
F_124 ( V_68 ) ;
return F_136 ( V_135 , V_53 ) ;
}
static int
F_137 ( struct V_135 * V_135 , struct V_53 * V_53 )
{
const struct V_147 * V_148 = & V_149 ;
return F_134 ( V_135 , V_53 , V_148 ) ;
}
static int
F_138 ( struct V_135 * V_135 , struct V_53 * V_53 )
{
const struct V_147 * V_148 = & V_150 ;
struct V_67 * V_68 = V_135 -> V_96 ;
int V_25 ;
if ( F_122 ( V_68 ) < 0 )
return - V_32 ;
if ( ( V_53 -> V_151 & V_152 ) &&
( V_53 -> V_153 & V_154 ) )
F_55 ( V_68 ) ;
V_25 = F_134 ( V_135 , V_53 , V_148 ) ;
if ( V_25 < 0 )
F_124 ( V_68 ) ;
return V_25 ;
}
static struct V_1 *
F_139 ( const char * V_12 )
{
struct V_1 * system ;
system = F_112 ( sizeof( * system ) , V_140 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
if ( ! F_140 ( ( unsigned long ) V_12 ) ) {
system -> V_2 |= V_3 ;
system -> V_12 = F_141 ( V_12 , V_140 ) ;
if ( ! system -> V_12 )
goto V_155;
} else
system -> V_12 = V_12 ;
system -> V_86 = NULL ;
system -> V_86 = F_126 ( sizeof( struct V_85 ) , V_140 ) ;
if ( ! system -> V_86 )
goto V_155;
F_11 ( & system -> V_87 , & V_156 ) ;
return system ;
V_155:
if ( system -> V_2 & V_3 )
F_58 ( system -> V_12 ) ;
F_58 ( system ) ;
return NULL ;
}
static struct V_93 *
F_142 ( struct V_67 * V_68 , const char * V_12 ,
struct V_35 * V_53 , struct V_93 * V_157 )
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
if ( & system -> V_87 == & V_156 )
system = NULL ;
V_90 = F_112 ( sizeof( * V_90 ) , V_140 ) ;
if ( ! V_90 )
goto V_158;
if ( ! system ) {
system = F_139 ( V_12 ) ;
if ( ! system )
goto V_155;
} else
F_59 ( system ) ;
V_90 -> V_41 = F_143 ( V_12 , V_157 ) ;
if ( ! V_90 -> V_41 ) {
F_144 ( L_18 , V_12 ) ;
F_56 ( system ) ;
goto V_155;
}
V_90 -> V_68 = V_68 ;
V_90 -> V_2 = 1 ;
V_90 -> V_92 = 1 ;
V_90 -> V_91 = system ;
V_53 -> system = V_90 ;
V_41 = F_145 ( L_19 , 0644 , V_90 -> V_41 , V_90 ,
& V_159 ) ;
if ( ! V_41 ) {
F_58 ( system -> V_86 ) ;
system -> V_86 = NULL ;
F_144 ( L_20 , V_12 ) ;
}
F_146 ( L_21 , 0644 , V_90 -> V_41 , V_90 ,
& V_160 ) ;
F_11 ( & V_90 -> V_87 , & V_68 -> V_161 ) ;
return V_90 -> V_41 ;
V_155:
F_58 ( V_90 ) ;
V_158:
if ( ! V_90 || ! system )
F_144 ( L_22 , V_12 ) ;
return NULL ;
}
static int
F_147 ( struct V_93 * V_157 , struct V_35 * V_53 )
{
struct V_5 * V_14 = V_53 -> V_6 ;
struct V_67 * V_68 = V_53 -> V_68 ;
struct V_4 * V_11 ;
struct V_93 * V_162 ;
const char * V_12 ;
int V_25 ;
if ( strcmp ( V_14 -> V_7 -> system , V_121 ) != 0 ) {
V_162 = F_142 ( V_68 , V_14 -> V_7 -> system , V_53 , V_157 ) ;
if ( ! V_162 )
return - V_22 ;
} else
V_162 = V_157 ;
V_12 = F_52 ( V_14 ) ;
V_53 -> V_90 = F_143 ( V_12 , V_162 ) ;
if ( ! V_53 -> V_90 ) {
F_144 ( L_23 , V_12 ) ;
return - 1 ;
}
if ( V_14 -> V_7 -> V_80 && ! ( V_14 -> V_38 & V_102 ) )
F_146 ( L_21 , 0644 , V_53 -> V_90 , V_53 ,
& V_163 ) ;
#ifdef F_38
if ( V_14 -> V_31 . type && V_14 -> V_7 -> V_80 )
F_146 ( L_24 , 0444 , V_53 -> V_90 ,
( void * ) ( long ) V_14 -> V_31 . type ,
& V_164 ) ;
#endif
V_11 = F_4 ( V_14 ) ;
if ( F_148 ( V_11 ) ) {
V_25 = V_14 -> V_7 -> V_165 ( V_14 ) ;
if ( V_25 < 0 ) {
F_144 ( L_25 ,
V_12 ) ;
return - 1 ;
}
}
F_146 ( L_19 , 0644 , V_53 -> V_90 , V_53 ,
& V_166 ) ;
F_146 ( L_26 , 0644 , V_53 -> V_90 , V_53 ,
& V_167 ) ;
F_146 ( L_27 , 0444 , V_53 -> V_90 , V_14 ,
& V_168 ) ;
return 0 ;
}
static void F_149 ( struct V_5 * V_14 )
{
struct V_35 * V_53 ;
struct V_67 * V_68 ;
F_150 (tr, file) {
if ( V_53 -> V_6 != V_14 )
continue;
F_65 ( V_53 ) ;
break;
} F_46 () ;
}
static void F_151 ( struct V_5 * V_14 )
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
F_152 ( & V_14 -> V_31 ) ;
F_149 ( V_14 ) ;
F_18 ( & V_14 -> V_87 ) ;
}
static int F_153 ( struct V_5 * V_14 )
{
int V_25 = 0 ;
const char * V_12 ;
V_12 = F_52 ( V_14 ) ;
if ( F_13 ( ! V_12 ) )
return - V_101 ;
if ( V_14 -> V_7 -> V_169 ) {
V_25 = V_14 -> V_7 -> V_169 ( V_14 ) ;
if ( V_25 < 0 && V_25 != - V_170 )
F_144 ( L_28 , V_12 ) ;
}
return V_25 ;
}
static int
F_154 ( struct V_5 * V_14 , struct V_171 * V_172 )
{
int V_25 ;
V_25 = F_153 ( V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_14 -> V_87 , & V_173 ) ;
V_14 -> V_172 = V_172 ;
return 0 ;
}
static char * F_155 ( char * V_174 , struct V_175 * V_176 , int V_37 )
{
int V_177 ;
int V_178 ;
V_178 = snprintf ( V_174 , 0 , L_29 , V_176 -> V_179 ) ;
if ( V_37 < V_178 )
return NULL ;
snprintf ( V_174 , V_178 + 1 , L_29 , V_176 -> V_179 ) ;
V_177 = strlen ( V_174 + V_37 ) ;
memmove ( V_174 + V_178 , V_174 + V_37 , V_177 ) ;
V_174 [ V_178 + V_177 ] = 0 ;
return V_174 + V_178 ;
}
static void F_156 ( struct V_5 * V_14 ,
struct V_175 * V_176 )
{
char * V_174 ;
int V_180 = 0 ;
int V_37 = strlen ( V_176 -> V_181 ) ;
for ( V_174 = V_14 -> V_134 ; * V_174 ; V_174 ++ ) {
if ( * V_174 == '\\' ) {
V_174 ++ ;
if ( ! * V_174 )
break;
continue;
}
if ( * V_174 == '"' ) {
V_180 ^= 1 ;
continue;
}
if ( V_180 )
continue;
if ( isdigit ( * V_174 ) ) {
do {
V_174 ++ ;
} while ( isalnum ( * V_174 ) );
if ( ! * V_174 )
break;
continue;
}
if ( isalpha ( * V_174 ) || * V_174 == '_' ) {
if ( strncmp ( V_176 -> V_181 , V_174 , V_37 ) == 0 &&
! isalnum ( V_174 [ V_37 ] ) && V_174 [ V_37 ] != '_' ) {
V_174 = F_155 ( V_174 , V_176 , V_37 ) ;
if ( F_57 ( ! V_174 ) )
return;
continue;
}
V_182:
do {
V_174 ++ ;
} while ( isalnum ( * V_174 ) || * V_174 == '_' );
if ( ! * V_174 )
break;
if ( * V_174 == '.' || ( V_174 [ 0 ] == '-' && V_174 [ 1 ] == '>' ) ) {
V_174 += * V_174 == '.' ? 1 : 2 ;
if ( ! * V_174 )
break;
goto V_182;
}
continue;
}
}
}
void F_157 ( struct V_175 * * V_176 , int V_37 )
{
struct V_5 * V_14 , * V_122 ;
const char * V_183 = NULL ;
int V_184 ;
int V_185 ;
F_158 ( & V_186 ) ;
F_17 (call, p, &ftrace_events, list) {
if ( ! V_183 || V_14 -> V_7 -> system != V_183 ) {
V_184 = 0 ;
V_183 = V_14 -> V_7 -> system ;
}
for ( V_185 = V_184 ; V_185 < V_37 ; V_185 ++ ) {
if ( V_14 -> V_7 -> system == V_176 [ V_185 ] -> system ) {
if ( ! V_184 )
V_184 = V_185 ;
F_156 ( V_14 , V_176 [ V_185 ] ) ;
}
}
}
F_159 ( & V_186 ) ;
}
static struct V_35 *
F_160 ( struct V_5 * V_14 ,
struct V_67 * V_68 )
{
struct V_35 * V_53 ;
V_53 = F_9 ( V_97 , V_21 ) ;
if ( ! V_53 )
return NULL ;
V_53 -> V_6 = V_14 ;
V_53 -> V_68 = V_68 ;
F_161 ( & V_53 -> V_74 , 0 ) ;
F_161 ( & V_53 -> V_187 , 0 ) ;
F_162 ( & V_53 -> V_188 ) ;
F_11 ( & V_53 -> V_87 , & V_68 -> V_120 ) ;
return V_53 ;
}
static int
F_163 ( struct V_5 * V_14 , struct V_67 * V_68 )
{
struct V_35 * V_53 ;
V_53 = F_160 ( V_14 , V_68 ) ;
if ( ! V_53 )
return - V_22 ;
return F_147 ( V_68 -> V_189 , V_53 ) ;
}
static T_5 int
F_164 ( struct V_5 * V_14 ,
struct V_67 * V_68 )
{
struct V_35 * V_53 ;
V_53 = F_160 ( V_14 , V_68 ) ;
if ( ! V_53 )
return - V_22 ;
return 0 ;
}
int F_165 ( struct V_5 * V_14 )
{
int V_25 ;
F_40 ( & V_145 ) ;
F_40 ( & V_69 ) ;
V_25 = F_154 ( V_14 , NULL ) ;
if ( V_25 >= 0 )
F_166 ( V_14 ) ;
F_47 ( & V_69 ) ;
F_47 ( & V_145 ) ;
return V_25 ;
}
static void F_167 ( struct V_5 * V_14 )
{
F_151 ( V_14 ) ;
F_16 ( V_14 ) ;
F_70 ( V_14 -> V_86 ) ;
V_14 -> V_86 = NULL ;
}
static int F_168 ( struct V_5 * V_14 )
{
struct V_67 * V_68 ;
struct V_35 * V_53 ;
#ifdef F_38
if ( V_14 -> V_190 )
return - V_191 ;
#endif
F_41 (tr, file) {
if ( V_53 -> V_6 != V_14 )
continue;
if ( V_53 -> V_38 & V_70 )
return - V_191 ;
break;
} F_46 () ;
F_167 ( V_14 ) ;
return 0 ;
}
int F_169 ( struct V_5 * V_14 )
{
int V_25 ;
F_40 ( & V_145 ) ;
F_40 ( & V_69 ) ;
F_158 ( & V_186 ) ;
V_25 = F_168 ( V_14 ) ;
F_159 ( & V_186 ) ;
F_47 ( & V_69 ) ;
F_47 ( & V_145 ) ;
return V_25 ;
}
static void F_170 ( struct V_171 * V_172 )
{
struct V_5 * * V_14 , * * V_192 , * * V_193 ;
if ( ! V_172 -> V_194 )
return;
if ( F_171 ( V_172 ) ) {
F_172 ( L_30 ,
V_172 -> V_12 ) ;
return;
}
V_192 = V_172 -> V_195 ;
V_193 = V_172 -> V_195 + V_172 -> V_194 ;
F_173 (call, start, end) {
F_154 ( * V_14 , V_172 ) ;
F_166 ( * V_14 ) ;
}
}
static void F_174 ( struct V_171 * V_172 )
{
struct V_5 * V_14 , * V_122 ;
bool V_196 = false ;
F_158 ( & V_186 ) ;
F_17 (call, p, &ftrace_events, list) {
if ( V_14 -> V_172 == V_172 ) {
if ( V_14 -> V_38 & V_84 )
V_196 = true ;
F_167 ( V_14 ) ;
}
}
F_159 ( & V_186 ) ;
if ( V_196 )
F_175 () ;
}
static int F_176 ( struct V_197 * V_198 ,
unsigned long V_124 , void * V_52 )
{
struct V_171 * V_172 = V_52 ;
F_40 ( & V_145 ) ;
F_40 ( & V_69 ) ;
switch ( V_124 ) {
case V_199 :
F_170 ( V_172 ) ;
break;
case V_200 :
F_174 ( V_172 ) ;
break;
}
F_47 ( & V_69 ) ;
F_47 ( & V_145 ) ;
return 0 ;
}
static void
F_177 ( struct V_67 * V_68 )
{
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
V_25 = F_163 ( V_14 , V_68 ) ;
if ( V_25 < 0 )
F_144 ( L_31 ,
F_52 ( V_14 ) ) ;
}
}
struct V_35 *
F_178 ( struct V_67 * V_68 , const char * system , const char * V_31 )
{
struct V_35 * V_53 ;
struct V_5 * V_14 ;
const char * V_12 ;
F_6 (file, &tr->events, list) {
V_14 = V_53 -> V_6 ;
V_12 = F_52 ( V_14 ) ;
if ( ! V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_80 )
continue;
if ( V_14 -> V_38 & V_102 )
continue;
if ( strcmp ( V_31 , V_12 ) == 0 &&
strcmp ( system , V_14 -> V_7 -> system ) == 0 )
return V_53 ;
}
return NULL ;
}
static void
F_179 ( unsigned long V_201 , unsigned long V_202 , void * * V_203 )
{
struct V_204 * * V_205 = (struct V_204 * * ) V_203 ;
struct V_204 * V_52 = * V_205 ;
if ( ! V_52 )
return;
if ( V_52 -> V_66 )
F_45 ( V_81 , & V_52 -> V_53 -> V_38 ) ;
else
F_43 ( V_81 , & V_52 -> V_53 -> V_38 ) ;
}
static void
F_180 ( unsigned long V_201 , unsigned long V_202 , void * * V_203 )
{
struct V_204 * * V_205 = (struct V_204 * * ) V_203 ;
struct V_204 * V_52 = * V_205 ;
if ( ! V_52 )
return;
if ( ! V_52 -> V_206 )
return;
if ( V_52 -> V_66 == ! ( V_52 -> V_53 -> V_38 & V_75 ) )
return;
if ( V_52 -> V_206 != - 1 )
( V_52 -> V_206 ) -- ;
F_179 ( V_201 , V_202 , V_203 ) ;
}
static int
F_181 ( struct V_109 * V_110 , unsigned long V_201 ,
struct V_207 * V_208 , void * V_203 )
{
struct V_204 * V_52 = V_203 ;
F_90 ( V_110 , L_32 , ( void * ) V_201 ) ;
F_90 ( V_110 , L_33 ,
V_52 -> V_66 ? V_209 : V_210 ,
V_52 -> V_53 -> V_6 -> V_7 -> system ,
F_52 ( V_52 -> V_53 -> V_6 ) ) ;
if ( V_52 -> V_206 == - 1 )
F_102 ( V_110 , L_34 ) ;
else
F_90 ( V_110 , L_35 , V_52 -> V_206 ) ;
return 0 ;
}
static int
F_182 ( struct V_207 * V_208 , unsigned long V_201 ,
void * * V_203 )
{
struct V_204 * * V_205 = (struct V_204 * * ) V_203 ;
struct V_204 * V_52 = * V_205 ;
V_52 -> V_211 ++ ;
return 0 ;
}
static void
F_183 ( struct V_207 * V_208 , unsigned long V_201 ,
void * * V_203 )
{
struct V_204 * * V_205 = (struct V_204 * * ) V_203 ;
struct V_204 * V_52 = * V_205 ;
if ( F_57 ( V_52 -> V_211 <= 0 ) )
return;
V_52 -> V_211 -- ;
if ( ! V_52 -> V_211 ) {
F_48 ( V_52 -> V_53 , 0 , 1 ) ;
F_184 ( V_52 -> V_53 -> V_6 -> V_172 ) ;
F_58 ( V_52 ) ;
}
* V_205 = NULL ;
}
static int
F_185 ( struct V_212 * V_213 ,
char * V_214 , char * V_215 , char * V_216 , int V_217 )
{
struct V_67 * V_68 = F_76 () ;
struct V_35 * V_53 ;
struct V_207 * V_208 ;
struct V_204 * V_52 ;
const char * system ;
const char * V_31 ;
char * V_218 ;
bool V_66 ;
int V_25 ;
if ( ! V_68 )
return - V_32 ;
if ( ! V_217 || ! V_216 )
return - V_101 ;
system = F_74 ( & V_216 , L_4 ) ;
if ( ! V_216 )
return - V_101 ;
V_31 = F_74 ( & V_216 , L_4 ) ;
F_40 ( & V_69 ) ;
V_25 = - V_101 ;
V_53 = F_178 ( V_68 , system , V_31 ) ;
if ( ! V_53 )
goto V_126;
V_66 = strcmp ( V_215 , V_209 ) == 0 ;
if ( V_66 )
V_208 = V_216 ? & V_219 : & V_220 ;
else
V_208 = V_216 ? & V_221 : & V_222 ;
if ( V_214 [ 0 ] == '!' ) {
F_186 ( V_214 + 1 , V_208 ) ;
V_25 = 0 ;
goto V_126;
}
V_25 = - V_22 ;
V_52 = F_126 ( sizeof( * V_52 ) , V_140 ) ;
if ( ! V_52 )
goto V_126;
V_52 -> V_66 = V_66 ;
V_52 -> V_206 = - 1 ;
V_52 -> V_53 = V_53 ;
if ( ! V_216 )
goto V_223;
V_218 = F_74 ( & V_216 , L_4 ) ;
V_25 = - V_101 ;
if ( ! strlen ( V_218 ) )
goto V_155;
V_25 = F_187 ( V_218 , 0 , & V_52 -> V_206 ) ;
if ( V_25 )
goto V_155;
V_223:
V_25 = F_188 ( V_53 -> V_6 -> V_172 ) ;
if ( ! V_25 ) {
V_25 = - V_191 ;
goto V_155;
}
V_25 = F_48 ( V_53 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_116;
V_25 = F_189 ( V_214 , V_208 , V_52 ) ;
if ( ! V_25 ) {
V_25 = - V_224 ;
goto V_225;
} else if ( V_25 < 0 )
goto V_225;
V_25 = 0 ;
V_126:
F_47 ( & V_69 ) ;
return V_25 ;
V_225:
F_48 ( V_53 , 0 , 1 ) ;
V_116:
F_184 ( V_53 -> V_6 -> V_172 ) ;
V_155:
F_58 ( V_52 ) ;
goto V_126;
}
static T_5 int F_190 ( void )
{
int V_25 ;
V_25 = F_191 ( & V_226 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_191 ( & V_227 ) ;
if ( F_13 ( V_25 < 0 ) )
F_192 ( & V_226 ) ;
return V_25 ;
}
static inline int F_190 ( void ) { return 0 ; }
static T_5 void
F_193 ( struct V_67 * V_68 )
{
struct V_35 * V_53 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_147 ( V_68 -> V_189 , V_53 ) ;
if ( V_25 < 0 )
F_144 ( L_31 ,
F_52 ( V_53 -> V_6 ) ) ;
}
}
static T_5 void
F_194 ( struct V_67 * V_68 )
{
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_57 ( V_14 -> V_172 ) )
continue;
V_25 = F_164 ( V_14 , V_68 ) ;
if ( V_25 < 0 )
F_144 ( L_36 ,
F_52 ( V_14 ) ) ;
}
}
static void
F_195 ( struct V_67 * V_68 )
{
struct V_35 * V_53 , * V_29 ;
F_17 (file, next, &tr->events, list)
F_65 ( V_53 ) ;
}
static void F_166 ( struct V_5 * V_14 )
{
struct V_67 * V_68 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_163 ( V_14 , V_68 ) ;
}
static T_5 int F_196 ( char * V_228 )
{
F_197 ( V_229 , V_228 , V_230 ) ;
V_231 = true ;
V_232 = true ;
return 1 ;
}
static int
F_198 ( struct V_93 * V_157 , struct V_67 * V_68 )
{
struct V_93 * V_162 ;
struct V_93 * V_41 ;
V_41 = F_145 ( L_37 , 0644 , V_157 ,
V_68 , & V_233 ) ;
if ( ! V_41 ) {
F_144 ( L_38 ) ;
return - V_22 ;
}
V_162 = F_143 ( L_39 , V_157 ) ;
if ( ! V_162 ) {
F_144 ( L_40 ) ;
return - V_22 ;
}
F_146 ( L_41 , 0444 , V_162 ,
V_234 ,
& V_235 ) ;
F_146 ( L_42 , 0444 , V_162 ,
V_236 ,
& V_235 ) ;
F_146 ( L_21 , 0644 , V_162 ,
V_68 , & V_237 ) ;
V_68 -> V_189 = V_162 ;
return 0 ;
}
int F_199 ( struct V_93 * V_157 , struct V_67 * V_68 )
{
int V_25 ;
F_40 ( & V_69 ) ;
V_25 = F_198 ( V_157 , V_68 ) ;
if ( V_25 )
goto V_238;
F_158 ( & V_186 ) ;
F_177 ( V_68 ) ;
F_159 ( & V_186 ) ;
V_238:
F_47 ( & V_69 ) ;
return V_25 ;
}
static T_5 int
F_200 ( struct V_93 * V_157 , struct V_67 * V_68 )
{
int V_25 ;
F_40 ( & V_69 ) ;
V_25 = F_198 ( V_157 , V_68 ) ;
if ( V_25 )
goto V_238;
F_158 ( & V_186 ) ;
F_193 ( V_68 ) ;
F_159 ( & V_186 ) ;
V_238:
F_47 ( & V_69 ) ;
return V_25 ;
}
int F_201 ( struct V_67 * V_68 )
{
F_40 ( & V_69 ) ;
F_202 ( V_68 ) ;
F_71 ( V_68 , NULL , NULL , NULL , 0 ) ;
F_203 () ;
F_158 ( & V_186 ) ;
F_195 ( V_68 ) ;
F_64 ( V_68 -> V_189 ) ;
F_159 ( & V_186 ) ;
V_68 -> V_189 = NULL ;
F_47 ( & V_69 ) ;
return 0 ;
}
static T_5 int F_204 ( void )
{
V_20 = F_205 ( V_10 , V_239 ) ;
V_97 = F_205 ( V_35 , V_239 ) ;
return 0 ;
}
static T_5 void
F_206 ( struct V_67 * V_68 , bool V_240 )
{
char * V_103 = V_229 ;
char * V_241 ;
int V_25 ;
while ( true ) {
V_241 = F_74 ( & V_103 , L_43 ) ;
if ( ! V_241 )
break;
if ( ! * V_241 )
continue;
if ( V_240 )
F_73 ( V_68 , V_241 , 0 ) ;
V_25 = F_73 ( V_68 , V_241 , 1 ) ;
if ( V_25 )
F_144 ( L_44 , V_241 ) ;
if ( V_103 )
* ( V_103 - 1 ) = ',' ;
}
}
static T_5 int F_207 ( void )
{
struct V_67 * V_68 = F_76 () ;
struct V_5 * * V_44 , * V_14 ;
int V_25 ;
if ( ! V_68 )
return - V_32 ;
F_173 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_14 = * V_44 ;
V_25 = F_153 ( V_14 ) ;
if ( ! V_25 )
F_11 ( & V_14 -> V_87 , & V_173 ) ;
}
F_194 ( V_68 ) ;
F_206 ( V_68 , false ) ;
F_208 () ;
F_190 () ;
F_209 () ;
return 0 ;
}
static T_5 int F_210 ( void )
{
struct V_67 * V_68 ;
V_68 = F_76 () ;
if ( ! V_68 )
return - V_32 ;
F_206 ( V_68 , true ) ;
return 0 ;
}
static T_5 int F_211 ( void )
{
struct V_67 * V_68 ;
struct V_93 * V_242 ;
struct V_93 * V_41 ;
int V_25 ;
V_68 = F_76 () ;
if ( ! V_68 )
return - V_32 ;
V_242 = F_212 () ;
if ( F_213 ( V_242 ) )
return 0 ;
V_41 = F_145 ( L_45 , 0444 , V_242 ,
V_68 , & V_243 ) ;
if ( ! V_41 )
F_144 ( L_46 ) ;
if ( F_14 () )
F_144 ( L_47 ) ;
V_25 = F_200 ( V_242 , V_68 ) ;
if ( V_25 )
return V_25 ;
#ifdef F_214
V_25 = F_215 ( & V_244 ) ;
if ( V_25 )
F_144 ( L_48 ) ;
#endif
return 0 ;
}
void T_5 F_216 ( void )
{
F_204 () ;
F_217 () ;
F_207 () ;
}
static T_5 void F_218 ( struct V_245 * V_246 )
{
F_66 ( & V_247 ) ;
F_219 ( & V_248 ) ;
F_220 ( 1 ) ;
F_221 ( & V_248 ) ;
F_69 ( & V_247 ) ;
F_40 ( & V_249 ) ;
F_222 ( 1 ) ;
F_47 ( & V_249 ) ;
}
static T_5 int F_223 ( void * V_250 )
{
void * V_251 ;
V_251 = F_112 ( 1234 , V_140 ) ;
if ( ! V_251 )
F_51 ( L_49 ) ;
F_224 ( F_218 ) ;
F_58 ( V_251 ) ;
F_225 ( V_252 ) ;
while ( ! F_226 () ) {
F_227 () ;
F_225 ( V_252 ) ;
}
F_228 ( V_253 ) ;
return 0 ;
}
static T_5 void F_229 ( void )
{
struct V_254 * V_255 ;
V_255 = F_230 ( F_223 , NULL , L_50 ) ;
F_222 ( 1 ) ;
F_231 ( V_255 ) ;
}
static T_5 void F_232 ( void )
{
struct V_89 * V_90 ;
struct V_35 * V_53 ;
struct V_5 * V_14 ;
struct V_1 * system ;
struct V_67 * V_68 ;
int V_25 ;
V_68 = F_76 () ;
if ( ! V_68 )
return;
F_51 ( L_51 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_53 -> V_6 ;
if ( ! V_14 -> V_7 || ! V_14 -> V_7 -> V_57 )
continue;
#ifndef F_233
if ( V_14 -> V_7 -> system &&
strcmp ( V_14 -> V_7 -> system , L_52 ) == 0 )
continue;
#endif
F_51 ( L_53 , F_52 ( V_14 ) ) ;
if ( V_53 -> V_38 & V_70 ) {
F_144 ( L_54 ) ;
F_57 ( 1 ) ;
continue;
}
F_54 ( V_53 , 1 ) ;
F_229 () ;
F_54 ( V_53 , 0 ) ;
F_234 ( L_55 ) ;
}
F_51 ( L_56 ) ;
F_6 (dir, &tr->systems, list) {
system = V_90 -> V_91 ;
if ( strcmp ( system -> V_12 , L_57 ) == 0 )
continue;
F_51 ( L_58 , system -> V_12 ) ;
V_25 = F_72 ( V_68 , NULL , system -> V_12 , NULL , 1 ) ;
if ( F_57 ( V_25 ) ) {
F_144 ( L_59 ,
system -> V_12 ) ;
continue;
}
F_229 () ;
V_25 = F_72 ( V_68 , NULL , system -> V_12 , NULL , 0 ) ;
if ( F_57 ( V_25 ) ) {
F_144 ( L_60 ,
system -> V_12 ) ;
continue;
}
F_234 ( L_55 ) ;
}
F_51 ( L_61 ) ;
F_51 ( L_62 ) ;
V_25 = F_72 ( V_68 , NULL , NULL , NULL , 1 ) ;
if ( F_57 ( V_25 ) ) {
F_144 ( L_63 ) ;
return;
}
F_229 () ;
V_25 = F_72 ( V_68 , NULL , NULL , NULL , 0 ) ;
if ( F_57 ( V_25 ) ) {
F_144 ( L_64 ) ;
return;
}
F_234 ( L_55 ) ;
}
static void
F_235 ( unsigned long V_201 , unsigned long V_202 ,
struct V_256 * V_257 , struct V_258 * V_258 )
{
struct V_259 * V_31 ;
struct V_260 * V_40 ;
struct V_261 * V_41 ;
unsigned long V_38 ;
long V_262 ;
int V_263 ;
int V_39 ;
V_39 = F_24 () ;
F_236 () ;
V_263 = F_237 () ;
V_262 = F_50 ( & F_238 ( V_264 , V_263 ) ) ;
if ( V_262 != 1 )
goto V_126;
F_23 ( V_38 ) ;
V_31 = F_239 ( & V_40 ,
V_265 , sizeof( * V_41 ) ,
V_38 , V_39 ) ;
if ( ! V_31 )
goto V_126;
V_41 = F_26 ( V_31 ) ;
V_41 -> V_201 = V_201 ;
V_41 -> V_202 = V_202 ;
F_240 ( V_40 , V_31 , V_38 , V_39 ) ;
V_126:
F_241 ( & F_238 ( V_264 , V_263 ) ) ;
F_242 () ;
}
static T_5 void F_243 ( void )
{
int V_25 ;
V_25 = F_244 ( & V_266 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_51 ( L_65 ) ;
return;
}
F_51 ( L_66 ) ;
F_232 () ;
F_245 ( & V_266 ) ;
}
static T_5 void F_243 ( void )
{
}
static T_5 int F_246 ( void )
{
if ( ! V_232 ) {
F_232 () ;
F_243 () ;
}
return 0 ;
}
