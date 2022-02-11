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
static T_1 F_11 ( void )
{
return F_12 ( sizeof( struct V_33 ) )
+ F_12 ( 1 )
+ F_12 ( 1 )
+ F_12 ( 1 )
+ F_12 ( 4 )
+ F_12 ( sizeof( struct V_34 ) )
+ F_12 ( sizeof( struct V_10 ) )
+ F_12 ( V_35 * sizeof( V_36 ) )
+ F_12 ( V_37 )
+ F_12 ( sizeof( struct V_38 ) )
+ 64 ;
}
int F_13 ( struct V_12 * V_13 , struct V_39 * V_40 ,
struct V_10 * V_11 , int V_41 ,
struct V_42 * V_43 ,
bool V_44 )
{
const struct V_45 * V_46 = F_14 ( V_13 ) ;
if ( F_15 ( V_40 , V_47 , V_13 -> V_48 ) )
goto V_49;
if ( V_41 & ( 1 << ( V_50 - 1 ) ) )
if ( F_15 ( V_40 , V_50 , V_46 -> V_51 ) < 0 )
goto V_49;
#if F_10 ( V_24 )
if ( V_11 -> V_14 == V_25 ) {
if ( V_41 & ( 1 << ( V_52 - 1 ) ) )
if ( F_15 ( V_40 , V_52 ,
F_16 ( V_13 ) -> V_53 ) < 0 )
goto V_49;
if ( ( ( 1 << V_13 -> V_54 ) & ( V_55 | V_56 ) ) &&
F_15 ( V_40 , V_57 , F_17 ( V_13 ) ) )
goto V_49;
}
#endif
if ( V_44 && F_18 ( V_40 , V_58 , V_13 -> V_59 ) )
goto V_49;
V_11 -> V_60 = F_19 ( V_43 , F_20 ( V_13 ) ) ;
V_11 -> V_61 = F_21 ( V_13 ) ;
return 0 ;
V_49:
return 1 ;
}
int F_22 ( struct V_12 * V_13 , struct V_62 * V_63 ,
struct V_39 * V_40 , const struct V_64 * V_65 ,
struct V_42 * V_43 ,
V_36 V_66 , V_36 V_67 , T_2 V_68 ,
const struct V_69 * V_70 ,
bool V_44 )
{
const struct V_71 * V_72 ;
const struct V_1 * V_9 ;
int V_41 = V_65 -> V_73 ;
struct V_10 * V_11 ;
struct V_69 * V_74 ;
struct V_75 * V_76 ;
void * V_77 = NULL ;
V_9 = V_3 [ V_65 -> V_78 ] ;
F_23 ( ! V_9 ) ;
V_74 = F_24 ( V_40 , V_66 , V_67 , V_70 -> V_79 , sizeof( * V_11 ) ,
V_68 ) ;
if ( ! V_74 )
return - V_80 ;
V_11 = F_25 ( V_74 ) ;
F_23 ( ! F_26 ( V_13 ) ) ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_81 = V_13 -> V_54 ;
V_11 -> V_82 = 0 ;
V_11 -> V_83 = 0 ;
if ( F_13 ( V_13 , V_40 , V_11 , V_41 , V_43 , V_44 ) )
goto V_49;
if ( V_41 & ( 1 << ( V_84 - 1 ) ) ) {
struct V_34 V_85 = {
. V_86 = F_27 ( V_13 ) ,
. V_87 = V_13 -> V_88 ,
. V_89 = V_13 -> V_90 ,
. V_91 = F_28 ( V_13 ) ,
} ;
if ( F_29 ( V_40 , V_84 , sizeof( V_85 ) , & V_85 ) < 0 )
goto V_49;
}
if ( V_41 & ( 1 << ( V_92 - 1 ) ) )
if ( F_30 ( V_13 , V_40 , V_92 ) )
goto V_49;
if ( V_13 -> V_93 == V_94 ) {
if ( F_15 ( V_40 , V_95 , V_13 -> V_96 ) )
goto V_49;
}
if ( ! V_63 ) {
V_9 -> V_97 ( V_13 , V_11 , NULL ) ;
goto V_98;
}
if ( V_63 -> V_99 == V_100 ||
V_63 -> V_99 == V_101 ||
V_63 -> V_99 == V_102 ) {
V_11 -> V_82 = 1 ;
V_11 -> V_83 = V_63 -> V_103 ;
V_11 -> V_104 =
F_31 ( V_63 -> V_105 - V_106 ) ;
} else if ( V_63 -> V_99 == V_107 ) {
V_11 -> V_82 = 4 ;
V_11 -> V_83 = V_63 -> V_108 ;
V_11 -> V_104 =
F_31 ( V_63 -> V_105 - V_106 ) ;
} else if ( F_32 ( & V_13 -> V_109 ) ) {
V_11 -> V_82 = 2 ;
V_11 -> V_83 = V_63 -> V_108 ;
V_11 -> V_104 =
F_31 ( V_13 -> V_109 . V_110 - V_106 ) ;
} else {
V_11 -> V_82 = 0 ;
V_11 -> V_104 = 0 ;
}
if ( ( V_41 & ( 1 << ( V_111 - 1 ) ) ) && V_9 -> V_112 ) {
V_76 = F_33 ( V_40 , V_111 ,
V_9 -> V_112 ,
V_113 ) ;
if ( ! V_76 )
goto V_49;
V_77 = F_34 ( V_76 ) ;
}
if ( V_41 & ( 1 << ( V_114 - 1 ) ) ) {
int V_115 = 0 ;
F_35 () ;
V_72 = F_36 ( V_63 -> V_116 ) ;
if ( V_72 )
V_115 = F_37 ( V_40 , V_114 , V_72 -> V_117 ) ;
F_38 () ;
if ( V_115 < 0 )
goto V_49;
}
V_9 -> V_97 ( V_13 , V_11 , V_77 ) ;
if ( V_13 -> V_54 < V_118 ) {
union V_119 V_77 ;
T_1 V_120 = 0 ;
int V_76 ;
F_35 () ;
V_72 = F_36 ( V_63 -> V_116 ) ;
if ( V_72 && V_72 -> V_121 )
V_120 = V_72 -> V_121 ( V_13 , V_41 , & V_76 , & V_77 ) ;
F_38 () ;
if ( V_120 && F_29 ( V_40 , V_76 , V_120 , & V_77 ) < 0 )
goto V_49;
}
V_98:
F_39 ( V_40 , V_74 ) ;
return 0 ;
V_49:
F_40 ( V_40 , V_74 ) ;
return - V_80 ;
}
static int F_41 ( struct V_12 * V_13 ,
struct V_39 * V_40 ,
const struct V_64 * V_65 ,
struct V_42 * V_43 ,
V_36 V_66 , V_36 V_67 , T_2 V_68 ,
const struct V_69 * V_70 ,
bool V_44 )
{
return F_22 ( V_13 , F_42 ( V_13 ) , V_40 , V_65 , V_43 ,
V_66 , V_67 , V_68 , V_70 , V_44 ) ;
}
static int F_43 ( struct V_12 * V_13 ,
struct V_39 * V_40 ,
V_36 V_66 , V_36 V_67 , T_2 V_68 ,
const struct V_69 * V_70 )
{
struct V_122 * V_123 = F_44 ( V_13 ) ;
struct V_10 * V_11 ;
struct V_69 * V_74 ;
long V_124 ;
V_74 = F_24 ( V_40 , V_66 , V_67 , V_70 -> V_79 , sizeof( * V_11 ) ,
V_68 ) ;
if ( ! V_74 )
return - V_80 ;
V_11 = F_25 ( V_74 ) ;
F_23 ( V_123 -> V_125 != V_118 ) ;
V_124 = V_123 -> V_126 . V_110 - V_106 ;
if ( V_124 < 0 )
V_124 = 0 ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_83 = 0 ;
V_11 -> V_81 = V_123 -> V_127 ;
V_11 -> V_82 = 3 ;
V_11 -> V_104 = F_31 ( V_124 ) ;
V_11 -> V_128 = 0 ;
V_11 -> V_129 = 0 ;
V_11 -> V_60 = 0 ;
V_11 -> V_61 = 0 ;
F_39 ( V_40 , V_74 ) ;
return 0 ;
}
static int F_45 ( struct V_12 * V_13 , struct V_39 * V_40 ,
V_36 V_66 , V_36 V_67 , T_2 V_68 ,
const struct V_69 * V_70 , bool V_44 )
{
struct V_130 * V_131 = F_46 ( V_13 ) ;
struct V_10 * V_11 ;
struct V_69 * V_74 ;
long V_124 ;
V_74 = F_24 ( V_40 , V_66 , V_67 , V_70 -> V_79 , sizeof( * V_11 ) ,
V_68 ) ;
if ( ! V_74 )
return - V_80 ;
V_11 = F_25 ( V_74 ) ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_81 = V_132 ;
V_11 -> V_82 = 1 ;
V_11 -> V_83 = V_131 -> V_133 ;
F_47 ( F_48 ( struct V_134 , V_135 ) !=
F_48 ( struct V_12 , V_136 ) ) ;
V_124 = F_46 ( V_13 ) -> V_137 . V_110 - V_106 ;
V_11 -> V_104 = ( V_124 >= 0 ) ? F_31 ( V_124 ) : 0 ;
V_11 -> V_128 = 0 ;
V_11 -> V_129 = 0 ;
V_11 -> V_60 = 0 ;
V_11 -> V_61 = 0 ;
if ( V_44 && F_18 ( V_40 , V_58 ,
F_49 ( V_131 ) -> V_138 ) )
return - V_80 ;
F_39 ( V_40 , V_74 ) ;
return 0 ;
}
static int F_50 ( struct V_12 * V_13 , struct V_39 * V_40 ,
const struct V_64 * V_11 ,
struct V_42 * V_43 ,
V_36 V_66 , V_36 V_67 , T_2 V_68 ,
const struct V_69 * V_70 , bool V_44 )
{
if ( V_13 -> V_54 == V_118 )
return F_43 ( V_13 , V_40 , V_66 , V_67 ,
V_68 , V_70 ) ;
if ( V_13 -> V_54 == V_139 )
return F_45 ( V_13 , V_40 , V_66 , V_67 ,
V_68 , V_70 , V_44 ) ;
return F_41 ( V_13 , V_40 , V_11 , V_43 , V_66 , V_67 ,
V_68 , V_70 , V_44 ) ;
}
struct V_12 * F_51 ( struct V_140 * V_140 ,
struct V_141 * V_142 ,
const struct V_64 * V_65 )
{
struct V_12 * V_13 ;
F_35 () ;
if ( V_65 -> V_143 == V_6 )
V_13 = F_52 ( V_140 , V_142 , NULL , 0 , V_65 -> V_16 . V_29 [ 0 ] ,
V_65 -> V_16 . V_19 , V_65 -> V_16 . V_27 [ 0 ] ,
V_65 -> V_16 . V_17 , V_65 -> V_16 . V_21 ) ;
#if F_10 ( V_24 )
else if ( V_65 -> V_143 == V_25 ) {
if ( F_53 ( (struct V_26 * ) V_65 -> V_16 . V_29 ) &&
F_53 ( (struct V_26 * ) V_65 -> V_16 . V_27 ) )
V_13 = F_52 ( V_140 , V_142 , NULL , 0 , V_65 -> V_16 . V_29 [ 3 ] ,
V_65 -> V_16 . V_19 , V_65 -> V_16 . V_27 [ 3 ] ,
V_65 -> V_16 . V_17 , V_65 -> V_16 . V_21 ) ;
else
V_13 = F_54 ( V_140 , V_142 , NULL , 0 ,
(struct V_26 * ) V_65 -> V_16 . V_29 ,
V_65 -> V_16 . V_19 ,
(struct V_26 * ) V_65 -> V_16 . V_27 ,
V_65 -> V_16 . V_17 ,
V_65 -> V_16 . V_21 ) ;
}
#endif
else {
F_38 () ;
return F_4 ( - V_144 ) ;
}
F_38 () ;
if ( ! V_13 )
return F_4 ( - V_8 ) ;
if ( F_55 ( V_13 , V_65 -> V_16 . V_23 ) ) {
F_56 ( V_13 ) ;
return F_4 ( - V_8 ) ;
}
return V_13 ;
}
int F_57 ( struct V_141 * V_142 ,
struct V_39 * V_145 ,
const struct V_69 * V_74 ,
const struct V_64 * V_65 )
{
struct V_140 * V_140 = F_58 ( V_145 -> V_13 ) ;
struct V_39 * V_146 ;
struct V_12 * V_13 ;
int V_115 ;
V_13 = F_51 ( V_140 , V_142 , V_65 ) ;
if ( F_59 ( V_13 ) )
return F_60 ( V_13 ) ;
V_146 = F_61 ( F_11 () , V_147 ) ;
if ( ! V_146 ) {
V_115 = - V_148 ;
goto V_98;
}
V_115 = F_50 ( V_13 , V_146 , V_65 ,
F_62 ( F_63 ( V_145 ) . V_13 ) ,
F_63 ( V_145 ) . V_66 ,
V_74 -> V_149 , 0 , V_74 ,
F_64 ( V_145 , V_150 ) ) ;
if ( V_115 < 0 ) {
F_65 ( V_115 == - V_80 ) ;
F_66 ( V_146 ) ;
goto V_98;
}
V_115 = F_67 ( V_140 -> V_151 , V_146 , F_63 ( V_145 ) . V_66 ,
V_152 ) ;
if ( V_115 > 0 )
V_115 = 0 ;
V_98:
if ( V_13 )
F_56 ( V_13 ) ;
return V_115 ;
}
static int F_68 ( int V_153 , struct V_39 * V_145 ,
const struct V_69 * V_74 ,
const struct V_64 * V_65 )
{
const struct V_1 * V_9 ;
int V_115 ;
V_9 = F_1 ( V_65 -> V_78 ) ;
if ( F_59 ( V_9 ) )
V_115 = F_60 ( V_9 ) ;
else if ( V_153 == V_154 )
V_115 = V_9 -> V_155 ( V_145 , V_74 , V_65 ) ;
else if ( V_153 == V_156 && V_9 -> V_157 )
V_115 = V_9 -> V_157 ( V_145 , V_65 ) ;
else
V_115 = - V_158 ;
F_5 ( V_9 ) ;
return V_115 ;
}
static int F_69 ( const T_3 * V_159 , const T_3 * V_160 , int V_161 )
{
int V_162 = V_161 >> 5 ;
V_161 &= 0x1f ;
if ( V_162 ) {
if ( memcmp ( V_159 , V_160 , V_162 << 2 ) )
return 0 ;
}
if ( V_161 ) {
T_3 V_163 , V_164 ;
T_3 V_165 ;
V_163 = V_159 [ V_162 ] ;
V_164 = V_160 [ V_162 ] ;
V_165 = F_70 ( ( 0xffffffff ) << ( 32 - V_161 ) ) ;
if ( ( V_163 ^ V_164 ) & V_165 )
return 0 ;
}
return 1 ;
}
static int F_71 ( const struct V_75 * V_166 ,
const struct V_167 * V_168 )
{
const void * V_169 = F_34 ( V_166 ) ;
int V_170 = F_72 ( V_166 ) ;
while ( V_170 > 0 ) {
int V_171 = 1 ;
const struct V_172 * V_173 = V_169 ;
switch ( V_173 -> V_174 ) {
case V_175 :
break;
case V_176 :
V_171 = 0 ;
break;
case V_177 :
V_171 = V_168 -> V_178 >= V_173 [ 1 ] . V_179 ;
break;
case V_180 :
V_171 = V_168 -> V_178 <= V_173 [ 1 ] . V_179 ;
break;
case V_181 :
V_171 = V_168 -> V_182 >= V_173 [ 1 ] . V_179 ;
break;
case V_183 :
V_171 = V_168 -> V_182 <= V_173 [ 1 ] . V_179 ;
break;
case V_184 :
V_171 = ! ( V_168 -> V_185 & V_186 ) ;
break;
case V_187 :
case V_188 : {
const struct V_189 * V_190 ;
const T_3 * V_191 ;
V_190 = ( const struct V_189 * ) ( V_173 + 1 ) ;
if ( V_190 -> V_192 != - 1 &&
V_190 -> V_192 != ( V_173 -> V_174 == V_187 ?
V_168 -> V_178 : V_168 -> V_182 ) ) {
V_171 = 0 ;
break;
}
if ( V_173 -> V_174 == V_187 )
V_191 = V_168 -> V_193 ;
else
V_191 = V_168 -> V_194 ;
if ( V_190 -> V_195 != V_196 &&
V_190 -> V_195 != V_168 -> V_195 ) {
if ( V_168 -> V_195 == V_25 &&
V_190 -> V_195 == V_6 ) {
if ( V_191 [ 0 ] == 0 && V_191 [ 1 ] == 0 &&
V_191 [ 2 ] == F_70 ( 0xffff ) &&
F_69 ( V_191 + 3 ,
V_190 -> V_191 ,
V_190 -> V_197 ) )
break;
}
V_171 = 0 ;
break;
}
if ( V_190 -> V_197 == 0 )
break;
if ( F_69 ( V_191 , V_190 -> V_191 ,
V_190 -> V_197 ) )
break;
V_171 = 0 ;
break;
}
case V_198 : {
V_36 V_199 ;
V_199 = * ( ( const V_36 * ) ( V_173 + 1 ) ) ;
if ( V_199 != V_168 -> V_199 )
V_171 = 0 ;
break;
}
case V_200 : {
struct V_201 * V_190 ;
V_190 = (struct V_201 * ) ( V_173 + 1 ) ;
if ( ( V_168 -> V_202 & V_190 -> V_165 ) != V_190 -> V_202 )
V_171 = 0 ;
break;
}
}
if ( V_171 ) {
V_170 -= V_173 -> V_171 ;
V_169 += V_173 -> V_171 ;
} else {
V_170 -= V_173 -> V_179 ;
V_169 += V_173 -> V_179 ;
}
}
return V_170 == 0 ;
}
static void F_73 ( struct V_167 * V_168 ,
const struct V_12 * V_13 )
{
#if F_10 ( V_24 )
if ( V_13 -> V_15 == V_25 ) {
V_168 -> V_193 = V_13 -> V_28 . V_203 ;
V_168 -> V_194 = V_13 -> V_30 . V_203 ;
} else
#endif
{
V_168 -> V_193 = & V_13 -> V_31 ;
V_168 -> V_194 = & V_13 -> V_32 ;
}
}
int F_74 ( const struct V_75 * V_169 , struct V_12 * V_13 )
{
struct V_45 * V_46 = F_14 ( V_13 ) ;
struct V_167 V_168 ;
if ( ! V_169 )
return 1 ;
V_168 . V_195 = V_13 -> V_15 ;
F_73 ( & V_168 , V_13 ) ;
V_168 . V_178 = V_46 -> V_204 ;
V_168 . V_182 = F_75 ( V_46 -> V_205 ) ;
V_168 . V_199 = V_13 -> V_22 ;
V_168 . V_185 = F_26 ( V_13 ) ? V_13 -> V_206 : 0 ;
if ( F_26 ( V_13 ) )
V_168 . V_202 = V_13 -> V_59 ;
else if ( V_13 -> V_54 == V_139 )
V_168 . V_202 = F_49 ( F_46 ( V_13 ) ) -> V_138 ;
else
V_168 . V_202 = 0 ;
return F_71 ( V_169 , & V_168 ) ;
}
static int F_76 ( const void * V_169 , int V_170 , int V_207 )
{
while ( V_170 >= 0 ) {
const struct V_172 * V_173 = V_169 ;
if ( V_207 > V_170 )
return 0 ;
if ( V_207 == V_170 )
return 1 ;
if ( V_173 -> V_171 < 4 || V_173 -> V_171 & 3 )
return 0 ;
V_170 -= V_173 -> V_171 ;
V_169 += V_173 -> V_171 ;
}
return 0 ;
}
static bool F_77 ( const struct V_172 * V_173 , int V_170 ,
int * V_208 )
{
* V_208 += sizeof( V_36 ) ;
if ( V_170 < * V_208 )
return false ;
return true ;
}
static bool F_78 ( const struct V_172 * V_173 , int V_170 ,
int * V_208 )
{
struct V_189 * V_190 ;
int V_209 ;
* V_208 += sizeof( struct V_189 ) ;
if ( V_170 < * V_208 )
return false ;
V_190 = (struct V_189 * ) ( V_173 + 1 ) ;
switch ( V_190 -> V_195 ) {
case V_196 :
V_209 = 0 ;
break;
case V_6 :
V_209 = sizeof( struct V_210 ) ;
break;
case V_25 :
V_209 = sizeof( struct V_26 ) ;
break;
default:
return false ;
}
* V_208 += V_209 ;
if ( V_170 < * V_208 )
return false ;
if ( V_190 -> V_197 > 8 * V_209 )
return false ;
return true ;
}
static bool F_79 ( const struct V_172 * V_173 ,
int V_170 , int * V_208 )
{
* V_208 += sizeof( struct V_172 ) ;
if ( V_170 < * V_208 )
return false ;
return true ;
}
static bool F_80 ( const struct V_172 * V_173 , int V_170 ,
int * V_208 )
{
* V_208 += sizeof( struct V_201 ) ;
return V_170 >= * V_208 ;
}
static int F_81 ( const struct V_75 * V_76 ,
const struct V_39 * V_40 )
{
bool V_44 = F_64 ( V_40 , V_150 ) ;
const void * V_211 , * V_169 ;
int V_212 , V_170 ;
if ( ! V_76 || F_72 ( V_76 ) < sizeof( struct V_172 ) )
return - V_144 ;
V_211 = V_169 = F_34 ( V_76 ) ;
V_170 = V_212 = F_72 ( V_76 ) ;
while ( V_170 > 0 ) {
int V_208 = sizeof( struct V_172 ) ;
const struct V_172 * V_173 = V_169 ;
switch ( V_173 -> V_174 ) {
case V_187 :
case V_188 :
if ( ! F_78 ( V_169 , V_170 , & V_208 ) )
return - V_144 ;
break;
case V_198 :
if ( ! F_77 ( V_169 , V_170 , & V_208 ) )
return - V_144 ;
break;
case V_177 :
case V_180 :
case V_181 :
case V_183 :
if ( ! F_79 ( V_169 , V_170 , & V_208 ) )
return - V_144 ;
break;
case V_200 :
if ( ! V_44 )
return - V_213 ;
if ( ! F_80 ( V_169 , V_170 , & V_208 ) )
return - V_144 ;
break;
case V_184 :
case V_176 :
case V_175 :
break;
default:
return - V_144 ;
}
if ( V_173 -> V_174 != V_175 ) {
if ( V_173 -> V_179 < V_208 || V_173 -> V_179 > V_170 + 4 || V_173 -> V_179 & 3 )
return - V_144 ;
if ( V_173 -> V_179 < V_170 &&
! F_76 ( V_211 , V_212 , V_170 - V_173 -> V_179 ) )
return - V_144 ;
}
if ( V_173 -> V_171 < V_208 || V_173 -> V_171 > V_170 + 4 || V_173 -> V_171 & 3 )
return - V_144 ;
V_169 += V_173 -> V_171 ;
V_170 -= V_173 -> V_171 ;
}
return V_170 == 0 ? 0 : - V_144 ;
}
static int F_82 ( struct V_12 * V_13 ,
struct V_39 * V_40 ,
struct V_214 * V_215 ,
const struct V_64 * V_11 ,
const struct V_75 * V_169 ,
bool V_44 )
{
if ( ! F_74 ( V_169 , V_13 ) )
return 0 ;
return F_41 ( V_13 , V_40 , V_11 ,
F_62 ( F_63 ( V_215 -> V_40 ) . V_13 ) ,
F_63 ( V_215 -> V_40 ) . V_66 ,
V_215 -> V_74 -> V_149 , V_216 , V_215 -> V_74 ,
V_44 ) ;
}
static void F_83 ( void )
{
F_47 ( F_48 ( struct V_122 , V_217 ) !=
F_48 ( struct V_12 , V_15 ) ) ;
F_47 ( F_48 ( struct V_122 , V_218 ) !=
F_48 ( struct V_45 , V_204 ) ) ;
F_47 ( F_48 ( struct V_122 , V_219 ) !=
F_48 ( struct V_45 , V_205 ) ) ;
F_47 ( F_48 ( struct V_122 , V_220 ) !=
F_48 ( struct V_45 , V_221 ) ) ;
F_47 ( F_48 ( struct V_122 , V_222 ) !=
F_48 ( struct V_45 , V_223 ) ) ;
#if F_10 ( V_24 )
F_47 ( F_48 ( struct V_122 , V_224 ) !=
F_48 ( struct V_12 , V_28 ) ) ;
F_47 ( F_48 ( struct V_122 , V_225 ) !=
F_48 ( struct V_12 , V_30 ) ) ;
#endif
}
void F_84 ( struct V_141 * V_142 , struct V_39 * V_40 ,
struct V_214 * V_215 ,
const struct V_64 * V_11 , struct V_75 * V_169 )
{
bool V_44 = F_64 ( V_215 -> V_40 , V_150 ) ;
struct V_140 * V_140 = F_58 ( V_40 -> V_13 ) ;
V_36 V_226 = V_11 -> V_226 ;
int V_227 , V_228 , V_229 , V_230 ;
struct V_12 * V_13 ;
if ( V_226 & V_231 )
V_226 |= V_232 ;
V_229 = V_215 -> args [ 1 ] ;
V_230 = V_228 = V_215 -> args [ 2 ] ;
if ( V_215 -> args [ 0 ] == 0 ) {
if ( ! ( V_226 & V_55 ) || V_11 -> V_16 . V_19 )
goto V_233;
for ( V_227 = V_229 ; V_227 < V_234 ; V_227 ++ ) {
struct V_235 * V_236 ;
V_228 = 0 ;
V_236 = & V_142 -> V_237 [ V_227 ] ;
F_85 ( & V_236 -> V_238 ) ;
F_86 (sk, &ilb->head) {
struct V_45 * V_46 = F_14 ( V_13 ) ;
if ( ! F_87 ( F_58 ( V_13 ) , V_140 ) )
continue;
if ( V_228 < V_230 ) {
V_228 ++ ;
continue;
}
if ( V_11 -> V_143 != V_196 &&
V_13 -> V_15 != V_11 -> V_143 )
goto V_239;
if ( V_11 -> V_16 . V_17 != V_46 -> V_240 &&
V_11 -> V_16 . V_17 )
goto V_239;
if ( F_82 ( V_13 , V_40 , V_215 , V_11 ,
V_169 , V_44 ) < 0 ) {
F_88 ( & V_236 -> V_238 ) ;
goto V_241;
}
V_239:
++ V_228 ;
}
F_88 ( & V_236 -> V_238 ) ;
V_230 = 0 ;
}
V_233:
V_215 -> args [ 0 ] = 1 ;
V_229 = V_228 = V_230 = 0 ;
}
if ( ! ( V_226 & ~ V_55 ) )
goto V_98;
#define F_89 16
for ( V_227 = V_229 ; V_227 <= V_142 -> V_242 ; V_227 ++ ) {
struct V_243 * V_244 = & V_142 -> V_245 [ V_227 ] ;
T_4 * V_238 = F_90 ( V_142 , V_227 ) ;
struct V_246 * V_247 ;
struct V_12 * V_248 [ F_89 ] ;
int V_249 [ F_89 ] ;
int V_250 , V_251 , V_252 ;
if ( F_91 ( & V_244 -> V_253 ) )
continue;
if ( V_227 > V_229 )
V_230 = 0 ;
V_254:
V_228 = 0 ;
V_251 = 0 ;
F_92 ( V_238 ) ;
F_93 (sk, node, &head->chain) {
int V_255 ;
if ( ! F_87 ( F_58 ( V_13 ) , V_140 ) )
continue;
if ( V_228 < V_230 )
goto V_256;
V_255 = ( V_13 -> V_54 == V_118 ) ?
F_44 ( V_13 ) -> V_127 : V_13 -> V_54 ;
if ( ! ( V_226 & ( 1 << V_255 ) ) )
goto V_256;
if ( V_11 -> V_143 != V_196 &&
V_13 -> V_15 != V_11 -> V_143 )
goto V_256;
if ( V_11 -> V_16 . V_17 != F_8 ( V_13 -> V_18 ) &&
V_11 -> V_16 . V_17 )
goto V_256;
if ( V_11 -> V_16 . V_19 != V_13 -> V_20 &&
V_11 -> V_16 . V_19 )
goto V_256;
F_83 () ;
if ( ! F_74 ( V_169 , V_13 ) )
goto V_256;
F_94 ( V_13 ) ;
V_249 [ V_251 ] = V_228 ;
V_248 [ V_251 ] = V_13 ;
if ( ++ V_251 == F_89 )
break;
V_256:
++ V_228 ;
}
F_95 ( V_238 ) ;
V_252 = 0 ;
for ( V_250 = 0 ; V_250 < V_251 ; V_250 ++ ) {
if ( V_252 >= 0 ) {
V_252 = F_50 ( V_248 [ V_250 ] , V_40 , V_11 ,
F_62 ( F_63 ( V_215 -> V_40 ) . V_13 ) ,
F_63 ( V_215 -> V_40 ) . V_66 ,
V_215 -> V_74 -> V_149 , V_216 ,
V_215 -> V_74 , V_44 ) ;
if ( V_252 < 0 )
V_228 = V_249 [ V_250 ] ;
}
F_56 ( V_248 [ V_250 ] ) ;
}
if ( V_252 < 0 )
break;
F_96 () ;
if ( V_251 == F_89 ) {
V_230 = V_228 + 1 ;
goto V_254;
}
}
V_241:
V_215 -> args [ 1 ] = V_227 ;
V_215 -> args [ 2 ] = V_228 ;
V_98:
;
}
static int F_97 ( struct V_39 * V_40 , struct V_214 * V_215 ,
const struct V_64 * V_11 ,
struct V_75 * V_169 )
{
const struct V_1 * V_9 ;
int V_115 = 0 ;
V_9 = F_1 ( V_11 -> V_78 ) ;
if ( ! F_59 ( V_9 ) )
V_9 -> V_257 ( V_40 , V_215 , V_11 , V_169 ) ;
else
V_115 = F_60 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_115 ? : V_40 -> V_170 ;
}
static int F_98 ( struct V_39 * V_40 , struct V_214 * V_215 )
{
int V_258 = sizeof( struct V_64 ) ;
struct V_75 * V_169 = NULL ;
if ( F_99 ( V_215 -> V_74 , V_258 ) )
V_169 = F_100 ( V_215 -> V_74 , V_258 , V_259 ) ;
return F_97 ( V_40 , V_215 , F_25 ( V_215 -> V_74 ) , V_169 ) ;
}
static int F_101 ( int type )
{
switch ( type ) {
case V_260 :
return V_261 ;
case V_262 :
return V_263 ;
default:
return 0 ;
}
}
static int F_102 ( struct V_39 * V_40 ,
struct V_214 * V_215 )
{
struct V_264 * V_265 = F_25 ( V_215 -> V_74 ) ;
int V_258 = sizeof( struct V_264 ) ;
struct V_64 V_65 ;
struct V_75 * V_169 = NULL ;
V_65 . V_143 = V_196 ;
V_65 . V_78 = F_101 ( V_215 -> V_74 -> V_79 ) ;
V_65 . V_73 = V_265 -> V_73 ;
V_65 . V_226 = V_265 -> V_226 ;
V_65 . V_16 = V_265 -> V_16 ;
if ( F_99 ( V_215 -> V_74 , V_258 ) )
V_169 = F_100 ( V_215 -> V_74 , V_258 , V_259 ) ;
return F_97 ( V_40 , V_215 , & V_65 , V_169 ) ;
}
static int F_103 ( struct V_39 * V_145 ,
const struct V_69 * V_74 )
{
struct V_264 * V_265 = F_25 ( V_74 ) ;
struct V_64 V_65 ;
V_65 . V_143 = V_265 -> V_14 ;
V_65 . V_78 = F_101 ( V_74 -> V_79 ) ;
V_65 . V_73 = V_265 -> V_73 ;
V_65 . V_226 = V_265 -> V_226 ;
V_65 . V_16 = V_265 -> V_16 ;
return F_68 ( V_154 , V_145 , V_74 , & V_65 ) ;
}
static int F_104 ( struct V_39 * V_40 , struct V_69 * V_74 )
{
int V_258 = sizeof( struct V_264 ) ;
struct V_140 * V_140 = F_58 ( V_40 -> V_13 ) ;
if ( V_74 -> V_79 >= V_266 ||
F_105 ( V_74 ) < V_258 )
return - V_144 ;
if ( V_74 -> V_68 & V_267 ) {
if ( F_99 ( V_74 , V_258 ) ) {
struct V_75 * V_76 ;
int V_115 ;
V_76 = F_100 ( V_74 , V_258 ,
V_259 ) ;
V_115 = F_81 ( V_76 , V_40 ) ;
if ( V_115 )
return V_115 ;
}
{
struct V_268 V_269 = {
. V_257 = F_102 ,
} ;
return F_106 ( V_140 -> V_151 , V_40 , V_74 , & V_269 ) ;
}
}
return F_103 ( V_40 , V_74 ) ;
}
static int F_107 ( struct V_39 * V_40 , struct V_69 * V_270 )
{
int V_258 = sizeof( struct V_64 ) ;
struct V_140 * V_140 = F_58 ( V_40 -> V_13 ) ;
if ( F_105 ( V_270 ) < V_258 )
return - V_144 ;
if ( V_270 -> V_79 == V_154 &&
V_270 -> V_68 & V_267 ) {
if ( F_99 ( V_270 , V_258 ) ) {
struct V_75 * V_76 ;
int V_115 ;
V_76 = F_100 ( V_270 , V_258 ,
V_259 ) ;
V_115 = F_81 ( V_76 , V_40 ) ;
if ( V_115 )
return V_115 ;
}
{
struct V_268 V_269 = {
. V_257 = F_98 ,
} ;
return F_106 ( V_140 -> V_151 , V_40 , V_270 , & V_269 ) ;
}
}
return F_68 ( V_270 -> V_79 , V_40 , V_270 , F_25 ( V_270 ) ) ;
}
static
int F_108 ( struct V_39 * V_40 , struct V_12 * V_13 )
{
const struct V_1 * V_9 ;
struct V_69 * V_74 ;
struct V_75 * V_76 ;
struct V_10 * V_11 ;
void * V_77 = NULL ;
int V_115 = 0 ;
V_74 = F_24 ( V_40 , 0 , 0 , V_154 , sizeof( * V_11 ) , 0 ) ;
if ( ! V_74 )
return - V_148 ;
V_11 = F_25 ( V_74 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_7 ( V_11 , V_13 ) ;
if ( V_13 -> V_93 == V_271 || V_13 -> V_93 == V_272 )
V_11 -> V_16 . V_17 = F_14 ( V_13 ) -> V_240 ;
V_11 -> V_81 = V_13 -> V_54 ;
if ( ( V_115 = F_15 ( V_40 , V_95 , V_13 -> V_96 ) ) ) {
F_40 ( V_40 , V_74 ) ;
return V_115 ;
}
V_9 = F_1 ( V_13 -> V_96 ) ;
if ( F_59 ( V_9 ) ) {
F_5 ( V_9 ) ;
F_40 ( V_40 , V_74 ) ;
return F_60 ( V_9 ) ;
}
V_76 = V_9 -> V_112
? F_33 ( V_40 , V_111 ,
V_9 -> V_112 ,
V_113 )
: NULL ;
if ( V_76 )
V_77 = F_34 ( V_76 ) ;
V_9 -> V_97 ( V_13 , V_11 , V_77 ) ;
F_5 ( V_9 ) ;
F_39 ( V_40 , V_74 ) ;
return 0 ;
}
int F_109 ( const struct V_1 * V_270 )
{
const T_5 type = V_270 -> V_273 ;
int V_115 = - V_144 ;
if ( type >= V_274 )
goto V_98;
F_3 ( & V_7 ) ;
V_115 = - V_275 ;
if ( ! V_3 [ type ] ) {
V_3 [ type ] = V_270 ;
V_115 = 0 ;
}
F_6 ( & V_7 ) ;
V_98:
return V_115 ;
}
void F_110 ( const struct V_1 * V_270 )
{
const T_5 type = V_270 -> V_273 ;
if ( type >= V_274 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_6 F_111 ( void )
{
const int V_276 = ( V_274 *
sizeof( struct V_1 * ) ) ;
int V_115 = - V_148 ;
V_3 = F_112 ( V_276 , V_147 ) ;
if ( ! V_3 )
goto V_98;
V_115 = F_113 ( & V_1 ) ;
if ( V_115 )
goto V_277;
V_115 = F_113 ( & V_278 ) ;
if ( V_115 )
goto V_279;
F_114 ( F_104 ) ;
V_98:
return V_115 ;
V_279:
F_115 ( & V_1 ) ;
V_277:
F_116 ( V_3 ) ;
goto V_98;
}
static void T_7 F_117 ( void )
{
F_115 ( & V_278 ) ;
F_115 ( & V_1 ) ;
F_118 ( F_104 ) ;
F_116 ( V_3 ) ;
}
