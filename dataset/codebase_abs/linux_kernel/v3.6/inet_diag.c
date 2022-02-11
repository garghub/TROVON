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
T_1 V_18 , T_1 V_19 , T_2 V_20 ,
const struct V_21 * V_22 )
{
const struct V_23 * V_24 = F_8 ( V_11 ) ;
struct V_25 * V_26 ;
struct V_21 * V_27 ;
struct V_28 * V_29 ;
void * V_30 = NULL ;
const struct V_1 * V_9 ;
int V_31 = V_17 -> V_32 ;
V_9 = V_3 [ V_17 -> V_33 ] ;
F_9 ( V_9 == NULL ) ;
V_27 = F_10 ( V_15 , V_18 , V_19 , V_22 -> V_34 , sizeof( * V_26 ) ,
V_20 ) ;
if ( ! V_27 )
return - V_35 ;
V_26 = F_11 ( V_27 ) ;
F_9 ( V_11 -> V_36 == V_37 ) ;
V_26 -> V_38 = V_11 -> V_39 ;
V_26 -> V_40 = V_11 -> V_36 ;
V_26 -> V_41 = 0 ;
V_26 -> V_42 = 0 ;
V_26 -> V_43 . V_44 = V_11 -> V_45 ;
F_12 ( V_11 , V_26 -> V_43 . V_46 ) ;
V_26 -> V_43 . V_47 = V_24 -> V_48 ;
V_26 -> V_43 . V_49 = V_24 -> V_50 ;
V_26 -> V_43 . V_51 [ 0 ] = V_24 -> V_52 ;
V_26 -> V_43 . V_53 [ 0 ] = V_24 -> V_54 ;
if ( V_31 & ( 1 << ( V_55 - 1 ) ) )
if ( F_13 ( V_15 , V_55 , V_24 -> V_56 ) < 0 )
goto V_57;
#if F_14 ( V_58 )
if ( V_26 -> V_38 == V_59 ) {
const struct V_60 * V_61 = F_15 ( V_11 ) ;
* (struct V_62 * ) V_26 -> V_43 . V_51 = V_61 -> V_63 ;
* (struct V_62 * ) V_26 -> V_43 . V_53 = V_61 -> V_64 ;
if ( V_31 & ( 1 << ( V_65 - 1 ) ) )
if ( F_13 ( V_15 , V_65 , V_61 -> V_66 ) < 0 )
goto V_57;
}
#endif
V_26 -> V_67 = F_16 ( V_11 ) ;
V_26 -> V_68 = F_17 ( V_11 ) ;
if ( V_31 & ( 1 << ( V_69 - 1 ) ) ) {
struct V_70 V_71 = {
. V_72 = F_18 ( V_11 ) ,
. V_73 = V_11 -> V_74 ,
. V_75 = V_11 -> V_76 ,
. V_77 = F_19 ( V_11 ) ,
} ;
if ( F_20 ( V_15 , V_69 , sizeof( V_71 ) , & V_71 ) < 0 )
goto V_57;
}
if ( V_31 & ( 1 << ( V_78 - 1 ) ) )
if ( F_21 ( V_11 , V_15 , V_78 ) )
goto V_57;
if ( V_13 == NULL ) {
V_9 -> V_79 ( V_11 , V_26 , NULL ) ;
goto V_80;
}
#define F_22 ( T_3 ) DIV_ROUND_UP((tmo - jiffies) * 1000, HZ)
if ( V_13 -> V_81 == V_82 ) {
V_26 -> V_41 = 1 ;
V_26 -> V_42 = V_13 -> V_83 ;
V_26 -> V_84 = F_22 ( V_13 -> V_85 ) ;
} else if ( V_13 -> V_81 == V_86 ) {
V_26 -> V_41 = 4 ;
V_26 -> V_42 = V_13 -> V_87 ;
V_26 -> V_84 = F_22 ( V_13 -> V_85 ) ;
} else if ( F_23 ( & V_11 -> V_88 ) ) {
V_26 -> V_41 = 2 ;
V_26 -> V_42 = V_13 -> V_87 ;
V_26 -> V_84 = F_22 ( V_11 -> V_88 . V_89 ) ;
} else {
V_26 -> V_41 = 0 ;
V_26 -> V_84 = 0 ;
}
#undef F_22
if ( V_31 & ( 1 << ( V_90 - 1 ) ) ) {
V_29 = F_24 ( V_15 , V_90 ,
sizeof( struct V_91 ) ) ;
if ( ! V_29 )
goto V_57;
V_30 = F_25 ( V_29 ) ;
}
if ( ( V_31 & ( 1 << ( V_92 - 1 ) ) ) && V_13 -> V_93 )
if ( F_26 ( V_15 , V_92 ,
V_13 -> V_93 -> V_94 ) < 0 )
goto V_57;
V_9 -> V_79 ( V_11 , V_26 , V_30 ) ;
if ( V_11 -> V_36 < V_37 &&
V_13 -> V_93 && V_13 -> V_93 -> V_95 )
V_13 -> V_93 -> V_95 ( V_11 , V_31 , V_15 ) ;
V_80:
return F_27 ( V_15 , V_27 ) ;
V_57:
F_28 ( V_15 , V_27 ) ;
return - V_35 ;
}
static int F_29 ( struct V_10 * V_11 ,
struct V_14 * V_15 , struct V_16 * V_17 ,
T_1 V_18 , T_1 V_19 , T_2 V_20 ,
const struct V_21 * V_22 )
{
return F_7 ( V_11 , F_30 ( V_11 ) ,
V_15 , V_17 , V_18 , V_19 , V_20 , V_22 ) ;
}
static int F_31 ( struct V_96 * V_97 ,
struct V_14 * V_15 , struct V_16 * V_17 ,
T_1 V_18 , T_1 V_19 , T_2 V_20 ,
const struct V_21 * V_22 )
{
long T_3 ;
struct V_25 * V_26 ;
struct V_21 * V_27 ;
V_27 = F_10 ( V_15 , V_18 , V_19 , V_22 -> V_34 , sizeof( * V_26 ) ,
V_20 ) ;
if ( ! V_27 )
return - V_35 ;
V_26 = F_11 ( V_27 ) ;
F_9 ( V_97 -> V_98 != V_37 ) ;
T_3 = V_97 -> V_99 - V_100 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_26 -> V_38 = V_97 -> V_101 ;
V_26 -> V_42 = 0 ;
V_26 -> V_43 . V_44 = V_97 -> V_102 ;
F_12 ( V_97 , V_26 -> V_43 . V_46 ) ;
V_26 -> V_43 . V_47 = V_97 -> V_103 ;
V_26 -> V_43 . V_49 = V_97 -> V_104 ;
V_26 -> V_43 . V_51 [ 0 ] = V_97 -> V_105 ;
V_26 -> V_43 . V_53 [ 0 ] = V_97 -> V_106 ;
V_26 -> V_40 = V_97 -> V_107 ;
V_26 -> V_41 = 3 ;
V_26 -> V_84 = F_32 ( T_3 * 1000 , V_108 ) ;
V_26 -> V_109 = 0 ;
V_26 -> V_110 = 0 ;
V_26 -> V_67 = 0 ;
V_26 -> V_68 = 0 ;
#if F_14 ( V_58 )
if ( V_97 -> V_101 == V_59 ) {
const struct V_111 * V_112 =
F_33 ( (struct V_10 * ) V_97 ) ;
* (struct V_62 * ) V_26 -> V_43 . V_51 = V_112 -> V_113 ;
* (struct V_62 * ) V_26 -> V_43 . V_53 = V_112 -> V_114 ;
}
#endif
return F_27 ( V_15 , V_27 ) ;
}
static int F_34 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_16 * V_26 , T_1 V_18 , T_1 V_19 , T_2 V_20 ,
const struct V_21 * V_22 )
{
if ( V_11 -> V_36 == V_37 )
return F_31 ( (struct V_96 * ) V_11 ,
V_15 , V_26 , V_18 , V_19 , V_20 ,
V_22 ) ;
return F_29 ( V_11 , V_15 , V_26 , V_18 , V_19 , V_20 , V_22 ) ;
}
int F_35 ( struct V_115 * V_116 , struct V_14 * V_117 ,
const struct V_21 * V_27 , struct V_16 * V_17 )
{
int V_118 ;
struct V_10 * V_11 ;
struct V_14 * V_119 ;
struct V_120 * V_120 = F_36 ( V_117 -> V_11 ) ;
V_118 = - V_121 ;
if ( V_17 -> V_122 == V_6 ) {
V_11 = F_37 ( V_120 , V_116 , V_17 -> V_43 . V_53 [ 0 ] ,
V_17 -> V_43 . V_49 , V_17 -> V_43 . V_51 [ 0 ] ,
V_17 -> V_43 . V_47 , V_17 -> V_43 . V_44 ) ;
}
#if F_14 ( V_58 )
else if ( V_17 -> V_122 == V_59 ) {
V_11 = F_38 ( V_120 , V_116 ,
(struct V_62 * ) V_17 -> V_43 . V_53 ,
V_17 -> V_43 . V_49 ,
(struct V_62 * ) V_17 -> V_43 . V_51 ,
V_17 -> V_43 . V_47 ,
V_17 -> V_43 . V_44 ) ;
}
#endif
else {
goto V_123;
}
V_118 = - V_8 ;
if ( V_11 == NULL )
goto V_123;
V_118 = F_39 ( V_11 , V_17 -> V_43 . V_46 ) ;
if ( V_118 )
goto V_80;
V_119 = F_40 ( sizeof( struct V_25 ) +
sizeof( struct V_70 ) +
sizeof( struct V_91 ) + 64 , V_124 ) ;
if ( ! V_119 ) {
V_118 = - V_125 ;
goto V_80;
}
V_118 = F_34 ( V_11 , V_119 , V_17 ,
F_41 ( V_117 ) . V_18 ,
V_27 -> V_126 , 0 , V_27 ) ;
if ( V_118 < 0 ) {
F_42 ( V_118 == - V_35 ) ;
F_43 ( V_119 ) ;
goto V_80;
}
V_118 = F_44 ( V_120 -> V_127 , V_119 , F_41 ( V_117 ) . V_18 ,
V_128 ) ;
if ( V_118 > 0 )
V_118 = 0 ;
V_80:
if ( V_11 ) {
if ( V_11 -> V_36 == V_37 )
F_45 ( (struct V_96 * ) V_11 ) ;
else
F_46 ( V_11 ) ;
}
V_123:
return V_118 ;
}
static int F_47 ( struct V_14 * V_117 ,
const struct V_21 * V_27 ,
struct V_16 * V_17 )
{
const struct V_1 * V_9 ;
int V_118 ;
V_9 = F_1 ( V_17 -> V_33 ) ;
if ( F_48 ( V_9 ) )
V_118 = F_49 ( V_9 ) ;
else
V_118 = V_9 -> V_129 ( V_117 , V_27 , V_17 ) ;
F_5 ( V_9 ) ;
return V_118 ;
}
static int F_50 ( const T_4 * V_130 , const T_4 * V_131 , int V_132 )
{
int V_133 = V_132 >> 5 ;
V_132 &= 0x1f ;
if ( V_133 ) {
if ( memcmp ( V_130 , V_131 , V_133 << 2 ) )
return 0 ;
}
if ( V_132 ) {
T_4 V_134 , V_135 ;
T_4 V_136 ;
V_134 = V_130 [ V_133 ] ;
V_135 = V_131 [ V_133 ] ;
V_136 = F_51 ( ( 0xffffffff ) << ( 32 - V_132 ) ) ;
if ( ( V_134 ^ V_135 ) & V_136 )
return 0 ;
}
return 1 ;
}
static int F_52 ( const struct V_28 * V_137 ,
const struct V_138 * V_139 )
{
const void * V_140 = F_25 ( V_137 ) ;
int V_141 = F_53 ( V_137 ) ;
while ( V_141 > 0 ) {
int V_142 = 1 ;
const struct V_143 * V_144 = V_140 ;
switch ( V_144 -> V_145 ) {
case V_146 :
break;
case V_147 :
V_142 = 0 ;
break;
case V_148 :
V_142 = V_139 -> V_149 >= V_144 [ 1 ] . V_150 ;
break;
case V_151 :
V_142 = V_139 -> V_149 <= V_144 [ 1 ] . V_150 ;
break;
case V_152 :
V_142 = V_139 -> V_153 >= V_144 [ 1 ] . V_150 ;
break;
case V_154 :
V_142 = V_139 -> V_153 <= V_144 [ 1 ] . V_150 ;
break;
case V_155 :
V_142 = ! ( V_139 -> V_156 & V_157 ) ;
break;
case V_158 :
case V_159 : {
struct V_160 * V_161 ;
T_4 * V_162 ;
V_161 = (struct V_160 * ) ( V_144 + 1 ) ;
if ( V_161 -> V_163 != - 1 &&
V_161 -> V_163 != ( V_144 -> V_145 == V_158 ?
V_139 -> V_149 : V_139 -> V_153 ) ) {
V_142 = 0 ;
break;
}
if ( V_161 -> V_164 == 0 )
break;
if ( V_144 -> V_145 == V_158 )
V_162 = V_139 -> V_165 ;
else
V_162 = V_139 -> V_64 ;
if ( F_50 ( V_162 , V_161 -> V_162 ,
V_161 -> V_164 ) )
break;
if ( V_139 -> V_166 == V_59 &&
V_161 -> V_166 == V_6 ) {
if ( V_162 [ 0 ] == 0 && V_162 [ 1 ] == 0 &&
V_162 [ 2 ] == F_51 ( 0xffff ) &&
F_50 ( V_162 + 3 , V_161 -> V_162 ,
V_161 -> V_164 ) )
break;
}
V_142 = 0 ;
break;
}
}
if ( V_142 ) {
V_141 -= V_144 -> V_142 ;
V_140 += V_144 -> V_142 ;
} else {
V_141 -= V_144 -> V_150 ;
V_140 += V_144 -> V_150 ;
}
}
return V_141 == 0 ;
}
int F_54 ( const struct V_28 * V_140 , struct V_10 * V_11 )
{
struct V_138 V_139 ;
struct V_23 * V_24 = F_8 ( V_11 ) ;
if ( V_140 == NULL )
return 1 ;
V_139 . V_166 = V_11 -> V_39 ;
#if F_14 ( V_58 )
if ( V_139 . V_166 == V_59 ) {
struct V_60 * V_61 = F_15 ( V_11 ) ;
V_139 . V_165 = V_61 -> V_63 . V_167 ;
V_139 . V_64 = V_61 -> V_64 . V_167 ;
} else
#endif
{
V_139 . V_165 = & V_24 -> V_52 ;
V_139 . V_64 = & V_24 -> V_54 ;
}
V_139 . V_149 = V_24 -> V_168 ;
V_139 . V_153 = F_55 ( V_24 -> V_50 ) ;
V_139 . V_156 = V_11 -> V_169 ;
return F_52 ( V_140 , & V_139 ) ;
}
static int F_56 ( const void * V_140 , int V_141 , int V_170 )
{
while ( V_141 >= 0 ) {
const struct V_143 * V_144 = V_140 ;
if ( V_170 > V_141 )
return 0 ;
if ( V_170 == V_141 )
return 1 ;
if ( V_144 -> V_142 < 4 || V_144 -> V_142 & 3 )
return 0 ;
V_141 -= V_144 -> V_142 ;
V_140 += V_144 -> V_142 ;
}
return 0 ;
}
static int F_57 ( const void * V_171 , int V_172 )
{
const void * V_140 = V_171 ;
int V_141 = V_172 ;
while ( V_141 > 0 ) {
const struct V_143 * V_144 = V_140 ;
switch ( V_144 -> V_145 ) {
case V_155 :
case V_158 :
case V_159 :
case V_148 :
case V_151 :
case V_152 :
case V_154 :
case V_147 :
if ( V_144 -> V_150 < 4 || V_144 -> V_150 > V_141 + 4 || V_144 -> V_150 & 3 )
return - V_121 ;
if ( V_144 -> V_150 < V_141 &&
! F_56 ( V_171 , V_172 , V_141 - V_144 -> V_150 ) )
return - V_121 ;
break;
case V_146 :
break;
default:
return - V_121 ;
}
if ( V_144 -> V_142 < 4 || V_144 -> V_142 > V_141 + 4 || V_144 -> V_142 & 3 )
return - V_121 ;
V_140 += V_144 -> V_142 ;
V_141 -= V_144 -> V_142 ;
}
return V_141 == 0 ? 0 : - V_121 ;
}
static int F_58 ( struct V_10 * V_11 ,
struct V_14 * V_15 ,
struct V_173 * V_174 ,
struct V_16 * V_26 ,
const struct V_28 * V_140 )
{
if ( ! F_54 ( V_140 , V_11 ) )
return 0 ;
return F_29 ( V_11 , V_15 , V_26 ,
F_41 ( V_174 -> V_15 ) . V_18 ,
V_174 -> V_27 -> V_126 , V_175 , V_174 -> V_27 ) ;
}
static int F_59 ( struct V_96 * V_97 ,
struct V_14 * V_15 ,
struct V_173 * V_174 ,
struct V_16 * V_26 ,
const struct V_28 * V_140 )
{
if ( V_140 != NULL ) {
struct V_138 V_139 ;
V_139 . V_166 = V_97 -> V_101 ;
#if F_14 ( V_58 )
if ( V_97 -> V_101 == V_59 ) {
struct V_111 * V_112 =
F_33 ( (struct V_10 * ) V_97 ) ;
V_139 . V_165 = V_112 -> V_113 . V_167 ;
V_139 . V_64 = V_112 -> V_114 . V_167 ;
} else
#endif
{
V_139 . V_165 = & V_97 -> V_105 ;
V_139 . V_64 = & V_97 -> V_106 ;
}
V_139 . V_149 = V_97 -> V_176 ;
V_139 . V_153 = F_55 ( V_97 -> V_104 ) ;
V_139 . V_156 = 0 ;
if ( ! F_52 ( V_140 , & V_139 ) )
return 0 ;
}
return F_31 ( V_97 , V_15 , V_26 ,
F_41 ( V_174 -> V_15 ) . V_18 ,
V_174 -> V_27 -> V_126 , V_175 , V_174 -> V_27 ) ;
}
static int F_60 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_177 * V_17 , T_1 V_18 , T_1 V_19 ,
const struct V_21 * V_22 )
{
const struct V_178 * V_179 = F_61 ( V_17 ) ;
struct V_23 * V_24 = F_8 ( V_11 ) ;
struct V_25 * V_26 ;
struct V_21 * V_27 ;
long T_3 ;
V_27 = F_10 ( V_15 , V_18 , V_19 , V_22 -> V_34 , sizeof( * V_26 ) ,
V_175 ) ;
if ( ! V_27 )
return - V_35 ;
V_26 = F_11 ( V_27 ) ;
V_26 -> V_38 = V_11 -> V_39 ;
V_26 -> V_40 = V_180 ;
V_26 -> V_41 = 1 ;
V_26 -> V_42 = V_17 -> V_181 ;
V_26 -> V_43 . V_44 = V_11 -> V_45 ;
F_12 ( V_17 , V_26 -> V_43 . V_46 ) ;
T_3 = V_17 -> V_89 - V_100 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_26 -> V_43 . V_47 = V_24 -> V_48 ;
V_26 -> V_43 . V_49 = V_179 -> V_182 ;
V_26 -> V_43 . V_51 [ 0 ] = V_179 -> V_183 ;
V_26 -> V_43 . V_53 [ 0 ] = V_179 -> V_184 ;
V_26 -> V_84 = F_62 ( T_3 ) ;
V_26 -> V_109 = 0 ;
V_26 -> V_110 = 0 ;
V_26 -> V_67 = F_16 ( V_11 ) ;
V_26 -> V_68 = 0 ;
#if F_14 ( V_58 )
if ( V_26 -> V_38 == V_59 ) {
* (struct V_62 * ) V_26 -> V_43 . V_51 = F_63 ( V_17 ) -> V_183 ;
* (struct V_62 * ) V_26 -> V_43 . V_53 = F_63 ( V_17 ) -> V_184 ;
}
#endif
return F_27 ( V_15 , V_27 ) ;
}
static int F_64 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_173 * V_174 ,
struct V_16 * V_26 ,
const struct V_28 * V_140 )
{
struct V_138 V_139 ;
struct V_12 * V_13 = F_30 ( V_11 ) ;
struct V_185 * V_186 ;
struct V_23 * V_24 = F_8 ( V_11 ) ;
int V_187 , V_188 ;
int V_189 , V_190 ;
int V_118 = 0 ;
V_188 = V_174 -> args [ 3 ] ;
V_190 = V_174 -> args [ 4 ] ;
if ( V_188 > 0 )
V_188 -- ;
V_139 . V_166 = V_11 -> V_39 ;
F_65 ( & V_13 -> V_191 . V_192 ) ;
V_186 = V_13 -> V_191 . V_193 ;
if ( ! V_186 || ! V_186 -> V_194 )
goto V_80;
if ( V_140 != NULL ) {
V_139 . V_149 = V_24 -> V_168 ;
V_139 . V_156 = V_11 -> V_169 ;
}
for ( V_187 = V_188 ; V_187 < V_186 -> V_195 ; V_187 ++ ) {
struct V_177 * V_17 , * V_196 = V_186 -> V_197 [ V_187 ] ;
V_189 = 0 ;
for ( V_17 = V_196 ; V_17 ; V_189 ++ , V_17 = V_17 -> V_198 ) {
struct V_178 * V_179 = F_61 ( V_17 ) ;
if ( V_189 < V_190 )
continue;
if ( V_26 -> V_43 . V_49 != V_179 -> V_182 &&
V_26 -> V_43 . V_49 )
continue;
if ( V_140 ) {
V_139 . V_165 =
#if F_14 ( V_58 )
( V_139 . V_166 == V_59 ) ?
F_63 ( V_17 ) -> V_183 . V_167 :
#endif
& V_179 -> V_183 ;
V_139 . V_64 =
#if F_14 ( V_58 )
( V_139 . V_166 == V_59 ) ?
F_63 ( V_17 ) -> V_184 . V_167 :
#endif
& V_179 -> V_184 ;
V_139 . V_153 = F_55 ( V_179 -> V_182 ) ;
if ( ! F_52 ( V_140 , & V_139 ) )
continue;
}
V_118 = F_60 ( V_15 , V_11 , V_17 ,
F_41 ( V_174 -> V_15 ) . V_18 ,
V_174 -> V_27 -> V_126 , V_174 -> V_27 ) ;
if ( V_118 < 0 ) {
V_174 -> args [ 3 ] = V_187 + 1 ;
V_174 -> args [ 4 ] = V_189 ;
goto V_80;
}
}
V_190 = 0 ;
}
V_80:
F_66 ( & V_13 -> V_191 . V_192 ) ;
return V_118 ;
}
void F_67 ( struct V_115 * V_116 , struct V_14 * V_15 ,
struct V_173 * V_174 , struct V_16 * V_26 , struct V_28 * V_140 )
{
int V_199 , V_200 ;
int V_201 , V_202 ;
struct V_120 * V_120 = F_36 ( V_15 -> V_11 ) ;
V_201 = V_174 -> args [ 1 ] ;
V_202 = V_200 = V_174 -> args [ 2 ] ;
if ( V_174 -> args [ 0 ] == 0 ) {
if ( ! ( V_26 -> V_203 & ( V_204 | V_205 ) ) )
goto V_206;
for ( V_199 = V_201 ; V_199 < V_207 ; V_199 ++ ) {
struct V_10 * V_11 ;
struct V_208 * V_209 ;
struct V_210 * V_211 ;
V_200 = 0 ;
V_211 = & V_116 -> V_212 [ V_199 ] ;
F_68 ( & V_211 -> V_213 ) ;
F_69 (sk, node, &ilb->head) {
struct V_23 * V_24 = F_8 ( V_11 ) ;
if ( ! F_70 ( F_36 ( V_11 ) , V_120 ) )
continue;
if ( V_200 < V_202 ) {
V_200 ++ ;
continue;
}
if ( V_26 -> V_122 != V_214 &&
V_11 -> V_39 != V_26 -> V_122 )
goto V_215;
if ( V_26 -> V_43 . V_47 != V_24 -> V_48 &&
V_26 -> V_43 . V_47 )
goto V_215;
if ( ! ( V_26 -> V_203 & V_204 ) ||
V_26 -> V_43 . V_49 ||
V_174 -> args [ 3 ] > 0 )
goto V_216;
if ( F_58 ( V_11 , V_15 , V_174 , V_26 , V_140 ) < 0 ) {
F_71 ( & V_211 -> V_213 ) ;
goto V_217;
}
V_216:
if ( ! ( V_26 -> V_203 & V_205 ) )
goto V_215;
if ( F_64 ( V_15 , V_11 , V_174 , V_26 , V_140 ) < 0 ) {
F_71 ( & V_211 -> V_213 ) ;
goto V_217;
}
V_215:
V_174 -> args [ 3 ] = 0 ;
V_174 -> args [ 4 ] = 0 ;
++ V_200 ;
}
F_71 ( & V_211 -> V_213 ) ;
V_202 = 0 ;
V_174 -> args [ 3 ] = 0 ;
V_174 -> args [ 4 ] = 0 ;
}
V_206:
V_174 -> args [ 0 ] = 1 ;
V_201 = V_200 = V_202 = 0 ;
}
if ( ! ( V_26 -> V_203 & ~ ( V_204 | V_205 ) ) )
goto V_80;
for ( V_199 = V_201 ; V_199 <= V_116 -> V_218 ; V_199 ++ ) {
struct V_219 * V_196 = & V_116 -> V_220 [ V_199 ] ;
T_5 * V_213 = F_72 ( V_116 , V_199 ) ;
struct V_10 * V_11 ;
struct V_208 * V_209 ;
V_200 = 0 ;
if ( F_73 ( & V_196 -> V_221 ) &&
F_73 ( & V_196 -> V_222 ) )
continue;
if ( V_199 > V_201 )
V_202 = 0 ;
F_68 ( V_213 ) ;
F_69 (sk, node, &head->chain) {
struct V_23 * V_24 = F_8 ( V_11 ) ;
if ( ! F_70 ( F_36 ( V_11 ) , V_120 ) )
continue;
if ( V_200 < V_202 )
goto V_223;
if ( ! ( V_26 -> V_203 & ( 1 << V_11 -> V_36 ) ) )
goto V_223;
if ( V_26 -> V_122 != V_214 &&
V_11 -> V_39 != V_26 -> V_122 )
goto V_223;
if ( V_26 -> V_43 . V_47 != V_24 -> V_48 &&
V_26 -> V_43 . V_47 )
goto V_223;
if ( V_26 -> V_43 . V_49 != V_24 -> V_50 &&
V_26 -> V_43 . V_49 )
goto V_223;
if ( F_58 ( V_11 , V_15 , V_174 , V_26 , V_140 ) < 0 ) {
F_71 ( V_213 ) ;
goto V_217;
}
V_223:
++ V_200 ;
}
if ( V_26 -> V_203 & V_224 ) {
struct V_96 * V_97 ;
F_74 (tw, node,
&head->twchain) {
if ( ! F_70 ( F_75 ( V_97 ) , V_120 ) )
continue;
if ( V_200 < V_202 )
goto V_225;
if ( V_26 -> V_122 != V_214 &&
V_97 -> V_101 != V_26 -> V_122 )
goto V_225;
if ( V_26 -> V_43 . V_47 != V_97 -> V_103 &&
V_26 -> V_43 . V_47 )
goto V_225;
if ( V_26 -> V_43 . V_49 != V_97 -> V_104 &&
V_26 -> V_43 . V_49 )
goto V_225;
if ( F_59 ( V_97 , V_15 , V_174 , V_26 , V_140 ) < 0 ) {
F_71 ( V_213 ) ;
goto V_217;
}
V_225:
++ V_200 ;
}
}
F_71 ( V_213 ) ;
}
V_217:
V_174 -> args [ 1 ] = V_199 ;
V_174 -> args [ 2 ] = V_200 ;
V_80:
;
}
static int F_76 ( struct V_14 * V_15 , struct V_173 * V_174 ,
struct V_16 * V_26 , struct V_28 * V_140 )
{
const struct V_1 * V_9 ;
V_9 = F_1 ( V_26 -> V_33 ) ;
if ( ! F_48 ( V_9 ) )
V_9 -> V_226 ( V_15 , V_174 , V_26 , V_140 ) ;
F_5 ( V_9 ) ;
return V_15 -> V_141 ;
}
static int F_77 ( struct V_14 * V_15 , struct V_173 * V_174 )
{
struct V_28 * V_140 = NULL ;
int V_227 = sizeof( struct V_16 ) ;
if ( F_78 ( V_174 -> V_27 , V_227 ) )
V_140 = F_79 ( V_174 -> V_27 , V_227 , V_228 ) ;
return F_76 ( V_15 , V_174 , F_11 ( V_174 -> V_27 ) , V_140 ) ;
}
static inline int F_80 ( int type )
{
switch ( type ) {
case V_229 :
return V_230 ;
case V_231 :
return V_232 ;
default:
return 0 ;
}
}
static int F_81 ( struct V_14 * V_15 , struct V_173 * V_174 )
{
struct V_233 * V_234 = F_11 ( V_174 -> V_27 ) ;
struct V_16 V_17 ;
struct V_28 * V_140 = NULL ;
int V_227 = sizeof( struct V_233 ) ;
V_17 . V_122 = V_214 ;
V_17 . V_33 = F_80 ( V_174 -> V_27 -> V_34 ) ;
V_17 . V_32 = V_234 -> V_32 ;
V_17 . V_203 = V_234 -> V_203 ;
V_17 . V_43 = V_234 -> V_43 ;
if ( F_78 ( V_174 -> V_27 , V_227 ) )
V_140 = F_79 ( V_174 -> V_27 , V_227 , V_228 ) ;
return F_76 ( V_15 , V_174 , & V_17 , V_140 ) ;
}
static int F_82 ( struct V_14 * V_117 ,
const struct V_21 * V_27 )
{
struct V_233 * V_234 = F_11 ( V_27 ) ;
struct V_16 V_17 ;
V_17 . V_122 = V_234 -> V_38 ;
V_17 . V_33 = F_80 ( V_27 -> V_34 ) ;
V_17 . V_32 = V_234 -> V_32 ;
V_17 . V_203 = V_234 -> V_203 ;
V_17 . V_43 = V_234 -> V_43 ;
return F_47 ( V_117 , V_27 , & V_17 ) ;
}
static int F_83 ( struct V_14 * V_15 , struct V_21 * V_27 )
{
int V_227 = sizeof( struct V_233 ) ;
struct V_120 * V_120 = F_36 ( V_15 -> V_11 ) ;
if ( V_27 -> V_34 >= V_235 ||
F_84 ( V_27 ) < V_227 )
return - V_121 ;
if ( V_27 -> V_20 & V_236 ) {
if ( F_78 ( V_27 , V_227 ) ) {
struct V_28 * V_29 ;
V_29 = F_79 ( V_27 , V_227 ,
V_228 ) ;
if ( V_29 == NULL ||
F_53 ( V_29 ) < sizeof( struct V_143 ) ||
F_57 ( F_25 ( V_29 ) , F_53 ( V_29 ) ) )
return - V_121 ;
}
{
struct V_237 V_238 = {
. V_226 = F_81 ,
} ;
return F_85 ( V_120 -> V_127 , V_15 , V_27 , & V_238 ) ;
}
}
return F_82 ( V_15 , V_27 ) ;
}
static int F_86 ( struct V_14 * V_15 , struct V_21 * V_239 )
{
int V_227 = sizeof( struct V_16 ) ;
struct V_120 * V_120 = F_36 ( V_15 -> V_11 ) ;
if ( F_84 ( V_239 ) < V_227 )
return - V_121 ;
if ( V_239 -> V_20 & V_236 ) {
if ( F_78 ( V_239 , V_227 ) ) {
struct V_28 * V_29 ;
V_29 = F_79 ( V_239 , V_227 ,
V_228 ) ;
if ( V_29 == NULL ||
F_53 ( V_29 ) < sizeof( struct V_143 ) ||
F_57 ( F_25 ( V_29 ) , F_53 ( V_29 ) ) )
return - V_121 ;
}
{
struct V_237 V_238 = {
. V_226 = F_77 ,
} ;
return F_85 ( V_120 -> V_127 , V_15 , V_239 , & V_238 ) ;
}
}
return F_47 ( V_15 , V_239 , F_11 ( V_239 ) ) ;
}
int F_87 ( const struct V_1 * V_239 )
{
const T_6 type = V_239 -> V_240 ;
int V_118 = - V_121 ;
if ( type >= V_241 )
goto V_80;
F_3 ( & V_7 ) ;
V_118 = - V_242 ;
if ( V_3 [ type ] == NULL ) {
V_3 [ type ] = V_239 ;
V_118 = 0 ;
}
F_6 ( & V_7 ) ;
V_80:
return V_118 ;
}
void F_88 ( const struct V_1 * V_239 )
{
const T_6 type = V_239 -> V_240 ;
if ( type >= V_241 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_7 F_89 ( void )
{
const int V_243 = ( V_241 *
sizeof( struct V_1 * ) ) ;
int V_118 = - V_125 ;
V_3 = F_90 ( V_243 , V_124 ) ;
if ( ! V_3 )
goto V_80;
V_118 = F_91 ( & V_1 ) ;
if ( V_118 )
goto V_244;
V_118 = F_91 ( & V_245 ) ;
if ( V_118 )
goto V_246;
F_92 ( F_83 ) ;
V_80:
return V_118 ;
V_246:
F_93 ( & V_1 ) ;
V_244:
F_94 ( V_3 ) ;
goto V_80;
}
static void T_8 F_95 ( void )
{
F_93 ( & V_245 ) ;
F_93 ( & V_1 ) ;
F_96 ( F_83 ) ;
F_94 ( V_3 ) ;
}
