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
static int F_18 ( int V_45 )
{
char V_46 [ V_47 ] ;
memset ( V_46 , ( V_45 & 0xff ) | 0x1 , V_47 ) ;
if ( ! V_45 )
return 0 ;
else
return F_18 ( V_45 - 1 ) ;
}
static void F_19 ( void )
{
return;
}
static T_5 void F_20 ( void )
{
char V_48 [ 8 ] ;
memset ( ( void * ) V_48 , 0 , 64 ) ;
}
static void F_21 ( void * V_49 )
{
void (* F_22)( void ) = V_49 ;
memcpy ( V_49 , F_19 , V_50 ) ;
F_22 () ;
}
static void F_23 ( void * V_49 )
{
void (* F_22)( void ) = V_49 ;
if ( F_24 ( V_49 , F_19 , V_50 ) )
return;
F_22 () ;
}
static void F_25 ( enum V_26 V_51 )
{
switch ( V_51 ) {
case V_52 :
F_26 ( L_3 ) ;
break;
case V_53 :
F_27 () ;
break;
case V_54 :
F_28 ( 1 ) ;
break;
case V_55 :
* ( ( int * ) 0 ) = 0 ;
break;
case V_56 :
for (; ; )
;
break;
case V_57 :
( void ) F_18 ( V_38 ) ;
break;
case V_58 :
F_20 () ;
break;
case V_59 : {
static T_6 V_48 [ 5 ] V_60 ( ( F_29 ( 4 ) ) ) = { 1 , 2 ,
3 , 4 , 5 } ;
T_7 * V_61 ;
T_7 V_62 = 0x12345678 ;
V_61 = ( T_7 * ) ( V_48 + 1 ) ;
if ( * V_61 == 0 )
V_62 = 0x87654321 ;
* V_61 = V_62 ;
break;
}
case V_63 : {
T_4 V_64 = 1020 ;
T_7 * V_48 = F_30 ( V_64 , V_65 ) ;
V_48 [ 1024 / sizeof( T_7 ) ] = 0x12345678 ;
F_31 ( V_48 ) ;
break;
}
case V_66 : {
T_4 V_64 = 1024 ;
T_7 * V_48 = F_30 ( V_64 , V_65 ) ;
F_31 ( V_48 ) ;
F_32 () ;
memset ( V_48 , 0x78 , V_64 ) ;
break;
}
case V_67 :
F_33 () ;
for (; ; )
F_34 () ;
break;
case V_68 :
F_35 () ;
for (; ; )
F_34 () ;
break;
case V_69 :
F_36 ( & V_70 ) ;
break;
case V_71 :
F_37 ( V_72 ) ;
F_32 () ;
break;
case V_73 :
F_21 ( V_74 ) ;
break;
case V_75 : {
T_6 V_76 [ V_50 ] ;
F_21 ( V_76 ) ;
break;
}
case V_77 : {
T_7 * V_78 = F_30 ( V_50 , V_65 ) ;
F_21 ( V_78 ) ;
F_31 ( V_78 ) ;
break;
}
case V_79 : {
T_7 * V_80 = F_38 ( V_50 ) ;
F_21 ( V_80 ) ;
F_39 ( V_80 ) ;
break;
}
case V_81 : {
unsigned long V_82 ;
V_82 = F_40 ( NULL , 0 , V_83 ,
V_84 | V_85 | V_86 ,
V_87 | V_88 , 0 ) ;
if ( V_82 >= V_89 ) {
F_41 ( L_4 ) ;
return;
}
F_23 ( ( void * ) V_82 ) ;
F_42 ( V_82 , V_83 ) ;
break;
}
case V_90 : {
unsigned long V_82 , V_91 ;
unsigned long * V_92 ;
V_82 = F_40 ( NULL , 0 , V_83 ,
V_84 | V_85 | V_86 ,
V_87 | V_88 , 0 ) ;
if ( V_82 >= V_89 ) {
F_41 ( L_4 ) ;
return;
}
V_92 = ( unsigned long * ) V_82 ;
V_91 = * V_92 ;
V_91 += 0xc0dec0de ;
* V_92 = V_91 ;
F_42 ( V_82 , V_83 ) ;
break;
}
case V_93 : {
unsigned long * V_92 ;
V_92 = ( unsigned long * ) & V_94 ;
* V_92 ^= 0xabcd1234 ;
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
bool V_95 = false ;
F_16 ( & V_40 , V_36 ) ;
V_28 -- ;
F_43 ( V_96 L_5 ,
F_14 ( V_44 ) , F_13 ( V_43 ) , V_28 ) ;
if ( V_28 == 0 ) {
V_95 = true ;
V_28 = V_37 ;
}
F_17 ( & V_40 , V_36 ) ;
if ( V_95 )
F_25 ( V_43 ) ;
}
static int F_44 ( enum V_32 V_51 )
{
int V_97 ;
V_44 = V_34 ;
if ( V_98 . V_99 != NULL )
F_45 ( & V_98 ) ;
switch ( V_51 ) {
case V_100 :
F_25 ( V_43 ) ;
return 0 ;
case V_101 :
V_98 . V_102 . V_103 = L_6 ;
V_98 . V_99 = ( V_104 * ) F_1 ;
break;
case V_105 :
V_98 . V_102 . V_103 = L_7 ;
V_98 . V_99 = ( V_104 * ) F_4 ;
break;
case V_106 :
V_98 . V_102 . V_103 = L_8 ;
V_98 . V_99 = ( V_104 * ) F_5 ;
break;
case V_107 :
V_98 . V_102 . V_103 = L_9 ;
V_98 . V_99 = ( V_104 * ) F_6 ;
break;
case V_108 :
V_98 . V_102 . V_103 = L_10 ;
V_98 . V_99 = ( V_104 * ) F_7 ;
break;
case V_109 :
V_98 . V_102 . V_103 = L_11 ;
V_98 . V_99 = ( V_104 * ) F_8 ;
break;
case V_110 :
V_98 . V_102 . V_103 = L_12 ;
V_98 . V_99 = ( V_104 * ) F_9 ;
break;
case V_111 :
#ifdef F_46
V_98 . V_102 . V_103 = L_13 ;
V_98 . V_99 = ( V_104 * ) F_10 ;
#else
F_43 ( V_96 L_14 ) ;
return - V_39 ;
#endif
break;
default:
F_43 ( V_96 L_15 ) ;
return - V_39 ;
}
V_44 = V_51 ;
if ( ( V_97 = F_47 ( & V_98 ) ) < 0 ) {
F_43 ( V_96 L_16 ) ;
V_44 = V_34 ;
}
return V_97 ;
}
static T_8 F_48 ( enum V_32 V_51 , struct V_22 * V_112 ,
const char T_9 * V_113 , T_4 V_28 , T_10 * V_114 )
{
char * V_46 ;
int V_115 ;
if ( V_28 >= V_83 )
return - V_39 ;
V_46 = ( char * ) F_49 ( V_65 ) ;
if ( ! V_46 )
return - V_116 ;
if ( F_50 ( V_46 , V_113 , V_28 ) ) {
F_51 ( ( unsigned long ) V_46 ) ;
return - V_117 ;
}
V_46 [ V_28 ] = '\0' ;
F_52 ( V_46 ) ;
V_43 = F_11 ( V_46 , V_28 ) ;
F_51 ( ( unsigned long ) V_46 ) ;
if ( V_43 == V_31 )
return - V_39 ;
V_115 = F_44 ( V_51 ) ;
if ( V_115 < 0 )
return V_115 ;
* V_114 += V_28 ;
return V_28 ;
}
static T_8 F_53 ( struct V_22 * V_112 , char T_9 * V_113 ,
T_4 V_28 , T_10 * V_114 )
{
char * V_46 ;
int V_29 , V_118 , V_119 ;
V_46 = ( char * ) F_49 ( V_65 ) ;
if ( V_46 == NULL )
return - V_116 ;
V_118 = snprintf ( V_46 , V_83 , L_17 ) ;
for ( V_29 = 0 ; V_29 < F_12 ( V_30 ) ; V_29 ++ )
V_118 += snprintf ( V_46 + V_118 , V_83 - V_118 , L_18 , V_30 [ V_29 ] ) ;
V_46 [ V_118 ] = '\0' ;
V_119 = F_54 ( V_113 , V_28 , V_114 ,
V_46 , V_118 ) ;
F_51 ( ( unsigned long ) V_46 ) ;
return V_119 ;
}
static int F_55 ( struct V_120 * V_120 , struct V_22 * V_22 )
{
return 0 ;
}
static T_8 F_56 ( struct V_22 * V_112 , const char T_9 * V_46 ,
T_4 V_28 , T_10 * V_114 )
{
return F_48 ( V_101 , V_112 , V_46 , V_28 , V_114 ) ;
}
static T_8 F_57 ( struct V_22 * V_112 , const char T_9 * V_46 ,
T_4 V_28 , T_10 * V_114 )
{
return F_48 ( V_105 , V_112 , V_46 , V_28 , V_114 ) ;
}
static T_8 F_58 ( struct V_22 * V_112 , const char T_9 * V_46 ,
T_4 V_28 , T_10 * V_114 )
{
return F_48 ( V_106 , V_112 , V_46 , V_28 , V_114 ) ;
}
static T_8 F_59 ( struct V_22 * V_112 , const char T_9 * V_46 ,
T_4 V_28 , T_10 * V_114 )
{
return F_48 ( V_107 , V_112 , V_46 , V_28 , V_114 ) ;
}
static T_8 F_60 ( struct V_22 * V_112 , const char T_9 * V_46 ,
T_4 V_28 , T_10 * V_114 )
{
return F_48 ( V_108 , V_112 , V_46 , V_28 , V_114 ) ;
}
static T_8 F_61 ( struct V_22 * V_112 , const char T_9 * V_46 ,
T_4 V_28 , T_10 * V_114 )
{
return F_48 ( V_109 , V_112 , V_46 , V_28 , V_114 ) ;
}
static T_8 F_62 ( struct V_22 * V_112 ,
const char T_9 * V_46 , T_4 V_28 , T_10 * V_114 )
{
return F_48 ( V_110 , V_112 , V_46 , V_28 , V_114 ) ;
}
static T_8 F_63 ( struct V_22 * V_112 , const char T_9 * V_46 ,
T_4 V_28 , T_10 * V_114 )
{
return F_48 ( V_111 , V_112 , V_46 , V_28 , V_114 ) ;
}
static T_8 F_64 ( struct V_22 * V_112 , const char T_9 * V_113 ,
T_4 V_28 , T_10 * V_114 )
{
enum V_26 type ;
char * V_46 ;
if ( V_28 >= V_83 )
return - V_39 ;
if ( V_28 < 1 )
return - V_39 ;
V_46 = ( char * ) F_49 ( V_65 ) ;
if ( ! V_46 )
return - V_116 ;
if ( F_50 ( V_46 , V_113 , V_28 ) ) {
F_51 ( ( unsigned long ) V_46 ) ;
return - V_117 ;
}
V_46 [ V_28 ] = '\0' ;
F_52 ( V_46 ) ;
type = F_11 ( V_46 , V_28 ) ;
F_51 ( ( unsigned long ) V_46 ) ;
if ( type == V_31 )
return - V_39 ;
F_43 ( V_96 L_19 ,
F_13 ( type ) ) ;
F_25 ( type ) ;
* V_114 += V_28 ;
return V_28 ;
}
static int T_11 F_65 ( void )
{
int V_97 = - V_39 ;
int V_121 = 1 ;
int V_29 ;
V_122 = F_66 ( L_20 , NULL ) ;
if ( ! V_122 ) {
F_43 ( V_123 L_21 ) ;
return - V_124 ;
}
#ifdef F_67
V_121 = F_12 ( V_125 ) ;
#endif
for ( V_29 = 0 ; V_29 < V_121 ; V_29 ++ ) {
const struct V_126 * V_127 = & V_125 [ V_29 ] ;
struct V_128 * V_129 ;
V_129 = F_68 ( V_127 -> V_33 , 0644 , V_122 ,
NULL , & V_127 -> V_130 ) ;
if ( V_129 == NULL ) {
F_43 ( V_123 L_22 ,
V_127 -> V_33 ) ;
goto V_131;
}
}
if ( F_15 () == - V_39 ) {
F_43 ( V_96 L_23 ) ;
goto V_131;
}
if ( V_44 != V_34 && V_43 != V_31 ) {
V_97 = F_44 ( V_44 ) ;
if ( V_97 < 0 ) {
F_43 ( V_96 L_24 ,
V_44 ) ;
goto V_131;
}
F_43 ( V_96 L_25 ,
V_42 , V_41 ) ;
} else {
F_43 ( V_96 L_26 ) ;
}
return 0 ;
V_131:
F_69 ( V_122 ) ;
return V_97 ;
}
static void T_12 F_70 ( void )
{
F_69 ( V_122 ) ;
F_45 ( & V_98 ) ;
F_43 ( V_96 L_27 ) ;
}
