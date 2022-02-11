static int F_1 ( char * V_1 , int V_2 , struct V_3 * V_4 ,
int type )
{
T_1 V_5 = 0 ;
if ( V_2 > sizeof( V_5 ) ) {
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
switch ( type ) {
case V_7 :
case V_8 :
V_5 = 0 ;
break;
case V_9 :
case V_10 :
V_5 = type ;
break;
default:
F_4 () ;
}
V_4 -> V_1 [ 1 ] = F_3 ( V_5 ) ;
F_5 ( V_11 , L_3 , V_1 ,
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
if ( ! V_14 )
V_2 = strlen ( V_13 ) ;
else
V_2 = V_14 - V_13 ;
return F_1 ( V_13 , V_2 , V_4 , type ) ;
}
static int F_8 ( struct V_15 * V_16 )
{
F_9 ( & V_16 -> V_17 ) ;
F_5 ( V_18 , L_4 , V_16 -> V_19 ,
F_10 ( & V_16 -> V_17 ) ) ;
return 0 ;
}
static void F_11 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_4 , V_16 -> V_19 ,
F_10 ( & V_16 -> V_17 ) ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( F_13 ( & V_16 -> V_17 , & V_20 ) ) {
F_14 ( & V_16 -> V_21 ) ;
F_15 ( & V_20 ) ;
F_5 ( V_11 , L_5 , V_16 -> V_19 ) ;
if ( V_16 -> V_22 )
F_11 ( V_16 -> V_22 ) ;
if ( V_16 -> V_23 )
F_11 ( V_16 -> V_23 ) ;
if ( V_16 -> V_24 )
F_11 ( V_16 -> V_24 ) ;
if ( F_16 ( V_16 ) )
F_17 ( V_16 -> V_19 ) ;
F_18 ( V_16 -> V_25 ) ;
F_19 ( V_16 , sizeof( * V_16 ) + strlen ( V_16 -> V_19 ) + 1 ) ;
}
}
static
struct V_15 * F_20 ( char * V_13 ,
struct V_26 * V_27 )
{
struct V_15 * V_16 ;
struct V_15 * V_28 = NULL ;
void * V_29 ;
F_12 ( V_13 != NULL ) ;
V_29 = V_27 ? V_27 -> V_30 : NULL ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_29 != V_16 -> V_31 . V_30 )
continue;
if ( strcmp ( V_13 , V_16 -> V_19 ) == 0 ) {
V_28 = V_16 ;
break;
}
}
if ( V_28 ) {
F_9 ( & V_28 -> V_17 ) ;
F_12 ( V_28 -> V_32 == 0 || F_16 ( V_28 ) == 0 ) ;
}
F_15 ( & V_20 ) ;
return V_28 ;
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
F_5 ( V_11 , L_6 , V_13 ,
V_27 ? V_27 -> V_30 : NULL ) ;
F_24 ( V_16 , sizeof( * V_16 ) + strlen ( V_13 ) + 1 ) ;
if ( ! V_16 )
return F_25 ( - V_38 ) ;
strcpy ( V_16 -> V_19 , V_13 ) ;
if ( V_27 )
V_16 -> V_31 = * V_27 ;
else
V_16 -> V_31 . V_39 = V_40 ;
F_26 ( & V_16 -> V_41 ) ;
V_16 -> V_31 . V_42 = 0 ;
V_16 -> V_31 . V_43 = 0 ;
V_16 -> V_31 . V_44 = V_36 ;
V_16 -> V_45 = type ;
F_27 ( & V_16 -> V_17 , 1 ) ;
V_16 -> V_25 = F_28 ( V_34 -> V_46 ) ;
if ( F_16 ( V_16 ) ) {
F_29 ( V_13 ) ;
V_16 -> V_31 . V_47 = V_34 -> V_48 ;
}
V_37 = F_7 ( V_13 , & V_16 -> V_49 , type ) ;
F_21 ( & V_20 ) ;
F_30 ( & V_16 -> V_21 , & V_50 ) ;
F_15 ( & V_20 ) ;
if ( V_37 ) {
F_11 ( V_16 ) ;
return F_25 ( V_37 ) ;
}
if ( F_16 ( V_16 ) ) {
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 && V_37 != - V_51 )
F_2 ( L_7 , V_37 ) ;
}
return V_16 ;
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
F_12 ( strlen ( V_12 ) < sizeof( V_13 ) / 2 ) ;
strcpy ( V_13 , V_12 ) ;
if ( F_36 ( V_54 ) ) {
F_12 ( V_52 . V_30 == NULL ) ;
V_52 . V_30 = V_36 ;
strcat ( V_13 , L_8 ) ;
} else {
F_12 ( V_52 . V_30 != NULL ) ;
strcat ( V_13 , L_9 ) ;
}
V_16 = F_23 ( V_34 , V_13 , V_9 , & V_52 , V_36 ) ;
return V_16 ;
}
static struct V_15 * F_37 ( struct V_33 * V_34 ,
struct V_26 * V_27 , struct V_35 * V_36 )
{
struct V_26 V_52 = * V_27 ;
struct V_15 * V_16 ;
V_52 . V_30 = V_36 ;
V_16 = F_23 ( V_34 , V_55 , V_10 ,
& V_52 , V_36 ) ;
return V_16 ;
}
static int F_38 ( struct V_33 * V_34 , char * V_13 ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_53 * V_54 = F_33 ( V_36 ) ;
struct V_15 * V_16 ;
struct V_15 * V_56 ;
struct V_15 * V_57 ;
char V_58 [ 32 ] ;
char * V_59 ;
int V_37 ;
F_5 ( V_11 , L_10 , V_13 , V_27 -> V_30 ) ;
V_59 = strrchr ( V_13 , '-' ) ;
if ( V_59 == NULL || V_59 - V_13 > 8 ) {
F_2 ( L_11 , V_13 ) ;
return - V_6 ;
}
memcpy ( V_58 , V_13 , V_59 - V_13 ) ;
strcpy ( V_58 + ( V_59 - V_13 ) , L_12 ) ;
V_56 = F_20 ( V_58 , NULL ) ;
if ( V_56 == NULL ) {
V_56 = F_23 ( V_34 , V_58 ,
V_8 , NULL , NULL ) ;
if ( F_39 ( V_56 ) ) {
F_2 ( L_13 , V_58 ) ;
GOTO ( V_60 , V_37 = F_40 ( V_56 ) ) ;
}
}
V_57 = F_37 ( V_34 , V_27 , V_36 ) ;
if ( F_39 ( V_57 ) ) {
V_37 = F_40 ( V_57 ) ;
F_2 ( L_14 ,
V_34 -> V_48 , V_37 ) ;
GOTO ( V_61 , V_37 ) ;
}
V_16 = F_23 ( V_34 , V_13 , V_7 , V_27 , V_36 ) ;
if ( F_39 ( V_16 ) ) {
F_2 ( L_15 , V_13 ) ;
GOTO ( V_62 , V_37 = F_40 ( V_16 ) ) ;
}
V_16 -> V_23 = V_56 ;
V_16 -> V_24 = V_57 ;
F_12 ( V_54 -> V_63 ) ;
if ( ! ( V_54 -> V_63 -> V_64 & V_65 ) ) {
struct V_15 * V_66 ;
* strrchr ( V_58 , '-' ) = 0 ;
V_66 = F_32 ( V_34 , V_58 , V_27 , V_36 ) ;
if ( F_39 ( V_66 ) )
GOTO ( V_67 , V_37 = F_40 ( V_66 ) ) ;
V_16 -> V_22 = V_66 ;
}
return 0 ;
V_67:
F_11 ( V_16 ) ;
V_62:
F_11 ( V_57 ) ;
V_61:
F_11 ( V_56 ) ;
V_60:
return V_37 ;
}
static int F_41 ( char * V_13 , struct V_26 * V_27 )
{
struct V_15 * V_16 ;
struct V_15 * V_23 = NULL ;
struct V_15 * V_24 = NULL ;
struct V_15 * V_22 = NULL ;
int V_37 = 0 ;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( V_16 == NULL )
return - V_51 ;
F_42 ( & V_16 -> V_41 ) ;
if ( F_43 ( V_16 -> V_32 ) ) {
F_44 ( & V_16 -> V_41 ) ;
F_11 ( V_16 ) ;
return V_37 ;
}
V_16 -> V_32 = 1 ;
V_22 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_44 ( & V_16 -> V_41 ) ;
if ( V_22 ) {
F_42 ( & V_22 -> V_41 ) ;
V_22 -> V_32 = 1 ;
F_44 ( & V_22 -> V_41 ) ;
F_11 ( V_22 ) ;
}
F_21 ( & V_20 ) ;
V_23 = V_16 -> V_23 ;
V_16 -> V_23 = NULL ;
V_24 = V_16 -> V_24 ;
V_16 -> V_24 = NULL ;
F_15 ( & V_20 ) ;
if ( V_23 )
F_11 ( V_23 ) ;
if ( V_24 ) {
F_42 ( & V_24 -> V_41 ) ;
V_24 -> V_32 = 1 ;
F_44 ( & V_24 -> V_41 ) ;
F_11 ( V_24 ) ;
}
F_11 ( V_16 ) ;
F_11 ( V_16 ) ;
F_5 ( V_11 , L_16 , V_13 ? V_13 : L_17 ,
V_37 ) ;
return V_37 ;
}
int F_45 ( struct V_68 * V_69 , void * V_70 )
{
struct V_33 * V_34 = V_70 ;
struct V_71 * V_72 = V_34 -> V_73 . V_74 . V_75 ;
struct V_76 * V_77 = & V_72 -> V_78 ;
struct V_15 * V_16 ;
F_46 ( V_69 , L_18 ,
F_47 ( V_77 , V_79 ) ? L_19 : L_20 ) ;
F_46 ( V_69 , L_21 ) ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_16 -> V_22 == NULL )
continue;
F_46 ( V_69 , L_22 ,
V_16 -> V_19 ,
V_16 -> V_22 -> V_31 . V_42 ) ;
}
F_15 ( & V_20 ) ;
return 0 ;
}
static void F_48 ( struct V_15 * V_16 )
{
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_49 ( & V_16 -> V_25 -> V_80 -> V_73 . V_74 . V_81 ) ;
if ( V_16 -> V_25 -> V_80 -> V_73 . V_74 . V_82 != 0 ) {
F_5 ( V_11 , L_23 , V_16 -> V_19 ) ;
F_31 ( V_16 -> V_25 -> V_80 , V_16 ) ;
} else {
F_5 ( V_11 , L_24 ,
V_16 -> V_19 ) ;
}
F_50 ( & V_16 -> V_25 -> V_80 -> V_73 . V_74 . V_81 ) ;
}
static int F_51 ( void * V_70 )
{
int V_37 = 0 ;
F_5 ( V_11 , L_25 ) ;
F_21 ( & V_20 ) ;
V_83 |= V_84 ;
while ( 1 ) {
struct V_85 V_86 ;
struct V_15 * V_16 , * V_87 ;
int rand = F_52 () & V_88 ;
int V_89 = ! ! ( V_83 & V_90 ) ;
int V_91 ;
V_83 &= ~ ( V_92 | V_93 ) ;
F_15 ( & V_20 ) ;
V_91 = V_94 * V_95 ;
V_91 += rand * V_95 / 100 ;
V_86 = F_53 ( V_91 , NULL , NULL ) ;
F_54 ( V_96 , V_83 & V_90 , & V_86 ) ;
V_87 = NULL ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list,
cld_list_chain) {
if ( ! V_16 -> V_97 )
continue;
F_15 ( & V_20 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_87 )
F_11 ( V_87 ) ;
V_87 = V_16 ;
V_16 -> V_97 = 0 ;
if ( F_55 ( ! V_89 ) )
F_48 ( V_16 ) ;
F_21 ( & V_20 ) ;
}
F_15 ( & V_20 ) ;
if ( V_87 )
F_11 ( V_87 ) ;
if ( F_43 ( V_89 ) ) {
F_21 ( & V_20 ) ;
break;
}
V_86 = (struct V_85 ) { 0 } ;
F_54 ( V_96 , V_83 & ( V_92 | V_90 ) ,
& V_86 ) ;
F_21 ( & V_20 ) ;
}
V_83 &= ~ V_84 ;
F_15 ( & V_20 ) ;
F_56 ( & V_98 ) ;
F_5 ( V_11 , L_26 ) ;
return V_37 ;
}
static void F_57 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_27 ,
V_16 -> V_19 , F_10 ( & V_16 -> V_17 ) ,
V_16 -> V_32 , V_83 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_42 ( & V_16 -> V_41 ) ;
if ( V_16 -> V_32 || V_16 -> V_97 ) {
F_44 ( & V_16 -> V_41 ) ;
return;
}
F_8 ( V_16 ) ;
V_16 -> V_97 = 1 ;
F_44 ( & V_16 -> V_41 ) ;
F_21 ( & V_20 ) ;
if ( V_83 & V_90 ) {
F_15 ( & V_20 ) ;
V_16 -> V_97 = 0 ;
F_11 ( V_16 ) ;
} else {
V_83 |= V_92 ;
F_15 ( & V_20 ) ;
F_58 ( & V_96 ) ;
}
}
static int F_59 ( const struct V_99 * V_100 ,
struct V_33 * V_34 ,
struct V_33 * V_101 )
{
struct V_102 * V_103 ;
int V_37 ;
V_37 = F_60 ( V_100 , V_34 , & V_34 -> V_104 , V_105 , V_101 ,
& V_106 ) ;
if ( V_37 )
return V_37 ;
V_103 = F_61 ( V_34 , V_105 ) ;
F_12 ( V_103 ) ;
V_103 -> V_107 = V_34 -> V_73 . V_74 . V_108 ;
F_62 ( V_103 ) ;
return 0 ;
}
static int F_63 ( const struct V_99 * V_100 ,
struct V_33 * V_34 )
{
struct V_102 * V_103 ;
V_103 = F_61 ( V_34 , V_105 ) ;
F_64 ( V_100 , V_103 ) ;
return 0 ;
}
static int F_65 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
struct V_53 * V_54 = F_33 ( V_36 ) ;
struct V_109 * V_74 = & V_34 -> V_73 . V_74 ;
struct V_110 V_111 , V_112 ;
struct V_113 * V_114 , * V_115 ;
struct V_99 * V_100 ;
int V_37 = 0 ;
F_12 ( V_54 ) ;
F_12 ( V_54 -> V_116 ) ;
F_66 ( V_100 ) ;
if ( V_100 == NULL )
return - V_38 ;
F_42 ( & V_74 -> V_117 ) ;
F_67 () ;
V_37 = F_68 ( V_100 , V_118 ) ;
if ( V_37 )
GOTO ( V_60 , V_37 ) ;
V_112 . V_119 = V_120 ;
V_112 . V_121 = 1 ;
V_112 . V_122 = 0 ;
V_37 = F_69 ( V_100 , V_54 -> V_116 , & V_112 ,
& V_74 -> V_123 ) ;
if ( V_37 )
GOTO ( V_124 , V_37 ) ;
V_37 = F_70 ( V_100 , V_54 -> V_116 , & V_111 ) ;
if ( V_37 )
GOTO ( V_124 , V_37 ) ;
V_114 = F_71 ( V_100 , V_54 -> V_116 , & V_111 ,
& V_74 -> V_123 -> V_125 -> V_126 ) ;
if ( F_43 ( F_39 ( V_114 ) ) )
GOTO ( V_127 , V_37 = F_40 ( V_114 ) ) ;
V_115 = F_72 ( V_100 , V_74 -> V_123 , V_114 ,
V_128 ,
V_129 | V_130 | V_131 | V_132 ) ;
F_73 ( V_100 , & V_114 -> V_133 ) ;
if ( F_39 ( V_115 ) )
GOTO ( V_127 , V_37 = F_40 ( V_115 ) ) ;
V_74 -> V_108 = V_115 ;
F_12 ( V_54 -> V_134 -> V_80 -> V_135 . V_136 ) ;
V_37 = F_59 ( V_100 , V_34 , V_54 -> V_134 -> V_80 ) ;
if ( V_37 )
GOTO ( V_137 , V_37 ) ;
F_74 ( V_34 , L_28 , V_34 ) ;
V_137:
if ( V_37 ) {
F_75 ( V_100 , & V_74 -> V_108 -> V_133 ) ;
V_74 -> V_108 = NULL ;
}
V_127:
if ( V_37 < 0 ) {
F_76 ( V_100 , V_74 -> V_123 ) ;
V_74 -> V_123 = NULL ;
F_44 ( & V_74 -> V_117 ) ;
}
V_124:
F_77 ( V_100 ) ;
V_60:
F_78 ( V_100 ) ;
return V_37 ;
}
static int F_79 ( struct V_33 * V_34 )
{
struct V_99 V_100 ;
struct V_109 * V_74 = & V_34 -> V_73 . V_74 ;
int V_37 ;
F_12 ( V_74 -> V_123 != NULL ) ;
V_37 = F_68 ( & V_100 , V_118 ) ;
if ( V_37 )
GOTO ( V_138 , V_37 ) ;
F_63 ( & V_100 , V_34 ) ;
F_73 ( & V_100 , & V_74 -> V_108 -> V_133 ) ;
V_74 -> V_108 = NULL ;
F_76 ( & V_100 , V_74 -> V_123 ) ;
V_74 -> V_123 = NULL ;
F_77 ( & V_100 ) ;
V_138:
F_80 ( V_34 , L_28 , V_34 ) ;
F_44 ( & V_74 -> V_117 ) ;
return 0 ;
}
static int F_81 ( const struct V_99 * V_100 , struct V_33 * V_34 )
{
struct V_102 * V_103 ;
int V_37 ;
V_37 = F_60 ( V_100 , V_34 , & V_34 -> V_104 , V_139 , V_34 ,
& V_140 ) ;
if ( V_37 )
return V_37 ;
V_103 = F_61 ( V_34 , V_139 ) ;
F_12 ( V_103 ) ;
F_82 ( V_103 ) ;
F_62 ( V_103 ) ;
return 0 ;
}
static int F_83 ( const struct V_99 * V_100 , struct V_33 * V_34 )
{
struct V_102 * V_103 ;
V_103 = F_61 ( V_34 , V_139 ) ;
if ( V_103 )
F_64 ( V_100 , V_103 ) ;
return 0 ;
}
static int F_84 ( struct V_33 * V_34 , enum V_141 V_142 )
{
int V_37 = 0 ;
switch ( V_142 ) {
case V_143 :
break;
case V_144 :
if ( F_85 ( & V_145 ) ) {
int V_146 ;
F_21 ( & V_20 ) ;
V_146 = V_83 & V_84 ;
if ( V_146 )
V_83 |= V_90 ;
F_15 ( & V_20 ) ;
if ( V_146 ) {
F_58 ( & V_96 ) ;
F_86 ( & V_98 ) ;
}
}
F_87 ( V_34 ) ;
V_37 = F_83 ( NULL , V_34 ) ;
if ( V_37 != 0 )
F_2 ( L_29 ) ;
break;
}
return V_37 ;
}
static int F_88 ( struct V_33 * V_34 )
{
int V_37 ;
if ( V_34 -> V_147 -> V_148 <= 1 )
F_89 () ;
F_90 ( V_34 ) ;
F_91 () ;
V_37 = F_92 ( V_34 ) ;
return V_37 ;
}
static int F_93 ( struct V_33 * V_34 , struct V_149 * V_52 )
{
struct V_150 V_151 ;
int V_37 ;
F_94 () ;
V_37 = F_95 ( V_34 , V_52 ) ;
if ( V_37 )
GOTO ( V_152 , V_37 ) ;
V_37 = F_81 ( NULL , V_34 ) ;
if ( V_37 ) {
F_2 ( L_30 ) ;
GOTO ( V_153 , V_37 ) ;
}
F_96 ( & V_151 ) ;
F_97 ( V_34 , V_151 . V_154 ) ;
F_98 ( V_34 ) ;
if ( F_99 ( & V_145 ) == 1 ) {
V_83 = 0 ;
F_100 ( & V_96 ) ;
V_37 = F_40 ( F_101 ( F_51 , NULL ,
L_31 ) ) ;
if ( F_102 ( V_37 ) ) {
F_2 ( L_32
L_33 ,
V_34 -> V_48 , V_37 ) ;
GOTO ( V_153 , V_37 ) ;
}
V_37 = 0 ;
}
return V_37 ;
V_153:
F_92 ( V_34 ) ;
V_152:
F_91 () ;
return V_37 ;
}
static int F_103 ( struct V_155 * V_156 , struct V_157 * V_158 ,
void * V_70 , int V_159 )
{
struct V_160 V_161 ;
struct V_15 * V_16 = (struct V_15 * ) V_70 ;
int V_37 = 0 ;
switch ( V_159 ) {
case V_162 :
F_104 ( V_156 , L_34 ) ;
F_105 ( V_156 , & V_161 ) ;
V_37 = F_106 ( & V_161 , V_163 ) ;
break;
case V_164 :
F_104 ( V_156 , L_35 ) ;
F_5 ( V_11 , L_36 V_165 L_37 ,
F_107 ( V_156 -> V_166 ) ,
( char * ) & V_156 -> V_166 -> V_167 . V_1 [ 0 ] ) ;
if ( ! V_16 ) {
F_5 ( V_18 , L_38 ) ;
break;
}
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_16 -> V_32 ) {
F_5 ( V_11 , L_39 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
if ( ! V_156 -> V_168 ||
! V_156 -> V_168 -> V_80 -> V_73 . V_74 . V_82 ) {
F_5 ( V_11 , L_40 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
F_57 ( V_16 ) ;
F_11 ( V_16 ) ;
break;
default:
F_4 () ;
}
return V_37 ;
}
static int F_108 ( struct V_169 * exp ,
struct V_170 * V_171 )
{
struct V_172 * V_173 ;
struct V_170 * V_174 , * V_175 ;
int V_37 ;
V_173 = F_109 ( F_110 ( exp ) ,
& V_176 , V_177 ,
V_178 ) ;
if ( ! V_173 )
return - V_38 ;
V_174 = F_111 ( & V_173 -> V_179 , & V_180 ) ;
if ( ! V_174 ) {
F_112 ( V_173 ) ;
return - V_38 ;
}
memcpy ( V_174 , V_171 , sizeof( * V_174 ) ) ;
F_113 ( V_173 ) ;
V_173 -> V_181 = V_182 ;
V_37 = F_114 ( V_173 ) ;
if ( ! V_37 ) {
V_175 = F_115 ( & V_173 -> V_179 , & V_180 ) ;
memcpy ( V_171 , V_175 , sizeof( * V_175 ) ) ;
}
F_112 ( V_173 ) ;
return V_37 ;
}
static int F_116 ( struct V_169 * exp , struct V_183 * V_184 ,
T_2 type , T_3 * V_185 , T_2 V_186 ,
T_1 * V_187 , void * V_188 , void * V_189 , void * V_190 ,
void * V_70 , T_2 V_191 , void * V_192 ,
struct V_160 * V_161 )
{
struct V_15 * V_16 = (struct V_15 * ) V_70 ;
struct V_193 V_194 = {
. V_195 = type ,
. V_196 = V_186 ,
. V_197 = F_103 ,
. V_198 = V_199 ,
} ;
struct V_172 * V_173 ;
int V_200 = F_16 ( V_16 ) ;
int V_37 ;
F_5 ( V_11 , L_41 , V_16 -> V_19 ,
V_16 -> V_49 . V_1 [ 0 ] ) ;
V_173 = F_109 ( F_110 ( exp ) ,
& V_201 , V_202 ,
V_203 ) ;
if ( V_173 == NULL )
return - V_38 ;
F_117 ( & V_173 -> V_179 , & V_204 , V_205 , 0 ) ;
F_113 ( V_173 ) ;
if ( V_16 -> V_31 . V_44 ) {
struct V_53 * V_54 = F_33 ( V_16 -> V_31 . V_44 ) ;
if ( V_54 && F_36 ( V_54 ) )
V_200 = 1 ;
}
V_173 -> V_181 = V_200 ? 5 : V_206 ;
V_37 = F_118 ( exp , & V_173 , & V_194 , & V_16 -> V_49 , NULL , V_187 ,
NULL , 0 , V_207 , V_161 , 0 ) ;
F_112 ( V_173 ) ;
return V_37 ;
}
static int F_119 ( struct V_169 * exp , struct V_183 * V_208 ,
T_2 V_186 , struct V_160 * V_161 )
{
F_120 ( V_161 , V_186 ) ;
return 0 ;
}
static void F_121 ( struct V_33 * V_209 )
{
F_21 ( & V_20 ) ;
V_83 |= V_92 ;
F_15 ( & V_20 ) ;
F_58 ( & V_96 ) ;
}
static int F_122 ( struct V_169 * exp ,
struct V_210 * V_211 )
{
struct V_172 * V_173 ;
struct V_210 * V_212 , * V_213 ;
int V_37 ;
V_173 = F_109 ( F_110 ( exp ) ,
& V_214 , V_177 ,
V_215 ) ;
if ( V_173 == NULL )
return - V_38 ;
V_212 = F_111 ( & V_173 -> V_179 , & V_216 ) ;
if ( ! V_212 ) {
F_112 ( V_173 ) ;
return - V_38 ;
}
memcpy ( V_212 , V_211 , sizeof( * V_212 ) ) ;
F_113 ( V_173 ) ;
F_5 ( V_11 , L_42 , V_211 -> V_217 ) ;
V_173 -> V_181 = V_218 ;
V_37 = F_114 ( V_173 ) ;
if ( ! V_37 ) {
V_213 = F_115 ( & V_173 -> V_179 ,
& V_216 ) ;
memcpy ( V_211 , V_213 , sizeof( * V_213 ) ) ;
F_5 ( V_11 , L_43 ,
V_211 -> V_217 , V_211 -> V_219 ) ;
}
F_112 ( V_173 ) ;
return V_37 ;
}
int F_123 ( const struct V_99 * V_100 , struct V_169 * exp ,
T_4 V_220 , void * V_221 , T_4 V_222 ,
void * V_223 , struct V_224 * V_225 )
{
int V_37 = - V_6 ;
if ( F_124 ( V_226 ) ) {
struct V_71 * V_72 = F_110 ( exp ) ;
int V_227 ;
if ( V_222 != sizeof( int ) )
return - V_6 ;
V_227 = * ( int * ) V_223 ;
F_5 ( V_11 , L_44 ,
V_72 -> V_228 -> V_48 , V_227 ,
V_72 -> V_229 , V_72 -> V_230 ,
V_72 -> V_231 , V_72 -> V_228 -> V_232 ,
F_125 ( V_72 -> V_233 ) ) ;
if ( ( V_72 -> V_233 != V_234 &&
V_72 -> V_233 != V_235 ) || V_227 > 1 )
F_126 ( V_72 ) ;
return 0 ;
}
if ( F_124 ( V_236 ) ) {
struct V_210 * V_211 ;
if ( V_222 != sizeof( struct V_210 ) )
return - V_6 ;
V_211 = (struct V_210 * ) V_223 ;
F_5 ( V_11 , L_45 ,
V_211 -> V_217 , V_211 -> V_237 ) ;
V_37 = F_122 ( exp , V_211 ) ;
return V_37 ;
}
if ( F_124 ( V_238 ) ) {
struct V_35 * V_36 = (struct V_35 * ) V_223 ;
if ( V_222 != sizeof( struct V_35 ) )
return - V_6 ;
V_37 = F_65 ( exp -> V_80 , V_36 ) ;
if ( V_37 )
F_2 ( L_46 , V_37 ) ;
return V_37 ;
}
if ( F_124 ( V_239 ) ) {
if ( V_222 != 0 )
return - V_6 ;
V_37 = F_79 ( exp -> V_80 ) ;
if ( V_37 )
F_2 ( L_47 , V_37 ) ;
return V_37 ;
}
if ( F_124 ( V_240 ) ) {
struct V_170 * V_171 ;
V_171 = (struct V_170 * ) V_223 ;
V_37 = F_108 ( exp , V_171 ) ;
return V_37 ;
}
if ( F_124 ( V_241 ) ) {
struct V_109 * V_74 = & exp -> V_80 -> V_73 . V_74 ;
struct V_242 V_243 ;
if ( V_222 == 0 ) {
if ( V_74 -> V_244 . V_245 != V_246 )
return 0 ;
V_223 = L_48 ;
V_222 = 4 ;
}
V_37 = F_127 ( V_223 , & V_243 ) ;
if ( V_37 ) {
F_2 ( L_49 ,
( char * ) V_223 ) ;
return V_37 ;
}
if ( V_74 -> V_244 . V_245 == V_246 ) {
V_74 -> V_244 = V_243 ;
} else if ( memcmp ( & V_74 -> V_244 , & V_243 ,
sizeof( V_243 ) ) != 0 ) {
char V_247 [ 20 ] ;
F_128 ( & V_74 -> V_244 ,
V_247 , sizeof( V_247 ) ) ;
F_129 ( L_50
L_51 ,
( char * ) V_223 , V_247 ) ;
V_37 = - V_248 ;
}
return V_37 ;
}
return V_37 ;
}
static int F_130 ( const struct V_99 * V_100 , struct V_169 * exp ,
T_2 V_220 , void * V_221 , T_2 * V_222 , void * V_223 ,
struct V_183 * V_209 )
{
int V_37 = - V_6 ;
if ( F_124 ( V_249 ) ) {
struct V_71 * V_72 = F_110 ( exp ) ;
struct V_76 * V_70 = V_223 ;
if ( * V_222 == sizeof( * V_70 ) ) {
* V_70 = V_72 -> V_78 ;
V_37 = 0 ;
}
}
return V_37 ;
}
static int F_131 ( struct V_33 * V_34 ,
struct V_71 * V_72 ,
enum V_250 V_251 )
{
int V_37 = 0 ;
F_12 ( V_72 -> V_228 == V_34 ) ;
F_5 ( V_11 , L_52 , V_251 ) ;
switch ( V_251 ) {
case V_252 :
if ( F_47 ( & V_72 -> V_78 , V_79 ) )
F_132 () ;
break;
case V_253 :
break;
case V_254 : {
struct V_255 * V_256 = V_34 -> V_257 ;
F_133 ( V_256 , V_258 ) ;
break;
}
case V_259 :
F_5 ( V_18 , L_53 , V_34 -> V_48 ) ;
V_34 -> V_260 = 0 ;
F_121 ( V_34 ) ;
if ( F_47 ( & V_72 -> V_78 , V_79 ) )
F_134 () ;
break;
case V_261 :
break;
case V_262 :
case V_263 :
break;
default:
F_2 ( L_54 , V_251 ) ;
F_4 () ;
}
return V_37 ;
}
static int F_135 ( struct V_33 * V_264 ,
struct V_15 * V_16 ,
T_1 V_265 ,
void * V_70 , int V_266 , bool V_267 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_53 * V_54 = F_33 ( V_27 -> V_44 ) ;
struct V_268 * V_269 ;
struct V_149 * V_52 ;
struct V_270 V_271 ;
T_5 V_272 = 0 ;
char * V_273 ;
char * V_274 ;
int V_275 ;
int V_276 ;
int V_37 = 0 ;
int V_277 = 0 ;
F_12 ( V_27 -> V_30 != NULL ) ;
F_12 ( V_27 -> V_44 == V_27 -> V_30 ) ;
F_24 ( V_273 , V_278 ) ;
if ( V_273 == NULL )
return - V_38 ;
if ( ! F_36 ( V_54 ) ) {
V_276 = snprintf ( V_273 , V_278 , L_55 , V_27 -> V_30 ) ;
if ( V_276 >= V_278 ) {
F_19 ( V_273 , V_278 ) ;
return - V_279 ;
}
} else {
F_12 ( F_35 ( V_54 ) ) ;
V_37 = F_136 ( V_54 -> V_280 , V_273 , NULL ,
V_278 ) ;
if ( V_37 ) {
F_19 ( V_273 , V_278 ) ;
return - V_6 ;
}
V_276 = strlen ( V_273 ) ;
}
++ V_276 ;
V_274 = V_273 + V_276 ;
V_275 = V_278 - V_276 ;
while ( V_266 > 0 ) {
int V_281 = sizeof( * V_269 ) ;
int V_282 ;
struct V_33 * V_34 ;
char * V_283 ;
char * V_284 ;
char * V_285 ;
char * V_286 ;
V_37 = - V_6 ;
if ( V_266 < sizeof( * V_269 ) )
break;
V_269 = ( F_137 ( V_269 ) ) ( V_70 + V_277 ) ;
if ( V_269 -> V_287 != 0 )
break;
if ( V_269 -> V_288 == 0 )
break;
if ( V_269 -> V_289 != sizeof( V_290 ) )
break;
V_281 += V_269 -> V_288 * V_269 -> V_289 ;
if ( V_266 < V_281 )
break;
if ( V_267 )
F_138 ( V_269 ) ;
if ( V_269 -> V_291 > V_278 ) {
F_2 ( L_56 , V_269 -> V_291 ) ;
break;
}
if ( V_269 -> V_291 < V_281 )
break;
V_277 += V_269 -> V_291 ;
V_266 -= V_269 -> V_291 ;
if ( V_266 < 0 )
break;
if ( V_269 -> V_292 > V_265 ) {
F_2 ( L_57 ,
V_269 -> V_292 , V_265 ) ;
break;
}
if ( V_272 >= V_269 -> V_292 ) {
F_2 ( L_58 ,
V_272 , V_269 -> V_292 ) ;
break;
}
V_272 = V_269 -> V_292 ;
V_282 = V_269 -> V_293 == V_294 ;
memset ( V_274 , 0 , V_275 ) ;
V_283 = V_274 ;
V_276 = 0 ;
strcpy ( V_283 , V_16 -> V_19 ) ;
V_284 = strrchr ( V_283 , '-' ) ;
if ( V_284 == NULL ) {
F_2 ( L_59 ,
V_264 -> V_48 , V_283 ) ;
break;
}
V_276 = V_284 - V_283 ;
V_283 [ V_276 ] = 0 ;
V_276 += sprintf ( V_283 + V_276 , L_60 ,
V_282 ? L_61 : L_62 , V_269 -> V_295 ) ;
V_284 = V_282 ? L_63 : L_64 ,
V_276 += sprintf ( V_283 + V_276 , L_65 , V_284 , V_273 ) ;
F_139 ( & V_271 , V_283 ) ;
V_34 = F_140 ( V_283 ) ;
if ( V_34 == NULL ) {
F_5 ( V_18 , L_66 ,
V_264 -> V_48 , V_283 ) ;
V_37 = 0 ;
continue;
}
++ V_276 ;
V_285 = V_274 + V_276 ;
V_276 += sprintf ( V_285 , L_67 , V_284 , L_68 ) ;
V_286 = V_274 + V_276 ;
F_49 ( & V_34 -> V_73 . V_74 . V_81 ) ;
if ( V_34 -> V_73 . V_74 . V_75 == NULL ) {
F_50 ( & V_34 -> V_73 . V_74 . V_81 ) ;
V_37 = 0 ;
continue;
}
V_37 = F_141 ( V_34 -> V_73 . V_74 . V_75 ,
V_269 -> V_73 . V_296 [ 0 ] ,
(struct V_297 * ) V_286 ) ;
F_50 ( & V_34 -> V_73 . V_74 . V_81 ) ;
if ( V_37 < 0 ) {
F_2 ( L_69 ,
F_142 ( V_269 -> V_73 . V_296 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_70 ,
V_286 , F_142 ( V_269 -> V_73 . V_296 [ 0 ] ) ) ;
V_276 += strlen ( V_286 ) ;
V_276 += sprintf ( V_274 + V_276 , L_71 , V_269 -> V_298 ) ;
F_12 ( V_276 < V_275 ) ;
F_143 ( & V_271 , 1 , V_285 ) ;
V_37 = - V_38 ;
V_52 = F_144 ( V_299 , & V_271 ) ;
if ( V_52 == NULL ) {
F_2 ( L_72 ) ;
break;
}
F_5 ( V_18 , L_73 ,
V_272 , V_265 , V_283 , V_285 ) ;
V_37 = F_145 ( V_52 ) ;
F_146 ( V_52 ) ;
if ( V_37 )
F_5 ( V_18 , L_74 ,
V_283 , V_37 ) ;
}
F_19 ( V_273 , V_278 ) ;
return V_37 ;
}
static int F_147 ( struct V_33 * V_34 ,
struct V_15 * V_16 )
{
struct V_172 * V_173 = NULL ;
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_300 * V_301 ;
struct V_302 * V_303 ;
struct V_304 * V_158 ;
struct V_305 * * V_306 ;
int V_307 ;
bool V_308 = true ;
bool V_267 = false ;
int V_309 ;
int V_310 ;
int V_37 ;
V_307 = V_311 ;
if ( V_27 -> V_42 == 0 )
V_307 = V_312 ;
F_24 ( V_306 , sizeof( * V_306 ) * V_307 ) ;
if ( V_306 == NULL )
GOTO ( V_313 , V_37 = - V_38 ) ;
for ( V_309 = 0 ; V_309 < V_307 ; V_309 ++ ) {
V_306 [ V_309 ] = F_148 ( V_314 ) ;
if ( V_306 [ V_309 ] == NULL )
GOTO ( V_313 , V_37 = - V_38 ) ;
}
V_315:
F_12 ( F_149 ( V_16 ) ) ;
F_12 ( F_150 ( & V_16 -> V_41 ) ) ;
V_173 = F_151 ( F_110 ( V_16 -> V_25 ) ,
& V_316 ) ;
if ( V_173 == NULL )
GOTO ( V_313 , V_37 = - V_38 ) ;
V_37 = F_152 ( V_173 , V_177 , V_317 ) ;
if ( V_37 )
GOTO ( V_313 , V_37 ) ;
V_301 = F_111 ( & V_173 -> V_179 , & V_318 ) ;
F_12 ( V_301 != NULL ) ;
F_12 ( sizeof( V_301 -> V_319 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_153 ( V_301 -> V_319 , V_16 -> V_19 , sizeof( V_301 -> V_319 ) )
>= sizeof( V_301 -> V_319 ) )
GOTO ( V_313 , V_37 = - V_279 ) ;
V_301 -> V_320 = V_27 -> V_42 + 1 ;
V_301 -> V_321 = V_16 -> V_45 ;
V_301 -> V_322 = V_323 ;
V_301 -> V_324 = V_307 ;
V_158 = F_154 ( V_173 , V_307 , 1 , V_325 ,
V_326 ) ;
if ( V_158 == NULL )
GOTO ( V_313 , V_37 = - V_38 ) ;
for ( V_309 = 0 ; V_309 < V_307 ; V_309 ++ )
F_155 ( V_158 , V_306 [ V_309 ] , 0 , V_278 ) ;
F_113 ( V_173 ) ;
V_37 = F_114 ( V_173 ) ;
if ( V_37 )
GOTO ( V_313 , V_37 ) ;
V_303 = F_115 ( & V_173 -> V_179 , & V_327 ) ;
if ( V_303 -> V_328 < V_303 -> V_329 )
GOTO ( V_313 , V_37 = - V_6 ) ;
V_27 -> V_42 = V_303 -> V_329 ;
V_308 = V_303 -> V_329 == V_303 -> V_328 ;
F_5 ( V_18 , L_75 ,
V_303 -> V_329 , V_308 == false ) ;
V_310 = F_156 ( V_173 , V_173 -> V_330 , 0 ) ;
if ( V_310 < 0 )
GOTO ( V_313 , V_37 = V_310 ) ;
if ( V_310 > V_307 << V_323 )
GOTO ( V_313 , V_37 = - V_6 ) ;
if ( V_310 == 0 ) {
if ( ! V_308 )
V_37 = - V_6 ;
GOTO ( V_313 , V_37 ) ;
}
V_267 = ! ! F_157 ( V_173 ) ;
#if V_331 < F_158 ( 3 , 2 , 50 , 0 )
if ( F_43 ( V_173 -> V_332 -> V_333 ) )
V_267 = ! V_267 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_309 = 0 ; V_309 < V_307 && V_310 > 0 ; V_309 ++ ) {
int V_334 ;
void * V_59 ;
V_59 = F_159 ( V_306 [ V_309 ] ) ;
V_334 = F_135 ( V_34 , V_16 , V_303 -> V_329 , V_59 ,
F_160 ( int , V_310 , V_278 ) ,
V_267 ) ;
F_161 ( V_306 [ V_309 ] ) ;
if ( V_334 < 0 ) {
F_162 ( L_76 ,
V_16 -> V_19 , V_334 ) ;
break;
}
V_310 -= V_278 ;
}
V_313:
if ( V_173 )
F_112 ( V_173 ) ;
if ( V_37 == 0 && ! V_308 )
goto V_315;
if ( V_306 ) {
for ( V_309 = 0 ; V_309 < V_307 ; V_309 ++ ) {
if ( V_306 [ V_309 ] == NULL )
break;
F_163 ( V_306 [ V_309 ] ) ;
}
F_19 ( V_306 , sizeof( * V_306 ) * V_307 ) ;
}
return V_37 ;
}
static int F_164 ( const struct V_99 * V_100 ,
struct V_33 * V_34 ,
struct V_102 * V_335 ,
struct V_102 * V_336 , char * V_13 )
{
char * V_337 ;
int V_37 ;
F_24 ( V_337 , strlen ( V_13 ) + 1 ) ;
if ( ! V_337 )
return - V_38 ;
sprintf ( V_337 , L_77 , V_13 ) ;
V_37 = F_165 ( V_100 , V_34 , V_336 , V_336 , V_13 , V_337 ) ;
if ( V_37 < 0 && V_37 != - V_51 )
GOTO ( V_313 , V_37 ) ;
V_37 = F_165 ( V_100 , V_34 , V_335 , V_336 , V_13 , V_13 ) ;
if ( V_37 == - V_51 ) {
F_166 ( V_100 , V_336 , NULL , V_13 ) ;
} else if ( V_37 < 0 ) {
F_165 ( V_100 , V_34 , V_336 , V_336 , V_337 , V_13 ) ;
V_313:
F_2 ( L_78 ,
V_34 -> V_48 , V_13 , V_37 ) ;
}
F_166 ( V_100 , V_336 , NULL , V_337 ) ;
F_19 ( V_337 , strlen ( V_13 ) + 1 ) ;
return V_37 ;
}
static int F_167 ( struct V_33 * V_264 ,
struct V_15 * V_16 , int V_338 )
{
struct V_102 * V_103 , * V_336 = NULL ;
struct V_113 * V_339 = V_264 -> V_73 . V_74 . V_108 ;
struct V_53 * V_54 = NULL ;
int V_37 = 0 ;
bool V_340 = false ;
struct V_99 * V_100 ;
F_12 ( V_16 ) ;
F_12 ( F_150 ( & V_16 -> V_41 ) ) ;
if ( F_16 ( V_16 ) && V_338 )
return 0 ;
if ( V_16 -> V_31 . V_44 )
V_54 = F_33 ( V_16 -> V_31 . V_44 ) ;
F_66 ( V_100 ) ;
if ( V_100 == NULL )
return - V_38 ;
V_37 = F_68 ( V_100 , V_118 ) ;
if ( V_37 )
GOTO ( V_341 , V_37 ) ;
V_103 = F_61 ( V_264 , V_139 ) ;
F_12 ( V_103 ) ;
V_336 = F_61 ( V_264 , V_105 ) ;
if ( V_336 && V_54 && F_36 ( V_54 ) && ! F_168 ( V_54 ) &&
V_339 != NULL &&
F_169 ( V_339 -> V_133 . V_342 ) == V_54 -> V_116 ) {
if ( ! V_338 )
V_37 = F_164 ( V_100 , V_264 , V_103 , V_336 ,
V_16 -> V_19 ) ;
if ( V_338 || V_37 ) {
if ( F_170 ( V_100 , V_336 , V_16 -> V_19 ) ) {
F_171 ( 0x13a ,
L_79 ,
V_16 -> V_19 ) ;
GOTO ( V_343 , V_37 = - V_51 ) ;
}
F_5 ( V_11 ,
L_80 ,
V_16 -> V_19 ) ;
}
F_62 ( V_103 ) ;
V_103 = V_336 ;
V_336 = NULL ;
} else {
if ( V_338 )
GOTO ( V_343 , V_37 = - V_344 ) ;
}
if ( F_16 ( V_16 ) ) {
F_172 ( V_16 -> V_19 ) ;
V_340 = true ;
}
V_37 = F_173 ( V_100 , V_103 , V_16 -> V_19 ,
& V_16 -> V_31 ) ;
V_343:
F_174 ( V_100 , V_103 ) ;
if ( V_336 )
F_174 ( V_100 , V_336 ) ;
if ( V_340 ) {
F_12 ( F_16 ( V_16 ) ) ;
F_175 ( V_16 -> V_19 ) ;
F_176 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_12 ) ) ;
}
F_77 ( V_100 ) ;
V_341:
F_78 ( V_100 ) ;
return V_37 ;
}
int F_31 ( struct V_33 * V_264 , struct V_15 * V_16 )
{
struct V_160 V_161 = { 0 } ;
T_1 V_187 = V_345 ;
int V_37 = 0 , V_346 ;
F_12 ( V_16 ) ;
F_42 ( & V_16 -> V_41 ) ;
if ( V_16 -> V_32 ) {
F_44 ( & V_16 -> V_41 ) ;
return 0 ;
}
F_177 ( V_347 , 20 ) ;
F_5 ( V_11 , L_81 , V_16 -> V_19 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_42 + 1 ) ;
V_346 = F_116 ( V_264 -> V_73 . V_74 . V_348 , NULL , V_349 , NULL ,
V_350 , & V_187 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_161 ) ;
if ( V_346 == 0 ) {
F_8 ( V_16 ) ;
V_37 = F_178 ( & V_161 , ( void * ) V_16 ) ;
F_12 ( V_37 == 0 ) ;
} else {
F_5 ( V_11 , L_82 , V_346 ) ;
V_16 -> V_97 = 1 ;
F_8 ( V_16 ) ;
}
if ( F_149 ( V_16 ) ) {
V_37 = 0 ;
if ( V_346 == 0 )
V_37 = F_147 ( V_264 , V_16 ) ;
} else {
V_37 = F_167 ( V_264 , V_16 , V_346 != 0 ) ;
}
F_5 ( V_11 , L_83 ,
V_264 -> V_48 , V_16 -> V_19 , V_37 ? L_84 : L_85 , V_37 ) ;
F_44 ( & V_16 -> V_41 ) ;
if ( ! V_346 ) {
V_346 = F_119 ( V_264 -> V_73 . V_74 . V_348 , NULL ,
V_350 , & V_161 ) ;
if ( V_346 )
F_2 ( L_86 , V_346 ) ;
}
return V_37 ;
}
static int F_179 ( struct V_33 * V_34 , T_4 V_2 , void * V_274 )
{
struct V_149 * V_52 = V_274 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_37 = 0 ;
switch ( V_52 -> V_351 ) {
case V_352 : {
struct V_210 * V_211 ;
if ( F_180 ( V_52 , 1 ) !=
sizeof( struct V_210 ) )
GOTO ( V_313 , V_37 = - V_6 ) ;
V_211 = (struct V_210 * ) F_181 ( V_52 , 1 ) ;
F_5 ( V_11 , L_87 ,
V_211 -> V_217 , V_211 -> V_237 ) ;
V_37 = F_122 ( V_34 -> V_73 . V_74 . V_348 , V_211 ) ;
break;
}
case V_353 :
F_2 ( L_88 ) ;
V_37 = - V_354 ;
break;
case V_355 : {
V_37 = F_182 ( V_52 ) ;
break;
}
case V_356 : {
struct V_15 * V_16 ;
struct V_35 * V_36 ;
V_13 = F_183 ( V_52 , 1 ) ;
V_27 = (struct V_26 * ) F_181 ( V_52 , 2 ) ;
V_36 = * (struct V_35 * * ) F_181 ( V_52 , 3 ) ;
F_5 ( V_11 , L_89 , V_13 ,
V_27 -> V_42 ) ;
V_37 = F_38 ( V_34 , V_13 , V_27 , V_36 ) ;
if ( V_37 )
break;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( V_16 == NULL ) {
V_37 = - V_51 ;
break;
}
V_16 -> V_31 . V_43 |= V_357 ;
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 == 0 && V_16 -> V_22 != NULL ) {
if ( F_47 ( & V_34 -> V_73 . V_74 . V_75 ->
V_78 , V_79 ) ) {
V_37 = F_31 ( V_34 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_358 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_11 ( V_358 ) ;
}
if ( V_37 )
F_2 ( L_90 , V_37 ) ;
}
if ( V_37 == 0 && V_16 -> V_24 != NULL ) {
V_37 = F_31 ( V_34 , V_16 -> V_24 ) ;
if ( V_37 == - V_51 ) {
F_5 ( V_11 ,
L_91 ) ;
V_37 = 0 ;
}
if ( V_37 )
F_2 (
L_92 ,
V_34 -> V_48 , V_37 ) ;
}
F_11 ( V_16 ) ;
break;
}
case V_359 : {
V_13 = F_183 ( V_52 , 1 ) ;
if ( V_52 -> V_360 >= 2 )
V_27 = (struct V_26 * ) F_181 (
V_52 , 2 ) ;
V_37 = F_41 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_93 , V_52 -> V_351 ) ;
GOTO ( V_313 , V_37 = - V_6 ) ;
}
}
V_313:
return V_37 ;
}
int T_6 F_184 ( void )
{
return F_185 ( & V_361 , NULL , NULL ,
V_362 , NULL ) ;
}
static void F_186 ( void )
{
F_187 ( V_362 ) ;
}
