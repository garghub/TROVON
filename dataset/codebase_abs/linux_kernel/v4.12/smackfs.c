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
F_11 ( V_18 ) ;
V_23 = F_9 ( sizeof( * V_23 ) , V_31 ) ;
if ( V_23 != NULL ) {
V_23 -> V_35 = V_21 ;
F_7 ( & V_36 ) ;
F_10 ( & V_23 -> V_34 , & V_37 ) ;
F_11 ( & V_36 ) ;
} else
V_25 = - V_32 ;
return V_25 ;
}
}
V_33:
F_11 ( V_18 ) ;
return V_25 ;
}
static int F_12 ( const char * string )
{
int V_38 = 0 ;
const char * V_39 ;
for ( V_39 = string ; ; V_39 ++ )
switch ( * V_39 ) {
case '-' :
break;
case 'r' :
case 'R' :
V_38 |= V_40 ;
break;
case 'w' :
case 'W' :
V_38 |= V_41 ;
break;
case 'x' :
case 'X' :
V_38 |= V_42 ;
break;
case 'a' :
case 'A' :
V_38 |= V_43 ;
break;
case 't' :
case 'T' :
V_38 |= V_44 ;
break;
case 'l' :
case 'L' :
V_38 |= V_45 ;
break;
case 'b' :
case 'B' :
V_38 |= V_46 ;
break;
default:
return V_38 ;
}
}
static int F_13 ( const char * V_47 , const char * V_48 ,
const char * V_49 , const char * V_50 ,
struct V_13 * V_51 , int V_52 ,
int V_53 )
{
const char * V_39 ;
struct V_6 * V_7 ;
if ( V_52 ) {
V_51 -> V_27 = F_14 ( V_47 , V_53 ) ;
if ( F_15 ( V_51 -> V_27 ) )
return F_16 ( V_51 -> V_27 ) ;
V_51 -> V_26 = F_14 ( V_48 , V_53 ) ;
if ( F_15 ( V_51 -> V_26 ) )
return F_16 ( V_51 -> V_26 ) ;
} else {
V_39 = F_17 ( V_47 , V_53 ) ;
if ( F_15 ( V_39 ) )
return F_16 ( V_39 ) ;
V_7 = F_18 ( V_39 ) ;
F_19 ( V_39 ) ;
if ( V_7 == NULL )
return - V_54 ;
V_51 -> V_27 = V_7 ;
V_39 = F_17 ( V_48 , V_53 ) ;
if ( F_15 ( V_39 ) )
return F_16 ( V_39 ) ;
V_7 = F_18 ( V_39 ) ;
F_19 ( V_39 ) ;
if ( V_7 == NULL )
return - V_54 ;
V_51 -> V_26 = V_7 ;
}
V_51 -> V_29 = F_12 ( V_49 ) ;
if ( V_50 )
V_51 -> V_30 = F_12 ( V_50 ) ;
else
V_51 -> V_30 = ~ V_51 -> V_29 ;
return 0 ;
}
static int F_20 ( const char * V_55 , struct V_13 * V_51 ,
int V_52 )
{
int V_25 ;
V_25 = F_13 ( V_55 , V_55 + V_56 ,
V_55 + V_56 + V_56 , NULL , V_51 ,
V_52 , V_56 ) ;
return V_25 ;
}
static T_1 F_21 ( char * V_55 , struct V_13 * V_51 ,
int V_52 , int V_57 )
{
T_1 V_58 = 0 ;
char * V_59 [ 4 ] ;
int V_25 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_57 ; ++ V_60 ) {
while ( isspace ( V_55 [ V_58 ] ) )
V_55 [ V_58 ++ ] = '\0' ;
if ( V_55 [ V_58 ] == '\0' )
return - V_61 ;
V_59 [ V_60 ] = V_55 + V_58 ;
while ( V_55 [ V_58 ] && ! isspace ( V_55 [ V_58 ] ) )
++ V_58 ;
}
while ( isspace ( V_55 [ V_58 ] ) )
V_55 [ V_58 ++ ] = '\0' ;
while ( V_60 < 4 )
V_59 [ V_60 ++ ] = NULL ;
V_25 = F_13 ( V_59 [ 0 ] , V_59 [ 1 ] , V_59 [ 2 ] , V_59 [ 3 ] , V_51 , V_52 , 0 ) ;
return V_25 == 0 ? V_58 : V_25 ;
}
static T_1 F_22 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 ,
struct V_15 * V_16 ,
struct V_17 * V_18 , int V_66 )
{
struct V_13 V_51 ;
char * V_55 ;
int V_25 ;
int V_67 = 0 ;
int V_57 ;
T_1 V_58 = 0 ;
if ( * V_65 != 0 )
return - V_61 ;
if ( V_66 == V_68 ) {
if ( V_64 < V_69 || V_64 > V_70 )
return - V_61 ;
} else {
if ( V_64 >= V_71 ) {
V_64 = V_71 - 1 ;
V_67 = 1 ;
}
}
V_55 = F_23 ( V_63 , V_64 ) ;
if ( F_15 ( V_55 ) )
return F_16 ( V_55 ) ;
if ( V_67 ) {
while ( V_64 > 0 && ( V_55 [ V_64 - 1 ] != '\n' ) )
-- V_64 ;
if ( V_64 == 0 ) {
V_25 = - V_61 ;
goto V_33;
}
}
V_55 [ V_64 ] = '\0' ;
V_57 = ( V_66 == V_72 ? 4 : 3 ) ;
while ( V_58 < V_64 ) {
if ( V_66 == V_68 ) {
V_25 = F_20 ( V_55 , & V_51 , 1 ) ;
if ( V_25 < 0 )
goto V_33;
V_58 = V_64 ;
} else {
V_25 = F_21 ( V_55 + V_58 , & V_51 , 1 , V_57 ) ;
if ( V_25 < 0 )
goto V_33;
if ( V_25 == 0 ) {
V_25 = - V_61 ;
goto V_33;
}
V_58 += V_25 ;
}
if ( V_16 == NULL )
V_25 = F_6 ( & V_51 , & V_51 . V_27 -> V_73 ,
& V_51 . V_27 -> V_74 , 1 ) ;
else
V_25 = F_6 ( & V_51 , V_16 , V_18 , 0 ) ;
if ( V_25 )
goto V_33;
}
V_25 = V_58 ;
V_33:
F_19 ( V_55 ) ;
return V_25 ;
}
static void * F_24 ( struct V_75 * V_76 , T_4 * V_77 ,
struct V_15 * V_78 )
{
struct V_15 * V_34 ;
int V_60 = * V_77 ;
F_25 () ;
for ( V_34 = F_26 ( F_27 ( V_78 ) ) ;
V_34 != V_78 ;
V_34 = F_26 ( F_27 ( V_34 ) ) ) {
if ( V_60 -- == 0 )
return V_34 ;
}
return NULL ;
}
static void * F_28 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 ,
struct V_15 * V_78 )
{
struct V_15 * V_34 = V_79 ;
++ * V_77 ;
V_34 = F_26 ( F_27 ( V_34 ) ) ;
return ( V_34 == V_78 ) ? NULL : V_34 ;
}
static void F_29 ( struct V_75 * V_76 , void * V_79 )
{
F_30 () ;
}
static void F_31 ( struct V_75 * V_76 , struct V_20 * V_14 , int V_80 )
{
if ( strlen ( V_14 -> V_27 -> V_81 ) >= V_80 ||
strlen ( V_14 -> V_26 -> V_81 ) >= V_80 )
return;
if ( V_14 -> V_28 == 0 )
return;
F_32 ( V_76 , L_1 ,
V_14 -> V_27 -> V_81 ,
V_14 -> V_26 -> V_81 ) ;
F_33 ( V_76 , ' ' ) ;
if ( V_14 -> V_28 & V_40 )
F_33 ( V_76 , 'r' ) ;
if ( V_14 -> V_28 & V_41 )
F_33 ( V_76 , 'w' ) ;
if ( V_14 -> V_28 & V_42 )
F_33 ( V_76 , 'x' ) ;
if ( V_14 -> V_28 & V_43 )
F_33 ( V_76 , 'a' ) ;
if ( V_14 -> V_28 & V_44 )
F_33 ( V_76 , 't' ) ;
if ( V_14 -> V_28 & V_45 )
F_33 ( V_76 , 'l' ) ;
if ( V_14 -> V_28 & V_46 )
F_33 ( V_76 , 'b' ) ;
F_33 ( V_76 , '\n' ) ;
}
static void * F_34 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_24 ( V_76 , V_77 , & V_37 ) ;
}
static void * F_35 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
return F_28 ( V_76 , V_79 , V_77 , & V_37 ) ;
}
static int F_36 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_22 * V_23 =
F_37 ( V_34 , struct V_22 , V_34 ) ;
F_31 ( V_76 , V_23 -> V_35 , V_56 ) ;
return 0 ;
}
static int F_38 ( struct V_82 * V_82 , struct V_62 * V_62 )
{
return F_39 ( V_62 , & V_83 ) ;
}
static T_1 F_40 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
if ( ! F_41 ( V_84 ) )
return - V_85 ;
return F_22 ( V_62 , V_63 , V_64 , V_65 , NULL , NULL ,
V_68 ) ;
}
static void F_42 ( void )
{
int V_25 ;
struct V_86 * V_87 ;
struct V_4 V_88 ;
F_2 ( & V_88 ) ;
V_25 = F_43 ( NULL , V_89 , NULL , NULL , & V_88 ) ;
if ( V_25 != 0 )
F_44 ( V_90 L_2 ,
V_91 , __LINE__ , V_25 ) ;
V_87 = F_45 ( sizeof( struct V_86 ) , V_31 ) ;
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
F_44 ( V_90 L_4 ,
V_91 , __LINE__ , V_25 ) ;
F_19 ( V_87 ) ;
return;
}
V_25 = F_48 ( V_87 -> V_94 , NULL , NULL , NULL , & V_88 ) ;
if ( V_25 != 0 ) {
F_44 ( V_90 L_5 ,
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
V_25 = F_43 ( V_101 , V_89 , NULL , NULL , & V_88 ) ;
if ( V_25 != 0 )
F_44 ( V_90 L_2 ,
V_91 , __LINE__ , V_25 ) ;
}
if ( V_102 == NULL )
V_102 = & V_103 ;
V_25 = F_50 ( V_102 -> V_81 , V_89 ,
NULL , NULL , & V_88 ) ;
if ( V_25 != 0 )
F_44 ( V_90 L_6 ,
V_91 , __LINE__ , V_25 ) ;
}
static void * F_51 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_24 ( V_76 , V_77 , & V_104 ) ;
}
static void * F_52 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
return F_28 ( V_76 , V_79 , V_77 , & V_104 ) ;
}
static int F_53 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_6 * V_7 =
F_37 ( V_34 , struct V_6 , V_34 ) ;
struct V_105 * V_106 = V_7 -> V_107 . V_108 . V_109 . V_1 ;
char V_110 = '/' ;
int V_60 ;
if ( strlen ( V_7 -> V_81 ) >= V_56 )
return 0 ;
F_32 ( V_76 , L_7 , V_7 -> V_81 , V_7 -> V_107 . V_108 . V_109 . V_111 ) ;
for ( V_60 = F_54 ( V_106 , 0 ) ; V_60 >= 0 ;
V_60 = F_54 ( V_106 , V_60 + 1 ) ) {
F_32 ( V_76 , L_8 , V_110 , V_60 ) ;
V_110 = ',' ;
}
F_33 ( V_76 , '\n' ) ;
return 0 ;
}
static int F_55 ( struct V_82 * V_82 , struct V_62 * V_62 )
{
return F_39 ( V_62 , & V_112 ) ;
}
static T_1 F_56 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 , int V_66 )
{
struct V_6 * V_7 ;
struct V_113 V_114 ;
char V_115 [ V_3 ] ;
int V_116 ;
unsigned int V_1 ;
int V_117 ;
T_1 V_25 = - V_61 ;
char * V_55 = NULL ;
char * V_51 ;
int V_118 ;
int V_60 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
if ( * V_65 != 0 )
return - V_61 ;
if ( V_66 == V_68 &&
( V_64 < V_119 || V_64 > V_120 ) )
return - V_61 ;
V_55 = F_23 ( V_63 , V_64 ) ;
if ( F_15 ( V_55 ) )
return F_16 ( V_55 ) ;
V_51 = V_55 ;
F_7 ( & V_121 ) ;
V_7 = F_14 ( V_51 , 0 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_33;
}
if ( V_66 == V_68 )
V_51 += V_56 ;
else
V_51 += strlen ( V_7 -> V_81 ) + 1 ;
V_118 = sscanf ( V_51 , L_9 , & V_116 ) ;
if ( V_118 != 1 || V_116 > V_122 )
goto V_33;
V_51 += V_123 ;
V_118 = sscanf ( V_51 , L_9 , & V_117 ) ;
if ( V_118 != 1 || V_117 > V_124 )
goto V_33;
if ( V_66 == V_68 &&
V_64 != ( V_119 + V_117 * V_123 ) )
goto V_33;
memset ( V_115 , 0 , sizeof( V_115 ) ) ;
for ( V_60 = 0 ; V_60 < V_117 ; V_60 ++ ) {
V_51 += V_123 ;
V_118 = sscanf ( V_51 , L_10 , & V_1 ) ;
if ( V_118 != 1 || V_1 > V_124 )
goto V_33;
F_1 ( V_1 , V_115 ) ;
}
V_25 = F_57 ( V_116 , V_115 , & V_114 , V_3 ) ;
if ( V_25 >= 0 ) {
F_58 ( V_7 -> V_107 . V_108 . V_109 . V_1 ) ;
V_7 -> V_107 . V_108 . V_109 . V_1 = V_114 . V_108 . V_109 . V_1 ;
V_7 -> V_107 . V_108 . V_109 . V_111 = V_114 . V_108 . V_109 . V_111 ;
V_25 = V_64 ;
}
V_33:
F_11 ( & V_121 ) ;
F_19 ( V_55 ) ;
return V_25 ;
}
static T_1 F_59 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
return F_56 ( V_62 , V_63 , V_64 , V_65 , V_68 ) ;
}
static int F_60 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_6 * V_7 =
F_37 ( V_34 , struct V_6 , V_34 ) ;
struct V_105 * V_106 = V_7 -> V_107 . V_108 . V_109 . V_1 ;
char V_110 = '/' ;
int V_60 ;
F_32 ( V_76 , L_7 , V_7 -> V_81 , V_7 -> V_107 . V_108 . V_109 . V_111 ) ;
for ( V_60 = F_54 ( V_106 , 0 ) ; V_60 >= 0 ;
V_60 = F_54 ( V_106 , V_60 + 1 ) ) {
F_32 ( V_76 , L_8 , V_110 , V_60 ) ;
V_110 = ',' ;
}
F_33 ( V_76 , '\n' ) ;
return 0 ;
}
static int F_61 ( struct V_82 * V_82 , struct V_62 * V_62 )
{
return F_39 ( V_62 , & V_125 ) ;
}
static T_1 F_62 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
return F_56 ( V_62 , V_63 , V_64 , V_65 , V_126 ) ;
}
static void * F_63 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_24 ( V_76 , V_77 , & V_127 ) ;
}
static void * F_64 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
return F_28 ( V_76 , V_79 , V_77 , & V_127 ) ;
}
static int F_65 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_128 * V_7 =
F_37 ( V_34 , struct V_128 , V_34 ) ;
char * V_129 = V_130 ;
if ( V_7 -> V_131 != NULL )
V_129 = V_7 -> V_131 -> V_81 ;
F_32 ( V_76 , L_11 , & V_7 -> V_132 . V_133 ,
V_7 -> V_134 , V_129 ) ;
return 0 ;
}
static int F_66 ( struct V_82 * V_82 , struct V_62 * V_62 )
{
return F_39 ( V_62 , & V_135 ) ;
}
static void F_67 ( struct V_128 * V_136 )
{
struct V_128 * V_137 ;
struct V_128 * V_138 ;
if ( F_68 ( & V_127 ) ) {
F_10 ( & V_136 -> V_34 , & V_127 ) ;
return;
}
V_137 = F_37 ( V_127 . V_139 ,
struct V_128 , V_34 ) ;
if ( V_136 -> V_134 > V_137 -> V_134 ) {
F_10 ( & V_136 -> V_34 , & V_127 ) ;
return;
}
F_8 (m, &smk_net4addr_list, list) {
if ( F_69 ( & V_137 -> V_34 , & V_127 ) ) {
F_10 ( & V_136 -> V_34 , & V_137 -> V_34 ) ;
return;
}
V_138 = F_37 ( V_137 -> V_34 . V_139 ,
struct V_128 , V_34 ) ;
if ( V_136 -> V_134 > V_138 -> V_134 ) {
F_10 ( & V_136 -> V_34 , & V_137 -> V_34 ) ;
return;
}
}
}
static T_1 F_70 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
struct V_128 * V_140 ;
struct V_141 V_142 ;
char * V_143 ;
struct V_6 * V_7 = NULL ;
char * V_55 ;
char * V_144 = ( char * ) & V_142 . V_145 . V_133 ;
int V_25 ;
struct V_4 V_146 ;
struct V_147 V_148 ;
unsigned int V_137 ;
unsigned int V_149 ;
int V_24 ;
T_5 V_150 = ( 1 << 31 ) ;
T_6 V_151 ;
T_5 V_152 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
if ( * V_65 != 0 )
return - V_61 ;
if ( V_64 < V_153 )
return - V_61 ;
V_55 = F_23 ( V_63 , V_64 ) ;
if ( F_15 ( V_55 ) )
return F_16 ( V_55 ) ;
V_143 = F_9 ( V_64 + 1 , V_31 ) ;
if ( V_143 == NULL ) {
V_25 = - V_32 ;
goto V_154;
}
V_25 = sscanf ( V_55 , L_12 ,
& V_144 [ 0 ] , & V_144 [ 1 ] , & V_144 [ 2 ] , & V_144 [ 3 ] , & V_149 , V_143 ) ;
if ( V_25 != 6 ) {
V_25 = sscanf ( V_55 , L_13 ,
& V_144 [ 0 ] , & V_144 [ 1 ] , & V_144 [ 2 ] , & V_144 [ 3 ] , V_143 ) ;
if ( V_25 != 5 ) {
V_25 = - V_61 ;
goto V_155;
}
V_137 = V_156 ;
V_149 = 32 ;
}
if ( V_149 > V_156 ) {
V_25 = - V_61 ;
goto V_155;
}
if ( V_143 [ 0 ] != '-' ) {
V_7 = F_14 ( V_143 , 0 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_155;
}
} else {
if ( strcmp ( V_143 , V_130 ) != 0 ) {
V_25 = - V_61 ;
goto V_155;
}
}
for ( V_137 = V_149 , V_152 = 0 ; V_137 > 0 ; V_137 -- ) {
V_152 |= V_150 ;
V_150 >>= 1 ;
}
V_148 . V_133 = F_71 ( V_152 ) ;
V_142 . V_145 . V_133 &= V_148 . V_133 ;
F_7 ( & V_157 ) ;
V_151 = V_142 . V_145 . V_133 ;
V_24 = 0 ;
F_8 (snp, &smk_net4addr_list, list) {
if ( V_140 -> V_132 . V_133 == V_151 && V_140 -> V_134 == V_149 ) {
V_24 = 1 ;
break;
}
}
F_2 ( & V_146 ) ;
if ( V_24 == 0 ) {
V_140 = F_9 ( sizeof( * V_140 ) , V_31 ) ;
if ( V_140 == NULL )
V_25 = - V_32 ;
else {
V_25 = 0 ;
V_140 -> V_132 . V_133 = V_142 . V_145 . V_133 ;
V_140 -> V_158 . V_133 = V_148 . V_133 ;
V_140 -> V_131 = V_7 ;
V_140 -> V_134 = V_149 ;
F_67 ( V_140 ) ;
}
} else {
if ( V_140 -> V_131 != NULL )
V_25 = F_72 ( & V_159 , NULL ,
& V_140 -> V_132 , & V_140 -> V_158 ,
V_89 , & V_146 ) ;
else
V_25 = 0 ;
V_140 -> V_131 = V_7 ;
}
if ( V_25 == 0 && V_7 != NULL )
V_25 = F_73 ( & V_159 , NULL ,
& V_140 -> V_132 , & V_140 -> V_158 , V_89 ,
V_140 -> V_131 -> V_12 , & V_146 ) ;
if ( V_25 == 0 )
V_25 = V_64 ;
F_11 ( & V_157 ) ;
V_155:
F_19 ( V_143 ) ;
V_154:
F_19 ( V_55 ) ;
return V_25 ;
}
static void * F_74 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_24 ( V_76 , V_77 , & V_160 ) ;
}
static void * F_75 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
return F_28 ( V_76 , V_79 , V_77 , & V_160 ) ;
}
static int F_76 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_161 * V_7 =
F_77 ( V_34 , struct V_161 , V_34 ) ;
if ( V_7 -> V_131 != NULL )
F_32 ( V_76 , L_14 , & V_7 -> V_132 , V_7 -> V_134 ,
V_7 -> V_131 -> V_81 ) ;
return 0 ;
}
static int F_78 ( struct V_82 * V_82 , struct V_62 * V_62 )
{
return F_39 ( V_62 , & V_162 ) ;
}
static void F_79 ( struct V_161 * V_136 )
{
struct V_161 * V_138 ;
struct V_161 * V_137 ;
if ( F_68 ( & V_160 ) ) {
F_10 ( & V_136 -> V_34 , & V_160 ) ;
return;
}
V_137 = F_37 ( V_160 . V_139 ,
struct V_161 , V_34 ) ;
if ( V_136 -> V_134 > V_137 -> V_134 ) {
F_10 ( & V_136 -> V_34 , & V_160 ) ;
return;
}
F_8 (m, &smk_net6addr_list, list) {
if ( F_69 ( & V_137 -> V_34 , & V_160 ) ) {
F_10 ( & V_136 -> V_34 , & V_137 -> V_34 ) ;
return;
}
V_138 = F_37 ( V_137 -> V_34 . V_139 ,
struct V_161 , V_34 ) ;
if ( V_136 -> V_134 > V_138 -> V_134 ) {
F_10 ( & V_136 -> V_34 , & V_137 -> V_34 ) ;
return;
}
}
}
static T_1 F_80 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
struct V_161 * V_140 ;
struct V_163 V_142 ;
struct V_163 V_164 ;
struct V_6 * V_7 = NULL ;
char * V_143 ;
char * V_55 ;
int V_25 = 0 ;
int V_24 = 0 ;
int V_60 ;
unsigned int V_165 [ 8 ] ;
unsigned int V_137 ;
unsigned int V_148 = 128 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
if ( * V_65 != 0 )
return - V_61 ;
if ( V_64 < V_153 )
return - V_61 ;
V_55 = F_23 ( V_63 , V_64 ) ;
if ( F_15 ( V_55 ) )
return F_16 ( V_55 ) ;
V_143 = F_9 ( V_64 + 1 , V_31 ) ;
if ( V_143 == NULL ) {
V_25 = - V_32 ;
goto V_154;
}
V_60 = sscanf ( V_55 , L_15 ,
& V_165 [ 0 ] , & V_165 [ 1 ] , & V_165 [ 2 ] , & V_165 [ 3 ] ,
& V_165 [ 4 ] , & V_165 [ 5 ] , & V_165 [ 6 ] , & V_165 [ 7 ] ,
& V_148 , V_143 ) ;
if ( V_60 != 10 ) {
V_60 = sscanf ( V_55 , L_16 ,
& V_165 [ 0 ] , & V_165 [ 1 ] , & V_165 [ 2 ] ,
& V_165 [ 3 ] , & V_165 [ 4 ] , & V_165 [ 5 ] ,
& V_165 [ 6 ] , & V_165 [ 7 ] , V_143 ) ;
if ( V_60 != 9 ) {
V_25 = - V_61 ;
goto V_155;
}
}
if ( V_148 > 128 ) {
V_25 = - V_61 ;
goto V_155;
}
for ( V_60 = 0 ; V_60 < 8 ; V_60 ++ ) {
if ( V_165 [ V_60 ] > 0xffff ) {
V_25 = - V_61 ;
goto V_155;
}
V_142 . V_166 [ V_60 ] = F_81 ( V_165 [ V_60 ] ) ;
}
if ( V_143 [ 0 ] != '-' ) {
V_7 = F_14 ( V_143 , 0 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_155;
}
} else {
if ( strcmp ( V_143 , V_167 ) != 0 ) {
V_25 = - V_61 ;
goto V_155;
}
}
for ( V_60 = 0 , V_137 = V_148 ; V_60 < 8 ; V_60 ++ ) {
if ( V_137 >= 16 ) {
V_164 . V_166 [ V_60 ] = 0xffff ;
V_137 -= 16 ;
} else if ( V_137 > 0 ) {
V_164 . V_166 [ V_60 ] = ( 1 << V_137 ) - 1 ;
V_137 = 0 ;
} else
V_164 . V_166 [ V_60 ] = 0 ;
V_142 . V_166 [ V_60 ] &= V_164 . V_166 [ V_60 ] ;
}
F_7 ( & V_168 ) ;
F_8 (snp, &smk_net6addr_list, list) {
if ( V_148 != V_140 -> V_134 )
continue;
for ( V_24 = 1 , V_60 = 0 ; V_60 < 8 ; V_60 ++ ) {
if ( V_142 . V_166 [ V_60 ] !=
V_140 -> V_132 . V_166 [ V_60 ] ) {
V_24 = 0 ;
break;
}
}
if ( V_24 == 1 )
break;
}
if ( V_24 == 0 ) {
V_140 = F_9 ( sizeof( * V_140 ) , V_31 ) ;
if ( V_140 == NULL )
V_25 = - V_32 ;
else {
V_140 -> V_132 = V_142 ;
V_140 -> V_158 = V_164 ;
V_140 -> V_134 = V_148 ;
V_140 -> V_131 = V_7 ;
F_79 ( V_140 ) ;
}
} else {
V_140 -> V_131 = V_7 ;
}
if ( V_25 == 0 )
V_25 = V_64 ;
F_11 ( & V_168 ) ;
V_155:
F_19 ( V_143 ) ;
V_154:
F_19 ( V_55 ) ;
return V_25 ;
}
static T_1 F_82 ( struct V_62 * V_169 , char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char V_170 [ 80 ] ;
T_1 V_25 ;
if ( * V_65 != 0 )
return 0 ;
sprintf ( V_170 , L_9 , V_95 ) ;
V_25 = F_83 ( V_63 , V_64 , V_65 , V_170 , strlen ( V_170 ) ) ;
return V_25 ;
}
static T_1 F_84 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char V_170 [ 80 ] ;
int V_60 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
if ( V_64 >= sizeof( V_170 ) || V_64 == 0 )
return - V_61 ;
if ( F_85 ( V_170 , V_63 , V_64 ) != 0 )
return - V_171 ;
V_170 [ V_64 ] = '\0' ;
if ( sscanf ( V_170 , L_9 , & V_60 ) != 1 )
return - V_61 ;
V_95 = V_60 ;
F_42 () ;
return V_64 ;
}
static T_1 F_86 ( struct V_62 * V_169 , char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char V_170 [ 80 ] ;
T_1 V_25 ;
if ( * V_65 != 0 )
return 0 ;
sprintf ( V_170 , L_9 , V_172 ) ;
V_25 = F_83 ( V_63 , V_64 , V_65 , V_170 , strlen ( V_170 ) ) ;
return V_25 ;
}
static T_1 F_87 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
struct V_6 * V_7 ;
char V_170 [ 80 ] ;
int V_60 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
if ( V_64 >= sizeof( V_170 ) || V_64 == 0 )
return - V_61 ;
if ( F_85 ( V_170 , V_63 , V_64 ) != 0 )
return - V_171 ;
V_170 [ V_64 ] = '\0' ;
if ( sscanf ( V_170 , L_9 , & V_60 ) != 1 )
return - V_61 ;
if ( V_172 != V_60 ) {
F_7 ( & V_173 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_107 . V_108 . V_109 . V_111 ==
V_172 )
V_7 -> V_107 . V_108 . V_109 . V_111 = V_60 ;
V_172 = V_60 ;
F_11 ( & V_173 ) ;
}
return V_64 ;
}
static T_1 F_88 ( struct V_62 * V_169 , char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char V_170 [ 80 ] ;
T_1 V_25 ;
if ( * V_65 != 0 )
return 0 ;
sprintf ( V_170 , L_9 , V_174 ) ;
V_25 = F_83 ( V_63 , V_64 , V_65 , V_170 , strlen ( V_170 ) ) ;
return V_25 ;
}
static T_1 F_89 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
struct V_6 * V_7 ;
char V_170 [ 80 ] ;
int V_60 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
if ( V_64 >= sizeof( V_170 ) || V_64 == 0 )
return - V_61 ;
if ( F_85 ( V_170 , V_63 , V_64 ) != 0 )
return - V_171 ;
V_170 [ V_64 ] = '\0' ;
if ( sscanf ( V_170 , L_9 , & V_60 ) != 1 )
return - V_61 ;
if ( V_174 != V_60 ) {
F_7 ( & V_173 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_107 . V_108 . V_109 . V_111 ==
V_174 )
V_7 -> V_107 . V_108 . V_109 . V_111 = V_60 ;
V_174 = V_60 ;
F_11 ( & V_173 ) ;
}
return V_64 ;
}
static T_1 F_90 ( struct V_62 * V_169 , char T_2 * V_63 ,
T_3 V_175 , T_4 * V_65 )
{
T_1 V_25 ;
int V_176 ;
if ( * V_65 != 0 )
return 0 ;
F_7 ( & V_177 ) ;
V_176 = strlen ( V_102 -> V_81 ) + 1 ;
if ( V_175 >= V_176 )
V_25 = F_83 ( V_63 , V_175 , V_65 ,
V_102 -> V_81 ,
V_176 ) ;
else
V_25 = - V_61 ;
F_11 ( & V_177 ) ;
return V_25 ;
}
static T_1 F_91 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
struct V_6 * V_7 ;
char * V_101 ;
char * V_55 ;
int V_25 = V_64 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
V_55 = F_23 ( V_63 , V_64 ) ;
if ( F_15 ( V_55 ) )
return F_16 ( V_55 ) ;
V_7 = F_14 ( V_55 , V_64 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_33;
}
F_7 ( & V_177 ) ;
V_101 = V_102 -> V_81 ;
V_102 = V_7 ;
F_49 ( V_101 ) ;
F_11 ( & V_177 ) ;
V_33:
F_19 ( V_55 ) ;
return V_25 ;
}
static void * F_92 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_24 ( V_76 , V_77 , & V_178 ) ;
}
static void * F_93 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
return F_28 ( V_76 , V_79 , V_77 , & V_178 ) ;
}
static int F_94 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_179 * V_180 =
F_37 ( V_34 , struct V_179 , V_34 ) ;
F_95 ( V_76 , V_180 -> V_131 -> V_81 ) ;
F_33 ( V_76 , ' ' ) ;
return 0 ;
}
static int F_96 ( struct V_82 * V_82 , struct V_62 * V_62 )
{
return F_39 ( V_62 , & V_181 ) ;
}
static void F_97 ( struct V_15 * V_182 ,
struct V_15 * V_183 )
{
struct V_15 * V_184 , * V_185 ;
if ( F_68 ( V_182 ) ) {
F_98 ( V_183 , V_182 , V_186 ) ;
} else {
V_184 = V_182 -> V_139 ;
V_185 = V_182 -> V_187 ;
V_183 -> V_187 -> V_139 = V_182 ;
V_183 -> V_139 -> V_187 = V_182 ;
F_99 ( V_182 -> V_139 , V_183 -> V_139 ) ;
V_182 -> V_187 = V_183 -> V_187 ;
V_186 () ;
V_183 -> V_139 = V_184 ;
V_183 -> V_187 = V_185 ;
V_184 -> V_187 = V_183 ;
V_185 -> V_139 = V_183 ;
}
}
static int F_100 ( char * V_55 , struct V_15 * V_34 )
{
char * V_59 ;
struct V_6 * V_7 ;
struct V_179 * V_180 ;
while ( ( V_59 = F_101 ( & V_55 , L_17 ) ) != NULL ) {
if ( ! * V_59 )
continue;
V_7 = F_14 ( V_59 , 0 ) ;
if ( F_15 ( V_7 ) )
return F_16 ( V_7 ) ;
V_180 = F_9 ( sizeof( * V_180 ) , V_31 ) ;
if ( V_180 == NULL )
return - V_32 ;
V_180 -> V_131 = V_7 ;
F_102 ( & V_180 -> V_34 , V_34 ) ;
}
return 0 ;
}
void F_103 ( struct V_15 * V_34 )
{
struct V_179 * V_180 ;
struct V_179 * V_188 ;
F_104 (sklep, sklep2, list, list)
F_19 ( V_180 ) ;
F_105 ( V_34 ) ;
}
static T_1 F_106 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char * V_55 ;
F_107 ( V_189 ) ;
int V_25 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
V_55 = F_23 ( V_63 , V_64 ) ;
if ( F_15 ( V_55 ) )
return F_16 ( V_55 ) ;
V_25 = F_100 ( V_55 , & V_189 ) ;
F_19 ( V_55 ) ;
if ( ! V_25 || ( V_25 == - V_61 && F_68 ( & V_189 ) ) ) {
F_7 ( & V_190 ) ;
F_97 ( & V_178 , & V_189 ) ;
F_11 ( & V_190 ) ;
V_25 = V_64 ;
}
F_103 ( & V_189 ) ;
return V_25 ;
}
static T_1 F_108 ( struct V_62 * V_169 , char T_2 * V_63 ,
T_3 V_175 , T_4 * V_65 )
{
char * V_143 = L_18 ;
T_1 V_25 = - V_61 ;
int V_176 ;
if ( * V_65 != 0 )
return 0 ;
if ( V_191 != NULL )
V_143 = V_191 -> V_81 ;
V_176 = strlen ( V_143 ) + 1 ;
if ( V_175 >= V_176 )
V_25 = F_83 ( V_63 , V_175 , V_65 , V_143 , V_176 ) ;
return V_25 ;
}
static T_1 F_109 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char * V_55 ;
struct V_6 * V_7 ;
int V_25 = V_64 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
V_55 = F_23 ( V_63 , V_64 ) ;
if ( F_15 ( V_55 ) )
return F_16 ( V_55 ) ;
V_7 = F_14 ( V_55 , V_64 ) ;
if ( F_16 ( V_7 ) == - V_61 )
V_7 = NULL ;
else if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_192;
}
V_191 = V_7 ;
V_192:
F_19 ( V_55 ) ;
return V_25 ;
}
static T_1 F_110 ( struct V_62 * V_169 , char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char V_170 [ 32 ] ;
T_1 V_25 ;
if ( * V_65 != 0 )
return 0 ;
sprintf ( V_170 , L_19 , V_193 ) ;
V_25 = F_83 ( V_63 , V_64 , V_65 , V_170 , strlen ( V_170 ) ) ;
return V_25 ;
}
static T_1 F_111 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char V_170 [ 32 ] ;
int V_60 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
if ( V_64 >= sizeof( V_170 ) || V_64 == 0 )
return - V_61 ;
if ( F_85 ( V_170 , V_63 , V_64 ) != 0 )
return - V_171 ;
V_170 [ V_64 ] = '\0' ;
if ( sscanf ( V_170 , L_9 , & V_60 ) != 1 )
return - V_61 ;
if ( V_60 < 0 || V_60 > 3 )
return - V_61 ;
V_193 = V_60 ;
return V_64 ;
}
static void * F_112 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_194 * V_195 = F_113 () ;
return F_24 ( V_76 , V_77 , & V_195 -> V_73 ) ;
}
static void * F_114 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
struct V_194 * V_195 = F_113 () ;
return F_28 ( V_76 , V_79 , V_77 , & V_195 -> V_73 ) ;
}
static int F_115 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_20 * V_14 =
F_37 ( V_34 , struct V_20 , V_34 ) ;
F_31 ( V_76 , V_14 , V_56 ) ;
return 0 ;
}
static int F_116 ( struct V_82 * V_82 , struct V_62 * V_62 )
{
return F_39 ( V_62 , & V_196 ) ;
}
static T_1 F_117 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
struct V_194 * V_195 = F_113 () ;
return F_22 ( V_62 , V_63 , V_64 , V_65 , & V_195 -> V_73 ,
& V_195 -> V_74 , V_68 ) ;
}
static T_1 F_118 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 , int V_66 )
{
struct V_13 V_51 ;
char * V_55 ;
int V_197 ;
V_55 = F_119 ( V_62 , V_63 , V_64 ) ;
if ( F_15 ( V_55 ) )
return F_16 ( V_55 ) ;
if ( V_66 == V_68 ) {
if ( V_64 < V_70 )
return - V_61 ;
V_197 = F_20 ( V_55 , & V_51 , 0 ) ;
} else {
V_197 = F_21 ( V_55 , & V_51 , 0 , 3 ) ;
}
if ( V_197 >= 0 )
V_197 = V_28 ( V_51 . V_27 , V_51 . V_26 ,
V_51 . V_29 , NULL ) ;
else if ( V_197 != - V_54 )
return V_197 ;
V_55 [ 0 ] = V_197 >= 0 ? '1' : '0' ;
V_55 [ 1 ] = '\0' ;
F_120 ( V_62 , 2 ) ;
if ( V_66 == V_68 )
return V_70 ;
return V_64 ;
}
static T_1 F_121 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
return F_118 ( V_62 , V_63 , V_64 , V_65 , V_68 ) ;
}
static int F_122 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_22 * V_23 =
F_37 ( V_34 , struct V_22 , V_34 ) ;
F_31 ( V_76 , V_23 -> V_35 , V_198 ) ;
return 0 ;
}
static int F_123 ( struct V_82 * V_82 , struct V_62 * V_62 )
{
return F_39 ( V_62 , & V_199 ) ;
}
static T_1 F_124 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
if ( ! F_41 ( V_84 ) )
return - V_85 ;
return F_22 ( V_62 , V_63 , V_64 , V_65 , NULL , NULL ,
V_126 ) ;
}
static void * F_125 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_194 * V_195 = F_113 () ;
return F_24 ( V_76 , V_77 , & V_195 -> V_73 ) ;
}
static void * F_126 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
struct V_194 * V_195 = F_113 () ;
return F_28 ( V_76 , V_79 , V_77 , & V_195 -> V_73 ) ;
}
static int F_127 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_20 * V_14 =
F_37 ( V_34 , struct V_20 , V_34 ) ;
F_31 ( V_76 , V_14 , V_198 ) ;
return 0 ;
}
static int F_128 ( struct V_82 * V_82 , struct V_62 * V_62 )
{
return F_39 ( V_62 , & V_200 ) ;
}
static T_1 F_129 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
struct V_194 * V_195 = F_113 () ;
return F_22 ( V_62 , V_63 , V_64 , V_65 , & V_195 -> V_73 ,
& V_195 -> V_74 , V_126 ) ;
}
static T_1 F_130 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
return F_118 ( V_62 , V_63 , V_64 , V_65 , V_126 ) ;
}
static T_1 F_131 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char * V_55 ;
const char * V_39 ;
struct V_6 * V_7 ;
struct V_20 * V_21 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_25 = V_64 ;
if ( * V_65 != 0 )
return - V_61 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
if ( V_64 == 0 || V_64 > V_198 )
return - V_61 ;
V_55 = F_132 ( V_63 , V_64 ) ;
if ( F_15 ( V_55 ) )
return F_16 ( V_55 ) ;
V_39 = F_17 ( V_55 , V_64 ) ;
if ( F_15 ( V_39 ) ) {
V_25 = F_16 ( V_39 ) ;
goto V_201;
}
V_7 = F_18 ( V_39 ) ;
if ( V_7 == NULL )
goto V_202;
V_16 = & V_7 -> V_73 ;
V_18 = & V_7 -> V_74 ;
F_7 ( V_18 ) ;
F_8 (sp, rule_list, list)
V_21 -> V_28 = 0 ;
F_11 ( V_18 ) ;
V_202:
F_19 ( V_39 ) ;
V_201:
F_19 ( V_55 ) ;
return V_25 ;
}
static int F_133 ( void )
{
return F_134 ( V_203 , L_20 ) ;
}
static T_1 F_135 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
if ( ! F_41 ( V_84 ) )
return - V_85 ;
return F_22 ( V_62 , V_63 , V_64 , V_65 , NULL , NULL ,
V_72 ) ;
}
static T_1 F_136 ( struct V_62 * V_169 , char T_2 * V_63 ,
T_3 V_175 , T_4 * V_65 )
{
struct V_6 * V_7 ;
T_1 V_25 = - V_61 ;
int V_176 ;
if ( * V_65 != 0 )
return 0 ;
if ( V_204 == NULL )
V_7 = & V_205 ;
else
V_7 = V_204 ;
V_176 = strlen ( V_7 -> V_81 ) + 1 ;
if ( V_175 >= V_176 )
V_25 = F_83 ( V_63 , V_175 , V_65 , V_7 -> V_81 ,
V_176 ) ;
return V_25 ;
}
static T_1 F_137 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char * V_55 ;
struct V_6 * V_7 ;
int V_25 = V_64 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
V_55 = F_23 ( V_63 , V_64 ) ;
if ( F_15 ( V_55 ) )
return F_16 ( V_55 ) ;
V_7 = F_14 ( V_55 , V_64 ) ;
if ( F_15 ( V_7 ) )
V_25 = F_16 ( V_7 ) ;
else
V_204 = V_7 ;
F_19 ( V_55 ) ;
return V_25 ;
}
static void * F_138 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_194 * V_195 = F_113 () ;
return F_24 ( V_76 , V_77 , & V_195 -> V_206 ) ;
}
static void * F_139 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
struct V_194 * V_195 = F_113 () ;
return F_28 ( V_76 , V_79 , V_77 , & V_195 -> V_206 ) ;
}
static int F_140 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_179 * V_180 =
F_77 ( V_34 , struct V_179 , V_34 ) ;
F_95 ( V_76 , V_180 -> V_131 -> V_81 ) ;
F_33 ( V_76 , ' ' ) ;
return 0 ;
}
static int F_141 ( struct V_82 * V_82 , struct V_62 * V_62 )
{
return F_39 ( V_62 , & V_207 ) ;
}
static T_1 F_142 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
struct V_194 * V_195 = F_113 () ;
char * V_55 ;
int V_25 ;
F_107 ( V_189 ) ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
if ( * V_65 != 0 )
return - V_61 ;
V_55 = F_23 ( V_63 , V_64 ) ;
if ( F_15 ( V_55 ) )
return F_16 ( V_55 ) ;
V_25 = F_100 ( V_55 , & V_189 ) ;
F_19 ( V_55 ) ;
if ( ! V_25 || ( V_25 == - V_61 && F_68 ( & V_189 ) ) ) {
F_103 ( & V_195 -> V_206 ) ;
F_143 ( & V_189 , & V_195 -> V_206 ) ;
return V_64 ;
}
F_103 ( & V_189 ) ;
return V_25 ;
}
static T_1 F_144 ( struct V_62 * V_169 , char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char V_170 [ 32 ] ;
T_1 V_25 ;
if ( * V_65 != 0 )
return 0 ;
sprintf ( V_170 , L_19 , V_208 ) ;
V_25 = F_83 ( V_63 , V_64 , V_65 , V_170 , strlen ( V_170 ) ) ;
return V_25 ;
}
static T_1 F_145 ( struct V_62 * V_62 , const char T_2 * V_63 ,
T_3 V_64 , T_4 * V_65 )
{
char V_170 [ 32 ] ;
int V_60 ;
if ( ! F_41 ( V_84 ) )
return - V_85 ;
if ( * V_65 != 0 || V_64 >= sizeof( V_170 ) || V_64 == 0 )
return - V_61 ;
if ( F_85 ( V_170 , V_63 , V_64 ) != 0 )
return - V_171 ;
V_170 [ V_64 ] = '\0' ;
if ( sscanf ( V_170 , L_9 , & V_60 ) != 1 )
return - V_61 ;
if ( V_60 < V_209 || V_60 > V_210 )
return - V_61 ;
V_208 = V_60 ;
return V_64 ;
}
static int F_146 ( struct V_211 * V_212 , void * V_55 , int V_213 )
{
int V_25 ;
struct V_82 * V_214 ;
static const struct V_215 V_216 [] = {
[ V_217 ] = {
L_21 , & V_218 , V_219 | V_220 } ,
[ V_221 ] = {
L_22 , & V_222 , V_219 | V_220 } ,
[ V_223 ] = {
L_23 , & V_224 , V_219 | V_220 } ,
[ V_225 ] = {
L_24 , & V_226 , V_219 | V_220 } ,
[ V_227 ] = {
L_25 , & V_228 , V_219 | V_220 } ,
[ V_229 ] = {
L_26 , & V_230 , V_219 | V_220 } ,
[ V_231 ] = {
L_27 , & V_232 , V_219 | V_220 } ,
[ V_233 ] = {
L_28 , & V_234 , V_219 | V_220 } ,
[ V_235 ] = {
L_29 , & V_236 , V_219 | V_237 } ,
[ V_238 ] = {
L_30 , & V_239 , V_219 | V_237 } ,
[ V_240 ] = {
L_31 , & V_241 , V_219 | V_220 } ,
[ V_242 ] = {
L_32 , & V_243 , V_219 | V_220 } ,
[ V_244 ] = {
L_33 , & V_245 , V_219 | V_237 } ,
[ V_246 ] = {
L_34 , & V_247 , V_219 | V_237 } ,
[ V_248 ] = {
L_35 , & V_249 , V_219 | V_220 } ,
[ V_250 ] = {
L_36 , & V_251 ,
V_219 | V_220 } ,
[ V_252 ] = {
L_37 , & V_253 , V_219 | V_220 } ,
[ V_254 ] = {
L_38 , & V_255 , V_219 | V_220 } ,
[ V_256 ] = {
L_39 , & V_257 , V_219 | V_220 } ,
#ifdef F_147
[ V_258 ] = {
L_40 , & V_259 , V_219 | V_220 } ,
#endif
#if F_148 ( V_260 )
[ V_261 ] = {
L_41 , & V_262 , V_219 | V_220 } ,
#endif
[ V_263 ] = {
L_42 , & V_264 ,
V_219 | V_237 } ,
{ L_18 }
} ;
V_25 = F_149 ( V_212 , V_265 , V_216 ) ;
if ( V_25 != 0 ) {
F_44 ( V_266 L_43 ,
V_91 , V_25 ) ;
return V_25 ;
}
V_214 = F_150 ( V_212 -> V_267 ) ;
return 0 ;
}
static struct V_268 * F_151 ( struct V_269 * V_270 ,
int V_271 , const char * V_272 , void * V_55 )
{
return F_152 ( V_270 , V_271 , V_55 , F_146 ) ;
}
static int T_7 F_153 ( struct V_6 * V_7 )
{
V_7 -> V_107 . V_273 = V_7 -> V_81 ;
V_7 -> V_107 . V_271 =
V_274 | V_275 ;
return F_57 ( V_172 , V_7 -> V_81 ,
& V_7 -> V_107 , strlen ( V_7 -> V_81 ) ) ;
}
static int T_7 F_154 ( void )
{
int V_276 ;
int V_25 ;
if ( V_277 == 0 )
return 0 ;
V_276 = F_133 () ;
if ( V_276 )
F_44 ( V_266 L_44 ) ;
V_276 = F_155 ( & V_278 ) ;
if ( ! V_276 ) {
V_279 = F_156 ( & V_278 ) ;
if ( F_15 ( V_279 ) ) {
F_44 ( V_266 L_45 ) ;
V_276 = F_16 ( V_279 ) ;
V_279 = NULL ;
}
}
F_42 () ;
F_49 ( NULL ) ;
V_25 = F_153 ( & V_103 ) ;
if ( V_276 == 0 && V_25 < 0 )
V_276 = V_25 ;
V_25 = F_153 ( & V_280 ) ;
if ( V_276 == 0 && V_25 < 0 )
V_276 = V_25 ;
V_25 = F_153 ( & V_281 ) ;
if ( V_276 == 0 && V_25 < 0 )
V_276 = V_25 ;
V_25 = F_153 ( & V_205 ) ;
if ( V_276 == 0 && V_25 < 0 )
V_276 = V_25 ;
V_25 = F_153 ( & V_282 ) ;
if ( V_276 == 0 && V_25 < 0 )
V_276 = V_25 ;
return V_276 ;
}
