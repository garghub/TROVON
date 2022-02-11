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
F_11 ( int , V_25 ) ;
return V_21 ;
}
void F_12 ( struct V_2 * V_20 )
{
struct V_13 * V_14 , * V_26 ;
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
int V_27 ;
V_27 = F_16 ( & V_20 -> V_28 ) ;
if ( ! V_27 )
return - V_29 ;
return 0 ;
}
int F_17 ( struct V_2 * V_20 ,
enum V_30 type , void * V_31 )
{
switch ( type ) {
case V_32 :
return F_18 ( V_20 -> V_8 ,
V_20 -> V_4 -> V_33 ,
V_20 ) ;
case V_34 :
F_19 ( V_20 -> V_8 ,
V_20 -> V_4 -> V_33 ,
V_20 ) ;
return 0 ;
#ifdef F_20
case V_35 :
return F_18 ( V_20 -> V_8 ,
V_20 -> V_4 -> V_36 ,
V_20 ) ;
case V_37 :
F_19 ( V_20 -> V_8 ,
V_20 -> V_4 -> V_36 ,
V_20 ) ;
return 0 ;
case V_38 :
case V_39 :
case V_40 :
case V_41 :
return 0 ;
#endif
}
return 0 ;
}
void F_21 ( bool V_42 )
{
struct V_2 * V_20 ;
F_22 ( & V_43 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! ( V_20 -> V_44 & V_45 ) )
continue;
if ( V_42 ) {
F_24 () ;
V_20 -> V_44 |= V_46 ;
} else {
F_25 () ;
V_20 -> V_44 &= ~ V_46 ;
}
}
F_26 ( & V_43 ) ;
}
static int F_27 ( struct V_2 * V_20 ,
int V_42 )
{
int V_21 = 0 ;
switch ( V_42 ) {
case 0 :
if ( V_20 -> V_44 & V_45 ) {
V_20 -> V_44 &= ~ V_45 ;
if ( V_20 -> V_44 & V_46 ) {
F_25 () ;
V_20 -> V_44 &= ~ V_46 ;
}
V_20 -> V_4 -> V_47 ( V_20 , V_34 , NULL ) ;
}
break;
case 1 :
if ( ! ( V_20 -> V_44 & V_45 ) ) {
if ( V_48 & V_49 ) {
F_24 () ;
V_20 -> V_44 |= V_46 ;
}
V_21 = V_20 -> V_4 -> V_47 ( V_20 , V_32 , NULL ) ;
if ( V_21 ) {
F_25 () ;
F_28 ( L_1
L_2 , V_20 -> V_8 ) ;
break;
}
V_20 -> V_44 |= V_45 ;
}
break;
}
return V_21 ;
}
static void F_29 ( void )
{
struct V_2 * V_20 ;
F_22 ( & V_43 ) ;
F_23 (call, &ftrace_events, list) {
F_27 ( V_20 , 0 ) ;
}
F_26 ( & V_43 ) ;
}
static void F_30 ( struct V_50 * system )
{
struct V_51 * V_52 = system -> V_52 ;
F_31 ( system -> V_53 == 0 ) ;
if ( -- system -> V_53 )
return;
if ( V_52 ) {
F_7 ( V_52 -> V_54 ) ;
F_7 ( V_52 ) ;
}
F_7 ( system -> V_8 ) ;
F_7 ( system ) ;
}
static void F_32 ( struct V_50 * system )
{
F_31 ( system -> V_53 == 0 ) ;
system -> V_53 ++ ;
}
static void F_33 ( struct V_50 * system )
{
F_22 ( & V_43 ) ;
F_30 ( system ) ;
F_26 ( & V_43 ) ;
}
static int F_34 ( const char * V_55 , const char * V_56 ,
const char * V_28 , int V_57 )
{
struct V_2 * V_20 ;
int V_21 = - V_58 ;
F_22 ( & V_43 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_8 || ! V_20 -> V_4 || ! V_20 -> V_4 -> V_47 )
continue;
if ( V_20 -> V_44 & V_59 )
continue;
if ( V_55 &&
strcmp ( V_55 , V_20 -> V_8 ) != 0 &&
strcmp ( V_55 , V_20 -> V_4 -> system ) != 0 )
continue;
if ( V_56 && strcmp ( V_56 , V_20 -> V_4 -> system ) != 0 )
continue;
if ( V_28 && strcmp ( V_28 , V_20 -> V_8 ) != 0 )
continue;
F_27 ( V_20 , V_57 ) ;
V_21 = 0 ;
}
F_26 ( & V_43 ) ;
return V_21 ;
}
static int F_35 ( char * V_60 , int V_57 )
{
char * V_28 = NULL , * V_56 = NULL , * V_55 ;
V_55 = F_36 ( & V_60 , L_3 ) ;
if ( V_60 ) {
V_56 = V_55 ;
V_28 = V_60 ;
V_55 = NULL ;
if ( ! strlen ( V_56 ) || strcmp ( V_56 , L_4 ) == 0 )
V_56 = NULL ;
if ( ! strlen ( V_28 ) || strcmp ( V_28 , L_4 ) == 0 )
V_28 = NULL ;
}
return F_34 ( V_55 , V_56 , V_28 , V_57 ) ;
}
int F_37 ( const char * system , const char * V_28 , int V_57 )
{
return F_34 ( NULL , system , V_28 , V_57 ) ;
}
static T_1
F_38 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_65 V_66 ;
T_1 V_67 , V_21 ;
if ( ! V_63 )
return 0 ;
V_21 = F_39 () ;
if ( V_21 < 0 )
return V_21 ;
if ( F_40 ( & V_66 , V_68 + 1 ) )
return - V_19 ;
V_67 = F_41 ( & V_66 , V_62 , V_63 , V_64 ) ;
if ( V_67 >= 0 && F_42 ( ( & V_66 ) ) ) {
int V_57 = 1 ;
if ( * V_66 . V_69 == '!' )
V_57 = 0 ;
V_66 . V_69 [ V_66 . V_70 ] = 0 ;
V_21 = F_35 ( V_66 . V_69 + ! V_57 , V_57 ) ;
if ( V_21 )
goto V_71;
}
V_21 = V_67 ;
V_71:
F_43 ( & V_66 ) ;
return V_21 ;
}
static void *
F_44 ( struct V_72 * V_73 , void * V_74 , T_4 * V_75 )
{
struct V_2 * V_20 = V_74 ;
( * V_75 ) ++ ;
F_45 (call, &ftrace_events, list) {
if ( V_20 -> V_4 && V_20 -> V_4 -> V_47 )
return V_20 ;
}
return NULL ;
}
static void * F_46 ( struct V_72 * V_73 , T_4 * V_75 )
{
struct V_2 * V_20 ;
T_4 V_76 ;
F_22 ( & V_43 ) ;
V_20 = F_47 ( & V_77 , struct V_2 , V_78 ) ;
for ( V_76 = 0 ; V_76 <= * V_75 ; ) {
V_20 = F_44 ( V_73 , V_20 , & V_76 ) ;
if ( ! V_20 )
break;
}
return V_20 ;
}
static void *
F_48 ( struct V_72 * V_73 , void * V_74 , T_4 * V_75 )
{
struct V_2 * V_20 = V_74 ;
( * V_75 ) ++ ;
F_45 (call, &ftrace_events, list) {
if ( V_20 -> V_44 & V_45 )
return V_20 ;
}
return NULL ;
}
static void * F_49 ( struct V_72 * V_73 , T_4 * V_75 )
{
struct V_2 * V_20 ;
T_4 V_76 ;
F_22 ( & V_43 ) ;
V_20 = F_47 ( & V_77 , struct V_2 , V_78 ) ;
for ( V_76 = 0 ; V_76 <= * V_75 ; ) {
V_20 = F_48 ( V_73 , V_20 , & V_76 ) ;
if ( ! V_20 )
break;
}
return V_20 ;
}
static int F_50 ( struct V_72 * V_73 , void * V_74 )
{
struct V_2 * V_20 = V_74 ;
if ( strcmp ( V_20 -> V_4 -> system , V_79 ) != 0 )
F_51 ( V_73 , L_5 , V_20 -> V_4 -> system ) ;
F_51 ( V_73 , L_2 , V_20 -> V_8 ) ;
return 0 ;
}
static void F_52 ( struct V_72 * V_73 , void * V_80 )
{
F_26 ( & V_43 ) ;
}
static int
F_53 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
const struct V_82 * V_83 ;
if ( ( V_61 -> V_84 & V_85 ) &&
( V_61 -> V_86 & V_87 ) )
F_29 () ;
V_83 = V_81 -> V_88 ;
return F_54 ( V_61 , V_83 ) ;
}
static T_1
F_55 ( struct V_61 * V_89 , char T_2 * V_62 , T_3 V_63 ,
T_4 * V_64 )
{
struct V_2 * V_20 = V_89 -> V_90 ;
char * V_60 ;
if ( V_20 -> V_44 & V_45 )
V_60 = L_6 ;
else
V_60 = L_7 ;
return F_56 ( V_62 , V_63 , V_64 , V_60 , 2 ) ;
}
static T_1
F_57 ( struct V_61 * V_89 , const char T_2 * V_62 , T_3 V_63 ,
T_4 * V_64 )
{
struct V_2 * V_20 = V_89 -> V_90 ;
unsigned long V_91 ;
int V_21 ;
V_21 = F_58 ( V_62 , V_63 , 10 , & V_91 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_39 () ;
if ( V_21 < 0 )
return V_21 ;
switch ( V_91 ) {
case 0 :
case 1 :
F_22 ( & V_43 ) ;
V_21 = F_27 ( V_20 , V_91 ) ;
F_26 ( & V_43 ) ;
break;
default:
return - V_58 ;
}
* V_64 += V_63 ;
return V_21 ? V_21 : V_63 ;
}
static T_1
F_59 ( struct V_61 * V_89 , char T_2 * V_62 , T_3 V_63 ,
T_4 * V_64 )
{
const char V_92 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_50 * system = V_89 -> V_90 ;
struct V_2 * V_20 ;
char V_60 [ 2 ] ;
int V_57 = 0 ;
int V_21 ;
F_22 ( & V_43 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_8 || ! V_20 -> V_4 || ! V_20 -> V_4 -> V_47 )
continue;
if ( system && strcmp ( V_20 -> V_4 -> system , system -> V_8 ) != 0 )
continue;
V_57 |= ( 1 << ! ! ( V_20 -> V_44 & V_45 ) ) ;
if ( V_57 == 3 )
break;
}
F_26 ( & V_43 ) ;
V_60 [ 0 ] = V_92 [ V_57 ] ;
V_60 [ 1 ] = '\n' ;
V_21 = F_56 ( V_62 , V_63 , V_64 , V_60 , 2 ) ;
return V_21 ;
}
static T_1
F_60 ( struct V_61 * V_89 , const char T_2 * V_62 , T_3 V_63 ,
T_4 * V_64 )
{
struct V_50 * system = V_89 -> V_90 ;
const char * V_8 = NULL ;
unsigned long V_91 ;
T_1 V_21 ;
V_21 = F_58 ( V_62 , V_63 , 10 , & V_91 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_39 () ;
if ( V_21 < 0 )
return V_21 ;
if ( V_91 != 0 && V_91 != 1 )
return - V_58 ;
if ( system )
V_8 = system -> V_8 ;
V_21 = F_34 ( NULL , V_8 , NULL , V_91 ) ;
if ( V_21 )
goto V_93;
V_21 = V_63 ;
V_93:
* V_64 += V_63 ;
return V_21 ;
}
static void * F_61 ( struct V_72 * V_73 , void * V_74 , T_4 * V_75 )
{
struct V_2 * V_20 = V_73 -> V_94 ;
struct V_13 * V_14 ;
struct V_1 * V_95 = & V_96 ;
struct V_1 * V_7 = F_1 ( V_20 ) ;
( * V_75 ) ++ ;
switch ( ( unsigned long ) V_74 ) {
case V_97 :
if ( F_62 ( F_63 ( V_95 ) ) )
return NULL ;
V_14 = F_47 ( V_95 -> V_98 ,
struct V_13 , V_18 ) ;
return V_14 ;
case V_99 :
if ( F_62 ( F_63 ( V_7 ) ) )
return NULL ;
V_14 = F_47 ( V_7 -> V_98 , struct V_13 , V_18 ) ;
return V_14 ;
case V_100 :
return NULL ;
}
V_14 = V_74 ;
if ( V_14 -> V_18 . V_98 == V_95 )
return ( void * ) V_99 ;
else if ( V_14 -> V_18 . V_98 == V_7 )
return ( void * ) V_100 ;
V_14 = F_47 ( V_14 -> V_18 . V_98 , struct V_13 , V_18 ) ;
return V_14 ;
}
static void * F_64 ( struct V_72 * V_73 , T_4 * V_75 )
{
T_4 V_76 = 0 ;
void * V_80 ;
if ( ! * V_75 )
return ( void * ) V_97 ;
V_80 = ( void * ) V_97 ;
do {
V_80 = F_61 ( V_73 , V_80 , & V_76 ) ;
} while ( V_80 && V_76 < * V_75 );
return V_80 ;
}
static int F_65 ( struct V_72 * V_73 , void * V_74 )
{
struct V_2 * V_20 = V_73 -> V_94 ;
struct V_13 * V_14 ;
const char * V_101 ;
switch ( ( unsigned long ) V_74 ) {
case V_97 :
F_51 ( V_73 , L_8 , V_20 -> V_8 ) ;
F_51 ( V_73 , L_9 , V_20 -> V_28 . type ) ;
F_51 ( V_73 , L_10 ) ;
return 0 ;
case V_99 :
F_66 ( V_73 , '\n' ) ;
return 0 ;
case V_100 :
F_51 ( V_73 , L_11 ,
V_20 -> V_102 ) ;
return 0 ;
}
V_14 = V_74 ;
V_101 = strchr ( V_14 -> type , '[' ) ;
if ( ! strncmp ( V_14 -> type , L_12 , 10 ) )
V_101 = NULL ;
if ( ! V_101 )
F_51 ( V_73 , L_13 ,
V_14 -> type , V_14 -> V_8 , V_14 -> V_9 ,
V_14 -> V_10 , ! ! V_14 -> V_11 ) ;
else
F_51 ( V_73 , L_14 ,
( int ) ( V_101 - V_14 -> type ) ,
V_14 -> type , V_14 -> V_8 ,
V_101 , V_14 -> V_9 ,
V_14 -> V_10 , ! ! V_14 -> V_11 ) ;
return 0 ;
}
static void F_67 ( struct V_72 * V_73 , void * V_80 )
{
}
static int F_68 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
struct V_2 * V_20 = V_81 -> V_88 ;
struct V_72 * V_73 ;
int V_21 ;
V_21 = F_54 ( V_61 , & V_103 ) ;
if ( V_21 < 0 )
return V_21 ;
V_73 = V_61 -> V_90 ;
V_73 -> V_94 = V_20 ;
return 0 ;
}
static T_1
F_69 ( struct V_61 * V_89 , char T_2 * V_62 , T_3 V_63 , T_4 * V_64 )
{
struct V_2 * V_20 = V_89 -> V_90 ;
struct V_104 * V_105 ;
int V_106 ;
if ( * V_64 )
return 0 ;
V_105 = F_70 ( sizeof( * V_105 ) , V_15 ) ;
if ( ! V_105 )
return - V_19 ;
F_71 ( V_105 ) ;
F_72 ( V_105 , L_15 , V_20 -> V_28 . type ) ;
V_106 = F_56 ( V_62 , V_63 , V_64 ,
V_105 -> V_69 , V_105 -> V_107 ) ;
F_7 ( V_105 ) ;
return V_106 ;
}
static T_1
F_73 ( struct V_61 * V_89 , char T_2 * V_62 , T_3 V_63 ,
T_4 * V_64 )
{
struct V_2 * V_20 = V_89 -> V_90 ;
struct V_104 * V_105 ;
int V_106 ;
if ( * V_64 )
return 0 ;
V_105 = F_70 ( sizeof( * V_105 ) , V_15 ) ;
if ( ! V_105 )
return - V_19 ;
F_71 ( V_105 ) ;
F_74 ( V_20 , V_105 ) ;
V_106 = F_56 ( V_62 , V_63 , V_64 , V_105 -> V_69 , V_105 -> V_107 ) ;
F_7 ( V_105 ) ;
return V_106 ;
}
static T_1
F_75 ( struct V_61 * V_89 , const char T_2 * V_62 , T_3 V_63 ,
T_4 * V_64 )
{
struct V_2 * V_20 = V_89 -> V_90 ;
char * V_60 ;
int V_16 ;
if ( V_63 >= V_108 )
return - V_58 ;
V_60 = ( char * ) F_76 ( V_109 ) ;
if ( ! V_60 )
return - V_19 ;
if ( F_77 ( V_60 , V_62 , V_63 ) ) {
F_78 ( ( unsigned long ) V_60 ) ;
return - V_110 ;
}
V_60 [ V_63 ] = '\0' ;
V_16 = F_79 ( V_20 , V_60 ) ;
F_78 ( ( unsigned long ) V_60 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_64 += V_63 ;
return V_63 ;
}
static int F_80 ( struct V_81 * V_81 , struct V_61 * V_89 )
{
struct V_50 * system = NULL ;
int V_21 ;
if ( ! V_81 -> V_88 )
goto V_111;
F_22 ( & V_43 ) ;
F_23 (system, &event_subsystems, list) {
if ( system == V_81 -> V_88 ) {
if ( ! system -> V_112 ) {
system = NULL ;
break;
}
F_32 ( system ) ;
break;
}
}
F_26 ( & V_43 ) ;
if ( system != V_81 -> V_88 )
return - V_29 ;
V_111:
V_21 = F_81 ( V_81 , V_89 ) ;
if ( V_21 < 0 && system )
F_33 ( system ) ;
return V_21 ;
}
static int F_82 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
struct V_50 * system = V_81 -> V_88 ;
if ( system )
F_33 ( system ) ;
return 0 ;
}
static T_1
F_83 ( struct V_61 * V_89 , char T_2 * V_62 , T_3 V_63 ,
T_4 * V_64 )
{
struct V_50 * system = V_89 -> V_90 ;
struct V_104 * V_105 ;
int V_106 ;
if ( * V_64 )
return 0 ;
V_105 = F_70 ( sizeof( * V_105 ) , V_15 ) ;
if ( ! V_105 )
return - V_19 ;
F_71 ( V_105 ) ;
F_84 ( system , V_105 ) ;
V_106 = F_56 ( V_62 , V_63 , V_64 , V_105 -> V_69 , V_105 -> V_107 ) ;
F_7 ( V_105 ) ;
return V_106 ;
}
static T_1
F_85 ( struct V_61 * V_89 , const char T_2 * V_62 , T_3 V_63 ,
T_4 * V_64 )
{
struct V_50 * system = V_89 -> V_90 ;
char * V_60 ;
int V_16 ;
if ( V_63 >= V_108 )
return - V_58 ;
V_60 = ( char * ) F_76 ( V_109 ) ;
if ( ! V_60 )
return - V_19 ;
if ( F_77 ( V_60 , V_62 , V_63 ) ) {
F_78 ( ( unsigned long ) V_60 ) ;
return - V_110 ;
}
V_60 [ V_63 ] = '\0' ;
V_16 = F_86 ( system , V_60 ) ;
F_78 ( ( unsigned long ) V_60 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_64 += V_63 ;
return V_63 ;
}
static T_1
F_87 ( struct V_61 * V_89 , char T_2 * V_62 , T_3 V_63 , T_4 * V_64 )
{
int (* F_88)( struct V_104 * V_105 ) = V_89 -> V_90 ;
struct V_104 * V_105 ;
int V_106 ;
if ( * V_64 )
return 0 ;
V_105 = F_70 ( sizeof( * V_105 ) , V_15 ) ;
if ( ! V_105 )
return - V_19 ;
F_71 ( V_105 ) ;
F_88 ( V_105 ) ;
V_106 = F_56 ( V_62 , V_63 , V_64 , V_105 -> V_69 , V_105 -> V_107 ) ;
F_7 ( V_105 ) ;
return V_106 ;
}
static struct V_113 * F_89 ( void )
{
static struct V_113 * V_114 ;
static struct V_113 * V_115 ;
if ( V_115 )
return V_115 ;
V_114 = F_90 () ;
if ( ! V_114 )
return NULL ;
V_115 = F_91 ( L_16 , V_114 ) ;
if ( ! V_115 )
F_92 ( L_17
L_18 ) ;
return V_115 ;
}
static struct V_113 *
F_93 ( const char * V_8 , struct V_113 * V_115 )
{
struct V_50 * system ;
struct V_113 * V_116 ;
F_23 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_8 , V_8 ) == 0 ) {
system -> V_112 ++ ;
return system -> V_116 ;
}
}
system = F_70 ( sizeof( * system ) , V_15 ) ;
if ( ! system ) {
F_92 ( L_19 ,
V_8 ) ;
return V_115 ;
}
system -> V_116 = F_91 ( V_8 , V_115 ) ;
if ( ! system -> V_116 ) {
F_92 ( L_20 ,
V_8 ) ;
F_7 ( system ) ;
return V_115 ;
}
system -> V_112 = 1 ;
system -> V_53 = 1 ;
system -> V_8 = F_4 ( V_8 , V_15 ) ;
if ( ! system -> V_8 ) {
F_94 ( system -> V_116 ) ;
F_7 ( system ) ;
return V_115 ;
}
F_6 ( & system -> V_78 , & V_117 ) ;
system -> V_52 = NULL ;
system -> V_52 = F_3 ( sizeof( struct V_51 ) , V_15 ) ;
if ( ! system -> V_52 ) {
F_92 ( L_21
L_22 , V_8 ) ;
return system -> V_116 ;
}
V_116 = F_95 ( L_23 , 0644 , system -> V_116 , system ,
& V_118 ) ;
if ( ! V_116 ) {
F_7 ( system -> V_52 ) ;
system -> V_52 = NULL ;
F_92 ( L_17
L_24 , V_8 ) ;
}
F_96 ( L_25 , 0644 , system -> V_116 , system ,
& V_119 ) ;
return system -> V_116 ;
}
static int
F_97 ( struct V_2 * V_20 , struct V_113 * V_115 ,
const struct V_120 * V_27 ,
const struct V_120 * V_42 ,
const struct V_120 * V_52 ,
const struct V_120 * V_121 )
{
struct V_1 * V_7 ;
int V_21 ;
if ( strcmp ( V_20 -> V_4 -> system , V_79 ) != 0 )
V_115 = F_93 ( V_20 -> V_4 -> system , V_115 ) ;
V_20 -> V_122 = F_91 ( V_20 -> V_8 , V_115 ) ;
if ( ! V_20 -> V_122 ) {
F_92 ( L_17
L_26 , V_20 -> V_8 ) ;
return - 1 ;
}
if ( V_20 -> V_4 -> V_47 && ! ( V_20 -> V_44 & V_59 ) )
F_96 ( L_25 , 0644 , V_20 -> V_122 , V_20 ,
V_42 ) ;
#ifdef F_20
if ( V_20 -> V_28 . type && V_20 -> V_4 -> V_47 )
F_96 ( L_27 , 0444 , V_20 -> V_122 , V_20 ,
V_27 ) ;
#endif
V_7 = F_1 ( V_20 ) ;
if ( F_63 ( V_7 ) ) {
V_21 = V_20 -> V_4 -> V_123 ( V_20 ) ;
if ( V_21 < 0 ) {
F_92 ( L_28
L_29 , V_20 -> V_8 ) ;
return V_21 ;
}
}
F_96 ( L_23 , 0644 , V_20 -> V_122 , V_20 ,
V_52 ) ;
F_96 ( L_30 , 0444 , V_20 -> V_122 , V_20 ,
V_121 ) ;
return 0 ;
}
static void F_98 ( struct V_2 * V_20 )
{
F_27 ( V_20 , 0 ) ;
if ( V_20 -> V_28 . V_124 )
F_99 ( & V_20 -> V_28 ) ;
F_14 ( & V_20 -> V_78 ) ;
}
static int F_100 ( struct V_2 * V_20 )
{
int V_21 = 0 ;
if ( F_9 ( ! V_20 -> V_8 ) )
return - V_58 ;
if ( V_20 -> V_4 -> V_125 ) {
V_21 = V_20 -> V_4 -> V_125 ( V_20 ) ;
if ( V_21 < 0 && V_21 != - V_126 )
F_101 ( L_31 ,
V_20 -> V_8 ) ;
}
return V_21 ;
}
static int
F_102 ( struct V_2 * V_20 , struct V_127 * V_128 ,
const struct V_120 * V_27 ,
const struct V_120 * V_42 ,
const struct V_120 * V_52 ,
const struct V_120 * V_121 )
{
struct V_113 * V_115 ;
int V_21 ;
V_21 = F_100 ( V_20 ) ;
if ( V_21 < 0 )
return V_21 ;
V_115 = F_89 () ;
if ( ! V_115 )
return - V_129 ;
V_21 = F_97 ( V_20 , V_115 , V_27 , V_42 , V_52 , V_121 ) ;
if ( ! V_21 )
F_6 ( & V_20 -> V_78 , & V_77 ) ;
V_20 -> V_128 = V_128 ;
return V_21 ;
}
int F_103 ( struct V_2 * V_20 )
{
int V_21 ;
F_22 ( & V_43 ) ;
V_21 = F_102 ( V_20 , NULL , & V_130 ,
& V_131 ,
& V_132 ,
& V_133 ) ;
F_26 ( & V_43 ) ;
return V_21 ;
}
static void F_104 ( const char * V_8 )
{
struct V_50 * system ;
if ( strcmp ( V_8 , V_79 ) == 0 )
return;
F_23 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_8 , V_8 ) == 0 ) {
if ( ! -- system -> V_112 ) {
F_105 ( system -> V_116 ) ;
F_14 ( & system -> V_78 ) ;
F_30 ( system ) ;
}
break;
}
}
}
static void F_106 ( struct V_2 * V_20 )
{
F_98 ( V_20 ) ;
F_12 ( V_20 ) ;
F_107 ( V_20 ) ;
F_105 ( V_20 -> V_122 ) ;
F_104 ( V_20 -> V_4 -> system ) ;
}
void F_108 ( struct V_2 * V_20 )
{
F_22 ( & V_43 ) ;
F_109 ( & V_134 ) ;
F_106 ( V_20 ) ;
F_110 ( & V_134 ) ;
F_26 ( & V_43 ) ;
}
static struct V_135 *
F_111 ( struct V_127 * V_128 )
{
struct V_135 * V_136 ;
V_136 = F_70 ( sizeof( * V_136 ) , V_15 ) ;
if ( ! V_136 )
return NULL ;
V_136 -> V_128 = V_128 ;
V_136 -> V_27 = V_130 ;
V_136 -> V_27 . V_137 = V_128 ;
V_136 -> V_42 = V_131 ;
V_136 -> V_42 . V_137 = V_128 ;
V_136 -> V_52 = V_132 ;
V_136 -> V_52 . V_137 = V_128 ;
V_136 -> V_121 = V_133 ;
V_136 -> V_121 . V_137 = V_128 ;
F_6 ( & V_136 -> V_78 , & V_138 ) ;
return V_136 ;
}
static void F_112 ( struct V_127 * V_128 )
{
struct V_135 * V_136 = NULL ;
struct V_2 * * V_20 , * * V_139 , * * V_140 ;
V_139 = V_128 -> V_141 ;
V_140 = V_128 -> V_141 + V_128 -> V_142 ;
if ( V_139 == V_140 )
return;
V_136 = F_111 ( V_128 ) ;
if ( ! V_136 )
return;
F_113 (call, start, end) {
F_102 ( * V_20 , V_128 ,
& V_136 -> V_27 , & V_136 -> V_42 ,
& V_136 -> V_52 , & V_136 -> V_121 ) ;
}
}
static void F_114 ( struct V_127 * V_128 )
{
struct V_135 * V_136 ;
struct V_2 * V_20 , * V_80 ;
bool V_143 = false ;
F_109 ( & V_134 ) ;
F_13 (call, p, &ftrace_events, list) {
if ( V_20 -> V_128 == V_128 ) {
V_143 = true ;
F_106 ( V_20 ) ;
}
}
F_23 (file_ops, &ftrace_module_file_list, list) {
if ( V_136 -> V_128 == V_128 )
break;
}
if ( & V_136 -> V_78 != & V_138 ) {
F_14 ( & V_136 -> V_78 ) ;
F_7 ( V_136 ) ;
}
if ( V_143 )
F_115 () ;
F_110 ( & V_134 ) ;
}
static int F_116 ( struct V_144 * V_145 ,
unsigned long V_91 , void * V_31 )
{
struct V_127 * V_128 = V_31 ;
F_22 ( & V_43 ) ;
switch ( V_91 ) {
case V_146 :
F_112 ( V_128 ) ;
break;
case V_147 :
F_114 ( V_128 ) ;
break;
}
F_26 ( & V_43 ) ;
return 0 ;
}
static int F_116 ( struct V_144 * V_145 ,
unsigned long V_91 , void * V_31 )
{
return 0 ;
}
static T_5 int F_117 ( char * V_148 )
{
F_118 ( V_149 , V_148 , V_150 ) ;
V_151 = 1 ;
V_152 = 1 ;
return 1 ;
}
static T_5 int F_119 ( void )
{
struct V_2 * * V_153 , * V_20 ;
char * V_60 = V_149 ;
char * V_154 ;
int V_21 ;
F_113 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_20 = * V_153 ;
V_21 = F_100 ( V_20 ) ;
if ( ! V_21 )
F_6 ( & V_20 -> V_78 , & V_77 ) ;
}
while ( true ) {
V_154 = F_36 ( & V_60 , L_32 ) ;
if ( ! V_154 )
break;
if ( ! * V_154 )
continue;
V_21 = F_35 ( V_154 , 1 ) ;
if ( V_21 )
F_101 ( L_33 , V_154 ) ;
}
return 0 ;
}
static T_5 int F_120 ( void )
{
struct V_2 * V_20 ;
struct V_113 * V_114 ;
struct V_113 * V_116 ;
struct V_113 * V_115 ;
int V_21 ;
V_114 = F_90 () ;
if ( ! V_114 )
return 0 ;
V_116 = F_95 ( L_34 , 0444 , V_114 ,
( void * ) & V_155 ,
& V_156 ) ;
if ( ! V_116 )
F_92 ( L_17
L_35 ) ;
V_116 = F_95 ( L_36 , 0644 , V_114 ,
( void * ) & V_157 ,
& V_158 ) ;
if ( ! V_116 )
F_92 ( L_17
L_37 ) ;
V_115 = F_89 () ;
if ( ! V_115 )
return 0 ;
F_96 ( L_38 , 0444 , V_115 ,
V_159 ,
& V_160 ) ;
F_96 ( L_39 , 0444 , V_115 ,
V_161 ,
& V_160 ) ;
F_96 ( L_25 , 0644 , V_115 ,
NULL , & V_119 ) ;
if ( F_10 () )
F_92 ( L_40 ) ;
F_23 (call, &ftrace_events, list) {
V_21 = F_97 ( V_20 , V_115 ,
& V_130 ,
& V_131 ,
& V_132 ,
& V_133 ) ;
if ( V_21 < 0 )
F_98 ( V_20 ) ;
}
V_21 = F_121 ( & V_162 ) ;
if ( V_21 )
F_92 ( L_41 ) ;
return 0 ;
}
static T_5 void F_122 ( struct V_163 * V_164 )
{
F_123 ( & V_165 ) ;
F_124 ( & V_166 ) ;
F_125 ( 1 ) ;
F_126 ( & V_166 ) ;
F_127 ( & V_165 ) ;
F_22 ( & V_167 ) ;
F_128 ( 1 ) ;
F_26 ( & V_167 ) ;
}
static T_5 int F_129 ( void * V_168 )
{
void * V_169 ;
V_169 = F_70 ( 1234 , V_15 ) ;
if ( ! V_169 )
F_28 ( L_42 ) ;
F_130 ( F_122 ) ;
F_7 ( V_169 ) ;
F_131 ( V_170 ) ;
while ( ! F_132 () )
F_133 () ;
return 0 ;
}
static T_5 void F_134 ( void )
{
struct V_171 * V_172 ;
V_172 = F_135 ( F_129 , NULL , L_43 ) ;
F_128 ( 1 ) ;
F_136 ( V_172 ) ;
}
static T_5 void F_137 ( void )
{
struct V_2 * V_20 ;
struct V_50 * system ;
int V_21 ;
F_28 ( L_44 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_4 || ! V_20 -> V_4 -> V_33 )
continue;
#ifndef F_138
if ( V_20 -> V_4 -> system &&
strcmp ( V_20 -> V_4 -> system , L_45 ) == 0 )
continue;
#endif
F_28 ( L_46 , V_20 -> V_8 ) ;
if ( V_20 -> V_44 & V_45 ) {
F_92 ( L_47 ) ;
F_31 ( 1 ) ;
continue;
}
F_27 ( V_20 , 1 ) ;
F_134 () ;
F_27 ( V_20 , 0 ) ;
F_139 ( L_48 ) ;
}
F_28 ( L_49 ) ;
F_23 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_8 , L_50 ) == 0 )
continue;
F_28 ( L_51 , system -> V_8 ) ;
V_21 = F_34 ( NULL , system -> V_8 , NULL , 1 ) ;
if ( F_31 ( V_21 ) ) {
F_92 ( L_52 ,
system -> V_8 ) ;
continue;
}
F_134 () ;
V_21 = F_34 ( NULL , system -> V_8 , NULL , 0 ) ;
if ( F_31 ( V_21 ) ) {
F_92 ( L_53 ,
system -> V_8 ) ;
continue;
}
F_139 ( L_48 ) ;
}
F_28 ( L_54 ) ;
F_28 ( L_55 ) ;
V_21 = F_34 ( NULL , NULL , NULL , 1 ) ;
if ( F_31 ( V_21 ) ) {
F_92 ( L_56 ) ;
return;
}
F_134 () ;
V_21 = F_34 ( NULL , NULL , NULL , 0 ) ;
if ( F_31 ( V_21 ) ) {
F_92 ( L_57 ) ;
return;
}
F_139 ( L_48 ) ;
}
static void
F_140 ( unsigned long V_173 , unsigned long V_174 ,
struct V_175 * V_176 , struct V_177 * V_177 )
{
struct V_178 * V_28 ;
struct V_179 * V_69 ;
struct V_180 * V_116 ;
unsigned long V_44 ;
long V_181 ;
int V_182 ;
int V_183 ;
V_183 = F_141 () ;
F_142 () ;
V_182 = F_143 () ;
V_181 = F_144 ( & F_145 ( V_184 , V_182 ) ) ;
if ( V_181 != 1 )
goto V_93;
F_146 ( V_44 ) ;
V_28 = F_147 ( & V_69 ,
V_185 , sizeof( * V_116 ) ,
V_44 , V_183 ) ;
if ( ! V_28 )
goto V_93;
V_116 = F_148 ( V_28 ) ;
V_116 -> V_173 = V_173 ;
V_116 -> V_174 = V_174 ;
F_149 ( V_69 , V_28 , V_44 , V_183 ) ;
V_93:
F_150 ( & F_145 ( V_184 , V_182 ) ) ;
F_151 () ;
}
static T_5 void F_152 ( void )
{
int V_21 ;
V_21 = F_153 ( & V_186 ) ;
if ( F_9 ( V_21 < 0 ) ) {
F_28 ( L_58 ) ;
return;
}
F_28 ( L_59 ) ;
F_137 () ;
F_154 ( & V_186 ) ;
}
static T_5 void F_152 ( void )
{
}
static T_5 int F_155 ( void )
{
if ( ! V_152 ) {
F_137 () ;
F_152 () ;
}
return 0 ;
}
