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
F_8 ( V_28 ) ;
break;
}
}
F_15 ( & V_20 ) ;
return V_28 ;
}
static
struct V_15 * F_23 ( struct V_32 * V_33 ,
char * V_13 ,
int type ,
struct V_26 * V_27 ,
struct V_34 * V_35 )
{
struct V_15 * V_16 ;
int V_36 ;
F_5 ( V_11 , L_6 , V_13 ,
V_27 ? V_27 -> V_30 : NULL ) ;
V_16 = F_24 ( sizeof( * V_16 ) + strlen ( V_13 ) + 1 , V_37 ) ;
if ( ! V_16 )
return F_25 ( - V_38 ) ;
V_36 = F_7 ( V_13 , & V_16 -> V_39 , type ) ;
if ( V_36 ) {
F_19 ( V_16 ) ;
return F_25 ( V_36 ) ;
}
strcpy ( V_16 -> V_19 , V_13 ) ;
if ( V_27 )
V_16 -> V_31 = * V_27 ;
else
V_16 -> V_31 . V_40 = V_41 ;
F_26 ( & V_16 -> V_42 ) ;
V_16 -> V_31 . V_43 = 0 ;
V_16 -> V_31 . V_44 = 0 ;
V_16 -> V_31 . V_45 = V_35 ;
V_16 -> V_46 = type ;
F_27 ( & V_16 -> V_17 , 1 ) ;
V_16 -> V_25 = F_28 ( V_33 -> V_47 ) ;
if ( F_16 ( V_16 ) ) {
F_29 ( V_13 ) ;
V_16 -> V_31 . V_48 = V_33 -> V_49 ;
}
F_21 ( & V_20 ) ;
F_30 ( & V_16 -> V_21 , & V_50 ) ;
F_15 ( & V_20 ) ;
if ( F_16 ( V_16 ) ) {
V_36 = F_31 ( V_33 , V_16 ) ;
if ( V_36 && V_36 != - V_51 )
F_2 ( L_7 , V_36 ) ;
}
return V_16 ;
}
static struct V_15 *
F_32 ( struct V_32 * V_33 , char * V_12 ,
struct V_26 * V_27 ,
struct V_34 * V_35 )
{
struct V_26 V_52 = * V_27 ;
struct V_15 * V_16 ;
char V_13 [ 32 ] ;
F_12 ( strlen ( V_12 ) < sizeof( V_13 ) / 2 ) ;
strcpy ( V_13 , V_12 ) ;
F_12 ( V_52 . V_30 ) ;
strcat ( V_13 , L_8 ) ;
V_16 = F_23 ( V_33 , V_13 , V_9 , & V_52 , V_35 ) ;
return V_16 ;
}
static struct V_15 *
F_33 ( struct V_32 * V_33 ,
struct V_26 * V_27 , struct V_34 * V_35 )
{
struct V_26 V_52 = * V_27 ;
struct V_15 * V_16 ;
V_52 . V_30 = V_35 ;
V_16 = F_23 ( V_33 , V_53 , V_10 ,
& V_52 , V_35 ) ;
return V_16 ;
}
static struct V_15 *
F_34 ( struct V_32 * V_33 , char * V_13 ,
struct V_26 * V_27 , struct V_34 * V_35 )
{
struct V_54 * V_55 = F_35 ( V_35 ) ;
struct V_15 * V_16 ;
struct V_15 * V_56 ;
struct V_15 * V_57 ;
struct V_15 * V_58 = NULL ;
char V_59 [ 32 ] ;
char * V_60 ;
int V_36 ;
F_5 ( V_11 , L_9 , V_13 , V_27 -> V_30 ) ;
V_60 = strrchr ( V_13 , '-' ) ;
if ( ! V_60 || V_60 - V_13 > 8 ) {
F_2 ( L_10 , V_13 ) ;
return F_25 ( - V_6 ) ;
}
memcpy ( V_59 , V_13 , V_60 - V_13 ) ;
strcpy ( V_59 + ( V_60 - V_13 ) , L_11 ) ;
V_56 = F_20 ( V_59 , NULL ) ;
if ( ! V_56 ) {
V_56 = F_23 ( V_33 , V_59 ,
V_8 , NULL , NULL ) ;
if ( F_36 ( V_56 ) ) {
F_2 ( L_12 , V_59 ) ;
V_36 = F_37 ( V_56 ) ;
goto V_61;
}
}
V_57 = F_33 ( V_33 , V_27 , V_35 ) ;
if ( F_36 ( V_57 ) ) {
V_36 = F_37 ( V_57 ) ;
F_2 ( L_13 ,
V_33 -> V_49 , V_36 ) ;
goto V_62;
}
V_16 = F_23 ( V_33 , V_13 , V_7 , V_27 , V_35 ) ;
if ( F_36 ( V_16 ) ) {
F_2 ( L_14 , V_13 ) ;
V_36 = F_37 ( V_16 ) ;
goto V_63;
}
F_12 ( V_55 -> V_64 ) ;
if ( ! ( V_55 -> V_64 -> V_65 & V_66 ) ) {
V_60 = strrchr ( V_59 , '-' ) ;
if ( V_60 ) {
* V_60 = 0 ;
} else {
F_2 ( L_15 ,
V_33 -> V_49 , V_59 , - V_6 ) ;
V_36 = - V_6 ;
goto V_67;
}
V_58 = F_32 ( V_33 , V_59 , V_27 , V_35 ) ;
if ( F_36 ( V_58 ) ) {
V_36 = F_37 ( V_58 ) ;
goto V_67;
}
}
F_38 ( & V_16 -> V_42 ) ;
V_16 -> V_22 = V_58 ;
V_16 -> V_23 = V_57 ;
V_16 -> V_24 = V_56 ;
F_39 ( & V_16 -> V_42 ) ;
return V_16 ;
V_67:
F_11 ( V_16 ) ;
V_63:
F_11 ( V_57 ) ;
V_62:
F_11 ( V_56 ) ;
V_61:
return F_25 ( V_36 ) ;
}
static inline void F_40 ( struct V_15 * V_16 )
{
F_38 ( & V_16 -> V_42 ) ;
F_21 ( & V_20 ) ;
V_16 -> V_68 = 1 ;
F_15 ( & V_20 ) ;
F_39 ( & V_16 -> V_42 ) ;
}
static int F_41 ( char * V_13 , struct V_26 * V_27 )
{
struct V_15 * V_16 ;
struct V_15 * V_24 = NULL ;
struct V_15 * V_23 = NULL ;
struct V_15 * V_22 = NULL ;
int V_36 = 0 ;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( ! V_16 )
return - V_51 ;
F_38 ( & V_16 -> V_42 ) ;
if ( F_42 ( V_16 -> V_68 ) ) {
F_39 ( & V_16 -> V_42 ) ;
F_11 ( V_16 ) ;
return V_36 ;
}
F_21 ( & V_20 ) ;
V_16 -> V_68 = 1 ;
F_15 ( & V_20 ) ;
V_22 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
V_23 = V_16 -> V_23 ;
V_16 -> V_23 = NULL ;
V_24 = V_16 -> V_24 ;
V_16 -> V_24 = NULL ;
F_39 ( & V_16 -> V_42 ) ;
if ( V_22 ) {
F_40 ( V_22 ) ;
F_11 ( V_22 ) ;
}
if ( V_23 ) {
F_40 ( V_23 ) ;
F_11 ( V_23 ) ;
}
if ( V_24 )
F_11 ( V_24 ) ;
F_11 ( V_16 ) ;
F_11 ( V_16 ) ;
F_5 ( V_11 , L_16 , V_13 ? V_13 : L_17 ,
V_36 ) ;
return V_36 ;
}
int F_43 ( struct V_69 * V_70 , void * V_71 )
{
struct V_32 * V_33 = V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_15 * V_16 ;
int V_36 ;
V_36 = F_44 ( V_33 ) ;
if ( V_36 )
return V_36 ;
V_73 = V_33 -> V_76 . V_77 . V_78 ;
V_75 = & V_73 -> V_79 ;
F_45 ( V_70 , L_18 ,
F_46 ( V_75 , V_80 ) ? L_19 : L_20 ) ;
F_45 ( V_70 , L_21 ) ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( ! V_16 -> V_22 )
continue;
F_45 ( V_70 , L_22 ,
V_16 -> V_19 ,
V_16 -> V_22 -> V_31 . V_43 ) ;
}
F_15 ( & V_20 ) ;
F_47 ( & V_33 -> V_76 . V_77 . V_81 ) ;
return 0 ;
}
static void F_48 ( struct V_15 * V_16 )
{
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_49 ( & V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_81 ,
V_83 ) ;
if ( V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_84 != 0 ) {
int V_36 ;
F_5 ( V_11 , L_23 , V_16 -> V_19 ) ;
V_36 = F_31 ( V_16 -> V_25 -> V_82 , V_16 ) ;
if ( V_36 && V_36 != - V_51 )
F_2 ( L_24 , V_36 ) ;
} else {
F_5 ( V_11 , L_25 ,
V_16 -> V_19 ) ;
}
F_47 ( & V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_81 ) ;
}
static int F_50 ( void * V_71 )
{
bool V_85 = true ;
F_5 ( V_11 , L_26 ) ;
F_21 ( & V_20 ) ;
V_86 |= V_87 ;
while ( ! ( V_86 & V_88 ) ) {
struct V_89 V_90 ;
struct V_15 * V_16 , * V_91 ;
int rand = F_51 () & V_92 ;
int V_93 ;
V_86 &= ~ ( V_94 | V_95 ) ;
F_15 ( & V_20 ) ;
if ( V_85 ) {
V_85 = false ;
F_52 ( & V_96 ) ;
}
V_93 = F_53 ( V_97 * V_98 ) ;
V_93 += F_53 ( rand * V_98 / 100 ) ;
V_90 = F_54 ( V_93 , NULL , NULL ) ;
F_55 ( V_99 , V_86 & ( V_88 | V_100 ) ,
& V_90 ) ;
V_91 = NULL ;
F_21 ( & V_20 ) ;
V_86 &= ~ V_100 ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( ! V_16 -> V_101 || V_16 -> V_68 )
continue;
F_8 ( V_16 ) ;
V_16 -> V_101 = 0 ;
F_15 ( & V_20 ) ;
if ( V_91 )
F_11 ( V_91 ) ;
V_91 = V_16 ;
if ( F_56 ( ! ( V_86 & V_88 ) ) ) {
F_48 ( V_16 ) ;
F_21 ( & V_20 ) ;
} else {
F_21 ( & V_20 ) ;
break;
}
}
F_15 ( & V_20 ) ;
if ( V_91 )
F_11 ( V_91 ) ;
V_90 = (struct V_89 ) { 0 } ;
F_55 ( V_99 , V_86 & ( V_94 | V_88 ) ,
& V_90 ) ;
F_21 ( & V_20 ) ;
}
V_86 &= ~ V_87 ;
F_15 ( & V_20 ) ;
F_52 ( & V_102 ) ;
F_5 ( V_11 , L_27 ) ;
return 0 ;
}
static void F_57 ( struct V_15 * V_16 )
{
bool V_103 = false ;
F_5 ( V_18 , L_28 ,
V_16 -> V_19 , F_10 ( & V_16 -> V_17 ) ,
V_16 -> V_68 , V_86 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_38 ( & V_16 -> V_42 ) ;
F_21 ( & V_20 ) ;
if ( ! ( V_86 & V_88 ) && ! V_16 -> V_68 && ! V_16 -> V_101 ) {
V_16 -> V_101 = 1 ;
V_86 |= V_94 ;
V_103 = true ;
}
F_15 ( & V_20 ) ;
F_39 ( & V_16 -> V_42 ) ;
if ( V_103 )
F_58 ( & V_99 ) ;
}
static int F_59 ( const struct V_104 * V_105 , struct V_32 * V_33 )
{
struct V_106 * V_107 ;
int V_36 ;
V_36 = F_60 ( V_105 , V_33 , & V_33 -> V_108 , V_109 , V_33 ,
& V_110 ) ;
if ( V_36 )
return V_36 ;
V_107 = F_61 ( V_33 , V_109 ) ;
F_12 ( V_107 ) ;
F_62 ( V_107 ) ;
F_63 ( V_107 ) ;
return 0 ;
}
static int F_64 ( const struct V_104 * V_105 , struct V_32 * V_33 )
{
struct V_106 * V_107 ;
V_107 = F_61 ( V_33 , V_109 ) ;
if ( V_107 )
F_65 ( V_105 , V_107 ) ;
return 0 ;
}
static int F_66 ( struct V_32 * V_33 )
{
int V_36 = 0 ;
int V_111 ;
if ( F_67 ( & V_112 ) ) {
F_12 ( V_86 & V_87 ) ;
V_111 = V_88 ;
} else {
V_111 = V_94 | V_100 ;
}
F_21 ( & V_20 ) ;
V_86 |= V_111 ;
F_15 ( & V_20 ) ;
F_58 ( & V_99 ) ;
if ( V_111 & V_88 )
F_68 ( & V_102 ) ;
F_69 ( V_33 ) ;
V_36 = F_64 ( NULL , V_33 ) ;
if ( V_36 )
F_2 ( L_29 ) ;
return V_36 ;
}
static int F_70 ( struct V_32 * V_33 )
{
if ( V_33 -> V_113 -> V_114 <= 1 )
F_71 () ;
F_72 ( V_33 ) ;
F_73 () ;
return F_74 ( V_33 ) ;
}
static int F_75 ( struct V_32 * V_33 , struct V_115 * V_52 )
{
struct V_116 V_117 = { NULL } ;
struct V_118 * V_119 ;
int V_36 ;
V_36 = F_76 () ;
if ( V_36 < 0 )
goto V_120;
V_36 = F_77 ( V_33 , V_52 ) ;
if ( V_36 )
goto V_121;
V_36 = F_59 ( NULL , V_33 ) ;
if ( V_36 ) {
F_2 ( L_30 ) ;
goto V_122;
}
F_78 ( & V_117 ) ;
F_79 ( V_33 , V_117 . V_123 , V_117 . V_124 ) ;
F_80 ( V_33 ) ;
if ( F_81 ( & V_112 ) == 1 ) {
V_86 = 0 ;
F_82 ( & V_99 ) ;
V_119 = F_83 ( F_50 , NULL , L_31 ) ;
if ( F_36 ( V_119 ) ) {
V_36 = F_37 ( V_119 ) ;
F_2 ( L_32 ,
V_33 -> V_49 , V_36 ) ;
goto V_122;
}
V_36 = 0 ;
F_68 ( & V_96 ) ;
}
return V_36 ;
V_122:
F_74 ( V_33 ) ;
V_121:
F_73 () ;
V_120:
return V_36 ;
}
static int F_84 ( struct V_125 * V_126 , struct V_127 * V_128 ,
void * V_71 , int V_129 )
{
struct V_130 V_131 ;
struct V_15 * V_16 = V_71 ;
int V_36 = 0 ;
switch ( V_129 ) {
case V_132 :
F_85 ( V_126 , L_33 ) ;
F_86 ( V_126 , & V_131 ) ;
V_36 = F_87 ( & V_131 , V_133 ) ;
break;
case V_134 :
F_85 ( V_126 , L_34 ) ;
F_5 ( V_11 , L_35 V_135 L_36 ,
F_88 ( V_126 -> V_136 ) ,
( char * ) & V_126 -> V_136 -> V_137 . V_1 [ 0 ] ) ;
if ( ! V_16 ) {
F_5 ( V_18 , L_37 ) ;
break;
}
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
V_126 -> V_138 = NULL ;
if ( V_16 -> V_68 ) {
F_5 ( V_11 , L_38 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
if ( ! V_126 -> V_139 ||
! V_126 -> V_139 -> V_82 -> V_76 . V_77 . V_84 ) {
F_5 ( V_11 , L_39 ,
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
return V_36 ;
}
static int F_89 ( struct V_140 * exp ,
struct V_141 * V_142 )
{
struct V_143 * V_144 ;
struct V_141 * V_145 , * V_146 ;
int V_36 ;
V_144 = F_90 ( F_91 ( exp ) ,
& V_147 , V_148 ,
V_149 ) ;
if ( ! V_144 )
return - V_38 ;
V_145 = F_92 ( & V_144 -> V_150 , & V_151 ) ;
if ( ! V_145 ) {
F_93 ( V_144 ) ;
return - V_38 ;
}
memcpy ( V_145 , V_142 , sizeof( * V_145 ) ) ;
F_94 ( V_144 ) ;
V_144 -> V_152 = V_153 ;
V_36 = F_95 ( V_144 ) ;
if ( ! V_36 ) {
V_146 = F_96 ( & V_144 -> V_150 , & V_151 ) ;
memcpy ( V_142 , V_146 , sizeof( * V_146 ) ) ;
}
F_93 ( V_144 ) ;
return V_36 ;
}
static int F_97 ( struct V_140 * exp , T_2 type ,
union V_154 * V_155 , T_2 V_156 ,
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
struct V_143 * V_144 ;
int V_170 = F_16 ( V_16 ) ;
int V_36 ;
F_5 ( V_11 , L_40 , V_16 -> V_19 ,
V_16 -> V_39 . V_1 [ 0 ] ) ;
V_144 = F_90 ( F_91 ( exp ) ,
& V_171 , V_172 ,
V_173 ) ;
if ( ! V_144 )
return - V_38 ;
F_98 ( & V_144 -> V_150 , & V_174 , V_175 , 0 ) ;
F_94 ( V_144 ) ;
V_144 -> V_152 = V_170 ? 5 : V_176 ;
V_36 = F_99 ( exp , & V_144 , & V_164 , & V_16 -> V_39 , NULL , V_157 ,
NULL , 0 , V_177 , V_131 , 0 ) ;
F_93 ( V_144 ) ;
return V_36 ;
}
static void F_100 ( struct V_32 * V_178 )
{
F_21 ( & V_20 ) ;
V_86 |= V_94 ;
F_15 ( & V_20 ) ;
F_58 ( & V_99 ) ;
}
static int F_101 ( struct V_140 * exp ,
struct V_179 * V_180 )
{
struct V_143 * V_144 ;
struct V_179 * V_181 , * V_182 ;
int V_36 ;
V_144 = F_90 ( F_91 ( exp ) ,
& V_183 , V_148 ,
V_184 ) ;
if ( ! V_144 )
return - V_38 ;
V_181 = F_92 ( & V_144 -> V_150 , & V_185 ) ;
if ( ! V_181 ) {
F_93 ( V_144 ) ;
return - V_38 ;
}
memcpy ( V_181 , V_180 , sizeof( * V_181 ) ) ;
F_94 ( V_144 ) ;
F_5 ( V_11 , L_41 , V_180 -> V_186 ) ;
V_144 -> V_152 = V_187 ;
V_36 = F_95 ( V_144 ) ;
if ( ! V_36 ) {
V_182 = F_96 ( & V_144 -> V_150 ,
& V_185 ) ;
memcpy ( V_180 , V_182 , sizeof( * V_182 ) ) ;
F_5 ( V_11 , L_42 ,
V_180 -> V_186 , V_180 -> V_188 ) ;
}
F_93 ( V_144 ) ;
return V_36 ;
}
static int F_102 ( const struct V_104 * V_105 , struct V_140 * exp ,
T_3 V_189 , void * V_190 , T_3 V_191 ,
void * V_192 , struct V_193 * V_194 )
{
int V_36 = - V_6 ;
if ( F_103 ( V_195 ) ) {
struct V_72 * V_73 = F_91 ( exp ) ;
int V_196 ;
if ( V_191 != sizeof( int ) )
return - V_6 ;
V_196 = * ( int * ) V_192 ;
F_5 ( V_11 , L_43 ,
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
struct V_141 * V_142 ;
V_142 = V_192 ;
V_36 = F_89 ( exp , V_142 ) ;
return V_36 ;
}
if ( F_103 ( V_206 ) ) {
struct V_207 * V_77 = & exp -> V_82 -> V_76 . V_77 ;
struct V_208 V_209 ;
if ( V_191 == 0 ) {
if ( V_77 -> V_210 . V_211 != V_212 )
return 0 ;
V_192 = L_44 ;
V_191 = 4 ;
}
V_36 = F_106 ( V_192 , & V_209 ) ;
if ( V_36 ) {
F_2 ( L_45 ,
( char * ) V_192 ) ;
return V_36 ;
}
if ( V_77 -> V_210 . V_211 == V_212 ) {
V_77 -> V_210 = V_209 ;
} else if ( memcmp ( & V_77 -> V_210 , & V_209 ,
sizeof( V_209 ) ) != 0 ) {
char V_213 [ 20 ] ;
F_107 ( & V_77 -> V_210 ,
V_213 , sizeof( V_213 ) ) ;
F_108 ( L_46 ,
( char * ) V_192 , V_213 ) ;
V_36 = - V_214 ;
}
return V_36 ;
}
return V_36 ;
}
static int F_109 ( const struct V_104 * V_105 , struct V_140 * exp ,
T_2 V_189 , void * V_190 , T_2 * V_191 , void * V_192 )
{
int V_36 = - V_6 ;
if ( F_103 ( V_215 ) ) {
struct V_72 * V_73 = F_91 ( exp ) ;
struct V_74 * V_71 = V_192 ;
if ( * V_191 == sizeof( * V_71 ) ) {
* V_71 = V_73 -> V_79 ;
V_36 = 0 ;
}
}
return V_36 ;
}
static int F_110 ( struct V_32 * V_33 ,
struct V_72 * V_73 ,
enum V_216 V_217 )
{
F_12 ( V_73 -> V_197 == V_33 ) ;
F_5 ( V_11 , L_47 , V_217 ) ;
switch ( V_217 ) {
case V_218 :
if ( F_46 ( & V_73 -> V_79 , V_80 ) )
F_111 () ;
break;
case V_219 :
break;
case V_220 : {
struct V_221 * V_222 = V_33 -> V_223 ;
F_112 ( V_222 , V_224 ) ;
break;
}
case V_225 :
F_5 ( V_18 , L_48 , V_33 -> V_49 ) ;
V_33 -> V_226 = 0 ;
F_100 ( V_33 ) ;
if ( F_46 ( & V_73 -> V_79 , V_80 ) )
F_113 () ;
break;
case V_227 :
break;
case V_228 :
case V_229 :
break;
default:
F_2 ( L_49 , V_217 ) ;
F_4 () ;
}
return 0 ;
}
static int F_114 ( struct V_32 * V_230 ,
struct V_15 * V_16 ,
T_1 V_231 ,
void * V_71 , int V_232 , bool V_233 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_234 * V_235 ;
struct V_115 * V_52 ;
struct V_236 V_237 ;
T_4 V_238 = 0 ;
char * V_239 ;
char * V_240 ;
int V_241 ;
int V_242 ;
int V_36 = 0 ;
int V_243 = 0 ;
F_12 ( V_27 -> V_30 ) ;
F_12 ( V_27 -> V_45 == V_27 -> V_30 ) ;
V_239 = F_24 ( V_244 , V_245 ) ;
if ( ! V_239 )
return - V_38 ;
V_242 = snprintf ( V_239 , V_244 , L_50 , V_27 -> V_30 ) ;
if ( V_242 >= V_244 ) {
F_19 ( V_239 ) ;
return - V_246 ;
}
++ V_242 ;
V_240 = V_239 + V_242 ;
V_241 = V_244 - V_242 ;
while ( V_232 > 0 ) {
int V_247 = sizeof( * V_235 ) ;
int V_248 , V_249 ;
struct V_32 * V_33 ;
char * V_250 ;
char * V_251 ;
char * V_252 ;
char * V_253 ;
T_5 V_2 ;
V_36 = - V_6 ;
if ( V_232 < sizeof( * V_235 ) )
break;
V_235 = ( F_115 ( V_235 ) ) ( V_71 + V_243 ) ;
if ( V_235 -> V_254 != 0 )
break;
if ( V_235 -> V_255 == 0 )
break;
if ( V_235 -> V_256 != sizeof( V_257 ) )
break;
V_247 += V_235 -> V_255 * V_235 -> V_256 ;
if ( V_232 < V_247 )
break;
if ( V_233 )
F_116 ( V_235 ) ;
if ( V_235 -> V_258 > V_244 ) {
F_2 ( L_51 , V_235 -> V_258 ) ;
break;
}
if ( V_235 -> V_258 < V_247 )
break;
V_243 += V_235 -> V_258 ;
V_232 -= V_235 -> V_258 ;
if ( V_232 < 0 )
break;
if ( V_235 -> V_259 > V_231 ) {
F_2 ( L_52 ,
V_235 -> V_259 , V_231 ) ;
break;
}
if ( V_238 >= V_235 -> V_259 ) {
F_2 ( L_53 ,
V_238 , V_235 -> V_259 ) ;
break;
}
V_238 = V_235 -> V_259 ;
V_248 = V_235 -> V_260 == V_261 ;
memset ( V_240 , 0 , V_241 ) ;
V_250 = V_240 ;
V_242 = 0 ;
strcpy ( V_250 , V_16 -> V_19 ) ;
V_251 = strrchr ( V_250 , '-' ) ;
if ( ! V_251 ) {
F_2 ( L_54 ,
V_230 -> V_49 , V_250 ) ;
break;
}
V_242 = V_251 - V_250 ;
V_250 [ V_242 ] = 0 ;
V_242 += sprintf ( V_250 + V_242 , L_55 ,
V_248 ? L_56 : L_57 , V_235 -> V_262 ) ;
V_251 = V_248 ? L_58 : L_59 ;
V_242 += sprintf ( V_250 + V_242 , L_60 , V_251 , V_239 ) ;
F_117 ( & V_237 , V_250 ) ;
V_33 = F_118 ( V_250 ) ;
if ( ! V_33 ) {
F_5 ( V_18 , L_61 ,
V_230 -> V_49 , V_250 ) ;
V_36 = 0 ;
continue;
}
++ V_242 ;
V_252 = V_240 + V_242 ;
V_242 += sprintf ( V_252 , L_62 , V_251 , L_63 ) ;
V_253 = V_240 + V_242 ;
F_119 ( & V_33 -> V_76 . V_77 . V_81 ) ;
if ( ! V_33 -> V_76 . V_77 . V_78 ) {
F_47 ( & V_33 -> V_76 . V_77 . V_81 ) ;
V_36 = 0 ;
continue;
}
V_36 = - V_51 ;
for ( V_249 = 0 ; V_249 < V_235 -> V_255 ; V_249 ++ ) {
V_36 = F_120 ( V_33 -> V_76 . V_77 . V_78 ,
V_235 -> V_76 . V_263 [ 0 ] ,
(struct V_264 * ) V_253 ) ;
if ( ! V_36 )
break;
}
F_47 ( & V_33 -> V_76 . V_77 . V_81 ) ;
if ( V_36 < 0 ) {
F_2 ( L_64 ,
F_121 ( V_235 -> V_76 . V_263 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_65 ,
V_253 , F_121 ( V_235 -> V_76 . V_263 [ 0 ] ) ) ;
V_242 += strlen ( V_253 ) ;
V_242 += sprintf ( V_240 + V_242 , L_66 , V_235 -> V_265 ) ;
F_12 ( V_242 < V_241 ) ;
F_122 ( & V_237 , 1 , V_252 ) ;
V_36 = - V_38 ;
V_2 = F_123 ( V_237 . V_266 , V_237 . V_267 ) ;
V_52 = F_24 ( V_2 , V_37 ) ;
if ( ! V_52 ) {
V_36 = - V_38 ;
break;
}
F_124 ( V_52 , V_268 , & V_237 ) ;
F_5 ( V_18 , L_67 ,
V_238 , V_231 , V_250 , V_252 ) ;
V_36 = F_125 ( V_52 ) ;
F_19 ( V_52 ) ;
if ( V_36 )
F_5 ( V_18 , L_68 ,
V_250 , V_36 ) ;
}
F_19 ( V_239 ) ;
return V_36 ;
}
static int F_126 ( struct V_32 * V_33 ,
struct V_15 * V_16 )
{
struct V_143 * V_144 = NULL ;
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_269 * V_270 ;
struct V_271 * V_272 ;
struct V_273 * V_128 ;
struct V_274 * * V_275 ;
int V_276 ;
bool V_277 = true ;
bool V_233 ;
int V_249 ;
int V_278 ;
int V_36 ;
V_276 = V_279 ;
if ( V_27 -> V_43 == 0 )
V_276 = V_280 ;
V_275 = F_127 ( V_276 , sizeof( * V_275 ) , V_245 ) ;
if ( ! V_275 ) {
V_36 = - V_38 ;
goto V_281;
}
for ( V_249 = 0 ; V_249 < V_276 ; V_249 ++ ) {
V_275 [ V_249 ] = F_128 ( V_245 ) ;
if ( ! V_275 [ V_249 ] ) {
V_36 = - V_38 ;
goto V_281;
}
}
V_282:
F_12 ( F_129 ( V_16 ) ) ;
F_12 ( F_130 ( & V_16 -> V_42 ) ) ;
V_144 = F_131 ( F_91 ( V_16 -> V_25 ) ,
& V_283 ) ;
if ( ! V_144 ) {
V_36 = - V_38 ;
goto V_281;
}
V_36 = F_132 ( V_144 , V_148 , V_284 ) ;
if ( V_36 )
goto V_281;
V_270 = F_92 ( & V_144 -> V_150 , & V_285 ) ;
F_12 ( sizeof( V_270 -> V_286 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_133 ( V_270 -> V_286 , V_16 -> V_19 , sizeof( V_270 -> V_286 ) )
>= sizeof( V_270 -> V_286 ) ) {
V_36 = - V_246 ;
goto V_281;
}
V_270 -> V_287 = V_27 -> V_43 + 1 ;
V_270 -> V_288 = V_16 -> V_46 ;
V_270 -> V_289 = V_290 ;
V_270 -> V_291 = V_276 ;
V_128 = F_134 ( V_144 , V_276 , 1 ,
V_292 | V_293 ,
V_294 ,
& V_295 ) ;
if ( ! V_128 ) {
V_36 = - V_38 ;
goto V_281;
}
for ( V_249 = 0 ; V_249 < V_276 ; V_249 ++ )
V_128 -> V_296 -> V_297 ( V_128 , V_275 [ V_249 ] , 0 , V_244 ) ;
F_94 ( V_144 ) ;
V_36 = F_95 ( V_144 ) ;
if ( V_36 )
goto V_281;
V_272 = F_96 ( & V_144 -> V_150 , & V_298 ) ;
if ( V_272 -> V_299 < V_272 -> V_300 ) {
V_36 = - V_6 ;
goto V_281;
}
V_27 -> V_43 = V_272 -> V_300 ;
V_277 = V_272 -> V_300 == V_272 -> V_299 ;
F_5 ( V_18 , L_69 ,
V_272 -> V_300 , V_277 == false ) ;
V_278 = F_135 ( V_144 , V_144 -> V_301 , 0 ) ;
if ( V_278 < 0 ) {
V_36 = V_278 ;
goto V_281;
}
if ( V_278 > V_276 << V_290 ) {
V_36 = - V_6 ;
goto V_281;
}
if ( V_278 == 0 ) {
if ( ! V_277 )
V_36 = - V_6 ;
goto V_281;
}
V_233 = ! ! F_136 ( V_144 ) ;
#if F_137 ( 3 , 0 , 53 , 0 ) > V_302
if ( F_42 ( V_144 -> V_303 -> V_304 ) )
V_233 = ! V_233 ;
#endif
for ( V_249 = 0 ; V_249 < V_276 && V_278 > 0 ; V_249 ++ ) {
int V_305 ;
void * V_60 ;
V_60 = F_138 ( V_275 [ V_249 ] ) ;
V_305 = F_114 ( V_33 , V_16 , V_272 -> V_300 , V_60 ,
F_139 ( int , V_278 , V_244 ) ,
V_233 ) ;
F_140 ( V_275 [ V_249 ] ) ;
if ( V_305 < 0 ) {
F_141 ( L_70 ,
V_16 -> V_19 , V_305 ) ;
break;
}
V_278 -= V_244 ;
}
V_281:
if ( V_144 )
F_93 ( V_144 ) ;
if ( V_36 == 0 && ! V_277 )
goto V_282;
if ( V_275 ) {
for ( V_249 = 0 ; V_249 < V_276 ; V_249 ++ ) {
if ( ! V_275 [ V_249 ] )
break;
F_142 ( V_275 [ V_249 ] ) ;
}
F_19 ( V_275 ) ;
}
return V_36 ;
}
static int F_143 ( struct V_32 * V_230 ,
struct V_15 * V_16 , int V_306 )
{
struct V_106 * V_107 ;
struct V_54 * V_55 = NULL ;
int V_36 = 0 ;
bool V_307 = false ;
struct V_104 * V_105 ;
F_12 ( V_16 ) ;
F_12 ( F_130 ( & V_16 -> V_42 ) ) ;
if ( F_16 ( V_16 ) && V_306 )
return 0 ;
if ( V_16 -> V_31 . V_45 )
V_55 = F_35 ( V_16 -> V_31 . V_45 ) ;
V_105 = F_24 ( sizeof( * V_105 ) , V_245 ) ;
if ( ! V_105 )
return - V_38 ;
V_36 = F_144 ( V_105 , V_308 ) ;
if ( V_36 )
goto V_309;
V_107 = F_61 ( V_230 , V_109 ) ;
F_12 ( V_107 ) ;
if ( V_306 ) {
V_36 = - V_310 ;
goto V_311;
}
if ( F_16 ( V_16 ) ) {
F_145 ( V_16 -> V_19 ) ;
V_307 = true ;
}
V_36 = F_146 ( V_105 , V_107 , V_16 -> V_19 ,
& V_16 -> V_31 ) ;
V_311:
F_147 ( V_105 , V_107 ) ;
if ( V_307 ) {
F_12 ( F_16 ( V_16 ) ) ;
F_148 ( V_16 -> V_19 ) ;
F_149 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_11 ) ) ;
}
F_150 ( V_105 ) ;
V_309:
F_19 ( V_105 ) ;
return V_36 ;
}
static bool F_151 ( struct V_72 * V_73 )
{
bool V_312 = true ;
F_21 ( & V_73 -> V_313 ) ;
if ( V_73 -> V_202 == V_203 ||
V_73 -> V_202 == V_314 )
V_312 = false ;
F_15 ( & V_73 -> V_313 ) ;
return V_312 ;
}
int F_31 ( struct V_32 * V_230 , struct V_15 * V_16 )
{
struct V_130 V_131 = { 0 } ;
T_1 V_157 = V_315 ;
bool V_316 = false ;
int V_36 = 0 , V_317 ;
F_12 ( V_16 ) ;
V_318:
F_38 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_68 ) {
F_39 ( & V_16 -> V_42 ) ;
return 0 ;
}
F_152 ( V_319 , 20 ) ;
F_5 ( V_11 , L_71 , V_16 -> V_19 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_43 + 1 ) ;
V_317 = F_97 ( V_230 -> V_76 . V_77 . V_320 , V_321 , NULL ,
V_322 , & V_157 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_131 ) ;
if ( V_317 == 0 ) {
F_8 ( V_16 ) ;
V_36 = F_153 ( & V_131 , ( void * ) V_16 ) ;
F_12 ( V_36 == 0 ) ;
} else {
F_5 ( V_11 , L_72 , V_317 ) ;
if ( V_317 == - V_323 &&
F_10 ( & V_230 -> V_76 . V_77 . V_324 ) > 0 && ! V_316 ) {
int V_325 = F_154 ( V_326 ) ;
struct V_72 * V_73 ;
struct V_89 V_90 ;
F_39 ( & V_16 -> V_42 ) ;
V_73 = F_91 ( V_230 -> V_76 . V_77 . V_320 ) ;
F_155 ( V_73 ) ;
V_90 = F_54 ( V_325 , NULL , NULL ) ;
F_55 ( V_73 -> V_327 ,
! F_151 ( V_73 ) , & V_90 ) ;
if ( V_73 -> V_202 == V_203 ) {
V_316 = true ;
goto V_318;
} else {
F_38 ( & V_16 -> V_42 ) ;
F_21 ( & V_20 ) ;
V_16 -> V_101 = 1 ;
F_15 ( & V_20 ) ;
}
} else {
F_21 ( & V_20 ) ;
V_16 -> V_101 = 1 ;
F_15 ( & V_20 ) ;
}
}
if ( F_129 ( V_16 ) ) {
V_36 = 0 ;
if ( ! V_317 ) {
V_36 = F_126 ( V_230 , V_16 ) ;
if ( V_36 ) {
F_2 ( L_73 ,
V_230 -> V_49 , V_16 -> V_19 , V_36 ) ;
V_36 = 0 ;
F_21 ( & V_20 ) ;
V_16 -> V_101 = 1 ;
F_15 ( & V_20 ) ;
}
}
} else {
V_36 = F_143 ( V_230 , V_16 , V_317 != 0 ) ;
}
F_5 ( V_11 , L_74 ,
V_230 -> V_49 , V_16 -> V_19 , V_36 ? L_75 : L_76 , V_36 ) ;
F_39 ( & V_16 -> V_42 ) ;
if ( ! V_317 )
F_156 ( & V_131 , V_322 ) ;
return V_36 ;
}
static int F_157 ( struct V_32 * V_33 , T_3 V_2 , void * V_240 )
{
struct V_115 * V_52 = V_240 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_36 = 0 ;
switch ( V_52 -> V_328 ) {
case V_329 : {
struct V_179 * V_180 ;
if ( F_158 ( V_52 , 1 ) !=
sizeof( struct V_179 ) ) {
V_36 = - V_6 ;
goto V_281;
}
V_180 = (struct V_179 * ) F_159 ( V_52 , 1 ) ;
F_5 ( V_11 , L_77 ,
V_180 -> V_186 , V_180 -> V_330 ) ;
V_36 = F_101 ( V_33 -> V_76 . V_77 . V_320 , V_180 ) ;
break;
}
case V_331 :
F_2 ( L_78 ) ;
V_36 = - V_332 ;
break;
case V_333 : {
V_36 = F_160 ( V_52 ) ;
break;
}
case V_334 : {
struct V_15 * V_16 ;
struct V_34 * V_35 ;
V_13 = F_161 ( V_52 , 1 ) ;
V_27 = (struct V_26 * ) F_159 ( V_52 , 2 ) ;
V_35 = * (struct V_34 * * ) F_159 ( V_52 , 3 ) ;
F_5 ( V_11 , L_79 , V_13 ,
V_27 -> V_43 ) ;
V_16 = F_34 ( V_33 , V_13 , V_27 , V_35 ) ;
if ( F_36 ( V_16 ) ) {
V_36 = F_37 ( V_16 ) ;
break;
}
V_16 -> V_31 . V_44 |= V_335 ;
V_36 = F_31 ( V_33 , V_16 ) ;
if ( V_36 == 0 && V_16 -> V_22 ) {
if ( F_46 ( & V_33 -> V_76 . V_77 . V_78 ->
V_79 , V_80 ) ) {
V_36 = F_31 ( V_33 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_336 ;
F_38 ( & V_16 -> V_42 ) ;
V_336 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_39 ( & V_16 -> V_42 ) ;
F_11 ( V_336 ) ;
}
if ( V_36 )
F_2 ( L_80 , V_36 ) ;
}
if ( V_36 == 0 && V_16 -> V_23 ) {
V_36 = F_31 ( V_33 , V_16 -> V_23 ) ;
if ( V_36 == - V_51 ) {
F_5 ( V_11 ,
L_81 ) ;
V_36 = 0 ;
}
if ( V_36 )
F_2 (
L_82 ,
V_33 -> V_49 , V_36 ) ;
}
break;
}
case V_337 : {
V_13 = F_161 ( V_52 , 1 ) ;
if ( V_52 -> V_266 >= 2 )
V_27 = (struct V_26 * ) F_159 (
V_52 , 2 ) ;
V_36 = F_41 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_83 , V_52 -> V_328 ) ;
V_36 = - V_6 ;
goto V_281;
}
}
V_281:
return V_36 ;
}
static int T_6 F_162 ( void )
{
return F_163 ( & V_338 , NULL ,
V_339 , NULL ) ;
}
static void F_164 ( void )
{
F_165 ( V_339 ) ;
}
