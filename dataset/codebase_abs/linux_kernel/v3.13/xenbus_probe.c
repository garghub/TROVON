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
struct V_18 * V_19 )
{
V_11 -> V_16 . V_19 = & V_19 -> V_19 ;
return F_34 ( & V_11 -> V_16 ) ;
}
void F_35 ( struct V_10 * V_11 )
{
F_36 ( & V_11 -> V_16 ) ;
}
static int F_37 ( struct V_6 * V_4 , void * V_51 )
{
struct V_3 * V_21 = F_4 ( V_4 ) ;
struct V_52 * V_53 = V_51 ;
if ( ! strcmp ( V_21 -> V_26 , V_53 -> V_26 ) ) {
V_53 -> V_4 = V_21 ;
F_29 ( V_4 ) ;
return 1 ;
}
return 0 ;
}
static struct V_3 * F_38 ( const char * V_26 ,
struct V_54 * V_19 )
{
struct V_52 V_53 = { . V_4 = NULL , . V_26 = V_26 } ;
F_39 ( V_19 , NULL , & V_53 , F_37 ) ;
return V_53 . V_4 ;
}
static int F_40 ( struct V_6 * V_4 , void * V_51 )
{
struct V_3 * V_21 = F_4 ( V_4 ) ;
struct V_52 * V_53 = V_51 ;
int V_32 = strlen ( V_53 -> V_26 ) ;
F_23 ( L_10 , V_53 -> V_26 ) ;
if ( strncmp ( V_21 -> V_26 , V_53 -> V_26 , V_32 ) )
return 0 ;
if ( ( strlen ( V_21 -> V_26 ) > V_32 ) && ( V_21 -> V_26 [ V_32 ] != '/' ) )
return 0 ;
V_53 -> V_4 = V_21 ;
F_29 ( V_4 ) ;
return 1 ;
}
static void F_41 ( const char * V_55 , struct V_54 * V_19 )
{
struct V_52 V_53 = { . V_26 = V_55 } ;
do {
V_53 . V_4 = NULL ;
F_39 ( V_19 , NULL , & V_53 , F_40 ) ;
if ( V_53 . V_4 ) {
F_42 ( & V_53 . V_4 -> V_4 ) ;
F_32 ( & V_53 . V_4 -> V_4 ) ;
}
} while ( V_53 . V_4 );
}
static void F_43 ( struct V_6 * V_4 )
{
if ( V_4 )
F_6 ( F_4 ( V_4 ) ) ;
}
static T_1 F_44 ( struct V_6 * V_4 ,
struct V_56 * V_57 , char * V_58 )
{
return sprintf ( V_58 , L_16 , F_4 ( V_4 ) -> V_26 ) ;
}
static T_1 F_45 ( struct V_6 * V_4 ,
struct V_56 * V_57 , char * V_58 )
{
return sprintf ( V_58 , L_16 , F_4 ( V_4 ) -> V_5 ) ;
}
static T_1 F_46 ( struct V_6 * V_4 ,
struct V_56 * V_57 , char * V_58 )
{
return sprintf ( V_58 , L_17 , V_4 -> V_19 -> V_59 ,
F_4 ( V_4 ) -> V_5 ) ;
}
int F_47 ( struct V_18 * V_19 ,
const char * type ,
const char * V_26 )
{
char V_60 [ V_61 ] ;
int V_24 ;
struct V_3 * V_21 ;
T_2 V_62 ;
char * V_63 ;
enum V_34 V_35 = F_19 ( V_26 ) ;
if ( V_35 != V_64 ) {
return 0 ;
}
V_62 = strlen ( V_26 ) + 1 + strlen ( type ) + 1 ;
V_21 = F_48 ( sizeof( * V_21 ) + V_62 , V_65 ) ;
if ( ! V_21 )
return - V_66 ;
V_21 -> V_35 = V_64 ;
V_63 = ( char * ) ( V_21 + 1 ) ;
strcpy ( V_63 , V_26 ) ;
V_21 -> V_26 = V_63 ;
V_63 += strlen ( V_63 ) + 1 ;
strcpy ( V_63 , type ) ;
V_21 -> V_5 = V_63 ;
F_49 ( & V_21 -> V_50 ) ;
V_21 -> V_4 . V_19 = & V_19 -> V_19 ;
V_21 -> V_4 . V_67 = F_43 ;
V_24 = V_19 -> V_68 ( V_60 , V_21 -> V_26 ) ;
if ( V_24 )
goto V_43;
F_50 ( & V_21 -> V_4 , L_10 , V_60 ) ;
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
char * * V_69 ;
unsigned int V_70 = 0 ;
int V_71 ;
V_69 = F_53 ( V_25 , V_19 -> V_72 , type , & V_70 ) ;
if ( F_54 ( V_69 ) )
return F_55 ( V_69 ) ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
V_24 = V_19 -> V_41 ( V_19 , type , V_69 [ V_71 ] ) ;
if ( V_24 )
break;
}
F_6 ( V_69 ) ;
return V_24 ;
}
int F_56 ( struct V_18 * V_19 )
{
int V_24 = 0 ;
char * * V_69 ;
unsigned int V_71 , V_70 ;
V_69 = F_53 ( V_25 , V_19 -> V_72 , L_5 , & V_70 ) ;
if ( F_54 ( V_69 ) )
return F_55 ( V_69 ) ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
V_24 = F_52 ( V_19 , V_69 [ V_71 ] ) ;
if ( V_24 )
break;
}
F_6 ( V_69 ) ;
return V_24 ;
}
static unsigned int F_57 ( const char * V_73 , char V_74 )
{
unsigned int V_71 , V_75 = 0 ;
for ( V_71 = 0 ; V_73 [ V_71 ] ; V_71 ++ )
if ( V_73 [ V_71 ] == V_74 )
V_75 ++ ;
return V_75 ;
}
static int F_58 ( const char * V_73 , char V_74 , unsigned int V_32 )
{
unsigned int V_71 ;
for ( V_71 = 0 ; V_73 [ V_71 ] ; V_71 ++ )
if ( V_73 [ V_71 ] == V_74 ) {
if ( V_32 == 0 )
return V_71 ;
V_32 -- ;
}
return ( V_32 == 0 ) ? V_71 : - V_76 ;
}
void F_59 ( const char * V_15 , struct V_18 * V_19 )
{
int V_77 , V_78 ;
struct V_3 * V_4 ;
char type [ V_61 ] ;
const char * V_79 , * V_72 ;
if ( F_57 ( V_15 , '/' ) < 2 )
return;
V_77 = F_16 ( V_25 , V_15 , L_5 ) ;
if ( ! V_77 ) {
F_41 ( V_15 , & V_19 -> V_19 ) ;
return;
}
V_79 = strchr ( V_15 , '/' ) + 1 ;
snprintf ( type , V_61 , L_18 , ( int ) strcspn ( V_79 , L_19 ) , V_79 ) ;
type [ V_61 - 1 ] = '\0' ;
V_78 = F_58 ( V_15 , '/' , V_19 -> V_80 ) ;
if ( V_78 < 0 )
return;
V_72 = F_60 ( V_65 , L_18 , V_78 , V_15 ) ;
if ( ! V_72 )
return;
V_4 = F_38 ( V_72 , & V_19 -> V_19 ) ;
if ( ! V_4 )
F_47 ( V_19 , type , V_72 ) ;
else
F_32 ( & V_4 -> V_4 ) ;
F_6 ( V_72 ) ;
}
int F_61 ( struct V_6 * V_4 )
{
int V_24 = 0 ;
struct V_10 * V_11 ;
struct V_3 * V_81
= F_11 ( V_4 , struct V_3 , V_4 ) ;
F_23 ( L_10 , V_81 -> V_26 ) ;
if ( V_4 -> V_16 == NULL )
return 0 ;
V_11 = F_3 ( V_4 -> V_16 ) ;
if ( V_11 -> V_82 )
V_24 = V_11 -> V_82 ( V_81 ) ;
if ( V_24 )
F_62 ( L_20 , F_63 ( V_4 ) , V_24 ) ;
return 0 ;
}
int F_64 ( struct V_6 * V_4 )
{
int V_24 ;
struct V_10 * V_11 ;
struct V_3 * V_81
= F_11 ( V_4 , struct V_3 , V_4 ) ;
F_23 ( L_10 , V_81 -> V_26 ) ;
if ( V_4 -> V_16 == NULL )
return 0 ;
V_11 = F_3 ( V_4 -> V_16 ) ;
V_24 = F_9 ( V_81 ) ;
if ( V_24 ) {
F_62 ( L_21 ,
F_63 ( V_4 ) , V_24 ) ;
return V_24 ;
}
V_81 -> V_35 = V_64 ;
if ( V_11 -> V_83 ) {
V_24 = V_11 -> V_83 ( V_81 ) ;
if ( V_24 ) {
F_62 ( L_22 , F_63 ( V_4 ) , V_24 ) ;
return V_24 ;
}
}
V_24 = F_10 ( V_81 ) ;
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
int F_66 ( struct V_84 * V_85 )
{
int V_75 = 0 ;
if ( V_86 > 0 )
V_75 = V_85 -> V_87 ( V_85 , 0 , NULL ) ;
else
F_67 ( & V_88 , V_85 ) ;
return V_75 ;
}
void F_68 ( struct V_84 * V_85 )
{
F_69 ( & V_88 , V_85 ) ;
}
void F_70 ( struct V_89 * V_90 )
{
V_86 = 1 ;
F_71 ( & V_88 , 0 , NULL ) ;
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
unsigned long V_91 = 0 ;
struct V_92 V_93 ;
V_91 = F_77 ( V_65 ) ;
if ( ! V_91 )
goto V_94;
V_95 = V_96 -> V_97 =
F_78 ( F_79 ( ( void * ) V_91 ) >>
V_98 ) ;
V_93 . V_99 = V_100 ;
V_93 . V_101 = V_100 ;
V_24 = F_80 ( V_102 ,
& V_93 ) ;
if ( V_24 == - V_103 )
goto V_94;
F_81 ( V_24 ) ;
V_104 = V_96 -> V_105 =
V_93 . V_106 ;
return 0 ;
V_94:
if ( V_91 != 0 )
F_82 ( V_91 ) ;
return V_24 ;
}
static int T_3 F_83 ( void )
{
int V_24 = 0 ;
T_4 V_107 = 0 ;
V_108 = V_109 ;
if ( ! F_73 () )
return - V_42 ;
F_84 () ;
if ( F_85 () )
V_108 = V_110 ;
if ( F_75 () )
V_108 = V_111 ;
if ( F_75 () && F_74 () )
V_108 = V_112 ;
if ( F_85 () && ! V_96 -> V_105 )
V_108 = V_112 ;
if ( F_85 () && V_96 -> V_105 )
V_86 = 1 ;
switch ( V_108 ) {
case V_112 :
V_24 = F_76 () ;
if ( V_24 )
goto V_113;
V_114 = F_86 ( V_95 ) ;
break;
case V_110 :
V_104 = V_96 -> V_105 ;
V_95 = V_96 -> V_97 ;
V_114 = F_86 ( V_95 ) ;
break;
case V_111 :
V_24 = F_87 ( V_115 , & V_107 ) ;
if ( V_24 )
goto V_113;
V_104 = ( int ) V_107 ;
V_24 = F_87 ( V_116 , & V_107 ) ;
if ( V_24 )
goto V_113;
V_95 = ( unsigned long ) V_107 ;
V_114 =
F_88 ( V_95 << V_98 , V_117 ) ;
break;
default:
F_62 ( L_25 ) ;
break;
}
V_24 = F_89 () ;
if ( V_24 ) {
F_62 ( L_26 , V_24 ) ;
goto V_113;
}
#ifdef F_90
F_91 ( L_27 , NULL ) ;
#endif
V_113:
return V_24 ;
}
