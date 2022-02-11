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
static bool F_88 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
return F_81 ( V_6 , V_176 ) ;
}
static void F_89 ( struct V_177 * V_178 ,
struct V_1 * V_2 )
{
struct V_179 V_35 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_180 ;
if ( F_90 ( V_178 , false , F_88 ( V_2 ) ,
& V_180 ) )
return;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_181 = F_32 ( V_6 -> V_182 ) ;
V_35 . V_183 = V_35 . V_181 ;
F_29 ( & V_35 . V_184 , & V_2 -> V_11 ) ;
V_35 . V_185 = V_2 -> V_12 ;
V_35 . V_186 = V_180 ;
V_35 . V_92 = F_32 ( V_2 -> V_187 ) ;
V_35 . V_93 = F_32 ( V_2 -> V_188 ) ;
V_35 . V_90 = F_32 ( V_2 -> V_189 ) ;
V_35 . V_91 = F_32 ( V_2 -> V_190 ) ;
V_35 . V_94 = F_32 ( 0x0000 ) ;
V_35 . V_95 = F_32 ( 0x0000 ) ;
F_91 ( V_178 , V_191 , sizeof( V_35 ) , & V_35 ) ;
V_2 -> V_36 = V_37 ;
F_92 ( V_107 , & V_2 -> V_24 ) ;
}
static void F_93 ( struct V_177 * V_178 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_178 -> V_6 ;
struct V_192 V_35 ;
T_2 V_180 ;
T_2 V_127 ;
F_94 ( V_6 , V_193 ) ;
if ( F_90 ( V_178 , false , F_88 ( V_2 ) ,
& V_180 ) < 0 )
return;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . type = V_194 ;
V_35 . V_186 = V_180 ;
V_35 . V_195 = V_2 -> V_12 ;
F_29 ( & V_35 . V_196 , & V_2 -> V_11 ) ;
V_35 . V_197 = V_6 -> V_198 ;
F_91 ( V_178 , V_199 , sizeof( V_35 ) , & V_35 ) ;
V_127 = 0x01 ;
F_91 ( V_178 , V_128 , sizeof( V_127 ) , & V_127 ) ;
V_2 -> V_36 = V_37 ;
}
struct V_1 * F_95 ( struct V_5 * V_6 , T_1 * V_11 ,
T_2 V_12 , T_2 V_200 , T_5 V_201 ,
T_2 V_39 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_177 V_178 ;
int V_202 ;
if ( ! F_81 ( V_6 , V_203 ) ) {
if ( F_96 ( V_6 ) )
return F_97 ( - V_204 ) ;
return F_97 ( - V_205 ) ;
}
if ( F_86 ( V_6 ) )
return F_97 ( - V_206 ) ;
V_2 = F_98 ( V_6 , V_11 , V_12 ) ;
if ( V_2 && ! F_9 ( V_107 , & V_2 -> V_24 ) ) {
return F_97 ( - V_206 ) ;
}
V_8 = F_99 ( V_6 , V_11 , V_12 ) ;
if ( V_8 && F_78 ( & V_8 -> V_207 , V_165 ) ) {
V_11 = & V_8 -> V_207 ;
V_12 = V_208 ;
}
if ( V_2 ) {
F_29 ( & V_2 -> V_11 , V_11 ) ;
} else {
V_2 = F_62 ( V_6 , V_106 , V_11 , V_39 ) ;
if ( ! V_2 )
return F_97 ( - V_209 ) ;
F_100 ( V_2 ) ;
V_2 -> V_210 = V_200 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_200 = V_211 ;
V_2 -> V_201 = V_201 ;
F_101 ( & V_178 , V_6 ) ;
if ( F_81 ( V_6 , V_193 ) ) {
T_2 V_127 = 0x00 ;
F_91 ( & V_178 , V_128 , sizeof( V_127 ) ,
& V_127 ) ;
}
if ( V_2 -> V_39 == V_126 ) {
if ( F_81 ( V_6 , V_212 ) &&
V_6 -> V_213 == V_214 ) {
F_76 ( & V_178 . V_215 ) ;
F_49 ( V_2 ) ;
return F_97 ( - V_206 ) ;
}
F_93 ( & V_178 , V_2 ) ;
goto V_216;
}
V_4 = F_45 ( V_6 , & V_2 -> V_11 , V_2 -> V_12 ) ;
if ( V_4 ) {
V_2 -> V_187 = V_4 -> V_88 ;
V_2 -> V_188 = V_4 -> V_89 ;
V_2 -> V_189 = V_4 -> V_90 ;
V_2 -> V_190 = V_4 -> V_91 ;
} else {
V_2 -> V_187 = V_6 -> V_187 ;
V_2 -> V_188 = V_6 -> V_188 ;
V_2 -> V_189 = V_6 -> V_189 ;
V_2 -> V_190 = V_6 -> V_190 ;
}
if ( F_81 ( V_6 , V_212 ) ) {
F_102 ( & V_178 ) ;
F_103 ( V_6 , V_217 ) ;
}
F_89 ( & V_178 , V_2 ) ;
V_216:
V_202 = F_104 ( & V_178 , F_85 ) ;
if ( V_202 ) {
F_49 ( V_2 ) ;
return F_97 ( V_202 ) ;
}
return V_2 ;
}
static bool F_105 ( struct V_5 * V_6 , T_1 * V_218 , T_2 type )
{
struct V_1 * V_2 ;
V_2 = F_98 ( V_6 , V_218 , type ) ;
if ( ! V_2 )
return false ;
if ( V_2 -> V_36 != V_58 )
return false ;
return true ;
}
static int F_106 ( struct V_5 * V_6 ,
T_1 * V_218 , T_2 V_13 )
{
struct V_3 * V_4 ;
if ( F_105 ( V_6 , V_218 , V_13 ) )
return - V_219 ;
V_4 = F_45 ( V_6 , V_218 , V_13 ) ;
if ( ! V_4 ) {
V_4 = F_107 ( V_6 , V_218 , V_13 ) ;
if ( ! V_4 )
return - V_209 ;
V_4 -> V_17 = V_18 ;
}
if ( V_4 -> V_17 == V_220 ||
V_4 -> V_17 == V_21 ||
V_4 -> V_17 == V_18 ) {
F_4 ( & V_4 -> V_16 ) ;
F_6 ( & V_4 -> V_16 , & V_6 -> V_14 ) ;
}
V_4 -> V_15 = true ;
F_18 ( L_10 , V_218 , V_13 ,
V_4 -> V_17 ) ;
return 0 ;
}
struct V_1 * F_108 ( struct V_5 * V_6 , T_1 * V_11 ,
T_2 V_12 , T_2 V_200 ,
T_5 V_201 )
{
struct V_1 * V_2 ;
if ( ! F_81 ( V_6 , V_203 ) ) {
if ( F_96 ( V_6 ) )
return F_97 ( - V_204 ) ;
return F_97 ( - V_205 ) ;
}
V_2 = F_98 ( V_6 , V_11 , V_12 ) ;
if ( V_2 ) {
if ( V_2 -> V_210 < V_200 )
V_2 -> V_210 = V_200 ;
goto V_175;
}
F_18 ( L_11 ) ;
V_2 = F_62 ( V_6 , V_106 , V_11 , V_40 ) ;
if ( ! V_2 )
return F_97 ( - V_209 ) ;
if ( F_106 ( V_6 , V_11 , V_12 ) < 0 )
return F_97 ( - V_206 ) ;
V_2 -> V_36 = V_37 ;
F_33 ( V_107 , & V_2 -> V_24 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_200 = V_211 ;
V_2 -> V_210 = V_200 ;
V_2 -> V_201 = V_201 ;
F_7 ( V_6 ) ;
V_175:
F_100 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_109 ( struct V_5 * V_6 , T_1 * V_11 ,
T_2 V_200 , T_2 V_134 )
{
struct V_1 * V_162 ;
if ( ! F_81 ( V_6 , V_221 ) ) {
if ( F_110 ( V_6 ) )
return F_97 ( - V_204 ) ;
return F_97 ( - V_205 ) ;
}
V_162 = F_111 ( V_6 , V_57 , V_11 ) ;
if ( ! V_162 ) {
V_162 = F_62 ( V_6 , V_57 , V_11 , V_40 ) ;
if ( ! V_162 )
return F_97 ( - V_209 ) ;
}
F_100 ( V_162 ) ;
if ( V_162 -> V_36 == V_133 || V_162 -> V_36 == V_172 ) {
V_162 -> V_200 = V_211 ;
V_162 -> V_210 = V_200 ;
V_162 -> V_134 = V_134 ;
F_28 ( V_162 ) ;
}
return V_162 ;
}
struct V_1 * F_112 ( struct V_5 * V_6 , int type , T_1 * V_11 ,
T_4 V_72 )
{
struct V_1 * V_162 ;
struct V_1 * V_103 ;
V_162 = F_109 ( V_6 , V_11 , V_211 , V_222 ) ;
if ( F_113 ( V_162 ) )
return V_162 ;
V_103 = F_111 ( V_6 , type , V_11 ) ;
if ( ! V_103 ) {
V_103 = F_62 ( V_6 , type , V_11 , V_40 ) ;
if ( ! V_103 ) {
F_74 ( V_162 ) ;
return F_97 ( - V_209 ) ;
}
}
V_162 -> V_77 = V_103 ;
V_103 -> V_77 = V_162 ;
F_100 ( V_103 ) ;
V_103 -> V_72 = V_72 ;
if ( V_162 -> V_36 == V_58 &&
( V_103 -> V_36 == V_133 || V_103 -> V_36 == V_172 ) ) {
F_33 ( V_144 , & V_162 -> V_24 ) ;
F_114 ( V_162 , V_223 ) ;
if ( F_9 ( V_116 , & V_162 -> V_24 ) ) {
F_33 ( V_224 , & V_162 -> V_24 ) ;
return V_103 ;
}
F_47 ( V_162 , 0x00 ) ;
}
return V_103 ;
}
int F_115 ( struct V_1 * V_2 )
{
F_18 ( L_2 , V_2 ) ;
if ( F_81 ( V_2 -> V_6 , V_225 ) ) {
if ( ! F_116 ( V_2 ) ||
! F_9 ( V_226 , & V_2 -> V_24 ) ||
V_2 -> V_138 != V_227 )
return 0 ;
}
if ( F_117 ( V_2 ) &&
! F_9 ( V_228 , & V_2 -> V_24 ) )
return 0 ;
return 1 ;
}
static int F_118 ( struct V_1 * V_2 , T_3 V_200 , T_3 V_134 )
{
F_18 ( L_2 , V_2 ) ;
if ( V_2 -> V_210 > V_200 )
V_200 = V_2 -> V_210 ;
if ( V_200 > V_2 -> V_200 )
V_2 -> V_210 = V_200 ;
else if ( F_9 ( V_229 , & V_2 -> V_24 ) )
return 1 ;
V_134 |= ( V_2 -> V_134 & 0x01 ) ;
V_2 -> V_134 = V_134 ;
if ( ! F_58 ( V_230 , & V_2 -> V_24 ) ) {
struct V_231 V_35 ;
V_35 . V_62 = F_32 ( V_2 -> V_62 ) ;
F_35 ( V_2 -> V_6 , V_232 ,
sizeof( V_35 ) , & V_35 ) ;
if ( F_9 ( V_228 , & V_2 -> V_24 ) )
F_33 ( V_233 , & V_2 -> V_24 ) ;
else
F_33 ( V_234 , & V_2 -> V_24 ) ;
}
return 0 ;
}
static void F_119 ( struct V_1 * V_2 )
{
F_18 ( L_2 , V_2 ) ;
if ( ! F_58 ( V_234 , & V_2 -> V_24 ) ) {
struct V_235 V_35 ;
V_35 . V_62 = F_32 ( V_2 -> V_62 ) ;
V_35 . V_236 = 0x01 ;
F_35 ( V_2 -> V_6 , V_237 , sizeof( V_35 ) ,
& V_35 ) ;
}
}
int F_120 ( struct V_1 * V_2 , T_3 V_200 , T_3 V_134 ,
bool V_238 )
{
F_18 ( L_2 , V_2 ) ;
if ( V_2 -> type == V_106 )
return F_121 ( V_2 , V_200 ) ;
if ( V_200 == V_239 )
return 1 ;
if ( V_200 == V_211 && ! F_117 ( V_2 ) )
return 1 ;
if ( ! F_9 ( V_229 , & V_2 -> V_24 ) )
goto V_240;
if ( V_2 -> V_138 == V_227 &&
V_200 == V_241 )
goto V_236;
if ( ( V_2 -> V_138 == V_242 ||
V_2 -> V_138 == V_227 ) &&
V_200 == V_243 )
goto V_236;
if ( ( V_2 -> V_138 == V_244 ||
V_2 -> V_138 == V_245 ) &&
( V_200 == V_246 || V_200 == V_211 ) )
goto V_236;
if ( V_2 -> V_138 == V_247 &&
( V_200 == V_246 || V_200 == V_211 ||
V_2 -> V_248 == 16 ) )
goto V_236;
V_240:
if ( F_9 ( V_234 , & V_2 -> V_24 ) )
return 0 ;
if ( V_238 )
F_33 ( V_249 , & V_2 -> V_24 ) ;
if ( ! F_118 ( V_2 , V_200 , V_134 ) )
return 0 ;
V_236:
if ( F_9 ( V_228 , & V_2 -> V_24 ) )
return 1 ;
F_119 ( V_2 ) ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_3 V_200 )
{
F_18 ( L_2 , V_2 ) ;
if ( V_200 != V_243 && V_200 != V_241 )
return 1 ;
if ( V_2 -> V_200 == V_243 ||
V_2 -> V_200 == V_241 )
return 1 ;
return 0 ;
}
int F_123 ( struct V_1 * V_2 , T_3 V_39 )
{
F_18 ( L_2 , V_2 ) ;
if ( V_39 == V_2 -> V_39 )
return 1 ;
if ( ! F_58 ( V_250 , & V_2 -> V_24 ) ) {
struct V_251 V_35 ;
F_29 ( & V_35 . V_9 , & V_2 -> V_11 ) ;
V_35 . V_39 = V_39 ;
F_35 ( V_2 -> V_6 , V_252 , sizeof( V_35 ) , & V_35 ) ;
}
return 0 ;
}
void F_114 ( struct V_1 * V_2 , T_3 V_253 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_18 ( L_4 , V_2 , V_2 -> V_109 ) ;
if ( V_2 -> V_109 != V_254 )
goto V_255;
if ( ! F_9 ( V_144 , & V_2 -> V_24 ) && ! V_253 )
goto V_255;
if ( ! F_58 ( V_116 , & V_2 -> V_24 ) ) {
struct V_256 V_35 ;
V_35 . V_62 = F_32 ( V_2 -> V_62 ) ;
F_35 ( V_6 , V_257 , sizeof( V_35 ) , & V_35 ) ;
}
V_255:
if ( V_6 -> V_258 > 0 )
F_124 ( V_6 -> V_259 , & V_2 -> V_108 ,
F_125 ( V_6 -> V_258 ) ) ;
}
void F_126 ( struct V_5 * V_6 )
{
struct V_260 * V_261 = & V_6 -> V_262 ;
struct V_1 * V_30 , * V_263 ;
F_18 ( L_12 , V_6 -> V_31 ) ;
F_127 (c, n, &h->list, list) {
V_30 -> V_36 = V_172 ;
F_128 ( V_30 , V_264 ) ;
F_49 ( V_30 ) ;
}
}
void F_129 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_18 ( L_12 , V_6 -> V_31 ) ;
F_19 ( V_6 ) ;
V_2 = F_130 ( V_6 , V_57 , V_265 ) ;
if ( V_2 )
F_28 ( V_2 ) ;
F_23 ( V_6 ) ;
}
static T_8 F_131 ( struct V_1 * V_2 )
{
T_8 V_52 = 0 ;
if ( V_2 -> V_39 == V_40 )
V_52 |= V_53 ;
if ( F_9 ( V_228 , & V_2 -> V_24 ) )
V_52 |= V_266 ;
if ( F_9 ( V_229 , & V_2 -> V_24 ) )
V_52 |= V_267 ;
if ( F_9 ( V_268 , & V_2 -> V_24 ) )
V_52 |= V_269 ;
if ( F_9 ( V_270 , & V_2 -> V_24 ) )
V_52 |= V_271 ;
return V_52 ;
}
int F_132 ( void T_9 * V_272 )
{
struct V_1 * V_30 ;
struct V_273 V_178 , * V_274 ;
struct V_275 * V_276 ;
struct V_5 * V_6 ;
int V_263 = 0 , V_277 , V_202 ;
if ( F_133 ( & V_178 , V_272 , sizeof( V_178 ) ) )
return - V_278 ;
if ( ! V_178 . V_279 || V_178 . V_279 > ( V_280 * 2 ) / sizeof( * V_276 ) )
return - V_281 ;
V_277 = sizeof( V_178 ) + V_178 . V_279 * sizeof( * V_276 ) ;
V_274 = F_134 ( V_277 , V_131 ) ;
if ( ! V_274 )
return - V_209 ;
V_6 = F_135 ( V_178 . V_282 ) ;
if ( ! V_6 ) {
F_136 ( V_274 ) ;
return - V_283 ;
}
V_276 = V_274 -> V_284 ;
F_19 ( V_6 ) ;
F_80 (c, &hdev->conn_hash.list, list) {
F_29 ( & ( V_276 + V_263 ) -> V_9 , & V_30 -> V_11 ) ;
( V_276 + V_263 ) -> V_62 = V_30 -> V_62 ;
( V_276 + V_263 ) -> type = V_30 -> type ;
( V_276 + V_263 ) -> V_38 = V_30 -> V_38 ;
( V_276 + V_263 ) -> V_36 = V_30 -> V_36 ;
( V_276 + V_263 ) -> V_52 = F_131 ( V_30 ) ;
if ( ++ V_263 >= V_178 . V_279 )
break;
}
F_23 ( V_6 ) ;
V_274 -> V_282 = V_6 -> V_285 ;
V_274 -> V_279 = V_263 ;
V_277 = sizeof( V_178 ) + V_263 * sizeof( * V_276 ) ;
F_14 ( V_6 ) ;
V_202 = F_137 ( V_272 , V_274 , V_277 ) ;
F_136 ( V_274 ) ;
return V_202 ? - V_278 : 0 ;
}
int F_138 ( struct V_5 * V_6 , void T_9 * V_272 )
{
struct V_286 V_178 ;
struct V_275 V_276 ;
struct V_1 * V_2 ;
char T_9 * V_287 = V_272 + sizeof( V_178 ) ;
if ( F_133 ( & V_178 , V_272 , sizeof( V_178 ) ) )
return - V_278 ;
F_19 ( V_6 ) ;
V_2 = F_111 ( V_6 , V_178 . type , & V_178 . V_9 ) ;
if ( V_2 ) {
F_29 ( & V_276 . V_9 , & V_2 -> V_11 ) ;
V_276 . V_62 = V_2 -> V_62 ;
V_276 . type = V_2 -> type ;
V_276 . V_38 = V_2 -> V_38 ;
V_276 . V_36 = V_2 -> V_36 ;
V_276 . V_52 = F_131 ( V_2 ) ;
}
F_23 ( V_6 ) ;
if ( ! V_2 )
return - V_288 ;
return F_137 ( V_287 , & V_276 , sizeof( V_276 ) ) ? - V_278 : 0 ;
}
int F_139 ( struct V_5 * V_6 , void T_9 * V_272 )
{
struct V_289 V_178 ;
struct V_1 * V_2 ;
if ( F_133 ( & V_178 , V_272 , sizeof( V_178 ) ) )
return - V_278 ;
F_19 ( V_6 ) ;
V_2 = F_111 ( V_6 , V_57 , & V_178 . V_9 ) ;
if ( V_2 )
V_178 . type = V_2 -> V_134 ;
F_23 ( V_6 ) ;
if ( ! V_2 )
return - V_288 ;
return F_137 ( V_272 , & V_178 , sizeof( V_178 ) ) ? - V_278 : 0 ;
}
struct V_290 * F_140 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_290 * V_291 ;
F_18 ( L_1 , V_6 -> V_31 , V_2 ) ;
if ( F_9 ( V_292 , & V_2 -> V_24 ) ) {
F_18 ( L_13 ) ;
return NULL ;
}
V_291 = F_63 ( sizeof( * V_291 ) , V_131 ) ;
if ( ! V_291 )
return NULL ;
V_291 -> V_2 = F_26 ( V_2 ) ;
F_65 ( & V_291 -> V_155 ) ;
V_291 -> V_36 = V_58 ;
F_141 ( & V_291 -> V_293 , & V_2 -> V_156 ) ;
return V_291 ;
}
void F_142 ( struct V_290 * V_291 )
{
struct V_1 * V_2 = V_291 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_18 ( L_14 , V_6 -> V_31 , V_2 , V_291 ) ;
F_143 ( & V_291 -> V_293 ) ;
F_144 () ;
F_33 ( V_292 , & V_2 -> V_24 ) ;
F_15 ( V_2 ) ;
F_76 ( & V_291 -> V_155 ) ;
F_136 ( V_291 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_290 * V_291 , * V_263 ;
F_18 ( L_2 , V_2 ) ;
F_127 (chan, n, &conn->chan_list, list)
F_142 ( V_291 ) ;
}
static struct V_290 * F_145 ( struct V_1 * V_294 ,
T_4 V_62 )
{
struct V_290 * V_295 ;
F_80 (hchan, &hcon->chan_list, list) {
if ( V_295 -> V_62 == V_62 )
return V_295 ;
}
return NULL ;
}
struct V_290 * F_146 ( struct V_5 * V_6 , T_4 V_62 )
{
struct V_260 * V_261 = & V_6 -> V_262 ;
struct V_1 * V_294 ;
struct V_290 * V_295 = NULL ;
F_20 () ;
F_21 (hcon, &h->list, list) {
V_295 = F_145 ( V_294 , V_62 ) ;
if ( V_295 )
break;
}
F_22 () ;
return V_295 ;
}
