static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
if ( V_2 -> V_5 == V_6 )
V_2 -> V_7 |= V_8 ;
return V_9 | V_10 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
if ( V_2 -> V_13 )
V_2 -> V_7 |= V_14 ;
memcpy ( V_2 -> V_15 , V_12 -> V_16 , sizeof( V_2 -> V_15 ) ) ;
return F_1 ( V_2 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_1 V_17 )
{
struct V_18 * V_19 = (struct V_18 * ) & V_2 -> V_15 ;
struct V_20 * V_21 = F_4 ( V_12 ) -> V_21 ;
T_2 V_22 , V_23 , V_24 ;
if ( V_2 -> V_13 || ( V_21 -> V_25 == 0 ) )
V_2 -> V_7 |= V_14 ;
V_19 -> V_26 = 1 ;
V_19 -> V_27 = 1 ;
V_19 -> V_28 = 1 ;
V_19 -> V_29 = V_12 -> V_30 ;
V_19 -> V_31 = F_4 ( V_12 ) -> V_32 ;
V_19 -> V_33 = V_21 -> V_25 ;
V_19 -> V_34 = V_21 -> V_25 ;
V_19 -> V_35 = F_5 ( F_6 ( V_21 ) ) ;
V_19 -> V_36 = F_5 ( V_21 -> V_37 ) ;
V_23 = V_21 -> V_38 ;
V_24 = V_21 -> V_39 ;
V_19 -> V_40 = F_7 ( ( V_23 << 16 ) | V_24 ) ;
V_19 -> V_41 = V_17 ;
V_22 = V_21 -> V_42 ;
V_19 -> V_43 [ 0 ] = V_44 ;
V_19 -> V_43 [ 1 ] = V_45 ;
V_19 -> V_43 [ 2 ] = V_46 ;
return F_1 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
T_2 V_47 = 8 * F_9 ( V_2 -> V_13 ) ;
T_3 * V_48 = ( T_3 * ) V_2 -> V_15 ;
memset ( V_2 -> V_15 , 0 , sizeof( V_2 -> V_15 ) ) ;
if ( V_47 == 0 ) {
T_3 V_49 = F_4 ( V_12 ) -> V_21 -> V_25 ;
if ( V_49 == 0 )
V_2 -> V_7 |= V_14 ;
else
* V_48 = V_49 ;
} else
V_2 -> V_7 |= V_14 ;
return F_1 ( V_2 ) ;
}
static void F_10 ( struct V_20 * V_21 , T_2 V_50 )
{
( void ) V_21 -> V_51 ( V_21 , V_52 , V_50 ) ;
}
static void F_11 ( struct V_20 * V_21 , T_2 V_53 )
{
( void ) V_21 -> V_51 ( V_21 , V_54 , V_53 ) ;
}
static int F_12 ( struct V_20 * V_21 )
{
return ( V_21 -> V_55 >>
V_56 ) &
V_57 ;
}
static int F_13 ( struct V_20 * V_21 , unsigned V_58 )
{
unsigned V_59 ;
V_59 = ( V_21 -> V_55 >> V_56 ) &
V_57 ;
if ( V_59 != V_58 ) {
V_21 -> V_55 &=
~ ( V_57 <<
V_56 ) ;
V_21 -> V_55 |=
( V_60 ) V_58 << V_56 ;
F_14 ( V_21 , V_21 -> V_61 -> V_62 ,
V_21 -> V_55 ) ;
}
return 0 ;
}
static int F_15 ( struct V_20 * V_21 )
{
return ( V_21 -> V_55 >>
V_63 ) &
V_64 ;
}
static int F_16 ( struct V_20 * V_21 , unsigned V_58 )
{
unsigned V_59 ;
V_59 = ( V_21 -> V_55 >> V_63 ) &
V_64 ;
if ( V_59 != V_58 ) {
V_21 -> V_55 &=
~ ( V_64 <<
V_63 ) ;
V_21 -> V_55 |=
( V_60 ) V_58 << V_63 ;
F_14 ( V_21 , V_21 -> V_61 -> V_62 ,
V_21 -> V_55 ) ;
}
return 0 ;
}
static int F_17 ( struct V_20 * V_21 )
{
return ! ! ( V_21 -> V_55 & V_65 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_1 V_17 )
{
struct V_66 * V_67 ;
struct V_20 * V_21 ;
struct V_68 * V_69 = (struct V_68 * ) V_2 -> V_15 ;
T_4 V_70 ;
T_1 V_71 ;
T_1 V_72 ;
int V_73 ;
if ( F_9 ( V_2 -> V_13 ) > V_12 -> V_30 ) {
V_2 -> V_7 |= V_14 ;
V_73 = F_1 ( V_2 ) ;
goto V_74;
}
V_67 = F_4 ( V_12 ) ;
V_21 = V_67 -> V_21 ;
memset ( V_2 -> V_15 , 0 , sizeof( V_2 -> V_15 ) ) ;
if ( V_2 -> V_3 == V_75 || V_67 -> V_76 == V_2 -> V_76 ||
V_67 -> V_77 == 0 )
V_69 -> V_76 = V_67 -> V_76 ;
V_69 -> V_78 = V_67 -> V_78 ;
V_70 = V_21 -> V_79 ;
V_69 -> V_70 = V_70 ? F_5 ( V_70 ) : V_80 ;
V_69 -> V_81 = F_5 ( V_67 -> V_81 ) ;
V_69 -> V_82 = F_7 ( V_67 -> V_83 ) ;
V_69 -> V_84 = F_5 ( V_67 -> V_84 ) ;
V_69 -> V_41 = V_17 ;
V_69 -> V_85 = V_21 -> V_86 ;
V_69 -> V_87 = V_21 -> V_88 ;
V_69 -> V_89 = V_21 -> V_90 ;
V_69 -> V_91 = V_21 -> V_92 << 4 ;
V_71 = V_21 -> V_93 ;
V_69 -> V_91 |= F_19 ( V_21 , V_71 ) + 1 ;
V_69 -> V_94 =
( V_95 [ V_71 & V_21 -> V_96 ] << 4 ) |
( F_17 ( V_21 ) ? 1 : 2 ) ;
V_69 -> V_97 = ( V_67 -> V_77 << 6 ) | V_21 -> V_98 ;
V_69 -> V_99 = ( V_21 -> V_100 << 4 ) |
V_21 -> V_101 ;
switch ( V_21 -> V_102 ) {
case 4096 :
V_72 = V_103 ;
break;
case 2048 :
V_72 = V_104 ;
break;
case 1024 :
V_72 = V_105 ;
break;
case 512 :
V_72 = V_106 ;
break;
case 256 :
V_72 = V_107 ;
break;
default:
V_72 = V_104 ;
break;
}
V_69 -> V_108 = ( V_72 << 4 ) | V_67 -> V_109 ;
V_69 -> V_110 = 0x10 ;
V_69 -> V_111 = V_67 -> V_111 ;
V_69 -> V_112 = V_113 ? V_103 : V_104 ;
V_69 -> V_114 = 0x10 ;
V_69 -> V_115 = F_5 ( V_67 -> V_115 ) ;
V_69 -> V_116 =
F_5 ( ( F_20 ( V_21 ) -
V_67 -> V_117 ) & 0xFFFF ) ;
V_69 -> V_118 = F_5 ( V_67 -> V_118 ) ;
V_69 -> V_119 = 1 ;
V_69 -> V_120 = V_67 -> V_121 ;
V_69 -> V_122 = 3 ;
V_69 -> V_123 =
( F_15 ( V_21 ) << 4 ) |
F_12 ( V_21 ) ;
if ( V_67 -> V_83 & V_124 ) {
T_2 V_59 ;
V_59 = V_21 -> V_125 ( V_21 , V_126 ) ;
V_69 -> V_127 [ 0 ] = V_59 >> 16 ;
V_69 -> V_127 [ 1 ] = V_59 >> 8 ;
V_69 -> V_127 [ 2 ] = V_59 ;
}
V_73 = F_1 ( V_2 ) ;
V_74:
return V_73 ;
}
static int F_21 ( struct V_20 * V_21 , T_4 * V_128 )
{
struct V_129 * V_130 = V_21 -> V_131 [ 0 ] ;
memcpy ( V_128 , V_130 -> V_132 , sizeof( V_130 -> V_132 ) ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
T_2 V_133 = 32 * ( F_9 ( V_2 -> V_13 ) & 0xffff ) ;
T_4 * V_48 = ( T_4 * ) V_2 -> V_15 ;
T_5 * V_134 = ( T_5 * ) V_2 -> V_15 ;
memset ( V_2 -> V_15 , 0 , sizeof( V_2 -> V_15 ) ) ;
if ( V_133 == 0 ) {
struct V_66 * V_67 = F_4 ( V_12 ) ;
unsigned V_135 , V_58 = F_6 ( V_67 -> V_21 ) ;
F_21 ( V_67 -> V_21 , V_48 ) ;
for ( V_135 = 0 ; V_135 < V_58 ; V_135 ++ )
V_134 [ V_135 ] = F_5 ( V_48 [ V_135 ] ) ;
} else
V_2 -> V_7 |= V_14 ;
return F_1 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
return F_8 ( V_2 , V_12 ) ;
}
static int F_24 ( struct V_20 * V_21 , int V_136 )
{
if ( V_136 )
V_21 -> V_55 |= V_65 ;
else
V_21 -> V_55 &= ~ V_65 ;
F_14 ( V_21 , V_21 -> V_61 -> V_62 ,
V_21 -> V_55 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_1 V_17 )
{
struct V_68 * V_69 = (struct V_68 * ) V_2 -> V_15 ;
struct V_137 V_138 ;
struct V_66 * V_67 ;
struct V_20 * V_21 ;
char V_139 = 0 ;
T_4 V_70 , V_140 ;
T_1 V_141 ;
T_1 V_142 ;
T_1 V_143 ;
T_4 V_144 ;
T_2 V_72 ;
int V_73 , V_145 ;
if ( F_9 ( V_2 -> V_13 ) > V_12 -> V_30 )
goto V_146;
V_67 = F_4 ( V_12 ) ;
V_21 = V_67 -> V_21 ;
V_138 . V_147 = V_12 ;
V_138 . V_148 . V_149 = V_17 ;
V_67 -> V_76 = V_69 -> V_76 ;
V_67 -> V_78 = V_69 -> V_78 ;
V_67 -> V_84 = F_26 ( V_69 -> V_84 ) ;
V_70 = F_26 ( V_69 -> V_70 ) ;
if ( V_21 -> V_79 != V_70 ||
V_21 -> V_98 != ( V_69 -> V_97 & 7 ) ) {
if ( V_70 == 0 || V_70 >= V_150 )
goto V_146;
F_27 ( V_21 , V_70 , V_69 -> V_97 & 7 ) ;
V_138 . V_138 = V_151 ;
F_28 ( & V_138 ) ;
}
V_140 = F_26 ( V_69 -> V_81 ) ;
if ( V_140 != V_67 -> V_81 ) {
if ( V_140 == 0 || V_140 >= V_150 )
goto V_146;
V_67 -> V_81 = V_140 ;
V_138 . V_138 = V_152 ;
F_28 ( & V_138 ) ;
}
V_141 = V_69 -> V_85 ;
if ( V_141 ) {
if ( V_141 == 0xFF )
V_141 = V_21 -> V_88 ;
else if ( V_141 >= 16 || ( V_141 & ~ V_21 -> V_88 ) )
goto V_146;
F_10 ( V_21 , V_141 ) ;
}
V_142 = V_69 -> V_99 & 0xF ;
if ( V_142 ) {
if ( V_142 == 15 )
V_142 = V_21 -> V_92 ;
else if ( V_142 >= 8 || ( V_142 & ~ V_21 -> V_92 ) )
goto V_146;
F_11 ( V_21 , V_142 ) ;
}
switch ( V_69 -> V_94 & 0xF ) {
case 0 :
break;
case 1 :
if ( F_24 ( V_21 , 1 ) )
goto V_146;
break;
case 2 :
if ( F_24 ( V_21 , 0 ) )
goto V_146;
break;
default:
goto V_146;
}
V_67 -> V_77 = V_69 -> V_97 >> 6 ;
V_67 -> V_111 = V_69 -> V_111 ;
switch ( ( V_69 -> V_108 >> 4 ) & 0xF ) {
case V_107 :
V_72 = 256 ;
break;
case V_106 :
V_72 = 512 ;
break;
case V_105 :
V_72 = 1024 ;
break;
case V_104 :
V_72 = 2048 ;
break;
case V_103 :
if ( ! V_113 )
goto V_146;
V_72 = 4096 ;
break;
default:
goto V_146;
}
F_29 ( V_21 , V_72 ) ;
V_67 -> V_109 = V_69 -> V_108 & 0xF ;
if ( ( ( V_69 -> V_114 >> 4 ) & 0xF ) > 1 )
goto V_146;
if ( V_69 -> V_115 == 0 )
V_67 -> V_115 = 0 ;
if ( V_69 -> V_116 == 0 )
V_67 -> V_117 = F_20 ( V_21 ) ;
if ( V_69 -> V_118 == 0 )
V_67 -> V_118 = 0 ;
V_145 = V_69 -> V_123 ;
if ( F_16 ( V_21 , ( V_145 >> 4 ) & 0xF ) )
goto V_146;
if ( F_13 ( V_21 , ( V_145 & 0xF ) ) )
goto V_146;
V_67 -> V_121 = V_69 -> V_120 & 0x1F ;
if ( V_69 -> V_120 & 0x80 ) {
V_139 = 1 ;
V_138 . V_138 = V_153 ;
F_28 ( & V_138 ) ;
}
V_143 = V_69 -> V_91 & 0xF ;
V_144 = ( V_69 -> V_94 >> 4 ) & 0xF ;
if ( V_144 && ! ( V_143 == V_154 || V_143 == V_155 ) )
goto V_146;
switch ( V_143 ) {
case V_155 :
if ( V_144 == 0 )
break;
case V_154 :
if ( V_144 == 0 )
V_144 = V_156 ;
else if ( V_144 == 1 )
V_144 = V_157 ;
else if ( V_144 == 2 )
V_144 = V_158 ;
else if ( V_144 == 3 )
V_144 = V_159 ;
else
goto V_146;
F_30 ( V_21 , V_144 ) ;
if ( V_144 == V_159 ) {
V_73 = V_9 | V_160 ;
goto V_161;
}
F_31 ( V_21 , V_162 | V_163 |
V_164 , 1000 ) ;
break;
case V_165 :
F_30 ( V_21 , V_166 ) ;
break;
case V_167 :
F_30 ( V_21 , V_168 ) ;
break;
default:
goto V_146;
}
V_73 = F_18 ( V_2 , V_12 , V_17 ) ;
if ( V_139 )
V_69 -> V_120 |= 0x80 ;
goto V_161;
V_146:
V_2 -> V_7 |= V_14 ;
V_73 = F_18 ( V_2 , V_12 , V_17 ) ;
V_161:
return V_73 ;
}
static int F_32 ( struct V_20 * V_21 , T_4 V_169 )
{
int V_135 ;
int V_73 ;
for ( V_135 = 0 ; V_135 < F_33 ( V_21 -> V_170 ) ; V_135 ++ ) {
if ( V_21 -> V_170 [ V_135 ] != V_169 )
continue;
if ( F_34 ( & V_21 -> V_171 [ V_135 ] ) ) {
V_21 -> V_170 [ V_135 ] = 0 ;
V_73 = 1 ;
goto V_74;
}
break;
}
V_73 = 0 ;
V_74:
return V_73 ;
}
static int F_35 ( struct V_20 * V_21 , T_4 V_169 )
{
int V_135 ;
T_4 V_172 = V_169 & 0x7FFF ;
int V_173 = 0 ;
int V_73 ;
if ( V_172 == 0x7FFF ) {
V_73 = 0 ;
goto V_74;
}
for ( V_135 = 0 ; V_135 < F_33 ( V_21 -> V_170 ) ; V_135 ++ ) {
if ( ! V_21 -> V_170 [ V_135 ] ) {
V_173 ++ ;
continue;
}
if ( V_21 -> V_170 [ V_135 ] == V_169 ) {
if ( F_36 ( & V_21 -> V_171 [ V_135 ] ) > 1 ) {
V_73 = 0 ;
goto V_74;
}
F_37 ( & V_21 -> V_171 [ V_135 ] ) ;
V_173 ++ ;
}
if ( ( V_21 -> V_170 [ V_135 ] & 0x7FFF ) == V_172 ) {
V_73 = - V_174 ;
goto V_74;
}
}
if ( ! V_173 ) {
V_73 = - V_175 ;
goto V_74;
}
for ( V_135 = 0 ; V_135 < F_33 ( V_21 -> V_170 ) ; V_135 ++ ) {
if ( ! V_21 -> V_170 [ V_135 ] &&
F_36 ( & V_21 -> V_171 [ V_135 ] ) == 1 ) {
V_176 . V_177 [ V_135 ] = V_172 ;
V_21 -> V_170 [ V_135 ] = V_169 ;
V_73 = 1 ;
goto V_74;
}
}
V_73 = - V_175 ;
V_74:
return V_73 ;
}
static int F_38 ( struct V_20 * V_21 , T_4 * V_128 )
{
struct V_129 * V_130 ;
int V_135 ;
int V_178 = 0 ;
V_130 = V_21 -> V_131 [ 0 ] ;
for ( V_135 = 0 ; V_135 < F_33 ( V_130 -> V_132 ) ; V_135 ++ ) {
T_4 V_169 = V_128 [ V_135 ] ;
T_4 V_179 = V_130 -> V_132 [ V_135 ] ;
if ( V_169 == V_179 )
continue;
if ( V_179 & 0x7FFF )
V_178 |= F_32 ( V_21 , V_179 ) ;
if ( V_169 & 0x7FFF ) {
int V_73 = F_35 ( V_21 , V_169 ) ;
if ( V_73 < 0 )
V_169 = 0 ;
else
V_178 |= V_73 ;
}
V_130 -> V_132 [ V_135 ] = V_169 ;
}
if ( V_178 ) {
V_60 V_180 ;
V_180 = ( V_60 ) V_21 -> V_170 [ 0 ] |
( ( V_60 ) V_21 -> V_170 [ 1 ] << 16 ) |
( ( V_60 ) V_21 -> V_170 [ 2 ] << 32 ) |
( ( V_60 ) V_21 -> V_170 [ 3 ] << 48 ) ;
F_39 ( V_181 , L_1 ,
( unsigned long long ) V_180 ) ;
F_14 ( V_21 , V_21 -> V_61 -> V_182 ,
V_180 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
T_2 V_133 = 32 * ( F_9 ( V_2 -> V_13 ) & 0xffff ) ;
T_5 * V_48 = ( T_5 * ) V_2 -> V_15 ;
T_4 * V_134 = ( T_4 * ) V_2 -> V_15 ;
struct V_66 * V_67 = F_4 ( V_12 ) ;
unsigned V_135 , V_58 = F_6 ( V_67 -> V_21 ) ;
for ( V_135 = 0 ; V_135 < V_58 ; V_135 ++ )
V_134 [ V_135 ] = F_26 ( V_48 [ V_135 ] ) ;
if ( V_133 != 0 || F_38 ( V_67 -> V_21 , V_134 ) != 0 )
V_2 -> V_7 |= V_14 ;
return F_22 ( V_2 , V_12 ) ;
}
static int F_41 ( struct V_183 * V_184 )
{
struct V_185 * V_48 =
(struct V_185 * ) V_184 -> V_15 ;
memset ( V_184 -> V_15 , 0 , sizeof( V_184 -> V_15 ) ) ;
if ( V_184 -> V_186 . V_13 != 0 )
V_184 -> V_186 . V_7 |= V_14 ;
V_48 -> V_187 = F_5 ( 1 << 8 ) ;
V_48 -> V_26 = 1 ;
V_48 -> V_27 = 1 ;
V_48 -> V_188 = 18 ;
return F_1 ( (struct V_1 * ) V_184 ) ;
}
static int F_42 ( struct V_183 * V_184 ,
struct V_11 * V_12 , T_1 V_17 )
{
struct V_189 * V_48 =
(struct V_189 * ) V_184 -> V_15 ;
struct V_66 * V_67 = F_4 ( V_12 ) ;
struct V_190 const * V_191 = V_67 -> V_21 -> V_190 ;
unsigned long V_192 ;
T_1 V_193 = V_48 -> V_193 ;
memset ( V_184 -> V_15 , 0 , sizeof( V_184 -> V_15 ) ) ;
V_48 -> V_193 = V_193 ;
if ( V_184 -> V_186 . V_13 != 0 ||
( V_193 != V_17 && V_193 != 0xFF ) )
V_184 -> V_186 . V_7 |= V_14 ;
if ( V_191 -> V_194 )
V_48 -> V_195 = V_67 -> V_21 -> V_100 - 1 ;
else
V_48 -> V_195 = 250 ;
V_48 -> V_196 = 4 ;
V_48 -> V_197 = V_198 ;
F_43 ( & V_67 -> V_199 , V_192 ) ;
if ( V_191 -> V_194 )
V_48 -> V_200 = F_44 ( V_67 -> V_21 , V_191 -> V_194 ) ;
else
V_48 -> V_200 = V_67 -> V_201 ;
V_48 -> V_202 = F_7 ( V_67 -> V_203 ) ;
V_48 -> V_204 = F_7 ( V_67 -> V_205 ) ;
V_48 -> V_206 = F_5 ( V_67 -> V_207 ) ;
V_48 -> V_208 [ 0 ] = V_67 -> V_209 [ 0 ] ;
V_48 -> V_208 [ 1 ] = V_67 -> V_209 [ 1 ] ;
V_48 -> V_208 [ 2 ] = V_67 -> V_209 [ 2 ] ;
V_48 -> V_208 [ 3 ] = V_67 -> V_209 [ 3 ] ;
V_48 -> V_208 [ 4 ] = V_67 -> V_209 [ 4 ] ;
F_45 ( & V_67 -> V_199 , V_192 ) ;
return F_1 ( (struct V_1 * ) V_184 ) ;
}
static int F_46 ( struct V_183 * V_184 ,
struct V_11 * V_12 , T_1 V_17 )
{
struct V_189 * V_48 =
(struct V_189 * ) V_184 -> V_15 ;
struct V_66 * V_67 = F_4 ( V_12 ) ;
struct V_190 const * V_191 = V_67 -> V_21 -> V_190 ;
unsigned long V_192 ;
T_1 V_7 ;
int V_73 ;
if ( V_184 -> V_186 . V_13 != 0 ||
( V_48 -> V_193 != V_17 && V_48 -> V_193 != 0xFF ) ) {
V_184 -> V_186 . V_7 |= V_14 ;
V_73 = F_1 ( (struct V_1 * ) V_184 ) ;
goto V_74;
}
F_43 ( & V_67 -> V_199 , V_192 ) ;
if ( V_191 -> V_194 )
V_7 = F_44 ( V_67 -> V_21 , V_191 -> V_194 ) ;
else
V_7 = V_67 -> V_201 ;
if ( V_7 == V_210 ) {
V_67 -> V_203 = F_9 ( V_48 -> V_202 ) ;
V_67 -> V_205 = F_9 ( V_48 -> V_204 ) ;
V_67 -> V_207 = F_26 ( V_48 -> V_206 ) ;
V_67 -> V_209 [ 0 ] = V_48 -> V_208 [ 0 ] ;
V_67 -> V_209 [ 1 ] = V_48 -> V_208 [ 1 ] ;
V_67 -> V_209 [ 2 ] = V_48 -> V_208 [ 2 ] ;
V_67 -> V_209 [ 3 ] = V_48 -> V_208 [ 3 ] ;
V_67 -> V_209 [ 4 ] = V_48 -> V_208 [ 4 ] ;
if ( V_191 -> V_194 ) {
F_47 ( V_67 -> V_21 , V_191 -> V_211 ,
V_67 -> V_205 ) ;
F_47 ( V_67 -> V_21 , V_191 -> V_212 ,
V_67 -> V_203 ) ;
} else
V_67 -> V_201 = V_213 ;
}
F_45 ( & V_67 -> V_199 , V_192 ) ;
V_73 = F_42 ( V_184 , V_12 , V_17 ) ;
V_74:
return V_73 ;
}
static V_60 F_48 ( struct V_66 * V_67 ,
struct V_190 const * V_191 ,
T_5 V_214 )
{
V_60 V_73 ;
switch ( V_214 ) {
case V_215 :
V_73 = ( V_191 -> V_216 ) ?
F_44 ( V_67 -> V_21 , V_191 -> V_216 ) :
V_67 -> V_217 ;
break;
case V_218 :
V_73 = ( V_191 -> V_219 ) ?
F_44 ( V_67 -> V_21 , V_191 -> V_219 ) :
V_67 -> V_220 ;
break;
case V_221 :
V_73 = ( V_191 -> V_222 ) ?
F_44 ( V_67 -> V_21 , V_191 -> V_222 ) :
V_67 -> V_223 ;
break;
case V_224 :
V_73 = ( V_191 -> V_225 ) ?
F_44 ( V_67 -> V_21 , V_191 -> V_225 ) :
V_67 -> V_226 ;
break;
case V_227 :
V_73 = ( V_191 -> V_228 ) ?
F_44 ( V_67 -> V_21 , V_191 -> V_228 ) :
V_67 -> V_229 ;
break;
default:
V_73 = 0 ;
}
return V_73 ;
}
static int F_49 ( struct V_183 * V_184 ,
struct V_11 * V_12 )
{
struct V_230 * V_48 =
(struct V_230 * ) V_184 -> V_15 ;
struct V_66 * V_67 = F_4 ( V_12 ) ;
struct V_190 const * V_191 = V_67 -> V_21 -> V_190 ;
T_1 V_7 ;
int V_135 ;
memset ( V_184 -> V_15 , 0 , sizeof( V_184 -> V_15 ) ) ;
V_48 -> V_206 = F_5 ( V_67 -> V_207 ) ;
if ( V_191 -> V_194 )
V_7 = F_44 ( V_67 -> V_21 , V_191 -> V_194 ) ;
else
V_7 = V_67 -> V_201 ;
V_48 -> V_200 = F_5 ( V_7 ) ;
for ( V_135 = 0 ; V_135 < F_33 ( V_67 -> V_209 ) ; V_135 ++ )
V_48 -> V_231 [ V_135 ] = ( V_7 != V_210 ) ? 0 :
F_7 (
F_48 ( V_67 , V_191 , V_67 -> V_209 [ V_135 ] ) ) ;
return F_1 ( (struct V_1 * ) V_184 ) ;
}
static int F_50 ( struct V_183 * V_184 ,
struct V_11 * V_12 )
{
struct V_232 * V_48 =
(struct V_232 * ) V_184 -> V_15 ;
struct V_66 * V_67 = F_4 ( V_12 ) ;
struct V_190 const * V_191 = V_67 -> V_21 -> V_190 ;
T_1 V_7 ;
int V_135 ;
memset ( V_184 -> V_15 , 0 , sizeof( V_184 -> V_15 ) ) ;
V_48 -> V_206 = F_5 ( V_67 -> V_207 ) ;
if ( V_191 -> V_194 )
V_7 = F_44 ( V_67 -> V_21 , V_191 -> V_194 ) ;
else
V_7 = V_67 -> V_201 ;
V_48 -> V_200 = F_5 ( V_7 ) ;
V_48 -> V_233 = F_7 ( 0x80000000 ) ;
for ( V_135 = 0 ; V_135 < F_33 ( V_67 -> V_209 ) ; V_135 ++ )
V_48 -> V_231 [ V_135 ] = ( V_7 != V_210 ) ? 0 :
F_51 (
F_48 ( V_67 , V_191 , V_67 -> V_209 [ V_135 ] ) ) ;
return F_1 ( (struct V_1 * ) V_184 ) ;
}
static int F_52 ( struct V_183 * V_184 ,
struct V_11 * V_12 , T_1 V_17 )
{
struct V_234 * V_48 = (struct V_234 * )
V_184 -> V_15 ;
struct V_66 * V_67 = F_4 ( V_12 ) ;
struct V_235 V_236 ;
T_1 V_193 = V_48 -> V_193 ;
F_53 ( V_67 -> V_21 , & V_236 ) ;
V_236 . V_237 -= V_67 -> V_238 ;
V_236 . V_239 -=
V_67 -> V_240 ;
V_236 . V_241 -= V_67 -> V_242 ;
V_236 . V_243 += V_67 -> V_244 ;
V_236 . V_243 -= V_67 -> V_245 ;
V_236 . V_246 -= V_67 -> V_247 ;
V_236 . V_248 -= V_67 -> V_249 ;
V_236 . V_250 -= V_67 -> V_251 ;
V_236 . V_252 -= V_67 -> V_253 ;
V_236 . V_254 -= V_67 -> V_255 ;
V_236 . V_256 -= V_67 -> V_257 ;
V_236 . V_258 -=
V_67 -> V_259 ;
V_236 . V_260 -=
V_67 -> V_261 ;
V_236 . V_262 -= V_67 -> V_263 ;
V_236 . V_262 += V_67 -> V_264 ;
memset ( V_184 -> V_15 , 0 , sizeof( V_184 -> V_15 ) ) ;
V_48 -> V_193 = V_193 ;
if ( V_184 -> V_186 . V_13 != 0 ||
( V_193 != V_17 && V_193 != 0xFF ) )
V_184 -> V_186 . V_7 |= V_14 ;
if ( V_236 . V_237 > 0xFFFFUL )
V_48 -> V_237 = F_5 ( 0xFFFF ) ;
else
V_48 -> V_237 =
F_5 ( ( T_4 ) V_236 . V_237 ) ;
if ( V_236 . V_239 > 0xFFUL )
V_48 -> V_239 = 0xFF ;
else
V_48 -> V_239 =
( T_1 ) V_236 . V_239 ;
if ( V_236 . V_241 > 0xFFUL )
V_48 -> V_241 = 0xFF ;
else
V_48 -> V_241 = ( T_1 ) V_236 . V_241 ;
if ( V_236 . V_243 > 0xFFFFUL )
V_48 -> V_243 = F_5 ( 0xFFFF ) ;
else
V_48 -> V_243 =
F_5 ( ( T_4 ) V_236 . V_243 ) ;
if ( V_236 . V_246 > 0xFFFFUL )
V_48 -> V_246 = F_5 ( 0xFFFF ) ;
else
V_48 -> V_246 =
F_5 ( ( T_4 ) V_236 . V_246 ) ;
if ( V_236 . V_248 > 0xFFFFUL )
V_48 -> V_248 = F_5 ( 0xFFFF ) ;
else
V_48 -> V_248 =
F_5 ( ( T_4 ) V_236 . V_248 ) ;
if ( V_236 . V_258 > 0xFUL )
V_236 . V_258 = 0xFUL ;
if ( V_236 . V_260 > 0xFUL )
V_236 . V_260 = 0xFUL ;
V_48 -> V_265 = ( V_236 . V_258 << 4 ) |
V_236 . V_260 ;
if ( V_236 . V_262 > 0xFFFFUL )
V_48 -> V_262 = F_5 ( 0xFFFF ) ;
else
V_48 -> V_262 = F_5 ( ( T_4 ) V_236 . V_262 ) ;
if ( V_236 . V_250 > 0xFFFFFFFFUL )
V_48 -> V_250 = F_7 ( 0xFFFFFFFF ) ;
else
V_48 -> V_250 = F_7 ( ( T_2 ) V_236 . V_250 ) ;
if ( V_236 . V_252 > 0xFFFFFFFFUL )
V_48 -> V_252 = F_7 ( 0xFFFFFFFF ) ;
else
V_48 -> V_252 = F_7 ( ( T_2 ) V_236 . V_252 ) ;
if ( V_236 . V_254 > 0xFFFFFFFFUL )
V_48 -> V_254 = F_7 ( 0xFFFFFFFF ) ;
else
V_48 -> V_254 =
F_7 ( ( T_2 ) V_236 . V_254 ) ;
if ( V_236 . V_256 > 0xFFFFFFFFUL )
V_48 -> V_256 = F_7 ( 0xFFFFFFFF ) ;
else
V_48 -> V_256 =
F_7 ( ( T_2 ) V_236 . V_256 ) ;
return F_1 ( (struct V_1 * ) V_184 ) ;
}
static int F_54 ( struct V_183 * V_184 ,
struct V_11 * V_12 , T_1 V_17 )
{
struct V_266 * V_48 =
(struct V_266 * ) V_184 -> V_15 ;
struct V_66 * V_67 = F_4 ( V_12 ) ;
V_60 V_267 , V_268 , V_269 , V_270 , V_271 ;
T_1 V_193 = V_48 -> V_193 ;
F_55 ( V_67 -> V_21 , & V_267 , & V_268 , & V_269 ,
& V_270 , & V_271 ) ;
V_267 -= V_67 -> V_251 ;
V_268 -= V_67 -> V_253 ;
V_269 -= V_67 -> V_255 ;
V_270 -= V_67 -> V_257 ;
memset ( V_184 -> V_15 , 0 , sizeof( V_184 -> V_15 ) ) ;
V_48 -> V_193 = V_193 ;
if ( V_184 -> V_186 . V_13 != 0 ||
( V_193 != V_17 && V_193 != 0xFF ) )
V_184 -> V_186 . V_7 |= V_14 ;
V_48 -> V_250 = F_51 ( V_267 ) ;
V_48 -> V_252 = F_51 ( V_268 ) ;
V_48 -> V_254 = F_51 ( V_269 ) ;
V_48 -> V_256 = F_51 ( V_270 ) ;
V_48 -> V_272 = F_51 ( V_67 -> V_273 ) ;
V_48 -> V_274 = F_51 ( V_67 -> V_275 ) ;
V_48 -> V_276 = F_51 ( V_67 -> V_277 ) ;
V_48 -> V_278 = F_51 ( V_67 -> V_279 ) ;
return F_1 ( (struct V_1 * ) V_184 ) ;
}
static int F_56 ( struct V_183 * V_184 ,
struct V_11 * V_12 , T_1 V_17 )
{
struct V_234 * V_48 = (struct V_234 * )
V_184 -> V_15 ;
struct V_66 * V_67 = F_4 ( V_12 ) ;
struct V_235 V_236 ;
F_53 ( V_67 -> V_21 , & V_236 ) ;
if ( V_48 -> V_208 & V_280 )
V_67 -> V_238 = V_236 . V_237 ;
if ( V_48 -> V_208 & V_281 )
V_67 -> V_240 =
V_236 . V_239 ;
if ( V_48 -> V_208 & V_282 )
V_67 -> V_242 = V_236 . V_241 ;
if ( V_48 -> V_208 & V_283 )
V_67 -> V_245 =
V_236 . V_243 + V_67 -> V_244 ;
if ( V_48 -> V_208 & V_284 )
V_67 -> V_247 =
V_236 . V_246 ;
if ( V_48 -> V_208 & V_285 )
V_67 -> V_249 = V_236 . V_248 ;
if ( V_48 -> V_208 & V_286 )
V_67 -> V_259 =
V_236 . V_258 ;
if ( V_48 -> V_208 & V_287 )
V_67 -> V_261 =
V_236 . V_260 ;
if ( V_48 -> V_208 & V_288 ) {
V_67 -> V_264 = 0 ;
V_67 -> V_263 = V_236 . V_262 ;
}
if ( V_48 -> V_208 & V_289 )
V_67 -> V_251 = V_236 . V_250 ;
if ( V_48 -> V_208 & V_290 )
V_67 -> V_253 = V_236 . V_252 ;
if ( V_48 -> V_208 & V_291 )
V_67 -> V_255 = V_236 . V_254 ;
if ( V_48 -> V_208 & V_292 )
V_67 -> V_257 = V_236 . V_256 ;
return F_52 ( V_184 , V_12 , V_17 ) ;
}
static int F_57 ( struct V_183 * V_184 ,
struct V_11 * V_12 , T_1 V_17 )
{
struct V_234 * V_48 = (struct V_234 * )
V_184 -> V_15 ;
struct V_66 * V_67 = F_4 ( V_12 ) ;
V_60 V_267 , V_268 , V_269 , V_270 , V_271 ;
F_55 ( V_67 -> V_21 , & V_267 , & V_268 , & V_269 ,
& V_270 , & V_271 ) ;
if ( V_48 -> V_208 & V_293 )
V_67 -> V_251 = V_267 ;
if ( V_48 -> V_208 & V_294 )
V_67 -> V_253 = V_268 ;
if ( V_48 -> V_208 & V_295 )
V_67 -> V_255 = V_269 ;
if ( V_48 -> V_208 & V_296 )
V_67 -> V_257 = V_270 ;
if ( V_48 -> V_208 & V_297 )
V_67 -> V_273 = 0 ;
if ( V_48 -> V_208 & V_298 )
V_67 -> V_275 = 0 ;
if ( V_48 -> V_208 & V_299 )
V_67 -> V_277 = 0 ;
if ( V_48 -> V_208 & V_300 )
V_67 -> V_279 = 0 ;
return F_54 ( V_184 , V_12 , V_17 ) ;
}
static int F_58 ( struct V_11 * V_12 , int V_301 ,
T_1 V_149 , struct V_302 * V_303 ,
struct V_302 * V_304 )
{
struct V_1 * V_2 = (struct V_1 * ) V_304 ;
struct V_66 * V_67 = F_4 ( V_12 ) ;
int V_73 ;
* V_304 = * V_303 ;
if ( V_2 -> V_27 != 1 ) {
V_2 -> V_7 |= V_305 ;
V_73 = F_1 ( V_2 ) ;
goto V_74;
}
if ( V_67 -> V_306 &&
F_59 ( V_307 , V_67 -> V_306 ) ) {
V_67 -> V_306 = 0 ;
V_67 -> V_77 = 0 ;
}
if ( ( V_301 & V_308 ) == 0 && V_67 -> V_76 != 0 &&
V_67 -> V_76 != V_2 -> V_76 &&
( V_2 -> V_3 == V_75 ||
( V_2 -> V_3 == V_309 &&
V_67 -> V_77 >= 2 ) ) ) {
if ( V_67 -> V_115 != 0xFFFF )
++ V_67 -> V_115 ;
if ( V_67 -> V_306 ||
V_67 -> V_84 == 0 ) {
V_73 = V_9 |
V_160 ;
goto V_74;
}
V_67 -> V_306 = V_307 +
V_67 -> V_84 * V_310 ;
V_73 = V_9 | V_160 ;
goto V_74;
} else if ( V_67 -> V_306 )
V_67 -> V_306 = 0 ;
switch ( V_2 -> V_3 ) {
case V_309 :
switch ( V_2 -> V_311 ) {
case V_312 :
V_73 = F_2 ( V_2 , V_12 ) ;
goto V_74;
case V_313 :
V_73 = F_3 ( V_2 , V_12 , V_149 ) ;
goto V_74;
case V_314 :
V_73 = F_8 ( V_2 , V_12 ) ;
goto V_74;
case V_315 :
V_73 = F_18 ( V_2 , V_12 , V_149 ) ;
goto V_74;
case V_316 :
V_73 = F_22 ( V_2 , V_12 ) ;
goto V_74;
case V_317 :
if ( V_67 -> V_83 & V_318 ) {
V_73 = V_9 |
V_160 ;
goto V_74;
}
if ( V_67 -> V_83 & V_319 ) {
V_73 = V_9 ;
goto V_74;
}
default:
V_2 -> V_7 |= V_320 ;
V_73 = F_1 ( V_2 ) ;
goto V_74;
}
case V_75 :
switch ( V_2 -> V_311 ) {
case V_314 :
V_73 = F_23 ( V_2 , V_12 ) ;
goto V_74;
case V_315 :
V_73 = F_25 ( V_2 , V_12 , V_149 ) ;
goto V_74;
case V_316 :
V_73 = F_40 ( V_2 , V_12 ) ;
goto V_74;
case V_317 :
if ( V_67 -> V_83 & V_318 ) {
V_73 = V_9 |
V_160 ;
goto V_74;
}
if ( V_67 -> V_83 & V_319 ) {
V_73 = V_9 ;
goto V_74;
}
default:
V_2 -> V_7 |= V_320 ;
V_73 = F_1 ( V_2 ) ;
goto V_74;
}
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_4 :
V_73 = V_9 ;
goto V_74;
default:
V_2 -> V_7 |= V_325 ;
V_73 = F_1 ( V_2 ) ;
}
V_74:
return V_73 ;
}
static int F_60 ( struct V_11 * V_12 , T_1 V_149 ,
struct V_302 * V_303 ,
struct V_302 * V_304 )
{
struct V_183 * V_184 = (struct V_183 * ) V_304 ;
int V_73 ;
* V_304 = * V_303 ;
if ( V_184 -> V_186 . V_27 != 1 ) {
V_184 -> V_186 . V_7 |= V_305 ;
V_73 = F_1 ( (struct V_1 * ) V_184 ) ;
goto V_74;
}
switch ( V_184 -> V_186 . V_3 ) {
case V_309 :
switch ( V_184 -> V_186 . V_311 ) {
case V_326 :
V_73 = F_41 ( V_184 ) ;
goto V_74;
case V_327 :
V_73 = F_42 ( V_184 , V_12 ,
V_149 ) ;
goto V_74;
case V_328 :
V_73 = F_49 ( V_184 , V_12 ) ;
goto V_74;
case V_329 :
V_73 = F_50 ( V_184 ,
V_12 ) ;
goto V_74;
case V_330 :
V_73 = F_52 ( V_184 , V_12 ,
V_149 ) ;
goto V_74;
case V_331 :
V_73 = F_54 ( V_184 , V_12 ,
V_149 ) ;
goto V_74;
default:
V_184 -> V_186 . V_7 |= V_320 ;
V_73 = F_1 ( (struct V_1 * ) V_184 ) ;
goto V_74;
}
case V_75 :
switch ( V_184 -> V_186 . V_311 ) {
case V_327 :
V_73 = F_46 ( V_184 , V_12 ,
V_149 ) ;
goto V_74;
case V_330 :
V_73 = F_56 ( V_184 , V_12 ,
V_149 ) ;
goto V_74;
case V_331 :
V_73 = F_57 ( V_184 , V_12 ,
V_149 ) ;
goto V_74;
default:
V_184 -> V_186 . V_7 |= V_320 ;
V_73 = F_1 ( (struct V_1 * ) V_184 ) ;
goto V_74;
}
case V_4 :
V_73 = V_9 ;
goto V_74;
default:
V_184 -> V_186 . V_7 |= V_325 ;
V_73 = F_1 ( (struct V_1 * ) V_184 ) ;
}
V_74:
return V_73 ;
}
int F_61 ( struct V_11 * V_12 , int V_301 , T_1 V_149 ,
struct V_332 * V_333 , struct V_334 * V_335 ,
struct V_302 * V_303 , struct V_302 * V_304 )
{
int V_73 ;
switch ( V_303 -> V_186 . V_5 ) {
case V_6 :
case V_336 :
V_73 = F_58 ( V_12 , V_301 , V_149 ,
V_303 , V_304 ) ;
goto V_74;
case V_337 :
V_73 = F_60 ( V_12 , V_149 , V_303 , V_304 ) ;
goto V_74;
default:
V_73 = V_9 ;
}
V_74:
return V_73 ;
}
