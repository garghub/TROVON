static const struct V_1 *
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
for (; * V_2 -> V_5 != '\0' ; V_2 ++ ) {
if ( ! strcmp ( V_2 -> V_5 , V_4 -> V_5 ) )
return V_2 ;
}
return NULL ;
}
int F_2 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
if ( ! V_11 -> V_12 )
return 0 ;
return F_1 ( V_11 -> V_12 , F_4 ( V_7 ) ) != NULL ;
}
static void F_5 ( struct V_3 * V_4 )
{
F_6 ( V_4 -> V_13 ) ;
V_4 -> V_13 = NULL ;
}
static void F_7 ( struct V_3 * V_4 )
{
if ( V_4 -> V_14 . V_15 ) {
F_8 ( & V_4 -> V_14 ) ;
F_6 ( V_4 -> V_14 . V_15 ) ;
V_4 -> V_14 . V_15 = NULL ;
}
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_3 ( V_4 -> V_4 . V_16 ) ;
F_7 ( V_4 ) ;
F_5 ( V_4 ) ;
return V_11 -> V_17 ( V_4 ) ;
}
static int F_10 ( struct V_3 * V_4 )
{
struct V_18 * V_19 =
F_11 ( V_4 -> V_4 . V_19 , struct V_18 , V_19 ) ;
return F_12 ( V_4 , & V_4 -> V_14 ,
V_19 -> V_20 ,
L_1 , V_4 -> V_13 , L_2 ) ;
}
int F_13 ( struct V_3 * V_21 ,
char * V_22 , char * V_23 )
{
int V_24 = F_14 ( V_25 , V_21 -> V_26 ,
V_22 , L_3 , & V_21 -> V_27 ,
V_23 , NULL , & V_21 -> V_13 ,
NULL ) ;
if ( V_24 ) {
F_15 ( V_21 , V_24 ,
L_4 ,
V_21 -> V_26 ) ;
return V_24 ;
}
if ( strlen ( V_21 -> V_13 ) == 0 ||
! F_16 ( V_25 , V_21 -> V_13 , L_5 ) ) {
F_15 ( V_21 , - V_28 ,
L_6
L_7 ,
V_21 -> V_26 ) ;
F_5 ( V_21 ) ;
return - V_28 ;
}
return 0 ;
}
void F_17 ( struct V_29 * V_30 ,
const char * * V_31 , unsigned int V_32 ,
int V_33 )
{
struct V_3 * V_4 =
F_11 ( V_30 , struct V_3 , V_14 ) ;
struct V_10 * V_11 = F_3 ( V_4 -> V_4 . V_16 ) ;
enum V_34 V_35 ;
if ( ! V_4 -> V_13 ||
strncmp ( V_4 -> V_13 , V_31 [ V_36 ] ,
strlen ( V_4 -> V_13 ) ) ) {
F_18 ( & V_4 -> V_4 , L_8 ,
V_31 [ V_36 ] ) ;
return;
}
V_35 = F_19 ( V_4 -> V_13 ) ;
F_18 ( & V_4 -> V_4 , L_9 ,
V_35 , F_20 ( V_35 ) , V_4 -> V_14 . V_15 ,
V_31 [ V_36 ] ) ;
if ( V_37 > V_38 ) {
if ( V_33 && ( V_35 == V_39 ) )
F_21 ( V_4 ) ;
return;
}
if ( V_11 -> V_20 )
V_11 -> V_20 ( V_4 , V_35 ) ;
}
int F_22 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_4 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( V_7 -> V_16 ) ;
const struct V_1 * V_40 ;
int V_24 ;
F_23 ( L_10 , V_4 -> V_26 ) ;
if ( ! V_11 -> V_41 ) {
V_24 = - V_42 ;
goto V_43;
}
V_40 = F_1 ( V_11 -> V_12 , V_4 ) ;
if ( ! V_40 ) {
V_24 = - V_42 ;
goto V_43;
}
V_24 = F_9 ( V_4 ) ;
if ( V_24 ) {
F_24 ( & V_4 -> V_4 , L_11 ,
V_4 -> V_26 ) ;
return V_24 ;
}
V_24 = V_11 -> V_41 ( V_4 , V_40 ) ;
if ( V_24 )
goto V_43;
V_24 = F_10 ( V_4 ) ;
if ( V_24 ) {
F_24 ( & V_4 -> V_4 , L_12 ,
V_4 -> V_26 ) ;
return V_24 ;
}
return 0 ;
V_43:
F_25 ( V_4 , V_24 , L_13 , V_4 -> V_26 ) ;
F_26 ( V_4 , V_44 ) ;
return V_24 ;
}
int F_27 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_4 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( V_7 -> V_16 ) ;
F_23 ( L_10 , V_4 -> V_26 ) ;
F_7 ( V_4 ) ;
if ( V_11 -> remove )
V_11 -> remove ( V_4 ) ;
F_5 ( V_4 ) ;
F_26 ( V_4 , V_44 ) ;
return 0 ;
}
void F_28 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_4 ( V_7 ) ;
unsigned long V_45 = 5 * V_46 ;
F_23 ( L_10 , V_4 -> V_26 ) ;
F_29 ( & V_4 -> V_4 ) ;
if ( V_4 -> V_35 != V_47 ) {
F_30 ( L_14 ,
V_48 , V_4 -> V_26 , F_20 ( V_4 -> V_35 ) ) ;
goto V_49;
}
F_26 ( V_4 , V_39 ) ;
V_45 = F_31 ( & V_4 -> V_50 , V_45 ) ;
if ( ! V_45 )
F_30 ( L_15 ,
V_48 , V_4 -> V_26 ) ;
V_49:
F_32 ( & V_4 -> V_4 ) ;
}
int F_33 ( struct V_10 * V_11 ,
struct V_18 * V_19 ,
struct V_51 * V_52 , const char * V_53 )
{
V_11 -> V_16 . V_54 = V_11 -> V_54 ? V_11 -> V_54 : V_11 -> V_12 [ 0 ] . V_5 ;
V_11 -> V_16 . V_19 = & V_19 -> V_19 ;
V_11 -> V_16 . V_52 = V_52 ;
V_11 -> V_16 . V_53 = V_53 ;
return F_34 ( & V_11 -> V_16 ) ;
}
void F_35 ( struct V_10 * V_11 )
{
F_36 ( & V_11 -> V_16 ) ;
}
static int F_37 ( struct V_6 * V_4 , void * V_55 )
{
struct V_3 * V_21 = F_4 ( V_4 ) ;
struct V_56 * V_57 = V_55 ;
if ( ! strcmp ( V_21 -> V_26 , V_57 -> V_26 ) ) {
V_57 -> V_4 = V_21 ;
F_29 ( V_4 ) ;
return 1 ;
}
return 0 ;
}
static struct V_3 * F_38 ( const char * V_26 ,
struct V_58 * V_19 )
{
struct V_56 V_57 = { . V_4 = NULL , . V_26 = V_26 } ;
F_39 ( V_19 , NULL , & V_57 , F_37 ) ;
return V_57 . V_4 ;
}
static int F_40 ( struct V_6 * V_4 , void * V_55 )
{
struct V_3 * V_21 = F_4 ( V_4 ) ;
struct V_56 * V_57 = V_55 ;
int V_32 = strlen ( V_57 -> V_26 ) ;
F_23 ( L_10 , V_57 -> V_26 ) ;
if ( strncmp ( V_21 -> V_26 , V_57 -> V_26 , V_32 ) )
return 0 ;
if ( ( strlen ( V_21 -> V_26 ) > V_32 ) && ( V_21 -> V_26 [ V_32 ] != '/' ) )
return 0 ;
V_57 -> V_4 = V_21 ;
F_29 ( V_4 ) ;
return 1 ;
}
static void F_41 ( const char * V_59 , struct V_58 * V_19 )
{
struct V_56 V_57 = { . V_26 = V_59 } ;
do {
V_57 . V_4 = NULL ;
F_39 ( V_19 , NULL , & V_57 , F_40 ) ;
if ( V_57 . V_4 ) {
F_42 ( & V_57 . V_4 -> V_4 ) ;
F_32 ( & V_57 . V_4 -> V_4 ) ;
}
} while ( V_57 . V_4 );
}
static void F_43 ( struct V_6 * V_4 )
{
if ( V_4 )
F_6 ( F_4 ( V_4 ) ) ;
}
static T_1 F_44 ( struct V_6 * V_4 ,
struct V_60 * V_61 , char * V_62 )
{
return sprintf ( V_62 , L_16 , F_4 ( V_4 ) -> V_26 ) ;
}
static T_1 F_45 ( struct V_6 * V_4 ,
struct V_60 * V_61 , char * V_62 )
{
return sprintf ( V_62 , L_16 , F_4 ( V_4 ) -> V_5 ) ;
}
static T_1 F_46 ( struct V_6 * V_4 ,
struct V_60 * V_61 , char * V_62 )
{
return sprintf ( V_62 , L_17 , V_4 -> V_19 -> V_54 ,
F_4 ( V_4 ) -> V_5 ) ;
}
int F_47 ( struct V_18 * V_19 ,
const char * type ,
const char * V_26 )
{
char V_63 [ V_64 ] ;
int V_24 ;
struct V_3 * V_21 ;
T_2 V_65 ;
char * V_66 ;
enum V_34 V_35 = F_19 ( V_26 ) ;
if ( V_35 != V_67 ) {
return 0 ;
}
V_65 = strlen ( V_26 ) + 1 + strlen ( type ) + 1 ;
V_21 = F_48 ( sizeof( * V_21 ) + V_65 , V_68 ) ;
if ( ! V_21 )
return - V_69 ;
V_21 -> V_35 = V_67 ;
V_66 = ( char * ) ( V_21 + 1 ) ;
strcpy ( V_66 , V_26 ) ;
V_21 -> V_26 = V_66 ;
V_66 += strlen ( V_66 ) + 1 ;
strcpy ( V_66 , type ) ;
V_21 -> V_5 = V_66 ;
F_49 ( & V_21 -> V_50 ) ;
V_21 -> V_4 . V_19 = & V_19 -> V_19 ;
V_21 -> V_4 . V_70 = F_43 ;
V_24 = V_19 -> V_71 ( V_63 , V_21 -> V_26 ) ;
if ( V_24 )
goto V_43;
F_50 ( & V_21 -> V_4 , L_10 , V_63 ) ;
V_24 = F_51 ( & V_21 -> V_4 ) ;
if ( V_24 )
goto V_43;
return 0 ;
V_43:
F_6 ( V_21 ) ;
return V_24 ;
}
static int F_52 ( struct V_18 * V_19 , const char * type )
{
int V_24 = 0 ;
char * * V_72 ;
unsigned int V_73 = 0 ;
int V_74 ;
V_72 = F_53 ( V_25 , V_19 -> V_75 , type , & V_73 ) ;
if ( F_54 ( V_72 ) )
return F_55 ( V_72 ) ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ ) {
V_24 = V_19 -> V_41 ( V_19 , type , V_72 [ V_74 ] ) ;
if ( V_24 )
break;
}
F_6 ( V_72 ) ;
return V_24 ;
}
int F_56 ( struct V_18 * V_19 )
{
int V_24 = 0 ;
char * * V_72 ;
unsigned int V_74 , V_73 ;
V_72 = F_53 ( V_25 , V_19 -> V_75 , L_5 , & V_73 ) ;
if ( F_54 ( V_72 ) )
return F_55 ( V_72 ) ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ ) {
V_24 = F_52 ( V_19 , V_72 [ V_74 ] ) ;
if ( V_24 )
break;
}
F_6 ( V_72 ) ;
return V_24 ;
}
static unsigned int F_57 ( const char * V_76 , char V_77 )
{
unsigned int V_74 , V_78 = 0 ;
for ( V_74 = 0 ; V_76 [ V_74 ] ; V_74 ++ )
if ( V_76 [ V_74 ] == V_77 )
V_78 ++ ;
return V_78 ;
}
static int F_58 ( const char * V_76 , char V_77 , unsigned int V_32 )
{
unsigned int V_74 ;
for ( V_74 = 0 ; V_76 [ V_74 ] ; V_74 ++ )
if ( V_76 [ V_74 ] == V_77 ) {
if ( V_32 == 0 )
return V_74 ;
V_32 -- ;
}
return ( V_32 == 0 ) ? V_74 : - V_79 ;
}
void F_59 ( const char * V_15 , struct V_18 * V_19 )
{
int V_80 , V_81 ;
struct V_3 * V_4 ;
char type [ V_64 ] ;
const char * V_82 , * V_75 ;
if ( F_57 ( V_15 , '/' ) < 2 )
return;
V_80 = F_16 ( V_25 , V_15 , L_5 ) ;
if ( ! V_80 ) {
F_41 ( V_15 , & V_19 -> V_19 ) ;
return;
}
V_82 = strchr ( V_15 , '/' ) + 1 ;
snprintf ( type , V_64 , L_18 , ( int ) strcspn ( V_82 , L_19 ) , V_82 ) ;
type [ V_64 - 1 ] = '\0' ;
V_81 = F_58 ( V_15 , '/' , V_19 -> V_83 ) ;
if ( V_81 < 0 )
return;
V_75 = F_60 ( V_68 , L_18 , V_81 , V_15 ) ;
if ( ! V_75 )
return;
V_4 = F_38 ( V_75 , & V_19 -> V_19 ) ;
if ( ! V_4 )
F_47 ( V_19 , type , V_75 ) ;
else
F_32 ( & V_4 -> V_4 ) ;
F_6 ( V_75 ) ;
}
int F_61 ( struct V_6 * V_4 )
{
int V_24 = 0 ;
struct V_10 * V_11 ;
struct V_3 * V_84
= F_11 ( V_4 , struct V_3 , V_4 ) ;
F_23 ( L_10 , V_84 -> V_26 ) ;
if ( V_4 -> V_16 == NULL )
return 0 ;
V_11 = F_3 ( V_4 -> V_16 ) ;
if ( V_11 -> V_85 )
V_24 = V_11 -> V_85 ( V_84 ) ;
if ( V_24 )
F_62 ( L_20 , F_63 ( V_4 ) , V_24 ) ;
return 0 ;
}
int F_64 ( struct V_6 * V_4 )
{
int V_24 ;
struct V_10 * V_11 ;
struct V_3 * V_84
= F_11 ( V_4 , struct V_3 , V_4 ) ;
F_23 ( L_10 , V_84 -> V_26 ) ;
if ( V_4 -> V_16 == NULL )
return 0 ;
V_11 = F_3 ( V_4 -> V_16 ) ;
V_24 = F_9 ( V_84 ) ;
if ( V_24 ) {
F_62 ( L_21 ,
F_63 ( V_4 ) , V_24 ) ;
return V_24 ;
}
V_84 -> V_35 = V_67 ;
if ( V_11 -> V_86 ) {
V_24 = V_11 -> V_86 ( V_84 ) ;
if ( V_24 ) {
F_62 ( L_22 , F_63 ( V_4 ) , V_24 ) ;
return V_24 ;
}
}
V_24 = F_10 ( V_84 ) ;
if ( V_24 ) {
F_62 ( L_23 ,
F_63 ( V_4 ) , V_24 ) ;
return V_24 ;
}
return 0 ;
}
int F_65 ( struct V_6 * V_4 )
{
F_23 ( L_24 ) ;
return 0 ;
}
int F_66 ( struct V_87 * V_88 )
{
int V_78 = 0 ;
if ( V_89 > 0 )
V_78 = V_88 -> V_90 ( V_88 , 0 , NULL ) ;
else
F_67 ( & V_91 , V_88 ) ;
return V_78 ;
}
void F_68 ( struct V_87 * V_88 )
{
F_69 ( & V_91 , V_88 ) ;
}
void F_70 ( struct V_92 * V_93 )
{
V_89 = 1 ;
F_71 ( & V_91 , 0 , NULL ) ;
}
static int T_3 F_72 ( void )
{
if ( ! F_73 () )
return - V_42 ;
if ( F_74 () || F_75 () )
return 0 ;
F_70 ( NULL ) ;
return 0 ;
}
static int T_3 F_76 ( void )
{
int V_24 = 0 ;
unsigned long V_94 = 0 ;
struct V_95 V_96 ;
V_94 = F_77 ( V_68 ) ;
if ( ! V_94 )
goto V_97;
V_98 = V_99 -> V_100 =
F_78 ( F_79 ( ( void * ) V_94 ) >>
V_101 ) ;
V_96 . V_102 = V_103 ;
V_96 . V_104 = V_103 ;
V_24 = F_80 ( V_105 ,
& V_96 ) ;
if ( V_24 == - V_106 )
goto V_97;
F_81 ( V_24 ) ;
V_107 = V_99 -> V_108 =
V_96 . V_109 ;
return 0 ;
V_97:
if ( V_94 != 0 )
F_82 ( V_94 ) ;
return V_24 ;
}
static int F_83 ( struct V_87 * V_88 ,
unsigned long V_110 , void * V_55 )
{
int V_24 = 0 ;
if ( F_75 () ) {
T_4 V_111 ;
V_24 = F_84 ( V_112 , & V_111 ) ;
if ( ! V_24 && V_111 )
V_107 = V_111 ;
else
F_62 ( L_25 ,
V_24 ) ;
} else
V_107 = V_99 -> V_108 ;
return V_24 ;
}
static int T_3 F_85 ( void )
{
int V_24 = 0 ;
T_4 V_111 = 0 ;
V_113 = V_114 ;
if ( ! F_73 () )
return - V_42 ;
F_86 () ;
if ( F_87 () )
V_113 = V_115 ;
if ( F_75 () )
V_113 = V_116 ;
if ( F_75 () && F_74 () )
V_113 = V_117 ;
if ( F_87 () && ! V_99 -> V_108 )
V_113 = V_117 ;
if ( F_87 () && V_99 -> V_108 )
V_89 = 1 ;
switch ( V_113 ) {
case V_117 :
V_24 = F_76 () ;
if ( V_24 )
goto V_118;
V_119 = F_88 ( V_98 ) ;
break;
case V_115 :
V_107 = V_99 -> V_108 ;
V_98 = V_99 -> V_100 ;
V_119 = F_88 ( V_98 ) ;
break;
case V_116 :
V_24 = F_84 ( V_112 , & V_111 ) ;
if ( V_24 )
goto V_118;
V_107 = ( int ) V_111 ;
V_24 = F_84 ( V_120 , & V_111 ) ;
if ( V_24 )
goto V_118;
V_98 = ( unsigned long ) V_111 ;
V_119 =
F_89 ( V_98 << V_101 , V_121 ) ;
break;
default:
F_62 ( L_26 ) ;
break;
}
V_24 = F_90 () ;
if ( V_24 ) {
F_62 ( L_27 , V_24 ) ;
goto V_118;
}
if ( ( V_113 != V_117 ) &&
( V_113 != V_114 ) )
F_91 ( & V_122 ) ;
#ifdef F_92
F_93 ( L_28 , NULL ) ;
#endif
V_118:
return V_24 ;
}
