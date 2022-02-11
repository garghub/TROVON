static void
F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
V_2 -> V_3 -> V_4 ( NULL , V_2 , NULL ) ;
F_2 () ;
F_3 ( V_2 ) ;
}
enum V_5
F_4 ( struct V_6 * V_7 , void * V_8 )
{
struct V_1 * V_2 ;
enum V_5 V_9 = V_10 ;
struct V_11 * V_12 ;
if ( F_5 ( & V_7 -> V_13 ) )
return V_9 ;
F_6 (data, &file->triggers, list) {
if ( ! V_8 ) {
V_2 -> V_14 -> V_15 ( V_2 ) ;
continue;
}
V_12 = F_7 ( V_2 -> V_12 ) ;
if ( V_12 && ! F_8 ( V_12 , V_8 ) )
continue;
if ( V_2 -> V_3 -> V_16 ) {
V_9 |= V_2 -> V_3 -> V_17 ;
continue;
}
V_2 -> V_14 -> V_15 ( V_2 ) ;
}
return V_9 ;
}
void
F_9 ( struct V_6 * V_7 ,
enum V_5 V_9 )
{
struct V_1 * V_2 ;
F_6 (data, &file->triggers, list) {
if ( V_2 -> V_3 -> V_17 & V_9 )
V_2 -> V_14 -> V_15 ( V_2 ) ;
}
}
static void * F_10 ( struct V_18 * V_19 , void * V_20 , T_1 * V_21 )
{
struct V_6 * V_22 = F_11 ( V_19 -> V_23 ) ;
if ( V_20 == V_24 )
return NULL ;
return F_12 ( V_20 , & V_22 -> V_13 , V_21 ) ;
}
static void * F_13 ( struct V_18 * V_19 , T_1 * V_21 )
{
struct V_6 * V_22 ;
F_14 ( & V_25 ) ;
V_22 = F_11 ( V_19 -> V_23 ) ;
if ( F_15 ( ! V_22 ) )
return F_16 ( - V_26 ) ;
if ( F_5 ( & V_22 -> V_13 ) )
return * V_21 == 0 ? V_24 : NULL ;
return F_17 ( & V_22 -> V_13 , * V_21 ) ;
}
static void F_18 ( struct V_18 * V_19 , void * V_20 )
{
F_19 ( & V_25 ) ;
}
static int F_20 ( struct V_18 * V_19 , void * V_27 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
if ( V_27 == V_24 ) {
F_21 ( V_19 , L_1 ) ;
F_22 ( V_19 , '#' ) ;
F_14 ( & V_30 ) ;
F_23 (p, &trigger_commands, list)
F_24 ( V_19 , L_2 , V_29 -> V_31 ) ;
F_22 ( V_19 , '\n' ) ;
F_19 ( & V_30 ) ;
return 0 ;
}
V_2 = F_25 ( V_27 , struct V_1 , V_32 ) ;
V_2 -> V_14 -> V_33 ( V_19 , V_2 -> V_14 , V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_34 * V_34 , struct V_7 * V_7 )
{
int V_35 = 0 ;
F_14 ( & V_25 ) ;
if ( F_15 ( ! F_11 ( V_7 ) ) ) {
F_19 ( & V_25 ) ;
return - V_26 ;
}
if ( V_7 -> V_36 & V_37 ) {
V_35 = F_27 ( V_7 , & V_38 ) ;
if ( ! V_35 ) {
struct V_18 * V_19 = V_7 -> V_39 ;
V_19 -> V_23 = V_7 ;
}
}
F_19 ( & V_25 ) ;
return V_35 ;
}
static int F_28 ( struct V_6 * V_7 , char * V_40 )
{
char * V_41 , * V_42 = V_40 ;
struct V_28 * V_29 ;
int V_35 = - V_43 ;
V_41 = F_29 ( & V_42 , L_3 ) ;
V_41 = ( V_41 [ 0 ] != '!' ) ? V_41 : V_41 + 1 ;
F_14 ( & V_30 ) ;
F_30 (p, &trigger_commands, list) {
if ( strcmp ( V_29 -> V_31 , V_41 ) == 0 ) {
V_35 = V_29 -> V_15 ( V_29 , V_7 , V_40 , V_41 , V_42 ) ;
goto V_44;
}
}
V_44:
F_19 ( & V_30 ) ;
return V_35 ;
}
static T_2 F_31 ( struct V_7 * V_7 ,
const char T_3 * V_45 ,
T_4 V_46 , T_1 * V_47 )
{
struct V_6 * V_22 ;
T_2 V_35 ;
char * V_48 ;
if ( ! V_46 )
return 0 ;
if ( V_46 >= V_49 )
return - V_43 ;
V_48 = ( char * ) F_32 ( V_50 ) ;
if ( ! V_48 )
return - V_51 ;
if ( F_33 ( V_48 , V_45 , V_46 ) ) {
F_34 ( ( unsigned long ) V_48 ) ;
return - V_52 ;
}
V_48 [ V_46 ] = '\0' ;
F_35 ( V_48 ) ;
F_14 ( & V_25 ) ;
V_22 = F_11 ( V_7 ) ;
if ( F_15 ( ! V_22 ) ) {
F_19 ( & V_25 ) ;
F_34 ( ( unsigned long ) V_48 ) ;
return - V_26 ;
}
V_35 = F_28 ( V_22 , V_48 ) ;
F_19 ( & V_25 ) ;
F_34 ( ( unsigned long ) V_48 ) ;
if ( V_35 < 0 )
goto V_53;
* V_47 += V_46 ;
V_35 = V_46 ;
V_53:
return V_35 ;
}
static int F_36 ( struct V_34 * V_34 , struct V_7 * V_7 )
{
F_14 ( & V_25 ) ;
if ( V_7 -> V_36 & V_37 )
F_37 ( V_34 , V_7 ) ;
F_19 ( & V_25 ) ;
return 0 ;
}
static T_2
F_38 ( struct V_7 * V_54 , const char T_3 * V_45 ,
T_4 V_46 , T_1 * V_47 )
{
return F_31 ( V_54 , V_45 , V_46 , V_47 ) ;
}
static int
F_39 ( struct V_34 * V_34 , struct V_7 * V_54 )
{
return F_26 ( V_34 , V_54 ) ;
}
static int
F_40 ( struct V_34 * V_34 , struct V_7 * V_7 )
{
return F_36 ( V_34 , V_7 ) ;
}
static T_5 int F_41 ( struct V_28 * V_55 )
{
struct V_28 * V_29 ;
int V_35 = 0 ;
F_14 ( & V_30 ) ;
F_30 (p, &trigger_commands, list) {
if ( strcmp ( V_55 -> V_31 , V_29 -> V_31 ) == 0 ) {
V_35 = - V_56 ;
goto V_44;
}
}
F_42 ( & V_55 -> V_32 , & V_57 ) ;
V_44:
F_19 ( & V_30 ) ;
return V_35 ;
}
static T_5 int F_43 ( struct V_28 * V_55 )
{
struct V_28 * V_29 , * V_58 ;
int V_35 = - V_26 ;
F_14 ( & V_30 ) ;
F_44 (p, n, &trigger_commands, list) {
if ( strcmp ( V_55 -> V_31 , V_29 -> V_31 ) == 0 ) {
V_35 = 0 ;
F_45 ( & V_29 -> V_32 ) ;
goto V_44;
}
}
V_44:
F_19 ( & V_30 ) ;
return V_35 ;
}
static int
F_46 ( const char * V_31 , struct V_18 * V_19 ,
void * V_2 , char * V_59 )
{
long V_60 = ( long ) V_2 ;
F_21 ( V_19 , V_31 ) ;
if ( V_60 == - 1 )
F_21 ( V_19 , L_4 ) ;
else
F_24 ( V_19 , L_5 , V_60 ) ;
if ( V_59 )
F_24 ( V_19 , L_6 , V_59 ) ;
else
F_22 ( V_19 , '\n' ) ;
return 0 ;
}
static int
F_47 ( struct V_61 * V_14 ,
struct V_1 * V_2 )
{
V_2 -> V_62 ++ ;
return 0 ;
}
static void
F_48 ( struct V_61 * V_14 ,
struct V_1 * V_2 )
{
if ( F_49 ( V_2 -> V_62 <= 0 ) )
return;
V_2 -> V_62 -- ;
if ( ! V_2 -> V_62 )
F_1 ( V_2 ) ;
}
static int F_50 ( struct V_6 * V_7 ,
int V_63 )
{
int V_35 = 0 ;
if ( V_63 ) {
if ( F_51 ( & V_7 -> V_64 ) > 1 )
return V_35 ;
F_52 ( V_65 , & V_7 -> V_66 ) ;
V_35 = F_53 ( V_7 , 1 , 1 ) ;
} else {
if ( F_54 ( & V_7 -> V_64 ) > 0 )
return V_35 ;
F_55 ( V_65 , & V_7 -> V_66 ) ;
V_35 = F_53 ( V_7 , 0 , 1 ) ;
}
return V_35 ;
}
void
F_56 ( struct V_67 * V_68 )
{
struct V_6 * V_7 ;
F_30 (file, &tr->events, list) {
struct V_1 * V_2 ;
F_6 (data, &file->triggers, list) {
F_50 ( V_7 , 0 ) ;
if ( V_2 -> V_14 -> free )
V_2 -> V_14 -> free ( V_2 -> V_14 , V_2 ) ;
}
}
}
static void F_57 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
bool V_69 = false ;
F_6 (data, &file->triggers, list) {
if ( V_2 -> V_12 || V_2 -> V_3 -> V_16 ) {
V_69 = true ;
break;
}
}
if ( V_69 )
F_52 ( V_70 , & V_7 -> V_66 ) ;
else
F_55 ( V_70 , & V_7 -> V_66 ) ;
}
static int F_58 ( char * V_71 , struct V_61 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_1 * V_72 ;
int V_35 = 0 ;
F_6 (test, &file->triggers, list) {
if ( V_72 -> V_3 -> V_17 == V_2 -> V_3 -> V_17 ) {
V_35 = - V_73 ;
goto V_53;
}
}
if ( V_2 -> V_14 -> V_74 ) {
V_35 = V_2 -> V_14 -> V_74 ( V_2 -> V_14 , V_2 ) ;
if ( V_35 < 0 )
goto V_53;
}
F_59 ( & V_2 -> V_32 , & V_7 -> V_13 ) ;
V_35 ++ ;
if ( F_50 ( V_7 , 1 ) < 0 ) {
F_60 ( & V_2 -> V_32 ) ;
V_35 -- ;
}
F_57 ( V_7 ) ;
V_53:
return V_35 ;
}
static void F_61 ( char * V_71 , struct V_61 * V_14 ,
struct V_1 * V_72 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 ;
bool V_75 = false ;
F_6 (data, &file->triggers, list) {
if ( V_2 -> V_3 -> V_17 == V_72 -> V_3 -> V_17 ) {
V_75 = true ;
F_60 ( & V_2 -> V_32 ) ;
F_57 ( V_7 ) ;
F_50 ( V_7 , 0 ) ;
break;
}
}
if ( V_75 && V_2 -> V_14 -> free )
V_2 -> V_14 -> free ( V_2 -> V_14 , V_2 ) ;
}
static int
F_62 ( struct V_28 * V_3 ,
struct V_6 * V_7 ,
char * V_71 , char * V_55 , char * V_76 )
{
struct V_1 * V_77 ;
struct V_61 * V_78 ;
char * V_79 = NULL ;
char * V_80 ;
int V_35 ;
if ( V_76 && isdigit ( V_76 [ 0 ] ) )
V_79 = F_29 ( & V_76 , L_7 ) ;
V_78 = V_3 -> V_81 ( V_55 , V_79 ) ;
V_35 = - V_51 ;
V_77 = F_63 ( sizeof( * V_77 ) , V_82 ) ;
if ( ! V_77 )
goto V_53;
V_77 -> V_60 = - 1 ;
V_77 -> V_14 = V_78 ;
V_77 -> V_3 = V_3 ;
F_64 ( & V_77 -> V_32 ) ;
if ( V_71 [ 0 ] == '!' ) {
V_3 -> V_83 ( V_71 + 1 , V_78 , V_77 , V_7 ) ;
F_3 ( V_77 ) ;
V_35 = 0 ;
goto V_53;
}
if ( V_79 ) {
V_80 = F_29 ( & V_79 , L_8 ) ;
V_35 = - V_43 ;
if ( ! strlen ( V_80 ) )
goto V_84;
V_35 = F_65 ( V_80 , 0 , & V_77 -> V_60 ) ;
if ( V_35 )
goto V_84;
}
if ( ! V_76 )
goto V_85;
if ( ! V_3 -> V_4 )
goto V_85;
V_35 = V_3 -> V_4 ( V_76 , V_77 , V_7 ) ;
if ( V_35 < 0 )
goto V_84;
V_85:
V_35 = V_3 -> V_86 ( V_71 , V_78 , V_77 , V_7 ) ;
if ( ! V_35 ) {
V_35 = - V_87 ;
goto V_84;
} else if ( V_35 < 0 )
goto V_84;
V_35 = 0 ;
V_53:
return V_35 ;
V_84:
if ( V_3 -> V_4 )
V_3 -> V_4 ( NULL , V_77 , NULL ) ;
F_3 ( V_77 ) ;
goto V_53;
}
static int F_66 ( char * V_59 ,
struct V_1 * V_77 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_77 ;
struct V_11 * V_12 = NULL , * V_88 ;
int V_35 = - V_43 ;
char * V_89 ;
if ( ! V_59 )
goto V_90;
V_89 = F_29 ( & V_59 , L_7 ) ;
if ( ! strlen ( V_89 ) || strcmp ( V_89 , L_9 ) != 0 )
goto V_53;
if ( ! V_59 )
goto V_53;
V_35 = F_67 ( V_7 -> V_91 , V_59 , false , & V_12 ) ;
if ( V_35 )
goto V_53;
V_90:
V_88 = F_68 ( V_2 -> V_12 ) ;
F_69 ( V_2 -> V_12 , V_12 ) ;
if ( V_88 ) {
F_2 () ;
F_70 ( V_88 ) ;
}
F_3 ( V_2 -> V_59 ) ;
V_2 -> V_59 = NULL ;
if ( V_59 ) {
V_2 -> V_59 = F_71 ( V_59 , V_82 ) ;
if ( ! V_2 -> V_59 ) {
F_70 ( F_68 ( V_2 -> V_12 ) ) ;
V_2 -> V_12 = NULL ;
V_35 = - V_51 ;
}
}
V_53:
return V_35 ;
}
static void
F_72 ( struct V_1 * V_2 )
{
if ( F_73 () )
return;
F_74 () ;
}
static void
F_75 ( struct V_1 * V_2 )
{
if ( F_73 () )
return;
if ( ! V_2 -> V_60 )
return;
if ( V_2 -> V_60 != - 1 )
( V_2 -> V_60 ) -- ;
F_74 () ;
}
static void
F_76 ( struct V_1 * V_2 )
{
if ( ! F_73 () )
return;
F_77 () ;
}
static void
F_78 ( struct V_1 * V_2 )
{
if ( ! F_73 () )
return;
if ( ! V_2 -> V_60 )
return;
if ( V_2 -> V_60 != - 1 )
( V_2 -> V_60 ) -- ;
F_77 () ;
}
static int
F_79 ( struct V_18 * V_19 , struct V_61 * V_14 ,
struct V_1 * V_2 )
{
return F_46 ( L_10 , V_19 , ( void * ) V_2 -> V_60 ,
V_2 -> V_59 ) ;
}
static int
F_80 ( struct V_18 * V_19 , struct V_61 * V_14 ,
struct V_1 * V_2 )
{
return F_46 ( L_11 , V_19 , ( void * ) V_2 -> V_60 ,
V_2 -> V_59 ) ;
}
static struct V_61 *
F_81 ( char * V_55 , char * V_76 )
{
struct V_61 * V_14 ;
if ( strcmp ( V_55 , L_10 ) == 0 )
V_14 = V_76 ? & V_92 :
& V_93 ;
else
V_14 = V_76 ? & V_94 :
& V_95 ;
return V_14 ;
}
static void
F_82 ( struct V_1 * V_2 )
{
F_83 () ;
}
static void
F_84 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_60 )
return;
if ( V_2 -> V_60 != - 1 )
( V_2 -> V_60 ) -- ;
F_82 ( V_2 ) ;
}
static int
F_85 ( char * V_71 , struct V_61 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_35 = F_58 ( V_71 , V_14 , V_2 , V_7 ) ;
if ( V_35 > 0 && F_86 () != 0 ) {
F_61 ( V_71 , V_14 , V_2 , V_7 ) ;
V_35 = 0 ;
}
return V_35 ;
}
static int
F_87 ( struct V_18 * V_19 , struct V_61 * V_14 ,
struct V_1 * V_2 )
{
return F_46 ( L_12 , V_19 , ( void * ) V_2 -> V_60 ,
V_2 -> V_59 ) ;
}
static struct V_61 *
F_88 ( char * V_55 , char * V_76 )
{
return V_76 ? & V_96 : & V_97 ;
}
static T_5 int F_89 ( void )
{
int V_35 ;
V_35 = F_41 ( & V_98 ) ;
F_90 ( V_35 < 0 ) ;
return V_35 ;
}
static T_5 int F_89 ( void ) { return 0 ; }
static void
F_91 ( struct V_1 * V_2 )
{
F_92 ( V_99 ) ;
}
static void
F_93 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_60 )
return;
if ( V_2 -> V_60 != - 1 )
( V_2 -> V_60 ) -- ;
F_91 ( V_2 ) ;
}
static int
F_94 ( struct V_18 * V_19 , struct V_61 * V_14 ,
struct V_1 * V_2 )
{
return F_46 ( L_13 , V_19 , ( void * ) V_2 -> V_60 ,
V_2 -> V_59 ) ;
}
static struct V_61 *
F_95 ( char * V_55 , char * V_76 )
{
return V_76 ? & V_100 : & V_101 ;
}
static T_5 int F_96 ( void )
{
int V_35 ;
V_35 = F_41 ( & V_102 ) ;
F_90 ( V_35 < 0 ) ;
return V_35 ;
}
static T_5 int F_96 ( void ) { return 0 ; }
static T_5 void F_97 ( void )
{
F_43 ( & V_103 ) ;
F_43 ( & V_104 ) ;
}
static void
F_98 ( struct V_1 * V_2 )
{
struct V_105 * V_106 = V_2 -> V_39 ;
if ( V_106 -> V_107 )
F_55 ( V_108 , & V_106 -> V_7 -> V_66 ) ;
else
F_52 ( V_108 , & V_106 -> V_7 -> V_66 ) ;
}
static void
F_99 ( struct V_1 * V_2 )
{
struct V_105 * V_106 = V_2 -> V_39 ;
if ( ! V_2 -> V_60 )
return;
if ( V_106 -> V_107 == ! ( V_106 -> V_7 -> V_66 & V_109 ) )
return;
if ( V_2 -> V_60 != - 1 )
( V_2 -> V_60 ) -- ;
F_98 ( V_2 ) ;
}
static int
F_100 ( struct V_18 * V_19 , struct V_61 * V_14 ,
struct V_1 * V_2 )
{
struct V_105 * V_106 = V_2 -> V_39 ;
F_24 ( V_19 , L_14 ,
V_106 -> V_107 ? V_110 : V_111 ,
V_106 -> V_7 -> V_91 -> V_112 -> system ,
F_101 ( V_106 -> V_7 -> V_91 ) ) ;
if ( V_2 -> V_60 == - 1 )
F_21 ( V_19 , L_4 ) ;
else
F_24 ( V_19 , L_5 , V_2 -> V_60 ) ;
if ( V_2 -> V_59 )
F_24 ( V_19 , L_6 , V_2 -> V_59 ) ;
else
F_22 ( V_19 , '\n' ) ;
return 0 ;
}
static void
F_102 ( struct V_61 * V_14 ,
struct V_1 * V_2 )
{
struct V_105 * V_106 = V_2 -> V_39 ;
if ( F_49 ( V_2 -> V_62 <= 0 ) )
return;
V_2 -> V_62 -- ;
if ( ! V_2 -> V_62 ) {
F_53 ( V_106 -> V_7 , 0 , 1 ) ;
F_103 ( V_106 -> V_7 -> V_91 -> V_113 ) ;
F_1 ( V_2 ) ;
F_3 ( V_106 ) ;
}
}
static int
F_104 ( struct V_28 * V_3 ,
struct V_6 * V_7 ,
char * V_71 , char * V_55 , char * V_76 )
{
struct V_6 * V_114 ;
struct V_105 * V_106 ;
struct V_1 * V_77 ;
struct V_61 * V_78 ;
struct V_67 * V_68 = V_7 -> V_68 ;
const char * system ;
const char * V_115 ;
char * V_79 ;
char * V_80 ;
bool V_107 ;
int V_35 ;
if ( ! V_76 )
return - V_43 ;
V_79 = F_29 ( & V_76 , L_7 ) ;
if ( ! V_79 )
return - V_43 ;
system = F_29 ( & V_79 , L_8 ) ;
if ( ! V_79 )
return - V_43 ;
V_115 = F_29 ( & V_79 , L_8 ) ;
V_35 = - V_43 ;
V_114 = F_105 ( V_68 , system , V_115 ) ;
if ( ! V_114 )
goto V_53;
V_107 = strcmp ( V_55 , V_110 ) == 0 ;
V_78 = V_3 -> V_81 ( V_55 , V_79 ) ;
V_35 = - V_51 ;
V_77 = F_63 ( sizeof( * V_77 ) , V_82 ) ;
if ( ! V_77 )
goto V_53;
V_106 = F_63 ( sizeof( * V_106 ) , V_82 ) ;
if ( ! V_106 ) {
F_3 ( V_77 ) ;
goto V_53;
}
V_77 -> V_60 = - 1 ;
V_77 -> V_14 = V_78 ;
V_77 -> V_3 = V_3 ;
F_64 ( & V_77 -> V_32 ) ;
F_106 ( V_77 -> V_12 , NULL ) ;
V_106 -> V_107 = V_107 ;
V_106 -> V_7 = V_114 ;
V_77 -> V_39 = V_106 ;
if ( V_71 [ 0 ] == '!' ) {
V_3 -> V_83 ( V_71 + 1 , V_78 , V_77 , V_7 ) ;
F_3 ( V_77 ) ;
F_3 ( V_106 ) ;
V_35 = 0 ;
goto V_53;
}
if ( V_79 ) {
V_80 = F_29 ( & V_79 , L_8 ) ;
V_35 = - V_43 ;
if ( ! strlen ( V_80 ) )
goto V_84;
V_35 = F_65 ( V_80 , 0 , & V_77 -> V_60 ) ;
if ( V_35 )
goto V_84;
}
if ( ! V_76 )
goto V_85;
if ( ! V_3 -> V_4 )
goto V_85;
V_35 = V_3 -> V_4 ( V_76 , V_77 , V_7 ) ;
if ( V_35 < 0 )
goto V_84;
V_85:
V_35 = F_107 ( V_114 -> V_91 -> V_113 ) ;
if ( ! V_35 ) {
V_35 = - V_56 ;
goto V_84;
}
V_35 = F_53 ( V_114 , 1 , 1 ) ;
if ( V_35 < 0 )
goto V_116;
V_35 = V_3 -> V_86 ( V_71 , V_78 , V_77 , V_7 ) ;
if ( ! V_35 ) {
V_35 = - V_87 ;
goto V_117;
} else if ( V_35 < 0 )
goto V_117;
V_35 = 0 ;
V_53:
return V_35 ;
V_117:
F_53 ( V_114 , 0 , 1 ) ;
V_116:
F_103 ( V_114 -> V_91 -> V_113 ) ;
V_84:
if ( V_3 -> V_4 )
V_3 -> V_4 ( NULL , V_77 , NULL ) ;
F_3 ( V_77 ) ;
F_3 ( V_106 ) ;
goto V_53;
}
static int F_108 ( char * V_71 ,
struct V_61 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_105 * V_106 = V_2 -> V_39 ;
struct V_105 * V_118 ;
struct V_1 * V_72 ;
int V_35 = 0 ;
F_6 (test, &file->triggers, list) {
V_118 = V_72 -> V_39 ;
if ( V_118 &&
( V_118 -> V_7 == V_106 -> V_7 ) ) {
V_35 = - V_73 ;
goto V_53;
}
}
if ( V_2 -> V_14 -> V_74 ) {
V_35 = V_2 -> V_14 -> V_74 ( V_2 -> V_14 , V_2 ) ;
if ( V_35 < 0 )
goto V_53;
}
F_59 ( & V_2 -> V_32 , & V_7 -> V_13 ) ;
V_35 ++ ;
if ( F_50 ( V_7 , 1 ) < 0 ) {
F_60 ( & V_2 -> V_32 ) ;
V_35 -- ;
}
F_57 ( V_7 ) ;
V_53:
return V_35 ;
}
static void F_109 ( char * V_71 ,
struct V_61 * V_14 ,
struct V_1 * V_72 ,
struct V_6 * V_7 )
{
struct V_105 * V_118 = V_72 -> V_39 ;
struct V_105 * V_106 ;
struct V_1 * V_2 ;
bool V_75 = false ;
F_6 (data, &file->triggers, list) {
V_106 = V_2 -> V_39 ;
if ( V_106 &&
( V_106 -> V_7 == V_118 -> V_7 ) ) {
V_75 = true ;
F_60 ( & V_2 -> V_32 ) ;
F_57 ( V_7 ) ;
F_50 ( V_7 , 0 ) ;
break;
}
}
if ( V_75 && V_2 -> V_14 -> free )
V_2 -> V_14 -> free ( V_2 -> V_14 , V_2 ) ;
}
static struct V_61 *
F_110 ( char * V_55 , char * V_76 )
{
struct V_61 * V_14 ;
bool V_107 ;
V_107 = strcmp ( V_55 , V_110 ) == 0 ;
if ( V_107 )
V_14 = V_76 ? & V_119 :
& V_120 ;
else
V_14 = V_76 ? & V_121 :
& V_122 ;
return V_14 ;
}
static T_5 void F_111 ( void )
{
F_43 ( & V_123 ) ;
F_43 ( & V_124 ) ;
}
static T_5 int F_112 ( void )
{
int V_35 ;
V_35 = F_41 ( & V_123 ) ;
if ( F_90 ( V_35 < 0 ) )
return V_35 ;
V_35 = F_41 ( & V_124 ) ;
if ( F_90 ( V_35 < 0 ) )
F_111 () ;
return V_35 ;
}
static T_5 int F_113 ( void )
{
int V_35 ;
V_35 = F_41 ( & V_103 ) ;
if ( F_90 ( V_35 < 0 ) )
return V_35 ;
V_35 = F_41 ( & V_104 ) ;
if ( F_90 ( V_35 < 0 ) )
F_97 () ;
return V_35 ;
}
T_5 int F_114 ( void )
{
F_113 () ;
F_89 () ;
F_96 () ;
F_112 () ;
return 0 ;
}
