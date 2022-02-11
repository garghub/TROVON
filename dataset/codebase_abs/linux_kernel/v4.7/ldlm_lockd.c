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
struct V_104 * V_105 )
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
if ( F_12 ( V_122 ) )
return 0 ;
break;
case V_123 :
if ( F_12 ( V_124 ) )
return 0 ;
break;
case V_125 :
if ( F_12 ( V_126 ) )
return 0 ;
break;
case V_127 :
V_20 = F_58 ( V_15 ) ;
F_42 ( V_15 , V_20 ) ;
return 0 ;
case V_128 :
F_60 ( & V_15 -> V_26 , & V_129 ) ;
if ( F_12 ( V_130 ) )
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
V_2 = V_15 -> V_42 -> V_87 -> V_131 ;
F_19 ( V_2 ) ;
F_60 ( & V_15 -> V_26 , & V_132 ) ;
V_17 = F_61 ( & V_15 -> V_26 , & V_133 ) ;
if ( ! V_17 ) {
V_20 = F_42 ( V_15 , - V_114 ) ;
F_64 ( V_15 , L_29 , V_20 ,
NULL ) ;
return 0 ;
}
if ( F_12 ( V_21 ) &&
F_70 ( V_15 -> V_117 ) == V_121 ) {
V_20 = F_72 ( & V_17 -> V_134 [ 0 ] , 0 ) ;
if ( V_20 < 0 )
F_26 ( L_30 , V_20 ) ;
}
V_6 = F_73 ( & V_17 -> V_134 [ 0 ] , 0 ) ;
if ( ! V_6 ) {
F_8 ( V_10 , L_31 ,
V_17 -> V_134 [ 0 ] . V_107 ) ;
V_20 = F_42 ( V_15 , - V_32 ) ;
F_64 ( V_15 , L_32 , V_20 ,
& V_17 -> V_134 [ 0 ] ) ;
return 0 ;
}
if ( F_74 ( V_6 ) &&
F_70 ( V_15 -> V_117 ) == V_121 )
F_75 ( V_135 ) ;
F_3 ( V_6 ) ;
V_6 -> V_47 |= F_76 ( V_17 -> V_45 &
V_136 ) ;
if ( F_70 ( V_15 -> V_117 ) == V_121 ) {
if ( ( F_77 ( V_6 ) && F_78 ( V_6 ) ) ||
F_79 ( V_6 ) ) {
F_2 ( V_6 , L_31 ,
V_17 -> V_134 [ 0 ] . V_107 ) ;
F_7 ( V_6 ) ;
F_9 ( V_6 ) ;
V_20 = F_42 ( V_15 , - V_32 ) ;
F_64 ( V_15 , L_33 , V_20 ,
& V_17 -> V_134 [ 0 ] ) ;
return 0 ;
}
F_27 ( V_6 ) ;
F_80 ( V_6 ) ;
}
F_7 ( V_6 ) ;
switch ( F_70 ( V_15 -> V_117 ) ) {
case V_121 :
F_8 ( V_137 , L_34 ) ;
F_81 ( & V_15 -> V_26 , & V_138 ) ;
if ( ! F_5 ( V_6 ) ) {
V_20 = F_42 ( V_15 , 0 ) ;
if ( V_15 -> V_59 || V_20 )
F_64 ( V_15 , L_35 , V_20 ,
& V_17 -> V_134 [ 0 ] ) ;
}
if ( F_41 ( V_2 , & V_17 -> V_38 , V_6 ) )
F_1 ( V_2 , & V_17 -> V_38 , V_6 ) ;
break;
case V_123 :
F_8 ( V_137 , L_36 ) ;
F_81 ( & V_15 -> V_26 , & V_139 ) ;
F_42 ( V_15 , 0 ) ;
F_10 ( V_15 , V_2 , V_17 , V_6 ) ;
break;
case V_125 :
F_8 ( V_137 , L_37 ) ;
F_81 ( & V_15 -> V_26 , & V_140 ) ;
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
static unsigned int V_141 ;
F_45 ( & V_66 -> V_68 ) ;
if ( ! F_84 ( & V_66 -> V_72 ) &&
( F_84 ( & V_66 -> V_71 ) || V_141 == 0 ) )
V_62 = F_85 ( V_66 -> V_72 . V_142 ,
struct V_61 , V_70 ) ;
else
if ( ! F_84 ( & V_66 -> V_71 ) )
V_62 = F_85 ( V_66 -> V_71 . V_142 ,
struct V_61 ,
V_70 ) ;
if ( V_62 ) {
if ( ++ V_141 >= F_86 ( & V_66 -> V_143 ) )
V_141 = 0 ;
F_87 ( & V_62 -> V_70 ) ;
}
F_48 ( & V_66 -> V_68 ) ;
return V_62 ;
}
static int F_88 ( struct V_65 * V_66 )
{
struct V_144 V_145 = { . V_146 = V_66 } ;
struct V_147 * V_148 ;
F_51 ( & V_145 . V_149 ) ;
V_145 . V_150 = F_86 ( & V_66 -> V_143 ) ;
snprintf ( V_145 . V_151 , sizeof( V_145 . V_151 ) ,
L_38 , V_145 . V_150 ) ;
V_148 = F_89 ( V_152 , & V_145 , L_39 , V_145 . V_151 ) ;
if ( F_90 ( V_148 ) ) {
F_26 ( L_40 ,
F_86 ( & V_66 -> V_143 ) , F_91 ( V_148 ) ) ;
return F_91 ( V_148 ) ;
}
F_49 ( & V_145 . V_149 ) ;
return 0 ;
}
static int V_152 ( void * V_153 )
{
struct V_65 * V_66 ;
{
struct V_144 * V_145 = V_153 ;
V_66 = V_145 -> V_146 ;
F_92 ( & V_66 -> V_143 ) ;
F_92 ( & V_66 -> V_154 ) ;
F_93 ( & V_145 -> V_149 ) ;
}
while ( 1 ) {
struct V_155 V_156 = { 0 } ;
struct V_61 * V_62 = NULL ;
int V_157 ;
V_62 = F_83 ( V_66 ) ;
if ( ! V_62 ) {
F_94 ( & V_66 -> V_154 ) ;
F_95 ( V_66 -> V_73 ,
( V_62 = F_83 ( V_66 ) ) ,
& V_156 ) ;
V_157 = F_96 ( & V_66 -> V_154 ) ;
} else {
V_157 = F_86 ( & V_66 -> V_154 ) ;
}
if ( ! V_62 -> V_81 )
break;
if ( F_20 ( V_157 < V_66 -> V_158 &&
V_157 >= F_86 ( & V_66 -> V_143 ) &&
! V_62 -> V_80 ) )
F_88 ( V_66 ) ;
if ( V_62 -> V_80 )
F_97 () ;
if ( V_62 -> V_84 ) {
int V_78 ;
V_78 = F_98 ( & V_62 -> V_79 ,
V_62 -> V_84 ,
V_159 ) ;
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
F_94 ( & V_66 -> V_154 ) ;
F_94 ( & V_66 -> V_143 ) ;
F_93 ( & V_66 -> V_160 ) ;
return 0 ;
}
int F_102 ( void )
{
int V_20 = 0 ;
F_103 ( & V_161 ) ;
if ( ++ V_162 == 1 ) {
V_20 = F_104 () ;
if ( V_20 )
V_162 -- ;
}
F_105 ( & V_161 ) ;
return V_20 ;
}
void F_106 ( void )
{
F_103 ( & V_161 ) ;
if ( V_162 == 1 ) {
int V_20 = F_107 () ;
if ( V_20 )
F_26 ( L_41 , V_20 ) ;
else
V_162 -- ;
} else {
V_162 -- ;
}
F_105 ( & V_161 ) ;
}
static T_1 F_108 ( struct V_163 * V_164 ,
struct V_165 * V_166 ,
char * V_167 )
{
return sprintf ( V_167 , L_42 , V_168 ) ;
}
static T_1 F_109 ( struct V_163 * V_164 ,
struct V_165 * V_166 ,
const char * V_169 ,
T_2 V_78 )
{
int V_20 ;
unsigned long V_89 ;
V_20 = F_110 ( V_169 , 10 , & V_89 ) ;
if ( V_20 )
return V_20 ;
V_168 = V_89 ;
return V_78 ;
}
static int F_104 ( void )
{
static struct V_170 V_171 ;
struct V_65 * V_66 = NULL ;
int V_20 = 0 ;
int V_172 ;
if ( V_67 )
return - V_173 ;
V_67 = F_22 ( sizeof( * V_67 ) , V_34 ) ;
if ( ! V_67 )
return - V_35 ;
V_174 = F_111 ( L_43 , V_175 ) ;
if ( ! V_174 ) {
V_20 = - V_35 ;
goto V_29;
}
V_20 = F_112 ( V_174 , & V_176 ) ;
if ( V_20 )
goto V_29;
V_177 = F_113 ( L_44 , NULL , V_174 ) ;
if ( ! V_177 ) {
V_20 = - V_35 ;
goto V_29;
}
V_178 = F_113 ( L_45 , NULL , V_174 ) ;
if ( ! V_178 ) {
V_20 = - V_35 ;
goto V_29;
}
V_20 = F_114 () ;
if ( V_20 != 0 )
goto V_29;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 = ( F_115 ( V_171 ) ) {
. V_179 = L_46 ,
. V_180 = 2 ,
. V_181 = {
. V_182 = V_183 ,
. V_184 = V_185 ,
. V_186 = V_187 ,
. V_188 = V_189 ,
. V_190 = V_191 ,
. V_192 = V_193 ,
} ,
. V_194 = {
. V_195 = L_47 ,
. V_196 = V_197 ,
. V_198 = V_199 ,
. V_200 = V_201 ,
. V_202 = V_203 ,
. V_204 = V_205 ,
. V_206 = 1 ,
. V_207 = V_208 | V_209 ,
} ,
. V_210 = {
. V_211 = V_212 ,
} ,
. V_213 = {
. V_214 = F_69 ,
} ,
} ;
V_67 -> V_215 =
F_116 ( & V_171 , V_178 ,
V_216 ) ;
if ( F_90 ( V_67 -> V_215 ) ) {
F_26 ( L_48 ) ;
V_20 = F_91 ( V_67 -> V_215 ) ;
V_67 -> V_215 = NULL ;
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
F_119 ( & V_66 -> V_143 , 0 ) ;
F_119 ( & V_66 -> V_154 , 0 ) ;
if ( V_205 == 0 ) {
V_66 -> V_217 = V_199 ;
V_66 -> V_158 = V_203 ;
} else {
V_66 -> V_217 = V_66 -> V_158 =
F_120 ( int , V_203 , F_121 ( int , V_199 ,
V_205 ) ) ;
}
for ( V_172 = 0 ; V_172 < V_66 -> V_217 ; V_172 ++ ) {
V_20 = F_88 ( V_66 ) ;
if ( V_20 < 0 )
goto V_29;
}
V_20 = F_122 () ;
if ( V_20 ) {
F_26 ( L_49 , V_20 ) ;
goto V_29;
}
return 0 ;
V_29:
F_107 () ;
return V_20 ;
}
static int F_107 ( void )
{
if ( ! F_84 ( F_123 ( V_218 ) ) ||
! F_84 ( F_123 ( V_219 ) ) ) {
F_26 ( L_50 ) ;
F_124 ( V_218 , V_10 ) ;
F_124 ( V_219 , V_10 ) ;
return - V_220 ;
}
F_125 () ;
if ( V_67 -> V_65 ) {
struct V_65 * V_66 = V_67 -> V_65 ;
while ( F_86 ( & V_66 -> V_143 ) > 0 ) {
struct V_61 V_62 = { . V_81 = NULL } ;
F_51 ( & V_66 -> V_160 ) ;
F_45 ( & V_66 -> V_68 ) ;
F_47 ( & V_62 . V_70 , & V_66 -> V_72 ) ;
F_34 ( & V_66 -> V_73 ) ;
F_48 ( & V_66 -> V_68 ) ;
F_49 ( & V_66 -> V_160 ) ;
}
F_101 ( V_66 ) ;
}
if ( V_67 -> V_215 )
F_126 ( V_67 -> V_215 ) ;
if ( V_177 )
F_127 ( V_177 ) ;
if ( V_178 )
F_127 ( V_178 ) ;
if ( V_174 )
F_128 ( V_174 ) ;
F_129 () ;
F_101 ( V_67 ) ;
V_67 = NULL ;
return 0 ;
}
int F_130 ( void )
{
F_131 ( & V_161 ) ;
F_131 ( F_132 ( V_218 ) ) ;
F_131 ( F_132 ( V_219 ) ) ;
V_221 = F_133 ( L_51 ,
sizeof( struct V_222 ) , 0 ,
V_223 , NULL ) ;
if ( ! V_221 )
return - V_35 ;
V_224 = F_133 ( L_52 ,
sizeof( struct V_5 ) , 0 ,
V_223 | V_225 , NULL ) ;
if ( ! V_224 ) {
F_134 ( V_221 ) ;
return - V_35 ;
}
V_226 = F_133 ( L_53 ,
sizeof( struct V_227 ) ,
0 , V_223 , NULL ) ;
if ( ! V_226 ) {
F_134 ( V_221 ) ;
F_134 ( V_224 ) ;
return - V_35 ;
}
#if V_228
V_229 = V_230 ;
#endif
return 0 ;
}
void F_135 ( void )
{
if ( V_162 )
F_26 ( L_54 , V_162 ) ;
F_134 ( V_221 ) ;
F_136 () ;
F_134 ( V_224 ) ;
F_134 ( V_226 ) ;
}
