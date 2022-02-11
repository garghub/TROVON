static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
if ( V_2 -> V_4 == V_5 ) {
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
V_2 -> V_17 . type = V_18 ;
break;
case V_19 :
case V_20 :
V_2 -> V_17 . type = V_21 ;
break;
default:
V_2 -> V_17 . type = V_22 ;
break;
}
} else {
V_3 = V_23 ;
}
F_2 ( V_2 , L_1 ,
V_2 -> V_17 . type , V_3 ) ;
return V_3 ;
}
void F_3 ( struct V_1 * V_2 , enum V_24 V_25 , void * V_26 ,
void * V_27 )
{
struct V_28 * V_29 = (struct V_28 * ) V_26 ;
T_2 * V_30 = ( T_2 * ) V_27 ;
T_3 V_31 [ 4 ] ;
T_3 V_32 = 0 ;
if ( ( ! ( V_25 & V_2 -> V_33 ) ) || ( V_26 == NULL ) )
return;
F_4 ( V_2 , V_25 ,
L_2 ,
V_29 -> V_34 , V_29 -> V_35 , V_29 -> V_36 ,
V_29 -> V_37 ) ;
F_4 ( V_2 , V_25 , L_3 ,
V_29 -> V_38 , V_29 -> V_39 ) ;
F_4 ( V_2 , V_25 , L_4 ,
V_29 -> V_40 . V_41 . V_42 ,
V_29 -> V_40 . V_41 . V_43 ) ;
F_4 ( V_2 , V_25 , L_5 ,
V_29 -> V_40 . V_44 . V_45 ,
V_29 -> V_40 . V_44 . V_46 ) ;
if ( ( V_27 != NULL ) && ( V_29 -> V_36 != 0 ) ) {
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
F_4 ( V_2 , V_25 , L_6 ) ;
for ( V_32 = 0 ; V_32 < F_5 ( V_29 -> V_36 ) ; V_32 ++ ) {
V_31 [ ( ( V_32 % 16 ) / 4 ) ] |=
( ( T_3 ) V_30 [ V_32 ] ) << ( 8 * ( V_32 % 4 ) ) ;
if ( ( V_32 % 16 ) == 15 ) {
F_4 ( V_2 , V_25 ,
L_7 ,
V_32 - 15 , V_31 [ 0 ] , V_31 [ 1 ] , V_31 [ 2 ] ,
V_31 [ 3 ] ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
}
}
if ( ( V_32 % 16 ) != 0 )
F_4 ( V_2 , V_25 , L_7 ,
V_32 - ( V_32 % 16 ) , V_31 [ 0 ] , V_31 [ 1 ] , V_31 [ 2 ] ,
V_31 [ 3 ] ) ;
}
}
T_1 F_6 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
T_3 V_47 ;
V_2 -> V_48 . V_49 = true ;
V_47 = F_7 ( V_2 , V_50 ) ;
V_47 = ( ( V_47 & V_51 ) >>
V_52 ) ;
V_2 -> V_53 = ( T_2 ) V_47 ;
F_1 ( V_2 ) ;
switch ( V_2 -> V_17 . type ) {
case V_18 :
break;
default:
return V_23 ;
break;
}
V_3 = F_8 ( V_2 ) ;
return V_3 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
T_4 * V_35 ,
struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_58 * V_59 =
(struct V_58 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 , V_61 ) ;
V_26 . V_35 |= F_11 ( V_62 ) ;
V_3 = F_12 ( V_2 , & V_26 , V_55 ,
sizeof( * V_55 ) , V_57 ) ;
* V_35 = F_5 ( V_59 -> V_63 ) ;
return V_3 ;
}
T_1 F_13 ( struct V_1 * V_2 ,
T_4 V_35 , T_2 * V_64 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_65 * V_59 =
(struct V_65 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 ,
V_66 ) ;
V_59 -> V_63 = F_11 ( V_35 ) ;
memcpy ( & V_59 -> V_67 , & V_64 [ 0 ] , 4 ) ;
memcpy ( & V_59 -> V_68 , & V_64 [ 4 ] , 2 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
T_1 F_14 ( struct V_1 * V_2 , T_2 * V_64 )
{
struct V_54 V_55 ;
T_1 V_3 ;
T_4 V_35 = 0 ;
V_3 = F_9 ( V_2 , & V_35 , & V_55 , NULL ) ;
if ( V_35 & V_69 )
memcpy ( V_64 , & V_55 . V_70 , sizeof( V_55 . V_70 ) ) ;
return V_3 ;
}
T_1 F_15 ( T_2 * V_64 )
{
T_1 V_3 = 0 ;
if ( F_16 ( V_64 ) ) {
F_2 ( V_2 , L_8 ) ;
V_3 = V_71 ;
} else if ( F_17 ( V_64 ) ) {
F_2 ( V_2 , L_9 ) ;
V_3 = V_71 ;
} else if ( V_64 [ 0 ] == 0 && V_64 [ 1 ] == 0 && V_64 [ 2 ] == 0 &&
V_64 [ 3 ] == 0 && V_64 [ 4 ] == 0 && V_64 [ 5 ] == 0 ) {
F_2 ( V_2 , L_10 ) ;
V_3 = V_71 ;
}
return V_3 ;
}
T_1 F_18 ( struct V_1 * V_2 )
{
T_3 V_72 = 0 ;
T_3 V_47 = 0 ;
T_3 V_73 ;
V_73 = F_7 ( V_2 , V_74 ) & V_75
>> V_76 ;
for ( V_72 = 0 ; V_72 < V_73 + 2 ; V_72 ++ ) {
V_47 = F_7 ( V_2 , V_77 ) ;
if ( ! ( V_47 & V_78 ) )
break;
F_19 ( 100 ) ;
}
if ( V_47 & V_78 ) {
F_2 ( V_2 , L_11 ) ;
return V_79 ;
}
V_2 -> V_80 = ( T_2 ) V_2 -> V_81 . V_82 ;
if ( ! V_72 ) {
V_47 = F_7 ( V_2 , V_83 ) ;
F_20 ( V_2 , V_83 ,
( V_47 | V_84 ) ) ;
for ( V_72 = 0 ; V_72 < 10 ; V_72 ++ ) {
V_47 = F_7 ( V_2 , V_83 ) ;
if ( ! ( V_47 & V_84 ) )
break;
F_21 ( 1000 , 2000 ) ;
}
if ( V_47 & V_84 ) {
F_2 ( V_2 , L_12 ) ;
return V_79 ;
}
}
F_22 ( V_2 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
T_3 V_47 ;
V_47 = F_7 ( V_2 , V_85 ) ;
F_20 ( V_2 , V_85 , ( V_47 | V_86 ) ) ;
}
T_3 F_23 ( struct V_1 * V_2 )
{
T_3 V_87 = 0 ;
T_3 V_88 = 0 ;
T_3 V_53 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_89 ; V_32 ++ ) {
if ( ! V_2 -> V_90 . V_91 [ V_32 ] )
continue;
V_87 = F_7 ( V_2 , F_24 ( V_32 ) ) ;
V_53 = ( V_87 & V_92 )
>> V_93 ;
if ( V_53 != V_2 -> V_53 )
continue;
V_88 = ( V_87 & V_94 )
>> V_95 ;
break;
}
return V_88 ;
}
void F_25 ( struct V_1 * V_2 , T_3 V_88 )
{
T_3 V_87 = 0 ;
T_3 V_96 = 0 ;
T_3 V_53 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_89 ; V_32 ++ ) {
if ( ! V_2 -> V_90 . V_91 [ V_32 ] )
continue;
V_87 = F_7 ( V_2 , F_24 ( V_32 ) ) ;
V_53 = ( V_87 & V_92 )
>> V_93 ;
if ( V_53 != V_2 -> V_53 )
continue;
V_96 = ( V_88 << V_97 ) &
V_94 ;
V_87 &= ~ V_94 ;
V_87 |= V_96 ;
F_20 ( V_2 , F_24 ( V_32 ) , V_87 ) ;
}
}
T_1 F_26 ( struct V_1 * V_2 ,
bool V_98 )
{
struct V_28 V_26 ;
struct V_99 * V_100 =
(struct V_99 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 ,
V_101 ) ;
if ( V_98 )
V_100 -> V_102 = F_27 ( V_103 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , NULL ) ;
return V_3 ;
}
T_1 F_28 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_104 * V_100 =
(struct V_104 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 ,
V_105 ) ;
V_100 -> V_106 = V_107 ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
T_1 F_29 ( struct V_1 * V_2 ,
bool V_108 , struct V_109 * V_110 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_111 * V_112 =
(struct V_111 * ) & V_26 . V_40 . V_60 ;
struct V_109 * V_113 = & V_2 -> V_48 . V_114 ;
T_1 V_3 ;
T_4 V_63 ;
F_10 ( & V_26 , V_115 ) ;
if ( V_108 )
V_63 = V_116 ;
else
V_63 = V_117 ;
V_112 -> V_63 = F_11 ( V_63 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
if ( V_3 )
goto V_118;
memcpy ( & V_2 -> V_48 . V_119 , V_113 ,
sizeof( struct V_109 ) ) ;
V_113 -> V_120 = (enum V_121 ) V_112 -> V_120 ;
V_113 -> V_122 = (enum V_123 ) V_112 -> V_122 ;
V_113 -> V_114 = V_112 -> V_114 ;
V_113 -> V_124 = V_112 -> V_124 ;
V_113 -> V_125 = V_112 -> V_125 ;
if ( V_112 -> V_63 & F_11 ( V_116 ) )
V_113 -> V_126 = true ;
else
V_113 -> V_126 = false ;
if ( V_110 )
* V_110 = * V_113 ;
V_2 -> V_48 . V_49 = false ;
V_118:
return V_3 ;
}
T_1 F_30 ( struct V_1 * V_2 ,
struct V_127 * V_128 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_129 * V_100 =
(struct V_129 * ) & V_26 . V_40 . V_60 ;
struct V_130 * V_112 =
(struct V_130 * )
& V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 ,
V_131 ) ;
V_100 -> V_132 = F_11 ( V_128 -> V_132 ) ;
V_100 -> V_133 = V_128 -> V_133 ;
V_100 -> V_134 = V_128 -> V_135 ;
V_100 -> V_136 = F_11 ( V_128 -> V_35 ) ;
V_26 . V_35 |= F_11 ( ( T_4 ) ( V_62 | V_137 ) ) ;
if ( sizeof( V_128 -> V_138 ) > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_3 = F_12 ( V_2 , & V_26 , & V_128 -> V_138 ,
sizeof( V_128 -> V_138 ) , V_57 ) ;
if ( V_3 )
goto V_141;
V_128 -> V_142 = F_5 ( V_112 -> V_142 ) ;
V_128 -> V_143 = F_5 ( V_112 -> V_143 ) ;
V_128 -> V_144 = F_5 ( V_112 -> V_145 ) ;
V_128 -> V_146 = F_5 ( V_112 -> V_147 ) ;
V_141:
return V_3 ;
}
T_1 F_31 ( struct V_1 * V_2 ,
T_4 V_142 , bool V_148 , struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_149 * V_100 =
(struct V_149 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
T_4 V_35 = 0 ;
F_10 ( & V_26 ,
V_150 ) ;
if ( V_148 )
V_35 |= V_151 ;
V_100 -> V_152 = F_11 ( V_35 ) ;
V_100 -> V_153 = F_11 ( V_151 ) ;
V_100 -> V_142 = F_11 ( V_142 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
T_1 F_32 ( struct V_1 * V_2 ,
T_4 V_142 , bool V_148 , struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_149 * V_100 =
(struct V_149 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
T_4 V_35 = 0 ;
F_10 ( & V_26 ,
V_150 ) ;
if ( V_148 )
V_35 |= V_154 ;
V_100 -> V_152 = F_11 ( V_35 ) ;
V_100 -> V_153 = F_11 ( V_154 ) ;
V_100 -> V_142 = F_11 ( V_142 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
T_1 F_33 ( struct V_1 * V_2 ,
T_4 V_142 , bool V_155 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_149 * V_100 =
(struct V_149 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 ,
V_150 ) ;
if ( V_155 )
V_100 -> V_152
|= F_11 ( V_156 ) ;
else
V_100 -> V_152
&= F_11 ( ~ V_156 ) ;
V_100 -> V_153 = F_11 ( V_156 ) ;
V_100 -> V_142 = F_11 ( V_142 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
T_1 F_34 ( struct V_1 * V_2 ,
struct V_127 * V_128 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_157 * V_100 =
(struct V_157 * ) & V_26 . V_40 . V_60 ;
struct V_130 * V_112 =
(struct V_130 * )
& V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 ,
V_158 ) ;
V_100 -> V_142 = F_11 ( V_128 -> V_142 ) ;
V_26 . V_35 |= F_11 ( ( T_4 ) V_62 ) ;
if ( sizeof( V_128 -> V_138 ) > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_3 = F_12 ( V_2 , & V_26 , & V_128 -> V_138 ,
sizeof( V_128 -> V_138 ) , NULL ) ;
if ( V_3 )
goto V_159;
V_128 -> V_142 = F_5 ( V_112 -> V_142 ) ;
V_128 -> V_143 = F_5 ( V_112 -> V_143 ) ;
V_128 -> V_144 = F_5 ( V_112 -> V_145 ) ;
V_128 -> V_146 = F_5 ( V_112 -> V_147 ) ;
V_159:
return V_3 ;
}
T_1 F_35 ( struct V_1 * V_2 ,
struct V_127 * V_128 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_157 * V_100 =
(struct V_157 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 ,
V_160 ) ;
V_100 -> V_142 = F_11 ( V_128 -> V_142 ) ;
V_26 . V_35 |= F_11 ( ( T_4 ) ( V_62 | V_137 ) ) ;
if ( sizeof( V_128 -> V_138 ) > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_3 = F_12 ( V_2 , & V_26 , & V_128 -> V_138 ,
sizeof( V_128 -> V_138 ) , V_57 ) ;
return V_3 ;
}
T_1 F_36 ( struct V_1 * V_2 ,
struct V_161 * V_162 ,
T_4 V_163 , T_4 * V_164 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_157 * V_165 =
(struct V_157 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 ,
V_166 ) ;
V_26 . V_35 |= F_11 ( ( T_4 ) V_62 ) ;
if ( V_163 > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_165 -> V_142 = F_11 ( * V_164 ) ;
V_3 = F_12 ( V_2 , & V_26 , V_162 , V_163 , V_57 ) ;
* V_164 = F_5 ( V_165 -> V_142 ) ;
return V_3 ;
}
T_1 F_37 ( struct V_1 * V_2 ,
T_4 * V_167 , T_4 * V_168 ,
T_4 * V_169 , T_4 * V_170 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_171 * V_112 =
(struct V_171 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 , V_172 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
if ( ! V_3 ) {
if ( V_167 != NULL )
* V_167 = F_5 ( V_112 -> V_173 ) ;
if ( V_168 != NULL )
* V_168 = F_5 ( V_112 -> V_174 ) ;
if ( V_169 != NULL )
* V_169 = F_5 ( V_112 -> V_175 ) ;
if ( V_170 != NULL )
* V_170 = F_5 ( V_112 -> V_176 ) ;
}
return V_3 ;
}
T_1 F_38 ( struct V_1 * V_2 ,
struct V_177 * V_178 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_179 * V_100 =
(struct V_179 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
if ( V_178 == NULL )
return V_180 ;
F_10 ( & V_26 , V_181 ) ;
V_26 . V_35 |= F_11 ( V_182 ) ;
V_100 -> V_183 = V_178 -> V_184 ;
V_100 -> V_185 = V_178 -> V_186 ;
V_100 -> V_187 = V_178 -> V_188 ;
V_100 -> V_189 = V_178 -> V_190 ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
bool F_39 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
bool V_191 = false ;
if ( V_2 -> V_48 . V_49 ) {
V_3 = F_29 ( V_2 , true , NULL , NULL ) ;
if ( V_3 )
goto V_192;
}
V_191 = V_2 -> V_48 . V_114 . V_114 & V_193 ;
V_192:
return V_191 ;
}
T_1 F_40 ( struct V_1 * V_2 , T_4 V_132 ,
T_4 V_194 , T_2 V_195 ,
bool V_196 , T_4 * V_197 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_198 * V_100 =
(struct V_198 * ) & V_26 . V_40 . V_60 ;
struct V_199 * V_112 =
(struct V_199 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
T_4 V_200 = 0 ;
if ( ! ! V_132 != ! ! V_194 )
return V_180 ;
F_10 ( & V_26 , V_201 ) ;
V_100 -> V_132 = F_11 ( V_132 ) ;
V_100 -> V_194 = F_11 ( V_194 ) ;
V_100 -> V_202 = V_195 ;
if ( ! V_132 )
V_200 |= V_203 ;
if ( V_196 )
V_200 |= V_204 ;
else
V_200 |= V_205 ;
V_100 -> V_200 = F_11 ( V_200 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
if ( ! V_3 && V_197 )
* V_197 = F_5 ( V_112 -> V_197 ) ;
return V_3 ;
}
T_1 F_41 ( struct V_1 * V_2 ,
T_4 V_197 , T_4 * V_206 ,
bool * V_207 , T_4 * V_208 ,
T_4 * V_209 , T_4 * V_210 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_211 * V_212 =
(struct V_211 * )
& V_26 . V_40 . V_60 ;
T_1 V_3 ;
if ( V_197 == 0 )
return V_180 ;
F_10 ( & V_26 ,
V_213 ) ;
V_212 -> V_142 = F_11 ( V_197 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
if ( V_3 )
goto V_214;
if ( V_206 )
* V_206 = F_5 ( V_212 -> V_206 ) ;
if ( V_208 )
* V_208 = F_5 ( V_212 -> V_208 ) ;
if ( V_209 )
* V_209 = F_5 ( V_212 -> V_209 ) ;
if ( V_210 )
* V_210 = F_5 ( V_212 -> V_210 ) ;
if ( V_207 ) {
T_4 V_35 = F_5 ( V_212 -> V_200 ) ;
if ( V_35 & V_203 )
* V_207 = true ;
else
* V_207 = false ;
}
V_214:
return V_3 ;
}
T_1 F_42 ( struct V_1 * V_2 , T_4 V_142 ,
struct V_215 * V_216 ,
T_4 V_217 , struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_218 * V_100 =
(struct V_218 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
T_4 V_163 ;
if ( V_217 == 0 || ! V_216 || ! V_2 )
return V_180 ;
V_163 = V_217 * sizeof( struct V_215 ) ;
F_10 ( & V_26 , V_219 ) ;
V_100 -> V_220 = F_11 ( V_217 ) ;
V_100 -> V_142 [ 0 ] = F_11 ( V_221 | V_142 ) ;
V_100 -> V_142 [ 1 ] = 0 ;
V_100 -> V_142 [ 2 ] = 0 ;
V_26 . V_35 |= F_11 ( ( T_4 ) ( V_62 | V_137 ) ) ;
if ( V_163 > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_3 = F_12 ( V_2 , & V_26 , V_216 , V_163 ,
V_57 ) ;
return V_3 ;
}
T_1 F_43 ( struct V_1 * V_2 , T_4 V_142 ,
struct V_222 * V_216 ,
T_4 V_217 , struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_218 * V_100 =
(struct V_218 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
T_4 V_163 ;
if ( V_217 == 0 || ! V_216 || ! V_2 )
return V_180 ;
V_163 = V_217 * sizeof( struct V_222 ) ;
F_10 ( & V_26 , V_223 ) ;
V_100 -> V_220 = F_11 ( V_217 ) ;
V_100 -> V_142 [ 0 ] = F_11 ( V_221 | V_142 ) ;
V_100 -> V_142 [ 1 ] = 0 ;
V_100 -> V_142 [ 2 ] = 0 ;
V_26 . V_35 |= F_11 ( ( T_4 ) ( V_62 | V_137 ) ) ;
if ( V_163 > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_3 = F_12 ( V_2 , & V_26 , V_216 , V_163 ,
V_57 ) ;
return V_3 ;
}
T_1 F_44 ( struct V_1 * V_2 , T_4 V_142 ,
struct V_224 * V_225 ,
T_2 V_217 , struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_218 * V_100 =
(struct V_218 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
T_4 V_163 ;
if ( V_217 == 0 || ! V_225 || ! V_2 )
return V_180 ;
V_163 = V_217 * sizeof( struct V_224 ) ;
F_10 ( & V_26 , V_226 ) ;
V_100 -> V_220 = F_11 ( V_217 ) ;
V_100 -> V_142 [ 0 ] = F_11 ( V_142 | V_221 ) ;
V_100 -> V_142 [ 1 ] = 0 ;
V_100 -> V_142 [ 2 ] = 0 ;
V_26 . V_35 |= F_11 ( ( T_4 ) ( V_62 | V_137 ) ) ;
if ( V_163 > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_3 = F_12 ( V_2 , & V_26 , V_225 , V_163 ,
V_57 ) ;
return V_3 ;
}
T_1 F_45 ( struct V_1 * V_2 , T_4 V_142 ,
struct V_224 * V_225 ,
T_2 V_217 , struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_218 * V_100 =
(struct V_218 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
T_4 V_163 ;
if ( V_217 == 0 || ! V_225 || ! V_2 )
return V_180 ;
V_163 = V_217 * sizeof( struct V_224 ) ;
F_10 ( & V_26 , V_227 ) ;
V_100 -> V_220 = F_11 ( V_217 ) ;
V_100 -> V_142 [ 0 ] = F_11 ( V_142 | V_221 ) ;
V_100 -> V_142 [ 1 ] = 0 ;
V_100 -> V_142 [ 2 ] = 0 ;
V_26 . V_35 |= F_11 ( ( T_4 ) ( V_62 | V_137 ) ) ;
if ( V_163 > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_3 = F_12 ( V_2 , & V_26 , V_225 , V_163 ,
V_57 ) ;
return V_3 ;
}
T_1 F_46 ( struct V_1 * V_2 , T_4 V_228 ,
T_3 V_229 , T_3 V_230 , T_2 * V_231 , T_4 V_232 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_233 * V_100 =
(struct V_233 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 , V_234 ) ;
V_100 -> V_235 = F_27 ( V_228 ) ;
V_26 . V_38 = F_27 ( V_229 ) ;
V_26 . V_39 = F_27 ( V_230 ) ;
V_26 . V_35 |= F_11 ( ( T_4 ) V_182 ) ;
if ( V_232 ) {
V_26 . V_35 |= F_11 ( ( T_4 ) ( V_62 |
V_137 ) ) ;
if ( V_232 > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_26 . V_36 = F_11 ( V_232 ) ;
}
V_3 = F_12 ( V_2 , & V_26 , V_231 , V_232 , V_57 ) ;
return V_3 ;
}
T_1 F_47 ( struct V_1 * V_2 ,
enum V_236 V_237 ,
T_2 V_238 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_239 * V_100 =
(struct V_239 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 ,
V_240 ) ;
V_100 -> V_241 = ( T_2 ) V_237 ;
V_100 -> V_242 = V_238 ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
T_1 F_48 ( struct V_1 * V_2 ,
enum V_243 V_244 ,
enum V_245 V_246 ,
T_2 V_247 , T_5 * V_248 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_249 * V_212 =
(struct V_249 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 , V_250 ) ;
V_212 -> V_251 = F_11 ( V_244 ) ;
V_212 -> V_252 = F_11 ( V_246 ) ;
V_212 -> V_253 = F_27 ( V_247 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
if ( ! V_3 || V_2 -> V_254 . V_255 == V_256 )
* V_248 = F_49 ( V_212 -> V_248 ) ;
return V_3 ;
}
T_1 F_50 ( struct V_1 * V_2 ,
enum V_243 V_244 ,
T_2 V_247 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_249 * V_100 =
(struct V_249 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 , V_257 ) ;
V_100 -> V_251 = F_11 ( V_244 ) ;
V_100 -> V_253 = F_27 ( V_247 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
T_1 F_51 ( struct V_1 * V_2 , T_2 V_258 ,
T_3 V_259 , T_4 V_260 , void * V_31 ,
bool V_261 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_262 * V_100 =
(struct V_262 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
if ( V_259 & 0xFF000000 ) {
V_3 = V_180 ;
goto V_263;
}
F_10 ( & V_26 , V_264 ) ;
if ( V_261 )
V_100 -> V_63 |= V_265 ;
V_100 -> V_258 = V_258 ;
V_100 -> V_259 = F_27 ( V_259 ) ;
V_100 -> V_260 = F_11 ( V_260 ) ;
V_26 . V_35 |= F_11 ( ( T_4 ) V_62 ) ;
if ( V_260 > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_3 = F_12 ( V_2 , & V_26 , V_31 , V_260 , V_57 ) ;
V_263:
return V_3 ;
}
static void F_52 ( struct V_1 * V_2 , void * V_266 ,
T_3 V_267 ,
enum V_268 V_269 )
{
struct V_270 * V_271 ;
T_3 V_272 , V_273 , V_274 ;
struct V_275 * V_276 ;
T_3 V_277 ;
T_3 V_32 = 0 ;
T_4 V_235 ;
V_271 = (struct V_270 * ) V_266 ;
if ( V_269 == V_278 )
V_276 = (struct V_275 * ) & V_2 -> V_279 ;
else if ( V_269 == V_280 )
V_276 = (struct V_275 * ) & V_2 -> V_90 ;
else
return;
for ( V_32 = 0 ; V_32 < V_267 ; V_32 ++ , V_271 ++ ) {
V_235 = F_5 ( V_271 -> V_235 ) ;
V_272 = F_49 ( V_271 -> V_272 ) ;
V_273 = F_49 ( V_271 -> V_273 ) ;
V_274 = F_49 ( V_271 -> V_274 ) ;
switch ( V_235 ) {
case V_281 :
V_276 -> V_282 = V_272 ;
break;
case V_283 :
V_276 -> V_284 = V_272 ;
break;
case V_285 :
V_276 -> V_286 = V_272 ;
break;
case V_287 :
V_276 -> V_288 = V_272 ;
break;
case V_289 :
V_276 -> V_290 = V_272 ;
break;
case V_291 :
if ( V_272 == 1 )
V_276 -> V_292 = true ;
break;
case V_293 :
V_276 -> V_294 = V_272 ;
V_276 -> V_295 = V_273 ;
break;
case V_296 :
if ( V_272 == 1 )
V_276 -> V_297 = true ;
break;
case V_298 :
if ( V_272 == 1 )
V_276 -> V_299 = true ;
break;
case V_300 :
if ( V_272 == 1 )
V_276 -> V_301 = true ;
break;
case V_302 :
V_276 -> V_303 = V_272 ;
break;
case V_304 :
if ( V_272 == 1 ) {
V_276 -> V_305 = true ;
V_276 -> V_306 = V_273 ;
V_276 -> V_307 = V_274 ;
}
break;
case V_308 :
if ( V_272 == 1 )
V_276 -> V_309 = true ;
break;
case V_310 :
V_276 -> V_311 = true ;
V_277 = F_7 ( V_2 , V_312 ) ;
if ( V_277 & V_313 )
V_276 -> V_314 = V_272 ;
else
V_276 -> V_314 = 128 ;
V_276 -> V_315 = V_273 ;
break;
case V_316 :
V_276 -> V_317 = V_272 ;
V_276 -> V_318 = V_274 ;
break;
case V_319 :
V_276 -> V_320 = V_272 ;
V_276 -> V_318 = V_274 ;
break;
case V_321 :
V_276 -> V_322 = V_272 ;
break;
case V_323 :
V_276 -> V_324 = V_272 ;
break;
case V_325 :
if ( V_272 == 1 )
V_276 -> V_326 = true ;
break;
case V_327 :
if ( V_272 == 1 )
V_276 -> V_328 = true ;
break;
case V_329 :
if ( V_272 == 1 )
V_276 -> V_330 = true ;
break;
case V_331 :
if ( V_274 < V_89 )
V_276 -> V_91 [ V_274 ] = true ;
break;
case V_332 :
if ( V_274 < V_89 )
V_276 -> V_333 [ V_274 ] = true ;
break;
case V_334 :
if ( V_272 == 1 ) {
V_276 -> V_335 = V_274 ;
V_276 -> V_336 = V_273 ;
}
break;
case V_337 :
if ( V_272 == 1 )
V_276 -> V_338 = true ;
break;
case V_339 :
V_276 -> V_340 = true ;
V_276 -> V_341 = V_272 ;
V_276 -> V_342 = V_273 ;
break;
default:
break;
}
}
V_276 -> V_343 = V_344 ;
}
T_1 F_53 ( struct V_1 * V_2 ,
void * V_266 , T_4 V_345 , T_4 * V_346 ,
enum V_268 V_269 ,
struct V_56 * V_57 )
{
struct V_347 * V_100 ;
T_1 V_3 = 0 ;
struct V_28 V_26 ;
V_100 = (struct V_347 * ) & V_26 . V_40 . V_60 ;
if ( V_269 != V_280 &&
V_269 != V_278 ) {
V_3 = V_180 ;
goto exit;
}
F_10 ( & V_26 , V_269 ) ;
V_26 . V_35 |= F_11 ( ( T_4 ) V_62 ) ;
if ( V_345 > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_3 = F_12 ( V_2 , & V_26 , V_266 , V_345 , V_57 ) ;
* V_346 = F_5 ( V_26 . V_36 ) ;
if ( V_3 )
goto exit;
F_52 ( V_2 , V_266 , F_49 ( V_100 -> V_217 ) ,
V_269 ) ;
exit:
return V_3 ;
}
T_1 F_54 ( struct V_1 * V_2 , T_2 V_348 ,
T_2 V_349 , void * V_266 , T_4 V_345 ,
T_4 * V_350 , T_4 * V_351 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_352 * V_100 =
(struct V_352 * ) & V_26 . V_40 . V_60 ;
struct V_352 * V_112 =
(struct V_352 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
if ( V_345 == 0 || ! V_266 )
return V_180 ;
F_10 ( & V_26 , V_353 ) ;
V_26 . V_35 |= F_11 ( ( T_4 ) V_62 ) ;
V_100 -> type = V_349 & V_354 ;
V_100 -> type |= ( ( V_348 << V_355 ) &
V_356 ) ;
V_26 . V_36 = F_11 ( V_345 ) ;
V_26 . V_35 |= F_11 ( ( T_4 ) V_62 ) ;
if ( V_345 > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_3 = F_12 ( V_2 , & V_26 , V_266 , V_345 , V_57 ) ;
if ( ! V_3 ) {
if ( V_350 != NULL )
* V_350 = F_5 ( V_112 -> V_350 ) ;
if ( V_351 != NULL )
* V_351 = F_5 ( V_112 -> V_351 ) ;
}
return V_3 ;
}
T_1 F_55 ( struct V_1 * V_2 ,
bool V_357 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_358 * V_100 =
(struct V_358 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 , V_359 ) ;
if ( ! V_357 )
V_100 -> V_106 |= V_360 ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
T_1 F_56 ( struct V_1 * V_2 , bool V_361 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_362 * V_100 =
(struct V_362 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 , V_363 ) ;
if ( V_361 )
V_100 -> V_106 |= V_364 ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
T_1 F_57 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_365 * V_100 =
(struct V_365 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
F_10 ( & V_26 , V_366 ) ;
V_100 -> V_106 = V_367 ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
T_1 F_58 ( struct V_1 * V_2 , T_4 V_142 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_157 * V_100 =
(struct V_157 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
if ( V_142 == 0 )
return V_180 ;
F_10 ( & V_26 , V_368 ) ;
V_100 -> V_142 = F_11 ( V_142 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , V_57 ) ;
return V_3 ;
}
static T_1 F_59 ( struct V_1 * V_2 , T_4 V_142 ,
void * V_266 , T_4 V_345 ,
enum V_268 V_34 ,
struct V_56 * V_57 )
{
struct V_28 V_26 ;
struct V_369 * V_100 =
(struct V_369 * ) & V_26 . V_40 . V_60 ;
T_1 V_3 ;
bool V_370 = false ;
switch ( V_34 ) {
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
V_370 = true ;
break;
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
V_370 = false ;
break;
default:
return V_180 ;
}
F_10 ( & V_26 , V_34 ) ;
V_26 . V_35 |= F_11 ( ( T_4 ) V_62 ) ;
if ( V_370 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_137 ) ;
if ( V_345 > V_139 )
V_26 . V_35 |= F_11 ( ( T_4 ) V_140 ) ;
V_26 . V_36 = F_11 ( V_345 ) ;
V_100 -> V_383 = F_11 ( V_142 ) ;
V_3 = F_12 ( V_2 , & V_26 , V_266 , V_345 , V_57 ) ;
return V_3 ;
}
T_1 F_60 ( struct V_1 * V_2 ,
T_4 V_142 ,
struct V_384 * V_385 ,
struct V_56 * V_57 )
{
return F_59 ( V_2 , V_142 , ( void * ) V_385 , sizeof( * V_385 ) ,
V_372 ,
V_57 ) ;
}
T_1 F_61 ( struct V_1 * V_2 ,
T_4 V_142 ,
struct V_386 * V_385 ,
struct V_56 * V_57 )
{
return F_59 ( V_2 , V_142 , ( void * ) V_385 , sizeof( * V_385 ) ,
V_378 ,
V_57 ) ;
}
T_1 F_62 ( struct V_1 * V_2 ,
T_4 V_142 ,
struct V_387 * V_385 ,
struct V_56 * V_57 )
{
return F_59 ( V_2 , V_142 , ( void * ) V_385 , sizeof( * V_385 ) ,
V_379 ,
V_57 ) ;
}
T_1 F_63 ( struct V_1 * V_2 ,
T_4 V_142 ,
struct V_388 * V_385 ,
struct V_56 * V_57 )
{
return F_59 ( V_2 , V_142 , ( void * ) V_385 , sizeof( * V_385 ) ,
V_380 ,
V_57 ) ;
}
T_1 F_64 ( struct V_1 * V_2 ,
T_4 V_142 ,
struct V_389 * V_385 ,
struct V_56 * V_57 )
{
return F_59 ( V_2 , V_142 , ( void * ) V_385 , sizeof( * V_385 ) ,
V_381 ,
V_57 ) ;
}
T_1 F_65 ( struct V_1 * V_2 ,
T_4 V_142 ,
struct V_390 * V_385 ,
struct V_56 * V_57 )
{
return F_59 ( V_2 , V_142 , ( void * ) V_385 , sizeof( * V_385 ) ,
V_382 ,
V_57 ) ;
}
static T_1 F_66 ( struct V_1 * V_2 ,
struct V_391 * V_392 )
{
T_3 V_393 , V_394 ;
T_3 V_395 , V_396 ;
T_3 V_397 , V_398 ;
T_3 V_399 ;
switch ( V_392 -> V_400 ) {
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
V_394 = V_407 ;
V_394 <<= ( T_3 ) V_392 -> V_400 ;
break;
default:
return V_180 ;
}
switch ( V_392 -> V_408 ) {
case V_409 :
case V_410 :
case V_411 :
case V_412 :
V_393 = V_413 ;
V_393 <<= ( T_3 ) V_392 -> V_408 ;
break;
default:
return V_180 ;
}
switch ( V_392 -> V_414 ) {
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
V_396 = V_407 ;
V_396 <<= ( T_3 ) V_392 -> V_414 ;
break;
default:
return V_180 ;
}
switch ( V_392 -> V_420 ) {
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
V_395 = V_413 ;
V_395 <<= ( T_3 ) V_392 -> V_420 ;
break;
default:
return V_180 ;
}
V_399 = F_7 ( V_2 , V_427 ) ;
V_397 = ( V_399 & V_428 )
>> V_429 ;
if ( V_394 + V_393 > V_397 )
return V_430 ;
V_399 = F_7 ( V_2 , V_431 ) ;
V_398 = ( V_399 & V_432 )
>> V_433 ;
if ( V_396 + V_395 > V_398 )
return V_430 ;
return 0 ;
}
T_1 F_67 ( struct V_1 * V_2 ,
struct V_391 * V_392 )
{
T_1 V_434 = 0 ;
T_3 V_435 = 0 ;
T_3 V_399 ;
if ( ! V_392 )
return V_180 ;
V_434 = F_66 ( V_2 , V_392 ) ;
if ( V_434 )
return V_434 ;
V_399 = F_7 ( V_2 , V_312 ) ;
V_399 &= ~ V_436 ;
V_399 |= ( ( T_3 ) V_392 -> V_414 << V_437 ) &
V_436 ;
V_399 &= ~ V_438 ;
V_399 |= ( ( T_3 ) V_392 -> V_420 << V_439 ) &
V_438 ;
V_399 &= ~ V_440 ;
V_399 |= ( ( T_3 ) V_392 -> V_400 <<
V_441 ) &
V_440 ;
V_399 &= ~ V_442 ;
V_399 |= ( ( T_3 ) V_392 -> V_408 <<
V_443 ) &
V_442 ;
V_399 &= ~ V_313 ;
if ( V_392 -> V_435 == V_444 )
V_435 = 1 ;
V_399 |= ( V_435 << V_445 ) &
V_313 ;
if ( V_392 -> V_446 )
V_399 |= V_447 ;
if ( V_392 -> V_448 )
V_399 |= V_449 ;
if ( V_392 -> V_450 )
V_399 |= V_451 ;
F_20 ( V_2 , V_312 , V_399 ) ;
return 0 ;
}
