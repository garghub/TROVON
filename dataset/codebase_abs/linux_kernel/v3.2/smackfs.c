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
static int F_11 ( const char * V_19 , struct V_7 * V_20 , int V_21 )
{
char V_22 [ V_23 ] ;
struct V_24 * V_25 ;
if ( V_21 ) {
V_20 -> V_16 = F_12 ( V_19 , 0 ) ;
if ( V_20 -> V_16 == NULL )
return - 1 ;
V_20 -> V_15 = F_12 ( V_19 + V_23 , 0 ) ;
if ( V_20 -> V_15 == NULL )
return - 1 ;
} else {
F_13 ( V_19 , 0 , V_22 ) ;
V_25 = F_14 ( V_22 ) ;
if ( V_25 == NULL )
return - 1 ;
V_20 -> V_16 = V_25 -> V_26 ;
F_13 ( V_19 + V_23 , 0 , V_22 ) ;
V_25 = F_14 ( V_22 ) ;
if ( V_25 == NULL )
return - 1 ;
V_20 -> V_15 = V_25 -> V_26 ;
}
V_20 -> V_17 = 0 ;
switch ( V_19 [ V_23 + V_23 ] ) {
case '-' :
break;
case 'r' :
case 'R' :
V_20 -> V_17 |= V_27 ;
break;
default:
return - 1 ;
}
switch ( V_19 [ V_23 + V_23 + 1 ] ) {
case '-' :
break;
case 'w' :
case 'W' :
V_20 -> V_17 |= V_28 ;
break;
default:
return - 1 ;
}
switch ( V_19 [ V_23 + V_23 + 2 ] ) {
case '-' :
break;
case 'x' :
case 'X' :
V_20 -> V_17 |= V_29 ;
break;
default:
return - 1 ;
}
switch ( V_19 [ V_23 + V_23 + 3 ] ) {
case '-' :
break;
case 'a' :
case 'A' :
V_20 -> V_17 |= V_30 ;
break;
default:
return - 1 ;
}
switch ( V_19 [ V_23 + V_23 + 4 ] ) {
case '-' :
break;
case 't' :
case 'T' :
V_20 -> V_17 |= V_31 ;
break;
default:
return - 1 ;
}
return 0 ;
}
static T_1 F_15 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_36 * V_37 ;
struct V_24 * V_25 ;
struct V_7 * V_20 ;
char * V_19 ;
int V_38 = - V_39 ;
int V_40 = 0 ;
if ( * V_35 != 0 )
return - V_39 ;
if ( V_34 < ( V_41 ) || V_34 > V_42 )
return - V_39 ;
V_19 = F_16 ( V_42 , V_43 ) ;
if ( V_19 == NULL )
return - V_44 ;
if ( F_17 ( V_19 , V_33 , V_34 ) != 0 ) {
V_38 = - V_45 ;
goto V_46;
}
if ( V_34 == ( V_41 ) )
V_19 [ V_41 ] = '-' ;
V_20 = F_16 ( sizeof( * V_20 ) , V_43 ) ;
if ( V_20 == NULL ) {
V_38 = - V_44 ;
goto V_46;
}
if ( F_11 ( V_19 , V_20 , 1 ) )
goto V_47;
if ( V_10 == NULL ) {
V_40 = 1 ;
V_25 = F_14 ( V_20 -> V_16 ) ;
V_10 = & V_25 -> V_48 ;
V_12 = & V_25 -> V_49 ;
}
V_38 = V_34 ;
if ( V_40 && ! F_6 ( V_20 , V_10 , V_12 ) ) {
V_37 = F_16 ( sizeof( * V_37 ) , V_43 ) ;
if ( V_37 != NULL ) {
V_37 -> V_50 = V_20 ;
F_9 ( & V_37 -> V_18 , & V_51 ) ;
} else
V_38 = - V_44 ;
goto V_46;
}
V_47:
F_18 ( V_20 ) ;
V_46:
F_18 ( V_19 ) ;
return V_38 ;
}
static void * F_19 ( struct V_52 * V_53 , T_4 * V_54 ,
struct V_9 * V_55 )
{
struct V_9 * V_18 ;
if ( V_53 -> V_56 == 0 )
V_53 -> V_57 = V_55 ;
if ( V_53 -> V_57 == NULL )
return NULL ;
V_18 = V_53 -> V_57 ;
if ( F_20 ( V_18 ) )
return NULL ;
if ( V_53 -> V_56 == 0 )
return V_18 -> V_58 ;
return V_18 ;
}
static void * F_21 ( struct V_52 * V_53 , void * V_59 , T_4 * V_54 ,
struct V_9 * V_55 )
{
struct V_9 * V_18 = V_59 ;
if ( F_22 ( V_18 , V_55 ) ) {
V_53 -> V_57 = NULL ;
return NULL ;
}
V_53 -> V_57 = V_18 -> V_58 ;
return V_18 -> V_58 ;
}
static void F_23 ( struct V_52 * V_53 , void * V_59 )
{
}
static void * F_24 ( struct V_52 * V_53 , T_4 * V_54 )
{
return F_19 ( V_53 , V_54 , & V_51 ) ;
}
static void * F_25 ( struct V_52 * V_53 , void * V_59 , T_4 * V_54 )
{
return F_21 ( V_53 , V_59 , V_54 , & V_51 ) ;
}
static int F_26 ( struct V_52 * V_53 , void * V_59 )
{
struct V_9 * V_18 = V_59 ;
struct V_36 * V_37 =
F_27 ( V_18 , struct V_36 , V_18 ) ;
struct V_7 * V_8 = V_37 -> V_50 ;
F_28 ( V_53 , L_1 , ( char * ) V_8 -> V_16 ,
( char * ) V_8 -> V_15 ) ;
F_29 ( V_53 , ' ' ) ;
if ( V_8 -> V_17 & V_27 )
F_29 ( V_53 , 'r' ) ;
if ( V_8 -> V_17 & V_28 )
F_29 ( V_53 , 'w' ) ;
if ( V_8 -> V_17 & V_29 )
F_29 ( V_53 , 'x' ) ;
if ( V_8 -> V_17 & V_30 )
F_29 ( V_53 , 'a' ) ;
if ( V_8 -> V_17 & V_31 )
F_29 ( V_53 , 't' ) ;
if ( V_8 -> V_17 == 0 )
F_29 ( V_53 , '-' ) ;
F_29 ( V_53 , '\n' ) ;
return 0 ;
}
static int F_30 ( struct V_60 * V_60 , struct V_32 * V_32 )
{
return F_31 ( V_32 , & V_61 ) ;
}
static T_1 F_32 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
if ( ! F_33 ( V_62 ) )
return - V_63 ;
return F_15 ( V_32 , V_33 , V_34 , V_35 , NULL , NULL ) ;
}
static void F_34 ( void )
{
int V_38 ;
struct V_64 * V_65 ;
struct V_1 V_66 ;
F_1 ( & V_66 ) ;
V_38 = F_35 ( NULL , V_67 , NULL , NULL , & V_66 ) ;
if ( V_38 != 0 )
F_36 ( V_68 L_2 ,
V_69 , __LINE__ , V_38 ) ;
V_65 = F_37 ( sizeof( struct V_64 ) , V_43 ) ;
if ( V_65 == NULL )
F_38 ( L_3 ) ;
V_65 -> V_70 . V_71 = NULL ;
V_65 -> V_72 = V_73 ;
V_65 -> type = V_74 ;
V_65 -> V_75 [ 0 ] = V_76 ;
for ( V_38 = 1 ; V_38 < V_77 ; V_38 ++ )
V_65 -> V_75 [ V_38 ] = V_78 ;
V_38 = F_39 ( V_65 , & V_66 ) ;
if ( V_38 != 0 ) {
F_36 ( V_68 L_4 ,
V_69 , __LINE__ , V_38 ) ;
F_18 ( V_65 ) ;
return;
}
V_38 = F_40 ( V_65 -> V_72 , NULL , NULL , NULL , & V_66 ) ;
if ( V_38 != 0 ) {
F_36 ( V_68 L_5 ,
V_69 , __LINE__ , V_38 ) ;
F_18 ( V_65 ) ;
return;
}
}
static void F_41 ( char * V_79 )
{
int V_38 ;
struct V_1 V_66 ;
F_1 ( & V_66 ) ;
if ( V_79 != NULL ) {
V_38 = F_35 ( V_79 , V_67 , NULL , NULL , & V_66 ) ;
if ( V_38 != 0 )
F_36 ( V_68 L_2 ,
V_69 , __LINE__ , V_38 ) ;
}
V_38 = F_42 ( V_80 , V_67 ,
NULL , NULL , & V_66 ) ;
if ( V_38 != 0 )
F_36 ( V_68 L_6 ,
V_69 , __LINE__ , V_38 ) ;
}
static void * F_43 ( struct V_52 * V_53 , T_4 * V_54 )
{
return F_19 ( V_53 , V_54 , & V_81 ) ;
}
static void * F_44 ( struct V_52 * V_53 , void * V_59 , T_4 * V_54 )
{
return F_21 ( V_53 , V_59 , V_54 , & V_81 ) ;
}
static int F_45 ( struct V_52 * V_53 , void * V_59 )
{
struct V_9 * V_18 = V_59 ;
struct V_24 * V_25 =
F_27 ( V_18 , struct V_24 , V_18 ) ;
struct V_82 * V_83 = V_25 -> V_84 ;
char * V_85 ;
char V_86 = '/' ;
int V_87 = 1 ;
int V_88 ;
unsigned char V_89 ;
if ( V_83 == NULL )
return 0 ;
F_28 ( V_53 , L_7 , ( char * ) & V_25 -> V_26 , V_83 -> V_90 ) ;
V_85 = V_83 -> V_91 ;
for ( V_88 = 0 ; V_88 < V_23 ; V_88 ++ )
for ( V_89 = 0x80 ; V_89 != 0 ; V_89 >>= 1 ) {
if ( V_89 & V_85 [ V_88 ] ) {
F_28 ( V_53 , L_8 , V_86 , V_87 ) ;
V_86 = ',' ;
}
V_87 ++ ;
}
F_29 ( V_53 , '\n' ) ;
return 0 ;
}
static int F_46 ( struct V_60 * V_60 , struct V_32 * V_32 )
{
return F_31 ( V_32 , & V_92 ) ;
}
static T_1 F_47 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
struct V_24 * V_25 ;
struct V_82 * V_83 = NULL ;
char V_93 [ V_23 ] ;
int V_94 ;
int V_87 ;
int V_95 ;
T_1 V_38 = - V_39 ;
char * V_19 = NULL ;
char * V_20 ;
int V_96 ;
int V_88 ;
if ( ! F_33 ( V_62 ) )
return - V_63 ;
if ( * V_35 != 0 )
return - V_39 ;
if ( V_34 < V_97 || V_34 > V_98 )
return - V_39 ;
V_19 = F_16 ( V_34 + 1 , V_43 ) ;
if ( V_19 == NULL )
return - V_44 ;
if ( F_17 ( V_19 , V_33 , V_34 ) != 0 ) {
V_38 = - V_45 ;
goto V_99;
}
if ( V_19 [ 0 ] == '-' ) {
V_38 = - V_39 ;
goto V_99;
}
V_19 [ V_34 ] = '\0' ;
V_20 = V_19 ;
F_7 ( & V_100 ) ;
V_25 = F_48 ( V_20 , 0 ) ;
if ( V_25 == NULL )
goto V_46;
V_20 += V_23 ;
V_96 = sscanf ( V_20 , L_9 , & V_94 ) ;
if ( V_96 != 1 || V_94 > V_101 )
goto V_46;
V_20 += V_102 ;
V_96 = sscanf ( V_20 , L_9 , & V_95 ) ;
if ( V_96 != 1 || V_95 > V_103 )
goto V_46;
if ( V_34 != ( V_97 + V_95 * V_102 ) )
goto V_46;
memset ( V_93 , 0 , sizeof( V_93 ) ) ;
for ( V_88 = 0 ; V_88 < V_95 ; V_88 ++ ) {
V_20 += V_102 ;
V_96 = sscanf ( V_20 , L_9 , & V_87 ) ;
if ( V_96 != 1 || V_87 > V_104 )
goto V_46;
F_49 ( V_87 , V_93 ) ;
}
if ( V_25 -> V_84 == NULL ) {
V_83 = F_16 ( sizeof( struct V_82 ) , V_43 ) ;
if ( V_83 == NULL ) {
V_38 = - V_44 ;
goto V_46;
}
}
F_50 ( & V_25 -> V_105 ) ;
if ( V_83 == NULL )
V_83 = V_25 -> V_84 ;
else
V_25 -> V_84 = V_83 ;
V_83 -> V_90 = V_94 ;
memcpy ( V_83 -> V_91 , V_93 , sizeof( V_93 ) ) ;
F_51 ( & V_25 -> V_105 ) ;
V_38 = V_34 ;
V_46:
F_10 ( & V_100 ) ;
V_99:
F_18 ( V_19 ) ;
return V_38 ;
}
static void * F_52 ( struct V_52 * V_53 , T_4 * V_54 )
{
return F_19 ( V_53 , V_54 , & V_106 ) ;
}
static void * F_53 ( struct V_52 * V_53 , void * V_59 , T_4 * V_54 )
{
return F_21 ( V_53 , V_59 , V_54 , & V_106 ) ;
}
static int F_54 ( struct V_52 * V_53 , void * V_59 )
{
struct V_9 * V_18 = V_59 ;
struct V_107 * V_25 =
F_27 ( V_18 , struct V_107 , V_18 ) ;
unsigned char * V_108 = ( char * ) & V_25 -> V_109 . V_110 . V_111 ;
int V_112 ;
T_5 V_113 = F_55 ( V_25 -> V_114 . V_111 ) ;
for ( V_112 = 0 ; V_113 ; V_113 <<= 1 , V_112 ++ ) ;
F_28 ( V_53 , L_10 ,
V_108 [ 0 ] , V_108 [ 1 ] , V_108 [ 2 ] , V_108 [ 3 ] , V_112 , V_25 -> V_115 ) ;
return 0 ;
}
static int F_56 ( struct V_60 * V_60 , struct V_32 * V_32 )
{
return F_31 ( V_32 , & V_116 ) ;
}
static void F_57 ( struct V_107 * V_117 )
{
struct V_107 * V_89 , * V_118 ;
if ( F_20 ( & V_106 ) ) {
F_9 ( & V_117 -> V_18 , & V_106 ) ;
return;
}
V_89 = F_58 ( V_106 . V_58 ,
struct V_107 , V_18 ) ;
if ( V_117 -> V_114 . V_111 > V_89 -> V_114 . V_111 ) {
F_9 ( & V_117 -> V_18 , & V_106 ) ;
return;
}
F_8 (m, &smk_netlbladdr_list, list) {
if ( F_22 ( & V_89 -> V_18 , & V_106 ) ) {
F_9 ( & V_117 -> V_18 , & V_89 -> V_18 ) ;
return;
}
V_118 = F_58 ( V_89 -> V_18 . V_58 ,
struct V_107 , V_18 ) ;
if ( V_117 -> V_114 . V_111 > V_118 -> V_114 . V_111 ) {
F_9 ( & V_117 -> V_18 , & V_89 -> V_18 ) ;
return;
}
}
}
static T_1 F_59 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
struct V_107 * V_25 ;
struct V_119 V_120 ;
char V_22 [ V_23 ] ;
char * V_13 ;
char V_19 [ V_121 + 1 ] ;
char * V_122 = ( char * ) & V_120 . V_110 . V_111 ;
int V_38 ;
struct V_1 V_123 ;
struct V_124 V_125 ;
unsigned int V_89 ;
int V_14 ;
T_5 V_126 = ( 1 << 31 ) ;
T_6 V_127 ;
T_5 V_113 ;
if ( ! F_33 ( V_62 ) )
return - V_63 ;
if ( * V_35 != 0 )
return - V_39 ;
if ( V_34 < V_128 || V_34 > V_121 )
return - V_39 ;
if ( F_17 ( V_19 , V_33 , V_34 ) != 0 )
return - V_45 ;
V_19 [ V_34 ] = '\0' ;
V_38 = sscanf ( V_19 , L_11 ,
& V_122 [ 0 ] , & V_122 [ 1 ] , & V_122 [ 2 ] , & V_122 [ 3 ] , & V_89 , V_22 ) ;
if ( V_38 != 6 ) {
V_38 = sscanf ( V_19 , L_12 ,
& V_122 [ 0 ] , & V_122 [ 1 ] , & V_122 [ 2 ] , & V_122 [ 3 ] , V_22 ) ;
if ( V_38 != 5 )
return - V_39 ;
V_89 = V_129 ;
}
if ( V_89 > V_129 )
return - V_39 ;
if ( V_22 [ 0 ] != '-' ) {
V_13 = F_12 ( V_22 , 0 ) ;
if ( V_13 == NULL )
return - V_39 ;
} else {
if ( strcmp ( V_22 , V_130 ) == 0 )
V_13 = ( char * ) V_130 ;
else
return - V_39 ;
}
for ( V_113 = 0 ; V_89 > 0 ; V_89 -- ) {
V_113 |= V_126 ;
V_126 >>= 1 ;
}
V_125 . V_111 = F_60 ( V_113 ) ;
V_120 . V_110 . V_111 &= V_125 . V_111 ;
F_7 ( & V_131 ) ;
V_127 = V_120 . V_110 . V_111 ;
V_14 = 0 ;
F_8 (skp, &smk_netlbladdr_list, list) {
if ( V_25 -> V_109 . V_110 . V_111 == V_127 &&
V_25 -> V_114 . V_111 == V_125 . V_111 ) {
V_14 = 1 ;
break;
}
}
F_1 ( & V_123 ) ;
if ( V_14 == 0 ) {
V_25 = F_16 ( sizeof( * V_25 ) , V_43 ) ;
if ( V_25 == NULL )
V_38 = - V_44 ;
else {
V_38 = 0 ;
V_25 -> V_109 . V_110 . V_111 = V_120 . V_110 . V_111 ;
V_25 -> V_114 . V_111 = V_125 . V_111 ;
V_25 -> V_115 = V_13 ;
F_57 ( V_25 ) ;
}
} else {
if ( V_25 -> V_115 != V_130 )
V_38 = F_61 ( & V_132 , NULL ,
& V_25 -> V_109 . V_110 , & V_25 -> V_114 ,
V_67 , & V_123 ) ;
else
V_38 = 0 ;
V_25 -> V_115 = V_13 ;
}
if ( V_38 == 0 && V_13 != V_130 )
V_38 = F_62 ( & V_132 , NULL ,
& V_25 -> V_109 . V_110 , & V_25 -> V_114 , V_67 ,
F_4 ( V_25 -> V_115 ) , & V_123 ) ;
if ( V_38 == 0 )
V_38 = V_34 ;
F_10 ( & V_131 ) ;
return V_38 ;
}
static T_1 F_63 ( struct V_32 * V_133 , char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
char V_134 [ 80 ] ;
T_1 V_38 ;
if ( * V_35 != 0 )
return 0 ;
sprintf ( V_134 , L_9 , V_73 ) ;
V_38 = F_64 ( V_33 , V_34 , V_35 , V_134 , strlen ( V_134 ) ) ;
return V_38 ;
}
static T_1 F_65 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
char V_134 [ 80 ] ;
int V_88 ;
if ( ! F_33 ( V_62 ) )
return - V_63 ;
if ( V_34 >= sizeof( V_134 ) || V_34 == 0 )
return - V_39 ;
if ( F_17 ( V_134 , V_33 , V_34 ) != 0 )
return - V_45 ;
V_134 [ V_34 ] = '\0' ;
if ( sscanf ( V_134 , L_9 , & V_88 ) != 1 )
return - V_39 ;
V_73 = V_88 ;
F_34 () ;
return V_34 ;
}
static T_1 F_66 ( struct V_32 * V_133 , char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
char V_134 [ 80 ] ;
T_1 V_38 ;
if ( * V_35 != 0 )
return 0 ;
sprintf ( V_134 , L_9 , V_135 ) ;
V_38 = F_64 ( V_33 , V_34 , V_35 , V_134 , strlen ( V_134 ) ) ;
return V_38 ;
}
static T_1 F_67 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
char V_134 [ 80 ] ;
int V_88 ;
if ( ! F_33 ( V_62 ) )
return - V_63 ;
if ( V_34 >= sizeof( V_134 ) || V_34 == 0 )
return - V_39 ;
if ( F_17 ( V_134 , V_33 , V_34 ) != 0 )
return - V_45 ;
V_134 [ V_34 ] = '\0' ;
if ( sscanf ( V_134 , L_9 , & V_88 ) != 1 )
return - V_39 ;
V_135 = V_88 ;
return V_34 ;
}
static T_1 F_68 ( struct V_32 * V_133 , char T_2 * V_33 ,
T_3 V_136 , T_4 * V_35 )
{
T_1 V_38 ;
int V_137 ;
if ( * V_35 != 0 )
return 0 ;
F_7 ( & V_138 ) ;
V_137 = strlen ( V_80 ) + 1 ;
if ( V_136 >= V_137 )
V_38 = F_64 ( V_33 , V_136 , V_35 ,
V_80 , V_137 ) ;
else
V_38 = - V_39 ;
F_10 ( & V_138 ) ;
return V_38 ;
}
static T_1 F_69 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
char V_139 [ V_23 ] ;
char * V_79 ;
char * V_22 ;
if ( ! F_33 ( V_62 ) )
return - V_63 ;
if ( V_34 >= V_23 )
return - V_39 ;
if ( F_17 ( V_139 , V_33 , V_34 ) != 0 )
return - V_45 ;
V_22 = F_12 ( V_139 , V_34 ) ;
if ( V_22 == NULL )
return - V_39 ;
F_7 ( & V_138 ) ;
V_79 = V_80 ;
V_80 = V_22 ;
F_41 ( V_79 ) ;
F_10 ( & V_138 ) ;
return V_34 ;
}
static T_1 F_70 ( struct V_32 * V_133 , char T_2 * V_33 ,
T_3 V_136 , T_4 * V_35 )
{
char * V_22 = L_13 ;
T_1 V_38 = - V_39 ;
int V_137 ;
if ( * V_35 != 0 )
return 0 ;
if ( V_140 != NULL )
V_22 = V_140 ;
V_137 = strlen ( V_22 ) + 1 ;
if ( V_136 >= V_137 )
V_38 = F_64 ( V_33 , V_136 , V_35 , V_22 , V_137 ) ;
return V_38 ;
}
static T_1 F_71 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
char V_139 [ V_23 ] ;
char * V_13 = F_72 ( V_4 -> V_141 -> V_142 ) ;
if ( ! F_33 ( V_62 ) )
return - V_63 ;
if ( V_140 != NULL && V_140 != V_13 )
return - V_63 ;
if ( V_34 >= V_23 )
return - V_39 ;
if ( F_17 ( V_139 , V_33 , V_34 ) != 0 )
return - V_45 ;
V_140 = F_12 ( V_139 , V_34 ) ;
return V_34 ;
}
static T_1 F_73 ( struct V_32 * V_133 , char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
char V_134 [ 32 ] ;
T_1 V_38 ;
if ( * V_35 != 0 )
return 0 ;
sprintf ( V_134 , L_14 , V_143 ) ;
V_38 = F_64 ( V_33 , V_34 , V_35 , V_134 , strlen ( V_134 ) ) ;
return V_38 ;
}
static T_1 F_74 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
char V_134 [ 32 ] ;
int V_88 ;
if ( ! F_33 ( V_62 ) )
return - V_63 ;
if ( V_34 >= sizeof( V_134 ) || V_34 == 0 )
return - V_39 ;
if ( F_17 ( V_134 , V_33 , V_34 ) != 0 )
return - V_45 ;
V_134 [ V_34 ] = '\0' ;
if ( sscanf ( V_134 , L_9 , & V_88 ) != 1 )
return - V_39 ;
if ( V_88 < 0 || V_88 > 3 )
return - V_39 ;
V_143 = V_88 ;
return V_34 ;
}
static void * F_75 ( struct V_52 * V_53 , T_4 * V_54 )
{
struct V_144 * V_145 = F_76 () ;
return F_19 ( V_53 , V_54 , & V_145 -> V_48 ) ;
}
static void * F_77 ( struct V_52 * V_53 , void * V_59 , T_4 * V_54 )
{
struct V_144 * V_145 = F_76 () ;
return F_21 ( V_53 , V_59 , V_54 , & V_145 -> V_48 ) ;
}
static int F_78 ( struct V_52 * V_53 , void * V_59 )
{
struct V_9 * V_18 = V_59 ;
struct V_7 * V_8 =
F_27 ( V_18 , struct V_7 , V_18 ) ;
F_28 ( V_53 , L_1 , ( char * ) V_8 -> V_16 ,
( char * ) V_8 -> V_15 ) ;
F_29 ( V_53 , ' ' ) ;
if ( V_8 -> V_17 & V_27 )
F_29 ( V_53 , 'r' ) ;
if ( V_8 -> V_17 & V_28 )
F_29 ( V_53 , 'w' ) ;
if ( V_8 -> V_17 & V_29 )
F_29 ( V_53 , 'x' ) ;
if ( V_8 -> V_17 & V_30 )
F_29 ( V_53 , 'a' ) ;
if ( V_8 -> V_17 & V_31 )
F_29 ( V_53 , 't' ) ;
if ( V_8 -> V_17 == 0 )
F_29 ( V_53 , '-' ) ;
F_29 ( V_53 , '\n' ) ;
return 0 ;
}
static int F_79 ( struct V_60 * V_60 , struct V_32 * V_32 )
{
return F_31 ( V_32 , & V_146 ) ;
}
static T_1 F_80 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
struct V_144 * V_145 = F_76 () ;
return F_15 ( V_32 , V_33 , V_34 , V_35 , & V_145 -> V_48 ,
& V_145 -> V_49 ) ;
}
static T_1 F_81 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
struct V_7 V_20 ;
char * V_19 ;
int V_147 ;
V_19 = F_82 ( V_32 , V_33 , V_34 ) ;
if ( F_83 ( V_19 ) )
return F_84 ( V_19 ) ;
if ( V_34 < V_42 || F_11 ( V_19 , & V_20 , 0 ) )
return - V_39 ;
V_147 = V_17 ( V_20 . V_16 , V_20 . V_15 , V_20 . V_17 ,
NULL ) ;
V_19 [ 0 ] = V_147 == 0 ? '1' : '0' ;
V_19 [ 1 ] = '\0' ;
F_85 ( V_32 , 2 ) ;
return V_42 ;
}
static int F_86 ( struct V_148 * V_149 , void * V_19 , int V_150 )
{
int V_38 ;
struct V_60 * V_151 ;
static struct V_152 V_153 [] = {
[ V_154 ] = {
L_15 , & V_155 , V_156 | V_157 } ,
[ V_158 ] = {
L_16 , & V_159 , V_156 | V_157 } ,
[ V_160 ] = {
L_17 , & V_161 , V_156 | V_157 } ,
[ V_162 ] = {
L_18 , & V_163 , V_156 | V_157 } ,
[ V_164 ] = {
L_19 , & V_165 , V_156 | V_157 } ,
[ V_166 ] = {
L_20 , & V_167 , V_156 | V_157 } ,
[ V_168 ] = {
L_21 , & V_169 , V_156 | V_157 } ,
[ V_170 ] = {
L_22 , & V_171 , V_156 | V_157 } ,
[ V_172 ] = {
L_23 , & V_173 , V_156 | V_174 } ,
[ V_175 ] = {
L_24 , & V_176 , V_156 | V_174 } ,
{ L_13 }
} ;
V_38 = F_87 ( V_149 , V_177 , V_153 ) ;
if ( V_38 != 0 ) {
F_36 ( V_178 L_25 ,
V_69 , V_38 ) ;
return V_38 ;
}
V_151 = V_149 -> V_179 -> V_180 ;
V_151 -> V_181 = F_88 ( V_182 . V_26 ) ;
return 0 ;
}
static struct V_183 * F_89 ( struct V_184 * V_185 ,
int V_186 , const char * V_187 , void * V_19 )
{
return F_90 ( V_185 , V_186 , V_19 , F_86 ) ;
}
static int T_7 F_91 ( void )
{
int V_188 ;
if ( ! F_92 ( & V_189 ) )
return 0 ;
V_188 = F_93 ( & V_190 ) ;
if ( ! V_188 ) {
V_191 = F_94 ( & V_190 ) ;
if ( F_83 ( V_191 ) ) {
F_36 ( V_178 L_26 ) ;
V_188 = F_84 ( V_191 ) ;
V_191 = NULL ;
}
}
F_34 () ;
F_41 ( NULL ) ;
F_95 ( & V_182 . V_49 ) ;
F_95 ( & V_192 . V_49 ) ;
F_95 ( & V_193 . V_49 ) ;
F_95 ( & V_194 . V_49 ) ;
F_95 ( & V_195 . V_49 ) ;
F_95 ( & V_196 . V_49 ) ;
F_96 ( & V_182 . V_48 ) ;
F_96 ( & V_192 . V_48 ) ;
F_96 ( & V_193 . V_48 ) ;
F_96 ( & V_194 . V_48 ) ;
F_96 ( & V_195 . V_48 ) ;
F_96 ( & V_196 . V_48 ) ;
return V_188 ;
}
