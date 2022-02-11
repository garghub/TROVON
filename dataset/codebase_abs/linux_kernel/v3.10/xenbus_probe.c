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
F_30 ( V_48 L_14 , V_49 ,
V_4 -> V_26 , F_20 ( V_4 -> V_35 ) ) ;
goto V_50;
}
F_26 ( V_4 , V_39 ) ;
V_45 = F_31 ( & V_4 -> V_51 , V_45 ) ;
if ( ! V_45 )
F_30 ( V_48 L_15 ,
V_49 , V_4 -> V_26 ) ;
V_50:
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
static int F_37 ( struct V_6 * V_4 , void * V_52 )
{
struct V_3 * V_21 = F_4 ( V_4 ) ;
struct V_53 * V_54 = V_52 ;
if ( ! strcmp ( V_21 -> V_26 , V_54 -> V_26 ) ) {
V_54 -> V_4 = V_21 ;
F_29 ( V_4 ) ;
return 1 ;
}
return 0 ;
}
static struct V_3 * F_38 ( const char * V_26 ,
struct V_55 * V_19 )
{
struct V_53 V_54 = { . V_4 = NULL , . V_26 = V_26 } ;
F_39 ( V_19 , NULL , & V_54 , F_37 ) ;
return V_54 . V_4 ;
}
static int F_40 ( struct V_6 * V_4 , void * V_52 )
{
struct V_3 * V_21 = F_4 ( V_4 ) ;
struct V_53 * V_54 = V_52 ;
int V_32 = strlen ( V_54 -> V_26 ) ;
F_23 ( L_10 , V_54 -> V_26 ) ;
if ( strncmp ( V_21 -> V_26 , V_54 -> V_26 , V_32 ) )
return 0 ;
if ( ( strlen ( V_21 -> V_26 ) > V_32 ) && ( V_21 -> V_26 [ V_32 ] != '/' ) )
return 0 ;
V_54 -> V_4 = V_21 ;
F_29 ( V_4 ) ;
return 1 ;
}
static void F_41 ( const char * V_56 , struct V_55 * V_19 )
{
struct V_53 V_54 = { . V_26 = V_56 } ;
do {
V_54 . V_4 = NULL ;
F_39 ( V_19 , NULL , & V_54 , F_40 ) ;
if ( V_54 . V_4 ) {
F_42 ( & V_54 . V_4 -> V_4 ) ;
F_32 ( & V_54 . V_4 -> V_4 ) ;
}
} while ( V_54 . V_4 );
}
static void F_43 ( struct V_6 * V_4 )
{
if ( V_4 )
F_6 ( F_4 ( V_4 ) ) ;
}
static T_1 F_44 ( struct V_6 * V_4 ,
struct V_57 * V_58 , char * V_59 )
{
return sprintf ( V_59 , L_16 , F_4 ( V_4 ) -> V_26 ) ;
}
static T_1 F_45 ( struct V_6 * V_4 ,
struct V_57 * V_58 , char * V_59 )
{
return sprintf ( V_59 , L_16 , F_4 ( V_4 ) -> V_5 ) ;
}
static T_1 F_46 ( struct V_6 * V_4 ,
struct V_57 * V_58 , char * V_59 )
{
return sprintf ( V_59 , L_17 , V_4 -> V_19 -> V_60 ,
F_4 ( V_4 ) -> V_5 ) ;
}
int F_47 ( struct V_18 * V_19 ,
const char * type ,
const char * V_26 )
{
char V_61 [ V_62 ] ;
int V_24 ;
struct V_3 * V_21 ;
T_2 V_63 ;
char * V_64 ;
enum V_34 V_35 = F_19 ( V_26 ) ;
if ( V_35 != V_65 ) {
return 0 ;
}
V_63 = strlen ( V_26 ) + 1 + strlen ( type ) + 1 ;
V_21 = F_48 ( sizeof( * V_21 ) + V_63 , V_66 ) ;
if ( ! V_21 )
return - V_67 ;
V_21 -> V_35 = V_65 ;
V_64 = ( char * ) ( V_21 + 1 ) ;
strcpy ( V_64 , V_26 ) ;
V_21 -> V_26 = V_64 ;
V_64 += strlen ( V_64 ) + 1 ;
strcpy ( V_64 , type ) ;
V_21 -> V_5 = V_64 ;
F_49 ( & V_21 -> V_51 ) ;
V_21 -> V_4 . V_19 = & V_19 -> V_19 ;
V_21 -> V_4 . V_68 = F_43 ;
V_24 = V_19 -> V_69 ( V_61 , V_21 -> V_26 ) ;
if ( V_24 )
goto V_43;
F_50 ( & V_21 -> V_4 , V_61 ) ;
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
char * * V_70 ;
unsigned int V_71 = 0 ;
int V_72 ;
V_70 = F_53 ( V_25 , V_19 -> V_73 , type , & V_71 ) ;
if ( F_54 ( V_70 ) )
return F_55 ( V_70 ) ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
V_24 = V_19 -> V_41 ( V_19 , type , V_70 [ V_72 ] ) ;
if ( V_24 )
break;
}
F_6 ( V_70 ) ;
return V_24 ;
}
int F_56 ( struct V_18 * V_19 )
{
int V_24 = 0 ;
char * * V_70 ;
unsigned int V_72 , V_71 ;
V_70 = F_53 ( V_25 , V_19 -> V_73 , L_5 , & V_71 ) ;
if ( F_54 ( V_70 ) )
return F_55 ( V_70 ) ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
V_24 = F_52 ( V_19 , V_70 [ V_72 ] ) ;
if ( V_24 )
break;
}
F_6 ( V_70 ) ;
return V_24 ;
}
static unsigned int F_57 ( const char * V_74 , char V_75 )
{
unsigned int V_72 , V_76 = 0 ;
for ( V_72 = 0 ; V_74 [ V_72 ] ; V_72 ++ )
if ( V_74 [ V_72 ] == V_75 )
V_76 ++ ;
return V_76 ;
}
static int F_58 ( const char * V_74 , char V_75 , unsigned int V_32 )
{
unsigned int V_72 ;
for ( V_72 = 0 ; V_74 [ V_72 ] ; V_72 ++ )
if ( V_74 [ V_72 ] == V_75 ) {
if ( V_32 == 0 )
return V_72 ;
V_32 -- ;
}
return ( V_32 == 0 ) ? V_72 : - V_77 ;
}
void F_59 ( const char * V_15 , struct V_18 * V_19 )
{
int V_78 , V_79 ;
struct V_3 * V_4 ;
char type [ V_62 ] ;
const char * V_80 , * V_73 ;
if ( F_57 ( V_15 , '/' ) < 2 )
return;
V_78 = F_16 ( V_25 , V_15 , L_5 ) ;
if ( ! V_78 ) {
F_41 ( V_15 , & V_19 -> V_19 ) ;
return;
}
V_80 = strchr ( V_15 , '/' ) + 1 ;
snprintf ( type , V_62 , L_18 , ( int ) strcspn ( V_80 , L_19 ) , V_80 ) ;
type [ V_62 - 1 ] = '\0' ;
V_79 = F_58 ( V_15 , '/' , V_19 -> V_81 ) ;
if ( V_79 < 0 )
return;
V_73 = F_60 ( V_66 , L_18 , V_79 , V_15 ) ;
if ( ! V_73 )
return;
V_4 = F_38 ( V_73 , & V_19 -> V_19 ) ;
if ( ! V_4 )
F_47 ( V_19 , type , V_73 ) ;
else
F_32 ( & V_4 -> V_4 ) ;
F_6 ( V_73 ) ;
}
int F_61 ( struct V_6 * V_4 )
{
int V_24 = 0 ;
struct V_10 * V_11 ;
struct V_3 * V_82
= F_11 ( V_4 , struct V_3 , V_4 ) ;
F_23 ( L_10 , V_82 -> V_26 ) ;
if ( V_4 -> V_16 == NULL )
return 0 ;
V_11 = F_3 ( V_4 -> V_16 ) ;
if ( V_11 -> V_83 )
V_24 = V_11 -> V_83 ( V_82 ) ;
if ( V_24 )
F_30 ( V_84
L_20 , F_62 ( V_4 ) , V_24 ) ;
return 0 ;
}
int F_63 ( struct V_6 * V_4 )
{
int V_24 ;
struct V_10 * V_11 ;
struct V_3 * V_82
= F_11 ( V_4 , struct V_3 , V_4 ) ;
F_23 ( L_10 , V_82 -> V_26 ) ;
if ( V_4 -> V_16 == NULL )
return 0 ;
V_11 = F_3 ( V_4 -> V_16 ) ;
V_24 = F_9 ( V_82 ) ;
if ( V_24 ) {
F_30 ( V_84
L_21 ,
F_62 ( V_4 ) , V_24 ) ;
return V_24 ;
}
V_82 -> V_35 = V_65 ;
if ( V_11 -> V_85 ) {
V_24 = V_11 -> V_85 ( V_82 ) ;
if ( V_24 ) {
F_30 ( V_84
L_22 ,
F_62 ( V_4 ) , V_24 ) ;
return V_24 ;
}
}
V_24 = F_10 ( V_82 ) ;
if ( V_24 ) {
F_30 ( V_84
L_23
L_24 , F_62 ( V_4 ) , V_24 ) ;
return V_24 ;
}
return 0 ;
}
int F_64 ( struct V_6 * V_4 )
{
F_23 ( L_25 ) ;
return 0 ;
}
int F_65 ( struct V_86 * V_87 )
{
int V_76 = 0 ;
if ( V_88 > 0 )
V_76 = V_87 -> V_89 ( V_87 , 0 , NULL ) ;
else
F_66 ( & V_90 , V_87 ) ;
return V_76 ;
}
void F_67 ( struct V_86 * V_87 )
{
F_68 ( & V_90 , V_87 ) ;
}
void F_69 ( struct V_91 * V_92 )
{
V_88 = 1 ;
F_70 ( & V_90 , 0 , NULL ) ;
}
static int T_3 F_71 ( void )
{
if ( ! F_72 () )
return - V_42 ;
if ( F_73 () || F_74 () )
return 0 ;
F_69 ( NULL ) ;
return 0 ;
}
static int T_3 F_75 ( void )
{
int V_24 = 0 ;
unsigned long V_93 = 0 ;
struct V_94 V_95 ;
V_93 = F_76 ( V_66 ) ;
if ( ! V_93 )
goto V_96;
V_97 = V_98 -> V_99 =
F_77 ( F_78 ( ( void * ) V_93 ) >>
V_100 ) ;
V_95 . V_101 = V_102 ;
V_95 . V_103 = V_102 ;
V_24 = F_79 ( V_104 ,
& V_95 ) ;
if ( V_24 == - V_105 )
goto V_96;
F_80 ( V_24 ) ;
V_106 = V_98 -> V_107 =
V_95 . V_108 ;
return 0 ;
V_96:
if ( V_93 != 0 )
F_81 ( V_93 ) ;
return V_24 ;
}
static int T_3 F_82 ( void )
{
int V_24 = 0 ;
T_4 V_109 = 0 ;
V_110 = V_111 ;
if ( ! F_72 () )
return - V_42 ;
F_83 () ;
if ( F_84 () )
V_110 = V_112 ;
if ( F_74 () )
V_110 = V_113 ;
if ( F_74 () && F_73 () )
V_110 = V_114 ;
if ( F_84 () && ! V_98 -> V_107 )
V_110 = V_114 ;
if ( F_84 () && V_98 -> V_107 )
V_88 = 1 ;
switch ( V_110 ) {
case V_114 :
V_24 = F_75 () ;
if ( V_24 )
goto V_115;
V_116 = F_85 ( V_97 ) ;
break;
case V_112 :
V_106 = V_98 -> V_107 ;
V_97 = V_98 -> V_99 ;
V_116 = F_85 ( V_97 ) ;
break;
case V_113 :
V_24 = F_86 ( V_117 , & V_109 ) ;
if ( V_24 )
goto V_115;
V_106 = ( int ) V_109 ;
V_24 = F_86 ( V_118 , & V_109 ) ;
if ( V_24 )
goto V_115;
V_97 = ( unsigned long ) V_109 ;
V_116 =
F_87 ( V_97 << V_100 , V_119 ) ;
break;
default:
F_88 ( L_26 ) ;
break;
}
V_24 = F_89 () ;
if ( V_24 ) {
F_30 ( V_84
L_27 , V_24 ) ;
goto V_115;
}
#ifdef F_90
F_91 ( L_28 , NULL ) ;
#endif
V_115:
return V_24 ;
}
