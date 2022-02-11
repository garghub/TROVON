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
int F_7 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_14 * V_15 , struct V_16 * V_17 ,
struct V_18 * V_19 ,
T_1 V_20 , T_1 V_21 , T_2 V_22 ,
const struct V_23 * V_24 )
{
const struct V_25 * V_26 = F_8 ( V_11 ) ;
struct V_27 * V_28 ;
struct V_23 * V_29 ;
struct V_30 * V_31 ;
void * V_32 = NULL ;
const struct V_1 * V_9 ;
int V_33 = V_17 -> V_34 ;
V_9 = V_3 [ V_17 -> V_35 ] ;
F_9 ( V_9 == NULL ) ;
V_29 = F_10 ( V_15 , V_20 , V_21 , V_24 -> V_36 , sizeof( * V_28 ) ,
V_22 ) ;
if ( ! V_29 )
return - V_37 ;
V_28 = F_11 ( V_29 ) ;
F_9 ( V_11 -> V_38 == V_39 ) ;
V_28 -> V_40 = V_11 -> V_41 ;
V_28 -> V_42 = V_11 -> V_38 ;
V_28 -> V_43 = 0 ;
V_28 -> V_44 = 0 ;
V_28 -> V_45 . V_46 = V_11 -> V_47 ;
F_12 ( V_11 , V_28 -> V_45 . V_48 ) ;
V_28 -> V_45 . V_49 = V_26 -> V_50 ;
V_28 -> V_45 . V_51 = V_26 -> V_52 ;
V_28 -> V_45 . V_53 [ 0 ] = V_26 -> V_54 ;
V_28 -> V_45 . V_55 [ 0 ] = V_26 -> V_56 ;
if ( F_13 ( V_15 , V_57 , V_11 -> V_58 ) )
goto V_59;
if ( V_33 & ( 1 << ( V_60 - 1 ) ) )
if ( F_13 ( V_15 , V_60 , V_26 -> V_61 ) < 0 )
goto V_59;
#if F_14 ( V_62 )
if ( V_28 -> V_40 == V_63 ) {
const struct V_64 * V_65 = F_15 ( V_11 ) ;
* (struct V_66 * ) V_28 -> V_45 . V_53 = V_65 -> V_67 ;
* (struct V_66 * ) V_28 -> V_45 . V_55 = V_65 -> V_68 ;
if ( V_33 & ( 1 << ( V_69 - 1 ) ) )
if ( F_13 ( V_15 , V_69 , V_65 -> V_70 ) < 0 )
goto V_59;
}
#endif
V_28 -> V_71 = F_16 ( V_19 , F_17 ( V_11 ) ) ;
V_28 -> V_72 = F_18 ( V_11 ) ;
if ( V_33 & ( 1 << ( V_73 - 1 ) ) ) {
struct V_74 V_75 = {
. V_76 = F_19 ( V_11 ) ,
. V_77 = V_11 -> V_78 ,
. V_79 = V_11 -> V_80 ,
. V_81 = F_20 ( V_11 ) ,
} ;
if ( F_21 ( V_15 , V_73 , sizeof( V_75 ) , & V_75 ) < 0 )
goto V_59;
}
if ( V_33 & ( 1 << ( V_82 - 1 ) ) )
if ( F_22 ( V_11 , V_15 , V_82 ) )
goto V_59;
if ( V_13 == NULL ) {
V_9 -> V_83 ( V_11 , V_28 , NULL ) ;
goto V_84;
}
#define F_23 ( T_3 ) DIV_ROUND_UP((tmo - jiffies) * 1000, HZ)
if ( V_13 -> V_85 == V_86 ) {
V_28 -> V_43 = 1 ;
V_28 -> V_44 = V_13 -> V_87 ;
V_28 -> V_88 = F_23 ( V_13 -> V_89 ) ;
} else if ( V_13 -> V_85 == V_90 ) {
V_28 -> V_43 = 4 ;
V_28 -> V_44 = V_13 -> V_91 ;
V_28 -> V_88 = F_23 ( V_13 -> V_89 ) ;
} else if ( F_24 ( & V_11 -> V_92 ) ) {
V_28 -> V_43 = 2 ;
V_28 -> V_44 = V_13 -> V_91 ;
V_28 -> V_88 = F_23 ( V_11 -> V_92 . V_93 ) ;
} else {
V_28 -> V_43 = 0 ;
V_28 -> V_88 = 0 ;
}
#undef F_23
if ( V_33 & ( 1 << ( V_94 - 1 ) ) ) {
V_31 = F_25 ( V_15 , V_94 ,
sizeof( struct V_95 ) ) ;
if ( ! V_31 )
goto V_59;
V_32 = F_26 ( V_31 ) ;
}
if ( ( V_33 & ( 1 << ( V_96 - 1 ) ) ) && V_13 -> V_97 )
if ( F_27 ( V_15 , V_96 ,
V_13 -> V_97 -> V_98 ) < 0 )
goto V_59;
V_9 -> V_83 ( V_11 , V_28 , V_32 ) ;
if ( V_11 -> V_38 < V_39 &&
V_13 -> V_97 && V_13 -> V_97 -> V_99 )
V_13 -> V_97 -> V_99 ( V_11 , V_33 , V_15 ) ;
V_84:
return F_28 ( V_15 , V_29 ) ;
V_59:
F_29 ( V_15 , V_29 ) ;
return - V_37 ;
}
static int F_30 ( struct V_10 * V_11 ,
struct V_14 * V_15 , struct V_16 * V_17 ,
struct V_18 * V_19 ,
T_1 V_20 , T_1 V_21 , T_2 V_22 ,
const struct V_23 * V_24 )
{
return F_7 ( V_11 , F_31 ( V_11 ) ,
V_15 , V_17 , V_19 , V_20 , V_21 , V_22 , V_24 ) ;
}
static int F_32 ( struct V_100 * V_101 ,
struct V_14 * V_15 , struct V_16 * V_17 ,
T_1 V_20 , T_1 V_21 , T_2 V_22 ,
const struct V_23 * V_24 )
{
long T_3 ;
struct V_27 * V_28 ;
struct V_23 * V_29 ;
V_29 = F_10 ( V_15 , V_20 , V_21 , V_24 -> V_36 , sizeof( * V_28 ) ,
V_22 ) ;
if ( ! V_29 )
return - V_37 ;
V_28 = F_11 ( V_29 ) ;
F_9 ( V_101 -> V_102 != V_39 ) ;
T_3 = V_101 -> V_103 - V_104 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_28 -> V_40 = V_101 -> V_105 ;
V_28 -> V_44 = 0 ;
V_28 -> V_45 . V_46 = V_101 -> V_106 ;
F_12 ( V_101 , V_28 -> V_45 . V_48 ) ;
V_28 -> V_45 . V_49 = V_101 -> V_107 ;
V_28 -> V_45 . V_51 = V_101 -> V_108 ;
V_28 -> V_45 . V_53 [ 0 ] = V_101 -> V_109 ;
V_28 -> V_45 . V_55 [ 0 ] = V_101 -> V_110 ;
V_28 -> V_42 = V_101 -> V_111 ;
V_28 -> V_43 = 3 ;
V_28 -> V_88 = F_33 ( T_3 * 1000 , V_112 ) ;
V_28 -> V_113 = 0 ;
V_28 -> V_114 = 0 ;
V_28 -> V_71 = 0 ;
V_28 -> V_72 = 0 ;
#if F_14 ( V_62 )
if ( V_101 -> V_105 == V_63 ) {
const struct V_115 * V_116 =
F_34 ( (struct V_10 * ) V_101 ) ;
* (struct V_66 * ) V_28 -> V_45 . V_53 = V_116 -> V_117 ;
* (struct V_66 * ) V_28 -> V_45 . V_55 = V_116 -> V_118 ;
}
#endif
return F_28 ( V_15 , V_29 ) ;
}
static int F_35 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_16 * V_28 ,
struct V_18 * V_19 ,
T_1 V_20 , T_1 V_21 , T_2 V_22 ,
const struct V_23 * V_24 )
{
if ( V_11 -> V_38 == V_39 )
return F_32 ( (struct V_100 * ) V_11 ,
V_15 , V_28 , V_20 , V_21 , V_22 ,
V_24 ) ;
return F_30 ( V_11 , V_15 , V_28 , V_19 , V_20 , V_21 , V_22 , V_24 ) ;
}
int F_36 ( struct V_119 * V_120 , struct V_14 * V_121 ,
const struct V_23 * V_29 , struct V_16 * V_17 )
{
int V_122 ;
struct V_10 * V_11 ;
struct V_14 * V_123 ;
struct V_124 * V_124 = F_37 ( V_121 -> V_11 ) ;
V_122 = - V_125 ;
if ( V_17 -> V_126 == V_6 ) {
V_11 = F_38 ( V_124 , V_120 , V_17 -> V_45 . V_55 [ 0 ] ,
V_17 -> V_45 . V_51 , V_17 -> V_45 . V_53 [ 0 ] ,
V_17 -> V_45 . V_49 , V_17 -> V_45 . V_46 ) ;
}
#if F_14 ( V_62 )
else if ( V_17 -> V_126 == V_63 ) {
V_11 = F_39 ( V_124 , V_120 ,
(struct V_66 * ) V_17 -> V_45 . V_55 ,
V_17 -> V_45 . V_51 ,
(struct V_66 * ) V_17 -> V_45 . V_53 ,
V_17 -> V_45 . V_49 ,
V_17 -> V_45 . V_46 ) ;
}
#endif
else {
goto V_127;
}
V_122 = - V_8 ;
if ( V_11 == NULL )
goto V_127;
V_122 = F_40 ( V_11 , V_17 -> V_45 . V_48 ) ;
if ( V_122 )
goto V_84;
V_123 = F_41 ( sizeof( struct V_27 ) +
sizeof( struct V_74 ) +
sizeof( struct V_95 ) + 64 , V_128 ) ;
if ( ! V_123 ) {
V_122 = - V_129 ;
goto V_84;
}
V_122 = F_35 ( V_11 , V_123 , V_17 ,
F_42 ( F_43 ( V_121 ) . V_130 ) ,
F_43 ( V_121 ) . V_20 ,
V_29 -> V_131 , 0 , V_29 ) ;
if ( V_122 < 0 ) {
F_44 ( V_122 == - V_37 ) ;
F_45 ( V_123 ) ;
goto V_84;
}
V_122 = F_46 ( V_124 -> V_132 , V_123 , F_43 ( V_121 ) . V_20 ,
V_133 ) ;
if ( V_122 > 0 )
V_122 = 0 ;
V_84:
if ( V_11 ) {
if ( V_11 -> V_38 == V_39 )
F_47 ( (struct V_100 * ) V_11 ) ;
else
F_48 ( V_11 ) ;
}
V_127:
return V_122 ;
}
static int F_49 ( struct V_14 * V_121 ,
const struct V_23 * V_29 ,
struct V_16 * V_17 )
{
const struct V_1 * V_9 ;
int V_122 ;
V_9 = F_1 ( V_17 -> V_35 ) ;
if ( F_50 ( V_9 ) )
V_122 = F_51 ( V_9 ) ;
else
V_122 = V_9 -> V_134 ( V_121 , V_29 , V_17 ) ;
F_5 ( V_9 ) ;
return V_122 ;
}
static int F_52 ( const T_4 * V_135 , const T_4 * V_136 , int V_137 )
{
int V_138 = V_137 >> 5 ;
V_137 &= 0x1f ;
if ( V_138 ) {
if ( memcmp ( V_135 , V_136 , V_138 << 2 ) )
return 0 ;
}
if ( V_137 ) {
T_4 V_139 , V_140 ;
T_4 V_141 ;
V_139 = V_135 [ V_138 ] ;
V_140 = V_136 [ V_138 ] ;
V_141 = F_53 ( ( 0xffffffff ) << ( 32 - V_137 ) ) ;
if ( ( V_139 ^ V_140 ) & V_141 )
return 0 ;
}
return 1 ;
}
static int F_54 ( const struct V_30 * V_142 ,
const struct V_143 * V_144 )
{
const void * V_145 = F_26 ( V_142 ) ;
int V_146 = F_55 ( V_142 ) ;
while ( V_146 > 0 ) {
int V_147 = 1 ;
const struct V_148 * V_149 = V_145 ;
switch ( V_149 -> V_150 ) {
case V_151 :
break;
case V_152 :
V_147 = 0 ;
break;
case V_153 :
V_147 = V_144 -> V_154 >= V_149 [ 1 ] . V_155 ;
break;
case V_156 :
V_147 = V_144 -> V_154 <= V_149 [ 1 ] . V_155 ;
break;
case V_157 :
V_147 = V_144 -> V_158 >= V_149 [ 1 ] . V_155 ;
break;
case V_159 :
V_147 = V_144 -> V_158 <= V_149 [ 1 ] . V_155 ;
break;
case V_160 :
V_147 = ! ( V_144 -> V_161 & V_162 ) ;
break;
case V_163 :
case V_164 : {
struct V_165 * V_166 ;
T_4 * V_167 ;
V_166 = (struct V_165 * ) ( V_149 + 1 ) ;
if ( V_166 -> V_168 != - 1 &&
V_166 -> V_168 != ( V_149 -> V_150 == V_163 ?
V_144 -> V_154 : V_144 -> V_158 ) ) {
V_147 = 0 ;
break;
}
if ( V_149 -> V_150 == V_163 )
V_167 = V_144 -> V_169 ;
else
V_167 = V_144 -> V_68 ;
if ( V_166 -> V_170 != V_171 &&
V_166 -> V_170 != V_144 -> V_170 ) {
if ( V_144 -> V_170 == V_63 &&
V_166 -> V_170 == V_6 ) {
if ( V_167 [ 0 ] == 0 && V_167 [ 1 ] == 0 &&
V_167 [ 2 ] == F_53 ( 0xffff ) &&
F_52 ( V_167 + 3 ,
V_166 -> V_167 ,
V_166 -> V_172 ) )
break;
}
V_147 = 0 ;
break;
}
if ( V_166 -> V_172 == 0 )
break;
if ( F_52 ( V_167 , V_166 -> V_167 ,
V_166 -> V_172 ) )
break;
V_147 = 0 ;
break;
}
}
if ( V_147 ) {
V_146 -= V_149 -> V_147 ;
V_145 += V_149 -> V_147 ;
} else {
V_146 -= V_149 -> V_155 ;
V_145 += V_149 -> V_155 ;
}
}
return V_146 == 0 ;
}
int F_56 ( const struct V_30 * V_145 , struct V_10 * V_11 )
{
struct V_143 V_144 ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
if ( V_145 == NULL )
return 1 ;
V_144 . V_170 = V_11 -> V_41 ;
#if F_14 ( V_62 )
if ( V_144 . V_170 == V_63 ) {
struct V_64 * V_65 = F_15 ( V_11 ) ;
V_144 . V_169 = V_65 -> V_67 . V_173 ;
V_144 . V_68 = V_65 -> V_68 . V_173 ;
} else
#endif
{
V_144 . V_169 = & V_26 -> V_54 ;
V_144 . V_68 = & V_26 -> V_56 ;
}
V_144 . V_154 = V_26 -> V_174 ;
V_144 . V_158 = F_57 ( V_26 -> V_52 ) ;
V_144 . V_161 = V_11 -> V_175 ;
return F_54 ( V_145 , & V_144 ) ;
}
static int F_58 ( const void * V_145 , int V_146 , int V_176 )
{
while ( V_146 >= 0 ) {
const struct V_148 * V_149 = V_145 ;
if ( V_176 > V_146 )
return 0 ;
if ( V_176 == V_146 )
return 1 ;
if ( V_149 -> V_147 < 4 || V_149 -> V_147 & 3 )
return 0 ;
V_146 -= V_149 -> V_147 ;
V_145 += V_149 -> V_147 ;
}
return 0 ;
}
static bool F_59 ( const struct V_148 * V_149 , int V_146 ,
int * V_177 )
{
int V_178 ;
struct V_165 * V_166 ;
* V_177 += sizeof( struct V_165 ) ;
if ( V_146 < * V_177 )
return false ;
V_166 = (struct V_165 * ) ( V_149 + 1 ) ;
switch ( V_166 -> V_170 ) {
case V_171 :
V_178 = 0 ;
break;
case V_6 :
V_178 = sizeof( struct V_179 ) ;
break;
case V_63 :
V_178 = sizeof( struct V_66 ) ;
break;
default:
return false ;
}
* V_177 += V_178 ;
if ( V_146 < * V_177 )
return false ;
if ( V_166 -> V_172 > 8 * V_178 )
return false ;
return true ;
}
static inline bool F_60 ( const struct V_148 * V_149 ,
int V_146 , int * V_177 )
{
* V_177 += sizeof( struct V_148 ) ;
if ( V_146 < * V_177 )
return false ;
return true ;
}
static int F_61 ( const void * V_180 , int V_181 )
{
const void * V_145 = V_180 ;
int V_146 = V_181 ;
while ( V_146 > 0 ) {
const struct V_148 * V_149 = V_145 ;
int V_177 = sizeof( struct V_148 ) ;
switch ( V_149 -> V_150 ) {
case V_163 :
case V_164 :
if ( ! F_59 ( V_145 , V_146 , & V_177 ) )
return - V_125 ;
break;
case V_153 :
case V_156 :
case V_157 :
case V_159 :
if ( ! F_60 ( V_145 , V_146 , & V_177 ) )
return - V_125 ;
break;
case V_160 :
case V_152 :
case V_151 :
break;
default:
return - V_125 ;
}
if ( V_149 -> V_150 != V_151 ) {
if ( V_149 -> V_155 < V_177 || V_149 -> V_155 > V_146 + 4 || V_149 -> V_155 & 3 )
return - V_125 ;
if ( V_149 -> V_155 < V_146 &&
! F_58 ( V_180 , V_181 , V_146 - V_149 -> V_155 ) )
return - V_125 ;
}
if ( V_149 -> V_147 < V_177 || V_149 -> V_147 > V_146 + 4 || V_149 -> V_147 & 3 )
return - V_125 ;
V_145 += V_149 -> V_147 ;
V_146 -= V_149 -> V_147 ;
}
return V_146 == 0 ? 0 : - V_125 ;
}
static int F_62 ( struct V_10 * V_11 ,
struct V_14 * V_15 ,
struct V_182 * V_183 ,
struct V_16 * V_28 ,
const struct V_30 * V_145 )
{
if ( ! F_56 ( V_145 , V_11 ) )
return 0 ;
return F_30 ( V_11 , V_15 , V_28 ,
F_42 ( F_43 ( V_183 -> V_15 ) . V_130 ) ,
F_43 ( V_183 -> V_15 ) . V_20 ,
V_183 -> V_29 -> V_131 , V_184 , V_183 -> V_29 ) ;
}
static int F_63 ( struct V_100 * V_101 ,
struct V_14 * V_15 ,
struct V_182 * V_183 ,
struct V_16 * V_28 ,
const struct V_30 * V_145 )
{
if ( V_145 != NULL ) {
struct V_143 V_144 ;
V_144 . V_170 = V_101 -> V_105 ;
#if F_14 ( V_62 )
if ( V_101 -> V_105 == V_63 ) {
struct V_115 * V_116 =
F_34 ( (struct V_10 * ) V_101 ) ;
V_144 . V_169 = V_116 -> V_117 . V_173 ;
V_144 . V_68 = V_116 -> V_118 . V_173 ;
} else
#endif
{
V_144 . V_169 = & V_101 -> V_109 ;
V_144 . V_68 = & V_101 -> V_110 ;
}
V_144 . V_154 = V_101 -> V_185 ;
V_144 . V_158 = F_57 ( V_101 -> V_108 ) ;
V_144 . V_161 = 0 ;
if ( ! F_54 ( V_145 , & V_144 ) )
return 0 ;
}
return F_32 ( V_101 , V_15 , V_28 ,
F_43 ( V_183 -> V_15 ) . V_20 ,
V_183 -> V_29 -> V_131 , V_184 , V_183 -> V_29 ) ;
}
static inline void F_64 ( const struct V_10 * V_11 ,
const struct V_186 * V_17 ,
struct V_143 * V_144 )
{
struct V_187 * V_188 = F_65 ( V_17 ) ;
#if F_14 ( V_62 )
if ( V_11 -> V_41 == V_63 ) {
if ( V_17 -> V_189 -> V_170 == V_63 ) {
V_144 -> V_169 = F_66 ( V_17 ) -> V_190 . V_173 ;
V_144 -> V_68 = F_66 ( V_17 ) -> V_191 . V_173 ;
} else if ( V_17 -> V_189 -> V_170 == V_6 ) {
F_67 ( V_188 -> V_190 ,
& V_144 -> V_192 ) ;
F_67 ( V_188 -> V_191 ,
& V_144 -> V_193 ) ;
V_144 -> V_169 = V_144 -> V_192 . V_173 ;
V_144 -> V_68 = V_144 -> V_193 . V_173 ;
}
} else
#endif
{
V_144 -> V_169 = & V_188 -> V_190 ;
V_144 -> V_68 = & V_188 -> V_191 ;
}
}
static int F_68 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_186 * V_17 ,
struct V_18 * V_19 ,
T_1 V_20 , T_1 V_21 ,
const struct V_23 * V_24 )
{
const struct V_187 * V_188 = F_65 ( V_17 ) ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
struct V_27 * V_28 ;
struct V_23 * V_29 ;
long T_3 ;
V_29 = F_10 ( V_15 , V_20 , V_21 , V_24 -> V_36 , sizeof( * V_28 ) ,
V_184 ) ;
if ( ! V_29 )
return - V_37 ;
V_28 = F_11 ( V_29 ) ;
V_28 -> V_40 = V_11 -> V_41 ;
V_28 -> V_42 = V_194 ;
V_28 -> V_43 = 1 ;
V_28 -> V_44 = V_17 -> V_195 ;
V_28 -> V_45 . V_46 = V_11 -> V_47 ;
F_12 ( V_17 , V_28 -> V_45 . V_48 ) ;
T_3 = V_17 -> V_93 - V_104 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_28 -> V_45 . V_49 = V_26 -> V_50 ;
V_28 -> V_45 . V_51 = V_188 -> V_196 ;
V_28 -> V_45 . V_53 [ 0 ] = V_188 -> V_190 ;
V_28 -> V_45 . V_55 [ 0 ] = V_188 -> V_191 ;
V_28 -> V_88 = F_69 ( T_3 ) ;
V_28 -> V_113 = 0 ;
V_28 -> V_114 = 0 ;
V_28 -> V_71 = F_16 ( V_19 , F_17 ( V_11 ) ) ;
V_28 -> V_72 = 0 ;
#if F_14 ( V_62 )
if ( V_28 -> V_40 == V_63 ) {
struct V_143 V_144 ;
F_64 ( V_11 , V_17 , & V_144 ) ;
memcpy ( V_28 -> V_45 . V_53 , V_144 . V_169 , sizeof( struct V_66 ) ) ;
memcpy ( V_28 -> V_45 . V_55 , V_144 . V_68 , sizeof( struct V_66 ) ) ;
}
#endif
return F_28 ( V_15 , V_29 ) ;
}
static int F_70 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_182 * V_183 ,
struct V_16 * V_28 ,
const struct V_30 * V_145 )
{
struct V_143 V_144 ;
struct V_12 * V_13 = F_31 ( V_11 ) ;
struct V_197 * V_198 ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
int V_199 , V_200 ;
int V_201 , V_202 ;
int V_122 = 0 ;
V_200 = V_183 -> args [ 3 ] ;
V_202 = V_183 -> args [ 4 ] ;
if ( V_200 > 0 )
V_200 -- ;
V_144 . V_170 = V_11 -> V_41 ;
F_71 ( & V_13 -> V_203 . V_204 ) ;
V_198 = V_13 -> V_203 . V_205 ;
if ( ! V_198 || ! V_198 -> V_206 )
goto V_84;
if ( V_145 != NULL ) {
V_144 . V_154 = V_26 -> V_174 ;
V_144 . V_161 = V_11 -> V_175 ;
}
for ( V_199 = V_200 ; V_199 < V_198 -> V_207 ; V_199 ++ ) {
struct V_186 * V_17 , * V_208 = V_198 -> V_209 [ V_199 ] ;
V_201 = 0 ;
for ( V_17 = V_208 ; V_17 ; V_201 ++ , V_17 = V_17 -> V_210 ) {
struct V_187 * V_188 = F_65 ( V_17 ) ;
if ( V_201 < V_202 )
continue;
if ( V_28 -> V_45 . V_51 != V_188 -> V_196 &&
V_28 -> V_45 . V_51 )
continue;
if ( V_145 ) {
F_64 ( V_11 , V_17 , & V_144 ) ;
V_144 . V_158 = F_57 ( V_188 -> V_196 ) ;
if ( ! F_54 ( V_145 , & V_144 ) )
continue;
}
V_122 = F_68 ( V_15 , V_11 , V_17 ,
F_42 ( F_43 ( V_183 -> V_15 ) . V_130 ) ,
F_43 ( V_183 -> V_15 ) . V_20 ,
V_183 -> V_29 -> V_131 , V_183 -> V_29 ) ;
if ( V_122 < 0 ) {
V_183 -> args [ 3 ] = V_199 + 1 ;
V_183 -> args [ 4 ] = V_201 ;
goto V_84;
}
}
V_202 = 0 ;
}
V_84:
F_72 ( & V_13 -> V_203 . V_204 ) ;
return V_122 ;
}
void F_73 ( struct V_119 * V_120 , struct V_14 * V_15 ,
struct V_182 * V_183 , struct V_16 * V_28 , struct V_30 * V_145 )
{
int V_211 , V_212 ;
int V_213 , V_214 ;
struct V_124 * V_124 = F_37 ( V_15 -> V_11 ) ;
V_213 = V_183 -> args [ 1 ] ;
V_214 = V_212 = V_183 -> args [ 2 ] ;
if ( V_183 -> args [ 0 ] == 0 ) {
if ( ! ( V_28 -> V_215 & ( V_216 | V_217 ) ) )
goto V_218;
for ( V_211 = V_213 ; V_211 < V_219 ; V_211 ++ ) {
struct V_10 * V_11 ;
struct V_220 * V_221 ;
struct V_222 * V_223 ;
V_212 = 0 ;
V_223 = & V_120 -> V_224 [ V_211 ] ;
F_74 ( & V_223 -> V_225 ) ;
F_75 (sk, node, &ilb->head) {
struct V_25 * V_26 = F_8 ( V_11 ) ;
if ( ! F_76 ( F_37 ( V_11 ) , V_124 ) )
continue;
if ( V_212 < V_214 ) {
V_212 ++ ;
continue;
}
if ( V_28 -> V_126 != V_171 &&
V_11 -> V_41 != V_28 -> V_126 )
goto V_226;
if ( V_28 -> V_45 . V_49 != V_26 -> V_50 &&
V_28 -> V_45 . V_49 )
goto V_226;
if ( ! ( V_28 -> V_215 & V_216 ) ||
V_28 -> V_45 . V_51 ||
V_183 -> args [ 3 ] > 0 )
goto V_227;
if ( F_62 ( V_11 , V_15 , V_183 , V_28 , V_145 ) < 0 ) {
F_77 ( & V_223 -> V_225 ) ;
goto V_228;
}
V_227:
if ( ! ( V_28 -> V_215 & V_217 ) )
goto V_226;
if ( F_70 ( V_15 , V_11 , V_183 , V_28 , V_145 ) < 0 ) {
F_77 ( & V_223 -> V_225 ) ;
goto V_228;
}
V_226:
V_183 -> args [ 3 ] = 0 ;
V_183 -> args [ 4 ] = 0 ;
++ V_212 ;
}
F_77 ( & V_223 -> V_225 ) ;
V_214 = 0 ;
V_183 -> args [ 3 ] = 0 ;
V_183 -> args [ 4 ] = 0 ;
}
V_218:
V_183 -> args [ 0 ] = 1 ;
V_213 = V_212 = V_214 = 0 ;
}
if ( ! ( V_28 -> V_215 & ~ ( V_216 | V_217 ) ) )
goto V_84;
for ( V_211 = V_213 ; V_211 <= V_120 -> V_229 ; V_211 ++ ) {
struct V_230 * V_208 = & V_120 -> V_231 [ V_211 ] ;
T_5 * V_225 = F_78 ( V_120 , V_211 ) ;
struct V_10 * V_11 ;
struct V_220 * V_221 ;
V_212 = 0 ;
if ( F_79 ( & V_208 -> V_232 ) &&
F_79 ( & V_208 -> V_233 ) )
continue;
if ( V_211 > V_213 )
V_214 = 0 ;
F_74 ( V_225 ) ;
F_75 (sk, node, &head->chain) {
struct V_25 * V_26 = F_8 ( V_11 ) ;
if ( ! F_76 ( F_37 ( V_11 ) , V_124 ) )
continue;
if ( V_212 < V_214 )
goto V_234;
if ( ! ( V_28 -> V_215 & ( 1 << V_11 -> V_38 ) ) )
goto V_234;
if ( V_28 -> V_126 != V_171 &&
V_11 -> V_41 != V_28 -> V_126 )
goto V_234;
if ( V_28 -> V_45 . V_49 != V_26 -> V_50 &&
V_28 -> V_45 . V_49 )
goto V_234;
if ( V_28 -> V_45 . V_51 != V_26 -> V_52 &&
V_28 -> V_45 . V_51 )
goto V_234;
if ( F_62 ( V_11 , V_15 , V_183 , V_28 , V_145 ) < 0 ) {
F_77 ( V_225 ) ;
goto V_228;
}
V_234:
++ V_212 ;
}
if ( V_28 -> V_215 & V_235 ) {
struct V_100 * V_101 ;
F_80 (tw, node,
&head->twchain) {
if ( ! F_76 ( F_81 ( V_101 ) , V_124 ) )
continue;
if ( V_212 < V_214 )
goto V_236;
if ( V_28 -> V_126 != V_171 &&
V_101 -> V_105 != V_28 -> V_126 )
goto V_236;
if ( V_28 -> V_45 . V_49 != V_101 -> V_107 &&
V_28 -> V_45 . V_49 )
goto V_236;
if ( V_28 -> V_45 . V_51 != V_101 -> V_108 &&
V_28 -> V_45 . V_51 )
goto V_236;
if ( F_63 ( V_101 , V_15 , V_183 , V_28 , V_145 ) < 0 ) {
F_77 ( V_225 ) ;
goto V_228;
}
V_236:
++ V_212 ;
}
}
F_77 ( V_225 ) ;
}
V_228:
V_183 -> args [ 1 ] = V_211 ;
V_183 -> args [ 2 ] = V_212 ;
V_84:
;
}
static int F_82 ( struct V_14 * V_15 , struct V_182 * V_183 ,
struct V_16 * V_28 , struct V_30 * V_145 )
{
const struct V_1 * V_9 ;
int V_122 = 0 ;
V_9 = F_1 ( V_28 -> V_35 ) ;
if ( ! F_50 ( V_9 ) )
V_9 -> V_237 ( V_15 , V_183 , V_28 , V_145 ) ;
else
V_122 = F_51 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_122 ? : V_15 -> V_146 ;
}
static int F_83 ( struct V_14 * V_15 , struct V_182 * V_183 )
{
struct V_30 * V_145 = NULL ;
int V_238 = sizeof( struct V_16 ) ;
if ( F_84 ( V_183 -> V_29 , V_238 ) )
V_145 = F_85 ( V_183 -> V_29 , V_238 , V_239 ) ;
return F_82 ( V_15 , V_183 , F_11 ( V_183 -> V_29 ) , V_145 ) ;
}
static inline int F_86 ( int type )
{
switch ( type ) {
case V_240 :
return V_241 ;
case V_242 :
return V_243 ;
default:
return 0 ;
}
}
static int F_87 ( struct V_14 * V_15 , struct V_182 * V_183 )
{
struct V_244 * V_245 = F_11 ( V_183 -> V_29 ) ;
struct V_16 V_17 ;
struct V_30 * V_145 = NULL ;
int V_238 = sizeof( struct V_244 ) ;
V_17 . V_126 = V_171 ;
V_17 . V_35 = F_86 ( V_183 -> V_29 -> V_36 ) ;
V_17 . V_34 = V_245 -> V_34 ;
V_17 . V_215 = V_245 -> V_215 ;
V_17 . V_45 = V_245 -> V_45 ;
if ( F_84 ( V_183 -> V_29 , V_238 ) )
V_145 = F_85 ( V_183 -> V_29 , V_238 , V_239 ) ;
return F_82 ( V_15 , V_183 , & V_17 , V_145 ) ;
}
static int F_88 ( struct V_14 * V_121 ,
const struct V_23 * V_29 )
{
struct V_244 * V_245 = F_11 ( V_29 ) ;
struct V_16 V_17 ;
V_17 . V_126 = V_245 -> V_40 ;
V_17 . V_35 = F_86 ( V_29 -> V_36 ) ;
V_17 . V_34 = V_245 -> V_34 ;
V_17 . V_215 = V_245 -> V_215 ;
V_17 . V_45 = V_245 -> V_45 ;
return F_49 ( V_121 , V_29 , & V_17 ) ;
}
static int F_89 ( struct V_14 * V_15 , struct V_23 * V_29 )
{
int V_238 = sizeof( struct V_244 ) ;
struct V_124 * V_124 = F_37 ( V_15 -> V_11 ) ;
if ( V_29 -> V_36 >= V_246 ||
F_90 ( V_29 ) < V_238 )
return - V_125 ;
if ( V_29 -> V_22 & V_247 ) {
if ( F_84 ( V_29 , V_238 ) ) {
struct V_30 * V_31 ;
V_31 = F_85 ( V_29 , V_238 ,
V_239 ) ;
if ( V_31 == NULL ||
F_55 ( V_31 ) < sizeof( struct V_148 ) ||
F_61 ( F_26 ( V_31 ) , F_55 ( V_31 ) ) )
return - V_125 ;
}
{
struct V_248 V_249 = {
. V_237 = F_87 ,
} ;
return F_91 ( V_124 -> V_132 , V_15 , V_29 , & V_249 ) ;
}
}
return F_88 ( V_15 , V_29 ) ;
}
static int F_92 ( struct V_14 * V_15 , struct V_23 * V_250 )
{
int V_238 = sizeof( struct V_16 ) ;
struct V_124 * V_124 = F_37 ( V_15 -> V_11 ) ;
if ( F_90 ( V_250 ) < V_238 )
return - V_125 ;
if ( V_250 -> V_22 & V_247 ) {
if ( F_84 ( V_250 , V_238 ) ) {
struct V_30 * V_31 ;
V_31 = F_85 ( V_250 , V_238 ,
V_239 ) ;
if ( V_31 == NULL ||
F_55 ( V_31 ) < sizeof( struct V_148 ) ||
F_61 ( F_26 ( V_31 ) , F_55 ( V_31 ) ) )
return - V_125 ;
}
{
struct V_248 V_249 = {
. V_237 = F_83 ,
} ;
return F_91 ( V_124 -> V_132 , V_15 , V_250 , & V_249 ) ;
}
}
return F_49 ( V_15 , V_250 , F_11 ( V_250 ) ) ;
}
int F_93 ( const struct V_1 * V_250 )
{
const T_6 type = V_250 -> V_251 ;
int V_122 = - V_125 ;
if ( type >= V_252 )
goto V_84;
F_3 ( & V_7 ) ;
V_122 = - V_253 ;
if ( V_3 [ type ] == NULL ) {
V_3 [ type ] = V_250 ;
V_122 = 0 ;
}
F_6 ( & V_7 ) ;
V_84:
return V_122 ;
}
void F_94 ( const struct V_1 * V_250 )
{
const T_6 type = V_250 -> V_251 ;
if ( type >= V_252 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_7 F_95 ( void )
{
const int V_254 = ( V_252 *
sizeof( struct V_1 * ) ) ;
int V_122 = - V_129 ;
V_3 = F_96 ( V_254 , V_128 ) ;
if ( ! V_3 )
goto V_84;
V_122 = F_97 ( & V_1 ) ;
if ( V_122 )
goto V_255;
V_122 = F_97 ( & V_256 ) ;
if ( V_122 )
goto V_257;
F_98 ( F_89 ) ;
V_84:
return V_122 ;
V_257:
F_99 ( & V_1 ) ;
V_255:
F_100 ( V_3 ) ;
goto V_84;
}
static void T_8 F_101 ( void )
{
F_99 ( & V_256 ) ;
F_99 ( & V_1 ) ;
F_102 ( F_89 ) ;
F_100 ( V_3 ) ;
}
