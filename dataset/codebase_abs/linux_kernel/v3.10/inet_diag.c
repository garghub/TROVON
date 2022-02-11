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
if ( V_13 -> V_85 == V_86 ||
V_13 -> V_85 == V_87 ||
V_13 -> V_85 == V_88 ) {
V_28 -> V_43 = 1 ;
V_28 -> V_44 = V_13 -> V_89 ;
V_28 -> V_90 = F_23 ( V_13 -> V_91 ) ;
} else if ( V_13 -> V_85 == V_92 ) {
V_28 -> V_43 = 4 ;
V_28 -> V_44 = V_13 -> V_93 ;
V_28 -> V_90 = F_23 ( V_13 -> V_91 ) ;
} else if ( F_24 ( & V_11 -> V_94 ) ) {
V_28 -> V_43 = 2 ;
V_28 -> V_44 = V_13 -> V_93 ;
V_28 -> V_90 = F_23 ( V_11 -> V_94 . V_95 ) ;
} else {
V_28 -> V_43 = 0 ;
V_28 -> V_90 = 0 ;
}
#undef F_23
if ( V_33 & ( 1 << ( V_96 - 1 ) ) ) {
V_31 = F_25 ( V_15 , V_96 ,
sizeof( struct V_97 ) ) ;
if ( ! V_31 )
goto V_59;
V_32 = F_26 ( V_31 ) ;
}
if ( ( V_33 & ( 1 << ( V_98 - 1 ) ) ) && V_13 -> V_99 )
if ( F_27 ( V_15 , V_98 ,
V_13 -> V_99 -> V_100 ) < 0 )
goto V_59;
V_9 -> V_83 ( V_11 , V_28 , V_32 ) ;
if ( V_11 -> V_38 < V_39 &&
V_13 -> V_99 && V_13 -> V_99 -> V_101 )
V_13 -> V_99 -> V_101 ( V_11 , V_33 , V_15 ) ;
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
static int F_32 ( struct V_102 * V_103 ,
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
F_9 ( V_103 -> V_104 != V_39 ) ;
T_3 = V_103 -> V_105 - V_106 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_28 -> V_40 = V_103 -> V_107 ;
V_28 -> V_44 = 0 ;
V_28 -> V_45 . V_46 = V_103 -> V_108 ;
F_12 ( V_103 , V_28 -> V_45 . V_48 ) ;
V_28 -> V_45 . V_49 = V_103 -> V_109 ;
V_28 -> V_45 . V_51 = V_103 -> V_110 ;
V_28 -> V_45 . V_53 [ 0 ] = V_103 -> V_111 ;
V_28 -> V_45 . V_55 [ 0 ] = V_103 -> V_112 ;
V_28 -> V_42 = V_103 -> V_113 ;
V_28 -> V_43 = 3 ;
V_28 -> V_90 = F_33 ( T_3 * 1000 , V_114 ) ;
V_28 -> V_115 = 0 ;
V_28 -> V_116 = 0 ;
V_28 -> V_71 = 0 ;
V_28 -> V_72 = 0 ;
#if F_14 ( V_62 )
if ( V_103 -> V_107 == V_63 ) {
const struct V_117 * V_118 =
F_34 ( (struct V_10 * ) V_103 ) ;
* (struct V_66 * ) V_28 -> V_45 . V_53 = V_118 -> V_119 ;
* (struct V_66 * ) V_28 -> V_45 . V_55 = V_118 -> V_120 ;
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
return F_32 ( (struct V_102 * ) V_11 ,
V_15 , V_28 , V_20 , V_21 , V_22 ,
V_24 ) ;
return F_30 ( V_11 , V_15 , V_28 , V_19 , V_20 , V_21 , V_22 , V_24 ) ;
}
int F_36 ( struct V_121 * V_122 , struct V_14 * V_123 ,
const struct V_23 * V_29 , struct V_16 * V_17 )
{
int V_124 ;
struct V_10 * V_11 ;
struct V_14 * V_125 ;
struct V_126 * V_126 = F_37 ( V_123 -> V_11 ) ;
V_124 = - V_127 ;
if ( V_17 -> V_128 == V_6 ) {
V_11 = F_38 ( V_126 , V_122 , V_17 -> V_45 . V_55 [ 0 ] ,
V_17 -> V_45 . V_51 , V_17 -> V_45 . V_53 [ 0 ] ,
V_17 -> V_45 . V_49 , V_17 -> V_45 . V_46 ) ;
}
#if F_14 ( V_62 )
else if ( V_17 -> V_128 == V_63 ) {
V_11 = F_39 ( V_126 , V_122 ,
(struct V_66 * ) V_17 -> V_45 . V_55 ,
V_17 -> V_45 . V_51 ,
(struct V_66 * ) V_17 -> V_45 . V_53 ,
V_17 -> V_45 . V_49 ,
V_17 -> V_45 . V_46 ) ;
}
#endif
else {
goto V_129;
}
V_124 = - V_8 ;
if ( V_11 == NULL )
goto V_129;
V_124 = F_40 ( V_11 , V_17 -> V_45 . V_48 ) ;
if ( V_124 )
goto V_84;
V_125 = F_41 ( sizeof( struct V_27 ) +
sizeof( struct V_74 ) +
sizeof( struct V_97 ) + 64 , V_130 ) ;
if ( ! V_125 ) {
V_124 = - V_131 ;
goto V_84;
}
V_124 = F_35 ( V_11 , V_125 , V_17 ,
F_42 ( F_43 ( V_123 ) . V_11 ) ,
F_43 ( V_123 ) . V_20 ,
V_29 -> V_132 , 0 , V_29 ) ;
if ( V_124 < 0 ) {
F_44 ( V_124 == - V_37 ) ;
F_45 ( V_125 ) ;
goto V_84;
}
V_124 = F_46 ( V_126 -> V_133 , V_125 , F_43 ( V_123 ) . V_20 ,
V_134 ) ;
if ( V_124 > 0 )
V_124 = 0 ;
V_84:
if ( V_11 ) {
if ( V_11 -> V_38 == V_39 )
F_47 ( (struct V_102 * ) V_11 ) ;
else
F_48 ( V_11 ) ;
}
V_129:
return V_124 ;
}
static int F_49 ( struct V_14 * V_123 ,
const struct V_23 * V_29 ,
struct V_16 * V_17 )
{
const struct V_1 * V_9 ;
int V_124 ;
V_9 = F_1 ( V_17 -> V_35 ) ;
if ( F_50 ( V_9 ) )
V_124 = F_51 ( V_9 ) ;
else
V_124 = V_9 -> V_135 ( V_123 , V_29 , V_17 ) ;
F_5 ( V_9 ) ;
return V_124 ;
}
static int F_52 ( const T_4 * V_136 , const T_4 * V_137 , int V_138 )
{
int V_139 = V_138 >> 5 ;
V_138 &= 0x1f ;
if ( V_139 ) {
if ( memcmp ( V_136 , V_137 , V_139 << 2 ) )
return 0 ;
}
if ( V_138 ) {
T_4 V_140 , V_141 ;
T_4 V_142 ;
V_140 = V_136 [ V_139 ] ;
V_141 = V_137 [ V_139 ] ;
V_142 = F_53 ( ( 0xffffffff ) << ( 32 - V_138 ) ) ;
if ( ( V_140 ^ V_141 ) & V_142 )
return 0 ;
}
return 1 ;
}
static int F_54 ( const struct V_30 * V_143 ,
const struct V_144 * V_145 )
{
const void * V_146 = F_26 ( V_143 ) ;
int V_147 = F_55 ( V_143 ) ;
while ( V_147 > 0 ) {
int V_148 = 1 ;
const struct V_149 * V_150 = V_146 ;
switch ( V_150 -> V_151 ) {
case V_152 :
break;
case V_153 :
V_148 = 0 ;
break;
case V_154 :
V_148 = V_145 -> V_155 >= V_150 [ 1 ] . V_156 ;
break;
case V_157 :
V_148 = V_145 -> V_155 <= V_150 [ 1 ] . V_156 ;
break;
case V_158 :
V_148 = V_145 -> V_159 >= V_150 [ 1 ] . V_156 ;
break;
case V_160 :
V_148 = V_145 -> V_159 <= V_150 [ 1 ] . V_156 ;
break;
case V_161 :
V_148 = ! ( V_145 -> V_162 & V_163 ) ;
break;
case V_164 :
case V_165 : {
struct V_166 * V_167 ;
T_4 * V_168 ;
V_167 = (struct V_166 * ) ( V_150 + 1 ) ;
if ( V_167 -> V_169 != - 1 &&
V_167 -> V_169 != ( V_150 -> V_151 == V_164 ?
V_145 -> V_155 : V_145 -> V_159 ) ) {
V_148 = 0 ;
break;
}
if ( V_150 -> V_151 == V_164 )
V_168 = V_145 -> V_170 ;
else
V_168 = V_145 -> V_68 ;
if ( V_167 -> V_171 != V_172 &&
V_167 -> V_171 != V_145 -> V_171 ) {
if ( V_145 -> V_171 == V_63 &&
V_167 -> V_171 == V_6 ) {
if ( V_168 [ 0 ] == 0 && V_168 [ 1 ] == 0 &&
V_168 [ 2 ] == F_53 ( 0xffff ) &&
F_52 ( V_168 + 3 ,
V_167 -> V_168 ,
V_167 -> V_173 ) )
break;
}
V_148 = 0 ;
break;
}
if ( V_167 -> V_173 == 0 )
break;
if ( F_52 ( V_168 , V_167 -> V_168 ,
V_167 -> V_173 ) )
break;
V_148 = 0 ;
break;
}
}
if ( V_148 ) {
V_147 -= V_150 -> V_148 ;
V_146 += V_150 -> V_148 ;
} else {
V_147 -= V_150 -> V_156 ;
V_146 += V_150 -> V_156 ;
}
}
return V_147 == 0 ;
}
int F_56 ( const struct V_30 * V_146 , struct V_10 * V_11 )
{
struct V_144 V_145 ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
if ( V_146 == NULL )
return 1 ;
V_145 . V_171 = V_11 -> V_41 ;
#if F_14 ( V_62 )
if ( V_145 . V_171 == V_63 ) {
struct V_64 * V_65 = F_15 ( V_11 ) ;
V_145 . V_170 = V_65 -> V_67 . V_174 ;
V_145 . V_68 = V_65 -> V_68 . V_174 ;
} else
#endif
{
V_145 . V_170 = & V_26 -> V_54 ;
V_145 . V_68 = & V_26 -> V_56 ;
}
V_145 . V_155 = V_26 -> V_175 ;
V_145 . V_159 = F_57 ( V_26 -> V_52 ) ;
V_145 . V_162 = V_11 -> V_176 ;
return F_54 ( V_146 , & V_145 ) ;
}
static int F_58 ( const void * V_146 , int V_147 , int V_177 )
{
while ( V_147 >= 0 ) {
const struct V_149 * V_150 = V_146 ;
if ( V_177 > V_147 )
return 0 ;
if ( V_177 == V_147 )
return 1 ;
if ( V_150 -> V_148 < 4 || V_150 -> V_148 & 3 )
return 0 ;
V_147 -= V_150 -> V_148 ;
V_146 += V_150 -> V_148 ;
}
return 0 ;
}
static bool F_59 ( const struct V_149 * V_150 , int V_147 ,
int * V_178 )
{
int V_179 ;
struct V_166 * V_167 ;
* V_178 += sizeof( struct V_166 ) ;
if ( V_147 < * V_178 )
return false ;
V_167 = (struct V_166 * ) ( V_150 + 1 ) ;
switch ( V_167 -> V_171 ) {
case V_172 :
V_179 = 0 ;
break;
case V_6 :
V_179 = sizeof( struct V_180 ) ;
break;
case V_63 :
V_179 = sizeof( struct V_66 ) ;
break;
default:
return false ;
}
* V_178 += V_179 ;
if ( V_147 < * V_178 )
return false ;
if ( V_167 -> V_173 > 8 * V_179 )
return false ;
return true ;
}
static inline bool F_60 ( const struct V_149 * V_150 ,
int V_147 , int * V_178 )
{
* V_178 += sizeof( struct V_149 ) ;
if ( V_147 < * V_178 )
return false ;
return true ;
}
static int F_61 ( const void * V_181 , int V_182 )
{
const void * V_146 = V_181 ;
int V_147 = V_182 ;
while ( V_147 > 0 ) {
const struct V_149 * V_150 = V_146 ;
int V_178 = sizeof( struct V_149 ) ;
switch ( V_150 -> V_151 ) {
case V_164 :
case V_165 :
if ( ! F_59 ( V_146 , V_147 , & V_178 ) )
return - V_127 ;
break;
case V_154 :
case V_157 :
case V_158 :
case V_160 :
if ( ! F_60 ( V_146 , V_147 , & V_178 ) )
return - V_127 ;
break;
case V_161 :
case V_153 :
case V_152 :
break;
default:
return - V_127 ;
}
if ( V_150 -> V_151 != V_152 ) {
if ( V_150 -> V_156 < V_178 || V_150 -> V_156 > V_147 + 4 || V_150 -> V_156 & 3 )
return - V_127 ;
if ( V_150 -> V_156 < V_147 &&
! F_58 ( V_181 , V_182 , V_147 - V_150 -> V_156 ) )
return - V_127 ;
}
if ( V_150 -> V_148 < V_178 || V_150 -> V_148 > V_147 + 4 || V_150 -> V_148 & 3 )
return - V_127 ;
V_146 += V_150 -> V_148 ;
V_147 -= V_150 -> V_148 ;
}
return V_147 == 0 ? 0 : - V_127 ;
}
static int F_62 ( struct V_10 * V_11 ,
struct V_14 * V_15 ,
struct V_183 * V_184 ,
struct V_16 * V_28 ,
const struct V_30 * V_146 )
{
if ( ! F_56 ( V_146 , V_11 ) )
return 0 ;
return F_30 ( V_11 , V_15 , V_28 ,
F_42 ( F_43 ( V_184 -> V_15 ) . V_11 ) ,
F_43 ( V_184 -> V_15 ) . V_20 ,
V_184 -> V_29 -> V_132 , V_185 , V_184 -> V_29 ) ;
}
static int F_63 ( struct V_102 * V_103 ,
struct V_14 * V_15 ,
struct V_183 * V_184 ,
struct V_16 * V_28 ,
const struct V_30 * V_146 )
{
if ( V_146 != NULL ) {
struct V_144 V_145 ;
V_145 . V_171 = V_103 -> V_107 ;
#if F_14 ( V_62 )
if ( V_103 -> V_107 == V_63 ) {
struct V_117 * V_118 =
F_34 ( (struct V_10 * ) V_103 ) ;
V_145 . V_170 = V_118 -> V_119 . V_174 ;
V_145 . V_68 = V_118 -> V_120 . V_174 ;
} else
#endif
{
V_145 . V_170 = & V_103 -> V_111 ;
V_145 . V_68 = & V_103 -> V_112 ;
}
V_145 . V_155 = V_103 -> V_186 ;
V_145 . V_159 = F_57 ( V_103 -> V_110 ) ;
V_145 . V_162 = 0 ;
if ( ! F_54 ( V_146 , & V_145 ) )
return 0 ;
}
return F_32 ( V_103 , V_15 , V_28 ,
F_43 ( V_184 -> V_15 ) . V_20 ,
V_184 -> V_29 -> V_132 , V_185 , V_184 -> V_29 ) ;
}
static inline void F_64 ( const struct V_10 * V_11 ,
const struct V_187 * V_17 ,
struct V_144 * V_145 )
{
struct V_188 * V_189 = F_65 ( V_17 ) ;
#if F_14 ( V_62 )
if ( V_11 -> V_41 == V_63 ) {
if ( V_17 -> V_190 -> V_171 == V_63 ) {
V_145 -> V_170 = F_66 ( V_17 ) -> V_191 . V_174 ;
V_145 -> V_68 = F_66 ( V_17 ) -> V_192 . V_174 ;
} else if ( V_17 -> V_190 -> V_171 == V_6 ) {
F_67 ( V_189 -> V_191 ,
& V_145 -> V_193 ) ;
F_67 ( V_189 -> V_192 ,
& V_145 -> V_194 ) ;
V_145 -> V_170 = V_145 -> V_193 . V_174 ;
V_145 -> V_68 = V_145 -> V_194 . V_174 ;
}
} else
#endif
{
V_145 -> V_170 = & V_189 -> V_191 ;
V_145 -> V_68 = & V_189 -> V_192 ;
}
}
static int F_68 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_187 * V_17 ,
struct V_18 * V_19 ,
T_1 V_20 , T_1 V_21 ,
const struct V_23 * V_24 )
{
const struct V_188 * V_189 = F_65 ( V_17 ) ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
struct V_27 * V_28 ;
struct V_23 * V_29 ;
long T_3 ;
V_29 = F_10 ( V_15 , V_20 , V_21 , V_24 -> V_36 , sizeof( * V_28 ) ,
V_185 ) ;
if ( ! V_29 )
return - V_37 ;
V_28 = F_11 ( V_29 ) ;
V_28 -> V_40 = V_11 -> V_41 ;
V_28 -> V_42 = V_195 ;
V_28 -> V_43 = 1 ;
V_28 -> V_44 = V_17 -> V_196 ;
V_28 -> V_45 . V_46 = V_11 -> V_47 ;
F_12 ( V_17 , V_28 -> V_45 . V_48 ) ;
T_3 = V_17 -> V_95 - V_106 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_28 -> V_45 . V_49 = V_26 -> V_50 ;
V_28 -> V_45 . V_51 = V_189 -> V_197 ;
V_28 -> V_45 . V_53 [ 0 ] = V_189 -> V_191 ;
V_28 -> V_45 . V_55 [ 0 ] = V_189 -> V_192 ;
V_28 -> V_90 = F_69 ( T_3 ) ;
V_28 -> V_115 = 0 ;
V_28 -> V_116 = 0 ;
V_28 -> V_71 = F_16 ( V_19 , F_17 ( V_11 ) ) ;
V_28 -> V_72 = 0 ;
#if F_14 ( V_62 )
if ( V_28 -> V_40 == V_63 ) {
struct V_144 V_145 ;
F_64 ( V_11 , V_17 , & V_145 ) ;
memcpy ( V_28 -> V_45 . V_53 , V_145 . V_170 , sizeof( struct V_66 ) ) ;
memcpy ( V_28 -> V_45 . V_55 , V_145 . V_68 , sizeof( struct V_66 ) ) ;
}
#endif
return F_28 ( V_15 , V_29 ) ;
}
static int F_70 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_183 * V_184 ,
struct V_16 * V_28 ,
const struct V_30 * V_146 )
{
struct V_144 V_145 ;
struct V_12 * V_13 = F_31 ( V_11 ) ;
struct V_198 * V_199 ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
int V_200 , V_201 ;
int V_202 , V_203 ;
int V_124 = 0 ;
V_201 = V_184 -> args [ 3 ] ;
V_203 = V_184 -> args [ 4 ] ;
if ( V_201 > 0 )
V_201 -- ;
V_145 . V_171 = V_11 -> V_41 ;
F_71 ( & V_13 -> V_204 . V_205 ) ;
V_199 = V_13 -> V_204 . V_206 ;
if ( ! V_199 || ! V_199 -> V_207 )
goto V_84;
if ( V_146 != NULL ) {
V_145 . V_155 = V_26 -> V_175 ;
V_145 . V_162 = V_11 -> V_176 ;
}
for ( V_200 = V_201 ; V_200 < V_199 -> V_208 ; V_200 ++ ) {
struct V_187 * V_17 , * V_209 = V_199 -> V_210 [ V_200 ] ;
V_202 = 0 ;
for ( V_17 = V_209 ; V_17 ; V_202 ++ , V_17 = V_17 -> V_211 ) {
struct V_188 * V_189 = F_65 ( V_17 ) ;
if ( V_202 < V_203 )
continue;
if ( V_28 -> V_45 . V_51 != V_189 -> V_197 &&
V_28 -> V_45 . V_51 )
continue;
if ( V_146 ) {
F_64 ( V_11 , V_17 , & V_145 ) ;
V_145 . V_159 = F_57 ( V_189 -> V_197 ) ;
if ( ! F_54 ( V_146 , & V_145 ) )
continue;
}
V_124 = F_68 ( V_15 , V_11 , V_17 ,
F_42 ( F_43 ( V_184 -> V_15 ) . V_11 ) ,
F_43 ( V_184 -> V_15 ) . V_20 ,
V_184 -> V_29 -> V_132 , V_184 -> V_29 ) ;
if ( V_124 < 0 ) {
V_184 -> args [ 3 ] = V_200 + 1 ;
V_184 -> args [ 4 ] = V_202 ;
goto V_84;
}
}
V_203 = 0 ;
}
V_84:
F_72 ( & V_13 -> V_204 . V_205 ) ;
return V_124 ;
}
void F_73 ( struct V_121 * V_122 , struct V_14 * V_15 ,
struct V_183 * V_184 , struct V_16 * V_28 , struct V_30 * V_146 )
{
int V_212 , V_213 ;
int V_214 , V_215 ;
struct V_126 * V_126 = F_37 ( V_15 -> V_11 ) ;
V_214 = V_184 -> args [ 1 ] ;
V_215 = V_213 = V_184 -> args [ 2 ] ;
if ( V_184 -> args [ 0 ] == 0 ) {
if ( ! ( V_28 -> V_216 & ( V_217 | V_218 ) ) )
goto V_219;
for ( V_212 = V_214 ; V_212 < V_220 ; V_212 ++ ) {
struct V_10 * V_11 ;
struct V_221 * V_222 ;
struct V_223 * V_224 ;
V_213 = 0 ;
V_224 = & V_122 -> V_225 [ V_212 ] ;
F_74 ( & V_224 -> V_226 ) ;
F_75 (sk, node, &ilb->head) {
struct V_25 * V_26 = F_8 ( V_11 ) ;
if ( ! F_76 ( F_37 ( V_11 ) , V_126 ) )
continue;
if ( V_213 < V_215 ) {
V_213 ++ ;
continue;
}
if ( V_28 -> V_128 != V_172 &&
V_11 -> V_41 != V_28 -> V_128 )
goto V_227;
if ( V_28 -> V_45 . V_49 != V_26 -> V_50 &&
V_28 -> V_45 . V_49 )
goto V_227;
if ( ! ( V_28 -> V_216 & V_217 ) ||
V_28 -> V_45 . V_51 ||
V_184 -> args [ 3 ] > 0 )
goto V_228;
if ( F_62 ( V_11 , V_15 , V_184 , V_28 , V_146 ) < 0 ) {
F_77 ( & V_224 -> V_226 ) ;
goto V_229;
}
V_228:
if ( ! ( V_28 -> V_216 & V_218 ) )
goto V_227;
if ( F_70 ( V_15 , V_11 , V_184 , V_28 , V_146 ) < 0 ) {
F_77 ( & V_224 -> V_226 ) ;
goto V_229;
}
V_227:
V_184 -> args [ 3 ] = 0 ;
V_184 -> args [ 4 ] = 0 ;
++ V_213 ;
}
F_77 ( & V_224 -> V_226 ) ;
V_215 = 0 ;
V_184 -> args [ 3 ] = 0 ;
V_184 -> args [ 4 ] = 0 ;
}
V_219:
V_184 -> args [ 0 ] = 1 ;
V_214 = V_213 = V_215 = 0 ;
}
if ( ! ( V_28 -> V_216 & ~ ( V_217 | V_218 ) ) )
goto V_84;
for ( V_212 = V_214 ; V_212 <= V_122 -> V_230 ; V_212 ++ ) {
struct V_231 * V_209 = & V_122 -> V_232 [ V_212 ] ;
T_5 * V_226 = F_78 ( V_122 , V_212 ) ;
struct V_10 * V_11 ;
struct V_221 * V_222 ;
V_213 = 0 ;
if ( F_79 ( & V_209 -> V_233 ) &&
F_79 ( & V_209 -> V_234 ) )
continue;
if ( V_212 > V_214 )
V_215 = 0 ;
F_74 ( V_226 ) ;
F_75 (sk, node, &head->chain) {
struct V_25 * V_26 = F_8 ( V_11 ) ;
if ( ! F_76 ( F_37 ( V_11 ) , V_126 ) )
continue;
if ( V_213 < V_215 )
goto V_235;
if ( ! ( V_28 -> V_216 & ( 1 << V_11 -> V_38 ) ) )
goto V_235;
if ( V_28 -> V_128 != V_172 &&
V_11 -> V_41 != V_28 -> V_128 )
goto V_235;
if ( V_28 -> V_45 . V_49 != V_26 -> V_50 &&
V_28 -> V_45 . V_49 )
goto V_235;
if ( V_28 -> V_45 . V_51 != V_26 -> V_52 &&
V_28 -> V_45 . V_51 )
goto V_235;
if ( F_62 ( V_11 , V_15 , V_184 , V_28 , V_146 ) < 0 ) {
F_77 ( V_226 ) ;
goto V_229;
}
V_235:
++ V_213 ;
}
if ( V_28 -> V_216 & V_236 ) {
struct V_102 * V_103 ;
F_80 (tw, node,
&head->twchain) {
if ( ! F_76 ( F_81 ( V_103 ) , V_126 ) )
continue;
if ( V_213 < V_215 )
goto V_237;
if ( V_28 -> V_128 != V_172 &&
V_103 -> V_107 != V_28 -> V_128 )
goto V_237;
if ( V_28 -> V_45 . V_49 != V_103 -> V_109 &&
V_28 -> V_45 . V_49 )
goto V_237;
if ( V_28 -> V_45 . V_51 != V_103 -> V_110 &&
V_28 -> V_45 . V_51 )
goto V_237;
if ( F_63 ( V_103 , V_15 , V_184 , V_28 , V_146 ) < 0 ) {
F_77 ( V_226 ) ;
goto V_229;
}
V_237:
++ V_213 ;
}
}
F_77 ( V_226 ) ;
}
V_229:
V_184 -> args [ 1 ] = V_212 ;
V_184 -> args [ 2 ] = V_213 ;
V_84:
;
}
static int F_82 ( struct V_14 * V_15 , struct V_183 * V_184 ,
struct V_16 * V_28 , struct V_30 * V_146 )
{
const struct V_1 * V_9 ;
int V_124 = 0 ;
V_9 = F_1 ( V_28 -> V_35 ) ;
if ( ! F_50 ( V_9 ) )
V_9 -> V_238 ( V_15 , V_184 , V_28 , V_146 ) ;
else
V_124 = F_51 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_124 ? : V_15 -> V_147 ;
}
static int F_83 ( struct V_14 * V_15 , struct V_183 * V_184 )
{
struct V_30 * V_146 = NULL ;
int V_239 = sizeof( struct V_16 ) ;
if ( F_84 ( V_184 -> V_29 , V_239 ) )
V_146 = F_85 ( V_184 -> V_29 , V_239 , V_240 ) ;
return F_82 ( V_15 , V_184 , F_11 ( V_184 -> V_29 ) , V_146 ) ;
}
static inline int F_86 ( int type )
{
switch ( type ) {
case V_241 :
return V_242 ;
case V_243 :
return V_244 ;
default:
return 0 ;
}
}
static int F_87 ( struct V_14 * V_15 , struct V_183 * V_184 )
{
struct V_245 * V_246 = F_11 ( V_184 -> V_29 ) ;
struct V_16 V_17 ;
struct V_30 * V_146 = NULL ;
int V_239 = sizeof( struct V_245 ) ;
V_17 . V_128 = V_172 ;
V_17 . V_35 = F_86 ( V_184 -> V_29 -> V_36 ) ;
V_17 . V_34 = V_246 -> V_34 ;
V_17 . V_216 = V_246 -> V_216 ;
V_17 . V_45 = V_246 -> V_45 ;
if ( F_84 ( V_184 -> V_29 , V_239 ) )
V_146 = F_85 ( V_184 -> V_29 , V_239 , V_240 ) ;
return F_82 ( V_15 , V_184 , & V_17 , V_146 ) ;
}
static int F_88 ( struct V_14 * V_123 ,
const struct V_23 * V_29 )
{
struct V_245 * V_246 = F_11 ( V_29 ) ;
struct V_16 V_17 ;
V_17 . V_128 = V_246 -> V_40 ;
V_17 . V_35 = F_86 ( V_29 -> V_36 ) ;
V_17 . V_34 = V_246 -> V_34 ;
V_17 . V_216 = V_246 -> V_216 ;
V_17 . V_45 = V_246 -> V_45 ;
return F_49 ( V_123 , V_29 , & V_17 ) ;
}
static int F_89 ( struct V_14 * V_15 , struct V_23 * V_29 )
{
int V_239 = sizeof( struct V_245 ) ;
struct V_126 * V_126 = F_37 ( V_15 -> V_11 ) ;
if ( V_29 -> V_36 >= V_247 ||
F_90 ( V_29 ) < V_239 )
return - V_127 ;
if ( V_29 -> V_22 & V_248 ) {
if ( F_84 ( V_29 , V_239 ) ) {
struct V_30 * V_31 ;
V_31 = F_85 ( V_29 , V_239 ,
V_240 ) ;
if ( V_31 == NULL ||
F_55 ( V_31 ) < sizeof( struct V_149 ) ||
F_61 ( F_26 ( V_31 ) , F_55 ( V_31 ) ) )
return - V_127 ;
}
{
struct V_249 V_250 = {
. V_238 = F_87 ,
} ;
return F_91 ( V_126 -> V_133 , V_15 , V_29 , & V_250 ) ;
}
}
return F_88 ( V_15 , V_29 ) ;
}
static int F_92 ( struct V_14 * V_15 , struct V_23 * V_251 )
{
int V_239 = sizeof( struct V_16 ) ;
struct V_126 * V_126 = F_37 ( V_15 -> V_11 ) ;
if ( F_90 ( V_251 ) < V_239 )
return - V_127 ;
if ( V_251 -> V_22 & V_248 ) {
if ( F_84 ( V_251 , V_239 ) ) {
struct V_30 * V_31 ;
V_31 = F_85 ( V_251 , V_239 ,
V_240 ) ;
if ( V_31 == NULL ||
F_55 ( V_31 ) < sizeof( struct V_149 ) ||
F_61 ( F_26 ( V_31 ) , F_55 ( V_31 ) ) )
return - V_127 ;
}
{
struct V_249 V_250 = {
. V_238 = F_83 ,
} ;
return F_91 ( V_126 -> V_133 , V_15 , V_251 , & V_250 ) ;
}
}
return F_49 ( V_15 , V_251 , F_11 ( V_251 ) ) ;
}
int F_93 ( const struct V_1 * V_251 )
{
const T_6 type = V_251 -> V_252 ;
int V_124 = - V_127 ;
if ( type >= V_253 )
goto V_84;
F_3 ( & V_7 ) ;
V_124 = - V_254 ;
if ( V_3 [ type ] == NULL ) {
V_3 [ type ] = V_251 ;
V_124 = 0 ;
}
F_6 ( & V_7 ) ;
V_84:
return V_124 ;
}
void F_94 ( const struct V_1 * V_251 )
{
const T_6 type = V_251 -> V_252 ;
if ( type >= V_253 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_7 F_95 ( void )
{
const int V_255 = ( V_253 *
sizeof( struct V_1 * ) ) ;
int V_124 = - V_131 ;
V_3 = F_96 ( V_255 , V_130 ) ;
if ( ! V_3 )
goto V_84;
V_124 = F_97 ( & V_1 ) ;
if ( V_124 )
goto V_256;
V_124 = F_97 ( & V_257 ) ;
if ( V_124 )
goto V_258;
F_98 ( F_89 ) ;
V_84:
return V_124 ;
V_258:
F_99 ( & V_1 ) ;
V_256:
F_100 ( V_3 ) ;
goto V_84;
}
static void T_8 F_101 ( void )
{
F_99 ( & V_257 ) ;
F_99 ( & V_1 ) ;
F_102 ( F_89 ) ;
F_100 ( V_3 ) ;
}
