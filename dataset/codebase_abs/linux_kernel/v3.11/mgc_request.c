static int F_1 ( char * V_1 , int V_2 , struct V_3 * V_4 ,
int type )
{
T_1 V_5 = 0 ;
if ( V_2 > 8 ) {
F_2 ( L_1 , V_1 ) ;
return - V_6 ;
}
if ( V_2 <= 0 ) {
F_2 ( L_2 , V_1 ) ;
return - V_6 ;
}
memcpy ( & V_5 , V_1 , V_2 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_1 [ 0 ] = F_3 ( V_5 ) ;
switch( type ) {
case V_7 :
case V_8 :
V_5 = 0 ;
break;
case V_9 :
V_5 = type ;
break;
default:
F_4 () ;
}
V_4 -> V_1 [ 1 ] = F_3 ( V_5 ) ;
F_5 ( V_10 , L_3 V_11 L_4 V_11 L_5 , V_1 ,
V_4 -> V_1 [ 0 ] , V_4 -> V_1 [ 1 ] , ( char * ) & V_4 -> V_1 [ 0 ] ) ;
return 0 ;
}
int F_6 ( char * V_12 , struct V_3 * V_4 , int type )
{
return F_1 ( V_12 , strlen ( V_12 ) , V_4 , type ) ;
}
int F_7 ( char * V_13 , struct V_3 * V_4 , int type )
{
char * V_14 ;
int V_2 ;
V_14 = strrchr ( V_13 , '-' ) ;
F_8 ( V_14 ) ;
V_2 = V_14 - V_13 ;
return F_1 ( V_13 , V_2 , V_4 , type ) ;
}
static int F_9 ( struct V_15 * V_16 )
{
V_17 ;
F_10 ( & V_16 -> V_18 ) ;
F_5 ( V_19 , L_6 , V_16 -> V_20 ,
F_11 ( & V_16 -> V_18 ) ) ;
RETURN ( 0 ) ;
}
static void F_12 ( struct V_15 * V_16 )
{
V_17 ;
F_5 ( V_19 , L_6 , V_16 -> V_20 ,
F_11 ( & V_16 -> V_18 ) ) ;
F_8 ( F_11 ( & V_16 -> V_18 ) > 0 ) ;
if ( F_13 ( & V_16 -> V_18 , & V_21 ) ) {
F_14 ( & V_16 -> V_22 ) ;
F_15 ( & V_21 ) ;
F_5 ( V_10 , L_7 , V_16 -> V_20 ) ;
if ( V_16 -> V_23 )
F_12 ( V_16 -> V_23 ) ;
if ( V_16 -> V_24 )
F_12 ( V_16 -> V_24 ) ;
if ( F_16 ( V_16 ) )
F_17 ( V_16 -> V_20 ) ;
F_18 ( V_16 -> V_25 ) ;
F_19 ( V_16 , sizeof( * V_16 ) + strlen ( V_16 -> V_20 ) + 1 ) ;
}
EXIT ;
}
static
struct V_15 * F_20 ( char * V_13 ,
struct V_26 * V_27 )
{
struct V_15 * V_16 ;
struct V_15 * V_28 = NULL ;
void * V_29 ;
V_17 ;
F_8 ( V_13 != NULL ) ;
V_29 = V_27 ? V_27 -> V_30 : NULL ;
F_21 ( & V_21 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_29 != V_16 -> V_31 . V_30 )
continue;
if ( strcmp ( V_13 , V_16 -> V_20 ) == 0 ) {
V_28 = V_16 ;
break;
}
}
if ( V_28 ) {
F_10 ( & V_28 -> V_18 ) ;
F_8 ( V_28 -> V_32 == 0 || F_16 ( V_28 ) == 0 ) ;
}
F_15 ( & V_21 ) ;
RETURN ( V_28 ) ;
}
static
struct V_15 * F_23 ( struct V_33 * V_34 ,
char * V_13 ,
int type ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_15 * V_16 ;
int V_37 ;
V_17 ;
F_5 ( V_10 , L_8 , V_13 ,
V_27 ? V_27 -> V_30 : 0 ) ;
F_24 ( V_16 , sizeof( * V_16 ) + strlen ( V_13 ) + 1 ) ;
if ( ! V_16 )
RETURN ( F_25 ( - V_38 ) ) ;
strcpy ( V_16 -> V_20 , V_13 ) ;
if ( V_27 )
V_16 -> V_31 = * V_27 ;
else
V_16 -> V_31 . V_39 = V_40 ;
F_26 ( & V_16 -> V_41 ) ;
V_16 -> V_31 . V_42 = 0 ;
V_16 -> V_31 . V_43 = 0 ;
V_16 -> V_31 . V_44 = V_36 ;
V_16 -> V_45 = type ;
F_27 ( & V_16 -> V_18 , 1 ) ;
V_16 -> V_25 = F_28 ( V_34 -> V_46 ) ;
if ( F_16 ( V_16 ) ) {
F_29 ( V_13 ) ;
V_16 -> V_31 . V_47 = V_34 -> V_48 ;
}
V_37 = F_7 ( V_13 , & V_16 -> V_49 , type ) ;
F_21 ( & V_21 ) ;
F_30 ( & V_16 -> V_22 , & V_50 ) ;
F_15 ( & V_21 ) ;
if ( V_37 ) {
F_12 ( V_16 ) ;
RETURN ( F_25 ( V_37 ) ) ;
}
if ( F_16 ( V_16 ) ) {
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 && V_37 != - V_51 )
F_2 ( L_9 , V_37 ) ;
}
RETURN ( V_16 ) ;
}
static struct V_15 * F_32 ( struct V_33 * V_34 ,
char * V_12 ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_26 V_52 = * V_27 ;
struct V_53 * V_54 = F_33 ( V_36 ) ;
struct V_15 * V_16 ;
char V_13 [ 32 ] ;
if ( F_34 ( V_54 ) )
return NULL ;
if ( F_35 ( V_54 ) && V_52 . V_30 )
return NULL ;
F_8 ( strlen ( V_12 ) < sizeof( V_13 ) / 2 ) ;
strcpy ( V_13 , V_12 ) ;
if ( F_36 ( V_54 ) ) {
F_8 ( V_52 . V_30 == NULL ) ;
V_52 . V_30 = V_36 ;
strcat ( V_13 , L_10 ) ;
} else {
F_8 ( V_52 . V_30 != NULL ) ;
strcat ( V_13 , L_11 ) ;
}
V_16 = F_23 ( V_34 , V_13 , V_9 , & V_52 , V_36 ) ;
return V_16 ;
}
static int F_37 ( struct V_33 * V_34 , char * V_13 ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_53 * V_54 = F_33 ( V_36 ) ;
struct V_15 * V_16 ;
struct V_15 * V_55 ;
char V_56 [ 32 ] ;
char * V_57 ;
V_17 ;
F_5 ( V_10 , L_12 , V_13 , V_27 -> V_30 ) ;
V_57 = strrchr ( V_13 , '-' ) ;
if ( V_57 == NULL || V_57 - V_13 > 8 ) {
F_2 ( L_13 , V_13 ) ;
RETURN ( - V_6 ) ;
}
memcpy ( V_56 , V_13 , V_57 - V_13 ) ;
strcpy ( V_56 + ( V_57 - V_13 ) , L_14 ) ;
V_55 = F_20 ( V_56 , NULL ) ;
if ( V_55 == NULL ) {
V_55 = F_23 ( V_34 , V_56 ,
V_8 , NULL , NULL ) ;
if ( F_38 ( V_55 ) ) {
F_2 ( L_15 , V_56 ) ;
RETURN ( F_39 ( V_55 ) ) ;
}
}
V_16 = F_23 ( V_34 , V_13 , V_7 , V_27 , V_36 ) ;
if ( F_38 ( V_16 ) ) {
F_2 ( L_16 , V_13 ) ;
F_12 ( V_55 ) ;
RETURN ( F_39 ( V_16 ) ) ;
}
V_16 -> V_24 = V_55 ;
F_8 ( V_54 -> V_58 ) ;
if ( ! ( V_54 -> V_58 -> V_59 & V_60 ) ) {
struct V_15 * V_61 ;
* strrchr ( V_56 , '-' ) = 0 ;
V_61 = F_32 ( V_34 , V_56 , V_27 , V_36 ) ;
if ( F_38 ( V_61 ) ) {
F_12 ( V_16 ) ;
RETURN ( F_39 ( V_61 ) ) ;
}
V_16 -> V_23 = V_61 ;
}
RETURN ( 0 ) ;
}
static int F_40 ( char * V_13 , struct V_26 * V_27 )
{
struct V_15 * V_16 ;
struct V_15 * V_24 = NULL ;
struct V_15 * V_23 = NULL ;
int V_37 = 0 ;
V_17 ;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( V_16 == NULL )
RETURN ( - V_51 ) ;
F_41 ( & V_16 -> V_41 ) ;
if ( F_42 ( V_16 -> V_32 ) ) {
F_43 ( & V_16 -> V_41 ) ;
F_12 ( V_16 ) ;
RETURN ( V_37 ) ;
}
V_16 -> V_32 = 1 ;
V_23 = V_16 -> V_23 ;
V_16 -> V_23 = NULL ;
F_43 ( & V_16 -> V_41 ) ;
if ( V_23 ) {
F_41 ( & V_23 -> V_41 ) ;
V_23 -> V_32 = 1 ;
F_43 ( & V_23 -> V_41 ) ;
F_12 ( V_23 ) ;
}
F_21 ( & V_21 ) ;
V_24 = V_16 -> V_24 ;
V_16 -> V_24 = NULL ;
F_15 ( & V_21 ) ;
if ( V_24 )
F_12 ( V_24 ) ;
F_12 ( V_16 ) ;
F_12 ( V_16 ) ;
F_5 ( V_10 , L_17 , V_13 ? V_13 : L_18 ,
V_37 ) ;
RETURN ( V_37 ) ;
}
int F_44 ( struct V_62 * V_63 , void * V_64 )
{
struct V_33 * V_34 = V_64 ;
struct V_65 * V_66 = V_34 -> V_67 . V_68 . V_69 ;
struct V_70 * V_71 = & V_66 -> V_72 ;
struct V_15 * V_16 ;
V_17 ;
F_45 ( V_63 , L_19 ,
F_46 ( V_71 , V_73 ) ? L_20 : L_21 ) ;
F_45 ( V_63 , L_22 ) ;
F_21 ( & V_21 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_16 -> V_23 == NULL )
continue;
F_45 ( V_63 , L_23 ,
V_16 -> V_20 ,
V_16 -> V_23 -> V_31 . V_42 ) ;
}
F_15 ( & V_21 ) ;
RETURN ( 0 ) ;
}
static void F_47 ( struct V_15 * V_16 )
{
V_17 ;
F_8 ( F_11 ( & V_16 -> V_18 ) > 0 ) ;
F_48 ( & V_16 -> V_25 -> V_74 -> V_67 . V_68 . V_75 ) ;
if ( V_16 -> V_25 -> V_74 -> V_67 . V_68 . V_76 != 0 ) {
F_5 ( V_10 , L_24 , V_16 -> V_20 ) ;
F_31 ( V_16 -> V_25 -> V_74 , V_16 ) ;
} else {
F_5 ( V_10 , L_25 ,
V_16 -> V_20 ) ;
}
F_49 ( & V_16 -> V_25 -> V_74 -> V_67 . V_68 . V_75 ) ;
EXIT ;
}
static int F_50 ( void * V_64 )
{
int V_37 = 0 ;
V_17 ;
F_5 ( V_10 , L_26 ) ;
F_21 ( & V_21 ) ;
V_77 |= V_78 ;
while ( 1 ) {
struct V_79 V_80 ;
struct V_15 * V_16 , * V_81 ;
int rand = F_51 () & V_82 ;
int V_83 = ! ! ( V_77 & V_84 ) ;
int V_85 ;
V_77 &= ~ ( V_86 | V_87 ) ;
F_15 ( & V_21 ) ;
V_85 = V_88 * V_89 ;
V_85 += rand * V_89 / 100 ;
V_80 = F_52 ( V_85 , NULL , NULL ) ;
F_53 ( V_90 , V_77 & V_84 , & V_80 ) ;
V_81 = NULL ;
F_21 ( & V_21 ) ;
F_22 (cld, &config_llog_list,
cld_list_chain) {
if ( ! V_16 -> V_91 )
continue;
F_15 ( & V_21 ) ;
F_8 ( F_11 ( & V_16 -> V_18 ) > 0 ) ;
if ( V_81 )
F_12 ( V_81 ) ;
V_81 = V_16 ;
V_16 -> V_91 = 0 ;
if ( F_54 ( ! V_83 ) )
F_47 ( V_16 ) ;
F_21 ( & V_21 ) ;
}
F_15 ( & V_21 ) ;
if ( V_81 )
F_12 ( V_81 ) ;
if ( F_42 ( V_83 ) ) {
F_21 ( & V_21 ) ;
break;
}
V_80 = (struct V_79 ) { 0 } ;
F_53 ( V_90 , V_77 & ( V_86 | V_84 ) ,
& V_80 ) ;
F_21 ( & V_21 ) ;
}
V_77 &= ~ V_78 ;
F_15 ( & V_21 ) ;
F_55 ( & V_92 ) ;
F_5 ( V_10 , L_27 ) ;
RETURN ( V_37 ) ;
}
static void F_56 ( struct V_15 * V_16 )
{
V_17 ;
F_5 ( V_19 , L_28 ,
V_16 -> V_20 , F_11 ( & V_16 -> V_18 ) ,
V_16 -> V_32 , V_77 ) ;
F_8 ( F_11 ( & V_16 -> V_18 ) > 0 ) ;
F_41 ( & V_16 -> V_41 ) ;
if ( V_16 -> V_32 || V_16 -> V_91 ) {
F_43 ( & V_16 -> V_41 ) ;
V_93 ;
}
F_9 ( V_16 ) ;
V_16 -> V_91 = 1 ;
F_43 ( & V_16 -> V_41 ) ;
F_21 ( & V_21 ) ;
if ( V_77 & V_84 ) {
F_15 ( & V_21 ) ;
V_16 -> V_91 = 0 ;
F_12 ( V_16 ) ;
} else {
V_77 |= V_86 ;
F_15 ( & V_21 ) ;
F_57 ( & V_90 ) ;
}
EXIT ;
}
static int F_58 ( struct V_33 * V_34 , struct V_35 * V_36 ,
struct V_94 * V_95 )
{
struct V_96 V_97 ;
struct V_53 * V_54 = F_33 ( V_36 ) ;
struct V_98 * V_68 = & V_34 -> V_67 . V_68 ;
struct V_99 * V_99 ;
char * V_100 ;
int V_101 = 0 ;
V_17 ;
F_8 ( V_54 ) ;
F_8 ( V_54 -> V_102 == V_95 ) ;
F_59 ( & V_68 -> V_103 ) ;
F_60 () ;
V_34 -> V_104 = F_61 ( V_54 -> V_105 ) ;
if ( F_38 ( V_34 -> V_104 ) ) {
F_62 ( & V_68 -> V_103 ) ;
F_2 ( L_29 , V_54 -> V_105 ,
V_34 -> V_48 , F_39 ( V_34 -> V_104 ) ) ;
RETURN ( F_39 ( V_34 -> V_104 ) ) ;
}
V_68 -> V_106 = V_95 ;
V_101 = F_63 ( V_34 , V_95 -> V_107 ) ;
if ( V_101 )
GOTO ( V_108 , V_101 ) ;
F_64 ( & V_34 -> V_109 ) ;
V_34 -> V_109 . V_110 = V_95 ;
V_34 -> V_109 . V_111 = V_95 -> V_112 ;
V_34 -> V_109 . V_113 = F_65 () ;
F_66 ( & V_97 , & V_34 -> V_109 , NULL ) ;
V_99 = F_67 ( V_114 , F_68 ( V_115 -> V_113 ) ,
strlen ( V_114 ) ) ;
F_69 ( & V_97 , & V_34 -> V_109 , NULL ) ;
if ( F_38 ( V_99 ) ) {
V_101 = F_39 ( V_99 ) ;
F_2 ( L_30 ,
V_114 , V_101 ) ;
GOTO ( V_108 , V_101 ) ;
}
V_68 -> V_116 = V_99 ;
F_70 ( V_34 , L_31 , V_34 ) ;
V_100 = F_71 ( V_34 , V_95 -> V_107 ) ;
if ( V_100 )
F_5 ( V_10 , L_32 , V_100 ) ;
RETURN ( 0 ) ;
V_108:
F_72 ( V_34 -> V_104 ) ;
V_34 -> V_104 = NULL ;
V_68 -> V_106 = NULL ;
F_62 ( & V_68 -> V_103 ) ;
RETURN ( V_101 ) ;
}
static int F_73 ( struct V_33 * V_34 )
{
struct V_98 * V_68 = & V_34 -> V_67 . V_68 ;
int V_37 = 0 ;
V_17 ;
F_8 ( V_68 -> V_106 != NULL ) ;
if ( V_68 -> V_116 != NULL ) {
struct V_96 V_97 ;
F_66 ( & V_97 , & V_34 -> V_109 , NULL ) ;
F_74 ( V_68 -> V_116 ) ;
V_68 -> V_116 = NULL ;
F_69 ( & V_97 , & V_34 -> V_109 , NULL ) ;
F_75 ( V_34 , L_31 , V_34 ) ;
}
V_68 -> V_106 = NULL ;
if ( V_34 -> V_104 )
F_72 ( V_34 -> V_104 ) ;
F_62 ( & V_68 -> V_103 ) ;
RETURN ( V_37 ) ;
}
static int F_76 ( struct V_33 * V_34 , enum V_117 V_118 )
{
int V_37 = 0 ;
V_17 ;
switch ( V_118 ) {
case V_119 :
break;
case V_120 :
if ( F_77 ( & V_121 ) ) {
int V_122 ;
F_21 ( & V_21 ) ;
V_122 = V_77 & V_78 ;
if ( V_122 )
V_77 |= V_84 ;
F_15 ( & V_21 ) ;
if ( V_122 ) {
F_57 ( & V_90 ) ;
F_78 ( & V_92 ) ;
}
}
F_79 ( V_34 ) ;
V_37 = F_80 ( V_34 , 0 ) ;
if ( V_37 != 0 )
F_2 ( L_33 ) ;
break;
}
RETURN ( V_37 ) ;
}
static int F_81 ( struct V_33 * V_34 )
{
struct V_98 * V_68 = & V_34 -> V_67 . V_68 ;
int V_37 ;
V_17 ;
F_8 ( V_68 -> V_106 == NULL ) ;
if ( V_34 -> V_123 -> V_124 <= 1 )
F_82 () ;
F_83 ( V_34 ) ;
F_84 () ;
V_37 = F_85 ( V_34 ) ;
RETURN ( V_37 ) ;
}
static int F_86 ( struct V_33 * V_34 , struct V_125 * V_52 )
{
struct V_126 V_127 ;
int V_37 ;
V_17 ;
F_87 () ;
V_37 = F_88 ( V_34 , V_52 ) ;
if ( V_37 )
GOTO ( V_128 , V_37 ) ;
V_37 = F_89 ( V_34 , & V_34 -> V_129 , V_34 , NULL ) ;
if ( V_37 ) {
F_2 ( L_34 ) ;
GOTO ( V_130 , V_37 ) ;
}
F_90 ( & V_127 ) ;
F_91 ( V_34 , V_127 . V_131 ) ;
F_92 ( V_34 ) ;
if ( F_93 ( & V_121 ) == 1 ) {
V_77 = 0 ;
F_94 ( & V_90 ) ;
V_37 = F_39 ( F_95 ( F_50 , NULL ,
L_35 ) ) ;
if ( F_96 ( V_37 ) ) {
F_2 ( L_36
L_37 ,
V_34 -> V_48 , V_37 ) ;
GOTO ( V_130 , V_37 ) ;
}
V_37 = 0 ;
}
RETURN ( V_37 ) ;
V_130:
F_85 ( V_34 ) ;
V_128:
F_84 () ;
RETURN ( V_37 ) ;
}
static int F_97 ( struct V_132 * V_133 , struct V_134 * V_135 ,
void * V_64 , int V_136 )
{
struct V_137 V_138 ;
struct V_15 * V_16 = (struct V_15 * ) V_64 ;
int V_37 = 0 ;
V_17 ;
switch ( V_136 ) {
case V_139 :
F_98 ( V_133 , L_38 ) ;
F_99 ( V_133 , & V_138 ) ;
V_37 = F_100 ( & V_138 , V_140 ) ;
break;
case V_141 :
F_98 ( V_133 , L_39 ) ;
F_5 ( V_10 , L_40 V_11 L_5 ,
V_133 -> V_142 -> V_143 . V_1 [ 0 ] ,
( char * ) & V_133 -> V_142 -> V_143 . V_1 [ 0 ] ) ;
if ( ! V_16 ) {
F_5 ( V_19 , L_41 ) ;
break;
}
F_8 ( F_11 ( & V_16 -> V_18 ) > 0 ) ;
if ( V_16 -> V_32 ) {
F_5 ( V_10 , L_42 ,
V_16 -> V_20 ) ;
F_12 ( V_16 ) ;
break;
}
if ( ! V_133 -> V_144 ||
! V_133 -> V_144 -> V_74 -> V_67 . V_68 . V_76 ) {
F_5 ( V_10 , L_43 ,
V_16 -> V_20 ) ;
F_12 ( V_16 ) ;
break;
}
F_56 ( V_16 ) ;
F_12 ( V_16 ) ;
break;
default:
F_4 () ;
}
RETURN ( V_37 ) ;
}
static int F_101 ( struct V_145 * exp ,
struct V_146 * V_147 )
{
struct V_148 * V_149 ;
struct V_146 * V_150 , * V_151 ;
int V_37 ;
V_17 ;
V_149 = F_102 ( F_103 ( exp ) ,
& V_152 , V_153 ,
V_154 ) ;
if ( ! V_149 )
RETURN ( - V_38 ) ;
V_150 = F_104 ( & V_149 -> V_155 , & V_156 ) ;
if ( ! V_150 ) {
F_105 ( V_149 ) ;
RETURN ( - V_38 ) ;
}
memcpy ( V_150 , V_147 , sizeof( * V_150 ) ) ;
F_106 ( V_149 ) ;
V_149 -> V_157 = V_158 ;
V_37 = F_107 ( V_149 ) ;
if ( ! V_37 ) {
V_151 = F_108 ( & V_149 -> V_155 , & V_156 ) ;
memcpy ( V_147 , V_151 , sizeof( * V_151 ) ) ;
}
F_105 ( V_149 ) ;
RETURN ( V_37 ) ;
}
static int F_109 ( struct V_145 * exp , struct V_159 * V_160 ,
T_2 type , T_3 * V_161 , T_2 V_162 ,
T_1 * V_163 , void * V_164 , void * V_165 , void * V_166 ,
void * V_64 , T_2 V_167 , void * V_168 ,
struct V_137 * V_138 )
{
struct V_15 * V_16 = (struct V_15 * ) V_64 ;
struct V_169 V_170 = { type , V_162 , F_97 ,
V_171 , NULL , NULL , NULL } ;
struct V_148 * V_149 ;
int V_172 = F_16 ( V_16 ) ;
int V_37 ;
V_17 ;
F_5 ( V_10 , L_44 V_11 L_45 , V_16 -> V_20 ,
V_16 -> V_49 . V_1 [ 0 ] ) ;
V_149 = F_102 ( F_103 ( exp ) ,
& V_173 , V_174 ,
V_175 ) ;
if ( V_149 == NULL )
RETURN ( - V_38 ) ;
F_110 ( & V_149 -> V_155 , & V_176 , V_177 , 0 ) ;
F_106 ( V_149 ) ;
if ( V_16 -> V_31 . V_44 ) {
struct V_53 * V_54 = F_33 ( V_16 -> V_31 . V_44 ) ;
if ( V_54 && F_36 ( V_54 ) )
V_172 = 1 ;
}
V_149 -> V_157 = V_172 ? 5 : V_178 ;
V_37 = F_111 ( exp , & V_149 , & V_170 , & V_16 -> V_49 , NULL , V_163 ,
NULL , 0 , V_179 , V_138 , 0 ) ;
F_105 ( V_149 ) ;
RETURN ( V_37 ) ;
}
static int F_112 ( struct V_145 * exp , struct V_159 * V_180 ,
T_2 V_162 , struct V_137 * V_138 )
{
V_17 ;
F_113 ( V_138 , V_162 ) ;
RETURN ( 0 ) ;
}
static void F_114 ( struct V_33 * V_181 )
{
F_21 ( & V_21 ) ;
V_77 |= V_86 ;
F_15 ( & V_21 ) ;
F_57 ( & V_90 ) ;
}
static int F_115 ( struct V_145 * exp ,
struct V_182 * V_183 )
{
struct V_148 * V_149 ;
struct V_182 * V_184 , * V_185 ;
int V_37 ;
V_17 ;
V_149 = F_102 ( F_103 ( exp ) ,
& V_186 , V_153 ,
V_187 ) ;
if ( V_149 == NULL )
RETURN ( - V_38 ) ;
V_184 = F_104 ( & V_149 -> V_155 , & V_188 ) ;
if ( ! V_184 ) {
F_105 ( V_149 ) ;
RETURN ( - V_38 ) ;
}
memcpy ( V_184 , V_183 , sizeof( * V_184 ) ) ;
F_106 ( V_149 ) ;
F_5 ( V_10 , L_46 , V_183 -> V_189 ) ;
V_149 -> V_157 = V_190 ;
V_37 = F_107 ( V_149 ) ;
if ( ! V_37 ) {
V_185 = F_108 ( & V_149 -> V_155 ,
& V_188 ) ;
memcpy ( V_183 , V_185 , sizeof( * V_185 ) ) ;
F_5 ( V_10 , L_47 ,
V_183 -> V_189 , V_183 -> V_191 ) ;
}
F_105 ( V_149 ) ;
RETURN ( V_37 ) ;
}
int F_116 ( const struct V_192 * V_193 , struct V_145 * exp ,
T_4 V_194 , void * V_195 , T_4 V_196 ,
void * V_197 , struct V_198 * V_199 )
{
int V_37 = - V_6 ;
V_17 ;
if ( F_117 ( V_200 ) ) {
struct V_65 * V_66 = F_103 ( exp ) ;
int V_201 ;
if ( V_196 != sizeof( int ) )
RETURN ( - V_6 ) ;
V_201 = * ( int * ) V_197 ;
F_5 ( V_10 , L_48 ,
V_66 -> V_202 -> V_48 , V_201 ,
V_66 -> V_203 , V_66 -> V_204 ,
V_66 -> V_205 , V_66 -> V_202 -> V_206 ,
F_118 ( V_66 -> V_207 ) ) ;
if ( ( V_66 -> V_207 != V_208 &&
V_66 -> V_207 != V_209 ) || V_201 > 1 )
F_119 ( V_66 ) ;
RETURN ( 0 ) ;
}
if ( F_117 ( V_210 ) ) {
struct V_182 * V_183 ;
if ( V_196 != sizeof( struct V_182 ) )
RETURN ( - V_6 ) ;
V_183 = (struct V_182 * ) V_197 ;
F_5 ( V_10 , L_49 ,
V_183 -> V_189 , V_183 -> V_211 ) ;
V_37 = F_115 ( exp , V_183 ) ;
RETURN ( V_37 ) ;
}
if ( F_117 ( V_212 ) ) {
struct V_35 * V_36 = (struct V_35 * ) V_197 ;
struct V_53 * V_54 ;
if ( V_196 != sizeof( struct V_35 ) )
RETURN ( - V_6 ) ;
V_54 = F_33 ( V_36 ) ;
V_37 = F_58 ( exp -> V_74 , V_36 , V_54 -> V_102 ) ;
if ( V_37 ) {
F_2 ( L_50 , V_37 ) ;
}
RETURN ( V_37 ) ;
}
if ( F_117 ( V_213 ) ) {
if ( V_196 != 0 )
RETURN ( - V_6 ) ;
V_37 = F_73 ( exp -> V_74 ) ;
if ( V_37 ) {
F_2 ( L_51 , V_37 ) ;
}
RETURN ( V_37 ) ;
}
if ( F_117 ( V_214 ) ) {
struct V_146 * V_147 ;
V_147 = (struct V_146 * ) V_197 ;
V_37 = F_101 ( exp , V_147 ) ;
RETURN ( V_37 ) ;
}
if ( F_117 ( V_215 ) ) {
struct V_98 * V_68 = & exp -> V_74 -> V_67 . V_68 ;
struct V_216 V_217 ;
if ( V_196 == 0 ) {
if ( V_68 -> V_218 . V_219 != V_220 )
RETURN ( 0 ) ;
V_197 = L_52 ;
V_196 = 4 ;
}
V_37 = F_120 ( V_197 , & V_217 ) ;
if ( V_37 ) {
F_2 ( L_53 ,
( char * ) V_197 ) ;
RETURN ( V_37 ) ;
}
if ( V_68 -> V_218 . V_219 == V_220 ) {
V_68 -> V_218 = V_217 ;
} else if ( memcmp ( & V_68 -> V_218 , & V_217 ,
sizeof( V_217 ) ) != 0 ) {
char V_221 [ 20 ] ;
F_121 ( & V_68 -> V_218 ,
V_221 , sizeof( V_221 ) ) ;
F_122 ( L_54
L_55 ,
( char * ) V_197 , V_221 ) ;
V_37 = - V_222 ;
}
RETURN ( V_37 ) ;
}
RETURN ( V_37 ) ;
}
static int F_123 ( const struct V_192 * V_193 , struct V_145 * exp ,
T_2 V_194 , void * V_195 , T_2 * V_196 , void * V_197 ,
struct V_159 * V_181 )
{
int V_37 = - V_6 ;
if ( F_117 ( V_223 ) ) {
struct V_65 * V_66 = F_103 ( exp ) ;
struct V_70 * V_64 = V_197 ;
if ( * V_196 == sizeof( * V_64 ) ) {
* V_64 = V_66 -> V_72 ;
V_37 = 0 ;
}
}
return V_37 ;
}
static int F_124 ( struct V_33 * V_34 ,
struct V_65 * V_66 ,
enum V_224 V_225 )
{
int V_37 = 0 ;
F_8 ( V_66 -> V_202 == V_34 ) ;
F_5 ( V_10 , L_56 , V_225 ) ;
switch ( V_225 ) {
case V_226 :
if ( F_46 ( & V_66 -> V_72 , V_73 ) )
F_125 () ;
break;
case V_227 :
break;
case V_228 : {
struct V_229 * V_230 = V_34 -> V_231 ;
F_126 ( V_230 , V_232 ) ;
break;
}
case V_233 :
F_5 ( V_19 , L_57 , V_34 -> V_48 ) ;
V_34 -> V_234 = 0 ;
F_114 ( V_34 ) ;
if ( F_46 ( & V_66 -> V_72 , V_73 ) )
F_127 () ;
break;
case V_235 :
break;
case V_236 :
case V_237 :
break;
default:
F_2 ( L_58 , V_225 ) ;
F_4 () ;
}
RETURN ( V_37 ) ;
}
static int F_128 ( struct V_33 * V_34 , struct V_238 * V_239 ,
struct V_33 * V_240 , int * V_241 )
{
struct V_242 * V_243 ;
int V_37 ;
V_17 ;
F_8 ( V_239 == & V_34 -> V_129 ) ;
V_37 = F_129 ( NULL , V_34 , V_239 , V_244 , V_240 ,
& V_245 ) ;
if ( V_37 )
GOTO ( V_246 , V_37 ) ;
V_243 = F_130 ( V_239 , V_244 ) ;
if ( ! V_243 )
GOTO ( V_246 , V_37 = - V_247 ) ;
F_131 ( V_243 ) ;
F_132 ( V_243 ) ;
RETURN ( 0 ) ;
V_246:
V_243 = F_133 ( V_34 , V_248 ) ;
if ( V_243 )
F_134 ( NULL , V_243 ) ;
RETURN ( V_37 ) ;
}
static int F_135 ( struct V_33 * V_34 , int V_249 )
{
struct V_242 * V_243 ;
V_17 ;
V_243 = F_133 ( V_34 , V_244 ) ;
if ( V_243 )
F_134 ( NULL , V_243 ) ;
V_243 = F_133 ( V_34 , V_248 ) ;
if ( V_243 )
F_134 ( NULL , V_243 ) ;
RETURN ( 0 ) ;
}
static int F_136 ( struct V_33 * V_250 ,
struct V_15 * V_16 ,
T_1 V_251 ,
void * V_64 , int V_252 , bool V_253 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_53 * V_54 = F_33 ( V_27 -> V_44 ) ;
struct V_254 * V_255 ;
struct V_125 * V_52 ;
struct V_256 V_257 ;
T_5 V_258 = 0 ;
char * V_259 ;
char * V_260 ;
int V_261 ;
int V_262 ;
int V_37 = 0 ;
int V_263 = 0 ;
V_17 ;
F_8 ( V_27 -> V_30 != NULL ) ;
F_8 ( V_27 -> V_44 == V_27 -> V_30 ) ;
F_24 ( V_259 , V_264 ) ;
if ( V_259 == NULL )
RETURN ( - V_38 ) ;
if ( ! F_36 ( V_54 ) ) {
V_262 = snprintf ( V_259 , V_264 , L_59 , V_27 -> V_30 ) ;
if ( V_262 >= V_264 ) {
F_19 ( V_259 , V_264 ) ;
return - V_265 ;
}
} else {
F_8 ( F_35 ( V_54 ) ) ;
V_37 = F_137 ( V_54 -> V_266 , V_259 , NULL ,
V_264 ) ;
if ( V_37 ) {
F_19 ( V_259 , V_264 ) ;
RETURN ( - V_6 ) ;
}
V_262 = strlen ( V_259 ) ;
}
++ V_262 ;
V_260 = V_259 + V_262 ;
V_261 = V_264 - V_262 ;
while ( V_252 > 0 ) {
int V_267 = sizeof( * V_255 ) ;
int V_268 ;
struct V_33 * V_34 ;
char * V_269 ;
char * V_270 ;
char * V_271 ;
char * V_272 ;
V_37 = - V_6 ;
if ( V_252 < sizeof( * V_255 ) )
break;
V_255 = ( F_138 ( V_255 ) ) ( V_64 + V_263 ) ;
if ( V_255 -> V_273 != 0 )
break;
if ( V_255 -> V_274 == 0 )
break;
if ( V_255 -> V_275 != sizeof( V_276 ) )
break;
V_267 += V_255 -> V_274 * V_255 -> V_275 ;
if ( V_252 < V_267 )
break;
if ( V_253 )
F_139 ( V_255 ) ;
if ( V_255 -> V_277 > V_264 ) {
F_2 ( L_60 , V_255 -> V_277 ) ;
break;
}
if ( V_255 -> V_277 < V_267 )
break;
V_263 += V_255 -> V_277 ;
V_252 -= V_255 -> V_277 ;
if ( V_252 < 0 )
break;
if ( V_255 -> V_278 > V_251 ) {
F_2 ( L_61 ,
V_255 -> V_278 , V_251 ) ;
break;
}
if ( V_258 >= V_255 -> V_278 ) {
F_2 ( L_62 ,
V_258 , V_255 -> V_278 ) ;
break;
}
V_258 = V_255 -> V_278 ;
V_268 = V_255 -> V_279 == V_280 ;
memset ( V_260 , 0 , V_261 ) ;
V_269 = V_260 ;
V_262 = 0 ;
strcpy ( V_269 , V_16 -> V_20 ) ;
V_270 = strrchr ( V_269 , '-' ) ;
if ( V_270 == NULL ) {
F_2 ( L_63 ,
V_250 -> V_48 , V_269 ) ;
break;
}
V_262 = V_270 - V_269 ;
V_269 [ V_262 ] = 0 ;
V_262 += sprintf ( V_269 + V_262 , L_64 ,
V_268 ? L_65 : L_66 , V_255 -> V_281 ) ;
V_270 = V_268 ? L_67 : L_68 ,
V_262 += sprintf ( V_269 + V_262 , L_69 , V_270 , V_259 ) ;
F_140 ( & V_257 , V_269 ) ;
V_34 = F_141 ( V_269 ) ;
if ( V_34 == NULL ) {
F_5 ( V_19 , L_70 ,
V_250 -> V_48 , V_269 ) ;
V_37 = 0 ;
continue;
}
++ V_262 ;
V_271 = V_260 + V_262 ;
V_262 += sprintf ( V_271 , L_71 , V_270 , L_72 ) ;
V_272 = V_260 + V_262 ;
F_48 ( & V_34 -> V_67 . V_68 . V_75 ) ;
if ( V_34 -> V_67 . V_68 . V_69 == NULL ) {
F_49 ( & V_34 -> V_67 . V_68 . V_75 ) ;
V_37 = 0 ;
continue;
}
V_37 = F_142 ( V_34 -> V_67 . V_68 . V_69 ,
V_255 -> V_67 . V_282 [ 0 ] ,
(struct V_283 * ) V_272 ) ;
F_49 ( & V_34 -> V_67 . V_68 . V_75 ) ;
if ( V_37 < 0 ) {
F_2 ( L_73 ,
F_143 ( V_255 -> V_67 . V_282 [ 0 ] ) ) ;
break;
}
F_5 ( V_19 , L_74 ,
V_272 , F_143 ( V_255 -> V_67 . V_282 [ 0 ] ) ) ;
V_262 += strlen ( V_272 ) ;
V_262 += sprintf ( V_260 + V_262 , L_75 , V_255 -> V_284 ) ;
F_8 ( V_262 < V_261 ) ;
F_144 ( & V_257 , 1 , V_271 ) ;
V_37 = - V_38 ;
V_52 = F_145 ( V_285 , & V_257 ) ;
if ( V_52 == NULL ) {
F_2 ( L_76 ) ;
break;
}
F_5 ( V_19 , L_77 V_286 L_4 V_286 L_78 ,
V_258 , V_251 , V_269 , V_271 ) ;
V_37 = F_146 ( V_52 ) ;
F_147 ( V_52 ) ;
if ( V_37 )
F_5 ( V_19 , L_79 ,
V_269 , V_37 ) ;
}
F_19 ( V_259 , V_264 ) ;
RETURN ( V_37 ) ;
}
static int F_148 ( struct V_33 * V_34 ,
struct V_15 * V_16 )
{
struct V_148 * V_149 = NULL ;
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_287 * V_288 ;
struct V_289 * V_290 ;
struct V_291 * V_135 ;
struct V_292 * * V_293 ;
int V_294 ;
bool V_295 = true ;
bool V_253 = false ;
int V_296 ;
int V_297 ;
int V_37 ;
V_17 ;
V_294 = V_298 ;
if ( V_27 -> V_42 == 0 )
V_294 = V_299 ;
F_24 ( V_293 , sizeof( * V_293 ) * V_294 ) ;
if ( V_293 == NULL )
GOTO ( V_246 , V_37 = - V_38 ) ;
for ( V_296 = 0 ; V_296 < V_294 ; V_296 ++ ) {
V_293 [ V_296 ] = F_149 ( V_300 ) ;
if ( V_293 [ V_296 ] == NULL )
GOTO ( V_246 , V_37 = - V_38 ) ;
}
V_301:
F_8 ( F_150 ( V_16 ) ) ;
F_8 ( F_151 ( & V_16 -> V_41 ) ) ;
V_149 = F_152 ( F_103 ( V_16 -> V_25 ) ,
& V_302 ) ;
if ( V_149 == NULL )
GOTO ( V_246 , V_37 = - V_38 ) ;
V_37 = F_153 ( V_149 , V_153 , V_303 ) ;
if ( V_37 )
GOTO ( V_246 , V_37 ) ;
V_288 = F_104 ( & V_149 -> V_155 , & V_304 ) ;
F_8 ( V_288 != NULL ) ;
F_8 ( sizeof( V_288 -> V_305 ) > strlen ( V_16 -> V_20 ) ) ;
if ( F_154 ( V_288 -> V_305 , V_16 -> V_20 , sizeof( V_288 -> V_305 ) )
>= sizeof( V_288 -> V_305 ) )
GOTO ( V_246 , V_37 = - V_265 ) ;
V_288 -> V_306 = V_27 -> V_42 + 1 ;
V_288 -> V_307 = V_16 -> V_45 ;
V_288 -> V_308 = V_309 ;
V_288 -> V_310 = V_294 ;
V_135 = F_155 ( V_149 , V_294 , 1 , V_311 ,
V_312 ) ;
if ( V_135 == NULL )
GOTO ( V_246 , V_37 = - V_38 ) ;
for ( V_296 = 0 ; V_296 < V_294 ; V_296 ++ )
F_156 ( V_135 , V_293 [ V_296 ] , 0 , V_264 ) ;
F_106 ( V_149 ) ;
V_37 = F_107 ( V_149 ) ;
if ( V_37 )
GOTO ( V_246 , V_37 ) ;
V_290 = F_108 ( & V_149 -> V_155 , & V_313 ) ;
if ( V_290 -> V_314 < V_290 -> V_315 )
GOTO ( V_246 , V_37 = - V_6 ) ;
V_27 -> V_42 = V_290 -> V_315 ;
V_295 = V_290 -> V_315 == V_290 -> V_314 ;
F_5 ( V_19 , L_80 V_286 L_81 ,
V_290 -> V_315 , V_295 == false ) ;
V_297 = F_157 ( V_149 , V_149 -> V_316 , 0 ) ;
if ( V_297 < 0 )
GOTO ( V_246 , V_37 = V_297 ) ;
if ( V_297 > V_294 << V_309 )
GOTO ( V_246 , V_37 = - V_6 ) ;
if ( V_297 == 0 ) {
if ( ! V_295 )
V_37 = - V_6 ;
GOTO ( V_246 , V_37 ) ;
}
V_253 = ! ! F_158 ( V_149 ) ;
#if V_317 < F_159 ( 3 , 2 , 50 , 0 )
if ( F_42 ( V_149 -> V_318 -> V_319 ) )
V_253 = ! V_253 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_296 = 0 ; V_296 < V_294 && V_297 > 0 ; V_296 ++ ) {
int V_320 ;
void * V_57 ;
V_57 = F_160 ( V_293 [ V_296 ] ) ;
V_320 = F_136 ( V_34 , V_16 , V_290 -> V_315 , V_57 ,
F_161 ( int , V_297 , V_264 ) ,
V_253 ) ;
F_162 ( V_293 [ V_296 ] ) ;
if ( V_320 < 0 ) {
F_163 ( L_82 ,
V_16 -> V_20 , V_320 ) ;
break;
}
V_297 -= V_264 ;
}
V_246:
if ( V_149 )
F_105 ( V_149 ) ;
if ( V_37 == 0 && ! V_295 )
goto V_301;
if ( V_293 ) {
for ( V_296 = 0 ; V_296 < V_294 ; V_296 ++ ) {
if ( V_293 [ V_296 ] == NULL )
break;
F_164 ( V_293 [ V_296 ] ) ;
}
F_19 ( V_293 , sizeof( * V_293 ) * V_294 ) ;
}
return V_37 ;
}
static int F_165 ( struct V_33 * V_250 ,
struct V_15 * V_16 ,
int V_321 )
{
struct V_242 * V_243 , * V_322 = NULL ;
struct V_96 * V_323 ;
struct V_53 * V_54 = NULL ;
int V_37 = 0 , V_324 = 0 ;
bool V_325 = false ;
V_17 ;
F_8 ( V_16 ) ;
F_8 ( F_151 ( & V_16 -> V_41 ) ) ;
if ( F_16 ( V_16 ) && V_321 )
RETURN ( 0 ) ;
if ( V_16 -> V_31 . V_44 )
V_54 = F_33 ( V_16 -> V_31 . V_44 ) ;
V_243 = F_133 ( V_250 , V_244 ) ;
if ( ! V_243 ) {
F_2 ( L_83 ) ;
RETURN ( - V_6 ) ;
}
F_166 ( V_323 ) ;
if ( V_323 == NULL )
RETURN ( - V_38 ) ;
V_322 = F_133 ( V_250 , V_248 ) ;
if ( V_321 ) {
GOTO ( V_326 , V_37 = - V_327 ) ;
}
if ( F_16 ( V_16 ) ) {
F_167 ( V_16 -> V_20 ) ;
V_325 = true ;
}
V_37 = F_168 ( NULL , V_243 , V_16 -> V_20 ,
& V_16 -> V_31 ) ;
EXIT ;
V_326:
F_132 ( V_243 ) ;
if ( V_322 )
F_132 ( V_322 ) ;
if ( V_324 )
F_69 ( V_323 , & V_250 -> V_109 , NULL ) ;
F_169 ( V_323 ) ;
if ( V_325 ) {
F_8 ( F_16 ( V_16 ) ) ;
F_170 ( V_16 -> V_20 ) ;
F_171 ( V_16 -> V_20 ,
strlen ( V_16 -> V_20 ) -
strlen ( L_14 ) ) ;
}
RETURN ( V_37 ) ;
}
int F_31 ( struct V_33 * V_250 , struct V_15 * V_16 )
{
struct V_137 V_138 = { 0 } ;
T_1 V_163 = V_328 ;
int V_37 = 0 , V_329 ;
V_17 ;
F_8 ( V_16 ) ;
F_41 ( & V_16 -> V_41 ) ;
if ( V_16 -> V_32 ) {
F_43 ( & V_16 -> V_41 ) ;
RETURN ( 0 ) ;
}
F_172 ( V_330 , 20 ) ;
F_5 ( V_10 , L_84 , V_16 -> V_20 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_42 + 1 ) ;
V_329 = F_109 ( V_250 -> V_67 . V_68 . V_331 , NULL , V_332 , NULL ,
V_333 , & V_163 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_138 ) ;
if ( V_329 == 0 ) {
F_9 ( V_16 ) ;
V_37 = F_173 ( & V_138 , ( void * ) V_16 ) ;
F_8 ( V_37 == 0 ) ;
} else {
F_5 ( V_10 , L_85 , V_329 ) ;
V_16 -> V_91 = 1 ;
F_9 ( V_16 ) ;
}
if ( F_150 ( V_16 ) ) {
V_37 = 0 ;
if ( V_329 == 0 )
V_37 = F_148 ( V_250 , V_16 ) ;
} else {
V_37 = F_165 ( V_250 , V_16 , V_329 != 0 ) ;
}
F_5 ( V_10 , L_86 ,
V_250 -> V_48 , V_16 -> V_20 , V_37 ? L_87 : L_88 , V_37 ) ;
F_43 ( & V_16 -> V_41 ) ;
if ( ! V_329 ) {
V_329 = F_112 ( V_250 -> V_67 . V_68 . V_331 , NULL ,
V_333 , & V_138 ) ;
if ( V_329 )
F_2 ( L_89 , V_329 ) ;
}
RETURN ( V_37 ) ;
}
static int F_174 ( struct V_33 * V_34 , T_4 V_2 , void * V_260 )
{
struct V_125 * V_52 = V_260 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_37 = 0 ;
V_17 ;
switch( V_52 -> V_334 ) {
case V_335 : {
struct V_182 * V_183 ;
if ( F_175 ( V_52 , 1 ) !=
sizeof( struct V_182 ) )
GOTO ( V_246 , V_37 = - V_6 ) ;
V_183 = (struct V_182 * ) F_176 ( V_52 , 1 ) ;
F_5 ( V_10 , L_90 ,
V_183 -> V_189 , V_183 -> V_211 ) ;
V_37 = F_115 ( V_34 -> V_67 . V_68 . V_331 , V_183 ) ;
break;
}
case V_336 :
F_2 ( L_91 ) ;
V_37 = - V_337 ;
break;
case V_338 : {
V_37 = F_177 ( V_52 ) ;
break;
}
case V_339 : {
struct V_15 * V_16 ;
struct V_35 * V_36 ;
V_13 = F_178 ( V_52 , 1 ) ;
V_27 = (struct V_26 * ) F_176 ( V_52 , 2 ) ;
V_36 = * (struct V_35 * * ) F_176 ( V_52 , 3 ) ;
F_5 ( V_10 , L_92 , V_13 ,
V_27 -> V_42 ) ;
V_37 = F_37 ( V_34 , V_13 , V_27 , V_36 ) ;
if ( V_37 )
break;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( V_16 == NULL ) {
V_37 = - V_51 ;
break;
}
V_16 -> V_31 . V_43 |= V_340 ;
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 == 0 && V_16 -> V_23 != NULL ) {
if ( F_46 ( & V_34 -> V_67 . V_68 . V_69 ->
V_72 , V_73 ) ) {
V_37 = F_31 ( V_34 , V_16 -> V_23 ) ;
} else {
struct V_15 * V_341 = V_16 -> V_23 ;
V_16 -> V_23 = NULL ;
F_12 ( V_341 ) ;
}
if ( V_37 )
F_2 ( L_93 , V_37 ) ;
}
F_12 ( V_16 ) ;
break;
}
case V_342 : {
V_13 = F_178 ( V_52 , 1 ) ;
if ( V_52 -> V_343 >= 2 )
V_27 = (struct V_26 * ) F_176 (
V_52 , 2 ) ;
V_37 = F_40 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_94 , V_52 -> V_334 ) ;
GOTO ( V_246 , V_37 = - V_6 ) ;
}
}
V_246:
RETURN ( V_37 ) ;
}
int T_6 F_179 ( void )
{
return F_180 ( & V_344 , NULL , NULL ,
V_345 , NULL ) ;
}
static void F_181 ( void )
{
F_182 ( V_345 ) ;
}
