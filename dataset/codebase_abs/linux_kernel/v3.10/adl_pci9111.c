static void F_1 ( unsigned long V_1 ,
bool V_2 ,
bool V_3 ,
bool V_4 ,
bool V_5 ,
bool V_6 )
{
int V_7 = 0 ;
if ( V_2 )
V_7 |= V_8 ;
if ( V_3 )
V_7 |= V_9 ;
if ( V_4 )
V_7 |= V_10 ;
if ( V_5 )
V_7 |= V_11 ;
if ( V_6 )
V_7 |= V_12 ;
F_2 ( V_7 , V_1 + V_13 ) ;
}
static void F_3 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
unsigned long V_19 = V_15 -> V_20 + V_21 ;
F_4 ( V_19 , 1 , 0 , V_22 | V_23 ) ;
F_4 ( V_19 , 1 , 1 , V_24 | V_23 ) ;
F_4 ( V_19 , 1 , 2 , V_24 | V_23 ) ;
F_5 ( 1 ) ;
F_6 ( V_19 , 1 , 2 , V_17 -> V_25 ) ;
F_6 ( V_19 , 1 , 1 , V_17 -> V_26 ) ;
}
static void F_7 ( struct V_14 * V_15 ,
enum V_27 V_28 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 &= 0x9 ;
switch ( V_28 ) {
case V_30 :
break;
case V_31 :
V_7 |= V_32 ;
break;
case V_33 :
V_7 |= V_34 ;
break;
}
F_2 ( V_7 , V_15 -> V_20 + V_29 ) ;
}
static void F_9 ( struct V_14 * V_15 , bool V_35 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 &= 0x7 ;
if ( V_35 )
V_7 |= V_36 ;
F_2 ( V_7 , V_15 -> V_20 + V_29 ) ;
}
static void F_10 ( struct V_14 * V_15 , bool V_37 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 &= 0xe ;
if ( V_37 )
V_7 |= V_38 ;
F_2 ( V_7 , V_15 -> V_20 + V_29 ) ;
}
static void F_11 ( struct V_14 * V_15 ,
enum V_39 V_40 ,
enum V_41 V_42 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 >>= 4 ;
V_7 &= 0xc0 ;
if ( V_40 == V_43 )
V_7 |= V_44 ;
if ( V_42 == V_45 )
V_7 |= V_46 ;
F_2 ( V_7 , V_15 -> V_20 + V_47 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
unsigned long V_48 = V_15 -> V_20 + V_47 ;
F_2 ( 0 , V_48 ) ;
F_2 ( V_49 , V_48 ) ;
F_2 ( 0 , V_48 ) ;
}
static int F_13 ( struct V_14 * V_15 ,
struct V_50 * V_51 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_1 ( V_17 -> V_52 , true , true , true ,
true , false ) ;
F_7 ( V_15 , V_30 ) ;
F_10 ( V_15 , false ) ;
F_12 ( V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_53 * V_54 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
int V_55 ;
int error = 0 ;
int V_56 , V_57 ;
int V_58 ;
error |= F_15 ( & V_54 -> V_59 , V_60 ) ;
error |= F_15 ( & V_54 -> V_61 ,
V_62 | V_63 | V_64 ) ;
error |= F_15 ( & V_54 -> V_65 ,
V_62 | V_64 ) ;
error |= F_15 ( & V_54 -> V_66 , V_67 ) ;
error |= F_15 ( & V_54 -> V_68 ,
V_67 | V_69 ) ;
if ( error )
return 1 ;
error |= F_16 ( V_54 -> V_61 ) ;
error |= F_16 ( V_54 -> V_65 ) ;
error |= F_16 ( V_54 -> V_68 ) ;
if ( ( V_54 -> V_65 == V_62 ) &&
! ( ( V_54 -> V_61 == V_62 ) ||
( V_54 -> V_61 == V_63 ) ) )
error |= - V_70 ;
if ( ( V_54 -> V_65 == V_64 ) &&
! ( ( V_54 -> V_61 == V_64 ) ||
( V_54 -> V_61 == V_63 ) ) )
error |= - V_70 ;
if ( error )
return 2 ;
error |= F_17 ( & V_54 -> V_71 , 0 ) ;
if ( V_54 -> V_65 == V_62 )
error |= F_18 ( & V_54 -> V_72 ,
V_73 ) ;
else
error |= F_17 ( & V_54 -> V_72 , 0 ) ;
if ( V_54 -> V_61 == V_62 )
error |= F_18 ( & V_54 -> V_74 ,
V_73 ) ;
else
error |= F_17 ( & V_54 -> V_74 , 0 ) ;
error |= F_17 ( & V_54 -> V_75 ,
V_54 -> V_76 ) ;
if ( V_54 -> V_68 == V_67 )
error |= F_18 ( & V_54 -> V_77 , 1 ) ;
else
error |= F_17 ( & V_54 -> V_77 , 0 ) ;
if ( error )
return 3 ;
if ( V_54 -> V_65 == V_62 ) {
V_55 = V_54 -> V_72 ;
F_19 ( V_78 ,
& V_17 -> V_26 ,
& V_17 -> V_25 ,
& V_54 -> V_72 ,
V_54 -> V_7 & V_79 ) ;
if ( V_55 != V_54 -> V_72 )
error ++ ;
}
if ( V_54 -> V_61 == V_62 ) {
unsigned int V_80 ;
unsigned int V_74 ;
unsigned int V_81 ;
V_80 = V_54 -> V_76 * V_54 -> V_72 ;
if ( V_54 -> V_74 != V_80 ) {
if ( V_80 < V_54 -> V_74 ) {
V_81 =
V_54 -> V_74 / V_80 ;
V_74 = V_81 * V_80 ;
if ( V_54 -> V_74 != V_74 ) {
V_54 -> V_74 = V_74 ;
error ++ ;
}
} else {
V_54 -> V_74 = V_80 ;
error ++ ;
}
}
}
if ( error )
return 4 ;
if ( V_54 -> V_82 ) {
V_56 = F_20 ( V_54 -> V_82 [ 0 ] ) ;
V_57 = F_21 ( V_54 -> V_82 [ 0 ] ) ;
if ( V_54 -> V_76 > 1 ) {
for ( V_58 = 0 ; V_58 < V_54 -> V_76 ; V_58 ++ ) {
if ( F_22 ( V_54 -> V_82 [ V_58 ] ) != V_58 ) {
F_23 ( V_15 ,
L_1
L_2 ) ;
error ++ ;
}
if ( F_20 ( V_54 -> V_82 [ V_58 ] ) != V_56 ) {
F_23 ( V_15 ,
L_3 ) ;
error ++ ;
}
if ( F_21 ( V_54 -> V_82 [ V_58 ] ) != V_57 ) {
F_23 ( V_15 ,
L_4 ) ;
error ++ ;
}
}
}
}
if ( error )
return 5 ;
return 0 ;
}
static int F_24 ( struct V_14 * V_15 ,
struct V_50 * V_51 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_53 * V_83 = & V_51 -> V_84 -> V_54 ;
if ( ! V_15 -> V_85 ) {
F_23 ( V_15 ,
L_5 ) ;
return - 1 ;
}
if ( V_83 -> V_76 > 1 ) {
F_2 ( V_83 -> V_76 - 1 ,
V_15 -> V_20 + V_86 ) ;
F_10 ( V_15 , true ) ;
} else {
F_2 ( F_22 ( V_83 -> V_82 [ 0 ] ) ,
V_15 -> V_20 + V_86 ) ;
F_10 ( V_15 , false ) ;
}
F_2 ( F_20 ( V_83 -> V_82 [ 0 ] ) & V_87 ,
V_15 -> V_20 + V_88 ) ;
switch ( V_83 -> V_68 ) {
case V_67 :
V_17 -> V_89 =
V_83 -> V_77 * V_83 -> V_76 ;
V_17 -> V_90 = 0 ;
break;
case V_69 :
V_17 -> V_89 = 0 ;
V_17 -> V_90 = 1 ;
break;
default:
F_23 ( V_15 , L_6 ) ;
return - 1 ;
}
V_17 -> V_91 = 0 ;
switch ( V_83 -> V_65 ) {
case V_62 :
F_7 ( V_15 , V_30 ) ;
F_3 ( V_15 ) ;
F_12 ( V_15 ) ;
F_11 ( V_15 , V_43 ,
V_92 ) ;
F_7 ( V_15 , V_31 ) ;
F_1 ( V_17 -> V_52 , true , true ,
false , true , true ) ;
if ( V_83 -> V_61 == V_62 ) {
V_17 -> V_91 =
( V_83 -> V_74 /
( V_83 -> V_72 *
V_83 -> V_76 ) ) - 1 ;
}
break;
case V_64 :
F_7 ( V_15 , V_33 ) ;
F_12 ( V_15 ) ;
F_11 ( V_15 , V_43 ,
V_92 ) ;
F_1 ( V_17 -> V_52 , true , true ,
false , true , true ) ;
break;
default:
F_23 ( V_15 , L_7 ) ;
return - 1 ;
}
V_17 -> V_89 *= ( 1 + V_17 -> V_91 ) ;
V_17 -> V_76 = V_83 -> V_76 ;
V_17 -> V_93 = 0 ;
V_17 -> V_94 =
V_17 -> V_76 * ( 1 + V_17 -> V_91 ) ;
return 0 ;
}
static void F_25 ( struct V_14 * V_15 ,
struct V_50 * V_51 , void * V_95 ,
unsigned int V_96 ,
unsigned int V_97 )
{
short * V_98 = V_95 ;
unsigned int V_99 = V_51 -> V_99 ;
unsigned int V_100 = ( V_99 + 1 ) >> 1 ;
unsigned int V_101 = ( V_99 == 0xffff ) ? 0 : 4 ;
unsigned int V_102 = V_96 / sizeof( short ) ;
unsigned int V_58 ;
for ( V_58 = 0 ; V_58 < V_102 ; V_58 ++ )
V_98 [ V_58 ] = ( ( V_98 [ V_58 ] >> V_101 ) & V_99 ) ^ V_100 ;
}
static T_1 F_26 ( int V_85 , void * V_103 )
{
struct V_14 * V_15 = V_103 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_50 * V_51 = V_15 -> V_104 ;
struct V_105 * V_84 ;
unsigned int V_106 ;
unsigned long V_107 ;
unsigned char V_108 ;
if ( ! V_15 -> V_109 ) {
return V_110 ;
}
V_84 = V_51 -> V_84 ;
F_27 ( & V_15 -> V_111 , V_107 ) ;
V_108 = F_8 ( V_17 -> V_52 + V_13 ) ;
if ( ! ( ( ( V_108 & V_12 ) != 0 ) &&
( ( ( V_108 & V_112 ) == V_112 ) ||
( ( V_108 & V_113 ) == V_113 ) ) ) ) {
F_28 ( & V_15 -> V_111 , V_107 ) ;
return V_110 ;
}
if ( ( V_108 & V_112 ) == V_112 ) {
V_106 = F_8 ( V_15 -> V_20 + V_88 ) ;
if ( ! ( V_106 & V_114 ) ) {
F_28 ( & V_15 -> V_111 , V_107 ) ;
F_23 ( V_15 , V_115 L_8 ) ;
F_2 ( 0 , V_15 -> V_20 + V_116 ) ;
F_13 ( V_15 , V_51 ) ;
V_84 -> V_117 |= V_118 | V_119 ;
F_29 ( V_15 , V_51 ) ;
return V_120 ;
}
if ( ! ( V_106 & V_121 ) ) {
unsigned int V_102 ;
unsigned int V_122 = 0 ;
V_102 =
V_123 >
V_17 -> V_89
&& ! V_17 ->
V_90 ? V_17 -> V_89 :
V_123 ;
F_30 ( V_15 -> V_20 + V_124 ,
V_17 -> V_125 , V_102 ) ;
if ( V_17 -> V_91 < 1 ) {
V_122 =
F_31 ( V_51 ,
V_17 ->
V_125 ,
V_102 *
sizeof( short ) ) ;
} else {
int V_126 = 0 ;
int V_127 ;
while ( V_126 < V_102 ) {
if ( V_17 -> V_93 <
V_17 -> V_76 ) {
V_127 =
V_17 -> V_76 -
V_17 -> V_93 ;
if ( V_127 >
V_102 - V_126 )
V_127 =
V_102 -
V_126 ;
V_122 +=
F_31
( V_51 ,
V_17 -> V_125
+ V_126 ,
V_127 * sizeof( short ) ) ;
} else {
V_127 =
V_17 -> V_94
-
V_17 -> V_93 ;
if ( V_127 >
V_102 - V_126 )
V_127 =
V_102 -
V_126 ;
V_122 +=
sizeof( short ) * V_127 ;
}
V_126 += V_127 ;
V_17 -> V_93 += V_127 ;
if ( V_17 -> V_93 >=
V_17 -> V_94 )
V_17 -> V_93 = 0 ;
}
}
V_17 -> V_89 -=
V_122 / sizeof( short ) ;
}
}
if ( ( V_17 -> V_89 == 0 ) && ( ! V_17 -> V_90 ) ) {
V_84 -> V_117 |= V_119 ;
F_13 ( V_15 , V_51 ) ;
}
F_2 ( 0 , V_15 -> V_20 + V_116 ) ;
F_28 ( & V_15 -> V_111 , V_107 ) ;
F_29 ( V_15 , V_51 ) ;
return V_120 ;
}
static int F_32 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_128 * V_129 , unsigned int * V_95 )
{
unsigned int V_130 = F_22 ( V_129 -> V_131 ) ;
unsigned int V_56 = F_20 ( V_129 -> V_131 ) ;
unsigned int V_99 = V_51 -> V_99 ;
unsigned int V_100 = ( V_99 + 1 ) >> 1 ;
unsigned int V_101 = ( V_99 == 0xffff ) ? 0 : 4 ;
unsigned int V_106 ;
int V_132 ;
int V_58 ;
F_2 ( V_130 , V_15 -> V_20 + V_86 ) ;
V_106 = F_8 ( V_15 -> V_20 + V_88 ) ;
if ( ( V_106 & V_87 ) != V_56 ) {
F_2 ( V_56 & V_87 ,
V_15 -> V_20 + V_88 ) ;
}
F_12 ( V_15 ) ;
for ( V_58 = 0 ; V_58 < V_129 -> V_133 ; V_58 ++ ) {
F_2 ( 0 , V_15 -> V_20 + V_134 ) ;
V_132 = V_135 ;
while ( V_132 -- ) {
V_106 = F_8 ( V_15 -> V_20 + V_88 ) ;
if ( V_106 & V_136 )
goto V_137;
}
F_23 ( V_15 , L_9 ) ;
V_95 [ V_58 ] = 0 ;
F_12 ( V_15 ) ;
return - V_138 ;
V_137:
V_95 [ V_58 ] = F_33 ( V_15 -> V_20 + V_124 ) ;
V_95 [ V_58 ] = ( ( V_95 [ V_58 ] >> V_101 ) & V_99 ) ^ V_100 ;
}
return V_58 ;
}
static int F_34 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_128 * V_129 ,
unsigned int * V_95 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
unsigned int V_139 = 0 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_129 -> V_133 ; V_58 ++ ) {
V_139 = V_95 [ V_58 ] ;
F_35 ( V_139 , V_15 -> V_20 + V_140 ) ;
}
V_17 -> V_141 = V_139 ;
return V_129 -> V_133 ;
}
static int F_36 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_128 * V_129 ,
unsigned int * V_95 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_129 -> V_133 ; V_58 ++ )
V_95 [ V_58 ] = V_17 -> V_141 ;
return V_129 -> V_133 ;
}
static int F_37 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_128 * V_129 ,
unsigned int * V_95 )
{
V_95 [ 1 ] = F_33 ( V_15 -> V_20 + V_142 ) ;
return V_129 -> V_133 ;
}
static int F_38 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_128 * V_129 ,
unsigned int * V_95 )
{
unsigned int V_143 = V_95 [ 0 ] ;
unsigned int V_144 = V_95 [ 1 ] ;
if ( V_143 ) {
V_51 -> V_145 &= ~ V_143 ;
V_51 -> V_145 |= ( V_144 & V_143 ) ;
F_35 ( V_51 -> V_145 , V_15 -> V_20 + V_142 ) ;
}
V_95 [ 1 ] = V_51 -> V_145 ;
return V_129 -> V_133 ;
}
static int F_39 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_1 ( V_17 -> V_52 , true , true , true ,
true , false ) ;
F_7 ( V_15 , V_30 ) ;
F_9 ( V_15 , false ) ;
F_10 ( V_15 , false ) ;
V_17 -> V_26 = 0 ;
V_17 -> V_25 = 0 ;
F_3 ( V_15 ) ;
return 0 ;
}
static int F_40 ( struct V_14 * V_15 ,
unsigned long V_146 )
{
struct V_147 * V_148 = F_41 ( V_15 ) ;
struct V_16 * V_17 ;
struct V_50 * V_51 ;
int V_149 ;
V_17 = F_42 ( sizeof( * V_17 ) , V_150 ) ;
if ( ! V_17 )
return - V_151 ;
V_15 -> V_18 = V_17 ;
V_149 = F_43 ( V_15 ) ;
if ( V_149 )
return V_149 ;
V_17 -> V_52 = F_44 ( V_148 , 1 ) ;
V_15 -> V_20 = F_44 ( V_148 , 2 ) ;
F_39 ( V_15 ) ;
if ( V_148 -> V_85 > 0 ) {
V_149 = F_45 ( V_15 -> V_85 , F_26 ,
V_152 , V_15 -> V_153 , V_15 ) ;
if ( V_149 )
return V_149 ;
V_15 -> V_85 = V_148 -> V_85 ;
}
V_149 = F_46 ( V_15 , 4 ) ;
if ( V_149 )
return V_149 ;
V_51 = & V_15 -> V_154 [ 0 ] ;
V_15 -> V_104 = V_51 ;
V_51 -> type = V_155 ;
V_51 -> V_156 = V_157 | V_158 | V_159 ;
V_51 -> V_160 = 16 ;
V_51 -> V_99 = 0xffff ;
V_51 -> V_161 = 16 ;
V_51 -> V_162 = & V_163 ;
V_51 -> V_164 = F_13 ;
V_51 -> V_165 = F_32 ;
V_51 -> V_166 = F_14 ;
V_51 -> V_167 = F_24 ;
V_51 -> V_168 = F_25 ;
V_51 = & V_15 -> V_154 [ 1 ] ;
V_51 -> type = V_169 ;
V_51 -> V_156 = V_170 | V_158 ;
V_51 -> V_160 = 1 ;
V_51 -> V_99 = 0x0fff ;
V_51 -> V_161 = 1 ;
V_51 -> V_162 = & V_171 ;
V_51 -> V_172 = F_34 ;
V_51 -> V_165 = F_36 ;
V_51 = & V_15 -> V_154 [ 2 ] ;
V_51 -> type = V_173 ;
V_51 -> V_156 = V_157 ;
V_51 -> V_160 = 16 ;
V_51 -> V_99 = 1 ;
V_51 -> V_162 = & V_174 ;
V_51 -> V_175 = F_37 ;
V_51 = & V_15 -> V_154 [ 3 ] ;
V_51 -> type = V_176 ;
V_51 -> V_156 = V_157 | V_170 ;
V_51 -> V_160 = 16 ;
V_51 -> V_99 = 1 ;
V_51 -> V_162 = & V_174 ;
V_51 -> V_175 = F_38 ;
F_47 ( V_15 -> V_177 , L_10 , V_15 -> V_153 ) ;
return 0 ;
}
static void F_48 ( struct V_14 * V_15 )
{
if ( V_15 -> V_20 )
F_39 ( V_15 ) ;
if ( V_15 -> V_85 != 0 )
F_49 ( V_15 -> V_85 , V_15 ) ;
F_50 ( V_15 ) ;
}
static int F_51 ( struct V_147 * V_15 ,
const struct V_178 * V_179 )
{
return F_52 ( V_15 , & V_180 ,
V_179 -> V_181 ) ;
}
