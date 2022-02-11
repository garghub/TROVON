static inline T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ,
V_2 -> V_4 * V_5 , 0 ) ;
}
static inline int F_3 ( struct V_1 * V_6 ,
struct V_1 * V_7 )
{
if ( V_6 -> V_4 != V_7 -> V_4 )
return 1 ;
return memcmp ( V_6 -> V_3 , V_7 -> V_3 , V_6 -> V_4 * V_5 ) ;
}
static int F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_9 -> V_16 -> V_9 . V_17 ;
int V_4 , V_18 , V_19 , V_20 ;
struct V_21 * V_22 ;
struct V_1 V_2 ;
bool V_23 = false ;
T_1 V_24 ;
V_4 = V_13 -> V_25 ;
V_18 = V_5 * V_4 ;
V_2 . V_3 = V_13 -> V_26 ;
V_2 . V_4 = V_4 ;
V_24 = F_1 ( & V_2 ) ;
if ( V_11 -> V_27 & V_28 ) {
V_19 = V_29 ;
F_5 (esw->offloads.mod_hdr_tbl, mh,
mod_hdr_hlist, hash_key) {
if ( ! F_3 ( & V_22 -> V_2 , & V_2 ) ) {
V_23 = true ;
break;
}
}
} else {
V_19 = V_30 ;
F_5 (priv->fs.tc.mod_hdr_tbl, mh,
mod_hdr_hlist, hash_key) {
if ( ! F_3 ( & V_22 -> V_2 , & V_2 ) ) {
V_23 = true ;
break;
}
}
}
if ( V_23 )
goto V_31;
V_22 = F_6 ( sizeof( * V_22 ) + V_18 , V_32 ) ;
if ( ! V_22 )
return - V_33 ;
V_22 -> V_2 . V_3 = ( void * ) V_22 + sizeof( * V_22 ) ;
memcpy ( V_22 -> V_2 . V_3 , V_2 . V_3 , V_18 ) ;
V_22 -> V_2 . V_4 = V_4 ;
F_7 ( & V_22 -> V_34 ) ;
V_20 = F_8 ( V_9 -> V_16 , V_19 ,
V_22 -> V_2 . V_4 ,
V_22 -> V_2 . V_3 ,
& V_22 -> V_35 ) ;
if ( V_20 )
goto V_36;
if ( V_11 -> V_27 & V_28 )
F_9 ( V_15 -> V_37 . V_38 , & V_22 -> V_39 , V_24 ) ;
else
F_9 ( V_9 -> V_40 . V_41 . V_38 , & V_22 -> V_39 , V_24 ) ;
V_31:
F_10 ( & V_11 -> V_42 , & V_22 -> V_34 ) ;
if ( V_11 -> V_27 & V_28 )
V_11 -> V_43 -> V_35 = V_22 -> V_35 ;
else
V_11 -> V_44 -> V_35 = V_22 -> V_35 ;
return 0 ;
V_36:
F_11 ( V_22 ) ;
return V_20 ;
}
static void F_12 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_45 * V_46 = V_11 -> V_42 . V_46 ;
F_13 ( & V_11 -> V_42 ) ;
if ( F_14 ( V_46 ) ) {
struct V_21 * V_22 ;
V_22 = F_15 ( V_46 , struct V_21 , V_34 ) ;
F_16 ( V_9 -> V_16 , V_22 -> V_35 ) ;
F_17 ( & V_22 -> V_39 ) ;
F_11 ( V_22 ) ;
}
}
static struct V_47 *
F_18 ( struct V_8 * V_9 ,
struct V_12 * V_13 ,
struct V_10 * V_11 )
{
struct V_48 * V_49 = V_11 -> V_44 ;
struct V_50 * V_51 = V_9 -> V_16 ;
struct V_52 V_53 = {} ;
struct V_54 V_55 = {
. V_56 = V_49 -> V_56 ,
. V_57 = V_49 -> V_57 ,
. V_58 = 0 ,
} ;
struct V_59 * V_60 = NULL ;
struct V_47 * V_61 ;
bool V_62 = false ;
int V_20 ;
if ( V_49 -> V_56 & V_63 ) {
V_53 . type = V_64 ;
V_53 . V_65 = V_9 -> V_40 . V_66 . V_65 . V_67 ;
} else if ( V_49 -> V_56 & V_68 ) {
V_60 = F_19 ( V_51 , true ) ;
if ( F_20 ( V_60 ) )
return F_21 ( V_60 ) ;
V_53 . type = V_69 ;
V_53 . V_60 = V_60 ;
}
if ( V_49 -> V_56 & V_70 ) {
V_20 = F_4 ( V_9 , V_11 , V_13 ) ;
V_55 . V_71 = V_49 -> V_35 ;
F_11 ( V_13 -> V_26 ) ;
if ( V_20 ) {
V_61 = F_22 ( V_20 ) ;
goto V_72;
}
}
if ( F_23 ( V_9 -> V_40 . V_41 . V_67 ) ) {
V_9 -> V_40 . V_41 . V_67 =
F_24 ( V_9 -> V_40 . V_73 ,
V_74 ,
V_75 ,
V_76 ,
0 , 0 ) ;
if ( F_20 ( V_9 -> V_40 . V_41 . V_67 ) ) {
F_25 ( V_9 -> V_77 ,
L_1 ) ;
V_61 = F_21 ( V_9 -> V_40 . V_41 . V_67 ) ;
goto V_78;
}
V_62 = true ;
}
V_13 -> V_79 . V_80 = V_81 ;
V_61 = F_26 ( V_9 -> V_40 . V_41 . V_67 , & V_13 -> V_79 ,
& V_55 , & V_53 , 1 ) ;
if ( F_20 ( V_61 ) )
goto V_82;
return V_61 ;
V_82:
if ( V_62 ) {
F_27 ( V_9 -> V_40 . V_41 . V_67 ) ;
V_9 -> V_40 . V_41 . V_67 = NULL ;
}
V_78:
if ( V_49 -> V_56 & V_70 )
F_12 ( V_9 , V_11 ) ;
V_72:
F_28 ( V_51 , V_60 ) ;
return V_61 ;
}
static void F_29 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_48 * V_49 = V_11 -> V_44 ;
struct V_59 * V_60 = NULL ;
V_60 = F_30 ( V_11 -> V_61 ) ;
F_31 ( V_11 -> V_61 ) ;
F_28 ( V_9 -> V_16 , V_60 ) ;
if ( ! F_32 ( V_9 ) && ( V_9 -> V_40 . V_41 . V_67 ) ) {
F_27 ( V_9 -> V_40 . V_41 . V_67 ) ;
V_9 -> V_40 . V_41 . V_67 = NULL ;
}
if ( V_49 -> V_56 & V_70 )
F_12 ( V_9 , V_11 ) ;
}
static struct V_47 *
F_33 ( struct V_8 * V_9 ,
struct V_12 * V_13 ,
struct V_10 * V_11 )
{
struct V_14 * V_15 = V_9 -> V_16 -> V_9 . V_17 ;
struct V_83 * V_49 = V_11 -> V_43 ;
struct V_84 * V_85 , * V_86 = NULL ;
struct V_47 * V_61 = NULL ;
struct V_87 * V_88 ;
struct V_8 * V_89 ;
int V_20 ;
if ( V_49 -> V_56 & V_90 ) {
V_85 = F_34 ( F_35 ( V_9 -> V_77 ) ,
V_49 -> V_13 -> V_91 ) ;
V_20 = F_36 ( V_9 , & V_13 -> V_92 ,
V_85 , & V_86 , V_11 ) ;
if ( V_20 ) {
V_61 = F_22 ( V_20 ) ;
if ( V_20 != - V_93 )
goto V_94;
}
V_89 = F_37 ( V_86 ) ;
V_88 = V_89 -> V_95 ;
V_49 -> V_96 = V_88 -> V_97 ;
}
V_20 = F_38 ( V_15 , V_49 ) ;
if ( V_20 ) {
V_61 = F_22 ( V_20 ) ;
goto V_98;
}
if ( V_49 -> V_56 & V_70 ) {
V_20 = F_4 ( V_9 , V_11 , V_13 ) ;
F_11 ( V_13 -> V_26 ) ;
if ( V_20 ) {
V_61 = F_22 ( V_20 ) ;
goto V_99;
}
}
if ( V_61 != F_22 ( - V_93 ) ) {
V_61 = F_39 ( V_15 , & V_13 -> V_79 , V_49 ) ;
if ( F_20 ( V_61 ) )
goto V_82;
}
return V_61 ;
V_82:
if ( V_49 -> V_56 & V_70 )
F_12 ( V_9 , V_11 ) ;
V_99:
F_40 ( V_15 , V_49 ) ;
V_98:
if ( V_49 -> V_56 & V_90 )
F_41 ( V_9 , V_11 ) ;
V_94:
return V_61 ;
}
static void F_42 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_14 * V_15 = V_9 -> V_16 -> V_9 . V_17 ;
struct V_83 * V_49 = V_11 -> V_43 ;
if ( V_11 -> V_27 & V_100 ) {
V_11 -> V_27 &= ~ V_100 ;
F_43 ( V_15 , V_11 -> V_61 , V_49 ) ;
}
F_40 ( V_15 , V_49 ) ;
if ( V_49 -> V_56 & V_90 ) {
F_41 ( V_9 , V_11 ) ;
F_44 ( V_49 -> V_13 ) ;
}
if ( V_49 -> V_56 & V_70 )
F_12 ( V_9 , V_11 ) ;
}
void F_45 ( struct V_8 * V_9 ,
struct V_101 * V_102 )
{
struct V_14 * V_15 = V_9 -> V_16 -> V_9 . V_17 ;
struct V_83 * V_43 ;
struct V_10 * V_11 ;
int V_20 ;
V_20 = F_46 ( V_9 -> V_16 , V_102 -> V_103 ,
V_102 -> V_104 , V_102 -> V_105 ,
& V_102 -> V_58 ) ;
if ( V_20 ) {
F_47 ( V_9 -> V_16 , L_2 ,
V_20 ) ;
return;
}
V_102 -> V_27 |= V_106 ;
F_48 ( V_9 ) ;
F_49 (flow, &e->flows, encap) {
V_43 = V_11 -> V_43 ;
V_43 -> V_58 = V_102 -> V_58 ;
V_11 -> V_61 = F_39 ( V_15 , & V_43 -> V_13 -> V_79 , V_43 ) ;
if ( F_20 ( V_11 -> V_61 ) ) {
V_20 = F_50 ( V_11 -> V_61 ) ;
F_47 ( V_9 -> V_16 , L_3 ,
V_20 ) ;
continue;
}
V_11 -> V_27 |= V_100 ;
}
}
void F_51 ( struct V_8 * V_9 ,
struct V_101 * V_102 )
{
struct V_14 * V_15 = V_9 -> V_16 -> V_9 . V_17 ;
struct V_10 * V_11 ;
F_49 (flow, &e->flows, encap) {
if ( V_11 -> V_27 & V_100 ) {
V_11 -> V_27 &= ~ V_100 ;
F_43 ( V_15 , V_11 -> V_61 , V_11 -> V_43 ) ;
}
}
if ( V_102 -> V_27 & V_106 ) {
V_102 -> V_27 &= ~ V_106 ;
F_52 ( V_9 -> V_16 , V_102 -> V_58 ) ;
}
}
void F_53 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = & V_108 -> V_110 ;
T_2 V_111 , V_112 , V_113 = 0 ;
struct V_10 * V_11 ;
struct V_101 * V_102 ;
struct V_59 * V_60 ;
struct V_114 * V_115 ;
bool V_116 = false ;
struct V_117 * V_118 ;
if ( V_110 -> V_119 == V_120 )
V_115 = & V_121 ;
#if F_54 ( V_122 )
else if ( V_110 -> V_119 == V_123 )
V_115 = V_124 -> V_125 ;
#endif
else
return;
F_49 (e, &nhe->encap_list, encap_list) {
if ( ! ( V_102 -> V_27 & V_106 ) )
continue;
F_49 (flow, &e->flows, encap) {
if ( V_11 -> V_27 & V_100 ) {
V_60 = F_30 ( V_11 -> V_61 ) ;
F_55 ( V_60 , & V_111 , & V_112 , & V_113 ) ;
if ( F_56 ( ( unsigned long ) V_113 , V_108 -> V_126 ) ) {
V_116 = true ;
break;
}
}
}
}
if ( V_116 ) {
V_108 -> V_126 = V_127 ;
V_118 = F_57 ( V_115 , & V_110 -> V_128 , V_110 -> V_51 ) ;
if ( ! V_118 ) {
F_58 ( 1 , L_4 ) ;
return;
}
F_59 ( V_118 , NULL ) ;
F_60 ( V_118 ) ;
}
}
static void F_41 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_45 * V_46 = V_11 -> V_129 . V_46 ;
F_13 ( & V_11 -> V_129 ) ;
if ( F_14 ( V_46 ) ) {
struct V_101 * V_102 ;
V_102 = F_15 ( V_46 , struct V_101 , V_34 ) ;
F_61 ( F_37 ( V_102 -> V_85 ) , V_102 ) ;
if ( V_102 -> V_27 & V_106 )
F_52 ( V_9 -> V_16 , V_102 -> V_58 ) ;
F_62 ( & V_102 -> V_130 ) ;
F_11 ( V_102 -> V_105 ) ;
F_11 ( V_102 ) ;
}
}
static void F_63 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
if ( V_11 -> V_27 & V_28 )
F_42 ( V_9 , V_11 ) ;
else
F_29 ( V_9 , V_11 ) ;
}
static void F_64 ( struct V_131 * V_79 ,
struct V_132 * V_133 )
{
void * V_134 = F_65 ( V_135 , V_79 -> V_136 ,
V_137 ) ;
void * V_138 = F_65 ( V_135 , V_79 -> V_139 ,
V_137 ) ;
void * V_140 = F_65 ( V_135 , V_79 -> V_136 ,
V_141 ) ;
void * V_142 = F_65 ( V_135 , V_79 -> V_139 ,
V_141 ) ;
F_66 ( V_143 , V_134 , V_144 ) ;
F_67 ( V_143 , V_138 , V_144 , V_145 ) ;
if ( F_68 ( V_133 -> V_146 , V_147 ) ) {
struct V_148 * V_2 =
F_69 ( V_133 -> V_146 ,
V_147 ,
V_133 -> V_2 ) ;
struct V_148 * V_149 =
F_69 ( V_133 -> V_146 ,
V_147 ,
V_133 -> V_149 ) ;
F_67 ( V_150 , V_140 , V_151 ,
F_70 ( V_149 -> V_152 ) ) ;
F_67 ( V_150 , V_142 , V_151 ,
F_70 ( V_2 -> V_152 ) ) ;
}
}
static int F_71 ( struct V_8 * V_9 ,
struct V_131 * V_79 ,
struct V_132 * V_133 )
{
void * V_134 = F_65 ( V_135 , V_79 -> V_136 ,
V_137 ) ;
void * V_138 = F_65 ( V_135 , V_79 -> V_139 ,
V_137 ) ;
struct V_153 * V_154 =
F_69 ( V_133 -> V_146 ,
V_155 ,
V_133 -> V_2 ) ;
if ( F_68 ( V_133 -> V_146 , V_156 ) ) {
struct V_157 * V_2 =
F_69 ( V_133 -> V_146 ,
V_156 ,
V_133 -> V_2 ) ;
struct V_157 * V_149 =
F_69 ( V_133 -> V_146 ,
V_156 ,
V_133 -> V_149 ) ;
struct V_14 * V_15 = V_9 -> V_16 -> V_9 . V_17 ;
struct V_84 * V_158 = F_72 ( V_15 ) ;
struct V_8 * V_159 = F_37 ( V_158 ) ;
if ( F_73 ( & V_149 -> V_160 , 0xff , sizeof( V_149 -> V_160 ) ) )
goto V_161;
if ( F_74 ( V_159 , F_75 ( V_2 -> V_160 ) ) &&
F_76 ( V_9 -> V_16 , V_162 ) )
F_64 ( V_79 , V_133 ) ;
else {
F_77 ( V_9 -> V_77 ,
L_5 , F_75 ( V_2 -> V_160 ) ) ;
return - V_163 ;
}
F_67 ( V_143 , V_134 ,
V_164 , F_78 ( V_149 -> V_160 ) ) ;
F_67 ( V_143 , V_138 ,
V_164 , F_78 ( V_2 -> V_160 ) ) ;
F_67 ( V_143 , V_134 ,
V_165 , F_78 ( V_149 -> V_166 ) ) ;
F_67 ( V_143 , V_138 ,
V_165 , F_78 ( V_2 -> V_166 ) ) ;
} else {
V_161:
F_77 ( V_9 -> V_77 ,
L_6 ) ;
return - V_163 ;
}
if ( V_154 -> V_167 == V_168 ) {
struct V_169 * V_2 =
F_69 ( V_133 -> V_146 ,
V_170 ,
V_133 -> V_2 ) ;
struct V_169 * V_149 =
F_69 ( V_133 -> V_146 ,
V_170 ,
V_133 -> V_149 ) ;
F_67 ( V_143 , V_134 ,
V_171 . V_172 . V_173 ,
F_79 ( V_149 -> V_166 ) ) ;
F_67 ( V_143 , V_138 ,
V_171 . V_172 . V_173 ,
F_79 ( V_2 -> V_166 ) ) ;
F_67 ( V_143 , V_134 ,
V_174 . V_172 . V_173 ,
F_79 ( V_149 -> V_160 ) ) ;
F_67 ( V_143 , V_138 ,
V_174 . V_172 . V_173 ,
F_79 ( V_2 -> V_160 ) ) ;
F_66 ( V_143 , V_134 , V_175 ) ;
F_67 ( V_143 , V_138 , V_175 , V_176 ) ;
} else if ( V_154 -> V_167 == V_177 ) {
struct V_178 * V_2 =
F_69 ( V_133 -> V_146 ,
V_179 ,
V_133 -> V_2 ) ;
struct V_178 * V_149 =
F_69 ( V_133 -> V_146 ,
V_179 ,
V_133 -> V_149 ) ;
memcpy ( F_65 ( V_143 , V_134 ,
V_171 . V_180 . V_181 ) ,
& V_149 -> V_166 , F_80 ( V_180 , V_181 ) ) ;
memcpy ( F_65 ( V_143 , V_138 ,
V_171 . V_180 . V_181 ) ,
& V_2 -> V_166 , F_80 ( V_180 , V_181 ) ) ;
memcpy ( F_65 ( V_143 , V_134 ,
V_174 . V_180 . V_181 ) ,
& V_149 -> V_160 , F_80 ( V_180 , V_181 ) ) ;
memcpy ( F_65 ( V_143 , V_138 ,
V_174 . V_180 . V_181 ) ,
& V_2 -> V_160 , F_80 ( V_180 , V_181 ) ) ;
F_66 ( V_143 , V_134 , V_175 ) ;
F_67 ( V_143 , V_138 , V_175 , V_182 ) ;
}
F_66 ( V_143 , V_134 , V_183 ) ;
F_66 ( V_143 , V_134 , V_184 ) ;
F_81 ( F_65 ( V_143 , V_138 ,
V_183 ) , V_9 -> V_77 -> V_185 ) ;
F_67 ( V_143 , V_134 , V_186 , 1 ) ;
F_67 ( V_143 , V_138 , V_186 , 0 ) ;
return 0 ;
}
static int F_82 ( struct V_8 * V_9 ,
struct V_131 * V_79 ,
struct V_132 * V_133 ,
T_3 * V_187 )
{
void * V_134 = F_65 ( V_135 , V_79 -> V_136 ,
V_137 ) ;
void * V_138 = F_65 ( V_135 , V_79 -> V_139 ,
V_137 ) ;
T_4 V_167 = 0 ;
T_3 V_188 = 0 ;
* V_187 = V_189 ;
if ( V_133 -> V_146 -> V_190 &
~ ( F_83 ( V_191 ) |
F_83 ( V_192 ) |
F_83 ( V_193 ) |
F_83 ( V_194 ) |
F_83 ( V_168 ) |
F_83 ( V_177 ) |
F_83 ( V_195 ) |
F_83 ( V_147 ) |
F_83 ( V_170 ) |
F_83 ( V_179 ) |
F_83 ( V_156 ) |
F_83 ( V_155 ) |
F_83 ( V_196 ) |
F_83 ( V_197 ) ) ) {
F_77 ( V_9 -> V_77 , L_7 ,
V_133 -> V_146 -> V_190 ) ;
return - V_163 ;
}
if ( ( F_68 ( V_133 -> V_146 ,
V_170 ) ||
F_68 ( V_133 -> V_146 , V_147 ) ||
F_68 ( V_133 -> V_146 , V_156 ) ) &&
F_68 ( V_133 -> V_146 , V_155 ) ) {
struct V_153 * V_2 =
F_69 ( V_133 -> V_146 ,
V_155 ,
V_133 -> V_2 ) ;
switch ( V_2 -> V_167 ) {
case V_168 :
case V_177 :
if ( F_71 ( V_9 , V_79 , V_133 ) )
return - V_163 ;
break;
default:
return - V_163 ;
}
V_134 = F_65 ( V_135 , V_79 -> V_136 ,
V_198 ) ;
V_138 = F_65 ( V_135 , V_79 -> V_139 ,
V_198 ) ;
}
if ( F_68 ( V_133 -> V_146 , V_191 ) ) {
struct V_153 * V_2 =
F_69 ( V_133 -> V_146 ,
V_191 ,
V_133 -> V_2 ) ;
struct V_153 * V_149 =
F_69 ( V_133 -> V_146 ,
V_191 ,
V_133 -> V_149 ) ;
V_167 = V_2 -> V_167 ;
if ( V_149 -> V_27 & V_199 ) {
F_67 ( V_143 , V_134 , V_186 , 1 ) ;
F_67 ( V_143 , V_138 , V_186 ,
V_2 -> V_27 & V_199 ) ;
if ( V_2 -> V_27 & V_199 )
* V_187 = V_200 ;
}
}
if ( F_68 ( V_133 -> V_146 , V_192 ) ) {
struct V_201 * V_2 =
F_69 ( V_133 -> V_146 ,
V_192 ,
V_133 -> V_2 ) ;
struct V_201 * V_149 =
F_69 ( V_133 -> V_146 ,
V_192 ,
V_133 -> V_149 ) ;
V_188 = V_2 -> V_188 ;
F_67 ( V_143 , V_134 , V_175 ,
F_78 ( V_149 -> V_202 ) ) ;
F_67 ( V_143 , V_138 , V_175 ,
F_78 ( V_2 -> V_202 ) ) ;
F_67 ( V_143 , V_134 , V_144 ,
V_149 -> V_188 ) ;
F_67 ( V_143 , V_138 , V_144 ,
V_2 -> V_188 ) ;
if ( V_149 -> V_188 )
* V_187 = V_200 ;
}
if ( F_68 ( V_133 -> V_146 , V_193 ) ) {
struct V_203 * V_2 =
F_69 ( V_133 -> V_146 ,
V_193 ,
V_133 -> V_2 ) ;
struct V_203 * V_149 =
F_69 ( V_133 -> V_146 ,
V_193 ,
V_133 -> V_149 ) ;
F_81 ( F_65 ( V_143 , V_134 ,
V_183 ) ,
V_149 -> V_160 ) ;
F_81 ( F_65 ( V_143 , V_138 ,
V_183 ) ,
V_2 -> V_160 ) ;
F_81 ( F_65 ( V_143 , V_134 ,
V_204 ) ,
V_149 -> V_166 ) ;
F_81 ( F_65 ( V_143 , V_138 ,
V_204 ) ,
V_2 -> V_166 ) ;
}
if ( F_68 ( V_133 -> V_146 , V_194 ) ) {
struct V_205 * V_2 =
F_69 ( V_133 -> V_146 ,
V_194 ,
V_133 -> V_2 ) ;
struct V_205 * V_149 =
F_69 ( V_133 -> V_146 ,
V_194 ,
V_133 -> V_149 ) ;
if ( V_149 -> V_206 || V_149 -> V_207 ) {
F_67 ( V_143 , V_134 , V_208 , 1 ) ;
F_67 ( V_143 , V_138 , V_208 , 1 ) ;
F_67 ( V_143 , V_134 , V_209 , V_149 -> V_206 ) ;
F_67 ( V_143 , V_138 , V_209 , V_2 -> V_206 ) ;
F_67 ( V_143 , V_134 , V_210 , V_149 -> V_207 ) ;
F_67 ( V_143 , V_138 , V_210 , V_2 -> V_207 ) ;
}
}
if ( V_167 == V_168 ) {
struct V_169 * V_2 =
F_69 ( V_133 -> V_146 ,
V_168 ,
V_133 -> V_2 ) ;
struct V_169 * V_149 =
F_69 ( V_133 -> V_146 ,
V_168 ,
V_133 -> V_149 ) ;
memcpy ( F_65 ( V_143 , V_134 ,
V_171 . V_172 . V_173 ) ,
& V_149 -> V_166 , sizeof( V_149 -> V_166 ) ) ;
memcpy ( F_65 ( V_143 , V_138 ,
V_171 . V_172 . V_173 ) ,
& V_2 -> V_166 , sizeof( V_2 -> V_166 ) ) ;
memcpy ( F_65 ( V_143 , V_134 ,
V_174 . V_172 . V_173 ) ,
& V_149 -> V_160 , sizeof( V_149 -> V_160 ) ) ;
memcpy ( F_65 ( V_143 , V_138 ,
V_174 . V_172 . V_173 ) ,
& V_2 -> V_160 , sizeof( V_2 -> V_160 ) ) ;
if ( V_149 -> V_166 || V_149 -> V_160 )
* V_187 = V_200 ;
}
if ( V_167 == V_177 ) {
struct V_178 * V_2 =
F_69 ( V_133 -> V_146 ,
V_177 ,
V_133 -> V_2 ) ;
struct V_178 * V_149 =
F_69 ( V_133 -> V_146 ,
V_177 ,
V_133 -> V_149 ) ;
memcpy ( F_65 ( V_143 , V_134 ,
V_171 . V_180 . V_181 ) ,
& V_149 -> V_166 , sizeof( V_149 -> V_166 ) ) ;
memcpy ( F_65 ( V_143 , V_138 ,
V_171 . V_180 . V_181 ) ,
& V_2 -> V_166 , sizeof( V_2 -> V_166 ) ) ;
memcpy ( F_65 ( V_143 , V_134 ,
V_174 . V_180 . V_181 ) ,
& V_149 -> V_160 , sizeof( V_149 -> V_160 ) ) ;
memcpy ( F_65 ( V_143 , V_138 ,
V_174 . V_180 . V_181 ) ,
& V_2 -> V_160 , sizeof( V_2 -> V_160 ) ) ;
if ( F_84 ( & V_149 -> V_166 ) != V_211 ||
F_84 ( & V_149 -> V_160 ) != V_211 )
* V_187 = V_200 ;
}
if ( F_68 ( V_133 -> V_146 , V_197 ) ) {
struct V_212 * V_2 =
F_69 ( V_133 -> V_146 ,
V_197 ,
V_133 -> V_2 ) ;
struct V_212 * V_149 =
F_69 ( V_133 -> V_146 ,
V_197 ,
V_133 -> V_149 ) ;
F_67 ( V_143 , V_134 , V_213 , V_149 -> V_214 & 0x3 ) ;
F_67 ( V_143 , V_138 , V_213 , V_2 -> V_214 & 0x3 ) ;
F_67 ( V_143 , V_134 , V_215 , V_149 -> V_214 >> 2 ) ;
F_67 ( V_143 , V_138 , V_215 , V_2 -> V_214 >> 2 ) ;
F_67 ( V_143 , V_134 , V_216 , V_149 -> V_217 ) ;
F_67 ( V_143 , V_138 , V_216 , V_2 -> V_217 ) ;
if ( V_149 -> V_217 &&
! F_85 ( V_9 -> V_16 ,
V_218 . V_219 ) )
return - V_163 ;
if ( V_149 -> V_214 || V_149 -> V_217 )
* V_187 = V_200 ;
}
if ( F_68 ( V_133 -> V_146 , V_195 ) ) {
struct V_157 * V_2 =
F_69 ( V_133 -> V_146 ,
V_195 ,
V_133 -> V_2 ) ;
struct V_157 * V_149 =
F_69 ( V_133 -> V_146 ,
V_195 ,
V_133 -> V_149 ) ;
switch ( V_188 ) {
case V_220 :
F_67 ( V_143 , V_134 ,
V_221 , F_78 ( V_149 -> V_166 ) ) ;
F_67 ( V_143 , V_138 ,
V_221 , F_78 ( V_2 -> V_166 ) ) ;
F_67 ( V_143 , V_134 ,
V_222 , F_78 ( V_149 -> V_160 ) ) ;
F_67 ( V_143 , V_138 ,
V_222 , F_78 ( V_2 -> V_160 ) ) ;
break;
case V_145 :
F_67 ( V_143 , V_134 ,
V_165 , F_78 ( V_149 -> V_166 ) ) ;
F_67 ( V_143 , V_138 ,
V_165 , F_78 ( V_2 -> V_166 ) ) ;
F_67 ( V_143 , V_134 ,
V_164 , F_78 ( V_149 -> V_160 ) ) ;
F_67 ( V_143 , V_138 ,
V_164 , F_78 ( V_2 -> V_160 ) ) ;
break;
default:
F_25 ( V_9 -> V_77 ,
L_8 ) ;
return - V_223 ;
}
if ( V_149 -> V_166 || V_149 -> V_160 )
* V_187 = V_224 ;
}
if ( F_68 ( V_133 -> V_146 , V_196 ) ) {
struct V_225 * V_2 =
F_69 ( V_133 -> V_146 ,
V_196 ,
V_133 -> V_2 ) ;
struct V_225 * V_149 =
F_69 ( V_133 -> V_146 ,
V_196 ,
V_133 -> V_149 ) ;
F_67 ( V_143 , V_134 , V_226 ,
F_78 ( V_149 -> V_27 ) ) ;
F_67 ( V_143 , V_138 , V_226 ,
F_78 ( V_2 -> V_27 ) ) ;
if ( V_149 -> V_27 )
* V_187 = V_224 ;
}
return 0 ;
}
static int F_86 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_131 * V_79 ,
struct V_132 * V_133 )
{
struct V_50 * V_51 = V_9 -> V_16 ;
struct V_14 * V_15 = V_51 -> V_9 . V_17 ;
struct V_87 * V_88 = V_9 -> V_95 ;
struct V_227 * V_97 ;
T_3 V_187 ;
int V_20 ;
V_20 = F_82 ( V_9 , V_79 , V_133 , & V_187 ) ;
if ( ! V_20 && ( V_11 -> V_27 & V_28 ) ) {
V_97 = V_88 -> V_97 ;
if ( V_97 -> V_228 != V_229 &&
( V_15 -> V_37 . V_230 != V_231 &&
V_15 -> V_37 . V_230 < V_187 ) ) {
F_77 ( V_9 -> V_77 ,
L_9 ,
V_187 , V_15 -> V_37 . V_230 ) ;
return - V_163 ;
}
}
return V_20 ;
}
static int F_87 ( T_3 V_232 , T_1 V_149 , T_1 V_233 , T_1 V_234 ,
struct V_235 * V_236 ,
struct V_235 * V_237 )
{
T_1 * V_238 , * V_239 ;
if ( V_232 >= V_240 )
goto V_36;
V_238 = ( T_1 * ) ( F_88 ( V_236 , V_232 ) + V_234 ) ;
V_239 = ( T_1 * ) ( F_88 ( V_237 , V_232 ) + V_234 ) ;
if ( * V_238 & V_149 )
goto V_36;
* V_238 |= V_149 ;
* V_239 |= ( V_233 & V_149 ) ;
return 0 ;
V_36:
return - V_163 ;
}
static int F_89 ( struct V_235 * V_236 ,
struct V_235 * V_237 ,
struct V_12 * V_13 )
{
struct V_235 * V_241 , * V_242 , * V_243 , * V_244 ;
int V_245 , V_246 , V_247 , V_248 , V_249 , V_250 , V_251 ;
void * V_252 , * V_253 , * V_254 ;
struct V_255 * V_133 ;
T_3 V_256 , V_257 ;
T_1 V_258 , V_259 ;
unsigned long V_149 ;
T_5 V_260 ;
T_6 V_261 ;
void * V_56 ;
V_241 = & V_236 [ V_262 ] ;
V_242 = & V_236 [ V_263 ] ;
V_243 = & V_237 [ V_262 ] ;
V_244 = & V_237 [ V_263 ] ;
V_246 = F_90 ( V_264 ) ;
V_56 = V_13 -> V_26 ;
V_248 = V_13 -> V_25 ;
V_247 = 0 ;
for ( V_245 = 0 ; V_245 < F_91 ( V_265 ) ; V_245 ++ ) {
V_133 = & V_265 [ V_245 ] ;
V_258 = 0 ;
V_259 = 0 ;
V_252 = ( void * ) V_241 + V_133 -> V_234 ;
V_253 = ( void * ) V_242 + V_133 -> V_234 ;
memcpy ( & V_258 , V_252 , V_133 -> V_266 ) ;
memcpy ( & V_259 , V_253 , V_133 -> V_266 ) ;
if ( ! V_258 && ! V_259 )
continue;
if ( V_258 && V_259 ) {
F_92 ( V_267 L_10 , V_133 -> V_268 ) ;
return - V_163 ;
}
if ( V_247 == V_248 ) {
F_92 ( V_267 L_11 , V_247 ) ;
return - V_163 ;
}
if ( V_258 ) {
V_256 = V_269 ;
V_149 = V_258 ;
V_254 = ( void * ) V_243 + V_133 -> V_234 ;
memset ( V_252 , 0 , V_133 -> V_266 ) ;
} else {
V_256 = V_270 ;
V_149 = V_259 ;
V_254 = ( void * ) V_244 + V_133 -> V_234 ;
memset ( V_253 , 0 , V_133 -> V_266 ) ;
}
V_257 = V_133 -> V_266 * V_271 ;
if ( V_257 == 32 ) {
V_260 = * ( T_5 * ) & V_149 ;
V_149 = ( V_272 unsigned long ) F_93 ( F_70 ( V_260 ) ) ;
} else if ( V_257 == 16 ) {
V_261 = * ( T_6 * ) & V_149 ;
V_149 = ( V_272 unsigned long ) F_94 ( F_75 ( V_261 ) ) ;
}
V_249 = F_95 ( & V_149 , V_257 ) ;
V_251 = F_96 ( & V_149 , V_257 , V_249 ) ;
V_250 = F_97 ( & V_149 , V_257 ) ;
if ( V_249 < V_251 && V_251 < V_250 ) {
F_92 ( V_267 L_12 ,
V_149 ) ;
return - V_163 ;
}
F_67 ( V_273 , V_56 , V_274 , V_256 ) ;
F_67 ( V_273 , V_56 , V_268 , V_133 -> V_268 ) ;
if ( V_256 == V_269 ) {
F_67 ( V_273 , V_56 , V_234 , V_249 ) ;
F_67 ( V_273 , V_56 , V_275 , ( V_250 - V_249 + 1 ) ) ;
}
if ( V_257 == 32 )
F_67 ( V_273 , V_56 , V_276 , F_79 ( * ( T_5 * ) V_254 ) >> V_249 ) ;
else if ( V_257 == 16 )
F_67 ( V_273 , V_56 , V_276 , F_78 ( * ( T_6 * ) V_254 ) >> V_249 ) ;
else if ( V_257 == 8 )
F_67 ( V_273 , V_56 , V_276 , * ( T_3 * ) V_254 >> V_249 ) ;
V_56 += V_246 ;
V_247 ++ ;
}
V_13 -> V_25 = V_247 ;
return 0 ;
}
static int F_98 ( struct V_8 * V_9 ,
const struct V_277 * V_6 , int V_19 ,
struct V_12 * V_13 )
{
int V_278 , V_246 , V_248 ;
V_278 = F_99 ( V_6 ) ;
V_246 = F_90 ( V_264 ) ;
if ( V_19 == V_29 )
V_248 = F_85 ( V_9 -> V_16 , V_279 ) ;
else
V_248 = F_100 ( V_9 -> V_16 , V_279 ) ;
V_248 = F_101 ( V_248 , V_278 * 16 ) ;
V_13 -> V_26 = F_102 ( V_248 , V_246 , V_32 ) ;
if ( ! V_13 -> V_26 )
return - V_33 ;
V_13 -> V_25 = V_248 ;
return 0 ;
}
static int F_103 ( struct V_8 * V_9 ,
const struct V_277 * V_6 , int V_19 ,
struct V_12 * V_13 )
{
struct V_235 V_236 [ V_280 ] , V_237 [ V_280 ] , * V_281 ;
int V_278 , V_245 , V_20 = - V_163 ;
T_1 V_149 , V_233 , V_234 ;
T_3 V_256 , V_282 ;
V_278 = F_99 ( V_6 ) ;
memset ( V_236 , 0 , sizeof( struct V_235 ) * V_280 ) ;
memset ( V_237 , 0 , sizeof( struct V_235 ) * V_280 ) ;
for ( V_245 = 0 ; V_245 < V_278 ; V_245 ++ ) {
V_282 = F_104 ( V_6 , V_245 ) ;
V_256 = F_105 ( V_6 , V_245 ) ;
V_20 = - V_163 ;
if ( V_282 == V_283 ) {
F_92 ( V_267 L_13 ) ;
goto V_36;
}
if ( V_256 != V_262 && V_256 != V_263 ) {
F_92 ( V_267 L_14 , V_256 ) ;
goto V_36;
}
V_149 = F_106 ( V_6 , V_245 ) ;
V_233 = F_107 ( V_6 , V_245 ) ;
V_234 = F_108 ( V_6 , V_245 ) ;
V_20 = F_87 ( V_282 , ~ V_149 , V_233 , V_234 , & V_236 [ V_256 ] , & V_237 [ V_256 ] ) ;
if ( V_20 )
goto V_36;
}
V_20 = F_98 ( V_9 , V_6 , V_19 , V_13 ) ;
if ( V_20 )
goto V_36;
V_20 = F_89 ( V_236 , V_237 , V_13 ) ;
if ( V_20 < 0 )
goto V_284;
for ( V_256 = 0 ; V_256 < V_280 ; V_256 ++ ) {
V_281 = & V_236 [ V_256 ] ;
if ( memcmp ( V_281 , & V_285 , sizeof( V_285 ) ) ) {
F_92 ( V_267 L_15 ,
V_256 ) ;
F_109 ( V_267 , L_16 , V_286 ,
16 , 1 , V_281 , sizeof( V_285 ) , true ) ;
V_20 = - V_163 ;
goto V_284;
}
}
return 0 ;
V_284:
F_11 ( V_13 -> V_26 ) ;
V_36:
return V_20 ;
}
static bool F_110 ( struct V_8 * V_9 , T_1 V_56 , T_1 V_287 )
{
T_1 V_288 = V_289 | V_290 |
V_291 ;
if ( ! ( V_56 & V_70 ) ) {
F_77 ( V_9 -> V_77 ,
L_17 ) ;
return false ;
}
if ( V_287 & ~ V_288 ) {
F_77 ( V_9 -> V_77 ,
L_18 ,
V_287 ) ;
return false ;
}
return true ;
}
static bool F_111 ( struct V_131 * V_79 ,
struct V_292 * V_293 )
{
const struct V_277 * V_6 ;
bool V_294 ;
F_112 ( V_3 ) ;
T_3 V_282 , V_188 ;
void * V_138 ;
T_4 V_175 ;
int V_278 , V_245 ;
V_138 = F_65 ( V_135 , V_79 -> V_139 , V_137 ) ;
V_175 = F_113 ( V_143 , V_138 , V_175 ) ;
if ( V_175 != V_176 && V_175 != V_182 )
goto V_295;
V_294 = false ;
F_114 ( V_293 , & V_3 ) ;
F_49 (a, &actions, list) {
if ( ! F_115 ( V_6 ) )
continue;
V_278 = F_99 ( V_6 ) ;
for ( V_245 = 0 ; V_245 < V_278 ; V_245 ++ ) {
V_282 = F_104 ( V_6 , V_245 ) ;
if ( V_282 == V_296 ||
V_282 == V_297 ) {
V_294 = true ;
break;
}
}
}
V_188 = F_113 ( V_143 , V_138 , V_144 ) ;
if ( V_294 && V_188 != V_220 && V_188 != V_145 ) {
F_116 ( L_19 , V_188 ) ;
return false ;
}
V_295:
return true ;
}
static bool F_117 ( struct V_8 * V_9 ,
struct V_292 * V_293 ,
struct V_12 * V_13 ,
struct V_10 * V_11 )
{
T_1 V_3 ;
if ( V_11 -> V_27 & V_28 )
V_3 = V_11 -> V_43 -> V_56 ;
else
V_3 = V_11 -> V_44 -> V_56 ;
if ( V_3 & V_70 )
return F_111 ( & V_13 -> V_79 , V_293 ) ;
return true ;
}
static int F_118 ( struct V_8 * V_9 , struct V_292 * V_293 ,
struct V_12 * V_13 ,
struct V_10 * V_11 )
{
struct V_48 * V_49 = V_11 -> V_44 ;
const struct V_277 * V_6 ;
F_112 ( V_3 ) ;
int V_20 ;
if ( ! F_119 ( V_293 ) )
return - V_223 ;
V_49 -> V_57 = V_298 ;
V_49 -> V_56 = 0 ;
F_114 ( V_293 , & V_3 ) ;
F_49 (a, &actions, list) {
if ( F_120 ( V_6 ) ) {
V_49 -> V_56 |= V_299 ;
if ( F_121 ( V_9 -> V_16 ,
V_300 . V_301 ) )
V_49 -> V_56 |= V_68 ;
continue;
}
if ( F_115 ( V_6 ) ) {
V_20 = F_103 ( V_9 , V_6 , V_30 ,
V_13 ) ;
if ( V_20 )
return V_20 ;
V_49 -> V_56 |= V_70 |
V_63 ;
continue;
}
if ( F_122 ( V_6 ) ) {
if ( F_110 ( V_9 , V_49 -> V_56 ,
F_123 ( V_6 ) ) )
continue;
return - V_163 ;
}
if ( F_124 ( V_6 ) ) {
T_1 V_302 = F_125 ( V_6 ) ;
if ( V_302 & ~ V_303 ) {
F_77 ( V_9 -> V_77 , L_20 ,
V_302 ) ;
return - V_223 ;
}
V_49 -> V_57 = V_302 ;
V_49 -> V_56 |= V_63 ;
continue;
}
return - V_223 ;
}
if ( ! F_117 ( V_9 , V_293 , V_13 , V_11 ) )
return - V_163 ;
return 0 ;
}
static inline int F_126 ( struct V_304 * V_6 ,
struct V_304 * V_7 )
{
return memcmp ( V_6 , V_7 , sizeof( * V_6 ) ) ;
}
static inline int F_127 ( struct V_304 * V_2 )
{
return F_2 ( V_2 , sizeof( * V_2 ) , 0 ) ;
}
static int F_128 ( struct V_8 * V_9 ,
struct V_84 * V_305 ,
struct V_84 * * V_85 ,
struct V_306 * V_307 ,
struct V_117 * * V_308 ,
int * V_309 )
{
struct V_14 * V_15 = V_9 -> V_16 -> V_9 . V_17 ;
struct V_310 * V_311 ;
struct V_117 * V_118 = NULL ;
#if F_54 ( V_312 )
int V_313 ;
V_311 = F_129 ( F_35 ( V_305 ) , V_307 ) ;
V_313 = F_130 ( V_311 ) ;
if ( V_313 )
return V_313 ;
#else
return - V_163 ;
#endif
if ( ! F_131 ( V_9 -> V_77 , V_311 -> V_160 . V_51 ) )
* V_85 = F_72 ( V_15 ) ;
else
* V_85 = V_311 -> V_160 . V_51 ;
* V_309 = F_132 ( & V_311 -> V_160 ) ;
V_118 = F_133 ( & V_311 -> V_160 , & V_307 -> V_314 ) ;
F_134 ( V_311 ) ;
if ( ! V_118 )
return - V_33 ;
* V_308 = V_118 ;
return 0 ;
}
static int F_135 ( struct V_8 * V_9 ,
struct V_84 * V_305 ,
struct V_84 * * V_85 ,
struct V_315 * V_316 ,
struct V_117 * * V_308 ,
int * V_309 )
{
struct V_117 * V_118 = NULL ;
struct V_317 * V_160 ;
#if F_54 ( V_312 ) && F_54 ( V_122 )
struct V_14 * V_15 = V_9 -> V_16 -> V_9 . V_17 ;
int V_313 ;
V_313 = V_124 -> V_318 ( F_35 ( V_305 ) , NULL , & V_160 ,
V_316 ) ;
if ( V_313 < 0 )
return V_313 ;
* V_309 = F_136 ( V_160 ) ;
if ( ! F_131 ( V_9 -> V_77 , V_160 -> V_51 ) )
* V_85 = F_72 ( V_15 ) ;
else
* V_85 = V_160 -> V_51 ;
#else
return - V_163 ;
#endif
V_118 = F_133 ( V_160 , & V_316 -> V_314 ) ;
F_137 ( V_160 ) ;
if ( ! V_118 )
return - V_33 ;
* V_308 = V_118 ;
return 0 ;
}
static void F_138 ( struct V_84 * V_85 ,
char V_319 [] , int V_104 ,
unsigned char V_320 [ V_321 ] ,
int V_217 ,
T_5 V_314 ,
T_5 V_322 ,
T_6 V_323 ,
T_5 V_324 )
{
struct V_325 * V_326 = (struct V_325 * ) V_319 ;
struct V_327 * V_328 = (struct V_327 * ) ( ( char * ) V_326 + sizeof( struct V_325 ) ) ;
struct V_329 * V_330 = (struct V_329 * ) ( ( char * ) V_328 + sizeof( struct V_327 ) ) ;
struct V_331 * V_332 = (struct V_331 * ) ( ( char * ) V_330 + sizeof( struct V_329 ) ) ;
memset ( V_319 , 0 , V_104 ) ;
F_81 ( V_326 -> V_320 , V_320 ) ;
F_81 ( V_326 -> V_333 , V_85 -> V_185 ) ;
V_326 -> V_334 = F_139 ( V_176 ) ;
V_328 -> V_314 = V_314 ;
V_328 -> V_322 = V_322 ;
V_328 -> V_217 = V_217 ;
V_328 -> V_335 = V_145 ;
V_328 -> V_336 = 0x4 ;
V_328 -> V_337 = 0x5 ;
V_330 -> V_53 = V_323 ;
V_332 -> V_338 = V_339 ;
V_332 -> V_324 = F_140 ( V_324 ) ;
}
static void F_141 ( struct V_84 * V_85 ,
char V_319 [] , int V_104 ,
unsigned char V_320 [ V_321 ] ,
int V_217 ,
struct V_340 * V_314 ,
struct V_340 * V_322 ,
T_6 V_323 ,
T_5 V_324 )
{
struct V_325 * V_326 = (struct V_325 * ) V_319 ;
struct V_341 * V_342 = (struct V_341 * ) ( ( char * ) V_326 + sizeof( struct V_325 ) ) ;
struct V_329 * V_330 = (struct V_329 * ) ( ( char * ) V_342 + sizeof( struct V_341 ) ) ;
struct V_331 * V_332 = (struct V_331 * ) ( ( char * ) V_330 + sizeof( struct V_329 ) ) ;
memset ( V_319 , 0 , V_104 ) ;
F_81 ( V_326 -> V_320 , V_320 ) ;
F_81 ( V_326 -> V_333 , V_85 -> V_185 ) ;
V_326 -> V_334 = F_139 ( V_182 ) ;
F_142 ( V_342 , 0 , 0 ) ;
V_342 -> V_343 = V_145 ;
V_342 -> V_344 = V_217 ;
V_342 -> V_314 = * V_314 ;
V_342 -> V_322 = * V_322 ;
V_330 -> V_53 = V_323 ;
V_332 -> V_338 = V_339 ;
V_332 -> V_324 = F_140 ( V_324 ) ;
}
static int F_143 ( struct V_8 * V_9 ,
struct V_84 * V_305 ,
struct V_101 * V_102 )
{
int V_345 = F_76 ( V_9 -> V_16 , V_346 ) ;
int V_347 = V_348 + sizeof( struct V_327 ) + V_349 ;
struct V_304 * V_350 = & V_102 -> V_92 . V_2 ;
struct V_84 * V_85 ;
struct V_117 * V_118 = NULL ;
struct V_306 V_307 = {} ;
char * V_105 ;
int V_217 , V_20 ;
T_3 V_351 ;
if ( V_345 < V_347 ) {
F_47 ( V_9 -> V_16 , L_21 ,
V_347 , V_345 ) ;
return - V_163 ;
}
V_105 = F_6 ( V_347 , V_32 ) ;
if ( ! V_105 )
return - V_33 ;
switch ( V_102 -> V_103 ) {
case V_352 :
V_307 . V_353 = V_145 ;
V_307 . V_354 = V_350 -> V_355 ;
break;
default:
V_20 = - V_163 ;
goto V_356;
}
V_307 . V_357 = V_350 -> V_214 ;
V_307 . V_314 = V_350 -> V_358 . V_173 . V_160 ;
V_307 . V_322 = V_350 -> V_358 . V_173 . V_166 ;
V_20 = F_128 ( V_9 , V_305 , & V_85 ,
& V_307 , & V_118 , & V_217 ) ;
if ( V_20 )
goto V_356;
V_102 -> V_110 . V_51 = V_118 -> V_51 ;
V_102 -> V_110 . V_119 = V_118 -> V_359 -> V_119 ;
memcpy ( & V_102 -> V_110 . V_128 , V_118 -> V_360 , V_118 -> V_115 -> V_361 ) ;
V_102 -> V_85 = V_85 ;
V_20 = F_144 ( F_37 ( V_85 ) , V_102 ) ;
if ( V_20 )
goto V_356;
F_145 ( & V_118 -> V_362 ) ;
V_351 = V_118 -> V_351 ;
F_81 ( V_102 -> V_320 , V_118 -> V_363 ) ;
F_146 ( & V_118 -> V_362 ) ;
switch ( V_102 -> V_103 ) {
case V_352 :
F_138 ( V_85 , V_105 ,
V_347 , V_102 -> V_320 , V_217 ,
V_307 . V_314 ,
V_307 . V_322 , V_350 -> V_355 ,
F_147 ( V_350 -> V_364 ) ) ;
break;
default:
V_20 = - V_163 ;
goto V_365;
}
V_102 -> V_104 = V_347 ;
V_102 -> V_105 = V_105 ;
if ( ! ( V_351 & V_366 ) ) {
F_59 ( V_118 , NULL ) ;
V_20 = - V_93 ;
goto V_367;
}
V_20 = F_46 ( V_9 -> V_16 , V_102 -> V_103 ,
V_347 , V_105 , & V_102 -> V_58 ) ;
if ( V_20 )
goto V_365;
V_102 -> V_27 |= V_106 ;
F_48 ( F_37 ( V_85 ) ) ;
F_60 ( V_118 ) ;
return V_20 ;
V_365:
F_61 ( F_37 ( V_102 -> V_85 ) , V_102 ) ;
V_356:
F_11 ( V_105 ) ;
V_367:
if ( V_118 )
F_60 ( V_118 ) ;
return V_20 ;
}
static int F_148 ( struct V_8 * V_9 ,
struct V_84 * V_305 ,
struct V_101 * V_102 )
{
int V_345 = F_76 ( V_9 -> V_16 , V_346 ) ;
int V_368 = V_348 + sizeof( struct V_341 ) + V_349 ;
struct V_304 * V_350 = & V_102 -> V_92 . V_2 ;
struct V_84 * V_85 ;
struct V_117 * V_118 = NULL ;
struct V_315 V_316 = {} ;
char * V_105 ;
int V_20 , V_217 = 0 ;
T_3 V_351 ;
if ( V_345 < V_368 ) {
F_47 ( V_9 -> V_16 , L_21 ,
V_368 , V_345 ) ;
return - V_163 ;
}
V_105 = F_6 ( V_368 , V_32 ) ;
if ( ! V_105 )
return - V_33 ;
switch ( V_102 -> V_103 ) {
case V_352 :
V_316 . V_369 = V_145 ;
V_316 . V_370 = V_350 -> V_355 ;
break;
default:
V_20 = - V_163 ;
goto V_356;
}
V_316 . V_371 = F_149 ( F_150 ( V_350 -> V_214 ) , V_350 -> V_372 ) ;
V_316 . V_314 = V_350 -> V_358 . V_181 . V_160 ;
V_316 . V_322 = V_350 -> V_358 . V_181 . V_166 ;
V_20 = F_135 ( V_9 , V_305 , & V_85 ,
& V_316 , & V_118 , & V_217 ) ;
if ( V_20 )
goto V_356;
V_102 -> V_110 . V_51 = V_118 -> V_51 ;
V_102 -> V_110 . V_119 = V_118 -> V_359 -> V_119 ;
memcpy ( & V_102 -> V_110 . V_128 , V_118 -> V_360 , V_118 -> V_115 -> V_361 ) ;
V_102 -> V_85 = V_85 ;
V_20 = F_144 ( F_37 ( V_85 ) , V_102 ) ;
if ( V_20 )
goto V_356;
F_145 ( & V_118 -> V_362 ) ;
V_351 = V_118 -> V_351 ;
F_81 ( V_102 -> V_320 , V_118 -> V_363 ) ;
F_146 ( & V_118 -> V_362 ) ;
switch ( V_102 -> V_103 ) {
case V_352 :
F_141 ( V_85 , V_105 ,
V_368 , V_102 -> V_320 , V_217 ,
& V_316 . V_314 ,
& V_316 . V_322 , V_350 -> V_355 ,
F_147 ( V_350 -> V_364 ) ) ;
break;
default:
V_20 = - V_163 ;
goto V_365;
}
V_102 -> V_104 = V_368 ;
V_102 -> V_105 = V_105 ;
if ( ! ( V_351 & V_366 ) ) {
F_59 ( V_118 , NULL ) ;
V_20 = - V_93 ;
goto V_367;
}
V_20 = F_46 ( V_9 -> V_16 , V_102 -> V_103 ,
V_368 , V_105 , & V_102 -> V_58 ) ;
if ( V_20 )
goto V_365;
V_102 -> V_27 |= V_106 ;
F_48 ( F_37 ( V_85 ) ) ;
F_60 ( V_118 ) ;
return V_20 ;
V_365:
F_61 ( F_37 ( V_102 -> V_85 ) , V_102 ) ;
V_356:
F_11 ( V_105 ) ;
V_367:
if ( V_118 )
F_60 ( V_118 ) ;
return V_20 ;
}
static int F_36 ( struct V_8 * V_9 ,
struct V_373 * V_92 ,
struct V_84 * V_305 ,
struct V_84 * * V_86 ,
struct V_10 * V_11 )
{
struct V_14 * V_15 = V_9 -> V_16 -> V_9 . V_17 ;
struct V_84 * V_158 = F_72 ( V_15 ) ;
unsigned short V_119 = F_151 ( V_92 ) ;
struct V_8 * V_159 = F_37 ( V_158 ) ;
struct V_83 * V_49 = V_11 -> V_43 ;
struct V_304 * V_2 = & V_92 -> V_2 ;
struct V_101 * V_102 ;
int V_103 , V_20 = 0 ;
T_7 V_24 ;
bool V_23 = false ;
if ( ! F_73 ( & V_2 -> V_355 , 0 , sizeof( V_2 -> V_355 ) ) )
goto V_374;
if ( F_73 ( & V_2 -> V_375 , 0 , sizeof( V_2 -> V_375 ) ) ) {
V_374:
F_77 ( V_9 -> V_77 ,
L_22 ) ;
return - V_163 ;
}
if ( F_74 ( V_159 , F_75 ( V_2 -> V_355 ) ) &&
F_76 ( V_9 -> V_16 , V_162 ) ) {
V_103 = V_352 ;
} else {
F_77 ( V_9 -> V_77 ,
L_5 , F_75 ( V_2 -> V_355 ) ) ;
return - V_163 ;
}
V_24 = F_127 ( V_2 ) ;
F_152 (esw->offloads.encap_tbl, e,
encap_hlist, hash_key) {
if ( ! F_126 ( & V_102 -> V_92 . V_2 , V_2 ) ) {
V_23 = true ;
break;
}
}
if ( V_23 )
goto V_31;
V_102 = F_6 ( sizeof( * V_102 ) , V_32 ) ;
if ( ! V_102 )
return - V_33 ;
V_102 -> V_92 = * V_92 ;
V_102 -> V_103 = V_103 ;
F_7 ( & V_102 -> V_34 ) ;
if ( V_119 == V_120 )
V_20 = F_143 ( V_9 , V_305 , V_102 ) ;
else if ( V_119 == V_123 )
V_20 = F_148 ( V_9 , V_305 , V_102 ) ;
if ( V_20 && V_20 != - V_93 )
goto V_36;
F_153 ( V_15 -> V_37 . V_376 , & V_102 -> V_130 , V_24 ) ;
V_31:
F_10 ( & V_11 -> V_129 , & V_102 -> V_34 ) ;
* V_86 = V_102 -> V_85 ;
if ( V_102 -> V_27 & V_106 )
V_49 -> V_58 = V_102 -> V_58 ;
else
V_20 = - V_93 ;
return V_20 ;
V_36:
F_11 ( V_102 ) ;
return V_20 ;
}
static int F_154 ( struct V_8 * V_9 , struct V_292 * V_293 ,
struct V_12 * V_13 ,
struct V_10 * V_11 )
{
struct V_83 * V_49 = V_11 -> V_43 ;
struct V_87 * V_88 = V_9 -> V_95 ;
struct V_373 * V_377 = NULL ;
const struct V_277 * V_6 ;
F_112 ( V_3 ) ;
bool V_129 = false ;
int V_20 = 0 ;
if ( ! F_119 ( V_293 ) )
return - V_223 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_378 = V_88 -> V_97 ;
F_114 ( V_293 , & V_3 ) ;
F_49 (a, &actions, list) {
if ( F_120 ( V_6 ) ) {
V_49 -> V_56 |= V_299 |
V_68 ;
continue;
}
if ( F_115 ( V_6 ) ) {
V_20 = F_103 ( V_9 , V_6 , V_29 ,
V_13 ) ;
if ( V_20 )
return V_20 ;
V_49 -> V_56 |= V_70 ;
continue;
}
if ( F_122 ( V_6 ) ) {
if ( F_110 ( V_9 , V_49 -> V_56 ,
F_123 ( V_6 ) ) )
continue;
return - V_163 ;
}
if ( F_155 ( V_6 ) ) {
int V_379 = F_156 ( V_6 ) ;
struct V_84 * V_85 ;
struct V_8 * V_89 ;
V_85 = F_34 ( F_35 ( V_9 -> V_77 ) , V_379 ) ;
if ( F_131 ( V_9 -> V_77 ,
V_85 ) ) {
V_49 -> V_56 |= V_63 |
V_68 ;
V_89 = F_37 ( V_85 ) ;
V_88 = V_89 -> V_95 ;
V_49 -> V_96 = V_88 -> V_97 ;
} else if ( V_129 ) {
V_13 -> V_91 = V_379 ;
V_13 -> V_92 = * V_377 ;
V_49 -> V_13 = V_13 ;
V_49 -> V_56 |= V_90 |
V_63 |
V_68 ;
} else {
F_157 ( L_23 ,
V_9 -> V_77 -> V_380 , V_85 -> V_380 ) ;
return - V_223 ;
}
continue;
}
if ( F_158 ( V_6 ) ) {
V_377 = F_159 ( V_6 ) ;
if ( V_377 )
V_129 = true ;
else
return - V_163 ;
continue;
}
if ( F_160 ( V_6 ) ) {
if ( F_161 ( V_6 ) == V_381 ) {
V_49 -> V_56 |= V_382 ;
} else if ( F_161 ( V_6 ) == V_383 ) {
if ( F_162 ( V_6 ) != F_139 ( V_384 ) )
return - V_163 ;
V_49 -> V_56 |= V_385 ;
V_49 -> V_66 = F_163 ( V_6 ) ;
} else {
return - V_163 ;
}
continue;
}
if ( F_164 ( V_6 ) ) {
V_49 -> V_56 |= V_386 ;
continue;
}
return - V_223 ;
}
if ( ! F_117 ( V_9 , V_293 , V_13 , V_11 ) )
return - V_163 ;
return V_20 ;
}
int F_165 ( struct V_8 * V_9 ,
struct V_132 * V_133 )
{
struct V_14 * V_15 = V_9 -> V_16 -> V_9 . V_17 ;
struct V_12 * V_13 ;
struct V_387 * V_41 = & V_9 -> V_40 . V_41 ;
struct V_10 * V_11 ;
int V_388 , V_20 = 0 ;
T_3 V_389 = 0 ;
if ( V_15 && V_15 -> V_390 == V_391 ) {
V_389 = V_28 ;
V_388 = sizeof( struct V_83 ) ;
} else {
V_389 = V_392 ;
V_388 = sizeof( struct V_48 ) ;
}
V_11 = F_6 ( sizeof( * V_11 ) + V_388 , V_32 ) ;
V_13 = F_166 ( sizeof( * V_13 ) , V_32 ) ;
if ( ! V_13 || ! V_11 ) {
V_20 = - V_33 ;
goto V_393;
}
V_11 -> V_394 = V_133 -> V_394 ;
V_11 -> V_27 = V_389 ;
V_20 = F_86 ( V_9 , V_11 , & V_13 -> V_79 , V_133 ) ;
if ( V_20 < 0 )
goto V_393;
if ( V_11 -> V_27 & V_28 ) {
V_20 = F_154 ( V_9 , V_133 -> V_293 , V_13 , V_11 ) ;
if ( V_20 < 0 )
goto V_393;
V_11 -> V_61 = F_33 ( V_9 , V_13 , V_11 ) ;
} else {
V_20 = F_118 ( V_9 , V_133 -> V_293 , V_13 , V_11 ) ;
if ( V_20 < 0 )
goto V_393;
V_11 -> V_61 = F_18 ( V_9 , V_13 , V_11 ) ;
}
if ( F_20 ( V_11 -> V_61 ) ) {
V_20 = F_50 ( V_11 -> V_61 ) ;
if ( V_20 != - V_93 )
goto V_393;
}
if ( V_20 != - V_93 )
V_11 -> V_27 |= V_100 ;
V_20 = F_167 ( & V_41 -> V_395 , & V_11 -> V_396 ,
V_41 -> V_397 ) ;
if ( V_20 )
goto V_398;
if ( V_11 -> V_27 & V_28 &&
! ( V_11 -> V_43 -> V_56 & V_90 ) )
F_44 ( V_13 ) ;
return V_20 ;
V_398:
F_63 ( V_9 , V_11 ) ;
V_393:
F_44 ( V_13 ) ;
F_11 ( V_11 ) ;
return V_20 ;
}
int F_168 ( struct V_8 * V_9 ,
struct V_132 * V_133 )
{
struct V_10 * V_11 ;
struct V_387 * V_41 = & V_9 -> V_40 . V_41 ;
V_11 = F_169 ( & V_41 -> V_395 , & V_133 -> V_394 ,
V_41 -> V_397 ) ;
if ( ! V_11 )
return - V_223 ;
F_170 ( & V_41 -> V_395 , & V_11 -> V_396 , V_41 -> V_397 ) ;
F_63 ( V_9 , V_11 ) ;
F_11 ( V_11 ) ;
return 0 ;
}
int F_171 ( struct V_8 * V_9 ,
struct V_132 * V_133 )
{
struct V_387 * V_41 = & V_9 -> V_40 . V_41 ;
struct V_10 * V_11 ;
struct V_59 * V_60 ;
T_2 V_111 ;
T_2 V_112 ;
T_2 V_113 ;
V_11 = F_169 ( & V_41 -> V_395 , & V_133 -> V_394 ,
V_41 -> V_397 ) ;
if ( ! V_11 )
return - V_223 ;
if ( ! ( V_11 -> V_27 & V_100 ) )
return 0 ;
V_60 = F_30 ( V_11 -> V_61 ) ;
if ( ! V_60 )
return 0 ;
F_55 ( V_60 , & V_111 , & V_112 , & V_113 ) ;
F_172 ( V_133 -> V_293 , V_111 , V_112 , V_113 ) ;
return 0 ;
}
int F_173 ( struct V_8 * V_9 )
{
struct V_387 * V_41 = & V_9 -> V_40 . V_41 ;
F_174 ( V_41 -> V_38 ) ;
V_41 -> V_397 = V_399 ;
return F_175 ( & V_41 -> V_395 , & V_41 -> V_397 ) ;
}
static void F_176 ( void * V_400 , void * V_401 )
{
struct V_10 * V_11 = V_400 ;
struct V_8 * V_9 = V_401 ;
F_63 ( V_9 , V_11 ) ;
F_11 ( V_11 ) ;
}
void F_177 ( struct V_8 * V_9 )
{
struct V_387 * V_41 = & V_9 -> V_40 . V_41 ;
F_178 ( & V_41 -> V_395 , F_176 , V_9 ) ;
if ( ! F_23 ( V_41 -> V_67 ) ) {
F_27 ( V_41 -> V_67 ) ;
V_41 -> V_67 = NULL ;
}
}
