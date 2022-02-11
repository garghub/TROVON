static inline int F_1 ( T_1 V_1 , unsigned char * V_2 )
{
T_1 V_3 ;
int V_4 , V_5 ;
V_4 = sizeof( V_2 [ 0 ] ) * 8 ;
V_3 = V_1 / V_4 ;
V_5 = V_1 % V_4 ;
return ( V_2 [ V_3 ] & ( 1 << V_5 ) ) != 0 ;
}
static inline void F_2 ( T_1 V_1 , unsigned char * V_2 )
{
T_1 V_3 ;
int V_4 , V_5 ;
V_4 = sizeof( V_2 [ 0 ] ) * 8 ;
V_3 = V_1 / V_4 ;
V_5 = V_1 % V_4 ;
V_2 [ V_3 ] |= ( 1 << V_5 ) ;
}
static void F_3 ( void )
{
V_6 = F_4 ( L_1 , NULL ) ;
V_7 = F_4 ( L_2 , V_6 ) ;
}
static int F_5 ( struct V_8 * V_9 , void * V_10 )
{
F_6 ( V_9 , L_3 ) ;
return 0 ;
}
static int F_7 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
return F_8 ( V_12 , F_5 , NULL ) ;
}
static void F_9 ( const char * V_13 )
{
struct V_14 * V_15 , * V_16 ;
char V_17 [ 64 ] ;
if( V_6 == NULL ) F_3 () ;
V_15 = F_4 ( V_13 , V_7 ) ;
if( ! V_15 ) return;
V_16 = F_10 ( L_4 , V_18 , V_15 , & V_19 ) ;
if( ! V_16 ) return;
snprintf ( V_17 , sizeof( V_17 ) , L_5 , V_13 ) ;
F_11 ( V_13 , V_6 , V_17 ) ;
}
static int F_12 ( char * V_20 )
{
V_21 = 1 ;
return 1 ;
}
static int F_13 ( char * * V_22 )
{
char * V_20 = * V_22 , * V_23 ;
int V_3 = - 1 ;
if( isdigit ( * V_20 ) ) {
V_3 = F_14 ( V_20 , & V_23 , 0 ) ;
if( V_23 == V_20 )
return - 1 ;
* V_22 = V_23 ;
}
else if ( ( 'a' <= * V_20 ) && ( * V_20 <= 'z' ) ) {
V_3 = * V_20 - 'a' ;
V_20 ++ ;
* V_22 = V_20 ;
}
return V_3 ;
}
static int F_15 ( char * V_20 , int * V_24 , char * * V_25 )
{
struct V_26 * V_27 ;
struct V_28 V_29 = V_30 ;
char * V_31 ;
int V_3 , V_32 = 0 , V_33 ;
if( V_24 ) * V_24 = - 1 ;
V_3 = * V_20 ;
if( V_3 == '=' ) {
char * V_23 ;
int V_34 ;
V_20 ++ ;
if( ! strcmp ( V_20 , L_6 ) ) {
V_30 = F_16 ( V_30 ) ;
goto V_35;
}
V_32 = - V_36 ;
V_34 = F_14 ( V_20 , & V_23 , 0 ) ;
if( ( * V_23 != '\0' ) || ( V_23 == V_20 ) ) {
* V_25 = L_7 ;
goto V_35;
}
F_17 ( & V_37 ) ;
if ( V_38 != V_39 ) {
* V_25 = L_8 ;
goto V_35;
}
V_38 = V_34 ;
F_18 ( V_40 L_9 ,
V_34 ) ;
V_32 = 0 ;
V_35:
F_19 ( & V_37 ) ;
return V_32 ;
}
V_3 = F_13 ( & V_20 ) ;
if( V_3 < 0 ) {
* V_25 = L_10 ;
return - V_36 ;
}
if( V_3 >= V_41 ) {
* V_25 = L_11 ;
return 1 ;
}
V_32 = - V_42 ;
F_17 ( & V_37 ) ;
V_27 = & V_43 [ V_3 ] ;
if( V_27 -> V_12 != NULL ) {
* V_25 = L_12 ;
goto V_44;
}
if ( V_24 )
* V_24 = V_3 ;
V_32 = - V_36 ;
for ( V_33 = 0 ; V_33 < sizeof( L_13 ) ; V_33 ++ ) {
switch ( * V_20 ) {
case 'r' :
V_29 . V_45 = 0 ;
break;
case 's' :
V_29 . V_46 = 1 ;
break;
case 'd' :
V_27 -> V_47 = 1 ;
break;
case 'c' :
V_27 -> V_48 = 1 ;
break;
case '=' :
V_20 ++ ;
goto V_49;
default:
* V_25 = L_14
L_15 ;
goto V_44;
}
V_20 ++ ;
}
if ( * V_20 == '=' )
* V_25 = L_16 ;
else
* V_25 = L_17 ;
goto V_44;
V_49:
V_31 = strchr ( V_20 , ',' ) ;
if ( V_31 == NULL )
V_31 = strchr ( V_20 , ':' ) ;
if( V_31 != NULL ) {
if( V_27 -> V_47 ) {
* V_25 = L_18 ;
goto V_44;
}
else {
* V_31 = '\0' ;
V_31 ++ ;
}
}
V_32 = 0 ;
V_27 -> V_12 = V_20 ;
V_27 -> V_50 . V_12 = V_31 ;
V_27 -> V_51 = V_29 ;
V_44:
F_19 ( & V_37 ) ;
return V_32 ;
}
static int F_20 ( char * V_20 )
{
char * error ;
int V_32 ;
V_32 = F_15 ( V_20 , NULL , & error ) ;
if( V_32 )
F_18 ( V_52 L_19
L_20 , V_20 , error ) ;
return 1 ;
}
static int F_21 ( char * V_20 )
{
F_18 ( L_21
L_22 , V_20 ) ;
return 1 ;
}
static void F_22 ( void )
{
struct V_26 * V_26 ;
struct V_53 * V_54 , * V_55 ;
unsigned long V_29 ;
int V_3 ;
int V_56 ;
while( 1 ) {
V_3 = F_23 (
V_57 ,
V_58 ,
& V_59 ,
& V_60 ,
V_61
) ;
if ( V_3 < 0 ) {
if( V_3 == - V_62 )
break;
F_18 ( V_52 L_23
L_24 , - V_3 ) ;
return;
}
for ( V_56 = 0 ; V_56 < V_3 / sizeof( struct V_63 * ) ; V_56 ++ ) {
F_24 (
( * V_58 ) [ V_56 ] -> V_64 ,
V_65 ,
( * V_58 ) [ V_56 ] -> V_66
) ;
F_25 ( ( * V_58 ) [ V_56 ] ) ;
}
}
F_26 ( V_57 , V_67 ) ;
F_27 (list, next_ele, &restart) {
V_26 = F_28 ( V_54 , struct V_26 , V_68 ) ;
F_29 ( & V_26 -> V_68 ) ;
F_30 ( & V_26 -> V_69 , V_29 ) ;
F_31 ( V_26 -> V_70 ) ;
F_32 ( & V_26 -> V_69 , V_29 ) ;
}
}
static T_2 F_33 ( int V_71 , void * V_72 )
{
F_22 () ;
return V_73 ;
}
static void F_34 ( void )
{
if( V_74 != - 1 )
F_35 ( V_74 , 1 ) ;
}
static inline int F_36 ( struct V_26 * V_27 , T_1 * V_75 )
{
char * V_12 ;
int V_76 ;
int V_32 ;
T_3 V_77 ;
T_3 V_78 ;
char * V_31 ;
T_4 V_79 ;
unsigned long long V_80 ;
int V_81 ;
int V_82 ;
if ( V_27 -> V_12 && V_27 -> V_50 . V_12 ) {
V_12 = V_27 -> V_50 . V_12 ;
goto V_44;
}
V_76 = F_37 ( V_27 -> V_12 , F_38 ( F_39 () ) , 0 ) ;
if ( V_76 < 0 )
return V_76 ;
V_32 = F_40 ( V_83 , & V_76 , & V_77 , & V_31 , \
& V_79 , & V_80 , & V_81 , & V_78 , & V_82 ) ;
F_41 ( V_76 ) ;
if( V_32 == - V_36 )
V_12 = V_27 -> V_12 ;
else
V_12 = V_31 ;
V_44:
return F_42 ( V_12 , V_75 ) ;
}
static int F_43 ( int V_76 , void * V_84 , int V_85 , int V_86 )
{
int V_32 ;
V_32 = F_44 ( V_76 , V_84 , V_86 , V_85 ) ;
if ( V_32 < 0 )
return V_32 ;
return 0 ;
}
static int F_45 ( char * V_12 , T_1 V_80 , T_4 V_79 )
{
unsigned long V_87 ;
unsigned long long V_88 ;
int V_32 ;
V_32 = F_46 ( V_12 , & V_87 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_25
L_26 , V_12 , - V_32 ) ;
return V_32 ;
}
V_32 = F_42 ( V_12 , & V_88 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_27
L_24 , V_12 , - V_32 ) ;
return V_32 ;
}
if ( V_88 != V_80 ) {
F_18 ( V_52 L_28
L_29 , ( unsigned long long ) V_80 , V_88 ) ;
return - V_36 ;
}
if ( V_87 != V_79 ) {
F_18 ( V_52 L_30
L_31 , V_79 , V_87 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_47 ( char * V_89 , char * V_90 , char * V_50 )
{
struct V_91 V_92 , V_93 ;
int V_32 ;
if ( V_89 == NULL )
return 0 ;
if ( ! strcmp ( V_89 , V_90 ) )
return 0 ;
V_32 = F_48 ( V_89 , & V_92 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_32 , V_89 ,
- V_32 ) ;
return 0 ;
}
V_32 = F_48 ( V_90 , & V_93 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_32 , V_90 ,
- V_32 ) ;
return 1 ;
}
if ( ( V_92 . V_94 == V_93 . V_94 ) && ( V_92 . V_95 == V_93 . V_95 ) )
return 0 ;
F_18 ( V_52 L_33
L_34 ,
V_89 , V_90 , V_50 ) ;
return 1 ;
}
static int F_49 ( char * V_12 , struct V_28 * V_28 , int V_48 ,
char * * V_96 , int * V_97 ,
unsigned long * V_98 , int * V_99 ,
int * V_100 )
{
T_4 V_79 ;
unsigned long long V_80 ;
T_3 V_77 , V_78 ;
char * V_31 ;
int V_76 , V_32 , V_101 , V_102 , V_103 = 0644 ;
V_76 = F_37 ( V_12 , * V_28 , V_103 ) ;
if ( V_76 < 0 ) {
if ( ( V_76 == - V_104 ) && ( V_100 != NULL ) )
* V_100 = 1 ;
if ( ! V_28 -> V_45 ||
( ( V_76 != - V_105 ) && ( V_76 != - V_106 ) ) )
return V_76 ;
V_28 -> V_45 = 0 ;
V_76 = F_37 ( V_12 , * V_28 , V_103 ) ;
if ( V_76 < 0 )
return V_76 ;
}
if ( V_48 )
F_18 ( V_40 L_35 , V_12 ) ;
else {
V_32 = F_50 ( V_76 , V_28 -> V_45 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_36 ,
V_12 , - V_32 ) ;
goto V_107;
}
}
if ( V_96 == NULL )
return V_76 ;
V_32 = F_40 ( V_83 , & V_76 , & V_77 , & V_31 , & V_79 ,
& V_80 , & V_101 , & V_78 , V_97 ) ;
if ( V_32 && ( * V_96 != NULL ) ) {
F_18 ( V_52 L_37
L_38 , V_12 , - V_32 ) ;
goto V_107;
}
if ( V_32 )
return V_76 ;
V_102 = F_47 ( * V_96 , V_31 ,
V_12 ) ;
if ( V_102 && ! F_45 ( * V_96 , V_80 ,
V_79 ) ) {
F_18 ( V_52 L_39 ,
* V_96 ) ;
V_32 = F_51 ( V_12 , V_76 , * V_96 ,
V_101 , V_78 , & V_80 ) ;
if ( V_32 ) {
F_18 ( V_52 L_40 , - V_32 ) ;
goto V_107;
}
} else {
* V_96 = V_31 ;
V_32 = F_45 ( * V_96 , V_80 , V_79 ) ;
if ( V_32 )
goto V_107;
}
F_52 ( V_77 , V_80 , V_101 , V_78 , * V_97 ,
V_98 , V_99 ) ;
return V_76 ;
V_107:
F_41 ( V_76 ) ;
return V_32 ;
}
static int F_53 ( char * V_108 , char * V_31 ,
struct V_28 V_29 ,
int V_101 , int V_109 , int * V_97 ,
unsigned long * V_98 , int * V_99 )
{
int V_32 , V_76 ;
V_29 . V_110 = 1 ;
V_76 = F_49 ( V_108 , & V_29 , 0 , NULL , NULL , NULL , NULL , NULL ) ;
if ( V_76 < 0 ) {
V_32 = V_76 ;
F_18 ( V_52 L_41 ,
V_108 , - V_32 ) ;
goto V_44;
}
V_32 = F_54 ( V_76 , V_108 , V_31 , V_101 , V_109 ,
V_97 , V_98 ,
V_99 ) ;
if ( ! V_32 )
return V_76 ;
F_41 ( V_76 ) ;
V_44:
return V_32 ;
}
static void F_55 ( struct V_26 * V_27 )
{
F_41 ( V_27 -> V_76 ) ;
if( V_27 -> V_50 . V_12 == NULL )
return;
F_41 ( V_27 -> V_50 . V_76 ) ;
F_56 ( V_27 -> V_50 . V_111 ) ;
V_27 -> V_50 . V_111 = NULL ;
}
static int F_57 ( struct V_26 * V_27 )
{
struct V_28 V_29 ;
char * * V_112 ;
int V_32 , V_113 , * V_114 ;
int V_76 ;
V_27 -> V_28 = V_27 -> V_51 ;
V_113 = 0 ;
V_114 = ( V_27 -> V_50 . V_12 != NULL ) ? & V_113 : NULL ;
V_112 = V_27 -> V_47 ? NULL : & V_27 -> V_50 . V_12 ;
V_76 = F_49 ( V_27 -> V_12 , & V_27 -> V_28 , V_27 -> V_48 ,
V_112 , & V_27 -> V_50 . V_82 ,
& V_27 -> V_50 . V_115 , & V_27 -> V_50 . V_116 ,
V_114 ) ;
if( ( V_76 == - V_104 ) && V_113 ) {
V_76 = F_53 ( V_27 -> V_12 , V_27 -> V_50 . V_12 ,
V_27 -> V_28 , 1 << 9 , V_117 ,
& V_27 -> V_50 . V_82 ,
& V_27 -> V_50 . V_115 ,
& V_27 -> V_50 . V_116 ) ;
if( V_76 >= 0 ) {
F_18 ( V_40 L_42
L_43 , V_27 -> V_12 , V_27 -> V_50 . V_12 ) ;
}
}
if( V_76 < 0 ) {
F_18 ( L_44 , V_27 -> V_12 ,
- V_76 ) ;
return V_76 ;
}
V_27 -> V_76 = V_76 ;
if( V_27 -> V_50 . V_12 != NULL ) {
F_58 ( V_27 -> V_70 , 8 * sizeof( long ) ) ;
V_32 = - V_118 ;
V_27 -> V_50 . V_111 = F_59 ( V_27 -> V_50 . V_115 ) ;
if( V_27 -> V_50 . V_111 == NULL ) {
F_18 ( V_52 L_45 ) ;
goto error;
}
F_60 () ;
V_32 = F_43 ( V_27 -> V_76 , V_27 -> V_50 . V_111 ,
V_27 -> V_50 . V_82 ,
V_27 -> V_50 . V_115 ) ;
if( V_32 < 0 )
goto error;
V_29 = V_27 -> V_28 ;
V_29 . V_45 = 0 ;
V_32 = F_49 ( V_27 -> V_50 . V_12 , & V_29 , V_27 -> V_48 , NULL ,
NULL , NULL , NULL , NULL ) ;
if( V_32 < 0 ) goto error;
V_27 -> V_50 . V_76 = V_32 ;
}
return 0 ;
error:
F_41 ( V_27 -> V_76 ) ;
return V_32 ;
}
static void F_61 ( struct V_119 * V_72 )
{
struct V_26 * V_27 = F_62 ( V_72 ) ;
F_63 ( V_27 -> V_70 ) ;
* V_27 = ( (struct V_26 ) V_120 ) ;
}
static int F_64 ( int V_34 , T_5 V_80 , int V_121 ,
struct V_122 * * V_123 )
{
struct V_119 * V_124 = NULL ;
struct V_122 * V_125 ;
V_125 = F_65 ( 1 << V_126 ) ;
if( V_125 == NULL )
return - V_118 ;
V_125 -> V_34 = V_34 ;
V_125 -> V_127 = V_121 << V_126 ;
V_125 -> V_128 = & V_129 ;
F_66 ( V_125 , V_80 / 512 ) ;
if ( V_34 == V_39 )
sprintf ( V_125 -> V_130 , L_46 , 'a' + V_121 ) ;
else
sprintf ( V_125 -> V_130 , L_47 , V_121 ) ;
if ( V_34 == V_39 ) {
V_43 [ V_121 ] . V_131 . V_132 = V_121 ;
V_43 [ V_121 ] . V_131 . V_17 = V_133 ;
V_43 [ V_121 ] . V_131 . V_72 . V_134 = F_61 ;
F_67 ( & V_43 [ V_121 ] . V_131 . V_72 , & V_43 [ V_121 ] ) ;
F_68 ( & V_43 [ V_121 ] . V_131 ) ;
V_124 = & V_43 [ V_121 ] . V_131 . V_72 ;
}
V_125 -> V_135 = & V_43 [ V_121 ] ;
V_125 -> V_70 = V_43 [ V_121 ] . V_70 ;
F_69 ( V_124 , V_125 ) ;
* V_123 = V_125 ;
return 0 ;
}
static int F_70 ( int V_3 , char * * V_25 )
{
struct V_26 * V_27 = & V_43 [ V_3 ] ;
int V_32 = 0 ;
if( V_27 -> V_12 == NULL )
goto V_44;
V_32 = F_36 ( V_27 , & V_27 -> V_80 ) ;
if( V_32 < 0 ) {
* V_25 = L_48 ;
goto V_44;
}
V_27 -> V_80 = F_71 ( V_27 -> V_80 ) ;
F_72 ( & V_27 -> V_68 ) ;
F_73 ( V_27 -> V_136 , V_137 ) ;
V_32 = - V_118 ;
V_27 -> V_70 = F_74 ( F_31 , & V_27 -> V_69 ) ;
if ( V_27 -> V_70 == NULL ) {
* V_25 = L_49 ;
goto V_44;
}
V_27 -> V_70 -> V_138 = V_27 ;
F_75 ( V_27 -> V_70 , true , false ) ;
F_76 ( V_27 -> V_70 , V_137 ) ;
V_32 = F_64 ( V_39 , V_27 -> V_80 , V_3 , & V_139 [ V_3 ] ) ;
if( V_32 ) {
* V_25 = L_50 ;
goto V_140;
}
if ( V_38 != V_39 )
F_64 ( V_38 , V_27 -> V_80 , V_3 ,
& V_141 [ V_3 ] ) ;
if ( V_21 )
F_9 ( V_139 [ V_3 ] -> V_130 ) ;
V_32 = 0 ;
V_44:
return V_32 ;
V_140:
F_63 ( V_27 -> V_70 ) ;
goto V_44;
}
static int F_77 ( char * V_20 , char * * V_25 )
{
int V_3 , V_142 ;
V_20 = F_78 ( V_20 , V_143 ) ;
if ( V_20 == NULL ) {
* V_25 = L_51 ;
return - V_118 ;
}
V_142 = F_15 ( V_20 , & V_3 , V_25 ) ;
if ( V_142 )
goto V_144;
if ( V_3 == - 1 ) {
V_142 = 0 ;
goto V_144;
}
F_17 ( & V_37 ) ;
V_142 = F_70 ( V_3 , V_25 ) ;
if ( V_142 )
V_43 [ V_3 ] . V_12 = NULL ;
F_19 ( & V_37 ) ;
V_44:
return V_142 ;
V_144:
F_25 ( V_20 ) ;
goto V_44;
}
static int F_79 ( char * V_17 , char * V_20 , int V_80 , char * * V_25 )
{
struct V_26 * V_27 ;
int V_3 , V_86 = 0 ;
V_3 = F_13 ( & V_17 ) ;
if( ( V_3 >= V_41 ) || ( V_3 < 0 ) ) {
* V_25 = L_52 ;
return - 1 ;
}
V_27 = & V_43 [ V_3 ] ;
F_17 ( & V_37 ) ;
if( V_27 -> V_12 == NULL ) {
F_80 ( V_20 , V_80 , V_86 , L_53 , 1 ) ;
goto V_44;
}
F_80 ( V_20 , V_80 , V_86 , V_27 -> V_12 , 0 ) ;
if( V_27 -> V_50 . V_12 != NULL ) {
F_80 ( V_20 , V_80 , V_86 , L_54 , 0 ) ;
F_80 ( V_20 , V_80 , V_86 , V_27 -> V_50 . V_12 , 1 ) ;
}
else F_80 ( V_20 , V_80 , V_86 , L_53 , 1 ) ;
V_44:
F_19 ( & V_37 ) ;
return V_86 ;
}
static int F_81 ( char * * V_20 , int * V_145 , int * V_146 )
{
int V_3 ;
V_3 = F_13 ( V_20 ) ;
* V_145 = 0 ;
* V_146 = V_41 - 1 ;
return V_3 ;
}
static int F_82 ( int V_3 , char * * V_25 )
{
struct V_122 * V_125 = V_139 [ V_3 ] ;
struct V_26 * V_27 ;
int V_32 = - V_147 ;
F_17 ( & V_37 ) ;
V_27 = & V_43 [ V_3 ] ;
if( V_27 -> V_12 == NULL )
goto V_44;
V_32 = - V_42 ;
if( V_27 -> V_56 > 0 )
goto V_44;
V_139 [ V_3 ] = NULL ;
if( V_125 != NULL ) {
F_83 ( V_125 ) ;
F_84 ( V_125 ) ;
}
if( V_141 [ V_3 ] != NULL ) {
F_83 ( V_141 [ V_3 ] ) ;
F_84 ( V_141 [ V_3 ] ) ;
V_141 [ V_3 ] = NULL ;
}
V_32 = 0 ;
F_85 ( & V_27 -> V_131 ) ;
V_44:
F_19 ( & V_37 ) ;
return V_32 ;
}
static int T_6 F_86 ( void )
{
F_87 ( & V_148 ) ;
return 0 ;
}
static int T_6 F_88 ( void )
{
struct V_26 * V_27 = & V_43 [ 0 ] ;
F_17 ( & V_37 ) ;
if( V_27 -> V_12 == NULL )
V_27 -> V_12 = L_55 ;
F_19 ( & V_37 ) ;
return 0 ;
}
static int T_6 F_89 ( void )
{
char * error ;
int V_33 , V_32 ;
if ( F_90 ( V_39 , L_56 ) )
return - 1 ;
if ( V_38 != V_39 ) {
char V_17 [ sizeof( L_57 ) ] ;
snprintf ( V_17 , sizeof( V_17 ) , L_58 , V_38 ) ;
if ( F_90 ( V_38 , L_56 ) )
return - 1 ;
}
V_58 = F_91 (
sizeof( struct V_63 * ) * V_61 ,
V_143
) ;
V_59 = 0 ;
if ( V_58 == NULL ) {
F_18 ( V_52 L_59 ) ;
return - 1 ;
}
V_149 = F_91 (
sizeof( struct V_63 * ) * V_61 ,
V_143
) ;
V_150 = 0 ;
if ( V_149 == NULL ) {
F_18 ( V_52 L_59 ) ;
return - 1 ;
}
F_92 ( & V_151 ) ;
F_17 ( & V_37 ) ;
for ( V_33 = 0 ; V_33 < V_41 ; V_33 ++ ) {
V_32 = F_70 ( V_33 , & error ) ;
if( V_32 )
F_18 ( V_52 L_60
L_20 , V_33 , error ) ;
}
F_19 ( & V_37 ) ;
return 0 ;
}
static int T_6 F_93 ( void ) {
unsigned long V_152 ;
int V_32 ;
if( V_30 . V_46 ) {
F_18 ( V_40 L_61 ) ;
}
V_152 = F_94 ( 0 , 0 ) ;
V_74 = F_95 ( V_152 + V_117 - sizeof( void * ) ,
& V_57 ) ;
if( V_74 < 0 ) {
F_18 ( V_52
L_62
L_63 , - V_74 ) ;
V_74 = - 1 ;
return 0 ;
}
V_32 = F_96 ( V_67 , V_57 , V_153 , F_33 ,
0 , L_56 , V_43 ) ;
if( V_32 != 0 )
F_18 ( V_52 L_64 , - V_32 ) ;
return 0 ;
}
static int F_97 ( struct V_154 * V_155 , T_7 V_103 )
{
struct V_122 * V_125 = V_155 -> V_156 ;
struct V_26 * V_27 = V_125 -> V_135 ;
int V_32 = 0 ;
F_17 ( & V_157 ) ;
if( V_27 -> V_56 == 0 ) {
V_32 = F_57 ( V_27 ) ;
if( V_32 ) {
F_18 ( V_52 L_65 ,
V_125 -> V_130 , V_27 -> V_12 , - V_32 ) ;
goto V_44;
}
}
V_27 -> V_56 ++ ;
F_98 ( V_125 , ! V_27 -> V_28 . V_45 ) ;
V_44:
F_19 ( & V_157 ) ;
return V_32 ;
}
static void F_99 ( struct V_122 * V_125 , T_7 V_103 )
{
struct V_26 * V_27 = V_125 -> V_135 ;
F_17 ( & V_157 ) ;
if( -- V_27 -> V_56 == 0 )
F_55 ( V_27 ) ;
F_19 ( & V_157 ) ;
}
static void F_100 ( T_1 V_158 , int V_66 , unsigned long * V_159 ,
T_1 * V_160 , unsigned long * V_111 ,
T_1 V_82 , unsigned long * V_161 ,
T_1 V_115 )
{
T_1 V_162 = V_158 >> 9 ;
int V_33 , V_163 = 0 ;
for( V_33 = 0 ; V_33 < V_66 > > 9 ; V_33 ++ ) {
if( V_159 != NULL )
F_2 ( V_33 , ( unsigned char * ) V_159 ) ;
if( F_1 ( V_162 + V_33 , ( unsigned char * ) V_111 ) )
continue;
V_163 = 1 ;
F_2 ( V_162 + V_33 , ( unsigned char * ) V_111 ) ;
}
if( ! V_163 )
return;
* V_160 = V_162 / (sizeof( unsigned long ) * 8 ) ;
if ( * V_160 == ( F_101 ( V_115 ,
sizeof( unsigned long ) ) - 1 ) )
( * V_160 ) -- ;
V_161 [ 0 ] = V_111 [ * V_160 ] ;
V_161 [ 1 ] = V_111 [ * V_160 + 1 ] ;
* V_160 *= sizeof( unsigned long ) ;
* V_160 += V_82 ;
}
static void F_102 ( struct V_63 * V_64 , unsigned long * V_111 ,
T_1 V_82 , T_1 V_115 )
{
T_1 V_162 = V_64 -> V_85 >> 9 ;
int V_33 ;
if( V_64 -> V_66 > ( sizeof( V_64 -> V_164 ) * 8 ) << 9 )
F_103 ( L_66 ) ;
if( V_64 -> V_165 == V_166 ) {
for( V_33 = 0 ; V_33 < V_64 -> V_66 > > 9 ; V_33 ++ ) {
if( F_1 ( V_162 + V_33 , ( unsigned char * ) V_111 ) )
F_2 ( V_33 , ( unsigned char * )
& V_64 -> V_164 ) ;
}
}
else F_100 ( V_64 -> V_85 , V_64 -> V_66 , & V_64 -> V_164 ,
& V_64 -> V_160 , V_111 , V_82 ,
V_64 -> V_161 , V_115 ) ;
}
static void F_104 ( struct V_167 * V_64 , struct V_63 * V_168 ,
unsigned long long V_85 , int V_169 ,
int V_86 , struct V_170 * V_170 )
{
struct V_122 * V_125 = V_64 -> V_171 ;
struct V_26 * V_27 = V_125 -> V_135 ;
V_168 -> V_64 = V_64 ;
V_168 -> V_172 [ 0 ] = ( V_27 -> V_50 . V_12 != NULL ) ? V_27 -> V_50 . V_76 :
V_27 -> V_76 ;
V_168 -> V_172 [ 1 ] = V_27 -> V_76 ;
V_168 -> V_160 = - 1 ;
V_168 -> V_85 = V_85 ;
V_168 -> V_66 = V_86 ;
V_168 -> error = 0 ;
V_168 -> V_164 = 0 ;
V_168 -> V_165 = ( F_105 ( V_64 ) == V_173 ) ? V_166 : V_174 ;
V_168 -> V_175 [ 0 ] = 0 ;
V_168 -> V_175 [ 1 ] = V_27 -> V_50 . V_116 ;
V_168 -> V_176 = F_106 ( V_170 ) + V_169 ;
V_168 -> V_101 = 1 << 9 ;
if( V_27 -> V_50 . V_12 != NULL )
F_102 ( V_168 , V_27 -> V_50 . V_111 ,
V_27 -> V_50 . V_82 , V_27 -> V_50 . V_115 ) ;
}
static void F_107 ( struct V_167 * V_64 ,
struct V_63 * V_168 )
{
struct V_122 * V_125 = V_64 -> V_171 ;
struct V_26 * V_27 = V_125 -> V_135 ;
V_168 -> V_64 = V_64 ;
V_168 -> V_172 [ 0 ] = ( V_27 -> V_50 . V_12 != NULL ) ? V_27 -> V_50 . V_76 :
V_27 -> V_76 ;
V_168 -> V_165 = V_177 ;
}
static bool F_108 ( struct V_63 * V_168 , struct V_26 * V_72 )
{
int V_3 = F_109 ( V_57 , & V_168 ,
sizeof( V_168 ) ) ;
if ( V_3 != sizeof( V_168 ) ) {
if ( V_3 != - V_62 )
F_18 ( L_67
L_68 , - V_3 ) ;
else if ( F_110 ( & V_72 -> V_68 ) )
F_111 ( & V_72 -> V_68 , & V_68 ) ;
F_25 ( V_168 ) ;
return false ;
}
return true ;
}
static void F_31 ( struct V_178 * V_179 )
{
struct V_63 * V_168 ;
struct V_167 * V_64 ;
while( 1 ) {
struct V_26 * V_72 = V_179 -> V_138 ;
if( V_72 -> V_167 == NULL ) {
struct V_167 * V_64 = F_112 ( V_179 ) ;
if( V_64 == NULL )
return;
V_72 -> V_167 = V_64 ;
V_72 -> V_180 = F_113 ( V_64 ) ;
V_72 -> V_181 = 0 ;
V_72 -> V_182 = F_114 ( V_179 , V_64 , V_72 -> V_136 ) ;
}
V_64 = V_72 -> V_167 ;
if ( F_115 ( V_64 ) == V_183 ) {
V_168 = F_91 ( sizeof( struct V_63 ) ,
V_184 ) ;
if ( V_168 == NULL ) {
if ( F_110 ( & V_72 -> V_68 ) )
F_111 ( & V_72 -> V_68 , & V_68 ) ;
return;
}
F_107 ( V_64 , V_168 ) ;
if ( F_108 ( V_168 , V_72 ) == false )
return;
}
while( V_72 -> V_181 < V_72 -> V_182 ) {
struct V_185 * V_136 = & V_72 -> V_136 [ V_72 -> V_181 ] ;
V_168 = F_91 ( sizeof( struct V_63 ) ,
V_184 ) ;
if( V_168 == NULL ) {
if( F_110 ( & V_72 -> V_68 ) )
F_111 ( & V_72 -> V_68 , & V_68 ) ;
return;
}
F_104 ( V_64 , V_168 ,
( unsigned long long ) V_72 -> V_180 << 9 ,
V_136 -> V_85 , V_136 -> V_66 , F_116 ( V_136 ) ) ;
if ( F_108 ( V_168 , V_72 ) == false )
return;
V_72 -> V_180 += V_136 -> V_66 >> 9 ;
V_72 -> V_181 ++ ;
}
V_72 -> V_182 = 0 ;
V_72 -> V_167 = NULL ;
}
}
static int F_117 ( struct V_154 * V_155 , struct V_186 * V_187 )
{
struct V_26 * V_27 = V_155 -> V_156 -> V_135 ;
V_187 -> V_188 = 128 ;
V_187 -> V_189 = 32 ;
V_187 -> V_190 = V_27 -> V_80 / ( 128 * 32 * 512 ) ;
return 0 ;
}
static int F_118 ( struct V_154 * V_155 , T_7 V_103 ,
unsigned int V_191 , unsigned long V_192 )
{
struct V_26 * V_27 = V_155 -> V_156 -> V_135 ;
T_8 F_81 [ V_193 ] ;
switch ( V_191 ) {
struct V_194 V_195 ;
case V_196 :
memset ( & F_81 , 0 , V_193 * 2 ) ;
F_81 [ V_197 ] = V_27 -> V_80 / ( 128 * 32 * 512 ) ;
F_81 [ V_198 ] = 128 ;
F_81 [ V_199 ] = 32 ;
if( F_119 ( ( char V_200 * ) V_192 , ( char * ) & F_81 ,
sizeof( F_81 ) ) )
return - V_201 ;
return 0 ;
case V_202 :
if( F_120 ( & V_195 , ( char V_200 * ) V_192 , sizeof( V_195 ) ) )
return - V_201 ;
V_195 . V_203 = 255 ;
V_195 . V_204 = 255 ;
V_195 . V_205 = 255 ;
V_195 . V_206 = 255 ;
if( F_119 ( ( char V_200 * ) V_192 , & V_195 , sizeof( V_195 ) ) )
return - V_201 ;
return 0 ;
}
return - V_36 ;
}
static int V_163 ( struct V_63 * V_64 )
{
int V_3 ;
if( V_64 -> V_160 == - 1 )
return 0 ;
V_3 = F_121 ( V_64 -> V_172 [ 1 ] , & V_64 -> V_161 ,
sizeof( V_64 -> V_161 ) , V_64 -> V_160 ) ;
if( V_3 != sizeof( V_64 -> V_161 ) ) {
F_18 ( L_69 , - V_3 ,
V_64 -> V_172 [ 1 ] ) ;
return 1 ;
}
return 0 ;
}
static void F_122 ( struct V_63 * V_64 )
{
char * V_84 ;
unsigned long V_86 ;
int V_3 , V_207 , V_208 , V_23 , V_1 ;
T_1 V_5 ;
if ( V_64 -> V_165 == V_177 ) {
V_3 = F_123 ( V_64 -> V_172 [ 0 ] ) ;
if ( V_3 != 0 ) {
F_18 ( L_70
L_71 , - V_3 , V_64 -> V_172 [ 0 ] ) ;
V_64 -> error = 1 ;
}
return;
}
V_207 = V_64 -> V_66 / V_64 -> V_101 ;
V_208 = 0 ;
do {
V_1 = F_1 ( V_208 , ( unsigned char * ) & V_64 -> V_164 ) ;
V_23 = V_208 ;
while( ( V_23 < V_207 ) &&
( F_1 ( V_23 , ( unsigned char * )
& V_64 -> V_164 ) == V_1 ) )
V_23 ++ ;
V_5 = V_64 -> V_85 + V_64 -> V_175 [ V_1 ] +
V_208 * V_64 -> V_101 ;
V_86 = ( V_23 - V_208 ) * V_64 -> V_101 ;
V_84 = & V_64 -> V_176 [ V_208 * V_64 -> V_101 ] ;
if( V_64 -> V_165 == V_166 ) {
V_3 = 0 ;
do {
V_84 = & V_84 [ V_3 ] ;
V_86 -= V_3 ;
V_3 = F_44 ( V_64 -> V_172 [ V_1 ] , V_84 , V_86 , V_5 ) ;
if ( V_3 < 0 ) {
F_18 ( L_72
L_71 , - V_3 , V_64 -> V_172 [ V_1 ] ) ;
V_64 -> error = 1 ;
return;
}
} while( ( V_3 < V_86 ) && ( V_3 != 0 ) );
if ( V_3 < V_86 ) memset ( & V_84 [ V_3 ] , 0 , V_86 - V_3 ) ;
} else {
V_3 = F_121 ( V_64 -> V_172 [ V_1 ] , V_84 , V_86 , V_5 ) ;
if( V_3 != V_86 ) {
F_18 ( L_73
L_71 , - V_3 , V_64 -> V_172 [ V_1 ] ) ;
V_64 -> error = 1 ;
return;
}
}
V_208 = V_23 ;
} while( V_208 < V_207 );
V_64 -> error = V_163 ( V_64 ) ;
}
int F_124 ( void * V_192 )
{
int V_3 , V_56 , V_209 , V_210 ;
F_125 () ;
while( 1 ) {
V_3 = F_23 (
V_211 ,
V_149 ,
& V_150 ,
& V_212 ,
V_61
) ;
if ( V_3 < 0 ) {
if ( V_3 == - V_62 ) {
F_126 ( - 1 ) ;
continue;
} else {
F_18 ( L_74
L_75
L_76 ,
V_211 , - V_3 , V_212 ) ;
}
}
for ( V_56 = 0 ; V_56 < V_3 / sizeof( struct V_63 * ) ; V_56 ++ ) {
V_213 ++ ;
F_122 ( ( * V_149 ) [ V_56 ] ) ;
}
V_209 = 0 ;
do {
V_210 = F_109 ( V_211 , ( ( char * ) V_149 ) + V_209 , V_3 ) ;
if ( V_210 > 0 ) {
V_209 += V_210 ;
} else {
if ( V_210 != - V_62 ) {
F_18 ( L_74
L_24 , V_211 , - V_3 ) ;
}
}
if ( V_209 < V_3 ) {
F_127 ( - 1 ) ;
}
} while ( V_209 < V_3 );
}
return 0 ;
}
