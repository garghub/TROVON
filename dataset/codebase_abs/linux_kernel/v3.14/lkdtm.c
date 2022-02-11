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
static int F_10 ( T_3 * V_21 , struct V_22 * V_22 ,
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
if ( F_24 ( ( void V_51 * ) V_49 , F_19 , V_50 ) )
return;
F_22 () ;
}
static void F_25 ( enum V_26 V_52 )
{
switch ( V_52 ) {
case V_53 :
F_26 ( L_3 ) ;
break;
case V_54 :
F_27 () ;
break;
case V_55 :
F_28 ( 1 ) ;
break;
case V_56 :
* ( ( int * ) 0 ) = 0 ;
break;
case V_57 :
for (; ; )
;
break;
case V_58 :
( void ) F_18 ( V_38 ) ;
break;
case V_59 :
F_20 () ;
break;
case V_60 : {
static T_6 V_48 [ 5 ] V_61 ( ( F_29 ( 4 ) ) ) = { 1 , 2 ,
3 , 4 , 5 } ;
T_7 * V_62 ;
T_7 V_63 = 0x12345678 ;
V_62 = ( T_7 * ) ( V_48 + 1 ) ;
if ( * V_62 == 0 )
V_63 = 0x87654321 ;
* V_62 = V_63 ;
break;
}
case V_64 : {
T_4 V_65 = 1020 ;
T_7 * V_48 = F_30 ( V_65 , V_66 ) ;
V_48 [ 1024 / sizeof( T_7 ) ] = 0x12345678 ;
F_31 ( V_48 ) ;
break;
}
case V_67 : {
T_4 V_65 = 1024 ;
T_7 * V_48 = F_30 ( V_65 , V_66 ) ;
F_31 ( V_48 ) ;
F_32 () ;
memset ( V_48 , 0x78 , V_65 ) ;
break;
}
case V_68 :
F_33 () ;
for (; ; )
F_34 () ;
break;
case V_69 :
F_35 () ;
for (; ; )
F_34 () ;
break;
case V_70 :
F_36 ( & V_71 ) ;
F_37 ( & V_71 ) ;
break;
case V_72 :
F_38 ( V_73 ) ;
F_32 () ;
break;
case V_74 :
F_21 ( V_75 ) ;
break;
case V_76 : {
T_6 V_77 [ V_50 ] ;
F_21 ( V_77 ) ;
break;
}
case V_78 : {
T_7 * V_79 = F_30 ( V_50 , V_66 ) ;
F_21 ( V_79 ) ;
F_31 ( V_79 ) ;
break;
}
case V_80 : {
T_7 * V_81 = F_39 ( V_50 ) ;
F_21 ( V_81 ) ;
F_40 ( V_81 ) ;
break;
}
case V_82 : {
unsigned long V_83 ;
V_83 = F_41 ( NULL , 0 , V_84 ,
V_85 | V_86 | V_87 ,
V_88 | V_89 , 0 ) ;
if ( V_83 >= V_90 ) {
F_42 ( L_4 ) ;
return;
}
F_23 ( ( void * ) V_83 ) ;
F_43 ( V_83 , V_84 ) ;
break;
}
case V_91 : {
unsigned long V_83 , V_92 ;
unsigned long * V_93 ;
V_83 = F_41 ( NULL , 0 , V_84 ,
V_85 | V_86 | V_87 ,
V_88 | V_89 , 0 ) ;
if ( V_83 >= V_90 ) {
F_42 ( L_4 ) ;
return;
}
V_93 = ( unsigned long * ) V_83 ;
V_92 = * V_93 ;
V_92 += 0xc0dec0de ;
* V_93 = V_92 ;
F_43 ( V_83 , V_84 ) ;
break;
}
case V_94 : {
unsigned long * V_93 ;
V_93 = ( unsigned long * ) & V_95 ;
* V_93 ^= 0xabcd1234 ;
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
bool V_96 = false ;
F_16 ( & V_40 , V_36 ) ;
V_28 -- ;
F_44 ( V_97 L_5 ,
F_14 ( V_44 ) , F_13 ( V_43 ) , V_28 ) ;
if ( V_28 == 0 ) {
V_96 = true ;
V_28 = V_37 ;
}
F_17 ( & V_40 , V_36 ) ;
if ( V_96 )
F_25 ( V_43 ) ;
}
static int F_45 ( enum V_32 V_52 )
{
int V_98 ;
V_44 = V_34 ;
if ( V_99 . V_100 != NULL )
F_46 ( & V_99 ) ;
switch ( V_52 ) {
case V_101 :
F_25 ( V_43 ) ;
return 0 ;
case V_102 :
V_99 . V_103 . V_104 = L_6 ;
V_99 . V_100 = ( V_105 * ) F_1 ;
break;
case V_106 :
V_99 . V_103 . V_104 = L_7 ;
V_99 . V_100 = ( V_105 * ) F_4 ;
break;
case V_107 :
V_99 . V_103 . V_104 = L_8 ;
V_99 . V_100 = ( V_105 * ) F_5 ;
break;
case V_108 :
V_99 . V_103 . V_104 = L_9 ;
V_99 . V_100 = ( V_105 * ) F_6 ;
break;
case V_109 :
V_99 . V_103 . V_104 = L_10 ;
V_99 . V_100 = ( V_105 * ) F_7 ;
break;
case V_110 :
V_99 . V_103 . V_104 = L_11 ;
V_99 . V_100 = ( V_105 * ) F_8 ;
break;
case V_111 :
V_99 . V_103 . V_104 = L_12 ;
V_99 . V_100 = ( V_105 * ) F_9 ;
break;
case V_112 :
#ifdef F_47
V_99 . V_103 . V_104 = L_13 ;
V_99 . V_100 = ( V_105 * ) F_10 ;
#else
F_44 ( V_97 L_14 ) ;
return - V_39 ;
#endif
break;
default:
F_44 ( V_97 L_15 ) ;
return - V_39 ;
}
V_44 = V_52 ;
if ( ( V_98 = F_48 ( & V_99 ) ) < 0 ) {
F_44 ( V_97 L_16 ) ;
V_44 = V_34 ;
}
return V_98 ;
}
static T_8 F_49 ( enum V_32 V_52 , struct V_22 * V_113 ,
const char V_51 * V_114 , T_4 V_28 , T_9 * V_115 )
{
char * V_46 ;
int V_116 ;
if ( V_28 >= V_84 )
return - V_39 ;
V_46 = ( char * ) F_50 ( V_66 ) ;
if ( ! V_46 )
return - V_117 ;
if ( F_51 ( V_46 , V_114 , V_28 ) ) {
F_52 ( ( unsigned long ) V_46 ) ;
return - V_118 ;
}
V_46 [ V_28 ] = '\0' ;
F_53 ( V_46 ) ;
V_43 = F_11 ( V_46 , V_28 ) ;
F_52 ( ( unsigned long ) V_46 ) ;
if ( V_43 == V_31 )
return - V_39 ;
V_116 = F_45 ( V_52 ) ;
if ( V_116 < 0 )
return V_116 ;
* V_115 += V_28 ;
return V_28 ;
}
static T_8 F_54 ( struct V_22 * V_113 , char V_51 * V_114 ,
T_4 V_28 , T_9 * V_115 )
{
char * V_46 ;
int V_29 , V_119 , V_120 ;
V_46 = ( char * ) F_50 ( V_66 ) ;
if ( V_46 == NULL )
return - V_117 ;
V_119 = snprintf ( V_46 , V_84 , L_17 ) ;
for ( V_29 = 0 ; V_29 < F_12 ( V_30 ) ; V_29 ++ )
V_119 += snprintf ( V_46 + V_119 , V_84 - V_119 , L_18 , V_30 [ V_29 ] ) ;
V_46 [ V_119 ] = '\0' ;
V_120 = F_55 ( V_114 , V_28 , V_115 ,
V_46 , V_119 ) ;
F_52 ( ( unsigned long ) V_46 ) ;
return V_120 ;
}
static int F_56 ( struct V_121 * V_121 , struct V_22 * V_22 )
{
return 0 ;
}
static T_8 F_57 ( struct V_22 * V_113 , const char V_51 * V_46 ,
T_4 V_28 , T_9 * V_115 )
{
return F_49 ( V_102 , V_113 , V_46 , V_28 , V_115 ) ;
}
static T_8 F_58 ( struct V_22 * V_113 , const char V_51 * V_46 ,
T_4 V_28 , T_9 * V_115 )
{
return F_49 ( V_106 , V_113 , V_46 , V_28 , V_115 ) ;
}
static T_8 F_59 ( struct V_22 * V_113 , const char V_51 * V_46 ,
T_4 V_28 , T_9 * V_115 )
{
return F_49 ( V_107 , V_113 , V_46 , V_28 , V_115 ) ;
}
static T_8 F_60 ( struct V_22 * V_113 , const char V_51 * V_46 ,
T_4 V_28 , T_9 * V_115 )
{
return F_49 ( V_108 , V_113 , V_46 , V_28 , V_115 ) ;
}
static T_8 F_61 ( struct V_22 * V_113 , const char V_51 * V_46 ,
T_4 V_28 , T_9 * V_115 )
{
return F_49 ( V_109 , V_113 , V_46 , V_28 , V_115 ) ;
}
static T_8 F_62 ( struct V_22 * V_113 , const char V_51 * V_46 ,
T_4 V_28 , T_9 * V_115 )
{
return F_49 ( V_110 , V_113 , V_46 , V_28 , V_115 ) ;
}
static T_8 F_63 ( struct V_22 * V_113 ,
const char V_51 * V_46 , T_4 V_28 , T_9 * V_115 )
{
return F_49 ( V_111 , V_113 , V_46 , V_28 , V_115 ) ;
}
static T_8 F_64 ( struct V_22 * V_113 , const char V_51 * V_46 ,
T_4 V_28 , T_9 * V_115 )
{
return F_49 ( V_112 , V_113 , V_46 , V_28 , V_115 ) ;
}
static T_8 F_65 ( struct V_22 * V_113 , const char V_51 * V_114 ,
T_4 V_28 , T_9 * V_115 )
{
enum V_26 type ;
char * V_46 ;
if ( V_28 >= V_84 )
return - V_39 ;
if ( V_28 < 1 )
return - V_39 ;
V_46 = ( char * ) F_50 ( V_66 ) ;
if ( ! V_46 )
return - V_117 ;
if ( F_51 ( V_46 , V_114 , V_28 ) ) {
F_52 ( ( unsigned long ) V_46 ) ;
return - V_118 ;
}
V_46 [ V_28 ] = '\0' ;
F_53 ( V_46 ) ;
type = F_11 ( V_46 , V_28 ) ;
F_52 ( ( unsigned long ) V_46 ) ;
if ( type == V_31 )
return - V_39 ;
F_44 ( V_97 L_19 ,
F_13 ( type ) ) ;
F_25 ( type ) ;
* V_115 += V_28 ;
return V_28 ;
}
static int T_10 F_66 ( void )
{
int V_98 = - V_39 ;
int V_122 = 1 ;
int V_29 ;
V_123 = F_67 ( L_20 , NULL ) ;
if ( ! V_123 ) {
F_44 ( V_124 L_21 ) ;
return - V_125 ;
}
#ifdef F_68
V_122 = F_12 ( V_126 ) ;
#endif
for ( V_29 = 0 ; V_29 < V_122 ; V_29 ++ ) {
const struct V_127 * V_128 = & V_126 [ V_29 ] ;
struct V_129 * V_130 ;
V_130 = F_69 ( V_128 -> V_33 , 0644 , V_123 ,
NULL , & V_128 -> V_131 ) ;
if ( V_130 == NULL ) {
F_44 ( V_124 L_22 ,
V_128 -> V_33 ) ;
goto V_132;
}
}
if ( F_15 () == - V_39 ) {
F_44 ( V_97 L_23 ) ;
goto V_132;
}
if ( V_44 != V_34 && V_43 != V_31 ) {
V_98 = F_45 ( V_44 ) ;
if ( V_98 < 0 ) {
F_44 ( V_97 L_24 ,
V_44 ) ;
goto V_132;
}
F_44 ( V_97 L_25 ,
V_42 , V_41 ) ;
} else {
F_44 ( V_97 L_26 ) ;
}
return 0 ;
V_132:
F_70 ( V_123 ) ;
return V_98 ;
}
static void T_11 F_71 ( void )
{
F_70 ( V_123 ) ;
F_46 ( & V_99 ) ;
F_44 ( V_97 L_27 ) ;
}
