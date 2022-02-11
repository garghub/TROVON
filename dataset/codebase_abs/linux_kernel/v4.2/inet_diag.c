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
int F_49 ( struct V_128 * V_129 ,
struct V_41 * V_130 ,
const struct V_50 * V_58 ,
const struct V_43 * V_44 )
{
struct V_131 * V_131 = F_50 ( V_130 -> V_13 ) ;
struct V_41 * V_132 ;
struct V_12 * V_13 ;
int V_106 ;
V_106 = - V_133 ;
if ( V_44 -> V_134 == V_6 )
V_13 = F_51 ( V_131 , V_129 , V_44 -> V_16 . V_29 [ 0 ] ,
V_44 -> V_16 . V_19 , V_44 -> V_16 . V_27 [ 0 ] ,
V_44 -> V_16 . V_17 , V_44 -> V_16 . V_21 ) ;
#if F_10 ( V_24 )
else if ( V_44 -> V_134 == V_25 )
V_13 = F_52 ( V_131 , V_129 ,
(struct V_26 * ) V_44 -> V_16 . V_29 ,
V_44 -> V_16 . V_19 ,
(struct V_26 * ) V_44 -> V_16 . V_27 ,
V_44 -> V_16 . V_17 ,
V_44 -> V_16 . V_21 ) ;
#endif
else
goto V_135;
V_106 = - V_8 ;
if ( ! V_13 )
goto V_135;
V_106 = F_53 ( V_13 , V_44 -> V_16 . V_23 ) ;
if ( V_106 )
goto V_91;
V_132 = F_54 ( F_11 () , V_136 ) ;
if ( ! V_132 ) {
V_106 = - V_137 ;
goto V_91;
}
V_106 = F_48 ( V_13 , V_132 , V_44 ,
F_55 ( F_56 ( V_130 ) . V_13 ) ,
F_56 ( V_130 ) . V_47 ,
V_58 -> V_138 , 0 , V_58 ) ;
if ( V_106 < 0 ) {
F_57 ( V_106 == - V_64 ) ;
F_58 ( V_132 ) ;
goto V_91;
}
V_106 = F_59 ( V_131 -> V_139 , V_132 , F_56 ( V_130 ) . V_47 ,
V_140 ) ;
if ( V_106 > 0 )
V_106 = 0 ;
V_91:
if ( V_13 )
F_60 ( V_13 ) ;
V_135:
return V_106 ;
}
static int F_61 ( struct V_41 * V_130 ,
const struct V_50 * V_58 ,
const struct V_43 * V_44 )
{
const struct V_1 * V_9 ;
int V_106 ;
V_9 = F_1 ( V_44 -> V_62 ) ;
if ( F_62 ( V_9 ) )
V_106 = F_63 ( V_9 ) ;
else
V_106 = V_9 -> V_141 ( V_130 , V_58 , V_44 ) ;
F_5 ( V_9 ) ;
return V_106 ;
}
static int F_64 ( const T_4 * V_142 , const T_4 * V_143 , int V_144 )
{
int V_145 = V_144 >> 5 ;
V_144 &= 0x1f ;
if ( V_145 ) {
if ( memcmp ( V_142 , V_143 , V_145 << 2 ) )
return 0 ;
}
if ( V_144 ) {
T_4 V_146 , V_147 ;
T_4 V_148 ;
V_146 = V_142 [ V_145 ] ;
V_147 = V_143 [ V_145 ] ;
V_148 = F_65 ( ( 0xffffffff ) << ( 32 - V_144 ) ) ;
if ( ( V_146 ^ V_147 ) & V_148 )
return 0 ;
}
return 1 ;
}
static int F_66 ( const struct V_59 * V_149 ,
const struct V_150 * V_151 )
{
const void * V_152 = F_32 ( V_149 ) ;
int V_153 = F_67 ( V_149 ) ;
while ( V_153 > 0 ) {
int V_154 = 1 ;
const struct V_155 * V_156 = V_152 ;
switch ( V_156 -> V_157 ) {
case V_158 :
break;
case V_159 :
V_154 = 0 ;
break;
case V_160 :
V_154 = V_151 -> V_161 >= V_156 [ 1 ] . V_162 ;
break;
case V_163 :
V_154 = V_151 -> V_161 <= V_156 [ 1 ] . V_162 ;
break;
case V_164 :
V_154 = V_151 -> V_165 >= V_156 [ 1 ] . V_162 ;
break;
case V_166 :
V_154 = V_151 -> V_165 <= V_156 [ 1 ] . V_162 ;
break;
case V_167 :
V_154 = ! ( V_151 -> V_168 & V_169 ) ;
break;
case V_170 :
case V_171 : {
const struct V_172 * V_173 ;
const T_4 * V_174 ;
V_173 = ( const struct V_172 * ) ( V_156 + 1 ) ;
if ( V_173 -> V_175 != - 1 &&
V_173 -> V_175 != ( V_156 -> V_157 == V_170 ?
V_151 -> V_161 : V_151 -> V_165 ) ) {
V_154 = 0 ;
break;
}
if ( V_156 -> V_157 == V_170 )
V_174 = V_151 -> V_176 ;
else
V_174 = V_151 -> V_177 ;
if ( V_173 -> V_178 != V_179 &&
V_173 -> V_178 != V_151 -> V_178 ) {
if ( V_151 -> V_178 == V_25 &&
V_173 -> V_178 == V_6 ) {
if ( V_174 [ 0 ] == 0 && V_174 [ 1 ] == 0 &&
V_174 [ 2 ] == F_65 ( 0xffff ) &&
F_64 ( V_174 + 3 ,
V_173 -> V_174 ,
V_173 -> V_180 ) )
break;
}
V_154 = 0 ;
break;
}
if ( V_173 -> V_180 == 0 )
break;
if ( F_64 ( V_174 , V_173 -> V_174 ,
V_173 -> V_180 ) )
break;
V_154 = 0 ;
break;
}
}
if ( V_154 ) {
V_153 -= V_156 -> V_154 ;
V_152 += V_156 -> V_154 ;
} else {
V_153 -= V_156 -> V_162 ;
V_152 += V_156 -> V_162 ;
}
}
return V_153 == 0 ;
}
static void F_68 ( struct V_150 * V_151 ,
const struct V_12 * V_13 )
{
#if F_10 ( V_24 )
if ( V_13 -> V_15 == V_25 ) {
V_151 -> V_176 = V_13 -> V_28 . V_181 ;
V_151 -> V_177 = V_13 -> V_30 . V_181 ;
} else
#endif
{
V_151 -> V_176 = & V_13 -> V_31 ;
V_151 -> V_177 = & V_13 -> V_32 ;
}
}
int F_69 ( const struct V_59 * V_152 , struct V_12 * V_13 )
{
struct V_52 * V_53 = F_14 ( V_13 ) ;
struct V_150 V_151 ;
if ( ! V_152 )
return 1 ;
V_151 . V_178 = V_13 -> V_15 ;
F_68 ( & V_151 , V_13 ) ;
V_151 . V_161 = V_53 -> V_182 ;
V_151 . V_165 = F_70 ( V_53 -> V_183 ) ;
V_151 . V_168 = F_18 ( V_13 ) ? V_13 -> V_184 : 0 ;
return F_66 ( V_152 , & V_151 ) ;
}
static int F_71 ( const void * V_152 , int V_153 , int V_185 )
{
while ( V_153 >= 0 ) {
const struct V_155 * V_156 = V_152 ;
if ( V_185 > V_153 )
return 0 ;
if ( V_185 == V_153 )
return 1 ;
if ( V_156 -> V_154 < 4 || V_156 -> V_154 & 3 )
return 0 ;
V_153 -= V_156 -> V_154 ;
V_152 += V_156 -> V_154 ;
}
return 0 ;
}
static bool F_72 ( const struct V_155 * V_156 , int V_153 ,
int * V_186 )
{
struct V_172 * V_173 ;
int V_187 ;
* V_186 += sizeof( struct V_172 ) ;
if ( V_153 < * V_186 )
return false ;
V_173 = (struct V_172 * ) ( V_156 + 1 ) ;
switch ( V_173 -> V_178 ) {
case V_179 :
V_187 = 0 ;
break;
case V_6 :
V_187 = sizeof( struct V_188 ) ;
break;
case V_25 :
V_187 = sizeof( struct V_26 ) ;
break;
default:
return false ;
}
* V_186 += V_187 ;
if ( V_153 < * V_186 )
return false ;
if ( V_173 -> V_180 > 8 * V_187 )
return false ;
return true ;
}
static bool F_73 ( const struct V_155 * V_156 ,
int V_153 , int * V_186 )
{
* V_186 += sizeof( struct V_155 ) ;
if ( V_153 < * V_186 )
return false ;
return true ;
}
static int F_74 ( const void * V_189 , int V_190 )
{
const void * V_152 = V_189 ;
int V_153 = V_190 ;
while ( V_153 > 0 ) {
int V_186 = sizeof( struct V_155 ) ;
const struct V_155 * V_156 = V_152 ;
switch ( V_156 -> V_157 ) {
case V_170 :
case V_171 :
if ( ! F_72 ( V_152 , V_153 , & V_186 ) )
return - V_133 ;
break;
case V_160 :
case V_163 :
case V_164 :
case V_166 :
if ( ! F_73 ( V_152 , V_153 , & V_186 ) )
return - V_133 ;
break;
case V_167 :
case V_159 :
case V_158 :
break;
default:
return - V_133 ;
}
if ( V_156 -> V_157 != V_158 ) {
if ( V_156 -> V_162 < V_186 || V_156 -> V_162 > V_153 + 4 || V_156 -> V_162 & 3 )
return - V_133 ;
if ( V_156 -> V_162 < V_153 &&
! F_71 ( V_189 , V_190 , V_153 - V_156 -> V_162 ) )
return - V_133 ;
}
if ( V_156 -> V_154 < V_186 || V_156 -> V_154 > V_153 + 4 || V_156 -> V_154 & 3 )
return - V_133 ;
V_152 += V_156 -> V_154 ;
V_153 -= V_156 -> V_154 ;
}
return V_153 == 0 ? 0 : - V_133 ;
}
static int F_75 ( struct V_12 * V_13 ,
struct V_41 * V_42 ,
struct V_191 * V_192 ,
const struct V_43 * V_11 ,
const struct V_59 * V_152 )
{
if ( ! F_69 ( V_152 , V_13 ) )
return 0 ;
return F_39 ( V_13 , V_42 , V_11 ,
F_55 ( F_56 ( V_192 -> V_42 ) . V_13 ) ,
F_56 ( V_192 -> V_42 ) . V_47 ,
V_192 -> V_58 -> V_138 , V_193 , V_192 -> V_58 ) ;
}
static void F_76 ( void )
{
F_46 ( F_47 ( struct V_113 , V_194 ) !=
F_47 ( struct V_12 , V_15 ) ) ;
F_46 ( F_47 ( struct V_113 , V_195 ) !=
F_47 ( struct V_52 , V_182 ) ) ;
F_46 ( F_47 ( struct V_113 , V_196 ) !=
F_47 ( struct V_52 , V_183 ) ) ;
F_46 ( F_47 ( struct V_113 , V_197 ) !=
F_47 ( struct V_52 , V_198 ) ) ;
F_46 ( F_47 ( struct V_113 , V_199 ) !=
F_47 ( struct V_52 , V_200 ) ) ;
#if F_10 ( V_24 )
F_46 ( F_47 ( struct V_113 , V_201 ) !=
F_47 ( struct V_12 , V_28 ) ) ;
F_46 ( F_47 ( struct V_113 , V_202 ) !=
F_47 ( struct V_12 , V_30 ) ) ;
#endif
}
static int F_77 ( struct V_41 * V_42 , struct V_12 * V_13 ,
struct V_191 * V_192 ,
const struct V_43 * V_11 ,
const struct V_59 * V_152 )
{
struct V_39 * V_40 = F_40 ( V_13 ) ;
struct V_52 * V_53 = F_14 ( V_13 ) ;
struct V_150 V_151 ;
int V_203 , V_204 , V_205 , V_206 ;
struct V_207 * V_208 ;
int V_106 = 0 ;
V_204 = V_192 -> args [ 3 ] ;
V_206 = V_192 -> args [ 4 ] ;
if ( V_204 > 0 )
V_204 -- ;
V_151 . V_178 = V_13 -> V_15 ;
F_78 ( & V_40 -> V_209 . V_210 ) ;
V_208 = V_40 -> V_209 . V_211 ;
if ( ! V_208 || ! F_79 ( V_208 ) )
goto V_91;
if ( V_152 ) {
V_151 . V_161 = V_53 -> V_182 ;
V_151 . V_168 = V_13 -> V_184 ;
}
for ( V_203 = V_204 ; V_203 < V_208 -> V_212 ; V_203 ++ ) {
struct V_213 * V_44 , * V_214 = V_208 -> V_215 [ V_203 ] ;
V_205 = 0 ;
for ( V_44 = V_214 ; V_44 ; V_205 ++ , V_44 = V_44 -> V_216 ) {
struct V_123 * V_217 = F_80 ( V_44 ) ;
if ( V_205 < V_206 )
continue;
if ( V_11 -> V_16 . V_19 != V_217 -> V_218 &&
V_11 -> V_16 . V_19 )
continue;
if ( V_152 ) {
F_68 ( & V_151 , F_81 ( V_44 ) ) ;
V_151 . V_165 = F_70 ( V_217 -> V_218 ) ;
if ( ! F_66 ( V_152 , & V_151 ) )
continue;
}
V_106 = F_44 ( F_81 ( V_44 ) , V_42 ,
F_56 ( V_192 -> V_42 ) . V_47 ,
V_192 -> V_58 -> V_138 ,
V_193 , V_192 -> V_58 ) ;
if ( V_106 < 0 ) {
V_192 -> args [ 3 ] = V_203 + 1 ;
V_192 -> args [ 4 ] = V_205 ;
goto V_91;
}
}
V_206 = 0 ;
}
V_91:
F_82 ( & V_40 -> V_209 . V_210 ) ;
return V_106 ;
}
void F_83 ( struct V_128 * V_129 , struct V_41 * V_42 ,
struct V_191 * V_192 ,
const struct V_43 * V_11 , struct V_59 * V_152 )
{
struct V_131 * V_131 = F_50 ( V_42 -> V_13 ) ;
int V_219 , V_220 , V_221 , V_222 ;
V_221 = V_192 -> args [ 1 ] ;
V_222 = V_220 = V_192 -> args [ 2 ] ;
if ( V_192 -> args [ 0 ] == 0 ) {
if ( ! ( V_11 -> V_223 & ( V_76 | V_224 ) ) )
goto V_225;
for ( V_219 = V_221 ; V_219 < V_226 ; V_219 ++ ) {
struct V_227 * V_228 ;
struct V_229 * V_230 ;
struct V_12 * V_13 ;
V_220 = 0 ;
V_228 = & V_129 -> V_231 [ V_219 ] ;
F_84 ( & V_228 -> V_232 ) ;
F_85 (sk, node, &ilb->head) {
struct V_52 * V_53 = F_14 ( V_13 ) ;
if ( ! F_86 ( F_50 ( V_13 ) , V_131 ) )
continue;
if ( V_220 < V_222 ) {
V_220 ++ ;
continue;
}
if ( V_11 -> V_134 != V_179 &&
V_13 -> V_15 != V_11 -> V_134 )
goto V_233;
if ( V_11 -> V_16 . V_17 != V_53 -> V_234 &&
V_11 -> V_16 . V_17 )
goto V_233;
if ( ! ( V_11 -> V_223 & V_76 ) ||
V_11 -> V_16 . V_19 ||
V_192 -> args [ 3 ] > 0 )
goto V_235;
if ( F_75 ( V_13 , V_42 , V_192 , V_11 , V_152 ) < 0 ) {
F_87 ( & V_228 -> V_232 ) ;
goto V_236;
}
V_235:
if ( ! ( V_11 -> V_223 & V_224 ) )
goto V_233;
if ( F_77 ( V_42 , V_13 , V_192 , V_11 , V_152 ) < 0 ) {
F_87 ( & V_228 -> V_232 ) ;
goto V_236;
}
V_233:
V_192 -> args [ 3 ] = 0 ;
V_192 -> args [ 4 ] = 0 ;
++ V_220 ;
}
F_87 ( & V_228 -> V_232 ) ;
V_222 = 0 ;
V_192 -> args [ 3 ] = 0 ;
V_192 -> args [ 4 ] = 0 ;
}
V_225:
V_192 -> args [ 0 ] = 1 ;
V_221 = V_220 = V_222 = 0 ;
}
if ( ! ( V_11 -> V_223 & ~ ( V_76 | V_224 ) ) )
goto V_91;
for ( V_219 = V_221 ; V_219 <= V_129 -> V_237 ; V_219 ++ ) {
struct V_238 * V_214 = & V_129 -> V_239 [ V_219 ] ;
T_5 * V_232 = F_88 ( V_129 , V_219 ) ;
struct V_229 * V_230 ;
struct V_12 * V_13 ;
V_220 = 0 ;
if ( F_89 ( & V_214 -> V_240 ) )
continue;
if ( V_219 > V_221 )
V_222 = 0 ;
F_84 ( V_232 ) ;
F_85 (sk, node, &head->chain) {
int V_241 , V_242 ;
if ( ! F_86 ( F_50 ( V_13 ) , V_131 ) )
continue;
if ( V_220 < V_222 )
goto V_243;
V_241 = ( V_13 -> V_66 == V_109 ) ?
F_42 ( V_13 ) -> V_118 : V_13 -> V_66 ;
if ( ! ( V_11 -> V_223 & ( 1 << V_241 ) ) )
goto V_243;
if ( V_11 -> V_134 != V_179 &&
V_13 -> V_15 != V_11 -> V_134 )
goto V_243;
if ( V_11 -> V_16 . V_17 != F_8 ( V_13 -> V_18 ) &&
V_11 -> V_16 . V_17 )
goto V_243;
if ( V_11 -> V_16 . V_19 != V_13 -> V_20 &&
V_11 -> V_16 . V_19 )
goto V_243;
F_76 () ;
if ( ! F_69 ( V_152 , V_13 ) )
goto V_243;
V_242 = F_48 ( V_13 , V_42 , V_11 ,
F_55 ( F_56 ( V_192 -> V_42 ) . V_13 ) ,
F_56 ( V_192 -> V_42 ) . V_47 ,
V_192 -> V_58 -> V_138 , V_193 ,
V_192 -> V_58 ) ;
if ( V_242 < 0 ) {
F_87 ( V_232 ) ;
goto V_236;
}
V_243:
++ V_220 ;
}
F_87 ( V_232 ) ;
}
V_236:
V_192 -> args [ 1 ] = V_219 ;
V_192 -> args [ 2 ] = V_220 ;
V_91:
;
}
static int F_90 ( struct V_41 * V_42 , struct V_191 * V_192 ,
const struct V_43 * V_11 ,
struct V_59 * V_152 )
{
const struct V_1 * V_9 ;
int V_106 = 0 ;
V_9 = F_1 ( V_11 -> V_62 ) ;
if ( ! F_62 ( V_9 ) )
V_9 -> V_244 ( V_42 , V_192 , V_11 , V_152 ) ;
else
V_106 = F_63 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_106 ? : V_42 -> V_153 ;
}
static int F_91 ( struct V_41 * V_42 , struct V_191 * V_192 )
{
int V_245 = sizeof( struct V_43 ) ;
struct V_59 * V_152 = NULL ;
if ( F_92 ( V_192 -> V_58 , V_245 ) )
V_152 = F_93 ( V_192 -> V_58 , V_245 , V_246 ) ;
return F_90 ( V_42 , V_192 , F_17 ( V_192 -> V_58 ) , V_152 ) ;
}
static int F_94 ( int type )
{
switch ( type ) {
case V_247 :
return V_248 ;
case V_249 :
return V_250 ;
default:
return 0 ;
}
}
static int F_95 ( struct V_41 * V_42 ,
struct V_191 * V_192 )
{
struct V_251 * V_252 = F_17 ( V_192 -> V_58 ) ;
int V_245 = sizeof( struct V_251 ) ;
struct V_43 V_44 ;
struct V_59 * V_152 = NULL ;
V_44 . V_134 = V_179 ;
V_44 . V_62 = F_94 ( V_192 -> V_58 -> V_63 ) ;
V_44 . V_57 = V_252 -> V_57 ;
V_44 . V_223 = V_252 -> V_223 ;
V_44 . V_16 = V_252 -> V_16 ;
if ( F_92 ( V_192 -> V_58 , V_245 ) )
V_152 = F_93 ( V_192 -> V_58 , V_245 , V_246 ) ;
return F_90 ( V_42 , V_192 , & V_44 , V_152 ) ;
}
static int F_96 ( struct V_41 * V_130 ,
const struct V_50 * V_58 )
{
struct V_251 * V_252 = F_17 ( V_58 ) ;
struct V_43 V_44 ;
V_44 . V_134 = V_252 -> V_14 ;
V_44 . V_62 = F_94 ( V_58 -> V_63 ) ;
V_44 . V_57 = V_252 -> V_57 ;
V_44 . V_223 = V_252 -> V_223 ;
V_44 . V_16 = V_252 -> V_16 ;
return F_61 ( V_130 , V_58 , & V_44 ) ;
}
static int F_97 ( struct V_41 * V_42 , struct V_50 * V_58 )
{
int V_245 = sizeof( struct V_251 ) ;
struct V_131 * V_131 = F_50 ( V_42 -> V_13 ) ;
if ( V_58 -> V_63 >= V_253 ||
F_98 ( V_58 ) < V_245 )
return - V_133 ;
if ( V_58 -> V_49 & V_254 ) {
if ( F_92 ( V_58 , V_245 ) ) {
struct V_59 * V_60 ;
V_60 = F_93 ( V_58 , V_245 ,
V_246 ) ;
if ( ! V_60 ||
F_67 ( V_60 ) < sizeof( struct V_155 ) ||
F_74 ( F_32 ( V_60 ) , F_67 ( V_60 ) ) )
return - V_133 ;
}
{
struct V_255 V_256 = {
. V_244 = F_95 ,
} ;
return F_99 ( V_131 -> V_139 , V_42 , V_58 , & V_256 ) ;
}
}
return F_96 ( V_42 , V_58 ) ;
}
static int F_100 ( struct V_41 * V_42 , struct V_50 * V_257 )
{
int V_245 = sizeof( struct V_43 ) ;
struct V_131 * V_131 = F_50 ( V_42 -> V_13 ) ;
if ( F_98 ( V_257 ) < V_245 )
return - V_133 ;
if ( V_257 -> V_49 & V_254 ) {
if ( F_92 ( V_257 , V_245 ) ) {
struct V_59 * V_60 ;
V_60 = F_93 ( V_257 , V_245 ,
V_246 ) ;
if ( ! V_60 ||
F_67 ( V_60 ) < sizeof( struct V_155 ) ||
F_74 ( F_32 ( V_60 ) , F_67 ( V_60 ) ) )
return - V_133 ;
}
{
struct V_255 V_256 = {
. V_244 = F_91 ,
} ;
return F_99 ( V_131 -> V_139 , V_42 , V_257 , & V_256 ) ;
}
}
return F_61 ( V_42 , V_257 , F_17 ( V_257 ) ) ;
}
static
int F_101 ( struct V_41 * V_42 , struct V_12 * V_13 )
{
const struct V_1 * V_9 ;
struct V_50 * V_58 ;
struct V_59 * V_60 ;
struct V_10 * V_11 ;
void * V_61 = NULL ;
int V_106 = 0 ;
V_58 = F_16 ( V_42 , 0 , 0 , V_258 , sizeof( * V_11 ) , 0 ) ;
if ( ! V_58 )
return - V_137 ;
V_11 = F_17 ( V_58 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_7 ( V_11 , V_13 ) ;
if ( V_13 -> V_259 == V_260 || V_13 -> V_259 == V_261 )
V_11 -> V_16 . V_17 = F_14 ( V_13 ) -> V_234 ;
V_11 -> V_65 = V_13 -> V_66 ;
if ( ( V_106 = F_19 ( V_42 , V_262 , V_13 -> V_263 ) ) ) {
F_38 ( V_42 , V_58 ) ;
return V_106 ;
}
V_9 = F_1 ( V_13 -> V_263 ) ;
if ( F_62 ( V_9 ) ) {
F_5 ( V_9 ) ;
F_38 ( V_42 , V_58 ) ;
return F_63 ( V_9 ) ;
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
int F_102 ( const struct V_1 * V_257 )
{
const T_6 type = V_257 -> V_264 ;
int V_106 = - V_133 ;
if ( type >= V_265 )
goto V_91;
F_3 ( & V_7 ) ;
V_106 = - V_266 ;
if ( ! V_3 [ type ] ) {
V_3 [ type ] = V_257 ;
V_106 = 0 ;
}
F_6 ( & V_7 ) ;
V_91:
return V_106 ;
}
void F_103 ( const struct V_1 * V_257 )
{
const T_6 type = V_257 -> V_264 ;
if ( type >= V_265 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_7 F_104 ( void )
{
const int V_267 = ( V_265 *
sizeof( struct V_1 * ) ) ;
int V_106 = - V_137 ;
V_3 = F_105 ( V_267 , V_136 ) ;
if ( ! V_3 )
goto V_91;
V_106 = F_106 ( & V_1 ) ;
if ( V_106 )
goto V_268;
V_106 = F_106 ( & V_269 ) ;
if ( V_106 )
goto V_270;
F_107 ( F_97 ) ;
V_91:
return V_106 ;
V_270:
F_108 ( & V_1 ) ;
V_268:
F_109 ( V_3 ) ;
goto V_91;
}
static void T_8 F_110 ( void )
{
F_108 ( & V_269 ) ;
F_108 ( & V_1 ) ;
F_111 ( F_97 ) ;
F_109 ( V_3 ) ;
}
