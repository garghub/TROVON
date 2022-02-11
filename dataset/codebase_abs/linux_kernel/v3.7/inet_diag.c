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
if ( V_33 & ( 1 << ( V_57 - 1 ) ) )
if ( F_13 ( V_15 , V_57 , V_26 -> V_58 ) < 0 )
goto V_59;
#if F_14 ( V_60 )
if ( V_28 -> V_40 == V_61 ) {
const struct V_62 * V_63 = F_15 ( V_11 ) ;
* (struct V_64 * ) V_28 -> V_45 . V_53 = V_63 -> V_65 ;
* (struct V_64 * ) V_28 -> V_45 . V_55 = V_63 -> V_66 ;
if ( V_33 & ( 1 << ( V_67 - 1 ) ) )
if ( F_13 ( V_15 , V_67 , V_63 -> V_68 ) < 0 )
goto V_59;
}
#endif
V_28 -> V_69 = F_16 ( V_19 , F_17 ( V_11 ) ) ;
V_28 -> V_70 = F_18 ( V_11 ) ;
if ( V_33 & ( 1 << ( V_71 - 1 ) ) ) {
struct V_72 V_73 = {
. V_74 = F_19 ( V_11 ) ,
. V_75 = V_11 -> V_76 ,
. V_77 = V_11 -> V_78 ,
. V_79 = F_20 ( V_11 ) ,
} ;
if ( F_21 ( V_15 , V_71 , sizeof( V_73 ) , & V_73 ) < 0 )
goto V_59;
}
if ( V_33 & ( 1 << ( V_80 - 1 ) ) )
if ( F_22 ( V_11 , V_15 , V_80 ) )
goto V_59;
if ( V_13 == NULL ) {
V_9 -> V_81 ( V_11 , V_28 , NULL ) ;
goto V_82;
}
#define F_23 ( T_3 ) DIV_ROUND_UP((tmo - jiffies) * 1000, HZ)
if ( V_13 -> V_83 == V_84 ) {
V_28 -> V_43 = 1 ;
V_28 -> V_44 = V_13 -> V_85 ;
V_28 -> V_86 = F_23 ( V_13 -> V_87 ) ;
} else if ( V_13 -> V_83 == V_88 ) {
V_28 -> V_43 = 4 ;
V_28 -> V_44 = V_13 -> V_89 ;
V_28 -> V_86 = F_23 ( V_13 -> V_87 ) ;
} else if ( F_24 ( & V_11 -> V_90 ) ) {
V_28 -> V_43 = 2 ;
V_28 -> V_44 = V_13 -> V_89 ;
V_28 -> V_86 = F_23 ( V_11 -> V_90 . V_91 ) ;
} else {
V_28 -> V_43 = 0 ;
V_28 -> V_86 = 0 ;
}
#undef F_23
if ( V_33 & ( 1 << ( V_92 - 1 ) ) ) {
V_31 = F_25 ( V_15 , V_92 ,
sizeof( struct V_93 ) ) ;
if ( ! V_31 )
goto V_59;
V_32 = F_26 ( V_31 ) ;
}
if ( ( V_33 & ( 1 << ( V_94 - 1 ) ) ) && V_13 -> V_95 )
if ( F_27 ( V_15 , V_94 ,
V_13 -> V_95 -> V_96 ) < 0 )
goto V_59;
V_9 -> V_81 ( V_11 , V_28 , V_32 ) ;
if ( V_11 -> V_38 < V_39 &&
V_13 -> V_95 && V_13 -> V_95 -> V_97 )
V_13 -> V_95 -> V_97 ( V_11 , V_33 , V_15 ) ;
V_82:
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
static int F_32 ( struct V_98 * V_99 ,
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
F_9 ( V_99 -> V_100 != V_39 ) ;
T_3 = V_99 -> V_101 - V_102 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_28 -> V_40 = V_99 -> V_103 ;
V_28 -> V_44 = 0 ;
V_28 -> V_45 . V_46 = V_99 -> V_104 ;
F_12 ( V_99 , V_28 -> V_45 . V_48 ) ;
V_28 -> V_45 . V_49 = V_99 -> V_105 ;
V_28 -> V_45 . V_51 = V_99 -> V_106 ;
V_28 -> V_45 . V_53 [ 0 ] = V_99 -> V_107 ;
V_28 -> V_45 . V_55 [ 0 ] = V_99 -> V_108 ;
V_28 -> V_42 = V_99 -> V_109 ;
V_28 -> V_43 = 3 ;
V_28 -> V_86 = F_33 ( T_3 * 1000 , V_110 ) ;
V_28 -> V_111 = 0 ;
V_28 -> V_112 = 0 ;
V_28 -> V_69 = 0 ;
V_28 -> V_70 = 0 ;
#if F_14 ( V_60 )
if ( V_99 -> V_103 == V_61 ) {
const struct V_113 * V_114 =
F_34 ( (struct V_10 * ) V_99 ) ;
* (struct V_64 * ) V_28 -> V_45 . V_53 = V_114 -> V_115 ;
* (struct V_64 * ) V_28 -> V_45 . V_55 = V_114 -> V_116 ;
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
return F_32 ( (struct V_98 * ) V_11 ,
V_15 , V_28 , V_20 , V_21 , V_22 ,
V_24 ) ;
return F_30 ( V_11 , V_15 , V_28 , V_19 , V_20 , V_21 , V_22 , V_24 ) ;
}
int F_36 ( struct V_117 * V_118 , struct V_14 * V_119 ,
const struct V_23 * V_29 , struct V_16 * V_17 )
{
int V_120 ;
struct V_10 * V_11 ;
struct V_14 * V_121 ;
struct V_122 * V_122 = F_37 ( V_119 -> V_11 ) ;
V_120 = - V_123 ;
if ( V_17 -> V_124 == V_6 ) {
V_11 = F_38 ( V_122 , V_118 , V_17 -> V_45 . V_55 [ 0 ] ,
V_17 -> V_45 . V_51 , V_17 -> V_45 . V_53 [ 0 ] ,
V_17 -> V_45 . V_49 , V_17 -> V_45 . V_46 ) ;
}
#if F_14 ( V_60 )
else if ( V_17 -> V_124 == V_61 ) {
V_11 = F_39 ( V_122 , V_118 ,
(struct V_64 * ) V_17 -> V_45 . V_55 ,
V_17 -> V_45 . V_51 ,
(struct V_64 * ) V_17 -> V_45 . V_53 ,
V_17 -> V_45 . V_49 ,
V_17 -> V_45 . V_46 ) ;
}
#endif
else {
goto V_125;
}
V_120 = - V_8 ;
if ( V_11 == NULL )
goto V_125;
V_120 = F_40 ( V_11 , V_17 -> V_45 . V_48 ) ;
if ( V_120 )
goto V_82;
V_121 = F_41 ( sizeof( struct V_27 ) +
sizeof( struct V_72 ) +
sizeof( struct V_93 ) + 64 , V_126 ) ;
if ( ! V_121 ) {
V_120 = - V_127 ;
goto V_82;
}
V_120 = F_35 ( V_11 , V_121 , V_17 ,
F_42 ( F_43 ( V_119 ) . V_128 ) ,
F_43 ( V_119 ) . V_20 ,
V_29 -> V_129 , 0 , V_29 ) ;
if ( V_120 < 0 ) {
F_44 ( V_120 == - V_37 ) ;
F_45 ( V_121 ) ;
goto V_82;
}
V_120 = F_46 ( V_122 -> V_130 , V_121 , F_43 ( V_119 ) . V_20 ,
V_131 ) ;
if ( V_120 > 0 )
V_120 = 0 ;
V_82:
if ( V_11 ) {
if ( V_11 -> V_38 == V_39 )
F_47 ( (struct V_98 * ) V_11 ) ;
else
F_48 ( V_11 ) ;
}
V_125:
return V_120 ;
}
static int F_49 ( struct V_14 * V_119 ,
const struct V_23 * V_29 ,
struct V_16 * V_17 )
{
const struct V_1 * V_9 ;
int V_120 ;
V_9 = F_1 ( V_17 -> V_35 ) ;
if ( F_50 ( V_9 ) )
V_120 = F_51 ( V_9 ) ;
else
V_120 = V_9 -> V_132 ( V_119 , V_29 , V_17 ) ;
F_5 ( V_9 ) ;
return V_120 ;
}
static int F_52 ( const T_4 * V_133 , const T_4 * V_134 , int V_135 )
{
int V_136 = V_135 >> 5 ;
V_135 &= 0x1f ;
if ( V_136 ) {
if ( memcmp ( V_133 , V_134 , V_136 << 2 ) )
return 0 ;
}
if ( V_135 ) {
T_4 V_137 , V_138 ;
T_4 V_139 ;
V_137 = V_133 [ V_136 ] ;
V_138 = V_134 [ V_136 ] ;
V_139 = F_53 ( ( 0xffffffff ) << ( 32 - V_135 ) ) ;
if ( ( V_137 ^ V_138 ) & V_139 )
return 0 ;
}
return 1 ;
}
static int F_54 ( const struct V_30 * V_140 ,
const struct V_141 * V_142 )
{
const void * V_143 = F_26 ( V_140 ) ;
int V_144 = F_55 ( V_140 ) ;
while ( V_144 > 0 ) {
int V_145 = 1 ;
const struct V_146 * V_147 = V_143 ;
switch ( V_147 -> V_148 ) {
case V_149 :
break;
case V_150 :
V_145 = 0 ;
break;
case V_151 :
V_145 = V_142 -> V_152 >= V_147 [ 1 ] . V_153 ;
break;
case V_154 :
V_145 = V_142 -> V_152 <= V_147 [ 1 ] . V_153 ;
break;
case V_155 :
V_145 = V_142 -> V_156 >= V_147 [ 1 ] . V_153 ;
break;
case V_157 :
V_145 = V_142 -> V_156 <= V_147 [ 1 ] . V_153 ;
break;
case V_158 :
V_145 = ! ( V_142 -> V_159 & V_160 ) ;
break;
case V_161 :
case V_162 : {
struct V_163 * V_164 ;
T_4 * V_165 ;
V_164 = (struct V_163 * ) ( V_147 + 1 ) ;
if ( V_164 -> V_166 != - 1 &&
V_164 -> V_166 != ( V_147 -> V_148 == V_161 ?
V_142 -> V_152 : V_142 -> V_156 ) ) {
V_145 = 0 ;
break;
}
if ( V_147 -> V_148 == V_161 )
V_165 = V_142 -> V_167 ;
else
V_165 = V_142 -> V_66 ;
if ( V_164 -> V_168 != V_169 &&
V_164 -> V_168 != V_142 -> V_168 ) {
if ( V_142 -> V_168 == V_61 &&
V_164 -> V_168 == V_6 ) {
if ( V_165 [ 0 ] == 0 && V_165 [ 1 ] == 0 &&
V_165 [ 2 ] == F_53 ( 0xffff ) &&
F_52 ( V_165 + 3 ,
V_164 -> V_165 ,
V_164 -> V_170 ) )
break;
}
V_145 = 0 ;
break;
}
if ( V_164 -> V_170 == 0 )
break;
if ( F_52 ( V_165 , V_164 -> V_165 ,
V_164 -> V_170 ) )
break;
V_145 = 0 ;
break;
}
}
if ( V_145 ) {
V_144 -= V_147 -> V_145 ;
V_143 += V_147 -> V_145 ;
} else {
V_144 -= V_147 -> V_153 ;
V_143 += V_147 -> V_153 ;
}
}
return V_144 == 0 ;
}
int F_56 ( const struct V_30 * V_143 , struct V_10 * V_11 )
{
struct V_141 V_142 ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
if ( V_143 == NULL )
return 1 ;
V_142 . V_168 = V_11 -> V_41 ;
#if F_14 ( V_60 )
if ( V_142 . V_168 == V_61 ) {
struct V_62 * V_63 = F_15 ( V_11 ) ;
V_142 . V_167 = V_63 -> V_65 . V_171 ;
V_142 . V_66 = V_63 -> V_66 . V_171 ;
} else
#endif
{
V_142 . V_167 = & V_26 -> V_54 ;
V_142 . V_66 = & V_26 -> V_56 ;
}
V_142 . V_152 = V_26 -> V_172 ;
V_142 . V_156 = F_57 ( V_26 -> V_52 ) ;
V_142 . V_159 = V_11 -> V_173 ;
return F_54 ( V_143 , & V_142 ) ;
}
static int F_58 ( const void * V_143 , int V_144 , int V_174 )
{
while ( V_144 >= 0 ) {
const struct V_146 * V_147 = V_143 ;
if ( V_174 > V_144 )
return 0 ;
if ( V_174 == V_144 )
return 1 ;
if ( V_147 -> V_145 < 4 || V_147 -> V_145 & 3 )
return 0 ;
V_144 -= V_147 -> V_145 ;
V_143 += V_147 -> V_145 ;
}
return 0 ;
}
static bool F_59 ( const struct V_146 * V_147 , int V_144 ,
int * V_175 )
{
int V_176 ;
struct V_163 * V_164 ;
* V_175 += sizeof( struct V_163 ) ;
if ( V_144 < * V_175 )
return false ;
V_164 = (struct V_163 * ) ( V_147 + 1 ) ;
switch ( V_164 -> V_168 ) {
case V_169 :
V_176 = 0 ;
break;
case V_6 :
V_176 = sizeof( struct V_177 ) ;
break;
case V_61 :
V_176 = sizeof( struct V_64 ) ;
break;
default:
return false ;
}
* V_175 += V_176 ;
if ( V_144 < * V_175 )
return false ;
if ( V_164 -> V_170 > 8 * V_176 )
return false ;
return true ;
}
static inline bool F_60 ( const struct V_146 * V_147 ,
int V_144 , int * V_175 )
{
* V_175 += sizeof( struct V_146 ) ;
if ( V_144 < * V_175 )
return false ;
return true ;
}
static int F_61 ( const void * V_178 , int V_179 )
{
const void * V_143 = V_178 ;
int V_144 = V_179 ;
while ( V_144 > 0 ) {
const struct V_146 * V_147 = V_143 ;
int V_175 = sizeof( struct V_146 ) ;
switch ( V_147 -> V_148 ) {
case V_161 :
case V_162 :
if ( ! F_59 ( V_143 , V_144 , & V_175 ) )
return - V_123 ;
break;
case V_151 :
case V_154 :
case V_155 :
case V_157 :
if ( ! F_60 ( V_143 , V_144 , & V_175 ) )
return - V_123 ;
break;
case V_158 :
case V_150 :
case V_149 :
break;
default:
return - V_123 ;
}
if ( V_147 -> V_148 != V_149 ) {
if ( V_147 -> V_153 < V_175 || V_147 -> V_153 > V_144 + 4 || V_147 -> V_153 & 3 )
return - V_123 ;
if ( V_147 -> V_153 < V_144 &&
! F_58 ( V_178 , V_179 , V_144 - V_147 -> V_153 ) )
return - V_123 ;
}
if ( V_147 -> V_145 < V_175 || V_147 -> V_145 > V_144 + 4 || V_147 -> V_145 & 3 )
return - V_123 ;
V_143 += V_147 -> V_145 ;
V_144 -= V_147 -> V_145 ;
}
return V_144 == 0 ? 0 : - V_123 ;
}
static int F_62 ( struct V_10 * V_11 ,
struct V_14 * V_15 ,
struct V_180 * V_181 ,
struct V_16 * V_28 ,
const struct V_30 * V_143 )
{
if ( ! F_56 ( V_143 , V_11 ) )
return 0 ;
return F_30 ( V_11 , V_15 , V_28 ,
F_42 ( F_43 ( V_181 -> V_15 ) . V_128 ) ,
F_43 ( V_181 -> V_15 ) . V_20 ,
V_181 -> V_29 -> V_129 , V_182 , V_181 -> V_29 ) ;
}
static int F_63 ( struct V_98 * V_99 ,
struct V_14 * V_15 ,
struct V_180 * V_181 ,
struct V_16 * V_28 ,
const struct V_30 * V_143 )
{
if ( V_143 != NULL ) {
struct V_141 V_142 ;
V_142 . V_168 = V_99 -> V_103 ;
#if F_14 ( V_60 )
if ( V_99 -> V_103 == V_61 ) {
struct V_113 * V_114 =
F_34 ( (struct V_10 * ) V_99 ) ;
V_142 . V_167 = V_114 -> V_115 . V_171 ;
V_142 . V_66 = V_114 -> V_116 . V_171 ;
} else
#endif
{
V_142 . V_167 = & V_99 -> V_107 ;
V_142 . V_66 = & V_99 -> V_108 ;
}
V_142 . V_152 = V_99 -> V_183 ;
V_142 . V_156 = F_57 ( V_99 -> V_106 ) ;
V_142 . V_159 = 0 ;
if ( ! F_54 ( V_143 , & V_142 ) )
return 0 ;
}
return F_32 ( V_99 , V_15 , V_28 ,
F_43 ( V_181 -> V_15 ) . V_20 ,
V_181 -> V_29 -> V_129 , V_182 , V_181 -> V_29 ) ;
}
static inline void F_64 ( const struct V_10 * V_11 ,
const struct V_184 * V_17 ,
struct V_141 * V_142 )
{
struct V_185 * V_186 = F_65 ( V_17 ) ;
#if F_14 ( V_60 )
if ( V_11 -> V_41 == V_61 ) {
if ( V_17 -> V_187 -> V_168 == V_61 ) {
V_142 -> V_167 = F_66 ( V_17 ) -> V_188 . V_171 ;
V_142 -> V_66 = F_66 ( V_17 ) -> V_189 . V_171 ;
} else if ( V_17 -> V_187 -> V_168 == V_6 ) {
F_67 ( V_186 -> V_188 ,
& V_142 -> V_190 ) ;
F_67 ( V_186 -> V_189 ,
& V_142 -> V_191 ) ;
V_142 -> V_167 = V_142 -> V_190 . V_171 ;
V_142 -> V_66 = V_142 -> V_191 . V_171 ;
}
} else
#endif
{
V_142 -> V_167 = & V_186 -> V_188 ;
V_142 -> V_66 = & V_186 -> V_189 ;
}
}
static int F_68 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_184 * V_17 ,
struct V_18 * V_19 ,
T_1 V_20 , T_1 V_21 ,
const struct V_23 * V_24 )
{
const struct V_185 * V_186 = F_65 ( V_17 ) ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
struct V_27 * V_28 ;
struct V_23 * V_29 ;
long T_3 ;
V_29 = F_10 ( V_15 , V_20 , V_21 , V_24 -> V_36 , sizeof( * V_28 ) ,
V_182 ) ;
if ( ! V_29 )
return - V_37 ;
V_28 = F_11 ( V_29 ) ;
V_28 -> V_40 = V_11 -> V_41 ;
V_28 -> V_42 = V_192 ;
V_28 -> V_43 = 1 ;
V_28 -> V_44 = V_17 -> V_193 ;
V_28 -> V_45 . V_46 = V_11 -> V_47 ;
F_12 ( V_17 , V_28 -> V_45 . V_48 ) ;
T_3 = V_17 -> V_91 - V_102 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_28 -> V_45 . V_49 = V_26 -> V_50 ;
V_28 -> V_45 . V_51 = V_186 -> V_194 ;
V_28 -> V_45 . V_53 [ 0 ] = V_186 -> V_188 ;
V_28 -> V_45 . V_55 [ 0 ] = V_186 -> V_189 ;
V_28 -> V_86 = F_69 ( T_3 ) ;
V_28 -> V_111 = 0 ;
V_28 -> V_112 = 0 ;
V_28 -> V_69 = F_16 ( V_19 , F_17 ( V_11 ) ) ;
V_28 -> V_70 = 0 ;
#if F_14 ( V_60 )
if ( V_28 -> V_40 == V_61 ) {
struct V_141 V_142 ;
F_64 ( V_11 , V_17 , & V_142 ) ;
memcpy ( V_28 -> V_45 . V_53 , V_142 . V_167 , sizeof( struct V_64 ) ) ;
memcpy ( V_28 -> V_45 . V_55 , V_142 . V_66 , sizeof( struct V_64 ) ) ;
}
#endif
return F_28 ( V_15 , V_29 ) ;
}
static int F_70 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_180 * V_181 ,
struct V_16 * V_28 ,
const struct V_30 * V_143 )
{
struct V_141 V_142 ;
struct V_12 * V_13 = F_31 ( V_11 ) ;
struct V_195 * V_196 ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
int V_197 , V_198 ;
int V_199 , V_200 ;
int V_120 = 0 ;
V_198 = V_181 -> args [ 3 ] ;
V_200 = V_181 -> args [ 4 ] ;
if ( V_198 > 0 )
V_198 -- ;
V_142 . V_168 = V_11 -> V_41 ;
F_71 ( & V_13 -> V_201 . V_202 ) ;
V_196 = V_13 -> V_201 . V_203 ;
if ( ! V_196 || ! V_196 -> V_204 )
goto V_82;
if ( V_143 != NULL ) {
V_142 . V_152 = V_26 -> V_172 ;
V_142 . V_159 = V_11 -> V_173 ;
}
for ( V_197 = V_198 ; V_197 < V_196 -> V_205 ; V_197 ++ ) {
struct V_184 * V_17 , * V_206 = V_196 -> V_207 [ V_197 ] ;
V_199 = 0 ;
for ( V_17 = V_206 ; V_17 ; V_199 ++ , V_17 = V_17 -> V_208 ) {
struct V_185 * V_186 = F_65 ( V_17 ) ;
if ( V_199 < V_200 )
continue;
if ( V_28 -> V_45 . V_51 != V_186 -> V_194 &&
V_28 -> V_45 . V_51 )
continue;
if ( V_143 ) {
F_64 ( V_11 , V_17 , & V_142 ) ;
V_142 . V_156 = F_57 ( V_186 -> V_194 ) ;
if ( ! F_54 ( V_143 , & V_142 ) )
continue;
}
V_120 = F_68 ( V_15 , V_11 , V_17 ,
F_42 ( F_43 ( V_181 -> V_15 ) . V_128 ) ,
F_43 ( V_181 -> V_15 ) . V_20 ,
V_181 -> V_29 -> V_129 , V_181 -> V_29 ) ;
if ( V_120 < 0 ) {
V_181 -> args [ 3 ] = V_197 + 1 ;
V_181 -> args [ 4 ] = V_199 ;
goto V_82;
}
}
V_200 = 0 ;
}
V_82:
F_72 ( & V_13 -> V_201 . V_202 ) ;
return V_120 ;
}
void F_73 ( struct V_117 * V_118 , struct V_14 * V_15 ,
struct V_180 * V_181 , struct V_16 * V_28 , struct V_30 * V_143 )
{
int V_209 , V_210 ;
int V_211 , V_212 ;
struct V_122 * V_122 = F_37 ( V_15 -> V_11 ) ;
V_211 = V_181 -> args [ 1 ] ;
V_212 = V_210 = V_181 -> args [ 2 ] ;
if ( V_181 -> args [ 0 ] == 0 ) {
if ( ! ( V_28 -> V_213 & ( V_214 | V_215 ) ) )
goto V_216;
for ( V_209 = V_211 ; V_209 < V_217 ; V_209 ++ ) {
struct V_10 * V_11 ;
struct V_218 * V_219 ;
struct V_220 * V_221 ;
V_210 = 0 ;
V_221 = & V_118 -> V_222 [ V_209 ] ;
F_74 ( & V_221 -> V_223 ) ;
F_75 (sk, node, &ilb->head) {
struct V_25 * V_26 = F_8 ( V_11 ) ;
if ( ! F_76 ( F_37 ( V_11 ) , V_122 ) )
continue;
if ( V_210 < V_212 ) {
V_210 ++ ;
continue;
}
if ( V_28 -> V_124 != V_169 &&
V_11 -> V_41 != V_28 -> V_124 )
goto V_224;
if ( V_28 -> V_45 . V_49 != V_26 -> V_50 &&
V_28 -> V_45 . V_49 )
goto V_224;
if ( ! ( V_28 -> V_213 & V_214 ) ||
V_28 -> V_45 . V_51 ||
V_181 -> args [ 3 ] > 0 )
goto V_225;
if ( F_62 ( V_11 , V_15 , V_181 , V_28 , V_143 ) < 0 ) {
F_77 ( & V_221 -> V_223 ) ;
goto V_226;
}
V_225:
if ( ! ( V_28 -> V_213 & V_215 ) )
goto V_224;
if ( F_70 ( V_15 , V_11 , V_181 , V_28 , V_143 ) < 0 ) {
F_77 ( & V_221 -> V_223 ) ;
goto V_226;
}
V_224:
V_181 -> args [ 3 ] = 0 ;
V_181 -> args [ 4 ] = 0 ;
++ V_210 ;
}
F_77 ( & V_221 -> V_223 ) ;
V_212 = 0 ;
V_181 -> args [ 3 ] = 0 ;
V_181 -> args [ 4 ] = 0 ;
}
V_216:
V_181 -> args [ 0 ] = 1 ;
V_211 = V_210 = V_212 = 0 ;
}
if ( ! ( V_28 -> V_213 & ~ ( V_214 | V_215 ) ) )
goto V_82;
for ( V_209 = V_211 ; V_209 <= V_118 -> V_227 ; V_209 ++ ) {
struct V_228 * V_206 = & V_118 -> V_229 [ V_209 ] ;
T_5 * V_223 = F_78 ( V_118 , V_209 ) ;
struct V_10 * V_11 ;
struct V_218 * V_219 ;
V_210 = 0 ;
if ( F_79 ( & V_206 -> V_230 ) &&
F_79 ( & V_206 -> V_231 ) )
continue;
if ( V_209 > V_211 )
V_212 = 0 ;
F_74 ( V_223 ) ;
F_75 (sk, node, &head->chain) {
struct V_25 * V_26 = F_8 ( V_11 ) ;
if ( ! F_76 ( F_37 ( V_11 ) , V_122 ) )
continue;
if ( V_210 < V_212 )
goto V_232;
if ( ! ( V_28 -> V_213 & ( 1 << V_11 -> V_38 ) ) )
goto V_232;
if ( V_28 -> V_124 != V_169 &&
V_11 -> V_41 != V_28 -> V_124 )
goto V_232;
if ( V_28 -> V_45 . V_49 != V_26 -> V_50 &&
V_28 -> V_45 . V_49 )
goto V_232;
if ( V_28 -> V_45 . V_51 != V_26 -> V_52 &&
V_28 -> V_45 . V_51 )
goto V_232;
if ( F_62 ( V_11 , V_15 , V_181 , V_28 , V_143 ) < 0 ) {
F_77 ( V_223 ) ;
goto V_226;
}
V_232:
++ V_210 ;
}
if ( V_28 -> V_213 & V_233 ) {
struct V_98 * V_99 ;
F_80 (tw, node,
&head->twchain) {
if ( ! F_76 ( F_81 ( V_99 ) , V_122 ) )
continue;
if ( V_210 < V_212 )
goto V_234;
if ( V_28 -> V_124 != V_169 &&
V_99 -> V_103 != V_28 -> V_124 )
goto V_234;
if ( V_28 -> V_45 . V_49 != V_99 -> V_105 &&
V_28 -> V_45 . V_49 )
goto V_234;
if ( V_28 -> V_45 . V_51 != V_99 -> V_106 &&
V_28 -> V_45 . V_51 )
goto V_234;
if ( F_63 ( V_99 , V_15 , V_181 , V_28 , V_143 ) < 0 ) {
F_77 ( V_223 ) ;
goto V_226;
}
V_234:
++ V_210 ;
}
}
F_77 ( V_223 ) ;
}
V_226:
V_181 -> args [ 1 ] = V_209 ;
V_181 -> args [ 2 ] = V_210 ;
V_82:
;
}
static int F_82 ( struct V_14 * V_15 , struct V_180 * V_181 ,
struct V_16 * V_28 , struct V_30 * V_143 )
{
const struct V_1 * V_9 ;
int V_120 = 0 ;
V_9 = F_1 ( V_28 -> V_35 ) ;
if ( ! F_50 ( V_9 ) )
V_9 -> V_235 ( V_15 , V_181 , V_28 , V_143 ) ;
else
V_120 = F_51 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_120 ? : V_15 -> V_144 ;
}
static int F_83 ( struct V_14 * V_15 , struct V_180 * V_181 )
{
struct V_30 * V_143 = NULL ;
int V_236 = sizeof( struct V_16 ) ;
if ( F_84 ( V_181 -> V_29 , V_236 ) )
V_143 = F_85 ( V_181 -> V_29 , V_236 , V_237 ) ;
return F_82 ( V_15 , V_181 , F_11 ( V_181 -> V_29 ) , V_143 ) ;
}
static inline int F_86 ( int type )
{
switch ( type ) {
case V_238 :
return V_239 ;
case V_240 :
return V_241 ;
default:
return 0 ;
}
}
static int F_87 ( struct V_14 * V_15 , struct V_180 * V_181 )
{
struct V_242 * V_243 = F_11 ( V_181 -> V_29 ) ;
struct V_16 V_17 ;
struct V_30 * V_143 = NULL ;
int V_236 = sizeof( struct V_242 ) ;
V_17 . V_124 = V_169 ;
V_17 . V_35 = F_86 ( V_181 -> V_29 -> V_36 ) ;
V_17 . V_34 = V_243 -> V_34 ;
V_17 . V_213 = V_243 -> V_213 ;
V_17 . V_45 = V_243 -> V_45 ;
if ( F_84 ( V_181 -> V_29 , V_236 ) )
V_143 = F_85 ( V_181 -> V_29 , V_236 , V_237 ) ;
return F_82 ( V_15 , V_181 , & V_17 , V_143 ) ;
}
static int F_88 ( struct V_14 * V_119 ,
const struct V_23 * V_29 )
{
struct V_242 * V_243 = F_11 ( V_29 ) ;
struct V_16 V_17 ;
V_17 . V_124 = V_243 -> V_40 ;
V_17 . V_35 = F_86 ( V_29 -> V_36 ) ;
V_17 . V_34 = V_243 -> V_34 ;
V_17 . V_213 = V_243 -> V_213 ;
V_17 . V_45 = V_243 -> V_45 ;
return F_49 ( V_119 , V_29 , & V_17 ) ;
}
static int F_89 ( struct V_14 * V_15 , struct V_23 * V_29 )
{
int V_236 = sizeof( struct V_242 ) ;
struct V_122 * V_122 = F_37 ( V_15 -> V_11 ) ;
if ( V_29 -> V_36 >= V_244 ||
F_90 ( V_29 ) < V_236 )
return - V_123 ;
if ( V_29 -> V_22 & V_245 ) {
if ( F_84 ( V_29 , V_236 ) ) {
struct V_30 * V_31 ;
V_31 = F_85 ( V_29 , V_236 ,
V_237 ) ;
if ( V_31 == NULL ||
F_55 ( V_31 ) < sizeof( struct V_146 ) ||
F_61 ( F_26 ( V_31 ) , F_55 ( V_31 ) ) )
return - V_123 ;
}
{
struct V_246 V_247 = {
. V_235 = F_87 ,
} ;
return F_91 ( V_122 -> V_130 , V_15 , V_29 , & V_247 ) ;
}
}
return F_88 ( V_15 , V_29 ) ;
}
static int F_92 ( struct V_14 * V_15 , struct V_23 * V_248 )
{
int V_236 = sizeof( struct V_16 ) ;
struct V_122 * V_122 = F_37 ( V_15 -> V_11 ) ;
if ( F_90 ( V_248 ) < V_236 )
return - V_123 ;
if ( V_248 -> V_22 & V_245 ) {
if ( F_84 ( V_248 , V_236 ) ) {
struct V_30 * V_31 ;
V_31 = F_85 ( V_248 , V_236 ,
V_237 ) ;
if ( V_31 == NULL ||
F_55 ( V_31 ) < sizeof( struct V_146 ) ||
F_61 ( F_26 ( V_31 ) , F_55 ( V_31 ) ) )
return - V_123 ;
}
{
struct V_246 V_247 = {
. V_235 = F_83 ,
} ;
return F_91 ( V_122 -> V_130 , V_15 , V_248 , & V_247 ) ;
}
}
return F_49 ( V_15 , V_248 , F_11 ( V_248 ) ) ;
}
int F_93 ( const struct V_1 * V_248 )
{
const T_6 type = V_248 -> V_249 ;
int V_120 = - V_123 ;
if ( type >= V_250 )
goto V_82;
F_3 ( & V_7 ) ;
V_120 = - V_251 ;
if ( V_3 [ type ] == NULL ) {
V_3 [ type ] = V_248 ;
V_120 = 0 ;
}
F_6 ( & V_7 ) ;
V_82:
return V_120 ;
}
void F_94 ( const struct V_1 * V_248 )
{
const T_6 type = V_248 -> V_249 ;
if ( type >= V_250 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_7 F_95 ( void )
{
const int V_252 = ( V_250 *
sizeof( struct V_1 * ) ) ;
int V_120 = - V_127 ;
V_3 = F_96 ( V_252 , V_126 ) ;
if ( ! V_3 )
goto V_82;
V_120 = F_97 ( & V_1 ) ;
if ( V_120 )
goto V_253;
V_120 = F_97 ( & V_254 ) ;
if ( V_120 )
goto V_255;
F_98 ( F_89 ) ;
V_82:
return V_120 ;
V_255:
F_99 ( & V_1 ) ;
V_253:
F_100 ( V_3 ) ;
goto V_82;
}
static void T_8 F_101 ( void )
{
F_99 ( & V_254 ) ;
F_99 ( & V_1 ) ;
F_102 ( F_89 ) ;
F_100 ( V_3 ) ;
}
