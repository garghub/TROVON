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
if ( F_15 ( V_50 -> V_27 ) )
return F_16 ( V_50 -> V_27 ) ;
V_50 -> V_26 = F_14 ( V_47 , V_52 ) ;
if ( F_15 ( V_50 -> V_26 ) )
return F_16 ( V_50 -> V_26 ) ;
} else {
V_38 = F_17 ( V_46 , V_52 ) ;
if ( F_15 ( V_38 ) )
return F_16 ( V_38 ) ;
V_7 = F_18 ( V_38 ) ;
F_19 ( V_38 ) ;
if ( V_7 == NULL )
return - V_53 ;
V_50 -> V_27 = V_7 ;
V_38 = F_17 ( V_47 , V_52 ) ;
if ( F_15 ( V_38 ) )
return F_16 ( V_38 ) ;
V_7 = F_18 ( V_38 ) ;
F_19 ( V_38 ) ;
if ( V_7 == NULL )
return - V_53 ;
V_50 -> V_26 = V_7 ;
}
V_50 -> V_29 = F_12 ( V_48 ) ;
if ( V_49 )
V_50 -> V_30 = F_12 ( V_49 ) ;
else
V_50 -> V_30 = ~ V_50 -> V_29 ;
return 0 ;
}
static int F_20 ( const char * V_54 , struct V_13 * V_50 ,
int V_51 )
{
int V_25 ;
V_25 = F_13 ( V_54 , V_54 + V_55 ,
V_54 + V_55 + V_55 , NULL , V_50 ,
V_51 , V_55 ) ;
return V_25 ;
}
static T_1 F_21 ( char * V_54 , struct V_13 * V_50 ,
int V_51 , int V_56 )
{
T_1 V_57 = 0 ;
char * V_58 [ 4 ] ;
int V_25 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_56 ; ++ V_59 ) {
while ( isspace ( V_54 [ V_57 ] ) )
V_54 [ V_57 ++ ] = '\0' ;
if ( V_54 [ V_57 ] == '\0' )
return - V_60 ;
V_58 [ V_59 ] = V_54 + V_57 ;
while ( V_54 [ V_57 ] && ! isspace ( V_54 [ V_57 ] ) )
++ V_57 ;
}
while ( isspace ( V_54 [ V_57 ] ) )
V_54 [ V_57 ++ ] = '\0' ;
while ( V_59 < 4 )
V_58 [ V_59 ++ ] = NULL ;
V_25 = F_13 ( V_58 [ 0 ] , V_58 [ 1 ] , V_58 [ 2 ] , V_58 [ 3 ] , V_50 , V_51 , 0 ) ;
return V_25 == 0 ? V_57 : V_25 ;
}
static T_1 F_22 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 ,
struct V_15 * V_16 ,
struct V_17 * V_18 , int V_65 )
{
struct V_13 V_50 ;
char * V_54 ;
int V_25 ;
int V_66 = 0 ;
int V_56 ;
T_1 V_57 = 0 ;
if ( * V_64 != 0 )
return - V_60 ;
if ( V_65 == V_67 ) {
if ( V_63 < V_68 || V_63 > V_69 )
return - V_60 ;
} else {
if ( V_63 >= V_70 ) {
V_63 = V_70 - 1 ;
V_66 = 1 ;
}
}
V_54 = F_23 ( V_63 + 1 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_33;
}
if ( V_66 ) {
while ( V_63 > 0 && ( V_54 [ V_63 - 1 ] != '\n' ) )
-- V_63 ;
if ( V_63 == 0 ) {
V_25 = - V_60 ;
goto V_33;
}
}
V_54 [ V_63 ] = '\0' ;
V_56 = ( V_65 == V_72 ? 4 : 3 ) ;
while ( V_57 < V_63 ) {
if ( V_65 == V_67 ) {
V_25 = F_20 ( V_54 , & V_50 , 1 ) ;
if ( V_25 < 0 )
goto V_33;
V_57 = V_63 ;
} else {
V_25 = F_21 ( V_54 + V_57 , & V_50 , 1 , V_56 ) ;
if ( V_25 < 0 )
goto V_33;
if ( V_25 == 0 ) {
V_25 = - V_60 ;
goto V_33;
}
V_57 += V_25 ;
}
if ( V_16 == NULL )
V_25 = F_6 ( & V_50 , & V_50 . V_27 -> V_73 ,
& V_50 . V_27 -> V_74 , 1 ) ;
else
V_25 = F_6 ( & V_50 , V_16 , V_18 , 0 ) ;
if ( V_25 )
goto V_33;
}
V_25 = V_57 ;
V_33:
F_19 ( V_54 ) ;
return V_25 ;
}
static void * F_25 ( struct V_75 * V_76 , T_4 * V_77 ,
struct V_15 * V_78 )
{
struct V_15 * V_34 ;
int V_59 = * V_77 ;
F_26 () ;
for ( V_34 = F_27 ( F_28 ( V_78 ) ) ;
V_34 != V_78 ;
V_34 = F_27 ( F_28 ( V_34 ) ) ) {
if ( V_59 -- == 0 )
return V_34 ;
}
return NULL ;
}
static void * F_29 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 ,
struct V_15 * V_78 )
{
struct V_15 * V_34 = V_79 ;
++ * V_77 ;
V_34 = F_27 ( F_28 ( V_34 ) ) ;
return ( V_34 == V_78 ) ? NULL : V_34 ;
}
static void F_30 ( struct V_75 * V_76 , void * V_79 )
{
F_31 () ;
}
static void F_32 ( struct V_75 * V_76 , struct V_20 * V_14 , int V_80 )
{
if ( strlen ( V_14 -> V_27 -> V_81 ) >= V_80 ||
strlen ( V_14 -> V_26 -> V_81 ) >= V_80 )
return;
if ( V_14 -> V_28 == 0 )
return;
F_33 ( V_76 , L_1 ,
V_14 -> V_27 -> V_81 ,
V_14 -> V_26 -> V_81 ) ;
F_34 ( V_76 , ' ' ) ;
if ( V_14 -> V_28 & V_39 )
F_34 ( V_76 , 'r' ) ;
if ( V_14 -> V_28 & V_40 )
F_34 ( V_76 , 'w' ) ;
if ( V_14 -> V_28 & V_41 )
F_34 ( V_76 , 'x' ) ;
if ( V_14 -> V_28 & V_42 )
F_34 ( V_76 , 'a' ) ;
if ( V_14 -> V_28 & V_43 )
F_34 ( V_76 , 't' ) ;
if ( V_14 -> V_28 & V_44 )
F_34 ( V_76 , 'l' ) ;
if ( V_14 -> V_28 & V_45 )
F_34 ( V_76 , 'b' ) ;
F_34 ( V_76 , '\n' ) ;
}
static void * F_35 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_25 ( V_76 , V_77 , & V_36 ) ;
}
static void * F_36 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
return F_29 ( V_76 , V_79 , V_77 , & V_36 ) ;
}
static int F_37 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_22 * V_23 =
F_38 ( V_34 , struct V_22 , V_34 ) ;
F_32 ( V_76 , V_23 -> V_35 , V_55 ) ;
return 0 ;
}
static int F_39 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_83 ) ;
}
static T_1 F_41 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_42 ( V_84 ) )
return - V_85 ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_67 ) ;
}
static void F_43 ( void )
{
int V_25 ;
struct V_86 * V_87 ;
struct V_4 V_88 ;
F_2 ( & V_88 ) ;
V_25 = F_44 ( NULL , V_89 , NULL , NULL , & V_88 ) ;
if ( V_25 != 0 )
F_45 ( V_90 L_2 ,
V_91 , __LINE__ , V_25 ) ;
V_87 = F_23 ( sizeof( struct V_86 ) , V_31 ) ;
if ( V_87 == NULL )
F_46 ( L_3 ) ;
V_87 -> V_92 . V_93 = NULL ;
V_87 -> V_94 = V_95 ;
V_87 -> type = V_96 ;
V_87 -> V_97 [ 0 ] = V_98 ;
for ( V_25 = 1 ; V_25 < V_99 ; V_25 ++ )
V_87 -> V_97 [ V_25 ] = V_100 ;
V_25 = F_47 ( V_87 , & V_88 ) ;
if ( V_25 != 0 ) {
F_45 ( V_90 L_4 ,
V_91 , __LINE__ , V_25 ) ;
F_19 ( V_87 ) ;
return;
}
V_25 = F_48 ( V_87 -> V_94 , NULL , NULL , NULL , & V_88 ) ;
if ( V_25 != 0 ) {
F_45 ( V_90 L_5 ,
V_91 , __LINE__ , V_25 ) ;
F_19 ( V_87 ) ;
return;
}
}
static void F_49 ( char * V_101 )
{
int V_25 ;
struct V_4 V_88 ;
F_2 ( & V_88 ) ;
if ( V_101 != NULL ) {
V_25 = F_44 ( V_101 , V_89 , NULL , NULL , & V_88 ) ;
if ( V_25 != 0 )
F_45 ( V_90 L_2 ,
V_91 , __LINE__ , V_25 ) ;
}
if ( V_102 == NULL )
V_102 = & V_103 ;
V_25 = F_50 ( V_102 -> V_81 , V_89 ,
NULL , NULL , & V_88 ) ;
if ( V_25 != 0 )
F_45 ( V_90 L_6 ,
V_91 , __LINE__ , V_25 ) ;
}
static void * F_51 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_25 ( V_76 , V_77 , & V_104 ) ;
}
static void * F_52 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
return F_29 ( V_76 , V_79 , V_77 , & V_104 ) ;
}
static int F_53 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_6 * V_7 =
F_38 ( V_34 , struct V_6 , V_34 ) ;
struct V_105 * V_106 = V_7 -> V_107 . V_108 . V_109 . V_1 ;
char V_110 = '/' ;
int V_59 ;
if ( strlen ( V_7 -> V_81 ) >= V_55 )
return 0 ;
F_33 ( V_76 , L_7 , V_7 -> V_81 , V_7 -> V_107 . V_108 . V_109 . V_111 ) ;
for ( V_59 = F_54 ( V_106 , 0 ) ; V_59 >= 0 ;
V_59 = F_54 ( V_106 , V_59 + 1 ) ) {
F_33 ( V_76 , L_8 , V_110 , V_59 ) ;
V_110 = ',' ;
}
F_34 ( V_76 , '\n' ) ;
return 0 ;
}
static int F_55 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_112 ) ;
}
static T_1 F_56 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 , int V_65 )
{
struct V_6 * V_7 ;
struct V_113 V_114 ;
char V_115 [ V_3 ] ;
int V_116 ;
unsigned int V_1 ;
int V_117 ;
T_1 V_25 = - V_60 ;
char * V_54 = NULL ;
char * V_50 ;
int V_118 ;
int V_59 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( * V_64 != 0 )
return - V_60 ;
if ( V_65 == V_67 &&
( V_63 < V_119 || V_63 > V_120 ) )
return - V_60 ;
V_54 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_121;
}
V_54 [ V_63 ] = '\0' ;
V_50 = V_54 ;
F_7 ( & V_122 ) ;
V_7 = F_14 ( V_50 , 0 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_33;
}
if ( V_65 == V_67 )
V_50 += V_55 ;
else
V_50 += strlen ( V_7 -> V_81 ) + 1 ;
V_118 = sscanf ( V_50 , L_9 , & V_116 ) ;
if ( V_118 != 1 || V_116 > V_123 )
goto V_33;
V_50 += V_124 ;
V_118 = sscanf ( V_50 , L_9 , & V_117 ) ;
if ( V_118 != 1 || V_117 > V_125 )
goto V_33;
if ( V_65 == V_67 &&
V_63 != ( V_119 + V_117 * V_124 ) )
goto V_33;
memset ( V_115 , 0 , sizeof( V_115 ) ) ;
for ( V_59 = 0 ; V_59 < V_117 ; V_59 ++ ) {
V_50 += V_124 ;
V_118 = sscanf ( V_50 , L_10 , & V_1 ) ;
if ( V_118 != 1 || V_1 > V_125 )
goto V_33;
F_1 ( V_1 , V_115 ) ;
}
V_25 = F_57 ( V_116 , V_115 , & V_114 , V_3 ) ;
if ( V_25 >= 0 ) {
F_58 ( V_7 -> V_107 . V_108 . V_109 . V_1 ) ;
V_7 -> V_107 . V_108 . V_109 . V_1 = V_114 . V_108 . V_109 . V_1 ;
V_7 -> V_107 . V_108 . V_109 . V_111 = V_114 . V_108 . V_109 . V_111 ;
V_25 = V_63 ;
}
V_33:
F_11 ( & V_122 ) ;
V_121:
F_19 ( V_54 ) ;
return V_25 ;
}
static T_1 F_59 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_56 ( V_61 , V_62 , V_63 , V_64 , V_67 ) ;
}
static int F_60 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_6 * V_7 =
F_38 ( V_34 , struct V_6 , V_34 ) ;
struct V_105 * V_106 = V_7 -> V_107 . V_108 . V_109 . V_1 ;
char V_110 = '/' ;
int V_59 ;
F_33 ( V_76 , L_7 , V_7 -> V_81 , V_7 -> V_107 . V_108 . V_109 . V_111 ) ;
for ( V_59 = F_54 ( V_106 , 0 ) ; V_59 >= 0 ;
V_59 = F_54 ( V_106 , V_59 + 1 ) ) {
F_33 ( V_76 , L_8 , V_110 , V_59 ) ;
V_110 = ',' ;
}
F_34 ( V_76 , '\n' ) ;
return 0 ;
}
static int F_61 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_126 ) ;
}
static T_1 F_62 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_56 ( V_61 , V_62 , V_63 , V_64 , V_127 ) ;
}
static void * F_63 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_25 ( V_76 , V_77 , & V_128 ) ;
}
static void * F_64 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
return F_29 ( V_76 , V_79 , V_77 , & V_128 ) ;
}
static int F_65 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_129 * V_7 =
F_38 ( V_34 , struct V_129 , V_34 ) ;
unsigned char * V_130 = ( char * ) & V_7 -> V_131 . V_132 . V_133 ;
int V_134 ;
T_5 V_135 = F_66 ( V_7 -> V_136 . V_133 ) ;
for ( V_134 = 0 ; V_135 ; V_135 <<= 1 , V_134 ++ ) ;
F_33 ( V_76 , L_11 ,
V_130 [ 0 ] , V_130 [ 1 ] , V_130 [ 2 ] , V_130 [ 3 ] , V_134 , V_7 -> V_137 -> V_81 ) ;
return 0 ;
}
static int F_67 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_138 ) ;
}
static void F_68 ( struct V_129 * V_139 )
{
struct V_129 * V_140 , * V_141 ;
if ( F_69 ( & V_128 ) ) {
F_10 ( & V_139 -> V_34 , & V_128 ) ;
return;
}
V_140 = F_38 ( V_128 . V_142 ,
struct V_129 , V_34 ) ;
if ( V_139 -> V_136 . V_133 > V_140 -> V_136 . V_133 ) {
F_10 ( & V_139 -> V_34 , & V_128 ) ;
return;
}
F_8 (m, &smk_netlbladdr_list, list) {
if ( F_70 ( & V_140 -> V_34 , & V_128 ) ) {
F_10 ( & V_139 -> V_34 , & V_140 -> V_34 ) ;
return;
}
V_141 = F_38 ( V_140 -> V_34 . V_142 ,
struct V_129 , V_34 ) ;
if ( V_139 -> V_136 . V_133 > V_141 -> V_136 . V_133 ) {
F_10 ( & V_139 -> V_34 , & V_140 -> V_34 ) ;
return;
}
}
}
static T_1 F_71 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_129 * V_143 ;
struct V_144 V_145 ;
char * V_146 ;
struct V_6 * V_7 ;
char * V_54 ;
char * V_147 = ( char * ) & V_145 . V_132 . V_133 ;
int V_25 ;
struct V_4 V_148 ;
struct V_149 V_150 ;
unsigned int V_140 ;
int V_24 ;
T_5 V_151 = ( 1 << 31 ) ;
T_6 V_152 ;
T_5 V_135 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( * V_64 != 0 )
return - V_60 ;
if ( V_63 < V_153 )
return - V_60 ;
V_54 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_154;
}
V_146 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_146 == NULL ) {
V_25 = - V_32 ;
goto V_154;
}
V_54 [ V_63 ] = '\0' ;
V_25 = sscanf ( V_54 , L_12 ,
& V_147 [ 0 ] , & V_147 [ 1 ] , & V_147 [ 2 ] , & V_147 [ 3 ] , & V_140 , V_146 ) ;
if ( V_25 != 6 ) {
V_25 = sscanf ( V_54 , L_13 ,
& V_147 [ 0 ] , & V_147 [ 1 ] , & V_147 [ 2 ] , & V_147 [ 3 ] , V_146 ) ;
if ( V_25 != 5 ) {
V_25 = - V_60 ;
goto V_155;
}
V_140 = V_156 ;
}
if ( V_140 > V_156 ) {
V_25 = - V_60 ;
goto V_155;
}
if ( V_146 [ 0 ] != '-' ) {
V_7 = F_14 ( V_146 , 0 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_155;
}
} else {
if ( strcmp ( V_146 , V_157 . V_81 ) == 0 )
V_7 = & V_157 ;
else {
V_25 = - V_60 ;
goto V_155;
}
}
for ( V_135 = 0 ; V_140 > 0 ; V_140 -- ) {
V_135 |= V_151 ;
V_151 >>= 1 ;
}
V_150 . V_133 = F_72 ( V_135 ) ;
V_145 . V_132 . V_133 &= V_150 . V_133 ;
F_7 ( & V_158 ) ;
V_152 = V_145 . V_132 . V_133 ;
V_24 = 0 ;
F_8 (snp, &smk_netlbladdr_list, list) {
if ( V_143 -> V_131 . V_132 . V_133 == V_152 &&
V_143 -> V_136 . V_133 == V_150 . V_133 ) {
V_24 = 1 ;
break;
}
}
F_2 ( & V_148 ) ;
if ( V_24 == 0 ) {
V_143 = F_9 ( sizeof( * V_143 ) , V_31 ) ;
if ( V_143 == NULL )
V_25 = - V_32 ;
else {
V_25 = 0 ;
V_143 -> V_131 . V_132 . V_133 = V_145 . V_132 . V_133 ;
V_143 -> V_136 . V_133 = V_150 . V_133 ;
V_143 -> V_137 = V_7 ;
F_68 ( V_143 ) ;
}
} else {
if ( V_143 -> V_137 != & V_157 )
V_25 = F_73 ( & V_159 , NULL ,
& V_143 -> V_131 . V_132 , & V_143 -> V_136 ,
V_89 , & V_148 ) ;
else
V_25 = 0 ;
V_143 -> V_137 = V_7 ;
}
if ( V_25 == 0 && V_7 != & V_157 )
V_25 = F_74 ( & V_159 , NULL ,
& V_143 -> V_131 . V_132 , & V_143 -> V_136 , V_89 ,
V_143 -> V_137 -> V_12 , & V_148 ) ;
if ( V_25 == 0 )
V_25 = V_63 ;
F_11 ( & V_158 ) ;
V_155:
F_19 ( V_146 ) ;
V_154:
F_19 ( V_54 ) ;
return V_25 ;
}
static T_1 F_75 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_161 , L_9 , V_95 ) ;
V_25 = F_76 ( V_62 , V_63 , V_64 , V_161 , strlen ( V_161 ) ) ;
return V_25 ;
}
static T_1 F_77 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 80 ] ;
int V_59 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( V_63 >= sizeof( V_161 ) || V_63 == 0 )
return - V_60 ;
if ( F_24 ( V_161 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_161 [ V_63 ] = '\0' ;
if ( sscanf ( V_161 , L_9 , & V_59 ) != 1 )
return - V_60 ;
V_95 = V_59 ;
F_43 () ;
return V_63 ;
}
static T_1 F_78 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_161 , L_9 , V_162 ) ;
V_25 = F_76 ( V_62 , V_63 , V_64 , V_161 , strlen ( V_161 ) ) ;
return V_25 ;
}
static T_1 F_79 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char V_161 [ 80 ] ;
int V_59 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( V_63 >= sizeof( V_161 ) || V_63 == 0 )
return - V_60 ;
if ( F_24 ( V_161 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_161 [ V_63 ] = '\0' ;
if ( sscanf ( V_161 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_162 != V_59 ) {
F_7 ( & V_163 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_107 . V_108 . V_109 . V_111 ==
V_162 )
V_7 -> V_107 . V_108 . V_109 . V_111 = V_59 ;
V_162 = V_59 ;
F_11 ( & V_163 ) ;
}
return V_63 ;
}
static T_1 F_80 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_161 , L_9 , V_164 ) ;
V_25 = F_76 ( V_62 , V_63 , V_64 , V_161 , strlen ( V_161 ) ) ;
return V_25 ;
}
static T_1 F_81 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char V_161 [ 80 ] ;
int V_59 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( V_63 >= sizeof( V_161 ) || V_63 == 0 )
return - V_60 ;
if ( F_24 ( V_161 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_161 [ V_63 ] = '\0' ;
if ( sscanf ( V_161 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_164 != V_59 ) {
F_7 ( & V_163 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_107 . V_108 . V_109 . V_111 ==
V_164 )
V_7 -> V_107 . V_108 . V_109 . V_111 = V_59 ;
V_164 = V_59 ;
F_11 ( & V_163 ) ;
}
return V_63 ;
}
static T_1 F_82 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_165 , T_4 * V_64 )
{
T_1 V_25 ;
int V_166 ;
if ( * V_64 != 0 )
return 0 ;
F_7 ( & V_167 ) ;
V_166 = strlen ( V_102 -> V_81 ) + 1 ;
if ( V_165 >= V_166 )
V_25 = F_76 ( V_62 , V_165 , V_64 ,
V_102 -> V_81 ,
V_166 ) ;
else
V_25 = - V_60 ;
F_11 ( & V_167 ) ;
return V_25 ;
}
static T_1 F_83 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char * V_101 ;
char * V_54 ;
int V_25 = V_63 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
V_54 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_33;
}
V_7 = F_14 ( V_54 , V_63 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_33;
}
F_7 ( & V_167 ) ;
V_101 = V_102 -> V_81 ;
V_102 = V_7 ;
F_49 ( V_101 ) ;
F_11 ( & V_167 ) ;
V_33:
F_19 ( V_54 ) ;
return V_25 ;
}
static void * F_84 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_25 ( V_76 , V_77 , & V_168 ) ;
}
static void * F_85 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
return F_29 ( V_76 , V_79 , V_77 , & V_168 ) ;
}
static int F_86 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_169 * V_170 =
F_38 ( V_34 , struct V_169 , V_34 ) ;
F_87 ( V_76 , V_170 -> V_137 -> V_81 ) ;
F_34 ( V_76 , ' ' ) ;
return 0 ;
}
static int F_88 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_171 ) ;
}
static void F_89 ( struct V_15 * V_172 ,
struct V_15 * V_173 )
{
struct V_15 * V_174 , * V_175 ;
if ( F_69 ( V_172 ) ) {
F_90 ( V_173 , V_172 , V_176 ) ;
} else {
V_174 = V_172 -> V_142 ;
V_175 = V_172 -> V_177 ;
V_173 -> V_177 -> V_142 = V_172 ;
V_173 -> V_142 -> V_177 = V_172 ;
F_91 ( V_172 -> V_142 , V_173 -> V_142 ) ;
V_172 -> V_177 = V_173 -> V_177 ;
V_176 () ;
V_173 -> V_142 = V_174 ;
V_173 -> V_177 = V_175 ;
V_174 -> V_177 = V_173 ;
V_175 -> V_142 = V_173 ;
}
}
static T_1 F_92 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_54 ;
char * V_178 ;
char * V_58 ;
struct V_6 * V_7 ;
struct V_169 * V_170 ;
struct V_169 * V_179 ;
F_93 ( V_180 ) ;
int V_25 = V_63 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
V_54 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
F_19 ( V_54 ) ;
return - V_71 ;
}
V_178 = V_54 ;
while ( ( V_58 = F_94 ( & V_178 , L_14 ) ) != NULL ) {
if ( ! * V_58 )
continue;
V_7 = F_14 ( V_58 , 0 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
break;
}
V_170 = F_9 ( sizeof( * V_170 ) , V_31 ) ;
if ( V_170 == NULL ) {
V_25 = - V_32 ;
break;
}
V_170 -> V_137 = V_7 ;
F_10 ( & V_170 -> V_34 , & V_180 ) ;
}
F_19 ( V_54 ) ;
if ( V_25 == - V_60 && F_69 ( & V_180 ) )
V_25 = V_63 ;
if ( V_25 >= 0 ) {
F_7 ( & V_181 ) ;
F_89 ( & V_168 , & V_180 ) ;
F_11 ( & V_181 ) ;
}
F_95 (sop, sop2, &list_tmp, list)
F_19 ( V_170 ) ;
return V_25 ;
}
static T_1 F_96 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_165 , T_4 * V_64 )
{
char * V_146 = L_15 ;
T_1 V_25 = - V_60 ;
int V_166 ;
if ( * V_64 != 0 )
return 0 ;
if ( V_182 != NULL )
V_146 = V_182 -> V_81 ;
V_166 = strlen ( V_146 ) + 1 ;
if ( V_165 >= V_166 )
V_25 = F_76 ( V_62 , V_165 , V_64 , V_146 , V_166 ) ;
return V_25 ;
}
static T_1 F_97 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_54 ;
struct V_6 * V_7 ;
int V_25 = V_63 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
V_54 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_183;
}
V_7 = F_14 ( V_54 , V_63 ) ;
if ( F_16 ( V_7 ) == - V_60 )
V_7 = NULL ;
else if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_183;
}
V_182 = V_7 ;
V_183:
F_19 ( V_54 ) ;
return V_25 ;
}
static T_1 F_98 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 32 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_161 , L_16 , V_184 ) ;
V_25 = F_76 ( V_62 , V_63 , V_64 , V_161 , strlen ( V_161 ) ) ;
return V_25 ;
}
static T_1 F_99 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 32 ] ;
int V_59 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( V_63 >= sizeof( V_161 ) || V_63 == 0 )
return - V_60 ;
if ( F_24 ( V_161 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_161 [ V_63 ] = '\0' ;
if ( sscanf ( V_161 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_59 < 0 || V_59 > 3 )
return - V_60 ;
V_184 = V_59 ;
return V_63 ;
}
static void * F_100 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_185 * V_186 = F_101 () ;
return F_25 ( V_76 , V_77 , & V_186 -> V_73 ) ;
}
static void * F_102 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
struct V_185 * V_186 = F_101 () ;
return F_29 ( V_76 , V_79 , V_77 , & V_186 -> V_73 ) ;
}
static int F_103 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_20 * V_14 =
F_38 ( V_34 , struct V_20 , V_34 ) ;
F_32 ( V_76 , V_14 , V_55 ) ;
return 0 ;
}
static int F_104 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_187 ) ;
}
static T_1 F_105 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_185 * V_186 = F_101 () ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , & V_186 -> V_73 ,
& V_186 -> V_74 , V_67 ) ;
}
static T_1 F_106 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 , int V_65 )
{
struct V_13 V_50 ;
char * V_54 ;
int V_188 ;
V_54 = F_107 ( V_61 , V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
if ( V_65 == V_67 ) {
if ( V_63 < V_69 )
return - V_60 ;
V_188 = F_20 ( V_54 , & V_50 , 0 ) ;
} else {
V_188 = F_21 ( V_54 , & V_50 , 0 , 3 ) ;
}
if ( V_188 >= 0 )
V_188 = V_28 ( V_50 . V_27 , V_50 . V_26 ,
V_50 . V_29 , NULL ) ;
else if ( V_188 != - V_53 )
return V_188 ;
V_54 [ 0 ] = V_188 >= 0 ? '1' : '0' ;
V_54 [ 1 ] = '\0' ;
F_108 ( V_61 , 2 ) ;
if ( V_65 == V_67 )
return V_69 ;
return V_63 ;
}
static T_1 F_109 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_106 ( V_61 , V_62 , V_63 , V_64 , V_67 ) ;
}
static int F_110 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_22 * V_23 =
F_38 ( V_34 , struct V_22 , V_34 ) ;
F_32 ( V_76 , V_23 -> V_35 , V_189 ) ;
return 0 ;
}
static int F_111 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_190 ) ;
}
static T_1 F_112 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_42 ( V_84 ) )
return - V_85 ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_127 ) ;
}
static void * F_113 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_185 * V_186 = F_101 () ;
return F_25 ( V_76 , V_77 , & V_186 -> V_73 ) ;
}
static void * F_114 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
struct V_185 * V_186 = F_101 () ;
return F_29 ( V_76 , V_79 , V_77 , & V_186 -> V_73 ) ;
}
static int F_115 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_20 * V_14 =
F_38 ( V_34 , struct V_20 , V_34 ) ;
F_32 ( V_76 , V_14 , V_189 ) ;
return 0 ;
}
static int F_116 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_191 ) ;
}
static T_1 F_117 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_185 * V_186 = F_101 () ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , & V_186 -> V_73 ,
& V_186 -> V_74 , V_127 ) ;
}
static T_1 F_118 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_106 ( V_61 , V_62 , V_63 , V_64 , V_127 ) ;
}
static T_1 F_119 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_54 ;
const char * V_38 ;
struct V_6 * V_7 ;
struct V_20 * V_21 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_25 = V_63 ;
if ( * V_64 != 0 )
return - V_60 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( V_63 == 0 || V_63 > V_189 )
return - V_60 ;
V_54 = F_9 ( V_63 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_192;
}
V_38 = F_17 ( V_54 , V_63 ) ;
if ( F_15 ( V_38 ) ) {
V_25 = F_16 ( V_38 ) ;
goto V_192;
}
V_7 = F_18 ( V_38 ) ;
if ( V_7 == NULL )
goto V_193;
V_16 = & V_7 -> V_73 ;
V_18 = & V_7 -> V_74 ;
F_7 ( V_18 ) ;
F_8 (sp, rule_list, list)
V_21 -> V_28 = 0 ;
F_11 ( V_18 ) ;
V_193:
F_19 ( V_38 ) ;
V_192:
F_19 ( V_54 ) ;
return V_25 ;
}
static int F_120 ( void )
{
int V_194 ;
V_194 = F_121 ( V_195 , L_17 ) ;
if ( V_194 )
return V_194 ;
return 0 ;
}
static T_1 F_122 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_42 ( V_84 ) )
return - V_85 ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_72 ) ;
}
static T_1 F_123 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_165 , T_4 * V_64 )
{
struct V_6 * V_7 ;
T_1 V_25 = - V_60 ;
int V_166 ;
if ( * V_64 != 0 )
return 0 ;
if ( V_196 == NULL )
V_7 = & V_197 ;
else
V_7 = V_196 ;
V_166 = strlen ( V_7 -> V_81 ) + 1 ;
if ( V_165 >= V_166 )
V_25 = F_76 ( V_62 , V_165 , V_64 , V_7 -> V_81 ,
V_166 ) ;
return V_25 ;
}
static T_1 F_124 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_54 ;
struct V_6 * V_7 ;
int V_25 = V_63 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
V_54 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 )
V_25 = - V_71 ;
else {
V_7 = F_14 ( V_54 , V_63 ) ;
if ( F_15 ( V_7 ) )
V_25 = F_16 ( V_7 ) ;
else
V_196 = V_7 ;
}
F_19 ( V_54 ) ;
return V_25 ;
}
static T_1 F_125 ( struct V_61 * V_160 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 32 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_161 , L_16 , V_198 ) ;
V_25 = F_76 ( V_62 , V_63 , V_64 , V_161 , strlen ( V_161 ) ) ;
return V_25 ;
}
static T_1 F_126 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_161 [ 32 ] ;
int V_59 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( * V_64 != 0 || V_63 >= sizeof( V_161 ) || V_63 == 0 )
return - V_60 ;
if ( F_24 ( V_161 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_161 [ V_63 ] = '\0' ;
if ( sscanf ( V_161 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_59 < V_199 || V_59 > V_200 )
return - V_60 ;
V_198 = V_59 ;
return V_63 ;
}
static int F_127 ( struct V_201 * V_202 , void * V_54 , int V_203 )
{
int V_25 ;
struct V_82 * V_204 ;
static struct V_205 V_206 [] = {
[ V_207 ] = {
L_18 , & V_208 , V_209 | V_210 } ,
[ V_211 ] = {
L_19 , & V_212 , V_209 | V_210 } ,
[ V_213 ] = {
L_20 , & V_214 , V_209 | V_210 } ,
[ V_215 ] = {
L_21 , & V_216 , V_209 | V_210 } ,
[ V_217 ] = {
L_22 , & V_218 , V_209 | V_210 } ,
[ V_219 ] = {
L_23 , & V_220 , V_209 | V_210 } ,
[ V_221 ] = {
L_24 , & V_222 , V_209 | V_210 } ,
[ V_223 ] = {
L_25 , & V_224 , V_209 | V_210 } ,
[ V_225 ] = {
L_26 , & V_226 , V_209 | V_227 } ,
[ V_228 ] = {
L_27 , & V_229 , V_209 | V_227 } ,
[ V_230 ] = {
L_28 , & V_231 , V_209 | V_210 } ,
[ V_232 ] = {
L_29 , & V_233 , V_209 | V_210 } ,
[ V_234 ] = {
L_30 , & V_235 , V_209 | V_227 } ,
[ V_236 ] = {
L_31 , & V_237 , V_209 | V_227 } ,
[ V_238 ] = {
L_32 , & V_239 , V_209 | V_210 } ,
[ V_240 ] = {
L_33 , & V_241 ,
V_209 | V_210 } ,
[ V_242 ] = {
L_34 , & V_243 , V_209 | V_210 } ,
[ V_244 ] = {
L_35 , & V_245 , V_209 | V_210 } ,
[ V_246 ] = {
L_36 , & V_247 , V_209 | V_210 } ,
#ifdef F_128
[ V_248 ] = {
L_37 , & V_249 , V_209 | V_210 } ,
#endif
{ L_15 }
} ;
V_25 = F_129 ( V_202 , V_250 , V_206 ) ;
if ( V_25 != 0 ) {
F_45 ( V_251 L_38 ,
V_91 , V_25 ) ;
return V_25 ;
}
V_204 = F_130 ( V_202 -> V_252 ) ;
return 0 ;
}
static struct V_253 * F_131 ( struct V_254 * V_255 ,
int V_256 , const char * V_257 , void * V_54 )
{
return F_132 ( V_255 , V_256 , V_54 , F_127 ) ;
}
static int T_7 F_133 ( struct V_6 * V_7 )
{
V_7 -> V_107 . V_258 = V_7 -> V_81 ;
V_7 -> V_107 . V_256 =
V_259 | V_260 ;
return F_57 ( V_162 , V_7 -> V_81 ,
& V_7 -> V_107 , strlen ( V_7 -> V_81 ) ) ;
}
static int T_7 F_134 ( void )
{
int V_194 ;
int V_25 ;
if ( ! F_135 ( L_39 ) )
return 0 ;
V_194 = F_120 () ;
if ( V_194 )
F_45 ( V_251 L_40 ) ;
V_194 = F_136 ( & V_261 ) ;
if ( ! V_194 ) {
V_262 = F_137 ( & V_261 ) ;
if ( F_15 ( V_262 ) ) {
F_45 ( V_251 L_41 ) ;
V_194 = F_16 ( V_262 ) ;
V_262 = NULL ;
}
}
F_43 () ;
F_49 ( NULL ) ;
V_25 = F_133 ( & V_103 ) ;
if ( V_194 == 0 && V_25 < 0 )
V_194 = V_25 ;
V_25 = F_133 ( & V_263 ) ;
if ( V_194 == 0 && V_25 < 0 )
V_194 = V_25 ;
V_25 = F_133 ( & V_264 ) ;
if ( V_194 == 0 && V_25 < 0 )
V_194 = V_25 ;
V_25 = F_133 ( & V_265 ) ;
if ( V_194 == 0 && V_25 < 0 )
V_194 = V_25 ;
V_25 = F_133 ( & V_197 ) ;
if ( V_194 == 0 && V_25 < 0 )
V_194 = V_25 ;
V_25 = F_133 ( & V_266 ) ;
if ( V_194 == 0 && V_25 < 0 )
V_194 = V_25 ;
return V_194 ;
}
