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
case 'b' :
case 'B' :
V_37 |= V_45 ;
break;
default:
return V_37 ;
}
}
static int F_13 ( const char * V_46 , const char * V_47 ,
const char * V_48 , const char * V_49 ,
struct V_13 * V_50 , int V_51 ,
int V_52 )
{
const char * V_38 ;
struct V_6 * V_7 ;
if ( V_51 ) {
V_50 -> V_27 = F_14 ( V_46 , V_52 ) ;
if ( V_50 -> V_27 == NULL )
return - V_53 ;
V_50 -> V_26 = F_14 ( V_47 , V_52 ) ;
if ( V_50 -> V_26 == NULL )
return - V_53 ;
} else {
V_38 = F_15 ( V_46 , V_52 ) ;
if ( V_38 == NULL )
return - V_53 ;
V_7 = F_16 ( V_38 ) ;
F_17 ( V_38 ) ;
if ( V_7 == NULL )
return - V_54 ;
V_50 -> V_27 = V_7 ;
V_38 = F_15 ( V_47 , V_52 ) ;
if ( V_38 == NULL )
return - V_53 ;
V_7 = F_16 ( V_38 ) ;
F_17 ( V_38 ) ;
if ( V_7 == NULL )
return - V_54 ;
V_50 -> V_26 = V_7 ;
}
V_50 -> V_29 = F_12 ( V_48 ) ;
if ( V_49 )
V_50 -> V_30 = F_12 ( V_49 ) ;
else
V_50 -> V_30 = ~ V_50 -> V_29 ;
return 0 ;
}
static int F_18 ( const char * V_55 , struct V_13 * V_50 ,
int V_51 )
{
int V_25 ;
V_25 = F_13 ( V_55 , V_55 + V_56 ,
V_55 + V_56 + V_56 , NULL , V_50 ,
V_51 , V_56 ) ;
return V_25 ;
}
static T_1 F_19 ( char * V_55 , struct V_13 * V_50 ,
int V_51 , int V_57 )
{
T_1 V_58 = 0 ;
char * V_59 [ 4 ] ;
int V_25 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_57 ; ++ V_60 ) {
while ( isspace ( V_55 [ V_58 ] ) )
V_55 [ V_58 ++ ] = '\0' ;
if ( V_55 [ V_58 ] == '\0' )
return - 1 ;
V_59 [ V_60 ] = V_55 + V_58 ;
while ( V_55 [ V_58 ] && ! isspace ( V_55 [ V_58 ] ) )
++ V_58 ;
}
while ( isspace ( V_55 [ V_58 ] ) )
V_55 [ V_58 ++ ] = '\0' ;
while ( V_60 < 4 )
V_59 [ V_60 ++ ] = NULL ;
V_25 = F_13 ( V_59 [ 0 ] , V_59 [ 1 ] , V_59 [ 2 ] , V_59 [ 3 ] , V_50 , V_51 , 0 ) ;
return V_25 == 0 ? V_58 : V_25 ;
}
static T_1 F_20 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 ,
struct V_15 * V_16 ,
struct V_17 * V_18 , int V_65 )
{
struct V_13 V_50 ;
char * V_55 ;
int V_25 ;
int V_66 = 0 ;
int V_57 ;
T_1 V_58 = 0 ;
if ( * V_64 != 0 )
return - V_53 ;
if ( V_65 == V_67 ) {
if ( V_63 < V_68 || V_63 > V_69 )
return - V_53 ;
} else {
if ( V_63 >= V_70 ) {
V_63 = V_70 - 1 ;
V_66 = 1 ;
}
}
V_55 = F_21 ( V_63 + 1 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_22 ( V_55 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_33;
}
if ( V_66 ) {
while ( V_63 > 0 && ( V_55 [ V_63 - 1 ] != '\n' ) )
-- V_63 ;
if ( V_63 == 0 ) {
V_25 = - V_53 ;
goto V_33;
}
}
V_55 [ V_63 ] = '\0' ;
V_57 = ( V_65 == V_72 ? 4 : 3 ) ;
while ( V_58 < V_63 ) {
if ( V_65 == V_67 ) {
V_25 = F_18 ( V_55 , & V_50 , 1 ) ;
if ( V_25 != 0 ) {
V_25 = - V_53 ;
goto V_33;
}
V_58 = V_63 ;
} else {
V_25 = F_19 ( V_55 + V_58 , & V_50 , 1 , V_57 ) ;
if ( V_25 <= 0 ) {
V_25 = - V_53 ;
goto V_33;
}
V_58 += V_25 ;
}
if ( V_16 == NULL )
V_25 = F_6 ( & V_50 , & V_50 . V_27 -> V_73 ,
& V_50 . V_27 -> V_74 , 1 ) ;
else
V_25 = F_6 ( & V_50 , V_16 , V_18 , 0 ) ;
if ( V_25 )
goto V_33;
}
V_25 = V_58 ;
V_33:
F_17 ( V_55 ) ;
return V_25 ;
}
static void * F_23 ( struct V_75 * V_76 , T_4 * V_77 ,
struct V_15 * V_78 )
{
struct V_15 * V_34 ;
if ( V_76 -> V_79 == 0 )
V_76 -> V_80 = V_78 ;
if ( V_76 -> V_80 == NULL )
return NULL ;
V_34 = V_76 -> V_80 ;
if ( F_24 ( V_34 ) )
return NULL ;
if ( V_76 -> V_79 == 0 )
return V_34 -> V_81 ;
return V_34 ;
}
static void * F_25 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 ,
struct V_15 * V_78 )
{
struct V_15 * V_34 = V_82 ;
if ( F_26 ( V_34 , V_78 ) ) {
V_76 -> V_80 = NULL ;
return NULL ;
}
V_76 -> V_80 = V_34 -> V_81 ;
return V_34 -> V_81 ;
}
static void F_27 ( struct V_75 * V_76 , void * V_82 )
{
}
static void F_28 ( struct V_75 * V_76 , struct V_20 * V_14 , int V_83 )
{
if ( strlen ( V_14 -> V_27 -> V_84 ) >= V_83 ||
strlen ( V_14 -> V_26 -> V_84 ) >= V_83 )
return;
if ( V_14 -> V_28 == 0 )
return;
F_29 ( V_76 , L_1 ,
V_14 -> V_27 -> V_84 ,
V_14 -> V_26 -> V_84 ) ;
F_30 ( V_76 , ' ' ) ;
if ( V_14 -> V_28 & V_39 )
F_30 ( V_76 , 'r' ) ;
if ( V_14 -> V_28 & V_40 )
F_30 ( V_76 , 'w' ) ;
if ( V_14 -> V_28 & V_41 )
F_30 ( V_76 , 'x' ) ;
if ( V_14 -> V_28 & V_42 )
F_30 ( V_76 , 'a' ) ;
if ( V_14 -> V_28 & V_43 )
F_30 ( V_76 , 't' ) ;
if ( V_14 -> V_28 & V_44 )
F_30 ( V_76 , 'l' ) ;
if ( V_14 -> V_28 & V_45 )
F_30 ( V_76 , 'b' ) ;
F_30 ( V_76 , '\n' ) ;
}
static void * F_31 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_23 ( V_76 , V_77 , & V_36 ) ;
}
static void * F_32 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
return F_25 ( V_76 , V_82 , V_77 , & V_36 ) ;
}
static int F_33 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_22 * V_23 =
F_34 ( V_34 , struct V_22 , V_34 ) ;
F_28 ( V_76 , V_23 -> V_35 , V_56 ) ;
return 0 ;
}
static int F_35 ( struct V_85 * V_85 , struct V_61 * V_61 )
{
return F_36 ( V_61 , & V_86 ) ;
}
static T_1 F_37 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_38 ( V_87 ) )
return - V_88 ;
return F_20 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_67 ) ;
}
static void F_39 ( void )
{
int V_25 ;
struct V_89 * V_90 ;
struct V_4 V_91 ;
F_2 ( & V_91 ) ;
V_25 = F_40 ( NULL , V_92 , NULL , NULL , & V_91 ) ;
if ( V_25 != 0 )
F_41 ( V_93 L_2 ,
V_94 , __LINE__ , V_25 ) ;
V_90 = F_21 ( sizeof( struct V_89 ) , V_31 ) ;
if ( V_90 == NULL )
F_42 ( L_3 ) ;
V_90 -> V_95 . V_96 = NULL ;
V_90 -> V_97 = V_98 ;
V_90 -> type = V_99 ;
V_90 -> V_100 [ 0 ] = V_101 ;
for ( V_25 = 1 ; V_25 < V_102 ; V_25 ++ )
V_90 -> V_100 [ V_25 ] = V_103 ;
V_25 = F_43 ( V_90 , & V_91 ) ;
if ( V_25 != 0 ) {
F_41 ( V_93 L_4 ,
V_94 , __LINE__ , V_25 ) ;
F_17 ( V_90 ) ;
return;
}
V_25 = F_44 ( V_90 -> V_97 , NULL , NULL , NULL , & V_91 ) ;
if ( V_25 != 0 ) {
F_41 ( V_93 L_5 ,
V_94 , __LINE__ , V_25 ) ;
F_17 ( V_90 ) ;
return;
}
}
static void F_45 ( char * V_104 )
{
int V_25 ;
struct V_4 V_91 ;
F_2 ( & V_91 ) ;
if ( V_104 != NULL ) {
V_25 = F_40 ( V_104 , V_92 , NULL , NULL , & V_91 ) ;
if ( V_25 != 0 )
F_41 ( V_93 L_2 ,
V_94 , __LINE__ , V_25 ) ;
}
if ( V_105 == NULL )
V_105 = & V_106 ;
V_25 = F_46 ( V_105 -> V_84 , V_92 ,
NULL , NULL , & V_91 ) ;
if ( V_25 != 0 )
F_41 ( V_93 L_6 ,
V_94 , __LINE__ , V_25 ) ;
}
static void * F_47 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_23 ( V_76 , V_77 , & V_107 ) ;
}
static void * F_48 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
return F_25 ( V_76 , V_82 , V_77 , & V_107 ) ;
}
static int F_49 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_6 * V_7 =
F_34 ( V_34 , struct V_6 , V_34 ) ;
struct V_108 * V_109 = V_7 -> V_110 . V_111 . V_112 . V_1 ;
char V_113 = '/' ;
int V_60 ;
if ( strlen ( V_7 -> V_84 ) >= V_56 )
return 0 ;
F_29 ( V_76 , L_7 , V_7 -> V_84 , V_7 -> V_110 . V_111 . V_112 . V_114 ) ;
for ( V_60 = F_50 ( V_109 , 0 ) ; V_60 >= 0 ;
V_60 = F_50 ( V_109 , V_60 + 1 ) ) {
F_29 ( V_76 , L_8 , V_113 , V_60 ) ;
V_113 = ',' ;
}
F_30 ( V_76 , '\n' ) ;
return 0 ;
}
static int F_51 ( struct V_85 * V_85 , struct V_61 * V_61 )
{
return F_36 ( V_61 , & V_115 ) ;
}
static T_1 F_52 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 , int V_65 )
{
struct V_6 * V_7 ;
struct V_116 V_117 ;
char V_118 [ V_3 ] ;
int V_119 ;
unsigned int V_1 ;
int V_120 ;
T_1 V_25 = - V_53 ;
char * V_55 = NULL ;
char * V_50 ;
int V_121 ;
int V_60 ;
if ( ! F_38 ( V_87 ) )
return - V_88 ;
if ( * V_64 != 0 )
return - V_53 ;
if ( V_65 == V_67 &&
( V_63 < V_122 || V_63 > V_123 ) )
return - V_53 ;
V_55 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_22 ( V_55 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_124;
}
V_55 [ V_63 ] = '\0' ;
V_50 = V_55 ;
F_7 ( & V_125 ) ;
V_7 = F_14 ( V_50 , 0 ) ;
if ( V_7 == NULL )
goto V_33;
if ( V_65 == V_67 )
V_50 += V_56 ;
else
V_50 += strlen ( V_7 -> V_84 ) + 1 ;
V_121 = sscanf ( V_50 , L_9 , & V_119 ) ;
if ( V_121 != 1 || V_119 > V_126 )
goto V_33;
V_50 += V_127 ;
V_121 = sscanf ( V_50 , L_9 , & V_120 ) ;
if ( V_121 != 1 || V_120 > V_128 )
goto V_33;
if ( V_65 == V_67 &&
V_63 != ( V_122 + V_120 * V_127 ) )
goto V_33;
memset ( V_118 , 0 , sizeof( V_118 ) ) ;
for ( V_60 = 0 ; V_60 < V_120 ; V_60 ++ ) {
V_50 += V_127 ;
V_121 = sscanf ( V_50 , L_10 , & V_1 ) ;
if ( V_121 != 1 || V_1 > V_128 )
goto V_33;
F_1 ( V_1 , V_118 ) ;
}
V_25 = F_53 ( V_119 , V_118 , & V_117 , V_3 ) ;
if ( V_25 >= 0 ) {
F_54 ( V_7 -> V_110 . V_111 . V_112 . V_1 ) ;
V_7 -> V_110 . V_111 . V_112 . V_1 = V_117 . V_111 . V_112 . V_1 ;
V_7 -> V_110 . V_111 . V_112 . V_114 = V_117 . V_111 . V_112 . V_114 ;
V_25 = V_63 ;
}
V_33:
F_11 ( & V_125 ) ;
V_124:
F_17 ( V_55 ) ;
return V_25 ;
}
static T_1 F_55 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_52 ( V_61 , V_62 , V_63 , V_64 , V_67 ) ;
}
static int F_56 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_6 * V_7 =
F_34 ( V_34 , struct V_6 , V_34 ) ;
struct V_108 * V_109 = V_7 -> V_110 . V_111 . V_112 . V_1 ;
char V_113 = '/' ;
int V_60 ;
F_29 ( V_76 , L_7 , V_7 -> V_84 , V_7 -> V_110 . V_111 . V_112 . V_114 ) ;
for ( V_60 = F_50 ( V_109 , 0 ) ; V_60 >= 0 ;
V_60 = F_50 ( V_109 , V_60 + 1 ) ) {
F_29 ( V_76 , L_8 , V_113 , V_60 ) ;
V_113 = ',' ;
}
F_30 ( V_76 , '\n' ) ;
return 0 ;
}
static int F_57 ( struct V_85 * V_85 , struct V_61 * V_61 )
{
return F_36 ( V_61 , & V_129 ) ;
}
static T_1 F_58 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_52 ( V_61 , V_62 , V_63 , V_64 , V_130 ) ;
}
static void * F_59 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_23 ( V_76 , V_77 , & V_131 ) ;
}
static void * F_60 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
return F_25 ( V_76 , V_82 , V_77 , & V_131 ) ;
}
static int F_61 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_132 * V_7 =
F_34 ( V_34 , struct V_132 , V_34 ) ;
unsigned char * V_133 = ( char * ) & V_7 -> V_134 . V_135 . V_136 ;
int V_137 ;
T_5 V_138 = F_62 ( V_7 -> V_139 . V_136 ) ;
for ( V_137 = 0 ; V_138 ; V_138 <<= 1 , V_137 ++ ) ;
F_29 ( V_76 , L_11 ,
V_133 [ 0 ] , V_133 [ 1 ] , V_133 [ 2 ] , V_133 [ 3 ] , V_137 , V_7 -> V_140 -> V_84 ) ;
return 0 ;
}
static int F_63 ( struct V_85 * V_85 , struct V_61 * V_61 )
{
return F_36 ( V_61 , & V_141 ) ;
}
static void F_64 ( struct V_132 * V_142 )
{
struct V_132 * V_143 , * V_144 ;
if ( F_24 ( & V_131 ) ) {
F_10 ( & V_142 -> V_34 , & V_131 ) ;
return;
}
V_143 = F_65 ( V_131 . V_81 ,
struct V_132 , V_34 ) ;
if ( V_142 -> V_139 . V_136 > V_143 -> V_139 . V_136 ) {
F_10 ( & V_142 -> V_34 , & V_131 ) ;
return;
}
F_8 (m, &smk_netlbladdr_list, list) {
if ( F_26 ( & V_143 -> V_34 , & V_131 ) ) {
F_10 ( & V_142 -> V_34 , & V_143 -> V_34 ) ;
return;
}
V_144 = F_65 ( V_143 -> V_34 . V_81 ,
struct V_132 , V_34 ) ;
if ( V_142 -> V_139 . V_136 > V_144 -> V_139 . V_136 ) {
F_10 ( & V_142 -> V_34 , & V_143 -> V_34 ) ;
return;
}
}
}
static T_1 F_66 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_132 * V_145 ;
struct V_146 V_147 ;
char * V_148 ;
struct V_6 * V_7 ;
char * V_55 ;
char * V_149 = ( char * ) & V_147 . V_135 . V_136 ;
int V_25 ;
struct V_4 V_150 ;
struct V_151 V_152 ;
unsigned int V_143 ;
int V_24 ;
T_5 V_153 = ( 1 << 31 ) ;
T_6 V_154 ;
T_5 V_138 ;
if ( ! F_38 ( V_87 ) )
return - V_88 ;
if ( * V_64 != 0 )
return - V_53 ;
if ( V_63 < V_155 )
return - V_53 ;
V_55 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_22 ( V_55 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_156;
}
V_148 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_148 == NULL ) {
V_25 = - V_32 ;
goto V_156;
}
V_55 [ V_63 ] = '\0' ;
V_25 = sscanf ( V_55 , L_12 ,
& V_149 [ 0 ] , & V_149 [ 1 ] , & V_149 [ 2 ] , & V_149 [ 3 ] , & V_143 , V_148 ) ;
if ( V_25 != 6 ) {
V_25 = sscanf ( V_55 , L_13 ,
& V_149 [ 0 ] , & V_149 [ 1 ] , & V_149 [ 2 ] , & V_149 [ 3 ] , V_148 ) ;
if ( V_25 != 5 ) {
V_25 = - V_53 ;
goto V_157;
}
V_143 = V_158 ;
}
if ( V_143 > V_158 ) {
V_25 = - V_53 ;
goto V_157;
}
if ( V_148 [ 0 ] != '-' ) {
V_7 = F_14 ( V_148 , 0 ) ;
if ( V_7 == NULL ) {
V_25 = - V_53 ;
goto V_157;
}
} else {
if ( strcmp ( V_148 , V_159 . V_84 ) == 0 )
V_7 = & V_159 ;
else {
V_25 = - V_53 ;
goto V_157;
}
}
for ( V_138 = 0 ; V_143 > 0 ; V_143 -- ) {
V_138 |= V_153 ;
V_153 >>= 1 ;
}
V_152 . V_136 = F_67 ( V_138 ) ;
V_147 . V_135 . V_136 &= V_152 . V_136 ;
F_7 ( & V_160 ) ;
V_154 = V_147 . V_135 . V_136 ;
V_24 = 0 ;
F_8 (snp, &smk_netlbladdr_list, list) {
if ( V_145 -> V_134 . V_135 . V_136 == V_154 &&
V_145 -> V_139 . V_136 == V_152 . V_136 ) {
V_24 = 1 ;
break;
}
}
F_2 ( & V_150 ) ;
if ( V_24 == 0 ) {
V_145 = F_9 ( sizeof( * V_145 ) , V_31 ) ;
if ( V_145 == NULL )
V_25 = - V_32 ;
else {
V_25 = 0 ;
V_145 -> V_134 . V_135 . V_136 = V_147 . V_135 . V_136 ;
V_145 -> V_139 . V_136 = V_152 . V_136 ;
V_145 -> V_140 = V_7 ;
F_64 ( V_145 ) ;
}
} else {
if ( V_145 -> V_140 != & V_159 )
V_25 = F_68 ( & V_161 , NULL ,
& V_145 -> V_134 . V_135 , & V_145 -> V_139 ,
V_92 , & V_150 ) ;
else
V_25 = 0 ;
V_145 -> V_140 = V_7 ;
}
if ( V_25 == 0 && V_7 != & V_159 )
V_25 = F_69 ( & V_161 , NULL ,
& V_145 -> V_134 . V_135 , & V_145 -> V_139 , V_92 ,
V_145 -> V_140 -> V_12 , & V_150 ) ;
if ( V_25 == 0 )
V_25 = V_63 ;
F_11 ( & V_160 ) ;
V_157:
F_17 ( V_148 ) ;
V_156:
F_17 ( V_55 ) ;
return V_25 ;
}
static T_1 F_70 ( struct V_61 * V_162 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_163 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_163 , L_9 , V_98 ) ;
V_25 = F_71 ( V_62 , V_63 , V_64 , V_163 , strlen ( V_163 ) ) ;
return V_25 ;
}
static T_1 F_72 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_163 [ 80 ] ;
int V_60 ;
if ( ! F_38 ( V_87 ) )
return - V_88 ;
if ( V_63 >= sizeof( V_163 ) || V_63 == 0 )
return - V_53 ;
if ( F_22 ( V_163 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_163 [ V_63 ] = '\0' ;
if ( sscanf ( V_163 , L_9 , & V_60 ) != 1 )
return - V_53 ;
V_98 = V_60 ;
F_39 () ;
return V_63 ;
}
static T_1 F_73 ( struct V_61 * V_162 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_163 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_163 , L_9 , V_164 ) ;
V_25 = F_71 ( V_62 , V_63 , V_64 , V_163 , strlen ( V_163 ) ) ;
return V_25 ;
}
static T_1 F_74 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char V_163 [ 80 ] ;
int V_60 ;
if ( ! F_38 ( V_87 ) )
return - V_88 ;
if ( V_63 >= sizeof( V_163 ) || V_63 == 0 )
return - V_53 ;
if ( F_22 ( V_163 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_163 [ V_63 ] = '\0' ;
if ( sscanf ( V_163 , L_9 , & V_60 ) != 1 )
return - V_53 ;
if ( V_164 != V_60 ) {
F_7 ( & V_165 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_110 . V_111 . V_112 . V_114 ==
V_164 )
V_7 -> V_110 . V_111 . V_112 . V_114 = V_60 ;
V_164 = V_60 ;
F_11 ( & V_165 ) ;
}
return V_63 ;
}
static T_1 F_75 ( struct V_61 * V_162 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_163 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_163 , L_9 , V_166 ) ;
V_25 = F_71 ( V_62 , V_63 , V_64 , V_163 , strlen ( V_163 ) ) ;
return V_25 ;
}
static T_1 F_76 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char V_163 [ 80 ] ;
int V_60 ;
if ( ! F_38 ( V_87 ) )
return - V_88 ;
if ( V_63 >= sizeof( V_163 ) || V_63 == 0 )
return - V_53 ;
if ( F_22 ( V_163 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_163 [ V_63 ] = '\0' ;
if ( sscanf ( V_163 , L_9 , & V_60 ) != 1 )
return - V_53 ;
if ( V_166 != V_60 ) {
F_7 ( & V_165 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_110 . V_111 . V_112 . V_114 ==
V_166 )
V_7 -> V_110 . V_111 . V_112 . V_114 = V_60 ;
V_166 = V_60 ;
F_11 ( & V_165 ) ;
}
return V_63 ;
}
static T_1 F_77 ( struct V_61 * V_162 , char T_2 * V_62 ,
T_3 V_167 , T_4 * V_64 )
{
T_1 V_25 ;
int V_168 ;
if ( * V_64 != 0 )
return 0 ;
F_7 ( & V_169 ) ;
V_168 = strlen ( V_105 -> V_84 ) + 1 ;
if ( V_167 >= V_168 )
V_25 = F_71 ( V_62 , V_167 , V_64 ,
V_105 -> V_84 ,
V_168 ) ;
else
V_25 = - V_53 ;
F_11 ( & V_169 ) ;
return V_25 ;
}
static T_1 F_78 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char * V_104 ;
char * V_55 ;
int V_25 = V_63 ;
if ( ! F_38 ( V_87 ) )
return - V_88 ;
V_55 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_22 ( V_55 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_33;
}
V_7 = F_14 ( V_55 , V_63 ) ;
if ( V_7 == NULL ) {
V_25 = - V_53 ;
goto V_33;
}
F_7 ( & V_169 ) ;
V_104 = V_105 -> V_84 ;
V_105 = V_7 ;
F_45 ( V_104 ) ;
F_11 ( & V_169 ) ;
V_33:
F_17 ( V_55 ) ;
return V_25 ;
}
static T_1 F_79 ( struct V_61 * V_162 , char T_2 * V_62 ,
T_3 V_167 , T_4 * V_64 )
{
char * V_148 = L_14 ;
T_1 V_25 = - V_53 ;
int V_168 ;
if ( * V_64 != 0 )
return 0 ;
if ( V_170 != NULL )
V_148 = V_170 -> V_84 ;
V_168 = strlen ( V_148 ) + 1 ;
if ( V_167 >= V_168 )
V_25 = F_71 ( V_62 , V_167 , V_64 , V_148 , V_168 ) ;
return V_25 ;
}
static T_1 F_80 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_55 ;
struct V_6 * V_7 = F_81 ( V_9 -> V_171 -> V_172 ) ;
int V_25 = V_63 ;
if ( ! F_38 ( V_87 ) )
return - V_88 ;
if ( V_170 != NULL && V_170 != V_7 )
return - V_88 ;
V_55 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_22 ( V_55 , V_62 , V_63 ) != 0 )
V_25 = - V_71 ;
else
V_170 = F_14 ( V_55 , V_63 ) ;
F_17 ( V_55 ) ;
return V_25 ;
}
static T_1 F_82 ( struct V_61 * V_162 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_163 [ 32 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_163 , L_15 , V_173 ) ;
V_25 = F_71 ( V_62 , V_63 , V_64 , V_163 , strlen ( V_163 ) ) ;
return V_25 ;
}
static T_1 F_83 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_163 [ 32 ] ;
int V_60 ;
if ( ! F_38 ( V_87 ) )
return - V_88 ;
if ( V_63 >= sizeof( V_163 ) || V_63 == 0 )
return - V_53 ;
if ( F_22 ( V_163 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_163 [ V_63 ] = '\0' ;
if ( sscanf ( V_163 , L_9 , & V_60 ) != 1 )
return - V_53 ;
if ( V_60 < 0 || V_60 > 3 )
return - V_53 ;
V_173 = V_60 ;
return V_63 ;
}
static void * F_84 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_174 * V_175 = F_85 () ;
return F_23 ( V_76 , V_77 , & V_175 -> V_73 ) ;
}
static void * F_86 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
struct V_174 * V_175 = F_85 () ;
return F_25 ( V_76 , V_82 , V_77 , & V_175 -> V_73 ) ;
}
static int F_87 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_20 * V_14 =
F_34 ( V_34 , struct V_20 , V_34 ) ;
F_28 ( V_76 , V_14 , V_56 ) ;
return 0 ;
}
static int F_88 ( struct V_85 * V_85 , struct V_61 * V_61 )
{
return F_36 ( V_61 , & V_176 ) ;
}
static T_1 F_89 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_174 * V_175 = F_85 () ;
return F_20 ( V_61 , V_62 , V_63 , V_64 , & V_175 -> V_73 ,
& V_175 -> V_74 , V_67 ) ;
}
static T_1 F_90 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 , int V_65 )
{
struct V_13 V_50 ;
char * V_55 ;
int V_177 ;
V_55 = F_91 ( V_61 , V_62 , V_63 ) ;
if ( F_92 ( V_55 ) )
return F_93 ( V_55 ) ;
if ( V_65 == V_67 ) {
if ( V_63 < V_69 )
return - V_53 ;
V_177 = F_18 ( V_55 , & V_50 , 0 ) ;
} else {
V_177 = F_19 ( V_55 , & V_50 , 0 , 3 ) ;
}
if ( V_177 >= 0 )
V_177 = V_28 ( V_50 . V_27 , V_50 . V_26 ,
V_50 . V_29 , NULL ) ;
else if ( V_177 != - V_54 )
return - V_53 ;
V_55 [ 0 ] = V_177 >= 0 ? '1' : '0' ;
V_55 [ 1 ] = '\0' ;
F_94 ( V_61 , 2 ) ;
if ( V_65 == V_67 )
return V_69 ;
return V_63 ;
}
static T_1 F_95 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_90 ( V_61 , V_62 , V_63 , V_64 , V_67 ) ;
}
static int F_96 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_22 * V_23 =
F_34 ( V_34 , struct V_22 , V_34 ) ;
F_28 ( V_76 , V_23 -> V_35 , V_178 ) ;
return 0 ;
}
static int F_97 ( struct V_85 * V_85 , struct V_61 * V_61 )
{
return F_36 ( V_61 , & V_179 ) ;
}
static T_1 F_98 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_38 ( V_87 ) )
return - V_88 ;
return F_20 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_130 ) ;
}
static void * F_99 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_174 * V_175 = F_85 () ;
return F_23 ( V_76 , V_77 , & V_175 -> V_73 ) ;
}
static void * F_100 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
struct V_174 * V_175 = F_85 () ;
return F_25 ( V_76 , V_82 , V_77 , & V_175 -> V_73 ) ;
}
static int F_101 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_20 * V_14 =
F_34 ( V_34 , struct V_20 , V_34 ) ;
F_28 ( V_76 , V_14 , V_178 ) ;
return 0 ;
}
static int F_102 ( struct V_85 * V_85 , struct V_61 * V_61 )
{
return F_36 ( V_61 , & V_180 ) ;
}
static T_1 F_103 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_174 * V_175 = F_85 () ;
return F_20 ( V_61 , V_62 , V_63 , V_64 , & V_175 -> V_73 ,
& V_175 -> V_74 , V_130 ) ;
}
static T_1 F_104 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_90 ( V_61 , V_62 , V_63 , V_64 , V_130 ) ;
}
static T_1 F_105 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_55 = NULL ;
const char * V_38 = NULL ;
struct V_6 * V_7 ;
struct V_20 * V_21 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_25 = V_63 ;
if ( * V_64 != 0 )
return - V_53 ;
if ( ! F_38 ( V_87 ) )
return - V_88 ;
if ( V_63 == 0 || V_63 > V_178 )
return - V_53 ;
V_55 = F_9 ( V_63 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_22 ( V_55 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_157;
}
V_38 = F_15 ( V_55 , V_63 ) ;
if ( V_38 == NULL ) {
V_25 = - V_53 ;
goto V_157;
}
V_7 = F_16 ( V_38 ) ;
if ( V_7 == NULL )
goto V_157;
V_16 = & V_7 -> V_73 ;
V_18 = & V_7 -> V_74 ;
F_7 ( V_18 ) ;
F_8 (sp, rule_list, list)
V_21 -> V_28 = 0 ;
F_11 ( V_18 ) ;
V_157:
F_17 ( V_55 ) ;
F_17 ( V_38 ) ;
return V_25 ;
}
static int F_106 ( void )
{
V_181 = F_107 ( L_16 , NULL , V_182 ) ;
if ( ! V_181 )
return - V_32 ;
return 0 ;
}
static T_1 F_108 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_38 ( V_87 ) )
return - V_88 ;
return F_20 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_72 ) ;
}
static T_1 F_109 ( struct V_61 * V_162 , char T_2 * V_62 ,
T_3 V_167 , T_4 * V_64 )
{
struct V_6 * V_7 ;
T_1 V_25 = - V_53 ;
int V_168 ;
if ( * V_64 != 0 )
return 0 ;
if ( V_183 == NULL )
V_7 = & V_184 ;
else
V_7 = V_183 ;
V_168 = strlen ( V_7 -> V_84 ) + 1 ;
if ( V_167 >= V_168 )
V_25 = F_71 ( V_62 , V_167 , V_64 , V_7 -> V_84 ,
V_168 ) ;
return V_25 ;
}
static T_1 F_110 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_55 ;
struct V_6 * V_7 ;
int V_25 = V_63 ;
if ( ! F_38 ( V_87 ) )
return - V_88 ;
V_55 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_22 ( V_55 , V_62 , V_63 ) != 0 )
V_25 = - V_71 ;
else {
V_7 = F_14 ( V_55 , V_63 ) ;
if ( V_7 == NULL )
V_25 = - V_53 ;
else
V_183 = F_14 ( V_55 , V_63 ) ;
}
F_17 ( V_55 ) ;
return V_25 ;
}
static T_1 F_111 ( struct V_61 * V_162 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_163 [ 32 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_163 , L_15 , V_185 ) ;
V_25 = F_71 ( V_62 , V_63 , V_64 , V_163 , strlen ( V_163 ) ) ;
return V_25 ;
}
static T_1 F_112 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_163 [ 32 ] ;
int V_60 ;
if ( ! F_38 ( V_87 ) )
return - V_88 ;
if ( * V_64 != 0 || V_63 >= sizeof( V_163 ) || V_63 == 0 )
return - V_53 ;
if ( F_22 ( V_163 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_163 [ V_63 ] = '\0' ;
if ( sscanf ( V_163 , L_9 , & V_60 ) != 1 )
return - V_53 ;
if ( V_60 < V_186 || V_60 > V_187 )
return - V_53 ;
V_185 = V_60 ;
return V_63 ;
}
static int F_113 ( struct V_188 * V_189 , void * V_55 , int V_190 )
{
int V_25 ;
struct V_85 * V_191 ;
static struct V_192 V_193 [] = {
[ V_194 ] = {
L_17 , & V_195 , V_196 | V_197 } ,
[ V_198 ] = {
L_18 , & V_199 , V_196 | V_197 } ,
[ V_200 ] = {
L_19 , & V_201 , V_196 | V_197 } ,
[ V_202 ] = {
L_20 , & V_203 , V_196 | V_197 } ,
[ V_204 ] = {
L_21 , & V_205 , V_196 | V_197 } ,
[ V_206 ] = {
L_22 , & V_207 , V_196 | V_197 } ,
[ V_208 ] = {
L_23 , & V_209 , V_196 | V_197 } ,
[ V_210 ] = {
L_24 , & V_211 , V_196 | V_197 } ,
[ V_212 ] = {
L_25 , & V_213 , V_196 | V_214 } ,
[ V_215 ] = {
L_26 , & V_216 , V_196 | V_214 } ,
[ V_217 ] = {
L_27 , & V_218 , V_196 | V_197 } ,
[ V_219 ] = {
L_28 , & V_220 , V_196 | V_197 } ,
[ V_221 ] = {
L_29 , & V_222 , V_196 | V_214 } ,
[ V_223 ] = {
L_30 , & V_224 , V_196 | V_214 } ,
[ V_225 ] = {
L_31 , & V_226 , V_196 | V_197 } ,
[ V_227 ] = {
L_32 , & V_228 ,
V_196 | V_197 } ,
[ V_229 ] = {
L_33 , & V_230 , V_196 | V_197 } ,
[ V_231 ] = {
L_34 , & V_232 , V_196 | V_197 } ,
[ V_233 ] = {
L_35 , & V_234 , V_196 | V_197 } ,
{ L_14 }
} ;
V_25 = F_114 ( V_189 , V_235 , V_193 ) ;
if ( V_25 != 0 ) {
F_41 ( V_236 L_36 ,
V_94 , V_25 ) ;
return V_25 ;
}
V_191 = V_189 -> V_237 -> V_238 ;
return 0 ;
}
static struct V_239 * F_115 ( struct V_240 * V_241 ,
int V_242 , const char * V_243 , void * V_55 )
{
return F_116 ( V_241 , V_242 , V_55 , F_113 ) ;
}
static int T_7 F_117 ( struct V_6 * V_7 )
{
V_7 -> V_110 . V_244 = V_7 -> V_84 ;
V_7 -> V_110 . V_242 =
V_245 | V_246 ;
return F_53 ( V_164 , V_7 -> V_84 ,
& V_7 -> V_110 , strlen ( V_7 -> V_84 ) ) ;
}
static int T_7 F_118 ( void )
{
int V_247 ;
int V_25 ;
if ( ! F_119 ( & V_248 ) )
return 0 ;
V_247 = F_106 () ;
if ( V_247 )
F_41 ( V_236 L_37 ) ;
V_247 = F_120 ( & V_249 ) ;
if ( ! V_247 ) {
V_250 = F_121 ( & V_249 ) ;
if ( F_92 ( V_250 ) ) {
F_41 ( V_236 L_38 ) ;
V_247 = F_93 ( V_250 ) ;
V_250 = NULL ;
}
}
F_39 () ;
F_45 ( NULL ) ;
V_25 = F_117 ( & V_106 ) ;
if ( V_247 == 0 && V_25 < 0 )
V_247 = V_25 ;
V_25 = F_117 ( & V_251 ) ;
if ( V_247 == 0 && V_25 < 0 )
V_247 = V_25 ;
V_25 = F_117 ( & V_252 ) ;
if ( V_247 == 0 && V_25 < 0 )
V_247 = V_25 ;
V_25 = F_117 ( & V_253 ) ;
if ( V_247 == 0 && V_25 < 0 )
V_247 = V_25 ;
V_25 = F_117 ( & V_184 ) ;
if ( V_247 == 0 && V_25 < 0 )
V_247 = V_25 ;
V_25 = F_117 ( & V_254 ) ;
if ( V_247 == 0 && V_25 < 0 )
V_247 = V_25 ;
return V_247 ;
}
