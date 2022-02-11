static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 (c, &conn->chan_l, list) {
if ( V_5 -> V_6 == V_4 )
return V_5 ;
}
return NULL ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 (c, &conn->chan_l, list) {
if ( V_5 -> V_7 == V_4 )
return V_5 ;
}
return NULL ;
}
static struct V_1 * F_4 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
F_5 ( & V_3 -> V_8 ) ;
V_5 = F_3 ( V_3 , V_4 ) ;
if ( V_5 )
F_6 ( V_5 ) ;
F_7 ( & V_3 -> V_8 ) ;
return V_5 ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 , T_2 V_9 )
{
struct V_1 * V_5 ;
F_2 (c, &conn->chan_l, list) {
if ( V_5 -> V_9 == V_9 )
return V_5 ;
}
return NULL ;
}
static struct V_1 * F_9 ( T_3 V_10 , T_4 * V_11 )
{
struct V_1 * V_5 ;
F_2 (c, &chan_list, global_l) {
if ( V_5 -> V_12 == V_10 && ! F_10 ( & F_11 ( V_5 -> V_13 ) -> V_11 , V_11 ) )
return V_5 ;
}
return NULL ;
}
int F_12 ( struct V_1 * V_14 , T_4 * V_11 , T_3 V_10 )
{
int V_15 ;
F_13 ( & V_16 ) ;
if ( V_10 && F_9 ( V_10 , V_11 ) ) {
V_15 = - V_17 ;
goto V_18;
}
if ( V_10 ) {
V_14 -> V_10 = V_10 ;
V_14 -> V_12 = V_10 ;
V_15 = 0 ;
} else {
T_1 V_19 ;
V_15 = - V_20 ;
for ( V_19 = 0x1001 ; V_19 < 0x1100 ; V_19 += 2 )
if ( ! F_9 ( F_14 ( V_19 ) , V_11 ) ) {
V_14 -> V_10 = F_14 ( V_19 ) ;
V_14 -> V_12 = F_14 ( V_19 ) ;
V_15 = 0 ;
break;
}
}
V_18:
F_15 ( & V_16 ) ;
return V_15 ;
}
int F_16 ( struct V_1 * V_14 , T_5 V_7 )
{
F_13 ( & V_16 ) ;
V_14 -> V_7 = V_7 ;
F_15 ( & V_16 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_2 * V_3 )
{
T_1 V_4 = V_21 ;
for (; V_4 < V_22 ; V_4 ++ ) {
if ( ! F_3 ( V_3 , V_4 ) )
return V_4 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_14 , int V_23 )
{
F_19 ( L_1 , V_14 , F_20 ( V_14 -> V_23 ) ,
F_20 ( V_23 ) ) ;
V_14 -> V_23 = V_23 ;
V_14 -> V_24 -> V_25 ( V_14 , V_23 ) ;
}
static void F_21 ( struct V_1 * V_14 , int V_23 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
F_22 ( V_13 ) ;
F_18 ( V_14 , V_23 ) ;
F_23 ( V_13 ) ;
}
static inline void F_24 ( struct V_1 * V_14 , int V_15 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
V_13 -> V_27 = V_15 ;
}
static inline void F_25 ( struct V_1 * V_14 , int V_15 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
F_22 ( V_13 ) ;
F_24 ( V_14 , V_15 ) ;
F_23 ( V_13 ) ;
}
static void F_26 ( struct V_1 * V_14 )
{
if ( ! F_27 ( & V_14 -> V_28 ) &&
V_14 -> V_29 ) {
F_28 ( V_14 , & V_14 -> V_30 ,
F_29 ( V_14 -> V_29 ) ) ;
}
}
static void F_30 ( struct V_1 * V_14 )
{
F_31 ( V_14 ) ;
if ( V_14 -> V_31 ) {
F_28 ( V_14 , & V_14 -> V_28 ,
F_29 ( V_14 -> V_31 ) ) ;
}
}
static struct V_32 * F_32 ( struct V_33 * V_34 ,
T_1 V_35 )
{
struct V_32 * V_36 ;
F_33 (head, skb) {
if ( F_34 ( V_36 ) -> V_37 . V_38 == V_35 )
return V_36 ;
}
return NULL ;
}
static int F_35 ( struct V_39 * V_40 , T_1 V_41 )
{
T_6 V_42 , V_43 ;
V_42 = F_36 ( V_41 ) ;
V_40 -> V_44 = F_37 ( sizeof( T_1 ) * V_42 , V_45 ) ;
if ( ! V_40 -> V_44 )
return - V_46 ;
V_40 -> V_47 = V_42 - 1 ;
V_40 -> V_34 = V_48 ;
V_40 -> V_49 = V_48 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
V_40 -> V_44 [ V_43 ] = V_48 ;
return 0 ;
}
static inline void F_38 ( struct V_39 * V_40 )
{
F_39 ( V_40 -> V_44 ) ;
}
static inline bool F_40 ( struct V_39 * V_40 ,
T_1 V_35 )
{
return V_40 -> V_44 [ V_35 & V_40 -> V_47 ] != V_48 ;
}
static T_1 F_41 ( struct V_39 * V_40 , T_1 V_35 )
{
T_1 V_47 = V_40 -> V_47 ;
if ( V_40 -> V_34 == V_48 ) {
return V_48 ;
} else if ( V_40 -> V_34 == V_35 ) {
V_40 -> V_34 = V_40 -> V_44 [ V_35 & V_47 ] ;
V_40 -> V_44 [ V_35 & V_47 ] = V_48 ;
if ( V_40 -> V_34 == V_50 ) {
V_40 -> V_34 = V_48 ;
V_40 -> V_49 = V_48 ;
}
} else {
T_1 V_51 = V_40 -> V_34 ;
while ( V_40 -> V_44 [ V_51 & V_47 ] != V_35 ) {
V_51 = V_40 -> V_44 [ V_51 & V_47 ] ;
if ( V_51 == V_50 )
return V_48 ;
}
V_40 -> V_44 [ V_51 & V_47 ] = V_40 -> V_44 [ V_35 & V_47 ] ;
V_40 -> V_44 [ V_35 & V_47 ] = V_48 ;
if ( V_40 -> V_49 == V_35 )
V_40 -> V_49 = V_51 ;
}
return V_35 ;
}
static inline T_1 F_42 ( struct V_39 * V_40 )
{
return F_41 ( V_40 , V_40 -> V_34 ) ;
}
static void F_43 ( struct V_39 * V_40 )
{
T_1 V_43 ;
if ( V_40 -> V_34 == V_48 )
return;
for ( V_43 = 0 ; V_43 <= V_40 -> V_47 ; V_43 ++ )
V_40 -> V_44 [ V_43 ] = V_48 ;
V_40 -> V_34 = V_48 ;
V_40 -> V_49 = V_48 ;
}
static void F_44 ( struct V_39 * V_40 , T_1 V_35 )
{
T_1 V_47 = V_40 -> V_47 ;
if ( V_40 -> V_44 [ V_35 & V_47 ] != V_48 )
return;
if ( V_40 -> V_49 == V_48 )
V_40 -> V_34 = V_35 ;
else
V_40 -> V_44 [ V_40 -> V_49 & V_47 ] = V_35 ;
V_40 -> V_49 = V_35 ;
V_40 -> V_44 [ V_35 & V_47 ] = V_50 ;
}
static void F_45 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_46 ( V_53 , struct V_1 ,
V_54 . V_53 ) ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_55 ;
F_19 ( L_2 , V_14 , F_20 ( V_14 -> V_23 ) ) ;
F_5 ( & V_3 -> V_8 ) ;
F_6 ( V_14 ) ;
if ( V_14 -> V_23 == V_56 || V_14 -> V_23 == V_57 )
V_55 = V_58 ;
else if ( V_14 -> V_23 == V_59 &&
V_14 -> V_60 != V_61 )
V_55 = V_58 ;
else
V_55 = V_62 ;
F_47 ( V_14 , V_55 ) ;
F_48 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
F_49 ( V_14 ) ;
}
struct V_1 * F_50 ( void )
{
struct V_1 * V_14 ;
V_14 = F_51 ( sizeof( * V_14 ) , V_64 ) ;
if ( ! V_14 )
return NULL ;
F_52 ( & V_14 -> V_65 ) ;
F_13 ( & V_16 ) ;
F_53 ( & V_14 -> V_66 , & V_67 ) ;
F_15 ( & V_16 ) ;
F_54 ( & V_14 -> V_54 , F_45 ) ;
V_14 -> V_23 = V_68 ;
F_55 ( & V_14 -> V_69 ) ;
F_56 ( V_70 , & V_14 -> V_71 ) ;
F_19 ( L_3 , V_14 ) ;
return V_14 ;
}
static void F_57 ( struct V_69 * V_69 )
{
struct V_1 * V_14 = F_46 ( V_69 , struct V_1 , V_69 ) ;
F_19 ( L_3 , V_14 ) ;
F_13 ( & V_16 ) ;
F_58 ( & V_14 -> V_66 ) ;
F_15 ( & V_16 ) ;
F_39 ( V_14 ) ;
}
void F_59 ( struct V_1 * V_5 )
{
F_19 ( L_4 , V_5 , F_60 ( & V_5 -> V_69 . V_72 ) ) ;
F_61 ( & V_5 -> V_69 ) ;
}
void F_49 ( struct V_1 * V_5 )
{
F_19 ( L_4 , V_5 , F_60 ( & V_5 -> V_69 . V_72 ) ) ;
F_62 ( & V_5 -> V_69 , F_57 ) ;
}
void F_63 ( struct V_1 * V_14 )
{
V_14 -> V_73 = V_74 ;
V_14 -> V_75 = V_76 ;
V_14 -> V_77 = V_78 ;
V_14 -> V_79 = V_78 ;
V_14 -> V_80 = V_78 ;
V_14 -> V_60 = V_81 ;
F_56 ( V_82 , & V_14 -> V_83 ) ;
}
static void F_64 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_19 ( L_5 , V_3 ,
F_65 ( V_14 -> V_10 ) , V_14 -> V_6 ) ;
V_3 -> V_84 = V_85 ;
V_14 -> V_3 = V_3 ;
switch ( V_14 -> V_86 ) {
case V_87 :
if ( V_3 -> V_88 -> type == V_89 ) {
V_14 -> V_90 = V_91 ;
V_14 -> V_7 = V_92 ;
V_14 -> V_6 = V_92 ;
} else {
V_14 -> V_7 = F_17 ( V_3 ) ;
V_14 -> V_90 = V_91 ;
}
break;
case V_93 :
V_14 -> V_7 = V_94 ;
V_14 -> V_6 = V_94 ;
V_14 -> V_90 = V_91 ;
break;
case V_95 :
V_14 -> V_7 = V_96 ;
V_14 -> V_6 = V_96 ;
V_14 -> V_90 = V_97 ;
V_14 -> V_98 = V_97 ;
break;
default:
V_14 -> V_7 = V_99 ;
V_14 -> V_6 = V_99 ;
V_14 -> V_90 = V_91 ;
}
V_14 -> V_100 = V_101 ;
V_14 -> V_102 = V_103 ;
V_14 -> V_104 = V_105 ;
V_14 -> V_106 = V_107 ;
V_14 -> V_108 = V_109 ;
V_14 -> V_110 = V_111 ;
F_59 ( V_14 ) ;
F_53 ( & V_14 -> V_44 , & V_3 -> V_112 ) ;
}
void F_66 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_5 ( & V_3 -> V_8 ) ;
F_64 ( V_3 , V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
}
void F_67 ( struct V_1 * V_14 , int V_15 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
F_68 ( V_14 ) ;
F_19 ( L_6 , V_14 , V_3 , V_15 ) ;
if ( V_3 ) {
F_58 ( & V_14 -> V_44 ) ;
F_49 ( V_14 ) ;
V_14 -> V_3 = NULL ;
if ( V_14 -> V_86 != V_95 )
F_69 ( V_3 -> V_88 ) ;
}
if ( V_14 -> V_24 -> V_113 )
V_14 -> V_24 -> V_113 ( V_14 , V_15 ) ;
if ( F_70 ( V_70 , & V_14 -> V_71 ) )
return;
switch( V_14 -> V_114 ) {
case V_115 :
break;
case V_116 :
F_31 ( V_14 ) ;
F_71 ( V_14 ) ;
F_72 ( V_14 ) ;
F_73 ( & V_14 -> V_117 ) ;
F_38 ( & V_14 -> V_118 ) ;
F_38 ( & V_14 -> V_119 ) ;
case V_120 :
F_73 ( & V_14 -> V_121 ) ;
break;
}
return;
}
void F_47 ( struct V_1 * V_14 , int V_55 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_26 * V_13 = V_14 -> V_13 ;
F_19 ( L_7 , V_14 ,
F_20 ( V_14 -> V_23 ) , V_13 ) ;
switch ( V_14 -> V_23 ) {
case V_122 :
if ( V_14 -> V_24 -> V_113 )
V_14 -> V_24 -> V_113 ( V_14 , 0 ) ;
break;
case V_56 :
case V_57 :
if ( V_14 -> V_86 == V_87 &&
V_3 -> V_88 -> type == V_123 ) {
F_74 ( V_14 , V_13 -> V_124 ) ;
F_75 ( V_3 , V_14 , V_55 ) ;
} else
F_67 ( V_14 , V_55 ) ;
break;
case V_125 :
if ( V_14 -> V_86 == V_87 &&
V_3 -> V_88 -> type == V_123 ) {
struct V_126 V_127 ;
T_5 V_128 ;
if ( F_70 ( V_129 , & F_11 ( V_13 ) -> V_83 ) )
V_128 = V_130 ;
else
V_128 = V_131 ;
F_21 ( V_14 , V_132 ) ;
V_127 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_127 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_127 . V_128 = F_14 ( V_128 ) ;
V_127 . V_133 = F_76 ( V_134 ) ;
F_77 ( V_3 , V_14 -> V_9 , V_135 ,
sizeof( V_127 ) , & V_127 ) ;
}
F_67 ( V_14 , V_55 ) ;
break;
case V_59 :
case V_132 :
F_67 ( V_14 , V_55 ) ;
break;
default:
if ( V_14 -> V_24 -> V_113 )
V_14 -> V_24 -> V_113 ( V_14 , 0 ) ;
break;
}
}
static inline T_2 F_78 ( struct V_1 * V_14 )
{
if ( V_14 -> V_86 == V_136 ) {
switch ( V_14 -> V_60 ) {
case V_137 :
return V_138 ;
case V_139 :
return V_140 ;
default:
return V_141 ;
}
} else if ( V_14 -> V_10 == F_76 ( V_142 ) ) {
if ( V_14 -> V_60 == V_81 )
V_14 -> V_60 = V_61 ;
if ( V_14 -> V_60 == V_137 )
return V_143 ;
else
return V_141 ;
} else {
switch ( V_14 -> V_60 ) {
case V_137 :
return V_144 ;
case V_139 :
return V_145 ;
default:
return V_141 ;
}
}
}
int F_79 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
T_7 V_146 ;
V_146 = F_78 ( V_14 ) ;
return F_80 ( V_3 -> V_88 , V_14 -> V_60 , V_146 ) ;
}
static T_2 F_81 ( struct V_2 * V_3 )
{
T_2 V_147 ;
F_82 ( & V_3 -> V_65 ) ;
if ( ++ V_3 -> V_148 > 128 )
V_3 -> V_148 = 1 ;
V_147 = V_3 -> V_148 ;
F_83 ( & V_3 -> V_65 ) ;
return V_147 ;
}
static void F_77 ( struct V_2 * V_3 , T_2 V_9 , T_2 V_149 , T_1 V_150 , void * V_151 )
{
struct V_32 * V_36 = F_84 ( V_3 , V_149 , V_9 , V_150 , V_151 ) ;
T_2 V_83 ;
F_19 ( L_8 , V_149 ) ;
if ( ! V_36 )
return;
if ( F_85 ( V_3 -> V_88 -> V_152 ) )
V_83 = V_153 ;
else
V_83 = V_154 ;
F_34 ( V_36 ) -> V_155 = V_156 ;
V_36 -> V_157 = V_158 ;
F_86 ( V_3 -> V_159 , V_36 , V_83 ) ;
}
static void F_87 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
struct V_160 * V_88 = V_14 -> V_3 -> V_88 ;
T_1 V_83 ;
F_19 ( L_9 , V_14 , V_36 , V_36 -> V_150 ,
V_36 -> V_157 ) ;
if ( ! F_70 ( V_161 , & V_14 -> V_83 ) &&
F_85 ( V_88 -> V_152 ) )
V_83 = V_153 ;
else
V_83 = V_154 ;
F_34 ( V_36 ) -> V_155 = F_70 ( V_82 , & V_14 -> V_83 ) ;
F_86 ( V_14 -> V_3 -> V_159 , V_36 , V_83 ) ;
}
static void F_88 ( T_1 V_162 , struct V_163 * V_37 )
{
V_37 -> V_164 = ( V_162 & V_165 ) >> V_166 ;
V_37 -> V_167 = ( V_162 & V_168 ) >> V_169 ;
if ( V_162 & V_170 ) {
V_37 -> V_171 = 1 ;
V_37 -> V_172 = ( V_162 & V_173 ) >> V_174 ;
V_37 -> V_175 = ( V_162 & V_176 ) >> V_177 ;
V_37 -> V_178 = 0 ;
V_37 -> V_38 = 0 ;
} else {
V_37 -> V_171 = 0 ;
V_37 -> V_178 = ( V_162 & V_179 ) >> V_180 ;
V_37 -> V_38 = ( V_162 & V_181 ) >> V_182 ;
V_37 -> V_172 = 0 ;
V_37 -> V_175 = 0 ;
}
}
static void F_89 ( T_8 V_183 , struct V_163 * V_37 )
{
V_37 -> V_164 = ( V_183 & V_184 ) >> V_185 ;
V_37 -> V_167 = ( V_183 & V_186 ) >> V_187 ;
if ( V_183 & V_188 ) {
V_37 -> V_171 = 1 ;
V_37 -> V_172 = ( V_183 & V_189 ) >> V_190 ;
V_37 -> V_175 = ( V_183 & V_191 ) >> V_192 ;
V_37 -> V_178 = 0 ;
V_37 -> V_38 = 0 ;
} else {
V_37 -> V_171 = 0 ;
V_37 -> V_178 = ( V_183 & V_193 ) >> V_194 ;
V_37 -> V_38 = ( V_183 & V_195 ) >> V_196 ;
V_37 -> V_172 = 0 ;
V_37 -> V_175 = 0 ;
}
}
static inline void F_90 ( struct V_1 * V_14 ,
struct V_32 * V_36 )
{
if ( F_70 ( V_197 , & V_14 -> V_83 ) ) {
F_89 ( F_91 ( V_36 -> V_151 ) ,
& F_34 ( V_36 ) -> V_37 ) ;
F_92 ( V_36 , V_198 ) ;
} else {
F_88 ( F_93 ( V_36 -> V_151 ) ,
& F_34 ( V_36 ) -> V_37 ) ;
F_92 ( V_36 , V_199 ) ;
}
}
static T_8 F_94 ( struct V_163 * V_37 )
{
T_8 V_200 ;
V_200 = V_37 -> V_164 << V_185 ;
V_200 |= V_37 -> V_167 << V_187 ;
if ( V_37 -> V_171 ) {
V_200 |= V_37 -> V_172 << V_190 ;
V_200 |= V_37 -> V_175 << V_192 ;
V_200 |= V_188 ;
} else {
V_200 |= V_37 -> V_178 << V_194 ;
V_200 |= V_37 -> V_38 << V_196 ;
}
return V_200 ;
}
static T_1 F_95 ( struct V_163 * V_37 )
{
T_1 V_200 ;
V_200 = V_37 -> V_164 << V_166 ;
V_200 |= V_37 -> V_167 << V_169 ;
if ( V_37 -> V_171 ) {
V_200 |= V_37 -> V_172 << V_174 ;
V_200 |= V_37 -> V_175 << V_177 ;
V_200 |= V_170 ;
} else {
V_200 |= V_37 -> V_178 << V_180 ;
V_200 |= V_37 -> V_38 << V_182 ;
}
return V_200 ;
}
static inline void F_96 ( struct V_1 * V_14 ,
struct V_163 * V_37 ,
struct V_32 * V_36 )
{
if ( F_70 ( V_197 , & V_14 -> V_83 ) ) {
F_97 ( F_94 ( V_37 ) ,
V_36 -> V_151 + V_201 ) ;
} else {
F_98 ( F_95 ( V_37 ) ,
V_36 -> V_151 + V_201 ) ;
}
}
static inline unsigned int F_99 ( struct V_1 * V_14 )
{
if ( F_70 ( V_197 , & V_14 -> V_83 ) )
return V_202 ;
else
return V_203 ;
}
static struct V_32 * F_100 ( struct V_1 * V_14 ,
T_8 V_37 )
{
struct V_32 * V_36 ;
struct V_204 * V_205 ;
int V_206 = F_99 ( V_14 ) ;
if ( V_14 -> V_73 == V_74 )
V_206 += V_207 ;
V_36 = F_101 ( V_206 , V_45 ) ;
if ( ! V_36 )
return F_102 ( - V_46 ) ;
V_205 = (struct V_204 * ) F_103 ( V_36 , V_201 ) ;
V_205 -> V_150 = F_14 ( V_206 - V_201 ) ;
V_205 -> V_4 = F_14 ( V_14 -> V_6 ) ;
if ( F_70 ( V_197 , & V_14 -> V_83 ) )
F_97 ( V_37 , F_103 ( V_36 , V_198 ) ) ;
else
F_98 ( V_37 , F_103 ( V_36 , V_199 ) ) ;
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_104 ( 0 , ( T_2 * ) V_36 -> V_151 , V_36 -> V_150 ) ;
F_98 ( V_73 , F_103 ( V_36 , V_207 ) ) ;
}
V_36 -> V_157 = V_158 ;
return V_36 ;
}
static void F_105 ( struct V_1 * V_14 ,
struct V_163 * V_37 )
{
struct V_32 * V_36 ;
T_8 V_208 ;
F_19 ( L_10 , V_14 , V_37 ) ;
if ( ! V_37 -> V_171 )
return;
if ( F_106 ( V_209 , & V_14 -> V_210 ) &&
! V_37 -> V_172 )
V_37 -> V_167 = 1 ;
if ( V_37 -> V_175 == V_211 )
F_107 ( V_212 , & V_14 -> V_210 ) ;
else if ( V_37 -> V_175 == V_213 )
F_56 ( V_212 , & V_14 -> V_210 ) ;
if ( V_37 -> V_175 != V_214 ) {
V_14 -> V_215 = V_37 -> V_164 ;
F_72 ( V_14 ) ;
}
F_19 ( L_11 , V_37 -> V_164 ,
V_37 -> V_167 , V_37 -> V_172 , V_37 -> V_175 ) ;
if ( F_70 ( V_197 , & V_14 -> V_83 ) )
V_208 = F_94 ( V_37 ) ;
else
V_208 = F_95 ( V_37 ) ;
V_36 = F_100 ( V_14 , V_208 ) ;
if ( ! F_108 ( V_36 ) )
F_87 ( V_14 , V_36 ) ;
}
static void F_109 ( struct V_1 * V_14 , bool V_172 )
{
struct V_163 V_37 ;
F_19 ( L_12 , V_14 , V_172 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_171 = 1 ;
V_37 . V_172 = V_172 ;
if ( F_70 ( V_216 , & V_14 -> V_210 ) )
V_37 . V_175 = V_213 ;
else
V_37 . V_175 = V_211 ;
V_37 . V_164 = V_14 -> V_217 ;
F_105 ( V_14 , & V_37 ) ;
}
static inline int F_110 ( struct V_1 * V_14 )
{
return ! F_70 ( V_218 , & V_14 -> V_71 ) ;
}
static void F_111 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_219 V_220 ;
V_220 . V_7 = F_14 ( V_14 -> V_7 ) ;
V_220 . V_10 = V_14 -> V_10 ;
V_14 -> V_9 = F_81 ( V_3 ) ;
F_56 ( V_218 , & V_14 -> V_71 ) ;
F_77 ( V_3 , V_14 -> V_9 , V_221 , sizeof( V_220 ) , & V_220 ) ;
}
static void F_112 ( struct V_1 * V_14 )
{
V_14 -> V_71 = 0 ;
F_68 ( V_14 ) ;
V_14 -> V_23 = V_56 ;
V_14 -> V_24 -> V_222 ( V_14 ) ;
}
static void F_113 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
if ( V_3 -> V_88 -> type == V_89 ) {
F_112 ( V_14 ) ;
return;
}
if ( V_3 -> V_223 & V_224 ) {
if ( ! ( V_3 -> V_223 & V_225 ) )
return;
if ( F_79 ( V_14 ) &&
F_110 ( V_14 ) )
F_111 ( V_14 ) ;
} else {
struct V_226 V_220 ;
V_220 . type = F_76 ( V_227 ) ;
V_3 -> V_223 |= V_224 ;
V_3 -> V_228 = F_81 ( V_3 ) ;
F_114 ( & V_3 -> V_229 , V_230 ) ;
F_77 ( V_3 , V_3 -> V_228 ,
V_231 , sizeof( V_220 ) , & V_220 ) ;
}
}
static inline int F_115 ( T_7 V_114 , T_9 V_232 )
{
T_8 V_233 = V_234 ;
if ( ! V_235 )
V_233 |= V_236 | V_237 ;
switch ( V_114 ) {
case V_116 :
return V_236 & V_232 & V_233 ;
case V_120 :
return V_237 & V_232 & V_233 ;
default:
return 0x00 ;
}
}
static void F_75 ( struct V_2 * V_3 , struct V_1 * V_14 , int V_15 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
struct V_238 V_220 ;
if ( ! V_3 )
return;
if ( V_14 -> V_114 == V_116 && V_14 -> V_23 == V_56 ) {
F_31 ( V_14 ) ;
F_71 ( V_14 ) ;
F_72 ( V_14 ) ;
}
if ( V_14 -> V_86 == V_95 ) {
F_18 ( V_14 , V_132 ) ;
return;
}
V_220 . V_6 = F_14 ( V_14 -> V_6 ) ;
V_220 . V_7 = F_14 ( V_14 -> V_7 ) ;
F_77 ( V_3 , F_81 ( V_3 ) ,
V_239 , sizeof( V_220 ) , & V_220 ) ;
F_22 ( V_13 ) ;
F_18 ( V_14 , V_132 ) ;
F_24 ( V_14 , V_15 ) ;
F_23 ( V_13 ) ;
}
static void F_116 ( struct V_2 * V_3 )
{
struct V_1 * V_14 , * V_240 ;
F_19 ( L_13 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_117 (chan, tmp, &conn->chan_l, list) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_6 ( V_14 ) ;
if ( V_14 -> V_86 != V_87 ) {
F_48 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_59 ) {
if ( ! F_79 ( V_14 ) ||
! F_110 ( V_14 ) ) {
F_48 ( V_14 ) ;
continue;
}
if ( ! F_115 ( V_14 -> V_114 , V_3 -> V_232 )
&& F_70 ( V_241 ,
& V_14 -> V_71 ) ) {
F_47 ( V_14 , V_242 ) ;
F_48 ( V_14 ) ;
continue;
}
F_111 ( V_14 ) ;
} else if ( V_14 -> V_23 == V_125 ) {
struct V_126 V_127 ;
char V_243 [ 128 ] ;
V_127 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_127 . V_6 = F_14 ( V_14 -> V_7 ) ;
if ( F_79 ( V_14 ) ) {
F_22 ( V_13 ) ;
if ( F_70 ( V_129 ,
& F_11 ( V_13 ) -> V_83 ) ) {
struct V_26 * V_244 = F_11 ( V_13 ) -> V_244 ;
V_127 . V_128 = F_76 ( V_245 ) ;
V_127 . V_133 = F_76 ( V_246 ) ;
if ( V_244 )
V_244 -> V_247 ( V_244 , 0 ) ;
} else {
F_18 ( V_14 , V_57 ) ;
V_127 . V_128 = F_76 ( V_248 ) ;
V_127 . V_133 = F_76 ( V_134 ) ;
}
F_23 ( V_13 ) ;
} else {
V_127 . V_128 = F_76 ( V_245 ) ;
V_127 . V_133 = F_76 ( V_249 ) ;
}
F_77 ( V_3 , V_14 -> V_9 , V_135 ,
sizeof( V_127 ) , & V_127 ) ;
if ( F_70 ( V_250 , & V_14 -> V_71 ) ||
V_127 . V_128 != V_248 ) {
F_48 ( V_14 ) ;
continue;
}
F_56 ( V_250 , & V_14 -> V_71 ) ;
F_77 ( V_3 , F_81 ( V_3 ) , V_251 ,
F_118 ( V_14 , V_243 ) , V_243 ) ;
V_14 -> V_252 ++ ;
}
F_48 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_1 * F_119 ( int V_23 , T_1 V_4 ,
T_4 * V_11 ,
T_4 * V_253 )
{
struct V_1 * V_5 , * V_254 = NULL ;
F_120 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_7 == V_4 ) {
int V_255 , V_256 ;
int V_257 , V_258 ;
V_255 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_11 ) ;
V_256 = ! F_10 ( & F_11 ( V_13 ) -> V_253 , V_253 ) ;
if ( V_255 && V_256 ) {
F_121 ( & V_16 ) ;
return V_5 ;
}
V_257 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_259 ) ;
V_258 = ! F_10 ( & F_11 ( V_13 ) -> V_253 , V_259 ) ;
if ( ( V_255 && V_258 ) || ( V_257 && V_256 ) ||
( V_257 && V_258 ) )
V_254 = V_5 ;
}
}
F_121 ( & V_16 ) ;
return V_254 ;
}
static void F_122 ( struct V_2 * V_3 )
{
struct V_26 * V_244 , * V_13 ;
struct V_1 * V_14 , * V_260 ;
F_19 ( L_14 ) ;
V_260 = F_119 ( V_122 , V_92 ,
V_3 -> V_11 , V_3 -> V_253 ) ;
if ( ! V_260 )
return;
V_244 = V_260 -> V_13 ;
F_22 ( V_244 ) ;
V_14 = V_260 -> V_24 -> V_261 ( V_260 ) ;
if ( ! V_14 )
goto V_262;
V_13 = V_14 -> V_13 ;
F_123 ( V_3 -> V_88 ) ;
V_3 -> V_88 -> V_263 = V_264 ;
F_124 ( & F_11 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_124 ( & F_11 ( V_13 ) -> V_253 , V_3 -> V_253 ) ;
F_125 ( V_244 , V_13 ) ;
F_66 ( V_3 , V_14 ) ;
F_112 ( V_14 ) ;
V_262:
F_23 ( V_244 ) ;
}
static void F_126 ( struct V_2 * V_3 )
{
struct V_1 * V_14 ;
struct V_160 * V_88 = V_3 -> V_88 ;
F_19 ( L_13 , V_3 ) ;
if ( ! V_88 -> V_265 && V_88 -> type == V_89 )
F_122 ( V_3 ) ;
if ( V_88 -> V_265 && V_88 -> type == V_89 )
F_127 ( V_88 , V_88 -> V_266 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
F_6 ( V_14 ) ;
if ( V_14 -> V_86 == V_95 ) {
F_48 ( V_14 ) ;
continue;
}
if ( V_88 -> type == V_89 ) {
if ( F_127 ( V_88 , V_14 -> V_60 ) )
F_112 ( V_14 ) ;
} else if ( V_14 -> V_86 != V_87 ) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_68 ( V_14 ) ;
F_22 ( V_13 ) ;
F_18 ( V_14 , V_56 ) ;
V_13 -> V_267 ( V_13 ) ;
F_23 ( V_13 ) ;
} else if ( V_14 -> V_23 == V_59 )
F_113 ( V_14 ) ;
F_48 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static void F_128 ( struct V_2 * V_3 , int V_15 )
{
struct V_1 * V_14 ;
F_19 ( L_13 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
if ( F_70 ( V_268 , & V_14 -> V_83 ) )
F_24 ( V_14 , V_15 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static void F_129 ( struct V_52 * V_53 )
{
struct V_2 * V_3 = F_46 ( V_53 , struct V_2 ,
V_229 . V_53 ) ;
V_3 -> V_223 |= V_225 ;
V_3 -> V_228 = 0 ;
F_116 ( V_3 ) ;
}
static void F_130 ( struct V_160 * V_88 , int V_15 )
{
struct V_2 * V_3 = V_88 -> V_269 ;
struct V_1 * V_14 , * V_270 ;
if ( ! V_3 )
return;
F_19 ( L_15 , V_88 , V_3 , V_15 ) ;
F_131 ( V_3 -> V_271 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_117 (chan, l, &conn->chan_l, list) {
F_59 ( V_14 ) ;
F_6 ( V_14 ) ;
F_67 ( V_14 , V_15 ) ;
F_48 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_49 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
F_132 ( V_3 -> V_159 ) ;
if ( V_3 -> V_223 & V_224 )
F_133 ( & V_3 -> V_229 ) ;
if ( F_106 ( V_272 , & V_88 -> V_83 ) ) {
F_133 ( & V_3 -> V_273 ) ;
F_134 ( V_3 ) ;
}
V_88 -> V_269 = NULL ;
F_39 ( V_3 ) ;
}
static void F_135 ( struct V_52 * V_53 )
{
struct V_2 * V_3 = F_46 ( V_53 , struct V_2 ,
V_273 . V_53 ) ;
F_19 ( L_13 , V_3 ) ;
if ( F_106 ( V_272 , & V_3 -> V_88 -> V_83 ) ) {
F_134 ( V_3 ) ;
F_130 ( V_3 -> V_88 , V_62 ) ;
}
}
static struct V_2 * F_136 ( struct V_160 * V_88 , T_2 V_133 )
{
struct V_2 * V_3 = V_88 -> V_269 ;
struct V_274 * V_159 ;
if ( V_3 || V_133 )
return V_3 ;
V_159 = F_137 ( V_88 ) ;
if ( ! V_159 )
return NULL ;
V_3 = F_51 ( sizeof( struct V_2 ) , V_64 ) ;
if ( ! V_3 ) {
F_132 ( V_159 ) ;
return NULL ;
}
V_88 -> V_269 = V_3 ;
V_3 -> V_88 = V_88 ;
V_3 -> V_159 = V_159 ;
F_19 ( L_16 , V_88 , V_3 , V_159 ) ;
if ( V_88 -> V_152 -> V_275 && V_88 -> type == V_89 )
V_3 -> V_276 = V_88 -> V_152 -> V_275 ;
else
V_3 -> V_276 = V_88 -> V_152 -> V_277 ;
V_3 -> V_11 = & V_88 -> V_152 -> V_278 ;
V_3 -> V_253 = & V_88 -> V_253 ;
V_3 -> V_232 = 0 ;
F_138 ( & V_3 -> V_65 ) ;
F_52 ( & V_3 -> V_8 ) ;
F_139 ( & V_3 -> V_112 ) ;
if ( V_88 -> type == V_89 )
F_54 ( & V_3 -> V_273 , F_135 ) ;
else
F_54 ( & V_3 -> V_229 , F_129 ) ;
V_3 -> V_84 = V_85 ;
return V_3 ;
}
static struct V_1 * F_140 ( int V_23 , T_3 V_10 ,
T_4 * V_11 ,
T_4 * V_253 )
{
struct V_1 * V_5 , * V_254 = NULL ;
F_120 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_10 == V_10 ) {
int V_255 , V_256 ;
int V_257 , V_258 ;
V_255 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_11 ) ;
V_256 = ! F_10 ( & F_11 ( V_13 ) -> V_253 , V_253 ) ;
if ( V_255 && V_256 ) {
F_121 ( & V_16 ) ;
return V_5 ;
}
V_257 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_259 ) ;
V_258 = ! F_10 ( & F_11 ( V_13 ) -> V_253 , V_259 ) ;
if ( ( V_255 && V_258 ) || ( V_257 && V_256 ) ||
( V_257 && V_258 ) )
V_254 = V_5 ;
}
}
F_121 ( & V_16 ) ;
return V_254 ;
}
int F_141 ( struct V_1 * V_14 , T_3 V_10 , T_1 V_4 ,
T_4 * V_253 , T_2 V_279 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
T_4 * V_11 = & F_11 ( V_13 ) -> V_11 ;
struct V_2 * V_3 ;
struct V_160 * V_88 ;
struct V_280 * V_152 ;
T_7 V_146 ;
int V_15 ;
F_19 ( L_17 , F_142 ( V_11 ) , F_142 ( V_253 ) ,
V_279 , F_65 ( V_10 ) ) ;
V_152 = F_143 ( V_253 , V_11 ) ;
if ( ! V_152 )
return - V_281 ;
F_144 ( V_152 ) ;
F_6 ( V_14 ) ;
if ( ( F_65 ( V_10 ) & 0x0101 ) != 0x0001 && ! V_4 &&
V_14 -> V_86 != V_136 ) {
V_15 = - V_20 ;
goto V_18;
}
if ( V_14 -> V_86 == V_87 && ! ( V_10 || V_4 ) ) {
V_15 = - V_20 ;
goto V_18;
}
switch ( V_14 -> V_114 ) {
case V_115 :
break;
case V_116 :
case V_120 :
if ( ! V_235 )
break;
default:
V_15 = - V_282 ;
goto V_18;
}
switch ( V_14 -> V_23 ) {
case V_59 :
case V_125 :
case V_57 :
V_15 = 0 ;
goto V_18;
case V_56 :
V_15 = - V_283 ;
goto V_18;
case V_68 :
case V_284 :
break;
default:
V_15 = - V_285 ;
goto V_18;
}
F_22 ( V_13 ) ;
F_124 ( & F_11 ( V_13 ) -> V_253 , V_253 ) ;
F_23 ( V_13 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_4 ;
V_146 = F_78 ( V_14 ) ;
if ( V_14 -> V_6 == V_92 )
V_88 = F_145 ( V_152 , V_89 , V_253 , V_279 ,
V_14 -> V_60 , V_146 ) ;
else
V_88 = F_145 ( V_152 , V_123 , V_253 , V_279 ,
V_14 -> V_60 , V_146 ) ;
if ( F_108 ( V_88 ) ) {
V_15 = F_146 ( V_88 ) ;
goto V_18;
}
V_3 = F_136 ( V_88 , 0 ) ;
if ( ! V_3 ) {
F_69 ( V_88 ) ;
V_15 = - V_46 ;
goto V_18;
}
if ( V_88 -> type == V_89 ) {
V_15 = 0 ;
if ( ! F_147 ( & V_3 -> V_112 ) ) {
V_15 = - V_286 ;
F_69 ( V_88 ) ;
}
if ( V_15 )
goto V_18;
}
F_124 ( V_11 , V_3 -> V_11 ) ;
F_48 ( V_14 ) ;
F_66 ( V_3 , V_14 ) ;
F_6 ( V_14 ) ;
F_21 ( V_14 , V_59 ) ;
F_74 ( V_14 , V_13 -> V_124 ) ;
if ( V_88 -> V_23 == V_56 ) {
if ( V_14 -> V_86 != V_87 ) {
F_68 ( V_14 ) ;
if ( F_79 ( V_14 ) )
F_21 ( V_14 , V_56 ) ;
} else
F_113 ( V_14 ) ;
}
V_15 = 0 ;
V_18:
F_48 ( V_14 ) ;
F_148 ( V_152 ) ;
F_149 ( V_152 ) ;
return V_15 ;
}
int F_150 ( struct V_26 * V_13 )
{
struct V_1 * V_14 = F_151 ( V_13 ) -> V_14 ;
F_152 ( V_287 , V_288 ) ;
int V_15 = 0 ;
int V_289 = V_290 / 5 ;
F_153 ( F_154 ( V_13 ) , & V_287 ) ;
F_155 ( V_291 ) ;
while ( V_14 -> V_292 > 0 && V_14 -> V_3 ) {
if ( ! V_289 )
V_289 = V_290 / 5 ;
if ( F_156 ( V_288 ) ) {
V_15 = F_157 ( V_289 ) ;
break;
}
F_23 ( V_13 ) ;
V_289 = F_158 ( V_289 ) ;
F_22 ( V_13 ) ;
F_155 ( V_291 ) ;
V_15 = F_159 ( V_13 ) ;
if ( V_15 )
break;
}
F_155 ( V_293 ) ;
F_160 ( F_154 ( V_13 ) , & V_287 ) ;
return V_15 ;
}
static void F_161 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_46 ( V_53 , struct V_1 ,
V_28 . V_53 ) ;
F_19 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
if ( ! V_14 -> V_3 ) {
F_48 ( V_14 ) ;
F_49 ( V_14 ) ;
return;
}
F_162 ( V_14 , NULL , NULL , V_294 ) ;
F_48 ( V_14 ) ;
F_49 ( V_14 ) ;
}
static void F_163 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_46 ( V_53 , struct V_1 ,
V_30 . V_53 ) ;
F_19 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
if ( ! V_14 -> V_3 ) {
F_48 ( V_14 ) ;
F_49 ( V_14 ) ;
return;
}
F_162 ( V_14 , NULL , NULL , V_295 ) ;
F_48 ( V_14 ) ;
F_49 ( V_14 ) ;
}
static void F_164 ( struct V_1 * V_14 ,
struct V_33 * V_296 )
{
struct V_32 * V_36 ;
struct V_163 * V_37 ;
F_19 ( L_18 , V_14 , V_296 ) ;
F_165 ( V_296 , & V_14 -> V_121 ) ;
while ( ! F_166 ( & V_14 -> V_121 ) ) {
V_36 = F_167 ( & V_14 -> V_121 ) ;
F_34 ( V_36 ) -> V_37 . V_297 = 1 ;
V_37 = & F_34 ( V_36 ) -> V_37 ;
V_37 -> V_164 = 0 ;
V_37 -> V_38 = V_14 -> V_298 ;
F_96 ( V_14 , V_37 , V_36 ) ;
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_104 ( 0 , ( T_2 * ) V_36 -> V_151 , V_36 -> V_150 ) ;
F_98 ( V_73 , F_103 ( V_36 , V_207 ) ) ;
}
F_87 ( V_14 , V_36 ) ;
F_19 ( L_19 , V_37 -> V_38 ) ;
V_14 -> V_298 = F_168 ( V_14 , V_14 -> V_298 ) ;
V_14 -> V_299 ++ ;
}
}
static int F_169 ( struct V_1 * V_14 )
{
struct V_32 * V_36 , * V_300 ;
struct V_163 * V_37 ;
int V_301 = 0 ;
F_19 ( L_3 , V_14 ) ;
if ( V_14 -> V_23 != V_56 )
return - V_302 ;
if ( F_70 ( V_303 , & V_14 -> V_210 ) )
return 0 ;
while ( V_14 -> V_304 &&
V_14 -> V_292 < V_14 -> V_305 &&
V_14 -> V_306 == V_307 ) {
V_36 = V_14 -> V_304 ;
F_34 ( V_36 ) -> V_37 . V_297 = 1 ;
V_37 = & F_34 ( V_36 ) -> V_37 ;
if ( F_106 ( V_209 , & V_14 -> V_210 ) )
V_37 -> V_167 = 1 ;
V_37 -> V_164 = V_14 -> V_217 ;
V_14 -> V_215 = V_14 -> V_217 ;
V_37 -> V_38 = V_14 -> V_298 ;
F_96 ( V_14 , V_37 , V_36 ) ;
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_104 ( 0 , ( T_2 * ) V_36 -> V_151 , V_36 -> V_150 ) ;
F_98 ( V_73 , F_103 ( V_36 , V_207 ) ) ;
}
V_300 = F_170 ( V_36 , V_45 ) ;
if ( ! V_300 )
break;
F_26 ( V_14 ) ;
V_14 -> V_298 = F_168 ( V_14 , V_14 -> V_298 ) ;
V_14 -> V_292 ++ ;
V_14 -> V_299 ++ ;
V_301 ++ ;
if ( F_171 ( & V_14 -> V_121 , V_36 ) )
V_14 -> V_304 = NULL ;
else
V_14 -> V_304 = F_172 ( & V_14 -> V_121 , V_36 ) ;
F_87 ( V_14 , V_300 ) ;
F_19 ( L_19 , V_37 -> V_38 ) ;
}
F_19 ( L_20 , V_301 ,
V_14 -> V_292 , F_173 ( & V_14 -> V_121 ) ) ;
return V_301 ;
}
static void F_174 ( struct V_1 * V_14 )
{
struct V_163 V_37 ;
struct V_32 * V_36 ;
struct V_32 * V_300 ;
T_1 V_35 ;
F_19 ( L_3 , V_14 ) ;
if ( F_70 ( V_303 , & V_14 -> V_210 ) )
return;
while ( V_14 -> V_119 . V_34 != V_48 ) {
V_35 = F_42 ( & V_14 -> V_119 ) ;
V_36 = F_32 ( & V_14 -> V_121 , V_35 ) ;
if ( ! V_36 ) {
F_19 ( L_21 ,
V_35 ) ;
continue;
}
F_34 ( V_36 ) -> V_37 . V_297 ++ ;
V_37 = F_34 ( V_36 ) -> V_37 ;
if ( V_14 -> V_75 != 0 &&
F_34 ( V_36 ) -> V_37 . V_297 > V_14 -> V_75 ) {
F_19 ( L_22 , V_14 -> V_75 ) ;
F_75 ( V_14 -> V_3 , V_14 , V_242 ) ;
F_43 ( & V_14 -> V_119 ) ;
break;
}
V_37 . V_164 = V_14 -> V_217 ;
if ( F_106 ( V_209 , & V_14 -> V_210 ) )
V_37 . V_167 = 1 ;
else
V_37 . V_167 = 0 ;
if ( F_175 ( V_36 ) ) {
V_300 = F_176 ( V_36 , V_64 ) ;
} else {
V_300 = F_170 ( V_36 , V_64 ) ;
}
if ( ! V_300 ) {
F_43 ( & V_14 -> V_119 ) ;
break;
}
if ( F_70 ( V_197 , & V_14 -> V_83 ) ) {
F_97 ( F_94 ( & V_37 ) ,
V_300 -> V_151 + V_201 ) ;
} else {
F_98 ( F_95 ( & V_37 ) ,
V_300 -> V_151 + V_201 ) ;
}
if ( V_14 -> V_73 == V_74 ) {
T_1 V_73 = F_104 ( 0 , ( T_2 * ) V_300 -> V_151 , V_300 -> V_150 ) ;
F_98 ( V_73 , F_103 ( V_300 ,
V_207 ) ) ;
}
F_87 ( V_14 , V_300 ) ;
F_19 ( L_23 , V_37 . V_38 ) ;
V_14 -> V_215 = V_14 -> V_217 ;
}
}
static void F_177 ( struct V_1 * V_14 ,
struct V_163 * V_37 )
{
F_19 ( L_10 , V_14 , V_37 ) ;
F_44 ( & V_14 -> V_119 , V_37 -> V_164 ) ;
F_174 ( V_14 ) ;
}
static void F_178 ( struct V_1 * V_14 ,
struct V_163 * V_37 )
{
struct V_32 * V_36 ;
F_19 ( L_10 , V_14 , V_37 ) ;
if ( V_37 -> V_172 )
F_56 ( V_209 , & V_14 -> V_210 ) ;
F_43 ( & V_14 -> V_119 ) ;
if ( F_70 ( V_303 , & V_14 -> V_210 ) )
return;
if ( V_14 -> V_292 ) {
F_33 (&chan->tx_q, skb) {
if ( F_34 ( V_36 ) -> V_37 . V_38 == V_37 -> V_164 ||
V_36 == V_14 -> V_304 )
break;
}
F_179 (&chan->tx_q, skb) {
if ( V_36 == V_14 -> V_304 )
break;
F_44 ( & V_14 -> V_119 ,
F_34 ( V_36 ) -> V_37 . V_38 ) ;
}
F_174 ( V_14 ) ;
}
}
static void F_180 ( struct V_1 * V_14 )
{
struct V_163 V_37 ;
T_1 V_308 = F_181 ( V_14 , V_14 -> V_217 ,
V_14 -> V_215 ) ;
int V_309 ;
F_19 ( L_24 ,
V_14 , V_14 -> V_215 , V_14 -> V_217 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_171 = 1 ;
if ( F_70 ( V_216 , & V_14 -> V_210 ) &&
V_14 -> V_310 == V_311 ) {
F_72 ( V_14 ) ;
V_37 . V_175 = V_213 ;
V_37 . V_164 = V_14 -> V_217 ;
F_105 ( V_14 , & V_37 ) ;
} else {
if ( ! F_70 ( V_303 , & V_14 -> V_210 ) ) {
F_169 ( V_14 ) ;
if ( V_14 -> V_217 == V_14 -> V_215 )
V_308 = 0 ;
}
V_309 = V_14 -> V_80 ;
V_309 += V_309 << 1 ;
V_309 >>= 2 ;
F_19 ( L_25 , V_308 ,
V_309 ) ;
if ( V_308 >= V_309 ) {
F_72 ( V_14 ) ;
V_37 . V_175 = V_211 ;
V_37 . V_164 = V_14 -> V_217 ;
F_105 ( V_14 , & V_37 ) ;
V_308 = 0 ;
}
if ( V_308 )
F_182 ( V_14 ) ;
}
}
static inline int F_183 ( struct V_1 * V_14 ,
struct V_312 * V_313 , int V_150 ,
int V_314 , struct V_32 * V_36 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * * V_315 ;
int V_301 = 0 ;
if ( F_184 ( F_103 ( V_36 , V_314 ) , V_313 -> V_316 , V_314 ) )
return - V_317 ;
V_301 += V_314 ;
V_150 -= V_314 ;
V_315 = & F_185 ( V_36 ) -> V_318 ;
while ( V_150 ) {
struct V_32 * V_240 ;
V_314 = F_186 (unsigned int, conn->mtu, len) ;
V_240 = V_14 -> V_24 -> V_319 ( V_14 , V_314 ,
V_313 -> V_320 & V_321 ) ;
if ( F_108 ( V_240 ) )
return F_146 ( V_240 ) ;
* V_315 = V_240 ;
if ( F_184 ( F_103 ( * V_315 , V_314 ) , V_313 -> V_316 , V_314 ) )
return - V_317 ;
( * V_315 ) -> V_157 = V_36 -> V_157 ;
V_301 += V_314 ;
V_150 -= V_314 ;
V_36 -> V_150 += ( * V_315 ) -> V_150 ;
V_36 -> V_322 += ( * V_315 ) -> V_150 ;
V_315 = & ( * V_315 ) -> V_323 ;
}
return V_301 ;
}
static struct V_32 * F_187 ( struct V_1 * V_14 ,
struct V_312 * V_313 , T_6 V_150 ,
T_8 V_157 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_314 , V_206 = V_201 + V_324 ;
struct V_204 * V_205 ;
F_19 ( L_26 , V_14 , V_150 , V_157 ) ;
V_314 = F_186 (unsigned int, (conn->mtu - hlen), len) ;
V_36 = V_14 -> V_24 -> V_319 ( V_14 , V_314 + V_206 ,
V_313 -> V_320 & V_321 ) ;
if ( F_108 ( V_36 ) )
return V_36 ;
V_36 -> V_157 = V_157 ;
V_205 = (struct V_204 * ) F_103 ( V_36 , V_201 ) ;
V_205 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_205 -> V_150 = F_14 ( V_150 + V_324 ) ;
F_188 ( V_14 -> V_10 , F_103 ( V_36 , V_324 ) ) ;
V_15 = F_183 ( V_14 , V_313 , V_150 , V_314 , V_36 ) ;
if ( F_189 ( V_15 < 0 ) ) {
F_131 ( V_36 ) ;
return F_102 ( V_15 ) ;
}
return V_36 ;
}
static struct V_32 * F_190 ( struct V_1 * V_14 ,
struct V_312 * V_313 , T_6 V_150 ,
T_8 V_157 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_314 ;
struct V_204 * V_205 ;
F_19 ( L_27 , V_14 , V_150 ) ;
V_314 = F_186 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_36 = V_14 -> V_24 -> V_319 ( V_14 , V_314 + V_201 ,
V_313 -> V_320 & V_321 ) ;
if ( F_108 ( V_36 ) )
return V_36 ;
V_36 -> V_157 = V_157 ;
V_205 = (struct V_204 * ) F_103 ( V_36 , V_201 ) ;
V_205 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_205 -> V_150 = F_14 ( V_150 ) ;
V_15 = F_183 ( V_14 , V_313 , V_150 , V_314 , V_36 ) ;
if ( F_189 ( V_15 < 0 ) ) {
F_131 ( V_36 ) ;
return F_102 ( V_15 ) ;
}
return V_36 ;
}
static struct V_32 * F_191 ( struct V_1 * V_14 ,
struct V_312 * V_313 , T_6 V_150 ,
T_1 V_325 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_314 , V_206 ;
struct V_204 * V_205 ;
F_19 ( L_27 , V_14 , V_150 ) ;
if ( ! V_3 )
return F_102 ( - V_302 ) ;
V_206 = F_99 ( V_14 ) ;
if ( V_325 )
V_206 += V_326 ;
if ( V_14 -> V_73 == V_74 )
V_206 += V_207 ;
V_314 = F_186 (unsigned int, (conn->mtu - hlen), len) ;
V_36 = V_14 -> V_24 -> V_319 ( V_14 , V_314 + V_206 ,
V_313 -> V_320 & V_321 ) ;
if ( F_108 ( V_36 ) )
return V_36 ;
V_205 = (struct V_204 * ) F_103 ( V_36 , V_201 ) ;
V_205 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_205 -> V_150 = F_14 ( V_150 + ( V_206 - V_201 ) ) ;
if ( F_70 ( V_197 , & V_14 -> V_83 ) )
F_97 ( 0 , F_103 ( V_36 , V_198 ) ) ;
else
F_98 ( 0 , F_103 ( V_36 , V_199 ) ) ;
if ( V_325 )
F_98 ( V_325 , F_103 ( V_36 , V_326 ) ) ;
V_15 = F_183 ( V_14 , V_313 , V_150 , V_314 , V_36 ) ;
if ( F_189 ( V_15 < 0 ) ) {
F_131 ( V_36 ) ;
return F_102 ( V_15 ) ;
}
F_34 ( V_36 ) -> V_37 . V_73 = V_14 -> V_73 ;
F_34 ( V_36 ) -> V_37 . V_297 = 0 ;
return V_36 ;
}
static int F_192 ( struct V_1 * V_14 ,
struct V_33 * V_327 ,
struct V_312 * V_313 , T_6 V_150 )
{
struct V_32 * V_36 ;
T_1 V_328 ;
T_6 V_329 ;
T_2 V_178 ;
F_19 ( L_28 , V_14 , V_313 , V_150 ) ;
V_329 = V_14 -> V_3 -> V_276 ;
V_329 = F_186 ( T_6 , V_329 , V_330 ) ;
if ( V_14 -> V_73 )
V_329 -= V_207 ;
V_329 -= F_99 ( V_14 ) ;
V_329 = F_186 ( T_6 , V_329 , V_14 -> V_331 ) ;
if ( V_150 <= V_329 ) {
V_178 = V_332 ;
V_328 = 0 ;
V_329 = V_150 ;
} else {
V_178 = V_333 ;
V_328 = V_150 ;
V_329 -= V_326 ;
}
while ( V_150 > 0 ) {
V_36 = F_191 ( V_14 , V_313 , V_329 , V_328 ) ;
if ( F_108 ( V_36 ) ) {
F_193 ( V_327 ) ;
return F_146 ( V_36 ) ;
}
F_34 ( V_36 ) -> V_37 . V_178 = V_178 ;
F_194 ( V_327 , V_36 ) ;
V_150 -= V_329 ;
if ( V_328 ) {
V_328 = 0 ;
V_329 += V_326 ;
}
if ( V_150 <= V_329 ) {
V_178 = V_334 ;
V_329 = V_150 ;
} else {
V_178 = V_335 ;
}
}
return 0 ;
}
int F_195 ( struct V_1 * V_14 , struct V_312 * V_313 , T_6 V_150 ,
T_8 V_157 )
{
struct V_32 * V_36 ;
int V_15 ;
struct V_33 V_327 ;
if ( V_14 -> V_86 == V_93 ) {
V_36 = F_187 ( V_14 , V_313 , V_150 , V_157 ) ;
if ( F_108 ( V_36 ) )
return F_146 ( V_36 ) ;
F_87 ( V_14 , V_36 ) ;
return V_150 ;
}
switch ( V_14 -> V_114 ) {
case V_115 :
if ( V_150 > V_14 -> V_90 )
return - V_336 ;
V_36 = F_190 ( V_14 , V_313 , V_150 , V_157 ) ;
if ( F_108 ( V_36 ) )
return F_146 ( V_36 ) ;
F_87 ( V_14 , V_36 ) ;
V_15 = V_150 ;
break;
case V_116 :
case V_120 :
if ( V_150 > V_14 -> V_90 ) {
V_15 = - V_336 ;
break;
}
F_196 ( & V_327 ) ;
V_15 = F_192 ( V_14 , & V_327 , V_313 , V_150 ) ;
if ( V_14 -> V_23 != V_56 ) {
F_193 ( & V_327 ) ;
V_15 = - V_302 ;
}
if ( V_15 )
break;
if ( V_14 -> V_114 == V_116 )
F_162 ( V_14 , NULL , & V_327 , V_337 ) ;
else
F_164 ( V_14 , & V_327 ) ;
V_15 = V_150 ;
F_193 ( & V_327 ) ;
break;
default:
F_19 ( L_29 , V_14 -> V_114 ) ;
V_15 = - V_285 ;
}
return V_15 ;
}
static void F_197 ( struct V_1 * V_14 , T_1 V_38 )
{
struct V_163 V_37 ;
T_1 V_35 ;
F_19 ( L_30 , V_14 , V_38 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_171 = 1 ;
V_37 . V_175 = V_214 ;
for ( V_35 = V_14 -> V_338 ; V_35 != V_38 ;
V_35 = F_168 ( V_14 , V_35 ) ) {
if ( ! F_32 ( & V_14 -> V_117 , V_35 ) ) {
V_37 . V_164 = V_35 ;
F_105 ( V_14 , & V_37 ) ;
F_44 ( & V_14 -> V_118 , V_35 ) ;
}
}
V_14 -> V_338 = F_168 ( V_14 , V_38 ) ;
}
static void F_198 ( struct V_1 * V_14 )
{
struct V_163 V_37 ;
F_19 ( L_3 , V_14 ) ;
if ( V_14 -> V_118 . V_49 == V_48 )
return;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_171 = 1 ;
V_37 . V_175 = V_214 ;
V_37 . V_164 = V_14 -> V_118 . V_49 ;
F_105 ( V_14 , & V_37 ) ;
}
static void F_199 ( struct V_1 * V_14 , T_1 V_38 )
{
struct V_163 V_37 ;
T_1 V_339 ;
T_1 V_35 ;
F_19 ( L_30 , V_14 , V_38 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_171 = 1 ;
V_37 . V_175 = V_214 ;
V_339 = V_14 -> V_118 . V_34 ;
do {
V_35 = F_42 ( & V_14 -> V_118 ) ;
if ( V_35 == V_38 || V_35 == V_48 )
break;
V_37 . V_164 = V_35 ;
F_105 ( V_14 , & V_37 ) ;
F_44 ( & V_14 -> V_118 , V_35 ) ;
} while ( V_14 -> V_118 . V_34 != V_339 );
}
static void F_200 ( struct V_1 * V_14 , T_1 V_164 )
{
struct V_32 * V_340 ;
T_1 V_341 ;
F_19 ( L_31 , V_14 , V_164 ) ;
if ( V_14 -> V_292 == 0 || V_164 == V_14 -> V_342 )
return;
F_19 ( L_32 ,
V_14 -> V_342 , V_14 -> V_292 ) ;
for ( V_341 = V_14 -> V_342 ; V_341 != V_164 ;
V_341 = F_168 ( V_14 , V_341 ) ) {
V_340 = F_32 ( & V_14 -> V_121 , V_341 ) ;
if ( V_340 ) {
F_201 ( V_340 , & V_14 -> V_121 ) ;
F_131 ( V_340 ) ;
V_14 -> V_292 -- ;
}
}
V_14 -> V_342 = V_164 ;
if ( V_14 -> V_292 == 0 )
F_31 ( V_14 ) ;
F_19 ( L_33 , V_14 -> V_292 ) ;
}
static void F_202 ( struct V_1 * V_14 )
{
F_19 ( L_3 , V_14 ) ;
V_14 -> V_338 = V_14 -> V_217 ;
F_43 ( & V_14 -> V_118 ) ;
F_73 ( & V_14 -> V_117 ) ;
V_14 -> V_310 = V_311 ;
}
static void F_203 ( struct V_1 * V_14 ,
struct V_163 * V_37 ,
struct V_33 * V_296 , T_2 V_343 )
{
F_19 ( L_34 , V_14 , V_37 , V_296 ,
V_343 ) ;
switch ( V_343 ) {
case V_337 :
if ( V_14 -> V_304 == NULL )
V_14 -> V_304 = F_204 ( V_296 ) ;
F_165 ( V_296 , & V_14 -> V_121 ) ;
F_169 ( V_14 ) ;
break;
case V_344 :
F_19 ( L_35 ) ;
F_56 ( V_216 , & V_14 -> V_210 ) ;
if ( V_14 -> V_310 == V_345 ) {
F_202 ( V_14 ) ;
}
F_180 ( V_14 ) ;
break;
case V_346 :
F_19 ( L_36 ) ;
F_107 ( V_216 , & V_14 -> V_210 ) ;
if ( F_70 ( V_212 , & V_14 -> V_210 ) ) {
struct V_163 V_347 ;
memset ( & V_347 , 0 , sizeof( V_347 ) ) ;
V_347 . V_171 = 1 ;
V_347 . V_175 = V_211 ;
V_347 . V_172 = 1 ;
V_347 . V_164 = V_14 -> V_217 ;
F_105 ( V_14 , & V_347 ) ;
V_14 -> V_348 = 1 ;
F_30 ( V_14 ) ;
V_14 -> V_306 = V_349 ;
}
break;
case V_350 :
F_200 ( V_14 , V_37 -> V_164 ) ;
break;
case V_351 :
F_109 ( V_14 , 1 ) ;
V_14 -> V_348 = 1 ;
F_30 ( V_14 ) ;
F_72 ( V_14 ) ;
V_14 -> V_306 = V_349 ;
break;
case V_295 :
F_109 ( V_14 , 1 ) ;
V_14 -> V_348 = 1 ;
F_30 ( V_14 ) ;
V_14 -> V_306 = V_349 ;
break;
case V_352 :
break;
default:
break;
}
}
static void F_205 ( struct V_1 * V_14 ,
struct V_163 * V_37 ,
struct V_33 * V_296 , T_2 V_343 )
{
F_19 ( L_34 , V_14 , V_37 , V_296 ,
V_343 ) ;
switch ( V_343 ) {
case V_337 :
if ( V_14 -> V_304 == NULL )
V_14 -> V_304 = F_204 ( V_296 ) ;
F_165 ( V_296 , & V_14 -> V_121 ) ;
break;
case V_344 :
F_19 ( L_35 ) ;
F_56 ( V_216 , & V_14 -> V_210 ) ;
if ( V_14 -> V_310 == V_345 ) {
F_202 ( V_14 ) ;
}
F_180 ( V_14 ) ;
break;
case V_346 :
F_19 ( L_36 ) ;
F_107 ( V_216 , & V_14 -> V_210 ) ;
if ( F_70 ( V_212 , & V_14 -> V_210 ) ) {
struct V_163 V_347 ;
memset ( & V_347 , 0 , sizeof( V_347 ) ) ;
V_347 . V_171 = 1 ;
V_347 . V_175 = V_211 ;
V_347 . V_172 = 1 ;
V_347 . V_164 = V_14 -> V_217 ;
F_105 ( V_14 , & V_347 ) ;
V_14 -> V_348 = 1 ;
F_30 ( V_14 ) ;
V_14 -> V_306 = V_349 ;
}
break;
case V_350 :
F_200 ( V_14 , V_37 -> V_164 ) ;
case V_352 :
if ( V_37 && V_37 -> V_167 ) {
F_71 ( V_14 ) ;
if ( V_14 -> V_292 > 0 )
F_26 ( V_14 ) ;
V_14 -> V_348 = 0 ;
V_14 -> V_306 = V_307 ;
F_19 ( L_37 , V_14 -> V_306 ) ;
}
break;
case V_351 :
break;
case V_294 :
if ( V_14 -> V_75 == 0 || V_14 -> V_348 < V_14 -> V_75 ) {
F_109 ( V_14 , 1 ) ;
F_30 ( V_14 ) ;
V_14 -> V_348 ++ ;
} else {
F_75 ( V_14 -> V_3 , V_14 , V_353 ) ;
}
break;
default:
break;
}
}
static void F_162 ( struct V_1 * V_14 , struct V_163 * V_37 ,
struct V_33 * V_296 , T_2 V_343 )
{
F_19 ( L_38 ,
V_14 , V_37 , V_296 , V_343 , V_14 -> V_306 ) ;
switch ( V_14 -> V_306 ) {
case V_307 :
F_203 ( V_14 , V_37 , V_296 , V_343 ) ;
break;
case V_349 :
F_205 ( V_14 , V_37 , V_296 , V_343 ) ;
break;
default:
break;
}
}
static void F_206 ( struct V_1 * V_14 ,
struct V_163 * V_37 )
{
F_19 ( L_10 , V_14 , V_37 ) ;
F_162 ( V_14 , V_37 , NULL , V_350 ) ;
}
static void F_207 ( struct V_1 * V_14 ,
struct V_163 * V_37 )
{
F_19 ( L_10 , V_14 , V_37 ) ;
F_162 ( V_14 , V_37 , NULL , V_352 ) ;
}
static void F_208 ( struct V_2 * V_3 , struct V_32 * V_36 )
{
struct V_32 * V_354 ;
struct V_1 * V_14 ;
F_19 ( L_13 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
struct V_26 * V_13 = V_14 -> V_13 ;
if ( V_14 -> V_86 != V_136 )
continue;
if ( V_36 -> V_13 == V_13 )
continue;
V_354 = F_170 ( V_36 , V_64 ) ;
if ( ! V_354 )
continue;
if ( V_14 -> V_24 -> V_355 ( V_14 , V_354 ) )
F_131 ( V_354 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_32 * F_84 ( struct V_2 * V_3 , T_2 V_149 ,
T_2 V_9 , T_1 V_356 , void * V_151 )
{
struct V_32 * V_36 , * * V_315 ;
struct V_357 * V_358 ;
struct V_204 * V_205 ;
int V_150 , V_314 ;
F_19 ( L_39 ,
V_3 , V_149 , V_9 , V_356 ) ;
V_150 = V_201 + V_359 + V_356 ;
V_314 = F_186 (unsigned int, conn->mtu, len) ;
V_36 = F_101 ( V_314 , V_64 ) ;
if ( ! V_36 )
return NULL ;
V_205 = (struct V_204 * ) F_103 ( V_36 , V_201 ) ;
V_205 -> V_150 = F_14 ( V_359 + V_356 ) ;
if ( V_3 -> V_88 -> type == V_89 )
V_205 -> V_4 = F_76 ( V_360 ) ;
else
V_205 -> V_4 = F_76 ( V_99 ) ;
V_358 = (struct V_357 * ) F_103 ( V_36 , V_359 ) ;
V_358 -> V_149 = V_149 ;
V_358 -> V_9 = V_9 ;
V_358 -> V_150 = F_14 ( V_356 ) ;
if ( V_356 ) {
V_314 -= V_201 + V_359 ;
memcpy ( F_103 ( V_36 , V_314 ) , V_151 , V_314 ) ;
V_151 += V_314 ;
}
V_150 -= V_36 -> V_150 ;
V_315 = & F_185 ( V_36 ) -> V_318 ;
while ( V_150 ) {
V_314 = F_186 (unsigned int, conn->mtu, len) ;
* V_315 = F_101 ( V_314 , V_64 ) ;
if ( ! * V_315 )
goto V_361;
memcpy ( F_103 ( * V_315 , V_314 ) , V_151 , V_314 ) ;
V_150 -= V_314 ;
V_151 += V_314 ;
V_315 = & ( * V_315 ) -> V_323 ;
}
return V_36 ;
V_361:
F_131 ( V_36 ) ;
return NULL ;
}
static inline int F_209 ( void * * V_362 , int * type , int * V_363 , unsigned long * V_364 )
{
struct V_365 * V_366 = * V_362 ;
int V_150 ;
V_150 = V_367 + V_366 -> V_150 ;
* V_362 += V_150 ;
* type = V_366 -> type ;
* V_363 = V_366 -> V_150 ;
switch ( V_366 -> V_150 ) {
case 1 :
* V_364 = * ( ( T_2 * ) V_366 -> V_364 ) ;
break;
case 2 :
* V_364 = F_93 ( V_366 -> V_364 ) ;
break;
case 4 :
* V_364 = F_91 ( V_366 -> V_364 ) ;
break;
default:
* V_364 = ( unsigned long ) V_366 -> V_364 ;
break;
}
F_19 ( L_40 , * type , V_366 -> V_150 , * V_364 ) ;
return V_150 ;
}
static void F_210 ( void * * V_362 , T_2 type , T_2 V_150 , unsigned long V_364 )
{
struct V_365 * V_366 = * V_362 ;
F_19 ( L_40 , type , V_150 , V_364 ) ;
V_366 -> type = type ;
V_366 -> V_150 = V_150 ;
switch ( V_150 ) {
case 1 :
* ( ( T_2 * ) V_366 -> V_364 ) = V_364 ;
break;
case 2 :
F_98 ( V_364 , V_366 -> V_364 ) ;
break;
case 4 :
F_97 ( V_364 , V_366 -> V_364 ) ;
break;
default:
memcpy ( V_366 -> V_364 , ( void * ) V_364 , V_150 ) ;
break;
}
* V_362 += V_367 + V_150 ;
}
static void F_211 ( void * * V_362 , struct V_1 * V_14 )
{
struct V_368 V_369 ;
switch ( V_14 -> V_114 ) {
case V_116 :
V_369 . V_147 = V_14 -> V_100 ;
V_369 . V_370 = V_14 -> V_102 ;
V_369 . V_371 = F_14 ( V_14 -> V_104 ) ;
V_369 . V_372 = F_212 ( V_14 -> V_106 ) ;
V_369 . V_373 = F_213 ( V_109 ) ;
V_369 . V_374 = F_213 ( V_111 ) ;
break;
case V_120 :
V_369 . V_147 = 1 ;
V_369 . V_370 = V_103 ;
V_369 . V_371 = F_14 ( V_14 -> V_104 ) ;
V_369 . V_372 = F_212 ( V_14 -> V_106 ) ;
V_369 . V_373 = 0 ;
V_369 . V_374 = 0 ;
break;
default:
return;
}
F_210 ( V_362 , V_375 , sizeof( V_369 ) ,
( unsigned long ) & V_369 ) ;
}
static void F_214 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_46 ( V_53 , struct V_1 ,
V_376 . V_53 ) ;
T_1 V_308 ;
F_19 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
V_308 = F_181 ( V_14 , V_14 -> V_217 ,
V_14 -> V_215 ) ;
if ( V_308 )
F_109 ( V_14 , 0 ) ;
F_48 ( V_14 ) ;
F_49 ( V_14 ) ;
}
int F_215 ( struct V_1 * V_14 )
{
int V_15 ;
V_14 -> V_298 = 0 ;
V_14 -> V_338 = 0 ;
V_14 -> V_342 = 0 ;
V_14 -> V_292 = 0 ;
V_14 -> V_217 = 0 ;
V_14 -> V_299 = 0 ;
V_14 -> V_215 = 0 ;
V_14 -> V_377 = NULL ;
V_14 -> V_378 = NULL ;
V_14 -> V_328 = 0 ;
F_216 ( & V_14 -> V_121 ) ;
if ( V_14 -> V_114 != V_116 )
return 0 ;
V_14 -> V_310 = V_311 ;
V_14 -> V_306 = V_307 ;
F_54 ( & V_14 -> V_30 , F_163 ) ;
F_54 ( & V_14 -> V_28 , F_161 ) ;
F_54 ( & V_14 -> V_376 , F_214 ) ;
F_216 ( & V_14 -> V_117 ) ;
V_15 = F_35 ( & V_14 -> V_118 , V_14 -> V_77 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_35 ( & V_14 -> V_119 , V_14 -> V_305 ) ;
if ( V_15 < 0 )
F_38 ( & V_14 -> V_118 ) ;
return V_15 ;
}
static inline T_7 F_217 ( T_7 V_114 , T_5 V_379 )
{
switch ( V_114 ) {
case V_120 :
case V_116 :
if ( F_115 ( V_114 , V_379 ) )
return V_114 ;
default:
return V_115 ;
}
}
static inline bool F_218 ( struct V_1 * V_14 )
{
return V_380 && V_14 -> V_3 -> V_232 & V_381 ;
}
static inline bool F_219 ( struct V_1 * V_14 )
{
return V_380 && V_14 -> V_3 -> V_232 & V_382 ;
}
static inline void F_220 ( struct V_1 * V_14 )
{
if ( V_14 -> V_77 > V_78 &&
F_218 ( V_14 ) ) {
F_56 ( V_197 , & V_14 -> V_83 ) ;
V_14 -> V_79 = V_383 ;
} else {
V_14 -> V_77 = F_186 ( T_1 , V_14 -> V_77 ,
V_78 ) ;
V_14 -> V_79 = V_78 ;
}
V_14 -> V_80 = V_14 -> V_77 ;
}
static int F_118 ( struct V_1 * V_14 , void * V_151 )
{
struct V_384 * V_220 = V_151 ;
struct V_385 V_386 = { . V_114 = V_14 -> V_114 } ;
void * V_362 = V_220 -> V_151 ;
T_1 V_41 ;
F_19 ( L_3 , V_14 ) ;
if ( V_14 -> V_252 || V_14 -> V_387 )
goto V_18;
switch ( V_14 -> V_114 ) {
case V_120 :
case V_116 :
if ( F_70 ( V_241 , & V_14 -> V_71 ) )
break;
if ( F_219 ( V_14 ) )
F_56 ( V_388 , & V_14 -> V_83 ) ;
default:
V_14 -> V_114 = F_217 ( V_386 . V_114 , V_14 -> V_3 -> V_232 ) ;
break;
}
V_18:
if ( V_14 -> V_98 != V_91 )
F_210 ( & V_362 , V_389 , 2 , V_14 -> V_98 ) ;
switch ( V_14 -> V_114 ) {
case V_115 :
if ( ! ( V_14 -> V_3 -> V_232 & V_236 ) &&
! ( V_14 -> V_3 -> V_232 & V_237 ) )
break;
V_386 . V_114 = V_115 ;
V_386 . V_390 = 0 ;
V_386 . V_391 = 0 ;
V_386 . V_29 = 0 ;
V_386 . V_31 = 0 ;
V_386 . V_392 = 0 ;
F_210 ( & V_362 , V_393 , sizeof( V_386 ) ,
( unsigned long ) & V_386 ) ;
break;
case V_116 :
V_386 . V_114 = V_116 ;
V_386 . V_391 = V_14 -> V_75 ;
V_386 . V_29 = 0 ;
V_386 . V_31 = 0 ;
V_41 = F_186 ( T_1 , V_394 , V_14 -> V_3 -> V_276 -
V_202 -
V_326 -
V_207 ) ;
V_386 . V_392 = F_14 ( V_41 ) ;
F_220 ( V_14 ) ;
V_386 . V_390 = F_186 ( T_1 , V_14 -> V_77 ,
V_78 ) ;
F_210 ( & V_362 , V_393 , sizeof( V_386 ) ,
( unsigned long ) & V_386 ) ;
if ( F_70 ( V_388 , & V_14 -> V_83 ) )
F_211 ( & V_362 , V_14 ) ;
if ( ! ( V_14 -> V_3 -> V_232 & V_395 ) )
break;
if ( V_14 -> V_73 == V_396 ||
F_70 ( V_397 , & V_14 -> V_71 ) ) {
V_14 -> V_73 = V_396 ;
F_210 ( & V_362 , V_398 , 1 , V_14 -> V_73 ) ;
}
if ( F_70 ( V_197 , & V_14 -> V_83 ) )
F_210 ( & V_362 , V_399 , 2 ,
V_14 -> V_77 ) ;
break;
case V_120 :
F_220 ( V_14 ) ;
V_386 . V_114 = V_120 ;
V_386 . V_390 = 0 ;
V_386 . V_391 = 0 ;
V_386 . V_29 = 0 ;
V_386 . V_31 = 0 ;
V_41 = F_186 ( T_1 , V_394 , V_14 -> V_3 -> V_276 -
V_202 -
V_326 -
V_207 ) ;
V_386 . V_392 = F_14 ( V_41 ) ;
F_210 ( & V_362 , V_393 , sizeof( V_386 ) ,
( unsigned long ) & V_386 ) ;
if ( F_70 ( V_388 , & V_14 -> V_83 ) )
F_211 ( & V_362 , V_14 ) ;
if ( ! ( V_14 -> V_3 -> V_232 & V_395 ) )
break;
if ( V_14 -> V_73 == V_396 ||
F_70 ( V_397 , & V_14 -> V_71 ) ) {
V_14 -> V_73 = V_396 ;
F_210 ( & V_362 , V_398 , 1 , V_14 -> V_73 ) ;
}
break;
}
V_220 -> V_6 = F_14 ( V_14 -> V_6 ) ;
V_220 -> V_83 = F_76 ( 0 ) ;
return V_362 - V_151 ;
}
static int F_221 ( struct V_1 * V_14 , void * V_151 )
{
struct V_400 * V_127 = V_151 ;
void * V_362 = V_127 -> V_151 ;
void * V_220 = V_14 -> V_401 ;
int V_150 = V_14 -> V_402 ;
int type , V_403 , V_363 ;
unsigned long V_364 ;
struct V_385 V_386 = { . V_114 = V_115 } ;
struct V_368 V_369 ;
T_2 V_404 = 0 ;
T_1 V_276 = V_91 ;
T_1 V_128 = V_405 ;
T_1 V_41 ;
F_19 ( L_3 , V_14 ) ;
while ( V_150 >= V_367 ) {
V_150 -= F_209 ( & V_220 , & type , & V_363 , & V_364 ) ;
V_403 = type & V_406 ;
type &= V_407 ;
switch ( type ) {
case V_389 :
V_276 = V_364 ;
break;
case V_408 :
V_14 -> V_374 = V_364 ;
break;
case V_409 :
break;
case V_393 :
if ( V_363 == sizeof( V_386 ) )
memcpy ( & V_386 , ( void * ) V_364 , V_363 ) ;
break;
case V_398 :
if ( V_364 == V_396 )
F_56 ( V_397 , & V_14 -> V_71 ) ;
break;
case V_375 :
V_404 = 1 ;
if ( V_363 == sizeof( V_369 ) )
memcpy ( & V_369 , ( void * ) V_364 , V_363 ) ;
break;
case V_399 :
if ( ! V_380 )
return - V_58 ;
F_56 ( V_197 , & V_14 -> V_83 ) ;
F_56 ( V_410 , & V_14 -> V_71 ) ;
V_14 -> V_79 = V_383 ;
V_14 -> V_305 = V_364 ;
break;
default:
if ( V_403 )
break;
V_128 = V_411 ;
* ( ( T_2 * ) V_362 ++ ) = type ;
break;
}
}
if ( V_14 -> V_387 || V_14 -> V_252 > 1 )
goto V_18;
switch ( V_14 -> V_114 ) {
case V_120 :
case V_116 :
if ( ! F_70 ( V_241 , & V_14 -> V_71 ) ) {
V_14 -> V_114 = F_217 ( V_386 . V_114 ,
V_14 -> V_3 -> V_232 ) ;
break;
}
if ( V_404 ) {
if ( F_219 ( V_14 ) )
F_56 ( V_388 , & V_14 -> V_83 ) ;
else
return - V_58 ;
}
if ( V_14 -> V_114 != V_386 . V_114 )
return - V_58 ;
break;
}
V_18:
if ( V_14 -> V_114 != V_386 . V_114 ) {
V_128 = V_412 ;
V_386 . V_114 = V_14 -> V_114 ;
if ( V_14 -> V_387 == 1 )
return - V_58 ;
F_210 ( & V_362 , V_393 ,
sizeof( V_386 ) , ( unsigned long ) & V_386 ) ;
}
if ( V_128 == V_405 ) {
if ( V_276 < V_413 )
V_128 = V_412 ;
else {
V_14 -> V_90 = V_276 ;
F_56 ( V_414 , & V_14 -> V_71 ) ;
}
F_210 ( & V_362 , V_389 , 2 , V_14 -> V_90 ) ;
if ( V_404 ) {
if ( V_14 -> V_102 != V_415 &&
V_369 . V_370 != V_415 &&
V_369 . V_370 != V_14 -> V_102 ) {
V_128 = V_412 ;
if ( V_14 -> V_252 >= 1 )
return - V_58 ;
F_210 ( & V_362 , V_375 ,
sizeof( V_369 ) ,
( unsigned long ) & V_369 ) ;
} else {
V_128 = V_416 ;
F_56 ( V_417 , & V_14 -> V_71 ) ;
}
}
switch ( V_386 . V_114 ) {
case V_115 :
V_14 -> V_73 = V_396 ;
F_56 ( V_418 , & V_14 -> V_71 ) ;
break;
case V_116 :
if ( ! F_70 ( V_410 , & V_14 -> V_71 ) )
V_14 -> V_305 = V_386 . V_390 ;
else
V_386 . V_390 = V_78 ;
V_14 -> V_419 = V_386 . V_391 ;
V_41 = F_186 ( T_1 , F_222 ( V_386 . V_392 ) ,
V_14 -> V_3 -> V_276 -
V_202 -
V_326 -
V_207 ) ;
V_386 . V_392 = F_14 ( V_41 ) ;
V_14 -> V_331 = V_41 ;
V_386 . V_29 =
F_76 ( V_420 ) ;
V_386 . V_31 =
F_76 ( V_421 ) ;
F_56 ( V_418 , & V_14 -> V_71 ) ;
F_210 ( & V_362 , V_393 ,
sizeof( V_386 ) , ( unsigned long ) & V_386 ) ;
if ( F_70 ( V_388 , & V_14 -> V_83 ) ) {
V_14 -> V_422 = V_369 . V_147 ;
V_14 -> V_423 = V_369 . V_370 ;
V_14 -> V_424 = F_222 ( V_369 . V_371 ) ;
V_14 -> V_425 =
F_223 ( V_369 . V_374 ) ;
V_14 -> V_426 =
F_223 ( V_369 . V_373 ) ;
V_14 -> V_427 =
F_223 ( V_369 . V_372 ) ;
F_210 ( & V_362 , V_375 ,
sizeof( V_369 ) , ( unsigned long ) & V_369 ) ;
}
break;
case V_120 :
V_41 = F_186 ( T_1 , F_222 ( V_386 . V_392 ) ,
V_14 -> V_3 -> V_276 -
V_202 -
V_326 -
V_207 ) ;
V_386 . V_392 = F_14 ( V_41 ) ;
V_14 -> V_331 = V_41 ;
F_56 ( V_418 , & V_14 -> V_71 ) ;
F_210 ( & V_362 , V_393 ,
sizeof( V_386 ) , ( unsigned long ) & V_386 ) ;
break;
default:
V_128 = V_412 ;
memset ( & V_386 , 0 , sizeof( V_386 ) ) ;
V_386 . V_114 = V_14 -> V_114 ;
}
if ( V_128 == V_405 )
F_56 ( V_428 , & V_14 -> V_71 ) ;
}
V_127 -> V_7 = F_14 ( V_14 -> V_6 ) ;
V_127 -> V_128 = F_14 ( V_128 ) ;
V_127 -> V_83 = F_76 ( 0 ) ;
return V_362 - V_151 ;
}
static int F_224 ( struct V_1 * V_14 , void * V_127 , int V_150 , void * V_151 , T_1 * V_128 )
{
struct V_384 * V_220 = V_151 ;
void * V_362 = V_220 -> V_151 ;
int type , V_363 ;
unsigned long V_364 ;
struct V_385 V_386 = { . V_114 = V_115 } ;
struct V_368 V_369 ;
F_19 ( L_41 , V_14 , V_127 , V_150 , V_151 ) ;
while ( V_150 >= V_367 ) {
V_150 -= F_209 ( & V_127 , & type , & V_363 , & V_364 ) ;
switch ( type ) {
case V_389 :
if ( V_364 < V_413 ) {
* V_128 = V_412 ;
V_14 -> V_98 = V_413 ;
} else
V_14 -> V_98 = V_364 ;
F_210 ( & V_362 , V_389 , 2 , V_14 -> V_98 ) ;
break;
case V_408 :
V_14 -> V_374 = V_364 ;
F_210 ( & V_362 , V_408 ,
2 , V_14 -> V_374 ) ;
break;
case V_393 :
if ( V_363 == sizeof( V_386 ) )
memcpy ( & V_386 , ( void * ) V_364 , V_363 ) ;
if ( F_70 ( V_241 , & V_14 -> V_71 ) &&
V_386 . V_114 != V_14 -> V_114 )
return - V_58 ;
V_14 -> V_73 = 0 ;
F_210 ( & V_362 , V_393 ,
sizeof( V_386 ) , ( unsigned long ) & V_386 ) ;
break;
case V_399 :
V_14 -> V_80 = F_186 ( T_1 , V_364 , V_14 -> V_80 ) ;
F_210 ( & V_362 , V_399 , 2 ,
V_14 -> V_77 ) ;
break;
case V_375 :
if ( V_363 == sizeof( V_369 ) )
memcpy ( & V_369 , ( void * ) V_364 , V_363 ) ;
if ( V_14 -> V_102 != V_415 &&
V_369 . V_370 != V_415 &&
V_369 . V_370 != V_14 -> V_102 )
return - V_58 ;
F_210 ( & V_362 , V_375 ,
sizeof( V_369 ) , ( unsigned long ) & V_369 ) ;
break;
}
}
if ( V_14 -> V_114 == V_115 && V_14 -> V_114 != V_386 . V_114 )
return - V_58 ;
V_14 -> V_114 = V_386 . V_114 ;
if ( * V_128 == V_405 || * V_128 == V_416 ) {
switch ( V_386 . V_114 ) {
case V_116 :
V_14 -> V_29 = F_222 ( V_386 . V_29 ) ;
V_14 -> V_31 = F_222 ( V_386 . V_31 ) ;
V_14 -> V_429 = F_222 ( V_386 . V_392 ) ;
if ( ! F_70 ( V_197 , & V_14 -> V_83 ) )
V_14 -> V_80 = F_186 ( T_1 , V_14 -> V_80 ,
V_386 . V_390 ) ;
if ( F_70 ( V_388 , & V_14 -> V_83 ) ) {
V_14 -> V_104 = F_222 ( V_369 . V_371 ) ;
V_14 -> V_106 =
F_223 ( V_369 . V_372 ) ;
V_14 -> V_108 = F_223 ( V_369 . V_373 ) ;
V_14 -> V_110 =
F_223 ( V_369 . V_374 ) ;
}
break;
case V_120 :
V_14 -> V_429 = F_222 ( V_386 . V_392 ) ;
}
}
V_220 -> V_6 = F_14 ( V_14 -> V_6 ) ;
V_220 -> V_83 = F_76 ( 0 ) ;
return V_362 - V_151 ;
}
static int F_225 ( struct V_1 * V_14 , void * V_151 , T_1 V_128 , T_1 V_83 )
{
struct V_400 * V_127 = V_151 ;
void * V_362 = V_127 -> V_151 ;
F_19 ( L_3 , V_14 ) ;
V_127 -> V_7 = F_14 ( V_14 -> V_6 ) ;
V_127 -> V_128 = F_14 ( V_128 ) ;
V_127 -> V_83 = F_14 ( V_83 ) ;
return V_362 - V_151 ;
}
void F_226 ( struct V_1 * V_14 )
{
struct V_126 V_127 ;
struct V_2 * V_3 = V_14 -> V_3 ;
T_2 V_243 [ 128 ] ;
V_127 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_127 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_127 . V_128 = F_76 ( V_248 ) ;
V_127 . V_133 = F_76 ( V_134 ) ;
F_77 ( V_3 , V_14 -> V_9 ,
V_135 , sizeof( V_127 ) , & V_127 ) ;
if ( F_227 ( V_250 , & V_14 -> V_71 ) )
return;
F_77 ( V_3 , F_81 ( V_3 ) , V_251 ,
F_118 ( V_14 , V_243 ) , V_243 ) ;
V_14 -> V_252 ++ ;
}
static void F_228 ( struct V_1 * V_14 , void * V_127 , int V_150 )
{
int type , V_363 ;
unsigned long V_364 ;
T_1 V_430 = V_14 -> V_80 ;
struct V_385 V_386 = {
. V_114 = V_14 -> V_114 ,
. V_29 = F_76 ( V_420 ) ,
. V_31 = F_76 ( V_421 ) ,
. V_392 = F_14 ( V_14 -> V_98 ) ,
. V_390 = F_186 ( T_1 , V_14 -> V_80 , V_78 ) ,
} ;
F_19 ( L_42 , V_14 , V_127 , V_150 ) ;
if ( ( V_14 -> V_114 != V_116 ) && ( V_14 -> V_114 != V_120 ) )
return;
while ( V_150 >= V_367 ) {
V_150 -= F_209 ( & V_127 , & type , & V_363 , & V_364 ) ;
switch ( type ) {
case V_393 :
if ( V_363 == sizeof( V_386 ) )
memcpy ( & V_386 , ( void * ) V_364 , V_363 ) ;
break;
case V_399 :
V_430 = V_364 ;
break;
}
}
switch ( V_386 . V_114 ) {
case V_116 :
V_14 -> V_29 = F_222 ( V_386 . V_29 ) ;
V_14 -> V_31 = F_222 ( V_386 . V_31 ) ;
V_14 -> V_429 = F_222 ( V_386 . V_392 ) ;
if ( F_70 ( V_197 , & V_14 -> V_83 ) )
V_14 -> V_80 = F_186 ( T_1 , V_14 -> V_80 , V_430 ) ;
else
V_14 -> V_80 = F_186 ( T_1 , V_14 -> V_80 ,
V_386 . V_390 ) ;
break;
case V_120 :
V_14 -> V_429 = F_222 ( V_386 . V_392 ) ;
}
}
static inline int F_229 ( struct V_2 * V_3 , struct V_357 * V_358 , T_2 * V_151 )
{
struct V_431 * V_432 = (struct V_431 * ) V_151 ;
if ( V_432 -> V_55 != V_433 )
return 0 ;
if ( ( V_3 -> V_223 & V_224 ) &&
V_358 -> V_9 == V_3 -> V_228 ) {
F_230 ( & V_3 -> V_229 ) ;
V_3 -> V_223 |= V_225 ;
V_3 -> V_228 = 0 ;
F_116 ( V_3 ) ;
}
return 0 ;
}
static inline int F_231 ( struct V_2 * V_3 , struct V_357 * V_358 , T_2 * V_151 )
{
struct V_219 * V_220 = (struct V_219 * ) V_151 ;
struct V_126 V_127 ;
struct V_1 * V_14 = NULL , * V_260 ;
struct V_26 * V_244 , * V_13 = NULL ;
int V_128 , V_133 = V_134 ;
T_1 V_6 = 0 , V_7 = F_65 ( V_220 -> V_7 ) ;
T_3 V_10 = V_220 -> V_10 ;
F_19 ( L_43 , F_65 ( V_10 ) , V_7 ) ;
V_260 = F_140 ( V_122 , V_10 , V_3 -> V_11 , V_3 -> V_253 ) ;
if ( ! V_260 ) {
V_128 = V_131 ;
goto V_434;
}
V_244 = V_260 -> V_13 ;
F_5 ( & V_3 -> V_8 ) ;
F_22 ( V_244 ) ;
if ( V_10 != F_76 ( V_142 ) &&
! F_232 ( V_3 -> V_88 ) ) {
V_3 -> V_84 = V_435 ;
V_128 = V_130 ;
goto V_436;
}
V_128 = V_437 ;
if ( F_1 ( V_3 , V_7 ) )
goto V_436;
V_14 = V_260 -> V_24 -> V_261 ( V_260 ) ;
if ( ! V_14 )
goto V_436;
V_13 = V_14 -> V_13 ;
F_123 ( V_3 -> V_88 ) ;
F_124 ( & F_11 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_124 ( & F_11 ( V_13 ) -> V_253 , V_3 -> V_253 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_7 ;
F_125 ( V_244 , V_13 ) ;
F_64 ( V_3 , V_14 ) ;
V_6 = V_14 -> V_7 ;
F_74 ( V_14 , V_13 -> V_124 ) ;
V_14 -> V_9 = V_358 -> V_9 ;
if ( V_3 -> V_223 & V_225 ) {
if ( F_79 ( V_14 ) ) {
if ( F_70 ( V_129 , & F_11 ( V_13 ) -> V_83 ) ) {
F_18 ( V_14 , V_125 ) ;
V_128 = V_245 ;
V_133 = V_246 ;
V_244 -> V_247 ( V_244 , 0 ) ;
} else {
F_18 ( V_14 , V_57 ) ;
V_128 = V_248 ;
V_133 = V_134 ;
}
} else {
F_18 ( V_14 , V_125 ) ;
V_128 = V_245 ;
V_133 = V_249 ;
}
} else {
F_18 ( V_14 , V_125 ) ;
V_128 = V_245 ;
V_133 = V_134 ;
}
V_436:
F_23 ( V_244 ) ;
F_7 ( & V_3 -> V_8 ) ;
V_434:
V_127 . V_7 = F_14 ( V_7 ) ;
V_127 . V_6 = F_14 ( V_6 ) ;
V_127 . V_128 = F_14 ( V_128 ) ;
V_127 . V_133 = F_14 ( V_133 ) ;
F_77 ( V_3 , V_358 -> V_9 , V_135 , sizeof( V_127 ) , & V_127 ) ;
if ( V_128 == V_245 && V_133 == V_134 ) {
struct V_226 V_438 ;
V_438 . type = F_76 ( V_227 ) ;
V_3 -> V_223 |= V_224 ;
V_3 -> V_228 = F_81 ( V_3 ) ;
F_114 ( & V_3 -> V_229 , V_230 ) ;
F_77 ( V_3 , V_3 -> V_228 ,
V_231 , sizeof( V_438 ) , & V_438 ) ;
}
if ( V_14 && ! F_70 ( V_250 , & V_14 -> V_71 ) &&
V_128 == V_248 ) {
T_2 V_243 [ 128 ] ;
F_56 ( V_250 , & V_14 -> V_71 ) ;
F_77 ( V_3 , F_81 ( V_3 ) , V_251 ,
F_118 ( V_14 , V_243 ) , V_243 ) ;
V_14 -> V_252 ++ ;
}
return 0 ;
}
static inline int F_233 ( struct V_2 * V_3 , struct V_357 * V_358 , T_2 * V_151 )
{
struct V_126 * V_127 = (struct V_126 * ) V_151 ;
T_1 V_7 , V_6 , V_128 , V_133 ;
struct V_1 * V_14 ;
T_2 V_220 [ 128 ] ;
int V_15 ;
V_7 = F_65 ( V_127 -> V_7 ) ;
V_6 = F_65 ( V_127 -> V_6 ) ;
V_128 = F_65 ( V_127 -> V_128 ) ;
V_133 = F_65 ( V_127 -> V_133 ) ;
F_19 ( L_44 ,
V_6 , V_7 , V_128 , V_133 ) ;
F_5 ( & V_3 -> V_8 ) ;
if ( V_7 ) {
V_14 = F_3 ( V_3 , V_7 ) ;
if ( ! V_14 ) {
V_15 = - V_317 ;
goto V_439;
}
} else {
V_14 = F_8 ( V_3 , V_358 -> V_9 ) ;
if ( ! V_14 ) {
V_15 = - V_317 ;
goto V_439;
}
}
V_15 = 0 ;
F_6 ( V_14 ) ;
switch ( V_128 ) {
case V_248 :
F_21 ( V_14 , V_57 ) ;
V_14 -> V_9 = 0 ;
V_14 -> V_6 = V_6 ;
F_107 ( V_218 , & V_14 -> V_71 ) ;
if ( F_227 ( V_250 , & V_14 -> V_71 ) )
break;
F_77 ( V_3 , F_81 ( V_3 ) , V_251 ,
F_118 ( V_14 , V_220 ) , V_220 ) ;
V_14 -> V_252 ++ ;
break;
case V_245 :
F_56 ( V_218 , & V_14 -> V_71 ) ;
break;
default:
F_67 ( V_14 , V_58 ) ;
break;
}
F_48 ( V_14 ) ;
V_439:
F_7 ( & V_3 -> V_8 ) ;
return V_15 ;
}
static inline void F_234 ( struct V_1 * V_14 )
{
if ( V_14 -> V_114 != V_116 && V_14 -> V_114 != V_120 )
V_14 -> V_73 = V_396 ;
else if ( ! F_70 ( V_397 , & V_14 -> V_71 ) )
V_14 -> V_73 = V_74 ;
}
static inline int F_235 ( struct V_2 * V_3 , struct V_357 * V_358 , T_1 V_440 , T_2 * V_151 )
{
struct V_384 * V_220 = (struct V_384 * ) V_151 ;
T_1 V_6 , V_83 ;
T_2 V_127 [ 64 ] ;
struct V_1 * V_14 ;
int V_150 , V_15 = 0 ;
V_6 = F_65 ( V_220 -> V_6 ) ;
V_83 = F_65 ( V_220 -> V_83 ) ;
F_19 ( L_45 , V_6 , V_83 ) ;
V_14 = F_4 ( V_3 , V_6 ) ;
if ( ! V_14 )
return - V_441 ;
if ( V_14 -> V_23 != V_57 && V_14 -> V_23 != V_125 ) {
struct V_442 V_432 ;
V_432 . V_55 = F_76 ( V_443 ) ;
V_432 . V_7 = F_14 ( V_14 -> V_7 ) ;
V_432 . V_6 = F_14 ( V_14 -> V_6 ) ;
F_77 ( V_3 , V_358 -> V_9 , V_444 ,
sizeof( V_432 ) , & V_432 ) ;
goto V_439;
}
V_150 = V_440 - sizeof( * V_220 ) ;
if ( V_150 < 0 || V_14 -> V_402 + V_150 > sizeof( V_14 -> V_401 ) ) {
F_77 ( V_3 , V_358 -> V_9 , V_445 ,
F_225 ( V_14 , V_127 ,
V_446 , V_83 ) , V_127 ) ;
goto V_439;
}
memcpy ( V_14 -> V_401 + V_14 -> V_402 , V_220 -> V_151 , V_150 ) ;
V_14 -> V_402 += V_150 ;
if ( V_83 & V_447 ) {
F_77 ( V_3 , V_358 -> V_9 , V_445 ,
F_225 ( V_14 , V_127 ,
V_405 , V_83 ) , V_127 ) ;
goto V_439;
}
V_150 = F_221 ( V_14 , V_127 ) ;
if ( V_150 < 0 ) {
F_75 ( V_3 , V_14 , V_242 ) ;
goto V_439;
}
F_77 ( V_3 , V_358 -> V_9 , V_445 , V_150 , V_127 ) ;
V_14 -> V_387 ++ ;
V_14 -> V_402 = 0 ;
if ( ! F_70 ( V_428 , & V_14 -> V_71 ) )
goto V_439;
if ( F_70 ( V_448 , & V_14 -> V_71 ) ) {
F_234 ( V_14 ) ;
if ( V_14 -> V_114 == V_116 ||
V_14 -> V_114 == V_120 )
V_15 = F_215 ( V_14 ) ;
if ( V_15 < 0 )
F_75 ( V_14 -> V_3 , V_14 , - V_15 ) ;
else
F_112 ( V_14 ) ;
goto V_439;
}
if ( ! F_227 ( V_250 , & V_14 -> V_71 ) ) {
T_2 V_243 [ 64 ] ;
F_77 ( V_3 , F_81 ( V_3 ) , V_251 ,
F_118 ( V_14 , V_243 ) , V_243 ) ;
V_14 -> V_252 ++ ;
}
if ( F_70 ( V_449 , & V_14 -> V_71 ) &&
F_70 ( V_417 , & V_14 -> V_71 ) ) {
F_107 ( V_417 , & V_14 -> V_71 ) ;
F_56 ( V_428 , & V_14 -> V_71 ) ;
F_77 ( V_3 , V_358 -> V_9 , V_445 ,
F_225 ( V_14 , V_127 ,
V_405 , V_83 ) , V_127 ) ;
}
V_439:
F_48 ( V_14 ) ;
return V_15 ;
}
static inline int F_236 ( struct V_2 * V_3 , struct V_357 * V_358 , T_2 * V_151 )
{
struct V_400 * V_127 = (struct V_400 * ) V_151 ;
T_1 V_7 , V_83 , V_128 ;
struct V_1 * V_14 ;
int V_150 = F_222 ( V_358 -> V_150 ) - sizeof( * V_127 ) ;
int V_15 = 0 ;
V_7 = F_65 ( V_127 -> V_7 ) ;
V_83 = F_65 ( V_127 -> V_83 ) ;
V_128 = F_65 ( V_127 -> V_128 ) ;
F_19 ( L_46 , V_7 , V_83 ,
V_128 , V_150 ) ;
V_14 = F_4 ( V_3 , V_7 ) ;
if ( ! V_14 )
return 0 ;
switch ( V_128 ) {
case V_405 :
F_228 ( V_14 , V_127 -> V_151 , V_150 ) ;
F_107 ( V_449 , & V_14 -> V_71 ) ;
break;
case V_416 :
F_56 ( V_449 , & V_14 -> V_71 ) ;
if ( F_70 ( V_417 , & V_14 -> V_71 ) ) {
char V_243 [ 64 ] ;
V_150 = F_224 ( V_14 , V_127 -> V_151 , V_150 ,
V_243 , & V_128 ) ;
if ( V_150 < 0 ) {
F_75 ( V_3 , V_14 , V_242 ) ;
goto V_18;
}
F_107 ( V_417 , & V_14 -> V_71 ) ;
F_56 ( V_428 , & V_14 -> V_71 ) ;
F_77 ( V_3 , V_358 -> V_9 , V_445 ,
F_225 ( V_14 , V_243 ,
V_405 , 0x0000 ) , V_243 ) ;
}
goto V_18;
case V_412 :
if ( V_14 -> V_387 <= V_450 ) {
char V_220 [ 64 ] ;
if ( V_150 > sizeof( V_220 ) - sizeof( struct V_384 ) ) {
F_75 ( V_3 , V_14 , V_242 ) ;
goto V_18;
}
V_128 = V_405 ;
V_150 = F_224 ( V_14 , V_127 -> V_151 , V_150 ,
V_220 , & V_128 ) ;
if ( V_150 < 0 ) {
F_75 ( V_3 , V_14 , V_242 ) ;
goto V_18;
}
F_77 ( V_3 , F_81 ( V_3 ) ,
V_251 , V_150 , V_220 ) ;
V_14 -> V_252 ++ ;
if ( V_128 != V_405 )
goto V_18;
break;
}
default:
F_25 ( V_14 , V_242 ) ;
F_74 ( V_14 , V_451 ) ;
F_75 ( V_3 , V_14 , V_242 ) ;
goto V_18;
}
if ( V_83 & V_447 )
goto V_18;
F_56 ( V_448 , & V_14 -> V_71 ) ;
if ( F_70 ( V_428 , & V_14 -> V_71 ) ) {
F_234 ( V_14 ) ;
if ( V_14 -> V_114 == V_116 ||
V_14 -> V_114 == V_120 )
V_15 = F_215 ( V_14 ) ;
if ( V_15 < 0 )
F_75 ( V_14 -> V_3 , V_14 , - V_15 ) ;
else
F_112 ( V_14 ) ;
}
V_18:
F_48 ( V_14 ) ;
return V_15 ;
}
static inline int F_237 ( struct V_2 * V_3 , struct V_357 * V_358 , T_2 * V_151 )
{
struct V_238 * V_220 = (struct V_238 * ) V_151 ;
struct V_452 V_127 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
struct V_26 * V_13 ;
V_7 = F_65 ( V_220 -> V_7 ) ;
V_6 = F_65 ( V_220 -> V_6 ) ;
F_19 ( L_47 , V_7 , V_6 ) ;
F_5 ( & V_3 -> V_8 ) ;
V_14 = F_3 ( V_3 , V_6 ) ;
if ( ! V_14 ) {
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
F_6 ( V_14 ) ;
V_13 = V_14 -> V_13 ;
V_127 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_127 . V_7 = F_14 ( V_14 -> V_6 ) ;
F_77 ( V_3 , V_358 -> V_9 , V_453 , sizeof( V_127 ) , & V_127 ) ;
F_22 ( V_13 ) ;
V_13 -> V_454 = V_455 ;
F_23 ( V_13 ) ;
F_59 ( V_14 ) ;
F_67 ( V_14 , V_242 ) ;
F_48 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_49 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_238 ( struct V_2 * V_3 , struct V_357 * V_358 , T_2 * V_151 )
{
struct V_452 * V_127 = (struct V_452 * ) V_151 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
V_7 = F_65 ( V_127 -> V_7 ) ;
V_6 = F_65 ( V_127 -> V_6 ) ;
F_19 ( L_48 , V_6 , V_7 ) ;
F_5 ( & V_3 -> V_8 ) ;
V_14 = F_3 ( V_3 , V_7 ) ;
if ( ! V_14 ) {
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
F_6 ( V_14 ) ;
F_59 ( V_14 ) ;
F_67 ( V_14 , 0 ) ;
F_48 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_49 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_239 ( struct V_2 * V_3 , struct V_357 * V_358 , T_2 * V_151 )
{
struct V_226 * V_220 = (struct V_226 * ) V_151 ;
T_1 type ;
type = F_65 ( V_220 -> type ) ;
F_19 ( L_49 , type ) ;
if ( type == V_227 ) {
T_2 V_243 [ 8 ] ;
T_8 V_232 = V_234 ;
struct V_456 * V_127 = (struct V_456 * ) V_243 ;
V_127 -> type = F_76 ( V_227 ) ;
V_127 -> V_128 = F_76 ( V_457 ) ;
if ( ! V_235 )
V_232 |= V_236 | V_237
| V_395 ;
if ( V_380 )
V_232 |= V_382
| V_381 ;
F_97 ( V_232 , V_127 -> V_151 ) ;
F_77 ( V_3 , V_358 -> V_9 ,
V_458 , sizeof( V_243 ) , V_243 ) ;
} else if ( type == V_459 ) {
T_2 V_243 [ 12 ] ;
struct V_456 * V_127 = (struct V_456 * ) V_243 ;
if ( V_380 )
V_460 [ 0 ] |= V_461 ;
else
V_460 [ 0 ] &= ~ V_461 ;
V_127 -> type = F_76 ( V_459 ) ;
V_127 -> V_128 = F_76 ( V_457 ) ;
memcpy ( V_127 -> V_151 , V_460 , sizeof( V_460 ) ) ;
F_77 ( V_3 , V_358 -> V_9 ,
V_458 , sizeof( V_243 ) , V_243 ) ;
} else {
struct V_456 V_127 ;
V_127 . type = F_14 ( type ) ;
V_127 . V_128 = F_76 ( V_462 ) ;
F_77 ( V_3 , V_358 -> V_9 ,
V_458 , sizeof( V_127 ) , & V_127 ) ;
}
return 0 ;
}
static inline int F_240 ( struct V_2 * V_3 , struct V_357 * V_358 , T_2 * V_151 )
{
struct V_456 * V_127 = (struct V_456 * ) V_151 ;
T_1 type , V_128 ;
type = F_65 ( V_127 -> type ) ;
V_128 = F_65 ( V_127 -> V_128 ) ;
F_19 ( L_50 , type , V_128 ) ;
if ( V_358 -> V_9 != V_3 -> V_228 ||
V_3 -> V_223 & V_225 )
return 0 ;
F_230 ( & V_3 -> V_229 ) ;
if ( V_128 != V_457 ) {
V_3 -> V_223 |= V_225 ;
V_3 -> V_228 = 0 ;
F_116 ( V_3 ) ;
return 0 ;
}
switch ( type ) {
case V_227 :
V_3 -> V_232 = F_91 ( V_127 -> V_151 ) ;
if ( V_3 -> V_232 & V_463 ) {
struct V_226 V_220 ;
V_220 . type = F_76 ( V_459 ) ;
V_3 -> V_228 = F_81 ( V_3 ) ;
F_77 ( V_3 , V_3 -> V_228 ,
V_231 , sizeof( V_220 ) , & V_220 ) ;
} else {
V_3 -> V_223 |= V_225 ;
V_3 -> V_228 = 0 ;
F_116 ( V_3 ) ;
}
break;
case V_459 :
V_3 -> V_464 = V_127 -> V_151 [ 0 ] ;
V_3 -> V_223 |= V_225 ;
V_3 -> V_228 = 0 ;
F_116 ( V_3 ) ;
break;
}
return 0 ;
}
static inline int F_241 ( struct V_2 * V_3 ,
struct V_357 * V_358 , T_1 V_440 ,
void * V_151 )
{
struct V_465 * V_220 = V_151 ;
struct V_466 V_127 ;
T_1 V_10 , V_7 ;
if ( V_440 != sizeof( * V_220 ) )
return - V_467 ;
if ( ! V_380 )
return - V_20 ;
V_10 = F_222 ( V_220 -> V_10 ) ;
V_7 = F_222 ( V_220 -> V_7 ) ;
F_19 ( L_51 , V_10 , V_7 , V_220 -> V_468 ) ;
V_127 . V_6 = 0 ;
V_127 . V_7 = F_14 ( V_7 ) ;
V_127 . V_128 = F_76 ( V_437 ) ;
V_127 . V_133 = F_76 ( V_134 ) ;
F_77 ( V_3 , V_358 -> V_9 , V_469 ,
sizeof( V_127 ) , & V_127 ) ;
return 0 ;
}
static inline int F_242 ( struct V_2 * V_3 ,
struct V_357 * V_358 , void * V_151 )
{
F_19 ( L_13 , V_3 ) ;
return F_233 ( V_3 , V_358 , V_151 ) ;
}
static void F_243 ( struct V_2 * V_3 , T_2 V_9 ,
T_1 V_470 , T_1 V_128 )
{
struct V_471 V_127 ;
F_19 ( L_52 , V_470 , V_128 ) ;
V_127 . V_470 = F_14 ( V_470 ) ;
V_127 . V_128 = F_14 ( V_128 ) ;
F_77 ( V_3 , V_9 , V_472 , sizeof( V_127 ) , & V_127 ) ;
}
static void F_244 ( struct V_2 * V_3 ,
struct V_1 * V_14 ,
T_1 V_470 , T_1 V_128 )
{
struct V_473 V_474 ;
T_2 V_9 ;
F_19 ( L_52 , V_470 , V_128 ) ;
V_9 = F_81 ( V_3 ) ;
if ( V_14 )
V_14 -> V_9 = V_9 ;
V_474 . V_470 = F_14 ( V_470 ) ;
V_474 . V_128 = F_14 ( V_128 ) ;
F_77 ( V_3 , V_9 , V_475 , sizeof( V_474 ) , & V_474 ) ;
}
static void F_245 ( struct V_2 * V_3 , T_2 V_9 ,
T_1 V_470 )
{
struct V_476 V_127 ;
F_19 ( L_53 , V_470 ) ;
V_127 . V_470 = F_14 ( V_470 ) ;
F_77 ( V_3 , V_9 , V_477 , sizeof( V_127 ) , & V_127 ) ;
}
static inline int F_246 ( struct V_2 * V_3 ,
struct V_357 * V_358 ,
T_1 V_440 , void * V_151 )
{
struct V_478 * V_220 = V_151 ;
T_1 V_470 = 0 ;
T_1 V_128 = V_479 ;
if ( V_440 != sizeof( * V_220 ) )
return - V_467 ;
V_470 = F_222 ( V_220 -> V_470 ) ;
F_19 ( L_54 , V_470 , V_220 -> V_480 ) ;
if ( ! V_380 )
return - V_20 ;
F_243 ( V_3 , V_358 -> V_9 , V_470 , V_128 ) ;
return 0 ;
}
static inline int F_247 ( struct V_2 * V_3 ,
struct V_357 * V_358 ,
T_1 V_440 , void * V_151 )
{
struct V_471 * V_127 = V_151 ;
T_1 V_470 , V_128 ;
if ( V_440 != sizeof( * V_127 ) )
return - V_467 ;
V_470 = F_222 ( V_127 -> V_470 ) ;
V_128 = F_222 ( V_127 -> V_128 ) ;
F_19 ( L_52 , V_470 , V_128 ) ;
F_244 ( V_3 , NULL , V_470 , V_481 ) ;
return 0 ;
}
static inline int F_248 ( struct V_2 * V_3 ,
struct V_357 * V_358 ,
T_1 V_440 , void * V_151 )
{
struct V_473 * V_474 = V_151 ;
T_1 V_470 , V_128 ;
if ( V_440 != sizeof( * V_474 ) )
return - V_467 ;
V_470 = F_222 ( V_474 -> V_470 ) ;
V_128 = F_222 ( V_474 -> V_128 ) ;
F_19 ( L_52 , V_470 , V_128 ) ;
F_245 ( V_3 , V_358 -> V_9 , V_470 ) ;
return 0 ;
}
static inline int F_249 ( struct V_2 * V_3 ,
struct V_357 * V_358 ,
T_1 V_440 , void * V_151 )
{
struct V_476 * V_127 = V_151 ;
T_1 V_470 ;
if ( V_440 != sizeof( * V_127 ) )
return - V_467 ;
V_470 = F_222 ( V_127 -> V_470 ) ;
F_19 ( L_53 , V_470 ) ;
return 0 ;
}
static inline int F_250 ( T_1 V_482 , T_1 V_483 , T_1 V_484 ,
T_1 V_485 )
{
T_1 V_486 ;
if ( V_482 > V_483 || V_482 < 6 || V_483 > 3200 )
return - V_20 ;
if ( V_485 < 10 || V_485 > 3200 )
return - V_20 ;
if ( V_483 >= V_485 * 8 )
return - V_20 ;
V_486 = ( V_485 * 8 / V_483 ) - 1 ;
if ( V_484 > 499 || V_484 > V_486 )
return - V_20 ;
return 0 ;
}
static inline int F_251 ( struct V_2 * V_3 ,
struct V_357 * V_358 , T_2 * V_151 )
{
struct V_160 * V_88 = V_3 -> V_88 ;
struct F_251 * V_220 ;
struct V_487 V_127 ;
T_1 V_482 , V_483 , V_484 , V_485 , V_440 ;
int V_15 ;
if ( ! ( V_88 -> V_488 & V_489 ) )
return - V_20 ;
V_440 = F_65 ( V_358 -> V_150 ) ;
if ( V_440 != sizeof( struct F_251 ) )
return - V_467 ;
V_220 = (struct F_251 * ) V_151 ;
V_482 = F_65 ( V_220 -> V_482 ) ;
V_483 = F_65 ( V_220 -> V_483 ) ;
V_484 = F_65 ( V_220 -> V_484 ) ;
V_485 = F_65 ( V_220 -> V_485 ) ;
F_19 ( L_55 ,
V_482 , V_483 , V_484 , V_485 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_15 = F_250 ( V_482 , V_483 , V_484 , V_485 ) ;
if ( V_15 )
V_127 . V_128 = F_76 ( V_490 ) ;
else
V_127 . V_128 = F_76 ( V_491 ) ;
F_77 ( V_3 , V_358 -> V_9 , V_492 ,
sizeof( V_127 ) , & V_127 ) ;
if ( ! V_15 )
F_252 ( V_88 , V_482 , V_483 , V_484 , V_485 ) ;
return 0 ;
}
static inline int F_253 ( struct V_2 * V_3 ,
struct V_357 * V_358 , T_1 V_440 , T_2 * V_151 )
{
int V_15 = 0 ;
switch ( V_358 -> V_149 ) {
case V_444 :
F_229 ( V_3 , V_358 , V_151 ) ;
break;
case V_221 :
V_15 = F_231 ( V_3 , V_358 , V_151 ) ;
break;
case V_135 :
V_15 = F_233 ( V_3 , V_358 , V_151 ) ;
break;
case V_251 :
V_15 = F_235 ( V_3 , V_358 , V_440 , V_151 ) ;
break;
case V_445 :
V_15 = F_236 ( V_3 , V_358 , V_151 ) ;
break;
case V_239 :
V_15 = F_237 ( V_3 , V_358 , V_151 ) ;
break;
case V_453 :
V_15 = F_238 ( V_3 , V_358 , V_151 ) ;
break;
case V_493 :
F_77 ( V_3 , V_358 -> V_9 , V_494 , V_440 , V_151 ) ;
break;
case V_494 :
break;
case V_231 :
V_15 = F_239 ( V_3 , V_358 , V_151 ) ;
break;
case V_458 :
V_15 = F_240 ( V_3 , V_358 , V_151 ) ;
break;
case V_495 :
V_15 = F_241 ( V_3 , V_358 , V_440 , V_151 ) ;
break;
case V_469 :
V_15 = F_242 ( V_3 , V_358 , V_151 ) ;
break;
case V_496 :
V_15 = F_246 ( V_3 , V_358 , V_440 , V_151 ) ;
break;
case V_472 :
V_15 = F_247 ( V_3 , V_358 , V_440 , V_151 ) ;
break;
case V_475 :
V_15 = F_248 ( V_3 , V_358 , V_440 , V_151 ) ;
break;
case V_477 :
V_15 = F_249 ( V_3 , V_358 , V_440 , V_151 ) ;
break;
default:
F_254 ( L_56 , V_358 -> V_149 ) ;
V_15 = - V_20 ;
break;
}
return V_15 ;
}
static inline int F_255 ( struct V_2 * V_3 ,
struct V_357 * V_358 , T_2 * V_151 )
{
switch ( V_358 -> V_149 ) {
case V_444 :
return 0 ;
case V_497 :
return F_251 ( V_3 , V_358 , V_151 ) ;
case V_492 :
return 0 ;
default:
F_254 ( L_57 , V_358 -> V_149 ) ;
return - V_20 ;
}
}
static inline void F_256 ( struct V_2 * V_3 ,
struct V_32 * V_36 )
{
T_2 * V_151 = V_36 -> V_151 ;
int V_150 = V_36 -> V_150 ;
struct V_357 V_358 ;
int V_15 ;
F_208 ( V_3 , V_36 ) ;
while ( V_150 >= V_359 ) {
T_1 V_440 ;
memcpy ( & V_358 , V_151 , V_359 ) ;
V_151 += V_359 ;
V_150 -= V_359 ;
V_440 = F_222 ( V_358 . V_150 ) ;
F_19 ( L_58 , V_358 . V_149 , V_440 , V_358 . V_9 ) ;
if ( V_440 > V_150 || ! V_358 . V_9 ) {
F_19 ( L_59 ) ;
break;
}
if ( V_3 -> V_88 -> type == V_89 )
V_15 = F_255 ( V_3 , & V_358 , V_151 ) ;
else
V_15 = F_253 ( V_3 , & V_358 , V_440 , V_151 ) ;
if ( V_15 ) {
struct V_431 V_432 ;
F_254 ( L_60 , V_15 ) ;
V_432 . V_55 = F_76 ( V_433 ) ;
F_77 ( V_3 , V_358 . V_9 , V_444 , sizeof( V_432 ) , & V_432 ) ;
}
V_151 += V_440 ;
V_150 -= V_440 ;
}
F_131 ( V_36 ) ;
}
static int F_257 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
T_1 V_498 , V_499 ;
int V_500 ;
if ( F_70 ( V_197 , & V_14 -> V_83 ) )
V_500 = V_202 ;
else
V_500 = V_203 ;
if ( V_14 -> V_73 == V_74 ) {
F_258 ( V_36 , V_36 -> V_150 - V_207 ) ;
V_499 = F_93 ( V_36 -> V_151 + V_36 -> V_150 ) ;
V_498 = F_104 ( 0 , V_36 -> V_151 - V_500 , V_36 -> V_150 + V_500 ) ;
if ( V_498 != V_499 )
return - V_501 ;
}
return 0 ;
}
static void F_259 ( struct V_1 * V_14 )
{
struct V_163 V_37 ;
F_19 ( L_3 , V_14 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_171 = 1 ;
V_37 . V_167 = 1 ;
V_37 . V_164 = V_14 -> V_217 ;
F_56 ( V_209 , & V_14 -> V_210 ) ;
if ( F_70 ( V_216 , & V_14 -> V_210 ) ) {
V_37 . V_175 = V_213 ;
F_105 ( V_14 , & V_37 ) ;
}
if ( F_106 ( V_303 , & V_14 -> V_210 ) &&
V_14 -> V_292 > 0 )
F_26 ( V_14 ) ;
F_169 ( V_14 ) ;
if ( ! F_70 ( V_216 , & V_14 -> V_210 ) &&
F_70 ( V_209 , & V_14 -> V_210 ) ) {
V_37 . V_175 = V_211 ;
F_105 ( V_14 , & V_37 ) ;
}
}
static void F_260 ( struct V_32 * V_36 ,
struct V_32 * V_502 , struct V_32 * * V_503 )
{
if ( ! F_261 ( V_36 ) )
F_185 ( V_36 ) -> V_318 = V_502 ;
V_502 -> V_323 = NULL ;
( * V_503 ) -> V_323 = V_502 ;
* V_503 = V_502 ;
V_36 -> V_150 += V_502 -> V_150 ;
V_36 -> V_322 += V_502 -> V_150 ;
V_36 -> V_504 += V_502 -> V_504 ;
}
static int F_262 ( struct V_1 * V_14 , struct V_32 * V_36 ,
struct V_163 * V_37 )
{
int V_15 = - V_20 ;
switch ( V_37 -> V_178 ) {
case V_332 :
if ( V_14 -> V_377 )
break;
V_15 = V_14 -> V_24 -> V_355 ( V_14 , V_36 ) ;
break;
case V_333 :
if ( V_14 -> V_377 )
break;
V_14 -> V_328 = F_93 ( V_36 -> V_151 ) ;
F_92 ( V_36 , V_326 ) ;
if ( V_14 -> V_328 > V_14 -> V_98 ) {
V_15 = - V_336 ;
break;
}
if ( V_36 -> V_150 >= V_14 -> V_328 )
break;
V_14 -> V_377 = V_36 ;
V_14 -> V_378 = V_36 ;
V_36 = NULL ;
V_15 = 0 ;
break;
case V_335 :
if ( ! V_14 -> V_377 )
break;
F_260 ( V_14 -> V_377 , V_36 ,
& V_14 -> V_378 ) ;
V_36 = NULL ;
if ( V_14 -> V_377 -> V_150 >= V_14 -> V_328 )
break;
V_15 = 0 ;
break;
case V_334 :
if ( ! V_14 -> V_377 )
break;
F_260 ( V_14 -> V_377 , V_36 ,
& V_14 -> V_378 ) ;
V_36 = NULL ;
if ( V_14 -> V_377 -> V_150 != V_14 -> V_328 )
break;
V_15 = V_14 -> V_24 -> V_355 ( V_14 , V_14 -> V_377 ) ;
if ( ! V_15 ) {
V_14 -> V_377 = NULL ;
V_14 -> V_378 = NULL ;
V_14 -> V_328 = 0 ;
}
break;
}
if ( V_15 ) {
F_131 ( V_36 ) ;
F_131 ( V_14 -> V_377 ) ;
V_14 -> V_377 = NULL ;
V_14 -> V_378 = NULL ;
V_14 -> V_328 = 0 ;
}
return V_15 ;
}
void F_263 ( struct V_1 * V_14 , int V_505 )
{
T_2 V_343 ;
if ( V_14 -> V_114 != V_116 )
return;
V_343 = V_505 ? V_344 : V_346 ;
F_162 ( V_14 , NULL , NULL , V_343 ) ;
}
static int F_264 ( struct V_1 * V_14 )
{
int V_15 = 0 ;
F_19 ( L_3 , V_14 ) ;
while ( ! F_70 ( V_216 , & V_14 -> V_210 ) ) {
struct V_32 * V_36 ;
F_19 ( L_61 ,
V_14 -> V_217 , F_173 ( & V_14 -> V_117 ) ) ;
V_36 = F_32 ( & V_14 -> V_117 , V_14 -> V_217 ) ;
if ( ! V_36 )
break;
F_201 ( V_36 , & V_14 -> V_117 ) ;
V_14 -> V_217 = F_168 ( V_14 , V_14 -> V_217 ) ;
V_15 = F_262 ( V_14 , V_36 , & F_34 ( V_36 ) -> V_37 ) ;
if ( V_15 )
break;
}
if ( F_166 ( & V_14 -> V_117 ) ) {
V_14 -> V_310 = V_311 ;
F_180 ( V_14 ) ;
}
return V_15 ;
}
static void F_265 ( struct V_1 * V_14 ,
struct V_163 * V_37 )
{
struct V_32 * V_36 ;
F_19 ( L_10 , V_14 , V_37 ) ;
if ( V_37 -> V_164 == V_14 -> V_298 ) {
F_19 ( L_62 , V_37 -> V_164 ) ;
F_75 ( V_14 -> V_3 , V_14 , V_242 ) ;
return;
}
V_36 = F_32 ( & V_14 -> V_121 , V_37 -> V_164 ) ;
if ( V_36 == NULL ) {
F_19 ( L_63 ,
V_37 -> V_164 ) ;
return;
}
if ( V_14 -> V_75 != 0 && F_34 ( V_36 ) -> V_37 . V_297 >= V_14 -> V_75 ) {
F_19 ( L_22 , V_14 -> V_75 ) ;
F_75 ( V_14 -> V_3 , V_14 , V_242 ) ;
return;
}
F_107 ( V_303 , & V_14 -> V_210 ) ;
if ( V_37 -> V_172 ) {
F_206 ( V_14 , V_37 ) ;
F_56 ( V_209 , & V_14 -> V_210 ) ;
F_177 ( V_14 , V_37 ) ;
F_169 ( V_14 ) ;
if ( V_14 -> V_306 == V_349 ) {
F_56 ( V_506 , & V_14 -> V_210 ) ;
V_14 -> V_507 = V_37 -> V_164 ;
}
} else {
F_207 ( V_14 , V_37 ) ;
if ( V_37 -> V_167 ) {
if ( V_14 -> V_507 != V_37 -> V_164 ||
! F_106 ( V_506 ,
& V_14 -> V_210 ) )
F_177 ( V_14 , V_37 ) ;
} else {
F_177 ( V_14 , V_37 ) ;
if ( V_14 -> V_306 == V_349 ) {
F_56 ( V_506 , & V_14 -> V_210 ) ;
V_14 -> V_507 = V_37 -> V_164 ;
}
}
}
}
static void F_266 ( struct V_1 * V_14 ,
struct V_163 * V_37 )
{
struct V_32 * V_36 ;
F_19 ( L_10 , V_14 , V_37 ) ;
if ( V_37 -> V_164 == V_14 -> V_298 ) {
F_19 ( L_62 , V_37 -> V_164 ) ;
F_75 ( V_14 -> V_3 , V_14 , V_242 ) ;
return;
}
V_36 = F_32 ( & V_14 -> V_121 , V_37 -> V_164 ) ;
if ( V_14 -> V_75 && V_36 &&
F_34 ( V_36 ) -> V_37 . V_297 >= V_14 -> V_75 ) {
F_19 ( L_22 , V_14 -> V_75 ) ;
F_75 ( V_14 -> V_3 , V_14 , V_242 ) ;
return;
}
F_107 ( V_303 , & V_14 -> V_210 ) ;
F_206 ( V_14 , V_37 ) ;
if ( V_37 -> V_167 ) {
if ( ! F_106 ( V_508 , & V_14 -> V_210 ) )
F_178 ( V_14 , V_37 ) ;
} else {
F_178 ( V_14 , V_37 ) ;
F_169 ( V_14 ) ;
if ( V_14 -> V_306 == V_349 )
F_56 ( V_508 , & V_14 -> V_210 ) ;
}
}
static T_2 F_267 ( struct V_1 * V_14 , T_1 V_38 )
{
F_19 ( L_64 , V_14 , V_38 ) ;
F_19 ( L_65 , V_14 -> V_215 ,
V_14 -> V_338 ) ;
if ( V_14 -> V_310 == V_345 ) {
if ( F_181 ( V_14 , V_38 , V_14 -> V_215 ) >=
V_14 -> V_77 ) {
if ( V_14 -> V_77 <= ( ( V_14 -> V_79 + 1 ) >> 1 ) ) {
F_19 ( L_66 ) ;
return V_509 ;
} else {
F_19 ( L_67 ) ;
return V_510 ;
}
}
if ( V_14 -> V_118 . V_34 == V_38 ) {
F_19 ( L_68 ) ;
return V_511 ;
}
if ( F_32 ( & V_14 -> V_117 , V_38 ) ) {
F_19 ( L_69 ) ;
return V_512 ;
}
if ( F_40 ( & V_14 -> V_118 , V_38 ) ) {
F_19 ( L_70 ) ;
return V_513 ;
}
}
if ( V_14 -> V_338 == V_38 ) {
if ( F_181 ( V_14 , V_38 , V_14 -> V_215 ) >=
V_14 -> V_77 ) {
F_19 ( L_71 ) ;
return V_510 ;
} else {
F_19 ( L_72 ) ;
return V_514 ;
}
}
if ( F_181 ( V_14 , V_38 , V_14 -> V_215 ) <
F_181 ( V_14 , V_14 -> V_338 ,
V_14 -> V_215 ) ) {
F_19 ( L_73 ) ;
return V_515 ;
}
if ( F_181 ( V_14 , V_38 , V_14 -> V_215 ) >= V_14 -> V_77 ) {
if ( V_14 -> V_77 <= ( ( V_14 -> V_79 + 1 ) >> 1 ) ) {
F_19 ( L_74 ) ;
return V_509 ;
} else {
F_19 ( L_71 ) ;
return V_510 ;
}
} else {
F_19 ( L_75 ) ;
return V_516 ;
}
}
static int F_268 ( struct V_1 * V_14 ,
struct V_163 * V_37 ,
struct V_32 * V_36 , T_2 V_343 )
{
int V_15 = 0 ;
bool V_517 = 0 ;
F_19 ( L_76 , V_14 , V_37 , V_36 ,
V_343 ) ;
switch ( V_343 ) {
case V_518 :
switch ( F_267 ( V_14 , V_37 -> V_38 ) ) {
case V_514 :
F_206 ( V_14 , V_37 ) ;
if ( F_70 ( V_216 , & V_14 -> V_210 ) ) {
F_19 ( L_77 ,
V_37 -> V_38 ) ;
break;
}
V_14 -> V_338 = F_168 ( V_14 ,
V_37 -> V_38 ) ;
V_14 -> V_217 = V_14 -> V_338 ;
V_517 = 1 ;
V_15 = F_262 ( V_14 , V_36 , V_37 ) ;
if ( V_15 )
break;
if ( V_37 -> V_167 ) {
if ( ! F_106 ( V_508 ,
& V_14 -> V_210 ) ) {
V_37 -> V_167 = 0 ;
F_178 ( V_14 , V_37 ) ;
F_169 ( V_14 ) ;
}
}
if ( ! F_70 ( V_216 , & V_14 -> V_210 ) )
F_180 ( V_14 ) ;
break;
case V_516 :
F_206 ( V_14 , V_37 ) ;
if ( F_70 ( V_216 , & V_14 -> V_210 ) ) {
F_19 ( L_78 ,
V_37 -> V_38 ) ;
break;
}
F_269 ( & V_14 -> V_117 , V_36 ) ;
V_517 = 1 ;
F_19 ( L_79 , V_36 ,
F_173 ( & V_14 -> V_117 ) ) ;
F_107 ( V_506 , & V_14 -> V_210 ) ;
F_43 ( & V_14 -> V_118 ) ;
F_197 ( V_14 , V_37 -> V_38 ) ;
V_14 -> V_310 = V_345 ;
break;
case V_515 :
F_206 ( V_14 , V_37 ) ;
break;
case V_509 :
break;
case V_510 :
default:
F_75 ( V_14 -> V_3 , V_14 ,
V_242 ) ;
break;
}
break;
case V_519 :
F_206 ( V_14 , V_37 ) ;
if ( V_37 -> V_167 ) {
F_107 ( V_303 , & V_14 -> V_210 ) ;
if ( ! F_106 ( V_508 ,
& V_14 -> V_210 ) ) {
V_37 -> V_167 = 0 ;
F_178 ( V_14 , V_37 ) ;
}
F_169 ( V_14 ) ;
} else if ( V_37 -> V_172 ) {
F_259 ( V_14 ) ;
} else {
if ( F_106 ( V_303 ,
& V_14 -> V_210 ) &&
V_14 -> V_292 )
F_26 ( V_14 ) ;
F_169 ( V_14 ) ;
}
break;
case V_520 :
F_56 ( V_303 , & V_14 -> V_210 ) ;
F_206 ( V_14 , V_37 ) ;
if ( V_37 && V_37 -> V_172 ) {
F_56 ( V_209 , & V_14 -> V_210 ) ;
F_109 ( V_14 , 0 ) ;
}
F_31 ( V_14 ) ;
F_43 ( & V_14 -> V_119 ) ;
break;
case V_521 :
F_266 ( V_14 , V_37 ) ;
break;
case V_522 :
F_265 ( V_14 , V_37 ) ;
break;
default:
break;
}
if ( V_36 && ! V_517 ) {
F_19 ( L_80 , V_36 ) ;
F_131 ( V_36 ) ;
}
return V_15 ;
}
static int F_270 ( struct V_1 * V_14 ,
struct V_163 * V_37 ,
struct V_32 * V_36 , T_2 V_343 )
{
int V_15 = 0 ;
T_1 V_38 = V_37 -> V_38 ;
bool V_517 = 0 ;
F_19 ( L_76 , V_14 , V_37 , V_36 ,
V_343 ) ;
switch ( V_343 ) {
case V_518 :
switch ( F_267 ( V_14 , V_38 ) ) {
case V_514 :
F_206 ( V_14 , V_37 ) ;
F_269 ( & V_14 -> V_117 , V_36 ) ;
V_517 = 1 ;
F_19 ( L_79 , V_36 ,
F_173 ( & V_14 -> V_117 ) ) ;
V_14 -> V_338 = F_168 ( V_14 , V_38 ) ;
break;
case V_511 :
F_42 ( & V_14 -> V_118 ) ;
F_206 ( V_14 , V_37 ) ;
F_269 ( & V_14 -> V_117 , V_36 ) ;
V_517 = 1 ;
F_19 ( L_79 , V_36 ,
F_173 ( & V_14 -> V_117 ) ) ;
V_15 = F_264 ( V_14 ) ;
if ( V_15 )
break;
break;
case V_516 :
F_269 ( & V_14 -> V_117 , V_36 ) ;
V_517 = 1 ;
F_19 ( L_79 , V_36 ,
F_173 ( & V_14 -> V_117 ) ) ;
F_206 ( V_14 , V_37 ) ;
F_197 ( V_14 , V_37 -> V_38 ) ;
break;
case V_513 :
F_269 ( & V_14 -> V_117 , V_36 ) ;
V_517 = 1 ;
F_19 ( L_79 , V_36 ,
F_173 ( & V_14 -> V_117 ) ) ;
F_206 ( V_14 , V_37 ) ;
F_199 ( V_14 , V_37 -> V_38 ) ;
break;
case V_512 :
F_206 ( V_14 , V_37 ) ;
break;
case V_515 :
break;
case V_509 :
break;
case V_510 :
default:
F_75 ( V_14 -> V_3 , V_14 ,
V_242 ) ;
break;
}
break;
case V_519 :
F_206 ( V_14 , V_37 ) ;
if ( V_37 -> V_167 ) {
F_107 ( V_303 , & V_14 -> V_210 ) ;
if ( ! F_106 ( V_508 ,
& V_14 -> V_210 ) ) {
V_37 -> V_167 = 0 ;
F_178 ( V_14 , V_37 ) ;
}
F_169 ( V_14 ) ;
} else if ( V_37 -> V_172 ) {
if ( F_106 ( V_303 ,
& V_14 -> V_210 ) &&
V_14 -> V_292 ) {
F_26 ( V_14 ) ;
}
F_56 ( V_209 , & V_14 -> V_210 ) ;
F_198 ( V_14 ) ;
} else {
if ( F_106 ( V_303 ,
& V_14 -> V_210 ) &&
V_14 -> V_292 )
F_26 ( V_14 ) ;
F_180 ( V_14 ) ;
}
break;
case V_520 :
F_56 ( V_303 , & V_14 -> V_210 ) ;
F_206 ( V_14 , V_37 ) ;
if ( V_37 -> V_172 ) {
F_198 ( V_14 ) ;
} else {
struct V_163 V_523 ;
memset ( & V_523 , 0 , sizeof( V_523 ) ) ;
V_523 . V_171 = 1 ;
V_523 . V_175 = V_211 ;
V_523 . V_164 = V_14 -> V_217 ;
F_105 ( V_14 , & V_523 ) ;
}
break;
case V_521 :
F_266 ( V_14 , V_37 ) ;
break;
case V_522 :
F_265 ( V_14 , V_37 ) ;
break;
}
if ( V_36 && ! V_517 ) {
F_19 ( L_80 , V_36 ) ;
F_131 ( V_36 ) ;
}
return V_15 ;
}
static bool F_271 ( struct V_1 * V_14 , T_1 V_164 )
{
T_1 V_524 ;
V_524 = F_181 ( V_14 , V_14 -> V_298 , V_14 -> V_342 ) ;
return F_181 ( V_14 , V_14 -> V_298 , V_164 ) <= V_524 ;
}
static int F_272 ( struct V_1 * V_14 , struct V_163 * V_37 ,
struct V_32 * V_36 , T_2 V_343 )
{
int V_15 = 0 ;
F_19 ( L_81 , V_14 ,
V_37 , V_36 , V_343 , V_14 -> V_310 ) ;
if ( F_271 ( V_14 , V_37 -> V_164 ) ) {
switch ( V_14 -> V_310 ) {
case V_311 :
V_15 = F_268 ( V_14 , V_37 , V_36 , V_343 ) ;
break;
case V_345 :
V_15 = F_270 ( V_14 , V_37 , V_36 ,
V_343 ) ;
break;
default:
break;
}
} else {
F_19 ( L_82 ,
V_37 -> V_164 , V_14 -> V_298 ,
V_14 -> V_342 ) ;
F_75 ( V_14 -> V_3 , V_14 , V_242 ) ;
}
return V_15 ;
}
static int F_273 ( struct V_1 * V_14 , struct V_163 * V_37 ,
struct V_32 * V_36 )
{
int V_15 = 0 ;
F_19 ( L_83 , V_14 , V_37 , V_36 ,
V_14 -> V_310 ) ;
if ( F_267 ( V_14 , V_37 -> V_38 ) ==
V_514 ) {
F_206 ( V_14 , V_37 ) ;
F_19 ( L_84 , V_14 -> V_217 ,
F_168 ( V_14 , V_14 -> V_217 ) ) ;
V_14 -> V_217 = F_168 ( V_14 , V_14 -> V_217 ) ;
F_262 ( V_14 , V_36 , V_37 ) ;
} else {
if ( V_14 -> V_377 ) {
F_131 ( V_14 -> V_377 ) ;
V_14 -> V_377 = NULL ;
}
V_14 -> V_378 = NULL ;
V_14 -> V_328 = 0 ;
if ( V_36 ) {
F_19 ( L_80 , V_36 ) ;
F_131 ( V_36 ) ;
}
}
V_14 -> V_215 = V_37 -> V_38 ;
V_14 -> V_338 = F_168 ( V_14 , V_37 -> V_38 ) ;
return V_15 ;
}
static int F_274 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
struct V_163 * V_37 = & F_34 ( V_36 ) -> V_37 ;
T_1 V_150 ;
T_2 V_343 ;
F_90 ( V_14 , V_36 ) ;
V_150 = V_36 -> V_150 ;
if ( F_257 ( V_14 , V_36 ) )
goto V_525;
if ( ! V_37 -> V_171 && V_37 -> V_178 == V_333 )
V_150 -= V_326 ;
if ( V_14 -> V_73 == V_74 )
V_150 -= V_207 ;
if ( V_150 > V_14 -> V_429 ) {
F_75 ( V_14 -> V_3 , V_14 , V_242 ) ;
goto V_525;
}
if ( ! V_37 -> V_171 ) {
int V_15 ;
F_19 ( L_85 ,
V_37 -> V_178 , V_37 -> V_164 , V_37 -> V_167 ,
V_37 -> V_38 ) ;
if ( V_37 -> V_167 && V_14 -> V_306 != V_349 )
goto V_525;
if ( V_14 -> V_114 != V_120 ) {
V_343 = V_518 ;
V_15 = F_272 ( V_14 , V_37 , V_36 , V_343 ) ;
} else {
V_15 = F_273 ( V_14 , V_37 , V_36 ) ;
}
if ( V_15 )
F_75 ( V_14 -> V_3 , V_14 ,
V_242 ) ;
} else {
const T_2 V_526 [ 4 ] = {
V_519 , V_521 ,
V_520 , V_522
} ;
if ( V_14 -> V_114 == V_120 )
goto V_525;
F_19 ( L_86 ,
V_37 -> V_164 , V_37 -> V_167 , V_37 -> V_172 ,
V_37 -> V_175 ) ;
if ( V_150 != 0 ) {
F_254 ( L_87 , V_150 ) ;
F_75 ( V_14 -> V_3 , V_14 , V_242 ) ;
goto V_525;
}
if ( V_37 -> V_167 && ( V_37 -> V_172 ||
V_14 -> V_306 != V_349 ) )
goto V_525;
V_343 = V_526 [ V_37 -> V_175 ] ;
if ( F_272 ( V_14 , V_37 , V_36 , V_343 ) )
F_75 ( V_14 -> V_3 , V_14 , V_242 ) ;
}
return 0 ;
V_525:
F_131 ( V_36 ) ;
return 0 ;
}
static void F_275 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_4 ( V_3 , V_4 ) ;
if ( ! V_14 ) {
if ( V_4 == V_96 ) {
V_14 = F_276 ( V_3 , V_36 ) ;
if ( ! V_14 ) {
F_131 ( V_36 ) ;
return;
}
F_6 ( V_14 ) ;
} else {
F_19 ( L_88 , V_4 ) ;
F_131 ( V_36 ) ;
return;
}
}
F_19 ( L_89 , V_14 , V_36 -> V_150 ) ;
if ( V_14 -> V_23 != V_56 )
goto V_525;
switch ( V_14 -> V_114 ) {
case V_115 :
if ( V_14 -> V_98 < V_36 -> V_150 )
goto V_525;
if ( ! V_14 -> V_24 -> V_355 ( V_14 , V_36 ) )
goto V_18;
break;
case V_116 :
case V_120 :
F_274 ( V_14 , V_36 ) ;
goto V_18;
default:
F_19 ( L_90 , V_14 , V_14 -> V_114 ) ;
break;
}
V_525:
F_131 ( V_36 ) ;
V_18:
F_48 ( V_14 ) ;
}
static void F_277 ( struct V_2 * V_3 , T_3 V_10 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_140 ( 0 , V_10 , V_3 -> V_11 , V_3 -> V_253 ) ;
if ( ! V_14 )
goto V_525;
F_19 ( L_89 , V_14 , V_36 -> V_150 ) ;
if ( V_14 -> V_23 != V_284 && V_14 -> V_23 != V_56 )
goto V_525;
if ( V_14 -> V_98 < V_36 -> V_150 )
goto V_525;
if ( ! V_14 -> V_24 -> V_355 ( V_14 , V_36 ) )
return;
V_525:
F_131 ( V_36 ) ;
}
static void F_278 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_119 ( 0 , V_4 , V_3 -> V_11 , V_3 -> V_253 ) ;
if ( ! V_14 )
goto V_525;
F_19 ( L_89 , V_14 , V_36 -> V_150 ) ;
if ( V_14 -> V_23 != V_284 && V_14 -> V_23 != V_56 )
goto V_525;
if ( V_14 -> V_98 < V_36 -> V_150 )
goto V_525;
if ( ! V_14 -> V_24 -> V_355 ( V_14 , V_36 ) )
return;
V_525:
F_131 ( V_36 ) ;
}
static void F_279 ( struct V_2 * V_3 , struct V_32 * V_36 )
{
struct V_204 * V_205 = ( void * ) V_36 -> V_151 ;
T_1 V_4 , V_150 ;
T_3 V_10 ;
F_92 ( V_36 , V_201 ) ;
V_4 = F_65 ( V_205 -> V_4 ) ;
V_150 = F_65 ( V_205 -> V_150 ) ;
if ( V_150 != V_36 -> V_150 ) {
F_131 ( V_36 ) ;
return;
}
F_19 ( L_91 , V_150 , V_4 ) ;
switch ( V_4 ) {
case V_360 :
case V_99 :
F_256 ( V_3 , V_36 ) ;
break;
case V_94 :
V_10 = F_280 ( ( T_3 * ) V_36 -> V_151 ) ;
F_92 ( V_36 , V_324 ) ;
F_277 ( V_3 , V_10 , V_36 ) ;
break;
case V_92 :
F_278 ( V_3 , V_4 , V_36 ) ;
break;
case V_527 :
if ( F_281 ( V_3 , V_36 ) )
F_130 ( V_3 -> V_88 , V_528 ) ;
break;
default:
F_275 ( V_3 , V_4 , V_36 ) ;
break;
}
}
int F_282 ( struct V_280 * V_152 , T_4 * V_278 )
{
int V_529 = 0 , V_530 = 0 , V_531 = 0 ;
struct V_1 * V_5 ;
F_19 ( L_92 , V_152 -> V_532 , F_142 ( V_278 ) ) ;
F_120 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
if ( V_5 -> V_23 != V_122 )
continue;
if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , & V_152 -> V_278 ) ) {
V_530 |= V_533 ;
if ( F_70 ( V_534 , & V_5 -> V_83 ) )
V_530 |= V_489 ;
V_529 ++ ;
} else if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_259 ) ) {
V_531 |= V_533 ;
if ( F_70 ( V_534 , & V_5 -> V_83 ) )
V_531 |= V_489 ;
}
}
F_121 ( & V_16 ) ;
return V_529 ? V_530 : V_531 ;
}
void F_283 ( struct V_160 * V_88 , T_2 V_133 )
{
struct V_2 * V_3 ;
F_19 ( L_93 , V_88 , F_142 ( & V_88 -> V_253 ) , V_133 ) ;
if ( ! V_133 ) {
V_3 = F_136 ( V_88 , V_133 ) ;
if ( V_3 )
F_126 ( V_3 ) ;
} else
F_130 ( V_88 , F_284 ( V_133 ) ) ;
}
int F_285 ( struct V_160 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_269 ;
F_19 ( L_94 , V_88 ) ;
if ( ! V_3 )
return V_85 ;
return V_3 -> V_84 ;
}
void F_286 ( struct V_160 * V_88 , T_2 V_55 )
{
F_19 ( L_95 , V_88 , V_55 ) ;
F_130 ( V_88 , F_284 ( V_55 ) ) ;
}
static inline void F_287 ( struct V_1 * V_14 , T_2 V_535 )
{
if ( V_14 -> V_86 != V_87 )
return;
if ( V_535 == 0x00 ) {
if ( V_14 -> V_60 == V_139 ) {
F_74 ( V_14 , V_536 ) ;
} else if ( V_14 -> V_60 == V_137 )
F_47 ( V_14 , V_58 ) ;
} else {
if ( V_14 -> V_60 == V_139 )
F_68 ( V_14 ) ;
}
}
int F_288 ( struct V_160 * V_88 , T_2 V_133 , T_2 V_535 )
{
struct V_2 * V_3 = V_88 -> V_269 ;
struct V_1 * V_14 ;
if ( ! V_3 )
return 0 ;
F_19 ( L_96 , V_3 , V_133 , V_535 ) ;
if ( V_88 -> type == V_89 ) {
if ( ! V_133 && V_535 )
F_289 ( V_3 , 0 ) ;
F_230 ( & V_3 -> V_273 ) ;
}
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
F_6 ( V_14 ) ;
F_19 ( L_97 , V_14 , V_14 -> V_7 ,
F_20 ( V_14 -> V_23 ) ) ;
if ( V_14 -> V_86 == V_95 ) {
F_48 ( V_14 ) ;
continue;
}
if ( V_14 -> V_7 == V_92 ) {
if ( ! V_133 && V_535 ) {
V_14 -> V_60 = V_88 -> V_60 ;
F_112 ( V_14 ) ;
}
F_48 ( V_14 ) ;
continue;
}
if ( F_70 ( V_218 , & V_14 -> V_71 ) ) {
F_48 ( V_14 ) ;
continue;
}
if ( ! V_133 && ( V_14 -> V_23 == V_56 ||
V_14 -> V_23 == V_57 ) ) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_107 ( V_537 , & F_11 ( V_13 ) -> V_83 ) ;
V_13 -> V_267 ( V_13 ) ;
F_287 ( V_14 , V_535 ) ;
F_48 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_59 ) {
if ( ! V_133 ) {
F_111 ( V_14 ) ;
} else {
F_74 ( V_14 , V_538 ) ;
}
} else if ( V_14 -> V_23 == V_125 ) {
struct V_26 * V_13 = V_14 -> V_13 ;
struct V_126 V_127 ;
T_5 V_539 , V_540 ;
F_22 ( V_13 ) ;
if ( ! V_133 ) {
if ( F_70 ( V_129 ,
& F_11 ( V_13 ) -> V_83 ) ) {
struct V_26 * V_244 = F_11 ( V_13 ) -> V_244 ;
V_539 = V_245 ;
V_540 = V_246 ;
if ( V_244 )
V_244 -> V_247 ( V_244 , 0 ) ;
} else {
F_18 ( V_14 , V_57 ) ;
V_539 = V_248 ;
V_540 = V_134 ;
}
} else {
F_18 ( V_14 , V_132 ) ;
F_74 ( V_14 , V_538 ) ;
V_539 = V_130 ;
V_540 = V_134 ;
}
F_23 ( V_13 ) ;
V_127 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_127 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_127 . V_128 = F_14 ( V_539 ) ;
V_127 . V_133 = F_14 ( V_540 ) ;
F_77 ( V_3 , V_14 -> V_9 , V_135 ,
sizeof( V_127 ) , & V_127 ) ;
if ( ! F_70 ( V_250 , & V_14 -> V_71 ) &&
V_539 == V_248 ) {
char V_243 [ 128 ] ;
F_56 ( V_250 , & V_14 -> V_71 ) ;
F_77 ( V_3 , F_81 ( V_3 ) ,
V_251 ,
F_118 ( V_14 , V_243 ) ,
V_243 ) ;
V_14 -> V_252 ++ ;
}
}
F_48 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
int F_290 ( struct V_160 * V_88 , struct V_32 * V_36 , T_1 V_83 )
{
struct V_2 * V_3 = V_88 -> V_269 ;
if ( ! V_3 )
V_3 = F_136 ( V_88 , 0 ) ;
if ( ! V_3 )
goto V_525;
F_19 ( L_98 , V_3 , V_36 -> V_150 , V_83 ) ;
if ( ! ( V_83 & V_541 ) ) {
struct V_204 * V_542 ;
int V_150 ;
if ( V_3 -> V_543 ) {
F_254 ( L_99 , V_36 -> V_150 ) ;
F_131 ( V_3 -> V_271 ) ;
V_3 -> V_271 = NULL ;
V_3 -> V_543 = 0 ;
F_128 ( V_3 , V_544 ) ;
}
if ( V_36 -> V_150 < V_201 ) {
F_254 ( L_100 , V_36 -> V_150 ) ;
F_128 ( V_3 , V_544 ) ;
goto V_525;
}
V_542 = (struct V_204 * ) V_36 -> V_151 ;
V_150 = F_65 ( V_542 -> V_150 ) + V_201 ;
if ( V_150 == V_36 -> V_150 ) {
F_279 ( V_3 , V_36 ) ;
return 0 ;
}
F_19 ( L_101 , V_150 , V_36 -> V_150 ) ;
if ( V_36 -> V_150 > V_150 ) {
F_254 ( L_102 ,
V_36 -> V_150 , V_150 ) ;
F_128 ( V_3 , V_544 ) ;
goto V_525;
}
V_3 -> V_271 = F_101 ( V_150 , V_64 ) ;
if ( ! V_3 -> V_271 )
goto V_525;
F_291 ( V_36 , F_103 ( V_3 -> V_271 , V_36 -> V_150 ) ,
V_36 -> V_150 ) ;
V_3 -> V_543 = V_150 - V_36 -> V_150 ;
} else {
F_19 ( L_103 , V_36 -> V_150 , V_3 -> V_543 ) ;
if ( ! V_3 -> V_543 ) {
F_254 ( L_104 , V_36 -> V_150 ) ;
F_128 ( V_3 , V_544 ) ;
goto V_525;
}
if ( V_36 -> V_150 > V_3 -> V_543 ) {
F_254 ( L_105 ,
V_36 -> V_150 , V_3 -> V_543 ) ;
F_131 ( V_3 -> V_271 ) ;
V_3 -> V_271 = NULL ;
V_3 -> V_543 = 0 ;
F_128 ( V_3 , V_544 ) ;
goto V_525;
}
F_291 ( V_36 , F_103 ( V_3 -> V_271 , V_36 -> V_150 ) ,
V_36 -> V_150 ) ;
V_3 -> V_543 -= V_36 -> V_150 ;
if ( ! V_3 -> V_543 ) {
F_279 ( V_3 , V_3 -> V_271 ) ;
V_3 -> V_271 = NULL ;
}
}
V_525:
F_131 ( V_36 ) ;
return 0 ;
}
static int F_292 ( struct V_545 * V_546 , void * V_19 )
{
struct V_1 * V_5 ;
F_120 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
F_293 ( V_546 , L_106 ,
F_142 ( & F_11 ( V_13 ) -> V_11 ) ,
F_142 ( & F_11 ( V_13 ) -> V_253 ) ,
V_5 -> V_23 , F_65 ( V_5 -> V_10 ) ,
V_5 -> V_7 , V_5 -> V_6 , V_5 -> V_98 , V_5 -> V_90 ,
V_5 -> V_60 , V_5 -> V_114 ) ;
}
F_121 ( & V_16 ) ;
return 0 ;
}
static int F_294 ( struct V_547 * V_547 , struct V_548 * V_548 )
{
return F_295 ( V_548 , F_292 , V_547 -> V_549 ) ;
}
int T_10 F_296 ( void )
{
int V_15 ;
V_15 = F_297 () ;
if ( V_15 < 0 )
return V_15 ;
if ( V_550 ) {
V_551 = F_298 ( L_107 , 0444 ,
V_550 , NULL , & V_552 ) ;
if ( ! V_551 )
F_254 ( L_108 ) ;
}
return 0 ;
}
void F_299 ( void )
{
F_300 ( V_551 ) ;
F_301 () ;
}
