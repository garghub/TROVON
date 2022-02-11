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
* ( V_21 * ) V_16 = F_4 ( va_arg ( V_17 , V_21 ) ) ;
V_16 += 4 ;
memcpy ( V_16 , va_arg ( V_17 , int * ) , V_15 ) ;
V_16 += V_15 ;
break;
case V_22 :
case V_23 :
* V_16 ++ = va_arg ( V_17 , int ) ;
V_16 += 2 ;
* ( V_21 * ) V_16 = F_4 ( va_arg ( V_17 , V_21 ) ) ;
V_16 += 4 ;
break;
case V_24 :
case V_25 :
case V_26 :
* V_16 ++ = va_arg ( V_17 , int ) ;
* ( V_27 * ) V_16 = F_5 ( va_arg ( V_17 , int ) ) ;
V_16 += 2 ;
break;
case V_28 :
* V_16 ++ = va_arg ( V_17 , int ) ;
* ( V_27 * ) V_16 = F_5 ( va_arg ( V_17 , int ) ) ;
V_16 += 2 ;
* ( V_21 * ) V_16 = F_4 ( va_arg ( V_17 , V_21 ) ) ;
V_16 += 4 ;
break;
case V_29 :
V_16 ++ ;
* ( V_27 * ) V_16 = F_5 ( va_arg ( V_17 , int ) ) ;
V_16 += 2 ;
break;
default:
F_6 ( L_1 ,
V_30 , V_31 , V_13 , V_13 ) ;
V_16 -- ;
break;
}
V_14 = V_16 - V_2 -> V_10 ;
if ( V_14 > 0 ) {
* V_2 -> V_6 . V_12 = F_4 ( * V_2 -> V_6 . V_12 + 1 ) ;
* V_2 -> V_10 = V_13 ;
V_2 -> V_10 = V_16 ;
V_2 -> V_9 += V_14 ;
}
va_end ( V_17 ) ;
return V_14 ;
}
static int F_7 ( struct V_32 * V_33 ,
struct V_1 * V_34 )
{
int V_35 ;
int V_36 ;
if ( ! ( V_33 -> V_37 & V_38 ) )
return 0 ;
V_36 = F_8 ( V_33 -> V_39 ,
F_9 ( V_33 -> V_39 , V_40 ) ,
V_34 -> V_6 . V_7 , V_34 -> V_9 ,
& V_35 , V_41 ) ;
if ( V_36 )
F_10 ( V_33 -> V_42 , L_2 , V_36 ) ;
return V_36 ;
}
static int F_11 ( struct V_32 * V_33 ,
struct V_1 * V_34 )
{
T_1 V_43 , V_44 ;
int V_35 ;
int V_15 , V_36 = 0 ;
if ( ! ( V_33 -> V_37 & V_38 ) )
return 0 ;
V_43 = V_34 -> V_6 . V_7 [ 4 ] ;
V_44 = V_34 -> V_6 . V_7 [ 5 ] ;
* V_34 -> V_6 . V_12 = 0 ;
for ( V_15 = 0 ; ! V_36 && V_15 < V_45 ; V_15 ++ ) {
struct V_1 V_46 ;
union V_47 * V_11 ;
V_21 V_48 , V_12 ;
V_27 V_49 ;
T_1 * V_16 ;
V_36 = F_8 ( V_33 -> V_39 ,
F_12 ( V_33 -> V_39 , V_50 ) ,
V_34 -> V_6 . V_7 , V_34 -> V_9 ,
& V_35 , V_41 ) ;
if ( V_36 ) {
F_10 ( V_33 -> V_42 , L_3 , V_36 ) ;
break;
}
if ( V_35 == 0 )
continue;
V_36 = - V_51 ;
if ( V_35 < V_5 ) {
F_10 ( V_33 -> V_42 ,
L_4 ,
V_35 ) ;
break;
}
V_16 = F_1 ( & V_46 , V_34 -> V_6 . V_7 ,
V_35 ) ;
V_12 = F_13 ( * V_46 . V_6 . V_12 ) ;
for ( V_48 = 0 ; V_48 < V_12 ; V_48 ++ ) {
V_11 = (union V_47 * ) V_16 ;
V_49 = V_52 [ V_11 -> V_53 ] ;
if ( ! V_49 ) {
F_10 ( V_33 -> V_42 ,
L_5 ) ;
F_14 ( L_6 , V_34 -> V_6 . V_7 ,
V_35 ) ;
break;
}
if ( V_11 -> V_53 != V_43 )
F_10 ( V_33 -> V_42 ,
L_7 ,
V_11 -> V_53 ) ;
else if ( ( V_44 != 0xff ) && \
( V_11 -> V_54 . V_55 != V_44 ) )
F_10 ( V_33 -> V_42 ,
L_8 ,
V_43 , V_11 -> V_54 . V_55 ) ;
else
return 0 ;
V_16 += V_49 ;
}
}
return ( V_15 >= V_45 ) ? - V_56 : V_36 ;
}
static int F_15 ( struct V_32 * V_33 , int V_57 ,
int V_58 , void * V_59 , int V_60 )
{
int V_36 ;
T_1 V_61 ;
unsigned int V_62 ;
if ( ! ( V_33 -> V_37 & V_38 ) )
return 0 ;
memset ( V_59 , '\0' , V_60 ) ;
V_61 = V_63 | V_64 ;
switch ( V_57 ) {
case V_65 :
V_62 = F_16 ( V_33 -> V_39 , 0 ) ;
break;
default:
V_62 = F_17 ( V_33 -> V_39 , 0 ) ;
V_61 |= V_66 ;
break;
}
V_36 = F_18 ( V_33 -> V_39 , V_62 , V_57 , V_61 , V_58 , 0 ,
V_59 , V_60 , 2 * V_67 ) ;
if ( V_36 < 0 ) {
F_19 ( V_33 -> V_42 ,
L_9 ,
V_57 , V_58 , V_36 ) ;
return V_36 ;
}
return 0 ;
}
static int F_20 ( struct V_32 * V_33 , V_27 V_68 )
{
struct V_1 V_69 ;
F_2 ( & V_69 , V_33 -> V_70 , V_71 ) ;
F_3 ( & V_69 , V_29 , V_68 ) ;
return F_7 ( V_33 , & V_69 ) ;
}
static int F_21 ( struct V_32 * V_33 , V_21 V_72 )
{
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
struct V_1 V_69 ;
F_2 ( & V_69 , V_33 -> V_70 , V_71 ) ;
F_3 ( & V_69 , V_22 , V_33 -> V_75 , V_72 ) ;
V_74 -> V_76 = V_72 ;
return F_7 ( V_33 , & V_69 ) ;
}
static int F_23 ( struct V_32 * V_33 , T_1 V_68 )
{
struct V_1 V_69 ;
if ( V_68 ) {
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
F_21 ( V_33 , V_74 -> V_76 ) ;
}
F_2 ( & V_69 , V_33 -> V_70 , V_71 ) ;
F_3 ( & V_69 , V_25 , V_33 -> V_75 , V_68 ) ;
return F_7 ( V_33 , & V_69 ) ;
}
static int F_24 ( struct V_32 * V_33 , T_1 V_68 )
{
struct V_1 V_69 ;
F_2 ( & V_69 , V_33 -> V_70 , V_71 ) ;
F_3 ( & V_69 , V_26 , V_33 -> V_75 , V_68 ) ;
return F_7 ( V_33 , & V_69 ) ;
}
static int F_25 ( struct V_32 * V_33 , V_27 V_77 )
{
struct V_1 V_69 ;
F_2 ( & V_69 , V_33 -> V_70 , V_71 ) ;
F_3 ( & V_69 , V_24 , V_33 -> V_75 , V_77 ) ;
return F_7 ( V_33 , & V_69 ) ;
}
static int F_26 ( struct V_32 * V_33 , T_1 V_78 ,
V_21 V_79 )
{
struct V_1 V_69 ;
F_2 ( & V_69 , V_33 -> V_70 , V_71 ) ;
F_3 ( & V_69 , V_28 , V_33 -> V_75 , V_78 , V_79 ) ;
return F_7 ( V_33 , & V_69 ) ;
}
static int F_27 ( struct V_32 * V_33 ,
V_21 * V_80 )
{
struct V_81 * V_82 ;
struct V_1 V_69 ;
int V_36 ;
T_1 * V_16 ;
V_16 = F_2 ( & V_69 , V_33 -> V_70 , V_71 ) ;
F_3 ( & V_69 , V_23 , V_33 -> V_75 ) ;
V_36 = F_7 ( V_33 , & V_69 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_11 ( V_33 , & V_69 ) ;
if ( V_36 )
return V_36 ;
V_82 = (struct V_81 * ) V_16 ;
if ( V_80 )
* V_80 = F_13 ( V_82 -> V_83 ) ;
return V_36 ;
}
static int F_28 ( struct V_32 * V_33 ,
struct V_84 * V_85 )
{
V_21 V_72 ;
V_72 = ( V_33 -> V_86 . V_87 & V_88 ) ? 0x00800000 : 0 ;
V_72 |= ( V_85 -> V_89 - 1 ) << 24 ;
V_72 |= ( V_85 -> V_90 - 1 ) << 20 ;
V_72 |= ( V_85 -> V_91 + V_85 -> V_92 - 1 ) << 16 ;
V_72 |= V_85 -> V_93 - 1 ;
F_19 ( V_33 -> V_42 , L_10 , V_72 ) ;
return F_21 ( V_33 , V_72 ) ;
}
static void F_29 ( struct V_94 * V_94 )
{
F_30 ( V_94 ) ;
F_31 ( V_94 -> V_95 ) ;
}
static int F_32 ( struct V_32 * V_33 ,
struct V_94 * V_94 , T_1 * V_96 )
{
struct V_1 V_69 ;
F_2 ( & V_69 , V_96 , V_71 ) ;
F_3 ( & V_69 , V_25 , V_33 -> V_75 , 1 ) ;
F_33 ( V_94 , V_33 -> V_39 ,
F_9 ( V_33 -> V_39 , V_40 ) ,
V_96 , V_71 ,
F_29 , V_33 ) ;
return F_34 ( V_94 , V_97 ) ;
}
static void F_35 ( struct V_32 * V_33 , int V_98 )
{
T_1 V_99 [ 16 ] ;
V_99 [ 0 ] = 0 ;
V_99 [ 1 ] = ! ! V_98 ;
F_15 ( V_33 , V_65 ,
V_100 , V_99 , sizeof( V_99 ) ) ;
}
static inline
struct V_101 * F_36 ( struct V_32 * V_33 )
{
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
return V_74 -> V_102 ;
}
static int F_37 ( struct V_101 * V_102 ,
struct V_103 * V_104 )
{
const unsigned int V_75 = ( V_104 -> V_14 >> 4 ) & 0x0f ;
struct V_32 * V_33 = V_102 -> V_33 [ V_75 ] ;
struct V_105 * V_42 = V_33 -> V_42 ;
struct V_106 * V_106 ;
struct V_107 * V_108 ;
struct V_109 V_110 ;
V_108 = F_38 ( V_42 , & V_106 ) ;
if ( ! V_108 )
return - V_111 ;
V_106 -> V_112 = F_13 ( V_104 -> V_13 ) ;
V_106 -> V_113 = V_104 -> V_14 & 0x0f ;
if ( V_104 -> V_114 & V_115 )
V_106 -> V_112 |= V_116 ;
if ( V_104 -> V_114 & V_117 )
V_106 -> V_112 |= V_118 ;
else
memcpy ( V_106 -> V_119 , V_104 -> V_119 , V_106 -> V_113 ) ;
F_39 ( & V_102 -> V_120 , F_13 ( V_104 -> V_121 ) , & V_110 ) ;
V_108 -> V_122 = F_40 ( V_110 ) ;
F_41 ( V_108 ) ;
V_42 -> V_123 . V_124 ++ ;
V_42 -> V_123 . V_125 += V_106 -> V_113 ;
return 0 ;
}
static int F_42 ( struct V_101 * V_102 ,
struct V_126 * V_127 )
{
const V_21 V_128 = F_13 ( V_127 -> V_129 ) ;
const unsigned int V_75 = ( V_127 -> V_55 >> 4 ) & 0x0f ;
struct V_32 * V_33 = V_102 -> V_33 [ V_75 ] ;
struct V_105 * V_42 = V_33 -> V_42 ;
struct V_106 * V_106 ;
enum V_130 V_131 = V_132 ;
T_1 V_133 = 0 ;
struct V_107 * V_108 ;
struct V_109 V_110 ;
if ( V_33 -> V_86 . V_37 == V_134 )
return 0 ;
if ( ! V_128 ) {
V_33 -> V_86 . V_37 = V_132 ;
return 0 ;
}
if ( V_128 & ( V_135 |
V_136 ) ) {
V_131 = V_137 ;
}
if ( V_128 & V_138 ) {
V_131 = V_134 ;
} else if ( V_128 & V_139 ) {
V_21 V_140 = ( F_13 ( V_127 -> V_141 ) & 0x00ff0000 ) >> 16 ;
V_21 V_142 = ( F_13 ( V_127 -> V_141 ) & 0xff000000 ) >> 24 ;
if ( V_140 > 127 )
V_133 |= V_143 ;
else if ( V_140 > 96 )
V_133 |= V_144 ;
if ( V_142 > 127 )
V_133 |= V_145 ;
else if ( V_142 > 96 )
V_133 |= V_146 ;
if ( V_133 & ( V_144 |
V_146 ) )
V_131 = V_147 ;
else if ( V_133 & ( V_143 |
V_145 ) )
V_131 = V_148 ;
}
if ( V_33 -> V_86 . V_37 == V_131 )
return 0 ;
V_108 = F_43 ( V_42 , & V_106 ) ;
if ( ! V_108 )
return - V_111 ;
switch ( V_131 ) {
case V_134 :
V_106 -> V_112 |= V_149 ;
F_44 ( V_42 ) ;
break;
case V_148 :
V_106 -> V_112 |= V_150 ;
V_106 -> V_119 [ 1 ] |= V_133 ;
V_33 -> V_86 . V_151 . V_152 ++ ;
break;
case V_147 :
V_106 -> V_112 |= V_150 ;
V_106 -> V_119 [ 1 ] |= V_133 ;
V_33 -> V_86 . V_151 . V_153 ++ ;
break;
case V_132 :
break;
default:
if ( V_128 & V_135 ) {
V_106 -> V_112 |= V_154 ;
V_106 -> V_119 [ 2 ] |= V_155 ;
V_42 -> V_123 . V_156 ++ ;
V_42 -> V_123 . V_157 ++ ;
}
if ( V_128 & V_136 ) {
V_106 -> V_112 |= V_150 ;
V_106 -> V_119 [ 1 ] |= V_158 ;
V_42 -> V_123 . V_156 ++ ;
V_42 -> V_123 . V_157 ++ ;
}
V_131 = V_132 ;
break;
}
V_33 -> V_86 . V_37 = V_131 ;
F_39 ( & V_102 -> V_120 , F_13 ( V_127 -> V_121 ) , & V_110 ) ;
V_108 -> V_122 = F_40 ( V_110 ) ;
F_41 ( V_108 ) ;
V_42 -> V_123 . V_124 ++ ;
V_42 -> V_123 . V_125 += V_106 -> V_113 ;
return 0 ;
}
static void F_45 ( struct V_101 * V_102 ,
struct V_159 * V_160 )
{
if ( V_102 -> V_161 > 0 )
V_102 -> V_161 -- ;
else
F_46 ( & V_102 -> V_120 ,
F_13 ( V_160 -> V_162 [ 1 ] ) ) ;
}
static int F_47 ( struct V_32 * V_33 , struct V_94 * V_94 )
{
struct V_101 * V_102 = F_36 ( V_33 ) ;
struct V_105 * V_42 = V_33 -> V_42 ;
struct V_1 V_163 ;
T_1 * V_10 , * V_164 ;
V_27 V_12 ;
int V_36 = 0 ;
V_10 = F_1 ( & V_163 , V_94 -> V_165 ,
V_94 -> V_35 ) ;
if ( ! V_10 ) {
F_10 ( V_42 , L_11 , V_94 -> V_35 ) ;
return - V_166 ;
}
V_164 = V_94 -> V_165 + V_94 -> V_35 ;
V_12 = F_48 ( * V_163 . V_6 . V_167 ) ;
for (; V_12 > 0 ; V_12 -- ) {
union V_47 * V_11 = (union V_47 * ) V_10 ;
V_27 V_168 = V_52 [ V_11 -> V_53 ] ;
if ( ! V_168 ) {
F_10 ( V_42 ,
L_12 ) ;
V_36 = - V_169 ;
break;
}
if ( V_10 + V_168 > V_164 ) {
F_10 ( V_42 ,
L_13 ) ;
V_36 = - V_51 ;
break;
}
switch ( V_11 -> V_53 ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
V_36 = F_37 ( V_102 , & V_11 -> V_174 ) ;
if ( V_36 < 0 )
goto V_175;
break;
case V_176 :
V_36 = F_42 ( V_102 , & V_11 -> V_177 ) ;
if ( V_36 < 0 )
goto V_175;
break;
case V_178 :
F_45 ( V_102 , & V_11 -> V_179 ) ;
break;
default:
F_10 ( V_42 ,
L_14 ,
V_11 -> V_53 , V_11 -> V_53 ) ;
break;
}
V_10 += V_168 ;
}
V_175:
if ( V_36 )
F_14 ( L_15 ,
V_94 -> V_165 , V_94 -> V_35 ) ;
return V_36 ;
}
static int F_49 ( struct V_32 * V_33 ,
struct V_107 * V_108 , T_1 * V_180 , T_3 * V_181 )
{
struct V_106 * V_182 = (struct V_106 * ) V_108 -> V_119 ;
T_1 V_53 , V_14 , V_114 ;
struct V_1 V_163 ;
F_2 ( & V_163 , V_180 , * V_181 ) ;
if ( ( V_182 -> V_112 & V_118 ) || ( V_182 -> V_113 == 0 ) )
V_53 = V_20 ;
else if ( V_182 -> V_113 <= 4 )
V_53 = V_19 ;
else
V_53 = V_18 ;
V_14 = ( V_33 -> V_75 << 4 ) | ( V_182 -> V_113 & 0x0f ) ;
V_114 = 0 ;
if ( V_182 -> V_112 & V_116 )
V_114 |= 0x02 ;
if ( V_182 -> V_112 & V_118 )
V_114 |= 0x01 ;
F_3 ( & V_163 , V_53 , 0 , V_114 , V_14 , V_182 -> V_112 ,
V_182 -> V_119 ) ;
* V_181 = V_163 . V_9 ;
return 0 ;
}
static int F_50 ( struct V_32 * V_33 )
{
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
int V_36 ;
V_36 = F_24 ( V_33 ,
V_33 -> V_86 . V_87 & V_183 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_25 ( V_33 , 1 ) ;
if ( V_36 )
return V_36 ;
if ( V_74 -> V_102 -> V_184 == 0 ) {
F_51 ( & V_74 -> V_102 -> V_120 , & V_185 ) ;
V_36 = F_20 ( V_33 , 1 ) ;
}
V_74 -> V_102 -> V_184 ++ ;
return V_36 ;
}
static int F_52 ( struct V_32 * V_33 )
{
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
if ( V_74 -> V_102 -> V_184 == 1 )
F_20 ( V_33 , 0 ) ;
V_74 -> V_102 -> V_184 -- ;
return 0 ;
}
static int F_53 ( struct V_32 * V_33 )
{
struct V_101 * V_102 ;
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
if ( ! V_33 -> V_186 ) {
struct V_187 V_188 ;
struct V_189 V_190 ;
int V_36 ;
V_102 = F_54 ( sizeof( struct V_101 ) ,
V_191 ) ;
if ( ! V_102 )
return - V_111 ;
V_102 -> V_161 = 5 ;
V_36 = F_15 ( V_33 , V_192 ,
V_193 ,
& V_188 , sizeof( V_188 ) ) ;
if ( V_36 ) {
F_55 ( V_102 ) ;
F_56 ( V_33 -> V_42 -> V_33 . V_194 ,
L_16 ,
V_185 . V_195 , V_36 ) ;
return V_36 ;
}
V_36 = F_15 ( V_33 , V_192 ,
V_196 ,
& V_190 , sizeof( V_190 ) ) ;
if ( V_36 ) {
F_55 ( V_102 ) ;
F_56 ( V_33 -> V_42 -> V_33 . V_194 ,
L_17 ,
V_185 . V_195 , V_36 ) ;
return V_36 ;
}
F_57 ( V_33 -> V_42 -> V_33 . V_194 ,
L_18 ,
V_185 . V_195 ,
V_190 . V_197 , V_190 . V_198 , V_190 . V_199 ,
V_185 . V_200 ) ;
F_35 ( V_33 , 1 ) ;
} else {
V_102 = F_36 ( V_33 -> V_186 ) ;
}
V_74 -> V_102 = V_102 ;
V_102 -> V_33 [ V_33 -> V_75 ] = V_33 ;
F_26 ( V_33 , 0 , 1 ) ;
return 0 ;
}
static void F_58 ( struct V_32 * V_33 )
{
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
if ( V_33 -> V_86 . V_37 != V_201 ) {
F_23 ( V_33 , 0 ) ;
}
if ( V_33 -> V_75 == 0 ) {
if ( V_74 -> V_102 -> V_184 > 0 )
F_20 ( V_33 , 0 ) ;
F_35 ( V_33 , 0 ) ;
}
}
static void F_59 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_186 && ! V_33 -> V_202 )
F_55 ( F_36 ( V_33 ) ) ;
}
static int F_60 ( struct V_203 * V_204 )
{
struct V_205 * V_206 ;
int V_15 ;
V_206 = V_204 -> V_207 ;
for ( V_15 = 0 ; V_15 < V_206 -> V_208 . V_209 ; V_15 ++ ) {
struct V_210 * V_211 = & V_206 -> V_212 [ V_15 ] . V_208 ;
switch ( V_211 -> V_213 ) {
case V_40 :
case V_50 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
break;
default:
return - V_218 ;
}
}
return 0 ;
}
