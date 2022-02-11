int
F_1 ( struct V_1 * V_2 ,
int V_3 , struct V_4 * V_5 , bool V_6 )
{
int V_7 , V_8 , V_9 , V_10 ;
int V_11 , V_12 , V_13 , V_14 ;
int V_15 ;
if ( ! V_2 -> V_16 ) {
T_1 V_17 = F_2 ( V_2 -> V_18 ,
NULL , V_3 , V_5 ) ;
V_15 = F_3 ( V_17 ) ;
if ( V_6 )
V_15 -= 96 ;
return V_15 ;
}
V_11 = V_5 -> V_11 ;
V_8 = V_19 ;
V_9 = V_20 ;
V_10 = V_21 ;
switch ( V_2 -> V_16 ) {
case V_22 :
V_7 = V_23 ;
V_8 = V_24 ;
break;
case V_25 :
V_7 = V_26 ;
V_8 *= 2 ;
V_10 *= 2 ;
break;
case V_27 :
V_7 = V_28 ;
V_8 *= 4 ;
V_10 *= 4 ;
break;
default:
V_7 = V_29 ;
break;
}
V_12 = V_9 + ( V_3 << 3 ) ;
V_14 = V_11 * V_10 ;
V_13 = F_4 ( V_12 * 10 , V_14 ) ;
V_15 = V_7 + V_8 + ( V_10 * V_13 ) ;
return V_15 ;
}
unsigned int
F_5 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
unsigned int V_33 ;
switch ( V_2 -> V_16 ) {
case V_22 :
V_33 = V_34 ;
break;
case V_25 :
V_33 = V_35 ;
break;
case V_27 :
V_33 = V_36 ;
break;
case V_37 :
default:
V_33 = V_38 ;
if ( ( V_31 -> V_39 == V_40 ) && ! V_2 -> V_41 )
V_33 = V_42 ;
break;
}
return V_33 ;
}
unsigned int
F_6 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
unsigned int V_7 ;
switch ( V_2 -> V_16 ) {
case V_22 :
V_7 = V_23 ;
break;
case V_25 :
V_7 = V_26 ;
break;
case V_27 :
V_7 = V_28 ;
break;
case V_37 :
V_7 = V_29 ;
default:
if ( V_31 -> V_43 == V_44 )
V_7 = V_45 ;
break;
}
return V_7 ;
}
void
F_7 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = & V_2 -> V_47 ;
V_47 -> V_48 += F_8 ( V_2 , V_49 ) ;
V_47 -> V_50 += F_8 ( V_2 , V_51 ) ;
V_47 -> V_52 += F_8 ( V_2 , V_53 ) ;
V_47 -> V_54 += F_8 ( V_2 , V_55 ) ;
V_47 -> V_56 += F_8 ( V_2 , V_57 ) ;
}
static inline void
F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
unsigned int V_58 ;
T_2 V_43 = V_59 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_60 [ V_43 ] . V_61 ; V_58 ++ ) {
T_3 V_62 ;
T_4 V_63 ;
if ( V_2 -> V_64 )
V_5 = & V_2 -> V_60 [ V_43 ] . V_65 [ V_66 [ V_58 ] ] ;
else if ( V_58 < 4 )
V_5 = & V_2 -> V_60 [ V_43 ] . V_65 [ 0 ] ;
else
V_5 = & V_2 -> V_60 [ V_43 ] . V_65 [ 4 ] ;
V_62 = F_10 ( V_5 -> V_39 ) ;
V_63 = F_1 ( V_2 , 10 , V_5 , false ) ;
F_11 ( V_2 , V_63 , V_62 ) ;
if ( ! ( V_5 -> V_67 & V_68 ) )
continue;
V_63 = F_1 ( V_2 , 10 , V_5 , true ) ;
F_11 ( V_2 , V_63 ,
V_62 + ( V_69 << 2 ) ) ;
}
}
static int
F_12 ( struct V_1 * V_2 , unsigned int V_70 )
{
if ( F_13 ( V_2 , F_14 ( 0xffffffff , V_71 ) )
<= V_70 )
return - V_72 ;
F_15 ( V_2 , V_73 , V_71 ,
F_16 ( V_2 , V_70 ) ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , unsigned int V_70 )
{
if ( F_13 ( V_2 , F_14 ( 0xffffffff , V_74 ) )
<= V_70 )
return - V_72 ;
F_15 ( V_2 , V_73 , V_74 ,
F_16 ( V_2 , V_70 ) ) ;
return 0 ;
}
int
F_18 ( struct V_1 * V_2 , const T_2 * V_75 )
{
struct V_76 * V_77 = F_19 ( V_2 ) ;
T_3 V_78 , V_79 ;
T_3 V_80 ;
memcpy ( V_77 -> V_81 , V_75 , V_82 ) ;
V_80 = F_8 ( V_2 , V_83 ) & 0xffff0000 ;
V_78 = F_20 ( V_75 ) ;
V_79 = F_21 ( V_75 + 4 ) ;
F_11 ( V_2 , V_78 , V_84 ) ;
F_11 ( V_2 , V_80 | V_79 , V_83 ) ;
return 0 ;
}
void
F_22 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = F_19 ( V_2 ) ;
T_4 V_85 = 0 ;
if ( V_2 -> V_86 == V_87 )
F_23 ( V_77 ) ;
F_11 ( V_2 ,
F_20 ( V_77 -> V_88 ) ,
V_89 ) ;
F_11 ( V_2 ,
F_21 ( V_77 -> V_88 + 4 ) |
( ( V_77 -> V_90 & 0x3fff ) << V_91 ) ,
V_92 ) ;
if ( V_77 -> V_90 == 0 ) {
F_24 ( V_2 ) ;
return;
}
F_15 ( V_2 , V_93 , V_94 ,
V_85 ? V_85 + 4 : 0 ) ;
F_25 ( V_2 , NULL , 0 ) ;
}
void
F_26 ( struct V_1 * V_2 , const T_2 * V_95 )
{
struct V_76 * V_77 = F_19 ( V_2 ) ;
memcpy ( V_77 -> V_96 , V_95 , V_82 ) ;
if ( V_2 -> V_86 == V_87 )
F_23 ( V_77 ) ;
}
void
F_27 ( struct V_1 * V_2 , T_3 V_97 , T_3 V_98 )
{
F_11 ( V_2 , V_97 , V_99 ) ;
F_11 ( V_2 , V_98 , V_100 ) ;
}
T_3
F_28 ( struct V_1 * V_2 )
{
T_3 V_101 , V_102 = 0 ;
V_102 = F_8 ( V_2 , V_103 ) ;
if ( V_2 -> V_86 == V_87 ) {
V_101 = F_8 ( V_2 , V_104 ) ;
if ( V_101 & V_105 )
V_102 |= V_106 ;
if ( V_101 & ( V_107 | V_108 ) )
V_102 |= V_109 ;
}
return V_102 ;
}
void
F_29 ( struct V_1 * V_2 , T_3 V_102 )
{
T_3 V_101 = 0 ;
if ( V_2 -> V_86 == V_87 ) {
if ( V_102 & V_106 )
V_101 |= V_105 ;
if ( V_102 & V_109 )
V_101 |= V_107 | V_108 ;
}
if ( V_2 -> V_86 == V_110 &&
( V_102 & V_106 ) ) {
V_102 &= ~ V_106 ;
V_102 |= V_111 ;
}
if ( V_101 )
F_30 ( V_2 , V_112 , V_113 ) ;
else
F_31 ( V_2 , V_112 , V_113 ) ;
F_11 ( V_2 , V_102 & 0xff , V_103 ) ;
if ( V_2 -> V_86 == V_87 )
F_11 ( V_2 , V_101 , V_104 ) ;
}
T_5
F_32 ( struct V_1 * V_2 )
{
T_3 V_114 , V_115 , V_116 ;
int V_58 ;
unsigned long V_67 ;
F_33 ( V_67 ) ;
V_115 = F_8 ( V_2 , V_117 ) ;
for ( V_58 = 0 ; V_58 < V_118 ; V_58 ++ ) {
V_114 = F_8 ( V_2 , V_119 ) ;
V_116 = F_8 ( V_2 , V_117 ) ;
if ( V_116 == V_115 )
break;
V_115 = V_116 ;
}
F_34 ( V_67 ) ;
F_35 ( V_58 == V_118 ) ;
return ( ( T_5 ) V_115 << 32 ) | V_114 ;
}
void
F_36 ( struct V_1 * V_2 , T_5 V_120 )
{
F_11 ( V_2 , V_120 & 0xffffffff , V_119 ) ;
F_11 ( V_2 , ( V_120 >> 32 ) & 0xffffffff , V_117 ) ;
}
void
F_37 ( struct V_1 * V_2 )
{
T_3 V_121 ;
V_121 = F_8 ( V_2 , V_93 ) | V_122 ;
F_11 ( V_2 , V_121 , V_93 ) ;
F_11 ( V_2 , V_121 , V_93 ) ;
}
void
F_38 ( struct V_1 * V_2 , T_3 V_123 , T_3 V_124 )
{
T_3 V_125 , V_126 , V_127 ;
switch ( V_2 -> V_128 ) {
case V_129 :
case V_130 :
if ( V_2 -> V_86 == V_110 ) {
V_125 = 0xffffffff ;
V_126 = 0xffffffff ;
} else {
V_125 = 0x0000ffff ;
V_126 = 0x0007ffff ;
}
F_31 ( V_2 , V_83 , V_131 ) ;
break;
case V_132 :
F_30 ( V_2 , V_133 , V_134 ) ;
default:
V_125 = ( V_123 - V_135 ) << 3 ;
V_126 = ( V_123 - V_136 ) << 3 ;
break;
}
V_127 = V_123 + 1 ;
if ( V_2 -> V_128 == V_137 ||
V_2 -> V_128 == V_138 )
F_11 ( V_2 , 0 , V_139 ) ;
F_11 ( V_2 , V_123 , V_139 ) ;
F_11 ( V_2 , V_125 , V_140 ) ;
F_11 ( V_2 , V_126 , V_141 ) ;
F_11 ( V_2 , V_127 , V_142 ) ;
if ( V_124 & V_122 )
F_37 ( V_2 ) ;
F_11 ( V_2 , V_124 & ( V_143 |
V_144 ) ,
V_93 ) ;
if ( V_2 -> V_86 == V_110 )
F_11 ( V_2 , V_145 , V_146 ) ;
else
F_11 ( V_2 , V_145 , V_147 ) ;
F_31 ( V_2 , V_83 , V_148 ) ;
}
static inline bool
F_39 ( int V_149 , int V_150 , int V_151 , int V_152 )
{
if ( ( V_150 - V_149 == V_151 ) ||
( V_149 - V_150 == V_152 - V_151 ) ||
( ( V_149 | 0x10000 ) - V_150 == V_152 - V_151 ) ||
( ( V_150 | 0x10000 ) - V_149 == V_151 ) )
return true ;
return false ;
}
bool
F_40 ( struct V_1 * V_2 , int V_152 )
{
unsigned int V_153 , V_154 , V_155 ;
V_153 = F_8 ( V_2 , V_139 ) ;
V_154 = F_8 ( V_2 , V_142 ) ;
V_155 = F_8 ( V_2 , V_140 ) >> 3 ;
if ( F_39 ( V_153 , V_154 , 1 , V_152 ) &&
F_39 ( V_155 , V_153 , V_135 ,
V_152 ) )
return true ;
return false ;
}
void
F_41 ( struct V_1 * V_2 , T_2 V_156 )
{
int V_33 = F_5 ( V_2 ) + 3 * V_156 ;
int V_157 = F_6 ( V_2 ) + V_33 ;
int V_158 = V_157 ;
F_42 ( V_2 , V_33 ) ;
F_12 ( V_2 , V_157 ) ;
F_17 ( V_2 , V_158 ) ;
V_2 -> V_159 = V_156 ;
}
void
F_43 ( struct V_1 * V_2 )
{
F_31 ( V_2 , V_160 , V_161 ) ;
}
void
F_44 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_160 , V_161 ) ;
}
int
F_45 ( struct V_1 * V_2 , enum V_162 V_163 )
{
struct V_76 * V_77 = F_19 ( V_2 ) ;
T_3 V_80 , V_164 , V_78 , V_79 ;
F_46 ( V_2 , V_165 , L_1 , V_163 ) ;
V_80 = F_8 ( V_2 , V_83 ) & 0xffff0000 ;
V_80 &= ~ ( V_166 | V_167
| V_168
| ( V_2 -> V_86 == V_110 ?
( V_148 | V_169 ) : 0 ) ) ;
V_164 = 0 ;
switch ( V_163 ) {
case V_132 :
V_80 |= V_166 | V_168 ;
V_164 |= V_170 ;
if ( V_2 -> V_86 == V_110 )
V_80 |= V_169 ;
else
F_30 ( V_2 , V_171 , V_172 ) ;
break;
case V_137 :
case V_138 :
V_80 |= V_167 | V_168 ;
V_164 |= V_173 ;
if ( V_2 -> V_86 == V_110 )
V_80 |= V_169 ;
else
F_31 ( V_2 , V_171 , V_172 ) ;
break;
case V_130 :
V_80 |= V_168
| ( V_2 -> V_86 == V_110 ?
V_148 : 0 ) ;
case V_129 :
V_80 |= V_168
| ( V_2 -> V_86 == V_110 ?
V_169 : 0 ) ;
break;
default:
return - V_72 ;
}
V_78 = F_20 ( V_77 -> V_81 ) ;
V_79 = F_21 ( V_77 -> V_81 + 4 ) ;
F_11 ( V_2 , V_78 , V_84 ) ;
F_11 ( V_2 , V_80 | V_79 , V_83 ) ;
if ( V_2 -> V_86 == V_110 )
F_11 ( V_2 , V_164 , V_174 ) ;
return 0 ;
}
void
F_47 ( struct V_1 * V_2 , enum V_162 V_163 )
{
F_22 ( V_2 ) ;
F_45 ( V_2 , V_163 ) ;
if ( V_2 -> V_86 == V_87 &&
V_2 -> V_175 )
F_9 ( V_2 ) ;
F_11 ( V_2 , ( V_176 |
V_177 <<
V_178 ) ,
V_179 ) ;
if ( V_2 -> V_180 >= V_181 ) {
F_11 ( V_2 , 0x000100aa , V_182 ) ;
F_11 ( V_2 , 0x00003210 , V_183 ) ;
}
if ( V_2 -> V_86 == V_87 ) {
F_11 ( V_2 ,
F_48 ( 2 , V_184 ) |
F_48 ( 5 , V_185 ) |
F_48 ( 0 , V_186 ) ,
V_187 ) ;
}
if ( V_2 -> V_159 > 0 )
F_41 ( V_2 , V_2 -> V_159 ) ;
if ( V_2 -> V_86 == V_87 ) {
T_3 V_121 = V_188 | V_189 ;
if ( V_2 -> V_64 )
F_31 ( V_2 , V_83 , V_121 ) ;
else
F_30 ( V_2 , V_83 , V_121 ) ;
}
return;
}
