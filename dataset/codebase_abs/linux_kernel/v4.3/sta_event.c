void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_2 -> V_6 )
return;
F_2 ( V_5 , V_7 ,
L_1 ) ;
V_2 -> V_6 = false ;
V_2 -> V_8 = false ;
V_2 -> V_9 = false ;
if ( ( F_3 ( V_2 ) == V_10 ) &&
F_4 ( V_2 -> V_5 -> V_11 ) ) {
F_5 ( V_2 ) ;
if ( V_2 -> V_5 -> V_12 )
F_6 ( V_2 ) ;
}
F_7 ( V_2 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 . V_24 = false ;
V_2 -> V_23 . V_25 = false ;
V_2 -> V_26 = 0 ;
V_2 -> V_23 . V_27 = false ;
V_2 -> V_28 = 0 ;
V_2 -> V_23 . V_29 = false ;
V_2 -> V_23 . V_30 = 0 ;
V_2 -> V_31 = true ;
V_2 -> V_32 = 0 ;
if ( ( F_3 ( V_2 ) == V_10 ||
F_3 ( V_2 ) == V_33 ) && V_2 -> V_34 )
F_8 ( V_2 ) ;
if ( V_2 -> V_35 == V_36 ) {
V_2 -> V_37 = V_38 ;
V_2 -> V_39 = false ;
}
F_2 ( V_5 , V_7 ,
L_2 ,
V_2 -> V_40 . V_41 , V_2 -> V_40 . V_42 ) ;
F_2 ( V_5 , V_7 ,
L_3 ,
V_2 -> V_43 . V_44 . V_41 . V_41 ,
V_2 -> V_43 . V_44 . V_41 . V_42 ) ;
memcpy ( & V_2 -> V_40 ,
& V_2 -> V_43 . V_44 . V_41 ,
sizeof( struct V_45 ) ) ;
memcpy ( V_2 -> V_46 ,
V_2 -> V_43 . V_44 . V_47 , V_48 ) ;
memset ( & V_2 -> V_43 , 0x00 , sizeof( V_2 -> V_43 ) ) ;
V_5 -> V_49 = false ;
V_5 -> V_50 = false ;
if ( V_5 -> V_51 && V_5 -> V_52 )
return;
V_2 -> V_6 = false ;
F_2 ( V_5 , V_53 ,
L_4 ,
V_2 -> V_54 , V_3 ) ;
if ( V_2 -> V_35 == V_55 ||
V_2 -> V_35 == V_56 ) {
F_9 ( V_2 -> V_57 , V_3 , NULL , 0 ,
false , V_58 ) ;
}
F_10 ( V_2 -> V_54 ) ;
F_11 ( V_2 -> V_57 , V_5 ) ;
if ( F_12 ( V_2 -> V_57 ) )
F_13 ( V_2 -> V_57 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
int V_61 = 0 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_62 * V_63 ;
struct V_64 * V_65 =
( void * ) V_60 -> V_66 + sizeof( V_5 -> V_67 ) ;
T_2 * V_68 = V_65 -> V_69 ;
if ( V_60 -> V_70 < ( sizeof( struct V_64 ) -
sizeof( T_1 ) - sizeof( V_5 -> V_67 ) ) ) {
F_2 ( V_5 , ERROR , L_5 ) ;
return - 1 ;
}
V_63 = F_15 ( V_2 , V_65 -> V_69 ) ;
if ( ! V_63 ) {
F_2 ( V_5 , ERROR , L_6 ) ;
return - 1 ;
}
switch ( F_16 ( V_65 -> type ) ) {
case V_71 :
F_17 ( V_2 -> V_57 ,
V_65 -> V_69 ,
V_72 ,
F_16 ( V_65 -> V_73 . V_3 ) ,
V_58 ) ;
break;
case V_74 :
F_2 ( V_5 , V_75 , L_7 ) ;
F_2 ( V_5 , V_75 ,
L_8 ,
V_65 -> V_73 . V_76 . V_77 ,
V_65 -> V_73 . V_76 . V_78 ,
V_65 -> V_73 . V_76 . V_79 ) ;
if ( V_65 -> V_73 . V_76 . V_77 != 0 ) {
switch ( V_65 -> V_73 . V_76 . V_79 ) {
case V_80 :
V_63 -> V_81 = V_82 ;
break;
case V_83 :
V_63 -> V_81 = V_84 ;
break;
default:
break;
}
return V_61 ;
}
switch ( V_65 -> V_73 . V_76 . V_79 ) {
case V_80 :
if ( V_63 -> V_81 == V_82 )
break;
F_18 ( V_2 , V_68 ,
false ) ;
V_63 -> V_81 = V_82 ;
break;
case V_83 :
if ( V_63 -> V_81 == V_84 )
break;
F_18 ( V_2 , V_68 ,
true ) ;
V_63 -> V_81 = V_84 ;
break;
default:
break;
}
break;
case V_85 :
F_2 ( V_5 , V_75 , L_9 ) ;
V_63 -> V_81 = V_86 ;
break;
case V_87 :
F_2 ( V_5 , V_75 ,
L_10 ,
V_65 -> V_73 . V_88 ) ;
break;
default:
break;
}
return V_61 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 ;
struct V_62 * V_63 ;
unsigned long V_93 ;
V_92 = ( void * ) V_90 ;
F_2 ( V_2 -> V_5 , V_75 ,
L_11 ,
V_92 -> V_94 , V_92 -> V_95 ,
V_92 -> V_96 ) ;
if ( F_20 ( V_92 -> V_94 , V_2 -> V_57 -> V_97 ) ) {
if ( V_92 -> V_95 )
V_2 -> V_9 = false ;
else
V_2 -> V_9 = true ;
} else if ( F_21 ( V_92 -> V_94 ) ) {
F_22 ( V_2 , V_92 -> V_94 , V_92 -> V_95 ) ;
} else {
F_23 ( & V_2 -> V_98 , V_93 ) ;
V_63 = F_15 ( V_2 , V_92 -> V_94 ) ;
F_24 ( & V_2 -> V_98 , V_93 ) ;
if ( V_63 && V_63 -> V_95 != V_92 -> V_95 ) {
V_63 -> V_95 = V_92 -> V_95 ;
F_22 ( V_2 , V_92 -> V_94 ,
V_92 -> V_95 ) ;
}
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 ;
struct V_62 * V_63 ;
int V_77 ;
unsigned long V_93 ;
V_92 = ( void * ) V_90 ;
F_2 ( V_2 -> V_5 , V_75 ,
L_12 ,
V_92 -> V_94 , V_92 -> V_95 ,
V_92 -> V_96 ) ;
if ( F_20 ( V_92 -> V_94 , V_2 -> V_54 ) ) {
if ( V_92 -> V_95 )
V_2 -> V_9 = false ;
else
V_2 -> V_9 = true ;
} else {
if ( ! F_4 ( V_2 -> V_5 -> V_11 ) )
return;
V_77 = F_26 ( V_2 , V_92 -> V_94 ) ;
if ( F_27 ( V_77 ) ) {
F_23 ( & V_2 -> V_98 , V_93 ) ;
V_63 = F_15 ( V_2 , V_92 -> V_94 ) ;
F_24 ( & V_2 -> V_98 , V_93 ) ;
if ( V_63 && V_63 -> V_95 != V_92 -> V_95 ) {
V_63 -> V_95 = V_92 -> V_95 ;
F_22 ( V_2 ,
V_92 -> V_94 ,
V_92 -> V_95 ) ;
}
}
}
}
void F_28 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_99 * V_100 ;
T_1 V_77 ;
V_100 = ( void * ) V_60 -> V_66 + sizeof( V_101 ) ;
if ( F_16 ( V_100 -> V_102 . type ) != V_103 ) {
F_2 ( V_2 -> V_5 , ERROR ,
L_13 ) ;
return;
}
V_77 = F_16 ( V_100 -> V_77 ) ;
if ( V_77 ) {
F_2 ( V_2 -> V_5 , V_75 ,
L_14 ) ;
} else {
F_2 ( V_2 -> V_5 , V_75 ,
L_15 ) ;
}
}
void F_29 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_89 * V_90 ;
T_1 V_104 , V_105 ;
int V_106 ;
if ( ! V_2 -> V_6 ) {
F_2 ( V_2 -> V_5 , ERROR ,
L_16 ,
V_2 -> V_107 ) ;
return;
}
V_106 = V_60 -> V_70 - sizeof( V_101 ) ;
V_90 = ( void * ) V_60 -> V_66 + sizeof( V_101 ) ;
while ( V_106 >= ( int ) sizeof( struct V_89 ) ) {
V_104 = F_16 ( V_90 -> type ) ;
V_105 = F_16 ( V_90 -> V_70 ) ;
if ( ( sizeof( struct V_89 ) + V_105 ) >
V_106 ) {
F_2 ( V_2 -> V_5 , ERROR ,
L_17 ,
V_105 , V_106 ) ;
break;
}
if ( V_104 == V_108 ) {
if ( F_3 ( V_2 ) == V_10 )
F_25 ( V_2 , V_90 ) ;
else
F_19 ( V_2 , V_90 ) ;
}
V_106 -= sizeof( struct V_89 ) +
V_105 ;
V_90 = ( void * ) ( ( T_2 * ) V_90 + V_105 +
sizeof( struct V_89 ) ) ;
}
}
void F_30 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_89 * V_90 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
T_3 V_70 = V_60 -> V_70 - sizeof( V_101 ) ;
T_2 * V_113 = V_60 -> V_66 + sizeof( V_101 ) ;
T_1 V_104 , V_105 ;
while ( V_70 >= sizeof( struct V_89 ) ) {
V_90 = (struct V_89 * ) V_113 ;
V_105 = F_16 ( V_90 -> V_70 ) ;
V_104 = F_16 ( V_90 -> type ) ;
if ( ( V_105 + sizeof( struct V_89 ) ) > V_70 )
break;
switch ( V_104 ) {
case V_114 :
V_110 =
(struct V_109 * ) V_90 ;
V_5 -> V_115 = V_110 -> V_115 ;
V_5 -> V_116 =
V_110 -> V_117 ;
V_5 -> V_118 =
V_110 -> V_119 ;
F_31 ( V_5 ) ;
F_32 ( V_5 ) ;
break;
case V_120 :
V_112 =
(struct V_111 * ) V_90 ;
V_5 -> V_121 = V_112 -> V_121 ;
V_5 -> V_122 = V_112 -> V_123 ;
V_5 -> V_124 = V_112 -> V_125 ;
break;
default:
break;
}
V_70 -= V_105 + sizeof( struct V_89 ) ;
V_113 += V_105 +
sizeof( struct V_89 ) ;
}
F_33 ( V_5 -> V_126 , L_18 ,
V_5 -> V_121 , V_5 -> V_122 ,
V_5 -> V_115 , V_5 -> V_116 ,
V_5 -> V_118 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_61 = 0 ;
V_101 V_127 = V_5 -> V_67 ;
T_1 V_128 , V_3 ;
switch ( V_127 ) {
case V_129 :
F_2 ( V_5 , ERROR ,
L_19 ) ;
break;
case V_130 :
F_2 ( V_5 , V_75 , L_20 ) ;
if ( ! F_12 ( V_2 -> V_57 ) )
F_35 ( V_2 -> V_57 ) ;
F_36 ( V_2 -> V_57 , V_5 ) ;
break;
case V_131 :
F_2 ( V_5 , V_75 , L_21 ) ;
if ( V_2 -> V_132 . V_133 ) {
F_2 ( V_5 , V_7 ,
L_22 ) ;
break;
}
V_5 -> V_134 . V_135 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_136 * ) V_5 -> V_137 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_138 :
F_2 ( V_5 , V_75 , L_23 ) ;
if ( V_2 -> V_132 . V_133 ) {
F_2 ( V_5 , V_7 ,
L_24 ) ;
break;
}
V_5 -> V_134 . V_139 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_136 * ) V_5 -> V_137 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_140 :
F_2 ( V_5 , V_75 , L_25 ) ;
V_5 -> V_134 . V_141 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_136 * ) V_5 -> V_137 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_142 :
F_2 ( V_5 , V_75 , L_26 ) ;
V_5 -> V_143 = V_144 ;
F_37 ( V_5 ) ;
break;
case V_145 :
F_2 ( V_5 , V_75 , L_27 ) ;
if ( ! V_5 -> V_50 && V_2 -> V_9 &&
V_2 -> V_6 && V_5 -> V_146 . V_147 ) {
V_5 -> V_50 = true ;
F_2 ( V_5 , V_75 ,
L_28 ) ;
}
V_5 -> V_49 = false ;
if ( V_5 -> V_50 && V_5 -> V_148 ) {
if ( F_38 ( V_2 ) ) {
if ( V_5 -> V_149 ) {
V_5 -> V_143 = V_150 ;
V_5 -> V_151 = false ;
V_5 -> V_152 = false ;
F_39 ( & V_5 -> V_153 ) ;
break;
}
if ( ! F_40
( V_2 ,
V_154 |
V_155 ) )
V_5 -> V_143 =
V_156 ;
return 0 ;
}
}
V_5 -> V_143 = V_150 ;
V_5 -> V_151 = false ;
V_5 -> V_152 = false ;
F_39 ( & V_5 -> V_153 ) ;
break;
case V_157 :
V_5 -> V_158 . V_159 ( V_5 ) ;
F_2 ( V_5 , V_75 , L_29 ) ;
if ( V_5 -> V_160 )
V_5 -> V_160 = false ;
break;
case V_161 :
F_2 ( V_5 , V_75 , L_30 ) ;
V_61 = F_41 ( V_2 , V_162 ,
0 , 0 , NULL , false ) ;
break;
case V_163 :
F_2 ( V_5 , V_75 , L_31 ) ;
F_42 ( V_2 -> V_57 , V_2 -> V_54 ,
V_164 ,
- 1 , NULL , V_58 ) ;
break;
case V_165 :
F_2 ( V_5 , V_75 , L_32 ) ;
F_42 ( V_2 -> V_57 , V_2 -> V_54 ,
V_166 ,
- 1 , NULL , V_58 ) ;
break;
case V_167 :
case V_168 :
break;
case V_169 :
F_2 ( V_5 , V_75 , L_33 ) ;
V_2 -> V_39 = false ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_57 , V_5 ) ;
if ( F_12 ( V_2 -> V_57 ) )
F_13 ( V_2 -> V_57 ) ;
break;
case V_170 :
F_2 ( V_5 , V_75 , L_34 ) ;
V_61 = F_41 ( V_2 , V_171 ,
V_172 , 0 , NULL , false ) ;
break;
case V_173 :
F_2 ( V_5 , V_75 , L_35 ) ;
V_2 -> V_9 = true ;
break;
case V_174 :
F_2 ( V_5 , V_75 , L_36 ) ;
if ( V_5 -> V_175 )
V_61 = F_43 ( V_2 ,
V_5 -> V_60 -> V_66 ) ;
break;
case V_176 :
F_2 ( V_5 , V_75 , L_37 ) ;
V_61 = F_41 ( V_2 , V_177 ,
0 , 0 , NULL , false ) ;
break;
case V_178 :
F_44 ( V_2 -> V_57 ,
V_179 ,
V_58 ) ;
F_41 ( V_2 , V_180 ,
V_172 , 0 , NULL , false ) ;
V_2 -> V_181 = V_182 ;
F_2 ( V_5 , V_75 , L_38 ) ;
break;
case V_183 :
F_2 ( V_5 , V_75 , L_39 ) ;
break;
case V_184 :
F_2 ( V_5 , V_75 , L_40 ) ;
break;
case V_185 :
F_44 ( V_2 -> V_57 ,
V_186 ,
V_58 ) ;
F_41 ( V_2 , V_180 ,
V_172 , 0 , NULL , false ) ;
V_2 -> V_181 = V_187 ;
F_2 ( V_5 , V_75 , L_41 ) ;
break;
case V_188 :
F_2 ( V_5 , V_75 , L_42 ) ;
break;
case V_189 :
F_2 ( V_5 , V_75 , L_43 ) ;
break;
case V_190 :
F_2 ( V_5 , V_75 , L_44 ) ;
break;
case V_191 :
F_2 ( V_5 , V_75 , L_45 ) ;
break;
case V_192 :
F_2 ( V_5 , V_75 , L_46 ) ;
break;
case V_193 :
F_2 ( V_5 , V_75 , L_47 ) ;
break;
case V_194 :
F_2 ( V_5 , V_75 , L_48 ) ;
break;
case V_195 :
F_2 ( V_5 , V_75 , L_49 ) ;
V_61 = F_41 ( V_2 ,
V_196 ,
V_172 , 0 , NULL , false ) ;
break;
case V_197 :
F_2 ( V_5 , V_75 , L_50 ) ;
F_41 ( V_2 , V_198 ,
V_199 , 0 ,
V_5 -> V_137 , false ) ;
break;
case V_200 :
F_2 ( V_5 , V_75 , L_51 ) ;
F_45 ( V_2 , V_5 -> V_137 ) ;
break;
case V_201 :
F_2 ( V_5 , V_75 , L_52 ) ;
F_46 ( V_2 ,
(struct V_202
* )
V_5 -> V_137 ) ;
break;
case V_203 :
V_128 = F_16 ( * ( V_136 * ) V_5 -> V_137 ) ;
F_2 ( V_5 , V_75 ,
L_53 , V_128 ) ;
V_5 -> V_204 =
F_47 ( T_1 , V_5 -> V_205 , V_128 ) ;
F_2 ( V_5 , V_75 , L_54 ,
V_5 -> V_204 ) ;
break;
case V_206 :
F_2 ( V_5 , V_75 , L_55 ) ;
break;
case V_207 :
F_2 ( V_5 , V_75 , L_56 ) ;
break;
case V_208 :
F_2 ( V_5 , V_75 ,
L_57 , V_127 ) ;
break;
case V_209 :
F_2 ( V_5 , V_75 ,
L_58 ) ;
F_48 ( & V_2 -> V_210 ,
V_2 -> V_211 . V_212 ,
& V_2 -> V_211 . V_213 ,
V_214 ) ;
memset ( & V_2 -> V_211 , 0x00 , sizeof( struct V_215 ) ) ;
break;
case V_216 :
F_2 ( V_5 , V_75 , L_59 ) ;
V_2 -> V_217 =
V_218 + F_49 ( V_219 ) ;
V_2 -> V_220 = V_2 -> V_43 . V_44 . V_221 ;
V_61 = F_41 ( V_2 , V_222 ,
V_199 , 0 ,
V_2 -> V_43 . V_44 . V_47 ,
false ) ;
break;
case V_223 :
V_61 = F_14 ( V_2 , V_5 -> V_60 ) ;
break;
case V_224 :
F_2 ( V_5 , V_75 , L_60 ) ;
F_29 ( V_2 , V_5 -> V_60 ) ;
break;
case V_225 :
F_2 ( V_5 , V_75 , L_61 ) ;
F_28 ( V_2 , V_5 -> V_60 ) ;
break;
case V_226 :
F_2 ( V_5 , V_75 , L_62 ) ;
F_50 ( V_2 , V_5 -> V_137 ) ;
break;
case V_227 :
F_2 ( V_5 , V_75 , L_63 ) ;
V_61 = F_51 ( V_2 ,
V_5 -> V_60 ) ;
break;
case V_228 :
F_2 ( V_5 , V_75 , L_64 ) ;
V_61 = F_52 ( V_2 ,
V_5 -> V_60 ) ;
break;
case V_229 :
F_33 ( V_5 -> V_126 , L_65 ) ;
F_30 ( V_2 ,
V_5 -> V_60 ) ;
break;
default:
F_2 ( V_5 , ERROR , L_66 ,
V_127 ) ;
break;
}
return V_61 ;
}
