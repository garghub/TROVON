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
}
#endif
V_11 -> V_76 = F_21 ( V_46 , F_22 ( V_13 ) ) ;
V_11 -> V_77 = F_23 ( V_13 ) ;
if ( V_56 & ( 1 << ( V_78 - 1 ) ) ) {
struct V_34 V_79 = {
. V_80 = F_24 ( V_13 ) ,
. V_81 = V_13 -> V_82 ,
. V_83 = V_13 -> V_84 ,
. V_85 = F_25 ( V_13 ) ,
} ;
if ( F_26 ( V_42 , V_78 , sizeof( V_79 ) , & V_79 ) < 0 )
goto V_71;
}
if ( V_56 & ( 1 << ( V_86 - 1 ) ) )
if ( F_27 ( V_13 , V_42 , V_86 ) )
goto V_71;
if ( ! V_40 ) {
V_9 -> V_87 ( V_13 , V_11 , NULL ) ;
goto V_88;
}
#define F_28 ( T_3 ) DIV_ROUND_UP((tmo - jiffies) * 1000, HZ)
if ( V_40 -> V_89 == V_90 ||
V_40 -> V_89 == V_91 ||
V_40 -> V_89 == V_92 ) {
V_11 -> V_67 = 1 ;
V_11 -> V_68 = V_40 -> V_93 ;
V_11 -> V_94 = F_28 ( V_40 -> V_95 ) ;
} else if ( V_40 -> V_89 == V_96 ) {
V_11 -> V_67 = 4 ;
V_11 -> V_68 = V_40 -> V_97 ;
V_11 -> V_94 = F_28 ( V_40 -> V_95 ) ;
} else if ( F_29 ( & V_13 -> V_98 ) ) {
V_11 -> V_67 = 2 ;
V_11 -> V_68 = V_40 -> V_97 ;
V_11 -> V_94 = F_28 ( V_13 -> V_98 . V_99 ) ;
} else {
V_11 -> V_67 = 0 ;
V_11 -> V_94 = 0 ;
}
#undef F_28
if ( V_56 & ( 1 << ( V_100 - 1 ) ) ) {
V_60 = F_30 ( V_42 , V_100 ,
sizeof( struct V_33 ) ) ;
if ( ! V_60 )
goto V_71;
V_61 = F_31 ( V_60 ) ;
}
if ( V_56 & ( 1 << ( V_101 - 1 ) ) ) {
int V_102 = 0 ;
F_32 () ;
V_55 = F_33 ( V_40 -> V_103 ) ;
if ( V_55 )
V_102 = F_34 ( V_42 , V_101 , V_55 -> V_104 ) ;
F_35 () ;
if ( V_102 < 0 )
goto V_71;
}
V_9 -> V_87 ( V_13 , V_11 , V_61 ) ;
if ( V_13 -> V_66 < V_105 ) {
union V_106 V_61 ;
T_1 V_107 = 0 ;
int V_60 ;
F_32 () ;
V_55 = F_33 ( V_40 -> V_103 ) ;
if ( V_55 && V_55 -> V_108 )
V_107 = V_55 -> V_108 ( V_13 , V_56 , & V_60 , & V_61 ) ;
F_35 () ;
if ( V_107 && F_26 ( V_42 , V_60 , V_107 , & V_61 ) < 0 )
goto V_71;
}
V_88:
F_36 ( V_42 , V_58 ) ;
return 0 ;
V_71:
F_37 ( V_42 , V_58 ) ;
return - V_64 ;
}
static int F_38 ( struct V_12 * V_13 ,
struct V_41 * V_42 ,
const struct V_43 * V_44 ,
struct V_45 * V_46 ,
V_36 V_47 , V_36 V_48 , T_2 V_49 ,
const struct V_50 * V_51 )
{
return F_13 ( V_13 , F_39 ( V_13 ) , V_42 , V_44 ,
V_46 , V_47 , V_48 , V_49 , V_51 ) ;
}
static int F_40 ( struct V_12 * V_13 ,
struct V_41 * V_42 ,
V_36 V_47 , V_36 V_48 , T_2 V_49 ,
const struct V_50 * V_51 )
{
struct V_109 * V_110 = F_41 ( V_13 ) ;
struct V_10 * V_11 ;
struct V_50 * V_58 ;
long T_3 ;
V_58 = F_16 ( V_42 , V_47 , V_48 , V_51 -> V_63 , sizeof( * V_11 ) ,
V_49 ) ;
if ( ! V_58 )
return - V_64 ;
V_11 = F_17 ( V_58 ) ;
F_15 ( V_110 -> V_111 != V_105 ) ;
T_3 = V_110 -> V_112 . V_99 - V_113 ;
if ( T_3 < 0 )
T_3 = 0 ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_68 = 0 ;
V_11 -> V_65 = V_110 -> V_114 ;
V_11 -> V_67 = 3 ;
V_11 -> V_94 = F_42 ( T_3 ) ;
V_11 -> V_115 = 0 ;
V_11 -> V_116 = 0 ;
V_11 -> V_76 = 0 ;
V_11 -> V_77 = 0 ;
F_36 ( V_42 , V_58 ) ;
return 0 ;
}
static int F_43 ( struct V_12 * V_13 , struct V_41 * V_42 ,
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
V_11 -> V_65 = V_117 ;
V_11 -> V_67 = 1 ;
V_11 -> V_68 = F_44 ( V_13 ) -> V_118 ;
F_45 ( F_46 ( struct V_119 , V_120 ) !=
F_46 ( struct V_12 , V_121 ) ) ;
T_3 = F_44 ( V_13 ) -> V_122 . V_99 - V_113 ;
V_11 -> V_94 = ( T_3 >= 0 ) ? F_42 ( T_3 ) : 0 ;
V_11 -> V_115 = 0 ;
V_11 -> V_116 = 0 ;
V_11 -> V_76 = 0 ;
V_11 -> V_77 = 0 ;
F_36 ( V_42 , V_58 ) ;
return 0 ;
}
static int F_47 ( struct V_12 * V_13 , struct V_41 * V_42 ,
const struct V_43 * V_11 ,
struct V_45 * V_46 ,
V_36 V_47 , V_36 V_48 , T_2 V_49 ,
const struct V_50 * V_51 )
{
if ( V_13 -> V_66 == V_105 )
return F_40 ( V_13 , V_42 , V_47 , V_48 ,
V_49 , V_51 ) ;
if ( V_13 -> V_66 == V_123 )
return F_43 ( V_13 , V_42 , V_47 , V_48 ,
V_49 , V_51 ) ;
return F_38 ( V_13 , V_42 , V_11 , V_46 , V_47 , V_48 ,
V_49 , V_51 ) ;
}
int F_48 ( struct V_124 * V_125 ,
struct V_41 * V_126 ,
const struct V_50 * V_58 ,
const struct V_43 * V_44 )
{
struct V_127 * V_127 = F_49 ( V_126 -> V_13 ) ;
struct V_41 * V_128 ;
struct V_12 * V_13 ;
int V_102 ;
V_102 = - V_129 ;
if ( V_44 -> V_130 == V_6 )
V_13 = F_50 ( V_127 , V_125 , V_44 -> V_16 . V_29 [ 0 ] ,
V_44 -> V_16 . V_19 , V_44 -> V_16 . V_27 [ 0 ] ,
V_44 -> V_16 . V_17 , V_44 -> V_16 . V_21 ) ;
#if F_10 ( V_24 )
else if ( V_44 -> V_130 == V_25 )
V_13 = F_51 ( V_127 , V_125 ,
(struct V_26 * ) V_44 -> V_16 . V_29 ,
V_44 -> V_16 . V_19 ,
(struct V_26 * ) V_44 -> V_16 . V_27 ,
V_44 -> V_16 . V_17 ,
V_44 -> V_16 . V_21 ) ;
#endif
else
goto V_131;
V_102 = - V_8 ;
if ( ! V_13 )
goto V_131;
V_102 = F_52 ( V_13 , V_44 -> V_16 . V_23 ) ;
if ( V_102 )
goto V_88;
V_128 = F_53 ( F_11 () , V_132 ) ;
if ( ! V_128 ) {
V_102 = - V_133 ;
goto V_88;
}
V_102 = F_47 ( V_13 , V_128 , V_44 ,
F_54 ( F_55 ( V_126 ) . V_13 ) ,
F_55 ( V_126 ) . V_47 ,
V_58 -> V_134 , 0 , V_58 ) ;
if ( V_102 < 0 ) {
F_56 ( V_102 == - V_64 ) ;
F_57 ( V_128 ) ;
goto V_88;
}
V_102 = F_58 ( V_127 -> V_135 , V_128 , F_55 ( V_126 ) . V_47 ,
V_136 ) ;
if ( V_102 > 0 )
V_102 = 0 ;
V_88:
if ( V_13 )
F_59 ( V_13 ) ;
V_131:
return V_102 ;
}
static int F_60 ( struct V_41 * V_126 ,
const struct V_50 * V_58 ,
const struct V_43 * V_44 )
{
const struct V_1 * V_9 ;
int V_102 ;
V_9 = F_1 ( V_44 -> V_62 ) ;
if ( F_61 ( V_9 ) )
V_102 = F_62 ( V_9 ) ;
else
V_102 = V_9 -> V_137 ( V_126 , V_58 , V_44 ) ;
F_5 ( V_9 ) ;
return V_102 ;
}
static int F_63 ( const T_4 * V_138 , const T_4 * V_139 , int V_140 )
{
int V_141 = V_140 >> 5 ;
V_140 &= 0x1f ;
if ( V_141 ) {
if ( memcmp ( V_138 , V_139 , V_141 << 2 ) )
return 0 ;
}
if ( V_140 ) {
T_4 V_142 , V_143 ;
T_4 V_144 ;
V_142 = V_138 [ V_141 ] ;
V_143 = V_139 [ V_141 ] ;
V_144 = F_64 ( ( 0xffffffff ) << ( 32 - V_140 ) ) ;
if ( ( V_142 ^ V_143 ) & V_144 )
return 0 ;
}
return 1 ;
}
static int F_65 ( const struct V_59 * V_145 ,
const struct V_146 * V_147 )
{
const void * V_148 = F_31 ( V_145 ) ;
int V_149 = F_66 ( V_145 ) ;
while ( V_149 > 0 ) {
int V_150 = 1 ;
const struct V_151 * V_152 = V_148 ;
switch ( V_152 -> V_153 ) {
case V_154 :
break;
case V_155 :
V_150 = 0 ;
break;
case V_156 :
V_150 = V_147 -> V_157 >= V_152 [ 1 ] . V_158 ;
break;
case V_159 :
V_150 = V_147 -> V_157 <= V_152 [ 1 ] . V_158 ;
break;
case V_160 :
V_150 = V_147 -> V_161 >= V_152 [ 1 ] . V_158 ;
break;
case V_162 :
V_150 = V_147 -> V_161 <= V_152 [ 1 ] . V_158 ;
break;
case V_163 :
V_150 = ! ( V_147 -> V_164 & V_165 ) ;
break;
case V_166 :
case V_167 : {
const struct V_168 * V_169 ;
const T_4 * V_170 ;
V_169 = ( const struct V_168 * ) ( V_152 + 1 ) ;
if ( V_169 -> V_171 != - 1 &&
V_169 -> V_171 != ( V_152 -> V_153 == V_166 ?
V_147 -> V_157 : V_147 -> V_161 ) ) {
V_150 = 0 ;
break;
}
if ( V_152 -> V_153 == V_166 )
V_170 = V_147 -> V_172 ;
else
V_170 = V_147 -> V_173 ;
if ( V_169 -> V_174 != V_175 &&
V_169 -> V_174 != V_147 -> V_174 ) {
if ( V_147 -> V_174 == V_25 &&
V_169 -> V_174 == V_6 ) {
if ( V_170 [ 0 ] == 0 && V_170 [ 1 ] == 0 &&
V_170 [ 2 ] == F_64 ( 0xffff ) &&
F_63 ( V_170 + 3 ,
V_169 -> V_170 ,
V_169 -> V_176 ) )
break;
}
V_150 = 0 ;
break;
}
if ( V_169 -> V_176 == 0 )
break;
if ( F_63 ( V_170 , V_169 -> V_170 ,
V_169 -> V_176 ) )
break;
V_150 = 0 ;
break;
}
}
if ( V_150 ) {
V_149 -= V_152 -> V_150 ;
V_148 += V_152 -> V_150 ;
} else {
V_149 -= V_152 -> V_158 ;
V_148 += V_152 -> V_158 ;
}
}
return V_149 == 0 ;
}
static void F_67 ( struct V_146 * V_147 ,
const struct V_12 * V_13 )
{
#if F_10 ( V_24 )
if ( V_13 -> V_15 == V_25 ) {
V_147 -> V_172 = V_13 -> V_28 . V_177 ;
V_147 -> V_173 = V_13 -> V_30 . V_177 ;
} else
#endif
{
V_147 -> V_172 = & V_13 -> V_31 ;
V_147 -> V_173 = & V_13 -> V_32 ;
}
}
int F_68 ( const struct V_59 * V_148 , struct V_12 * V_13 )
{
struct V_52 * V_53 = F_14 ( V_13 ) ;
struct V_146 V_147 ;
if ( ! V_148 )
return 1 ;
V_147 . V_174 = V_13 -> V_15 ;
F_67 ( & V_147 , V_13 ) ;
V_147 . V_157 = V_53 -> V_178 ;
V_147 . V_161 = F_69 ( V_53 -> V_179 ) ;
V_147 . V_164 = F_18 ( V_13 ) ? V_13 -> V_180 : 0 ;
return F_65 ( V_148 , & V_147 ) ;
}
static int F_70 ( const void * V_148 , int V_149 , int V_181 )
{
while ( V_149 >= 0 ) {
const struct V_151 * V_152 = V_148 ;
if ( V_181 > V_149 )
return 0 ;
if ( V_181 == V_149 )
return 1 ;
if ( V_152 -> V_150 < 4 || V_152 -> V_150 & 3 )
return 0 ;
V_149 -= V_152 -> V_150 ;
V_148 += V_152 -> V_150 ;
}
return 0 ;
}
static bool F_71 ( const struct V_151 * V_152 , int V_149 ,
int * V_182 )
{
struct V_168 * V_169 ;
int V_183 ;
* V_182 += sizeof( struct V_168 ) ;
if ( V_149 < * V_182 )
return false ;
V_169 = (struct V_168 * ) ( V_152 + 1 ) ;
switch ( V_169 -> V_174 ) {
case V_175 :
V_183 = 0 ;
break;
case V_6 :
V_183 = sizeof( struct V_184 ) ;
break;
case V_25 :
V_183 = sizeof( struct V_26 ) ;
break;
default:
return false ;
}
* V_182 += V_183 ;
if ( V_149 < * V_182 )
return false ;
if ( V_169 -> V_176 > 8 * V_183 )
return false ;
return true ;
}
static bool F_72 ( const struct V_151 * V_152 ,
int V_149 , int * V_182 )
{
* V_182 += sizeof( struct V_151 ) ;
if ( V_149 < * V_182 )
return false ;
return true ;
}
static int F_73 ( const void * V_185 , int V_186 )
{
const void * V_148 = V_185 ;
int V_149 = V_186 ;
while ( V_149 > 0 ) {
int V_182 = sizeof( struct V_151 ) ;
const struct V_151 * V_152 = V_148 ;
switch ( V_152 -> V_153 ) {
case V_166 :
case V_167 :
if ( ! F_71 ( V_148 , V_149 , & V_182 ) )
return - V_129 ;
break;
case V_156 :
case V_159 :
case V_160 :
case V_162 :
if ( ! F_72 ( V_148 , V_149 , & V_182 ) )
return - V_129 ;
break;
case V_163 :
case V_155 :
case V_154 :
break;
default:
return - V_129 ;
}
if ( V_152 -> V_153 != V_154 ) {
if ( V_152 -> V_158 < V_182 || V_152 -> V_158 > V_149 + 4 || V_152 -> V_158 & 3 )
return - V_129 ;
if ( V_152 -> V_158 < V_149 &&
! F_70 ( V_185 , V_186 , V_149 - V_152 -> V_158 ) )
return - V_129 ;
}
if ( V_152 -> V_150 < V_182 || V_152 -> V_150 > V_149 + 4 || V_152 -> V_150 & 3 )
return - V_129 ;
V_148 += V_152 -> V_150 ;
V_149 -= V_152 -> V_150 ;
}
return V_149 == 0 ? 0 : - V_129 ;
}
static int F_74 ( struct V_12 * V_13 ,
struct V_41 * V_42 ,
struct V_187 * V_188 ,
const struct V_43 * V_11 ,
const struct V_59 * V_148 )
{
if ( ! F_68 ( V_148 , V_13 ) )
return 0 ;
return F_38 ( V_13 , V_42 , V_11 ,
F_54 ( F_55 ( V_188 -> V_42 ) . V_13 ) ,
F_55 ( V_188 -> V_42 ) . V_47 ,
V_188 -> V_58 -> V_134 , V_189 , V_188 -> V_58 ) ;
}
static void F_75 ( void )
{
F_45 ( F_46 ( struct V_109 , V_190 ) !=
F_46 ( struct V_12 , V_15 ) ) ;
F_45 ( F_46 ( struct V_109 , V_191 ) !=
F_46 ( struct V_52 , V_178 ) ) ;
F_45 ( F_46 ( struct V_109 , V_192 ) !=
F_46 ( struct V_52 , V_179 ) ) ;
F_45 ( F_46 ( struct V_109 , V_193 ) !=
F_46 ( struct V_52 , V_194 ) ) ;
F_45 ( F_46 ( struct V_109 , V_195 ) !=
F_46 ( struct V_52 , V_196 ) ) ;
#if F_10 ( V_24 )
F_45 ( F_46 ( struct V_109 , V_197 ) !=
F_46 ( struct V_12 , V_28 ) ) ;
F_45 ( F_46 ( struct V_109 , V_198 ) !=
F_46 ( struct V_12 , V_30 ) ) ;
#endif
}
static int F_76 ( struct V_41 * V_42 , struct V_12 * V_13 ,
struct V_187 * V_188 ,
const struct V_43 * V_11 ,
const struct V_59 * V_148 )
{
struct V_39 * V_40 = F_39 ( V_13 ) ;
struct V_52 * V_53 = F_14 ( V_13 ) ;
struct V_146 V_147 ;
int V_199 , V_200 , V_201 , V_202 ;
struct V_203 * V_204 ;
int V_102 = 0 ;
V_200 = V_188 -> args [ 3 ] ;
V_202 = V_188 -> args [ 4 ] ;
if ( V_200 > 0 )
V_200 -- ;
V_147 . V_174 = V_13 -> V_15 ;
F_77 ( & V_40 -> V_205 . V_206 ) ;
V_204 = V_40 -> V_205 . V_207 ;
if ( ! V_204 || ! F_78 ( V_204 ) )
goto V_88;
if ( V_148 ) {
V_147 . V_157 = V_53 -> V_178 ;
V_147 . V_164 = V_13 -> V_180 ;
}
for ( V_199 = V_200 ; V_199 < V_204 -> V_208 ; V_199 ++ ) {
struct V_209 * V_44 , * V_210 = V_204 -> V_211 [ V_199 ] ;
V_201 = 0 ;
for ( V_44 = V_210 ; V_44 ; V_201 ++ , V_44 = V_44 -> V_212 ) {
struct V_119 * V_213 = F_79 ( V_44 ) ;
if ( V_201 < V_202 )
continue;
if ( V_11 -> V_16 . V_19 != V_213 -> V_214 &&
V_11 -> V_16 . V_19 )
continue;
if ( V_148 ) {
F_67 ( & V_147 , F_80 ( V_44 ) ) ;
V_147 . V_161 = F_69 ( V_213 -> V_214 ) ;
if ( ! F_65 ( V_148 , & V_147 ) )
continue;
}
V_102 = F_43 ( F_80 ( V_44 ) , V_42 ,
F_55 ( V_188 -> V_42 ) . V_47 ,
V_188 -> V_58 -> V_134 ,
V_189 , V_188 -> V_58 ) ;
if ( V_102 < 0 ) {
V_188 -> args [ 3 ] = V_199 + 1 ;
V_188 -> args [ 4 ] = V_201 ;
goto V_88;
}
}
V_202 = 0 ;
}
V_88:
F_81 ( & V_40 -> V_205 . V_206 ) ;
return V_102 ;
}
void F_82 ( struct V_124 * V_125 , struct V_41 * V_42 ,
struct V_187 * V_188 ,
const struct V_43 * V_11 , struct V_59 * V_148 )
{
struct V_127 * V_127 = F_49 ( V_42 -> V_13 ) ;
int V_215 , V_216 , V_217 , V_218 ;
V_217 = V_188 -> args [ 1 ] ;
V_218 = V_216 = V_188 -> args [ 2 ] ;
if ( V_188 -> args [ 0 ] == 0 ) {
if ( ! ( V_11 -> V_219 & ( V_220 | V_221 ) ) )
goto V_222;
for ( V_215 = V_217 ; V_215 < V_223 ; V_215 ++ ) {
struct V_224 * V_225 ;
struct V_226 * V_227 ;
struct V_12 * V_13 ;
V_216 = 0 ;
V_225 = & V_125 -> V_228 [ V_215 ] ;
F_77 ( & V_225 -> V_229 ) ;
F_83 (sk, node, &ilb->head) {
struct V_52 * V_53 = F_14 ( V_13 ) ;
if ( ! F_84 ( F_49 ( V_13 ) , V_127 ) )
continue;
if ( V_216 < V_218 ) {
V_216 ++ ;
continue;
}
if ( V_11 -> V_130 != V_175 &&
V_13 -> V_15 != V_11 -> V_130 )
goto V_230;
if ( V_11 -> V_16 . V_17 != V_53 -> V_231 &&
V_11 -> V_16 . V_17 )
goto V_230;
if ( ! ( V_11 -> V_219 & V_220 ) ||
V_11 -> V_16 . V_19 ||
V_188 -> args [ 3 ] > 0 )
goto V_232;
if ( F_74 ( V_13 , V_42 , V_188 , V_11 , V_148 ) < 0 ) {
F_81 ( & V_225 -> V_229 ) ;
goto V_233;
}
V_232:
if ( ! ( V_11 -> V_219 & V_221 ) )
goto V_230;
if ( F_76 ( V_42 , V_13 , V_188 , V_11 , V_148 ) < 0 ) {
F_81 ( & V_225 -> V_229 ) ;
goto V_233;
}
V_230:
V_188 -> args [ 3 ] = 0 ;
V_188 -> args [ 4 ] = 0 ;
++ V_216 ;
}
F_81 ( & V_225 -> V_229 ) ;
V_218 = 0 ;
V_188 -> args [ 3 ] = 0 ;
V_188 -> args [ 4 ] = 0 ;
}
V_222:
V_188 -> args [ 0 ] = 1 ;
V_217 = V_216 = V_218 = 0 ;
}
if ( ! ( V_11 -> V_219 & ~ ( V_220 | V_221 ) ) )
goto V_88;
for ( V_215 = V_217 ; V_215 <= V_125 -> V_234 ; V_215 ++ ) {
struct V_235 * V_210 = & V_125 -> V_236 [ V_215 ] ;
T_5 * V_229 = F_85 ( V_125 , V_215 ) ;
struct V_226 * V_227 ;
struct V_12 * V_13 ;
V_216 = 0 ;
if ( F_86 ( & V_210 -> V_237 ) )
continue;
if ( V_215 > V_217 )
V_218 = 0 ;
F_77 ( V_229 ) ;
F_83 (sk, node, &head->chain) {
int V_238 , V_239 ;
if ( ! F_84 ( F_49 ( V_13 ) , V_127 ) )
continue;
if ( V_216 < V_218 )
goto V_240;
V_238 = ( V_13 -> V_66 == V_105 ) ?
F_41 ( V_13 ) -> V_114 : V_13 -> V_66 ;
if ( ! ( V_11 -> V_219 & ( 1 << V_238 ) ) )
goto V_240;
if ( V_11 -> V_130 != V_175 &&
V_13 -> V_15 != V_11 -> V_130 )
goto V_240;
if ( V_11 -> V_16 . V_17 != F_8 ( V_13 -> V_18 ) &&
V_11 -> V_16 . V_17 )
goto V_240;
if ( V_11 -> V_16 . V_19 != V_13 -> V_20 &&
V_11 -> V_16 . V_19 )
goto V_240;
F_75 () ;
if ( ! F_68 ( V_148 , V_13 ) )
goto V_240;
V_239 = F_47 ( V_13 , V_42 , V_11 ,
F_54 ( F_55 ( V_188 -> V_42 ) . V_13 ) ,
F_55 ( V_188 -> V_42 ) . V_47 ,
V_188 -> V_58 -> V_134 , V_189 ,
V_188 -> V_58 ) ;
if ( V_239 < 0 ) {
F_81 ( V_229 ) ;
goto V_233;
}
V_240:
++ V_216 ;
}
F_81 ( V_229 ) ;
}
V_233:
V_188 -> args [ 1 ] = V_215 ;
V_188 -> args [ 2 ] = V_216 ;
V_88:
;
}
static int F_87 ( struct V_41 * V_42 , struct V_187 * V_188 ,
const struct V_43 * V_11 ,
struct V_59 * V_148 )
{
const struct V_1 * V_9 ;
int V_102 = 0 ;
V_9 = F_1 ( V_11 -> V_62 ) ;
if ( ! F_61 ( V_9 ) )
V_9 -> V_241 ( V_42 , V_188 , V_11 , V_148 ) ;
else
V_102 = F_62 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_102 ? : V_42 -> V_149 ;
}
static int F_88 ( struct V_41 * V_42 , struct V_187 * V_188 )
{
int V_242 = sizeof( struct V_43 ) ;
struct V_59 * V_148 = NULL ;
if ( F_89 ( V_188 -> V_58 , V_242 ) )
V_148 = F_90 ( V_188 -> V_58 , V_242 , V_243 ) ;
return F_87 ( V_42 , V_188 , F_17 ( V_188 -> V_58 ) , V_148 ) ;
}
static int F_91 ( int type )
{
switch ( type ) {
case V_244 :
return V_245 ;
case V_246 :
return V_247 ;
default:
return 0 ;
}
}
static int F_92 ( struct V_41 * V_42 ,
struct V_187 * V_188 )
{
struct V_248 * V_249 = F_17 ( V_188 -> V_58 ) ;
int V_242 = sizeof( struct V_248 ) ;
struct V_43 V_44 ;
struct V_59 * V_148 = NULL ;
V_44 . V_130 = V_175 ;
V_44 . V_62 = F_91 ( V_188 -> V_58 -> V_63 ) ;
V_44 . V_57 = V_249 -> V_57 ;
V_44 . V_219 = V_249 -> V_219 ;
V_44 . V_16 = V_249 -> V_16 ;
if ( F_89 ( V_188 -> V_58 , V_242 ) )
V_148 = F_90 ( V_188 -> V_58 , V_242 , V_243 ) ;
return F_87 ( V_42 , V_188 , & V_44 , V_148 ) ;
}
static int F_93 ( struct V_41 * V_126 ,
const struct V_50 * V_58 )
{
struct V_248 * V_249 = F_17 ( V_58 ) ;
struct V_43 V_44 ;
V_44 . V_130 = V_249 -> V_14 ;
V_44 . V_62 = F_91 ( V_58 -> V_63 ) ;
V_44 . V_57 = V_249 -> V_57 ;
V_44 . V_219 = V_249 -> V_219 ;
V_44 . V_16 = V_249 -> V_16 ;
return F_60 ( V_126 , V_58 , & V_44 ) ;
}
static int F_94 ( struct V_41 * V_42 , struct V_50 * V_58 )
{
int V_242 = sizeof( struct V_248 ) ;
struct V_127 * V_127 = F_49 ( V_42 -> V_13 ) ;
if ( V_58 -> V_63 >= V_250 ||
F_95 ( V_58 ) < V_242 )
return - V_129 ;
if ( V_58 -> V_49 & V_251 ) {
if ( F_89 ( V_58 , V_242 ) ) {
struct V_59 * V_60 ;
V_60 = F_90 ( V_58 , V_242 ,
V_243 ) ;
if ( ! V_60 ||
F_66 ( V_60 ) < sizeof( struct V_151 ) ||
F_73 ( F_31 ( V_60 ) , F_66 ( V_60 ) ) )
return - V_129 ;
}
{
struct V_252 V_253 = {
. V_241 = F_92 ,
} ;
return F_96 ( V_127 -> V_135 , V_42 , V_58 , & V_253 ) ;
}
}
return F_93 ( V_42 , V_58 ) ;
}
static int F_97 ( struct V_41 * V_42 , struct V_50 * V_254 )
{
int V_242 = sizeof( struct V_43 ) ;
struct V_127 * V_127 = F_49 ( V_42 -> V_13 ) ;
if ( F_95 ( V_254 ) < V_242 )
return - V_129 ;
if ( V_254 -> V_49 & V_251 ) {
if ( F_89 ( V_254 , V_242 ) ) {
struct V_59 * V_60 ;
V_60 = F_90 ( V_254 , V_242 ,
V_243 ) ;
if ( ! V_60 ||
F_66 ( V_60 ) < sizeof( struct V_151 ) ||
F_73 ( F_31 ( V_60 ) , F_66 ( V_60 ) ) )
return - V_129 ;
}
{
struct V_252 V_253 = {
. V_241 = F_88 ,
} ;
return F_96 ( V_127 -> V_135 , V_42 , V_254 , & V_253 ) ;
}
}
return F_60 ( V_42 , V_254 , F_17 ( V_254 ) ) ;
}
int F_98 ( const struct V_1 * V_254 )
{
const T_6 type = V_254 -> V_255 ;
int V_102 = - V_129 ;
if ( type >= V_256 )
goto V_88;
F_3 ( & V_7 ) ;
V_102 = - V_257 ;
if ( ! V_3 [ type ] ) {
V_3 [ type ] = V_254 ;
V_102 = 0 ;
}
F_6 ( & V_7 ) ;
V_88:
return V_102 ;
}
void F_99 ( const struct V_1 * V_254 )
{
const T_6 type = V_254 -> V_255 ;
if ( type >= V_256 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_7 F_100 ( void )
{
const int V_258 = ( V_256 *
sizeof( struct V_1 * ) ) ;
int V_102 = - V_133 ;
V_3 = F_101 ( V_258 , V_132 ) ;
if ( ! V_3 )
goto V_88;
V_102 = F_102 ( & V_1 ) ;
if ( V_102 )
goto V_259;
V_102 = F_102 ( & V_260 ) ;
if ( V_102 )
goto V_261;
F_103 ( F_94 ) ;
V_88:
return V_102 ;
V_261:
F_104 ( & V_1 ) ;
V_259:
F_105 ( V_3 ) ;
goto V_88;
}
static void T_8 F_106 ( void )
{
F_104 ( & V_260 ) ;
F_104 ( & V_1 ) ;
F_107 ( F_94 ) ;
F_105 ( V_3 ) ;
}
