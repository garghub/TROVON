static const struct V_1 * F_1 ( int type )
{
if ( ! V_2 [ type ] )
F_2 ( L_1 , V_3 ,
V_4 , type ) ;
F_3 ( & V_5 ) ;
if ( ! V_2 [ type ] )
return F_4 ( - V_6 ) ;
return V_2 [ type ] ;
}
static inline void F_5 (
const struct V_1 * V_7 )
{
F_6 ( & V_5 ) ;
}
static int F_7 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
int V_12 , T_1 V_13 , T_1 V_14 , T_2 V_15 ,
const struct V_16 * V_17 )
{
const struct V_18 * V_19 = F_8 ( V_9 ) ;
const struct V_20 * V_21 = F_9 ( V_9 ) ;
struct V_22 * V_23 ;
struct V_16 * V_24 ;
void * V_25 = NULL ;
struct V_26 * V_27 = NULL ;
unsigned char * V_28 = F_10 ( V_11 ) ;
const struct V_1 * V_7 ;
V_7 = V_2 [ V_17 -> V_29 ] ;
F_11 ( V_7 == NULL ) ;
V_24 = F_12 ( V_11 , V_13 , V_14 , V_17 -> V_29 , sizeof( * V_23 ) ) ;
V_24 -> V_15 = V_15 ;
V_23 = F_13 ( V_24 ) ;
F_11 ( V_9 -> V_30 == V_31 ) ;
if ( V_12 & ( 1 << ( V_32 - 1 ) ) )
V_27 = F_14 ( V_11 , V_32 , sizeof( * V_27 ) ) ;
if ( V_12 & ( 1 << ( V_33 - 1 ) ) )
V_25 = F_14 ( V_11 , V_33 ,
V_7 -> V_34 ) ;
if ( ( V_12 & ( 1 << ( V_35 - 1 ) ) ) && V_21 -> V_36 ) {
const T_3 V_37 = strlen ( V_21 -> V_36 -> V_38 ) ;
strcpy ( F_14 ( V_11 , V_35 , V_37 + 1 ) ,
V_21 -> V_36 -> V_38 ) ;
}
V_23 -> V_39 = V_9 -> V_40 ;
V_23 -> V_41 = V_9 -> V_30 ;
V_23 -> V_42 = 0 ;
V_23 -> V_43 = 0 ;
V_23 -> V_44 . V_45 = V_9 -> V_46 ;
V_23 -> V_44 . V_47 [ 0 ] = ( T_1 ) ( unsigned long ) V_9 ;
V_23 -> V_44 . V_47 [ 1 ] = ( T_1 ) ( ( ( unsigned long ) V_9 >> 31 ) >> 1 ) ;
V_23 -> V_44 . V_48 = V_19 -> V_49 ;
V_23 -> V_44 . V_50 = V_19 -> V_51 ;
V_23 -> V_44 . V_52 [ 0 ] = V_19 -> V_53 ;
V_23 -> V_44 . V_54 [ 0 ] = V_19 -> V_55 ;
if ( V_12 & ( 1 << ( V_56 - 1 ) ) )
F_15 ( V_11 , V_56 , V_19 -> V_57 ) ;
#if F_16 ( V_58 ) || F_16 ( V_59 )
if ( V_23 -> V_39 == V_60 ) {
const struct V_61 * V_62 = F_17 ( V_9 ) ;
if ( V_12 & ( 1 << ( V_63 - 1 ) ) )
F_15 ( V_11 , V_63 , V_62 -> V_64 ) ;
F_18 ( (struct V_65 * ) V_23 -> V_44 . V_52 ,
& V_62 -> V_66 ) ;
F_18 ( (struct V_65 * ) V_23 -> V_44 . V_54 ,
& V_62 -> V_67 ) ;
}
#endif
#define F_19 ( T_4 ) DIV_ROUND_UP((tmo - jiffies) * 1000, HZ)
if ( V_21 -> V_68 == V_69 ) {
V_23 -> V_42 = 1 ;
V_23 -> V_43 = V_21 -> V_70 ;
V_23 -> V_71 = F_19 ( V_21 -> V_72 ) ;
} else if ( V_21 -> V_68 == V_73 ) {
V_23 -> V_42 = 4 ;
V_23 -> V_43 = V_21 -> V_74 ;
V_23 -> V_71 = F_19 ( V_21 -> V_72 ) ;
} else if ( F_20 ( & V_9 -> V_75 ) ) {
V_23 -> V_42 = 2 ;
V_23 -> V_43 = V_21 -> V_74 ;
V_23 -> V_71 = F_19 ( V_9 -> V_75 . V_76 ) ;
} else {
V_23 -> V_42 = 0 ;
V_23 -> V_71 = 0 ;
}
#undef F_19
V_23 -> V_77 = F_21 ( V_9 ) ;
V_23 -> V_78 = F_22 ( V_9 ) ;
if ( V_27 ) {
V_27 -> V_79 = F_23 ( V_9 ) ;
V_27 -> V_80 = V_9 -> V_81 ;
V_27 -> V_82 = V_9 -> V_83 ;
V_27 -> V_84 = F_24 ( V_9 ) ;
}
V_7 -> V_85 ( V_9 , V_23 , V_25 ) ;
if ( V_9 -> V_30 < V_31 &&
V_21 -> V_36 && V_21 -> V_36 -> V_86 )
V_21 -> V_36 -> V_86 ( V_9 , V_12 , V_11 ) ;
V_24 -> V_87 = F_10 ( V_11 ) - V_28 ;
return V_11 -> V_37 ;
V_88:
V_89:
F_25 ( V_11 , V_28 ) ;
return - V_90 ;
}
static int F_26 ( struct V_91 * V_92 ,
struct V_10 * V_11 , int V_12 , T_1 V_13 ,
T_1 V_14 , T_2 V_15 ,
const struct V_16 * V_17 )
{
long T_4 ;
struct V_22 * V_23 ;
const unsigned char * V_93 = F_10 ( V_11 ) ;
struct V_16 * V_24 = F_12 ( V_11 , V_13 , V_14 ,
V_17 -> V_29 , sizeof( * V_23 ) ) ;
V_23 = F_13 ( V_24 ) ;
F_11 ( V_92 -> V_94 != V_31 ) ;
V_24 -> V_15 = V_15 ;
T_4 = V_92 -> V_95 - V_96 ;
if ( T_4 < 0 )
T_4 = 0 ;
V_23 -> V_39 = V_92 -> V_97 ;
V_23 -> V_43 = 0 ;
V_23 -> V_44 . V_45 = V_92 -> V_98 ;
V_23 -> V_44 . V_47 [ 0 ] = ( T_1 ) ( unsigned long ) V_92 ;
V_23 -> V_44 . V_47 [ 1 ] = ( T_1 ) ( ( ( unsigned long ) V_92 >> 31 ) >> 1 ) ;
V_23 -> V_44 . V_48 = V_92 -> V_99 ;
V_23 -> V_44 . V_50 = V_92 -> V_100 ;
V_23 -> V_44 . V_52 [ 0 ] = V_92 -> V_101 ;
V_23 -> V_44 . V_54 [ 0 ] = V_92 -> V_102 ;
V_23 -> V_41 = V_92 -> V_103 ;
V_23 -> V_42 = 3 ;
V_23 -> V_71 = F_27 ( T_4 * 1000 , V_104 ) ;
V_23 -> V_105 = 0 ;
V_23 -> V_106 = 0 ;
V_23 -> V_77 = 0 ;
V_23 -> V_78 = 0 ;
#if F_16 ( V_58 ) || F_16 ( V_59 )
if ( V_92 -> V_97 == V_60 ) {
const struct V_107 * V_108 =
F_28 ( (struct V_8 * ) V_92 ) ;
F_18 ( (struct V_65 * ) V_23 -> V_44 . V_52 ,
& V_108 -> V_109 ) ;
F_18 ( (struct V_65 * ) V_23 -> V_44 . V_54 ,
& V_108 -> V_110 ) ;
}
#endif
V_24 -> V_87 = F_10 ( V_11 ) - V_93 ;
return V_11 -> V_37 ;
V_89:
F_25 ( V_11 , V_93 ) ;
return - V_90 ;
}
static int F_29 ( struct V_8 * V_9 , struct V_10 * V_11 ,
int V_12 , T_1 V_13 , T_1 V_14 , T_2 V_15 ,
const struct V_16 * V_17 )
{
if ( V_9 -> V_30 == V_31 )
return F_26 ( (struct V_91 * ) V_9 ,
V_11 , V_12 , V_13 , V_14 , V_15 ,
V_17 ) ;
return F_7 ( V_9 , V_11 , V_12 , V_13 , V_14 , V_15 , V_17 ) ;
}
static int F_30 ( struct V_10 * V_111 ,
const struct V_16 * V_24 )
{
int V_112 ;
struct V_8 * V_9 ;
struct V_113 * V_114 = F_13 ( V_24 ) ;
struct V_10 * V_115 ;
struct V_116 * V_117 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_24 -> V_29 ) ;
if ( F_31 ( V_7 ) ) {
V_112 = F_32 ( V_7 ) ;
goto V_118;
}
V_117 = V_7 -> V_119 ;
V_112 = - V_120 ;
if ( V_114 -> V_39 == V_121 ) {
V_9 = F_33 ( & V_122 , V_117 , V_114 -> V_44 . V_54 [ 0 ] ,
V_114 -> V_44 . V_50 , V_114 -> V_44 . V_52 [ 0 ] ,
V_114 -> V_44 . V_48 , V_114 -> V_44 . V_45 ) ;
}
#if F_16 ( V_58 ) || F_16 ( V_59 )
else if ( V_114 -> V_39 == V_60 ) {
V_9 = F_34 ( & V_122 , V_117 ,
(struct V_65 * ) V_114 -> V_44 . V_54 ,
V_114 -> V_44 . V_50 ,
(struct V_65 * ) V_114 -> V_44 . V_52 ,
V_114 -> V_44 . V_48 ,
V_114 -> V_44 . V_45 ) ;
}
#endif
else {
goto V_118;
}
V_112 = - V_6 ;
if ( V_9 == NULL )
goto V_118;
V_112 = - V_123 ;
if ( ( V_114 -> V_44 . V_47 [ 0 ] != V_124 ||
V_114 -> V_44 . V_47 [ 1 ] != V_124 ) &&
( ( T_1 ) ( unsigned long ) V_9 != V_114 -> V_44 . V_47 [ 0 ] ||
( T_1 ) ( ( ( ( unsigned long ) V_9 ) >> 31 ) >> 1 ) != V_114 -> V_44 . V_47 [ 1 ] ) )
goto V_125;
V_112 = - V_126 ;
V_115 = F_35 ( F_36 ( ( sizeof( struct V_22 ) +
sizeof( struct V_26 ) +
V_7 -> V_34 + 64 ) ) ,
V_127 ) ;
if ( ! V_115 )
goto V_125;
V_112 = F_29 ( V_9 , V_115 , V_114 -> V_128 ,
F_37 ( V_111 ) . V_13 ,
V_24 -> V_129 , 0 , V_24 ) ;
if ( V_112 < 0 ) {
F_38 ( V_112 == - V_90 ) ;
F_39 ( V_115 ) ;
goto V_125;
}
V_112 = F_40 ( V_130 , V_115 , F_37 ( V_111 ) . V_13 ,
V_131 ) ;
if ( V_112 > 0 )
V_112 = 0 ;
V_125:
if ( V_9 ) {
if ( V_9 -> V_30 == V_31 )
F_41 ( (struct V_91 * ) V_9 ) ;
else
F_42 ( V_9 ) ;
}
V_118:
F_5 ( V_7 ) ;
return V_112 ;
}
static int F_43 ( const T_5 * V_132 , const T_5 * V_133 , int V_134 )
{
int V_135 = V_134 >> 5 ;
V_134 &= 0x1f ;
if ( V_135 ) {
if ( memcmp ( V_132 , V_133 , V_135 << 2 ) )
return 0 ;
}
if ( V_134 ) {
T_5 V_136 , V_137 ;
T_5 V_138 ;
V_136 = V_132 [ V_135 ] ;
V_137 = V_133 [ V_135 ] ;
V_138 = F_44 ( ( 0xffffffff ) << ( 32 - V_134 ) ) ;
if ( ( V_136 ^ V_137 ) & V_138 )
return 0 ;
}
return 1 ;
}
static int F_45 ( const void * V_139 , int V_37 ,
const struct V_140 * V_141 )
{
while ( V_37 > 0 ) {
int V_142 = 1 ;
const struct V_143 * V_144 = V_139 ;
switch ( V_144 -> V_145 ) {
case V_146 :
break;
case V_147 :
V_142 = 0 ;
break;
case V_148 :
V_142 = V_141 -> V_149 >= V_144 [ 1 ] . V_150 ;
break;
case V_151 :
V_142 = V_141 -> V_149 <= V_144 [ 1 ] . V_150 ;
break;
case V_152 :
V_142 = V_141 -> V_153 >= V_144 [ 1 ] . V_150 ;
break;
case V_154 :
V_142 = V_141 -> V_153 <= V_144 [ 1 ] . V_150 ;
break;
case V_155 :
V_142 = ! ( V_141 -> V_156 & V_157 ) ;
break;
case V_158 :
case V_159 : {
struct V_160 * V_161 ;
T_5 * V_162 ;
V_161 = (struct V_160 * ) ( V_144 + 1 ) ;
if ( V_161 -> V_163 != - 1 &&
V_161 -> V_163 != ( V_144 -> V_145 == V_158 ?
V_141 -> V_149 : V_141 -> V_153 ) ) {
V_142 = 0 ;
break;
}
if ( V_161 -> V_164 == 0 )
break;
if ( V_144 -> V_145 == V_158 )
V_162 = V_141 -> V_165 ;
else
V_162 = V_141 -> V_67 ;
if ( F_43 ( V_162 , V_161 -> V_162 ,
V_161 -> V_164 ) )
break;
if ( V_141 -> V_166 == V_60 &&
V_161 -> V_166 == V_121 ) {
if ( V_162 [ 0 ] == 0 && V_162 [ 1 ] == 0 &&
V_162 [ 2 ] == F_44 ( 0xffff ) &&
F_43 ( V_162 + 3 , V_161 -> V_162 ,
V_161 -> V_164 ) )
break;
}
V_142 = 0 ;
break;
}
}
if ( V_142 ) {
V_37 -= V_144 -> V_142 ;
V_139 += V_144 -> V_142 ;
} else {
V_37 -= V_144 -> V_150 ;
V_139 += V_144 -> V_150 ;
}
}
return V_37 == 0 ;
}
static int F_46 ( const void * V_139 , int V_37 , int V_167 )
{
while ( V_37 >= 0 ) {
const struct V_143 * V_144 = V_139 ;
if ( V_167 > V_37 )
return 0 ;
if ( V_167 == V_37 )
return 1 ;
if ( V_144 -> V_142 < 4 || V_144 -> V_142 & 3 )
return 0 ;
V_37 -= V_144 -> V_142 ;
V_139 += V_144 -> V_142 ;
}
return 0 ;
}
static int F_47 ( const void * V_168 , int V_169 )
{
const void * V_139 = V_168 ;
int V_37 = V_169 ;
while ( V_37 > 0 ) {
const struct V_143 * V_144 = V_139 ;
switch ( V_144 -> V_145 ) {
case V_155 :
case V_158 :
case V_159 :
case V_148 :
case V_151 :
case V_152 :
case V_154 :
case V_147 :
if ( V_144 -> V_150 < 4 || V_144 -> V_150 > V_37 + 4 || V_144 -> V_150 & 3 )
return - V_120 ;
if ( V_144 -> V_150 < V_37 &&
! F_46 ( V_168 , V_169 , V_37 - V_144 -> V_150 ) )
return - V_120 ;
break;
case V_146 :
break;
default:
return - V_120 ;
}
if ( V_144 -> V_142 < 4 || V_144 -> V_142 > V_37 + 4 || V_144 -> V_142 & 3 )
return - V_120 ;
V_139 += V_144 -> V_142 ;
V_37 -= V_144 -> V_142 ;
}
return V_37 == 0 ? 0 : - V_120 ;
}
static int F_48 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_170 * V_171 )
{
struct V_113 * V_23 = F_13 ( V_171 -> V_24 ) ;
if ( F_49 ( V_171 -> V_24 , sizeof( * V_23 ) ) ) {
struct V_140 V_141 ;
const struct V_172 * V_139 = F_50 ( V_171 -> V_24 ,
sizeof( * V_23 ) ,
V_173 ) ;
struct V_18 * V_19 = F_8 ( V_9 ) ;
V_141 . V_166 = V_9 -> V_40 ;
#if F_16 ( V_58 ) || F_16 ( V_59 )
if ( V_141 . V_166 == V_60 ) {
struct V_61 * V_62 = F_17 ( V_9 ) ;
V_141 . V_165 = V_62 -> V_66 . V_174 ;
V_141 . V_67 = V_62 -> V_67 . V_174 ;
} else
#endif
{
V_141 . V_165 = & V_19 -> V_53 ;
V_141 . V_67 = & V_19 -> V_55 ;
}
V_141 . V_149 = V_19 -> V_175 ;
V_141 . V_153 = F_51 ( V_19 -> V_51 ) ;
V_141 . V_156 = V_9 -> V_176 ;
if ( ! F_45 ( F_52 ( V_139 ) , F_53 ( V_139 ) , & V_141 ) )
return 0 ;
}
return F_7 ( V_9 , V_11 , V_23 -> V_128 ,
F_37 ( V_171 -> V_11 ) . V_13 ,
V_171 -> V_24 -> V_129 , V_177 , V_171 -> V_24 ) ;
}
static int F_54 ( struct V_91 * V_92 ,
struct V_10 * V_11 ,
struct V_170 * V_171 )
{
struct V_113 * V_23 = F_13 ( V_171 -> V_24 ) ;
if ( F_49 ( V_171 -> V_24 , sizeof( * V_23 ) ) ) {
struct V_140 V_141 ;
const struct V_172 * V_139 = F_50 ( V_171 -> V_24 ,
sizeof( * V_23 ) ,
V_173 ) ;
V_141 . V_166 = V_92 -> V_97 ;
#if F_16 ( V_58 ) || F_16 ( V_59 )
if ( V_92 -> V_97 == V_60 ) {
struct V_107 * V_108 =
F_28 ( (struct V_8 * ) V_92 ) ;
V_141 . V_165 = V_108 -> V_109 . V_174 ;
V_141 . V_67 = V_108 -> V_110 . V_174 ;
} else
#endif
{
V_141 . V_165 = & V_92 -> V_101 ;
V_141 . V_67 = & V_92 -> V_102 ;
}
V_141 . V_149 = V_92 -> V_178 ;
V_141 . V_153 = F_51 ( V_92 -> V_100 ) ;
V_141 . V_156 = 0 ;
if ( ! F_45 ( F_52 ( V_139 ) , F_53 ( V_139 ) , & V_141 ) )
return 0 ;
}
return F_26 ( V_92 , V_11 , V_23 -> V_128 ,
F_37 ( V_171 -> V_11 ) . V_13 ,
V_171 -> V_24 -> V_129 , V_177 , V_171 -> V_24 ) ;
}
static int F_55 ( struct V_10 * V_11 , struct V_8 * V_9 ,
struct V_179 * V_114 , T_1 V_13 , T_1 V_14 ,
const struct V_16 * V_17 )
{
const struct V_180 * V_181 = F_56 ( V_114 ) ;
struct V_18 * V_19 = F_8 ( V_9 ) ;
unsigned char * V_28 = F_10 ( V_11 ) ;
struct V_22 * V_23 ;
struct V_16 * V_24 ;
long T_4 ;
V_24 = F_12 ( V_11 , V_13 , V_14 , V_17 -> V_29 , sizeof( * V_23 ) ) ;
V_24 -> V_15 = V_177 ;
V_23 = F_13 ( V_24 ) ;
V_23 -> V_39 = V_9 -> V_40 ;
V_23 -> V_41 = V_182 ;
V_23 -> V_42 = 1 ;
V_23 -> V_43 = V_114 -> V_183 ;
V_23 -> V_44 . V_45 = V_9 -> V_46 ;
V_23 -> V_44 . V_47 [ 0 ] = ( T_1 ) ( unsigned long ) V_114 ;
V_23 -> V_44 . V_47 [ 1 ] = ( T_1 ) ( ( ( unsigned long ) V_114 >> 31 ) >> 1 ) ;
T_4 = V_114 -> V_76 - V_96 ;
if ( T_4 < 0 )
T_4 = 0 ;
V_23 -> V_44 . V_48 = V_19 -> V_49 ;
V_23 -> V_44 . V_50 = V_181 -> V_184 ;
V_23 -> V_44 . V_52 [ 0 ] = V_181 -> V_185 ;
V_23 -> V_44 . V_54 [ 0 ] = V_181 -> V_186 ;
V_23 -> V_71 = F_57 ( T_4 ) ;
V_23 -> V_105 = 0 ;
V_23 -> V_106 = 0 ;
V_23 -> V_77 = F_21 ( V_9 ) ;
V_23 -> V_78 = 0 ;
#if F_16 ( V_58 ) || F_16 ( V_59 )
if ( V_23 -> V_39 == V_60 ) {
F_18 ( (struct V_65 * ) V_23 -> V_44 . V_52 ,
& F_58 ( V_114 ) -> V_185 ) ;
F_18 ( (struct V_65 * ) V_23 -> V_44 . V_54 ,
& F_58 ( V_114 ) -> V_186 ) ;
}
#endif
V_24 -> V_87 = F_10 ( V_11 ) - V_28 ;
return V_11 -> V_37 ;
V_89:
F_25 ( V_11 , V_28 ) ;
return - 1 ;
}
static int F_59 ( struct V_10 * V_11 , struct V_8 * V_9 ,
struct V_170 * V_171 )
{
struct V_140 V_141 ;
struct V_113 * V_23 = F_13 ( V_171 -> V_24 ) ;
struct V_20 * V_21 = F_9 ( V_9 ) ;
struct V_187 * V_188 ;
const struct V_172 * V_139 = NULL ;
struct V_18 * V_19 = F_8 ( V_9 ) ;
int V_189 , V_190 ;
int V_191 , V_192 ;
int V_112 = 0 ;
V_190 = V_171 -> args [ 3 ] ;
V_192 = V_171 -> args [ 4 ] ;
if ( V_190 > 0 )
V_190 -- ;
V_141 . V_166 = V_9 -> V_40 ;
F_60 ( & V_21 -> V_193 . V_194 ) ;
V_188 = V_21 -> V_193 . V_195 ;
if ( ! V_188 || ! V_188 -> V_196 )
goto V_125;
if ( F_49 ( V_171 -> V_24 , sizeof( * V_23 ) ) ) {
V_139 = F_50 ( V_171 -> V_24 , sizeof( * V_23 ) ,
V_173 ) ;
V_141 . V_149 = V_19 -> V_175 ;
V_141 . V_156 = V_9 -> V_176 ;
}
for ( V_189 = V_190 ; V_189 < V_188 -> V_197 ; V_189 ++ ) {
struct V_179 * V_114 , * V_198 = V_188 -> V_199 [ V_189 ] ;
V_191 = 0 ;
for ( V_114 = V_198 ; V_114 ; V_191 ++ , V_114 = V_114 -> V_200 ) {
struct V_180 * V_181 = F_56 ( V_114 ) ;
if ( V_191 < V_192 )
continue;
if ( V_23 -> V_44 . V_50 != V_181 -> V_184 &&
V_23 -> V_44 . V_50 )
continue;
if ( V_139 ) {
V_141 . V_165 =
#if F_16 ( V_58 ) || F_16 ( V_59 )
( V_141 . V_166 == V_60 ) ?
F_58 ( V_114 ) -> V_185 . V_174 :
#endif
& V_181 -> V_185 ;
V_141 . V_67 =
#if F_16 ( V_58 ) || F_16 ( V_59 )
( V_141 . V_166 == V_60 ) ?
F_58 ( V_114 ) -> V_186 . V_174 :
#endif
& V_181 -> V_186 ;
V_141 . V_153 = F_51 ( V_181 -> V_184 ) ;
if ( ! F_45 ( F_52 ( V_139 ) ,
F_53 ( V_139 ) , & V_141 ) )
continue;
}
V_112 = F_55 ( V_11 , V_9 , V_114 ,
F_37 ( V_171 -> V_11 ) . V_13 ,
V_171 -> V_24 -> V_129 , V_171 -> V_24 ) ;
if ( V_112 < 0 ) {
V_171 -> args [ 3 ] = V_189 + 1 ;
V_171 -> args [ 4 ] = V_191 ;
goto V_125;
}
}
V_192 = 0 ;
}
V_125:
F_61 ( & V_21 -> V_193 . V_194 ) ;
return V_112 ;
}
static int F_62 ( struct V_10 * V_11 , struct V_170 * V_171 )
{
int V_201 , V_202 ;
int V_203 , V_204 ;
struct V_113 * V_23 = F_13 ( V_171 -> V_24 ) ;
const struct V_1 * V_7 ;
struct V_116 * V_117 ;
V_7 = F_1 ( V_171 -> V_24 -> V_29 ) ;
if ( F_31 ( V_7 ) )
goto V_118;
V_117 = V_7 -> V_119 ;
V_203 = V_171 -> args [ 1 ] ;
V_204 = V_202 = V_171 -> args [ 2 ] ;
if ( V_171 -> args [ 0 ] == 0 ) {
if ( ! ( V_23 -> V_205 & ( V_206 | V_207 ) ) )
goto V_208;
for ( V_201 = V_203 ; V_201 < V_209 ; V_201 ++ ) {
struct V_8 * V_9 ;
struct V_210 * V_211 ;
struct V_212 * V_213 ;
V_202 = 0 ;
V_213 = & V_117 -> V_214 [ V_201 ] ;
F_63 ( & V_213 -> V_215 ) ;
F_64 (sk, node, &ilb->head) {
struct V_18 * V_19 = F_8 ( V_9 ) ;
if ( V_202 < V_204 ) {
V_202 ++ ;
continue;
}
if ( V_23 -> V_44 . V_48 != V_19 -> V_49 &&
V_23 -> V_44 . V_48 )
goto V_216;
if ( ! ( V_23 -> V_205 & V_206 ) ||
V_23 -> V_44 . V_50 ||
V_171 -> args [ 3 ] > 0 )
goto V_217;
if ( F_48 ( V_9 , V_11 , V_171 ) < 0 ) {
F_65 ( & V_213 -> V_215 ) ;
goto V_218;
}
V_217:
if ( ! ( V_23 -> V_205 & V_207 ) )
goto V_216;
if ( F_59 ( V_11 , V_9 , V_171 ) < 0 ) {
F_65 ( & V_213 -> V_215 ) ;
goto V_218;
}
V_216:
V_171 -> args [ 3 ] = 0 ;
V_171 -> args [ 4 ] = 0 ;
++ V_202 ;
}
F_65 ( & V_213 -> V_215 ) ;
V_204 = 0 ;
V_171 -> args [ 3 ] = 0 ;
V_171 -> args [ 4 ] = 0 ;
}
V_208:
V_171 -> args [ 0 ] = 1 ;
V_203 = V_202 = V_204 = 0 ;
}
if ( ! ( V_23 -> V_205 & ~ ( V_206 | V_207 ) ) )
goto V_118;
for ( V_201 = V_203 ; V_201 <= V_117 -> V_219 ; V_201 ++ ) {
struct V_220 * V_198 = & V_117 -> V_221 [ V_201 ] ;
T_6 * V_215 = F_66 ( V_117 , V_201 ) ;
struct V_8 * V_9 ;
struct V_210 * V_211 ;
V_202 = 0 ;
if ( F_67 ( & V_198 -> V_222 ) &&
F_67 ( & V_198 -> V_223 ) )
continue;
if ( V_201 > V_203 )
V_204 = 0 ;
F_63 ( V_215 ) ;
F_64 (sk, node, &head->chain) {
struct V_18 * V_19 = F_8 ( V_9 ) ;
if ( V_202 < V_204 )
goto V_224;
if ( ! ( V_23 -> V_205 & ( 1 << V_9 -> V_30 ) ) )
goto V_224;
if ( V_23 -> V_44 . V_48 != V_19 -> V_49 &&
V_23 -> V_44 . V_48 )
goto V_224;
if ( V_23 -> V_44 . V_50 != V_19 -> V_51 &&
V_23 -> V_44 . V_50 )
goto V_224;
if ( F_48 ( V_9 , V_11 , V_171 ) < 0 ) {
F_65 ( V_215 ) ;
goto V_218;
}
V_224:
++ V_202 ;
}
if ( V_23 -> V_205 & V_225 ) {
struct V_91 * V_92 ;
F_68 (tw, node,
&head->twchain) {
if ( V_202 < V_204 )
goto V_226;
if ( V_23 -> V_44 . V_48 != V_92 -> V_99 &&
V_23 -> V_44 . V_48 )
goto V_226;
if ( V_23 -> V_44 . V_50 != V_92 -> V_100 &&
V_23 -> V_44 . V_50 )
goto V_226;
if ( F_54 ( V_92 , V_11 , V_171 ) < 0 ) {
F_65 ( V_215 ) ;
goto V_218;
}
V_226:
++ V_202 ;
}
}
F_65 ( V_215 ) ;
}
V_218:
V_171 -> args [ 1 ] = V_201 ;
V_171 -> args [ 2 ] = V_202 ;
V_118:
F_5 ( V_7 ) ;
return V_11 -> V_37 ;
}
static int F_69 ( struct V_10 * V_11 , struct V_16 * V_24 )
{
int V_227 = sizeof( struct V_113 ) ;
if ( V_24 -> V_29 >= V_228 ||
V_87 ( V_24 ) < V_227 )
return - V_120 ;
if ( V_24 -> V_15 & V_229 ) {
if ( F_49 ( V_24 , V_227 ) ) {
struct V_172 * V_230 ;
V_230 = F_50 ( V_24 , V_227 ,
V_173 ) ;
if ( V_230 == NULL ||
F_53 ( V_230 ) < sizeof( struct V_143 ) ||
F_47 ( F_52 ( V_230 ) , F_53 ( V_230 ) ) )
return - V_120 ;
}
return F_70 ( V_130 , V_11 , V_24 ,
F_62 , NULL , 0 ) ;
}
return F_30 ( V_11 , V_24 ) ;
}
static void F_71 ( struct V_10 * V_11 )
{
F_3 ( & V_231 ) ;
F_72 ( V_11 , & F_69 ) ;
F_6 ( & V_231 ) ;
}
int F_73 ( const struct V_1 * V_232 )
{
const T_7 type = V_232 -> V_233 ;
int V_112 = - V_120 ;
if ( type >= V_228 )
goto V_125;
F_3 ( & V_5 ) ;
V_112 = - V_234 ;
if ( V_2 [ type ] == NULL ) {
V_2 [ type ] = V_232 ;
V_112 = 0 ;
}
F_6 ( & V_5 ) ;
V_125:
return V_112 ;
}
void F_74 ( const struct V_1 * V_232 )
{
const T_7 type = V_232 -> V_233 ;
if ( type >= V_228 )
return;
F_3 ( & V_5 ) ;
V_2 [ type ] = NULL ;
F_6 ( & V_5 ) ;
}
static int T_8 F_75 ( void )
{
const int V_235 = ( V_228 *
sizeof( struct V_1 * ) ) ;
int V_112 = - V_126 ;
V_2 = F_76 ( V_235 , V_127 ) ;
if ( ! V_2 )
goto V_125;
V_130 = F_77 ( & V_122 , V_4 , 0 ,
F_71 , NULL , V_236 ) ;
if ( V_130 == NULL )
goto V_237;
V_112 = 0 ;
V_125:
return V_112 ;
V_237:
F_78 ( V_2 ) ;
goto V_125;
}
static void T_9 F_79 ( void )
{
F_80 ( V_130 ) ;
F_78 ( V_2 ) ;
}
