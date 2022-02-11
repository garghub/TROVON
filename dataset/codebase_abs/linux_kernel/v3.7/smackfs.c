static inline void F_1 ( unsigned int V_1 , char * V_2 )
{
if ( V_1 == 0 || V_1 > ( V_3 * 8 ) )
return;
V_2 [ ( V_1 - 1 ) / 8 ] |= 0x80 >> ( ( V_1 - 1 ) % 8 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
V_5 -> V_6 = F_3 ( V_7 ) ;
V_5 -> V_8 = F_4 ( V_7 ) ;
V_5 -> V_9 = F_5 ( F_6 () ) ;
}
static int F_7 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_10 * V_16 ;
int V_17 = 0 ;
F_8 ( V_15 ) ;
F_9 (sp, rule_list, list) {
if ( V_16 -> V_18 == V_11 -> V_18 &&
V_16 -> V_19 == V_11 -> V_19 ) {
V_17 = 1 ;
V_16 -> V_20 = V_11 -> V_20 ;
break;
}
}
if ( V_17 == 0 )
F_10 ( & V_11 -> V_21 , V_13 ) ;
F_11 ( V_15 ) ;
return V_17 ;
}
static int F_12 ( const char * V_22 , const char * V_23 ,
const char * V_24 , struct V_10 * V_25 ,
int V_26 , int V_27 )
{
const char * V_28 ;
struct V_29 * V_30 ;
if ( V_26 ) {
V_25 -> V_19 = F_13 ( V_22 , V_27 ) ;
if ( V_25 -> V_19 == NULL )
return - 1 ;
V_25 -> V_18 = F_13 ( V_23 , V_27 ) ;
if ( V_25 -> V_18 == NULL )
return - 1 ;
} else {
V_28 = F_14 ( V_22 , V_27 ) ;
if ( V_28 == NULL )
return - 1 ;
V_30 = F_15 ( V_28 ) ;
F_16 ( V_28 ) ;
if ( V_30 == NULL )
return - 1 ;
V_25 -> V_19 = V_30 -> V_31 ;
V_28 = F_14 ( V_23 , V_27 ) ;
if ( V_28 == NULL )
return - 1 ;
V_30 = F_15 ( V_28 ) ;
F_16 ( V_28 ) ;
if ( V_30 == NULL )
return - 1 ;
V_25 -> V_18 = V_30 -> V_31 ;
}
V_25 -> V_20 = 0 ;
for ( V_28 = V_24 ; * V_28 != '\0' ; V_28 ++ ) {
switch ( * V_28 ) {
case '-' :
break;
case 'r' :
case 'R' :
V_25 -> V_20 |= V_32 ;
break;
case 'w' :
case 'W' :
V_25 -> V_20 |= V_33 ;
break;
case 'x' :
case 'X' :
V_25 -> V_20 |= V_34 ;
break;
case 'a' :
case 'A' :
V_25 -> V_20 |= V_35 ;
break;
case 't' :
case 'T' :
V_25 -> V_20 |= V_36 ;
break;
default:
return 0 ;
}
}
return 0 ;
}
static int F_17 ( const char * V_37 , struct V_10 * V_25 , int V_26 )
{
int V_38 ;
V_38 = F_12 ( V_37 , V_37 + V_39 ,
V_37 + V_39 + V_39 , V_25 , V_26 ,
V_39 ) ;
return V_38 ;
}
static int F_18 ( const char * V_37 , struct V_10 * V_25 ,
int V_26 )
{
char * V_22 ;
char * V_23 ;
char * V_24 ;
int V_40 ;
int V_38 = - 1 ;
V_40 = strlen ( V_37 ) ;
V_22 = F_19 ( V_40 + 1 , V_41 ) ;
if ( V_22 == NULL )
return - 1 ;
V_23 = F_19 ( V_40 , V_41 ) ;
if ( V_23 == NULL )
goto V_42;
V_24 = F_19 ( V_40 , V_41 ) ;
if ( V_24 == NULL )
goto V_43;
if ( sscanf ( V_37 , L_1 , V_22 , V_23 , V_24 ) == 3 )
V_38 = F_12 ( V_22 , V_23 , V_24 , V_25 , V_26 , 0 ) ;
F_16 ( V_24 ) ;
V_43:
F_16 ( V_23 ) ;
V_42:
F_16 ( V_22 ) ;
return V_38 ;
}
static T_1 F_20 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , int V_48 )
{
struct V_49 * V_50 ;
struct V_29 * V_30 ;
struct V_10 * V_25 ;
char * V_37 ;
int V_40 ;
int V_38 = - V_51 ;
int V_52 = 0 ;
if ( * V_47 != 0 )
return - V_51 ;
if ( V_48 == V_53 ) {
if ( V_46 != V_54 && V_46 != V_55 )
return - V_51 ;
V_40 = V_55 ;
} else
V_40 = V_46 + 1 ;
V_37 = F_19 ( V_40 , V_41 ) ;
if ( V_37 == NULL )
return - V_56 ;
if ( F_21 ( V_37 , V_45 , V_46 ) != 0 ) {
V_38 = - V_57 ;
goto V_58;
}
V_25 = F_19 ( sizeof( * V_25 ) , V_41 ) ;
if ( V_25 == NULL ) {
V_38 = - V_56 ;
goto V_58;
}
if ( V_48 == V_59 ) {
V_37 [ V_46 ] = '\0' ;
if ( F_18 ( V_37 , V_25 , 1 ) )
goto V_60;
} else {
if ( V_46 == ( V_54 ) )
V_37 [ V_54 ] = '-' ;
if ( F_17 ( V_37 , V_25 , 1 ) )
goto V_60;
}
if ( V_13 == NULL ) {
V_52 = 1 ;
V_30 = F_15 ( V_25 -> V_19 ) ;
V_13 = & V_30 -> V_61 ;
V_15 = & V_30 -> V_62 ;
}
V_38 = V_46 ;
if ( ! F_7 ( V_25 , V_13 , V_15 ) ) {
if ( V_52 ) {
V_50 = F_19 ( sizeof( * V_50 ) , V_41 ) ;
if ( V_50 != NULL ) {
V_50 -> V_63 = V_25 ;
F_10 ( & V_50 -> V_21 , & V_64 ) ;
} else
V_38 = - V_56 ;
}
goto V_58;
}
V_60:
F_16 ( V_25 ) ;
V_58:
F_16 ( V_37 ) ;
return V_38 ;
}
static void * F_22 ( struct V_65 * V_66 , T_4 * V_67 ,
struct V_12 * V_68 )
{
struct V_12 * V_21 ;
if ( V_66 -> V_69 == 0 )
V_66 -> V_70 = V_68 ;
if ( V_66 -> V_70 == NULL )
return NULL ;
V_21 = V_66 -> V_70 ;
if ( F_23 ( V_21 ) )
return NULL ;
if ( V_66 -> V_69 == 0 )
return V_21 -> V_71 ;
return V_21 ;
}
static void * F_24 ( struct V_65 * V_66 , void * V_72 , T_4 * V_67 ,
struct V_12 * V_68 )
{
struct V_12 * V_21 = V_72 ;
if ( F_25 ( V_21 , V_68 ) ) {
V_66 -> V_70 = NULL ;
return NULL ;
}
V_66 -> V_70 = V_21 -> V_71 ;
return V_21 -> V_71 ;
}
static void F_26 ( struct V_65 * V_66 , void * V_72 )
{
}
static void F_27 ( struct V_65 * V_66 , struct V_10 * V_11 , int V_73 )
{
if ( strlen ( V_11 -> V_19 ) >= V_73 || strlen ( V_11 -> V_18 ) >= V_73 )
return;
if ( V_11 -> V_20 == 0 )
return;
F_28 ( V_66 , L_2 , V_11 -> V_19 , V_11 -> V_18 ) ;
F_29 ( V_66 , ' ' ) ;
if ( V_11 -> V_20 & V_32 )
F_29 ( V_66 , 'r' ) ;
if ( V_11 -> V_20 & V_33 )
F_29 ( V_66 , 'w' ) ;
if ( V_11 -> V_20 & V_34 )
F_29 ( V_66 , 'x' ) ;
if ( V_11 -> V_20 & V_35 )
F_29 ( V_66 , 'a' ) ;
if ( V_11 -> V_20 & V_36 )
F_29 ( V_66 , 't' ) ;
F_29 ( V_66 , '\n' ) ;
}
static void * F_30 ( struct V_65 * V_66 , T_4 * V_67 )
{
return F_22 ( V_66 , V_67 , & V_64 ) ;
}
static void * F_31 ( struct V_65 * V_66 , void * V_72 , T_4 * V_67 )
{
return F_24 ( V_66 , V_72 , V_67 , & V_64 ) ;
}
static int F_32 ( struct V_65 * V_66 , void * V_72 )
{
struct V_12 * V_21 = V_72 ;
struct V_49 * V_50 =
F_33 ( V_21 , struct V_49 , V_21 ) ;
F_27 ( V_66 , V_50 -> V_63 , V_39 ) ;
return 0 ;
}
static int F_34 ( struct V_74 * V_74 , struct V_44 * V_44 )
{
return F_35 ( V_44 , & V_75 ) ;
}
static T_1 F_36 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
if ( ! F_37 ( V_76 ) )
return - V_77 ;
return F_20 ( V_44 , V_45 , V_46 , V_47 , NULL , NULL ,
V_53 ) ;
}
static void F_38 ( void )
{
int V_38 ;
struct V_78 * V_79 ;
struct V_4 V_80 ;
F_2 ( & V_80 ) ;
V_38 = F_39 ( NULL , V_81 , NULL , NULL , & V_80 ) ;
if ( V_38 != 0 )
F_40 ( V_82 L_3 ,
V_83 , __LINE__ , V_38 ) ;
V_79 = F_41 ( sizeof( struct V_78 ) , V_41 ) ;
if ( V_79 == NULL )
F_42 ( L_4 ) ;
V_79 -> V_84 . V_85 = NULL ;
V_79 -> V_86 = V_87 ;
V_79 -> type = V_88 ;
V_79 -> V_89 [ 0 ] = V_90 ;
for ( V_38 = 1 ; V_38 < V_91 ; V_38 ++ )
V_79 -> V_89 [ V_38 ] = V_92 ;
V_38 = F_43 ( V_79 , & V_80 ) ;
if ( V_38 != 0 ) {
F_40 ( V_82 L_5 ,
V_83 , __LINE__ , V_38 ) ;
F_16 ( V_79 ) ;
return;
}
V_38 = F_44 ( V_79 -> V_86 , NULL , NULL , NULL , & V_80 ) ;
if ( V_38 != 0 ) {
F_40 ( V_82 L_6 ,
V_83 , __LINE__ , V_38 ) ;
F_16 ( V_79 ) ;
return;
}
}
static void F_45 ( char * V_93 )
{
int V_38 ;
struct V_4 V_80 ;
F_2 ( & V_80 ) ;
if ( V_93 != NULL ) {
V_38 = F_39 ( V_93 , V_81 , NULL , NULL , & V_80 ) ;
if ( V_38 != 0 )
F_40 ( V_82 L_3 ,
V_83 , __LINE__ , V_38 ) ;
}
if ( V_94 == NULL )
V_94 = V_95 . V_31 ;
V_38 = F_46 ( V_94 , V_81 ,
NULL , NULL , & V_80 ) ;
if ( V_38 != 0 )
F_40 ( V_82 L_7 ,
V_83 , __LINE__ , V_38 ) ;
}
static void * F_47 ( struct V_65 * V_66 , T_4 * V_67 )
{
return F_22 ( V_66 , V_67 , & V_96 ) ;
}
static void * F_48 ( struct V_65 * V_66 , void * V_72 , T_4 * V_67 )
{
return F_24 ( V_66 , V_72 , V_67 , & V_96 ) ;
}
static int F_49 ( struct V_65 * V_66 , void * V_72 )
{
struct V_12 * V_21 = V_72 ;
struct V_29 * V_30 =
F_33 ( V_21 , struct V_29 , V_21 ) ;
struct V_97 * V_98 = V_30 -> V_99 . V_100 . V_101 . V_1 ;
char V_102 = '/' ;
int V_103 ;
if ( strlen ( V_30 -> V_31 ) >= V_39 )
return 0 ;
F_28 ( V_66 , L_8 , V_30 -> V_31 , V_30 -> V_99 . V_100 . V_101 . V_104 ) ;
for ( V_103 = F_50 ( V_98 , 0 ) ; V_103 >= 0 ;
V_103 = F_50 ( V_98 , V_103 + 1 ) ) {
F_28 ( V_66 , L_9 , V_102 , V_103 ) ;
V_102 = ',' ;
}
F_29 ( V_66 , '\n' ) ;
return 0 ;
}
static int F_51 ( struct V_74 * V_74 , struct V_44 * V_44 )
{
return F_35 ( V_44 , & V_105 ) ;
}
static T_1 F_52 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 , int V_48 )
{
struct V_29 * V_30 ;
struct V_106 V_107 ;
char V_108 [ V_3 ] ;
int V_109 ;
unsigned int V_1 ;
int V_110 ;
T_1 V_38 = - V_51 ;
char * V_37 = NULL ;
char * V_25 ;
int V_111 ;
int V_103 ;
if ( ! F_37 ( V_76 ) )
return - V_77 ;
if ( * V_47 != 0 )
return - V_51 ;
if ( V_48 == V_53 &&
( V_46 < V_112 || V_46 > V_113 ) )
return - V_51 ;
V_37 = F_19 ( V_46 + 1 , V_41 ) ;
if ( V_37 == NULL )
return - V_56 ;
if ( F_21 ( V_37 , V_45 , V_46 ) != 0 ) {
V_38 = - V_57 ;
goto V_114;
}
V_37 [ V_46 ] = '\0' ;
V_25 = V_37 ;
F_8 ( & V_115 ) ;
V_30 = F_53 ( V_25 , 0 ) ;
if ( V_30 == NULL )
goto V_58;
if ( V_48 == V_53 )
V_25 += V_39 ;
else
V_25 += strlen ( V_30 -> V_31 ) ;
V_111 = sscanf ( V_25 , L_10 , & V_109 ) ;
if ( V_111 != 1 || V_109 > V_116 )
goto V_58;
V_25 += V_117 ;
V_111 = sscanf ( V_25 , L_10 , & V_110 ) ;
if ( V_111 != 1 || V_110 > V_118 )
goto V_58;
if ( V_48 == V_53 &&
V_46 != ( V_112 + V_110 * V_117 ) )
goto V_58;
memset ( V_108 , 0 , sizeof( V_108 ) ) ;
for ( V_103 = 0 ; V_103 < V_110 ; V_103 ++ ) {
V_25 += V_117 ;
V_111 = sscanf ( V_25 , L_11 , & V_1 ) ;
if ( V_111 != 1 || V_1 > V_119 )
goto V_58;
F_1 ( V_1 , V_108 ) ;
}
V_38 = F_54 ( V_109 , V_108 , & V_107 , V_3 ) ;
if ( V_38 >= 0 ) {
F_55 ( V_30 -> V_99 . V_100 . V_101 . V_1 ) ;
V_30 -> V_99 . V_100 . V_101 . V_1 = V_107 . V_100 . V_101 . V_1 ;
V_30 -> V_99 . V_100 . V_101 . V_104 = V_107 . V_100 . V_101 . V_104 ;
V_38 = V_46 ;
}
V_58:
F_11 ( & V_115 ) ;
V_114:
F_16 ( V_37 ) ;
return V_38 ;
}
static T_1 F_56 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
return F_52 ( V_44 , V_45 , V_46 , V_47 , V_53 ) ;
}
static int F_57 ( struct V_65 * V_66 , void * V_72 )
{
struct V_12 * V_21 = V_72 ;
struct V_29 * V_30 =
F_33 ( V_21 , struct V_29 , V_21 ) ;
struct V_97 * V_98 = V_30 -> V_99 . V_100 . V_101 . V_1 ;
char V_102 = '/' ;
int V_103 ;
F_28 ( V_66 , L_8 , V_30 -> V_31 , V_30 -> V_99 . V_100 . V_101 . V_104 ) ;
for ( V_103 = F_50 ( V_98 , 0 ) ; V_103 >= 0 ;
V_103 = F_50 ( V_98 , V_103 + 1 ) ) {
F_28 ( V_66 , L_9 , V_102 , V_103 ) ;
V_102 = ',' ;
}
F_29 ( V_66 , '\n' ) ;
return 0 ;
}
static int F_58 ( struct V_74 * V_74 , struct V_44 * V_44 )
{
return F_35 ( V_44 , & V_120 ) ;
}
static T_1 F_59 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
return F_52 ( V_44 , V_45 , V_46 , V_47 , V_59 ) ;
}
static void * F_60 ( struct V_65 * V_66 , T_4 * V_67 )
{
return F_22 ( V_66 , V_67 , & V_121 ) ;
}
static void * F_61 ( struct V_65 * V_66 , void * V_72 , T_4 * V_67 )
{
return F_24 ( V_66 , V_72 , V_67 , & V_121 ) ;
}
static int F_62 ( struct V_65 * V_66 , void * V_72 )
{
struct V_12 * V_21 = V_72 ;
struct V_122 * V_30 =
F_33 ( V_21 , struct V_122 , V_21 ) ;
unsigned char * V_123 = ( char * ) & V_30 -> V_124 . V_125 . V_126 ;
int V_127 ;
T_5 V_128 = F_63 ( V_30 -> V_129 . V_126 ) ;
for ( V_127 = 0 ; V_128 ; V_128 <<= 1 , V_127 ++ ) ;
F_28 ( V_66 , L_12 ,
V_123 [ 0 ] , V_123 [ 1 ] , V_123 [ 2 ] , V_123 [ 3 ] , V_127 , V_30 -> V_130 ) ;
return 0 ;
}
static int F_64 ( struct V_74 * V_74 , struct V_44 * V_44 )
{
return F_35 ( V_44 , & V_131 ) ;
}
static void F_65 ( struct V_122 * V_132 )
{
struct V_122 * V_133 , * V_134 ;
if ( F_23 ( & V_121 ) ) {
F_10 ( & V_132 -> V_21 , & V_121 ) ;
return;
}
V_133 = F_66 ( V_121 . V_71 ,
struct V_122 , V_21 ) ;
if ( V_132 -> V_129 . V_126 > V_133 -> V_129 . V_126 ) {
F_10 ( & V_132 -> V_21 , & V_121 ) ;
return;
}
F_9 (m, &smk_netlbladdr_list, list) {
if ( F_25 ( & V_133 -> V_21 , & V_121 ) ) {
F_10 ( & V_132 -> V_21 , & V_133 -> V_21 ) ;
return;
}
V_134 = F_66 ( V_133 -> V_21 . V_71 ,
struct V_122 , V_21 ) ;
if ( V_132 -> V_129 . V_126 > V_134 -> V_129 . V_126 ) {
F_10 ( & V_132 -> V_21 , & V_133 -> V_21 ) ;
return;
}
}
}
static T_1 F_67 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_122 * V_30 ;
struct V_135 V_136 ;
char * V_137 ;
char * V_16 ;
char * V_37 ;
char * V_138 = ( char * ) & V_136 . V_125 . V_126 ;
int V_38 ;
struct V_4 V_139 ;
struct V_140 V_141 ;
unsigned int V_133 ;
int V_17 ;
T_5 V_142 = ( 1 << 31 ) ;
T_6 V_143 ;
T_5 V_128 ;
if ( ! F_37 ( V_76 ) )
return - V_77 ;
if ( * V_47 != 0 )
return - V_51 ;
if ( V_46 < V_144 )
return - V_51 ;
V_37 = F_19 ( V_46 + 1 , V_41 ) ;
if ( V_37 == NULL )
return - V_56 ;
if ( F_21 ( V_37 , V_45 , V_46 ) != 0 ) {
V_38 = - V_57 ;
goto V_145;
}
V_137 = F_19 ( V_46 + 1 , V_41 ) ;
if ( V_137 == NULL ) {
V_38 = - V_56 ;
goto V_145;
}
V_37 [ V_46 ] = '\0' ;
V_38 = sscanf ( V_37 , L_13 ,
& V_138 [ 0 ] , & V_138 [ 1 ] , & V_138 [ 2 ] , & V_138 [ 3 ] , & V_133 , V_137 ) ;
if ( V_38 != 6 ) {
V_38 = sscanf ( V_37 , L_14 ,
& V_138 [ 0 ] , & V_138 [ 1 ] , & V_138 [ 2 ] , & V_138 [ 3 ] , V_137 ) ;
if ( V_38 != 5 ) {
V_38 = - V_51 ;
goto V_146;
}
V_133 = V_147 ;
}
if ( V_133 > V_147 ) {
V_38 = - V_51 ;
goto V_146;
}
if ( V_137 [ 0 ] != '-' ) {
V_16 = F_13 ( V_137 , 0 ) ;
if ( V_16 == NULL ) {
V_38 = - V_51 ;
goto V_146;
}
} else {
if ( strcmp ( V_137 , V_148 ) == 0 )
V_16 = ( char * ) V_148 ;
else {
V_38 = - V_51 ;
goto V_146;
}
}
for ( V_128 = 0 ; V_133 > 0 ; V_133 -- ) {
V_128 |= V_142 ;
V_142 >>= 1 ;
}
V_141 . V_126 = F_68 ( V_128 ) ;
V_136 . V_125 . V_126 &= V_141 . V_126 ;
F_8 ( & V_149 ) ;
V_143 = V_136 . V_125 . V_126 ;
V_17 = 0 ;
F_9 (skp, &smk_netlbladdr_list, list) {
if ( V_30 -> V_124 . V_125 . V_126 == V_143 &&
V_30 -> V_129 . V_126 == V_141 . V_126 ) {
V_17 = 1 ;
break;
}
}
F_2 ( & V_139 ) ;
if ( V_17 == 0 ) {
V_30 = F_19 ( sizeof( * V_30 ) , V_41 ) ;
if ( V_30 == NULL )
V_38 = - V_56 ;
else {
V_38 = 0 ;
V_30 -> V_124 . V_125 . V_126 = V_136 . V_125 . V_126 ;
V_30 -> V_129 . V_126 = V_141 . V_126 ;
V_30 -> V_130 = V_16 ;
F_65 ( V_30 ) ;
}
} else {
if ( V_30 -> V_130 != V_148 )
V_38 = F_69 ( & V_150 , NULL ,
& V_30 -> V_124 . V_125 , & V_30 -> V_129 ,
V_81 , & V_139 ) ;
else
V_38 = 0 ;
V_30 -> V_130 = V_16 ;
}
if ( V_38 == 0 && V_16 != V_148 )
V_38 = F_70 ( & V_150 , NULL ,
& V_30 -> V_124 . V_125 , & V_30 -> V_129 , V_81 ,
F_5 ( V_30 -> V_130 ) , & V_139 ) ;
if ( V_38 == 0 )
V_38 = V_46 ;
F_11 ( & V_149 ) ;
V_146:
F_16 ( V_137 ) ;
V_145:
F_16 ( V_37 ) ;
return V_38 ;
}
static T_1 F_71 ( struct V_44 * V_151 , char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
char V_152 [ 80 ] ;
T_1 V_38 ;
if ( * V_47 != 0 )
return 0 ;
sprintf ( V_152 , L_10 , V_87 ) ;
V_38 = F_72 ( V_45 , V_46 , V_47 , V_152 , strlen ( V_152 ) ) ;
return V_38 ;
}
static T_1 F_73 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
char V_152 [ 80 ] ;
int V_103 ;
if ( ! F_37 ( V_76 ) )
return - V_77 ;
if ( V_46 >= sizeof( V_152 ) || V_46 == 0 )
return - V_51 ;
if ( F_21 ( V_152 , V_45 , V_46 ) != 0 )
return - V_57 ;
V_152 [ V_46 ] = '\0' ;
if ( sscanf ( V_152 , L_10 , & V_103 ) != 1 )
return - V_51 ;
V_87 = V_103 ;
F_38 () ;
return V_46 ;
}
static T_1 F_74 ( struct V_44 * V_151 , char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
char V_152 [ 80 ] ;
T_1 V_38 ;
if ( * V_47 != 0 )
return 0 ;
sprintf ( V_152 , L_10 , V_153 ) ;
V_38 = F_72 ( V_45 , V_46 , V_47 , V_152 , strlen ( V_152 ) ) ;
return V_38 ;
}
static T_1 F_75 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_29 * V_30 ;
char V_152 [ 80 ] ;
int V_103 ;
if ( ! F_37 ( V_76 ) )
return - V_77 ;
if ( V_46 >= sizeof( V_152 ) || V_46 == 0 )
return - V_51 ;
if ( F_21 ( V_152 , V_45 , V_46 ) != 0 )
return - V_57 ;
V_152 [ V_46 ] = '\0' ;
if ( sscanf ( V_152 , L_10 , & V_103 ) != 1 )
return - V_51 ;
if ( V_153 != V_103 ) {
F_8 ( & V_154 ) ;
F_9 (skp, &smack_known_list, list)
if ( V_30 -> V_99 . V_100 . V_101 . V_104 ==
V_153 )
V_30 -> V_99 . V_100 . V_101 . V_104 = V_103 ;
V_153 = V_103 ;
F_11 ( & V_154 ) ;
}
return V_46 ;
}
static T_1 F_76 ( struct V_44 * V_151 , char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
char V_152 [ 80 ] ;
T_1 V_38 ;
if ( * V_47 != 0 )
return 0 ;
sprintf ( V_152 , L_10 , V_155 ) ;
V_38 = F_72 ( V_45 , V_46 , V_47 , V_152 , strlen ( V_152 ) ) ;
return V_38 ;
}
static T_1 F_77 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_29 * V_30 ;
char V_152 [ 80 ] ;
int V_103 ;
if ( ! F_37 ( V_76 ) )
return - V_77 ;
if ( V_46 >= sizeof( V_152 ) || V_46 == 0 )
return - V_51 ;
if ( F_21 ( V_152 , V_45 , V_46 ) != 0 )
return - V_57 ;
V_152 [ V_46 ] = '\0' ;
if ( sscanf ( V_152 , L_10 , & V_103 ) != 1 )
return - V_51 ;
if ( V_155 != V_103 ) {
F_8 ( & V_154 ) ;
F_9 (skp, &smack_known_list, list)
if ( V_30 -> V_99 . V_100 . V_101 . V_104 ==
V_155 )
V_30 -> V_99 . V_100 . V_101 . V_104 = V_103 ;
V_155 = V_103 ;
F_11 ( & V_154 ) ;
}
return V_46 ;
}
static T_1 F_78 ( struct V_44 * V_151 , char T_2 * V_45 ,
T_3 V_156 , T_4 * V_47 )
{
T_1 V_38 ;
int V_157 ;
if ( * V_47 != 0 )
return 0 ;
F_8 ( & V_158 ) ;
V_157 = strlen ( V_94 ) + 1 ;
if ( V_156 >= V_157 )
V_38 = F_72 ( V_45 , V_156 , V_47 ,
V_94 , V_157 ) ;
else
V_38 = - V_51 ;
F_11 ( & V_158 ) ;
return V_38 ;
}
static T_1 F_79 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
char * V_93 ;
char * V_137 = NULL ;
char * V_37 ;
int V_38 = V_46 ;
if ( ! F_37 ( V_76 ) )
return - V_77 ;
V_37 = F_19 ( V_46 + 1 , V_41 ) ;
if ( V_37 == NULL )
return - V_56 ;
if ( F_21 ( V_37 , V_45 , V_46 ) != 0 ) {
V_38 = - V_57 ;
goto V_58;
}
V_137 = F_13 ( V_37 , V_46 ) ;
if ( V_137 == NULL ) {
V_38 = - V_51 ;
goto V_58;
}
F_8 ( & V_158 ) ;
V_93 = V_94 ;
V_94 = V_137 ;
F_45 ( V_93 ) ;
F_11 ( & V_158 ) ;
V_58:
F_16 ( V_37 ) ;
return V_38 ;
}
static T_1 F_80 ( struct V_44 * V_151 , char T_2 * V_45 ,
T_3 V_156 , T_4 * V_47 )
{
char * V_137 = L_15 ;
T_1 V_38 = - V_51 ;
int V_157 ;
if ( * V_47 != 0 )
return 0 ;
if ( V_159 != NULL )
V_137 = V_159 ;
V_157 = strlen ( V_137 ) + 1 ;
if ( V_156 >= V_157 )
V_38 = F_72 ( V_45 , V_156 , V_47 , V_137 , V_157 ) ;
return V_38 ;
}
static T_1 F_81 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
char * V_37 ;
char * V_16 = F_82 ( V_7 -> V_160 -> V_161 ) ;
int V_38 = V_46 ;
if ( ! F_37 ( V_76 ) )
return - V_77 ;
if ( V_159 != NULL && V_159 != V_16 )
return - V_77 ;
V_37 = F_19 ( V_46 , V_41 ) ;
if ( V_37 == NULL )
return - V_56 ;
if ( F_21 ( V_37 , V_45 , V_46 ) != 0 )
V_38 = - V_57 ;
else
V_159 = F_13 ( V_37 , V_46 ) ;
F_16 ( V_37 ) ;
return V_38 ;
}
static T_1 F_83 ( struct V_44 * V_151 , char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
char V_152 [ 32 ] ;
T_1 V_38 ;
if ( * V_47 != 0 )
return 0 ;
sprintf ( V_152 , L_16 , V_162 ) ;
V_38 = F_72 ( V_45 , V_46 , V_47 , V_152 , strlen ( V_152 ) ) ;
return V_38 ;
}
static T_1 F_84 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
char V_152 [ 32 ] ;
int V_103 ;
if ( ! F_37 ( V_76 ) )
return - V_77 ;
if ( V_46 >= sizeof( V_152 ) || V_46 == 0 )
return - V_51 ;
if ( F_21 ( V_152 , V_45 , V_46 ) != 0 )
return - V_57 ;
V_152 [ V_46 ] = '\0' ;
if ( sscanf ( V_152 , L_10 , & V_103 ) != 1 )
return - V_51 ;
if ( V_103 < 0 || V_103 > 3 )
return - V_51 ;
V_162 = V_103 ;
return V_46 ;
}
static void * F_85 ( struct V_65 * V_66 , T_4 * V_67 )
{
struct V_163 * V_164 = F_86 () ;
return F_22 ( V_66 , V_67 , & V_164 -> V_61 ) ;
}
static void * F_87 ( struct V_65 * V_66 , void * V_72 , T_4 * V_67 )
{
struct V_163 * V_164 = F_86 () ;
return F_24 ( V_66 , V_72 , V_67 , & V_164 -> V_61 ) ;
}
static int F_88 ( struct V_65 * V_66 , void * V_72 )
{
struct V_12 * V_21 = V_72 ;
struct V_10 * V_11 =
F_33 ( V_21 , struct V_10 , V_21 ) ;
F_27 ( V_66 , V_11 , V_39 ) ;
return 0 ;
}
static int F_89 ( struct V_74 * V_74 , struct V_44 * V_44 )
{
return F_35 ( V_44 , & V_165 ) ;
}
static T_1 F_90 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_163 * V_164 = F_86 () ;
return F_20 ( V_44 , V_45 , V_46 , V_47 , & V_164 -> V_61 ,
& V_164 -> V_62 , V_53 ) ;
}
static T_1 F_91 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 , int V_48 )
{
struct V_10 V_25 ;
char * V_37 ;
char * V_166 ;
int V_167 ;
V_37 = F_92 ( V_44 , V_45 , V_46 ) ;
if ( F_93 ( V_37 ) )
return F_94 ( V_37 ) ;
if ( V_48 == V_53 ) {
if ( V_46 < V_55 )
return - V_51 ;
V_167 = F_17 ( V_37 , & V_25 , 0 ) ;
} else {
V_166 = F_19 ( V_46 + 1 , V_41 ) ;
if ( V_166 == NULL )
return - V_56 ;
memcpy ( V_166 , V_37 , V_46 ) ;
V_166 [ V_46 ] = '\0' ;
V_167 = F_18 ( V_166 , & V_25 , 0 ) ;
F_16 ( V_166 ) ;
}
if ( V_167 )
return - V_51 ;
V_167 = V_20 ( V_25 . V_19 , V_25 . V_18 , V_25 . V_20 ,
NULL ) ;
V_37 [ 0 ] = V_167 == 0 ? '1' : '0' ;
V_37 [ 1 ] = '\0' ;
F_95 ( V_44 , 2 ) ;
if ( V_48 == V_53 )
return V_55 ;
return V_46 ;
}
static T_1 F_96 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
return F_91 ( V_44 , V_45 , V_46 , V_47 , V_53 ) ;
}
static int F_97 ( struct V_65 * V_66 , void * V_72 )
{
struct V_12 * V_21 = V_72 ;
struct V_49 * V_50 =
F_33 ( V_21 , struct V_49 , V_21 ) ;
F_27 ( V_66 , V_50 -> V_63 , V_168 ) ;
return 0 ;
}
static int F_98 ( struct V_74 * V_74 , struct V_44 * V_44 )
{
return F_35 ( V_44 , & V_169 ) ;
}
static T_1 F_99 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
if ( ! F_37 ( V_76 ) )
return - V_77 ;
return F_20 ( V_44 , V_45 , V_46 , V_47 , NULL , NULL ,
V_59 ) ;
}
static void * F_100 ( struct V_65 * V_66 , T_4 * V_67 )
{
struct V_163 * V_164 = F_86 () ;
return F_22 ( V_66 , V_67 , & V_164 -> V_61 ) ;
}
static void * F_101 ( struct V_65 * V_66 , void * V_72 , T_4 * V_67 )
{
struct V_163 * V_164 = F_86 () ;
return F_24 ( V_66 , V_72 , V_67 , & V_164 -> V_61 ) ;
}
static int F_102 ( struct V_65 * V_66 , void * V_72 )
{
struct V_12 * V_21 = V_72 ;
struct V_10 * V_11 =
F_33 ( V_21 , struct V_10 , V_21 ) ;
F_27 ( V_66 , V_11 , V_168 ) ;
return 0 ;
}
static int F_103 ( struct V_74 * V_74 , struct V_44 * V_44 )
{
return F_35 ( V_44 , & V_170 ) ;
}
static T_1 F_104 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_163 * V_164 = F_86 () ;
return F_20 ( V_44 , V_45 , V_46 , V_47 , & V_164 -> V_61 ,
& V_164 -> V_62 , V_59 ) ;
}
static T_1 F_105 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
return F_91 ( V_44 , V_45 , V_46 , V_47 , V_59 ) ;
}
static T_1 F_106 ( struct V_44 * V_44 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
char * V_37 = NULL ;
const char * V_28 = NULL ;
struct V_29 * V_30 ;
struct V_10 * V_16 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_38 = V_46 ;
if ( * V_47 != 0 )
return - V_51 ;
if ( ! F_37 ( V_76 ) )
return - V_77 ;
if ( V_46 == 0 || V_46 > V_168 )
return - V_51 ;
V_37 = F_19 ( V_46 , V_41 ) ;
if ( V_37 == NULL )
return - V_56 ;
if ( F_21 ( V_37 , V_45 , V_46 ) != 0 ) {
V_38 = - V_57 ;
goto V_146;
}
V_28 = F_14 ( V_37 , V_46 ) ;
if ( V_28 == NULL ) {
V_38 = - V_51 ;
goto V_146;
}
V_30 = F_15 ( V_28 ) ;
if ( V_30 == NULL ) {
V_38 = - V_51 ;
goto V_146;
}
V_13 = & V_30 -> V_61 ;
V_15 = & V_30 -> V_62 ;
F_8 ( V_15 ) ;
F_9 (sp, rule_list, list)
V_16 -> V_20 = 0 ;
F_11 ( V_15 ) ;
V_146:
F_16 ( V_37 ) ;
F_16 ( V_28 ) ;
return V_38 ;
}
static int F_107 ( struct V_171 * V_172 , void * V_37 , int V_173 )
{
int V_38 ;
struct V_74 * V_174 ;
static struct V_175 V_176 [] = {
[ V_177 ] = {
L_17 , & V_178 , V_179 | V_180 } ,
[ V_181 ] = {
L_18 , & V_182 , V_179 | V_180 } ,
[ V_183 ] = {
L_19 , & V_184 , V_179 | V_180 } ,
[ V_185 ] = {
L_20 , & V_186 , V_179 | V_180 } ,
[ V_187 ] = {
L_21 , & V_188 , V_179 | V_180 } ,
[ V_189 ] = {
L_22 , & V_190 , V_179 | V_180 } ,
[ V_191 ] = {
L_23 , & V_192 , V_179 | V_180 } ,
[ V_193 ] = {
L_24 , & V_194 , V_179 | V_180 } ,
[ V_195 ] = {
L_25 , & V_196 , V_179 | V_197 } ,
[ V_198 ] = {
L_26 , & V_199 , V_179 | V_197 } ,
[ V_200 ] = {
L_27 , & V_201 , V_179 | V_180 } ,
[ V_202 ] = {
L_28 , & V_203 , V_179 | V_180 } ,
[ V_204 ] = {
L_29 , & V_205 , V_179 | V_197 } ,
[ V_206 ] = {
L_30 , & V_207 , V_179 | V_197 } ,
[ V_208 ] = {
L_31 , & V_209 , V_179 | V_180 } ,
[ V_210 ] = {
L_32 , & V_211 ,
V_179 | V_180 } ,
{ L_15 }
} ;
V_38 = F_108 ( V_172 , V_212 , V_176 ) ;
if ( V_38 != 0 ) {
F_40 ( V_213 L_33 ,
V_83 , V_38 ) ;
return V_38 ;
}
V_174 = V_172 -> V_214 -> V_215 ;
return 0 ;
}
static struct V_216 * F_109 ( struct V_217 * V_218 ,
int V_219 , const char * V_220 , void * V_37 )
{
return F_110 ( V_218 , V_219 , V_37 , F_107 ) ;
}
static int T_7 F_111 ( struct V_29 * V_30 )
{
V_30 -> V_99 . V_221 = V_30 -> V_31 ;
V_30 -> V_99 . V_219 =
V_222 | V_223 ;
return F_54 ( V_153 , V_30 -> V_31 ,
& V_30 -> V_99 , strlen ( V_30 -> V_31 ) ) ;
}
static int T_7 F_112 ( void )
{
int V_224 ;
int V_38 ;
if ( ! F_113 ( & V_225 ) )
return 0 ;
V_224 = F_114 ( & V_226 ) ;
if ( ! V_224 ) {
V_227 = F_115 ( & V_226 ) ;
if ( F_93 ( V_227 ) ) {
F_40 ( V_213 L_34 ) ;
V_224 = F_94 ( V_227 ) ;
V_227 = NULL ;
}
}
F_38 () ;
F_45 ( NULL ) ;
V_38 = F_111 ( & V_95 ) ;
if ( V_224 == 0 && V_38 < 0 )
V_224 = V_38 ;
V_38 = F_111 ( & V_228 ) ;
if ( V_224 == 0 && V_38 < 0 )
V_224 = V_38 ;
V_38 = F_111 ( & V_229 ) ;
if ( V_224 == 0 && V_38 < 0 )
V_224 = V_38 ;
V_38 = F_111 ( & V_230 ) ;
if ( V_224 == 0 && V_38 < 0 )
V_224 = V_38 ;
V_38 = F_111 ( & V_231 ) ;
if ( V_224 == 0 && V_38 < 0 )
V_224 = V_38 ;
V_38 = F_111 ( & V_232 ) ;
if ( V_224 == 0 && V_38 < 0 )
V_224 = V_38 ;
return V_224 ;
}
