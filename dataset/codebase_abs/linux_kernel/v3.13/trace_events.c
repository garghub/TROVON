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
struct V_35 * V_36 ;
struct V_123 * V_124 ;
int V_125 = - V_32 ;
if ( * V_91 )
return 0 ;
V_124 = F_95 ( sizeof( * V_124 ) , V_126 ) ;
if ( ! V_124 )
return - V_22 ;
F_96 ( V_124 ) ;
F_27 ( & V_50 ) ;
V_36 = F_50 ( V_76 ) ;
if ( V_36 )
F_97 ( V_36 , V_124 ) ;
F_34 ( & V_50 ) ;
if ( V_36 )
V_125 = F_79 ( V_89 , V_90 , V_91 , V_124 -> V_100 , V_124 -> V_122 ) ;
F_43 ( V_124 ) ;
return V_125 ;
}
static T_1
F_98 ( struct V_36 * V_76 , const char T_2 * V_89 , T_3 V_90 ,
T_4 * V_91 )
{
struct V_35 * V_36 ;
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
V_36 = F_50 ( V_76 ) ;
if ( V_36 )
V_127 = F_102 ( V_36 , V_88 ) ;
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
if ( F_104 () )
return - V_32 ;
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
if ( F_105 ( V_49 ) < 0 ) {
F_47 ( V_72 ) ;
return - V_32 ;
}
V_25 = F_106 ( V_120 , V_76 ) ;
if ( V_25 < 0 ) {
F_107 ( V_49 ) ;
F_47 ( V_72 ) ;
}
return V_25 ;
}
static int F_108 ( struct V_120 * V_120 , struct V_36 * V_76 )
{
struct V_71 * V_72 ;
struct V_48 * V_49 = V_120 -> V_77 ;
int V_25 ;
if ( F_104 () )
return - V_32 ;
if ( F_105 ( V_49 ) < 0 )
return - V_32 ;
V_72 = F_109 ( sizeof( * V_72 ) , V_126 ) ;
if ( ! V_72 ) {
F_107 ( V_49 ) ;
return - V_22 ;
}
V_72 -> V_49 = V_49 ;
V_25 = F_106 ( V_120 , V_76 ) ;
if ( V_25 < 0 ) {
F_107 ( V_49 ) ;
F_43 ( V_72 ) ;
return V_25 ;
}
V_76 -> V_96 = V_72 ;
return 0 ;
}
static int F_110 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
struct V_71 * V_72 = V_36 -> V_96 ;
F_107 ( V_72 -> V_49 ) ;
if ( V_72 -> V_73 )
F_47 ( V_72 ) ;
else
F_43 ( V_72 ) ;
return 0 ;
}
static T_1
F_111 ( struct V_36 * V_76 , char T_2 * V_89 , T_3 V_90 ,
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
F_112 ( system , V_124 ) ;
V_125 = F_79 ( V_89 , V_90 , V_91 , V_124 -> V_100 , V_124 -> V_122 ) ;
F_43 ( V_124 ) ;
return V_125 ;
}
static T_1
F_113 ( struct V_36 * V_76 , const char T_2 * V_89 , T_3 V_90 ,
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
V_127 = F_114 ( V_72 , V_88 ) ;
F_101 ( ( unsigned long ) V_88 ) ;
if ( V_127 < 0 )
return V_127 ;
* V_91 += V_90 ;
return V_90 ;
}
static T_1
F_115 ( struct V_36 * V_76 , char T_2 * V_89 , T_3 V_90 , T_4 * V_91 )
{
int (* F_116)( struct V_123 * V_124 ) = V_76 -> V_96 ;
struct V_123 * V_124 ;
int V_125 ;
if ( * V_91 )
return 0 ;
V_124 = F_95 ( sizeof( * V_124 ) , V_126 ) ;
if ( ! V_124 )
return - V_22 ;
F_96 ( V_124 ) ;
F_116 ( V_124 ) ;
V_125 = F_79 ( V_89 , V_90 , V_91 , V_124 -> V_100 , V_124 -> V_122 ) ;
F_43 ( V_124 ) ;
return V_125 ;
}
static int
F_117 ( struct V_120 * V_120 , struct V_36 * V_36 ,
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
static int F_118 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
struct V_48 * V_49 = V_120 -> V_77 ;
F_107 ( V_49 ) ;
return F_119 ( V_120 , V_36 ) ;
}
static int
F_120 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
const struct V_133 * V_134 = & V_135 ;
return F_117 ( V_120 , V_36 , V_134 ) ;
}
static int
F_121 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
const struct V_133 * V_134 = & V_136 ;
struct V_48 * V_49 = V_120 -> V_77 ;
int V_25 ;
if ( F_105 ( V_49 ) < 0 )
return - V_32 ;
if ( ( V_36 -> V_137 & V_138 ) &&
( V_36 -> V_139 & V_140 ) )
F_40 ( V_49 ) ;
V_25 = F_117 ( V_120 , V_36 , V_134 ) ;
if ( V_25 < 0 )
F_107 ( V_49 ) ;
return V_25 ;
}
static struct V_1 *
F_122 ( const char * V_12 )
{
struct V_1 * system ;
system = F_95 ( sizeof( * system ) , V_126 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
if ( ! F_123 ( ( unsigned long ) V_12 ) ) {
system -> V_2 |= V_3 ;
system -> V_12 = F_124 ( V_12 , V_126 ) ;
if ( ! system -> V_12 )
goto V_141;
} else
system -> V_12 = V_12 ;
system -> V_68 = NULL ;
system -> V_68 = F_109 ( sizeof( struct V_67 ) , V_126 ) ;
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
F_125 ( struct V_48 * V_49 , const char * V_12 ,
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
system = F_122 ( V_12 ) ;
if ( ! system )
goto V_141;
} else
F_44 ( system ) ;
V_72 -> V_75 = F_126 ( V_12 , V_143 ) ;
if ( ! V_72 -> V_75 ) {
F_127 ( L_17 , V_12 ) ;
F_41 ( system ) ;
goto V_141;
}
V_72 -> V_49 = V_49 ;
V_72 -> V_2 = 1 ;
V_72 -> V_74 = 1 ;
V_72 -> V_73 = system ;
V_36 -> system = V_72 ;
V_75 = F_128 ( L_18 , 0644 , V_72 -> V_75 , V_72 ,
& V_145 ) ;
if ( ! V_75 ) {
F_43 ( system -> V_68 ) ;
system -> V_68 = NULL ;
F_127 ( L_19 , V_12 ) ;
}
F_129 ( L_20 , 0644 , V_72 -> V_75 , V_72 ,
& V_146 ) ;
F_11 ( & V_72 -> V_69 , & V_49 -> V_147 ) ;
return V_72 -> V_75 ;
V_141:
F_43 ( V_72 ) ;
V_144:
if ( ! V_72 || ! system )
F_127 ( L_21 ,
V_12 ) ;
return NULL ;
}
static int
F_130 ( struct V_78 * V_143 , struct V_35 * V_36 )
{
struct V_5 * V_14 = V_36 -> V_6 ;
struct V_48 * V_49 = V_36 -> V_49 ;
struct V_4 * V_11 ;
struct V_78 * V_148 ;
int V_25 ;
if ( strcmp ( V_14 -> V_7 -> system , V_107 ) != 0 ) {
V_148 = F_125 ( V_49 , V_14 -> V_7 -> system , V_36 , V_143 ) ;
if ( ! V_148 )
return - V_22 ;
} else
V_148 = V_143 ;
V_36 -> V_72 = F_126 ( V_14 -> V_12 , V_148 ) ;
if ( ! V_36 -> V_72 ) {
F_127 ( L_22 ,
V_14 -> V_12 ) ;
return - 1 ;
}
if ( V_14 -> V_7 -> V_62 && ! ( V_14 -> V_51 & V_87 ) )
F_129 ( L_20 , 0644 , V_36 -> V_72 , V_36 ,
& V_149 ) ;
#ifdef F_25
if ( V_14 -> V_31 . type && V_14 -> V_7 -> V_62 )
F_129 ( L_23 , 0444 , V_36 -> V_72 ,
( void * ) ( long ) V_14 -> V_31 . type ,
& V_150 ) ;
#endif
V_11 = F_4 ( V_14 ) ;
if ( F_131 ( V_11 ) ) {
V_25 = V_14 -> V_7 -> V_151 ( V_14 ) ;
if ( V_25 < 0 ) {
F_127 ( L_24
L_25 , V_14 -> V_12 ) ;
return - 1 ;
}
}
F_129 ( L_18 , 0644 , V_36 -> V_72 , V_36 ,
& V_152 ) ;
F_129 ( L_26 , 0444 , V_36 -> V_72 , V_14 ,
& V_153 ) ;
return 0 ;
}
static void F_132 ( struct V_5 * V_14 )
{
struct V_35 * V_36 ;
struct V_48 * V_49 ;
F_133 (tr, file) {
if ( V_36 -> V_6 != V_14 )
continue;
F_53 ( V_36 ) ;
break;
} F_33 () ;
}
static void F_134 ( struct V_5 * V_14 )
{
struct V_48 * V_49 ;
struct V_35 * V_36 ;
F_28 (tr, file) {
if ( V_36 -> V_6 != V_14 )
continue;
F_39 ( V_36 , 0 ) ;
F_135 ( V_36 ) ;
break;
} F_33 () ;
if ( V_14 -> V_31 . V_154 )
F_136 ( & V_14 -> V_31 ) ;
F_132 ( V_14 ) ;
F_18 ( & V_14 -> V_69 ) ;
}
static int F_137 ( struct V_5 * V_14 )
{
int V_25 = 0 ;
if ( F_13 ( ! V_14 -> V_12 ) )
return - V_86 ;
if ( V_14 -> V_7 -> V_155 ) {
V_25 = V_14 -> V_7 -> V_155 ( V_14 ) ;
if ( V_25 < 0 && V_25 != - V_156 )
F_138 ( L_27 ,
V_14 -> V_12 ) ;
}
return V_25 ;
}
static int
F_139 ( struct V_5 * V_14 , struct V_157 * V_158 )
{
int V_25 ;
V_25 = F_137 ( V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_14 -> V_69 , & V_159 ) ;
V_14 -> V_158 = V_158 ;
return 0 ;
}
static struct V_35 *
F_140 ( struct V_5 * V_14 ,
struct V_48 * V_49 )
{
struct V_35 * V_36 ;
V_36 = F_9 ( V_82 , V_21 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_6 = V_14 ;
V_36 -> V_49 = V_49 ;
F_141 ( & V_36 -> V_56 , 0 ) ;
F_11 ( & V_36 -> V_69 , & V_49 -> V_106 ) ;
return V_36 ;
}
static int
F_142 ( struct V_5 * V_14 , struct V_48 * V_49 )
{
struct V_35 * V_36 ;
V_36 = F_140 ( V_14 , V_49 ) ;
if ( ! V_36 )
return - V_22 ;
return F_130 ( V_49 -> V_160 , V_36 ) ;
}
static T_5 int
F_143 ( struct V_5 * V_14 ,
struct V_48 * V_49 )
{
struct V_35 * V_36 ;
V_36 = F_140 ( V_14 , V_49 ) ;
if ( ! V_36 )
return - V_22 ;
return 0 ;
}
int F_144 ( struct V_5 * V_14 )
{
int V_25 ;
F_27 ( & V_131 ) ;
F_27 ( & V_50 ) ;
V_25 = F_139 ( V_14 , NULL ) ;
if ( V_25 >= 0 )
F_145 ( V_14 ) ;
F_34 ( & V_50 ) ;
F_34 ( & V_131 ) ;
return V_25 ;
}
static void F_146 ( struct V_5 * V_14 )
{
F_134 ( V_14 ) ;
F_16 ( V_14 ) ;
F_147 ( V_14 ) ;
}
static int F_148 ( struct V_5 * V_14 )
{
struct V_48 * V_49 ;
struct V_35 * V_36 ;
#ifdef F_25
if ( V_14 -> V_161 )
return - V_162 ;
#endif
F_28 (tr, file) {
if ( V_36 -> V_6 != V_14 )
continue;
if ( V_36 -> V_51 & V_52 )
return - V_162 ;
break;
} F_33 () ;
F_146 ( V_14 ) ;
return 0 ;
}
int F_149 ( struct V_5 * V_14 )
{
int V_25 ;
F_27 ( & V_131 ) ;
F_27 ( & V_50 ) ;
F_150 ( & V_163 ) ;
V_25 = F_148 ( V_14 ) ;
F_151 ( & V_163 ) ;
F_34 ( & V_50 ) ;
F_34 ( & V_131 ) ;
return V_25 ;
}
static void F_152 ( struct V_157 * V_158 )
{
struct V_5 * * V_14 , * * V_164 , * * V_165 ;
V_164 = V_158 -> V_166 ;
V_165 = V_158 -> V_166 + V_158 -> V_167 ;
F_153 (call, start, end) {
F_139 ( * V_14 , V_158 ) ;
F_145 ( * V_14 ) ;
}
}
static void F_154 ( struct V_157 * V_158 )
{
struct V_5 * V_14 , * V_108 ;
bool V_168 = false ;
F_150 ( & V_163 ) ;
F_17 (call, p, &ftrace_events, list) {
if ( V_14 -> V_158 == V_158 ) {
if ( V_14 -> V_51 & V_66 )
V_168 = true ;
F_146 ( V_14 ) ;
}
}
F_151 ( & V_163 ) ;
if ( V_168 )
F_155 () ;
}
static int F_156 ( struct V_169 * V_170 ,
unsigned long V_109 , void * V_34 )
{
struct V_157 * V_158 = V_34 ;
F_27 ( & V_131 ) ;
F_27 ( & V_50 ) ;
switch ( V_109 ) {
case V_171 :
F_152 ( V_158 ) ;
break;
case V_172 :
F_154 ( V_158 ) ;
break;
}
F_34 ( & V_50 ) ;
F_34 ( & V_131 ) ;
return 0 ;
}
static void
F_157 ( struct V_48 * V_49 )
{
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
V_25 = F_142 ( V_14 , V_49 ) ;
if ( V_25 < 0 )
F_127 ( L_28 ,
V_14 -> V_12 ) ;
}
}
static struct V_35 *
F_158 ( struct V_48 * V_49 , const char * system , const char * V_31 )
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
F_159 ( unsigned long V_173 , unsigned long V_174 , void * * V_175 )
{
struct V_176 * * V_177 = (struct V_176 * * ) V_175 ;
struct V_176 * V_34 = * V_177 ;
if ( ! V_34 )
return;
if ( V_34 -> V_47 )
F_32 ( V_63 , & V_34 -> V_36 -> V_51 ) ;
else
F_30 ( V_63 , & V_34 -> V_36 -> V_51 ) ;
}
static void
F_160 ( unsigned long V_173 , unsigned long V_174 , void * * V_175 )
{
struct V_176 * * V_177 = (struct V_176 * * ) V_175 ;
struct V_176 * V_34 = * V_177 ;
if ( ! V_34 )
return;
if ( ! V_34 -> V_178 )
return;
if ( V_34 -> V_47 == ! ( V_34 -> V_36 -> V_51 & V_57 ) )
return;
if ( V_34 -> V_178 != - 1 )
( V_34 -> V_178 ) -- ;
F_159 ( V_173 , V_174 , V_175 ) ;
}
static int
F_161 ( struct V_94 * V_95 , unsigned long V_173 ,
struct V_179 * V_180 , void * V_175 )
{
struct V_176 * V_34 = V_175 ;
F_75 ( V_95 , L_29 , ( void * ) V_173 ) ;
F_75 ( V_95 , L_30 ,
V_34 -> V_47 ? V_181 : V_182 ,
V_34 -> V_36 -> V_6 -> V_7 -> system ,
V_34 -> V_36 -> V_6 -> V_12 ) ;
if ( V_34 -> V_178 == - 1 )
F_75 ( V_95 , L_31 ) ;
else
F_75 ( V_95 , L_32 , V_34 -> V_178 ) ;
return 0 ;
}
static int
F_162 ( struct V_179 * V_180 , unsigned long V_173 ,
void * * V_175 )
{
struct V_176 * * V_177 = (struct V_176 * * ) V_175 ;
struct V_176 * V_34 = * V_177 ;
V_34 -> V_183 ++ ;
return 0 ;
}
static void
F_163 ( struct V_179 * V_180 , unsigned long V_173 ,
void * * V_175 )
{
struct V_176 * * V_177 = (struct V_176 * * ) V_175 ;
struct V_176 * V_34 = * V_177 ;
if ( F_42 ( V_34 -> V_183 <= 0 ) )
return;
V_34 -> V_183 -- ;
if ( ! V_34 -> V_183 ) {
F_35 ( V_34 -> V_36 , 0 , 1 ) ;
F_164 ( V_34 -> V_36 -> V_6 -> V_158 ) ;
F_43 ( V_34 ) ;
}
* V_177 = NULL ;
}
static int
F_165 ( struct V_184 * V_185 ,
char * V_186 , char * V_187 , char * V_188 , int V_189 )
{
struct V_48 * V_49 = F_61 () ;
struct V_35 * V_36 ;
struct V_179 * V_180 ;
struct V_176 * V_34 ;
const char * system ;
const char * V_31 ;
char * V_190 ;
bool V_47 ;
int V_25 ;
if ( ! V_189 || ! V_188 )
return - V_86 ;
system = F_59 ( & V_188 , L_3 ) ;
if ( ! V_188 )
return - V_86 ;
V_31 = F_59 ( & V_188 , L_3 ) ;
F_27 ( & V_50 ) ;
V_25 = - V_86 ;
V_36 = F_158 ( V_49 , system , V_31 ) ;
if ( ! V_36 )
goto V_111;
V_47 = strcmp ( V_187 , V_181 ) == 0 ;
if ( V_47 )
V_180 = V_188 ? & V_191 : & V_192 ;
else
V_180 = V_188 ? & V_193 : & V_194 ;
if ( V_186 [ 0 ] == '!' ) {
F_166 ( V_186 + 1 , V_180 ) ;
V_25 = 0 ;
goto V_111;
}
V_25 = - V_22 ;
V_34 = F_109 ( sizeof( * V_34 ) , V_126 ) ;
if ( ! V_34 )
goto V_111;
V_34 -> V_47 = V_47 ;
V_34 -> V_178 = - 1 ;
V_34 -> V_36 = V_36 ;
if ( ! V_188 )
goto V_195;
V_190 = F_59 ( & V_188 , L_3 ) ;
V_25 = - V_86 ;
if ( ! strlen ( V_190 ) )
goto V_141;
V_25 = F_167 ( V_190 , 0 , & V_34 -> V_178 ) ;
if ( V_25 )
goto V_141;
V_195:
V_25 = F_168 ( V_36 -> V_6 -> V_158 ) ;
if ( ! V_25 ) {
V_25 = - V_162 ;
goto V_141;
}
V_25 = F_35 ( V_36 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_102;
V_25 = F_169 ( V_186 , V_180 , V_34 ) ;
if ( ! V_25 ) {
V_25 = - V_196 ;
goto V_197;
} else if ( V_25 < 0 )
goto V_197;
V_25 = 0 ;
V_111:
F_34 ( & V_50 ) ;
return V_25 ;
V_197:
F_35 ( V_36 , 0 , 1 ) ;
V_102:
F_164 ( V_36 -> V_6 -> V_158 ) ;
V_141:
F_43 ( V_34 ) ;
goto V_111;
}
static T_5 int F_170 ( void )
{
int V_25 ;
V_25 = F_171 ( & V_198 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_171 ( & V_199 ) ;
if ( F_13 ( V_25 < 0 ) )
F_172 ( & V_198 ) ;
return V_25 ;
}
static inline int F_170 ( void ) { return 0 ; }
static T_5 void
F_173 ( struct V_48 * V_49 )
{
struct V_35 * V_36 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_130 ( V_49 -> V_160 , V_36 ) ;
if ( V_25 < 0 )
F_127 ( L_28 ,
V_36 -> V_6 -> V_12 ) ;
}
}
static T_5 void
F_174 ( struct V_48 * V_49 )
{
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_42 ( V_14 -> V_158 ) )
continue;
V_25 = F_143 ( V_14 , V_49 ) ;
if ( V_25 < 0 )
F_127 ( L_33 ,
V_14 -> V_12 ) ;
}
}
static void
F_175 ( struct V_48 * V_49 )
{
struct V_35 * V_36 , * V_29 ;
F_17 (file, next, &tr->events, list)
F_53 ( V_36 ) ;
}
static void F_145 ( struct V_5 * V_14 )
{
struct V_48 * V_49 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_142 ( V_14 , V_49 ) ;
}
static T_5 int F_176 ( char * V_200 )
{
F_177 ( V_201 , V_200 , V_202 ) ;
V_203 = true ;
V_204 = true ;
return 1 ;
}
static int
F_178 ( struct V_78 * V_143 , struct V_48 * V_49 )
{
struct V_78 * V_148 ;
struct V_78 * V_75 ;
V_75 = F_128 ( L_34 , 0644 , V_143 ,
V_49 , & V_205 ) ;
if ( ! V_75 ) {
F_127 ( L_35 ) ;
return - V_22 ;
}
V_148 = F_126 ( L_36 , V_143 ) ;
if ( ! V_148 ) {
F_127 ( L_37 ) ;
return - V_22 ;
}
F_129 ( L_38 , 0444 , V_148 ,
V_206 ,
& V_207 ) ;
F_129 ( L_39 , 0444 , V_148 ,
V_208 ,
& V_207 ) ;
F_129 ( L_20 , 0644 , V_148 ,
V_49 , & V_209 ) ;
V_49 -> V_160 = V_148 ;
return 0 ;
}
int F_179 ( struct V_78 * V_143 , struct V_48 * V_49 )
{
int V_25 ;
F_27 ( & V_50 ) ;
V_25 = F_178 ( V_143 , V_49 ) ;
if ( V_25 )
goto V_210;
F_150 ( & V_163 ) ;
F_157 ( V_49 ) ;
F_151 ( & V_163 ) ;
V_210:
F_34 ( & V_50 ) ;
return V_25 ;
}
static T_5 int
F_180 ( struct V_78 * V_143 , struct V_48 * V_49 )
{
int V_25 ;
F_27 ( & V_50 ) ;
V_25 = F_178 ( V_143 , V_49 ) ;
if ( V_25 )
goto V_210;
F_150 ( & V_163 ) ;
F_173 ( V_49 ) ;
F_151 ( & V_163 ) ;
V_210:
F_34 ( & V_50 ) ;
return V_25 ;
}
int F_181 ( struct V_48 * V_49 )
{
F_27 ( & V_50 ) ;
F_56 ( V_49 , NULL , NULL , NULL , 0 ) ;
F_182 () ;
F_150 ( & V_163 ) ;
F_175 ( V_49 ) ;
F_49 ( V_49 -> V_160 ) ;
F_151 ( & V_163 ) ;
V_49 -> V_160 = NULL ;
F_34 ( & V_50 ) ;
return 0 ;
}
static T_5 int F_183 ( void )
{
V_20 = F_184 ( V_10 , V_211 ) ;
V_82 = F_184 ( V_35 , V_211 ) ;
return 0 ;
}
static T_5 int F_185 ( void )
{
struct V_48 * V_49 = F_61 () ;
struct V_5 * * V_212 , * V_14 ;
char * V_88 = V_201 ;
char * V_213 ;
int V_25 ;
F_153 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_14 = * V_212 ;
V_25 = F_137 ( V_14 ) ;
if ( ! V_25 )
F_11 ( & V_14 -> V_69 , & V_159 ) ;
}
F_174 ( V_49 ) ;
while ( true ) {
V_213 = F_59 ( & V_88 , L_40 ) ;
if ( ! V_213 )
break;
if ( ! * V_213 )
continue;
V_25 = F_58 ( V_49 , V_213 , 1 ) ;
if ( V_25 )
F_138 ( L_41 , V_213 ) ;
}
F_186 () ;
F_170 () ;
return 0 ;
}
static T_5 int F_187 ( void )
{
struct V_48 * V_49 ;
struct V_78 * V_214 ;
struct V_78 * V_75 ;
int V_25 ;
V_49 = F_61 () ;
V_214 = F_188 () ;
if ( ! V_214 )
return 0 ;
V_75 = F_128 ( L_42 , 0444 , V_214 ,
V_49 , & V_215 ) ;
if ( ! V_75 )
F_127 ( L_43
L_44 ) ;
if ( F_14 () )
F_127 ( L_45 ) ;
V_25 = F_180 ( V_214 , V_49 ) ;
if ( V_25 )
return V_25 ;
#ifdef F_189
V_25 = F_190 ( & V_216 ) ;
if ( V_25 )
F_127 ( L_46 ) ;
#endif
return 0 ;
}
static T_5 void F_191 ( struct V_217 * V_218 )
{
F_54 ( & V_219 ) ;
F_192 ( & V_220 ) ;
F_193 ( 1 ) ;
F_194 ( & V_220 ) ;
F_55 ( & V_219 ) ;
F_27 ( & V_221 ) ;
F_195 ( 1 ) ;
F_34 ( & V_221 ) ;
}
static T_5 int F_196 ( void * V_222 )
{
void * V_223 ;
V_223 = F_95 ( 1234 , V_126 ) ;
if ( ! V_223 )
F_38 ( L_47 ) ;
F_197 ( F_191 ) ;
F_43 ( V_223 ) ;
F_198 ( V_224 ) ;
while ( ! F_199 () )
F_200 () ;
return 0 ;
}
static T_5 void F_201 ( void )
{
struct V_225 * V_226 ;
V_226 = F_202 ( F_196 , NULL , L_48 ) ;
F_195 ( 1 ) ;
F_203 ( V_226 ) ;
}
static T_5 void F_204 ( void )
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
#ifndef F_205
if ( V_14 -> V_7 -> system &&
strcmp ( V_14 -> V_7 -> system , L_50 ) == 0 )
continue;
#endif
F_38 ( L_51 , V_14 -> V_12 ) ;
if ( V_36 -> V_51 & V_52 ) {
F_127 ( L_52 ) ;
F_42 ( 1 ) ;
continue;
}
F_39 ( V_36 , 1 ) ;
F_201 () ;
F_39 ( V_36 , 0 ) ;
F_206 ( L_53 ) ;
}
F_38 ( L_54 ) ;
F_6 (dir, &tr->systems, list) {
system = V_72 -> V_73 ;
if ( strcmp ( system -> V_12 , L_55 ) == 0 )
continue;
F_38 ( L_56 , system -> V_12 ) ;
V_25 = F_57 ( V_49 , NULL , system -> V_12 , NULL , 1 ) ;
if ( F_42 ( V_25 ) ) {
F_127 ( L_57 ,
system -> V_12 ) ;
continue;
}
F_201 () ;
V_25 = F_57 ( V_49 , NULL , system -> V_12 , NULL , 0 ) ;
if ( F_42 ( V_25 ) ) {
F_127 ( L_58 ,
system -> V_12 ) ;
continue;
}
F_206 ( L_53 ) ;
}
F_38 ( L_59 ) ;
F_38 ( L_60 ) ;
V_25 = F_57 ( V_49 , NULL , NULL , NULL , 1 ) ;
if ( F_42 ( V_25 ) ) {
F_127 ( L_61 ) ;
return;
}
F_201 () ;
V_25 = F_57 ( V_49 , NULL , NULL , NULL , 0 ) ;
if ( F_42 ( V_25 ) ) {
F_127 ( L_62 ) ;
return;
}
F_206 ( L_53 ) ;
}
static void
F_207 ( unsigned long V_173 , unsigned long V_174 ,
struct V_227 * V_228 , struct V_229 * V_229 )
{
struct V_230 * V_31 ;
struct V_231 * V_100 ;
struct V_232 * V_75 ;
unsigned long V_51 ;
long V_233 ;
int V_234 ;
int V_235 ;
V_235 = F_208 () ;
F_209 () ;
V_234 = F_210 () ;
V_233 = F_37 ( & F_211 ( V_236 , V_234 ) ) ;
if ( V_233 != 1 )
goto V_111;
F_212 ( V_51 ) ;
V_31 = F_213 ( & V_100 ,
V_237 , sizeof( * V_75 ) ,
V_51 , V_235 ) ;
if ( ! V_31 )
goto V_111;
V_75 = F_214 ( V_31 ) ;
V_75 -> V_173 = V_173 ;
V_75 -> V_174 = V_174 ;
F_215 ( V_100 , V_31 , V_51 , V_235 ) ;
V_111:
F_216 ( & F_211 ( V_236 , V_234 ) ) ;
F_217 () ;
}
static T_5 void F_218 ( void )
{
int V_25 ;
V_25 = F_219 ( & V_238 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_38 ( L_63 ) ;
return;
}
F_38 ( L_64 ) ;
F_204 () ;
F_220 ( & V_238 ) ;
}
static T_5 void F_218 ( void )
{
}
static T_5 int F_221 ( void )
{
if ( ! V_204 ) {
F_204 () ;
F_218 () ;
}
return 0 ;
}
