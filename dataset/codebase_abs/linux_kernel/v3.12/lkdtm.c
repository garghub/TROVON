static unsigned int F_1 ( unsigned int V_1 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static T_1 F_4 ( unsigned int V_1 ,
struct V_2 * V_3 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static void F_5 ( struct V_4 * V_5 )
{
F_2 () ;
F_3 () ;
}
static void F_6 ( int V_6 , int V_7 , struct V_8 * V_9 [] )
{
F_2 () ;
F_3 () ;
}
static unsigned long F_7 ( unsigned long V_10 ,
struct V_11 * V_11 ,
struct V_12 * V_13 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 , T_2 V_16 ,
const enum V_17 V_18 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
int F_10 ( T_3 * V_21 , struct V_22 * V_22 ,
struct V_23 * V_24 , unsigned int V_20 ,
unsigned long V_25 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static enum V_26 F_11 ( const char * V_27 , T_4 V_28 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_12 ( V_30 ) ; V_29 ++ ) {
if ( ! strcmp ( V_27 , V_30 [ V_29 ] ) )
return V_29 + 1 ;
}
return V_31 ;
}
static const char * F_13 ( enum V_26 type )
{
if ( type == V_31 || type < 0 || type > F_12 ( V_30 ) )
return L_1 ;
return V_30 [ type - 1 ] ;
}
static const char * F_14 ( enum V_32 V_33 )
{
if ( V_33 == V_34 || V_33 < 0 || V_33 > F_12 ( V_35 ) )
return L_2 ;
return V_35 [ V_33 - 1 ] ;
}
static int F_15 ( void )
{
int V_29 ;
unsigned long V_36 ;
if ( V_37 < 1 || V_38 < 1 )
return - V_39 ;
F_16 ( & V_40 , V_36 ) ;
V_28 = V_37 ;
F_17 ( & V_40 , V_36 ) ;
if ( ! V_41 && ! V_42 )
return 0 ;
if ( ! V_41 || ! V_42 )
return - V_39 ;
V_43 = F_11 ( V_41 , strlen ( V_41 ) ) ;
if ( V_43 == V_31 )
return - V_39 ;
for ( V_29 = 0 ; V_29 < F_12 ( V_35 ) ; V_29 ++ ) {
if ( ! strcmp ( V_42 , V_35 [ V_29 ] ) ) {
V_44 = V_29 + 1 ;
return 0 ;
}
}
return - V_39 ;
}
static int F_18 ( int V_5 )
{
char V_45 [ 1024 ] ;
memset ( V_45 , 0xFF , 1024 ) ;
V_38 -- ;
if ( ! V_38 )
return 0 ;
else
return F_18 ( V_5 ) ;
}
static void F_19 ( void )
{
return;
}
static void F_20 ( void * V_46 )
{
void (* F_21)( void ) = V_46 ;
memcpy ( V_46 , F_19 , V_47 ) ;
F_21 () ;
}
static void F_22 ( enum V_26 V_48 )
{
switch ( V_48 ) {
case V_49 :
F_23 ( L_3 ) ;
break;
case V_50 :
F_24 () ;
break;
case V_51 :
F_25 ( 1 ) ;
break;
case V_52 :
* ( ( int * ) 0 ) = 0 ;
break;
case V_53 :
for (; ; )
;
break;
case V_54 :
( void ) F_18 ( 0 ) ;
break;
case V_55 : {
volatile char V_56 [ 8 ] ;
memset ( ( void * ) V_56 , 0 , 64 ) ;
break;
}
case V_57 : {
static T_5 V_56 [ 5 ] V_58 ( ( F_26 ( 4 ) ) ) = { 1 , 2 ,
3 , 4 , 5 } ;
T_6 * V_59 ;
T_6 V_60 = 0x12345678 ;
V_59 = ( T_6 * ) ( V_56 + 1 ) ;
if ( * V_59 == 0 )
V_60 = 0x87654321 ;
* V_59 = V_60 ;
break;
}
case V_61 : {
T_4 V_62 = 1020 ;
T_6 * V_56 = F_27 ( V_62 , V_63 ) ;
V_56 [ 1024 / sizeof( T_6 ) ] = 0x12345678 ;
F_28 ( V_56 ) ;
break;
}
case V_64 : {
T_4 V_62 = 1024 ;
T_6 * V_56 = F_27 ( V_62 , V_63 ) ;
F_28 ( V_56 ) ;
F_29 () ;
memset ( V_56 , 0x78 , V_62 ) ;
break;
}
case V_65 :
F_30 () ;
for (; ; )
F_31 () ;
break;
case V_66 :
F_32 () ;
for (; ; )
F_31 () ;
break;
case V_67 :
F_33 ( & V_68 ) ;
break;
case V_69 :
F_34 ( V_70 ) ;
F_29 () ;
break;
case V_71 :
F_20 ( V_72 ) ;
break;
case V_73 : {
T_5 V_74 [ V_47 ] ;
F_20 ( V_74 ) ;
break;
}
case V_75 : {
T_6 * V_76 = F_27 ( V_47 , V_63 ) ;
F_20 ( V_76 ) ;
F_28 ( V_76 ) ;
break;
}
case V_77 : {
T_6 * V_78 = F_35 ( V_47 ) ;
F_20 ( V_78 ) ;
F_36 ( V_78 ) ;
break;
}
case V_31 :
default:
break;
}
}
static void F_2 ( void )
{
unsigned long V_36 ;
bool V_79 = false ;
F_16 ( & V_40 , V_36 ) ;
V_28 -- ;
F_37 ( V_80 L_4 ,
F_14 ( V_44 ) , F_13 ( V_43 ) , V_28 ) ;
if ( V_28 == 0 ) {
V_79 = true ;
V_28 = V_37 ;
}
F_17 ( & V_40 , V_36 ) ;
if ( V_79 )
F_22 ( V_43 ) ;
}
static int F_38 ( enum V_32 V_48 )
{
int V_81 ;
V_44 = V_34 ;
if ( V_82 . V_83 != NULL )
F_39 ( & V_82 ) ;
switch ( V_48 ) {
case V_84 :
F_22 ( V_43 ) ;
return 0 ;
case V_85 :
V_82 . V_86 . V_87 = L_5 ;
V_82 . V_83 = ( V_88 * ) F_1 ;
break;
case V_89 :
V_82 . V_86 . V_87 = L_6 ;
V_82 . V_83 = ( V_88 * ) F_4 ;
break;
case V_90 :
V_82 . V_86 . V_87 = L_7 ;
V_82 . V_83 = ( V_88 * ) F_5 ;
break;
case V_91 :
V_82 . V_86 . V_87 = L_8 ;
V_82 . V_83 = ( V_88 * ) F_6 ;
break;
case V_92 :
V_82 . V_86 . V_87 = L_9 ;
V_82 . V_83 = ( V_88 * ) F_7 ;
break;
case V_93 :
V_82 . V_86 . V_87 = L_10 ;
V_82 . V_83 = ( V_88 * ) F_8 ;
break;
case V_94 :
V_82 . V_86 . V_87 = L_11 ;
V_82 . V_83 = ( V_88 * ) F_9 ;
break;
case V_95 :
#ifdef F_40
V_82 . V_86 . V_87 = L_12 ;
V_82 . V_83 = ( V_88 * ) F_10 ;
#else
F_37 ( V_80 L_13 ) ;
return - V_39 ;
#endif
break;
default:
F_37 ( V_80 L_14 ) ;
return - V_39 ;
}
V_44 = V_48 ;
if ( ( V_81 = F_41 ( & V_82 ) ) < 0 ) {
F_37 ( V_80 L_15 ) ;
V_44 = V_34 ;
}
return V_81 ;
}
static T_7 F_42 ( enum V_32 V_48 , struct V_22 * V_96 ,
const char T_8 * V_97 , T_4 V_28 , T_9 * V_98 )
{
char * V_45 ;
int V_99 ;
if ( V_28 >= V_100 )
return - V_39 ;
V_45 = ( char * ) F_43 ( V_63 ) ;
if ( ! V_45 )
return - V_101 ;
if ( F_44 ( V_45 , V_97 , V_28 ) ) {
F_45 ( ( unsigned long ) V_45 ) ;
return - V_102 ;
}
V_45 [ V_28 ] = '\0' ;
F_46 ( V_45 ) ;
V_43 = F_11 ( V_45 , V_28 ) ;
F_45 ( ( unsigned long ) V_45 ) ;
if ( V_43 == V_31 )
return - V_39 ;
V_99 = F_38 ( V_48 ) ;
if ( V_99 < 0 )
return V_99 ;
* V_98 += V_28 ;
return V_28 ;
}
static T_7 F_47 ( struct V_22 * V_96 , char T_8 * V_97 ,
T_4 V_28 , T_9 * V_98 )
{
char * V_45 ;
int V_29 , V_103 , V_104 ;
V_45 = ( char * ) F_43 ( V_63 ) ;
if ( V_45 == NULL )
return - V_101 ;
V_103 = snprintf ( V_45 , V_100 , L_16 ) ;
for ( V_29 = 0 ; V_29 < F_12 ( V_30 ) ; V_29 ++ )
V_103 += snprintf ( V_45 + V_103 , V_100 - V_103 , L_17 , V_30 [ V_29 ] ) ;
V_45 [ V_103 ] = '\0' ;
V_104 = F_48 ( V_97 , V_28 , V_98 ,
V_45 , V_103 ) ;
F_45 ( ( unsigned long ) V_45 ) ;
return V_104 ;
}
static int F_49 ( struct V_105 * V_105 , struct V_22 * V_22 )
{
return 0 ;
}
static T_7 F_50 ( struct V_22 * V_96 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_98 )
{
return F_42 ( V_85 , V_96 , V_45 , V_28 , V_98 ) ;
}
static T_7 F_51 ( struct V_22 * V_96 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_98 )
{
return F_42 ( V_89 , V_96 , V_45 , V_28 , V_98 ) ;
}
static T_7 F_52 ( struct V_22 * V_96 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_98 )
{
return F_42 ( V_90 , V_96 , V_45 , V_28 , V_98 ) ;
}
static T_7 F_53 ( struct V_22 * V_96 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_98 )
{
return F_42 ( V_91 , V_96 , V_45 , V_28 , V_98 ) ;
}
static T_7 F_54 ( struct V_22 * V_96 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_98 )
{
return F_42 ( V_92 , V_96 , V_45 , V_28 , V_98 ) ;
}
static T_7 F_55 ( struct V_22 * V_96 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_98 )
{
return F_42 ( V_93 , V_96 , V_45 , V_28 , V_98 ) ;
}
static T_7 F_56 ( struct V_22 * V_96 ,
const char T_8 * V_45 , T_4 V_28 , T_9 * V_98 )
{
return F_42 ( V_94 , V_96 , V_45 , V_28 , V_98 ) ;
}
static T_7 F_57 ( struct V_22 * V_96 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_98 )
{
return F_42 ( V_95 , V_96 , V_45 , V_28 , V_98 ) ;
}
static T_7 F_58 ( struct V_22 * V_96 , const char T_8 * V_97 ,
T_4 V_28 , T_9 * V_98 )
{
enum V_26 type ;
char * V_45 ;
if ( V_28 >= V_100 )
return - V_39 ;
if ( V_28 < 1 )
return - V_39 ;
V_45 = ( char * ) F_43 ( V_63 ) ;
if ( ! V_45 )
return - V_101 ;
if ( F_44 ( V_45 , V_97 , V_28 ) ) {
F_45 ( ( unsigned long ) V_45 ) ;
return - V_102 ;
}
V_45 [ V_28 ] = '\0' ;
F_46 ( V_45 ) ;
type = F_11 ( V_45 , V_28 ) ;
F_45 ( ( unsigned long ) V_45 ) ;
if ( type == V_31 )
return - V_39 ;
F_37 ( V_80 L_18 ,
F_13 ( type ) ) ;
F_22 ( type ) ;
* V_98 += V_28 ;
return V_28 ;
}
static int T_10 F_59 ( void )
{
int V_81 = - V_39 ;
int V_106 = 1 ;
int V_29 ;
V_107 = F_60 ( L_19 , NULL ) ;
if ( ! V_107 ) {
F_37 ( V_108 L_20 ) ;
return - V_109 ;
}
#ifdef F_61
V_106 = F_12 ( V_110 ) ;
#endif
for ( V_29 = 0 ; V_29 < V_106 ; V_29 ++ ) {
const struct V_111 * V_112 = & V_110 [ V_29 ] ;
struct V_113 * V_114 ;
V_114 = F_62 ( V_112 -> V_33 , 0644 , V_107 ,
NULL , & V_112 -> V_115 ) ;
if ( V_114 == NULL ) {
F_37 ( V_108 L_21 ,
V_112 -> V_33 ) ;
goto V_116;
}
}
if ( F_15 () == - V_39 ) {
F_37 ( V_80 L_22 ) ;
goto V_116;
}
if ( V_44 != V_34 && V_43 != V_31 ) {
V_81 = F_38 ( V_44 ) ;
if ( V_81 < 0 ) {
F_37 ( V_80 L_23 ,
V_44 ) ;
goto V_116;
}
F_37 ( V_80 L_24 ,
V_42 , V_41 ) ;
} else {
F_37 ( V_80 L_25 ) ;
}
return 0 ;
V_116:
F_63 ( V_107 ) ;
return V_81 ;
}
static void T_11 F_64 ( void )
{
F_63 ( V_107 ) ;
F_39 ( & V_82 ) ;
F_37 ( V_80 L_26 ) ;
}
