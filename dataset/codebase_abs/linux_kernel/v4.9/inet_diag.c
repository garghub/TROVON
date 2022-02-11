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
if ( ! V_63 ) {
V_9 -> V_93 ( V_13 , V_11 , NULL ) ;
goto V_94;
}
if ( V_63 -> V_95 == V_96 ||
V_63 -> V_95 == V_97 ||
V_63 -> V_95 == V_98 ) {
V_11 -> V_82 = 1 ;
V_11 -> V_83 = V_63 -> V_99 ;
V_11 -> V_100 =
F_31 ( V_63 -> V_101 - V_102 ) ;
} else if ( V_63 -> V_95 == V_103 ) {
V_11 -> V_82 = 4 ;
V_11 -> V_83 = V_63 -> V_104 ;
V_11 -> V_100 =
F_31 ( V_63 -> V_101 - V_102 ) ;
} else if ( F_32 ( & V_13 -> V_105 ) ) {
V_11 -> V_82 = 2 ;
V_11 -> V_83 = V_63 -> V_104 ;
V_11 -> V_100 =
F_31 ( V_13 -> V_105 . V_106 - V_102 ) ;
} else {
V_11 -> V_82 = 0 ;
V_11 -> V_100 = 0 ;
}
if ( ( V_41 & ( 1 << ( V_107 - 1 ) ) ) && V_9 -> V_108 ) {
V_76 = F_33 ( V_40 , V_107 ,
V_9 -> V_108 ,
V_109 ) ;
if ( ! V_76 )
goto V_49;
V_77 = F_34 ( V_76 ) ;
}
if ( V_41 & ( 1 << ( V_110 - 1 ) ) ) {
int V_111 = 0 ;
F_35 () ;
V_72 = F_36 ( V_63 -> V_112 ) ;
if ( V_72 )
V_111 = F_37 ( V_40 , V_110 , V_72 -> V_113 ) ;
F_38 () ;
if ( V_111 < 0 )
goto V_49;
}
V_9 -> V_93 ( V_13 , V_11 , V_77 ) ;
if ( V_13 -> V_54 < V_114 ) {
union V_115 V_77 ;
T_1 V_116 = 0 ;
int V_76 ;
F_35 () ;
V_72 = F_36 ( V_63 -> V_112 ) ;
if ( V_72 && V_72 -> V_117 )
V_116 = V_72 -> V_117 ( V_13 , V_41 , & V_76 , & V_77 ) ;
F_38 () ;
if ( V_116 && F_29 ( V_40 , V_76 , V_116 , & V_77 ) < 0 )
goto V_49;
}
V_94:
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
struct V_118 * V_119 = F_44 ( V_13 ) ;
struct V_10 * V_11 ;
struct V_69 * V_74 ;
long V_120 ;
V_74 = F_24 ( V_40 , V_66 , V_67 , V_70 -> V_79 , sizeof( * V_11 ) ,
V_68 ) ;
if ( ! V_74 )
return - V_80 ;
V_11 = F_25 ( V_74 ) ;
F_23 ( V_119 -> V_121 != V_114 ) ;
V_120 = V_119 -> V_122 . V_106 - V_102 ;
if ( V_120 < 0 )
V_120 = 0 ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_83 = 0 ;
V_11 -> V_81 = V_119 -> V_123 ;
V_11 -> V_82 = 3 ;
V_11 -> V_100 = F_31 ( V_120 ) ;
V_11 -> V_124 = 0 ;
V_11 -> V_125 = 0 ;
V_11 -> V_60 = 0 ;
V_11 -> V_61 = 0 ;
F_39 ( V_40 , V_74 ) ;
return 0 ;
}
static int F_45 ( struct V_12 * V_13 , struct V_39 * V_40 ,
V_36 V_66 , V_36 V_67 , T_2 V_68 ,
const struct V_69 * V_70 , bool V_44 )
{
struct V_126 * V_127 = F_46 ( V_13 ) ;
struct V_10 * V_11 ;
struct V_69 * V_74 ;
long V_120 ;
V_74 = F_24 ( V_40 , V_66 , V_67 , V_70 -> V_79 , sizeof( * V_11 ) ,
V_68 ) ;
if ( ! V_74 )
return - V_80 ;
V_11 = F_25 ( V_74 ) ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_81 = V_128 ;
V_11 -> V_82 = 1 ;
V_11 -> V_83 = V_127 -> V_129 ;
F_47 ( F_48 ( struct V_130 , V_131 ) !=
F_48 ( struct V_12 , V_132 ) ) ;
V_120 = F_46 ( V_13 ) -> V_133 . V_106 - V_102 ;
V_11 -> V_100 = ( V_120 >= 0 ) ? F_31 ( V_120 ) : 0 ;
V_11 -> V_124 = 0 ;
V_11 -> V_125 = 0 ;
V_11 -> V_60 = 0 ;
V_11 -> V_61 = 0 ;
if ( V_44 && F_18 ( V_40 , V_58 ,
F_49 ( V_127 ) -> V_134 ) )
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
if ( V_13 -> V_54 == V_114 )
return F_43 ( V_13 , V_40 , V_66 , V_67 ,
V_68 , V_70 ) ;
if ( V_13 -> V_54 == V_135 )
return F_45 ( V_13 , V_40 , V_66 , V_67 ,
V_68 , V_70 , V_44 ) ;
return F_41 ( V_13 , V_40 , V_11 , V_43 , V_66 , V_67 ,
V_68 , V_70 , V_44 ) ;
}
struct V_12 * F_51 ( struct V_136 * V_136 ,
struct V_137 * V_138 ,
const struct V_64 * V_65 )
{
struct V_12 * V_13 ;
F_35 () ;
if ( V_65 -> V_139 == V_6 )
V_13 = F_52 ( V_136 , V_138 , NULL , 0 , V_65 -> V_16 . V_29 [ 0 ] ,
V_65 -> V_16 . V_19 , V_65 -> V_16 . V_27 [ 0 ] ,
V_65 -> V_16 . V_17 , V_65 -> V_16 . V_21 ) ;
#if F_10 ( V_24 )
else if ( V_65 -> V_139 == V_25 ) {
if ( F_53 ( (struct V_26 * ) V_65 -> V_16 . V_29 ) &&
F_53 ( (struct V_26 * ) V_65 -> V_16 . V_27 ) )
V_13 = F_52 ( V_136 , V_138 , NULL , 0 , V_65 -> V_16 . V_29 [ 3 ] ,
V_65 -> V_16 . V_19 , V_65 -> V_16 . V_27 [ 3 ] ,
V_65 -> V_16 . V_17 , V_65 -> V_16 . V_21 ) ;
else
V_13 = F_54 ( V_136 , V_138 , NULL , 0 ,
(struct V_26 * ) V_65 -> V_16 . V_29 ,
V_65 -> V_16 . V_19 ,
(struct V_26 * ) V_65 -> V_16 . V_27 ,
V_65 -> V_16 . V_17 ,
V_65 -> V_16 . V_21 ) ;
}
#endif
else {
F_38 () ;
return F_4 ( - V_140 ) ;
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
int F_57 ( struct V_137 * V_138 ,
struct V_39 * V_141 ,
const struct V_69 * V_74 ,
const struct V_64 * V_65 )
{
struct V_136 * V_136 = F_58 ( V_141 -> V_13 ) ;
struct V_39 * V_142 ;
struct V_12 * V_13 ;
int V_111 ;
V_13 = F_51 ( V_136 , V_138 , V_65 ) ;
if ( F_59 ( V_13 ) )
return F_60 ( V_13 ) ;
V_142 = F_61 ( F_11 () , V_143 ) ;
if ( ! V_142 ) {
V_111 = - V_144 ;
goto V_94;
}
V_111 = F_50 ( V_13 , V_142 , V_65 ,
F_62 ( F_63 ( V_141 ) . V_13 ) ,
F_63 ( V_141 ) . V_66 ,
V_74 -> V_145 , 0 , V_74 ,
F_64 ( V_141 , V_146 ) ) ;
if ( V_111 < 0 ) {
F_65 ( V_111 == - V_80 ) ;
F_66 ( V_142 ) ;
goto V_94;
}
V_111 = F_67 ( V_136 -> V_147 , V_142 , F_63 ( V_141 ) . V_66 ,
V_148 ) ;
if ( V_111 > 0 )
V_111 = 0 ;
V_94:
if ( V_13 )
F_56 ( V_13 ) ;
return V_111 ;
}
static int F_68 ( int V_149 , struct V_39 * V_141 ,
const struct V_69 * V_74 ,
const struct V_64 * V_65 )
{
const struct V_1 * V_9 ;
int V_111 ;
V_9 = F_1 ( V_65 -> V_78 ) ;
if ( F_59 ( V_9 ) )
V_111 = F_60 ( V_9 ) ;
else if ( V_149 == V_150 )
V_111 = V_9 -> V_151 ( V_141 , V_74 , V_65 ) ;
else if ( V_149 == V_152 && V_9 -> V_153 )
V_111 = V_9 -> V_153 ( V_141 , V_65 ) ;
else
V_111 = - V_154 ;
F_5 ( V_9 ) ;
return V_111 ;
}
static int F_69 ( const T_3 * V_155 , const T_3 * V_156 , int V_157 )
{
int V_158 = V_157 >> 5 ;
V_157 &= 0x1f ;
if ( V_158 ) {
if ( memcmp ( V_155 , V_156 , V_158 << 2 ) )
return 0 ;
}
if ( V_157 ) {
T_3 V_159 , V_160 ;
T_3 V_161 ;
V_159 = V_155 [ V_158 ] ;
V_160 = V_156 [ V_158 ] ;
V_161 = F_70 ( ( 0xffffffff ) << ( 32 - V_157 ) ) ;
if ( ( V_159 ^ V_160 ) & V_161 )
return 0 ;
}
return 1 ;
}
static int F_71 ( const struct V_75 * V_162 ,
const struct V_163 * V_164 )
{
const void * V_165 = F_34 ( V_162 ) ;
int V_166 = F_72 ( V_162 ) ;
while ( V_166 > 0 ) {
int V_167 = 1 ;
const struct V_168 * V_169 = V_165 ;
switch ( V_169 -> V_170 ) {
case V_171 :
break;
case V_172 :
V_167 = 0 ;
break;
case V_173 :
V_167 = V_164 -> V_174 >= V_169 [ 1 ] . V_175 ;
break;
case V_176 :
V_167 = V_164 -> V_174 <= V_169 [ 1 ] . V_175 ;
break;
case V_177 :
V_167 = V_164 -> V_178 >= V_169 [ 1 ] . V_175 ;
break;
case V_179 :
V_167 = V_164 -> V_178 <= V_169 [ 1 ] . V_175 ;
break;
case V_180 :
V_167 = ! ( V_164 -> V_181 & V_182 ) ;
break;
case V_183 :
case V_184 : {
const struct V_185 * V_186 ;
const T_3 * V_187 ;
V_186 = ( const struct V_185 * ) ( V_169 + 1 ) ;
if ( V_186 -> V_188 != - 1 &&
V_186 -> V_188 != ( V_169 -> V_170 == V_183 ?
V_164 -> V_174 : V_164 -> V_178 ) ) {
V_167 = 0 ;
break;
}
if ( V_169 -> V_170 == V_183 )
V_187 = V_164 -> V_189 ;
else
V_187 = V_164 -> V_190 ;
if ( V_186 -> V_191 != V_192 &&
V_186 -> V_191 != V_164 -> V_191 ) {
if ( V_164 -> V_191 == V_25 &&
V_186 -> V_191 == V_6 ) {
if ( V_187 [ 0 ] == 0 && V_187 [ 1 ] == 0 &&
V_187 [ 2 ] == F_70 ( 0xffff ) &&
F_69 ( V_187 + 3 ,
V_186 -> V_187 ,
V_186 -> V_193 ) )
break;
}
V_167 = 0 ;
break;
}
if ( V_186 -> V_193 == 0 )
break;
if ( F_69 ( V_187 , V_186 -> V_187 ,
V_186 -> V_193 ) )
break;
V_167 = 0 ;
break;
}
case V_194 : {
V_36 V_195 ;
V_195 = * ( ( const V_36 * ) ( V_169 + 1 ) ) ;
if ( V_195 != V_164 -> V_195 )
V_167 = 0 ;
break;
}
case V_196 : {
struct V_197 * V_186 ;
V_186 = (struct V_197 * ) ( V_169 + 1 ) ;
if ( ( V_164 -> V_198 & V_186 -> V_161 ) != V_186 -> V_198 )
V_167 = 0 ;
break;
}
}
if ( V_167 ) {
V_166 -= V_169 -> V_167 ;
V_165 += V_169 -> V_167 ;
} else {
V_166 -= V_169 -> V_175 ;
V_165 += V_169 -> V_175 ;
}
}
return V_166 == 0 ;
}
static void F_73 ( struct V_163 * V_164 ,
const struct V_12 * V_13 )
{
#if F_10 ( V_24 )
if ( V_13 -> V_15 == V_25 ) {
V_164 -> V_189 = V_13 -> V_28 . V_199 ;
V_164 -> V_190 = V_13 -> V_30 . V_199 ;
} else
#endif
{
V_164 -> V_189 = & V_13 -> V_31 ;
V_164 -> V_190 = & V_13 -> V_32 ;
}
}
int F_74 ( const struct V_75 * V_165 , struct V_12 * V_13 )
{
struct V_45 * V_46 = F_14 ( V_13 ) ;
struct V_163 V_164 ;
if ( ! V_165 )
return 1 ;
V_164 . V_191 = V_13 -> V_15 ;
F_73 ( & V_164 , V_13 ) ;
V_164 . V_174 = V_46 -> V_200 ;
V_164 . V_178 = F_75 ( V_46 -> V_201 ) ;
V_164 . V_195 = V_13 -> V_22 ;
V_164 . V_181 = F_26 ( V_13 ) ? V_13 -> V_202 : 0 ;
if ( F_26 ( V_13 ) )
V_164 . V_198 = V_13 -> V_59 ;
else if ( V_13 -> V_54 == V_135 )
V_164 . V_198 = F_49 ( F_46 ( V_13 ) ) -> V_134 ;
else
V_164 . V_198 = 0 ;
return F_71 ( V_165 , & V_164 ) ;
}
static int F_76 ( const void * V_165 , int V_166 , int V_203 )
{
while ( V_166 >= 0 ) {
const struct V_168 * V_169 = V_165 ;
if ( V_203 > V_166 )
return 0 ;
if ( V_203 == V_166 )
return 1 ;
if ( V_169 -> V_167 < 4 || V_169 -> V_167 & 3 )
return 0 ;
V_166 -= V_169 -> V_167 ;
V_165 += V_169 -> V_167 ;
}
return 0 ;
}
static bool F_77 ( const struct V_168 * V_169 , int V_166 ,
int * V_204 )
{
* V_204 += sizeof( V_36 ) ;
if ( V_166 < * V_204 )
return false ;
return true ;
}
static bool F_78 ( const struct V_168 * V_169 , int V_166 ,
int * V_204 )
{
struct V_185 * V_186 ;
int V_205 ;
* V_204 += sizeof( struct V_185 ) ;
if ( V_166 < * V_204 )
return false ;
V_186 = (struct V_185 * ) ( V_169 + 1 ) ;
switch ( V_186 -> V_191 ) {
case V_192 :
V_205 = 0 ;
break;
case V_6 :
V_205 = sizeof( struct V_206 ) ;
break;
case V_25 :
V_205 = sizeof( struct V_26 ) ;
break;
default:
return false ;
}
* V_204 += V_205 ;
if ( V_166 < * V_204 )
return false ;
if ( V_186 -> V_193 > 8 * V_205 )
return false ;
return true ;
}
static bool F_79 ( const struct V_168 * V_169 ,
int V_166 , int * V_204 )
{
* V_204 += sizeof( struct V_168 ) ;
if ( V_166 < * V_204 )
return false ;
return true ;
}
static bool F_80 ( const struct V_168 * V_169 , int V_166 ,
int * V_204 )
{
* V_204 += sizeof( struct V_197 ) ;
return V_166 >= * V_204 ;
}
static int F_81 ( const struct V_75 * V_76 ,
const struct V_39 * V_40 )
{
bool V_44 = F_64 ( V_40 , V_146 ) ;
const void * V_207 , * V_165 ;
int V_208 , V_166 ;
if ( ! V_76 || F_72 ( V_76 ) < sizeof( struct V_168 ) )
return - V_140 ;
V_207 = V_165 = F_34 ( V_76 ) ;
V_166 = V_208 = F_72 ( V_76 ) ;
while ( V_166 > 0 ) {
int V_204 = sizeof( struct V_168 ) ;
const struct V_168 * V_169 = V_165 ;
switch ( V_169 -> V_170 ) {
case V_183 :
case V_184 :
if ( ! F_78 ( V_165 , V_166 , & V_204 ) )
return - V_140 ;
break;
case V_194 :
if ( ! F_77 ( V_165 , V_166 , & V_204 ) )
return - V_140 ;
break;
case V_173 :
case V_176 :
case V_177 :
case V_179 :
if ( ! F_79 ( V_165 , V_166 , & V_204 ) )
return - V_140 ;
break;
case V_196 :
if ( ! V_44 )
return - V_209 ;
if ( ! F_80 ( V_165 , V_166 , & V_204 ) )
return - V_140 ;
break;
case V_180 :
case V_172 :
case V_171 :
break;
default:
return - V_140 ;
}
if ( V_169 -> V_170 != V_171 ) {
if ( V_169 -> V_175 < V_204 || V_169 -> V_175 > V_166 + 4 || V_169 -> V_175 & 3 )
return - V_140 ;
if ( V_169 -> V_175 < V_166 &&
! F_76 ( V_207 , V_208 , V_166 - V_169 -> V_175 ) )
return - V_140 ;
}
if ( V_169 -> V_167 < V_204 || V_169 -> V_167 > V_166 + 4 || V_169 -> V_167 & 3 )
return - V_140 ;
V_165 += V_169 -> V_167 ;
V_166 -= V_169 -> V_167 ;
}
return V_166 == 0 ? 0 : - V_140 ;
}
static int F_82 ( struct V_12 * V_13 ,
struct V_39 * V_40 ,
struct V_210 * V_211 ,
const struct V_64 * V_11 ,
const struct V_75 * V_165 ,
bool V_44 )
{
if ( ! F_74 ( V_165 , V_13 ) )
return 0 ;
return F_41 ( V_13 , V_40 , V_11 ,
F_62 ( F_63 ( V_211 -> V_40 ) . V_13 ) ,
F_63 ( V_211 -> V_40 ) . V_66 ,
V_211 -> V_74 -> V_145 , V_212 , V_211 -> V_74 ,
V_44 ) ;
}
static void F_83 ( void )
{
F_47 ( F_48 ( struct V_118 , V_213 ) !=
F_48 ( struct V_12 , V_15 ) ) ;
F_47 ( F_48 ( struct V_118 , V_214 ) !=
F_48 ( struct V_45 , V_200 ) ) ;
F_47 ( F_48 ( struct V_118 , V_215 ) !=
F_48 ( struct V_45 , V_201 ) ) ;
F_47 ( F_48 ( struct V_118 , V_216 ) !=
F_48 ( struct V_45 , V_217 ) ) ;
F_47 ( F_48 ( struct V_118 , V_218 ) !=
F_48 ( struct V_45 , V_219 ) ) ;
#if F_10 ( V_24 )
F_47 ( F_48 ( struct V_118 , V_220 ) !=
F_48 ( struct V_12 , V_28 ) ) ;
F_47 ( F_48 ( struct V_118 , V_221 ) !=
F_48 ( struct V_12 , V_30 ) ) ;
#endif
}
void F_84 ( struct V_137 * V_138 , struct V_39 * V_40 ,
struct V_210 * V_211 ,
const struct V_64 * V_11 , struct V_75 * V_165 )
{
struct V_136 * V_136 = F_58 ( V_40 -> V_13 ) ;
int V_222 , V_223 , V_224 , V_225 ;
V_36 V_226 = V_11 -> V_226 ;
bool V_44 = F_64 ( V_211 -> V_40 , V_146 ) ;
if ( V_226 & V_227 )
V_226 |= V_228 ;
V_224 = V_211 -> args [ 1 ] ;
V_225 = V_223 = V_211 -> args [ 2 ] ;
if ( V_211 -> args [ 0 ] == 0 ) {
if ( ! ( V_226 & V_55 ) )
goto V_229;
for ( V_222 = V_224 ; V_222 < V_230 ; V_222 ++ ) {
struct V_231 * V_232 ;
struct V_12 * V_13 ;
V_223 = 0 ;
V_232 = & V_138 -> V_233 [ V_222 ] ;
F_85 ( & V_232 -> V_234 ) ;
F_86 (sk, &ilb->head) {
struct V_45 * V_46 = F_14 ( V_13 ) ;
if ( ! F_87 ( F_58 ( V_13 ) , V_136 ) )
continue;
if ( V_223 < V_225 ) {
V_223 ++ ;
continue;
}
if ( V_11 -> V_139 != V_192 &&
V_13 -> V_15 != V_11 -> V_139 )
goto V_235;
if ( V_11 -> V_16 . V_17 != V_46 -> V_236 &&
V_11 -> V_16 . V_17 )
goto V_235;
if ( V_11 -> V_16 . V_19 ||
V_211 -> args [ 3 ] > 0 )
goto V_235;
if ( F_82 ( V_13 , V_40 , V_211 , V_11 ,
V_165 , V_44 ) < 0 ) {
F_88 ( & V_232 -> V_234 ) ;
goto V_237;
}
V_235:
V_211 -> args [ 3 ] = 0 ;
V_211 -> args [ 4 ] = 0 ;
++ V_223 ;
}
F_88 ( & V_232 -> V_234 ) ;
V_225 = 0 ;
V_211 -> args [ 3 ] = 0 ;
V_211 -> args [ 4 ] = 0 ;
}
V_229:
V_211 -> args [ 0 ] = 1 ;
V_224 = V_223 = V_225 = 0 ;
}
if ( ! ( V_226 & ~ V_55 ) )
goto V_94;
for ( V_222 = V_224 ; V_222 <= V_138 -> V_238 ; V_222 ++ ) {
struct V_239 * V_240 = & V_138 -> V_241 [ V_222 ] ;
T_4 * V_234 = F_89 ( V_138 , V_222 ) ;
struct V_242 * V_243 ;
struct V_12 * V_13 ;
V_223 = 0 ;
if ( F_90 ( & V_240 -> V_244 ) )
continue;
if ( V_222 > V_224 )
V_225 = 0 ;
F_85 ( V_234 ) ;
F_91 (sk, node, &head->chain) {
int V_245 , V_246 ;
if ( ! F_87 ( F_58 ( V_13 ) , V_136 ) )
continue;
if ( V_223 < V_225 )
goto V_247;
V_245 = ( V_13 -> V_54 == V_114 ) ?
F_44 ( V_13 ) -> V_123 : V_13 -> V_54 ;
if ( ! ( V_226 & ( 1 << V_245 ) ) )
goto V_247;
if ( V_11 -> V_139 != V_192 &&
V_13 -> V_15 != V_11 -> V_139 )
goto V_247;
if ( V_11 -> V_16 . V_17 != F_8 ( V_13 -> V_18 ) &&
V_11 -> V_16 . V_17 )
goto V_247;
if ( V_11 -> V_16 . V_19 != V_13 -> V_20 &&
V_11 -> V_16 . V_19 )
goto V_247;
F_83 () ;
if ( ! F_74 ( V_165 , V_13 ) )
goto V_247;
V_246 = F_50 ( V_13 , V_40 , V_11 ,
F_62 ( F_63 ( V_211 -> V_40 ) . V_13 ) ,
F_63 ( V_211 -> V_40 ) . V_66 ,
V_211 -> V_74 -> V_145 , V_212 ,
V_211 -> V_74 , V_44 ) ;
if ( V_246 < 0 ) {
F_88 ( V_234 ) ;
goto V_237;
}
V_247:
++ V_223 ;
}
F_88 ( V_234 ) ;
F_92 () ;
}
V_237:
V_211 -> args [ 1 ] = V_222 ;
V_211 -> args [ 2 ] = V_223 ;
V_94:
;
}
static int F_93 ( struct V_39 * V_40 , struct V_210 * V_211 ,
const struct V_64 * V_11 ,
struct V_75 * V_165 )
{
const struct V_1 * V_9 ;
int V_111 = 0 ;
V_9 = F_1 ( V_11 -> V_78 ) ;
if ( ! F_59 ( V_9 ) )
V_9 -> V_248 ( V_40 , V_211 , V_11 , V_165 ) ;
else
V_111 = F_60 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_111 ? : V_40 -> V_166 ;
}
static int F_94 ( struct V_39 * V_40 , struct V_210 * V_211 )
{
int V_249 = sizeof( struct V_64 ) ;
struct V_75 * V_165 = NULL ;
if ( F_95 ( V_211 -> V_74 , V_249 ) )
V_165 = F_96 ( V_211 -> V_74 , V_249 , V_250 ) ;
return F_93 ( V_40 , V_211 , F_25 ( V_211 -> V_74 ) , V_165 ) ;
}
static int F_97 ( int type )
{
switch ( type ) {
case V_251 :
return V_252 ;
case V_253 :
return V_254 ;
default:
return 0 ;
}
}
static int F_98 ( struct V_39 * V_40 ,
struct V_210 * V_211 )
{
struct V_255 * V_256 = F_25 ( V_211 -> V_74 ) ;
int V_249 = sizeof( struct V_255 ) ;
struct V_64 V_65 ;
struct V_75 * V_165 = NULL ;
V_65 . V_139 = V_192 ;
V_65 . V_78 = F_97 ( V_211 -> V_74 -> V_79 ) ;
V_65 . V_73 = V_256 -> V_73 ;
V_65 . V_226 = V_256 -> V_226 ;
V_65 . V_16 = V_256 -> V_16 ;
if ( F_95 ( V_211 -> V_74 , V_249 ) )
V_165 = F_96 ( V_211 -> V_74 , V_249 , V_250 ) ;
return F_93 ( V_40 , V_211 , & V_65 , V_165 ) ;
}
static int F_99 ( struct V_39 * V_141 ,
const struct V_69 * V_74 )
{
struct V_255 * V_256 = F_25 ( V_74 ) ;
struct V_64 V_65 ;
V_65 . V_139 = V_256 -> V_14 ;
V_65 . V_78 = F_97 ( V_74 -> V_79 ) ;
V_65 . V_73 = V_256 -> V_73 ;
V_65 . V_226 = V_256 -> V_226 ;
V_65 . V_16 = V_256 -> V_16 ;
return F_68 ( V_150 , V_141 , V_74 , & V_65 ) ;
}
static int F_100 ( struct V_39 * V_40 , struct V_69 * V_74 )
{
int V_249 = sizeof( struct V_255 ) ;
struct V_136 * V_136 = F_58 ( V_40 -> V_13 ) ;
if ( V_74 -> V_79 >= V_257 ||
F_101 ( V_74 ) < V_249 )
return - V_140 ;
if ( V_74 -> V_68 & V_258 ) {
if ( F_95 ( V_74 , V_249 ) ) {
struct V_75 * V_76 ;
int V_111 ;
V_76 = F_96 ( V_74 , V_249 ,
V_250 ) ;
V_111 = F_81 ( V_76 , V_40 ) ;
if ( V_111 )
return V_111 ;
}
{
struct V_259 V_260 = {
. V_248 = F_98 ,
} ;
return F_102 ( V_136 -> V_147 , V_40 , V_74 , & V_260 ) ;
}
}
return F_99 ( V_40 , V_74 ) ;
}
static int F_103 ( struct V_39 * V_40 , struct V_69 * V_261 )
{
int V_249 = sizeof( struct V_64 ) ;
struct V_136 * V_136 = F_58 ( V_40 -> V_13 ) ;
if ( F_101 ( V_261 ) < V_249 )
return - V_140 ;
if ( V_261 -> V_79 == V_150 &&
V_261 -> V_68 & V_258 ) {
if ( F_95 ( V_261 , V_249 ) ) {
struct V_75 * V_76 ;
int V_111 ;
V_76 = F_96 ( V_261 , V_249 ,
V_250 ) ;
V_111 = F_81 ( V_76 , V_40 ) ;
if ( V_111 )
return V_111 ;
}
{
struct V_259 V_260 = {
. V_248 = F_94 ,
} ;
return F_102 ( V_136 -> V_147 , V_40 , V_261 , & V_260 ) ;
}
}
return F_68 ( V_261 -> V_79 , V_40 , V_261 , F_25 ( V_261 ) ) ;
}
static
int F_104 ( struct V_39 * V_40 , struct V_12 * V_13 )
{
const struct V_1 * V_9 ;
struct V_69 * V_74 ;
struct V_75 * V_76 ;
struct V_10 * V_11 ;
void * V_77 = NULL ;
int V_111 = 0 ;
V_74 = F_24 ( V_40 , 0 , 0 , V_150 , sizeof( * V_11 ) , 0 ) ;
if ( ! V_74 )
return - V_144 ;
V_11 = F_25 ( V_74 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_7 ( V_11 , V_13 ) ;
if ( V_13 -> V_262 == V_263 || V_13 -> V_262 == V_264 )
V_11 -> V_16 . V_17 = F_14 ( V_13 ) -> V_236 ;
V_11 -> V_81 = V_13 -> V_54 ;
if ( ( V_111 = F_15 ( V_40 , V_265 , V_13 -> V_266 ) ) ) {
F_40 ( V_40 , V_74 ) ;
return V_111 ;
}
V_9 = F_1 ( V_13 -> V_266 ) ;
if ( F_59 ( V_9 ) ) {
F_5 ( V_9 ) ;
F_40 ( V_40 , V_74 ) ;
return F_60 ( V_9 ) ;
}
V_76 = V_9 -> V_108
? F_33 ( V_40 , V_107 ,
V_9 -> V_108 ,
V_109 )
: NULL ;
if ( V_76 )
V_77 = F_34 ( V_76 ) ;
V_9 -> V_93 ( V_13 , V_11 , V_77 ) ;
F_5 ( V_9 ) ;
F_39 ( V_40 , V_74 ) ;
return 0 ;
}
int F_105 ( const struct V_1 * V_261 )
{
const T_5 type = V_261 -> V_267 ;
int V_111 = - V_140 ;
if ( type >= V_268 )
goto V_94;
F_3 ( & V_7 ) ;
V_111 = - V_269 ;
if ( ! V_3 [ type ] ) {
V_3 [ type ] = V_261 ;
V_111 = 0 ;
}
F_6 ( & V_7 ) ;
V_94:
return V_111 ;
}
void F_106 ( const struct V_1 * V_261 )
{
const T_5 type = V_261 -> V_267 ;
if ( type >= V_268 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_6 F_107 ( void )
{
const int V_270 = ( V_268 *
sizeof( struct V_1 * ) ) ;
int V_111 = - V_144 ;
V_3 = F_108 ( V_270 , V_143 ) ;
if ( ! V_3 )
goto V_94;
V_111 = F_109 ( & V_1 ) ;
if ( V_111 )
goto V_271;
V_111 = F_109 ( & V_272 ) ;
if ( V_111 )
goto V_273;
F_110 ( F_100 ) ;
V_94:
return V_111 ;
V_273:
F_111 ( & V_1 ) ;
V_271:
F_112 ( V_3 ) ;
goto V_94;
}
static void T_7 F_113 ( void )
{
F_111 ( & V_272 ) ;
F_111 ( & V_1 ) ;
F_114 ( F_100 ) ;
F_112 ( V_3 ) ;
}
