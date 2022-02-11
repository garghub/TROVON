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
static inline void F_5 (
const struct V_1 * V_9 )
{
F_6 ( & V_7 ) ;
}
static T_1 F_7 ( void )
{
return F_8 ( sizeof( struct V_10 ) )
+ F_8 ( 1 )
+ F_8 ( 1 )
+ F_8 ( 1 )
+ F_8 ( sizeof( struct V_11 ) )
+ F_8 ( sizeof( struct V_12 ) )
+ F_8 ( V_13 * sizeof( V_14 ) )
+ F_8 ( V_15 )
+ F_8 ( sizeof( struct V_16 ) )
+ 64 ;
}
int F_9 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 , struct V_23 * V_24 ,
struct V_25 * V_26 ,
V_14 V_27 , V_14 V_28 , T_2 V_29 ,
const struct V_30 * V_31 )
{
const struct V_32 * V_33 = F_10 ( V_18 ) ;
struct V_12 * V_34 ;
struct V_30 * V_35 ;
struct V_36 * V_37 ;
void * V_38 = NULL ;
const struct V_1 * V_9 ;
int V_39 = V_24 -> V_40 ;
V_9 = V_3 [ V_24 -> V_41 ] ;
F_11 ( V_9 == NULL ) ;
V_35 = F_12 ( V_22 , V_27 , V_28 , V_31 -> V_42 , sizeof( * V_34 ) ,
V_29 ) ;
if ( ! V_35 )
return - V_43 ;
V_34 = F_13 ( V_35 ) ;
F_11 ( V_18 -> V_44 == V_45 ) ;
V_34 -> V_46 = V_18 -> V_47 ;
V_34 -> V_48 = V_18 -> V_44 ;
V_34 -> V_49 = 0 ;
V_34 -> V_50 = 0 ;
V_34 -> V_51 . V_52 = V_18 -> V_53 ;
F_14 ( V_18 , V_34 -> V_51 . V_54 ) ;
V_34 -> V_51 . V_55 = V_33 -> V_56 ;
V_34 -> V_51 . V_57 = V_33 -> V_58 ;
memset ( & V_34 -> V_51 . V_59 , 0 , sizeof( V_34 -> V_51 . V_59 ) ) ;
memset ( & V_34 -> V_51 . V_60 , 0 , sizeof( V_34 -> V_51 . V_60 ) ) ;
V_34 -> V_51 . V_59 [ 0 ] = V_33 -> V_61 ;
V_34 -> V_51 . V_60 [ 0 ] = V_33 -> V_62 ;
if ( F_15 ( V_22 , V_63 , V_18 -> V_64 ) )
goto V_65;
if ( V_39 & ( 1 << ( V_66 - 1 ) ) )
if ( F_15 ( V_22 , V_66 , V_33 -> V_67 ) < 0 )
goto V_65;
#if F_16 ( V_68 )
if ( V_34 -> V_46 == V_69 ) {
* (struct V_70 * ) V_34 -> V_51 . V_59 = V_18 -> V_71 ;
* (struct V_70 * ) V_34 -> V_51 . V_60 = V_18 -> V_72 ;
if ( V_39 & ( 1 << ( V_73 - 1 ) ) )
if ( F_15 ( V_22 , V_73 ,
F_17 ( V_18 ) -> V_74 ) < 0 )
goto V_65;
}
#endif
V_34 -> V_75 = F_18 ( V_26 , F_19 ( V_18 ) ) ;
V_34 -> V_76 = F_20 ( V_18 ) ;
if ( V_39 & ( 1 << ( V_77 - 1 ) ) ) {
struct V_11 V_78 = {
. V_79 = F_21 ( V_18 ) ,
. V_80 = V_18 -> V_81 ,
. V_82 = V_18 -> V_83 ,
. V_84 = F_22 ( V_18 ) ,
} ;
if ( F_23 ( V_22 , V_77 , sizeof( V_78 ) , & V_78 ) < 0 )
goto V_65;
}
if ( V_39 & ( 1 << ( V_85 - 1 ) ) )
if ( F_24 ( V_18 , V_22 , V_85 ) )
goto V_65;
if ( V_20 == NULL ) {
V_9 -> V_86 ( V_18 , V_34 , NULL ) ;
goto V_87;
}
#define F_25 ( T_3 ) DIV_ROUND_UP((tmo - jiffies) * 1000, HZ)
if ( V_20 -> V_88 == V_89 ||
V_20 -> V_88 == V_90 ||
V_20 -> V_88 == V_91 ) {
V_34 -> V_49 = 1 ;
V_34 -> V_50 = V_20 -> V_92 ;
V_34 -> V_93 = F_25 ( V_20 -> V_94 ) ;
} else if ( V_20 -> V_88 == V_95 ) {
V_34 -> V_49 = 4 ;
V_34 -> V_50 = V_20 -> V_96 ;
V_34 -> V_93 = F_25 ( V_20 -> V_94 ) ;
} else if ( F_26 ( & V_18 -> V_97 ) ) {
V_34 -> V_49 = 2 ;
V_34 -> V_50 = V_20 -> V_96 ;
V_34 -> V_93 = F_25 ( V_18 -> V_97 . V_98 ) ;
} else {
V_34 -> V_49 = 0 ;
V_34 -> V_93 = 0 ;
}
#undef F_25
if ( V_39 & ( 1 << ( V_99 - 1 ) ) ) {
V_37 = F_27 ( V_22 , V_99 ,
sizeof( struct V_10 ) ) ;
if ( ! V_37 )
goto V_65;
V_38 = F_28 ( V_37 ) ;
}
if ( ( V_39 & ( 1 << ( V_100 - 1 ) ) ) && V_20 -> V_101 )
if ( F_29 ( V_22 , V_100 ,
V_20 -> V_101 -> V_102 ) < 0 )
goto V_65;
V_9 -> V_86 ( V_18 , V_34 , V_38 ) ;
if ( V_18 -> V_44 < V_45 &&
V_20 -> V_101 && V_20 -> V_101 -> V_103 )
V_20 -> V_101 -> V_103 ( V_18 , V_39 , V_22 ) ;
V_87:
F_30 ( V_22 , V_35 ) ;
return 0 ;
V_65:
F_31 ( V_22 , V_35 ) ;
return - V_43 ;
}
static int F_32 ( struct V_17 * V_18 ,
struct V_21 * V_22 , struct V_23 * V_24 ,
struct V_25 * V_26 ,
V_14 V_27 , V_14 V_28 , T_2 V_29 ,
const struct V_30 * V_31 )
{
return F_9 ( V_18 , F_33 ( V_18 ) ,
V_22 , V_24 , V_26 , V_27 , V_28 , V_29 , V_31 ) ;
}
static int F_34 ( struct V_104 * V_105 ,
struct V_21 * V_22 , struct V_23 * V_24 ,
V_14 V_27 , V_14 V_28 , T_2 V_29 ,
const struct V_30 * V_31 )
{
T_4 T_3 ;
struct V_12 * V_34 ;
struct V_30 * V_35 ;
V_35 = F_12 ( V_22 , V_27 , V_28 , V_31 -> V_42 , sizeof( * V_34 ) ,
V_29 ) ;
if ( ! V_35 )
return - V_43 ;
V_34 = F_13 ( V_35 ) ;
F_11 ( V_105 -> V_106 != V_45 ) ;
T_3 = V_105 -> V_107 - F_35 () ;
if ( T_3 < 0 )
T_3 = 0 ;
V_34 -> V_46 = V_105 -> V_108 ;
V_34 -> V_50 = 0 ;
V_34 -> V_51 . V_52 = V_105 -> V_109 ;
F_14 ( V_105 , V_34 -> V_51 . V_54 ) ;
V_34 -> V_51 . V_55 = V_105 -> V_110 ;
V_34 -> V_51 . V_57 = V_105 -> V_111 ;
memset ( & V_34 -> V_51 . V_59 , 0 , sizeof( V_34 -> V_51 . V_59 ) ) ;
memset ( & V_34 -> V_51 . V_60 , 0 , sizeof( V_34 -> V_51 . V_60 ) ) ;
V_34 -> V_51 . V_59 [ 0 ] = V_105 -> V_112 ;
V_34 -> V_51 . V_60 [ 0 ] = V_105 -> V_113 ;
V_34 -> V_48 = V_105 -> V_114 ;
V_34 -> V_49 = 3 ;
V_34 -> V_93 = F_36 ( T_3 ) ;
V_34 -> V_115 = 0 ;
V_34 -> V_116 = 0 ;
V_34 -> V_75 = 0 ;
V_34 -> V_76 = 0 ;
#if F_16 ( V_68 )
if ( V_105 -> V_108 == V_69 ) {
* (struct V_70 * ) V_34 -> V_51 . V_59 = V_105 -> V_117 ;
* (struct V_70 * ) V_34 -> V_51 . V_60 = V_105 -> V_118 ;
}
#endif
F_30 ( V_22 , V_35 ) ;
return 0 ;
}
static int F_37 ( struct V_17 * V_18 , struct V_21 * V_22 ,
struct V_23 * V_34 ,
struct V_25 * V_26 ,
V_14 V_27 , V_14 V_28 , T_2 V_29 ,
const struct V_30 * V_31 )
{
if ( V_18 -> V_44 == V_45 )
return F_34 ( F_38 ( V_18 ) , V_22 , V_34 , V_27 , V_28 ,
V_29 , V_31 ) ;
return F_32 ( V_18 , V_22 , V_34 , V_26 , V_27 , V_28 ,
V_29 , V_31 ) ;
}
int F_39 ( struct V_119 * V_120 , struct V_21 * V_121 ,
const struct V_30 * V_35 , struct V_23 * V_24 )
{
int V_122 ;
struct V_17 * V_18 ;
struct V_21 * V_123 ;
struct V_124 * V_124 = F_40 ( V_121 -> V_18 ) ;
V_122 = - V_125 ;
if ( V_24 -> V_126 == V_6 ) {
V_18 = F_41 ( V_124 , V_120 , V_24 -> V_51 . V_60 [ 0 ] ,
V_24 -> V_51 . V_57 , V_24 -> V_51 . V_59 [ 0 ] ,
V_24 -> V_51 . V_55 , V_24 -> V_51 . V_52 ) ;
}
#if F_16 ( V_68 )
else if ( V_24 -> V_126 == V_69 ) {
V_18 = F_42 ( V_124 , V_120 ,
(struct V_70 * ) V_24 -> V_51 . V_60 ,
V_24 -> V_51 . V_57 ,
(struct V_70 * ) V_24 -> V_51 . V_59 ,
V_24 -> V_51 . V_55 ,
V_24 -> V_51 . V_52 ) ;
}
#endif
else {
goto V_127;
}
V_122 = - V_8 ;
if ( V_18 == NULL )
goto V_127;
V_122 = F_43 ( V_18 , V_24 -> V_51 . V_54 ) ;
if ( V_122 )
goto V_87;
V_123 = F_44 ( F_7 () , V_128 ) ;
if ( ! V_123 ) {
V_122 = - V_129 ;
goto V_87;
}
V_122 = F_37 ( V_18 , V_123 , V_24 ,
F_45 ( F_46 ( V_121 ) . V_18 ) ,
F_46 ( V_121 ) . V_27 ,
V_35 -> V_130 , 0 , V_35 ) ;
if ( V_122 < 0 ) {
F_47 ( V_122 == - V_43 ) ;
F_48 ( V_123 ) ;
goto V_87;
}
V_122 = F_49 ( V_124 -> V_131 , V_123 , F_46 ( V_121 ) . V_27 ,
V_132 ) ;
if ( V_122 > 0 )
V_122 = 0 ;
V_87:
if ( V_18 )
F_50 ( V_18 ) ;
V_127:
return V_122 ;
}
static int F_51 ( struct V_21 * V_121 ,
const struct V_30 * V_35 ,
struct V_23 * V_24 )
{
const struct V_1 * V_9 ;
int V_122 ;
V_9 = F_1 ( V_24 -> V_41 ) ;
if ( F_52 ( V_9 ) )
V_122 = F_53 ( V_9 ) ;
else
V_122 = V_9 -> V_133 ( V_121 , V_35 , V_24 ) ;
F_5 ( V_9 ) ;
return V_122 ;
}
static int F_54 ( const T_5 * V_134 , const T_5 * V_135 , int V_136 )
{
int V_137 = V_136 >> 5 ;
V_136 &= 0x1f ;
if ( V_137 ) {
if ( memcmp ( V_134 , V_135 , V_137 << 2 ) )
return 0 ;
}
if ( V_136 ) {
T_5 V_138 , V_139 ;
T_5 V_140 ;
V_138 = V_134 [ V_137 ] ;
V_139 = V_135 [ V_137 ] ;
V_140 = F_55 ( ( 0xffffffff ) << ( 32 - V_136 ) ) ;
if ( ( V_138 ^ V_139 ) & V_140 )
return 0 ;
}
return 1 ;
}
static int F_56 ( const struct V_36 * V_141 ,
const struct V_142 * V_143 )
{
const void * V_144 = F_28 ( V_141 ) ;
int V_145 = F_57 ( V_141 ) ;
while ( V_145 > 0 ) {
int V_146 = 1 ;
const struct V_147 * V_148 = V_144 ;
switch ( V_148 -> V_149 ) {
case V_150 :
break;
case V_151 :
V_146 = 0 ;
break;
case V_152 :
V_146 = V_143 -> V_153 >= V_148 [ 1 ] . V_154 ;
break;
case V_155 :
V_146 = V_143 -> V_153 <= V_148 [ 1 ] . V_154 ;
break;
case V_156 :
V_146 = V_143 -> V_157 >= V_148 [ 1 ] . V_154 ;
break;
case V_158 :
V_146 = V_143 -> V_157 <= V_148 [ 1 ] . V_154 ;
break;
case V_159 :
V_146 = ! ( V_143 -> V_160 & V_161 ) ;
break;
case V_162 :
case V_163 : {
struct V_164 * V_165 ;
T_5 * V_166 ;
V_165 = (struct V_164 * ) ( V_148 + 1 ) ;
if ( V_165 -> V_167 != - 1 &&
V_165 -> V_167 != ( V_148 -> V_149 == V_162 ?
V_143 -> V_153 : V_143 -> V_157 ) ) {
V_146 = 0 ;
break;
}
if ( V_148 -> V_149 == V_162 )
V_166 = V_143 -> V_168 ;
else
V_166 = V_143 -> V_169 ;
if ( V_165 -> V_170 != V_171 &&
V_165 -> V_170 != V_143 -> V_170 ) {
if ( V_143 -> V_170 == V_69 &&
V_165 -> V_170 == V_6 ) {
if ( V_166 [ 0 ] == 0 && V_166 [ 1 ] == 0 &&
V_166 [ 2 ] == F_55 ( 0xffff ) &&
F_54 ( V_166 + 3 ,
V_165 -> V_166 ,
V_165 -> V_172 ) )
break;
}
V_146 = 0 ;
break;
}
if ( V_165 -> V_172 == 0 )
break;
if ( F_54 ( V_166 , V_165 -> V_166 ,
V_165 -> V_172 ) )
break;
V_146 = 0 ;
break;
}
}
if ( V_146 ) {
V_145 -= V_148 -> V_146 ;
V_144 += V_148 -> V_146 ;
} else {
V_145 -= V_148 -> V_154 ;
V_144 += V_148 -> V_154 ;
}
}
return V_145 == 0 ;
}
int F_58 ( const struct V_36 * V_144 , struct V_17 * V_18 )
{
struct V_142 V_143 ;
struct V_32 * V_33 = F_10 ( V_18 ) ;
if ( V_144 == NULL )
return 1 ;
V_143 . V_170 = V_18 -> V_47 ;
#if F_16 ( V_68 )
if ( V_143 . V_170 == V_69 ) {
V_143 . V_168 = V_18 -> V_71 . V_173 ;
V_143 . V_169 = V_18 -> V_72 . V_173 ;
} else
#endif
{
V_143 . V_168 = & V_33 -> V_61 ;
V_143 . V_169 = & V_33 -> V_62 ;
}
V_143 . V_153 = V_33 -> V_174 ;
V_143 . V_157 = F_59 ( V_33 -> V_58 ) ;
V_143 . V_160 = V_18 -> V_175 ;
return F_56 ( V_144 , & V_143 ) ;
}
static int F_60 ( const void * V_144 , int V_145 , int V_176 )
{
while ( V_145 >= 0 ) {
const struct V_147 * V_148 = V_144 ;
if ( V_176 > V_145 )
return 0 ;
if ( V_176 == V_145 )
return 1 ;
if ( V_148 -> V_146 < 4 || V_148 -> V_146 & 3 )
return 0 ;
V_145 -= V_148 -> V_146 ;
V_144 += V_148 -> V_146 ;
}
return 0 ;
}
static bool F_61 ( const struct V_147 * V_148 , int V_145 ,
int * V_177 )
{
int V_178 ;
struct V_164 * V_165 ;
* V_177 += sizeof( struct V_164 ) ;
if ( V_145 < * V_177 )
return false ;
V_165 = (struct V_164 * ) ( V_148 + 1 ) ;
switch ( V_165 -> V_170 ) {
case V_171 :
V_178 = 0 ;
break;
case V_6 :
V_178 = sizeof( struct V_179 ) ;
break;
case V_69 :
V_178 = sizeof( struct V_70 ) ;
break;
default:
return false ;
}
* V_177 += V_178 ;
if ( V_145 < * V_177 )
return false ;
if ( V_165 -> V_172 > 8 * V_178 )
return false ;
return true ;
}
static inline bool F_62 ( const struct V_147 * V_148 ,
int V_145 , int * V_177 )
{
* V_177 += sizeof( struct V_147 ) ;
if ( V_145 < * V_177 )
return false ;
return true ;
}
static int F_63 ( const void * V_180 , int V_181 )
{
const void * V_144 = V_180 ;
int V_145 = V_181 ;
while ( V_145 > 0 ) {
const struct V_147 * V_148 = V_144 ;
int V_177 = sizeof( struct V_147 ) ;
switch ( V_148 -> V_149 ) {
case V_162 :
case V_163 :
if ( ! F_61 ( V_144 , V_145 , & V_177 ) )
return - V_125 ;
break;
case V_152 :
case V_155 :
case V_156 :
case V_158 :
if ( ! F_62 ( V_144 , V_145 , & V_177 ) )
return - V_125 ;
break;
case V_159 :
case V_151 :
case V_150 :
break;
default:
return - V_125 ;
}
if ( V_148 -> V_149 != V_150 ) {
if ( V_148 -> V_154 < V_177 || V_148 -> V_154 > V_145 + 4 || V_148 -> V_154 & 3 )
return - V_125 ;
if ( V_148 -> V_154 < V_145 &&
! F_60 ( V_180 , V_181 , V_145 - V_148 -> V_154 ) )
return - V_125 ;
}
if ( V_148 -> V_146 < V_177 || V_148 -> V_146 > V_145 + 4 || V_148 -> V_146 & 3 )
return - V_125 ;
V_144 += V_148 -> V_146 ;
V_145 -= V_148 -> V_146 ;
}
return V_145 == 0 ? 0 : - V_125 ;
}
static int F_64 ( struct V_17 * V_18 ,
struct V_21 * V_22 ,
struct V_182 * V_183 ,
struct V_23 * V_34 ,
const struct V_36 * V_144 )
{
if ( ! F_58 ( V_144 , V_18 ) )
return 0 ;
return F_32 ( V_18 , V_22 , V_34 ,
F_45 ( F_46 ( V_183 -> V_22 ) . V_18 ) ,
F_46 ( V_183 -> V_22 ) . V_27 ,
V_183 -> V_35 -> V_130 , V_184 , V_183 -> V_35 ) ;
}
static int F_65 ( struct V_17 * V_18 ,
struct V_21 * V_22 ,
struct V_182 * V_183 ,
struct V_23 * V_34 ,
const struct V_36 * V_144 )
{
struct V_104 * V_105 = F_38 ( V_18 ) ;
if ( V_144 != NULL ) {
struct V_142 V_143 ;
V_143 . V_170 = V_105 -> V_108 ;
#if F_16 ( V_68 )
if ( V_105 -> V_108 == V_69 ) {
V_143 . V_168 = V_105 -> V_117 . V_173 ;
V_143 . V_169 = V_105 -> V_118 . V_173 ;
} else
#endif
{
V_143 . V_168 = & V_105 -> V_112 ;
V_143 . V_169 = & V_105 -> V_113 ;
}
V_143 . V_153 = V_105 -> V_185 ;
V_143 . V_157 = F_59 ( V_105 -> V_111 ) ;
V_143 . V_160 = 0 ;
if ( ! F_56 ( V_144 , & V_143 ) )
return 0 ;
}
return F_34 ( V_105 , V_22 , V_34 ,
F_46 ( V_183 -> V_22 ) . V_27 ,
V_183 -> V_35 -> V_130 , V_184 , V_183 -> V_35 ) ;
}
static inline void F_66 ( const struct V_17 * V_18 ,
const struct V_186 * V_24 ,
struct V_142 * V_143 )
{
struct V_187 * V_188 = F_67 ( V_24 ) ;
#if F_16 ( V_68 )
if ( V_18 -> V_47 == V_69 ) {
if ( V_24 -> V_189 -> V_170 == V_69 ) {
V_143 -> V_168 = V_188 -> V_190 . V_173 ;
V_143 -> V_169 = V_188 -> V_191 . V_173 ;
} else if ( V_24 -> V_189 -> V_170 == V_6 ) {
F_68 ( V_188 -> V_192 ,
& V_143 -> V_193 ) ;
F_68 ( V_188 -> V_194 ,
& V_143 -> V_195 ) ;
V_143 -> V_168 = V_143 -> V_193 . V_173 ;
V_143 -> V_169 = V_143 -> V_195 . V_173 ;
}
} else
#endif
{
V_143 -> V_168 = & V_188 -> V_192 ;
V_143 -> V_169 = & V_188 -> V_194 ;
}
}
static int F_69 ( struct V_21 * V_22 , struct V_17 * V_18 ,
struct V_186 * V_24 ,
struct V_25 * V_26 ,
V_14 V_27 , V_14 V_28 ,
const struct V_30 * V_31 )
{
const struct V_187 * V_188 = F_67 ( V_24 ) ;
struct V_32 * V_33 = F_10 ( V_18 ) ;
struct V_12 * V_34 ;
struct V_30 * V_35 ;
long T_3 ;
V_35 = F_12 ( V_22 , V_27 , V_28 , V_31 -> V_42 , sizeof( * V_34 ) ,
V_184 ) ;
if ( ! V_35 )
return - V_43 ;
V_34 = F_13 ( V_35 ) ;
V_34 -> V_46 = V_18 -> V_47 ;
V_34 -> V_48 = V_196 ;
V_34 -> V_49 = 1 ;
V_34 -> V_50 = V_24 -> V_197 ;
V_34 -> V_51 . V_52 = V_18 -> V_53 ;
F_14 ( V_24 , V_34 -> V_51 . V_54 ) ;
T_3 = V_24 -> V_98 - V_198 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_34 -> V_51 . V_55 = V_33 -> V_56 ;
V_34 -> V_51 . V_57 = V_188 -> V_199 ;
memset ( & V_34 -> V_51 . V_59 , 0 , sizeof( V_34 -> V_51 . V_59 ) ) ;
memset ( & V_34 -> V_51 . V_60 , 0 , sizeof( V_34 -> V_51 . V_60 ) ) ;
V_34 -> V_51 . V_59 [ 0 ] = V_188 -> V_192 ;
V_34 -> V_51 . V_60 [ 0 ] = V_188 -> V_194 ;
V_34 -> V_93 = F_36 ( T_3 ) ;
V_34 -> V_115 = 0 ;
V_34 -> V_116 = 0 ;
V_34 -> V_75 = F_18 ( V_26 , F_19 ( V_18 ) ) ;
V_34 -> V_76 = 0 ;
#if F_16 ( V_68 )
if ( V_34 -> V_46 == V_69 ) {
struct V_142 V_143 ;
F_66 ( V_18 , V_24 , & V_143 ) ;
memcpy ( V_34 -> V_51 . V_59 , V_143 . V_168 , sizeof( struct V_70 ) ) ;
memcpy ( V_34 -> V_51 . V_60 , V_143 . V_169 , sizeof( struct V_70 ) ) ;
}
#endif
F_30 ( V_22 , V_35 ) ;
return 0 ;
}
static int F_70 ( struct V_21 * V_22 , struct V_17 * V_18 ,
struct V_182 * V_183 ,
struct V_23 * V_34 ,
const struct V_36 * V_144 )
{
struct V_142 V_143 ;
struct V_19 * V_20 = F_33 ( V_18 ) ;
struct V_200 * V_201 ;
struct V_32 * V_33 = F_10 ( V_18 ) ;
int V_202 , V_203 ;
int V_204 , V_205 ;
int V_122 = 0 ;
V_203 = V_183 -> args [ 3 ] ;
V_205 = V_183 -> args [ 4 ] ;
if ( V_203 > 0 )
V_203 -- ;
V_143 . V_170 = V_18 -> V_47 ;
F_71 ( & V_20 -> V_206 . V_207 ) ;
V_201 = V_20 -> V_206 . V_208 ;
if ( ! V_201 || ! V_201 -> V_209 )
goto V_87;
if ( V_144 != NULL ) {
V_143 . V_153 = V_33 -> V_174 ;
V_143 . V_160 = V_18 -> V_175 ;
}
for ( V_202 = V_203 ; V_202 < V_201 -> V_210 ; V_202 ++ ) {
struct V_186 * V_24 , * V_211 = V_201 -> V_212 [ V_202 ] ;
V_204 = 0 ;
for ( V_24 = V_211 ; V_24 ; V_204 ++ , V_24 = V_24 -> V_213 ) {
struct V_187 * V_188 = F_67 ( V_24 ) ;
if ( V_204 < V_205 )
continue;
if ( V_34 -> V_51 . V_57 != V_188 -> V_199 &&
V_34 -> V_51 . V_57 )
continue;
if ( V_144 ) {
F_66 ( V_18 , V_24 , & V_143 ) ;
V_143 . V_157 = F_59 ( V_188 -> V_199 ) ;
if ( ! F_56 ( V_144 , & V_143 ) )
continue;
}
V_122 = F_69 ( V_22 , V_18 , V_24 ,
F_45 ( F_46 ( V_183 -> V_22 ) . V_18 ) ,
F_46 ( V_183 -> V_22 ) . V_27 ,
V_183 -> V_35 -> V_130 , V_183 -> V_35 ) ;
if ( V_122 < 0 ) {
V_183 -> args [ 3 ] = V_202 + 1 ;
V_183 -> args [ 4 ] = V_204 ;
goto V_87;
}
}
V_205 = 0 ;
}
V_87:
F_72 ( & V_20 -> V_206 . V_207 ) ;
return V_122 ;
}
void F_73 ( struct V_119 * V_120 , struct V_21 * V_22 ,
struct V_182 * V_183 , struct V_23 * V_34 , struct V_36 * V_144 )
{
int V_214 , V_215 ;
int V_216 , V_217 ;
struct V_124 * V_124 = F_40 ( V_22 -> V_18 ) ;
V_216 = V_183 -> args [ 1 ] ;
V_217 = V_215 = V_183 -> args [ 2 ] ;
if ( V_183 -> args [ 0 ] == 0 ) {
if ( ! ( V_34 -> V_218 & ( V_219 | V_220 ) ) )
goto V_221;
for ( V_214 = V_216 ; V_214 < V_222 ; V_214 ++ ) {
struct V_17 * V_18 ;
struct V_223 * V_224 ;
struct V_225 * V_226 ;
V_215 = 0 ;
V_226 = & V_120 -> V_227 [ V_214 ] ;
F_74 ( & V_226 -> V_228 ) ;
F_75 (sk, node, &ilb->head) {
struct V_32 * V_33 = F_10 ( V_18 ) ;
if ( ! F_76 ( F_40 ( V_18 ) , V_124 ) )
continue;
if ( V_215 < V_217 ) {
V_215 ++ ;
continue;
}
if ( V_34 -> V_126 != V_171 &&
V_18 -> V_47 != V_34 -> V_126 )
goto V_229;
if ( V_34 -> V_51 . V_55 != V_33 -> V_56 &&
V_34 -> V_51 . V_55 )
goto V_229;
if ( ! ( V_34 -> V_218 & V_219 ) ||
V_34 -> V_51 . V_57 ||
V_183 -> args [ 3 ] > 0 )
goto V_230;
if ( F_64 ( V_18 , V_22 , V_183 , V_34 , V_144 ) < 0 ) {
F_77 ( & V_226 -> V_228 ) ;
goto V_231;
}
V_230:
if ( ! ( V_34 -> V_218 & V_220 ) )
goto V_229;
if ( F_70 ( V_22 , V_18 , V_183 , V_34 , V_144 ) < 0 ) {
F_77 ( & V_226 -> V_228 ) ;
goto V_231;
}
V_229:
V_183 -> args [ 3 ] = 0 ;
V_183 -> args [ 4 ] = 0 ;
++ V_215 ;
}
F_77 ( & V_226 -> V_228 ) ;
V_217 = 0 ;
V_183 -> args [ 3 ] = 0 ;
V_183 -> args [ 4 ] = 0 ;
}
V_221:
V_183 -> args [ 0 ] = 1 ;
V_216 = V_215 = V_217 = 0 ;
}
if ( ! ( V_34 -> V_218 & ~ ( V_219 | V_220 ) ) )
goto V_87;
for ( V_214 = V_216 ; V_214 <= V_120 -> V_232 ; V_214 ++ ) {
struct V_233 * V_211 = & V_120 -> V_234 [ V_214 ] ;
T_6 * V_228 = F_78 ( V_120 , V_214 ) ;
struct V_17 * V_18 ;
struct V_223 * V_224 ;
V_215 = 0 ;
if ( F_79 ( & V_211 -> V_235 ) )
continue;
if ( V_214 > V_216 )
V_217 = 0 ;
F_74 ( V_228 ) ;
F_75 (sk, node, &head->chain) {
int V_236 ;
int V_237 ;
if ( ! F_76 ( F_40 ( V_18 ) , V_124 ) )
continue;
if ( V_215 < V_217 )
goto V_238;
V_237 = ( V_18 -> V_44 == V_45 ) ?
F_38 ( V_18 ) -> V_114 : V_18 -> V_44 ;
if ( ! ( V_34 -> V_218 & ( 1 << V_237 ) ) )
goto V_238;
if ( V_34 -> V_126 != V_171 &&
V_18 -> V_47 != V_34 -> V_126 )
goto V_238;
if ( V_34 -> V_51 . V_55 != F_80 ( V_18 -> V_239 ) &&
V_34 -> V_51 . V_55 )
goto V_238;
if ( V_34 -> V_51 . V_57 != V_18 -> V_240 &&
V_34 -> V_51 . V_57 )
goto V_238;
if ( V_18 -> V_44 == V_45 )
V_236 = F_65 ( V_18 , V_22 , V_183 , V_34 , V_144 ) ;
else
V_236 = F_64 ( V_18 , V_22 , V_183 , V_34 , V_144 ) ;
if ( V_236 < 0 ) {
F_77 ( V_228 ) ;
goto V_231;
}
V_238:
++ V_215 ;
}
F_77 ( V_228 ) ;
}
V_231:
V_183 -> args [ 1 ] = V_214 ;
V_183 -> args [ 2 ] = V_215 ;
V_87:
;
}
static int F_81 ( struct V_21 * V_22 , struct V_182 * V_183 ,
struct V_23 * V_34 , struct V_36 * V_144 )
{
const struct V_1 * V_9 ;
int V_122 = 0 ;
V_9 = F_1 ( V_34 -> V_41 ) ;
if ( ! F_52 ( V_9 ) )
V_9 -> V_241 ( V_22 , V_183 , V_34 , V_144 ) ;
else
V_122 = F_53 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_122 ? : V_22 -> V_145 ;
}
static int F_82 ( struct V_21 * V_22 , struct V_182 * V_183 )
{
struct V_36 * V_144 = NULL ;
int V_242 = sizeof( struct V_23 ) ;
if ( F_83 ( V_183 -> V_35 , V_242 ) )
V_144 = F_84 ( V_183 -> V_35 , V_242 , V_243 ) ;
return F_81 ( V_22 , V_183 , F_13 ( V_183 -> V_35 ) , V_144 ) ;
}
static inline int F_85 ( int type )
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
static int F_86 ( struct V_21 * V_22 , struct V_182 * V_183 )
{
struct V_248 * V_249 = F_13 ( V_183 -> V_35 ) ;
struct V_23 V_24 ;
struct V_36 * V_144 = NULL ;
int V_242 = sizeof( struct V_248 ) ;
V_24 . V_126 = V_171 ;
V_24 . V_41 = F_85 ( V_183 -> V_35 -> V_42 ) ;
V_24 . V_40 = V_249 -> V_40 ;
V_24 . V_218 = V_249 -> V_218 ;
V_24 . V_51 = V_249 -> V_51 ;
if ( F_83 ( V_183 -> V_35 , V_242 ) )
V_144 = F_84 ( V_183 -> V_35 , V_242 , V_243 ) ;
return F_81 ( V_22 , V_183 , & V_24 , V_144 ) ;
}
static int F_87 ( struct V_21 * V_121 ,
const struct V_30 * V_35 )
{
struct V_248 * V_249 = F_13 ( V_35 ) ;
struct V_23 V_24 ;
V_24 . V_126 = V_249 -> V_46 ;
V_24 . V_41 = F_85 ( V_35 -> V_42 ) ;
V_24 . V_40 = V_249 -> V_40 ;
V_24 . V_218 = V_249 -> V_218 ;
V_24 . V_51 = V_249 -> V_51 ;
return F_51 ( V_121 , V_35 , & V_24 ) ;
}
static int F_88 ( struct V_21 * V_22 , struct V_30 * V_35 )
{
int V_242 = sizeof( struct V_248 ) ;
struct V_124 * V_124 = F_40 ( V_22 -> V_18 ) ;
if ( V_35 -> V_42 >= V_250 ||
F_89 ( V_35 ) < V_242 )
return - V_125 ;
if ( V_35 -> V_29 & V_251 ) {
if ( F_83 ( V_35 , V_242 ) ) {
struct V_36 * V_37 ;
V_37 = F_84 ( V_35 , V_242 ,
V_243 ) ;
if ( V_37 == NULL ||
F_57 ( V_37 ) < sizeof( struct V_147 ) ||
F_63 ( F_28 ( V_37 ) , F_57 ( V_37 ) ) )
return - V_125 ;
}
{
struct V_252 V_253 = {
. V_241 = F_86 ,
} ;
return F_90 ( V_124 -> V_131 , V_22 , V_35 , & V_253 ) ;
}
}
return F_87 ( V_22 , V_35 ) ;
}
static int F_91 ( struct V_21 * V_22 , struct V_30 * V_254 )
{
int V_242 = sizeof( struct V_23 ) ;
struct V_124 * V_124 = F_40 ( V_22 -> V_18 ) ;
if ( F_89 ( V_254 ) < V_242 )
return - V_125 ;
if ( V_254 -> V_29 & V_251 ) {
if ( F_83 ( V_254 , V_242 ) ) {
struct V_36 * V_37 ;
V_37 = F_84 ( V_254 , V_242 ,
V_243 ) ;
if ( V_37 == NULL ||
F_57 ( V_37 ) < sizeof( struct V_147 ) ||
F_63 ( F_28 ( V_37 ) , F_57 ( V_37 ) ) )
return - V_125 ;
}
{
struct V_252 V_253 = {
. V_241 = F_82 ,
} ;
return F_90 ( V_124 -> V_131 , V_22 , V_254 , & V_253 ) ;
}
}
return F_51 ( V_22 , V_254 , F_13 ( V_254 ) ) ;
}
int F_92 ( const struct V_1 * V_254 )
{
const T_7 type = V_254 -> V_255 ;
int V_122 = - V_125 ;
if ( type >= V_256 )
goto V_87;
F_3 ( & V_7 ) ;
V_122 = - V_257 ;
if ( V_3 [ type ] == NULL ) {
V_3 [ type ] = V_254 ;
V_122 = 0 ;
}
F_6 ( & V_7 ) ;
V_87:
return V_122 ;
}
void F_93 ( const struct V_1 * V_254 )
{
const T_7 type = V_254 -> V_255 ;
if ( type >= V_256 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_8 F_94 ( void )
{
const int V_258 = ( V_256 *
sizeof( struct V_1 * ) ) ;
int V_122 = - V_129 ;
V_3 = F_95 ( V_258 , V_128 ) ;
if ( ! V_3 )
goto V_87;
V_122 = F_96 ( & V_1 ) ;
if ( V_122 )
goto V_259;
V_122 = F_96 ( & V_260 ) ;
if ( V_122 )
goto V_261;
F_97 ( F_88 ) ;
V_87:
return V_122 ;
V_261:
F_98 ( & V_1 ) ;
V_259:
F_99 ( V_3 ) ;
goto V_87;
}
static void T_9 F_100 ( void )
{
F_98 ( & V_260 ) ;
F_98 ( & V_1 ) ;
F_101 ( F_88 ) ;
F_99 ( V_3 ) ;
}
