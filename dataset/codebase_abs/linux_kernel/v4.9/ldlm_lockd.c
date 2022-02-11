void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_7 ;
F_2 ( V_6 , L_1 ) ;
F_3 ( V_6 ) ;
F_4 ( V_6 ) ;
if ( F_5 ( V_6 ) )
F_6 ( V_6 ) ;
V_7 = ! V_6 -> V_8 && ! V_6 -> V_9 ;
F_7 ( V_6 ) ;
if ( V_7 ) {
F_8 ( V_10 ,
L_2 , V_6 ,
V_6 -> V_11 ) ;
if ( V_6 -> V_11 )
V_6 -> V_11 ( V_6 , V_4 , V_6 -> V_12 ,
V_13 ) ;
} else {
F_8 ( V_10 ,
L_3 ,
V_6 ) ;
}
F_2 ( V_6 , L_4 ) ;
F_9 ( V_6 ) ;
}
static void F_10 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_5 * V_6 )
{
int V_18 ;
F_11 ( V_19 ) ;
int V_20 = 0 ;
F_2 ( V_6 , L_5 ) ;
if ( F_12 ( V_21 ) ) {
int V_22 = F_13 ( 1 ) ;
while ( V_22 > 0 ) {
F_14 ( V_23 ) ;
F_15 ( V_22 ) ;
if ( V_6 -> V_24 == V_6 -> V_25 ||
F_16 ( V_6 ) )
break;
}
}
V_18 = F_17 ( & V_15 -> V_26 , & V_27 , V_28 ) ;
if ( V_18 < 0 ) {
F_18 ( V_6 , L_6 , V_18 ) ;
V_20 = V_18 ;
goto V_29;
} else if ( V_18 > 0 ) {
if ( V_6 -> V_30 > 0 ) {
F_19 ( V_6 -> V_31 ) ;
if ( F_20 ( V_6 -> V_30 < V_18 ) ) {
F_18 ( V_6 , L_7 ,
V_6 -> V_30 , V_18 ) ;
V_20 = - V_32 ;
goto V_29;
}
} else if ( F_21 ( V_6 ) ) {
void * V_33 ;
V_33 = F_22 ( V_18 , V_34 ) ;
if ( ! V_33 ) {
F_18 ( V_6 , L_8 , V_18 ) ;
V_20 = - V_35 ;
goto V_29;
}
F_3 ( V_6 ) ;
F_19 ( ! V_6 -> V_31 ) ;
V_6 -> V_36 = V_37 ;
V_6 -> V_31 = V_33 ;
V_6 -> V_30 = V_18 ;
F_7 ( V_6 ) ;
}
}
F_3 ( V_6 ) ;
if ( F_16 ( V_6 ) ||
V_6 -> V_24 == V_6 -> V_25 ) {
F_7 ( V_6 ) ;
F_2 ( V_6 , L_9 ) ;
V_20 = 0 ;
goto V_29;
}
if ( V_17 -> V_38 . V_24 != V_6 -> V_25 ) {
V_6 -> V_25 = V_17 -> V_38 . V_24 ;
F_2 ( V_6 , L_10 ) ;
}
if ( V_6 -> V_39 -> V_40 != V_41 ) {
F_23 ( V_15 -> V_42 ,
V_17 -> V_38 . V_39 . V_40 ,
& V_17 -> V_38 . V_43 ,
& V_6 -> V_43 ) ;
F_2 ( V_6 , L_11 ) ;
}
F_24 ( V_6 ) ;
if ( memcmp ( & V_17 -> V_38 . V_39 . V_44 ,
& V_6 -> V_39 -> V_44 ,
sizeof( V_6 -> V_39 -> V_44 ) ) != 0 ) {
F_7 ( V_6 ) ;
V_20 = F_25 ( V_2 , V_6 ,
& V_17 -> V_38 . V_39 . V_44 ) ;
if ( V_20 < 0 ) {
F_18 ( V_6 , L_12 ) ;
goto V_29;
}
F_2 ( V_6 , L_13 ) ;
F_26 ( L_14 ) ;
F_3 ( V_6 ) ;
}
if ( V_17 -> V_45 & V_46 ) {
F_27 ( V_6 ) ;
V_6 -> V_47 |= V_48 | V_49 ;
F_2 ( V_6 , L_15 ) ;
}
if ( V_6 -> V_30 > 0 ) {
V_20 = F_28 ( V_6 , & V_15 -> V_26 , V_28 ,
V_6 -> V_31 , V_18 ) ;
if ( V_20 < 0 ) {
F_7 ( V_6 ) ;
goto V_29;
}
}
F_29 ( V_6 , & V_19 ) ;
F_7 ( V_6 ) ;
F_2 ( V_6 , L_16 ) ;
F_30 ( V_50 , 2 ) ;
F_31 ( V_2 , & V_19 , V_51 ) ;
F_32 ( L_17 ,
V_6 ) ;
goto V_29;
V_29:
if ( V_20 < 0 ) {
F_3 ( V_6 ) ;
F_33 ( V_6 ) ;
F_7 ( V_6 ) ;
F_34 ( & V_6 -> V_52 ) ;
}
F_9 ( V_6 ) ;
}
static void F_35 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_5 * V_6 )
{
int V_20 = - V_53 ;
F_2 ( V_6 , L_18 ) ;
if ( V_6 -> V_54 )
V_20 = V_6 -> V_54 ( V_6 , V_15 ) ;
if ( V_15 -> V_55 ) {
F_36 ( V_15 ) ;
} else {
V_15 -> V_56 = V_20 ;
F_37 ( V_15 ) ;
}
F_3 ( V_6 ) ;
if ( V_6 -> V_24 == V_57 &&
! V_6 -> V_8 && ! V_6 -> V_9 &&
F_38 ( F_39 () ,
F_40 ( V_6 -> V_58 ,
F_13 ( 10 ) ) ) ) {
F_7 ( V_6 ) ;
if ( F_41 ( V_2 , NULL , V_6 ) )
F_1 ( V_2 , NULL , V_6 ) ;
return;
}
F_7 ( V_6 ) ;
F_9 ( V_6 ) ;
}
static int F_42 ( struct V_14 * V_15 , int V_20 )
{
if ( V_15 -> V_59 )
return 0 ;
V_15 -> V_56 = V_20 ;
if ( ! V_15 -> V_60 ) {
V_20 = F_43 ( V_15 , 1 , NULL , NULL ) ;
if ( V_20 )
return V_20 ;
}
return F_36 ( V_15 ) ;
}
static int F_44 ( struct V_61 * V_62 ,
enum V_63 V_64 )
{
struct V_65 * V_66 = V_67 -> V_65 ;
F_45 ( & V_66 -> V_68 ) ;
if ( V_62 -> V_69 && F_46 ( V_62 -> V_69 ) ) {
F_47 ( & V_62 -> V_70 , & V_66 -> V_71 ) ;
} else {
F_47 ( & V_62 -> V_70 , & V_66 -> V_72 ) ;
}
F_48 ( & V_66 -> V_68 ) ;
F_34 ( & V_66 -> V_73 ) ;
if ( ! ( V_64 & V_74 ) )
F_49 ( & V_62 -> V_75 ) ;
return 0 ;
}
static inline void F_50 ( struct V_61 * V_62 ,
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_76 * V_77 , int V_78 ,
struct V_5 * V_6 ,
enum V_63 V_64 )
{
F_51 ( & V_62 -> V_75 ) ;
F_52 ( & V_62 -> V_79 ) ;
if ( F_53 () )
V_62 -> V_80 = 1 ;
V_62 -> V_81 = V_2 ;
V_62 -> V_82 = V_64 ;
if ( V_4 )
V_62 -> V_83 = * V_4 ;
if ( V_78 ) {
F_54 ( & V_62 -> V_79 , V_77 ) ;
F_55 ( V_77 ) ;
V_62 -> V_84 = V_78 ;
} else {
V_62 -> V_69 = V_6 ;
}
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_76 * V_77 , int V_78 ,
enum V_63 V_64 )
{
if ( V_77 && V_78 == 0 )
return 0 ;
if ( V_64 & V_74 ) {
struct V_61 * V_62 ;
V_62 = F_22 ( sizeof( * V_62 ) , V_34 ) ;
if ( ! V_62 )
return - V_35 ;
F_50 ( V_62 , V_2 , V_4 , V_77 , V_78 , V_6 , V_64 ) ;
return F_44 ( V_62 , V_64 ) ;
} else {
struct V_61 V_62 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
F_50 ( & V_62 , V_2 , V_4 , V_77 , V_78 , V_6 , V_64 ) ;
return F_44 ( & V_62 , V_64 ) ;
}
}
int F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
return F_56 ( V_2 , V_4 , V_6 , NULL , 0 , V_74 ) ;
}
int F_57 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_76 * V_77 , int V_78 ,
enum V_63 V_64 )
{
return F_56 ( V_2 , V_4 , NULL , V_77 , V_78 , V_64 ) ;
}
static int F_58 ( struct V_14 * V_15 )
{
struct V_85 * V_86 = V_15 -> V_42 -> V_87 ;
char * V_88 ;
void * V_89 ;
int V_90 , V_91 ;
int V_20 = - V_53 ;
F_59 ( V_92 , V_15 , L_19 , V_86 -> V_93 ) ;
F_60 ( & V_15 -> V_26 , & V_94 ) ;
V_88 = F_61 ( & V_15 -> V_26 , & V_95 ) ;
if ( ! V_88 ) {
F_59 ( V_96 , V_15 , L_20 ) ;
return - V_97 ;
}
V_90 = F_17 ( & V_15 -> V_26 , & V_95 ,
V_28 ) ;
V_89 = F_61 ( & V_15 -> V_26 , & V_98 ) ;
if ( ! V_89 ) {
F_59 ( V_96 , V_15 , L_21 ) ;
return - V_97 ;
}
V_91 = F_17 ( & V_15 -> V_26 , & V_98 ,
V_28 ) ;
if ( F_62 ( V_99 ) )
V_20 = F_63 ( V_15 -> V_100 -> V_101 ,
V_15 -> V_42 ,
sizeof( V_99 ) ,
V_99 ,
V_91 , V_89 , NULL ) ;
else
F_59 ( V_102 , V_15 , L_22 , V_88 ) ;
return V_20 ;
}
static inline void F_64 ( struct V_14 * V_15 ,
const char * V_103 , int V_20 ,
const struct V_104 * V_105 )
{
F_59 ( ( V_15 -> V_59 || V_20 ) ? V_102 : V_10 , V_15 ,
L_23 ,
V_103 , F_65 ( V_15 -> V_106 ) , V_20 ,
V_105 ? V_105 -> V_107 : 0 ) ;
if ( V_15 -> V_59 )
F_66 ( L_24 ) ;
else if ( V_20 )
F_66 ( L_25 ) ;
}
static int F_67 ( struct V_14 * V_15 )
{
struct V_108 * V_109 ;
struct V_110 * V_111 = & V_15 -> V_42 -> V_87 -> V_112 . V_111 ;
V_109 = F_61 ( & V_15 -> V_26 , & V_113 ) ;
if ( ! V_109 ) {
F_26 ( L_26 ) ;
return - V_114 ;
}
V_109 -> V_115 = F_68 ( V_109 -> V_115 ) ;
V_111 -> V_116 = V_109 -> V_115 ;
return 0 ;
}
static int F_69 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
struct V_5 * V_6 ;
int V_20 ;
if ( F_70 ( V_15 -> V_117 ) == V_118 )
return 0 ;
F_71 ( & V_15 -> V_26 , V_15 , V_119 ) ;
if ( ! V_15 -> V_42 ) {
V_20 = F_42 ( V_15 , - V_120 ) ;
F_64 ( V_15 , L_27 ,
V_20 , NULL ) ;
return 0 ;
}
F_19 ( V_15 -> V_42 -> V_87 ) ;
switch ( F_70 ( V_15 -> V_117 ) ) {
case V_121 :
if ( F_12 ( V_122 ) ) {
if ( V_123 )
F_42 ( V_15 , - ( int ) V_123 ) ;
return 0 ;
}
break;
case V_124 :
if ( F_12 ( V_125 ) )
return 0 ;
break;
case V_126 :
if ( F_12 ( V_127 ) )
return 0 ;
break;
case V_128 :
V_20 = F_58 ( V_15 ) ;
F_42 ( V_15 , V_20 ) ;
return 0 ;
case V_129 :
F_60 ( & V_15 -> V_26 , & V_130 ) ;
if ( F_12 ( V_131 ) )
return 0 ;
V_20 = F_67 ( V_15 ) ;
F_42 ( V_15 , V_20 ) ;
return 0 ;
default:
F_26 ( L_28 ,
F_70 ( V_15 -> V_117 ) ) ;
F_42 ( V_15 , - V_114 ) ;
return 0 ;
}
V_2 = V_15 -> V_42 -> V_87 -> V_132 ;
F_19 ( V_2 ) ;
F_60 ( & V_15 -> V_26 , & V_133 ) ;
V_17 = F_61 ( & V_15 -> V_26 , & V_134 ) ;
if ( ! V_17 ) {
V_20 = F_42 ( V_15 , - V_114 ) ;
F_64 ( V_15 , L_29 , V_20 ,
NULL ) ;
return 0 ;
}
if ( F_12 ( V_21 ) &&
F_70 ( V_15 -> V_117 ) == V_121 ) {
V_20 = F_72 ( & V_17 -> V_135 [ 0 ] , 0 ) ;
if ( V_20 < 0 )
F_26 ( L_30 , V_20 ) ;
}
V_6 = F_73 ( & V_17 -> V_135 [ 0 ] , 0 ) ;
if ( ! V_6 ) {
F_8 ( V_10 , L_31 ,
V_17 -> V_135 [ 0 ] . V_107 ) ;
V_20 = F_42 ( V_15 , - V_32 ) ;
F_64 ( V_15 , L_32 , V_20 ,
& V_17 -> V_135 [ 0 ] ) ;
return 0 ;
}
if ( F_74 ( V_6 ) &&
F_70 ( V_15 -> V_117 ) == V_121 )
F_75 ( V_136 ) ;
F_3 ( V_6 ) ;
V_6 -> V_47 |= F_76 ( V_17 -> V_45 &
V_137 ) ;
if ( F_70 ( V_15 -> V_117 ) == V_121 ) {
if ( ( F_77 ( V_6 ) && F_78 ( V_6 ) ) ||
F_79 ( V_6 ) ) {
F_2 ( V_6 ,
L_33 ,
V_17 -> V_135 [ 0 ] . V_107 ) ;
F_7 ( V_6 ) ;
F_9 ( V_6 ) ;
V_20 = F_42 ( V_15 , - V_32 ) ;
F_64 ( V_15 , L_34 , V_20 ,
& V_17 -> V_135 [ 0 ] ) ;
return 0 ;
}
F_27 ( V_6 ) ;
F_80 ( V_6 ) ;
}
F_7 ( V_6 ) ;
switch ( F_70 ( V_15 -> V_117 ) ) {
case V_121 :
F_8 ( V_138 , L_35 ) ;
F_81 ( & V_15 -> V_26 , & V_139 ) ;
if ( ! F_5 ( V_6 ) ) {
V_20 = F_42 ( V_15 , 0 ) ;
if ( V_15 -> V_59 || V_20 )
F_64 ( V_15 , L_36 , V_20 ,
& V_17 -> V_135 [ 0 ] ) ;
}
if ( F_41 ( V_2 , & V_17 -> V_38 , V_6 ) )
F_1 ( V_2 , & V_17 -> V_38 , V_6 ) ;
break;
case V_124 :
F_8 ( V_138 , L_37 ) ;
F_81 ( & V_15 -> V_26 , & V_140 ) ;
F_42 ( V_15 , 0 ) ;
F_10 ( V_15 , V_2 , V_17 , V_6 ) ;
break;
case V_126 :
F_8 ( V_138 , L_38 ) ;
F_81 ( & V_15 -> V_26 , & V_141 ) ;
F_35 ( V_15 , V_2 , V_17 , V_6 ) ;
break;
default:
F_82 () ;
}
return 0 ;
}
static struct V_61 * F_83 ( struct V_65 * V_66 )
{
struct V_61 * V_62 = NULL ;
static unsigned int V_142 ;
F_45 ( & V_66 -> V_68 ) ;
if ( ! F_84 ( & V_66 -> V_72 ) &&
( F_84 ( & V_66 -> V_71 ) || V_142 == 0 ) )
V_62 = F_85 ( V_66 -> V_72 . V_143 ,
struct V_61 , V_70 ) ;
else
if ( ! F_84 ( & V_66 -> V_71 ) )
V_62 = F_85 ( V_66 -> V_71 . V_143 ,
struct V_61 ,
V_70 ) ;
if ( V_62 ) {
if ( ++ V_142 >= F_86 ( & V_66 -> V_144 ) )
V_142 = 0 ;
F_87 ( & V_62 -> V_70 ) ;
}
F_48 ( & V_66 -> V_68 ) ;
return V_62 ;
}
static int F_88 ( struct V_65 * V_66 )
{
struct V_145 V_146 = { . V_147 = V_66 } ;
struct V_148 * V_149 ;
F_51 ( & V_146 . V_150 ) ;
V_146 . V_151 = F_86 ( & V_66 -> V_144 ) ;
snprintf ( V_146 . V_152 , sizeof( V_146 . V_152 ) ,
L_39 , V_146 . V_151 ) ;
V_149 = F_89 ( V_153 , & V_146 , L_40 , V_146 . V_152 ) ;
if ( F_90 ( V_149 ) ) {
F_26 ( L_41 ,
F_86 ( & V_66 -> V_144 ) , F_91 ( V_149 ) ) ;
return F_91 ( V_149 ) ;
}
F_49 ( & V_146 . V_150 ) ;
return 0 ;
}
static int V_153 ( void * V_154 )
{
struct V_65 * V_66 ;
{
struct V_145 * V_146 = V_154 ;
V_66 = V_146 -> V_147 ;
F_92 ( & V_66 -> V_144 ) ;
F_92 ( & V_66 -> V_155 ) ;
F_93 ( & V_146 -> V_150 ) ;
}
while ( 1 ) {
struct V_156 V_157 = { 0 } ;
struct V_61 * V_62 = NULL ;
int V_158 ;
V_62 = F_83 ( V_66 ) ;
if ( ! V_62 ) {
F_94 ( & V_66 -> V_155 ) ;
F_95 ( V_66 -> V_73 ,
( V_62 = F_83 ( V_66 ) ) ,
& V_157 ) ;
V_158 = F_96 ( & V_66 -> V_155 ) ;
} else {
V_158 = F_86 ( & V_66 -> V_155 ) ;
}
if ( ! V_62 -> V_81 )
break;
if ( F_20 ( V_158 < V_66 -> V_159 &&
V_158 >= F_86 ( & V_66 -> V_144 ) &&
! V_62 -> V_80 ) )
F_88 ( V_66 ) ;
if ( V_62 -> V_80 )
F_97 () ;
if ( V_62 -> V_84 ) {
int V_78 ;
V_78 = F_98 ( & V_62 -> V_79 ,
V_62 -> V_84 ,
V_160 ) ;
F_99 ( & V_62 -> V_79 , V_78 , NULL ,
V_62 -> V_82 ) ;
} else {
F_1 ( V_62 -> V_81 , & V_62 -> V_83 ,
V_62 -> V_69 ) ;
}
if ( V_62 -> V_80 )
F_100 () ;
if ( V_62 -> V_82 & V_74 )
F_101 ( V_62 ) ;
else
F_93 ( & V_62 -> V_75 ) ;
}
F_94 ( & V_66 -> V_155 ) ;
F_94 ( & V_66 -> V_144 ) ;
F_93 ( & V_66 -> V_161 ) ;
return 0 ;
}
int F_102 ( void )
{
int V_20 = 0 ;
F_103 ( & V_162 ) ;
if ( ++ V_163 == 1 ) {
V_20 = F_104 () ;
if ( V_20 )
V_163 -- ;
}
F_105 ( & V_162 ) ;
return V_20 ;
}
void F_106 ( void )
{
F_103 ( & V_162 ) ;
if ( V_163 == 1 ) {
int V_20 = F_107 () ;
if ( V_20 )
F_26 ( L_42 , V_20 ) ;
else
V_163 -- ;
} else {
V_163 -- ;
}
F_105 ( & V_162 ) ;
}
static T_1 F_108 ( struct V_164 * V_165 ,
struct V_166 * V_167 ,
char * V_168 )
{
return sprintf ( V_168 , L_43 , V_169 ) ;
}
static T_1 F_109 ( struct V_164 * V_165 ,
struct V_166 * V_167 ,
const char * V_170 ,
T_2 V_78 )
{
int V_20 ;
unsigned long V_89 ;
V_20 = F_110 ( V_170 , 10 , & V_89 ) ;
if ( V_20 )
return V_20 ;
V_169 = V_89 ;
return V_78 ;
}
static int F_104 ( void )
{
static struct V_171 V_172 ;
struct V_65 * V_66 = NULL ;
int V_20 = 0 ;
int V_173 ;
if ( V_67 )
return - V_174 ;
V_67 = F_22 ( sizeof( * V_67 ) , V_34 ) ;
if ( ! V_67 )
return - V_35 ;
V_175 = F_111 ( L_44 , V_176 ) ;
if ( ! V_175 ) {
V_20 = - V_35 ;
goto V_29;
}
V_20 = F_112 ( V_175 , & V_177 ) ;
if ( V_20 )
goto V_29;
V_178 = F_113 ( L_45 , NULL , V_175 ) ;
if ( ! V_178 ) {
V_20 = - V_35 ;
goto V_29;
}
V_179 = F_113 ( L_46 , NULL , V_175 ) ;
if ( ! V_179 ) {
V_20 = - V_35 ;
goto V_29;
}
V_20 = F_114 () ;
if ( V_20 != 0 )
goto V_29;
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
V_172 = ( F_115 ( V_172 ) ) {
. V_180 = L_47 ,
. V_181 = 2 ,
. V_182 = {
. V_183 = V_184 ,
. V_185 = V_186 ,
. V_187 = V_188 ,
. V_189 = V_190 ,
. V_191 = V_192 ,
. V_193 = V_194 ,
} ,
. V_195 = {
. V_196 = L_48 ,
. V_197 = V_198 ,
. V_199 = V_200 ,
. V_201 = V_202 ,
. V_203 = V_204 ,
. V_205 = V_206 ,
. V_207 = 1 ,
. V_208 = V_209 | V_210 ,
} ,
. V_211 = {
. V_212 = V_213 ,
} ,
. V_214 = {
. V_215 = F_69 ,
} ,
} ;
V_67 -> V_216 =
F_116 ( & V_172 , V_179 ,
V_217 ) ;
if ( F_90 ( V_67 -> V_216 ) ) {
F_26 ( L_49 ) ;
V_20 = F_91 ( V_67 -> V_216 ) ;
V_67 -> V_216 = NULL ;
goto V_29;
}
V_66 = F_22 ( sizeof( * V_66 ) , V_34 ) ;
if ( ! V_66 ) {
V_20 = - V_35 ;
goto V_29;
}
V_67 -> V_65 = V_66 ;
F_117 ( & V_66 -> V_68 ) ;
F_52 ( & V_66 -> V_72 ) ;
F_52 ( & V_66 -> V_71 ) ;
F_118 ( & V_66 -> V_73 ) ;
F_119 ( & V_66 -> V_144 , 0 ) ;
F_119 ( & V_66 -> V_155 , 0 ) ;
if ( V_206 == 0 ) {
V_66 -> V_218 = V_200 ;
V_66 -> V_159 = V_204 ;
} else {
V_66 -> V_218 = F_120 ( int , V_204 ,
F_121 ( int , V_200 ,
V_206 ) ) ;
V_66 -> V_159 = V_66 -> V_218 ;
}
for ( V_173 = 0 ; V_173 < V_66 -> V_218 ; V_173 ++ ) {
V_20 = F_88 ( V_66 ) ;
if ( V_20 < 0 )
goto V_29;
}
V_20 = F_122 () ;
if ( V_20 ) {
F_26 ( L_50 , V_20 ) ;
goto V_29;
}
return 0 ;
V_29:
F_107 () ;
return V_20 ;
}
static int F_107 ( void )
{
if ( ! F_84 ( F_123 ( V_219 ) ) ||
! F_84 ( F_123 ( V_220 ) ) ) {
F_26 ( L_51 ) ;
F_124 ( V_219 , V_10 ) ;
F_124 ( V_220 , V_10 ) ;
return - V_221 ;
}
F_125 () ;
if ( V_67 -> V_65 ) {
struct V_65 * V_66 = V_67 -> V_65 ;
while ( F_86 ( & V_66 -> V_144 ) > 0 ) {
struct V_61 V_62 = { . V_81 = NULL } ;
F_51 ( & V_66 -> V_161 ) ;
F_45 ( & V_66 -> V_68 ) ;
F_47 ( & V_62 . V_70 , & V_66 -> V_72 ) ;
F_34 ( & V_66 -> V_73 ) ;
F_48 ( & V_66 -> V_68 ) ;
F_49 ( & V_66 -> V_161 ) ;
}
F_101 ( V_66 ) ;
}
if ( V_67 -> V_216 )
F_126 ( V_67 -> V_216 ) ;
if ( V_178 )
F_127 ( V_178 ) ;
if ( V_179 )
F_127 ( V_179 ) ;
if ( V_175 )
F_128 ( V_175 ) ;
F_129 () ;
F_101 ( V_67 ) ;
V_67 = NULL ;
return 0 ;
}
int F_130 ( void )
{
F_131 ( & V_162 ) ;
F_131 ( F_132 ( V_219 ) ) ;
F_131 ( F_132 ( V_220 ) ) ;
V_222 = F_133 ( L_52 ,
sizeof( struct V_223 ) , 0 ,
V_224 , NULL ) ;
if ( ! V_222 )
return - V_35 ;
V_225 = F_133 ( L_53 ,
sizeof( struct V_5 ) , 0 ,
V_224 |
V_226 , NULL ) ;
if ( ! V_225 ) {
F_134 ( V_222 ) ;
return - V_35 ;
}
V_227 = F_133 ( L_54 ,
sizeof( struct V_228 ) ,
0 , V_224 , NULL ) ;
if ( ! V_227 ) {
F_134 ( V_222 ) ;
F_134 ( V_225 ) ;
return - V_35 ;
}
#if V_229
V_230 = V_231 ;
#endif
return 0 ;
}
void F_135 ( void )
{
if ( V_163 )
F_26 ( L_55 , V_163 ) ;
F_134 ( V_222 ) ;
F_136 () ;
F_134 ( V_225 ) ;
F_134 ( V_227 ) ;
}
