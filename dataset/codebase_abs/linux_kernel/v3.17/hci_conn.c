static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 , 0 , NULL ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_6 * V_7 ;
struct V_8 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 ++ ;
V_2 -> V_16 = V_3 -> V_16 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
V_9 . V_19 = 0x02 ;
V_7 = F_6 ( V_3 , & V_2 -> V_18 ) ;
if ( V_7 ) {
if ( F_7 ( V_7 ) <= V_20 ) {
V_9 . V_19 = V_7 -> V_21 . V_19 ;
V_9 . V_22 = V_7 -> V_21 . V_22 ;
V_9 . V_23 = V_7 -> V_21 . V_23 |
F_8 ( 0x8000 ) ;
}
memcpy ( V_2 -> V_24 , V_7 -> V_21 . V_24 , 3 ) ;
if ( V_7 -> V_21 . V_25 > 0 )
F_9 ( V_26 , & V_2 -> V_27 ) ;
}
V_9 . V_28 = F_8 ( V_2 -> V_28 ) ;
if ( F_10 ( V_3 ) && ! ( V_3 -> V_29 & V_30 ) )
V_9 . V_31 = 0x01 ;
else
V_9 . V_31 = 0x00 ;
F_2 ( V_3 , V_32 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_33 V_9 ;
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_3 -> V_34 < V_35 )
return;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
F_2 ( V_2 -> V_3 , V_36 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_37 V_9 ;
V_9 . V_38 = V_39 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
F_2 ( V_2 -> V_3 , V_40 , sizeof( V_9 ) , & V_9 ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_38 )
{
struct V_41 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_42 ;
V_9 . V_43 = F_8 ( V_2 -> V_43 ) ;
V_9 . V_38 = V_38 ;
F_2 ( V_2 -> V_3 , V_44 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_45 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_42 ;
V_9 . V_46 = F_15 ( V_2 -> V_43 ) ;
V_9 . V_38 = F_16 ( V_2 ) ;
F_2 ( V_2 -> V_3 , V_47 ,
sizeof( V_9 ) , & V_9 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_2 V_43 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_48 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_43 = F_8 ( V_43 ) ;
V_9 . V_28 = F_8 ( V_2 -> V_28 ) ;
F_2 ( V_3 , V_49 , sizeof( V_9 ) , & V_9 ) ;
}
bool F_18 ( struct V_1 * V_2 , T_2 V_43 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_50 V_9 ;
const struct V_51 * V_52 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_43 = F_8 ( V_43 ) ;
V_9 . V_53 = F_19 ( 0x00001f40 ) ;
V_9 . V_54 = F_19 ( 0x00001f40 ) ;
V_9 . V_55 = F_8 ( V_2 -> V_56 ) ;
switch ( V_2 -> V_56 & V_57 ) {
case V_58 :
if ( V_2 -> V_15 > F_20 ( V_59 ) )
return false ;
V_9 . V_60 = 0x02 ;
V_52 = & V_59 [ V_2 -> V_15 - 1 ] ;
break;
case V_61 :
if ( V_2 -> V_15 > F_20 ( V_62 ) )
return false ;
V_9 . V_60 = 0x01 ;
V_52 = & V_62 [ V_2 -> V_15 - 1 ] ;
break;
default:
return false ;
}
V_9 . V_28 = F_21 ( V_52 -> V_28 ) ;
V_9 . V_63 = F_21 ( V_52 -> V_63 ) ;
if ( F_2 ( V_3 , V_64 , sizeof( V_9 ) , & V_9 ) < 0 )
return false ;
return true ;
}
T_3 F_22 ( struct V_1 * V_2 , T_4 V_65 , T_4 V_66 , T_4 V_67 ,
T_4 V_68 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_69 * V_70 ;
struct V_71 V_9 ;
F_23 ( V_3 ) ;
V_70 = F_24 ( V_3 , & V_2 -> V_18 , V_2 -> V_72 ) ;
if ( V_70 ) {
V_70 -> V_73 = V_65 ;
V_70 -> V_74 = V_66 ;
V_70 -> V_75 = V_67 ;
V_70 -> V_76 = V_68 ;
}
F_25 ( V_3 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_43 = F_8 ( V_2 -> V_43 ) ;
V_9 . V_77 = F_8 ( V_65 ) ;
V_9 . V_78 = F_8 ( V_66 ) ;
V_9 . V_75 = F_8 ( V_67 ) ;
V_9 . V_76 = F_8 ( V_68 ) ;
V_9 . V_79 = F_8 ( 0x0000 ) ;
V_9 . V_80 = F_8 ( 0x0000 ) ;
F_2 ( V_3 , V_81 , sizeof( V_9 ) , & V_9 ) ;
if ( V_70 )
return 0x01 ;
return 0x00 ;
}
void F_26 ( struct V_1 * V_2 , T_5 V_82 , T_6 rand ,
T_1 V_83 [ 16 ] )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_84 V_9 ;
F_4 ( L_1 , V_2 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_43 = F_8 ( V_2 -> V_43 ) ;
V_9 . rand = rand ;
V_9 . V_82 = V_82 ;
memcpy ( V_9 . V_83 , V_83 , sizeof( V_9 . V_83 ) ) ;
F_2 ( V_3 , V_85 , sizeof( V_9 ) , & V_9 ) ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_86 )
{
struct V_1 * V_87 = V_2 -> V_88 ;
if ( ! V_87 )
return;
F_4 ( L_1 , V_2 ) ;
if ( ! V_86 ) {
if ( F_28 ( V_2 -> V_3 ) )
F_18 ( V_87 , V_2 -> V_43 ) ;
else
F_17 ( V_87 , V_2 -> V_43 ) ;
} else {
F_29 ( V_87 , V_86 ) ;
F_30 ( V_87 ) ;
}
}
static void F_31 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_32 ( V_90 , struct V_1 ,
V_91 . V_90 ) ;
int V_92 = F_33 ( & V_2 -> V_92 ) ;
F_4 ( L_2 , V_2 , F_34 ( V_2 -> V_10 ) ) ;
F_35 ( V_92 < 0 ) ;
if ( V_92 > 0 )
return;
switch ( V_2 -> V_10 ) {
case V_11 :
case V_93 :
if ( V_2 -> V_12 ) {
if ( V_2 -> type == V_94 )
F_11 ( V_2 ) ;
else if ( V_2 -> type == V_95 )
F_1 ( V_2 ) ;
} else if ( V_2 -> type == V_96 || V_2 -> type == V_97 ) {
F_12 ( V_2 ) ;
}
break;
case V_98 :
case V_99 :
if ( V_2 -> type == V_100 ) {
F_14 ( V_2 ) ;
} else {
T_1 V_38 = F_16 ( V_2 ) ;
if ( V_2 -> type == V_94 &&
V_2 -> V_13 == V_14 ) {
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_101 V_9 ;
V_9 . V_43 = F_8 ( V_2 -> V_43 ) ;
F_2 ( V_3 , V_102 ,
sizeof( V_9 ) , & V_9 ) ;
}
F_13 ( V_2 , V_38 ) ;
}
break;
default:
V_2 -> V_10 = V_103 ;
break;
}
}
static void F_36 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_32 ( V_90 , struct V_1 ,
V_104 . V_90 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_105 ) ;
if ( ! F_37 ( V_3 ) || ! F_37 ( V_2 ) )
return;
if ( V_2 -> V_105 != V_106 || ! ( V_2 -> V_16 & V_107 ) )
return;
if ( F_38 ( V_3 ) && F_38 ( V_2 ) ) {
struct V_108 V_9 ;
V_9 . V_43 = F_8 ( V_2 -> V_43 ) ;
V_9 . V_63 = F_8 ( 0 ) ;
V_9 . V_109 = F_8 ( 0 ) ;
V_9 . V_110 = F_8 ( 0 ) ;
F_2 ( V_3 , V_111 , sizeof( V_9 ) , & V_9 ) ;
}
if ( ! F_39 ( V_112 , & V_2 -> V_27 ) ) {
struct V_113 V_9 ;
V_9 . V_43 = F_8 ( V_2 -> V_43 ) ;
V_9 . V_114 = F_8 ( V_3 -> V_115 ) ;
V_9 . V_116 = F_8 ( V_3 -> V_117 ) ;
V_9 . V_15 = F_8 ( 4 ) ;
V_9 . V_118 = F_8 ( 1 ) ;
F_2 ( V_3 , V_119 , sizeof( V_9 ) , & V_9 ) ;
}
}
static void F_40 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_32 ( V_90 , struct V_1 ,
V_120 . V_90 ) ;
F_2 ( V_2 -> V_3 , V_121 , sizeof( V_2 -> V_18 ) ,
& V_2 -> V_18 ) ;
}
static void F_41 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_32 ( V_90 , struct V_1 ,
F_41 . V_90 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_4 ) ;
if ( F_42 ( V_122 , & V_3 -> V_123 ) ) {
T_3 V_124 = 0x00 ;
F_2 ( V_3 , V_125 , sizeof( V_124 ) ,
& V_124 ) ;
F_43 ( V_2 , V_126 ) ;
return;
}
F_1 ( V_2 ) ;
}
struct V_1 * F_44 ( struct V_5 * V_3 , int type , T_7 * V_18 ,
T_3 V_13 )
{
struct V_1 * V_2 ;
F_4 ( L_5 , V_3 -> V_127 , V_18 ) ;
V_2 = F_45 ( sizeof( * V_2 ) , V_128 ) ;
if ( ! V_2 )
return NULL ;
F_5 ( & V_2 -> V_18 , V_18 ) ;
F_5 ( & V_2 -> V_129 , & V_3 -> V_17 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> type = type ;
V_2 -> V_13 = V_13 ;
V_2 -> V_105 = V_106 ;
V_2 -> V_10 = V_130 ;
V_2 -> V_131 = V_132 ;
V_2 -> V_133 = V_3 -> V_133 ;
V_2 -> V_134 = 0xff ;
V_2 -> V_135 = 0xff ;
V_2 -> V_136 = V_137 ;
V_2 -> V_138 = V_137 ;
F_9 ( V_139 , & V_2 -> V_27 ) ;
V_2 -> V_140 = V_141 ;
if ( V_2 -> V_13 == V_14 )
V_2 -> V_12 = true ;
switch ( type ) {
case V_94 :
V_2 -> V_28 = V_3 -> V_28 & V_142 ;
break;
case V_95 :
F_46 ( V_3 , & V_2 -> V_129 , & V_2 -> V_143 ) ;
break;
case V_96 :
if ( F_28 ( V_3 ) )
V_2 -> V_28 = ( V_3 -> V_144 & V_145 ) |
( V_3 -> V_144 & V_146 ) ;
else
V_2 -> V_28 = V_3 -> V_28 & V_147 ;
break;
case V_97 :
V_2 -> V_28 = V_3 -> V_144 & ~ V_146 ;
break;
}
F_47 ( & V_2 -> V_148 ) ;
F_48 ( & V_2 -> V_149 ) ;
F_49 ( & V_2 -> V_91 , F_31 ) ;
F_49 ( & V_2 -> V_120 , F_40 ) ;
F_49 ( & V_2 -> V_104 , F_36 ) ;
F_49 ( & V_2 -> F_41 , F_41 ) ;
F_50 ( & V_2 -> V_92 , 0 ) ;
F_51 ( V_3 ) ;
F_52 ( V_3 , V_2 ) ;
if ( V_3 -> V_150 )
V_3 -> V_150 ( V_3 , V_151 ) ;
F_53 ( V_2 ) ;
return V_2 ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_6 , V_3 -> V_127 , V_2 , V_2 -> V_43 ) ;
F_54 ( & V_2 -> V_91 ) ;
F_54 ( & V_2 -> V_120 ) ;
F_54 ( & V_2 -> V_104 ) ;
if ( V_2 -> type == V_94 ) {
struct V_1 * V_87 = V_2 -> V_88 ;
if ( V_87 )
V_87 -> V_88 = NULL ;
V_3 -> V_152 += V_2 -> V_153 ;
} else if ( V_2 -> type == V_95 ) {
F_54 ( & V_2 -> F_41 ) ;
if ( V_3 -> V_154 )
V_3 -> V_155 += V_2 -> V_153 ;
else
V_3 -> V_152 += V_2 -> V_153 ;
} else {
struct V_1 * V_156 = V_2 -> V_88 ;
if ( V_156 ) {
V_156 -> V_88 = NULL ;
F_55 ( V_156 ) ;
}
}
F_56 ( V_2 ) ;
if ( V_2 -> V_157 )
F_57 ( V_2 -> V_157 ) ;
F_58 ( V_3 , V_2 ) ;
if ( V_3 -> V_150 )
V_3 -> V_150 ( V_3 , V_158 ) ;
F_59 ( & V_2 -> V_148 ) ;
F_60 ( V_2 ) ;
F_61 ( V_3 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
struct V_5 * F_63 ( T_7 * V_18 , T_7 * V_129 )
{
int V_159 = F_64 ( V_129 , V_160 ) ;
struct V_5 * V_3 = NULL , * V_161 ;
F_4 ( L_7 , V_129 , V_18 ) ;
F_65 ( & V_162 ) ;
F_66 (d, &hci_dev_list, list) {
if ( ! F_42 ( V_163 , & V_161 -> V_27 ) ||
F_42 ( V_164 , & V_161 -> V_123 ) ||
V_161 -> V_165 != V_166 )
continue;
if ( V_159 ) {
if ( ! F_64 ( & V_161 -> V_17 , V_129 ) ) {
V_3 = V_161 ; break;
}
} else {
if ( F_64 ( & V_161 -> V_17 , V_18 ) ) {
V_3 = V_161 ; break;
}
}
}
if ( V_3 )
V_3 = F_51 ( V_3 ) ;
F_67 ( & V_162 ) ;
return V_3 ;
}
void F_43 ( struct V_1 * V_2 , T_3 V_86 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_69 * V_70 ;
V_70 = F_68 ( & V_3 -> V_167 , & V_2 -> V_18 ,
V_2 -> V_72 ) ;
if ( V_70 && V_70 -> V_2 ) {
F_55 ( V_70 -> V_2 ) ;
V_70 -> V_2 = NULL ;
}
V_2 -> V_10 = V_103 ;
F_69 ( V_3 , & V_2 -> V_18 , V_2 -> type , V_2 -> V_72 ,
V_86 ) ;
F_29 ( V_2 , V_86 ) ;
F_30 ( V_2 ) ;
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
}
static void F_72 ( struct V_5 * V_3 , T_3 V_86 )
{
struct V_1 * V_2 ;
if ( V_86 == 0 )
return;
F_73 ( L_8 ,
V_86 ) ;
F_23 ( V_3 ) ;
V_2 = F_74 ( V_3 , V_95 , V_11 ) ;
if ( ! V_2 )
goto V_168;
F_43 ( V_2 , V_86 ) ;
V_168:
F_25 ( V_3 ) ;
}
static void F_75 ( struct V_169 * V_170 ,
struct V_1 * V_2 )
{
struct V_171 V_9 ;
struct V_5 * V_3 = V_2 -> V_3 ;
T_3 V_172 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
if ( F_76 ( V_170 , false , & V_172 ) )
return;
V_9 . V_173 = F_8 ( V_3 -> V_174 ) ;
V_9 . V_175 = F_8 ( V_3 -> V_176 ) ;
F_5 ( & V_9 . V_177 , & V_2 -> V_18 ) ;
V_9 . V_178 = V_2 -> V_72 ;
V_9 . V_179 = V_172 ;
V_9 . V_77 = F_8 ( V_2 -> V_180 ) ;
V_9 . V_78 = F_8 ( V_2 -> V_181 ) ;
V_9 . V_75 = F_8 ( V_2 -> V_182 ) ;
V_9 . V_76 = F_8 ( V_2 -> V_183 ) ;
V_9 . V_79 = F_8 ( 0x0000 ) ;
V_9 . V_80 = F_8 ( 0x0000 ) ;
F_77 ( V_170 , V_184 , sizeof( V_9 ) , & V_9 ) ;
V_2 -> V_10 = V_11 ;
}
static void F_78 ( struct V_169 * V_170 ,
struct V_1 * V_2 )
{
struct V_5 * V_3 = V_170 -> V_3 ;
struct V_185 V_9 ;
T_3 V_172 ;
T_3 V_124 ;
F_79 ( V_186 , & V_3 -> V_123 ) ;
if ( F_76 ( V_170 , false , & V_172 ) < 0 )
return;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . type = V_187 ;
V_9 . V_179 = V_172 ;
V_9 . V_188 = V_2 -> V_72 ;
F_5 ( & V_9 . V_189 , & V_2 -> V_18 ) ;
V_9 . V_190 = V_3 -> V_191 ;
F_77 ( V_170 , V_192 , sizeof( V_9 ) , & V_9 ) ;
V_124 = 0x01 ;
F_77 ( V_170 , V_125 , sizeof( V_124 ) , & V_124 ) ;
V_2 -> V_10 = V_11 ;
}
struct V_1 * F_80 ( struct V_5 * V_3 , T_7 * V_18 ,
T_3 V_72 , T_3 V_193 , T_4 V_194 ,
T_3 V_13 )
{
struct V_69 * V_70 ;
struct V_1 * V_2 ;
struct V_195 * V_196 ;
struct V_169 V_170 ;
int V_197 ;
V_2 = F_81 ( V_3 , V_95 , V_18 ) ;
if ( V_2 ) {
V_2 -> V_198 = V_193 ;
goto V_168;
}
V_2 = F_74 ( V_3 , V_95 , V_11 ) ;
if ( V_2 )
return F_82 ( - V_199 ) ;
V_196 = F_83 ( V_3 , V_18 , V_72 ) ;
if ( V_196 && F_64 ( & V_196 -> V_200 , V_160 ) ) {
V_18 = & V_196 -> V_200 ;
V_72 = V_201 ;
}
V_2 = F_44 ( V_3 , V_95 , V_18 , V_13 ) ;
if ( ! V_2 )
return F_82 ( - V_202 ) ;
V_2 -> V_72 = V_72 ;
V_2 -> V_193 = V_203 ;
V_2 -> V_198 = V_193 ;
V_2 -> V_194 = V_194 ;
F_84 ( & V_170 , V_3 ) ;
if ( F_42 ( V_186 , & V_3 -> V_123 ) ) {
T_3 V_124 = 0x00 ;
F_77 ( & V_170 , V_125 , sizeof( V_124 ) ,
& V_124 ) ;
}
if ( V_2 -> V_13 == V_204 ) {
if ( F_42 ( V_205 , & V_3 -> V_123 ) &&
V_3 -> V_206 == V_207 ) {
F_59 ( & V_170 . V_208 ) ;
F_30 ( V_2 ) ;
return F_82 ( - V_199 ) ;
}
F_78 ( & V_170 , V_2 ) ;
goto V_209;
}
V_70 = F_24 ( V_3 , & V_2 -> V_18 , V_2 -> V_72 ) ;
if ( V_70 ) {
V_2 -> V_180 = V_70 -> V_73 ;
V_2 -> V_181 = V_70 -> V_74 ;
V_2 -> V_182 = V_70 -> V_75 ;
V_2 -> V_183 = V_70 -> V_76 ;
} else {
V_2 -> V_180 = V_3 -> V_180 ;
V_2 -> V_181 = V_3 -> V_181 ;
V_2 -> V_182 = V_3 -> V_182 ;
V_2 -> V_183 = V_3 -> V_183 ;
}
if ( F_42 ( V_205 , & V_3 -> V_123 ) ) {
F_85 ( & V_170 ) ;
F_9 ( V_210 , & V_3 -> V_123 ) ;
}
F_75 ( & V_170 , V_2 ) ;
V_209:
V_197 = F_86 ( & V_170 , F_72 ) ;
if ( V_197 ) {
F_30 ( V_2 ) ;
return F_82 ( V_197 ) ;
}
V_168:
F_87 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_88 ( struct V_5 * V_3 , T_7 * V_18 ,
T_3 V_193 , T_3 V_131 )
{
struct V_1 * V_156 ;
if ( ! F_42 ( V_211 , & V_3 -> V_123 ) )
return F_82 ( - V_212 ) ;
V_156 = F_81 ( V_3 , V_94 , V_18 ) ;
if ( ! V_156 ) {
V_156 = F_44 ( V_3 , V_94 , V_18 , V_14 ) ;
if ( ! V_156 )
return F_82 ( - V_202 ) ;
}
F_87 ( V_156 ) ;
if ( V_156 -> V_10 == V_130 || V_156 -> V_10 == V_103 ) {
V_156 -> V_193 = V_203 ;
V_156 -> V_198 = V_193 ;
V_156 -> V_131 = V_131 ;
F_3 ( V_156 ) ;
}
return V_156 ;
}
struct V_1 * F_89 ( struct V_5 * V_3 , int type , T_7 * V_18 ,
T_2 V_56 )
{
struct V_1 * V_156 ;
struct V_1 * V_87 ;
V_156 = F_88 ( V_3 , V_18 , V_203 , V_213 ) ;
if ( F_90 ( V_156 ) )
return V_156 ;
V_87 = F_81 ( V_3 , type , V_18 ) ;
if ( ! V_87 ) {
V_87 = F_44 ( V_3 , type , V_18 , V_14 ) ;
if ( ! V_87 ) {
F_55 ( V_156 ) ;
return F_82 ( - V_202 ) ;
}
}
V_156 -> V_88 = V_87 ;
V_87 -> V_88 = V_156 ;
F_87 ( V_87 ) ;
V_87 -> V_56 = V_56 ;
if ( V_156 -> V_10 == V_99 &&
( V_87 -> V_10 == V_130 || V_87 -> V_10 == V_103 ) ) {
F_9 ( V_139 , & V_156 -> V_27 ) ;
F_91 ( V_156 , V_214 ) ;
if ( F_42 ( V_112 , & V_156 -> V_27 ) ) {
F_9 ( V_215 , & V_156 -> V_27 ) ;
return V_87 ;
}
F_27 ( V_156 , 0x00 ) ;
}
return V_87 ;
}
int F_92 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( F_42 ( V_216 , & V_2 -> V_3 -> V_27 ) ) {
if ( ! F_93 ( V_2 ) ||
! F_42 ( V_217 , & V_2 -> V_27 ) ||
V_2 -> V_135 != V_218 )
return 0 ;
}
if ( F_94 ( V_2 ) &&
! F_42 ( V_219 , & V_2 -> V_27 ) )
return 0 ;
return 1 ;
}
static int F_95 ( struct V_1 * V_2 , T_1 V_193 , T_1 V_131 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_198 > V_193 )
V_193 = V_2 -> V_198 ;
if ( V_193 > V_2 -> V_193 )
V_2 -> V_198 = V_193 ;
else if ( F_42 ( V_220 , & V_2 -> V_27 ) )
return 1 ;
V_131 |= ( V_2 -> V_131 & 0x01 ) ;
V_2 -> V_131 = V_131 ;
if ( ! F_39 ( V_221 , & V_2 -> V_27 ) ) {
struct V_222 V_9 ;
V_9 . V_43 = F_8 ( V_2 -> V_43 ) ;
F_2 ( V_2 -> V_3 , V_223 ,
sizeof( V_9 ) , & V_9 ) ;
if ( F_42 ( V_219 , & V_2 -> V_27 ) )
F_9 ( V_224 , & V_2 -> V_27 ) ;
else
F_9 ( V_225 , & V_2 -> V_27 ) ;
}
return 0 ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_39 ( V_225 , & V_2 -> V_27 ) ) {
struct V_226 V_9 ;
V_9 . V_43 = F_8 ( V_2 -> V_43 ) ;
V_9 . V_227 = 0x01 ;
F_2 ( V_2 -> V_3 , V_228 , sizeof( V_9 ) ,
& V_9 ) ;
}
}
int F_97 ( struct V_1 * V_2 , T_1 V_193 , T_1 V_131 ,
bool V_229 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_95 )
return F_98 ( V_2 , V_193 ) ;
if ( V_193 == V_230 )
return 1 ;
if ( V_193 == V_203 && ! F_94 ( V_2 ) )
return 1 ;
if ( ! F_42 ( V_220 , & V_2 -> V_27 ) )
goto V_231;
if ( V_2 -> V_135 == V_218 &&
V_193 == V_232 )
goto V_227;
if ( ( V_2 -> V_135 == V_233 ||
V_2 -> V_135 == V_218 ) &&
V_193 == V_234 )
goto V_227;
if ( ( V_2 -> V_135 == V_235 ||
V_2 -> V_135 == V_236 ) &&
( V_193 == V_237 || V_193 == V_203 ) )
goto V_227;
if ( V_2 -> V_135 == V_238 &&
( V_193 == V_237 || V_193 == V_203 ||
V_2 -> V_239 == 16 ) )
goto V_227;
V_231:
if ( F_42 ( V_225 , & V_2 -> V_27 ) )
return 0 ;
if ( V_229 )
F_9 ( V_240 , & V_2 -> V_27 ) ;
if ( ! F_95 ( V_2 , V_193 , V_131 ) )
return 0 ;
V_227:
if ( F_42 ( V_219 , & V_2 -> V_27 ) )
return 1 ;
F_96 ( V_2 ) ;
return 0 ;
}
int F_99 ( struct V_1 * V_2 , T_1 V_193 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_193 != V_234 && V_193 != V_232 )
return 1 ;
if ( V_2 -> V_193 == V_234 ||
V_2 -> V_193 == V_232 )
return 1 ;
return 0 ;
}
int F_100 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_39 ( V_221 , & V_2 -> V_27 ) ) {
struct V_241 V_9 ;
V_9 . V_43 = F_8 ( V_2 -> V_43 ) ;
F_2 ( V_2 -> V_3 , V_242 ,
sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
int F_101 ( struct V_1 * V_2 , T_1 V_13 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_13 == V_2 -> V_13 )
return 1 ;
if ( ! F_39 ( V_243 , & V_2 -> V_27 ) ) {
struct V_244 V_9 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
V_9 . V_13 = V_13 ;
F_2 ( V_2 -> V_3 , V_245 , sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
void F_91 ( struct V_1 * V_2 , T_1 V_246 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_105 ) ;
if ( V_2 -> V_105 != V_247 )
goto V_248;
if ( ! F_42 ( V_139 , & V_2 -> V_27 ) && ! V_246 )
goto V_248;
if ( ! F_39 ( V_112 , & V_2 -> V_27 ) ) {
struct V_249 V_9 ;
V_9 . V_43 = F_8 ( V_2 -> V_43 ) ;
F_2 ( V_3 , V_250 , sizeof( V_9 ) , & V_9 ) ;
}
V_248:
if ( V_3 -> V_251 > 0 )
F_102 ( V_3 -> V_252 , & V_2 -> V_104 ,
F_103 ( V_3 -> V_251 ) ) ;
}
void F_104 ( struct V_5 * V_3 )
{
struct V_253 * V_254 = & V_3 -> V_255 ;
struct V_1 * V_256 , * V_257 ;
F_4 ( L_9 , V_3 -> V_127 ) ;
F_105 (c, n, &h->list, list) {
V_256 -> V_10 = V_103 ;
F_106 ( V_256 , V_258 ) ;
F_30 ( V_256 ) ;
}
}
void F_107 ( struct V_5 * V_3 )
{
struct V_1 * V_2 ;
F_4 ( L_9 , V_3 -> V_127 ) ;
F_23 ( V_3 ) ;
V_2 = F_74 ( V_3 , V_94 , V_93 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_25 ( V_3 ) ;
}
static T_8 F_108 ( struct V_1 * V_2 )
{
T_8 V_29 = 0 ;
if ( V_2 -> V_13 == V_14 )
V_29 |= V_30 ;
if ( F_42 ( V_219 , & V_2 -> V_27 ) )
V_29 |= V_259 ;
if ( F_42 ( V_220 , & V_2 -> V_27 ) )
V_29 |= V_260 ;
if ( F_42 ( V_261 , & V_2 -> V_27 ) )
V_29 |= V_262 ;
if ( F_42 ( V_263 , & V_2 -> V_27 ) )
V_29 |= V_264 ;
return V_29 ;
}
int F_109 ( void T_9 * V_265 )
{
struct V_1 * V_256 ;
struct V_266 V_170 , * V_267 ;
struct V_268 * V_269 ;
struct V_5 * V_3 ;
int V_257 = 0 , V_270 , V_197 ;
if ( F_110 ( & V_170 , V_265 , sizeof( V_170 ) ) )
return - V_271 ;
if ( ! V_170 . V_272 || V_170 . V_272 > ( V_273 * 2 ) / sizeof( * V_269 ) )
return - V_274 ;
V_270 = sizeof( V_170 ) + V_170 . V_272 * sizeof( * V_269 ) ;
V_267 = F_111 ( V_270 , V_128 ) ;
if ( ! V_267 )
return - V_202 ;
V_3 = F_112 ( V_170 . V_275 ) ;
if ( ! V_3 ) {
F_113 ( V_267 ) ;
return - V_276 ;
}
V_269 = V_267 -> V_277 ;
F_23 ( V_3 ) ;
F_66 (c, &hdev->conn_hash.list, list) {
F_5 ( & ( V_269 + V_257 ) -> V_17 , & V_256 -> V_18 ) ;
( V_269 + V_257 ) -> V_43 = V_256 -> V_43 ;
( V_269 + V_257 ) -> type = V_256 -> type ;
( V_269 + V_257 ) -> V_12 = V_256 -> V_12 ;
( V_269 + V_257 ) -> V_10 = V_256 -> V_10 ;
( V_269 + V_257 ) -> V_29 = F_108 ( V_256 ) ;
if ( ++ V_257 >= V_170 . V_272 )
break;
}
F_25 ( V_3 ) ;
V_267 -> V_275 = V_3 -> V_278 ;
V_267 -> V_272 = V_257 ;
V_270 = sizeof( V_170 ) + V_257 * sizeof( * V_269 ) ;
F_61 ( V_3 ) ;
V_197 = F_114 ( V_265 , V_267 , V_270 ) ;
F_113 ( V_267 ) ;
return V_197 ? - V_271 : 0 ;
}
int F_115 ( struct V_5 * V_3 , void T_9 * V_265 )
{
struct V_279 V_170 ;
struct V_268 V_269 ;
struct V_1 * V_2 ;
char T_9 * V_280 = V_265 + sizeof( V_170 ) ;
if ( F_110 ( & V_170 , V_265 , sizeof( V_170 ) ) )
return - V_271 ;
F_23 ( V_3 ) ;
V_2 = F_81 ( V_3 , V_170 . type , & V_170 . V_17 ) ;
if ( V_2 ) {
F_5 ( & V_269 . V_17 , & V_2 -> V_18 ) ;
V_269 . V_43 = V_2 -> V_43 ;
V_269 . type = V_2 -> type ;
V_269 . V_12 = V_2 -> V_12 ;
V_269 . V_10 = V_2 -> V_10 ;
V_269 . V_29 = F_108 ( V_2 ) ;
}
F_25 ( V_3 ) ;
if ( ! V_2 )
return - V_281 ;
return F_114 ( V_280 , & V_269 , sizeof( V_269 ) ) ? - V_271 : 0 ;
}
int F_116 ( struct V_5 * V_3 , void T_9 * V_265 )
{
struct V_282 V_170 ;
struct V_1 * V_2 ;
if ( F_110 ( & V_170 , V_265 , sizeof( V_170 ) ) )
return - V_271 ;
F_23 ( V_3 ) ;
V_2 = F_81 ( V_3 , V_94 , & V_170 . V_17 ) ;
if ( V_2 )
V_170 . type = V_2 -> V_131 ;
F_25 ( V_3 ) ;
if ( ! V_2 )
return - V_281 ;
return F_114 ( V_265 , & V_170 , sizeof( V_170 ) ) ? - V_271 : 0 ;
}
struct V_283 * F_117 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_283 * V_284 ;
F_4 ( L_10 , V_3 -> V_127 , V_2 ) ;
V_284 = F_45 ( sizeof( * V_284 ) , V_128 ) ;
if ( ! V_284 )
return NULL ;
V_284 -> V_2 = V_2 ;
F_47 ( & V_284 -> V_148 ) ;
V_284 -> V_10 = V_99 ;
F_118 ( & V_284 -> V_285 , & V_2 -> V_149 ) ;
return V_284 ;
}
void F_119 ( struct V_283 * V_284 )
{
struct V_1 * V_2 = V_284 -> V_2 ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_11 , V_3 -> V_127 , V_2 , V_284 ) ;
F_120 ( & V_284 -> V_285 ) ;
F_121 () ;
F_55 ( V_2 ) ;
F_59 ( & V_284 -> V_148 ) ;
F_113 ( V_284 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_283 * V_284 , * V_257 ;
F_4 ( L_1 , V_2 ) ;
F_105 (chan, n, &conn->chan_list, list)
F_119 ( V_284 ) ;
}
static struct V_283 * F_122 ( struct V_1 * V_286 ,
T_2 V_43 )
{
struct V_283 * V_287 ;
F_66 (hchan, &hcon->chan_list, list) {
if ( V_287 -> V_43 == V_43 )
return V_287 ;
}
return NULL ;
}
struct V_283 * F_123 ( struct V_5 * V_3 , T_2 V_43 )
{
struct V_253 * V_254 = & V_3 -> V_255 ;
struct V_1 * V_286 ;
struct V_283 * V_287 = NULL ;
F_124 () ;
F_125 (hcon, &h->list, list) {
V_287 = F_122 ( V_286 , V_43 ) ;
if ( V_287 )
break;
}
F_126 () ;
return V_287 ;
}
