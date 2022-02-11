int
F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
int V_5 , struct V_6 * V_7 , bool V_8 )
{
int V_9 , V_10 , V_11 , V_12 ;
int V_13 , V_14 , V_15 , V_16 ;
int V_17 ;
if ( ! V_2 -> V_18 ) {
T_1 V_19 = F_2 ( V_2 -> V_20 ,
NULL , V_4 , V_5 , V_7 ) ;
V_17 = F_3 ( V_19 ) ;
if ( V_8 )
V_17 -= 96 ;
return V_17 ;
}
V_13 = V_7 -> V_13 ;
V_10 = V_21 ;
V_11 = V_22 ;
V_12 = V_23 ;
switch ( V_2 -> V_18 ) {
case V_24 :
V_9 = V_25 ;
V_10 = V_26 ;
break;
case V_27 :
V_9 = V_28 ;
V_10 *= 2 ;
V_12 *= 2 ;
V_13 = F_4 ( V_13 , 2 ) ;
break;
case V_29 :
V_9 = V_30 ;
V_10 *= 4 ;
V_12 *= 4 ;
V_13 = F_4 ( V_13 , 4 ) ;
break;
default:
V_9 = V_31 ;
break;
}
V_14 = V_11 + ( V_5 << 3 ) ;
V_16 = V_13 * V_12 ;
V_15 = F_4 ( V_14 * 10 , V_16 ) ;
V_17 = V_9 + V_10 + ( V_12 * V_15 ) ;
return V_17 ;
}
unsigned int
F_5 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_34 ;
unsigned int V_35 ;
switch ( V_2 -> V_18 ) {
case V_24 :
V_35 = V_36 ;
break;
case V_27 :
V_35 = V_37 ;
break;
case V_29 :
V_35 = V_38 ;
break;
case V_39 :
default:
V_35 = V_40 ;
if ( ( V_33 -> V_41 == V_42 ) && ! V_2 -> V_43 )
V_35 = V_44 ;
break;
}
return V_35 ;
}
unsigned int
F_6 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_34 ;
unsigned int V_9 ;
switch ( V_2 -> V_18 ) {
case V_24 :
V_9 = V_25 ;
break;
case V_27 :
V_9 = V_28 ;
break;
case V_29 :
V_9 = V_30 ;
break;
case V_39 :
V_9 = V_31 ;
default:
if ( V_33 -> V_4 == V_45 )
V_9 = V_46 ;
break;
}
return V_9 ;
}
void
F_7 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = & V_2 -> V_48 ;
V_48 -> V_49 += F_8 ( V_2 , V_50 ) ;
V_48 -> V_51 += F_8 ( V_2 , V_52 ) ;
V_48 -> V_53 += F_8 ( V_2 , V_54 ) ;
V_48 -> V_55 += F_8 ( V_2 , V_56 ) ;
V_48 -> V_57 += F_8 ( V_2 , V_58 ) ;
}
static inline void
F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
unsigned int V_59 ;
T_2 V_4 = V_60 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_61 [ V_4 ] . V_62 ; V_59 ++ ) {
T_3 V_63 ;
T_4 V_64 ;
if ( V_2 -> V_65 )
V_7 = & V_2 -> V_61 [ V_4 ] . V_66 [ V_67 [ V_59 ] ] ;
else if ( V_59 < 4 )
V_7 = & V_2 -> V_61 [ V_4 ] . V_66 [ 0 ] ;
else
V_7 = & V_2 -> V_61 [ V_4 ] . V_66 [ 4 ] ;
V_63 = F_10 ( V_7 -> V_41 ) ;
V_64 = F_1 ( V_2 , V_4 , 10 ,
V_7 , false ) ;
F_11 ( V_2 , V_64 , V_63 ) ;
if ( ! ( V_7 -> V_68 & V_69 ) )
continue;
V_64 = F_1 ( V_2 , V_4 , 10 , V_7 , true ) ;
F_11 ( V_2 , V_64 ,
V_63 + ( V_70 << 2 ) ) ;
}
}
static int
F_12 ( struct V_1 * V_2 , unsigned int V_71 )
{
if ( F_13 ( V_2 , F_14 ( 0xffffffff , V_72 ) )
<= V_71 )
return - V_73 ;
F_15 ( V_2 , V_74 , V_72 ,
F_16 ( V_2 , V_71 ) ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , unsigned int V_71 )
{
if ( F_13 ( V_2 , F_14 ( 0xffffffff , V_75 ) )
<= V_71 )
return - V_73 ;
F_15 ( V_2 , V_74 , V_75 ,
F_16 ( V_2 , V_71 ) ) ;
return 0 ;
}
int
F_18 ( struct V_1 * V_2 , const T_2 * V_76 )
{
struct V_77 * V_78 = F_19 ( V_2 ) ;
T_3 V_79 , V_80 ;
T_3 V_81 ;
memcpy ( V_78 -> V_82 , V_76 , V_83 ) ;
V_81 = F_8 ( V_2 , V_84 ) & 0xffff0000 ;
V_79 = F_20 ( V_76 ) ;
V_80 = F_21 ( V_76 + 4 ) ;
F_11 ( V_2 , V_79 , V_85 ) ;
F_11 ( V_2 , V_81 | V_80 , V_84 ) ;
return 0 ;
}
void
F_22 ( struct V_1 * V_2 )
{
struct V_77 * V_78 = F_19 ( V_2 ) ;
T_4 V_86 = 0 ;
if ( V_2 -> V_87 == V_88 )
F_23 ( V_78 ) ;
F_11 ( V_2 ,
F_20 ( V_78 -> V_89 ) ,
V_90 ) ;
F_11 ( V_2 ,
F_21 ( V_78 -> V_89 + 4 ) |
( ( V_78 -> V_91 & 0x3fff ) << V_92 ) ,
V_93 ) ;
if ( V_78 -> V_91 == 0 ) {
F_24 ( V_2 ) ;
return;
}
F_15 ( V_2 , V_94 , V_95 ,
V_86 ? V_86 + 4 : 0 ) ;
F_25 ( V_2 , NULL , 0 ) ;
}
void
F_26 ( struct V_1 * V_2 , const T_2 * V_96 )
{
struct V_77 * V_78 = F_19 ( V_2 ) ;
memcpy ( V_78 -> V_97 , V_96 , V_83 ) ;
if ( V_2 -> V_87 == V_88 )
F_23 ( V_78 ) ;
}
void
F_27 ( struct V_1 * V_2 , T_3 V_98 , T_3 V_99 )
{
F_11 ( V_2 , V_98 , V_100 ) ;
F_11 ( V_2 , V_99 , V_101 ) ;
}
T_3
F_28 ( struct V_1 * V_2 )
{
T_3 V_102 , V_103 = 0 ;
V_103 = F_8 ( V_2 , V_104 ) ;
if ( V_2 -> V_87 == V_88 ) {
V_102 = F_8 ( V_2 , V_105 ) ;
if ( V_102 & V_106 )
V_103 |= V_107 ;
if ( V_102 & ( V_108 | V_109 ) )
V_103 |= V_110 ;
}
return V_103 ;
}
void
F_29 ( struct V_1 * V_2 , T_3 V_103 )
{
T_3 V_102 = 0 ;
if ( V_2 -> V_87 == V_88 ) {
if ( V_103 & V_107 )
V_102 |= V_106 ;
if ( V_103 & V_110 )
V_102 |= V_108 | V_109 ;
}
if ( V_2 -> V_87 == V_111 &&
( V_103 & V_107 ) ) {
V_103 &= ~ V_107 ;
V_103 |= V_112 ;
}
if ( V_102 )
F_30 ( V_2 , V_113 , V_114 ) ;
else
F_31 ( V_2 , V_113 , V_114 ) ;
F_11 ( V_2 , V_103 & 0xff , V_104 ) ;
if ( V_2 -> V_87 == V_88 )
F_11 ( V_2 , V_102 , V_105 ) ;
}
T_5
F_32 ( struct V_1 * V_2 )
{
T_3 V_115 , V_116 , V_117 ;
int V_59 ;
unsigned long V_68 ;
F_33 ( V_68 ) ;
V_116 = F_8 ( V_2 , V_118 ) ;
for ( V_59 = 0 ; V_59 < V_119 ; V_59 ++ ) {
V_115 = F_8 ( V_2 , V_120 ) ;
V_117 = F_8 ( V_2 , V_118 ) ;
if ( V_117 == V_116 )
break;
V_116 = V_117 ;
}
F_34 ( V_68 ) ;
F_35 ( V_59 == V_119 ) ;
return ( ( T_5 ) V_116 << 32 ) | V_115 ;
}
void
F_36 ( struct V_1 * V_2 , T_5 V_121 )
{
F_11 ( V_2 , V_121 & 0xffffffff , V_120 ) ;
F_11 ( V_2 , ( V_121 >> 32 ) & 0xffffffff , V_118 ) ;
}
void
F_37 ( struct V_1 * V_2 )
{
T_3 V_122 ;
V_122 = F_8 ( V_2 , V_94 ) | V_123 ;
F_11 ( V_2 , V_122 , V_94 ) ;
F_11 ( V_2 , V_122 , V_94 ) ;
}
void
F_38 ( struct V_1 * V_2 , T_3 V_124 , T_3 V_125 )
{
T_3 V_126 , V_127 , V_128 ;
switch ( V_2 -> V_129 ) {
case V_130 :
case V_131 :
if ( V_2 -> V_87 == V_111 ) {
V_126 = 0xffffffff ;
V_127 = 0xffffffff ;
} else {
V_126 = 0x0000ffff ;
V_127 = 0x0007ffff ;
}
F_31 ( V_2 , V_84 , V_132 ) ;
break;
case V_133 :
F_30 ( V_2 , V_134 , V_135 ) ;
default:
V_126 = ( V_124 - V_136 ) << 3 ;
V_127 = ( V_124 - V_137 ) << 3 ;
break;
}
V_128 = V_124 + 1 ;
if ( V_2 -> V_129 == V_138 ||
V_2 -> V_129 == V_139 )
F_11 ( V_2 , 0 , V_140 ) ;
F_11 ( V_2 , V_124 , V_140 ) ;
F_11 ( V_2 , V_126 , V_141 ) ;
F_11 ( V_2 , V_127 , V_142 ) ;
F_11 ( V_2 , V_128 , V_143 ) ;
if ( V_125 & V_123 )
F_37 ( V_2 ) ;
F_11 ( V_2 , V_125 & ( V_144 |
V_145 ) ,
V_94 ) ;
if ( V_2 -> V_87 == V_111 )
F_11 ( V_2 , V_146 , V_147 ) ;
else
F_11 ( V_2 , V_146 , V_148 ) ;
F_31 ( V_2 , V_84 , V_149 ) ;
}
static inline bool
F_39 ( int V_150 , int V_151 , int V_152 , int V_153 )
{
if ( ( V_151 - V_150 == V_152 ) ||
( V_150 - V_151 == V_153 - V_152 ) ||
( ( V_150 | 0x10000 ) - V_151 == V_153 - V_152 ) ||
( ( V_151 | 0x10000 ) - V_150 == V_152 ) )
return true ;
return false ;
}
bool
F_40 ( struct V_1 * V_2 , int V_153 )
{
unsigned int V_154 , V_155 , V_156 ;
V_154 = F_8 ( V_2 , V_140 ) ;
V_155 = F_8 ( V_2 , V_143 ) ;
V_156 = F_8 ( V_2 , V_141 ) >> 3 ;
if ( F_39 ( V_154 , V_155 , 1 , V_153 ) &&
F_39 ( V_156 , V_154 , V_136 ,
V_153 ) )
return true ;
return false ;
}
void
F_41 ( struct V_1 * V_2 , T_2 V_157 )
{
int V_35 = F_5 ( V_2 ) + 3 * V_157 ;
int V_158 = F_6 ( V_2 ) + V_35 ;
int V_159 = V_158 ;
F_42 ( V_2 , V_35 ) ;
F_12 ( V_2 , V_158 ) ;
F_17 ( V_2 , V_159 ) ;
V_2 -> V_160 = V_157 ;
}
void
F_43 ( struct V_1 * V_2 )
{
F_31 ( V_2 , V_161 , V_162 ) ;
}
void
F_44 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_161 , V_162 ) ;
}
int
F_45 ( struct V_1 * V_2 , enum V_163 V_164 )
{
struct V_77 * V_78 = F_19 ( V_2 ) ;
T_3 V_81 , V_165 , V_79 , V_80 ;
F_46 ( V_2 , V_166 , L_1 , V_164 ) ;
V_81 = F_8 ( V_2 , V_84 ) & 0xffff0000 ;
V_81 &= ~ ( V_167 | V_168
| V_169
| ( V_2 -> V_87 == V_111 ?
( V_149 | V_170 ) : 0 ) ) ;
V_165 = 0 ;
switch ( V_164 ) {
case V_133 :
V_81 |= V_167 | V_169 ;
V_165 |= V_171 ;
if ( V_2 -> V_87 == V_111 )
V_81 |= V_170 ;
else
F_30 ( V_2 , V_172 , V_173 ) ;
break;
case V_138 :
case V_139 :
V_81 |= V_168 | V_169 ;
V_165 |= V_174 ;
if ( V_2 -> V_87 == V_111 )
V_81 |= V_170 ;
else
F_31 ( V_2 , V_172 , V_173 ) ;
break;
case V_131 :
V_81 |= V_169
| ( V_2 -> V_87 == V_111 ?
V_149 : 0 ) ;
case V_130 :
V_81 |= V_169
| ( V_2 -> V_87 == V_111 ?
V_170 : 0 ) ;
break;
default:
return - V_73 ;
}
V_79 = F_20 ( V_78 -> V_82 ) ;
V_80 = F_21 ( V_78 -> V_82 + 4 ) ;
F_11 ( V_2 , V_79 , V_85 ) ;
F_11 ( V_2 , V_81 | V_80 , V_84 ) ;
if ( V_2 -> V_87 == V_111 )
F_11 ( V_2 , V_165 , V_175 ) ;
return 0 ;
}
void
F_47 ( struct V_1 * V_2 , enum V_163 V_164 )
{
F_22 ( V_2 ) ;
F_45 ( V_2 , V_164 ) ;
if ( V_2 -> V_87 == V_88 &&
V_2 -> V_176 )
F_9 ( V_2 ) ;
F_11 ( V_2 , ( V_177 |
V_178 <<
V_179 ) ,
V_180 ) ;
if ( V_2 -> V_181 >= V_182 ) {
F_11 ( V_2 , 0x000100aa , V_183 ) ;
F_11 ( V_2 , 0x00003210 , V_184 ) ;
}
if ( V_2 -> V_87 == V_88 ) {
F_11 ( V_2 ,
F_48 ( 2 , V_185 ) |
F_48 ( 5 , V_186 ) |
F_48 ( 0 , V_187 ) ,
V_188 ) ;
}
if ( V_2 -> V_160 > 0 )
F_41 ( V_2 , V_2 -> V_160 ) ;
if ( V_2 -> V_87 == V_88 ) {
T_3 V_122 = V_189 | V_190 ;
if ( V_2 -> V_65 )
F_31 ( V_2 , V_84 , V_122 ) ;
else
F_30 ( V_2 , V_84 , V_122 ) ;
}
return;
}
