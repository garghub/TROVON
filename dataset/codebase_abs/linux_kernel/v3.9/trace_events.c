struct V_1 *
F_1 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_4 -> V_5 )
return & V_3 -> V_4 -> V_6 ;
return V_3 -> V_4 -> V_5 ( V_3 ) ;
}
static int F_2 ( struct V_1 * V_7 , const char * type ,
const char * V_8 , int V_9 , int V_10 ,
int V_11 , int V_12 )
{
struct V_13 * V_14 ;
V_14 = F_3 ( sizeof( * V_14 ) , V_15 ) ;
if ( ! V_14 )
goto V_16;
V_14 -> V_8 = F_4 ( V_8 , V_15 ) ;
if ( ! V_14 -> V_8 )
goto V_16;
V_14 -> type = F_4 ( type , V_15 ) ;
if ( ! V_14 -> type )
goto V_16;
if ( V_12 == V_17 )
V_14 -> V_12 = F_5 ( type ) ;
else
V_14 -> V_12 = V_12 ;
V_14 -> V_9 = V_9 ;
V_14 -> V_10 = V_10 ;
V_14 -> V_11 = V_11 ;
F_6 ( & V_14 -> V_18 , V_7 ) ;
return 0 ;
V_16:
if ( V_14 )
F_7 ( V_14 -> V_8 ) ;
F_7 ( V_14 ) ;
return - V_19 ;
}
int F_8 ( struct V_2 * V_20 , const char * type ,
const char * V_8 , int V_9 , int V_10 , int V_11 ,
int V_12 )
{
struct V_1 * V_7 ;
if ( F_9 ( ! V_20 -> V_4 ) )
return 0 ;
V_7 = F_1 ( V_20 ) ;
return F_2 ( V_7 , type , V_8 , V_9 , V_10 ,
V_11 , V_12 ) ;
}
static int F_10 ( void )
{
int V_21 ;
struct V_22 V_23 ;
F_11 (unsigned short, type) ;
F_11 (unsigned char, flags) ;
F_11 (unsigned char, preempt_count) ;
F_11 ( int , V_24 ) ;
return V_21 ;
}
void F_12 ( struct V_2 * V_20 )
{
struct V_13 * V_14 , * V_25 ;
struct V_1 * V_7 ;
V_7 = F_1 ( V_20 ) ;
F_13 (field, next, head, link) {
F_14 ( & V_14 -> V_18 ) ;
F_7 ( V_14 -> type ) ;
F_7 ( V_14 -> V_8 ) ;
F_7 ( V_14 ) ;
}
}
int F_15 ( struct V_2 * V_20 )
{
int V_26 ;
V_26 = F_16 ( & V_20 -> V_27 ) ;
if ( ! V_26 )
return - V_28 ;
return 0 ;
}
int F_17 ( struct V_2 * V_20 ,
enum V_29 type , void * V_30 )
{
switch ( type ) {
case V_31 :
return F_18 ( V_20 -> V_8 ,
V_20 -> V_4 -> V_32 ,
V_20 ) ;
case V_33 :
F_19 ( V_20 -> V_8 ,
V_20 -> V_4 -> V_32 ,
V_20 ) ;
return 0 ;
#ifdef F_20
case V_34 :
return F_18 ( V_20 -> V_8 ,
V_20 -> V_4 -> V_35 ,
V_20 ) ;
case V_36 :
F_19 ( V_20 -> V_8 ,
V_20 -> V_4 -> V_35 ,
V_20 ) ;
return 0 ;
case V_37 :
case V_38 :
case V_39 :
case V_40 :
return 0 ;
#endif
}
return 0 ;
}
void F_21 ( bool V_41 )
{
struct V_2 * V_20 ;
F_22 ( & V_42 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! ( V_20 -> V_43 & V_44 ) )
continue;
if ( V_41 ) {
F_24 () ;
V_20 -> V_43 |= V_45 ;
} else {
F_25 () ;
V_20 -> V_43 &= ~ V_45 ;
}
}
F_26 ( & V_42 ) ;
}
static int F_27 ( struct V_2 * V_20 ,
int V_41 )
{
int V_21 = 0 ;
switch ( V_41 ) {
case 0 :
if ( V_20 -> V_43 & V_44 ) {
V_20 -> V_43 &= ~ V_44 ;
if ( V_20 -> V_43 & V_45 ) {
F_25 () ;
V_20 -> V_43 &= ~ V_45 ;
}
V_20 -> V_4 -> V_46 ( V_20 , V_33 , NULL ) ;
}
break;
case 1 :
if ( ! ( V_20 -> V_43 & V_44 ) ) {
if ( V_47 & V_48 ) {
F_24 () ;
V_20 -> V_43 |= V_45 ;
}
V_21 = V_20 -> V_4 -> V_46 ( V_20 , V_31 , NULL ) ;
if ( V_21 ) {
F_25 () ;
F_28 ( L_1
L_2 , V_20 -> V_8 ) ;
break;
}
V_20 -> V_43 |= V_44 ;
}
break;
}
return V_21 ;
}
static void F_29 ( void )
{
struct V_2 * V_20 ;
F_22 ( & V_42 ) ;
F_23 (call, &ftrace_events, list) {
F_27 ( V_20 , 0 ) ;
}
F_26 ( & V_42 ) ;
}
static void F_30 ( struct V_49 * system )
{
struct V_50 * V_51 = system -> V_51 ;
F_31 ( system -> V_52 == 0 ) ;
if ( -- system -> V_52 )
return;
if ( V_51 ) {
F_7 ( V_51 -> V_53 ) ;
F_7 ( V_51 ) ;
}
F_7 ( system -> V_8 ) ;
F_7 ( system ) ;
}
static void F_32 ( struct V_49 * system )
{
F_31 ( system -> V_52 == 0 ) ;
system -> V_52 ++ ;
}
static void F_33 ( struct V_49 * system )
{
F_22 ( & V_42 ) ;
F_30 ( system ) ;
F_26 ( & V_42 ) ;
}
static int F_34 ( const char * V_54 , const char * V_55 ,
const char * V_27 , int V_56 )
{
struct V_2 * V_20 ;
int V_21 = - V_57 ;
F_22 ( & V_42 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_8 || ! V_20 -> V_4 || ! V_20 -> V_4 -> V_46 )
continue;
if ( V_20 -> V_43 & V_58 )
continue;
if ( V_54 &&
strcmp ( V_54 , V_20 -> V_8 ) != 0 &&
strcmp ( V_54 , V_20 -> V_4 -> system ) != 0 )
continue;
if ( V_55 && strcmp ( V_55 , V_20 -> V_4 -> system ) != 0 )
continue;
if ( V_27 && strcmp ( V_27 , V_20 -> V_8 ) != 0 )
continue;
F_27 ( V_20 , V_56 ) ;
V_21 = 0 ;
}
F_26 ( & V_42 ) ;
return V_21 ;
}
static int F_35 ( char * V_59 , int V_56 )
{
char * V_27 = NULL , * V_55 = NULL , * V_54 ;
V_54 = F_36 ( & V_59 , L_3 ) ;
if ( V_59 ) {
V_55 = V_54 ;
V_27 = V_59 ;
V_54 = NULL ;
if ( ! strlen ( V_55 ) || strcmp ( V_55 , L_4 ) == 0 )
V_55 = NULL ;
if ( ! strlen ( V_27 ) || strcmp ( V_27 , L_4 ) == 0 )
V_27 = NULL ;
}
return F_34 ( V_54 , V_55 , V_27 , V_56 ) ;
}
int F_37 ( const char * system , const char * V_27 , int V_56 )
{
return F_34 ( NULL , system , V_27 , V_56 ) ;
}
static T_1
F_38 ( struct V_60 * V_60 , const char T_2 * V_61 ,
T_3 V_62 , T_4 * V_63 )
{
struct V_64 V_65 ;
T_1 V_66 , V_21 ;
if ( ! V_62 )
return 0 ;
V_21 = F_39 () ;
if ( V_21 < 0 )
return V_21 ;
if ( F_40 ( & V_65 , V_67 + 1 ) )
return - V_19 ;
V_66 = F_41 ( & V_65 , V_61 , V_62 , V_63 ) ;
if ( V_66 >= 0 && F_42 ( ( & V_65 ) ) ) {
int V_56 = 1 ;
if ( * V_65 . V_68 == '!' )
V_56 = 0 ;
V_65 . V_68 [ V_65 . V_69 ] = 0 ;
V_21 = F_35 ( V_65 . V_68 + ! V_56 , V_56 ) ;
if ( V_21 )
goto V_70;
}
V_21 = V_66 ;
V_70:
F_43 ( & V_65 ) ;
return V_21 ;
}
static void *
F_44 ( struct V_71 * V_72 , void * V_73 , T_4 * V_74 )
{
struct V_2 * V_20 = V_73 ;
( * V_74 ) ++ ;
F_45 (call, &ftrace_events, list) {
if ( V_20 -> V_4 && V_20 -> V_4 -> V_46 )
return V_20 ;
}
return NULL ;
}
static void * F_46 ( struct V_71 * V_72 , T_4 * V_74 )
{
struct V_2 * V_20 ;
T_4 V_75 ;
F_22 ( & V_42 ) ;
V_20 = F_47 ( & V_76 , struct V_2 , V_77 ) ;
for ( V_75 = 0 ; V_75 <= * V_74 ; ) {
V_20 = F_44 ( V_72 , V_20 , & V_75 ) ;
if ( ! V_20 )
break;
}
return V_20 ;
}
static void *
F_48 ( struct V_71 * V_72 , void * V_73 , T_4 * V_74 )
{
struct V_2 * V_20 = V_73 ;
( * V_74 ) ++ ;
F_45 (call, &ftrace_events, list) {
if ( V_20 -> V_43 & V_44 )
return V_20 ;
}
return NULL ;
}
static void * F_49 ( struct V_71 * V_72 , T_4 * V_74 )
{
struct V_2 * V_20 ;
T_4 V_75 ;
F_22 ( & V_42 ) ;
V_20 = F_47 ( & V_76 , struct V_2 , V_77 ) ;
for ( V_75 = 0 ; V_75 <= * V_74 ; ) {
V_20 = F_48 ( V_72 , V_20 , & V_75 ) ;
if ( ! V_20 )
break;
}
return V_20 ;
}
static int F_50 ( struct V_71 * V_72 , void * V_73 )
{
struct V_2 * V_20 = V_73 ;
if ( strcmp ( V_20 -> V_4 -> system , V_78 ) != 0 )
F_51 ( V_72 , L_5 , V_20 -> V_4 -> system ) ;
F_51 ( V_72 , L_2 , V_20 -> V_8 ) ;
return 0 ;
}
static void F_52 ( struct V_71 * V_72 , void * V_79 )
{
F_26 ( & V_42 ) ;
}
static T_1
F_53 ( struct V_60 * V_80 , char T_2 * V_61 , T_3 V_62 ,
T_4 * V_63 )
{
struct V_2 * V_20 = V_80 -> V_81 ;
char * V_59 ;
if ( V_20 -> V_43 & V_44 )
V_59 = L_6 ;
else
V_59 = L_7 ;
return F_54 ( V_61 , V_62 , V_63 , V_59 , 2 ) ;
}
static T_1
F_55 ( struct V_60 * V_80 , const char T_2 * V_61 , T_3 V_62 ,
T_4 * V_63 )
{
struct V_2 * V_20 = V_80 -> V_81 ;
unsigned long V_82 ;
int V_21 ;
V_21 = F_56 ( V_61 , V_62 , 10 , & V_82 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_39 () ;
if ( V_21 < 0 )
return V_21 ;
switch ( V_82 ) {
case 0 :
case 1 :
F_22 ( & V_42 ) ;
V_21 = F_27 ( V_20 , V_82 ) ;
F_26 ( & V_42 ) ;
break;
default:
return - V_57 ;
}
* V_63 += V_62 ;
return V_21 ? V_21 : V_62 ;
}
static T_1
F_57 ( struct V_60 * V_80 , char T_2 * V_61 , T_3 V_62 ,
T_4 * V_63 )
{
const char V_83 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_49 * system = V_80 -> V_81 ;
struct V_2 * V_20 ;
char V_59 [ 2 ] ;
int V_56 = 0 ;
int V_21 ;
F_22 ( & V_42 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_8 || ! V_20 -> V_4 || ! V_20 -> V_4 -> V_46 )
continue;
if ( system && strcmp ( V_20 -> V_4 -> system , system -> V_8 ) != 0 )
continue;
V_56 |= ( 1 << ! ! ( V_20 -> V_43 & V_44 ) ) ;
if ( V_56 == 3 )
break;
}
F_26 ( & V_42 ) ;
V_59 [ 0 ] = V_83 [ V_56 ] ;
V_59 [ 1 ] = '\n' ;
V_21 = F_54 ( V_61 , V_62 , V_63 , V_59 , 2 ) ;
return V_21 ;
}
static T_1
F_58 ( struct V_60 * V_80 , const char T_2 * V_61 , T_3 V_62 ,
T_4 * V_63 )
{
struct V_49 * system = V_80 -> V_81 ;
const char * V_8 = NULL ;
unsigned long V_82 ;
T_1 V_21 ;
V_21 = F_56 ( V_61 , V_62 , 10 , & V_82 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_39 () ;
if ( V_21 < 0 )
return V_21 ;
if ( V_82 != 0 && V_82 != 1 )
return - V_57 ;
if ( system )
V_8 = system -> V_8 ;
V_21 = F_34 ( NULL , V_8 , NULL , V_82 ) ;
if ( V_21 )
goto V_84;
V_21 = V_62 ;
V_84:
* V_63 += V_62 ;
return V_21 ;
}
static void * F_59 ( struct V_71 * V_72 , void * V_73 , T_4 * V_74 )
{
struct V_2 * V_20 = V_72 -> V_85 ;
struct V_13 * V_14 ;
struct V_1 * V_86 = & V_87 ;
struct V_1 * V_7 = F_1 ( V_20 ) ;
( * V_74 ) ++ ;
switch ( ( unsigned long ) V_73 ) {
case V_88 :
if ( F_60 ( F_61 ( V_86 ) ) )
return NULL ;
V_14 = F_47 ( V_86 -> V_89 ,
struct V_13 , V_18 ) ;
return V_14 ;
case V_90 :
if ( F_60 ( F_61 ( V_7 ) ) )
return NULL ;
V_14 = F_47 ( V_7 -> V_89 , struct V_13 , V_18 ) ;
return V_14 ;
case V_91 :
return NULL ;
}
V_14 = V_73 ;
if ( V_14 -> V_18 . V_89 == V_86 )
return ( void * ) V_90 ;
else if ( V_14 -> V_18 . V_89 == V_7 )
return ( void * ) V_91 ;
V_14 = F_47 ( V_14 -> V_18 . V_89 , struct V_13 , V_18 ) ;
return V_14 ;
}
static void * F_62 ( struct V_71 * V_72 , T_4 * V_74 )
{
T_4 V_75 = 0 ;
void * V_79 ;
if ( ! * V_74 )
return ( void * ) V_88 ;
V_79 = ( void * ) V_88 ;
do {
V_79 = F_59 ( V_72 , V_79 , & V_75 ) ;
} while ( V_79 && V_75 < * V_74 );
return V_79 ;
}
static int F_63 ( struct V_71 * V_72 , void * V_73 )
{
struct V_2 * V_20 = V_72 -> V_85 ;
struct V_13 * V_14 ;
const char * V_92 ;
switch ( ( unsigned long ) V_73 ) {
case V_88 :
F_51 ( V_72 , L_8 , V_20 -> V_8 ) ;
F_51 ( V_72 , L_9 , V_20 -> V_27 . type ) ;
F_51 ( V_72 , L_10 ) ;
return 0 ;
case V_90 :
F_64 ( V_72 , '\n' ) ;
return 0 ;
case V_91 :
F_51 ( V_72 , L_11 ,
V_20 -> V_93 ) ;
return 0 ;
}
V_14 = V_73 ;
V_92 = strchr ( V_14 -> type , '[' ) ;
if ( ! strncmp ( V_14 -> type , L_12 , 10 ) )
V_92 = NULL ;
if ( ! V_92 )
F_51 ( V_72 , L_13 ,
V_14 -> type , V_14 -> V_8 , V_14 -> V_9 ,
V_14 -> V_10 , ! ! V_14 -> V_11 ) ;
else
F_51 ( V_72 , L_14 ,
( int ) ( V_92 - V_14 -> type ) ,
V_14 -> type , V_14 -> V_8 ,
V_92 , V_14 -> V_9 ,
V_14 -> V_10 , ! ! V_14 -> V_11 ) ;
return 0 ;
}
static void F_65 ( struct V_71 * V_72 , void * V_79 )
{
}
static int F_66 ( struct V_94 * V_94 , struct V_60 * V_60 )
{
struct V_2 * V_20 = V_94 -> V_95 ;
struct V_71 * V_72 ;
int V_21 ;
V_21 = F_67 ( V_60 , & V_96 ) ;
if ( V_21 < 0 )
return V_21 ;
V_72 = V_60 -> V_81 ;
V_72 -> V_85 = V_20 ;
return 0 ;
}
static T_1
F_68 ( struct V_60 * V_80 , char T_2 * V_61 , T_3 V_62 , T_4 * V_63 )
{
struct V_2 * V_20 = V_80 -> V_81 ;
struct V_97 * V_98 ;
int V_99 ;
if ( * V_63 )
return 0 ;
V_98 = F_69 ( sizeof( * V_98 ) , V_15 ) ;
if ( ! V_98 )
return - V_19 ;
F_70 ( V_98 ) ;
F_71 ( V_98 , L_15 , V_20 -> V_27 . type ) ;
V_99 = F_54 ( V_61 , V_62 , V_63 ,
V_98 -> V_68 , V_98 -> V_100 ) ;
F_7 ( V_98 ) ;
return V_99 ;
}
static T_1
F_72 ( struct V_60 * V_80 , char T_2 * V_61 , T_3 V_62 ,
T_4 * V_63 )
{
struct V_2 * V_20 = V_80 -> V_81 ;
struct V_97 * V_98 ;
int V_99 ;
if ( * V_63 )
return 0 ;
V_98 = F_69 ( sizeof( * V_98 ) , V_15 ) ;
if ( ! V_98 )
return - V_19 ;
F_70 ( V_98 ) ;
F_73 ( V_20 , V_98 ) ;
V_99 = F_54 ( V_61 , V_62 , V_63 , V_98 -> V_68 , V_98 -> V_100 ) ;
F_7 ( V_98 ) ;
return V_99 ;
}
static T_1
F_74 ( struct V_60 * V_80 , const char T_2 * V_61 , T_3 V_62 ,
T_4 * V_63 )
{
struct V_2 * V_20 = V_80 -> V_81 ;
char * V_59 ;
int V_16 ;
if ( V_62 >= V_101 )
return - V_57 ;
V_59 = ( char * ) F_75 ( V_102 ) ;
if ( ! V_59 )
return - V_19 ;
if ( F_76 ( V_59 , V_61 , V_62 ) ) {
F_77 ( ( unsigned long ) V_59 ) ;
return - V_103 ;
}
V_59 [ V_62 ] = '\0' ;
V_16 = F_78 ( V_20 , V_59 ) ;
F_77 ( ( unsigned long ) V_59 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_63 += V_62 ;
return V_62 ;
}
static int F_79 ( struct V_94 * V_94 , struct V_60 * V_80 )
{
struct V_49 * system = NULL ;
int V_21 ;
if ( ! V_94 -> V_95 )
goto V_104;
F_22 ( & V_42 ) ;
F_23 (system, &event_subsystems, list) {
if ( system == V_94 -> V_95 ) {
if ( ! system -> V_105 ) {
system = NULL ;
break;
}
F_32 ( system ) ;
break;
}
}
F_26 ( & V_42 ) ;
if ( system != V_94 -> V_95 )
return - V_28 ;
V_104:
V_21 = F_80 ( V_94 , V_80 ) ;
if ( V_21 < 0 && system )
F_33 ( system ) ;
return V_21 ;
}
static int F_81 ( struct V_94 * V_94 , struct V_60 * V_60 )
{
struct V_49 * system = V_94 -> V_95 ;
if ( system )
F_33 ( system ) ;
return 0 ;
}
static T_1
F_82 ( struct V_60 * V_80 , char T_2 * V_61 , T_3 V_62 ,
T_4 * V_63 )
{
struct V_49 * system = V_80 -> V_81 ;
struct V_97 * V_98 ;
int V_99 ;
if ( * V_63 )
return 0 ;
V_98 = F_69 ( sizeof( * V_98 ) , V_15 ) ;
if ( ! V_98 )
return - V_19 ;
F_70 ( V_98 ) ;
F_83 ( system , V_98 ) ;
V_99 = F_54 ( V_61 , V_62 , V_63 , V_98 -> V_68 , V_98 -> V_100 ) ;
F_7 ( V_98 ) ;
return V_99 ;
}
static T_1
F_84 ( struct V_60 * V_80 , const char T_2 * V_61 , T_3 V_62 ,
T_4 * V_63 )
{
struct V_49 * system = V_80 -> V_81 ;
char * V_59 ;
int V_16 ;
if ( V_62 >= V_101 )
return - V_57 ;
V_59 = ( char * ) F_75 ( V_102 ) ;
if ( ! V_59 )
return - V_19 ;
if ( F_76 ( V_59 , V_61 , V_62 ) ) {
F_77 ( ( unsigned long ) V_59 ) ;
return - V_103 ;
}
V_59 [ V_62 ] = '\0' ;
V_16 = F_85 ( system , V_59 ) ;
F_77 ( ( unsigned long ) V_59 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_63 += V_62 ;
return V_62 ;
}
static T_1
F_86 ( struct V_60 * V_80 , char T_2 * V_61 , T_3 V_62 , T_4 * V_63 )
{
int (* F_87)( struct V_97 * V_98 ) = V_80 -> V_81 ;
struct V_97 * V_98 ;
int V_99 ;
if ( * V_63 )
return 0 ;
V_98 = F_69 ( sizeof( * V_98 ) , V_15 ) ;
if ( ! V_98 )
return - V_19 ;
F_70 ( V_98 ) ;
F_87 ( V_98 ) ;
V_99 = F_54 ( V_61 , V_62 , V_63 , V_98 -> V_68 , V_98 -> V_100 ) ;
F_7 ( V_98 ) ;
return V_99 ;
}
static struct V_106 * F_88 ( void )
{
static struct V_106 * V_107 ;
static struct V_106 * V_108 ;
if ( V_108 )
return V_108 ;
V_107 = F_89 () ;
if ( ! V_107 )
return NULL ;
V_108 = F_90 ( L_16 , V_107 ) ;
if ( ! V_108 )
F_91 ( L_17
L_18 ) ;
return V_108 ;
}
static int
F_92 ( struct V_94 * V_94 , struct V_60 * V_60 )
{
const struct V_109 * V_110 = & V_111 ;
return F_67 ( V_60 , V_110 ) ;
}
static int
F_93 ( struct V_94 * V_94 , struct V_60 * V_60 )
{
const struct V_109 * V_110 = & V_112 ;
if ( ( V_60 -> V_113 & V_114 ) &&
( V_60 -> V_115 & V_116 ) )
F_29 () ;
return F_67 ( V_60 , V_110 ) ;
}
static struct V_106 *
F_94 ( const char * V_8 , struct V_106 * V_108 )
{
struct V_49 * system ;
struct V_106 * V_117 ;
F_23 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_8 , V_8 ) == 0 ) {
system -> V_105 ++ ;
return system -> V_117 ;
}
}
system = F_69 ( sizeof( * system ) , V_15 ) ;
if ( ! system ) {
F_91 ( L_19 ,
V_8 ) ;
return V_108 ;
}
system -> V_117 = F_90 ( V_8 , V_108 ) ;
if ( ! system -> V_117 ) {
F_91 ( L_20 ,
V_8 ) ;
F_7 ( system ) ;
return V_108 ;
}
system -> V_105 = 1 ;
system -> V_52 = 1 ;
system -> V_8 = F_4 ( V_8 , V_15 ) ;
if ( ! system -> V_8 ) {
F_95 ( system -> V_117 ) ;
F_7 ( system ) ;
return V_108 ;
}
F_6 ( & system -> V_77 , & V_118 ) ;
system -> V_51 = NULL ;
system -> V_51 = F_3 ( sizeof( struct V_50 ) , V_15 ) ;
if ( ! system -> V_51 ) {
F_91 ( L_21
L_22 , V_8 ) ;
return system -> V_117 ;
}
V_117 = F_96 ( L_23 , 0644 , system -> V_117 , system ,
& V_119 ) ;
if ( ! V_117 ) {
F_7 ( system -> V_51 ) ;
system -> V_51 = NULL ;
F_91 ( L_17
L_24 , V_8 ) ;
}
F_97 ( L_25 , 0644 , system -> V_117 , system ,
& V_120 ) ;
return system -> V_117 ;
}
static int
F_98 ( struct V_2 * V_20 , struct V_106 * V_108 ,
const struct V_121 * V_26 ,
const struct V_121 * V_41 ,
const struct V_121 * V_51 ,
const struct V_121 * V_122 )
{
struct V_1 * V_7 ;
int V_21 ;
if ( strcmp ( V_20 -> V_4 -> system , V_78 ) != 0 )
V_108 = F_94 ( V_20 -> V_4 -> system , V_108 ) ;
V_20 -> V_123 = F_90 ( V_20 -> V_8 , V_108 ) ;
if ( ! V_20 -> V_123 ) {
F_91 ( L_17
L_26 , V_20 -> V_8 ) ;
return - 1 ;
}
if ( V_20 -> V_4 -> V_46 && ! ( V_20 -> V_43 & V_58 ) )
F_97 ( L_25 , 0644 , V_20 -> V_123 , V_20 ,
V_41 ) ;
#ifdef F_20
if ( V_20 -> V_27 . type && V_20 -> V_4 -> V_46 )
F_97 ( L_27 , 0444 , V_20 -> V_123 , V_20 ,
V_26 ) ;
#endif
V_7 = F_1 ( V_20 ) ;
if ( F_61 ( V_7 ) ) {
V_21 = V_20 -> V_4 -> V_124 ( V_20 ) ;
if ( V_21 < 0 ) {
F_91 ( L_28
L_29 , V_20 -> V_8 ) ;
return V_21 ;
}
}
F_97 ( L_23 , 0644 , V_20 -> V_123 , V_20 ,
V_51 ) ;
F_97 ( L_30 , 0444 , V_20 -> V_123 , V_20 ,
V_122 ) ;
return 0 ;
}
static void F_99 ( struct V_2 * V_20 )
{
F_27 ( V_20 , 0 ) ;
if ( V_20 -> V_27 . V_125 )
F_100 ( & V_20 -> V_27 ) ;
F_14 ( & V_20 -> V_77 ) ;
}
static int F_101 ( struct V_2 * V_20 )
{
int V_21 = 0 ;
if ( F_9 ( ! V_20 -> V_8 ) )
return - V_57 ;
if ( V_20 -> V_4 -> V_126 ) {
V_21 = V_20 -> V_4 -> V_126 ( V_20 ) ;
if ( V_21 < 0 && V_21 != - V_127 )
F_102 ( L_31 ,
V_20 -> V_8 ) ;
}
return V_21 ;
}
static int
F_103 ( struct V_2 * V_20 , struct V_128 * V_129 ,
const struct V_121 * V_26 ,
const struct V_121 * V_41 ,
const struct V_121 * V_51 ,
const struct V_121 * V_122 )
{
struct V_106 * V_108 ;
int V_21 ;
V_21 = F_101 ( V_20 ) ;
if ( V_21 < 0 )
return V_21 ;
V_108 = F_88 () ;
if ( ! V_108 )
return - V_130 ;
V_21 = F_98 ( V_20 , V_108 , V_26 , V_41 , V_51 , V_122 ) ;
if ( ! V_21 )
F_6 ( & V_20 -> V_77 , & V_76 ) ;
V_20 -> V_129 = V_129 ;
return V_21 ;
}
int F_104 ( struct V_2 * V_20 )
{
int V_21 ;
F_22 ( & V_42 ) ;
V_21 = F_103 ( V_20 , NULL , & V_131 ,
& V_132 ,
& V_133 ,
& V_134 ) ;
F_26 ( & V_42 ) ;
return V_21 ;
}
static void F_105 ( const char * V_8 )
{
struct V_49 * system ;
if ( strcmp ( V_8 , V_78 ) == 0 )
return;
F_23 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_8 , V_8 ) == 0 ) {
if ( ! -- system -> V_105 ) {
F_106 ( system -> V_117 ) ;
F_14 ( & system -> V_77 ) ;
F_30 ( system ) ;
}
break;
}
}
}
static void F_107 ( struct V_2 * V_20 )
{
F_99 ( V_20 ) ;
F_12 ( V_20 ) ;
F_108 ( V_20 ) ;
F_106 ( V_20 -> V_123 ) ;
F_105 ( V_20 -> V_4 -> system ) ;
}
void F_109 ( struct V_2 * V_20 )
{
F_22 ( & V_42 ) ;
F_110 ( & V_135 ) ;
F_107 ( V_20 ) ;
F_111 ( & V_135 ) ;
F_26 ( & V_42 ) ;
}
static struct V_136 *
F_112 ( struct V_128 * V_129 )
{
struct V_136 * V_137 ;
V_137 = F_69 ( sizeof( * V_137 ) , V_15 ) ;
if ( ! V_137 )
return NULL ;
V_137 -> V_129 = V_129 ;
V_137 -> V_26 = V_131 ;
V_137 -> V_26 . V_138 = V_129 ;
V_137 -> V_41 = V_132 ;
V_137 -> V_41 . V_138 = V_129 ;
V_137 -> V_51 = V_133 ;
V_137 -> V_51 . V_138 = V_129 ;
V_137 -> V_122 = V_134 ;
V_137 -> V_122 . V_138 = V_129 ;
F_6 ( & V_137 -> V_77 , & V_139 ) ;
return V_137 ;
}
static void F_113 ( struct V_128 * V_129 )
{
struct V_136 * V_137 = NULL ;
struct V_2 * * V_20 , * * V_140 , * * V_141 ;
V_140 = V_129 -> V_142 ;
V_141 = V_129 -> V_142 + V_129 -> V_143 ;
if ( V_140 == V_141 )
return;
V_137 = F_112 ( V_129 ) ;
if ( ! V_137 )
return;
F_114 (call, start, end) {
F_103 ( * V_20 , V_129 ,
& V_137 -> V_26 , & V_137 -> V_41 ,
& V_137 -> V_51 , & V_137 -> V_122 ) ;
}
}
static void F_115 ( struct V_128 * V_129 )
{
struct V_136 * V_137 ;
struct V_2 * V_20 , * V_79 ;
bool V_144 = false ;
F_110 ( & V_135 ) ;
F_13 (call, p, &ftrace_events, list) {
if ( V_20 -> V_129 == V_129 ) {
V_144 = true ;
F_107 ( V_20 ) ;
}
}
F_23 (file_ops, &ftrace_module_file_list, list) {
if ( V_137 -> V_129 == V_129 )
break;
}
if ( & V_137 -> V_77 != & V_139 ) {
F_14 ( & V_137 -> V_77 ) ;
F_7 ( V_137 ) ;
}
if ( V_144 )
F_116 () ;
F_111 ( & V_135 ) ;
}
static int F_117 ( struct V_145 * V_146 ,
unsigned long V_82 , void * V_30 )
{
struct V_128 * V_129 = V_30 ;
F_22 ( & V_42 ) ;
switch ( V_82 ) {
case V_147 :
F_113 ( V_129 ) ;
break;
case V_148 :
F_115 ( V_129 ) ;
break;
}
F_26 ( & V_42 ) ;
return 0 ;
}
static int F_117 ( struct V_145 * V_146 ,
unsigned long V_82 , void * V_30 )
{
return 0 ;
}
static T_5 int F_118 ( char * V_149 )
{
F_119 ( V_150 , V_149 , V_151 ) ;
V_152 = 1 ;
V_153 = 1 ;
return 1 ;
}
static T_5 int F_120 ( void )
{
struct V_2 * * V_154 , * V_20 ;
char * V_59 = V_150 ;
char * V_155 ;
int V_21 ;
F_114 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_20 = * V_154 ;
V_21 = F_101 ( V_20 ) ;
if ( ! V_21 )
F_6 ( & V_20 -> V_77 , & V_76 ) ;
}
while ( true ) {
V_155 = F_36 ( & V_59 , L_32 ) ;
if ( ! V_155 )
break;
if ( ! * V_155 )
continue;
V_21 = F_35 ( V_155 , 1 ) ;
if ( V_21 )
F_102 ( L_33 , V_155 ) ;
}
F_121 () ;
return 0 ;
}
static T_5 int F_122 ( void )
{
struct V_2 * V_20 ;
struct V_106 * V_107 ;
struct V_106 * V_117 ;
struct V_106 * V_108 ;
int V_21 ;
V_107 = F_89 () ;
if ( ! V_107 )
return 0 ;
V_117 = F_96 ( L_34 , 0444 , V_107 ,
NULL , & V_156 ) ;
if ( ! V_117 )
F_91 ( L_17
L_35 ) ;
V_117 = F_96 ( L_36 , 0644 , V_107 ,
NULL , & V_157 ) ;
if ( ! V_117 )
F_91 ( L_17
L_37 ) ;
V_108 = F_88 () ;
if ( ! V_108 )
return 0 ;
F_97 ( L_38 , 0444 , V_108 ,
V_158 ,
& V_159 ) ;
F_97 ( L_39 , 0444 , V_108 ,
V_160 ,
& V_159 ) ;
F_97 ( L_25 , 0644 , V_108 ,
NULL , & V_120 ) ;
if ( F_10 () )
F_91 ( L_40 ) ;
F_23 (call, &ftrace_events, list) {
V_21 = F_98 ( V_20 , V_108 ,
& V_131 ,
& V_132 ,
& V_133 ,
& V_134 ) ;
if ( V_21 < 0 )
F_99 ( V_20 ) ;
}
V_21 = F_123 ( & V_161 ) ;
if ( V_21 )
F_91 ( L_41 ) ;
return 0 ;
}
static T_5 void F_124 ( struct V_162 * V_163 )
{
F_125 ( & V_164 ) ;
F_126 ( & V_165 ) ;
F_127 ( 1 ) ;
F_128 ( & V_165 ) ;
F_129 ( & V_164 ) ;
F_22 ( & V_166 ) ;
F_130 ( 1 ) ;
F_26 ( & V_166 ) ;
}
static T_5 int F_131 ( void * V_167 )
{
void * V_168 ;
V_168 = F_69 ( 1234 , V_15 ) ;
if ( ! V_168 )
F_28 ( L_42 ) ;
F_132 ( F_124 ) ;
F_7 ( V_168 ) ;
F_133 ( V_169 ) ;
while ( ! F_134 () )
F_135 () ;
return 0 ;
}
static T_5 void F_136 ( void )
{
struct V_170 * V_171 ;
V_171 = F_137 ( F_131 , NULL , L_43 ) ;
F_130 ( 1 ) ;
F_138 ( V_171 ) ;
}
static T_5 void F_139 ( void )
{
struct V_2 * V_20 ;
struct V_49 * system ;
int V_21 ;
F_28 ( L_44 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_4 || ! V_20 -> V_4 -> V_32 )
continue;
#ifndef F_140
if ( V_20 -> V_4 -> system &&
strcmp ( V_20 -> V_4 -> system , L_45 ) == 0 )
continue;
#endif
F_28 ( L_46 , V_20 -> V_8 ) ;
if ( V_20 -> V_43 & V_44 ) {
F_91 ( L_47 ) ;
F_31 ( 1 ) ;
continue;
}
F_27 ( V_20 , 1 ) ;
F_136 () ;
F_27 ( V_20 , 0 ) ;
F_141 ( L_48 ) ;
}
F_28 ( L_49 ) ;
F_23 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_8 , L_50 ) == 0 )
continue;
F_28 ( L_51 , system -> V_8 ) ;
V_21 = F_34 ( NULL , system -> V_8 , NULL , 1 ) ;
if ( F_31 ( V_21 ) ) {
F_91 ( L_52 ,
system -> V_8 ) ;
continue;
}
F_136 () ;
V_21 = F_34 ( NULL , system -> V_8 , NULL , 0 ) ;
if ( F_31 ( V_21 ) ) {
F_91 ( L_53 ,
system -> V_8 ) ;
continue;
}
F_141 ( L_48 ) ;
}
F_28 ( L_54 ) ;
F_28 ( L_55 ) ;
V_21 = F_34 ( NULL , NULL , NULL , 1 ) ;
if ( F_31 ( V_21 ) ) {
F_91 ( L_56 ) ;
return;
}
F_136 () ;
V_21 = F_34 ( NULL , NULL , NULL , 0 ) ;
if ( F_31 ( V_21 ) ) {
F_91 ( L_57 ) ;
return;
}
F_141 ( L_48 ) ;
}
static void
F_142 ( unsigned long V_172 , unsigned long V_173 ,
struct V_174 * V_175 , struct V_176 * V_176 )
{
struct V_177 * V_27 ;
struct V_178 * V_68 ;
struct V_179 * V_117 ;
unsigned long V_43 ;
long V_180 ;
int V_181 ;
int V_182 ;
V_182 = F_143 () ;
F_144 () ;
V_181 = F_145 () ;
V_180 = F_146 ( & F_147 ( V_183 , V_181 ) ) ;
if ( V_180 != 1 )
goto V_84;
F_148 ( V_43 ) ;
V_27 = F_149 ( & V_68 ,
V_184 , sizeof( * V_117 ) ,
V_43 , V_182 ) ;
if ( ! V_27 )
goto V_84;
V_117 = F_150 ( V_27 ) ;
V_117 -> V_172 = V_172 ;
V_117 -> V_173 = V_173 ;
F_151 ( V_68 , V_27 , V_43 , V_182 ) ;
V_84:
F_152 ( & F_147 ( V_183 , V_181 ) ) ;
F_153 () ;
}
static T_5 void F_154 ( void )
{
int V_21 ;
V_21 = F_155 ( & V_185 ) ;
if ( F_9 ( V_21 < 0 ) ) {
F_28 ( L_58 ) ;
return;
}
F_28 ( L_59 ) ;
F_139 () ;
F_156 ( & V_185 ) ;
}
static T_5 void F_154 ( void )
{
}
static T_5 int F_157 ( void )
{
if ( ! V_153 ) {
F_139 () ;
F_154 () ;
}
return 0 ;
}
