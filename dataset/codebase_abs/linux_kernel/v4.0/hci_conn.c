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
T_1 V_89 [ 16 ] )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_90 V_9 ;
F_4 ( L_1 , V_2 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
V_9 . rand = rand ;
V_9 . V_88 = V_88 ;
memcpy ( V_9 . V_89 , V_89 , sizeof( V_9 . V_89 ) ) ;
F_2 ( V_3 , V_91 , sizeof( V_9 ) , & V_9 ) ;
}
void F_28 ( struct V_1 * V_2 , T_1 V_92 )
{
struct V_1 * V_93 = V_2 -> V_65 ;
if ( ! V_93 )
return;
F_4 ( L_1 , V_2 ) ;
if ( ! V_92 ) {
if ( F_21 ( V_2 -> V_3 ) )
F_18 ( V_93 , V_2 -> V_45 ) ;
else
F_17 ( V_93 , V_2 -> V_45 ) ;
} else {
F_29 ( V_93 , V_92 ) ;
F_30 ( V_93 ) ;
}
}
static void F_31 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 , struct V_1 ,
V_96 . V_95 ) ;
int V_97 = F_33 ( & V_2 -> V_97 ) ;
F_4 ( L_2 , V_2 , F_34 ( V_2 -> V_10 ) ) ;
F_35 ( V_97 < 0 ) ;
if ( V_97 > 0 )
return;
switch ( V_2 -> V_10 ) {
case V_11 :
case V_98 :
if ( V_2 -> V_12 ) {
if ( V_2 -> type == V_42 )
F_11 ( V_2 ) ;
else if ( V_2 -> type == V_99 )
F_1 ( V_2 ) ;
} else if ( V_2 -> type == V_100 || V_2 -> type == V_101 ) {
F_12 ( V_2 ) ;
}
break;
case V_102 :
case V_103 :
if ( V_2 -> type == V_104 ) {
F_14 ( V_2 ) ;
} else {
T_1 V_38 = F_16 ( V_2 ) ;
F_13 ( V_2 , V_38 ) ;
}
break;
default:
V_2 -> V_10 = V_105 ;
break;
}
}
static void F_36 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 , struct V_1 ,
V_106 . V_95 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_107 ) ;
if ( ! F_37 ( V_3 ) || ! F_37 ( V_2 ) )
return;
if ( V_2 -> V_107 != V_108 || ! ( V_2 -> V_16 & V_109 ) )
return;
if ( F_38 ( V_3 ) && F_38 ( V_2 ) ) {
struct V_110 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
V_9 . V_69 = F_8 ( 0 ) ;
V_9 . V_111 = F_8 ( 0 ) ;
V_9 . V_112 = F_8 ( 0 ) ;
F_2 ( V_3 , V_113 , sizeof( V_9 ) , & V_9 ) ;
}
if ( ! F_39 ( V_114 , & V_2 -> V_27 ) ) {
struct V_115 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
V_9 . V_116 = F_8 ( V_3 -> V_117 ) ;
V_9 . V_118 = F_8 ( V_3 -> V_119 ) ;
V_9 . V_15 = F_8 ( 4 ) ;
V_9 . V_120 = F_8 ( 1 ) ;
F_2 ( V_3 , V_121 , sizeof( V_9 ) , & V_9 ) ;
}
}
static void F_40 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 , struct V_1 ,
V_122 . V_95 ) ;
F_2 ( V_2 -> V_3 , V_123 , sizeof( V_2 -> V_18 ) ,
& V_2 -> V_18 ) ;
}
static void F_41 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 , struct V_1 ,
F_41 . V_95 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_4 ) ;
if ( V_2 -> V_13 == V_124 ) {
T_3 V_125 = 0x00 ;
F_2 ( V_3 , V_126 , sizeof( V_125 ) ,
& V_125 ) ;
F_42 ( V_2 , V_127 ) ;
return;
}
F_1 ( V_2 ) ;
}
struct V_1 * F_43 ( struct V_5 * V_3 , int type , T_7 * V_18 ,
T_3 V_13 )
{
struct V_1 * V_2 ;
F_4 ( L_5 , V_3 -> V_128 , V_18 ) ;
V_2 = F_44 ( sizeof( * V_2 ) , V_129 ) ;
if ( ! V_2 )
return NULL ;
F_5 ( & V_2 -> V_18 , V_18 ) ;
F_5 ( & V_2 -> V_130 , & V_3 -> V_17 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> type = type ;
V_2 -> V_13 = V_13 ;
V_2 -> V_107 = V_108 ;
V_2 -> V_10 = V_131 ;
V_2 -> V_132 = V_133 ;
V_2 -> V_134 = V_3 -> V_134 ;
V_2 -> V_135 = 0xff ;
V_2 -> V_136 = 0xff ;
V_2 -> V_137 = V_138 ;
V_2 -> V_139 = V_140 ;
V_2 -> V_141 = V_140 ;
F_9 ( V_142 , & V_2 -> V_27 ) ;
V_2 -> V_143 = V_144 ;
if ( V_2 -> V_13 == V_14 )
V_2 -> V_12 = true ;
switch ( type ) {
case V_42 :
V_2 -> V_28 = V_3 -> V_28 & V_145 ;
break;
case V_99 :
F_45 ( V_3 , & V_2 -> V_130 , & V_2 -> V_146 ) ;
break;
case V_100 :
if ( F_21 ( V_3 ) )
V_2 -> V_28 = ( V_3 -> V_147 & V_148 ) |
( V_3 -> V_147 & V_149 ) ;
else
V_2 -> V_28 = V_3 -> V_28 & V_150 ;
break;
case V_101 :
V_2 -> V_28 = V_3 -> V_147 & ~ V_149 ;
break;
}
F_46 ( & V_2 -> V_151 ) ;
F_47 ( & V_2 -> V_152 ) ;
F_48 ( & V_2 -> V_96 , F_31 ) ;
F_48 ( & V_2 -> V_122 , F_40 ) ;
F_48 ( & V_2 -> V_106 , F_36 ) ;
F_48 ( & V_2 -> F_41 , F_41 ) ;
F_49 ( & V_2 -> V_97 , 0 ) ;
F_50 ( V_3 ) ;
F_51 ( V_3 , V_2 ) ;
if ( V_3 -> V_153 )
V_3 -> V_153 ( V_3 , V_154 ) ;
F_52 ( V_2 ) ;
return V_2 ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_6 , V_3 -> V_128 , V_2 , V_2 -> V_45 ) ;
F_53 ( & V_2 -> V_96 ) ;
F_53 ( & V_2 -> V_122 ) ;
F_53 ( & V_2 -> V_106 ) ;
if ( V_2 -> type == V_42 ) {
struct V_1 * V_93 = V_2 -> V_65 ;
if ( V_93 )
V_93 -> V_65 = NULL ;
V_3 -> V_155 += V_2 -> V_156 ;
} else if ( V_2 -> type == V_99 ) {
F_54 ( & V_2 -> F_41 ) ;
if ( V_3 -> V_157 )
V_3 -> V_158 += V_2 -> V_156 ;
else
V_3 -> V_155 += V_2 -> V_156 ;
} else {
struct V_1 * V_159 = V_2 -> V_65 ;
if ( V_159 ) {
V_159 -> V_65 = NULL ;
F_55 ( V_159 ) ;
}
}
F_56 ( V_2 ) ;
if ( V_2 -> V_160 )
F_57 ( V_2 -> V_160 ) ;
F_58 ( V_3 , V_2 ) ;
if ( V_3 -> V_153 )
V_3 -> V_153 ( V_3 , V_161 ) ;
F_59 ( & V_2 -> V_151 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 -> V_162 ) ;
if ( F_62 ( V_163 , & V_2 -> V_27 ) )
F_63 ( V_2 -> V_3 , & V_2 -> V_18 , V_2 -> V_78 ) ;
F_64 ( V_3 ) ;
F_65 ( V_2 ) ;
return 0 ;
}
struct V_5 * F_66 ( T_7 * V_18 , T_7 * V_130 )
{
int V_164 = F_67 ( V_130 , V_165 ) ;
struct V_5 * V_3 = NULL , * V_166 ;
F_4 ( L_7 , V_130 , V_18 ) ;
F_68 ( & V_167 ) ;
F_69 (d, &hci_dev_list, list) {
if ( ! F_62 ( V_168 , & V_166 -> V_27 ) ||
F_62 ( V_169 , & V_166 -> V_170 ) ||
V_166 -> V_171 != V_172 )
continue;
if ( V_164 ) {
if ( ! F_67 ( & V_166 -> V_17 , V_130 ) ) {
V_3 = V_166 ; break;
}
} else {
if ( F_67 ( & V_166 -> V_17 , V_18 ) ) {
V_3 = V_166 ; break;
}
}
}
if ( V_3 )
V_3 = F_50 ( V_3 ) ;
F_70 ( & V_167 ) ;
return V_3 ;
}
void F_42 ( struct V_1 * V_2 , T_3 V_92 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_75 * V_76 ;
V_76 = F_71 ( & V_3 -> V_173 , & V_2 -> V_18 ,
V_2 -> V_78 ) ;
if ( V_76 && V_76 -> V_2 ) {
F_55 ( V_76 -> V_2 ) ;
F_65 ( V_76 -> V_2 ) ;
V_76 -> V_2 = NULL ;
}
V_2 -> V_10 = V_105 ;
F_72 ( V_3 , & V_2 -> V_18 , V_2 -> type , V_2 -> V_78 ,
V_92 ) ;
F_29 ( V_2 , V_92 ) ;
F_30 ( V_2 ) ;
F_73 ( V_3 ) ;
F_74 ( V_3 ) ;
}
static void F_75 ( struct V_5 * V_3 , T_3 V_92 , T_4 V_174 )
{
struct V_1 * V_2 ;
if ( V_92 == 0 )
return;
F_76 ( L_8 ,
V_92 ) ;
F_24 ( V_3 ) ;
V_2 = F_77 ( V_3 , V_99 , V_11 ) ;
if ( ! V_2 )
goto V_175;
F_42 ( V_2 , V_92 ) ;
V_175:
F_26 ( V_3 ) ;
}
static void F_78 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
struct V_178 V_9 ;
struct V_5 * V_3 = V_2 -> V_3 ;
T_3 V_179 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
if ( F_79 ( V_177 , false , & V_179 ) )
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
F_80 ( V_177 , V_191 , sizeof( V_9 ) , & V_9 ) ;
V_2 -> V_10 = V_11 ;
}
static void F_81 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
struct V_5 * V_3 = V_177 -> V_3 ;
struct V_192 V_9 ;
T_3 V_179 ;
T_3 V_125 ;
F_82 ( V_193 , & V_3 -> V_170 ) ;
if ( F_79 ( V_177 , false , & V_179 ) < 0 )
return;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . type = V_194 ;
V_9 . V_186 = V_179 ;
V_9 . V_195 = V_2 -> V_78 ;
F_5 ( & V_9 . V_196 , & V_2 -> V_18 ) ;
V_9 . V_197 = V_3 -> V_198 ;
F_80 ( V_177 , V_199 , sizeof( V_9 ) , & V_9 ) ;
V_125 = 0x01 ;
F_80 ( V_177 , V_126 , sizeof( V_125 ) , & V_125 ) ;
V_2 -> V_10 = V_11 ;
}
struct V_1 * F_83 ( struct V_5 * V_3 , T_7 * V_18 ,
T_3 V_78 , T_3 V_200 , T_4 V_201 ,
T_3 V_13 )
{
struct V_75 * V_76 ;
struct V_1 * V_2 ;
struct V_202 * V_203 ;
struct V_176 V_177 ;
int V_204 ;
V_2 = F_84 ( V_3 , V_99 , V_18 ) ;
if ( V_2 ) {
V_2 -> V_205 = V_200 ;
goto V_175;
}
V_2 = F_77 ( V_3 , V_99 , V_11 ) ;
if ( V_2 )
return F_85 ( - V_206 ) ;
V_203 = F_86 ( V_3 , V_18 , V_78 ) ;
if ( V_203 && F_67 ( & V_203 -> V_207 , V_165 ) ) {
V_18 = & V_203 -> V_207 ;
V_78 = V_208 ;
}
V_2 = F_43 ( V_3 , V_99 , V_18 , V_13 ) ;
if ( ! V_2 )
return F_85 ( - V_209 ) ;
V_2 -> V_78 = V_78 ;
V_2 -> V_200 = V_210 ;
V_2 -> V_205 = V_200 ;
V_2 -> V_201 = V_201 ;
F_87 ( & V_177 , V_3 ) ;
if ( F_62 ( V_193 , & V_3 -> V_170 ) ) {
T_3 V_125 = 0x00 ;
F_80 ( & V_177 , V_126 , sizeof( V_125 ) ,
& V_125 ) ;
}
if ( V_2 -> V_13 == V_124 ) {
if ( F_62 ( V_211 , & V_3 -> V_170 ) &&
V_3 -> V_212 == V_213 ) {
F_59 ( & V_177 . V_214 ) ;
F_30 ( V_2 ) ;
return F_85 ( - V_206 ) ;
}
F_81 ( & V_177 , V_2 ) ;
goto V_215;
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
if ( F_62 ( V_211 , & V_3 -> V_170 ) ) {
F_88 ( & V_177 ) ;
F_9 ( V_216 , & V_3 -> V_170 ) ;
}
F_78 ( & V_177 , V_2 ) ;
V_215:
V_204 = F_89 ( & V_177 , F_75 ) ;
if ( V_204 ) {
F_30 ( V_2 ) ;
return F_85 ( V_204 ) ;
}
V_175:
F_90 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_91 ( struct V_5 * V_3 , T_7 * V_18 ,
T_3 V_200 , T_3 V_132 )
{
struct V_1 * V_159 ;
if ( ! F_62 ( V_217 , & V_3 -> V_170 ) )
return F_85 ( - V_218 ) ;
V_159 = F_84 ( V_3 , V_42 , V_18 ) ;
if ( ! V_159 ) {
V_159 = F_43 ( V_3 , V_42 , V_18 , V_14 ) ;
if ( ! V_159 )
return F_85 ( - V_209 ) ;
}
F_90 ( V_159 ) ;
if ( V_159 -> V_10 == V_131 || V_159 -> V_10 == V_105 ) {
V_159 -> V_200 = V_210 ;
V_159 -> V_205 = V_200 ;
V_159 -> V_132 = V_132 ;
F_3 ( V_159 ) ;
}
return V_159 ;
}
struct V_1 * F_92 ( struct V_5 * V_3 , int type , T_7 * V_18 ,
T_2 V_60 )
{
struct V_1 * V_159 ;
struct V_1 * V_93 ;
V_159 = F_91 ( V_3 , V_18 , V_210 , V_219 ) ;
if ( F_93 ( V_159 ) )
return V_159 ;
V_93 = F_84 ( V_3 , type , V_18 ) ;
if ( ! V_93 ) {
V_93 = F_43 ( V_3 , type , V_18 , V_14 ) ;
if ( ! V_93 ) {
F_55 ( V_159 ) ;
return F_85 ( - V_209 ) ;
}
}
V_159 -> V_65 = V_93 ;
V_93 -> V_65 = V_159 ;
F_90 ( V_93 ) ;
V_93 -> V_60 = V_60 ;
if ( V_159 -> V_10 == V_103 &&
( V_93 -> V_10 == V_131 || V_93 -> V_10 == V_105 ) ) {
F_9 ( V_142 , & V_159 -> V_27 ) ;
F_94 ( V_159 , V_220 ) ;
if ( F_62 ( V_114 , & V_159 -> V_27 ) ) {
F_9 ( V_221 , & V_159 -> V_27 ) ;
return V_93 ;
}
F_28 ( V_159 , 0x00 ) ;
}
return V_93 ;
}
int F_95 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( F_62 ( V_222 , & V_2 -> V_3 -> V_27 ) ) {
if ( ! F_96 ( V_2 ) ||
! F_62 ( V_223 , & V_2 -> V_27 ) ||
V_2 -> V_136 != V_224 )
return 0 ;
}
if ( F_97 ( V_2 ) &&
! F_62 ( V_225 , & V_2 -> V_27 ) )
return 0 ;
return 1 ;
}
static int F_98 ( struct V_1 * V_2 , T_1 V_200 , T_1 V_132 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_205 > V_200 )
V_200 = V_2 -> V_205 ;
if ( V_200 > V_2 -> V_200 )
V_2 -> V_205 = V_200 ;
else if ( F_62 ( V_226 , & V_2 -> V_27 ) )
return 1 ;
V_132 |= ( V_2 -> V_132 & 0x01 ) ;
V_2 -> V_132 = V_132 ;
if ( ! F_39 ( V_227 , & V_2 -> V_27 ) ) {
struct V_228 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
F_2 ( V_2 -> V_3 , V_229 ,
sizeof( V_9 ) , & V_9 ) ;
if ( F_62 ( V_225 , & V_2 -> V_27 ) )
F_9 ( V_230 , & V_2 -> V_27 ) ;
else
F_9 ( V_231 , & V_2 -> V_27 ) ;
}
return 0 ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_39 ( V_231 , & V_2 -> V_27 ) ) {
struct V_232 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
V_9 . V_233 = 0x01 ;
F_2 ( V_2 -> V_3 , V_234 , sizeof( V_9 ) ,
& V_9 ) ;
}
}
int F_100 ( struct V_1 * V_2 , T_1 V_200 , T_1 V_132 ,
bool V_235 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_99 )
return F_101 ( V_2 , V_200 ) ;
if ( V_200 == V_236 )
return 1 ;
if ( V_200 == V_210 && ! F_97 ( V_2 ) )
return 1 ;
if ( ! F_62 ( V_226 , & V_2 -> V_27 ) )
goto V_237;
if ( V_2 -> V_136 == V_224 &&
V_200 == V_238 )
goto V_233;
if ( ( V_2 -> V_136 == V_239 ||
V_2 -> V_136 == V_224 ) &&
V_200 == V_240 )
goto V_233;
if ( ( V_2 -> V_136 == V_241 ||
V_2 -> V_136 == V_242 ) &&
( V_200 == V_243 || V_200 == V_210 ) )
goto V_233;
if ( V_2 -> V_136 == V_244 &&
( V_200 == V_243 || V_200 == V_210 ||
V_2 -> V_245 == 16 ) )
goto V_233;
V_237:
if ( F_62 ( V_231 , & V_2 -> V_27 ) )
return 0 ;
if ( V_235 )
F_9 ( V_246 , & V_2 -> V_27 ) ;
if ( ! F_98 ( V_2 , V_200 , V_132 ) )
return 0 ;
V_233:
if ( F_62 ( V_225 , & V_2 -> V_27 ) )
return 1 ;
F_99 ( V_2 ) ;
return 0 ;
}
int F_102 ( struct V_1 * V_2 , T_1 V_200 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_200 != V_240 && V_200 != V_238 )
return 1 ;
if ( V_2 -> V_200 == V_240 ||
V_2 -> V_200 == V_238 )
return 1 ;
return 0 ;
}
int F_103 ( struct V_1 * V_2 , T_1 V_13 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_13 == V_2 -> V_13 )
return 1 ;
if ( ! F_39 ( V_247 , & V_2 -> V_27 ) ) {
struct V_248 V_9 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
V_9 . V_13 = V_13 ;
F_2 ( V_2 -> V_3 , V_249 , sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
void F_94 ( struct V_1 * V_2 , T_1 V_250 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_107 ) ;
if ( V_2 -> V_107 != V_251 )
goto V_252;
if ( ! F_62 ( V_142 , & V_2 -> V_27 ) && ! V_250 )
goto V_252;
if ( ! F_39 ( V_114 , & V_2 -> V_27 ) ) {
struct V_253 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
F_2 ( V_3 , V_254 , sizeof( V_9 ) , & V_9 ) ;
}
V_252:
if ( V_3 -> V_255 > 0 )
F_104 ( V_3 -> V_256 , & V_2 -> V_106 ,
F_105 ( V_3 -> V_255 ) ) ;
}
void F_106 ( struct V_5 * V_3 )
{
struct V_257 * V_258 = & V_3 -> V_259 ;
struct V_1 * V_260 , * V_261 ;
F_4 ( L_9 , V_3 -> V_128 ) ;
F_107 (c, n, &h->list, list) {
V_260 -> V_10 = V_105 ;
F_108 ( V_260 , V_262 ) ;
F_30 ( V_260 ) ;
}
}
void F_109 ( struct V_5 * V_3 )
{
struct V_1 * V_2 ;
F_4 ( L_9 , V_3 -> V_128 ) ;
F_24 ( V_3 ) ;
V_2 = F_77 ( V_3 , V_42 , V_98 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_26 ( V_3 ) ;
}
static T_8 F_110 ( struct V_1 * V_2 )
{
T_8 V_29 = 0 ;
if ( V_2 -> V_13 == V_14 )
V_29 |= V_30 ;
if ( F_62 ( V_225 , & V_2 -> V_27 ) )
V_29 |= V_263 ;
if ( F_62 ( V_226 , & V_2 -> V_27 ) )
V_29 |= V_264 ;
if ( F_62 ( V_265 , & V_2 -> V_27 ) )
V_29 |= V_266 ;
if ( F_62 ( V_267 , & V_2 -> V_27 ) )
V_29 |= V_268 ;
return V_29 ;
}
int F_111 ( void T_9 * V_269 )
{
struct V_1 * V_260 ;
struct V_270 V_177 , * V_271 ;
struct V_272 * V_273 ;
struct V_5 * V_3 ;
int V_261 = 0 , V_274 , V_204 ;
if ( F_112 ( & V_177 , V_269 , sizeof( V_177 ) ) )
return - V_275 ;
if ( ! V_177 . V_276 || V_177 . V_276 > ( V_277 * 2 ) / sizeof( * V_273 ) )
return - V_278 ;
V_274 = sizeof( V_177 ) + V_177 . V_276 * sizeof( * V_273 ) ;
V_271 = F_113 ( V_274 , V_129 ) ;
if ( ! V_271 )
return - V_209 ;
V_3 = F_114 ( V_177 . V_279 ) ;
if ( ! V_3 ) {
F_115 ( V_271 ) ;
return - V_280 ;
}
V_273 = V_271 -> V_281 ;
F_24 ( V_3 ) ;
F_69 (c, &hdev->conn_hash.list, list) {
F_5 ( & ( V_273 + V_261 ) -> V_17 , & V_260 -> V_18 ) ;
( V_273 + V_261 ) -> V_45 = V_260 -> V_45 ;
( V_273 + V_261 ) -> type = V_260 -> type ;
( V_273 + V_261 ) -> V_12 = V_260 -> V_12 ;
( V_273 + V_261 ) -> V_10 = V_260 -> V_10 ;
( V_273 + V_261 ) -> V_29 = F_110 ( V_260 ) ;
if ( ++ V_261 >= V_177 . V_276 )
break;
}
F_26 ( V_3 ) ;
V_271 -> V_279 = V_3 -> V_282 ;
V_271 -> V_276 = V_261 ;
V_274 = sizeof( V_177 ) + V_261 * sizeof( * V_273 ) ;
F_64 ( V_3 ) ;
V_204 = F_116 ( V_269 , V_271 , V_274 ) ;
F_115 ( V_271 ) ;
return V_204 ? - V_275 : 0 ;
}
int F_117 ( struct V_5 * V_3 , void T_9 * V_269 )
{
struct V_283 V_177 ;
struct V_272 V_273 ;
struct V_1 * V_2 ;
char T_9 * V_284 = V_269 + sizeof( V_177 ) ;
if ( F_112 ( & V_177 , V_269 , sizeof( V_177 ) ) )
return - V_275 ;
F_24 ( V_3 ) ;
V_2 = F_84 ( V_3 , V_177 . type , & V_177 . V_17 ) ;
if ( V_2 ) {
F_5 ( & V_273 . V_17 , & V_2 -> V_18 ) ;
V_273 . V_45 = V_2 -> V_45 ;
V_273 . type = V_2 -> type ;
V_273 . V_12 = V_2 -> V_12 ;
V_273 . V_10 = V_2 -> V_10 ;
V_273 . V_29 = F_110 ( V_2 ) ;
}
F_26 ( V_3 ) ;
if ( ! V_2 )
return - V_285 ;
return F_116 ( V_284 , & V_273 , sizeof( V_273 ) ) ? - V_275 : 0 ;
}
int F_118 ( struct V_5 * V_3 , void T_9 * V_269 )
{
struct V_286 V_177 ;
struct V_1 * V_2 ;
if ( F_112 ( & V_177 , V_269 , sizeof( V_177 ) ) )
return - V_275 ;
F_24 ( V_3 ) ;
V_2 = F_84 ( V_3 , V_42 , & V_177 . V_17 ) ;
if ( V_2 )
V_177 . type = V_2 -> V_132 ;
F_26 ( V_3 ) ;
if ( ! V_2 )
return - V_285 ;
return F_116 ( V_269 , & V_177 , sizeof( V_177 ) ) ? - V_275 : 0 ;
}
struct V_287 * F_119 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_287 * V_288 ;
F_4 ( L_10 , V_3 -> V_128 , V_2 ) ;
if ( F_62 ( V_289 , & V_2 -> V_27 ) ) {
F_4 ( L_11 ) ;
return NULL ;
}
V_288 = F_44 ( sizeof( * V_288 ) , V_129 ) ;
if ( ! V_288 )
return NULL ;
V_288 -> V_2 = F_120 ( V_2 ) ;
F_46 ( & V_288 -> V_151 ) ;
V_288 -> V_10 = V_103 ;
F_121 ( & V_288 -> V_290 , & V_2 -> V_152 ) ;
return V_288 ;
}
void F_122 ( struct V_287 * V_288 )
{
struct V_1 * V_2 = V_288 -> V_2 ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_12 , V_3 -> V_128 , V_2 , V_288 ) ;
F_123 ( & V_288 -> V_290 ) ;
F_124 () ;
F_9 ( V_289 , & V_2 -> V_27 ) ;
F_65 ( V_2 ) ;
F_59 ( & V_288 -> V_151 ) ;
F_115 ( V_288 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_287 * V_288 , * V_261 ;
F_4 ( L_1 , V_2 ) ;
F_107 (chan, n, &conn->chan_list, list)
F_122 ( V_288 ) ;
}
static struct V_287 * F_125 ( struct V_1 * V_291 ,
T_2 V_45 )
{
struct V_287 * V_292 ;
F_69 (hchan, &hcon->chan_list, list) {
if ( V_292 -> V_45 == V_45 )
return V_292 ;
}
return NULL ;
}
struct V_287 * F_126 ( struct V_5 * V_3 , T_2 V_45 )
{
struct V_257 * V_258 = & V_3 -> V_259 ;
struct V_1 * V_291 ;
struct V_287 * V_292 = NULL ;
F_127 () ;
F_128 (hcon, &h->list, list) {
V_292 = F_125 ( V_291 , V_45 ) ;
if ( V_292 )
break;
}
F_129 () ;
return V_292 ;
}
