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
V_48 = F_32 ( V_45 , V_46 ) ;
if ( F_33 ( V_48 ) )
return F_34 ( V_48 ) ;
F_35 ( V_48 ) ;
F_14 ( & V_25 ) ;
V_22 = F_11 ( V_7 ) ;
if ( F_15 ( ! V_22 ) ) {
F_19 ( & V_25 ) ;
F_3 ( V_48 ) ;
return - V_26 ;
}
V_35 = F_28 ( V_22 , V_48 ) ;
F_19 ( & V_25 ) ;
F_3 ( V_48 ) ;
if ( V_35 < 0 )
goto V_50;
* V_47 += V_46 ;
V_35 = V_46 ;
V_50:
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
F_38 ( struct V_7 * V_51 , const char T_3 * V_45 ,
T_4 V_46 , T_1 * V_47 )
{
return F_31 ( V_51 , V_45 , V_46 , V_47 ) ;
}
static int
F_39 ( struct V_34 * V_34 , struct V_7 * V_51 )
{
return F_26 ( V_34 , V_51 ) ;
}
static int
F_40 ( struct V_34 * V_34 , struct V_7 * V_7 )
{
return F_36 ( V_34 , V_7 ) ;
}
static T_5 int F_41 ( struct V_28 * V_52 )
{
struct V_28 * V_29 ;
int V_35 = 0 ;
F_14 ( & V_30 ) ;
F_30 (p, &trigger_commands, list) {
if ( strcmp ( V_52 -> V_31 , V_29 -> V_31 ) == 0 ) {
V_35 = - V_53 ;
goto V_44;
}
}
F_42 ( & V_52 -> V_32 , & V_54 ) ;
V_44:
F_19 ( & V_30 ) ;
return V_35 ;
}
static T_5 int F_43 ( struct V_28 * V_52 )
{
struct V_28 * V_29 , * V_55 ;
int V_35 = - V_26 ;
F_14 ( & V_30 ) ;
F_44 (p, n, &trigger_commands, list) {
if ( strcmp ( V_52 -> V_31 , V_29 -> V_31 ) == 0 ) {
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
void * V_2 , char * V_56 )
{
long V_57 = ( long ) V_2 ;
F_21 ( V_19 , V_31 ) ;
if ( V_57 == - 1 )
F_21 ( V_19 , L_4 ) ;
else
F_24 ( V_19 , L_5 , V_57 ) ;
if ( V_56 )
F_24 ( V_19 , L_6 , V_56 ) ;
else
F_22 ( V_19 , '\n' ) ;
return 0 ;
}
static int
F_47 ( struct V_58 * V_14 ,
struct V_1 * V_2 )
{
V_2 -> V_59 ++ ;
return 0 ;
}
static void
F_48 ( struct V_58 * V_14 ,
struct V_1 * V_2 )
{
if ( F_49 ( V_2 -> V_59 <= 0 ) )
return;
V_2 -> V_59 -- ;
if ( ! V_2 -> V_59 )
F_1 ( V_2 ) ;
}
static int F_50 ( struct V_6 * V_7 ,
int V_60 )
{
int V_35 = 0 ;
if ( V_60 ) {
if ( F_51 ( & V_7 -> V_61 ) > 1 )
return V_35 ;
F_52 ( V_62 , & V_7 -> V_63 ) ;
V_35 = F_53 ( V_7 , 1 , 1 ) ;
} else {
if ( F_54 ( & V_7 -> V_61 ) > 0 )
return V_35 ;
F_55 ( V_62 , & V_7 -> V_63 ) ;
V_35 = F_53 ( V_7 , 0 , 1 ) ;
}
return V_35 ;
}
void
F_56 ( struct V_64 * V_65 )
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
bool V_66 = false ;
F_6 (data, &file->triggers, list) {
if ( V_2 -> V_12 || V_2 -> V_3 -> V_16 ) {
V_66 = true ;
break;
}
}
if ( V_66 )
F_52 ( V_67 , & V_7 -> V_63 ) ;
else
F_55 ( V_67 , & V_7 -> V_63 ) ;
}
static int F_58 ( char * V_68 , struct V_58 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_1 * V_69 ;
int V_35 = 0 ;
F_6 (test, &file->triggers, list) {
if ( V_69 -> V_3 -> V_17 == V_2 -> V_3 -> V_17 ) {
V_35 = - V_70 ;
goto V_50;
}
}
if ( V_2 -> V_14 -> V_71 ) {
V_35 = V_2 -> V_14 -> V_71 ( V_2 -> V_14 , V_2 ) ;
if ( V_35 < 0 )
goto V_50;
}
F_59 ( & V_2 -> V_32 , & V_7 -> V_13 ) ;
V_35 ++ ;
F_57 ( V_7 ) ;
if ( F_50 ( V_7 , 1 ) < 0 ) {
F_60 ( & V_2 -> V_32 ) ;
F_57 ( V_7 ) ;
V_35 -- ;
}
V_50:
return V_35 ;
}
static void F_61 ( char * V_68 , struct V_58 * V_14 ,
struct V_1 * V_69 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 ;
bool V_72 = false ;
F_6 (data, &file->triggers, list) {
if ( V_2 -> V_3 -> V_17 == V_69 -> V_3 -> V_17 ) {
V_72 = true ;
F_60 ( & V_2 -> V_32 ) ;
F_50 ( V_7 , 0 ) ;
F_57 ( V_7 ) ;
break;
}
}
if ( V_72 && V_2 -> V_14 -> free )
V_2 -> V_14 -> free ( V_2 -> V_14 , V_2 ) ;
}
static int
F_62 ( struct V_28 * V_3 ,
struct V_6 * V_7 ,
char * V_68 , char * V_52 , char * V_73 )
{
struct V_1 * V_74 ;
struct V_58 * V_75 ;
char * V_76 = NULL ;
char * V_77 ;
int V_35 ;
if ( V_73 && isdigit ( V_73 [ 0 ] ) )
V_76 = F_29 ( & V_73 , L_7 ) ;
V_75 = V_3 -> V_78 ( V_52 , V_76 ) ;
V_35 = - V_79 ;
V_74 = F_63 ( sizeof( * V_74 ) , V_80 ) ;
if ( ! V_74 )
goto V_50;
V_74 -> V_57 = - 1 ;
V_74 -> V_14 = V_75 ;
V_74 -> V_3 = V_3 ;
F_64 ( & V_74 -> V_32 ) ;
if ( V_68 [ 0 ] == '!' ) {
V_3 -> V_81 ( V_68 + 1 , V_75 , V_74 , V_7 ) ;
F_3 ( V_74 ) ;
V_35 = 0 ;
goto V_50;
}
if ( V_76 ) {
V_77 = F_29 ( & V_76 , L_8 ) ;
V_35 = - V_43 ;
if ( ! strlen ( V_77 ) )
goto V_82;
V_35 = F_65 ( V_77 , 0 , & V_74 -> V_57 ) ;
if ( V_35 )
goto V_82;
}
if ( ! V_73 )
goto V_83;
if ( ! V_3 -> V_4 )
goto V_83;
V_35 = V_3 -> V_4 ( V_73 , V_74 , V_7 ) ;
if ( V_35 < 0 )
goto V_82;
V_83:
V_35 = V_3 -> V_84 ( V_68 , V_75 , V_74 , V_7 ) ;
if ( ! V_35 ) {
V_35 = - V_85 ;
goto V_82;
} else if ( V_35 < 0 )
goto V_82;
V_35 = 0 ;
V_50:
return V_35 ;
V_82:
if ( V_3 -> V_4 )
V_3 -> V_4 ( NULL , V_74 , NULL ) ;
F_3 ( V_74 ) ;
goto V_50;
}
static int F_66 ( char * V_56 ,
struct V_1 * V_74 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_74 ;
struct V_11 * V_12 = NULL , * V_86 ;
int V_35 = - V_43 ;
char * V_87 ;
if ( ! V_56 )
goto V_88;
V_87 = F_29 ( & V_56 , L_7 ) ;
if ( ! strlen ( V_87 ) || strcmp ( V_87 , L_9 ) != 0 )
goto V_50;
if ( ! V_56 )
goto V_50;
V_35 = F_67 ( V_7 -> V_89 , V_56 , false , & V_12 ) ;
if ( V_35 )
goto V_50;
V_88:
V_86 = F_68 ( V_2 -> V_12 ) ;
F_69 ( V_2 -> V_12 , V_12 ) ;
if ( V_86 ) {
F_2 () ;
F_70 ( V_86 ) ;
}
F_3 ( V_2 -> V_56 ) ;
V_2 -> V_56 = NULL ;
if ( V_56 ) {
V_2 -> V_56 = F_71 ( V_56 , V_80 ) ;
if ( ! V_2 -> V_56 ) {
F_70 ( F_68 ( V_2 -> V_12 ) ) ;
V_2 -> V_12 = NULL ;
V_35 = - V_79 ;
}
}
V_50:
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
if ( ! V_2 -> V_57 )
return;
if ( V_2 -> V_57 != - 1 )
( V_2 -> V_57 ) -- ;
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
if ( ! V_2 -> V_57 )
return;
if ( V_2 -> V_57 != - 1 )
( V_2 -> V_57 ) -- ;
F_77 () ;
}
static int
F_79 ( struct V_18 * V_19 , struct V_58 * V_14 ,
struct V_1 * V_2 )
{
return F_46 ( L_10 , V_19 , ( void * ) V_2 -> V_57 ,
V_2 -> V_56 ) ;
}
static int
F_80 ( struct V_18 * V_19 , struct V_58 * V_14 ,
struct V_1 * V_2 )
{
return F_46 ( L_11 , V_19 , ( void * ) V_2 -> V_57 ,
V_2 -> V_56 ) ;
}
static struct V_58 *
F_81 ( char * V_52 , char * V_73 )
{
struct V_58 * V_14 ;
if ( strcmp ( V_52 , L_10 ) == 0 )
V_14 = V_73 ? & V_90 :
& V_91 ;
else
V_14 = V_73 ? & V_92 :
& V_93 ;
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
if ( ! V_2 -> V_57 )
return;
if ( V_2 -> V_57 != - 1 )
( V_2 -> V_57 ) -- ;
F_82 ( V_2 ) ;
}
static int
F_85 ( char * V_68 , struct V_58 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_35 = F_58 ( V_68 , V_14 , V_2 , V_7 ) ;
if ( V_35 > 0 && F_86 () != 0 ) {
F_61 ( V_68 , V_14 , V_2 , V_7 ) ;
V_35 = 0 ;
}
return V_35 ;
}
static int
F_87 ( struct V_18 * V_19 , struct V_58 * V_14 ,
struct V_1 * V_2 )
{
return F_46 ( L_12 , V_19 , ( void * ) V_2 -> V_57 ,
V_2 -> V_56 ) ;
}
static struct V_58 *
F_88 ( char * V_52 , char * V_73 )
{
return V_73 ? & V_94 : & V_95 ;
}
static T_5 int F_89 ( void )
{
int V_35 ;
V_35 = F_41 ( & V_96 ) ;
F_90 ( V_35 < 0 ) ;
return V_35 ;
}
static T_5 int F_89 ( void ) { return 0 ; }
static void
F_91 ( struct V_1 * V_2 )
{
F_92 ( V_97 ) ;
}
static void
F_93 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_57 )
return;
if ( V_2 -> V_57 != - 1 )
( V_2 -> V_57 ) -- ;
F_91 ( V_2 ) ;
}
static int
F_94 ( struct V_18 * V_19 , struct V_58 * V_14 ,
struct V_1 * V_2 )
{
return F_46 ( L_13 , V_19 , ( void * ) V_2 -> V_57 ,
V_2 -> V_56 ) ;
}
static struct V_58 *
F_95 ( char * V_52 , char * V_73 )
{
return V_73 ? & V_98 : & V_99 ;
}
static T_5 int F_96 ( void )
{
int V_35 ;
V_35 = F_41 ( & V_100 ) ;
F_90 ( V_35 < 0 ) ;
return V_35 ;
}
static T_5 int F_96 ( void ) { return 0 ; }
static T_5 void F_97 ( void )
{
F_43 ( & V_101 ) ;
F_43 ( & V_102 ) ;
}
static void
F_98 ( struct V_1 * V_2 )
{
struct V_103 * V_104 = V_2 -> V_39 ;
if ( V_104 -> V_105 )
F_55 ( V_106 , & V_104 -> V_7 -> V_63 ) ;
else
F_52 ( V_106 , & V_104 -> V_7 -> V_63 ) ;
}
static void
F_99 ( struct V_1 * V_2 )
{
struct V_103 * V_104 = V_2 -> V_39 ;
if ( ! V_2 -> V_57 )
return;
if ( V_104 -> V_105 == ! ( V_104 -> V_7 -> V_63 & V_107 ) )
return;
if ( V_2 -> V_57 != - 1 )
( V_2 -> V_57 ) -- ;
F_98 ( V_2 ) ;
}
static int
F_100 ( struct V_18 * V_19 , struct V_58 * V_14 ,
struct V_1 * V_2 )
{
struct V_103 * V_104 = V_2 -> V_39 ;
F_24 ( V_19 , L_14 ,
V_104 -> V_105 ? V_108 : V_109 ,
V_104 -> V_7 -> V_89 -> V_110 -> system ,
F_101 ( V_104 -> V_7 -> V_89 ) ) ;
if ( V_2 -> V_57 == - 1 )
F_21 ( V_19 , L_4 ) ;
else
F_24 ( V_19 , L_5 , V_2 -> V_57 ) ;
if ( V_2 -> V_56 )
F_24 ( V_19 , L_6 , V_2 -> V_56 ) ;
else
F_22 ( V_19 , '\n' ) ;
return 0 ;
}
static void
F_102 ( struct V_58 * V_14 ,
struct V_1 * V_2 )
{
struct V_103 * V_104 = V_2 -> V_39 ;
if ( F_49 ( V_2 -> V_59 <= 0 ) )
return;
V_2 -> V_59 -- ;
if ( ! V_2 -> V_59 ) {
F_53 ( V_104 -> V_7 , 0 , 1 ) ;
F_103 ( V_104 -> V_7 -> V_89 -> V_111 ) ;
F_1 ( V_2 ) ;
F_3 ( V_104 ) ;
}
}
static int
F_104 ( struct V_28 * V_3 ,
struct V_6 * V_7 ,
char * V_68 , char * V_52 , char * V_73 )
{
struct V_6 * V_112 ;
struct V_103 * V_104 ;
struct V_1 * V_74 ;
struct V_58 * V_75 ;
struct V_64 * V_65 = V_7 -> V_65 ;
const char * system ;
const char * V_113 ;
char * V_76 ;
char * V_77 ;
bool V_105 ;
int V_35 ;
if ( ! V_73 )
return - V_43 ;
V_76 = F_29 ( & V_73 , L_7 ) ;
if ( ! V_76 )
return - V_43 ;
system = F_29 ( & V_76 , L_8 ) ;
if ( ! V_76 )
return - V_43 ;
V_113 = F_29 ( & V_76 , L_8 ) ;
V_35 = - V_43 ;
V_112 = F_105 ( V_65 , system , V_113 ) ;
if ( ! V_112 )
goto V_50;
V_105 = strcmp ( V_52 , V_108 ) == 0 ;
V_75 = V_3 -> V_78 ( V_52 , V_76 ) ;
V_35 = - V_79 ;
V_74 = F_63 ( sizeof( * V_74 ) , V_80 ) ;
if ( ! V_74 )
goto V_50;
V_104 = F_63 ( sizeof( * V_104 ) , V_80 ) ;
if ( ! V_104 ) {
F_3 ( V_74 ) ;
goto V_50;
}
V_74 -> V_57 = - 1 ;
V_74 -> V_14 = V_75 ;
V_74 -> V_3 = V_3 ;
F_64 ( & V_74 -> V_32 ) ;
F_106 ( V_74 -> V_12 , NULL ) ;
V_104 -> V_105 = V_105 ;
V_104 -> V_7 = V_112 ;
V_74 -> V_39 = V_104 ;
if ( V_68 [ 0 ] == '!' ) {
V_3 -> V_81 ( V_68 + 1 , V_75 , V_74 , V_7 ) ;
F_3 ( V_74 ) ;
F_3 ( V_104 ) ;
V_35 = 0 ;
goto V_50;
}
if ( V_76 ) {
V_77 = F_29 ( & V_76 , L_8 ) ;
V_35 = - V_43 ;
if ( ! strlen ( V_77 ) )
goto V_82;
V_35 = F_65 ( V_77 , 0 , & V_74 -> V_57 ) ;
if ( V_35 )
goto V_82;
}
if ( ! V_73 )
goto V_83;
if ( ! V_3 -> V_4 )
goto V_83;
V_35 = V_3 -> V_4 ( V_73 , V_74 , V_7 ) ;
if ( V_35 < 0 )
goto V_82;
V_83:
V_35 = F_107 ( V_112 -> V_89 -> V_111 ) ;
if ( ! V_35 ) {
V_35 = - V_53 ;
goto V_82;
}
V_35 = F_53 ( V_112 , 1 , 1 ) ;
if ( V_35 < 0 )
goto V_114;
V_35 = V_3 -> V_84 ( V_68 , V_75 , V_74 , V_7 ) ;
if ( ! V_35 ) {
V_35 = - V_85 ;
goto V_115;
} else if ( V_35 < 0 )
goto V_115;
V_35 = 0 ;
V_50:
return V_35 ;
V_115:
F_53 ( V_112 , 0 , 1 ) ;
V_114:
F_103 ( V_112 -> V_89 -> V_111 ) ;
V_82:
if ( V_3 -> V_4 )
V_3 -> V_4 ( NULL , V_74 , NULL ) ;
F_3 ( V_74 ) ;
F_3 ( V_104 ) ;
goto V_50;
}
static int F_108 ( char * V_68 ,
struct V_58 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_103 * V_104 = V_2 -> V_39 ;
struct V_103 * V_116 ;
struct V_1 * V_69 ;
int V_35 = 0 ;
F_6 (test, &file->triggers, list) {
V_116 = V_69 -> V_39 ;
if ( V_116 &&
( V_116 -> V_7 == V_104 -> V_7 ) ) {
V_35 = - V_70 ;
goto V_50;
}
}
if ( V_2 -> V_14 -> V_71 ) {
V_35 = V_2 -> V_14 -> V_71 ( V_2 -> V_14 , V_2 ) ;
if ( V_35 < 0 )
goto V_50;
}
F_59 ( & V_2 -> V_32 , & V_7 -> V_13 ) ;
V_35 ++ ;
F_57 ( V_7 ) ;
if ( F_50 ( V_7 , 1 ) < 0 ) {
F_60 ( & V_2 -> V_32 ) ;
F_57 ( V_7 ) ;
V_35 -- ;
}
V_50:
return V_35 ;
}
static void F_109 ( char * V_68 ,
struct V_58 * V_14 ,
struct V_1 * V_69 ,
struct V_6 * V_7 )
{
struct V_103 * V_116 = V_69 -> V_39 ;
struct V_103 * V_104 ;
struct V_1 * V_2 ;
bool V_72 = false ;
F_6 (data, &file->triggers, list) {
V_104 = V_2 -> V_39 ;
if ( V_104 &&
( V_104 -> V_7 == V_116 -> V_7 ) ) {
V_72 = true ;
F_60 ( & V_2 -> V_32 ) ;
F_50 ( V_7 , 0 ) ;
F_57 ( V_7 ) ;
break;
}
}
if ( V_72 && V_2 -> V_14 -> free )
V_2 -> V_14 -> free ( V_2 -> V_14 , V_2 ) ;
}
static struct V_58 *
F_110 ( char * V_52 , char * V_73 )
{
struct V_58 * V_14 ;
bool V_105 ;
V_105 = strcmp ( V_52 , V_108 ) == 0 ;
if ( V_105 )
V_14 = V_73 ? & V_117 :
& V_118 ;
else
V_14 = V_73 ? & V_119 :
& V_120 ;
return V_14 ;
}
static T_5 void F_111 ( void )
{
F_43 ( & V_121 ) ;
F_43 ( & V_122 ) ;
}
static T_5 int F_112 ( void )
{
int V_35 ;
V_35 = F_41 ( & V_121 ) ;
if ( F_90 ( V_35 < 0 ) )
return V_35 ;
V_35 = F_41 ( & V_122 ) ;
if ( F_90 ( V_35 < 0 ) )
F_111 () ;
return V_35 ;
}
static T_5 int F_113 ( void )
{
int V_35 ;
V_35 = F_41 ( & V_101 ) ;
if ( F_90 ( V_35 < 0 ) )
return V_35 ;
V_35 = F_41 ( & V_102 ) ;
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
