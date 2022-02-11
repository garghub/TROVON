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
int F_17 ( struct V_2 * V_20 , enum V_30 type )
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
#endif
}
return 0 ;
}
void F_21 ( bool V_37 )
{
struct V_2 * V_20 ;
F_22 ( & V_38 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! ( V_20 -> V_39 & V_40 ) )
continue;
if ( V_37 ) {
F_24 () ;
V_20 -> V_39 |= V_41 ;
} else {
F_25 () ;
V_20 -> V_39 &= ~ V_41 ;
}
}
F_26 ( & V_38 ) ;
}
static int F_27 ( struct V_2 * V_20 ,
int V_37 )
{
int V_21 = 0 ;
switch ( V_37 ) {
case 0 :
if ( V_20 -> V_39 & V_40 ) {
V_20 -> V_39 &= ~ V_40 ;
if ( V_20 -> V_39 & V_41 ) {
F_25 () ;
V_20 -> V_39 &= ~ V_41 ;
}
V_20 -> V_4 -> V_42 ( V_20 , V_33 ) ;
}
break;
case 1 :
if ( ! ( V_20 -> V_39 & V_40 ) ) {
if ( V_43 & V_44 ) {
F_24 () ;
V_20 -> V_39 |= V_41 ;
}
V_21 = V_20 -> V_4 -> V_42 ( V_20 , V_31 ) ;
if ( V_21 ) {
F_25 () ;
F_28 ( L_1
L_2 , V_20 -> V_8 ) ;
break;
}
V_20 -> V_39 |= V_40 ;
}
break;
}
return V_21 ;
}
static void F_29 ( void )
{
struct V_2 * V_20 ;
F_22 ( & V_38 ) ;
F_23 (call, &ftrace_events, list) {
F_27 ( V_20 , 0 ) ;
}
F_26 ( & V_38 ) ;
}
static int F_30 ( const char * V_45 , const char * V_46 ,
const char * V_28 , int V_47 )
{
struct V_2 * V_20 ;
int V_21 = - V_48 ;
F_22 ( & V_38 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_8 || ! V_20 -> V_4 || ! V_20 -> V_4 -> V_42 )
continue;
if ( V_45 &&
strcmp ( V_45 , V_20 -> V_8 ) != 0 &&
strcmp ( V_45 , V_20 -> V_4 -> system ) != 0 )
continue;
if ( V_46 && strcmp ( V_46 , V_20 -> V_4 -> system ) != 0 )
continue;
if ( V_28 && strcmp ( V_28 , V_20 -> V_8 ) != 0 )
continue;
F_27 ( V_20 , V_47 ) ;
V_21 = 0 ;
}
F_26 ( & V_38 ) ;
return V_21 ;
}
static int F_31 ( char * V_49 , int V_47 )
{
char * V_28 = NULL , * V_46 = NULL , * V_45 ;
V_45 = F_32 ( & V_49 , L_3 ) ;
if ( V_49 ) {
V_46 = V_45 ;
V_28 = V_49 ;
V_45 = NULL ;
if ( ! strlen ( V_46 ) || strcmp ( V_46 , L_4 ) == 0 )
V_46 = NULL ;
if ( ! strlen ( V_28 ) || strcmp ( V_28 , L_4 ) == 0 )
V_28 = NULL ;
}
return F_30 ( V_45 , V_46 , V_28 , V_47 ) ;
}
int F_33 ( const char * system , const char * V_28 , int V_47 )
{
return F_30 ( NULL , system , V_28 , V_47 ) ;
}
static T_1
F_34 ( struct V_50 * V_50 , const char T_2 * V_51 ,
T_3 V_52 , T_4 * V_53 )
{
struct V_54 V_55 ;
T_1 V_56 , V_21 ;
if ( ! V_52 )
return 0 ;
V_21 = F_35 () ;
if ( V_21 < 0 )
return V_21 ;
if ( F_36 ( & V_55 , V_57 + 1 ) )
return - V_19 ;
V_56 = F_37 ( & V_55 , V_51 , V_52 , V_53 ) ;
if ( V_56 >= 0 && F_38 ( ( & V_55 ) ) ) {
int V_47 = 1 ;
if ( * V_55 . V_58 == '!' )
V_47 = 0 ;
V_55 . V_58 [ V_55 . V_59 ] = 0 ;
V_21 = F_31 ( V_55 . V_58 + ! V_47 , V_47 ) ;
if ( V_21 )
goto V_60;
}
V_21 = V_56 ;
V_60:
F_39 ( & V_55 ) ;
return V_21 ;
}
static void *
F_40 ( struct V_61 * V_62 , void * V_63 , T_4 * V_64 )
{
struct V_2 * V_20 = V_63 ;
( * V_64 ) ++ ;
F_41 (call, &ftrace_events, list) {
if ( V_20 -> V_4 && V_20 -> V_4 -> V_42 )
return V_20 ;
}
return NULL ;
}
static void * F_42 ( struct V_61 * V_62 , T_4 * V_64 )
{
struct V_2 * V_20 ;
T_4 V_65 ;
F_22 ( & V_38 ) ;
V_20 = F_43 ( & V_66 , struct V_2 , V_67 ) ;
for ( V_65 = 0 ; V_65 <= * V_64 ; ) {
V_20 = F_40 ( V_62 , V_20 , & V_65 ) ;
if ( ! V_20 )
break;
}
return V_20 ;
}
static void *
F_44 ( struct V_61 * V_62 , void * V_63 , T_4 * V_64 )
{
struct V_2 * V_20 = V_63 ;
( * V_64 ) ++ ;
F_41 (call, &ftrace_events, list) {
if ( V_20 -> V_39 & V_40 )
return V_20 ;
}
return NULL ;
}
static void * F_45 ( struct V_61 * V_62 , T_4 * V_64 )
{
struct V_2 * V_20 ;
T_4 V_65 ;
F_22 ( & V_38 ) ;
V_20 = F_43 ( & V_66 , struct V_2 , V_67 ) ;
for ( V_65 = 0 ; V_65 <= * V_64 ; ) {
V_20 = F_44 ( V_62 , V_20 , & V_65 ) ;
if ( ! V_20 )
break;
}
return V_20 ;
}
static int F_46 ( struct V_61 * V_62 , void * V_63 )
{
struct V_2 * V_20 = V_63 ;
if ( strcmp ( V_20 -> V_4 -> system , V_68 ) != 0 )
F_47 ( V_62 , L_5 , V_20 -> V_4 -> system ) ;
F_47 ( V_62 , L_2 , V_20 -> V_8 ) ;
return 0 ;
}
static void F_48 ( struct V_61 * V_62 , void * V_69 )
{
F_26 ( & V_38 ) ;
}
static int
F_49 ( struct V_70 * V_70 , struct V_50 * V_50 )
{
const struct V_71 * V_72 ;
if ( ( V_50 -> V_73 & V_74 ) &&
( V_50 -> V_75 & V_76 ) )
F_29 () ;
V_72 = V_70 -> V_77 ;
return F_50 ( V_50 , V_72 ) ;
}
static T_1
F_51 ( struct V_50 * V_78 , char T_2 * V_51 , T_3 V_52 ,
T_4 * V_53 )
{
struct V_2 * V_20 = V_78 -> V_79 ;
char * V_49 ;
if ( V_20 -> V_39 & V_40 )
V_49 = L_6 ;
else
V_49 = L_7 ;
return F_52 ( V_51 , V_52 , V_53 , V_49 , 2 ) ;
}
static T_1
F_53 ( struct V_50 * V_78 , const char T_2 * V_51 , T_3 V_52 ,
T_4 * V_53 )
{
struct V_2 * V_20 = V_78 -> V_79 ;
char V_49 [ 64 ] ;
unsigned long V_80 ;
int V_21 ;
if ( V_52 >= sizeof( V_49 ) )
return - V_48 ;
if ( F_54 ( & V_49 , V_51 , V_52 ) )
return - V_81 ;
V_49 [ V_52 ] = 0 ;
V_21 = F_55 ( V_49 , 10 , & V_80 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_35 () ;
if ( V_21 < 0 )
return V_21 ;
switch ( V_80 ) {
case 0 :
case 1 :
F_22 ( & V_38 ) ;
V_21 = F_27 ( V_20 , V_80 ) ;
F_26 ( & V_38 ) ;
break;
default:
return - V_48 ;
}
* V_53 += V_52 ;
return V_21 ? V_21 : V_52 ;
}
static T_1
F_56 ( struct V_50 * V_78 , char T_2 * V_51 , T_3 V_52 ,
T_4 * V_53 )
{
const char V_82 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
const char * system = V_78 -> V_79 ;
struct V_2 * V_20 ;
char V_49 [ 2 ] ;
int V_47 = 0 ;
int V_21 ;
F_22 ( & V_38 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_8 || ! V_20 -> V_4 || ! V_20 -> V_4 -> V_42 )
continue;
if ( system && strcmp ( V_20 -> V_4 -> system , system ) != 0 )
continue;
V_47 |= ( 1 << ! ! ( V_20 -> V_39 & V_40 ) ) ;
if ( V_47 == 3 )
break;
}
F_26 ( & V_38 ) ;
V_49 [ 0 ] = V_82 [ V_47 ] ;
V_49 [ 1 ] = '\n' ;
V_21 = F_52 ( V_51 , V_52 , V_53 , V_49 , 2 ) ;
return V_21 ;
}
static T_1
F_57 ( struct V_50 * V_78 , const char T_2 * V_51 , T_3 V_52 ,
T_4 * V_53 )
{
const char * system = V_78 -> V_79 ;
unsigned long V_80 ;
char V_49 [ 64 ] ;
T_1 V_21 ;
if ( V_52 >= sizeof( V_49 ) )
return - V_48 ;
if ( F_54 ( & V_49 , V_51 , V_52 ) )
return - V_81 ;
V_49 [ V_52 ] = 0 ;
V_21 = F_55 ( V_49 , 10 , & V_80 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_35 () ;
if ( V_21 < 0 )
return V_21 ;
if ( V_80 != 0 && V_80 != 1 )
return - V_48 ;
V_21 = F_30 ( NULL , system , NULL , V_80 ) ;
if ( V_21 )
goto V_83;
V_21 = V_52 ;
V_83:
* V_53 += V_52 ;
return V_21 ;
}
static void * F_58 ( struct V_61 * V_62 , void * V_63 , T_4 * V_64 )
{
struct V_2 * V_20 = V_62 -> V_84 ;
struct V_13 * V_14 ;
struct V_1 * V_85 = & V_86 ;
struct V_1 * V_7 = F_1 ( V_20 ) ;
( * V_64 ) ++ ;
switch ( ( unsigned long ) V_63 ) {
case V_87 :
if ( F_59 ( F_60 ( V_85 ) ) )
return NULL ;
V_14 = F_43 ( V_85 -> V_88 ,
struct V_13 , V_18 ) ;
return V_14 ;
case V_89 :
if ( F_59 ( F_60 ( V_7 ) ) )
return NULL ;
V_14 = F_43 ( V_7 -> V_88 , struct V_13 , V_18 ) ;
return V_14 ;
case V_90 :
return NULL ;
}
V_14 = V_63 ;
if ( V_14 -> V_18 . V_88 == V_85 )
return ( void * ) V_89 ;
else if ( V_14 -> V_18 . V_88 == V_7 )
return ( void * ) V_90 ;
V_14 = F_43 ( V_14 -> V_18 . V_88 , struct V_13 , V_18 ) ;
return V_14 ;
}
static void * F_61 ( struct V_61 * V_62 , T_4 * V_64 )
{
T_4 V_65 = 0 ;
void * V_69 ;
if ( ! * V_64 )
return ( void * ) V_87 ;
V_69 = ( void * ) V_87 ;
do {
V_69 = F_58 ( V_62 , V_69 , & V_65 ) ;
} while ( V_69 && V_65 < * V_64 );
return V_69 ;
}
static int F_62 ( struct V_61 * V_62 , void * V_63 )
{
struct V_2 * V_20 = V_62 -> V_84 ;
struct V_13 * V_14 ;
const char * V_91 ;
switch ( ( unsigned long ) V_63 ) {
case V_87 :
F_47 ( V_62 , L_8 , V_20 -> V_8 ) ;
F_47 ( V_62 , L_9 , V_20 -> V_28 . type ) ;
F_47 ( V_62 , L_10 ) ;
return 0 ;
case V_89 :
F_63 ( V_62 , '\n' ) ;
return 0 ;
case V_90 :
F_47 ( V_62 , L_11 ,
V_20 -> V_92 ) ;
return 0 ;
}
V_14 = V_63 ;
V_91 = strchr ( V_14 -> type , '[' ) ;
if ( ! strncmp ( V_14 -> type , L_12 , 10 ) )
V_91 = NULL ;
if ( ! V_91 )
F_47 ( V_62 , L_13 ,
V_14 -> type , V_14 -> V_8 , V_14 -> V_9 ,
V_14 -> V_10 , ! ! V_14 -> V_11 ) ;
else
F_47 ( V_62 , L_14 ,
( int ) ( V_91 - V_14 -> type ) ,
V_14 -> type , V_14 -> V_8 ,
V_91 , V_14 -> V_9 ,
V_14 -> V_10 , ! ! V_14 -> V_11 ) ;
return 0 ;
}
static void F_64 ( struct V_61 * V_62 , void * V_69 )
{
}
static int F_65 ( struct V_70 * V_70 , struct V_50 * V_50 )
{
struct V_2 * V_20 = V_70 -> V_77 ;
struct V_61 * V_62 ;
int V_21 ;
V_21 = F_50 ( V_50 , & V_93 ) ;
if ( V_21 < 0 )
return V_21 ;
V_62 = V_50 -> V_79 ;
V_62 -> V_84 = V_20 ;
return 0 ;
}
static T_1
F_66 ( struct V_50 * V_78 , char T_2 * V_51 , T_3 V_52 , T_4 * V_53 )
{
struct V_2 * V_20 = V_78 -> V_79 ;
struct V_94 * V_95 ;
int V_96 ;
if ( * V_53 )
return 0 ;
V_95 = F_67 ( sizeof( * V_95 ) , V_15 ) ;
if ( ! V_95 )
return - V_19 ;
F_68 ( V_95 ) ;
F_69 ( V_95 , L_15 , V_20 -> V_28 . type ) ;
V_96 = F_52 ( V_51 , V_52 , V_53 ,
V_95 -> V_58 , V_95 -> V_97 ) ;
F_7 ( V_95 ) ;
return V_96 ;
}
static T_1
F_70 ( struct V_50 * V_78 , char T_2 * V_51 , T_3 V_52 ,
T_4 * V_53 )
{
struct V_2 * V_20 = V_78 -> V_79 ;
struct V_94 * V_95 ;
int V_96 ;
if ( * V_53 )
return 0 ;
V_95 = F_67 ( sizeof( * V_95 ) , V_15 ) ;
if ( ! V_95 )
return - V_19 ;
F_68 ( V_95 ) ;
F_71 ( V_20 , V_95 ) ;
V_96 = F_52 ( V_51 , V_52 , V_53 , V_95 -> V_58 , V_95 -> V_97 ) ;
F_7 ( V_95 ) ;
return V_96 ;
}
static T_1
F_72 ( struct V_50 * V_78 , const char T_2 * V_51 , T_3 V_52 ,
T_4 * V_53 )
{
struct V_2 * V_20 = V_78 -> V_79 ;
char * V_49 ;
int V_16 ;
if ( V_52 >= V_98 )
return - V_48 ;
V_49 = ( char * ) F_73 ( V_99 ) ;
if ( ! V_49 )
return - V_19 ;
if ( F_54 ( V_49 , V_51 , V_52 ) ) {
F_74 ( ( unsigned long ) V_49 ) ;
return - V_81 ;
}
V_49 [ V_52 ] = '\0' ;
V_16 = F_75 ( V_20 , V_49 ) ;
F_74 ( ( unsigned long ) V_49 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_53 += V_52 ;
return V_52 ;
}
static T_1
F_76 ( struct V_50 * V_78 , char T_2 * V_51 , T_3 V_52 ,
T_4 * V_53 )
{
struct V_100 * system = V_78 -> V_79 ;
struct V_94 * V_95 ;
int V_96 ;
if ( * V_53 )
return 0 ;
V_95 = F_67 ( sizeof( * V_95 ) , V_15 ) ;
if ( ! V_95 )
return - V_19 ;
F_68 ( V_95 ) ;
F_77 ( system , V_95 ) ;
V_96 = F_52 ( V_51 , V_52 , V_53 , V_95 -> V_58 , V_95 -> V_97 ) ;
F_7 ( V_95 ) ;
return V_96 ;
}
static T_1
F_78 ( struct V_50 * V_78 , const char T_2 * V_51 , T_3 V_52 ,
T_4 * V_53 )
{
struct V_100 * system = V_78 -> V_79 ;
char * V_49 ;
int V_16 ;
if ( V_52 >= V_98 )
return - V_48 ;
V_49 = ( char * ) F_73 ( V_99 ) ;
if ( ! V_49 )
return - V_19 ;
if ( F_54 ( V_49 , V_51 , V_52 ) ) {
F_74 ( ( unsigned long ) V_49 ) ;
return - V_81 ;
}
V_49 [ V_52 ] = '\0' ;
V_16 = F_79 ( system , V_49 ) ;
F_74 ( ( unsigned long ) V_49 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_53 += V_52 ;
return V_52 ;
}
static T_1
F_80 ( struct V_50 * V_78 , char T_2 * V_51 , T_3 V_52 , T_4 * V_53 )
{
int (* F_81)( struct V_94 * V_95 ) = V_78 -> V_79 ;
struct V_94 * V_95 ;
int V_96 ;
if ( * V_53 )
return 0 ;
V_95 = F_67 ( sizeof( * V_95 ) , V_15 ) ;
if ( ! V_95 )
return - V_19 ;
F_68 ( V_95 ) ;
F_81 ( V_95 ) ;
V_96 = F_52 ( V_51 , V_52 , V_53 , V_95 -> V_58 , V_95 -> V_97 ) ;
F_7 ( V_95 ) ;
return V_96 ;
}
static struct V_101 * F_82 ( void )
{
static struct V_101 * V_102 ;
static struct V_101 * V_103 ;
if ( V_103 )
return V_103 ;
V_102 = F_83 () ;
if ( ! V_102 )
return NULL ;
V_103 = F_84 ( L_16 , V_102 ) ;
if ( ! V_103 )
F_85 ( L_17
L_18 ) ;
return V_103 ;
}
static struct V_101 *
F_86 ( const char * V_8 , struct V_101 * V_103 )
{
struct V_100 * system ;
struct V_101 * V_104 ;
F_23 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_8 , V_8 ) == 0 ) {
system -> V_105 ++ ;
return system -> V_104 ;
}
}
system = F_67 ( sizeof( * system ) , V_15 ) ;
if ( ! system ) {
F_85 ( L_19 ,
V_8 ) ;
return V_103 ;
}
system -> V_104 = F_84 ( V_8 , V_103 ) ;
if ( ! system -> V_104 ) {
F_85 ( L_20 ,
V_8 ) ;
F_7 ( system ) ;
return V_103 ;
}
system -> V_105 = 1 ;
system -> V_8 = F_4 ( V_8 , V_15 ) ;
if ( ! system -> V_8 ) {
F_87 ( system -> V_104 ) ;
F_7 ( system ) ;
return V_103 ;
}
F_6 ( & system -> V_67 , & V_106 ) ;
system -> V_107 = NULL ;
system -> V_107 = F_3 ( sizeof( struct V_108 ) , V_15 ) ;
if ( ! system -> V_107 ) {
F_85 ( L_21
L_22 , V_8 ) ;
return system -> V_104 ;
}
V_104 = F_88 ( L_23 , 0644 , system -> V_104 , system ,
& V_109 ) ;
if ( ! V_104 ) {
F_7 ( system -> V_107 ) ;
system -> V_107 = NULL ;
F_85 ( L_17
L_24 , V_8 ) ;
}
F_89 ( L_25 , 0644 , system -> V_104 ,
( void * ) system -> V_8 ,
& V_110 ) ;
return system -> V_104 ;
}
static int
F_90 ( struct V_2 * V_20 , struct V_101 * V_103 ,
const struct V_111 * V_27 ,
const struct V_111 * V_37 ,
const struct V_111 * V_107 ,
const struct V_111 * V_112 )
{
struct V_1 * V_7 ;
int V_21 ;
if ( strcmp ( V_20 -> V_4 -> system , V_68 ) != 0 )
V_103 = F_86 ( V_20 -> V_4 -> system , V_103 ) ;
V_20 -> V_113 = F_84 ( V_20 -> V_8 , V_103 ) ;
if ( ! V_20 -> V_113 ) {
F_85 ( L_17
L_26 , V_20 -> V_8 ) ;
return - 1 ;
}
if ( V_20 -> V_4 -> V_42 )
F_89 ( L_25 , 0644 , V_20 -> V_113 , V_20 ,
V_37 ) ;
#ifdef F_20
if ( V_20 -> V_28 . type && V_20 -> V_4 -> V_42 )
F_89 ( L_27 , 0444 , V_20 -> V_113 , V_20 ,
V_27 ) ;
#endif
V_7 = F_1 ( V_20 ) ;
if ( F_60 ( V_7 ) ) {
V_21 = V_20 -> V_4 -> V_114 ( V_20 ) ;
if ( V_21 < 0 ) {
F_85 ( L_28
L_29 , V_20 -> V_8 ) ;
return V_21 ;
}
}
F_89 ( L_23 , 0644 , V_20 -> V_113 , V_20 ,
V_107 ) ;
F_89 ( L_30 , 0444 , V_20 -> V_113 , V_20 ,
V_112 ) ;
return 0 ;
}
static int
F_91 ( struct V_2 * V_20 , struct V_115 * V_116 ,
const struct V_111 * V_27 ,
const struct V_111 * V_37 ,
const struct V_111 * V_107 ,
const struct V_111 * V_112 )
{
struct V_101 * V_103 ;
int V_21 ;
if ( ! V_20 -> V_8 )
return - V_48 ;
if ( V_20 -> V_4 -> V_117 ) {
V_21 = V_20 -> V_4 -> V_117 ( V_20 ) ;
if ( V_21 < 0 ) {
if ( V_21 != - V_118 )
F_85 ( L_31 ,
V_20 -> V_8 ) ;
return V_21 ;
}
}
V_103 = F_82 () ;
if ( ! V_103 )
return - V_119 ;
V_21 = F_90 ( V_20 , V_103 , V_27 , V_37 , V_107 , V_112 ) ;
if ( ! V_21 )
F_6 ( & V_20 -> V_67 , & V_66 ) ;
V_20 -> V_116 = V_116 ;
return V_21 ;
}
int F_92 ( struct V_2 * V_20 )
{
int V_21 ;
F_22 ( & V_38 ) ;
V_21 = F_91 ( V_20 , NULL , & V_120 ,
& V_121 ,
& V_122 ,
& V_123 ) ;
F_26 ( & V_38 ) ;
return V_21 ;
}
static void F_93 ( const char * V_8 )
{
struct V_100 * system ;
if ( strcmp ( V_8 , V_68 ) == 0 )
return;
F_23 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_8 , V_8 ) == 0 ) {
if ( ! -- system -> V_105 ) {
struct V_108 * V_107 = system -> V_107 ;
F_94 ( system -> V_104 ) ;
F_14 ( & system -> V_67 ) ;
if ( V_107 ) {
F_7 ( V_107 -> V_124 ) ;
F_7 ( V_107 ) ;
}
F_7 ( system -> V_8 ) ;
F_7 ( system ) ;
}
break;
}
}
}
static void F_95 ( struct V_2 * V_20 )
{
F_27 ( V_20 , 0 ) ;
if ( V_20 -> V_28 . V_125 )
F_96 ( & V_20 -> V_28 ) ;
F_94 ( V_20 -> V_113 ) ;
F_14 ( & V_20 -> V_67 ) ;
F_12 ( V_20 ) ;
F_97 ( V_20 ) ;
F_93 ( V_20 -> V_4 -> system ) ;
}
void F_98 ( struct V_2 * V_20 )
{
F_22 ( & V_38 ) ;
F_99 ( & V_126 ) ;
F_95 ( V_20 ) ;
F_100 ( & V_126 ) ;
F_26 ( & V_38 ) ;
}
static struct V_127 *
F_101 ( struct V_115 * V_116 )
{
struct V_127 * V_128 ;
V_128 = F_67 ( sizeof( * V_128 ) , V_15 ) ;
if ( ! V_128 )
return NULL ;
V_128 -> V_116 = V_116 ;
V_128 -> V_27 = V_120 ;
V_128 -> V_27 . V_129 = V_116 ;
V_128 -> V_37 = V_121 ;
V_128 -> V_37 . V_129 = V_116 ;
V_128 -> V_107 = V_122 ;
V_128 -> V_107 . V_129 = V_116 ;
V_128 -> V_112 = V_123 ;
V_128 -> V_112 . V_129 = V_116 ;
F_6 ( & V_128 -> V_67 , & V_130 ) ;
return V_128 ;
}
static void F_102 ( struct V_115 * V_116 )
{
struct V_127 * V_128 = NULL ;
struct V_2 * * V_20 , * * V_131 , * * V_132 ;
V_131 = V_116 -> V_133 ;
V_132 = V_116 -> V_133 + V_116 -> V_134 ;
if ( V_131 == V_132 )
return;
V_128 = F_101 ( V_116 ) ;
if ( ! V_128 )
return;
F_103 (call, start, end) {
F_91 ( * V_20 , V_116 ,
& V_128 -> V_27 , & V_128 -> V_37 ,
& V_128 -> V_107 , & V_128 -> V_112 ) ;
}
}
static void F_104 ( struct V_115 * V_116 )
{
struct V_127 * V_128 ;
struct V_2 * V_20 , * V_69 ;
bool V_135 = false ;
F_99 ( & V_126 ) ;
F_13 (call, p, &ftrace_events, list) {
if ( V_20 -> V_116 == V_116 ) {
V_135 = true ;
F_95 ( V_20 ) ;
}
}
F_23 (file_ops, &ftrace_module_file_list, list) {
if ( V_128 -> V_116 == V_116 )
break;
}
if ( & V_128 -> V_67 != & V_130 ) {
F_14 ( & V_128 -> V_67 ) ;
F_7 ( V_128 ) ;
}
if ( V_135 )
F_105 () ;
F_100 ( & V_126 ) ;
}
static int F_106 ( struct V_136 * V_137 ,
unsigned long V_80 , void * V_138 )
{
struct V_115 * V_116 = V_138 ;
F_22 ( & V_38 ) ;
switch ( V_80 ) {
case V_139 :
F_102 ( V_116 ) ;
break;
case V_140 :
F_104 ( V_116 ) ;
break;
}
F_26 ( & V_38 ) ;
return 0 ;
}
static int F_106 ( struct V_136 * V_137 ,
unsigned long V_80 , void * V_138 )
{
return 0 ;
}
static T_5 int F_107 ( char * V_141 )
{
F_108 ( V_142 , V_141 , V_143 ) ;
V_144 = 1 ;
V_145 = 1 ;
return 1 ;
}
static T_5 int F_109 ( void )
{
struct V_2 * * V_20 ;
struct V_101 * V_102 ;
struct V_101 * V_104 ;
struct V_101 * V_103 ;
int V_21 ;
char * V_49 = V_142 ;
char * V_146 ;
V_102 = F_83 () ;
if ( ! V_102 )
return 0 ;
V_104 = F_88 ( L_32 , 0444 , V_102 ,
( void * ) & V_147 ,
& V_148 ) ;
if ( ! V_104 )
F_85 ( L_17
L_33 ) ;
V_104 = F_88 ( L_34 , 0644 , V_102 ,
( void * ) & V_149 ,
& V_150 ) ;
if ( ! V_104 )
F_85 ( L_17
L_35 ) ;
V_103 = F_82 () ;
if ( ! V_103 )
return 0 ;
F_89 ( L_36 , 0444 , V_103 ,
V_151 ,
& V_152 ) ;
F_89 ( L_37 , 0444 , V_103 ,
V_153 ,
& V_152 ) ;
F_89 ( L_25 , 0644 , V_103 ,
NULL , & V_110 ) ;
if ( F_10 () )
F_85 ( L_38 ) ;
F_103 (call, __start_ftrace_events, __stop_ftrace_events) {
F_91 ( * V_20 , NULL , & V_120 ,
& V_121 ,
& V_122 ,
& V_123 ) ;
}
while ( true ) {
V_146 = F_32 ( & V_49 , L_39 ) ;
if ( ! V_146 )
break;
if ( ! * V_146 )
continue;
V_21 = F_31 ( V_146 , 1 ) ;
if ( V_21 )
F_85 ( L_40 , V_146 ) ;
}
V_21 = F_110 ( & V_154 ) ;
if ( V_21 )
F_85 ( L_41 ) ;
return 0 ;
}
static T_5 void F_111 ( struct V_155 * V_156 )
{
F_112 ( & V_157 ) ;
F_113 ( & V_158 ) ;
F_114 ( 1 ) ;
F_115 ( & V_158 ) ;
F_116 ( & V_157 ) ;
F_22 ( & V_159 ) ;
F_117 ( 1 ) ;
F_26 ( & V_159 ) ;
}
static T_5 int F_118 ( void * V_160 )
{
void * V_161 ;
V_161 = F_67 ( 1234 , V_15 ) ;
if ( ! V_161 )
F_28 ( L_42 ) ;
F_119 ( F_111 ) ;
F_7 ( V_161 ) ;
F_120 ( V_162 ) ;
while ( ! F_121 () )
F_122 () ;
return 0 ;
}
static T_5 void F_123 ( void )
{
struct V_163 * V_164 ;
V_164 = F_124 ( F_118 , NULL , L_43 ) ;
F_117 ( 1 ) ;
F_125 ( V_164 ) ;
}
static T_5 void F_126 ( void )
{
struct V_2 * V_20 ;
struct V_100 * system ;
int V_21 ;
F_28 ( L_44 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_4 || ! V_20 -> V_4 -> V_32 )
continue;
#ifndef F_127
if ( V_20 -> V_4 -> system &&
strcmp ( V_20 -> V_4 -> system , L_45 ) == 0 )
continue;
#endif
F_28 ( L_46 , V_20 -> V_8 ) ;
if ( V_20 -> V_39 & V_40 ) {
F_85 ( L_47 ) ;
F_128 ( 1 ) ;
continue;
}
F_27 ( V_20 , 1 ) ;
F_123 () ;
F_27 ( V_20 , 0 ) ;
F_129 ( L_48 ) ;
}
F_28 ( L_49 ) ;
F_23 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_8 , L_50 ) == 0 )
continue;
F_28 ( L_51 , system -> V_8 ) ;
V_21 = F_30 ( NULL , system -> V_8 , NULL , 1 ) ;
if ( F_128 ( V_21 ) ) {
F_85 ( L_52 ,
system -> V_8 ) ;
continue;
}
F_123 () ;
V_21 = F_30 ( NULL , system -> V_8 , NULL , 0 ) ;
if ( F_128 ( V_21 ) )
F_85 ( L_53 ,
system -> V_8 ) ;
F_129 ( L_48 ) ;
}
F_28 ( L_54 ) ;
F_28 ( L_55 ) ;
V_21 = F_30 ( NULL , NULL , NULL , 1 ) ;
if ( F_128 ( V_21 ) ) {
F_85 ( L_56 ) ;
return;
}
F_123 () ;
V_21 = F_30 ( NULL , NULL , NULL , 0 ) ;
if ( F_128 ( V_21 ) ) {
F_85 ( L_57 ) ;
return;
}
F_129 ( L_48 ) ;
}
static void
F_130 ( unsigned long V_165 , unsigned long V_166 )
{
struct V_167 * V_28 ;
struct V_168 * V_58 ;
struct V_169 * V_104 ;
unsigned long V_39 ;
long V_170 ;
int V_171 ;
int V_172 ;
V_172 = F_131 () ;
F_132 () ;
V_171 = F_133 () ;
V_170 = F_134 ( & F_135 ( V_173 , V_171 ) ) ;
if ( V_170 != 1 )
goto V_83;
F_136 ( V_39 ) ;
V_28 = F_137 ( & V_58 ,
V_174 , sizeof( * V_104 ) ,
V_39 , V_172 ) ;
if ( ! V_28 )
goto V_83;
V_104 = F_138 ( V_28 ) ;
V_104 -> V_165 = V_165 ;
V_104 -> V_166 = V_166 ;
F_139 ( V_58 , V_28 , V_39 , V_172 ) ;
V_83:
F_140 ( & F_135 ( V_173 , V_171 ) ) ;
F_141 () ;
}
static T_5 void F_142 ( void )
{
int V_21 ;
V_21 = F_143 ( & V_175 ) ;
if ( F_9 ( V_21 < 0 ) ) {
F_28 ( L_58 ) ;
return;
}
F_28 ( L_59 ) ;
F_126 () ;
F_144 ( & V_175 ) ;
}
static T_5 void F_142 ( void )
{
}
static T_5 int F_145 ( void )
{
if ( ! V_145 ) {
F_126 () ;
F_142 () ;
}
return 0 ;
}
