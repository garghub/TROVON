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
struct V_43 V_9 ;
V_9 . V_44 = F_8 ( V_2 -> V_44 ) ;
F_2 ( V_3 , V_45 , sizeof( V_9 ) , & V_9 ) ;
}
V_2 -> V_10 = V_46 ;
V_9 . V_44 = F_8 ( V_2 -> V_44 ) ;
V_9 . V_38 = V_38 ;
return F_2 ( V_2 -> V_3 , V_47 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_48 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_46 ;
V_9 . V_49 = F_15 ( V_2 -> V_44 ) ;
V_9 . V_38 = F_16 ( V_2 ) ;
F_2 ( V_2 -> V_3 , V_50 ,
sizeof( V_9 ) , & V_9 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_2 V_44 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_51 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_44 = F_8 ( V_44 ) ;
V_9 . V_28 = F_8 ( V_2 -> V_28 ) ;
F_2 ( V_3 , V_52 , sizeof( V_9 ) , & V_9 ) ;
}
bool F_18 ( struct V_1 * V_2 , T_2 V_44 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_53 V_9 ;
const struct V_54 * V_55 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_44 = F_8 ( V_44 ) ;
V_9 . V_56 = F_19 ( 0x00001f40 ) ;
V_9 . V_57 = F_19 ( 0x00001f40 ) ;
V_9 . V_58 = F_8 ( V_2 -> V_59 ) ;
switch ( V_2 -> V_59 & V_60 ) {
case V_61 :
if ( V_2 -> V_15 > F_20 ( V_62 ) )
return false ;
V_55 = & V_62 [ V_2 -> V_15 - 1 ] ;
break;
case V_63 :
if ( F_21 ( V_2 -> V_64 ) ) {
if ( V_2 -> V_15 > F_20 ( V_65 ) )
return false ;
V_55 = & V_65 [ V_2 -> V_15 - 1 ] ;
} else {
if ( V_2 -> V_15 > F_20 ( V_66 ) )
return false ;
V_55 = & V_66 [ V_2 -> V_15 - 1 ] ;
}
break;
default:
return false ;
}
V_9 . V_67 = V_55 -> V_67 ;
V_9 . V_28 = F_22 ( V_55 -> V_28 ) ;
V_9 . V_68 = F_22 ( V_55 -> V_68 ) ;
if ( F_2 ( V_3 , V_69 , sizeof( V_9 ) , & V_9 ) < 0 )
return false ;
return true ;
}
T_3 F_23 ( struct V_1 * V_2 , T_4 V_70 , T_4 V_71 , T_4 V_72 ,
T_4 V_73 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_74 * V_75 ;
struct V_76 V_9 ;
F_24 ( V_3 ) ;
V_75 = F_25 ( V_3 , & V_2 -> V_18 , V_2 -> V_77 ) ;
if ( V_75 ) {
V_75 -> V_78 = V_70 ;
V_75 -> V_79 = V_71 ;
V_75 -> V_80 = V_72 ;
V_75 -> V_81 = V_73 ;
}
F_26 ( V_3 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_44 = F_8 ( V_2 -> V_44 ) ;
V_9 . V_82 = F_8 ( V_70 ) ;
V_9 . V_83 = F_8 ( V_71 ) ;
V_9 . V_80 = F_8 ( V_72 ) ;
V_9 . V_81 = F_8 ( V_73 ) ;
V_9 . V_84 = F_8 ( 0x0000 ) ;
V_9 . V_85 = F_8 ( 0x0000 ) ;
F_2 ( V_3 , V_86 , sizeof( V_9 ) , & V_9 ) ;
if ( V_75 )
return 0x01 ;
return 0x00 ;
}
void F_27 ( struct V_1 * V_2 , T_5 V_87 , T_6 rand ,
T_1 V_88 [ 16 ] )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_89 V_9 ;
F_4 ( L_1 , V_2 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_44 = F_8 ( V_2 -> V_44 ) ;
V_9 . rand = rand ;
V_9 . V_87 = V_87 ;
memcpy ( V_9 . V_88 , V_88 , sizeof( V_9 . V_88 ) ) ;
F_2 ( V_3 , V_90 , sizeof( V_9 ) , & V_9 ) ;
}
void F_28 ( struct V_1 * V_2 , T_1 V_91 )
{
struct V_1 * V_92 = V_2 -> V_64 ;
if ( ! V_92 )
return;
F_4 ( L_1 , V_2 ) ;
if ( ! V_91 ) {
if ( F_21 ( V_2 -> V_3 ) )
F_18 ( V_92 , V_2 -> V_44 ) ;
else
F_17 ( V_92 , V_2 -> V_44 ) ;
} else {
F_29 ( V_92 , V_91 ) ;
F_30 ( V_92 ) ;
}
}
static void F_31 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_32 ( V_94 , struct V_1 ,
V_95 . V_94 ) ;
int V_96 = F_33 ( & V_2 -> V_96 ) ;
F_4 ( L_2 , V_2 , F_34 ( V_2 -> V_10 ) ) ;
F_35 ( V_96 < 0 ) ;
if ( V_96 > 0 )
return;
switch ( V_2 -> V_10 ) {
case V_11 :
case V_97 :
if ( V_2 -> V_12 ) {
if ( V_2 -> type == V_42 )
F_11 ( V_2 ) ;
else if ( V_2 -> type == V_98 )
F_1 ( V_2 ) ;
} else if ( V_2 -> type == V_99 || V_2 -> type == V_100 ) {
F_12 ( V_2 ) ;
}
break;
case V_101 :
case V_102 :
if ( V_2 -> type == V_103 ) {
F_14 ( V_2 ) ;
} else {
T_1 V_38 = F_16 ( V_2 ) ;
F_13 ( V_2 , V_38 ) ;
}
break;
default:
V_2 -> V_10 = V_104 ;
break;
}
}
static void F_36 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_32 ( V_94 , struct V_1 ,
V_105 . V_94 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_106 ) ;
if ( ! F_37 ( V_3 ) || ! F_37 ( V_2 ) )
return;
if ( V_2 -> V_106 != V_107 || ! ( V_2 -> V_16 & V_108 ) )
return;
if ( F_38 ( V_3 ) && F_38 ( V_2 ) ) {
struct V_109 V_9 ;
V_9 . V_44 = F_8 ( V_2 -> V_44 ) ;
V_9 . V_68 = F_8 ( 0 ) ;
V_9 . V_110 = F_8 ( 0 ) ;
V_9 . V_111 = F_8 ( 0 ) ;
F_2 ( V_3 , V_112 , sizeof( V_9 ) , & V_9 ) ;
}
if ( ! F_39 ( V_113 , & V_2 -> V_27 ) ) {
struct V_114 V_9 ;
V_9 . V_44 = F_8 ( V_2 -> V_44 ) ;
V_9 . V_115 = F_8 ( V_3 -> V_116 ) ;
V_9 . V_117 = F_8 ( V_3 -> V_118 ) ;
V_9 . V_15 = F_8 ( 4 ) ;
V_9 . V_119 = F_8 ( 1 ) ;
F_2 ( V_3 , V_120 , sizeof( V_9 ) , & V_9 ) ;
}
}
static void F_40 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_32 ( V_94 , struct V_1 ,
V_121 . V_94 ) ;
F_2 ( V_2 -> V_3 , V_122 , sizeof( V_2 -> V_18 ) ,
& V_2 -> V_18 ) ;
}
static void F_41 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_32 ( V_94 , struct V_1 ,
F_41 . V_94 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_4 ) ;
if ( F_42 ( V_123 , & V_3 -> V_124 ) ) {
T_3 V_125 = 0x00 ;
F_2 ( V_3 , V_126 , sizeof( V_125 ) ,
& V_125 ) ;
F_43 ( V_2 , V_127 ) ;
return;
}
F_1 ( V_2 ) ;
}
struct V_1 * F_44 ( struct V_5 * V_3 , int type , T_7 * V_18 ,
T_3 V_13 )
{
struct V_1 * V_2 ;
F_4 ( L_5 , V_3 -> V_128 , V_18 ) ;
V_2 = F_45 ( sizeof( * V_2 ) , V_129 ) ;
if ( ! V_2 )
return NULL ;
F_5 ( & V_2 -> V_18 , V_18 ) ;
F_5 ( & V_2 -> V_130 , & V_3 -> V_17 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> type = type ;
V_2 -> V_13 = V_13 ;
V_2 -> V_106 = V_107 ;
V_2 -> V_10 = V_131 ;
V_2 -> V_132 = V_133 ;
V_2 -> V_134 = V_3 -> V_134 ;
V_2 -> V_135 = 0xff ;
V_2 -> V_136 = 0xff ;
V_2 -> V_137 = V_138 ;
V_2 -> V_139 = V_138 ;
F_9 ( V_140 , & V_2 -> V_27 ) ;
V_2 -> V_141 = V_142 ;
if ( V_2 -> V_13 == V_14 )
V_2 -> V_12 = true ;
switch ( type ) {
case V_42 :
V_2 -> V_28 = V_3 -> V_28 & V_143 ;
break;
case V_98 :
F_46 ( V_3 , & V_2 -> V_130 , & V_2 -> V_144 ) ;
break;
case V_99 :
if ( F_21 ( V_3 ) )
V_2 -> V_28 = ( V_3 -> V_145 & V_146 ) |
( V_3 -> V_145 & V_147 ) ;
else
V_2 -> V_28 = V_3 -> V_28 & V_148 ;
break;
case V_100 :
V_2 -> V_28 = V_3 -> V_145 & ~ V_147 ;
break;
}
F_47 ( & V_2 -> V_149 ) ;
F_48 ( & V_2 -> V_150 ) ;
F_49 ( & V_2 -> V_95 , F_31 ) ;
F_49 ( & V_2 -> V_121 , F_40 ) ;
F_49 ( & V_2 -> V_105 , F_36 ) ;
F_49 ( & V_2 -> F_41 , F_41 ) ;
F_50 ( & V_2 -> V_96 , 0 ) ;
F_51 ( V_3 ) ;
F_52 ( V_3 , V_2 ) ;
if ( V_3 -> V_151 )
V_3 -> V_151 ( V_3 , V_152 ) ;
F_53 ( V_2 ) ;
return V_2 ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_6 , V_3 -> V_128 , V_2 , V_2 -> V_44 ) ;
F_54 ( & V_2 -> V_95 ) ;
F_54 ( & V_2 -> V_121 ) ;
F_54 ( & V_2 -> V_105 ) ;
if ( V_2 -> type == V_42 ) {
struct V_1 * V_92 = V_2 -> V_64 ;
if ( V_92 )
V_92 -> V_64 = NULL ;
V_3 -> V_153 += V_2 -> V_154 ;
} else if ( V_2 -> type == V_98 ) {
F_54 ( & V_2 -> F_41 ) ;
if ( V_3 -> V_155 )
V_3 -> V_156 += V_2 -> V_154 ;
else
V_3 -> V_153 += V_2 -> V_154 ;
} else {
struct V_1 * V_157 = V_2 -> V_64 ;
if ( V_157 ) {
V_157 -> V_64 = NULL ;
F_55 ( V_157 ) ;
}
}
F_56 ( V_2 ) ;
if ( V_2 -> V_158 )
F_57 ( V_2 -> V_158 ) ;
F_58 ( V_3 , V_2 ) ;
if ( V_3 -> V_151 )
V_3 -> V_151 ( V_3 , V_159 ) ;
F_59 ( & V_2 -> V_149 ) ;
F_60 ( V_2 ) ;
F_61 ( V_3 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
struct V_5 * F_63 ( T_7 * V_18 , T_7 * V_130 )
{
int V_160 = F_64 ( V_130 , V_161 ) ;
struct V_5 * V_3 = NULL , * V_162 ;
F_4 ( L_7 , V_130 , V_18 ) ;
F_65 ( & V_163 ) ;
F_66 (d, &hci_dev_list, list) {
if ( ! F_42 ( V_164 , & V_162 -> V_27 ) ||
F_42 ( V_165 , & V_162 -> V_124 ) ||
V_162 -> V_166 != V_167 )
continue;
if ( V_160 ) {
if ( ! F_64 ( & V_162 -> V_17 , V_130 ) ) {
V_3 = V_162 ; break;
}
} else {
if ( F_64 ( & V_162 -> V_17 , V_18 ) ) {
V_3 = V_162 ; break;
}
}
}
if ( V_3 )
V_3 = F_51 ( V_3 ) ;
F_67 ( & V_163 ) ;
return V_3 ;
}
void F_43 ( struct V_1 * V_2 , T_3 V_91 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_74 * V_75 ;
V_75 = F_68 ( & V_3 -> V_168 , & V_2 -> V_18 ,
V_2 -> V_77 ) ;
if ( V_75 && V_75 -> V_2 ) {
F_55 ( V_75 -> V_2 ) ;
F_62 ( V_75 -> V_2 ) ;
V_75 -> V_2 = NULL ;
}
V_2 -> V_10 = V_104 ;
F_69 ( V_3 , & V_2 -> V_18 , V_2 -> type , V_2 -> V_77 ,
V_91 ) ;
F_29 ( V_2 , V_91 ) ;
F_30 ( V_2 ) ;
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
}
static void F_72 ( struct V_5 * V_3 , T_3 V_91 )
{
struct V_1 * V_2 ;
if ( V_91 == 0 )
return;
F_73 ( L_8 ,
V_91 ) ;
F_24 ( V_3 ) ;
V_2 = F_74 ( V_3 , V_98 , V_11 ) ;
if ( ! V_2 )
goto V_169;
F_43 ( V_2 , V_91 ) ;
V_169:
F_26 ( V_3 ) ;
}
static void F_75 ( struct V_170 * V_171 ,
struct V_1 * V_2 )
{
struct V_172 V_9 ;
struct V_5 * V_3 = V_2 -> V_3 ;
T_3 V_173 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
if ( F_76 ( V_171 , false , & V_173 ) )
return;
V_9 . V_174 = F_8 ( V_3 -> V_175 ) ;
V_9 . V_176 = F_8 ( V_3 -> V_177 ) ;
F_5 ( & V_9 . V_178 , & V_2 -> V_18 ) ;
V_9 . V_179 = V_2 -> V_77 ;
V_9 . V_180 = V_173 ;
V_9 . V_82 = F_8 ( V_2 -> V_181 ) ;
V_9 . V_83 = F_8 ( V_2 -> V_182 ) ;
V_9 . V_80 = F_8 ( V_2 -> V_183 ) ;
V_9 . V_81 = F_8 ( V_2 -> V_184 ) ;
V_9 . V_84 = F_8 ( 0x0000 ) ;
V_9 . V_85 = F_8 ( 0x0000 ) ;
F_77 ( V_171 , V_185 , sizeof( V_9 ) , & V_9 ) ;
V_2 -> V_10 = V_11 ;
}
static void F_78 ( struct V_170 * V_171 ,
struct V_1 * V_2 )
{
struct V_5 * V_3 = V_171 -> V_3 ;
struct V_186 V_9 ;
T_3 V_173 ;
T_3 V_125 ;
F_79 ( V_187 , & V_3 -> V_124 ) ;
if ( F_76 ( V_171 , false , & V_173 ) < 0 )
return;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . type = V_188 ;
V_9 . V_180 = V_173 ;
V_9 . V_189 = V_2 -> V_77 ;
F_5 ( & V_9 . V_190 , & V_2 -> V_18 ) ;
V_9 . V_191 = V_3 -> V_192 ;
F_77 ( V_171 , V_193 , sizeof( V_9 ) , & V_9 ) ;
V_125 = 0x01 ;
F_77 ( V_171 , V_126 , sizeof( V_125 ) , & V_125 ) ;
V_2 -> V_10 = V_11 ;
}
struct V_1 * F_80 ( struct V_5 * V_3 , T_7 * V_18 ,
T_3 V_77 , T_3 V_194 , T_4 V_195 ,
T_3 V_13 )
{
struct V_74 * V_75 ;
struct V_1 * V_2 ;
struct V_196 * V_197 ;
struct V_170 V_171 ;
int V_198 ;
V_2 = F_81 ( V_3 , V_98 , V_18 ) ;
if ( V_2 ) {
V_2 -> V_199 = V_194 ;
goto V_169;
}
V_2 = F_74 ( V_3 , V_98 , V_11 ) ;
if ( V_2 )
return F_82 ( - V_200 ) ;
V_197 = F_83 ( V_3 , V_18 , V_77 ) ;
if ( V_197 && F_64 ( & V_197 -> V_201 , V_161 ) ) {
V_18 = & V_197 -> V_201 ;
V_77 = V_202 ;
}
V_2 = F_44 ( V_3 , V_98 , V_18 , V_13 ) ;
if ( ! V_2 )
return F_82 ( - V_203 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> V_194 = V_204 ;
V_2 -> V_199 = V_194 ;
V_2 -> V_195 = V_195 ;
F_84 ( & V_171 , V_3 ) ;
if ( F_42 ( V_187 , & V_3 -> V_124 ) ) {
T_3 V_125 = 0x00 ;
F_77 ( & V_171 , V_126 , sizeof( V_125 ) ,
& V_125 ) ;
}
if ( V_2 -> V_13 == V_205 ) {
if ( F_42 ( V_206 , & V_3 -> V_124 ) &&
V_3 -> V_207 == V_208 ) {
F_59 ( & V_171 . V_209 ) ;
F_30 ( V_2 ) ;
return F_82 ( - V_200 ) ;
}
F_78 ( & V_171 , V_2 ) ;
goto V_210;
}
V_75 = F_25 ( V_3 , & V_2 -> V_18 , V_2 -> V_77 ) ;
if ( V_75 ) {
V_2 -> V_181 = V_75 -> V_78 ;
V_2 -> V_182 = V_75 -> V_79 ;
V_2 -> V_183 = V_75 -> V_80 ;
V_2 -> V_184 = V_75 -> V_81 ;
} else {
V_2 -> V_181 = V_3 -> V_181 ;
V_2 -> V_182 = V_3 -> V_182 ;
V_2 -> V_183 = V_3 -> V_183 ;
V_2 -> V_184 = V_3 -> V_184 ;
}
if ( F_42 ( V_206 , & V_3 -> V_124 ) ) {
F_85 ( & V_171 ) ;
F_9 ( V_211 , & V_3 -> V_124 ) ;
}
F_75 ( & V_171 , V_2 ) ;
V_210:
V_198 = F_86 ( & V_171 , F_72 ) ;
if ( V_198 ) {
F_30 ( V_2 ) ;
return F_82 ( V_198 ) ;
}
V_169:
F_87 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_88 ( struct V_5 * V_3 , T_7 * V_18 ,
T_3 V_194 , T_3 V_132 )
{
struct V_1 * V_157 ;
if ( ! F_42 ( V_212 , & V_3 -> V_124 ) )
return F_82 ( - V_213 ) ;
V_157 = F_81 ( V_3 , V_42 , V_18 ) ;
if ( ! V_157 ) {
V_157 = F_44 ( V_3 , V_42 , V_18 , V_14 ) ;
if ( ! V_157 )
return F_82 ( - V_203 ) ;
}
F_87 ( V_157 ) ;
if ( V_157 -> V_10 == V_131 || V_157 -> V_10 == V_104 ) {
V_157 -> V_194 = V_204 ;
V_157 -> V_199 = V_194 ;
V_157 -> V_132 = V_132 ;
F_3 ( V_157 ) ;
}
return V_157 ;
}
struct V_1 * F_89 ( struct V_5 * V_3 , int type , T_7 * V_18 ,
T_2 V_59 )
{
struct V_1 * V_157 ;
struct V_1 * V_92 ;
V_157 = F_88 ( V_3 , V_18 , V_204 , V_214 ) ;
if ( F_90 ( V_157 ) )
return V_157 ;
V_92 = F_81 ( V_3 , type , V_18 ) ;
if ( ! V_92 ) {
V_92 = F_44 ( V_3 , type , V_18 , V_14 ) ;
if ( ! V_92 ) {
F_55 ( V_157 ) ;
return F_82 ( - V_203 ) ;
}
}
V_157 -> V_64 = V_92 ;
V_92 -> V_64 = V_157 ;
F_87 ( V_92 ) ;
V_92 -> V_59 = V_59 ;
if ( V_157 -> V_10 == V_102 &&
( V_92 -> V_10 == V_131 || V_92 -> V_10 == V_104 ) ) {
F_9 ( V_140 , & V_157 -> V_27 ) ;
F_91 ( V_157 , V_215 ) ;
if ( F_42 ( V_113 , & V_157 -> V_27 ) ) {
F_9 ( V_216 , & V_157 -> V_27 ) ;
return V_92 ;
}
F_28 ( V_157 , 0x00 ) ;
}
return V_92 ;
}
int F_92 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( F_42 ( V_217 , & V_2 -> V_3 -> V_27 ) ) {
if ( ! F_93 ( V_2 ) ||
! F_42 ( V_218 , & V_2 -> V_27 ) ||
V_2 -> V_136 != V_219 )
return 0 ;
}
if ( F_94 ( V_2 ) &&
! F_42 ( V_220 , & V_2 -> V_27 ) )
return 0 ;
return 1 ;
}
static int F_95 ( struct V_1 * V_2 , T_1 V_194 , T_1 V_132 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_199 > V_194 )
V_194 = V_2 -> V_199 ;
if ( V_194 > V_2 -> V_194 )
V_2 -> V_199 = V_194 ;
else if ( F_42 ( V_221 , & V_2 -> V_27 ) )
return 1 ;
V_132 |= ( V_2 -> V_132 & 0x01 ) ;
V_2 -> V_132 = V_132 ;
if ( ! F_39 ( V_222 , & V_2 -> V_27 ) ) {
struct V_223 V_9 ;
V_9 . V_44 = F_8 ( V_2 -> V_44 ) ;
F_2 ( V_2 -> V_3 , V_224 ,
sizeof( V_9 ) , & V_9 ) ;
if ( F_42 ( V_220 , & V_2 -> V_27 ) )
F_9 ( V_225 , & V_2 -> V_27 ) ;
else
F_9 ( V_226 , & V_2 -> V_27 ) ;
}
return 0 ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_39 ( V_226 , & V_2 -> V_27 ) ) {
struct V_227 V_9 ;
V_9 . V_44 = F_8 ( V_2 -> V_44 ) ;
V_9 . V_228 = 0x01 ;
F_2 ( V_2 -> V_3 , V_229 , sizeof( V_9 ) ,
& V_9 ) ;
}
}
int F_97 ( struct V_1 * V_2 , T_1 V_194 , T_1 V_132 ,
bool V_230 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_98 )
return F_98 ( V_2 , V_194 ) ;
if ( V_194 == V_231 )
return 1 ;
if ( V_194 == V_204 && ! F_94 ( V_2 ) )
return 1 ;
if ( ! F_42 ( V_221 , & V_2 -> V_27 ) )
goto V_232;
if ( V_2 -> V_136 == V_219 &&
V_194 == V_233 )
goto V_228;
if ( ( V_2 -> V_136 == V_234 ||
V_2 -> V_136 == V_219 ) &&
V_194 == V_235 )
goto V_228;
if ( ( V_2 -> V_136 == V_236 ||
V_2 -> V_136 == V_237 ) &&
( V_194 == V_238 || V_194 == V_204 ) )
goto V_228;
if ( V_2 -> V_136 == V_239 &&
( V_194 == V_238 || V_194 == V_204 ||
V_2 -> V_240 == 16 ) )
goto V_228;
V_232:
if ( F_42 ( V_226 , & V_2 -> V_27 ) )
return 0 ;
if ( V_230 )
F_9 ( V_241 , & V_2 -> V_27 ) ;
if ( ! F_95 ( V_2 , V_194 , V_132 ) )
return 0 ;
V_228:
if ( F_42 ( V_220 , & V_2 -> V_27 ) )
return 1 ;
F_96 ( V_2 ) ;
return 0 ;
}
int F_99 ( struct V_1 * V_2 , T_1 V_194 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_194 != V_235 && V_194 != V_233 )
return 1 ;
if ( V_2 -> V_194 == V_235 ||
V_2 -> V_194 == V_233 )
return 1 ;
return 0 ;
}
int F_100 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_39 ( V_222 , & V_2 -> V_27 ) ) {
struct V_242 V_9 ;
V_9 . V_44 = F_8 ( V_2 -> V_44 ) ;
F_2 ( V_2 -> V_3 , V_243 ,
sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
int F_101 ( struct V_1 * V_2 , T_1 V_13 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_13 == V_2 -> V_13 )
return 1 ;
if ( ! F_39 ( V_244 , & V_2 -> V_27 ) ) {
struct V_245 V_9 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
V_9 . V_13 = V_13 ;
F_2 ( V_2 -> V_3 , V_246 , sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
void F_91 ( struct V_1 * V_2 , T_1 V_247 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_106 ) ;
if ( V_2 -> V_106 != V_248 )
goto V_249;
if ( ! F_42 ( V_140 , & V_2 -> V_27 ) && ! V_247 )
goto V_249;
if ( ! F_39 ( V_113 , & V_2 -> V_27 ) ) {
struct V_250 V_9 ;
V_9 . V_44 = F_8 ( V_2 -> V_44 ) ;
F_2 ( V_3 , V_251 , sizeof( V_9 ) , & V_9 ) ;
}
V_249:
if ( V_3 -> V_252 > 0 )
F_102 ( V_3 -> V_253 , & V_2 -> V_105 ,
F_103 ( V_3 -> V_252 ) ) ;
}
void F_104 ( struct V_5 * V_3 )
{
struct V_254 * V_255 = & V_3 -> V_256 ;
struct V_1 * V_257 , * V_258 ;
F_4 ( L_9 , V_3 -> V_128 ) ;
F_105 (c, n, &h->list, list) {
V_257 -> V_10 = V_104 ;
F_106 ( V_257 , V_259 ) ;
F_30 ( V_257 ) ;
}
}
void F_107 ( struct V_5 * V_3 )
{
struct V_1 * V_2 ;
F_4 ( L_9 , V_3 -> V_128 ) ;
F_24 ( V_3 ) ;
V_2 = F_74 ( V_3 , V_42 , V_97 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_26 ( V_3 ) ;
}
static T_8 F_108 ( struct V_1 * V_2 )
{
T_8 V_29 = 0 ;
if ( V_2 -> V_13 == V_14 )
V_29 |= V_30 ;
if ( F_42 ( V_220 , & V_2 -> V_27 ) )
V_29 |= V_260 ;
if ( F_42 ( V_221 , & V_2 -> V_27 ) )
V_29 |= V_261 ;
if ( F_42 ( V_262 , & V_2 -> V_27 ) )
V_29 |= V_263 ;
if ( F_42 ( V_264 , & V_2 -> V_27 ) )
V_29 |= V_265 ;
return V_29 ;
}
int F_109 ( void T_9 * V_266 )
{
struct V_1 * V_257 ;
struct V_267 V_171 , * V_268 ;
struct V_269 * V_270 ;
struct V_5 * V_3 ;
int V_258 = 0 , V_271 , V_198 ;
if ( F_110 ( & V_171 , V_266 , sizeof( V_171 ) ) )
return - V_272 ;
if ( ! V_171 . V_273 || V_171 . V_273 > ( V_274 * 2 ) / sizeof( * V_270 ) )
return - V_275 ;
V_271 = sizeof( V_171 ) + V_171 . V_273 * sizeof( * V_270 ) ;
V_268 = F_111 ( V_271 , V_129 ) ;
if ( ! V_268 )
return - V_203 ;
V_3 = F_112 ( V_171 . V_276 ) ;
if ( ! V_3 ) {
F_113 ( V_268 ) ;
return - V_277 ;
}
V_270 = V_268 -> V_278 ;
F_24 ( V_3 ) ;
F_66 (c, &hdev->conn_hash.list, list) {
F_5 ( & ( V_270 + V_258 ) -> V_17 , & V_257 -> V_18 ) ;
( V_270 + V_258 ) -> V_44 = V_257 -> V_44 ;
( V_270 + V_258 ) -> type = V_257 -> type ;
( V_270 + V_258 ) -> V_12 = V_257 -> V_12 ;
( V_270 + V_258 ) -> V_10 = V_257 -> V_10 ;
( V_270 + V_258 ) -> V_29 = F_108 ( V_257 ) ;
if ( ++ V_258 >= V_171 . V_273 )
break;
}
F_26 ( V_3 ) ;
V_268 -> V_276 = V_3 -> V_279 ;
V_268 -> V_273 = V_258 ;
V_271 = sizeof( V_171 ) + V_258 * sizeof( * V_270 ) ;
F_61 ( V_3 ) ;
V_198 = F_114 ( V_266 , V_268 , V_271 ) ;
F_113 ( V_268 ) ;
return V_198 ? - V_272 : 0 ;
}
int F_115 ( struct V_5 * V_3 , void T_9 * V_266 )
{
struct V_280 V_171 ;
struct V_269 V_270 ;
struct V_1 * V_2 ;
char T_9 * V_281 = V_266 + sizeof( V_171 ) ;
if ( F_110 ( & V_171 , V_266 , sizeof( V_171 ) ) )
return - V_272 ;
F_24 ( V_3 ) ;
V_2 = F_81 ( V_3 , V_171 . type , & V_171 . V_17 ) ;
if ( V_2 ) {
F_5 ( & V_270 . V_17 , & V_2 -> V_18 ) ;
V_270 . V_44 = V_2 -> V_44 ;
V_270 . type = V_2 -> type ;
V_270 . V_12 = V_2 -> V_12 ;
V_270 . V_10 = V_2 -> V_10 ;
V_270 . V_29 = F_108 ( V_2 ) ;
}
F_26 ( V_3 ) ;
if ( ! V_2 )
return - V_282 ;
return F_114 ( V_281 , & V_270 , sizeof( V_270 ) ) ? - V_272 : 0 ;
}
int F_116 ( struct V_5 * V_3 , void T_9 * V_266 )
{
struct V_283 V_171 ;
struct V_1 * V_2 ;
if ( F_110 ( & V_171 , V_266 , sizeof( V_171 ) ) )
return - V_272 ;
F_24 ( V_3 ) ;
V_2 = F_81 ( V_3 , V_42 , & V_171 . V_17 ) ;
if ( V_2 )
V_171 . type = V_2 -> V_132 ;
F_26 ( V_3 ) ;
if ( ! V_2 )
return - V_282 ;
return F_114 ( V_266 , & V_171 , sizeof( V_171 ) ) ? - V_272 : 0 ;
}
struct V_284 * F_117 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_284 * V_285 ;
F_4 ( L_10 , V_3 -> V_128 , V_2 ) ;
if ( F_42 ( V_286 , & V_2 -> V_27 ) ) {
F_4 ( L_11 ) ;
return NULL ;
}
V_285 = F_45 ( sizeof( * V_285 ) , V_129 ) ;
if ( ! V_285 )
return NULL ;
V_285 -> V_2 = F_118 ( V_2 ) ;
F_47 ( & V_285 -> V_149 ) ;
V_285 -> V_10 = V_102 ;
F_119 ( & V_285 -> V_287 , & V_2 -> V_150 ) ;
return V_285 ;
}
void F_120 ( struct V_284 * V_285 )
{
struct V_1 * V_2 = V_285 -> V_2 ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_12 , V_3 -> V_128 , V_2 , V_285 ) ;
F_121 ( & V_285 -> V_287 ) ;
F_122 () ;
F_9 ( V_286 , & V_2 -> V_27 ) ;
F_62 ( V_2 ) ;
F_59 ( & V_285 -> V_149 ) ;
F_113 ( V_285 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_284 * V_285 , * V_258 ;
F_4 ( L_1 , V_2 ) ;
F_105 (chan, n, &conn->chan_list, list)
F_120 ( V_285 ) ;
}
static struct V_284 * F_123 ( struct V_1 * V_288 ,
T_2 V_44 )
{
struct V_284 * V_289 ;
F_66 (hchan, &hcon->chan_list, list) {
if ( V_289 -> V_44 == V_44 )
return V_289 ;
}
return NULL ;
}
struct V_284 * F_124 ( struct V_5 * V_3 , T_2 V_44 )
{
struct V_254 * V_255 = & V_3 -> V_256 ;
struct V_1 * V_288 ;
struct V_284 * V_289 = NULL ;
F_125 () ;
F_126 (hcon, &h->list, list) {
V_289 = F_123 ( V_288 , V_44 ) ;
if ( V_289 )
break;
}
F_127 () ;
return V_289 ;
}
