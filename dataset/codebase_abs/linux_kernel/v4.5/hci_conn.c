static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
T_1 * V_9 ;
T_2 V_10 ;
V_9 = & V_2 -> V_11 ;
V_10 = V_2 -> V_12 ;
V_8 = F_2 ( V_6 , V_9 , V_10 ) ;
if ( V_8 ) {
V_9 = & V_8 -> V_9 ;
V_10 = V_8 -> V_13 ;
}
V_4 = F_3 ( & V_6 -> V_14 , V_9 ,
V_10 ) ;
if ( ! V_4 || ! V_4 -> V_15 )
return;
V_4 -> V_15 = false ;
F_4 ( & V_4 -> V_16 ) ;
switch ( V_4 -> V_17 ) {
case V_18 :
F_5 ( V_6 , V_9 , V_10 ) ;
return;
case V_19 :
case V_20 :
F_6 ( & V_4 -> V_16 , & V_6 -> V_14 ) ;
break;
case V_21 :
F_6 ( & V_4 -> V_16 , & V_6 -> V_22 ) ;
break;
default:
break;
}
F_7 ( V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( F_9 ( V_23 , & V_2 -> V_24 ) )
F_5 ( V_2 -> V_6 , & V_2 -> V_11 , V_2 -> V_12 ) ;
F_10 ( V_2 ) ;
F_11 ( V_6 , V_2 ) ;
if ( V_6 -> V_25 )
V_6 -> V_25 ( V_6 , V_26 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 -> V_27 ) ;
F_14 ( V_6 ) ;
F_15 ( V_2 ) ;
}
static void F_16 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_17 ( V_29 , struct V_1 ,
F_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_1 * V_30 = NULL ;
F_18 ( L_1 , V_6 -> V_31 , V_2 ) ;
F_19 ( V_6 ) ;
F_20 () ;
F_21 (c, &hdev->conn_hash.list, list) {
if ( V_30 == V_2 )
break;
}
F_22 () ;
if ( V_30 == V_2 ) {
F_1 ( V_2 ) ;
F_8 ( V_2 ) ;
}
F_23 ( V_6 ) ;
F_14 ( V_6 ) ;
F_15 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_18 ( L_1 , V_2 -> V_6 -> V_31 , V_2 ) ;
F_25 ( V_2 -> V_6 ) ;
F_26 ( V_2 ) ;
F_27 ( & V_2 -> F_16 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_32 * V_33 ;
struct V_34 V_35 ;
F_18 ( L_2 , V_2 ) ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = true ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 ++ ;
V_2 -> V_42 = V_6 -> V_42 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
F_29 ( & V_35 . V_9 , & V_2 -> V_11 ) ;
V_35 . V_43 = 0x02 ;
V_33 = F_30 ( V_6 , & V_2 -> V_11 ) ;
if ( V_33 ) {
if ( F_31 ( V_33 ) <= V_44 ) {
V_35 . V_43 = V_33 -> V_45 . V_43 ;
V_35 . V_46 = V_33 -> V_45 . V_46 ;
V_35 . V_47 = V_33 -> V_45 . V_47 |
F_32 ( 0x8000 ) ;
}
memcpy ( V_2 -> V_48 , V_33 -> V_45 . V_48 , 3 ) ;
if ( V_33 -> V_45 . V_49 > 0 )
F_33 ( V_50 , & V_2 -> V_24 ) ;
}
V_35 . V_51 = F_32 ( V_2 -> V_51 ) ;
if ( F_34 ( V_6 ) && ! ( V_6 -> V_52 & V_53 ) )
V_35 . V_54 = 0x01 ;
else
V_35 . V_54 = 0x00 ;
F_35 ( V_6 , V_55 , sizeof( V_35 ) , & V_35 ) ;
}
int F_36 ( struct V_1 * V_2 , T_3 V_56 )
{
F_18 ( L_2 , V_2 ) ;
if ( V_2 -> type == V_57 && V_2 -> V_39 == V_40 &&
( V_2 -> V_36 == V_58 || V_2 -> V_36 == V_59 ) ) {
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_60 V_61 ;
V_61 . V_62 = F_32 ( V_2 -> V_62 ) ;
F_35 ( V_6 , V_63 , sizeof( V_61 ) ,
& V_61 ) ;
}
return F_37 ( V_2 , V_56 ) ;
}
static void F_38 ( struct V_1 * V_2 , T_4 V_62 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_64 V_35 ;
F_18 ( L_2 , V_2 ) ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = true ;
V_2 -> V_41 ++ ;
V_35 . V_62 = F_32 ( V_62 ) ;
V_35 . V_51 = F_32 ( V_2 -> V_51 ) ;
F_35 ( V_6 , V_65 , sizeof( V_35 ) , & V_35 ) ;
}
bool F_39 ( struct V_1 * V_2 , T_4 V_62 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_66 V_35 ;
const struct V_67 * V_68 ;
F_18 ( L_2 , V_2 ) ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = true ;
V_2 -> V_41 ++ ;
V_35 . V_62 = F_32 ( V_62 ) ;
V_35 . V_69 = F_40 ( 0x00001f40 ) ;
V_35 . V_70 = F_40 ( 0x00001f40 ) ;
V_35 . V_71 = F_32 ( V_2 -> V_72 ) ;
switch ( V_2 -> V_72 & V_73 ) {
case V_74 :
if ( V_2 -> V_41 > F_41 ( V_75 ) )
return false ;
V_68 = & V_75 [ V_2 -> V_41 - 1 ] ;
break;
case V_76 :
if ( F_42 ( V_2 -> V_77 ) ) {
if ( V_2 -> V_41 > F_41 ( V_78 ) )
return false ;
V_68 = & V_78 [ V_2 -> V_41 - 1 ] ;
} else {
if ( V_2 -> V_41 > F_41 ( V_79 ) )
return false ;
V_68 = & V_79 [ V_2 -> V_41 - 1 ] ;
}
break;
default:
return false ;
}
V_35 . V_80 = V_68 -> V_80 ;
V_35 . V_51 = F_43 ( V_68 -> V_51 ) ;
V_35 . V_81 = F_43 ( V_68 -> V_81 ) ;
if ( F_35 ( V_6 , V_82 , sizeof( V_35 ) , & V_35 ) < 0 )
return false ;
return true ;
}
T_2 F_44 ( struct V_1 * V_2 , T_5 V_83 , T_5 V_84 , T_5 V_85 ,
T_5 V_86 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
struct V_87 V_35 ;
F_19 ( V_6 ) ;
V_4 = F_45 ( V_6 , & V_2 -> V_11 , V_2 -> V_12 ) ;
if ( V_4 ) {
V_4 -> V_88 = V_83 ;
V_4 -> V_89 = V_84 ;
V_4 -> V_90 = V_85 ;
V_4 -> V_91 = V_86 ;
}
F_23 ( V_6 ) ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_62 = F_32 ( V_2 -> V_62 ) ;
V_35 . V_92 = F_32 ( V_83 ) ;
V_35 . V_93 = F_32 ( V_84 ) ;
V_35 . V_90 = F_32 ( V_85 ) ;
V_35 . V_91 = F_32 ( V_86 ) ;
V_35 . V_94 = F_32 ( 0x0000 ) ;
V_35 . V_95 = F_32 ( 0x0000 ) ;
F_35 ( V_6 , V_96 , sizeof( V_35 ) , & V_35 ) ;
if ( V_4 )
return 0x01 ;
return 0x00 ;
}
void F_46 ( struct V_1 * V_2 , T_6 V_97 , T_7 rand ,
T_3 V_98 [ 16 ] , T_3 V_99 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_100 V_35 ;
F_18 ( L_2 , V_2 ) ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_62 = F_32 ( V_2 -> V_62 ) ;
V_35 . rand = rand ;
V_35 . V_97 = V_97 ;
memcpy ( V_35 . V_98 , V_98 , V_99 ) ;
F_35 ( V_6 , V_101 , sizeof( V_35 ) , & V_35 ) ;
}
void F_47 ( struct V_1 * V_2 , T_3 V_102 )
{
struct V_1 * V_103 = V_2 -> V_77 ;
if ( ! V_103 )
return;
F_18 ( L_2 , V_2 ) ;
if ( ! V_102 ) {
if ( F_42 ( V_2 -> V_6 ) )
F_39 ( V_103 , V_2 -> V_62 ) ;
else
F_38 ( V_103 , V_2 -> V_62 ) ;
} else {
F_48 ( V_103 , V_102 ) ;
F_49 ( V_103 ) ;
}
}
static void F_50 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_17 ( V_29 , struct V_1 ,
V_104 . V_29 ) ;
int V_105 = F_51 ( & V_2 -> V_105 ) ;
F_18 ( L_3 , V_2 , F_52 ( V_2 -> V_36 ) ) ;
F_53 ( V_105 < 0 ) ;
if ( V_105 > 0 )
return;
if ( V_2 -> V_36 == V_37 && V_2 -> type == V_106 &&
F_9 ( V_107 , & V_2 -> V_24 ) ) {
F_24 ( V_2 ) ;
return;
}
F_37 ( V_2 , F_54 ( V_2 ) ) ;
}
static void F_55 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_17 ( V_29 , struct V_1 ,
V_108 . V_29 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_18 ( L_4 , V_2 , V_2 -> V_109 ) ;
if ( ! F_56 ( V_6 ) || ! F_56 ( V_2 ) )
return;
if ( V_2 -> V_109 != V_110 || ! ( V_2 -> V_42 & V_111 ) )
return;
if ( F_57 ( V_6 ) && F_57 ( V_2 ) ) {
struct V_112 V_35 ;
V_35 . V_62 = F_32 ( V_2 -> V_62 ) ;
V_35 . V_81 = F_32 ( 0 ) ;
V_35 . V_113 = F_32 ( 0 ) ;
V_35 . V_114 = F_32 ( 0 ) ;
F_35 ( V_6 , V_115 , sizeof( V_35 ) , & V_35 ) ;
}
if ( ! F_58 ( V_116 , & V_2 -> V_24 ) ) {
struct V_117 V_35 ;
V_35 . V_62 = F_32 ( V_2 -> V_62 ) ;
V_35 . V_118 = F_32 ( V_6 -> V_119 ) ;
V_35 . V_120 = F_32 ( V_6 -> V_121 ) ;
V_35 . V_41 = F_32 ( 4 ) ;
V_35 . V_122 = F_32 ( 1 ) ;
F_35 ( V_6 , V_123 , sizeof( V_35 ) , & V_35 ) ;
}
}
static void F_59 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_17 ( V_29 , struct V_1 ,
V_124 . V_29 ) ;
F_35 ( V_2 -> V_6 , V_125 , sizeof( V_2 -> V_11 ) ,
& V_2 -> V_11 ) ;
}
static void F_60 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_17 ( V_29 , struct V_1 ,
F_60 . V_29 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_18 ( L_5 ) ;
if ( V_2 -> V_39 == V_126 ) {
T_2 V_127 = 0x00 ;
F_35 ( V_6 , V_128 , sizeof( V_127 ) ,
& V_127 ) ;
F_61 ( V_2 , V_129 ) ;
return;
}
F_37 ( V_2 , V_130 ) ;
}
struct V_1 * F_62 ( struct V_5 * V_6 , int type , T_1 * V_11 ,
T_2 V_39 )
{
struct V_1 * V_2 ;
F_18 ( L_6 , V_6 -> V_31 , V_11 ) ;
V_2 = F_63 ( sizeof( * V_2 ) , V_131 ) ;
if ( ! V_2 )
return NULL ;
F_29 ( & V_2 -> V_11 , V_11 ) ;
F_29 ( & V_2 -> V_132 , & V_6 -> V_9 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> type = type ;
V_2 -> V_39 = V_39 ;
V_2 -> V_109 = V_110 ;
V_2 -> V_36 = V_133 ;
V_2 -> V_134 = V_135 ;
V_2 -> V_136 = V_6 -> V_136 ;
V_2 -> V_137 = 0xff ;
V_2 -> V_138 = 0xff ;
V_2 -> V_139 = V_140 ;
V_2 -> V_141 = V_142 ;
V_2 -> V_143 = V_142 ;
F_33 ( V_144 , & V_2 -> V_24 ) ;
V_2 -> V_145 = V_146 ;
if ( V_2 -> V_39 == V_40 )
V_2 -> V_38 = true ;
switch ( type ) {
case V_57 :
V_2 -> V_51 = V_6 -> V_51 & V_147 ;
break;
case V_106 :
F_64 ( V_6 , & V_2 -> V_132 , & V_2 -> V_148 ) ;
break;
case V_149 :
if ( F_42 ( V_6 ) )
V_2 -> V_51 = ( V_6 -> V_150 & V_151 ) |
( V_6 -> V_150 & V_152 ) ;
else
V_2 -> V_51 = V_6 -> V_51 & V_153 ;
break;
case V_154 :
V_2 -> V_51 = V_6 -> V_150 & ~ V_152 ;
break;
}
F_65 ( & V_2 -> V_155 ) ;
F_66 ( & V_2 -> V_156 ) ;
F_67 ( & V_2 -> V_104 , F_50 ) ;
F_67 ( & V_2 -> V_124 , F_59 ) ;
F_67 ( & V_2 -> V_108 , F_55 ) ;
F_67 ( & V_2 -> F_60 , F_60 ) ;
F_68 ( & V_2 -> F_16 , F_16 ) ;
F_69 ( & V_2 -> V_105 , 0 ) ;
F_25 ( V_6 ) ;
F_70 ( V_6 , V_2 ) ;
if ( V_6 -> V_25 )
V_6 -> V_25 ( V_6 , V_157 ) ;
F_71 ( V_2 ) ;
return V_2 ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_18 ( L_7 , V_6 -> V_31 , V_2 , V_2 -> V_62 ) ;
F_72 ( & V_2 -> V_104 ) ;
F_72 ( & V_2 -> V_124 ) ;
F_72 ( & V_2 -> V_108 ) ;
if ( V_2 -> type == V_57 ) {
struct V_1 * V_103 = V_2 -> V_77 ;
if ( V_103 )
V_103 -> V_77 = NULL ;
V_6 -> V_158 += V_2 -> V_159 ;
} else if ( V_2 -> type == V_106 ) {
F_73 ( & V_2 -> F_60 ) ;
if ( V_6 -> V_160 )
V_6 -> V_161 += V_2 -> V_159 ;
else
V_6 -> V_158 += V_2 -> V_159 ;
} else {
struct V_1 * V_162 = V_2 -> V_77 ;
if ( V_162 ) {
V_162 -> V_77 = NULL ;
F_74 ( V_162 ) ;
}
}
if ( V_2 -> V_163 )
F_75 ( V_2 -> V_163 ) ;
F_76 ( & V_2 -> V_155 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
struct V_5 * F_77 ( T_1 * V_11 , T_1 * V_132 )
{
int V_164 = F_78 ( V_132 , V_165 ) ;
struct V_5 * V_6 = NULL , * V_166 ;
F_18 ( L_8 , V_132 , V_11 ) ;
F_79 ( & V_167 ) ;
F_80 (d, &hci_dev_list, list) {
if ( ! F_9 ( V_168 , & V_166 -> V_24 ) ||
F_81 ( V_166 , V_169 ) ||
V_166 -> V_170 != V_171 )
continue;
if ( V_164 ) {
if ( ! F_78 ( & V_166 -> V_9 , V_132 ) ) {
V_6 = V_166 ; break;
}
} else {
if ( F_78 ( & V_166 -> V_9 , V_11 ) ) {
V_6 = V_166 ; break;
}
}
}
if ( V_6 )
V_6 = F_25 ( V_6 ) ;
F_82 ( & V_167 ) ;
return V_6 ;
}
void F_61 ( struct V_1 * V_2 , T_2 V_102 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
V_4 = F_3 ( & V_6 -> V_14 , & V_2 -> V_11 ,
V_2 -> V_12 ) ;
if ( V_4 && V_4 -> V_2 ) {
F_74 ( V_4 -> V_2 ) ;
F_15 ( V_4 -> V_2 ) ;
V_4 -> V_2 = NULL ;
}
V_2 -> V_36 = V_172 ;
if ( V_102 != V_173 ||
( V_4 && V_4 -> V_15 ) )
F_83 ( V_6 , & V_2 -> V_11 , V_2 -> type ,
V_2 -> V_12 , V_102 ) ;
F_48 ( V_2 , V_102 ) ;
F_49 ( V_2 ) ;
F_7 ( V_6 ) ;
F_84 ( V_6 ) ;
}
static void F_85 ( struct V_5 * V_6 , T_2 V_102 , T_5 V_174 )
{
struct V_1 * V_2 ;
F_19 ( V_6 ) ;
V_2 = F_86 ( V_6 ) ;
if ( ! V_102 ) {
F_1 ( V_2 ) ;
goto V_175;
}
F_87 ( L_9 ,
V_102 ) ;
if ( ! V_2 )
goto V_175;
F_61 ( V_2 , V_102 ) ;
V_175:
F_23 ( V_6 ) ;
}
static void F_88 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
struct V_178 V_35 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_179 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
if ( F_89 ( V_177 , false , & V_179 ) )
return;
V_35 . V_180 = F_32 ( V_6 -> V_181 ) ;
V_35 . V_182 = V_35 . V_180 ;
F_29 ( & V_35 . V_183 , & V_2 -> V_11 ) ;
V_35 . V_184 = V_2 -> V_12 ;
V_35 . V_185 = V_179 ;
V_35 . V_92 = F_32 ( V_2 -> V_186 ) ;
V_35 . V_93 = F_32 ( V_2 -> V_187 ) ;
V_35 . V_90 = F_32 ( V_2 -> V_188 ) ;
V_35 . V_91 = F_32 ( V_2 -> V_189 ) ;
V_35 . V_94 = F_32 ( 0x0000 ) ;
V_35 . V_95 = F_32 ( 0x0000 ) ;
F_90 ( V_177 , V_190 , sizeof( V_35 ) , & V_35 ) ;
V_2 -> V_36 = V_37 ;
F_91 ( V_107 , & V_2 -> V_24 ) ;
}
static void F_92 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_177 -> V_6 ;
struct V_191 V_35 ;
T_2 V_179 ;
T_2 V_127 ;
F_93 ( V_6 , V_192 ) ;
if ( F_89 ( V_177 , false , & V_179 ) < 0 )
return;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . type = V_193 ;
V_35 . V_185 = V_179 ;
V_35 . V_194 = V_2 -> V_12 ;
F_29 ( & V_35 . V_195 , & V_2 -> V_11 ) ;
V_35 . V_196 = V_6 -> V_197 ;
F_90 ( V_177 , V_198 , sizeof( V_35 ) , & V_35 ) ;
V_127 = 0x01 ;
F_90 ( V_177 , V_128 , sizeof( V_127 ) , & V_127 ) ;
V_2 -> V_36 = V_37 ;
}
struct V_1 * F_94 ( struct V_5 * V_6 , T_1 * V_11 ,
T_2 V_12 , T_2 V_199 , T_5 V_200 ,
T_2 V_39 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_176 V_177 ;
int V_201 ;
if ( ! F_81 ( V_6 , V_202 ) ) {
if ( F_95 ( V_6 ) )
return F_96 ( - V_203 ) ;
return F_96 ( - V_204 ) ;
}
if ( F_86 ( V_6 ) )
return F_96 ( - V_205 ) ;
V_2 = F_97 ( V_6 , V_11 , V_12 ) ;
if ( V_2 && ! F_9 ( V_107 , & V_2 -> V_24 ) ) {
return F_96 ( - V_205 ) ;
}
V_8 = F_98 ( V_6 , V_11 , V_12 ) ;
if ( V_8 && F_78 ( & V_8 -> V_206 , V_165 ) ) {
V_11 = & V_8 -> V_206 ;
V_12 = V_207 ;
}
if ( V_2 ) {
F_29 ( & V_2 -> V_11 , V_11 ) ;
} else {
V_2 = F_62 ( V_6 , V_106 , V_11 , V_39 ) ;
if ( ! V_2 )
return F_96 ( - V_208 ) ;
F_99 ( V_2 ) ;
V_2 -> V_209 = V_199 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_199 = V_210 ;
V_2 -> V_200 = V_200 ;
F_100 ( & V_177 , V_6 ) ;
if ( F_81 ( V_6 , V_192 ) ) {
T_2 V_127 = 0x00 ;
F_90 ( & V_177 , V_128 , sizeof( V_127 ) ,
& V_127 ) ;
}
if ( V_2 -> V_39 == V_126 ) {
if ( F_81 ( V_6 , V_211 ) &&
V_6 -> V_212 == V_213 ) {
F_76 ( & V_177 . V_214 ) ;
F_49 ( V_2 ) ;
return F_96 ( - V_205 ) ;
}
F_92 ( & V_177 , V_2 ) ;
goto V_215;
}
V_4 = F_45 ( V_6 , & V_2 -> V_11 , V_2 -> V_12 ) ;
if ( V_4 ) {
V_2 -> V_186 = V_4 -> V_88 ;
V_2 -> V_187 = V_4 -> V_89 ;
V_2 -> V_188 = V_4 -> V_90 ;
V_2 -> V_189 = V_4 -> V_91 ;
} else {
V_2 -> V_186 = V_6 -> V_186 ;
V_2 -> V_187 = V_6 -> V_187 ;
V_2 -> V_188 = V_6 -> V_188 ;
V_2 -> V_189 = V_6 -> V_189 ;
}
if ( F_81 ( V_6 , V_211 ) ) {
F_101 ( & V_177 ) ;
F_102 ( V_6 , V_216 ) ;
}
F_88 ( & V_177 , V_2 ) ;
V_215:
V_201 = F_103 ( & V_177 , F_85 ) ;
if ( V_201 ) {
F_49 ( V_2 ) ;
return F_96 ( V_201 ) ;
}
return V_2 ;
}
static bool F_104 ( struct V_5 * V_6 , T_1 * V_217 , T_2 type )
{
struct V_1 * V_2 ;
V_2 = F_97 ( V_6 , V_217 , type ) ;
if ( ! V_2 )
return false ;
if ( V_2 -> V_36 != V_58 )
return false ;
return true ;
}
static int F_105 ( struct V_5 * V_6 ,
T_1 * V_217 , T_2 V_13 )
{
struct V_3 * V_4 ;
if ( F_104 ( V_6 , V_217 , V_13 ) )
return - V_218 ;
V_4 = F_45 ( V_6 , V_217 , V_13 ) ;
if ( ! V_4 ) {
V_4 = F_106 ( V_6 , V_217 , V_13 ) ;
if ( ! V_4 )
return - V_208 ;
V_4 -> V_17 = V_18 ;
}
if ( V_4 -> V_17 == V_219 ||
V_4 -> V_17 == V_21 ||
V_4 -> V_17 == V_18 ) {
F_4 ( & V_4 -> V_16 ) ;
F_6 ( & V_4 -> V_16 , & V_6 -> V_14 ) ;
}
V_4 -> V_15 = true ;
F_18 ( L_10 , V_217 , V_13 ,
V_4 -> V_17 ) ;
return 0 ;
}
struct V_1 * F_107 ( struct V_5 * V_6 , T_1 * V_11 ,
T_2 V_12 , T_2 V_199 ,
T_5 V_200 )
{
struct V_1 * V_2 ;
if ( ! F_81 ( V_6 , V_202 ) ) {
if ( F_95 ( V_6 ) )
return F_96 ( - V_203 ) ;
return F_96 ( - V_204 ) ;
}
V_2 = F_97 ( V_6 , V_11 , V_12 ) ;
if ( V_2 ) {
if ( V_2 -> V_209 < V_199 )
V_2 -> V_209 = V_199 ;
goto V_175;
}
F_18 ( L_11 ) ;
V_2 = F_62 ( V_6 , V_106 , V_11 , V_40 ) ;
if ( ! V_2 )
return F_96 ( - V_208 ) ;
if ( F_105 ( V_6 , V_11 , V_12 ) < 0 )
return F_96 ( - V_205 ) ;
V_2 -> V_36 = V_37 ;
F_33 ( V_107 , & V_2 -> V_24 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_199 = V_210 ;
V_2 -> V_209 = V_199 ;
V_2 -> V_200 = V_200 ;
F_7 ( V_6 ) ;
V_175:
F_99 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_108 ( struct V_5 * V_6 , T_1 * V_11 ,
T_2 V_199 , T_2 V_134 )
{
struct V_1 * V_162 ;
if ( ! F_81 ( V_6 , V_220 ) ) {
if ( F_109 ( V_6 ) )
return F_96 ( - V_203 ) ;
return F_96 ( - V_204 ) ;
}
V_162 = F_110 ( V_6 , V_57 , V_11 ) ;
if ( ! V_162 ) {
V_162 = F_62 ( V_6 , V_57 , V_11 , V_40 ) ;
if ( ! V_162 )
return F_96 ( - V_208 ) ;
}
F_99 ( V_162 ) ;
if ( V_162 -> V_36 == V_133 || V_162 -> V_36 == V_172 ) {
V_162 -> V_199 = V_210 ;
V_162 -> V_209 = V_199 ;
V_162 -> V_134 = V_134 ;
F_28 ( V_162 ) ;
}
return V_162 ;
}
struct V_1 * F_111 ( struct V_5 * V_6 , int type , T_1 * V_11 ,
T_4 V_72 )
{
struct V_1 * V_162 ;
struct V_1 * V_103 ;
V_162 = F_108 ( V_6 , V_11 , V_210 , V_221 ) ;
if ( F_112 ( V_162 ) )
return V_162 ;
V_103 = F_110 ( V_6 , type , V_11 ) ;
if ( ! V_103 ) {
V_103 = F_62 ( V_6 , type , V_11 , V_40 ) ;
if ( ! V_103 ) {
F_74 ( V_162 ) ;
return F_96 ( - V_208 ) ;
}
}
V_162 -> V_77 = V_103 ;
V_103 -> V_77 = V_162 ;
F_99 ( V_103 ) ;
V_103 -> V_72 = V_72 ;
if ( V_162 -> V_36 == V_58 &&
( V_103 -> V_36 == V_133 || V_103 -> V_36 == V_172 ) ) {
F_33 ( V_144 , & V_162 -> V_24 ) ;
F_113 ( V_162 , V_222 ) ;
if ( F_9 ( V_116 , & V_162 -> V_24 ) ) {
F_33 ( V_223 , & V_162 -> V_24 ) ;
return V_103 ;
}
F_47 ( V_162 , 0x00 ) ;
}
return V_103 ;
}
int F_114 ( struct V_1 * V_2 )
{
F_18 ( L_2 , V_2 ) ;
if ( F_81 ( V_2 -> V_6 , V_224 ) ) {
if ( ! F_115 ( V_2 ) ||
! F_9 ( V_225 , & V_2 -> V_24 ) ||
V_2 -> V_138 != V_226 )
return 0 ;
}
if ( F_116 ( V_2 ) &&
! F_9 ( V_227 , & V_2 -> V_24 ) )
return 0 ;
return 1 ;
}
static int F_117 ( struct V_1 * V_2 , T_3 V_199 , T_3 V_134 )
{
F_18 ( L_2 , V_2 ) ;
if ( V_2 -> V_209 > V_199 )
V_199 = V_2 -> V_209 ;
if ( V_199 > V_2 -> V_199 )
V_2 -> V_209 = V_199 ;
else if ( F_9 ( V_228 , & V_2 -> V_24 ) )
return 1 ;
V_134 |= ( V_2 -> V_134 & 0x01 ) ;
V_2 -> V_134 = V_134 ;
if ( ! F_58 ( V_229 , & V_2 -> V_24 ) ) {
struct V_230 V_35 ;
V_35 . V_62 = F_32 ( V_2 -> V_62 ) ;
F_35 ( V_2 -> V_6 , V_231 ,
sizeof( V_35 ) , & V_35 ) ;
if ( F_9 ( V_227 , & V_2 -> V_24 ) )
F_33 ( V_232 , & V_2 -> V_24 ) ;
else
F_33 ( V_233 , & V_2 -> V_24 ) ;
}
return 0 ;
}
static void F_118 ( struct V_1 * V_2 )
{
F_18 ( L_2 , V_2 ) ;
if ( ! F_58 ( V_233 , & V_2 -> V_24 ) ) {
struct V_234 V_35 ;
V_35 . V_62 = F_32 ( V_2 -> V_62 ) ;
V_35 . V_235 = 0x01 ;
F_35 ( V_2 -> V_6 , V_236 , sizeof( V_35 ) ,
& V_35 ) ;
}
}
int F_119 ( struct V_1 * V_2 , T_3 V_199 , T_3 V_134 ,
bool V_237 )
{
F_18 ( L_2 , V_2 ) ;
if ( V_2 -> type == V_106 )
return F_120 ( V_2 , V_199 ) ;
if ( V_199 == V_238 )
return 1 ;
if ( V_199 == V_210 && ! F_116 ( V_2 ) )
return 1 ;
if ( ! F_9 ( V_228 , & V_2 -> V_24 ) )
goto V_239;
if ( V_2 -> V_138 == V_226 &&
V_199 == V_240 )
goto V_235;
if ( ( V_2 -> V_138 == V_241 ||
V_2 -> V_138 == V_226 ) &&
V_199 == V_242 )
goto V_235;
if ( ( V_2 -> V_138 == V_243 ||
V_2 -> V_138 == V_244 ) &&
( V_199 == V_245 || V_199 == V_210 ) )
goto V_235;
if ( V_2 -> V_138 == V_246 &&
( V_199 == V_245 || V_199 == V_210 ||
V_2 -> V_247 == 16 ) )
goto V_235;
V_239:
if ( F_9 ( V_233 , & V_2 -> V_24 ) )
return 0 ;
if ( V_237 )
F_33 ( V_248 , & V_2 -> V_24 ) ;
if ( ! F_117 ( V_2 , V_199 , V_134 ) )
return 0 ;
V_235:
if ( F_9 ( V_227 , & V_2 -> V_24 ) )
return 1 ;
F_118 ( V_2 ) ;
return 0 ;
}
int F_121 ( struct V_1 * V_2 , T_3 V_199 )
{
F_18 ( L_2 , V_2 ) ;
if ( V_199 != V_242 && V_199 != V_240 )
return 1 ;
if ( V_2 -> V_199 == V_242 ||
V_2 -> V_199 == V_240 )
return 1 ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_3 V_39 )
{
F_18 ( L_2 , V_2 ) ;
if ( V_39 == V_2 -> V_39 )
return 1 ;
if ( ! F_58 ( V_249 , & V_2 -> V_24 ) ) {
struct V_250 V_35 ;
F_29 ( & V_35 . V_9 , & V_2 -> V_11 ) ;
V_35 . V_39 = V_39 ;
F_35 ( V_2 -> V_6 , V_251 , sizeof( V_35 ) , & V_35 ) ;
}
return 0 ;
}
void F_113 ( struct V_1 * V_2 , T_3 V_252 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_18 ( L_4 , V_2 , V_2 -> V_109 ) ;
if ( V_2 -> V_109 != V_253 )
goto V_254;
if ( ! F_9 ( V_144 , & V_2 -> V_24 ) && ! V_252 )
goto V_254;
if ( ! F_58 ( V_116 , & V_2 -> V_24 ) ) {
struct V_255 V_35 ;
V_35 . V_62 = F_32 ( V_2 -> V_62 ) ;
F_35 ( V_6 , V_256 , sizeof( V_35 ) , & V_35 ) ;
}
V_254:
if ( V_6 -> V_257 > 0 )
F_123 ( V_6 -> V_258 , & V_2 -> V_108 ,
F_124 ( V_6 -> V_257 ) ) ;
}
void F_125 ( struct V_5 * V_6 )
{
struct V_259 * V_260 = & V_6 -> V_261 ;
struct V_1 * V_30 , * V_262 ;
F_18 ( L_12 , V_6 -> V_31 ) ;
F_126 (c, n, &h->list, list) {
V_30 -> V_36 = V_172 ;
F_127 ( V_30 , V_263 ) ;
F_49 ( V_30 ) ;
}
}
void F_128 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_18 ( L_12 , V_6 -> V_31 ) ;
F_19 ( V_6 ) ;
V_2 = F_129 ( V_6 , V_57 , V_264 ) ;
if ( V_2 )
F_28 ( V_2 ) ;
F_23 ( V_6 ) ;
}
static T_8 F_130 ( struct V_1 * V_2 )
{
T_8 V_52 = 0 ;
if ( V_2 -> V_39 == V_40 )
V_52 |= V_53 ;
if ( F_9 ( V_227 , & V_2 -> V_24 ) )
V_52 |= V_265 ;
if ( F_9 ( V_228 , & V_2 -> V_24 ) )
V_52 |= V_266 ;
if ( F_9 ( V_267 , & V_2 -> V_24 ) )
V_52 |= V_268 ;
if ( F_9 ( V_269 , & V_2 -> V_24 ) )
V_52 |= V_270 ;
return V_52 ;
}
int F_131 ( void T_9 * V_271 )
{
struct V_1 * V_30 ;
struct V_272 V_177 , * V_273 ;
struct V_274 * V_275 ;
struct V_5 * V_6 ;
int V_262 = 0 , V_276 , V_201 ;
if ( F_132 ( & V_177 , V_271 , sizeof( V_177 ) ) )
return - V_277 ;
if ( ! V_177 . V_278 || V_177 . V_278 > ( V_279 * 2 ) / sizeof( * V_275 ) )
return - V_280 ;
V_276 = sizeof( V_177 ) + V_177 . V_278 * sizeof( * V_275 ) ;
V_273 = F_133 ( V_276 , V_131 ) ;
if ( ! V_273 )
return - V_208 ;
V_6 = F_134 ( V_177 . V_281 ) ;
if ( ! V_6 ) {
F_135 ( V_273 ) ;
return - V_282 ;
}
V_275 = V_273 -> V_283 ;
F_19 ( V_6 ) ;
F_80 (c, &hdev->conn_hash.list, list) {
F_29 ( & ( V_275 + V_262 ) -> V_9 , & V_30 -> V_11 ) ;
( V_275 + V_262 ) -> V_62 = V_30 -> V_62 ;
( V_275 + V_262 ) -> type = V_30 -> type ;
( V_275 + V_262 ) -> V_38 = V_30 -> V_38 ;
( V_275 + V_262 ) -> V_36 = V_30 -> V_36 ;
( V_275 + V_262 ) -> V_52 = F_130 ( V_30 ) ;
if ( ++ V_262 >= V_177 . V_278 )
break;
}
F_23 ( V_6 ) ;
V_273 -> V_281 = V_6 -> V_284 ;
V_273 -> V_278 = V_262 ;
V_276 = sizeof( V_177 ) + V_262 * sizeof( * V_275 ) ;
F_14 ( V_6 ) ;
V_201 = F_136 ( V_271 , V_273 , V_276 ) ;
F_135 ( V_273 ) ;
return V_201 ? - V_277 : 0 ;
}
int F_137 ( struct V_5 * V_6 , void T_9 * V_271 )
{
struct V_285 V_177 ;
struct V_274 V_275 ;
struct V_1 * V_2 ;
char T_9 * V_286 = V_271 + sizeof( V_177 ) ;
if ( F_132 ( & V_177 , V_271 , sizeof( V_177 ) ) )
return - V_277 ;
F_19 ( V_6 ) ;
V_2 = F_110 ( V_6 , V_177 . type , & V_177 . V_9 ) ;
if ( V_2 ) {
F_29 ( & V_275 . V_9 , & V_2 -> V_11 ) ;
V_275 . V_62 = V_2 -> V_62 ;
V_275 . type = V_2 -> type ;
V_275 . V_38 = V_2 -> V_38 ;
V_275 . V_36 = V_2 -> V_36 ;
V_275 . V_52 = F_130 ( V_2 ) ;
}
F_23 ( V_6 ) ;
if ( ! V_2 )
return - V_287 ;
return F_136 ( V_286 , & V_275 , sizeof( V_275 ) ) ? - V_277 : 0 ;
}
int F_138 ( struct V_5 * V_6 , void T_9 * V_271 )
{
struct V_288 V_177 ;
struct V_1 * V_2 ;
if ( F_132 ( & V_177 , V_271 , sizeof( V_177 ) ) )
return - V_277 ;
F_19 ( V_6 ) ;
V_2 = F_110 ( V_6 , V_57 , & V_177 . V_9 ) ;
if ( V_2 )
V_177 . type = V_2 -> V_134 ;
F_23 ( V_6 ) ;
if ( ! V_2 )
return - V_287 ;
return F_136 ( V_271 , & V_177 , sizeof( V_177 ) ) ? - V_277 : 0 ;
}
struct V_289 * F_139 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_289 * V_290 ;
F_18 ( L_1 , V_6 -> V_31 , V_2 ) ;
if ( F_9 ( V_291 , & V_2 -> V_24 ) ) {
F_18 ( L_13 ) ;
return NULL ;
}
V_290 = F_63 ( sizeof( * V_290 ) , V_131 ) ;
if ( ! V_290 )
return NULL ;
V_290 -> V_2 = F_26 ( V_2 ) ;
F_65 ( & V_290 -> V_155 ) ;
V_290 -> V_36 = V_58 ;
F_140 ( & V_290 -> V_292 , & V_2 -> V_156 ) ;
return V_290 ;
}
void F_141 ( struct V_289 * V_290 )
{
struct V_1 * V_2 = V_290 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_18 ( L_14 , V_6 -> V_31 , V_2 , V_290 ) ;
F_142 ( & V_290 -> V_292 ) ;
F_143 () ;
F_33 ( V_291 , & V_2 -> V_24 ) ;
F_15 ( V_2 ) ;
F_76 ( & V_290 -> V_155 ) ;
F_135 ( V_290 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_289 * V_290 , * V_262 ;
F_18 ( L_2 , V_2 ) ;
F_126 (chan, n, &conn->chan_list, list)
F_141 ( V_290 ) ;
}
static struct V_289 * F_144 ( struct V_1 * V_293 ,
T_4 V_62 )
{
struct V_289 * V_294 ;
F_80 (hchan, &hcon->chan_list, list) {
if ( V_294 -> V_62 == V_62 )
return V_294 ;
}
return NULL ;
}
struct V_289 * F_145 ( struct V_5 * V_6 , T_4 V_62 )
{
struct V_259 * V_260 = & V_6 -> V_261 ;
struct V_1 * V_293 ;
struct V_289 * V_294 = NULL ;
F_20 () ;
F_21 (hcon, &h->list, list) {
V_294 = F_144 ( V_293 , V_62 ) ;
if ( V_294 )
break;
}
F_22 () ;
return V_294 ;
}
