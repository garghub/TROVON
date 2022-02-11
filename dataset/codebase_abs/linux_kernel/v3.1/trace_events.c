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
static void F_30 ( struct V_45 * system )
{
struct V_46 * V_47 = system -> V_47 ;
F_31 ( system -> V_48 == 0 ) ;
if ( -- system -> V_48 )
return;
if ( V_47 ) {
F_7 ( V_47 -> V_49 ) ;
F_7 ( V_47 ) ;
}
F_7 ( system -> V_8 ) ;
F_7 ( system ) ;
}
static void F_32 ( struct V_45 * system )
{
F_31 ( system -> V_48 == 0 ) ;
system -> V_48 ++ ;
}
static void F_33 ( struct V_45 * system )
{
F_22 ( & V_38 ) ;
F_30 ( system ) ;
F_26 ( & V_38 ) ;
}
static int F_34 ( const char * V_50 , const char * V_51 ,
const char * V_28 , int V_52 )
{
struct V_2 * V_20 ;
int V_21 = - V_53 ;
F_22 ( & V_38 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_8 || ! V_20 -> V_4 || ! V_20 -> V_4 -> V_42 )
continue;
if ( V_50 &&
strcmp ( V_50 , V_20 -> V_8 ) != 0 &&
strcmp ( V_50 , V_20 -> V_4 -> system ) != 0 )
continue;
if ( V_51 && strcmp ( V_51 , V_20 -> V_4 -> system ) != 0 )
continue;
if ( V_28 && strcmp ( V_28 , V_20 -> V_8 ) != 0 )
continue;
F_27 ( V_20 , V_52 ) ;
V_21 = 0 ;
}
F_26 ( & V_38 ) ;
return V_21 ;
}
static int F_35 ( char * V_54 , int V_52 )
{
char * V_28 = NULL , * V_51 = NULL , * V_50 ;
V_50 = F_36 ( & V_54 , L_3 ) ;
if ( V_54 ) {
V_51 = V_50 ;
V_28 = V_54 ;
V_50 = NULL ;
if ( ! strlen ( V_51 ) || strcmp ( V_51 , L_4 ) == 0 )
V_51 = NULL ;
if ( ! strlen ( V_28 ) || strcmp ( V_28 , L_4 ) == 0 )
V_28 = NULL ;
}
return F_34 ( V_50 , V_51 , V_28 , V_52 ) ;
}
int F_37 ( const char * system , const char * V_28 , int V_52 )
{
return F_34 ( NULL , system , V_28 , V_52 ) ;
}
static T_1
F_38 ( struct V_55 * V_55 , const char T_2 * V_56 ,
T_3 V_57 , T_4 * V_58 )
{
struct V_59 V_60 ;
T_1 V_61 , V_21 ;
if ( ! V_57 )
return 0 ;
V_21 = F_39 () ;
if ( V_21 < 0 )
return V_21 ;
if ( F_40 ( & V_60 , V_62 + 1 ) )
return - V_19 ;
V_61 = F_41 ( & V_60 , V_56 , V_57 , V_58 ) ;
if ( V_61 >= 0 && F_42 ( ( & V_60 ) ) ) {
int V_52 = 1 ;
if ( * V_60 . V_63 == '!' )
V_52 = 0 ;
V_60 . V_63 [ V_60 . V_64 ] = 0 ;
V_21 = F_35 ( V_60 . V_63 + ! V_52 , V_52 ) ;
if ( V_21 )
goto V_65;
}
V_21 = V_61 ;
V_65:
F_43 ( & V_60 ) ;
return V_21 ;
}
static void *
F_44 ( struct V_66 * V_67 , void * V_68 , T_4 * V_69 )
{
struct V_2 * V_20 = V_68 ;
( * V_69 ) ++ ;
F_45 (call, &ftrace_events, list) {
if ( V_20 -> V_4 && V_20 -> V_4 -> V_42 )
return V_20 ;
}
return NULL ;
}
static void * F_46 ( struct V_66 * V_67 , T_4 * V_69 )
{
struct V_2 * V_20 ;
T_4 V_70 ;
F_22 ( & V_38 ) ;
V_20 = F_47 ( & V_71 , struct V_2 , V_72 ) ;
for ( V_70 = 0 ; V_70 <= * V_69 ; ) {
V_20 = F_44 ( V_67 , V_20 , & V_70 ) ;
if ( ! V_20 )
break;
}
return V_20 ;
}
static void *
F_48 ( struct V_66 * V_67 , void * V_68 , T_4 * V_69 )
{
struct V_2 * V_20 = V_68 ;
( * V_69 ) ++ ;
F_45 (call, &ftrace_events, list) {
if ( V_20 -> V_39 & V_40 )
return V_20 ;
}
return NULL ;
}
static void * F_49 ( struct V_66 * V_67 , T_4 * V_69 )
{
struct V_2 * V_20 ;
T_4 V_70 ;
F_22 ( & V_38 ) ;
V_20 = F_47 ( & V_71 , struct V_2 , V_72 ) ;
for ( V_70 = 0 ; V_70 <= * V_69 ; ) {
V_20 = F_48 ( V_67 , V_20 , & V_70 ) ;
if ( ! V_20 )
break;
}
return V_20 ;
}
static int F_50 ( struct V_66 * V_67 , void * V_68 )
{
struct V_2 * V_20 = V_68 ;
if ( strcmp ( V_20 -> V_4 -> system , V_73 ) != 0 )
F_51 ( V_67 , L_5 , V_20 -> V_4 -> system ) ;
F_51 ( V_67 , L_2 , V_20 -> V_8 ) ;
return 0 ;
}
static void F_52 ( struct V_66 * V_67 , void * V_74 )
{
F_26 ( & V_38 ) ;
}
static int
F_53 ( struct V_75 * V_75 , struct V_55 * V_55 )
{
const struct V_76 * V_77 ;
if ( ( V_55 -> V_78 & V_79 ) &&
( V_55 -> V_80 & V_81 ) )
F_29 () ;
V_77 = V_75 -> V_82 ;
return F_54 ( V_55 , V_77 ) ;
}
static T_1
F_55 ( struct V_55 * V_83 , char T_2 * V_56 , T_3 V_57 ,
T_4 * V_58 )
{
struct V_2 * V_20 = V_83 -> V_84 ;
char * V_54 ;
if ( V_20 -> V_39 & V_40 )
V_54 = L_6 ;
else
V_54 = L_7 ;
return F_56 ( V_56 , V_57 , V_58 , V_54 , 2 ) ;
}
static T_1
F_57 ( struct V_55 * V_83 , const char T_2 * V_56 , T_3 V_57 ,
T_4 * V_58 )
{
struct V_2 * V_20 = V_83 -> V_84 ;
unsigned long V_85 ;
int V_21 ;
V_21 = F_58 ( V_56 , V_57 , 10 , & V_85 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_39 () ;
if ( V_21 < 0 )
return V_21 ;
switch ( V_85 ) {
case 0 :
case 1 :
F_22 ( & V_38 ) ;
V_21 = F_27 ( V_20 , V_85 ) ;
F_26 ( & V_38 ) ;
break;
default:
return - V_53 ;
}
* V_58 += V_57 ;
return V_21 ? V_21 : V_57 ;
}
static T_1
F_59 ( struct V_55 * V_83 , char T_2 * V_56 , T_3 V_57 ,
T_4 * V_58 )
{
const char V_86 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_45 * system = V_83 -> V_84 ;
struct V_2 * V_20 ;
char V_54 [ 2 ] ;
int V_52 = 0 ;
int V_21 ;
F_22 ( & V_38 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_8 || ! V_20 -> V_4 || ! V_20 -> V_4 -> V_42 )
continue;
if ( system && strcmp ( V_20 -> V_4 -> system , system -> V_8 ) != 0 )
continue;
V_52 |= ( 1 << ! ! ( V_20 -> V_39 & V_40 ) ) ;
if ( V_52 == 3 )
break;
}
F_26 ( & V_38 ) ;
V_54 [ 0 ] = V_86 [ V_52 ] ;
V_54 [ 1 ] = '\n' ;
V_21 = F_56 ( V_56 , V_57 , V_58 , V_54 , 2 ) ;
return V_21 ;
}
static T_1
F_60 ( struct V_55 * V_83 , const char T_2 * V_56 , T_3 V_57 ,
T_4 * V_58 )
{
struct V_45 * system = V_83 -> V_84 ;
const char * V_8 = NULL ;
unsigned long V_85 ;
T_1 V_21 ;
V_21 = F_58 ( V_56 , V_57 , 10 , & V_85 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_39 () ;
if ( V_21 < 0 )
return V_21 ;
if ( V_85 != 0 && V_85 != 1 )
return - V_53 ;
if ( system )
V_8 = system -> V_8 ;
V_21 = F_34 ( NULL , V_8 , NULL , V_85 ) ;
if ( V_21 )
goto V_87;
V_21 = V_57 ;
V_87:
* V_58 += V_57 ;
return V_21 ;
}
static void * F_61 ( struct V_66 * V_67 , void * V_68 , T_4 * V_69 )
{
struct V_2 * V_20 = V_67 -> V_88 ;
struct V_13 * V_14 ;
struct V_1 * V_89 = & V_90 ;
struct V_1 * V_7 = F_1 ( V_20 ) ;
( * V_69 ) ++ ;
switch ( ( unsigned long ) V_68 ) {
case V_91 :
if ( F_62 ( F_63 ( V_89 ) ) )
return NULL ;
V_14 = F_47 ( V_89 -> V_92 ,
struct V_13 , V_18 ) ;
return V_14 ;
case V_93 :
if ( F_62 ( F_63 ( V_7 ) ) )
return NULL ;
V_14 = F_47 ( V_7 -> V_92 , struct V_13 , V_18 ) ;
return V_14 ;
case V_94 :
return NULL ;
}
V_14 = V_68 ;
if ( V_14 -> V_18 . V_92 == V_89 )
return ( void * ) V_93 ;
else if ( V_14 -> V_18 . V_92 == V_7 )
return ( void * ) V_94 ;
V_14 = F_47 ( V_14 -> V_18 . V_92 , struct V_13 , V_18 ) ;
return V_14 ;
}
static void * F_64 ( struct V_66 * V_67 , T_4 * V_69 )
{
T_4 V_70 = 0 ;
void * V_74 ;
if ( ! * V_69 )
return ( void * ) V_91 ;
V_74 = ( void * ) V_91 ;
do {
V_74 = F_61 ( V_67 , V_74 , & V_70 ) ;
} while ( V_74 && V_70 < * V_69 );
return V_74 ;
}
static int F_65 ( struct V_66 * V_67 , void * V_68 )
{
struct V_2 * V_20 = V_67 -> V_88 ;
struct V_13 * V_14 ;
const char * V_95 ;
switch ( ( unsigned long ) V_68 ) {
case V_91 :
F_51 ( V_67 , L_8 , V_20 -> V_8 ) ;
F_51 ( V_67 , L_9 , V_20 -> V_28 . type ) ;
F_51 ( V_67 , L_10 ) ;
return 0 ;
case V_93 :
F_66 ( V_67 , '\n' ) ;
return 0 ;
case V_94 :
F_51 ( V_67 , L_11 ,
V_20 -> V_96 ) ;
return 0 ;
}
V_14 = V_68 ;
V_95 = strchr ( V_14 -> type , '[' ) ;
if ( ! strncmp ( V_14 -> type , L_12 , 10 ) )
V_95 = NULL ;
if ( ! V_95 )
F_51 ( V_67 , L_13 ,
V_14 -> type , V_14 -> V_8 , V_14 -> V_9 ,
V_14 -> V_10 , ! ! V_14 -> V_11 ) ;
else
F_51 ( V_67 , L_14 ,
( int ) ( V_95 - V_14 -> type ) ,
V_14 -> type , V_14 -> V_8 ,
V_95 , V_14 -> V_9 ,
V_14 -> V_10 , ! ! V_14 -> V_11 ) ;
return 0 ;
}
static void F_67 ( struct V_66 * V_67 , void * V_74 )
{
}
static int F_68 ( struct V_75 * V_75 , struct V_55 * V_55 )
{
struct V_2 * V_20 = V_75 -> V_82 ;
struct V_66 * V_67 ;
int V_21 ;
V_21 = F_54 ( V_55 , & V_97 ) ;
if ( V_21 < 0 )
return V_21 ;
V_67 = V_55 -> V_84 ;
V_67 -> V_88 = V_20 ;
return 0 ;
}
static T_1
F_69 ( struct V_55 * V_83 , char T_2 * V_56 , T_3 V_57 , T_4 * V_58 )
{
struct V_2 * V_20 = V_83 -> V_84 ;
struct V_98 * V_99 ;
int V_100 ;
if ( * V_58 )
return 0 ;
V_99 = F_70 ( sizeof( * V_99 ) , V_15 ) ;
if ( ! V_99 )
return - V_19 ;
F_71 ( V_99 ) ;
F_72 ( V_99 , L_15 , V_20 -> V_28 . type ) ;
V_100 = F_56 ( V_56 , V_57 , V_58 ,
V_99 -> V_63 , V_99 -> V_101 ) ;
F_7 ( V_99 ) ;
return V_100 ;
}
static T_1
F_73 ( struct V_55 * V_83 , char T_2 * V_56 , T_3 V_57 ,
T_4 * V_58 )
{
struct V_2 * V_20 = V_83 -> V_84 ;
struct V_98 * V_99 ;
int V_100 ;
if ( * V_58 )
return 0 ;
V_99 = F_70 ( sizeof( * V_99 ) , V_15 ) ;
if ( ! V_99 )
return - V_19 ;
F_71 ( V_99 ) ;
F_74 ( V_20 , V_99 ) ;
V_100 = F_56 ( V_56 , V_57 , V_58 , V_99 -> V_63 , V_99 -> V_101 ) ;
F_7 ( V_99 ) ;
return V_100 ;
}
static T_1
F_75 ( struct V_55 * V_83 , const char T_2 * V_56 , T_3 V_57 ,
T_4 * V_58 )
{
struct V_2 * V_20 = V_83 -> V_84 ;
char * V_54 ;
int V_16 ;
if ( V_57 >= V_102 )
return - V_53 ;
V_54 = ( char * ) F_76 ( V_103 ) ;
if ( ! V_54 )
return - V_19 ;
if ( F_77 ( V_54 , V_56 , V_57 ) ) {
F_78 ( ( unsigned long ) V_54 ) ;
return - V_104 ;
}
V_54 [ V_57 ] = '\0' ;
V_16 = F_79 ( V_20 , V_54 ) ;
F_78 ( ( unsigned long ) V_54 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_58 += V_57 ;
return V_57 ;
}
static int F_80 ( struct V_75 * V_75 , struct V_55 * V_83 )
{
struct V_45 * system = NULL ;
int V_21 ;
if ( ! V_75 -> V_82 )
goto V_105;
F_22 ( & V_38 ) ;
F_23 (system, &event_subsystems, list) {
if ( system == V_75 -> V_82 ) {
if ( ! system -> V_106 ) {
system = NULL ;
break;
}
F_32 ( system ) ;
break;
}
}
F_26 ( & V_38 ) ;
if ( system != V_75 -> V_82 )
return - V_29 ;
V_105:
V_21 = F_81 ( V_75 , V_83 ) ;
if ( V_21 < 0 && system )
F_33 ( system ) ;
return V_21 ;
}
static int F_82 ( struct V_75 * V_75 , struct V_55 * V_55 )
{
struct V_45 * system = V_75 -> V_82 ;
if ( system )
F_33 ( system ) ;
return 0 ;
}
static T_1
F_83 ( struct V_55 * V_83 , char T_2 * V_56 , T_3 V_57 ,
T_4 * V_58 )
{
struct V_45 * system = V_83 -> V_84 ;
struct V_98 * V_99 ;
int V_100 ;
if ( * V_58 )
return 0 ;
V_99 = F_70 ( sizeof( * V_99 ) , V_15 ) ;
if ( ! V_99 )
return - V_19 ;
F_71 ( V_99 ) ;
F_84 ( system , V_99 ) ;
V_100 = F_56 ( V_56 , V_57 , V_58 , V_99 -> V_63 , V_99 -> V_101 ) ;
F_7 ( V_99 ) ;
return V_100 ;
}
static T_1
F_85 ( struct V_55 * V_83 , const char T_2 * V_56 , T_3 V_57 ,
T_4 * V_58 )
{
struct V_45 * system = V_83 -> V_84 ;
char * V_54 ;
int V_16 ;
if ( V_57 >= V_102 )
return - V_53 ;
V_54 = ( char * ) F_76 ( V_103 ) ;
if ( ! V_54 )
return - V_19 ;
if ( F_77 ( V_54 , V_56 , V_57 ) ) {
F_78 ( ( unsigned long ) V_54 ) ;
return - V_104 ;
}
V_54 [ V_57 ] = '\0' ;
V_16 = F_86 ( system , V_54 ) ;
F_78 ( ( unsigned long ) V_54 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_58 += V_57 ;
return V_57 ;
}
static T_1
F_87 ( struct V_55 * V_83 , char T_2 * V_56 , T_3 V_57 , T_4 * V_58 )
{
int (* F_88)( struct V_98 * V_99 ) = V_83 -> V_84 ;
struct V_98 * V_99 ;
int V_100 ;
if ( * V_58 )
return 0 ;
V_99 = F_70 ( sizeof( * V_99 ) , V_15 ) ;
if ( ! V_99 )
return - V_19 ;
F_71 ( V_99 ) ;
F_88 ( V_99 ) ;
V_100 = F_56 ( V_56 , V_57 , V_58 , V_99 -> V_63 , V_99 -> V_101 ) ;
F_7 ( V_99 ) ;
return V_100 ;
}
static struct V_107 * F_89 ( void )
{
static struct V_107 * V_108 ;
static struct V_107 * V_109 ;
if ( V_109 )
return V_109 ;
V_108 = F_90 () ;
if ( ! V_108 )
return NULL ;
V_109 = F_91 ( L_16 , V_108 ) ;
if ( ! V_109 )
F_92 ( L_17
L_18 ) ;
return V_109 ;
}
static struct V_107 *
F_93 ( const char * V_8 , struct V_107 * V_109 )
{
struct V_45 * system ;
struct V_107 * V_110 ;
F_23 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_8 , V_8 ) == 0 ) {
F_32 ( system ) ;
system -> V_106 ++ ;
return system -> V_110 ;
}
}
system = F_70 ( sizeof( * system ) , V_15 ) ;
if ( ! system ) {
F_92 ( L_19 ,
V_8 ) ;
return V_109 ;
}
system -> V_110 = F_91 ( V_8 , V_109 ) ;
if ( ! system -> V_110 ) {
F_92 ( L_20 ,
V_8 ) ;
F_7 ( system ) ;
return V_109 ;
}
system -> V_106 = 1 ;
system -> V_48 = 1 ;
system -> V_8 = F_4 ( V_8 , V_15 ) ;
if ( ! system -> V_8 ) {
F_94 ( system -> V_110 ) ;
F_7 ( system ) ;
return V_109 ;
}
F_6 ( & system -> V_72 , & V_111 ) ;
system -> V_47 = NULL ;
system -> V_47 = F_3 ( sizeof( struct V_46 ) , V_15 ) ;
if ( ! system -> V_47 ) {
F_92 ( L_21
L_22 , V_8 ) ;
return system -> V_110 ;
}
V_110 = F_95 ( L_23 , 0644 , system -> V_110 , system ,
& V_112 ) ;
if ( ! V_110 ) {
F_7 ( system -> V_47 ) ;
system -> V_47 = NULL ;
F_92 ( L_17
L_24 , V_8 ) ;
}
F_96 ( L_25 , 0644 , system -> V_110 , system ,
& V_113 ) ;
return system -> V_110 ;
}
static int
F_97 ( struct V_2 * V_20 , struct V_107 * V_109 ,
const struct V_114 * V_27 ,
const struct V_114 * V_37 ,
const struct V_114 * V_47 ,
const struct V_114 * V_115 )
{
struct V_1 * V_7 ;
int V_21 ;
if ( strcmp ( V_20 -> V_4 -> system , V_73 ) != 0 )
V_109 = F_93 ( V_20 -> V_4 -> system , V_109 ) ;
V_20 -> V_116 = F_91 ( V_20 -> V_8 , V_109 ) ;
if ( ! V_20 -> V_116 ) {
F_92 ( L_17
L_26 , V_20 -> V_8 ) ;
return - 1 ;
}
if ( V_20 -> V_4 -> V_42 )
F_96 ( L_25 , 0644 , V_20 -> V_116 , V_20 ,
V_37 ) ;
#ifdef F_20
if ( V_20 -> V_28 . type && V_20 -> V_4 -> V_42 )
F_96 ( L_27 , 0444 , V_20 -> V_116 , V_20 ,
V_27 ) ;
#endif
V_7 = F_1 ( V_20 ) ;
if ( F_63 ( V_7 ) ) {
V_21 = V_20 -> V_4 -> V_117 ( V_20 ) ;
if ( V_21 < 0 ) {
F_92 ( L_28
L_29 , V_20 -> V_8 ) ;
return V_21 ;
}
}
F_96 ( L_23 , 0644 , V_20 -> V_116 , V_20 ,
V_47 ) ;
F_96 ( L_30 , 0444 , V_20 -> V_116 , V_20 ,
V_115 ) ;
return 0 ;
}
static int
F_98 ( struct V_2 * V_20 , struct V_118 * V_119 ,
const struct V_114 * V_27 ,
const struct V_114 * V_37 ,
const struct V_114 * V_47 ,
const struct V_114 * V_115 )
{
struct V_107 * V_109 ;
int V_21 ;
if ( ! V_20 -> V_8 )
return - V_53 ;
if ( V_20 -> V_4 -> V_120 ) {
V_21 = V_20 -> V_4 -> V_120 ( V_20 ) ;
if ( V_21 < 0 ) {
if ( V_21 != - V_121 )
F_92 ( L_31 ,
V_20 -> V_8 ) ;
return V_21 ;
}
}
V_109 = F_89 () ;
if ( ! V_109 )
return - V_122 ;
V_21 = F_97 ( V_20 , V_109 , V_27 , V_37 , V_47 , V_115 ) ;
if ( ! V_21 )
F_6 ( & V_20 -> V_72 , & V_71 ) ;
V_20 -> V_119 = V_119 ;
return V_21 ;
}
int F_99 ( struct V_2 * V_20 )
{
int V_21 ;
F_22 ( & V_38 ) ;
V_21 = F_98 ( V_20 , NULL , & V_123 ,
& V_124 ,
& V_125 ,
& V_126 ) ;
F_26 ( & V_38 ) ;
return V_21 ;
}
static void F_100 ( const char * V_8 )
{
struct V_45 * system ;
if ( strcmp ( V_8 , V_73 ) == 0 )
return;
F_23 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_8 , V_8 ) == 0 ) {
if ( ! -- system -> V_106 ) {
F_101 ( system -> V_110 ) ;
F_14 ( & system -> V_72 ) ;
F_30 ( system ) ;
}
break;
}
}
}
static void F_102 ( struct V_2 * V_20 )
{
F_27 ( V_20 , 0 ) ;
if ( V_20 -> V_28 . V_127 )
F_103 ( & V_20 -> V_28 ) ;
F_101 ( V_20 -> V_116 ) ;
F_14 ( & V_20 -> V_72 ) ;
F_12 ( V_20 ) ;
F_104 ( V_20 ) ;
F_100 ( V_20 -> V_4 -> system ) ;
}
void F_105 ( struct V_2 * V_20 )
{
F_22 ( & V_38 ) ;
F_106 ( & V_128 ) ;
F_102 ( V_20 ) ;
F_107 ( & V_128 ) ;
F_26 ( & V_38 ) ;
}
static struct V_129 *
F_108 ( struct V_118 * V_119 )
{
struct V_129 * V_130 ;
V_130 = F_70 ( sizeof( * V_130 ) , V_15 ) ;
if ( ! V_130 )
return NULL ;
V_130 -> V_119 = V_119 ;
V_130 -> V_27 = V_123 ;
V_130 -> V_27 . V_131 = V_119 ;
V_130 -> V_37 = V_124 ;
V_130 -> V_37 . V_131 = V_119 ;
V_130 -> V_47 = V_125 ;
V_130 -> V_47 . V_131 = V_119 ;
V_130 -> V_115 = V_126 ;
V_130 -> V_115 . V_131 = V_119 ;
F_6 ( & V_130 -> V_72 , & V_132 ) ;
return V_130 ;
}
static void F_109 ( struct V_118 * V_119 )
{
struct V_129 * V_130 = NULL ;
struct V_2 * * V_20 , * * V_133 , * * V_134 ;
V_133 = V_119 -> V_135 ;
V_134 = V_119 -> V_135 + V_119 -> V_136 ;
if ( V_133 == V_134 )
return;
V_130 = F_108 ( V_119 ) ;
if ( ! V_130 )
return;
F_110 (call, start, end) {
F_98 ( * V_20 , V_119 ,
& V_130 -> V_27 , & V_130 -> V_37 ,
& V_130 -> V_47 , & V_130 -> V_115 ) ;
}
}
static void F_111 ( struct V_118 * V_119 )
{
struct V_129 * V_130 ;
struct V_2 * V_20 , * V_74 ;
bool V_137 = false ;
F_106 ( & V_128 ) ;
F_13 (call, p, &ftrace_events, list) {
if ( V_20 -> V_119 == V_119 ) {
V_137 = true ;
F_102 ( V_20 ) ;
}
}
F_23 (file_ops, &ftrace_module_file_list, list) {
if ( V_130 -> V_119 == V_119 )
break;
}
if ( & V_130 -> V_72 != & V_132 ) {
F_14 ( & V_130 -> V_72 ) ;
F_7 ( V_130 ) ;
}
if ( V_137 )
F_112 () ;
F_107 ( & V_128 ) ;
}
static int F_113 ( struct V_138 * V_139 ,
unsigned long V_85 , void * V_140 )
{
struct V_118 * V_119 = V_140 ;
F_22 ( & V_38 ) ;
switch ( V_85 ) {
case V_141 :
F_109 ( V_119 ) ;
break;
case V_142 :
F_111 ( V_119 ) ;
break;
}
F_26 ( & V_38 ) ;
return 0 ;
}
static int F_113 ( struct V_138 * V_139 ,
unsigned long V_85 , void * V_140 )
{
return 0 ;
}
static T_5 int F_114 ( char * V_143 )
{
F_115 ( V_144 , V_143 , V_145 ) ;
V_146 = 1 ;
V_147 = 1 ;
return 1 ;
}
static T_5 int F_116 ( void )
{
struct V_2 * * V_20 ;
struct V_107 * V_108 ;
struct V_107 * V_110 ;
struct V_107 * V_109 ;
int V_21 ;
char * V_54 = V_144 ;
char * V_148 ;
V_108 = F_90 () ;
if ( ! V_108 )
return 0 ;
V_110 = F_95 ( L_32 , 0444 , V_108 ,
( void * ) & V_149 ,
& V_150 ) ;
if ( ! V_110 )
F_92 ( L_17
L_33 ) ;
V_110 = F_95 ( L_34 , 0644 , V_108 ,
( void * ) & V_151 ,
& V_152 ) ;
if ( ! V_110 )
F_92 ( L_17
L_35 ) ;
V_109 = F_89 () ;
if ( ! V_109 )
return 0 ;
F_96 ( L_36 , 0444 , V_109 ,
V_153 ,
& V_154 ) ;
F_96 ( L_37 , 0444 , V_109 ,
V_155 ,
& V_154 ) ;
F_96 ( L_25 , 0644 , V_109 ,
NULL , & V_113 ) ;
if ( F_10 () )
F_92 ( L_38 ) ;
F_110 (call, __start_ftrace_events, __stop_ftrace_events) {
F_98 ( * V_20 , NULL , & V_123 ,
& V_124 ,
& V_125 ,
& V_126 ) ;
}
while ( true ) {
V_148 = F_36 ( & V_54 , L_39 ) ;
if ( ! V_148 )
break;
if ( ! * V_148 )
continue;
V_21 = F_35 ( V_148 , 1 ) ;
if ( V_21 )
F_92 ( L_40 , V_148 ) ;
}
V_21 = F_117 ( & V_156 ) ;
if ( V_21 )
F_92 ( L_41 ) ;
return 0 ;
}
static T_5 void F_118 ( struct V_157 * V_158 )
{
F_119 ( & V_159 ) ;
F_120 ( & V_160 ) ;
F_121 ( 1 ) ;
F_122 ( & V_160 ) ;
F_123 ( & V_159 ) ;
F_22 ( & V_161 ) ;
F_124 ( 1 ) ;
F_26 ( & V_161 ) ;
}
static T_5 int F_125 ( void * V_162 )
{
void * V_163 ;
V_163 = F_70 ( 1234 , V_15 ) ;
if ( ! V_163 )
F_28 ( L_42 ) ;
F_126 ( F_118 ) ;
F_7 ( V_163 ) ;
F_127 ( V_164 ) ;
while ( ! F_128 () )
F_129 () ;
return 0 ;
}
static T_5 void F_130 ( void )
{
struct V_165 * V_166 ;
V_166 = F_131 ( F_125 , NULL , L_43 ) ;
F_124 ( 1 ) ;
F_132 ( V_166 ) ;
}
static T_5 void F_133 ( void )
{
struct V_2 * V_20 ;
struct V_45 * system ;
int V_21 ;
F_28 ( L_44 ) ;
F_23 (call, &ftrace_events, list) {
if ( ! V_20 -> V_4 || ! V_20 -> V_4 -> V_32 )
continue;
#ifndef F_134
if ( V_20 -> V_4 -> system &&
strcmp ( V_20 -> V_4 -> system , L_45 ) == 0 )
continue;
#endif
F_28 ( L_46 , V_20 -> V_8 ) ;
if ( V_20 -> V_39 & V_40 ) {
F_92 ( L_47 ) ;
F_31 ( 1 ) ;
continue;
}
F_27 ( V_20 , 1 ) ;
F_130 () ;
F_27 ( V_20 , 0 ) ;
F_135 ( L_48 ) ;
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
F_130 () ;
V_21 = F_34 ( NULL , system -> V_8 , NULL , 0 ) ;
if ( F_31 ( V_21 ) )
F_92 ( L_53 ,
system -> V_8 ) ;
F_135 ( L_48 ) ;
}
F_28 ( L_54 ) ;
F_28 ( L_55 ) ;
V_21 = F_34 ( NULL , NULL , NULL , 1 ) ;
if ( F_31 ( V_21 ) ) {
F_92 ( L_56 ) ;
return;
}
F_130 () ;
V_21 = F_34 ( NULL , NULL , NULL , 0 ) ;
if ( F_31 ( V_21 ) ) {
F_92 ( L_57 ) ;
return;
}
F_135 ( L_48 ) ;
}
static void
F_136 ( unsigned long V_167 , unsigned long V_168 )
{
struct V_169 * V_28 ;
struct V_170 * V_63 ;
struct V_171 * V_110 ;
unsigned long V_39 ;
long V_172 ;
int V_173 ;
int V_174 ;
V_174 = F_137 () ;
F_138 () ;
V_173 = F_139 () ;
V_172 = F_140 ( & F_141 ( V_175 , V_173 ) ) ;
if ( V_172 != 1 )
goto V_87;
F_142 ( V_39 ) ;
V_28 = F_143 ( & V_63 ,
V_176 , sizeof( * V_110 ) ,
V_39 , V_174 ) ;
if ( ! V_28 )
goto V_87;
V_110 = F_144 ( V_28 ) ;
V_110 -> V_167 = V_167 ;
V_110 -> V_168 = V_168 ;
F_145 ( V_63 , V_28 , V_39 , V_174 ) ;
V_87:
F_146 ( & F_141 ( V_175 , V_173 ) ) ;
F_147 () ;
}
static T_5 void F_148 ( void )
{
int V_21 ;
V_21 = F_149 ( & V_177 ) ;
if ( F_9 ( V_21 < 0 ) ) {
F_28 ( L_58 ) ;
return;
}
F_28 ( L_59 ) ;
F_133 () ;
F_150 ( & V_177 ) ;
}
static T_5 void F_148 ( void )
{
}
static T_5 int F_151 ( void )
{
if ( ! V_147 ) {
F_133 () ;
F_148 () ;
}
return 0 ;
}
