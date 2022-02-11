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
F_5 ( V_4 ) ;
if ( V_11 -> remove )
V_11 -> remove ( V_4 ) ;
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
struct V_18 * V_19 ,
struct V_52 * V_53 ,
const char * V_54 )
{
V_11 -> V_16 . V_55 = V_11 -> V_55 ;
V_11 -> V_16 . V_19 = & V_19 -> V_19 ;
V_11 -> V_16 . V_53 = V_53 ;
V_11 -> V_16 . V_54 = V_54 ;
return F_34 ( & V_11 -> V_16 ) ;
}
void F_35 ( struct V_10 * V_11 )
{
F_36 ( & V_11 -> V_16 ) ;
}
static int F_37 ( struct V_6 * V_4 , void * V_56 )
{
struct V_3 * V_21 = F_4 ( V_4 ) ;
struct V_57 * V_58 = V_56 ;
if ( ! strcmp ( V_21 -> V_26 , V_58 -> V_26 ) ) {
V_58 -> V_4 = V_21 ;
F_29 ( V_4 ) ;
return 1 ;
}
return 0 ;
}
struct V_3 * F_38 ( const char * V_26 ,
struct V_59 * V_19 )
{
struct V_57 V_58 = { . V_4 = NULL , . V_26 = V_26 } ;
F_39 ( V_19 , NULL , & V_58 , F_37 ) ;
return V_58 . V_4 ;
}
static int F_40 ( struct V_6 * V_4 , void * V_56 )
{
struct V_3 * V_21 = F_4 ( V_4 ) ;
struct V_57 * V_58 = V_56 ;
int V_32 = strlen ( V_58 -> V_26 ) ;
F_23 ( L_10 , V_58 -> V_26 ) ;
if ( strncmp ( V_21 -> V_26 , V_58 -> V_26 , V_32 ) )
return 0 ;
if ( ( strlen ( V_21 -> V_26 ) > V_32 ) && ( V_21 -> V_26 [ V_32 ] != '/' ) )
return 0 ;
V_58 -> V_4 = V_21 ;
F_29 ( V_4 ) ;
return 1 ;
}
static void F_41 ( const char * V_60 , struct V_59 * V_19 )
{
struct V_57 V_58 = { . V_26 = V_60 } ;
do {
V_58 . V_4 = NULL ;
F_39 ( V_19 , NULL , & V_58 , F_40 ) ;
if ( V_58 . V_4 ) {
F_42 ( & V_58 . V_4 -> V_4 ) ;
F_32 ( & V_58 . V_4 -> V_4 ) ;
}
} while ( V_58 . V_4 );
}
static void F_43 ( struct V_6 * V_4 )
{
if ( V_4 )
F_6 ( F_4 ( V_4 ) ) ;
}
static T_1 F_44 ( struct V_6 * V_4 ,
struct V_61 * V_62 , char * V_63 )
{
return sprintf ( V_63 , L_16 , F_4 ( V_4 ) -> V_26 ) ;
}
static T_1 F_45 ( struct V_6 * V_4 ,
struct V_61 * V_62 , char * V_63 )
{
return sprintf ( V_63 , L_16 , F_4 ( V_4 ) -> V_5 ) ;
}
static T_1 F_46 ( struct V_6 * V_4 ,
struct V_61 * V_62 , char * V_63 )
{
return sprintf ( V_63 , L_17 , V_4 -> V_19 -> V_55 ,
F_4 ( V_4 ) -> V_5 ) ;
}
int F_47 ( struct V_18 * V_19 ,
const char * type ,
const char * V_26 )
{
char V_64 [ V_65 ] ;
int V_24 ;
struct V_3 * V_21 ;
T_2 V_66 ;
char * V_67 ;
enum V_34 V_35 = F_19 ( V_26 ) ;
if ( V_35 != V_68 ) {
return 0 ;
}
V_66 = strlen ( V_26 ) + 1 + strlen ( type ) + 1 ;
V_21 = F_48 ( sizeof( * V_21 ) + V_66 , V_69 ) ;
if ( ! V_21 )
return - V_70 ;
V_21 -> V_35 = V_68 ;
V_67 = ( char * ) ( V_21 + 1 ) ;
strcpy ( V_67 , V_26 ) ;
V_21 -> V_26 = V_67 ;
V_67 += strlen ( V_67 ) + 1 ;
strcpy ( V_67 , type ) ;
V_21 -> V_5 = V_67 ;
F_49 ( & V_21 -> V_51 ) ;
V_21 -> V_4 . V_19 = & V_19 -> V_19 ;
V_21 -> V_4 . V_71 = F_43 ;
V_24 = V_19 -> V_72 ( V_64 , V_21 -> V_26 ) ;
if ( V_24 )
goto V_43;
F_50 ( & V_21 -> V_4 , V_64 ) ;
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
char * * V_73 ;
unsigned int V_74 = 0 ;
int V_75 ;
V_73 = F_53 ( V_25 , V_19 -> V_76 , type , & V_74 ) ;
if ( F_54 ( V_73 ) )
return F_55 ( V_73 ) ;
for ( V_75 = 0 ; V_75 < V_74 ; V_75 ++ ) {
V_24 = V_19 -> V_41 ( V_19 , type , V_73 [ V_75 ] ) ;
if ( V_24 )
break;
}
F_6 ( V_73 ) ;
return V_24 ;
}
int F_56 ( struct V_18 * V_19 )
{
int V_24 = 0 ;
char * * V_73 ;
unsigned int V_75 , V_74 ;
V_73 = F_53 ( V_25 , V_19 -> V_76 , L_5 , & V_74 ) ;
if ( F_54 ( V_73 ) )
return F_55 ( V_73 ) ;
for ( V_75 = 0 ; V_75 < V_74 ; V_75 ++ ) {
V_24 = F_52 ( V_19 , V_73 [ V_75 ] ) ;
if ( V_24 )
break;
}
F_6 ( V_73 ) ;
return V_24 ;
}
static unsigned int F_57 ( const char * V_77 , char V_78 )
{
unsigned int V_75 , V_79 = 0 ;
for ( V_75 = 0 ; V_77 [ V_75 ] ; V_75 ++ )
if ( V_77 [ V_75 ] == V_78 )
V_79 ++ ;
return V_79 ;
}
static int F_58 ( const char * V_77 , char V_78 , unsigned int V_32 )
{
unsigned int V_75 ;
for ( V_75 = 0 ; V_77 [ V_75 ] ; V_75 ++ )
if ( V_77 [ V_75 ] == V_78 ) {
if ( V_32 == 0 )
return V_75 ;
V_32 -- ;
}
return ( V_32 == 0 ) ? V_75 : - V_80 ;
}
void F_59 ( const char * V_15 , struct V_18 * V_19 )
{
int V_81 , V_82 ;
struct V_3 * V_4 ;
char type [ V_65 ] ;
const char * V_83 , * V_76 ;
if ( F_57 ( V_15 , '/' ) < 2 )
return;
V_81 = F_16 ( V_25 , V_15 , L_5 ) ;
if ( ! V_81 ) {
F_41 ( V_15 , & V_19 -> V_19 ) ;
return;
}
V_83 = strchr ( V_15 , '/' ) + 1 ;
snprintf ( type , V_65 , L_18 , ( int ) strcspn ( V_83 , L_19 ) , V_83 ) ;
type [ V_65 - 1 ] = '\0' ;
V_82 = F_58 ( V_15 , '/' , V_19 -> V_84 ) ;
if ( V_82 < 0 )
return;
V_76 = F_60 ( V_69 , L_18 , V_82 , V_15 ) ;
if ( ! V_76 )
return;
V_4 = F_38 ( V_76 , & V_19 -> V_19 ) ;
if ( ! V_4 )
F_47 ( V_19 , type , V_76 ) ;
else
F_32 ( & V_4 -> V_4 ) ;
F_6 ( V_76 ) ;
}
int F_61 ( struct V_6 * V_4 )
{
int V_24 = 0 ;
struct V_10 * V_11 ;
struct V_3 * V_85
= F_11 ( V_4 , struct V_3 , V_4 ) ;
F_23 ( L_10 , V_85 -> V_26 ) ;
if ( V_4 -> V_16 == NULL )
return 0 ;
V_11 = F_3 ( V_4 -> V_16 ) ;
if ( V_11 -> V_86 )
V_24 = V_11 -> V_86 ( V_85 ) ;
if ( V_24 )
F_30 ( V_87
L_20 , F_62 ( V_4 ) , V_24 ) ;
return 0 ;
}
int F_63 ( struct V_6 * V_4 )
{
int V_24 ;
struct V_10 * V_11 ;
struct V_3 * V_85
= F_11 ( V_4 , struct V_3 , V_4 ) ;
F_23 ( L_10 , V_85 -> V_26 ) ;
if ( V_4 -> V_16 == NULL )
return 0 ;
V_11 = F_3 ( V_4 -> V_16 ) ;
V_24 = F_9 ( V_85 ) ;
if ( V_24 ) {
F_30 ( V_87
L_21 ,
F_62 ( V_4 ) , V_24 ) ;
return V_24 ;
}
V_85 -> V_35 = V_68 ;
if ( V_11 -> V_88 ) {
V_24 = V_11 -> V_88 ( V_85 ) ;
if ( V_24 ) {
F_30 ( V_87
L_22 ,
F_62 ( V_4 ) , V_24 ) ;
return V_24 ;
}
}
V_24 = F_10 ( V_85 ) ;
if ( V_24 ) {
F_30 ( V_87
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
int F_65 ( struct V_89 * V_90 )
{
int V_79 = 0 ;
if ( V_91 > 0 )
V_79 = V_90 -> V_92 ( V_90 , 0 , NULL ) ;
else
F_66 ( & V_93 , V_90 ) ;
return V_79 ;
}
void F_67 ( struct V_89 * V_90 )
{
F_68 ( & V_93 , V_90 ) ;
}
void F_69 ( struct V_94 * V_95 )
{
V_91 = 1 ;
F_70 ( & V_93 , 0 , NULL ) ;
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
unsigned long V_96 = 0 ;
struct V_97 V_98 ;
V_96 = F_76 ( V_69 ) ;
if ( ! V_96 )
goto V_99;
V_100 = V_101 -> V_102 =
F_77 ( F_78 ( ( void * ) V_96 ) >>
V_103 ) ;
V_98 . V_104 = V_105 ;
V_98 . V_106 = V_105 ;
V_24 = F_79 ( V_107 ,
& V_98 ) ;
if ( V_24 == - V_108 )
goto V_99;
F_80 ( V_24 ) ;
V_109 = V_101 -> V_110 =
V_98 . V_111 ;
return 0 ;
V_99:
if ( V_96 != 0 )
F_81 ( V_96 ) ;
return V_24 ;
}
static int T_3 F_82 ( void )
{
int V_24 = 0 ;
if ( ! F_72 () )
return - V_42 ;
if ( F_74 () ) {
T_4 V_112 = 0 ;
V_24 = F_83 ( V_113 , & V_112 ) ;
if ( V_24 )
goto V_114;
V_109 = ( int ) V_112 ;
V_24 = F_83 ( V_115 , & V_112 ) ;
if ( V_24 )
goto V_114;
V_100 = ( unsigned long ) V_112 ;
V_116 = F_84 ( V_100 << V_103 , V_117 ) ;
} else {
V_109 = V_101 -> V_110 ;
V_100 = V_101 -> V_102 ;
if ( V_109 )
V_91 = 1 ;
else {
V_24 = F_75 () ;
if ( V_24 )
goto V_114;
}
V_116 = F_85 ( V_100 ) ;
}
V_24 = F_86 () ;
if ( V_24 ) {
F_30 ( V_87
L_26 , V_24 ) ;
goto V_114;
}
#ifdef F_87
F_88 ( L_27 , NULL ) ;
#endif
V_114:
return V_24 ;
}
