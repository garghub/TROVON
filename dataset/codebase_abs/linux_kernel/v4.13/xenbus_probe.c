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
const char * V_31 , const char * V_32 ,
int V_33 )
{
struct V_3 * V_4 =
F_11 ( V_30 , struct V_3 , V_14 ) ;
struct V_10 * V_11 = F_3 ( V_4 -> V_4 . V_16 ) ;
enum V_34 V_35 ;
if ( ! V_4 -> V_13 ||
strncmp ( V_4 -> V_13 , V_31 , strlen ( V_4 -> V_13 ) ) ) {
F_18 ( & V_4 -> V_4 , L_8 , V_31 ) ;
return;
}
V_35 = F_19 ( V_4 -> V_13 ) ;
F_18 ( & V_4 -> V_4 , L_9 ,
V_35 , F_20 ( V_35 ) , V_4 -> V_14 . V_15 , V_31 ) ;
if ( V_36 > V_37 ) {
if ( V_33 && ( V_35 == V_38 ) )
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
const struct V_1 * V_39 ;
int V_24 ;
F_23 ( L_10 , V_4 -> V_26 ) ;
if ( ! V_11 -> V_40 ) {
V_24 = - V_41 ;
goto V_42;
}
V_39 = F_1 ( V_11 -> V_12 , V_4 ) ;
if ( ! V_39 ) {
V_24 = - V_41 ;
goto V_42;
}
V_24 = F_9 ( V_4 ) ;
if ( V_24 ) {
F_24 ( & V_4 -> V_4 , L_11 ,
V_4 -> V_26 ) ;
return V_24 ;
}
V_24 = V_11 -> V_40 ( V_4 , V_39 ) ;
if ( V_24 )
goto V_42;
V_24 = F_10 ( V_4 ) ;
if ( V_24 ) {
F_24 ( & V_4 -> V_4 , L_12 ,
V_4 -> V_26 ) ;
return V_24 ;
}
return 0 ;
V_42:
F_25 ( V_4 , V_24 , L_13 , V_4 -> V_26 ) ;
F_26 ( V_4 , V_43 ) ;
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
F_26 ( V_4 , V_43 ) ;
return 0 ;
}
void F_28 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_4 ( V_7 ) ;
unsigned long V_44 = 5 * V_45 ;
F_23 ( L_10 , V_4 -> V_26 ) ;
F_29 ( & V_4 -> V_4 ) ;
if ( V_4 -> V_35 != V_46 ) {
F_30 ( L_14 ,
V_47 , V_4 -> V_26 , F_20 ( V_4 -> V_35 ) ) ;
goto V_48;
}
F_26 ( V_4 , V_38 ) ;
V_44 = F_31 ( & V_4 -> V_49 , V_44 ) ;
if ( ! V_44 )
F_30 ( L_15 ,
V_47 , V_4 -> V_26 ) ;
V_48:
F_32 ( & V_4 -> V_4 ) ;
}
int F_33 ( struct V_10 * V_11 ,
struct V_18 * V_19 ,
struct V_50 * V_51 , const char * V_52 )
{
V_11 -> V_16 . V_53 = V_11 -> V_53 ? V_11 -> V_53 : V_11 -> V_12 [ 0 ] . V_5 ;
V_11 -> V_16 . V_19 = & V_19 -> V_19 ;
V_11 -> V_16 . V_51 = V_51 ;
V_11 -> V_16 . V_52 = V_52 ;
return F_34 ( & V_11 -> V_16 ) ;
}
void F_35 ( struct V_10 * V_11 )
{
F_36 ( & V_11 -> V_16 ) ;
}
static int F_37 ( struct V_6 * V_4 , void * V_54 )
{
struct V_3 * V_21 = F_4 ( V_4 ) ;
struct V_55 * V_56 = V_54 ;
if ( ! strcmp ( V_21 -> V_26 , V_56 -> V_26 ) ) {
V_56 -> V_4 = V_21 ;
F_29 ( V_4 ) ;
return 1 ;
}
return 0 ;
}
static struct V_3 * F_38 ( const char * V_26 ,
struct V_57 * V_19 )
{
struct V_55 V_56 = { . V_4 = NULL , . V_26 = V_26 } ;
F_39 ( V_19 , NULL , & V_56 , F_37 ) ;
return V_56 . V_4 ;
}
static int F_40 ( struct V_6 * V_4 , void * V_54 )
{
struct V_3 * V_21 = F_4 ( V_4 ) ;
struct V_55 * V_56 = V_54 ;
int V_58 = strlen ( V_56 -> V_26 ) ;
F_23 ( L_10 , V_56 -> V_26 ) ;
if ( strncmp ( V_21 -> V_26 , V_56 -> V_26 , V_58 ) )
return 0 ;
if ( ( strlen ( V_21 -> V_26 ) > V_58 ) && ( V_21 -> V_26 [ V_58 ] != '/' ) )
return 0 ;
V_56 -> V_4 = V_21 ;
F_29 ( V_4 ) ;
return 1 ;
}
static void F_41 ( const char * V_31 , struct V_57 * V_19 )
{
struct V_55 V_56 = { . V_26 = V_31 } ;
do {
V_56 . V_4 = NULL ;
F_39 ( V_19 , NULL , & V_56 , F_40 ) ;
if ( V_56 . V_4 ) {
F_42 ( & V_56 . V_4 -> V_4 ) ;
F_32 ( & V_56 . V_4 -> V_4 ) ;
}
} while ( V_56 . V_4 );
}
static void F_43 ( struct V_6 * V_4 )
{
if ( V_4 )
F_6 ( F_4 ( V_4 ) ) ;
}
static T_1 F_44 ( struct V_6 * V_4 ,
struct V_59 * V_60 , char * V_61 )
{
return sprintf ( V_61 , L_16 , F_4 ( V_4 ) -> V_26 ) ;
}
static T_1 F_45 ( struct V_6 * V_4 ,
struct V_59 * V_60 , char * V_61 )
{
return sprintf ( V_61 , L_16 , F_4 ( V_4 ) -> V_5 ) ;
}
static T_1 F_46 ( struct V_6 * V_4 ,
struct V_59 * V_60 , char * V_61 )
{
return sprintf ( V_61 , L_17 , V_4 -> V_19 -> V_53 ,
F_4 ( V_4 ) -> V_5 ) ;
}
int F_47 ( struct V_18 * V_19 ,
const char * type ,
const char * V_26 )
{
char V_62 [ V_63 ] ;
int V_24 ;
struct V_3 * V_21 ;
T_2 V_64 ;
char * V_65 ;
enum V_34 V_35 = F_19 ( V_26 ) ;
if ( V_35 != V_66 ) {
return 0 ;
}
V_64 = strlen ( V_26 ) + 1 + strlen ( type ) + 1 ;
V_21 = F_48 ( sizeof( * V_21 ) + V_64 , V_67 ) ;
if ( ! V_21 )
return - V_68 ;
V_21 -> V_35 = V_66 ;
V_65 = ( char * ) ( V_21 + 1 ) ;
strcpy ( V_65 , V_26 ) ;
V_21 -> V_26 = V_65 ;
V_65 += strlen ( V_65 ) + 1 ;
strcpy ( V_65 , type ) ;
V_21 -> V_5 = V_65 ;
F_49 ( & V_21 -> V_49 ) ;
V_21 -> V_4 . V_19 = & V_19 -> V_19 ;
V_21 -> V_4 . V_69 = F_43 ;
V_24 = V_19 -> V_70 ( V_62 , V_21 -> V_26 ) ;
if ( V_24 )
goto V_42;
F_50 ( & V_21 -> V_4 , L_10 , V_62 ) ;
V_24 = F_51 ( & V_21 -> V_4 ) ;
if ( V_24 )
goto V_42;
return 0 ;
V_42:
F_6 ( V_21 ) ;
return V_24 ;
}
static int F_52 ( struct V_18 * V_19 , const char * type )
{
int V_24 = 0 ;
char * * V_71 ;
unsigned int V_72 = 0 ;
int V_73 ;
V_71 = F_53 ( V_25 , V_19 -> V_74 , type , & V_72 ) ;
if ( F_54 ( V_71 ) )
return F_55 ( V_71 ) ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
V_24 = V_19 -> V_40 ( V_19 , type , V_71 [ V_73 ] ) ;
if ( V_24 )
break;
}
F_6 ( V_71 ) ;
return V_24 ;
}
int F_56 ( struct V_18 * V_19 )
{
int V_24 = 0 ;
char * * V_71 ;
unsigned int V_73 , V_72 ;
V_71 = F_53 ( V_25 , V_19 -> V_74 , L_5 , & V_72 ) ;
if ( F_54 ( V_71 ) )
return F_55 ( V_71 ) ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
V_24 = F_52 ( V_19 , V_71 [ V_73 ] ) ;
if ( V_24 )
break;
}
F_6 ( V_71 ) ;
return V_24 ;
}
static unsigned int F_57 ( const char * V_75 , char V_76 )
{
unsigned int V_73 , V_77 = 0 ;
for ( V_73 = 0 ; V_75 [ V_73 ] ; V_73 ++ )
if ( V_75 [ V_73 ] == V_76 )
V_77 ++ ;
return V_77 ;
}
static int F_58 ( const char * V_75 , char V_76 , unsigned int V_58 )
{
unsigned int V_73 ;
for ( V_73 = 0 ; V_75 [ V_73 ] ; V_73 ++ )
if ( V_75 [ V_73 ] == V_76 ) {
if ( V_58 == 0 )
return V_73 ;
V_58 -- ;
}
return ( V_58 == 0 ) ? V_73 : - V_78 ;
}
void F_59 ( const char * V_15 , struct V_18 * V_19 )
{
int V_79 , V_80 ;
struct V_3 * V_4 ;
char type [ V_63 ] ;
const char * V_81 , * V_74 ;
if ( F_57 ( V_15 , '/' ) < 2 )
return;
V_79 = F_16 ( V_25 , V_15 , L_5 ) ;
if ( ! V_79 ) {
F_41 ( V_15 , & V_19 -> V_19 ) ;
return;
}
V_81 = strchr ( V_15 , '/' ) + 1 ;
snprintf ( type , V_63 , L_18 , ( int ) strcspn ( V_81 , L_19 ) , V_81 ) ;
type [ V_63 - 1 ] = '\0' ;
V_80 = F_58 ( V_15 , '/' , V_19 -> V_82 ) ;
if ( V_80 < 0 )
return;
V_74 = F_60 ( V_67 , L_18 , V_80 , V_15 ) ;
if ( ! V_74 )
return;
V_4 = F_38 ( V_74 , & V_19 -> V_19 ) ;
if ( ! V_4 )
F_47 ( V_19 , type , V_74 ) ;
else
F_32 ( & V_4 -> V_4 ) ;
F_6 ( V_74 ) ;
}
int F_61 ( struct V_6 * V_4 )
{
int V_24 = 0 ;
struct V_10 * V_11 ;
struct V_3 * V_83
= F_11 ( V_4 , struct V_3 , V_4 ) ;
F_23 ( L_10 , V_83 -> V_26 ) ;
if ( V_4 -> V_16 == NULL )
return 0 ;
V_11 = F_3 ( V_4 -> V_16 ) ;
if ( V_11 -> V_84 )
V_24 = V_11 -> V_84 ( V_83 ) ;
if ( V_24 )
F_62 ( L_20 , F_63 ( V_4 ) , V_24 ) ;
return 0 ;
}
int F_64 ( struct V_6 * V_4 )
{
int V_24 ;
struct V_10 * V_11 ;
struct V_3 * V_83
= F_11 ( V_4 , struct V_3 , V_4 ) ;
F_23 ( L_10 , V_83 -> V_26 ) ;
if ( V_4 -> V_16 == NULL )
return 0 ;
V_11 = F_3 ( V_4 -> V_16 ) ;
V_24 = F_9 ( V_83 ) ;
if ( V_24 ) {
F_62 ( L_21 ,
F_63 ( V_4 ) , V_24 ) ;
return V_24 ;
}
V_83 -> V_35 = V_66 ;
if ( V_11 -> V_85 ) {
V_24 = V_11 -> V_85 ( V_83 ) ;
if ( V_24 ) {
F_62 ( L_22 , F_63 ( V_4 ) , V_24 ) ;
return V_24 ;
}
}
V_24 = F_10 ( V_83 ) ;
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
int F_66 ( struct V_86 * V_87 )
{
int V_77 = 0 ;
if ( V_88 > 0 )
V_77 = V_87 -> V_89 ( V_87 , 0 , NULL ) ;
else
F_67 ( & V_90 , V_87 ) ;
return V_77 ;
}
void F_68 ( struct V_86 * V_87 )
{
F_69 ( & V_90 , V_87 ) ;
}
void F_70 ( struct V_91 * V_92 )
{
V_88 = 1 ;
F_71 ( & V_90 , 0 , NULL ) ;
}
static int T_3 F_72 ( void )
{
if ( ! F_73 () )
return - V_41 ;
if ( F_74 () || F_75 () )
return 0 ;
F_70 ( NULL ) ;
return 0 ;
}
static int T_3 F_76 ( void )
{
int V_24 = - V_68 ;
unsigned long V_93 = 0 ;
struct V_94 V_95 ;
V_93 = F_77 ( V_67 ) ;
if ( ! V_93 )
goto V_96;
V_97 = V_98 -> V_99 = F_78 ( ( void * ) V_93 ) ;
V_95 . V_100 = V_101 ;
V_95 . V_102 = V_101 ;
V_24 = F_79 ( V_103 ,
& V_95 ) ;
if ( V_24 == - V_104 )
goto V_96;
F_80 ( V_24 ) ;
V_105 = V_98 -> V_106 =
V_95 . V_107 ;
return 0 ;
V_96:
if ( V_93 != 0 )
F_81 ( V_93 ) ;
return V_24 ;
}
static int F_82 ( struct V_86 * V_87 ,
unsigned long V_108 , void * V_54 )
{
int V_24 = 0 ;
if ( F_75 () ) {
T_4 V_109 = 0 ;
V_24 = F_83 ( V_110 , & V_109 ) ;
if ( ! V_24 && V_109 )
V_105 = V_109 ;
else
F_62 ( L_25 ,
V_24 ) ;
} else
V_105 = V_98 -> V_106 ;
return V_24 ;
}
static int T_3 F_84 ( void )
{
int V_24 = 0 ;
T_4 V_109 = 0 ;
V_111 = V_112 ;
if ( ! F_73 () )
return - V_41 ;
F_85 () ;
if ( F_86 () )
V_111 = V_113 ;
if ( F_75 () )
V_111 = V_114 ;
if ( F_75 () && F_74 () )
V_111 = V_115 ;
if ( F_86 () && ! V_98 -> V_106 )
V_111 = V_115 ;
if ( F_86 () && V_98 -> V_106 )
V_88 = 1 ;
switch ( V_111 ) {
case V_115 :
V_24 = F_76 () ;
if ( V_24 )
goto V_116;
V_117 = F_87 ( V_97 ) ;
break;
case V_113 :
V_105 = V_98 -> V_106 ;
V_97 = V_98 -> V_99 ;
V_117 = F_87 ( V_97 ) ;
break;
case V_114 :
V_24 = F_83 ( V_110 , & V_109 ) ;
if ( V_24 )
goto V_116;
V_105 = ( int ) V_109 ;
V_24 = F_83 ( V_118 , & V_109 ) ;
if ( V_24 )
goto V_116;
V_97 = ( unsigned long ) V_109 ;
V_117 =
F_88 ( V_97 << V_119 ,
V_120 ) ;
break;
default:
F_62 ( L_26 ) ;
break;
}
V_24 = F_89 () ;
if ( V_24 ) {
F_62 ( L_27 , V_24 ) ;
goto V_116;
}
if ( ( V_111 != V_115 ) &&
( V_111 != V_112 ) )
F_90 ( & V_121 ) ;
#ifdef F_91
F_92 ( L_28 ) ;
#endif
V_116:
return V_24 ;
}
