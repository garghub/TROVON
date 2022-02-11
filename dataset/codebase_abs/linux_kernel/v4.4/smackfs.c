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
char * V_130 = V_131 ;
if ( V_7 -> V_132 != NULL )
V_130 = V_7 -> V_132 -> V_81 ;
F_33 ( V_76 , L_11 , & V_7 -> V_133 . V_134 ,
V_7 -> V_135 , V_130 ) ;
return 0 ;
}
static int F_66 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_136 ) ;
}
static void F_67 ( struct V_129 * V_137 )
{
struct V_129 * V_138 ;
struct V_129 * V_139 ;
if ( F_68 ( & V_128 ) ) {
F_10 ( & V_137 -> V_34 , & V_128 ) ;
return;
}
V_138 = F_38 ( V_128 . V_140 ,
struct V_129 , V_34 ) ;
if ( V_137 -> V_135 > V_138 -> V_135 ) {
F_10 ( & V_137 -> V_34 , & V_128 ) ;
return;
}
F_8 (m, &smk_net4addr_list, list) {
if ( F_69 ( & V_138 -> V_34 , & V_128 ) ) {
F_10 ( & V_137 -> V_34 , & V_138 -> V_34 ) ;
return;
}
V_139 = F_38 ( V_138 -> V_34 . V_140 ,
struct V_129 , V_34 ) ;
if ( V_137 -> V_135 > V_139 -> V_135 ) {
F_10 ( & V_137 -> V_34 , & V_138 -> V_34 ) ;
return;
}
}
}
static T_1 F_70 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_129 * V_141 ;
struct V_142 V_143 ;
char * V_144 ;
struct V_6 * V_7 = NULL ;
char * V_54 ;
char * V_145 = ( char * ) & V_143 . V_146 . V_134 ;
int V_25 ;
struct V_4 V_147 ;
struct V_148 V_149 ;
unsigned int V_138 ;
unsigned int V_150 ;
int V_24 ;
T_5 V_151 = ( 1 << 31 ) ;
T_6 V_152 ;
T_5 V_153 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( * V_64 != 0 )
return - V_60 ;
if ( V_63 < V_154 )
return - V_60 ;
V_54 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_155;
}
V_144 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_144 == NULL ) {
V_25 = - V_32 ;
goto V_155;
}
V_54 [ V_63 ] = '\0' ;
V_25 = sscanf ( V_54 , L_12 ,
& V_145 [ 0 ] , & V_145 [ 1 ] , & V_145 [ 2 ] , & V_145 [ 3 ] , & V_150 , V_144 ) ;
if ( V_25 != 6 ) {
V_25 = sscanf ( V_54 , L_13 ,
& V_145 [ 0 ] , & V_145 [ 1 ] , & V_145 [ 2 ] , & V_145 [ 3 ] , V_144 ) ;
if ( V_25 != 5 ) {
V_25 = - V_60 ;
goto V_156;
}
V_138 = V_157 ;
V_150 = 32 ;
}
if ( V_150 > V_157 ) {
V_25 = - V_60 ;
goto V_156;
}
if ( V_144 [ 0 ] != '-' ) {
V_7 = F_14 ( V_144 , 0 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_156;
}
} else {
if ( strcmp ( V_144 , V_131 ) != 0 ) {
V_25 = - V_60 ;
goto V_156;
}
}
for ( V_138 = V_150 , V_153 = 0 ; V_138 > 0 ; V_138 -- ) {
V_153 |= V_151 ;
V_151 >>= 1 ;
}
V_149 . V_134 = F_71 ( V_153 ) ;
V_143 . V_146 . V_134 &= V_149 . V_134 ;
F_7 ( & V_158 ) ;
V_152 = V_143 . V_146 . V_134 ;
V_24 = 0 ;
F_8 (snp, &smk_net4addr_list, list) {
if ( V_141 -> V_133 . V_134 == V_152 && V_141 -> V_135 == V_150 ) {
V_24 = 1 ;
break;
}
}
F_2 ( & V_147 ) ;
if ( V_24 == 0 ) {
V_141 = F_9 ( sizeof( * V_141 ) , V_31 ) ;
if ( V_141 == NULL )
V_25 = - V_32 ;
else {
V_25 = 0 ;
V_141 -> V_133 . V_134 = V_143 . V_146 . V_134 ;
V_141 -> V_159 . V_134 = V_149 . V_134 ;
V_141 -> V_132 = V_7 ;
V_141 -> V_135 = V_150 ;
F_67 ( V_141 ) ;
}
} else {
if ( V_141 -> V_132 != NULL )
V_25 = F_72 ( & V_160 , NULL ,
& V_141 -> V_133 , & V_141 -> V_159 ,
V_89 , & V_147 ) ;
else
V_25 = 0 ;
V_141 -> V_132 = V_7 ;
}
if ( V_25 == 0 && V_7 != NULL )
V_25 = F_73 ( & V_160 , NULL ,
& V_141 -> V_133 , & V_141 -> V_159 , V_89 ,
V_141 -> V_132 -> V_12 , & V_147 ) ;
if ( V_25 == 0 )
V_25 = V_63 ;
F_11 ( & V_158 ) ;
V_156:
F_19 ( V_144 ) ;
V_155:
F_19 ( V_54 ) ;
return V_25 ;
}
static void * F_74 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_25 ( V_76 , V_77 , & V_161 ) ;
}
static void * F_75 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
return F_29 ( V_76 , V_79 , V_77 , & V_161 ) ;
}
static int F_76 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_162 * V_7 =
F_77 ( V_34 , struct V_162 , V_34 ) ;
if ( V_7 -> V_132 != NULL )
F_33 ( V_76 , L_14 , & V_7 -> V_133 , V_7 -> V_135 ,
V_7 -> V_132 -> V_81 ) ;
return 0 ;
}
static int F_78 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_163 ) ;
}
static void F_79 ( struct V_162 * V_137 )
{
struct V_162 * V_139 ;
struct V_162 * V_138 ;
if ( F_68 ( & V_161 ) ) {
F_10 ( & V_137 -> V_34 , & V_161 ) ;
return;
}
V_138 = F_38 ( V_161 . V_140 ,
struct V_162 , V_34 ) ;
if ( V_137 -> V_135 > V_138 -> V_135 ) {
F_10 ( & V_137 -> V_34 , & V_161 ) ;
return;
}
F_8 (m, &smk_net6addr_list, list) {
if ( F_69 ( & V_138 -> V_34 , & V_161 ) ) {
F_10 ( & V_137 -> V_34 , & V_138 -> V_34 ) ;
return;
}
V_139 = F_38 ( V_138 -> V_34 . V_140 ,
struct V_162 , V_34 ) ;
if ( V_137 -> V_135 > V_139 -> V_135 ) {
F_10 ( & V_137 -> V_34 , & V_138 -> V_34 ) ;
return;
}
}
}
static T_1 F_80 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_162 * V_141 ;
struct V_164 V_143 ;
struct V_164 V_165 ;
struct V_6 * V_7 = NULL ;
char * V_144 ;
char * V_54 ;
int V_25 = 0 ;
int V_24 = 0 ;
int V_59 ;
unsigned int V_166 [ 8 ] ;
unsigned int V_138 ;
unsigned int V_149 = 128 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( * V_64 != 0 )
return - V_60 ;
if ( V_63 < V_154 )
return - V_60 ;
V_54 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_155;
}
V_144 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_144 == NULL ) {
V_25 = - V_32 ;
goto V_155;
}
V_54 [ V_63 ] = '\0' ;
V_59 = sscanf ( V_54 , L_15 ,
& V_166 [ 0 ] , & V_166 [ 1 ] , & V_166 [ 2 ] , & V_166 [ 3 ] ,
& V_166 [ 4 ] , & V_166 [ 5 ] , & V_166 [ 6 ] , & V_166 [ 7 ] ,
& V_149 , V_144 ) ;
if ( V_59 != 10 ) {
V_59 = sscanf ( V_54 , L_16 ,
& V_166 [ 0 ] , & V_166 [ 1 ] , & V_166 [ 2 ] ,
& V_166 [ 3 ] , & V_166 [ 4 ] , & V_166 [ 5 ] ,
& V_166 [ 6 ] , & V_166 [ 7 ] , V_144 ) ;
if ( V_59 != 9 ) {
V_25 = - V_60 ;
goto V_156;
}
}
if ( V_149 > 128 ) {
V_25 = - V_60 ;
goto V_156;
}
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
if ( V_166 [ V_59 ] > 0xffff ) {
V_25 = - V_60 ;
goto V_156;
}
V_143 . V_167 [ V_59 ] = F_81 ( V_166 [ V_59 ] ) ;
}
if ( V_144 [ 0 ] != '-' ) {
V_7 = F_14 ( V_144 , 0 ) ;
if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_156;
}
} else {
if ( strcmp ( V_144 , V_168 ) != 0 ) {
V_25 = - V_60 ;
goto V_156;
}
}
for ( V_59 = 0 , V_138 = V_149 ; V_59 < 8 ; V_59 ++ ) {
if ( V_138 >= 16 ) {
V_165 . V_167 [ V_59 ] = 0xffff ;
V_138 -= 16 ;
} else if ( V_138 > 0 ) {
V_165 . V_167 [ V_59 ] = ( 1 << V_138 ) - 1 ;
V_138 = 0 ;
} else
V_165 . V_167 [ V_59 ] = 0 ;
V_143 . V_167 [ V_59 ] &= V_165 . V_167 [ V_59 ] ;
}
F_7 ( & V_169 ) ;
F_8 (snp, &smk_net6addr_list, list) {
if ( V_149 != V_141 -> V_135 )
continue;
for ( V_24 = 1 , V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
if ( V_143 . V_167 [ V_59 ] !=
V_141 -> V_133 . V_167 [ V_59 ] ) {
V_24 = 0 ;
break;
}
}
if ( V_24 == 1 )
break;
}
if ( V_24 == 0 ) {
V_141 = F_9 ( sizeof( * V_141 ) , V_31 ) ;
if ( V_141 == NULL )
V_25 = - V_32 ;
else {
V_141 -> V_133 = V_143 ;
V_141 -> V_159 = V_165 ;
V_141 -> V_135 = V_149 ;
V_141 -> V_132 = V_7 ;
F_79 ( V_141 ) ;
}
} else {
V_141 -> V_132 = V_7 ;
}
if ( V_25 == 0 )
V_25 = V_63 ;
F_11 ( & V_169 ) ;
V_156:
F_19 ( V_144 ) ;
V_155:
F_19 ( V_54 ) ;
return V_25 ;
}
static T_1 F_82 ( struct V_61 * V_170 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_171 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_171 , L_9 , V_95 ) ;
V_25 = F_83 ( V_62 , V_63 , V_64 , V_171 , strlen ( V_171 ) ) ;
return V_25 ;
}
static T_1 F_84 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_171 [ 80 ] ;
int V_59 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( V_63 >= sizeof( V_171 ) || V_63 == 0 )
return - V_60 ;
if ( F_24 ( V_171 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_171 [ V_63 ] = '\0' ;
if ( sscanf ( V_171 , L_9 , & V_59 ) != 1 )
return - V_60 ;
V_95 = V_59 ;
F_43 () ;
return V_63 ;
}
static T_1 F_85 ( struct V_61 * V_170 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_171 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_171 , L_9 , V_172 ) ;
V_25 = F_83 ( V_62 , V_63 , V_64 , V_171 , strlen ( V_171 ) ) ;
return V_25 ;
}
static T_1 F_86 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char V_171 [ 80 ] ;
int V_59 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( V_63 >= sizeof( V_171 ) || V_63 == 0 )
return - V_60 ;
if ( F_24 ( V_171 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_171 [ V_63 ] = '\0' ;
if ( sscanf ( V_171 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_172 != V_59 ) {
F_7 ( & V_173 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_107 . V_108 . V_109 . V_111 ==
V_172 )
V_7 -> V_107 . V_108 . V_109 . V_111 = V_59 ;
V_172 = V_59 ;
F_11 ( & V_173 ) ;
}
return V_63 ;
}
static T_1 F_87 ( struct V_61 * V_170 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_171 [ 80 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_171 , L_9 , V_174 ) ;
V_25 = F_83 ( V_62 , V_63 , V_64 , V_171 , strlen ( V_171 ) ) ;
return V_25 ;
}
static T_1 F_88 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_6 * V_7 ;
char V_171 [ 80 ] ;
int V_59 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( V_63 >= sizeof( V_171 ) || V_63 == 0 )
return - V_60 ;
if ( F_24 ( V_171 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_171 [ V_63 ] = '\0' ;
if ( sscanf ( V_171 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_174 != V_59 ) {
F_7 ( & V_173 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_107 . V_108 . V_109 . V_111 ==
V_174 )
V_7 -> V_107 . V_108 . V_109 . V_111 = V_59 ;
V_174 = V_59 ;
F_11 ( & V_173 ) ;
}
return V_63 ;
}
static T_1 F_89 ( struct V_61 * V_170 , char T_2 * V_62 ,
T_3 V_175 , T_4 * V_64 )
{
T_1 V_25 ;
int V_176 ;
if ( * V_64 != 0 )
return 0 ;
F_7 ( & V_177 ) ;
V_176 = strlen ( V_102 -> V_81 ) + 1 ;
if ( V_175 >= V_176 )
V_25 = F_83 ( V_62 , V_175 , V_64 ,
V_102 -> V_81 ,
V_176 ) ;
else
V_25 = - V_60 ;
F_11 ( & V_177 ) ;
return V_25 ;
}
static T_1 F_90 ( struct V_61 * V_61 , const char T_2 * V_62 ,
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
F_7 ( & V_177 ) ;
V_101 = V_102 -> V_81 ;
V_102 = V_7 ;
F_49 ( V_101 ) ;
F_11 ( & V_177 ) ;
V_33:
F_19 ( V_54 ) ;
return V_25 ;
}
static void * F_91 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_25 ( V_76 , V_77 , & V_178 ) ;
}
static void * F_92 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
return F_29 ( V_76 , V_79 , V_77 , & V_178 ) ;
}
static int F_93 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_179 * V_180 =
F_38 ( V_34 , struct V_179 , V_34 ) ;
F_94 ( V_76 , V_180 -> V_132 -> V_81 ) ;
F_34 ( V_76 , ' ' ) ;
return 0 ;
}
static int F_95 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_181 ) ;
}
static void F_96 ( struct V_15 * V_182 ,
struct V_15 * V_183 )
{
struct V_15 * V_184 , * V_185 ;
if ( F_68 ( V_182 ) ) {
F_97 ( V_183 , V_182 , V_186 ) ;
} else {
V_184 = V_182 -> V_140 ;
V_185 = V_182 -> V_187 ;
V_183 -> V_187 -> V_140 = V_182 ;
V_183 -> V_140 -> V_187 = V_182 ;
F_98 ( V_182 -> V_140 , V_183 -> V_140 ) ;
V_182 -> V_187 = V_183 -> V_187 ;
V_186 () ;
V_183 -> V_140 = V_184 ;
V_183 -> V_187 = V_185 ;
V_184 -> V_187 = V_183 ;
V_185 -> V_140 = V_183 ;
}
}
static int F_99 ( char * V_54 , struct V_15 * V_34 )
{
char * V_58 ;
struct V_6 * V_7 ;
struct V_179 * V_180 ;
while ( ( V_58 = F_100 ( & V_54 , L_17 ) ) != NULL ) {
if ( ! * V_58 )
continue;
V_7 = F_14 ( V_58 , 0 ) ;
if ( F_15 ( V_7 ) )
return F_16 ( V_7 ) ;
V_180 = F_9 ( sizeof( * V_180 ) , V_31 ) ;
if ( V_180 == NULL )
return - V_32 ;
V_180 -> V_132 = V_7 ;
F_101 ( & V_180 -> V_34 , V_34 ) ;
}
return 0 ;
}
void F_102 ( struct V_15 * V_34 )
{
struct V_179 * V_180 ;
struct V_179 * V_188 ;
F_103 (sklep, sklep2, list, list)
F_19 ( V_180 ) ;
F_104 ( V_34 ) ;
}
static T_1 F_105 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char * V_54 ;
F_106 ( V_189 ) ;
int V_25 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
V_54 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
F_19 ( V_54 ) ;
return - V_71 ;
}
V_25 = F_99 ( V_54 , & V_189 ) ;
F_19 ( V_54 ) ;
if ( ! V_25 || ( V_25 == - V_60 && F_68 ( & V_189 ) ) ) {
F_7 ( & V_190 ) ;
F_96 ( & V_178 , & V_189 ) ;
F_11 ( & V_190 ) ;
V_25 = V_63 ;
}
F_102 ( & V_189 ) ;
return V_25 ;
}
static T_1 F_107 ( struct V_61 * V_170 , char T_2 * V_62 ,
T_3 V_175 , T_4 * V_64 )
{
char * V_144 = L_18 ;
T_1 V_25 = - V_60 ;
int V_176 ;
if ( * V_64 != 0 )
return 0 ;
if ( V_191 != NULL )
V_144 = V_191 -> V_81 ;
V_176 = strlen ( V_144 ) + 1 ;
if ( V_175 >= V_176 )
V_25 = F_83 ( V_62 , V_175 , V_64 , V_144 , V_176 ) ;
return V_25 ;
}
static T_1 F_108 ( struct V_61 * V_61 , const char T_2 * V_62 ,
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
goto V_192;
}
V_7 = F_14 ( V_54 , V_63 ) ;
if ( F_16 ( V_7 ) == - V_60 )
V_7 = NULL ;
else if ( F_15 ( V_7 ) ) {
V_25 = F_16 ( V_7 ) ;
goto V_192;
}
V_191 = V_7 ;
V_192:
F_19 ( V_54 ) ;
return V_25 ;
}
static T_1 F_109 ( struct V_61 * V_170 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_171 [ 32 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_171 , L_19 , V_193 ) ;
V_25 = F_83 ( V_62 , V_63 , V_64 , V_171 , strlen ( V_171 ) ) ;
return V_25 ;
}
static T_1 F_110 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_171 [ 32 ] ;
int V_59 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( V_63 >= sizeof( V_171 ) || V_63 == 0 )
return - V_60 ;
if ( F_24 ( V_171 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_171 [ V_63 ] = '\0' ;
if ( sscanf ( V_171 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_59 < 0 || V_59 > 3 )
return - V_60 ;
V_193 = V_59 ;
return V_63 ;
}
static void * F_111 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_194 * V_195 = F_112 () ;
return F_25 ( V_76 , V_77 , & V_195 -> V_73 ) ;
}
static void * F_113 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
struct V_194 * V_195 = F_112 () ;
return F_29 ( V_76 , V_79 , V_77 , & V_195 -> V_73 ) ;
}
static int F_114 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_20 * V_14 =
F_38 ( V_34 , struct V_20 , V_34 ) ;
F_32 ( V_76 , V_14 , V_55 ) ;
return 0 ;
}
static int F_115 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_196 ) ;
}
static T_1 F_116 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_194 * V_195 = F_112 () ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , & V_195 -> V_73 ,
& V_195 -> V_74 , V_67 ) ;
}
static T_1 F_117 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 , int V_65 )
{
struct V_13 V_50 ;
char * V_54 ;
int V_197 ;
V_54 = F_118 ( V_61 , V_62 , V_63 ) ;
if ( F_15 ( V_54 ) )
return F_16 ( V_54 ) ;
if ( V_65 == V_67 ) {
if ( V_63 < V_69 )
return - V_60 ;
V_197 = F_20 ( V_54 , & V_50 , 0 ) ;
} else {
V_197 = F_21 ( V_54 , & V_50 , 0 , 3 ) ;
}
if ( V_197 >= 0 )
V_197 = V_28 ( V_50 . V_27 , V_50 . V_26 ,
V_50 . V_29 , NULL ) ;
else if ( V_197 != - V_53 )
return V_197 ;
V_54 [ 0 ] = V_197 >= 0 ? '1' : '0' ;
V_54 [ 1 ] = '\0' ;
F_119 ( V_61 , 2 ) ;
if ( V_65 == V_67 )
return V_69 ;
return V_63 ;
}
static T_1 F_120 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_117 ( V_61 , V_62 , V_63 , V_64 , V_67 ) ;
}
static int F_121 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_22 * V_23 =
F_38 ( V_34 , struct V_22 , V_34 ) ;
F_32 ( V_76 , V_23 -> V_35 , V_198 ) ;
return 0 ;
}
static int F_122 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_199 ) ;
}
static T_1 F_123 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_42 ( V_84 ) )
return - V_85 ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_127 ) ;
}
static void * F_124 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_194 * V_195 = F_112 () ;
return F_25 ( V_76 , V_77 , & V_195 -> V_73 ) ;
}
static void * F_125 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
struct V_194 * V_195 = F_112 () ;
return F_29 ( V_76 , V_79 , V_77 , & V_195 -> V_73 ) ;
}
static int F_126 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_20 * V_14 =
F_38 ( V_34 , struct V_20 , V_34 ) ;
F_32 ( V_76 , V_14 , V_198 ) ;
return 0 ;
}
static int F_127 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_200 ) ;
}
static T_1 F_128 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_194 * V_195 = F_112 () ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , & V_195 -> V_73 ,
& V_195 -> V_74 , V_127 ) ;
}
static T_1 F_129 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
return F_117 ( V_61 , V_62 , V_63 , V_64 , V_127 ) ;
}
static T_1 F_130 ( struct V_61 * V_61 , const char T_2 * V_62 ,
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
if ( V_63 == 0 || V_63 > V_198 )
return - V_60 ;
V_54 = F_9 ( V_63 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
V_25 = - V_71 ;
goto V_201;
}
V_38 = F_17 ( V_54 , V_63 ) ;
if ( F_15 ( V_38 ) ) {
V_25 = F_16 ( V_38 ) ;
goto V_201;
}
V_7 = F_18 ( V_38 ) ;
if ( V_7 == NULL )
goto V_202;
V_16 = & V_7 -> V_73 ;
V_18 = & V_7 -> V_74 ;
F_7 ( V_18 ) ;
F_8 (sp, rule_list, list)
V_21 -> V_28 = 0 ;
F_11 ( V_18 ) ;
V_202:
F_19 ( V_38 ) ;
V_201:
F_19 ( V_54 ) ;
return V_25 ;
}
static int F_131 ( void )
{
return F_132 ( V_203 , L_20 ) ;
}
static T_1 F_133 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
if ( ! F_42 ( V_84 ) )
return - V_85 ;
return F_22 ( V_61 , V_62 , V_63 , V_64 , NULL , NULL ,
V_72 ) ;
}
static T_1 F_134 ( struct V_61 * V_170 , char T_2 * V_62 ,
T_3 V_175 , T_4 * V_64 )
{
struct V_6 * V_7 ;
T_1 V_25 = - V_60 ;
int V_176 ;
if ( * V_64 != 0 )
return 0 ;
if ( V_204 == NULL )
V_7 = & V_205 ;
else
V_7 = V_204 ;
V_176 = strlen ( V_7 -> V_81 ) + 1 ;
if ( V_175 >= V_176 )
V_25 = F_83 ( V_62 , V_175 , V_64 , V_7 -> V_81 ,
V_176 ) ;
return V_25 ;
}
static T_1 F_135 ( struct V_61 * V_61 , const char T_2 * V_62 ,
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
V_204 = V_7 ;
}
F_19 ( V_54 ) ;
return V_25 ;
}
static void * F_136 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_194 * V_195 = F_112 () ;
return F_25 ( V_76 , V_77 , & V_195 -> V_206 ) ;
}
static void * F_137 ( struct V_75 * V_76 , void * V_79 , T_4 * V_77 )
{
struct V_194 * V_195 = F_112 () ;
return F_29 ( V_76 , V_79 , V_77 , & V_195 -> V_206 ) ;
}
static int F_138 ( struct V_75 * V_76 , void * V_79 )
{
struct V_15 * V_34 = V_79 ;
struct V_179 * V_180 =
F_77 ( V_34 , struct V_179 , V_34 ) ;
F_94 ( V_76 , V_180 -> V_132 -> V_81 ) ;
F_34 ( V_76 , ' ' ) ;
return 0 ;
}
static int F_139 ( struct V_82 * V_82 , struct V_61 * V_61 )
{
return F_40 ( V_61 , & V_207 ) ;
}
static T_1 F_140 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_194 * V_195 = F_112 () ;
char * V_54 ;
int V_25 ;
F_106 ( V_189 ) ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( * V_64 != 0 )
return - V_60 ;
V_54 = F_9 ( V_63 + 1 , V_31 ) ;
if ( V_54 == NULL )
return - V_32 ;
if ( F_24 ( V_54 , V_62 , V_63 ) != 0 ) {
F_19 ( V_54 ) ;
return - V_71 ;
}
V_25 = F_99 ( V_54 , & V_189 ) ;
F_19 ( V_54 ) ;
if ( ! V_25 || ( V_25 == - V_60 && F_68 ( & V_189 ) ) ) {
F_102 ( & V_195 -> V_206 ) ;
F_141 ( & V_189 , & V_195 -> V_206 ) ;
return V_63 ;
}
F_102 ( & V_189 ) ;
return V_25 ;
}
static T_1 F_142 ( struct V_61 * V_170 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_171 [ 32 ] ;
T_1 V_25 ;
if ( * V_64 != 0 )
return 0 ;
sprintf ( V_171 , L_19 , V_208 ) ;
V_25 = F_83 ( V_62 , V_63 , V_64 , V_171 , strlen ( V_171 ) ) ;
return V_25 ;
}
static T_1 F_143 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_171 [ 32 ] ;
int V_59 ;
if ( ! F_42 ( V_84 ) )
return - V_85 ;
if ( * V_64 != 0 || V_63 >= sizeof( V_171 ) || V_63 == 0 )
return - V_60 ;
if ( F_24 ( V_171 , V_62 , V_63 ) != 0 )
return - V_71 ;
V_171 [ V_63 ] = '\0' ;
if ( sscanf ( V_171 , L_9 , & V_59 ) != 1 )
return - V_60 ;
if ( V_59 < V_209 || V_59 > V_210 )
return - V_60 ;
V_208 = V_59 ;
return V_63 ;
}
static int F_144 ( struct V_211 * V_212 , void * V_54 , int V_213 )
{
int V_25 ;
struct V_82 * V_214 ;
static struct V_215 V_216 [] = {
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
#ifdef F_145
[ V_258 ] = {
L_40 , & V_259 , V_219 | V_220 } ,
#endif
#if F_146 ( V_260 )
[ V_261 ] = {
L_41 , & V_262 , V_219 | V_220 } ,
#endif
[ V_263 ] = {
L_42 , & V_264 ,
V_219 | V_237 } ,
{ L_18 }
} ;
V_25 = F_147 ( V_212 , V_265 , V_216 ) ;
if ( V_25 != 0 ) {
F_45 ( V_266 L_43 ,
V_91 , V_25 ) ;
return V_25 ;
}
V_214 = F_148 ( V_212 -> V_267 ) ;
return 0 ;
}
static struct V_268 * F_149 ( struct V_269 * V_270 ,
int V_271 , const char * V_272 , void * V_54 )
{
return F_150 ( V_270 , V_271 , V_54 , F_144 ) ;
}
static int T_7 F_151 ( struct V_6 * V_7 )
{
V_7 -> V_107 . V_273 = V_7 -> V_81 ;
V_7 -> V_107 . V_271 =
V_274 | V_275 ;
return F_57 ( V_172 , V_7 -> V_81 ,
& V_7 -> V_107 , strlen ( V_7 -> V_81 ) ) ;
}
static int T_7 F_152 ( void )
{
int V_276 ;
int V_25 ;
if ( V_277 == 0 )
return 0 ;
V_276 = F_131 () ;
if ( V_276 )
F_45 ( V_266 L_44 ) ;
V_276 = F_153 ( & V_278 ) ;
if ( ! V_276 ) {
V_279 = F_154 ( & V_278 ) ;
if ( F_15 ( V_279 ) ) {
F_45 ( V_266 L_45 ) ;
V_276 = F_16 ( V_279 ) ;
V_279 = NULL ;
}
}
F_43 () ;
F_49 ( NULL ) ;
V_25 = F_151 ( & V_103 ) ;
if ( V_276 == 0 && V_25 < 0 )
V_276 = V_25 ;
V_25 = F_151 ( & V_280 ) ;
if ( V_276 == 0 && V_25 < 0 )
V_276 = V_25 ;
V_25 = F_151 ( & V_281 ) ;
if ( V_276 == 0 && V_25 < 0 )
V_276 = V_25 ;
V_25 = F_151 ( & V_282 ) ;
if ( V_276 == 0 && V_25 < 0 )
V_276 = V_25 ;
V_25 = F_151 ( & V_205 ) ;
if ( V_276 == 0 && V_25 < 0 )
V_276 = V_25 ;
V_25 = F_151 ( & V_283 ) ;
if ( V_276 == 0 && V_25 < 0 )
V_276 = V_25 ;
return V_276 ;
}
