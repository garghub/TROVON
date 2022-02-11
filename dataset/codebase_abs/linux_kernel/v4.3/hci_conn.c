static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 , 0 , NULL ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 * V_9 ;
T_2 V_10 ;
V_9 = & V_2 -> V_11 ;
V_10 = V_2 -> V_12 ;
V_8 = F_4 ( V_2 -> V_3 , V_9 , V_10 ) ;
if ( V_8 ) {
V_9 = & V_8 -> V_9 ;
V_10 = V_8 -> V_13 ;
}
V_6 = F_5 ( V_2 -> V_3 , V_9 , V_10 ) ;
if ( ! V_6 )
return;
V_6 -> V_14 = false ;
F_6 ( & V_6 -> V_15 ) ;
switch ( V_6 -> V_16 ) {
case V_17 :
F_7 ( V_2 -> V_3 , V_9 , V_10 ) ;
return;
case V_18 :
case V_19 :
F_8 ( & V_6 -> V_15 , & V_2 -> V_3 -> V_20 ) ;
break;
case V_21 :
F_8 ( & V_6 -> V_15 , & V_2 -> V_3 -> V_22 ) ;
break;
default:
break;
}
F_9 ( V_2 -> V_3 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_23 * V_3 = V_2 -> V_3 ;
if ( F_11 ( V_24 , & V_2 -> V_25 ) )
F_7 ( V_2 -> V_3 , & V_2 -> V_11 , V_2 -> V_12 ) ;
F_12 ( V_2 ) ;
F_13 ( V_3 , V_2 ) ;
if ( V_3 -> V_26 )
V_3 -> V_26 ( V_3 , V_27 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 -> V_28 ) ;
F_16 ( V_3 ) ;
F_17 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_23 * V_3 = V_2 -> V_3 ;
struct V_29 * V_30 ;
struct V_31 V_32 ;
F_20 ( L_1 , V_2 ) ;
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = true ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 ++ ;
V_2 -> V_39 = V_3 -> V_39 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
F_21 ( & V_32 . V_9 , & V_2 -> V_11 ) ;
V_32 . V_40 = 0x02 ;
V_30 = F_22 ( V_3 , & V_2 -> V_11 ) ;
if ( V_30 ) {
if ( F_23 ( V_30 ) <= V_41 ) {
V_32 . V_40 = V_30 -> V_42 . V_40 ;
V_32 . V_43 = V_30 -> V_42 . V_43 ;
V_32 . V_44 = V_30 -> V_42 . V_44 |
F_24 ( 0x8000 ) ;
}
memcpy ( V_2 -> V_45 , V_30 -> V_42 . V_45 , 3 ) ;
if ( V_30 -> V_42 . V_46 > 0 )
F_25 ( V_47 , & V_2 -> V_25 ) ;
}
V_32 . V_48 = F_24 ( V_2 -> V_48 ) ;
if ( F_26 ( V_3 ) && ! ( V_3 -> V_49 & V_50 ) )
V_32 . V_51 = 0x01 ;
else
V_32 . V_51 = 0x00 ;
F_2 ( V_3 , V_52 , sizeof( V_32 ) , & V_32 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_53 V_32 ;
F_20 ( L_1 , V_2 ) ;
if ( V_2 -> V_3 -> V_54 < V_55 )
return;
F_21 ( & V_32 . V_9 , & V_2 -> V_11 ) ;
F_2 ( V_2 -> V_3 , V_56 , sizeof( V_32 ) , & V_32 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_57 V_32 ;
V_32 . V_58 = V_59 ;
F_21 ( & V_32 . V_9 , & V_2 -> V_11 ) ;
F_2 ( V_2 -> V_3 , V_60 , sizeof( V_32 ) , & V_32 ) ;
}
int F_29 ( struct V_1 * V_2 , T_3 V_58 )
{
struct V_61 V_32 ;
F_20 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_62 && V_2 -> V_36 == V_37 ) {
struct V_23 * V_3 = V_2 -> V_3 ;
struct V_63 V_64 ;
V_64 . V_65 = F_24 ( V_2 -> V_65 ) ;
F_2 ( V_3 , V_66 , sizeof( V_64 ) ,
& V_64 ) ;
}
V_2 -> V_33 = V_67 ;
V_32 . V_65 = F_24 ( V_2 -> V_65 ) ;
V_32 . V_58 = V_58 ;
return F_2 ( V_2 -> V_3 , V_68 , sizeof( V_32 ) , & V_32 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_69 V_32 ;
F_20 ( L_1 , V_2 ) ;
V_2 -> V_33 = V_67 ;
V_32 . V_70 = F_31 ( V_2 -> V_65 ) ;
V_32 . V_58 = F_32 ( V_2 ) ;
F_2 ( V_2 -> V_3 , V_71 ,
sizeof( V_32 ) , & V_32 ) ;
}
static void F_33 ( struct V_1 * V_2 , T_4 V_65 )
{
struct V_23 * V_3 = V_2 -> V_3 ;
struct V_72 V_32 ;
F_20 ( L_1 , V_2 ) ;
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = true ;
V_2 -> V_38 ++ ;
V_32 . V_65 = F_24 ( V_65 ) ;
V_32 . V_48 = F_24 ( V_2 -> V_48 ) ;
F_2 ( V_3 , V_73 , sizeof( V_32 ) , & V_32 ) ;
}
bool F_34 ( struct V_1 * V_2 , T_4 V_65 )
{
struct V_23 * V_3 = V_2 -> V_3 ;
struct V_74 V_32 ;
const struct V_75 * V_76 ;
F_20 ( L_1 , V_2 ) ;
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = true ;
V_2 -> V_38 ++ ;
V_32 . V_65 = F_24 ( V_65 ) ;
V_32 . V_77 = F_35 ( 0x00001f40 ) ;
V_32 . V_78 = F_35 ( 0x00001f40 ) ;
V_32 . V_79 = F_24 ( V_2 -> V_80 ) ;
switch ( V_2 -> V_80 & V_81 ) {
case V_82 :
if ( V_2 -> V_38 > F_36 ( V_83 ) )
return false ;
V_76 = & V_83 [ V_2 -> V_38 - 1 ] ;
break;
case V_84 :
if ( F_37 ( V_2 -> V_85 ) ) {
if ( V_2 -> V_38 > F_36 ( V_86 ) )
return false ;
V_76 = & V_86 [ V_2 -> V_38 - 1 ] ;
} else {
if ( V_2 -> V_38 > F_36 ( V_87 ) )
return false ;
V_76 = & V_87 [ V_2 -> V_38 - 1 ] ;
}
break;
default:
return false ;
}
V_32 . V_88 = V_76 -> V_88 ;
V_32 . V_48 = F_38 ( V_76 -> V_48 ) ;
V_32 . V_89 = F_38 ( V_76 -> V_89 ) ;
if ( F_2 ( V_3 , V_90 , sizeof( V_32 ) , & V_32 ) < 0 )
return false ;
return true ;
}
T_2 F_39 ( struct V_1 * V_2 , T_5 V_91 , T_5 V_92 , T_5 V_93 ,
T_5 V_94 )
{
struct V_23 * V_3 = V_2 -> V_3 ;
struct V_5 * V_6 ;
struct V_95 V_32 ;
F_40 ( V_3 ) ;
V_6 = F_41 ( V_3 , & V_2 -> V_11 , V_2 -> V_12 ) ;
if ( V_6 ) {
V_6 -> V_96 = V_91 ;
V_6 -> V_97 = V_92 ;
V_6 -> V_98 = V_93 ;
V_6 -> V_99 = V_94 ;
}
F_42 ( V_3 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_65 = F_24 ( V_2 -> V_65 ) ;
V_32 . V_100 = F_24 ( V_91 ) ;
V_32 . V_101 = F_24 ( V_92 ) ;
V_32 . V_98 = F_24 ( V_93 ) ;
V_32 . V_99 = F_24 ( V_94 ) ;
V_32 . V_102 = F_24 ( 0x0000 ) ;
V_32 . V_103 = F_24 ( 0x0000 ) ;
F_2 ( V_3 , V_104 , sizeof( V_32 ) , & V_32 ) ;
if ( V_6 )
return 0x01 ;
return 0x00 ;
}
void F_43 ( struct V_1 * V_2 , T_6 V_105 , T_7 rand ,
T_3 V_106 [ 16 ] , T_3 V_107 )
{
struct V_23 * V_3 = V_2 -> V_3 ;
struct V_108 V_32 ;
F_20 ( L_1 , V_2 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_65 = F_24 ( V_2 -> V_65 ) ;
V_32 . rand = rand ;
V_32 . V_105 = V_105 ;
memcpy ( V_32 . V_106 , V_106 , V_107 ) ;
F_2 ( V_3 , V_109 , sizeof( V_32 ) , & V_32 ) ;
}
void F_44 ( struct V_1 * V_2 , T_3 V_110 )
{
struct V_1 * V_111 = V_2 -> V_85 ;
if ( ! V_111 )
return;
F_20 ( L_1 , V_2 ) ;
if ( ! V_110 ) {
if ( F_37 ( V_2 -> V_3 ) )
F_34 ( V_111 , V_2 -> V_65 ) ;
else
F_33 ( V_111 , V_2 -> V_65 ) ;
} else {
F_45 ( V_111 , V_110 ) ;
F_46 ( V_111 ) ;
}
}
static void F_47 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_48 ( V_113 , struct V_1 ,
V_114 . V_113 ) ;
int V_115 = F_49 ( & V_2 -> V_115 ) ;
F_20 ( L_2 , V_2 , F_50 ( V_2 -> V_33 ) ) ;
F_51 ( V_115 < 0 ) ;
if ( V_115 > 0 )
return;
switch ( V_2 -> V_33 ) {
case V_34 :
case V_116 :
if ( V_2 -> V_35 ) {
if ( V_2 -> type == V_62 )
F_27 ( V_2 ) ;
else if ( V_2 -> type == V_117 ) {
if ( F_11 ( V_118 , & V_2 -> V_25 ) )
F_18 ( V_2 ) ;
else
F_1 ( V_2 ) ;
}
} else if ( V_2 -> type == V_119 || V_2 -> type == V_120 ) {
F_28 ( V_2 ) ;
}
break;
case V_121 :
case V_122 :
if ( V_2 -> type == V_123 ) {
F_30 ( V_2 ) ;
} else {
T_3 V_58 = F_32 ( V_2 ) ;
F_29 ( V_2 , V_58 ) ;
}
break;
default:
V_2 -> V_33 = V_124 ;
break;
}
}
static void F_52 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_48 ( V_113 , struct V_1 ,
V_125 . V_113 ) ;
struct V_23 * V_3 = V_2 -> V_3 ;
F_20 ( L_3 , V_2 , V_2 -> V_126 ) ;
if ( ! F_53 ( V_3 ) || ! F_53 ( V_2 ) )
return;
if ( V_2 -> V_126 != V_127 || ! ( V_2 -> V_39 & V_128 ) )
return;
if ( F_54 ( V_3 ) && F_54 ( V_2 ) ) {
struct V_129 V_32 ;
V_32 . V_65 = F_24 ( V_2 -> V_65 ) ;
V_32 . V_89 = F_24 ( 0 ) ;
V_32 . V_130 = F_24 ( 0 ) ;
V_32 . V_131 = F_24 ( 0 ) ;
F_2 ( V_3 , V_132 , sizeof( V_32 ) , & V_32 ) ;
}
if ( ! F_55 ( V_133 , & V_2 -> V_25 ) ) {
struct V_134 V_32 ;
V_32 . V_65 = F_24 ( V_2 -> V_65 ) ;
V_32 . V_135 = F_24 ( V_3 -> V_136 ) ;
V_32 . V_137 = F_24 ( V_3 -> V_138 ) ;
V_32 . V_38 = F_24 ( 4 ) ;
V_32 . V_139 = F_24 ( 1 ) ;
F_2 ( V_3 , V_140 , sizeof( V_32 ) , & V_32 ) ;
}
}
static void F_56 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_48 ( V_113 , struct V_1 ,
V_141 . V_113 ) ;
F_2 ( V_2 -> V_3 , V_142 , sizeof( V_2 -> V_11 ) ,
& V_2 -> V_11 ) ;
}
static void F_57 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_48 ( V_113 , struct V_1 ,
F_57 . V_113 ) ;
struct V_23 * V_3 = V_2 -> V_3 ;
F_20 ( L_4 ) ;
if ( V_2 -> V_36 == V_143 ) {
T_2 V_144 = 0x00 ;
F_2 ( V_3 , V_145 , sizeof( V_144 ) ,
& V_144 ) ;
F_58 ( V_2 , V_146 ) ;
return;
}
F_1 ( V_2 ) ;
}
struct V_1 * F_59 ( struct V_23 * V_3 , int type , T_1 * V_11 ,
T_2 V_36 )
{
struct V_1 * V_2 ;
F_20 ( L_5 , V_3 -> V_147 , V_11 ) ;
V_2 = F_60 ( sizeof( * V_2 ) , V_148 ) ;
if ( ! V_2 )
return NULL ;
F_21 ( & V_2 -> V_11 , V_11 ) ;
F_21 ( & V_2 -> V_149 , & V_3 -> V_9 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> type = type ;
V_2 -> V_36 = V_36 ;
V_2 -> V_126 = V_127 ;
V_2 -> V_33 = V_150 ;
V_2 -> V_151 = V_152 ;
V_2 -> V_153 = V_3 -> V_153 ;
V_2 -> V_154 = 0xff ;
V_2 -> V_155 = 0xff ;
V_2 -> V_156 = V_157 ;
V_2 -> V_158 = V_159 ;
V_2 -> V_160 = V_159 ;
F_25 ( V_161 , & V_2 -> V_25 ) ;
V_2 -> V_162 = V_163 ;
if ( V_2 -> V_36 == V_37 )
V_2 -> V_35 = true ;
switch ( type ) {
case V_62 :
V_2 -> V_48 = V_3 -> V_48 & V_164 ;
break;
case V_117 :
F_61 ( V_3 , & V_2 -> V_149 , & V_2 -> V_165 ) ;
break;
case V_119 :
if ( F_37 ( V_3 ) )
V_2 -> V_48 = ( V_3 -> V_166 & V_167 ) |
( V_3 -> V_166 & V_168 ) ;
else
V_2 -> V_48 = V_3 -> V_48 & V_169 ;
break;
case V_120 :
V_2 -> V_48 = V_3 -> V_166 & ~ V_168 ;
break;
}
F_62 ( & V_2 -> V_170 ) ;
F_63 ( & V_2 -> V_171 ) ;
F_64 ( & V_2 -> V_114 , F_47 ) ;
F_64 ( & V_2 -> V_141 , F_56 ) ;
F_64 ( & V_2 -> V_125 , F_52 ) ;
F_64 ( & V_2 -> F_57 , F_57 ) ;
F_65 ( & V_2 -> V_115 , 0 ) ;
F_66 ( V_3 ) ;
F_67 ( V_3 , V_2 ) ;
if ( V_3 -> V_26 )
V_3 -> V_26 ( V_3 , V_172 ) ;
F_68 ( V_2 ) ;
return V_2 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_23 * V_3 = V_2 -> V_3 ;
F_20 ( L_6 , V_3 -> V_147 , V_2 , V_2 -> V_65 ) ;
F_69 ( & V_2 -> V_114 ) ;
F_69 ( & V_2 -> V_141 ) ;
F_69 ( & V_2 -> V_125 ) ;
if ( V_2 -> type == V_62 ) {
struct V_1 * V_111 = V_2 -> V_85 ;
if ( V_111 )
V_111 -> V_85 = NULL ;
V_3 -> V_173 += V_2 -> V_174 ;
} else if ( V_2 -> type == V_117 ) {
F_70 ( & V_2 -> F_57 ) ;
if ( V_3 -> V_175 )
V_3 -> V_176 += V_2 -> V_174 ;
else
V_3 -> V_173 += V_2 -> V_174 ;
} else {
struct V_1 * V_177 = V_2 -> V_85 ;
if ( V_177 ) {
V_177 -> V_85 = NULL ;
F_71 ( V_177 ) ;
}
}
if ( V_2 -> V_178 )
F_72 ( V_2 -> V_178 ) ;
F_73 ( & V_2 -> V_170 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
struct V_23 * F_74 ( T_1 * V_11 , T_1 * V_149 )
{
int V_179 = F_75 ( V_149 , V_180 ) ;
struct V_23 * V_3 = NULL , * V_181 ;
F_20 ( L_7 , V_149 , V_11 ) ;
F_76 ( & V_182 ) ;
F_77 (d, &hci_dev_list, list) {
if ( ! F_11 ( V_183 , & V_181 -> V_25 ) ||
F_78 ( V_181 , V_184 ) ||
V_181 -> V_185 != V_186 )
continue;
if ( V_179 ) {
if ( ! F_75 ( & V_181 -> V_9 , V_149 ) ) {
V_3 = V_181 ; break;
}
} else {
if ( F_75 ( & V_181 -> V_9 , V_11 ) ) {
V_3 = V_181 ; break;
}
}
}
if ( V_3 )
V_3 = F_66 ( V_3 ) ;
F_79 ( & V_182 ) ;
return V_3 ;
}
void F_58 ( struct V_1 * V_2 , T_2 V_110 )
{
struct V_23 * V_3 = V_2 -> V_3 ;
struct V_5 * V_6 ;
V_6 = F_80 ( & V_3 -> V_20 , & V_2 -> V_11 ,
V_2 -> V_12 ) ;
if ( V_6 && V_6 -> V_2 ) {
F_71 ( V_6 -> V_2 ) ;
F_17 ( V_6 -> V_2 ) ;
V_6 -> V_2 = NULL ;
}
V_2 -> V_33 = V_124 ;
F_81 ( V_3 , & V_2 -> V_11 , V_2 -> type , V_2 -> V_12 ,
V_110 ) ;
F_45 ( V_2 , V_110 ) ;
F_46 ( V_2 ) ;
F_9 ( V_3 ) ;
F_82 ( V_3 ) ;
}
static void F_83 ( struct V_23 * V_3 , T_2 V_110 , T_5 V_187 )
{
struct V_1 * V_2 ;
F_40 ( V_3 ) ;
V_2 = F_84 ( V_3 ) ;
if ( ! V_110 ) {
F_3 ( V_2 ) ;
goto V_188;
}
F_85 ( L_8 ,
V_110 ) ;
if ( ! V_2 )
goto V_188;
F_58 ( V_2 , V_110 ) ;
V_188:
F_42 ( V_3 ) ;
}
static void F_86 ( struct V_189 * V_190 ,
struct V_1 * V_2 )
{
struct V_191 V_32 ;
struct V_23 * V_3 = V_2 -> V_3 ;
T_2 V_192 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
if ( F_87 ( V_190 , false , & V_192 ) )
return;
V_32 . V_193 = F_24 ( V_3 -> V_194 ) ;
V_32 . V_195 = F_24 ( V_3 -> V_196 ) ;
F_21 ( & V_32 . V_197 , & V_2 -> V_11 ) ;
V_32 . V_198 = V_2 -> V_12 ;
V_32 . V_199 = V_192 ;
V_32 . V_100 = F_24 ( V_2 -> V_200 ) ;
V_32 . V_101 = F_24 ( V_2 -> V_201 ) ;
V_32 . V_98 = F_24 ( V_2 -> V_202 ) ;
V_32 . V_99 = F_24 ( V_2 -> V_203 ) ;
V_32 . V_102 = F_24 ( 0x0000 ) ;
V_32 . V_103 = F_24 ( 0x0000 ) ;
F_88 ( V_190 , V_204 , sizeof( V_32 ) , & V_32 ) ;
V_2 -> V_33 = V_34 ;
F_89 ( V_118 , & V_2 -> V_25 ) ;
}
static void F_90 ( struct V_189 * V_190 ,
struct V_1 * V_2 )
{
struct V_23 * V_3 = V_190 -> V_3 ;
struct V_205 V_32 ;
T_2 V_192 ;
T_2 V_144 ;
F_91 ( V_3 , V_206 ) ;
if ( F_87 ( V_190 , false , & V_192 ) < 0 )
return;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . type = V_207 ;
V_32 . V_199 = V_192 ;
V_32 . V_208 = V_2 -> V_12 ;
F_21 ( & V_32 . V_209 , & V_2 -> V_11 ) ;
V_32 . V_210 = V_3 -> V_211 ;
F_88 ( V_190 , V_212 , sizeof( V_32 ) , & V_32 ) ;
V_144 = 0x01 ;
F_88 ( V_190 , V_145 , sizeof( V_144 ) , & V_144 ) ;
V_2 -> V_33 = V_34 ;
}
struct V_1 * F_92 ( struct V_23 * V_3 , T_1 * V_11 ,
T_2 V_12 , T_2 V_213 , T_5 V_214 ,
T_2 V_36 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 , * V_215 ;
struct V_7 * V_8 ;
struct V_189 V_190 ;
int V_216 ;
if ( ! F_78 ( V_3 , V_217 ) ) {
if ( F_93 ( V_3 ) )
return F_94 ( - V_218 ) ;
return F_94 ( - V_219 ) ;
}
V_2 = F_95 ( V_3 , V_117 , V_11 ) ;
V_215 = NULL ;
if ( V_2 ) {
if ( V_2 -> V_33 == V_34 &&
F_11 ( V_118 , & V_2 -> V_25 ) ) {
F_20 ( L_9 , V_11 ) ;
V_215 = V_2 ;
} else {
if ( V_2 -> V_220 < V_213 )
V_2 -> V_220 = V_213 ;
goto V_188;
}
}
if ( F_84 ( V_3 ) )
return F_94 ( - V_221 ) ;
V_8 = F_96 ( V_3 , V_11 , V_12 ) ;
if ( V_8 && F_75 ( & V_8 -> V_222 , V_180 ) ) {
V_11 = & V_8 -> V_222 ;
V_12 = V_223 ;
}
if ( V_215 ) {
V_2 = V_215 ;
F_21 ( & V_2 -> V_11 , V_11 ) ;
} else {
V_2 = F_59 ( V_3 , V_117 , V_11 , V_36 ) ;
}
if ( ! V_2 )
return F_94 ( - V_224 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_213 = V_225 ;
V_2 -> V_214 = V_214 ;
if ( ! V_215 )
V_2 -> V_220 = V_213 ;
F_97 ( & V_190 , V_3 ) ;
if ( F_78 ( V_3 , V_206 ) ) {
T_2 V_144 = 0x00 ;
F_88 ( & V_190 , V_145 , sizeof( V_144 ) ,
& V_144 ) ;
}
if ( V_2 -> V_36 == V_143 ) {
if ( F_78 ( V_3 , V_226 ) &&
V_3 -> V_227 == V_228 ) {
F_73 ( & V_190 . V_229 ) ;
F_46 ( V_2 ) ;
return F_94 ( - V_221 ) ;
}
F_90 ( & V_190 , V_2 ) ;
goto V_230;
}
V_6 = F_41 ( V_3 , & V_2 -> V_11 , V_2 -> V_12 ) ;
if ( V_6 ) {
V_2 -> V_200 = V_6 -> V_96 ;
V_2 -> V_201 = V_6 -> V_97 ;
V_2 -> V_202 = V_6 -> V_98 ;
V_2 -> V_203 = V_6 -> V_99 ;
} else {
V_2 -> V_200 = V_3 -> V_200 ;
V_2 -> V_201 = V_3 -> V_201 ;
V_2 -> V_202 = V_3 -> V_202 ;
V_2 -> V_203 = V_3 -> V_203 ;
}
if ( F_78 ( V_3 , V_226 ) ) {
F_98 ( & V_190 ) ;
F_99 ( V_3 , V_231 ) ;
}
F_86 ( & V_190 , V_2 ) ;
V_230:
V_216 = F_100 ( & V_190 , F_83 ) ;
if ( V_216 ) {
F_46 ( V_2 ) ;
return F_94 ( V_216 ) ;
}
V_188:
if ( ! V_215 )
F_101 ( V_2 ) ;
return V_2 ;
}
static void F_102 ( struct V_23 * V_3 , T_2 V_110 ,
T_5 V_187 )
{
struct V_1 * V_2 ;
if ( ! V_110 )
return;
F_85 ( L_10 ,
V_110 ) ;
F_40 ( V_3 ) ;
V_2 = F_103 ( V_3 , V_117 , V_34 ) ;
if ( V_2 )
F_58 ( V_2 , V_110 ) ;
F_42 ( V_3 ) ;
}
static bool F_104 ( struct V_23 * V_3 , T_1 * V_232 , T_2 type )
{
struct V_1 * V_2 ;
V_2 = F_95 ( V_3 , V_117 , V_232 ) ;
if ( ! V_2 )
return false ;
if ( V_2 -> V_12 != type )
return false ;
if ( V_2 -> V_33 != V_122 )
return false ;
return true ;
}
static int F_105 ( struct V_189 * V_190 ,
T_1 * V_232 , T_2 V_13 )
{
struct V_23 * V_3 = V_190 -> V_3 ;
struct V_5 * V_6 ;
if ( F_104 ( V_3 , V_232 , V_13 ) )
return - V_233 ;
V_6 = F_41 ( V_3 , V_232 , V_13 ) ;
if ( ! V_6 ) {
V_6 = F_106 ( V_3 , V_232 , V_13 ) ;
if ( ! V_6 )
return - V_224 ;
V_6 -> V_16 = V_17 ;
}
if ( V_6 -> V_16 == V_234 ||
V_6 -> V_16 == V_21 ||
V_6 -> V_16 == V_17 ) {
F_6 ( & V_6 -> V_15 ) ;
F_8 ( & V_6 -> V_15 , & V_3 -> V_20 ) ;
}
V_6 -> V_14 = true ;
F_107 ( V_190 ) ;
F_20 ( L_11 , V_232 , V_13 ,
V_6 -> V_16 ) ;
return 0 ;
}
struct V_1 * F_108 ( struct V_23 * V_3 , T_1 * V_11 ,
T_2 V_12 , T_2 V_213 ,
T_5 V_214 , T_2 V_36 )
{
struct V_1 * V_2 ;
struct V_189 V_190 ;
int V_216 ;
if ( ! F_78 ( V_3 , V_217 ) ) {
if ( F_93 ( V_3 ) )
return F_94 ( - V_218 ) ;
return F_94 ( - V_219 ) ;
}
V_2 = F_95 ( V_3 , V_117 , V_11 ) ;
if ( V_2 ) {
if ( V_2 -> V_220 < V_213 )
V_2 -> V_220 = V_213 ;
goto V_188;
}
F_20 ( L_12 ) ;
V_2 = F_59 ( V_3 , V_117 , V_11 , V_36 ) ;
if ( ! V_2 )
return F_94 ( - V_224 ) ;
F_97 ( & V_190 , V_3 ) ;
if ( F_105 ( & V_190 , V_11 , V_12 ) < 0 )
return F_94 ( - V_221 ) ;
V_2 -> V_33 = V_34 ;
F_25 ( V_118 , & V_2 -> V_25 ) ;
V_216 = F_100 ( & V_190 , F_102 ) ;
if ( V_216 && V_216 != - V_235 ) {
F_46 ( V_2 ) ;
return F_94 ( V_216 ) ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_213 = V_225 ;
V_2 -> V_220 = V_213 ;
V_2 -> V_214 = V_214 ;
V_188:
F_101 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_109 ( struct V_23 * V_3 , T_1 * V_11 ,
T_2 V_213 , T_2 V_151 )
{
struct V_1 * V_177 ;
if ( ! F_78 ( V_3 , V_236 ) ) {
if ( F_110 ( V_3 ) )
return F_94 ( - V_218 ) ;
return F_94 ( - V_219 ) ;
}
V_177 = F_95 ( V_3 , V_62 , V_11 ) ;
if ( ! V_177 ) {
V_177 = F_59 ( V_3 , V_62 , V_11 , V_37 ) ;
if ( ! V_177 )
return F_94 ( - V_224 ) ;
}
F_101 ( V_177 ) ;
if ( V_177 -> V_33 == V_150 || V_177 -> V_33 == V_124 ) {
V_177 -> V_213 = V_225 ;
V_177 -> V_220 = V_213 ;
V_177 -> V_151 = V_151 ;
F_19 ( V_177 ) ;
}
return V_177 ;
}
struct V_1 * F_111 ( struct V_23 * V_3 , int type , T_1 * V_11 ,
T_4 V_80 )
{
struct V_1 * V_177 ;
struct V_1 * V_111 ;
V_177 = F_109 ( V_3 , V_11 , V_225 , V_237 ) ;
if ( F_112 ( V_177 ) )
return V_177 ;
V_111 = F_95 ( V_3 , type , V_11 ) ;
if ( ! V_111 ) {
V_111 = F_59 ( V_3 , type , V_11 , V_37 ) ;
if ( ! V_111 ) {
F_71 ( V_177 ) ;
return F_94 ( - V_224 ) ;
}
}
V_177 -> V_85 = V_111 ;
V_111 -> V_85 = V_177 ;
F_101 ( V_111 ) ;
V_111 -> V_80 = V_80 ;
if ( V_177 -> V_33 == V_122 &&
( V_111 -> V_33 == V_150 || V_111 -> V_33 == V_124 ) ) {
F_25 ( V_161 , & V_177 -> V_25 ) ;
F_113 ( V_177 , V_238 ) ;
if ( F_11 ( V_133 , & V_177 -> V_25 ) ) {
F_25 ( V_239 , & V_177 -> V_25 ) ;
return V_111 ;
}
F_44 ( V_177 , 0x00 ) ;
}
return V_111 ;
}
int F_114 ( struct V_1 * V_2 )
{
F_20 ( L_1 , V_2 ) ;
if ( F_78 ( V_2 -> V_3 , V_240 ) ) {
if ( ! F_115 ( V_2 ) ||
! F_11 ( V_241 , & V_2 -> V_25 ) ||
V_2 -> V_155 != V_242 )
return 0 ;
}
if ( F_116 ( V_2 ) &&
! F_11 ( V_243 , & V_2 -> V_25 ) )
return 0 ;
return 1 ;
}
static int F_117 ( struct V_1 * V_2 , T_3 V_213 , T_3 V_151 )
{
F_20 ( L_1 , V_2 ) ;
if ( V_2 -> V_220 > V_213 )
V_213 = V_2 -> V_220 ;
if ( V_213 > V_2 -> V_213 )
V_2 -> V_220 = V_213 ;
else if ( F_11 ( V_244 , & V_2 -> V_25 ) )
return 1 ;
V_151 |= ( V_2 -> V_151 & 0x01 ) ;
V_2 -> V_151 = V_151 ;
if ( ! F_55 ( V_245 , & V_2 -> V_25 ) ) {
struct V_246 V_32 ;
V_32 . V_65 = F_24 ( V_2 -> V_65 ) ;
F_2 ( V_2 -> V_3 , V_247 ,
sizeof( V_32 ) , & V_32 ) ;
if ( F_11 ( V_243 , & V_2 -> V_25 ) )
F_25 ( V_248 , & V_2 -> V_25 ) ;
else
F_25 ( V_249 , & V_2 -> V_25 ) ;
}
return 0 ;
}
static void F_118 ( struct V_1 * V_2 )
{
F_20 ( L_1 , V_2 ) ;
if ( ! F_55 ( V_249 , & V_2 -> V_25 ) ) {
struct V_250 V_32 ;
V_32 . V_65 = F_24 ( V_2 -> V_65 ) ;
V_32 . V_251 = 0x01 ;
F_2 ( V_2 -> V_3 , V_252 , sizeof( V_32 ) ,
& V_32 ) ;
}
}
int F_119 ( struct V_1 * V_2 , T_3 V_213 , T_3 V_151 ,
bool V_253 )
{
F_20 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_117 )
return F_120 ( V_2 , V_213 ) ;
if ( V_213 == V_254 )
return 1 ;
if ( V_213 == V_225 && ! F_116 ( V_2 ) )
return 1 ;
if ( ! F_11 ( V_244 , & V_2 -> V_25 ) )
goto V_255;
if ( V_2 -> V_155 == V_242 &&
V_213 == V_256 )
goto V_251;
if ( ( V_2 -> V_155 == V_257 ||
V_2 -> V_155 == V_242 ) &&
V_213 == V_258 )
goto V_251;
if ( ( V_2 -> V_155 == V_259 ||
V_2 -> V_155 == V_260 ) &&
( V_213 == V_261 || V_213 == V_225 ) )
goto V_251;
if ( V_2 -> V_155 == V_262 &&
( V_213 == V_261 || V_213 == V_225 ||
V_2 -> V_263 == 16 ) )
goto V_251;
V_255:
if ( F_11 ( V_249 , & V_2 -> V_25 ) )
return 0 ;
if ( V_253 )
F_25 ( V_264 , & V_2 -> V_25 ) ;
if ( ! F_117 ( V_2 , V_213 , V_151 ) )
return 0 ;
V_251:
if ( F_11 ( V_243 , & V_2 -> V_25 ) )
return 1 ;
F_118 ( V_2 ) ;
return 0 ;
}
int F_121 ( struct V_1 * V_2 , T_3 V_213 )
{
F_20 ( L_1 , V_2 ) ;
if ( V_213 != V_258 && V_213 != V_256 )
return 1 ;
if ( V_2 -> V_213 == V_258 ||
V_2 -> V_213 == V_256 )
return 1 ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_3 V_36 )
{
F_20 ( L_1 , V_2 ) ;
if ( V_36 == V_2 -> V_36 )
return 1 ;
if ( ! F_55 ( V_265 , & V_2 -> V_25 ) ) {
struct V_266 V_32 ;
F_21 ( & V_32 . V_9 , & V_2 -> V_11 ) ;
V_32 . V_36 = V_36 ;
F_2 ( V_2 -> V_3 , V_267 , sizeof( V_32 ) , & V_32 ) ;
}
return 0 ;
}
void F_113 ( struct V_1 * V_2 , T_3 V_268 )
{
struct V_23 * V_3 = V_2 -> V_3 ;
F_20 ( L_3 , V_2 , V_2 -> V_126 ) ;
if ( V_2 -> V_126 != V_269 )
goto V_270;
if ( ! F_11 ( V_161 , & V_2 -> V_25 ) && ! V_268 )
goto V_270;
if ( ! F_55 ( V_133 , & V_2 -> V_25 ) ) {
struct V_271 V_32 ;
V_32 . V_65 = F_24 ( V_2 -> V_65 ) ;
F_2 ( V_3 , V_272 , sizeof( V_32 ) , & V_32 ) ;
}
V_270:
if ( V_3 -> V_273 > 0 )
F_123 ( V_3 -> V_274 , & V_2 -> V_125 ,
F_124 ( V_3 -> V_273 ) ) ;
}
void F_125 ( struct V_23 * V_3 )
{
struct V_275 * V_276 = & V_3 -> V_277 ;
struct V_1 * V_278 , * V_279 ;
F_20 ( L_13 , V_3 -> V_147 ) ;
F_126 (c, n, &h->list, list) {
V_278 -> V_33 = V_124 ;
F_127 ( V_278 , V_280 ) ;
F_46 ( V_278 ) ;
}
}
void F_128 ( struct V_23 * V_3 )
{
struct V_1 * V_2 ;
F_20 ( L_13 , V_3 -> V_147 ) ;
F_40 ( V_3 ) ;
V_2 = F_103 ( V_3 , V_62 , V_116 ) ;
if ( V_2 )
F_19 ( V_2 ) ;
F_42 ( V_3 ) ;
}
static T_8 F_129 ( struct V_1 * V_2 )
{
T_8 V_49 = 0 ;
if ( V_2 -> V_36 == V_37 )
V_49 |= V_50 ;
if ( F_11 ( V_243 , & V_2 -> V_25 ) )
V_49 |= V_281 ;
if ( F_11 ( V_244 , & V_2 -> V_25 ) )
V_49 |= V_282 ;
if ( F_11 ( V_283 , & V_2 -> V_25 ) )
V_49 |= V_284 ;
if ( F_11 ( V_285 , & V_2 -> V_25 ) )
V_49 |= V_286 ;
return V_49 ;
}
int F_130 ( void T_9 * V_287 )
{
struct V_1 * V_278 ;
struct V_288 V_190 , * V_289 ;
struct V_290 * V_291 ;
struct V_23 * V_3 ;
int V_279 = 0 , V_292 , V_216 ;
if ( F_131 ( & V_190 , V_287 , sizeof( V_190 ) ) )
return - V_293 ;
if ( ! V_190 . V_294 || V_190 . V_294 > ( V_295 * 2 ) / sizeof( * V_291 ) )
return - V_296 ;
V_292 = sizeof( V_190 ) + V_190 . V_294 * sizeof( * V_291 ) ;
V_289 = F_132 ( V_292 , V_148 ) ;
if ( ! V_289 )
return - V_224 ;
V_3 = F_133 ( V_190 . V_297 ) ;
if ( ! V_3 ) {
F_134 ( V_289 ) ;
return - V_298 ;
}
V_291 = V_289 -> V_299 ;
F_40 ( V_3 ) ;
F_77 (c, &hdev->conn_hash.list, list) {
F_21 ( & ( V_291 + V_279 ) -> V_9 , & V_278 -> V_11 ) ;
( V_291 + V_279 ) -> V_65 = V_278 -> V_65 ;
( V_291 + V_279 ) -> type = V_278 -> type ;
( V_291 + V_279 ) -> V_35 = V_278 -> V_35 ;
( V_291 + V_279 ) -> V_33 = V_278 -> V_33 ;
( V_291 + V_279 ) -> V_49 = F_129 ( V_278 ) ;
if ( ++ V_279 >= V_190 . V_294 )
break;
}
F_42 ( V_3 ) ;
V_289 -> V_297 = V_3 -> V_300 ;
V_289 -> V_294 = V_279 ;
V_292 = sizeof( V_190 ) + V_279 * sizeof( * V_291 ) ;
F_16 ( V_3 ) ;
V_216 = F_135 ( V_287 , V_289 , V_292 ) ;
F_134 ( V_289 ) ;
return V_216 ? - V_293 : 0 ;
}
int F_136 ( struct V_23 * V_3 , void T_9 * V_287 )
{
struct V_301 V_190 ;
struct V_290 V_291 ;
struct V_1 * V_2 ;
char T_9 * V_302 = V_287 + sizeof( V_190 ) ;
if ( F_131 ( & V_190 , V_287 , sizeof( V_190 ) ) )
return - V_293 ;
F_40 ( V_3 ) ;
V_2 = F_95 ( V_3 , V_190 . type , & V_190 . V_9 ) ;
if ( V_2 ) {
F_21 ( & V_291 . V_9 , & V_2 -> V_11 ) ;
V_291 . V_65 = V_2 -> V_65 ;
V_291 . type = V_2 -> type ;
V_291 . V_35 = V_2 -> V_35 ;
V_291 . V_33 = V_2 -> V_33 ;
V_291 . V_49 = F_129 ( V_2 ) ;
}
F_42 ( V_3 ) ;
if ( ! V_2 )
return - V_303 ;
return F_135 ( V_302 , & V_291 , sizeof( V_291 ) ) ? - V_293 : 0 ;
}
int F_137 ( struct V_23 * V_3 , void T_9 * V_287 )
{
struct V_304 V_190 ;
struct V_1 * V_2 ;
if ( F_131 ( & V_190 , V_287 , sizeof( V_190 ) ) )
return - V_293 ;
F_40 ( V_3 ) ;
V_2 = F_95 ( V_3 , V_62 , & V_190 . V_9 ) ;
if ( V_2 )
V_190 . type = V_2 -> V_151 ;
F_42 ( V_3 ) ;
if ( ! V_2 )
return - V_303 ;
return F_135 ( V_287 , & V_190 , sizeof( V_190 ) ) ? - V_293 : 0 ;
}
struct V_305 * F_138 ( struct V_1 * V_2 )
{
struct V_23 * V_3 = V_2 -> V_3 ;
struct V_305 * V_306 ;
F_20 ( L_14 , V_3 -> V_147 , V_2 ) ;
if ( F_11 ( V_307 , & V_2 -> V_25 ) ) {
F_20 ( L_15 ) ;
return NULL ;
}
V_306 = F_60 ( sizeof( * V_306 ) , V_148 ) ;
if ( ! V_306 )
return NULL ;
V_306 -> V_2 = F_139 ( V_2 ) ;
F_62 ( & V_306 -> V_170 ) ;
V_306 -> V_33 = V_122 ;
F_140 ( & V_306 -> V_308 , & V_2 -> V_171 ) ;
return V_306 ;
}
void F_141 ( struct V_305 * V_306 )
{
struct V_1 * V_2 = V_306 -> V_2 ;
struct V_23 * V_3 = V_2 -> V_3 ;
F_20 ( L_16 , V_3 -> V_147 , V_2 , V_306 ) ;
F_142 ( & V_306 -> V_308 ) ;
F_143 () ;
F_25 ( V_307 , & V_2 -> V_25 ) ;
F_17 ( V_2 ) ;
F_73 ( & V_306 -> V_170 ) ;
F_134 ( V_306 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_305 * V_306 , * V_279 ;
F_20 ( L_1 , V_2 ) ;
F_126 (chan, n, &conn->chan_list, list)
F_141 ( V_306 ) ;
}
static struct V_305 * F_144 ( struct V_1 * V_309 ,
T_4 V_65 )
{
struct V_305 * V_310 ;
F_77 (hchan, &hcon->chan_list, list) {
if ( V_310 -> V_65 == V_65 )
return V_310 ;
}
return NULL ;
}
struct V_305 * F_145 ( struct V_23 * V_3 , T_4 V_65 )
{
struct V_275 * V_276 = & V_3 -> V_277 ;
struct V_1 * V_309 ;
struct V_305 * V_310 = NULL ;
F_146 () ;
F_147 (hcon, &h->list, list) {
V_310 = F_144 ( V_309 , V_65 ) ;
if ( V_310 )
break;
}
F_148 () ;
return V_310 ;
}
