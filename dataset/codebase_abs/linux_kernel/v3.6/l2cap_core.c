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
F_55 ( & V_14 -> V_69 , 1 ) ;
F_56 ( V_70 , & V_14 -> V_71 ) ;
F_19 ( L_3 , V_14 ) ;
return V_14 ;
}
void F_57 ( struct V_1 * V_14 )
{
F_13 ( & V_16 ) ;
F_58 ( & V_14 -> V_66 ) ;
F_15 ( & V_16 ) ;
F_49 ( V_14 ) ;
}
void F_59 ( struct V_1 * V_14 )
{
V_14 -> V_72 = V_73 ;
V_14 -> V_74 = V_75 ;
V_14 -> V_76 = V_77 ;
V_14 -> V_78 = V_77 ;
V_14 -> V_79 = V_77 ;
V_14 -> V_60 = V_80 ;
F_56 ( V_81 , & V_14 -> V_82 ) ;
}
static void F_60 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_19 ( L_4 , V_3 ,
F_61 ( V_14 -> V_10 ) , V_14 -> V_6 ) ;
V_3 -> V_83 = V_84 ;
V_14 -> V_3 = V_3 ;
switch ( V_14 -> V_85 ) {
case V_86 :
if ( V_3 -> V_87 -> type == V_88 ) {
V_14 -> V_89 = V_90 ;
V_14 -> V_7 = V_91 ;
V_14 -> V_6 = V_91 ;
} else {
V_14 -> V_7 = F_17 ( V_3 ) ;
V_14 -> V_89 = V_90 ;
}
break;
case V_92 :
V_14 -> V_7 = V_93 ;
V_14 -> V_6 = V_93 ;
V_14 -> V_89 = V_90 ;
break;
case V_94 :
V_14 -> V_7 = V_95 ;
V_14 -> V_6 = V_95 ;
V_14 -> V_89 = V_96 ;
V_14 -> V_97 = V_96 ;
break;
default:
V_14 -> V_7 = V_98 ;
V_14 -> V_6 = V_98 ;
V_14 -> V_89 = V_90 ;
}
V_14 -> V_99 = V_100 ;
V_14 -> V_101 = V_102 ;
V_14 -> V_103 = V_104 ;
V_14 -> V_105 = V_106 ;
V_14 -> V_107 = V_108 ;
V_14 -> V_109 = V_110 ;
F_62 ( V_14 ) ;
F_53 ( & V_14 -> V_44 , & V_3 -> V_111 ) ;
}
void F_63 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_5 ( & V_3 -> V_8 ) ;
F_60 ( V_3 , V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
}
void F_64 ( struct V_1 * V_14 , int V_15 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
F_65 ( V_14 ) ;
F_19 ( L_5 , V_14 , V_3 , V_15 ) ;
if ( V_3 ) {
F_58 ( & V_14 -> V_44 ) ;
F_49 ( V_14 ) ;
V_14 -> V_3 = NULL ;
if ( V_14 -> V_85 != V_94 )
F_66 ( V_3 -> V_87 ) ;
}
if ( V_14 -> V_24 -> V_112 )
V_14 -> V_24 -> V_112 ( V_14 , V_15 ) ;
if ( F_67 ( V_70 , & V_14 -> V_71 ) )
return;
switch( V_14 -> V_113 ) {
case V_114 :
break;
case V_115 :
F_31 ( V_14 ) ;
F_68 ( V_14 ) ;
F_69 ( V_14 ) ;
F_70 ( & V_14 -> V_116 ) ;
F_38 ( & V_14 -> V_117 ) ;
F_38 ( & V_14 -> V_118 ) ;
case V_119 :
F_70 ( & V_14 -> V_120 ) ;
break;
}
return;
}
void F_47 ( struct V_1 * V_14 , int V_55 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_26 * V_13 = V_14 -> V_13 ;
F_19 ( L_6 , V_14 ,
F_20 ( V_14 -> V_23 ) , V_13 ) ;
switch ( V_14 -> V_23 ) {
case V_121 :
if ( V_14 -> V_24 -> V_112 )
V_14 -> V_24 -> V_112 ( V_14 , 0 ) ;
break;
case V_56 :
case V_57 :
if ( V_14 -> V_85 == V_86 &&
V_3 -> V_87 -> type == V_122 ) {
F_71 ( V_14 , V_13 -> V_123 ) ;
F_72 ( V_3 , V_14 , V_55 ) ;
} else
F_64 ( V_14 , V_55 ) ;
break;
case V_124 :
if ( V_14 -> V_85 == V_86 &&
V_3 -> V_87 -> type == V_122 ) {
struct V_125 V_126 ;
T_5 V_127 ;
if ( F_67 ( V_128 , & F_11 ( V_13 ) -> V_82 ) )
V_127 = V_129 ;
else
V_127 = V_130 ;
F_21 ( V_14 , V_131 ) ;
V_126 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_126 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_126 . V_127 = F_14 ( V_127 ) ;
V_126 . V_132 = F_73 ( V_133 ) ;
F_74 ( V_3 , V_14 -> V_9 , V_134 ,
sizeof( V_126 ) , & V_126 ) ;
}
F_64 ( V_14 , V_55 ) ;
break;
case V_59 :
case V_131 :
F_64 ( V_14 , V_55 ) ;
break;
default:
if ( V_14 -> V_24 -> V_112 )
V_14 -> V_24 -> V_112 ( V_14 , 0 ) ;
break;
}
}
static inline T_2 F_75 ( struct V_1 * V_14 )
{
if ( V_14 -> V_85 == V_135 ) {
switch ( V_14 -> V_60 ) {
case V_136 :
return V_137 ;
case V_138 :
return V_139 ;
default:
return V_140 ;
}
} else if ( V_14 -> V_10 == F_73 ( V_141 ) ) {
if ( V_14 -> V_60 == V_80 )
V_14 -> V_60 = V_61 ;
if ( V_14 -> V_60 == V_136 )
return V_142 ;
else
return V_140 ;
} else {
switch ( V_14 -> V_60 ) {
case V_136 :
return V_143 ;
case V_138 :
return V_144 ;
default:
return V_140 ;
}
}
}
int F_76 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
T_7 V_145 ;
V_145 = F_75 ( V_14 ) ;
return F_77 ( V_3 -> V_87 , V_14 -> V_60 , V_145 ) ;
}
static T_2 F_78 ( struct V_2 * V_3 )
{
T_2 V_146 ;
F_79 ( & V_3 -> V_65 ) ;
if ( ++ V_3 -> V_147 > 128 )
V_3 -> V_147 = 1 ;
V_146 = V_3 -> V_147 ;
F_80 ( & V_3 -> V_65 ) ;
return V_146 ;
}
static void F_74 ( struct V_2 * V_3 , T_2 V_9 , T_2 V_148 , T_1 V_149 , void * V_150 )
{
struct V_32 * V_36 = F_81 ( V_3 , V_148 , V_9 , V_149 , V_150 ) ;
T_2 V_82 ;
F_19 ( L_7 , V_148 ) ;
if ( ! V_36 )
return;
if ( F_82 ( V_3 -> V_87 -> V_151 ) )
V_82 = V_152 ;
else
V_82 = V_153 ;
F_34 ( V_36 ) -> V_154 = V_155 ;
V_36 -> V_156 = V_157 ;
F_83 ( V_3 -> V_158 , V_36 , V_82 ) ;
}
static void F_84 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
struct V_159 * V_87 = V_14 -> V_3 -> V_87 ;
T_1 V_82 ;
F_19 ( L_8 , V_14 , V_36 , V_36 -> V_149 ,
V_36 -> V_156 ) ;
if ( ! F_67 ( V_160 , & V_14 -> V_82 ) &&
F_82 ( V_87 -> V_151 ) )
V_82 = V_152 ;
else
V_82 = V_153 ;
F_34 ( V_36 ) -> V_154 = F_67 ( V_81 , & V_14 -> V_82 ) ;
F_83 ( V_14 -> V_3 -> V_158 , V_36 , V_82 ) ;
}
static void F_85 ( T_1 V_161 , struct V_162 * V_37 )
{
V_37 -> V_163 = ( V_161 & V_164 ) >> V_165 ;
V_37 -> V_166 = ( V_161 & V_167 ) >> V_168 ;
if ( V_161 & V_169 ) {
V_37 -> V_170 = 1 ;
V_37 -> V_171 = ( V_161 & V_172 ) >> V_173 ;
V_37 -> V_174 = ( V_161 & V_175 ) >> V_176 ;
V_37 -> V_177 = 0 ;
V_37 -> V_38 = 0 ;
} else {
V_37 -> V_170 = 0 ;
V_37 -> V_177 = ( V_161 & V_178 ) >> V_179 ;
V_37 -> V_38 = ( V_161 & V_180 ) >> V_181 ;
V_37 -> V_171 = 0 ;
V_37 -> V_174 = 0 ;
}
}
static void F_86 ( T_8 V_182 , struct V_162 * V_37 )
{
V_37 -> V_163 = ( V_182 & V_183 ) >> V_184 ;
V_37 -> V_166 = ( V_182 & V_185 ) >> V_186 ;
if ( V_182 & V_187 ) {
V_37 -> V_170 = 1 ;
V_37 -> V_171 = ( V_182 & V_188 ) >> V_189 ;
V_37 -> V_174 = ( V_182 & V_190 ) >> V_191 ;
V_37 -> V_177 = 0 ;
V_37 -> V_38 = 0 ;
} else {
V_37 -> V_170 = 0 ;
V_37 -> V_177 = ( V_182 & V_192 ) >> V_193 ;
V_37 -> V_38 = ( V_182 & V_194 ) >> V_195 ;
V_37 -> V_171 = 0 ;
V_37 -> V_174 = 0 ;
}
}
static inline void F_87 ( struct V_1 * V_14 ,
struct V_32 * V_36 )
{
if ( F_67 ( V_196 , & V_14 -> V_82 ) ) {
F_86 ( F_88 ( V_36 -> V_150 ) ,
& F_34 ( V_36 ) -> V_37 ) ;
F_89 ( V_36 , V_197 ) ;
} else {
F_85 ( F_90 ( V_36 -> V_150 ) ,
& F_34 ( V_36 ) -> V_37 ) ;
F_89 ( V_36 , V_198 ) ;
}
}
static T_8 F_91 ( struct V_162 * V_37 )
{
T_8 V_199 ;
V_199 = V_37 -> V_163 << V_184 ;
V_199 |= V_37 -> V_166 << V_186 ;
if ( V_37 -> V_170 ) {
V_199 |= V_37 -> V_171 << V_189 ;
V_199 |= V_37 -> V_174 << V_191 ;
V_199 |= V_187 ;
} else {
V_199 |= V_37 -> V_177 << V_193 ;
V_199 |= V_37 -> V_38 << V_195 ;
}
return V_199 ;
}
static T_1 F_92 ( struct V_162 * V_37 )
{
T_1 V_199 ;
V_199 = V_37 -> V_163 << V_165 ;
V_199 |= V_37 -> V_166 << V_168 ;
if ( V_37 -> V_170 ) {
V_199 |= V_37 -> V_171 << V_173 ;
V_199 |= V_37 -> V_174 << V_176 ;
V_199 |= V_169 ;
} else {
V_199 |= V_37 -> V_177 << V_179 ;
V_199 |= V_37 -> V_38 << V_181 ;
}
return V_199 ;
}
static inline void F_93 ( struct V_1 * V_14 ,
struct V_162 * V_37 ,
struct V_32 * V_36 )
{
if ( F_67 ( V_196 , & V_14 -> V_82 ) ) {
F_94 ( F_91 ( V_37 ) ,
V_36 -> V_150 + V_200 ) ;
} else {
F_95 ( F_92 ( V_37 ) ,
V_36 -> V_150 + V_200 ) ;
}
}
static inline unsigned int F_96 ( struct V_1 * V_14 )
{
if ( F_67 ( V_196 , & V_14 -> V_82 ) )
return V_201 ;
else
return V_202 ;
}
static struct V_32 * F_97 ( struct V_1 * V_14 ,
T_8 V_37 )
{
struct V_32 * V_36 ;
struct V_203 * V_204 ;
int V_205 = F_96 ( V_14 ) ;
if ( V_14 -> V_72 == V_73 )
V_205 += V_206 ;
V_36 = F_98 ( V_205 , V_45 ) ;
if ( ! V_36 )
return F_99 ( - V_46 ) ;
V_204 = (struct V_203 * ) F_100 ( V_36 , V_200 ) ;
V_204 -> V_149 = F_14 ( V_205 - V_200 ) ;
V_204 -> V_4 = F_14 ( V_14 -> V_6 ) ;
if ( F_67 ( V_196 , & V_14 -> V_82 ) )
F_94 ( V_37 , F_100 ( V_36 , V_197 ) ) ;
else
F_95 ( V_37 , F_100 ( V_36 , V_198 ) ) ;
if ( V_14 -> V_72 == V_73 ) {
T_1 V_72 = F_101 ( 0 , ( T_2 * ) V_36 -> V_150 , V_36 -> V_149 ) ;
F_95 ( V_72 , F_100 ( V_36 , V_206 ) ) ;
}
V_36 -> V_156 = V_157 ;
return V_36 ;
}
static void F_102 ( struct V_1 * V_14 ,
struct V_162 * V_37 )
{
struct V_32 * V_36 ;
T_8 V_207 ;
F_19 ( L_9 , V_14 , V_37 ) ;
if ( ! V_37 -> V_170 )
return;
if ( F_103 ( V_208 , & V_14 -> V_209 ) &&
! V_37 -> V_171 )
V_37 -> V_166 = 1 ;
if ( V_37 -> V_174 == V_210 )
F_104 ( V_211 , & V_14 -> V_209 ) ;
else if ( V_37 -> V_174 == V_212 )
F_56 ( V_211 , & V_14 -> V_209 ) ;
if ( V_37 -> V_174 != V_213 ) {
V_14 -> V_214 = V_37 -> V_163 ;
F_69 ( V_14 ) ;
}
F_19 ( L_10 , V_37 -> V_163 ,
V_37 -> V_166 , V_37 -> V_171 , V_37 -> V_174 ) ;
if ( F_67 ( V_196 , & V_14 -> V_82 ) )
V_207 = F_91 ( V_37 ) ;
else
V_207 = F_92 ( V_37 ) ;
V_36 = F_97 ( V_14 , V_207 ) ;
if ( ! F_105 ( V_36 ) )
F_84 ( V_14 , V_36 ) ;
}
static void F_106 ( struct V_1 * V_14 , bool V_171 )
{
struct V_162 V_37 ;
F_19 ( L_11 , V_14 , V_171 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_170 = 1 ;
V_37 . V_171 = V_171 ;
if ( F_67 ( V_215 , & V_14 -> V_209 ) )
V_37 . V_174 = V_212 ;
else
V_37 . V_174 = V_210 ;
V_37 . V_163 = V_14 -> V_216 ;
F_102 ( V_14 , & V_37 ) ;
}
static inline int F_107 ( struct V_1 * V_14 )
{
return ! F_67 ( V_217 , & V_14 -> V_71 ) ;
}
static void F_108 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_218 V_219 ;
V_219 . V_7 = F_14 ( V_14 -> V_7 ) ;
V_219 . V_10 = V_14 -> V_10 ;
V_14 -> V_9 = F_78 ( V_3 ) ;
F_56 ( V_217 , & V_14 -> V_71 ) ;
F_74 ( V_3 , V_14 -> V_9 , V_220 , sizeof( V_219 ) , & V_219 ) ;
}
static void F_109 ( struct V_1 * V_14 )
{
V_14 -> V_71 = 0 ;
F_65 ( V_14 ) ;
V_14 -> V_23 = V_56 ;
V_14 -> V_24 -> V_221 ( V_14 ) ;
}
static void F_110 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
if ( V_3 -> V_87 -> type == V_88 ) {
F_109 ( V_14 ) ;
return;
}
if ( V_3 -> V_222 & V_223 ) {
if ( ! ( V_3 -> V_222 & V_224 ) )
return;
if ( F_76 ( V_14 ) &&
F_107 ( V_14 ) )
F_108 ( V_14 ) ;
} else {
struct V_225 V_219 ;
V_219 . type = F_73 ( V_226 ) ;
V_3 -> V_222 |= V_223 ;
V_3 -> V_227 = F_78 ( V_3 ) ;
F_111 ( & V_3 -> V_228 , V_229 ) ;
F_74 ( V_3 , V_3 -> V_227 ,
V_230 , sizeof( V_219 ) , & V_219 ) ;
}
}
static inline int F_112 ( T_7 V_113 , T_9 V_231 )
{
T_8 V_232 = V_233 ;
if ( ! V_234 )
V_232 |= V_235 | V_236 ;
switch ( V_113 ) {
case V_115 :
return V_235 & V_231 & V_232 ;
case V_119 :
return V_236 & V_231 & V_232 ;
default:
return 0x00 ;
}
}
static void F_72 ( struct V_2 * V_3 , struct V_1 * V_14 , int V_15 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
struct V_237 V_219 ;
if ( ! V_3 )
return;
if ( V_14 -> V_113 == V_115 && V_14 -> V_23 == V_56 ) {
F_31 ( V_14 ) ;
F_68 ( V_14 ) ;
F_69 ( V_14 ) ;
}
if ( V_14 -> V_85 == V_94 ) {
F_18 ( V_14 , V_131 ) ;
return;
}
V_219 . V_6 = F_14 ( V_14 -> V_6 ) ;
V_219 . V_7 = F_14 ( V_14 -> V_7 ) ;
F_74 ( V_3 , F_78 ( V_3 ) ,
V_238 , sizeof( V_219 ) , & V_219 ) ;
F_22 ( V_13 ) ;
F_18 ( V_14 , V_131 ) ;
F_24 ( V_14 , V_15 ) ;
F_23 ( V_13 ) ;
}
static void F_113 ( struct V_2 * V_3 )
{
struct V_1 * V_14 , * V_239 ;
F_19 ( L_12 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_114 (chan, tmp, &conn->chan_l, list) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_6 ( V_14 ) ;
if ( V_14 -> V_85 != V_86 ) {
F_48 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_59 ) {
if ( ! F_76 ( V_14 ) ||
! F_107 ( V_14 ) ) {
F_48 ( V_14 ) ;
continue;
}
if ( ! F_112 ( V_14 -> V_113 , V_3 -> V_231 )
&& F_67 ( V_240 ,
& V_14 -> V_71 ) ) {
F_47 ( V_14 , V_241 ) ;
F_48 ( V_14 ) ;
continue;
}
F_108 ( V_14 ) ;
} else if ( V_14 -> V_23 == V_124 ) {
struct V_125 V_126 ;
char V_242 [ 128 ] ;
V_126 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_126 . V_6 = F_14 ( V_14 -> V_7 ) ;
if ( F_76 ( V_14 ) ) {
F_22 ( V_13 ) ;
if ( F_67 ( V_128 ,
& F_11 ( V_13 ) -> V_82 ) ) {
struct V_26 * V_243 = F_11 ( V_13 ) -> V_243 ;
V_126 . V_127 = F_73 ( V_244 ) ;
V_126 . V_132 = F_73 ( V_245 ) ;
if ( V_243 )
V_243 -> V_246 ( V_243 , 0 ) ;
} else {
F_18 ( V_14 , V_57 ) ;
V_126 . V_127 = F_73 ( V_247 ) ;
V_126 . V_132 = F_73 ( V_133 ) ;
}
F_23 ( V_13 ) ;
} else {
V_126 . V_127 = F_73 ( V_244 ) ;
V_126 . V_132 = F_73 ( V_248 ) ;
}
F_74 ( V_3 , V_14 -> V_9 , V_134 ,
sizeof( V_126 ) , & V_126 ) ;
if ( F_67 ( V_249 , & V_14 -> V_71 ) ||
V_126 . V_127 != V_247 ) {
F_48 ( V_14 ) ;
continue;
}
F_56 ( V_249 , & V_14 -> V_71 ) ;
F_74 ( V_3 , F_78 ( V_3 ) , V_250 ,
F_115 ( V_14 , V_242 ) , V_242 ) ;
V_14 -> V_251 ++ ;
}
F_48 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_1 * F_116 ( int V_23 , T_1 V_4 ,
T_4 * V_11 ,
T_4 * V_252 )
{
struct V_1 * V_5 , * V_253 = NULL ;
F_117 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_7 == V_4 ) {
int V_254 , V_255 ;
int V_256 , V_257 ;
V_254 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_11 ) ;
V_255 = ! F_10 ( & F_11 ( V_13 ) -> V_252 , V_252 ) ;
if ( V_254 && V_255 ) {
F_118 ( & V_16 ) ;
return V_5 ;
}
V_256 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_258 ) ;
V_257 = ! F_10 ( & F_11 ( V_13 ) -> V_252 , V_258 ) ;
if ( ( V_254 && V_257 ) || ( V_256 && V_255 ) ||
( V_256 && V_257 ) )
V_253 = V_5 ;
}
}
F_118 ( & V_16 ) ;
return V_253 ;
}
static void F_119 ( struct V_2 * V_3 )
{
struct V_26 * V_243 , * V_13 ;
struct V_1 * V_14 , * V_259 ;
F_19 ( L_13 ) ;
V_259 = F_116 ( V_121 , V_91 ,
V_3 -> V_11 , V_3 -> V_252 ) ;
if ( ! V_259 )
return;
V_243 = V_259 -> V_13 ;
F_22 ( V_243 ) ;
V_14 = V_259 -> V_24 -> V_260 ( V_259 ) ;
if ( ! V_14 )
goto V_261;
V_13 = V_14 -> V_13 ;
F_120 ( V_3 -> V_87 ) ;
V_3 -> V_87 -> V_262 = V_263 ;
F_121 ( & F_11 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_121 ( & F_11 ( V_13 ) -> V_252 , V_3 -> V_252 ) ;
F_122 ( V_243 , V_13 ) ;
F_63 ( V_3 , V_14 ) ;
F_109 ( V_14 ) ;
V_261:
F_23 ( V_243 ) ;
}
static void F_123 ( struct V_2 * V_3 )
{
struct V_1 * V_14 ;
struct V_159 * V_87 = V_3 -> V_87 ;
F_19 ( L_12 , V_3 ) ;
if ( ! V_87 -> V_264 && V_87 -> type == V_88 )
F_119 ( V_3 ) ;
if ( V_87 -> V_264 && V_87 -> type == V_88 )
F_124 ( V_87 , V_87 -> V_265 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
F_6 ( V_14 ) ;
if ( V_14 -> V_85 == V_94 ) {
F_48 ( V_14 ) ;
continue;
}
if ( V_87 -> type == V_88 ) {
if ( F_124 ( V_87 , V_14 -> V_60 ) )
F_109 ( V_14 ) ;
} else if ( V_14 -> V_85 != V_86 ) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_65 ( V_14 ) ;
F_22 ( V_13 ) ;
F_18 ( V_14 , V_56 ) ;
V_13 -> V_266 ( V_13 ) ;
F_23 ( V_13 ) ;
} else if ( V_14 -> V_23 == V_59 )
F_110 ( V_14 ) ;
F_48 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static void F_125 ( struct V_2 * V_3 , int V_15 )
{
struct V_1 * V_14 ;
F_19 ( L_12 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
if ( F_67 ( V_267 , & V_14 -> V_82 ) )
F_24 ( V_14 , V_15 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static void F_126 ( struct V_52 * V_53 )
{
struct V_2 * V_3 = F_46 ( V_53 , struct V_2 ,
V_228 . V_53 ) ;
V_3 -> V_222 |= V_224 ;
V_3 -> V_227 = 0 ;
F_113 ( V_3 ) ;
}
static void F_127 ( struct V_159 * V_87 , int V_15 )
{
struct V_2 * V_3 = V_87 -> V_268 ;
struct V_1 * V_14 , * V_269 ;
if ( ! V_3 )
return;
F_19 ( L_14 , V_87 , V_3 , V_15 ) ;
F_128 ( V_3 -> V_270 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_114 (chan, l, &conn->chan_l, list) {
F_62 ( V_14 ) ;
F_6 ( V_14 ) ;
F_64 ( V_14 , V_15 ) ;
F_48 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_49 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
F_129 ( V_3 -> V_158 ) ;
if ( V_3 -> V_222 & V_223 )
F_130 ( & V_3 -> V_228 ) ;
if ( F_103 ( V_271 , & V_87 -> V_82 ) ) {
F_130 ( & V_3 -> V_272 ) ;
F_131 ( V_3 ) ;
}
V_87 -> V_268 = NULL ;
F_39 ( V_3 ) ;
}
static void F_132 ( struct V_52 * V_53 )
{
struct V_2 * V_3 = F_46 ( V_53 , struct V_2 ,
V_272 . V_53 ) ;
F_19 ( L_12 , V_3 ) ;
if ( F_103 ( V_271 , & V_3 -> V_87 -> V_82 ) ) {
F_131 ( V_3 ) ;
F_127 ( V_3 -> V_87 , V_62 ) ;
}
}
static struct V_2 * F_133 ( struct V_159 * V_87 , T_2 V_132 )
{
struct V_2 * V_3 = V_87 -> V_268 ;
struct V_273 * V_158 ;
if ( V_3 || V_132 )
return V_3 ;
V_158 = F_134 ( V_87 ) ;
if ( ! V_158 )
return NULL ;
V_3 = F_51 ( sizeof( struct V_2 ) , V_64 ) ;
if ( ! V_3 ) {
F_129 ( V_158 ) ;
return NULL ;
}
V_87 -> V_268 = V_3 ;
V_3 -> V_87 = V_87 ;
V_3 -> V_158 = V_158 ;
F_19 ( L_15 , V_87 , V_3 , V_158 ) ;
if ( V_87 -> V_151 -> V_274 && V_87 -> type == V_88 )
V_3 -> V_275 = V_87 -> V_151 -> V_274 ;
else
V_3 -> V_275 = V_87 -> V_151 -> V_276 ;
V_3 -> V_11 = & V_87 -> V_151 -> V_277 ;
V_3 -> V_252 = & V_87 -> V_252 ;
V_3 -> V_231 = 0 ;
F_135 ( & V_3 -> V_65 ) ;
F_52 ( & V_3 -> V_8 ) ;
F_136 ( & V_3 -> V_111 ) ;
if ( V_87 -> type == V_88 )
F_54 ( & V_3 -> V_272 , F_132 ) ;
else
F_54 ( & V_3 -> V_228 , F_126 ) ;
V_3 -> V_83 = V_84 ;
return V_3 ;
}
static struct V_1 * F_137 ( int V_23 , T_3 V_10 ,
T_4 * V_11 ,
T_4 * V_252 )
{
struct V_1 * V_5 , * V_253 = NULL ;
F_117 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_10 == V_10 ) {
int V_254 , V_255 ;
int V_256 , V_257 ;
V_254 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_11 ) ;
V_255 = ! F_10 ( & F_11 ( V_13 ) -> V_252 , V_252 ) ;
if ( V_254 && V_255 ) {
F_118 ( & V_16 ) ;
return V_5 ;
}
V_256 = ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_258 ) ;
V_257 = ! F_10 ( & F_11 ( V_13 ) -> V_252 , V_258 ) ;
if ( ( V_254 && V_257 ) || ( V_256 && V_255 ) ||
( V_256 && V_257 ) )
V_253 = V_5 ;
}
}
F_118 ( & V_16 ) ;
return V_253 ;
}
int F_138 ( struct V_1 * V_14 , T_3 V_10 , T_1 V_4 ,
T_4 * V_252 , T_2 V_278 )
{
struct V_26 * V_13 = V_14 -> V_13 ;
T_4 * V_11 = & F_11 ( V_13 ) -> V_11 ;
struct V_2 * V_3 ;
struct V_159 * V_87 ;
struct V_279 * V_151 ;
T_7 V_145 ;
int V_15 ;
F_19 ( L_16 , F_139 ( V_11 ) , F_139 ( V_252 ) ,
V_278 , F_61 ( V_14 -> V_10 ) ) ;
V_151 = F_140 ( V_252 , V_11 ) ;
if ( ! V_151 )
return - V_280 ;
F_141 ( V_151 ) ;
F_6 ( V_14 ) ;
if ( ( F_61 ( V_10 ) & 0x0101 ) != 0x0001 && ! V_4 &&
V_14 -> V_85 != V_135 ) {
V_15 = - V_20 ;
goto V_18;
}
if ( V_14 -> V_85 == V_86 && ! ( V_10 || V_4 ) ) {
V_15 = - V_20 ;
goto V_18;
}
switch ( V_14 -> V_113 ) {
case V_114 :
break;
case V_115 :
case V_119 :
if ( ! V_234 )
break;
default:
V_15 = - V_281 ;
goto V_18;
}
switch ( V_14 -> V_23 ) {
case V_59 :
case V_124 :
case V_57 :
V_15 = 0 ;
goto V_18;
case V_56 :
V_15 = - V_282 ;
goto V_18;
case V_68 :
case V_283 :
break;
default:
V_15 = - V_284 ;
goto V_18;
}
F_22 ( V_13 ) ;
F_121 ( & F_11 ( V_13 ) -> V_252 , V_252 ) ;
F_23 ( V_13 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_4 ;
V_145 = F_75 ( V_14 ) ;
if ( V_14 -> V_6 == V_91 )
V_87 = F_142 ( V_151 , V_88 , V_252 , V_278 ,
V_14 -> V_60 , V_145 ) ;
else
V_87 = F_142 ( V_151 , V_122 , V_252 , V_278 ,
V_14 -> V_60 , V_145 ) ;
if ( F_105 ( V_87 ) ) {
V_15 = F_143 ( V_87 ) ;
goto V_18;
}
V_3 = F_133 ( V_87 , 0 ) ;
if ( ! V_3 ) {
F_66 ( V_87 ) ;
V_15 = - V_46 ;
goto V_18;
}
if ( V_87 -> type == V_88 ) {
V_15 = 0 ;
if ( ! F_144 ( & V_3 -> V_111 ) ) {
V_15 = - V_285 ;
F_66 ( V_87 ) ;
}
if ( V_15 )
goto V_18;
}
F_121 ( V_11 , V_3 -> V_11 ) ;
F_48 ( V_14 ) ;
F_63 ( V_3 , V_14 ) ;
F_6 ( V_14 ) ;
F_21 ( V_14 , V_59 ) ;
F_71 ( V_14 , V_13 -> V_123 ) ;
if ( V_87 -> V_23 == V_56 ) {
if ( V_14 -> V_85 != V_86 ) {
F_65 ( V_14 ) ;
if ( F_76 ( V_14 ) )
F_21 ( V_14 , V_56 ) ;
} else
F_110 ( V_14 ) ;
}
V_15 = 0 ;
V_18:
F_48 ( V_14 ) ;
F_145 ( V_151 ) ;
F_146 ( V_151 ) ;
return V_15 ;
}
int F_147 ( struct V_26 * V_13 )
{
struct V_1 * V_14 = F_148 ( V_13 ) -> V_14 ;
F_149 ( V_286 , V_287 ) ;
int V_15 = 0 ;
int V_288 = V_289 / 5 ;
F_150 ( F_151 ( V_13 ) , & V_286 ) ;
F_152 ( V_290 ) ;
while ( V_14 -> V_291 > 0 && V_14 -> V_3 ) {
if ( ! V_288 )
V_288 = V_289 / 5 ;
if ( F_153 ( V_287 ) ) {
V_15 = F_154 ( V_288 ) ;
break;
}
F_23 ( V_13 ) ;
V_288 = F_155 ( V_288 ) ;
F_22 ( V_13 ) ;
F_152 ( V_290 ) ;
V_15 = F_156 ( V_13 ) ;
if ( V_15 )
break;
}
F_152 ( V_292 ) ;
F_157 ( F_151 ( V_13 ) , & V_286 ) ;
return V_15 ;
}
static void F_158 ( struct V_52 * V_53 )
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
F_159 ( V_14 , NULL , NULL , V_293 ) ;
F_48 ( V_14 ) ;
F_49 ( V_14 ) ;
}
static void F_160 ( struct V_52 * V_53 )
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
F_159 ( V_14 , NULL , NULL , V_294 ) ;
F_48 ( V_14 ) ;
F_49 ( V_14 ) ;
}
static void F_161 ( struct V_1 * V_14 ,
struct V_33 * V_295 )
{
struct V_32 * V_36 ;
struct V_162 * V_37 ;
F_19 ( L_17 , V_14 , V_295 ) ;
F_162 ( V_295 , & V_14 -> V_120 ) ;
while ( ! F_163 ( & V_14 -> V_120 ) ) {
V_36 = F_164 ( & V_14 -> V_120 ) ;
F_34 ( V_36 ) -> V_37 . V_296 = 1 ;
V_37 = & F_34 ( V_36 ) -> V_37 ;
V_37 -> V_163 = 0 ;
V_37 -> V_38 = V_14 -> V_297 ;
F_93 ( V_14 , V_37 , V_36 ) ;
if ( V_14 -> V_72 == V_73 ) {
T_1 V_72 = F_101 ( 0 , ( T_2 * ) V_36 -> V_150 , V_36 -> V_149 ) ;
F_95 ( V_72 , F_100 ( V_36 , V_206 ) ) ;
}
F_84 ( V_14 , V_36 ) ;
F_19 ( L_18 , V_37 -> V_38 ) ;
V_14 -> V_297 = F_165 ( V_14 , V_14 -> V_297 ) ;
V_14 -> V_298 ++ ;
}
}
static int F_166 ( struct V_1 * V_14 )
{
struct V_32 * V_36 , * V_299 ;
struct V_162 * V_37 ;
int V_300 = 0 ;
F_19 ( L_3 , V_14 ) ;
if ( V_14 -> V_23 != V_56 )
return - V_301 ;
if ( F_67 ( V_302 , & V_14 -> V_209 ) )
return 0 ;
while ( V_14 -> V_303 &&
V_14 -> V_291 < V_14 -> V_304 &&
V_14 -> V_305 == V_306 ) {
V_36 = V_14 -> V_303 ;
F_34 ( V_36 ) -> V_37 . V_296 = 1 ;
V_37 = & F_34 ( V_36 ) -> V_37 ;
if ( F_103 ( V_208 , & V_14 -> V_209 ) )
V_37 -> V_166 = 1 ;
V_37 -> V_163 = V_14 -> V_216 ;
V_14 -> V_214 = V_14 -> V_216 ;
V_37 -> V_38 = V_14 -> V_297 ;
F_93 ( V_14 , V_37 , V_36 ) ;
if ( V_14 -> V_72 == V_73 ) {
T_1 V_72 = F_101 ( 0 , ( T_2 * ) V_36 -> V_150 , V_36 -> V_149 ) ;
F_95 ( V_72 , F_100 ( V_36 , V_206 ) ) ;
}
V_299 = F_167 ( V_36 , V_45 ) ;
if ( ! V_299 )
break;
F_26 ( V_14 ) ;
V_14 -> V_297 = F_165 ( V_14 , V_14 -> V_297 ) ;
V_14 -> V_291 ++ ;
V_14 -> V_298 ++ ;
V_300 ++ ;
if ( F_168 ( & V_14 -> V_120 , V_36 ) )
V_14 -> V_303 = NULL ;
else
V_14 -> V_303 = F_169 ( & V_14 -> V_120 , V_36 ) ;
F_84 ( V_14 , V_299 ) ;
F_19 ( L_18 , V_37 -> V_38 ) ;
}
F_19 ( L_19 , V_300 ,
V_14 -> V_291 , F_170 ( & V_14 -> V_120 ) ) ;
return V_300 ;
}
static void F_171 ( struct V_1 * V_14 )
{
struct V_162 V_37 ;
struct V_32 * V_36 ;
struct V_32 * V_299 ;
T_1 V_35 ;
F_19 ( L_3 , V_14 ) ;
if ( F_67 ( V_302 , & V_14 -> V_209 ) )
return;
while ( V_14 -> V_118 . V_34 != V_48 ) {
V_35 = F_42 ( & V_14 -> V_118 ) ;
V_36 = F_32 ( & V_14 -> V_120 , V_35 ) ;
if ( ! V_36 ) {
F_19 ( L_20 ,
V_35 ) ;
continue;
}
F_34 ( V_36 ) -> V_37 . V_296 ++ ;
V_37 = F_34 ( V_36 ) -> V_37 ;
if ( V_14 -> V_74 != 0 &&
F_34 ( V_36 ) -> V_37 . V_296 > V_14 -> V_74 ) {
F_19 ( L_21 , V_14 -> V_74 ) ;
F_72 ( V_14 -> V_3 , V_14 , V_241 ) ;
F_43 ( & V_14 -> V_118 ) ;
break;
}
V_37 . V_163 = V_14 -> V_216 ;
if ( F_103 ( V_208 , & V_14 -> V_209 ) )
V_37 . V_166 = 1 ;
else
V_37 . V_166 = 0 ;
if ( F_172 ( V_36 ) ) {
V_299 = F_173 ( V_36 , V_64 ) ;
} else {
V_299 = F_167 ( V_36 , V_64 ) ;
}
if ( ! V_299 ) {
F_43 ( & V_14 -> V_118 ) ;
break;
}
if ( F_67 ( V_196 , & V_14 -> V_82 ) ) {
F_94 ( F_91 ( & V_37 ) ,
V_299 -> V_150 + V_200 ) ;
} else {
F_95 ( F_92 ( & V_37 ) ,
V_299 -> V_150 + V_200 ) ;
}
if ( V_14 -> V_72 == V_73 ) {
T_1 V_72 = F_101 ( 0 , ( T_2 * ) V_299 -> V_150 , V_299 -> V_149 ) ;
F_95 ( V_72 , F_100 ( V_299 ,
V_206 ) ) ;
}
F_84 ( V_14 , V_299 ) ;
F_19 ( L_22 , V_37 . V_38 ) ;
V_14 -> V_214 = V_14 -> V_216 ;
}
}
static void F_174 ( struct V_1 * V_14 ,
struct V_162 * V_37 )
{
F_19 ( L_9 , V_14 , V_37 ) ;
F_44 ( & V_14 -> V_118 , V_37 -> V_163 ) ;
F_171 ( V_14 ) ;
}
static void F_175 ( struct V_1 * V_14 ,
struct V_162 * V_37 )
{
struct V_32 * V_36 ;
F_19 ( L_9 , V_14 , V_37 ) ;
if ( V_37 -> V_171 )
F_56 ( V_208 , & V_14 -> V_209 ) ;
F_43 ( & V_14 -> V_118 ) ;
if ( F_67 ( V_302 , & V_14 -> V_209 ) )
return;
if ( V_14 -> V_291 ) {
F_33 (&chan->tx_q, skb) {
if ( F_34 ( V_36 ) -> V_37 . V_38 == V_37 -> V_163 ||
V_36 == V_14 -> V_303 )
break;
}
F_176 (&chan->tx_q, skb) {
if ( V_36 == V_14 -> V_303 )
break;
F_44 ( & V_14 -> V_118 ,
F_34 ( V_36 ) -> V_37 . V_38 ) ;
}
F_171 ( V_14 ) ;
}
}
static void F_177 ( struct V_1 * V_14 )
{
struct V_162 V_37 ;
T_1 V_307 = F_178 ( V_14 , V_14 -> V_216 ,
V_14 -> V_214 ) ;
int V_308 ;
F_19 ( L_23 ,
V_14 , V_14 -> V_214 , V_14 -> V_216 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_170 = 1 ;
if ( F_67 ( V_215 , & V_14 -> V_209 ) &&
V_14 -> V_309 == V_310 ) {
F_69 ( V_14 ) ;
V_37 . V_174 = V_212 ;
V_37 . V_163 = V_14 -> V_216 ;
F_102 ( V_14 , & V_37 ) ;
} else {
if ( ! F_67 ( V_302 , & V_14 -> V_209 ) ) {
F_166 ( V_14 ) ;
if ( V_14 -> V_216 == V_14 -> V_214 )
V_307 = 0 ;
}
V_308 = V_14 -> V_79 ;
V_308 += V_308 << 1 ;
V_308 >>= 2 ;
F_19 ( L_24 , V_307 ,
V_308 ) ;
if ( V_307 >= V_308 ) {
F_69 ( V_14 ) ;
V_37 . V_174 = V_210 ;
V_37 . V_163 = V_14 -> V_216 ;
F_102 ( V_14 , & V_37 ) ;
V_307 = 0 ;
}
if ( V_307 )
F_179 ( V_14 ) ;
}
}
static inline int F_180 ( struct V_1 * V_14 ,
struct V_311 * V_312 , int V_149 ,
int V_313 , struct V_32 * V_36 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * * V_314 ;
int V_300 = 0 ;
if ( F_181 ( F_100 ( V_36 , V_313 ) , V_312 -> V_315 , V_313 ) )
return - V_316 ;
V_300 += V_313 ;
V_149 -= V_313 ;
V_314 = & F_182 ( V_36 ) -> V_317 ;
while ( V_149 ) {
struct V_32 * V_239 ;
V_313 = F_183 (unsigned int, conn->mtu, len) ;
V_239 = V_14 -> V_24 -> V_318 ( V_14 , V_313 ,
V_312 -> V_319 & V_320 ) ;
if ( F_105 ( V_239 ) )
return F_143 ( V_239 ) ;
* V_314 = V_239 ;
if ( F_181 ( F_100 ( * V_314 , V_313 ) , V_312 -> V_315 , V_313 ) )
return - V_316 ;
( * V_314 ) -> V_156 = V_36 -> V_156 ;
V_300 += V_313 ;
V_149 -= V_313 ;
V_36 -> V_149 += ( * V_314 ) -> V_149 ;
V_36 -> V_321 += ( * V_314 ) -> V_149 ;
V_314 = & ( * V_314 ) -> V_322 ;
}
return V_300 ;
}
static struct V_32 * F_184 ( struct V_1 * V_14 ,
struct V_311 * V_312 , T_6 V_149 ,
T_8 V_156 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_313 , V_205 = V_200 + V_323 ;
struct V_203 * V_204 ;
F_19 ( L_25 , V_14 , V_149 , V_156 ) ;
V_313 = F_183 (unsigned int, (conn->mtu - hlen), len) ;
V_36 = V_14 -> V_24 -> V_318 ( V_14 , V_313 + V_205 ,
V_312 -> V_319 & V_320 ) ;
if ( F_105 ( V_36 ) )
return V_36 ;
V_36 -> V_156 = V_156 ;
V_204 = (struct V_203 * ) F_100 ( V_36 , V_200 ) ;
V_204 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_204 -> V_149 = F_14 ( V_149 + V_323 ) ;
F_185 ( V_14 -> V_10 , F_100 ( V_36 , V_323 ) ) ;
V_15 = F_180 ( V_14 , V_312 , V_149 , V_313 , V_36 ) ;
if ( F_186 ( V_15 < 0 ) ) {
F_128 ( V_36 ) ;
return F_99 ( V_15 ) ;
}
return V_36 ;
}
static struct V_32 * F_187 ( struct V_1 * V_14 ,
struct V_311 * V_312 , T_6 V_149 ,
T_8 V_156 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_313 ;
struct V_203 * V_204 ;
F_19 ( L_26 , V_14 , V_149 ) ;
V_313 = F_183 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
V_36 = V_14 -> V_24 -> V_318 ( V_14 , V_313 + V_200 ,
V_312 -> V_319 & V_320 ) ;
if ( F_105 ( V_36 ) )
return V_36 ;
V_36 -> V_156 = V_156 ;
V_204 = (struct V_203 * ) F_100 ( V_36 , V_200 ) ;
V_204 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_204 -> V_149 = F_14 ( V_149 ) ;
V_15 = F_180 ( V_14 , V_312 , V_149 , V_313 , V_36 ) ;
if ( F_186 ( V_15 < 0 ) ) {
F_128 ( V_36 ) ;
return F_99 ( V_15 ) ;
}
return V_36 ;
}
static struct V_32 * F_188 ( struct V_1 * V_14 ,
struct V_311 * V_312 , T_6 V_149 ,
T_1 V_324 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_32 * V_36 ;
int V_15 , V_313 , V_205 ;
struct V_203 * V_204 ;
F_19 ( L_26 , V_14 , V_149 ) ;
if ( ! V_3 )
return F_99 ( - V_301 ) ;
V_205 = F_96 ( V_14 ) ;
if ( V_324 )
V_205 += V_325 ;
if ( V_14 -> V_72 == V_73 )
V_205 += V_206 ;
V_313 = F_183 (unsigned int, (conn->mtu - hlen), len) ;
V_36 = V_14 -> V_24 -> V_318 ( V_14 , V_313 + V_205 ,
V_312 -> V_319 & V_320 ) ;
if ( F_105 ( V_36 ) )
return V_36 ;
V_204 = (struct V_203 * ) F_100 ( V_36 , V_200 ) ;
V_204 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_204 -> V_149 = F_14 ( V_149 + ( V_205 - V_200 ) ) ;
if ( F_67 ( V_196 , & V_14 -> V_82 ) )
F_94 ( 0 , F_100 ( V_36 , V_197 ) ) ;
else
F_95 ( 0 , F_100 ( V_36 , V_198 ) ) ;
if ( V_324 )
F_95 ( V_324 , F_100 ( V_36 , V_325 ) ) ;
V_15 = F_180 ( V_14 , V_312 , V_149 , V_313 , V_36 ) ;
if ( F_186 ( V_15 < 0 ) ) {
F_128 ( V_36 ) ;
return F_99 ( V_15 ) ;
}
F_34 ( V_36 ) -> V_37 . V_72 = V_14 -> V_72 ;
F_34 ( V_36 ) -> V_37 . V_296 = 0 ;
return V_36 ;
}
static int F_189 ( struct V_1 * V_14 ,
struct V_33 * V_326 ,
struct V_311 * V_312 , T_6 V_149 )
{
struct V_32 * V_36 ;
T_1 V_327 ;
T_6 V_328 ;
T_2 V_177 ;
F_19 ( L_27 , V_14 , V_312 , V_149 ) ;
V_328 = V_14 -> V_3 -> V_275 ;
V_328 = F_183 ( T_6 , V_328 , V_329 ) ;
if ( V_14 -> V_72 )
V_328 -= V_206 ;
V_328 -= F_96 ( V_14 ) ;
V_328 = F_183 ( T_6 , V_328 , V_14 -> V_330 ) ;
if ( V_149 <= V_328 ) {
V_177 = V_331 ;
V_327 = 0 ;
V_328 = V_149 ;
} else {
V_177 = V_332 ;
V_327 = V_149 ;
V_328 -= V_325 ;
}
while ( V_149 > 0 ) {
V_36 = F_188 ( V_14 , V_312 , V_328 , V_327 ) ;
if ( F_105 ( V_36 ) ) {
F_190 ( V_326 ) ;
return F_143 ( V_36 ) ;
}
F_34 ( V_36 ) -> V_37 . V_177 = V_177 ;
F_191 ( V_326 , V_36 ) ;
V_149 -= V_328 ;
if ( V_327 ) {
V_327 = 0 ;
V_328 += V_325 ;
}
if ( V_149 <= V_328 ) {
V_177 = V_333 ;
V_328 = V_149 ;
} else {
V_177 = V_334 ;
}
}
return 0 ;
}
int F_192 ( struct V_1 * V_14 , struct V_311 * V_312 , T_6 V_149 ,
T_8 V_156 )
{
struct V_32 * V_36 ;
int V_15 ;
struct V_33 V_326 ;
if ( V_14 -> V_85 == V_92 ) {
V_36 = F_184 ( V_14 , V_312 , V_149 , V_156 ) ;
if ( F_105 ( V_36 ) )
return F_143 ( V_36 ) ;
F_84 ( V_14 , V_36 ) ;
return V_149 ;
}
switch ( V_14 -> V_113 ) {
case V_114 :
if ( V_149 > V_14 -> V_89 )
return - V_335 ;
V_36 = F_187 ( V_14 , V_312 , V_149 , V_156 ) ;
if ( F_105 ( V_36 ) )
return F_143 ( V_36 ) ;
F_84 ( V_14 , V_36 ) ;
V_15 = V_149 ;
break;
case V_115 :
case V_119 :
if ( V_149 > V_14 -> V_89 ) {
V_15 = - V_335 ;
break;
}
F_193 ( & V_326 ) ;
V_15 = F_189 ( V_14 , & V_326 , V_312 , V_149 ) ;
if ( V_14 -> V_23 != V_56 ) {
F_190 ( & V_326 ) ;
V_15 = - V_301 ;
}
if ( V_15 )
break;
if ( V_14 -> V_113 == V_115 )
F_159 ( V_14 , NULL , & V_326 , V_336 ) ;
else
F_161 ( V_14 , & V_326 ) ;
V_15 = V_149 ;
F_190 ( & V_326 ) ;
break;
default:
F_19 ( L_28 , V_14 -> V_113 ) ;
V_15 = - V_284 ;
}
return V_15 ;
}
static void F_194 ( struct V_1 * V_14 , T_1 V_38 )
{
struct V_162 V_37 ;
T_1 V_35 ;
F_19 ( L_29 , V_14 , V_38 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_170 = 1 ;
V_37 . V_174 = V_213 ;
for ( V_35 = V_14 -> V_337 ; V_35 != V_38 ;
V_35 = F_165 ( V_14 , V_35 ) ) {
if ( ! F_32 ( & V_14 -> V_116 , V_35 ) ) {
V_37 . V_163 = V_35 ;
F_102 ( V_14 , & V_37 ) ;
F_44 ( & V_14 -> V_117 , V_35 ) ;
}
}
V_14 -> V_337 = F_165 ( V_14 , V_38 ) ;
}
static void F_195 ( struct V_1 * V_14 )
{
struct V_162 V_37 ;
F_19 ( L_3 , V_14 ) ;
if ( V_14 -> V_117 . V_49 == V_48 )
return;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_170 = 1 ;
V_37 . V_174 = V_213 ;
V_37 . V_163 = V_14 -> V_117 . V_49 ;
F_102 ( V_14 , & V_37 ) ;
}
static void F_196 ( struct V_1 * V_14 , T_1 V_38 )
{
struct V_162 V_37 ;
T_1 V_338 ;
T_1 V_35 ;
F_19 ( L_29 , V_14 , V_38 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_170 = 1 ;
V_37 . V_174 = V_213 ;
V_338 = V_14 -> V_117 . V_34 ;
do {
V_35 = F_42 ( & V_14 -> V_117 ) ;
if ( V_35 == V_38 || V_35 == V_48 )
break;
V_37 . V_163 = V_35 ;
F_102 ( V_14 , & V_37 ) ;
F_44 ( & V_14 -> V_117 , V_35 ) ;
} while ( V_14 -> V_117 . V_34 != V_338 );
}
static void F_197 ( struct V_1 * V_14 , T_1 V_163 )
{
struct V_32 * V_339 ;
T_1 V_340 ;
F_19 ( L_30 , V_14 , V_163 ) ;
if ( V_14 -> V_291 == 0 || V_163 == V_14 -> V_341 )
return;
F_19 ( L_31 ,
V_14 -> V_341 , V_14 -> V_291 ) ;
for ( V_340 = V_14 -> V_341 ; V_340 != V_163 ;
V_340 = F_165 ( V_14 , V_340 ) ) {
V_339 = F_32 ( & V_14 -> V_120 , V_340 ) ;
if ( V_339 ) {
F_198 ( V_339 , & V_14 -> V_120 ) ;
F_128 ( V_339 ) ;
V_14 -> V_291 -- ;
}
}
V_14 -> V_341 = V_163 ;
if ( V_14 -> V_291 == 0 )
F_31 ( V_14 ) ;
F_19 ( L_32 , V_14 -> V_291 ) ;
}
static void F_199 ( struct V_1 * V_14 )
{
F_19 ( L_3 , V_14 ) ;
V_14 -> V_337 = V_14 -> V_216 ;
F_43 ( & V_14 -> V_117 ) ;
F_70 ( & V_14 -> V_116 ) ;
V_14 -> V_309 = V_310 ;
}
static void F_200 ( struct V_1 * V_14 ,
struct V_162 * V_37 ,
struct V_33 * V_295 , T_2 V_342 )
{
F_19 ( L_33 , V_14 , V_37 , V_295 ,
V_342 ) ;
switch ( V_342 ) {
case V_336 :
if ( V_14 -> V_303 == NULL )
V_14 -> V_303 = F_201 ( V_295 ) ;
F_162 ( V_295 , & V_14 -> V_120 ) ;
F_166 ( V_14 ) ;
break;
case V_343 :
F_19 ( L_34 ) ;
F_56 ( V_215 , & V_14 -> V_209 ) ;
if ( V_14 -> V_309 == V_344 ) {
F_199 ( V_14 ) ;
}
F_177 ( V_14 ) ;
break;
case V_345 :
F_19 ( L_35 ) ;
F_104 ( V_215 , & V_14 -> V_209 ) ;
if ( F_67 ( V_211 , & V_14 -> V_209 ) ) {
struct V_162 V_346 ;
memset ( & V_346 , 0 , sizeof( V_346 ) ) ;
V_346 . V_170 = 1 ;
V_346 . V_174 = V_210 ;
V_346 . V_171 = 1 ;
V_346 . V_163 = V_14 -> V_216 ;
F_102 ( V_14 , & V_346 ) ;
V_14 -> V_347 = 1 ;
F_30 ( V_14 ) ;
V_14 -> V_305 = V_348 ;
}
break;
case V_349 :
F_197 ( V_14 , V_37 -> V_163 ) ;
break;
case V_350 :
F_106 ( V_14 , 1 ) ;
V_14 -> V_347 = 1 ;
F_30 ( V_14 ) ;
F_69 ( V_14 ) ;
V_14 -> V_305 = V_348 ;
break;
case V_294 :
F_106 ( V_14 , 1 ) ;
V_14 -> V_347 = 1 ;
F_30 ( V_14 ) ;
V_14 -> V_305 = V_348 ;
break;
case V_351 :
break;
default:
break;
}
}
static void F_202 ( struct V_1 * V_14 ,
struct V_162 * V_37 ,
struct V_33 * V_295 , T_2 V_342 )
{
F_19 ( L_33 , V_14 , V_37 , V_295 ,
V_342 ) ;
switch ( V_342 ) {
case V_336 :
if ( V_14 -> V_303 == NULL )
V_14 -> V_303 = F_201 ( V_295 ) ;
F_162 ( V_295 , & V_14 -> V_120 ) ;
break;
case V_343 :
F_19 ( L_34 ) ;
F_56 ( V_215 , & V_14 -> V_209 ) ;
if ( V_14 -> V_309 == V_344 ) {
F_199 ( V_14 ) ;
}
F_177 ( V_14 ) ;
break;
case V_345 :
F_19 ( L_35 ) ;
F_104 ( V_215 , & V_14 -> V_209 ) ;
if ( F_67 ( V_211 , & V_14 -> V_209 ) ) {
struct V_162 V_346 ;
memset ( & V_346 , 0 , sizeof( V_346 ) ) ;
V_346 . V_170 = 1 ;
V_346 . V_174 = V_210 ;
V_346 . V_171 = 1 ;
V_346 . V_163 = V_14 -> V_216 ;
F_102 ( V_14 , & V_346 ) ;
V_14 -> V_347 = 1 ;
F_30 ( V_14 ) ;
V_14 -> V_305 = V_348 ;
}
break;
case V_349 :
F_197 ( V_14 , V_37 -> V_163 ) ;
case V_351 :
if ( V_37 && V_37 -> V_166 ) {
F_68 ( V_14 ) ;
if ( V_14 -> V_291 > 0 )
F_26 ( V_14 ) ;
V_14 -> V_347 = 0 ;
V_14 -> V_305 = V_306 ;
F_19 ( L_36 , V_14 -> V_305 ) ;
}
break;
case V_350 :
break;
case V_293 :
if ( V_14 -> V_74 == 0 || V_14 -> V_347 < V_14 -> V_74 ) {
F_106 ( V_14 , 1 ) ;
F_30 ( V_14 ) ;
V_14 -> V_347 ++ ;
} else {
F_72 ( V_14 -> V_3 , V_14 , V_352 ) ;
}
break;
default:
break;
}
}
static void F_159 ( struct V_1 * V_14 , struct V_162 * V_37 ,
struct V_33 * V_295 , T_2 V_342 )
{
F_19 ( L_37 ,
V_14 , V_37 , V_295 , V_342 , V_14 -> V_305 ) ;
switch ( V_14 -> V_305 ) {
case V_306 :
F_200 ( V_14 , V_37 , V_295 , V_342 ) ;
break;
case V_348 :
F_202 ( V_14 , V_37 , V_295 , V_342 ) ;
break;
default:
break;
}
}
static void F_203 ( struct V_1 * V_14 ,
struct V_162 * V_37 )
{
F_19 ( L_9 , V_14 , V_37 ) ;
F_159 ( V_14 , V_37 , NULL , V_349 ) ;
}
static void F_204 ( struct V_1 * V_14 ,
struct V_162 * V_37 )
{
F_19 ( L_9 , V_14 , V_37 ) ;
F_159 ( V_14 , V_37 , NULL , V_351 ) ;
}
static void F_205 ( struct V_2 * V_3 , struct V_32 * V_36 )
{
struct V_32 * V_353 ;
struct V_1 * V_14 ;
F_19 ( L_12 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
struct V_26 * V_13 = V_14 -> V_13 ;
if ( V_14 -> V_85 != V_135 )
continue;
if ( V_36 -> V_13 == V_13 )
continue;
V_353 = F_167 ( V_36 , V_64 ) ;
if ( ! V_353 )
continue;
if ( V_14 -> V_24 -> V_354 ( V_14 , V_353 ) )
F_128 ( V_353 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_32 * F_81 ( struct V_2 * V_3 , T_2 V_148 ,
T_2 V_9 , T_1 V_355 , void * V_150 )
{
struct V_32 * V_36 , * * V_314 ;
struct V_356 * V_357 ;
struct V_203 * V_204 ;
int V_149 , V_313 ;
F_19 ( L_38 ,
V_3 , V_148 , V_9 , V_355 ) ;
V_149 = V_200 + V_358 + V_355 ;
V_313 = F_183 (unsigned int, conn->mtu, len) ;
V_36 = F_98 ( V_313 , V_64 ) ;
if ( ! V_36 )
return NULL ;
V_204 = (struct V_203 * ) F_100 ( V_36 , V_200 ) ;
V_204 -> V_149 = F_14 ( V_358 + V_355 ) ;
if ( V_3 -> V_87 -> type == V_88 )
V_204 -> V_4 = F_73 ( V_359 ) ;
else
V_204 -> V_4 = F_73 ( V_98 ) ;
V_357 = (struct V_356 * ) F_100 ( V_36 , V_358 ) ;
V_357 -> V_148 = V_148 ;
V_357 -> V_9 = V_9 ;
V_357 -> V_149 = F_14 ( V_355 ) ;
if ( V_355 ) {
V_313 -= V_200 + V_358 ;
memcpy ( F_100 ( V_36 , V_313 ) , V_150 , V_313 ) ;
V_150 += V_313 ;
}
V_149 -= V_36 -> V_149 ;
V_314 = & F_182 ( V_36 ) -> V_317 ;
while ( V_149 ) {
V_313 = F_183 (unsigned int, conn->mtu, len) ;
* V_314 = F_98 ( V_313 , V_64 ) ;
if ( ! * V_314 )
goto V_360;
memcpy ( F_100 ( * V_314 , V_313 ) , V_150 , V_313 ) ;
V_149 -= V_313 ;
V_150 += V_313 ;
V_314 = & ( * V_314 ) -> V_322 ;
}
return V_36 ;
V_360:
F_128 ( V_36 ) ;
return NULL ;
}
static inline int F_206 ( void * * V_361 , int * type , int * V_362 , unsigned long * V_363 )
{
struct V_364 * V_365 = * V_361 ;
int V_149 ;
V_149 = V_366 + V_365 -> V_149 ;
* V_361 += V_149 ;
* type = V_365 -> type ;
* V_362 = V_365 -> V_149 ;
switch ( V_365 -> V_149 ) {
case 1 :
* V_363 = * ( ( T_2 * ) V_365 -> V_363 ) ;
break;
case 2 :
* V_363 = F_90 ( V_365 -> V_363 ) ;
break;
case 4 :
* V_363 = F_88 ( V_365 -> V_363 ) ;
break;
default:
* V_363 = ( unsigned long ) V_365 -> V_363 ;
break;
}
F_19 ( L_39 , * type , V_365 -> V_149 , * V_363 ) ;
return V_149 ;
}
static void F_207 ( void * * V_361 , T_2 type , T_2 V_149 , unsigned long V_363 )
{
struct V_364 * V_365 = * V_361 ;
F_19 ( L_39 , type , V_149 , V_363 ) ;
V_365 -> type = type ;
V_365 -> V_149 = V_149 ;
switch ( V_149 ) {
case 1 :
* ( ( T_2 * ) V_365 -> V_363 ) = V_363 ;
break;
case 2 :
F_95 ( V_363 , V_365 -> V_363 ) ;
break;
case 4 :
F_94 ( V_363 , V_365 -> V_363 ) ;
break;
default:
memcpy ( V_365 -> V_363 , ( void * ) V_363 , V_149 ) ;
break;
}
* V_361 += V_366 + V_149 ;
}
static void F_208 ( void * * V_361 , struct V_1 * V_14 )
{
struct V_367 V_368 ;
switch ( V_14 -> V_113 ) {
case V_115 :
V_368 . V_146 = V_14 -> V_99 ;
V_368 . V_369 = V_14 -> V_101 ;
V_368 . V_370 = F_14 ( V_14 -> V_103 ) ;
V_368 . V_371 = F_209 ( V_14 -> V_105 ) ;
V_368 . V_372 = F_210 ( V_108 ) ;
V_368 . V_373 = F_210 ( V_110 ) ;
break;
case V_119 :
V_368 . V_146 = 1 ;
V_368 . V_369 = V_102 ;
V_368 . V_370 = F_14 ( V_14 -> V_103 ) ;
V_368 . V_371 = F_209 ( V_14 -> V_105 ) ;
V_368 . V_372 = 0 ;
V_368 . V_373 = 0 ;
break;
default:
return;
}
F_207 ( V_361 , V_374 , sizeof( V_368 ) ,
( unsigned long ) & V_368 ) ;
}
static void F_211 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_46 ( V_53 , struct V_1 ,
V_375 . V_53 ) ;
T_1 V_307 ;
F_19 ( L_3 , V_14 ) ;
F_6 ( V_14 ) ;
V_307 = F_178 ( V_14 , V_14 -> V_216 ,
V_14 -> V_214 ) ;
if ( V_307 )
F_106 ( V_14 , 0 ) ;
F_48 ( V_14 ) ;
F_49 ( V_14 ) ;
}
int F_212 ( struct V_1 * V_14 )
{
int V_15 ;
V_14 -> V_297 = 0 ;
V_14 -> V_337 = 0 ;
V_14 -> V_341 = 0 ;
V_14 -> V_291 = 0 ;
V_14 -> V_216 = 0 ;
V_14 -> V_298 = 0 ;
V_14 -> V_214 = 0 ;
V_14 -> V_376 = NULL ;
V_14 -> V_377 = NULL ;
V_14 -> V_327 = 0 ;
F_213 ( & V_14 -> V_120 ) ;
if ( V_14 -> V_113 != V_115 )
return 0 ;
V_14 -> V_309 = V_310 ;
V_14 -> V_305 = V_306 ;
F_54 ( & V_14 -> V_30 , F_160 ) ;
F_54 ( & V_14 -> V_28 , F_158 ) ;
F_54 ( & V_14 -> V_375 , F_211 ) ;
F_213 ( & V_14 -> V_116 ) ;
V_15 = F_35 ( & V_14 -> V_117 , V_14 -> V_76 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_35 ( & V_14 -> V_118 , V_14 -> V_304 ) ;
if ( V_15 < 0 )
F_38 ( & V_14 -> V_117 ) ;
return V_15 ;
}
static inline T_7 F_214 ( T_7 V_113 , T_5 V_378 )
{
switch ( V_113 ) {
case V_119 :
case V_115 :
if ( F_112 ( V_113 , V_378 ) )
return V_113 ;
default:
return V_114 ;
}
}
static inline bool F_215 ( struct V_1 * V_14 )
{
return V_379 && V_14 -> V_3 -> V_231 & V_380 ;
}
static inline bool F_216 ( struct V_1 * V_14 )
{
return V_379 && V_14 -> V_3 -> V_231 & V_381 ;
}
static inline void F_217 ( struct V_1 * V_14 )
{
if ( V_14 -> V_76 > V_77 &&
F_215 ( V_14 ) ) {
F_56 ( V_196 , & V_14 -> V_82 ) ;
V_14 -> V_78 = V_382 ;
} else {
V_14 -> V_76 = F_183 ( T_1 , V_14 -> V_76 ,
V_77 ) ;
V_14 -> V_78 = V_77 ;
}
V_14 -> V_79 = V_14 -> V_76 ;
}
static int F_115 ( struct V_1 * V_14 , void * V_150 )
{
struct V_383 * V_219 = V_150 ;
struct V_384 V_385 = { . V_113 = V_14 -> V_113 } ;
void * V_361 = V_219 -> V_150 ;
T_1 V_41 ;
F_19 ( L_3 , V_14 ) ;
if ( V_14 -> V_251 || V_14 -> V_386 )
goto V_18;
switch ( V_14 -> V_113 ) {
case V_119 :
case V_115 :
if ( F_67 ( V_240 , & V_14 -> V_71 ) )
break;
if ( F_216 ( V_14 ) )
F_56 ( V_387 , & V_14 -> V_82 ) ;
default:
V_14 -> V_113 = F_214 ( V_385 . V_113 , V_14 -> V_3 -> V_231 ) ;
break;
}
V_18:
if ( V_14 -> V_97 != V_90 )
F_207 ( & V_361 , V_388 , 2 , V_14 -> V_97 ) ;
switch ( V_14 -> V_113 ) {
case V_114 :
if ( ! ( V_14 -> V_3 -> V_231 & V_235 ) &&
! ( V_14 -> V_3 -> V_231 & V_236 ) )
break;
V_385 . V_113 = V_114 ;
V_385 . V_389 = 0 ;
V_385 . V_390 = 0 ;
V_385 . V_29 = 0 ;
V_385 . V_31 = 0 ;
V_385 . V_391 = 0 ;
F_207 ( & V_361 , V_392 , sizeof( V_385 ) ,
( unsigned long ) & V_385 ) ;
break;
case V_115 :
V_385 . V_113 = V_115 ;
V_385 . V_390 = V_14 -> V_74 ;
V_385 . V_29 = 0 ;
V_385 . V_31 = 0 ;
V_41 = F_183 ( T_1 , V_393 , V_14 -> V_3 -> V_275 -
V_201 -
V_325 -
V_206 ) ;
V_385 . V_391 = F_14 ( V_41 ) ;
F_217 ( V_14 ) ;
V_385 . V_389 = F_183 ( T_1 , V_14 -> V_76 ,
V_77 ) ;
F_207 ( & V_361 , V_392 , sizeof( V_385 ) ,
( unsigned long ) & V_385 ) ;
if ( F_67 ( V_387 , & V_14 -> V_82 ) )
F_208 ( & V_361 , V_14 ) ;
if ( ! ( V_14 -> V_3 -> V_231 & V_394 ) )
break;
if ( V_14 -> V_72 == V_395 ||
F_67 ( V_396 , & V_14 -> V_71 ) ) {
V_14 -> V_72 = V_395 ;
F_207 ( & V_361 , V_397 , 1 , V_14 -> V_72 ) ;
}
if ( F_67 ( V_196 , & V_14 -> V_82 ) )
F_207 ( & V_361 , V_398 , 2 ,
V_14 -> V_76 ) ;
break;
case V_119 :
F_217 ( V_14 ) ;
V_385 . V_113 = V_119 ;
V_385 . V_389 = 0 ;
V_385 . V_390 = 0 ;
V_385 . V_29 = 0 ;
V_385 . V_31 = 0 ;
V_41 = F_183 ( T_1 , V_393 , V_14 -> V_3 -> V_275 -
V_201 -
V_325 -
V_206 ) ;
V_385 . V_391 = F_14 ( V_41 ) ;
F_207 ( & V_361 , V_392 , sizeof( V_385 ) ,
( unsigned long ) & V_385 ) ;
if ( F_67 ( V_387 , & V_14 -> V_82 ) )
F_208 ( & V_361 , V_14 ) ;
if ( ! ( V_14 -> V_3 -> V_231 & V_394 ) )
break;
if ( V_14 -> V_72 == V_395 ||
F_67 ( V_396 , & V_14 -> V_71 ) ) {
V_14 -> V_72 = V_395 ;
F_207 ( & V_361 , V_397 , 1 , V_14 -> V_72 ) ;
}
break;
}
V_219 -> V_6 = F_14 ( V_14 -> V_6 ) ;
V_219 -> V_82 = F_73 ( 0 ) ;
return V_361 - V_150 ;
}
static int F_218 ( struct V_1 * V_14 , void * V_150 )
{
struct V_399 * V_126 = V_150 ;
void * V_361 = V_126 -> V_150 ;
void * V_219 = V_14 -> V_400 ;
int V_149 = V_14 -> V_401 ;
int type , V_402 , V_362 ;
unsigned long V_363 ;
struct V_384 V_385 = { . V_113 = V_114 } ;
struct V_367 V_368 ;
T_2 V_403 = 0 ;
T_1 V_275 = V_90 ;
T_1 V_127 = V_404 ;
T_1 V_41 ;
F_19 ( L_3 , V_14 ) ;
while ( V_149 >= V_366 ) {
V_149 -= F_206 ( & V_219 , & type , & V_362 , & V_363 ) ;
V_402 = type & V_405 ;
type &= V_406 ;
switch ( type ) {
case V_388 :
V_275 = V_363 ;
break;
case V_407 :
V_14 -> V_373 = V_363 ;
break;
case V_408 :
break;
case V_392 :
if ( V_362 == sizeof( V_385 ) )
memcpy ( & V_385 , ( void * ) V_363 , V_362 ) ;
break;
case V_397 :
if ( V_363 == V_395 )
F_56 ( V_396 , & V_14 -> V_71 ) ;
break;
case V_374 :
V_403 = 1 ;
if ( V_362 == sizeof( V_368 ) )
memcpy ( & V_368 , ( void * ) V_363 , V_362 ) ;
break;
case V_398 :
if ( ! V_379 )
return - V_58 ;
F_56 ( V_196 , & V_14 -> V_82 ) ;
F_56 ( V_409 , & V_14 -> V_71 ) ;
V_14 -> V_78 = V_382 ;
V_14 -> V_304 = V_363 ;
break;
default:
if ( V_402 )
break;
V_127 = V_410 ;
* ( ( T_2 * ) V_361 ++ ) = type ;
break;
}
}
if ( V_14 -> V_386 || V_14 -> V_251 > 1 )
goto V_18;
switch ( V_14 -> V_113 ) {
case V_119 :
case V_115 :
if ( ! F_67 ( V_240 , & V_14 -> V_71 ) ) {
V_14 -> V_113 = F_214 ( V_385 . V_113 ,
V_14 -> V_3 -> V_231 ) ;
break;
}
if ( V_403 ) {
if ( F_216 ( V_14 ) )
F_56 ( V_387 , & V_14 -> V_82 ) ;
else
return - V_58 ;
}
if ( V_14 -> V_113 != V_385 . V_113 )
return - V_58 ;
break;
}
V_18:
if ( V_14 -> V_113 != V_385 . V_113 ) {
V_127 = V_411 ;
V_385 . V_113 = V_14 -> V_113 ;
if ( V_14 -> V_386 == 1 )
return - V_58 ;
F_207 ( & V_361 , V_392 ,
sizeof( V_385 ) , ( unsigned long ) & V_385 ) ;
}
if ( V_127 == V_404 ) {
if ( V_275 < V_412 )
V_127 = V_411 ;
else {
V_14 -> V_89 = V_275 ;
F_56 ( V_413 , & V_14 -> V_71 ) ;
}
F_207 ( & V_361 , V_388 , 2 , V_14 -> V_89 ) ;
if ( V_403 ) {
if ( V_14 -> V_101 != V_414 &&
V_368 . V_369 != V_414 &&
V_368 . V_369 != V_14 -> V_101 ) {
V_127 = V_411 ;
if ( V_14 -> V_251 >= 1 )
return - V_58 ;
F_207 ( & V_361 , V_374 ,
sizeof( V_368 ) ,
( unsigned long ) & V_368 ) ;
} else {
V_127 = V_415 ;
F_56 ( V_416 , & V_14 -> V_71 ) ;
}
}
switch ( V_385 . V_113 ) {
case V_114 :
V_14 -> V_72 = V_395 ;
F_56 ( V_417 , & V_14 -> V_71 ) ;
break;
case V_115 :
if ( ! F_67 ( V_409 , & V_14 -> V_71 ) )
V_14 -> V_304 = V_385 . V_389 ;
else
V_385 . V_389 = V_77 ;
V_14 -> V_418 = V_385 . V_390 ;
V_41 = F_183 ( T_1 , F_219 ( V_385 . V_391 ) ,
V_14 -> V_3 -> V_275 -
V_201 -
V_325 -
V_206 ) ;
V_385 . V_391 = F_14 ( V_41 ) ;
V_14 -> V_330 = V_41 ;
V_385 . V_29 =
F_73 ( V_419 ) ;
V_385 . V_31 =
F_73 ( V_420 ) ;
F_56 ( V_417 , & V_14 -> V_71 ) ;
F_207 ( & V_361 , V_392 ,
sizeof( V_385 ) , ( unsigned long ) & V_385 ) ;
if ( F_67 ( V_387 , & V_14 -> V_82 ) ) {
V_14 -> V_421 = V_368 . V_146 ;
V_14 -> V_422 = V_368 . V_369 ;
V_14 -> V_423 = F_219 ( V_368 . V_370 ) ;
V_14 -> V_424 =
F_220 ( V_368 . V_373 ) ;
V_14 -> V_425 =
F_220 ( V_368 . V_372 ) ;
V_14 -> V_426 =
F_220 ( V_368 . V_371 ) ;
F_207 ( & V_361 , V_374 ,
sizeof( V_368 ) , ( unsigned long ) & V_368 ) ;
}
break;
case V_119 :
V_41 = F_183 ( T_1 , F_219 ( V_385 . V_391 ) ,
V_14 -> V_3 -> V_275 -
V_201 -
V_325 -
V_206 ) ;
V_385 . V_391 = F_14 ( V_41 ) ;
V_14 -> V_330 = V_41 ;
F_56 ( V_417 , & V_14 -> V_71 ) ;
F_207 ( & V_361 , V_392 ,
sizeof( V_385 ) , ( unsigned long ) & V_385 ) ;
break;
default:
V_127 = V_411 ;
memset ( & V_385 , 0 , sizeof( V_385 ) ) ;
V_385 . V_113 = V_14 -> V_113 ;
}
if ( V_127 == V_404 )
F_56 ( V_427 , & V_14 -> V_71 ) ;
}
V_126 -> V_7 = F_14 ( V_14 -> V_6 ) ;
V_126 -> V_127 = F_14 ( V_127 ) ;
V_126 -> V_82 = F_73 ( 0 ) ;
return V_361 - V_150 ;
}
static int F_221 ( struct V_1 * V_14 , void * V_126 , int V_149 , void * V_150 , T_1 * V_127 )
{
struct V_383 * V_219 = V_150 ;
void * V_361 = V_219 -> V_150 ;
int type , V_362 ;
unsigned long V_363 ;
struct V_384 V_385 = { . V_113 = V_114 } ;
struct V_367 V_368 ;
F_19 ( L_40 , V_14 , V_126 , V_149 , V_150 ) ;
while ( V_149 >= V_366 ) {
V_149 -= F_206 ( & V_126 , & type , & V_362 , & V_363 ) ;
switch ( type ) {
case V_388 :
if ( V_363 < V_412 ) {
* V_127 = V_411 ;
V_14 -> V_97 = V_412 ;
} else
V_14 -> V_97 = V_363 ;
F_207 ( & V_361 , V_388 , 2 , V_14 -> V_97 ) ;
break;
case V_407 :
V_14 -> V_373 = V_363 ;
F_207 ( & V_361 , V_407 ,
2 , V_14 -> V_373 ) ;
break;
case V_392 :
if ( V_362 == sizeof( V_385 ) )
memcpy ( & V_385 , ( void * ) V_363 , V_362 ) ;
if ( F_67 ( V_240 , & V_14 -> V_71 ) &&
V_385 . V_113 != V_14 -> V_113 )
return - V_58 ;
V_14 -> V_72 = 0 ;
F_207 ( & V_361 , V_392 ,
sizeof( V_385 ) , ( unsigned long ) & V_385 ) ;
break;
case V_398 :
V_14 -> V_79 = F_183 ( T_1 , V_363 , V_14 -> V_79 ) ;
F_207 ( & V_361 , V_398 , 2 ,
V_14 -> V_76 ) ;
break;
case V_374 :
if ( V_362 == sizeof( V_368 ) )
memcpy ( & V_368 , ( void * ) V_363 , V_362 ) ;
if ( V_14 -> V_101 != V_414 &&
V_368 . V_369 != V_414 &&
V_368 . V_369 != V_14 -> V_101 )
return - V_58 ;
F_207 ( & V_361 , V_374 ,
sizeof( V_368 ) , ( unsigned long ) & V_368 ) ;
break;
}
}
if ( V_14 -> V_113 == V_114 && V_14 -> V_113 != V_385 . V_113 )
return - V_58 ;
V_14 -> V_113 = V_385 . V_113 ;
if ( * V_127 == V_404 || * V_127 == V_415 ) {
switch ( V_385 . V_113 ) {
case V_115 :
V_14 -> V_29 = F_219 ( V_385 . V_29 ) ;
V_14 -> V_31 = F_219 ( V_385 . V_31 ) ;
V_14 -> V_428 = F_219 ( V_385 . V_391 ) ;
if ( ! F_67 ( V_196 , & V_14 -> V_82 ) )
V_14 -> V_79 = F_183 ( T_1 , V_14 -> V_79 ,
V_385 . V_389 ) ;
if ( F_67 ( V_387 , & V_14 -> V_82 ) ) {
V_14 -> V_103 = F_219 ( V_368 . V_370 ) ;
V_14 -> V_105 =
F_220 ( V_368 . V_371 ) ;
V_14 -> V_107 = F_220 ( V_368 . V_372 ) ;
V_14 -> V_109 =
F_220 ( V_368 . V_373 ) ;
}
break;
case V_119 :
V_14 -> V_428 = F_219 ( V_385 . V_391 ) ;
}
}
V_219 -> V_6 = F_14 ( V_14 -> V_6 ) ;
V_219 -> V_82 = F_73 ( 0 ) ;
return V_361 - V_150 ;
}
static int F_222 ( struct V_1 * V_14 , void * V_150 , T_1 V_127 , T_1 V_82 )
{
struct V_399 * V_126 = V_150 ;
void * V_361 = V_126 -> V_150 ;
F_19 ( L_3 , V_14 ) ;
V_126 -> V_7 = F_14 ( V_14 -> V_6 ) ;
V_126 -> V_127 = F_14 ( V_127 ) ;
V_126 -> V_82 = F_14 ( V_82 ) ;
return V_361 - V_150 ;
}
void F_223 ( struct V_1 * V_14 )
{
struct V_125 V_126 ;
struct V_2 * V_3 = V_14 -> V_3 ;
T_2 V_242 [ 128 ] ;
V_126 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_126 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_126 . V_127 = F_73 ( V_247 ) ;
V_126 . V_132 = F_73 ( V_133 ) ;
F_74 ( V_3 , V_14 -> V_9 ,
V_134 , sizeof( V_126 ) , & V_126 ) ;
if ( F_224 ( V_249 , & V_14 -> V_71 ) )
return;
F_74 ( V_3 , F_78 ( V_3 ) , V_250 ,
F_115 ( V_14 , V_242 ) , V_242 ) ;
V_14 -> V_251 ++ ;
}
static void F_225 ( struct V_1 * V_14 , void * V_126 , int V_149 )
{
int type , V_362 ;
unsigned long V_363 ;
T_1 V_429 = V_14 -> V_79 ;
struct V_384 V_385 = {
. V_113 = V_14 -> V_113 ,
. V_29 = F_73 ( V_419 ) ,
. V_31 = F_73 ( V_420 ) ,
. V_391 = F_14 ( V_14 -> V_97 ) ,
. V_389 = F_183 ( T_1 , V_14 -> V_79 , V_77 ) ,
} ;
F_19 ( L_41 , V_14 , V_126 , V_149 ) ;
if ( ( V_14 -> V_113 != V_115 ) && ( V_14 -> V_113 != V_119 ) )
return;
while ( V_149 >= V_366 ) {
V_149 -= F_206 ( & V_126 , & type , & V_362 , & V_363 ) ;
switch ( type ) {
case V_392 :
if ( V_362 == sizeof( V_385 ) )
memcpy ( & V_385 , ( void * ) V_363 , V_362 ) ;
break;
case V_398 :
V_429 = V_363 ;
break;
}
}
switch ( V_385 . V_113 ) {
case V_115 :
V_14 -> V_29 = F_219 ( V_385 . V_29 ) ;
V_14 -> V_31 = F_219 ( V_385 . V_31 ) ;
V_14 -> V_428 = F_219 ( V_385 . V_391 ) ;
if ( F_67 ( V_196 , & V_14 -> V_82 ) )
V_14 -> V_79 = F_183 ( T_1 , V_14 -> V_79 , V_429 ) ;
else
V_14 -> V_79 = F_183 ( T_1 , V_14 -> V_79 ,
V_385 . V_389 ) ;
break;
case V_119 :
V_14 -> V_428 = F_219 ( V_385 . V_391 ) ;
}
}
static inline int F_226 ( struct V_2 * V_3 , struct V_356 * V_357 , T_2 * V_150 )
{
struct V_430 * V_431 = (struct V_430 * ) V_150 ;
if ( V_431 -> V_55 != V_432 )
return 0 ;
if ( ( V_3 -> V_222 & V_223 ) &&
V_357 -> V_9 == V_3 -> V_227 ) {
F_227 ( & V_3 -> V_228 ) ;
V_3 -> V_222 |= V_224 ;
V_3 -> V_227 = 0 ;
F_113 ( V_3 ) ;
}
return 0 ;
}
static inline int F_228 ( struct V_2 * V_3 , struct V_356 * V_357 , T_2 * V_150 )
{
struct V_218 * V_219 = (struct V_218 * ) V_150 ;
struct V_125 V_126 ;
struct V_1 * V_14 = NULL , * V_259 ;
struct V_26 * V_243 , * V_13 = NULL ;
int V_127 , V_132 = V_133 ;
T_1 V_6 = 0 , V_7 = F_61 ( V_219 -> V_7 ) ;
T_3 V_10 = V_219 -> V_10 ;
F_19 ( L_42 , F_61 ( V_10 ) , V_7 ) ;
V_259 = F_137 ( V_121 , V_10 , V_3 -> V_11 , V_3 -> V_252 ) ;
if ( ! V_259 ) {
V_127 = V_130 ;
goto V_433;
}
V_243 = V_259 -> V_13 ;
F_5 ( & V_3 -> V_8 ) ;
F_22 ( V_243 ) ;
if ( V_10 != F_73 ( V_141 ) &&
! F_229 ( V_3 -> V_87 ) ) {
V_3 -> V_83 = V_434 ;
V_127 = V_129 ;
goto V_435;
}
V_127 = V_436 ;
if ( F_1 ( V_3 , V_7 ) )
goto V_435;
V_14 = V_259 -> V_24 -> V_260 ( V_259 ) ;
if ( ! V_14 )
goto V_435;
V_13 = V_14 -> V_13 ;
F_120 ( V_3 -> V_87 ) ;
F_121 ( & F_11 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_121 ( & F_11 ( V_13 ) -> V_252 , V_3 -> V_252 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_7 ;
F_122 ( V_243 , V_13 ) ;
F_60 ( V_3 , V_14 ) ;
V_6 = V_14 -> V_7 ;
F_71 ( V_14 , V_13 -> V_123 ) ;
V_14 -> V_9 = V_357 -> V_9 ;
if ( V_3 -> V_222 & V_224 ) {
if ( F_76 ( V_14 ) ) {
if ( F_67 ( V_128 , & F_11 ( V_13 ) -> V_82 ) ) {
F_18 ( V_14 , V_124 ) ;
V_127 = V_244 ;
V_132 = V_245 ;
V_243 -> V_246 ( V_243 , 0 ) ;
} else {
F_18 ( V_14 , V_57 ) ;
V_127 = V_247 ;
V_132 = V_133 ;
}
} else {
F_18 ( V_14 , V_124 ) ;
V_127 = V_244 ;
V_132 = V_248 ;
}
} else {
F_18 ( V_14 , V_124 ) ;
V_127 = V_244 ;
V_132 = V_133 ;
}
V_435:
F_23 ( V_243 ) ;
F_7 ( & V_3 -> V_8 ) ;
V_433:
V_126 . V_7 = F_14 ( V_7 ) ;
V_126 . V_6 = F_14 ( V_6 ) ;
V_126 . V_127 = F_14 ( V_127 ) ;
V_126 . V_132 = F_14 ( V_132 ) ;
F_74 ( V_3 , V_357 -> V_9 , V_134 , sizeof( V_126 ) , & V_126 ) ;
if ( V_127 == V_244 && V_132 == V_133 ) {
struct V_225 V_437 ;
V_437 . type = F_73 ( V_226 ) ;
V_3 -> V_222 |= V_223 ;
V_3 -> V_227 = F_78 ( V_3 ) ;
F_111 ( & V_3 -> V_228 , V_229 ) ;
F_74 ( V_3 , V_3 -> V_227 ,
V_230 , sizeof( V_437 ) , & V_437 ) ;
}
if ( V_14 && ! F_67 ( V_249 , & V_14 -> V_71 ) &&
V_127 == V_247 ) {
T_2 V_242 [ 128 ] ;
F_56 ( V_249 , & V_14 -> V_71 ) ;
F_74 ( V_3 , F_78 ( V_3 ) , V_250 ,
F_115 ( V_14 , V_242 ) , V_242 ) ;
V_14 -> V_251 ++ ;
}
return 0 ;
}
static inline int F_230 ( struct V_2 * V_3 , struct V_356 * V_357 , T_2 * V_150 )
{
struct V_125 * V_126 = (struct V_125 * ) V_150 ;
T_1 V_7 , V_6 , V_127 , V_132 ;
struct V_1 * V_14 ;
T_2 V_219 [ 128 ] ;
int V_15 ;
V_7 = F_61 ( V_126 -> V_7 ) ;
V_6 = F_61 ( V_126 -> V_6 ) ;
V_127 = F_61 ( V_126 -> V_127 ) ;
V_132 = F_61 ( V_126 -> V_132 ) ;
F_19 ( L_43 ,
V_6 , V_7 , V_127 , V_132 ) ;
F_5 ( & V_3 -> V_8 ) ;
if ( V_7 ) {
V_14 = F_3 ( V_3 , V_7 ) ;
if ( ! V_14 ) {
V_15 = - V_316 ;
goto V_438;
}
} else {
V_14 = F_8 ( V_3 , V_357 -> V_9 ) ;
if ( ! V_14 ) {
V_15 = - V_316 ;
goto V_438;
}
}
V_15 = 0 ;
F_6 ( V_14 ) ;
switch ( V_127 ) {
case V_247 :
F_21 ( V_14 , V_57 ) ;
V_14 -> V_9 = 0 ;
V_14 -> V_6 = V_6 ;
F_104 ( V_217 , & V_14 -> V_71 ) ;
if ( F_224 ( V_249 , & V_14 -> V_71 ) )
break;
F_74 ( V_3 , F_78 ( V_3 ) , V_250 ,
F_115 ( V_14 , V_219 ) , V_219 ) ;
V_14 -> V_251 ++ ;
break;
case V_244 :
F_56 ( V_217 , & V_14 -> V_71 ) ;
break;
default:
F_64 ( V_14 , V_58 ) ;
break;
}
F_48 ( V_14 ) ;
V_438:
F_7 ( & V_3 -> V_8 ) ;
return V_15 ;
}
static inline void F_231 ( struct V_1 * V_14 )
{
if ( V_14 -> V_113 != V_115 && V_14 -> V_113 != V_119 )
V_14 -> V_72 = V_395 ;
else if ( ! F_67 ( V_396 , & V_14 -> V_71 ) )
V_14 -> V_72 = V_73 ;
}
static inline int F_232 ( struct V_2 * V_3 , struct V_356 * V_357 , T_1 V_439 , T_2 * V_150 )
{
struct V_383 * V_219 = (struct V_383 * ) V_150 ;
T_1 V_6 , V_82 ;
T_2 V_126 [ 64 ] ;
struct V_1 * V_14 ;
int V_149 , V_15 = 0 ;
V_6 = F_61 ( V_219 -> V_6 ) ;
V_82 = F_61 ( V_219 -> V_82 ) ;
F_19 ( L_44 , V_6 , V_82 ) ;
V_14 = F_4 ( V_3 , V_6 ) ;
if ( ! V_14 )
return - V_440 ;
if ( V_14 -> V_23 != V_57 && V_14 -> V_23 != V_124 ) {
struct V_441 V_431 ;
V_431 . V_55 = F_73 ( V_442 ) ;
V_431 . V_7 = F_14 ( V_14 -> V_7 ) ;
V_431 . V_6 = F_14 ( V_14 -> V_6 ) ;
F_74 ( V_3 , V_357 -> V_9 , V_443 ,
sizeof( V_431 ) , & V_431 ) ;
goto V_438;
}
V_149 = V_439 - sizeof( * V_219 ) ;
if ( V_149 < 0 || V_14 -> V_401 + V_149 > sizeof( V_14 -> V_400 ) ) {
F_74 ( V_3 , V_357 -> V_9 , V_444 ,
F_222 ( V_14 , V_126 ,
V_445 , V_82 ) , V_126 ) ;
goto V_438;
}
memcpy ( V_14 -> V_400 + V_14 -> V_401 , V_219 -> V_150 , V_149 ) ;
V_14 -> V_401 += V_149 ;
if ( V_82 & V_446 ) {
F_74 ( V_3 , V_357 -> V_9 , V_444 ,
F_222 ( V_14 , V_126 ,
V_404 , V_82 ) , V_126 ) ;
goto V_438;
}
V_149 = F_218 ( V_14 , V_126 ) ;
if ( V_149 < 0 ) {
F_72 ( V_3 , V_14 , V_241 ) ;
goto V_438;
}
F_74 ( V_3 , V_357 -> V_9 , V_444 , V_149 , V_126 ) ;
V_14 -> V_386 ++ ;
V_14 -> V_401 = 0 ;
if ( ! F_67 ( V_427 , & V_14 -> V_71 ) )
goto V_438;
if ( F_67 ( V_447 , & V_14 -> V_71 ) ) {
F_231 ( V_14 ) ;
if ( V_14 -> V_113 == V_115 ||
V_14 -> V_113 == V_119 )
V_15 = F_212 ( V_14 ) ;
if ( V_15 < 0 )
F_72 ( V_14 -> V_3 , V_14 , - V_15 ) ;
else
F_109 ( V_14 ) ;
goto V_438;
}
if ( ! F_224 ( V_249 , & V_14 -> V_71 ) ) {
T_2 V_242 [ 64 ] ;
F_74 ( V_3 , F_78 ( V_3 ) , V_250 ,
F_115 ( V_14 , V_242 ) , V_242 ) ;
V_14 -> V_251 ++ ;
}
if ( F_67 ( V_448 , & V_14 -> V_71 ) &&
F_67 ( V_416 , & V_14 -> V_71 ) ) {
F_104 ( V_416 , & V_14 -> V_71 ) ;
F_56 ( V_427 , & V_14 -> V_71 ) ;
F_74 ( V_3 , V_357 -> V_9 , V_444 ,
F_222 ( V_14 , V_126 ,
V_404 , V_82 ) , V_126 ) ;
}
V_438:
F_48 ( V_14 ) ;
return V_15 ;
}
static inline int F_233 ( struct V_2 * V_3 , struct V_356 * V_357 , T_2 * V_150 )
{
struct V_399 * V_126 = (struct V_399 * ) V_150 ;
T_1 V_7 , V_82 , V_127 ;
struct V_1 * V_14 ;
int V_149 = F_219 ( V_357 -> V_149 ) - sizeof( * V_126 ) ;
int V_15 = 0 ;
V_7 = F_61 ( V_126 -> V_7 ) ;
V_82 = F_61 ( V_126 -> V_82 ) ;
V_127 = F_61 ( V_126 -> V_127 ) ;
F_19 ( L_45 , V_7 , V_82 ,
V_127 , V_149 ) ;
V_14 = F_4 ( V_3 , V_7 ) ;
if ( ! V_14 )
return 0 ;
switch ( V_127 ) {
case V_404 :
F_225 ( V_14 , V_126 -> V_150 , V_149 ) ;
F_104 ( V_448 , & V_14 -> V_71 ) ;
break;
case V_415 :
F_56 ( V_448 , & V_14 -> V_71 ) ;
if ( F_67 ( V_416 , & V_14 -> V_71 ) ) {
char V_242 [ 64 ] ;
V_149 = F_221 ( V_14 , V_126 -> V_150 , V_149 ,
V_242 , & V_127 ) ;
if ( V_149 < 0 ) {
F_72 ( V_3 , V_14 , V_241 ) ;
goto V_18;
}
F_104 ( V_416 , & V_14 -> V_71 ) ;
F_56 ( V_427 , & V_14 -> V_71 ) ;
F_74 ( V_3 , V_357 -> V_9 , V_444 ,
F_222 ( V_14 , V_242 ,
V_404 , 0x0000 ) , V_242 ) ;
}
goto V_18;
case V_411 :
if ( V_14 -> V_386 <= V_449 ) {
char V_219 [ 64 ] ;
if ( V_149 > sizeof( V_219 ) - sizeof( struct V_383 ) ) {
F_72 ( V_3 , V_14 , V_241 ) ;
goto V_18;
}
V_127 = V_404 ;
V_149 = F_221 ( V_14 , V_126 -> V_150 , V_149 ,
V_219 , & V_127 ) ;
if ( V_149 < 0 ) {
F_72 ( V_3 , V_14 , V_241 ) ;
goto V_18;
}
F_74 ( V_3 , F_78 ( V_3 ) ,
V_250 , V_149 , V_219 ) ;
V_14 -> V_251 ++ ;
if ( V_127 != V_404 )
goto V_18;
break;
}
default:
F_25 ( V_14 , V_241 ) ;
F_71 ( V_14 , V_450 ) ;
F_72 ( V_3 , V_14 , V_241 ) ;
goto V_18;
}
if ( V_82 & V_446 )
goto V_18;
F_56 ( V_447 , & V_14 -> V_71 ) ;
if ( F_67 ( V_427 , & V_14 -> V_71 ) ) {
F_231 ( V_14 ) ;
if ( V_14 -> V_113 == V_115 ||
V_14 -> V_113 == V_119 )
V_15 = F_212 ( V_14 ) ;
if ( V_15 < 0 )
F_72 ( V_14 -> V_3 , V_14 , - V_15 ) ;
else
F_109 ( V_14 ) ;
}
V_18:
F_48 ( V_14 ) ;
return V_15 ;
}
static inline int F_234 ( struct V_2 * V_3 , struct V_356 * V_357 , T_2 * V_150 )
{
struct V_237 * V_219 = (struct V_237 * ) V_150 ;
struct V_451 V_126 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
struct V_26 * V_13 ;
V_7 = F_61 ( V_219 -> V_7 ) ;
V_6 = F_61 ( V_219 -> V_6 ) ;
F_19 ( L_46 , V_7 , V_6 ) ;
F_5 ( & V_3 -> V_8 ) ;
V_14 = F_3 ( V_3 , V_6 ) ;
if ( ! V_14 ) {
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
F_6 ( V_14 ) ;
V_13 = V_14 -> V_13 ;
V_126 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_126 . V_7 = F_14 ( V_14 -> V_6 ) ;
F_74 ( V_3 , V_357 -> V_9 , V_452 , sizeof( V_126 ) , & V_126 ) ;
F_22 ( V_13 ) ;
V_13 -> V_453 = V_454 ;
F_23 ( V_13 ) ;
F_62 ( V_14 ) ;
F_64 ( V_14 , V_241 ) ;
F_48 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_49 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_235 ( struct V_2 * V_3 , struct V_356 * V_357 , T_2 * V_150 )
{
struct V_451 * V_126 = (struct V_451 * ) V_150 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
V_7 = F_61 ( V_126 -> V_7 ) ;
V_6 = F_61 ( V_126 -> V_6 ) ;
F_19 ( L_47 , V_6 , V_7 ) ;
F_5 ( & V_3 -> V_8 ) ;
V_14 = F_3 ( V_3 , V_7 ) ;
if ( ! V_14 ) {
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
F_6 ( V_14 ) ;
F_62 ( V_14 ) ;
F_64 ( V_14 , 0 ) ;
F_48 ( V_14 ) ;
V_14 -> V_24 -> V_63 ( V_14 ) ;
F_49 ( V_14 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_236 ( struct V_2 * V_3 , struct V_356 * V_357 , T_2 * V_150 )
{
struct V_225 * V_219 = (struct V_225 * ) V_150 ;
T_1 type ;
type = F_61 ( V_219 -> type ) ;
F_19 ( L_48 , type ) ;
if ( type == V_226 ) {
T_2 V_242 [ 8 ] ;
T_8 V_231 = V_233 ;
struct V_455 * V_126 = (struct V_455 * ) V_242 ;
V_126 -> type = F_73 ( V_226 ) ;
V_126 -> V_127 = F_73 ( V_456 ) ;
if ( ! V_234 )
V_231 |= V_235 | V_236
| V_394 ;
if ( V_379 )
V_231 |= V_381
| V_380 ;
F_94 ( V_231 , V_126 -> V_150 ) ;
F_74 ( V_3 , V_357 -> V_9 ,
V_457 , sizeof( V_242 ) , V_242 ) ;
} else if ( type == V_458 ) {
T_2 V_242 [ 12 ] ;
struct V_455 * V_126 = (struct V_455 * ) V_242 ;
if ( V_379 )
V_459 [ 0 ] |= V_460 ;
else
V_459 [ 0 ] &= ~ V_460 ;
V_126 -> type = F_73 ( V_458 ) ;
V_126 -> V_127 = F_73 ( V_456 ) ;
memcpy ( V_126 -> V_150 , V_459 , sizeof( V_459 ) ) ;
F_74 ( V_3 , V_357 -> V_9 ,
V_457 , sizeof( V_242 ) , V_242 ) ;
} else {
struct V_455 V_126 ;
V_126 . type = F_14 ( type ) ;
V_126 . V_127 = F_73 ( V_461 ) ;
F_74 ( V_3 , V_357 -> V_9 ,
V_457 , sizeof( V_126 ) , & V_126 ) ;
}
return 0 ;
}
static inline int F_237 ( struct V_2 * V_3 , struct V_356 * V_357 , T_2 * V_150 )
{
struct V_455 * V_126 = (struct V_455 * ) V_150 ;
T_1 type , V_127 ;
type = F_61 ( V_126 -> type ) ;
V_127 = F_61 ( V_126 -> V_127 ) ;
F_19 ( L_49 , type , V_127 ) ;
if ( V_357 -> V_9 != V_3 -> V_227 ||
V_3 -> V_222 & V_224 )
return 0 ;
F_227 ( & V_3 -> V_228 ) ;
if ( V_127 != V_456 ) {
V_3 -> V_222 |= V_224 ;
V_3 -> V_227 = 0 ;
F_113 ( V_3 ) ;
return 0 ;
}
switch ( type ) {
case V_226 :
V_3 -> V_231 = F_88 ( V_126 -> V_150 ) ;
if ( V_3 -> V_231 & V_462 ) {
struct V_225 V_219 ;
V_219 . type = F_73 ( V_458 ) ;
V_3 -> V_227 = F_78 ( V_3 ) ;
F_74 ( V_3 , V_3 -> V_227 ,
V_230 , sizeof( V_219 ) , & V_219 ) ;
} else {
V_3 -> V_222 |= V_224 ;
V_3 -> V_227 = 0 ;
F_113 ( V_3 ) ;
}
break;
case V_458 :
V_3 -> V_463 = V_126 -> V_150 [ 0 ] ;
V_3 -> V_222 |= V_224 ;
V_3 -> V_227 = 0 ;
F_113 ( V_3 ) ;
break;
}
return 0 ;
}
static inline int F_238 ( struct V_2 * V_3 ,
struct V_356 * V_357 , T_1 V_439 ,
void * V_150 )
{
struct V_464 * V_219 = V_150 ;
struct V_465 V_126 ;
T_1 V_10 , V_7 ;
if ( V_439 != sizeof( * V_219 ) )
return - V_466 ;
if ( ! V_379 )
return - V_20 ;
V_10 = F_219 ( V_219 -> V_10 ) ;
V_7 = F_219 ( V_219 -> V_7 ) ;
F_19 ( L_50 , V_10 , V_7 , V_219 -> V_467 ) ;
V_126 . V_6 = 0 ;
V_126 . V_7 = F_14 ( V_7 ) ;
V_126 . V_127 = F_73 ( V_436 ) ;
V_126 . V_132 = F_73 ( V_133 ) ;
F_74 ( V_3 , V_357 -> V_9 , V_468 ,
sizeof( V_126 ) , & V_126 ) ;
return 0 ;
}
static inline int F_239 ( struct V_2 * V_3 ,
struct V_356 * V_357 , void * V_150 )
{
F_19 ( L_12 , V_3 ) ;
return F_230 ( V_3 , V_357 , V_150 ) ;
}
static void F_240 ( struct V_2 * V_3 , T_2 V_9 ,
T_1 V_469 , T_1 V_127 )
{
struct V_470 V_126 ;
F_19 ( L_51 , V_469 , V_127 ) ;
V_126 . V_469 = F_14 ( V_469 ) ;
V_126 . V_127 = F_14 ( V_127 ) ;
F_74 ( V_3 , V_9 , V_471 , sizeof( V_126 ) , & V_126 ) ;
}
static void F_241 ( struct V_2 * V_3 ,
struct V_1 * V_14 ,
T_1 V_469 , T_1 V_127 )
{
struct V_472 V_473 ;
T_2 V_9 ;
F_19 ( L_51 , V_469 , V_127 ) ;
V_9 = F_78 ( V_3 ) ;
if ( V_14 )
V_14 -> V_9 = V_9 ;
V_473 . V_469 = F_14 ( V_469 ) ;
V_473 . V_127 = F_14 ( V_127 ) ;
F_74 ( V_3 , V_9 , V_474 , sizeof( V_473 ) , & V_473 ) ;
}
static void F_242 ( struct V_2 * V_3 , T_2 V_9 ,
T_1 V_469 )
{
struct V_475 V_126 ;
F_19 ( L_52 , V_469 ) ;
V_126 . V_469 = F_14 ( V_469 ) ;
F_74 ( V_3 , V_9 , V_476 , sizeof( V_126 ) , & V_126 ) ;
}
static inline int F_243 ( struct V_2 * V_3 ,
struct V_356 * V_357 ,
T_1 V_439 , void * V_150 )
{
struct V_477 * V_219 = V_150 ;
T_1 V_469 = 0 ;
T_1 V_127 = V_478 ;
if ( V_439 != sizeof( * V_219 ) )
return - V_466 ;
V_469 = F_219 ( V_219 -> V_469 ) ;
F_19 ( L_53 , V_469 , V_219 -> V_479 ) ;
if ( ! V_379 )
return - V_20 ;
F_240 ( V_3 , V_357 -> V_9 , V_469 , V_127 ) ;
return 0 ;
}
static inline int F_244 ( struct V_2 * V_3 ,
struct V_356 * V_357 ,
T_1 V_439 , void * V_150 )
{
struct V_470 * V_126 = V_150 ;
T_1 V_469 , V_127 ;
if ( V_439 != sizeof( * V_126 ) )
return - V_466 ;
V_469 = F_219 ( V_126 -> V_469 ) ;
V_127 = F_219 ( V_126 -> V_127 ) ;
F_19 ( L_51 , V_469 , V_127 ) ;
F_241 ( V_3 , NULL , V_469 , V_480 ) ;
return 0 ;
}
static inline int F_245 ( struct V_2 * V_3 ,
struct V_356 * V_357 ,
T_1 V_439 , void * V_150 )
{
struct V_472 * V_473 = V_150 ;
T_1 V_469 , V_127 ;
if ( V_439 != sizeof( * V_473 ) )
return - V_466 ;
V_469 = F_219 ( V_473 -> V_469 ) ;
V_127 = F_219 ( V_473 -> V_127 ) ;
F_19 ( L_51 , V_469 , V_127 ) ;
F_242 ( V_3 , V_357 -> V_9 , V_469 ) ;
return 0 ;
}
static inline int F_246 ( struct V_2 * V_3 ,
struct V_356 * V_357 ,
T_1 V_439 , void * V_150 )
{
struct V_475 * V_126 = V_150 ;
T_1 V_469 ;
if ( V_439 != sizeof( * V_126 ) )
return - V_466 ;
V_469 = F_219 ( V_126 -> V_469 ) ;
F_19 ( L_52 , V_469 ) ;
return 0 ;
}
static inline int F_247 ( T_1 V_481 , T_1 V_482 , T_1 V_483 ,
T_1 V_484 )
{
T_1 V_485 ;
if ( V_481 > V_482 || V_481 < 6 || V_482 > 3200 )
return - V_20 ;
if ( V_484 < 10 || V_484 > 3200 )
return - V_20 ;
if ( V_482 >= V_484 * 8 )
return - V_20 ;
V_485 = ( V_484 * 8 / V_482 ) - 1 ;
if ( V_483 > 499 || V_483 > V_485 )
return - V_20 ;
return 0 ;
}
static inline int F_248 ( struct V_2 * V_3 ,
struct V_356 * V_357 , T_2 * V_150 )
{
struct V_159 * V_87 = V_3 -> V_87 ;
struct F_248 * V_219 ;
struct V_486 V_126 ;
T_1 V_481 , V_482 , V_483 , V_484 , V_439 ;
int V_15 ;
if ( ! ( V_87 -> V_487 & V_488 ) )
return - V_20 ;
V_439 = F_61 ( V_357 -> V_149 ) ;
if ( V_439 != sizeof( struct F_248 ) )
return - V_466 ;
V_219 = (struct F_248 * ) V_150 ;
V_481 = F_61 ( V_219 -> V_481 ) ;
V_482 = F_61 ( V_219 -> V_482 ) ;
V_483 = F_61 ( V_219 -> V_483 ) ;
V_484 = F_61 ( V_219 -> V_484 ) ;
F_19 ( L_54 ,
V_481 , V_482 , V_483 , V_484 ) ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_15 = F_247 ( V_481 , V_482 , V_483 , V_484 ) ;
if ( V_15 )
V_126 . V_127 = F_73 ( V_489 ) ;
else
V_126 . V_127 = F_73 ( V_490 ) ;
F_74 ( V_3 , V_357 -> V_9 , V_491 ,
sizeof( V_126 ) , & V_126 ) ;
if ( ! V_15 )
F_249 ( V_87 , V_481 , V_482 , V_483 , V_484 ) ;
return 0 ;
}
static inline int F_250 ( struct V_2 * V_3 ,
struct V_356 * V_357 , T_1 V_439 , T_2 * V_150 )
{
int V_15 = 0 ;
switch ( V_357 -> V_148 ) {
case V_443 :
F_226 ( V_3 , V_357 , V_150 ) ;
break;
case V_220 :
V_15 = F_228 ( V_3 , V_357 , V_150 ) ;
break;
case V_134 :
V_15 = F_230 ( V_3 , V_357 , V_150 ) ;
break;
case V_250 :
V_15 = F_232 ( V_3 , V_357 , V_439 , V_150 ) ;
break;
case V_444 :
V_15 = F_233 ( V_3 , V_357 , V_150 ) ;
break;
case V_238 :
V_15 = F_234 ( V_3 , V_357 , V_150 ) ;
break;
case V_452 :
V_15 = F_235 ( V_3 , V_357 , V_150 ) ;
break;
case V_492 :
F_74 ( V_3 , V_357 -> V_9 , V_493 , V_439 , V_150 ) ;
break;
case V_493 :
break;
case V_230 :
V_15 = F_236 ( V_3 , V_357 , V_150 ) ;
break;
case V_457 :
V_15 = F_237 ( V_3 , V_357 , V_150 ) ;
break;
case V_494 :
V_15 = F_238 ( V_3 , V_357 , V_439 , V_150 ) ;
break;
case V_468 :
V_15 = F_239 ( V_3 , V_357 , V_150 ) ;
break;
case V_495 :
V_15 = F_243 ( V_3 , V_357 , V_439 , V_150 ) ;
break;
case V_471 :
V_15 = F_244 ( V_3 , V_357 , V_439 , V_150 ) ;
break;
case V_474 :
V_15 = F_245 ( V_3 , V_357 , V_439 , V_150 ) ;
break;
case V_476 :
V_15 = F_246 ( V_3 , V_357 , V_439 , V_150 ) ;
break;
default:
F_251 ( L_55 , V_357 -> V_148 ) ;
V_15 = - V_20 ;
break;
}
return V_15 ;
}
static inline int F_252 ( struct V_2 * V_3 ,
struct V_356 * V_357 , T_2 * V_150 )
{
switch ( V_357 -> V_148 ) {
case V_443 :
return 0 ;
case V_496 :
return F_248 ( V_3 , V_357 , V_150 ) ;
case V_491 :
return 0 ;
default:
F_251 ( L_56 , V_357 -> V_148 ) ;
return - V_20 ;
}
}
static inline void F_253 ( struct V_2 * V_3 ,
struct V_32 * V_36 )
{
T_2 * V_150 = V_36 -> V_150 ;
int V_149 = V_36 -> V_149 ;
struct V_356 V_357 ;
int V_15 ;
F_205 ( V_3 , V_36 ) ;
while ( V_149 >= V_358 ) {
T_1 V_439 ;
memcpy ( & V_357 , V_150 , V_358 ) ;
V_150 += V_358 ;
V_149 -= V_358 ;
V_439 = F_219 ( V_357 . V_149 ) ;
F_19 ( L_57 , V_357 . V_148 , V_439 , V_357 . V_9 ) ;
if ( V_439 > V_149 || ! V_357 . V_9 ) {
F_19 ( L_58 ) ;
break;
}
if ( V_3 -> V_87 -> type == V_88 )
V_15 = F_252 ( V_3 , & V_357 , V_150 ) ;
else
V_15 = F_250 ( V_3 , & V_357 , V_439 , V_150 ) ;
if ( V_15 ) {
struct V_430 V_431 ;
F_251 ( L_59 , V_15 ) ;
V_431 . V_55 = F_73 ( V_432 ) ;
F_74 ( V_3 , V_357 . V_9 , V_443 , sizeof( V_431 ) , & V_431 ) ;
}
V_150 += V_439 ;
V_149 -= V_439 ;
}
F_128 ( V_36 ) ;
}
static int F_254 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
T_1 V_497 , V_498 ;
int V_499 ;
if ( F_67 ( V_196 , & V_14 -> V_82 ) )
V_499 = V_201 ;
else
V_499 = V_202 ;
if ( V_14 -> V_72 == V_73 ) {
F_255 ( V_36 , V_36 -> V_149 - V_206 ) ;
V_498 = F_90 ( V_36 -> V_150 + V_36 -> V_149 ) ;
V_497 = F_101 ( 0 , V_36 -> V_150 - V_499 , V_36 -> V_149 + V_499 ) ;
if ( V_497 != V_498 )
return - V_500 ;
}
return 0 ;
}
static void F_256 ( struct V_1 * V_14 )
{
struct V_162 V_37 ;
F_19 ( L_3 , V_14 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_170 = 1 ;
V_37 . V_166 = 1 ;
V_37 . V_163 = V_14 -> V_216 ;
F_56 ( V_208 , & V_14 -> V_209 ) ;
if ( F_67 ( V_215 , & V_14 -> V_209 ) ) {
V_37 . V_174 = V_212 ;
F_102 ( V_14 , & V_37 ) ;
}
if ( F_103 ( V_302 , & V_14 -> V_209 ) &&
V_14 -> V_291 > 0 )
F_26 ( V_14 ) ;
F_166 ( V_14 ) ;
if ( ! F_67 ( V_215 , & V_14 -> V_209 ) &&
F_67 ( V_208 , & V_14 -> V_209 ) ) {
V_37 . V_174 = V_210 ;
F_102 ( V_14 , & V_37 ) ;
}
}
static void F_257 ( struct V_32 * V_36 ,
struct V_32 * V_501 , struct V_32 * * V_502 )
{
if ( ! F_258 ( V_36 ) )
F_182 ( V_36 ) -> V_317 = V_501 ;
V_501 -> V_322 = NULL ;
( * V_502 ) -> V_322 = V_501 ;
* V_502 = V_501 ;
V_36 -> V_149 += V_501 -> V_149 ;
V_36 -> V_321 += V_501 -> V_149 ;
V_36 -> V_503 += V_501 -> V_503 ;
}
static int F_259 ( struct V_1 * V_14 , struct V_32 * V_36 ,
struct V_162 * V_37 )
{
int V_15 = - V_20 ;
switch ( V_37 -> V_177 ) {
case V_331 :
if ( V_14 -> V_376 )
break;
V_15 = V_14 -> V_24 -> V_354 ( V_14 , V_36 ) ;
break;
case V_332 :
if ( V_14 -> V_376 )
break;
V_14 -> V_327 = F_90 ( V_36 -> V_150 ) ;
F_89 ( V_36 , V_325 ) ;
if ( V_14 -> V_327 > V_14 -> V_97 ) {
V_15 = - V_335 ;
break;
}
if ( V_36 -> V_149 >= V_14 -> V_327 )
break;
V_14 -> V_376 = V_36 ;
V_14 -> V_377 = V_36 ;
V_36 = NULL ;
V_15 = 0 ;
break;
case V_334 :
if ( ! V_14 -> V_376 )
break;
F_257 ( V_14 -> V_376 , V_36 ,
& V_14 -> V_377 ) ;
V_36 = NULL ;
if ( V_14 -> V_376 -> V_149 >= V_14 -> V_327 )
break;
V_15 = 0 ;
break;
case V_333 :
if ( ! V_14 -> V_376 )
break;
F_257 ( V_14 -> V_376 , V_36 ,
& V_14 -> V_377 ) ;
V_36 = NULL ;
if ( V_14 -> V_376 -> V_149 != V_14 -> V_327 )
break;
V_15 = V_14 -> V_24 -> V_354 ( V_14 , V_14 -> V_376 ) ;
if ( ! V_15 ) {
V_14 -> V_376 = NULL ;
V_14 -> V_377 = NULL ;
V_14 -> V_327 = 0 ;
}
break;
}
if ( V_15 ) {
F_128 ( V_36 ) ;
F_128 ( V_14 -> V_376 ) ;
V_14 -> V_376 = NULL ;
V_14 -> V_377 = NULL ;
V_14 -> V_327 = 0 ;
}
return V_15 ;
}
void F_260 ( struct V_1 * V_14 , int V_504 )
{
T_2 V_342 ;
if ( V_14 -> V_113 != V_115 )
return;
V_342 = V_504 ? V_343 : V_345 ;
F_159 ( V_14 , NULL , NULL , V_342 ) ;
}
static int F_261 ( struct V_1 * V_14 )
{
int V_15 = 0 ;
F_19 ( L_3 , V_14 ) ;
while ( ! F_67 ( V_215 , & V_14 -> V_209 ) ) {
struct V_32 * V_36 ;
F_19 ( L_60 ,
V_14 -> V_216 , F_170 ( & V_14 -> V_116 ) ) ;
V_36 = F_32 ( & V_14 -> V_116 , V_14 -> V_216 ) ;
if ( ! V_36 )
break;
F_198 ( V_36 , & V_14 -> V_116 ) ;
V_14 -> V_216 = F_165 ( V_14 , V_14 -> V_216 ) ;
V_15 = F_259 ( V_14 , V_36 , & F_34 ( V_36 ) -> V_37 ) ;
if ( V_15 )
break;
}
if ( F_163 ( & V_14 -> V_116 ) ) {
V_14 -> V_309 = V_310 ;
F_177 ( V_14 ) ;
}
return V_15 ;
}
static void F_262 ( struct V_1 * V_14 ,
struct V_162 * V_37 )
{
struct V_32 * V_36 ;
F_19 ( L_9 , V_14 , V_37 ) ;
if ( V_37 -> V_163 == V_14 -> V_297 ) {
F_19 ( L_61 , V_37 -> V_163 ) ;
F_72 ( V_14 -> V_3 , V_14 , V_241 ) ;
return;
}
V_36 = F_32 ( & V_14 -> V_120 , V_37 -> V_163 ) ;
if ( V_36 == NULL ) {
F_19 ( L_62 ,
V_37 -> V_163 ) ;
return;
}
if ( V_14 -> V_74 != 0 && F_34 ( V_36 ) -> V_37 . V_296 >= V_14 -> V_74 ) {
F_19 ( L_21 , V_14 -> V_74 ) ;
F_72 ( V_14 -> V_3 , V_14 , V_241 ) ;
return;
}
F_104 ( V_302 , & V_14 -> V_209 ) ;
if ( V_37 -> V_171 ) {
F_203 ( V_14 , V_37 ) ;
F_56 ( V_208 , & V_14 -> V_209 ) ;
F_174 ( V_14 , V_37 ) ;
F_166 ( V_14 ) ;
if ( V_14 -> V_305 == V_348 ) {
F_56 ( V_505 , & V_14 -> V_209 ) ;
V_14 -> V_506 = V_37 -> V_163 ;
}
} else {
F_204 ( V_14 , V_37 ) ;
if ( V_37 -> V_166 ) {
if ( V_14 -> V_506 != V_37 -> V_163 ||
! F_103 ( V_505 ,
& V_14 -> V_209 ) )
F_174 ( V_14 , V_37 ) ;
} else {
F_174 ( V_14 , V_37 ) ;
if ( V_14 -> V_305 == V_348 ) {
F_56 ( V_505 , & V_14 -> V_209 ) ;
V_14 -> V_506 = V_37 -> V_163 ;
}
}
}
}
static void F_263 ( struct V_1 * V_14 ,
struct V_162 * V_37 )
{
struct V_32 * V_36 ;
F_19 ( L_9 , V_14 , V_37 ) ;
if ( V_37 -> V_163 == V_14 -> V_297 ) {
F_19 ( L_61 , V_37 -> V_163 ) ;
F_72 ( V_14 -> V_3 , V_14 , V_241 ) ;
return;
}
V_36 = F_32 ( & V_14 -> V_120 , V_37 -> V_163 ) ;
if ( V_14 -> V_74 && V_36 &&
F_34 ( V_36 ) -> V_37 . V_296 >= V_14 -> V_74 ) {
F_19 ( L_21 , V_14 -> V_74 ) ;
F_72 ( V_14 -> V_3 , V_14 , V_241 ) ;
return;
}
F_104 ( V_302 , & V_14 -> V_209 ) ;
F_203 ( V_14 , V_37 ) ;
if ( V_37 -> V_166 ) {
if ( ! F_103 ( V_507 , & V_14 -> V_209 ) )
F_175 ( V_14 , V_37 ) ;
} else {
F_175 ( V_14 , V_37 ) ;
F_166 ( V_14 ) ;
if ( V_14 -> V_305 == V_348 )
F_56 ( V_507 , & V_14 -> V_209 ) ;
}
}
static T_2 F_264 ( struct V_1 * V_14 , T_1 V_38 )
{
F_19 ( L_63 , V_14 , V_38 ) ;
F_19 ( L_64 , V_14 -> V_214 ,
V_14 -> V_337 ) ;
if ( V_14 -> V_309 == V_344 ) {
if ( F_178 ( V_14 , V_38 , V_14 -> V_214 ) >=
V_14 -> V_76 ) {
if ( V_14 -> V_76 <= ( ( V_14 -> V_78 + 1 ) >> 1 ) ) {
F_19 ( L_65 ) ;
return V_508 ;
} else {
F_19 ( L_66 ) ;
return V_509 ;
}
}
if ( V_14 -> V_117 . V_34 == V_38 ) {
F_19 ( L_67 ) ;
return V_510 ;
}
if ( F_32 ( & V_14 -> V_116 , V_38 ) ) {
F_19 ( L_68 ) ;
return V_511 ;
}
if ( F_40 ( & V_14 -> V_117 , V_38 ) ) {
F_19 ( L_69 ) ;
return V_512 ;
}
}
if ( V_14 -> V_337 == V_38 ) {
if ( F_178 ( V_14 , V_38 , V_14 -> V_214 ) >=
V_14 -> V_76 ) {
F_19 ( L_70 ) ;
return V_509 ;
} else {
F_19 ( L_71 ) ;
return V_513 ;
}
}
if ( F_178 ( V_14 , V_38 , V_14 -> V_214 ) <
F_178 ( V_14 , V_14 -> V_337 ,
V_14 -> V_214 ) ) {
F_19 ( L_72 ) ;
return V_514 ;
}
if ( F_178 ( V_14 , V_38 , V_14 -> V_214 ) >= V_14 -> V_76 ) {
if ( V_14 -> V_76 <= ( ( V_14 -> V_78 + 1 ) >> 1 ) ) {
F_19 ( L_73 ) ;
return V_508 ;
} else {
F_19 ( L_70 ) ;
return V_509 ;
}
} else {
F_19 ( L_74 ) ;
return V_515 ;
}
}
static int F_265 ( struct V_1 * V_14 ,
struct V_162 * V_37 ,
struct V_32 * V_36 , T_2 V_342 )
{
int V_15 = 0 ;
bool V_516 = 0 ;
F_19 ( L_75 , V_14 , V_37 , V_36 ,
V_342 ) ;
switch ( V_342 ) {
case V_517 :
switch ( F_264 ( V_14 , V_37 -> V_38 ) ) {
case V_513 :
F_203 ( V_14 , V_37 ) ;
if ( F_67 ( V_215 , & V_14 -> V_209 ) ) {
F_19 ( L_76 ,
V_37 -> V_38 ) ;
break;
}
V_14 -> V_337 = F_165 ( V_14 ,
V_37 -> V_38 ) ;
V_14 -> V_216 = V_14 -> V_337 ;
V_516 = 1 ;
V_15 = F_259 ( V_14 , V_36 , V_37 ) ;
if ( V_15 )
break;
if ( V_37 -> V_166 ) {
if ( ! F_103 ( V_507 ,
& V_14 -> V_209 ) ) {
V_37 -> V_166 = 0 ;
F_175 ( V_14 , V_37 ) ;
F_166 ( V_14 ) ;
}
}
if ( ! F_67 ( V_215 , & V_14 -> V_209 ) )
F_177 ( V_14 ) ;
break;
case V_515 :
F_203 ( V_14 , V_37 ) ;
if ( F_67 ( V_215 , & V_14 -> V_209 ) ) {
F_19 ( L_77 ,
V_37 -> V_38 ) ;
break;
}
F_266 ( & V_14 -> V_116 , V_36 ) ;
V_516 = 1 ;
F_19 ( L_78 , V_36 ,
F_170 ( & V_14 -> V_116 ) ) ;
F_104 ( V_505 , & V_14 -> V_209 ) ;
F_43 ( & V_14 -> V_117 ) ;
F_194 ( V_14 , V_37 -> V_38 ) ;
V_14 -> V_309 = V_344 ;
break;
case V_514 :
F_203 ( V_14 , V_37 ) ;
break;
case V_508 :
break;
case V_509 :
default:
F_72 ( V_14 -> V_3 , V_14 ,
V_241 ) ;
break;
}
break;
case V_518 :
F_203 ( V_14 , V_37 ) ;
if ( V_37 -> V_166 ) {
F_104 ( V_302 , & V_14 -> V_209 ) ;
if ( ! F_103 ( V_507 ,
& V_14 -> V_209 ) ) {
V_37 -> V_166 = 0 ;
F_175 ( V_14 , V_37 ) ;
}
F_166 ( V_14 ) ;
} else if ( V_37 -> V_171 ) {
F_256 ( V_14 ) ;
} else {
if ( F_103 ( V_302 ,
& V_14 -> V_209 ) &&
V_14 -> V_291 )
F_26 ( V_14 ) ;
F_166 ( V_14 ) ;
}
break;
case V_519 :
F_56 ( V_302 , & V_14 -> V_209 ) ;
F_203 ( V_14 , V_37 ) ;
if ( V_37 && V_37 -> V_171 ) {
F_56 ( V_208 , & V_14 -> V_209 ) ;
F_106 ( V_14 , 0 ) ;
}
F_31 ( V_14 ) ;
F_43 ( & V_14 -> V_118 ) ;
break;
case V_520 :
F_263 ( V_14 , V_37 ) ;
break;
case V_521 :
F_262 ( V_14 , V_37 ) ;
break;
default:
break;
}
if ( V_36 && ! V_516 ) {
F_19 ( L_79 , V_36 ) ;
F_128 ( V_36 ) ;
}
return V_15 ;
}
static int F_267 ( struct V_1 * V_14 ,
struct V_162 * V_37 ,
struct V_32 * V_36 , T_2 V_342 )
{
int V_15 = 0 ;
T_1 V_38 = V_37 -> V_38 ;
bool V_516 = 0 ;
F_19 ( L_75 , V_14 , V_37 , V_36 ,
V_342 ) ;
switch ( V_342 ) {
case V_517 :
switch ( F_264 ( V_14 , V_38 ) ) {
case V_513 :
F_203 ( V_14 , V_37 ) ;
F_266 ( & V_14 -> V_116 , V_36 ) ;
V_516 = 1 ;
F_19 ( L_78 , V_36 ,
F_170 ( & V_14 -> V_116 ) ) ;
V_14 -> V_337 = F_165 ( V_14 , V_38 ) ;
break;
case V_510 :
F_42 ( & V_14 -> V_117 ) ;
F_203 ( V_14 , V_37 ) ;
F_266 ( & V_14 -> V_116 , V_36 ) ;
V_516 = 1 ;
F_19 ( L_78 , V_36 ,
F_170 ( & V_14 -> V_116 ) ) ;
V_15 = F_261 ( V_14 ) ;
if ( V_15 )
break;
break;
case V_515 :
F_266 ( & V_14 -> V_116 , V_36 ) ;
V_516 = 1 ;
F_19 ( L_78 , V_36 ,
F_170 ( & V_14 -> V_116 ) ) ;
F_203 ( V_14 , V_37 ) ;
F_194 ( V_14 , V_37 -> V_38 ) ;
break;
case V_512 :
F_266 ( & V_14 -> V_116 , V_36 ) ;
V_516 = 1 ;
F_19 ( L_78 , V_36 ,
F_170 ( & V_14 -> V_116 ) ) ;
F_203 ( V_14 , V_37 ) ;
F_196 ( V_14 , V_37 -> V_38 ) ;
break;
case V_511 :
F_203 ( V_14 , V_37 ) ;
break;
case V_514 :
break;
case V_508 :
break;
case V_509 :
default:
F_72 ( V_14 -> V_3 , V_14 ,
V_241 ) ;
break;
}
break;
case V_518 :
F_203 ( V_14 , V_37 ) ;
if ( V_37 -> V_166 ) {
F_104 ( V_302 , & V_14 -> V_209 ) ;
if ( ! F_103 ( V_507 ,
& V_14 -> V_209 ) ) {
V_37 -> V_166 = 0 ;
F_175 ( V_14 , V_37 ) ;
}
F_166 ( V_14 ) ;
} else if ( V_37 -> V_171 ) {
if ( F_103 ( V_302 ,
& V_14 -> V_209 ) &&
V_14 -> V_291 ) {
F_26 ( V_14 ) ;
}
F_56 ( V_208 , & V_14 -> V_209 ) ;
F_195 ( V_14 ) ;
} else {
if ( F_103 ( V_302 ,
& V_14 -> V_209 ) &&
V_14 -> V_291 )
F_26 ( V_14 ) ;
F_177 ( V_14 ) ;
}
break;
case V_519 :
F_56 ( V_302 , & V_14 -> V_209 ) ;
F_203 ( V_14 , V_37 ) ;
if ( V_37 -> V_171 ) {
F_195 ( V_14 ) ;
} else {
struct V_162 V_522 ;
memset ( & V_522 , 0 , sizeof( V_522 ) ) ;
V_522 . V_170 = 1 ;
V_522 . V_174 = V_210 ;
V_522 . V_163 = V_14 -> V_216 ;
F_102 ( V_14 , & V_522 ) ;
}
break;
case V_520 :
F_263 ( V_14 , V_37 ) ;
break;
case V_521 :
F_262 ( V_14 , V_37 ) ;
break;
}
if ( V_36 && ! V_516 ) {
F_19 ( L_79 , V_36 ) ;
F_128 ( V_36 ) ;
}
return V_15 ;
}
static bool F_268 ( struct V_1 * V_14 , T_1 V_163 )
{
T_1 V_523 ;
V_523 = F_178 ( V_14 , V_14 -> V_297 , V_14 -> V_341 ) ;
return F_178 ( V_14 , V_14 -> V_297 , V_163 ) <= V_523 ;
}
static int F_269 ( struct V_1 * V_14 , struct V_162 * V_37 ,
struct V_32 * V_36 , T_2 V_342 )
{
int V_15 = 0 ;
F_19 ( L_80 , V_14 ,
V_37 , V_36 , V_342 , V_14 -> V_309 ) ;
if ( F_268 ( V_14 , V_37 -> V_163 ) ) {
switch ( V_14 -> V_309 ) {
case V_310 :
V_15 = F_265 ( V_14 , V_37 , V_36 , V_342 ) ;
break;
case V_344 :
V_15 = F_267 ( V_14 , V_37 , V_36 ,
V_342 ) ;
break;
default:
break;
}
} else {
F_19 ( L_81 ,
V_37 -> V_163 , V_14 -> V_297 ,
V_14 -> V_341 ) ;
F_72 ( V_14 -> V_3 , V_14 , V_241 ) ;
}
return V_15 ;
}
static int F_270 ( struct V_1 * V_14 , struct V_162 * V_37 ,
struct V_32 * V_36 )
{
int V_15 = 0 ;
F_19 ( L_82 , V_14 , V_37 , V_36 ,
V_14 -> V_309 ) ;
if ( F_264 ( V_14 , V_37 -> V_38 ) ==
V_513 ) {
F_203 ( V_14 , V_37 ) ;
F_19 ( L_83 , V_14 -> V_216 ,
F_165 ( V_14 , V_14 -> V_216 ) ) ;
V_14 -> V_216 = F_165 ( V_14 , V_14 -> V_216 ) ;
F_259 ( V_14 , V_36 , V_37 ) ;
} else {
if ( V_14 -> V_376 ) {
F_128 ( V_14 -> V_376 ) ;
V_14 -> V_376 = NULL ;
}
V_14 -> V_377 = NULL ;
V_14 -> V_327 = 0 ;
if ( V_36 ) {
F_19 ( L_79 , V_36 ) ;
F_128 ( V_36 ) ;
}
}
V_14 -> V_214 = V_37 -> V_38 ;
V_14 -> V_337 = F_165 ( V_14 , V_37 -> V_38 ) ;
return V_15 ;
}
static int F_271 ( struct V_1 * V_14 , struct V_32 * V_36 )
{
struct V_162 * V_37 = & F_34 ( V_36 ) -> V_37 ;
T_1 V_149 ;
T_2 V_342 ;
F_87 ( V_14 , V_36 ) ;
V_149 = V_36 -> V_149 ;
if ( F_254 ( V_14 , V_36 ) )
goto V_524;
if ( ! V_37 -> V_170 && V_37 -> V_177 == V_332 )
V_149 -= V_325 ;
if ( V_14 -> V_72 == V_73 )
V_149 -= V_206 ;
if ( V_149 > V_14 -> V_428 ) {
F_72 ( V_14 -> V_3 , V_14 , V_241 ) ;
goto V_524;
}
if ( ! V_37 -> V_170 ) {
int V_15 ;
F_19 ( L_84 ,
V_37 -> V_177 , V_37 -> V_163 , V_37 -> V_166 ,
V_37 -> V_38 ) ;
if ( V_37 -> V_166 && V_14 -> V_305 != V_348 )
goto V_524;
if ( V_14 -> V_113 != V_119 ) {
V_342 = V_517 ;
V_15 = F_269 ( V_14 , V_37 , V_36 , V_342 ) ;
} else {
V_15 = F_270 ( V_14 , V_37 , V_36 ) ;
}
if ( V_15 )
F_72 ( V_14 -> V_3 , V_14 ,
V_241 ) ;
} else {
const T_2 V_525 [ 4 ] = {
V_518 , V_520 ,
V_519 , V_521
} ;
if ( V_14 -> V_113 == V_119 )
goto V_524;
F_19 ( L_85 ,
V_37 -> V_163 , V_37 -> V_166 , V_37 -> V_171 ,
V_37 -> V_174 ) ;
if ( V_149 != 0 ) {
F_251 ( L_86 , V_149 ) ;
F_72 ( V_14 -> V_3 , V_14 , V_241 ) ;
goto V_524;
}
if ( V_37 -> V_166 && ( V_37 -> V_171 ||
V_14 -> V_305 != V_348 ) )
goto V_524;
V_342 = V_525 [ V_37 -> V_174 ] ;
if ( F_269 ( V_14 , V_37 , V_36 , V_342 ) )
F_72 ( V_14 -> V_3 , V_14 , V_241 ) ;
}
return 0 ;
V_524:
F_128 ( V_36 ) ;
return 0 ;
}
static void F_272 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_4 ( V_3 , V_4 ) ;
if ( ! V_14 ) {
if ( V_4 == V_95 ) {
V_14 = F_273 ( V_3 , V_36 ) ;
if ( ! V_14 ) {
F_128 ( V_36 ) ;
return;
}
F_6 ( V_14 ) ;
} else {
F_19 ( L_87 , V_4 ) ;
F_128 ( V_36 ) ;
return;
}
}
F_19 ( L_88 , V_14 , V_36 -> V_149 ) ;
if ( V_14 -> V_23 != V_56 )
goto V_524;
switch ( V_14 -> V_113 ) {
case V_114 :
if ( V_14 -> V_97 < V_36 -> V_149 )
goto V_524;
if ( ! V_14 -> V_24 -> V_354 ( V_14 , V_36 ) )
goto V_18;
break;
case V_115 :
case V_119 :
F_271 ( V_14 , V_36 ) ;
goto V_18;
default:
F_19 ( L_89 , V_14 , V_14 -> V_113 ) ;
break;
}
V_524:
F_128 ( V_36 ) ;
V_18:
F_48 ( V_14 ) ;
}
static void F_274 ( struct V_2 * V_3 , T_3 V_10 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_137 ( 0 , V_10 , V_3 -> V_11 , V_3 -> V_252 ) ;
if ( ! V_14 )
goto V_524;
F_19 ( L_88 , V_14 , V_36 -> V_149 ) ;
if ( V_14 -> V_23 != V_283 && V_14 -> V_23 != V_56 )
goto V_524;
if ( V_14 -> V_97 < V_36 -> V_149 )
goto V_524;
if ( ! V_14 -> V_24 -> V_354 ( V_14 , V_36 ) )
return;
V_524:
F_128 ( V_36 ) ;
}
static void F_275 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_32 * V_36 )
{
struct V_1 * V_14 ;
V_14 = F_116 ( 0 , V_4 , V_3 -> V_11 , V_3 -> V_252 ) ;
if ( ! V_14 )
goto V_524;
F_19 ( L_88 , V_14 , V_36 -> V_149 ) ;
if ( V_14 -> V_23 != V_283 && V_14 -> V_23 != V_56 )
goto V_524;
if ( V_14 -> V_97 < V_36 -> V_149 )
goto V_524;
if ( ! V_14 -> V_24 -> V_354 ( V_14 , V_36 ) )
return;
V_524:
F_128 ( V_36 ) ;
}
static void F_276 ( struct V_2 * V_3 , struct V_32 * V_36 )
{
struct V_203 * V_204 = ( void * ) V_36 -> V_150 ;
T_1 V_4 , V_149 ;
T_3 V_10 ;
F_89 ( V_36 , V_200 ) ;
V_4 = F_61 ( V_204 -> V_4 ) ;
V_149 = F_61 ( V_204 -> V_149 ) ;
if ( V_149 != V_36 -> V_149 ) {
F_128 ( V_36 ) ;
return;
}
F_19 ( L_90 , V_149 , V_4 ) ;
switch ( V_4 ) {
case V_359 :
case V_98 :
F_253 ( V_3 , V_36 ) ;
break;
case V_93 :
V_10 = F_277 ( ( T_3 * ) V_36 -> V_150 ) ;
F_89 ( V_36 , V_323 ) ;
F_274 ( V_3 , V_10 , V_36 ) ;
break;
case V_91 :
F_275 ( V_3 , V_4 , V_36 ) ;
break;
case V_526 :
if ( F_278 ( V_3 , V_36 ) )
F_127 ( V_3 -> V_87 , V_527 ) ;
break;
default:
F_272 ( V_3 , V_4 , V_36 ) ;
break;
}
}
int F_279 ( struct V_279 * V_151 , T_4 * V_277 )
{
int V_528 = 0 , V_529 = 0 , V_530 = 0 ;
struct V_1 * V_5 ;
F_19 ( L_91 , V_151 -> V_531 , F_139 ( V_277 ) ) ;
F_117 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
if ( V_5 -> V_23 != V_121 )
continue;
if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , & V_151 -> V_277 ) ) {
V_529 |= V_532 ;
if ( F_67 ( V_533 , & V_5 -> V_82 ) )
V_529 |= V_488 ;
V_528 ++ ;
} else if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_258 ) ) {
V_530 |= V_532 ;
if ( F_67 ( V_533 , & V_5 -> V_82 ) )
V_530 |= V_488 ;
}
}
F_118 ( & V_16 ) ;
return V_528 ? V_529 : V_530 ;
}
int F_280 ( struct V_159 * V_87 , T_2 V_132 )
{
struct V_2 * V_3 ;
F_19 ( L_92 , V_87 , F_139 ( & V_87 -> V_252 ) , V_132 ) ;
if ( ! V_132 ) {
V_3 = F_133 ( V_87 , V_132 ) ;
if ( V_3 )
F_123 ( V_3 ) ;
} else
F_127 ( V_87 , F_281 ( V_132 ) ) ;
return 0 ;
}
int F_282 ( struct V_159 * V_87 )
{
struct V_2 * V_3 = V_87 -> V_268 ;
F_19 ( L_93 , V_87 ) ;
if ( ! V_3 )
return V_84 ;
return V_3 -> V_83 ;
}
int F_283 ( struct V_159 * V_87 , T_2 V_55 )
{
F_19 ( L_94 , V_87 , V_55 ) ;
F_127 ( V_87 , F_281 ( V_55 ) ) ;
return 0 ;
}
static inline void F_284 ( struct V_1 * V_14 , T_2 V_534 )
{
if ( V_14 -> V_85 != V_86 )
return;
if ( V_534 == 0x00 ) {
if ( V_14 -> V_60 == V_138 ) {
F_71 ( V_14 , V_535 ) ;
} else if ( V_14 -> V_60 == V_136 )
F_47 ( V_14 , V_58 ) ;
} else {
if ( V_14 -> V_60 == V_138 )
F_65 ( V_14 ) ;
}
}
int F_285 ( struct V_159 * V_87 , T_2 V_132 , T_2 V_534 )
{
struct V_2 * V_3 = V_87 -> V_268 ;
struct V_1 * V_14 ;
if ( ! V_3 )
return 0 ;
F_19 ( L_95 , V_3 , V_132 , V_534 ) ;
if ( V_87 -> type == V_88 ) {
if ( ! V_132 && V_534 )
F_286 ( V_3 , 0 ) ;
F_227 ( & V_3 -> V_272 ) ;
}
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
F_6 ( V_14 ) ;
F_19 ( L_96 , V_14 , V_14 -> V_7 ,
F_20 ( V_14 -> V_23 ) ) ;
if ( V_14 -> V_7 == V_91 ) {
if ( ! V_132 && V_534 ) {
V_14 -> V_60 = V_87 -> V_60 ;
F_109 ( V_14 ) ;
}
F_48 ( V_14 ) ;
continue;
}
if ( F_67 ( V_217 , & V_14 -> V_71 ) ) {
F_48 ( V_14 ) ;
continue;
}
if ( ! V_132 && ( V_14 -> V_23 == V_56 ||
V_14 -> V_23 == V_57 ) ) {
struct V_26 * V_13 = V_14 -> V_13 ;
F_104 ( V_536 , & F_11 ( V_13 ) -> V_82 ) ;
V_13 -> V_266 ( V_13 ) ;
F_284 ( V_14 , V_534 ) ;
F_48 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_59 ) {
if ( ! V_132 ) {
F_108 ( V_14 ) ;
} else {
F_71 ( V_14 , V_537 ) ;
}
} else if ( V_14 -> V_23 == V_124 ) {
struct V_26 * V_13 = V_14 -> V_13 ;
struct V_125 V_126 ;
T_5 V_538 , V_539 ;
F_22 ( V_13 ) ;
if ( ! V_132 ) {
if ( F_67 ( V_128 ,
& F_11 ( V_13 ) -> V_82 ) ) {
struct V_26 * V_243 = F_11 ( V_13 ) -> V_243 ;
V_538 = V_244 ;
V_539 = V_245 ;
if ( V_243 )
V_243 -> V_246 ( V_243 , 0 ) ;
} else {
F_18 ( V_14 , V_57 ) ;
V_538 = V_247 ;
V_539 = V_133 ;
}
} else {
F_18 ( V_14 , V_131 ) ;
F_71 ( V_14 , V_537 ) ;
V_538 = V_129 ;
V_539 = V_133 ;
}
F_23 ( V_13 ) ;
V_126 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_126 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_126 . V_127 = F_14 ( V_538 ) ;
V_126 . V_132 = F_14 ( V_539 ) ;
F_74 ( V_3 , V_14 -> V_9 , V_134 ,
sizeof( V_126 ) , & V_126 ) ;
if ( ! F_67 ( V_249 , & V_14 -> V_71 ) &&
V_538 == V_247 ) {
char V_242 [ 128 ] ;
F_56 ( V_249 , & V_14 -> V_71 ) ;
F_74 ( V_3 , F_78 ( V_3 ) ,
V_250 ,
F_115 ( V_14 , V_242 ) ,
V_242 ) ;
V_14 -> V_251 ++ ;
}
}
F_48 ( V_14 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
int F_287 ( struct V_159 * V_87 , struct V_32 * V_36 , T_1 V_82 )
{
struct V_2 * V_3 = V_87 -> V_268 ;
if ( ! V_3 )
V_3 = F_133 ( V_87 , 0 ) ;
if ( ! V_3 )
goto V_524;
F_19 ( L_97 , V_3 , V_36 -> V_149 , V_82 ) ;
if ( ! ( V_82 & V_540 ) ) {
struct V_203 * V_541 ;
int V_149 ;
if ( V_3 -> V_542 ) {
F_251 ( L_98 , V_36 -> V_149 ) ;
F_128 ( V_3 -> V_270 ) ;
V_3 -> V_270 = NULL ;
V_3 -> V_542 = 0 ;
F_125 ( V_3 , V_543 ) ;
}
if ( V_36 -> V_149 < V_200 ) {
F_251 ( L_99 , V_36 -> V_149 ) ;
F_125 ( V_3 , V_543 ) ;
goto V_524;
}
V_541 = (struct V_203 * ) V_36 -> V_150 ;
V_149 = F_61 ( V_541 -> V_149 ) + V_200 ;
if ( V_149 == V_36 -> V_149 ) {
F_276 ( V_3 , V_36 ) ;
return 0 ;
}
F_19 ( L_100 , V_149 , V_36 -> V_149 ) ;
if ( V_36 -> V_149 > V_149 ) {
F_251 ( L_101 ,
V_36 -> V_149 , V_149 ) ;
F_125 ( V_3 , V_543 ) ;
goto V_524;
}
V_3 -> V_270 = F_98 ( V_149 , V_64 ) ;
if ( ! V_3 -> V_270 )
goto V_524;
F_288 ( V_36 , F_100 ( V_3 -> V_270 , V_36 -> V_149 ) ,
V_36 -> V_149 ) ;
V_3 -> V_542 = V_149 - V_36 -> V_149 ;
} else {
F_19 ( L_102 , V_36 -> V_149 , V_3 -> V_542 ) ;
if ( ! V_3 -> V_542 ) {
F_251 ( L_103 , V_36 -> V_149 ) ;
F_125 ( V_3 , V_543 ) ;
goto V_524;
}
if ( V_36 -> V_149 > V_3 -> V_542 ) {
F_251 ( L_104 ,
V_36 -> V_149 , V_3 -> V_542 ) ;
F_128 ( V_3 -> V_270 ) ;
V_3 -> V_270 = NULL ;
V_3 -> V_542 = 0 ;
F_125 ( V_3 , V_543 ) ;
goto V_524;
}
F_288 ( V_36 , F_100 ( V_3 -> V_270 , V_36 -> V_149 ) ,
V_36 -> V_149 ) ;
V_3 -> V_542 -= V_36 -> V_149 ;
if ( ! V_3 -> V_542 ) {
F_276 ( V_3 , V_3 -> V_270 ) ;
V_3 -> V_270 = NULL ;
}
}
V_524:
F_128 ( V_36 ) ;
return 0 ;
}
static int F_289 ( struct V_544 * V_545 , void * V_19 )
{
struct V_1 * V_5 ;
F_117 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_26 * V_13 = V_5 -> V_13 ;
F_290 ( V_545 , L_105 ,
F_139 ( & F_11 ( V_13 ) -> V_11 ) ,
F_139 ( & F_11 ( V_13 ) -> V_252 ) ,
V_5 -> V_23 , F_61 ( V_5 -> V_10 ) ,
V_5 -> V_7 , V_5 -> V_6 , V_5 -> V_97 , V_5 -> V_89 ,
V_5 -> V_60 , V_5 -> V_113 ) ;
}
F_118 ( & V_16 ) ;
return 0 ;
}
static int F_291 ( struct V_546 * V_546 , struct V_547 * V_547 )
{
return F_292 ( V_547 , F_289 , V_546 -> V_548 ) ;
}
int T_10 F_293 ( void )
{
int V_15 ;
V_15 = F_294 () ;
if ( V_15 < 0 )
return V_15 ;
if ( V_549 ) {
V_550 = F_295 ( L_106 , 0444 ,
V_549 , NULL , & V_551 ) ;
if ( ! V_550 )
F_251 ( L_107 ) ;
}
return 0 ;
}
void F_296 ( void )
{
F_297 ( V_550 ) ;
F_298 () ;
}
