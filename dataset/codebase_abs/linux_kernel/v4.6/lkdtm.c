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
static void F_20 ( void )
{
F_21 ( L_3 ) ;
return;
}
static T_5 void F_22 ( void )
{
char V_48 [ 8 ] ;
memset ( ( void * ) V_48 , 0 , 64 ) ;
}
static void T_5 F_23 ( void * V_49 )
{
void (* F_24)( void ) = V_49 ;
F_21 ( L_4 , F_19 ) ;
F_19 () ;
memcpy ( V_49 , F_19 , V_50 ) ;
F_25 ( ( unsigned long ) V_49 , ( unsigned long ) V_49 + V_50 ) ;
F_21 ( L_5 , F_24 ) ;
F_24 () ;
}
static void F_26 ( void * V_49 )
{
void (* F_24)( void ) = V_49 ;
F_21 ( L_4 , F_19 ) ;
F_19 () ;
if ( F_27 ( ( void V_51 * ) V_49 , F_19 , V_50 ) )
return;
F_25 ( ( unsigned long ) V_49 , ( unsigned long ) V_49 + V_50 ) ;
F_21 ( L_5 , F_24 ) ;
F_24 () ;
}
static void F_28 ( enum V_26 V_52 )
{
switch ( V_52 ) {
case V_53 :
F_29 ( L_6 ) ;
break;
case V_54 :
F_30 () ;
break;
case V_55 :
F_31 ( 1 ) ;
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
F_22 () ;
break;
case V_60 : {
static T_6 V_48 [ 5 ] V_61 ( ( F_32 ( 4 ) ) ) = { 1 , 2 ,
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
T_7 * V_48 = F_33 ( V_65 , V_66 ) ;
V_48 [ 1024 / sizeof( T_7 ) ] = 0x12345678 ;
F_34 ( V_48 ) ;
break;
}
case V_67 : {
int * V_68 , * V_69 ;
T_4 V_65 = 1024 ;
T_4 V_70 = ( V_65 / sizeof( * V_68 ) ) / 2 ;
V_68 = F_33 ( V_65 , V_66 ) ;
F_21 ( L_7 , V_68 , & V_68 [ V_70 * 2 ] ) ;
F_21 ( L_8 ,
& V_68 [ V_70 ] ) ;
F_34 ( V_68 ) ;
V_68 [ V_70 ] = 0x0abcdef0 ;
V_69 = F_33 ( V_65 , V_66 ) ;
F_34 ( V_69 ) ;
if ( V_69 != V_68 )
F_21 ( L_9 ) ;
break;
}
case V_71 : {
int * V_68 , * V_63 , V_72 ;
T_4 V_65 = 1024 ;
T_4 V_70 = ( V_65 / sizeof( * V_68 ) ) / 2 ;
V_68 = F_33 ( V_65 , V_66 ) ;
if ( ! V_68 )
break;
V_63 = F_33 ( V_65 , V_66 ) ;
if ( ! V_63 ) {
F_34 ( V_68 ) ;
break;
}
* V_63 = 0x12345678 ;
V_68 [ V_70 ] = * V_63 ;
F_21 ( L_10 , V_68 [ V_70 ] ) ;
F_34 ( V_68 ) ;
F_21 ( L_11 ) ;
V_72 = V_68 [ V_70 ] ;
if ( V_72 != * V_63 ) {
F_21 ( L_12 , V_72 ) ;
F_30 () ;
}
F_21 ( L_13 ) ;
F_34 ( V_63 ) ;
break;
}
case V_73 : {
unsigned long V_62 = F_35 ( V_66 ) ;
if ( ! V_62 )
break;
F_21 ( L_14 ) ;
memset ( ( void * ) V_62 , 0x3 , V_74 ) ;
F_36 ( V_62 ) ;
F_37 () ;
F_21 ( L_15 ) ;
memset ( ( void * ) V_62 , 0x78 , V_74 ) ;
V_62 = F_35 ( V_66 ) ;
F_36 ( V_62 ) ;
F_37 () ;
break;
}
case V_75 : {
unsigned long V_62 = F_35 ( V_66 ) ;
int V_72 , * V_63 ;
int * V_68 ;
if ( ! V_62 )
break;
V_63 = F_33 ( 1024 , V_66 ) ;
if ( ! V_63 ) {
F_36 ( V_62 ) ;
break;
}
V_68 = ( int * ) V_62 ;
* V_63 = 0x12345678 ;
V_68 [ 0 ] = * V_63 ;
F_21 ( L_10 , V_68 [ 0 ] ) ;
F_36 ( V_62 ) ;
F_21 ( L_16 ) ;
V_72 = V_68 [ 0 ] ;
if ( V_72 != * V_63 ) {
F_21 ( L_12 , V_72 ) ;
F_30 () ;
}
F_21 ( L_17 ) ;
F_34 ( V_63 ) ;
break;
}
case V_76 :
F_38 () ;
for (; ; )
F_39 () ;
break;
case V_77 :
F_40 () ;
for (; ; )
F_39 () ;
break;
case V_78 :
F_41 ( & V_79 ) ;
F_42 ( & V_79 ) ;
break;
case V_80 :
F_43 ( V_81 ) ;
F_37 () ;
break;
case V_82 :
F_23 ( V_83 ) ;
break;
case V_84 : {
T_6 V_85 [ V_50 ] ;
F_23 ( V_85 ) ;
break;
}
case V_86 : {
T_7 * V_87 = F_33 ( V_50 , V_66 ) ;
F_23 ( V_87 ) ;
F_34 ( V_87 ) ;
break;
}
case V_88 : {
T_7 * V_89 = F_44 ( V_50 ) ;
F_23 ( V_89 ) ;
F_45 ( V_89 ) ;
break;
}
case V_90 : {
unsigned long V_91 ;
V_91 = F_46 ( NULL , 0 , V_74 ,
V_92 | V_93 | V_94 ,
V_95 | V_96 , 0 ) ;
if ( V_91 >= V_97 ) {
F_47 ( L_18 ) ;
return;
}
F_26 ( ( void * ) V_91 ) ;
F_48 ( V_91 , V_74 ) ;
break;
}
case V_98 : {
unsigned long V_91 , V_99 = 0 ;
unsigned long * V_100 ;
V_91 = F_46 ( NULL , 0 , V_74 ,
V_92 | V_93 | V_94 ,
V_95 | V_96 , 0 ) ;
if ( V_91 >= V_97 ) {
F_47 ( L_18 ) ;
return;
}
if ( F_27 ( ( void V_51 * ) V_91 , & V_99 , sizeof( V_99 ) ) ) {
F_47 ( L_19 ) ;
F_48 ( V_91 , V_74 ) ;
return;
}
V_100 = ( unsigned long * ) V_91 ;
F_21 ( L_20 , V_100 ) ;
V_99 = * V_100 ;
V_99 += 0xc0dec0de ;
F_21 ( L_21 , V_100 ) ;
* V_100 = V_99 ;
F_48 ( V_91 , V_74 ) ;
break;
}
case V_101 : {
unsigned long * V_100 = ( unsigned long * ) & V_102 ;
F_21 ( L_22 , V_100 ) ;
* V_100 ^= 0xabcd1234 ;
break;
}
case V_103 : {
unsigned long * V_100 = & V_104 ;
if ( ( * V_100 & 0xAA ) != 0xAA ) {
F_21 ( L_23 , V_100 ) ;
break;
}
F_21 ( L_24 , V_100 ) ;
* V_100 ^= 0xabcd1234 ;
break;
}
case V_105 : {
T_4 V_106 ;
unsigned char * V_100 ;
V_106 = ( unsigned long ) F_20 -
( unsigned long ) F_19 ;
V_100 = ( unsigned char * ) F_20 ;
F_21 ( L_25 , V_106 , V_100 ) ;
memcpy ( V_100 , ( unsigned char * ) F_19 , V_106 ) ;
F_25 ( ( unsigned long ) V_100 ,
( unsigned long ) ( V_100 + V_106 ) ) ;
F_20 () ;
break;
}
case V_107 : {
T_8 V_108 = F_49 ( V_109 ) ;
T_8 V_110 = F_49 ( V_111 ) ;
F_21 ( L_26 ) ;
F_50 ( & V_108 ) ;
F_21 ( L_27 ) ;
F_51 ( & V_110 ) ;
return;
}
case V_31 :
default:
break;
}
}
static void F_2 ( void )
{
unsigned long V_36 ;
bool V_112 = false ;
F_16 ( & V_40 , V_36 ) ;
V_28 -- ;
F_21 ( L_28 ,
F_14 ( V_44 ) , F_13 ( V_43 ) , V_28 ) ;
if ( V_28 == 0 ) {
V_112 = true ;
V_28 = V_37 ;
}
F_17 ( & V_40 , V_36 ) ;
if ( V_112 )
F_28 ( V_43 ) ;
}
static int F_52 ( enum V_32 V_52 )
{
int V_113 ;
V_44 = V_34 ;
if ( V_114 . V_115 != NULL )
F_53 ( & V_114 ) ;
switch ( V_52 ) {
case V_116 :
F_28 ( V_43 ) ;
return 0 ;
case V_117 :
V_114 . V_118 . V_119 = L_29 ;
V_114 . V_115 = ( V_120 * ) F_1 ;
break;
case V_121 :
V_114 . V_118 . V_119 = L_30 ;
V_114 . V_115 = ( V_120 * ) F_4 ;
break;
case V_122 :
V_114 . V_118 . V_119 = L_31 ;
V_114 . V_115 = ( V_120 * ) F_5 ;
break;
case V_123 :
V_114 . V_118 . V_119 = L_32 ;
V_114 . V_115 = ( V_120 * ) F_6 ;
break;
case V_124 :
V_114 . V_118 . V_119 = L_33 ;
V_114 . V_115 = ( V_120 * ) F_7 ;
break;
case V_125 :
V_114 . V_118 . V_119 = L_34 ;
V_114 . V_115 = ( V_120 * ) F_8 ;
break;
case V_126 :
V_114 . V_118 . V_119 = L_35 ;
V_114 . V_115 = ( V_120 * ) F_9 ;
break;
case V_127 :
#ifdef F_54
V_114 . V_118 . V_119 = L_36 ;
V_114 . V_115 = ( V_120 * ) F_10 ;
#else
F_21 ( L_37 ) ;
return - V_39 ;
#endif
break;
default:
F_21 ( L_38 ) ;
return - V_39 ;
}
V_44 = V_52 ;
if ( ( V_113 = F_55 ( & V_114 ) ) < 0 ) {
F_21 ( L_39 ) ;
V_44 = V_34 ;
}
return V_113 ;
}
static T_9 F_56 ( enum V_32 V_52 , struct V_22 * V_128 ,
const char V_51 * V_129 , T_4 V_28 , T_10 * V_130 )
{
char * V_46 ;
int V_131 ;
if ( V_28 >= V_74 )
return - V_39 ;
V_46 = ( char * ) F_35 ( V_66 ) ;
if ( ! V_46 )
return - V_132 ;
if ( F_57 ( V_46 , V_129 , V_28 ) ) {
F_36 ( ( unsigned long ) V_46 ) ;
return - V_133 ;
}
V_46 [ V_28 ] = '\0' ;
F_58 ( V_46 ) ;
V_43 = F_11 ( V_46 , V_28 ) ;
F_36 ( ( unsigned long ) V_46 ) ;
if ( V_43 == V_31 )
return - V_39 ;
V_131 = F_52 ( V_52 ) ;
if ( V_131 < 0 )
return V_131 ;
* V_130 += V_28 ;
return V_28 ;
}
static T_9 F_59 ( struct V_22 * V_128 , char V_51 * V_129 ,
T_4 V_28 , T_10 * V_130 )
{
char * V_46 ;
int V_29 , V_134 , V_135 ;
V_46 = ( char * ) F_35 ( V_66 ) ;
if ( V_46 == NULL )
return - V_132 ;
V_134 = snprintf ( V_46 , V_74 , L_40 ) ;
for ( V_29 = 0 ; V_29 < F_12 ( V_30 ) ; V_29 ++ )
V_134 += snprintf ( V_46 + V_134 , V_74 - V_134 , L_41 , V_30 [ V_29 ] ) ;
V_46 [ V_134 ] = '\0' ;
V_135 = F_60 ( V_129 , V_28 , V_130 ,
V_46 , V_134 ) ;
F_36 ( ( unsigned long ) V_46 ) ;
return V_135 ;
}
static int F_61 ( struct V_136 * V_136 , struct V_22 * V_22 )
{
return 0 ;
}
static T_9 F_62 ( struct V_22 * V_128 , const char V_51 * V_46 ,
T_4 V_28 , T_10 * V_130 )
{
return F_56 ( V_117 , V_128 , V_46 , V_28 , V_130 ) ;
}
static T_9 F_63 ( struct V_22 * V_128 , const char V_51 * V_46 ,
T_4 V_28 , T_10 * V_130 )
{
return F_56 ( V_121 , V_128 , V_46 , V_28 , V_130 ) ;
}
static T_9 F_64 ( struct V_22 * V_128 , const char V_51 * V_46 ,
T_4 V_28 , T_10 * V_130 )
{
return F_56 ( V_122 , V_128 , V_46 , V_28 , V_130 ) ;
}
static T_9 F_65 ( struct V_22 * V_128 , const char V_51 * V_46 ,
T_4 V_28 , T_10 * V_130 )
{
return F_56 ( V_123 , V_128 , V_46 , V_28 , V_130 ) ;
}
static T_9 F_66 ( struct V_22 * V_128 , const char V_51 * V_46 ,
T_4 V_28 , T_10 * V_130 )
{
return F_56 ( V_124 , V_128 , V_46 , V_28 , V_130 ) ;
}
static T_9 F_67 ( struct V_22 * V_128 , const char V_51 * V_46 ,
T_4 V_28 , T_10 * V_130 )
{
return F_56 ( V_125 , V_128 , V_46 , V_28 , V_130 ) ;
}
static T_9 F_68 ( struct V_22 * V_128 ,
const char V_51 * V_46 , T_4 V_28 , T_10 * V_130 )
{
return F_56 ( V_126 , V_128 , V_46 , V_28 , V_130 ) ;
}
static T_9 F_69 ( struct V_22 * V_128 , const char V_51 * V_46 ,
T_4 V_28 , T_10 * V_130 )
{
return F_56 ( V_127 , V_128 , V_46 , V_28 , V_130 ) ;
}
static T_9 F_70 ( struct V_22 * V_128 , const char V_51 * V_129 ,
T_4 V_28 , T_10 * V_130 )
{
enum V_26 type ;
char * V_46 ;
if ( V_28 >= V_74 )
return - V_39 ;
if ( V_28 < 1 )
return - V_39 ;
V_46 = ( char * ) F_35 ( V_66 ) ;
if ( ! V_46 )
return - V_132 ;
if ( F_57 ( V_46 , V_129 , V_28 ) ) {
F_36 ( ( unsigned long ) V_46 ) ;
return - V_133 ;
}
V_46 [ V_28 ] = '\0' ;
F_58 ( V_46 ) ;
type = F_11 ( V_46 , V_28 ) ;
F_36 ( ( unsigned long ) V_46 ) ;
if ( type == V_31 )
return - V_39 ;
F_21 ( L_42 , F_13 ( type ) ) ;
F_28 ( type ) ;
* V_130 += V_28 ;
return V_28 ;
}
static int T_11 F_71 ( void )
{
int V_113 = - V_39 ;
int V_137 = 1 ;
int V_29 ;
V_104 |= 0xAA ;
V_138 = F_72 ( L_43 , NULL ) ;
if ( ! V_138 ) {
F_73 ( L_44 ) ;
return - V_139 ;
}
#ifdef F_74
V_137 = F_12 ( V_140 ) ;
#endif
for ( V_29 = 0 ; V_29 < V_137 ; V_29 ++ ) {
const struct V_141 * V_142 = & V_140 [ V_29 ] ;
struct V_143 * V_144 ;
V_144 = F_75 ( V_142 -> V_33 , 0644 , V_138 ,
NULL , & V_142 -> V_145 ) ;
if ( V_144 == NULL ) {
F_73 ( L_45 , V_142 -> V_33 ) ;
goto V_146;
}
}
if ( F_15 () == - V_39 ) {
F_21 ( L_46 ) ;
goto V_146;
}
if ( V_44 != V_34 && V_43 != V_31 ) {
V_113 = F_52 ( V_44 ) ;
if ( V_113 < 0 ) {
F_21 ( L_47 , V_44 ) ;
goto V_146;
}
F_21 ( L_48 ,
V_42 , V_41 ) ;
} else {
F_21 ( L_49 ) ;
}
return 0 ;
V_146:
F_76 ( V_138 ) ;
return V_113 ;
}
static void T_12 F_77 ( void )
{
F_76 ( V_138 ) ;
F_53 ( & V_114 ) ;
F_21 ( L_50 ) ;
}
