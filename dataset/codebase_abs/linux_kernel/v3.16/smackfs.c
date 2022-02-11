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
return - V_52 ;
V_49 -> V_26 = F_15 ( V_46 , V_51 ) ;
if ( V_49 -> V_26 == NULL )
return - V_52 ;
} else {
V_38 = F_16 ( V_45 , V_51 ) ;
if ( V_38 == NULL )
return - V_52 ;
V_7 = F_17 ( V_38 ) ;
F_18 ( V_38 ) ;
if ( V_7 == NULL )
return - V_53 ;
V_49 -> V_27 = V_7 ;
V_38 = F_16 ( V_46 , V_51 ) ;
if ( V_38 == NULL )
return - V_52 ;
V_7 = F_17 ( V_38 ) ;
F_18 ( V_38 ) ;
if ( V_7 == NULL )
return - V_53 ;
V_49 -> V_26 = V_7 -> V_54 ;
}
V_49 -> V_29 = F_12 ( V_47 ) ;
if ( V_48 )
V_49 -> V_30 = F_12 ( V_48 ) ;
else
V_49 -> V_30 = ~ V_49 -> V_29 ;
return 0 ;
}
static int F_19 ( const char * V_55 , struct V_13 * V_49 ,
int V_50 )
{
int V_25 ;
V_25 = F_13 ( V_55 , V_55 + V_56 ,
V_55 + V_56 + V_56 , NULL , V_49 ,
V_50 , V_56 ) ;
return V_25 ;
}
static T_1 F_20 ( char * V_55 , struct V_13 * V_49 ,
int V_50 , int V_57 )
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
V_25 = F_13 ( V_59 [ 0 ] , V_59 [ 1 ] , V_59 [ 2 ] , V_59 [ 3 ] , V_49 , V_50 , 0 ) ;
return V_25 == 0 ? V_58 : V_25 ;
}
static T_1 F_21 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 ,
struct V_15 * V_16 ,
struct V_17 * V_18 , int V_65 )
{
struct V_13 V_49 ;
char * V_55 ;
int V_25 ;
int V_66 = 0 ;
int V_57 ;
T_1 V_58 = 0 ;
if ( * V_64 != 0 )
return - V_52 ;
if ( V_65 == V_67 ) {
if ( V_63 < V_68 || V_63 > V_69 )
return - V_52 ;
} else {
if ( V_63 >= V_70 ) {
V_63 = V_70 - 1 ;
V_66 = 1 ;
}
}
V_55 = F_22 ( V_63 + 1 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_23 ( V_55 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_33;
}
if ( V_66 ) {
while ( V_63 > 0 && ( V_55 [ V_63 - 1 ] != '\n' ) )
-- V_63 ;
if ( V_63 == 0 ) {
V_25 = - V_52 ;
goto V_33;
}
}
V_55 [ V_63 ] = '\0' ;
V_57 = ( V_65 == V_72 ? 4 : 3 ) ;
while ( V_58 < V_63 ) {
if ( V_65 == V_67 ) {
V_25 = F_19 ( V_55 , & V_49 , 1 ) ;
if ( V_25 != 0 ) {
V_25 = - V_52 ;
goto V_33;
}
V_58 = V_63 ;
} else {
V_25 = F_20 ( V_55 + V_58 , & V_49 , 1 , V_57 ) ;
if ( V_25 <= 0 ) {
V_25 = - V_52 ;
goto V_33;
}
V_58 += V_25 ;
}
if ( V_16 == NULL )
V_25 = F_6 ( & V_49 , & V_49 . V_27 -> V_73 ,
& V_49 . V_27 -> V_74 , 1 ) ;
else
V_25 = F_6 ( & V_49 , V_16 , V_18 , 0 ) ;
if ( V_25 )
goto V_33;
}
V_25 = V_58 ;
V_33:
F_18 ( V_55 ) ;
return V_25 ;
}
static void * F_24 ( struct V_75 * V_76 , T_4 * V_77 ,
struct V_15 * V_78 )
{
struct V_15 * V_34 ;
if ( V_76 -> V_79 == 0 )
V_76 -> V_80 = V_78 ;
if ( V_76 -> V_80 == NULL )
return NULL ;
V_34 = V_76 -> V_80 ;
if ( F_25 ( V_34 ) )
return NULL ;
if ( V_76 -> V_79 == 0 )
return V_34 -> V_81 ;
return V_34 ;
}
static void * F_26 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 ,
struct V_15 * V_78 )
{
struct V_15 * V_34 = V_82 ;
if ( F_27 ( V_34 , V_78 ) ) {
V_76 -> V_80 = NULL ;
return NULL ;
}
V_76 -> V_80 = V_34 -> V_81 ;
return V_34 -> V_81 ;
}
static void F_28 ( struct V_75 * V_76 , void * V_82 )
{
}
static void F_29 ( struct V_75 * V_76 , struct V_20 * V_14 , int V_83 )
{
if ( strlen ( V_14 -> V_27 -> V_54 ) >= V_83 ||
strlen ( V_14 -> V_26 ) >= V_83 )
return;
if ( V_14 -> V_28 == 0 )
return;
F_30 ( V_76 , L_1 , V_14 -> V_27 -> V_54 , V_14 -> V_26 ) ;
F_31 ( V_76 , ' ' ) ;
if ( V_14 -> V_28 & V_39 )
F_31 ( V_76 , 'r' ) ;
if ( V_14 -> V_28 & V_40 )
F_31 ( V_76 , 'w' ) ;
if ( V_14 -> V_28 & V_41 )
F_31 ( V_76 , 'x' ) ;
if ( V_14 -> V_28 & V_42 )
F_31 ( V_76 , 'a' ) ;
if ( V_14 -> V_28 & V_43 )
F_31 ( V_76 , 't' ) ;
if ( V_14 -> V_28 & V_44 )
F_31 ( V_76 , 'l' ) ;
F_31 ( V_76 , '\n' ) ;
}
static void * F_32 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_24 ( V_76 , V_77 , & V_36 ) ;
}
static void * F_33 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
return F_26 ( V_76 , V_82 , V_77 , & V_36 ) ;
}
static int F_34 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_22 * V_23 =
F_35 ( V_34 , struct V_22 , V_34 ) ;
F_29 ( V_76 , V_23 -> V_35 , V_56 ) ;
return 0 ;
}
static int F_36 ( struct V_84 * V_84 , struct V_61 * V_61 )
{
return F_37 ( V_61 , & V_85 ) ;
}
static T_1 F_38 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_39 ( V_86 ) )
return - V_87 ;
return F_21 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_67 ) ;
}
static void F_40 ( void )
{
int V_25 ;
struct V_88 * V_89 ;
struct V_4 V_90 ;
F_2 ( & V_90 ) ;
V_25 = F_41 ( NULL , V_91 , NULL , NULL , & V_90 ) ;
if ( V_25 != 0 )
F_42 ( V_92 L_2 ,
V_93 , __LINE__ , V_25 ) ;
V_89 = F_22 ( sizeof( struct V_88 ) , V_31 ) ;
if ( V_89 == NULL )
F_43 ( L_3 ) ;
V_89 -> V_94 . V_95 = NULL ;
V_89 -> V_96 = V_97 ;
V_89 -> type = V_98 ;
V_89 -> V_99 [ 0 ] = V_100 ;
for ( V_25 = 1 ; V_25 < V_101 ; V_25 ++ )
V_89 -> V_99 [ V_25 ] = V_102 ;
V_25 = F_44 ( V_89 , & V_90 ) ;
if ( V_25 != 0 ) {
F_42 ( V_92 L_4 ,
V_93 , __LINE__ , V_25 ) ;
F_18 ( V_89 ) ;
return;
}
V_25 = F_45 ( V_89 -> V_96 , NULL , NULL , NULL , & V_90 ) ;
if ( V_25 != 0 ) {
F_42 ( V_92 L_5 ,
V_93 , __LINE__ , V_25 ) ;
F_18 ( V_89 ) ;
return;
}
}
static void F_46 ( char * V_103 )
{
int V_25 ;
struct V_4 V_90 ;
F_2 ( & V_90 ) ;
if ( V_103 != NULL ) {
V_25 = F_41 ( V_103 , V_91 , NULL , NULL , & V_90 ) ;
if ( V_25 != 0 )
F_42 ( V_92 L_2 ,
V_93 , __LINE__ , V_25 ) ;
}
if ( V_104 == NULL )
V_104 = & V_105 ;
V_25 = F_47 ( V_104 -> V_54 , V_91 ,
NULL , NULL , & V_90 ) ;
if ( V_25 != 0 )
F_42 ( V_92 L_6 ,
V_93 , __LINE__ , V_25 ) ;
}
static void * F_48 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_24 ( V_76 , V_77 , & V_106 ) ;
}
static void * F_49 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
return F_26 ( V_76 , V_82 , V_77 , & V_106 ) ;
}
static int F_50 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_6 * V_7 =
F_35 ( V_34 , struct V_6 , V_34 ) ;
struct V_107 * V_108 = V_7 -> V_109 . V_110 . V_111 . V_1 ;
char V_112 = '/' ;
int V_60 ;
if ( strlen ( V_7 -> V_54 ) >= V_56 )
return 0 ;
F_30 ( V_76 , L_7 , V_7 -> V_54 , V_7 -> V_109 . V_110 . V_111 . V_113 ) ;
for ( V_60 = F_51 ( V_108 , 0 ) ; V_60 >= 0 ;
V_60 = F_51 ( V_108 , V_60 + 1 ) ) {
F_30 ( V_76 , L_8 , V_112 , V_60 ) ;
V_112 = ',' ;
}
F_31 ( V_76 , '\n' ) ;
return 0 ;
}
static int F_52 ( struct V_84 * V_84 , struct V_61 * V_61 )
{
return F_37 ( V_61 , & V_114 ) ;
}
static T_1 F_53 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 , int V_65 )
{
struct V_6 * V_7 ;
struct V_115 V_116 ;
char V_117 [ V_3 ] ;
int V_118 ;
unsigned int V_1 ;
int V_119 ;
T_1 V_25 = - V_52 ;
char * V_55 = NULL ;
char * V_49 ;
int V_120 ;
int V_60 ;
if ( ! F_39 ( V_86 ) )
return - V_87 ;
if ( * V_64 != 0 )
return - V_52 ;
if ( V_65 == V_67 &&
( V_63 < V_121 || V_63 > V_122 ) )
return - V_52 ;
V_55 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_23 ( V_55 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_123;
}
V_55 [ V_63 ] = '\0' ;
V_49 = V_55 ;
F_7 ( & V_124 ) ;
V_7 = F_14 ( V_49 , 0 ) ;
if ( V_7 == NULL )
goto V_33;
if ( V_65 == V_67 )
V_49 += V_56 ;
else
V_49 += strlen ( V_7 -> V_54 ) + 1 ;
V_120 = sscanf ( V_49 , L_9 , & V_118 ) ;
if ( V_120 != 1 || V_118 > V_125 )
goto V_33;
V_49 += V_126 ;
V_120 = sscanf ( V_49 , L_9 , & V_119 ) ;
if ( V_120 != 1 || V_119 > V_127 )
goto V_33;
if ( V_65 == V_67 &&
V_63 != ( V_121 + V_119 * V_126 ) )
goto V_33;
memset ( V_117 , 0 , sizeof( V_117 ) ) ;
for ( V_60 = 0 ; V_60 < V_119 ; V_60 ++ ) {
V_49 += V_126 ;
V_120 = sscanf ( V_49 , L_10 , & V_1 ) ;
if ( V_120 != 1 || V_1 > V_127 )
goto V_33;
F_1 ( V_1 , V_117 ) ;
}
V_25 = F_54 ( V_118 , V_117 , & V_116 , V_3 ) ;
if ( V_25 >= 0 ) {
F_55 ( V_7 -> V_109 . V_110 . V_111 . V_1 ) ;
V_7 -> V_109 . V_110 . V_111 . V_1 = V_116 . V_110 . V_111 . V_1 ;
V_7 -> V_109 . V_110 . V_111 . V_113 = V_116 . V_110 . V_111 . V_113 ;
V_25 = V_63 ;
}
V_33:
F_11 ( & V_124 ) ;
V_123:
F_18 ( V_55 ) ;
return V_25 ;
}
static T_1 F_56 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_53 ( V_61 , V_62 , V_63 , V_64 , V_67 ) ;
}
static int F_57 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_6 * V_7 =
F_35 ( V_34 , struct V_6 , V_34 ) ;
struct V_107 * V_108 = V_7 -> V_109 . V_110 . V_111 . V_1 ;
char V_112 = '/' ;
int V_60 ;
F_30 ( V_76 , L_7 , V_7 -> V_54 , V_7 -> V_109 . V_110 . V_111 . V_113 ) ;
for ( V_60 = F_51 ( V_108 , 0 ) ; V_60 >= 0 ;
V_60 = F_51 ( V_108 , V_60 + 1 ) ) {
F_30 ( V_76 , L_8 , V_112 , V_60 ) ;
V_112 = ',' ;
}
F_31 ( V_76 , '\n' ) ;
return 0 ;
}
static int F_58 ( struct V_84 * V_84 , struct V_61 * V_61 )
{
return F_37 ( V_61 , & V_128 ) ;
}
static T_1 F_59 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_53 ( V_61 , V_62 , V_63 , V_64 , V_129 ) ;
}
static void * F_60 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_24 ( V_76 , V_77 , & V_130 ) ;
}
static void * F_61 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
return F_26 ( V_76 , V_82 , V_77 , & V_130 ) ;
}
static int F_62 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_131 * V_7 =
F_35 ( V_34 , struct V_131 , V_34 ) ;
unsigned char * V_132 = ( char * ) & V_7 -> V_133 . V_134 . V_135 ;
int V_136 ;
T_5 V_137 = F_63 ( V_7 -> V_138 . V_135 ) ;
for ( V_136 = 0 ; V_137 ; V_137 <<= 1 , V_136 ++ ) ;
F_30 ( V_76 , L_11 ,
V_132 [ 0 ] , V_132 [ 1 ] , V_132 [ 2 ] , V_132 [ 3 ] , V_136 , V_7 -> V_139 ) ;
return 0 ;
}
static int F_64 ( struct V_84 * V_84 , struct V_61 * V_61 )
{
return F_37 ( V_61 , & V_140 ) ;
}
static void F_65 ( struct V_131 * V_141 )
{
struct V_131 * V_142 , * V_143 ;
if ( F_25 ( & V_130 ) ) {
F_10 ( & V_141 -> V_34 , & V_130 ) ;
return;
}
V_142 = F_66 ( V_130 . V_81 ,
struct V_131 , V_34 ) ;
if ( V_141 -> V_138 . V_135 > V_142 -> V_138 . V_135 ) {
F_10 ( & V_141 -> V_34 , & V_130 ) ;
return;
}
F_8 (m, &smk_netlbladdr_list, list) {
if ( F_27 ( & V_142 -> V_34 , & V_130 ) ) {
F_10 ( & V_141 -> V_34 , & V_142 -> V_34 ) ;
return;
}
V_143 = F_66 ( V_142 -> V_34 . V_81 ,
struct V_131 , V_34 ) ;
if ( V_141 -> V_138 . V_135 > V_143 -> V_138 . V_135 ) {
F_10 ( & V_141 -> V_34 , & V_142 -> V_34 ) ;
return;
}
}
}
static T_1 F_67 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_131 * V_7 ;
struct V_144 V_145 ;
char * V_146 ;
char * V_21 ;
char * V_55 ;
char * V_147 = ( char * ) & V_145 . V_134 . V_135 ;
int V_25 ;
struct V_4 V_148 ;
struct V_149 V_150 ;
unsigned int V_142 ;
int V_24 ;
T_5 V_151 = ( 1 << 31 ) ;
T_6 V_152 ;
T_5 V_137 ;
if ( ! F_39 ( V_86 ) )
return - V_87 ;
if ( * V_64 != 0 )
return - V_52 ;
if ( V_63 < V_153 )
return - V_52 ;
V_55 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_23 ( V_55 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_154;
}
V_146 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_146 == NULL ) {
V_25 = - V_32 ;
goto V_154;
}
V_55 [ V_63 ] = '\0' ;
V_25 = sscanf ( V_55 , L_12 ,
& V_147 [ 0 ] , & V_147 [ 1 ] , & V_147 [ 2 ] , & V_147 [ 3 ] , & V_142 , V_146 ) ;
if ( V_25 != 6 ) {
V_25 = sscanf ( V_55 , L_13 ,
& V_147 [ 0 ] , & V_147 [ 1 ] , & V_147 [ 2 ] , & V_147 [ 3 ] , V_146 ) ;
if ( V_25 != 5 ) {
V_25 = - V_52 ;
goto V_155;
}
V_142 = V_156 ;
}
if ( V_142 > V_156 ) {
V_25 = - V_52 ;
goto V_155;
}
if ( V_146 [ 0 ] != '-' ) {
V_21 = F_15 ( V_146 , 0 ) ;
if ( V_21 == NULL ) {
V_25 = - V_52 ;
goto V_155;
}
} else {
if ( strcmp ( V_146 , V_157 ) == 0 )
V_21 = ( char * ) V_157 ;
else {
V_25 = - V_52 ;
goto V_155;
}
}
for ( V_137 = 0 ; V_142 > 0 ; V_142 -- ) {
V_137 |= V_151 ;
V_151 >>= 1 ;
}
V_150 . V_135 = F_68 ( V_137 ) ;
V_145 . V_134 . V_135 &= V_150 . V_135 ;
F_7 ( & V_158 ) ;
V_152 = V_145 . V_134 . V_135 ;
V_24 = 0 ;
F_8 (skp, &smk_netlbladdr_list, list) {
if ( V_7 -> V_133 . V_134 . V_135 == V_152 &&
V_7 -> V_138 . V_135 == V_150 . V_135 ) {
V_24 = 1 ;
break;
}
}
F_2 ( & V_148 ) ;
if ( V_24 == 0 ) {
V_7 = F_9 ( sizeof( * V_7 ) , V_31 ) ;
if ( V_7 == NULL )
V_25 = - V_32 ;
else {
V_25 = 0 ;
V_7 -> V_133 . V_134 . V_135 = V_145 . V_134 . V_135 ;
V_7 -> V_138 . V_135 = V_150 . V_135 ;
V_7 -> V_139 = V_21 ;
F_65 ( V_7 ) ;
}
} else {
if ( V_7 -> V_139 != V_157 )
V_25 = F_69 ( & V_159 , NULL ,
& V_7 -> V_133 . V_134 , & V_7 -> V_138 ,
V_91 , & V_148 ) ;
else
V_25 = 0 ;
V_7 -> V_139 = V_21 ;
}
if ( V_25 == 0 && V_21 != V_157 )
V_25 = F_70 ( & V_159 , NULL ,
& V_7 -> V_133 . V_134 , & V_7 -> V_138 , V_91 ,
F_71 ( V_7 -> V_139 ) , & V_148 ) ;
if ( V_25 == 0 )
V_25 = V_63 ;
F_11 ( & V_158 ) ;
V_155:
F_18 ( V_146 ) ;
V_154:
F_18 ( V_55 ) ;
return V_25 ;
}
static T_1 F_72 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_161 , L_9 , V_97 ) ;
V_25 = F_73 ( V_62 , V_63 , V_64 , V_161 , strlen ( V_161 ) ) ;
return V_25 ;
}
static T_1 F_74 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 80 ] ;
int V_60 ;
if ( ! F_39 ( V_86 ) )
return - V_87 ;
if ( V_63 >= sizeof( V_161 ) || V_63 == 0 )
return - V_52 ;
if ( F_23 ( V_161 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_161 [ V_63 ] = '\0' ;
if ( sscanf ( V_161 , L_9 , & V_60 ) != 1 )
return - V_52 ;
V_97 = V_60 ;
F_40 () ;
return V_63 ;
}
static T_1 F_75 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_161 , L_9 , V_162 ) ;
V_25 = F_73 ( V_62 , V_63 , V_64 , V_161 , strlen ( V_161 ) ) ;
return V_25 ;
}
static T_1 F_76 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char V_161 [ 80 ] ;
int V_60 ;
if ( ! F_39 ( V_86 ) )
return - V_87 ;
if ( V_63 >= sizeof( V_161 ) || V_63 == 0 )
return - V_52 ;
if ( F_23 ( V_161 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_161 [ V_63 ] = '\0' ;
if ( sscanf ( V_161 , L_9 , & V_60 ) != 1 )
return - V_52 ;
if ( V_162 != V_60 ) {
F_7 ( & V_163 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_109 . V_110 . V_111 . V_113 ==
V_162 )
V_7 -> V_109 . V_110 . V_111 . V_113 = V_60 ;
V_162 = V_60 ;
F_11 ( & V_163 ) ;
}
return V_63 ;
}
static T_1 F_77 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_161 , L_9 , V_164 ) ;
V_25 = F_73 ( V_62 , V_63 , V_64 , V_161 , strlen ( V_161 ) ) ;
return V_25 ;
}
static T_1 F_78 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char V_161 [ 80 ] ;
int V_60 ;
if ( ! F_39 ( V_86 ) )
return - V_87 ;
if ( V_63 >= sizeof( V_161 ) || V_63 == 0 )
return - V_52 ;
if ( F_23 ( V_161 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_161 [ V_63 ] = '\0' ;
if ( sscanf ( V_161 , L_9 , & V_60 ) != 1 )
return - V_52 ;
if ( V_164 != V_60 ) {
F_7 ( & V_163 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_109 . V_110 . V_111 . V_113 ==
V_164 )
V_7 -> V_109 . V_110 . V_111 . V_113 = V_60 ;
V_164 = V_60 ;
F_11 ( & V_163 ) ;
}
return V_63 ;
}
static T_1 F_79 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_165 , T_4 * V_64 )
{
T_1 V_25 ;
int V_166 ;
if ( * V_64 != 0 )
return 0 ;
F_7 ( & V_167 ) ;
V_166 = strlen ( V_104 -> V_54 ) + 1 ;
if ( V_165 >= V_166 )
V_25 = F_73 ( V_62 , V_165 , V_64 ,
V_104 -> V_54 ,
V_166 ) ;
else
V_25 = - V_52 ;
F_11 ( & V_167 ) ;
return V_25 ;
}
static T_1 F_80 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char * V_103 ;
char * V_55 ;
int V_25 = V_63 ;
if ( ! F_39 ( V_86 ) )
return - V_87 ;
V_55 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_23 ( V_55 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_33;
}
V_7 = F_14 ( V_55 , V_63 ) ;
if ( V_7 == NULL ) {
V_25 = - V_52 ;
goto V_33;
}
F_7 ( & V_167 ) ;
V_103 = V_104 -> V_54 ;
V_104 = V_7 ;
F_46 ( V_103 ) ;
F_11 ( & V_167 ) ;
V_33:
F_18 ( V_55 ) ;
return V_25 ;
}
static T_1 F_81 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_165 , T_4 * V_64 )
{
char * V_146 = L_14 ;
T_1 V_25 = - V_52 ;
int V_166 ;
if ( * V_64 != 0 )
return 0 ;
if ( V_168 != NULL )
V_146 = V_168 -> V_54 ;
V_166 = strlen ( V_146 ) + 1 ;
if ( V_165 >= V_166 )
V_25 = F_73 ( V_62 , V_165 , V_64 , V_146 , V_166 ) ;
return V_25 ;
}
static T_1 F_82 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_55 ;
struct V_6 * V_7 = F_83 ( V_9 -> V_169 -> V_170 ) ;
int V_25 = V_63 ;
if ( ! F_39 ( V_86 ) )
return - V_87 ;
if ( V_168 != NULL && V_168 != V_7 )
return - V_87 ;
V_55 = F_9 ( V_63 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_23 ( V_55 , V_62 , V_63 ) != 0 )
V_25 = - V_71 ;
else
V_168 = F_14 ( V_55 , V_63 ) ;
F_18 ( V_55 ) ;
return V_25 ;
}
static T_1 F_84 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 32 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_161 , L_15 , V_171 ) ;
V_25 = F_73 ( V_62 , V_63 , V_64 , V_161 , strlen ( V_161 ) ) ;
return V_25 ;
}
static T_1 F_85 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 32 ] ;
int V_60 ;
if ( ! F_39 ( V_86 ) )
return - V_87 ;
if ( V_63 >= sizeof( V_161 ) || V_63 == 0 )
return - V_52 ;
if ( F_23 ( V_161 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_161 [ V_63 ] = '\0' ;
if ( sscanf ( V_161 , L_9 , & V_60 ) != 1 )
return - V_52 ;
if ( V_60 < 0 || V_60 > 3 )
return - V_52 ;
V_171 = V_60 ;
return V_63 ;
}
static void * F_86 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_172 * V_173 = F_87 () ;
return F_24 ( V_76 , V_77 , & V_173 -> V_73 ) ;
}
static void * F_88 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
struct V_172 * V_173 = F_87 () ;
return F_26 ( V_76 , V_82 , V_77 , & V_173 -> V_73 ) ;
}
static int F_89 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_20 * V_14 =
F_35 ( V_34 , struct V_20 , V_34 ) ;
F_29 ( V_76 , V_14 , V_56 ) ;
return 0 ;
}
static int F_90 ( struct V_84 * V_84 , struct V_61 * V_61 )
{
return F_37 ( V_61 , & V_174 ) ;
}
static T_1 F_91 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_172 * V_173 = F_87 () ;
return F_21 ( V_61 , V_62 , V_63 , V_64 , & V_173 -> V_73 ,
& V_173 -> V_74 , V_67 ) ;
}
static T_1 F_92 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 , int V_65 )
{
struct V_13 V_49 ;
char * V_55 ;
int V_175 ;
V_55 = F_93 ( V_61 , V_62 , V_63 ) ;
if ( F_94 ( V_55 ) )
return F_95 ( V_55 ) ;
if ( V_65 == V_67 ) {
if ( V_63 < V_69 )
return - V_52 ;
V_175 = F_19 ( V_55 , & V_49 , 0 ) ;
} else {
V_175 = F_20 ( V_55 , & V_49 , 0 , 3 ) ;
}
if ( V_175 >= 0 )
V_175 = V_28 ( V_49 . V_27 , V_49 . V_26 ,
V_49 . V_29 , NULL ) ;
else if ( V_175 != - V_53 )
return - V_52 ;
V_55 [ 0 ] = V_175 == 0 ? '1' : '0' ;
V_55 [ 1 ] = '\0' ;
F_96 ( V_61 , 2 ) ;
if ( V_65 == V_67 )
return V_69 ;
return V_63 ;
}
static T_1 F_97 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_92 ( V_61 , V_62 , V_63 , V_64 , V_67 ) ;
}
static int F_98 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_22 * V_23 =
F_35 ( V_34 , struct V_22 , V_34 ) ;
F_29 ( V_76 , V_23 -> V_35 , V_176 ) ;
return 0 ;
}
static int F_99 ( struct V_84 * V_84 , struct V_61 * V_61 )
{
return F_37 ( V_61 , & V_177 ) ;
}
static T_1 F_100 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_39 ( V_86 ) )
return - V_87 ;
return F_21 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_129 ) ;
}
static void * F_101 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_172 * V_173 = F_87 () ;
return F_24 ( V_76 , V_77 , & V_173 -> V_73 ) ;
}
static void * F_102 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
struct V_172 * V_173 = F_87 () ;
return F_26 ( V_76 , V_82 , V_77 , & V_173 -> V_73 ) ;
}
static int F_103 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_20 * V_14 =
F_35 ( V_34 , struct V_20 , V_34 ) ;
F_29 ( V_76 , V_14 , V_176 ) ;
return 0 ;
}
static int F_104 ( struct V_84 * V_84 , struct V_61 * V_61 )
{
return F_37 ( V_61 , & V_178 ) ;
}
static T_1 F_105 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_172 * V_173 = F_87 () ;
return F_21 ( V_61 , V_62 , V_63 , V_64 , & V_173 -> V_73 ,
& V_173 -> V_74 , V_129 ) ;
}
static T_1 F_106 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_92 ( V_61 , V_62 , V_63 , V_64 , V_129 ) ;
}
static T_1 F_107 ( struct V_61 * V_61 , const char T_2 * V_62 ,
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
return - V_52 ;
if ( ! F_39 ( V_86 ) )
return - V_87 ;
if ( V_63 == 0 || V_63 > V_176 )
return - V_52 ;
V_55 = F_9 ( V_63 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_23 ( V_55 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_155;
}
V_38 = F_16 ( V_55 , V_63 ) ;
if ( V_38 == NULL ) {
V_25 = - V_52 ;
goto V_155;
}
V_7 = F_17 ( V_38 ) ;
if ( V_7 == NULL )
goto V_155;
V_16 = & V_7 -> V_73 ;
V_18 = & V_7 -> V_74 ;
F_7 ( V_18 ) ;
F_8 (sp, rule_list, list)
V_21 -> V_28 = 0 ;
F_11 ( V_18 ) ;
V_155:
F_18 ( V_55 ) ;
F_18 ( V_38 ) ;
return V_25 ;
}
static int F_108 ( void )
{
V_179 = F_109 ( L_16 , NULL , V_180 ) ;
if ( ! V_179 )
return - V_32 ;
return 0 ;
}
static T_1 F_110 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_39 ( V_86 ) )
return - V_87 ;
return F_21 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_72 ) ;
}
static T_1 F_111 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_165 , T_4 * V_64 )
{
struct V_6 * V_7 ;
T_1 V_25 = - V_52 ;
int V_166 ;
if ( * V_64 != 0 )
return 0 ;
if ( V_181 == NULL )
V_7 = & V_182 ;
else
V_7 = V_181 ;
V_166 = strlen ( V_7 -> V_54 ) + 1 ;
if ( V_165 >= V_166 )
V_25 = F_73 ( V_62 , V_165 , V_64 , V_7 -> V_54 ,
V_166 ) ;
return V_25 ;
}
static T_1 F_112 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_55 ;
struct V_6 * V_7 ;
int V_25 = V_63 ;
if ( ! F_39 ( V_86 ) )
return - V_87 ;
V_55 = F_9 ( V_63 , V_31 ) ;
if ( V_55 == NULL )
return - V_32 ;
if ( F_23 ( V_55 , V_62 , V_63 ) != 0 )
V_25 = - V_71 ;
else {
V_7 = F_14 ( V_55 , V_63 ) ;
if ( V_7 == NULL )
V_25 = - V_52 ;
else
V_181 = F_14 ( V_55 , V_63 ) ;
}
F_18 ( V_55 ) ;
return V_25 ;
}
static T_1 F_113 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 32 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_161 , L_15 , V_183 ) ;
V_25 = F_73 ( V_62 , V_63 , V_64 , V_161 , strlen ( V_161 ) ) ;
return V_25 ;
}
static T_1 F_114 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 32 ] ;
int V_60 ;
if ( ! F_39 ( V_86 ) )
return - V_87 ;
if ( * V_64 != 0 || V_63 >= sizeof( V_161 ) || V_63 == 0 )
return - V_52 ;
if ( F_23 ( V_161 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_161 [ V_63 ] = '\0' ;
if ( sscanf ( V_161 , L_9 , & V_60 ) != 1 )
return - V_52 ;
if ( V_60 < V_184 || V_60 > V_185 )
return - V_52 ;
V_183 = V_60 ;
return V_63 ;
}
static int F_115 ( struct V_186 * V_187 , void * V_55 , int V_188 )
{
int V_25 ;
struct V_84 * V_189 ;
static struct V_190 V_191 [] = {
[ V_192 ] = {
L_17 , & V_193 , V_194 | V_195 } ,
[ V_196 ] = {
L_18 , & V_197 , V_194 | V_195 } ,
[ V_198 ] = {
L_19 , & V_199 , V_194 | V_195 } ,
[ V_200 ] = {
L_20 , & V_201 , V_194 | V_195 } ,
[ V_202 ] = {
L_21 , & V_203 , V_194 | V_195 } ,
[ V_204 ] = {
L_22 , & V_205 , V_194 | V_195 } ,
[ V_206 ] = {
L_23 , & V_207 , V_194 | V_195 } ,
[ V_208 ] = {
L_24 , & V_209 , V_194 | V_195 } ,
[ V_210 ] = {
L_25 , & V_211 , V_194 | V_212 } ,
[ V_213 ] = {
L_26 , & V_214 , V_194 | V_212 } ,
[ V_215 ] = {
L_27 , & V_216 , V_194 | V_195 } ,
[ V_217 ] = {
L_28 , & V_218 , V_194 | V_195 } ,
[ V_219 ] = {
L_29 , & V_220 , V_194 | V_212 } ,
[ V_221 ] = {
L_30 , & V_222 , V_194 | V_212 } ,
[ V_223 ] = {
L_31 , & V_224 , V_194 | V_195 } ,
[ V_225 ] = {
L_32 , & V_226 ,
V_194 | V_195 } ,
[ V_227 ] = {
L_33 , & V_228 , V_194 | V_195 } ,
[ V_229 ] = {
L_34 , & V_230 , V_194 | V_195 } ,
[ V_231 ] = {
L_35 , & V_232 , V_194 | V_195 } ,
{ L_14 }
} ;
V_25 = F_116 ( V_187 , V_233 , V_191 ) ;
if ( V_25 != 0 ) {
F_42 ( V_234 L_36 ,
V_93 , V_25 ) ;
return V_25 ;
}
V_189 = V_187 -> V_235 -> V_236 ;
return 0 ;
}
static struct V_237 * F_117 ( struct V_238 * V_239 ,
int V_240 , const char * V_241 , void * V_55 )
{
return F_118 ( V_239 , V_240 , V_55 , F_115 ) ;
}
static int T_7 F_119 ( struct V_6 * V_7 )
{
V_7 -> V_109 . V_242 = V_7 -> V_54 ;
V_7 -> V_109 . V_240 =
V_243 | V_244 ;
return F_54 ( V_162 , V_7 -> V_54 ,
& V_7 -> V_109 , strlen ( V_7 -> V_54 ) ) ;
}
static int T_7 F_120 ( void )
{
int V_245 ;
int V_25 ;
if ( ! F_121 ( & V_246 ) )
return 0 ;
V_245 = F_108 () ;
if ( V_245 )
F_42 ( V_234 L_37 ) ;
V_245 = F_122 ( & V_247 ) ;
if ( ! V_245 ) {
V_248 = F_123 ( & V_247 ) ;
if ( F_94 ( V_248 ) ) {
F_42 ( V_234 L_38 ) ;
V_245 = F_95 ( V_248 ) ;
V_248 = NULL ;
}
}
F_40 () ;
F_46 ( NULL ) ;
V_25 = F_119 ( & V_105 ) ;
if ( V_245 == 0 && V_25 < 0 )
V_245 = V_25 ;
V_25 = F_119 ( & V_249 ) ;
if ( V_245 == 0 && V_25 < 0 )
V_245 = V_25 ;
V_25 = F_119 ( & V_250 ) ;
if ( V_245 == 0 && V_25 < 0 )
V_245 = V_25 ;
V_25 = F_119 ( & V_251 ) ;
if ( V_245 == 0 && V_25 < 0 )
V_245 = V_25 ;
V_25 = F_119 ( & V_182 ) ;
if ( V_245 == 0 && V_25 < 0 )
V_245 = V_25 ;
V_25 = F_119 ( & V_252 ) ;
if ( V_245 == 0 && V_25 < 0 )
V_245 = V_25 ;
return V_245 ;
}
