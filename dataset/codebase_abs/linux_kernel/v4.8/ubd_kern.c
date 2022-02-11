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
struct V_53 * V_54 ;
struct V_26 * V_26 ;
struct V_55 * V_56 , * V_57 ;
unsigned long V_29 ;
int V_3 ;
while( 1 ) {
V_3 = F_23 ( V_58 , & V_54 ,
sizeof( struct V_53 * ) ) ;
if( V_3 != sizeof( V_54 ) ) {
if( V_3 == - V_59 )
break;
F_18 ( V_52 L_23
L_24 , - V_3 ) ;
return;
}
F_24 ( V_54 -> V_54 , 0 , V_54 -> V_60 ) ;
F_25 ( V_54 ) ;
}
F_26 ( V_58 , V_61 ) ;
F_27 (list, next_ele, &restart) {
V_26 = F_28 ( V_56 , struct V_26 , V_62 ) ;
F_29 ( & V_26 -> V_62 ) ;
F_30 ( & V_26 -> V_63 , V_29 ) ;
F_31 ( V_26 -> V_64 ) ;
F_32 ( & V_26 -> V_63 , V_29 ) ;
}
}
static T_2 F_33 ( int V_65 , void * V_66 )
{
F_22 () ;
return V_67 ;
}
static void F_34 ( void )
{
if( V_68 != - 1 )
F_35 ( V_68 , 1 ) ;
}
static inline int F_36 ( struct V_26 * V_27 , T_1 * V_69 )
{
char * V_12 ;
int V_70 ;
int V_32 ;
T_3 V_71 ;
T_3 V_72 ;
char * V_31 ;
T_4 V_73 ;
unsigned long long V_74 ;
int V_75 ;
int V_76 ;
if ( V_27 -> V_12 && V_27 -> V_50 . V_12 ) {
V_12 = V_27 -> V_50 . V_12 ;
goto V_44;
}
V_70 = F_37 ( V_27 -> V_12 , F_38 ( F_39 () ) , 0 ) ;
if ( V_70 < 0 )
return V_70 ;
V_32 = F_40 ( V_77 , & V_70 , & V_71 , & V_31 , \
& V_73 , & V_74 , & V_75 , & V_72 , & V_76 ) ;
F_41 ( V_70 ) ;
if( V_32 == - V_36 )
V_12 = V_27 -> V_12 ;
else
V_12 = V_31 ;
V_44:
return F_42 ( V_12 , V_69 ) ;
}
static int F_43 ( int V_70 , void * V_78 , int V_79 , int V_80 )
{
int V_32 ;
V_32 = F_44 ( V_70 , V_78 , V_80 , V_79 ) ;
if ( V_32 < 0 )
return V_32 ;
return 0 ;
}
static int F_45 ( char * V_12 , T_1 V_74 , T_4 V_73 )
{
unsigned long V_81 ;
unsigned long long V_82 ;
int V_32 ;
V_32 = F_46 ( V_12 , & V_81 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_25
L_26 , V_12 , - V_32 ) ;
return V_32 ;
}
V_32 = F_42 ( V_12 , & V_82 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_27
L_24 , V_12 , - V_32 ) ;
return V_32 ;
}
if ( V_82 != V_74 ) {
F_18 ( V_52 L_28
L_29 , ( unsigned long long ) V_74 , V_82 ) ;
return - V_36 ;
}
if ( V_81 != V_73 ) {
F_18 ( V_52 L_30
L_31 , V_73 , V_81 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_47 ( char * V_83 , char * V_84 , char * V_50 )
{
struct V_85 V_86 , V_87 ;
int V_32 ;
if ( V_83 == NULL )
return 0 ;
if ( ! strcmp ( V_83 , V_84 ) )
return 0 ;
V_32 = F_48 ( V_83 , & V_86 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_32 , V_83 ,
- V_32 ) ;
return 0 ;
}
V_32 = F_48 ( V_84 , & V_87 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_32 , V_84 ,
- V_32 ) ;
return 1 ;
}
if ( ( V_86 . V_88 == V_87 . V_88 ) && ( V_86 . V_89 == V_87 . V_89 ) )
return 0 ;
F_18 ( V_52 L_33
L_34 ,
V_83 , V_84 , V_50 ) ;
return 1 ;
}
static int F_49 ( char * V_12 , struct V_28 * V_28 , int V_48 ,
char * * V_90 , int * V_91 ,
unsigned long * V_92 , int * V_93 ,
int * V_94 )
{
T_4 V_73 ;
unsigned long long V_74 ;
T_3 V_71 , V_72 ;
char * V_31 ;
int V_70 , V_32 , V_95 , V_96 , V_97 = 0644 ;
V_70 = F_37 ( V_12 , * V_28 , V_97 ) ;
if ( V_70 < 0 ) {
if ( ( V_70 == - V_98 ) && ( V_94 != NULL ) )
* V_94 = 1 ;
if ( ! V_28 -> V_45 ||
( ( V_70 != - V_99 ) && ( V_70 != - V_100 ) ) )
return V_70 ;
V_28 -> V_45 = 0 ;
V_70 = F_37 ( V_12 , * V_28 , V_97 ) ;
if ( V_70 < 0 )
return V_70 ;
}
if ( V_48 )
F_18 ( V_40 L_35 , V_12 ) ;
else {
V_32 = F_50 ( V_70 , V_28 -> V_45 ) ;
if ( V_32 < 0 ) {
F_18 ( V_52 L_36 ,
V_12 , - V_32 ) ;
goto V_101;
}
}
if ( V_90 == NULL )
return V_70 ;
V_32 = F_40 ( V_77 , & V_70 , & V_71 , & V_31 , & V_73 ,
& V_74 , & V_95 , & V_72 , V_91 ) ;
if ( V_32 && ( * V_90 != NULL ) ) {
F_18 ( V_52 L_37
L_38 , V_12 , - V_32 ) ;
goto V_101;
}
if ( V_32 )
return V_70 ;
V_96 = F_47 ( * V_90 , V_31 ,
V_12 ) ;
if ( V_96 && ! F_45 ( * V_90 , V_74 ,
V_73 ) ) {
F_18 ( V_52 L_39 ,
* V_90 ) ;
V_32 = F_51 ( V_12 , V_70 , * V_90 ,
V_95 , V_72 , & V_74 ) ;
if ( V_32 ) {
F_18 ( V_52 L_40 , - V_32 ) ;
goto V_101;
}
} else {
* V_90 = V_31 ;
V_32 = F_45 ( * V_90 , V_74 , V_73 ) ;
if ( V_32 )
goto V_101;
}
F_52 ( V_71 , V_74 , V_95 , V_72 , * V_91 ,
V_92 , V_93 ) ;
return V_70 ;
V_101:
F_41 ( V_70 ) ;
return V_32 ;
}
static int F_53 ( char * V_102 , char * V_31 ,
struct V_28 V_29 ,
int V_95 , int V_103 , int * V_91 ,
unsigned long * V_92 , int * V_93 )
{
int V_32 , V_70 ;
V_29 . V_104 = 1 ;
V_70 = F_49 ( V_102 , & V_29 , 0 , NULL , NULL , NULL , NULL , NULL ) ;
if ( V_70 < 0 ) {
V_32 = V_70 ;
F_18 ( V_52 L_41 ,
V_102 , - V_32 ) ;
goto V_44;
}
V_32 = F_54 ( V_70 , V_102 , V_31 , V_95 , V_103 ,
V_91 , V_92 ,
V_93 ) ;
if ( ! V_32 )
return V_70 ;
F_41 ( V_70 ) ;
V_44:
return V_32 ;
}
static void F_55 ( struct V_26 * V_27 )
{
F_41 ( V_27 -> V_70 ) ;
if( V_27 -> V_50 . V_12 == NULL )
return;
F_41 ( V_27 -> V_50 . V_70 ) ;
F_56 ( V_27 -> V_50 . V_105 ) ;
V_27 -> V_50 . V_105 = NULL ;
}
static int F_57 ( struct V_26 * V_27 )
{
struct V_28 V_29 ;
char * * V_106 ;
int V_32 , V_107 , * V_108 ;
int V_70 ;
V_27 -> V_28 = V_27 -> V_51 ;
V_107 = 0 ;
V_108 = ( V_27 -> V_50 . V_12 != NULL ) ? & V_107 : NULL ;
V_106 = V_27 -> V_47 ? NULL : & V_27 -> V_50 . V_12 ;
V_70 = F_49 ( V_27 -> V_12 , & V_27 -> V_28 , V_27 -> V_48 ,
V_106 , & V_27 -> V_50 . V_76 ,
& V_27 -> V_50 . V_109 , & V_27 -> V_50 . V_110 ,
V_108 ) ;
if( ( V_70 == - V_98 ) && V_107 ) {
V_70 = F_53 ( V_27 -> V_12 , V_27 -> V_50 . V_12 ,
V_27 -> V_28 , 1 << 9 , V_111 ,
& V_27 -> V_50 . V_76 ,
& V_27 -> V_50 . V_109 ,
& V_27 -> V_50 . V_110 ) ;
if( V_70 >= 0 ) {
F_18 ( V_40 L_42
L_43 , V_27 -> V_12 , V_27 -> V_50 . V_12 ) ;
}
}
if( V_70 < 0 ) {
F_18 ( L_44 , V_27 -> V_12 ,
- V_70 ) ;
return V_70 ;
}
V_27 -> V_70 = V_70 ;
if( V_27 -> V_50 . V_12 != NULL ) {
F_58 ( V_27 -> V_64 , 8 * sizeof( long ) ) ;
V_32 = - V_112 ;
V_27 -> V_50 . V_105 = F_59 ( V_27 -> V_50 . V_109 ) ;
if( V_27 -> V_50 . V_105 == NULL ) {
F_18 ( V_52 L_45 ) ;
goto error;
}
F_60 () ;
V_32 = F_43 ( V_27 -> V_70 , V_27 -> V_50 . V_105 ,
V_27 -> V_50 . V_76 ,
V_27 -> V_50 . V_109 ) ;
if( V_32 < 0 )
goto error;
V_29 = V_27 -> V_28 ;
V_29 . V_45 = 0 ;
V_32 = F_49 ( V_27 -> V_50 . V_12 , & V_29 , V_27 -> V_48 , NULL ,
NULL , NULL , NULL , NULL ) ;
if( V_32 < 0 ) goto error;
V_27 -> V_50 . V_70 = V_32 ;
}
return 0 ;
error:
F_41 ( V_27 -> V_70 ) ;
return V_32 ;
}
static void F_61 ( struct V_113 * V_66 )
{
struct V_26 * V_27 = F_62 ( V_66 ) ;
F_63 ( V_27 -> V_64 ) ;
* V_27 = ( (struct V_26 ) V_114 ) ;
}
static int F_64 ( int V_34 , T_5 V_74 , int V_115 ,
struct V_116 * * V_117 )
{
struct V_113 * V_118 = NULL ;
struct V_116 * V_119 ;
V_119 = F_65 ( 1 << V_120 ) ;
if( V_119 == NULL )
return - V_112 ;
V_119 -> V_34 = V_34 ;
V_119 -> V_121 = V_115 << V_120 ;
V_119 -> V_122 = & V_123 ;
F_66 ( V_119 , V_74 / 512 ) ;
if ( V_34 == V_39 )
sprintf ( V_119 -> V_124 , L_46 , 'a' + V_115 ) ;
else
sprintf ( V_119 -> V_124 , L_47 , V_115 ) ;
if ( V_34 == V_39 ) {
V_43 [ V_115 ] . V_125 . V_126 = V_115 ;
V_43 [ V_115 ] . V_125 . V_17 = V_127 ;
V_43 [ V_115 ] . V_125 . V_66 . V_128 = F_61 ;
F_67 ( & V_43 [ V_115 ] . V_125 . V_66 , & V_43 [ V_115 ] ) ;
F_68 ( & V_43 [ V_115 ] . V_125 ) ;
V_118 = & V_43 [ V_115 ] . V_125 . V_66 ;
}
V_119 -> V_129 = & V_43 [ V_115 ] ;
V_119 -> V_64 = V_43 [ V_115 ] . V_64 ;
F_69 ( V_118 , V_119 ) ;
* V_117 = V_119 ;
return 0 ;
}
static int F_70 ( int V_3 , char * * V_25 )
{
struct V_26 * V_27 = & V_43 [ V_3 ] ;
int V_32 = 0 ;
if( V_27 -> V_12 == NULL )
goto V_44;
V_32 = F_36 ( V_27 , & V_27 -> V_74 ) ;
if( V_32 < 0 ) {
* V_25 = L_48 ;
goto V_44;
}
V_27 -> V_74 = F_71 ( V_27 -> V_74 ) ;
F_72 ( & V_27 -> V_62 ) ;
F_73 ( V_27 -> V_130 , V_131 ) ;
V_32 = - V_112 ;
V_27 -> V_64 = F_74 ( F_31 , & V_27 -> V_63 ) ;
if ( V_27 -> V_64 == NULL ) {
* V_25 = L_49 ;
goto V_44;
}
V_27 -> V_64 -> V_132 = V_27 ;
F_75 ( V_27 -> V_64 , true , false ) ;
F_76 ( V_27 -> V_64 , V_131 ) ;
V_32 = F_64 ( V_39 , V_27 -> V_74 , V_3 , & V_133 [ V_3 ] ) ;
if( V_32 ) {
* V_25 = L_50 ;
goto V_134;
}
if ( V_38 != V_39 )
F_64 ( V_38 , V_27 -> V_74 , V_3 ,
& V_135 [ V_3 ] ) ;
if ( V_21 )
F_9 ( V_133 [ V_3 ] -> V_124 ) ;
V_32 = 0 ;
V_44:
return V_32 ;
V_134:
F_63 ( V_27 -> V_64 ) ;
goto V_44;
}
static int F_77 ( char * V_20 , char * * V_25 )
{
int V_3 , V_136 ;
V_20 = F_78 ( V_20 , V_137 ) ;
if ( V_20 == NULL ) {
* V_25 = L_51 ;
return - V_112 ;
}
V_136 = F_15 ( V_20 , & V_3 , V_25 ) ;
if ( V_136 )
goto V_138;
if ( V_3 == - 1 ) {
V_136 = 0 ;
goto V_138;
}
F_17 ( & V_37 ) ;
V_136 = F_70 ( V_3 , V_25 ) ;
if ( V_136 )
V_43 [ V_3 ] . V_12 = NULL ;
F_19 ( & V_37 ) ;
V_44:
return V_136 ;
V_138:
F_25 ( V_20 ) ;
goto V_44;
}
static int F_79 ( char * V_17 , char * V_20 , int V_74 , char * * V_25 )
{
struct V_26 * V_27 ;
int V_3 , V_80 = 0 ;
V_3 = F_13 ( & V_17 ) ;
if( ( V_3 >= V_41 ) || ( V_3 < 0 ) ) {
* V_25 = L_52 ;
return - 1 ;
}
V_27 = & V_43 [ V_3 ] ;
F_17 ( & V_37 ) ;
if( V_27 -> V_12 == NULL ) {
F_80 ( V_20 , V_74 , V_80 , L_53 , 1 ) ;
goto V_44;
}
F_80 ( V_20 , V_74 , V_80 , V_27 -> V_12 , 0 ) ;
if( V_27 -> V_50 . V_12 != NULL ) {
F_80 ( V_20 , V_74 , V_80 , L_54 , 0 ) ;
F_80 ( V_20 , V_74 , V_80 , V_27 -> V_50 . V_12 , 1 ) ;
}
else F_80 ( V_20 , V_74 , V_80 , L_53 , 1 ) ;
V_44:
F_19 ( & V_37 ) ;
return V_80 ;
}
static int F_81 ( char * * V_20 , int * V_139 , int * V_140 )
{
int V_3 ;
V_3 = F_13 ( V_20 ) ;
* V_139 = 0 ;
* V_140 = V_41 - 1 ;
return V_3 ;
}
static int F_82 ( int V_3 , char * * V_25 )
{
struct V_116 * V_119 = V_133 [ V_3 ] ;
struct V_26 * V_27 ;
int V_32 = - V_141 ;
F_17 ( & V_37 ) ;
V_27 = & V_43 [ V_3 ] ;
if( V_27 -> V_12 == NULL )
goto V_44;
V_32 = - V_42 ;
if( V_27 -> V_142 > 0 )
goto V_44;
V_133 [ V_3 ] = NULL ;
if( V_119 != NULL ) {
F_83 ( V_119 ) ;
F_84 ( V_119 ) ;
}
if( V_135 [ V_3 ] != NULL ) {
F_83 ( V_135 [ V_3 ] ) ;
F_84 ( V_135 [ V_3 ] ) ;
V_135 [ V_3 ] = NULL ;
}
V_32 = 0 ;
F_85 ( & V_27 -> V_125 ) ;
V_44:
F_19 ( & V_37 ) ;
return V_32 ;
}
static int T_6 F_86 ( void )
{
F_87 ( & V_143 ) ;
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
F_91 ( & V_144 ) ;
F_17 ( & V_37 ) ;
for ( V_33 = 0 ; V_33 < V_41 ; V_33 ++ ) {
V_32 = F_70 ( V_33 , & error ) ;
if( V_32 )
F_18 ( V_52 L_59
L_20 , V_33 , error ) ;
}
F_19 ( & V_37 ) ;
return 0 ;
}
static int T_6 F_92 ( void ) {
unsigned long V_145 ;
int V_32 ;
if( V_30 . V_46 ) {
F_18 ( V_40 L_60 ) ;
}
V_145 = F_93 ( 0 , 0 ) ;
V_68 = F_94 ( V_145 + V_111 - sizeof( void * ) ,
& V_58 ) ;
if( V_68 < 0 ) {
F_18 ( V_52
L_61
L_62 , - V_68 ) ;
V_68 = - 1 ;
return 0 ;
}
V_32 = F_95 ( V_61 , V_58 , V_146 , F_33 ,
0 , L_56 , V_43 ) ;
if( V_32 != 0 )
F_18 ( V_52 L_63 , - V_32 ) ;
return 0 ;
}
static int F_96 ( struct V_147 * V_148 , T_7 V_97 )
{
struct V_116 * V_119 = V_148 -> V_149 ;
struct V_26 * V_27 = V_119 -> V_129 ;
int V_32 = 0 ;
F_17 ( & V_150 ) ;
if( V_27 -> V_142 == 0 ) {
V_32 = F_57 ( V_27 ) ;
if( V_32 ) {
F_18 ( V_52 L_64 ,
V_119 -> V_124 , V_27 -> V_12 , - V_32 ) ;
goto V_44;
}
}
V_27 -> V_142 ++ ;
F_97 ( V_119 , ! V_27 -> V_28 . V_45 ) ;
V_44:
F_19 ( & V_150 ) ;
return V_32 ;
}
static void F_98 ( struct V_116 * V_119 , T_7 V_97 )
{
struct V_26 * V_27 = V_119 -> V_129 ;
F_17 ( & V_150 ) ;
if( -- V_27 -> V_142 == 0 )
F_55 ( V_27 ) ;
F_19 ( & V_150 ) ;
}
static void F_99 ( T_1 V_151 , int V_60 , unsigned long * V_152 ,
T_1 * V_153 , unsigned long * V_105 ,
T_1 V_76 , unsigned long * V_154 ,
T_1 V_109 )
{
T_1 V_155 = V_151 >> 9 ;
int V_33 , V_156 = 0 ;
for( V_33 = 0 ; V_33 < V_60 > > 9 ; V_33 ++ ) {
if( V_152 != NULL )
F_2 ( V_33 , ( unsigned char * ) V_152 ) ;
if( F_1 ( V_155 + V_33 , ( unsigned char * ) V_105 ) )
continue;
V_156 = 1 ;
F_2 ( V_155 + V_33 , ( unsigned char * ) V_105 ) ;
}
if( ! V_156 )
return;
* V_153 = V_155 / (sizeof( unsigned long ) * 8 ) ;
if ( * V_153 == ( F_100 ( V_109 ,
sizeof( unsigned long ) ) - 1 ) )
( * V_153 ) -- ;
V_154 [ 0 ] = V_105 [ * V_153 ] ;
V_154 [ 1 ] = V_105 [ * V_153 + 1 ] ;
* V_153 *= sizeof( unsigned long ) ;
* V_153 += V_76 ;
}
static void F_101 ( struct V_53 * V_54 , unsigned long * V_105 ,
T_1 V_76 , T_1 V_109 )
{
T_1 V_155 = V_54 -> V_79 >> 9 ;
int V_33 ;
if( V_54 -> V_60 > ( sizeof( V_54 -> V_157 ) * 8 ) << 9 )
F_102 ( L_65 ) ;
if( V_54 -> V_158 == V_159 ) {
for( V_33 = 0 ; V_33 < V_54 -> V_60 > > 9 ; V_33 ++ ) {
if( F_1 ( V_155 + V_33 , ( unsigned char * ) V_105 ) )
F_2 ( V_33 , ( unsigned char * )
& V_54 -> V_157 ) ;
}
}
else F_99 ( V_54 -> V_79 , V_54 -> V_60 , & V_54 -> V_157 ,
& V_54 -> V_153 , V_105 , V_76 ,
V_54 -> V_154 , V_109 ) ;
}
static void F_103 ( struct V_160 * V_54 , struct V_53 * V_161 ,
unsigned long long V_79 , int V_162 ,
int V_80 , struct V_163 * V_163 )
{
struct V_116 * V_119 = V_54 -> V_164 ;
struct V_26 * V_27 = V_119 -> V_129 ;
V_161 -> V_54 = V_54 ;
V_161 -> V_165 [ 0 ] = ( V_27 -> V_50 . V_12 != NULL ) ? V_27 -> V_50 . V_70 :
V_27 -> V_70 ;
V_161 -> V_165 [ 1 ] = V_27 -> V_70 ;
V_161 -> V_153 = - 1 ;
V_161 -> V_79 = V_79 ;
V_161 -> V_60 = V_80 ;
V_161 -> error = 0 ;
V_161 -> V_157 = 0 ;
V_161 -> V_158 = ( F_104 ( V_54 ) == V_166 ) ? V_159 : V_167 ;
V_161 -> V_168 [ 0 ] = 0 ;
V_161 -> V_168 [ 1 ] = V_27 -> V_50 . V_110 ;
V_161 -> V_169 = F_105 ( V_163 ) + V_162 ;
V_161 -> V_95 = 1 << 9 ;
if( V_27 -> V_50 . V_12 != NULL )
F_101 ( V_161 , V_27 -> V_50 . V_105 ,
V_27 -> V_50 . V_76 , V_27 -> V_50 . V_109 ) ;
}
static void F_106 ( struct V_160 * V_54 ,
struct V_53 * V_161 )
{
struct V_116 * V_119 = V_54 -> V_164 ;
struct V_26 * V_27 = V_119 -> V_129 ;
V_161 -> V_54 = V_54 ;
V_161 -> V_165 [ 0 ] = ( V_27 -> V_50 . V_12 != NULL ) ? V_27 -> V_50 . V_70 :
V_27 -> V_70 ;
V_161 -> V_158 = V_170 ;
}
static bool F_107 ( struct V_53 * V_161 , struct V_26 * V_66 )
{
int V_3 = F_108 ( V_58 , & V_161 ,
sizeof( V_161 ) ) ;
if ( V_3 != sizeof( V_161 ) ) {
if ( V_3 != - V_59 )
F_18 ( L_66
L_67 , - V_3 ) ;
else if ( F_109 ( & V_66 -> V_62 ) )
F_110 ( & V_66 -> V_62 , & V_62 ) ;
F_25 ( V_161 ) ;
return false ;
}
return true ;
}
static void F_31 ( struct V_171 * V_172 )
{
struct V_53 * V_161 ;
struct V_160 * V_54 ;
while( 1 ) {
struct V_26 * V_66 = V_172 -> V_132 ;
if( V_66 -> V_160 == NULL ) {
struct V_160 * V_54 = F_111 ( V_172 ) ;
if( V_54 == NULL )
return;
V_66 -> V_160 = V_54 ;
V_66 -> V_173 = F_112 ( V_54 ) ;
V_66 -> V_174 = 0 ;
V_66 -> V_175 = F_113 ( V_172 , V_54 , V_66 -> V_130 ) ;
}
V_54 = V_66 -> V_160 ;
if ( F_114 ( V_54 ) == V_176 ) {
V_161 = F_115 ( sizeof( struct V_53 ) ,
V_177 ) ;
if ( V_161 == NULL ) {
if ( F_109 ( & V_66 -> V_62 ) )
F_110 ( & V_66 -> V_62 , & V_62 ) ;
return;
}
F_106 ( V_54 , V_161 ) ;
if ( F_107 ( V_161 , V_66 ) == false )
return;
}
while( V_66 -> V_174 < V_66 -> V_175 ) {
struct V_178 * V_130 = & V_66 -> V_130 [ V_66 -> V_174 ] ;
V_161 = F_115 ( sizeof( struct V_53 ) ,
V_177 ) ;
if( V_161 == NULL ) {
if( F_109 ( & V_66 -> V_62 ) )
F_110 ( & V_66 -> V_62 , & V_62 ) ;
return;
}
F_103 ( V_54 , V_161 ,
( unsigned long long ) V_66 -> V_173 << 9 ,
V_130 -> V_79 , V_130 -> V_60 , F_116 ( V_130 ) ) ;
if ( F_107 ( V_161 , V_66 ) == false )
return;
V_66 -> V_173 += V_130 -> V_60 >> 9 ;
V_66 -> V_174 ++ ;
}
V_66 -> V_175 = 0 ;
V_66 -> V_160 = NULL ;
}
}
static int F_117 ( struct V_147 * V_148 , struct V_179 * V_180 )
{
struct V_26 * V_27 = V_148 -> V_149 -> V_129 ;
V_180 -> V_181 = 128 ;
V_180 -> V_182 = 32 ;
V_180 -> V_183 = V_27 -> V_74 / ( 128 * 32 * 512 ) ;
return 0 ;
}
static int F_118 ( struct V_147 * V_148 , T_7 V_97 ,
unsigned int V_184 , unsigned long V_185 )
{
struct V_26 * V_27 = V_148 -> V_149 -> V_129 ;
T_8 F_81 [ V_186 ] ;
switch ( V_184 ) {
struct V_187 V_188 ;
case V_189 :
memset ( & F_81 , 0 , V_186 * 2 ) ;
F_81 [ V_190 ] = V_27 -> V_74 / ( 128 * 32 * 512 ) ;
F_81 [ V_191 ] = 128 ;
F_81 [ V_192 ] = 32 ;
if( F_119 ( ( char V_193 * ) V_185 , ( char * ) & F_81 ,
sizeof( F_81 ) ) )
return - V_194 ;
return 0 ;
case V_195 :
if( F_120 ( & V_188 , ( char V_193 * ) V_185 , sizeof( V_188 ) ) )
return - V_194 ;
V_188 . V_196 = 255 ;
V_188 . V_197 = 255 ;
V_188 . V_198 = 255 ;
V_188 . V_199 = 255 ;
if( F_119 ( ( char V_193 * ) V_185 , & V_188 , sizeof( V_188 ) ) )
return - V_194 ;
return 0 ;
}
return - V_36 ;
}
static int V_156 ( struct V_53 * V_54 )
{
int V_3 ;
if( V_54 -> V_153 == - 1 )
return 0 ;
V_3 = F_121 ( V_54 -> V_165 [ 1 ] , & V_54 -> V_154 ,
sizeof( V_54 -> V_154 ) , V_54 -> V_153 ) ;
if( V_3 != sizeof( V_54 -> V_154 ) ) {
F_18 ( L_68 , - V_3 ,
V_54 -> V_165 [ 1 ] ) ;
return 1 ;
}
return 0 ;
}
static void F_122 ( struct V_53 * V_54 )
{
char * V_78 ;
unsigned long V_80 ;
int V_3 , V_200 , V_201 , V_23 , V_1 ;
T_1 V_5 ;
if ( V_54 -> V_158 == V_170 ) {
V_3 = F_123 ( V_54 -> V_165 [ 0 ] ) ;
if ( V_3 != 0 ) {
F_18 ( L_69
L_70 , - V_3 , V_54 -> V_165 [ 0 ] ) ;
V_54 -> error = 1 ;
}
return;
}
V_200 = V_54 -> V_60 / V_54 -> V_95 ;
V_201 = 0 ;
do {
V_1 = F_1 ( V_201 , ( unsigned char * ) & V_54 -> V_157 ) ;
V_23 = V_201 ;
while( ( V_23 < V_200 ) &&
( F_1 ( V_23 , ( unsigned char * )
& V_54 -> V_157 ) == V_1 ) )
V_23 ++ ;
V_5 = V_54 -> V_79 + V_54 -> V_168 [ V_1 ] +
V_201 * V_54 -> V_95 ;
V_80 = ( V_23 - V_201 ) * V_54 -> V_95 ;
V_78 = & V_54 -> V_169 [ V_201 * V_54 -> V_95 ] ;
if( V_54 -> V_158 == V_159 ) {
V_3 = 0 ;
do {
V_78 = & V_78 [ V_3 ] ;
V_80 -= V_3 ;
V_3 = F_44 ( V_54 -> V_165 [ V_1 ] , V_78 , V_80 , V_5 ) ;
if ( V_3 < 0 ) {
F_18 ( L_71
L_70 , - V_3 , V_54 -> V_165 [ V_1 ] ) ;
V_54 -> error = 1 ;
return;
}
} while( ( V_3 < V_80 ) && ( V_3 != 0 ) );
if ( V_3 < V_80 ) memset ( & V_78 [ V_3 ] , 0 , V_80 - V_3 ) ;
} else {
V_3 = F_121 ( V_54 -> V_165 [ V_1 ] , V_78 , V_80 , V_5 ) ;
if( V_3 != V_80 ) {
F_18 ( L_72
L_70 , - V_3 , V_54 -> V_165 [ V_1 ] ) ;
V_54 -> error = 1 ;
return;
}
}
V_201 = V_23 ;
} while( V_201 < V_200 );
V_54 -> error = V_156 ( V_54 ) ;
}
int F_124 ( void * V_185 )
{
struct V_53 * V_54 ;
int V_3 ;
F_125 () ;
while( 1 ) {
V_3 = F_23 ( V_202 , & V_54 ,
sizeof( struct V_53 * ) ) ;
if( V_3 != sizeof( struct V_53 * ) ) {
if( V_3 < 0 )
F_18 ( L_73
L_24 , V_202 , - V_3 ) ;
else {
F_18 ( L_74
L_75 , V_202 , V_3 ) ;
}
continue;
}
V_203 ++ ;
F_122 ( V_54 ) ;
V_3 = F_108 ( V_202 , & V_54 ,
sizeof( struct V_53 * ) ) ;
if( V_3 != sizeof( struct V_53 * ) )
F_18 ( L_76 ,
V_202 , - V_3 ) ;
}
return 0 ;
}
