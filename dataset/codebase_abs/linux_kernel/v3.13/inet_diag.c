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
memset ( & V_28 -> V_45 . V_53 , 0 , sizeof( V_28 -> V_45 . V_53 ) ) ;
memset ( & V_28 -> V_45 . V_54 , 0 , sizeof( V_28 -> V_45 . V_54 ) ) ;
V_28 -> V_45 . V_53 [ 0 ] = V_26 -> V_55 ;
V_28 -> V_45 . V_54 [ 0 ] = V_26 -> V_56 ;
if ( F_13 ( V_15 , V_57 , V_11 -> V_58 ) )
goto V_59;
if ( V_33 & ( 1 << ( V_60 - 1 ) ) )
if ( F_13 ( V_15 , V_60 , V_26 -> V_61 ) < 0 )
goto V_59;
#if F_14 ( V_62 )
if ( V_28 -> V_40 == V_63 ) {
* (struct V_64 * ) V_28 -> V_45 . V_53 = V_11 -> V_65 ;
* (struct V_64 * ) V_28 -> V_45 . V_54 = V_11 -> V_66 ;
if ( V_33 & ( 1 << ( V_67 - 1 ) ) )
if ( F_13 ( V_15 , V_67 ,
F_15 ( V_11 ) -> V_68 ) < 0 )
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
if ( V_13 -> V_83 == V_84 ||
V_13 -> V_83 == V_85 ||
V_13 -> V_83 == V_86 ) {
V_28 -> V_43 = 1 ;
V_28 -> V_44 = V_13 -> V_87 ;
V_28 -> V_88 = F_23 ( V_13 -> V_89 ) ;
} else if ( V_13 -> V_83 == V_90 ) {
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
V_9 -> V_81 ( V_11 , V_28 , V_32 ) ;
if ( V_11 -> V_38 < V_39 &&
V_13 -> V_97 && V_13 -> V_97 -> V_99 )
V_13 -> V_97 -> V_99 ( V_11 , V_33 , V_15 ) ;
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
static int F_32 ( struct V_100 * V_101 ,
struct V_14 * V_15 , struct V_16 * V_17 ,
T_1 V_20 , T_1 V_21 , T_2 V_22 ,
const struct V_23 * V_24 )
{
T_4 T_3 ;
struct V_27 * V_28 ;
struct V_23 * V_29 ;
V_29 = F_10 ( V_15 , V_20 , V_21 , V_24 -> V_36 , sizeof( * V_28 ) ,
V_22 ) ;
if ( ! V_29 )
return - V_37 ;
V_28 = F_11 ( V_29 ) ;
F_9 ( V_101 -> V_102 != V_39 ) ;
T_3 = V_101 -> V_103 - F_33 () ;
if ( T_3 < 0 )
T_3 = 0 ;
V_28 -> V_40 = V_101 -> V_104 ;
V_28 -> V_44 = 0 ;
V_28 -> V_45 . V_46 = V_101 -> V_105 ;
F_12 ( V_101 , V_28 -> V_45 . V_48 ) ;
V_28 -> V_45 . V_49 = V_101 -> V_106 ;
V_28 -> V_45 . V_51 = V_101 -> V_107 ;
memset ( & V_28 -> V_45 . V_53 , 0 , sizeof( V_28 -> V_45 . V_53 ) ) ;
memset ( & V_28 -> V_45 . V_54 , 0 , sizeof( V_28 -> V_45 . V_54 ) ) ;
V_28 -> V_45 . V_53 [ 0 ] = V_101 -> V_108 ;
V_28 -> V_45 . V_54 [ 0 ] = V_101 -> V_109 ;
V_28 -> V_42 = V_101 -> V_110 ;
V_28 -> V_43 = 3 ;
V_28 -> V_88 = F_34 ( T_3 ) ;
V_28 -> V_111 = 0 ;
V_28 -> V_112 = 0 ;
V_28 -> V_69 = 0 ;
V_28 -> V_70 = 0 ;
#if F_14 ( V_62 )
if ( V_101 -> V_104 == V_63 ) {
* (struct V_64 * ) V_28 -> V_45 . V_53 = V_101 -> V_113 ;
* (struct V_64 * ) V_28 -> V_45 . V_54 = V_101 -> V_114 ;
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
return F_32 ( F_36 ( V_11 ) , V_15 , V_28 , V_20 , V_21 ,
V_22 , V_24 ) ;
return F_30 ( V_11 , V_15 , V_28 , V_19 , V_20 , V_21 ,
V_22 , V_24 ) ;
}
int F_37 ( struct V_115 * V_116 , struct V_14 * V_117 ,
const struct V_23 * V_29 , struct V_16 * V_17 )
{
int V_118 ;
struct V_10 * V_11 ;
struct V_14 * V_119 ;
struct V_120 * V_120 = F_38 ( V_117 -> V_11 ) ;
V_118 = - V_121 ;
if ( V_17 -> V_122 == V_6 ) {
V_11 = F_39 ( V_120 , V_116 , V_17 -> V_45 . V_54 [ 0 ] ,
V_17 -> V_45 . V_51 , V_17 -> V_45 . V_53 [ 0 ] ,
V_17 -> V_45 . V_49 , V_17 -> V_45 . V_46 ) ;
}
#if F_14 ( V_62 )
else if ( V_17 -> V_122 == V_63 ) {
V_11 = F_40 ( V_120 , V_116 ,
(struct V_64 * ) V_17 -> V_45 . V_54 ,
V_17 -> V_45 . V_51 ,
(struct V_64 * ) V_17 -> V_45 . V_53 ,
V_17 -> V_45 . V_49 ,
V_17 -> V_45 . V_46 ) ;
}
#endif
else {
goto V_123;
}
V_118 = - V_8 ;
if ( V_11 == NULL )
goto V_123;
V_118 = F_41 ( V_11 , V_17 -> V_45 . V_48 ) ;
if ( V_118 )
goto V_82;
V_119 = F_42 ( sizeof( struct V_27 ) +
sizeof( struct V_72 ) +
sizeof( struct V_95 ) + 64 , V_124 ) ;
if ( ! V_119 ) {
V_118 = - V_125 ;
goto V_82;
}
V_118 = F_35 ( V_11 , V_119 , V_17 ,
F_43 ( F_44 ( V_117 ) . V_11 ) ,
F_44 ( V_117 ) . V_20 ,
V_29 -> V_126 , 0 , V_29 ) ;
if ( V_118 < 0 ) {
F_45 ( V_118 == - V_37 ) ;
F_46 ( V_119 ) ;
goto V_82;
}
V_118 = F_47 ( V_120 -> V_127 , V_119 , F_44 ( V_117 ) . V_20 ,
V_128 ) ;
if ( V_118 > 0 )
V_118 = 0 ;
V_82:
if ( V_11 )
F_48 ( V_11 ) ;
V_123:
return V_118 ;
}
static int F_49 ( struct V_14 * V_117 ,
const struct V_23 * V_29 ,
struct V_16 * V_17 )
{
const struct V_1 * V_9 ;
int V_118 ;
V_9 = F_1 ( V_17 -> V_35 ) ;
if ( F_50 ( V_9 ) )
V_118 = F_51 ( V_9 ) ;
else
V_118 = V_9 -> V_129 ( V_117 , V_29 , V_17 ) ;
F_5 ( V_9 ) ;
return V_118 ;
}
static int F_52 ( const T_5 * V_130 , const T_5 * V_131 , int V_132 )
{
int V_133 = V_132 >> 5 ;
V_132 &= 0x1f ;
if ( V_133 ) {
if ( memcmp ( V_130 , V_131 , V_133 << 2 ) )
return 0 ;
}
if ( V_132 ) {
T_5 V_134 , V_135 ;
T_5 V_136 ;
V_134 = V_130 [ V_133 ] ;
V_135 = V_131 [ V_133 ] ;
V_136 = F_53 ( ( 0xffffffff ) << ( 32 - V_132 ) ) ;
if ( ( V_134 ^ V_135 ) & V_136 )
return 0 ;
}
return 1 ;
}
static int F_54 ( const struct V_30 * V_137 ,
const struct V_138 * V_139 )
{
const void * V_140 = F_26 ( V_137 ) ;
int V_141 = F_55 ( V_137 ) ;
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
T_5 * V_162 ;
V_161 = (struct V_160 * ) ( V_144 + 1 ) ;
if ( V_161 -> V_163 != - 1 &&
V_161 -> V_163 != ( V_144 -> V_145 == V_158 ?
V_139 -> V_149 : V_139 -> V_153 ) ) {
V_142 = 0 ;
break;
}
if ( V_144 -> V_145 == V_158 )
V_162 = V_139 -> V_164 ;
else
V_162 = V_139 -> V_165 ;
if ( V_161 -> V_166 != V_167 &&
V_161 -> V_166 != V_139 -> V_166 ) {
if ( V_139 -> V_166 == V_63 &&
V_161 -> V_166 == V_6 ) {
if ( V_162 [ 0 ] == 0 && V_162 [ 1 ] == 0 &&
V_162 [ 2 ] == F_53 ( 0xffff ) &&
F_52 ( V_162 + 3 ,
V_161 -> V_162 ,
V_161 -> V_168 ) )
break;
}
V_142 = 0 ;
break;
}
if ( V_161 -> V_168 == 0 )
break;
if ( F_52 ( V_162 , V_161 -> V_162 ,
V_161 -> V_168 ) )
break;
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
int F_56 ( const struct V_30 * V_140 , struct V_10 * V_11 )
{
struct V_138 V_139 ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
if ( V_140 == NULL )
return 1 ;
V_139 . V_166 = V_11 -> V_41 ;
#if F_14 ( V_62 )
if ( V_139 . V_166 == V_63 ) {
V_139 . V_164 = V_11 -> V_65 . V_169 ;
V_139 . V_165 = V_11 -> V_66 . V_169 ;
} else
#endif
{
V_139 . V_164 = & V_26 -> V_55 ;
V_139 . V_165 = & V_26 -> V_56 ;
}
V_139 . V_149 = V_26 -> V_170 ;
V_139 . V_153 = F_57 ( V_26 -> V_52 ) ;
V_139 . V_156 = V_11 -> V_171 ;
return F_54 ( V_140 , & V_139 ) ;
}
static int F_58 ( const void * V_140 , int V_141 , int V_172 )
{
while ( V_141 >= 0 ) {
const struct V_143 * V_144 = V_140 ;
if ( V_172 > V_141 )
return 0 ;
if ( V_172 == V_141 )
return 1 ;
if ( V_144 -> V_142 < 4 || V_144 -> V_142 & 3 )
return 0 ;
V_141 -= V_144 -> V_142 ;
V_140 += V_144 -> V_142 ;
}
return 0 ;
}
static bool F_59 ( const struct V_143 * V_144 , int V_141 ,
int * V_173 )
{
int V_174 ;
struct V_160 * V_161 ;
* V_173 += sizeof( struct V_160 ) ;
if ( V_141 < * V_173 )
return false ;
V_161 = (struct V_160 * ) ( V_144 + 1 ) ;
switch ( V_161 -> V_166 ) {
case V_167 :
V_174 = 0 ;
break;
case V_6 :
V_174 = sizeof( struct V_175 ) ;
break;
case V_63 :
V_174 = sizeof( struct V_64 ) ;
break;
default:
return false ;
}
* V_173 += V_174 ;
if ( V_141 < * V_173 )
return false ;
if ( V_161 -> V_168 > 8 * V_174 )
return false ;
return true ;
}
static inline bool F_60 ( const struct V_143 * V_144 ,
int V_141 , int * V_173 )
{
* V_173 += sizeof( struct V_143 ) ;
if ( V_141 < * V_173 )
return false ;
return true ;
}
static int F_61 ( const void * V_176 , int V_177 )
{
const void * V_140 = V_176 ;
int V_141 = V_177 ;
while ( V_141 > 0 ) {
const struct V_143 * V_144 = V_140 ;
int V_173 = sizeof( struct V_143 ) ;
switch ( V_144 -> V_145 ) {
case V_158 :
case V_159 :
if ( ! F_59 ( V_140 , V_141 , & V_173 ) )
return - V_121 ;
break;
case V_148 :
case V_151 :
case V_152 :
case V_154 :
if ( ! F_60 ( V_140 , V_141 , & V_173 ) )
return - V_121 ;
break;
case V_155 :
case V_147 :
case V_146 :
break;
default:
return - V_121 ;
}
if ( V_144 -> V_145 != V_146 ) {
if ( V_144 -> V_150 < V_173 || V_144 -> V_150 > V_141 + 4 || V_144 -> V_150 & 3 )
return - V_121 ;
if ( V_144 -> V_150 < V_141 &&
! F_58 ( V_176 , V_177 , V_141 - V_144 -> V_150 ) )
return - V_121 ;
}
if ( V_144 -> V_142 < V_173 || V_144 -> V_142 > V_141 + 4 || V_144 -> V_142 & 3 )
return - V_121 ;
V_140 += V_144 -> V_142 ;
V_141 -= V_144 -> V_142 ;
}
return V_141 == 0 ? 0 : - V_121 ;
}
static int F_62 ( struct V_10 * V_11 ,
struct V_14 * V_15 ,
struct V_178 * V_179 ,
struct V_16 * V_28 ,
const struct V_30 * V_140 )
{
if ( ! F_56 ( V_140 , V_11 ) )
return 0 ;
return F_30 ( V_11 , V_15 , V_28 ,
F_43 ( F_44 ( V_179 -> V_15 ) . V_11 ) ,
F_44 ( V_179 -> V_15 ) . V_20 ,
V_179 -> V_29 -> V_126 , V_180 , V_179 -> V_29 ) ;
}
static int F_63 ( struct V_10 * V_11 ,
struct V_14 * V_15 ,
struct V_178 * V_179 ,
struct V_16 * V_28 ,
const struct V_30 * V_140 )
{
struct V_100 * V_101 = F_36 ( V_11 ) ;
if ( V_140 != NULL ) {
struct V_138 V_139 ;
V_139 . V_166 = V_101 -> V_104 ;
#if F_14 ( V_62 )
if ( V_101 -> V_104 == V_63 ) {
V_139 . V_164 = V_101 -> V_113 . V_169 ;
V_139 . V_165 = V_101 -> V_114 . V_169 ;
} else
#endif
{
V_139 . V_164 = & V_101 -> V_108 ;
V_139 . V_165 = & V_101 -> V_109 ;
}
V_139 . V_149 = V_101 -> V_181 ;
V_139 . V_153 = F_57 ( V_101 -> V_107 ) ;
V_139 . V_156 = 0 ;
if ( ! F_54 ( V_140 , & V_139 ) )
return 0 ;
}
return F_32 ( V_101 , V_15 , V_28 ,
F_44 ( V_179 -> V_15 ) . V_20 ,
V_179 -> V_29 -> V_126 , V_180 , V_179 -> V_29 ) ;
}
static inline void F_64 ( const struct V_10 * V_11 ,
const struct V_182 * V_17 ,
struct V_138 * V_139 )
{
struct V_183 * V_184 = F_65 ( V_17 ) ;
#if F_14 ( V_62 )
if ( V_11 -> V_41 == V_63 ) {
if ( V_17 -> V_185 -> V_166 == V_63 ) {
V_139 -> V_164 = V_184 -> V_186 . V_169 ;
V_139 -> V_165 = V_184 -> V_187 . V_169 ;
} else if ( V_17 -> V_185 -> V_166 == V_6 ) {
F_66 ( V_184 -> V_188 ,
& V_139 -> V_189 ) ;
F_66 ( V_184 -> V_190 ,
& V_139 -> V_191 ) ;
V_139 -> V_164 = V_139 -> V_189 . V_169 ;
V_139 -> V_165 = V_139 -> V_191 . V_169 ;
}
} else
#endif
{
V_139 -> V_164 = & V_184 -> V_188 ;
V_139 -> V_165 = & V_184 -> V_190 ;
}
}
static int F_67 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_182 * V_17 ,
struct V_18 * V_19 ,
T_1 V_20 , T_1 V_21 ,
const struct V_23 * V_24 )
{
const struct V_183 * V_184 = F_65 ( V_17 ) ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
struct V_27 * V_28 ;
struct V_23 * V_29 ;
long T_3 ;
V_29 = F_10 ( V_15 , V_20 , V_21 , V_24 -> V_36 , sizeof( * V_28 ) ,
V_180 ) ;
if ( ! V_29 )
return - V_37 ;
V_28 = F_11 ( V_29 ) ;
V_28 -> V_40 = V_11 -> V_41 ;
V_28 -> V_42 = V_192 ;
V_28 -> V_43 = 1 ;
V_28 -> V_44 = V_17 -> V_193 ;
V_28 -> V_45 . V_46 = V_11 -> V_47 ;
F_12 ( V_17 , V_28 -> V_45 . V_48 ) ;
T_3 = V_17 -> V_93 - V_194 ;
if ( T_3 < 0 )
T_3 = 0 ;
V_28 -> V_45 . V_49 = V_26 -> V_50 ;
V_28 -> V_45 . V_51 = V_184 -> V_195 ;
memset ( & V_28 -> V_45 . V_53 , 0 , sizeof( V_28 -> V_45 . V_53 ) ) ;
memset ( & V_28 -> V_45 . V_54 , 0 , sizeof( V_28 -> V_45 . V_54 ) ) ;
V_28 -> V_45 . V_53 [ 0 ] = V_184 -> V_188 ;
V_28 -> V_45 . V_54 [ 0 ] = V_184 -> V_190 ;
V_28 -> V_88 = F_34 ( T_3 ) ;
V_28 -> V_111 = 0 ;
V_28 -> V_112 = 0 ;
V_28 -> V_69 = F_16 ( V_19 , F_17 ( V_11 ) ) ;
V_28 -> V_70 = 0 ;
#if F_14 ( V_62 )
if ( V_28 -> V_40 == V_63 ) {
struct V_138 V_139 ;
F_64 ( V_11 , V_17 , & V_139 ) ;
memcpy ( V_28 -> V_45 . V_53 , V_139 . V_164 , sizeof( struct V_64 ) ) ;
memcpy ( V_28 -> V_45 . V_54 , V_139 . V_165 , sizeof( struct V_64 ) ) ;
}
#endif
return F_28 ( V_15 , V_29 ) ;
}
static int F_68 ( struct V_14 * V_15 , struct V_10 * V_11 ,
struct V_178 * V_179 ,
struct V_16 * V_28 ,
const struct V_30 * V_140 )
{
struct V_138 V_139 ;
struct V_12 * V_13 = F_31 ( V_11 ) ;
struct V_196 * V_197 ;
struct V_25 * V_26 = F_8 ( V_11 ) ;
int V_198 , V_199 ;
int V_200 , V_201 ;
int V_118 = 0 ;
V_199 = V_179 -> args [ 3 ] ;
V_201 = V_179 -> args [ 4 ] ;
if ( V_199 > 0 )
V_199 -- ;
V_139 . V_166 = V_11 -> V_41 ;
F_69 ( & V_13 -> V_202 . V_203 ) ;
V_197 = V_13 -> V_202 . V_204 ;
if ( ! V_197 || ! V_197 -> V_205 )
goto V_82;
if ( V_140 != NULL ) {
V_139 . V_149 = V_26 -> V_170 ;
V_139 . V_156 = V_11 -> V_171 ;
}
for ( V_198 = V_199 ; V_198 < V_197 -> V_206 ; V_198 ++ ) {
struct V_182 * V_17 , * V_207 = V_197 -> V_208 [ V_198 ] ;
V_200 = 0 ;
for ( V_17 = V_207 ; V_17 ; V_200 ++ , V_17 = V_17 -> V_209 ) {
struct V_183 * V_184 = F_65 ( V_17 ) ;
if ( V_200 < V_201 )
continue;
if ( V_28 -> V_45 . V_51 != V_184 -> V_195 &&
V_28 -> V_45 . V_51 )
continue;
if ( V_140 ) {
F_64 ( V_11 , V_17 , & V_139 ) ;
V_139 . V_153 = F_57 ( V_184 -> V_195 ) ;
if ( ! F_54 ( V_140 , & V_139 ) )
continue;
}
V_118 = F_67 ( V_15 , V_11 , V_17 ,
F_43 ( F_44 ( V_179 -> V_15 ) . V_11 ) ,
F_44 ( V_179 -> V_15 ) . V_20 ,
V_179 -> V_29 -> V_126 , V_179 -> V_29 ) ;
if ( V_118 < 0 ) {
V_179 -> args [ 3 ] = V_198 + 1 ;
V_179 -> args [ 4 ] = V_200 ;
goto V_82;
}
}
V_201 = 0 ;
}
V_82:
F_70 ( & V_13 -> V_202 . V_203 ) ;
return V_118 ;
}
void F_71 ( struct V_115 * V_116 , struct V_14 * V_15 ,
struct V_178 * V_179 , struct V_16 * V_28 , struct V_30 * V_140 )
{
int V_210 , V_211 ;
int V_212 , V_213 ;
struct V_120 * V_120 = F_38 ( V_15 -> V_11 ) ;
V_212 = V_179 -> args [ 1 ] ;
V_213 = V_211 = V_179 -> args [ 2 ] ;
if ( V_179 -> args [ 0 ] == 0 ) {
if ( ! ( V_28 -> V_214 & ( V_215 | V_216 ) ) )
goto V_217;
for ( V_210 = V_212 ; V_210 < V_218 ; V_210 ++ ) {
struct V_10 * V_11 ;
struct V_219 * V_220 ;
struct V_221 * V_222 ;
V_211 = 0 ;
V_222 = & V_116 -> V_223 [ V_210 ] ;
F_72 ( & V_222 -> V_224 ) ;
F_73 (sk, node, &ilb->head) {
struct V_25 * V_26 = F_8 ( V_11 ) ;
if ( ! F_74 ( F_38 ( V_11 ) , V_120 ) )
continue;
if ( V_211 < V_213 ) {
V_211 ++ ;
continue;
}
if ( V_28 -> V_122 != V_167 &&
V_11 -> V_41 != V_28 -> V_122 )
goto V_225;
if ( V_28 -> V_45 . V_49 != V_26 -> V_50 &&
V_28 -> V_45 . V_49 )
goto V_225;
if ( ! ( V_28 -> V_214 & V_215 ) ||
V_28 -> V_45 . V_51 ||
V_179 -> args [ 3 ] > 0 )
goto V_226;
if ( F_62 ( V_11 , V_15 , V_179 , V_28 , V_140 ) < 0 ) {
F_75 ( & V_222 -> V_224 ) ;
goto V_227;
}
V_226:
if ( ! ( V_28 -> V_214 & V_216 ) )
goto V_225;
if ( F_68 ( V_15 , V_11 , V_179 , V_28 , V_140 ) < 0 ) {
F_75 ( & V_222 -> V_224 ) ;
goto V_227;
}
V_225:
V_179 -> args [ 3 ] = 0 ;
V_179 -> args [ 4 ] = 0 ;
++ V_211 ;
}
F_75 ( & V_222 -> V_224 ) ;
V_213 = 0 ;
V_179 -> args [ 3 ] = 0 ;
V_179 -> args [ 4 ] = 0 ;
}
V_217:
V_179 -> args [ 0 ] = 1 ;
V_212 = V_211 = V_213 = 0 ;
}
if ( ! ( V_28 -> V_214 & ~ ( V_215 | V_216 ) ) )
goto V_82;
for ( V_210 = V_212 ; V_210 <= V_116 -> V_228 ; V_210 ++ ) {
struct V_229 * V_207 = & V_116 -> V_230 [ V_210 ] ;
T_6 * V_224 = F_76 ( V_116 , V_210 ) ;
struct V_10 * V_11 ;
struct V_219 * V_220 ;
V_211 = 0 ;
if ( F_77 ( & V_207 -> V_231 ) )
continue;
if ( V_210 > V_212 )
V_213 = 0 ;
F_72 ( V_224 ) ;
F_73 (sk, node, &head->chain) {
int V_232 ;
int V_233 ;
if ( ! F_74 ( F_38 ( V_11 ) , V_120 ) )
continue;
if ( V_211 < V_213 )
goto V_234;
V_233 = ( V_11 -> V_38 == V_39 ) ?
F_36 ( V_11 ) -> V_110 : V_11 -> V_38 ;
if ( ! ( V_28 -> V_214 & ( 1 << V_233 ) ) )
goto V_234;
if ( V_28 -> V_122 != V_167 &&
V_11 -> V_41 != V_28 -> V_122 )
goto V_234;
if ( V_28 -> V_45 . V_49 != F_78 ( V_11 -> V_235 ) &&
V_28 -> V_45 . V_49 )
goto V_234;
if ( V_28 -> V_45 . V_51 != V_11 -> V_236 &&
V_28 -> V_45 . V_51 )
goto V_234;
if ( V_11 -> V_38 == V_39 )
V_232 = F_63 ( V_11 , V_15 , V_179 , V_28 , V_140 ) ;
else
V_232 = F_62 ( V_11 , V_15 , V_179 , V_28 , V_140 ) ;
if ( V_232 < 0 ) {
F_75 ( V_224 ) ;
goto V_227;
}
V_234:
++ V_211 ;
}
F_75 ( V_224 ) ;
}
V_227:
V_179 -> args [ 1 ] = V_210 ;
V_179 -> args [ 2 ] = V_211 ;
V_82:
;
}
static int F_79 ( struct V_14 * V_15 , struct V_178 * V_179 ,
struct V_16 * V_28 , struct V_30 * V_140 )
{
const struct V_1 * V_9 ;
int V_118 = 0 ;
V_9 = F_1 ( V_28 -> V_35 ) ;
if ( ! F_50 ( V_9 ) )
V_9 -> V_237 ( V_15 , V_179 , V_28 , V_140 ) ;
else
V_118 = F_51 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_118 ? : V_15 -> V_141 ;
}
static int F_80 ( struct V_14 * V_15 , struct V_178 * V_179 )
{
struct V_30 * V_140 = NULL ;
int V_238 = sizeof( struct V_16 ) ;
if ( F_81 ( V_179 -> V_29 , V_238 ) )
V_140 = F_82 ( V_179 -> V_29 , V_238 , V_239 ) ;
return F_79 ( V_15 , V_179 , F_11 ( V_179 -> V_29 ) , V_140 ) ;
}
static inline int F_83 ( int type )
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
static int F_84 ( struct V_14 * V_15 , struct V_178 * V_179 )
{
struct V_244 * V_245 = F_11 ( V_179 -> V_29 ) ;
struct V_16 V_17 ;
struct V_30 * V_140 = NULL ;
int V_238 = sizeof( struct V_244 ) ;
V_17 . V_122 = V_167 ;
V_17 . V_35 = F_83 ( V_179 -> V_29 -> V_36 ) ;
V_17 . V_34 = V_245 -> V_34 ;
V_17 . V_214 = V_245 -> V_214 ;
V_17 . V_45 = V_245 -> V_45 ;
if ( F_81 ( V_179 -> V_29 , V_238 ) )
V_140 = F_82 ( V_179 -> V_29 , V_238 , V_239 ) ;
return F_79 ( V_15 , V_179 , & V_17 , V_140 ) ;
}
static int F_85 ( struct V_14 * V_117 ,
const struct V_23 * V_29 )
{
struct V_244 * V_245 = F_11 ( V_29 ) ;
struct V_16 V_17 ;
V_17 . V_122 = V_245 -> V_40 ;
V_17 . V_35 = F_83 ( V_29 -> V_36 ) ;
V_17 . V_34 = V_245 -> V_34 ;
V_17 . V_214 = V_245 -> V_214 ;
V_17 . V_45 = V_245 -> V_45 ;
return F_49 ( V_117 , V_29 , & V_17 ) ;
}
static int F_86 ( struct V_14 * V_15 , struct V_23 * V_29 )
{
int V_238 = sizeof( struct V_244 ) ;
struct V_120 * V_120 = F_38 ( V_15 -> V_11 ) ;
if ( V_29 -> V_36 >= V_246 ||
F_87 ( V_29 ) < V_238 )
return - V_121 ;
if ( V_29 -> V_22 & V_247 ) {
if ( F_81 ( V_29 , V_238 ) ) {
struct V_30 * V_31 ;
V_31 = F_82 ( V_29 , V_238 ,
V_239 ) ;
if ( V_31 == NULL ||
F_55 ( V_31 ) < sizeof( struct V_143 ) ||
F_61 ( F_26 ( V_31 ) , F_55 ( V_31 ) ) )
return - V_121 ;
}
{
struct V_248 V_249 = {
. V_237 = F_84 ,
} ;
return F_88 ( V_120 -> V_127 , V_15 , V_29 , & V_249 ) ;
}
}
return F_85 ( V_15 , V_29 ) ;
}
static int F_89 ( struct V_14 * V_15 , struct V_23 * V_250 )
{
int V_238 = sizeof( struct V_16 ) ;
struct V_120 * V_120 = F_38 ( V_15 -> V_11 ) ;
if ( F_87 ( V_250 ) < V_238 )
return - V_121 ;
if ( V_250 -> V_22 & V_247 ) {
if ( F_81 ( V_250 , V_238 ) ) {
struct V_30 * V_31 ;
V_31 = F_82 ( V_250 , V_238 ,
V_239 ) ;
if ( V_31 == NULL ||
F_55 ( V_31 ) < sizeof( struct V_143 ) ||
F_61 ( F_26 ( V_31 ) , F_55 ( V_31 ) ) )
return - V_121 ;
}
{
struct V_248 V_249 = {
. V_237 = F_80 ,
} ;
return F_88 ( V_120 -> V_127 , V_15 , V_250 , & V_249 ) ;
}
}
return F_49 ( V_15 , V_250 , F_11 ( V_250 ) ) ;
}
int F_90 ( const struct V_1 * V_250 )
{
const T_7 type = V_250 -> V_251 ;
int V_118 = - V_121 ;
if ( type >= V_252 )
goto V_82;
F_3 ( & V_7 ) ;
V_118 = - V_253 ;
if ( V_3 [ type ] == NULL ) {
V_3 [ type ] = V_250 ;
V_118 = 0 ;
}
F_6 ( & V_7 ) ;
V_82:
return V_118 ;
}
void F_91 ( const struct V_1 * V_250 )
{
const T_7 type = V_250 -> V_251 ;
if ( type >= V_252 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_8 F_92 ( void )
{
const int V_254 = ( V_252 *
sizeof( struct V_1 * ) ) ;
int V_118 = - V_125 ;
V_3 = F_93 ( V_254 , V_124 ) ;
if ( ! V_3 )
goto V_82;
V_118 = F_94 ( & V_1 ) ;
if ( V_118 )
goto V_255;
V_118 = F_94 ( & V_256 ) ;
if ( V_118 )
goto V_257;
F_95 ( F_86 ) ;
V_82:
return V_118 ;
V_257:
F_96 ( & V_1 ) ;
V_255:
F_97 ( V_3 ) ;
goto V_82;
}
static void T_9 F_98 ( void )
{
F_96 ( & V_256 ) ;
F_96 ( & V_1 ) ;
F_99 ( F_86 ) ;
F_97 ( V_3 ) ;
}
