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
int F_39 ( struct V_35 * V_36 ,
int V_47 , int V_54 )
{
return F_35 ( V_36 , V_47 , V_54 ) ;
}
static int F_40 ( struct V_35 * V_36 ,
int V_47 )
{
return F_35 ( V_36 , V_47 , 0 ) ;
}
static void F_41 ( struct V_48 * V_49 )
{
struct V_35 * V_36 ;
F_27 ( & V_50 ) ;
F_6 (file, &tr->events, list) {
F_40 ( V_36 , 0 ) ;
}
F_34 ( & V_50 ) ;
}
static void F_42 ( struct V_1 * system )
{
struct V_67 * V_68 = system -> V_68 ;
F_43 ( F_1 ( system ) == 0 ) ;
if ( F_3 ( system ) )
return;
F_18 ( & system -> V_69 ) ;
if ( V_68 ) {
F_44 ( V_68 -> V_70 ) ;
F_44 ( V_68 ) ;
}
if ( system -> V_2 & V_3 )
F_44 ( system -> V_12 ) ;
F_44 ( system ) ;
}
static void F_45 ( struct V_1 * system )
{
F_43 ( F_1 ( system ) == 0 ) ;
F_2 ( system ) ;
}
static void F_46 ( struct V_71 * V_72 )
{
F_43 ( V_72 -> V_2 == 0 ) ;
V_72 -> V_2 ++ ;
F_45 ( V_72 -> V_73 ) ;
}
static void F_47 ( struct V_71 * V_72 )
{
F_43 ( V_72 -> V_2 == 0 ) ;
F_43 ( F_1 ( V_72 -> V_73 ) == 1 && V_72 -> V_2 != 1 ) ;
F_42 ( V_72 -> V_73 ) ;
if ( ! -- V_72 -> V_2 )
F_44 ( V_72 ) ;
}
static void F_48 ( struct V_71 * V_72 )
{
F_27 ( & V_50 ) ;
F_47 ( V_72 ) ;
F_34 ( & V_50 ) ;
}
static void F_49 ( struct V_71 * V_72 )
{
if ( ! V_72 )
return;
if ( ! -- V_72 -> V_74 ) {
F_50 ( V_72 -> V_75 ) ;
F_18 ( & V_72 -> V_69 ) ;
F_47 ( V_72 ) ;
}
}
static void F_51 ( struct V_35 * V_36 )
{
struct V_76 * V_72 = V_36 -> V_72 ;
struct V_76 * V_77 ;
if ( V_72 ) {
F_52 ( & V_72 -> V_78 ) ;
F_6 (child, &dir->d_subdirs, d_u.d_child) {
if ( V_77 -> V_79 )
V_77 -> V_79 -> V_80 = NULL ;
}
F_53 ( & V_72 -> V_78 ) ;
F_50 ( V_72 ) ;
}
F_18 ( & V_36 -> V_69 ) ;
F_49 ( V_36 -> system ) ;
F_19 ( V_81 , V_36 ) ;
}
static int
F_54 ( struct V_48 * V_49 , const char * V_82 ,
const char * V_83 , const char * V_31 , int V_84 )
{
struct V_35 * V_36 ;
struct V_5 * V_14 ;
int V_25 = - V_85 ;
F_6 (file, &tr->events, list) {
V_14 = V_36 -> V_6 ;
if ( ! V_14 -> V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_62 )
continue;
if ( V_14 -> V_51 & V_86 )
continue;
if ( V_82 &&
strcmp ( V_82 , V_14 -> V_12 ) != 0 &&
strcmp ( V_82 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_83 && strcmp ( V_83 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_31 && strcmp ( V_31 , V_14 -> V_12 ) != 0 )
continue;
F_40 ( V_36 , V_84 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static int F_55 ( struct V_48 * V_49 , const char * V_82 ,
const char * V_83 , const char * V_31 , int V_84 )
{
int V_25 ;
F_27 ( & V_50 ) ;
V_25 = F_54 ( V_49 , V_82 , V_83 , V_31 , V_84 ) ;
F_34 ( & V_50 ) ;
return V_25 ;
}
static int F_56 ( struct V_48 * V_49 , char * V_87 , int V_84 )
{
char * V_31 = NULL , * V_83 = NULL , * V_82 ;
V_82 = F_57 ( & V_87 , L_3 ) ;
if ( V_87 ) {
V_83 = V_82 ;
V_31 = V_87 ;
V_82 = NULL ;
if ( ! strlen ( V_83 ) || strcmp ( V_83 , L_4 ) == 0 )
V_83 = NULL ;
if ( ! strlen ( V_31 ) || strcmp ( V_31 , L_4 ) == 0 )
V_31 = NULL ;
}
return F_55 ( V_49 , V_82 , V_83 , V_31 , V_84 ) ;
}
int F_58 ( const char * system , const char * V_31 , int V_84 )
{
struct V_48 * V_49 = F_59 () ;
return F_55 ( V_49 , NULL , system , V_31 , V_84 ) ;
}
static T_1
F_60 ( struct V_36 * V_36 , const char T_2 * V_88 ,
T_3 V_89 , T_4 * V_90 )
{
struct V_91 V_92 ;
struct V_93 * V_94 = V_36 -> V_95 ;
struct V_48 * V_49 = V_94 -> V_96 ;
T_1 V_97 , V_25 ;
if ( ! V_89 )
return 0 ;
V_25 = F_61 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_62 ( & V_92 , V_98 + 1 ) )
return - V_22 ;
V_97 = F_63 ( & V_92 , V_88 , V_89 , V_90 ) ;
if ( V_97 >= 0 && F_64 ( ( & V_92 ) ) ) {
int V_84 = 1 ;
if ( * V_92 . V_99 == '!' )
V_84 = 0 ;
V_92 . V_99 [ V_92 . V_100 ] = 0 ;
V_25 = F_56 ( V_49 , V_92 . V_99 + ! V_84 , V_84 ) ;
if ( V_25 )
goto V_101;
}
V_25 = V_97 ;
V_101:
F_65 ( & V_92 ) ;
return V_25 ;
}
static void *
F_66 ( struct V_93 * V_94 , void * V_102 , T_4 * V_103 )
{
struct V_35 * V_36 = V_102 ;
struct V_5 * V_14 ;
struct V_48 * V_49 = V_94 -> V_96 ;
( * V_103 ) ++ ;
F_67 (file, &tr->events, list) {
V_14 = V_36 -> V_6 ;
if ( V_14 -> V_7 && V_14 -> V_7 -> V_62 )
return V_36 ;
}
return NULL ;
}
static void * F_68 ( struct V_93 * V_94 , T_4 * V_103 )
{
struct V_35 * V_36 ;
struct V_48 * V_49 = V_94 -> V_96 ;
T_4 V_104 ;
F_27 ( & V_50 ) ;
V_36 = F_69 ( & V_49 -> V_105 , struct V_35 , V_69 ) ;
for ( V_104 = 0 ; V_104 <= * V_103 ; ) {
V_36 = F_66 ( V_94 , V_36 , & V_104 ) ;
if ( ! V_36 )
break;
}
return V_36 ;
}
static void *
F_70 ( struct V_93 * V_94 , void * V_102 , T_4 * V_103 )
{
struct V_35 * V_36 = V_102 ;
struct V_48 * V_49 = V_94 -> V_96 ;
( * V_103 ) ++ ;
F_67 (file, &tr->events, list) {
if ( V_36 -> V_51 & V_52 )
return V_36 ;
}
return NULL ;
}
static void * F_71 ( struct V_93 * V_94 , T_4 * V_103 )
{
struct V_35 * V_36 ;
struct V_48 * V_49 = V_94 -> V_96 ;
T_4 V_104 ;
F_27 ( & V_50 ) ;
V_36 = F_69 ( & V_49 -> V_105 , struct V_35 , V_69 ) ;
for ( V_104 = 0 ; V_104 <= * V_103 ; ) {
V_36 = F_70 ( V_94 , V_36 , & V_104 ) ;
if ( ! V_36 )
break;
}
return V_36 ;
}
static int F_72 ( struct V_93 * V_94 , void * V_102 )
{
struct V_35 * V_36 = V_102 ;
struct V_5 * V_14 = V_36 -> V_6 ;
if ( strcmp ( V_14 -> V_7 -> system , V_106 ) != 0 )
F_73 ( V_94 , L_5 , V_14 -> V_7 -> system ) ;
F_73 ( V_94 , L_2 , V_14 -> V_12 ) ;
return 0 ;
}
static void F_74 ( struct V_93 * V_94 , void * V_107 )
{
F_34 ( & V_50 ) ;
}
static T_1
F_75 ( struct V_36 * V_108 , char T_2 * V_88 , T_3 V_89 ,
T_4 * V_90 )
{
struct V_35 * V_36 ;
unsigned long V_51 ;
char V_87 [ 4 ] = L_6 ;
F_27 ( & V_50 ) ;
V_36 = F_76 ( V_108 ) ;
if ( F_77 ( V_36 ) )
V_51 = V_36 -> V_51 ;
F_34 ( & V_50 ) ;
if ( ! V_36 )
return - V_32 ;
if ( V_51 & V_52 &&
! ( V_51 & V_57 ) )
strcpy ( V_87 , L_7 ) ;
if ( V_51 & V_57 ||
V_51 & V_59 )
strcat ( V_87 , L_4 ) ;
strcat ( V_87 , L_8 ) ;
return F_78 ( V_88 , V_89 , V_90 , V_87 , strlen ( V_87 ) ) ;
}
static T_1
F_79 ( struct V_36 * V_108 , const char T_2 * V_88 , T_3 V_89 ,
T_4 * V_90 )
{
struct V_35 * V_36 ;
unsigned long V_109 ;
int V_25 ;
V_25 = F_80 ( V_88 , V_89 , 10 , & V_109 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_61 () ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_109 ) {
case 0 :
case 1 :
V_25 = - V_32 ;
F_27 ( & V_50 ) ;
V_36 = F_76 ( V_108 ) ;
if ( F_77 ( V_36 ) )
V_25 = F_40 ( V_36 , V_109 ) ;
F_34 ( & V_50 ) ;
break;
default:
return - V_85 ;
}
* V_90 += V_89 ;
return V_25 ? V_25 : V_89 ;
}
static T_1
F_81 ( struct V_36 * V_108 , char T_2 * V_88 , T_3 V_89 ,
T_4 * V_90 )
{
const char V_110 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_71 * V_72 = V_108 -> V_95 ;
struct V_1 * system = V_72 -> V_73 ;
struct V_5 * V_14 ;
struct V_35 * V_36 ;
struct V_48 * V_49 = V_72 -> V_49 ;
char V_87 [ 2 ] ;
int V_84 = 0 ;
int V_25 ;
F_27 ( & V_50 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_36 -> V_6 ;
if ( ! V_14 -> V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_62 )
continue;
if ( system && strcmp ( V_14 -> V_7 -> system , system -> V_12 ) != 0 )
continue;
V_84 |= ( 1 << ! ! ( V_36 -> V_51 & V_52 ) ) ;
if ( V_84 == 3 )
break;
}
F_34 ( & V_50 ) ;
V_87 [ 0 ] = V_110 [ V_84 ] ;
V_87 [ 1 ] = '\n' ;
V_25 = F_78 ( V_88 , V_89 , V_90 , V_87 , 2 ) ;
return V_25 ;
}
static T_1
F_82 ( struct V_36 * V_108 , const char T_2 * V_88 , T_3 V_89 ,
T_4 * V_90 )
{
struct V_71 * V_72 = V_108 -> V_95 ;
struct V_1 * system = V_72 -> V_73 ;
const char * V_12 = NULL ;
unsigned long V_109 ;
T_1 V_25 ;
V_25 = F_80 ( V_88 , V_89 , 10 , & V_109 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_61 () ;
if ( V_25 < 0 )
return V_25 ;
if ( V_109 != 0 && V_109 != 1 )
return - V_85 ;
if ( system )
V_12 = system -> V_12 ;
V_25 = F_55 ( V_72 -> V_49 , NULL , V_12 , NULL , V_109 ) ;
if ( V_25 )
goto V_111;
V_25 = V_89 ;
V_111:
* V_90 += V_89 ;
return V_25 ;
}
static void * F_83 ( struct V_93 * V_94 , void * V_102 , T_4 * V_103 )
{
struct V_5 * V_14 = F_76 ( V_94 -> V_96 ) ;
struct V_4 * V_112 = & V_15 ;
struct V_4 * V_11 = F_4 ( V_14 ) ;
struct V_4 * V_113 = V_102 ;
( * V_103 ) ++ ;
switch ( ( unsigned long ) V_102 ) {
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
static int F_84 ( struct V_93 * V_94 , void * V_102 )
{
struct V_5 * V_14 = F_76 ( V_94 -> V_96 ) ;
struct V_10 * V_13 ;
const char * V_118 ;
switch ( ( unsigned long ) V_102 ) {
case V_114 :
F_73 ( V_94 , L_9 , V_14 -> V_12 ) ;
F_73 ( V_94 , L_10 , V_14 -> V_31 . type ) ;
F_73 ( V_94 , L_11 ) ;
return 0 ;
case V_115 :
F_85 ( V_94 , '\n' ) ;
return 0 ;
case V_116 :
F_73 ( V_94 , L_12 ,
V_14 -> V_119 ) ;
return 0 ;
}
V_13 = F_69 ( V_102 , struct V_10 , V_24 ) ;
V_118 = strchr ( V_13 -> type , '[' ) ;
if ( ! strncmp ( V_13 -> type , L_13 , 10 ) )
V_118 = NULL ;
if ( ! V_118 )
F_73 ( V_94 , L_14 ,
V_13 -> type , V_13 -> V_12 , V_13 -> V_16 ,
V_13 -> V_17 , ! ! V_13 -> V_18 ) ;
else
F_73 ( V_94 , L_15 ,
( int ) ( V_118 - V_13 -> type ) ,
V_13 -> type , V_13 -> V_12 ,
V_118 , V_13 -> V_16 ,
V_13 -> V_17 , ! ! V_13 -> V_18 ) ;
return 0 ;
}
static void * F_86 ( struct V_93 * V_94 , T_4 * V_103 )
{
void * V_107 = ( void * ) V_114 ;
T_4 V_104 = 0 ;
F_27 ( & V_50 ) ;
if ( ! F_76 ( V_94 -> V_96 ) )
return F_87 ( - V_32 ) ;
while ( V_104 < * V_103 && V_107 )
V_107 = F_83 ( V_94 , V_107 , & V_104 ) ;
return V_107 ;
}
static void F_88 ( struct V_93 * V_94 , void * V_107 )
{
F_34 ( & V_50 ) ;
}
static int F_89 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
struct V_93 * V_94 ;
int V_25 ;
V_25 = F_90 ( V_36 , & V_121 ) ;
if ( V_25 < 0 )
return V_25 ;
V_94 = V_36 -> V_95 ;
V_94 -> V_96 = V_36 ;
return 0 ;
}
static T_1
F_91 ( struct V_36 * V_108 , char T_2 * V_88 , T_3 V_89 , T_4 * V_90 )
{
int V_30 = ( long ) F_76 ( V_108 ) ;
char V_87 [ 32 ] ;
int V_122 ;
if ( * V_90 )
return 0 ;
if ( F_92 ( ! V_30 ) )
return - V_32 ;
V_122 = sprintf ( V_87 , L_16 , V_30 ) ;
return F_78 ( V_88 , V_89 , V_90 , V_87 , V_122 ) ;
}
static T_1
F_93 ( struct V_36 * V_108 , char T_2 * V_88 , T_3 V_89 ,
T_4 * V_90 )
{
struct V_35 * V_36 ;
struct V_123 * V_124 ;
int V_125 = - V_32 ;
if ( * V_90 )
return 0 ;
V_124 = F_94 ( sizeof( * V_124 ) , V_126 ) ;
if ( ! V_124 )
return - V_22 ;
F_95 ( V_124 ) ;
F_27 ( & V_50 ) ;
V_36 = F_76 ( V_108 ) ;
if ( V_36 )
F_96 ( V_36 , V_124 ) ;
F_34 ( & V_50 ) ;
if ( V_36 )
V_125 = F_78 ( V_88 , V_89 , V_90 , V_124 -> V_99 , V_124 -> V_122 ) ;
F_44 ( V_124 ) ;
return V_125 ;
}
static T_1
F_97 ( struct V_36 * V_108 , const char T_2 * V_88 , T_3 V_89 ,
T_4 * V_90 )
{
struct V_35 * V_36 ;
char * V_87 ;
int V_127 = - V_32 ;
if ( V_89 >= V_128 )
return - V_85 ;
V_87 = ( char * ) F_98 ( V_129 ) ;
if ( ! V_87 )
return - V_22 ;
if ( F_99 ( V_87 , V_88 , V_89 ) ) {
F_100 ( ( unsigned long ) V_87 ) ;
return - V_130 ;
}
V_87 [ V_89 ] = '\0' ;
F_27 ( & V_50 ) ;
V_36 = F_76 ( V_108 ) ;
if ( V_36 )
V_127 = F_101 ( V_36 , V_87 ) ;
F_34 ( & V_50 ) ;
F_100 ( ( unsigned long ) V_87 ) ;
if ( V_127 < 0 )
return V_127 ;
* V_90 += V_89 ;
return V_89 ;
}
static int F_102 ( struct V_120 * V_120 , struct V_36 * V_108 )
{
struct V_1 * system = NULL ;
struct V_71 * V_72 = NULL ;
struct V_48 * V_49 ;
int V_25 ;
if ( F_103 () )
return - V_32 ;
F_27 ( & V_131 ) ;
F_27 ( & V_50 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_72 == V_120 -> V_80 ) {
if ( V_72 -> V_74 ) {
F_46 ( V_72 ) ;
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
F_48 ( V_72 ) ;
return - V_32 ;
}
V_25 = F_105 ( V_120 , V_108 ) ;
if ( V_25 < 0 ) {
F_106 ( V_49 ) ;
F_48 ( V_72 ) ;
}
return V_25 ;
}
static int F_107 ( struct V_120 * V_120 , struct V_36 * V_108 )
{
struct V_71 * V_72 ;
struct V_48 * V_49 = V_120 -> V_80 ;
int V_25 ;
if ( F_103 () )
return - V_32 ;
if ( F_104 ( V_49 ) < 0 )
return - V_32 ;
V_72 = F_108 ( sizeof( * V_72 ) , V_126 ) ;
if ( ! V_72 ) {
F_106 ( V_49 ) ;
return - V_22 ;
}
V_72 -> V_49 = V_49 ;
V_25 = F_105 ( V_120 , V_108 ) ;
if ( V_25 < 0 ) {
F_106 ( V_49 ) ;
F_44 ( V_72 ) ;
return V_25 ;
}
V_108 -> V_95 = V_72 ;
return 0 ;
}
static int F_109 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
struct V_71 * V_72 = V_36 -> V_95 ;
F_106 ( V_72 -> V_49 ) ;
if ( V_72 -> V_73 )
F_48 ( V_72 ) ;
else
F_44 ( V_72 ) ;
return 0 ;
}
static T_1
F_110 ( struct V_36 * V_108 , char T_2 * V_88 , T_3 V_89 ,
T_4 * V_90 )
{
struct V_71 * V_72 = V_108 -> V_95 ;
struct V_1 * system = V_72 -> V_73 ;
struct V_123 * V_124 ;
int V_125 ;
if ( * V_90 )
return 0 ;
V_124 = F_94 ( sizeof( * V_124 ) , V_126 ) ;
if ( ! V_124 )
return - V_22 ;
F_95 ( V_124 ) ;
F_111 ( system , V_124 ) ;
V_125 = F_78 ( V_88 , V_89 , V_90 , V_124 -> V_99 , V_124 -> V_122 ) ;
F_44 ( V_124 ) ;
return V_125 ;
}
static T_1
F_112 ( struct V_36 * V_108 , const char T_2 * V_88 , T_3 V_89 ,
T_4 * V_90 )
{
struct V_71 * V_72 = V_108 -> V_95 ;
char * V_87 ;
int V_127 ;
if ( V_89 >= V_128 )
return - V_85 ;
V_87 = ( char * ) F_98 ( V_129 ) ;
if ( ! V_87 )
return - V_22 ;
if ( F_99 ( V_87 , V_88 , V_89 ) ) {
F_100 ( ( unsigned long ) V_87 ) ;
return - V_130 ;
}
V_87 [ V_89 ] = '\0' ;
V_127 = F_113 ( V_72 , V_87 ) ;
F_100 ( ( unsigned long ) V_87 ) ;
if ( V_127 < 0 )
return V_127 ;
* V_90 += V_89 ;
return V_89 ;
}
static T_1
F_114 ( struct V_36 * V_108 , char T_2 * V_88 , T_3 V_89 , T_4 * V_90 )
{
int (* F_115)( struct V_123 * V_124 ) = V_108 -> V_95 ;
struct V_123 * V_124 ;
int V_125 ;
if ( * V_90 )
return 0 ;
V_124 = F_94 ( sizeof( * V_124 ) , V_126 ) ;
if ( ! V_124 )
return - V_22 ;
F_95 ( V_124 ) ;
F_115 ( V_124 ) ;
V_125 = F_78 ( V_88 , V_89 , V_90 , V_124 -> V_99 , V_124 -> V_122 ) ;
F_44 ( V_124 ) ;
return V_125 ;
}
static int
F_116 ( struct V_120 * V_120 , struct V_36 * V_36 ,
const struct V_133 * V_134 )
{
struct V_93 * V_94 ;
int V_25 ;
V_25 = F_90 ( V_36 , V_134 ) ;
if ( V_25 < 0 )
return V_25 ;
V_94 = V_36 -> V_95 ;
V_94 -> V_96 = V_120 -> V_80 ;
return V_25 ;
}
static int F_117 ( struct V_120 * V_120 , struct V_36 * V_36 )
{
struct V_48 * V_49 = V_120 -> V_80 ;
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
struct V_48 * V_49 = V_120 -> V_80 ;
int V_25 ;
if ( F_104 ( V_49 ) < 0 )
return - V_32 ;
if ( ( V_36 -> V_137 & V_138 ) &&
( V_36 -> V_139 & V_140 ) )
F_41 ( V_49 ) ;
V_25 = F_116 ( V_120 , V_36 , V_134 ) ;
if ( V_25 < 0 )
F_106 ( V_49 ) ;
return V_25 ;
}
static struct V_1 *
F_121 ( const char * V_12 )
{
struct V_1 * system ;
system = F_94 ( sizeof( * system ) , V_126 ) ;
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
F_44 ( system -> V_12 ) ;
F_44 ( system ) ;
return NULL ;
}
static struct V_76 *
F_124 ( struct V_48 * V_49 , const char * V_12 ,
struct V_35 * V_36 , struct V_76 * V_143 )
{
struct V_71 * V_72 ;
struct V_1 * system ;
struct V_76 * V_75 ;
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
V_72 = F_94 ( sizeof( * V_72 ) , V_126 ) ;
if ( ! V_72 )
goto V_144;
if ( ! system ) {
system = F_121 ( V_12 ) ;
if ( ! system )
goto V_141;
} else
F_45 ( system ) ;
V_72 -> V_75 = F_125 ( V_12 , V_143 ) ;
if ( ! V_72 -> V_75 ) {
F_126 ( L_17 , V_12 ) ;
F_42 ( system ) ;
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
F_44 ( system -> V_68 ) ;
system -> V_68 = NULL ;
F_126 ( L_19 , V_12 ) ;
}
F_128 ( L_20 , 0644 , V_72 -> V_75 , V_72 ,
& V_146 ) ;
F_11 ( & V_72 -> V_69 , & V_49 -> V_147 ) ;
return V_72 -> V_75 ;
V_141:
F_44 ( V_72 ) ;
V_144:
if ( ! V_72 || ! system )
F_126 ( L_21 ,
V_12 ) ;
return NULL ;
}
static int
F_129 ( struct V_76 * V_143 , struct V_35 * V_36 )
{
struct V_5 * V_14 = V_36 -> V_6 ;
struct V_48 * V_49 = V_36 -> V_49 ;
struct V_4 * V_11 ;
struct V_76 * V_148 ;
int V_25 ;
if ( strcmp ( V_14 -> V_7 -> system , V_106 ) != 0 ) {
V_148 = F_124 ( V_49 , V_14 -> V_7 -> system , V_36 , V_143 ) ;
if ( ! V_148 )
return - V_22 ;
} else
V_148 = V_143 ;
V_36 -> V_72 = F_125 ( V_14 -> V_12 , V_148 ) ;
if ( ! V_36 -> V_72 ) {
F_126 ( L_22 ,
V_14 -> V_12 ) ;
return - 1 ;
}
if ( V_14 -> V_7 -> V_62 && ! ( V_14 -> V_51 & V_86 ) )
F_128 ( L_20 , 0644 , V_36 -> V_72 , V_36 ,
& V_149 ) ;
#ifdef F_25
if ( V_14 -> V_31 . type && V_14 -> V_7 -> V_62 )
F_128 ( L_23 , 0444 , V_36 -> V_72 ,
( void * ) ( long ) V_14 -> V_31 . type ,
& V_150 ) ;
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
F_128 ( L_18 , 0644 , V_36 -> V_72 , V_36 ,
& V_152 ) ;
F_128 ( L_26 , 0644 , V_36 -> V_72 , V_36 ,
& V_153 ) ;
F_128 ( L_27 , 0444 , V_36 -> V_72 , V_14 ,
& V_154 ) ;
return 0 ;
}
static void F_131 ( struct V_5 * V_14 )
{
struct V_35 * V_36 ;
struct V_48 * V_49 ;
F_132 (tr, file) {
if ( V_36 -> V_6 != V_14 )
continue;
F_51 ( V_36 ) ;
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
F_40 ( V_36 , 0 ) ;
F_134 ( V_36 ) ;
break;
} F_33 () ;
if ( V_14 -> V_31 . V_155 )
F_135 ( & V_14 -> V_31 ) ;
F_131 ( V_14 ) ;
F_18 ( & V_14 -> V_69 ) ;
}
static int F_136 ( struct V_5 * V_14 )
{
int V_25 = 0 ;
if ( F_13 ( ! V_14 -> V_12 ) )
return - V_85 ;
if ( V_14 -> V_7 -> V_156 ) {
V_25 = V_14 -> V_7 -> V_156 ( V_14 ) ;
if ( V_25 < 0 && V_25 != - V_157 )
F_137 ( L_28 ,
V_14 -> V_12 ) ;
}
return V_25 ;
}
static int
F_138 ( struct V_5 * V_14 , struct V_158 * V_159 )
{
int V_25 ;
V_25 = F_136 ( V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_14 -> V_69 , & V_160 ) ;
V_14 -> V_159 = V_159 ;
return 0 ;
}
static struct V_35 *
F_139 ( struct V_5 * V_14 ,
struct V_48 * V_49 )
{
struct V_35 * V_36 ;
V_36 = F_9 ( V_81 , V_21 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_6 = V_14 ;
V_36 -> V_49 = V_49 ;
F_140 ( & V_36 -> V_56 , 0 ) ;
F_140 ( & V_36 -> V_161 , 0 ) ;
F_141 ( & V_36 -> V_162 ) ;
F_11 ( & V_36 -> V_69 , & V_49 -> V_105 ) ;
return V_36 ;
}
static int
F_142 ( struct V_5 * V_14 , struct V_48 * V_49 )
{
struct V_35 * V_36 ;
V_36 = F_139 ( V_14 , V_49 ) ;
if ( ! V_36 )
return - V_22 ;
return F_129 ( V_49 -> V_163 , V_36 ) ;
}
static T_5 int
F_143 ( struct V_5 * V_14 ,
struct V_48 * V_49 )
{
struct V_35 * V_36 ;
V_36 = F_139 ( V_14 , V_49 ) ;
if ( ! V_36 )
return - V_22 ;
return 0 ;
}
int F_144 ( struct V_5 * V_14 )
{
int V_25 ;
F_27 ( & V_131 ) ;
F_27 ( & V_50 ) ;
V_25 = F_138 ( V_14 , NULL ) ;
if ( V_25 >= 0 )
F_145 ( V_14 ) ;
F_34 ( & V_50 ) ;
F_34 ( & V_131 ) ;
return V_25 ;
}
static void F_146 ( struct V_5 * V_14 )
{
F_133 ( V_14 ) ;
F_16 ( V_14 ) ;
F_147 ( V_14 ) ;
}
static int F_148 ( struct V_5 * V_14 )
{
struct V_48 * V_49 ;
struct V_35 * V_36 ;
#ifdef F_25
if ( V_14 -> V_164 )
return - V_165 ;
#endif
F_28 (tr, file) {
if ( V_36 -> V_6 != V_14 )
continue;
if ( V_36 -> V_51 & V_52 )
return - V_165 ;
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
F_150 ( & V_166 ) ;
V_25 = F_148 ( V_14 ) ;
F_151 ( & V_166 ) ;
F_34 ( & V_50 ) ;
F_34 ( & V_131 ) ;
return V_25 ;
}
static void F_152 ( struct V_158 * V_159 )
{
struct V_5 * * V_14 , * * V_167 , * * V_168 ;
if ( ! V_159 -> V_169 )
return;
if ( F_153 ( V_159 ) ) {
F_154 ( L_29 ,
V_159 -> V_12 ) ;
return;
}
V_167 = V_159 -> V_170 ;
V_168 = V_159 -> V_170 + V_159 -> V_169 ;
F_155 (call, start, end) {
F_138 ( * V_14 , V_159 ) ;
F_145 ( * V_14 ) ;
}
}
static void F_156 ( struct V_158 * V_159 )
{
struct V_5 * V_14 , * V_107 ;
bool V_171 = false ;
F_150 ( & V_166 ) ;
F_17 (call, p, &ftrace_events, list) {
if ( V_14 -> V_159 == V_159 ) {
if ( V_14 -> V_51 & V_66 )
V_171 = true ;
F_146 ( V_14 ) ;
}
}
F_151 ( & V_166 ) ;
if ( V_171 )
F_157 () ;
}
static int F_158 ( struct V_172 * V_173 ,
unsigned long V_109 , void * V_34 )
{
struct V_158 * V_159 = V_34 ;
F_27 ( & V_131 ) ;
F_27 ( & V_50 ) ;
switch ( V_109 ) {
case V_174 :
F_152 ( V_159 ) ;
break;
case V_175 :
F_156 ( V_159 ) ;
break;
}
F_34 ( & V_50 ) ;
F_34 ( & V_131 ) ;
return 0 ;
}
static void
F_159 ( struct V_48 * V_49 )
{
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
V_25 = F_142 ( V_14 , V_49 ) ;
if ( V_25 < 0 )
F_126 ( L_30 ,
V_14 -> V_12 ) ;
}
}
struct V_35 *
F_160 ( struct V_48 * V_49 , const char * system , const char * V_31 )
{
struct V_35 * V_36 ;
struct V_5 * V_14 ;
F_6 (file, &tr->events, list) {
V_14 = V_36 -> V_6 ;
if ( ! V_14 -> V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_62 )
continue;
if ( V_14 -> V_51 & V_86 )
continue;
if ( strcmp ( V_31 , V_14 -> V_12 ) == 0 &&
strcmp ( system , V_14 -> V_7 -> system ) == 0 )
return V_36 ;
}
return NULL ;
}
static void
F_161 ( unsigned long V_176 , unsigned long V_177 , void * * V_178 )
{
struct V_179 * * V_180 = (struct V_179 * * ) V_178 ;
struct V_179 * V_34 = * V_180 ;
if ( ! V_34 )
return;
if ( V_34 -> V_47 )
F_32 ( V_63 , & V_34 -> V_36 -> V_51 ) ;
else
F_30 ( V_63 , & V_34 -> V_36 -> V_51 ) ;
}
static void
F_162 ( unsigned long V_176 , unsigned long V_177 , void * * V_178 )
{
struct V_179 * * V_180 = (struct V_179 * * ) V_178 ;
struct V_179 * V_34 = * V_180 ;
if ( ! V_34 )
return;
if ( ! V_34 -> V_181 )
return;
if ( V_34 -> V_47 == ! ( V_34 -> V_36 -> V_51 & V_57 ) )
return;
if ( V_34 -> V_181 != - 1 )
( V_34 -> V_181 ) -- ;
F_161 ( V_176 , V_177 , V_178 ) ;
}
static int
F_163 ( struct V_93 * V_94 , unsigned long V_176 ,
struct V_182 * V_183 , void * V_178 )
{
struct V_179 * V_34 = V_178 ;
F_73 ( V_94 , L_31 , ( void * ) V_176 ) ;
F_73 ( V_94 , L_32 ,
V_34 -> V_47 ? V_184 : V_185 ,
V_34 -> V_36 -> V_6 -> V_7 -> system ,
V_34 -> V_36 -> V_6 -> V_12 ) ;
if ( V_34 -> V_181 == - 1 )
F_73 ( V_94 , L_33 ) ;
else
F_73 ( V_94 , L_34 , V_34 -> V_181 ) ;
return 0 ;
}
static int
F_164 ( struct V_182 * V_183 , unsigned long V_176 ,
void * * V_178 )
{
struct V_179 * * V_180 = (struct V_179 * * ) V_178 ;
struct V_179 * V_34 = * V_180 ;
V_34 -> V_186 ++ ;
return 0 ;
}
static void
F_165 ( struct V_182 * V_183 , unsigned long V_176 ,
void * * V_178 )
{
struct V_179 * * V_180 = (struct V_179 * * ) V_178 ;
struct V_179 * V_34 = * V_180 ;
if ( F_43 ( V_34 -> V_186 <= 0 ) )
return;
V_34 -> V_186 -- ;
if ( ! V_34 -> V_186 ) {
F_35 ( V_34 -> V_36 , 0 , 1 ) ;
F_166 ( V_34 -> V_36 -> V_6 -> V_159 ) ;
F_44 ( V_34 ) ;
}
* V_180 = NULL ;
}
static int
F_167 ( struct V_187 * V_188 ,
char * V_189 , char * V_190 , char * V_191 , int V_192 )
{
struct V_48 * V_49 = F_59 () ;
struct V_35 * V_36 ;
struct V_182 * V_183 ;
struct V_179 * V_34 ;
const char * system ;
const char * V_31 ;
char * V_193 ;
bool V_47 ;
int V_25 ;
if ( ! V_192 || ! V_191 )
return - V_85 ;
system = F_57 ( & V_191 , L_3 ) ;
if ( ! V_191 )
return - V_85 ;
V_31 = F_57 ( & V_191 , L_3 ) ;
F_27 ( & V_50 ) ;
V_25 = - V_85 ;
V_36 = F_160 ( V_49 , system , V_31 ) ;
if ( ! V_36 )
goto V_111;
V_47 = strcmp ( V_190 , V_184 ) == 0 ;
if ( V_47 )
V_183 = V_191 ? & V_194 : & V_195 ;
else
V_183 = V_191 ? & V_196 : & V_197 ;
if ( V_189 [ 0 ] == '!' ) {
F_168 ( V_189 + 1 , V_183 ) ;
V_25 = 0 ;
goto V_111;
}
V_25 = - V_22 ;
V_34 = F_108 ( sizeof( * V_34 ) , V_126 ) ;
if ( ! V_34 )
goto V_111;
V_34 -> V_47 = V_47 ;
V_34 -> V_181 = - 1 ;
V_34 -> V_36 = V_36 ;
if ( ! V_191 )
goto V_198;
V_193 = F_57 ( & V_191 , L_3 ) ;
V_25 = - V_85 ;
if ( ! strlen ( V_193 ) )
goto V_141;
V_25 = F_169 ( V_193 , 0 , & V_34 -> V_181 ) ;
if ( V_25 )
goto V_141;
V_198:
V_25 = F_170 ( V_36 -> V_6 -> V_159 ) ;
if ( ! V_25 ) {
V_25 = - V_165 ;
goto V_141;
}
V_25 = F_35 ( V_36 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_101;
V_25 = F_171 ( V_189 , V_183 , V_34 ) ;
if ( ! V_25 ) {
V_25 = - V_199 ;
goto V_200;
} else if ( V_25 < 0 )
goto V_200;
V_25 = 0 ;
V_111:
F_34 ( & V_50 ) ;
return V_25 ;
V_200:
F_35 ( V_36 , 0 , 1 ) ;
V_101:
F_166 ( V_36 -> V_6 -> V_159 ) ;
V_141:
F_44 ( V_34 ) ;
goto V_111;
}
static T_5 int F_172 ( void )
{
int V_25 ;
V_25 = F_173 ( & V_201 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_173 ( & V_202 ) ;
if ( F_13 ( V_25 < 0 ) )
F_174 ( & V_201 ) ;
return V_25 ;
}
static inline int F_172 ( void ) { return 0 ; }
static T_5 void
F_175 ( struct V_48 * V_49 )
{
struct V_35 * V_36 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_129 ( V_49 -> V_163 , V_36 ) ;
if ( V_25 < 0 )
F_126 ( L_30 ,
V_36 -> V_6 -> V_12 ) ;
}
}
static T_5 void
F_176 ( struct V_48 * V_49 )
{
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_43 ( V_14 -> V_159 ) )
continue;
V_25 = F_143 ( V_14 , V_49 ) ;
if ( V_25 < 0 )
F_126 ( L_35 ,
V_14 -> V_12 ) ;
}
}
static void
F_177 ( struct V_48 * V_49 )
{
struct V_35 * V_36 , * V_29 ;
F_17 (file, next, &tr->events, list)
F_51 ( V_36 ) ;
}
static void F_145 ( struct V_5 * V_14 )
{
struct V_48 * V_49 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_142 ( V_14 , V_49 ) ;
}
static T_5 int F_178 ( char * V_203 )
{
F_179 ( V_204 , V_203 , V_205 ) ;
V_206 = true ;
V_207 = true ;
return 1 ;
}
static int
F_180 ( struct V_76 * V_143 , struct V_48 * V_49 )
{
struct V_76 * V_148 ;
struct V_76 * V_75 ;
V_75 = F_127 ( L_36 , 0644 , V_143 ,
V_49 , & V_208 ) ;
if ( ! V_75 ) {
F_126 ( L_37 ) ;
return - V_22 ;
}
V_148 = F_125 ( L_38 , V_143 ) ;
if ( ! V_148 ) {
F_126 ( L_39 ) ;
return - V_22 ;
}
F_128 ( L_40 , 0444 , V_148 ,
V_209 ,
& V_210 ) ;
F_128 ( L_41 , 0444 , V_148 ,
V_211 ,
& V_210 ) ;
F_128 ( L_20 , 0644 , V_148 ,
V_49 , & V_212 ) ;
V_49 -> V_163 = V_148 ;
return 0 ;
}
int F_181 ( struct V_76 * V_143 , struct V_48 * V_49 )
{
int V_25 ;
F_27 ( & V_50 ) ;
V_25 = F_180 ( V_143 , V_49 ) ;
if ( V_25 )
goto V_213;
F_150 ( & V_166 ) ;
F_159 ( V_49 ) ;
F_151 ( & V_166 ) ;
V_213:
F_34 ( & V_50 ) ;
return V_25 ;
}
static T_5 int
F_182 ( struct V_76 * V_143 , struct V_48 * V_49 )
{
int V_25 ;
F_27 ( & V_50 ) ;
V_25 = F_180 ( V_143 , V_49 ) ;
if ( V_25 )
goto V_213;
F_150 ( & V_166 ) ;
F_175 ( V_49 ) ;
F_151 ( & V_166 ) ;
V_213:
F_34 ( & V_50 ) ;
return V_25 ;
}
int F_183 ( struct V_48 * V_49 )
{
F_27 ( & V_50 ) ;
F_184 ( V_49 ) ;
F_54 ( V_49 , NULL , NULL , NULL , 0 ) ;
F_185 () ;
F_150 ( & V_166 ) ;
F_177 ( V_49 ) ;
F_50 ( V_49 -> V_163 ) ;
F_151 ( & V_166 ) ;
V_49 -> V_163 = NULL ;
F_34 ( & V_50 ) ;
return 0 ;
}
static T_5 int F_186 ( void )
{
V_20 = F_187 ( V_10 , V_214 ) ;
V_81 = F_187 ( V_35 , V_214 ) ;
return 0 ;
}
static T_5 int F_188 ( void )
{
struct V_48 * V_49 = F_59 () ;
struct V_5 * * V_215 , * V_14 ;
char * V_87 = V_204 ;
char * V_216 ;
int V_25 ;
F_155 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_14 = * V_215 ;
V_25 = F_136 ( V_14 ) ;
if ( ! V_25 )
F_11 ( & V_14 -> V_69 , & V_160 ) ;
}
F_176 ( V_49 ) ;
while ( true ) {
V_216 = F_57 ( & V_87 , L_42 ) ;
if ( ! V_216 )
break;
if ( ! * V_216 )
continue;
V_25 = F_56 ( V_49 , V_216 , 1 ) ;
if ( V_25 )
F_137 ( L_43 , V_216 ) ;
}
F_189 () ;
F_172 () ;
F_190 () ;
return 0 ;
}
static T_5 int F_191 ( void )
{
struct V_48 * V_49 ;
struct V_76 * V_217 ;
struct V_76 * V_75 ;
int V_25 ;
V_49 = F_59 () ;
V_217 = F_192 () ;
if ( ! V_217 )
return 0 ;
V_75 = F_127 ( L_44 , 0444 , V_217 ,
V_49 , & V_218 ) ;
if ( ! V_75 )
F_126 ( L_45
L_46 ) ;
if ( F_14 () )
F_126 ( L_47 ) ;
V_25 = F_182 ( V_217 , V_49 ) ;
if ( V_25 )
return V_25 ;
#ifdef F_193
V_25 = F_194 ( & V_219 ) ;
if ( V_25 )
F_126 ( L_48 ) ;
#endif
return 0 ;
}
static T_5 void F_195 ( struct V_220 * V_221 )
{
F_52 ( & V_222 ) ;
F_196 ( & V_223 ) ;
F_197 ( 1 ) ;
F_198 ( & V_223 ) ;
F_53 ( & V_222 ) ;
F_27 ( & V_224 ) ;
F_199 ( 1 ) ;
F_34 ( & V_224 ) ;
}
static T_5 int F_200 ( void * V_225 )
{
void * V_226 ;
V_226 = F_94 ( 1234 , V_126 ) ;
if ( ! V_226 )
F_38 ( L_49 ) ;
F_201 ( F_195 ) ;
F_44 ( V_226 ) ;
F_202 ( V_227 ) ;
while ( ! F_203 () )
F_204 () ;
return 0 ;
}
static T_5 void F_205 ( void )
{
struct V_228 * V_229 ;
V_229 = F_206 ( F_200 , NULL , L_50 ) ;
F_199 ( 1 ) ;
F_207 ( V_229 ) ;
}
static T_5 void F_208 ( void )
{
struct V_71 * V_72 ;
struct V_35 * V_36 ;
struct V_5 * V_14 ;
struct V_1 * system ;
struct V_48 * V_49 ;
int V_25 ;
V_49 = F_59 () ;
F_38 ( L_51 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_36 -> V_6 ;
if ( ! V_14 -> V_7 || ! V_14 -> V_7 -> V_38 )
continue;
#ifndef F_209
if ( V_14 -> V_7 -> system &&
strcmp ( V_14 -> V_7 -> system , L_52 ) == 0 )
continue;
#endif
F_38 ( L_53 , V_14 -> V_12 ) ;
if ( V_36 -> V_51 & V_52 ) {
F_126 ( L_54 ) ;
F_43 ( 1 ) ;
continue;
}
F_40 ( V_36 , 1 ) ;
F_205 () ;
F_40 ( V_36 , 0 ) ;
F_210 ( L_55 ) ;
}
F_38 ( L_56 ) ;
F_6 (dir, &tr->systems, list) {
system = V_72 -> V_73 ;
if ( strcmp ( system -> V_12 , L_57 ) == 0 )
continue;
F_38 ( L_58 , system -> V_12 ) ;
V_25 = F_55 ( V_49 , NULL , system -> V_12 , NULL , 1 ) ;
if ( F_43 ( V_25 ) ) {
F_126 ( L_59 ,
system -> V_12 ) ;
continue;
}
F_205 () ;
V_25 = F_55 ( V_49 , NULL , system -> V_12 , NULL , 0 ) ;
if ( F_43 ( V_25 ) ) {
F_126 ( L_60 ,
system -> V_12 ) ;
continue;
}
F_210 ( L_55 ) ;
}
F_38 ( L_61 ) ;
F_38 ( L_62 ) ;
V_25 = F_55 ( V_49 , NULL , NULL , NULL , 1 ) ;
if ( F_43 ( V_25 ) ) {
F_126 ( L_63 ) ;
return;
}
F_205 () ;
V_25 = F_55 ( V_49 , NULL , NULL , NULL , 0 ) ;
if ( F_43 ( V_25 ) ) {
F_126 ( L_64 ) ;
return;
}
F_210 ( L_55 ) ;
}
static void
F_211 ( unsigned long V_176 , unsigned long V_177 ,
struct V_230 * V_231 , struct V_232 * V_232 )
{
struct V_233 * V_31 ;
struct V_234 * V_99 ;
struct V_235 * V_75 ;
unsigned long V_51 ;
long V_236 ;
int V_237 ;
int V_238 ;
V_238 = F_212 () ;
F_213 () ;
V_237 = F_214 () ;
V_236 = F_37 ( & F_215 ( V_239 , V_237 ) ) ;
if ( V_236 != 1 )
goto V_111;
F_216 ( V_51 ) ;
V_31 = F_217 ( & V_99 ,
V_240 , sizeof( * V_75 ) ,
V_51 , V_238 ) ;
if ( ! V_31 )
goto V_111;
V_75 = F_218 ( V_31 ) ;
V_75 -> V_176 = V_176 ;
V_75 -> V_177 = V_177 ;
F_219 ( V_99 , V_31 , V_51 , V_238 ) ;
V_111:
F_220 ( & F_215 ( V_239 , V_237 ) ) ;
F_221 () ;
}
static T_5 void F_222 ( void )
{
int V_25 ;
V_25 = F_223 ( & V_241 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_38 ( L_65 ) ;
return;
}
F_38 ( L_66 ) ;
F_208 () ;
F_224 ( & V_241 ) ;
}
static T_5 void F_222 ( void )
{
}
static T_5 int F_225 ( void )
{
if ( ! V_207 ) {
F_208 () ;
F_222 () ;
}
return 0 ;
}
