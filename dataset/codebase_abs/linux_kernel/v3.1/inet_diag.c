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
#if F_15 ( V_56 ) || F_15 ( V_57 )
if ( V_23 -> V_39 == V_58 ) {
const struct V_59 * V_60 = F_16 ( V_9 ) ;
F_17 ( (struct V_61 * ) V_23 -> V_44 . V_52 ,
& V_60 -> V_62 ) ;
F_17 ( (struct V_61 * ) V_23 -> V_44 . V_54 ,
& V_60 -> V_63 ) ;
}
#endif
#define F_18 ( T_4 ) DIV_ROUND_UP((tmo - jiffies) * 1000, HZ)
if ( V_21 -> V_64 == V_65 ) {
V_23 -> V_42 = 1 ;
V_23 -> V_43 = V_21 -> V_66 ;
V_23 -> V_67 = F_18 ( V_21 -> V_68 ) ;
} else if ( V_21 -> V_64 == V_69 ) {
V_23 -> V_42 = 4 ;
V_23 -> V_43 = V_21 -> V_70 ;
V_23 -> V_67 = F_18 ( V_21 -> V_68 ) ;
} else if ( F_19 ( & V_9 -> V_71 ) ) {
V_23 -> V_42 = 2 ;
V_23 -> V_43 = V_21 -> V_70 ;
V_23 -> V_67 = F_18 ( V_9 -> V_71 . V_72 ) ;
} else {
V_23 -> V_42 = 0 ;
V_23 -> V_67 = 0 ;
}
#undef F_18
V_23 -> V_73 = F_20 ( V_9 ) ;
V_23 -> V_74 = F_21 ( V_9 ) ;
if ( V_27 ) {
V_27 -> V_75 = F_22 ( V_9 ) ;
V_27 -> V_76 = V_9 -> V_77 ;
V_27 -> V_78 = V_9 -> V_79 ;
V_27 -> V_80 = F_23 ( V_9 ) ;
}
V_7 -> V_81 ( V_9 , V_23 , V_25 ) ;
if ( V_9 -> V_30 < V_31 &&
V_21 -> V_36 && V_21 -> V_36 -> V_82 )
V_21 -> V_36 -> V_82 ( V_9 , V_12 , V_11 ) ;
V_24 -> V_83 = F_10 ( V_11 ) - V_28 ;
return V_11 -> V_37 ;
V_84:
V_85:
F_24 ( V_11 , V_28 ) ;
return - V_86 ;
}
static int F_25 ( struct V_87 * V_88 ,
struct V_10 * V_11 , int V_12 , T_1 V_13 ,
T_1 V_14 , T_2 V_15 ,
const struct V_16 * V_17 )
{
long T_4 ;
struct V_22 * V_23 ;
const unsigned char * V_89 = F_10 ( V_11 ) ;
struct V_16 * V_24 = F_12 ( V_11 , V_13 , V_14 ,
V_17 -> V_29 , sizeof( * V_23 ) ) ;
V_23 = F_13 ( V_24 ) ;
F_11 ( V_88 -> V_90 != V_31 ) ;
V_24 -> V_15 = V_15 ;
T_4 = V_88 -> V_91 - V_92 ;
if ( T_4 < 0 )
T_4 = 0 ;
V_23 -> V_39 = V_88 -> V_93 ;
V_23 -> V_43 = 0 ;
V_23 -> V_44 . V_45 = V_88 -> V_94 ;
V_23 -> V_44 . V_47 [ 0 ] = ( T_1 ) ( unsigned long ) V_88 ;
V_23 -> V_44 . V_47 [ 1 ] = ( T_1 ) ( ( ( unsigned long ) V_88 >> 31 ) >> 1 ) ;
V_23 -> V_44 . V_48 = V_88 -> V_95 ;
V_23 -> V_44 . V_50 = V_88 -> V_96 ;
V_23 -> V_44 . V_52 [ 0 ] = V_88 -> V_97 ;
V_23 -> V_44 . V_54 [ 0 ] = V_88 -> V_98 ;
V_23 -> V_41 = V_88 -> V_99 ;
V_23 -> V_42 = 3 ;
V_23 -> V_67 = F_26 ( T_4 * 1000 , V_100 ) ;
V_23 -> V_101 = 0 ;
V_23 -> V_102 = 0 ;
V_23 -> V_73 = 0 ;
V_23 -> V_74 = 0 ;
#if F_15 ( V_56 ) || F_15 ( V_57 )
if ( V_88 -> V_93 == V_58 ) {
const struct V_103 * V_104 =
F_27 ( (struct V_8 * ) V_88 ) ;
F_17 ( (struct V_61 * ) V_23 -> V_44 . V_52 ,
& V_104 -> V_105 ) ;
F_17 ( (struct V_61 * ) V_23 -> V_44 . V_54 ,
& V_104 -> V_106 ) ;
}
#endif
V_24 -> V_83 = F_10 ( V_11 ) - V_89 ;
return V_11 -> V_37 ;
V_85:
F_24 ( V_11 , V_89 ) ;
return - V_86 ;
}
static int F_28 ( struct V_8 * V_9 , struct V_10 * V_11 ,
int V_12 , T_1 V_13 , T_1 V_14 , T_2 V_15 ,
const struct V_16 * V_17 )
{
if ( V_9 -> V_30 == V_31 )
return F_25 ( (struct V_87 * ) V_9 ,
V_11 , V_12 , V_13 , V_14 , V_15 ,
V_17 ) ;
return F_7 ( V_9 , V_11 , V_12 , V_13 , V_14 , V_15 , V_17 ) ;
}
static int F_29 ( struct V_10 * V_107 ,
const struct V_16 * V_24 )
{
int V_108 ;
struct V_8 * V_9 ;
struct V_109 * V_110 = F_13 ( V_24 ) ;
struct V_10 * V_111 ;
struct V_112 * V_113 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_24 -> V_29 ) ;
if ( F_30 ( V_7 ) ) {
V_108 = F_31 ( V_7 ) ;
goto V_114;
}
V_113 = V_7 -> V_115 ;
V_108 = - V_116 ;
if ( V_110 -> V_39 == V_117 ) {
V_9 = F_32 ( & V_118 , V_113 , V_110 -> V_44 . V_54 [ 0 ] ,
V_110 -> V_44 . V_50 , V_110 -> V_44 . V_52 [ 0 ] ,
V_110 -> V_44 . V_48 , V_110 -> V_44 . V_45 ) ;
}
#if F_15 ( V_56 ) || F_15 ( V_57 )
else if ( V_110 -> V_39 == V_58 ) {
V_9 = F_33 ( & V_118 , V_113 ,
(struct V_61 * ) V_110 -> V_44 . V_54 ,
V_110 -> V_44 . V_50 ,
(struct V_61 * ) V_110 -> V_44 . V_52 ,
V_110 -> V_44 . V_48 ,
V_110 -> V_44 . V_45 ) ;
}
#endif
else {
goto V_114;
}
V_108 = - V_6 ;
if ( V_9 == NULL )
goto V_114;
V_108 = - V_119 ;
if ( ( V_110 -> V_44 . V_47 [ 0 ] != V_120 ||
V_110 -> V_44 . V_47 [ 1 ] != V_120 ) &&
( ( T_1 ) ( unsigned long ) V_9 != V_110 -> V_44 . V_47 [ 0 ] ||
( T_1 ) ( ( ( ( unsigned long ) V_9 ) >> 31 ) >> 1 ) != V_110 -> V_44 . V_47 [ 1 ] ) )
goto V_121;
V_108 = - V_122 ;
V_111 = F_34 ( F_35 ( ( sizeof( struct V_22 ) +
sizeof( struct V_26 ) +
V_7 -> V_34 + 64 ) ) ,
V_123 ) ;
if ( ! V_111 )
goto V_121;
V_108 = F_28 ( V_9 , V_111 , V_110 -> V_124 ,
F_36 ( V_107 ) . V_13 ,
V_24 -> V_125 , 0 , V_24 ) ;
if ( V_108 < 0 ) {
F_37 ( V_108 == - V_86 ) ;
F_38 ( V_111 ) ;
goto V_121;
}
V_108 = F_39 ( V_126 , V_111 , F_36 ( V_107 ) . V_13 ,
V_127 ) ;
if ( V_108 > 0 )
V_108 = 0 ;
V_121:
if ( V_9 ) {
if ( V_9 -> V_30 == V_31 )
F_40 ( (struct V_87 * ) V_9 ) ;
else
F_41 ( V_9 ) ;
}
V_114:
F_5 ( V_7 ) ;
return V_108 ;
}
static int F_42 ( const T_5 * V_128 , const T_5 * V_129 , int V_130 )
{
int V_131 = V_130 >> 5 ;
V_130 &= 0x1f ;
if ( V_131 ) {
if ( memcmp ( V_128 , V_129 , V_131 << 2 ) )
return 0 ;
}
if ( V_130 ) {
T_5 V_132 , V_133 ;
T_5 V_134 ;
V_132 = V_128 [ V_131 ] ;
V_133 = V_129 [ V_131 ] ;
V_134 = F_43 ( ( 0xffffffff ) << ( 32 - V_130 ) ) ;
if ( ( V_132 ^ V_133 ) & V_134 )
return 0 ;
}
return 1 ;
}
static int F_44 ( const void * V_135 , int V_37 ,
const struct V_136 * V_137 )
{
while ( V_37 > 0 ) {
int V_138 = 1 ;
const struct V_139 * V_140 = V_135 ;
switch ( V_140 -> V_141 ) {
case V_142 :
break;
case V_143 :
V_138 = 0 ;
break;
case V_144 :
V_138 = V_137 -> V_145 >= V_140 [ 1 ] . V_146 ;
break;
case V_147 :
V_138 = V_137 -> V_145 <= V_140 [ 1 ] . V_146 ;
break;
case V_148 :
V_138 = V_137 -> V_149 >= V_140 [ 1 ] . V_146 ;
break;
case V_150 :
V_138 = V_137 -> V_149 <= V_140 [ 1 ] . V_146 ;
break;
case V_151 :
V_138 = ! ( V_137 -> V_152 & V_153 ) ;
break;
case V_154 :
case V_155 : {
struct V_156 * V_157 ;
T_5 * V_158 ;
V_157 = (struct V_156 * ) ( V_140 + 1 ) ;
if ( V_157 -> V_159 != - 1 &&
V_157 -> V_159 != ( V_140 -> V_141 == V_154 ?
V_137 -> V_145 : V_137 -> V_149 ) ) {
V_138 = 0 ;
break;
}
if ( V_157 -> V_160 == 0 )
break;
if ( V_140 -> V_141 == V_154 )
V_158 = V_137 -> V_161 ;
else
V_158 = V_137 -> V_63 ;
if ( F_42 ( V_158 , V_157 -> V_158 ,
V_157 -> V_160 ) )
break;
if ( V_137 -> V_162 == V_58 &&
V_157 -> V_162 == V_117 ) {
if ( V_158 [ 0 ] == 0 && V_158 [ 1 ] == 0 &&
V_158 [ 2 ] == F_43 ( 0xffff ) &&
F_42 ( V_158 + 3 , V_157 -> V_158 ,
V_157 -> V_160 ) )
break;
}
V_138 = 0 ;
break;
}
}
if ( V_138 ) {
V_37 -= V_140 -> V_138 ;
V_135 += V_140 -> V_138 ;
} else {
V_37 -= V_140 -> V_146 ;
V_135 += V_140 -> V_146 ;
}
}
return V_37 == 0 ;
}
static int F_45 ( const void * V_135 , int V_37 , int V_163 )
{
while ( V_37 >= 0 ) {
const struct V_139 * V_140 = V_135 ;
if ( V_163 > V_37 )
return 0 ;
if ( V_163 == V_37 )
return 1 ;
if ( V_140 -> V_138 < 4 || V_140 -> V_138 & 3 )
return 0 ;
V_37 -= V_140 -> V_138 ;
V_135 += V_140 -> V_138 ;
}
return 0 ;
}
static int F_46 ( const void * V_164 , int V_165 )
{
const void * V_135 = V_164 ;
int V_37 = V_165 ;
while ( V_37 > 0 ) {
const struct V_139 * V_140 = V_135 ;
switch ( V_140 -> V_141 ) {
case V_151 :
case V_154 :
case V_155 :
case V_144 :
case V_147 :
case V_148 :
case V_150 :
case V_143 :
if ( V_140 -> V_146 < 4 || V_140 -> V_146 > V_37 + 4 || V_140 -> V_146 & 3 )
return - V_116 ;
if ( V_140 -> V_146 < V_37 &&
! F_45 ( V_164 , V_165 , V_37 - V_140 -> V_146 ) )
return - V_116 ;
break;
case V_142 :
break;
default:
return - V_116 ;
}
if ( V_140 -> V_138 < 4 || V_140 -> V_138 > V_37 + 4 || V_140 -> V_138 & 3 )
return - V_116 ;
V_135 += V_140 -> V_138 ;
V_37 -= V_140 -> V_138 ;
}
return V_37 == 0 ? 0 : - V_116 ;
}
static int F_47 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_166 * V_167 )
{
struct V_109 * V_23 = F_13 ( V_167 -> V_24 ) ;
if ( F_48 ( V_167 -> V_24 , sizeof( * V_23 ) ) ) {
struct V_136 V_137 ;
const struct V_168 * V_135 = F_49 ( V_167 -> V_24 ,
sizeof( * V_23 ) ,
V_169 ) ;
struct V_18 * V_19 = F_8 ( V_9 ) ;
V_137 . V_162 = V_9 -> V_40 ;
#if F_15 ( V_56 ) || F_15 ( V_57 )
if ( V_137 . V_162 == V_58 ) {
struct V_59 * V_60 = F_16 ( V_9 ) ;
V_137 . V_161 = V_60 -> V_62 . V_170 ;
V_137 . V_63 = V_60 -> V_63 . V_170 ;
} else
#endif
{
V_137 . V_161 = & V_19 -> V_53 ;
V_137 . V_63 = & V_19 -> V_55 ;
}
V_137 . V_145 = V_19 -> V_171 ;
V_137 . V_149 = F_50 ( V_19 -> V_51 ) ;
V_137 . V_152 = V_9 -> V_172 ;
if ( ! F_44 ( F_51 ( V_135 ) , F_52 ( V_135 ) , & V_137 ) )
return 0 ;
}
return F_7 ( V_9 , V_11 , V_23 -> V_124 ,
F_36 ( V_167 -> V_11 ) . V_13 ,
V_167 -> V_24 -> V_125 , V_173 , V_167 -> V_24 ) ;
}
static int F_53 ( struct V_87 * V_88 ,
struct V_10 * V_11 ,
struct V_166 * V_167 )
{
struct V_109 * V_23 = F_13 ( V_167 -> V_24 ) ;
if ( F_48 ( V_167 -> V_24 , sizeof( * V_23 ) ) ) {
struct V_136 V_137 ;
const struct V_168 * V_135 = F_49 ( V_167 -> V_24 ,
sizeof( * V_23 ) ,
V_169 ) ;
V_137 . V_162 = V_88 -> V_93 ;
#if F_15 ( V_56 ) || F_15 ( V_57 )
if ( V_88 -> V_93 == V_58 ) {
struct V_103 * V_104 =
F_27 ( (struct V_8 * ) V_88 ) ;
V_137 . V_161 = V_104 -> V_105 . V_170 ;
V_137 . V_63 = V_104 -> V_106 . V_170 ;
} else
#endif
{
V_137 . V_161 = & V_88 -> V_97 ;
V_137 . V_63 = & V_88 -> V_98 ;
}
V_137 . V_145 = V_88 -> V_174 ;
V_137 . V_149 = F_50 ( V_88 -> V_96 ) ;
V_137 . V_152 = 0 ;
if ( ! F_44 ( F_51 ( V_135 ) , F_52 ( V_135 ) , & V_137 ) )
return 0 ;
}
return F_25 ( V_88 , V_11 , V_23 -> V_124 ,
F_36 ( V_167 -> V_11 ) . V_13 ,
V_167 -> V_24 -> V_125 , V_173 , V_167 -> V_24 ) ;
}
static int F_54 ( struct V_10 * V_11 , struct V_8 * V_9 ,
struct V_175 * V_110 , T_1 V_13 , T_1 V_14 ,
const struct V_16 * V_17 )
{
const struct V_176 * V_177 = F_55 ( V_110 ) ;
struct V_18 * V_19 = F_8 ( V_9 ) ;
unsigned char * V_28 = F_10 ( V_11 ) ;
struct V_22 * V_23 ;
struct V_16 * V_24 ;
long T_4 ;
V_24 = F_12 ( V_11 , V_13 , V_14 , V_17 -> V_29 , sizeof( * V_23 ) ) ;
V_24 -> V_15 = V_173 ;
V_23 = F_13 ( V_24 ) ;
V_23 -> V_39 = V_9 -> V_40 ;
V_23 -> V_41 = V_178 ;
V_23 -> V_42 = 1 ;
V_23 -> V_43 = V_110 -> V_179 ;
V_23 -> V_44 . V_45 = V_9 -> V_46 ;
V_23 -> V_44 . V_47 [ 0 ] = ( T_1 ) ( unsigned long ) V_110 ;
V_23 -> V_44 . V_47 [ 1 ] = ( T_1 ) ( ( ( unsigned long ) V_110 >> 31 ) >> 1 ) ;
T_4 = V_110 -> V_72 - V_92 ;
if ( T_4 < 0 )
T_4 = 0 ;
V_23 -> V_44 . V_48 = V_19 -> V_49 ;
V_23 -> V_44 . V_50 = V_177 -> V_180 ;
V_23 -> V_44 . V_52 [ 0 ] = V_177 -> V_181 ;
V_23 -> V_44 . V_54 [ 0 ] = V_177 -> V_182 ;
V_23 -> V_67 = F_56 ( T_4 ) ;
V_23 -> V_101 = 0 ;
V_23 -> V_102 = 0 ;
V_23 -> V_73 = F_20 ( V_9 ) ;
V_23 -> V_74 = 0 ;
#if F_15 ( V_56 ) || F_15 ( V_57 )
if ( V_23 -> V_39 == V_58 ) {
F_17 ( (struct V_61 * ) V_23 -> V_44 . V_52 ,
& F_57 ( V_110 ) -> V_181 ) ;
F_17 ( (struct V_61 * ) V_23 -> V_44 . V_54 ,
& F_57 ( V_110 ) -> V_182 ) ;
}
#endif
V_24 -> V_83 = F_10 ( V_11 ) - V_28 ;
return V_11 -> V_37 ;
V_85:
F_24 ( V_11 , V_28 ) ;
return - 1 ;
}
static int F_58 ( struct V_10 * V_11 , struct V_8 * V_9 ,
struct V_166 * V_167 )
{
struct V_136 V_137 ;
struct V_109 * V_23 = F_13 ( V_167 -> V_24 ) ;
struct V_20 * V_21 = F_9 ( V_9 ) ;
struct V_183 * V_184 ;
const struct V_168 * V_135 = NULL ;
struct V_18 * V_19 = F_8 ( V_9 ) ;
int V_185 , V_186 ;
int V_187 , V_188 ;
int V_108 = 0 ;
V_186 = V_167 -> args [ 3 ] ;
V_188 = V_167 -> args [ 4 ] ;
if ( V_186 > 0 )
V_186 -- ;
V_137 . V_162 = V_9 -> V_40 ;
F_59 ( & V_21 -> V_189 . V_190 ) ;
V_184 = V_21 -> V_189 . V_191 ;
if ( ! V_184 || ! V_184 -> V_192 )
goto V_121;
if ( F_48 ( V_167 -> V_24 , sizeof( * V_23 ) ) ) {
V_135 = F_49 ( V_167 -> V_24 , sizeof( * V_23 ) ,
V_169 ) ;
V_137 . V_145 = V_19 -> V_171 ;
V_137 . V_152 = V_9 -> V_172 ;
}
for ( V_185 = V_186 ; V_185 < V_184 -> V_193 ; V_185 ++ ) {
struct V_175 * V_110 , * V_194 = V_184 -> V_195 [ V_185 ] ;
V_187 = 0 ;
for ( V_110 = V_194 ; V_110 ; V_187 ++ , V_110 = V_110 -> V_196 ) {
struct V_176 * V_177 = F_55 ( V_110 ) ;
if ( V_187 < V_188 )
continue;
if ( V_23 -> V_44 . V_50 != V_177 -> V_180 &&
V_23 -> V_44 . V_50 )
continue;
if ( V_135 ) {
V_137 . V_161 =
#if F_15 ( V_56 ) || F_15 ( V_57 )
( V_137 . V_162 == V_58 ) ?
F_57 ( V_110 ) -> V_181 . V_170 :
#endif
& V_177 -> V_181 ;
V_137 . V_63 =
#if F_15 ( V_56 ) || F_15 ( V_57 )
( V_137 . V_162 == V_58 ) ?
F_57 ( V_110 ) -> V_182 . V_170 :
#endif
& V_177 -> V_182 ;
V_137 . V_149 = F_50 ( V_177 -> V_180 ) ;
if ( ! F_44 ( F_51 ( V_135 ) ,
F_52 ( V_135 ) , & V_137 ) )
continue;
}
V_108 = F_54 ( V_11 , V_9 , V_110 ,
F_36 ( V_167 -> V_11 ) . V_13 ,
V_167 -> V_24 -> V_125 , V_167 -> V_24 ) ;
if ( V_108 < 0 ) {
V_167 -> args [ 3 ] = V_185 + 1 ;
V_167 -> args [ 4 ] = V_187 ;
goto V_121;
}
}
V_188 = 0 ;
}
V_121:
F_60 ( & V_21 -> V_189 . V_190 ) ;
return V_108 ;
}
static int F_61 ( struct V_10 * V_11 , struct V_166 * V_167 )
{
int V_197 , V_198 ;
int V_199 , V_200 ;
struct V_109 * V_23 = F_13 ( V_167 -> V_24 ) ;
const struct V_1 * V_7 ;
struct V_112 * V_113 ;
V_7 = F_1 ( V_167 -> V_24 -> V_29 ) ;
if ( F_30 ( V_7 ) )
goto V_114;
V_113 = V_7 -> V_115 ;
V_199 = V_167 -> args [ 1 ] ;
V_200 = V_198 = V_167 -> args [ 2 ] ;
if ( V_167 -> args [ 0 ] == 0 ) {
if ( ! ( V_23 -> V_201 & ( V_202 | V_203 ) ) )
goto V_204;
for ( V_197 = V_199 ; V_197 < V_205 ; V_197 ++ ) {
struct V_8 * V_9 ;
struct V_206 * V_207 ;
struct V_208 * V_209 ;
V_198 = 0 ;
V_209 = & V_113 -> V_210 [ V_197 ] ;
F_62 ( & V_209 -> V_211 ) ;
F_63 (sk, node, &ilb->head) {
struct V_18 * V_19 = F_8 ( V_9 ) ;
if ( V_198 < V_200 ) {
V_198 ++ ;
continue;
}
if ( V_23 -> V_44 . V_48 != V_19 -> V_49 &&
V_23 -> V_44 . V_48 )
goto V_212;
if ( ! ( V_23 -> V_201 & V_202 ) ||
V_23 -> V_44 . V_50 ||
V_167 -> args [ 3 ] > 0 )
goto V_213;
if ( F_47 ( V_9 , V_11 , V_167 ) < 0 ) {
F_64 ( & V_209 -> V_211 ) ;
goto V_214;
}
V_213:
if ( ! ( V_23 -> V_201 & V_203 ) )
goto V_212;
if ( F_58 ( V_11 , V_9 , V_167 ) < 0 ) {
F_64 ( & V_209 -> V_211 ) ;
goto V_214;
}
V_212:
V_167 -> args [ 3 ] = 0 ;
V_167 -> args [ 4 ] = 0 ;
++ V_198 ;
}
F_64 ( & V_209 -> V_211 ) ;
V_200 = 0 ;
V_167 -> args [ 3 ] = 0 ;
V_167 -> args [ 4 ] = 0 ;
}
V_204:
V_167 -> args [ 0 ] = 1 ;
V_199 = V_198 = V_200 = 0 ;
}
if ( ! ( V_23 -> V_201 & ~ ( V_202 | V_203 ) ) )
goto V_114;
for ( V_197 = V_199 ; V_197 <= V_113 -> V_215 ; V_197 ++ ) {
struct V_216 * V_194 = & V_113 -> V_217 [ V_197 ] ;
T_6 * V_211 = F_65 ( V_113 , V_197 ) ;
struct V_8 * V_9 ;
struct V_206 * V_207 ;
V_198 = 0 ;
if ( F_66 ( & V_194 -> V_218 ) &&
F_66 ( & V_194 -> V_219 ) )
continue;
if ( V_197 > V_199 )
V_200 = 0 ;
F_62 ( V_211 ) ;
F_63 (sk, node, &head->chain) {
struct V_18 * V_19 = F_8 ( V_9 ) ;
if ( V_198 < V_200 )
goto V_220;
if ( ! ( V_23 -> V_201 & ( 1 << V_9 -> V_30 ) ) )
goto V_220;
if ( V_23 -> V_44 . V_48 != V_19 -> V_49 &&
V_23 -> V_44 . V_48 )
goto V_220;
if ( V_23 -> V_44 . V_50 != V_19 -> V_51 &&
V_23 -> V_44 . V_50 )
goto V_220;
if ( F_47 ( V_9 , V_11 , V_167 ) < 0 ) {
F_64 ( V_211 ) ;
goto V_214;
}
V_220:
++ V_198 ;
}
if ( V_23 -> V_201 & V_221 ) {
struct V_87 * V_88 ;
F_67 (tw, node,
&head->twchain) {
if ( V_198 < V_200 )
goto V_222;
if ( V_23 -> V_44 . V_48 != V_88 -> V_95 &&
V_23 -> V_44 . V_48 )
goto V_222;
if ( V_23 -> V_44 . V_50 != V_88 -> V_96 &&
V_23 -> V_44 . V_50 )
goto V_222;
if ( F_53 ( V_88 , V_11 , V_167 ) < 0 ) {
F_64 ( V_211 ) ;
goto V_214;
}
V_222:
++ V_198 ;
}
}
F_64 ( V_211 ) ;
}
V_214:
V_167 -> args [ 1 ] = V_197 ;
V_167 -> args [ 2 ] = V_198 ;
V_114:
F_5 ( V_7 ) ;
return V_11 -> V_37 ;
}
static int F_68 ( struct V_10 * V_11 , struct V_16 * V_24 )
{
int V_223 = sizeof( struct V_109 ) ;
if ( V_24 -> V_29 >= V_224 ||
V_83 ( V_24 ) < V_223 )
return - V_116 ;
if ( V_24 -> V_15 & V_225 ) {
if ( F_48 ( V_24 , V_223 ) ) {
struct V_168 * V_226 ;
V_226 = F_49 ( V_24 , V_223 ,
V_169 ) ;
if ( V_226 == NULL ||
F_52 ( V_226 ) < sizeof( struct V_139 ) ||
F_46 ( F_51 ( V_226 ) , F_52 ( V_226 ) ) )
return - V_116 ;
}
return F_69 ( V_126 , V_11 , V_24 ,
F_61 , NULL , 0 ) ;
}
return F_29 ( V_11 , V_24 ) ;
}
static void F_70 ( struct V_10 * V_11 )
{
F_3 ( & V_227 ) ;
F_71 ( V_11 , & F_68 ) ;
F_6 ( & V_227 ) ;
}
int F_72 ( const struct V_1 * V_228 )
{
const T_7 type = V_228 -> V_229 ;
int V_108 = - V_116 ;
if ( type >= V_224 )
goto V_121;
F_3 ( & V_5 ) ;
V_108 = - V_230 ;
if ( V_2 [ type ] == NULL ) {
V_2 [ type ] = V_228 ;
V_108 = 0 ;
}
F_6 ( & V_5 ) ;
V_121:
return V_108 ;
}
void F_73 ( const struct V_1 * V_228 )
{
const T_7 type = V_228 -> V_229 ;
if ( type >= V_224 )
return;
F_3 ( & V_5 ) ;
V_2 [ type ] = NULL ;
F_6 ( & V_5 ) ;
}
static int T_8 F_74 ( void )
{
const int V_231 = ( V_224 *
sizeof( struct V_1 * ) ) ;
int V_108 = - V_122 ;
V_2 = F_75 ( V_231 , V_123 ) ;
if ( ! V_2 )
goto V_121;
V_126 = F_76 ( & V_118 , V_4 , 0 ,
F_70 , NULL , V_232 ) ;
if ( V_126 == NULL )
goto V_233;
V_108 = 0 ;
V_121:
return V_108 ;
V_233:
F_77 ( V_2 ) ;
goto V_121;
}
static void T_9 F_78 ( void )
{
F_79 ( V_126 ) ;
F_77 ( V_2 ) ;
}
