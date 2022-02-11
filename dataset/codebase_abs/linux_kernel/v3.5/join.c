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
for ( V_30 = 0 ; V_25 [ V_30 ] && V_30 < V_26 ; V_30 ++ ) {
for ( V_31 = 0 ; V_29 [ V_31 ] && V_31 < V_24 ; V_31 ++ ) {
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
F_18 ( V_2 , V_15 ) ;
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
if ( F_19 ( V_2 -> V_8 ) &&
! ( F_20 ( V_2 -> V_8 -> V_109 ) &&
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
F_21 ( ( T_1 ) V_15 -> V_120 ) ;
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
if ( F_20 ( V_2 -> V_8 -> V_109 ) &&
( ! V_15 -> V_110 ) &&
( V_2 -> V_8 -> V_111 & V_112 ||
V_2 -> V_8 -> V_111 & V_113 ) )
F_22 ( V_2 , V_15 , & V_78 ) ;
F_23 ( V_2 , V_125 , & V_78 ) ;
F_24 ( V_2 , & V_78 , & V_15 -> V_126 ,
V_15 -> V_114 ) ;
if ( V_2 -> V_105 . V_127 && V_2 -> V_48 )
F_14 ( V_2 , & V_78 ) ;
if ( V_2 -> V_121 . V_122 && V_2 -> V_45 )
F_13 ( V_2 , & V_78 ) ;
F_1 ( V_2 , & V_78 ) ;
F_4 ( V_2 , & V_78 , V_15 ) ;
V_58 -> V_128 = F_3 ( ( V_54 ) ( V_78 - ( T_1 * ) V_60 ) + V_129 ) ;
V_77 = V_15 -> V_86 ;
if ( V_2 -> V_8 -> V_111 == V_130 )
V_77 &= ~ V_131 ;
V_77 &= V_132 ;
F_2 ( V_2 -> V_8 -> V_9 , L_13 ,
V_77 , V_132 ) ;
V_60 -> V_86 = F_3 ( V_77 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_57 * V_133 )
{
struct V_134 * V_8 = V_2 -> V_8 ;
int V_27 = 0 ;
struct V_135 * V_136 ;
struct V_14 * V_15 ;
T_1 V_137 = true ;
V_136 = (struct V_135 * ) & V_133 -> V_61 ;
V_2 -> V_138 = F_26 ( F_16 ( V_133 -> V_128 ) - V_129 ,
sizeof( V_2 -> V_139 ) ) ;
memcpy ( V_2 -> V_139 , & V_133 -> V_61 , V_2 -> V_138 ) ;
if ( F_16 ( V_136 -> V_140 ) ) {
V_2 -> V_8 -> V_141 . V_142 ++ ;
F_8 ( V_2 -> V_8 -> V_9 ,
L_14 ,
F_16 ( V_136 -> V_140 ) ,
F_16 ( V_136 -> V_86 ) ,
F_16 ( V_136 -> V_143 ) ) ;
V_27 = F_16 ( V_136 -> V_140 ) ;
goto V_36;
}
V_2 -> V_144 = true ;
V_2 -> V_8 -> V_145 = V_146 ;
V_2 -> V_8 -> V_147 = false ;
V_2 -> V_8 -> V_148 = false ;
V_15 = V_2 -> V_81 ;
F_2 ( V_2 -> V_8 -> V_9 , L_15 ,
V_15 -> V_89 . V_89 ) ;
memcpy ( & V_2 -> V_99 . V_149 ,
V_15 , sizeof( struct V_14 ) ) ;
V_2 -> V_99 . V_149 . V_150
= V_15 -> V_94 . V_93 . V_95 ;
V_2 -> V_99 . V_151 = ( T_1 ) V_15 -> V_120 ;
if ( V_15 -> V_126 . V_152 . V_153 == V_154 )
V_2 -> V_99 . V_155 = true ;
else
V_2 -> V_99 . V_155 = false ;
if ( ( V_2 -> V_156 || V_15 -> V_114 ) &&
V_2 -> V_99 . V_155 )
V_2 -> V_155 = true ;
else
V_2 -> V_155 = false ;
V_2 -> V_99 . V_157 = false ;
if ( V_2 -> V_155 )
V_2 -> V_99 . V_157
= ( ( V_15 -> V_126 . V_158 &
V_159 ) ? 1 : 0 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_16 ,
V_2 -> V_160 ) ;
if ( V_2 -> V_105 . V_123 || V_2 -> V_105 . V_124 )
V_2 -> V_161 = false ;
if ( V_2 -> V_155 ) {
V_137 = false ;
} else {
F_27 ( V_2 , NULL ) ;
F_28 ( V_2 ) ;
}
if ( V_137 )
F_2 ( V_2 -> V_8 -> V_9 ,
L_17 ) ;
V_2 -> V_162 = 0 ;
V_2 -> V_163 = 0 ;
V_2 -> V_164 = 0 ;
V_2 -> V_165 = 0 ;
V_2 -> V_166 = 0 ;
V_2 -> V_167 = 0 ;
V_2 -> V_168 = 0 ;
V_2 -> V_169 = 0 ;
V_2 -> V_170 = 0 ;
V_2 -> V_171 = 0 ;
F_29 ( V_2 ) ;
V_2 -> V_8 -> V_141 . V_172 ++ ;
F_2 ( V_2 -> V_8 -> V_9 , L_18 ) ;
F_30 ( V_2 ,
V_2 -> V_99 . V_149 . V_83 ) ;
if ( ! F_31 ( V_2 -> V_173 ) )
F_32 ( V_2 -> V_173 ) ;
if ( F_33 ( V_2 -> V_173 ) )
F_34 ( V_2 -> V_173 ) ;
if ( V_2 -> V_105 . V_123 || V_2 -> V_105 . V_124 )
V_2 -> V_174 = true ;
V_36:
if ( V_8 -> V_175 -> V_176 ) {
if ( V_27 )
V_8 -> V_177 . V_178 = - 1 ;
else
V_8 -> V_177 . V_178 = 0 ;
}
return V_27 ;
}
int
F_35 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_179 * V_180 )
{
int V_53 = 0 ;
struct V_134 * V_8 = V_2 -> V_8 ;
struct V_181 * V_182 =
& V_58 -> V_61 . V_182 ;
struct V_14 * V_15 ;
T_3 V_183 = 0 ;
T_3 V_30 ;
V_54 V_77 ;
struct V_73 * V_74 ;
T_1 V_119 ;
struct V_184 * V_185 ;
struct V_186 * V_187 ;
T_1 * V_78 = ( T_1 * ) V_182 +
sizeof( struct V_181 ) ;
if ( ! V_8 )
return - 1 ;
V_58 -> V_79 = F_3 ( V_188 ) ;
V_15 = & V_2 -> V_99 . V_149 ;
V_2 -> V_81 = V_15 ;
memset ( V_182 -> V_89 , 0 , V_189 ) ;
memcpy ( V_182 -> V_89 , V_180 -> V_89 , V_180 -> V_90 ) ;
F_2 ( V_8 -> V_9 , L_19 ,
V_182 -> V_89 ) ;
memset ( V_15 -> V_89 . V_89 , 0 , V_189 ) ;
memcpy ( V_15 -> V_89 . V_89 , V_180 -> V_89 , V_180 -> V_90 ) ;
V_15 -> V_89 . V_90 = V_180 -> V_90 ;
V_182 -> V_190 = V_191 ;
V_15 -> V_190 = V_192 ;
V_182 -> V_85 = F_3 ( V_2 -> V_85 ) ;
V_15 -> V_85 = V_2 -> V_85 ;
#define F_36 3
#define F_37 1
V_182 -> V_94 . V_93 . V_153 = F_36 ;
V_182 -> V_94 . V_93 . V_12 = F_37 ;
if ( ! F_38 ( V_2 , V_8 -> V_193 ,
( V_54 ) V_2 -> V_194 , 0 ) ) {
struct V_195 * V_196 ;
V_196 = F_38 ( V_2 , V_8 -> V_193 ,
V_197 , 0 ) ;
if ( V_196 )
V_2 -> V_194 = ( T_1 ) V_196 -> V_150 ;
}
if ( ! V_2 -> V_194 ) {
F_8 ( V_8 -> V_9 , L_20 ) ;
return - 1 ;
}
F_2 ( V_8 -> V_9 , L_21 ,
V_2 -> V_194 ) ;
V_2 -> V_99 . V_149 . V_150 = V_2 -> V_194 ;
V_2 -> V_99 . V_151 = V_8 -> V_193 ;
V_15 -> V_150 = V_2 -> V_194 ;
V_182 -> V_94 . V_93 . V_95 =
V_2 -> V_194 ;
memcpy ( & V_15 -> V_94 , & V_182 -> V_94 ,
sizeof( union V_198 ) ) ;
#define F_39 6
#define F_40 2
V_182 -> V_199 . V_200 . V_153 = F_39 ;
V_182 -> V_199 . V_200 . V_12 = F_40 ;
V_182 -> V_199 . V_200 . V_201
= F_3 ( V_2 -> V_201 ) ;
memcpy ( & V_15 -> V_199 , & V_182 -> V_199 ,
sizeof( union V_202 ) ) ;
V_15 -> V_86 |= V_203 ;
V_77 = F_16 ( V_182 -> V_86 ) ;
V_77 &= ~ V_204 ;
V_77 |= V_203 ;
if ( V_2 -> V_105 . V_205 ) {
F_2 ( V_8 -> V_9 ,
L_22 ) ;
V_15 -> V_206 = V_207 ;
V_77 |= V_208 ;
} else {
F_2 ( V_8 -> V_9 , L_23
L_24 ) ;
V_15 -> V_206 = V_209 ;
}
memset ( V_182 -> V_34 , 0 , sizeof( V_182 -> V_34 ) ) ;
F_11 ( V_2 , V_182 -> V_34 ) ;
if ( ( V_8 -> V_193 & V_210 ) &&
( V_2 -> V_160 & V_211 ) ) {
if ( F_41 ( V_2 , V_212 ,
V_213 , 0 ,
& V_2 -> V_160 ) ) {
F_8 ( V_8 -> V_9 ,
L_25 ) ;
return - 1 ;
}
}
for ( V_30 = 0 ; V_30 < sizeof( V_182 -> V_34 ) ; V_30 ++ )
if ( ! V_182 -> V_34 [ V_30 ] )
break;
V_2 -> V_99 . V_100 = V_30 ;
memcpy ( & V_2 -> V_99 . V_101 ,
& V_182 -> V_34 , V_2 -> V_99 . V_100 ) ;
F_2 ( V_8 -> V_9 , L_26 ,
V_182 -> V_34 [ 0 ] , V_182 -> V_34 [ 1 ] ,
V_182 -> V_34 [ 2 ] , V_182 -> V_34 [ 3 ] ) ;
F_2 ( V_8 -> V_9 , L_27 ) ;
if ( F_19 ( V_8 ) ) {
V_74 = (struct V_73 * ) V_78 ;
V_74 -> V_19 . type = F_3 ( V_115 ) ;
V_74 -> V_19 . V_12 =
F_3 ( sizeof( struct V_116 ) ) ;
memset ( V_74 -> V_117 , 0x00 ,
sizeof( struct V_116 ) ) ;
V_74 -> V_117 [ 0 ] . V_118 =
( T_1 ) V_2 -> V_99 . V_149 . V_150 ;
F_2 ( V_8 -> V_9 , L_28 ,
V_74 -> V_117 [ 0 ] . V_118 ) ;
V_74 -> V_117 [ 0 ] . V_119
= F_21 ( V_2 -> V_99 . V_151 ) ;
if ( V_8 -> V_193 & V_112 ||
V_8 -> V_193 & V_113 ) {
if ( V_8 -> V_214 ==
V_215 )
V_74 -> V_117 [ 0 ] . V_119 |=
( V_215 << 4 ) ;
else if ( V_8 -> V_214 ==
V_215 )
V_74 -> V_117 [ 0 ] . V_119 |=
( V_216 << 4 ) ;
}
F_2 ( V_8 -> V_9 , L_29 ,
V_74 -> V_117 [ 0 ] . V_119 ) ;
V_78 += sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
V_183 +=
sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
}
V_183 += F_23 ( V_2 ,
V_217 , & V_78 ) ;
if ( V_2 -> V_105 . V_123 ) {
V_53 = F_15 ( V_2 , & V_78 ) ;
if ( V_53 == - 1 )
return - 1 ;
V_183 += V_53 ;
}
if ( V_8 -> V_218 ) {
V_185 = (struct V_184 * ) V_78 ;
memset ( V_185 , 0 , sizeof( struct V_184 ) ) ;
V_185 -> V_19 . type = F_3 ( V_219 ) ;
V_185 -> V_19 . V_12 =
F_3 ( sizeof( struct V_220 ) ) ;
V_119 = F_21 (
V_2 -> V_8 -> V_111 ) ;
F_42 ( V_2 , V_119 , V_185 ) ;
V_78 += sizeof( struct V_184 ) ;
V_183 += sizeof( struct V_184 ) ;
V_187 = (struct V_186 * ) V_78 ;
memset ( V_187 , 0 , sizeof( struct V_186 ) ) ;
V_187 -> V_19 . type = F_3 ( V_221 ) ;
V_187 -> V_19 . V_12 =
F_3 ( sizeof( struct V_222 ) ) ;
V_187 -> V_223 . V_224 =
( T_1 ) V_2 -> V_99 . V_149 . V_150 ;
if ( V_8 -> V_214 ) {
V_187 -> V_223 . V_225 = V_8 -> V_214 ;
V_187 -> V_223 . V_225 |=
V_226 ;
}
V_187 -> V_223 . V_227 =
F_3 ( V_228 ) ;
V_187 -> V_223 . V_229 [ 0 ] = 0xff ;
V_78 += sizeof( struct V_186 ) ;
V_183 +=
sizeof( struct V_186 ) ;
}
V_58 -> V_128 =
F_3 ( ( V_54 ) ( sizeof( struct V_181 )
+ V_129 + V_183 ) ) ;
if ( V_8 -> V_193 == V_130 )
V_77 &= ~ V_131 ;
else
V_77 |= V_131 ;
V_182 -> V_86 = F_3 ( V_77 ) ;
return 0 ;
}
int
F_43 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_14 * V_15 )
{
int V_53 = 0 ;
struct V_230 * V_231 =
& V_58 -> V_61 . V_231 ;
struct V_73 * V_74 ;
T_3 V_183 = 0 ;
V_54 V_77 ;
T_3 V_30 , V_76 = 0 ;
V_54 V_160 ;
T_1 * V_78 =
( T_1 * ) V_231 +
sizeof( struct V_230 ) ;
#define F_44 0x02
if ( V_15 -> V_232 & F_44 ) {
V_160 =
V_2 ->
V_160 | V_211 ;
if ( F_41 ( V_2 , V_212 ,
V_213 , 0 ,
& V_160 ) ) {
F_8 ( V_2 -> V_8 -> V_9 ,
L_30 ) ;
return - 1 ;
}
}
V_2 -> V_81 = V_15 ;
V_58 -> V_79 = F_3 ( V_233 ) ;
V_231 -> V_149 . V_190 = V_191 ;
V_231 -> V_149 . V_85
= F_3 ( V_15 -> V_85 ) ;
memcpy ( & V_231 -> V_149 . V_234 ,
& V_15 -> V_83 , V_235 ) ;
memcpy ( & V_231 -> V_149 . V_89 ,
& V_15 -> V_89 . V_89 , V_15 -> V_89 . V_90 ) ;
memcpy ( & V_231 -> V_149 . V_94 ,
& V_15 -> V_94 ,
sizeof( union V_198 ) ) ;
memcpy ( & V_231 -> V_149 . V_199 ,
& V_15 -> V_199 , sizeof( union V_202 ) ) ;
V_77 = V_15 -> V_86 ;
V_77 &= V_132 ;
F_2 ( V_2 -> V_8 -> V_9 ,
L_31 ,
V_77 , V_132 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_32 ,
V_231 -> V_149 . V_234 ,
V_231 -> V_149 . V_89 ) ;
for ( V_30 = 0 ; V_15 -> V_42 [ V_30 ] &&
V_30 < V_40 ;
V_30 ++ )
;
V_76 = V_30 ;
memset ( V_231 -> V_149 . V_101 , 0 ,
sizeof( V_231 -> V_149 . V_101 ) ) ;
memcpy ( V_231 -> V_149 . V_101 ,
V_15 -> V_42 , V_76 ) ;
V_2 -> V_99 . V_100 = V_76 ;
memcpy ( & V_2 -> V_99 . V_101 , V_15 -> V_42 ,
V_76 ) ;
V_2 -> V_99 . V_149 . V_150 = V_15 -> V_150 ;
V_2 -> V_99 . V_151 = ( T_1 ) V_15 -> V_120 ;
if ( V_2 -> V_105 . V_106 || V_2 -> V_105 . V_123 )
V_77 |= V_208 ;
if ( F_19 ( V_2 -> V_8 ) ) {
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
F_21 ( ( T_1 ) V_15 -> V_120 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_34 ,
V_74 -> V_117 [ 0 ] . V_119 ) ;
V_78 += sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
V_183 += sizeof( V_74 -> V_19 ) +
sizeof( struct V_116 ) ;
}
if ( V_2 -> V_105 . V_123 )
V_53 = F_15 ( V_2 , & V_78 ) ;
if ( V_53 == - 1 )
return - 1 ;
V_183 += V_53 ;
if ( F_20 ( V_2 -> V_8 -> V_109 ) )
V_183 += F_22 ( V_2 ,
V_15 , & V_78 ) ;
V_183 += F_23 ( V_2 ,
V_217 , & V_78 ) ;
V_58 -> V_128 = F_3
( ( V_54 ) ( sizeof( struct V_230 )
+ V_129 + V_183 ) ) ;
V_231 -> V_149 . V_86 = F_3 ( V_77 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_57 * V_133 )
{
int V_27 = 0 ;
struct V_134 * V_8 = V_2 -> V_8 ;
struct V_236 * V_237 ;
struct V_14 * V_15 ;
V_237 = & V_133 -> V_61 . V_237 ;
V_15 = V_2 -> V_81 ;
if ( F_16 ( V_133 -> V_238 ) ) {
F_8 ( V_2 -> V_8 -> V_9 , L_35 ) ;
if ( V_2 -> V_144 )
F_46 ( V_2 ) ;
memset ( & V_2 -> V_99 . V_149 ,
0x00 , sizeof( struct V_14 ) ) ;
V_27 = - 1 ;
goto V_36;
}
V_2 -> V_144 = true ;
if ( F_16 ( V_133 -> V_79 ) == V_188 ) {
F_2 ( V_2 -> V_8 -> V_9 , L_36 ,
V_15 -> V_89 . V_89 ) ;
memcpy ( V_15 -> V_83 ,
V_237 -> V_234 , V_235 ) ;
V_2 -> V_239 = V_240 ;
} else {
F_2 ( V_2 -> V_8 -> V_9 , L_37 ,
V_15 -> V_89 . V_89 ) ;
memcpy ( & V_2 -> V_99 . V_149 ,
V_15 , sizeof( struct V_14 ) ) ;
V_2 -> V_239 = V_241 ;
}
F_2 ( V_2 -> V_8 -> V_9 , L_38 ,
V_2 -> V_194 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_39 ,
V_2 -> V_99 . V_149 . V_83 ) ;
if ( ! F_31 ( V_2 -> V_173 ) )
F_32 ( V_2 -> V_173 ) ;
if ( F_33 ( V_2 -> V_173 ) )
F_34 ( V_2 -> V_173 ) ;
F_29 ( V_2 ) ;
V_36:
if ( V_8 -> V_175 -> V_176 ) {
if ( V_27 )
V_8 -> V_177 . V_178 = - 1 ;
else
V_8 -> V_177 . V_178 = 0 ;
}
return V_27 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
T_1 V_242 [ V_235 ] ;
if ( ( V_2 -> V_190 != V_243 ) ||
( V_15 -> V_190 != V_243 ) )
return - 1 ;
memcpy ( & V_242 ,
& V_2 -> V_99 . V_149 . V_83 ,
sizeof( V_242 ) ) ;
V_2 -> V_138 = 0 ;
return F_48 ( V_2 , V_80 ,
V_213 , 0 , V_15 ) ;
}
int
F_49 ( struct V_1 * V_2 ,
struct V_179 * V_244 )
{
F_2 ( V_2 -> V_8 -> V_9 , L_40 ,
V_2 -> V_194 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_41 ,
V_2 -> V_99 . V_149 . V_150 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_42 ,
V_2 -> V_99 . V_151 ) ;
return F_48 ( V_2 , V_188 ,
V_213 , 0 , V_244 ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_2 ( V_2 -> V_8 -> V_9 , L_43 ,
V_2 -> V_99 . V_149 . V_89 . V_89 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_44 ,
V_2 -> V_99 . V_149 . V_89 . V_90 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_45 ,
V_15 -> V_89 . V_89 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_46 ,
V_15 -> V_89 . V_90 ) ;
if ( V_2 -> V_99 . V_149 . V_89 . V_90 &&
! F_51 ( & V_15 -> V_89 ,
& V_2 -> V_99 . V_149 . V_89 ) &&
( V_2 -> V_99 . V_149 . V_190 ==
V_192 ) ) {
F_2 ( V_2 -> V_8 -> V_9 , L_47
L_48 ) ;
return - 1 ;
}
F_2 ( V_2 -> V_8 -> V_9 , L_41 ,
V_2 -> V_99 . V_149 . V_150 ) ;
F_2 ( V_2 -> V_8 -> V_9 , L_49 ,
V_2 -> V_99 . V_151 ) ;
return F_48 ( V_2 , V_233 ,
V_213 , 0 , V_15 ) ;
}
static int F_52 ( struct V_1 * V_2 , T_1 * V_245 )
{
T_1 V_83 [ V_235 ] ;
int V_27 ;
T_1 V_246 [ V_235 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( V_245 ) {
if ( ! memcmp ( V_245 , V_246 , sizeof( V_246 ) ) )
memcpy ( ( T_1 * ) & V_83 ,
( T_1 * ) & V_2 -> V_99 . V_149 .
V_83 , V_235 ) ;
else
memcpy ( ( T_1 * ) & V_83 , ( T_1 * ) V_245 , V_235 ) ;
} else {
memcpy ( ( T_1 * ) & V_83 , ( T_1 * ) & V_2 -> V_99 .
V_149 . V_83 , V_235 ) ;
}
V_27 = F_48 ( V_2 , V_247 ,
V_213 , 0 , & V_83 ) ;
return V_27 ;
}
int F_53 ( struct V_1 * V_2 , T_1 * V_245 )
{
if ( ! V_2 -> V_144 )
return 0 ;
switch ( V_2 -> V_190 ) {
case V_243 :
return F_52 ( V_2 , V_245 ) ;
case V_192 :
return F_48 ( V_2 ,
V_248 ,
V_213 , 0 , NULL ) ;
case V_249 :
return F_48 ( V_2 , V_250 ,
V_213 , 0 , NULL ) ;
default:
break;
}
return 0 ;
}
T_1
F_21 ( T_1 V_151 )
{
switch ( V_151 ) {
case V_251 :
case V_113 :
case V_251 | V_113 :
return V_252 ;
case V_130 :
case V_210 :
case V_130 | V_210 :
default:
return V_253 ;
}
}
