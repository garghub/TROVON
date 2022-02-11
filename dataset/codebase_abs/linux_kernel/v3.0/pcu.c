int F_1 ( struct V_1 * V_2 ,
int V_3 , struct V_4 * V_5 , bool V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 , V_11 , V_12 , V_13 ;
int V_14 , V_15 , V_16 , V_17 ;
int V_18 ;
if ( ! V_2 -> V_19 ) {
T_1 V_20 = F_2 ( V_8 -> V_21 ,
NULL , V_3 , V_5 ) ;
V_18 = F_3 ( V_20 ) ;
if ( V_6 )
V_18 -= 96 ;
return V_18 ;
}
V_14 = V_5 -> V_14 ;
V_11 = V_22 ;
V_12 = V_23 ;
V_13 = V_24 ;
switch ( V_2 -> V_19 ) {
case V_25 :
V_10 = V_26 ;
V_11 = V_27 ;
break;
case V_28 :
V_10 = V_29 ;
V_11 *= 2 ;
V_13 *= 2 ;
break;
case V_30 :
V_10 = V_31 ;
V_11 *= 4 ;
V_13 *= 4 ;
break;
default:
V_10 = V_32 ;
break;
}
V_15 = V_12 + ( V_3 << 3 ) ;
V_17 = V_14 * V_13 ;
V_16 = F_4 ( V_15 * 10 , V_17 ) ;
V_18 = V_10 + V_11 + ( V_13 * V_16 ) ;
return V_18 ;
}
unsigned int F_5 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
unsigned int V_36 ;
switch ( V_2 -> V_19 ) {
case V_25 :
V_36 = V_37 ;
break;
case V_28 :
V_36 = V_38 ;
break;
case V_30 :
V_36 = V_39 ;
break;
case V_40 :
default:
V_36 = V_41 ;
if ( ( V_34 -> V_42 & V_43 ) && ! V_2 -> V_44 )
V_36 = V_45 ;
break;
}
return V_36 ;
}
unsigned int F_6 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
unsigned int V_10 ;
switch ( V_2 -> V_19 ) {
case V_25 :
V_10 = V_26 ;
break;
case V_28 :
V_10 = V_29 ;
break;
case V_30 :
V_10 = V_31 ;
break;
case V_40 :
V_10 = V_32 ;
default:
if ( V_34 -> V_42 & V_46 )
V_10 = V_47 ;
break;
}
return V_10 ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = & V_2 -> V_9 -> V_49 ;
V_49 -> V_50 += F_8 ( V_2 , V_51 ) ;
V_49 -> V_52 += F_8 ( V_2 , V_53 ) ;
V_49 -> V_54 += F_8 ( V_2 , V_55 ) ;
V_49 -> V_56 += F_8 ( V_2 , V_57 ) ;
V_49 -> V_58 += F_8 ( V_2 , V_59 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_4 * V_5 ;
unsigned int V_60 ;
T_2 V_61 = V_62 ;
for ( V_60 = 0 ; V_60 < V_8 -> V_63 [ V_61 ] . V_64 ; V_60 ++ ) {
T_3 V_65 ;
T_4 V_66 ;
if ( V_2 -> V_67 )
V_5 = & V_8 -> V_63 [ V_61 ] . V_68 [ V_69 [ V_60 ] ] ;
else if ( V_60 < 4 )
V_5 = & V_8 -> V_63 [ V_61 ] . V_68 [ 0 ] ;
else
V_5 = & V_8 -> V_63 [ V_61 ] . V_68 [ 4 ] ;
V_65 = F_10 ( V_5 -> V_42 ) ;
V_66 = F_1 ( V_2 , 10 , V_5 , false ) ;
F_11 ( V_2 , V_66 , V_65 ) ;
if ( ! ( V_5 -> V_70 & V_71 ) )
continue;
V_66 = F_1 ( V_2 , 10 , V_5 , true ) ;
F_11 ( V_2 , V_66 ,
V_65 + ( V_72 << 2 ) ) ;
}
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_73 )
{
if ( F_13 ( V_2 , F_14 ( 0xffffffff , V_74 ) )
<= V_73 )
return - V_75 ;
F_15 ( V_2 , V_76 , V_74 ,
F_16 ( V_2 , V_73 ) ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_73 )
{
if ( F_13 ( V_2 , F_14 ( 0xffffffff , V_77 ) )
<= V_73 )
return - V_75 ;
F_15 ( V_2 , V_76 , V_77 ,
F_16 ( V_2 , V_73 ) ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , const T_2 * V_78 )
{
struct V_79 * V_80 = F_19 ( V_2 ) ;
T_3 V_81 , V_82 ;
T_3 V_83 ;
memcpy ( V_80 -> V_84 , V_78 , V_85 ) ;
V_83 = F_8 ( V_2 , V_86 ) & 0xffff0000 ;
V_81 = F_20 ( V_78 ) ;
V_82 = F_21 ( V_78 + 4 ) ;
F_11 ( V_2 , V_81 , V_87 ) ;
F_11 ( V_2 , V_83 | V_82 , V_86 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = F_19 ( V_2 ) ;
T_4 V_88 = 0 ;
if ( V_2 -> V_89 == V_90 )
F_23 ( V_80 ) ;
F_11 ( V_2 ,
F_20 ( V_80 -> V_91 ) ,
V_92 ) ;
F_11 ( V_2 ,
F_21 ( V_80 -> V_91 + 4 ) |
( ( V_80 -> V_93 & 0x3fff ) << V_94 ) ,
V_95 ) ;
if ( V_80 -> V_93 == 0 ) {
F_24 ( V_2 ) ;
return;
}
F_15 ( V_2 , V_96 , V_97 ,
V_88 ? V_88 + 4 : 0 ) ;
F_25 ( V_2 , NULL , 0 ) ;
}
void F_26 ( struct V_1 * V_2 , const T_2 * V_98 )
{
struct V_79 * V_80 = F_19 ( V_2 ) ;
memcpy ( V_80 -> V_99 , V_98 , V_85 ) ;
if ( V_2 -> V_89 == V_90 )
F_23 ( V_80 ) ;
}
void F_27 ( struct V_1 * V_2 , T_3 V_100 , T_3 V_101 )
{
F_11 ( V_2 , V_100 , V_102 ) ;
F_11 ( V_2 , V_101 , V_103 ) ;
}
T_3 F_28 ( struct V_1 * V_2 )
{
T_3 V_104 , V_105 = 0 ;
V_105 = F_8 ( V_2 , V_106 ) ;
if ( V_2 -> V_89 == V_90 ) {
V_104 = F_8 ( V_2 , V_107 ) ;
if ( V_104 & V_108 )
V_105 |= V_109 ;
if ( V_104 & ( V_110 | V_111 ) )
V_105 |= V_112 ;
}
return V_105 ;
}
void F_29 ( struct V_1 * V_2 , T_3 V_105 )
{
T_3 V_104 = 0 ;
if ( V_2 -> V_89 == V_90 ) {
if ( V_105 & V_109 )
V_104 |= V_108 ;
if ( V_105 & V_112 )
V_104 |= V_110 | V_111 ;
}
if ( V_2 -> V_89 == V_113 &&
( V_105 & V_109 ) ) {
V_105 &= ~ V_109 ;
V_105 |= V_114 ;
}
if ( V_104 )
F_30 ( V_2 , V_115 , V_116 ) ;
else
F_31 ( V_2 , V_115 , V_116 ) ;
F_11 ( V_2 , V_105 & 0xff , V_106 ) ;
if ( V_2 -> V_89 == V_90 )
F_11 ( V_2 , V_104 , V_107 ) ;
}
T_5 F_32 ( struct V_1 * V_2 )
{
T_3 V_117 , V_118 , V_119 ;
int V_60 ;
unsigned long V_70 ;
F_33 ( V_70 ) ;
V_118 = F_8 ( V_2 , V_120 ) ;
for ( V_60 = 0 ; V_60 < V_121 ; V_60 ++ ) {
V_117 = F_8 ( V_2 , V_122 ) ;
V_119 = F_8 ( V_2 , V_120 ) ;
if ( V_119 == V_118 )
break;
V_118 = V_119 ;
}
F_34 ( V_70 ) ;
F_35 ( V_60 == V_121 ) ;
return ( ( ( T_5 ) V_118 << 32 ) | V_117 ) ;
}
void F_36 ( struct V_1 * V_2 , T_5 V_123 )
{
F_11 ( V_2 , V_123 & 0xffffffff , V_122 ) ;
F_11 ( V_2 , ( V_123 >> 32 ) & 0xffffffff , V_120 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
T_3 V_124 ;
V_124 = F_8 ( V_2 , V_96 ) | V_125 ;
F_11 ( V_2 , V_124 , V_96 ) ;
F_11 ( V_2 , V_124 , V_96 ) ;
}
void F_38 ( struct V_1 * V_2 , T_3 V_126 , T_3 V_127 )
{
T_3 V_128 , V_129 , V_130 ;
switch ( V_2 -> V_9 -> V_131 ) {
case V_132 :
case V_133 :
if ( V_2 -> V_89 == V_113 ) {
V_128 = 0xffffffff ;
V_129 = 0xffffffff ;
} else {
V_128 = 0x0000ffff ;
V_129 = 0x0007ffff ;
}
F_31 ( V_2 , V_86 , V_134 ) ;
break;
case V_135 :
F_30 ( V_2 , V_136 , V_137 ) ;
default:
V_128 = ( V_126 - V_138 ) << 3 ;
V_129 = ( V_126 - V_139 ) << 3 ;
break;
}
V_130 = V_126 + 1 ;
if ( V_2 -> V_9 -> V_131 == V_140 ||
V_2 -> V_9 -> V_131 == V_141 )
F_11 ( V_2 , 0 , V_142 ) ;
F_11 ( V_2 , V_126 , V_142 ) ;
F_11 ( V_2 , V_128 , V_143 ) ;
F_11 ( V_2 , V_129 , V_144 ) ;
F_11 ( V_2 , V_130 , V_145 ) ;
if ( V_127 & V_125 )
F_37 ( V_2 ) ;
F_11 ( V_2 , V_127 & ( V_146 |
V_147 ) ,
V_96 ) ;
if ( V_2 -> V_89 == V_113 )
F_11 ( V_2 , V_148 , V_149 ) ;
else
F_11 ( V_2 , V_148 , V_150 ) ;
F_31 ( V_2 , V_86 , V_151 ) ;
}
static inline bool
F_39 ( int V_152 , int V_153 , int V_154 , int V_155 )
{
if ( ( V_153 - V_152 == V_154 ) ||
( V_152 - V_153 == V_155 - V_154 ) ||
( ( V_152 | 0x10000 ) - V_153 == V_155 - V_154 ) ||
( ( V_153 | 0x10000 ) - V_152 == V_154 ) )
return true ;
return false ;
}
bool
F_40 ( struct V_1 * V_2 , int V_155 )
{
unsigned int V_156 , V_157 , V_158 ;
V_156 = F_8 ( V_2 , V_142 ) ;
V_157 = F_8 ( V_2 , V_145 ) ;
V_158 = F_8 ( V_2 , V_143 ) >> 3 ;
if ( F_39 ( V_156 , V_157 , 1 , V_155 ) &&
F_39 ( V_158 , V_156 , V_138 ,
V_155 ) )
return true ;
return false ;
}
void F_41 ( struct V_1 * V_2 , T_2 V_159 )
{
int V_36 = F_5 ( V_2 ) + 3 * V_159 ;
int V_160 = F_6 ( V_2 ) + V_36 ;
int V_161 = V_160 ;
F_42 ( V_2 , V_36 ) ;
F_12 ( V_2 , V_160 ) ;
F_17 ( V_2 , V_161 ) ;
V_2 -> V_162 = V_159 ;
}
void F_43 ( struct V_1 * V_2 )
{
F_31 ( V_2 , V_163 , V_164 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_163 , V_164 ) ;
}
int F_45 ( struct V_1 * V_2 , enum V_165 V_166 )
{
struct V_79 * V_80 = F_19 ( V_2 ) ;
T_3 V_83 , V_167 , V_81 , V_82 ;
F_46 ( V_2 -> V_9 , V_168 , L_1 , V_166 ) ;
V_83 = F_8 ( V_2 , V_86 ) & 0xffff0000 ;
V_83 &= ~ ( V_169 | V_170
| V_171
| ( V_2 -> V_89 == V_113 ?
( V_151 | V_172 ) : 0 ) ) ;
V_167 = 0 ;
switch ( V_166 ) {
case V_135 :
V_83 |= V_169 | V_171 ;
V_167 |= V_173 ;
if ( V_2 -> V_89 == V_113 )
V_83 |= V_172 ;
else
F_30 ( V_2 , V_174 , V_175 ) ;
break;
case V_140 :
case V_141 :
V_83 |= V_170 | V_171 ;
V_167 |= V_176 ;
if ( V_2 -> V_89 == V_113 )
V_83 |= V_172 ;
else
F_31 ( V_2 , V_174 , V_175 ) ;
break;
case V_133 :
V_83 |= V_171
| ( V_2 -> V_89 == V_113 ?
V_151 : 0 ) ;
case V_132 :
V_83 |= V_171
| ( V_2 -> V_89 == V_113 ?
V_172 : 0 ) ;
break;
default:
return - V_75 ;
}
V_81 = F_20 ( V_80 -> V_84 ) ;
V_82 = F_21 ( V_80 -> V_84 + 4 ) ;
F_11 ( V_2 , V_81 , V_87 ) ;
F_11 ( V_2 , V_83 | V_82 , V_86 ) ;
if ( V_2 -> V_89 == V_113 )
F_11 ( V_2 , V_167 , V_177 ) ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 , enum V_165 V_166 ,
T_2 V_178 )
{
F_22 ( V_2 ) ;
F_45 ( V_2 , V_166 ) ;
if ( V_2 -> V_89 == V_90 &&
V_2 -> V_9 -> V_179 )
F_9 ( V_2 ) ;
F_11 ( V_2 , ( V_180 |
V_181 <<
V_182 ) ,
V_183 ) ;
if ( V_2 -> V_184 >= V_185 ) {
F_11 ( V_2 , 0x000100aa , V_186 ) ;
F_11 ( V_2 , 0x00003210 , V_187 ) ;
}
if ( V_2 -> V_89 == V_90 ) {
F_11 ( V_2 ,
F_48 ( 2 , V_188 ) |
F_48 ( 5 , V_189 ) |
F_48 ( 0 , V_190 ) ,
V_191 ) ;
}
if ( V_2 -> V_162 > 0 )
F_41 ( V_2 , V_2 -> V_162 ) ;
if ( V_2 -> V_89 == V_90 ) {
T_3 V_124 = V_192 | V_193 ;
if ( V_2 -> V_67 )
F_31 ( V_2 , V_86 , V_124 ) ;
else
F_30 ( V_2 , V_86 , V_124 ) ;
}
return;
}
