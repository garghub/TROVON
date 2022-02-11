void F_1 ( struct V_1 * V_2 )
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
if ( V_2 -> V_14 )
continue;
if ( ! V_8 ) {
V_2 -> V_15 -> V_16 ( V_2 , V_8 ) ;
continue;
}
V_12 = F_7 ( V_2 -> V_12 ) ;
if ( V_12 && ! F_8 ( V_12 , V_8 ) )
continue;
if ( F_9 ( V_2 -> V_3 ) ) {
V_9 |= V_2 -> V_3 -> V_17 ;
continue;
}
V_2 -> V_15 -> V_16 ( V_2 , V_8 ) ;
}
return V_9 ;
}
void
F_10 ( struct V_6 * V_7 ,
enum V_5 V_9 ,
void * V_8 )
{
struct V_1 * V_2 ;
F_6 (data, &file->triggers, list) {
if ( V_2 -> V_14 )
continue;
if ( V_2 -> V_3 -> V_17 & V_9 )
V_2 -> V_15 -> V_16 ( V_2 , V_8 ) ;
}
}
static void * F_11 ( struct V_18 * V_19 , void * V_20 , T_1 * V_21 )
{
struct V_6 * V_22 = F_12 ( V_19 -> V_23 ) ;
if ( V_20 == V_24 )
return NULL ;
return F_13 ( V_20 , & V_22 -> V_13 , V_21 ) ;
}
static void * F_14 ( struct V_18 * V_19 , T_1 * V_21 )
{
struct V_6 * V_22 ;
F_15 ( & V_25 ) ;
V_22 = F_12 ( V_19 -> V_23 ) ;
if ( F_16 ( ! V_22 ) )
return F_17 ( - V_26 ) ;
if ( F_5 ( & V_22 -> V_13 ) )
return * V_21 == 0 ? V_24 : NULL ;
return F_18 ( & V_22 -> V_13 , * V_21 ) ;
}
static void F_19 ( struct V_18 * V_19 , void * V_20 )
{
F_20 ( & V_25 ) ;
}
static int F_21 ( struct V_18 * V_19 , void * V_27 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
if ( V_27 == V_24 ) {
F_22 ( V_19 , L_1 ) ;
F_23 ( V_19 , '#' ) ;
F_15 ( & V_30 ) ;
F_24 (p, &trigger_commands, list)
F_25 ( V_19 , L_2 , V_29 -> V_31 ) ;
F_23 ( V_19 , '\n' ) ;
F_20 ( & V_30 ) ;
return 0 ;
}
V_2 = F_26 ( V_27 , struct V_1 , V_32 ) ;
V_2 -> V_15 -> V_33 ( V_19 , V_2 -> V_15 , V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_34 * V_34 , struct V_7 * V_7 )
{
int V_35 = 0 ;
F_15 ( & V_25 ) ;
if ( F_16 ( ! F_12 ( V_7 ) ) ) {
F_20 ( & V_25 ) ;
return - V_26 ;
}
if ( ( V_7 -> V_36 & V_37 ) &&
( V_7 -> V_38 & V_39 ) ) {
struct V_6 * V_22 ;
struct V_28 * V_29 ;
V_22 = F_12 ( V_7 ) ;
F_28 (p, &trigger_commands, list) {
if ( V_29 -> V_40 )
V_29 -> V_40 ( V_22 ) ;
}
}
if ( V_7 -> V_36 & V_41 ) {
V_35 = F_29 ( V_7 , & V_42 ) ;
if ( ! V_35 ) {
struct V_18 * V_19 = V_7 -> V_43 ;
V_19 -> V_23 = V_7 ;
}
}
F_20 ( & V_25 ) ;
return V_35 ;
}
static int F_30 ( struct V_6 * V_7 , char * V_44 )
{
char * V_45 , * V_46 = V_44 ;
struct V_28 * V_29 ;
int V_35 = - V_47 ;
V_45 = F_31 ( & V_46 , L_3 ) ;
V_45 = ( V_45 [ 0 ] != '!' ) ? V_45 : V_45 + 1 ;
F_15 ( & V_30 ) ;
F_28 (p, &trigger_commands, list) {
if ( strcmp ( V_29 -> V_31 , V_45 ) == 0 ) {
V_35 = V_29 -> V_16 ( V_29 , V_7 , V_44 , V_45 , V_46 ) ;
goto V_48;
}
}
V_48:
F_20 ( & V_30 ) ;
return V_35 ;
}
static T_2 F_32 ( struct V_7 * V_7 ,
const char T_3 * V_49 ,
T_4 V_50 , T_1 * V_51 )
{
struct V_6 * V_22 ;
T_2 V_35 ;
char * V_52 ;
if ( ! V_50 )
return 0 ;
if ( V_50 >= V_53 )
return - V_47 ;
V_52 = F_33 ( V_49 , V_50 ) ;
if ( F_34 ( V_52 ) )
return F_35 ( V_52 ) ;
F_36 ( V_52 ) ;
F_15 ( & V_25 ) ;
V_22 = F_12 ( V_7 ) ;
if ( F_16 ( ! V_22 ) ) {
F_20 ( & V_25 ) ;
F_3 ( V_52 ) ;
return - V_26 ;
}
V_35 = F_30 ( V_22 , V_52 ) ;
F_20 ( & V_25 ) ;
F_3 ( V_52 ) ;
if ( V_35 < 0 )
goto V_54;
* V_51 += V_50 ;
V_35 = V_50 ;
V_54:
return V_35 ;
}
static int F_37 ( struct V_34 * V_34 , struct V_7 * V_7 )
{
F_15 ( & V_25 ) ;
if ( V_7 -> V_36 & V_41 )
F_38 ( V_34 , V_7 ) ;
F_20 ( & V_25 ) ;
return 0 ;
}
static T_2
F_39 ( struct V_7 * V_55 , const char T_3 * V_49 ,
T_4 V_50 , T_1 * V_51 )
{
return F_32 ( V_55 , V_49 , V_50 , V_51 ) ;
}
static int
F_40 ( struct V_34 * V_34 , struct V_7 * V_55 )
{
return F_27 ( V_34 , V_55 ) ;
}
static int
F_41 ( struct V_34 * V_34 , struct V_7 * V_7 )
{
return F_37 ( V_34 , V_7 ) ;
}
T_5 int F_42 ( struct V_28 * V_56 )
{
struct V_28 * V_29 ;
int V_35 = 0 ;
F_15 ( & V_30 ) ;
F_28 (p, &trigger_commands, list) {
if ( strcmp ( V_56 -> V_31 , V_29 -> V_31 ) == 0 ) {
V_35 = - V_57 ;
goto V_48;
}
}
F_43 ( & V_56 -> V_32 , & V_58 ) ;
V_48:
F_20 ( & V_30 ) ;
return V_35 ;
}
static T_5 int F_44 ( struct V_28 * V_56 )
{
struct V_28 * V_29 , * V_59 ;
int V_35 = - V_26 ;
F_15 ( & V_30 ) ;
F_45 (p, n, &trigger_commands, list) {
if ( strcmp ( V_56 -> V_31 , V_29 -> V_31 ) == 0 ) {
V_35 = 0 ;
F_46 ( & V_29 -> V_32 ) ;
goto V_48;
}
}
V_48:
F_20 ( & V_30 ) ;
return V_35 ;
}
static int
F_47 ( const char * V_31 , struct V_18 * V_19 ,
void * V_2 , char * V_60 )
{
long V_61 = ( long ) V_2 ;
F_22 ( V_19 , V_31 ) ;
if ( V_61 == - 1 )
F_22 ( V_19 , L_4 ) ;
else
F_25 ( V_19 , L_5 , V_61 ) ;
if ( V_60 )
F_25 ( V_19 , L_6 , V_60 ) ;
else
F_23 ( V_19 , '\n' ) ;
return 0 ;
}
int F_48 ( struct V_62 * V_15 ,
struct V_1 * V_2 )
{
V_2 -> V_63 ++ ;
return 0 ;
}
static void
F_49 ( struct V_62 * V_15 ,
struct V_1 * V_2 )
{
if ( F_50 ( V_2 -> V_63 <= 0 ) )
return;
V_2 -> V_63 -- ;
if ( ! V_2 -> V_63 )
F_1 ( V_2 ) ;
}
int F_51 ( struct V_6 * V_7 ,
int V_64 )
{
int V_35 = 0 ;
if ( V_64 ) {
if ( F_52 ( & V_7 -> V_65 ) > 1 )
return V_35 ;
F_53 ( V_66 , & V_7 -> V_67 ) ;
V_35 = F_54 ( V_7 , 1 , 1 ) ;
} else {
if ( F_55 ( & V_7 -> V_65 ) > 0 )
return V_35 ;
F_56 ( V_66 , & V_7 -> V_67 ) ;
V_35 = F_54 ( V_7 , 0 , 1 ) ;
}
return V_35 ;
}
void
F_57 ( struct V_68 * V_69 )
{
struct V_6 * V_7 ;
F_28 (file, &tr->events, list) {
struct V_1 * V_2 ;
F_6 (data, &file->triggers, list) {
F_51 ( V_7 , 0 ) ;
if ( V_2 -> V_15 -> free )
V_2 -> V_15 -> free ( V_2 -> V_15 , V_2 ) ;
}
}
}
void F_58 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
bool V_70 = false ;
F_6 (data, &file->triggers, list) {
if ( V_2 -> V_12 || F_9 ( V_2 -> V_3 ) ||
F_59 ( V_2 -> V_3 ) ) {
V_70 = true ;
break;
}
}
if ( V_70 )
F_53 ( V_71 , & V_7 -> V_67 ) ;
else
F_56 ( V_71 , & V_7 -> V_67 ) ;
}
static int F_60 ( char * V_72 , struct V_62 * V_15 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_1 * V_73 ;
int V_35 = 0 ;
F_6 (test, &file->triggers, list) {
if ( V_73 -> V_3 -> V_17 == V_2 -> V_3 -> V_17 ) {
V_35 = - V_74 ;
goto V_54;
}
}
if ( V_2 -> V_15 -> V_75 ) {
V_35 = V_2 -> V_15 -> V_75 ( V_2 -> V_15 , V_2 ) ;
if ( V_35 < 0 )
goto V_54;
}
F_61 ( & V_2 -> V_32 , & V_7 -> V_13 ) ;
V_35 ++ ;
F_58 ( V_7 ) ;
if ( F_51 ( V_7 , 1 ) < 0 ) {
F_62 ( & V_2 -> V_32 ) ;
F_58 ( V_7 ) ;
V_35 -- ;
}
V_54:
return V_35 ;
}
void F_63 ( char * V_72 , struct V_62 * V_15 ,
struct V_1 * V_73 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 ;
bool V_76 = false ;
F_6 (data, &file->triggers, list) {
if ( V_2 -> V_3 -> V_17 == V_73 -> V_3 -> V_17 ) {
V_76 = true ;
F_62 ( & V_2 -> V_32 ) ;
F_51 ( V_7 , 0 ) ;
F_58 ( V_7 ) ;
break;
}
}
if ( V_76 && V_2 -> V_15 -> free )
V_2 -> V_15 -> free ( V_2 -> V_15 , V_2 ) ;
}
static int
F_64 ( struct V_28 * V_3 ,
struct V_6 * V_7 ,
char * V_72 , char * V_56 , char * V_77 )
{
struct V_1 * V_78 ;
struct V_62 * V_79 ;
char * V_80 = NULL ;
char * V_81 ;
int V_35 ;
if ( V_77 && isdigit ( V_77 [ 0 ] ) )
V_80 = F_31 ( & V_77 , L_7 ) ;
V_79 = V_3 -> V_82 ( V_56 , V_80 ) ;
V_35 = - V_83 ;
V_78 = F_65 ( sizeof( * V_78 ) , V_84 ) ;
if ( ! V_78 )
goto V_54;
V_78 -> V_61 = - 1 ;
V_78 -> V_15 = V_79 ;
V_78 -> V_3 = V_3 ;
F_66 ( & V_78 -> V_32 ) ;
if ( V_72 [ 0 ] == '!' ) {
V_3 -> V_85 ( V_72 + 1 , V_79 , V_78 , V_7 ) ;
F_3 ( V_78 ) ;
V_35 = 0 ;
goto V_54;
}
if ( V_80 ) {
V_81 = F_31 ( & V_80 , L_8 ) ;
V_35 = - V_47 ;
if ( ! strlen ( V_81 ) )
goto V_86;
V_35 = F_67 ( V_81 , 0 , & V_78 -> V_61 ) ;
if ( V_35 )
goto V_86;
}
if ( ! V_77 )
goto V_87;
if ( ! V_3 -> V_4 )
goto V_87;
V_35 = V_3 -> V_4 ( V_77 , V_78 , V_7 ) ;
if ( V_35 < 0 )
goto V_86;
V_87:
V_35 = V_3 -> V_88 ( V_72 , V_79 , V_78 , V_7 ) ;
if ( ! V_35 ) {
V_35 = - V_89 ;
goto V_86;
} else if ( V_35 < 0 )
goto V_86;
V_35 = 0 ;
V_54:
return V_35 ;
V_86:
if ( V_3 -> V_4 )
V_3 -> V_4 ( NULL , V_78 , NULL ) ;
F_3 ( V_78 ) ;
goto V_54;
}
int F_68 ( char * V_60 ,
struct V_1 * V_78 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_78 ;
struct V_11 * V_12 = NULL , * V_90 ;
int V_35 = - V_47 ;
char * V_91 ;
if ( ! V_60 )
goto V_92;
V_91 = F_31 ( & V_60 , L_7 ) ;
if ( ! strlen ( V_91 ) || strcmp ( V_91 , L_9 ) != 0 )
goto V_54;
if ( ! V_60 )
goto V_54;
V_35 = F_69 ( V_7 -> V_93 , V_60 , false , & V_12 ) ;
if ( V_35 )
goto V_54;
V_92:
V_90 = F_70 ( V_2 -> V_12 ) ;
F_71 ( V_2 -> V_12 , V_12 ) ;
if ( V_90 ) {
F_2 () ;
F_72 ( V_90 ) ;
}
F_3 ( V_2 -> V_60 ) ;
V_2 -> V_60 = NULL ;
if ( V_60 ) {
V_2 -> V_60 = F_73 ( V_60 , V_84 ) ;
if ( ! V_2 -> V_60 ) {
F_72 ( F_70 ( V_2 -> V_12 ) ) ;
V_2 -> V_12 = NULL ;
V_35 = - V_83 ;
}
}
V_54:
return V_35 ;
}
static void
F_74 ( struct V_1 * V_2 , void * V_8 )
{
if ( F_75 () )
return;
F_76 () ;
}
static void
F_77 ( struct V_1 * V_2 , void * V_8 )
{
if ( F_75 () )
return;
if ( ! V_2 -> V_61 )
return;
if ( V_2 -> V_61 != - 1 )
( V_2 -> V_61 ) -- ;
F_76 () ;
}
static void
F_78 ( struct V_1 * V_2 , void * V_8 )
{
if ( ! F_75 () )
return;
F_79 () ;
}
static void
F_80 ( struct V_1 * V_2 , void * V_8 )
{
if ( ! F_75 () )
return;
if ( ! V_2 -> V_61 )
return;
if ( V_2 -> V_61 != - 1 )
( V_2 -> V_61 ) -- ;
F_79 () ;
}
static int
F_81 ( struct V_18 * V_19 , struct V_62 * V_15 ,
struct V_1 * V_2 )
{
return F_47 ( L_10 , V_19 , ( void * ) V_2 -> V_61 ,
V_2 -> V_60 ) ;
}
static int
F_82 ( struct V_18 * V_19 , struct V_62 * V_15 ,
struct V_1 * V_2 )
{
return F_47 ( L_11 , V_19 , ( void * ) V_2 -> V_61 ,
V_2 -> V_60 ) ;
}
static struct V_62 *
F_83 ( char * V_56 , char * V_77 )
{
struct V_62 * V_15 ;
if ( strcmp ( V_56 , L_10 ) == 0 )
V_15 = V_77 ? & V_94 :
& V_95 ;
else
V_15 = V_77 ? & V_96 :
& V_97 ;
return V_15 ;
}
static void
F_84 ( struct V_1 * V_2 , void * V_8 )
{
F_85 () ;
}
static void
F_86 ( struct V_1 * V_2 , void * V_8 )
{
if ( ! V_2 -> V_61 )
return;
if ( V_2 -> V_61 != - 1 )
( V_2 -> V_61 ) -- ;
F_84 ( V_2 , V_8 ) ;
}
static int
F_87 ( char * V_72 , struct V_62 * V_15 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_35 = F_60 ( V_72 , V_15 , V_2 , V_7 ) ;
if ( V_35 > 0 && F_88 () != 0 ) {
F_63 ( V_72 , V_15 , V_2 , V_7 ) ;
V_35 = 0 ;
}
return V_35 ;
}
static int
F_89 ( struct V_18 * V_19 , struct V_62 * V_15 ,
struct V_1 * V_2 )
{
return F_47 ( L_12 , V_19 , ( void * ) V_2 -> V_61 ,
V_2 -> V_60 ) ;
}
static struct V_62 *
F_90 ( char * V_56 , char * V_77 )
{
return V_77 ? & V_98 : & V_99 ;
}
static T_5 int F_91 ( void )
{
int V_35 ;
V_35 = F_42 ( & V_100 ) ;
F_92 ( V_35 < 0 ) ;
return V_35 ;
}
static T_5 int F_91 ( void ) { return 0 ; }
static void
F_93 ( struct V_1 * V_2 , void * V_8 )
{
F_94 ( V_101 ) ;
}
static void
F_95 ( struct V_1 * V_2 , void * V_8 )
{
if ( ! V_2 -> V_61 )
return;
if ( V_2 -> V_61 != - 1 )
( V_2 -> V_61 ) -- ;
F_93 ( V_2 , V_8 ) ;
}
static int
F_96 ( struct V_18 * V_19 , struct V_62 * V_15 ,
struct V_1 * V_2 )
{
return F_47 ( L_13 , V_19 , ( void * ) V_2 -> V_61 ,
V_2 -> V_60 ) ;
}
static struct V_62 *
F_97 ( char * V_56 , char * V_77 )
{
return V_77 ? & V_102 : & V_103 ;
}
static T_5 int F_98 ( void )
{
int V_35 ;
V_35 = F_42 ( & V_104 ) ;
F_92 ( V_35 < 0 ) ;
return V_35 ;
}
static T_5 int F_98 ( void ) { return 0 ; }
static T_5 void F_99 ( void )
{
F_44 ( & V_105 ) ;
F_44 ( & V_106 ) ;
}
static void
F_100 ( struct V_1 * V_2 , void * V_8 )
{
struct V_107 * V_108 = V_2 -> V_43 ;
if ( V_108 -> V_109 )
F_56 ( V_110 , & V_108 -> V_7 -> V_67 ) ;
else
F_53 ( V_110 , & V_108 -> V_7 -> V_67 ) ;
}
static void
F_101 ( struct V_1 * V_2 , void * V_8 )
{
struct V_107 * V_108 = V_2 -> V_43 ;
if ( ! V_2 -> V_61 )
return;
if ( V_108 -> V_109 == ! ( V_108 -> V_7 -> V_67 & V_111 ) )
return;
if ( V_2 -> V_61 != - 1 )
( V_2 -> V_61 ) -- ;
F_100 ( V_2 , V_8 ) ;
}
static int
F_102 ( struct V_18 * V_19 , struct V_62 * V_15 ,
struct V_1 * V_2 )
{
struct V_107 * V_108 = V_2 -> V_43 ;
F_25 ( V_19 , L_14 ,
V_108 -> V_109 ? V_112 : V_113 ,
V_108 -> V_7 -> V_93 -> V_114 -> system ,
F_103 ( V_108 -> V_7 -> V_93 ) ) ;
if ( V_2 -> V_61 == - 1 )
F_22 ( V_19 , L_4 ) ;
else
F_25 ( V_19 , L_5 , V_2 -> V_61 ) ;
if ( V_2 -> V_60 )
F_25 ( V_19 , L_6 , V_2 -> V_60 ) ;
else
F_23 ( V_19 , '\n' ) ;
return 0 ;
}
static void
F_104 ( struct V_62 * V_15 ,
struct V_1 * V_2 )
{
struct V_107 * V_108 = V_2 -> V_43 ;
if ( F_50 ( V_2 -> V_63 <= 0 ) )
return;
V_2 -> V_63 -- ;
if ( ! V_2 -> V_63 ) {
F_54 ( V_108 -> V_7 , 0 , 1 ) ;
F_105 ( V_108 -> V_7 -> V_93 -> V_115 ) ;
F_1 ( V_2 ) ;
F_3 ( V_108 ) ;
}
}
static int
F_106 ( struct V_28 * V_3 ,
struct V_6 * V_7 ,
char * V_72 , char * V_56 , char * V_77 )
{
struct V_6 * V_116 ;
struct V_107 * V_108 ;
struct V_1 * V_78 ;
struct V_62 * V_79 ;
struct V_68 * V_69 = V_7 -> V_69 ;
const char * system ;
const char * V_117 ;
char * V_80 ;
char * V_81 ;
bool V_109 ;
int V_35 ;
if ( ! V_77 )
return - V_47 ;
V_80 = F_31 ( & V_77 , L_7 ) ;
if ( ! V_80 )
return - V_47 ;
system = F_31 ( & V_80 , L_8 ) ;
if ( ! V_80 )
return - V_47 ;
V_117 = F_31 ( & V_80 , L_8 ) ;
V_35 = - V_47 ;
V_116 = F_107 ( V_69 , system , V_117 ) ;
if ( ! V_116 )
goto V_54;
V_109 = strcmp ( V_56 , V_112 ) == 0 ;
V_79 = V_3 -> V_82 ( V_56 , V_80 ) ;
V_35 = - V_83 ;
V_78 = F_65 ( sizeof( * V_78 ) , V_84 ) ;
if ( ! V_78 )
goto V_54;
V_108 = F_65 ( sizeof( * V_108 ) , V_84 ) ;
if ( ! V_108 ) {
F_3 ( V_78 ) ;
goto V_54;
}
V_78 -> V_61 = - 1 ;
V_78 -> V_15 = V_79 ;
V_78 -> V_3 = V_3 ;
F_66 ( & V_78 -> V_32 ) ;
F_108 ( V_78 -> V_12 , NULL ) ;
V_108 -> V_109 = V_109 ;
V_108 -> V_7 = V_116 ;
V_78 -> V_43 = V_108 ;
if ( V_72 [ 0 ] == '!' ) {
V_3 -> V_85 ( V_72 + 1 , V_79 , V_78 , V_7 ) ;
F_3 ( V_78 ) ;
F_3 ( V_108 ) ;
V_35 = 0 ;
goto V_54;
}
if ( V_80 ) {
V_81 = F_31 ( & V_80 , L_8 ) ;
V_35 = - V_47 ;
if ( ! strlen ( V_81 ) )
goto V_86;
V_35 = F_67 ( V_81 , 0 , & V_78 -> V_61 ) ;
if ( V_35 )
goto V_86;
}
if ( ! V_77 )
goto V_87;
if ( ! V_3 -> V_4 )
goto V_87;
V_35 = V_3 -> V_4 ( V_77 , V_78 , V_7 ) ;
if ( V_35 < 0 )
goto V_86;
V_87:
V_35 = F_109 ( V_116 -> V_93 -> V_115 ) ;
if ( ! V_35 ) {
V_35 = - V_57 ;
goto V_86;
}
V_35 = F_54 ( V_116 , 1 , 1 ) ;
if ( V_35 < 0 )
goto V_118;
V_35 = V_3 -> V_88 ( V_72 , V_79 , V_78 , V_7 ) ;
if ( ! V_35 ) {
V_35 = - V_89 ;
goto V_119;
} else if ( V_35 < 0 )
goto V_119;
V_35 = 0 ;
V_54:
return V_35 ;
V_119:
F_54 ( V_116 , 0 , 1 ) ;
V_118:
F_105 ( V_116 -> V_93 -> V_115 ) ;
V_86:
if ( V_3 -> V_4 )
V_3 -> V_4 ( NULL , V_78 , NULL ) ;
F_3 ( V_78 ) ;
F_3 ( V_108 ) ;
goto V_54;
}
static int F_110 ( char * V_72 ,
struct V_62 * V_15 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_107 * V_108 = V_2 -> V_43 ;
struct V_107 * V_120 ;
struct V_1 * V_73 ;
int V_35 = 0 ;
F_6 (test, &file->triggers, list) {
V_120 = V_73 -> V_43 ;
if ( V_120 &&
( V_120 -> V_7 == V_108 -> V_7 ) ) {
V_35 = - V_74 ;
goto V_54;
}
}
if ( V_2 -> V_15 -> V_75 ) {
V_35 = V_2 -> V_15 -> V_75 ( V_2 -> V_15 , V_2 ) ;
if ( V_35 < 0 )
goto V_54;
}
F_61 ( & V_2 -> V_32 , & V_7 -> V_13 ) ;
V_35 ++ ;
F_58 ( V_7 ) ;
if ( F_51 ( V_7 , 1 ) < 0 ) {
F_62 ( & V_2 -> V_32 ) ;
F_58 ( V_7 ) ;
V_35 -- ;
}
V_54:
return V_35 ;
}
static void F_111 ( char * V_72 ,
struct V_62 * V_15 ,
struct V_1 * V_73 ,
struct V_6 * V_7 )
{
struct V_107 * V_120 = V_73 -> V_43 ;
struct V_107 * V_108 ;
struct V_1 * V_2 ;
bool V_76 = false ;
F_6 (data, &file->triggers, list) {
V_108 = V_2 -> V_43 ;
if ( V_108 &&
( V_108 -> V_7 == V_120 -> V_7 ) ) {
V_76 = true ;
F_62 ( & V_2 -> V_32 ) ;
F_51 ( V_7 , 0 ) ;
F_58 ( V_7 ) ;
break;
}
}
if ( V_76 && V_2 -> V_15 -> free )
V_2 -> V_15 -> free ( V_2 -> V_15 , V_2 ) ;
}
static struct V_62 *
F_112 ( char * V_56 , char * V_77 )
{
struct V_62 * V_15 ;
bool V_109 ;
V_109 = strcmp ( V_56 , V_112 ) == 0 ;
if ( V_109 )
V_15 = V_77 ? & V_121 :
& V_122 ;
else
V_15 = V_77 ? & V_123 :
& V_124 ;
return V_15 ;
}
static T_5 void F_113 ( void )
{
F_44 ( & V_125 ) ;
F_44 ( & V_126 ) ;
}
static T_5 int F_114 ( void )
{
int V_35 ;
V_35 = F_42 ( & V_125 ) ;
if ( F_92 ( V_35 < 0 ) )
return V_35 ;
V_35 = F_42 ( & V_126 ) ;
if ( F_92 ( V_35 < 0 ) )
F_113 () ;
return V_35 ;
}
static T_5 int F_115 ( void )
{
int V_35 ;
V_35 = F_42 ( & V_105 ) ;
if ( F_92 ( V_35 < 0 ) )
return V_35 ;
V_35 = F_42 ( & V_106 ) ;
if ( F_92 ( V_35 < 0 ) )
F_99 () ;
return V_35 ;
}
T_5 int F_116 ( void )
{
F_115 () ;
F_91 () ;
F_98 () ;
F_114 () ;
return 0 ;
}
