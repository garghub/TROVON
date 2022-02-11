static bool F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
if ( V_2 -> V_5 . V_6 && ( V_4 > V_7 ) )
return false ;
if ( ( F_2 ( V_2 ) & V_8 ) && V_4 > V_9 )
return false ;
return true ;
}
int F_3 ( struct V_10 * V_11 , struct V_1 * V_2 ,
unsigned int V_12 , int * V_13 )
{
int V_14 = V_15 ;
int V_16 = F_4 ( V_12 ) ;
int V_17 = F_5 ( V_12 ) ;
int V_18 = F_6 ( V_12 ) ;
int V_19 = F_7 ( V_12 ) ;
T_1 V_20 = 0x44000002 ;
switch ( F_8 ( V_12 ) ) {
case 0 :
V_14 = V_21 ;
if ( ( F_2 ( V_2 ) & V_22 ) &&
( V_12 == F_9 ( V_20 ) ) ) {
F_10 ( V_2 , 3 , V_23 ) ;
F_11 ( V_2 , F_12 ( V_2 ) + 4 ) ;
V_14 = V_15 ;
}
break;
case 19 :
switch ( F_13 ( V_12 ) ) {
case V_24 :
case V_25 :
F_11 ( V_2 , F_14 ( V_2 ) ) ;
F_15 ( V_2 , F_16 ( V_2 ) ) ;
* V_13 = 0 ;
break;
default:
V_14 = V_21 ;
break;
}
break;
case 31 :
switch ( F_13 ( V_12 ) ) {
case V_26 :
F_10 ( V_2 , V_16 , F_2 ( V_2 ) ) ;
break;
case V_27 :
{
T_2 V_28 = F_17 ( V_2 , V_17 ) ;
if ( V_12 & 0x10000 ) {
T_2 V_29 = F_2 ( V_2 ) ;
V_29 &= ~ ( V_30 | V_31 ) ;
V_29 |= V_28 & ( V_30 | V_31 ) ;
F_18 ( V_2 , V_29 ) ;
} else
F_15 ( V_2 , V_28 ) ;
break;
}
case V_32 :
F_15 ( V_2 , F_17 ( V_2 , V_17 ) ) ;
break;
case V_33 :
{
int V_34 ;
V_34 = F_19 ( V_12 , 12 + 32 , 15 + 32 ) ;
if ( V_2 -> V_5 . V_35 . V_36 ) {
T_1 V_37 ;
V_37 = V_2 -> V_5 . V_35 . V_36 ( V_2 , V_34 ) ;
F_10 ( V_2 , V_16 , V_37 ) ;
}
break;
}
case V_38 :
{
int V_34 ;
V_34 = ( F_17 ( V_2 , V_19 ) >> 28 ) & 0xf ;
if ( V_2 -> V_5 . V_35 . V_36 ) {
T_1 V_37 ;
V_37 = V_2 -> V_5 . V_35 . V_36 ( V_2 , V_34 ) ;
F_10 ( V_2 , V_16 , V_37 ) ;
}
break;
}
case V_39 :
V_2 -> V_5 . V_35 . V_40 ( V_2 ,
( V_12 >> 16 ) & 0xf ,
F_17 ( V_2 , V_17 ) ) ;
break;
case V_41 :
V_2 -> V_5 . V_35 . V_40 ( V_2 ,
( F_17 ( V_2 , V_19 ) >> 28 ) & 0xf ,
F_17 ( V_2 , V_17 ) ) ;
break;
case V_42 :
case V_43 :
{
bool V_44 = ( V_12 & 0x00200000 ) ? true : false ;
T_2 V_45 = F_17 ( V_2 , V_19 ) ;
V_2 -> V_5 . V_35 . V_46 ( V_2 , V_45 , V_44 ) ;
break;
}
#ifdef F_20
case V_47 :
{
T_2 V_48 = F_17 ( V_2 , 3 ) ;
int V_49 ;
if ( ( F_2 ( V_2 ) & V_8 ) ||
! V_2 -> V_5 . V_6 ) {
V_14 = V_21 ;
break;
}
if ( F_21 ( V_2 , V_48 ) == V_15 )
break;
V_11 -> V_50 . V_51 = V_48 ;
for ( V_49 = 0 ; V_49 < 9 ; ++ V_49 ) {
T_2 V_52 = F_17 ( V_2 , 4 + V_49 ) ;
V_11 -> V_50 . args [ V_49 ] = V_52 ;
}
V_11 -> V_53 = V_54 ;
V_2 -> V_5 . V_55 = 1 ;
V_14 = V_56 ;
break;
}
#endif
case V_57 :
break;
case V_58 :
if ( ! V_2 -> V_5 . V_35 . V_59 )
return V_21 ;
V_2 -> V_5 . V_35 . V_59 ( V_2 ,
F_17 ( V_2 , V_17 ) ,
F_17 ( V_2 , V_19 ) ) ;
break;
case V_60 :
if ( ! V_2 -> V_5 . V_35 . V_61 )
return V_21 ;
V_2 -> V_5 . V_35 . V_61 ( V_2 ,
F_17 ( V_2 , V_19 ) ) ;
break;
case V_62 :
if ( ! V_2 -> V_5 . V_35 . V_63 )
return V_21 ;
V_2 -> V_5 . V_35 . V_63 ( V_2 ) ;
break;
case V_64 :
if ( ! V_2 -> V_5 . V_35 . V_65 ) {
V_14 = V_21 ;
} else {
T_2 V_66 , V_67 ;
V_67 = F_17 ( V_2 , V_19 ) ;
V_66 = V_2 -> V_5 . V_35 . V_65 ( V_2 , V_67 ) ;
F_10 ( V_2 , V_16 , V_66 ) ;
}
break;
case V_68 :
if ( ! V_2 -> V_5 . V_35 . V_69 ) {
V_14 = V_21 ;
} else {
T_2 V_66 , V_67 ;
V_67 = F_17 ( V_2 , V_19 ) ;
V_66 = V_2 -> V_5 . V_35 . V_69 ( V_2 , V_67 ) ;
F_10 ( V_2 , V_16 , V_66 ) ;
}
break;
case V_70 :
break;
case V_71 :
{
T_2 V_67 = F_17 ( V_2 , V_19 ) ;
T_2 V_72 = 0 ;
T_2 V_45 , V_73 ;
T_1 V_74 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_1 V_75 ;
int V_76 ;
if ( V_18 )
V_72 = F_17 ( V_2 , V_18 ) ;
V_45 = ( V_72 + V_67 ) & ~ 31ULL ;
if ( ! ( F_2 ( V_2 ) & V_77 ) )
V_45 &= 0xffffffff ;
V_73 = V_45 ;
V_76 = F_22 ( V_2 , & V_45 , 32 , V_74 , true ) ;
if ( ( V_76 == - V_78 ) || ( V_76 == - V_79 ) ) {
* V_13 = 0 ;
F_23 ( V_2 , V_73 ) ;
V_2 -> V_5 . V_80 = V_73 ;
V_75 = V_81 ;
if ( V_76 == - V_78 )
V_75 |= V_82 ;
else if ( V_76 == - V_79 )
V_75 |= V_83 ;
F_24 ( V_2 , V_75 ) ;
V_2 -> V_5 . V_84 = V_75 ;
F_25 ( V_2 ,
V_85 ) ;
}
break;
}
default:
V_14 = V_21 ;
}
break;
default:
V_14 = V_21 ;
}
if ( V_14 == V_21 )
V_14 = F_26 ( V_11 , V_2 ) ;
return V_14 ;
}
void F_27 ( struct V_1 * V_2 , struct V_86 * V_87 , bool V_88 ,
T_1 V_89 )
{
if ( V_88 ) {
T_1 V_90 = ( V_89 >> 2 ) & 0x7ff ;
V_87 -> V_91 = ( ~ V_90 << 17 ) ;
V_87 -> V_92 = V_89 & 0xfffe0000 ;
V_87 -> V_93 = ( V_89 & 2 ) ? 1 : 0 ;
V_87 -> V_94 = ( V_89 & 1 ) ? 1 : 0 ;
V_87 -> V_95 = ( V_87 -> V_95 & 0xffffffff00000000ULL ) | V_89 ;
} else {
V_87 -> V_96 = V_89 & 0xfffe0000 ;
V_87 -> V_97 = ( V_89 >> 3 ) & 0xf ;
V_87 -> V_98 = V_89 & 3 ;
V_87 -> V_95 = ( V_87 -> V_95 & 0x00000000ffffffffULL ) | ( ( V_99 ) V_89 << 32 ) ;
}
}
static struct V_86 * F_28 ( struct V_1 * V_2 , int V_100 )
{
struct V_101 * V_102 = F_29 ( V_2 ) ;
struct V_86 * V_87 ;
switch ( V_100 ) {
case V_103 ... V_104 :
V_87 = & V_102 -> V_105 [ ( V_100 - V_103 ) / 2 ] ;
break;
case V_106 ... V_107 :
V_87 = & V_102 -> V_105 [ 4 + ( ( V_100 - V_106 ) / 2 ) ] ;
break;
case V_108 ... V_109 :
V_87 = & V_102 -> V_110 [ ( V_100 - V_108 ) / 2 ] ;
break;
case V_111 ... V_112 :
V_87 = & V_102 -> V_110 [ 4 + ( ( V_100 - V_111 ) / 2 ) ] ;
break;
default:
F_30 () ;
}
return V_87 ;
}
int F_31 ( struct V_1 * V_2 , int V_100 , T_2 V_113 )
{
int V_14 = V_15 ;
switch ( V_100 ) {
case V_114 :
if ( ! F_1 ( V_2 , V_115 ) )
goto V_116;
F_29 ( V_2 ) -> V_117 = V_113 ;
break;
case V_118 :
F_24 ( V_2 , V_113 ) ;
break;
case V_119 :
F_23 ( V_2 , V_113 ) ;
break;
case V_120 :
F_29 ( V_2 ) -> V_121 = V_113 ;
break;
case V_103 ... V_104 :
case V_106 ... V_107 :
case V_108 ... V_109 :
case V_111 ... V_112 :
{
struct V_86 * V_87 = F_28 ( V_2 , V_100 ) ;
F_27 ( V_2 , V_87 , ! ( V_100 % 2 ) , ( T_1 ) V_113 ) ;
F_32 ( V_2 , 0 , 0 ) ;
F_33 ( V_2 ) ;
break;
}
case V_122 :
F_29 ( V_2 ) -> V_123 [ 0 ] = V_113 ;
break;
case V_124 :
F_29 ( V_2 ) -> V_123 [ 1 ] = V_113 ;
break;
case V_125 :
F_29 ( V_2 ) -> V_123 [ 2 ] = V_113 ;
break;
case V_126 :
F_29 ( V_2 ) -> V_123 [ 2 ] = V_113 ;
switch ( V_2 -> V_5 . V_127 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
if ( V_2 -> V_5 . V_128 & V_129 ) {
} else if ( V_113 & ( 1 << 29 ) ) {
V_2 -> V_5 . V_128 |= V_130 ;
F_34 ( V_2 , V_131 ) ;
} else {
V_2 -> V_5 . V_128 &= ~ V_130 ;
}
break;
}
break;
case V_132 :
case V_133 :
F_29 ( V_2 ) -> V_123 [ 4 ] = V_113 ;
break;
case V_134 :
F_29 ( V_2 ) -> V_123 [ 5 ] = V_113 ;
if ( V_2 -> V_5 . V_35 . V_135 ( V_2 ) &&
( F_35 () & V_136 ) )
V_2 -> V_5 . V_128 |= V_137 ;
break;
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
F_29 ( V_2 ) -> V_146 [ V_100 - V_138 ] = V_113 ;
break;
#ifdef F_20
case V_147 :
F_36 ( V_2 , V_113 ) ;
break;
case V_148 :
V_2 -> V_5 . V_149 = V_113 ;
break;
case V_150 :
V_2 -> V_5 . V_151 = V_113 ;
break;
case V_152 :
V_2 -> V_5 . V_153 = V_113 ;
break;
#ifdef F_37
case V_154 :
V_2 -> V_5 . V_155 = V_113 ;
break;
case V_156 :
V_2 -> V_5 . V_157 = V_113 ;
break;
case V_158 :
V_2 -> V_5 . V_159 = V_113 ;
break;
#endif
#endif
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
#ifdef F_20
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
#endif
break;
V_116:
default:
F_38 ( L_1 , V_100 ) ;
if ( V_100 & 0x10 ) {
if ( F_2 ( V_2 ) & V_8 ) {
F_39 ( V_2 , V_183 ) ;
V_14 = V_184 ;
}
} else {
if ( ( F_2 ( V_2 ) & V_8 ) || V_100 == 0 ) {
F_39 ( V_2 , V_185 ) ;
V_14 = V_184 ;
}
}
break;
}
return V_14 ;
}
int F_40 ( struct V_1 * V_2 , int V_100 , T_2 * V_113 )
{
int V_14 = V_15 ;
switch ( V_100 ) {
case V_103 ... V_104 :
case V_106 ... V_107 :
case V_108 ... V_109 :
case V_111 ... V_112 :
{
struct V_86 * V_87 = F_28 ( V_2 , V_100 ) ;
if ( V_100 % 2 )
* V_113 = V_87 -> V_95 >> 32 ;
else
* V_113 = V_87 -> V_95 ;
break;
}
case V_114 :
if ( ! F_1 ( V_2 , V_115 ) )
goto V_116;
* V_113 = F_29 ( V_2 ) -> V_117 ;
break;
case V_118 :
* V_113 = F_41 ( V_2 ) ;
break;
case V_119 :
* V_113 = F_42 ( V_2 ) ;
break;
case V_120 :
* V_113 = F_29 ( V_2 ) -> V_121 ;
break;
case V_122 :
* V_113 = F_29 ( V_2 ) -> V_123 [ 0 ] ;
break;
case V_124 :
* V_113 = F_29 ( V_2 ) -> V_123 [ 1 ] ;
break;
case V_125 :
case V_126 :
* V_113 = F_29 ( V_2 ) -> V_123 [ 2 ] ;
break;
case V_132 :
case V_133 :
* V_113 = F_29 ( V_2 ) -> V_123 [ 4 ] ;
break;
case V_134 :
* V_113 = F_29 ( V_2 ) -> V_123 [ 5 ] ;
break;
case V_186 :
case V_167 :
* V_113 = 0 ;
break;
case V_187 :
* V_113 = V_2 -> V_5 . V_188 ;
break;
case V_189 :
* V_113 = V_2 -> V_5 . V_190 ;
break;
case V_191 :
* V_113 = F_29 ( V_2 ) -> V_192 ;
break;
case V_193 :
* V_113 = V_2 -> V_5 . V_194 ;
break;
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
* V_113 = F_29 ( V_2 ) -> V_146 [ V_100 - V_138 ] ;
break;
#ifdef F_20
case V_147 :
* V_113 = V_2 -> V_5 . V_195 ;
break;
case V_148 :
* V_113 = V_2 -> V_5 . V_149 ;
break;
case V_150 :
* V_113 = V_2 -> V_5 . V_151 ;
break;
case V_152 :
* V_113 = V_2 -> V_5 . V_153 ;
break;
#ifdef F_37
case V_154 :
* V_113 = V_2 -> V_5 . V_155 ;
break;
case V_156 :
* V_113 = V_2 -> V_5 . V_157 ;
break;
case V_158 :
* V_113 = V_2 -> V_5 . V_159 ;
break;
#endif
#endif
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
#ifdef F_20
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_196 :
#endif
* V_113 = 0 ;
break;
default:
V_116:
F_38 ( L_2 , V_100 ) ;
if ( V_100 & 0x10 ) {
if ( F_2 ( V_2 ) & V_8 ) {
F_39 ( V_2 , V_183 ) ;
V_14 = V_184 ;
}
} else {
if ( ( F_2 ( V_2 ) & V_8 ) || V_100 == 0 ||
V_100 == 4 || V_100 == 5 || V_100 == 6 ) {
F_39 ( V_2 , V_185 ) ;
V_14 = V_184 ;
}
}
break;
}
return V_14 ;
}
T_1 F_43 ( struct V_1 * V_2 , unsigned int V_12 )
{
return F_44 ( V_12 ) ;
}
T_2 F_45 ( struct V_1 * V_2 , unsigned int V_12 )
{
#ifdef F_20
return V_2 -> V_5 . V_80 ;
#else
T_2 V_197 = 0 ;
T_2 V_18 = F_6 ( V_12 ) ;
T_2 V_19 = F_7 ( V_12 ) ;
switch ( F_8 ( V_12 ) ) {
case V_198 :
case V_199 :
case V_200 :
case V_201 :
if ( V_18 )
V_197 = F_17 ( V_2 , V_18 ) ;
V_197 += ( V_202 ) ( ( V_203 ) V_12 ) ;
break;
case 31 :
if ( V_18 )
V_197 = F_17 ( V_2 , V_18 ) ;
V_197 += F_17 ( V_2 , V_19 ) ;
break;
default:
F_46 ( V_204 L_3 , V_12 ) ;
break;
}
return V_197 ;
#endif
}
