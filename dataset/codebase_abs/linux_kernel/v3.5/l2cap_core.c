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
V_14 -> V_24 -> V_25 ( V_14 -> V_26 , V_23 ) ;
}
static void F_21 ( struct V_1 * V_14 , int V_23 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
F_22 ( V_13 ) ;
F_18 ( V_14 , V_23 ) ;
F_23 ( V_13 ) ;
}
static inline void F_24 ( struct V_1 * V_14 , int V_15 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
V_13 -> V_28 = V_15 ;
}
static inline void F_25 ( struct V_1 * V_14 , int V_15 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
F_22 ( V_13 ) ;
F_24 ( V_14 , V_15 ) ;
F_23 ( V_13 ) ;
}
static int F_26 ( struct V_29 * V_30 , T_1 V_31 )
{
T_6 V_32 , V_33 ;
V_32 = F_27 ( V_31 ) ;
V_30 -> V_34 = F_28 ( sizeof( T_1 ) * V_32 , V_35 ) ;
if ( ! V_30 -> V_34 )
return - V_36 ;
V_30 -> V_37 = V_32 - 1 ;
V_30 -> V_38 = V_39 ;
V_30 -> V_40 = V_39 ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ )
V_30 -> V_34 [ V_33 ] = V_39 ;
return 0 ;
}
static inline void F_29 ( struct V_29 * V_30 )
{
F_30 ( V_30 -> V_34 ) ;
}
static inline bool F_31 ( struct V_29 * V_30 ,
T_1 V_41 )
{
return V_30 -> V_34 [ V_41 & V_30 -> V_37 ] != V_39 ;
}
static T_1 F_32 ( struct V_29 * V_30 , T_1 V_41 )
{
T_1 V_37 = V_30 -> V_37 ;
if ( V_30 -> V_38 == V_39 ) {
return V_39 ;
} else if ( V_30 -> V_38 == V_41 ) {
V_30 -> V_38 = V_30 -> V_34 [ V_41 & V_37 ] ;
V_30 -> V_34 [ V_41 & V_37 ] = V_39 ;
if ( V_30 -> V_38 == V_42 ) {
V_30 -> V_38 = V_39 ;
V_30 -> V_40 = V_39 ;
}
} else {
T_1 V_43 = V_30 -> V_38 ;
while ( V_30 -> V_34 [ V_43 & V_37 ] != V_41 ) {
V_43 = V_30 -> V_34 [ V_43 & V_37 ] ;
if ( V_43 == V_42 )
return V_39 ;
}
V_30 -> V_34 [ V_43 & V_37 ] = V_30 -> V_34 [ V_41 & V_37 ] ;
V_30 -> V_34 [ V_41 & V_37 ] = V_39 ;
if ( V_30 -> V_40 == V_41 )
V_30 -> V_40 = V_43 ;
}
return V_41 ;
}
static inline T_1 F_33 ( struct V_29 * V_30 )
{
return F_32 ( V_30 , V_30 -> V_38 ) ;
}
static void F_34 ( struct V_29 * V_30 )
{
T_1 V_33 ;
if ( V_30 -> V_38 == V_39 )
return;
for ( V_33 = 0 ; V_33 <= V_30 -> V_37 ; V_33 ++ )
V_30 -> V_34 [ V_33 ] = V_39 ;
V_30 -> V_38 = V_39 ;
V_30 -> V_40 = V_39 ;
}
static void F_35 ( struct V_29 * V_30 , T_1 V_41 )
{
T_1 V_37 = V_30 -> V_37 ;
if ( V_30 -> V_34 [ V_41 & V_37 ] != V_39 )
return;
if ( V_30 -> V_40 == V_39 )
V_30 -> V_38 = V_41 ;
else
V_30 -> V_34 [ V_30 -> V_40 & V_37 ] = V_41 ;
V_30 -> V_40 = V_41 ;
V_30 -> V_34 [ V_41 & V_37 ] = V_42 ;
}
static void F_36 ( struct V_44 * V_45 )
{
struct V_1 * V_14 = F_37 ( V_45 , struct V_1 ,
V_46 . V_45 ) ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_47 ;
F_19 ( L_2 , V_14 , F_20 ( V_14 -> V_23 ) ) ;
F_5 ( & V_3 -> V_8 ) ;
F_6 ( V_14 ) ;
if ( V_14 -> V_23 == V_48 || V_14 -> V_23 == V_49 )
V_47 = V_50 ;
else if ( V_14 -> V_23 == V_51 &&
V_14 -> V_52 != V_53 )
V_47 = V_50 ;
else
V_47 = V_54 ;
F_38 ( V_14 , V_47 ) ;
F_39 ( V_14 ) ;
V_14 -> V_24 -> V_55 ( V_14 -> V_26 ) ;
F_7 ( & V_3 -> V_8 ) ;
F_40 ( V_14 ) ;
}
struct V_1 * F_41 ( void )
{
struct V_1 * V_14 ;
V_14 = F_42 ( sizeof( * V_14 ) , V_56 ) ;
if ( ! V_14 )
return NULL ;
F_43 ( & V_14 -> V_57 ) ;
F_13 ( & V_16 ) ;
F_44 ( & V_14 -> V_58 , & V_59 ) ;
F_15 ( & V_16 ) ;
F_45 ( & V_14 -> V_46 , F_36 ) ;
V_14 -> V_23 = V_60 ;
F_46 ( & V_14 -> V_61 , 1 ) ;
F_19 ( L_3 , V_14 ) ;
return V_14 ;
}
void F_47 ( struct V_1 * V_14 )
{
F_13 ( & V_16 ) ;
F_48 ( & V_14 -> V_58 ) ;
F_15 ( & V_16 ) ;
F_40 ( V_14 ) ;
}
void F_49 ( struct V_1 * V_14 )
{
V_14 -> V_62 = V_63 ;
V_14 -> V_64 = V_65 ;
V_14 -> V_66 = V_67 ;
V_14 -> V_68 = V_67 ;
V_14 -> V_52 = V_69 ;
F_50 ( V_70 , & V_14 -> V_71 ) ;
}
static void F_51 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_19 ( L_4 , V_3 ,
F_52 ( V_14 -> V_10 ) , V_14 -> V_6 ) ;
V_3 -> V_72 = V_73 ;
V_14 -> V_3 = V_3 ;
switch ( V_14 -> V_74 ) {
case V_75 :
if ( V_3 -> V_76 -> type == V_77 ) {
V_14 -> V_78 = V_79 ;
V_14 -> V_7 = V_80 ;
V_14 -> V_6 = V_80 ;
} else {
V_14 -> V_7 = F_17 ( V_3 ) ;
V_14 -> V_78 = V_81 ;
}
break;
case V_82 :
V_14 -> V_7 = V_83 ;
V_14 -> V_6 = V_83 ;
V_14 -> V_78 = V_81 ;
break;
default:
V_14 -> V_7 = V_84 ;
V_14 -> V_6 = V_84 ;
V_14 -> V_78 = V_81 ;
}
V_14 -> V_85 = V_86 ;
V_14 -> V_87 = V_88 ;
V_14 -> V_89 = V_90 ;
V_14 -> V_91 = V_92 ;
V_14 -> V_93 = V_94 ;
V_14 -> V_95 = V_96 ;
F_53 ( V_14 ) ;
F_44 ( & V_14 -> V_34 , & V_3 -> V_97 ) ;
}
static void F_54 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_5 ( & V_3 -> V_8 ) ;
F_51 ( V_3 , V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
}
static void F_55 ( struct V_1 * V_14 , int V_15 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_27 * V_98 = F_11 ( V_13 ) -> V_98 ;
F_56 ( V_14 ) ;
F_19 ( L_5 , V_14 , V_3 , V_15 ) ;
if ( V_3 ) {
F_48 ( & V_14 -> V_34 ) ;
F_40 ( V_14 ) ;
V_14 -> V_3 = NULL ;
F_57 ( V_3 -> V_76 ) ;
}
F_22 ( V_13 ) ;
F_18 ( V_14 , V_99 ) ;
F_58 ( V_13 , V_100 ) ;
if ( V_15 )
F_24 ( V_14 , V_15 ) ;
if ( V_98 ) {
F_59 ( V_13 ) ;
V_98 -> V_101 ( V_98 , 0 ) ;
} else
V_13 -> V_102 ( V_13 ) ;
F_23 ( V_13 ) ;
if ( ! ( F_60 ( V_103 , & V_14 -> V_104 ) &&
F_60 ( V_105 , & V_14 -> V_104 ) ) )
return;
F_61 ( & V_14 -> V_106 ) ;
if ( V_14 -> V_107 == V_108 ) {
struct V_109 * V_110 , * V_111 ;
F_62 ( V_14 ) ;
F_63 ( V_14 ) ;
F_64 ( V_14 ) ;
F_61 ( & V_14 -> V_112 ) ;
F_29 ( & V_14 -> V_109 ) ;
F_29 ( & V_14 -> V_113 ) ;
F_65 (l, tmp, &chan->srej_l, list) {
F_48 ( & V_110 -> V_34 ) ;
F_30 ( V_110 ) ;
}
}
}
static void F_66 ( struct V_27 * V_98 )
{
struct V_27 * V_13 ;
F_19 ( L_6 , V_98 ) ;
while ( ( V_13 = F_67 ( V_98 , NULL ) ) ) {
struct V_1 * V_14 = F_68 ( V_13 ) -> V_14 ;
F_6 ( V_14 ) ;
F_56 ( V_14 ) ;
F_38 ( V_14 , V_114 ) ;
F_39 ( V_14 ) ;
V_14 -> V_24 -> V_55 ( V_14 -> V_26 ) ;
}
}
void F_38 ( struct V_1 * V_14 , int V_47 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_27 * V_13 = V_14 -> V_13 ;
F_19 ( L_7 , V_14 ,
F_20 ( V_14 -> V_23 ) , V_13 ) ;
switch ( V_14 -> V_23 ) {
case V_115 :
F_22 ( V_13 ) ;
F_66 ( V_13 ) ;
F_18 ( V_14 , V_99 ) ;
F_58 ( V_13 , V_100 ) ;
F_23 ( V_13 ) ;
break;
case V_48 :
case V_49 :
if ( V_14 -> V_74 == V_75 &&
V_3 -> V_76 -> type == V_116 ) {
F_69 ( V_14 , V_13 -> V_117 ) ;
F_70 ( V_3 , V_14 , V_47 ) ;
} else
F_55 ( V_14 , V_47 ) ;
break;
case V_118 :
if ( V_14 -> V_74 == V_75 &&
V_3 -> V_76 -> type == V_116 ) {
struct V_119 V_120 ;
T_5 V_121 ;
if ( F_60 ( V_122 , & F_11 ( V_13 ) -> V_71 ) )
V_121 = V_123 ;
else
V_121 = V_124 ;
F_21 ( V_14 , V_125 ) ;
V_120 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_120 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_120 . V_121 = F_14 ( V_121 ) ;
V_120 . V_126 = F_14 ( V_127 ) ;
F_71 ( V_3 , V_14 -> V_9 , V_128 ,
sizeof( V_120 ) , & V_120 ) ;
}
F_55 ( V_14 , V_47 ) ;
break;
case V_51 :
case V_125 :
F_55 ( V_14 , V_47 ) ;
break;
default:
F_22 ( V_13 ) ;
F_58 ( V_13 , V_100 ) ;
F_23 ( V_13 ) ;
break;
}
}
static inline T_2 F_72 ( struct V_1 * V_14 )
{
if ( V_14 -> V_74 == V_129 ) {
switch ( V_14 -> V_52 ) {
case V_130 :
return V_131 ;
case V_132 :
return V_133 ;
default:
return V_134 ;
}
} else if ( V_14 -> V_10 == F_14 ( 0x0001 ) ) {
if ( V_14 -> V_52 == V_69 )
V_14 -> V_52 = V_53 ;
if ( V_14 -> V_52 == V_130 )
return V_135 ;
else
return V_134 ;
} else {
switch ( V_14 -> V_52 ) {
case V_130 :
return V_136 ;
case V_132 :
return V_137 ;
default:
return V_134 ;
}
}
}
int F_73 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
T_7 V_138 ;
V_138 = F_72 ( V_14 ) ;
return F_74 ( V_3 -> V_76 , V_14 -> V_52 , V_138 ) ;
}
static T_2 F_75 ( struct V_2 * V_3 )
{
T_2 V_139 ;
F_76 ( & V_3 -> V_57 ) ;
if ( ++ V_3 -> V_140 > 128 )
V_3 -> V_140 = 1 ;
V_139 = V_3 -> V_140 ;
F_77 ( & V_3 -> V_57 ) ;
return V_139 ;
}
static void F_71 ( struct V_2 * V_3 , T_2 V_9 , T_2 V_141 , T_1 V_142 , void * V_26 )
{
struct V_143 * V_144 = F_78 ( V_3 , V_141 , V_9 , V_142 , V_26 ) ;
T_2 V_71 ;
F_19 ( L_8 , V_141 ) ;
if ( ! V_144 )
return;
if ( F_79 ( V_3 -> V_76 -> V_145 ) )
V_71 = V_146 ;
else
V_71 = V_147 ;
F_80 ( V_144 ) -> V_148 = V_149 ;
V_144 -> V_150 = V_151 ;
F_81 ( V_3 -> V_152 , V_144 , V_71 ) ;
}
static void F_82 ( struct V_1 * V_14 , struct V_143 * V_144 )
{
struct V_153 * V_76 = V_14 -> V_3 -> V_76 ;
T_1 V_71 ;
F_19 ( L_9 , V_14 , V_144 , V_144 -> V_142 ,
V_144 -> V_150 ) ;
if ( ! F_60 ( V_154 , & V_14 -> V_71 ) &&
F_79 ( V_76 -> V_145 ) )
V_71 = V_146 ;
else
V_71 = V_147 ;
F_80 ( V_144 ) -> V_148 = F_60 ( V_70 , & V_14 -> V_71 ) ;
F_81 ( V_14 -> V_3 -> V_152 , V_144 , V_71 ) ;
}
static void F_83 ( T_1 V_155 , struct V_156 * V_157 )
{
V_157 -> V_158 = ( V_155 & V_159 ) >> V_160 ;
V_157 -> V_161 = ( V_155 & V_162 ) >> V_163 ;
if ( V_155 & V_164 ) {
V_157 -> V_165 = 1 ;
V_157 -> V_166 = ( V_155 & V_167 ) >> V_168 ;
V_157 -> V_169 = ( V_155 & V_170 ) >> V_171 ;
V_157 -> V_172 = 0 ;
V_157 -> V_173 = 0 ;
} else {
V_157 -> V_165 = 0 ;
V_157 -> V_172 = ( V_155 & V_174 ) >> V_175 ;
V_157 -> V_173 = ( V_155 & V_176 ) >> V_177 ;
V_157 -> V_166 = 0 ;
V_157 -> V_169 = 0 ;
}
}
static void F_84 ( T_8 V_178 , struct V_156 * V_157 )
{
V_157 -> V_158 = ( V_178 & V_179 ) >> V_180 ;
V_157 -> V_161 = ( V_178 & V_181 ) >> V_182 ;
if ( V_178 & V_183 ) {
V_157 -> V_165 = 1 ;
V_157 -> V_166 = ( V_178 & V_184 ) >> V_185 ;
V_157 -> V_169 = ( V_178 & V_186 ) >> V_187 ;
V_157 -> V_172 = 0 ;
V_157 -> V_173 = 0 ;
} else {
V_157 -> V_165 = 0 ;
V_157 -> V_172 = ( V_178 & V_188 ) >> V_189 ;
V_157 -> V_173 = ( V_178 & V_190 ) >> V_191 ;
V_157 -> V_166 = 0 ;
V_157 -> V_169 = 0 ;
}
}
static inline void F_85 ( struct V_1 * V_14 ,
struct V_143 * V_144 )
{
if ( F_60 ( V_192 , & V_14 -> V_71 ) ) {
F_84 ( F_86 ( V_144 -> V_26 ) ,
& F_80 ( V_144 ) -> V_157 ) ;
} else {
F_83 ( F_87 ( V_144 -> V_26 ) ,
& F_80 ( V_144 ) -> V_157 ) ;
}
}
static T_8 F_88 ( struct V_156 * V_157 )
{
T_8 V_193 ;
V_193 = V_157 -> V_158 << V_180 ;
V_193 |= V_157 -> V_161 << V_182 ;
if ( V_157 -> V_165 ) {
V_193 |= V_157 -> V_166 << V_185 ;
V_193 |= V_157 -> V_169 << V_187 ;
V_193 |= V_183 ;
} else {
V_193 |= V_157 -> V_172 << V_189 ;
V_193 |= V_157 -> V_173 << V_191 ;
}
return V_193 ;
}
static T_1 F_89 ( struct V_156 * V_157 )
{
T_1 V_193 ;
V_193 = V_157 -> V_158 << V_160 ;
V_193 |= V_157 -> V_161 << V_163 ;
if ( V_157 -> V_165 ) {
V_193 |= V_157 -> V_166 << V_168 ;
V_193 |= V_157 -> V_169 << V_171 ;
V_193 |= V_164 ;
} else {
V_193 |= V_157 -> V_172 << V_175 ;
V_193 |= V_157 -> V_173 << V_177 ;
}
return V_193 ;
}
static inline void F_90 ( struct V_1 * V_14 ,
struct V_156 * V_157 ,
struct V_143 * V_144 )
{
if ( F_60 ( V_192 , & V_14 -> V_71 ) ) {
F_91 ( F_88 ( V_157 ) ,
V_144 -> V_26 + V_194 ) ;
} else {
F_92 ( F_89 ( V_157 ) ,
V_144 -> V_26 + V_194 ) ;
}
}
static inline void F_93 ( struct V_1 * V_14 , T_8 V_157 )
{
struct V_143 * V_144 ;
struct V_195 * V_196 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_197 , V_198 ;
if ( V_14 -> V_23 != V_48 )
return;
if ( F_60 ( V_192 , & V_14 -> V_71 ) )
V_198 = V_199 ;
else
V_198 = V_200 ;
if ( V_14 -> V_62 == V_63 )
V_198 += V_201 ;
F_19 ( L_10 , V_14 , V_157 ) ;
V_197 = F_94 (unsigned int, conn->mtu, hlen) ;
V_157 |= F_95 ( V_14 ) ;
if ( F_96 ( V_202 , & V_14 -> V_203 ) )
V_157 |= F_97 ( V_14 ) ;
if ( F_96 ( V_204 , & V_14 -> V_203 ) )
V_157 |= F_98 ( V_14 ) ;
V_144 = F_99 ( V_197 , V_56 ) ;
if ( ! V_144 )
return;
V_196 = (struct V_195 * ) F_100 ( V_144 , V_194 ) ;
V_196 -> V_142 = F_14 ( V_198 - V_194 ) ;
V_196 -> V_4 = F_14 ( V_14 -> V_6 ) ;
F_101 ( V_14 , V_157 , F_100 ( V_144 , F_102 ( V_14 ) ) ) ;
if ( V_14 -> V_62 == V_63 ) {
T_1 V_62 = F_103 ( 0 , ( T_2 * ) V_196 , V_197 - V_201 ) ;
F_92 ( V_62 , F_100 ( V_144 , V_201 ) ) ;
}
V_144 -> V_150 = V_151 ;
F_82 ( V_14 , V_144 ) ;
}
static inline void F_104 ( struct V_1 * V_14 , T_8 V_157 )
{
if ( F_60 ( V_205 , & V_14 -> V_203 ) ) {
V_157 |= F_105 ( V_14 , V_206 ) ;
F_50 ( V_207 , & V_14 -> V_203 ) ;
} else
V_157 |= F_105 ( V_14 , V_208 ) ;
V_157 |= F_106 ( V_14 , V_14 -> V_209 ) ;
F_93 ( V_14 , V_157 ) ;
}
static inline int F_107 ( struct V_1 * V_14 )
{
return ! F_60 ( V_210 , & V_14 -> V_104 ) ;
}
static void F_108 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_211 V_212 ;
V_212 . V_7 = F_14 ( V_14 -> V_7 ) ;
V_212 . V_10 = V_14 -> V_10 ;
V_14 -> V_9 = F_75 ( V_3 ) ;
F_50 ( V_210 , & V_14 -> V_104 ) ;
F_71 ( V_3 , V_14 -> V_9 , V_213 , sizeof( V_212 ) , & V_212 ) ;
}
static void F_109 ( struct V_1 * V_14 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
struct V_27 * V_98 ;
F_22 ( V_13 ) ;
V_98 = F_11 ( V_13 ) -> V_98 ;
F_19 ( L_11 , V_13 , V_98 ) ;
V_14 -> V_104 = 0 ;
F_56 ( V_14 ) ;
F_18 ( V_14 , V_48 ) ;
V_13 -> V_102 ( V_13 ) ;
if ( V_98 )
V_98 -> V_101 ( V_98 , 0 ) ;
F_23 ( V_13 ) ;
}
static void F_110 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
if ( V_3 -> V_76 -> type == V_77 ) {
F_109 ( V_14 ) ;
return;
}
if ( V_3 -> V_214 & V_215 ) {
if ( ! ( V_3 -> V_214 & V_216 ) )
return;
if ( F_73 ( V_14 ) &&
F_107 ( V_14 ) )
F_108 ( V_14 ) ;
} else {
struct V_217 V_212 ;
V_212 . type = F_14 ( V_218 ) ;
V_3 -> V_214 |= V_215 ;
V_3 -> V_219 = F_75 ( V_3 ) ;
F_111 ( & V_3 -> V_220 , V_221 ) ;
F_71 ( V_3 , V_3 -> V_219 ,
V_222 , sizeof( V_212 ) , & V_212 ) ;
}
}
static inline int F_112 ( T_7 V_107 , T_9 V_223 )
{
T_8 V_224 = V_225 ;
if ( ! V_226 )
V_224 |= V_227 | V_228 ;
switch ( V_107 ) {
case V_108 :
return V_227 & V_223 & V_224 ;
case V_229 :
return V_228 & V_223 & V_224 ;
default:
return 0x00 ;
}
}
static void F_70 ( struct V_2 * V_3 , struct V_1 * V_14 , int V_15 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
struct V_230 V_212 ;
if ( ! V_3 )
return;
if ( V_14 -> V_107 == V_108 ) {
F_62 ( V_14 ) ;
F_63 ( V_14 ) ;
F_64 ( V_14 ) ;
}
V_212 . V_6 = F_14 ( V_14 -> V_6 ) ;
V_212 . V_7 = F_14 ( V_14 -> V_7 ) ;
F_71 ( V_3 , F_75 ( V_3 ) ,
V_231 , sizeof( V_212 ) , & V_212 ) ;
F_22 ( V_13 ) ;
F_18 ( V_14 , V_125 ) ;
F_24 ( V_14 , V_15 ) ;
F_23 ( V_13 ) ;
}
static void F_113 ( struct V_2 * V_3 )
{
struct V_1 * V_14 , * V_111 ;
F_19 ( L_12 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_65 (chan, tmp, &conn->chan_l, list) {
struct V_27 * V_13 = V_14 -> V_13 ;
F_6 ( V_14 ) ;
if ( V_14 -> V_74 != V_75 ) {
F_39 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_51 ) {
if ( ! F_73 ( V_14 ) ||
! F_107 ( V_14 ) ) {
F_39 ( V_14 ) ;
continue;
}
if ( ! F_112 ( V_14 -> V_107 , V_3 -> V_223 )
&& F_60 ( V_232 ,
& V_14 -> V_104 ) ) {
F_38 ( V_14 , V_114 ) ;
F_39 ( V_14 ) ;
continue;
}
F_108 ( V_14 ) ;
} else if ( V_14 -> V_23 == V_118 ) {
struct V_119 V_120 ;
char V_233 [ 128 ] ;
V_120 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_120 . V_6 = F_14 ( V_14 -> V_7 ) ;
if ( F_73 ( V_14 ) ) {
F_22 ( V_13 ) ;
if ( F_60 ( V_122 ,
& F_11 ( V_13 ) -> V_71 ) ) {
struct V_27 * V_98 = F_11 ( V_13 ) -> V_98 ;
V_120 . V_121 = F_14 ( V_234 ) ;
V_120 . V_126 = F_14 ( V_235 ) ;
if ( V_98 )
V_98 -> V_101 ( V_98 , 0 ) ;
} else {
F_18 ( V_14 , V_49 ) ;
V_120 . V_121 = F_14 ( V_236 ) ;
V_120 . V_126 = F_14 ( V_127 ) ;
}
F_23 ( V_13 ) ;
} else {
V_120 . V_121 = F_14 ( V_234 ) ;
V_120 . V_126 = F_14 ( V_237 ) ;
}
F_71 ( V_3 , V_14 -> V_9 , V_128 ,
sizeof( V_120 ) , & V_120 ) ;
if ( F_60 ( V_238 , & V_14 -> V_104 ) ||
V_120 . V_121 != V_236 ) {
F_39 ( V_14 ) ;
continue;
}
F_50 ( V_238 , & V_14 -> V_104 ) ;
F_71 ( V_3 , F_75 ( V_3 ) , V_239 ,
F_114 ( V_14 , V_233 ) , V_233 ) ;
V_14 -> V_240 ++ ;
}
F_39 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_1 * F_115 ( int V_23 , T_1 V_4 ,
T_4 * V_11 ,
T_4 * V_241 )
{
struct V_1 * V_5 , * V_242 = NULL ;
F_116 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_27 * V_13 = V_5 -> V_13 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_7 == V_4 ) {
int V_243 , V_244 ;
int V_245 , V_246 ;
V_243 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_11 ) ;
V_244 = ! F_10 ( & F_11 ( V_13 ) -> V_241 , V_241 ) ;
if ( V_243 && V_244 ) {
F_117 ( & V_16 ) ;
return V_5 ;
}
V_245 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_247 ) ;
V_246 = ! F_10 ( & F_11 ( V_13 ) -> V_241 , V_247 ) ;
if ( ( V_243 && V_246 ) || ( V_245 && V_244 ) ||
( V_245 && V_246 ) )
V_242 = V_5 ;
}
}
F_117 ( & V_16 ) ;
return V_242 ;
}
static void F_118 ( struct V_2 * V_3 )
{
struct V_27 * V_98 , * V_13 ;
struct V_1 * V_14 , * V_248 ;
F_19 ( L_13 ) ;
V_248 = F_115 ( V_115 , V_80 ,
V_3 -> V_11 , V_3 -> V_241 ) ;
if ( ! V_248 )
return;
V_98 = V_248 -> V_13 ;
F_22 ( V_98 ) ;
if ( F_119 ( V_98 ) ) {
F_19 ( L_14 , V_98 -> V_249 ) ;
goto V_250;
}
V_14 = V_248 -> V_24 -> V_251 ( V_248 -> V_26 ) ;
if ( ! V_14 )
goto V_250;
V_13 = V_14 -> V_13 ;
F_120 ( V_3 -> V_76 ) ;
F_121 ( & F_11 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_121 ( & F_11 ( V_13 ) -> V_241 , V_3 -> V_241 ) ;
F_122 ( V_98 , V_13 ) ;
F_54 ( V_3 , V_14 ) ;
F_69 ( V_14 , V_13 -> V_117 ) ;
F_18 ( V_14 , V_48 ) ;
V_98 -> V_101 ( V_98 , 0 ) ;
V_250:
F_23 ( V_98 ) ;
}
static void F_123 ( struct V_2 * V_3 )
{
struct V_1 * V_14 ;
F_19 ( L_12 , V_3 ) ;
if ( ! V_3 -> V_76 -> V_252 && V_3 -> V_76 -> type == V_77 )
F_118 ( V_3 ) ;
if ( V_3 -> V_76 -> V_252 && V_3 -> V_76 -> type == V_77 )
F_124 ( V_3 , V_3 -> V_76 -> V_253 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
F_6 ( V_14 ) ;
if ( V_3 -> V_76 -> type == V_77 ) {
if ( F_124 ( V_3 , V_14 -> V_52 ) )
F_109 ( V_14 ) ;
} else if ( V_14 -> V_74 != V_75 ) {
struct V_27 * V_13 = V_14 -> V_13 ;
F_56 ( V_14 ) ;
F_22 ( V_13 ) ;
F_18 ( V_14 , V_48 ) ;
V_13 -> V_102 ( V_13 ) ;
F_23 ( V_13 ) ;
} else if ( V_14 -> V_23 == V_51 )
F_110 ( V_14 ) ;
F_39 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static void F_125 ( struct V_2 * V_3 , int V_15 )
{
struct V_1 * V_14 ;
F_19 ( L_12 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
if ( F_60 ( V_254 , & V_14 -> V_71 ) )
F_24 ( V_14 , V_15 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static void F_126 ( struct V_44 * V_45 )
{
struct V_2 * V_3 = F_37 ( V_45 , struct V_2 ,
V_220 . V_45 ) ;
V_3 -> V_214 |= V_216 ;
V_3 -> V_219 = 0 ;
F_113 ( V_3 ) ;
}
static void F_127 ( struct V_153 * V_76 , int V_15 )
{
struct V_2 * V_3 = V_76 -> V_255 ;
struct V_1 * V_14 , * V_110 ;
if ( ! V_3 )
return;
F_19 ( L_15 , V_76 , V_3 , V_15 ) ;
F_128 ( V_3 -> V_256 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_65 (chan, l, &conn->chan_l, list) {
F_53 ( V_14 ) ;
F_6 ( V_14 ) ;
F_55 ( V_14 , V_15 ) ;
F_39 ( V_14 ) ;
V_14 -> V_24 -> V_55 ( V_14 -> V_26 ) ;
F_40 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
F_129 ( V_3 -> V_152 ) ;
if ( V_3 -> V_214 & V_215 )
F_130 ( & V_3 -> V_220 ) ;
if ( F_96 ( V_257 , & V_76 -> V_71 ) ) {
F_130 ( & V_3 -> V_258 ) ;
F_131 ( V_3 ) ;
}
V_76 -> V_255 = NULL ;
F_30 ( V_3 ) ;
}
static void F_132 ( struct V_44 * V_45 )
{
struct V_2 * V_3 = F_37 ( V_45 , struct V_2 ,
V_258 . V_45 ) ;
F_19 ( L_12 , V_3 ) ;
if ( F_96 ( V_257 , & V_3 -> V_76 -> V_71 ) ) {
F_131 ( V_3 ) ;
F_127 ( V_3 -> V_76 , V_54 ) ;
}
}
static struct V_2 * F_133 ( struct V_153 * V_76 , T_2 V_126 )
{
struct V_2 * V_3 = V_76 -> V_255 ;
struct V_259 * V_152 ;
if ( V_3 || V_126 )
return V_3 ;
V_152 = F_134 ( V_76 ) ;
if ( ! V_152 )
return NULL ;
V_3 = F_42 ( sizeof( struct V_2 ) , V_56 ) ;
if ( ! V_3 ) {
F_129 ( V_152 ) ;
return NULL ;
}
V_76 -> V_255 = V_3 ;
V_3 -> V_76 = V_76 ;
V_3 -> V_152 = V_152 ;
F_19 ( L_16 , V_76 , V_3 , V_152 ) ;
if ( V_76 -> V_145 -> V_260 && V_76 -> type == V_77 )
V_3 -> V_261 = V_76 -> V_145 -> V_260 ;
else
V_3 -> V_261 = V_76 -> V_145 -> V_262 ;
V_3 -> V_11 = & V_76 -> V_145 -> V_263 ;
V_3 -> V_241 = & V_76 -> V_241 ;
V_3 -> V_223 = 0 ;
F_135 ( & V_3 -> V_57 ) ;
F_43 ( & V_3 -> V_8 ) ;
F_136 ( & V_3 -> V_97 ) ;
if ( V_76 -> type == V_77 )
F_45 ( & V_3 -> V_258 , F_132 ) ;
else
F_45 ( & V_3 -> V_220 , F_126 ) ;
V_3 -> V_72 = V_73 ;
return V_3 ;
}
static struct V_1 * F_137 ( int V_23 , T_3 V_10 ,
T_4 * V_11 ,
T_4 * V_241 )
{
struct V_1 * V_5 , * V_242 = NULL ;
F_116 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_27 * V_13 = V_5 -> V_13 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_10 == V_10 ) {
int V_243 , V_244 ;
int V_245 , V_246 ;
V_243 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_11 ) ;
V_244 = ! F_10 ( & F_11 ( V_13 ) -> V_241 , V_241 ) ;
if ( V_243 && V_244 ) {
F_117 ( & V_16 ) ;
return V_5 ;
}
V_245 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_247 ) ;
V_246 = ! F_10 ( & F_11 ( V_13 ) -> V_241 , V_247 ) ;
if ( ( V_243 && V_246 ) || ( V_245 && V_244 ) ||
( V_245 && V_246 ) )
V_242 = V_5 ;
}
}
F_117 ( & V_16 ) ;
return V_242 ;
}
int F_138 ( struct V_1 * V_14 , T_3 V_10 , T_1 V_4 ,
T_4 * V_241 , T_2 V_264 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
T_4 * V_11 = & F_11 ( V_13 ) -> V_11 ;
struct V_2 * V_3 ;
struct V_153 * V_76 ;
struct V_265 * V_145 ;
T_7 V_138 ;
int V_15 ;
F_19 ( L_17 , F_139 ( V_11 ) , F_139 ( V_241 ) ,
V_264 , F_52 ( V_14 -> V_10 ) ) ;
V_145 = F_140 ( V_241 , V_11 ) ;
if ( ! V_145 )
return - V_266 ;
F_141 ( V_145 ) ;
F_6 ( V_14 ) ;
if ( ( F_52 ( V_10 ) & 0x0101 ) != 0x0001 && ! V_4 &&
V_14 -> V_74 != V_129 ) {
V_15 = - V_20 ;
goto V_18;
}
if ( V_14 -> V_74 == V_75 && ! ( V_10 || V_4 ) ) {
V_15 = - V_20 ;
goto V_18;
}
switch ( V_14 -> V_107 ) {
case V_267 :
break;
case V_108 :
case V_229 :
if ( ! V_226 )
break;
default:
V_15 = - V_268 ;
goto V_18;
}
F_22 ( V_13 ) ;
switch ( V_13 -> V_269 ) {
case V_51 :
case V_118 :
case V_49 :
V_15 = 0 ;
F_23 ( V_13 ) ;
goto V_18;
case V_48 :
V_15 = - V_270 ;
F_23 ( V_13 ) ;
goto V_18;
case V_60 :
case V_271 :
break;
default:
V_15 = - V_272 ;
F_23 ( V_13 ) ;
goto V_18;
}
F_121 ( & F_11 ( V_13 ) -> V_241 , V_241 ) ;
F_23 ( V_13 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_4 ;
V_138 = F_72 ( V_14 ) ;
if ( V_14 -> V_6 == V_80 )
V_76 = F_142 ( V_145 , V_77 , V_241 , V_264 ,
V_14 -> V_52 , V_138 ) ;
else
V_76 = F_142 ( V_145 , V_116 , V_241 , V_264 ,
V_14 -> V_52 , V_138 ) ;
if ( F_143 ( V_76 ) ) {
V_15 = F_144 ( V_76 ) ;
goto V_18;
}
V_3 = F_133 ( V_76 , 0 ) ;
if ( ! V_3 ) {
F_57 ( V_76 ) ;
V_15 = - V_36 ;
goto V_18;
}
if ( V_76 -> type == V_77 ) {
V_15 = 0 ;
if ( ! F_145 ( & V_3 -> V_97 ) ) {
V_15 = - V_273 ;
F_57 ( V_76 ) ;
}
if ( V_15 )
goto V_18;
}
F_121 ( V_11 , V_3 -> V_11 ) ;
F_39 ( V_14 ) ;
F_54 ( V_3 , V_14 ) ;
F_6 ( V_14 ) ;
F_21 ( V_14 , V_51 ) ;
F_69 ( V_14 , V_13 -> V_117 ) ;
if ( V_76 -> V_23 == V_48 ) {
if ( V_14 -> V_74 != V_75 ) {
F_56 ( V_14 ) ;
if ( F_73 ( V_14 ) )
F_21 ( V_14 , V_48 ) ;
} else
F_110 ( V_14 ) ;
}
V_15 = 0 ;
V_18:
F_39 ( V_14 ) ;
F_146 ( V_145 ) ;
F_147 ( V_145 ) ;
return V_15 ;
}
int F_148 ( struct V_27 * V_13 )
{
struct V_1 * V_14 = F_68 ( V_13 ) -> V_14 ;
F_149 ( V_274 , V_275 ) ;
int V_15 = 0 ;
int V_276 = V_277 / 5 ;
F_150 ( F_151 ( V_13 ) , & V_274 ) ;
F_152 ( V_278 ) ;
while ( V_14 -> V_279 > 0 && V_14 -> V_3 ) {
if ( ! V_276 )
V_276 = V_277 / 5 ;
if ( F_153 ( V_275 ) ) {
V_15 = F_154 ( V_276 ) ;
break;
}
F_23 ( V_13 ) ;
V_276 = F_155 ( V_276 ) ;
F_22 ( V_13 ) ;
F_152 ( V_278 ) ;
V_15 = F_156 ( V_13 ) ;
if ( V_15 )
break;
}
F_152 ( V_280 ) ;
F_157 ( F_151 ( V_13 ) , & V_274 ) ;
return V_15 ;
}
static void F_158 ( struct V_44 * V_45 )
{
struct V_1 * V_14 = F_37 ( V_45 , struct V_1 ,
V_281 . V_45 ) ;
F_19 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
if ( V_14 -> V_282 >= V_14 -> V_283 ) {
F_70 ( V_14 -> V_3 , V_14 , V_284 ) ;
F_39 ( V_14 ) ;
F_40 ( V_14 ) ;
return;
}
V_14 -> V_282 ++ ;
F_159 ( V_14 ) ;
F_104 ( V_14 , V_167 ) ;
F_39 ( V_14 ) ;
F_40 ( V_14 ) ;
}
static void F_160 ( struct V_44 * V_45 )
{
struct V_1 * V_14 = F_37 ( V_45 , struct V_1 ,
V_285 . V_45 ) ;
F_19 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
V_14 -> V_282 = 1 ;
F_159 ( V_14 ) ;
F_50 ( V_286 , & V_14 -> V_203 ) ;
F_104 ( V_14 , V_167 ) ;
F_39 ( V_14 ) ;
F_40 ( V_14 ) ;
}
static void F_161 ( struct V_1 * V_14 )
{
struct V_143 * V_144 ;
while ( ( V_144 = F_162 ( & V_14 -> V_106 ) ) &&
V_14 -> V_279 ) {
if ( F_80 ( V_144 ) -> V_157 . V_173 == V_14 -> V_287 )
break;
V_144 = F_163 ( & V_14 -> V_106 ) ;
F_128 ( V_144 ) ;
V_14 -> V_279 -- ;
}
if ( ! V_14 -> V_279 )
F_62 ( V_14 ) ;
}
static void F_164 ( struct V_1 * V_14 )
{
struct V_143 * V_144 ;
T_8 V_157 ;
T_1 V_62 ;
while ( ( V_144 = F_163 ( & V_14 -> V_106 ) ) ) {
V_157 = F_165 ( V_14 , V_144 -> V_26 + V_194 ) ;
V_157 |= F_166 ( V_14 , V_14 -> V_288 ) ;
V_157 |= F_167 ( V_14 , F_80 ( V_144 ) -> V_157 . V_172 ) ;
F_101 ( V_14 , V_157 , V_144 -> V_26 + V_194 ) ;
if ( V_14 -> V_62 == V_63 ) {
V_62 = F_103 ( 0 , ( T_2 * ) V_144 -> V_26 ,
V_144 -> V_142 - V_201 ) ;
F_92 ( V_62 ,
V_144 -> V_26 + V_144 -> V_142 - V_201 ) ;
}
F_82 ( V_14 , V_144 ) ;
V_14 -> V_288 = F_168 ( V_14 , V_14 -> V_288 ) ;
}
}
static void F_169 ( struct V_1 * V_14 , T_1 V_289 )
{
struct V_143 * V_144 , * V_290 ;
T_1 V_62 ;
T_8 V_157 ;
V_144 = F_162 ( & V_14 -> V_106 ) ;
if ( ! V_144 )
return;
while ( F_80 ( V_144 ) -> V_157 . V_173 != V_289 ) {
if ( F_170 ( & V_14 -> V_106 , V_144 ) )
return;
V_144 = F_171 ( & V_14 -> V_106 , V_144 ) ;
}
if ( F_80 ( V_144 ) -> V_157 . V_291 == V_14 -> V_283 &&
V_14 -> V_283 ) {
F_70 ( V_14 -> V_3 , V_14 , V_284 ) ;
return;
}
V_290 = F_172 ( V_144 , V_56 ) ;
F_80 ( V_144 ) -> V_157 . V_291 ++ ;
V_157 = F_165 ( V_14 , V_290 -> V_26 + V_194 ) ;
V_157 &= F_173 ( V_14 ) ;
if ( F_96 ( V_202 , & V_14 -> V_203 ) )
V_157 |= F_97 ( V_14 ) ;
V_157 |= F_106 ( V_14 , V_14 -> V_209 ) ;
V_157 |= F_166 ( V_14 , V_289 ) ;
F_101 ( V_14 , V_157 , V_290 -> V_26 + V_194 ) ;
if ( V_14 -> V_62 == V_63 ) {
V_62 = F_103 ( 0 , ( T_2 * ) V_290 -> V_26 ,
V_290 -> V_142 - V_201 ) ;
F_92 ( V_62 ,
V_290 -> V_26 + V_290 -> V_142 - V_201 ) ;
}
F_82 ( V_14 , V_290 ) ;
}
static int F_174 ( struct V_1 * V_14 )
{
struct V_143 * V_144 , * V_290 ;
T_1 V_62 ;
T_8 V_157 ;
int V_292 = 0 ;
if ( V_14 -> V_23 != V_48 )
return - V_293 ;
if ( F_60 ( V_294 , & V_14 -> V_203 ) )
return 0 ;
while ( ( V_144 = V_14 -> V_295 ) && ( ! F_175 ( V_14 ) ) ) {
if ( F_80 ( V_144 ) -> V_157 . V_291 == V_14 -> V_283 &&
V_14 -> V_283 ) {
F_70 ( V_14 -> V_3 , V_14 , V_284 ) ;
break;
}
V_290 = F_172 ( V_144 , V_56 ) ;
F_80 ( V_144 ) -> V_157 . V_291 ++ ;
V_157 = F_165 ( V_14 , V_290 -> V_26 + V_194 ) ;
V_157 &= F_173 ( V_14 ) ;
if ( F_96 ( V_202 , & V_14 -> V_203 ) )
V_157 |= F_97 ( V_14 ) ;
V_157 |= F_106 ( V_14 , V_14 -> V_209 ) ;
V_157 |= F_166 ( V_14 , V_14 -> V_288 ) ;
V_157 |= F_167 ( V_14 , F_80 ( V_144 ) -> V_157 . V_172 ) ;
F_101 ( V_14 , V_157 , V_290 -> V_26 + V_194 ) ;
if ( V_14 -> V_62 == V_63 ) {
V_62 = F_103 ( 0 , ( T_2 * ) V_144 -> V_26 ,
V_290 -> V_142 - V_201 ) ;
F_92 ( V_62 , V_144 -> V_26 +
V_290 -> V_142 - V_201 ) ;
}
F_82 ( V_14 , V_290 ) ;
F_176 ( V_14 ) ;
F_80 ( V_144 ) -> V_157 . V_173 = V_14 -> V_288 ;
V_14 -> V_288 = F_168 ( V_14 , V_14 -> V_288 ) ;
if ( F_80 ( V_144 ) -> V_157 . V_291 == 1 ) {
V_14 -> V_279 ++ ;
if ( ! V_292 ++ )
F_64 ( V_14 ) ;
}
V_14 -> V_296 ++ ;
if ( F_170 ( & V_14 -> V_106 , V_144 ) )
V_14 -> V_295 = NULL ;
else
V_14 -> V_295 = F_171 ( & V_14 -> V_106 , V_144 ) ;
}
return V_292 ;
}
static int F_177 ( struct V_1 * V_14 )
{
int V_297 ;
if ( ! F_178 ( & V_14 -> V_106 ) )
V_14 -> V_295 = V_14 -> V_106 . V_298 ;
V_14 -> V_288 = V_14 -> V_287 ;
V_297 = F_174 ( V_14 ) ;
return V_297 ;
}
static void F_179 ( struct V_1 * V_14 )
{
T_8 V_157 = 0 ;
V_157 |= F_106 ( V_14 , V_14 -> V_209 ) ;
if ( F_60 ( V_205 , & V_14 -> V_203 ) ) {
V_157 |= F_105 ( V_14 , V_206 ) ;
F_50 ( V_207 , & V_14 -> V_203 ) ;
F_93 ( V_14 , V_157 ) ;
return;
}
if ( F_174 ( V_14 ) > 0 )
return;
V_157 |= F_105 ( V_14 , V_208 ) ;
F_93 ( V_14 , V_157 ) ;
}
static void F_180 ( struct V_1 * V_14 )
{
F_64 ( V_14 ) ;
F_179 ( V_14 ) ;
}
static void F_181 ( struct V_1 * V_14 )
{
struct V_109 * V_40 ;
T_8 V_157 ;
V_157 = F_105 ( V_14 , V_299 ) ;
V_157 |= F_97 ( V_14 ) ;
V_40 = F_182 ( ( & V_14 -> V_300 ) -> V_43 , struct V_109 , V_34 ) ;
V_157 |= F_106 ( V_14 , V_40 -> V_289 ) ;
F_93 ( V_14 , V_157 ) ;
}
static inline int F_183 ( struct V_1 * V_14 ,
struct V_301 * V_302 , int V_142 ,
int V_197 , struct V_143 * V_144 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_143 * * V_303 ;
int V_304 = 0 ;
if ( F_184 ( F_100 ( V_144 , V_197 ) , V_302 -> V_305 , V_197 ) )
return - V_306 ;
V_304 += V_197 ;
V_142 -= V_197 ;
V_303 = & F_185 ( V_144 ) -> V_307 ;
while ( V_142 ) {
struct V_143 * V_111 ;
V_197 = F_94 (unsigned int, conn->mtu, len) ;
V_111 = V_14 -> V_24 -> V_308 ( V_14 , V_197 ,
V_302 -> V_309 & V_310 ) ;
if ( F_143 ( V_111 ) )
return F_144 ( V_111 ) ;
* V_303 = V_111 ;
if ( F_184 ( F_100 ( * V_303 , V_197 ) , V_302 -> V_305 , V_197 ) )
return - V_306 ;
( * V_303 ) -> V_150 = V_144 -> V_150 ;
V_304 += V_197 ;
V_142 -= V_197 ;
V_144 -> V_142 += ( * V_303 ) -> V_142 ;
V_144 -> V_311 += ( * V_303 ) -> V_142 ;
V_303 = & ( * V_303 ) -> V_298 ;
}
return V_304 ;
}
static struct V_143 * F_186 ( struct V_1 * V_14 ,
struct V_301 * V_302 , T_6 V_142 ,
T_8 V_150 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_143 * V_144 ;
int V_15 , V_197 , V_198 = V_194 + V_312 ;
struct V_195 * V_196 ;
F_19 ( L_18 , V_14 , ( int ) V_142 , V_150 ) ;
V_197 = F_94 (unsigned int, (conn->mtu - hlen), len) ;
V_144 = V_14 -> V_24 -> V_308 ( V_14 , V_197 + V_198 ,
V_302 -> V_309 & V_310 ) ;
if ( F_143 ( V_144 ) )
return V_144 ;
V_144 -> V_150 = V_150 ;
V_196 = (struct V_195 * ) F_100 ( V_144 , V_194 ) ;
V_196 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_196 -> V_142 = F_14 ( V_142 + V_312 ) ;
F_187 ( V_14 -> V_10 , F_100 ( V_144 , V_312 ) ) ;
V_15 = F_183 ( V_14 , V_302 , V_142 , V_197 , V_144 ) ;
if ( F_188 ( V_15 < 0 ) ) {
F_128 ( V_144 ) ;
return F_189 ( V_15 ) ;
}
return V_144 ;
}
static struct V_143 * F_190 ( struct V_1 * V_14 ,
struct V_301 * V_302 , T_6 V_142 ,
T_8 V_150 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_143 * V_144 ;
int V_15 , V_197 ;
struct V_195 * V_196 ;
F_19 ( L_19 , V_14 , ( int ) V_142 ) ;
V_197 = F_94 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_144 = V_14 -> V_24 -> V_308 ( V_14 , V_197 + V_194 ,
V_302 -> V_309 & V_310 ) ;
if ( F_143 ( V_144 ) )
return V_144 ;
V_144 -> V_150 = V_150 ;
V_196 = (struct V_195 * ) F_100 ( V_144 , V_194 ) ;
V_196 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_196 -> V_142 = F_14 ( V_142 ) ;
V_15 = F_183 ( V_14 , V_302 , V_142 , V_197 , V_144 ) ;
if ( F_188 ( V_15 < 0 ) ) {
F_128 ( V_144 ) ;
return F_189 ( V_15 ) ;
}
return V_144 ;
}
static struct V_143 * F_191 ( struct V_1 * V_14 ,
struct V_301 * V_302 , T_6 V_142 ,
T_1 V_313 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_143 * V_144 ;
int V_15 , V_197 , V_198 ;
struct V_195 * V_196 ;
F_19 ( L_19 , V_14 , ( int ) V_142 ) ;
if ( ! V_3 )
return F_189 ( - V_293 ) ;
if ( F_60 ( V_192 , & V_14 -> V_71 ) )
V_198 = V_199 ;
else
V_198 = V_200 ;
if ( V_313 )
V_198 += V_314 ;
if ( V_14 -> V_62 == V_63 )
V_198 += V_201 ;
V_197 = F_94 (unsigned int, (conn->mtu - hlen), len) ;
V_144 = V_14 -> V_24 -> V_308 ( V_14 , V_197 + V_198 ,
V_302 -> V_309 & V_310 ) ;
if ( F_143 ( V_144 ) )
return V_144 ;
V_196 = (struct V_195 * ) F_100 ( V_144 , V_194 ) ;
V_196 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_196 -> V_142 = F_14 ( V_142 + ( V_198 - V_194 ) ) ;
F_101 ( V_14 , 0 , F_100 ( V_144 , F_102 ( V_14 ) ) ) ;
if ( V_313 )
F_92 ( V_313 , F_100 ( V_144 , V_314 ) ) ;
V_15 = F_183 ( V_14 , V_302 , V_142 , V_197 , V_144 ) ;
if ( F_188 ( V_15 < 0 ) ) {
F_128 ( V_144 ) ;
return F_189 ( V_15 ) ;
}
if ( V_14 -> V_62 == V_63 )
F_92 ( 0 , F_100 ( V_144 , V_201 ) ) ;
F_80 ( V_144 ) -> V_157 . V_291 = 0 ;
return V_144 ;
}
static int F_192 ( struct V_1 * V_14 ,
struct V_315 * V_316 ,
struct V_301 * V_302 , T_6 V_142 )
{
struct V_143 * V_144 ;
T_1 V_317 ;
T_6 V_318 ;
int V_15 = 0 ;
T_2 V_172 ;
F_19 ( L_20 , V_14 , V_302 , ( int ) V_142 ) ;
V_318 = V_14 -> V_3 -> V_261 ;
V_318 = F_94 ( T_6 , V_318 , V_319 ) ;
V_318 -= V_199 + V_201 ;
V_318 = F_94 ( T_6 , V_318 , V_14 -> V_320 ) ;
if ( V_142 <= V_318 ) {
V_172 = V_321 ;
V_317 = 0 ;
V_318 = V_142 ;
} else {
V_172 = V_322 ;
V_317 = V_142 ;
V_318 -= V_314 ;
}
while ( V_142 > 0 ) {
V_144 = F_191 ( V_14 , V_302 , V_318 , V_317 ) ;
if ( F_143 ( V_144 ) ) {
F_193 ( V_316 ) ;
return F_144 ( V_144 ) ;
}
F_80 ( V_144 ) -> V_157 . V_172 = V_172 ;
F_194 ( V_316 , V_144 ) ;
V_142 -= V_318 ;
if ( V_317 ) {
V_317 = 0 ;
V_318 += V_314 ;
}
if ( V_142 <= V_318 ) {
V_172 = V_323 ;
V_318 = V_142 ;
} else {
V_172 = V_324 ;
}
}
return V_15 ;
}
int F_195 ( struct V_1 * V_14 , struct V_301 * V_302 , T_6 V_142 ,
T_8 V_150 )
{
struct V_143 * V_144 ;
int V_15 ;
struct V_315 V_316 ;
if ( V_14 -> V_74 == V_82 ) {
V_144 = F_186 ( V_14 , V_302 , V_142 , V_150 ) ;
if ( F_143 ( V_144 ) )
return F_144 ( V_144 ) ;
F_82 ( V_14 , V_144 ) ;
return V_142 ;
}
switch ( V_14 -> V_107 ) {
case V_267 :
if ( V_142 > V_14 -> V_78 )
return - V_325 ;
V_144 = F_190 ( V_14 , V_302 , V_142 , V_150 ) ;
if ( F_143 ( V_144 ) )
return F_144 ( V_144 ) ;
F_82 ( V_14 , V_144 ) ;
V_15 = V_142 ;
break;
case V_108 :
case V_229 :
if ( V_142 > V_14 -> V_78 ) {
V_15 = - V_325 ;
break;
}
F_196 ( & V_316 ) ;
V_15 = F_192 ( V_14 , & V_316 , V_302 , V_142 ) ;
if ( V_14 -> V_23 != V_48 ) {
F_193 ( & V_316 ) ;
V_15 = - V_293 ;
}
if ( V_15 )
break;
if ( V_14 -> V_107 == V_108 && V_14 -> V_295 == NULL )
V_14 -> V_295 = V_316 . V_298 ;
F_197 ( & V_316 , & V_14 -> V_106 ) ;
if ( V_14 -> V_107 == V_108 )
V_15 = F_174 ( V_14 ) ;
else
F_164 ( V_14 ) ;
if ( V_15 >= 0 )
V_15 = V_142 ;
F_193 ( & V_316 ) ;
break;
default:
F_19 ( L_21 , V_14 -> V_107 ) ;
V_15 = - V_272 ;
}
return V_15 ;
}
static void F_198 ( struct V_2 * V_3 , struct V_143 * V_144 )
{
struct V_143 * V_326 ;
struct V_1 * V_14 ;
F_19 ( L_12 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
struct V_27 * V_13 = V_14 -> V_13 ;
if ( V_14 -> V_74 != V_129 )
continue;
if ( V_144 -> V_13 == V_13 )
continue;
V_326 = F_172 ( V_144 , V_56 ) ;
if ( ! V_326 )
continue;
if ( V_14 -> V_24 -> V_327 ( V_14 -> V_26 , V_326 ) )
F_128 ( V_326 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_143 * F_78 ( struct V_2 * V_3 ,
T_2 V_141 , T_2 V_9 , T_1 V_328 , void * V_26 )
{
struct V_143 * V_144 , * * V_303 ;
struct V_329 * V_330 ;
struct V_195 * V_196 ;
int V_142 , V_197 ;
F_19 ( L_22 ,
V_3 , V_141 , V_9 , V_328 ) ;
V_142 = V_194 + V_331 + V_328 ;
V_197 = F_94 (unsigned int, conn->mtu, len) ;
V_144 = F_99 ( V_197 , V_56 ) ;
if ( ! V_144 )
return NULL ;
V_196 = (struct V_195 * ) F_100 ( V_144 , V_194 ) ;
V_196 -> V_142 = F_14 ( V_331 + V_328 ) ;
if ( V_3 -> V_76 -> type == V_77 )
V_196 -> V_4 = F_14 ( V_332 ) ;
else
V_196 -> V_4 = F_14 ( V_84 ) ;
V_330 = (struct V_329 * ) F_100 ( V_144 , V_331 ) ;
V_330 -> V_141 = V_141 ;
V_330 -> V_9 = V_9 ;
V_330 -> V_142 = F_14 ( V_328 ) ;
if ( V_328 ) {
V_197 -= V_194 + V_331 ;
memcpy ( F_100 ( V_144 , V_197 ) , V_26 , V_197 ) ;
V_26 += V_197 ;
}
V_142 -= V_144 -> V_142 ;
V_303 = & F_185 ( V_144 ) -> V_307 ;
while ( V_142 ) {
V_197 = F_94 (unsigned int, conn->mtu, len) ;
* V_303 = F_99 ( V_197 , V_56 ) ;
if ( ! * V_303 )
goto V_333;
memcpy ( F_100 ( * V_303 , V_197 ) , V_26 , V_197 ) ;
V_142 -= V_197 ;
V_26 += V_197 ;
V_303 = & ( * V_303 ) -> V_298 ;
}
return V_144 ;
V_333:
F_128 ( V_144 ) ;
return NULL ;
}
static inline int F_199 ( void * * V_334 , int * type , int * V_335 , unsigned long * V_336 )
{
struct V_337 * V_338 = * V_334 ;
int V_142 ;
V_142 = V_339 + V_338 -> V_142 ;
* V_334 += V_142 ;
* type = V_338 -> type ;
* V_335 = V_338 -> V_142 ;
switch ( V_338 -> V_142 ) {
case 1 :
* V_336 = * ( ( T_2 * ) V_338 -> V_336 ) ;
break;
case 2 :
* V_336 = F_87 ( V_338 -> V_336 ) ;
break;
case 4 :
* V_336 = F_86 ( V_338 -> V_336 ) ;
break;
default:
* V_336 = ( unsigned long ) V_338 -> V_336 ;
break;
}
F_19 ( L_23 , * type , V_338 -> V_142 , * V_336 ) ;
return V_142 ;
}
static void F_200 ( void * * V_334 , T_2 type , T_2 V_142 , unsigned long V_336 )
{
struct V_337 * V_338 = * V_334 ;
F_19 ( L_23 , type , V_142 , V_336 ) ;
V_338 -> type = type ;
V_338 -> V_142 = V_142 ;
switch ( V_142 ) {
case 1 :
* ( ( T_2 * ) V_338 -> V_336 ) = V_336 ;
break;
case 2 :
F_92 ( V_336 , V_338 -> V_336 ) ;
break;
case 4 :
F_91 ( V_336 , V_338 -> V_336 ) ;
break;
default:
memcpy ( V_338 -> V_336 , ( void * ) V_336 , V_142 ) ;
break;
}
* V_334 += V_339 + V_142 ;
}
static void F_201 ( void * * V_334 , struct V_1 * V_14 )
{
struct V_340 V_341 ;
switch ( V_14 -> V_107 ) {
case V_108 :
V_341 . V_139 = V_14 -> V_85 ;
V_341 . V_342 = V_14 -> V_87 ;
V_341 . V_343 = F_14 ( V_14 -> V_89 ) ;
V_341 . V_344 = F_202 ( V_14 -> V_91 ) ;
V_341 . V_345 = F_202 ( V_94 ) ;
V_341 . V_346 = F_202 ( V_96 ) ;
break;
case V_229 :
V_341 . V_139 = 1 ;
V_341 . V_342 = V_88 ;
V_341 . V_343 = F_14 ( V_14 -> V_89 ) ;
V_341 . V_344 = F_202 ( V_14 -> V_91 ) ;
V_341 . V_345 = 0 ;
V_341 . V_346 = 0 ;
break;
default:
return;
}
F_200 ( V_334 , V_347 , sizeof( V_341 ) ,
( unsigned long ) & V_341 ) ;
}
static void F_203 ( struct V_44 * V_45 )
{
struct V_1 * V_14 = F_37 ( V_45 , struct V_1 ,
V_348 . V_45 ) ;
F_19 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
F_179 ( V_14 ) ;
F_39 ( V_14 ) ;
F_40 ( V_14 ) ;
}
static inline int F_204 ( struct V_1 * V_14 )
{
int V_15 ;
V_14 -> V_288 = 0 ;
V_14 -> V_349 = 0 ;
V_14 -> V_287 = 0 ;
V_14 -> V_279 = 0 ;
V_14 -> V_209 = 0 ;
V_14 -> V_350 = 0 ;
V_14 -> V_296 = 0 ;
V_14 -> V_351 = 0 ;
V_14 -> V_352 = NULL ;
V_14 -> V_353 = NULL ;
V_14 -> V_317 = 0 ;
F_205 ( & V_14 -> V_106 ) ;
if ( V_14 -> V_107 != V_108 )
return 0 ;
V_14 -> V_354 = V_355 ;
V_14 -> V_356 = V_357 ;
F_45 ( & V_14 -> V_285 , F_160 ) ;
F_45 ( & V_14 -> V_281 , F_158 ) ;
F_45 ( & V_14 -> V_348 , F_203 ) ;
F_205 ( & V_14 -> V_112 ) ;
F_136 ( & V_14 -> V_300 ) ;
V_15 = F_26 ( & V_14 -> V_109 , V_14 -> V_66 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_26 ( & V_14 -> V_113 , V_14 -> V_358 ) ;
}
static inline T_7 F_206 ( T_7 V_107 , T_5 V_359 )
{
switch ( V_107 ) {
case V_229 :
case V_108 :
if ( F_112 ( V_107 , V_359 ) )
return V_107 ;
default:
return V_267 ;
}
}
static inline bool F_207 ( struct V_1 * V_14 )
{
return V_360 && V_14 -> V_3 -> V_223 & V_361 ;
}
static inline bool F_208 ( struct V_1 * V_14 )
{
return V_360 && V_14 -> V_3 -> V_223 & V_362 ;
}
static inline void F_209 ( struct V_1 * V_14 )
{
if ( V_14 -> V_66 > V_67 &&
F_207 ( V_14 ) ) {
F_50 ( V_192 , & V_14 -> V_71 ) ;
V_14 -> V_68 = V_363 ;
} else {
V_14 -> V_66 = F_94 ( T_1 , V_14 -> V_66 ,
V_67 ) ;
V_14 -> V_68 = V_67 ;
}
}
static int F_114 ( struct V_1 * V_14 , void * V_26 )
{
struct V_364 * V_212 = V_26 ;
struct V_365 V_366 = { . V_107 = V_14 -> V_107 } ;
void * V_334 = V_212 -> V_26 ;
T_1 V_31 ;
F_19 ( L_3 , V_14 ) ;
if ( V_14 -> V_240 || V_14 -> V_367 )
goto V_18;
switch ( V_14 -> V_107 ) {
case V_229 :
case V_108 :
if ( F_60 ( V_232 , & V_14 -> V_104 ) )
break;
if ( F_208 ( V_14 ) )
F_50 ( V_368 , & V_14 -> V_71 ) ;
default:
V_14 -> V_107 = F_206 ( V_366 . V_107 , V_14 -> V_3 -> V_223 ) ;
break;
}
V_18:
if ( V_14 -> V_369 != V_81 )
F_200 ( & V_334 , V_370 , 2 , V_14 -> V_369 ) ;
switch ( V_14 -> V_107 ) {
case V_267 :
if ( ! ( V_14 -> V_3 -> V_223 & V_227 ) &&
! ( V_14 -> V_3 -> V_223 & V_228 ) )
break;
V_366 . V_107 = V_267 ;
V_366 . V_371 = 0 ;
V_366 . V_372 = 0 ;
V_366 . V_373 = 0 ;
V_366 . V_374 = 0 ;
V_366 . V_375 = 0 ;
F_200 ( & V_334 , V_376 , sizeof( V_366 ) ,
( unsigned long ) & V_366 ) ;
break;
case V_108 :
V_366 . V_107 = V_108 ;
V_366 . V_372 = V_14 -> V_64 ;
V_366 . V_373 = 0 ;
V_366 . V_374 = 0 ;
V_31 = F_94 ( T_1 , V_377 , V_14 -> V_3 -> V_261 -
V_199 -
V_314 -
V_201 ) ;
V_366 . V_375 = F_14 ( V_31 ) ;
F_209 ( V_14 ) ;
V_366 . V_371 = F_94 ( T_1 , V_14 -> V_66 ,
V_67 ) ;
F_200 ( & V_334 , V_376 , sizeof( V_366 ) ,
( unsigned long ) & V_366 ) ;
if ( F_60 ( V_368 , & V_14 -> V_71 ) )
F_201 ( & V_334 , V_14 ) ;
if ( ! ( V_14 -> V_3 -> V_223 & V_378 ) )
break;
if ( V_14 -> V_62 == V_379 ||
F_60 ( V_380 , & V_14 -> V_104 ) ) {
V_14 -> V_62 = V_379 ;
F_200 ( & V_334 , V_381 , 1 , V_14 -> V_62 ) ;
}
if ( F_60 ( V_192 , & V_14 -> V_71 ) )
F_200 ( & V_334 , V_382 , 2 ,
V_14 -> V_66 ) ;
break;
case V_229 :
V_366 . V_107 = V_229 ;
V_366 . V_371 = 0 ;
V_366 . V_372 = 0 ;
V_366 . V_373 = 0 ;
V_366 . V_374 = 0 ;
V_31 = F_94 ( T_1 , V_377 , V_14 -> V_3 -> V_261 -
V_199 -
V_314 -
V_201 ) ;
V_366 . V_375 = F_14 ( V_31 ) ;
F_200 ( & V_334 , V_376 , sizeof( V_366 ) ,
( unsigned long ) & V_366 ) ;
if ( F_60 ( V_368 , & V_14 -> V_71 ) )
F_201 ( & V_334 , V_14 ) ;
if ( ! ( V_14 -> V_3 -> V_223 & V_378 ) )
break;
if ( V_14 -> V_62 == V_379 ||
F_60 ( V_380 , & V_14 -> V_104 ) ) {
V_14 -> V_62 = V_379 ;
F_200 ( & V_334 , V_381 , 1 , V_14 -> V_62 ) ;
}
break;
}
V_212 -> V_6 = F_14 ( V_14 -> V_6 ) ;
V_212 -> V_71 = F_14 ( 0 ) ;
return V_334 - V_26 ;
}
static int F_210 ( struct V_1 * V_14 , void * V_26 )
{
struct V_383 * V_120 = V_26 ;
void * V_334 = V_120 -> V_26 ;
void * V_212 = V_14 -> V_384 ;
int V_142 = V_14 -> V_385 ;
int type , V_386 , V_335 ;
unsigned long V_336 ;
struct V_365 V_366 = { . V_107 = V_267 } ;
struct V_340 V_341 ;
T_2 V_387 = 0 ;
T_1 V_261 = V_81 ;
T_1 V_121 = V_388 ;
T_1 V_31 ;
F_19 ( L_3 , V_14 ) ;
while ( V_142 >= V_339 ) {
V_142 -= F_199 ( & V_212 , & type , & V_335 , & V_336 ) ;
V_386 = type & V_389 ;
type &= V_390 ;
switch ( type ) {
case V_370 :
V_261 = V_336 ;
break;
case V_391 :
V_14 -> V_346 = V_336 ;
break;
case V_392 :
break;
case V_376 :
if ( V_335 == sizeof( V_366 ) )
memcpy ( & V_366 , ( void * ) V_336 , V_335 ) ;
break;
case V_381 :
if ( V_336 == V_379 )
F_50 ( V_380 , & V_14 -> V_104 ) ;
break;
case V_347 :
V_387 = 1 ;
if ( V_335 == sizeof( V_341 ) )
memcpy ( & V_341 , ( void * ) V_336 , V_335 ) ;
break;
case V_382 :
if ( ! V_360 )
return - V_50 ;
F_50 ( V_192 , & V_14 -> V_71 ) ;
F_50 ( V_393 , & V_14 -> V_104 ) ;
V_14 -> V_68 = V_363 ;
V_14 -> V_358 = V_336 ;
break;
default:
if ( V_386 )
break;
V_121 = V_394 ;
* ( ( T_2 * ) V_334 ++ ) = type ;
break;
}
}
if ( V_14 -> V_367 || V_14 -> V_240 > 1 )
goto V_18;
switch ( V_14 -> V_107 ) {
case V_229 :
case V_108 :
if ( ! F_60 ( V_232 , & V_14 -> V_104 ) ) {
V_14 -> V_107 = F_206 ( V_366 . V_107 ,
V_14 -> V_3 -> V_223 ) ;
break;
}
if ( V_387 ) {
if ( F_208 ( V_14 ) )
F_50 ( V_368 , & V_14 -> V_71 ) ;
else
return - V_50 ;
}
if ( V_14 -> V_107 != V_366 . V_107 )
return - V_50 ;
break;
}
V_18:
if ( V_14 -> V_107 != V_366 . V_107 ) {
V_121 = V_395 ;
V_366 . V_107 = V_14 -> V_107 ;
if ( V_14 -> V_367 == 1 )
return - V_50 ;
F_200 ( & V_334 , V_376 ,
sizeof( V_366 ) , ( unsigned long ) & V_366 ) ;
}
if ( V_121 == V_388 ) {
if ( V_261 < V_396 )
V_121 = V_395 ;
else {
V_14 -> V_78 = V_261 ;
F_50 ( V_397 , & V_14 -> V_104 ) ;
}
F_200 ( & V_334 , V_370 , 2 , V_14 -> V_78 ) ;
if ( V_387 ) {
if ( V_14 -> V_87 != V_398 &&
V_341 . V_342 != V_398 &&
V_341 . V_342 != V_14 -> V_87 ) {
V_121 = V_395 ;
if ( V_14 -> V_240 >= 1 )
return - V_50 ;
F_200 ( & V_334 , V_347 ,
sizeof( V_341 ) ,
( unsigned long ) & V_341 ) ;
} else {
V_121 = V_399 ;
F_50 ( V_400 , & V_14 -> V_104 ) ;
}
}
switch ( V_366 . V_107 ) {
case V_267 :
V_14 -> V_62 = V_379 ;
F_50 ( V_401 , & V_14 -> V_104 ) ;
break;
case V_108 :
if ( ! F_60 ( V_393 , & V_14 -> V_104 ) )
V_14 -> V_358 = V_366 . V_371 ;
else
V_366 . V_371 = V_67 ;
V_14 -> V_283 = V_366 . V_372 ;
V_31 = F_94 ( T_1 , F_211 ( V_366 . V_375 ) ,
V_14 -> V_3 -> V_261 -
V_199 -
V_314 -
V_201 ) ;
V_366 . V_375 = F_14 ( V_31 ) ;
V_14 -> V_320 = V_31 ;
V_366 . V_373 =
F_212 ( V_402 ) ;
V_366 . V_374 =
F_212 ( V_403 ) ;
F_50 ( V_401 , & V_14 -> V_104 ) ;
F_200 ( & V_334 , V_376 ,
sizeof( V_366 ) , ( unsigned long ) & V_366 ) ;
if ( F_60 ( V_368 , & V_14 -> V_71 ) ) {
V_14 -> V_404 = V_341 . V_139 ;
V_14 -> V_405 = V_341 . V_342 ;
V_14 -> V_406 = F_211 ( V_341 . V_343 ) ;
V_14 -> V_407 =
F_213 ( V_341 . V_346 ) ;
V_14 -> V_408 =
F_213 ( V_341 . V_345 ) ;
V_14 -> V_409 =
F_213 ( V_341 . V_344 ) ;
F_200 ( & V_334 , V_347 ,
sizeof( V_341 ) , ( unsigned long ) & V_341 ) ;
}
break;
case V_229 :
V_31 = F_94 ( T_1 , F_211 ( V_366 . V_375 ) ,
V_14 -> V_3 -> V_261 -
V_199 -
V_314 -
V_201 ) ;
V_366 . V_375 = F_14 ( V_31 ) ;
V_14 -> V_320 = V_31 ;
F_50 ( V_401 , & V_14 -> V_104 ) ;
F_200 ( & V_334 , V_376 ,
sizeof( V_366 ) , ( unsigned long ) & V_366 ) ;
break;
default:
V_121 = V_395 ;
memset ( & V_366 , 0 , sizeof( V_366 ) ) ;
V_366 . V_107 = V_14 -> V_107 ;
}
if ( V_121 == V_388 )
F_50 ( V_103 , & V_14 -> V_104 ) ;
}
V_120 -> V_7 = F_14 ( V_14 -> V_6 ) ;
V_120 -> V_121 = F_14 ( V_121 ) ;
V_120 -> V_71 = F_14 ( 0x0000 ) ;
return V_334 - V_26 ;
}
static int F_214 ( struct V_1 * V_14 , void * V_120 , int V_142 , void * V_26 , T_1 * V_121 )
{
struct V_364 * V_212 = V_26 ;
void * V_334 = V_212 -> V_26 ;
int type , V_335 ;
unsigned long V_336 ;
struct V_365 V_366 = { . V_107 = V_267 } ;
struct V_340 V_341 ;
F_19 ( L_24 , V_14 , V_120 , V_142 , V_26 ) ;
while ( V_142 >= V_339 ) {
V_142 -= F_199 ( & V_120 , & type , & V_335 , & V_336 ) ;
switch ( type ) {
case V_370 :
if ( V_336 < V_396 ) {
* V_121 = V_395 ;
V_14 -> V_369 = V_396 ;
} else
V_14 -> V_369 = V_336 ;
F_200 ( & V_334 , V_370 , 2 , V_14 -> V_369 ) ;
break;
case V_391 :
V_14 -> V_346 = V_336 ;
F_200 ( & V_334 , V_391 ,
2 , V_14 -> V_346 ) ;
break;
case V_376 :
if ( V_335 == sizeof( V_366 ) )
memcpy ( & V_366 , ( void * ) V_336 , V_335 ) ;
if ( F_60 ( V_232 , & V_14 -> V_104 ) &&
V_366 . V_107 != V_14 -> V_107 )
return - V_50 ;
V_14 -> V_62 = 0 ;
F_200 ( & V_334 , V_376 ,
sizeof( V_366 ) , ( unsigned long ) & V_366 ) ;
break;
case V_382 :
V_14 -> V_66 = F_94 ( T_1 , V_336 ,
V_363 ) ;
F_200 ( & V_334 , V_382 , 2 ,
V_14 -> V_66 ) ;
break;
case V_347 :
if ( V_335 == sizeof( V_341 ) )
memcpy ( & V_341 , ( void * ) V_336 , V_335 ) ;
if ( V_14 -> V_87 != V_398 &&
V_341 . V_342 != V_398 &&
V_341 . V_342 != V_14 -> V_87 )
return - V_50 ;
F_200 ( & V_334 , V_347 ,
sizeof( V_341 ) , ( unsigned long ) & V_341 ) ;
break;
}
}
if ( V_14 -> V_107 == V_267 && V_14 -> V_107 != V_366 . V_107 )
return - V_50 ;
V_14 -> V_107 = V_366 . V_107 ;
if ( * V_121 == V_388 || * V_121 == V_399 ) {
switch ( V_366 . V_107 ) {
case V_108 :
V_14 -> V_373 = F_211 ( V_366 . V_373 ) ;
V_14 -> V_374 = F_211 ( V_366 . V_374 ) ;
V_14 -> V_410 = F_211 ( V_366 . V_375 ) ;
if ( F_60 ( V_368 , & V_14 -> V_71 ) ) {
V_14 -> V_89 = F_211 ( V_341 . V_343 ) ;
V_14 -> V_91 =
F_213 ( V_341 . V_344 ) ;
V_14 -> V_93 = F_213 ( V_341 . V_345 ) ;
V_14 -> V_95 =
F_213 ( V_341 . V_346 ) ;
}
break;
case V_229 :
V_14 -> V_410 = F_211 ( V_366 . V_375 ) ;
}
}
V_212 -> V_6 = F_14 ( V_14 -> V_6 ) ;
V_212 -> V_71 = F_14 ( 0x0000 ) ;
return V_334 - V_26 ;
}
static int F_215 ( struct V_1 * V_14 , void * V_26 , T_1 V_121 , T_1 V_71 )
{
struct V_383 * V_120 = V_26 ;
void * V_334 = V_120 -> V_26 ;
F_19 ( L_3 , V_14 ) ;
V_120 -> V_7 = F_14 ( V_14 -> V_6 ) ;
V_120 -> V_121 = F_14 ( V_121 ) ;
V_120 -> V_71 = F_14 ( V_71 ) ;
return V_334 - V_26 ;
}
void F_216 ( struct V_1 * V_14 )
{
struct V_119 V_120 ;
struct V_2 * V_3 = V_14 -> V_3 ;
T_2 V_233 [ 128 ] ;
V_120 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_120 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_120 . V_121 = F_14 ( V_236 ) ;
V_120 . V_126 = F_14 ( V_127 ) ;
F_71 ( V_3 , V_14 -> V_9 ,
V_128 , sizeof( V_120 ) , & V_120 ) ;
if ( F_217 ( V_238 , & V_14 -> V_104 ) )
return;
F_71 ( V_3 , F_75 ( V_3 ) , V_239 ,
F_114 ( V_14 , V_233 ) , V_233 ) ;
V_14 -> V_240 ++ ;
}
static void F_218 ( struct V_1 * V_14 , void * V_120 , int V_142 )
{
int type , V_335 ;
unsigned long V_336 ;
struct V_365 V_366 ;
F_19 ( L_25 , V_14 , V_120 , V_142 ) ;
if ( ( V_14 -> V_107 != V_108 ) && ( V_14 -> V_107 != V_229 ) )
return;
while ( V_142 >= V_339 ) {
V_142 -= F_199 ( & V_120 , & type , & V_335 , & V_336 ) ;
if ( type != V_376 )
continue;
if ( V_335 != sizeof( V_366 ) )
break;
memcpy ( & V_366 , ( void * ) V_336 , V_335 ) ;
goto V_18;
}
V_366 . V_107 = V_14 -> V_107 ;
V_366 . V_373 = F_14 ( V_402 ) ;
V_366 . V_374 = F_14 ( V_403 ) ;
V_366 . V_375 = F_14 ( V_14 -> V_369 ) ;
F_219 ( L_26 ) ;
V_18:
switch ( V_366 . V_107 ) {
case V_108 :
V_14 -> V_373 = F_211 ( V_366 . V_373 ) ;
V_14 -> V_374 = F_211 ( V_366 . V_374 ) ;
V_14 -> V_410 = F_211 ( V_366 . V_375 ) ;
break;
case V_229 :
V_14 -> V_410 = F_211 ( V_366 . V_375 ) ;
}
}
static inline int F_220 ( struct V_2 * V_3 , struct V_329 * V_330 , T_2 * V_26 )
{
struct V_411 * V_412 = (struct V_411 * ) V_26 ;
if ( V_412 -> V_47 != V_413 )
return 0 ;
if ( ( V_3 -> V_214 & V_215 ) &&
V_330 -> V_9 == V_3 -> V_219 ) {
F_221 ( & V_3 -> V_220 ) ;
V_3 -> V_214 |= V_216 ;
V_3 -> V_219 = 0 ;
F_113 ( V_3 ) ;
}
return 0 ;
}
static inline int F_222 ( struct V_2 * V_3 , struct V_329 * V_330 , T_2 * V_26 )
{
struct V_211 * V_212 = (struct V_211 * ) V_26 ;
struct V_119 V_120 ;
struct V_1 * V_14 = NULL , * V_248 ;
struct V_27 * V_98 , * V_13 = NULL ;
int V_121 , V_126 = V_127 ;
T_1 V_6 = 0 , V_7 = F_52 ( V_212 -> V_7 ) ;
T_3 V_10 = V_212 -> V_10 ;
F_19 ( L_27 , F_52 ( V_10 ) , V_7 ) ;
V_248 = F_137 ( V_115 , V_10 , V_3 -> V_11 , V_3 -> V_241 ) ;
if ( ! V_248 ) {
V_121 = V_124 ;
goto V_414;
}
V_98 = V_248 -> V_13 ;
F_5 ( & V_3 -> V_8 ) ;
F_22 ( V_98 ) ;
if ( V_10 != F_14 ( 0x0001 ) &&
! F_223 ( V_3 -> V_76 ) ) {
V_3 -> V_72 = V_415 ;
V_121 = V_123 ;
goto V_416;
}
V_121 = V_417 ;
if ( F_119 ( V_98 ) ) {
F_19 ( L_14 , V_98 -> V_249 ) ;
goto V_416;
}
V_14 = V_248 -> V_24 -> V_251 ( V_248 -> V_26 ) ;
if ( ! V_14 )
goto V_416;
V_13 = V_14 -> V_13 ;
if ( F_1 ( V_3 , V_7 ) ) {
F_58 ( V_13 , V_100 ) ;
V_14 -> V_24 -> V_55 ( V_14 -> V_26 ) ;
goto V_416;
}
F_120 ( V_3 -> V_76 ) ;
F_121 ( & F_11 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_121 ( & F_11 ( V_13 ) -> V_241 , V_3 -> V_241 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_7 ;
F_122 ( V_98 , V_13 ) ;
F_51 ( V_3 , V_14 ) ;
V_6 = V_14 -> V_7 ;
F_69 ( V_14 , V_13 -> V_117 ) ;
V_14 -> V_9 = V_330 -> V_9 ;
if ( V_3 -> V_214 & V_216 ) {
if ( F_73 ( V_14 ) ) {
if ( F_60 ( V_122 , & F_11 ( V_13 ) -> V_71 ) ) {
F_18 ( V_14 , V_118 ) ;
V_121 = V_234 ;
V_126 = V_235 ;
V_98 -> V_101 ( V_98 , 0 ) ;
} else {
F_18 ( V_14 , V_49 ) ;
V_121 = V_236 ;
V_126 = V_127 ;
}
} else {
F_18 ( V_14 , V_118 ) ;
V_121 = V_234 ;
V_126 = V_237 ;
}
} else {
F_18 ( V_14 , V_118 ) ;
V_121 = V_234 ;
V_126 = V_127 ;
}
V_416:
F_23 ( V_98 ) ;
F_7 ( & V_3 -> V_8 ) ;
V_414:
V_120 . V_7 = F_14 ( V_7 ) ;
V_120 . V_6 = F_14 ( V_6 ) ;
V_120 . V_121 = F_14 ( V_121 ) ;
V_120 . V_126 = F_14 ( V_126 ) ;
F_71 ( V_3 , V_330 -> V_9 , V_128 , sizeof( V_120 ) , & V_120 ) ;
if ( V_121 == V_234 && V_126 == V_127 ) {
struct V_217 V_418 ;
V_418 . type = F_14 ( V_218 ) ;
V_3 -> V_214 |= V_215 ;
V_3 -> V_219 = F_75 ( V_3 ) ;
F_111 ( & V_3 -> V_220 , V_221 ) ;
F_71 ( V_3 , V_3 -> V_219 ,
V_222 , sizeof( V_418 ) , & V_418 ) ;
}
if ( V_14 && ! F_60 ( V_238 , & V_14 -> V_104 ) &&
V_121 == V_236 ) {
T_2 V_233 [ 128 ] ;
F_50 ( V_238 , & V_14 -> V_104 ) ;
F_71 ( V_3 , F_75 ( V_3 ) , V_239 ,
F_114 ( V_14 , V_233 ) , V_233 ) ;
V_14 -> V_240 ++ ;
}
return 0 ;
}
static inline int F_224 ( struct V_2 * V_3 , struct V_329 * V_330 , T_2 * V_26 )
{
struct V_119 * V_120 = (struct V_119 * ) V_26 ;
T_1 V_7 , V_6 , V_121 , V_126 ;
struct V_1 * V_14 ;
T_2 V_212 [ 128 ] ;
int V_15 ;
V_7 = F_52 ( V_120 -> V_7 ) ;
V_6 = F_52 ( V_120 -> V_6 ) ;
V_121 = F_52 ( V_120 -> V_121 ) ;
V_126 = F_52 ( V_120 -> V_126 ) ;
F_19 ( L_28 ,
V_6 , V_7 , V_121 , V_126 ) ;
F_5 ( & V_3 -> V_8 ) ;
if ( V_7 ) {
V_14 = F_3 ( V_3 , V_7 ) ;
if ( ! V_14 ) {
V_15 = - V_306 ;
goto V_419;
}
} else {
V_14 = F_8 ( V_3 , V_330 -> V_9 ) ;
if ( ! V_14 ) {
V_15 = - V_306 ;
goto V_419;
}
}
V_15 = 0 ;
F_6 ( V_14 ) ;
switch ( V_121 ) {
case V_236 :
F_21 ( V_14 , V_49 ) ;
V_14 -> V_9 = 0 ;
V_14 -> V_6 = V_6 ;
F_225 ( V_210 , & V_14 -> V_104 ) ;
if ( F_217 ( V_238 , & V_14 -> V_104 ) )
break;
F_71 ( V_3 , F_75 ( V_3 ) , V_239 ,
F_114 ( V_14 , V_212 ) , V_212 ) ;
V_14 -> V_240 ++ ;
break;
case V_234 :
F_50 ( V_210 , & V_14 -> V_104 ) ;
break;
default:
F_55 ( V_14 , V_50 ) ;
break;
}
F_39 ( V_14 ) ;
V_419:
F_7 ( & V_3 -> V_8 ) ;
return V_15 ;
}
static inline void F_226 ( struct V_1 * V_14 )
{
if ( V_14 -> V_107 != V_108 && V_14 -> V_107 != V_229 )
V_14 -> V_62 = V_379 ;
else if ( ! F_60 ( V_380 , & V_14 -> V_104 ) )
V_14 -> V_62 = V_63 ;
}
static inline int F_227 ( struct V_2 * V_3 , struct V_329 * V_330 , T_1 V_420 , T_2 * V_26 )
{
struct V_364 * V_212 = (struct V_364 * ) V_26 ;
T_1 V_6 , V_71 ;
T_2 V_120 [ 64 ] ;
struct V_1 * V_14 ;
int V_142 , V_15 = 0 ;
V_6 = F_52 ( V_212 -> V_6 ) ;
V_71 = F_52 ( V_212 -> V_71 ) ;
F_19 ( L_29 , V_6 , V_71 ) ;
V_14 = F_4 ( V_3 , V_6 ) ;
if ( ! V_14 )
return - V_421 ;
if ( V_14 -> V_23 != V_49 && V_14 -> V_23 != V_118 ) {
struct V_422 V_412 ;
V_412 . V_47 = F_14 ( V_423 ) ;
V_412 . V_7 = F_14 ( V_14 -> V_7 ) ;
V_412 . V_6 = F_14 ( V_14 -> V_6 ) ;
F_71 ( V_3 , V_330 -> V_9 , V_424 ,
sizeof( V_412 ) , & V_412 ) ;
goto V_419;
}
V_142 = V_420 - sizeof( * V_212 ) ;
if ( V_142 < 0 || V_14 -> V_385 + V_142 > sizeof( V_14 -> V_384 ) ) {
F_71 ( V_3 , V_330 -> V_9 , V_425 ,
F_215 ( V_14 , V_120 ,
V_426 , V_71 ) , V_120 ) ;
goto V_419;
}
memcpy ( V_14 -> V_384 + V_14 -> V_385 , V_212 -> V_26 , V_142 ) ;
V_14 -> V_385 += V_142 ;
if ( V_71 & 0x0001 ) {
F_71 ( V_3 , V_330 -> V_9 , V_425 ,
F_215 ( V_14 , V_120 ,
V_388 , 0x0001 ) , V_120 ) ;
goto V_419;
}
V_142 = F_210 ( V_14 , V_120 ) ;
if ( V_142 < 0 ) {
F_70 ( V_3 , V_14 , V_114 ) ;
goto V_419;
}
F_71 ( V_3 , V_330 -> V_9 , V_425 , V_142 , V_120 ) ;
V_14 -> V_367 ++ ;
V_14 -> V_385 = 0 ;
if ( ! F_60 ( V_103 , & V_14 -> V_104 ) )
goto V_419;
if ( F_60 ( V_105 , & V_14 -> V_104 ) ) {
F_226 ( V_14 ) ;
F_21 ( V_14 , V_48 ) ;
if ( V_14 -> V_107 == V_108 ||
V_14 -> V_107 == V_229 )
V_15 = F_204 ( V_14 ) ;
if ( V_15 < 0 )
F_70 ( V_14 -> V_3 , V_14 , - V_15 ) ;
else
F_109 ( V_14 ) ;
goto V_419;
}
if ( ! F_217 ( V_238 , & V_14 -> V_104 ) ) {
T_2 V_233 [ 64 ] ;
F_71 ( V_3 , F_75 ( V_3 ) , V_239 ,
F_114 ( V_14 , V_233 ) , V_233 ) ;
V_14 -> V_240 ++ ;
}
if ( F_60 ( V_427 , & V_14 -> V_104 ) &&
F_60 ( V_400 , & V_14 -> V_104 ) ) {
F_225 ( V_400 , & V_14 -> V_104 ) ;
F_50 ( V_103 , & V_14 -> V_104 ) ;
F_71 ( V_3 , V_330 -> V_9 , V_425 ,
F_215 ( V_14 , V_120 ,
V_388 , 0x0000 ) , V_120 ) ;
}
V_419:
F_39 ( V_14 ) ;
return V_15 ;
}
static inline int F_228 ( struct V_2 * V_3 , struct V_329 * V_330 , T_2 * V_26 )
{
struct V_383 * V_120 = (struct V_383 * ) V_26 ;
T_1 V_7 , V_71 , V_121 ;
struct V_1 * V_14 ;
int V_142 = F_211 ( V_330 -> V_142 ) - sizeof( * V_120 ) ;
int V_15 = 0 ;
V_7 = F_52 ( V_120 -> V_7 ) ;
V_71 = F_52 ( V_120 -> V_71 ) ;
V_121 = F_52 ( V_120 -> V_121 ) ;
F_19 ( L_30 , V_7 , V_71 ,
V_121 , V_142 ) ;
V_14 = F_4 ( V_3 , V_7 ) ;
if ( ! V_14 )
return 0 ;
switch ( V_121 ) {
case V_388 :
F_218 ( V_14 , V_120 -> V_26 , V_142 ) ;
F_225 ( V_427 , & V_14 -> V_104 ) ;
break;
case V_399 :
F_50 ( V_427 , & V_14 -> V_104 ) ;
if ( F_60 ( V_400 , & V_14 -> V_104 ) ) {
char V_233 [ 64 ] ;
V_142 = F_214 ( V_14 , V_120 -> V_26 , V_142 ,
V_233 , & V_121 ) ;
if ( V_142 < 0 ) {
F_70 ( V_3 , V_14 , V_114 ) ;
goto V_18;
}
F_225 ( V_400 , & V_14 -> V_104 ) ;
F_50 ( V_103 , & V_14 -> V_104 ) ;
F_71 ( V_3 , V_330 -> V_9 , V_425 ,
F_215 ( V_14 , V_233 ,
V_388 , 0x0000 ) , V_233 ) ;
}
goto V_18;
case V_395 :
if ( V_14 -> V_367 <= V_428 ) {
char V_212 [ 64 ] ;
if ( V_142 > sizeof( V_212 ) - sizeof( struct V_364 ) ) {
F_70 ( V_3 , V_14 , V_114 ) ;
goto V_18;
}
V_121 = V_388 ;
V_142 = F_214 ( V_14 , V_120 -> V_26 , V_142 ,
V_212 , & V_121 ) ;
if ( V_142 < 0 ) {
F_70 ( V_3 , V_14 , V_114 ) ;
goto V_18;
}
F_71 ( V_3 , F_75 ( V_3 ) ,
V_239 , V_142 , V_212 ) ;
V_14 -> V_240 ++ ;
if ( V_121 != V_388 )
goto V_18;
break;
}
default:
F_25 ( V_14 , V_114 ) ;
F_69 ( V_14 , V_429 ) ;
F_70 ( V_3 , V_14 , V_114 ) ;
goto V_18;
}
if ( V_71 & 0x01 )
goto V_18;
F_50 ( V_105 , & V_14 -> V_104 ) ;
if ( F_60 ( V_103 , & V_14 -> V_104 ) ) {
F_226 ( V_14 ) ;
F_21 ( V_14 , V_48 ) ;
if ( V_14 -> V_107 == V_108 ||
V_14 -> V_107 == V_229 )
V_15 = F_204 ( V_14 ) ;
if ( V_15 < 0 )
F_70 ( V_14 -> V_3 , V_14 , - V_15 ) ;
else
F_109 ( V_14 ) ;
}
V_18:
F_39 ( V_14 ) ;
return V_15 ;
}
static inline int F_229 ( struct V_2 * V_3 , struct V_329 * V_330 , T_2 * V_26 )
{
struct V_230 * V_212 = (struct V_230 * ) V_26 ;
struct V_430 V_120 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
struct V_27 * V_13 ;
V_7 = F_52 ( V_212 -> V_7 ) ;
V_6 = F_52 ( V_212 -> V_6 ) ;
F_19 ( L_31 , V_7 , V_6 ) ;
F_5 ( & V_3 -> V_8 ) ;
V_14 = F_3 ( V_3 , V_6 ) ;
if ( ! V_14 ) {
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
F_6 ( V_14 ) ;
V_13 = V_14 -> V_13 ;
V_120 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_120 . V_7 = F_14 ( V_14 -> V_6 ) ;
F_71 ( V_3 , V_330 -> V_9 , V_431 , sizeof( V_120 ) , & V_120 ) ;
F_22 ( V_13 ) ;
V_13 -> V_432 = V_433 ;
F_23 ( V_13 ) ;
F_53 ( V_14 ) ;
F_55 ( V_14 , V_114 ) ;
F_39 ( V_14 ) ;
V_14 -> V_24 -> V_55 ( V_14 -> V_26 ) ;
F_40 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_230 ( struct V_2 * V_3 , struct V_329 * V_330 , T_2 * V_26 )
{
struct V_430 * V_120 = (struct V_430 * ) V_26 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
V_7 = F_52 ( V_120 -> V_7 ) ;
V_6 = F_52 ( V_120 -> V_6 ) ;
F_19 ( L_32 , V_6 , V_7 ) ;
F_5 ( & V_3 -> V_8 ) ;
V_14 = F_3 ( V_3 , V_7 ) ;
if ( ! V_14 ) {
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
F_6 ( V_14 ) ;
F_53 ( V_14 ) ;
F_55 ( V_14 , 0 ) ;
F_39 ( V_14 ) ;
V_14 -> V_24 -> V_55 ( V_14 -> V_26 ) ;
F_40 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_231 ( struct V_2 * V_3 , struct V_329 * V_330 , T_2 * V_26 )
{
struct V_217 * V_212 = (struct V_217 * ) V_26 ;
T_1 type ;
type = F_52 ( V_212 -> type ) ;
F_19 ( L_33 , type ) ;
if ( type == V_218 ) {
T_2 V_233 [ 8 ] ;
T_8 V_223 = V_225 ;
struct V_434 * V_120 = (struct V_434 * ) V_233 ;
V_120 -> type = F_14 ( V_218 ) ;
V_120 -> V_121 = F_14 ( V_435 ) ;
if ( ! V_226 )
V_223 |= V_227 | V_228
| V_378 ;
if ( V_360 )
V_223 |= V_362
| V_361 ;
F_91 ( V_223 , V_120 -> V_26 ) ;
F_71 ( V_3 , V_330 -> V_9 ,
V_436 , sizeof( V_233 ) , V_233 ) ;
} else if ( type == V_437 ) {
T_2 V_233 [ 12 ] ;
struct V_434 * V_120 = (struct V_434 * ) V_233 ;
if ( V_360 )
V_438 [ 0 ] |= V_439 ;
else
V_438 [ 0 ] &= ~ V_439 ;
V_120 -> type = F_14 ( V_437 ) ;
V_120 -> V_121 = F_14 ( V_435 ) ;
memcpy ( V_120 -> V_26 , V_438 , sizeof( V_438 ) ) ;
F_71 ( V_3 , V_330 -> V_9 ,
V_436 , sizeof( V_233 ) , V_233 ) ;
} else {
struct V_434 V_120 ;
V_120 . type = F_14 ( type ) ;
V_120 . V_121 = F_14 ( V_440 ) ;
F_71 ( V_3 , V_330 -> V_9 ,
V_436 , sizeof( V_120 ) , & V_120 ) ;
}
return 0 ;
}
static inline int F_232 ( struct V_2 * V_3 , struct V_329 * V_330 , T_2 * V_26 )
{
struct V_434 * V_120 = (struct V_434 * ) V_26 ;
T_1 type , V_121 ;
type = F_52 ( V_120 -> type ) ;
V_121 = F_52 ( V_120 -> V_121 ) ;
F_19 ( L_34 , type , V_121 ) ;
if ( V_330 -> V_9 != V_3 -> V_219 ||
V_3 -> V_214 & V_216 )
return 0 ;
F_221 ( & V_3 -> V_220 ) ;
if ( V_121 != V_435 ) {
V_3 -> V_214 |= V_216 ;
V_3 -> V_219 = 0 ;
F_113 ( V_3 ) ;
return 0 ;
}
switch ( type ) {
case V_218 :
V_3 -> V_223 = F_86 ( V_120 -> V_26 ) ;
if ( V_3 -> V_223 & V_441 ) {
struct V_217 V_212 ;
V_212 . type = F_14 ( V_437 ) ;
V_3 -> V_219 = F_75 ( V_3 ) ;
F_71 ( V_3 , V_3 -> V_219 ,
V_222 , sizeof( V_212 ) , & V_212 ) ;
} else {
V_3 -> V_214 |= V_216 ;
V_3 -> V_219 = 0 ;
F_113 ( V_3 ) ;
}
break;
case V_437 :
V_3 -> V_442 = V_120 -> V_26 [ 0 ] ;
V_3 -> V_214 |= V_216 ;
V_3 -> V_219 = 0 ;
F_113 ( V_3 ) ;
break;
}
return 0 ;
}
static inline int F_233 ( struct V_2 * V_3 ,
struct V_329 * V_330 , T_1 V_420 ,
void * V_26 )
{
struct V_443 * V_212 = V_26 ;
struct V_444 V_120 ;
T_1 V_10 , V_7 ;
if ( V_420 != sizeof( * V_212 ) )
return - V_445 ;
if ( ! V_360 )
return - V_20 ;
V_10 = F_211 ( V_212 -> V_10 ) ;
V_7 = F_211 ( V_212 -> V_7 ) ;
F_19 ( L_35 , V_10 , V_7 , V_212 -> V_446 ) ;
V_120 . V_6 = 0 ;
V_120 . V_7 = F_14 ( V_7 ) ;
V_120 . V_121 = F_212 ( V_417 ) ;
V_120 . V_126 = F_212 ( V_127 ) ;
F_71 ( V_3 , V_330 -> V_9 , V_447 ,
sizeof( V_120 ) , & V_120 ) ;
return 0 ;
}
static inline int F_234 ( struct V_2 * V_3 ,
struct V_329 * V_330 , void * V_26 )
{
F_19 ( L_12 , V_3 ) ;
return F_224 ( V_3 , V_330 , V_26 ) ;
}
static void F_235 ( struct V_2 * V_3 , T_2 V_9 ,
T_1 V_448 , T_1 V_121 )
{
struct V_449 V_120 ;
F_19 ( L_36 , V_448 , V_121 ) ;
V_120 . V_448 = F_14 ( V_448 ) ;
V_120 . V_121 = F_14 ( V_121 ) ;
F_71 ( V_3 , V_9 , V_450 , sizeof( V_120 ) , & V_120 ) ;
}
static void F_236 ( struct V_2 * V_3 ,
struct V_1 * V_14 , T_1 V_448 , T_1 V_121 )
{
struct V_451 V_452 ;
T_2 V_9 ;
F_19 ( L_36 , V_448 , V_121 ) ;
V_9 = F_75 ( V_3 ) ;
if ( V_14 )
V_14 -> V_9 = V_9 ;
V_452 . V_448 = F_14 ( V_448 ) ;
V_452 . V_121 = F_14 ( V_121 ) ;
F_71 ( V_3 , V_9 , V_453 , sizeof( V_452 ) , & V_452 ) ;
}
static void F_237 ( struct V_2 * V_3 , T_2 V_9 ,
T_1 V_448 )
{
struct V_454 V_120 ;
F_19 ( L_37 , V_448 ) ;
V_120 . V_448 = F_14 ( V_448 ) ;
F_71 ( V_3 , V_9 , V_455 , sizeof( V_120 ) , & V_120 ) ;
}
static inline int F_238 ( struct V_2 * V_3 ,
struct V_329 * V_330 , T_1 V_420 , void * V_26 )
{
struct V_456 * V_212 = V_26 ;
T_1 V_448 = 0 ;
T_1 V_121 = V_457 ;
if ( V_420 != sizeof( * V_212 ) )
return - V_445 ;
V_448 = F_211 ( V_212 -> V_448 ) ;
F_19 ( L_38 , V_448 , V_212 -> V_458 ) ;
if ( ! V_360 )
return - V_20 ;
F_235 ( V_3 , V_330 -> V_9 , V_448 , V_121 ) ;
return 0 ;
}
static inline int F_239 ( struct V_2 * V_3 ,
struct V_329 * V_330 , T_1 V_420 , void * V_26 )
{
struct V_449 * V_120 = V_26 ;
T_1 V_448 , V_121 ;
if ( V_420 != sizeof( * V_120 ) )
return - V_445 ;
V_448 = F_211 ( V_120 -> V_448 ) ;
V_121 = F_211 ( V_120 -> V_121 ) ;
F_19 ( L_36 , V_448 , V_121 ) ;
F_236 ( V_3 , NULL , V_448 , V_459 ) ;
return 0 ;
}
static inline int F_240 ( struct V_2 * V_3 ,
struct V_329 * V_330 , T_1 V_420 , void * V_26 )
{
struct V_451 * V_452 = V_26 ;
T_1 V_448 , V_121 ;
if ( V_420 != sizeof( * V_452 ) )
return - V_445 ;
V_448 = F_211 ( V_452 -> V_448 ) ;
V_121 = F_211 ( V_452 -> V_121 ) ;
F_19 ( L_36 , V_448 , V_121 ) ;
F_237 ( V_3 , V_330 -> V_9 , V_448 ) ;
return 0 ;
}
static inline int F_241 ( struct V_2 * V_3 ,
struct V_329 * V_330 , T_1 V_420 , void * V_26 )
{
struct V_454 * V_120 = V_26 ;
T_1 V_448 ;
if ( V_420 != sizeof( * V_120 ) )
return - V_445 ;
V_448 = F_211 ( V_120 -> V_448 ) ;
F_19 ( L_37 , V_448 ) ;
return 0 ;
}
static inline int F_242 ( T_1 V_460 , T_1 V_461 , T_1 V_462 ,
T_1 V_463 )
{
T_1 V_464 ;
if ( V_460 > V_461 || V_460 < 6 || V_461 > 3200 )
return - V_20 ;
if ( V_463 < 10 || V_463 > 3200 )
return - V_20 ;
if ( V_461 >= V_463 * 8 )
return - V_20 ;
V_464 = ( V_463 * 8 / V_461 ) - 1 ;
if ( V_462 > 499 || V_462 > V_464 )
return - V_20 ;
return 0 ;
}
static inline int F_243 ( struct V_2 * V_3 ,
struct V_329 * V_330 , T_2 * V_26 )
{
struct V_153 * V_76 = V_3 -> V_76 ;
struct F_243 * V_212 ;
struct V_465 V_120 ;
T_1 V_460 , V_461 , V_462 , V_463 , V_420 ;
int V_15 ;
if ( ! ( V_76 -> V_466 & V_467 ) )
return - V_20 ;
V_420 = F_52 ( V_330 -> V_142 ) ;
if ( V_420 != sizeof( struct F_243 ) )
return - V_445 ;
V_212 = (struct F_243 * ) V_26 ;
V_460 = F_52 ( V_212 -> V_460 ) ;
V_461 = F_52 ( V_212 -> V_461 ) ;
V_462 = F_52 ( V_212 -> V_462 ) ;
V_463 = F_52 ( V_212 -> V_463 ) ;
F_19 ( L_39 ,
V_460 , V_461 , V_462 , V_463 ) ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_15 = F_242 ( V_460 , V_461 , V_462 , V_463 ) ;
if ( V_15 )
V_120 . V_121 = F_14 ( V_468 ) ;
else
V_120 . V_121 = F_14 ( V_469 ) ;
F_71 ( V_3 , V_330 -> V_9 , V_470 ,
sizeof( V_120 ) , & V_120 ) ;
if ( ! V_15 )
F_244 ( V_76 , V_460 , V_461 , V_462 , V_463 ) ;
return 0 ;
}
static inline int F_245 ( struct V_2 * V_3 ,
struct V_329 * V_330 , T_1 V_420 , T_2 * V_26 )
{
int V_15 = 0 ;
switch ( V_330 -> V_141 ) {
case V_424 :
F_220 ( V_3 , V_330 , V_26 ) ;
break;
case V_213 :
V_15 = F_222 ( V_3 , V_330 , V_26 ) ;
break;
case V_128 :
V_15 = F_224 ( V_3 , V_330 , V_26 ) ;
break;
case V_239 :
V_15 = F_227 ( V_3 , V_330 , V_420 , V_26 ) ;
break;
case V_425 :
V_15 = F_228 ( V_3 , V_330 , V_26 ) ;
break;
case V_231 :
V_15 = F_229 ( V_3 , V_330 , V_26 ) ;
break;
case V_431 :
V_15 = F_230 ( V_3 , V_330 , V_26 ) ;
break;
case V_471 :
F_71 ( V_3 , V_330 -> V_9 , V_472 , V_420 , V_26 ) ;
break;
case V_472 :
break;
case V_222 :
V_15 = F_231 ( V_3 , V_330 , V_26 ) ;
break;
case V_436 :
V_15 = F_232 ( V_3 , V_330 , V_26 ) ;
break;
case V_473 :
V_15 = F_233 ( V_3 , V_330 , V_420 , V_26 ) ;
break;
case V_447 :
V_15 = F_234 ( V_3 , V_330 , V_26 ) ;
break;
case V_474 :
V_15 = F_238 ( V_3 , V_330 , V_420 , V_26 ) ;
break;
case V_450 :
V_15 = F_239 ( V_3 , V_330 , V_420 , V_26 ) ;
break;
case V_453 :
V_15 = F_240 ( V_3 , V_330 , V_420 , V_26 ) ;
break;
case V_455 :
V_15 = F_241 ( V_3 , V_330 , V_420 , V_26 ) ;
break;
default:
F_219 ( L_40 , V_330 -> V_141 ) ;
V_15 = - V_20 ;
break;
}
return V_15 ;
}
static inline int F_246 ( struct V_2 * V_3 ,
struct V_329 * V_330 , T_2 * V_26 )
{
switch ( V_330 -> V_141 ) {
case V_424 :
return 0 ;
case V_475 :
return F_243 ( V_3 , V_330 , V_26 ) ;
case V_470 :
return 0 ;
default:
F_219 ( L_41 , V_330 -> V_141 ) ;
return - V_20 ;
}
}
static inline void F_247 ( struct V_2 * V_3 ,
struct V_143 * V_144 )
{
T_2 * V_26 = V_144 -> V_26 ;
int V_142 = V_144 -> V_142 ;
struct V_329 V_330 ;
int V_15 ;
F_198 ( V_3 , V_144 ) ;
while ( V_142 >= V_331 ) {
T_1 V_420 ;
memcpy ( & V_330 , V_26 , V_331 ) ;
V_26 += V_331 ;
V_142 -= V_331 ;
V_420 = F_211 ( V_330 . V_142 ) ;
F_19 ( L_42 , V_330 . V_141 , V_420 , V_330 . V_9 ) ;
if ( V_420 > V_142 || ! V_330 . V_9 ) {
F_19 ( L_43 ) ;
break;
}
if ( V_3 -> V_76 -> type == V_77 )
V_15 = F_246 ( V_3 , & V_330 , V_26 ) ;
else
V_15 = F_245 ( V_3 , & V_330 , V_420 , V_26 ) ;
if ( V_15 ) {
struct V_411 V_412 ;
F_219 ( L_44 , V_15 ) ;
V_412 . V_47 = F_14 ( V_413 ) ;
F_71 ( V_3 , V_330 . V_9 , V_424 , sizeof( V_412 ) , & V_412 ) ;
}
V_26 += V_420 ;
V_142 -= V_420 ;
}
F_128 ( V_144 ) ;
}
static int F_248 ( struct V_1 * V_14 , struct V_143 * V_144 )
{
T_1 V_476 , V_477 ;
int V_478 ;
if ( F_60 ( V_192 , & V_14 -> V_71 ) )
V_478 = V_199 ;
else
V_478 = V_200 ;
if ( V_14 -> V_62 == V_63 ) {
F_249 ( V_144 , V_144 -> V_142 - V_201 ) ;
V_477 = F_87 ( V_144 -> V_26 + V_144 -> V_142 ) ;
V_476 = F_103 ( 0 , V_144 -> V_26 - V_478 , V_144 -> V_142 + V_478 ) ;
if ( V_476 != V_477 )
return - V_479 ;
}
return 0 ;
}
static inline void F_250 ( struct V_1 * V_14 )
{
T_8 V_157 = 0 ;
V_14 -> V_296 = 0 ;
V_157 |= F_106 ( V_14 , V_14 -> V_209 ) ;
if ( F_60 ( V_205 , & V_14 -> V_203 ) ) {
V_157 |= F_105 ( V_14 , V_206 ) ;
F_93 ( V_14 , V_157 ) ;
F_50 ( V_207 , & V_14 -> V_203 ) ;
}
if ( F_60 ( V_294 , & V_14 -> V_203 ) )
F_177 ( V_14 ) ;
F_174 ( V_14 ) ;
if ( ! F_60 ( V_205 , & V_14 -> V_203 ) &&
V_14 -> V_296 == 0 ) {
V_157 |= F_105 ( V_14 , V_208 ) ;
F_93 ( V_14 , V_157 ) ;
}
}
static int F_251 ( struct V_1 * V_14 , struct V_143 * V_144 , T_1 V_289 , T_2 V_172 )
{
struct V_143 * V_480 ;
int V_481 , V_482 ;
F_80 ( V_144 ) -> V_157 . V_173 = V_289 ;
F_80 ( V_144 ) -> V_157 . V_172 = V_172 ;
V_480 = F_162 ( & V_14 -> V_112 ) ;
V_481 = F_252 ( V_14 , V_289 , V_14 -> V_209 ) ;
while ( V_480 ) {
if ( F_80 ( V_480 ) -> V_157 . V_173 == V_289 )
return - V_20 ;
V_482 = F_252 ( V_14 ,
F_80 ( V_480 ) -> V_157 . V_173 , V_14 -> V_209 ) ;
if ( V_482 > V_481 ) {
F_253 ( & V_14 -> V_112 , V_480 , V_144 ) ;
return 0 ;
}
if ( F_170 ( & V_14 -> V_112 , V_480 ) )
V_480 = NULL ;
else
V_480 = F_171 ( & V_14 -> V_112 , V_480 ) ;
}
F_194 ( & V_14 -> V_112 , V_144 ) ;
return 0 ;
}
static void F_254 ( struct V_143 * V_144 ,
struct V_143 * V_483 , struct V_143 * * V_484 )
{
if ( ! F_255 ( V_144 ) )
F_185 ( V_144 ) -> V_307 = V_483 ;
V_483 -> V_298 = NULL ;
( * V_484 ) -> V_298 = V_483 ;
* V_484 = V_483 ;
V_144 -> V_142 += V_483 -> V_142 ;
V_144 -> V_311 += V_483 -> V_142 ;
V_144 -> V_485 += V_483 -> V_485 ;
}
static int F_256 ( struct V_1 * V_14 , struct V_143 * V_144 , T_8 V_157 )
{
int V_15 = - V_20 ;
switch ( F_257 ( V_14 , V_157 ) ) {
case V_321 :
if ( V_14 -> V_352 )
break;
V_15 = V_14 -> V_24 -> V_327 ( V_14 -> V_26 , V_144 ) ;
break;
case V_322 :
if ( V_14 -> V_352 )
break;
V_14 -> V_317 = F_87 ( V_144 -> V_26 ) ;
F_258 ( V_144 , V_314 ) ;
if ( V_14 -> V_317 > V_14 -> V_369 ) {
V_15 = - V_325 ;
break;
}
if ( V_144 -> V_142 >= V_14 -> V_317 )
break;
V_14 -> V_352 = V_144 ;
V_14 -> V_353 = V_144 ;
V_144 = NULL ;
V_15 = 0 ;
break;
case V_324 :
if ( ! V_14 -> V_352 )
break;
F_254 ( V_14 -> V_352 , V_144 ,
& V_14 -> V_353 ) ;
V_144 = NULL ;
if ( V_14 -> V_352 -> V_142 >= V_14 -> V_317 )
break;
V_15 = 0 ;
break;
case V_323 :
if ( ! V_14 -> V_352 )
break;
F_254 ( V_14 -> V_352 , V_144 ,
& V_14 -> V_353 ) ;
V_144 = NULL ;
if ( V_14 -> V_352 -> V_142 != V_14 -> V_317 )
break;
V_15 = V_14 -> V_24 -> V_327 ( V_14 -> V_26 , V_14 -> V_352 ) ;
if ( ! V_15 ) {
V_14 -> V_352 = NULL ;
V_14 -> V_353 = NULL ;
V_14 -> V_317 = 0 ;
}
break;
}
if ( V_15 ) {
F_128 ( V_144 ) ;
F_128 ( V_14 -> V_352 ) ;
V_14 -> V_352 = NULL ;
V_14 -> V_353 = NULL ;
V_14 -> V_317 = 0 ;
}
return V_15 ;
}
static void F_259 ( struct V_1 * V_14 )
{
F_19 ( L_45 , V_14 ) ;
F_50 ( V_205 , & V_14 -> V_203 ) ;
F_34 ( & V_14 -> V_109 ) ;
F_260 ( V_14 ) ;
}
static void F_261 ( struct V_1 * V_14 )
{
T_8 V_157 ;
if ( ! F_60 ( V_207 , & V_14 -> V_203 ) )
goto V_18;
V_157 = F_106 ( V_14 , V_14 -> V_209 ) ;
V_157 |= F_98 ( V_14 ) ;
V_157 |= F_105 ( V_14 , V_208 ) ;
F_93 ( V_14 , V_157 ) ;
V_14 -> V_282 = 1 ;
F_62 ( V_14 ) ;
F_159 ( V_14 ) ;
F_50 ( V_286 , & V_14 -> V_203 ) ;
V_18:
F_225 ( V_205 , & V_14 -> V_203 ) ;
F_225 ( V_207 , & V_14 -> V_203 ) ;
F_19 ( L_46 , V_14 ) ;
}
void F_262 ( struct V_1 * V_14 , int V_486 )
{
if ( V_14 -> V_107 == V_108 ) {
if ( V_486 )
F_259 ( V_14 ) ;
else
F_261 ( V_14 ) ;
}
}
static void F_263 ( struct V_1 * V_14 , T_1 V_289 )
{
struct V_143 * V_144 ;
T_8 V_157 ;
while ( ( V_144 = F_162 ( & V_14 -> V_112 ) ) &&
! F_60 ( V_205 , & V_14 -> V_203 ) ) {
int V_15 ;
if ( F_80 ( V_144 ) -> V_157 . V_173 != V_289 )
break;
V_144 = F_163 ( & V_14 -> V_112 ) ;
V_157 = F_167 ( V_14 , F_80 ( V_144 ) -> V_157 . V_172 ) ;
V_15 = F_256 ( V_14 , V_144 , V_157 ) ;
if ( V_15 < 0 ) {
F_70 ( V_14 -> V_3 , V_14 , V_114 ) ;
break;
}
V_14 -> V_487 = F_168 ( V_14 , V_14 -> V_487 ) ;
V_289 = F_168 ( V_14 , V_289 ) ;
}
}
static void F_264 ( struct V_1 * V_14 , T_1 V_289 )
{
struct V_109 * V_110 , * V_111 ;
T_8 V_157 ;
F_65 (l, tmp, &chan->srej_l, list) {
if ( V_110 -> V_289 == V_289 ) {
F_48 ( & V_110 -> V_34 ) ;
F_30 ( V_110 ) ;
return;
}
V_157 = F_105 ( V_14 , V_299 ) ;
V_157 |= F_106 ( V_14 , V_110 -> V_289 ) ;
F_93 ( V_14 , V_157 ) ;
F_48 ( & V_110 -> V_34 ) ;
F_265 ( & V_110 -> V_34 , & V_14 -> V_300 ) ;
}
}
static int F_266 ( struct V_1 * V_14 , T_1 V_289 )
{
struct V_109 * V_488 ;
T_8 V_157 ;
while ( V_289 != V_14 -> V_349 ) {
V_157 = F_105 ( V_14 , V_299 ) ;
V_157 |= F_106 ( V_14 , V_14 -> V_349 ) ;
F_35 ( & V_14 -> V_109 , V_14 -> V_349 ) ;
F_93 ( V_14 , V_157 ) ;
V_488 = F_42 ( sizeof( struct V_109 ) , V_56 ) ;
if ( ! V_488 )
return - V_36 ;
V_488 -> V_289 = V_14 -> V_349 ;
V_14 -> V_349 = F_168 ( V_14 , V_14 -> V_349 ) ;
F_265 ( & V_488 -> V_34 , & V_14 -> V_300 ) ;
}
V_14 -> V_349 = F_168 ( V_14 , V_14 -> V_349 ) ;
return 0 ;
}
static inline int F_267 ( struct V_1 * V_14 , T_8 V_489 , struct V_143 * V_144 )
{
T_1 V_289 = F_268 ( V_14 , V_489 ) ;
T_1 V_490 = F_269 ( V_14 , V_489 ) ;
T_2 V_172 = F_257 ( V_14 , V_489 ) ;
int V_481 , V_491 ;
int V_492 = ( V_14 -> V_66 / 6 ) + 1 ;
int V_15 = 0 ;
F_19 ( L_47 , V_14 , V_144 -> V_142 ,
V_289 , V_489 ) ;
if ( F_270 ( V_14 , V_489 ) &&
F_60 ( V_286 , & V_14 -> V_203 ) ) {
F_63 ( V_14 ) ;
if ( V_14 -> V_279 > 0 )
F_176 ( V_14 ) ;
F_225 ( V_286 , & V_14 -> V_203 ) ;
}
V_14 -> V_287 = V_490 ;
F_161 ( V_14 ) ;
V_481 = F_252 ( V_14 , V_289 , V_14 -> V_209 ) ;
if ( V_481 >= V_14 -> V_66 ) {
F_70 ( V_14 -> V_3 , V_14 , V_114 ) ;
goto V_493;
}
if ( F_60 ( V_205 , & V_14 -> V_203 ) ) {
if ( ! F_60 ( V_207 , & V_14 -> V_203 ) )
F_180 ( V_14 ) ;
goto V_493;
}
if ( V_289 == V_14 -> V_349 )
goto V_494;
if ( F_60 ( V_495 , & V_14 -> V_203 ) ) {
struct V_109 * V_496 ;
V_496 = F_271 ( & V_14 -> V_300 ,
struct V_109 , V_34 ) ;
if ( V_289 == V_496 -> V_289 ) {
F_251 ( V_14 , V_144 , V_289 , V_172 ) ;
F_263 ( V_14 , V_289 ) ;
F_48 ( & V_496 -> V_34 ) ;
F_30 ( V_496 ) ;
if ( F_145 ( & V_14 -> V_300 ) ) {
V_14 -> V_209 = V_14 -> V_487 ;
F_225 ( V_495 , & V_14 -> V_203 ) ;
F_180 ( V_14 ) ;
F_19 ( L_48 , V_14 ) ;
}
} else {
struct V_109 * V_110 ;
if ( F_251 ( V_14 , V_144 , V_289 , V_172 ) < 0 )
goto V_493;
F_2 (l, &chan->srej_l, list) {
if ( V_110 -> V_289 == V_289 ) {
F_264 ( V_14 , V_289 ) ;
return 0 ;
}
}
V_15 = F_266 ( V_14 , V_289 ) ;
if ( V_15 < 0 ) {
F_70 ( V_14 -> V_3 , V_14 , - V_15 ) ;
return V_15 ;
}
}
} else {
V_491 = F_252 ( V_14 ,
V_14 -> V_349 , V_14 -> V_209 ) ;
if ( V_481 < V_491 )
goto V_493;
F_50 ( V_495 , & V_14 -> V_203 ) ;
F_19 ( L_49 , V_14 ) ;
F_136 ( & V_14 -> V_300 ) ;
V_14 -> V_487 = V_14 -> V_209 ;
F_196 ( & V_14 -> V_112 ) ;
F_251 ( V_14 , V_144 , V_289 , V_172 ) ;
if ( F_64 ( V_14 ) )
F_50 ( V_204 , & V_14 -> V_203 ) ;
V_15 = F_266 ( V_14 , V_289 ) ;
if ( V_15 < 0 ) {
F_70 ( V_14 -> V_3 , V_14 , - V_15 ) ;
return V_15 ;
}
}
return 0 ;
V_494:
V_14 -> V_349 = F_168 ( V_14 , V_14 -> V_349 ) ;
if ( F_60 ( V_495 , & V_14 -> V_203 ) ) {
F_80 ( V_144 ) -> V_157 . V_173 = V_289 ;
F_80 ( V_144 ) -> V_157 . V_172 = V_172 ;
F_194 ( & V_14 -> V_112 , V_144 ) ;
return 0 ;
}
V_15 = F_256 ( V_14 , V_144 , V_489 ) ;
V_14 -> V_209 = F_168 ( V_14 , V_14 -> V_209 ) ;
if ( V_15 < 0 ) {
F_70 ( V_14 -> V_3 , V_14 , V_114 ) ;
return V_15 ;
}
if ( F_270 ( V_14 , V_489 ) ) {
if ( ! F_96 ( V_497 , & V_14 -> V_203 ) )
F_177 ( V_14 ) ;
}
V_14 -> V_350 = ( V_14 -> V_350 + 1 ) % V_492 ;
if ( V_14 -> V_350 == V_492 - 1 )
F_180 ( V_14 ) ;
else
F_260 ( V_14 ) ;
return 0 ;
V_493:
F_128 ( V_144 ) ;
return 0 ;
}
static inline void F_272 ( struct V_1 * V_14 , T_8 V_489 )
{
F_19 ( L_50 , V_14 ,
F_269 ( V_14 , V_489 ) , V_489 ) ;
V_14 -> V_287 = F_269 ( V_14 , V_489 ) ;
F_161 ( V_14 ) ;
if ( F_273 ( V_14 , V_489 ) ) {
F_50 ( V_202 , & V_14 -> V_203 ) ;
if ( F_60 ( V_495 , & V_14 -> V_203 ) ) {
if ( F_60 ( V_294 , & V_14 -> V_203 ) &&
( V_14 -> V_279 > 0 ) )
F_176 ( V_14 ) ;
F_225 ( V_294 , & V_14 -> V_203 ) ;
F_181 ( V_14 ) ;
} else {
F_250 ( V_14 ) ;
}
} else if ( F_270 ( V_14 , V_489 ) ) {
F_225 ( V_294 , & V_14 -> V_203 ) ;
if ( ! F_96 ( V_497 , & V_14 -> V_203 ) )
F_177 ( V_14 ) ;
} else {
if ( F_60 ( V_294 , & V_14 -> V_203 ) &&
( V_14 -> V_279 > 0 ) )
F_176 ( V_14 ) ;
F_225 ( V_294 , & V_14 -> V_203 ) ;
if ( F_60 ( V_495 , & V_14 -> V_203 ) )
F_180 ( V_14 ) ;
else
F_174 ( V_14 ) ;
}
}
static inline void F_274 ( struct V_1 * V_14 , T_8 V_489 )
{
T_1 V_289 = F_269 ( V_14 , V_489 ) ;
F_19 ( L_50 , V_14 , V_289 , V_489 ) ;
F_225 ( V_294 , & V_14 -> V_203 ) ;
V_14 -> V_287 = V_289 ;
F_161 ( V_14 ) ;
if ( F_270 ( V_14 , V_489 ) ) {
if ( ! F_96 ( V_497 , & V_14 -> V_203 ) )
F_177 ( V_14 ) ;
} else {
F_177 ( V_14 ) ;
if ( F_60 ( V_286 , & V_14 -> V_203 ) )
F_50 ( V_497 , & V_14 -> V_203 ) ;
}
}
static inline void F_275 ( struct V_1 * V_14 , T_8 V_489 )
{
T_1 V_289 = F_269 ( V_14 , V_489 ) ;
F_19 ( L_50 , V_14 , V_289 , V_489 ) ;
F_225 ( V_294 , & V_14 -> V_203 ) ;
if ( F_273 ( V_14 , V_489 ) ) {
V_14 -> V_287 = V_289 ;
F_161 ( V_14 ) ;
F_50 ( V_202 , & V_14 -> V_203 ) ;
F_169 ( V_14 , V_289 ) ;
F_174 ( V_14 ) ;
if ( F_60 ( V_286 , & V_14 -> V_203 ) ) {
V_14 -> V_498 = V_289 ;
F_50 ( V_499 , & V_14 -> V_203 ) ;
}
} else if ( F_270 ( V_14 , V_489 ) ) {
if ( F_60 ( V_499 , & V_14 -> V_203 ) &&
V_14 -> V_498 == V_289 )
F_225 ( V_499 , & V_14 -> V_203 ) ;
else
F_169 ( V_14 , V_289 ) ;
} else {
F_169 ( V_14 , V_289 ) ;
if ( F_60 ( V_286 , & V_14 -> V_203 ) ) {
V_14 -> V_498 = V_289 ;
F_50 ( V_499 , & V_14 -> V_203 ) ;
}
}
}
static inline void F_276 ( struct V_1 * V_14 , T_8 V_489 )
{
T_1 V_289 = F_269 ( V_14 , V_489 ) ;
F_19 ( L_50 , V_14 , V_289 , V_489 ) ;
F_50 ( V_294 , & V_14 -> V_203 ) ;
V_14 -> V_287 = V_289 ;
F_161 ( V_14 ) ;
if ( F_273 ( V_14 , V_489 ) )
F_50 ( V_202 , & V_14 -> V_203 ) ;
if ( ! F_60 ( V_495 , & V_14 -> V_203 ) ) {
F_62 ( V_14 ) ;
if ( F_273 ( V_14 , V_489 ) )
F_104 ( V_14 , V_162 ) ;
return;
}
if ( F_273 ( V_14 , V_489 ) ) {
F_181 ( V_14 ) ;
} else {
V_489 = F_105 ( V_14 , V_208 ) ;
F_93 ( V_14 , V_489 ) ;
}
}
static inline int F_277 ( struct V_1 * V_14 , T_8 V_489 , struct V_143 * V_144 )
{
F_19 ( L_51 , V_14 , V_489 , V_144 -> V_142 ) ;
if ( F_270 ( V_14 , V_489 ) &&
F_60 ( V_286 , & V_14 -> V_203 ) ) {
F_63 ( V_14 ) ;
if ( V_14 -> V_279 > 0 )
F_176 ( V_14 ) ;
F_225 ( V_286 , & V_14 -> V_203 ) ;
}
switch ( F_278 ( V_14 , V_489 ) ) {
case V_208 :
F_272 ( V_14 , V_489 ) ;
break;
case V_500 :
F_274 ( V_14 , V_489 ) ;
break;
case V_299 :
F_275 ( V_14 , V_489 ) ;
break;
case V_206 :
F_276 ( V_14 , V_489 ) ;
break;
}
F_128 ( V_144 ) ;
return 0 ;
}
static int F_279 ( struct V_1 * V_14 , struct V_143 * V_144 )
{
T_8 V_157 ;
T_1 V_490 ;
int V_142 , V_482 , V_501 ;
F_85 ( V_14 , V_144 ) ;
V_157 = F_165 ( V_14 , V_144 -> V_26 ) ;
F_258 ( V_144 , F_102 ( V_14 ) ) ;
V_142 = V_144 -> V_142 ;
if ( F_248 ( V_14 , V_144 ) )
goto V_493;
if ( F_280 ( V_14 , V_157 ) && ! F_281 ( V_14 , V_157 ) )
V_142 -= V_314 ;
if ( V_14 -> V_62 == V_63 )
V_142 -= V_201 ;
if ( V_142 > V_14 -> V_410 ) {
F_70 ( V_14 -> V_3 , V_14 , V_114 ) ;
goto V_493;
}
V_490 = F_269 ( V_14 , V_157 ) ;
V_501 = F_252 ( V_14 , V_490 , V_14 -> V_287 ) ;
V_482 = F_252 ( V_14 , V_14 -> V_288 ,
V_14 -> V_287 ) ;
if ( V_501 > V_482 ) {
F_70 ( V_14 -> V_3 , V_14 , V_114 ) ;
goto V_493;
}
if ( ! F_281 ( V_14 , V_157 ) ) {
if ( V_142 < 0 ) {
F_70 ( V_14 -> V_3 , V_14 , V_114 ) ;
goto V_493;
}
F_267 ( V_14 , V_157 , V_144 ) ;
} else {
if ( V_142 != 0 ) {
F_219 ( L_52 , V_142 ) ;
F_70 ( V_14 -> V_3 , V_14 , V_114 ) ;
goto V_493;
}
F_277 ( V_14 , V_157 , V_144 ) ;
}
return 0 ;
V_493:
F_128 ( V_144 ) ;
return 0 ;
}
static inline int F_282 ( struct V_2 * V_3 , T_1 V_4 , struct V_143 * V_144 )
{
struct V_1 * V_14 ;
T_8 V_157 ;
T_1 V_289 ;
int V_142 ;
V_14 = F_4 ( V_3 , V_4 ) ;
if ( ! V_14 ) {
F_19 ( L_53 , V_4 ) ;
F_128 ( V_144 ) ;
return 0 ;
}
F_19 ( L_54 , V_14 , V_144 -> V_142 ) ;
if ( V_14 -> V_23 != V_48 )
goto V_493;
switch ( V_14 -> V_107 ) {
case V_267 :
if ( V_14 -> V_369 < V_144 -> V_142 )
goto V_493;
if ( ! V_14 -> V_24 -> V_327 ( V_14 -> V_26 , V_144 ) )
goto V_18;
break;
case V_108 :
F_279 ( V_14 , V_144 ) ;
goto V_18;
case V_229 :
V_157 = F_165 ( V_14 , V_144 -> V_26 ) ;
F_258 ( V_144 , F_102 ( V_14 ) ) ;
V_142 = V_144 -> V_142 ;
if ( F_248 ( V_14 , V_144 ) )
goto V_493;
if ( F_280 ( V_14 , V_157 ) )
V_142 -= V_314 ;
if ( V_14 -> V_62 == V_63 )
V_142 -= V_201 ;
if ( V_142 > V_14 -> V_410 || V_142 < 0 || F_281 ( V_14 , V_157 ) )
goto V_493;
V_289 = F_268 ( V_14 , V_157 ) ;
if ( V_14 -> V_349 != V_289 ) {
F_128 ( V_14 -> V_352 ) ;
V_14 -> V_352 = NULL ;
V_14 -> V_353 = NULL ;
V_14 -> V_317 = 0 ;
}
V_14 -> V_349 = F_168 ( V_14 , V_289 ) ;
if ( F_256 ( V_14 , V_144 , V_157 ) == - V_325 )
F_70 ( V_14 -> V_3 , V_14 , V_114 ) ;
goto V_18;
default:
F_19 ( L_55 , V_14 , V_14 -> V_107 ) ;
break;
}
V_493:
F_128 ( V_144 ) ;
V_18:
F_39 ( V_14 ) ;
return 0 ;
}
static inline int F_283 ( struct V_2 * V_3 , T_3 V_10 , struct V_143 * V_144 )
{
struct V_1 * V_14 ;
V_14 = F_137 ( 0 , V_10 , V_3 -> V_11 , V_3 -> V_241 ) ;
if ( ! V_14 )
goto V_493;
F_19 ( L_54 , V_14 , V_144 -> V_142 ) ;
if ( V_14 -> V_23 != V_271 && V_14 -> V_23 != V_48 )
goto V_493;
if ( V_14 -> V_369 < V_144 -> V_142 )
goto V_493;
if ( ! V_14 -> V_24 -> V_327 ( V_14 -> V_26 , V_144 ) )
return 0 ;
V_493:
F_128 ( V_144 ) ;
return 0 ;
}
static inline int F_284 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_143 * V_144 )
{
struct V_1 * V_14 ;
V_14 = F_115 ( 0 , V_4 , V_3 -> V_11 , V_3 -> V_241 ) ;
if ( ! V_14 )
goto V_493;
F_19 ( L_54 , V_14 , V_144 -> V_142 ) ;
if ( V_14 -> V_23 != V_271 && V_14 -> V_23 != V_48 )
goto V_493;
if ( V_14 -> V_369 < V_144 -> V_142 )
goto V_493;
if ( ! V_14 -> V_24 -> V_327 ( V_14 -> V_26 , V_144 ) )
return 0 ;
V_493:
F_128 ( V_144 ) ;
return 0 ;
}
static void F_285 ( struct V_2 * V_3 , struct V_143 * V_144 )
{
struct V_195 * V_196 = ( void * ) V_144 -> V_26 ;
T_1 V_4 , V_142 ;
T_3 V_10 ;
F_258 ( V_144 , V_194 ) ;
V_4 = F_52 ( V_196 -> V_4 ) ;
V_142 = F_52 ( V_196 -> V_142 ) ;
if ( V_142 != V_144 -> V_142 ) {
F_128 ( V_144 ) ;
return;
}
F_19 ( L_56 , V_142 , V_4 ) ;
switch ( V_4 ) {
case V_332 :
case V_84 :
F_247 ( V_3 , V_144 ) ;
break;
case V_83 :
V_10 = F_286 ( ( T_3 * ) V_144 -> V_26 ) ;
F_258 ( V_144 , 2 ) ;
F_283 ( V_3 , V_10 , V_144 ) ;
break;
case V_80 :
F_284 ( V_3 , V_4 , V_144 ) ;
break;
case V_502 :
if ( F_287 ( V_3 , V_144 ) )
F_127 ( V_3 -> V_76 , V_503 ) ;
break;
default:
F_282 ( V_3 , V_4 , V_144 ) ;
break;
}
}
int F_288 ( struct V_265 * V_145 , T_4 * V_263 )
{
int V_504 = 0 , V_505 = 0 , V_506 = 0 ;
struct V_1 * V_5 ;
F_19 ( L_57 , V_145 -> V_507 , F_139 ( V_263 ) ) ;
F_116 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_27 * V_13 = V_5 -> V_13 ;
if ( V_5 -> V_23 != V_115 )
continue;
if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , & V_145 -> V_263 ) ) {
V_505 |= V_508 ;
if ( F_60 ( V_509 , & V_5 -> V_71 ) )
V_505 |= V_467 ;
V_504 ++ ;
} else if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_247 ) ) {
V_506 |= V_508 ;
if ( F_60 ( V_509 , & V_5 -> V_71 ) )
V_506 |= V_467 ;
}
}
F_117 ( & V_16 ) ;
return V_504 ? V_505 : V_506 ;
}
int F_289 ( struct V_153 * V_76 , T_2 V_126 )
{
struct V_2 * V_3 ;
F_19 ( L_58 , V_76 , F_139 ( & V_76 -> V_241 ) , V_126 ) ;
if ( ! V_126 ) {
V_3 = F_133 ( V_76 , V_126 ) ;
if ( V_3 )
F_123 ( V_3 ) ;
} else
F_127 ( V_76 , F_290 ( V_126 ) ) ;
return 0 ;
}
int F_291 ( struct V_153 * V_76 )
{
struct V_2 * V_3 = V_76 -> V_255 ;
F_19 ( L_59 , V_76 ) ;
if ( ! V_3 )
return V_73 ;
return V_3 -> V_72 ;
}
int F_292 ( struct V_153 * V_76 , T_2 V_47 )
{
F_19 ( L_60 , V_76 , V_47 ) ;
F_127 ( V_76 , F_290 ( V_47 ) ) ;
return 0 ;
}
static inline void F_293 ( struct V_1 * V_14 , T_2 V_510 )
{
if ( V_14 -> V_74 != V_75 )
return;
if ( V_510 == 0x00 ) {
if ( V_14 -> V_52 == V_132 ) {
F_69 ( V_14 , V_511 ) ;
} else if ( V_14 -> V_52 == V_130 )
F_38 ( V_14 , V_50 ) ;
} else {
if ( V_14 -> V_52 == V_132 )
F_56 ( V_14 ) ;
}
}
int F_294 ( struct V_153 * V_76 , T_2 V_126 , T_2 V_510 )
{
struct V_2 * V_3 = V_76 -> V_255 ;
struct V_1 * V_14 ;
if ( ! V_3 )
return 0 ;
F_19 ( L_12 , V_3 ) ;
if ( V_76 -> type == V_77 ) {
if ( ! V_126 && V_510 )
F_295 ( V_3 , 0 ) ;
F_221 ( & V_3 -> V_258 ) ;
}
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
F_6 ( V_14 ) ;
F_19 ( L_61 , V_14 -> V_7 ) ;
if ( V_14 -> V_7 == V_80 ) {
if ( ! V_126 && V_510 ) {
V_14 -> V_52 = V_76 -> V_52 ;
F_109 ( V_14 ) ;
}
F_39 ( V_14 ) ;
continue;
}
if ( F_60 ( V_210 , & V_14 -> V_104 ) ) {
F_39 ( V_14 ) ;
continue;
}
if ( ! V_126 && ( V_14 -> V_23 == V_48 ||
V_14 -> V_23 == V_49 ) ) {
struct V_27 * V_13 = V_14 -> V_13 ;
F_225 ( V_512 , & F_11 ( V_13 ) -> V_71 ) ;
V_13 -> V_102 ( V_13 ) ;
F_293 ( V_14 , V_510 ) ;
F_39 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_51 ) {
if ( ! V_126 ) {
F_108 ( V_14 ) ;
} else {
F_69 ( V_14 , V_513 ) ;
}
} else if ( V_14 -> V_23 == V_118 ) {
struct V_27 * V_13 = V_14 -> V_13 ;
struct V_119 V_120 ;
T_5 V_514 , V_515 ;
F_22 ( V_13 ) ;
if ( ! V_126 ) {
if ( F_60 ( V_122 ,
& F_11 ( V_13 ) -> V_71 ) ) {
struct V_27 * V_98 = F_11 ( V_13 ) -> V_98 ;
V_514 = V_234 ;
V_515 = V_235 ;
if ( V_98 )
V_98 -> V_101 ( V_98 , 0 ) ;
} else {
F_18 ( V_14 , V_49 ) ;
V_514 = V_236 ;
V_515 = V_127 ;
}
} else {
F_18 ( V_14 , V_125 ) ;
F_69 ( V_14 , V_513 ) ;
V_514 = V_123 ;
V_515 = V_127 ;
}
F_23 ( V_13 ) ;
V_120 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_120 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_120 . V_121 = F_14 ( V_514 ) ;
V_120 . V_126 = F_14 ( V_515 ) ;
F_71 ( V_3 , V_14 -> V_9 , V_128 ,
sizeof( V_120 ) , & V_120 ) ;
}
F_39 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
int F_296 ( struct V_153 * V_76 , struct V_143 * V_144 , T_1 V_71 )
{
struct V_2 * V_3 = V_76 -> V_255 ;
if ( ! V_3 )
V_3 = F_133 ( V_76 , 0 ) ;
if ( ! V_3 )
goto V_493;
F_19 ( L_62 , V_3 , V_144 -> V_142 , V_71 ) ;
if ( ! ( V_71 & V_516 ) ) {
struct V_195 * V_517 ;
int V_142 ;
if ( V_3 -> V_518 ) {
F_219 ( L_63 , V_144 -> V_142 ) ;
F_128 ( V_3 -> V_256 ) ;
V_3 -> V_256 = NULL ;
V_3 -> V_518 = 0 ;
F_125 ( V_3 , V_519 ) ;
}
if ( V_144 -> V_142 < V_194 ) {
F_219 ( L_64 , V_144 -> V_142 ) ;
F_125 ( V_3 , V_519 ) ;
goto V_493;
}
V_517 = (struct V_195 * ) V_144 -> V_26 ;
V_142 = F_52 ( V_517 -> V_142 ) + V_194 ;
if ( V_142 == V_144 -> V_142 ) {
F_285 ( V_3 , V_144 ) ;
return 0 ;
}
F_19 ( L_65 , V_142 , V_144 -> V_142 ) ;
if ( V_144 -> V_142 > V_142 ) {
F_219 ( L_66 ,
V_144 -> V_142 , V_142 ) ;
F_125 ( V_3 , V_519 ) ;
goto V_493;
}
V_3 -> V_256 = F_99 ( V_142 , V_56 ) ;
if ( ! V_3 -> V_256 )
goto V_493;
F_297 ( V_144 , F_100 ( V_3 -> V_256 , V_144 -> V_142 ) ,
V_144 -> V_142 ) ;
V_3 -> V_518 = V_142 - V_144 -> V_142 ;
} else {
F_19 ( L_67 , V_144 -> V_142 , V_3 -> V_518 ) ;
if ( ! V_3 -> V_518 ) {
F_219 ( L_68 , V_144 -> V_142 ) ;
F_125 ( V_3 , V_519 ) ;
goto V_493;
}
if ( V_144 -> V_142 > V_3 -> V_518 ) {
F_219 ( L_69 ,
V_144 -> V_142 , V_3 -> V_518 ) ;
F_128 ( V_3 -> V_256 ) ;
V_3 -> V_256 = NULL ;
V_3 -> V_518 = 0 ;
F_125 ( V_3 , V_519 ) ;
goto V_493;
}
F_297 ( V_144 , F_100 ( V_3 -> V_256 , V_144 -> V_142 ) ,
V_144 -> V_142 ) ;
V_3 -> V_518 -= V_144 -> V_142 ;
if ( ! V_3 -> V_518 ) {
F_285 ( V_3 , V_3 -> V_256 ) ;
V_3 -> V_256 = NULL ;
}
}
V_493:
F_128 ( V_144 ) ;
return 0 ;
}
static int F_298 ( struct V_520 * V_521 , void * V_19 )
{
struct V_1 * V_5 ;
F_116 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_27 * V_13 = V_5 -> V_13 ;
F_299 ( V_521 , L_70 ,
F_139 ( & F_11 ( V_13 ) -> V_11 ) ,
F_139 ( & F_11 ( V_13 ) -> V_241 ) ,
V_5 -> V_23 , F_52 ( V_5 -> V_10 ) ,
V_5 -> V_7 , V_5 -> V_6 , V_5 -> V_369 , V_5 -> V_78 ,
V_5 -> V_52 , V_5 -> V_107 ) ;
}
F_117 ( & V_16 ) ;
return 0 ;
}
static int F_300 ( struct V_522 * V_522 , struct V_523 * V_523 )
{
return F_301 ( V_523 , F_298 , V_522 -> V_524 ) ;
}
int T_10 F_302 ( void )
{
int V_15 ;
V_15 = F_303 () ;
if ( V_15 < 0 )
return V_15 ;
if ( V_525 ) {
V_526 = F_304 ( L_71 , 0444 ,
V_525 , NULL , & V_527 ) ;
if ( ! V_526 )
F_219 ( L_72 ) ;
}
return 0 ;
}
void F_305 ( void )
{
F_306 ( V_526 ) ;
F_307 () ;
}
