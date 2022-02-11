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
F_70 ( V_166 , V_169 ) ||
V_166 -> V_170 != V_171 )
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
F_71 ( & V_167 ) ;
return V_3 ;
}
void F_42 ( struct V_1 * V_2 , T_3 V_92 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_75 * V_76 ;
V_76 = F_72 ( & V_3 -> V_172 , & V_2 -> V_18 ,
V_2 -> V_78 ) ;
if ( V_76 && V_76 -> V_2 ) {
F_55 ( V_76 -> V_2 ) ;
F_65 ( V_76 -> V_2 ) ;
V_76 -> V_2 = NULL ;
}
V_2 -> V_10 = V_105 ;
F_73 ( V_3 , & V_2 -> V_18 , V_2 -> type , V_2 -> V_78 ,
V_92 ) ;
F_29 ( V_2 , V_92 ) ;
F_30 ( V_2 ) ;
F_74 ( V_3 ) ;
F_75 ( V_3 ) ;
}
static void F_76 ( struct V_5 * V_3 , T_3 V_92 , T_4 V_173 )
{
struct V_1 * V_2 ;
if ( V_92 == 0 )
return;
F_77 ( L_8 ,
V_92 ) ;
F_24 ( V_3 ) ;
V_2 = F_78 ( V_3 , V_99 , V_11 ) ;
if ( ! V_2 )
goto V_174;
F_42 ( V_2 , V_92 ) ;
V_174:
F_26 ( V_3 ) ;
}
static void F_79 ( struct V_175 * V_176 ,
struct V_1 * V_2 )
{
struct V_177 V_9 ;
struct V_5 * V_3 = V_2 -> V_3 ;
T_3 V_178 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
if ( F_80 ( V_176 , false , & V_178 ) )
return;
V_9 . V_179 = F_8 ( V_3 -> V_180 ) ;
V_9 . V_181 = F_8 ( V_3 -> V_182 ) ;
F_5 ( & V_9 . V_183 , & V_2 -> V_18 ) ;
V_9 . V_184 = V_2 -> V_78 ;
V_9 . V_185 = V_178 ;
V_9 . V_83 = F_8 ( V_2 -> V_186 ) ;
V_9 . V_84 = F_8 ( V_2 -> V_187 ) ;
V_9 . V_81 = F_8 ( V_2 -> V_188 ) ;
V_9 . V_82 = F_8 ( V_2 -> V_189 ) ;
V_9 . V_85 = F_8 ( 0x0000 ) ;
V_9 . V_86 = F_8 ( 0x0000 ) ;
F_81 ( V_176 , V_190 , sizeof( V_9 ) , & V_9 ) ;
V_2 -> V_10 = V_11 ;
}
static void F_82 ( struct V_175 * V_176 ,
struct V_1 * V_2 )
{
struct V_5 * V_3 = V_176 -> V_3 ;
struct V_191 V_9 ;
T_3 V_178 ;
T_3 V_125 ;
F_83 ( V_3 , V_192 ) ;
if ( F_80 ( V_176 , false , & V_178 ) < 0 )
return;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . type = V_193 ;
V_9 . V_185 = V_178 ;
V_9 . V_194 = V_2 -> V_78 ;
F_5 ( & V_9 . V_195 , & V_2 -> V_18 ) ;
V_9 . V_196 = V_3 -> V_197 ;
F_81 ( V_176 , V_198 , sizeof( V_9 ) , & V_9 ) ;
V_125 = 0x01 ;
F_81 ( V_176 , V_126 , sizeof( V_125 ) , & V_125 ) ;
V_2 -> V_10 = V_11 ;
}
struct V_1 * F_84 ( struct V_5 * V_3 , T_7 * V_18 ,
T_3 V_78 , T_3 V_199 , T_4 V_200 ,
T_3 V_13 )
{
struct V_75 * V_76 ;
struct V_1 * V_2 ;
struct V_201 * V_202 ;
struct V_175 V_176 ;
int V_203 ;
if ( ! F_70 ( V_3 , V_204 ) ) {
if ( F_85 ( V_3 ) )
return F_86 ( - V_205 ) ;
return F_86 ( - V_206 ) ;
}
V_2 = F_87 ( V_3 , V_99 , V_18 ) ;
if ( V_2 ) {
V_2 -> V_207 = V_199 ;
goto V_174;
}
V_2 = F_78 ( V_3 , V_99 , V_11 ) ;
if ( V_2 )
return F_86 ( - V_208 ) ;
V_202 = F_88 ( V_3 , V_18 , V_78 ) ;
if ( V_202 && F_67 ( & V_202 -> V_209 , V_165 ) ) {
V_18 = & V_202 -> V_209 ;
V_78 = V_210 ;
}
V_2 = F_43 ( V_3 , V_99 , V_18 , V_13 ) ;
if ( ! V_2 )
return F_86 ( - V_211 ) ;
V_2 -> V_78 = V_78 ;
V_2 -> V_199 = V_212 ;
V_2 -> V_207 = V_199 ;
V_2 -> V_200 = V_200 ;
F_89 ( & V_176 , V_3 ) ;
if ( F_70 ( V_3 , V_192 ) ) {
T_3 V_125 = 0x00 ;
F_81 ( & V_176 , V_126 , sizeof( V_125 ) ,
& V_125 ) ;
}
if ( V_2 -> V_13 == V_124 ) {
if ( F_70 ( V_3 , V_213 ) &&
V_3 -> V_214 == V_215 ) {
F_59 ( & V_176 . V_216 ) ;
F_30 ( V_2 ) ;
return F_86 ( - V_208 ) ;
}
F_82 ( & V_176 , V_2 ) ;
goto V_217;
}
V_76 = F_25 ( V_3 , & V_2 -> V_18 , V_2 -> V_78 ) ;
if ( V_76 ) {
V_2 -> V_186 = V_76 -> V_79 ;
V_2 -> V_187 = V_76 -> V_80 ;
V_2 -> V_188 = V_76 -> V_81 ;
V_2 -> V_189 = V_76 -> V_82 ;
} else {
V_2 -> V_186 = V_3 -> V_186 ;
V_2 -> V_187 = V_3 -> V_187 ;
V_2 -> V_188 = V_3 -> V_188 ;
V_2 -> V_189 = V_3 -> V_189 ;
}
if ( F_70 ( V_3 , V_213 ) ) {
F_90 ( & V_176 ) ;
F_91 ( V_3 , V_218 ) ;
}
F_79 ( & V_176 , V_2 ) ;
V_217:
V_203 = F_92 ( & V_176 , F_76 ) ;
if ( V_203 ) {
F_30 ( V_2 ) ;
return F_86 ( V_203 ) ;
}
V_174:
F_93 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_94 ( struct V_5 * V_3 , T_7 * V_18 ,
T_3 V_199 , T_3 V_132 )
{
struct V_1 * V_159 ;
if ( ! F_70 ( V_3 , V_219 ) ) {
if ( F_95 ( V_3 ) )
return F_86 ( - V_205 ) ;
return F_86 ( - V_206 ) ;
}
V_159 = F_87 ( V_3 , V_42 , V_18 ) ;
if ( ! V_159 ) {
V_159 = F_43 ( V_3 , V_42 , V_18 , V_14 ) ;
if ( ! V_159 )
return F_86 ( - V_211 ) ;
}
F_93 ( V_159 ) ;
if ( V_159 -> V_10 == V_131 || V_159 -> V_10 == V_105 ) {
V_159 -> V_199 = V_212 ;
V_159 -> V_207 = V_199 ;
V_159 -> V_132 = V_132 ;
F_3 ( V_159 ) ;
}
return V_159 ;
}
struct V_1 * F_96 ( struct V_5 * V_3 , int type , T_7 * V_18 ,
T_2 V_60 )
{
struct V_1 * V_159 ;
struct V_1 * V_93 ;
V_159 = F_94 ( V_3 , V_18 , V_212 , V_220 ) ;
if ( F_97 ( V_159 ) )
return V_159 ;
V_93 = F_87 ( V_3 , type , V_18 ) ;
if ( ! V_93 ) {
V_93 = F_43 ( V_3 , type , V_18 , V_14 ) ;
if ( ! V_93 ) {
F_55 ( V_159 ) ;
return F_86 ( - V_211 ) ;
}
}
V_159 -> V_65 = V_93 ;
V_93 -> V_65 = V_159 ;
F_93 ( V_93 ) ;
V_93 -> V_60 = V_60 ;
if ( V_159 -> V_10 == V_103 &&
( V_93 -> V_10 == V_131 || V_93 -> V_10 == V_105 ) ) {
F_9 ( V_142 , & V_159 -> V_27 ) ;
F_98 ( V_159 , V_221 ) ;
if ( F_62 ( V_114 , & V_159 -> V_27 ) ) {
F_9 ( V_222 , & V_159 -> V_27 ) ;
return V_93 ;
}
F_28 ( V_159 , 0x00 ) ;
}
return V_93 ;
}
int F_99 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( F_70 ( V_2 -> V_3 , V_223 ) ) {
if ( ! F_100 ( V_2 ) ||
! F_62 ( V_224 , & V_2 -> V_27 ) ||
V_2 -> V_136 != V_225 )
return 0 ;
}
if ( F_101 ( V_2 ) &&
! F_62 ( V_226 , & V_2 -> V_27 ) )
return 0 ;
return 1 ;
}
static int F_102 ( struct V_1 * V_2 , T_1 V_199 , T_1 V_132 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_207 > V_199 )
V_199 = V_2 -> V_207 ;
if ( V_199 > V_2 -> V_199 )
V_2 -> V_207 = V_199 ;
else if ( F_62 ( V_227 , & V_2 -> V_27 ) )
return 1 ;
V_132 |= ( V_2 -> V_132 & 0x01 ) ;
V_2 -> V_132 = V_132 ;
if ( ! F_39 ( V_228 , & V_2 -> V_27 ) ) {
struct V_229 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
F_2 ( V_2 -> V_3 , V_230 ,
sizeof( V_9 ) , & V_9 ) ;
if ( F_62 ( V_226 , & V_2 -> V_27 ) )
F_9 ( V_231 , & V_2 -> V_27 ) ;
else
F_9 ( V_232 , & V_2 -> V_27 ) ;
}
return 0 ;
}
static void F_103 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_39 ( V_232 , & V_2 -> V_27 ) ) {
struct V_233 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
V_9 . V_234 = 0x01 ;
F_2 ( V_2 -> V_3 , V_235 , sizeof( V_9 ) ,
& V_9 ) ;
}
}
int F_104 ( struct V_1 * V_2 , T_1 V_199 , T_1 V_132 ,
bool V_236 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_99 )
return F_105 ( V_2 , V_199 ) ;
if ( V_199 == V_237 )
return 1 ;
if ( V_199 == V_212 && ! F_101 ( V_2 ) )
return 1 ;
if ( ! F_62 ( V_227 , & V_2 -> V_27 ) )
goto V_238;
if ( V_2 -> V_136 == V_225 &&
V_199 == V_239 )
goto V_234;
if ( ( V_2 -> V_136 == V_240 ||
V_2 -> V_136 == V_225 ) &&
V_199 == V_241 )
goto V_234;
if ( ( V_2 -> V_136 == V_242 ||
V_2 -> V_136 == V_243 ) &&
( V_199 == V_244 || V_199 == V_212 ) )
goto V_234;
if ( V_2 -> V_136 == V_245 &&
( V_199 == V_244 || V_199 == V_212 ||
V_2 -> V_246 == 16 ) )
goto V_234;
V_238:
if ( F_62 ( V_232 , & V_2 -> V_27 ) )
return 0 ;
if ( V_236 )
F_9 ( V_247 , & V_2 -> V_27 ) ;
if ( ! F_102 ( V_2 , V_199 , V_132 ) )
return 0 ;
V_234:
if ( F_62 ( V_226 , & V_2 -> V_27 ) )
return 1 ;
F_103 ( V_2 ) ;
return 0 ;
}
int F_106 ( struct V_1 * V_2 , T_1 V_199 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_199 != V_241 && V_199 != V_239 )
return 1 ;
if ( V_2 -> V_199 == V_241 ||
V_2 -> V_199 == V_239 )
return 1 ;
return 0 ;
}
int F_107 ( struct V_1 * V_2 , T_1 V_13 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_13 == V_2 -> V_13 )
return 1 ;
if ( ! F_39 ( V_248 , & V_2 -> V_27 ) ) {
struct V_249 V_9 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
V_9 . V_13 = V_13 ;
F_2 ( V_2 -> V_3 , V_250 , sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
void F_98 ( struct V_1 * V_2 , T_1 V_251 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_107 ) ;
if ( V_2 -> V_107 != V_252 )
goto V_253;
if ( ! F_62 ( V_142 , & V_2 -> V_27 ) && ! V_251 )
goto V_253;
if ( ! F_39 ( V_114 , & V_2 -> V_27 ) ) {
struct V_254 V_9 ;
V_9 . V_45 = F_8 ( V_2 -> V_45 ) ;
F_2 ( V_3 , V_255 , sizeof( V_9 ) , & V_9 ) ;
}
V_253:
if ( V_3 -> V_256 > 0 )
F_108 ( V_3 -> V_257 , & V_2 -> V_106 ,
F_109 ( V_3 -> V_256 ) ) ;
}
void F_110 ( struct V_5 * V_3 )
{
struct V_258 * V_259 = & V_3 -> V_260 ;
struct V_1 * V_261 , * V_262 ;
F_4 ( L_9 , V_3 -> V_128 ) ;
F_111 (c, n, &h->list, list) {
V_261 -> V_10 = V_105 ;
F_112 ( V_261 , V_263 ) ;
F_30 ( V_261 ) ;
}
}
void F_113 ( struct V_5 * V_3 )
{
struct V_1 * V_2 ;
F_4 ( L_9 , V_3 -> V_128 ) ;
F_24 ( V_3 ) ;
V_2 = F_78 ( V_3 , V_42 , V_98 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_26 ( V_3 ) ;
}
static T_8 F_114 ( struct V_1 * V_2 )
{
T_8 V_29 = 0 ;
if ( V_2 -> V_13 == V_14 )
V_29 |= V_30 ;
if ( F_62 ( V_226 , & V_2 -> V_27 ) )
V_29 |= V_264 ;
if ( F_62 ( V_227 , & V_2 -> V_27 ) )
V_29 |= V_265 ;
if ( F_62 ( V_266 , & V_2 -> V_27 ) )
V_29 |= V_267 ;
if ( F_62 ( V_268 , & V_2 -> V_27 ) )
V_29 |= V_269 ;
return V_29 ;
}
int F_115 ( void T_9 * V_270 )
{
struct V_1 * V_261 ;
struct V_271 V_176 , * V_272 ;
struct V_273 * V_274 ;
struct V_5 * V_3 ;
int V_262 = 0 , V_275 , V_203 ;
if ( F_116 ( & V_176 , V_270 , sizeof( V_176 ) ) )
return - V_276 ;
if ( ! V_176 . V_277 || V_176 . V_277 > ( V_278 * 2 ) / sizeof( * V_274 ) )
return - V_279 ;
V_275 = sizeof( V_176 ) + V_176 . V_277 * sizeof( * V_274 ) ;
V_272 = F_117 ( V_275 , V_129 ) ;
if ( ! V_272 )
return - V_211 ;
V_3 = F_118 ( V_176 . V_280 ) ;
if ( ! V_3 ) {
F_119 ( V_272 ) ;
return - V_281 ;
}
V_274 = V_272 -> V_282 ;
F_24 ( V_3 ) ;
F_69 (c, &hdev->conn_hash.list, list) {
F_5 ( & ( V_274 + V_262 ) -> V_17 , & V_261 -> V_18 ) ;
( V_274 + V_262 ) -> V_45 = V_261 -> V_45 ;
( V_274 + V_262 ) -> type = V_261 -> type ;
( V_274 + V_262 ) -> V_12 = V_261 -> V_12 ;
( V_274 + V_262 ) -> V_10 = V_261 -> V_10 ;
( V_274 + V_262 ) -> V_29 = F_114 ( V_261 ) ;
if ( ++ V_262 >= V_176 . V_277 )
break;
}
F_26 ( V_3 ) ;
V_272 -> V_280 = V_3 -> V_283 ;
V_272 -> V_277 = V_262 ;
V_275 = sizeof( V_176 ) + V_262 * sizeof( * V_274 ) ;
F_64 ( V_3 ) ;
V_203 = F_120 ( V_270 , V_272 , V_275 ) ;
F_119 ( V_272 ) ;
return V_203 ? - V_276 : 0 ;
}
int F_121 ( struct V_5 * V_3 , void T_9 * V_270 )
{
struct V_284 V_176 ;
struct V_273 V_274 ;
struct V_1 * V_2 ;
char T_9 * V_285 = V_270 + sizeof( V_176 ) ;
if ( F_116 ( & V_176 , V_270 , sizeof( V_176 ) ) )
return - V_276 ;
F_24 ( V_3 ) ;
V_2 = F_87 ( V_3 , V_176 . type , & V_176 . V_17 ) ;
if ( V_2 ) {
F_5 ( & V_274 . V_17 , & V_2 -> V_18 ) ;
V_274 . V_45 = V_2 -> V_45 ;
V_274 . type = V_2 -> type ;
V_274 . V_12 = V_2 -> V_12 ;
V_274 . V_10 = V_2 -> V_10 ;
V_274 . V_29 = F_114 ( V_2 ) ;
}
F_26 ( V_3 ) ;
if ( ! V_2 )
return - V_286 ;
return F_120 ( V_285 , & V_274 , sizeof( V_274 ) ) ? - V_276 : 0 ;
}
int F_122 ( struct V_5 * V_3 , void T_9 * V_270 )
{
struct V_287 V_176 ;
struct V_1 * V_2 ;
if ( F_116 ( & V_176 , V_270 , sizeof( V_176 ) ) )
return - V_276 ;
F_24 ( V_3 ) ;
V_2 = F_87 ( V_3 , V_42 , & V_176 . V_17 ) ;
if ( V_2 )
V_176 . type = V_2 -> V_132 ;
F_26 ( V_3 ) ;
if ( ! V_2 )
return - V_286 ;
return F_120 ( V_270 , & V_176 , sizeof( V_176 ) ) ? - V_276 : 0 ;
}
struct V_288 * F_123 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_288 * V_289 ;
F_4 ( L_10 , V_3 -> V_128 , V_2 ) ;
if ( F_62 ( V_290 , & V_2 -> V_27 ) ) {
F_4 ( L_11 ) ;
return NULL ;
}
V_289 = F_44 ( sizeof( * V_289 ) , V_129 ) ;
if ( ! V_289 )
return NULL ;
V_289 -> V_2 = F_124 ( V_2 ) ;
F_46 ( & V_289 -> V_151 ) ;
V_289 -> V_10 = V_103 ;
F_125 ( & V_289 -> V_291 , & V_2 -> V_152 ) ;
return V_289 ;
}
void F_126 ( struct V_288 * V_289 )
{
struct V_1 * V_2 = V_289 -> V_2 ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_12 , V_3 -> V_128 , V_2 , V_289 ) ;
F_127 ( & V_289 -> V_291 ) ;
F_128 () ;
F_9 ( V_290 , & V_2 -> V_27 ) ;
F_65 ( V_2 ) ;
F_59 ( & V_289 -> V_151 ) ;
F_119 ( V_289 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_288 * V_289 , * V_262 ;
F_4 ( L_1 , V_2 ) ;
F_111 (chan, n, &conn->chan_list, list)
F_126 ( V_289 ) ;
}
static struct V_288 * F_129 ( struct V_1 * V_292 ,
T_2 V_45 )
{
struct V_288 * V_293 ;
F_69 (hchan, &hcon->chan_list, list) {
if ( V_293 -> V_45 == V_45 )
return V_293 ;
}
return NULL ;
}
struct V_288 * F_130 ( struct V_5 * V_3 , T_2 V_45 )
{
struct V_258 * V_259 = & V_3 -> V_260 ;
struct V_1 * V_292 ;
struct V_288 * V_293 = NULL ;
F_131 () ;
F_132 (hcon, &h->list, list) {
V_293 = F_129 ( V_292 , V_45 ) ;
if ( V_293 )
break;
}
F_133 () ;
return V_293 ;
}
