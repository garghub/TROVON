static inline void F_1 ( unsigned int V_1 , char * V_2 )
{
if ( V_1 == 0 || V_1 > ( V_3 * 8 ) )
return;
V_2 [ ( V_1 - 1 ) / 8 ] |= 0x80 >> ( ( V_1 - 1 ) % 8 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 () ;
V_5 -> V_8 = F_4 ( V_9 ) ;
V_5 -> V_10 = F_5 ( V_9 ) ;
V_5 -> V_11 = V_7 -> V_12 ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_18 , int V_19 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 = 0 ;
int V_25 = 0 ;
F_7 ( V_18 ) ;
F_8 (sp, rule_list, list) {
if ( V_21 -> V_26 == V_14 -> V_26 &&
V_21 -> V_27 == V_14 -> V_27 ) {
V_24 = 1 ;
V_21 -> V_28 |= V_14 -> V_29 ;
V_21 -> V_28 &= ~ V_14 -> V_30 ;
break;
}
}
if ( V_24 == 0 ) {
V_21 = F_9 ( sizeof( * V_21 ) , V_31 ) ;
if ( V_21 == NULL ) {
V_25 = - V_32 ;
goto V_33;
}
V_21 -> V_27 = V_14 -> V_27 ;
V_21 -> V_26 = V_14 -> V_26 ;
V_21 -> V_28 = V_14 -> V_29 & ~ V_14 -> V_30 ;
F_10 ( & V_21 -> V_34 , V_16 ) ;
if ( V_19 ) {
V_23 = F_9 ( sizeof( * V_23 ) , V_31 ) ;
if ( V_23 != NULL ) {
V_23 -> V_35 = V_21 ;
F_10 ( & V_23 -> V_34 , & V_36 ) ;
} else
V_25 = - V_32 ;
}
}
V_33:
F_11 ( V_18 ) ;
return V_25 ;
}
static int F_12 ( const char * string )
{
int V_37 = 0 ;
const char * V_38 ;
for ( V_38 = string ; ; V_38 ++ )
switch ( * V_38 ) {
case '-' :
break;
case 'r' :
case 'R' :
V_37 |= V_39 ;
break;
case 'w' :
case 'W' :
V_37 |= V_40 ;
break;
case 'x' :
case 'X' :
V_37 |= V_41 ;
break;
case 'a' :
case 'A' :
V_37 |= V_42 ;
break;
case 't' :
case 'T' :
V_37 |= V_43 ;
break;
case 'l' :
case 'L' :
V_37 |= V_44 ;
break;
default:
return V_37 ;
}
}
static int F_13 ( const char * V_45 , const char * V_46 ,
const char * V_47 , const char * V_48 ,
struct V_13 * V_49 , int V_50 ,
int V_51 )
{
const char * V_38 ;
struct V_6 * V_7 ;
if ( V_50 ) {
V_49 -> V_27 = F_14 ( V_45 , V_51 ) ;
if ( V_49 -> V_27 == NULL )
return - 1 ;
V_49 -> V_26 = F_15 ( V_46 , V_51 ) ;
if ( V_49 -> V_26 == NULL )
return - 1 ;
} else {
V_38 = F_16 ( V_45 , V_51 ) ;
if ( V_38 == NULL )
return - 1 ;
V_7 = F_17 ( V_38 ) ;
F_18 ( V_38 ) ;
if ( V_7 == NULL )
return - 1 ;
V_49 -> V_27 = V_7 ;
V_38 = F_16 ( V_46 , V_51 ) ;
if ( V_38 == NULL )
return - 1 ;
V_7 = F_17 ( V_38 ) ;
F_18 ( V_38 ) ;
if ( V_7 == NULL )
return - 1 ;
V_49 -> V_26 = V_7 -> V_52 ;
}
V_49 -> V_29 = F_12 ( V_47 ) ;
if ( V_48 )
V_49 -> V_30 = F_12 ( V_48 ) ;
else
V_49 -> V_30 = ~ V_49 -> V_29 ;
return 0 ;
}
static int F_19 ( const char * V_53 , struct V_13 * V_49 ,
int V_50 )
{
int V_25 ;
V_25 = F_13 ( V_53 , V_53 + V_54 ,
V_53 + V_54 + V_54 , NULL , V_49 ,
V_50 , V_54 ) ;
return V_25 ;
}
static T_1 F_20 ( char * V_53 , struct V_13 * V_49 ,
int V_50 , int V_55 )
{
T_1 V_56 = 0 ;
char * V_57 [ 4 ] ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_55 ; ++ V_58 ) {
while ( isspace ( V_53 [ V_56 ] ) )
V_53 [ V_56 ++ ] = '\0' ;
if ( V_53 [ V_56 ] == '\0' )
return - 1 ;
V_57 [ V_58 ] = V_53 + V_56 ;
while ( V_53 [ V_56 ] && ! isspace ( V_53 [ V_56 ] ) )
++ V_56 ;
}
while ( isspace ( V_53 [ V_56 ] ) )
V_53 [ V_56 ++ ] = '\0' ;
while ( V_58 < 4 )
V_57 [ V_58 ++ ] = NULL ;
if ( F_13 ( V_57 [ 0 ] , V_57 [ 1 ] , V_57 [ 2 ] , V_57 [ 3 ] , V_49 , V_50 , 0 ) )
return - 1 ;
return V_56 ;
}
static T_1 F_21 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 ,
struct V_15 * V_16 ,
struct V_17 * V_18 , int V_63 )
{
struct V_13 V_49 ;
char * V_53 ;
int V_25 ;
int V_64 = 0 ;
int V_55 ;
T_1 V_56 = 0 ;
if ( * V_62 != 0 )
return - V_65 ;
if ( V_63 == V_66 ) {
if ( V_61 < V_67 || V_61 > V_68 )
return - V_65 ;
} else {
if ( V_61 >= V_69 ) {
V_61 = V_69 - 1 ;
V_64 = 1 ;
}
}
V_53 = F_22 ( V_61 + 1 , V_31 ) ;
if ( V_53 == NULL )
return - V_32 ;
if ( F_23 ( V_53 , V_60 , V_61 ) != 0 ) {
V_25 = - V_70 ;
goto V_33;
}
if ( V_64 ) {
while ( V_61 > 0 && ( V_53 [ V_61 - 1 ] != '\n' ) )
-- V_61 ;
if ( V_61 == 0 ) {
V_25 = - V_65 ;
goto V_33;
}
}
V_53 [ V_61 ] = '\0' ;
V_55 = ( V_63 == V_71 ? 4 : 3 ) ;
while ( V_56 < V_61 ) {
if ( V_63 == V_66 ) {
V_25 = F_19 ( V_53 , & V_49 , 1 ) ;
if ( V_25 != 0 ) {
V_25 = - V_65 ;
goto V_33;
}
V_56 = V_61 ;
} else {
V_25 = F_20 ( V_53 + V_56 , & V_49 , 1 , V_55 ) ;
if ( V_25 <= 0 ) {
V_25 = - V_65 ;
goto V_33;
}
V_56 += V_25 ;
}
if ( V_16 == NULL )
V_25 = F_6 ( & V_49 , & V_49 . V_27 -> V_72 ,
& V_49 . V_27 -> V_73 , 1 ) ;
else
V_25 = F_6 ( & V_49 , V_16 , V_18 , 0 ) ;
if ( V_25 )
goto V_33;
}
V_25 = V_56 ;
V_33:
F_18 ( V_53 ) ;
return V_25 ;
}
static void * F_24 ( struct V_74 * V_75 , T_4 * V_76 ,
struct V_15 * V_77 )
{
struct V_15 * V_34 ;
if ( V_75 -> V_78 == 0 )
V_75 -> V_79 = V_77 ;
if ( V_75 -> V_79 == NULL )
return NULL ;
V_34 = V_75 -> V_79 ;
if ( F_25 ( V_34 ) )
return NULL ;
if ( V_75 -> V_78 == 0 )
return V_34 -> V_80 ;
return V_34 ;
}
static void * F_26 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 ,
struct V_15 * V_77 )
{
struct V_15 * V_34 = V_81 ;
if ( F_27 ( V_34 , V_77 ) ) {
V_75 -> V_79 = NULL ;
return NULL ;
}
V_75 -> V_79 = V_34 -> V_80 ;
return V_34 -> V_80 ;
}
static void F_28 ( struct V_74 * V_75 , void * V_81 )
{
}
static void F_29 ( struct V_74 * V_75 , struct V_20 * V_14 , int V_82 )
{
if ( strlen ( V_14 -> V_27 -> V_52 ) >= V_82 ||
strlen ( V_14 -> V_26 ) >= V_82 )
return;
if ( V_14 -> V_28 == 0 )
return;
F_30 ( V_75 , L_1 , V_14 -> V_27 -> V_52 , V_14 -> V_26 ) ;
F_31 ( V_75 , ' ' ) ;
if ( V_14 -> V_28 & V_39 )
F_31 ( V_75 , 'r' ) ;
if ( V_14 -> V_28 & V_40 )
F_31 ( V_75 , 'w' ) ;
if ( V_14 -> V_28 & V_41 )
F_31 ( V_75 , 'x' ) ;
if ( V_14 -> V_28 & V_42 )
F_31 ( V_75 , 'a' ) ;
if ( V_14 -> V_28 & V_43 )
F_31 ( V_75 , 't' ) ;
if ( V_14 -> V_28 & V_44 )
F_31 ( V_75 , 'l' ) ;
F_31 ( V_75 , '\n' ) ;
}
static void * F_32 ( struct V_74 * V_75 , T_4 * V_76 )
{
return F_24 ( V_75 , V_76 , & V_36 ) ;
}
static void * F_33 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 )
{
return F_26 ( V_75 , V_81 , V_76 , & V_36 ) ;
}
static int F_34 ( struct V_74 * V_75 , void * V_81 )
{
struct V_15 * V_34 = V_81 ;
struct V_22 * V_23 =
F_35 ( V_34 , struct V_22 , V_34 ) ;
F_29 ( V_75 , V_23 -> V_35 , V_54 ) ;
return 0 ;
}
static int F_36 ( struct V_83 * V_83 , struct V_59 * V_59 )
{
return F_37 ( V_59 , & V_84 ) ;
}
static T_1 F_38 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
if ( ! F_39 ( V_85 ) )
return - V_86 ;
return F_21 ( V_59 , V_60 , V_61 , V_62 , NULL , NULL ,
V_66 ) ;
}
static void F_40 ( void )
{
int V_25 ;
struct V_87 * V_88 ;
struct V_4 V_89 ;
F_2 ( & V_89 ) ;
V_25 = F_41 ( NULL , V_90 , NULL , NULL , & V_89 ) ;
if ( V_25 != 0 )
F_42 ( V_91 L_2 ,
V_92 , __LINE__ , V_25 ) ;
V_88 = F_22 ( sizeof( struct V_87 ) , V_31 ) ;
if ( V_88 == NULL )
F_43 ( L_3 ) ;
V_88 -> V_93 . V_94 = NULL ;
V_88 -> V_95 = V_96 ;
V_88 -> type = V_97 ;
V_88 -> V_98 [ 0 ] = V_99 ;
for ( V_25 = 1 ; V_25 < V_100 ; V_25 ++ )
V_88 -> V_98 [ V_25 ] = V_101 ;
V_25 = F_44 ( V_88 , & V_89 ) ;
if ( V_25 != 0 ) {
F_42 ( V_91 L_4 ,
V_92 , __LINE__ , V_25 ) ;
F_18 ( V_88 ) ;
return;
}
V_25 = F_45 ( V_88 -> V_95 , NULL , NULL , NULL , & V_89 ) ;
if ( V_25 != 0 ) {
F_42 ( V_91 L_5 ,
V_92 , __LINE__ , V_25 ) ;
F_18 ( V_88 ) ;
return;
}
}
static void F_46 ( char * V_102 )
{
int V_25 ;
struct V_4 V_89 ;
F_2 ( & V_89 ) ;
if ( V_102 != NULL ) {
V_25 = F_41 ( V_102 , V_90 , NULL , NULL , & V_89 ) ;
if ( V_25 != 0 )
F_42 ( V_91 L_2 ,
V_92 , __LINE__ , V_25 ) ;
}
if ( V_103 == NULL )
V_103 = & V_104 ;
V_25 = F_47 ( V_103 -> V_52 , V_90 ,
NULL , NULL , & V_89 ) ;
if ( V_25 != 0 )
F_42 ( V_91 L_6 ,
V_92 , __LINE__ , V_25 ) ;
}
static void * F_48 ( struct V_74 * V_75 , T_4 * V_76 )
{
return F_24 ( V_75 , V_76 , & V_105 ) ;
}
static void * F_49 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 )
{
return F_26 ( V_75 , V_81 , V_76 , & V_105 ) ;
}
static int F_50 ( struct V_74 * V_75 , void * V_81 )
{
struct V_15 * V_34 = V_81 ;
struct V_6 * V_7 =
F_35 ( V_34 , struct V_6 , V_34 ) ;
struct V_106 * V_107 = V_7 -> V_108 . V_109 . V_110 . V_1 ;
char V_111 = '/' ;
int V_58 ;
if ( strlen ( V_7 -> V_52 ) >= V_54 )
return 0 ;
F_30 ( V_75 , L_7 , V_7 -> V_52 , V_7 -> V_108 . V_109 . V_110 . V_112 ) ;
for ( V_58 = F_51 ( V_107 , 0 ) ; V_58 >= 0 ;
V_58 = F_51 ( V_107 , V_58 + 1 ) ) {
F_30 ( V_75 , L_8 , V_111 , V_58 ) ;
V_111 = ',' ;
}
F_31 ( V_75 , '\n' ) ;
return 0 ;
}
static int F_52 ( struct V_83 * V_83 , struct V_59 * V_59 )
{
return F_37 ( V_59 , & V_113 ) ;
}
static T_1 F_53 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 , int V_63 )
{
struct V_6 * V_7 ;
struct V_114 V_115 ;
char V_116 [ V_3 ] ;
int V_117 ;
unsigned int V_1 ;
int V_118 ;
T_1 V_25 = - V_65 ;
char * V_53 = NULL ;
char * V_49 ;
int V_119 ;
int V_58 ;
if ( ! F_39 ( V_85 ) )
return - V_86 ;
if ( * V_62 != 0 )
return - V_65 ;
if ( V_63 == V_66 &&
( V_61 < V_120 || V_61 > V_121 ) )
return - V_65 ;
V_53 = F_9 ( V_61 + 1 , V_31 ) ;
if ( V_53 == NULL )
return - V_32 ;
if ( F_23 ( V_53 , V_60 , V_61 ) != 0 ) {
V_25 = - V_70 ;
goto V_122;
}
V_53 [ V_61 ] = '\0' ;
V_49 = V_53 ;
F_7 ( & V_123 ) ;
V_7 = F_14 ( V_49 , 0 ) ;
if ( V_7 == NULL )
goto V_33;
if ( V_63 == V_66 )
V_49 += V_54 ;
else
V_49 += strlen ( V_7 -> V_52 ) + 1 ;
V_119 = sscanf ( V_49 , L_9 , & V_117 ) ;
if ( V_119 != 1 || V_117 > V_124 )
goto V_33;
V_49 += V_125 ;
V_119 = sscanf ( V_49 , L_9 , & V_118 ) ;
if ( V_119 != 1 || V_118 > V_126 )
goto V_33;
if ( V_63 == V_66 &&
V_61 != ( V_120 + V_118 * V_125 ) )
goto V_33;
memset ( V_116 , 0 , sizeof( V_116 ) ) ;
for ( V_58 = 0 ; V_58 < V_118 ; V_58 ++ ) {
V_49 += V_125 ;
V_119 = sscanf ( V_49 , L_10 , & V_1 ) ;
if ( V_119 != 1 || V_1 > V_126 )
goto V_33;
F_1 ( V_1 , V_116 ) ;
}
V_25 = F_54 ( V_117 , V_116 , & V_115 , V_3 ) ;
if ( V_25 >= 0 ) {
F_55 ( V_7 -> V_108 . V_109 . V_110 . V_1 ) ;
V_7 -> V_108 . V_109 . V_110 . V_1 = V_115 . V_109 . V_110 . V_1 ;
V_7 -> V_108 . V_109 . V_110 . V_112 = V_115 . V_109 . V_110 . V_112 ;
V_25 = V_61 ;
}
V_33:
F_11 ( & V_123 ) ;
V_122:
F_18 ( V_53 ) ;
return V_25 ;
}
static T_1 F_56 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
return F_53 ( V_59 , V_60 , V_61 , V_62 , V_66 ) ;
}
static int F_57 ( struct V_74 * V_75 , void * V_81 )
{
struct V_15 * V_34 = V_81 ;
struct V_6 * V_7 =
F_35 ( V_34 , struct V_6 , V_34 ) ;
struct V_106 * V_107 = V_7 -> V_108 . V_109 . V_110 . V_1 ;
char V_111 = '/' ;
int V_58 ;
F_30 ( V_75 , L_7 , V_7 -> V_52 , V_7 -> V_108 . V_109 . V_110 . V_112 ) ;
for ( V_58 = F_51 ( V_107 , 0 ) ; V_58 >= 0 ;
V_58 = F_51 ( V_107 , V_58 + 1 ) ) {
F_30 ( V_75 , L_8 , V_111 , V_58 ) ;
V_111 = ',' ;
}
F_31 ( V_75 , '\n' ) ;
return 0 ;
}
static int F_58 ( struct V_83 * V_83 , struct V_59 * V_59 )
{
return F_37 ( V_59 , & V_127 ) ;
}
static T_1 F_59 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
return F_53 ( V_59 , V_60 , V_61 , V_62 , V_128 ) ;
}
static void * F_60 ( struct V_74 * V_75 , T_4 * V_76 )
{
return F_24 ( V_75 , V_76 , & V_129 ) ;
}
static void * F_61 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 )
{
return F_26 ( V_75 , V_81 , V_76 , & V_129 ) ;
}
static int F_62 ( struct V_74 * V_75 , void * V_81 )
{
struct V_15 * V_34 = V_81 ;
struct V_130 * V_7 =
F_35 ( V_34 , struct V_130 , V_34 ) ;
unsigned char * V_131 = ( char * ) & V_7 -> V_132 . V_133 . V_134 ;
int V_135 ;
T_5 V_136 = F_63 ( V_7 -> V_137 . V_134 ) ;
for ( V_135 = 0 ; V_136 ; V_136 <<= 1 , V_135 ++ ) ;
F_30 ( V_75 , L_11 ,
V_131 [ 0 ] , V_131 [ 1 ] , V_131 [ 2 ] , V_131 [ 3 ] , V_135 , V_7 -> V_138 ) ;
return 0 ;
}
static int F_64 ( struct V_83 * V_83 , struct V_59 * V_59 )
{
return F_37 ( V_59 , & V_139 ) ;
}
static void F_65 ( struct V_130 * V_140 )
{
struct V_130 * V_141 , * V_142 ;
if ( F_25 ( & V_129 ) ) {
F_10 ( & V_140 -> V_34 , & V_129 ) ;
return;
}
V_141 = F_66 ( V_129 . V_80 ,
struct V_130 , V_34 ) ;
if ( V_140 -> V_137 . V_134 > V_141 -> V_137 . V_134 ) {
F_10 ( & V_140 -> V_34 , & V_129 ) ;
return;
}
F_8 (m, &smk_netlbladdr_list, list) {
if ( F_27 ( & V_141 -> V_34 , & V_129 ) ) {
F_10 ( & V_140 -> V_34 , & V_141 -> V_34 ) ;
return;
}
V_142 = F_66 ( V_141 -> V_34 . V_80 ,
struct V_130 , V_34 ) ;
if ( V_140 -> V_137 . V_134 > V_142 -> V_137 . V_134 ) {
F_10 ( & V_140 -> V_34 , & V_141 -> V_34 ) ;
return;
}
}
}
static T_1 F_67 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_130 * V_7 ;
struct V_143 V_144 ;
char * V_145 ;
char * V_21 ;
char * V_53 ;
char * V_146 = ( char * ) & V_144 . V_133 . V_134 ;
int V_25 ;
struct V_4 V_147 ;
struct V_148 V_149 ;
unsigned int V_141 ;
int V_24 ;
T_5 V_150 = ( 1 << 31 ) ;
T_6 V_151 ;
T_5 V_136 ;
if ( ! F_39 ( V_85 ) )
return - V_86 ;
if ( * V_62 != 0 )
return - V_65 ;
if ( V_61 < V_152 )
return - V_65 ;
V_53 = F_9 ( V_61 + 1 , V_31 ) ;
if ( V_53 == NULL )
return - V_32 ;
if ( F_23 ( V_53 , V_60 , V_61 ) != 0 ) {
V_25 = - V_70 ;
goto V_153;
}
V_145 = F_9 ( V_61 + 1 , V_31 ) ;
if ( V_145 == NULL ) {
V_25 = - V_32 ;
goto V_153;
}
V_53 [ V_61 ] = '\0' ;
V_25 = sscanf ( V_53 , L_12 ,
& V_146 [ 0 ] , & V_146 [ 1 ] , & V_146 [ 2 ] , & V_146 [ 3 ] , & V_141 , V_145 ) ;
if ( V_25 != 6 ) {
V_25 = sscanf ( V_53 , L_13 ,
& V_146 [ 0 ] , & V_146 [ 1 ] , & V_146 [ 2 ] , & V_146 [ 3 ] , V_145 ) ;
if ( V_25 != 5 ) {
V_25 = - V_65 ;
goto V_154;
}
V_141 = V_155 ;
}
if ( V_141 > V_155 ) {
V_25 = - V_65 ;
goto V_154;
}
if ( V_145 [ 0 ] != '-' ) {
V_21 = F_15 ( V_145 , 0 ) ;
if ( V_21 == NULL ) {
V_25 = - V_65 ;
goto V_154;
}
} else {
if ( strcmp ( V_145 , V_156 ) == 0 )
V_21 = ( char * ) V_156 ;
else {
V_25 = - V_65 ;
goto V_154;
}
}
for ( V_136 = 0 ; V_141 > 0 ; V_141 -- ) {
V_136 |= V_150 ;
V_150 >>= 1 ;
}
V_149 . V_134 = F_68 ( V_136 ) ;
V_144 . V_133 . V_134 &= V_149 . V_134 ;
F_7 ( & V_157 ) ;
V_151 = V_144 . V_133 . V_134 ;
V_24 = 0 ;
F_8 (skp, &smk_netlbladdr_list, list) {
if ( V_7 -> V_132 . V_133 . V_134 == V_151 &&
V_7 -> V_137 . V_134 == V_149 . V_134 ) {
V_24 = 1 ;
break;
}
}
F_2 ( & V_147 ) ;
if ( V_24 == 0 ) {
V_7 = F_9 ( sizeof( * V_7 ) , V_31 ) ;
if ( V_7 == NULL )
V_25 = - V_32 ;
else {
V_25 = 0 ;
V_7 -> V_132 . V_133 . V_134 = V_144 . V_133 . V_134 ;
V_7 -> V_137 . V_134 = V_149 . V_134 ;
V_7 -> V_138 = V_21 ;
F_65 ( V_7 ) ;
}
} else {
if ( V_7 -> V_138 != V_156 )
V_25 = F_69 ( & V_158 , NULL ,
& V_7 -> V_132 . V_133 , & V_7 -> V_137 ,
V_90 , & V_147 ) ;
else
V_25 = 0 ;
V_7 -> V_138 = V_21 ;
}
if ( V_25 == 0 && V_21 != V_156 )
V_25 = F_70 ( & V_158 , NULL ,
& V_7 -> V_132 . V_133 , & V_7 -> V_137 , V_90 ,
F_71 ( V_7 -> V_138 ) , & V_147 ) ;
if ( V_25 == 0 )
V_25 = V_61 ;
F_11 ( & V_157 ) ;
V_154:
F_18 ( V_145 ) ;
V_153:
F_18 ( V_53 ) ;
return V_25 ;
}
static T_1 F_72 ( struct V_59 * V_159 , char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_160 [ 80 ] ;
T_1 V_25 ;
if ( * V_62 != 0 )
return 0 ;
sprintf ( V_160 , L_9 , V_96 ) ;
V_25 = F_73 ( V_60 , V_61 , V_62 , V_160 , strlen ( V_160 ) ) ;
return V_25 ;
}
static T_1 F_74 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_160 [ 80 ] ;
int V_58 ;
if ( ! F_39 ( V_85 ) )
return - V_86 ;
if ( V_61 >= sizeof( V_160 ) || V_61 == 0 )
return - V_65 ;
if ( F_23 ( V_160 , V_60 , V_61 ) != 0 )
return - V_70 ;
V_160 [ V_61 ] = '\0' ;
if ( sscanf ( V_160 , L_9 , & V_58 ) != 1 )
return - V_65 ;
V_96 = V_58 ;
F_40 () ;
return V_61 ;
}
static T_1 F_75 ( struct V_59 * V_159 , char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_160 [ 80 ] ;
T_1 V_25 ;
if ( * V_62 != 0 )
return 0 ;
sprintf ( V_160 , L_9 , V_161 ) ;
V_25 = F_73 ( V_60 , V_61 , V_62 , V_160 , strlen ( V_160 ) ) ;
return V_25 ;
}
static T_1 F_76 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_6 * V_7 ;
char V_160 [ 80 ] ;
int V_58 ;
if ( ! F_39 ( V_85 ) )
return - V_86 ;
if ( V_61 >= sizeof( V_160 ) || V_61 == 0 )
return - V_65 ;
if ( F_23 ( V_160 , V_60 , V_61 ) != 0 )
return - V_70 ;
V_160 [ V_61 ] = '\0' ;
if ( sscanf ( V_160 , L_9 , & V_58 ) != 1 )
return - V_65 ;
if ( V_161 != V_58 ) {
F_7 ( & V_162 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_108 . V_109 . V_110 . V_112 ==
V_161 )
V_7 -> V_108 . V_109 . V_110 . V_112 = V_58 ;
V_161 = V_58 ;
F_11 ( & V_162 ) ;
}
return V_61 ;
}
static T_1 F_77 ( struct V_59 * V_159 , char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_160 [ 80 ] ;
T_1 V_25 ;
if ( * V_62 != 0 )
return 0 ;
sprintf ( V_160 , L_9 , V_163 ) ;
V_25 = F_73 ( V_60 , V_61 , V_62 , V_160 , strlen ( V_160 ) ) ;
return V_25 ;
}
static T_1 F_78 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_6 * V_7 ;
char V_160 [ 80 ] ;
int V_58 ;
if ( ! F_39 ( V_85 ) )
return - V_86 ;
if ( V_61 >= sizeof( V_160 ) || V_61 == 0 )
return - V_65 ;
if ( F_23 ( V_160 , V_60 , V_61 ) != 0 )
return - V_70 ;
V_160 [ V_61 ] = '\0' ;
if ( sscanf ( V_160 , L_9 , & V_58 ) != 1 )
return - V_65 ;
if ( V_163 != V_58 ) {
F_7 ( & V_162 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_108 . V_109 . V_110 . V_112 ==
V_163 )
V_7 -> V_108 . V_109 . V_110 . V_112 = V_58 ;
V_163 = V_58 ;
F_11 ( & V_162 ) ;
}
return V_61 ;
}
static T_1 F_79 ( struct V_59 * V_159 , char T_2 * V_60 ,
T_3 V_164 , T_4 * V_62 )
{
T_1 V_25 ;
int V_165 ;
if ( * V_62 != 0 )
return 0 ;
F_7 ( & V_166 ) ;
V_165 = strlen ( V_103 -> V_52 ) + 1 ;
if ( V_164 >= V_165 )
V_25 = F_73 ( V_60 , V_164 , V_62 ,
V_103 -> V_52 ,
V_165 ) ;
else
V_25 = - V_65 ;
F_11 ( & V_166 ) ;
return V_25 ;
}
static T_1 F_80 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_6 * V_7 ;
char * V_102 ;
char * V_53 ;
int V_25 = V_61 ;
if ( ! F_39 ( V_85 ) )
return - V_86 ;
V_53 = F_9 ( V_61 + 1 , V_31 ) ;
if ( V_53 == NULL )
return - V_32 ;
if ( F_23 ( V_53 , V_60 , V_61 ) != 0 ) {
V_25 = - V_70 ;
goto V_33;
}
V_7 = F_14 ( V_53 , V_61 ) ;
if ( V_7 == NULL ) {
V_25 = - V_65 ;
goto V_33;
}
F_7 ( & V_166 ) ;
V_102 = V_103 -> V_52 ;
V_103 = V_7 ;
F_46 ( V_102 ) ;
F_11 ( & V_166 ) ;
V_33:
F_18 ( V_53 ) ;
return V_25 ;
}
static T_1 F_81 ( struct V_59 * V_159 , char T_2 * V_60 ,
T_3 V_164 , T_4 * V_62 )
{
char * V_145 = L_14 ;
T_1 V_25 = - V_65 ;
int V_165 ;
if ( * V_62 != 0 )
return 0 ;
if ( V_167 != NULL )
V_145 = V_167 ;
V_165 = strlen ( V_145 ) + 1 ;
if ( V_164 >= V_165 )
V_25 = F_73 ( V_60 , V_164 , V_62 , V_145 , V_165 ) ;
return V_25 ;
}
static T_1 F_82 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char * V_53 ;
struct V_6 * V_7 = F_83 ( V_9 -> V_168 -> V_169 ) ;
int V_25 = V_61 ;
if ( ! F_39 ( V_85 ) )
return - V_86 ;
if ( V_167 != NULL && V_167 != V_7 -> V_52 )
return - V_86 ;
V_53 = F_9 ( V_61 , V_31 ) ;
if ( V_53 == NULL )
return - V_32 ;
if ( F_23 ( V_53 , V_60 , V_61 ) != 0 )
V_25 = - V_70 ;
else
V_167 = F_15 ( V_53 , V_61 ) ;
F_18 ( V_53 ) ;
return V_25 ;
}
static T_1 F_84 ( struct V_59 * V_159 , char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_160 [ 32 ] ;
T_1 V_25 ;
if ( * V_62 != 0 )
return 0 ;
sprintf ( V_160 , L_15 , V_170 ) ;
V_25 = F_73 ( V_60 , V_61 , V_62 , V_160 , strlen ( V_160 ) ) ;
return V_25 ;
}
static T_1 F_85 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_160 [ 32 ] ;
int V_58 ;
if ( ! F_39 ( V_85 ) )
return - V_86 ;
if ( V_61 >= sizeof( V_160 ) || V_61 == 0 )
return - V_65 ;
if ( F_23 ( V_160 , V_60 , V_61 ) != 0 )
return - V_70 ;
V_160 [ V_61 ] = '\0' ;
if ( sscanf ( V_160 , L_9 , & V_58 ) != 1 )
return - V_65 ;
if ( V_58 < 0 || V_58 > 3 )
return - V_65 ;
V_170 = V_58 ;
return V_61 ;
}
static void * F_86 ( struct V_74 * V_75 , T_4 * V_76 )
{
struct V_171 * V_172 = F_87 () ;
return F_24 ( V_75 , V_76 , & V_172 -> V_72 ) ;
}
static void * F_88 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 )
{
struct V_171 * V_172 = F_87 () ;
return F_26 ( V_75 , V_81 , V_76 , & V_172 -> V_72 ) ;
}
static int F_89 ( struct V_74 * V_75 , void * V_81 )
{
struct V_15 * V_34 = V_81 ;
struct V_20 * V_14 =
F_35 ( V_34 , struct V_20 , V_34 ) ;
F_29 ( V_75 , V_14 , V_54 ) ;
return 0 ;
}
static int F_90 ( struct V_83 * V_83 , struct V_59 * V_59 )
{
return F_37 ( V_59 , & V_173 ) ;
}
static T_1 F_91 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_171 * V_172 = F_87 () ;
return F_21 ( V_59 , V_60 , V_61 , V_62 , & V_172 -> V_72 ,
& V_172 -> V_73 , V_66 ) ;
}
static T_1 F_92 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 , int V_63 )
{
struct V_13 V_49 ;
char * V_53 ;
int V_174 ;
V_53 = F_93 ( V_59 , V_60 , V_61 ) ;
if ( F_94 ( V_53 ) )
return F_95 ( V_53 ) ;
if ( V_63 == V_66 ) {
if ( V_61 < V_68 )
return - V_65 ;
V_174 = F_19 ( V_53 , & V_49 , 0 ) ;
} else {
V_174 = F_20 ( V_53 , & V_49 , 0 , 3 ) ;
}
if ( V_174 < 0 )
return - V_65 ;
V_174 = V_28 ( V_49 . V_27 , V_49 . V_26 ,
V_49 . V_29 , NULL ) ;
V_53 [ 0 ] = V_174 == 0 ? '1' : '0' ;
V_53 [ 1 ] = '\0' ;
F_96 ( V_59 , 2 ) ;
if ( V_63 == V_66 )
return V_68 ;
return V_61 ;
}
static T_1 F_97 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
return F_92 ( V_59 , V_60 , V_61 , V_62 , V_66 ) ;
}
static int F_98 ( struct V_74 * V_75 , void * V_81 )
{
struct V_15 * V_34 = V_81 ;
struct V_22 * V_23 =
F_35 ( V_34 , struct V_22 , V_34 ) ;
F_29 ( V_75 , V_23 -> V_35 , V_175 ) ;
return 0 ;
}
static int F_99 ( struct V_83 * V_83 , struct V_59 * V_59 )
{
return F_37 ( V_59 , & V_176 ) ;
}
static T_1 F_100 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
if ( ! F_39 ( V_85 ) )
return - V_86 ;
return F_21 ( V_59 , V_60 , V_61 , V_62 , NULL , NULL ,
V_128 ) ;
}
static void * F_101 ( struct V_74 * V_75 , T_4 * V_76 )
{
struct V_171 * V_172 = F_87 () ;
return F_24 ( V_75 , V_76 , & V_172 -> V_72 ) ;
}
static void * F_102 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 )
{
struct V_171 * V_172 = F_87 () ;
return F_26 ( V_75 , V_81 , V_76 , & V_172 -> V_72 ) ;
}
static int F_103 ( struct V_74 * V_75 , void * V_81 )
{
struct V_15 * V_34 = V_81 ;
struct V_20 * V_14 =
F_35 ( V_34 , struct V_20 , V_34 ) ;
F_29 ( V_75 , V_14 , V_175 ) ;
return 0 ;
}
static int F_104 ( struct V_83 * V_83 , struct V_59 * V_59 )
{
return F_37 ( V_59 , & V_177 ) ;
}
static T_1 F_105 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_171 * V_172 = F_87 () ;
return F_21 ( V_59 , V_60 , V_61 , V_62 , & V_172 -> V_72 ,
& V_172 -> V_73 , V_128 ) ;
}
static T_1 F_106 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
return F_92 ( V_59 , V_60 , V_61 , V_62 , V_128 ) ;
}
static T_1 F_107 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char * V_53 = NULL ;
const char * V_38 = NULL ;
struct V_6 * V_7 ;
struct V_20 * V_21 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_25 = V_61 ;
if ( * V_62 != 0 )
return - V_65 ;
if ( ! F_39 ( V_85 ) )
return - V_86 ;
if ( V_61 == 0 || V_61 > V_175 )
return - V_65 ;
V_53 = F_9 ( V_61 , V_31 ) ;
if ( V_53 == NULL )
return - V_32 ;
if ( F_23 ( V_53 , V_60 , V_61 ) != 0 ) {
V_25 = - V_70 ;
goto V_154;
}
V_38 = F_16 ( V_53 , V_61 ) ;
if ( V_38 == NULL ) {
V_25 = - V_65 ;
goto V_154;
}
V_7 = F_17 ( V_38 ) ;
if ( V_7 == NULL )
goto V_154;
V_16 = & V_7 -> V_72 ;
V_18 = & V_7 -> V_73 ;
F_7 ( V_18 ) ;
F_8 (sp, rule_list, list)
V_21 -> V_28 = 0 ;
F_11 ( V_18 ) ;
V_154:
F_18 ( V_53 ) ;
F_18 ( V_38 ) ;
return V_25 ;
}
static int F_108 ( void )
{
V_178 = F_109 ( L_16 , NULL , V_179 ) ;
if ( ! V_178 )
return - V_32 ;
return 0 ;
}
static T_1 F_110 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
if ( ! F_111 ( V_85 ) )
return - V_86 ;
return F_21 ( V_59 , V_60 , V_61 , V_62 , NULL , NULL ,
V_71 ) ;
}
static int F_112 ( struct V_180 * V_181 , void * V_53 , int V_182 )
{
int V_25 ;
struct V_83 * V_183 ;
static struct V_184 V_185 [] = {
[ V_186 ] = {
L_17 , & V_187 , V_188 | V_189 } ,
[ V_190 ] = {
L_18 , & V_191 , V_188 | V_189 } ,
[ V_192 ] = {
L_19 , & V_193 , V_188 | V_189 } ,
[ V_194 ] = {
L_20 , & V_195 , V_188 | V_189 } ,
[ V_196 ] = {
L_21 , & V_197 , V_188 | V_189 } ,
[ V_198 ] = {
L_22 , & V_199 , V_188 | V_189 } ,
[ V_200 ] = {
L_23 , & V_201 , V_188 | V_189 } ,
[ V_202 ] = {
L_24 , & V_203 , V_188 | V_189 } ,
[ V_204 ] = {
L_25 , & V_205 , V_188 | V_206 } ,
[ V_207 ] = {
L_26 , & V_208 , V_188 | V_206 } ,
[ V_209 ] = {
L_27 , & V_210 , V_188 | V_189 } ,
[ V_211 ] = {
L_28 , & V_212 , V_188 | V_189 } ,
[ V_213 ] = {
L_29 , & V_214 , V_188 | V_206 } ,
[ V_215 ] = {
L_30 , & V_216 , V_188 | V_206 } ,
[ V_217 ] = {
L_31 , & V_218 , V_188 | V_189 } ,
[ V_219 ] = {
L_32 , & V_220 ,
V_188 | V_189 } ,
[ V_221 ] = {
L_33 , & V_222 , V_188 | V_189 } ,
{ L_14 }
} ;
V_25 = F_113 ( V_181 , V_223 , V_185 ) ;
if ( V_25 != 0 ) {
F_42 ( V_224 L_34 ,
V_92 , V_25 ) ;
return V_25 ;
}
V_183 = V_181 -> V_225 -> V_226 ;
return 0 ;
}
static struct V_227 * F_114 ( struct V_228 * V_229 ,
int V_230 , const char * V_231 , void * V_53 )
{
return F_115 ( V_229 , V_230 , V_53 , F_112 ) ;
}
static int T_7 F_116 ( struct V_6 * V_7 )
{
V_7 -> V_108 . V_232 = V_7 -> V_52 ;
V_7 -> V_108 . V_230 =
V_233 | V_234 ;
return F_54 ( V_161 , V_7 -> V_52 ,
& V_7 -> V_108 , strlen ( V_7 -> V_52 ) ) ;
}
static int T_7 F_117 ( void )
{
int V_235 ;
int V_25 ;
if ( ! F_118 ( & V_236 ) )
return 0 ;
V_235 = F_108 () ;
if ( V_235 )
F_42 ( V_224 L_35 ) ;
V_235 = F_119 ( & V_237 ) ;
if ( ! V_235 ) {
V_238 = F_120 ( & V_237 ) ;
if ( F_94 ( V_238 ) ) {
F_42 ( V_224 L_36 ) ;
V_235 = F_95 ( V_238 ) ;
V_238 = NULL ;
}
}
F_40 () ;
F_46 ( NULL ) ;
V_25 = F_116 ( & V_104 ) ;
if ( V_235 == 0 && V_25 < 0 )
V_235 = V_25 ;
V_25 = F_116 ( & V_239 ) ;
if ( V_235 == 0 && V_25 < 0 )
V_235 = V_25 ;
V_25 = F_116 ( & V_240 ) ;
if ( V_235 == 0 && V_25 < 0 )
V_235 = V_25 ;
V_25 = F_116 ( & V_241 ) ;
if ( V_235 == 0 && V_25 < 0 )
V_235 = V_25 ;
V_25 = F_116 ( & V_242 ) ;
if ( V_235 == 0 && V_25 < 0 )
V_235 = V_25 ;
V_25 = F_116 ( & V_243 ) ;
if ( V_235 == 0 && V_25 < 0 )
V_235 = V_25 ;
return V_235 ;
}
