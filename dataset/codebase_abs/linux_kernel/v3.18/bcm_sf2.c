static void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 * V_4 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
memcpy ( V_4 + V_5 * V_7 ,
V_8 [ V_5 ] . string , V_7 ) ;
}
static void F_2 ( struct V_1 * V_2 ,
int V_3 , T_2 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
const struct V_11 * V_12 ;
unsigned int V_5 ;
T_3 V_13 = 0 ;
T_4 V_14 ;
F_4 ( & V_10 -> V_15 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_12 = & V_8 [ V_5 ] ;
V_14 = V_12 -> V_16 + F_5 ( V_3 ) ;
if ( V_12 -> V_17 == 8 )
V_13 = F_6 ( V_10 , V_14 ) ;
else
V_13 = F_7 ( V_10 , V_14 ) ;
V_4 [ V_5 ] = ( T_3 ) V_13 ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return V_6 ;
}
static char * F_10 ( struct V_18 * V_19 , int V_20 )
{
return L_1 ;
}
static void F_11 ( struct V_1 * V_2 , int V_21 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_5 ;
T_4 V_16 ;
for ( V_5 = 0 ; V_5 < V_10 -> V_22 . V_23 ; V_5 ++ ) {
if ( ! ( ( 1 << V_5 ) & V_2 -> V_24 ) )
continue;
V_16 = F_7 ( V_10 , F_12 ( V_5 ) ) ;
V_16 |= ( 1 << V_21 ) ;
F_13 ( V_10 , V_16 , F_12 ( V_5 ) ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 , V_13 ;
V_16 = F_7 ( V_10 , V_25 ) ;
V_16 &= ~ F_15 ( V_3 ) ;
F_13 ( V_10 , V_16 , V_25 ) ;
V_16 = F_7 ( V_10 , V_26 ) ;
V_16 |= ( V_27 | V_28 | V_29 ) ;
V_16 &= ~ ( V_30 | V_31 ) ;
F_13 ( V_10 , V_16 , V_26 ) ;
F_13 ( V_10 , V_32 , V_33 ) ;
V_16 = F_7 ( V_10 , V_34 ) ;
V_16 |= V_35 ;
F_13 ( V_10 , V_16 , V_34 ) ;
switch ( V_3 ) {
case 8 :
V_13 = V_36 ;
break;
case 7 :
V_13 = V_37 ;
break;
case 5 :
V_13 = V_38 ;
break;
default:
V_13 = 0 ;
break;
}
V_16 = F_7 ( V_10 , V_39 ) ;
V_16 |= V_13 ;
F_13 ( V_10 , V_16 , V_39 ) ;
V_16 = F_7 ( V_10 , V_40 ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , V_40 ) ;
V_16 = F_7 ( V_10 , V_41 ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , V_41 ) ;
V_16 = F_7 ( V_10 , V_42 ) ;
V_16 |= ( V_43 | V_44 ) ;
F_13 ( V_10 , V_16 , V_42 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_3 , bool V_45 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_46 ) ;
if ( V_45 )
V_16 |= 1 << V_3 ;
else
V_16 &= ~ ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , V_46 ) ;
}
static int F_17 ( struct V_1 * V_2 , int V_3 ,
struct V_47 * V_48 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_21 = V_2 -> V_49 [ V_2 -> V_50 ] . V_21 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_25 ) ;
V_16 &= ~ F_15 ( V_3 ) ;
F_13 ( V_10 , V_16 , V_25 ) ;
F_13 ( V_10 , 0 , F_18 ( V_3 ) ) ;
if ( V_3 == 7 )
F_19 ( V_10 , F_20 ( V_51 ) ) ;
V_16 = F_7 ( V_10 , F_12 ( V_3 ) ) ;
V_16 &= ~ V_52 ;
V_16 |= ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , F_12 ( V_3 ) ) ;
F_11 ( V_2 , V_21 ) ;
if ( V_10 -> V_53 [ V_3 ] . V_54 . V_55 )
F_16 ( V_2 , V_3 , true ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , int V_3 ,
struct V_47 * V_48 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_56 , V_16 ;
if ( V_10 -> V_57 & ( 1 << V_3 ) )
return;
if ( V_3 == 7 ) {
F_22 ( V_10 , F_20 ( V_51 ) ) ;
F_23 ( V_10 , F_20 ( V_51 ) , V_58 ) ;
}
if ( F_24 ( V_2 , V_3 ) )
V_56 = V_26 ;
else
V_56 = F_18 ( V_3 ) ;
V_16 = F_7 ( V_10 , V_56 ) ;
V_16 |= V_30 | V_31 ;
F_13 ( V_10 , V_16 , V_56 ) ;
V_16 = F_7 ( V_10 , V_25 ) ;
V_16 |= F_15 ( V_3 ) ;
F_13 ( V_10 , V_16 , V_25 ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_3 ,
struct V_47 * V_48 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_59 * V_60 = & V_10 -> V_53 [ V_3 ] . V_54 ;
int V_61 ;
V_60 -> V_62 = ( V_63 | V_64 ) ;
V_61 = F_26 ( V_48 , 0 ) ;
if ( V_61 )
return 0 ;
F_16 ( V_2 , V_3 , true ) ;
return 1 ;
}
static int F_27 ( struct V_1 * V_2 , int V_3 ,
struct V_59 * V_65 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_59 * V_60 = & V_10 -> V_53 [ V_3 ] . V_54 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_66 ) ;
V_65 -> V_55 = V_60 -> V_55 ;
V_65 -> V_67 = ! ! ( V_16 & ( 1 << V_3 ) ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , int V_3 ,
struct V_47 * V_68 ,
struct V_59 * V_65 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_59 * V_60 = & V_10 -> V_53 [ V_3 ] . V_54 ;
V_60 -> V_55 = V_65 -> V_55 ;
if ( ! V_60 -> V_55 ) {
F_16 ( V_2 , V_3 , false ) ;
} else {
V_60 -> V_55 = F_25 ( V_2 , V_3 , V_68 ) ;
if ( ! V_60 -> V_55 )
return - V_69 ;
}
return 0 ;
}
static T_6 F_29 ( int V_70 , void * V_71 )
{
struct V_9 * V_10 = V_71 ;
V_10 -> V_72 = F_30 ( V_10 , V_73 ) &
~ V_10 -> V_74 ;
F_31 ( V_10 , V_10 -> V_72 , V_58 ) ;
return V_75 ;
}
static T_6 F_32 ( int V_70 , void * V_71 )
{
struct V_9 * V_10 = V_71 ;
V_10 -> V_76 = F_33 ( V_10 , V_73 ) &
~ V_10 -> V_77 ;
F_23 ( V_10 , V_10 -> V_76 , V_58 ) ;
if ( V_10 -> V_76 & F_34 ( V_51 ) )
V_10 -> V_53 [ 7 ] . V_78 = 1 ;
if ( V_10 -> V_76 & F_35 ( V_51 ) )
V_10 -> V_53 [ 7 ] . V_78 = 0 ;
return V_75 ;
}
static int F_36 ( struct V_9 * V_10 )
{
unsigned int V_79 = 1000 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_80 ) ;
V_16 |= V_81 | V_82 | V_83 ;
F_13 ( V_10 , V_16 , V_80 ) ;
do {
V_16 = F_7 ( V_10 , V_80 ) ;
if ( ! ( V_16 & V_81 ) )
break;
F_37 ( 1000 , 2000 ) ;
} while ( V_79 -- > 0 );
if ( V_79 == 0 )
return - V_84 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
const char * V_85 [ V_86 ] = V_87 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_88 * V_89 ;
void T_7 * * V_90 ;
unsigned int V_3 ;
unsigned int V_5 ;
T_4 V_16 , V_91 ;
int V_61 ;
F_39 ( & V_10 -> V_92 ) ;
F_40 ( & V_10 -> V_15 ) ;
V_89 = V_2 -> V_93 -> V_94 -> V_95 ;
V_10 -> V_96 = F_41 ( V_89 , 0 ) ;
V_10 -> V_97 = F_41 ( V_89 , 1 ) ;
V_90 = & V_10 -> V_98 ;
for ( V_5 = 0 ; V_5 < V_86 ; V_5 ++ ) {
* V_90 = F_42 ( V_89 , V_5 ) ;
if ( * V_90 == NULL ) {
F_43 ( L_2 , V_85 [ V_5 ] ) ;
V_61 = - V_99 ;
goto V_100;
}
V_90 ++ ;
}
V_61 = F_36 ( V_10 ) ;
if ( V_61 ) {
F_43 ( L_3 , V_61 ) ;
goto V_100;
}
F_31 ( V_10 , 0xffffffff , V_101 ) ;
F_31 ( V_10 , 0xffffffff , V_58 ) ;
F_31 ( V_10 , 0 , V_102 ) ;
F_23 ( V_10 , 0xffffffff , V_101 ) ;
F_23 ( V_10 , 0xffffffff , V_58 ) ;
F_23 ( V_10 , 0 , V_102 ) ;
V_61 = F_44 ( V_10 -> V_96 , F_29 , 0 ,
L_4 , V_10 ) ;
if ( V_61 < 0 ) {
F_43 ( L_5 ) ;
goto V_100;
}
V_61 = F_44 ( V_10 -> V_97 , F_32 , 0 ,
L_6 , V_10 ) ;
if ( V_61 < 0 ) {
F_43 ( L_7 ) ;
goto V_103;
}
V_16 = F_7 ( V_10 , V_104 ) ;
V_16 |= V_105 ;
F_13 ( V_10 , V_16 , V_104 ) ;
V_16 &= ~ V_105 ;
F_13 ( V_10 , V_16 , V_104 ) ;
V_10 -> V_22 . V_23 = F_7 ( V_10 , V_106 ) + 1 ;
if ( V_10 -> V_22 . V_23 > V_107 )
V_10 -> V_22 . V_23 = V_107 ;
if ( F_45 ( V_89 , L_8 ,
& V_10 -> V_22 . V_108 ) )
V_10 -> V_22 . V_108 = 1 ;
for ( V_3 = 0 ; V_3 < V_10 -> V_22 . V_23 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 )
F_17 ( V_2 , V_3 , NULL ) ;
else if ( F_24 ( V_2 , V_3 ) )
F_14 ( V_2 , V_3 ) ;
else
F_21 ( V_2 , V_3 , NULL ) ;
}
V_2 -> V_109 |= ( ( 1 << 30 ) | ( 1 << 0 ) ) ;
V_91 = F_46 ( V_10 , V_110 ) ;
V_10 -> V_22 . V_111 = ( V_91 >> V_112 ) &
V_113 ;
V_10 -> V_22 . V_114 = ( V_91 & V_115 ) ;
V_91 = F_46 ( V_10 , V_116 ) ;
V_10 -> V_22 . V_117 = V_91 & V_118 ;
F_47 ( L_9 ,
V_10 -> V_22 . V_111 >> 8 , V_10 -> V_22 . V_111 & 0xff ,
V_10 -> V_22 . V_114 >> 8 , V_10 -> V_22 . V_114 & 0xff ,
V_10 -> V_98 , V_10 -> V_96 , V_10 -> V_97 ) ;
return 0 ;
V_103:
F_48 ( V_10 -> V_96 , V_10 ) ;
V_100:
V_90 = & V_10 -> V_98 ;
for ( V_5 = 0 ; V_5 < V_86 ; V_5 ++ ) {
if ( * V_90 )
F_49 ( * V_90 ) ;
V_90 ++ ;
}
return V_61 ;
}
static int F_50 ( struct V_1 * V_2 , T_8 * V_119 )
{
return 0 ;
}
static T_4 F_51 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
return V_10 -> V_22 . V_117 ;
}
static int F_52 ( struct V_1 * V_2 , int V_120 , int V_119 ,
int V_121 , T_9 V_13 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_61 = 0 ;
T_4 V_16 ;
V_16 = F_46 ( V_10 , V_122 ) ;
V_16 |= V_123 ;
F_53 ( V_10 , V_16 , V_122 ) ;
V_16 = 0x70 ;
V_16 <<= 2 ;
F_13 ( V_10 , V_119 , V_16 ) ;
V_16 = 0x80 << 8 | V_121 << 1 ;
V_16 <<= 2 ;
if ( V_120 )
V_61 = F_7 ( V_10 , V_16 ) ;
else
F_13 ( V_10 , V_13 , V_16 ) ;
V_16 = F_46 ( V_10 , V_122 ) ;
V_16 &= ~ V_123 ;
F_53 ( V_10 , V_16 , V_122 ) ;
return V_61 & 0xffff ;
}
static int F_54 ( struct V_1 * V_2 , int V_119 , int V_121 )
{
switch ( V_119 ) {
case 0 :
case 30 :
return F_52 ( V_2 , 1 , V_119 , V_121 , 0 ) ;
default:
return 0xffff ;
}
}
static int F_55 ( struct V_1 * V_2 , int V_119 , int V_121 ,
T_9 V_13 )
{
switch ( V_119 ) {
case 0 :
case 30 :
F_52 ( V_2 , 0 , V_119 , V_121 , V_13 ) ;
break;
}
return 0 ;
}
static void F_56 ( struct V_1 * V_2 , int V_3 ,
struct V_47 * V_68 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_124 = 0 , V_125 ;
const char * V_126 = NULL ;
T_4 V_16 ;
switch ( V_68 -> V_127 ) {
case V_128 :
V_126 = L_10 ;
V_124 = 1 ;
case V_129 :
if ( ! V_126 )
V_126 = L_11 ;
V_125 = V_130 ;
break;
case V_131 :
V_126 = L_12 ;
V_125 = V_132 ;
break;
case V_133 :
V_126 = L_13 ;
V_125 = V_134 ;
break;
default:
goto V_135;
}
if ( ! V_68 -> V_78 ) {
V_16 = F_46 ( V_10 , F_57 ( V_3 ) ) ;
V_16 &= ~ V_136 ;
F_53 ( V_10 , V_16 , F_57 ( V_3 ) ) ;
goto V_135;
}
V_16 = F_46 ( V_10 , F_57 ( V_3 ) ) ;
V_16 &= ~ V_137 ;
V_16 &= ~ ( V_138 << V_139 ) ;
V_16 &= ~ ( V_140 | V_141 ) ;
V_16 |= V_125 | V_136 ;
if ( V_124 )
V_16 |= V_137 ;
if ( V_68 -> V_142 ) {
if ( V_68 -> V_143 )
V_16 |= V_141 ;
V_16 |= V_140 ;
}
F_53 ( V_10 , V_16 , F_57 ( V_3 ) ) ;
F_47 ( L_14 , V_3 , V_126 ) ;
V_135:
V_16 = V_144 ;
switch ( V_68 -> V_145 ) {
case V_146 :
V_16 |= V_147 << V_148 ;
break;
case V_149 :
V_16 |= V_150 << V_148 ;
break;
}
if ( V_68 -> V_78 )
V_16 |= V_44 ;
if ( V_68 -> V_151 == V_152 )
V_16 |= V_153 ;
F_13 ( V_10 , V_16 , F_58 ( V_3 ) ) ;
}
static void F_59 ( struct V_1 * V_2 , int V_3 ,
struct V_154 * V_155 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_78 , V_151 , V_142 , V_145 ;
T_4 V_16 ;
V_78 = F_7 ( V_10 , V_156 ) ;
V_151 = F_7 ( V_10 , V_157 ) ;
V_142 = F_7 ( V_10 , V_158 ) ;
V_145 = F_7 ( V_10 , V_159 ) ;
V_145 >>= ( V_3 * V_160 ) ;
V_145 &= V_161 ;
V_155 -> V_78 = 0 ;
if ( V_3 == 7 ) {
V_155 -> V_78 = V_10 -> V_53 [ V_3 ] . V_78 ;
V_16 = F_7 ( V_10 , F_58 ( 7 ) ) ;
V_16 |= V_144 ;
if ( V_155 -> V_78 )
V_16 |= V_44 ;
else
V_16 &= ~ V_44 ;
F_13 ( V_10 , V_16 , F_58 ( 7 ) ) ;
V_155 -> V_151 = 1 ;
} else {
V_155 -> V_78 = ! ! ( V_78 & ( 1 << V_3 ) ) ;
V_155 -> V_151 = ! ! ( V_151 & ( 1 << V_3 ) ) ;
}
switch ( V_145 ) {
case V_162 :
V_155 -> V_145 = V_163 ;
break;
case V_150 :
V_155 -> V_145 = V_149 ;
break;
case V_147 :
V_155 -> V_145 = V_146 ;
break;
}
if ( ( V_142 & ( 1 << V_3 ) ) &&
( V_142 & ( 1 << ( V_3 + V_164 ) ) ) ) {
V_155 -> V_143 = 1 ;
V_155 -> V_142 = 1 ;
}
if ( V_142 & ( 1 << V_3 ) )
V_155 -> V_142 = 1 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
F_31 ( V_10 , 0xffffffff , V_101 ) ;
F_31 ( V_10 , 0xffffffff , V_58 ) ;
F_31 ( V_10 , 0 , V_102 ) ;
F_23 ( V_10 , 0xffffffff , V_101 ) ;
F_23 ( V_10 , 0xffffffff , V_58 ) ;
F_23 ( V_10 , 0 , V_102 ) ;
for ( V_3 = 0 ; V_3 < V_107 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 ||
F_24 ( V_2 , V_3 ) )
F_21 ( V_2 , V_3 , NULL ) ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
T_4 V_16 ;
int V_61 ;
V_61 = F_36 ( V_10 ) ;
if ( V_61 ) {
F_43 ( L_15 , V_165 ) ;
return V_61 ;
}
if ( V_10 -> V_22 . V_108 == 1 ) {
V_16 = F_46 ( V_10 , V_166 ) ;
V_16 |= V_167 ;
V_16 &= ~ ( V_168 | V_169 ) ;
F_53 ( V_10 , V_16 , V_166 ) ;
F_62 ( 21 ) ;
V_16 = F_46 ( V_10 , V_166 ) ;
V_16 &= ~ V_167 ;
F_53 ( V_10 , V_16 , V_166 ) ;
}
for ( V_3 = 0 ; V_3 < V_107 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 )
F_17 ( V_2 , V_3 , NULL ) ;
else if ( F_24 ( V_2 , V_3 ) )
F_14 ( V_2 , V_3 ) ;
}
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , int V_3 ,
struct V_170 * V_171 )
{
struct V_172 * V_60 = V_2 -> V_49 [ V_2 -> V_50 ] . V_173 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_170 V_174 ;
V_60 -> V_175 -> V_176 ( V_60 , & V_174 ) ;
V_171 -> V_62 = V_174 . V_62 ;
memset ( & V_171 -> V_177 , 0 , sizeof( V_171 -> V_177 ) ) ;
if ( V_174 . V_178 & V_179 )
memcpy ( & V_171 -> V_177 , V_174 . V_177 , sizeof( V_171 -> V_177 ) ) ;
if ( V_10 -> V_57 & ( 1 << V_3 ) )
V_171 -> V_178 = V_174 . V_178 ;
else
V_171 -> V_178 = 0 ;
}
static int F_64 ( struct V_1 * V_2 , int V_3 ,
struct V_170 * V_171 )
{
struct V_172 * V_60 = V_2 -> V_49 [ V_2 -> V_50 ] . V_173 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_21 = V_2 -> V_49 [ V_2 -> V_50 ] . V_21 ;
struct V_170 V_174 ;
V_60 -> V_175 -> V_176 ( V_60 , & V_174 ) ;
if ( V_171 -> V_178 & ~ V_174 . V_62 )
return - V_180 ;
if ( V_171 -> V_178 )
V_10 -> V_57 |= ( 1 << V_3 ) ;
else
V_10 -> V_57 &= ~ ( 1 << V_3 ) ;
if ( V_10 -> V_57 && V_10 -> V_57 != ( 1 << V_21 ) )
V_10 -> V_57 |= ( 1 << V_21 ) ;
else
V_10 -> V_57 &= ~ ( 1 << V_21 ) ;
return V_60 -> V_175 -> V_181 ( V_60 , V_171 ) ;
}
static int T_10 F_65 ( void )
{
F_66 ( & V_182 ) ;
return 0 ;
}
static void T_11 F_67 ( void )
{
F_68 ( & V_182 ) ;
}
