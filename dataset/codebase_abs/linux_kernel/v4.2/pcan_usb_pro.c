static T_1 * F_1 ( struct V_1 * V_2 , void * V_3 ,
int V_4 )
{
if ( V_4 < V_5 )
return NULL ;
V_2 -> V_6 . V_7 = ( T_1 * ) V_3 ;
V_2 -> V_8 = V_2 -> V_9 = V_4 ;
V_2 -> V_10 = V_2 -> V_6 . V_7 + V_5 ;
return V_2 -> V_10 ;
}
static T_1 * F_2 ( struct V_1 * V_2 ,
void * V_3 , int V_4 )
{
T_1 * V_11 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_11 ) {
V_2 -> V_9 = V_5 ;
* V_2 -> V_6 . V_12 = 0 ;
}
return V_11 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_13 , ... )
{
int V_14 , V_15 ;
T_1 * V_16 ;
T_2 V_17 ;
va_start ( V_17 , V_13 ) ;
V_16 = V_2 -> V_10 + 1 ;
V_15 = 0 ;
switch ( V_13 ) {
case V_18 :
V_15 += 4 ;
case V_19 :
V_15 += 4 ;
case V_20 :
* V_16 ++ = va_arg ( V_17 , int ) ;
* V_16 ++ = va_arg ( V_17 , int ) ;
* V_16 ++ = va_arg ( V_17 , int ) ;
* ( V_21 * ) V_16 = F_4 ( va_arg ( V_17 , V_22 ) ) ;
V_16 += 4 ;
memcpy ( V_16 , va_arg ( V_17 , int * ) , V_15 ) ;
V_16 += V_15 ;
break;
case V_23 :
case V_24 :
* V_16 ++ = va_arg ( V_17 , int ) ;
V_16 += 2 ;
* ( V_21 * ) V_16 = F_4 ( va_arg ( V_17 , V_22 ) ) ;
V_16 += 4 ;
break;
case V_25 :
case V_26 :
case V_27 :
* V_16 ++ = va_arg ( V_17 , int ) ;
* ( V_28 * ) V_16 = F_5 ( va_arg ( V_17 , int ) ) ;
V_16 += 2 ;
break;
case V_29 :
* V_16 ++ = va_arg ( V_17 , int ) ;
* ( V_28 * ) V_16 = F_5 ( va_arg ( V_17 , int ) ) ;
V_16 += 2 ;
* ( V_21 * ) V_16 = F_4 ( va_arg ( V_17 , V_22 ) ) ;
V_16 += 4 ;
break;
case V_30 :
V_16 ++ ;
* ( V_28 * ) V_16 = F_5 ( va_arg ( V_17 , int ) ) ;
V_16 += 2 ;
break;
default:
F_6 ( L_1 ,
V_31 , V_32 , V_13 , V_13 ) ;
V_16 -- ;
break;
}
V_14 = V_16 - V_2 -> V_10 ;
if ( V_14 > 0 ) {
* V_2 -> V_6 . V_12 = F_4 ( F_7 ( * V_2 -> V_6 . V_12 ) + 1 ) ;
* V_2 -> V_10 = V_13 ;
V_2 -> V_10 = V_16 ;
V_2 -> V_9 += V_14 ;
}
va_end ( V_17 ) ;
return V_14 ;
}
static int F_8 ( struct V_33 * V_34 ,
struct V_1 * V_35 )
{
int V_36 ;
int V_37 ;
if ( ! ( V_34 -> V_38 & V_39 ) )
return 0 ;
V_37 = F_9 ( V_34 -> V_40 ,
F_10 ( V_34 -> V_40 , V_41 ) ,
V_35 -> V_6 . V_7 , V_35 -> V_9 ,
& V_36 , V_42 ) ;
if ( V_37 )
F_11 ( V_34 -> V_43 , L_2 , V_37 ) ;
return V_37 ;
}
static int F_12 ( struct V_33 * V_34 ,
struct V_1 * V_35 )
{
T_1 V_44 , V_45 ;
int V_36 ;
int V_15 , V_37 = 0 ;
if ( ! ( V_34 -> V_38 & V_39 ) )
return 0 ;
V_44 = V_35 -> V_6 . V_7 [ 4 ] ;
V_45 = V_35 -> V_6 . V_7 [ 5 ] ;
* V_35 -> V_6 . V_12 = 0 ;
for ( V_15 = 0 ; ! V_37 && V_15 < V_46 ; V_15 ++ ) {
struct V_1 V_47 ;
union V_48 * V_11 ;
V_22 V_49 , V_12 ;
T_3 V_50 ;
T_1 * V_16 ;
V_37 = F_9 ( V_34 -> V_40 ,
F_13 ( V_34 -> V_40 , V_51 ) ,
V_35 -> V_6 . V_7 , V_35 -> V_9 ,
& V_36 , V_42 ) ;
if ( V_37 ) {
F_11 ( V_34 -> V_43 , L_3 , V_37 ) ;
break;
}
if ( V_36 == 0 )
continue;
V_37 = - V_52 ;
if ( V_36 < V_5 ) {
F_11 ( V_34 -> V_43 ,
L_4 ,
V_36 ) ;
break;
}
V_16 = F_1 ( & V_47 , V_35 -> V_6 . V_7 ,
V_36 ) ;
V_12 = F_7 ( * V_47 . V_6 . V_12 ) ;
for ( V_49 = 0 ; V_49 < V_12 ; V_49 ++ ) {
V_11 = (union V_48 * ) V_16 ;
V_50 = V_53 [ V_11 -> V_54 ] ;
if ( ! V_50 ) {
F_11 ( V_34 -> V_43 ,
L_5 ) ;
F_14 ( L_6 , V_35 -> V_6 . V_7 ,
V_36 ) ;
break;
}
if ( V_11 -> V_54 != V_44 )
F_11 ( V_34 -> V_43 ,
L_7 ,
V_11 -> V_54 ) ;
else if ( ( V_45 != 0xff ) && \
( V_11 -> V_55 . V_56 != V_45 ) )
F_11 ( V_34 -> V_43 ,
L_8 ,
V_44 , V_11 -> V_55 . V_56 ) ;
else
return 0 ;
V_16 += V_50 ;
}
}
return ( V_15 >= V_46 ) ? - V_57 : V_37 ;
}
int F_15 ( struct V_33 * V_34 , int V_58 ,
int V_59 , void * V_60 , int V_61 )
{
int V_37 ;
T_1 V_62 ;
unsigned int V_63 ;
if ( ! ( V_34 -> V_38 & V_39 ) )
return 0 ;
V_62 = V_64 | V_65 ;
switch ( V_58 ) {
case V_66 :
V_63 = F_16 ( V_34 -> V_40 , 0 ) ;
break;
default:
V_63 = F_17 ( V_34 -> V_40 , 0 ) ;
V_62 |= V_67 ;
memset ( V_60 , '\0' , V_61 ) ;
break;
}
V_37 = F_18 ( V_34 -> V_40 , V_63 , V_58 , V_62 , V_59 , 0 ,
V_60 , V_61 , 2 * V_68 ) ;
if ( V_37 < 0 ) {
F_19 ( V_34 -> V_43 ,
L_9 ,
V_58 , V_59 , V_37 ) ;
return V_37 ;
}
return 0 ;
}
static int F_20 ( struct V_33 * V_34 , T_3 V_69 )
{
struct V_1 V_70 ;
F_2 ( & V_70 , V_34 -> V_71 , V_72 ) ;
F_3 ( & V_70 , V_30 , V_69 ) ;
return F_8 ( V_34 , & V_70 ) ;
}
static int F_21 ( struct V_33 * V_34 , V_22 V_73 )
{
struct V_74 * V_75 =
F_22 ( V_34 , struct V_74 , V_34 ) ;
struct V_1 V_70 ;
F_2 ( & V_70 , V_34 -> V_71 , V_72 ) ;
F_3 ( & V_70 , V_23 , V_34 -> V_76 , V_73 ) ;
V_75 -> V_77 = V_73 ;
return F_8 ( V_34 , & V_70 ) ;
}
static int F_23 ( struct V_33 * V_34 , T_1 V_69 )
{
struct V_1 V_70 ;
if ( V_69 ) {
struct V_74 * V_75 =
F_22 ( V_34 , struct V_74 , V_34 ) ;
F_21 ( V_34 , V_75 -> V_77 ) ;
}
F_2 ( & V_70 , V_34 -> V_71 , V_72 ) ;
F_3 ( & V_70 , V_26 , V_34 -> V_76 , V_69 ) ;
return F_8 ( V_34 , & V_70 ) ;
}
static int F_24 ( struct V_33 * V_34 , T_1 V_69 )
{
struct V_1 V_70 ;
F_2 ( & V_70 , V_34 -> V_71 , V_72 ) ;
F_3 ( & V_70 , V_27 , V_34 -> V_76 , V_69 ) ;
return F_8 ( V_34 , & V_70 ) ;
}
static int F_25 ( struct V_33 * V_34 , T_3 V_78 )
{
struct V_1 V_70 ;
F_2 ( & V_70 , V_34 -> V_71 , V_72 ) ;
F_3 ( & V_70 , V_25 , V_34 -> V_76 , V_78 ) ;
return F_8 ( V_34 , & V_70 ) ;
}
static int F_26 ( struct V_33 * V_34 , T_1 V_79 ,
V_22 V_80 )
{
struct V_1 V_70 ;
F_2 ( & V_70 , V_34 -> V_71 , V_72 ) ;
F_3 ( & V_70 , V_29 , V_34 -> V_76 , V_79 , V_80 ) ;
return F_8 ( V_34 , & V_70 ) ;
}
static int F_27 ( struct V_33 * V_34 ,
V_22 * V_81 )
{
struct V_82 * V_83 ;
struct V_1 V_70 ;
int V_37 ;
T_1 * V_16 ;
V_16 = F_2 ( & V_70 , V_34 -> V_71 , V_72 ) ;
F_3 ( & V_70 , V_24 , V_34 -> V_76 ) ;
V_37 = F_8 ( V_34 , & V_70 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_12 ( V_34 , & V_70 ) ;
if ( V_37 )
return V_37 ;
V_83 = (struct V_82 * ) V_16 ;
if ( V_81 )
* V_81 = F_7 ( V_83 -> V_84 ) ;
return V_37 ;
}
static int F_28 ( struct V_33 * V_34 ,
struct V_85 * V_86 )
{
V_22 V_73 ;
V_73 = ( V_34 -> V_87 . V_88 & V_89 ) ? 0x00800000 : 0 ;
V_73 |= ( V_86 -> V_90 - 1 ) << 24 ;
V_73 |= ( V_86 -> V_91 - 1 ) << 20 ;
V_73 |= ( V_86 -> V_92 + V_86 -> V_93 - 1 ) << 16 ;
V_73 |= V_86 -> V_94 - 1 ;
F_19 ( V_34 -> V_43 , L_10 , V_73 ) ;
return F_21 ( V_34 , V_73 ) ;
}
void F_29 ( struct V_95 * V_95 )
{
F_30 ( V_95 ) ;
F_31 ( V_95 -> V_96 ) ;
}
static int F_32 ( struct V_33 * V_34 ,
struct V_95 * V_95 , T_1 * V_97 )
{
struct V_1 V_70 ;
F_2 ( & V_70 , V_97 , V_72 ) ;
F_3 ( & V_70 , V_26 , V_34 -> V_76 , 1 ) ;
F_33 ( V_95 , V_34 -> V_40 ,
F_10 ( V_34 -> V_40 , V_41 ) ,
V_97 , V_72 ,
F_29 , V_34 ) ;
return F_34 ( V_95 , V_98 ) ;
}
static int F_35 ( struct V_33 * V_34 , int V_99 )
{
T_1 * V_100 ;
int V_37 ;
V_100 = F_36 ( V_101 , V_102 ) ;
if ( ! V_100 )
return - V_103 ;
V_100 [ 0 ] = 0 ;
V_100 [ 1 ] = ! ! V_99 ;
V_37 = F_15 ( V_34 , V_66 ,
V_104 , V_100 ,
V_101 ) ;
F_37 ( V_100 ) ;
return V_37 ;
}
static inline
struct V_105 * F_38 ( struct V_33 * V_34 )
{
struct V_74 * V_75 =
F_22 ( V_34 , struct V_74 , V_34 ) ;
return V_75 -> V_106 ;
}
static int F_39 ( struct V_105 * V_106 ,
struct V_107 * V_108 )
{
const unsigned int V_76 = ( V_108 -> V_14 >> 4 ) & 0x0f ;
struct V_33 * V_34 = V_106 -> V_34 [ V_76 ] ;
struct V_109 * V_43 = V_34 -> V_43 ;
struct V_110 * V_110 ;
struct V_111 * V_112 ;
struct V_113 V_114 ;
struct V_115 * V_116 ;
V_112 = F_40 ( V_43 , & V_110 ) ;
if ( ! V_112 )
return - V_103 ;
V_110 -> V_117 = F_7 ( V_108 -> V_13 ) ;
V_110 -> V_118 = V_108 -> V_14 & 0x0f ;
if ( V_108 -> V_119 & V_120 )
V_110 -> V_117 |= V_121 ;
if ( V_108 -> V_119 & V_122 )
V_110 -> V_117 |= V_123 ;
else
memcpy ( V_110 -> V_124 , V_108 -> V_124 , V_110 -> V_118 ) ;
F_41 ( & V_106 -> V_125 , F_7 ( V_108 -> V_126 ) , & V_114 ) ;
V_116 = F_42 ( V_112 ) ;
V_116 -> V_127 = F_43 ( V_114 ) ;
V_43 -> V_128 . V_129 ++ ;
V_43 -> V_128 . V_130 += V_110 -> V_118 ;
F_44 ( V_112 ) ;
return 0 ;
}
static int F_45 ( struct V_105 * V_106 ,
struct V_131 * V_132 )
{
const T_3 V_133 = F_46 ( V_132 -> V_134 ) ;
const unsigned int V_76 = ( V_132 -> V_56 >> 4 ) & 0x0f ;
struct V_33 * V_34 = V_106 -> V_34 [ V_76 ] ;
struct V_109 * V_43 = V_34 -> V_43 ;
struct V_110 * V_110 ;
enum V_135 V_136 = V_137 ;
T_1 V_138 = 0 ;
struct V_111 * V_112 ;
struct V_113 V_114 ;
struct V_115 * V_116 ;
if ( V_34 -> V_87 . V_38 == V_139 )
return 0 ;
if ( ! V_133 ) {
V_34 -> V_87 . V_38 = V_137 ;
return 0 ;
}
if ( V_133 & ( V_140 |
V_141 ) ) {
V_136 = V_142 ;
}
if ( V_133 & V_143 ) {
V_136 = V_139 ;
} else if ( V_133 & V_144 ) {
V_22 V_145 = ( F_7 ( V_132 -> V_146 ) & 0x00ff0000 ) >> 16 ;
V_22 V_147 = ( F_7 ( V_132 -> V_146 ) & 0xff000000 ) >> 24 ;
if ( V_145 > 127 )
V_138 |= V_148 ;
else if ( V_145 > 96 )
V_138 |= V_149 ;
if ( V_147 > 127 )
V_138 |= V_150 ;
else if ( V_147 > 96 )
V_138 |= V_151 ;
if ( V_138 & ( V_149 |
V_151 ) )
V_136 = V_152 ;
else if ( V_138 & ( V_148 |
V_150 ) )
V_136 = V_153 ;
}
if ( V_34 -> V_87 . V_38 == V_136 )
return 0 ;
V_112 = F_47 ( V_43 , & V_110 ) ;
if ( ! V_112 )
return - V_103 ;
switch ( V_136 ) {
case V_139 :
V_110 -> V_117 |= V_154 ;
V_34 -> V_87 . V_155 . V_156 ++ ;
F_48 ( V_43 ) ;
break;
case V_153 :
V_110 -> V_117 |= V_157 ;
V_110 -> V_124 [ 1 ] |= V_138 ;
V_34 -> V_87 . V_155 . V_158 ++ ;
break;
case V_152 :
V_110 -> V_117 |= V_157 ;
V_110 -> V_124 [ 1 ] |= V_138 ;
V_34 -> V_87 . V_155 . V_159 ++ ;
break;
case V_137 :
break;
default:
if ( V_133 & V_140 ) {
V_110 -> V_117 |= V_160 ;
V_110 -> V_124 [ 2 ] |= V_161 ;
V_43 -> V_128 . V_162 ++ ;
V_43 -> V_128 . V_163 ++ ;
}
if ( V_133 & V_141 ) {
V_110 -> V_117 |= V_157 ;
V_110 -> V_124 [ 1 ] |= V_164 ;
V_43 -> V_128 . V_162 ++ ;
V_43 -> V_128 . V_163 ++ ;
}
V_136 = V_137 ;
break;
}
V_34 -> V_87 . V_38 = V_136 ;
F_41 ( & V_106 -> V_125 , F_7 ( V_132 -> V_126 ) , & V_114 ) ;
V_116 = F_42 ( V_112 ) ;
V_116 -> V_127 = F_43 ( V_114 ) ;
V_43 -> V_128 . V_129 ++ ;
V_43 -> V_128 . V_130 += V_110 -> V_118 ;
F_44 ( V_112 ) ;
return 0 ;
}
static void F_49 ( struct V_105 * V_106 ,
struct V_165 * V_166 )
{
if ( V_106 -> V_167 > 0 )
V_106 -> V_167 -- ;
else
F_50 ( & V_106 -> V_125 ,
F_7 ( V_166 -> V_168 [ 1 ] ) ) ;
}
static int F_51 ( struct V_33 * V_34 , struct V_95 * V_95 )
{
struct V_105 * V_106 = F_38 ( V_34 ) ;
struct V_109 * V_43 = V_34 -> V_43 ;
struct V_1 V_169 ;
T_1 * V_10 , * V_170 ;
T_3 V_12 ;
int V_37 = 0 ;
V_10 = F_1 ( & V_169 , V_95 -> V_171 ,
V_95 -> V_36 ) ;
if ( ! V_10 ) {
F_11 ( V_43 , L_11 , V_95 -> V_36 ) ;
return - V_172 ;
}
V_170 = V_95 -> V_171 + V_95 -> V_36 ;
V_12 = F_46 ( * V_169 . V_6 . V_173 ) ;
for (; V_12 > 0 ; V_12 -- ) {
union V_48 * V_11 = (union V_48 * ) V_10 ;
T_3 V_174 = V_53 [ V_11 -> V_54 ] ;
if ( ! V_174 ) {
F_11 ( V_43 ,
L_12 ) ;
V_37 = - V_175 ;
break;
}
if ( V_10 + V_174 > V_170 ) {
F_11 ( V_43 ,
L_13 ) ;
V_37 = - V_52 ;
break;
}
switch ( V_11 -> V_54 ) {
case V_176 :
case V_177 :
case V_178 :
case V_179 :
V_37 = F_39 ( V_106 , & V_11 -> V_180 ) ;
if ( V_37 < 0 )
goto V_181;
break;
case V_182 :
V_37 = F_45 ( V_106 , & V_11 -> V_183 ) ;
if ( V_37 < 0 )
goto V_181;
break;
case V_184 :
F_49 ( V_106 , & V_11 -> V_185 ) ;
break;
default:
F_11 ( V_43 ,
L_14 ,
V_11 -> V_54 , V_11 -> V_54 ) ;
break;
}
V_10 += V_174 ;
}
V_181:
if ( V_37 )
F_14 ( L_15 ,
V_95 -> V_171 , V_95 -> V_36 ) ;
return V_37 ;
}
static int F_52 ( struct V_33 * V_34 ,
struct V_111 * V_112 , T_1 * V_186 , T_4 * V_187 )
{
struct V_110 * V_188 = (struct V_110 * ) V_112 -> V_124 ;
T_1 V_54 , V_14 , V_119 ;
struct V_1 V_169 ;
F_2 ( & V_169 , V_186 , * V_187 ) ;
if ( ( V_188 -> V_117 & V_123 ) || ( V_188 -> V_118 == 0 ) )
V_54 = V_20 ;
else if ( V_188 -> V_118 <= 4 )
V_54 = V_19 ;
else
V_54 = V_18 ;
V_14 = ( V_34 -> V_76 << 4 ) | ( V_188 -> V_118 & 0x0f ) ;
V_119 = 0 ;
if ( V_188 -> V_117 & V_121 )
V_119 |= 0x02 ;
if ( V_188 -> V_117 & V_123 )
V_119 |= 0x01 ;
F_3 ( & V_169 , V_54 , 0 , V_119 , V_14 , V_188 -> V_117 ,
V_188 -> V_124 ) ;
* V_187 = V_169 . V_9 ;
return 0 ;
}
static int F_53 ( struct V_33 * V_34 )
{
struct V_74 * V_75 =
F_22 ( V_34 , struct V_74 , V_34 ) ;
int V_37 ;
V_37 = F_24 ( V_34 ,
V_34 -> V_87 . V_88 & V_189 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_25 ( V_34 , 1 ) ;
if ( V_37 )
return V_37 ;
if ( V_75 -> V_106 -> V_190 == 0 ) {
F_54 ( & V_75 -> V_106 -> V_125 , & V_191 ) ;
V_37 = F_20 ( V_34 , 1 ) ;
}
V_75 -> V_106 -> V_190 ++ ;
return V_37 ;
}
static int F_55 ( struct V_33 * V_34 )
{
struct V_74 * V_75 =
F_22 ( V_34 , struct V_74 , V_34 ) ;
if ( V_75 -> V_106 -> V_190 == 1 )
F_20 ( V_34 , 0 ) ;
V_75 -> V_106 -> V_190 -- ;
return 0 ;
}
static int F_56 ( struct V_33 * V_34 )
{
struct V_74 * V_75 =
F_22 ( V_34 , struct V_74 , V_34 ) ;
struct V_105 * V_106 = NULL ;
struct V_192 * V_193 = NULL ;
struct V_194 * V_195 = NULL ;
int V_37 ;
if ( ! V_34 -> V_196 ) {
V_106 = F_57 ( sizeof( struct V_105 ) ,
V_102 ) ;
V_193 = F_36 ( sizeof( struct V_192 ) , V_102 ) ;
V_195 = F_36 ( sizeof( struct V_194 ) , V_102 ) ;
if ( ! V_106 || ! V_193 || ! V_195 ) {
V_37 = - V_103 ;
goto V_197;
}
V_106 -> V_167 = 5 ;
V_37 = F_15 ( V_34 , V_198 ,
V_199 ,
V_193 , sizeof( * V_193 ) ) ;
if ( V_37 ) {
F_58 ( V_34 -> V_43 -> V_34 . V_200 ,
L_16 ,
V_191 . V_201 , V_37 ) ;
goto V_197;
}
V_37 = F_15 ( V_34 , V_198 ,
V_202 ,
V_195 , sizeof( * V_195 ) ) ;
if ( V_37 ) {
F_58 ( V_34 -> V_43 -> V_34 . V_200 ,
L_17 ,
V_191 . V_201 , V_37 ) ;
goto V_197;
}
V_37 = F_35 ( V_34 , 1 ) ;
if ( V_37 )
goto V_197;
F_59 ( V_34 -> V_43 -> V_34 . V_200 ,
L_18 ,
V_191 . V_201 ,
V_195 -> V_203 , V_195 -> V_204 , V_195 -> V_205 ,
V_191 . V_206 ) ;
} else {
V_106 = F_38 ( V_34 -> V_196 ) ;
}
V_75 -> V_106 = V_106 ;
V_106 -> V_34 [ V_34 -> V_76 ] = V_34 ;
F_26 ( V_34 , 0 , 1 ) ;
F_37 ( V_195 ) ;
F_37 ( V_193 ) ;
return 0 ;
V_197:
F_37 ( V_195 ) ;
F_37 ( V_193 ) ;
F_37 ( V_106 ) ;
return V_37 ;
}
static void F_60 ( struct V_33 * V_34 )
{
struct V_74 * V_75 =
F_22 ( V_34 , struct V_74 , V_34 ) ;
if ( V_34 -> V_87 . V_38 != V_207 ) {
F_23 ( V_34 , 0 ) ;
}
if ( V_34 -> V_76 == 0 ) {
if ( V_75 -> V_106 -> V_190 > 0 )
F_20 ( V_34 , 0 ) ;
F_35 ( V_34 , 0 ) ;
}
}
static void F_61 ( struct V_33 * V_34 )
{
if ( ! V_34 -> V_196 && ! V_34 -> V_208 )
F_37 ( F_38 ( V_34 ) ) ;
}
int F_62 ( struct V_209 * V_210 )
{
struct V_211 * V_212 ;
int V_15 ;
V_212 = V_210 -> V_213 ;
for ( V_15 = 0 ; V_15 < V_212 -> V_214 . V_215 ; V_15 ++ ) {
struct V_216 * V_217 = & V_212 -> V_218 [ V_15 ] . V_214 ;
switch ( V_217 -> V_219 ) {
case V_41 :
case V_51 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
break;
default:
return - V_224 ;
}
}
return 0 ;
}
