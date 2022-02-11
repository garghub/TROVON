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
F_12 ( V_13 ) ;
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
static struct V_15 *
F_32 ( struct V_33 * V_34 , char * V_12 ,
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
static struct V_15 *
F_33 ( struct V_33 * V_34 ,
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
if ( ! V_60 || V_60 - V_13 > 8 ) {
F_2 ( L_10 , V_13 ) ;
return - V_6 ;
}
memcpy ( V_59 , V_13 , V_60 - V_13 ) ;
strcpy ( V_59 + ( V_60 - V_13 ) , L_11 ) ;
V_57 = F_20 ( V_59 , NULL ) ;
if ( ! V_57 ) {
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
V_60 = strrchr ( V_59 , '-' ) ;
if ( V_60 ) {
* V_60 = 0 ;
} else {
F_2 ( L_15 ,
V_34 -> V_49 , V_59 , - V_6 ) ;
F_11 ( V_16 ) ;
return - V_6 ;
}
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
if ( ! V_16 )
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
F_5 ( V_11 , L_16 , V_13 ? V_13 : L_17 ,
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
F_44 ( V_70 , L_18 ,
F_45 ( V_75 , V_80 ) ? L_19 : L_20 ) ;
F_44 ( V_70 , L_21 ) ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( ! V_16 -> V_22 )
continue;
F_44 ( V_70 , L_22 ,
V_16 -> V_19 ,
V_16 -> V_22 -> V_31 . V_43 ) ;
}
F_15 ( & V_20 ) ;
F_46 ( & V_34 -> V_76 . V_77 . V_81 ) ;
return 0 ;
}
static void F_47 ( struct V_15 * V_16 )
{
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_48 ( & V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_81 ) ;
if ( V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_83 != 0 ) {
int V_37 ;
F_5 ( V_11 , L_23 , V_16 -> V_19 ) ;
V_37 = F_31 ( V_16 -> V_25 -> V_82 , V_16 ) ;
if ( V_37 && V_37 != - V_52 )
F_2 ( L_24 , V_37 ) ;
} else {
F_5 ( V_11 , L_25 ,
V_16 -> V_19 ) ;
}
F_46 ( & V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_81 ) ;
}
static int F_49 ( void * V_71 )
{
bool V_84 = true ;
F_5 ( V_11 , L_26 ) ;
F_21 ( & V_20 ) ;
V_85 |= V_86 ;
while ( 1 ) {
struct V_87 V_88 ;
struct V_15 * V_16 , * V_89 ;
int rand = F_50 () & V_90 ;
int V_91 = ! ! ( V_85 & V_92 ) ;
int V_93 ;
V_85 &= ~ ( V_94 | V_95 ) ;
F_15 ( & V_20 ) ;
if ( V_84 ) {
V_84 = false ;
F_51 ( & V_96 ) ;
}
V_93 = V_97 * V_98 ;
V_93 += rand * V_98 / 100 ;
V_88 = F_52 ( V_93 , NULL , NULL ) ;
F_53 ( V_99 , V_85 & ( V_92 | V_100 ) ,
& V_88 ) ;
V_89 = NULL ;
F_21 ( & V_20 ) ;
V_85 &= ~ V_100 ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( ! V_16 -> V_101 )
continue;
F_15 ( & V_20 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_89 )
F_11 ( V_89 ) ;
V_89 = V_16 ;
V_16 -> V_101 = 0 ;
if ( F_54 ( ! V_91 ) )
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
F_53 ( V_99 , V_85 & ( V_94 | V_92 ) ,
& V_88 ) ;
F_21 ( & V_20 ) ;
}
V_85 &= ~ V_86 ;
F_15 ( & V_20 ) ;
F_51 ( & V_102 ) ;
F_5 ( V_11 , L_27 ) ;
return 0 ;
}
static void F_55 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_28 ,
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
F_56 ( & V_99 ) ;
}
}
static int F_57 ( const struct V_103 * V_104 , struct V_33 * V_34 )
{
struct V_105 * V_106 ;
int V_37 ;
V_37 = F_58 ( V_104 , V_34 , & V_34 -> V_107 , V_108 , V_34 ,
& V_109 ) ;
if ( V_37 )
return V_37 ;
V_106 = F_59 ( V_34 , V_108 ) ;
F_12 ( V_106 ) ;
F_60 ( V_106 ) ;
F_61 ( V_106 ) ;
return 0 ;
}
static int F_62 ( const struct V_103 * V_104 , struct V_33 * V_34 )
{
struct V_105 * V_106 ;
V_106 = F_59 ( V_34 , V_108 ) ;
if ( V_106 )
F_63 ( V_104 , V_106 ) ;
return 0 ;
}
static int F_64 ( struct V_33 * V_34 , enum V_110 V_111 )
{
int V_37 = 0 ;
int V_112 ;
switch ( V_111 ) {
case V_113 :
break;
case V_114 :
if ( F_65 ( & V_115 ) ) {
F_12 ( V_85 & V_86 ) ;
V_112 = V_92 ;
} else {
V_112 = V_94 | V_100 ;
}
F_21 ( & V_20 ) ;
V_85 |= V_112 ;
F_15 ( & V_20 ) ;
F_56 ( & V_99 ) ;
if ( V_112 & V_92 )
F_66 ( & V_102 ) ;
F_67 ( V_34 ) ;
V_37 = F_62 ( NULL , V_34 ) ;
if ( V_37 != 0 )
F_2 ( L_29 ) ;
break;
}
return V_37 ;
}
static int F_68 ( struct V_33 * V_34 )
{
if ( V_34 -> V_116 -> V_117 <= 1 )
F_69 () ;
F_70 ( V_34 ) ;
F_71 () ;
return F_72 ( V_34 ) ;
}
static int F_73 ( struct V_33 * V_34 , struct V_118 * V_53 )
{
struct V_119 V_120 = { NULL } ;
struct V_121 * V_122 ;
int V_37 ;
V_37 = F_74 () ;
if ( V_37 < 0 )
goto V_123;
V_37 = F_75 ( V_34 , V_53 ) ;
if ( V_37 )
goto V_124;
V_37 = F_57 ( NULL , V_34 ) ;
if ( V_37 ) {
F_2 ( L_30 ) ;
goto V_125;
}
F_76 ( & V_120 ) ;
F_77 ( V_34 , V_120 . V_126 , V_120 . V_127 ) ;
F_78 ( V_34 ) ;
if ( F_79 ( & V_115 ) == 1 ) {
V_85 = 0 ;
F_80 ( & V_99 ) ;
V_122 = F_81 ( F_49 , NULL , L_31 ) ;
if ( F_36 ( V_122 ) ) {
V_37 = F_37 ( V_122 ) ;
F_2 ( L_32 ,
V_34 -> V_49 , V_37 ) ;
goto V_125;
}
V_37 = 0 ;
F_66 ( & V_96 ) ;
}
return V_37 ;
V_125:
F_72 ( V_34 ) ;
V_124:
F_71 () ;
V_123:
return V_37 ;
}
static int F_82 ( struct V_128 * V_129 , struct V_130 * V_131 ,
void * V_71 , int V_132 )
{
struct V_133 V_134 ;
struct V_15 * V_16 = V_71 ;
int V_37 = 0 ;
switch ( V_132 ) {
case V_135 :
F_83 ( V_129 , L_33 ) ;
F_84 ( V_129 , & V_134 ) ;
V_37 = F_85 ( & V_134 , V_136 ) ;
break;
case V_137 :
F_83 ( V_129 , L_34 ) ;
F_5 ( V_11 , L_35 V_138 L_36 ,
F_86 ( V_129 -> V_139 ) ,
( char * ) & V_129 -> V_139 -> V_140 . V_1 [ 0 ] ) ;
if ( ! V_16 ) {
F_5 ( V_18 , L_37 ) ;
break;
}
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_16 -> V_32 ) {
F_5 ( V_11 , L_38 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
if ( ! V_129 -> V_141 ||
! V_129 -> V_141 -> V_82 -> V_76 . V_77 . V_83 ) {
F_5 ( V_11 , L_39 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
F_55 ( V_16 ) ;
F_11 ( V_16 ) ;
break;
default:
F_4 () ;
}
return V_37 ;
}
static int F_87 ( struct V_142 * exp ,
struct V_143 * V_144 )
{
struct V_145 * V_146 ;
struct V_143 * V_147 , * V_148 ;
int V_37 ;
V_146 = F_88 ( F_89 ( exp ) ,
& V_149 , V_150 ,
V_151 ) ;
if ( ! V_146 )
return - V_39 ;
V_147 = F_90 ( & V_146 -> V_152 , & V_153 ) ;
if ( ! V_147 ) {
F_91 ( V_146 ) ;
return - V_39 ;
}
memcpy ( V_147 , V_144 , sizeof( * V_147 ) ) ;
F_92 ( V_146 ) ;
V_146 -> V_154 = V_155 ;
V_37 = F_93 ( V_146 ) ;
if ( ! V_37 ) {
V_148 = F_94 ( & V_146 -> V_152 , & V_153 ) ;
memcpy ( V_144 , V_148 , sizeof( * V_148 ) ) ;
}
F_91 ( V_146 ) ;
return V_37 ;
}
static int F_95 ( struct V_142 * exp , struct V_156 * V_157 ,
T_2 type , T_3 * V_158 , T_2 V_159 ,
T_1 * V_160 , void * V_161 , void * V_162 , void * V_163 ,
void * V_71 , T_2 V_164 , void * V_165 ,
struct V_133 * V_134 )
{
struct V_15 * V_16 = V_71 ;
struct V_166 V_167 = {
. V_168 = type ,
. V_169 = V_159 ,
. V_170 = F_82 ,
. V_171 = V_172 ,
} ;
struct V_145 * V_146 ;
int V_173 = F_16 ( V_16 ) ;
int V_37 ;
F_5 ( V_11 , L_40 , V_16 -> V_19 ,
V_16 -> V_50 . V_1 [ 0 ] ) ;
V_146 = F_88 ( F_89 ( exp ) ,
& V_174 , V_175 ,
V_176 ) ;
if ( ! V_146 )
return - V_39 ;
F_96 ( & V_146 -> V_152 , & V_177 , V_178 , 0 ) ;
F_92 ( V_146 ) ;
V_146 -> V_154 = V_173 ? 5 : V_179 ;
V_37 = F_97 ( exp , & V_146 , & V_167 , & V_16 -> V_50 , NULL , V_160 ,
NULL , 0 , V_180 , V_134 , 0 ) ;
F_91 ( V_146 ) ;
return V_37 ;
}
static void F_98 ( struct V_33 * V_181 )
{
F_21 ( & V_20 ) ;
V_85 |= V_94 ;
F_15 ( & V_20 ) ;
F_56 ( & V_99 ) ;
}
static int F_99 ( struct V_142 * exp ,
struct V_182 * V_183 )
{
struct V_145 * V_146 ;
struct V_182 * V_184 , * V_185 ;
int V_37 ;
V_146 = F_88 ( F_89 ( exp ) ,
& V_186 , V_150 ,
V_187 ) ;
if ( ! V_146 )
return - V_39 ;
V_184 = F_90 ( & V_146 -> V_152 , & V_188 ) ;
if ( ! V_184 ) {
F_91 ( V_146 ) ;
return - V_39 ;
}
memcpy ( V_184 , V_183 , sizeof( * V_184 ) ) ;
F_92 ( V_146 ) ;
F_5 ( V_11 , L_41 , V_183 -> V_189 ) ;
V_146 -> V_154 = V_190 ;
V_37 = F_93 ( V_146 ) ;
if ( ! V_37 ) {
V_185 = F_94 ( & V_146 -> V_152 ,
& V_188 ) ;
memcpy ( V_183 , V_185 , sizeof( * V_185 ) ) ;
F_5 ( V_11 , L_42 ,
V_183 -> V_189 , V_183 -> V_191 ) ;
}
F_91 ( V_146 ) ;
return V_37 ;
}
static int F_100 ( const struct V_103 * V_104 , struct V_142 * exp ,
T_4 V_192 , void * V_193 , T_4 V_194 ,
void * V_195 , struct V_196 * V_197 )
{
int V_37 = - V_6 ;
if ( F_101 ( V_198 ) ) {
struct V_72 * V_73 = F_89 ( exp ) ;
int V_199 ;
if ( V_194 != sizeof( int ) )
return - V_6 ;
V_199 = * ( int * ) V_195 ;
F_5 ( V_11 , L_43 ,
V_73 -> V_200 -> V_49 , V_199 ,
V_73 -> V_201 , V_73 -> V_202 ,
V_73 -> V_203 , V_73 -> V_200 -> V_204 ,
F_102 ( V_73 -> V_205 ) ) ;
if ( ( V_73 -> V_205 != V_206 &&
V_73 -> V_205 != V_207 ) || V_199 > 1 )
F_103 ( V_73 ) ;
return 0 ;
}
if ( F_101 ( V_208 ) ) {
struct V_143 * V_144 ;
V_144 = V_195 ;
V_37 = F_87 ( exp , V_144 ) ;
return V_37 ;
}
if ( F_101 ( V_209 ) ) {
struct V_210 * V_77 = & exp -> V_82 -> V_76 . V_77 ;
struct V_211 V_212 ;
if ( V_194 == 0 ) {
if ( V_77 -> V_213 . V_214 != V_215 )
return 0 ;
V_195 = L_44 ;
V_194 = 4 ;
}
V_37 = F_104 ( V_195 , & V_212 ) ;
if ( V_37 ) {
F_2 ( L_45 ,
( char * ) V_195 ) ;
return V_37 ;
}
if ( V_77 -> V_213 . V_214 == V_215 ) {
V_77 -> V_213 = V_212 ;
} else if ( memcmp ( & V_77 -> V_213 , & V_212 ,
sizeof( V_212 ) ) != 0 ) {
char V_216 [ 20 ] ;
F_105 ( & V_77 -> V_213 ,
V_216 , sizeof( V_216 ) ) ;
F_106 ( L_46 ,
( char * ) V_195 , V_216 ) ;
V_37 = - V_217 ;
}
return V_37 ;
}
return V_37 ;
}
static int F_107 ( const struct V_103 * V_104 , struct V_142 * exp ,
T_2 V_192 , void * V_193 , T_2 * V_194 , void * V_195 ,
struct V_156 * V_181 )
{
int V_37 = - V_6 ;
if ( F_101 ( V_218 ) ) {
struct V_72 * V_73 = F_89 ( exp ) ;
struct V_74 * V_71 = V_195 ;
if ( * V_194 == sizeof( * V_71 ) ) {
* V_71 = V_73 -> V_79 ;
V_37 = 0 ;
}
}
return V_37 ;
}
static int F_108 ( struct V_33 * V_34 ,
struct V_72 * V_73 ,
enum V_219 V_220 )
{
F_12 ( V_73 -> V_200 == V_34 ) ;
F_5 ( V_11 , L_47 , V_220 ) ;
switch ( V_220 ) {
case V_221 :
if ( F_45 ( & V_73 -> V_79 , V_80 ) )
F_109 () ;
break;
case V_222 :
break;
case V_223 : {
struct V_224 * V_225 = V_34 -> V_226 ;
F_110 ( V_225 , V_227 ) ;
break;
}
case V_228 :
F_5 ( V_18 , L_48 , V_34 -> V_49 ) ;
V_34 -> V_229 = 0 ;
F_98 ( V_34 ) ;
if ( F_45 ( & V_73 -> V_79 , V_80 ) )
F_111 () ;
break;
case V_230 :
break;
case V_231 :
case V_232 :
break;
default:
F_2 ( L_49 , V_220 ) ;
F_4 () ;
}
return 0 ;
}
static int F_112 ( struct V_33 * V_233 ,
struct V_15 * V_16 ,
T_1 V_234 ,
void * V_71 , int V_235 , bool V_236 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_237 * V_238 ;
struct V_118 * V_53 ;
struct V_239 V_240 ;
T_5 V_241 = 0 ;
char * V_242 ;
char * V_243 ;
int V_244 ;
int V_245 ;
int V_37 = 0 ;
int V_246 = 0 ;
F_12 ( V_27 -> V_30 ) ;
F_12 ( V_27 -> V_45 == V_27 -> V_30 ) ;
V_242 = F_24 ( V_247 , V_248 ) ;
if ( ! V_242 )
return - V_39 ;
V_245 = snprintf ( V_242 , V_247 , L_50 , V_27 -> V_30 ) ;
if ( V_245 >= V_247 ) {
F_19 ( V_242 ) ;
return - V_249 ;
}
++ V_245 ;
V_243 = V_242 + V_245 ;
V_244 = V_247 - V_245 ;
while ( V_235 > 0 ) {
int V_250 = sizeof( * V_238 ) ;
int V_251 ;
struct V_33 * V_34 ;
char * V_252 ;
char * V_253 ;
char * V_254 ;
char * V_255 ;
V_37 = - V_6 ;
if ( V_235 < sizeof( * V_238 ) )
break;
V_238 = ( F_113 ( V_238 ) ) ( V_71 + V_246 ) ;
if ( V_238 -> V_256 != 0 )
break;
if ( V_238 -> V_257 == 0 )
break;
if ( V_238 -> V_258 != sizeof( V_259 ) )
break;
V_250 += V_238 -> V_257 * V_238 -> V_258 ;
if ( V_235 < V_250 )
break;
if ( V_236 )
F_114 ( V_238 ) ;
if ( V_238 -> V_260 > V_247 ) {
F_2 ( L_51 , V_238 -> V_260 ) ;
break;
}
if ( V_238 -> V_260 < V_250 )
break;
V_246 += V_238 -> V_260 ;
V_235 -= V_238 -> V_260 ;
if ( V_235 < 0 )
break;
if ( V_238 -> V_261 > V_234 ) {
F_2 ( L_52 ,
V_238 -> V_261 , V_234 ) ;
break;
}
if ( V_241 >= V_238 -> V_261 ) {
F_2 ( L_53 ,
V_241 , V_238 -> V_261 ) ;
break;
}
V_241 = V_238 -> V_261 ;
V_251 = V_238 -> V_262 == V_263 ;
memset ( V_243 , 0 , V_244 ) ;
V_252 = V_243 ;
V_245 = 0 ;
strcpy ( V_252 , V_16 -> V_19 ) ;
V_253 = strrchr ( V_252 , '-' ) ;
if ( ! V_253 ) {
F_2 ( L_54 ,
V_233 -> V_49 , V_252 ) ;
break;
}
V_245 = V_253 - V_252 ;
V_252 [ V_245 ] = 0 ;
V_245 += sprintf ( V_252 + V_245 , L_55 ,
V_251 ? L_56 : L_57 , V_238 -> V_264 ) ;
V_253 = V_251 ? L_58 : L_59 ;
V_245 += sprintf ( V_252 + V_245 , L_60 , V_253 , V_242 ) ;
F_115 ( & V_240 , V_252 ) ;
V_34 = F_116 ( V_252 ) ;
if ( ! V_34 ) {
F_5 ( V_18 , L_61 ,
V_233 -> V_49 , V_252 ) ;
V_37 = 0 ;
continue;
}
++ V_245 ;
V_254 = V_243 + V_245 ;
V_245 += sprintf ( V_254 , L_62 , V_253 , L_63 ) ;
V_255 = V_243 + V_245 ;
F_48 ( & V_34 -> V_76 . V_77 . V_81 ) ;
if ( ! V_34 -> V_76 . V_77 . V_78 ) {
F_46 ( & V_34 -> V_76 . V_77 . V_81 ) ;
V_37 = 0 ;
continue;
}
V_37 = F_117 ( V_34 -> V_76 . V_77 . V_78 ,
V_238 -> V_76 . V_265 [ 0 ] ,
(struct V_266 * ) V_255 ) ;
F_46 ( & V_34 -> V_76 . V_77 . V_81 ) ;
if ( V_37 < 0 ) {
F_2 ( L_64 ,
F_118 ( V_238 -> V_76 . V_265 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_65 ,
V_255 , F_118 ( V_238 -> V_76 . V_265 [ 0 ] ) ) ;
V_245 += strlen ( V_255 ) ;
V_245 += sprintf ( V_243 + V_245 , L_66 , V_238 -> V_267 ) ;
F_12 ( V_245 < V_244 ) ;
F_119 ( & V_240 , 1 , V_254 ) ;
V_37 = - V_39 ;
V_53 = F_120 ( V_268 , & V_240 ) ;
if ( F_36 ( V_53 ) ) {
F_2 ( L_67 ) ;
break;
}
F_5 ( V_18 , L_68 ,
V_241 , V_234 , V_252 , V_254 ) ;
V_37 = F_121 ( V_53 ) ;
F_122 ( V_53 ) ;
if ( V_37 )
F_5 ( V_18 , L_69 ,
V_252 , V_37 ) ;
}
F_19 ( V_242 ) ;
return V_37 ;
}
static int F_123 ( struct V_33 * V_34 ,
struct V_15 * V_16 )
{
struct V_145 * V_146 = NULL ;
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_269 * V_270 ;
struct V_271 * V_272 ;
struct V_273 * V_131 ;
struct V_274 * * V_275 ;
int V_276 ;
bool V_277 = true ;
bool V_236 ;
int V_278 ;
int V_279 ;
int V_37 ;
V_276 = V_280 ;
if ( V_27 -> V_43 == 0 )
V_276 = V_281 ;
V_275 = F_124 ( V_276 , sizeof( * V_275 ) , V_248 ) ;
if ( ! V_275 ) {
V_37 = - V_39 ;
goto V_282;
}
for ( V_278 = 0 ; V_278 < V_276 ; V_278 ++ ) {
V_275 [ V_278 ] = F_125 ( V_248 ) ;
if ( ! V_275 [ V_278 ] ) {
V_37 = - V_39 ;
goto V_282;
}
}
V_283:
F_12 ( F_126 ( V_16 ) ) ;
F_12 ( F_127 ( & V_16 -> V_42 ) ) ;
V_146 = F_128 ( F_89 ( V_16 -> V_25 ) ,
& V_284 ) ;
if ( ! V_146 ) {
V_37 = - V_39 ;
goto V_282;
}
V_37 = F_129 ( V_146 , V_150 , V_285 ) ;
if ( V_37 )
goto V_282;
V_270 = F_90 ( & V_146 -> V_152 , & V_286 ) ;
F_12 ( sizeof( V_270 -> V_287 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_130 ( V_270 -> V_287 , V_16 -> V_19 , sizeof( V_270 -> V_287 ) )
>= sizeof( V_270 -> V_287 ) ) {
V_37 = - V_249 ;
goto V_282;
}
V_270 -> V_288 = V_27 -> V_43 + 1 ;
V_270 -> V_289 = V_16 -> V_46 ;
V_270 -> V_290 = V_291 ;
V_270 -> V_292 = V_276 ;
V_131 = F_131 ( V_146 , V_276 , 1 , V_293 ,
V_294 ) ;
if ( ! V_131 ) {
V_37 = - V_39 ;
goto V_282;
}
for ( V_278 = 0 ; V_278 < V_276 ; V_278 ++ )
F_132 ( V_131 , V_275 [ V_278 ] , 0 , V_247 ) ;
F_92 ( V_146 ) ;
V_37 = F_93 ( V_146 ) ;
if ( V_37 )
goto V_282;
V_272 = F_94 ( & V_146 -> V_152 , & V_295 ) ;
if ( V_272 -> V_296 < V_272 -> V_297 ) {
V_37 = - V_6 ;
goto V_282;
}
V_27 -> V_43 = V_272 -> V_297 ;
V_277 = V_272 -> V_297 == V_272 -> V_296 ;
F_5 ( V_18 , L_70 ,
V_272 -> V_297 , V_277 == false ) ;
V_279 = F_133 ( V_146 , V_146 -> V_298 , 0 ) ;
if ( V_279 < 0 ) {
V_37 = V_279 ;
goto V_282;
}
if ( V_279 > V_276 << V_291 ) {
V_37 = - V_6 ;
goto V_282;
}
if ( V_279 == 0 ) {
if ( ! V_277 )
V_37 = - V_6 ;
goto V_282;
}
V_236 = ! ! F_134 ( V_146 ) ;
#if V_299 < F_135 ( 3 , 2 , 50 , 0 )
if ( F_40 ( V_146 -> V_300 -> V_301 ) )
V_236 = ! V_236 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_278 = 0 ; V_278 < V_276 && V_279 > 0 ; V_278 ++ ) {
int V_302 ;
void * V_60 ;
V_60 = F_136 ( V_275 [ V_278 ] ) ;
V_302 = F_112 ( V_34 , V_16 , V_272 -> V_297 , V_60 ,
F_137 ( int , V_279 , V_247 ) ,
V_236 ) ;
F_138 ( V_275 [ V_278 ] ) ;
if ( V_302 < 0 ) {
F_139 ( L_71 ,
V_16 -> V_19 , V_302 ) ;
break;
}
V_279 -= V_247 ;
}
V_282:
if ( V_146 )
F_91 ( V_146 ) ;
if ( V_37 == 0 && ! V_277 )
goto V_283;
if ( V_275 ) {
for ( V_278 = 0 ; V_278 < V_276 ; V_278 ++ ) {
if ( ! V_275 [ V_278 ] )
break;
F_140 ( V_275 [ V_278 ] ) ;
}
F_19 ( V_275 ) ;
}
return V_37 ;
}
static int F_141 ( struct V_33 * V_233 ,
struct V_15 * V_16 , int V_303 )
{
struct V_105 * V_106 ;
struct V_55 * V_56 = NULL ;
int V_37 = 0 ;
bool V_304 = false ;
struct V_103 * V_104 ;
F_12 ( V_16 ) ;
F_12 ( F_127 ( & V_16 -> V_42 ) ) ;
if ( F_16 ( V_16 ) && V_303 )
return 0 ;
if ( V_16 -> V_31 . V_45 )
V_56 = F_35 ( V_16 -> V_31 . V_45 ) ;
V_104 = F_24 ( sizeof( * V_104 ) , V_248 ) ;
if ( ! V_104 )
return - V_39 ;
V_37 = F_142 ( V_104 , V_305 ) ;
if ( V_37 )
goto V_306;
V_106 = F_59 ( V_233 , V_108 ) ;
F_12 ( V_106 ) ;
if ( V_303 ) {
V_37 = - V_307 ;
goto V_308;
}
if ( F_16 ( V_16 ) ) {
F_143 ( V_16 -> V_19 ) ;
V_304 = true ;
}
V_37 = F_144 ( V_104 , V_106 , V_16 -> V_19 ,
& V_16 -> V_31 ) ;
V_308:
F_145 ( V_104 , V_106 ) ;
if ( V_304 ) {
F_12 ( F_16 ( V_16 ) ) ;
F_146 ( V_16 -> V_19 ) ;
F_147 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_11 ) ) ;
}
F_148 ( V_104 ) ;
V_306:
F_19 ( V_104 ) ;
return V_37 ;
}
int F_31 ( struct V_33 * V_233 , struct V_15 * V_16 )
{
struct V_133 V_134 = { 0 } ;
T_1 V_160 = V_309 ;
int V_37 = 0 , V_310 ;
F_12 ( V_16 ) ;
F_39 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_32 ) {
F_41 ( & V_16 -> V_42 ) ;
return 0 ;
}
F_149 ( V_311 , 20 ) ;
F_5 ( V_11 , L_72 , V_16 -> V_19 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_43 + 1 ) ;
V_310 = F_95 ( V_233 -> V_76 . V_77 . V_312 , NULL , V_313 , NULL ,
V_314 , & V_160 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_134 ) ;
if ( V_310 == 0 ) {
F_8 ( V_16 ) ;
V_37 = F_150 ( & V_134 , ( void * ) V_16 ) ;
F_12 ( V_37 == 0 ) ;
} else {
F_5 ( V_11 , L_73 , V_310 ) ;
V_16 -> V_101 = 1 ;
F_8 ( V_16 ) ;
}
if ( F_126 ( V_16 ) ) {
V_37 = 0 ;
if ( V_310 == 0 )
V_37 = F_123 ( V_233 , V_16 ) ;
} else {
V_37 = F_141 ( V_233 , V_16 , V_310 != 0 ) ;
}
F_5 ( V_11 , L_74 ,
V_233 -> V_49 , V_16 -> V_19 , V_37 ? L_75 : L_76 , V_37 ) ;
F_41 ( & V_16 -> V_42 ) ;
if ( ! V_310 )
F_151 ( & V_134 , V_314 ) ;
return V_37 ;
}
static int F_152 ( struct V_33 * V_34 , T_4 V_2 , void * V_243 )
{
struct V_118 * V_53 = V_243 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_37 = 0 ;
switch ( V_53 -> V_315 ) {
case V_316 : {
struct V_182 * V_183 ;
if ( F_153 ( V_53 , 1 ) !=
sizeof( struct V_182 ) ) {
V_37 = - V_6 ;
goto V_282;
}
V_183 = (struct V_182 * ) F_154 ( V_53 , 1 ) ;
F_5 ( V_11 , L_77 ,
V_183 -> V_189 , V_183 -> V_317 ) ;
V_37 = F_99 ( V_34 -> V_76 . V_77 . V_312 , V_183 ) ;
break;
}
case V_318 :
F_2 ( L_78 ) ;
V_37 = - V_319 ;
break;
case V_320 : {
V_37 = F_155 ( V_53 ) ;
break;
}
case V_321 : {
struct V_15 * V_16 ;
struct V_35 * V_36 ;
V_13 = F_156 ( V_53 , 1 ) ;
V_27 = (struct V_26 * ) F_154 ( V_53 , 2 ) ;
V_36 = * (struct V_35 * * ) F_154 ( V_53 , 3 ) ;
F_5 ( V_11 , L_79 , V_13 ,
V_27 -> V_43 ) ;
V_37 = F_34 ( V_34 , V_13 , V_27 , V_36 ) ;
if ( V_37 )
break;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( ! V_16 ) {
V_37 = - V_52 ;
break;
}
V_16 -> V_31 . V_44 |= V_322 ;
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 == 0 && V_16 -> V_22 ) {
if ( F_45 ( & V_34 -> V_76 . V_77 . V_78 ->
V_79 , V_80 ) ) {
V_37 = F_31 ( V_34 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_323 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_11 ( V_323 ) ;
}
if ( V_37 )
F_2 ( L_80 , V_37 ) ;
}
if ( V_37 == 0 && V_16 -> V_24 ) {
V_37 = F_31 ( V_34 , V_16 -> V_24 ) ;
if ( V_37 == - V_52 ) {
F_5 ( V_11 ,
L_81 ) ;
V_37 = 0 ;
}
if ( V_37 )
F_2 (
L_82 ,
V_34 -> V_49 , V_37 ) ;
}
F_11 ( V_16 ) ;
break;
}
case V_324 : {
V_13 = F_156 ( V_53 , 1 ) ;
if ( V_53 -> V_325 >= 2 )
V_27 = (struct V_26 * ) F_154 (
V_53 , 2 ) ;
V_37 = F_38 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_83 , V_53 -> V_315 ) ;
V_37 = - V_6 ;
goto V_282;
}
}
V_282:
return V_37 ;
}
static int T_6 F_157 ( void )
{
return F_158 ( & V_326 , NULL ,
V_327 , NULL ) ;
}
static void F_159 ( void )
{
F_160 ( V_327 ) ;
}
