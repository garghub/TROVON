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
F_2 ( V_2 -> V_8 -> V_9 ,
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
F_2 ( V_2 -> V_8 -> V_9 ,
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
F_8 ( V_2 -> V_8 -> V_9 , L_3 ) ;
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
F_2 ( V_2 -> V_8 -> V_9 , L_4 ,
V_2 -> V_34 ) ;
if ( ! V_2 -> V_35 ) {
while ( * V_28 ) {
if ( ( * V_28 & 0x7f ) == V_2 -> V_34 ) {
V_27 = 0 ;
goto V_36;
}
V_28 ++ ;
}
F_8 ( V_2 -> V_8 -> V_9 , L_5
L_6 ,
V_2 -> V_34 ) ;
V_27 = - 1 ;
goto V_36;
}
V_27 = 0 ;
V_36:
F_9 ( V_29 ) ;
return V_27 ;
}
static int
F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
T_1 * V_37 , T_3 * V_38 )
{
T_1 V_39 [ V_40 ] ;
T_3 V_41 ;
memcpy ( V_37 , V_15 -> V_42 , V_40 ) ;
V_41 = F_11 ( V_2 , V_39 ) ;
if ( F_6 ( V_2 , V_37 , V_40 ,
V_39 , V_41 ) ) {
* V_38 = 0 ;
F_8 ( V_2 -> V_8 -> V_9 , L_7 ,
V_10 ) ;
return - 1 ;
}
* V_38 =
F_12 ( V_43 , strlen ( V_37 ) , V_40 ) ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , T_1 * * V_3 )
{
int V_44 = 0 ;
struct V_5 V_6 ;
if ( ! V_3 || ! * V_3 )
return 0 ;
if ( V_2 -> V_45 ) {
F_2 ( V_2 -> V_8 -> V_9 , L_8 ,
V_2 -> V_45 , * V_3 ) ;
V_6 . type = F_3 ( V_46 ) ;
V_6 . V_12 = F_3 ( V_2 -> V_45 ) ;
memcpy ( * V_3 , & V_6 , sizeof( V_6 ) ) ;
* V_3 += sizeof( V_6 ) ;
V_44 += sizeof( V_6 ) ;
memcpy ( * V_3 , V_2 -> V_47 , V_2 -> V_45 ) ;
* V_3 += V_2 -> V_45 ;
V_44 += V_2 -> V_45 ;
}
F_9 ( V_2 -> V_47 ) ;
V_2 -> V_45 = 0 ;
return V_44 ;
}
static int
F_14 ( struct V_1 * V_2 , T_1 * * V_3 )
{
int V_44 = 0 ;
struct V_5 V_6 ;
if ( V_3 == NULL )
return 0 ;
if ( * V_3 == NULL )
return 0 ;
if ( V_2 -> V_48 ) {
F_2 ( V_2 -> V_8 -> V_9 , L_9 ,
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
static int F_15 ( struct V_1 * V_2 ,
T_1 * * V_3 )
{
struct V_51 * V_52 ;
int V_53 ;
if ( ! V_3 || ! ( * V_3 ) )
return 0 ;
V_52 = (struct V_51 * ) ( * V_3 ) ;
V_52 -> V_19 . type = F_3 ( ( V_54 ) V_2 -> V_55 [ 0 ] ) ;
V_52 -> V_19 . type = F_3 (
F_16 ( V_52 -> V_19 . type ) & 0x00FF ) ;
V_52 -> V_19 . V_12 = F_3 ( ( V_54 ) V_2 -> V_55 [ 1 ] ) ;
V_52 -> V_19 . V_12 = F_3 ( F_16 ( V_52 -> V_19 . V_12 )
& 0x00FF ) ;
if ( F_16 ( V_52 -> V_19 . V_12 ) <= ( sizeof( V_2 -> V_55 ) - 2 ) )
memcpy ( V_52 -> V_56 , & V_2 -> V_55 [ 2 ] ,
F_16 ( V_52 -> V_19 . V_12 ) ) ;
else
return - 1 ;
V_53 = sizeof( V_52 -> V_19 ) +
F_16 ( V_52 -> V_19 . V_12 ) ;
* V_3 += V_53 ;
return V_53 ;
}
int F_17 ( struct V_1 * V_2 ,
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
F_16 ( V_64 -> V_19 . V_12 ) ) ;
V_78 += sizeof( V_64 -> V_19 ) + F_16 ( V_64 -> V_19 . V_12 ) ;
V_66 = (struct V_65 * ) V_78 ;
V_66 -> V_19 . type = F_3 ( V_91 ) ;
V_66 -> V_19 . V_12 = F_3 ( sizeof( V_66 -> V_92 . V_93 ) ) ;
memcpy ( & V_66 -> V_92 . V_93 ,
& V_15 -> V_94 . V_93 . V_95 ,
sizeof( V_66 -> V_92 . V_93 ) ) ;
V_78 += sizeof( V_66 -> V_19 ) + F_16 ( V_66 -> V_19 . V_12 ) ;
V_68 = (struct V_67 * ) V_78 ;
V_68 -> V_19 . type = F_3 ( V_96 ) ;
V_68 -> V_19 . V_12 = F_3 ( sizeof( V_68 -> V_97 . V_98 ) ) ;
V_78 += sizeof( V_68 -> V_19 ) + F_16 ( V_68 -> V_19 . V_12 ) ;
if ( F_10
( V_2 , V_15 , V_75 , & V_76 ) )
return - 1 ;
V_2 -> V_99 . V_100 = V_76 ;
memcpy ( & V_2 -> V_99 . V_101 , V_75 , V_76 ) ;
V_70 = (struct V_69 * ) V_78 ;
V_70 -> V_19 . type = F_3 ( V_102 ) ;
V_70 -> V_19 . V_12 = F_3 ( ( V_54 ) V_76 ) ;
memcpy ( V_70 -> V_75 , V_75 , V_76 ) ;
V_78 += sizeof( V_70 -> V_19 ) + V_76 ;
F_2 ( V_2 -> V_8 -> V_9 , L_10 ,
V_76 ) ;
V_72 = (struct V_71 * ) V_78 ;
V_72 -> V_19 . type = F_3 ( V_103 ) ;
V_72 -> V_19 . V_12 = F_3 ( sizeof( V_72 -> V_104 ) ) ;
if ( V_2 -> V_105 . V_106 )
V_72 -> V_104 = F_3 (
( V_54 ) V_2 -> V_105 . V_107 ) ;
else
V_72 -> V_104 = F_3 ( V_108 ) ;
V_78 += sizeof( V_72 -> V_19 ) + F_16 ( V_72 -> V_19 . V_12 ) ;
if ( F_18 ( V_2 -> V_8 ) &&
! ( F_19 ( V_2 -> V_8 -> V_109 ) &&
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
F_2 ( V_2 -> V_8 -> V_9 , L_11 ,
V_74 -> V_117 [ 0 ] . V_118 ) ;
V_74 -> V_117 [ 0 ] . V_119 =
F_20 ( ( T_1 ) V_15 -> V_120 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_12 ,
V_74 -> V_117 [ 0 ] . V_119 ) ;
V_78 += sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
}
if ( ! V_2 -> V_121 . V_122 ) {
if ( V_2 -> V_105 . V_123 || V_2 -> V_105 . V_124 )
V_53 = F_15 ( V_2 , & V_78 ) ;
if ( V_53 == - 1 )
return - 1 ;
}
if ( F_19 ( V_2 -> V_8 -> V_109 ) &&
( ! V_15 -> V_110 ) &&
( V_2 -> V_8 -> V_111 & V_112 ||
V_2 -> V_8 -> V_111 & V_113 ) )
F_21 ( V_2 , V_15 , & V_78 ) ;
if ( F_22 ( V_2 -> V_8 -> V_109 ) &&
! V_15 -> V_110 && ! V_15 -> V_125 &&
V_2 -> V_8 -> V_111 & V_126 )
F_23 ( V_2 , V_15 , & V_78 ) ;
F_24 ( V_2 , V_127 , & V_78 ) ;
F_25 ( V_2 , & V_78 , & V_15 -> V_128 ,
V_15 -> V_114 ) ;
if ( V_2 -> V_105 . V_129 && V_2 -> V_48 )
F_14 ( V_2 , & V_78 ) ;
if ( V_2 -> V_121 . V_122 && V_2 -> V_45 )
F_13 ( V_2 , & V_78 ) ;
F_1 ( V_2 , & V_78 ) ;
F_4 ( V_2 , & V_78 , V_15 ) ;
F_26 ( V_2 , & V_78 , V_15 ) ;
V_58 -> V_130 = F_3 ( ( V_54 ) ( V_78 - ( T_1 * ) V_60 ) + V_131 ) ;
V_77 = V_15 -> V_86 ;
if ( V_2 -> V_8 -> V_111 == V_132 )
V_77 &= ~ V_133 ;
V_77 &= V_134 ;
F_2 ( V_2 -> V_8 -> V_9 , L_13 ,
V_77 , V_134 ) ;
V_60 -> V_86 = F_3 ( V_77 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_57 * V_135 )
{
struct V_136 * V_8 = V_2 -> V_8 ;
int V_27 = 0 ;
struct V_137 * V_138 ;
struct V_14 * V_15 ;
bool V_139 = true ;
V_54 V_140 , V_141 ;
V_138 = (struct V_137 * ) & V_135 -> V_61 ;
V_140 = F_16 ( V_138 -> V_86 ) ;
V_141 = F_16 ( V_138 -> V_141 ) ;
V_2 -> V_142 = F_28 ( F_16 ( V_135 -> V_130 ) - V_131 ,
sizeof( V_2 -> V_143 ) ) ;
memcpy ( V_2 -> V_143 , & V_135 -> V_61 , V_2 -> V_142 ) ;
if ( V_141 ) {
V_2 -> V_8 -> V_144 . V_145 ++ ;
F_8 ( V_2 -> V_8 -> V_9 ,
L_14 ,
V_141 , V_140 , F_16 ( V_138 -> V_146 ) ) ;
if ( V_140 == V_147 ) {
if ( V_141 == V_148 )
V_27 = V_149 ;
else
V_27 = V_150 ;
} else {
V_27 = V_141 ;
}
goto V_36;
}
V_2 -> V_151 = true ;
V_2 -> V_8 -> V_152 = V_153 ;
V_2 -> V_8 -> V_154 = false ;
V_2 -> V_8 -> V_155 = false ;
V_15 = V_2 -> V_81 ;
F_2 ( V_2 -> V_8 -> V_9 , L_15 ,
V_15 -> V_89 . V_89 ) ;
memcpy ( & V_2 -> V_99 . V_156 ,
V_15 , sizeof( struct V_14 ) ) ;
V_2 -> V_99 . V_156 . V_157
= V_15 -> V_94 . V_93 . V_95 ;
V_2 -> V_99 . V_158 = ( T_1 ) V_15 -> V_120 ;
if ( V_15 -> V_128 . V_159 . V_160 == V_161 )
V_2 -> V_99 . V_162 = true ;
else
V_2 -> V_99 . V_162 = false ;
if ( ( V_2 -> V_163 || V_15 -> V_114 ) &&
V_2 -> V_99 . V_162 )
V_2 -> V_162 = true ;
else
V_2 -> V_162 = false ;
V_2 -> V_99 . V_164 = false ;
if ( V_2 -> V_162 )
V_2 -> V_99 . V_164
= ( ( V_15 -> V_128 . V_165 &
V_166 ) ? 1 : 0 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_16 ,
V_2 -> V_167 ) ;
if ( V_2 -> V_105 . V_123 || V_2 -> V_105 . V_124 )
V_2 -> V_168 = false ;
if ( V_2 -> V_162 ) {
V_139 = false ;
} else {
F_29 ( V_2 , NULL ) ;
F_30 ( V_2 ) ;
}
if ( V_139 )
F_2 ( V_2 -> V_8 -> V_9 ,
L_17 ) ;
V_2 -> V_169 = 0 ;
V_2 -> V_170 = 0 ;
V_2 -> V_171 = 0 ;
V_2 -> V_172 = 0 ;
V_2 -> V_173 = 0 ;
V_2 -> V_174 = 0 ;
V_2 -> V_175 = 0 ;
V_2 -> V_176 = 0 ;
V_2 -> V_177 = 0 ;
V_2 -> V_178 = 0 ;
F_31 ( V_2 ) ;
V_2 -> V_8 -> V_144 . V_179 ++ ;
F_2 ( V_2 -> V_8 -> V_9 , L_18 ) ;
F_32 ( V_2 ,
V_2 -> V_99 . V_156 . V_83 ) ;
if ( ! F_33 ( V_2 -> V_180 ) )
F_34 ( V_2 -> V_180 ) ;
F_35 ( V_2 -> V_180 , V_8 ) ;
if ( V_2 -> V_105 . V_123 || V_2 -> V_105 . V_124 )
V_2 -> V_181 = true ;
V_36:
if ( V_8 -> V_182 -> V_183 ) {
if ( V_27 )
V_8 -> V_184 . V_185 = - 1 ;
else
V_8 -> V_184 . V_185 = 0 ;
}
return V_27 ;
}
int
F_36 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_186 * V_187 )
{
int V_53 = 0 ;
struct V_136 * V_8 = V_2 -> V_8 ;
struct V_188 * V_189 =
& V_58 -> V_61 . V_189 ;
struct V_14 * V_15 ;
T_3 V_190 = 0 ;
T_3 V_30 ;
V_54 V_77 ;
struct V_73 * V_74 ;
T_1 V_119 ;
struct V_191 * V_192 ;
struct V_193 * V_194 ;
T_1 * V_78 = ( T_1 * ) V_189 +
sizeof( struct V_188 ) ;
if ( ! V_8 )
return - 1 ;
V_58 -> V_79 = F_3 ( V_195 ) ;
V_15 = & V_2 -> V_99 . V_156 ;
V_2 -> V_81 = V_15 ;
memset ( V_189 -> V_89 , 0 , V_196 ) ;
memcpy ( V_189 -> V_89 , V_187 -> V_89 , V_187 -> V_90 ) ;
F_2 ( V_8 -> V_9 , L_19 ,
V_189 -> V_89 ) ;
memset ( V_15 -> V_89 . V_89 , 0 , V_196 ) ;
memcpy ( V_15 -> V_89 . V_89 , V_187 -> V_89 , V_187 -> V_90 ) ;
V_15 -> V_89 . V_90 = V_187 -> V_90 ;
V_189 -> V_197 = V_198 ;
V_15 -> V_197 = V_199 ;
V_189 -> V_85 = F_3 ( V_2 -> V_85 ) ;
V_15 -> V_85 = V_2 -> V_85 ;
#define F_37 3
#define F_38 1
V_189 -> V_94 . V_93 . V_160 = F_37 ;
V_189 -> V_94 . V_93 . V_12 = F_38 ;
if ( ! F_39 ( V_2 , V_8 -> V_200 ,
( V_54 ) V_2 -> V_201 , 0 ) ) {
struct V_202 * V_203 ;
V_203 = F_39 ( V_2 , V_8 -> V_200 ,
V_204 , 0 ) ;
if ( V_203 )
V_2 -> V_201 = ( T_1 ) V_203 -> V_157 ;
}
if ( ! V_2 -> V_201 ) {
F_8 ( V_8 -> V_9 , L_20 ) ;
return - 1 ;
}
F_2 ( V_8 -> V_9 , L_21 ,
V_2 -> V_201 ) ;
V_2 -> V_99 . V_156 . V_157 = V_2 -> V_201 ;
V_2 -> V_99 . V_158 = V_8 -> V_200 ;
V_15 -> V_157 = V_2 -> V_201 ;
V_189 -> V_94 . V_93 . V_95 =
V_2 -> V_201 ;
memcpy ( & V_15 -> V_94 , & V_189 -> V_94 ,
sizeof( union V_205 ) ) ;
#define F_40 6
#define F_41 2
V_189 -> V_206 . V_207 . V_160 = F_40 ;
V_189 -> V_206 . V_207 . V_12 = F_41 ;
V_189 -> V_206 . V_207 . V_208
= F_3 ( V_2 -> V_208 ) ;
memcpy ( & V_15 -> V_206 , & V_189 -> V_206 ,
sizeof( union V_209 ) ) ;
V_15 -> V_86 |= V_210 ;
V_77 = V_210 ;
if ( V_2 -> V_105 . V_211 ) {
F_2 ( V_8 -> V_9 ,
L_22 ) ;
V_15 -> V_212 = V_213 ;
V_77 |= V_214 ;
} else {
F_2 ( V_8 -> V_9 , L_23
L_24 ) ;
V_15 -> V_212 = V_215 ;
}
memset ( V_189 -> V_34 , 0 , sizeof( V_189 -> V_34 ) ) ;
F_11 ( V_2 , V_189 -> V_34 ) ;
if ( ( V_8 -> V_200 & V_216 ) &&
( V_2 -> V_167 & V_217 ) ) {
if ( F_42 ( V_2 , V_218 ,
V_219 , 0 ,
& V_2 -> V_167 , false ) ) {
F_8 ( V_8 -> V_9 ,
L_25 ) ;
return - 1 ;
}
}
for ( V_30 = 0 ; V_30 < sizeof( V_189 -> V_34 ) ; V_30 ++ )
if ( ! V_189 -> V_34 [ V_30 ] )
break;
V_2 -> V_99 . V_100 = V_30 ;
memcpy ( & V_2 -> V_99 . V_101 ,
& V_189 -> V_34 , V_2 -> V_99 . V_100 ) ;
F_2 ( V_8 -> V_9 , L_26 ,
V_189 -> V_34 ) ;
F_2 ( V_8 -> V_9 , L_27 ) ;
if ( F_18 ( V_8 ) ) {
V_74 = (struct V_73 * ) V_78 ;
V_74 -> V_19 . type = F_3 ( V_115 ) ;
V_74 -> V_19 . V_12 =
F_3 ( sizeof( struct V_116 ) ) ;
memset ( V_74 -> V_117 , 0x00 ,
sizeof( struct V_116 ) ) ;
V_74 -> V_117 [ 0 ] . V_118 =
( T_1 ) V_2 -> V_99 . V_156 . V_157 ;
F_2 ( V_8 -> V_9 , L_28 ,
V_74 -> V_117 [ 0 ] . V_118 ) ;
V_74 -> V_117 [ 0 ] . V_119
= F_20 ( V_2 -> V_99 . V_158 ) ;
if ( V_8 -> V_200 & V_112 ||
V_8 -> V_200 & V_113 ) {
if ( V_8 -> V_220 ==
V_221 )
V_74 -> V_117 [ 0 ] . V_119 |=
( V_221 << 4 ) ;
else if ( V_8 -> V_220 ==
V_222 )
V_74 -> V_117 [ 0 ] . V_119 |=
( V_222 << 4 ) ;
}
F_2 ( V_8 -> V_9 , L_29 ,
V_74 -> V_117 [ 0 ] . V_119 ) ;
V_78 += sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
V_190 +=
sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
}
V_190 += F_24 ( V_2 ,
V_223 , & V_78 ) ;
if ( V_2 -> V_105 . V_123 ) {
V_53 = F_15 ( V_2 , & V_78 ) ;
if ( V_53 == - 1 )
return - 1 ;
V_190 += V_53 ;
}
if ( V_8 -> V_224 ) {
V_192 = (struct V_191 * ) V_78 ;
memset ( V_192 , 0 , sizeof( struct V_191 ) ) ;
V_192 -> V_19 . type = F_3 ( V_225 ) ;
V_192 -> V_19 . V_12 =
F_3 ( sizeof( struct V_226 ) ) ;
V_119 = F_20 (
V_2 -> V_8 -> V_111 ) ;
F_43 ( V_2 , V_119 , & V_192 -> V_192 ) ;
if ( V_8 -> V_220 ==
V_227 ) {
V_54 V_228 ;
V_228 = F_16 ( V_192 -> V_192 . V_140 ) ;
V_228 &= ~ V_229 ;
V_228 &= ~ V_230 ;
V_192 -> V_192 . V_140 = F_3 ( V_228 ) ;
}
V_78 += sizeof( struct V_191 ) ;
V_190 += sizeof( struct V_191 ) ;
V_194 = (struct V_193 * ) V_78 ;
memset ( V_194 , 0 , sizeof( struct V_193 ) ) ;
V_194 -> V_19 . type = F_3 ( V_231 ) ;
V_194 -> V_19 . V_12 =
F_3 ( sizeof( struct V_232 ) ) ;
V_194 -> V_233 . V_234 =
( T_1 ) V_2 -> V_99 . V_156 . V_157 ;
if ( V_8 -> V_220 ) {
V_194 -> V_233 . V_235 = V_8 -> V_220 ;
V_194 -> V_233 . V_235 |=
V_236 ;
}
V_194 -> V_233 . V_237 =
F_3 ( V_238 ) ;
V_194 -> V_233 . V_239 [ 0 ] = 0xff ;
V_78 += sizeof( struct V_193 ) ;
V_190 +=
sizeof( struct V_193 ) ;
}
V_58 -> V_130 =
F_3 ( ( V_54 ) ( sizeof( struct V_188 )
+ V_131 + V_190 ) ) ;
if ( V_8 -> V_200 == V_132 )
V_77 &= ~ V_133 ;
else
V_77 |= V_133 ;
V_189 -> V_86 = F_3 ( V_77 ) ;
return 0 ;
}
int
F_44 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_14 * V_15 )
{
int V_53 = 0 ;
struct V_240 * V_241 =
& V_58 -> V_61 . V_241 ;
struct V_73 * V_74 ;
T_3 V_190 = 0 ;
V_54 V_77 ;
T_3 V_30 , V_76 = 0 ;
V_54 V_167 ;
T_1 * V_78 =
( T_1 * ) V_241 +
sizeof( struct V_240 ) ;
#define F_45 0x02
if ( V_15 -> V_242 & F_45 ) {
V_167 =
V_2 ->
V_167 | V_217 ;
if ( F_42 ( V_2 , V_218 ,
V_219 , 0 ,
& V_167 , false ) ) {
F_8 ( V_2 -> V_8 -> V_9 ,
L_30 ) ;
return - 1 ;
}
}
V_2 -> V_81 = V_15 ;
V_58 -> V_79 = F_3 ( V_243 ) ;
V_241 -> V_156 . V_197 = V_198 ;
V_241 -> V_156 . V_85
= F_3 ( V_15 -> V_85 ) ;
memcpy ( & V_241 -> V_156 . V_244 ,
& V_15 -> V_83 , V_245 ) ;
memcpy ( & V_241 -> V_156 . V_89 ,
& V_15 -> V_89 . V_89 , V_15 -> V_89 . V_90 ) ;
memcpy ( & V_241 -> V_156 . V_94 ,
& V_15 -> V_94 ,
sizeof( union V_205 ) ) ;
memcpy ( & V_241 -> V_156 . V_206 ,
& V_15 -> V_206 , sizeof( union V_209 ) ) ;
V_77 = V_15 -> V_86 ;
V_77 &= V_134 ;
F_2 ( V_2 -> V_8 -> V_9 ,
L_31 ,
V_77 , V_134 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_32 ,
V_241 -> V_156 . V_244 ,
V_241 -> V_156 . V_89 ) ;
for ( V_30 = 0 ; V_30 < V_40 &&
V_15 -> V_42 [ V_30 ] ; V_30 ++ )
;
V_76 = V_30 ;
memset ( V_241 -> V_156 . V_101 , 0 ,
sizeof( V_241 -> V_156 . V_101 ) ) ;
memcpy ( V_241 -> V_156 . V_101 ,
V_15 -> V_42 , V_76 ) ;
V_2 -> V_99 . V_100 = V_76 ;
memcpy ( & V_2 -> V_99 . V_101 , V_15 -> V_42 ,
V_76 ) ;
V_2 -> V_99 . V_156 . V_157 = V_15 -> V_157 ;
V_2 -> V_99 . V_158 = ( T_1 ) V_15 -> V_120 ;
if ( V_2 -> V_105 . V_106 || V_2 -> V_105 . V_123 )
V_77 |= V_214 ;
if ( F_18 ( V_2 -> V_8 ) ) {
V_74 = (struct V_73 * ) V_78 ;
V_74 -> V_19 . type = F_3 ( V_115 ) ;
V_74 -> V_19 . V_12 =
F_3 ( sizeof( struct V_116 ) ) ;
memset ( V_74 -> V_117 , 0x00 ,
sizeof( struct V_116 ) ) ;
V_74 -> V_117 [ 0 ] . V_118 =
( V_15 -> V_94 . V_93 . V_95 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_33 ,
V_74 -> V_117 [ 0 ] . V_118 ) ;
V_74 -> V_117 [ 0 ] . V_119 =
F_20 ( ( T_1 ) V_15 -> V_120 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_34 ,
V_74 -> V_117 [ 0 ] . V_119 ) ;
V_78 += sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
V_190 += sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
}
if ( V_2 -> V_105 . V_123 )
V_53 = F_15 ( V_2 , & V_78 ) ;
if ( V_53 == - 1 )
return - 1 ;
V_190 += V_53 ;
if ( F_19 ( V_2 -> V_8 -> V_109 ) )
V_190 += F_21 ( V_2 ,
V_15 , & V_78 ) ;
V_190 += F_24 ( V_2 ,
V_223 , & V_78 ) ;
V_58 -> V_130 = F_3
( ( V_54 ) ( sizeof( struct V_240 )
+ V_131 + V_190 ) ) ;
V_241 -> V_156 . V_86 = F_3 ( V_77 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_57 * V_135 )
{
int V_27 = 0 ;
struct V_136 * V_8 = V_2 -> V_8 ;
struct V_246 * V_247 ;
struct V_14 * V_15 ;
V_54 V_248 ;
V_247 = & V_135 -> V_61 . V_247 ;
V_15 = V_2 -> V_81 ;
V_248 = F_16 ( V_135 -> V_249 ) ;
if ( V_248 ) {
F_8 ( V_2 -> V_8 -> V_9 , L_35 ) ;
if ( V_2 -> V_151 )
F_47 ( V_2 , V_248 ) ;
memset ( & V_2 -> V_99 . V_156 ,
0x00 , sizeof( struct V_14 ) ) ;
V_27 = - 1 ;
goto V_36;
}
V_2 -> V_151 = true ;
if ( F_16 ( V_135 -> V_79 ) == V_195 ) {
F_2 ( V_2 -> V_8 -> V_9 , L_36 ,
V_15 -> V_89 . V_89 ) ;
memcpy ( V_15 -> V_83 ,
V_247 -> V_244 , V_245 ) ;
V_2 -> V_250 = V_251 ;
} else {
F_2 ( V_2 -> V_8 -> V_9 , L_37 ,
V_15 -> V_89 . V_89 ) ;
memcpy ( & V_2 -> V_99 . V_156 ,
V_15 , sizeof( struct V_14 ) ) ;
V_2 -> V_250 = V_252 ;
}
F_2 ( V_2 -> V_8 -> V_9 , L_38 ,
V_2 -> V_201 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_39 ,
V_2 -> V_99 . V_156 . V_83 ) ;
if ( ! F_33 ( V_2 -> V_180 ) )
F_34 ( V_2 -> V_180 ) ;
F_35 ( V_2 -> V_180 , V_8 ) ;
F_31 ( V_2 ) ;
V_36:
if ( V_8 -> V_182 -> V_183 ) {
if ( V_27 )
V_8 -> V_184 . V_185 = - 1 ;
else
V_8 -> V_184 . V_185 = 0 ;
}
return V_27 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
if ( ( F_49 ( V_2 ) != V_253 ) ||
( V_15 -> V_197 != V_254 ) )
return - 1 ;
if ( F_22 ( V_2 -> V_8 -> V_109 ) &&
! V_15 -> V_110 && ! V_15 -> V_125 &&
V_2 -> V_8 -> V_111 & V_126 )
F_50 ( V_2 ) ;
else
F_51 ( V_2 ) ;
V_2 -> V_142 = 0 ;
return F_42 ( V_2 , V_80 ,
V_219 , 0 , V_15 , true ) ;
}
int
F_52 ( struct V_1 * V_2 ,
struct V_186 * V_255 )
{
F_2 ( V_2 -> V_8 -> V_9 , L_40 ,
V_2 -> V_201 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_41 ,
V_2 -> V_99 . V_156 . V_157 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_42 ,
V_2 -> V_99 . V_158 ) ;
if ( F_22 ( V_2 -> V_8 -> V_109 ) &&
V_2 -> V_8 -> V_111 & V_126 )
F_50 ( V_2 ) ;
else
F_51 ( V_2 ) ;
return F_42 ( V_2 , V_195 ,
V_219 , 0 , V_255 , true ) ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_2 ( V_2 -> V_8 -> V_9 , L_43 ,
V_2 -> V_99 . V_156 . V_89 . V_89 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_44 ,
V_2 -> V_99 . V_156 . V_89 . V_90 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_45 ,
V_15 -> V_89 . V_89 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_46 ,
V_15 -> V_89 . V_90 ) ;
if ( V_2 -> V_99 . V_156 . V_89 . V_90 &&
! F_54 ( & V_15 -> V_89 ,
& V_2 -> V_99 . V_156 . V_89 ) &&
( V_2 -> V_99 . V_156 . V_197 ==
V_199 ) ) {
F_2 ( V_2 -> V_8 -> V_9 , L_47
L_48 ) ;
return - 1 ;
}
if ( F_22 ( V_2 -> V_8 -> V_109 ) &&
! V_15 -> V_110 && ! V_15 -> V_125 &&
V_2 -> V_8 -> V_111 & V_126 )
F_50 ( V_2 ) ;
else
F_51 ( V_2 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_41 ,
V_2 -> V_99 . V_156 . V_157 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_49 ,
V_2 -> V_99 . V_158 ) ;
return F_42 ( V_2 , V_243 ,
V_219 , 0 , V_15 , true ) ;
}
static int F_55 ( struct V_1 * V_2 , T_1 * V_256 )
{
T_1 V_83 [ V_245 ] ;
int V_27 ;
if ( ! V_256 || F_56 ( V_256 ) )
memcpy ( V_83 ,
V_2 -> V_99 . V_156 . V_83 ,
V_245 ) ;
else
memcpy ( V_83 , V_256 , V_245 ) ;
V_27 = F_42 ( V_2 , V_257 ,
V_219 , 0 , V_83 , true ) ;
return V_27 ;
}
int F_57 ( struct V_1 * V_2 , T_1 * V_256 )
{
int V_27 = 0 ;
if ( ! V_2 -> V_151 )
return 0 ;
switch ( V_2 -> V_197 ) {
case V_254 :
case V_258 :
V_27 = F_55 ( V_2 , V_256 ) ;
if ( V_27 )
F_58 ( V_2 -> V_180 , 0 , NULL , 0 ,
V_32 ) ;
break;
case V_199 :
return F_42 ( V_2 , V_259 ,
V_219 , 0 , NULL , true ) ;
case V_260 :
return F_42 ( V_2 , V_261 ,
V_219 , 0 , NULL , true ) ;
default:
break;
}
return V_27 ;
}
void F_59 ( struct V_136 * V_8 )
{
struct V_1 * V_2 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_262 ; V_30 ++ ) {
V_2 = V_8 -> V_2 [ V_30 ] ;
if ( V_2 )
F_57 ( V_2 , NULL ) ;
}
}
T_1
F_20 ( T_1 V_158 )
{
switch ( V_158 ) {
case V_263 :
case V_113 :
case V_263 | V_113 :
case V_263 | V_113 | V_126 :
return V_264 ;
case V_132 :
case V_216 :
case V_132 | V_216 :
default:
return V_265 ;
}
}
