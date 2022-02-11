static const struct V_1 * F_1 ( int V_2 )
{
if ( ! V_3 [ V_2 ] )
F_2 ( L_1 , V_4 ,
V_5 , V_6 , V_2 ) ;
F_3 ( & V_7 ) ;
if ( ! V_3 [ V_2 ] )
return F_4 ( - V_8 ) ;
return V_3 [ V_2 ] ;
}
static void F_5 ( const struct V_1 * V_9 )
{
F_6 ( & V_7 ) ;
}
void F_7 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
V_11 -> V_14 = V_13 -> V_15 ;
V_11 -> V_16 . V_17 = F_8 ( V_13 -> V_18 ) ;
V_11 -> V_16 . V_19 = V_13 -> V_20 ;
V_11 -> V_16 . V_21 = V_13 -> V_22 ;
F_9 ( V_13 , V_11 -> V_16 . V_23 ) ;
#if F_10 ( V_24 )
if ( V_13 -> V_15 == V_25 ) {
* (struct V_26 * ) V_11 -> V_16 . V_27 = V_13 -> V_28 ;
* (struct V_26 * ) V_11 -> V_16 . V_29 = V_13 -> V_30 ;
} else
#endif
{
memset ( & V_11 -> V_16 . V_27 , 0 , sizeof( V_11 -> V_16 . V_27 ) ) ;
memset ( & V_11 -> V_16 . V_29 , 0 , sizeof( V_11 -> V_16 . V_29 ) ) ;
V_11 -> V_16 . V_27 [ 0 ] = V_13 -> V_31 ;
V_11 -> V_16 . V_29 [ 0 ] = V_13 -> V_32 ;
}
}
static T_1 F_11 ( struct V_12 * V_13 ,
const struct V_33 * V_34 ,
bool V_35 )
{
const struct V_1 * V_9 ;
T_1 V_36 = 0 ;
V_9 = V_3 [ V_34 -> V_37 ] ;
if ( V_9 && V_9 -> V_38 )
V_36 = V_9 -> V_38 ( V_13 , V_35 ) ;
return F_12 ( sizeof( struct V_39 ) )
+ F_12 ( 1 )
+ F_12 ( 1 )
+ F_12 ( 1 )
+ F_12 ( 4 )
+ F_12 ( sizeof( struct V_40 ) )
+ F_12 ( sizeof( struct V_10 ) )
+ F_12 ( V_41 * sizeof( V_42 ) )
+ F_12 ( V_43 )
+ F_12 ( sizeof( struct V_44 ) )
+ V_36
+ 64 ;
}
int F_13 ( struct V_12 * V_13 , struct V_45 * V_46 ,
struct V_10 * V_11 , int V_47 ,
struct V_48 * V_49 ,
bool V_35 )
{
const struct V_50 * V_51 = F_14 ( V_13 ) ;
if ( F_15 ( V_46 , V_52 , V_13 -> V_53 ) )
goto V_54;
if ( V_47 & ( 1 << ( V_55 - 1 ) ) )
if ( F_15 ( V_46 , V_55 , V_51 -> V_56 ) < 0 )
goto V_54;
#if F_10 ( V_24 )
if ( V_11 -> V_14 == V_25 ) {
if ( V_47 & ( 1 << ( V_57 - 1 ) ) )
if ( F_15 ( V_46 , V_57 ,
F_16 ( V_13 ) -> V_58 ) < 0 )
goto V_54;
if ( ( ( 1 << V_13 -> V_59 ) & ( V_60 | V_61 ) ) &&
F_15 ( V_46 , V_62 , F_17 ( V_13 ) ) )
goto V_54;
}
#endif
if ( V_35 && F_18 ( V_46 , V_63 , V_13 -> V_64 ) )
goto V_54;
V_11 -> V_65 = F_19 ( V_49 , F_20 ( V_13 ) ) ;
V_11 -> V_66 = F_21 ( V_13 ) ;
return 0 ;
V_54:
return 1 ;
}
int F_22 ( struct V_12 * V_13 , struct V_67 * V_68 ,
struct V_45 * V_46 , const struct V_33 * V_34 ,
struct V_48 * V_49 ,
V_42 V_69 , V_42 V_70 , T_2 V_71 ,
const struct V_72 * V_73 ,
bool V_35 )
{
const struct V_74 * V_75 ;
const struct V_1 * V_9 ;
int V_47 = V_34 -> V_76 ;
struct V_10 * V_11 ;
struct V_72 * V_77 ;
struct V_78 * V_79 ;
void * V_80 = NULL ;
V_9 = V_3 [ V_34 -> V_37 ] ;
F_23 ( ! V_9 ) ;
V_77 = F_24 ( V_46 , V_69 , V_70 , V_73 -> V_81 , sizeof( * V_11 ) ,
V_71 ) ;
if ( ! V_77 )
return - V_82 ;
V_11 = F_25 ( V_77 ) ;
F_23 ( ! F_26 ( V_13 ) ) ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_83 = V_13 -> V_59 ;
V_11 -> V_84 = 0 ;
V_11 -> V_85 = 0 ;
if ( F_13 ( V_13 , V_46 , V_11 , V_47 , V_49 , V_35 ) )
goto V_54;
if ( V_47 & ( 1 << ( V_86 - 1 ) ) ) {
struct V_40 V_87 = {
. V_88 = F_27 ( V_13 ) ,
. V_89 = V_13 -> V_90 ,
. V_91 = V_13 -> V_92 ,
. V_93 = F_28 ( V_13 ) ,
} ;
if ( F_29 ( V_46 , V_86 , sizeof( V_87 ) , & V_87 ) < 0 )
goto V_54;
}
if ( V_47 & ( 1 << ( V_94 - 1 ) ) )
if ( F_30 ( V_13 , V_46 , V_94 ) )
goto V_54;
if ( V_13 -> V_95 == V_96 ) {
if ( F_15 ( V_46 , V_97 , V_13 -> V_98 ) )
goto V_54;
}
if ( ! V_68 ) {
V_9 -> V_99 ( V_13 , V_11 , NULL ) ;
goto V_100;
}
if ( V_68 -> V_101 == V_102 ||
V_68 -> V_101 == V_103 ||
V_68 -> V_101 == V_104 ) {
V_11 -> V_84 = 1 ;
V_11 -> V_85 = V_68 -> V_105 ;
V_11 -> V_106 =
F_31 ( V_68 -> V_107 - V_108 ) ;
} else if ( V_68 -> V_101 == V_109 ) {
V_11 -> V_84 = 4 ;
V_11 -> V_85 = V_68 -> V_110 ;
V_11 -> V_106 =
F_31 ( V_68 -> V_107 - V_108 ) ;
} else if ( F_32 ( & V_13 -> V_111 ) ) {
V_11 -> V_84 = 2 ;
V_11 -> V_85 = V_68 -> V_110 ;
V_11 -> V_106 =
F_31 ( V_13 -> V_111 . V_112 - V_108 ) ;
} else {
V_11 -> V_84 = 0 ;
V_11 -> V_106 = 0 ;
}
if ( ( V_47 & ( 1 << ( V_113 - 1 ) ) ) && V_9 -> V_114 ) {
V_79 = F_33 ( V_46 , V_113 ,
V_9 -> V_114 ,
V_115 ) ;
if ( ! V_79 )
goto V_54;
V_80 = F_34 ( V_79 ) ;
}
if ( V_47 & ( 1 << ( V_116 - 1 ) ) ) {
int V_117 = 0 ;
F_35 () ;
V_75 = F_36 ( V_68 -> V_118 ) ;
if ( V_75 )
V_117 = F_37 ( V_46 , V_116 , V_75 -> V_119 ) ;
F_38 () ;
if ( V_117 < 0 )
goto V_54;
}
V_9 -> V_99 ( V_13 , V_11 , V_80 ) ;
if ( V_47 & ( 1 << ( V_113 - 1 ) ) && V_9 -> V_120 )
if ( V_9 -> V_120 ( V_13 , V_35 , V_46 ) < 0 )
goto V_54;
if ( V_13 -> V_59 < V_121 ) {
union V_122 V_80 ;
T_1 V_123 = 0 ;
int V_79 ;
F_35 () ;
V_75 = F_36 ( V_68 -> V_118 ) ;
if ( V_75 && V_75 -> V_124 )
V_123 = V_75 -> V_124 ( V_13 , V_47 , & V_79 , & V_80 ) ;
F_38 () ;
if ( V_123 && F_29 ( V_46 , V_79 , V_123 , & V_80 ) < 0 )
goto V_54;
}
if ( V_47 & ( 1 << ( V_125 - 1 ) ) ) {
V_42 V_126 = 0 ;
#ifdef F_39
V_126 = F_40 ( & V_13 -> V_127 ) ;
#endif
if ( F_18 ( V_46 , V_125 , V_126 ) )
goto V_54;
}
V_100:
F_41 ( V_46 , V_77 ) ;
return 0 ;
V_54:
F_42 ( V_46 , V_77 ) ;
return - V_82 ;
}
static int F_43 ( struct V_12 * V_13 ,
struct V_45 * V_46 ,
const struct V_33 * V_34 ,
struct V_48 * V_49 ,
V_42 V_69 , V_42 V_70 , T_2 V_71 ,
const struct V_72 * V_73 ,
bool V_35 )
{
return F_22 ( V_13 , F_44 ( V_13 ) , V_46 , V_34 , V_49 ,
V_69 , V_70 , V_71 , V_73 , V_35 ) ;
}
static int F_45 ( struct V_12 * V_13 ,
struct V_45 * V_46 ,
V_42 V_69 , V_42 V_70 , T_2 V_71 ,
const struct V_72 * V_73 )
{
struct V_128 * V_129 = F_46 ( V_13 ) ;
struct V_10 * V_11 ;
struct V_72 * V_77 ;
long V_130 ;
V_77 = F_24 ( V_46 , V_69 , V_70 , V_73 -> V_81 , sizeof( * V_11 ) ,
V_71 ) ;
if ( ! V_77 )
return - V_82 ;
V_11 = F_25 ( V_77 ) ;
F_23 ( V_129 -> V_131 != V_121 ) ;
V_130 = V_129 -> V_132 . V_112 - V_108 ;
if ( V_130 < 0 )
V_130 = 0 ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_85 = 0 ;
V_11 -> V_83 = V_129 -> V_133 ;
V_11 -> V_84 = 3 ;
V_11 -> V_106 = F_31 ( V_130 ) ;
V_11 -> V_134 = 0 ;
V_11 -> V_135 = 0 ;
V_11 -> V_65 = 0 ;
V_11 -> V_66 = 0 ;
F_41 ( V_46 , V_77 ) ;
return 0 ;
}
static int F_47 ( struct V_12 * V_13 , struct V_45 * V_46 ,
V_42 V_69 , V_42 V_70 , T_2 V_71 ,
const struct V_72 * V_73 , bool V_35 )
{
struct V_136 * V_137 = F_48 ( V_13 ) ;
struct V_10 * V_11 ;
struct V_72 * V_77 ;
long V_130 ;
V_77 = F_24 ( V_46 , V_69 , V_70 , V_73 -> V_81 , sizeof( * V_11 ) ,
V_71 ) ;
if ( ! V_77 )
return - V_82 ;
V_11 = F_25 ( V_77 ) ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_83 = V_138 ;
V_11 -> V_84 = 1 ;
V_11 -> V_85 = V_137 -> V_139 ;
F_49 ( F_50 ( struct V_140 , V_141 ) !=
F_50 ( struct V_12 , V_142 ) ) ;
V_130 = F_48 ( V_13 ) -> V_143 . V_112 - V_108 ;
V_11 -> V_106 = ( V_130 >= 0 ) ? F_31 ( V_130 ) : 0 ;
V_11 -> V_134 = 0 ;
V_11 -> V_135 = 0 ;
V_11 -> V_65 = 0 ;
V_11 -> V_66 = 0 ;
if ( V_35 && F_18 ( V_46 , V_63 ,
F_51 ( V_137 ) -> V_144 ) )
return - V_82 ;
F_41 ( V_46 , V_77 ) ;
return 0 ;
}
static int F_52 ( struct V_12 * V_13 , struct V_45 * V_46 ,
const struct V_33 * V_11 ,
struct V_48 * V_49 ,
V_42 V_69 , V_42 V_70 , T_2 V_71 ,
const struct V_72 * V_73 , bool V_35 )
{
if ( V_13 -> V_59 == V_121 )
return F_45 ( V_13 , V_46 , V_69 , V_70 ,
V_71 , V_73 ) ;
if ( V_13 -> V_59 == V_145 )
return F_47 ( V_13 , V_46 , V_69 , V_70 ,
V_71 , V_73 , V_35 ) ;
return F_43 ( V_13 , V_46 , V_11 , V_49 , V_69 , V_70 ,
V_71 , V_73 , V_35 ) ;
}
struct V_12 * F_53 ( struct V_146 * V_146 ,
struct V_147 * V_148 ,
const struct V_33 * V_34 )
{
struct V_12 * V_13 ;
F_35 () ;
if ( V_34 -> V_149 == V_6 )
V_13 = F_54 ( V_146 , V_148 , NULL , 0 , V_34 -> V_16 . V_29 [ 0 ] ,
V_34 -> V_16 . V_19 , V_34 -> V_16 . V_27 [ 0 ] ,
V_34 -> V_16 . V_17 , V_34 -> V_16 . V_21 ) ;
#if F_10 ( V_24 )
else if ( V_34 -> V_149 == V_25 ) {
if ( F_55 ( (struct V_26 * ) V_34 -> V_16 . V_29 ) &&
F_55 ( (struct V_26 * ) V_34 -> V_16 . V_27 ) )
V_13 = F_54 ( V_146 , V_148 , NULL , 0 , V_34 -> V_16 . V_29 [ 3 ] ,
V_34 -> V_16 . V_19 , V_34 -> V_16 . V_27 [ 3 ] ,
V_34 -> V_16 . V_17 , V_34 -> V_16 . V_21 ) ;
else
V_13 = F_56 ( V_146 , V_148 , NULL , 0 ,
(struct V_26 * ) V_34 -> V_16 . V_29 ,
V_34 -> V_16 . V_19 ,
(struct V_26 * ) V_34 -> V_16 . V_27 ,
V_34 -> V_16 . V_17 ,
V_34 -> V_16 . V_21 ) ;
}
#endif
else {
F_38 () ;
return F_4 ( - V_150 ) ;
}
F_38 () ;
if ( ! V_13 )
return F_4 ( - V_8 ) ;
if ( F_57 ( V_13 , V_34 -> V_16 . V_23 ) ) {
F_58 ( V_13 ) ;
return F_4 ( - V_8 ) ;
}
return V_13 ;
}
int F_59 ( struct V_147 * V_148 ,
struct V_45 * V_151 ,
const struct V_72 * V_77 ,
const struct V_33 * V_34 )
{
bool V_35 = F_60 ( V_151 , V_152 ) ;
struct V_146 * V_146 = F_61 ( V_151 -> V_13 ) ;
struct V_45 * V_153 ;
struct V_12 * V_13 ;
int V_117 ;
V_13 = F_53 ( V_146 , V_148 , V_34 ) ;
if ( F_62 ( V_13 ) )
return F_63 ( V_13 ) ;
V_153 = F_64 ( F_11 ( V_13 , V_34 , V_35 ) , V_154 ) ;
if ( ! V_153 ) {
V_117 = - V_155 ;
goto V_100;
}
V_117 = F_52 ( V_13 , V_153 , V_34 ,
F_65 ( F_66 ( V_151 ) . V_13 ) ,
F_66 ( V_151 ) . V_69 ,
V_77 -> V_156 , 0 , V_77 , V_35 ) ;
if ( V_117 < 0 ) {
F_67 ( V_117 == - V_82 ) ;
F_68 ( V_153 ) ;
goto V_100;
}
V_117 = F_69 ( V_146 -> V_157 , V_153 , F_66 ( V_151 ) . V_69 ,
V_158 ) ;
if ( V_117 > 0 )
V_117 = 0 ;
V_100:
if ( V_13 )
F_58 ( V_13 ) ;
return V_117 ;
}
static int F_70 ( int V_159 , struct V_45 * V_151 ,
const struct V_72 * V_77 ,
const struct V_33 * V_34 )
{
const struct V_1 * V_9 ;
int V_117 ;
V_9 = F_1 ( V_34 -> V_37 ) ;
if ( F_62 ( V_9 ) )
V_117 = F_63 ( V_9 ) ;
else if ( V_159 == V_160 )
V_117 = V_9 -> V_161 ( V_151 , V_77 , V_34 ) ;
else if ( V_159 == V_162 && V_9 -> V_163 )
V_117 = V_9 -> V_163 ( V_151 , V_34 ) ;
else
V_117 = - V_164 ;
F_5 ( V_9 ) ;
return V_117 ;
}
static int F_71 ( const T_3 * V_165 , const T_3 * V_166 , int V_167 )
{
int V_168 = V_167 >> 5 ;
V_167 &= 0x1f ;
if ( V_168 ) {
if ( memcmp ( V_165 , V_166 , V_168 << 2 ) )
return 0 ;
}
if ( V_167 ) {
T_3 V_169 , V_170 ;
T_3 V_171 ;
V_169 = V_165 [ V_168 ] ;
V_170 = V_166 [ V_168 ] ;
V_171 = F_72 ( ( 0xffffffff ) << ( 32 - V_167 ) ) ;
if ( ( V_169 ^ V_170 ) & V_171 )
return 0 ;
}
return 1 ;
}
static int F_73 ( const struct V_78 * V_172 ,
const struct V_173 * V_174 )
{
const void * V_175 = F_34 ( V_172 ) ;
int V_176 = F_74 ( V_172 ) ;
while ( V_176 > 0 ) {
int V_177 = 1 ;
const struct V_178 * V_179 = V_175 ;
switch ( V_179 -> V_180 ) {
case V_181 :
break;
case V_182 :
V_177 = 0 ;
break;
case V_183 :
V_177 = V_174 -> V_184 >= V_179 [ 1 ] . V_185 ;
break;
case V_186 :
V_177 = V_174 -> V_184 <= V_179 [ 1 ] . V_185 ;
break;
case V_187 :
V_177 = V_174 -> V_188 >= V_179 [ 1 ] . V_185 ;
break;
case V_189 :
V_177 = V_174 -> V_188 <= V_179 [ 1 ] . V_185 ;
break;
case V_190 :
V_177 = ! ( V_174 -> V_191 & V_192 ) ;
break;
case V_193 :
case V_194 : {
const struct V_195 * V_196 ;
const T_3 * V_197 ;
V_196 = ( const struct V_195 * ) ( V_179 + 1 ) ;
if ( V_196 -> V_198 != - 1 &&
V_196 -> V_198 != ( V_179 -> V_180 == V_193 ?
V_174 -> V_184 : V_174 -> V_188 ) ) {
V_177 = 0 ;
break;
}
if ( V_179 -> V_180 == V_193 )
V_197 = V_174 -> V_199 ;
else
V_197 = V_174 -> V_200 ;
if ( V_196 -> V_201 != V_202 &&
V_196 -> V_201 != V_174 -> V_201 ) {
if ( V_174 -> V_201 == V_25 &&
V_196 -> V_201 == V_6 ) {
if ( V_197 [ 0 ] == 0 && V_197 [ 1 ] == 0 &&
V_197 [ 2 ] == F_72 ( 0xffff ) &&
F_71 ( V_197 + 3 ,
V_196 -> V_197 ,
V_196 -> V_203 ) )
break;
}
V_177 = 0 ;
break;
}
if ( V_196 -> V_203 == 0 )
break;
if ( F_71 ( V_197 , V_196 -> V_197 ,
V_196 -> V_203 ) )
break;
V_177 = 0 ;
break;
}
case V_204 : {
V_42 V_205 ;
V_205 = * ( ( const V_42 * ) ( V_179 + 1 ) ) ;
if ( V_205 != V_174 -> V_205 )
V_177 = 0 ;
break;
}
case V_206 : {
struct V_207 * V_196 ;
V_196 = (struct V_207 * ) ( V_179 + 1 ) ;
if ( ( V_174 -> V_208 & V_196 -> V_171 ) != V_196 -> V_208 )
V_177 = 0 ;
break;
}
}
if ( V_177 ) {
V_176 -= V_179 -> V_177 ;
V_175 += V_179 -> V_177 ;
} else {
V_176 -= V_179 -> V_185 ;
V_175 += V_179 -> V_185 ;
}
}
return V_176 == 0 ;
}
static void F_75 ( struct V_173 * V_174 ,
const struct V_12 * V_13 )
{
#if F_10 ( V_24 )
if ( V_13 -> V_15 == V_25 ) {
V_174 -> V_199 = V_13 -> V_28 . V_209 ;
V_174 -> V_200 = V_13 -> V_30 . V_209 ;
} else
#endif
{
V_174 -> V_199 = & V_13 -> V_31 ;
V_174 -> V_200 = & V_13 -> V_32 ;
}
}
int F_76 ( const struct V_78 * V_175 , struct V_12 * V_13 )
{
struct V_50 * V_51 = F_14 ( V_13 ) ;
struct V_173 V_174 ;
if ( ! V_175 )
return 1 ;
V_174 . V_201 = V_13 -> V_15 ;
F_75 ( & V_174 , V_13 ) ;
V_174 . V_184 = V_51 -> V_210 ;
V_174 . V_188 = F_77 ( V_51 -> V_211 ) ;
V_174 . V_205 = V_13 -> V_22 ;
V_174 . V_191 = F_26 ( V_13 ) ? V_13 -> V_212 : 0 ;
if ( F_26 ( V_13 ) )
V_174 . V_208 = V_13 -> V_64 ;
else if ( V_13 -> V_59 == V_145 )
V_174 . V_208 = F_51 ( F_48 ( V_13 ) ) -> V_144 ;
else
V_174 . V_208 = 0 ;
return F_73 ( V_175 , & V_174 ) ;
}
static int F_78 ( const void * V_175 , int V_176 , int V_213 )
{
while ( V_176 >= 0 ) {
const struct V_178 * V_179 = V_175 ;
if ( V_213 > V_176 )
return 0 ;
if ( V_213 == V_176 )
return 1 ;
if ( V_179 -> V_177 < 4 || V_179 -> V_177 & 3 )
return 0 ;
V_176 -= V_179 -> V_177 ;
V_175 += V_179 -> V_177 ;
}
return 0 ;
}
static bool F_79 ( const struct V_178 * V_179 , int V_176 ,
int * V_214 )
{
* V_214 += sizeof( V_42 ) ;
if ( V_176 < * V_214 )
return false ;
return true ;
}
static bool F_80 ( const struct V_178 * V_179 , int V_176 ,
int * V_214 )
{
struct V_195 * V_196 ;
int V_215 ;
* V_214 += sizeof( struct V_195 ) ;
if ( V_176 < * V_214 )
return false ;
V_196 = (struct V_195 * ) ( V_179 + 1 ) ;
switch ( V_196 -> V_201 ) {
case V_202 :
V_215 = 0 ;
break;
case V_6 :
V_215 = sizeof( struct V_216 ) ;
break;
case V_25 :
V_215 = sizeof( struct V_26 ) ;
break;
default:
return false ;
}
* V_214 += V_215 ;
if ( V_176 < * V_214 )
return false ;
if ( V_196 -> V_203 > 8 * V_215 )
return false ;
return true ;
}
static bool F_81 ( const struct V_178 * V_179 ,
int V_176 , int * V_214 )
{
* V_214 += sizeof( struct V_178 ) ;
if ( V_176 < * V_214 )
return false ;
return true ;
}
static bool F_82 ( const struct V_178 * V_179 , int V_176 ,
int * V_214 )
{
* V_214 += sizeof( struct V_207 ) ;
return V_176 >= * V_214 ;
}
static int F_83 ( const struct V_78 * V_79 ,
const struct V_45 * V_46 )
{
bool V_35 = F_60 ( V_46 , V_152 ) ;
const void * V_217 , * V_175 ;
int V_218 , V_176 ;
if ( ! V_79 || F_74 ( V_79 ) < sizeof( struct V_178 ) )
return - V_150 ;
V_217 = V_175 = F_34 ( V_79 ) ;
V_176 = V_218 = F_74 ( V_79 ) ;
while ( V_176 > 0 ) {
int V_214 = sizeof( struct V_178 ) ;
const struct V_178 * V_179 = V_175 ;
switch ( V_179 -> V_180 ) {
case V_193 :
case V_194 :
if ( ! F_80 ( V_175 , V_176 , & V_214 ) )
return - V_150 ;
break;
case V_204 :
if ( ! F_79 ( V_175 , V_176 , & V_214 ) )
return - V_150 ;
break;
case V_183 :
case V_186 :
case V_187 :
case V_189 :
if ( ! F_81 ( V_175 , V_176 , & V_214 ) )
return - V_150 ;
break;
case V_206 :
if ( ! V_35 )
return - V_219 ;
if ( ! F_82 ( V_175 , V_176 , & V_214 ) )
return - V_150 ;
break;
case V_190 :
case V_182 :
case V_181 :
break;
default:
return - V_150 ;
}
if ( V_179 -> V_180 != V_181 ) {
if ( V_179 -> V_185 < V_214 || V_179 -> V_185 > V_176 + 4 || V_179 -> V_185 & 3 )
return - V_150 ;
if ( V_179 -> V_185 < V_176 &&
! F_78 ( V_217 , V_218 , V_176 - V_179 -> V_185 ) )
return - V_150 ;
}
if ( V_179 -> V_177 < V_214 || V_179 -> V_177 > V_176 + 4 || V_179 -> V_177 & 3 )
return - V_150 ;
V_175 += V_179 -> V_177 ;
V_176 -= V_179 -> V_177 ;
}
return V_176 == 0 ? 0 : - V_150 ;
}
static int F_84 ( struct V_12 * V_13 ,
struct V_45 * V_46 ,
struct V_220 * V_221 ,
const struct V_33 * V_11 ,
const struct V_78 * V_175 ,
bool V_35 )
{
if ( ! F_76 ( V_175 , V_13 ) )
return 0 ;
return F_43 ( V_13 , V_46 , V_11 ,
F_65 ( F_66 ( V_221 -> V_46 ) . V_13 ) ,
F_66 ( V_221 -> V_46 ) . V_69 ,
V_221 -> V_77 -> V_156 , V_222 , V_221 -> V_77 ,
V_35 ) ;
}
static void F_85 ( void )
{
F_49 ( F_50 ( struct V_128 , V_223 ) !=
F_50 ( struct V_12 , V_15 ) ) ;
F_49 ( F_50 ( struct V_128 , V_224 ) !=
F_50 ( struct V_50 , V_210 ) ) ;
F_49 ( F_50 ( struct V_128 , V_225 ) !=
F_50 ( struct V_50 , V_211 ) ) ;
F_49 ( F_50 ( struct V_128 , V_226 ) !=
F_50 ( struct V_50 , V_227 ) ) ;
F_49 ( F_50 ( struct V_128 , V_228 ) !=
F_50 ( struct V_50 , V_229 ) ) ;
#if F_10 ( V_24 )
F_49 ( F_50 ( struct V_128 , V_230 ) !=
F_50 ( struct V_12 , V_28 ) ) ;
F_49 ( F_50 ( struct V_128 , V_231 ) !=
F_50 ( struct V_12 , V_30 ) ) ;
#endif
}
void F_86 ( struct V_147 * V_148 , struct V_45 * V_46 ,
struct V_220 * V_221 ,
const struct V_33 * V_11 , struct V_78 * V_175 )
{
bool V_35 = F_60 ( V_221 -> V_46 , V_152 ) ;
struct V_146 * V_146 = F_61 ( V_46 -> V_13 ) ;
V_42 V_232 = V_11 -> V_232 ;
int V_233 , V_234 , V_235 , V_236 ;
struct V_12 * V_13 ;
if ( V_232 & V_237 )
V_232 |= V_238 ;
V_235 = V_221 -> args [ 1 ] ;
V_236 = V_234 = V_221 -> args [ 2 ] ;
if ( V_221 -> args [ 0 ] == 0 ) {
if ( ! ( V_232 & V_60 ) || V_11 -> V_16 . V_19 )
goto V_239;
for ( V_233 = V_235 ; V_233 < V_240 ; V_233 ++ ) {
struct V_241 * V_242 ;
V_234 = 0 ;
V_242 = & V_148 -> V_243 [ V_233 ] ;
F_87 ( & V_242 -> V_244 ) ;
F_88 (sk, &ilb->head) {
struct V_50 * V_51 = F_14 ( V_13 ) ;
if ( ! F_89 ( F_61 ( V_13 ) , V_146 ) )
continue;
if ( V_234 < V_236 ) {
V_234 ++ ;
continue;
}
if ( V_11 -> V_149 != V_202 &&
V_13 -> V_15 != V_11 -> V_149 )
goto V_245;
if ( V_11 -> V_16 . V_17 != V_51 -> V_246 &&
V_11 -> V_16 . V_17 )
goto V_245;
if ( F_84 ( V_13 , V_46 , V_221 , V_11 ,
V_175 , V_35 ) < 0 ) {
F_90 ( & V_242 -> V_244 ) ;
goto V_247;
}
V_245:
++ V_234 ;
}
F_90 ( & V_242 -> V_244 ) ;
V_236 = 0 ;
}
V_239:
V_221 -> args [ 0 ] = 1 ;
V_235 = V_234 = V_236 = 0 ;
}
if ( ! ( V_232 & ~ V_60 ) )
goto V_100;
#define F_91 16
for ( V_233 = V_235 ; V_233 <= V_148 -> V_248 ; V_233 ++ ) {
struct V_249 * V_250 = & V_148 -> V_251 [ V_233 ] ;
T_4 * V_244 = F_92 ( V_148 , V_233 ) ;
struct V_252 * V_253 ;
struct V_12 * V_254 [ F_91 ] ;
int V_255 [ F_91 ] ;
int V_256 , V_257 , V_258 ;
if ( F_93 ( & V_250 -> V_259 ) )
continue;
if ( V_233 > V_235 )
V_236 = 0 ;
V_260:
V_234 = 0 ;
V_257 = 0 ;
F_94 ( V_244 ) ;
F_95 (sk, node, &head->chain) {
int V_261 ;
if ( ! F_89 ( F_61 ( V_13 ) , V_146 ) )
continue;
if ( V_234 < V_236 )
goto V_262;
V_261 = ( V_13 -> V_59 == V_121 ) ?
F_46 ( V_13 ) -> V_133 : V_13 -> V_59 ;
if ( ! ( V_232 & ( 1 << V_261 ) ) )
goto V_262;
if ( V_11 -> V_149 != V_202 &&
V_13 -> V_15 != V_11 -> V_149 )
goto V_262;
if ( V_11 -> V_16 . V_17 != F_8 ( V_13 -> V_18 ) &&
V_11 -> V_16 . V_17 )
goto V_262;
if ( V_11 -> V_16 . V_19 != V_13 -> V_20 &&
V_11 -> V_16 . V_19 )
goto V_262;
F_85 () ;
if ( ! F_76 ( V_175 , V_13 ) )
goto V_262;
F_96 ( V_13 ) ;
V_255 [ V_257 ] = V_234 ;
V_254 [ V_257 ] = V_13 ;
if ( ++ V_257 == F_91 )
break;
V_262:
++ V_234 ;
}
F_97 ( V_244 ) ;
V_258 = 0 ;
for ( V_256 = 0 ; V_256 < V_257 ; V_256 ++ ) {
if ( V_258 >= 0 ) {
V_258 = F_52 ( V_254 [ V_256 ] , V_46 , V_11 ,
F_65 ( F_66 ( V_221 -> V_46 ) . V_13 ) ,
F_66 ( V_221 -> V_46 ) . V_69 ,
V_221 -> V_77 -> V_156 , V_222 ,
V_221 -> V_77 , V_35 ) ;
if ( V_258 < 0 )
V_234 = V_255 [ V_256 ] ;
}
F_58 ( V_254 [ V_256 ] ) ;
}
if ( V_258 < 0 )
break;
F_98 () ;
if ( V_257 == F_91 ) {
V_236 = V_234 + 1 ;
goto V_260;
}
}
V_247:
V_221 -> args [ 1 ] = V_233 ;
V_221 -> args [ 2 ] = V_234 ;
V_100:
;
}
static int F_99 ( struct V_45 * V_46 , struct V_220 * V_221 ,
const struct V_33 * V_11 ,
struct V_78 * V_175 )
{
const struct V_1 * V_9 ;
int V_117 = 0 ;
V_9 = F_1 ( V_11 -> V_37 ) ;
if ( ! F_62 ( V_9 ) )
V_9 -> V_263 ( V_46 , V_221 , V_11 , V_175 ) ;
else
V_117 = F_63 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_117 ? : V_46 -> V_176 ;
}
static int F_100 ( struct V_45 * V_46 , struct V_220 * V_221 )
{
int V_264 = sizeof( struct V_33 ) ;
struct V_78 * V_175 = NULL ;
if ( F_101 ( V_221 -> V_77 , V_264 ) )
V_175 = F_102 ( V_221 -> V_77 , V_264 , V_265 ) ;
return F_99 ( V_46 , V_221 , F_25 ( V_221 -> V_77 ) , V_175 ) ;
}
static int F_103 ( int type )
{
switch ( type ) {
case V_266 :
return V_267 ;
case V_268 :
return V_269 ;
default:
return 0 ;
}
}
static int F_104 ( struct V_45 * V_46 ,
struct V_220 * V_221 )
{
struct V_270 * V_271 = F_25 ( V_221 -> V_77 ) ;
int V_264 = sizeof( struct V_270 ) ;
struct V_33 V_34 ;
struct V_78 * V_175 = NULL ;
V_34 . V_149 = V_202 ;
V_34 . V_37 = F_103 ( V_221 -> V_77 -> V_81 ) ;
V_34 . V_76 = V_271 -> V_76 ;
V_34 . V_232 = V_271 -> V_232 ;
V_34 . V_16 = V_271 -> V_16 ;
if ( F_101 ( V_221 -> V_77 , V_264 ) )
V_175 = F_102 ( V_221 -> V_77 , V_264 , V_265 ) ;
return F_99 ( V_46 , V_221 , & V_34 , V_175 ) ;
}
static int F_105 ( struct V_45 * V_151 ,
const struct V_72 * V_77 )
{
struct V_270 * V_271 = F_25 ( V_77 ) ;
struct V_33 V_34 ;
V_34 . V_149 = V_271 -> V_14 ;
V_34 . V_37 = F_103 ( V_77 -> V_81 ) ;
V_34 . V_76 = V_271 -> V_76 ;
V_34 . V_232 = V_271 -> V_232 ;
V_34 . V_16 = V_271 -> V_16 ;
return F_70 ( V_160 , V_151 , V_77 , & V_34 ) ;
}
static int F_106 ( struct V_45 * V_46 , struct V_72 * V_77 )
{
int V_264 = sizeof( struct V_270 ) ;
struct V_146 * V_146 = F_61 ( V_46 -> V_13 ) ;
if ( V_77 -> V_81 >= V_272 ||
F_107 ( V_77 ) < V_264 )
return - V_150 ;
if ( V_77 -> V_71 & V_273 ) {
if ( F_101 ( V_77 , V_264 ) ) {
struct V_78 * V_79 ;
int V_117 ;
V_79 = F_102 ( V_77 , V_264 ,
V_265 ) ;
V_117 = F_83 ( V_79 , V_46 ) ;
if ( V_117 )
return V_117 ;
}
{
struct V_274 V_275 = {
. V_263 = F_104 ,
} ;
return F_108 ( V_146 -> V_157 , V_46 , V_77 , & V_275 ) ;
}
}
return F_105 ( V_46 , V_77 ) ;
}
static int F_109 ( struct V_45 * V_46 , struct V_72 * V_276 )
{
int V_264 = sizeof( struct V_33 ) ;
struct V_146 * V_146 = F_61 ( V_46 -> V_13 ) ;
if ( F_107 ( V_276 ) < V_264 )
return - V_150 ;
if ( V_276 -> V_81 == V_160 &&
V_276 -> V_71 & V_273 ) {
if ( F_101 ( V_276 , V_264 ) ) {
struct V_78 * V_79 ;
int V_117 ;
V_79 = F_102 ( V_276 , V_264 ,
V_265 ) ;
V_117 = F_83 ( V_79 , V_46 ) ;
if ( V_117 )
return V_117 ;
}
{
struct V_274 V_275 = {
. V_263 = F_100 ,
} ;
return F_108 ( V_146 -> V_157 , V_46 , V_276 , & V_275 ) ;
}
}
return F_70 ( V_276 -> V_81 , V_46 , V_276 , F_25 ( V_276 ) ) ;
}
static
int F_110 ( struct V_45 * V_46 , struct V_12 * V_13 )
{
const struct V_1 * V_9 ;
struct V_72 * V_77 ;
struct V_78 * V_79 ;
struct V_10 * V_11 ;
void * V_80 = NULL ;
int V_117 = 0 ;
V_77 = F_24 ( V_46 , 0 , 0 , V_160 , sizeof( * V_11 ) , 0 ) ;
if ( ! V_77 )
return - V_155 ;
V_11 = F_25 ( V_77 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_7 ( V_11 , V_13 ) ;
if ( V_13 -> V_95 == V_277 || V_13 -> V_95 == V_278 )
V_11 -> V_16 . V_17 = F_14 ( V_13 ) -> V_246 ;
V_11 -> V_83 = V_13 -> V_59 ;
if ( ( V_117 = F_15 ( V_46 , V_97 , V_13 -> V_98 ) ) ) {
F_42 ( V_46 , V_77 ) ;
return V_117 ;
}
V_9 = F_1 ( V_13 -> V_98 ) ;
if ( F_62 ( V_9 ) ) {
F_5 ( V_9 ) ;
F_42 ( V_46 , V_77 ) ;
return F_63 ( V_9 ) ;
}
V_79 = V_9 -> V_114
? F_33 ( V_46 , V_113 ,
V_9 -> V_114 ,
V_115 )
: NULL ;
if ( V_79 )
V_80 = F_34 ( V_79 ) ;
V_9 -> V_99 ( V_13 , V_11 , V_80 ) ;
F_5 ( V_9 ) ;
F_41 ( V_46 , V_77 ) ;
return 0 ;
}
int F_111 ( const struct V_1 * V_276 )
{
const T_5 type = V_276 -> V_279 ;
int V_117 = - V_150 ;
if ( type >= V_280 )
goto V_100;
F_3 ( & V_7 ) ;
V_117 = - V_281 ;
if ( ! V_3 [ type ] ) {
V_3 [ type ] = V_276 ;
V_117 = 0 ;
}
F_6 ( & V_7 ) ;
V_100:
return V_117 ;
}
void F_112 ( const struct V_1 * V_276 )
{
const T_5 type = V_276 -> V_279 ;
if ( type >= V_280 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_6 F_113 ( void )
{
const int V_282 = ( V_280 *
sizeof( struct V_1 * ) ) ;
int V_117 = - V_155 ;
V_3 = F_114 ( V_282 , V_154 ) ;
if ( ! V_3 )
goto V_100;
V_117 = F_115 ( & V_1 ) ;
if ( V_117 )
goto V_283;
V_117 = F_115 ( & V_284 ) ;
if ( V_117 )
goto V_285;
F_116 ( F_106 ) ;
V_100:
return V_117 ;
V_285:
F_117 ( & V_1 ) ;
V_283:
F_118 ( V_3 ) ;
goto V_100;
}
static void T_7 F_119 ( void )
{
F_117 ( & V_284 ) ;
F_117 ( & V_1 ) ;
F_120 ( F_106 ) ;
F_118 ( V_3 ) ;
}
