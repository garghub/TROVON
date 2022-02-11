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
void * V_28 = NULL ;
struct V_29 * V_30 = NULL ;
unsigned char * V_31 = F_9 ( V_15 ) ;
const struct V_1 * V_9 ;
int V_32 = V_17 -> V_33 ;
V_9 = V_3 [ V_17 -> V_34 ] ;
F_10 ( V_9 == NULL ) ;
V_27 = F_11 ( V_15 , V_18 , V_19 , V_22 -> V_35 , sizeof( * V_26 ) ) ;
V_27 -> V_20 = V_20 ;
V_26 = F_12 ( V_27 ) ;
F_10 ( V_11 -> V_36 == V_37 ) ;
if ( V_32 & ( 1 << ( V_38 - 1 ) ) )
V_30 = F_13 ( V_15 , V_38 , sizeof( * V_30 ) ) ;
V_26 -> V_39 = V_11 -> V_40 ;
V_26 -> V_41 = V_11 -> V_36 ;
V_26 -> V_42 = 0 ;
V_26 -> V_43 = 0 ;
V_26 -> V_44 . V_45 = V_11 -> V_46 ;
F_14 ( V_11 , V_26 -> V_44 . V_47 ) ;
V_26 -> V_44 . V_48 = V_24 -> V_49 ;
V_26 -> V_44 . V_50 = V_24 -> V_51 ;
V_26 -> V_44 . V_52 [ 0 ] = V_24 -> V_53 ;
V_26 -> V_44 . V_54 [ 0 ] = V_24 -> V_55 ;
if ( V_32 & ( 1 << ( V_56 - 1 ) ) )
F_15 ( V_15 , V_56 , V_24 -> V_57 ) ;
#if F_16 ( V_58 )
if ( V_26 -> V_39 == V_59 ) {
const struct V_60 * V_61 = F_17 ( V_11 ) ;
* (struct V_62 * ) V_26 -> V_44 . V_52 = V_61 -> V_63 ;
* (struct V_62 * ) V_26 -> V_44 . V_54 = V_61 -> V_64 ;
if ( V_32 & ( 1 << ( V_65 - 1 ) ) )
F_15 ( V_15 , V_65 , V_61 -> V_66 ) ;
}
#endif
V_26 -> V_67 = F_18 ( V_11 ) ;
V_26 -> V_68 = F_19 ( V_11 ) ;
if ( V_30 ) {
V_30 -> V_69 = F_20 ( V_11 ) ;
V_30 -> V_70 = V_11 -> V_71 ;
V_30 -> V_72 = V_11 -> V_73 ;
V_30 -> V_74 = F_21 ( V_11 ) ;
}
if ( V_32 & ( 1 << ( V_75 - 1 ) ) )
if ( F_22 ( V_11 , V_15 , V_75 ) )
goto V_76;
if ( V_13 == NULL ) {
V_9 -> V_77 ( V_11 , V_26 , NULL ) ;
goto V_78;
}
#define F_23 ( T_3 ) DIV_ROUND_UP((tmo - jiffies) * 1000, HZ)
if ( V_13 -> V_79 == V_80 ) {
V_26 -> V_42 = 1 ;
V_26 -> V_43 = V_13 -> V_81 ;
V_26 -> V_82 = F_23 ( V_13 -> V_83 ) ;
} else if ( V_13 -> V_79 == V_84 ) {
V_26 -> V_42 = 4 ;
V_26 -> V_43 = V_13 -> V_85 ;
V_26 -> V_82 = F_23 ( V_13 -> V_83 ) ;
} else if ( F_24 ( & V_11 -> V_86 ) ) {
V_26 -> V_42 = 2 ;
V_26 -> V_43 = V_13 -> V_85 ;
V_26 -> V_82 = F_23 ( V_11 -> V_86 . V_87 ) ;
} else {
V_26 -> V_42 = 0 ;
V_26 -> V_82 = 0 ;
}
#undef F_23
if ( V_32 & ( 1 << ( V_88 - 1 ) ) )
V_28 = F_13 ( V_15 , V_88 , sizeof( struct V_89 ) ) ;
if ( ( V_32 & ( 1 << ( V_90 - 1 ) ) ) && V_13 -> V_91 ) {
const T_4 V_92 = strlen ( V_13 -> V_91 -> V_93 ) ;
strcpy ( F_13 ( V_15 , V_90 , V_92 + 1 ) ,
V_13 -> V_91 -> V_93 ) ;
}
V_9 -> V_77 ( V_11 , V_26 , V_28 ) ;
if ( V_11 -> V_36 < V_37 &&
V_13 -> V_91 && V_13 -> V_91 -> V_94 )
V_13 -> V_91 -> V_94 ( V_11 , V_32 , V_15 ) ;
V_78:
V_27 -> V_95 = F_9 ( V_15 ) - V_31 ;
return V_15 -> V_92 ;
V_76:
V_96:
F_25 ( V_15 , V_31 ) ;
return - V_97 ;
}
static int F_26 ( struct V_10 * V_11 ,
struct V_14 * V_15 , struct V_16 * V_17 ,
T_1 V_18 , T_1 V_19 , T_2 V_20 ,
const struct V_21 * V_22 )
{
return F_7 ( V_11 , F_27 ( V_11 ) ,
V_15 , V_17 , V_18 , V_19 , V_20 , V_22 ) ;
}
static int F_28 ( struct V_98 * V_99 ,
struct V_14 * V_15 , struct V_16 * V_17 ,
T_1 V_18 , T_1 V_19 , T_2 V_20 ,
const struct V_21 * V_22 )
{
long T_3 ;
struct V_25 * V_26 ;
const unsigned char * V_100 = F_9 ( V_15 ) ;
struct V_21 * V_27 = F_11 ( V_15 , V_18 , V_19 ,
V_22 -> V_35 , sizeof( * V_26 ) ) ;
V_26 = F_12 ( V_27 ) ;
F_10 ( V_99 -> V_101 != V_37 ) ;
V_27 -> V_20 = V_20 ;
T_3 = V_99 -> V_102 - V_103 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_26 -> V_39 = V_99 -> V_104 ;
V_26 -> V_43 = 0 ;
V_26 -> V_44 . V_45 = V_99 -> V_105 ;
F_14 ( V_99 , V_26 -> V_44 . V_47 ) ;
V_26 -> V_44 . V_48 = V_99 -> V_106 ;
V_26 -> V_44 . V_50 = V_99 -> V_107 ;
V_26 -> V_44 . V_52 [ 0 ] = V_99 -> V_108 ;
V_26 -> V_44 . V_54 [ 0 ] = V_99 -> V_109 ;
V_26 -> V_41 = V_99 -> V_110 ;
V_26 -> V_42 = 3 ;
V_26 -> V_82 = F_29 ( T_3 * 1000 , V_111 ) ;
V_26 -> V_112 = 0 ;
V_26 -> V_113 = 0 ;
V_26 -> V_67 = 0 ;
V_26 -> V_68 = 0 ;
#if F_16 ( V_58 )
if ( V_99 -> V_104 == V_59 ) {
const struct V_114 * V_115 =
F_30 ( (struct V_10 * ) V_99 ) ;
* (struct V_62 * ) V_26 -> V_44 . V_52 = V_115 -> V_116 ;
* (struct V_62 * ) V_26 -> V_44 . V_54 = V_115 -> V_117 ;
}
#endif
V_27 -> V_95 = F_9 ( V_15 ) - V_100 ;
return V_15 -> V_92 ;
V_96:
F_25 ( V_15 , V_100 ) ;
return - V_97 ;
}
static int F_31 ( struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_16 * V_26 , T_1 V_18 , T_1 V_19 , T_2 V_20 ,
const struct V_21 * V_22 )
{
if ( V_11 -> V_36 == V_37 )
return F_28 ( (struct V_98 * ) V_11 ,
V_15 , V_26 , V_18 , V_19 , V_20 ,
V_22 ) ;
return F_26 ( V_11 , V_15 , V_26 , V_18 , V_19 , V_20 , V_22 ) ;
}
int F_32 ( struct V_118 * V_119 , struct V_14 * V_120 ,
const struct V_21 * V_27 , struct V_16 * V_17 )
{
int V_121 ;
struct V_10 * V_11 ;
struct V_14 * V_122 ;
V_121 = - V_123 ;
if ( V_17 -> V_124 == V_6 ) {
V_11 = F_33 ( & V_125 , V_119 , V_17 -> V_44 . V_54 [ 0 ] ,
V_17 -> V_44 . V_50 , V_17 -> V_44 . V_52 [ 0 ] ,
V_17 -> V_44 . V_48 , V_17 -> V_44 . V_45 ) ;
}
#if F_16 ( V_58 )
else if ( V_17 -> V_124 == V_59 ) {
V_11 = F_34 ( & V_125 , V_119 ,
(struct V_62 * ) V_17 -> V_44 . V_54 ,
V_17 -> V_44 . V_50 ,
(struct V_62 * ) V_17 -> V_44 . V_52 ,
V_17 -> V_44 . V_48 ,
V_17 -> V_44 . V_45 ) ;
}
#endif
else {
goto V_126;
}
V_121 = - V_8 ;
if ( V_11 == NULL )
goto V_126;
V_121 = F_35 ( V_11 , V_17 -> V_44 . V_47 ) ;
if ( V_121 )
goto V_78;
V_121 = - V_127 ;
V_122 = F_36 ( F_37 ( ( sizeof( struct V_25 ) +
sizeof( struct V_29 ) +
sizeof( struct V_89 ) + 64 ) ) ,
V_128 ) ;
if ( ! V_122 )
goto V_78;
V_121 = F_31 ( V_11 , V_122 , V_17 ,
F_38 ( V_120 ) . V_18 ,
V_27 -> V_129 , 0 , V_27 ) ;
if ( V_121 < 0 ) {
F_39 ( V_121 == - V_97 ) ;
F_40 ( V_122 ) ;
goto V_78;
}
V_121 = F_41 ( V_130 , V_122 , F_38 ( V_120 ) . V_18 ,
V_131 ) ;
if ( V_121 > 0 )
V_121 = 0 ;
V_78:
if ( V_11 ) {
if ( V_11 -> V_36 == V_37 )
F_42 ( (struct V_98 * ) V_11 ) ;
else
F_43 ( V_11 ) ;
}
V_126:
return V_121 ;
}
static int F_44 ( struct V_14 * V_120 ,
const struct V_21 * V_27 ,
struct V_16 * V_17 )
{
const struct V_1 * V_9 ;
int V_121 ;
V_9 = F_1 ( V_17 -> V_34 ) ;
if ( F_45 ( V_9 ) )
V_121 = F_46 ( V_9 ) ;
else
V_121 = V_9 -> V_132 ( V_120 , V_27 , V_17 ) ;
F_5 ( V_9 ) ;
return V_121 ;
}
static int F_47 ( const T_5 * V_133 , const T_5 * V_134 , int V_135 )
{
int V_136 = V_135 >> 5 ;
V_135 &= 0x1f ;
if ( V_136 ) {
if ( memcmp ( V_133 , V_134 , V_136 << 2 ) )
return 0 ;
}
if ( V_135 ) {
T_5 V_137 , V_138 ;
T_5 V_139 ;
V_137 = V_133 [ V_136 ] ;
V_138 = V_134 [ V_136 ] ;
V_139 = F_48 ( ( 0xffffffff ) << ( 32 - V_135 ) ) ;
if ( ( V_137 ^ V_138 ) & V_139 )
return 0 ;
}
return 1 ;
}
static int F_49 ( const struct V_140 * V_141 ,
const struct V_142 * V_143 )
{
const void * V_144 = F_50 ( V_141 ) ;
int V_92 = F_51 ( V_141 ) ;
while ( V_92 > 0 ) {
int V_145 = 1 ;
const struct V_146 * V_147 = V_144 ;
switch ( V_147 -> V_148 ) {
case V_149 :
break;
case V_150 :
V_145 = 0 ;
break;
case V_151 :
V_145 = V_143 -> V_152 >= V_147 [ 1 ] . V_153 ;
break;
case V_154 :
V_145 = V_143 -> V_152 <= V_147 [ 1 ] . V_153 ;
break;
case V_155 :
V_145 = V_143 -> V_156 >= V_147 [ 1 ] . V_153 ;
break;
case V_157 :
V_145 = V_143 -> V_156 <= V_147 [ 1 ] . V_153 ;
break;
case V_158 :
V_145 = ! ( V_143 -> V_159 & V_160 ) ;
break;
case V_161 :
case V_162 : {
struct V_163 * V_164 ;
T_5 * V_165 ;
V_164 = (struct V_163 * ) ( V_147 + 1 ) ;
if ( V_164 -> V_166 != - 1 &&
V_164 -> V_166 != ( V_147 -> V_148 == V_161 ?
V_143 -> V_152 : V_143 -> V_156 ) ) {
V_145 = 0 ;
break;
}
if ( V_164 -> V_167 == 0 )
break;
if ( V_147 -> V_148 == V_161 )
V_165 = V_143 -> V_168 ;
else
V_165 = V_143 -> V_64 ;
if ( F_47 ( V_165 , V_164 -> V_165 ,
V_164 -> V_167 ) )
break;
if ( V_143 -> V_169 == V_59 &&
V_164 -> V_169 == V_6 ) {
if ( V_165 [ 0 ] == 0 && V_165 [ 1 ] == 0 &&
V_165 [ 2 ] == F_48 ( 0xffff ) &&
F_47 ( V_165 + 3 , V_164 -> V_165 ,
V_164 -> V_167 ) )
break;
}
V_145 = 0 ;
break;
}
}
if ( V_145 ) {
V_92 -= V_147 -> V_145 ;
V_144 += V_147 -> V_145 ;
} else {
V_92 -= V_147 -> V_153 ;
V_144 += V_147 -> V_153 ;
}
}
return V_92 == 0 ;
}
int F_52 ( const struct V_140 * V_144 , struct V_10 * V_11 )
{
struct V_142 V_143 ;
struct V_23 * V_24 = F_8 ( V_11 ) ;
if ( V_144 == NULL )
return 1 ;
V_143 . V_169 = V_11 -> V_40 ;
#if F_16 ( V_58 )
if ( V_143 . V_169 == V_59 ) {
struct V_60 * V_61 = F_17 ( V_11 ) ;
V_143 . V_168 = V_61 -> V_63 . V_170 ;
V_143 . V_64 = V_61 -> V_64 . V_170 ;
} else
#endif
{
V_143 . V_168 = & V_24 -> V_53 ;
V_143 . V_64 = & V_24 -> V_55 ;
}
V_143 . V_152 = V_24 -> V_171 ;
V_143 . V_156 = F_53 ( V_24 -> V_51 ) ;
V_143 . V_159 = V_11 -> V_172 ;
return F_49 ( V_144 , & V_143 ) ;
}
static int F_54 ( const void * V_144 , int V_92 , int V_173 )
{
while ( V_92 >= 0 ) {
const struct V_146 * V_147 = V_144 ;
if ( V_173 > V_92 )
return 0 ;
if ( V_173 == V_92 )
return 1 ;
if ( V_147 -> V_145 < 4 || V_147 -> V_145 & 3 )
return 0 ;
V_92 -= V_147 -> V_145 ;
V_144 += V_147 -> V_145 ;
}
return 0 ;
}
static int F_55 ( const void * V_174 , int V_175 )
{
const void * V_144 = V_174 ;
int V_92 = V_175 ;
while ( V_92 > 0 ) {
const struct V_146 * V_147 = V_144 ;
switch ( V_147 -> V_148 ) {
case V_158 :
case V_161 :
case V_162 :
case V_151 :
case V_154 :
case V_155 :
case V_157 :
case V_150 :
if ( V_147 -> V_153 < 4 || V_147 -> V_153 > V_92 + 4 || V_147 -> V_153 & 3 )
return - V_123 ;
if ( V_147 -> V_153 < V_92 &&
! F_54 ( V_174 , V_175 , V_92 - V_147 -> V_153 ) )
return - V_123 ;
break;
case V_149 :
break;
default:
return - V_123 ;
}
if ( V_147 -> V_145 < 4 || V_147 -> V_145 > V_92 + 4 || V_147 -> V_145 & 3 )
return - V_123 ;
V_144 += V_147 -> V_145 ;
V_92 -= V_147 -> V_145 ;
}
return V_92 == 0 ? 0 : - V_123 ;
}
static int F_56 ( struct V_10 * V_11 ,
struct V_14 * V_15 ,
struct V_176 * V_177 ,
struct V_16 * V_26 ,
const struct V_140 * V_144 )
{
if ( ! F_52 ( V_144 , V_11 ) )
return 0 ;
return F_26 ( V_11 , V_15 , V_26 ,
F_38 ( V_177 -> V_15 ) . V_18 ,
V_177 -> V_27 -> V_129 , V_178 , V_177 -> V_27 ) ;
}
static int F_57 ( struct V_98 * V_99 ,
struct V_14 * V_15 ,
struct V_176 * V_177 ,
struct V_16 * V_26 ,
const struct V_140 * V_144 )
{
if ( V_144 != NULL ) {
struct V_142 V_143 ;
V_143 . V_169 = V_99 -> V_104 ;
#if F_16 ( V_58 )
if ( V_99 -> V_104 == V_59 ) {
struct V_114 * V_115 =
F_30 ( (struct V_10 * ) V_99 ) ;
V_143 . V_168 = V_115 -> V_116 . V_170 ;
V_143 . V_64 = V_115 -> V_117 . V_170 ;
} else
#endif
{
V_143 . V_168 = & V_99 -> V_108 ;
V_143 . V_64 = & V_99 -> V_109 ;
}
V_143 . V_152 = V_99 -> V_179 ;
V_143 . V_156 = F_53 ( V_99 -> V_107 ) ;
V_143 . V_159 = 0 ;
if ( ! F_49 ( V_144 , & V_143 ) )
return 0 ;
}
return F_28 ( V_99 , V_15 , V_26 ,
F_38 ( V_177 -> V_15 ) . V_18 ,
V_177 -> V_27 -> V_129 , V_178 , V_177 -> V_27 ) ;
}
static int F_58 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_180 * V_17 , T_1 V_18 , T_1 V_19 ,
const struct V_21 * V_22 )
{
const struct V_181 * V_182 = F_59 ( V_17 ) ;
struct V_23 * V_24 = F_8 ( V_11 ) ;
unsigned char * V_31 = F_9 ( V_15 ) ;
struct V_25 * V_26 ;
struct V_21 * V_27 ;
long T_3 ;
V_27 = F_11 ( V_15 , V_18 , V_19 , V_22 -> V_35 , sizeof( * V_26 ) ) ;
V_27 -> V_20 = V_178 ;
V_26 = F_12 ( V_27 ) ;
V_26 -> V_39 = V_11 -> V_40 ;
V_26 -> V_41 = V_183 ;
V_26 -> V_42 = 1 ;
V_26 -> V_43 = V_17 -> V_184 ;
V_26 -> V_44 . V_45 = V_11 -> V_46 ;
F_14 ( V_17 , V_26 -> V_44 . V_47 ) ;
T_3 = V_17 -> V_87 - V_103 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_26 -> V_44 . V_48 = V_24 -> V_49 ;
V_26 -> V_44 . V_50 = V_182 -> V_185 ;
V_26 -> V_44 . V_52 [ 0 ] = V_182 -> V_186 ;
V_26 -> V_44 . V_54 [ 0 ] = V_182 -> V_187 ;
V_26 -> V_82 = F_60 ( T_3 ) ;
V_26 -> V_112 = 0 ;
V_26 -> V_113 = 0 ;
V_26 -> V_67 = F_18 ( V_11 ) ;
V_26 -> V_68 = 0 ;
#if F_16 ( V_58 )
if ( V_26 -> V_39 == V_59 ) {
* (struct V_62 * ) V_26 -> V_44 . V_52 = F_61 ( V_17 ) -> V_186 ;
* (struct V_62 * ) V_26 -> V_44 . V_54 = F_61 ( V_17 ) -> V_187 ;
}
#endif
V_27 -> V_95 = F_9 ( V_15 ) - V_31 ;
return V_15 -> V_92 ;
V_96:
F_25 ( V_15 , V_31 ) ;
return - 1 ;
}
static int F_62 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_176 * V_177 ,
struct V_16 * V_26 ,
const struct V_140 * V_144 )
{
struct V_142 V_143 ;
struct V_12 * V_13 = F_27 ( V_11 ) ;
struct V_188 * V_189 ;
struct V_23 * V_24 = F_8 ( V_11 ) ;
int V_190 , V_191 ;
int V_192 , V_193 ;
int V_121 = 0 ;
V_191 = V_177 -> args [ 3 ] ;
V_193 = V_177 -> args [ 4 ] ;
if ( V_191 > 0 )
V_191 -- ;
V_143 . V_169 = V_11 -> V_40 ;
F_63 ( & V_13 -> V_194 . V_195 ) ;
V_189 = V_13 -> V_194 . V_196 ;
if ( ! V_189 || ! V_189 -> V_197 )
goto V_78;
if ( V_144 != NULL ) {
V_143 . V_152 = V_24 -> V_171 ;
V_143 . V_159 = V_11 -> V_172 ;
}
for ( V_190 = V_191 ; V_190 < V_189 -> V_198 ; V_190 ++ ) {
struct V_180 * V_17 , * V_199 = V_189 -> V_200 [ V_190 ] ;
V_192 = 0 ;
for ( V_17 = V_199 ; V_17 ; V_192 ++ , V_17 = V_17 -> V_201 ) {
struct V_181 * V_182 = F_59 ( V_17 ) ;
if ( V_192 < V_193 )
continue;
if ( V_26 -> V_44 . V_50 != V_182 -> V_185 &&
V_26 -> V_44 . V_50 )
continue;
if ( V_144 ) {
V_143 . V_168 =
#if F_16 ( V_58 )
( V_143 . V_169 == V_59 ) ?
F_61 ( V_17 ) -> V_186 . V_170 :
#endif
& V_182 -> V_186 ;
V_143 . V_64 =
#if F_16 ( V_58 )
( V_143 . V_169 == V_59 ) ?
F_61 ( V_17 ) -> V_187 . V_170 :
#endif
& V_182 -> V_187 ;
V_143 . V_156 = F_53 ( V_182 -> V_185 ) ;
if ( ! F_49 ( V_144 , & V_143 ) )
continue;
}
V_121 = F_58 ( V_15 , V_11 , V_17 ,
F_38 ( V_177 -> V_15 ) . V_18 ,
V_177 -> V_27 -> V_129 , V_177 -> V_27 ) ;
if ( V_121 < 0 ) {
V_177 -> args [ 3 ] = V_190 + 1 ;
V_177 -> args [ 4 ] = V_192 ;
goto V_78;
}
}
V_193 = 0 ;
}
V_78:
F_64 ( & V_13 -> V_194 . V_195 ) ;
return V_121 ;
}
void F_65 ( struct V_118 * V_119 , struct V_14 * V_15 ,
struct V_176 * V_177 , struct V_16 * V_26 , struct V_140 * V_144 )
{
int V_202 , V_203 ;
int V_204 , V_205 ;
V_204 = V_177 -> args [ 1 ] ;
V_205 = V_203 = V_177 -> args [ 2 ] ;
if ( V_177 -> args [ 0 ] == 0 ) {
if ( ! ( V_26 -> V_206 & ( V_207 | V_208 ) ) )
goto V_209;
for ( V_202 = V_204 ; V_202 < V_210 ; V_202 ++ ) {
struct V_10 * V_11 ;
struct V_211 * V_212 ;
struct V_213 * V_214 ;
V_203 = 0 ;
V_214 = & V_119 -> V_215 [ V_202 ] ;
F_66 ( & V_214 -> V_216 ) ;
F_67 (sk, node, &ilb->head) {
struct V_23 * V_24 = F_8 ( V_11 ) ;
if ( V_203 < V_205 ) {
V_203 ++ ;
continue;
}
if ( V_26 -> V_124 != V_217 &&
V_11 -> V_40 != V_26 -> V_124 )
goto V_218;
if ( V_26 -> V_44 . V_48 != V_24 -> V_49 &&
V_26 -> V_44 . V_48 )
goto V_218;
if ( ! ( V_26 -> V_206 & V_207 ) ||
V_26 -> V_44 . V_50 ||
V_177 -> args [ 3 ] > 0 )
goto V_219;
if ( F_56 ( V_11 , V_15 , V_177 , V_26 , V_144 ) < 0 ) {
F_68 ( & V_214 -> V_216 ) ;
goto V_220;
}
V_219:
if ( ! ( V_26 -> V_206 & V_208 ) )
goto V_218;
if ( F_62 ( V_15 , V_11 , V_177 , V_26 , V_144 ) < 0 ) {
F_68 ( & V_214 -> V_216 ) ;
goto V_220;
}
V_218:
V_177 -> args [ 3 ] = 0 ;
V_177 -> args [ 4 ] = 0 ;
++ V_203 ;
}
F_68 ( & V_214 -> V_216 ) ;
V_205 = 0 ;
V_177 -> args [ 3 ] = 0 ;
V_177 -> args [ 4 ] = 0 ;
}
V_209:
V_177 -> args [ 0 ] = 1 ;
V_204 = V_203 = V_205 = 0 ;
}
if ( ! ( V_26 -> V_206 & ~ ( V_207 | V_208 ) ) )
goto V_78;
for ( V_202 = V_204 ; V_202 <= V_119 -> V_221 ; V_202 ++ ) {
struct V_222 * V_199 = & V_119 -> V_223 [ V_202 ] ;
T_6 * V_216 = F_69 ( V_119 , V_202 ) ;
struct V_10 * V_11 ;
struct V_211 * V_212 ;
V_203 = 0 ;
if ( F_70 ( & V_199 -> V_224 ) &&
F_70 ( & V_199 -> V_225 ) )
continue;
if ( V_202 > V_204 )
V_205 = 0 ;
F_66 ( V_216 ) ;
F_67 (sk, node, &head->chain) {
struct V_23 * V_24 = F_8 ( V_11 ) ;
if ( V_203 < V_205 )
goto V_226;
if ( ! ( V_26 -> V_206 & ( 1 << V_11 -> V_36 ) ) )
goto V_226;
if ( V_26 -> V_124 != V_217 &&
V_11 -> V_40 != V_26 -> V_124 )
goto V_226;
if ( V_26 -> V_44 . V_48 != V_24 -> V_49 &&
V_26 -> V_44 . V_48 )
goto V_226;
if ( V_26 -> V_44 . V_50 != V_24 -> V_51 &&
V_26 -> V_44 . V_50 )
goto V_226;
if ( F_56 ( V_11 , V_15 , V_177 , V_26 , V_144 ) < 0 ) {
F_68 ( V_216 ) ;
goto V_220;
}
V_226:
++ V_203 ;
}
if ( V_26 -> V_206 & V_227 ) {
struct V_98 * V_99 ;
F_71 (tw, node,
&head->twchain) {
if ( V_203 < V_205 )
goto V_228;
if ( V_26 -> V_124 != V_217 &&
V_99 -> V_104 != V_26 -> V_124 )
goto V_228;
if ( V_26 -> V_44 . V_48 != V_99 -> V_106 &&
V_26 -> V_44 . V_48 )
goto V_228;
if ( V_26 -> V_44 . V_50 != V_99 -> V_107 &&
V_26 -> V_44 . V_50 )
goto V_228;
if ( F_57 ( V_99 , V_15 , V_177 , V_26 , V_144 ) < 0 ) {
F_68 ( V_216 ) ;
goto V_220;
}
V_228:
++ V_203 ;
}
}
F_68 ( V_216 ) ;
}
V_220:
V_177 -> args [ 1 ] = V_202 ;
V_177 -> args [ 2 ] = V_203 ;
V_78:
;
}
static int F_72 ( struct V_14 * V_15 , struct V_176 * V_177 ,
struct V_16 * V_26 , struct V_140 * V_144 )
{
const struct V_1 * V_9 ;
V_9 = F_1 ( V_26 -> V_34 ) ;
if ( ! F_45 ( V_9 ) )
V_9 -> V_229 ( V_15 , V_177 , V_26 , V_144 ) ;
F_5 ( V_9 ) ;
return V_15 -> V_92 ;
}
static int F_73 ( struct V_14 * V_15 , struct V_176 * V_177 )
{
struct V_140 * V_144 = NULL ;
int V_230 = sizeof( struct V_16 ) ;
if ( F_74 ( V_177 -> V_27 , V_230 ) )
V_144 = F_75 ( V_177 -> V_27 , V_230 , V_231 ) ;
return F_72 ( V_15 , V_177 , (struct V_16 * ) F_12 ( V_177 -> V_27 ) , V_144 ) ;
}
static inline int F_76 ( int type )
{
switch ( type ) {
case V_232 :
return V_233 ;
case V_234 :
return V_235 ;
default:
return 0 ;
}
}
static int F_77 ( struct V_14 * V_15 , struct V_176 * V_177 )
{
struct V_236 * V_237 = F_12 ( V_177 -> V_27 ) ;
struct V_16 V_17 ;
struct V_140 * V_144 = NULL ;
int V_230 = sizeof( struct V_236 ) ;
V_17 . V_124 = V_217 ;
V_17 . V_34 = F_76 ( V_177 -> V_27 -> V_35 ) ;
V_17 . V_33 = V_237 -> V_33 ;
V_17 . V_206 = V_237 -> V_206 ;
V_17 . V_44 = V_237 -> V_44 ;
if ( F_74 ( V_177 -> V_27 , V_230 ) )
V_144 = F_75 ( V_177 -> V_27 , V_230 , V_231 ) ;
return F_72 ( V_15 , V_177 , & V_17 , V_144 ) ;
}
static int F_78 ( struct V_14 * V_120 ,
const struct V_21 * V_27 )
{
struct V_236 * V_237 = F_12 ( V_27 ) ;
struct V_16 V_17 ;
V_17 . V_124 = V_237 -> V_39 ;
V_17 . V_34 = F_76 ( V_27 -> V_35 ) ;
V_17 . V_33 = V_237 -> V_33 ;
V_17 . V_206 = V_237 -> V_206 ;
V_17 . V_44 = V_237 -> V_44 ;
return F_44 ( V_120 , V_27 , & V_17 ) ;
}
static int F_79 ( struct V_14 * V_15 , struct V_21 * V_27 )
{
int V_230 = sizeof( struct V_236 ) ;
if ( V_27 -> V_35 >= V_238 ||
V_95 ( V_27 ) < V_230 )
return - V_123 ;
if ( V_27 -> V_20 & V_239 ) {
if ( F_74 ( V_27 , V_230 ) ) {
struct V_140 * V_240 ;
V_240 = F_75 ( V_27 , V_230 ,
V_231 ) ;
if ( V_240 == NULL ||
F_51 ( V_240 ) < sizeof( struct V_146 ) ||
F_55 ( F_50 ( V_240 ) , F_51 ( V_240 ) ) )
return - V_123 ;
}
{
struct V_241 V_242 = {
. V_229 = F_77 ,
} ;
return F_80 ( V_130 , V_15 , V_27 , & V_242 ) ;
}
}
return F_78 ( V_15 , V_27 ) ;
}
static int F_81 ( struct V_14 * V_15 , struct V_21 * V_243 )
{
int V_230 = sizeof( struct V_16 ) ;
if ( V_95 ( V_243 ) < V_230 )
return - V_123 ;
if ( V_243 -> V_20 & V_239 ) {
if ( F_74 ( V_243 , V_230 ) ) {
struct V_140 * V_240 ;
V_240 = F_75 ( V_243 , V_230 ,
V_231 ) ;
if ( V_240 == NULL ||
F_51 ( V_240 ) < sizeof( struct V_146 ) ||
F_55 ( F_50 ( V_240 ) , F_51 ( V_240 ) ) )
return - V_123 ;
}
{
struct V_241 V_242 = {
. V_229 = F_73 ,
} ;
return F_80 ( V_130 , V_15 , V_243 , & V_242 ) ;
}
}
return F_44 ( V_15 , V_243 , (struct V_16 * ) F_12 ( V_243 ) ) ;
}
int F_82 ( const struct V_1 * V_243 )
{
const T_7 type = V_243 -> V_244 ;
int V_121 = - V_123 ;
if ( type >= V_245 )
goto V_78;
F_3 ( & V_7 ) ;
V_121 = - V_246 ;
if ( V_3 [ type ] == NULL ) {
V_3 [ type ] = V_243 ;
V_121 = 0 ;
}
F_6 ( & V_7 ) ;
V_78:
return V_121 ;
}
void F_83 ( const struct V_1 * V_243 )
{
const T_7 type = V_243 -> V_244 ;
if ( type >= V_245 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_8 F_84 ( void )
{
const int V_247 = ( V_245 *
sizeof( struct V_1 * ) ) ;
int V_121 = - V_127 ;
V_3 = F_85 ( V_247 , V_128 ) ;
if ( ! V_3 )
goto V_78;
V_121 = F_86 ( & V_1 ) ;
if ( V_121 )
goto V_248;
V_121 = F_86 ( & V_249 ) ;
if ( V_121 )
goto V_250;
F_87 ( F_79 ) ;
V_78:
return V_121 ;
V_250:
F_88 ( & V_1 ) ;
V_248:
F_89 ( V_3 ) ;
goto V_78;
}
static void T_9 F_90 ( void )
{
F_88 ( & V_249 ) ;
F_88 ( & V_1 ) ;
F_91 ( F_79 ) ;
F_89 ( V_3 ) ;
}
