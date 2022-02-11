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
static void F_19 ( enum V_26 V_46 )
{
switch ( V_46 ) {
case V_47 :
F_20 ( L_3 ) ;
break;
case V_48 :
F_21 () ;
break;
case V_49 :
* ( ( int * ) 0 ) = 0 ;
break;
case V_50 :
for (; ; )
;
break;
case V_51 :
( void ) F_18 ( 0 ) ;
break;
case V_52 : {
volatile T_5 V_53 [ 8 ] ;
volatile T_5 * V_54 = V_53 ;
V_54 [ 12 ] = 0x12345678 ;
break;
}
case V_55 : {
static T_6 V_53 [ 5 ] V_56 ( ( F_22 ( 4 ) ) ) = { 1 , 2 ,
3 , 4 , 5 } ;
T_5 * V_54 ;
T_5 V_57 = 0x12345678 ;
V_54 = ( T_5 * ) ( V_53 + 1 ) ;
if ( * V_54 == 0 )
V_57 = 0x87654321 ;
* V_54 = V_57 ;
break;
}
case V_58 : {
T_4 V_59 = 1020 ;
T_5 * V_53 = F_23 ( V_59 , V_60 ) ;
V_53 [ 1024 / sizeof( T_5 ) ] = 0x12345678 ;
F_24 ( V_53 ) ;
break;
}
case V_61 : {
T_4 V_59 = 1024 ;
T_5 * V_53 = F_23 ( V_59 , V_60 ) ;
F_24 ( V_53 ) ;
F_25 () ;
memset ( V_53 , 0x78 , V_59 ) ;
break;
}
case V_62 :
F_26 () ;
for (; ; )
F_27 () ;
break;
case V_63 :
F_28 () ;
for (; ; )
F_27 () ;
break;
case V_64 :
F_29 ( V_65 ) ;
F_25 () ;
break;
case V_31 :
default:
break;
}
}
static void F_2 ( void )
{
unsigned long V_36 ;
F_16 ( & V_40 , V_36 ) ;
V_28 -- ;
F_30 ( V_66 L_4 ,
F_14 ( V_44 ) , F_13 ( V_43 ) , V_28 ) ;
if ( V_28 == 0 ) {
F_19 ( V_43 ) ;
V_28 = V_37 ;
}
F_17 ( & V_40 , V_36 ) ;
}
static int F_31 ( enum V_32 V_46 )
{
int V_67 ;
V_44 = V_34 ;
if ( V_68 . V_69 != NULL )
F_32 ( & V_68 ) ;
switch ( V_46 ) {
case V_70 :
F_19 ( V_43 ) ;
return 0 ;
case V_71 :
V_68 . V_72 . V_73 = L_5 ;
V_68 . V_69 = ( V_74 * ) F_1 ;
break;
case V_75 :
V_68 . V_72 . V_73 = L_6 ;
V_68 . V_69 = ( V_74 * ) F_4 ;
break;
case V_76 :
V_68 . V_72 . V_73 = L_7 ;
V_68 . V_69 = ( V_74 * ) F_5 ;
break;
case V_77 :
V_68 . V_72 . V_73 = L_8 ;
V_68 . V_69 = ( V_74 * ) F_6 ;
break;
case V_78 :
V_68 . V_72 . V_73 = L_9 ;
V_68 . V_69 = ( V_74 * ) F_7 ;
break;
case V_79 :
V_68 . V_72 . V_73 = L_10 ;
V_68 . V_69 = ( V_74 * ) F_8 ;
break;
case V_80 :
V_68 . V_72 . V_73 = L_11 ;
V_68 . V_69 = ( V_74 * ) F_9 ;
break;
case V_81 :
#ifdef F_33
V_68 . V_72 . V_73 = L_12 ;
V_68 . V_69 = ( V_74 * ) F_10 ;
#else
F_30 ( V_66 L_13 ) ;
return - V_39 ;
#endif
break;
default:
F_30 ( V_66 L_14 ) ;
return - V_39 ;
}
V_44 = V_46 ;
if ( ( V_67 = F_34 ( & V_68 ) ) < 0 ) {
F_30 ( V_66 L_15 ) ;
V_44 = V_34 ;
}
return V_67 ;
}
static T_7 F_35 ( enum V_32 V_46 , struct V_22 * V_82 ,
const char T_8 * V_83 , T_4 V_28 , T_9 * V_84 )
{
char * V_45 ;
int V_85 ;
if ( V_28 >= V_86 )
return - V_39 ;
V_45 = ( char * ) F_36 ( V_60 ) ;
if ( ! V_45 )
return - V_87 ;
if ( F_37 ( V_45 , V_83 , V_28 ) ) {
F_38 ( ( unsigned long ) V_45 ) ;
return - V_88 ;
}
V_45 [ V_28 ] = '\0' ;
F_39 ( V_45 ) ;
V_43 = F_11 ( V_45 , V_28 ) ;
F_38 ( ( unsigned long ) V_45 ) ;
if ( V_43 == V_31 )
return - V_39 ;
V_85 = F_31 ( V_46 ) ;
if ( V_85 < 0 )
return V_85 ;
* V_84 += V_28 ;
return V_28 ;
}
static T_7 F_40 ( struct V_22 * V_82 , char T_8 * V_83 ,
T_4 V_28 , T_9 * V_84 )
{
char * V_45 ;
int V_29 , V_89 , V_90 ;
V_45 = ( char * ) F_36 ( V_60 ) ;
V_89 = snprintf ( V_45 , V_86 , L_16 ) ;
for ( V_29 = 0 ; V_29 < F_12 ( V_30 ) ; V_29 ++ )
V_89 += snprintf ( V_45 + V_89 , V_86 - V_89 , L_17 , V_30 [ V_29 ] ) ;
V_45 [ V_89 ] = '\0' ;
V_90 = F_41 ( V_83 , V_28 , V_84 ,
V_45 , V_89 ) ;
F_38 ( ( unsigned long ) V_45 ) ;
return V_90 ;
}
static int F_42 ( struct V_91 * V_91 , struct V_22 * V_22 )
{
return 0 ;
}
static T_7 F_43 ( struct V_22 * V_82 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_84 )
{
return F_35 ( V_71 , V_82 , V_45 , V_28 , V_84 ) ;
}
static T_7 F_44 ( struct V_22 * V_82 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_84 )
{
return F_35 ( V_75 , V_82 , V_45 , V_28 , V_84 ) ;
}
static T_7 F_45 ( struct V_22 * V_82 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_84 )
{
return F_35 ( V_76 , V_82 , V_45 , V_28 , V_84 ) ;
}
static T_7 F_46 ( struct V_22 * V_82 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_84 )
{
return F_35 ( V_77 , V_82 , V_45 , V_28 , V_84 ) ;
}
static T_7 F_47 ( struct V_22 * V_82 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_84 )
{
return F_35 ( V_78 , V_82 , V_45 , V_28 , V_84 ) ;
}
static T_7 F_48 ( struct V_22 * V_82 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_84 )
{
return F_35 ( V_79 , V_82 , V_45 , V_28 , V_84 ) ;
}
static T_7 F_49 ( struct V_22 * V_82 ,
const char T_8 * V_45 , T_4 V_28 , T_9 * V_84 )
{
return F_35 ( V_80 , V_82 , V_45 , V_28 , V_84 ) ;
}
static T_7 F_50 ( struct V_22 * V_82 , const char T_8 * V_45 ,
T_4 V_28 , T_9 * V_84 )
{
return F_35 ( V_81 , V_82 , V_45 , V_28 , V_84 ) ;
}
static T_7 F_51 ( struct V_22 * V_82 , const char T_8 * V_83 ,
T_4 V_28 , T_9 * V_84 )
{
enum V_26 type ;
char * V_45 ;
if ( V_28 >= V_86 )
return - V_39 ;
if ( V_28 < 1 )
return - V_39 ;
V_45 = ( char * ) F_36 ( V_60 ) ;
if ( ! V_45 )
return - V_87 ;
if ( F_37 ( V_45 , V_83 , V_28 ) ) {
F_38 ( ( unsigned long ) V_45 ) ;
return - V_88 ;
}
V_45 [ V_28 ] = '\0' ;
F_39 ( V_45 ) ;
type = F_11 ( V_45 , V_28 ) ;
F_38 ( ( unsigned long ) V_45 ) ;
if ( type == V_31 )
return - V_39 ;
F_30 ( V_66 L_18 ,
F_13 ( type ) ) ;
F_19 ( type ) ;
* V_84 += V_28 ;
return V_28 ;
}
static int T_10 F_52 ( void )
{
int V_67 = - V_39 ;
int V_92 = 1 ;
int V_29 ;
V_93 = F_53 ( L_19 , NULL ) ;
if ( ! V_93 ) {
F_30 ( V_94 L_20 ) ;
return - V_95 ;
}
#ifdef F_54
V_92 = F_12 ( V_96 ) ;
#endif
for ( V_29 = 0 ; V_29 < V_92 ; V_29 ++ ) {
const struct V_97 * V_98 = & V_96 [ V_29 ] ;
struct V_99 * V_100 ;
V_100 = F_55 ( V_98 -> V_33 , 0644 , V_93 ,
NULL , & V_98 -> V_101 ) ;
if ( V_100 == NULL ) {
F_30 ( V_94 L_21 ,
V_98 -> V_33 ) ;
goto V_102;
}
}
if ( F_15 () == - V_39 ) {
F_30 ( V_66 L_22 ) ;
goto V_102;
}
if ( V_44 != V_34 && V_43 != V_31 ) {
V_67 = F_31 ( V_44 ) ;
if ( V_67 < 0 ) {
F_30 ( V_66 L_23 ,
V_44 ) ;
goto V_102;
}
F_30 ( V_66 L_24 ,
V_42 , V_41 ) ;
} else {
F_30 ( V_66 L_25 ) ;
}
return 0 ;
V_102:
F_56 ( V_93 ) ;
return V_67 ;
}
static void T_11 F_57 ( void )
{
F_56 ( V_93 ) ;
F_32 ( & V_68 ) ;
F_30 ( V_66 L_26 ) ;
}
