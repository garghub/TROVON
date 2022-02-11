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
int F_22 ( struct V_5 * V_14 ,
enum V_33 type , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
switch ( type ) {
case V_37 :
return F_23 ( V_14 -> V_12 ,
V_14 -> V_7 -> V_38 ,
V_36 ) ;
case V_39 :
F_24 ( V_14 -> V_12 ,
V_14 -> V_7 -> V_38 ,
V_36 ) ;
return 0 ;
#ifdef F_25
case V_40 :
return F_23 ( V_14 -> V_12 ,
V_14 -> V_7 -> V_41 ,
V_14 ) ;
case V_42 :
F_24 ( V_14 -> V_12 ,
V_14 -> V_7 -> V_41 ,
V_14 ) ;
return 0 ;
case V_43 :
case V_44 :
case V_45 :
case V_46 :
return 0 ;
#endif
}
return 0 ;
}
void F_26 ( bool V_47 )
{
struct V_35 * V_36 ;
struct V_48 * V_49 ;
F_27 ( & V_50 ) ;
F_28 (tr, file) {
if ( ! ( V_36 -> V_51 & V_52 ) )
continue;
if ( V_47 ) {
F_29 () ;
F_30 ( V_53 , & V_36 -> V_51 ) ;
} else {
F_31 () ;
F_32 ( V_53 , & V_36 -> V_51 ) ;
}
} F_33 () ;
F_34 ( & V_50 ) ;
}
static int F_35 ( struct V_35 * V_36 ,
int V_47 , int V_54 )
{
struct V_5 * V_14 = V_36 -> V_6 ;
int V_25 = 0 ;
int V_55 ;
switch ( V_47 ) {
case 0 :
if ( V_54 ) {
if ( F_36 ( & V_36 -> V_56 ) > 0 )
break;
V_55 = V_36 -> V_51 & V_57 ;
F_32 ( V_58 , & V_36 -> V_51 ) ;
} else
V_55 = ! ( V_36 -> V_51 & V_59 ) ;
if ( V_55 && ( V_36 -> V_51 & V_52 ) ) {
F_32 ( V_60 , & V_36 -> V_51 ) ;
if ( V_36 -> V_51 & V_61 ) {
F_31 () ;
F_32 ( V_53 , & V_36 -> V_51 ) ;
}
V_14 -> V_7 -> V_62 ( V_14 , V_39 , V_36 ) ;
}
if ( V_36 -> V_51 & V_59 )
F_30 ( V_63 , & V_36 -> V_51 ) ;
else
F_32 ( V_63 , & V_36 -> V_51 ) ;
break;
case 1 :
if ( ! V_54 )
F_32 ( V_63 , & V_36 -> V_51 ) ;
else {
if ( F_37 ( & V_36 -> V_56 ) > 1 )
break;
F_30 ( V_58 , & V_36 -> V_51 ) ;
}
if ( ! ( V_36 -> V_51 & V_52 ) ) {
if ( V_54 )
F_30 ( V_63 , & V_36 -> V_51 ) ;
if ( V_64 & V_65 ) {
F_29 () ;
F_30 ( V_53 , & V_36 -> V_51 ) ;
}
V_25 = V_14 -> V_7 -> V_62 ( V_14 , V_37 , V_36 ) ;
if ( V_25 ) {
F_31 () ;
F_38 ( L_1
L_2 , V_14 -> V_12 ) ;
break;
}
F_30 ( V_60 , & V_36 -> V_51 ) ;
V_14 -> V_51 |= V_66 ;
}
break;
}
return V_25 ;
}
static int F_39 ( struct V_35 * V_36 ,
int V_47 )
{
return F_35 ( V_36 , V_47 , 0 ) ;
}
static void F_40 ( struct V_48 * V_49 )
{
struct V_35 * V_36 ;
F_27 ( & V_50 ) ;
F_6 (file, &tr->events, list) {
F_39 ( V_36 , 0 ) ;
}
F_34 ( & V_50 ) ;
}
static void F_41 ( struct V_1 * system )
{
struct V_67 * V_68 = system -> V_68 ;
F_42 ( F_1 ( system ) == 0 ) ;
if ( F_3 ( system ) )
return;
F_18 ( & system -> V_69 ) ;
if ( V_68 ) {
F_43 ( V_68 -> V_70 ) ;
F_43 ( V_68 ) ;
}
if ( system -> V_2 & V_3 )
F_43 ( system -> V_12 ) ;
F_43 ( system ) ;
}
static void F_44 ( struct V_1 * system )
{
F_42 ( F_1 ( system ) == 0 ) ;
F_2 ( system ) ;
}
static void F_45 ( struct V_71 * V_72 )
{
F_42 ( V_72 -> V_2 == 0 ) ;
V_72 -> V_2 ++ ;
F_44 ( V_72 -> V_73 ) ;
}
static void F_46 ( struct V_71 * V_72 )
{
F_42 ( V_72 -> V_2 == 0 ) ;
F_42 ( F_1 ( V_72 -> V_73 ) == 1 && V_72 -> V_2 != 1 ) ;
F_41 ( V_72 -> V_73 ) ;
if ( ! -- V_72 -> V_2 )
F_43 ( V_72 ) ;
}
static void F_47 ( struct V_71 * V_72 )
{
F_27 ( & V_50 ) ;
F_46 ( V_72 ) ;
F_34 ( & V_50 ) ;
}
static void F_48 ( struct V_71 * V_72 )
{
if ( ! V_72 )
return;
if ( ! -- V_72 -> V_74 ) {
F_49 ( V_72 -> V_75 ) ;
F_18 ( & V_72 -> V_69 ) ;
F_46 ( V_72 ) ;
}
}
static void * F_50 ( struct V_36 * V_76 )
{
return F_51 ( F_52 ( V_76 ) -> V_77 ) ;
}
static void F_53 ( struct V_35 * V_36 )
{
struct V_78 * V_72 = V_36 -> V_72 ;
struct V_78 * V_79 ;
if ( V_72 ) {
F_54 ( & V_72 -> V_80 ) ;
F_6 (child, &dir->d_subdirs, d_u.d_child) {
if ( V_79 -> V_81 )
V_79 -> V_81 -> V_77 = NULL ;
}
F_55 ( & V_72 -> V_80 ) ;
F_49 ( V_72 ) ;
}
F_18 ( & V_36 -> V_69 ) ;
F_48 ( V_36 -> system ) ;
F_19 ( V_82 , V_36 ) ;
}
static int
F_56 ( struct V_48 * V_49 , const char * V_83 ,
const char * V_84 , const char * V_31 , int V_85 )
{
struct V_35 * V_36 ;
struct V_5 * V_14 ;
int V_25 = - V_86 ;
F_6 (file, &tr->events, list) {
V_14 = V_36 -> V_6 ;
if ( ! V_14 -> V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_62 )
continue;
if ( V_14 -> V_51 & V_87 )
continue;
if ( V_83 &&
strcmp ( V_83 , V_14 -> V_12 ) != 0 &&
strcmp ( V_83 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_84 && strcmp ( V_84 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_31 && strcmp ( V_31 , V_14 -> V_12 ) != 0 )
continue;
F_39 ( V_36 , V_85 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static int F_57 ( struct V_48 * V_49 , const char * V_83 ,
const char * V_84 , const char * V_31 , int V_85 )
{
int V_25 ;
F_27 ( & V_50 ) ;
V_25 = F_56 ( V_49 , V_83 , V_84 , V_31 , V_85 ) ;
F_34 ( & V_50 ) ;
return V_25 ;
}
static int F_58 ( struct V_48 * V_49 , char * V_88 , int V_85 )
{
char * V_31 = NULL , * V_84 = NULL , * V_83 ;
V_83 = F_59 ( & V_88 , L_3 ) ;
if ( V_88 ) {
V_84 = V_83 ;
V_31 = V_88 ;
V_83 = NULL ;
if ( ! strlen ( V_84 ) || strcmp ( V_84 , L_4 ) == 0 )
V_84 = NULL ;
if ( ! strlen ( V_31 ) || strcmp ( V_31 , L_4 ) == 0 )
V_31 = NULL ;
}
return F_57 ( V_49 , V_83 , V_84 , V_31 , V_85 ) ;
}
int F_60 ( const char * system , const char * V_31 , int V_85 )
{
struct V_48 * V_49 = F_61 () ;
return F_57 ( V_49 , NULL , system , V_31 , V_85 ) ;
}
static T_1
F_62 ( struct V_36 * V_36 , const char T_2 * V_89 ,
T_3 V_90 , T_4 * V_91 )
{
struct V_92 V_93 ;
struct V_94 * V_95 = V_36 -> V_96 ;
struct V_48 * V_49 = V_95 -> V_97 ;
T_1 V_98 , V_25 ;
if ( ! V_90 )
return 0 ;
V_25 = F_63 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_64 ( & V_93 , V_99 + 1 ) )
return - V_22 ;
V_98 = F_65 ( & V_93 , V_89 , V_90 , V_91 ) ;
if ( V_98 >= 0 && F_66 ( ( & V_93 ) ) ) {
int V_85 = 1 ;
if ( * V_93 . V_100 == '!' )
V_85 = 0 ;
V_93 . V_100 [ V_93 . V_101 ] = 0 ;
V_25 = F_58 ( V_49 , V_93 . V_100 + ! V_85 , V_85 ) ;
if ( V_25 )
goto V_102;
}
V_25 = V_98 ;
V_102:
F_67 ( & V_93 ) ;
return V_25 ;
}
static void *
F_68 ( struct V_94 * V_95 , void * V_103 , T_4 * V_104 )
{
struct V_35 * V_36 = V_103 ;
struct V_5 * V_14 ;
struct V_48 * V_49 = V_95 -> V_97 ;
( * V_104 ) ++ ;
F_69 (file, &tr->events, list) {
V_14 = V_36 -> V_6 ;
if ( V_14 -> V_7 && V_14 -> V_7 -> V_62 )
return V_36 ;
}
return NULL ;
}
static void * F_70 ( struct V_94 * V_95 , T_4 * V_104 )
{
struct V_35 * V_36 ;
struct V_48 * V_49 = V_95 -> V_97 ;
T_4 V_105 ;
F_27 ( & V_50 ) ;
V_36 = F_71 ( & V_49 -> V_106 , struct V_35 , V_69 ) ;
for ( V_105 = 0 ; V_105 <= * V_104 ; ) {
V_36 = F_68 ( V_95 , V_36 , & V_105 ) ;
if ( ! V_36 )
break;
}
return V_36 ;
}
static void *
F_72 ( struct V_94 * V_95 , void * V_103 , T_4 * V_104 )
{
struct V_35 * V_36 = V_103 ;
struct V_48 * V_49 = V_95 -> V_97 ;
( * V_104 ) ++ ;
F_69 (file, &tr->events, list) {
if ( V_36 -> V_51 & V_52 )
return V_36 ;
}
return NULL ;
}
static void * F_73 ( struct V_94 * V_95 , T_4 * V_104 )
{
struct V_35 * V_36 ;
struct V_48 * V_49 = V_95 -> V_97 ;
T_4 V_105 ;
F_27 ( & V_50 ) ;
V_36 = F_71 ( & V_49 -> V_106 , struct V_35 , V_69 ) ;
for ( V_105 = 0 ; V_105 <= * V_104 ; ) {
V_36 = F_72 ( V_95 , V_36 , & V_105 ) ;
if ( ! V_36 )
break;
}
return V_36 ;
}
static int F_74 ( struct V_94 * V_95 , void * V_103 )
{
struct V_35 * V_36 = V_103 ;
struct V_5 * V_14 = V_36 -> V_6 ;
if ( strcmp ( V_14 -> V_7 -> system , V_107 ) != 0 )
F_75 ( V_95 , L_5 , V_14 -> V_7 -> system ) ;
F_75 ( V_95 , L_2 , V_14 -> V_12 ) ;
return 0 ;
}
static void F_76 ( struct V_94 * V_95 , void * V_108 )
{
F_34 ( & V_50 ) ;
}
static T_1
F_77 ( struct V_36 * V_76 , char T_2 * V_89 , T_3 V_90 ,
T_4 * V_91 )
{
struct V_35 * V_36 ;
unsigned long V_51 ;
char V_88 [ 4 ] = L_6 ;
F_27 ( & V_50 ) ;
V_36 = F_50 ( V_76 ) ;
if ( F_78 ( V_36 ) )
V_51 = V_36 -> V_51 ;
F_34 ( & V_50 ) ;
if ( ! V_36 )
return - V_32 ;
if ( V_51 & V_52 &&
! ( V_51 & V_57 ) )
strcpy ( V_88 , L_7 ) ;
if ( V_51 & V_57 ||
V_51 & V_59 )
strcat ( V_88 , L_4 ) ;
strcat ( V_88 , L_8 ) ;
return F_79 ( V_89 , V_90 , V_91 , V_88 , strlen ( V_88 ) ) ;
}
static T_1
F_80 ( struct V_36 * V_76 , const char T_2 * V_89 , T_3 V_90 ,
T_4 * V_91 )
{
struct V_35 * V_36 ;
unsigned long V_109 ;
int V_25 ;
V_25 = F_81 ( V_89 , V_90 , 10 , & V_109 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_63 () ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_109 ) {
case 0 :
case 1 :
V_25 = - V_32 ;
F_27 ( & V_50 ) ;
V_36 = F_50 ( V_76 ) ;
if ( F_78 ( V_36 ) )
V_25 = F_39 ( V_36 , V_109 ) ;
F_34 ( & V_50 ) ;
break;
default:
return - V_86 ;
}
* V_91 += V_90 ;
return V_25 ? V_25 : V_90 ;
}
static T_1
F_82 ( struct V_36 * V_76 , char T_2 * V_89 , T_3 V_90 ,
T_4 * V_91 )
{
const char V_110 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_71 * V_72 = V_76 -> V_96 ;
struct V_1 * system = V_72 -> V_73 ;
struct V_5 * V_14 ;
struct V_35 * V_36 ;
struct V_48 * V_49 = V_72 -> V_49 ;
char V_88 [ 2 ] ;
int V_85 = 0 ;
int V_25 ;
F_27 ( & V_50 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_36 -> V_6 ;
if ( ! V_14 -> V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_62 )
continue;
if ( system && strcmp ( V_14 -> V_7 -> system , system -> V_12 ) != 0 )
continue;
V_85 |= ( 1 << ! ! ( V_36 -> V_51 & V_52 ) ) ;
if ( V_85 == 3 )
break;
}
F_34 ( & V_50 ) ;
V_88 [ 0 ] = V_110 [ V_85 ] ;
V_88 [ 1 ] = '\n' ;
V_25 = F_79 ( V_89 , V_90 , V_91 , V_88 , 2 ) ;
return V_25 ;
}
static T_1
F_83 ( struct V_36 * V_76 , const char T_2 * V_89 , T_3 V_90 ,
T_4 * V_91 )
{
struct V_71 * V_72 = V_76 -> V_96 ;
struct V_1 * system = V_72 -> V_73 ;
const char * V_12 = NULL ;
unsigned long V_109 ;
T_1 V_25 ;
V_25 = F_81 ( V_89 , V_90 , 10 , & V_109 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_63 () ;
if ( V_25 < 0 )
return V_25 ;
if ( V_109 != 0 && V_109 != 1 )
return - V_86 ;
if ( system )
V_12 = system -> V_12 ;
V_25 = F_57 ( V_72 -> V_49 , NULL , V_12 , NULL , V_109 ) ;
if ( V_25 )
goto V_111;
V_25 = V_90 ;
V_111:
* V_91 += V_90 ;
return V_25 ;
}
static void * F_84 ( struct V_94 * V_95 , void * V_103 , T_4 * V_104 )
{
struct V_5 * V_14 = F_50 ( V_95 -> V_97 ) ;
struct V_4 * V_112 = & V_15 ;
struct V_4 * V_11 = F_4 ( V_14 ) ;
struct V_4 * V_113 = V_103 ;
( * V_104 ) ++ ;
switch ( ( unsigned long ) V_103 ) {
case V_114 :
V_113 = V_112 ;
break;
case V_115 :
V_113 = V_11 ;
break;
case V_116 :
return NULL ;
}
V_113 = V_113 -> V_117 ;
if ( V_113 == V_112 )
return ( void * ) V_115 ;
else if ( V_113 == V_11 )
return ( void * ) V_116 ;
else
return V_113 ;
}
static int F_85 ( struct V_94 * V_95 , void * V_103 )
{
struct V_5 * V_14 = F_50 ( V_95 -> V_97 ) ;
struct V_10 * V_13 ;
const char * V_118 ;
switch ( ( unsigned long ) V_103 ) {
case V_114 :
F_75 ( V_95 , L_9 , V_14 -> V_12 ) ;
F_75 ( V_95 , L_10 , V_14 -> V_31 . type ) ;
F_75 ( V_95 , L_11 ) ;
return 0 ;
case V_115 :
F_86 ( V_95 , '\n' ) ;
return 0 ;
case V_116 :
F_75 ( V_95 , L_12 ,
V_14 -> V_119 ) ;
return 0 ;
}
V_13 = F_71 ( V_103 , struct V_10 , V_24 ) ;
V_118 = strchr ( V_13 -> type , '[' ) ;
if ( ! strncmp ( V_13 -> type , L_13 , 10 ) )
V_118 = NULL ;
if ( ! V_118 )
F_75 ( V_95 , L_14 ,
V_13 -> type , V_13 -> V_12 , V_13 -> V_16 ,
V_13 -> V_17 , ! ! V_13 -> V_18 ) ;
else
F_75 ( V_95 , L_15 ,
( int ) ( V_118 - V_13 -> type ) ,
V_13 -> type , V_13 -> V_12 ,
V_118 , V_13 -> V_16 ,
V_13 -> V_17 , ! ! V_13 -> V_18 ) ;
return 0 ;
}
static void * F_87 ( struct V_94 * V_95 , T_4 * V_104 )
{
void * V_108 = ( void * ) V_114 ;
T_4 V_105 = 0 ;
F_27 ( & V_50 ) ;
if ( ! F_50 ( V_95 -> V_97 ) )
return F_88 ( - V_32 ) ;
while ( V_105 < * V_104 && V_108 )
V_108 = F_84 ( V_95 , V_108 , & V_105 ) ;
return V_108 ;
}
static void F_89 ( struct V_94 * V_95 , void * V_108 )
{
F_34 ( & V_50 ) ;
}
static int F_90 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
struct V_94 * V_95 ;
int V_25 ;
V_25 = F_91 ( V_36 , & V_121 ) ;
if ( V_25 < 0 )
return V_25 ;
V_95 = V_36 -> V_96 ;
V_95 -> V_97 = V_36 ;
return 0 ;
}
static T_1
F_92 ( struct V_36 * V_76 , char T_2 * V_89 , T_3 V_90 , T_4 * V_91 )
{
int V_30 = ( long ) F_50 ( V_76 ) ;
char V_88 [ 32 ] ;
int V_122 ;
if ( * V_91 )
return 0 ;
if ( F_93 ( ! V_30 ) )
return - V_32 ;
V_122 = sprintf ( V_88 , L_16 , V_30 ) ;
return F_79 ( V_89 , V_90 , V_91 , V_88 , V_122 ) ;
}
static T_1
F_94 ( struct V_36 * V_76 , char T_2 * V_89 , T_3 V_90 ,
T_4 * V_91 )
{
struct V_5 * V_14 ;
struct V_123 * V_124 ;
int V_125 = - V_32 ;
if ( * V_91 )
return 0 ;
V_124 = F_95 ( sizeof( * V_124 ) , V_126 ) ;
if ( ! V_124 )
return - V_22 ;
F_96 ( V_124 ) ;
F_27 ( & V_50 ) ;
V_14 = F_50 ( V_76 ) ;
if ( V_14 )
F_97 ( V_14 , V_124 ) ;
F_34 ( & V_50 ) ;
if ( V_14 )
V_125 = F_79 ( V_89 , V_90 , V_91 , V_124 -> V_100 , V_124 -> V_122 ) ;
F_43 ( V_124 ) ;
return V_125 ;
}
static T_1
F_98 ( struct V_36 * V_76 , const char T_2 * V_89 , T_3 V_90 ,
T_4 * V_91 )
{
struct V_5 * V_14 ;
char * V_88 ;
int V_127 = - V_32 ;
if ( V_90 >= V_128 )
return - V_86 ;
V_88 = ( char * ) F_99 ( V_129 ) ;
if ( ! V_88 )
return - V_22 ;
if ( F_100 ( V_88 , V_89 , V_90 ) ) {
F_101 ( ( unsigned long ) V_88 ) ;
return - V_130 ;
}
V_88 [ V_90 ] = '\0' ;
F_27 ( & V_50 ) ;
V_14 = F_50 ( V_76 ) ;
if ( V_14 )
V_127 = F_102 ( V_14 , V_88 ) ;
F_34 ( & V_50 ) ;
F_101 ( ( unsigned long ) V_88 ) ;
if ( V_127 < 0 )
return V_127 ;
* V_91 += V_90 ;
return V_90 ;
}
static int F_103 ( struct V_120 * V_120 , struct V_36 * V_76 )
{
struct V_1 * system = NULL ;
struct V_71 * V_72 = NULL ;
struct V_48 * V_49 ;
int V_25 ;
F_27 ( & V_131 ) ;
F_27 ( & V_50 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_72 == V_120 -> V_77 ) {
if ( V_72 -> V_74 ) {
F_45 ( V_72 ) ;
system = V_72 -> V_73 ;
}
goto V_132;
}
}
}
V_132:
F_34 ( & V_50 ) ;
F_34 ( & V_131 ) ;
if ( ! system )
return - V_32 ;
F_13 ( ! V_72 ) ;
if ( F_104 ( V_49 ) < 0 ) {
F_47 ( V_72 ) ;
return - V_32 ;
}
V_25 = F_105 ( V_120 , V_76 ) ;
if ( V_25 < 0 ) {
F_106 ( V_49 ) ;
F_47 ( V_72 ) ;
}
return V_25 ;
}
static int F_107 ( struct V_120 * V_120 , struct V_36 * V_76 )
{
struct V_71 * V_72 ;
struct V_48 * V_49 = V_120 -> V_77 ;
int V_25 ;
if ( F_104 ( V_49 ) < 0 )
return - V_32 ;
V_72 = F_108 ( sizeof( * V_72 ) , V_126 ) ;
if ( ! V_72 ) {
F_106 ( V_49 ) ;
return - V_22 ;
}
V_72 -> V_49 = V_49 ;
V_25 = F_105 ( V_120 , V_76 ) ;
if ( V_25 < 0 ) {
F_106 ( V_49 ) ;
F_43 ( V_72 ) ;
}
V_76 -> V_96 = V_72 ;
return V_25 ;
}
static int F_109 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
struct V_71 * V_72 = V_36 -> V_96 ;
F_106 ( V_72 -> V_49 ) ;
if ( V_72 -> V_73 )
F_47 ( V_72 ) ;
else
F_43 ( V_72 ) ;
return 0 ;
}
static T_1
F_110 ( struct V_36 * V_76 , char T_2 * V_89 , T_3 V_90 ,
T_4 * V_91 )
{
struct V_71 * V_72 = V_76 -> V_96 ;
struct V_1 * system = V_72 -> V_73 ;
struct V_123 * V_124 ;
int V_125 ;
if ( * V_91 )
return 0 ;
V_124 = F_95 ( sizeof( * V_124 ) , V_126 ) ;
if ( ! V_124 )
return - V_22 ;
F_96 ( V_124 ) ;
F_111 ( system , V_124 ) ;
V_125 = F_79 ( V_89 , V_90 , V_91 , V_124 -> V_100 , V_124 -> V_122 ) ;
F_43 ( V_124 ) ;
return V_125 ;
}
static T_1
F_112 ( struct V_36 * V_76 , const char T_2 * V_89 , T_3 V_90 ,
T_4 * V_91 )
{
struct V_71 * V_72 = V_76 -> V_96 ;
char * V_88 ;
int V_127 ;
if ( V_90 >= V_128 )
return - V_86 ;
V_88 = ( char * ) F_99 ( V_129 ) ;
if ( ! V_88 )
return - V_22 ;
if ( F_100 ( V_88 , V_89 , V_90 ) ) {
F_101 ( ( unsigned long ) V_88 ) ;
return - V_130 ;
}
V_88 [ V_90 ] = '\0' ;
V_127 = F_113 ( V_72 , V_88 ) ;
F_101 ( ( unsigned long ) V_88 ) ;
if ( V_127 < 0 )
return V_127 ;
* V_91 += V_90 ;
return V_90 ;
}
static T_1
F_114 ( struct V_36 * V_76 , char T_2 * V_89 , T_3 V_90 , T_4 * V_91 )
{
int (* F_115)( struct V_123 * V_124 ) = V_76 -> V_96 ;
struct V_123 * V_124 ;
int V_125 ;
if ( * V_91 )
return 0 ;
V_124 = F_95 ( sizeof( * V_124 ) , V_126 ) ;
if ( ! V_124 )
return - V_22 ;
F_96 ( V_124 ) ;
F_115 ( V_124 ) ;
V_125 = F_79 ( V_89 , V_90 , V_91 , V_124 -> V_100 , V_124 -> V_122 ) ;
F_43 ( V_124 ) ;
return V_125 ;
}
static int
F_116 ( struct V_120 * V_120 , struct V_36 * V_36 ,
const struct V_133 * V_134 )
{
struct V_94 * V_95 ;
int V_25 ;
V_25 = F_91 ( V_36 , V_134 ) ;
if ( V_25 < 0 )
return V_25 ;
V_95 = V_36 -> V_96 ;
V_95 -> V_97 = V_120 -> V_77 ;
return V_25 ;
}
static int F_117 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
struct V_48 * V_49 = V_120 -> V_77 ;
F_106 ( V_49 ) ;
return F_118 ( V_120 , V_36 ) ;
}
static int
F_119 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
const struct V_133 * V_134 = & V_135 ;
return F_116 ( V_120 , V_36 , V_134 ) ;
}
static int
F_120 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
const struct V_133 * V_134 = & V_136 ;
struct V_48 * V_49 = V_120 -> V_77 ;
int V_25 ;
if ( F_104 ( V_49 ) < 0 )
return - V_32 ;
if ( ( V_36 -> V_137 & V_138 ) &&
( V_36 -> V_139 & V_140 ) )
F_40 ( V_49 ) ;
V_25 = F_116 ( V_120 , V_36 , V_134 ) ;
if ( V_25 < 0 )
F_106 ( V_49 ) ;
return V_25 ;
}
static struct V_1 *
F_121 ( const char * V_12 )
{
struct V_1 * system ;
system = F_95 ( sizeof( * system ) , V_126 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
if ( ! F_122 ( ( unsigned long ) V_12 ) ) {
system -> V_2 |= V_3 ;
system -> V_12 = F_123 ( V_12 , V_126 ) ;
if ( ! system -> V_12 )
goto V_141;
} else
system -> V_12 = V_12 ;
system -> V_68 = NULL ;
system -> V_68 = F_108 ( sizeof( struct V_67 ) , V_126 ) ;
if ( ! system -> V_68 )
goto V_141;
F_11 ( & system -> V_69 , & V_142 ) ;
return system ;
V_141:
if ( system -> V_2 & V_3 )
F_43 ( system -> V_12 ) ;
F_43 ( system ) ;
return NULL ;
}
static struct V_78 *
F_124 ( struct V_48 * V_49 , const char * V_12 ,
struct V_35 * V_36 , struct V_78 * V_143 )
{
struct V_71 * V_72 ;
struct V_1 * system ;
struct V_78 * V_75 ;
F_6 (dir, &tr->systems, list) {
system = V_72 -> V_73 ;
if ( strcmp ( system -> V_12 , V_12 ) == 0 ) {
V_72 -> V_74 ++ ;
V_36 -> system = V_72 ;
return V_72 -> V_75 ;
}
}
F_6 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_12 , V_12 ) == 0 )
break;
}
if ( & system -> V_69 == & V_142 )
system = NULL ;
V_72 = F_95 ( sizeof( * V_72 ) , V_126 ) ;
if ( ! V_72 )
goto V_144;
if ( ! system ) {
system = F_121 ( V_12 ) ;
if ( ! system )
goto V_141;
} else
F_44 ( system ) ;
V_72 -> V_75 = F_125 ( V_12 , V_143 ) ;
if ( ! V_72 -> V_75 ) {
F_126 ( L_17 , V_12 ) ;
F_41 ( system ) ;
goto V_141;
}
V_72 -> V_49 = V_49 ;
V_72 -> V_2 = 1 ;
V_72 -> V_74 = 1 ;
V_72 -> V_73 = system ;
V_36 -> system = V_72 ;
V_75 = F_127 ( L_18 , 0644 , V_72 -> V_75 , V_72 ,
& V_145 ) ;
if ( ! V_75 ) {
F_43 ( system -> V_68 ) ;
system -> V_68 = NULL ;
F_126 ( L_19 , V_12 ) ;
}
F_128 ( L_20 , 0644 , V_72 -> V_75 , V_72 ,
& V_146 ) ;
F_11 ( & V_72 -> V_69 , & V_49 -> V_147 ) ;
return V_72 -> V_75 ;
V_141:
F_43 ( V_72 ) ;
V_144:
if ( ! V_72 || ! system )
F_126 ( L_21 ,
V_12 ) ;
return NULL ;
}
static int
F_129 ( struct V_78 * V_143 ,
struct V_35 * V_36 ,
const struct V_148 * V_30 ,
const struct V_148 * V_47 ,
const struct V_148 * V_68 ,
const struct V_148 * V_149 )
{
struct V_5 * V_14 = V_36 -> V_6 ;
struct V_48 * V_49 = V_36 -> V_49 ;
struct V_4 * V_11 ;
struct V_78 * V_150 ;
int V_25 ;
if ( strcmp ( V_14 -> V_7 -> system , V_107 ) != 0 ) {
V_150 = F_124 ( V_49 , V_14 -> V_7 -> system , V_36 , V_143 ) ;
if ( ! V_150 )
return - V_22 ;
} else
V_150 = V_143 ;
V_36 -> V_72 = F_125 ( V_14 -> V_12 , V_150 ) ;
if ( ! V_36 -> V_72 ) {
F_126 ( L_22 ,
V_14 -> V_12 ) ;
return - 1 ;
}
if ( V_14 -> V_7 -> V_62 && ! ( V_14 -> V_51 & V_87 ) )
F_128 ( L_20 , 0644 , V_36 -> V_72 , V_36 ,
V_47 ) ;
#ifdef F_25
if ( V_14 -> V_31 . type && V_14 -> V_7 -> V_62 )
F_128 ( L_23 , 0444 , V_36 -> V_72 ,
( void * ) ( long ) V_14 -> V_31 . type , V_30 ) ;
#endif
V_11 = F_4 ( V_14 ) ;
if ( F_130 ( V_11 ) ) {
V_25 = V_14 -> V_7 -> V_151 ( V_14 ) ;
if ( V_25 < 0 ) {
F_126 ( L_24
L_25 , V_14 -> V_12 ) ;
return - 1 ;
}
}
F_128 ( L_18 , 0644 , V_36 -> V_72 , V_14 ,
V_68 ) ;
F_128 ( L_26 , 0444 , V_36 -> V_72 , V_14 ,
V_149 ) ;
return 0 ;
}
static void F_131 ( struct V_5 * V_14 )
{
struct V_35 * V_36 ;
struct V_48 * V_49 ;
F_132 (tr, file) {
if ( V_36 -> V_6 != V_14 )
continue;
F_53 ( V_36 ) ;
break;
} F_33 () ;
}
static void F_133 ( struct V_5 * V_14 )
{
struct V_48 * V_49 ;
struct V_35 * V_36 ;
F_28 (tr, file) {
if ( V_36 -> V_6 != V_14 )
continue;
F_39 ( V_36 , 0 ) ;
break;
} F_33 () ;
if ( V_14 -> V_31 . V_152 )
F_134 ( & V_14 -> V_31 ) ;
F_131 ( V_14 ) ;
F_18 ( & V_14 -> V_69 ) ;
}
static int F_135 ( struct V_5 * V_14 )
{
int V_25 = 0 ;
if ( F_13 ( ! V_14 -> V_12 ) )
return - V_86 ;
if ( V_14 -> V_7 -> V_153 ) {
V_25 = V_14 -> V_7 -> V_153 ( V_14 ) ;
if ( V_25 < 0 && V_25 != - V_154 )
F_136 ( L_27 ,
V_14 -> V_12 ) ;
}
return V_25 ;
}
static int
F_137 ( struct V_5 * V_14 , struct V_155 * V_156 )
{
int V_25 ;
V_25 = F_135 ( V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_14 -> V_69 , & V_157 ) ;
V_14 -> V_156 = V_156 ;
return 0 ;
}
static struct V_35 *
F_138 ( struct V_5 * V_14 ,
struct V_48 * V_49 )
{
struct V_35 * V_36 ;
V_36 = F_9 ( V_82 , V_21 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_6 = V_14 ;
V_36 -> V_49 = V_49 ;
F_139 ( & V_36 -> V_56 , 0 ) ;
F_11 ( & V_36 -> V_69 , & V_49 -> V_106 ) ;
return V_36 ;
}
static int
F_140 ( struct V_5 * V_14 ,
struct V_48 * V_49 ,
const struct V_148 * V_30 ,
const struct V_148 * V_47 ,
const struct V_148 * V_68 ,
const struct V_148 * V_149 )
{
struct V_35 * V_36 ;
V_36 = F_138 ( V_14 , V_49 ) ;
if ( ! V_36 )
return - V_22 ;
return F_129 ( V_49 -> V_158 , V_36 , V_30 , V_47 , V_68 , V_149 ) ;
}
static T_5 int
F_141 ( struct V_5 * V_14 ,
struct V_48 * V_49 )
{
struct V_35 * V_36 ;
V_36 = F_138 ( V_14 , V_49 ) ;
if ( ! V_36 )
return - V_22 ;
return 0 ;
}
int F_142 ( struct V_5 * V_14 )
{
int V_25 ;
F_27 ( & V_131 ) ;
F_27 ( & V_50 ) ;
V_25 = F_137 ( V_14 , NULL ) ;
if ( V_25 >= 0 )
F_143 ( V_14 , NULL ) ;
F_34 ( & V_50 ) ;
F_34 ( & V_131 ) ;
return V_25 ;
}
static void F_144 ( struct V_5 * V_14 )
{
F_133 ( V_14 ) ;
F_16 ( V_14 ) ;
F_145 ( V_14 ) ;
}
static int F_146 ( struct V_5 * V_14 )
{
struct V_48 * V_49 ;
struct V_35 * V_36 ;
#ifdef F_25
if ( V_14 -> V_159 )
return - V_160 ;
#endif
F_28 (tr, file) {
if ( V_36 -> V_6 != V_14 )
continue;
if ( V_36 -> V_51 & V_52 )
return - V_160 ;
break;
} F_33 () ;
F_144 ( V_14 ) ;
return 0 ;
}
int F_147 ( struct V_5 * V_14 )
{
int V_25 ;
F_27 ( & V_131 ) ;
F_27 ( & V_50 ) ;
F_148 ( & V_161 ) ;
V_25 = F_146 ( V_14 ) ;
F_149 ( & V_161 ) ;
F_34 ( & V_50 ) ;
F_34 ( & V_131 ) ;
return V_25 ;
}
static struct V_162 *
F_150 ( struct V_162 * V_163 , struct V_155 * V_156 )
{
if ( V_163 && V_156 == V_163 -> V_156 )
return V_163 ;
F_6 (file_ops, &ftrace_module_file_list, list) {
if ( V_163 -> V_156 == V_156 )
return V_163 ;
}
return NULL ;
}
static struct V_162 *
F_151 ( struct V_155 * V_156 )
{
struct V_162 * V_163 ;
V_163 = F_95 ( sizeof( * V_163 ) , V_126 ) ;
if ( ! V_163 )
return NULL ;
V_163 -> V_156 = V_156 ;
V_163 -> V_30 = V_164 ;
V_163 -> V_30 . V_165 = V_156 ;
V_163 -> V_47 = V_166 ;
V_163 -> V_47 . V_165 = V_156 ;
V_163 -> V_68 = V_167 ;
V_163 -> V_68 . V_165 = V_156 ;
V_163 -> V_149 = V_168 ;
V_163 -> V_149 . V_165 = V_156 ;
F_11 ( & V_163 -> V_69 , & V_169 ) ;
return V_163 ;
}
static void F_152 ( struct V_155 * V_156 )
{
struct V_162 * V_163 = NULL ;
struct V_5 * * V_14 , * * V_170 , * * V_171 ;
V_170 = V_156 -> V_172 ;
V_171 = V_156 -> V_172 + V_156 -> V_173 ;
if ( V_170 == V_171 )
return;
V_163 = F_151 ( V_156 ) ;
if ( ! V_163 )
return;
F_153 (call, start, end) {
F_137 ( * V_14 , V_156 ) ;
F_143 ( * V_14 , V_163 ) ;
}
}
static void F_154 ( struct V_155 * V_156 )
{
struct V_162 * V_163 ;
struct V_5 * V_14 , * V_108 ;
bool V_174 = false ;
F_148 ( & V_161 ) ;
F_17 (call, p, &ftrace_events, list) {
if ( V_14 -> V_156 == V_156 ) {
if ( V_14 -> V_51 & V_66 )
V_174 = true ;
F_144 ( V_14 ) ;
}
}
F_6 (file_ops, &ftrace_module_file_list, list) {
if ( V_163 -> V_156 == V_156 )
break;
}
if ( & V_163 -> V_69 != & V_169 ) {
F_18 ( & V_163 -> V_69 ) ;
F_43 ( V_163 ) ;
}
F_149 ( & V_161 ) ;
if ( V_174 )
F_155 () ;
}
static int F_156 ( struct V_175 * V_176 ,
unsigned long V_109 , void * V_34 )
{
struct V_155 * V_156 = V_34 ;
F_27 ( & V_131 ) ;
F_27 ( & V_50 ) ;
switch ( V_109 ) {
case V_177 :
F_152 ( V_156 ) ;
break;
case V_178 :
F_154 ( V_156 ) ;
break;
}
F_34 ( & V_50 ) ;
F_34 ( & V_131 ) ;
return 0 ;
}
static int
F_157 ( struct V_5 * V_14 ,
struct V_48 * V_49 ,
struct V_162 * V_163 )
{
return F_140 ( V_14 , V_49 ,
& V_163 -> V_30 , & V_163 -> V_47 ,
& V_163 -> V_68 , & V_163 -> V_149 ) ;
}
static inline struct V_162 *
F_150 ( struct V_162 * V_163 , struct V_155 * V_156 )
{
return NULL ;
}
static inline int F_156 ( struct V_175 * V_176 ,
unsigned long V_109 , void * V_34 )
{
return 0 ;
}
static inline int
F_157 ( struct V_5 * V_14 ,
struct V_48 * V_49 ,
struct V_162 * V_163 )
{
return - V_32 ;
}
static void
F_158 ( struct V_48 * V_49 )
{
struct V_162 * V_163 = NULL ;
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( V_14 -> V_156 ) {
V_163 = F_150 ( V_163 , V_14 -> V_156 ) ;
if ( ! V_163 )
continue;
V_25 = F_157 ( V_14 , V_49 , V_163 ) ;
if ( V_25 < 0 )
F_126 ( L_28 ,
V_14 -> V_12 ) ;
continue;
}
V_25 = F_140 ( V_14 , V_49 ,
& V_164 ,
& V_166 ,
& V_167 ,
& V_168 ) ;
if ( V_25 < 0 )
F_126 ( L_28 ,
V_14 -> V_12 ) ;
}
}
static struct V_35 *
F_159 ( struct V_48 * V_49 , const char * system , const char * V_31 )
{
struct V_35 * V_36 ;
struct V_5 * V_14 ;
F_6 (file, &tr->events, list) {
V_14 = V_36 -> V_6 ;
if ( ! V_14 -> V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_62 )
continue;
if ( V_14 -> V_51 & V_87 )
continue;
if ( strcmp ( V_31 , V_14 -> V_12 ) == 0 &&
strcmp ( system , V_14 -> V_7 -> system ) == 0 )
return V_36 ;
}
return NULL ;
}
static void
F_160 ( unsigned long V_179 , unsigned long V_180 , void * * V_181 )
{
struct V_182 * * V_183 = (struct V_182 * * ) V_181 ;
struct V_182 * V_34 = * V_183 ;
if ( ! V_34 )
return;
if ( V_34 -> V_47 )
F_32 ( V_63 , & V_34 -> V_36 -> V_51 ) ;
else
F_30 ( V_63 , & V_34 -> V_36 -> V_51 ) ;
}
static void
F_161 ( unsigned long V_179 , unsigned long V_180 , void * * V_181 )
{
struct V_182 * * V_183 = (struct V_182 * * ) V_181 ;
struct V_182 * V_34 = * V_183 ;
if ( ! V_34 )
return;
if ( ! V_34 -> V_184 )
return;
if ( V_34 -> V_47 == ! ( V_34 -> V_36 -> V_51 & V_57 ) )
return;
if ( V_34 -> V_184 != - 1 )
( V_34 -> V_184 ) -- ;
F_160 ( V_179 , V_180 , V_181 ) ;
}
static int
F_162 ( struct V_94 * V_95 , unsigned long V_179 ,
struct V_185 * V_186 , void * V_181 )
{
struct V_182 * V_34 = V_181 ;
F_75 ( V_95 , L_29 , ( void * ) V_179 ) ;
F_75 ( V_95 , L_30 ,
V_34 -> V_47 ? V_187 : V_188 ,
V_34 -> V_36 -> V_6 -> V_7 -> system ,
V_34 -> V_36 -> V_6 -> V_12 ) ;
if ( V_34 -> V_184 == - 1 )
F_75 ( V_95 , L_31 ) ;
else
F_75 ( V_95 , L_32 , V_34 -> V_184 ) ;
return 0 ;
}
static int
F_163 ( struct V_185 * V_186 , unsigned long V_179 ,
void * * V_181 )
{
struct V_182 * * V_183 = (struct V_182 * * ) V_181 ;
struct V_182 * V_34 = * V_183 ;
V_34 -> V_189 ++ ;
return 0 ;
}
static void
F_164 ( struct V_185 * V_186 , unsigned long V_179 ,
void * * V_181 )
{
struct V_182 * * V_183 = (struct V_182 * * ) V_181 ;
struct V_182 * V_34 = * V_183 ;
if ( F_42 ( V_34 -> V_189 <= 0 ) )
return;
V_34 -> V_189 -- ;
if ( ! V_34 -> V_189 ) {
F_35 ( V_34 -> V_36 , 0 , 1 ) ;
F_165 ( V_34 -> V_36 -> V_6 -> V_156 ) ;
F_43 ( V_34 ) ;
}
* V_183 = NULL ;
}
static int
F_166 ( struct V_190 * V_191 ,
char * V_192 , char * V_193 , char * V_194 , int V_195 )
{
struct V_48 * V_49 = F_61 () ;
struct V_35 * V_36 ;
struct V_185 * V_186 ;
struct V_182 * V_34 ;
const char * system ;
const char * V_31 ;
char * V_196 ;
bool V_47 ;
int V_25 ;
if ( ! V_195 || ! V_194 )
return - V_86 ;
system = F_59 ( & V_194 , L_3 ) ;
if ( ! V_194 )
return - V_86 ;
V_31 = F_59 ( & V_194 , L_3 ) ;
F_27 ( & V_50 ) ;
V_25 = - V_86 ;
V_36 = F_159 ( V_49 , system , V_31 ) ;
if ( ! V_36 )
goto V_111;
V_47 = strcmp ( V_193 , V_187 ) == 0 ;
if ( V_47 )
V_186 = V_194 ? & V_197 : & V_198 ;
else
V_186 = V_194 ? & V_199 : & V_200 ;
if ( V_192 [ 0 ] == '!' ) {
F_167 ( V_192 + 1 , V_186 ) ;
V_25 = 0 ;
goto V_111;
}
V_25 = - V_22 ;
V_34 = F_108 ( sizeof( * V_34 ) , V_126 ) ;
if ( ! V_34 )
goto V_111;
V_34 -> V_47 = V_47 ;
V_34 -> V_184 = - 1 ;
V_34 -> V_36 = V_36 ;
if ( ! V_194 )
goto V_201;
V_196 = F_59 ( & V_194 , L_3 ) ;
V_25 = - V_86 ;
if ( ! strlen ( V_196 ) )
goto V_141;
V_25 = F_168 ( V_196 , 0 , & V_34 -> V_184 ) ;
if ( V_25 )
goto V_141;
V_201:
V_25 = F_169 ( V_36 -> V_6 -> V_156 ) ;
if ( ! V_25 ) {
V_25 = - V_160 ;
goto V_141;
}
V_25 = F_35 ( V_36 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_102;
V_25 = F_170 ( V_192 , V_186 , V_34 ) ;
if ( ! V_25 ) {
V_25 = - V_202 ;
goto V_203;
} else if ( V_25 < 0 )
goto V_203;
V_25 = 0 ;
V_111:
F_34 ( & V_50 ) ;
return V_25 ;
V_203:
F_35 ( V_36 , 0 , 1 ) ;
V_102:
F_165 ( V_36 -> V_6 -> V_156 ) ;
V_141:
F_43 ( V_34 ) ;
goto V_111;
}
static T_5 int F_171 ( void )
{
int V_25 ;
V_25 = F_172 ( & V_204 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_172 ( & V_205 ) ;
if ( F_13 ( V_25 < 0 ) )
F_173 ( & V_204 ) ;
return V_25 ;
}
static inline int F_171 ( void ) { return 0 ; }
static T_5 void
F_174 ( struct V_48 * V_49 )
{
struct V_35 * V_36 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_129 ( V_49 -> V_158 , V_36 ,
& V_164 ,
& V_166 ,
& V_167 ,
& V_168 ) ;
if ( V_25 < 0 )
F_126 ( L_28 ,
V_36 -> V_6 -> V_12 ) ;
}
}
static T_5 void
F_175 ( struct V_48 * V_49 )
{
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_42 ( V_14 -> V_156 ) )
continue;
V_25 = F_141 ( V_14 , V_49 ) ;
if ( V_25 < 0 )
F_126 ( L_33 ,
V_14 -> V_12 ) ;
}
}
static void
F_176 ( struct V_48 * V_49 )
{
struct V_35 * V_36 , * V_29 ;
F_17 (file, next, &tr->events, list)
F_53 ( V_36 ) ;
}
static void
F_143 ( struct V_5 * V_14 ,
struct V_162 * V_163 )
{
struct V_48 * V_49 ;
F_6 (tr, &ftrace_trace_arrays, list) {
if ( V_163 )
F_157 ( V_14 , V_49 , V_163 ) ;
else
F_140 ( V_14 , V_49 ,
& V_164 ,
& V_166 ,
& V_167 ,
& V_168 ) ;
}
}
static T_5 int F_177 ( char * V_206 )
{
F_178 ( V_207 , V_206 , V_208 ) ;
V_209 = true ;
V_210 = true ;
return 1 ;
}
static int
F_179 ( struct V_78 * V_143 , struct V_48 * V_49 )
{
struct V_78 * V_150 ;
struct V_78 * V_75 ;
V_75 = F_127 ( L_34 , 0644 , V_143 ,
V_49 , & V_211 ) ;
if ( ! V_75 ) {
F_126 ( L_35 ) ;
return - V_22 ;
}
V_150 = F_125 ( L_36 , V_143 ) ;
if ( ! V_150 ) {
F_126 ( L_37 ) ;
return - V_22 ;
}
F_128 ( L_38 , 0444 , V_150 ,
V_212 ,
& V_213 ) ;
F_128 ( L_39 , 0444 , V_150 ,
V_214 ,
& V_213 ) ;
F_128 ( L_20 , 0644 , V_150 ,
V_49 , & V_215 ) ;
V_49 -> V_158 = V_150 ;
return 0 ;
}
int F_180 ( struct V_78 * V_143 , struct V_48 * V_49 )
{
int V_25 ;
F_27 ( & V_50 ) ;
V_25 = F_179 ( V_143 , V_49 ) ;
if ( V_25 )
goto V_216;
F_148 ( & V_161 ) ;
F_158 ( V_49 ) ;
F_149 ( & V_161 ) ;
V_216:
F_34 ( & V_50 ) ;
return V_25 ;
}
static T_5 int
F_181 ( struct V_78 * V_143 , struct V_48 * V_49 )
{
int V_25 ;
F_27 ( & V_50 ) ;
V_25 = F_179 ( V_143 , V_49 ) ;
if ( V_25 )
goto V_216;
F_148 ( & V_161 ) ;
F_174 ( V_49 ) ;
F_149 ( & V_161 ) ;
V_216:
F_34 ( & V_50 ) ;
return V_25 ;
}
int F_182 ( struct V_48 * V_49 )
{
F_27 ( & V_50 ) ;
F_56 ( V_49 , NULL , NULL , NULL , 0 ) ;
F_148 ( & V_161 ) ;
F_176 ( V_49 ) ;
F_49 ( V_49 -> V_158 ) ;
F_149 ( & V_161 ) ;
V_49 -> V_158 = NULL ;
F_34 ( & V_50 ) ;
return 0 ;
}
static T_5 int F_183 ( void )
{
V_20 = F_184 ( V_10 , V_217 ) ;
V_82 = F_184 ( V_35 , V_217 ) ;
return 0 ;
}
static T_5 int F_185 ( void )
{
struct V_48 * V_49 = F_61 () ;
struct V_5 * * V_218 , * V_14 ;
char * V_88 = V_207 ;
char * V_219 ;
int V_25 ;
F_153 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_14 = * V_218 ;
V_25 = F_135 ( V_14 ) ;
if ( ! V_25 )
F_11 ( & V_14 -> V_69 , & V_157 ) ;
}
F_175 ( V_49 ) ;
while ( true ) {
V_219 = F_59 ( & V_88 , L_40 ) ;
if ( ! V_219 )
break;
if ( ! * V_219 )
continue;
V_25 = F_58 ( V_49 , V_219 , 1 ) ;
if ( V_25 )
F_136 ( L_41 , V_219 ) ;
}
F_186 () ;
F_171 () ;
return 0 ;
}
static T_5 int F_187 ( void )
{
struct V_48 * V_49 ;
struct V_78 * V_220 ;
struct V_78 * V_75 ;
int V_25 ;
V_49 = F_61 () ;
V_220 = F_188 () ;
if ( ! V_220 )
return 0 ;
V_75 = F_127 ( L_42 , 0444 , V_220 ,
V_49 , & V_221 ) ;
if ( ! V_75 )
F_126 ( L_43
L_44 ) ;
if ( F_14 () )
F_126 ( L_45 ) ;
V_25 = F_181 ( V_220 , V_49 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_189 ( & V_222 ) ;
if ( V_25 )
F_126 ( L_46 ) ;
return 0 ;
}
static T_5 void F_190 ( struct V_223 * V_224 )
{
F_54 ( & V_225 ) ;
F_191 ( & V_226 ) ;
F_192 ( 1 ) ;
F_193 ( & V_226 ) ;
F_55 ( & V_225 ) ;
F_27 ( & V_227 ) ;
F_194 ( 1 ) ;
F_34 ( & V_227 ) ;
}
static T_5 int F_195 ( void * V_228 )
{
void * V_229 ;
V_229 = F_95 ( 1234 , V_126 ) ;
if ( ! V_229 )
F_38 ( L_47 ) ;
F_196 ( F_190 ) ;
F_43 ( V_229 ) ;
F_197 ( V_230 ) ;
while ( ! F_198 () )
F_199 () ;
return 0 ;
}
static T_5 void F_200 ( void )
{
struct V_231 * V_232 ;
V_232 = F_201 ( F_195 , NULL , L_48 ) ;
F_194 ( 1 ) ;
F_202 ( V_232 ) ;
}
static T_5 void F_203 ( void )
{
struct V_71 * V_72 ;
struct V_35 * V_36 ;
struct V_5 * V_14 ;
struct V_1 * system ;
struct V_48 * V_49 ;
int V_25 ;
V_49 = F_61 () ;
F_38 ( L_49 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_36 -> V_6 ;
if ( ! V_14 -> V_7 || ! V_14 -> V_7 -> V_38 )
continue;
#ifndef F_204
if ( V_14 -> V_7 -> system &&
strcmp ( V_14 -> V_7 -> system , L_50 ) == 0 )
continue;
#endif
F_38 ( L_51 , V_14 -> V_12 ) ;
if ( V_36 -> V_51 & V_52 ) {
F_126 ( L_52 ) ;
F_42 ( 1 ) ;
continue;
}
F_39 ( V_36 , 1 ) ;
F_200 () ;
F_39 ( V_36 , 0 ) ;
F_205 ( L_53 ) ;
}
F_38 ( L_54 ) ;
F_6 (dir, &tr->systems, list) {
system = V_72 -> V_73 ;
if ( strcmp ( system -> V_12 , L_55 ) == 0 )
continue;
F_38 ( L_56 , system -> V_12 ) ;
V_25 = F_57 ( V_49 , NULL , system -> V_12 , NULL , 1 ) ;
if ( F_42 ( V_25 ) ) {
F_126 ( L_57 ,
system -> V_12 ) ;
continue;
}
F_200 () ;
V_25 = F_57 ( V_49 , NULL , system -> V_12 , NULL , 0 ) ;
if ( F_42 ( V_25 ) ) {
F_126 ( L_58 ,
system -> V_12 ) ;
continue;
}
F_205 ( L_53 ) ;
}
F_38 ( L_59 ) ;
F_38 ( L_60 ) ;
V_25 = F_57 ( V_49 , NULL , NULL , NULL , 1 ) ;
if ( F_42 ( V_25 ) ) {
F_126 ( L_61 ) ;
return;
}
F_200 () ;
V_25 = F_57 ( V_49 , NULL , NULL , NULL , 0 ) ;
if ( F_42 ( V_25 ) ) {
F_126 ( L_62 ) ;
return;
}
F_205 ( L_53 ) ;
}
static void
F_206 ( unsigned long V_179 , unsigned long V_180 ,
struct V_233 * V_234 , struct V_235 * V_235 )
{
struct V_236 * V_31 ;
struct V_237 * V_100 ;
struct V_238 * V_75 ;
unsigned long V_51 ;
long V_239 ;
int V_240 ;
int V_241 ;
V_241 = F_207 () ;
F_208 () ;
V_240 = F_209 () ;
V_239 = F_37 ( & F_210 ( V_242 , V_240 ) ) ;
if ( V_239 != 1 )
goto V_111;
F_211 ( V_51 ) ;
V_31 = F_212 ( & V_100 ,
V_243 , sizeof( * V_75 ) ,
V_51 , V_241 ) ;
if ( ! V_31 )
goto V_111;
V_75 = F_213 ( V_31 ) ;
V_75 -> V_179 = V_179 ;
V_75 -> V_180 = V_180 ;
F_214 ( V_100 , V_31 , V_51 , V_241 ) ;
V_111:
F_215 ( & F_210 ( V_242 , V_240 ) ) ;
F_216 () ;
}
static T_5 void F_217 ( void )
{
int V_25 ;
V_25 = F_218 ( & V_244 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_38 ( L_63 ) ;
return;
}
F_38 ( L_64 ) ;
F_203 () ;
F_219 ( & V_244 ) ;
}
static T_5 void F_217 ( void )
{
}
static T_5 int F_220 ( void )
{
if ( ! V_210 ) {
F_203 () ;
F_217 () ;
}
return 0 ;
}
