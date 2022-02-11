static void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_5 = V_2 -> V_6 ;
enum V_7 V_8 = V_2 -> V_8 ;
V_3 [ 4 ] |= ( 1 << V_9 ) &
F_2 ( V_9 , V_10 ) ;
V_3 [ 3 ] |= V_11 ;
V_3 [ 2 ] |= V_12 ;
V_5 >>= 8 ;
V_3 [ 2 ] |= ( V_5 << V_13 ) &
F_3 ( V_13 , V_14 ) ;
V_5 >>= V_14 ;
V_3 [ 3 ] |= V_5 & F_3 ( V_15 , V_16 ) ;
V_3 [ 3 ] |= ( ( T_1 ) V_8 << V_17 ) &
F_2 ( V_17 , V_18 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
bool V_19 ;
T_1 V_20 ;
V_19 = F_5 ( V_2 -> V_21 ) ;
V_20 = ( V_19 ) ? V_22 : V_23 ;
V_3 [ 4 ] |= ( V_20 << V_24 ) &
F_2 ( V_24 , V_25 ) ;
if ( V_19 ) {
V_3 [ 3 ] |= ( V_26 << V_27 ) &
F_2 ( V_27 , V_28 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
V_3 [ 3 ] |= V_29 ;
V_3 [ 3 ] |= ( 0xf << V_30 ) &
F_2 ( V_30 , V_31 ) ;
V_3 [ 4 ] |= 0x7 & F_2 ( V_32 , V_33 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_34 , T_1 V_35 )
{
struct V_36 * V_37 = F_8 ( V_2 -> V_38 ) ;
F_9 ( V_35 , V_37 -> V_39 + V_34 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_34 , T_1 * V_35 )
{
struct V_36 * V_37 = F_8 ( V_2 -> V_38 ) ;
* V_35 = F_11 ( V_37 -> V_39 + V_34 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_8 ( V_2 -> V_38 ) ;
int V_40 ;
F_7 ( V_2 , V_41 , V_2 -> V_42 ) ;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 -> V_44 ; V_40 ++ ) {
F_7 ( V_2 , V_45 + ( V_40 * 4 ) ,
V_2 -> V_4 [ V_40 ] ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
F_12 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_15 ( V_2 -> V_21 ) == V_46 ||
F_15 ( V_2 -> V_21 ) == V_47 )
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_48 , V_49 ;
bool V_19 ;
V_19 = F_5 ( V_2 -> V_21 ) ;
V_48 = V_2 -> V_21 & F_17 ( 9 , 0 ) ;
V_48 |= V_50 ;
V_49 = ( V_2 -> V_42 << 9 ) & F_17 ( 18 , 9 ) ;
V_49 |= V_51 ;
if ( V_19 )
V_49 |= V_52 ;
F_7 ( V_2 , V_53 , V_48 ) ;
F_7 ( V_2 , V_54 , V_49 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_55 ;
V_55 = V_2 -> V_21 | V_50 ;
F_7 ( V_2 , V_53 , V_55 ) ;
F_7 ( V_2 , V_54 , 0 ) ;
}
static struct V_1 * F_19 (
struct V_1 * V_2 )
{
T_1 V_56 = V_2 -> V_56 ;
T_1 V_40 , V_35 ;
bool V_19 ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_16 ( V_2 ) ;
V_2 -> V_57 = F_20 ( V_2 -> V_21 , V_56 ) ;
V_19 = F_5 ( V_2 -> V_21 ) ;
if ( V_19 || F_15 ( V_2 -> V_21 ) != V_58 )
return V_2 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_57 ; V_40 ++ )
F_21 ( & V_2 -> V_59 [ V_40 ] ) ;
F_10 ( V_2 , V_60 , & V_35 ) ;
V_35 |= F_22 ( 31 - F_23 ( V_2 -> V_21 ) ) ;
F_7 ( V_2 , V_60 , V_35 ) ;
return V_2 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_35 ;
bool V_19 ;
V_19 = F_5 ( V_2 -> V_21 ) ;
if ( V_19 || F_15 ( V_2 -> V_21 ) != V_58 )
goto V_61;
F_10 ( V_2 , V_60 , & V_35 ) ;
V_35 &= ~ F_22 ( 31 - F_23 ( V_2 -> V_21 ) ) ;
F_7 ( V_2 , V_60 , V_35 ) ;
V_61:
F_18 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_62 )
{
F_9 ( V_62 , V_2 -> V_63 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 )
{
T_1 T_3 * V_64 = V_2 -> V_64 ;
T_1 V_65 , V_66 ;
V_65 = F_11 ( & V_64 [ 1 ] ) ;
V_66 = F_27 ( V_67 , V_65 ) ;
return V_66 ;
}
void F_28 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
enum V_68 V_69 )
{
switch ( V_69 ) {
case V_70 :
V_2 -> V_71 ++ ;
V_2 -> V_72 ++ ;
break;
case V_73 :
case V_74 :
V_2 -> V_75 ++ ;
V_2 -> V_72 ++ ;
break;
case V_76 :
V_2 -> V_77 ++ ;
V_2 -> V_72 ++ ;
break;
case V_78 :
V_2 -> V_79 ++ ;
V_2 -> V_72 ++ ;
break;
case V_80 :
V_2 -> V_77 ++ ;
V_2 -> V_72 ++ ;
break;
case V_81 :
V_2 -> V_82 ++ ;
break;
default:
break;
}
}
static void F_29 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_83 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static void F_30 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_84 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static void F_31 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_85 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static void F_32 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_86 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static bool F_33 ( void T_3 * V_5 , void T_3 * V_87 ,
void T_3 * V_63 , void T_3 * V_88 ,
T_1 V_89 , T_1 V_90 )
{
T_1 V_91 ;
T_4 V_92 = 10 ;
F_9 ( V_89 , V_5 ) ;
F_9 ( V_90 , V_87 ) ;
F_9 ( V_93 , V_63 ) ;
while ( ! ( V_91 = F_11 ( V_88 ) ) && V_92 -- )
F_34 ( 1 ) ;
if ( ! V_91 )
return false ;
F_9 ( 0 , V_63 ) ;
return true ;
}
static void F_35 ( struct V_36 * V_37 ,
T_1 V_89 , T_1 V_90 )
{
void T_3 * V_5 , * V_87 , * V_63 , * V_88 ;
V_5 = V_37 -> V_94 + V_95 ;
V_87 = V_37 -> V_94 + V_96 ;
V_63 = V_37 -> V_94 + V_97 ;
V_88 = V_37 -> V_94 + V_98 ;
if ( ! F_33 ( V_5 , V_87 , V_63 , V_88 , V_89 , V_90 ) )
F_36 ( V_37 -> V_38 , L_1 ,
V_89 ) ;
}
static void F_37 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 * V_20 )
{
void T_3 * V_5 = V_37 -> V_83 + V_34 ;
* V_20 = F_11 ( V_5 ) ;
}
static void F_38 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 * V_20 )
{
void T_3 * V_5 = V_37 -> V_85 + V_34 ;
* V_20 = F_11 ( V_5 ) ;
}
static void F_39 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 * V_20 )
{
void T_3 * V_5 = V_37 -> V_86 + V_34 ;
* V_20 = F_11 ( V_5 ) ;
}
static bool F_40 ( void T_3 * V_5 , void T_3 * V_99 ,
void T_3 * V_63 , void T_3 * V_88 ,
T_1 V_100 , T_1 * V_101 )
{
T_1 V_91 ;
T_4 V_92 = 10 ;
F_9 ( V_100 , V_5 ) ;
F_9 ( V_102 , V_63 ) ;
while ( ! ( V_91 = F_11 ( V_88 ) ) && V_92 -- )
F_34 ( 1 ) ;
if ( ! V_91 )
return false ;
* V_101 = F_11 ( V_99 ) ;
F_9 ( 0 , V_63 ) ;
return true ;
}
static void F_41 ( struct V_36 * V_37 ,
T_1 V_100 , T_1 * V_101 )
{
void T_3 * V_5 , * V_99 , * V_63 , * V_88 ;
V_5 = V_37 -> V_94 + V_95 ;
V_99 = V_37 -> V_94 + V_103 ;
V_63 = V_37 -> V_94 + V_97 ;
V_88 = V_37 -> V_94 + V_98 ;
if ( ! F_40 ( V_5 , V_99 , V_63 , V_88 , V_100 , V_101 ) )
F_36 ( V_37 -> V_38 , L_2 ,
V_100 ) ;
}
static void F_42 ( struct V_36 * V_37 )
{
T_1 V_104 , V_105 ;
T_4 * V_106 = V_37 -> V_38 -> V_106 ;
V_104 = ( V_106 [ 3 ] << 24 ) | ( V_106 [ 2 ] << 16 ) |
( V_106 [ 1 ] << 8 ) | V_106 [ 0 ] ;
V_105 = ( V_106 [ 5 ] << 24 ) | ( V_106 [ 4 ] << 16 ) ;
F_35 ( V_37 , V_107 , V_104 ) ;
F_35 ( V_37 , V_108 , V_105 ) ;
}
static int F_43 ( struct V_36 * V_37 )
{
struct V_109 * V_38 = V_37 -> V_38 ;
T_1 V_35 ;
T_4 V_92 = 10 ;
F_31 ( V_37 , V_110 , 0x0 ) ;
do {
F_44 ( 100 , 110 ) ;
F_38 ( V_37 , V_111 , & V_35 ) ;
} while ( ( V_35 != 0xffffffff ) && V_92 -- );
if ( V_35 != 0xffffffff ) {
F_36 ( V_38 , L_3 ) ;
return - V_112 ;
}
return 0 ;
}
static void F_45 ( struct V_36 * V_37 )
{
F_35 ( V_37 , V_113 , V_114 ) ;
F_35 ( V_37 , V_113 , 0 ) ;
}
static void F_46 ( struct V_36 * V_37 )
{
struct V_115 * V_116 = & V_37 -> V_117 -> V_116 ;
if ( V_116 -> V_118 ) {
struct V_119 * V_120 = F_47 ( V_37 -> V_119 ) ;
switch ( V_37 -> V_121 ) {
case V_122 :
F_48 ( V_120 , 2500000 ) ;
break;
case V_123 :
F_48 ( V_120 , 25000000 ) ;
break;
default:
F_48 ( V_120 , 125000000 ) ;
break;
}
}
#ifdef F_49
else {
switch ( V_37 -> V_121 ) {
case V_122 :
F_50 ( F_51 ( V_116 ) ,
L_4 , NULL , NULL ) ;
break;
case V_123 :
F_50 ( F_51 ( V_116 ) ,
L_5 , NULL , NULL ) ;
break;
default:
F_50 ( F_51 ( V_116 ) ,
L_6 , NULL , NULL ) ;
break;
}
}
#endif
}
static void F_52 ( struct V_36 * V_37 )
{
struct V_115 * V_116 = & V_37 -> V_117 -> V_116 ;
T_1 V_124 , V_125 , V_126 ;
T_1 V_127 , V_128 , V_129 ;
F_39 ( V_37 , V_130 , & V_124 ) ;
F_39 ( V_37 , V_131 , & V_125 ) ;
F_41 ( V_37 , V_132 , & V_126 ) ;
F_41 ( V_37 , V_133 , & V_127 ) ;
F_37 ( V_37 , V_134 , & V_128 ) ;
switch ( V_37 -> V_121 ) {
case V_122 :
F_53 ( & V_126 , 1 ) ;
V_127 &= ~ ( V_135 | V_136 ) ;
F_54 ( & V_124 , 0 ) ;
F_55 ( & V_125 , 500 ) ;
V_128 &= ~ V_137 ;
break;
case V_123 :
F_53 ( & V_126 , 1 ) ;
V_127 &= ~ V_136 ;
V_127 |= V_135 ;
F_54 ( & V_124 , 1 ) ;
F_55 ( & V_125 , 80 ) ;
V_128 &= ~ V_137 ;
break;
default:
F_53 ( & V_126 , 2 ) ;
V_127 &= ~ V_135 ;
V_127 |= V_136 ;
F_54 ( & V_124 , 2 ) ;
F_55 ( & V_125 , 0 ) ;
if ( V_116 -> V_118 ) {
F_56 ( & V_128 , V_37 -> V_138 ) ;
F_57 ( & V_128 , V_37 -> V_139 ) ;
}
V_128 |= V_137 ;
F_37 ( V_37 , V_140 , & V_129 ) ;
V_129 |= V_141 | V_142 ;
F_29 ( V_37 , V_140 , V_129 ) ;
break;
}
V_126 |= V_143 | V_144 | V_145 ;
F_35 ( V_37 , V_132 , V_126 ) ;
F_35 ( V_37 , V_133 , V_127 ) ;
F_29 ( V_37 , V_134 , V_128 ) ;
F_46 ( V_37 ) ;
F_32 ( V_37 , V_130 , V_124 ) ;
F_32 ( V_37 , V_131 , V_125 ) ;
}
static void F_58 ( struct V_36 * V_37 , int V_56 )
{
F_35 ( V_37 , V_146 , V_56 ) ;
}
static void F_59 ( struct V_36 * V_37 ,
bool V_147 )
{
T_1 V_35 ;
F_39 ( V_37 , V_148 , & V_35 ) ;
if ( V_147 )
V_35 |= V_149 | V_150 ;
else
V_35 &= ~ ( V_149 | V_150 ) ;
F_32 ( V_37 , V_148 , V_35 ) ;
}
static void F_60 ( struct V_36 * V_37 , bool V_147 )
{
T_1 V_35 ;
F_41 ( V_37 , V_113 , & V_35 ) ;
if ( V_147 )
V_35 |= V_151 ;
else
V_35 &= ~ V_151 ;
F_35 ( V_37 , V_113 , V_35 ) ;
V_37 -> V_152 -> V_153 ( V_37 , V_147 ) ;
}
static void F_61 ( struct V_36 * V_37 , bool V_147 )
{
T_1 V_35 ;
F_41 ( V_37 , V_113 , & V_35 ) ;
if ( V_147 )
V_35 |= V_154 ;
else
V_35 &= ~ V_154 ;
F_35 ( V_37 , V_113 , V_35 ) ;
}
static void F_62 ( struct V_36 * V_37 )
{
T_1 V_129 ;
if ( ! V_37 -> V_155 )
F_45 ( V_37 ) ;
F_52 ( V_37 ) ;
F_42 ( V_37 ) ;
F_41 ( V_37 , V_156 , & V_129 ) ;
F_63 ( & V_129 , 7 ) ;
F_35 ( V_37 , V_156 , V_129 ) ;
F_37 ( V_37 , V_157 , & V_129 ) ;
V_129 |= V_158 ;
F_29 ( V_37 , V_157 , V_129 ) ;
F_29 ( V_37 , V_159 , 0 ) ;
F_39 ( V_37 , V_160 , & V_129 ) ;
V_129 = ( V_161 << 16 ) | ( V_129 & 0xFFFF ) ;
F_32 ( V_37 , V_160 , V_129 ) ;
F_29 ( V_37 , V_162 , V_163 ) ;
F_29 ( V_37 , V_164 , V_165 ) ;
F_60 ( V_37 , V_37 -> V_166 ) ;
F_61 ( V_37 , V_37 -> V_167 ) ;
F_29 ( V_37 , V_168 , V_169 ) ;
F_39 ( V_37 , V_170 , & V_129 ) ;
V_129 &= ~ V_171 ;
V_129 &= ~ V_172 ;
V_129 |= V_173 ;
F_32 ( V_37 , V_170 , V_129 ) ;
F_29 ( V_37 , V_174 , V_175 ) ;
}
static void F_64 ( struct V_36 * V_37 )
{
T_1 V_20 = 0xffffffff ;
F_30 ( V_37 , V_176 , V_20 ) ;
F_30 ( V_37 , V_177 , V_20 ) ;
F_30 ( V_37 , V_178 , V_20 ) ;
F_30 ( V_37 , V_179 , V_20 ) ;
}
static void F_65 ( struct V_36 * V_37 ,
T_1 V_180 , T_5 V_181 ,
T_5 V_182 )
{
T_1 V_183 ;
T_1 V_184 , V_185 ;
V_184 = F_66 ( V_181 ) ;
V_185 = F_66 ( V_182 ) ;
F_37 ( V_37 , V_186 , & V_183 ) ;
V_183 |= V_187 ;
F_67 ( & V_183 , 3 ) ;
F_68 ( & V_183 , 0 ) ;
F_29 ( V_37 , V_186 , V_183 ) ;
F_37 ( V_37 , V_188 , & V_183 ) ;
F_69 ( & V_183 , V_180 ) ;
F_70 ( & V_183 , V_184 ) ;
F_71 ( & V_183 , V_185 ) ;
F_29 ( V_37 , V_188 , V_183 ) ;
}
static void F_72 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_41 ( V_37 , V_113 , & V_35 ) ;
F_35 ( V_37 , V_113 , V_35 | V_189 ) ;
}
static void F_73 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_41 ( V_37 , V_113 , & V_35 ) ;
F_35 ( V_37 , V_113 , V_35 | V_190 ) ;
}
static void F_74 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_41 ( V_37 , V_113 , & V_35 ) ;
F_35 ( V_37 , V_113 , V_35 & ~ V_189 ) ;
}
static void F_75 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_41 ( V_37 , V_113 , & V_35 ) ;
F_35 ( V_37 , V_113 , V_35 & ~ V_190 ) ;
}
bool F_76 ( struct V_36 * V_191 )
{
if ( ! F_11 ( V_191 -> V_39 + V_192 ) )
return false ;
if ( F_11 ( V_191 -> V_39 + V_193 ) )
return false ;
return true ;
}
static int F_77 ( struct V_36 * V_37 )
{
struct V_115 * V_116 = & V_37 -> V_117 -> V_116 ;
if ( ! F_76 ( V_37 ) )
return - V_112 ;
if ( V_37 -> V_155 ) {
F_64 ( V_37 ) ;
return 0 ;
}
if ( V_116 -> V_118 ) {
F_78 ( V_37 -> V_119 ) ;
F_34 ( 5 ) ;
F_79 ( V_37 -> V_119 ) ;
F_34 ( 5 ) ;
F_78 ( V_37 -> V_119 ) ;
F_34 ( 5 ) ;
} else {
#ifdef F_49
if ( F_80 ( F_51 ( & V_37 -> V_117 -> V_116 ) , L_7 ) ) {
F_50 ( F_51 ( & V_37 -> V_117 -> V_116 ) ,
L_7 , NULL , NULL ) ;
} else if ( F_80 ( F_51 ( & V_37 -> V_117 -> V_116 ) ,
L_8 ) ) {
F_50 ( F_51 ( & V_37 -> V_117 -> V_116 ) ,
L_8 , NULL , NULL ) ;
}
#endif
}
F_43 ( V_37 ) ;
F_64 ( V_37 ) ;
return 0 ;
}
static void F_81 ( struct V_36 * V_37 ,
struct V_1 * V_2 )
{
T_1 V_5 , V_35 ;
if ( F_5 ( V_2 -> V_21 ) ) {
V_5 = V_194 ;
V_35 = F_22 ( F_66 ( V_2 -> V_21 ) ) ;
} else {
V_5 = V_195 ;
V_35 = F_22 ( F_23 ( V_2 -> V_21 ) ) ;
}
F_30 ( V_37 , V_5 , V_35 ) ;
}
static void F_82 ( struct V_36 * V_37 )
{
struct V_115 * V_116 = & V_37 -> V_117 -> V_116 ;
struct V_1 * V_2 ;
T_1 V_196 ;
int V_40 ;
V_196 = 0 ;
for ( V_40 = 0 ; V_40 < V_37 -> V_197 ; V_40 ++ ) {
V_2 = V_37 -> V_198 [ V_40 ] -> V_199 ;
V_196 |= F_22 ( F_66 ( V_2 -> V_21 ) ) ;
V_2 = V_37 -> V_198 [ V_40 ] -> V_200 ;
if ( V_2 )
V_196 |= F_22 ( F_66 ( V_2 -> V_21 ) ) ;
}
F_30 ( V_37 , V_194 , V_196 ) ;
V_196 = 0 ;
for ( V_40 = 0 ; V_40 < V_37 -> V_201 ; V_40 ++ ) {
V_2 = V_37 -> V_202 [ V_40 ] ;
V_196 |= F_22 ( F_23 ( V_2 -> V_21 ) ) ;
}
F_30 ( V_37 , V_195 , V_196 ) ;
if ( V_116 -> V_118 ) {
if ( ! F_83 ( V_37 -> V_119 ) )
F_79 ( V_37 -> V_119 ) ;
}
}
static T_1 F_84 ( struct V_109 * V_38 )
{
struct V_36 * V_37 = F_8 ( V_38 ) ;
struct V_203 * V_204 = V_38 -> V_204 ;
T_5 V_205 , V_206 = 0 ;
T_1 V_167 , V_166 ;
T_4 V_207 = 0 ;
if ( ! V_204 -> V_208 || ! V_37 -> V_209 )
return 0 ;
if ( V_37 -> V_166 )
V_207 |= V_210 ;
if ( V_37 -> V_167 )
V_207 |= V_211 ;
V_205 = F_85 ( V_207 ) ;
if ( V_204 -> V_212 )
V_206 = V_213 ;
if ( V_204 -> V_214 )
V_206 |= V_215 ;
V_207 = F_86 ( V_205 , V_206 ) ;
V_166 = ! ! ( V_207 & V_210 ) ;
V_167 = ! ! ( V_207 & V_211 ) ;
if ( V_166 != V_37 -> V_166 ) {
V_37 -> V_166 = V_166 ;
V_37 -> V_152 -> V_216 ( V_37 , V_37 -> V_166 ) ;
}
if ( V_167 != V_37 -> V_167 ) {
V_37 -> V_167 = V_167 ;
V_37 -> V_152 -> V_217 ( V_37 , V_37 -> V_167 ) ;
}
return 0 ;
}
static void F_87 ( struct V_109 * V_38 )
{
struct V_36 * V_37 = F_8 ( V_38 ) ;
const struct V_218 * V_152 = V_37 -> V_152 ;
struct V_203 * V_204 = V_38 -> V_204 ;
if ( V_204 -> V_219 ) {
if ( V_37 -> V_121 != V_204 -> V_220 ) {
V_37 -> V_121 = V_204 -> V_220 ;
V_152 -> V_221 ( V_37 ) ;
V_152 -> V_222 ( V_37 ) ;
V_152 -> V_223 ( V_37 ) ;
F_88 ( V_204 ) ;
}
F_84 ( V_38 ) ;
} else {
V_152 -> V_224 ( V_37 ) ;
V_152 -> V_225 ( V_37 ) ;
V_37 -> V_121 = V_226 ;
F_88 ( V_204 ) ;
}
}
static struct V_227 * F_89 ( struct V_115 * V_116 )
{
struct V_228 args ;
struct V_229 * V_230 ;
int V_69 ;
V_230 = F_90 ( F_91 ( V_116 ) ) ;
V_69 = F_92 ( V_230 , L_9 , 0 ,
& args ) ;
if ( F_93 ( V_69 ) ) {
F_94 ( V_116 , L_10 ) ;
return NULL ;
}
return args . V_231 ;
}
int F_95 ( struct V_109 * V_38 )
{
struct V_36 * V_37 = F_8 ( V_38 ) ;
struct V_232 * V_233 ;
struct V_203 * V_234 ;
struct V_115 * V_116 = & V_37 -> V_117 -> V_116 ;
int V_40 ;
if ( V_116 -> V_118 ) {
for ( V_40 = 0 ; V_40 < 2 ; V_40 ++ ) {
V_233 = F_96 ( V_116 -> V_118 , L_9 , V_40 ) ;
V_234 = F_97 ( V_38 , V_233 ,
& F_87 ,
0 , V_37 -> V_235 ) ;
F_98 ( V_233 ) ;
if ( V_234 )
break;
}
if ( ! V_234 ) {
F_36 ( V_38 , L_11 ) ;
return - V_112 ;
}
} else {
#ifdef F_49
struct V_227 * V_231 = F_89 ( V_116 ) ;
if ( V_231 )
V_234 = V_231 -> V_236 ;
else
V_234 = NULL ;
if ( ! V_234 ||
F_99 ( V_38 , V_234 , & F_87 ,
V_37 -> V_235 ) ) {
F_36 ( V_38 , L_11 ) ;
return - V_112 ;
}
#else
return - V_112 ;
#endif
}
V_37 -> V_121 = V_226 ;
V_234 -> V_237 &= ~ V_238 &
~ V_239 &
~ V_240 ;
V_234 -> V_237 |= V_241 |
V_242 ;
V_234 -> V_243 = V_234 -> V_237 ;
return 0 ;
}
static int F_100 ( struct V_36 * V_37 ,
struct V_244 * V_245 )
{
struct V_115 * V_116 = & V_37 -> V_117 -> V_116 ;
struct V_109 * V_38 = V_37 -> V_38 ;
struct V_203 * V_246 ;
struct V_232 * V_247 ;
struct V_232 * V_248 = NULL ;
T_1 V_249 ;
int V_250 ;
if ( V_116 -> V_118 ) {
F_101 (dev->of_node, child_np) {
if ( F_102 ( V_247 ,
L_12 ) ) {
V_248 = V_247 ;
break;
}
}
if ( ! V_248 ) {
F_103 ( V_38 , L_13 ) ;
return - V_251 ;
}
return F_104 ( V_245 , V_248 ) ;
}
V_245 -> V_252 = ~ 0 ;
V_250 = F_105 ( V_245 ) ;
if ( V_250 )
return V_250 ;
V_250 = F_106 ( V_116 , L_14 , & V_249 ) ;
if ( V_250 )
V_250 = F_106 ( V_116 , L_15 , & V_249 ) ;
if ( V_250 )
return - V_253 ;
V_246 = F_107 ( V_245 , V_249 ) ;
if ( ! V_246 )
return - V_254 ;
return V_250 ;
}
int F_108 ( struct V_36 * V_37 )
{
struct V_109 * V_38 = V_37 -> V_38 ;
struct V_244 * V_255 ;
int V_250 ;
V_255 = F_109 () ;
if ( ! V_255 )
return - V_256 ;
V_255 -> V_257 = L_16 ;
V_255 -> V_258 = V_259 ;
V_255 -> V_260 = V_261 ;
snprintf ( V_255 -> V_21 , V_262 , L_17 , L_18 ,
V_38 -> V_257 ) ;
V_255 -> V_263 = ( void V_264 * ) V_37 -> V_94 ;
V_255 -> V_120 = & V_37 -> V_117 -> V_116 ;
V_250 = F_100 ( V_37 , V_255 ) ;
if ( V_250 ) {
F_36 ( V_38 , L_19 ) ;
F_110 ( V_255 ) ;
return V_250 ;
}
V_37 -> V_255 = V_255 ;
V_250 = F_95 ( V_38 ) ;
if ( V_250 )
F_111 ( V_37 ) ;
return V_250 ;
}
void F_112 ( struct V_36 * V_37 )
{
struct V_109 * V_38 = V_37 -> V_38 ;
if ( V_38 -> V_204 )
F_113 ( V_38 -> V_204 ) ;
}
void F_111 ( struct V_36 * V_37 )
{
struct V_109 * V_38 = V_37 -> V_38 ;
if ( V_38 -> V_204 )
F_113 ( V_38 -> V_204 ) ;
F_114 ( V_37 -> V_255 ) ;
F_110 ( V_37 -> V_255 ) ;
V_37 -> V_255 = NULL ;
}
