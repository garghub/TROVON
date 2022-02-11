static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_4 ) ;
V_2 -> V_5 = F_3 ( V_4 ) ;
V_2 -> V_6 = F_4 ( F_5 () ) ;
}
static int F_6 ( struct V_7 * V_8 , struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_7 * V_13 ;
int V_14 = 0 ;
F_7 ( V_12 ) ;
F_8 (sp, rule_list, list) {
if ( V_13 -> V_15 == V_8 -> V_15 &&
V_13 -> V_16 == V_8 -> V_16 ) {
V_14 = 1 ;
V_13 -> V_17 = V_8 -> V_17 ;
break;
}
}
if ( V_14 == 0 )
F_9 ( & V_8 -> V_18 , V_10 ) ;
F_10 ( V_12 ) ;
return V_14 ;
}
static T_1 F_11 ( struct V_19 * V_19 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_7 * V_23 ;
char * V_24 ;
int V_25 = - V_26 ;
if ( * V_22 != 0 )
return - V_26 ;
if ( V_21 < ( V_27 ) || V_21 > V_28 )
return - V_26 ;
V_24 = F_12 ( V_28 , V_29 ) ;
if ( V_24 == NULL )
return - V_30 ;
if ( F_13 ( V_24 , V_20 , V_21 ) != 0 ) {
V_25 = - V_31 ;
goto V_32;
}
if ( V_21 == ( V_27 ) )
V_24 [ V_27 ] = '-' ;
V_23 = F_12 ( sizeof( * V_23 ) , V_29 ) ;
if ( V_23 == NULL ) {
V_25 = - V_30 ;
goto V_32;
}
V_23 -> V_15 = F_14 ( V_24 , 0 ) ;
if ( V_23 -> V_15 == NULL )
goto V_33;
V_23 -> V_16 = F_14 ( V_24 + V_34 , 0 ) ;
if ( V_23 -> V_16 == NULL )
goto V_33;
V_23 -> V_17 = 0 ;
switch ( V_24 [ V_34 + V_34 ] ) {
case '-' :
break;
case 'r' :
case 'R' :
V_23 -> V_17 |= V_35 ;
break;
default:
goto V_33;
}
switch ( V_24 [ V_34 + V_34 + 1 ] ) {
case '-' :
break;
case 'w' :
case 'W' :
V_23 -> V_17 |= V_36 ;
break;
default:
goto V_33;
}
switch ( V_24 [ V_34 + V_34 + 2 ] ) {
case '-' :
break;
case 'x' :
case 'X' :
V_23 -> V_17 |= V_37 ;
break;
default:
goto V_33;
}
switch ( V_24 [ V_34 + V_34 + 3 ] ) {
case '-' :
break;
case 'a' :
case 'A' :
V_23 -> V_17 |= V_38 ;
break;
default:
goto V_33;
}
switch ( V_24 [ V_34 + V_34 + 4 ] ) {
case '-' :
break;
case 't' :
case 'T' :
V_23 -> V_17 |= V_39 ;
break;
default:
goto V_33;
}
V_25 = V_21 ;
if ( ! F_6 ( V_23 , V_10 , V_12 ) )
goto V_32;
V_33:
F_15 ( V_23 ) ;
V_32:
F_15 ( V_24 ) ;
return V_25 ;
}
static void * F_16 ( struct V_40 * V_41 , T_4 * V_42 )
{
if ( * V_42 == V_43 )
return NULL ;
if ( F_17 ( & V_44 ) )
return NULL ;
return V_44 . V_45 ;
}
static void * F_18 ( struct V_40 * V_41 , void * V_46 , T_4 * V_42 )
{
struct V_9 * V_18 = V_46 ;
if ( F_19 ( V_18 , & V_44 ) ) {
* V_42 = V_43 ;
return NULL ;
}
return V_18 -> V_45 ;
}
static int F_20 ( struct V_40 * V_41 , void * V_46 )
{
struct V_9 * V_18 = V_46 ;
struct V_7 * V_8 =
F_21 ( V_18 , struct V_7 , V_18 ) ;
F_22 ( V_41 , L_1 , ( char * ) V_8 -> V_15 ,
( char * ) V_8 -> V_16 ) ;
F_23 ( V_41 , ' ' ) ;
if ( V_8 -> V_17 & V_35 )
F_23 ( V_41 , 'r' ) ;
if ( V_8 -> V_17 & V_36 )
F_23 ( V_41 , 'w' ) ;
if ( V_8 -> V_17 & V_37 )
F_23 ( V_41 , 'x' ) ;
if ( V_8 -> V_17 & V_38 )
F_23 ( V_41 , 'a' ) ;
if ( V_8 -> V_17 & V_39 )
F_23 ( V_41 , 't' ) ;
if ( V_8 -> V_17 == 0 )
F_23 ( V_41 , '-' ) ;
F_23 ( V_41 , '\n' ) ;
return 0 ;
}
static void F_24 ( struct V_40 * V_41 , void * V_46 )
{
}
static int F_25 ( struct V_47 * V_47 , struct V_19 * V_19 )
{
return F_26 ( V_19 , & V_48 ) ;
}
static T_1 F_27 ( struct V_19 * V_19 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
if ( ! F_28 ( V_49 ) )
return - V_50 ;
return F_11 ( V_19 , V_20 , V_21 , V_22 , & V_44 ,
& V_51 ) ;
}
static void F_29 ( void )
{
int V_25 ;
struct V_52 * V_53 ;
struct V_1 V_54 ;
F_1 ( & V_54 ) ;
V_25 = F_30 ( NULL , V_55 , NULL , NULL , & V_54 ) ;
if ( V_25 != 0 )
F_31 ( V_56 L_2 ,
V_57 , __LINE__ , V_25 ) ;
V_53 = F_32 ( sizeof( struct V_52 ) , V_29 ) ;
if ( V_53 == NULL )
F_33 ( L_3 ) ;
V_53 -> V_58 . V_59 = NULL ;
V_53 -> V_60 = V_61 ;
V_53 -> type = V_62 ;
V_53 -> V_63 [ 0 ] = V_64 ;
for ( V_25 = 1 ; V_25 < V_65 ; V_25 ++ )
V_53 -> V_63 [ V_25 ] = V_66 ;
V_25 = F_34 ( V_53 , & V_54 ) ;
if ( V_25 != 0 ) {
F_31 ( V_56 L_4 ,
V_57 , __LINE__ , V_25 ) ;
F_15 ( V_53 ) ;
return;
}
V_25 = F_35 ( V_53 -> V_60 , NULL , NULL , NULL , & V_54 ) ;
if ( V_25 != 0 ) {
F_31 ( V_56 L_5 ,
V_57 , __LINE__ , V_25 ) ;
F_15 ( V_53 ) ;
return;
}
}
static void F_36 ( char * V_67 )
{
int V_25 ;
struct V_1 V_54 ;
F_1 ( & V_54 ) ;
if ( V_67 != NULL ) {
V_25 = F_30 ( V_67 , V_55 , NULL , NULL , & V_54 ) ;
if ( V_25 != 0 )
F_31 ( V_56 L_2 ,
V_57 , __LINE__ , V_25 ) ;
}
V_25 = F_37 ( V_68 , V_55 ,
NULL , NULL , & V_54 ) ;
if ( V_25 != 0 )
F_31 ( V_56 L_6 ,
V_57 , __LINE__ , V_25 ) ;
}
static void * F_38 ( struct V_40 * V_41 , T_4 * V_42 )
{
if ( * V_42 == V_43 )
return NULL ;
if ( F_17 ( & V_69 ) )
return NULL ;
return V_69 . V_45 ;
}
static void * F_39 ( struct V_40 * V_41 , void * V_46 , T_4 * V_42 )
{
struct V_9 * V_18 = V_46 ;
if ( F_19 ( V_18 , & V_69 ) ) {
* V_42 = V_43 ;
return NULL ;
}
return V_18 -> V_45 ;
}
static int F_40 ( struct V_40 * V_41 , void * V_46 )
{
struct V_9 * V_18 = V_46 ;
struct V_70 * V_71 =
F_21 ( V_18 , struct V_70 , V_18 ) ;
struct V_72 * V_73 = V_71 -> V_74 ;
char * V_75 ;
char V_76 = '/' ;
int V_77 = 1 ;
int V_78 ;
unsigned char V_79 ;
if ( V_73 == NULL )
return 0 ;
F_22 ( V_41 , L_7 , ( char * ) & V_71 -> V_80 , V_73 -> V_81 ) ;
V_75 = V_73 -> V_82 ;
for ( V_78 = 0 ; V_78 < V_34 ; V_78 ++ )
for ( V_79 = 0x80 ; V_79 != 0 ; V_79 >>= 1 ) {
if ( V_79 & V_75 [ V_78 ] ) {
F_22 ( V_41 , L_8 , V_76 , V_77 ) ;
V_76 = ',' ;
}
V_77 ++ ;
}
F_23 ( V_41 , '\n' ) ;
return 0 ;
}
static void F_41 ( struct V_40 * V_41 , void * V_46 )
{
}
static int F_42 ( struct V_47 * V_47 , struct V_19 * V_19 )
{
return F_26 ( V_19 , & V_83 ) ;
}
static T_1 F_43 ( struct V_19 * V_19 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 = NULL ;
char V_84 [ V_34 ] ;
int V_85 ;
int V_77 ;
int V_86 ;
T_1 V_25 = - V_26 ;
char * V_24 = NULL ;
char * V_23 ;
int V_87 ;
int V_78 ;
if ( ! F_28 ( V_49 ) )
return - V_50 ;
if ( * V_22 != 0 )
return - V_26 ;
if ( V_21 < V_88 || V_21 > V_89 )
return - V_26 ;
V_24 = F_12 ( V_21 + 1 , V_29 ) ;
if ( V_24 == NULL )
return - V_30 ;
if ( F_13 ( V_24 , V_20 , V_21 ) != 0 ) {
V_25 = - V_31 ;
goto V_90;
}
if ( V_24 [ 0 ] == '-' ) {
V_25 = - V_26 ;
goto V_90;
}
V_24 [ V_21 ] = '\0' ;
V_23 = V_24 ;
F_7 ( & V_91 ) ;
V_71 = F_44 ( V_23 , 0 ) ;
if ( V_71 == NULL )
goto V_32;
V_23 += V_34 ;
V_87 = sscanf ( V_23 , L_9 , & V_85 ) ;
if ( V_87 != 1 || V_85 > V_92 )
goto V_32;
V_23 += V_93 ;
V_87 = sscanf ( V_23 , L_9 , & V_86 ) ;
if ( V_87 != 1 || V_86 > V_94 )
goto V_32;
if ( V_21 != ( V_88 + V_86 * V_93 ) )
goto V_32;
memset ( V_84 , 0 , sizeof( V_84 ) ) ;
for ( V_78 = 0 ; V_78 < V_86 ; V_78 ++ ) {
V_23 += V_93 ;
V_87 = sscanf ( V_23 , L_9 , & V_77 ) ;
if ( V_87 != 1 || V_77 > V_95 )
goto V_32;
F_45 ( V_77 , V_84 ) ;
}
if ( V_71 -> V_74 == NULL ) {
V_73 = F_12 ( sizeof( struct V_72 ) , V_29 ) ;
if ( V_73 == NULL ) {
V_25 = - V_30 ;
goto V_32;
}
}
F_46 ( & V_71 -> V_96 ) ;
if ( V_73 == NULL )
V_73 = V_71 -> V_74 ;
else
V_71 -> V_74 = V_73 ;
V_73 -> V_81 = V_85 ;
memcpy ( V_73 -> V_82 , V_84 , sizeof( V_84 ) ) ;
F_47 ( & V_71 -> V_96 ) ;
V_25 = V_21 ;
V_32:
F_10 ( & V_91 ) ;
V_90:
F_15 ( V_24 ) ;
return V_25 ;
}
static void * F_48 ( struct V_40 * V_41 , T_4 * V_42 )
{
if ( * V_42 == V_43 )
return NULL ;
if ( F_17 ( & V_97 ) )
return NULL ;
return V_97 . V_45 ;
}
static void * F_49 ( struct V_40 * V_41 , void * V_46 , T_4 * V_42 )
{
struct V_9 * V_18 = V_46 ;
if ( F_19 ( V_18 , & V_97 ) ) {
* V_42 = V_43 ;
return NULL ;
}
return V_18 -> V_45 ;
}
static int F_50 ( struct V_40 * V_41 , void * V_46 )
{
struct V_9 * V_18 = V_46 ;
struct V_98 * V_71 =
F_21 ( V_18 , struct V_98 , V_18 ) ;
unsigned char * V_99 = ( char * ) & V_71 -> V_100 . V_101 . V_102 ;
int V_103 ;
T_5 V_104 = F_51 ( V_71 -> V_105 . V_102 ) ;
for ( V_103 = 0 ; V_104 ; V_104 <<= 1 , V_103 ++ ) ;
F_22 ( V_41 , L_10 ,
V_99 [ 0 ] , V_99 [ 1 ] , V_99 [ 2 ] , V_99 [ 3 ] , V_103 , V_71 -> V_106 ) ;
return 0 ;
}
static void F_52 ( struct V_40 * V_41 , void * V_46 )
{
}
static int F_53 ( struct V_47 * V_47 , struct V_19 * V_19 )
{
return F_26 ( V_19 , & V_107 ) ;
}
static void F_54 ( struct V_98 * V_108 )
{
struct V_98 * V_79 , * V_109 ;
if ( F_17 ( & V_97 ) ) {
F_9 ( & V_108 -> V_18 , & V_97 ) ;
return;
}
V_79 = F_55 ( V_97 . V_45 ,
struct V_98 , V_18 ) ;
if ( V_108 -> V_105 . V_102 > V_79 -> V_105 . V_102 ) {
F_9 ( & V_108 -> V_18 , & V_97 ) ;
return;
}
F_8 (m, &smk_netlbladdr_list, list) {
if ( F_19 ( & V_79 -> V_18 , & V_97 ) ) {
F_9 ( & V_108 -> V_18 , & V_79 -> V_18 ) ;
return;
}
V_109 = F_55 ( V_79 -> V_18 . V_45 ,
struct V_98 , V_18 ) ;
if ( V_108 -> V_105 . V_102 > V_109 -> V_105 . V_102 ) {
F_9 ( & V_108 -> V_18 , & V_79 -> V_18 ) ;
return;
}
}
}
static T_1 F_56 ( struct V_19 * V_19 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
struct V_98 * V_71 ;
struct V_110 V_111 ;
char V_112 [ V_34 ] ;
char * V_13 ;
char V_24 [ V_113 + 1 ] ;
char * V_114 = ( char * ) & V_111 . V_101 . V_102 ;
int V_25 ;
struct V_1 V_115 ;
struct V_116 V_117 ;
unsigned int V_79 ;
int V_14 ;
T_5 V_118 = ( 1 << 31 ) ;
T_6 V_119 ;
T_5 V_104 ;
if ( ! F_28 ( V_49 ) )
return - V_50 ;
if ( * V_22 != 0 )
return - V_26 ;
if ( V_21 < V_120 || V_21 > V_113 )
return - V_26 ;
if ( F_13 ( V_24 , V_20 , V_21 ) != 0 )
return - V_31 ;
V_24 [ V_21 ] = '\0' ;
V_25 = sscanf ( V_24 , L_11 ,
& V_114 [ 0 ] , & V_114 [ 1 ] , & V_114 [ 2 ] , & V_114 [ 3 ] , & V_79 , V_112 ) ;
if ( V_25 != 6 ) {
V_25 = sscanf ( V_24 , L_12 ,
& V_114 [ 0 ] , & V_114 [ 1 ] , & V_114 [ 2 ] , & V_114 [ 3 ] , V_112 ) ;
if ( V_25 != 5 )
return - V_26 ;
V_79 = V_121 ;
}
if ( V_79 > V_121 )
return - V_26 ;
if ( V_112 [ 0 ] != '-' ) {
V_13 = F_14 ( V_112 , 0 ) ;
if ( V_13 == NULL )
return - V_26 ;
} else {
if ( strcmp ( V_112 , V_122 ) == 0 )
V_13 = ( char * ) V_122 ;
else
return - V_26 ;
}
for ( V_104 = 0 ; V_79 > 0 ; V_79 -- ) {
V_104 |= V_118 ;
V_118 >>= 1 ;
}
V_117 . V_102 = F_57 ( V_104 ) ;
V_111 . V_101 . V_102 &= V_117 . V_102 ;
F_7 ( & V_123 ) ;
V_119 = V_111 . V_101 . V_102 ;
V_14 = 0 ;
F_8 (skp, &smk_netlbladdr_list, list) {
if ( V_71 -> V_100 . V_101 . V_102 == V_119 &&
V_71 -> V_105 . V_102 == V_117 . V_102 ) {
V_14 = 1 ;
break;
}
}
F_1 ( & V_115 ) ;
if ( V_14 == 0 ) {
V_71 = F_12 ( sizeof( * V_71 ) , V_29 ) ;
if ( V_71 == NULL )
V_25 = - V_30 ;
else {
V_25 = 0 ;
V_71 -> V_100 . V_101 . V_102 = V_111 . V_101 . V_102 ;
V_71 -> V_105 . V_102 = V_117 . V_102 ;
V_71 -> V_106 = V_13 ;
F_54 ( V_71 ) ;
}
} else {
if ( V_71 -> V_106 != V_122 )
V_25 = F_58 ( & V_124 , NULL ,
& V_71 -> V_100 . V_101 , & V_71 -> V_105 ,
V_55 , & V_115 ) ;
else
V_25 = 0 ;
V_71 -> V_106 = V_13 ;
}
if ( V_25 == 0 && V_13 != V_122 )
V_25 = F_59 ( & V_124 , NULL ,
& V_71 -> V_100 . V_101 , & V_71 -> V_105 , V_55 ,
F_4 ( V_71 -> V_106 ) , & V_115 ) ;
if ( V_25 == 0 )
V_25 = V_21 ;
F_10 ( & V_123 ) ;
return V_25 ;
}
static T_1 F_60 ( struct V_19 * V_125 , char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
char V_126 [ 80 ] ;
T_1 V_25 ;
if ( * V_22 != 0 )
return 0 ;
sprintf ( V_126 , L_9 , V_61 ) ;
V_25 = F_61 ( V_20 , V_21 , V_22 , V_126 , strlen ( V_126 ) ) ;
return V_25 ;
}
static T_1 F_62 ( struct V_19 * V_19 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
char V_126 [ 80 ] ;
int V_78 ;
if ( ! F_28 ( V_49 ) )
return - V_50 ;
if ( V_21 >= sizeof( V_126 ) || V_21 == 0 )
return - V_26 ;
if ( F_13 ( V_126 , V_20 , V_21 ) != 0 )
return - V_31 ;
V_126 [ V_21 ] = '\0' ;
if ( sscanf ( V_126 , L_9 , & V_78 ) != 1 )
return - V_26 ;
V_61 = V_78 ;
F_29 () ;
return V_21 ;
}
static T_1 F_63 ( struct V_19 * V_125 , char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
char V_126 [ 80 ] ;
T_1 V_25 ;
if ( * V_22 != 0 )
return 0 ;
sprintf ( V_126 , L_9 , V_127 ) ;
V_25 = F_61 ( V_20 , V_21 , V_22 , V_126 , strlen ( V_126 ) ) ;
return V_25 ;
}
static T_1 F_64 ( struct V_19 * V_19 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
char V_126 [ 80 ] ;
int V_78 ;
if ( ! F_28 ( V_49 ) )
return - V_50 ;
if ( V_21 >= sizeof( V_126 ) || V_21 == 0 )
return - V_26 ;
if ( F_13 ( V_126 , V_20 , V_21 ) != 0 )
return - V_31 ;
V_126 [ V_21 ] = '\0' ;
if ( sscanf ( V_126 , L_9 , & V_78 ) != 1 )
return - V_26 ;
V_127 = V_78 ;
return V_21 ;
}
static T_1 F_65 ( struct V_19 * V_125 , char T_2 * V_20 ,
T_3 V_128 , T_4 * V_22 )
{
T_1 V_25 ;
int V_129 ;
if ( * V_22 != 0 )
return 0 ;
F_7 ( & V_130 ) ;
V_129 = strlen ( V_68 ) + 1 ;
if ( V_128 >= V_129 )
V_25 = F_61 ( V_20 , V_128 , V_22 ,
V_68 , V_129 ) ;
else
V_25 = - V_26 ;
F_10 ( & V_130 ) ;
return V_25 ;
}
static T_1 F_66 ( struct V_19 * V_19 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
char V_131 [ V_34 ] ;
char * V_67 ;
char * V_112 ;
if ( ! F_28 ( V_49 ) )
return - V_50 ;
if ( V_21 >= V_34 )
return - V_26 ;
if ( F_13 ( V_131 , V_20 , V_21 ) != 0 )
return - V_31 ;
V_112 = F_14 ( V_131 , V_21 ) ;
if ( V_112 == NULL )
return - V_26 ;
F_7 ( & V_130 ) ;
V_67 = V_68 ;
V_68 = V_112 ;
F_36 ( V_67 ) ;
F_10 ( & V_130 ) ;
return V_21 ;
}
static T_1 F_67 ( struct V_19 * V_125 , char T_2 * V_20 ,
T_3 V_128 , T_4 * V_22 )
{
char * V_112 = L_13 ;
T_1 V_25 = - V_26 ;
int V_129 ;
if ( * V_22 != 0 )
return 0 ;
if ( V_132 != NULL )
V_112 = V_132 ;
V_129 = strlen ( V_112 ) + 1 ;
if ( V_128 >= V_129 )
V_25 = F_61 ( V_20 , V_128 , V_22 , V_112 , V_129 ) ;
return V_25 ;
}
static T_1 F_68 ( struct V_19 * V_19 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
char V_131 [ V_34 ] ;
char * V_13 = F_69 ( V_4 -> V_133 -> V_134 ) ;
if ( ! F_28 ( V_49 ) )
return - V_50 ;
if ( V_132 != NULL && V_132 != V_13 )
return - V_50 ;
if ( V_21 >= V_34 )
return - V_26 ;
if ( F_13 ( V_131 , V_20 , V_21 ) != 0 )
return - V_31 ;
V_132 = F_14 ( V_131 , V_21 ) ;
return V_21 ;
}
static T_1 F_70 ( struct V_19 * V_125 , char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
char V_126 [ 32 ] ;
T_1 V_25 ;
if ( * V_22 != 0 )
return 0 ;
sprintf ( V_126 , L_14 , V_135 ) ;
V_25 = F_61 ( V_20 , V_21 , V_22 , V_126 , strlen ( V_126 ) ) ;
return V_25 ;
}
static T_1 F_71 ( struct V_19 * V_19 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
char V_126 [ 32 ] ;
int V_78 ;
if ( ! F_28 ( V_49 ) )
return - V_50 ;
if ( V_21 >= sizeof( V_126 ) || V_21 == 0 )
return - V_26 ;
if ( F_13 ( V_126 , V_20 , V_21 ) != 0 )
return - V_31 ;
V_126 [ V_21 ] = '\0' ;
if ( sscanf ( V_126 , L_9 , & V_78 ) != 1 )
return - V_26 ;
if ( V_78 < 0 || V_78 > 3 )
return - V_26 ;
V_135 = V_78 ;
return V_21 ;
}
static void * F_72 ( struct V_40 * V_41 , T_4 * V_42 )
{
struct V_136 * V_137 = F_73 () ;
if ( * V_42 == V_43 )
return NULL ;
if ( F_17 ( & V_137 -> V_138 ) )
return NULL ;
return V_137 -> V_138 . V_45 ;
}
static void * F_74 ( struct V_40 * V_41 , void * V_46 , T_4 * V_42 )
{
struct V_136 * V_137 = F_73 () ;
struct V_9 * V_18 = V_46 ;
if ( F_19 ( V_18 , & V_137 -> V_138 ) ) {
* V_42 = V_43 ;
return NULL ;
}
return V_18 -> V_45 ;
}
static int F_75 ( struct V_40 * V_41 , void * V_46 )
{
struct V_9 * V_18 = V_46 ;
struct V_7 * V_8 =
F_21 ( V_18 , struct V_7 , V_18 ) ;
F_22 ( V_41 , L_1 , ( char * ) V_8 -> V_15 ,
( char * ) V_8 -> V_16 ) ;
F_23 ( V_41 , ' ' ) ;
if ( V_8 -> V_17 & V_35 )
F_23 ( V_41 , 'r' ) ;
if ( V_8 -> V_17 & V_36 )
F_23 ( V_41 , 'w' ) ;
if ( V_8 -> V_17 & V_37 )
F_23 ( V_41 , 'x' ) ;
if ( V_8 -> V_17 & V_38 )
F_23 ( V_41 , 'a' ) ;
if ( V_8 -> V_17 & V_39 )
F_23 ( V_41 , 't' ) ;
if ( V_8 -> V_17 == 0 )
F_23 ( V_41 , '-' ) ;
F_23 ( V_41 , '\n' ) ;
return 0 ;
}
static void F_76 ( struct V_40 * V_41 , void * V_46 )
{
}
static int F_77 ( struct V_47 * V_47 , struct V_19 * V_19 )
{
return F_26 ( V_19 , & V_139 ) ;
}
static T_1 F_78 ( struct V_19 * V_19 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
struct V_136 * V_137 = F_73 () ;
return F_11 ( V_19 , V_20 , V_21 , V_22 , & V_137 -> V_138 ,
& V_137 -> V_140 ) ;
}
static int F_79 ( struct V_141 * V_142 , void * V_24 , int V_143 )
{
int V_25 ;
struct V_47 * V_144 ;
static struct V_145 V_146 [] = {
[ V_147 ] = {
L_15 , & V_148 , V_149 | V_150 } ,
[ V_151 ] = {
L_16 , & V_152 , V_149 | V_150 } ,
[ V_153 ] = {
L_17 , & V_154 , V_149 | V_150 } ,
[ V_155 ] = {
L_18 , & V_156 , V_149 | V_150 } ,
[ V_157 ] = {
L_19 , & V_158 , V_149 | V_150 } ,
[ V_159 ] = {
L_20 , & V_160 , V_149 | V_150 } ,
[ V_161 ] = {
L_21 , & V_162 , V_149 | V_150 } ,
[ V_163 ] = {
L_22 , & V_164 , V_149 | V_150 } ,
[ V_165 ] = {
L_23 , & V_166 , V_149 | V_167 } ,
{ L_13 }
} ;
V_25 = F_80 ( V_142 , V_168 , V_146 ) ;
if ( V_25 != 0 ) {
F_31 ( V_169 L_24 ,
V_57 , V_25 ) ;
return V_25 ;
}
V_144 = V_142 -> V_170 -> V_171 ;
V_144 -> V_172 = F_81 ( V_173 . V_80 ) ;
return 0 ;
}
static struct V_174 * F_82 ( struct V_175 * V_176 ,
int V_177 , const char * V_178 , void * V_24 )
{
return F_83 ( V_176 , V_177 , V_24 , F_79 ) ;
}
static int T_7 F_84 ( void )
{
int V_179 ;
if ( ! F_85 ( & V_180 ) )
return 0 ;
V_179 = F_86 ( & V_181 ) ;
if ( ! V_179 ) {
V_182 = F_87 ( & V_181 ) ;
if ( F_88 ( V_182 ) ) {
F_31 ( V_169 L_25 ) ;
V_179 = F_89 ( V_182 ) ;
V_182 = NULL ;
}
}
F_29 () ;
F_36 ( NULL ) ;
return V_179 ;
}
