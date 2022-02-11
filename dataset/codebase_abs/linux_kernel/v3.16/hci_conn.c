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
if ( F_10 ( V_3 ) && ! ( V_3 -> V_13 & V_14 ) )
V_9 . V_29 = 0x01 ;
else
V_9 . V_29 = 0x00 ;
F_2 ( V_3 , V_30 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_31 V_9 ;
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_3 -> V_32 < V_33 )
return;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
F_2 ( V_2 -> V_3 , V_34 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_35 V_9 ;
V_9 . V_36 = V_37 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
F_2 ( V_2 -> V_3 , V_38 , sizeof( V_9 ) , & V_9 ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_39 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_40 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . V_36 = V_36 ;
F_2 ( V_2 -> V_3 , V_42 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_43 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_40 ;
V_9 . V_44 = F_15 ( V_2 -> V_41 ) ;
V_9 . V_36 = V_36 ;
F_2 ( V_2 -> V_3 , V_45 ,
sizeof( V_9 ) , & V_9 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_41 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_46 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_41 = F_8 ( V_41 ) ;
V_9 . V_28 = F_8 ( V_2 -> V_28 ) ;
F_2 ( V_3 , V_47 , sizeof( V_9 ) , & V_9 ) ;
}
bool F_17 ( struct V_1 * V_2 , T_2 V_41 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_48 V_9 ;
const struct V_49 * V_50 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_41 = F_8 ( V_41 ) ;
V_9 . V_51 = F_18 ( 0x00001f40 ) ;
V_9 . V_52 = F_18 ( 0x00001f40 ) ;
V_9 . V_53 = F_8 ( V_2 -> V_54 ) ;
switch ( V_2 -> V_54 & V_55 ) {
case V_56 :
if ( V_2 -> V_15 > F_19 ( V_57 ) )
return false ;
V_9 . V_58 = 0x02 ;
V_50 = & V_57 [ V_2 -> V_15 - 1 ] ;
break;
case V_59 :
if ( V_2 -> V_15 > F_19 ( V_60 ) )
return false ;
V_9 . V_58 = 0x01 ;
V_50 = & V_60 [ V_2 -> V_15 - 1 ] ;
break;
default:
return false ;
}
V_9 . V_28 = F_20 ( V_50 -> V_28 ) ;
V_9 . V_61 = F_20 ( V_50 -> V_61 ) ;
if ( F_2 ( V_3 , V_62 , sizeof( V_9 ) , & V_9 ) < 0 )
return false ;
return true ;
}
void F_21 ( struct V_1 * V_2 , T_3 V_63 , T_3 V_64 ,
T_3 V_65 , T_3 V_66 )
{
struct V_67 V_9 ;
struct V_5 * V_3 = V_2 -> V_3 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . V_68 = F_8 ( V_63 ) ;
V_9 . V_69 = F_8 ( V_64 ) ;
V_9 . V_70 = F_8 ( V_65 ) ;
V_9 . V_71 = F_8 ( V_66 ) ;
V_9 . V_72 = F_8 ( 0x0000 ) ;
V_9 . V_73 = F_8 ( 0x0000 ) ;
F_2 ( V_3 , V_74 , sizeof( V_9 ) , & V_9 ) ;
}
void F_22 ( struct V_1 * V_2 , T_4 V_75 , T_5 rand ,
T_1 V_76 [ 16 ] )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_77 V_9 ;
F_4 ( L_1 , V_2 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . rand = rand ;
V_9 . V_75 = V_75 ;
memcpy ( V_9 . V_76 , V_76 , sizeof( V_9 . V_76 ) ) ;
F_2 ( V_3 , V_78 , sizeof( V_9 ) , & V_9 ) ;
}
void F_23 ( struct V_1 * V_2 , T_1 V_79 )
{
struct V_1 * V_80 = V_2 -> V_81 ;
if ( ! V_80 )
return;
F_4 ( L_1 , V_2 ) ;
if ( ! V_79 ) {
if ( F_24 ( V_2 -> V_3 ) )
F_17 ( V_80 , V_2 -> V_41 ) ;
else
F_16 ( V_80 , V_2 -> V_41 ) ;
} else {
F_25 ( V_80 , V_79 ) ;
F_26 ( V_80 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_36 = F_28 ( V_2 ) ;
switch ( V_2 -> type ) {
case V_82 :
F_14 ( V_2 , V_36 ) ;
break;
default:
F_13 ( V_2 , V_36 ) ;
break;
}
}
static void F_29 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_30 ( V_84 , struct V_1 ,
V_85 . V_84 ) ;
int V_86 = F_31 ( & V_2 -> V_86 ) ;
F_4 ( L_2 , V_2 , F_32 ( V_2 -> V_10 ) ) ;
F_33 ( V_86 < 0 ) ;
if ( V_86 > 0 )
return;
switch ( V_2 -> V_10 ) {
case V_11 :
case V_87 :
if ( V_2 -> V_12 ) {
if ( V_2 -> type == V_88 )
F_11 ( V_2 ) ;
else if ( V_2 -> type == V_89 )
F_1 ( V_2 ) ;
} else if ( V_2 -> type == V_90 || V_2 -> type == V_91 ) {
F_12 ( V_2 ) ;
}
break;
case V_92 :
case V_93 :
F_27 ( V_2 ) ;
break;
default:
V_2 -> V_10 = V_94 ;
break;
}
}
static void F_34 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_30 ( V_84 , struct V_1 ,
V_95 . V_84 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_96 ) ;
if ( F_35 ( V_97 , & V_3 -> V_27 ) )
return;
if ( ! F_36 ( V_3 ) || ! F_36 ( V_2 ) )
return;
if ( V_2 -> V_96 != V_98 || ! ( V_2 -> V_16 & V_99 ) )
return;
if ( F_37 ( V_3 ) && F_37 ( V_2 ) ) {
struct V_100 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . V_61 = F_8 ( 0 ) ;
V_9 . V_101 = F_8 ( 0 ) ;
V_9 . V_102 = F_8 ( 0 ) ;
F_2 ( V_3 , V_103 , sizeof( V_9 ) , & V_9 ) ;
}
if ( ! F_38 ( V_104 , & V_2 -> V_27 ) ) {
struct V_105 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . V_106 = F_8 ( V_3 -> V_107 ) ;
V_9 . V_108 = F_8 ( V_3 -> V_109 ) ;
V_9 . V_15 = F_8 ( 4 ) ;
V_9 . V_110 = F_8 ( 1 ) ;
F_2 ( V_3 , V_111 , sizeof( V_9 ) , & V_9 ) ;
}
}
static void F_39 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_30 ( V_84 , struct V_1 ,
V_112 . V_84 ) ;
F_2 ( V_2 -> V_3 , V_113 , sizeof( V_2 -> V_18 ) ,
& V_2 -> V_18 ) ;
}
static void F_40 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_30 ( V_84 , struct V_1 ,
F_40 . V_84 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_4 ) ;
if ( F_35 ( V_114 , & V_3 -> V_115 ) ) {
T_6 V_116 = 0x00 ;
F_2 ( V_3 , V_117 , sizeof( V_116 ) ,
& V_116 ) ;
F_41 ( V_2 , V_118 ) ;
return;
}
F_1 ( V_2 ) ;
}
struct V_1 * F_42 ( struct V_5 * V_3 , int type , T_7 * V_18 )
{
struct V_1 * V_2 ;
F_4 ( L_5 , V_3 -> V_119 , V_18 ) ;
V_2 = F_43 ( sizeof( struct V_1 ) , V_120 ) ;
if ( ! V_2 )
return NULL ;
F_5 ( & V_2 -> V_18 , V_18 ) ;
F_5 ( & V_2 -> V_121 , & V_3 -> V_17 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> type = type ;
V_2 -> V_96 = V_98 ;
V_2 -> V_10 = V_122 ;
V_2 -> V_123 = V_124 ;
V_2 -> V_125 = V_3 -> V_125 ;
V_2 -> V_126 = 0xff ;
V_2 -> V_127 = 0xff ;
V_2 -> V_128 = V_129 ;
V_2 -> V_130 = V_129 ;
F_9 ( V_131 , & V_2 -> V_27 ) ;
V_2 -> V_132 = V_133 ;
switch ( type ) {
case V_88 :
V_2 -> V_28 = V_3 -> V_28 & V_134 ;
break;
case V_89 :
F_44 ( V_3 , & V_2 -> V_121 , & V_2 -> V_135 ) ;
break;
case V_90 :
if ( F_24 ( V_3 ) )
V_2 -> V_28 = ( V_3 -> V_136 & V_137 ) |
( V_3 -> V_136 & V_138 ) ;
else
V_2 -> V_28 = V_3 -> V_28 & V_139 ;
break;
case V_91 :
V_2 -> V_28 = V_3 -> V_136 & ~ V_138 ;
break;
}
F_45 ( & V_2 -> V_140 ) ;
F_46 ( & V_2 -> V_141 ) ;
F_47 ( & V_2 -> V_85 , F_29 ) ;
F_47 ( & V_2 -> V_112 , F_39 ) ;
F_47 ( & V_2 -> V_95 , F_34 ) ;
F_47 ( & V_2 -> F_40 , F_40 ) ;
F_48 ( & V_2 -> V_86 , 0 ) ;
F_49 ( V_3 ) ;
F_50 ( V_3 , V_2 ) ;
if ( V_3 -> V_142 )
V_3 -> V_142 ( V_3 , V_143 ) ;
F_51 ( V_2 ) ;
return V_2 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_6 , V_3 -> V_119 , V_2 , V_2 -> V_41 ) ;
F_52 ( & V_2 -> V_85 ) ;
F_52 ( & V_2 -> V_112 ) ;
F_52 ( & V_2 -> V_95 ) ;
if ( V_2 -> type == V_88 ) {
struct V_1 * V_80 = V_2 -> V_81 ;
if ( V_80 )
V_80 -> V_81 = NULL ;
V_3 -> V_144 += V_2 -> V_145 ;
} else if ( V_2 -> type == V_89 ) {
F_52 ( & V_2 -> F_40 ) ;
if ( V_3 -> V_146 )
V_3 -> V_147 += V_2 -> V_145 ;
else
V_3 -> V_144 += V_2 -> V_145 ;
} else {
struct V_1 * V_148 = V_2 -> V_81 ;
if ( V_148 ) {
V_148 -> V_81 = NULL ;
F_53 ( V_148 ) ;
}
}
F_54 ( V_2 ) ;
if ( V_2 -> V_149 )
F_55 ( V_2 -> V_149 ) ;
F_56 ( V_3 , V_2 ) ;
if ( V_3 -> V_142 )
V_3 -> V_142 ( V_3 , V_150 ) ;
F_57 ( & V_2 -> V_140 ) ;
F_58 ( V_2 ) ;
F_59 ( V_3 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
struct V_5 * F_61 ( T_7 * V_18 , T_7 * V_121 )
{
int V_151 = F_62 ( V_121 , V_152 ) ;
struct V_5 * V_3 = NULL , * V_153 ;
F_4 ( L_7 , V_121 , V_18 ) ;
F_63 ( & V_154 ) ;
F_64 (d, &hci_dev_list, list) {
if ( ! F_35 ( V_155 , & V_153 -> V_27 ) ||
F_35 ( V_97 , & V_153 -> V_27 ) ||
F_35 ( V_156 , & V_153 -> V_115 ) ||
V_153 -> V_157 != V_158 )
continue;
if ( V_151 ) {
if ( ! F_62 ( & V_153 -> V_17 , V_121 ) ) {
V_3 = V_153 ; break;
}
} else {
if ( F_62 ( & V_153 -> V_17 , V_18 ) ) {
V_3 = V_153 ; break;
}
}
}
if ( V_3 )
V_3 = F_49 ( V_3 ) ;
F_65 ( & V_154 ) ;
return V_3 ;
}
void F_41 ( struct V_1 * V_2 , T_6 V_79 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
V_2 -> V_10 = V_94 ;
F_66 ( V_3 , & V_2 -> V_18 , V_2 -> type , V_2 -> V_159 ,
V_79 ) ;
F_25 ( V_2 , V_79 ) ;
F_26 ( V_2 ) ;
F_67 ( V_3 ) ;
F_68 ( V_3 ) ;
}
static void F_69 ( struct V_5 * V_3 , T_6 V_79 )
{
struct V_1 * V_2 ;
if ( V_79 == 0 )
return;
F_70 ( L_8 ,
V_79 ) ;
F_71 ( V_3 ) ;
V_2 = F_72 ( V_3 , V_89 , V_11 ) ;
if ( ! V_2 )
goto V_160;
F_41 ( V_2 , V_79 ) ;
V_160:
F_73 ( V_3 ) ;
}
static void F_74 ( struct V_161 * V_162 ,
struct V_1 * V_2 )
{
struct V_163 V_9 ;
struct V_5 * V_3 = V_2 -> V_3 ;
T_6 V_164 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
if ( F_75 ( V_162 , false , & V_164 ) )
return;
V_9 . V_165 = F_8 ( V_3 -> V_166 ) ;
V_9 . V_167 = F_8 ( V_3 -> V_168 ) ;
F_5 ( & V_9 . V_169 , & V_2 -> V_18 ) ;
V_9 . V_170 = V_2 -> V_159 ;
V_9 . V_171 = V_164 ;
V_9 . V_68 = F_8 ( V_2 -> V_172 ) ;
V_9 . V_69 = F_8 ( V_2 -> V_173 ) ;
V_9 . V_71 = F_8 ( 0x002a ) ;
V_9 . V_72 = F_8 ( 0x0000 ) ;
V_9 . V_73 = F_8 ( 0x0000 ) ;
F_76 ( V_162 , V_174 , sizeof( V_9 ) , & V_9 ) ;
V_2 -> V_10 = V_11 ;
}
static void F_77 ( struct V_161 * V_162 ,
struct V_1 * V_2 )
{
struct V_5 * V_3 = V_162 -> V_3 ;
struct V_175 V_9 ;
T_6 V_164 ;
T_6 V_116 ;
V_116 = 0x00 ;
F_76 ( V_162 , V_117 , sizeof( V_116 ) , & V_116 ) ;
F_78 ( V_114 , & V_3 -> V_115 ) ;
if ( F_75 ( V_162 , false , & V_164 ) < 0 )
return;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . type = V_176 ;
V_9 . V_171 = V_164 ;
V_9 . V_177 = V_2 -> V_159 ;
F_5 ( & V_9 . V_178 , & V_2 -> V_18 ) ;
V_9 . V_179 = V_3 -> V_180 ;
F_76 ( V_162 , V_181 , sizeof( V_9 ) , & V_9 ) ;
V_116 = 0x01 ;
F_76 ( V_162 , V_117 , sizeof( V_116 ) , & V_116 ) ;
V_2 -> V_10 = V_11 ;
}
struct V_1 * F_79 ( struct V_5 * V_3 , T_7 * V_18 ,
T_6 V_159 , T_6 V_182 , T_6 V_123 )
{
struct V_183 * V_184 ;
struct V_1 * V_2 ;
struct V_185 * V_186 ;
struct V_161 V_162 ;
int V_187 ;
V_2 = F_80 ( V_3 , V_89 , V_18 ) ;
if ( V_2 ) {
V_2 -> V_188 = V_182 ;
V_2 -> V_123 = V_123 ;
goto V_160;
}
V_2 = F_72 ( V_3 , V_89 , V_11 ) ;
if ( V_2 )
return F_81 ( - V_189 ) ;
V_186 = F_82 ( V_3 , V_18 , V_159 ) ;
if ( V_186 && F_62 ( & V_186 -> V_190 , V_152 ) ) {
V_18 = & V_186 -> V_190 ;
V_159 = V_191 ;
}
V_2 = F_42 ( V_3 , V_89 , V_18 ) ;
if ( ! V_2 )
return F_81 ( - V_192 ) ;
V_2 -> V_159 = V_159 ;
V_2 -> V_182 = V_193 ;
V_2 -> V_188 = V_182 ;
V_2 -> V_123 = V_123 ;
F_83 ( & V_162 , V_3 ) ;
if ( F_35 ( V_114 , & V_3 -> V_115 ) ) {
F_77 ( & V_162 , V_2 ) ;
goto V_194;
}
V_2 -> V_12 = true ;
V_2 -> V_13 |= V_14 ;
V_184 = F_84 ( V_3 , & V_2 -> V_18 , V_2 -> V_159 ) ;
if ( V_184 ) {
V_2 -> V_172 = V_184 -> V_195 ;
V_2 -> V_173 = V_184 -> V_196 ;
} else {
V_2 -> V_172 = V_3 -> V_172 ;
V_2 -> V_173 = V_3 -> V_173 ;
}
if ( F_35 ( V_197 , & V_3 -> V_115 ) ) {
F_85 ( & V_162 ) ;
F_9 ( V_198 , & V_3 -> V_115 ) ;
}
F_74 ( & V_162 , V_2 ) ;
V_194:
V_187 = F_86 ( & V_162 , F_69 ) ;
if ( V_187 ) {
F_26 ( V_2 ) ;
return F_81 ( V_187 ) ;
}
V_160:
F_87 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_88 ( struct V_5 * V_3 , T_7 * V_18 ,
T_6 V_182 , T_6 V_123 )
{
struct V_1 * V_148 ;
if ( ! F_35 ( V_199 , & V_3 -> V_115 ) )
return F_81 ( - V_200 ) ;
V_148 = F_80 ( V_3 , V_88 , V_18 ) ;
if ( ! V_148 ) {
V_148 = F_42 ( V_3 , V_88 , V_18 ) ;
if ( ! V_148 )
return F_81 ( - V_192 ) ;
}
F_87 ( V_148 ) ;
if ( V_148 -> V_10 == V_122 || V_148 -> V_10 == V_94 ) {
V_148 -> V_182 = V_193 ;
V_148 -> V_188 = V_182 ;
V_148 -> V_123 = V_123 ;
F_3 ( V_148 ) ;
}
return V_148 ;
}
struct V_1 * F_89 ( struct V_5 * V_3 , int type , T_7 * V_18 ,
T_2 V_54 )
{
struct V_1 * V_148 ;
struct V_1 * V_80 ;
V_148 = F_88 ( V_3 , V_18 , V_193 , V_201 ) ;
if ( F_90 ( V_148 ) )
return V_148 ;
V_80 = F_80 ( V_3 , type , V_18 ) ;
if ( ! V_80 ) {
V_80 = F_42 ( V_3 , type , V_18 ) ;
if ( ! V_80 ) {
F_53 ( V_148 ) ;
return F_81 ( - V_192 ) ;
}
}
V_148 -> V_81 = V_80 ;
V_80 -> V_81 = V_148 ;
F_87 ( V_80 ) ;
V_80 -> V_54 = V_54 ;
if ( V_148 -> V_10 == V_93 &&
( V_80 -> V_10 == V_122 || V_80 -> V_10 == V_94 ) ) {
F_9 ( V_131 , & V_148 -> V_27 ) ;
F_91 ( V_148 , V_202 ) ;
if ( F_35 ( V_104 , & V_148 -> V_27 ) ) {
F_9 ( V_203 , & V_148 -> V_27 ) ;
return V_80 ;
}
F_23 ( V_148 , 0x00 ) ;
}
return V_80 ;
}
int F_92 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( F_35 ( V_204 , & V_2 -> V_3 -> V_27 ) ) {
if ( ! F_93 ( V_2 ) ||
! F_35 ( V_205 , & V_2 -> V_27 ) ||
V_2 -> V_127 != V_206 )
return 0 ;
}
if ( F_94 ( V_2 ) && ! ( V_2 -> V_13 & V_207 ) )
return 0 ;
return 1 ;
}
static int F_95 ( struct V_1 * V_2 , T_1 V_182 , T_1 V_123 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_188 > V_182 )
V_182 = V_2 -> V_188 ;
if ( V_182 > V_2 -> V_182 )
V_2 -> V_188 = V_182 ;
else if ( V_2 -> V_13 & V_208 )
return 1 ;
V_123 |= ( V_2 -> V_123 & 0x01 ) ;
V_2 -> V_123 = V_123 ;
if ( ! F_38 ( V_209 , & V_2 -> V_27 ) ) {
struct V_210 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
F_2 ( V_2 -> V_3 , V_211 ,
sizeof( V_9 ) , & V_9 ) ;
if ( V_2 -> V_13 & V_207 )
F_9 ( V_212 , & V_2 -> V_27 ) ;
else
F_9 ( V_213 , & V_2 -> V_27 ) ;
}
return 0 ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_38 ( V_213 , & V_2 -> V_27 ) ) {
struct V_214 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . V_215 = 0x01 ;
F_2 ( V_2 -> V_3 , V_216 , sizeof( V_9 ) ,
& V_9 ) ;
}
}
int F_97 ( struct V_1 * V_2 , T_1 V_182 , T_1 V_123 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_89 )
return F_98 ( V_2 , V_182 ) ;
if ( V_182 == V_217 )
return 1 ;
if ( V_182 == V_193 && ! F_94 ( V_2 ) )
return 1 ;
if ( ! ( V_2 -> V_13 & V_208 ) )
goto V_218;
if ( V_2 -> V_127 == V_206 &&
V_182 == V_219 )
goto V_215;
if ( ( V_2 -> V_127 == V_220 ||
V_2 -> V_127 == V_206 ) &&
V_182 == V_221 )
goto V_215;
if ( ( V_2 -> V_127 == V_222 ||
V_2 -> V_127 == V_223 ) &&
( V_182 == V_224 || V_182 == V_193 ) )
goto V_215;
if ( V_2 -> V_127 == V_225 &&
( V_182 == V_224 || V_182 == V_193 ||
V_2 -> V_226 == 16 ) )
goto V_215;
V_218:
if ( F_35 ( V_213 , & V_2 -> V_27 ) )
return 0 ;
if ( ! F_95 ( V_2 , V_182 , V_123 ) )
return 0 ;
V_215:
if ( V_2 -> V_13 & V_207 )
return 1 ;
F_96 ( V_2 ) ;
return 0 ;
}
int F_99 ( struct V_1 * V_2 , T_1 V_182 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_182 != V_221 && V_182 != V_219 )
return 1 ;
if ( V_2 -> V_182 == V_221 ||
V_2 -> V_182 == V_219 )
return 1 ;
return 0 ;
}
int F_100 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_38 ( V_209 , & V_2 -> V_27 ) ) {
struct V_227 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
F_2 ( V_2 -> V_3 , V_228 ,
sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
int F_101 ( struct V_1 * V_2 , T_1 V_229 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! V_229 && V_2 -> V_13 & V_14 )
return 1 ;
if ( ! F_38 ( V_230 , & V_2 -> V_27 ) ) {
struct V_231 V_9 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
V_9 . V_229 = V_229 ;
F_2 ( V_2 -> V_3 , V_232 , sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
void F_91 ( struct V_1 * V_2 , T_1 V_233 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_96 ) ;
if ( F_35 ( V_97 , & V_3 -> V_27 ) )
return;
if ( V_2 -> V_96 != V_234 )
goto V_235;
if ( ! F_35 ( V_131 , & V_2 -> V_27 ) && ! V_233 )
goto V_235;
if ( ! F_38 ( V_104 , & V_2 -> V_27 ) ) {
struct V_236 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
F_2 ( V_3 , V_237 , sizeof( V_9 ) , & V_9 ) ;
}
V_235:
if ( V_3 -> V_238 > 0 )
F_102 ( V_3 -> V_239 , & V_2 -> V_95 ,
F_103 ( V_3 -> V_238 ) ) ;
}
void F_104 ( struct V_5 * V_3 )
{
struct V_240 * V_241 = & V_3 -> V_242 ;
struct V_1 * V_243 , * V_244 ;
F_4 ( L_9 , V_3 -> V_119 ) ;
F_105 (c, n, &h->list, list) {
V_243 -> V_10 = V_94 ;
F_106 ( V_243 , V_245 ) ;
F_26 ( V_243 ) ;
}
}
void F_107 ( struct V_5 * V_3 )
{
struct V_1 * V_2 ;
F_4 ( L_9 , V_3 -> V_119 ) ;
F_71 ( V_3 ) ;
V_2 = F_72 ( V_3 , V_88 , V_87 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_73 ( V_3 ) ;
}
int F_108 ( void T_8 * V_246 )
{
struct V_1 * V_243 ;
struct V_247 V_162 , * V_248 ;
struct V_249 * V_250 ;
struct V_5 * V_3 ;
int V_244 = 0 , V_251 , V_187 ;
if ( F_109 ( & V_162 , V_246 , sizeof( V_162 ) ) )
return - V_252 ;
if ( ! V_162 . V_253 || V_162 . V_253 > ( V_254 * 2 ) / sizeof( * V_250 ) )
return - V_255 ;
V_251 = sizeof( V_162 ) + V_162 . V_253 * sizeof( * V_250 ) ;
V_248 = F_110 ( V_251 , V_120 ) ;
if ( ! V_248 )
return - V_192 ;
V_3 = F_111 ( V_162 . V_256 ) ;
if ( ! V_3 ) {
F_112 ( V_248 ) ;
return - V_257 ;
}
V_250 = V_248 -> V_258 ;
F_71 ( V_3 ) ;
F_64 (c, &hdev->conn_hash.list, list) {
F_5 ( & ( V_250 + V_244 ) -> V_17 , & V_243 -> V_18 ) ;
( V_250 + V_244 ) -> V_41 = V_243 -> V_41 ;
( V_250 + V_244 ) -> type = V_243 -> type ;
( V_250 + V_244 ) -> V_12 = V_243 -> V_12 ;
( V_250 + V_244 ) -> V_10 = V_243 -> V_10 ;
( V_250 + V_244 ) -> V_13 = V_243 -> V_13 ;
if ( ++ V_244 >= V_162 . V_253 )
break;
}
F_73 ( V_3 ) ;
V_248 -> V_256 = V_3 -> V_259 ;
V_248 -> V_253 = V_244 ;
V_251 = sizeof( V_162 ) + V_244 * sizeof( * V_250 ) ;
F_59 ( V_3 ) ;
V_187 = F_113 ( V_246 , V_248 , V_251 ) ;
F_112 ( V_248 ) ;
return V_187 ? - V_252 : 0 ;
}
int F_114 ( struct V_5 * V_3 , void T_8 * V_246 )
{
struct V_260 V_162 ;
struct V_249 V_250 ;
struct V_1 * V_2 ;
char T_8 * V_261 = V_246 + sizeof( V_162 ) ;
if ( F_109 ( & V_162 , V_246 , sizeof( V_162 ) ) )
return - V_252 ;
F_71 ( V_3 ) ;
V_2 = F_80 ( V_3 , V_162 . type , & V_162 . V_17 ) ;
if ( V_2 ) {
F_5 ( & V_250 . V_17 , & V_2 -> V_18 ) ;
V_250 . V_41 = V_2 -> V_41 ;
V_250 . type = V_2 -> type ;
V_250 . V_12 = V_2 -> V_12 ;
V_250 . V_10 = V_2 -> V_10 ;
V_250 . V_13 = V_2 -> V_13 ;
}
F_73 ( V_3 ) ;
if ( ! V_2 )
return - V_262 ;
return F_113 ( V_261 , & V_250 , sizeof( V_250 ) ) ? - V_252 : 0 ;
}
int F_115 ( struct V_5 * V_3 , void T_8 * V_246 )
{
struct V_263 V_162 ;
struct V_1 * V_2 ;
if ( F_109 ( & V_162 , V_246 , sizeof( V_162 ) ) )
return - V_252 ;
F_71 ( V_3 ) ;
V_2 = F_80 ( V_3 , V_88 , & V_162 . V_17 ) ;
if ( V_2 )
V_162 . type = V_2 -> V_123 ;
F_73 ( V_3 ) ;
if ( ! V_2 )
return - V_262 ;
return F_113 ( V_246 , & V_162 , sizeof( V_162 ) ) ? - V_252 : 0 ;
}
struct V_264 * F_116 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_264 * V_265 ;
F_4 ( L_10 , V_3 -> V_119 , V_2 ) ;
V_265 = F_43 ( sizeof( struct V_264 ) , V_120 ) ;
if ( ! V_265 )
return NULL ;
V_265 -> V_2 = V_2 ;
F_45 ( & V_265 -> V_140 ) ;
V_265 -> V_10 = V_93 ;
F_117 ( & V_265 -> V_266 , & V_2 -> V_141 ) ;
return V_265 ;
}
void F_118 ( struct V_264 * V_265 )
{
struct V_1 * V_2 = V_265 -> V_2 ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_11 , V_3 -> V_119 , V_2 , V_265 ) ;
F_119 ( & V_265 -> V_266 ) ;
F_120 () ;
F_53 ( V_2 ) ;
F_57 ( & V_265 -> V_140 ) ;
F_112 ( V_265 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_264 * V_265 , * V_244 ;
F_4 ( L_1 , V_2 ) ;
F_105 (chan, n, &conn->chan_list, list)
F_118 ( V_265 ) ;
}
static struct V_264 * F_121 ( struct V_1 * V_267 ,
T_2 V_41 )
{
struct V_264 * V_268 ;
F_64 (hchan, &hcon->chan_list, list) {
if ( V_268 -> V_41 == V_41 )
return V_268 ;
}
return NULL ;
}
struct V_264 * F_122 ( struct V_5 * V_3 , T_2 V_41 )
{
struct V_240 * V_241 = & V_3 -> V_242 ;
struct V_1 * V_267 ;
struct V_264 * V_268 = NULL ;
F_123 () ;
F_124 (hcon, &h->list, list) {
V_268 = F_121 ( V_267 , V_41 ) ;
if ( V_268 )
break;
}
F_125 () ;
return V_268 ;
}
