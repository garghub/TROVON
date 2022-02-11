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
static int F_35 ( struct V_32 * V_33 , int V_98 )
{
T_1 * V_99 ;
int V_36 ;
V_99 = F_36 ( V_100 , V_101 ) ;
if ( ! V_99 )
return - V_102 ;
V_99 [ 0 ] = 0 ;
V_99 [ 1 ] = ! ! V_98 ;
V_36 = F_15 ( V_33 , V_65 ,
V_103 , V_99 ,
V_100 ) ;
F_37 ( V_99 ) ;
return V_36 ;
}
static inline
struct V_104 * F_38 ( struct V_32 * V_33 )
{
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
return V_74 -> V_105 ;
}
static int F_39 ( struct V_104 * V_105 ,
struct V_106 * V_107 )
{
const unsigned int V_75 = ( V_107 -> V_14 >> 4 ) & 0x0f ;
struct V_32 * V_33 = V_105 -> V_33 [ V_75 ] ;
struct V_108 * V_42 = V_33 -> V_42 ;
struct V_109 * V_109 ;
struct V_110 * V_111 ;
struct V_112 V_113 ;
struct V_114 * V_115 ;
V_111 = F_40 ( V_42 , & V_109 ) ;
if ( ! V_111 )
return - V_102 ;
V_109 -> V_116 = F_13 ( V_107 -> V_13 ) ;
V_109 -> V_117 = V_107 -> V_14 & 0x0f ;
if ( V_107 -> V_118 & V_119 )
V_109 -> V_116 |= V_120 ;
if ( V_107 -> V_118 & V_121 )
V_109 -> V_116 |= V_122 ;
else
memcpy ( V_109 -> V_123 , V_107 -> V_123 , V_109 -> V_117 ) ;
F_41 ( & V_105 -> V_124 , F_13 ( V_107 -> V_125 ) , & V_113 ) ;
V_115 = F_42 ( V_111 ) ;
V_115 -> V_126 = F_43 ( V_113 ) ;
F_44 ( V_111 ) ;
V_42 -> V_127 . V_128 ++ ;
V_42 -> V_127 . V_129 += V_109 -> V_117 ;
return 0 ;
}
static int F_45 ( struct V_104 * V_105 ,
struct V_130 * V_131 )
{
const V_21 V_132 = F_13 ( V_131 -> V_133 ) ;
const unsigned int V_75 = ( V_131 -> V_55 >> 4 ) & 0x0f ;
struct V_32 * V_33 = V_105 -> V_33 [ V_75 ] ;
struct V_108 * V_42 = V_33 -> V_42 ;
struct V_109 * V_109 ;
enum V_134 V_135 = V_136 ;
T_1 V_137 = 0 ;
struct V_110 * V_111 ;
struct V_112 V_113 ;
struct V_114 * V_115 ;
if ( V_33 -> V_86 . V_37 == V_138 )
return 0 ;
if ( ! V_132 ) {
V_33 -> V_86 . V_37 = V_136 ;
return 0 ;
}
if ( V_132 & ( V_139 |
V_140 ) ) {
V_135 = V_141 ;
}
if ( V_132 & V_142 ) {
V_135 = V_138 ;
} else if ( V_132 & V_143 ) {
V_21 V_144 = ( F_13 ( V_131 -> V_145 ) & 0x00ff0000 ) >> 16 ;
V_21 V_146 = ( F_13 ( V_131 -> V_145 ) & 0xff000000 ) >> 24 ;
if ( V_144 > 127 )
V_137 |= V_147 ;
else if ( V_144 > 96 )
V_137 |= V_148 ;
if ( V_146 > 127 )
V_137 |= V_149 ;
else if ( V_146 > 96 )
V_137 |= V_150 ;
if ( V_137 & ( V_148 |
V_150 ) )
V_135 = V_151 ;
else if ( V_137 & ( V_147 |
V_149 ) )
V_135 = V_152 ;
}
if ( V_33 -> V_86 . V_37 == V_135 )
return 0 ;
V_111 = F_46 ( V_42 , & V_109 ) ;
if ( ! V_111 )
return - V_102 ;
switch ( V_135 ) {
case V_138 :
V_109 -> V_116 |= V_153 ;
F_47 ( V_42 ) ;
break;
case V_152 :
V_109 -> V_116 |= V_154 ;
V_109 -> V_123 [ 1 ] |= V_137 ;
V_33 -> V_86 . V_155 . V_156 ++ ;
break;
case V_151 :
V_109 -> V_116 |= V_154 ;
V_109 -> V_123 [ 1 ] |= V_137 ;
V_33 -> V_86 . V_155 . V_157 ++ ;
break;
case V_136 :
break;
default:
if ( V_132 & V_139 ) {
V_109 -> V_116 |= V_158 ;
V_109 -> V_123 [ 2 ] |= V_159 ;
V_42 -> V_127 . V_160 ++ ;
V_42 -> V_127 . V_161 ++ ;
}
if ( V_132 & V_140 ) {
V_109 -> V_116 |= V_154 ;
V_109 -> V_123 [ 1 ] |= V_162 ;
V_42 -> V_127 . V_160 ++ ;
V_42 -> V_127 . V_161 ++ ;
}
V_135 = V_136 ;
break;
}
V_33 -> V_86 . V_37 = V_135 ;
F_41 ( & V_105 -> V_124 , F_13 ( V_131 -> V_125 ) , & V_113 ) ;
V_115 = F_42 ( V_111 ) ;
V_115 -> V_126 = F_43 ( V_113 ) ;
F_44 ( V_111 ) ;
V_42 -> V_127 . V_128 ++ ;
V_42 -> V_127 . V_129 += V_109 -> V_117 ;
return 0 ;
}
static void F_48 ( struct V_104 * V_105 ,
struct V_163 * V_164 )
{
if ( V_105 -> V_165 > 0 )
V_105 -> V_165 -- ;
else
F_49 ( & V_105 -> V_124 ,
F_13 ( V_164 -> V_166 [ 1 ] ) ) ;
}
static int F_50 ( struct V_32 * V_33 , struct V_94 * V_94 )
{
struct V_104 * V_105 = F_38 ( V_33 ) ;
struct V_108 * V_42 = V_33 -> V_42 ;
struct V_1 V_167 ;
T_1 * V_10 , * V_168 ;
V_27 V_12 ;
int V_36 = 0 ;
V_10 = F_1 ( & V_167 , V_94 -> V_169 ,
V_94 -> V_35 ) ;
if ( ! V_10 ) {
F_10 ( V_42 , L_11 , V_94 -> V_35 ) ;
return - V_170 ;
}
V_168 = V_94 -> V_169 + V_94 -> V_35 ;
V_12 = F_51 ( * V_167 . V_6 . V_171 ) ;
for (; V_12 > 0 ; V_12 -- ) {
union V_47 * V_11 = (union V_47 * ) V_10 ;
V_27 V_172 = V_52 [ V_11 -> V_53 ] ;
if ( ! V_172 ) {
F_10 ( V_42 ,
L_12 ) ;
V_36 = - V_173 ;
break;
}
if ( V_10 + V_172 > V_168 ) {
F_10 ( V_42 ,
L_13 ) ;
V_36 = - V_51 ;
break;
}
switch ( V_11 -> V_53 ) {
case V_174 :
case V_175 :
case V_176 :
case V_177 :
V_36 = F_39 ( V_105 , & V_11 -> V_178 ) ;
if ( V_36 < 0 )
goto V_179;
break;
case V_180 :
V_36 = F_45 ( V_105 , & V_11 -> V_181 ) ;
if ( V_36 < 0 )
goto V_179;
break;
case V_182 :
F_48 ( V_105 , & V_11 -> V_183 ) ;
break;
default:
F_10 ( V_42 ,
L_14 ,
V_11 -> V_53 , V_11 -> V_53 ) ;
break;
}
V_10 += V_172 ;
}
V_179:
if ( V_36 )
F_14 ( L_15 ,
V_94 -> V_169 , V_94 -> V_35 ) ;
return V_36 ;
}
static int F_52 ( struct V_32 * V_33 ,
struct V_110 * V_111 , T_1 * V_184 , T_3 * V_185 )
{
struct V_109 * V_186 = (struct V_109 * ) V_111 -> V_123 ;
T_1 V_53 , V_14 , V_118 ;
struct V_1 V_167 ;
F_2 ( & V_167 , V_184 , * V_185 ) ;
if ( ( V_186 -> V_116 & V_122 ) || ( V_186 -> V_117 == 0 ) )
V_53 = V_20 ;
else if ( V_186 -> V_117 <= 4 )
V_53 = V_19 ;
else
V_53 = V_18 ;
V_14 = ( V_33 -> V_75 << 4 ) | ( V_186 -> V_117 & 0x0f ) ;
V_118 = 0 ;
if ( V_186 -> V_116 & V_120 )
V_118 |= 0x02 ;
if ( V_186 -> V_116 & V_122 )
V_118 |= 0x01 ;
F_3 ( & V_167 , V_53 , 0 , V_118 , V_14 , V_186 -> V_116 ,
V_186 -> V_123 ) ;
* V_185 = V_167 . V_9 ;
return 0 ;
}
static int F_53 ( struct V_32 * V_33 )
{
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
int V_36 ;
V_36 = F_24 ( V_33 ,
V_33 -> V_86 . V_87 & V_187 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_25 ( V_33 , 1 ) ;
if ( V_36 )
return V_36 ;
if ( V_74 -> V_105 -> V_188 == 0 ) {
F_54 ( & V_74 -> V_105 -> V_124 , & V_189 ) ;
V_36 = F_20 ( V_33 , 1 ) ;
}
V_74 -> V_105 -> V_188 ++ ;
return V_36 ;
}
static int F_55 ( struct V_32 * V_33 )
{
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
if ( V_74 -> V_105 -> V_188 == 1 )
F_20 ( V_33 , 0 ) ;
V_74 -> V_105 -> V_188 -- ;
return 0 ;
}
static int F_56 ( struct V_32 * V_33 )
{
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
struct V_104 * V_105 = NULL ;
struct V_190 * V_191 = NULL ;
struct V_192 * V_193 = NULL ;
int V_36 ;
if ( ! V_33 -> V_194 ) {
V_105 = F_57 ( sizeof( struct V_104 ) ,
V_101 ) ;
V_191 = F_36 ( sizeof( struct V_190 ) , V_101 ) ;
V_193 = F_36 ( sizeof( struct V_192 ) , V_101 ) ;
if ( ! V_105 || ! V_191 || ! V_193 ) {
V_36 = - V_102 ;
goto V_195;
}
V_105 -> V_165 = 5 ;
V_36 = F_15 ( V_33 , V_196 ,
V_197 ,
V_191 , sizeof( * V_191 ) ) ;
if ( V_36 ) {
F_58 ( V_33 -> V_42 -> V_33 . V_198 ,
L_16 ,
V_189 . V_199 , V_36 ) ;
goto V_195;
}
V_36 = F_15 ( V_33 , V_196 ,
V_200 ,
V_193 , sizeof( * V_193 ) ) ;
if ( V_36 ) {
F_58 ( V_33 -> V_42 -> V_33 . V_198 ,
L_17 ,
V_189 . V_199 , V_36 ) ;
goto V_195;
}
V_36 = F_35 ( V_33 , 1 ) ;
if ( V_36 )
goto V_195;
F_59 ( V_33 -> V_42 -> V_33 . V_198 ,
L_18 ,
V_189 . V_199 ,
V_193 -> V_201 , V_193 -> V_202 , V_193 -> V_203 ,
V_189 . V_204 ) ;
} else {
V_105 = F_38 ( V_33 -> V_194 ) ;
}
V_74 -> V_105 = V_105 ;
V_105 -> V_33 [ V_33 -> V_75 ] = V_33 ;
F_26 ( V_33 , 0 , 1 ) ;
return 0 ;
V_195:
F_37 ( V_193 ) ;
F_37 ( V_191 ) ;
F_37 ( V_105 ) ;
return V_36 ;
}
static void F_60 ( struct V_32 * V_33 )
{
struct V_73 * V_74 =
F_22 ( V_33 , struct V_73 , V_33 ) ;
if ( V_33 -> V_86 . V_37 != V_205 ) {
F_23 ( V_33 , 0 ) ;
}
if ( V_33 -> V_75 == 0 ) {
if ( V_74 -> V_105 -> V_188 > 0 )
F_20 ( V_33 , 0 ) ;
F_35 ( V_33 , 0 ) ;
}
}
static void F_61 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_194 && ! V_33 -> V_206 )
F_37 ( F_38 ( V_33 ) ) ;
}
static int F_62 ( struct V_207 * V_208 )
{
struct V_209 * V_210 ;
int V_15 ;
V_210 = V_208 -> V_211 ;
for ( V_15 = 0 ; V_15 < V_210 -> V_212 . V_213 ; V_15 ++ ) {
struct V_214 * V_215 = & V_210 -> V_216 [ V_15 ] . V_212 ;
switch ( V_215 -> V_217 ) {
case V_40 :
case V_50 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
break;
default:
return - V_222 ;
}
}
return 0 ;
}
