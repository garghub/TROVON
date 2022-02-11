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
0 ,
( * V_58 ) [ V_56 ] -> V_65
) ;
F_25 ( ( * V_58 ) [ V_56 ] ) ;
}
}
F_26 ( V_57 , V_66 ) ;
F_27 (list, next_ele, &restart) {
V_26 = F_28 ( V_54 , struct V_26 , V_67 ) ;
F_29 ( & V_26 -> V_67 ) ;
F_30 ( & V_26 -> V_68 , V_29 ) ;
F_31 ( V_26 -> V_69 ) ;
F_32 ( & V_26 -> V_68 , V_29 ) ;
}
}
static T_2 F_33 ( int V_70 , void * V_71 )
{
F_22 () ;
return V_72 ;
}
static void F_34 ( void )
{
if( V_73 != - 1 )
F_35 ( V_73 , 1 ) ;
}
static inline int F_36 ( struct V_26 * V_27 , T_1 * V_74 )
{
char * V_12 ;
int V_75 ;
int V_32 ;
T_3 V_76 ;
T_3 V_77 ;
char * V_31 ;
T_4 V_78 ;
unsigned long long V_79 ;
int V_80 ;
int V_81 ;
if ( V_27 -> V_12 && V_27 -> V_50 . V_12 ) {
V_12 = V_27 -> V_50 . V_12 ;
goto V_44;
}
V_75 = F_37 ( V_27 -> V_12 , F_38 ( F_39 () ) , 0 ) ;
if ( V_75 < 0 )
return V_75 ;
V_32 = F_40 ( V_82 , & V_75 , & V_76 , & V_31 , \
& V_78 , & V_79 , & V_80 , & V_77 , & V_81 ) ;
F_41 ( V_75 ) ;
if( V_32 == - V_36 )
V_12 = V_27 -> V_12 ;
else
V_12 = V_31 ;
V_44:
return F_42 ( V_12 , V_74 ) ;
}
static int F_43 ( int V_75 , void * V_83 , int V_84 , int V_85 )
{
int V_32 ;
V_32 = F_44 ( V_75 , V_83 , V_85 , V_84 ) ;
if ( V_32 < 0 )
return V_32 ;
return 0 ;
}
static int F_45 ( char * V_12 , T_1 V_79 , T_4 V_78 )
{
unsigned long V_86 ;
unsigned long long V_87 ;
int V_32 ;
V_32 = F_46 ( V_12 , & V_86 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_25
L_26 , V_12 , - V_32 ) ;
return V_32 ;
}
V_32 = F_42 ( V_12 , & V_87 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_27
L_24 , V_12 , - V_32 ) ;
return V_32 ;
}
if ( V_87 != V_79 ) {
F_18 ( V_52 L_28
L_29 , ( unsigned long long ) V_79 , V_87 ) ;
return - V_36 ;
}
if ( V_86 != V_78 ) {
F_18 ( V_52 L_30
L_31 , V_78 , V_86 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_47 ( char * V_88 , char * V_89 , char * V_50 )
{
struct V_90 V_91 , V_92 ;
int V_32 ;
if ( V_88 == NULL )
return 0 ;
if ( ! strcmp ( V_88 , V_89 ) )
return 0 ;
V_32 = F_48 ( V_88 , & V_91 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_32 , V_88 ,
- V_32 ) ;
return 0 ;
}
V_32 = F_48 ( V_89 , & V_92 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_32 , V_89 ,
- V_32 ) ;
return 1 ;
}
if ( ( V_91 . V_93 == V_92 . V_93 ) && ( V_91 . V_94 == V_92 . V_94 ) )
return 0 ;
F_18 ( V_52 L_33
L_34 ,
V_88 , V_89 , V_50 ) ;
return 1 ;
}
static int F_49 ( char * V_12 , struct V_28 * V_28 , int V_48 ,
char * * V_95 , int * V_96 ,
unsigned long * V_97 , int * V_98 ,
int * V_99 )
{
T_4 V_78 ;
unsigned long long V_79 ;
T_3 V_76 , V_77 ;
char * V_31 ;
int V_75 , V_32 , V_100 , V_101 , V_102 = 0644 ;
V_75 = F_37 ( V_12 , * V_28 , V_102 ) ;
if ( V_75 < 0 ) {
if ( ( V_75 == - V_103 ) && ( V_99 != NULL ) )
* V_99 = 1 ;
if ( ! V_28 -> V_45 ||
( ( V_75 != - V_104 ) && ( V_75 != - V_105 ) ) )
return V_75 ;
V_28 -> V_45 = 0 ;
V_75 = F_37 ( V_12 , * V_28 , V_102 ) ;
if ( V_75 < 0 )
return V_75 ;
}
if ( V_48 )
F_18 ( V_40 L_35 , V_12 ) ;
else {
V_32 = F_50 ( V_75 , V_28 -> V_45 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_36 ,
V_12 , - V_32 ) ;
goto V_106;
}
}
if ( V_95 == NULL )
return V_75 ;
V_32 = F_40 ( V_82 , & V_75 , & V_76 , & V_31 , & V_78 ,
& V_79 , & V_100 , & V_77 , V_96 ) ;
if ( V_32 && ( * V_95 != NULL ) ) {
F_18 ( V_52 L_37
L_38 , V_12 , - V_32 ) ;
goto V_106;
}
if ( V_32 )
return V_75 ;
V_101 = F_47 ( * V_95 , V_31 ,
V_12 ) ;
if ( V_101 && ! F_45 ( * V_95 , V_79 ,
V_78 ) ) {
F_18 ( V_52 L_39 ,
* V_95 ) ;
V_32 = F_51 ( V_12 , V_75 , * V_95 ,
V_100 , V_77 , & V_79 ) ;
if ( V_32 ) {
F_18 ( V_52 L_40 , - V_32 ) ;
goto V_106;
}
} else {
* V_95 = V_31 ;
V_32 = F_45 ( * V_95 , V_79 , V_78 ) ;
if ( V_32 )
goto V_106;
}
F_52 ( V_76 , V_79 , V_100 , V_77 , * V_96 ,
V_97 , V_98 ) ;
return V_75 ;
V_106:
F_41 ( V_75 ) ;
return V_32 ;
}
static int F_53 ( char * V_107 , char * V_31 ,
struct V_28 V_29 ,
int V_100 , int V_108 , int * V_96 ,
unsigned long * V_97 , int * V_98 )
{
int V_32 , V_75 ;
V_29 . V_109 = 1 ;
V_75 = F_49 ( V_107 , & V_29 , 0 , NULL , NULL , NULL , NULL , NULL ) ;
if ( V_75 < 0 ) {
V_32 = V_75 ;
F_18 ( V_52 L_41 ,
V_107 , - V_32 ) ;
goto V_44;
}
V_32 = F_54 ( V_75 , V_107 , V_31 , V_100 , V_108 ,
V_96 , V_97 ,
V_98 ) ;
if ( ! V_32 )
return V_75 ;
F_41 ( V_75 ) ;
V_44:
return V_32 ;
}
static void F_55 ( struct V_26 * V_27 )
{
F_41 ( V_27 -> V_75 ) ;
if( V_27 -> V_50 . V_12 == NULL )
return;
F_41 ( V_27 -> V_50 . V_75 ) ;
F_56 ( V_27 -> V_50 . V_110 ) ;
V_27 -> V_50 . V_110 = NULL ;
}
static int F_57 ( struct V_26 * V_27 )
{
struct V_28 V_29 ;
char * * V_111 ;
int V_32 , V_112 , * V_113 ;
int V_75 ;
V_27 -> V_28 = V_27 -> V_51 ;
V_112 = 0 ;
V_113 = ( V_27 -> V_50 . V_12 != NULL ) ? & V_112 : NULL ;
V_111 = V_27 -> V_47 ? NULL : & V_27 -> V_50 . V_12 ;
V_75 = F_49 ( V_27 -> V_12 , & V_27 -> V_28 , V_27 -> V_48 ,
V_111 , & V_27 -> V_50 . V_81 ,
& V_27 -> V_50 . V_114 , & V_27 -> V_50 . V_115 ,
V_113 ) ;
if( ( V_75 == - V_103 ) && V_112 ) {
V_75 = F_53 ( V_27 -> V_12 , V_27 -> V_50 . V_12 ,
V_27 -> V_28 , 1 << 9 , V_116 ,
& V_27 -> V_50 . V_81 ,
& V_27 -> V_50 . V_114 ,
& V_27 -> V_50 . V_115 ) ;
if( V_75 >= 0 ) {
F_18 ( V_40 L_42
L_43 , V_27 -> V_12 , V_27 -> V_50 . V_12 ) ;
}
}
if( V_75 < 0 ) {
F_18 ( L_44 , V_27 -> V_12 ,
- V_75 ) ;
return V_75 ;
}
V_27 -> V_75 = V_75 ;
if( V_27 -> V_50 . V_12 != NULL ) {
F_58 ( V_27 -> V_69 , 8 * sizeof( long ) ) ;
V_32 = - V_117 ;
V_27 -> V_50 . V_110 = F_59 ( V_27 -> V_50 . V_114 ) ;
if( V_27 -> V_50 . V_110 == NULL ) {
F_18 ( V_52 L_45 ) ;
goto error;
}
F_60 () ;
V_32 = F_43 ( V_27 -> V_75 , V_27 -> V_50 . V_110 ,
V_27 -> V_50 . V_81 ,
V_27 -> V_50 . V_114 ) ;
if( V_32 < 0 )
goto error;
V_29 = V_27 -> V_28 ;
V_29 . V_45 = 0 ;
V_32 = F_49 ( V_27 -> V_50 . V_12 , & V_29 , V_27 -> V_48 , NULL ,
NULL , NULL , NULL , NULL ) ;
if( V_32 < 0 ) goto error;
V_27 -> V_50 . V_75 = V_32 ;
}
return 0 ;
error:
F_41 ( V_27 -> V_75 ) ;
return V_32 ;
}
static void F_61 ( struct V_118 * V_71 )
{
struct V_26 * V_27 = F_62 ( V_71 ) ;
F_63 ( V_27 -> V_69 ) ;
* V_27 = ( (struct V_26 ) V_119 ) ;
}
static int F_64 ( int V_34 , T_5 V_79 , int V_120 ,
struct V_121 * * V_122 )
{
struct V_118 * V_123 = NULL ;
struct V_121 * V_124 ;
V_124 = F_65 ( 1 << V_125 ) ;
if( V_124 == NULL )
return - V_117 ;
V_124 -> V_34 = V_34 ;
V_124 -> V_126 = V_120 << V_125 ;
V_124 -> V_127 = & V_128 ;
F_66 ( V_124 , V_79 / 512 ) ;
if ( V_34 == V_39 )
sprintf ( V_124 -> V_129 , L_46 , 'a' + V_120 ) ;
else
sprintf ( V_124 -> V_129 , L_47 , V_120 ) ;
if ( V_34 == V_39 ) {
V_43 [ V_120 ] . V_130 . V_131 = V_120 ;
V_43 [ V_120 ] . V_130 . V_17 = V_132 ;
V_43 [ V_120 ] . V_130 . V_71 . V_133 = F_61 ;
F_67 ( & V_43 [ V_120 ] . V_130 . V_71 , & V_43 [ V_120 ] ) ;
F_68 ( & V_43 [ V_120 ] . V_130 ) ;
V_123 = & V_43 [ V_120 ] . V_130 . V_71 ;
}
V_124 -> V_134 = & V_43 [ V_120 ] ;
V_124 -> V_69 = V_43 [ V_120 ] . V_69 ;
F_69 ( V_123 , V_124 ) ;
* V_122 = V_124 ;
return 0 ;
}
static int F_70 ( int V_3 , char * * V_25 )
{
struct V_26 * V_27 = & V_43 [ V_3 ] ;
int V_32 = 0 ;
if( V_27 -> V_12 == NULL )
goto V_44;
V_32 = F_36 ( V_27 , & V_27 -> V_79 ) ;
if( V_32 < 0 ) {
* V_25 = L_48 ;
goto V_44;
}
V_27 -> V_79 = F_71 ( V_27 -> V_79 ) ;
F_72 ( & V_27 -> V_67 ) ;
F_73 ( V_27 -> V_135 , V_136 ) ;
V_32 = - V_117 ;
V_27 -> V_69 = F_74 ( F_31 , & V_27 -> V_68 ) ;
if ( V_27 -> V_69 == NULL ) {
* V_25 = L_49 ;
goto V_44;
}
V_27 -> V_69 -> V_137 = V_27 ;
F_75 ( V_27 -> V_69 , true , false ) ;
F_76 ( V_27 -> V_69 , V_136 ) ;
V_32 = F_64 ( V_39 , V_27 -> V_79 , V_3 , & V_138 [ V_3 ] ) ;
if( V_32 ) {
* V_25 = L_50 ;
goto V_139;
}
if ( V_38 != V_39 )
F_64 ( V_38 , V_27 -> V_79 , V_3 ,
& V_140 [ V_3 ] ) ;
if ( V_21 )
F_9 ( V_138 [ V_3 ] -> V_129 ) ;
V_32 = 0 ;
V_44:
return V_32 ;
V_139:
F_63 ( V_27 -> V_69 ) ;
goto V_44;
}
static int F_77 ( char * V_20 , char * * V_25 )
{
int V_3 , V_141 ;
V_20 = F_78 ( V_20 , V_142 ) ;
if ( V_20 == NULL ) {
* V_25 = L_51 ;
return - V_117 ;
}
V_141 = F_15 ( V_20 , & V_3 , V_25 ) ;
if ( V_141 )
goto V_143;
if ( V_3 == - 1 ) {
V_141 = 0 ;
goto V_143;
}
F_17 ( & V_37 ) ;
V_141 = F_70 ( V_3 , V_25 ) ;
if ( V_141 )
V_43 [ V_3 ] . V_12 = NULL ;
F_19 ( & V_37 ) ;
V_44:
return V_141 ;
V_143:
F_25 ( V_20 ) ;
goto V_44;
}
static int F_79 ( char * V_17 , char * V_20 , int V_79 , char * * V_25 )
{
struct V_26 * V_27 ;
int V_3 , V_85 = 0 ;
V_3 = F_13 ( & V_17 ) ;
if( ( V_3 >= V_41 ) || ( V_3 < 0 ) ) {
* V_25 = L_52 ;
return - 1 ;
}
V_27 = & V_43 [ V_3 ] ;
F_17 ( & V_37 ) ;
if( V_27 -> V_12 == NULL ) {
F_80 ( V_20 , V_79 , V_85 , L_53 , 1 ) ;
goto V_44;
}
F_80 ( V_20 , V_79 , V_85 , V_27 -> V_12 , 0 ) ;
if( V_27 -> V_50 . V_12 != NULL ) {
F_80 ( V_20 , V_79 , V_85 , L_54 , 0 ) ;
F_80 ( V_20 , V_79 , V_85 , V_27 -> V_50 . V_12 , 1 ) ;
}
else F_80 ( V_20 , V_79 , V_85 , L_53 , 1 ) ;
V_44:
F_19 ( & V_37 ) ;
return V_85 ;
}
static int F_81 ( char * * V_20 , int * V_144 , int * V_145 )
{
int V_3 ;
V_3 = F_13 ( V_20 ) ;
* V_144 = 0 ;
* V_145 = V_41 - 1 ;
return V_3 ;
}
static int F_82 ( int V_3 , char * * V_25 )
{
struct V_121 * V_124 = V_138 [ V_3 ] ;
struct V_26 * V_27 ;
int V_32 = - V_146 ;
F_17 ( & V_37 ) ;
V_27 = & V_43 [ V_3 ] ;
if( V_27 -> V_12 == NULL )
goto V_44;
V_32 = - V_42 ;
if( V_27 -> V_56 > 0 )
goto V_44;
V_138 [ V_3 ] = NULL ;
if( V_124 != NULL ) {
F_83 ( V_124 ) ;
F_84 ( V_124 ) ;
}
if( V_140 [ V_3 ] != NULL ) {
F_83 ( V_140 [ V_3 ] ) ;
F_84 ( V_140 [ V_3 ] ) ;
V_140 [ V_3 ] = NULL ;
}
V_32 = 0 ;
F_85 ( & V_27 -> V_130 ) ;
V_44:
F_19 ( & V_37 ) ;
return V_32 ;
}
static int T_6 F_86 ( void )
{
F_87 ( & V_147 ) ;
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
V_142
) ;
V_59 = 0 ;
if ( V_58 == NULL ) {
F_18 ( V_52 L_59 ) ;
return - 1 ;
}
V_148 = F_91 (
sizeof( struct V_63 * ) * V_61 ,
V_142
) ;
V_149 = 0 ;
if ( V_148 == NULL ) {
F_18 ( V_52 L_59 ) ;
return - 1 ;
}
F_92 ( & V_150 ) ;
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
unsigned long V_151 ;
int V_32 ;
if( V_30 . V_46 ) {
F_18 ( V_40 L_61 ) ;
}
V_151 = F_94 ( 0 , 0 ) ;
V_73 = F_95 ( V_151 + V_116 - sizeof( void * ) ,
& V_57 ) ;
if( V_73 < 0 ) {
F_18 ( V_52
L_62
L_63 , - V_73 ) ;
V_73 = - 1 ;
return 0 ;
}
V_32 = F_96 ( V_66 , V_57 , V_152 , F_33 ,
0 , L_56 , V_43 ) ;
if( V_32 != 0 )
F_18 ( V_52 L_64 , - V_32 ) ;
return 0 ;
}
static int F_97 ( struct V_153 * V_154 , T_7 V_102 )
{
struct V_121 * V_124 = V_154 -> V_155 ;
struct V_26 * V_27 = V_124 -> V_134 ;
int V_32 = 0 ;
F_17 ( & V_156 ) ;
if( V_27 -> V_56 == 0 ) {
V_32 = F_57 ( V_27 ) ;
if( V_32 ) {
F_18 ( V_52 L_65 ,
V_124 -> V_129 , V_27 -> V_12 , - V_32 ) ;
goto V_44;
}
}
V_27 -> V_56 ++ ;
F_98 ( V_124 , ! V_27 -> V_28 . V_45 ) ;
V_44:
F_19 ( & V_156 ) ;
return V_32 ;
}
static void F_99 ( struct V_121 * V_124 , T_7 V_102 )
{
struct V_26 * V_27 = V_124 -> V_134 ;
F_17 ( & V_156 ) ;
if( -- V_27 -> V_56 == 0 )
F_55 ( V_27 ) ;
F_19 ( & V_156 ) ;
}
static void F_100 ( T_1 V_157 , int V_65 , unsigned long * V_158 ,
T_1 * V_159 , unsigned long * V_110 ,
T_1 V_81 , unsigned long * V_160 ,
T_1 V_114 )
{
T_1 V_161 = V_157 >> 9 ;
int V_33 , V_162 = 0 ;
for( V_33 = 0 ; V_33 < V_65 > > 9 ; V_33 ++ ) {
if( V_158 != NULL )
F_2 ( V_33 , ( unsigned char * ) V_158 ) ;
if( F_1 ( V_161 + V_33 , ( unsigned char * ) V_110 ) )
continue;
V_162 = 1 ;
F_2 ( V_161 + V_33 , ( unsigned char * ) V_110 ) ;
}
if( ! V_162 )
return;
* V_159 = V_161 / (sizeof( unsigned long ) * 8 ) ;
if ( * V_159 == ( F_101 ( V_114 ,
sizeof( unsigned long ) ) - 1 ) )
( * V_159 ) -- ;
V_160 [ 0 ] = V_110 [ * V_159 ] ;
V_160 [ 1 ] = V_110 [ * V_159 + 1 ] ;
* V_159 *= sizeof( unsigned long ) ;
* V_159 += V_81 ;
}
static void F_102 ( struct V_63 * V_64 , unsigned long * V_110 ,
T_1 V_81 , T_1 V_114 )
{
T_1 V_161 = V_64 -> V_84 >> 9 ;
int V_33 ;
if( V_64 -> V_65 > ( sizeof( V_64 -> V_163 ) * 8 ) << 9 )
F_103 ( L_66 ) ;
if( V_64 -> V_164 == V_165 ) {
for( V_33 = 0 ; V_33 < V_64 -> V_65 > > 9 ; V_33 ++ ) {
if( F_1 ( V_161 + V_33 , ( unsigned char * ) V_110 ) )
F_2 ( V_33 , ( unsigned char * )
& V_64 -> V_163 ) ;
}
}
else F_100 ( V_64 -> V_84 , V_64 -> V_65 , & V_64 -> V_163 ,
& V_64 -> V_159 , V_110 , V_81 ,
V_64 -> V_160 , V_114 ) ;
}
static void F_104 ( struct V_166 * V_64 , struct V_63 * V_167 ,
unsigned long long V_84 , int V_168 ,
int V_85 , struct V_169 * V_169 )
{
struct V_121 * V_124 = V_64 -> V_170 ;
struct V_26 * V_27 = V_124 -> V_134 ;
V_167 -> V_64 = V_64 ;
V_167 -> V_171 [ 0 ] = ( V_27 -> V_50 . V_12 != NULL ) ? V_27 -> V_50 . V_75 :
V_27 -> V_75 ;
V_167 -> V_171 [ 1 ] = V_27 -> V_75 ;
V_167 -> V_159 = - 1 ;
V_167 -> V_84 = V_84 ;
V_167 -> V_65 = V_85 ;
V_167 -> error = 0 ;
V_167 -> V_163 = 0 ;
V_167 -> V_164 = ( F_105 ( V_64 ) == V_172 ) ? V_165 : V_173 ;
V_167 -> V_174 [ 0 ] = 0 ;
V_167 -> V_174 [ 1 ] = V_27 -> V_50 . V_115 ;
V_167 -> V_175 = F_106 ( V_169 ) + V_168 ;
V_167 -> V_100 = 1 << 9 ;
if( V_27 -> V_50 . V_12 != NULL )
F_102 ( V_167 , V_27 -> V_50 . V_110 ,
V_27 -> V_50 . V_81 , V_27 -> V_50 . V_114 ) ;
}
static void F_107 ( struct V_166 * V_64 ,
struct V_63 * V_167 )
{
struct V_121 * V_124 = V_64 -> V_170 ;
struct V_26 * V_27 = V_124 -> V_134 ;
V_167 -> V_64 = V_64 ;
V_167 -> V_171 [ 0 ] = ( V_27 -> V_50 . V_12 != NULL ) ? V_27 -> V_50 . V_75 :
V_27 -> V_75 ;
V_167 -> V_164 = V_176 ;
}
static bool F_108 ( struct V_63 * V_167 , struct V_26 * V_71 )
{
int V_3 = F_109 ( V_57 , & V_167 ,
sizeof( V_167 ) ) ;
if ( V_3 != sizeof( V_167 ) ) {
if ( V_3 != - V_62 )
F_18 ( L_67
L_68 , - V_3 ) ;
else if ( F_110 ( & V_71 -> V_67 ) )
F_111 ( & V_71 -> V_67 , & V_67 ) ;
F_25 ( V_167 ) ;
return false ;
}
return true ;
}
static void F_31 ( struct V_177 * V_178 )
{
struct V_63 * V_167 ;
struct V_166 * V_64 ;
while( 1 ) {
struct V_26 * V_71 = V_178 -> V_137 ;
if( V_71 -> V_166 == NULL ) {
struct V_166 * V_64 = F_112 ( V_178 ) ;
if( V_64 == NULL )
return;
V_71 -> V_166 = V_64 ;
V_71 -> V_179 = F_113 ( V_64 ) ;
V_71 -> V_180 = 0 ;
V_71 -> V_181 = F_114 ( V_178 , V_64 , V_71 -> V_135 ) ;
}
V_64 = V_71 -> V_166 ;
if ( F_115 ( V_64 ) == V_182 ) {
V_167 = F_91 ( sizeof( struct V_63 ) ,
V_183 ) ;
if ( V_167 == NULL ) {
if ( F_110 ( & V_71 -> V_67 ) )
F_111 ( & V_71 -> V_67 , & V_67 ) ;
return;
}
F_107 ( V_64 , V_167 ) ;
if ( F_108 ( V_167 , V_71 ) == false )
return;
}
while( V_71 -> V_180 < V_71 -> V_181 ) {
struct V_184 * V_135 = & V_71 -> V_135 [ V_71 -> V_180 ] ;
V_167 = F_91 ( sizeof( struct V_63 ) ,
V_183 ) ;
if( V_167 == NULL ) {
if( F_110 ( & V_71 -> V_67 ) )
F_111 ( & V_71 -> V_67 , & V_67 ) ;
return;
}
F_104 ( V_64 , V_167 ,
( unsigned long long ) V_71 -> V_179 << 9 ,
V_135 -> V_84 , V_135 -> V_65 , F_116 ( V_135 ) ) ;
if ( F_108 ( V_167 , V_71 ) == false )
return;
V_71 -> V_179 += V_135 -> V_65 >> 9 ;
V_71 -> V_180 ++ ;
}
V_71 -> V_181 = 0 ;
V_71 -> V_166 = NULL ;
}
}
static int F_117 ( struct V_153 * V_154 , struct V_185 * V_186 )
{
struct V_26 * V_27 = V_154 -> V_155 -> V_134 ;
V_186 -> V_187 = 128 ;
V_186 -> V_188 = 32 ;
V_186 -> V_189 = V_27 -> V_79 / ( 128 * 32 * 512 ) ;
return 0 ;
}
static int F_118 ( struct V_153 * V_154 , T_7 V_102 ,
unsigned int V_190 , unsigned long V_191 )
{
struct V_26 * V_27 = V_154 -> V_155 -> V_134 ;
T_8 F_81 [ V_192 ] ;
switch ( V_190 ) {
struct V_193 V_194 ;
case V_195 :
memset ( & F_81 , 0 , V_192 * 2 ) ;
F_81 [ V_196 ] = V_27 -> V_79 / ( 128 * 32 * 512 ) ;
F_81 [ V_197 ] = 128 ;
F_81 [ V_198 ] = 32 ;
if( F_119 ( ( char V_199 * ) V_191 , ( char * ) & F_81 ,
sizeof( F_81 ) ) )
return - V_200 ;
return 0 ;
case V_201 :
if( F_120 ( & V_194 , ( char V_199 * ) V_191 , sizeof( V_194 ) ) )
return - V_200 ;
V_194 . V_202 = 255 ;
V_194 . V_203 = 255 ;
V_194 . V_204 = 255 ;
V_194 . V_205 = 255 ;
if( F_119 ( ( char V_199 * ) V_191 , & V_194 , sizeof( V_194 ) ) )
return - V_200 ;
return 0 ;
}
return - V_36 ;
}
static int V_162 ( struct V_63 * V_64 )
{
int V_3 ;
if( V_64 -> V_159 == - 1 )
return 0 ;
V_3 = F_121 ( V_64 -> V_171 [ 1 ] , & V_64 -> V_160 ,
sizeof( V_64 -> V_160 ) , V_64 -> V_159 ) ;
if( V_3 != sizeof( V_64 -> V_160 ) ) {
F_18 ( L_69 , - V_3 ,
V_64 -> V_171 [ 1 ] ) ;
return 1 ;
}
return 0 ;
}
static void F_122 ( struct V_63 * V_64 )
{
char * V_83 ;
unsigned long V_85 ;
int V_3 , V_206 , V_207 , V_23 , V_1 ;
T_1 V_5 ;
if ( V_64 -> V_164 == V_176 ) {
V_3 = F_123 ( V_64 -> V_171 [ 0 ] ) ;
if ( V_3 != 0 ) {
F_18 ( L_70
L_71 , - V_3 , V_64 -> V_171 [ 0 ] ) ;
V_64 -> error = 1 ;
}
return;
}
V_206 = V_64 -> V_65 / V_64 -> V_100 ;
V_207 = 0 ;
do {
V_1 = F_1 ( V_207 , ( unsigned char * ) & V_64 -> V_163 ) ;
V_23 = V_207 ;
while( ( V_23 < V_206 ) &&
( F_1 ( V_23 , ( unsigned char * )
& V_64 -> V_163 ) == V_1 ) )
V_23 ++ ;
V_5 = V_64 -> V_84 + V_64 -> V_174 [ V_1 ] +
V_207 * V_64 -> V_100 ;
V_85 = ( V_23 - V_207 ) * V_64 -> V_100 ;
V_83 = & V_64 -> V_175 [ V_207 * V_64 -> V_100 ] ;
if( V_64 -> V_164 == V_165 ) {
V_3 = 0 ;
do {
V_83 = & V_83 [ V_3 ] ;
V_85 -= V_3 ;
V_3 = F_44 ( V_64 -> V_171 [ V_1 ] , V_83 , V_85 , V_5 ) ;
if ( V_3 < 0 ) {
F_18 ( L_72
L_71 , - V_3 , V_64 -> V_171 [ V_1 ] ) ;
V_64 -> error = 1 ;
return;
}
} while( ( V_3 < V_85 ) && ( V_3 != 0 ) );
if ( V_3 < V_85 ) memset ( & V_83 [ V_3 ] , 0 , V_85 - V_3 ) ;
} else {
V_3 = F_121 ( V_64 -> V_171 [ V_1 ] , V_83 , V_85 , V_5 ) ;
if( V_3 != V_85 ) {
F_18 ( L_73
L_71 , - V_3 , V_64 -> V_171 [ V_1 ] ) ;
V_64 -> error = 1 ;
return;
}
}
V_207 = V_23 ;
} while( V_207 < V_206 );
V_64 -> error = V_162 ( V_64 ) ;
}
int F_124 ( void * V_191 )
{
int V_3 , V_56 , V_208 , V_209 ;
F_125 () ;
while( 1 ) {
V_3 = F_23 (
V_210 ,
V_148 ,
& V_149 ,
& V_211 ,
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
V_210 , - V_3 , V_211 ) ;
}
}
for ( V_56 = 0 ; V_56 < V_3 / sizeof( struct V_63 * ) ; V_56 ++ ) {
V_212 ++ ;
F_122 ( ( * V_148 ) [ V_56 ] ) ;
}
V_208 = 0 ;
do {
V_209 = F_109 ( V_210 , ( ( char * ) V_148 ) + V_208 , V_3 ) ;
if ( V_209 > 0 ) {
V_208 += V_209 ;
} else {
if ( V_209 != - V_62 ) {
F_18 ( L_74
L_24 , V_210 , - V_3 ) ;
}
}
if ( V_208 < V_3 ) {
F_127 ( - 1 ) ;
}
} while ( V_208 < V_3 );
}
return 0 ;
}
