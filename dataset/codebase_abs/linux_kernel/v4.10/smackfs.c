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
V_54 = F_23 ( V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
if ( V_66 ) {
while ( V_63 > 0 && ( V_54 [ V_63 - 1 ] != '\n' ) )
-- V_63 ;
if ( V_63 == 0 ) {
V_25 = - V_60 ;
goto V_33;
}
}
V_54 [ V_63 ] = '\0' ;
V_56 = ( V_65 == V_71 ? 4 : 3 ) ;
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
V_25 = F_6 ( & V_50 , & V_50 . V_27 -> V_72 ,
& V_50 . V_27 -> V_73 , 1 ) ;
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
static void * F_24 ( struct V_74 * V_75 , T_4 * V_76 ,
struct V_15 * V_77 )
{
struct V_15 * V_34 ;
int V_59 = * V_76 ;
F_25 () ;
for ( V_34 = F_26 ( F_27 ( V_77 ) ) ;
V_34 != V_77 ;
V_34 = F_26 ( F_27 ( V_34 ) ) ) {
if ( V_59 -- == 0 )
return V_34 ;
}
return NULL ;
}
static void * F_28 ( struct V_74 * V_75 , void * V_78 , T_4 * V_76 ,
struct V_15 * V_77 )
{
struct V_15 * V_34 = V_78 ;
++ * V_76 ;
V_34 = F_26 ( F_27 ( V_34 ) ) ;
return ( V_34 == V_77 ) ? NULL : V_34 ;
}
static void F_29 ( struct V_74 * V_75 , void * V_78 )
{
F_30 () ;
}
static void F_31 ( struct V_74 * V_75 , struct V_20 * V_14 , int V_79 )
{
if ( strlen ( V_14 -> V_27 -> V_80 ) >= V_79 ||
strlen ( V_14 -> V_26 -> V_80 ) >= V_79 )
return;
if ( V_14 -> V_28 == 0 )
return;
F_32 ( V_75 , L_1 ,
V_14 -> V_27 -> V_80 ,
V_14 -> V_26 -> V_80 ) ;
F_33 ( V_75 , ' ' ) ;
if ( V_14 -> V_28 & V_39 )
F_33 ( V_75 , 'r' ) ;
if ( V_14 -> V_28 & V_40 )
F_33 ( V_75 , 'w' ) ;
if ( V_14 -> V_28 & V_41 )
F_33 ( V_75 , 'x' ) ;
if ( V_14 -> V_28 & V_42 )
F_33 ( V_75 , 'a' ) ;
if ( V_14 -> V_28 & V_43 )
F_33 ( V_75 , 't' ) ;
if ( V_14 -> V_28 & V_44 )
F_33 ( V_75 , 'l' ) ;
if ( V_14 -> V_28 & V_45 )
F_33 ( V_75 , 'b' ) ;
F_33 ( V_75 , '\n' ) ;
}
static void * F_34 ( struct V_74 * V_75 , T_4 * V_76 )
{
return F_24 ( V_75 , V_76 , & V_36 ) ;
}
static void * F_35 ( struct V_74 * V_75 , void * V_78 , T_4 * V_76 )
{
return F_28 ( V_75 , V_78 , V_76 , & V_36 ) ;
}
static int F_36 ( struct V_74 * V_75 , void * V_78 )
{
struct V_15 * V_34 = V_78 ;
struct V_22 * V_23 =
F_37 ( V_34 , struct V_22 , V_34 ) ;
F_31 ( V_75 , V_23 -> V_35 , V_55 ) ;
return 0 ;
}
static int F_38 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
return F_39 ( V_61 , & V_82 ) ;
}
static T_1 F_40 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_41 ( V_83 ) )
return - V_84 ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_67 ) ;
}
static void F_42 ( void )
{
int V_25 ;
struct V_85 * V_86 ;
struct V_4 V_87 ;
F_2 ( & V_87 ) ;
V_25 = F_43 ( NULL , V_88 , NULL , NULL , & V_87 ) ;
if ( V_25 != 0 )
F_44 ( V_89 L_2 ,
V_90 , __LINE__ , V_25 ) ;
V_86 = F_45 ( sizeof( struct V_85 ) , V_31 ) ;
if ( V_86 == NULL )
F_46 ( L_3 ) ;
V_86 -> V_91 . V_92 = NULL ;
V_86 -> V_93 = V_94 ;
V_86 -> type = V_95 ;
V_86 -> V_96 [ 0 ] = V_97 ;
for ( V_25 = 1 ; V_25 < V_98 ; V_25 ++ )
V_86 -> V_96 [ V_25 ] = V_99 ;
V_25 = F_47 ( V_86 , & V_87 ) ;
if ( V_25 != 0 ) {
F_44 ( V_89 L_4 ,
V_90 , __LINE__ , V_25 ) ;
F_19 ( V_86 ) ;
return;
}
V_25 = F_48 ( V_86 -> V_93 , NULL , NULL , NULL , & V_87 ) ;
if ( V_25 != 0 ) {
F_44 ( V_89 L_5 ,
V_90 , __LINE__ , V_25 ) ;
F_19 ( V_86 ) ;
return;
}
}
static void F_49 ( char * V_100 )
{
int V_25 ;
struct V_4 V_87 ;
F_2 ( & V_87 ) ;
if ( V_100 != NULL ) {
V_25 = F_43 ( V_100 , V_88 , NULL , NULL , & V_87 ) ;
if ( V_25 != 0 )
F_44 ( V_89 L_2 ,
V_90 , __LINE__ , V_25 ) ;
}
if ( V_101 == NULL )
V_101 = & V_102 ;
V_25 = F_50 ( V_101 -> V_80 , V_88 ,
NULL , NULL , & V_87 ) ;
if ( V_25 != 0 )
F_44 ( V_89 L_6 ,
V_90 , __LINE__ , V_25 ) ;
}
static void * F_51 ( struct V_74 * V_75 , T_4 * V_76 )
{
return F_24 ( V_75 , V_76 , & V_103 ) ;
}
static void * F_52 ( struct V_74 * V_75 , void * V_78 , T_4 * V_76 )
{
return F_28 ( V_75 , V_78 , V_76 , & V_103 ) ;
}
static int F_53 ( struct V_74 * V_75 , void * V_78 )
{
struct V_15 * V_34 = V_78 ;
struct V_6 * V_7 =
F_37 ( V_34 , struct V_6 , V_34 ) ;
struct V_104 * V_105 = V_7 -> V_106 . V_107 . V_108 . V_1 ;
char V_109 = '/' ;
int V_59 ;
if ( strlen ( V_7 -> V_80 ) >= V_55 )
return 0 ;
F_32 ( V_75 , L_7 , V_7 -> V_80 , V_7 -> V_106 . V_107 . V_108 . V_110 ) ;
for ( V_59 = F_54 ( V_105 , 0 ) ; V_59 >= 0 ;
V_59 = F_54 ( V_105 , V_59 + 1 ) ) {
F_32 ( V_75 , L_8 , V_109 , V_59 ) ;
V_109 = ',' ;
}
F_33 ( V_75 , '\n' ) ;
return 0 ;
}
static int F_55 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
return F_39 ( V_61 , & V_111 ) ;
}
static T_1 F_56 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 , int V_65 )
{
struct V_6 * V_7 ;
struct V_112 V_113 ;
char V_114 [ V_3 ] ;
int V_115 ;
unsigned int V_1 ;
int V_116 ;
T_1 V_25 = - V_60 ;
char * V_54 = NULL ;
char * V_50 ;
int V_117 ;
int V_59 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
if ( * V_64 != 0 )
return - V_60 ;
if ( V_65 == V_67 &&
( V_63 < V_118 || V_63 > V_119 ) )
return - V_60 ;
V_54 = F_23 ( V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
V_50 = V_54 ;
F_7 ( & V_120 ) ;
V_7 = F_14 ( V_50 , 0 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_33;
}
if ( V_65 == V_67 )
V_50 += V_55 ;
else
V_50 += strlen ( V_7 -> V_80 ) + 1 ;
V_117 = sscanf ( V_50 , L_9 , & V_115 ) ;
if ( V_117 != 1 || V_115 > V_121 )
goto V_33;
V_50 += V_122 ;
V_117 = sscanf ( V_50 , L_9 , & V_116 ) ;
if ( V_117 != 1 || V_116 > V_123 )
goto V_33;
if ( V_65 == V_67 &&
V_63 != ( V_118 + V_116 * V_122 ) )
goto V_33;
memset ( V_114 , 0 , sizeof( V_114 ) ) ;
for ( V_59 = 0 ; V_59 < V_116 ; V_59 ++ ) {
V_50 += V_122 ;
V_117 = sscanf ( V_50 , L_10 , & V_1 ) ;
if ( V_117 != 1 || V_1 > V_123 )
goto V_33;
F_1 ( V_1 , V_114 ) ;
}
V_25 = F_57 ( V_115 , V_114 , & V_113 , V_3 ) ;
if ( V_25 >= 0 ) {
F_58 ( V_7 -> V_106 . V_107 . V_108 . V_1 ) ;
V_7 -> V_106 . V_107 . V_108 . V_1 = V_113 . V_107 . V_108 . V_1 ;
V_7 -> V_106 . V_107 . V_108 . V_110 = V_113 . V_107 . V_108 . V_110 ;
V_25 = V_63 ;
}
V_33:
F_11 ( & V_120 ) ;
F_19 ( V_54 ) ;
return V_25 ;
}
static T_1 F_59 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_56 ( V_61 , V_62 , V_63 , V_64 , V_67 ) ;
}
static int F_60 ( struct V_74 * V_75 , void * V_78 )
{
struct V_15 * V_34 = V_78 ;
struct V_6 * V_7 =
F_37 ( V_34 , struct V_6 , V_34 ) ;
struct V_104 * V_105 = V_7 -> V_106 . V_107 . V_108 . V_1 ;
char V_109 = '/' ;
int V_59 ;
F_32 ( V_75 , L_7 , V_7 -> V_80 , V_7 -> V_106 . V_107 . V_108 . V_110 ) ;
for ( V_59 = F_54 ( V_105 , 0 ) ; V_59 >= 0 ;
V_59 = F_54 ( V_105 , V_59 + 1 ) ) {
F_32 ( V_75 , L_8 , V_109 , V_59 ) ;
V_109 = ',' ;
}
F_33 ( V_75 , '\n' ) ;
return 0 ;
}
static int F_61 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
return F_39 ( V_61 , & V_124 ) ;
}
static T_1 F_62 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_56 ( V_61 , V_62 , V_63 , V_64 , V_125 ) ;
}
static void * F_63 ( struct V_74 * V_75 , T_4 * V_76 )
{
return F_24 ( V_75 , V_76 , & V_126 ) ;
}
static void * F_64 ( struct V_74 * V_75 , void * V_78 , T_4 * V_76 )
{
return F_28 ( V_75 , V_78 , V_76 , & V_126 ) ;
}
static int F_65 ( struct V_74 * V_75 , void * V_78 )
{
struct V_15 * V_34 = V_78 ;
struct V_127 * V_7 =
F_37 ( V_34 , struct V_127 , V_34 ) ;
char * V_128 = V_129 ;
if ( V_7 -> V_130 != NULL )
V_128 = V_7 -> V_130 -> V_80 ;
F_32 ( V_75 , L_11 , & V_7 -> V_131 . V_132 ,
V_7 -> V_133 , V_128 ) ;
return 0 ;
}
static int F_66 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
return F_39 ( V_61 , & V_134 ) ;
}
static void F_67 ( struct V_127 * V_135 )
{
struct V_127 * V_136 ;
struct V_127 * V_137 ;
if ( F_68 ( & V_126 ) ) {
F_10 ( & V_135 -> V_34 , & V_126 ) ;
return;
}
V_136 = F_37 ( V_126 . V_138 ,
struct V_127 , V_34 ) ;
if ( V_135 -> V_133 > V_136 -> V_133 ) {
F_10 ( & V_135 -> V_34 , & V_126 ) ;
return;
}
F_8 (m, &smk_net4addr_list, list) {
if ( F_69 ( & V_136 -> V_34 , & V_126 ) ) {
F_10 ( & V_135 -> V_34 , & V_136 -> V_34 ) ;
return;
}
V_137 = F_37 ( V_136 -> V_34 . V_138 ,
struct V_127 , V_34 ) ;
if ( V_135 -> V_133 > V_137 -> V_133 ) {
F_10 ( & V_135 -> V_34 , & V_136 -> V_34 ) ;
return;
}
}
}
static T_1 F_70 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_127 * V_139 ;
struct V_140 V_141 ;
char * V_142 ;
struct V_6 * V_7 = NULL ;
char * V_54 ;
char * V_143 = ( char * ) & V_141 . V_144 . V_132 ;
int V_25 ;
struct V_4 V_145 ;
struct V_146 V_147 ;
unsigned int V_136 ;
unsigned int V_148 ;
int V_24 ;
T_5 V_149 = ( 1 << 31 ) ;
T_6 V_150 ;
T_5 V_151 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
if ( * V_64 != 0 )
return - V_60 ;
if ( V_63 < V_152 )
return - V_60 ;
V_54 = F_23 ( V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
V_142 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_142 == NULL ) {
V_25 = - V_32 ;
goto V_153;
}
V_25 = sscanf ( V_54 , L_12 ,
& V_143 [ 0 ] , & V_143 [ 1 ] , & V_143 [ 2 ] , & V_143 [ 3 ] , & V_148 , V_142 ) ;
if ( V_25 != 6 ) {
V_25 = sscanf ( V_54 , L_13 ,
& V_143 [ 0 ] , & V_143 [ 1 ] , & V_143 [ 2 ] , & V_143 [ 3 ] , V_142 ) ;
if ( V_25 != 5 ) {
V_25 = - V_60 ;
goto V_154;
}
V_136 = V_155 ;
V_148 = 32 ;
}
if ( V_148 > V_155 ) {
V_25 = - V_60 ;
goto V_154;
}
if ( V_142 [ 0 ] != '-' ) {
V_7 = F_14 ( V_142 , 0 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_154;
}
} else {
if ( strcmp ( V_142 , V_129 ) != 0 ) {
V_25 = - V_60 ;
goto V_154;
}
}
for ( V_136 = V_148 , V_151 = 0 ; V_136 > 0 ; V_136 -- ) {
V_151 |= V_149 ;
V_149 >>= 1 ;
}
V_147 . V_132 = F_71 ( V_151 ) ;
V_141 . V_144 . V_132 &= V_147 . V_132 ;
F_7 ( & V_156 ) ;
V_150 = V_141 . V_144 . V_132 ;
V_24 = 0 ;
F_8 (snp, &smk_net4addr_list, list) {
if ( V_139 -> V_131 . V_132 == V_150 && V_139 -> V_133 == V_148 ) {
V_24 = 1 ;
break;
}
}
F_2 ( & V_145 ) ;
if ( V_24 == 0 ) {
V_139 = F_9 ( sizeof( * V_139 ) , V_31 ) ;
if ( V_139 == NULL )
V_25 = - V_32 ;
else {
V_25 = 0 ;
V_139 -> V_131 . V_132 = V_141 . V_144 . V_132 ;
V_139 -> V_157 . V_132 = V_147 . V_132 ;
V_139 -> V_130 = V_7 ;
V_139 -> V_133 = V_148 ;
F_67 ( V_139 ) ;
}
} else {
if ( V_139 -> V_130 != NULL )
V_25 = F_72 ( & V_158 , NULL ,
& V_139 -> V_131 , & V_139 -> V_157 ,
V_88 , & V_145 ) ;
else
V_25 = 0 ;
V_139 -> V_130 = V_7 ;
}
if ( V_25 == 0 && V_7 != NULL )
V_25 = F_73 ( & V_158 , NULL ,
& V_139 -> V_131 , & V_139 -> V_157 , V_88 ,
V_139 -> V_130 -> V_12 , & V_145 ) ;
if ( V_25 == 0 )
V_25 = V_63 ;
F_11 ( & V_156 ) ;
V_154:
F_19 ( V_142 ) ;
V_153:
F_19 ( V_54 ) ;
return V_25 ;
}
static void * F_74 ( struct V_74 * V_75 , T_4 * V_76 )
{
return F_24 ( V_75 , V_76 , & V_159 ) ;
}
static void * F_75 ( struct V_74 * V_75 , void * V_78 , T_4 * V_76 )
{
return F_28 ( V_75 , V_78 , V_76 , & V_159 ) ;
}
static int F_76 ( struct V_74 * V_75 , void * V_78 )
{
struct V_15 * V_34 = V_78 ;
struct V_160 * V_7 =
F_77 ( V_34 , struct V_160 , V_34 ) ;
if ( V_7 -> V_130 != NULL )
F_32 ( V_75 , L_14 , & V_7 -> V_131 , V_7 -> V_133 ,
V_7 -> V_130 -> V_80 ) ;
return 0 ;
}
static int F_78 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
return F_39 ( V_61 , & V_161 ) ;
}
static void F_79 ( struct V_160 * V_135 )
{
struct V_160 * V_137 ;
struct V_160 * V_136 ;
if ( F_68 ( & V_159 ) ) {
F_10 ( & V_135 -> V_34 , & V_159 ) ;
return;
}
V_136 = F_37 ( V_159 . V_138 ,
struct V_160 , V_34 ) ;
if ( V_135 -> V_133 > V_136 -> V_133 ) {
F_10 ( & V_135 -> V_34 , & V_159 ) ;
return;
}
F_8 (m, &smk_net6addr_list, list) {
if ( F_69 ( & V_136 -> V_34 , & V_159 ) ) {
F_10 ( & V_135 -> V_34 , & V_136 -> V_34 ) ;
return;
}
V_137 = F_37 ( V_136 -> V_34 . V_138 ,
struct V_160 , V_34 ) ;
if ( V_135 -> V_133 > V_137 -> V_133 ) {
F_10 ( & V_135 -> V_34 , & V_136 -> V_34 ) ;
return;
}
}
}
static T_1 F_80 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_160 * V_139 ;
struct V_162 V_141 ;
struct V_162 V_163 ;
struct V_6 * V_7 = NULL ;
char * V_142 ;
char * V_54 ;
int V_25 = 0 ;
int V_24 = 0 ;
int V_59 ;
unsigned int V_164 [ 8 ] ;
unsigned int V_136 ;
unsigned int V_147 = 128 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
if ( * V_64 != 0 )
return - V_60 ;
if ( V_63 < V_152 )
return - V_60 ;
V_54 = F_23 ( V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
V_142 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_142 == NULL ) {
V_25 = - V_32 ;
goto V_153;
}
V_59 = sscanf ( V_54 , L_15 ,
& V_164 [ 0 ] , & V_164 [ 1 ] , & V_164 [ 2 ] , & V_164 [ 3 ] ,
& V_164 [ 4 ] , & V_164 [ 5 ] , & V_164 [ 6 ] , & V_164 [ 7 ] ,
& V_147 , V_142 ) ;
if ( V_59 != 10 ) {
V_59 = sscanf ( V_54 , L_16 ,
& V_164 [ 0 ] , & V_164 [ 1 ] , & V_164 [ 2 ] ,
& V_164 [ 3 ] , & V_164 [ 4 ] , & V_164 [ 5 ] ,
& V_164 [ 6 ] , & V_164 [ 7 ] , V_142 ) ;
if ( V_59 != 9 ) {
V_25 = - V_60 ;
goto V_154;
}
}
if ( V_147 > 128 ) {
V_25 = - V_60 ;
goto V_154;
}
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
if ( V_164 [ V_59 ] > 0xffff ) {
V_25 = - V_60 ;
goto V_154;
}
V_141 . V_165 [ V_59 ] = F_81 ( V_164 [ V_59 ] ) ;
}
if ( V_142 [ 0 ] != '-' ) {
V_7 = F_14 ( V_142 , 0 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_154;
}
} else {
if ( strcmp ( V_142 , V_166 ) != 0 ) {
V_25 = - V_60 ;
goto V_154;
}
}
for ( V_59 = 0 , V_136 = V_147 ; V_59 < 8 ; V_59 ++ ) {
if ( V_136 >= 16 ) {
V_163 . V_165 [ V_59 ] = 0xffff ;
V_136 -= 16 ;
} else if ( V_136 > 0 ) {
V_163 . V_165 [ V_59 ] = ( 1 << V_136 ) - 1 ;
V_136 = 0 ;
} else
V_163 . V_165 [ V_59 ] = 0 ;
V_141 . V_165 [ V_59 ] &= V_163 . V_165 [ V_59 ] ;
}
F_7 ( & V_167 ) ;
F_8 (snp, &smk_net6addr_list, list) {
if ( V_147 != V_139 -> V_133 )
continue;
for ( V_24 = 1 , V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
if ( V_141 . V_165 [ V_59 ] !=
V_139 -> V_131 . V_165 [ V_59 ] ) {
V_24 = 0 ;
break;
}
}
if ( V_24 == 1 )
break;
}
if ( V_24 == 0 ) {
V_139 = F_9 ( sizeof( * V_139 ) , V_31 ) ;
if ( V_139 == NULL )
V_25 = - V_32 ;
else {
V_139 -> V_131 = V_141 ;
V_139 -> V_157 = V_163 ;
V_139 -> V_133 = V_147 ;
V_139 -> V_130 = V_7 ;
F_79 ( V_139 ) ;
}
} else {
V_139 -> V_130 = V_7 ;
}
if ( V_25 == 0 )
V_25 = V_63 ;
F_11 ( & V_167 ) ;
V_154:
F_19 ( V_142 ) ;
V_153:
F_19 ( V_54 ) ;
return V_25 ;
}
static T_1 F_82 ( struct V_61 * V_168 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_169 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_169 , L_9 , V_94 ) ;
V_25 = F_83 ( V_62 , V_63 , V_64 , V_169 , strlen ( V_169 ) ) ;
return V_25 ;
}
static T_1 F_84 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_169 [ 80 ] ;
int V_59 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
if ( V_63 >= sizeof( V_169 ) || V_63 == 0 )
return - V_60 ;
if ( F_85 ( V_169 , V_62 , V_63 ) != 0 )
return - V_170 ;
V_169 [ V_63 ] = '\0' ;
if ( sscanf ( V_169 , L_9 , & V_59 ) != 1 )
return - V_60 ;
V_94 = V_59 ;
F_42 () ;
return V_63 ;
}
static T_1 F_86 ( struct V_61 * V_168 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_169 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_169 , L_9 , V_171 ) ;
V_25 = F_83 ( V_62 , V_63 , V_64 , V_169 , strlen ( V_169 ) ) ;
return V_25 ;
}
static T_1 F_87 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char V_169 [ 80 ] ;
int V_59 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
if ( V_63 >= sizeof( V_169 ) || V_63 == 0 )
return - V_60 ;
if ( F_85 ( V_169 , V_62 , V_63 ) != 0 )
return - V_170 ;
V_169 [ V_63 ] = '\0' ;
if ( sscanf ( V_169 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_171 != V_59 ) {
F_7 ( & V_172 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_106 . V_107 . V_108 . V_110 ==
V_171 )
V_7 -> V_106 . V_107 . V_108 . V_110 = V_59 ;
V_171 = V_59 ;
F_11 ( & V_172 ) ;
}
return V_63 ;
}
static T_1 F_88 ( struct V_61 * V_168 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_169 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_169 , L_9 , V_173 ) ;
V_25 = F_83 ( V_62 , V_63 , V_64 , V_169 , strlen ( V_169 ) ) ;
return V_25 ;
}
static T_1 F_89 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char V_169 [ 80 ] ;
int V_59 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
if ( V_63 >= sizeof( V_169 ) || V_63 == 0 )
return - V_60 ;
if ( F_85 ( V_169 , V_62 , V_63 ) != 0 )
return - V_170 ;
V_169 [ V_63 ] = '\0' ;
if ( sscanf ( V_169 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_173 != V_59 ) {
F_7 ( & V_172 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_106 . V_107 . V_108 . V_110 ==
V_173 )
V_7 -> V_106 . V_107 . V_108 . V_110 = V_59 ;
V_173 = V_59 ;
F_11 ( & V_172 ) ;
}
return V_63 ;
}
static T_1 F_90 ( struct V_61 * V_168 , char T_2 * V_62 ,
T_3 V_174 , T_4 * V_64 )
{
T_1 V_25 ;
int V_175 ;
if ( * V_64 != 0 )
return 0 ;
F_7 ( & V_176 ) ;
V_175 = strlen ( V_101 -> V_80 ) + 1 ;
if ( V_174 >= V_175 )
V_25 = F_83 ( V_62 , V_174 , V_64 ,
V_101 -> V_80 ,
V_175 ) ;
else
V_25 = - V_60 ;
F_11 ( & V_176 ) ;
return V_25 ;
}
static T_1 F_91 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char * V_100 ;
char * V_54 ;
int V_25 = V_63 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
V_54 = F_23 ( V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
V_7 = F_14 ( V_54 , V_63 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_33;
}
F_7 ( & V_176 ) ;
V_100 = V_101 -> V_80 ;
V_101 = V_7 ;
F_49 ( V_100 ) ;
F_11 ( & V_176 ) ;
V_33:
F_19 ( V_54 ) ;
return V_25 ;
}
static void * F_92 ( struct V_74 * V_75 , T_4 * V_76 )
{
return F_24 ( V_75 , V_76 , & V_177 ) ;
}
static void * F_93 ( struct V_74 * V_75 , void * V_78 , T_4 * V_76 )
{
return F_28 ( V_75 , V_78 , V_76 , & V_177 ) ;
}
static int F_94 ( struct V_74 * V_75 , void * V_78 )
{
struct V_15 * V_34 = V_78 ;
struct V_178 * V_179 =
F_37 ( V_34 , struct V_178 , V_34 ) ;
F_95 ( V_75 , V_179 -> V_130 -> V_80 ) ;
F_33 ( V_75 , ' ' ) ;
return 0 ;
}
static int F_96 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
return F_39 ( V_61 , & V_180 ) ;
}
static void F_97 ( struct V_15 * V_181 ,
struct V_15 * V_182 )
{
struct V_15 * V_183 , * V_184 ;
if ( F_68 ( V_181 ) ) {
F_98 ( V_182 , V_181 , V_185 ) ;
} else {
V_183 = V_181 -> V_138 ;
V_184 = V_181 -> V_186 ;
V_182 -> V_186 -> V_138 = V_181 ;
V_182 -> V_138 -> V_186 = V_181 ;
F_99 ( V_181 -> V_138 , V_182 -> V_138 ) ;
V_181 -> V_186 = V_182 -> V_186 ;
V_185 () ;
V_182 -> V_138 = V_183 ;
V_182 -> V_186 = V_184 ;
V_183 -> V_186 = V_182 ;
V_184 -> V_138 = V_182 ;
}
}
static int F_100 ( char * V_54 , struct V_15 * V_34 )
{
char * V_58 ;
struct V_6 * V_7 ;
struct V_178 * V_179 ;
while ( ( V_58 = F_101 ( & V_54 , L_17 ) ) != NULL ) {
if ( ! * V_58 )
continue;
V_7 = F_14 ( V_58 , 0 ) ;
if ( F_15 ( V_7 ) )
return F_16 ( V_7 ) ;
V_179 = F_9 ( sizeof( * V_179 ) , V_31 ) ;
if ( V_179 == NULL )
return - V_32 ;
V_179 -> V_130 = V_7 ;
F_102 ( & V_179 -> V_34 , V_34 ) ;
}
return 0 ;
}
void F_103 ( struct V_15 * V_34 )
{
struct V_178 * V_179 ;
struct V_178 * V_187 ;
F_104 (sklep, sklep2, list, list)
F_19 ( V_179 ) ;
F_105 ( V_34 ) ;
}
static T_1 F_106 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_54 ;
F_107 ( V_188 ) ;
int V_25 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
V_54 = F_23 ( V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
V_25 = F_100 ( V_54 , & V_188 ) ;
F_19 ( V_54 ) ;
if ( ! V_25 || ( V_25 == - V_60 && F_68 ( & V_188 ) ) ) {
F_7 ( & V_189 ) ;
F_97 ( & V_177 , & V_188 ) ;
F_11 ( & V_189 ) ;
V_25 = V_63 ;
}
F_103 ( & V_188 ) ;
return V_25 ;
}
static T_1 F_108 ( struct V_61 * V_168 , char T_2 * V_62 ,
T_3 V_174 , T_4 * V_64 )
{
char * V_142 = L_18 ;
T_1 V_25 = - V_60 ;
int V_175 ;
if ( * V_64 != 0 )
return 0 ;
if ( V_190 != NULL )
V_142 = V_190 -> V_80 ;
V_175 = strlen ( V_142 ) + 1 ;
if ( V_174 >= V_175 )
V_25 = F_83 ( V_62 , V_174 , V_64 , V_142 , V_175 ) ;
return V_25 ;
}
static T_1 F_109 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_54 ;
struct V_6 * V_7 ;
int V_25 = V_63 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
V_54 = F_23 ( V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
V_7 = F_14 ( V_54 , V_63 ) ;
if ( F_16 ( V_7 ) == - V_60 )
V_7 = NULL ;
else if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_191;
}
V_190 = V_7 ;
V_191:
F_19 ( V_54 ) ;
return V_25 ;
}
static T_1 F_110 ( struct V_61 * V_168 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_169 [ 32 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_169 , L_19 , V_192 ) ;
V_25 = F_83 ( V_62 , V_63 , V_64 , V_169 , strlen ( V_169 ) ) ;
return V_25 ;
}
static T_1 F_111 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_169 [ 32 ] ;
int V_59 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
if ( V_63 >= sizeof( V_169 ) || V_63 == 0 )
return - V_60 ;
if ( F_85 ( V_169 , V_62 , V_63 ) != 0 )
return - V_170 ;
V_169 [ V_63 ] = '\0' ;
if ( sscanf ( V_169 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_59 < 0 || V_59 > 3 )
return - V_60 ;
V_192 = V_59 ;
return V_63 ;
}
static void * F_112 ( struct V_74 * V_75 , T_4 * V_76 )
{
struct V_193 * V_194 = F_113 () ;
return F_24 ( V_75 , V_76 , & V_194 -> V_72 ) ;
}
static void * F_114 ( struct V_74 * V_75 , void * V_78 , T_4 * V_76 )
{
struct V_193 * V_194 = F_113 () ;
return F_28 ( V_75 , V_78 , V_76 , & V_194 -> V_72 ) ;
}
static int F_115 ( struct V_74 * V_75 , void * V_78 )
{
struct V_15 * V_34 = V_78 ;
struct V_20 * V_14 =
F_37 ( V_34 , struct V_20 , V_34 ) ;
F_31 ( V_75 , V_14 , V_55 ) ;
return 0 ;
}
static int F_116 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
return F_39 ( V_61 , & V_195 ) ;
}
static T_1 F_117 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_193 * V_194 = F_113 () ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , & V_194 -> V_72 ,
& V_194 -> V_73 , V_67 ) ;
}
static T_1 F_118 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 , int V_65 )
{
struct V_13 V_50 ;
char * V_54 ;
int V_196 ;
V_54 = F_119 ( V_61 , V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
if ( V_65 == V_67 ) {
if ( V_63 < V_69 )
return - V_60 ;
V_196 = F_20 ( V_54 , & V_50 , 0 ) ;
} else {
V_196 = F_21 ( V_54 , & V_50 , 0 , 3 ) ;
}
if ( V_196 >= 0 )
V_196 = V_28 ( V_50 . V_27 , V_50 . V_26 ,
V_50 . V_29 , NULL ) ;
else if ( V_196 != - V_53 )
return V_196 ;
V_54 [ 0 ] = V_196 >= 0 ? '1' : '0' ;
V_54 [ 1 ] = '\0' ;
F_120 ( V_61 , 2 ) ;
if ( V_65 == V_67 )
return V_69 ;
return V_63 ;
}
static T_1 F_121 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_118 ( V_61 , V_62 , V_63 , V_64 , V_67 ) ;
}
static int F_122 ( struct V_74 * V_75 , void * V_78 )
{
struct V_15 * V_34 = V_78 ;
struct V_22 * V_23 =
F_37 ( V_34 , struct V_22 , V_34 ) ;
F_31 ( V_75 , V_23 -> V_35 , V_197 ) ;
return 0 ;
}
static int F_123 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
return F_39 ( V_61 , & V_198 ) ;
}
static T_1 F_124 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_41 ( V_83 ) )
return - V_84 ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_125 ) ;
}
static void * F_125 ( struct V_74 * V_75 , T_4 * V_76 )
{
struct V_193 * V_194 = F_113 () ;
return F_24 ( V_75 , V_76 , & V_194 -> V_72 ) ;
}
static void * F_126 ( struct V_74 * V_75 , void * V_78 , T_4 * V_76 )
{
struct V_193 * V_194 = F_113 () ;
return F_28 ( V_75 , V_78 , V_76 , & V_194 -> V_72 ) ;
}
static int F_127 ( struct V_74 * V_75 , void * V_78 )
{
struct V_15 * V_34 = V_78 ;
struct V_20 * V_14 =
F_37 ( V_34 , struct V_20 , V_34 ) ;
F_31 ( V_75 , V_14 , V_197 ) ;
return 0 ;
}
static int F_128 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
return F_39 ( V_61 , & V_199 ) ;
}
static T_1 F_129 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_193 * V_194 = F_113 () ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , & V_194 -> V_72 ,
& V_194 -> V_73 , V_125 ) ;
}
static T_1 F_130 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_118 ( V_61 , V_62 , V_63 , V_64 , V_125 ) ;
}
static T_1 F_131 ( struct V_61 * V_61 , const char T_2 * V_62 ,
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
if ( ! F_41 ( V_83 ) )
return - V_84 ;
if ( V_63 == 0 || V_63 > V_197 )
return - V_60 ;
V_54 = F_132 ( V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
V_38 = F_17 ( V_54 , V_63 ) ;
if ( F_15 ( V_38 ) ) {
V_25 = F_16 ( V_38 ) ;
goto V_200;
}
V_7 = F_18 ( V_38 ) ;
if ( V_7 == NULL )
goto V_201;
V_16 = & V_7 -> V_72 ;
V_18 = & V_7 -> V_73 ;
F_7 ( V_18 ) ;
F_8 (sp, rule_list, list)
V_21 -> V_28 = 0 ;
F_11 ( V_18 ) ;
V_201:
F_19 ( V_38 ) ;
V_200:
F_19 ( V_54 ) ;
return V_25 ;
}
static int F_133 ( void )
{
return F_134 ( V_202 , L_20 ) ;
}
static T_1 F_135 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_41 ( V_83 ) )
return - V_84 ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_71 ) ;
}
static T_1 F_136 ( struct V_61 * V_168 , char T_2 * V_62 ,
T_3 V_174 , T_4 * V_64 )
{
struct V_6 * V_7 ;
T_1 V_25 = - V_60 ;
int V_175 ;
if ( * V_64 != 0 )
return 0 ;
if ( V_203 == NULL )
V_7 = & V_204 ;
else
V_7 = V_203 ;
V_175 = strlen ( V_7 -> V_80 ) + 1 ;
if ( V_174 >= V_175 )
V_25 = F_83 ( V_62 , V_174 , V_64 , V_7 -> V_80 ,
V_175 ) ;
return V_25 ;
}
static T_1 F_137 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_54 ;
struct V_6 * V_7 ;
int V_25 = V_63 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
V_54 = F_23 ( V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
V_7 = F_14 ( V_54 , V_63 ) ;
if ( F_15 ( V_7 ) )
V_25 = F_16 ( V_7 ) ;
else
V_203 = V_7 ;
F_19 ( V_54 ) ;
return V_25 ;
}
static void * F_138 ( struct V_74 * V_75 , T_4 * V_76 )
{
struct V_193 * V_194 = F_113 () ;
return F_24 ( V_75 , V_76 , & V_194 -> V_205 ) ;
}
static void * F_139 ( struct V_74 * V_75 , void * V_78 , T_4 * V_76 )
{
struct V_193 * V_194 = F_113 () ;
return F_28 ( V_75 , V_78 , V_76 , & V_194 -> V_205 ) ;
}
static int F_140 ( struct V_74 * V_75 , void * V_78 )
{
struct V_15 * V_34 = V_78 ;
struct V_178 * V_179 =
F_77 ( V_34 , struct V_178 , V_34 ) ;
F_95 ( V_75 , V_179 -> V_130 -> V_80 ) ;
F_33 ( V_75 , ' ' ) ;
return 0 ;
}
static int F_141 ( struct V_81 * V_81 , struct V_61 * V_61 )
{
return F_39 ( V_61 , & V_206 ) ;
}
static T_1 F_142 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_193 * V_194 = F_113 () ;
char * V_54 ;
int V_25 ;
F_107 ( V_188 ) ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
if ( * V_64 != 0 )
return - V_60 ;
V_54 = F_23 ( V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
V_25 = F_100 ( V_54 , & V_188 ) ;
F_19 ( V_54 ) ;
if ( ! V_25 || ( V_25 == - V_60 && F_68 ( & V_188 ) ) ) {
F_103 ( & V_194 -> V_205 ) ;
F_143 ( & V_188 , & V_194 -> V_205 ) ;
return V_63 ;
}
F_103 ( & V_188 ) ;
return V_25 ;
}
static T_1 F_144 ( struct V_61 * V_168 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_169 [ 32 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_169 , L_19 , V_207 ) ;
V_25 = F_83 ( V_62 , V_63 , V_64 , V_169 , strlen ( V_169 ) ) ;
return V_25 ;
}
static T_1 F_145 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_169 [ 32 ] ;
int V_59 ;
if ( ! F_41 ( V_83 ) )
return - V_84 ;
if ( * V_64 != 0 || V_63 >= sizeof( V_169 ) || V_63 == 0 )
return - V_60 ;
if ( F_85 ( V_169 , V_62 , V_63 ) != 0 )
return - V_170 ;
V_169 [ V_63 ] = '\0' ;
if ( sscanf ( V_169 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_59 < V_208 || V_59 > V_209 )
return - V_60 ;
V_207 = V_59 ;
return V_63 ;
}
static int F_146 ( struct V_210 * V_211 , void * V_54 , int V_212 )
{
int V_25 ;
struct V_81 * V_213 ;
static struct V_214 V_215 [] = {
[ V_216 ] = {
L_21 , & V_217 , V_218 | V_219 } ,
[ V_220 ] = {
L_22 , & V_221 , V_218 | V_219 } ,
[ V_222 ] = {
L_23 , & V_223 , V_218 | V_219 } ,
[ V_224 ] = {
L_24 , & V_225 , V_218 | V_219 } ,
[ V_226 ] = {
L_25 , & V_227 , V_218 | V_219 } ,
[ V_228 ] = {
L_26 , & V_229 , V_218 | V_219 } ,
[ V_230 ] = {
L_27 , & V_231 , V_218 | V_219 } ,
[ V_232 ] = {
L_28 , & V_233 , V_218 | V_219 } ,
[ V_234 ] = {
L_29 , & V_235 , V_218 | V_236 } ,
[ V_237 ] = {
L_30 , & V_238 , V_218 | V_236 } ,
[ V_239 ] = {
L_31 , & V_240 , V_218 | V_219 } ,
[ V_241 ] = {
L_32 , & V_242 , V_218 | V_219 } ,
[ V_243 ] = {
L_33 , & V_244 , V_218 | V_236 } ,
[ V_245 ] = {
L_34 , & V_246 , V_218 | V_236 } ,
[ V_247 ] = {
L_35 , & V_248 , V_218 | V_219 } ,
[ V_249 ] = {
L_36 , & V_250 ,
V_218 | V_219 } ,
[ V_251 ] = {
L_37 , & V_252 , V_218 | V_219 } ,
[ V_253 ] = {
L_38 , & V_254 , V_218 | V_219 } ,
[ V_255 ] = {
L_39 , & V_256 , V_218 | V_219 } ,
#ifdef F_147
[ V_257 ] = {
L_40 , & V_258 , V_218 | V_219 } ,
#endif
#if F_148 ( V_259 )
[ V_260 ] = {
L_41 , & V_261 , V_218 | V_219 } ,
#endif
[ V_262 ] = {
L_42 , & V_263 ,
V_218 | V_236 } ,
{ L_18 }
} ;
V_25 = F_149 ( V_211 , V_264 , V_215 ) ;
if ( V_25 != 0 ) {
F_44 ( V_265 L_43 ,
V_90 , V_25 ) ;
return V_25 ;
}
V_213 = F_150 ( V_211 -> V_266 ) ;
return 0 ;
}
static struct V_267 * F_151 ( struct V_268 * V_269 ,
int V_270 , const char * V_271 , void * V_54 )
{
return F_152 ( V_269 , V_270 , V_54 , F_146 ) ;
}
static int T_7 F_153 ( struct V_6 * V_7 )
{
V_7 -> V_106 . V_272 = V_7 -> V_80 ;
V_7 -> V_106 . V_270 =
V_273 | V_274 ;
return F_57 ( V_171 , V_7 -> V_80 ,
& V_7 -> V_106 , strlen ( V_7 -> V_80 ) ) ;
}
static int T_7 F_154 ( void )
{
int V_275 ;
int V_25 ;
if ( V_276 == 0 )
return 0 ;
V_275 = F_133 () ;
if ( V_275 )
F_44 ( V_265 L_44 ) ;
V_275 = F_155 ( & V_277 ) ;
if ( ! V_275 ) {
V_278 = F_156 ( & V_277 ) ;
if ( F_15 ( V_278 ) ) {
F_44 ( V_265 L_45 ) ;
V_275 = F_16 ( V_278 ) ;
V_278 = NULL ;
}
}
F_42 () ;
F_49 ( NULL ) ;
V_25 = F_153 ( & V_102 ) ;
if ( V_275 == 0 && V_25 < 0 )
V_275 = V_25 ;
V_25 = F_153 ( & V_279 ) ;
if ( V_275 == 0 && V_25 < 0 )
V_275 = V_25 ;
V_25 = F_153 ( & V_280 ) ;
if ( V_275 == 0 && V_25 < 0 )
V_275 = V_25 ;
V_25 = F_153 ( & V_204 ) ;
if ( V_275 == 0 && V_25 < 0 )
V_275 = V_25 ;
V_25 = F_153 ( & V_281 ) ;
if ( V_275 == 0 && V_25 < 0 )
V_275 = V_25 ;
return V_275 ;
}
