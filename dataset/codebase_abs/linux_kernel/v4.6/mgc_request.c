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
F_5 ( V_11 , L_23 , V_16 -> V_19 ) ;
F_31 ( V_16 -> V_25 -> V_82 , V_16 ) ;
} else {
F_5 ( V_11 , L_24 ,
V_16 -> V_19 ) ;
}
F_46 ( & V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_81 ) ;
}
static int F_49 ( void * V_71 )
{
bool V_84 = true ;
F_5 ( V_11 , L_25 ) ;
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
F_5 ( V_11 , L_26 ) ;
return 0 ;
}
static void F_55 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_27 ,
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
F_2 ( L_28 ) ;
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
F_74 () ;
V_37 = F_75 ( V_34 , V_53 ) ;
if ( V_37 )
goto V_123;
V_37 = F_57 ( NULL , V_34 ) ;
if ( V_37 ) {
F_2 ( L_29 ) ;
goto V_124;
}
F_76 ( & V_120 ) ;
F_77 ( V_34 , V_120 . V_125 , V_120 . V_126 ) ;
F_78 ( V_34 ) ;
if ( F_79 ( & V_115 ) == 1 ) {
V_85 = 0 ;
F_80 ( & V_99 ) ;
V_122 = F_81 ( F_49 , NULL , L_30 ) ;
if ( F_36 ( V_122 ) ) {
V_37 = F_37 ( V_122 ) ;
F_2 ( L_31 ,
V_34 -> V_49 , V_37 ) ;
goto V_124;
}
V_37 = 0 ;
F_66 ( & V_96 ) ;
}
return V_37 ;
V_124:
F_72 ( V_34 ) ;
V_123:
F_71 () ;
return V_37 ;
}
static int F_82 ( struct V_127 * V_128 , struct V_129 * V_130 ,
void * V_71 , int V_131 )
{
struct V_132 V_133 ;
struct V_15 * V_16 = V_71 ;
int V_37 = 0 ;
switch ( V_131 ) {
case V_134 :
F_83 ( V_128 , L_32 ) ;
F_84 ( V_128 , & V_133 ) ;
V_37 = F_85 ( & V_133 , V_135 ) ;
break;
case V_136 :
F_83 ( V_128 , L_33 ) ;
F_5 ( V_11 , L_34 V_137 L_35 ,
F_86 ( V_128 -> V_138 ) ,
( char * ) & V_128 -> V_138 -> V_139 . V_1 [ 0 ] ) ;
if ( ! V_16 ) {
F_5 ( V_18 , L_36 ) ;
break;
}
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_16 -> V_32 ) {
F_5 ( V_11 , L_37 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
if ( ! V_128 -> V_140 ||
! V_128 -> V_140 -> V_82 -> V_76 . V_77 . V_83 ) {
F_5 ( V_11 , L_38 ,
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
static int F_87 ( struct V_141 * exp ,
struct V_142 * V_143 )
{
struct V_144 * V_145 ;
struct V_142 * V_146 , * V_147 ;
int V_37 ;
V_145 = F_88 ( F_89 ( exp ) ,
& V_148 , V_149 ,
V_150 ) ;
if ( ! V_145 )
return - V_39 ;
V_146 = F_90 ( & V_145 -> V_151 , & V_152 ) ;
if ( ! V_146 ) {
F_91 ( V_145 ) ;
return - V_39 ;
}
memcpy ( V_146 , V_143 , sizeof( * V_146 ) ) ;
F_92 ( V_145 ) ;
V_145 -> V_153 = V_154 ;
V_37 = F_93 ( V_145 ) ;
if ( ! V_37 ) {
V_147 = F_94 ( & V_145 -> V_151 , & V_152 ) ;
memcpy ( V_143 , V_147 , sizeof( * V_147 ) ) ;
}
F_91 ( V_145 ) ;
return V_37 ;
}
static int F_95 ( struct V_141 * exp , struct V_155 * V_156 ,
T_2 type , T_3 * V_157 , T_2 V_158 ,
T_1 * V_159 , void * V_160 , void * V_161 , void * V_162 ,
void * V_71 , T_2 V_163 , void * V_164 ,
struct V_132 * V_133 )
{
struct V_15 * V_16 = V_71 ;
struct V_165 V_166 = {
. V_167 = type ,
. V_168 = V_158 ,
. V_169 = F_82 ,
. V_170 = V_171 ,
} ;
struct V_144 * V_145 ;
int V_172 = F_16 ( V_16 ) ;
int V_37 ;
F_5 ( V_11 , L_39 , V_16 -> V_19 ,
V_16 -> V_50 . V_1 [ 0 ] ) ;
V_145 = F_88 ( F_89 ( exp ) ,
& V_173 , V_174 ,
V_175 ) ;
if ( ! V_145 )
return - V_39 ;
F_96 ( & V_145 -> V_151 , & V_176 , V_177 , 0 ) ;
F_92 ( V_145 ) ;
V_145 -> V_153 = V_172 ? 5 : V_178 ;
V_37 = F_97 ( exp , & V_145 , & V_166 , & V_16 -> V_50 , NULL , V_159 ,
NULL , 0 , V_179 , V_133 , 0 ) ;
F_91 ( V_145 ) ;
return V_37 ;
}
static void F_98 ( struct V_33 * V_180 )
{
F_21 ( & V_20 ) ;
V_85 |= V_94 ;
F_15 ( & V_20 ) ;
F_56 ( & V_99 ) ;
}
static int F_99 ( struct V_141 * exp ,
struct V_181 * V_182 )
{
struct V_144 * V_145 ;
struct V_181 * V_183 , * V_184 ;
int V_37 ;
V_145 = F_88 ( F_89 ( exp ) ,
& V_185 , V_149 ,
V_186 ) ;
if ( ! V_145 )
return - V_39 ;
V_183 = F_90 ( & V_145 -> V_151 , & V_187 ) ;
if ( ! V_183 ) {
F_91 ( V_145 ) ;
return - V_39 ;
}
memcpy ( V_183 , V_182 , sizeof( * V_183 ) ) ;
F_92 ( V_145 ) ;
F_5 ( V_11 , L_40 , V_182 -> V_188 ) ;
V_145 -> V_153 = V_189 ;
V_37 = F_93 ( V_145 ) ;
if ( ! V_37 ) {
V_184 = F_94 ( & V_145 -> V_151 ,
& V_187 ) ;
memcpy ( V_182 , V_184 , sizeof( * V_184 ) ) ;
F_5 ( V_11 , L_41 ,
V_182 -> V_188 , V_182 -> V_190 ) ;
}
F_91 ( V_145 ) ;
return V_37 ;
}
static int F_100 ( const struct V_103 * V_104 , struct V_141 * exp ,
T_4 V_191 , void * V_192 , T_4 V_193 ,
void * V_194 , struct V_195 * V_196 )
{
int V_37 = - V_6 ;
if ( F_101 ( V_197 ) ) {
struct V_72 * V_73 = F_89 ( exp ) ;
int V_198 ;
if ( V_193 != sizeof( int ) )
return - V_6 ;
V_198 = * ( int * ) V_194 ;
F_5 ( V_11 , L_42 ,
V_73 -> V_199 -> V_49 , V_198 ,
V_73 -> V_200 , V_73 -> V_201 ,
V_73 -> V_202 , V_73 -> V_199 -> V_203 ,
F_102 ( V_73 -> V_204 ) ) ;
if ( ( V_73 -> V_204 != V_205 &&
V_73 -> V_204 != V_206 ) || V_198 > 1 )
F_103 ( V_73 ) ;
return 0 ;
}
if ( F_101 ( V_207 ) ) {
struct V_142 * V_143 ;
V_143 = V_194 ;
V_37 = F_87 ( exp , V_143 ) ;
return V_37 ;
}
if ( F_101 ( V_208 ) ) {
struct V_209 * V_77 = & exp -> V_82 -> V_76 . V_77 ;
struct V_210 V_211 ;
if ( V_193 == 0 ) {
if ( V_77 -> V_212 . V_213 != V_214 )
return 0 ;
V_194 = L_43 ;
V_193 = 4 ;
}
V_37 = F_104 ( V_194 , & V_211 ) ;
if ( V_37 ) {
F_2 ( L_44 ,
( char * ) V_194 ) ;
return V_37 ;
}
if ( V_77 -> V_212 . V_213 == V_214 ) {
V_77 -> V_212 = V_211 ;
} else if ( memcmp ( & V_77 -> V_212 , & V_211 ,
sizeof( V_211 ) ) != 0 ) {
char V_215 [ 20 ] ;
F_105 ( & V_77 -> V_212 ,
V_215 , sizeof( V_215 ) ) ;
F_106 ( L_45 ,
( char * ) V_194 , V_215 ) ;
V_37 = - V_216 ;
}
return V_37 ;
}
return V_37 ;
}
static int F_107 ( const struct V_103 * V_104 , struct V_141 * exp ,
T_2 V_191 , void * V_192 , T_2 * V_193 , void * V_194 ,
struct V_155 * V_180 )
{
int V_37 = - V_6 ;
if ( F_101 ( V_217 ) ) {
struct V_72 * V_73 = F_89 ( exp ) ;
struct V_74 * V_71 = V_194 ;
if ( * V_193 == sizeof( * V_71 ) ) {
* V_71 = V_73 -> V_79 ;
V_37 = 0 ;
}
}
return V_37 ;
}
static int F_108 ( struct V_33 * V_34 ,
struct V_72 * V_73 ,
enum V_218 V_219 )
{
F_12 ( V_73 -> V_199 == V_34 ) ;
F_5 ( V_11 , L_46 , V_219 ) ;
switch ( V_219 ) {
case V_220 :
if ( F_45 ( & V_73 -> V_79 , V_80 ) )
F_109 () ;
break;
case V_221 :
break;
case V_222 : {
struct V_223 * V_224 = V_34 -> V_225 ;
F_110 ( V_224 , V_226 ) ;
break;
}
case V_227 :
F_5 ( V_18 , L_47 , V_34 -> V_49 ) ;
V_34 -> V_228 = 0 ;
F_98 ( V_34 ) ;
if ( F_45 ( & V_73 -> V_79 , V_80 ) )
F_111 () ;
break;
case V_229 :
break;
case V_230 :
case V_231 :
break;
default:
F_2 ( L_48 , V_219 ) ;
F_4 () ;
}
return 0 ;
}
static int F_112 ( struct V_33 * V_232 ,
struct V_15 * V_16 ,
T_1 V_233 ,
void * V_71 , int V_234 , bool V_235 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_236 * V_237 ;
struct V_118 * V_53 ;
struct V_238 V_239 ;
T_5 V_240 = 0 ;
char * V_241 ;
char * V_242 ;
int V_243 ;
int V_244 ;
int V_37 = 0 ;
int V_245 = 0 ;
F_12 ( V_27 -> V_30 ) ;
F_12 ( V_27 -> V_45 == V_27 -> V_30 ) ;
V_241 = F_24 ( V_246 , V_247 ) ;
if ( ! V_241 )
return - V_39 ;
V_244 = snprintf ( V_241 , V_246 , L_49 , V_27 -> V_30 ) ;
if ( V_244 >= V_246 ) {
F_19 ( V_241 ) ;
return - V_248 ;
}
++ V_244 ;
V_242 = V_241 + V_244 ;
V_243 = V_246 - V_244 ;
while ( V_234 > 0 ) {
int V_249 = sizeof( * V_237 ) ;
int V_250 ;
struct V_33 * V_34 ;
char * V_251 ;
char * V_252 ;
char * V_253 ;
char * V_254 ;
V_37 = - V_6 ;
if ( V_234 < sizeof( * V_237 ) )
break;
V_237 = ( F_113 ( V_237 ) ) ( V_71 + V_245 ) ;
if ( V_237 -> V_255 != 0 )
break;
if ( V_237 -> V_256 == 0 )
break;
if ( V_237 -> V_257 != sizeof( V_258 ) )
break;
V_249 += V_237 -> V_256 * V_237 -> V_257 ;
if ( V_234 < V_249 )
break;
if ( V_235 )
F_114 ( V_237 ) ;
if ( V_237 -> V_259 > V_246 ) {
F_2 ( L_50 , V_237 -> V_259 ) ;
break;
}
if ( V_237 -> V_259 < V_249 )
break;
V_245 += V_237 -> V_259 ;
V_234 -= V_237 -> V_259 ;
if ( V_234 < 0 )
break;
if ( V_237 -> V_260 > V_233 ) {
F_2 ( L_51 ,
V_237 -> V_260 , V_233 ) ;
break;
}
if ( V_240 >= V_237 -> V_260 ) {
F_2 ( L_52 ,
V_240 , V_237 -> V_260 ) ;
break;
}
V_240 = V_237 -> V_260 ;
V_250 = V_237 -> V_261 == V_262 ;
memset ( V_242 , 0 , V_243 ) ;
V_251 = V_242 ;
V_244 = 0 ;
strcpy ( V_251 , V_16 -> V_19 ) ;
V_252 = strrchr ( V_251 , '-' ) ;
if ( ! V_252 ) {
F_2 ( L_53 ,
V_232 -> V_49 , V_251 ) ;
break;
}
V_244 = V_252 - V_251 ;
V_251 [ V_244 ] = 0 ;
V_244 += sprintf ( V_251 + V_244 , L_54 ,
V_250 ? L_55 : L_56 , V_237 -> V_263 ) ;
V_252 = V_250 ? L_57 : L_58 ;
V_244 += sprintf ( V_251 + V_244 , L_59 , V_252 , V_241 ) ;
F_115 ( & V_239 , V_251 ) ;
V_34 = F_116 ( V_251 ) ;
if ( ! V_34 ) {
F_5 ( V_18 , L_60 ,
V_232 -> V_49 , V_251 ) ;
V_37 = 0 ;
continue;
}
++ V_244 ;
V_253 = V_242 + V_244 ;
V_244 += sprintf ( V_253 , L_61 , V_252 , L_62 ) ;
V_254 = V_242 + V_244 ;
F_48 ( & V_34 -> V_76 . V_77 . V_81 ) ;
if ( ! V_34 -> V_76 . V_77 . V_78 ) {
F_46 ( & V_34 -> V_76 . V_77 . V_81 ) ;
V_37 = 0 ;
continue;
}
V_37 = F_117 ( V_34 -> V_76 . V_77 . V_78 ,
V_237 -> V_76 . V_264 [ 0 ] ,
(struct V_265 * ) V_254 ) ;
F_46 ( & V_34 -> V_76 . V_77 . V_81 ) ;
if ( V_37 < 0 ) {
F_2 ( L_63 ,
F_118 ( V_237 -> V_76 . V_264 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_64 ,
V_254 , F_118 ( V_237 -> V_76 . V_264 [ 0 ] ) ) ;
V_244 += strlen ( V_254 ) ;
V_244 += sprintf ( V_242 + V_244 , L_65 , V_237 -> V_266 ) ;
F_12 ( V_244 < V_243 ) ;
F_119 ( & V_239 , 1 , V_253 ) ;
V_37 = - V_39 ;
V_53 = F_120 ( V_267 , & V_239 ) ;
if ( F_36 ( V_53 ) ) {
F_2 ( L_66 ) ;
break;
}
F_5 ( V_18 , L_67 ,
V_240 , V_233 , V_251 , V_253 ) ;
V_37 = F_121 ( V_53 ) ;
F_122 ( V_53 ) ;
if ( V_37 )
F_5 ( V_18 , L_68 ,
V_251 , V_37 ) ;
}
F_19 ( V_241 ) ;
return V_37 ;
}
static int F_123 ( struct V_33 * V_34 ,
struct V_15 * V_16 )
{
struct V_144 * V_145 = NULL ;
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_268 * V_269 ;
struct V_270 * V_271 ;
struct V_272 * V_130 ;
struct V_273 * * V_274 ;
int V_275 ;
bool V_276 = true ;
bool V_235 ;
int V_277 ;
int V_278 ;
int V_37 ;
V_275 = V_279 ;
if ( V_27 -> V_43 == 0 )
V_275 = V_280 ;
V_274 = F_124 ( V_275 , sizeof( * V_274 ) , V_247 ) ;
if ( ! V_274 ) {
V_37 = - V_39 ;
goto V_281;
}
for ( V_277 = 0 ; V_277 < V_275 ; V_277 ++ ) {
V_274 [ V_277 ] = F_125 ( V_247 ) ;
if ( ! V_274 [ V_277 ] ) {
V_37 = - V_39 ;
goto V_281;
}
}
V_282:
F_12 ( F_126 ( V_16 ) ) ;
F_12 ( F_127 ( & V_16 -> V_42 ) ) ;
V_145 = F_128 ( F_89 ( V_16 -> V_25 ) ,
& V_283 ) ;
if ( ! V_145 ) {
V_37 = - V_39 ;
goto V_281;
}
V_37 = F_129 ( V_145 , V_149 , V_284 ) ;
if ( V_37 )
goto V_281;
V_269 = F_90 ( & V_145 -> V_151 , & V_285 ) ;
F_12 ( sizeof( V_269 -> V_286 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_130 ( V_269 -> V_286 , V_16 -> V_19 , sizeof( V_269 -> V_286 ) )
>= sizeof( V_269 -> V_286 ) ) {
V_37 = - V_248 ;
goto V_281;
}
V_269 -> V_287 = V_27 -> V_43 + 1 ;
V_269 -> V_288 = V_16 -> V_46 ;
V_269 -> V_289 = V_290 ;
V_269 -> V_291 = V_275 ;
V_130 = F_131 ( V_145 , V_275 , 1 , V_292 ,
V_293 ) ;
if ( ! V_130 ) {
V_37 = - V_39 ;
goto V_281;
}
for ( V_277 = 0 ; V_277 < V_275 ; V_277 ++ )
F_132 ( V_130 , V_274 [ V_277 ] , 0 , V_246 ) ;
F_92 ( V_145 ) ;
V_37 = F_93 ( V_145 ) ;
if ( V_37 )
goto V_281;
V_271 = F_94 ( & V_145 -> V_151 , & V_294 ) ;
if ( V_271 -> V_295 < V_271 -> V_296 ) {
V_37 = - V_6 ;
goto V_281;
}
V_27 -> V_43 = V_271 -> V_296 ;
V_276 = V_271 -> V_296 == V_271 -> V_295 ;
F_5 ( V_18 , L_69 ,
V_271 -> V_296 , V_276 == false ) ;
V_278 = F_133 ( V_145 , V_145 -> V_297 , 0 ) ;
if ( V_278 < 0 ) {
V_37 = V_278 ;
goto V_281;
}
if ( V_278 > V_275 << V_290 ) {
V_37 = - V_6 ;
goto V_281;
}
if ( V_278 == 0 ) {
if ( ! V_276 )
V_37 = - V_6 ;
goto V_281;
}
V_235 = ! ! F_134 ( V_145 ) ;
#if V_298 < F_135 ( 3 , 2 , 50 , 0 )
if ( F_40 ( V_145 -> V_299 -> V_300 ) )
V_235 = ! V_235 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_277 = 0 ; V_277 < V_275 && V_278 > 0 ; V_277 ++ ) {
int V_301 ;
void * V_60 ;
V_60 = F_136 ( V_274 [ V_277 ] ) ;
V_301 = F_112 ( V_34 , V_16 , V_271 -> V_296 , V_60 ,
F_137 ( int , V_278 , V_246 ) ,
V_235 ) ;
F_138 ( V_274 [ V_277 ] ) ;
if ( V_301 < 0 ) {
F_139 ( L_70 ,
V_16 -> V_19 , V_301 ) ;
break;
}
V_278 -= V_246 ;
}
V_281:
if ( V_145 )
F_91 ( V_145 ) ;
if ( V_37 == 0 && ! V_276 )
goto V_282;
if ( V_274 ) {
for ( V_277 = 0 ; V_277 < V_275 ; V_277 ++ ) {
if ( ! V_274 [ V_277 ] )
break;
F_140 ( V_274 [ V_277 ] ) ;
}
F_19 ( V_274 ) ;
}
return V_37 ;
}
static int F_141 ( struct V_33 * V_232 ,
struct V_15 * V_16 , int V_302 )
{
struct V_105 * V_106 ;
struct V_55 * V_56 = NULL ;
int V_37 = 0 ;
bool V_303 = false ;
struct V_103 * V_104 ;
F_12 ( V_16 ) ;
F_12 ( F_127 ( & V_16 -> V_42 ) ) ;
if ( F_16 ( V_16 ) && V_302 )
return 0 ;
if ( V_16 -> V_31 . V_45 )
V_56 = F_35 ( V_16 -> V_31 . V_45 ) ;
V_104 = F_24 ( sizeof( * V_104 ) , V_247 ) ;
if ( ! V_104 )
return - V_39 ;
V_37 = F_142 ( V_104 , V_304 ) ;
if ( V_37 )
goto V_305;
V_106 = F_59 ( V_232 , V_108 ) ;
F_12 ( V_106 ) ;
if ( V_302 ) {
V_37 = - V_306 ;
goto V_307;
}
if ( F_16 ( V_16 ) ) {
F_143 ( V_16 -> V_19 ) ;
V_303 = true ;
}
V_37 = F_144 ( V_104 , V_106 , V_16 -> V_19 ,
& V_16 -> V_31 ) ;
V_307:
F_145 ( V_104 , V_106 ) ;
if ( V_303 ) {
F_12 ( F_16 ( V_16 ) ) ;
F_146 ( V_16 -> V_19 ) ;
F_147 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_11 ) ) ;
}
F_148 ( V_104 ) ;
V_305:
F_19 ( V_104 ) ;
return V_37 ;
}
int F_31 ( struct V_33 * V_232 , struct V_15 * V_16 )
{
struct V_132 V_133 = { 0 } ;
T_1 V_159 = V_308 ;
int V_37 = 0 , V_309 ;
F_12 ( V_16 ) ;
F_39 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_32 ) {
F_41 ( & V_16 -> V_42 ) ;
return 0 ;
}
F_149 ( V_310 , 20 ) ;
F_5 ( V_11 , L_71 , V_16 -> V_19 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_43 + 1 ) ;
V_309 = F_95 ( V_232 -> V_76 . V_77 . V_311 , NULL , V_312 , NULL ,
V_313 , & V_159 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_133 ) ;
if ( V_309 == 0 ) {
F_8 ( V_16 ) ;
V_37 = F_150 ( & V_133 , ( void * ) V_16 ) ;
F_12 ( V_37 == 0 ) ;
} else {
F_5 ( V_11 , L_72 , V_309 ) ;
V_16 -> V_101 = 1 ;
F_8 ( V_16 ) ;
}
if ( F_126 ( V_16 ) ) {
V_37 = 0 ;
if ( V_309 == 0 )
V_37 = F_123 ( V_232 , V_16 ) ;
} else {
V_37 = F_141 ( V_232 , V_16 , V_309 != 0 ) ;
}
F_5 ( V_11 , L_73 ,
V_232 -> V_49 , V_16 -> V_19 , V_37 ? L_74 : L_75 , V_37 ) ;
F_41 ( & V_16 -> V_42 ) ;
if ( ! V_309 )
F_151 ( & V_133 , V_313 ) ;
return V_37 ;
}
static int F_152 ( struct V_33 * V_34 , T_4 V_2 , void * V_242 )
{
struct V_118 * V_53 = V_242 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_37 = 0 ;
switch ( V_53 -> V_314 ) {
case V_315 : {
struct V_181 * V_182 ;
if ( F_153 ( V_53 , 1 ) !=
sizeof( struct V_181 ) ) {
V_37 = - V_6 ;
goto V_281;
}
V_182 = (struct V_181 * ) F_154 ( V_53 , 1 ) ;
F_5 ( V_11 , L_76 ,
V_182 -> V_188 , V_182 -> V_316 ) ;
V_37 = F_99 ( V_34 -> V_76 . V_77 . V_311 , V_182 ) ;
break;
}
case V_317 :
F_2 ( L_77 ) ;
V_37 = - V_318 ;
break;
case V_319 : {
V_37 = F_155 ( V_53 ) ;
break;
}
case V_320 : {
struct V_15 * V_16 ;
struct V_35 * V_36 ;
V_13 = F_156 ( V_53 , 1 ) ;
V_27 = (struct V_26 * ) F_154 ( V_53 , 2 ) ;
V_36 = * (struct V_35 * * ) F_154 ( V_53 , 3 ) ;
F_5 ( V_11 , L_78 , V_13 ,
V_27 -> V_43 ) ;
V_37 = F_34 ( V_34 , V_13 , V_27 , V_36 ) ;
if ( V_37 )
break;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( ! V_16 ) {
V_37 = - V_52 ;
break;
}
V_16 -> V_31 . V_44 |= V_321 ;
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 == 0 && V_16 -> V_22 ) {
if ( F_45 ( & V_34 -> V_76 . V_77 . V_78 ->
V_79 , V_80 ) ) {
V_37 = F_31 ( V_34 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_322 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_11 ( V_322 ) ;
}
if ( V_37 )
F_2 ( L_79 , V_37 ) ;
}
if ( V_37 == 0 && V_16 -> V_24 ) {
V_37 = F_31 ( V_34 , V_16 -> V_24 ) ;
if ( V_37 == - V_52 ) {
F_5 ( V_11 ,
L_80 ) ;
V_37 = 0 ;
}
if ( V_37 )
F_2 (
L_81 ,
V_34 -> V_49 , V_37 ) ;
}
F_11 ( V_16 ) ;
break;
}
case V_323 : {
V_13 = F_156 ( V_53 , 1 ) ;
if ( V_53 -> V_324 >= 2 )
V_27 = (struct V_26 * ) F_154 (
V_53 , 2 ) ;
V_37 = F_38 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_82 , V_53 -> V_314 ) ;
V_37 = - V_6 ;
goto V_281;
}
}
V_281:
return V_37 ;
}
static int T_6 F_157 ( void )
{
return F_158 ( & V_325 , NULL ,
V_326 , NULL ) ;
}
static void F_159 ( void )
{
F_160 ( V_326 ) ;
}
