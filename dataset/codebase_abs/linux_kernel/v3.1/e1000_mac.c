T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 ;
T_2 V_6 ;
T_3 V_7 ;
V_4 -> type = V_8 ;
V_5 = F_2 ( V_2 ,
V_9 ,
& V_7 ) ;
if ( V_5 ) {
V_4 -> V_10 = V_11 ;
V_4 -> V_12 = V_13 ;
} else {
switch ( V_7 & V_14 ) {
case V_15 :
V_4 -> V_12 = V_16 ;
break;
case V_17 :
V_4 -> V_12 = V_18 ;
break;
default:
V_4 -> V_12 = V_13 ;
break;
}
V_4 -> V_10 = (enum V_19 ) ( ( V_7 &
V_20 ) >>
V_21 ) ;
}
V_6 = F_3 ( V_22 ) ;
V_4 -> V_23 = ( V_6 & V_24 ) >> V_25 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
T_2 V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
F_5 ( V_28 , V_26 , 0 ) ;
F_6 () ;
}
}
static void F_7 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_29 )
{
F_5 ( V_28 , V_26 , V_29 ) ;
F_6 () ;
}
void F_8 ( struct V_1 * V_2 , T_3 V_30 )
{
T_2 V_31 ;
T_4 V_32 [ V_33 ] = { 0 } ;
F_9 ( L_1 ) ;
V_2 -> V_34 . V_35 . V_36 ( V_2 , V_2 -> V_34 . V_37 , 0 ) ;
F_9 ( L_2 , V_30 - 1 ) ;
for ( V_31 = 1 ; V_31 < V_30 ; V_31 ++ )
V_2 -> V_34 . V_35 . V_36 ( V_2 , V_32 , V_31 ) ;
}
T_1 F_10 ( struct V_1 * V_2 , T_2 V_38 , bool V_39 )
{
T_2 V_40 = ( V_38 >> V_41 ) & V_42 ;
T_2 V_43 = 1 << ( V_38 & V_44 ) ;
T_2 V_45 = F_11 ( V_28 , V_40 ) ;
T_1 V_5 = 0 ;
if ( ( ! ! ( V_45 & V_43 ) ) == V_39 ) {
V_5 = - V_46 ;
} else {
if ( V_39 )
V_45 |= V_43 ;
else
V_45 &= ~ V_43 ;
}
F_7 ( V_2 , V_40 , V_45 ) ;
return V_5 ;
}
T_1 F_12 ( struct V_1 * V_2 )
{
T_2 V_31 ;
T_1 V_5 = 0 ;
T_3 V_26 , V_47 , V_48 ;
T_4 V_49 [ V_33 ] ;
V_5 = V_2 -> V_50 . V_35 . V_51 ( V_2 , V_52 , 1 ,
& V_47 ) ;
if ( V_5 ) {
F_9 ( L_3 ) ;
goto V_53;
}
if ( V_47 == 0xFFFF ) {
goto V_53;
}
if ( V_2 -> V_4 . V_23 == V_54 )
V_47 += V_55 ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 += 2 ) {
V_26 = V_47 + ( V_31 >> 1 ) ;
V_5 = V_2 -> V_50 . V_35 . V_51 ( V_2 , V_26 , 1 , & V_48 ) ;
if ( V_5 ) {
F_9 ( L_3 ) ;
goto V_53;
}
V_49 [ V_31 ] = ( T_4 ) ( V_48 & 0xFF ) ;
V_49 [ V_31 + 1 ] = ( T_4 ) ( V_48 >> 8 ) ;
}
if ( F_13 ( V_49 ) ) {
F_9 ( L_4 ) ;
goto V_53;
}
V_2 -> V_34 . V_35 . V_36 ( V_2 , V_49 , 0 ) ;
V_53:
return V_5 ;
}
void F_14 ( struct V_1 * V_2 , T_4 * V_37 , T_2 V_40 )
{
T_2 V_56 , V_57 ;
V_56 = ( ( T_2 ) V_37 [ 0 ] |
( ( T_2 ) V_37 [ 1 ] << 8 ) |
( ( T_2 ) V_37 [ 2 ] << 16 ) | ( ( T_2 ) V_37 [ 3 ] << 24 ) ) ;
V_57 = ( ( T_2 ) V_37 [ 4 ] | ( ( T_2 ) V_37 [ 5 ] << 8 ) ) ;
if ( V_56 || V_57 )
V_57 |= V_58 ;
F_15 ( F_16 ( V_40 ) , V_56 ) ;
F_6 () ;
F_15 ( F_17 ( V_40 ) , V_57 ) ;
F_6 () ;
}
void F_18 ( struct V_1 * V_2 , T_2 V_59 )
{
T_2 V_60 , V_61 , V_62 ;
V_61 = ( V_59 >> 5 ) & ( V_2 -> V_34 . V_63 - 1 ) ;
V_60 = V_59 & 0x1F ;
V_62 = F_11 ( V_64 , V_61 ) ;
V_62 |= ( 1 << V_60 ) ;
F_5 ( V_64 , V_61 , V_62 ) ;
F_6 () ;
}
static T_2 F_19 ( struct V_1 * V_2 , T_4 * V_65 )
{
T_2 V_59 , V_66 ;
T_4 V_67 = 0 ;
V_66 = ( V_2 -> V_34 . V_63 * 32 ) - 1 ;
while ( V_66 >> V_67 != 0xFF )
V_67 ++ ;
switch ( V_2 -> V_34 . V_68 ) {
default:
case 0 :
break;
case 1 :
V_67 += 1 ;
break;
case 2 :
V_67 += 2 ;
break;
case 3 :
V_67 += 4 ;
break;
}
V_59 = V_66 & ( ( ( V_65 [ 4 ] >> ( 8 - V_67 ) ) |
( ( ( T_3 ) V_65 [ 5 ] ) << V_67 ) ) ) ;
return V_59 ;
}
void F_20 ( struct V_1 * V_2 ,
T_4 * V_69 , T_2 V_70 )
{
T_2 V_59 , V_60 , V_61 ;
int V_31 ;
memset ( & V_2 -> V_34 . V_71 , 0 , sizeof( V_2 -> V_34 . V_71 ) ) ;
for ( V_31 = 0 ; ( T_2 ) V_31 < V_70 ; V_31 ++ ) {
V_59 = F_19 ( V_2 , V_69 ) ;
V_61 = ( V_59 >> 5 ) & ( V_2 -> V_34 . V_63 - 1 ) ;
V_60 = V_59 & 0x1F ;
V_2 -> V_34 . V_71 [ V_61 ] |= ( 1 << V_60 ) ;
V_69 += ( V_33 ) ;
}
for ( V_31 = V_2 -> V_34 . V_63 - 1 ; V_31 >= 0 ; V_31 -- )
F_5 ( V_64 , V_31 , V_2 -> V_34 . V_71 [ V_31 ] ) ;
F_6 () ;
}
void F_21 ( struct V_1 * V_2 )
{
F_3 ( V_72 ) ;
F_3 ( V_73 ) ;
F_3 ( V_74 ) ;
F_3 ( V_75 ) ;
F_3 ( V_76 ) ;
F_3 ( V_77 ) ;
F_3 ( V_78 ) ;
F_3 ( V_79 ) ;
F_3 ( V_80 ) ;
F_3 ( V_81 ) ;
F_3 ( V_82 ) ;
F_3 ( V_83 ) ;
F_3 ( V_84 ) ;
F_3 ( V_85 ) ;
F_3 ( V_86 ) ;
F_3 ( V_87 ) ;
F_3 ( V_88 ) ;
F_3 ( V_89 ) ;
F_3 ( V_90 ) ;
F_3 ( V_91 ) ;
F_3 ( V_92 ) ;
F_3 ( V_93 ) ;
F_3 ( V_94 ) ;
F_3 ( V_95 ) ;
F_3 ( V_96 ) ;
F_3 ( V_97 ) ;
F_3 ( V_98 ) ;
F_3 ( V_99 ) ;
F_3 ( V_100 ) ;
F_3 ( V_101 ) ;
F_3 ( V_102 ) ;
F_3 ( V_103 ) ;
F_3 ( V_104 ) ;
F_3 ( V_105 ) ;
F_3 ( V_106 ) ;
F_3 ( V_107 ) ;
F_3 ( V_108 ) ;
}
T_1 F_22 ( struct V_1 * V_2 )
{
struct V_109 * V_34 = & V_2 -> V_34 ;
T_1 V_5 ;
bool V_110 ;
if ( ! V_34 -> V_111 ) {
V_5 = 0 ;
goto V_53;
}
V_5 = F_23 ( V_2 , 1 , 0 , & V_110 ) ;
if ( V_5 )
goto V_53;
if ( ! V_110 )
goto V_53;
V_34 -> V_111 = false ;
F_24 ( V_2 ) ;
if ( ! V_34 -> V_112 ) {
V_5 = - V_46 ;
goto V_53;
}
F_25 ( V_2 ) ;
V_5 = F_26 ( V_2 ) ;
if ( V_5 )
F_9 ( L_5 ) ;
V_53:
return V_5 ;
}
T_1 F_27 ( struct V_1 * V_2 )
{
T_1 V_5 = 0 ;
if ( F_28 ( V_2 ) )
goto V_53;
if ( V_2 -> V_113 . V_114 == V_115 ) {
V_5 = F_29 ( V_2 ) ;
if ( V_5 )
goto V_53;
}
V_2 -> V_113 . V_116 = V_2 -> V_113 . V_114 ;
F_9 ( L_6 , V_2 -> V_113 . V_116 ) ;
V_5 = V_2 -> V_34 . V_35 . V_117 ( V_2 ) ;
if ( V_5 )
goto V_53;
F_9 ( L_7 ) ;
F_15 ( V_118 , V_119 ) ;
F_15 ( V_120 , V_121 ) ;
F_15 ( V_122 , V_123 ) ;
F_15 ( V_124 , V_2 -> V_113 . V_125 ) ;
V_5 = F_30 ( V_2 ) ;
V_53:
return V_5 ;
}
void F_25 ( struct V_1 * V_2 )
{
T_2 V_126 ;
V_126 = F_3 ( V_127 ) ;
V_126 &= ~ V_128 ;
V_126 |= V_129 << V_130 ;
F_15 ( V_127 , V_126 ) ;
F_6 () ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
T_1 V_5 = 0 ;
T_2 V_131 = 0 , V_132 = 0 ;
if ( V_2 -> V_113 . V_116 & V_133 ) {
V_131 = V_2 -> V_113 . V_134 ;
if ( V_2 -> V_113 . V_135 )
V_131 |= V_136 ;
V_132 = V_2 -> V_113 . V_137 ;
}
F_15 ( V_138 , V_131 ) ;
F_15 ( V_139 , V_132 ) ;
return V_5 ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
T_1 V_5 = 0 ;
T_3 V_48 ;
V_5 = V_2 -> V_50 . V_35 . V_51 ( V_2 , V_140 , 1 , & V_48 ) ;
if ( V_5 ) {
F_9 ( L_3 ) ;
goto V_53;
}
if ( ( V_48 & V_141 ) == 0 )
V_2 -> V_113 . V_114 = V_142 ;
else if ( ( V_48 & V_141 ) ==
V_143 )
V_2 -> V_113 . V_114 = V_133 ;
else
V_2 -> V_113 . V_114 = V_144 ;
V_53:
return V_5 ;
}
T_1 F_31 ( struct V_1 * V_2 )
{
T_2 V_145 ;
T_1 V_5 = 0 ;
V_145 = F_3 ( V_146 ) ;
F_9 ( L_8 , V_2 -> V_113 . V_116 ) ;
switch ( V_2 -> V_113 . V_116 ) {
case V_142 :
V_145 &= ( ~ ( V_147 | V_148 ) ) ;
break;
case V_149 :
V_145 &= ( ~ V_147 ) ;
V_145 |= V_148 ;
break;
case V_133 :
V_145 &= ( ~ V_148 ) ;
V_145 |= V_147 ;
break;
case V_144 :
V_145 |= ( V_147 | V_148 ) ;
break;
default:
F_9 ( L_9 ) ;
V_5 = - V_46 ;
goto V_53;
}
F_15 ( V_146 , V_145 ) ;
V_53:
return V_5 ;
}
T_1 F_26 ( struct V_1 * V_2 )
{
struct V_109 * V_34 = & V_2 -> V_34 ;
T_1 V_5 = 0 ;
T_3 V_150 , V_151 , V_152 ;
T_3 V_12 , V_153 ;
if ( V_34 -> V_154 ) {
if ( V_2 -> V_155 . V_156 == V_157 )
V_5 = F_31 ( V_2 ) ;
} else {
if ( V_2 -> V_155 . V_156 == V_158 )
V_5 = F_31 ( V_2 ) ;
}
if ( V_5 ) {
F_9 ( L_10 ) ;
goto V_53;
}
if ( ( V_2 -> V_155 . V_156 == V_158 ) && V_34 -> V_112 ) {
V_5 = V_2 -> V_155 . V_35 . V_159 ( V_2 , V_160 ,
& V_150 ) ;
if ( V_5 )
goto V_53;
V_5 = V_2 -> V_155 . V_35 . V_159 ( V_2 , V_160 ,
& V_150 ) ;
if ( V_5 )
goto V_53;
if ( ! ( V_150 & V_161 ) ) {
F_9 ( L_11
L_12 ) ;
goto V_53;
}
V_5 = V_2 -> V_155 . V_35 . V_159 ( V_2 , V_162 ,
& V_151 ) ;
if ( V_5 )
goto V_53;
V_5 = V_2 -> V_155 . V_35 . V_159 ( V_2 , V_163 ,
& V_152 ) ;
if ( V_5 )
goto V_53;
if ( ( V_151 & V_164 ) &&
( V_152 & V_165 ) ) {
if ( V_2 -> V_113 . V_114 == V_144 ) {
V_2 -> V_113 . V_116 = V_144 ;
F_9 ( L_13 ) ;
} else {
V_2 -> V_113 . V_116 = V_149 ;
F_9 ( L_14
L_15 ) ;
}
}
else if ( ! ( V_151 & V_164 ) &&
( V_151 & V_166 ) &&
( V_152 & V_165 ) &&
( V_152 & V_167 ) ) {
V_2 -> V_113 . V_116 = V_133 ;
F_9 ( L_16 ) ;
}
else if ( ( V_151 & V_164 ) &&
( V_151 & V_166 ) &&
! ( V_152 & V_165 ) &&
( V_152 & V_167 ) ) {
V_2 -> V_113 . V_116 = V_149 ;
F_9 ( L_17 ) ;
}
else if ( ( V_2 -> V_113 . V_114 == V_142 ||
V_2 -> V_113 . V_114 == V_133 ) ||
V_2 -> V_113 . V_168 ) {
V_2 -> V_113 . V_116 = V_142 ;
F_9 ( L_18 ) ;
} else {
V_2 -> V_113 . V_116 = V_149 ;
F_9 ( L_17 ) ;
}
V_5 = V_2 -> V_34 . V_35 . V_169 ( V_2 , & V_12 , & V_153 ) ;
if ( V_5 ) {
F_9 ( L_19 ) ;
goto V_53;
}
if ( V_153 == V_170 )
V_2 -> V_113 . V_116 = V_142 ;
V_5 = F_31 ( V_2 ) ;
if ( V_5 ) {
F_9 ( L_10 ) ;
goto V_53;
}
}
V_53:
return V_5 ;
}
T_1 F_32 ( struct V_1 * V_2 , T_3 * V_12 ,
T_3 * V_153 )
{
T_2 V_171 ;
V_171 = F_3 ( V_22 ) ;
if ( V_171 & V_172 ) {
* V_12 = V_173 ;
F_9 ( L_20 ) ;
} else if ( V_171 & V_174 ) {
* V_12 = V_175 ;
F_9 ( L_21 ) ;
} else {
* V_12 = V_176 ;
F_9 ( L_22 ) ;
}
if ( V_171 & V_177 ) {
* V_153 = V_178 ;
F_9 ( L_23 ) ;
} else {
* V_153 = V_170 ;
F_9 ( L_24 ) ;
}
return 0 ;
}
T_1 F_33 ( struct V_1 * V_2 )
{
T_2 V_179 ;
T_1 V_5 = 0 ;
T_1 V_180 = V_2 -> V_50 . V_181 + 1 ;
T_1 V_31 = 0 ;
while ( V_31 < V_180 ) {
V_179 = F_3 ( V_182 ) ;
if ( ! ( V_179 & V_183 ) )
break;
F_34 ( 50 ) ;
V_31 ++ ;
}
if ( V_31 == V_180 ) {
F_9 ( L_25 ) ;
V_5 = - V_184 ;
goto V_53;
}
for ( V_31 = 0 ; V_31 < V_180 ; V_31 ++ ) {
V_179 = F_3 ( V_182 ) ;
F_15 ( V_182 , V_179 | V_185 ) ;
if ( F_3 ( V_182 ) & V_185 )
break;
F_34 ( 50 ) ;
}
if ( V_31 == V_180 ) {
F_35 ( V_2 ) ;
F_9 ( L_26 ) ;
V_5 = - V_184 ;
goto V_53;
}
V_53:
return V_5 ;
}
void F_35 ( struct V_1 * V_2 )
{
T_2 V_179 ;
V_179 = F_3 ( V_182 ) ;
V_179 &= ~ ( V_183 | V_185 ) ;
F_15 ( V_182 , V_179 ) ;
}
T_1 F_36 ( struct V_1 * V_2 )
{
T_1 V_31 = 0 ;
T_1 V_5 = 0 ;
while ( V_31 < V_186 ) {
if ( F_3 ( V_187 ) & V_188 )
break;
F_37 ( 1 ) ;
V_31 ++ ;
}
if ( V_31 == V_186 ) {
F_9 ( L_27 ) ;
V_5 = - V_189 ;
goto V_53;
}
V_53:
return V_5 ;
}
static T_1 F_38 ( struct V_1 * V_2 , T_3 * V_190 )
{
T_1 V_5 ;
V_5 = V_2 -> V_50 . V_35 . V_51 ( V_2 , V_191 , 1 , V_190 ) ;
if ( V_5 ) {
F_9 ( L_3 ) ;
goto V_53;
}
if ( * V_190 == V_192 || * V_190 == V_193 ) {
switch( V_2 -> V_155 . V_156 ) {
case V_157 :
* V_190 = V_194 ;
break;
case V_158 :
default:
* V_190 = V_195 ;
break;
}
}
V_53:
return V_5 ;
}
T_1 F_39 ( struct V_1 * V_2 )
{
struct V_109 * V_34 = & V_2 -> V_34 ;
T_1 V_5 ;
const T_2 V_196 = 0x000000FF ;
const T_2 V_197 = V_198 ;
const T_2 V_199 = V_200 ;
T_3 V_190 , V_31 , V_201 ;
const T_3 V_202 = 0x0F ;
V_5 = F_38 ( V_2 , & V_190 ) ;
if ( V_5 )
goto V_53;
V_34 -> V_203 = F_3 ( V_204 ) ;
V_34 -> V_205 = V_34 -> V_203 ;
V_34 -> V_206 = V_34 -> V_203 ;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
V_201 = ( V_190 >> ( V_31 << 2 ) ) & V_202 ;
switch ( V_201 ) {
case V_207 :
case V_208 :
case V_209 :
V_34 -> V_205 &= ~ ( V_196 << ( V_31 << 3 ) ) ;
V_34 -> V_205 |= V_197 << ( V_31 << 3 ) ;
break;
case V_210 :
case V_211 :
case V_212 :
V_34 -> V_205 &= ~ ( V_196 << ( V_31 << 3 ) ) ;
V_34 -> V_205 |= V_199 << ( V_31 << 3 ) ;
break;
default:
break;
}
switch ( V_201 ) {
case V_213 :
case V_208 :
case V_211 :
V_34 -> V_206 &= ~ ( V_196 << ( V_31 << 3 ) ) ;
V_34 -> V_206 |= V_197 << ( V_31 << 3 ) ;
break;
case V_214 :
case V_209 :
case V_212 :
V_34 -> V_206 &= ~ ( V_196 << ( V_31 << 3 ) ) ;
V_34 -> V_206 |= V_199 << ( V_31 << 3 ) ;
break;
default:
break;
}
}
V_53:
return V_5 ;
}
T_1 F_40 ( struct V_1 * V_2 )
{
F_15 ( V_204 , V_2 -> V_34 . V_203 ) ;
return 0 ;
}
T_1 F_41 ( struct V_1 * V_2 )
{
T_2 V_215 = 0 ;
T_2 V_31 ;
V_215 = V_2 -> V_34 . V_206 ;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ )
if ( ( ( V_2 -> V_34 . V_206 >> ( V_31 * 8 ) ) & 0xFF ) ==
V_198 )
V_215 |= ( V_216 <<
( V_31 * 8 ) ) ;
F_15 ( V_204 , V_215 ) ;
return 0 ;
}
T_1 F_42 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_155 . V_156 ) {
case V_158 :
F_15 ( V_204 , V_2 -> V_34 . V_205 ) ;
break;
default:
break;
}
return 0 ;
}
T_1 F_43 ( struct V_1 * V_2 )
{
T_2 V_145 ;
T_1 V_180 = V_217 ;
T_1 V_5 = 0 ;
if ( V_2 -> V_4 . type != V_8 )
goto V_53;
V_145 = F_3 ( V_146 ) ;
V_145 |= V_218 ;
F_15 ( V_146 , V_145 ) ;
while ( V_180 ) {
if ( ! ( F_3 ( V_22 ) &
V_219 ) )
break;
F_34 ( 100 ) ;
V_180 -- ;
}
if ( ! V_180 ) {
F_9 ( L_28 ) ;
V_5 = - V_220 ;
goto V_53;
}
V_53:
return V_5 ;
}
T_1 F_44 ( struct V_1 * V_2 )
{
T_1 V_5 = 0 ;
if ( ! V_2 -> V_34 . V_112 && ( V_2 -> V_155 . V_221 == 0 || V_2 -> V_155 . V_221 == 3 ) ) {
F_9 ( L_29 ) ;
V_2 -> V_155 . V_221 = 1 ;
V_5 = - V_46 ;
goto V_53;
}
V_53:
return V_5 ;
}
T_1 F_45 ( struct V_1 * V_2 , T_2 V_6 ,
T_2 V_26 , T_4 V_190 )
{
T_2 V_31 , V_222 = 0 ;
T_1 V_5 = 0 ;
V_222 = ( ( T_2 ) V_190 ) | ( V_26 << V_223 ) ;
F_15 ( V_6 , V_222 ) ;
for ( V_31 = 0 ; V_31 < V_224 ; V_31 ++ ) {
F_34 ( 5 ) ;
V_222 = F_3 ( V_6 ) ;
if ( V_222 & V_225 )
break;
}
if ( ! ( V_222 & V_225 ) ) {
F_9 ( L_30 , V_6 ) ;
V_5 = - V_226 ;
goto V_53;
}
V_53:
return V_5 ;
}
bool F_46 ( struct V_1 * V_2 )
{
T_2 V_227 ;
T_2 V_228 , V_229 ;
bool V_5 = false ;
if ( ! V_2 -> V_34 . V_230 )
goto V_53;
V_227 = F_3 ( V_231 ) ;
if ( ! ( V_227 & V_232 ) )
goto V_53;
if ( V_2 -> V_34 . V_233 ) {
V_228 = F_3 ( V_234 ) ;
V_229 = F_3 ( V_235 ) ;
if ( ! ( V_229 & V_236 ) &&
( ( V_228 & V_237 ) ==
( V_238 << V_239 ) ) ) {
V_5 = true ;
goto V_53;
}
} else {
if ( ( V_227 & V_240 ) &&
! ( V_227 & V_241 ) ) {
V_5 = true ;
goto V_53;
}
}
V_53:
return V_5 ;
}
