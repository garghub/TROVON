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
int F_13 ( struct V_1 * V_2 , T_1 V_38 )
{
struct V_41 V_9 ;
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_42 && V_2 -> V_13 == V_14 ) {
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_43 V_44 ;
V_44 . V_45 = F_8 ( V_2 -> V_45 ) ;
F_2 ( V_3 , V_46 , sizeof( V_44 ) ,
& V_44 ) ;
}
V_2 -> V_10 = V_47 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
V_9 . V_38 = V_38 ;
return F_2 ( V_2 -> V_3 , V_48 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_49 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_47 ;
V_9 . V_50 = F_15 ( V_2 -> V_45 ) ;
V_9 . V_38 = F_16 ( V_2 ) ;
F_2 ( V_2 -> V_3 , V_51 ,
sizeof( V_9 ) , & V_9 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_2 V_45 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_52 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_45 = F_8 ( V_45 ) ;
V_9 . V_28 = F_8 ( V_2 -> V_28 ) ;
F_2 ( V_3 , V_53 , sizeof( V_9 ) , & V_9 ) ;
}
bool F_18 ( struct V_1 * V_2 , T_2 V_45 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_54 V_9 ;
const struct V_55 * V_56 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_45 = F_8 ( V_45 ) ;
V_9 . V_57 = F_19 ( 0x00001f40 ) ;
V_9 . V_58 = F_19 ( 0x00001f40 ) ;
V_9 . V_59 = F_8 ( V_2 -> V_60 ) ;
switch ( V_2 -> V_60 & V_61 ) {
case V_62 :
if ( V_2 -> V_15 > F_20 ( V_63 ) )
return false ;
V_56 = & V_63 [ V_2 -> V_15 - 1 ] ;
break;
case V_64 :
if ( F_21 ( V_2 -> V_65 ) ) {
if ( V_2 -> V_15 > F_20 ( V_66 ) )
return false ;
V_56 = & V_66 [ V_2 -> V_15 - 1 ] ;
} else {
if ( V_2 -> V_15 > F_20 ( V_67 ) )
return false ;
V_56 = & V_67 [ V_2 -> V_15 - 1 ] ;
}
break;
default:
return false ;
}
V_9 . V_68 = V_56 -> V_68 ;
V_9 . V_28 = F_22 ( V_56 -> V_28 ) ;
V_9 . V_69 = F_22 ( V_56 -> V_69 ) ;
if ( F_2 ( V_3 , V_70 , sizeof( V_9 ) , & V_9 ) < 0 )
return false ;
return true ;
}
T_3 F_23 ( struct V_1 * V_2 , T_4 V_71 , T_4 V_72 , T_4 V_73 ,
T_4 V_74 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_75 * V_76 ;
struct V_77 V_9 ;
F_24 ( V_3 ) ;
V_76 = F_25 ( V_3 , & V_2 -> V_18 , V_2 -> V_78 ) ;
if ( V_76 ) {
V_76 -> V_79 = V_71 ;
V_76 -> V_80 = V_72 ;
V_76 -> V_81 = V_73 ;
V_76 -> V_82 = V_74 ;
}
F_26 ( V_3 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
V_9 . V_83 = F_8 ( V_71 ) ;
V_9 . V_84 = F_8 ( V_72 ) ;
V_9 . V_81 = F_8 ( V_73 ) ;
V_9 . V_82 = F_8 ( V_74 ) ;
V_9 . V_85 = F_8 ( 0x0000 ) ;
V_9 . V_86 = F_8 ( 0x0000 ) ;
F_2 ( V_3 , V_87 , sizeof( V_9 ) , & V_9 ) ;
if ( V_76 )
return 0x01 ;
return 0x00 ;
}
void F_27 ( struct V_1 * V_2 , T_5 V_88 , T_6 rand ,
T_1 V_89 [ 16 ] , T_1 V_90 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_91 V_9 ;
F_4 ( L_1 , V_2 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
V_9 . rand = rand ;
V_9 . V_88 = V_88 ;
memcpy ( V_9 . V_89 , V_89 , V_90 ) ;
F_2 ( V_3 , V_92 , sizeof( V_9 ) , & V_9 ) ;
}
void F_28 ( struct V_1 * V_2 , T_1 V_93 )
{
struct V_1 * V_94 = V_2 -> V_65 ;
if ( ! V_94 )
return;
F_4 ( L_1 , V_2 ) ;
if ( ! V_93 ) {
if ( F_21 ( V_2 -> V_3 ) )
F_18 ( V_94 , V_2 -> V_45 ) ;
else
F_17 ( V_94 , V_2 -> V_45 ) ;
} else {
F_29 ( V_94 , V_93 ) ;
F_30 ( V_94 ) ;
}
}
static void F_31 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_32 ( V_96 , struct V_1 ,
V_97 . V_96 ) ;
int V_98 = F_33 ( & V_2 -> V_98 ) ;
F_4 ( L_2 , V_2 , F_34 ( V_2 -> V_10 ) ) ;
F_35 ( V_98 < 0 ) ;
if ( V_98 > 0 )
return;
switch ( V_2 -> V_10 ) {
case V_11 :
case V_99 :
if ( V_2 -> V_12 ) {
if ( V_2 -> type == V_42 )
F_11 ( V_2 ) ;
else if ( V_2 -> type == V_100 )
F_1 ( V_2 ) ;
} else if ( V_2 -> type == V_101 || V_2 -> type == V_102 ) {
F_12 ( V_2 ) ;
}
break;
case V_103 :
case V_104 :
if ( V_2 -> type == V_105 ) {
F_14 ( V_2 ) ;
} else {
T_1 V_38 = F_16 ( V_2 ) ;
F_13 ( V_2 , V_38 ) ;
}
break;
default:
V_2 -> V_10 = V_106 ;
break;
}
}
static void F_36 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_32 ( V_96 , struct V_1 ,
V_107 . V_96 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_108 ) ;
if ( ! F_37 ( V_3 ) || ! F_37 ( V_2 ) )
return;
if ( V_2 -> V_108 != V_109 || ! ( V_2 -> V_16 & V_110 ) )
return;
if ( F_38 ( V_3 ) && F_38 ( V_2 ) ) {
struct V_111 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
V_9 . V_69 = F_8 ( 0 ) ;
V_9 . V_112 = F_8 ( 0 ) ;
V_9 . V_113 = F_8 ( 0 ) ;
F_2 ( V_3 , V_114 , sizeof( V_9 ) , & V_9 ) ;
}
if ( ! F_39 ( V_115 , & V_2 -> V_27 ) ) {
struct V_116 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
V_9 . V_117 = F_8 ( V_3 -> V_118 ) ;
V_9 . V_119 = F_8 ( V_3 -> V_120 ) ;
V_9 . V_15 = F_8 ( 4 ) ;
V_9 . V_121 = F_8 ( 1 ) ;
F_2 ( V_3 , V_122 , sizeof( V_9 ) , & V_9 ) ;
}
}
static void F_40 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_32 ( V_96 , struct V_1 ,
V_123 . V_96 ) ;
F_2 ( V_2 -> V_3 , V_124 , sizeof( V_2 -> V_18 ) ,
& V_2 -> V_18 ) ;
}
static void F_41 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_32 ( V_96 , struct V_1 ,
F_41 . V_96 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_4 ) ;
if ( V_2 -> V_13 == V_125 ) {
T_3 V_126 = 0x00 ;
F_2 ( V_3 , V_127 , sizeof( V_126 ) ,
& V_126 ) ;
F_42 ( V_2 , V_128 ) ;
return;
}
F_1 ( V_2 ) ;
}
struct V_1 * F_43 ( struct V_5 * V_3 , int type , T_7 * V_18 ,
T_3 V_13 )
{
struct V_1 * V_2 ;
F_4 ( L_5 , V_3 -> V_129 , V_18 ) ;
V_2 = F_44 ( sizeof( * V_2 ) , V_130 ) ;
if ( ! V_2 )
return NULL ;
F_5 ( & V_2 -> V_18 , V_18 ) ;
F_5 ( & V_2 -> V_131 , & V_3 -> V_17 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> type = type ;
V_2 -> V_13 = V_13 ;
V_2 -> V_108 = V_109 ;
V_2 -> V_10 = V_132 ;
V_2 -> V_133 = V_134 ;
V_2 -> V_135 = V_3 -> V_135 ;
V_2 -> V_136 = 0xff ;
V_2 -> V_137 = 0xff ;
V_2 -> V_138 = V_139 ;
V_2 -> V_140 = V_141 ;
V_2 -> V_142 = V_141 ;
F_9 ( V_143 , & V_2 -> V_27 ) ;
V_2 -> V_144 = V_145 ;
if ( V_2 -> V_13 == V_14 )
V_2 -> V_12 = true ;
switch ( type ) {
case V_42 :
V_2 -> V_28 = V_3 -> V_28 & V_146 ;
break;
case V_100 :
F_45 ( V_3 , & V_2 -> V_131 , & V_2 -> V_147 ) ;
break;
case V_101 :
if ( F_21 ( V_3 ) )
V_2 -> V_28 = ( V_3 -> V_148 & V_149 ) |
( V_3 -> V_148 & V_150 ) ;
else
V_2 -> V_28 = V_3 -> V_28 & V_151 ;
break;
case V_102 :
V_2 -> V_28 = V_3 -> V_148 & ~ V_150 ;
break;
}
F_46 ( & V_2 -> V_152 ) ;
F_47 ( & V_2 -> V_153 ) ;
F_48 ( & V_2 -> V_97 , F_31 ) ;
F_48 ( & V_2 -> V_123 , F_40 ) ;
F_48 ( & V_2 -> V_107 , F_36 ) ;
F_48 ( & V_2 -> F_41 , F_41 ) ;
F_49 ( & V_2 -> V_98 , 0 ) ;
F_50 ( V_3 ) ;
F_51 ( V_3 , V_2 ) ;
if ( V_3 -> V_154 )
V_3 -> V_154 ( V_3 , V_155 ) ;
F_52 ( V_2 ) ;
return V_2 ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_6 , V_3 -> V_129 , V_2 , V_2 -> V_45 ) ;
F_53 ( & V_2 -> V_97 ) ;
F_53 ( & V_2 -> V_123 ) ;
F_53 ( & V_2 -> V_107 ) ;
if ( V_2 -> type == V_42 ) {
struct V_1 * V_94 = V_2 -> V_65 ;
if ( V_94 )
V_94 -> V_65 = NULL ;
V_3 -> V_156 += V_2 -> V_157 ;
} else if ( V_2 -> type == V_100 ) {
F_54 ( & V_2 -> F_41 ) ;
if ( V_3 -> V_158 )
V_3 -> V_159 += V_2 -> V_157 ;
else
V_3 -> V_156 += V_2 -> V_157 ;
} else {
struct V_1 * V_160 = V_2 -> V_65 ;
if ( V_160 ) {
V_160 -> V_65 = NULL ;
F_55 ( V_160 ) ;
}
}
F_56 ( V_2 ) ;
if ( V_2 -> V_161 )
F_57 ( V_2 -> V_161 ) ;
F_58 ( V_3 , V_2 ) ;
if ( V_3 -> V_154 )
V_3 -> V_154 ( V_3 , V_162 ) ;
F_59 ( & V_2 -> V_152 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 -> V_163 ) ;
if ( F_62 ( V_164 , & V_2 -> V_27 ) )
F_63 ( V_2 -> V_3 , & V_2 -> V_18 , V_2 -> V_78 ) ;
F_64 ( V_3 ) ;
F_65 ( V_2 ) ;
return 0 ;
}
struct V_5 * F_66 ( T_7 * V_18 , T_7 * V_131 )
{
int V_165 = F_67 ( V_131 , V_166 ) ;
struct V_5 * V_3 = NULL , * V_167 ;
F_4 ( L_7 , V_131 , V_18 ) ;
F_68 ( & V_168 ) ;
F_69 (d, &hci_dev_list, list) {
if ( ! F_62 ( V_169 , & V_167 -> V_27 ) ||
F_70 ( V_167 , V_170 ) ||
V_167 -> V_171 != V_172 )
continue;
if ( V_165 ) {
if ( ! F_67 ( & V_167 -> V_17 , V_131 ) ) {
V_3 = V_167 ; break;
}
} else {
if ( F_67 ( & V_167 -> V_17 , V_18 ) ) {
V_3 = V_167 ; break;
}
}
}
if ( V_3 )
V_3 = F_50 ( V_3 ) ;
F_71 ( & V_168 ) ;
return V_3 ;
}
void F_42 ( struct V_1 * V_2 , T_3 V_93 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_75 * V_76 ;
V_76 = F_72 ( & V_3 -> V_173 , & V_2 -> V_18 ,
V_2 -> V_78 ) ;
if ( V_76 && V_76 -> V_2 ) {
F_55 ( V_76 -> V_2 ) ;
F_65 ( V_76 -> V_2 ) ;
V_76 -> V_2 = NULL ;
}
V_2 -> V_10 = V_106 ;
F_73 ( V_3 , & V_2 -> V_18 , V_2 -> type , V_2 -> V_78 ,
V_93 ) ;
F_29 ( V_2 , V_93 ) ;
F_30 ( V_2 ) ;
F_74 ( V_3 ) ;
F_75 ( V_3 ) ;
}
static void F_76 ( struct V_5 * V_3 , T_3 V_93 , T_4 V_174 )
{
struct V_1 * V_2 ;
if ( V_93 == 0 )
return;
F_77 ( L_8 ,
V_93 ) ;
F_24 ( V_3 ) ;
V_2 = F_78 ( V_3 , V_100 , V_11 ) ;
if ( ! V_2 )
goto V_175;
F_42 ( V_2 , V_93 ) ;
V_175:
F_26 ( V_3 ) ;
}
static void F_79 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
struct V_178 V_9 ;
struct V_5 * V_3 = V_2 -> V_3 ;
T_3 V_179 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
if ( F_80 ( V_177 , false , & V_179 ) )
return;
V_9 . V_180 = F_8 ( V_3 -> V_181 ) ;
V_9 . V_182 = F_8 ( V_3 -> V_183 ) ;
F_5 ( & V_9 . V_184 , & V_2 -> V_18 ) ;
V_9 . V_185 = V_2 -> V_78 ;
V_9 . V_186 = V_179 ;
V_9 . V_83 = F_8 ( V_2 -> V_187 ) ;
V_9 . V_84 = F_8 ( V_2 -> V_188 ) ;
V_9 . V_81 = F_8 ( V_2 -> V_189 ) ;
V_9 . V_82 = F_8 ( V_2 -> V_190 ) ;
V_9 . V_85 = F_8 ( 0x0000 ) ;
V_9 . V_86 = F_8 ( 0x0000 ) ;
F_81 ( V_177 , V_191 , sizeof( V_9 ) , & V_9 ) ;
V_2 -> V_10 = V_11 ;
}
static void F_82 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
struct V_5 * V_3 = V_177 -> V_3 ;
struct V_192 V_9 ;
T_3 V_179 ;
T_3 V_126 ;
F_83 ( V_3 , V_193 ) ;
if ( F_80 ( V_177 , false , & V_179 ) < 0 )
return;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . type = V_194 ;
V_9 . V_186 = V_179 ;
V_9 . V_195 = V_2 -> V_78 ;
F_5 ( & V_9 . V_196 , & V_2 -> V_18 ) ;
V_9 . V_197 = V_3 -> V_198 ;
F_81 ( V_177 , V_199 , sizeof( V_9 ) , & V_9 ) ;
V_126 = 0x01 ;
F_81 ( V_177 , V_127 , sizeof( V_126 ) , & V_126 ) ;
V_2 -> V_10 = V_11 ;
}
struct V_1 * F_84 ( struct V_5 * V_3 , T_7 * V_18 ,
T_3 V_78 , T_3 V_200 , T_4 V_201 ,
T_3 V_13 )
{
struct V_75 * V_76 ;
struct V_1 * V_2 ;
struct V_202 * V_203 ;
struct V_176 V_177 ;
int V_204 ;
if ( ! F_70 ( V_3 , V_205 ) ) {
if ( F_85 ( V_3 ) )
return F_86 ( - V_206 ) ;
return F_86 ( - V_207 ) ;
}
V_2 = F_87 ( V_3 , V_100 , V_18 ) ;
if ( V_2 ) {
V_2 -> V_208 = V_200 ;
goto V_175;
}
V_2 = F_78 ( V_3 , V_100 , V_11 ) ;
if ( V_2 )
return F_86 ( - V_209 ) ;
V_203 = F_88 ( V_3 , V_18 , V_78 ) ;
if ( V_203 && F_67 ( & V_203 -> V_210 , V_166 ) ) {
V_18 = & V_203 -> V_210 ;
V_78 = V_211 ;
}
V_2 = F_43 ( V_3 , V_100 , V_18 , V_13 ) ;
if ( ! V_2 )
return F_86 ( - V_212 ) ;
V_2 -> V_78 = V_78 ;
V_2 -> V_200 = V_213 ;
V_2 -> V_208 = V_200 ;
V_2 -> V_201 = V_201 ;
F_89 ( & V_177 , V_3 ) ;
if ( F_70 ( V_3 , V_193 ) ) {
T_3 V_126 = 0x00 ;
F_81 ( & V_177 , V_127 , sizeof( V_126 ) ,
& V_126 ) ;
}
if ( V_2 -> V_13 == V_125 ) {
if ( F_70 ( V_3 , V_214 ) &&
V_3 -> V_215 == V_216 ) {
F_59 ( & V_177 . V_217 ) ;
F_30 ( V_2 ) ;
return F_86 ( - V_209 ) ;
}
F_82 ( & V_177 , V_2 ) ;
goto V_218;
}
V_76 = F_25 ( V_3 , & V_2 -> V_18 , V_2 -> V_78 ) ;
if ( V_76 ) {
V_2 -> V_187 = V_76 -> V_79 ;
V_2 -> V_188 = V_76 -> V_80 ;
V_2 -> V_189 = V_76 -> V_81 ;
V_2 -> V_190 = V_76 -> V_82 ;
} else {
V_2 -> V_187 = V_3 -> V_187 ;
V_2 -> V_188 = V_3 -> V_188 ;
V_2 -> V_189 = V_3 -> V_189 ;
V_2 -> V_190 = V_3 -> V_190 ;
}
if ( F_70 ( V_3 , V_214 ) ) {
F_90 ( & V_177 ) ;
F_91 ( V_3 , V_219 ) ;
}
F_79 ( & V_177 , V_2 ) ;
V_218:
V_204 = F_92 ( & V_177 , F_76 ) ;
if ( V_204 ) {
F_30 ( V_2 ) ;
return F_86 ( V_204 ) ;
}
V_175:
F_93 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_94 ( struct V_5 * V_3 , T_7 * V_18 ,
T_3 V_200 , T_3 V_133 )
{
struct V_1 * V_160 ;
if ( ! F_70 ( V_3 , V_220 ) ) {
if ( F_95 ( V_3 ) )
return F_86 ( - V_206 ) ;
return F_86 ( - V_207 ) ;
}
V_160 = F_87 ( V_3 , V_42 , V_18 ) ;
if ( ! V_160 ) {
V_160 = F_43 ( V_3 , V_42 , V_18 , V_14 ) ;
if ( ! V_160 )
return F_86 ( - V_212 ) ;
}
F_93 ( V_160 ) ;
if ( V_160 -> V_10 == V_132 || V_160 -> V_10 == V_106 ) {
V_160 -> V_200 = V_213 ;
V_160 -> V_208 = V_200 ;
V_160 -> V_133 = V_133 ;
F_3 ( V_160 ) ;
}
return V_160 ;
}
struct V_1 * F_96 ( struct V_5 * V_3 , int type , T_7 * V_18 ,
T_2 V_60 )
{
struct V_1 * V_160 ;
struct V_1 * V_94 ;
V_160 = F_94 ( V_3 , V_18 , V_213 , V_221 ) ;
if ( F_97 ( V_160 ) )
return V_160 ;
V_94 = F_87 ( V_3 , type , V_18 ) ;
if ( ! V_94 ) {
V_94 = F_43 ( V_3 , type , V_18 , V_14 ) ;
if ( ! V_94 ) {
F_55 ( V_160 ) ;
return F_86 ( - V_212 ) ;
}
}
V_160 -> V_65 = V_94 ;
V_94 -> V_65 = V_160 ;
F_93 ( V_94 ) ;
V_94 -> V_60 = V_60 ;
if ( V_160 -> V_10 == V_104 &&
( V_94 -> V_10 == V_132 || V_94 -> V_10 == V_106 ) ) {
F_9 ( V_143 , & V_160 -> V_27 ) ;
F_98 ( V_160 , V_222 ) ;
if ( F_62 ( V_115 , & V_160 -> V_27 ) ) {
F_9 ( V_223 , & V_160 -> V_27 ) ;
return V_94 ;
}
F_28 ( V_160 , 0x00 ) ;
}
return V_94 ;
}
int F_99 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( F_70 ( V_2 -> V_3 , V_224 ) ) {
if ( ! F_100 ( V_2 ) ||
! F_62 ( V_225 , & V_2 -> V_27 ) ||
V_2 -> V_137 != V_226 )
return 0 ;
}
if ( F_101 ( V_2 ) &&
! F_62 ( V_227 , & V_2 -> V_27 ) )
return 0 ;
return 1 ;
}
static int F_102 ( struct V_1 * V_2 , T_1 V_200 , T_1 V_133 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_208 > V_200 )
V_200 = V_2 -> V_208 ;
if ( V_200 > V_2 -> V_200 )
V_2 -> V_208 = V_200 ;
else if ( F_62 ( V_228 , & V_2 -> V_27 ) )
return 1 ;
V_133 |= ( V_2 -> V_133 & 0x01 ) ;
V_2 -> V_133 = V_133 ;
if ( ! F_39 ( V_229 , & V_2 -> V_27 ) ) {
struct V_230 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
F_2 ( V_2 -> V_3 , V_231 ,
sizeof( V_9 ) , & V_9 ) ;
if ( F_62 ( V_227 , & V_2 -> V_27 ) )
F_9 ( V_232 , & V_2 -> V_27 ) ;
else
F_9 ( V_233 , & V_2 -> V_27 ) ;
}
return 0 ;
}
static void F_103 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_39 ( V_233 , & V_2 -> V_27 ) ) {
struct V_234 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
V_9 . V_235 = 0x01 ;
F_2 ( V_2 -> V_3 , V_236 , sizeof( V_9 ) ,
& V_9 ) ;
}
}
int F_104 ( struct V_1 * V_2 , T_1 V_200 , T_1 V_133 ,
bool V_237 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_100 )
return F_105 ( V_2 , V_200 ) ;
if ( V_200 == V_238 )
return 1 ;
if ( V_200 == V_213 && ! F_101 ( V_2 ) )
return 1 ;
if ( ! F_62 ( V_228 , & V_2 -> V_27 ) )
goto V_239;
if ( V_2 -> V_137 == V_226 &&
V_200 == V_240 )
goto V_235;
if ( ( V_2 -> V_137 == V_241 ||
V_2 -> V_137 == V_226 ) &&
V_200 == V_242 )
goto V_235;
if ( ( V_2 -> V_137 == V_243 ||
V_2 -> V_137 == V_244 ) &&
( V_200 == V_245 || V_200 == V_213 ) )
goto V_235;
if ( V_2 -> V_137 == V_246 &&
( V_200 == V_245 || V_200 == V_213 ||
V_2 -> V_247 == 16 ) )
goto V_235;
V_239:
if ( F_62 ( V_233 , & V_2 -> V_27 ) )
return 0 ;
if ( V_237 )
F_9 ( V_248 , & V_2 -> V_27 ) ;
if ( ! F_102 ( V_2 , V_200 , V_133 ) )
return 0 ;
V_235:
if ( F_62 ( V_227 , & V_2 -> V_27 ) )
return 1 ;
F_103 ( V_2 ) ;
return 0 ;
}
int F_106 ( struct V_1 * V_2 , T_1 V_200 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_200 != V_242 && V_200 != V_240 )
return 1 ;
if ( V_2 -> V_200 == V_242 ||
V_2 -> V_200 == V_240 )
return 1 ;
return 0 ;
}
int F_107 ( struct V_1 * V_2 , T_1 V_13 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_13 == V_2 -> V_13 )
return 1 ;
if ( ! F_39 ( V_249 , & V_2 -> V_27 ) ) {
struct V_250 V_9 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
V_9 . V_13 = V_13 ;
F_2 ( V_2 -> V_3 , V_251 , sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
void F_98 ( struct V_1 * V_2 , T_1 V_252 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_108 ) ;
if ( V_2 -> V_108 != V_253 )
goto V_254;
if ( ! F_62 ( V_143 , & V_2 -> V_27 ) && ! V_252 )
goto V_254;
if ( ! F_39 ( V_115 , & V_2 -> V_27 ) ) {
struct V_255 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
F_2 ( V_3 , V_256 , sizeof( V_9 ) , & V_9 ) ;
}
V_254:
if ( V_3 -> V_257 > 0 )
F_108 ( V_3 -> V_258 , & V_2 -> V_107 ,
F_109 ( V_3 -> V_257 ) ) ;
}
void F_110 ( struct V_5 * V_3 )
{
struct V_259 * V_260 = & V_3 -> V_261 ;
struct V_1 * V_262 , * V_263 ;
F_4 ( L_9 , V_3 -> V_129 ) ;
F_111 (c, n, &h->list, list) {
V_262 -> V_10 = V_106 ;
F_112 ( V_262 , V_264 ) ;
F_30 ( V_262 ) ;
}
}
void F_113 ( struct V_5 * V_3 )
{
struct V_1 * V_2 ;
F_4 ( L_9 , V_3 -> V_129 ) ;
F_24 ( V_3 ) ;
V_2 = F_78 ( V_3 , V_42 , V_99 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_26 ( V_3 ) ;
}
static T_8 F_114 ( struct V_1 * V_2 )
{
T_8 V_29 = 0 ;
if ( V_2 -> V_13 == V_14 )
V_29 |= V_30 ;
if ( F_62 ( V_227 , & V_2 -> V_27 ) )
V_29 |= V_265 ;
if ( F_62 ( V_228 , & V_2 -> V_27 ) )
V_29 |= V_266 ;
if ( F_62 ( V_267 , & V_2 -> V_27 ) )
V_29 |= V_268 ;
if ( F_62 ( V_269 , & V_2 -> V_27 ) )
V_29 |= V_270 ;
return V_29 ;
}
int F_115 ( void T_9 * V_271 )
{
struct V_1 * V_262 ;
struct V_272 V_177 , * V_273 ;
struct V_274 * V_275 ;
struct V_5 * V_3 ;
int V_263 = 0 , V_276 , V_204 ;
if ( F_116 ( & V_177 , V_271 , sizeof( V_177 ) ) )
return - V_277 ;
if ( ! V_177 . V_278 || V_177 . V_278 > ( V_279 * 2 ) / sizeof( * V_275 ) )
return - V_280 ;
V_276 = sizeof( V_177 ) + V_177 . V_278 * sizeof( * V_275 ) ;
V_273 = F_117 ( V_276 , V_130 ) ;
if ( ! V_273 )
return - V_212 ;
V_3 = F_118 ( V_177 . V_281 ) ;
if ( ! V_3 ) {
F_119 ( V_273 ) ;
return - V_282 ;
}
V_275 = V_273 -> V_283 ;
F_24 ( V_3 ) ;
F_69 (c, &hdev->conn_hash.list, list) {
F_5 ( & ( V_275 + V_263 ) -> V_17 , & V_262 -> V_18 ) ;
( V_275 + V_263 ) -> V_45 = V_262 -> V_45 ;
( V_275 + V_263 ) -> type = V_262 -> type ;
( V_275 + V_263 ) -> V_12 = V_262 -> V_12 ;
( V_275 + V_263 ) -> V_10 = V_262 -> V_10 ;
( V_275 + V_263 ) -> V_29 = F_114 ( V_262 ) ;
if ( ++ V_263 >= V_177 . V_278 )
break;
}
F_26 ( V_3 ) ;
V_273 -> V_281 = V_3 -> V_284 ;
V_273 -> V_278 = V_263 ;
V_276 = sizeof( V_177 ) + V_263 * sizeof( * V_275 ) ;
F_64 ( V_3 ) ;
V_204 = F_120 ( V_271 , V_273 , V_276 ) ;
F_119 ( V_273 ) ;
return V_204 ? - V_277 : 0 ;
}
int F_121 ( struct V_5 * V_3 , void T_9 * V_271 )
{
struct V_285 V_177 ;
struct V_274 V_275 ;
struct V_1 * V_2 ;
char T_9 * V_286 = V_271 + sizeof( V_177 ) ;
if ( F_116 ( & V_177 , V_271 , sizeof( V_177 ) ) )
return - V_277 ;
F_24 ( V_3 ) ;
V_2 = F_87 ( V_3 , V_177 . type , & V_177 . V_17 ) ;
if ( V_2 ) {
F_5 ( & V_275 . V_17 , & V_2 -> V_18 ) ;
V_275 . V_45 = V_2 -> V_45 ;
V_275 . type = V_2 -> type ;
V_275 . V_12 = V_2 -> V_12 ;
V_275 . V_10 = V_2 -> V_10 ;
V_275 . V_29 = F_114 ( V_2 ) ;
}
F_26 ( V_3 ) ;
if ( ! V_2 )
return - V_287 ;
return F_120 ( V_286 , & V_275 , sizeof( V_275 ) ) ? - V_277 : 0 ;
}
int F_122 ( struct V_5 * V_3 , void T_9 * V_271 )
{
struct V_288 V_177 ;
struct V_1 * V_2 ;
if ( F_116 ( & V_177 , V_271 , sizeof( V_177 ) ) )
return - V_277 ;
F_24 ( V_3 ) ;
V_2 = F_87 ( V_3 , V_42 , & V_177 . V_17 ) ;
if ( V_2 )
V_177 . type = V_2 -> V_133 ;
F_26 ( V_3 ) ;
if ( ! V_2 )
return - V_287 ;
return F_120 ( V_271 , & V_177 , sizeof( V_177 ) ) ? - V_277 : 0 ;
}
struct V_289 * F_123 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_289 * V_290 ;
F_4 ( L_10 , V_3 -> V_129 , V_2 ) ;
if ( F_62 ( V_291 , & V_2 -> V_27 ) ) {
F_4 ( L_11 ) ;
return NULL ;
}
V_290 = F_44 ( sizeof( * V_290 ) , V_130 ) ;
if ( ! V_290 )
return NULL ;
V_290 -> V_2 = F_124 ( V_2 ) ;
F_46 ( & V_290 -> V_152 ) ;
V_290 -> V_10 = V_104 ;
F_125 ( & V_290 -> V_292 , & V_2 -> V_153 ) ;
return V_290 ;
}
void F_126 ( struct V_289 * V_290 )
{
struct V_1 * V_2 = V_290 -> V_2 ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_12 , V_3 -> V_129 , V_2 , V_290 ) ;
F_127 ( & V_290 -> V_292 ) ;
F_128 () ;
F_9 ( V_291 , & V_2 -> V_27 ) ;
F_65 ( V_2 ) ;
F_59 ( & V_290 -> V_152 ) ;
F_119 ( V_290 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_289 * V_290 , * V_263 ;
F_4 ( L_1 , V_2 ) ;
F_111 (chan, n, &conn->chan_list, list)
F_126 ( V_290 ) ;
}
static struct V_289 * F_129 ( struct V_1 * V_293 ,
T_2 V_45 )
{
struct V_289 * V_294 ;
F_69 (hchan, &hcon->chan_list, list) {
if ( V_294 -> V_45 == V_45 )
return V_294 ;
}
return NULL ;
}
struct V_289 * F_130 ( struct V_5 * V_3 , T_2 V_45 )
{
struct V_259 * V_260 = & V_3 -> V_261 ;
struct V_1 * V_293 ;
struct V_289 * V_294 = NULL ;
F_131 () ;
F_132 (hcon, &h->list, list) {
V_294 = F_129 ( V_293 , V_45 ) ;
if ( V_294 )
break;
}
F_133 () ;
return V_294 ;
}
