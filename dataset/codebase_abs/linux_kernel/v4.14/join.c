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
V_6 . type = F_3 ( V_11 ) ;
V_6 . V_12 = F_3 ( V_2 -> V_45 ) ;
memcpy ( * V_3 , & V_6 , sizeof( V_6 ) ) ;
* V_3 += sizeof( V_6 ) ;
V_44 += sizeof( V_6 ) ;
memcpy ( * V_3 , V_2 -> V_47 , V_2 -> V_45 ) ;
* V_3 += V_2 -> V_45 ;
V_44 += V_2 -> V_45 ;
}
F_8 ( V_2 -> V_47 ) ;
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
if ( V_2 -> V_48 ) {
F_2 ( V_2 -> V_8 , V_46 ,
L_9 ,
V_2 -> V_48 , * V_3 ) ;
V_6 . type = F_3 ( V_49 ) ;
V_6 . V_12 = F_3 ( V_2 -> V_48 ) ;
memcpy ( * V_3 , & V_6 , sizeof( V_6 ) ) ;
* V_3 += sizeof( V_6 ) ;
V_44 += sizeof( V_6 ) ;
memcpy ( * V_3 , V_2 -> V_50 , V_2 -> V_48 ) ;
* V_3 += V_2 -> V_48 ;
V_44 += V_2 -> V_48 ;
}
return V_44 ;
}
static int F_14 ( struct V_1 * V_2 ,
T_1 * * V_3 )
{
struct V_51 * V_52 ;
int V_53 ;
if ( ! V_3 || ! ( * V_3 ) )
return 0 ;
V_52 = (struct V_51 * ) ( * V_3 ) ;
V_52 -> V_19 . type = F_3 ( ( V_54 ) V_2 -> V_55 [ 0 ] ) ;
V_52 -> V_19 . type = F_3 (
F_15 ( V_52 -> V_19 . type ) & 0x00FF ) ;
V_52 -> V_19 . V_12 = F_3 ( ( V_54 ) V_2 -> V_55 [ 1 ] ) ;
V_52 -> V_19 . V_12 = F_3 ( F_15 ( V_52 -> V_19 . V_12 )
& 0x00FF ) ;
if ( F_15 ( V_52 -> V_19 . V_12 ) <= ( sizeof( V_2 -> V_55 ) - 2 ) )
memcpy ( V_52 -> V_56 , & V_2 -> V_55 [ 2 ] ,
F_15 ( V_52 -> V_19 . V_12 ) ) ;
else
return - 1 ;
V_53 = sizeof( V_52 -> V_19 ) +
F_15 ( V_52 -> V_19 . V_12 ) ;
* V_3 += V_53 ;
return V_53 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_14 * V_15 )
{
struct V_59 * V_60 = & V_58 -> V_61 . V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
T_1 V_75 [ V_40 ] ;
T_3 V_76 ;
V_54 V_77 ;
T_1 * V_78 ;
int V_53 = 0 ;
V_78 = ( T_1 * ) V_60 ;
V_58 -> V_79 = F_3 ( V_80 ) ;
V_2 -> V_81 = V_15 ;
memcpy ( V_60 -> V_82 ,
V_15 -> V_83 , sizeof( V_60 -> V_82 ) ) ;
V_78 += sizeof( V_60 -> V_82 ) ;
V_60 -> V_84 = F_3 ( V_2 -> V_84 ) ;
V_60 -> V_85 = F_3 ( V_15 -> V_85 ) ;
V_78 += sizeof( V_60 -> V_86 ) ;
V_78 += sizeof( V_60 -> V_84 ) ;
V_78 += sizeof( V_60 -> V_85 ) ;
V_78 += sizeof( V_60 -> V_87 ) ;
V_64 = (struct V_63 * ) V_78 ;
V_64 -> V_19 . type = F_3 ( V_88 ) ;
V_64 -> V_19 . V_12 = F_3 ( ( V_54 ) V_15 -> V_89 . V_90 ) ;
memcpy ( V_64 -> V_89 , V_15 -> V_89 . V_89 ,
F_15 ( V_64 -> V_19 . V_12 ) ) ;
V_78 += sizeof( V_64 -> V_19 ) + F_15 ( V_64 -> V_19 . V_12 ) ;
V_66 = (struct V_65 * ) V_78 ;
V_66 -> V_19 . type = F_3 ( V_91 ) ;
V_66 -> V_19 . V_12 = F_3 ( sizeof( V_66 -> V_92 . V_93 ) ) ;
memcpy ( & V_66 -> V_92 . V_93 ,
& V_15 -> V_94 . V_93 . V_95 ,
sizeof( V_66 -> V_92 . V_93 ) ) ;
V_78 += sizeof( V_66 -> V_19 ) + F_15 ( V_66 -> V_19 . V_12 ) ;
V_68 = (struct V_67 * ) V_78 ;
V_68 -> V_19 . type = F_3 ( V_96 ) ;
V_68 -> V_19 . V_12 = F_3 ( sizeof( V_68 -> V_97 . V_98 ) ) ;
V_78 += sizeof( V_68 -> V_19 ) + F_15 ( V_68 -> V_19 . V_12 ) ;
if ( F_9
( V_2 , V_15 , V_75 , & V_76 ) )
return - 1 ;
V_2 -> V_99 . V_100 = V_76 ;
memcpy ( & V_2 -> V_99 . V_101 , V_75 , V_76 ) ;
V_70 = (struct V_69 * ) V_78 ;
V_70 -> V_19 . type = F_3 ( V_102 ) ;
V_70 -> V_19 . V_12 = F_3 ( ( V_54 ) V_76 ) ;
memcpy ( V_70 -> V_75 , V_75 , V_76 ) ;
V_78 += sizeof( V_70 -> V_19 ) + V_76 ;
F_2 ( V_2 -> V_8 , V_9 , L_10 ,
V_76 ) ;
V_72 = (struct V_71 * ) V_78 ;
V_72 -> V_19 . type = F_3 ( V_103 ) ;
V_72 -> V_19 . V_12 = F_3 ( sizeof( V_72 -> V_104 ) ) ;
if ( V_2 -> V_105 . V_106 )
V_72 -> V_104 = F_3 (
( V_54 ) V_2 -> V_105 . V_107 ) ;
else
V_72 -> V_104 = F_3 ( V_108 ) ;
V_78 += sizeof( V_72 -> V_19 ) + F_15 ( V_72 -> V_19 . V_12 ) ;
if ( F_17 ( V_2 -> V_8 ) &&
! ( F_18 ( V_2 -> V_8 -> V_109 ) &&
( ! V_15 -> V_110 ) &&
( V_2 -> V_8 -> V_111 & V_112 ||
V_2 -> V_8 -> V_111 & V_113 ) &&
( V_15 -> V_114 )
)
) {
V_74 = (struct V_73 * ) V_78 ;
V_74 -> V_19 . type = F_3 ( V_115 ) ;
V_74 -> V_19 . V_12 =
F_3 ( sizeof( struct V_116 ) ) ;
memset ( V_74 -> V_117 , 0x00 ,
sizeof( struct V_116 ) ) ;
V_74 -> V_117 [ 0 ] . V_118 =
( V_15 -> V_94 . V_93 . V_95 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_11 ,
V_74 -> V_117 [ 0 ] . V_118 ) ;
V_74 -> V_117 [ 0 ] . V_119 =
F_19 ( ( T_1 ) V_15 -> V_120 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_12 ,
V_74 -> V_117 [ 0 ] . V_119 ) ;
V_78 += sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
}
if ( ! V_2 -> V_121 . V_122 ) {
if ( V_2 -> V_105 . V_123 || V_2 -> V_105 . V_124 )
V_53 = F_14 ( V_2 , & V_78 ) ;
if ( V_53 == - 1 )
return - 1 ;
}
if ( F_18 ( V_2 -> V_8 -> V_109 ) &&
( ! V_15 -> V_110 ) &&
( V_2 -> V_8 -> V_111 & V_112 ||
V_2 -> V_8 -> V_111 & V_113 ) )
F_20 ( V_2 , V_15 , & V_78 ) ;
if ( F_21 ( V_2 -> V_8 -> V_109 ) &&
! V_15 -> V_110 && ! V_15 -> V_125 &&
V_2 -> V_8 -> V_111 & V_126 )
F_22 ( V_2 , V_15 , & V_78 ) ;
F_23 ( V_2 , V_127 , & V_78 ) ;
F_24 ( V_2 , & V_78 , & V_15 -> V_128 ,
V_15 -> V_114 ) ;
if ( V_2 -> V_105 . V_129 && V_2 -> V_48 )
F_13 ( V_2 , & V_78 ) ;
if ( V_2 -> V_121 . V_122 && V_2 -> V_45 )
F_12 ( V_2 , & V_78 ) ;
F_1 ( V_2 , & V_78 ) ;
F_4 ( V_2 , & V_78 , V_15 ) ;
F_25 ( V_2 , & V_78 , V_15 ) ;
V_58 -> V_130 = F_3 ( ( V_54 ) ( V_78 - ( T_1 * ) V_60 ) + V_131 ) ;
V_77 = V_15 -> V_86 ;
if ( V_2 -> V_8 -> V_111 == V_132 )
V_77 &= ~ V_133 ;
V_77 &= V_134 ;
F_2 ( V_2 -> V_8 , V_9 ,
L_13 ,
V_77 , V_134 ) ;
V_60 -> V_86 = F_3 ( V_77 ) ;
return 0 ;
}
static const char * F_26 ( V_54 V_135 )
{
switch ( V_135 ) {
case V_136 :
return L_14 ;
case V_137 :
return L_15 ;
case V_138 :
return L_16 ;
case V_139 :
return L_17 ;
case V_140 :
return L_18 ;
}
return L_19 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_57 * V_141 )
{
struct V_142 * V_8 = V_2 -> V_8 ;
int V_27 = 0 ;
struct V_143 * V_144 ;
struct V_14 * V_15 ;
bool V_145 = true ;
V_54 V_135 , V_146 , V_147 ;
const T_1 * V_148 ;
struct V_149 * V_150 ;
if ( ! V_2 -> V_81 ) {
F_2 ( V_2 -> V_8 , ERROR ,
L_20 ) ;
goto V_36;
}
V_144 = (struct V_143 * ) & V_141 -> V_61 ;
V_135 = F_15 ( V_144 -> V_86 ) ;
V_146 = F_15 ( V_144 -> V_146 ) ;
V_147 = F_15 ( V_144 -> V_151 ) ;
if ( ( V_147 & ( F_28 ( 15 ) | F_28 ( 14 ) ) ) != ( F_28 ( 15 ) | F_28 ( 14 ) ) )
F_29 ( V_2 -> V_8 -> V_152 ,
L_21 ,
V_147 ) ;
V_147 &= ~ ( F_28 ( 15 ) | F_28 ( 14 ) ) ;
V_2 -> V_153 = F_30 ( F_15 ( V_141 -> V_130 ) - V_131 ,
sizeof( V_2 -> V_154 ) ) ;
V_144 -> V_151 = F_3 ( V_147 ) ;
memcpy ( V_2 -> V_154 , & V_141 -> V_61 , V_2 -> V_153 ) ;
if ( V_146 ) {
V_2 -> V_8 -> V_155 . V_156 ++ ;
F_2 ( V_2 -> V_8 , ERROR ,
L_22
L_23 ,
V_146 , V_135 ,
F_15 ( V_144 -> V_151 ) ) ;
F_2 ( V_2 -> V_8 , ERROR , L_24 ,
F_26 ( V_135 ) ) ;
if ( V_135 == V_138 ) {
if ( V_146 == V_157 ) {
V_27 = V_158 ;
F_2 ( V_2 -> V_8 , ERROR ,
L_25 ) ;
} else {
V_27 = V_159 ;
F_2 ( V_2 -> V_8 , ERROR ,
L_26 ) ;
}
} else {
V_27 = V_146 ;
}
goto V_36;
}
V_2 -> V_160 = true ;
V_2 -> V_8 -> V_161 = V_162 ;
V_2 -> V_8 -> V_163 = false ;
V_2 -> V_8 -> V_164 = false ;
V_15 = V_2 -> V_81 ;
F_2 ( V_2 -> V_8 , V_9 , L_27 ,
V_15 -> V_89 . V_89 ) ;
memcpy ( & V_2 -> V_99 . V_165 ,
V_15 , sizeof( struct V_14 ) ) ;
V_2 -> V_99 . V_165 . V_166
= V_15 -> V_94 . V_93 . V_95 ;
V_2 -> V_99 . V_167 = ( T_1 ) V_15 -> V_120 ;
if ( V_15 -> V_128 . V_168 . V_169 == V_170 )
V_2 -> V_99 . V_171 = true ;
else
V_2 -> V_99 . V_171 = false ;
if ( ( V_2 -> V_172 || V_15 -> V_114 ) &&
V_2 -> V_99 . V_171 )
V_2 -> V_171 = true ;
else
V_2 -> V_171 = false ;
V_2 -> V_99 . V_173 = false ;
if ( V_2 -> V_171 )
V_2 -> V_99 . V_173
= ( ( V_15 -> V_128 . V_174 &
V_175 ) ? 1 : 0 ) ;
V_148 = F_31 ( V_176 , V_144 -> V_177 ,
V_2 -> V_153
- sizeof( struct V_143 ) ) ;
if ( V_148 ) {
V_150 = (struct V_149 * ) ( V_148
+ sizeof( struct V_178 ) ) ;
V_2 -> V_179 = V_150 -> V_180 ;
V_2 -> V_181 = true ;
} else {
V_2 -> V_181 = false ;
}
F_2 ( V_2 -> V_8 , V_9 ,
L_28 ,
V_2 -> V_182 ) ;
if ( V_2 -> V_105 . V_123 || V_2 -> V_105 . V_124 )
V_2 -> V_183 = false ;
if ( V_2 -> V_171 ) {
V_145 = false ;
} else {
F_32 ( V_2 , NULL ) ;
F_33 ( V_2 ) ;
}
if ( V_145 )
F_2 ( V_2 -> V_8 , V_9 ,
L_29 ) ;
V_2 -> V_184 = 0 ;
V_2 -> V_185 = 0 ;
V_2 -> V_186 = 0 ;
V_2 -> V_187 = 0 ;
V_2 -> V_188 = 0 ;
V_2 -> V_189 = 0 ;
V_2 -> V_190 = 0 ;
V_2 -> V_191 = 0 ;
V_2 -> V_192 = 0 ;
V_2 -> V_193 = 0 ;
F_34 ( V_2 ) ;
V_2 -> V_8 -> V_155 . V_194 ++ ;
F_2 ( V_2 -> V_8 , V_9 , L_30 ) ;
F_35 ( V_2 ,
V_2 -> V_99 . V_165 . V_83 ) ;
if ( ! F_36 ( V_2 -> V_195 ) )
F_37 ( V_2 -> V_195 ) ;
F_38 ( V_2 -> V_195 , V_8 ) ;
if ( V_2 -> V_105 . V_123 || V_2 -> V_105 . V_124 )
V_2 -> V_196 = true ;
else
V_2 -> V_197 = true ;
V_36:
if ( V_8 -> V_198 -> V_199 ) {
if ( V_27 )
V_8 -> V_200 . V_201 = - 1 ;
else
V_8 -> V_200 . V_201 = 0 ;
}
return V_27 ;
}
int
F_39 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_202 * V_203 )
{
int V_53 = 0 ;
struct V_142 * V_8 = V_2 -> V_8 ;
struct V_204 * V_205 =
& V_58 -> V_61 . V_205 ;
struct V_14 * V_15 ;
T_3 V_206 = 0 ;
T_3 V_30 ;
V_54 V_77 ;
struct V_73 * V_74 ;
T_1 V_119 ;
struct V_207 * V_208 ;
struct V_209 * V_210 ;
T_1 * V_78 = ( T_1 * ) V_205 +
sizeof( struct V_204 ) ;
if ( ! V_8 )
return - 1 ;
V_58 -> V_79 = F_3 ( V_211 ) ;
V_15 = & V_2 -> V_99 . V_165 ;
V_2 -> V_81 = V_15 ;
memset ( V_205 -> V_89 , 0 , V_212 ) ;
memcpy ( V_205 -> V_89 , V_203 -> V_89 , V_203 -> V_90 ) ;
F_2 ( V_8 , V_9 , L_31 ,
V_205 -> V_89 ) ;
memset ( V_15 -> V_89 . V_89 , 0 , V_212 ) ;
memcpy ( V_15 -> V_89 . V_89 , V_203 -> V_89 , V_203 -> V_90 ) ;
V_15 -> V_89 . V_90 = V_203 -> V_90 ;
V_205 -> V_213 = V_214 ;
V_15 -> V_213 = V_215 ;
V_205 -> V_85 = F_3 ( V_2 -> V_85 ) ;
V_15 -> V_85 = V_2 -> V_85 ;
#define F_40 3
#define F_41 1
V_205 -> V_94 . V_93 . V_169 = F_40 ;
V_205 -> V_94 . V_93 . V_12 = F_41 ;
if ( ! F_42 ( V_2 , V_8 -> V_216 ,
( V_54 ) V_2 -> V_217 , 0 ) ) {
struct V_218 * V_219 ;
V_219 = F_42 ( V_2 , V_8 -> V_216 ,
V_220 , 0 ) ;
if ( V_219 )
V_2 -> V_217 = ( T_1 ) V_219 -> V_166 ;
}
if ( ! V_2 -> V_217 ) {
F_2 ( V_8 , ERROR ,
L_32 ) ;
return - 1 ;
}
F_2 ( V_8 , V_9 ,
L_33 ,
V_2 -> V_217 ) ;
V_2 -> V_99 . V_165 . V_166 = V_2 -> V_217 ;
V_2 -> V_99 . V_167 = V_8 -> V_216 ;
V_15 -> V_166 = V_2 -> V_217 ;
V_205 -> V_94 . V_93 . V_95 =
V_2 -> V_217 ;
memcpy ( & V_15 -> V_94 , & V_205 -> V_94 ,
sizeof( union V_221 ) ) ;
#define F_43 6
#define F_44 2
V_205 -> V_222 . V_223 . V_169 = F_43 ;
V_205 -> V_222 . V_223 . V_12 = F_44 ;
V_205 -> V_222 . V_223 . V_224
= F_3 ( V_2 -> V_224 ) ;
memcpy ( & V_15 -> V_222 , & V_205 -> V_222 ,
sizeof( union V_225 ) ) ;
V_15 -> V_86 |= V_226 ;
V_77 = V_226 ;
if ( V_2 -> V_105 . V_227 ) {
F_2 ( V_8 , V_9 ,
L_34 ) ;
V_15 -> V_228 = V_229 ;
V_77 |= V_230 ;
} else {
F_2 ( V_8 , V_9 ,
L_35
L_36 ) ;
V_15 -> V_228 = V_231 ;
}
memset ( V_205 -> V_34 , 0 , sizeof( V_205 -> V_34 ) ) ;
F_10 ( V_2 , V_205 -> V_34 ) ;
if ( ( V_8 -> V_216 & V_232 ) &&
( V_2 -> V_182 & V_233 ) ) {
if ( F_45 ( V_2 , V_234 ,
V_235 , 0 ,
& V_2 -> V_182 , false ) ) {
F_2 ( V_8 , ERROR ,
L_37 ) ;
return - 1 ;
}
}
for ( V_30 = 0 ; V_30 < sizeof( V_205 -> V_34 ) ; V_30 ++ )
if ( ! V_205 -> V_34 [ V_30 ] )
break;
V_2 -> V_99 . V_100 = V_30 ;
memcpy ( & V_2 -> V_99 . V_101 ,
& V_205 -> V_34 , V_2 -> V_99 . V_100 ) ;
F_2 ( V_8 , V_9 , L_38 ,
V_205 -> V_34 ) ;
F_2 ( V_8 , V_9 , L_39 ) ;
if ( F_17 ( V_8 ) ) {
V_74 = (struct V_73 * ) V_78 ;
V_74 -> V_19 . type = F_3 ( V_115 ) ;
V_74 -> V_19 . V_12 =
F_3 ( sizeof( struct V_116 ) ) ;
memset ( V_74 -> V_117 , 0x00 ,
sizeof( struct V_116 ) ) ;
V_74 -> V_117 [ 0 ] . V_118 =
( T_1 ) V_2 -> V_99 . V_165 . V_166 ;
F_2 ( V_8 , V_9 , L_40 ,
V_74 -> V_117 [ 0 ] . V_118 ) ;
V_74 -> V_117 [ 0 ] . V_119
= F_19 ( V_2 -> V_99 . V_167 ) ;
if ( V_8 -> V_216 & V_112 ||
V_8 -> V_216 & V_113 ) {
if ( V_8 -> V_236 ==
V_237 )
V_74 -> V_117 [ 0 ] . V_119 |=
( V_237 << 4 ) ;
else if ( V_8 -> V_236 ==
V_238 )
V_74 -> V_117 [ 0 ] . V_119 |=
( V_238 << 4 ) ;
}
F_2 ( V_8 , V_9 , L_41 ,
V_74 -> V_117 [ 0 ] . V_119 ) ;
V_78 += sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
V_206 +=
sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
}
V_206 += F_23 ( V_2 ,
V_239 , & V_78 ) ;
if ( V_2 -> V_105 . V_123 ) {
V_53 = F_14 ( V_2 , & V_78 ) ;
if ( V_53 == - 1 )
return - 1 ;
V_206 += V_53 ;
}
if ( V_8 -> V_240 ) {
V_208 = (struct V_207 * ) V_78 ;
memset ( V_208 , 0 , sizeof( struct V_207 ) ) ;
V_208 -> V_19 . type = F_3 ( V_241 ) ;
V_208 -> V_19 . V_12 =
F_3 ( sizeof( struct V_242 ) ) ;
V_119 = F_19 (
V_2 -> V_8 -> V_111 ) ;
F_46 ( V_2 , V_119 , & V_208 -> V_208 ) ;
if ( V_8 -> V_236 ==
V_243 ) {
V_54 V_244 ;
V_244 = F_15 ( V_208 -> V_208 . V_135 ) ;
V_244 &= ~ V_245 ;
V_244 &= ~ V_246 ;
V_208 -> V_208 . V_135 = F_3 ( V_244 ) ;
}
V_78 += sizeof( struct V_207 ) ;
V_206 += sizeof( struct V_207 ) ;
V_210 = (struct V_209 * ) V_78 ;
memset ( V_210 , 0 , sizeof( struct V_209 ) ) ;
V_210 -> V_19 . type = F_3 ( V_176 ) ;
V_210 -> V_19 . V_12 =
F_3 ( sizeof( struct V_149 ) ) ;
V_210 -> V_247 . V_248 =
( T_1 ) V_2 -> V_99 . V_165 . V_166 ;
if ( V_8 -> V_236 ) {
V_210 -> V_247 . V_180 = V_8 -> V_236 ;
V_210 -> V_247 . V_180 |=
V_249 ;
}
V_210 -> V_247 . V_250 =
F_3 ( V_251 ) ;
V_210 -> V_247 . V_252 [ 0 ] = 0xff ;
V_78 += sizeof( struct V_209 ) ;
V_206 +=
sizeof( struct V_209 ) ;
}
V_58 -> V_130 =
F_3 ( ( V_54 ) ( sizeof( struct V_204 )
+ V_131 + V_206 ) ) ;
if ( V_8 -> V_216 == V_132 )
V_77 &= ~ V_133 ;
else
V_77 |= V_133 ;
V_205 -> V_86 = F_3 ( V_77 ) ;
return 0 ;
}
int
F_47 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_14 * V_15 )
{
int V_53 = 0 ;
struct V_253 * V_254 =
& V_58 -> V_61 . V_254 ;
struct V_73 * V_74 ;
T_3 V_206 = 0 ;
V_54 V_77 ;
T_3 V_30 , V_76 = 0 ;
V_54 V_182 ;
T_1 * V_78 =
( T_1 * ) V_254 +
sizeof( struct V_253 ) ;
#define F_48 0x02
if ( V_15 -> V_255 & F_48 ) {
V_182 =
V_2 ->
V_182 | V_233 ;
if ( F_45 ( V_2 , V_234 ,
V_235 , 0 ,
& V_182 , false ) ) {
F_2 ( V_2 -> V_8 , ERROR ,
L_42 ) ;
return - 1 ;
}
}
V_2 -> V_81 = V_15 ;
V_58 -> V_79 = F_3 ( V_256 ) ;
V_254 -> V_165 . V_213 = V_214 ;
V_254 -> V_165 . V_85
= F_3 ( V_15 -> V_85 ) ;
memcpy ( & V_254 -> V_165 . V_257 ,
& V_15 -> V_83 , V_258 ) ;
memcpy ( & V_254 -> V_165 . V_89 ,
& V_15 -> V_89 . V_89 , V_15 -> V_89 . V_90 ) ;
memcpy ( & V_254 -> V_165 . V_94 ,
& V_15 -> V_94 ,
sizeof( union V_221 ) ) ;
memcpy ( & V_254 -> V_165 . V_222 ,
& V_15 -> V_222 , sizeof( union V_225 ) ) ;
V_77 = V_15 -> V_86 ;
V_77 &= V_134 ;
F_2 ( V_2 -> V_8 , V_9 ,
L_43 ,
V_77 , V_134 ) ;
F_2 ( V_2 -> V_8 , V_9 ,
L_44 ,
V_254 -> V_165 . V_257 ,
V_254 -> V_165 . V_89 ) ;
for ( V_30 = 0 ; V_30 < V_40 &&
V_15 -> V_42 [ V_30 ] ; V_30 ++ )
;
V_76 = V_30 ;
memset ( V_254 -> V_165 . V_101 , 0 ,
sizeof( V_254 -> V_165 . V_101 ) ) ;
memcpy ( V_254 -> V_165 . V_101 ,
V_15 -> V_42 , V_76 ) ;
V_2 -> V_99 . V_100 = V_76 ;
memcpy ( & V_2 -> V_99 . V_101 , V_15 -> V_42 ,
V_76 ) ;
V_2 -> V_99 . V_165 . V_166 = V_15 -> V_166 ;
V_2 -> V_99 . V_167 = ( T_1 ) V_15 -> V_120 ;
if ( V_2 -> V_105 . V_106 || V_2 -> V_105 . V_123 )
V_77 |= V_230 ;
if ( F_17 ( V_2 -> V_8 ) ) {
V_74 = (struct V_73 * ) V_78 ;
V_74 -> V_19 . type = F_3 ( V_115 ) ;
V_74 -> V_19 . V_12 =
F_3 ( sizeof( struct V_116 ) ) ;
memset ( V_74 -> V_117 , 0x00 ,
sizeof( struct V_116 ) ) ;
V_74 -> V_117 [ 0 ] . V_118 =
( V_15 -> V_94 . V_93 . V_95 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_45 ,
V_74 -> V_117 [ 0 ] . V_118 ) ;
V_74 -> V_117 [ 0 ] . V_119 =
F_19 ( ( T_1 ) V_15 -> V_120 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_46 ,
V_74 -> V_117 [ 0 ] . V_119 ) ;
V_78 += sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
V_206 += sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
}
if ( V_2 -> V_105 . V_123 )
V_53 = F_14 ( V_2 , & V_78 ) ;
if ( V_53 == - 1 )
return - 1 ;
V_206 += V_53 ;
if ( F_18 ( V_2 -> V_8 -> V_109 ) )
V_206 += F_20 ( V_2 ,
V_15 , & V_78 ) ;
V_206 += F_23 ( V_2 ,
V_239 , & V_78 ) ;
V_58 -> V_130 = F_3
( ( V_54 ) ( sizeof( struct V_253 )
+ V_131 + V_206 ) ) ;
V_254 -> V_165 . V_86 = F_3 ( V_77 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_57 * V_141 )
{
int V_27 = 0 ;
struct V_142 * V_8 = V_2 -> V_8 ;
struct V_259 * V_260 =
& V_141 -> V_61 . V_260 ;
struct V_261 * V_262 =
& V_141 -> V_61 . V_262 ;
struct V_14 * V_15 ;
V_54 V_58 = F_15 ( V_141 -> V_79 ) ;
T_1 V_263 ;
if ( ! V_2 -> V_81 ) {
F_2 ( V_2 -> V_8 , ERROR ,
L_47 ) ;
goto V_36;
}
if ( V_58 == V_211 )
V_263 = V_260 -> V_263 ;
else
V_263 = V_262 -> V_263 ;
V_15 = V_2 -> V_81 ;
if ( V_263 ) {
F_2 ( V_2 -> V_8 , ERROR , L_48 ) ;
if ( V_2 -> V_160 )
F_50 ( V_2 , V_263 , true ) ;
memset ( & V_2 -> V_99 . V_165 ,
0x00 , sizeof( struct V_14 ) ) ;
V_27 = - 1 ;
goto V_36;
}
V_2 -> V_160 = true ;
if ( F_15 ( V_141 -> V_79 ) == V_211 ) {
F_2 ( V_2 -> V_8 , V_9 , L_49 ,
V_15 -> V_89 . V_89 ) ;
memcpy ( V_15 -> V_83 ,
V_260 -> V_257 , V_258 ) ;
V_2 -> V_264 = V_265 ;
} else {
F_2 ( V_2 -> V_8 , V_9 ,
L_50 ,
V_15 -> V_89 . V_89 ) ;
memcpy ( & V_2 -> V_99 . V_165 ,
V_15 , sizeof( struct V_14 ) ) ;
V_2 -> V_264 = V_266 ;
}
F_2 ( V_2 -> V_8 , V_9 , L_51 ,
V_2 -> V_217 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_52 ,
V_2 -> V_99 . V_165 . V_83 ) ;
if ( ! F_36 ( V_2 -> V_195 ) )
F_37 ( V_2 -> V_195 ) ;
F_38 ( V_2 -> V_195 , V_8 ) ;
F_34 ( V_2 ) ;
V_36:
if ( V_8 -> V_198 -> V_199 ) {
if ( V_27 )
V_8 -> V_200 . V_201 = - 1 ;
else
V_8 -> V_200 . V_201 = 0 ;
}
return V_27 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
if ( ( F_52 ( V_2 ) != V_267 ) ||
( V_15 -> V_213 != V_268 ) )
return - 1 ;
if ( F_21 ( V_2 -> V_8 -> V_109 ) &&
! V_15 -> V_110 && ! V_15 -> V_125 &&
V_2 -> V_8 -> V_111 & V_126 )
F_53 ( V_2 ) ;
else
F_54 ( V_2 ) ;
V_2 -> V_153 = 0 ;
return F_45 ( V_2 , V_80 ,
V_235 , 0 , V_15 , true ) ;
}
int
F_55 ( struct V_1 * V_2 ,
struct V_202 * V_269 )
{
F_2 ( V_2 -> V_8 , V_9 , L_53 ,
V_2 -> V_217 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_54 ,
V_2 -> V_99 . V_165 . V_166 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_55 ,
V_2 -> V_99 . V_167 ) ;
if ( F_21 ( V_2 -> V_8 -> V_109 ) &&
V_2 -> V_8 -> V_111 & V_126 )
F_53 ( V_2 ) ;
else
F_54 ( V_2 ) ;
return F_45 ( V_2 , V_211 ,
V_235 , 0 , V_269 , true ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_2 ( V_2 -> V_8 , V_9 ,
L_56 ,
V_2 -> V_99 . V_165 . V_89 . V_89 ) ;
F_2 ( V_2 -> V_8 , V_9 ,
L_57 ,
V_2 -> V_99 . V_165 . V_89 . V_90 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_58 ,
V_15 -> V_89 . V_89 ) ;
F_2 ( V_2 -> V_8 , V_9 , L_59 ,
V_15 -> V_89 . V_90 ) ;
if ( V_2 -> V_99 . V_165 . V_89 . V_90 &&
! F_57 ( & V_15 -> V_89 ,
& V_2 -> V_99 . V_165 . V_89 ) &&
( V_2 -> V_99 . V_165 . V_213 ==
V_215 ) ) {
F_2 ( V_2 -> V_8 , V_9 ,
L_60
L_61 ) ;
return - 1 ;
}
if ( F_21 ( V_2 -> V_8 -> V_109 ) &&
! V_15 -> V_110 && ! V_15 -> V_125 &&
V_2 -> V_8 -> V_111 & V_126 )
F_53 ( V_2 ) ;
else
F_54 ( V_2 ) ;
F_2 ( V_2 -> V_8 , V_9 ,
L_54 ,
V_2 -> V_99 . V_165 . V_166 ) ;
F_2 ( V_2 -> V_8 , V_9 ,
L_62 ,
V_2 -> V_99 . V_167 ) ;
return F_45 ( V_2 , V_256 ,
V_235 , 0 , V_15 , true ) ;
}
static int F_58 ( struct V_1 * V_2 , T_1 * V_270 )
{
T_1 V_83 [ V_258 ] ;
int V_27 ;
if ( ! V_270 || F_59 ( V_270 ) )
memcpy ( V_83 ,
V_2 -> V_99 . V_165 . V_83 ,
V_258 ) ;
else
memcpy ( V_83 , V_270 , V_258 ) ;
V_27 = F_45 ( V_2 , V_271 ,
V_235 , 0 , V_83 , true ) ;
return V_27 ;
}
int F_60 ( struct V_1 * V_2 , T_1 * V_270 )
{
int V_27 = 0 ;
if ( ! V_2 -> V_160 )
return 0 ;
switch ( V_2 -> V_213 ) {
case V_268 :
case V_272 :
V_27 = F_58 ( V_2 , V_270 ) ;
if ( V_27 )
F_61 ( V_2 -> V_195 , 0 , NULL , 0 ,
true , V_32 ) ;
break;
case V_215 :
return F_45 ( V_2 , V_273 ,
V_235 , 0 , NULL , true ) ;
case V_274 :
return F_45 ( V_2 , V_275 ,
V_235 , 0 , NULL , true ) ;
default:
break;
}
return V_27 ;
}
void F_62 ( struct V_142 * V_8 )
{
struct V_1 * V_2 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_276 ; V_30 ++ ) {
V_2 = V_8 -> V_2 [ V_30 ] ;
if ( V_2 )
F_60 ( V_2 , NULL ) ;
}
}
T_1
F_19 ( T_1 V_167 )
{
switch ( V_167 ) {
case V_277 :
case V_113 :
case V_277 | V_113 :
case V_277 | V_113 | V_126 :
return V_278 ;
case V_132 :
case V_232 :
case V_132 | V_232 :
default:
return V_279 ;
}
}
