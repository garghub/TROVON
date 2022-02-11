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
static int F_7 ( char * V_13 , struct V_3 * V_4 , int type )
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
F_19 ( V_16 ) ;
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
V_16 = F_24 ( sizeof( * V_16 ) + strlen ( V_13 ) + 1 , V_38 ) ;
if ( ! V_16 )
return F_25 ( - V_39 ) ;
strcpy ( V_16 -> V_19 , V_13 ) ;
if ( V_27 )
V_16 -> V_31 = * V_27 ;
else
V_16 -> V_31 . V_40 = V_41 ;
F_26 ( & V_16 -> V_42 ) ;
V_16 -> V_31 . V_43 = 0 ;
V_16 -> V_31 . V_44 = 0 ;
V_16 -> V_31 . V_45 = V_36 ;
V_16 -> V_46 = type ;
F_27 ( & V_16 -> V_17 , 1 ) ;
V_16 -> V_25 = F_28 ( V_34 -> V_47 ) ;
if ( F_16 ( V_16 ) ) {
F_29 ( V_13 ) ;
V_16 -> V_31 . V_48 = V_34 -> V_49 ;
}
V_37 = F_7 ( V_13 , & V_16 -> V_50 , type ) ;
F_21 ( & V_20 ) ;
F_30 ( & V_16 -> V_21 , & V_51 ) ;
F_15 ( & V_20 ) ;
if ( V_37 ) {
F_11 ( V_16 ) ;
return F_25 ( V_37 ) ;
}
if ( F_16 ( V_16 ) ) {
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 && V_37 != - V_52 )
F_2 ( L_7 , V_37 ) ;
}
return V_16 ;
}
static struct V_15 * F_32 ( struct V_33 * V_34 ,
char * V_12 ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_26 V_53 = * V_27 ;
struct V_15 * V_16 ;
char V_13 [ 32 ] ;
F_12 ( strlen ( V_12 ) < sizeof( V_13 ) / 2 ) ;
strcpy ( V_13 , V_12 ) ;
F_12 ( V_53 . V_30 ) ;
strcat ( V_13 , L_8 ) ;
V_16 = F_23 ( V_34 , V_13 , V_9 , & V_53 , V_36 ) ;
return V_16 ;
}
static struct V_15 * F_33 ( struct V_33 * V_34 ,
struct V_26 * V_27 , struct V_35 * V_36 )
{
struct V_26 V_53 = * V_27 ;
struct V_15 * V_16 ;
V_53 . V_30 = V_36 ;
V_16 = F_23 ( V_34 , V_54 , V_10 ,
& V_53 , V_36 ) ;
return V_16 ;
}
static int F_34 ( struct V_33 * V_34 , char * V_13 ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_55 * V_56 = F_35 ( V_36 ) ;
struct V_15 * V_16 ;
struct V_15 * V_57 ;
struct V_15 * V_58 ;
char V_59 [ 32 ] ;
char * V_60 ;
int V_37 ;
F_5 ( V_11 , L_9 , V_13 , V_27 -> V_30 ) ;
V_60 = strrchr ( V_13 , '-' ) ;
if ( V_60 == NULL || V_60 - V_13 > 8 ) {
F_2 ( L_10 , V_13 ) ;
return - V_6 ;
}
memcpy ( V_59 , V_13 , V_60 - V_13 ) ;
strcpy ( V_59 + ( V_60 - V_13 ) , L_11 ) ;
V_57 = F_20 ( V_59 , NULL ) ;
if ( V_57 == NULL ) {
V_57 = F_23 ( V_34 , V_59 ,
V_8 , NULL , NULL ) ;
if ( F_36 ( V_57 ) ) {
F_2 ( L_12 , V_59 ) ;
V_37 = F_37 ( V_57 ) ;
goto V_61;
}
}
V_58 = F_33 ( V_34 , V_27 , V_36 ) ;
if ( F_36 ( V_58 ) ) {
V_37 = F_37 ( V_58 ) ;
F_2 ( L_13 ,
V_34 -> V_49 , V_37 ) ;
goto V_62;
}
V_16 = F_23 ( V_34 , V_13 , V_7 , V_27 , V_36 ) ;
if ( F_36 ( V_16 ) ) {
F_2 ( L_14 , V_13 ) ;
V_37 = F_37 ( V_16 ) ;
goto V_63;
}
V_16 -> V_23 = V_57 ;
V_16 -> V_24 = V_58 ;
F_12 ( V_56 -> V_64 ) ;
if ( ! ( V_56 -> V_64 -> V_65 & V_66 ) ) {
struct V_15 * V_67 ;
* strrchr ( V_59 , '-' ) = 0 ;
V_67 = F_32 ( V_34 , V_59 , V_27 , V_36 ) ;
if ( F_36 ( V_67 ) ) {
V_37 = F_37 ( V_67 ) ;
goto V_68;
}
V_16 -> V_22 = V_67 ;
}
return 0 ;
V_68:
F_11 ( V_16 ) ;
V_63:
F_11 ( V_58 ) ;
V_62:
F_11 ( V_57 ) ;
V_61:
return V_37 ;
}
static int F_38 ( char * V_13 , struct V_26 * V_27 )
{
struct V_15 * V_16 ;
struct V_15 * V_23 = NULL ;
struct V_15 * V_24 = NULL ;
struct V_15 * V_22 = NULL ;
int V_37 = 0 ;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( V_16 == NULL )
return - V_52 ;
F_39 ( & V_16 -> V_42 ) ;
if ( F_40 ( V_16 -> V_32 ) ) {
F_41 ( & V_16 -> V_42 ) ;
F_11 ( V_16 ) ;
return V_37 ;
}
V_16 -> V_32 = 1 ;
V_22 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_41 ( & V_16 -> V_42 ) ;
if ( V_22 ) {
F_39 ( & V_22 -> V_42 ) ;
V_22 -> V_32 = 1 ;
F_41 ( & V_22 -> V_42 ) ;
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
F_39 ( & V_24 -> V_42 ) ;
V_24 -> V_32 = 1 ;
F_41 ( & V_24 -> V_42 ) ;
F_11 ( V_24 ) ;
}
F_11 ( V_16 ) ;
F_11 ( V_16 ) ;
F_5 ( V_11 , L_15 , V_13 ? V_13 : L_16 ,
V_37 ) ;
return V_37 ;
}
int F_42 ( struct V_69 * V_70 , void * V_71 )
{
struct V_33 * V_34 = V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_15 * V_16 ;
int V_37 ;
V_37 = F_43 ( V_34 ) ;
if ( V_37 )
return V_37 ;
V_73 = V_34 -> V_76 . V_77 . V_78 ;
V_75 = & V_73 -> V_79 ;
F_44 ( V_70 , L_17 ,
F_45 ( V_75 , V_80 ) ? L_18 : L_19 ) ;
F_44 ( V_70 , L_20 ) ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_16 -> V_22 == NULL )
continue;
F_44 ( V_70 , L_21 ,
V_16 -> V_19 ,
V_16 -> V_22 -> V_31 . V_43 ) ;
}
F_15 ( & V_20 ) ;
F_46 ( V_34 ) ;
return 0 ;
}
static void F_47 ( struct V_15 * V_16 )
{
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_48 ( & V_16 -> V_25 -> V_81 -> V_76 . V_77 . V_82 ) ;
if ( V_16 -> V_25 -> V_81 -> V_76 . V_77 . V_83 != 0 ) {
F_5 ( V_11 , L_22 , V_16 -> V_19 ) ;
F_31 ( V_16 -> V_25 -> V_81 , V_16 ) ;
} else {
F_5 ( V_11 , L_23 ,
V_16 -> V_19 ) ;
}
F_49 ( & V_16 -> V_25 -> V_81 -> V_76 . V_77 . V_82 ) ;
}
static int F_50 ( void * V_71 )
{
bool V_84 = true ;
F_5 ( V_11 , L_24 ) ;
F_21 ( & V_20 ) ;
V_85 |= V_86 ;
while ( 1 ) {
struct V_87 V_88 ;
struct V_15 * V_16 , * V_89 ;
int rand = F_51 () & V_90 ;
int V_91 = ! ! ( V_85 & V_92 ) ;
int V_93 ;
V_85 &= ~ ( V_94 | V_95 ) ;
F_15 ( & V_20 ) ;
if ( V_84 ) {
V_84 = false ;
F_52 ( & V_96 ) ;
}
V_93 = V_97 * V_98 ;
V_93 += rand * V_98 / 100 ;
V_88 = F_53 ( V_93 , NULL , NULL ) ;
F_54 ( V_99 , V_85 & ( V_92 | V_100 ) ,
& V_88 ) ;
V_89 = NULL ;
F_21 ( & V_20 ) ;
V_85 &= ~ V_100 ;
F_22 (cld, &config_llog_list,
cld_list_chain) {
if ( ! V_16 -> V_101 )
continue;
F_15 ( & V_20 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_89 )
F_11 ( V_89 ) ;
V_89 = V_16 ;
V_16 -> V_101 = 0 ;
if ( F_55 ( ! V_91 ) )
F_47 ( V_16 ) ;
F_21 ( & V_20 ) ;
}
F_15 ( & V_20 ) ;
if ( V_89 )
F_11 ( V_89 ) ;
if ( F_40 ( V_91 ) ) {
F_21 ( & V_20 ) ;
break;
}
V_88 = (struct V_87 ) { 0 } ;
F_54 ( V_99 , V_85 & ( V_94 | V_92 ) ,
& V_88 ) ;
F_21 ( & V_20 ) ;
}
V_85 &= ~ V_86 ;
F_15 ( & V_20 ) ;
F_52 ( & V_102 ) ;
F_5 ( V_11 , L_25 ) ;
return 0 ;
}
static void F_56 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_26 ,
V_16 -> V_19 , F_10 ( & V_16 -> V_17 ) ,
V_16 -> V_32 , V_85 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_39 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_32 || V_16 -> V_101 ) {
F_41 ( & V_16 -> V_42 ) ;
return;
}
F_8 ( V_16 ) ;
V_16 -> V_101 = 1 ;
F_41 ( & V_16 -> V_42 ) ;
F_21 ( & V_20 ) ;
if ( V_85 & V_92 ) {
F_15 ( & V_20 ) ;
V_16 -> V_101 = 0 ;
F_11 ( V_16 ) ;
} else {
V_85 |= V_94 ;
F_15 ( & V_20 ) ;
F_57 ( & V_99 ) ;
}
}
static int F_58 ( const struct V_103 * V_104 , struct V_33 * V_34 )
{
struct V_105 * V_106 ;
int V_37 ;
V_37 = F_59 ( V_104 , V_34 , & V_34 -> V_107 , V_108 , V_34 ,
& V_109 ) ;
if ( V_37 )
return V_37 ;
V_106 = F_60 ( V_34 , V_108 ) ;
F_12 ( V_106 ) ;
F_61 ( V_106 ) ;
F_62 ( V_106 ) ;
return 0 ;
}
static int F_63 ( const struct V_103 * V_104 , struct V_33 * V_34 )
{
struct V_105 * V_106 ;
V_106 = F_60 ( V_34 , V_108 ) ;
if ( V_106 )
F_64 ( V_104 , V_106 ) ;
return 0 ;
}
static int F_65 ( struct V_33 * V_34 , enum V_110 V_111 )
{
int V_37 = 0 ;
int V_112 ;
switch ( V_111 ) {
case V_113 :
break;
case V_114 :
if ( F_66 ( & V_115 ) ) {
F_12 ( V_85 & V_86 ) ;
V_112 = V_92 ;
} else {
V_112 = V_94 | V_100 ;
}
F_21 ( & V_20 ) ;
V_85 |= V_112 ;
F_15 ( & V_20 ) ;
F_57 ( & V_99 ) ;
if ( V_112 & V_92 )
F_67 ( & V_102 ) ;
F_68 ( V_34 ) ;
V_37 = F_63 ( NULL , V_34 ) ;
if ( V_37 != 0 )
F_2 ( L_27 ) ;
break;
}
return V_37 ;
}
static int F_69 ( struct V_33 * V_34 )
{
if ( V_34 -> V_116 -> V_117 <= 1 )
F_70 () ;
F_71 ( V_34 ) ;
F_72 () ;
return F_73 ( V_34 ) ;
}
static int F_74 ( struct V_33 * V_34 , struct V_118 * V_53 )
{
struct V_119 V_120 = { NULL } ;
int V_37 ;
F_75 () ;
V_37 = F_76 ( V_34 , V_53 ) ;
if ( V_37 )
goto V_121;
V_37 = F_58 ( NULL , V_34 ) ;
if ( V_37 ) {
F_2 ( L_28 ) ;
goto V_122;
}
F_77 ( & V_120 ) ;
F_78 ( V_34 , V_120 . V_123 , V_120 . V_124 ) ;
F_79 ( V_34 ) ;
if ( F_80 ( & V_115 ) == 1 ) {
V_85 = 0 ;
F_81 ( & V_99 ) ;
V_37 = F_37 ( F_82 ( F_50 , NULL ,
L_29 ) ) ;
if ( F_83 ( V_37 ) ) {
F_2 ( L_30 ,
V_34 -> V_49 , V_37 ) ;
goto V_122;
}
V_37 = 0 ;
F_67 ( & V_96 ) ;
}
return V_37 ;
V_122:
F_73 ( V_34 ) ;
V_121:
F_72 () ;
return V_37 ;
}
static int F_84 ( struct V_125 * V_126 , struct V_127 * V_128 ,
void * V_71 , int V_129 )
{
struct V_130 V_131 ;
struct V_15 * V_16 = V_71 ;
int V_37 = 0 ;
switch ( V_129 ) {
case V_132 :
F_85 ( V_126 , L_31 ) ;
F_86 ( V_126 , & V_131 ) ;
V_37 = F_87 ( & V_131 , V_133 ) ;
break;
case V_134 :
F_85 ( V_126 , L_32 ) ;
F_5 ( V_11 , L_33 V_135 L_34 ,
F_88 ( V_126 -> V_136 ) ,
( char * ) & V_126 -> V_136 -> V_137 . V_1 [ 0 ] ) ;
if ( ! V_16 ) {
F_5 ( V_18 , L_35 ) ;
break;
}
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_16 -> V_32 ) {
F_5 ( V_11 , L_36 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
if ( ! V_126 -> V_138 ||
! V_126 -> V_138 -> V_81 -> V_76 . V_77 . V_83 ) {
F_5 ( V_11 , L_37 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
F_56 ( V_16 ) ;
F_11 ( V_16 ) ;
break;
default:
F_4 () ;
}
return V_37 ;
}
static int F_89 ( struct V_139 * exp ,
struct V_140 * V_141 )
{
struct V_142 * V_143 ;
struct V_140 * V_144 , * V_145 ;
int V_37 ;
V_143 = F_90 ( F_91 ( exp ) ,
& V_146 , V_147 ,
V_148 ) ;
if ( ! V_143 )
return - V_39 ;
V_144 = F_92 ( & V_143 -> V_149 , & V_150 ) ;
if ( ! V_144 ) {
F_93 ( V_143 ) ;
return - V_39 ;
}
memcpy ( V_144 , V_141 , sizeof( * V_144 ) ) ;
F_94 ( V_143 ) ;
V_143 -> V_151 = V_152 ;
V_37 = F_95 ( V_143 ) ;
if ( ! V_37 ) {
V_145 = F_96 ( & V_143 -> V_149 , & V_150 ) ;
memcpy ( V_141 , V_145 , sizeof( * V_145 ) ) ;
}
F_93 ( V_143 ) ;
return V_37 ;
}
static int F_97 ( struct V_139 * exp , struct V_153 * V_154 ,
T_2 type , T_3 * V_155 , T_2 V_156 ,
T_1 * V_157 , void * V_158 , void * V_159 , void * V_160 ,
void * V_71 , T_2 V_161 , void * V_162 ,
struct V_130 * V_131 )
{
struct V_15 * V_16 = V_71 ;
struct V_163 V_164 = {
. V_165 = type ,
. V_166 = V_156 ,
. V_167 = F_84 ,
. V_168 = V_169 ,
} ;
struct V_142 * V_143 ;
int V_170 = F_16 ( V_16 ) ;
int V_37 ;
F_5 ( V_11 , L_38 , V_16 -> V_19 ,
V_16 -> V_50 . V_1 [ 0 ] ) ;
V_143 = F_90 ( F_91 ( exp ) ,
& V_171 , V_172 ,
V_173 ) ;
if ( V_143 == NULL )
return - V_39 ;
F_98 ( & V_143 -> V_149 , & V_174 , V_175 , 0 ) ;
F_94 ( V_143 ) ;
V_143 -> V_151 = V_170 ? 5 : V_176 ;
V_37 = F_99 ( exp , & V_143 , & V_164 , & V_16 -> V_50 , NULL , V_157 ,
NULL , 0 , V_177 , V_131 , 0 ) ;
F_93 ( V_143 ) ;
return V_37 ;
}
static void F_100 ( struct V_33 * V_178 )
{
F_21 ( & V_20 ) ;
V_85 |= V_94 ;
F_15 ( & V_20 ) ;
F_57 ( & V_99 ) ;
}
static int F_101 ( struct V_139 * exp ,
struct V_179 * V_180 )
{
struct V_142 * V_143 ;
struct V_179 * V_181 , * V_182 ;
int V_37 ;
V_143 = F_90 ( F_91 ( exp ) ,
& V_183 , V_147 ,
V_184 ) ;
if ( V_143 == NULL )
return - V_39 ;
V_181 = F_92 ( & V_143 -> V_149 , & V_185 ) ;
if ( ! V_181 ) {
F_93 ( V_143 ) ;
return - V_39 ;
}
memcpy ( V_181 , V_180 , sizeof( * V_181 ) ) ;
F_94 ( V_143 ) ;
F_5 ( V_11 , L_39 , V_180 -> V_186 ) ;
V_143 -> V_151 = V_187 ;
V_37 = F_95 ( V_143 ) ;
if ( ! V_37 ) {
V_182 = F_96 ( & V_143 -> V_149 ,
& V_185 ) ;
memcpy ( V_180 , V_182 , sizeof( * V_182 ) ) ;
F_5 ( V_11 , L_40 ,
V_180 -> V_186 , V_180 -> V_188 ) ;
}
F_93 ( V_143 ) ;
return V_37 ;
}
static int F_102 ( const struct V_103 * V_104 , struct V_139 * exp ,
T_4 V_189 , void * V_190 , T_4 V_191 ,
void * V_192 , struct V_193 * V_194 )
{
int V_37 = - V_6 ;
if ( F_103 ( V_195 ) ) {
struct V_72 * V_73 = F_91 ( exp ) ;
int V_196 ;
if ( V_191 != sizeof( int ) )
return - V_6 ;
V_196 = * ( int * ) V_192 ;
F_5 ( V_11 , L_41 ,
V_73 -> V_197 -> V_49 , V_196 ,
V_73 -> V_198 , V_73 -> V_199 ,
V_73 -> V_200 , V_73 -> V_197 -> V_201 ,
F_104 ( V_73 -> V_202 ) ) ;
if ( ( V_73 -> V_202 != V_203 &&
V_73 -> V_202 != V_204 ) || V_196 > 1 )
F_105 ( V_73 ) ;
return 0 ;
}
if ( F_103 ( V_205 ) ) {
struct V_140 * V_141 ;
V_141 = V_192 ;
V_37 = F_89 ( exp , V_141 ) ;
return V_37 ;
}
if ( F_103 ( V_206 ) ) {
struct V_207 * V_77 = & exp -> V_81 -> V_76 . V_77 ;
struct V_208 V_209 ;
if ( V_191 == 0 ) {
if ( V_77 -> V_210 . V_211 != V_212 )
return 0 ;
V_192 = L_42 ;
V_191 = 4 ;
}
V_37 = F_106 ( V_192 , & V_209 ) ;
if ( V_37 ) {
F_2 ( L_43 ,
( char * ) V_192 ) ;
return V_37 ;
}
if ( V_77 -> V_210 . V_211 == V_212 ) {
V_77 -> V_210 = V_209 ;
} else if ( memcmp ( & V_77 -> V_210 , & V_209 ,
sizeof( V_209 ) ) != 0 ) {
char V_213 [ 20 ] ;
F_107 ( & V_77 -> V_210 ,
V_213 , sizeof( V_213 ) ) ;
F_108 ( L_44 ,
( char * ) V_192 , V_213 ) ;
V_37 = - V_214 ;
}
return V_37 ;
}
return V_37 ;
}
static int F_109 ( const struct V_103 * V_104 , struct V_139 * exp ,
T_2 V_189 , void * V_190 , T_2 * V_191 , void * V_192 ,
struct V_153 * V_178 )
{
int V_37 = - V_6 ;
if ( F_103 ( V_215 ) ) {
struct V_72 * V_73 = F_91 ( exp ) ;
struct V_74 * V_71 = V_192 ;
if ( * V_191 == sizeof( * V_71 ) ) {
* V_71 = V_73 -> V_79 ;
V_37 = 0 ;
}
}
return V_37 ;
}
static int F_110 ( struct V_33 * V_34 ,
struct V_72 * V_73 ,
enum V_216 V_217 )
{
F_12 ( V_73 -> V_197 == V_34 ) ;
F_5 ( V_11 , L_45 , V_217 ) ;
switch ( V_217 ) {
case V_218 :
if ( F_45 ( & V_73 -> V_79 , V_80 ) )
F_111 () ;
break;
case V_219 :
break;
case V_220 : {
struct V_221 * V_222 = V_34 -> V_223 ;
F_112 ( V_222 , V_224 ) ;
break;
}
case V_225 :
F_5 ( V_18 , L_46 , V_34 -> V_49 ) ;
V_34 -> V_226 = 0 ;
F_100 ( V_34 ) ;
if ( F_45 ( & V_73 -> V_79 , V_80 ) )
F_113 () ;
break;
case V_227 :
break;
case V_228 :
case V_229 :
break;
default:
F_2 ( L_47 , V_217 ) ;
F_4 () ;
}
return 0 ;
}
static int F_114 ( struct V_33 * V_230 ,
struct V_15 * V_16 ,
T_1 V_231 ,
void * V_71 , int V_232 , bool V_233 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_234 * V_235 ;
struct V_118 * V_53 ;
struct V_236 V_237 ;
T_5 V_238 = 0 ;
char * V_239 ;
char * V_240 ;
int V_241 ;
int V_242 ;
int V_37 = 0 ;
int V_243 = 0 ;
F_12 ( V_27 -> V_30 != NULL ) ;
F_12 ( V_27 -> V_45 == V_27 -> V_30 ) ;
V_239 = F_24 ( V_244 , V_245 ) ;
if ( ! V_239 )
return - V_39 ;
V_242 = snprintf ( V_239 , V_244 , L_48 , V_27 -> V_30 ) ;
if ( V_242 >= V_244 ) {
F_19 ( V_239 ) ;
return - V_246 ;
}
++ V_242 ;
V_240 = V_239 + V_242 ;
V_241 = V_244 - V_242 ;
while ( V_232 > 0 ) {
int V_247 = sizeof( * V_235 ) ;
int V_248 ;
struct V_33 * V_34 ;
char * V_249 ;
char * V_250 ;
char * V_251 ;
char * V_252 ;
V_37 = - V_6 ;
if ( V_232 < sizeof( * V_235 ) )
break;
V_235 = ( F_115 ( V_235 ) ) ( V_71 + V_243 ) ;
if ( V_235 -> V_253 != 0 )
break;
if ( V_235 -> V_254 == 0 )
break;
if ( V_235 -> V_255 != sizeof( V_256 ) )
break;
V_247 += V_235 -> V_254 * V_235 -> V_255 ;
if ( V_232 < V_247 )
break;
if ( V_233 )
F_116 ( V_235 ) ;
if ( V_235 -> V_257 > V_244 ) {
F_2 ( L_49 , V_235 -> V_257 ) ;
break;
}
if ( V_235 -> V_257 < V_247 )
break;
V_243 += V_235 -> V_257 ;
V_232 -= V_235 -> V_257 ;
if ( V_232 < 0 )
break;
if ( V_235 -> V_258 > V_231 ) {
F_2 ( L_50 ,
V_235 -> V_258 , V_231 ) ;
break;
}
if ( V_238 >= V_235 -> V_258 ) {
F_2 ( L_51 ,
V_238 , V_235 -> V_258 ) ;
break;
}
V_238 = V_235 -> V_258 ;
V_248 = V_235 -> V_259 == V_260 ;
memset ( V_240 , 0 , V_241 ) ;
V_249 = V_240 ;
V_242 = 0 ;
strcpy ( V_249 , V_16 -> V_19 ) ;
V_250 = strrchr ( V_249 , '-' ) ;
if ( V_250 == NULL ) {
F_2 ( L_52 ,
V_230 -> V_49 , V_249 ) ;
break;
}
V_242 = V_250 - V_249 ;
V_249 [ V_242 ] = 0 ;
V_242 += sprintf ( V_249 + V_242 , L_53 ,
V_248 ? L_54 : L_55 , V_235 -> V_261 ) ;
V_250 = V_248 ? L_56 : L_57 ;
V_242 += sprintf ( V_249 + V_242 , L_58 , V_250 , V_239 ) ;
F_117 ( & V_237 , V_249 ) ;
V_34 = F_118 ( V_249 ) ;
if ( V_34 == NULL ) {
F_5 ( V_18 , L_59 ,
V_230 -> V_49 , V_249 ) ;
V_37 = 0 ;
continue;
}
++ V_242 ;
V_251 = V_240 + V_242 ;
V_242 += sprintf ( V_251 , L_60 , V_250 , L_61 ) ;
V_252 = V_240 + V_242 ;
F_48 ( & V_34 -> V_76 . V_77 . V_82 ) ;
if ( V_34 -> V_76 . V_77 . V_78 == NULL ) {
F_49 ( & V_34 -> V_76 . V_77 . V_82 ) ;
V_37 = 0 ;
continue;
}
V_37 = F_119 ( V_34 -> V_76 . V_77 . V_78 ,
V_235 -> V_76 . V_262 [ 0 ] ,
(struct V_263 * ) V_252 ) ;
F_49 ( & V_34 -> V_76 . V_77 . V_82 ) ;
if ( V_37 < 0 ) {
F_2 ( L_62 ,
F_120 ( V_235 -> V_76 . V_262 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_63 ,
V_252 , F_120 ( V_235 -> V_76 . V_262 [ 0 ] ) ) ;
V_242 += strlen ( V_252 ) ;
V_242 += sprintf ( V_240 + V_242 , L_64 , V_235 -> V_264 ) ;
F_12 ( V_242 < V_241 ) ;
F_121 ( & V_237 , 1 , V_251 ) ;
V_37 = - V_39 ;
V_53 = F_122 ( V_265 , & V_237 ) ;
if ( V_53 == NULL ) {
F_2 ( L_65 ) ;
break;
}
F_5 ( V_18 , L_66 ,
V_238 , V_231 , V_249 , V_251 ) ;
V_37 = F_123 ( V_53 ) ;
F_124 ( V_53 ) ;
if ( V_37 )
F_5 ( V_18 , L_67 ,
V_249 , V_37 ) ;
}
F_19 ( V_239 ) ;
return V_37 ;
}
static int F_125 ( struct V_33 * V_34 ,
struct V_15 * V_16 )
{
struct V_142 * V_143 = NULL ;
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_266 * V_267 ;
struct V_268 * V_269 ;
struct V_270 * V_128 ;
struct V_271 * * V_272 ;
int V_273 ;
bool V_274 = true ;
bool V_233 = false ;
int V_275 ;
int V_276 ;
int V_37 ;
V_273 = V_277 ;
if ( V_27 -> V_43 == 0 )
V_273 = V_278 ;
V_272 = F_126 ( V_273 , sizeof( * V_272 ) , V_245 ) ;
if ( V_272 == NULL ) {
V_37 = - V_39 ;
goto V_279;
}
for ( V_275 = 0 ; V_275 < V_273 ; V_275 ++ ) {
V_272 [ V_275 ] = F_127 ( V_245 ) ;
if ( V_272 [ V_275 ] == NULL ) {
V_37 = - V_39 ;
goto V_279;
}
}
V_280:
F_12 ( F_128 ( V_16 ) ) ;
F_12 ( F_129 ( & V_16 -> V_42 ) ) ;
V_143 = F_130 ( F_91 ( V_16 -> V_25 ) ,
& V_281 ) ;
if ( V_143 == NULL ) {
V_37 = - V_39 ;
goto V_279;
}
V_37 = F_131 ( V_143 , V_147 , V_282 ) ;
if ( V_37 )
goto V_279;
V_267 = F_92 ( & V_143 -> V_149 , & V_283 ) ;
F_12 ( V_267 != NULL ) ;
F_12 ( sizeof( V_267 -> V_284 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_132 ( V_267 -> V_284 , V_16 -> V_19 , sizeof( V_267 -> V_284 ) )
>= sizeof( V_267 -> V_284 ) ) {
V_37 = - V_246 ;
goto V_279;
}
V_267 -> V_285 = V_27 -> V_43 + 1 ;
V_267 -> V_286 = V_16 -> V_46 ;
V_267 -> V_287 = V_288 ;
V_267 -> V_289 = V_273 ;
V_128 = F_133 ( V_143 , V_273 , 1 , V_290 ,
V_291 ) ;
if ( V_128 == NULL ) {
V_37 = - V_39 ;
goto V_279;
}
for ( V_275 = 0 ; V_275 < V_273 ; V_275 ++ )
F_134 ( V_128 , V_272 [ V_275 ] , 0 , V_244 ) ;
F_94 ( V_143 ) ;
V_37 = F_95 ( V_143 ) ;
if ( V_37 )
goto V_279;
V_269 = F_96 ( & V_143 -> V_149 , & V_292 ) ;
if ( V_269 -> V_293 < V_269 -> V_294 ) {
V_37 = - V_6 ;
goto V_279;
}
V_27 -> V_43 = V_269 -> V_294 ;
V_274 = V_269 -> V_294 == V_269 -> V_293 ;
F_5 ( V_18 , L_68 ,
V_269 -> V_294 , V_274 == false ) ;
V_276 = F_135 ( V_143 , V_143 -> V_295 , 0 ) ;
if ( V_276 < 0 ) {
V_37 = V_276 ;
goto V_279;
}
if ( V_276 > V_273 << V_288 ) {
V_37 = - V_6 ;
goto V_279;
}
if ( V_276 == 0 ) {
if ( ! V_274 )
V_37 = - V_6 ;
goto V_279;
}
V_233 = ! ! F_136 ( V_143 ) ;
#if V_296 < F_137 ( 3 , 2 , 50 , 0 )
if ( F_40 ( V_143 -> V_297 -> V_298 ) )
V_233 = ! V_233 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_275 = 0 ; V_275 < V_273 && V_276 > 0 ; V_275 ++ ) {
int V_299 ;
void * V_60 ;
V_60 = F_138 ( V_272 [ V_275 ] ) ;
V_299 = F_114 ( V_34 , V_16 , V_269 -> V_294 , V_60 ,
F_139 ( int , V_276 , V_244 ) ,
V_233 ) ;
F_140 ( V_272 [ V_275 ] ) ;
if ( V_299 < 0 ) {
F_141 ( L_69 ,
V_16 -> V_19 , V_299 ) ;
break;
}
V_276 -= V_244 ;
}
V_279:
if ( V_143 )
F_93 ( V_143 ) ;
if ( V_37 == 0 && ! V_274 )
goto V_280;
if ( V_272 ) {
for ( V_275 = 0 ; V_275 < V_273 ; V_275 ++ ) {
if ( V_272 [ V_275 ] == NULL )
break;
F_142 ( V_272 [ V_275 ] ) ;
}
F_19 ( V_272 ) ;
}
return V_37 ;
}
static int F_143 ( struct V_33 * V_230 ,
struct V_15 * V_16 , int V_300 )
{
struct V_105 * V_106 ;
struct V_55 * V_56 = NULL ;
int V_37 = 0 ;
bool V_301 = false ;
struct V_103 * V_104 ;
F_12 ( V_16 ) ;
F_12 ( F_129 ( & V_16 -> V_42 ) ) ;
if ( F_16 ( V_16 ) && V_300 )
return 0 ;
if ( V_16 -> V_31 . V_45 )
V_56 = F_35 ( V_16 -> V_31 . V_45 ) ;
V_104 = F_24 ( sizeof( * V_104 ) , V_245 ) ;
if ( ! V_104 )
return - V_39 ;
V_37 = F_144 ( V_104 , V_302 ) ;
if ( V_37 )
goto V_303;
V_106 = F_60 ( V_230 , V_108 ) ;
F_12 ( V_106 ) ;
if ( V_300 ) {
V_37 = - V_304 ;
goto V_305;
}
if ( F_16 ( V_16 ) ) {
F_145 ( V_16 -> V_19 ) ;
V_301 = true ;
}
V_37 = F_146 ( V_104 , V_106 , V_16 -> V_19 ,
& V_16 -> V_31 ) ;
V_305:
F_147 ( V_104 , V_106 ) ;
if ( V_301 ) {
F_12 ( F_16 ( V_16 ) ) ;
F_148 ( V_16 -> V_19 ) ;
F_149 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_11 ) ) ;
}
F_150 ( V_104 ) ;
V_303:
F_19 ( V_104 ) ;
return V_37 ;
}
int F_31 ( struct V_33 * V_230 , struct V_15 * V_16 )
{
struct V_130 V_131 = { 0 } ;
T_1 V_157 = V_306 ;
int V_37 = 0 , V_307 ;
F_12 ( V_16 ) ;
F_39 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_32 ) {
F_41 ( & V_16 -> V_42 ) ;
return 0 ;
}
F_151 ( V_308 , 20 ) ;
F_5 ( V_11 , L_70 , V_16 -> V_19 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_43 + 1 ) ;
V_307 = F_97 ( V_230 -> V_76 . V_77 . V_309 , NULL , V_310 , NULL ,
V_311 , & V_157 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_131 ) ;
if ( V_307 == 0 ) {
F_8 ( V_16 ) ;
V_37 = F_152 ( & V_131 , ( void * ) V_16 ) ;
F_12 ( V_37 == 0 ) ;
} else {
F_5 ( V_11 , L_71 , V_307 ) ;
V_16 -> V_101 = 1 ;
F_8 ( V_16 ) ;
}
if ( F_128 ( V_16 ) ) {
V_37 = 0 ;
if ( V_307 == 0 )
V_37 = F_125 ( V_230 , V_16 ) ;
} else {
V_37 = F_143 ( V_230 , V_16 , V_307 != 0 ) ;
}
F_5 ( V_11 , L_72 ,
V_230 -> V_49 , V_16 -> V_19 , V_37 ? L_73 : L_74 , V_37 ) ;
F_41 ( & V_16 -> V_42 ) ;
if ( ! V_307 )
F_153 ( & V_131 , V_311 ) ;
return V_37 ;
}
static int F_154 ( struct V_33 * V_34 , T_4 V_2 , void * V_240 )
{
struct V_118 * V_53 = V_240 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_37 = 0 ;
switch ( V_53 -> V_312 ) {
case V_313 : {
struct V_179 * V_180 ;
if ( F_155 ( V_53 , 1 ) !=
sizeof( struct V_179 ) ) {
V_37 = - V_6 ;
goto V_279;
}
V_180 = (struct V_179 * ) F_156 ( V_53 , 1 ) ;
F_5 ( V_11 , L_75 ,
V_180 -> V_186 , V_180 -> V_314 ) ;
V_37 = F_101 ( V_34 -> V_76 . V_77 . V_309 , V_180 ) ;
break;
}
case V_315 :
F_2 ( L_76 ) ;
V_37 = - V_316 ;
break;
case V_317 : {
V_37 = F_157 ( V_53 ) ;
break;
}
case V_318 : {
struct V_15 * V_16 ;
struct V_35 * V_36 ;
V_13 = F_158 ( V_53 , 1 ) ;
V_27 = (struct V_26 * ) F_156 ( V_53 , 2 ) ;
V_36 = * (struct V_35 * * ) F_156 ( V_53 , 3 ) ;
F_5 ( V_11 , L_77 , V_13 ,
V_27 -> V_43 ) ;
V_37 = F_34 ( V_34 , V_13 , V_27 , V_36 ) ;
if ( V_37 )
break;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( V_16 == NULL ) {
V_37 = - V_52 ;
break;
}
V_16 -> V_31 . V_44 |= V_319 ;
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 == 0 && V_16 -> V_22 != NULL ) {
if ( F_45 ( & V_34 -> V_76 . V_77 . V_78 ->
V_79 , V_80 ) ) {
V_37 = F_31 ( V_34 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_320 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_11 ( V_320 ) ;
}
if ( V_37 )
F_2 ( L_78 , V_37 ) ;
}
if ( V_37 == 0 && V_16 -> V_24 != NULL ) {
V_37 = F_31 ( V_34 , V_16 -> V_24 ) ;
if ( V_37 == - V_52 ) {
F_5 ( V_11 ,
L_79 ) ;
V_37 = 0 ;
}
if ( V_37 )
F_2 (
L_80 ,
V_34 -> V_49 , V_37 ) ;
}
F_11 ( V_16 ) ;
break;
}
case V_321 : {
V_13 = F_158 ( V_53 , 1 ) ;
if ( V_53 -> V_322 >= 2 )
V_27 = (struct V_26 * ) F_156 (
V_53 , 2 ) ;
V_37 = F_38 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_81 , V_53 -> V_312 ) ;
V_37 = - V_6 ;
goto V_279;
}
}
V_279:
return V_37 ;
}
static int T_6 F_159 ( void )
{
return F_160 ( & V_323 , NULL ,
V_324 , NULL ) ;
}
static void F_161 ( void )
{
F_162 ( V_324 ) ;
}
