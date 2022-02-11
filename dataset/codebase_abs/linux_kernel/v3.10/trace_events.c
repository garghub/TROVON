static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_4 -> V_5 )
return & V_3 -> V_4 -> V_6 ;
return V_3 -> V_4 -> V_5 ( V_3 ) ;
}
static struct V_7 *
F_2 ( struct V_1 * V_8 , char * V_9 )
{
struct V_7 * V_10 ;
F_3 (field, head, link) {
if ( ! strcmp ( V_10 -> V_9 , V_9 ) )
return V_10 ;
}
return NULL ;
}
struct V_7 *
F_4 ( struct V_2 * V_11 , char * V_9 )
{
struct V_7 * V_10 ;
struct V_1 * V_8 ;
V_10 = F_2 ( & V_12 , V_9 ) ;
if ( V_10 )
return V_10 ;
V_8 = F_1 ( V_11 ) ;
return F_2 ( V_8 , V_9 ) ;
}
static int F_5 ( struct V_1 * V_8 , const char * type ,
const char * V_9 , int V_13 , int V_14 ,
int V_15 , int V_16 )
{
struct V_7 * V_10 ;
V_10 = F_6 ( V_17 , V_18 ) ;
if ( ! V_10 )
goto V_19;
V_10 -> V_9 = V_9 ;
V_10 -> type = type ;
if ( V_16 == V_20 )
V_10 -> V_16 = F_7 ( type ) ;
else
V_10 -> V_16 = V_16 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_14 = V_14 ;
V_10 -> V_15 = V_15 ;
F_8 ( & V_10 -> V_21 , V_8 ) ;
return 0 ;
V_19:
F_9 ( V_17 , V_10 ) ;
return - V_22 ;
}
int F_10 ( struct V_2 * V_11 , const char * type ,
const char * V_9 , int V_13 , int V_14 , int V_15 ,
int V_16 )
{
struct V_1 * V_8 ;
if ( F_11 ( ! V_11 -> V_4 ) )
return 0 ;
V_8 = F_1 ( V_11 ) ;
return F_5 ( V_8 , type , V_9 , V_13 , V_14 ,
V_15 , V_16 ) ;
}
static int F_12 ( void )
{
int V_23 ;
struct V_24 V_25 ;
F_13 (unsigned short, type) ;
F_13 (unsigned char, flags) ;
F_13 (unsigned char, preempt_count) ;
F_13 ( int , V_26 ) ;
return V_23 ;
}
static void F_14 ( struct V_2 * V_11 )
{
struct V_7 * V_10 , * V_27 ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_11 ) ;
F_15 (field, next, head, link) {
F_16 ( & V_10 -> V_21 ) ;
F_9 ( V_17 , V_10 ) ;
}
}
int F_17 ( struct V_2 * V_11 )
{
int V_28 ;
V_28 = F_18 ( & V_11 -> V_29 ) ;
if ( ! V_28 )
return - V_30 ;
return 0 ;
}
int F_19 ( struct V_2 * V_11 ,
enum V_31 type , void * V_32 )
{
struct V_33 * V_34 = V_32 ;
switch ( type ) {
case V_35 :
return F_20 ( V_11 -> V_9 ,
V_11 -> V_4 -> V_36 ,
V_34 ) ;
case V_37 :
F_21 ( V_11 -> V_9 ,
V_11 -> V_4 -> V_36 ,
V_34 ) ;
return 0 ;
#ifdef F_22
case V_38 :
return F_20 ( V_11 -> V_9 ,
V_11 -> V_4 -> V_39 ,
V_11 ) ;
case V_40 :
F_21 ( V_11 -> V_9 ,
V_11 -> V_4 -> V_39 ,
V_11 ) ;
return 0 ;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
return 0 ;
#endif
}
return 0 ;
}
void F_23 ( bool V_45 )
{
struct V_33 * V_34 ;
struct V_46 * V_47 ;
F_24 ( & V_48 ) ;
F_25 (tr, file) {
if ( ! ( V_34 -> V_49 & V_50 ) )
continue;
if ( V_45 ) {
F_26 () ;
F_27 ( V_51 , & V_34 -> V_49 ) ;
} else {
F_28 () ;
F_29 ( V_51 , & V_34 -> V_49 ) ;
}
} F_30 () ;
F_31 ( & V_48 ) ;
}
static int F_32 ( struct V_33 * V_34 ,
int V_45 , int V_52 )
{
struct V_2 * V_11 = V_34 -> V_3 ;
int V_23 = 0 ;
int V_53 ;
switch ( V_45 ) {
case 0 :
if ( V_52 ) {
if ( F_33 ( & V_34 -> V_54 ) > 0 )
break;
V_53 = V_34 -> V_49 & V_55 ;
F_29 ( V_56 , & V_34 -> V_49 ) ;
} else
V_53 = ! ( V_34 -> V_49 & V_57 ) ;
if ( V_53 && ( V_34 -> V_49 & V_50 ) ) {
F_29 ( V_58 , & V_34 -> V_49 ) ;
if ( V_34 -> V_49 & V_59 ) {
F_28 () ;
F_29 ( V_51 , & V_34 -> V_49 ) ;
}
V_11 -> V_4 -> V_60 ( V_11 , V_37 , V_34 ) ;
}
if ( V_34 -> V_49 & V_57 )
F_27 ( V_61 , & V_34 -> V_49 ) ;
break;
case 1 :
if ( ! V_52 )
F_29 ( V_61 , & V_34 -> V_49 ) ;
else {
if ( F_34 ( & V_34 -> V_54 ) > 1 )
break;
F_27 ( V_56 , & V_34 -> V_49 ) ;
}
if ( ! ( V_34 -> V_49 & V_50 ) ) {
if ( V_52 )
F_27 ( V_61 , & V_34 -> V_49 ) ;
if ( V_62 & V_63 ) {
F_26 () ;
F_27 ( V_51 , & V_34 -> V_49 ) ;
}
V_23 = V_11 -> V_4 -> V_60 ( V_11 , V_35 , V_34 ) ;
if ( V_23 ) {
F_28 () ;
F_35 ( L_1
L_2 , V_11 -> V_9 ) ;
break;
}
F_27 ( V_58 , & V_34 -> V_49 ) ;
V_11 -> V_49 |= V_64 ;
}
break;
}
return V_23 ;
}
static int F_36 ( struct V_33 * V_34 ,
int V_45 )
{
return F_32 ( V_34 , V_45 , 0 ) ;
}
static void F_37 ( struct V_46 * V_47 )
{
struct V_33 * V_34 ;
F_24 ( & V_48 ) ;
F_3 (file, &tr->events, list) {
F_36 ( V_34 , 0 ) ;
}
F_31 ( & V_48 ) ;
}
static void F_38 ( struct V_65 * system )
{
struct V_66 * V_67 = system -> V_67 ;
F_39 ( system -> V_68 == 0 ) ;
if ( -- system -> V_68 )
return;
F_16 ( & system -> V_69 ) ;
if ( V_67 ) {
F_40 ( V_67 -> V_70 ) ;
F_40 ( V_67 ) ;
}
F_40 ( system ) ;
}
static void F_41 ( struct V_65 * system )
{
F_39 ( system -> V_68 == 0 ) ;
system -> V_68 ++ ;
}
static void F_42 ( struct V_71 * V_72 )
{
F_39 ( V_72 -> V_68 == 0 ) ;
V_72 -> V_68 ++ ;
F_41 ( V_72 -> V_73 ) ;
}
static void F_43 ( struct V_71 * V_72 )
{
F_39 ( V_72 -> V_68 == 0 ) ;
F_39 ( V_72 -> V_73 -> V_68 == 1 && V_72 -> V_68 != 1 ) ;
F_38 ( V_72 -> V_73 ) ;
if ( ! -- V_72 -> V_68 )
F_40 ( V_72 ) ;
}
static void F_44 ( struct V_71 * V_72 )
{
F_24 ( & V_48 ) ;
F_43 ( V_72 ) ;
F_31 ( & V_48 ) ;
}
static int F_45 ( struct V_46 * V_47 , const char * V_74 ,
const char * V_75 , const char * V_29 , int V_76 )
{
struct V_33 * V_34 ;
struct V_2 * V_11 ;
int V_23 = - V_77 ;
F_24 ( & V_48 ) ;
F_3 (file, &tr->events, list) {
V_11 = V_34 -> V_3 ;
if ( ! V_11 -> V_9 || ! V_11 -> V_4 || ! V_11 -> V_4 -> V_60 )
continue;
if ( V_11 -> V_49 & V_78 )
continue;
if ( V_74 &&
strcmp ( V_74 , V_11 -> V_9 ) != 0 &&
strcmp ( V_74 , V_11 -> V_4 -> system ) != 0 )
continue;
if ( V_75 && strcmp ( V_75 , V_11 -> V_4 -> system ) != 0 )
continue;
if ( V_29 && strcmp ( V_29 , V_11 -> V_9 ) != 0 )
continue;
F_36 ( V_34 , V_76 ) ;
V_23 = 0 ;
}
F_31 ( & V_48 ) ;
return V_23 ;
}
static int F_46 ( struct V_46 * V_47 , char * V_79 , int V_76 )
{
char * V_29 = NULL , * V_75 = NULL , * V_74 ;
V_74 = F_47 ( & V_79 , L_3 ) ;
if ( V_79 ) {
V_75 = V_74 ;
V_29 = V_79 ;
V_74 = NULL ;
if ( ! strlen ( V_75 ) || strcmp ( V_75 , L_4 ) == 0 )
V_75 = NULL ;
if ( ! strlen ( V_29 ) || strcmp ( V_29 , L_4 ) == 0 )
V_29 = NULL ;
}
return F_45 ( V_47 , V_74 , V_75 , V_29 , V_76 ) ;
}
int F_48 ( const char * system , const char * V_29 , int V_76 )
{
struct V_46 * V_47 = F_49 () ;
return F_45 ( V_47 , NULL , system , V_29 , V_76 ) ;
}
static T_1
F_50 ( struct V_34 * V_34 , const char T_2 * V_80 ,
T_3 V_81 , T_4 * V_82 )
{
struct V_83 V_84 ;
struct V_85 * V_86 = V_34 -> V_87 ;
struct V_46 * V_47 = V_86 -> V_88 ;
T_1 V_89 , V_23 ;
if ( ! V_81 )
return 0 ;
V_23 = F_51 () ;
if ( V_23 < 0 )
return V_23 ;
if ( F_52 ( & V_84 , V_90 + 1 ) )
return - V_22 ;
V_89 = F_53 ( & V_84 , V_80 , V_81 , V_82 ) ;
if ( V_89 >= 0 && F_54 ( ( & V_84 ) ) ) {
int V_76 = 1 ;
if ( * V_84 . V_91 == '!' )
V_76 = 0 ;
V_84 . V_91 [ V_84 . V_92 ] = 0 ;
V_23 = F_46 ( V_47 , V_84 . V_91 + ! V_76 , V_76 ) ;
if ( V_23 )
goto V_93;
}
V_23 = V_89 ;
V_93:
F_55 ( & V_84 ) ;
return V_23 ;
}
static void *
F_56 ( struct V_85 * V_86 , void * V_94 , T_4 * V_95 )
{
struct V_33 * V_34 = V_94 ;
struct V_2 * V_11 ;
struct V_46 * V_47 = V_86 -> V_88 ;
( * V_95 ) ++ ;
F_57 (file, &tr->events, list) {
V_11 = V_34 -> V_3 ;
if ( V_11 -> V_4 && V_11 -> V_4 -> V_60 )
return V_34 ;
}
return NULL ;
}
static void * F_58 ( struct V_85 * V_86 , T_4 * V_95 )
{
struct V_33 * V_34 ;
struct V_46 * V_47 = V_86 -> V_88 ;
T_4 V_96 ;
F_24 ( & V_48 ) ;
V_34 = F_59 ( & V_47 -> V_97 , struct V_33 , V_69 ) ;
for ( V_96 = 0 ; V_96 <= * V_95 ; ) {
V_34 = F_56 ( V_86 , V_34 , & V_96 ) ;
if ( ! V_34 )
break;
}
return V_34 ;
}
static void *
F_60 ( struct V_85 * V_86 , void * V_94 , T_4 * V_95 )
{
struct V_33 * V_34 = V_94 ;
struct V_46 * V_47 = V_86 -> V_88 ;
( * V_95 ) ++ ;
F_57 (file, &tr->events, list) {
if ( V_34 -> V_49 & V_50 )
return V_34 ;
}
return NULL ;
}
static void * F_61 ( struct V_85 * V_86 , T_4 * V_95 )
{
struct V_33 * V_34 ;
struct V_46 * V_47 = V_86 -> V_88 ;
T_4 V_96 ;
F_24 ( & V_48 ) ;
V_34 = F_59 ( & V_47 -> V_97 , struct V_33 , V_69 ) ;
for ( V_96 = 0 ; V_96 <= * V_95 ; ) {
V_34 = F_60 ( V_86 , V_34 , & V_96 ) ;
if ( ! V_34 )
break;
}
return V_34 ;
}
static int F_62 ( struct V_85 * V_86 , void * V_94 )
{
struct V_33 * V_34 = V_94 ;
struct V_2 * V_11 = V_34 -> V_3 ;
if ( strcmp ( V_11 -> V_4 -> system , V_98 ) != 0 )
F_63 ( V_86 , L_5 , V_11 -> V_4 -> system ) ;
F_63 ( V_86 , L_2 , V_11 -> V_9 ) ;
return 0 ;
}
static void F_64 ( struct V_85 * V_86 , void * V_99 )
{
F_31 ( & V_48 ) ;
}
static T_1
F_65 ( struct V_34 * V_100 , char T_2 * V_80 , T_3 V_81 ,
T_4 * V_82 )
{
struct V_33 * V_34 = V_100 -> V_87 ;
char * V_79 ;
if ( V_34 -> V_49 & V_50 ) {
if ( V_34 -> V_49 & V_55 )
V_79 = L_6 ;
else if ( V_34 -> V_49 & V_57 )
V_79 = L_7 ;
else
V_79 = L_8 ;
} else
V_79 = L_9 ;
return F_66 ( V_80 , V_81 , V_82 , V_79 , strlen ( V_79 ) ) ;
}
static T_1
F_67 ( struct V_34 * V_100 , const char T_2 * V_80 , T_3 V_81 ,
T_4 * V_82 )
{
struct V_33 * V_34 = V_100 -> V_87 ;
unsigned long V_101 ;
int V_23 ;
if ( ! V_34 )
return - V_77 ;
V_23 = F_68 ( V_80 , V_81 , 10 , & V_101 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_51 () ;
if ( V_23 < 0 )
return V_23 ;
switch ( V_101 ) {
case 0 :
case 1 :
F_24 ( & V_48 ) ;
V_23 = F_36 ( V_34 , V_101 ) ;
F_31 ( & V_48 ) ;
break;
default:
return - V_77 ;
}
* V_82 += V_81 ;
return V_23 ? V_23 : V_81 ;
}
static T_1
F_69 ( struct V_34 * V_100 , char T_2 * V_80 , T_3 V_81 ,
T_4 * V_82 )
{
const char V_102 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_71 * V_72 = V_100 -> V_87 ;
struct V_65 * system = V_72 -> V_73 ;
struct V_2 * V_11 ;
struct V_33 * V_34 ;
struct V_46 * V_47 = V_72 -> V_47 ;
char V_79 [ 2 ] ;
int V_76 = 0 ;
int V_23 ;
F_24 ( & V_48 ) ;
F_3 (file, &tr->events, list) {
V_11 = V_34 -> V_3 ;
if ( ! V_11 -> V_9 || ! V_11 -> V_4 || ! V_11 -> V_4 -> V_60 )
continue;
if ( system && strcmp ( V_11 -> V_4 -> system , system -> V_9 ) != 0 )
continue;
V_76 |= ( 1 << ! ! ( V_34 -> V_49 & V_50 ) ) ;
if ( V_76 == 3 )
break;
}
F_31 ( & V_48 ) ;
V_79 [ 0 ] = V_102 [ V_76 ] ;
V_79 [ 1 ] = '\n' ;
V_23 = F_66 ( V_80 , V_81 , V_82 , V_79 , 2 ) ;
return V_23 ;
}
static T_1
F_70 ( struct V_34 * V_100 , const char T_2 * V_80 , T_3 V_81 ,
T_4 * V_82 )
{
struct V_71 * V_72 = V_100 -> V_87 ;
struct V_65 * system = V_72 -> V_73 ;
const char * V_9 = NULL ;
unsigned long V_101 ;
T_1 V_23 ;
V_23 = F_68 ( V_80 , V_81 , 10 , & V_101 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_51 () ;
if ( V_23 < 0 )
return V_23 ;
if ( V_101 != 0 && V_101 != 1 )
return - V_77 ;
if ( system )
V_9 = system -> V_9 ;
V_23 = F_45 ( V_72 -> V_47 , NULL , V_9 , NULL , V_101 ) ;
if ( V_23 )
goto V_103;
V_23 = V_81 ;
V_103:
* V_82 += V_81 ;
return V_23 ;
}
static void * F_71 ( struct V_85 * V_86 , void * V_94 , T_4 * V_95 )
{
struct V_2 * V_11 = V_86 -> V_88 ;
struct V_7 * V_10 ;
struct V_1 * V_104 = & V_12 ;
struct V_1 * V_8 = F_1 ( V_11 ) ;
( * V_95 ) ++ ;
switch ( ( unsigned long ) V_94 ) {
case V_105 :
if ( F_72 ( F_73 ( V_104 ) ) )
return NULL ;
V_10 = F_59 ( V_104 -> V_106 ,
struct V_7 , V_21 ) ;
return V_10 ;
case V_107 :
if ( F_72 ( F_73 ( V_8 ) ) )
return NULL ;
V_10 = F_59 ( V_8 -> V_106 , struct V_7 , V_21 ) ;
return V_10 ;
case V_108 :
return NULL ;
}
V_10 = V_94 ;
if ( V_10 -> V_21 . V_106 == V_104 )
return ( void * ) V_107 ;
else if ( V_10 -> V_21 . V_106 == V_8 )
return ( void * ) V_108 ;
V_10 = F_59 ( V_10 -> V_21 . V_106 , struct V_7 , V_21 ) ;
return V_10 ;
}
static void * F_74 ( struct V_85 * V_86 , T_4 * V_95 )
{
T_4 V_96 = 0 ;
void * V_99 ;
if ( ! * V_95 )
return ( void * ) V_105 ;
V_99 = ( void * ) V_105 ;
do {
V_99 = F_71 ( V_86 , V_99 , & V_96 ) ;
} while ( V_99 && V_96 < * V_95 );
return V_99 ;
}
static int F_75 ( struct V_85 * V_86 , void * V_94 )
{
struct V_2 * V_11 = V_86 -> V_88 ;
struct V_7 * V_10 ;
const char * V_109 ;
switch ( ( unsigned long ) V_94 ) {
case V_105 :
F_63 ( V_86 , L_10 , V_11 -> V_9 ) ;
F_63 ( V_86 , L_11 , V_11 -> V_29 . type ) ;
F_63 ( V_86 , L_12 ) ;
return 0 ;
case V_107 :
F_76 ( V_86 , '\n' ) ;
return 0 ;
case V_108 :
F_63 ( V_86 , L_13 ,
V_11 -> V_110 ) ;
return 0 ;
}
V_10 = V_94 ;
V_109 = strchr ( V_10 -> type , '[' ) ;
if ( ! strncmp ( V_10 -> type , L_14 , 10 ) )
V_109 = NULL ;
if ( ! V_109 )
F_63 ( V_86 , L_15 ,
V_10 -> type , V_10 -> V_9 , V_10 -> V_13 ,
V_10 -> V_14 , ! ! V_10 -> V_15 ) ;
else
F_63 ( V_86 , L_16 ,
( int ) ( V_109 - V_10 -> type ) ,
V_10 -> type , V_10 -> V_9 ,
V_109 , V_10 -> V_13 ,
V_10 -> V_14 , ! ! V_10 -> V_15 ) ;
return 0 ;
}
static void F_77 ( struct V_85 * V_86 , void * V_99 )
{
}
static int F_78 ( struct V_111 * V_111 , struct V_34 * V_34 )
{
struct V_2 * V_11 = V_111 -> V_112 ;
struct V_85 * V_86 ;
int V_23 ;
V_23 = F_79 ( V_34 , & V_113 ) ;
if ( V_23 < 0 )
return V_23 ;
V_86 = V_34 -> V_87 ;
V_86 -> V_88 = V_11 ;
return 0 ;
}
static T_1
F_80 ( struct V_34 * V_100 , char T_2 * V_80 , T_3 V_81 , T_4 * V_82 )
{
struct V_2 * V_11 = V_100 -> V_87 ;
struct V_114 * V_115 ;
int V_116 ;
if ( * V_82 )
return 0 ;
V_115 = F_81 ( sizeof( * V_115 ) , V_117 ) ;
if ( ! V_115 )
return - V_22 ;
F_82 ( V_115 ) ;
F_83 ( V_115 , L_17 , V_11 -> V_29 . type ) ;
V_116 = F_66 ( V_80 , V_81 , V_82 ,
V_115 -> V_91 , V_115 -> V_118 ) ;
F_40 ( V_115 ) ;
return V_116 ;
}
static T_1
F_84 ( struct V_34 * V_100 , char T_2 * V_80 , T_3 V_81 ,
T_4 * V_82 )
{
struct V_2 * V_11 = V_100 -> V_87 ;
struct V_114 * V_115 ;
int V_116 ;
if ( * V_82 )
return 0 ;
V_115 = F_81 ( sizeof( * V_115 ) , V_117 ) ;
if ( ! V_115 )
return - V_22 ;
F_82 ( V_115 ) ;
F_85 ( V_11 , V_115 ) ;
V_116 = F_66 ( V_80 , V_81 , V_82 , V_115 -> V_91 , V_115 -> V_118 ) ;
F_40 ( V_115 ) ;
return V_116 ;
}
static T_1
F_86 ( struct V_34 * V_100 , const char T_2 * V_80 , T_3 V_81 ,
T_4 * V_82 )
{
struct V_2 * V_11 = V_100 -> V_87 ;
char * V_79 ;
int V_19 ;
if ( V_81 >= V_119 )
return - V_77 ;
V_79 = ( char * ) F_87 ( V_120 ) ;
if ( ! V_79 )
return - V_22 ;
if ( F_88 ( V_79 , V_80 , V_81 ) ) {
F_89 ( ( unsigned long ) V_79 ) ;
return - V_121 ;
}
V_79 [ V_81 ] = '\0' ;
V_19 = F_90 ( V_11 , V_79 ) ;
F_89 ( ( unsigned long ) V_79 ) ;
if ( V_19 < 0 )
return V_19 ;
* V_82 += V_81 ;
return V_81 ;
}
static int F_91 ( struct V_111 * V_111 , struct V_34 * V_100 )
{
struct V_65 * system = NULL ;
struct V_71 * V_72 = NULL ;
struct V_46 * V_47 ;
int V_23 ;
F_24 ( & V_48 ) ;
F_3 (tr, &ftrace_trace_arrays, list) {
F_3 (dir, &tr->systems, list) {
if ( V_72 == V_111 -> V_112 ) {
if ( V_72 -> V_122 ) {
F_42 ( V_72 ) ;
system = V_72 -> V_73 ;
}
goto V_123;
}
}
}
V_123:
F_31 ( & V_48 ) ;
if ( ! system )
return - V_30 ;
F_11 ( ! V_72 ) ;
V_23 = F_92 ( V_111 , V_100 ) ;
if ( V_23 < 0 )
F_44 ( V_72 ) ;
return V_23 ;
}
static int F_93 ( struct V_111 * V_111 , struct V_34 * V_100 )
{
struct V_71 * V_72 ;
struct V_46 * V_47 = V_111 -> V_112 ;
int V_23 ;
V_72 = F_94 ( sizeof( * V_72 ) , V_117 ) ;
if ( ! V_72 )
return - V_22 ;
V_72 -> V_47 = V_47 ;
V_23 = F_92 ( V_111 , V_100 ) ;
if ( V_23 < 0 )
F_40 ( V_72 ) ;
V_100 -> V_87 = V_72 ;
return V_23 ;
}
static int F_95 ( struct V_111 * V_111 , struct V_34 * V_34 )
{
struct V_71 * V_72 = V_34 -> V_87 ;
if ( V_72 -> V_73 )
F_44 ( V_72 ) ;
else
F_40 ( V_72 ) ;
return 0 ;
}
static T_1
F_96 ( struct V_34 * V_100 , char T_2 * V_80 , T_3 V_81 ,
T_4 * V_82 )
{
struct V_71 * V_72 = V_100 -> V_87 ;
struct V_65 * system = V_72 -> V_73 ;
struct V_114 * V_115 ;
int V_116 ;
if ( * V_82 )
return 0 ;
V_115 = F_81 ( sizeof( * V_115 ) , V_117 ) ;
if ( ! V_115 )
return - V_22 ;
F_82 ( V_115 ) ;
F_97 ( system , V_115 ) ;
V_116 = F_66 ( V_80 , V_81 , V_82 , V_115 -> V_91 , V_115 -> V_118 ) ;
F_40 ( V_115 ) ;
return V_116 ;
}
static T_1
F_98 ( struct V_34 * V_100 , const char T_2 * V_80 , T_3 V_81 ,
T_4 * V_82 )
{
struct V_71 * V_72 = V_100 -> V_87 ;
char * V_79 ;
int V_19 ;
if ( V_81 >= V_119 )
return - V_77 ;
V_79 = ( char * ) F_87 ( V_120 ) ;
if ( ! V_79 )
return - V_22 ;
if ( F_88 ( V_79 , V_80 , V_81 ) ) {
F_89 ( ( unsigned long ) V_79 ) ;
return - V_121 ;
}
V_79 [ V_81 ] = '\0' ;
V_19 = F_99 ( V_72 , V_79 ) ;
F_89 ( ( unsigned long ) V_79 ) ;
if ( V_19 < 0 )
return V_19 ;
* V_82 += V_81 ;
return V_81 ;
}
static T_1
F_100 ( struct V_34 * V_100 , char T_2 * V_80 , T_3 V_81 , T_4 * V_82 )
{
int (* F_101)( struct V_114 * V_115 ) = V_100 -> V_87 ;
struct V_114 * V_115 ;
int V_116 ;
if ( * V_82 )
return 0 ;
V_115 = F_81 ( sizeof( * V_115 ) , V_117 ) ;
if ( ! V_115 )
return - V_22 ;
F_82 ( V_115 ) ;
F_101 ( V_115 ) ;
V_116 = F_66 ( V_80 , V_81 , V_82 , V_115 -> V_91 , V_115 -> V_118 ) ;
F_40 ( V_115 ) ;
return V_116 ;
}
static int
F_102 ( struct V_111 * V_111 , struct V_34 * V_34 ,
const struct V_124 * V_125 )
{
struct V_85 * V_86 ;
int V_23 ;
V_23 = F_79 ( V_34 , V_125 ) ;
if ( V_23 < 0 )
return V_23 ;
V_86 = V_34 -> V_87 ;
V_86 -> V_88 = V_111 -> V_112 ;
return V_23 ;
}
static int
F_103 ( struct V_111 * V_111 , struct V_34 * V_34 )
{
const struct V_124 * V_125 = & V_126 ;
return F_102 ( V_111 , V_34 , V_125 ) ;
}
static int
F_104 ( struct V_111 * V_111 , struct V_34 * V_34 )
{
const struct V_124 * V_125 = & V_127 ;
struct V_46 * V_47 = V_111 -> V_112 ;
if ( ( V_34 -> V_128 & V_129 ) &&
( V_34 -> V_130 & V_131 ) )
F_37 ( V_47 ) ;
return F_102 ( V_111 , V_34 , V_125 ) ;
}
static struct V_65 *
F_105 ( const char * V_9 )
{
struct V_65 * system ;
system = F_81 ( sizeof( * system ) , V_117 ) ;
if ( ! system )
return NULL ;
system -> V_68 = 1 ;
system -> V_9 = V_9 ;
system -> V_67 = NULL ;
system -> V_67 = F_94 ( sizeof( struct V_66 ) , V_117 ) ;
if ( ! system -> V_67 )
goto V_132;
F_8 ( & system -> V_69 , & V_133 ) ;
return system ;
V_132:
F_40 ( system ) ;
return NULL ;
}
static struct V_134 *
F_106 ( struct V_46 * V_47 , const char * V_9 ,
struct V_33 * V_34 , struct V_134 * V_135 )
{
struct V_71 * V_72 ;
struct V_65 * system ;
struct V_134 * V_136 ;
F_3 (dir, &tr->systems, list) {
system = V_72 -> V_73 ;
if ( strcmp ( system -> V_9 , V_9 ) == 0 ) {
V_72 -> V_122 ++ ;
V_34 -> system = V_72 ;
return V_72 -> V_136 ;
}
}
F_3 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_9 , V_9 ) == 0 )
break;
}
if ( & system -> V_69 == & V_133 )
system = NULL ;
V_72 = F_81 ( sizeof( * V_72 ) , V_117 ) ;
if ( ! V_72 )
goto V_137;
if ( ! system ) {
system = F_105 ( V_9 ) ;
if ( ! system )
goto V_132;
} else
F_41 ( system ) ;
V_72 -> V_136 = F_107 ( V_9 , V_135 ) ;
if ( ! V_72 -> V_136 ) {
F_108 ( L_18 , V_9 ) ;
F_38 ( system ) ;
goto V_132;
}
V_72 -> V_47 = V_47 ;
V_72 -> V_68 = 1 ;
V_72 -> V_122 = 1 ;
V_72 -> V_73 = system ;
V_34 -> system = V_72 ;
V_136 = F_109 ( L_19 , 0644 , V_72 -> V_136 , V_72 ,
& V_138 ) ;
if ( ! V_136 ) {
F_40 ( system -> V_67 ) ;
system -> V_67 = NULL ;
F_108 ( L_20 , V_9 ) ;
}
F_110 ( L_21 , 0644 , V_72 -> V_136 , V_72 ,
& V_139 ) ;
F_8 ( & V_72 -> V_69 , & V_47 -> V_140 ) ;
return V_72 -> V_136 ;
V_132:
F_40 ( V_72 ) ;
V_137:
if ( ! V_72 || ! system )
F_108 ( L_22 ,
V_9 ) ;
return NULL ;
}
static int
F_111 ( struct V_134 * V_135 ,
struct V_33 * V_34 ,
const struct V_141 * V_28 ,
const struct V_141 * V_45 ,
const struct V_141 * V_67 ,
const struct V_141 * V_142 )
{
struct V_2 * V_11 = V_34 -> V_3 ;
struct V_46 * V_47 = V_34 -> V_47 ;
struct V_1 * V_8 ;
struct V_134 * V_143 ;
int V_23 ;
if ( strcmp ( V_11 -> V_4 -> system , V_98 ) != 0 ) {
V_143 = F_106 ( V_47 , V_11 -> V_4 -> system , V_34 , V_135 ) ;
if ( ! V_143 )
return - V_22 ;
} else
V_143 = V_135 ;
V_34 -> V_72 = F_107 ( V_11 -> V_9 , V_143 ) ;
if ( ! V_34 -> V_72 ) {
F_108 ( L_23 ,
V_11 -> V_9 ) ;
return - 1 ;
}
if ( V_11 -> V_4 -> V_60 && ! ( V_11 -> V_49 & V_78 ) )
F_110 ( L_21 , 0644 , V_34 -> V_72 , V_34 ,
V_45 ) ;
#ifdef F_22
if ( V_11 -> V_29 . type && V_11 -> V_4 -> V_60 )
F_110 ( L_24 , 0444 , V_34 -> V_72 , V_11 ,
V_28 ) ;
#endif
V_8 = F_1 ( V_11 ) ;
if ( F_73 ( V_8 ) ) {
V_23 = V_11 -> V_4 -> V_144 ( V_11 ) ;
if ( V_23 < 0 ) {
F_108 ( L_25
L_26 , V_11 -> V_9 ) ;
return - 1 ;
}
}
F_110 ( L_19 , 0644 , V_34 -> V_72 , V_11 ,
V_67 ) ;
F_110 ( L_27 , 0444 , V_34 -> V_72 , V_11 ,
V_142 ) ;
return 0 ;
}
static void F_112 ( struct V_71 * V_72 )
{
if ( ! V_72 )
return;
if ( ! -- V_72 -> V_122 ) {
F_113 ( V_72 -> V_136 ) ;
F_16 ( & V_72 -> V_69 ) ;
F_43 ( V_72 ) ;
}
}
static void F_114 ( struct V_2 * V_11 )
{
struct V_33 * V_34 ;
struct V_46 * V_47 ;
F_115 (tr, file) {
if ( V_34 -> V_3 != V_11 )
continue;
F_16 ( & V_34 -> V_69 ) ;
F_113 ( V_34 -> V_72 ) ;
F_112 ( V_34 -> system ) ;
F_9 ( V_145 , V_34 ) ;
break;
} F_30 () ;
}
static void F_116 ( struct V_2 * V_11 )
{
struct V_46 * V_47 ;
struct V_33 * V_34 ;
F_25 (tr, file) {
if ( V_34 -> V_3 != V_11 )
continue;
F_36 ( V_34 , 0 ) ;
break;
} F_30 () ;
if ( V_11 -> V_29 . V_146 )
F_117 ( & V_11 -> V_29 ) ;
F_114 ( V_11 ) ;
F_16 ( & V_11 -> V_69 ) ;
}
static int F_118 ( struct V_2 * V_11 )
{
int V_23 = 0 ;
if ( F_11 ( ! V_11 -> V_9 ) )
return - V_77 ;
if ( V_11 -> V_4 -> V_147 ) {
V_23 = V_11 -> V_4 -> V_147 ( V_11 ) ;
if ( V_23 < 0 && V_23 != - V_148 )
F_119 ( L_28 ,
V_11 -> V_9 ) ;
}
return V_23 ;
}
static int
F_120 ( struct V_2 * V_11 , struct V_149 * V_150 )
{
int V_23 ;
V_23 = F_118 ( V_11 ) ;
if ( V_23 < 0 )
return V_23 ;
F_8 ( & V_11 -> V_69 , & V_151 ) ;
V_11 -> V_150 = V_150 ;
return 0 ;
}
static struct V_33 *
F_121 ( struct V_2 * V_11 ,
struct V_46 * V_47 )
{
struct V_33 * V_34 ;
V_34 = F_6 ( V_145 , V_18 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_3 = V_11 ;
V_34 -> V_47 = V_47 ;
F_122 ( & V_34 -> V_54 , 0 ) ;
F_8 ( & V_34 -> V_69 , & V_47 -> V_97 ) ;
return V_34 ;
}
static int
F_123 ( struct V_2 * V_11 ,
struct V_46 * V_47 ,
const struct V_141 * V_28 ,
const struct V_141 * V_45 ,
const struct V_141 * V_67 ,
const struct V_141 * V_142 )
{
struct V_33 * V_34 ;
V_34 = F_121 ( V_11 , V_47 ) ;
if ( ! V_34 )
return - V_22 ;
return F_111 ( V_47 -> V_152 , V_34 , V_28 , V_45 , V_67 , V_142 ) ;
}
static T_5 int
F_124 ( struct V_2 * V_11 ,
struct V_46 * V_47 )
{
struct V_33 * V_34 ;
V_34 = F_121 ( V_11 , V_47 ) ;
if ( ! V_34 )
return - V_22 ;
return 0 ;
}
int F_125 ( struct V_2 * V_11 )
{
int V_23 ;
F_24 ( & V_48 ) ;
V_23 = F_120 ( V_11 , NULL ) ;
if ( V_23 >= 0 )
F_126 ( V_11 , NULL ) ;
F_31 ( & V_48 ) ;
return V_23 ;
}
static void F_127 ( struct V_2 * V_11 )
{
F_116 ( V_11 ) ;
F_14 ( V_11 ) ;
F_128 ( V_11 ) ;
}
void F_129 ( struct V_2 * V_11 )
{
F_24 ( & V_48 ) ;
F_130 ( & V_153 ) ;
F_127 ( V_11 ) ;
F_131 ( & V_153 ) ;
F_31 ( & V_48 ) ;
}
static struct V_154 *
F_132 ( struct V_154 * V_155 , struct V_149 * V_150 )
{
if ( V_155 && V_150 == V_155 -> V_150 )
return V_155 ;
F_3 (file_ops, &ftrace_module_file_list, list) {
if ( V_155 -> V_150 == V_150 )
return V_155 ;
}
return NULL ;
}
static struct V_154 *
F_133 ( struct V_149 * V_150 )
{
struct V_154 * V_155 ;
V_155 = F_81 ( sizeof( * V_155 ) , V_117 ) ;
if ( ! V_155 )
return NULL ;
V_155 -> V_150 = V_150 ;
V_155 -> V_28 = V_156 ;
V_155 -> V_28 . V_157 = V_150 ;
V_155 -> V_45 = V_158 ;
V_155 -> V_45 . V_157 = V_150 ;
V_155 -> V_67 = V_159 ;
V_155 -> V_67 . V_157 = V_150 ;
V_155 -> V_142 = V_160 ;
V_155 -> V_142 . V_157 = V_150 ;
F_8 ( & V_155 -> V_69 , & V_161 ) ;
return V_155 ;
}
static void F_134 ( struct V_149 * V_150 )
{
struct V_154 * V_155 = NULL ;
struct V_2 * * V_11 , * * V_162 , * * V_163 ;
V_162 = V_150 -> V_164 ;
V_163 = V_150 -> V_164 + V_150 -> V_165 ;
if ( V_162 == V_163 )
return;
V_155 = F_133 ( V_150 ) ;
if ( ! V_155 )
return;
F_135 (call, start, end) {
F_120 ( * V_11 , V_150 ) ;
F_126 ( * V_11 , V_155 ) ;
}
}
static void F_136 ( struct V_149 * V_150 )
{
struct V_154 * V_155 ;
struct V_2 * V_11 , * V_99 ;
bool V_166 = false ;
F_130 ( & V_153 ) ;
F_15 (call, p, &ftrace_events, list) {
if ( V_11 -> V_150 == V_150 ) {
if ( V_11 -> V_49 & V_64 )
V_166 = true ;
F_127 ( V_11 ) ;
}
}
F_3 (file_ops, &ftrace_module_file_list, list) {
if ( V_155 -> V_150 == V_150 )
break;
}
if ( & V_155 -> V_69 != & V_161 ) {
F_16 ( & V_155 -> V_69 ) ;
F_40 ( V_155 ) ;
}
F_131 ( & V_153 ) ;
if ( V_166 )
F_137 () ;
}
static int F_138 ( struct V_167 * V_168 ,
unsigned long V_101 , void * V_32 )
{
struct V_149 * V_150 = V_32 ;
F_24 ( & V_48 ) ;
switch ( V_101 ) {
case V_169 :
F_134 ( V_150 ) ;
break;
case V_170 :
F_136 ( V_150 ) ;
break;
}
F_31 ( & V_48 ) ;
return 0 ;
}
static int
F_139 ( struct V_2 * V_11 ,
struct V_46 * V_47 ,
struct V_154 * V_155 )
{
return F_123 ( V_11 , V_47 ,
& V_155 -> V_28 , & V_155 -> V_45 ,
& V_155 -> V_67 , & V_155 -> V_142 ) ;
}
static inline struct V_154 *
F_132 ( struct V_154 * V_155 , struct V_149 * V_150 )
{
return NULL ;
}
static inline int F_138 ( struct V_167 * V_168 ,
unsigned long V_101 , void * V_32 )
{
return 0 ;
}
static inline int
F_139 ( struct V_2 * V_11 ,
struct V_46 * V_47 ,
struct V_154 * V_155 )
{
return - V_30 ;
}
static void
F_140 ( struct V_46 * V_47 )
{
struct V_154 * V_155 = NULL ;
struct V_2 * V_11 ;
int V_23 ;
F_3 (call, &ftrace_events, list) {
if ( V_11 -> V_150 ) {
V_155 = F_132 ( V_155 , V_11 -> V_150 ) ;
if ( ! V_155 )
continue;
V_23 = F_139 ( V_11 , V_47 , V_155 ) ;
if ( V_23 < 0 )
F_108 ( L_29 ,
V_11 -> V_9 ) ;
continue;
}
V_23 = F_123 ( V_11 , V_47 ,
& V_156 ,
& V_158 ,
& V_159 ,
& V_160 ) ;
if ( V_23 < 0 )
F_108 ( L_29 ,
V_11 -> V_9 ) ;
}
}
static struct V_33 *
F_141 ( struct V_46 * V_47 , const char * system , const char * V_29 )
{
struct V_33 * V_34 ;
struct V_2 * V_11 ;
F_3 (file, &tr->events, list) {
V_11 = V_34 -> V_3 ;
if ( ! V_11 -> V_9 || ! V_11 -> V_4 || ! V_11 -> V_4 -> V_60 )
continue;
if ( V_11 -> V_49 & V_78 )
continue;
if ( strcmp ( V_29 , V_11 -> V_9 ) == 0 &&
strcmp ( system , V_11 -> V_4 -> system ) == 0 )
return V_34 ;
}
return NULL ;
}
static void
F_142 ( unsigned long V_171 , unsigned long V_172 , void * * V_173 )
{
struct V_174 * * V_175 = (struct V_174 * * ) V_173 ;
struct V_174 * V_32 = * V_175 ;
if ( ! V_32 )
return;
if ( V_32 -> V_45 )
F_29 ( V_61 , & V_32 -> V_34 -> V_49 ) ;
else
F_27 ( V_61 , & V_32 -> V_34 -> V_49 ) ;
}
static void
F_143 ( unsigned long V_171 , unsigned long V_172 , void * * V_173 )
{
struct V_174 * * V_175 = (struct V_174 * * ) V_173 ;
struct V_174 * V_32 = * V_175 ;
if ( ! V_32 )
return;
if ( ! V_32 -> V_176 )
return;
if ( V_32 -> V_45 == ! ( V_32 -> V_34 -> V_49 & V_55 ) )
return;
if ( V_32 -> V_176 != - 1 )
( V_32 -> V_176 ) -- ;
F_142 ( V_171 , V_172 , V_173 ) ;
}
static int
F_144 ( struct V_85 * V_86 , unsigned long V_171 ,
struct V_177 * V_178 , void * V_173 )
{
struct V_174 * V_32 = V_173 ;
F_63 ( V_86 , L_30 , ( void * ) V_171 ) ;
F_63 ( V_86 , L_31 ,
V_32 -> V_45 ? V_179 : V_180 ,
V_32 -> V_34 -> V_3 -> V_4 -> system ,
V_32 -> V_34 -> V_3 -> V_9 ) ;
if ( V_32 -> V_176 == - 1 )
F_63 ( V_86 , L_32 ) ;
else
F_63 ( V_86 , L_33 , V_32 -> V_176 ) ;
return 0 ;
}
static int
F_145 ( struct V_177 * V_178 , unsigned long V_171 ,
void * * V_173 )
{
struct V_174 * * V_175 = (struct V_174 * * ) V_173 ;
struct V_174 * V_32 = * V_175 ;
V_32 -> V_181 ++ ;
return 0 ;
}
static void
F_146 ( struct V_177 * V_178 , unsigned long V_171 ,
void * * V_173 )
{
struct V_174 * * V_175 = (struct V_174 * * ) V_173 ;
struct V_174 * V_32 = * V_175 ;
if ( F_39 ( V_32 -> V_181 <= 0 ) )
return;
V_32 -> V_181 -- ;
if ( ! V_32 -> V_181 ) {
F_32 ( V_32 -> V_34 , 0 , 1 ) ;
F_147 ( V_32 -> V_34 -> V_3 -> V_150 ) ;
F_40 ( V_32 ) ;
}
* V_175 = NULL ;
}
static int
F_148 ( struct V_182 * V_183 ,
char * V_184 , char * V_185 , char * V_186 , int V_187 )
{
struct V_46 * V_47 = F_49 () ;
struct V_33 * V_34 ;
struct V_177 * V_178 ;
struct V_174 * V_32 ;
const char * system ;
const char * V_29 ;
char * V_188 ;
bool V_45 ;
int V_23 ;
if ( ! V_187 )
return - V_77 ;
if ( ! V_186 )
return - V_77 ;
system = F_47 ( & V_186 , L_3 ) ;
if ( ! V_186 )
return - V_77 ;
V_29 = F_47 ( & V_186 , L_3 ) ;
F_24 ( & V_48 ) ;
V_23 = - V_77 ;
V_34 = F_141 ( V_47 , system , V_29 ) ;
if ( ! V_34 )
goto V_103;
V_45 = strcmp ( V_185 , V_179 ) == 0 ;
if ( V_45 )
V_178 = V_186 ? & V_189 : & V_190 ;
else
V_178 = V_186 ? & V_191 : & V_192 ;
if ( V_184 [ 0 ] == '!' ) {
F_149 ( V_184 + 1 , V_178 ) ;
V_23 = 0 ;
goto V_103;
}
V_23 = - V_22 ;
V_32 = F_94 ( sizeof( * V_32 ) , V_117 ) ;
if ( ! V_32 )
goto V_103;
V_32 -> V_45 = V_45 ;
V_32 -> V_176 = - 1 ;
V_32 -> V_34 = V_34 ;
if ( ! V_186 )
goto V_193;
V_188 = F_47 ( & V_186 , L_3 ) ;
V_23 = - V_77 ;
if ( ! strlen ( V_188 ) )
goto V_132;
V_23 = F_150 ( V_188 , 0 , & V_32 -> V_176 ) ;
if ( V_23 )
goto V_132;
V_193:
V_23 = F_151 ( V_34 -> V_3 -> V_150 ) ;
if ( ! V_23 ) {
V_23 = - V_194 ;
goto V_132;
}
V_23 = F_32 ( V_34 , 1 , 1 ) ;
if ( V_23 < 0 )
goto V_93;
V_23 = F_152 ( V_184 , V_178 , V_32 ) ;
if ( ! V_23 ) {
V_23 = - V_195 ;
goto V_196;
} else if ( V_23 < 0 )
goto V_196;
V_23 = 0 ;
V_103:
F_31 ( & V_48 ) ;
return V_23 ;
V_196:
F_32 ( V_34 , 0 , 1 ) ;
V_93:
F_147 ( V_34 -> V_3 -> V_150 ) ;
V_132:
F_40 ( V_32 ) ;
goto V_103;
}
static T_5 int F_153 ( void )
{
int V_23 ;
V_23 = F_154 ( & V_197 ) ;
if ( F_11 ( V_23 < 0 ) )
return V_23 ;
V_23 = F_154 ( & V_198 ) ;
if ( F_11 ( V_23 < 0 ) )
F_155 ( & V_197 ) ;
return V_23 ;
}
static inline int F_153 ( void ) { return 0 ; }
static T_5 void
F_156 ( struct V_46 * V_47 )
{
struct V_33 * V_34 ;
int V_23 ;
F_3 (file, &tr->events, list) {
V_23 = F_111 ( V_47 -> V_152 , V_34 ,
& V_156 ,
& V_158 ,
& V_159 ,
& V_160 ) ;
if ( V_23 < 0 )
F_108 ( L_29 ,
V_34 -> V_3 -> V_9 ) ;
}
}
static T_5 void
F_157 ( struct V_46 * V_47 )
{
struct V_2 * V_11 ;
int V_23 ;
F_3 (call, &ftrace_events, list) {
if ( F_39 ( V_11 -> V_150 ) )
continue;
V_23 = F_124 ( V_11 , V_47 ) ;
if ( V_23 < 0 )
F_108 ( L_34 ,
V_11 -> V_9 ) ;
}
}
static void
F_158 ( struct V_46 * V_47 )
{
struct V_33 * V_34 , * V_27 ;
F_15 (file, next, &tr->events, list) {
F_16 ( & V_34 -> V_69 ) ;
F_113 ( V_34 -> V_72 ) ;
F_112 ( V_34 -> system ) ;
F_9 ( V_145 , V_34 ) ;
}
}
static void
F_126 ( struct V_2 * V_11 ,
struct V_154 * V_155 )
{
struct V_46 * V_47 ;
F_3 (tr, &ftrace_trace_arrays, list) {
if ( V_155 )
F_139 ( V_11 , V_47 , V_155 ) ;
else
F_123 ( V_11 , V_47 ,
& V_156 ,
& V_158 ,
& V_159 ,
& V_160 ) ;
}
}
static T_5 int F_159 ( char * V_199 )
{
F_160 ( V_200 , V_199 , V_201 ) ;
V_202 = true ;
V_203 = true ;
return 1 ;
}
static int
F_161 ( struct V_134 * V_135 , struct V_46 * V_47 )
{
struct V_134 * V_143 ;
struct V_134 * V_136 ;
V_136 = F_109 ( L_35 , 0644 , V_135 ,
V_47 , & V_204 ) ;
if ( ! V_136 ) {
F_108 ( L_36 ) ;
return - V_22 ;
}
V_143 = F_107 ( L_37 , V_135 ) ;
if ( ! V_143 ) {
F_108 ( L_38 ) ;
return - V_22 ;
}
F_110 ( L_39 , 0444 , V_143 ,
V_205 ,
& V_206 ) ;
F_110 ( L_40 , 0444 , V_143 ,
V_207 ,
& V_206 ) ;
F_110 ( L_21 , 0644 , V_143 ,
V_47 , & V_208 ) ;
V_47 -> V_152 = V_143 ;
return 0 ;
}
int F_162 ( struct V_134 * V_135 , struct V_46 * V_47 )
{
int V_23 ;
F_24 ( & V_48 ) ;
V_23 = F_161 ( V_135 , V_47 ) ;
if ( V_23 )
goto V_209;
F_130 ( & V_153 ) ;
F_140 ( V_47 ) ;
F_131 ( & V_153 ) ;
V_209:
F_31 ( & V_48 ) ;
return V_23 ;
}
static T_5 int
F_163 ( struct V_134 * V_135 , struct V_46 * V_47 )
{
int V_23 ;
F_24 ( & V_48 ) ;
V_23 = F_161 ( V_135 , V_47 ) ;
if ( V_23 )
goto V_209;
F_130 ( & V_153 ) ;
F_156 ( V_47 ) ;
F_131 ( & V_153 ) ;
V_209:
F_31 ( & V_48 ) ;
return V_23 ;
}
int F_164 ( struct V_46 * V_47 )
{
F_45 ( V_47 , NULL , NULL , NULL , 0 ) ;
F_24 ( & V_48 ) ;
F_130 ( & V_153 ) ;
F_158 ( V_47 ) ;
F_113 ( V_47 -> V_152 ) ;
F_131 ( & V_153 ) ;
V_47 -> V_152 = NULL ;
F_31 ( & V_48 ) ;
return 0 ;
}
static T_5 int F_165 ( void )
{
V_17 = F_166 ( V_7 , V_210 ) ;
V_145 = F_166 ( V_33 , V_210 ) ;
return 0 ;
}
static T_5 int F_167 ( void )
{
struct V_46 * V_47 = F_49 () ;
struct V_2 * * V_211 , * V_11 ;
char * V_79 = V_200 ;
char * V_212 ;
int V_23 ;
F_135 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_11 = * V_211 ;
V_23 = F_118 ( V_11 ) ;
if ( ! V_23 )
F_8 ( & V_11 -> V_69 , & V_151 ) ;
}
F_157 ( V_47 ) ;
while ( true ) {
V_212 = F_47 ( & V_79 , L_41 ) ;
if ( ! V_212 )
break;
if ( ! * V_212 )
continue;
V_23 = F_46 ( V_47 , V_212 , 1 ) ;
if ( V_23 )
F_119 ( L_42 , V_212 ) ;
}
F_168 () ;
F_153 () ;
return 0 ;
}
static T_5 int F_169 ( void )
{
struct V_46 * V_47 ;
struct V_134 * V_213 ;
struct V_134 * V_136 ;
int V_23 ;
V_47 = F_49 () ;
V_213 = F_170 () ;
if ( ! V_213 )
return 0 ;
V_136 = F_109 ( L_43 , 0444 , V_213 ,
V_47 , & V_214 ) ;
if ( ! V_136 )
F_108 ( L_44
L_45 ) ;
if ( F_12 () )
F_108 ( L_46 ) ;
V_23 = F_163 ( V_213 , V_47 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_171 ( & V_215 ) ;
if ( V_23 )
F_108 ( L_47 ) ;
return 0 ;
}
static T_5 void F_172 ( struct V_216 * V_217 )
{
F_173 ( & V_218 ) ;
F_174 ( & V_219 ) ;
F_175 ( 1 ) ;
F_176 ( & V_219 ) ;
F_177 ( & V_218 ) ;
F_24 ( & V_220 ) ;
F_178 ( 1 ) ;
F_31 ( & V_220 ) ;
}
static T_5 int F_179 ( void * V_221 )
{
void * V_222 ;
V_222 = F_81 ( 1234 , V_117 ) ;
if ( ! V_222 )
F_35 ( L_48 ) ;
F_180 ( F_172 ) ;
F_40 ( V_222 ) ;
F_181 ( V_223 ) ;
while ( ! F_182 () )
F_183 () ;
return 0 ;
}
static T_5 void F_184 ( void )
{
struct V_224 * V_225 ;
V_225 = F_185 ( F_179 , NULL , L_49 ) ;
F_178 ( 1 ) ;
F_186 ( V_225 ) ;
}
static T_5 void F_187 ( void )
{
struct V_71 * V_72 ;
struct V_33 * V_34 ;
struct V_2 * V_11 ;
struct V_65 * system ;
struct V_46 * V_47 ;
int V_23 ;
V_47 = F_49 () ;
F_35 ( L_50 ) ;
F_3 (file, &tr->events, list) {
V_11 = V_34 -> V_3 ;
if ( ! V_11 -> V_4 || ! V_11 -> V_4 -> V_36 )
continue;
#ifndef F_188
if ( V_11 -> V_4 -> system &&
strcmp ( V_11 -> V_4 -> system , L_51 ) == 0 )
continue;
#endif
F_35 ( L_52 , V_11 -> V_9 ) ;
if ( V_34 -> V_49 & V_50 ) {
F_108 ( L_53 ) ;
F_39 ( 1 ) ;
continue;
}
F_36 ( V_34 , 1 ) ;
F_184 () ;
F_36 ( V_34 , 0 ) ;
F_189 ( L_54 ) ;
}
F_35 ( L_55 ) ;
F_3 (dir, &tr->systems, list) {
system = V_72 -> V_73 ;
if ( strcmp ( system -> V_9 , L_56 ) == 0 )
continue;
F_35 ( L_57 , system -> V_9 ) ;
V_23 = F_45 ( V_47 , NULL , system -> V_9 , NULL , 1 ) ;
if ( F_39 ( V_23 ) ) {
F_108 ( L_58 ,
system -> V_9 ) ;
continue;
}
F_184 () ;
V_23 = F_45 ( V_47 , NULL , system -> V_9 , NULL , 0 ) ;
if ( F_39 ( V_23 ) ) {
F_108 ( L_59 ,
system -> V_9 ) ;
continue;
}
F_189 ( L_54 ) ;
}
F_35 ( L_60 ) ;
F_35 ( L_61 ) ;
V_23 = F_45 ( V_47 , NULL , NULL , NULL , 1 ) ;
if ( F_39 ( V_23 ) ) {
F_108 ( L_62 ) ;
return;
}
F_184 () ;
V_23 = F_45 ( V_47 , NULL , NULL , NULL , 0 ) ;
if ( F_39 ( V_23 ) ) {
F_108 ( L_63 ) ;
return;
}
F_189 ( L_54 ) ;
}
static void
F_190 ( unsigned long V_171 , unsigned long V_172 ,
struct V_226 * V_227 , struct V_228 * V_228 )
{
struct V_229 * V_29 ;
struct V_230 * V_91 ;
struct V_231 * V_136 ;
unsigned long V_49 ;
long V_232 ;
int V_233 ;
int V_234 ;
V_234 = F_191 () ;
F_192 () ;
V_233 = F_193 () ;
V_232 = F_34 ( & F_194 ( V_235 , V_233 ) ) ;
if ( V_232 != 1 )
goto V_103;
F_195 ( V_49 ) ;
V_29 = F_196 ( & V_91 ,
V_236 , sizeof( * V_136 ) ,
V_49 , V_234 ) ;
if ( ! V_29 )
goto V_103;
V_136 = F_197 ( V_29 ) ;
V_136 -> V_171 = V_171 ;
V_136 -> V_172 = V_172 ;
F_198 ( V_91 , V_29 , V_49 , V_234 ) ;
V_103:
F_199 ( & F_194 ( V_235 , V_233 ) ) ;
F_200 () ;
}
static T_5 void F_201 ( void )
{
int V_23 ;
V_23 = F_202 ( & V_237 ) ;
if ( F_11 ( V_23 < 0 ) ) {
F_35 ( L_64 ) ;
return;
}
F_35 ( L_65 ) ;
F_187 () ;
F_203 ( & V_237 ) ;
}
static T_5 void F_201 ( void )
{
}
static T_5 int F_204 ( void )
{
if ( ! V_203 ) {
F_187 () ;
F_201 () ;
}
return 0 ;
}
