void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_7 ;
F_2 ( V_6 , L_1 ) ;
F_3 ( V_6 ) ;
V_6 -> V_8 |= V_9 ;
if ( V_6 -> V_8 & V_10 )
V_6 -> V_8 |= V_11 ;
V_7 = ! V_6 -> V_12 && ! V_6 -> V_13 ;
F_4 ( V_6 ) ;
if ( V_7 ) {
F_5 ( V_14 ,
L_2 , V_6 ,
V_6 -> V_15 ) ;
if ( V_6 -> V_15 != NULL )
V_6 -> V_15 ( V_6 , V_4 , V_6 -> V_16 ,
V_17 ) ;
} else {
F_5 ( V_14 ,
L_3 ,
V_6 ) ;
}
F_2 ( V_6 , L_4 ) ;
F_6 ( V_6 ) ;
}
static void F_7 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_5 * V_6 )
{
int V_22 ;
F_8 ( V_23 ) ;
int V_24 = 0 ;
F_2 ( V_6 , L_5 ) ;
if ( F_9 ( V_25 ) ) {
int V_26 = F_10 ( 1 ) ;
while ( V_26 > 0 ) {
F_11 ( V_27 ) ;
F_12 ( V_26 ) ;
if ( V_6 -> V_28 == V_6 -> V_29 ||
V_6 -> V_8 & V_30 )
break;
}
}
V_22 = F_13 ( & V_19 -> V_31 , & V_32 , V_33 ) ;
if ( V_22 < 0 ) {
F_14 ( V_6 , L_6 , V_22 ) ;
V_24 = V_22 ;
goto V_34;
} else if ( V_22 > 0 ) {
if ( V_6 -> V_35 > 0 ) {
F_15 ( V_6 -> V_36 != NULL ) ;
if ( F_16 ( V_6 -> V_35 < V_22 ) ) {
F_14 ( V_6 , L_7 ,
V_6 -> V_35 , V_22 ) ;
V_24 = - V_37 ;
goto V_34;
}
} else if ( F_17 ( V_6 ) ) {
void * V_38 ;
V_38 = F_18 ( V_22 , V_39 ) ;
if ( ! V_38 ) {
F_14 ( V_6 , L_8 , V_22 ) ;
V_24 = - V_40 ;
goto V_34;
}
F_3 ( V_6 ) ;
F_15 ( V_6 -> V_36 == NULL ) ;
V_6 -> V_41 = V_42 ;
V_6 -> V_36 = V_38 ;
V_6 -> V_35 = V_22 ;
F_4 ( V_6 ) ;
}
}
F_3 ( V_6 ) ;
if ( ( V_6 -> V_8 & V_30 ) ||
V_6 -> V_28 == V_6 -> V_29 ) {
F_4 ( V_6 ) ;
F_2 ( V_6 , L_9 ) ;
V_24 = 0 ;
goto V_34;
}
if ( V_21 -> V_43 . V_28 != V_6 -> V_29 ) {
V_6 -> V_29 = V_21 -> V_43 . V_28 ;
F_2 ( V_6 , L_10 ) ;
}
if ( V_6 -> V_44 -> V_45 != V_46 ) {
F_19 ( V_19 -> V_47 ,
V_21 -> V_43 . V_44 . V_45 ,
& V_21 -> V_43 . V_48 ,
& V_6 -> V_48 ) ;
F_2 ( V_6 , L_11 ) ;
}
F_20 ( V_6 ) ;
if ( memcmp ( & V_21 -> V_43 . V_44 . V_49 ,
& V_6 -> V_44 -> V_49 ,
sizeof( V_6 -> V_44 -> V_49 ) ) != 0 ) {
F_4 ( V_6 ) ;
V_24 = F_21 ( V_2 , V_6 ,
& V_21 -> V_43 . V_44 . V_49 ) ;
if ( V_24 < 0 ) {
F_14 ( V_6 , L_12 ) ;
goto V_34;
}
F_2 ( V_6 , L_13 ) ;
F_22 ( L_14 ) ;
F_3 ( V_6 ) ;
}
if ( V_21 -> V_50 & V_51 ) {
F_23 ( V_6 ) ;
V_6 -> V_8 |= V_9 | V_52 ;
F_2 ( V_6 , L_15 ) ;
}
if ( V_6 -> V_35 > 0 ) {
V_24 = F_24 ( V_6 , & V_19 -> V_31 , V_33 ,
V_6 -> V_36 , V_22 ) ;
if ( V_24 < 0 ) {
F_4 ( V_6 ) ;
goto V_34;
}
}
F_25 ( V_6 , & V_23 ) ;
F_4 ( V_6 ) ;
F_2 ( V_6 , L_16 ) ;
F_26 ( V_53 , 2 ) ;
F_27 ( V_2 , & V_23 , V_54 ) ;
F_28 ( L_17 ,
V_6 ) ;
goto V_34;
V_34:
if ( V_24 < 0 ) {
F_3 ( V_6 ) ;
V_6 -> V_8 |= V_55 ;
F_4 ( V_6 ) ;
F_29 ( & V_6 -> V_56 ) ;
}
F_6 ( V_6 ) ;
}
static void F_30 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_5 * V_6 )
{
int V_24 = - V_57 ;
F_2 ( V_6 , L_18 ) ;
if ( V_6 -> V_58 != NULL )
V_24 = V_6 -> V_58 ( V_6 , V_19 ) ;
if ( V_19 -> V_59 != NULL ) {
F_31 ( V_19 ) ;
} else {
V_19 -> V_60 = V_24 ;
F_32 ( V_19 ) ;
}
F_3 ( V_6 ) ;
if ( V_6 -> V_28 == V_61 &&
! V_6 -> V_12 && ! V_6 -> V_13 &&
F_33 ( F_34 () ,
F_35 ( V_6 -> V_62 ,
F_10 ( 10 ) ) ) ) {
F_4 ( V_6 ) ;
if ( F_36 ( V_2 , NULL , V_6 ) )
F_1 ( V_2 , NULL , V_6 ) ;
return;
}
F_4 ( V_6 ) ;
F_6 ( V_6 ) ;
}
static int F_37 ( struct V_18 * V_19 , int V_24 )
{
if ( V_19 -> V_63 )
return 0 ;
V_19 -> V_60 = V_24 ;
if ( ! V_19 -> V_64 ) {
V_24 = F_38 ( V_19 , 1 , NULL , NULL ) ;
if ( V_24 )
return V_24 ;
}
return F_31 ( V_19 ) ;
}
static int F_39 ( struct V_65 * V_66 ,
T_1 V_67 )
{
struct V_68 * V_69 = V_70 -> V_68 ;
F_40 ( & V_69 -> V_71 ) ;
if ( V_66 -> V_72 &&
V_66 -> V_72 -> V_8 & V_73 ) {
F_41 ( & V_66 -> V_74 , & V_69 -> V_75 ) ;
} else {
F_41 ( & V_66 -> V_74 , & V_69 -> V_76 ) ;
}
F_42 ( & V_69 -> V_71 ) ;
F_29 ( & V_69 -> V_77 ) ;
if ( ! ( V_67 & V_78 ) )
F_43 ( & V_66 -> V_79 ) ;
return 0 ;
}
static inline void F_44 ( struct V_65 * V_66 ,
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_80 * V_81 , int V_82 ,
struct V_5 * V_6 ,
T_1 V_67 )
{
F_45 ( & V_66 -> V_79 ) ;
F_46 ( & V_66 -> V_83 ) ;
if ( F_47 () )
V_66 -> V_84 = 1 ;
V_66 -> V_85 = V_2 ;
V_66 -> V_86 = V_67 ;
if ( V_4 != NULL )
V_66 -> V_87 = * V_4 ;
if ( V_82 ) {
F_48 ( & V_66 -> V_83 , V_81 ) ;
F_49 ( V_81 ) ;
V_66 -> V_88 = V_82 ;
} else {
V_66 -> V_72 = V_6 ;
}
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_80 * V_81 , int V_82 ,
T_1 V_67 )
{
if ( V_81 && V_82 == 0 )
return 0 ;
if ( V_67 & V_78 ) {
struct V_65 * V_66 ;
V_66 = F_18 ( sizeof( * V_66 ) , V_39 ) ;
if ( ! V_66 )
return - V_40 ;
F_44 ( V_66 , V_2 , V_4 , V_81 , V_82 , V_6 , V_67 ) ;
return F_39 ( V_66 , V_67 ) ;
} else {
struct V_65 V_66 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
F_44 ( & V_66 , V_2 , V_4 , V_81 , V_82 , V_6 , V_67 ) ;
return F_39 ( & V_66 , V_67 ) ;
}
}
int F_36 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
return F_50 ( V_2 , V_4 , V_6 , NULL , 0 , V_78 ) ;
}
int F_51 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_80 * V_81 , int V_82 ,
T_1 V_67 )
{
return F_50 ( V_2 , V_4 , NULL , V_81 , V_82 , V_67 ) ;
}
static int F_52 ( struct V_18 * V_19 )
{
struct V_89 * V_90 = V_19 -> V_47 -> V_91 ;
char * V_92 ;
void * V_93 ;
int V_94 , V_95 ;
int V_24 = - V_57 ;
F_53 ( V_96 , V_19 , L_19 , V_90 -> V_97 ) ;
F_54 ( & V_19 -> V_31 , & V_98 ) ;
V_92 = F_55 ( & V_19 -> V_31 , & V_99 ) ;
if ( V_92 == NULL ) {
F_53 ( V_100 , V_19 , L_20 ) ;
return - V_101 ;
}
V_94 = F_13 ( & V_19 -> V_31 , & V_99 ,
V_33 ) ;
V_93 = F_55 ( & V_19 -> V_31 , & V_102 ) ;
if ( V_93 == NULL ) {
F_53 ( V_100 , V_19 , L_21 ) ;
return - V_101 ;
}
V_95 = F_13 ( & V_19 -> V_31 , & V_102 ,
V_33 ) ;
if ( F_56 ( V_103 ) )
V_24 = F_57 ( V_19 -> V_104 -> V_105 ,
V_19 -> V_47 ,
sizeof( V_103 ) ,
V_103 ,
V_95 , V_93 , NULL ) ;
else
F_53 ( V_106 , V_19 , L_22 , V_92 ) ;
return V_24 ;
}
static inline void F_58 ( struct V_18 * V_19 ,
const char * V_107 , int V_24 ,
struct V_108 * V_109 )
{
F_53 ( ( V_19 -> V_63 || V_24 ) ? V_106 : V_14 , V_19 ,
L_23 ,
V_107 , F_59 ( V_19 -> V_110 ) , V_24 ,
V_109 ? V_109 -> V_111 : 0 ) ;
if ( V_19 -> V_63 )
F_60 ( L_24 ) ;
else if ( V_24 )
F_60 ( L_25 ) ;
}
static int F_61 ( struct V_18 * V_19 )
{
struct V_112 * V_113 ;
struct V_114 * V_115 = & V_19 -> V_47 -> V_91 -> V_116 . V_115 ;
V_113 = F_55 ( & V_19 -> V_31 , & V_117 ) ;
if ( V_113 == NULL ) {
F_22 ( L_26 ) ;
return - V_118 ;
}
V_113 -> V_119 = F_62 ( V_113 -> V_119 ) ;
V_115 -> V_120 = V_113 -> V_119 ;
return 0 ;
}
static int F_63 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
struct V_5 * V_6 ;
int V_24 ;
if ( F_64 ( V_19 -> V_121 ) == V_122 )
return 0 ;
F_65 ( & V_19 -> V_31 , V_19 , V_123 ) ;
if ( V_19 -> V_47 == NULL ) {
V_24 = F_37 ( V_19 , - V_124 ) ;
F_58 ( V_19 , L_27 ,
V_24 , NULL ) ;
return 0 ;
}
F_15 ( V_19 -> V_47 != NULL ) ;
F_15 ( V_19 -> V_47 -> V_91 != NULL ) ;
switch ( F_64 ( V_19 -> V_121 ) ) {
case V_125 :
if ( F_9 ( V_126 ) )
return 0 ;
break;
case V_127 :
if ( F_9 ( V_128 ) )
return 0 ;
break;
case V_129 :
if ( F_9 ( V_130 ) )
return 0 ;
break;
case V_131 :
V_24 = F_52 ( V_19 ) ;
F_37 ( V_19 , V_24 ) ;
return 0 ;
case V_132 :
F_54 ( & V_19 -> V_31 , & V_133 ) ;
if ( F_9 ( V_134 ) )
return 0 ;
V_24 = F_61 ( V_19 ) ;
F_37 ( V_19 , V_24 ) ;
return 0 ;
default:
F_22 ( L_28 ,
F_64 ( V_19 -> V_121 ) ) ;
F_37 ( V_19 , - V_118 ) ;
return 0 ;
}
V_2 = V_19 -> V_47 -> V_91 -> V_135 ;
F_15 ( V_2 != NULL ) ;
F_54 ( & V_19 -> V_31 , & V_136 ) ;
V_21 = F_55 ( & V_19 -> V_31 , & V_137 ) ;
if ( V_21 == NULL ) {
V_24 = F_37 ( V_19 , - V_118 ) ;
F_58 ( V_19 , L_29 , V_24 ,
NULL ) ;
return 0 ;
}
if ( F_9 ( V_25 ) &&
F_64 ( V_19 -> V_121 ) == V_125 ) {
V_24 = F_66 ( & V_21 -> V_138 [ 0 ] , 0 ) ;
if ( V_24 < 0 )
F_22 ( L_30 , V_24 ) ;
}
V_6 = F_67 ( & V_21 -> V_138 [ 0 ] , 0 ) ;
if ( ! V_6 ) {
F_5 ( V_14 , L_31 ,
V_21 -> V_138 [ 0 ] . V_111 ) ;
V_24 = F_37 ( V_19 , - V_37 ) ;
F_58 ( V_19 , L_32 , V_24 ,
& V_21 -> V_138 [ 0 ] ) ;
return 0 ;
}
if ( ( V_6 -> V_8 & V_139 ) &&
F_64 ( V_19 -> V_121 ) == V_125 )
F_68 ( V_140 ) ;
F_3 ( V_6 ) ;
V_6 -> V_8 |= F_69 ( V_21 -> V_50 &
V_141 ) ;
if ( F_64 ( V_19 -> V_121 ) == V_125 ) {
if ( ( ( V_6 -> V_8 & V_142 ) &&
( V_6 -> V_8 & V_143 ) ) ||
( V_6 -> V_8 & V_55 ) ) {
F_2 ( V_6 , L_31 ,
V_21 -> V_138 [ 0 ] . V_111 ) ;
F_4 ( V_6 ) ;
F_6 ( V_6 ) ;
V_24 = F_37 ( V_19 , - V_37 ) ;
F_58 ( V_19 , L_33 , V_24 ,
& V_21 -> V_138 [ 0 ] ) ;
return 0 ;
}
F_23 ( V_6 ) ;
V_6 -> V_8 |= V_52 ;
}
F_4 ( V_6 ) ;
switch ( F_64 ( V_19 -> V_121 ) ) {
case V_125 :
F_5 ( V_144 , L_34 ) ;
F_70 ( & V_19 -> V_31 , & V_145 ) ;
if ( ! ( V_6 -> V_8 & V_10 ) ) {
V_24 = F_37 ( V_19 , 0 ) ;
if ( V_19 -> V_63 || V_24 )
F_58 ( V_19 , L_35 , V_24 ,
& V_21 -> V_138 [ 0 ] ) ;
}
if ( F_36 ( V_2 , & V_21 -> V_43 , V_6 ) )
F_1 ( V_2 , & V_21 -> V_43 , V_6 ) ;
break;
case V_127 :
F_5 ( V_144 , L_36 ) ;
F_70 ( & V_19 -> V_31 , & V_146 ) ;
F_37 ( V_19 , 0 ) ;
F_7 ( V_19 , V_2 , V_21 , V_6 ) ;
break;
case V_129 :
F_5 ( V_144 , L_37 ) ;
F_70 ( & V_19 -> V_31 , & V_147 ) ;
F_30 ( V_19 , V_2 , V_21 , V_6 ) ;
break;
default:
F_71 () ;
}
return 0 ;
}
static struct V_65 * F_72 ( struct V_68 * V_69 )
{
struct V_65 * V_66 = NULL ;
static unsigned int V_148 ;
F_40 ( & V_69 -> V_71 ) ;
if ( ! F_73 ( & V_69 -> V_76 ) &&
( F_73 ( & V_69 -> V_75 ) || V_148 == 0 ) )
V_66 = F_74 ( V_69 -> V_76 . V_149 ,
struct V_65 , V_74 ) ;
else
if ( ! F_73 ( & V_69 -> V_75 ) )
V_66 = F_74 ( V_69 -> V_75 . V_149 ,
struct V_65 ,
V_74 ) ;
if ( V_66 ) {
if ( ++ V_148 >= F_75 ( & V_69 -> V_150 ) )
V_148 = 0 ;
F_76 ( & V_66 -> V_74 ) ;
}
F_42 ( & V_69 -> V_71 ) ;
return V_66 ;
}
static int F_77 ( struct V_68 * V_69 )
{
struct V_151 V_152 = { . V_153 = V_69 } ;
struct V_154 * V_155 ;
F_45 ( & V_152 . V_156 ) ;
V_152 . V_157 = F_75 ( & V_69 -> V_150 ) ;
snprintf ( V_152 . V_158 , sizeof( V_152 . V_158 ) ,
L_38 , V_152 . V_157 ) ;
V_155 = F_78 ( V_159 , & V_152 , L_39 , V_152 . V_158 ) ;
if ( F_79 ( V_155 ) ) {
F_22 ( L_40 ,
F_75 ( & V_69 -> V_150 ) , F_80 ( V_155 ) ) ;
return F_80 ( V_155 ) ;
}
F_43 ( & V_152 . V_156 ) ;
return 0 ;
}
static int V_159 ( void * V_160 )
{
struct V_68 * V_69 ;
{
struct V_151 * V_152 = V_160 ;
V_69 = V_152 -> V_153 ;
F_81 ( & V_69 -> V_150 ) ;
F_81 ( & V_69 -> V_161 ) ;
F_82 ( & V_152 -> V_156 ) ;
}
while ( 1 ) {
struct V_162 V_163 = { 0 } ;
struct V_65 * V_66 = NULL ;
int V_164 ;
V_66 = F_72 ( V_69 ) ;
if ( V_66 == NULL ) {
F_83 ( & V_69 -> V_161 ) ;
F_84 ( V_69 -> V_77 ,
( V_66 = F_72 ( V_69 ) ) != NULL ,
& V_163 ) ;
V_164 = F_85 ( & V_69 -> V_161 ) ;
} else {
V_164 = F_75 ( & V_69 -> V_161 ) ;
}
if ( V_66 -> V_85 == NULL )
break;
if ( F_16 ( V_164 < V_69 -> V_165 &&
V_164 >= F_75 ( & V_69 -> V_150 ) &&
! V_66 -> V_84 ) )
F_77 ( V_69 ) ;
if ( V_66 -> V_84 )
F_86 () ;
if ( V_66 -> V_88 ) {
int V_82 ;
V_82 = F_87 ( & V_66 -> V_83 ,
V_66 -> V_88 ,
V_166 ) ;
F_88 ( & V_66 -> V_83 , V_82 , NULL ,
V_66 -> V_86 ) ;
} else {
F_1 ( V_66 -> V_85 , & V_66 -> V_87 ,
V_66 -> V_72 ) ;
}
if ( V_66 -> V_84 )
F_89 () ;
if ( V_66 -> V_86 & V_78 )
F_90 ( V_66 ) ;
else
F_82 ( & V_66 -> V_79 ) ;
}
F_83 ( & V_69 -> V_161 ) ;
F_83 ( & V_69 -> V_150 ) ;
F_82 ( & V_69 -> V_167 ) ;
return 0 ;
}
int F_91 ( void )
{
int V_24 = 0 ;
F_92 ( & V_168 ) ;
if ( ++ V_169 == 1 ) {
V_24 = F_93 () ;
if ( V_24 )
V_169 -- ;
}
F_94 ( & V_168 ) ;
return V_24 ;
}
void F_95 ( void )
{
F_92 ( & V_168 ) ;
if ( V_169 == 1 ) {
int V_24 = F_96 () ;
if ( V_24 )
F_22 ( L_41 , V_24 ) ;
else
V_169 -- ;
} else {
V_169 -- ;
}
F_94 ( & V_168 ) ;
}
static T_2 F_97 ( struct V_170 * V_171 ,
struct V_172 * V_173 ,
char * V_174 )
{
return sprintf ( V_174 , L_42 , V_175 ) ;
}
static T_2 F_98 ( struct V_170 * V_171 ,
struct V_172 * V_173 ,
const char * V_176 ,
T_3 V_82 )
{
int V_24 ;
unsigned long V_93 ;
V_24 = F_99 ( V_176 , 10 , & V_93 ) ;
if ( V_24 )
return V_24 ;
V_175 = V_93 ;
return V_82 ;
}
static int F_93 ( void )
{
static struct V_177 V_178 ;
struct V_68 * V_69 = NULL ;
int V_24 = 0 ;
int V_179 ;
if ( V_70 != NULL )
return - V_180 ;
V_70 = F_18 ( sizeof( * V_70 ) , V_39 ) ;
if ( ! V_70 )
return - V_40 ;
V_181 = F_100 ( L_43 , V_182 ) ;
if ( ! V_181 ) {
V_24 = - V_40 ;
goto V_34;
}
V_24 = F_101 ( V_181 , & V_183 ) ;
if ( V_24 )
goto V_34;
V_184 = F_102 ( L_44 , NULL , V_181 ) ;
if ( ! V_184 ) {
V_24 = - V_40 ;
goto V_34;
}
V_185 = F_102 ( L_45 , NULL , V_181 ) ;
if ( ! V_185 ) {
V_24 = - V_40 ;
goto V_34;
}
V_24 = F_103 () ;
if ( V_24 != 0 )
goto V_34;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 = ( F_104 ( V_178 ) ) {
. V_186 = L_46 ,
. V_187 = 2 ,
. V_188 = {
. V_189 = V_190 ,
. V_191 = V_192 ,
. V_193 = V_194 ,
. V_195 = V_196 ,
. V_197 = V_198 ,
. V_199 = V_200 ,
} ,
. V_201 = {
. V_202 = L_47 ,
. V_203 = V_204 ,
. V_205 = V_206 ,
. V_207 = V_208 ,
. V_209 = V_210 ,
. V_211 = V_212 ,
. V_213 = 1 ,
. V_214 = V_215 | V_216 ,
} ,
. V_217 = {
. V_218 = V_219 ,
} ,
. V_220 = {
. V_221 = F_63 ,
} ,
} ;
V_70 -> V_222 =
F_105 ( & V_178 , V_185 ,
V_223 ) ;
if ( F_79 ( V_70 -> V_222 ) ) {
F_22 ( L_48 ) ;
V_24 = F_80 ( V_70 -> V_222 ) ;
V_70 -> V_222 = NULL ;
goto V_34;
}
V_69 = F_18 ( sizeof( * V_69 ) , V_39 ) ;
if ( ! V_69 ) {
V_24 = - V_40 ;
goto V_34;
}
V_70 -> V_68 = V_69 ;
F_106 ( & V_69 -> V_71 ) ;
F_46 ( & V_69 -> V_76 ) ;
F_46 ( & V_69 -> V_75 ) ;
F_107 ( & V_69 -> V_77 ) ;
F_108 ( & V_69 -> V_150 , 0 ) ;
F_108 ( & V_69 -> V_161 , 0 ) ;
if ( V_212 == 0 ) {
V_69 -> V_224 = V_206 ;
V_69 -> V_165 = V_210 ;
} else {
V_69 -> V_224 = V_69 -> V_165 =
F_109 ( int , V_210 , F_110 ( int , V_206 ,
V_212 ) ) ;
}
for ( V_179 = 0 ; V_179 < V_69 -> V_224 ; V_179 ++ ) {
V_24 = F_77 ( V_69 ) ;
if ( V_24 < 0 )
goto V_34;
}
V_24 = F_111 () ;
if ( V_24 ) {
F_22 ( L_49 , V_24 ) ;
goto V_34;
}
return 0 ;
V_34:
F_96 () ;
return V_24 ;
}
static int F_96 ( void )
{
if ( ! F_73 ( F_112 ( V_225 ) ) ||
! F_73 ( F_112 ( V_226 ) ) ) {
F_22 ( L_50 ) ;
F_113 ( V_225 , V_14 ) ;
F_113 ( V_226 , V_14 ) ;
return - V_227 ;
}
F_114 () ;
if ( V_70 -> V_68 != NULL ) {
struct V_68 * V_69 = V_70 -> V_68 ;
while ( F_75 ( & V_69 -> V_150 ) > 0 ) {
struct V_65 V_66 = { . V_85 = NULL } ;
F_45 ( & V_69 -> V_167 ) ;
F_40 ( & V_69 -> V_71 ) ;
F_41 ( & V_66 . V_74 , & V_69 -> V_76 ) ;
F_29 ( & V_69 -> V_77 ) ;
F_42 ( & V_69 -> V_71 ) ;
F_43 ( & V_69 -> V_167 ) ;
}
F_90 ( V_69 ) ;
}
if ( V_70 -> V_222 != NULL )
F_115 ( V_70 -> V_222 ) ;
if ( V_184 )
F_116 ( V_184 ) ;
if ( V_185 )
F_116 ( V_185 ) ;
if ( V_181 )
F_117 ( V_181 ) ;
F_118 () ;
F_90 ( V_70 ) ;
V_70 = NULL ;
return 0 ;
}
int F_119 ( void )
{
F_120 ( & V_168 ) ;
F_120 ( F_121 ( V_225 ) ) ;
F_120 ( F_121 ( V_226 ) ) ;
V_228 = F_122 ( L_51 ,
sizeof( struct V_229 ) , 0 ,
V_230 , NULL ) ;
if ( V_228 == NULL )
return - V_40 ;
V_231 = F_122 ( L_52 ,
sizeof( struct V_5 ) , 0 ,
V_230 | V_232 , NULL ) ;
if ( V_231 == NULL ) {
F_123 ( V_228 ) ;
return - V_40 ;
}
V_233 = F_122 ( L_53 ,
sizeof( struct V_234 ) ,
0 , V_230 , NULL ) ;
if ( V_233 == NULL ) {
F_123 ( V_228 ) ;
F_123 ( V_231 ) ;
return - V_40 ;
}
#if V_235
V_236 = V_237 ;
#endif
return 0 ;
}
void F_124 ( void )
{
if ( V_169 )
F_22 ( L_54 , V_169 ) ;
F_123 ( V_228 ) ;
F_125 () ;
F_123 ( V_231 ) ;
F_123 ( V_233 ) ;
}
