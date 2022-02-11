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
F_48 ( & V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_81 ,
V_83 ) ;
if ( V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_84 != 0 ) {
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
bool V_85 = true ;
F_5 ( V_11 , L_26 ) ;
F_21 ( & V_20 ) ;
V_86 |= V_87 ;
while ( 1 ) {
struct V_88 V_89 ;
struct V_15 * V_16 , * V_90 ;
int rand = F_50 () & V_91 ;
int V_92 = ! ! ( V_86 & V_93 ) ;
int V_94 ;
V_86 &= ~ ( V_95 | V_96 ) ;
F_15 ( & V_20 ) ;
if ( V_85 ) {
V_85 = false ;
F_51 ( & V_97 ) ;
}
V_94 = V_98 * V_99 ;
V_94 += rand * V_99 / 100 ;
V_89 = F_52 ( V_94 , NULL , NULL ) ;
F_53 ( V_100 , V_86 & ( V_93 | V_101 ) ,
& V_89 ) ;
V_90 = NULL ;
F_21 ( & V_20 ) ;
V_86 &= ~ V_101 ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( ! V_16 -> V_102 )
continue;
F_15 ( & V_20 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_90 )
F_11 ( V_90 ) ;
V_90 = V_16 ;
V_16 -> V_102 = 0 ;
if ( F_54 ( ! V_92 ) )
F_47 ( V_16 ) ;
F_21 ( & V_20 ) ;
}
F_15 ( & V_20 ) ;
if ( V_90 )
F_11 ( V_90 ) ;
if ( F_40 ( V_92 ) ) {
F_21 ( & V_20 ) ;
break;
}
V_89 = (struct V_88 ) { 0 } ;
F_53 ( V_100 , V_86 & ( V_95 | V_93 ) ,
& V_89 ) ;
F_21 ( & V_20 ) ;
}
V_86 &= ~ V_87 ;
F_15 ( & V_20 ) ;
F_51 ( & V_103 ) ;
F_5 ( V_11 , L_27 ) ;
return 0 ;
}
static void F_55 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_28 ,
V_16 -> V_19 , F_10 ( & V_16 -> V_17 ) ,
V_16 -> V_32 , V_86 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_39 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_32 || V_16 -> V_102 ) {
F_41 ( & V_16 -> V_42 ) ;
return;
}
F_8 ( V_16 ) ;
V_16 -> V_102 = 1 ;
F_41 ( & V_16 -> V_42 ) ;
F_21 ( & V_20 ) ;
if ( V_86 & V_93 ) {
F_15 ( & V_20 ) ;
V_16 -> V_102 = 0 ;
F_11 ( V_16 ) ;
} else {
V_86 |= V_95 ;
F_15 ( & V_20 ) ;
F_56 ( & V_100 ) ;
}
}
static int F_57 ( const struct V_104 * V_105 , struct V_33 * V_34 )
{
struct V_106 * V_107 ;
int V_37 ;
V_37 = F_58 ( V_105 , V_34 , & V_34 -> V_108 , V_109 , V_34 ,
& V_110 ) ;
if ( V_37 )
return V_37 ;
V_107 = F_59 ( V_34 , V_109 ) ;
F_12 ( V_107 ) ;
F_60 ( V_107 ) ;
F_61 ( V_107 ) ;
return 0 ;
}
static int F_62 ( const struct V_104 * V_105 , struct V_33 * V_34 )
{
struct V_106 * V_107 ;
V_107 = F_59 ( V_34 , V_109 ) ;
if ( V_107 )
F_63 ( V_105 , V_107 ) ;
return 0 ;
}
static int F_64 ( struct V_33 * V_34 , enum V_111 V_112 )
{
int V_37 = 0 ;
int V_113 ;
switch ( V_112 ) {
case V_114 :
break;
case V_115 :
if ( F_65 ( & V_116 ) ) {
F_12 ( V_86 & V_87 ) ;
V_113 = V_93 ;
} else {
V_113 = V_95 | V_101 ;
}
F_21 ( & V_20 ) ;
V_86 |= V_113 ;
F_15 ( & V_20 ) ;
F_56 ( & V_100 ) ;
if ( V_113 & V_93 )
F_66 ( & V_103 ) ;
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
if ( V_34 -> V_117 -> V_118 <= 1 )
F_69 () ;
F_70 ( V_34 ) ;
F_71 () ;
return F_72 ( V_34 ) ;
}
static int F_73 ( struct V_33 * V_34 , struct V_119 * V_53 )
{
struct V_120 V_121 = { NULL } ;
struct V_122 * V_123 ;
int V_37 ;
V_37 = F_74 () ;
if ( V_37 < 0 )
goto V_124;
V_37 = F_75 ( V_34 , V_53 ) ;
if ( V_37 )
goto V_125;
V_37 = F_57 ( NULL , V_34 ) ;
if ( V_37 ) {
F_2 ( L_30 ) ;
goto V_126;
}
F_76 ( & V_121 ) ;
F_77 ( V_34 , V_121 . V_127 , V_121 . V_128 ) ;
F_78 ( V_34 ) ;
if ( F_79 ( & V_116 ) == 1 ) {
V_86 = 0 ;
F_80 ( & V_100 ) ;
V_123 = F_81 ( F_49 , NULL , L_31 ) ;
if ( F_36 ( V_123 ) ) {
V_37 = F_37 ( V_123 ) ;
F_2 ( L_32 ,
V_34 -> V_49 , V_37 ) ;
goto V_126;
}
V_37 = 0 ;
F_66 ( & V_97 ) ;
}
return V_37 ;
V_126:
F_72 ( V_34 ) ;
V_125:
F_71 () ;
V_124:
return V_37 ;
}
static int F_82 ( struct V_129 * V_130 , struct V_131 * V_132 ,
void * V_71 , int V_133 )
{
struct V_134 V_135 ;
struct V_15 * V_16 = V_71 ;
int V_37 = 0 ;
switch ( V_133 ) {
case V_136 :
F_83 ( V_130 , L_33 ) ;
F_84 ( V_130 , & V_135 ) ;
V_37 = F_85 ( & V_135 , V_137 ) ;
break;
case V_138 :
F_83 ( V_130 , L_34 ) ;
F_5 ( V_11 , L_35 V_139 L_36 ,
F_86 ( V_130 -> V_140 ) ,
( char * ) & V_130 -> V_140 -> V_141 . V_1 [ 0 ] ) ;
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
if ( ! V_130 -> V_142 ||
! V_130 -> V_142 -> V_82 -> V_76 . V_77 . V_84 ) {
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
static int F_87 ( struct V_143 * exp ,
struct V_144 * V_145 )
{
struct V_146 * V_147 ;
struct V_144 * V_148 , * V_149 ;
int V_37 ;
V_147 = F_88 ( F_89 ( exp ) ,
& V_150 , V_151 ,
V_152 ) ;
if ( ! V_147 )
return - V_39 ;
V_148 = F_90 ( & V_147 -> V_153 , & V_154 ) ;
if ( ! V_148 ) {
F_91 ( V_147 ) ;
return - V_39 ;
}
memcpy ( V_148 , V_145 , sizeof( * V_148 ) ) ;
F_92 ( V_147 ) ;
V_147 -> V_155 = V_156 ;
V_37 = F_93 ( V_147 ) ;
if ( ! V_37 ) {
V_149 = F_94 ( & V_147 -> V_153 , & V_154 ) ;
memcpy ( V_145 , V_149 , sizeof( * V_149 ) ) ;
}
F_91 ( V_147 ) ;
return V_37 ;
}
static int F_95 ( struct V_143 * exp , struct V_157 * V_158 ,
T_2 type , T_3 * V_159 , T_2 V_160 ,
T_1 * V_161 , void * V_162 , void * V_163 , void * V_164 ,
void * V_71 , T_2 V_165 , void * V_166 ,
struct V_134 * V_135 )
{
struct V_15 * V_16 = V_71 ;
struct V_167 V_168 = {
. V_169 = type ,
. V_170 = V_160 ,
. V_171 = F_82 ,
. V_172 = V_173 ,
} ;
struct V_146 * V_147 ;
int V_174 = F_16 ( V_16 ) ;
int V_37 ;
F_5 ( V_11 , L_40 , V_16 -> V_19 ,
V_16 -> V_50 . V_1 [ 0 ] ) ;
V_147 = F_88 ( F_89 ( exp ) ,
& V_175 , V_176 ,
V_177 ) ;
if ( ! V_147 )
return - V_39 ;
F_96 ( & V_147 -> V_153 , & V_178 , V_179 , 0 ) ;
F_92 ( V_147 ) ;
V_147 -> V_155 = V_174 ? 5 : V_180 ;
V_37 = F_97 ( exp , & V_147 , & V_168 , & V_16 -> V_50 , NULL , V_161 ,
NULL , 0 , V_181 , V_135 , 0 ) ;
F_91 ( V_147 ) ;
return V_37 ;
}
static void F_98 ( struct V_33 * V_182 )
{
F_21 ( & V_20 ) ;
V_86 |= V_95 ;
F_15 ( & V_20 ) ;
F_56 ( & V_100 ) ;
}
static int F_99 ( struct V_143 * exp ,
struct V_183 * V_184 )
{
struct V_146 * V_147 ;
struct V_183 * V_185 , * V_186 ;
int V_37 ;
V_147 = F_88 ( F_89 ( exp ) ,
& V_187 , V_151 ,
V_188 ) ;
if ( ! V_147 )
return - V_39 ;
V_185 = F_90 ( & V_147 -> V_153 , & V_189 ) ;
if ( ! V_185 ) {
F_91 ( V_147 ) ;
return - V_39 ;
}
memcpy ( V_185 , V_184 , sizeof( * V_185 ) ) ;
F_92 ( V_147 ) ;
F_5 ( V_11 , L_41 , V_184 -> V_190 ) ;
V_147 -> V_155 = V_191 ;
V_37 = F_93 ( V_147 ) ;
if ( ! V_37 ) {
V_186 = F_94 ( & V_147 -> V_153 ,
& V_189 ) ;
memcpy ( V_184 , V_186 , sizeof( * V_186 ) ) ;
F_5 ( V_11 , L_42 ,
V_184 -> V_190 , V_184 -> V_192 ) ;
}
F_91 ( V_147 ) ;
return V_37 ;
}
static int F_100 ( const struct V_104 * V_105 , struct V_143 * exp ,
T_4 V_193 , void * V_194 , T_4 V_195 ,
void * V_196 , struct V_197 * V_198 )
{
int V_37 = - V_6 ;
if ( F_101 ( V_199 ) ) {
struct V_72 * V_73 = F_89 ( exp ) ;
int V_200 ;
if ( V_195 != sizeof( int ) )
return - V_6 ;
V_200 = * ( int * ) V_196 ;
F_5 ( V_11 , L_43 ,
V_73 -> V_201 -> V_49 , V_200 ,
V_73 -> V_202 , V_73 -> V_203 ,
V_73 -> V_204 , V_73 -> V_201 -> V_205 ,
F_102 ( V_73 -> V_206 ) ) ;
if ( ( V_73 -> V_206 != V_207 &&
V_73 -> V_206 != V_208 ) || V_200 > 1 )
F_103 ( V_73 ) ;
return 0 ;
}
if ( F_101 ( V_209 ) ) {
struct V_144 * V_145 ;
V_145 = V_196 ;
V_37 = F_87 ( exp , V_145 ) ;
return V_37 ;
}
if ( F_101 ( V_210 ) ) {
struct V_211 * V_77 = & exp -> V_82 -> V_76 . V_77 ;
struct V_212 V_213 ;
if ( V_195 == 0 ) {
if ( V_77 -> V_214 . V_215 != V_216 )
return 0 ;
V_196 = L_44 ;
V_195 = 4 ;
}
V_37 = F_104 ( V_196 , & V_213 ) ;
if ( V_37 ) {
F_2 ( L_45 ,
( char * ) V_196 ) ;
return V_37 ;
}
if ( V_77 -> V_214 . V_215 == V_216 ) {
V_77 -> V_214 = V_213 ;
} else if ( memcmp ( & V_77 -> V_214 , & V_213 ,
sizeof( V_213 ) ) != 0 ) {
char V_217 [ 20 ] ;
F_105 ( & V_77 -> V_214 ,
V_217 , sizeof( V_217 ) ) ;
F_106 ( L_46 ,
( char * ) V_196 , V_217 ) ;
V_37 = - V_218 ;
}
return V_37 ;
}
return V_37 ;
}
static int F_107 ( const struct V_104 * V_105 , struct V_143 * exp ,
T_2 V_193 , void * V_194 , T_2 * V_195 , void * V_196 ,
struct V_157 * V_182 )
{
int V_37 = - V_6 ;
if ( F_101 ( V_219 ) ) {
struct V_72 * V_73 = F_89 ( exp ) ;
struct V_74 * V_71 = V_196 ;
if ( * V_195 == sizeof( * V_71 ) ) {
* V_71 = V_73 -> V_79 ;
V_37 = 0 ;
}
}
return V_37 ;
}
static int F_108 ( struct V_33 * V_34 ,
struct V_72 * V_73 ,
enum V_220 V_221 )
{
F_12 ( V_73 -> V_201 == V_34 ) ;
F_5 ( V_11 , L_47 , V_221 ) ;
switch ( V_221 ) {
case V_222 :
if ( F_45 ( & V_73 -> V_79 , V_80 ) )
F_109 () ;
break;
case V_223 :
break;
case V_224 : {
struct V_225 * V_226 = V_34 -> V_227 ;
F_110 ( V_226 , V_228 ) ;
break;
}
case V_229 :
F_5 ( V_18 , L_48 , V_34 -> V_49 ) ;
V_34 -> V_230 = 0 ;
F_98 ( V_34 ) ;
if ( F_45 ( & V_73 -> V_79 , V_80 ) )
F_111 () ;
break;
case V_231 :
break;
case V_232 :
case V_233 :
break;
default:
F_2 ( L_49 , V_221 ) ;
F_4 () ;
}
return 0 ;
}
static int F_112 ( struct V_33 * V_234 ,
struct V_15 * V_16 ,
T_1 V_235 ,
void * V_71 , int V_236 , bool V_237 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_238 * V_239 ;
struct V_119 * V_53 ;
struct V_240 V_241 ;
T_5 V_242 = 0 ;
char * V_243 ;
char * V_244 ;
int V_245 ;
int V_246 ;
int V_37 = 0 ;
int V_247 = 0 ;
F_12 ( V_27 -> V_30 ) ;
F_12 ( V_27 -> V_45 == V_27 -> V_30 ) ;
V_243 = F_24 ( V_248 , V_249 ) ;
if ( ! V_243 )
return - V_39 ;
V_246 = snprintf ( V_243 , V_248 , L_50 , V_27 -> V_30 ) ;
if ( V_246 >= V_248 ) {
F_19 ( V_243 ) ;
return - V_250 ;
}
++ V_246 ;
V_244 = V_243 + V_246 ;
V_245 = V_248 - V_246 ;
while ( V_236 > 0 ) {
int V_251 = sizeof( * V_239 ) ;
int V_252 ;
struct V_33 * V_34 ;
char * V_253 ;
char * V_254 ;
char * V_255 ;
char * V_256 ;
V_37 = - V_6 ;
if ( V_236 < sizeof( * V_239 ) )
break;
V_239 = ( F_113 ( V_239 ) ) ( V_71 + V_247 ) ;
if ( V_239 -> V_257 != 0 )
break;
if ( V_239 -> V_258 == 0 )
break;
if ( V_239 -> V_259 != sizeof( V_260 ) )
break;
V_251 += V_239 -> V_258 * V_239 -> V_259 ;
if ( V_236 < V_251 )
break;
if ( V_237 )
F_114 ( V_239 ) ;
if ( V_239 -> V_261 > V_248 ) {
F_2 ( L_51 , V_239 -> V_261 ) ;
break;
}
if ( V_239 -> V_261 < V_251 )
break;
V_247 += V_239 -> V_261 ;
V_236 -= V_239 -> V_261 ;
if ( V_236 < 0 )
break;
if ( V_239 -> V_262 > V_235 ) {
F_2 ( L_52 ,
V_239 -> V_262 , V_235 ) ;
break;
}
if ( V_242 >= V_239 -> V_262 ) {
F_2 ( L_53 ,
V_242 , V_239 -> V_262 ) ;
break;
}
V_242 = V_239 -> V_262 ;
V_252 = V_239 -> V_263 == V_264 ;
memset ( V_244 , 0 , V_245 ) ;
V_253 = V_244 ;
V_246 = 0 ;
strcpy ( V_253 , V_16 -> V_19 ) ;
V_254 = strrchr ( V_253 , '-' ) ;
if ( ! V_254 ) {
F_2 ( L_54 ,
V_234 -> V_49 , V_253 ) ;
break;
}
V_246 = V_254 - V_253 ;
V_253 [ V_246 ] = 0 ;
V_246 += sprintf ( V_253 + V_246 , L_55 ,
V_252 ? L_56 : L_57 , V_239 -> V_265 ) ;
V_254 = V_252 ? L_58 : L_59 ;
V_246 += sprintf ( V_253 + V_246 , L_60 , V_254 , V_243 ) ;
F_115 ( & V_241 , V_253 ) ;
V_34 = F_116 ( V_253 ) ;
if ( ! V_34 ) {
F_5 ( V_18 , L_61 ,
V_234 -> V_49 , V_253 ) ;
V_37 = 0 ;
continue;
}
++ V_246 ;
V_255 = V_244 + V_246 ;
V_246 += sprintf ( V_255 , L_62 , V_254 , L_63 ) ;
V_256 = V_244 + V_246 ;
F_117 ( & V_34 -> V_76 . V_77 . V_81 ) ;
if ( ! V_34 -> V_76 . V_77 . V_78 ) {
F_46 ( & V_34 -> V_76 . V_77 . V_81 ) ;
V_37 = 0 ;
continue;
}
V_37 = F_118 ( V_34 -> V_76 . V_77 . V_78 ,
V_239 -> V_76 . V_266 [ 0 ] ,
(struct V_267 * ) V_256 ) ;
F_46 ( & V_34 -> V_76 . V_77 . V_81 ) ;
if ( V_37 < 0 ) {
F_2 ( L_64 ,
F_119 ( V_239 -> V_76 . V_266 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_65 ,
V_256 , F_119 ( V_239 -> V_76 . V_266 [ 0 ] ) ) ;
V_246 += strlen ( V_256 ) ;
V_246 += sprintf ( V_244 + V_246 , L_66 , V_239 -> V_268 ) ;
F_12 ( V_246 < V_245 ) ;
F_120 ( & V_241 , 1 , V_255 ) ;
V_37 = - V_39 ;
V_53 = F_121 ( V_269 , & V_241 ) ;
if ( F_36 ( V_53 ) ) {
F_2 ( L_67 ) ;
break;
}
F_5 ( V_18 , L_68 ,
V_242 , V_235 , V_253 , V_255 ) ;
V_37 = F_122 ( V_53 ) ;
F_123 ( V_53 ) ;
if ( V_37 )
F_5 ( V_18 , L_69 ,
V_253 , V_37 ) ;
}
F_19 ( V_243 ) ;
return V_37 ;
}
static int F_124 ( struct V_33 * V_34 ,
struct V_15 * V_16 )
{
struct V_146 * V_147 = NULL ;
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_270 * V_271 ;
struct V_272 * V_273 ;
struct V_274 * V_132 ;
struct V_275 * * V_276 ;
int V_277 ;
bool V_278 = true ;
bool V_237 ;
int V_279 ;
int V_280 ;
int V_37 ;
V_277 = V_281 ;
if ( V_27 -> V_43 == 0 )
V_277 = V_282 ;
V_276 = F_125 ( V_277 , sizeof( * V_276 ) , V_249 ) ;
if ( ! V_276 ) {
V_37 = - V_39 ;
goto V_283;
}
for ( V_279 = 0 ; V_279 < V_277 ; V_279 ++ ) {
V_276 [ V_279 ] = F_126 ( V_249 ) ;
if ( ! V_276 [ V_279 ] ) {
V_37 = - V_39 ;
goto V_283;
}
}
V_284:
F_12 ( F_127 ( V_16 ) ) ;
F_12 ( F_128 ( & V_16 -> V_42 ) ) ;
V_147 = F_129 ( F_89 ( V_16 -> V_25 ) ,
& V_285 ) ;
if ( ! V_147 ) {
V_37 = - V_39 ;
goto V_283;
}
V_37 = F_130 ( V_147 , V_151 , V_286 ) ;
if ( V_37 )
goto V_283;
V_271 = F_90 ( & V_147 -> V_153 , & V_287 ) ;
F_12 ( sizeof( V_271 -> V_288 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_131 ( V_271 -> V_288 , V_16 -> V_19 , sizeof( V_271 -> V_288 ) )
>= sizeof( V_271 -> V_288 ) ) {
V_37 = - V_250 ;
goto V_283;
}
V_271 -> V_289 = V_27 -> V_43 + 1 ;
V_271 -> V_290 = V_16 -> V_46 ;
V_271 -> V_291 = V_292 ;
V_271 -> V_293 = V_277 ;
V_132 = F_132 ( V_147 , V_277 , 1 , V_294 ,
V_295 ) ;
if ( ! V_132 ) {
V_37 = - V_39 ;
goto V_283;
}
for ( V_279 = 0 ; V_279 < V_277 ; V_279 ++ )
F_133 ( V_132 , V_276 [ V_279 ] , 0 , V_248 ) ;
F_92 ( V_147 ) ;
V_37 = F_93 ( V_147 ) ;
if ( V_37 )
goto V_283;
V_273 = F_94 ( & V_147 -> V_153 , & V_296 ) ;
if ( V_273 -> V_297 < V_273 -> V_298 ) {
V_37 = - V_6 ;
goto V_283;
}
V_27 -> V_43 = V_273 -> V_298 ;
V_278 = V_273 -> V_298 == V_273 -> V_297 ;
F_5 ( V_18 , L_70 ,
V_273 -> V_298 , V_278 == false ) ;
V_280 = F_134 ( V_147 , V_147 -> V_299 , 0 ) ;
if ( V_280 < 0 ) {
V_37 = V_280 ;
goto V_283;
}
if ( V_280 > V_277 << V_292 ) {
V_37 = - V_6 ;
goto V_283;
}
if ( V_280 == 0 ) {
if ( ! V_278 )
V_37 = - V_6 ;
goto V_283;
}
V_237 = ! ! F_135 ( V_147 ) ;
#if V_300 < F_136 ( 3 , 2 , 50 , 0 )
if ( F_40 ( V_147 -> V_301 -> V_302 ) )
V_237 = ! V_237 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_279 = 0 ; V_279 < V_277 && V_280 > 0 ; V_279 ++ ) {
int V_303 ;
void * V_60 ;
V_60 = F_137 ( V_276 [ V_279 ] ) ;
V_303 = F_112 ( V_34 , V_16 , V_273 -> V_298 , V_60 ,
F_138 ( int , V_280 , V_248 ) ,
V_237 ) ;
F_139 ( V_276 [ V_279 ] ) ;
if ( V_303 < 0 ) {
F_140 ( L_71 ,
V_16 -> V_19 , V_303 ) ;
break;
}
V_280 -= V_248 ;
}
V_283:
if ( V_147 )
F_91 ( V_147 ) ;
if ( V_37 == 0 && ! V_278 )
goto V_284;
if ( V_276 ) {
for ( V_279 = 0 ; V_279 < V_277 ; V_279 ++ ) {
if ( ! V_276 [ V_279 ] )
break;
F_141 ( V_276 [ V_279 ] ) ;
}
F_19 ( V_276 ) ;
}
return V_37 ;
}
static int F_142 ( struct V_33 * V_234 ,
struct V_15 * V_16 , int V_304 )
{
struct V_106 * V_107 ;
struct V_55 * V_56 = NULL ;
int V_37 = 0 ;
bool V_305 = false ;
struct V_104 * V_105 ;
F_12 ( V_16 ) ;
F_12 ( F_128 ( & V_16 -> V_42 ) ) ;
if ( F_16 ( V_16 ) && V_304 )
return 0 ;
if ( V_16 -> V_31 . V_45 )
V_56 = F_35 ( V_16 -> V_31 . V_45 ) ;
V_105 = F_24 ( sizeof( * V_105 ) , V_249 ) ;
if ( ! V_105 )
return - V_39 ;
V_37 = F_143 ( V_105 , V_306 ) ;
if ( V_37 )
goto V_307;
V_107 = F_59 ( V_234 , V_109 ) ;
F_12 ( V_107 ) ;
if ( V_304 ) {
V_37 = - V_308 ;
goto V_309;
}
if ( F_16 ( V_16 ) ) {
F_144 ( V_16 -> V_19 ) ;
V_305 = true ;
}
V_37 = F_145 ( V_105 , V_107 , V_16 -> V_19 ,
& V_16 -> V_31 ) ;
V_309:
F_146 ( V_105 , V_107 ) ;
if ( V_305 ) {
F_12 ( F_16 ( V_16 ) ) ;
F_147 ( V_16 -> V_19 ) ;
F_148 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_11 ) ) ;
}
F_149 ( V_105 ) ;
V_307:
F_19 ( V_105 ) ;
return V_37 ;
}
int F_31 ( struct V_33 * V_234 , struct V_15 * V_16 )
{
struct V_134 V_135 = { 0 } ;
T_1 V_161 = V_310 ;
int V_37 = 0 , V_311 ;
F_12 ( V_16 ) ;
F_39 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_32 ) {
F_41 ( & V_16 -> V_42 ) ;
return 0 ;
}
F_150 ( V_312 , 20 ) ;
F_5 ( V_11 , L_72 , V_16 -> V_19 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_43 + 1 ) ;
V_311 = F_95 ( V_234 -> V_76 . V_77 . V_313 , NULL , V_314 , NULL ,
V_315 , & V_161 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_135 ) ;
if ( V_311 == 0 ) {
F_8 ( V_16 ) ;
V_37 = F_151 ( & V_135 , ( void * ) V_16 ) ;
F_12 ( V_37 == 0 ) ;
} else {
F_5 ( V_11 , L_73 , V_311 ) ;
V_16 -> V_102 = 1 ;
F_8 ( V_16 ) ;
}
if ( F_127 ( V_16 ) ) {
V_37 = 0 ;
if ( V_311 == 0 )
V_37 = F_124 ( V_234 , V_16 ) ;
} else {
V_37 = F_142 ( V_234 , V_16 , V_311 != 0 ) ;
}
F_5 ( V_11 , L_74 ,
V_234 -> V_49 , V_16 -> V_19 , V_37 ? L_75 : L_76 , V_37 ) ;
F_41 ( & V_16 -> V_42 ) ;
if ( ! V_311 )
F_152 ( & V_135 , V_315 ) ;
return V_37 ;
}
static int F_153 ( struct V_33 * V_34 , T_4 V_2 , void * V_244 )
{
struct V_119 * V_53 = V_244 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_37 = 0 ;
switch ( V_53 -> V_316 ) {
case V_317 : {
struct V_183 * V_184 ;
if ( F_154 ( V_53 , 1 ) !=
sizeof( struct V_183 ) ) {
V_37 = - V_6 ;
goto V_283;
}
V_184 = (struct V_183 * ) F_155 ( V_53 , 1 ) ;
F_5 ( V_11 , L_77 ,
V_184 -> V_190 , V_184 -> V_318 ) ;
V_37 = F_99 ( V_34 -> V_76 . V_77 . V_313 , V_184 ) ;
break;
}
case V_319 :
F_2 ( L_78 ) ;
V_37 = - V_320 ;
break;
case V_321 : {
V_37 = F_156 ( V_53 ) ;
break;
}
case V_322 : {
struct V_15 * V_16 ;
struct V_35 * V_36 ;
V_13 = F_157 ( V_53 , 1 ) ;
V_27 = (struct V_26 * ) F_155 ( V_53 , 2 ) ;
V_36 = * (struct V_35 * * ) F_155 ( V_53 , 3 ) ;
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
V_16 -> V_31 . V_44 |= V_323 ;
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 == 0 && V_16 -> V_22 ) {
if ( F_45 ( & V_34 -> V_76 . V_77 . V_78 ->
V_79 , V_80 ) ) {
V_37 = F_31 ( V_34 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_324 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_11 ( V_324 ) ;
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
case V_325 : {
V_13 = F_157 ( V_53 , 1 ) ;
if ( V_53 -> V_326 >= 2 )
V_27 = (struct V_26 * ) F_155 (
V_53 , 2 ) ;
V_37 = F_38 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_83 , V_53 -> V_316 ) ;
V_37 = - V_6 ;
goto V_283;
}
}
V_283:
return V_37 ;
}
static int T_6 F_158 ( void )
{
return F_159 ( & V_327 , NULL ,
V_328 , NULL ) ;
}
static void F_160 ( void )
{
F_161 ( V_328 ) ;
}
