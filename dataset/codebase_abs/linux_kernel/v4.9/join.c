static int
F_1 ( struct V_1 * V_2 , T_1 * * V_3 )
{
int V_4 = 0 ;
struct V_5 V_6 ;
if ( ! V_3 )
return 0 ;
if ( ! ( * V_3 ) )
return 0 ;
if ( V_2 -> V_7 ) {
F_2 ( V_2 -> V_8 , V_9 ,
L_1 ,
V_10 , V_2 -> V_7 , * V_3 ) ;
V_6 . type = F_3 ( V_11 ) ;
V_6 . V_12 = F_3 ( V_2 -> V_7 ) ;
memcpy ( * V_3 , & V_6 , sizeof( V_6 ) ) ;
* V_3 += sizeof( V_6 ) ;
V_4 += sizeof( V_6 ) ;
memcpy ( * V_3 , V_2 -> V_13 , V_2 -> V_7 ) ;
* V_3 += V_2 -> V_7 ;
V_4 += V_2 -> V_7 ;
V_2 -> V_7 = 0 ;
}
return V_4 ;
}
static int
F_4 ( struct V_1 * V_2 , T_1 * * V_3 ,
struct V_14 * V_15 )
{
struct V_16 V_17 ;
T_2 V_18 ;
if ( V_3 == NULL )
return 0 ;
if ( * V_3 == NULL )
return 0 ;
memset ( & V_17 , 0x00 , sizeof( struct V_16 ) ) ;
V_17 . V_19 . type = F_3 ( V_20 ) ;
V_17 . V_19 . V_12 = F_3 ( 2 * sizeof( V_18 ) ) ;
memcpy ( * V_3 , & V_17 , sizeof( V_17 . V_19 ) ) ;
* V_3 += sizeof( V_17 . V_19 ) ;
V_18 = F_5 ( V_15 -> V_21 ) ;
memcpy ( * V_3 , & V_18 , sizeof( V_18 ) ) ;
* V_3 += sizeof( V_18 ) ;
V_18 = F_5 ( V_15 -> V_22 ) ;
F_2 ( V_2 -> V_8 , V_9 ,
L_2 ,
V_10 , V_15 -> V_22 , V_15 -> V_21 ) ;
memcpy ( * V_3 , & V_18 , sizeof( V_18 ) ) ;
* V_3 += sizeof( V_18 ) ;
return sizeof( V_17 . V_19 ) + ( 2 * sizeof( V_18 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_23 ,
T_3 V_24 , T_1 * V_25 , T_3 V_26 )
{
int V_27 ;
T_1 * V_28 = V_23 , * V_29 ;
T_3 V_30 , V_31 ;
V_29 = F_7 ( V_23 , V_24 , V_32 ) ;
if ( ! V_29 ) {
F_2 ( V_2 -> V_8 , ERROR , L_3 ) ;
return - V_33 ;
}
memset ( V_23 , 0 , V_24 ) ;
for ( V_30 = 0 ; V_30 < V_26 && V_25 [ V_30 ] ; V_30 ++ ) {
for ( V_31 = 0 ; V_31 < V_24 && V_29 [ V_31 ] ; V_31 ++ ) {
if ( ( V_25 [ V_30 ] & 0x7F ) == ( V_29 [ V_31 ] & 0x7F ) ) {
* V_23 ++ = V_29 [ V_31 ] ;
break;
}
}
}
F_2 ( V_2 -> V_8 , V_9 , L_4 ,
V_2 -> V_34 ) ;
if ( ! V_2 -> V_35 ) {
while ( * V_28 ) {
if ( ( * V_28 & 0x7f ) == V_2 -> V_34 ) {
V_27 = 0 ;
goto V_36;
}
V_28 ++ ;
}
F_2 ( V_2 -> V_8 , ERROR ,
L_5
L_6 ,
V_2 -> V_34 ) ;
V_27 = - 1 ;
goto V_36;
}
V_27 = 0 ;
V_36:
F_8 ( V_29 ) ;
return V_27 ;
}
static int
F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
T_1 * V_37 , T_3 * V_38 )
{
T_1 V_39 [ V_40 ] ;
T_3 V_41 ;
memcpy ( V_37 , V_15 -> V_42 , V_40 ) ;
V_41 = F_10 ( V_2 , V_39 ) ;
if ( F_6 ( V_2 , V_37 , V_40 ,
V_39 , V_41 ) ) {
* V_38 = 0 ;
F_2 ( V_2 -> V_8 , ERROR ,
L_7 ,
V_10 ) ;
return - 1 ;
}
* V_38 =
F_11 ( V_43 , strlen ( V_37 ) , V_40 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , T_1 * * V_3 )
{
int V_44 = 0 ;
struct V_5 V_6 ;
if ( ! V_3 || ! * V_3 )
return 0 ;
if ( V_2 -> V_45 ) {
F_2 ( V_2 -> V_8 , V_46 ,
L_8 ,
V_2 -> V_45 , * V_3 ) ;
V_6 . type = F_3 ( V_47 ) ;
V_6 . V_12 = F_3 ( V_2 -> V_45 ) ;
memcpy ( * V_3 , & V_6 , sizeof( V_6 ) ) ;
* V_3 += sizeof( V_6 ) ;
V_44 += sizeof( V_6 ) ;
memcpy ( * V_3 , V_2 -> V_48 , V_2 -> V_45 ) ;
* V_3 += V_2 -> V_45 ;
V_44 += V_2 -> V_45 ;
}
F_8 ( V_2 -> V_48 ) ;
V_2 -> V_45 = 0 ;
return V_44 ;
}
static int
F_13 ( struct V_1 * V_2 , T_1 * * V_3 )
{
int V_44 = 0 ;
struct V_5 V_6 ;
if ( V_3 == NULL )
return 0 ;
if ( * V_3 == NULL )
return 0 ;
if ( V_2 -> V_49 ) {
F_2 ( V_2 -> V_8 , V_46 ,
L_9 ,
V_2 -> V_49 , * V_3 ) ;
V_6 . type = F_3 ( V_50 ) ;
V_6 . V_12 = F_3 ( V_2 -> V_49 ) ;
memcpy ( * V_3 , & V_6 , sizeof( V_6 ) ) ;
* V_3 += sizeof( V_6 ) ;
V_44 += sizeof( V_6 ) ;
memcpy ( * V_3 , V_2 -> V_51 , V_2 -> V_49 ) ;
* V_3 += V_2 -> V_49 ;
V_44 += V_2 -> V_49 ;
}
return V_44 ;
}
static int F_14 ( struct V_1 * V_2 ,
T_1 * * V_3 )
{
struct V_52 * V_53 ;
int V_54 ;
if ( ! V_3 || ! ( * V_3 ) )
return 0 ;
V_53 = (struct V_52 * ) ( * V_3 ) ;
V_53 -> V_19 . type = F_3 ( ( V_55 ) V_2 -> V_56 [ 0 ] ) ;
V_53 -> V_19 . type = F_3 (
F_15 ( V_53 -> V_19 . type ) & 0x00FF ) ;
V_53 -> V_19 . V_12 = F_3 ( ( V_55 ) V_2 -> V_56 [ 1 ] ) ;
V_53 -> V_19 . V_12 = F_3 ( F_15 ( V_53 -> V_19 . V_12 )
& 0x00FF ) ;
if ( F_15 ( V_53 -> V_19 . V_12 ) <= ( sizeof( V_2 -> V_56 ) - 2 ) )
memcpy ( V_53 -> V_57 , & V_2 -> V_56 [ 2 ] ,
F_15 ( V_53 -> V_19 . V_12 ) ) ;
else
return - 1 ;
V_54 = sizeof( V_53 -> V_19 ) +
F_15 ( V_53 -> V_19 . V_12 ) ;
* V_3 += V_54 ;
return V_54 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
struct V_14 * V_15 )
{
struct V_60 * V_61 = & V_59 -> V_62 . V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
T_1 V_76 [ V_40 ] ;
T_3 V_77 ;
V_55 V_78 ;
T_1 * V_79 ;
int V_54 = 0 ;
V_79 = ( T_1 * ) V_61 ;
V_59 -> V_80 = F_3 ( V_81 ) ;
V_2 -> V_82 = V_15 ;
memcpy ( V_61 -> V_83 ,
V_15 -> V_84 , sizeof( V_61 -> V_83 ) ) ;
V_79 += sizeof( V_61 -> V_83 ) ;
V_61 -> V_85 = F_3 ( V_2 -> V_85 ) ;
V_61 -> V_86 = F_3 ( V_15 -> V_86 ) ;
V_79 += sizeof( V_61 -> V_87 ) ;
V_79 += sizeof( V_61 -> V_85 ) ;
V_79 += sizeof( V_61 -> V_86 ) ;
V_79 += sizeof( V_61 -> V_88 ) ;
V_65 = (struct V_64 * ) V_79 ;
V_65 -> V_19 . type = F_3 ( V_89 ) ;
V_65 -> V_19 . V_12 = F_3 ( ( V_55 ) V_15 -> V_90 . V_91 ) ;
memcpy ( V_65 -> V_90 , V_15 -> V_90 . V_90 ,
F_15 ( V_65 -> V_19 . V_12 ) ) ;
V_79 += sizeof( V_65 -> V_19 ) + F_15 ( V_65 -> V_19 . V_12 ) ;
V_67 = (struct V_66 * ) V_79 ;
V_67 -> V_19 . type = F_3 ( V_92 ) ;
V_67 -> V_19 . V_12 = F_3 ( sizeof( V_67 -> V_93 . V_94 ) ) ;
memcpy ( & V_67 -> V_93 . V_94 ,
& V_15 -> V_95 . V_94 . V_96 ,
sizeof( V_67 -> V_93 . V_94 ) ) ;
V_79 += sizeof( V_67 -> V_19 ) + F_15 ( V_67 -> V_19 . V_12 ) ;
V_69 = (struct V_68 * ) V_79 ;
V_69 -> V_19 . type = F_3 ( V_97 ) ;
V_69 -> V_19 . V_12 = F_3 ( sizeof( V_69 -> V_98 . V_99 ) ) ;
V_79 += sizeof( V_69 -> V_19 ) + F_15 ( V_69 -> V_19 . V_12 ) ;
if ( F_9
( V_2 , V_15 , V_76 , & V_77 ) )
return - 1 ;
V_2 -> V_100 . V_101 = V_77 ;
memcpy ( & V_2 -> V_100 . V_102 , V_76 , V_77 ) ;
V_71 = (struct V_70 * ) V_79 ;
V_71 -> V_19 . type = F_3 ( V_103 ) ;
V_71 -> V_19 . V_12 = F_3 ( ( V_55 ) V_77 ) ;
memcpy ( V_71 -> V_76 , V_76 , V_77 ) ;
V_79 += sizeof( V_71 -> V_19 ) + V_77 ;
F_2 ( V_2 -> V_8 , V_9 , L_10 ,
V_77 ) ;
V_73 = (struct V_72 * ) V_79 ;
V_73 -> V_19 . type = F_3 ( V_104 ) ;
V_73 -> V_19 . V_12 = F_3 ( sizeof( V_73 -> V_105 ) ) ;
if ( V_2 -> V_106 . V_107 )
V_73 -> V_105 = F_3 (
( V_55 ) V_2 -> V_106 . V_108 ) ;
else
V_73 -> V_105 = F_3 ( V_109 ) ;
V_79 += sizeof( V_73 -> V_19 ) + F_15 ( V_73 -> V_19 . V_12 ) ;
if ( F_17 ( V_2 -> V_8 ) &&
! ( F_18 ( V_2 -> V_8 -> V_110 ) &&
( ! V_15 -> V_111 ) &&
( V_2 -> V_8 -> V_112 & V_113 ||
V_2 -> V_8 -> V_112 & V_114 ) &&
( V_15 -> V_115 )
)
) {
V_75 = (struct V_74 * ) V_79 ;
V_75 -> V_19 . type = F_3 ( V_116 ) ;
V_75 -> V_19 . V_12 =
F_3 ( sizeof( struct V_117 ) ) ;
memset ( V_75 -> V_118 , 0x00 ,
sizeof( struct V_117 ) ) ;
V_75 -> V_118 [ 0 ] . V_119 =
( V_15 -> V_95 . V_94 . V_96 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_11 ,
V_75 -> V_118 [ 0 ] . V_119 ) ;
V_75 -> V_118 [ 0 ] . V_120 =
F_19 ( ( T_1 ) V_15 -> V_121 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_12 ,
V_75 -> V_118 [ 0 ] . V_120 ) ;
V_79 += sizeof( V_75 -> V_19 ) +
sizeof( struct V_117 ) ;
}
if ( ! V_2 -> V_122 . V_123 ) {
if ( V_2 -> V_106 . V_124 || V_2 -> V_106 . V_125 )
V_54 = F_14 ( V_2 , & V_79 ) ;
if ( V_54 == - 1 )
return - 1 ;
}
if ( F_18 ( V_2 -> V_8 -> V_110 ) &&
( ! V_15 -> V_111 ) &&
( V_2 -> V_8 -> V_112 & V_113 ||
V_2 -> V_8 -> V_112 & V_114 ) )
F_20 ( V_2 , V_15 , & V_79 ) ;
if ( F_21 ( V_2 -> V_8 -> V_110 ) &&
! V_15 -> V_111 && ! V_15 -> V_126 &&
V_2 -> V_8 -> V_112 & V_127 )
F_22 ( V_2 , V_15 , & V_79 ) ;
F_23 ( V_2 , V_128 , & V_79 ) ;
F_24 ( V_2 , & V_79 , & V_15 -> V_129 ,
V_15 -> V_115 ) ;
if ( V_2 -> V_106 . V_130 && V_2 -> V_49 )
F_13 ( V_2 , & V_79 ) ;
if ( V_2 -> V_122 . V_123 && V_2 -> V_45 )
F_12 ( V_2 , & V_79 ) ;
F_1 ( V_2 , & V_79 ) ;
F_4 ( V_2 , & V_79 , V_15 ) ;
F_25 ( V_2 , & V_79 , V_15 ) ;
V_59 -> V_131 = F_3 ( ( V_55 ) ( V_79 - ( T_1 * ) V_61 ) + V_132 ) ;
V_78 = V_15 -> V_87 ;
if ( V_2 -> V_8 -> V_112 == V_133 )
V_78 &= ~ V_134 ;
V_78 &= V_135 ;
F_2 ( V_2 -> V_8 , V_9 ,
L_13 ,
V_78 , V_135 ) ;
V_61 -> V_87 = F_3 ( V_78 ) ;
return 0 ;
}
static const char * F_26 ( V_55 V_136 )
{
switch ( V_136 ) {
case V_137 :
return L_14 ;
case V_138 :
return L_15 ;
case V_139 :
return L_16 ;
case V_140 :
return L_17 ;
case V_141 :
return L_18 ;
}
return L_19 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_58 * V_142 )
{
struct V_143 * V_8 = V_2 -> V_8 ;
int V_27 = 0 ;
struct V_144 * V_145 ;
struct V_14 * V_15 ;
bool V_146 = true ;
V_55 V_136 , V_147 , V_148 ;
const T_1 * V_149 ;
struct V_150 * V_151 ;
if ( ! V_2 -> V_82 ) {
F_2 ( V_2 -> V_8 , ERROR ,
L_20 ) ;
goto V_36;
}
V_145 = (struct V_144 * ) & V_142 -> V_62 ;
V_136 = F_15 ( V_145 -> V_87 ) ;
V_147 = F_15 ( V_145 -> V_147 ) ;
V_148 = F_15 ( V_145 -> V_152 ) ;
if ( ( V_148 & ( F_28 ( 15 ) | F_28 ( 14 ) ) ) != ( F_28 ( 15 ) | F_28 ( 14 ) ) )
F_29 ( V_2 -> V_8 -> V_153 ,
L_21 ,
V_148 ) ;
V_148 &= ~ ( F_28 ( 15 ) | F_28 ( 14 ) ) ;
V_2 -> V_154 = F_30 ( F_15 ( V_142 -> V_131 ) - V_132 ,
sizeof( V_2 -> V_155 ) ) ;
V_145 -> V_152 = F_3 ( V_148 ) ;
memcpy ( V_2 -> V_155 , & V_142 -> V_62 , V_2 -> V_154 ) ;
if ( V_147 ) {
V_2 -> V_8 -> V_156 . V_157 ++ ;
F_2 ( V_2 -> V_8 , ERROR ,
L_22
L_23 ,
V_147 , V_136 ,
F_15 ( V_145 -> V_152 ) ) ;
F_2 ( V_2 -> V_8 , ERROR , L_24 ,
F_26 ( V_136 ) ) ;
if ( V_136 == V_139 ) {
if ( V_147 == V_158 ) {
V_27 = V_159 ;
F_2 ( V_2 -> V_8 , ERROR ,
L_25 ) ;
} else {
V_27 = V_160 ;
F_2 ( V_2 -> V_8 , ERROR ,
L_26 ) ;
}
} else {
V_27 = V_147 ;
}
goto V_36;
}
V_2 -> V_161 = true ;
V_2 -> V_8 -> V_162 = V_163 ;
V_2 -> V_8 -> V_164 = false ;
V_2 -> V_8 -> V_165 = false ;
V_15 = V_2 -> V_82 ;
F_2 ( V_2 -> V_8 , V_9 , L_27 ,
V_15 -> V_90 . V_90 ) ;
memcpy ( & V_2 -> V_100 . V_166 ,
V_15 , sizeof( struct V_14 ) ) ;
V_2 -> V_100 . V_166 . V_167
= V_15 -> V_95 . V_94 . V_96 ;
V_2 -> V_100 . V_168 = ( T_1 ) V_15 -> V_121 ;
if ( V_15 -> V_129 . V_169 . V_170 == V_171 )
V_2 -> V_100 . V_172 = true ;
else
V_2 -> V_100 . V_172 = false ;
if ( ( V_2 -> V_173 || V_15 -> V_115 ) &&
V_2 -> V_100 . V_172 )
V_2 -> V_172 = true ;
else
V_2 -> V_172 = false ;
V_2 -> V_100 . V_174 = false ;
if ( V_2 -> V_172 )
V_2 -> V_100 . V_174
= ( ( V_15 -> V_129 . V_175 &
V_176 ) ? 1 : 0 ) ;
V_149 = F_31 ( V_177 , V_145 -> V_178 ,
V_2 -> V_154
- sizeof( struct V_144 ) ) ;
if ( V_149 ) {
V_151 = (struct V_150 * ) ( V_149
+ sizeof( struct V_179 ) ) ;
V_2 -> V_180 = V_151 -> V_181 ;
V_2 -> V_182 = true ;
} else {
V_2 -> V_182 = false ;
}
F_2 ( V_2 -> V_8 , V_9 ,
L_28 ,
V_2 -> V_183 ) ;
if ( V_2 -> V_106 . V_124 || V_2 -> V_106 . V_125 )
V_2 -> V_184 = false ;
if ( V_2 -> V_172 ) {
V_146 = false ;
} else {
F_32 ( V_2 , NULL ) ;
F_33 ( V_2 ) ;
}
if ( V_146 )
F_2 ( V_2 -> V_8 , V_9 ,
L_29 ) ;
V_2 -> V_185 = 0 ;
V_2 -> V_186 = 0 ;
V_2 -> V_187 = 0 ;
V_2 -> V_188 = 0 ;
V_2 -> V_189 = 0 ;
V_2 -> V_190 = 0 ;
V_2 -> V_191 = 0 ;
V_2 -> V_192 = 0 ;
V_2 -> V_193 = 0 ;
V_2 -> V_194 = 0 ;
F_34 ( V_2 ) ;
V_2 -> V_8 -> V_156 . V_195 ++ ;
F_2 ( V_2 -> V_8 , V_9 , L_30 ) ;
F_35 ( V_2 ,
V_2 -> V_100 . V_166 . V_84 ) ;
if ( ! F_36 ( V_2 -> V_196 ) )
F_37 ( V_2 -> V_196 ) ;
F_38 ( V_2 -> V_196 , V_8 ) ;
if ( V_2 -> V_106 . V_124 || V_2 -> V_106 . V_125 )
V_2 -> V_197 = true ;
else
V_2 -> V_198 = true ;
V_36:
if ( V_8 -> V_199 -> V_200 ) {
if ( V_27 )
V_8 -> V_201 . V_202 = - 1 ;
else
V_8 -> V_201 . V_202 = 0 ;
}
return V_27 ;
}
int
F_39 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
struct V_203 * V_204 )
{
int V_54 = 0 ;
struct V_143 * V_8 = V_2 -> V_8 ;
struct V_205 * V_206 =
& V_59 -> V_62 . V_206 ;
struct V_14 * V_15 ;
T_3 V_207 = 0 ;
T_3 V_30 ;
V_55 V_78 ;
struct V_74 * V_75 ;
T_1 V_120 ;
struct V_208 * V_209 ;
struct V_210 * V_211 ;
T_1 * V_79 = ( T_1 * ) V_206 +
sizeof( struct V_205 ) ;
if ( ! V_8 )
return - 1 ;
V_59 -> V_80 = F_3 ( V_212 ) ;
V_15 = & V_2 -> V_100 . V_166 ;
V_2 -> V_82 = V_15 ;
memset ( V_206 -> V_90 , 0 , V_213 ) ;
memcpy ( V_206 -> V_90 , V_204 -> V_90 , V_204 -> V_91 ) ;
F_2 ( V_8 , V_9 , L_31 ,
V_206 -> V_90 ) ;
memset ( V_15 -> V_90 . V_90 , 0 , V_213 ) ;
memcpy ( V_15 -> V_90 . V_90 , V_204 -> V_90 , V_204 -> V_91 ) ;
V_15 -> V_90 . V_91 = V_204 -> V_91 ;
V_206 -> V_214 = V_215 ;
V_15 -> V_214 = V_216 ;
V_206 -> V_86 = F_3 ( V_2 -> V_86 ) ;
V_15 -> V_86 = V_2 -> V_86 ;
#define F_40 3
#define F_41 1
V_206 -> V_95 . V_94 . V_170 = F_40 ;
V_206 -> V_95 . V_94 . V_12 = F_41 ;
if ( ! F_42 ( V_2 , V_8 -> V_217 ,
( V_55 ) V_2 -> V_218 , 0 ) ) {
struct V_219 * V_220 ;
V_220 = F_42 ( V_2 , V_8 -> V_217 ,
V_221 , 0 ) ;
if ( V_220 )
V_2 -> V_218 = ( T_1 ) V_220 -> V_167 ;
}
if ( ! V_2 -> V_218 ) {
F_2 ( V_8 , ERROR ,
L_32 ) ;
return - 1 ;
}
F_2 ( V_8 , V_9 ,
L_33 ,
V_2 -> V_218 ) ;
V_2 -> V_100 . V_166 . V_167 = V_2 -> V_218 ;
V_2 -> V_100 . V_168 = V_8 -> V_217 ;
V_15 -> V_167 = V_2 -> V_218 ;
V_206 -> V_95 . V_94 . V_96 =
V_2 -> V_218 ;
memcpy ( & V_15 -> V_95 , & V_206 -> V_95 ,
sizeof( union V_222 ) ) ;
#define F_43 6
#define F_44 2
V_206 -> V_223 . V_224 . V_170 = F_43 ;
V_206 -> V_223 . V_224 . V_12 = F_44 ;
V_206 -> V_223 . V_224 . V_225
= F_3 ( V_2 -> V_225 ) ;
memcpy ( & V_15 -> V_223 , & V_206 -> V_223 ,
sizeof( union V_226 ) ) ;
V_15 -> V_87 |= V_227 ;
V_78 = V_227 ;
if ( V_2 -> V_106 . V_228 ) {
F_2 ( V_8 , V_9 ,
L_34 ) ;
V_15 -> V_229 = V_230 ;
V_78 |= V_231 ;
} else {
F_2 ( V_8 , V_9 ,
L_35
L_36 ) ;
V_15 -> V_229 = V_232 ;
}
memset ( V_206 -> V_34 , 0 , sizeof( V_206 -> V_34 ) ) ;
F_10 ( V_2 , V_206 -> V_34 ) ;
if ( ( V_8 -> V_217 & V_233 ) &&
( V_2 -> V_183 & V_234 ) ) {
if ( F_45 ( V_2 , V_235 ,
V_236 , 0 ,
& V_2 -> V_183 , false ) ) {
F_2 ( V_8 , ERROR ,
L_37 ) ;
return - 1 ;
}
}
for ( V_30 = 0 ; V_30 < sizeof( V_206 -> V_34 ) ; V_30 ++ )
if ( ! V_206 -> V_34 [ V_30 ] )
break;
V_2 -> V_100 . V_101 = V_30 ;
memcpy ( & V_2 -> V_100 . V_102 ,
& V_206 -> V_34 , V_2 -> V_100 . V_101 ) ;
F_2 ( V_8 , V_9 , L_38 ,
V_206 -> V_34 ) ;
F_2 ( V_8 , V_9 , L_39 ) ;
if ( F_17 ( V_8 ) ) {
V_75 = (struct V_74 * ) V_79 ;
V_75 -> V_19 . type = F_3 ( V_116 ) ;
V_75 -> V_19 . V_12 =
F_3 ( sizeof( struct V_117 ) ) ;
memset ( V_75 -> V_118 , 0x00 ,
sizeof( struct V_117 ) ) ;
V_75 -> V_118 [ 0 ] . V_119 =
( T_1 ) V_2 -> V_100 . V_166 . V_167 ;
F_2 ( V_8 , V_9 , L_40 ,
V_75 -> V_118 [ 0 ] . V_119 ) ;
V_75 -> V_118 [ 0 ] . V_120
= F_19 ( V_2 -> V_100 . V_168 ) ;
if ( V_8 -> V_217 & V_113 ||
V_8 -> V_217 & V_114 ) {
if ( V_8 -> V_237 ==
V_238 )
V_75 -> V_118 [ 0 ] . V_120 |=
( V_238 << 4 ) ;
else if ( V_8 -> V_237 ==
V_239 )
V_75 -> V_118 [ 0 ] . V_120 |=
( V_239 << 4 ) ;
}
F_2 ( V_8 , V_9 , L_41 ,
V_75 -> V_118 [ 0 ] . V_120 ) ;
V_79 += sizeof( V_75 -> V_19 ) +
sizeof( struct V_117 ) ;
V_207 +=
sizeof( V_75 -> V_19 ) +
sizeof( struct V_117 ) ;
}
V_207 += F_23 ( V_2 ,
V_240 , & V_79 ) ;
if ( V_2 -> V_106 . V_124 ) {
V_54 = F_14 ( V_2 , & V_79 ) ;
if ( V_54 == - 1 )
return - 1 ;
V_207 += V_54 ;
}
if ( V_8 -> V_241 ) {
V_209 = (struct V_208 * ) V_79 ;
memset ( V_209 , 0 , sizeof( struct V_208 ) ) ;
V_209 -> V_19 . type = F_3 ( V_242 ) ;
V_209 -> V_19 . V_12 =
F_3 ( sizeof( struct V_243 ) ) ;
V_120 = F_19 (
V_2 -> V_8 -> V_112 ) ;
F_46 ( V_2 , V_120 , & V_209 -> V_209 ) ;
if ( V_8 -> V_237 ==
V_244 ) {
V_55 V_245 ;
V_245 = F_15 ( V_209 -> V_209 . V_136 ) ;
V_245 &= ~ V_246 ;
V_245 &= ~ V_247 ;
V_209 -> V_209 . V_136 = F_3 ( V_245 ) ;
}
V_79 += sizeof( struct V_208 ) ;
V_207 += sizeof( struct V_208 ) ;
V_211 = (struct V_210 * ) V_79 ;
memset ( V_211 , 0 , sizeof( struct V_210 ) ) ;
V_211 -> V_19 . type = F_3 ( V_177 ) ;
V_211 -> V_19 . V_12 =
F_3 ( sizeof( struct V_150 ) ) ;
V_211 -> V_248 . V_249 =
( T_1 ) V_2 -> V_100 . V_166 . V_167 ;
if ( V_8 -> V_237 ) {
V_211 -> V_248 . V_181 = V_8 -> V_237 ;
V_211 -> V_248 . V_181 |=
V_250 ;
}
V_211 -> V_248 . V_251 =
F_3 ( V_252 ) ;
V_211 -> V_248 . V_253 [ 0 ] = 0xff ;
V_79 += sizeof( struct V_210 ) ;
V_207 +=
sizeof( struct V_210 ) ;
}
V_59 -> V_131 =
F_3 ( ( V_55 ) ( sizeof( struct V_205 )
+ V_132 + V_207 ) ) ;
if ( V_8 -> V_217 == V_133 )
V_78 &= ~ V_134 ;
else
V_78 |= V_134 ;
V_206 -> V_87 = F_3 ( V_78 ) ;
return 0 ;
}
int
F_47 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
struct V_14 * V_15 )
{
int V_54 = 0 ;
struct V_254 * V_255 =
& V_59 -> V_62 . V_255 ;
struct V_74 * V_75 ;
T_3 V_207 = 0 ;
V_55 V_78 ;
T_3 V_30 , V_77 = 0 ;
V_55 V_183 ;
T_1 * V_79 =
( T_1 * ) V_255 +
sizeof( struct V_254 ) ;
#define F_48 0x02
if ( V_15 -> V_256 & F_48 ) {
V_183 =
V_2 ->
V_183 | V_234 ;
if ( F_45 ( V_2 , V_235 ,
V_236 , 0 ,
& V_183 , false ) ) {
F_2 ( V_2 -> V_8 , ERROR ,
L_42 ) ;
return - 1 ;
}
}
V_2 -> V_82 = V_15 ;
V_59 -> V_80 = F_3 ( V_257 ) ;
V_255 -> V_166 . V_214 = V_215 ;
V_255 -> V_166 . V_86
= F_3 ( V_15 -> V_86 ) ;
memcpy ( & V_255 -> V_166 . V_258 ,
& V_15 -> V_84 , V_259 ) ;
memcpy ( & V_255 -> V_166 . V_90 ,
& V_15 -> V_90 . V_90 , V_15 -> V_90 . V_91 ) ;
memcpy ( & V_255 -> V_166 . V_95 ,
& V_15 -> V_95 ,
sizeof( union V_222 ) ) ;
memcpy ( & V_255 -> V_166 . V_223 ,
& V_15 -> V_223 , sizeof( union V_226 ) ) ;
V_78 = V_15 -> V_87 ;
V_78 &= V_135 ;
F_2 ( V_2 -> V_8 , V_9 ,
L_43 ,
V_78 , V_135 ) ;
F_2 ( V_2 -> V_8 , V_9 ,
L_44 ,
V_255 -> V_166 . V_258 ,
V_255 -> V_166 . V_90 ) ;
for ( V_30 = 0 ; V_30 < V_40 &&
V_15 -> V_42 [ V_30 ] ; V_30 ++ )
;
V_77 = V_30 ;
memset ( V_255 -> V_166 . V_102 , 0 ,
sizeof( V_255 -> V_166 . V_102 ) ) ;
memcpy ( V_255 -> V_166 . V_102 ,
V_15 -> V_42 , V_77 ) ;
V_2 -> V_100 . V_101 = V_77 ;
memcpy ( & V_2 -> V_100 . V_102 , V_15 -> V_42 ,
V_77 ) ;
V_2 -> V_100 . V_166 . V_167 = V_15 -> V_167 ;
V_2 -> V_100 . V_168 = ( T_1 ) V_15 -> V_121 ;
if ( V_2 -> V_106 . V_107 || V_2 -> V_106 . V_124 )
V_78 |= V_231 ;
if ( F_17 ( V_2 -> V_8 ) ) {
V_75 = (struct V_74 * ) V_79 ;
V_75 -> V_19 . type = F_3 ( V_116 ) ;
V_75 -> V_19 . V_12 =
F_3 ( sizeof( struct V_117 ) ) ;
memset ( V_75 -> V_118 , 0x00 ,
sizeof( struct V_117 ) ) ;
V_75 -> V_118 [ 0 ] . V_119 =
( V_15 -> V_95 . V_94 . V_96 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_45 ,
V_75 -> V_118 [ 0 ] . V_119 ) ;
V_75 -> V_118 [ 0 ] . V_120 =
F_19 ( ( T_1 ) V_15 -> V_121 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_46 ,
V_75 -> V_118 [ 0 ] . V_120 ) ;
V_79 += sizeof( V_75 -> V_19 ) +
sizeof( struct V_117 ) ;
V_207 += sizeof( V_75 -> V_19 ) +
sizeof( struct V_117 ) ;
}
if ( V_2 -> V_106 . V_124 )
V_54 = F_14 ( V_2 , & V_79 ) ;
if ( V_54 == - 1 )
return - 1 ;
V_207 += V_54 ;
if ( F_18 ( V_2 -> V_8 -> V_110 ) )
V_207 += F_20 ( V_2 ,
V_15 , & V_79 ) ;
V_207 += F_23 ( V_2 ,
V_240 , & V_79 ) ;
V_59 -> V_131 = F_3
( ( V_55 ) ( sizeof( struct V_254 )
+ V_132 + V_207 ) ) ;
V_255 -> V_166 . V_87 = F_3 ( V_78 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_58 * V_142 )
{
int V_27 = 0 ;
struct V_143 * V_8 = V_2 -> V_8 ;
struct V_260 * V_261 =
& V_142 -> V_62 . V_261 ;
struct V_262 * V_263 =
& V_142 -> V_62 . V_263 ;
struct V_14 * V_15 ;
V_55 V_59 = F_15 ( V_142 -> V_80 ) ;
T_1 V_264 ;
if ( ! V_2 -> V_82 ) {
F_2 ( V_2 -> V_8 , ERROR ,
L_47 ) ;
goto V_36;
}
if ( V_59 == V_212 )
V_264 = V_261 -> V_264 ;
else
V_264 = V_263 -> V_264 ;
V_15 = V_2 -> V_82 ;
if ( V_264 ) {
F_2 ( V_2 -> V_8 , ERROR , L_48 ) ;
if ( V_2 -> V_161 )
F_50 ( V_2 , V_264 , true ) ;
memset ( & V_2 -> V_100 . V_166 ,
0x00 , sizeof( struct V_14 ) ) ;
V_27 = - 1 ;
goto V_36;
}
V_2 -> V_161 = true ;
if ( F_15 ( V_142 -> V_80 ) == V_212 ) {
F_2 ( V_2 -> V_8 , V_9 , L_49 ,
V_15 -> V_90 . V_90 ) ;
memcpy ( V_15 -> V_84 ,
V_261 -> V_258 , V_259 ) ;
V_2 -> V_265 = V_266 ;
} else {
F_2 ( V_2 -> V_8 , V_9 ,
L_50 ,
V_15 -> V_90 . V_90 ) ;
memcpy ( & V_2 -> V_100 . V_166 ,
V_15 , sizeof( struct V_14 ) ) ;
V_2 -> V_265 = V_267 ;
}
F_2 ( V_2 -> V_8 , V_9 , L_51 ,
V_2 -> V_218 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_52 ,
V_2 -> V_100 . V_166 . V_84 ) ;
if ( ! F_36 ( V_2 -> V_196 ) )
F_37 ( V_2 -> V_196 ) ;
F_38 ( V_2 -> V_196 , V_8 ) ;
F_34 ( V_2 ) ;
V_36:
if ( V_8 -> V_199 -> V_200 ) {
if ( V_27 )
V_8 -> V_201 . V_202 = - 1 ;
else
V_8 -> V_201 . V_202 = 0 ;
}
return V_27 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
if ( ( F_52 ( V_2 ) != V_268 ) ||
( V_15 -> V_214 != V_269 ) )
return - 1 ;
if ( F_21 ( V_2 -> V_8 -> V_110 ) &&
! V_15 -> V_111 && ! V_15 -> V_126 &&
V_2 -> V_8 -> V_112 & V_127 )
F_53 ( V_2 ) ;
else
F_54 ( V_2 ) ;
V_2 -> V_154 = 0 ;
return F_45 ( V_2 , V_81 ,
V_236 , 0 , V_15 , true ) ;
}
int
F_55 ( struct V_1 * V_2 ,
struct V_203 * V_270 )
{
F_2 ( V_2 -> V_8 , V_9 , L_53 ,
V_2 -> V_218 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_54 ,
V_2 -> V_100 . V_166 . V_167 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_55 ,
V_2 -> V_100 . V_168 ) ;
if ( F_21 ( V_2 -> V_8 -> V_110 ) &&
V_2 -> V_8 -> V_112 & V_127 )
F_53 ( V_2 ) ;
else
F_54 ( V_2 ) ;
return F_45 ( V_2 , V_212 ,
V_236 , 0 , V_270 , true ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_2 ( V_2 -> V_8 , V_9 ,
L_56 ,
V_2 -> V_100 . V_166 . V_90 . V_90 ) ;
F_2 ( V_2 -> V_8 , V_9 ,
L_57 ,
V_2 -> V_100 . V_166 . V_90 . V_91 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_58 ,
V_15 -> V_90 . V_90 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_59 ,
V_15 -> V_90 . V_91 ) ;
if ( V_2 -> V_100 . V_166 . V_90 . V_91 &&
! F_57 ( & V_15 -> V_90 ,
& V_2 -> V_100 . V_166 . V_90 ) &&
( V_2 -> V_100 . V_166 . V_214 ==
V_216 ) ) {
F_2 ( V_2 -> V_8 , V_9 ,
L_60
L_61 ) ;
return - 1 ;
}
if ( F_21 ( V_2 -> V_8 -> V_110 ) &&
! V_15 -> V_111 && ! V_15 -> V_126 &&
V_2 -> V_8 -> V_112 & V_127 )
F_53 ( V_2 ) ;
else
F_54 ( V_2 ) ;
F_2 ( V_2 -> V_8 , V_9 ,
L_54 ,
V_2 -> V_100 . V_166 . V_167 ) ;
F_2 ( V_2 -> V_8 , V_9 ,
L_62 ,
V_2 -> V_100 . V_168 ) ;
return F_45 ( V_2 , V_257 ,
V_236 , 0 , V_15 , true ) ;
}
static int F_58 ( struct V_1 * V_2 , T_1 * V_271 )
{
T_1 V_84 [ V_259 ] ;
int V_27 ;
if ( ! V_271 || F_59 ( V_271 ) )
memcpy ( V_84 ,
V_2 -> V_100 . V_166 . V_84 ,
V_259 ) ;
else
memcpy ( V_84 , V_271 , V_259 ) ;
V_27 = F_45 ( V_2 , V_272 ,
V_236 , 0 , V_84 , true ) ;
return V_27 ;
}
int F_60 ( struct V_1 * V_2 , T_1 * V_271 )
{
int V_27 = 0 ;
if ( ! V_2 -> V_161 )
return 0 ;
switch ( V_2 -> V_214 ) {
case V_269 :
case V_273 :
V_27 = F_58 ( V_2 , V_271 ) ;
if ( V_27 )
F_61 ( V_2 -> V_196 , 0 , NULL , 0 ,
true , V_32 ) ;
break;
case V_216 :
return F_45 ( V_2 , V_274 ,
V_236 , 0 , NULL , true ) ;
case V_275 :
return F_45 ( V_2 , V_276 ,
V_236 , 0 , NULL , true ) ;
default:
break;
}
return V_27 ;
}
void F_62 ( struct V_143 * V_8 )
{
struct V_1 * V_2 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_277 ; V_30 ++ ) {
V_2 = V_8 -> V_2 [ V_30 ] ;
if ( V_2 )
F_60 ( V_2 , NULL ) ;
}
}
T_1
F_19 ( T_1 V_168 )
{
switch ( V_168 ) {
case V_278 :
case V_114 :
case V_278 | V_114 :
case V_278 | V_114 | V_127 :
return V_279 ;
case V_133 :
case V_233 :
case V_133 | V_233 :
default:
return V_280 ;
}
}
