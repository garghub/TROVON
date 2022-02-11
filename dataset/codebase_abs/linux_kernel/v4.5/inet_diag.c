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
static void F_7 ( struct V_10 * V_11 , struct V_12 * V_13 )
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
+ F_12 ( sizeof( struct V_34 ) )
+ F_12 ( sizeof( struct V_10 ) )
+ F_12 ( V_35 * sizeof( V_36 ) )
+ F_12 ( V_37 )
+ F_12 ( sizeof( struct V_38 ) )
+ 64 ;
}
int F_13 ( struct V_12 * V_13 , struct V_39 * V_40 ,
struct V_41 * V_42 , const struct V_43 * V_44 ,
struct V_45 * V_46 ,
V_36 V_47 , V_36 V_48 , T_2 V_49 ,
const struct V_50 * V_51 )
{
const struct V_52 * V_53 = F_14 ( V_13 ) ;
const struct V_54 * V_55 ;
const struct V_1 * V_9 ;
int V_56 = V_44 -> V_57 ;
struct V_10 * V_11 ;
struct V_50 * V_58 ;
struct V_59 * V_60 ;
void * V_61 = NULL ;
V_9 = V_3 [ V_44 -> V_62 ] ;
F_15 ( ! V_9 ) ;
V_58 = F_16 ( V_42 , V_47 , V_48 , V_51 -> V_63 , sizeof( * V_11 ) ,
V_49 ) ;
if ( ! V_58 )
return - V_64 ;
V_11 = F_17 ( V_58 ) ;
F_15 ( ! F_18 ( V_13 ) ) ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_65 = V_13 -> V_66 ;
V_11 -> V_67 = 0 ;
V_11 -> V_68 = 0 ;
if ( F_19 ( V_42 , V_69 , V_13 -> V_70 ) )
goto V_71;
if ( V_56 & ( 1 << ( V_72 - 1 ) ) )
if ( F_19 ( V_42 , V_72 , V_53 -> V_73 ) < 0 )
goto V_71;
#if F_10 ( V_24 )
if ( V_11 -> V_14 == V_25 ) {
if ( V_56 & ( 1 << ( V_74 - 1 ) ) )
if ( F_19 ( V_42 , V_74 ,
F_20 ( V_13 ) -> V_75 ) < 0 )
goto V_71;
if ( ( ( 1 << V_13 -> V_66 ) & ( V_76 | V_77 ) ) &&
F_19 ( V_42 , V_78 , F_21 ( V_13 ) ) )
goto V_71;
}
#endif
V_11 -> V_79 = F_22 ( V_46 , F_23 ( V_13 ) ) ;
V_11 -> V_80 = F_24 ( V_13 ) ;
if ( V_56 & ( 1 << ( V_81 - 1 ) ) ) {
struct V_34 V_82 = {
. V_83 = F_25 ( V_13 ) ,
. V_84 = V_13 -> V_85 ,
. V_86 = V_13 -> V_87 ,
. V_88 = F_26 ( V_13 ) ,
} ;
if ( F_27 ( V_42 , V_81 , sizeof( V_82 ) , & V_82 ) < 0 )
goto V_71;
}
if ( V_56 & ( 1 << ( V_89 - 1 ) ) )
if ( F_28 ( V_13 , V_42 , V_89 ) )
goto V_71;
if ( ! V_40 ) {
V_9 -> V_90 ( V_13 , V_11 , NULL ) ;
goto V_91;
}
#define F_29 ( T_3 ) DIV_ROUND_UP((tmo - jiffies) * 1000, HZ)
if ( V_40 -> V_92 == V_93 ||
V_40 -> V_92 == V_94 ||
V_40 -> V_92 == V_95 ) {
V_11 -> V_67 = 1 ;
V_11 -> V_68 = V_40 -> V_96 ;
V_11 -> V_97 = F_29 ( V_40 -> V_98 ) ;
} else if ( V_40 -> V_92 == V_99 ) {
V_11 -> V_67 = 4 ;
V_11 -> V_68 = V_40 -> V_100 ;
V_11 -> V_97 = F_29 ( V_40 -> V_98 ) ;
} else if ( F_30 ( & V_13 -> V_101 ) ) {
V_11 -> V_67 = 2 ;
V_11 -> V_68 = V_40 -> V_100 ;
V_11 -> V_97 = F_29 ( V_13 -> V_101 . V_102 ) ;
} else {
V_11 -> V_67 = 0 ;
V_11 -> V_97 = 0 ;
}
#undef F_29
if ( ( V_56 & ( 1 << ( V_103 - 1 ) ) ) && V_9 -> V_104 ) {
V_60 = F_31 ( V_42 , V_103 ,
V_9 -> V_104 ) ;
if ( ! V_60 )
goto V_71;
V_61 = F_32 ( V_60 ) ;
}
if ( V_56 & ( 1 << ( V_105 - 1 ) ) ) {
int V_106 = 0 ;
F_33 () ;
V_55 = F_34 ( V_40 -> V_107 ) ;
if ( V_55 )
V_106 = F_35 ( V_42 , V_105 , V_55 -> V_108 ) ;
F_36 () ;
if ( V_106 < 0 )
goto V_71;
}
V_9 -> V_90 ( V_13 , V_11 , V_61 ) ;
if ( V_13 -> V_66 < V_109 ) {
union V_110 V_61 ;
T_1 V_111 = 0 ;
int V_60 ;
F_33 () ;
V_55 = F_34 ( V_40 -> V_107 ) ;
if ( V_55 && V_55 -> V_112 )
V_111 = V_55 -> V_112 ( V_13 , V_56 , & V_60 , & V_61 ) ;
F_36 () ;
if ( V_111 && F_27 ( V_42 , V_60 , V_111 , & V_61 ) < 0 )
goto V_71;
}
V_91:
F_37 ( V_42 , V_58 ) ;
return 0 ;
V_71:
F_38 ( V_42 , V_58 ) ;
return - V_64 ;
}
static int F_39 ( struct V_12 * V_13 ,
struct V_41 * V_42 ,
const struct V_43 * V_44 ,
struct V_45 * V_46 ,
V_36 V_47 , V_36 V_48 , T_2 V_49 ,
const struct V_50 * V_51 )
{
return F_13 ( V_13 , F_40 ( V_13 ) , V_42 , V_44 ,
V_46 , V_47 , V_48 , V_49 , V_51 ) ;
}
static int F_41 ( struct V_12 * V_13 ,
struct V_41 * V_42 ,
V_36 V_47 , V_36 V_48 , T_2 V_49 ,
const struct V_50 * V_51 )
{
struct V_113 * V_114 = F_42 ( V_13 ) ;
struct V_10 * V_11 ;
struct V_50 * V_58 ;
long T_3 ;
V_58 = F_16 ( V_42 , V_47 , V_48 , V_51 -> V_63 , sizeof( * V_11 ) ,
V_49 ) ;
if ( ! V_58 )
return - V_64 ;
V_11 = F_17 ( V_58 ) ;
F_15 ( V_114 -> V_115 != V_109 ) ;
T_3 = V_114 -> V_116 . V_102 - V_117 ;
if ( T_3 < 0 )
T_3 = 0 ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_68 = 0 ;
V_11 -> V_65 = V_114 -> V_118 ;
V_11 -> V_67 = 3 ;
V_11 -> V_97 = F_43 ( T_3 ) ;
V_11 -> V_119 = 0 ;
V_11 -> V_120 = 0 ;
V_11 -> V_79 = 0 ;
V_11 -> V_80 = 0 ;
F_37 ( V_42 , V_58 ) ;
return 0 ;
}
static int F_44 ( struct V_12 * V_13 , struct V_41 * V_42 ,
V_36 V_47 , V_36 V_48 , T_2 V_49 ,
const struct V_50 * V_51 )
{
struct V_10 * V_11 ;
struct V_50 * V_58 ;
long T_3 ;
V_58 = F_16 ( V_42 , V_47 , V_48 , V_51 -> V_63 , sizeof( * V_11 ) ,
V_49 ) ;
if ( ! V_58 )
return - V_64 ;
V_11 = F_17 ( V_58 ) ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_65 = V_121 ;
V_11 -> V_67 = 1 ;
V_11 -> V_68 = F_45 ( V_13 ) -> V_122 ;
F_46 ( F_47 ( struct V_123 , V_124 ) !=
F_47 ( struct V_12 , V_125 ) ) ;
T_3 = F_45 ( V_13 ) -> V_126 . V_102 - V_117 ;
V_11 -> V_97 = ( T_3 >= 0 ) ? F_43 ( T_3 ) : 0 ;
V_11 -> V_119 = 0 ;
V_11 -> V_120 = 0 ;
V_11 -> V_79 = 0 ;
V_11 -> V_80 = 0 ;
F_37 ( V_42 , V_58 ) ;
return 0 ;
}
static int F_48 ( struct V_12 * V_13 , struct V_41 * V_42 ,
const struct V_43 * V_11 ,
struct V_45 * V_46 ,
V_36 V_47 , V_36 V_48 , T_2 V_49 ,
const struct V_50 * V_51 )
{
if ( V_13 -> V_66 == V_109 )
return F_41 ( V_13 , V_42 , V_47 , V_48 ,
V_49 , V_51 ) ;
if ( V_13 -> V_66 == V_127 )
return F_44 ( V_13 , V_42 , V_47 , V_48 ,
V_49 , V_51 ) ;
return F_39 ( V_13 , V_42 , V_11 , V_46 , V_47 , V_48 ,
V_49 , V_51 ) ;
}
struct V_12 * F_49 ( struct V_128 * V_128 ,
struct V_129 * V_130 ,
const struct V_43 * V_44 )
{
struct V_12 * V_13 ;
if ( V_44 -> V_131 == V_6 )
V_13 = F_50 ( V_128 , V_130 , V_44 -> V_16 . V_29 [ 0 ] ,
V_44 -> V_16 . V_19 , V_44 -> V_16 . V_27 [ 0 ] ,
V_44 -> V_16 . V_17 , V_44 -> V_16 . V_21 ) ;
#if F_10 ( V_24 )
else if ( V_44 -> V_131 == V_25 ) {
if ( F_51 ( (struct V_26 * ) V_44 -> V_16 . V_29 ) &&
F_51 ( (struct V_26 * ) V_44 -> V_16 . V_27 ) )
V_13 = F_50 ( V_128 , V_130 , V_44 -> V_16 . V_29 [ 3 ] ,
V_44 -> V_16 . V_19 , V_44 -> V_16 . V_27 [ 3 ] ,
V_44 -> V_16 . V_17 , V_44 -> V_16 . V_21 ) ;
else
V_13 = F_52 ( V_128 , V_130 ,
(struct V_26 * ) V_44 -> V_16 . V_29 ,
V_44 -> V_16 . V_19 ,
(struct V_26 * ) V_44 -> V_16 . V_27 ,
V_44 -> V_16 . V_17 ,
V_44 -> V_16 . V_21 ) ;
}
#endif
else
return F_4 ( - V_132 ) ;
if ( ! V_13 )
return F_4 ( - V_8 ) ;
if ( F_53 ( V_13 , V_44 -> V_16 . V_23 ) ) {
F_54 ( V_13 ) ;
return F_4 ( - V_8 ) ;
}
return V_13 ;
}
int F_55 ( struct V_129 * V_130 ,
struct V_41 * V_133 ,
const struct V_50 * V_58 ,
const struct V_43 * V_44 )
{
struct V_128 * V_128 = F_56 ( V_133 -> V_13 ) ;
struct V_41 * V_134 ;
struct V_12 * V_13 ;
int V_106 ;
V_13 = F_49 ( V_128 , V_130 , V_44 ) ;
if ( F_57 ( V_13 ) )
return F_58 ( V_13 ) ;
V_134 = F_59 ( F_11 () , V_135 ) ;
if ( ! V_134 ) {
V_106 = - V_136 ;
goto V_91;
}
V_106 = F_48 ( V_13 , V_134 , V_44 ,
F_60 ( F_61 ( V_133 ) . V_13 ) ,
F_61 ( V_133 ) . V_47 ,
V_58 -> V_137 , 0 , V_58 ) ;
if ( V_106 < 0 ) {
F_62 ( V_106 == - V_64 ) ;
F_63 ( V_134 ) ;
goto V_91;
}
V_106 = F_64 ( V_128 -> V_138 , V_134 , F_61 ( V_133 ) . V_47 ,
V_139 ) ;
if ( V_106 > 0 )
V_106 = 0 ;
V_91:
if ( V_13 )
F_54 ( V_13 ) ;
return V_106 ;
}
static int F_65 ( int V_140 , struct V_41 * V_133 ,
const struct V_50 * V_58 ,
const struct V_43 * V_44 )
{
const struct V_1 * V_9 ;
int V_106 ;
V_9 = F_1 ( V_44 -> V_62 ) ;
if ( F_57 ( V_9 ) )
V_106 = F_58 ( V_9 ) ;
else if ( V_140 == V_141 )
V_106 = V_9 -> V_142 ( V_133 , V_58 , V_44 ) ;
else if ( V_140 == V_143 && V_9 -> V_144 )
V_106 = V_9 -> V_144 ( V_133 , V_44 ) ;
else
V_106 = - V_145 ;
F_5 ( V_9 ) ;
return V_106 ;
}
static int F_66 ( const T_4 * V_146 , const T_4 * V_147 , int V_148 )
{
int V_149 = V_148 >> 5 ;
V_148 &= 0x1f ;
if ( V_149 ) {
if ( memcmp ( V_146 , V_147 , V_149 << 2 ) )
return 0 ;
}
if ( V_148 ) {
T_4 V_150 , V_151 ;
T_4 V_152 ;
V_150 = V_146 [ V_149 ] ;
V_151 = V_147 [ V_149 ] ;
V_152 = F_67 ( ( 0xffffffff ) << ( 32 - V_148 ) ) ;
if ( ( V_150 ^ V_151 ) & V_152 )
return 0 ;
}
return 1 ;
}
static int F_68 ( const struct V_59 * V_153 ,
const struct V_154 * V_155 )
{
const void * V_156 = F_32 ( V_153 ) ;
int V_157 = F_69 ( V_153 ) ;
while ( V_157 > 0 ) {
int V_158 = 1 ;
const struct V_159 * V_160 = V_156 ;
switch ( V_160 -> V_161 ) {
case V_162 :
break;
case V_163 :
V_158 = 0 ;
break;
case V_164 :
V_158 = V_155 -> V_165 >= V_160 [ 1 ] . V_166 ;
break;
case V_167 :
V_158 = V_155 -> V_165 <= V_160 [ 1 ] . V_166 ;
break;
case V_168 :
V_158 = V_155 -> V_169 >= V_160 [ 1 ] . V_166 ;
break;
case V_170 :
V_158 = V_155 -> V_169 <= V_160 [ 1 ] . V_166 ;
break;
case V_171 :
V_158 = ! ( V_155 -> V_172 & V_173 ) ;
break;
case V_174 :
case V_175 : {
const struct V_176 * V_177 ;
const T_4 * V_178 ;
V_177 = ( const struct V_176 * ) ( V_160 + 1 ) ;
if ( V_177 -> V_179 != - 1 &&
V_177 -> V_179 != ( V_160 -> V_161 == V_174 ?
V_155 -> V_165 : V_155 -> V_169 ) ) {
V_158 = 0 ;
break;
}
if ( V_160 -> V_161 == V_174 )
V_178 = V_155 -> V_180 ;
else
V_178 = V_155 -> V_181 ;
if ( V_177 -> V_182 != V_183 &&
V_177 -> V_182 != V_155 -> V_182 ) {
if ( V_155 -> V_182 == V_25 &&
V_177 -> V_182 == V_6 ) {
if ( V_178 [ 0 ] == 0 && V_178 [ 1 ] == 0 &&
V_178 [ 2 ] == F_67 ( 0xffff ) &&
F_66 ( V_178 + 3 ,
V_177 -> V_178 ,
V_177 -> V_184 ) )
break;
}
V_158 = 0 ;
break;
}
if ( V_177 -> V_184 == 0 )
break;
if ( F_66 ( V_178 , V_177 -> V_178 ,
V_177 -> V_184 ) )
break;
V_158 = 0 ;
break;
}
}
if ( V_158 ) {
V_157 -= V_160 -> V_158 ;
V_156 += V_160 -> V_158 ;
} else {
V_157 -= V_160 -> V_166 ;
V_156 += V_160 -> V_166 ;
}
}
return V_157 == 0 ;
}
static void F_70 ( struct V_154 * V_155 ,
const struct V_12 * V_13 )
{
#if F_10 ( V_24 )
if ( V_13 -> V_15 == V_25 ) {
V_155 -> V_180 = V_13 -> V_28 . V_185 ;
V_155 -> V_181 = V_13 -> V_30 . V_185 ;
} else
#endif
{
V_155 -> V_180 = & V_13 -> V_31 ;
V_155 -> V_181 = & V_13 -> V_32 ;
}
}
int F_71 ( const struct V_59 * V_156 , struct V_12 * V_13 )
{
struct V_52 * V_53 = F_14 ( V_13 ) ;
struct V_154 V_155 ;
if ( ! V_156 )
return 1 ;
V_155 . V_182 = V_13 -> V_15 ;
F_70 ( & V_155 , V_13 ) ;
V_155 . V_165 = V_53 -> V_186 ;
V_155 . V_169 = F_72 ( V_53 -> V_187 ) ;
V_155 . V_172 = F_18 ( V_13 ) ? V_13 -> V_188 : 0 ;
return F_68 ( V_156 , & V_155 ) ;
}
static int F_73 ( const void * V_156 , int V_157 , int V_189 )
{
while ( V_157 >= 0 ) {
const struct V_159 * V_160 = V_156 ;
if ( V_189 > V_157 )
return 0 ;
if ( V_189 == V_157 )
return 1 ;
if ( V_160 -> V_158 < 4 || V_160 -> V_158 & 3 )
return 0 ;
V_157 -= V_160 -> V_158 ;
V_156 += V_160 -> V_158 ;
}
return 0 ;
}
static bool F_74 ( const struct V_159 * V_160 , int V_157 ,
int * V_190 )
{
struct V_176 * V_177 ;
int V_191 ;
* V_190 += sizeof( struct V_176 ) ;
if ( V_157 < * V_190 )
return false ;
V_177 = (struct V_176 * ) ( V_160 + 1 ) ;
switch ( V_177 -> V_182 ) {
case V_183 :
V_191 = 0 ;
break;
case V_6 :
V_191 = sizeof( struct V_192 ) ;
break;
case V_25 :
V_191 = sizeof( struct V_26 ) ;
break;
default:
return false ;
}
* V_190 += V_191 ;
if ( V_157 < * V_190 )
return false ;
if ( V_177 -> V_184 > 8 * V_191 )
return false ;
return true ;
}
static bool F_75 ( const struct V_159 * V_160 ,
int V_157 , int * V_190 )
{
* V_190 += sizeof( struct V_159 ) ;
if ( V_157 < * V_190 )
return false ;
return true ;
}
static int F_76 ( const void * V_193 , int V_194 )
{
const void * V_156 = V_193 ;
int V_157 = V_194 ;
while ( V_157 > 0 ) {
int V_190 = sizeof( struct V_159 ) ;
const struct V_159 * V_160 = V_156 ;
switch ( V_160 -> V_161 ) {
case V_174 :
case V_175 :
if ( ! F_74 ( V_156 , V_157 , & V_190 ) )
return - V_132 ;
break;
case V_164 :
case V_167 :
case V_168 :
case V_170 :
if ( ! F_75 ( V_156 , V_157 , & V_190 ) )
return - V_132 ;
break;
case V_171 :
case V_163 :
case V_162 :
break;
default:
return - V_132 ;
}
if ( V_160 -> V_161 != V_162 ) {
if ( V_160 -> V_166 < V_190 || V_160 -> V_166 > V_157 + 4 || V_160 -> V_166 & 3 )
return - V_132 ;
if ( V_160 -> V_166 < V_157 &&
! F_73 ( V_193 , V_194 , V_157 - V_160 -> V_166 ) )
return - V_132 ;
}
if ( V_160 -> V_158 < V_190 || V_160 -> V_158 > V_157 + 4 || V_160 -> V_158 & 3 )
return - V_132 ;
V_156 += V_160 -> V_158 ;
V_157 -= V_160 -> V_158 ;
}
return V_157 == 0 ? 0 : - V_132 ;
}
static int F_77 ( struct V_12 * V_13 ,
struct V_41 * V_42 ,
struct V_195 * V_196 ,
const struct V_43 * V_11 ,
const struct V_59 * V_156 )
{
if ( ! F_71 ( V_156 , V_13 ) )
return 0 ;
return F_39 ( V_13 , V_42 , V_11 ,
F_60 ( F_61 ( V_196 -> V_42 ) . V_13 ) ,
F_61 ( V_196 -> V_42 ) . V_47 ,
V_196 -> V_58 -> V_137 , V_197 , V_196 -> V_58 ) ;
}
static void F_78 ( void )
{
F_46 ( F_47 ( struct V_113 , V_198 ) !=
F_47 ( struct V_12 , V_15 ) ) ;
F_46 ( F_47 ( struct V_113 , V_199 ) !=
F_47 ( struct V_52 , V_186 ) ) ;
F_46 ( F_47 ( struct V_113 , V_200 ) !=
F_47 ( struct V_52 , V_187 ) ) ;
F_46 ( F_47 ( struct V_113 , V_201 ) !=
F_47 ( struct V_52 , V_202 ) ) ;
F_46 ( F_47 ( struct V_113 , V_203 ) !=
F_47 ( struct V_52 , V_204 ) ) ;
#if F_10 ( V_24 )
F_46 ( F_47 ( struct V_113 , V_205 ) !=
F_47 ( struct V_12 , V_28 ) ) ;
F_46 ( F_47 ( struct V_113 , V_206 ) !=
F_47 ( struct V_12 , V_30 ) ) ;
#endif
}
void F_79 ( struct V_129 * V_130 , struct V_41 * V_42 ,
struct V_195 * V_196 ,
const struct V_43 * V_11 , struct V_59 * V_156 )
{
struct V_128 * V_128 = F_56 ( V_42 -> V_13 ) ;
int V_207 , V_208 , V_209 , V_210 ;
V_36 V_211 = V_11 -> V_211 ;
if ( V_211 & V_212 )
V_211 |= V_213 ;
V_209 = V_196 -> args [ 1 ] ;
V_210 = V_208 = V_196 -> args [ 2 ] ;
if ( V_196 -> args [ 0 ] == 0 ) {
if ( ! ( V_211 & V_76 ) )
goto V_214;
for ( V_207 = V_209 ; V_207 < V_215 ; V_207 ++ ) {
struct V_216 * V_217 ;
struct V_218 * V_219 ;
struct V_12 * V_13 ;
V_208 = 0 ;
V_217 = & V_130 -> V_220 [ V_207 ] ;
F_80 ( & V_217 -> V_221 ) ;
F_81 (sk, node, &ilb->head) {
struct V_52 * V_53 = F_14 ( V_13 ) ;
if ( ! F_82 ( F_56 ( V_13 ) , V_128 ) )
continue;
if ( V_208 < V_210 ) {
V_208 ++ ;
continue;
}
if ( V_11 -> V_131 != V_183 &&
V_13 -> V_15 != V_11 -> V_131 )
goto V_222;
if ( V_11 -> V_16 . V_17 != V_53 -> V_223 &&
V_11 -> V_16 . V_17 )
goto V_222;
if ( V_11 -> V_16 . V_19 ||
V_196 -> args [ 3 ] > 0 )
goto V_222;
if ( F_77 ( V_13 , V_42 , V_196 , V_11 , V_156 ) < 0 ) {
F_83 ( & V_217 -> V_221 ) ;
goto V_224;
}
V_222:
V_196 -> args [ 3 ] = 0 ;
V_196 -> args [ 4 ] = 0 ;
++ V_208 ;
}
F_83 ( & V_217 -> V_221 ) ;
V_210 = 0 ;
V_196 -> args [ 3 ] = 0 ;
V_196 -> args [ 4 ] = 0 ;
}
V_214:
V_196 -> args [ 0 ] = 1 ;
V_209 = V_208 = V_210 = 0 ;
}
if ( ! ( V_211 & ~ V_76 ) )
goto V_91;
for ( V_207 = V_209 ; V_207 <= V_130 -> V_225 ; V_207 ++ ) {
struct V_226 * V_227 = & V_130 -> V_228 [ V_207 ] ;
T_5 * V_221 = F_84 ( V_130 , V_207 ) ;
struct V_218 * V_219 ;
struct V_12 * V_13 ;
V_208 = 0 ;
if ( F_85 ( & V_227 -> V_229 ) )
continue;
if ( V_207 > V_209 )
V_210 = 0 ;
F_80 ( V_221 ) ;
F_81 (sk, node, &head->chain) {
int V_230 , V_231 ;
if ( ! F_82 ( F_56 ( V_13 ) , V_128 ) )
continue;
if ( V_208 < V_210 )
goto V_232;
V_230 = ( V_13 -> V_66 == V_109 ) ?
F_42 ( V_13 ) -> V_118 : V_13 -> V_66 ;
if ( ! ( V_211 & ( 1 << V_230 ) ) )
goto V_232;
if ( V_11 -> V_131 != V_183 &&
V_13 -> V_15 != V_11 -> V_131 )
goto V_232;
if ( V_11 -> V_16 . V_17 != F_8 ( V_13 -> V_18 ) &&
V_11 -> V_16 . V_17 )
goto V_232;
if ( V_11 -> V_16 . V_19 != V_13 -> V_20 &&
V_11 -> V_16 . V_19 )
goto V_232;
F_78 () ;
if ( ! F_71 ( V_156 , V_13 ) )
goto V_232;
V_231 = F_48 ( V_13 , V_42 , V_11 ,
F_60 ( F_61 ( V_196 -> V_42 ) . V_13 ) ,
F_61 ( V_196 -> V_42 ) . V_47 ,
V_196 -> V_58 -> V_137 , V_197 ,
V_196 -> V_58 ) ;
if ( V_231 < 0 ) {
F_83 ( V_221 ) ;
goto V_224;
}
V_232:
++ V_208 ;
}
F_83 ( V_221 ) ;
}
V_224:
V_196 -> args [ 1 ] = V_207 ;
V_196 -> args [ 2 ] = V_208 ;
V_91:
;
}
static int F_86 ( struct V_41 * V_42 , struct V_195 * V_196 ,
const struct V_43 * V_11 ,
struct V_59 * V_156 )
{
const struct V_1 * V_9 ;
int V_106 = 0 ;
V_9 = F_1 ( V_11 -> V_62 ) ;
if ( ! F_57 ( V_9 ) )
V_9 -> V_233 ( V_42 , V_196 , V_11 , V_156 ) ;
else
V_106 = F_58 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_106 ? : V_42 -> V_157 ;
}
static int F_87 ( struct V_41 * V_42 , struct V_195 * V_196 )
{
int V_234 = sizeof( struct V_43 ) ;
struct V_59 * V_156 = NULL ;
if ( F_88 ( V_196 -> V_58 , V_234 ) )
V_156 = F_89 ( V_196 -> V_58 , V_234 , V_235 ) ;
return F_86 ( V_42 , V_196 , F_17 ( V_196 -> V_58 ) , V_156 ) ;
}
static int F_90 ( int type )
{
switch ( type ) {
case V_236 :
return V_237 ;
case V_238 :
return V_239 ;
default:
return 0 ;
}
}
static int F_91 ( struct V_41 * V_42 ,
struct V_195 * V_196 )
{
struct V_240 * V_241 = F_17 ( V_196 -> V_58 ) ;
int V_234 = sizeof( struct V_240 ) ;
struct V_43 V_44 ;
struct V_59 * V_156 = NULL ;
V_44 . V_131 = V_183 ;
V_44 . V_62 = F_90 ( V_196 -> V_58 -> V_63 ) ;
V_44 . V_57 = V_241 -> V_57 ;
V_44 . V_211 = V_241 -> V_211 ;
V_44 . V_16 = V_241 -> V_16 ;
if ( F_88 ( V_196 -> V_58 , V_234 ) )
V_156 = F_89 ( V_196 -> V_58 , V_234 , V_235 ) ;
return F_86 ( V_42 , V_196 , & V_44 , V_156 ) ;
}
static int F_92 ( struct V_41 * V_133 ,
const struct V_50 * V_58 )
{
struct V_240 * V_241 = F_17 ( V_58 ) ;
struct V_43 V_44 ;
V_44 . V_131 = V_241 -> V_14 ;
V_44 . V_62 = F_90 ( V_58 -> V_63 ) ;
V_44 . V_57 = V_241 -> V_57 ;
V_44 . V_211 = V_241 -> V_211 ;
V_44 . V_16 = V_241 -> V_16 ;
return F_65 ( V_141 , V_133 , V_58 , & V_44 ) ;
}
static int F_93 ( struct V_41 * V_42 , struct V_50 * V_58 )
{
int V_234 = sizeof( struct V_240 ) ;
struct V_128 * V_128 = F_56 ( V_42 -> V_13 ) ;
if ( V_58 -> V_63 >= V_242 ||
F_94 ( V_58 ) < V_234 )
return - V_132 ;
if ( V_58 -> V_49 & V_243 ) {
if ( F_88 ( V_58 , V_234 ) ) {
struct V_59 * V_60 ;
V_60 = F_89 ( V_58 , V_234 ,
V_235 ) ;
if ( ! V_60 ||
F_69 ( V_60 ) < sizeof( struct V_159 ) ||
F_76 ( F_32 ( V_60 ) , F_69 ( V_60 ) ) )
return - V_132 ;
}
{
struct V_244 V_245 = {
. V_233 = F_91 ,
} ;
return F_95 ( V_128 -> V_138 , V_42 , V_58 , & V_245 ) ;
}
}
return F_92 ( V_42 , V_58 ) ;
}
static int F_96 ( struct V_41 * V_42 , struct V_50 * V_246 )
{
int V_234 = sizeof( struct V_43 ) ;
struct V_128 * V_128 = F_56 ( V_42 -> V_13 ) ;
if ( F_94 ( V_246 ) < V_234 )
return - V_132 ;
if ( V_246 -> V_63 == V_141 &&
V_246 -> V_49 & V_243 ) {
if ( F_88 ( V_246 , V_234 ) ) {
struct V_59 * V_60 ;
V_60 = F_89 ( V_246 , V_234 ,
V_235 ) ;
if ( ! V_60 ||
F_69 ( V_60 ) < sizeof( struct V_159 ) ||
F_76 ( F_32 ( V_60 ) , F_69 ( V_60 ) ) )
return - V_132 ;
}
{
struct V_244 V_245 = {
. V_233 = F_87 ,
} ;
return F_95 ( V_128 -> V_138 , V_42 , V_246 , & V_245 ) ;
}
}
return F_65 ( V_246 -> V_63 , V_42 , V_246 , F_17 ( V_246 ) ) ;
}
static
int F_97 ( struct V_41 * V_42 , struct V_12 * V_13 )
{
const struct V_1 * V_9 ;
struct V_50 * V_58 ;
struct V_59 * V_60 ;
struct V_10 * V_11 ;
void * V_61 = NULL ;
int V_106 = 0 ;
V_58 = F_16 ( V_42 , 0 , 0 , V_141 , sizeof( * V_11 ) , 0 ) ;
if ( ! V_58 )
return - V_136 ;
V_11 = F_17 ( V_58 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_7 ( V_11 , V_13 ) ;
if ( V_13 -> V_247 == V_248 || V_13 -> V_247 == V_249 )
V_11 -> V_16 . V_17 = F_14 ( V_13 ) -> V_223 ;
V_11 -> V_65 = V_13 -> V_66 ;
if ( ( V_106 = F_19 ( V_42 , V_250 , V_13 -> V_251 ) ) ) {
F_38 ( V_42 , V_58 ) ;
return V_106 ;
}
V_9 = F_1 ( V_13 -> V_251 ) ;
if ( F_57 ( V_9 ) ) {
F_5 ( V_9 ) ;
F_38 ( V_42 , V_58 ) ;
return F_58 ( V_9 ) ;
}
V_60 = V_9 -> V_104
? F_31 ( V_42 , V_103 , V_9 -> V_104 )
: NULL ;
if ( V_60 )
V_61 = F_32 ( V_60 ) ;
V_9 -> V_90 ( V_13 , V_11 , V_61 ) ;
F_5 ( V_9 ) ;
F_37 ( V_42 , V_58 ) ;
return 0 ;
}
int F_98 ( const struct V_1 * V_246 )
{
const T_6 type = V_246 -> V_252 ;
int V_106 = - V_132 ;
if ( type >= V_253 )
goto V_91;
F_3 ( & V_7 ) ;
V_106 = - V_254 ;
if ( ! V_3 [ type ] ) {
V_3 [ type ] = V_246 ;
V_106 = 0 ;
}
F_6 ( & V_7 ) ;
V_91:
return V_106 ;
}
void F_99 ( const struct V_1 * V_246 )
{
const T_6 type = V_246 -> V_252 ;
if ( type >= V_253 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_7 F_100 ( void )
{
const int V_255 = ( V_253 *
sizeof( struct V_1 * ) ) ;
int V_106 = - V_136 ;
V_3 = F_101 ( V_255 , V_135 ) ;
if ( ! V_3 )
goto V_91;
V_106 = F_102 ( & V_1 ) ;
if ( V_106 )
goto V_256;
V_106 = F_102 ( & V_257 ) ;
if ( V_106 )
goto V_258;
F_103 ( F_93 ) ;
V_91:
return V_106 ;
V_258:
F_104 ( & V_1 ) ;
V_256:
F_105 ( V_3 ) ;
goto V_91;
}
static void T_8 F_106 ( void )
{
F_104 ( & V_257 ) ;
F_104 ( & V_1 ) ;
F_107 ( F_93 ) ;
F_105 ( V_3 ) ;
}
