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
static void F_17 ( struct V_1 * V_2 , bool V_45 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 ;
V_16 = F_18 ( V_10 , V_47 ) ;
if ( V_45 ) {
V_16 |= V_48 ;
V_16 &= ~ ( V_49 | V_50 | V_51 ) ;
F_19 ( V_10 , V_16 , V_47 ) ;
F_20 ( 21 ) ;
V_16 = F_18 ( V_10 , V_47 ) ;
V_16 &= ~ V_48 ;
} else {
V_16 |= V_49 | V_50 | V_48 ;
F_19 ( V_10 , V_16 , V_47 ) ;
F_21 ( 1 ) ;
V_16 |= V_51 ;
}
F_19 ( V_10 , V_16 , V_47 ) ;
if ( ! V_45 ) {
V_16 = F_18 ( V_10 , F_22 ( 0 ) ) ;
V_16 |= V_52 ;
F_19 ( V_10 , V_16 , F_22 ( 0 ) ) ;
}
}
static int F_23 ( struct V_1 * V_2 , int V_3 ,
struct V_53 * V_54 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_21 = V_2 -> V_55 [ V_2 -> V_56 ] . V_21 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_25 ) ;
V_16 &= ~ F_15 ( V_3 ) ;
F_13 ( V_10 , V_16 , V_25 ) ;
F_13 ( V_10 , 0 , F_24 ( V_3 ) ) ;
if ( V_3 == 0 && V_10 -> V_22 . V_57 == 1 ) {
F_17 ( V_2 , true ) ;
if ( V_54 ) {
V_54 -> V_58 = V_59 ;
F_25 ( V_54 ) ;
}
}
if ( V_3 == 7 )
F_26 ( V_10 , F_27 ( V_60 ) ) ;
V_16 = F_7 ( V_10 , F_12 ( V_3 ) ) ;
V_16 &= ~ V_61 ;
V_16 |= ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , F_12 ( V_3 ) ) ;
F_11 ( V_2 , V_21 ) ;
if ( V_10 -> V_62 [ V_3 ] . V_63 . V_64 )
F_16 ( V_2 , V_3 , true ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , int V_3 ,
struct V_53 * V_54 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_65 , V_16 ;
if ( V_10 -> V_66 & ( 1 << V_3 ) )
return;
if ( V_3 == 7 ) {
F_29 ( V_10 , F_27 ( V_60 ) ) ;
F_30 ( V_10 , F_27 ( V_60 ) , V_67 ) ;
}
if ( V_3 == 0 && V_10 -> V_22 . V_57 == 1 )
F_17 ( V_2 , false ) ;
if ( F_31 ( V_2 , V_3 ) )
V_65 = V_26 ;
else
V_65 = F_24 ( V_3 ) ;
V_16 = F_7 ( V_10 , V_65 ) ;
V_16 |= V_30 | V_31 ;
F_13 ( V_10 , V_16 , V_65 ) ;
V_16 = F_7 ( V_10 , V_25 ) ;
V_16 |= F_15 ( V_3 ) ;
F_13 ( V_10 , V_16 , V_25 ) ;
}
static int F_32 ( struct V_1 * V_2 , int V_3 ,
struct V_53 * V_54 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_68 * V_69 = & V_10 -> V_62 [ V_3 ] . V_63 ;
int V_70 ;
V_69 -> V_71 = ( V_72 | V_73 ) ;
V_70 = F_33 ( V_54 , 0 ) ;
if ( V_70 )
return 0 ;
F_16 ( V_2 , V_3 , true ) ;
return 1 ;
}
static int F_34 ( struct V_1 * V_2 , int V_3 ,
struct V_68 * V_74 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_68 * V_69 = & V_10 -> V_62 [ V_3 ] . V_63 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_75 ) ;
V_74 -> V_64 = V_69 -> V_64 ;
V_74 -> V_76 = ! ! ( V_16 & ( 1 << V_3 ) ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , int V_3 ,
struct V_53 * V_77 ,
struct V_68 * V_74 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_68 * V_69 = & V_10 -> V_62 [ V_3 ] . V_63 ;
V_69 -> V_64 = V_74 -> V_64 ;
if ( ! V_69 -> V_64 ) {
F_16 ( V_2 , V_3 , false ) ;
} else {
V_69 -> V_64 = F_32 ( V_2 , V_3 , V_77 ) ;
if ( ! V_69 -> V_64 )
return - V_78 ;
}
return 0 ;
}
static T_6 F_36 ( int V_79 , void * V_80 )
{
struct V_9 * V_10 = V_80 ;
V_10 -> V_81 = F_37 ( V_10 , V_82 ) &
~ V_10 -> V_83 ;
F_38 ( V_10 , V_10 -> V_81 , V_67 ) ;
return V_84 ;
}
static T_6 F_39 ( int V_79 , void * V_80 )
{
struct V_9 * V_10 = V_80 ;
V_10 -> V_85 = F_40 ( V_10 , V_82 ) &
~ V_10 -> V_86 ;
F_30 ( V_10 , V_10 -> V_85 , V_67 ) ;
if ( V_10 -> V_85 & F_41 ( V_60 ) )
V_10 -> V_62 [ 7 ] . V_87 = 1 ;
if ( V_10 -> V_85 & F_42 ( V_60 ) )
V_10 -> V_62 [ 7 ] . V_87 = 0 ;
return V_84 ;
}
static int F_43 ( struct V_9 * V_10 )
{
unsigned int V_88 = 1000 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_89 ) ;
V_16 |= V_90 | V_91 | V_92 ;
F_13 ( V_10 , V_16 , V_89 ) ;
do {
V_16 = F_7 ( V_10 , V_89 ) ;
if ( ! ( V_16 & V_90 ) )
break;
F_44 ( 1000 , 2000 ) ;
} while ( V_88 -- > 0 );
if ( V_88 == 0 )
return - V_93 ;
return 0 ;
}
static void F_45 ( struct V_9 * V_10 )
{
F_38 ( V_10 , 0xffffffff , V_94 ) ;
F_38 ( V_10 , 0xffffffff , V_67 ) ;
F_38 ( V_10 , 0 , V_95 ) ;
F_30 ( V_10 , 0xffffffff , V_94 ) ;
F_30 ( V_10 , 0xffffffff , V_67 ) ;
F_30 ( V_10 , 0 , V_95 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
const char * V_96 [ V_97 ] = V_98 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_99 * V_100 ;
void T_7 * * V_101 ;
unsigned int V_3 ;
unsigned int V_5 ;
T_4 V_16 , V_102 ;
int V_70 ;
F_47 ( & V_10 -> V_103 ) ;
F_48 ( & V_10 -> V_15 ) ;
V_100 = V_2 -> V_104 -> V_105 -> V_106 ;
V_10 -> V_107 = F_49 ( V_100 , 0 ) ;
V_10 -> V_108 = F_49 ( V_100 , 1 ) ;
V_101 = & V_10 -> V_109 ;
for ( V_5 = 0 ; V_5 < V_97 ; V_5 ++ ) {
* V_101 = F_50 ( V_100 , V_5 ) ;
if ( * V_101 == NULL ) {
F_51 ( L_2 , V_96 [ V_5 ] ) ;
V_70 = - V_110 ;
goto V_111;
}
V_101 ++ ;
}
V_70 = F_43 ( V_10 ) ;
if ( V_70 ) {
F_51 ( L_3 , V_70 ) ;
goto V_111;
}
F_45 ( V_10 ) ;
V_70 = F_52 ( V_10 -> V_107 , F_36 , 0 ,
L_4 , V_10 ) ;
if ( V_70 < 0 ) {
F_51 ( L_5 ) ;
goto V_111;
}
V_70 = F_52 ( V_10 -> V_108 , F_39 , 0 ,
L_6 , V_10 ) ;
if ( V_70 < 0 ) {
F_51 ( L_7 ) ;
goto V_112;
}
V_16 = F_7 ( V_10 , V_113 ) ;
V_16 |= V_114 ;
F_13 ( V_10 , V_16 , V_113 ) ;
V_16 &= ~ V_114 ;
F_13 ( V_10 , V_16 , V_113 ) ;
V_10 -> V_22 . V_23 = F_7 ( V_10 , V_115 ) + 1 ;
if ( V_10 -> V_22 . V_23 > V_116 )
V_10 -> V_22 . V_23 = V_116 ;
if ( F_53 ( V_100 , L_8 ,
& V_10 -> V_22 . V_57 ) )
V_10 -> V_22 . V_57 = 1 ;
for ( V_3 = 0 ; V_3 < V_10 -> V_22 . V_23 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 )
F_23 ( V_2 , V_3 , NULL ) ;
else if ( F_31 ( V_2 , V_3 ) )
F_14 ( V_2 , V_3 ) ;
else
F_28 ( V_2 , V_3 , NULL ) ;
}
V_2 -> V_117 |= ( ( 1 << 30 ) | ( 1 << 0 ) ) ;
V_102 = F_18 ( V_10 , V_118 ) ;
V_10 -> V_22 . V_119 = ( V_102 >> V_120 ) &
V_121 ;
V_10 -> V_22 . V_122 = ( V_102 & V_123 ) ;
V_102 = F_18 ( V_10 , V_124 ) ;
V_10 -> V_22 . V_125 = V_102 & V_126 ;
F_54 ( L_9 ,
V_10 -> V_22 . V_119 >> 8 , V_10 -> V_22 . V_119 & 0xff ,
V_10 -> V_22 . V_122 >> 8 , V_10 -> V_22 . V_122 & 0xff ,
V_10 -> V_109 , V_10 -> V_107 , V_10 -> V_108 ) ;
return 0 ;
V_112:
F_55 ( V_10 -> V_107 , V_10 ) ;
V_111:
V_101 = & V_10 -> V_109 ;
for ( V_5 = 0 ; V_5 < V_97 ; V_5 ++ ) {
if ( * V_101 )
F_56 ( * V_101 ) ;
V_101 ++ ;
}
return V_70 ;
}
static int F_57 ( struct V_1 * V_2 , T_8 * V_127 )
{
return 0 ;
}
static T_4 F_58 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
return V_10 -> V_22 . V_125 ;
}
static int F_59 ( struct V_1 * V_2 , int V_128 , int V_127 ,
int V_129 , T_9 V_13 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_70 = 0 ;
T_4 V_16 ;
V_16 = F_18 ( V_10 , V_130 ) ;
V_16 |= V_131 ;
F_19 ( V_10 , V_16 , V_130 ) ;
V_16 = 0x70 ;
V_16 <<= 2 ;
F_13 ( V_10 , V_127 , V_16 ) ;
V_16 = 0x80 << 8 | V_129 << 1 ;
V_16 <<= 2 ;
if ( V_128 )
V_70 = F_7 ( V_10 , V_16 ) ;
else
F_13 ( V_10 , V_13 , V_16 ) ;
V_16 = F_18 ( V_10 , V_130 ) ;
V_16 &= ~ V_131 ;
F_19 ( V_10 , V_16 , V_130 ) ;
return V_70 & 0xffff ;
}
static int F_60 ( struct V_1 * V_2 , int V_127 , int V_129 )
{
switch ( V_127 ) {
case 0 :
case 30 :
return F_59 ( V_2 , 1 , V_127 , V_129 , 0 ) ;
default:
return 0xffff ;
}
}
static int F_61 ( struct V_1 * V_2 , int V_127 , int V_129 ,
T_9 V_13 )
{
switch ( V_127 ) {
case 0 :
case 30 :
F_59 ( V_2 , 0 , V_127 , V_129 , V_13 ) ;
break;
}
return 0 ;
}
static void F_62 ( struct V_1 * V_2 , int V_3 ,
struct V_53 * V_77 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_132 = 0 , V_133 ;
const char * V_134 = NULL ;
T_4 V_16 ;
switch ( V_77 -> V_135 ) {
case V_136 :
V_134 = L_10 ;
V_132 = 1 ;
case V_137 :
if ( ! V_134 )
V_134 = L_11 ;
V_133 = V_138 ;
break;
case V_139 :
V_134 = L_12 ;
V_133 = V_140 ;
break;
case V_141 :
V_134 = L_13 ;
V_133 = V_142 ;
break;
default:
goto V_143;
}
if ( ! V_77 -> V_87 ) {
V_16 = F_18 ( V_10 , F_63 ( V_3 ) ) ;
V_16 &= ~ V_144 ;
F_19 ( V_10 , V_16 , F_63 ( V_3 ) ) ;
goto V_143;
}
V_16 = F_18 ( V_10 , F_63 ( V_3 ) ) ;
V_16 &= ~ V_145 ;
V_16 &= ~ ( V_146 << V_147 ) ;
V_16 &= ~ ( V_148 | V_149 ) ;
V_16 |= V_133 | V_144 ;
if ( V_132 )
V_16 |= V_145 ;
if ( V_77 -> V_150 ) {
if ( V_77 -> V_151 )
V_16 |= V_149 ;
V_16 |= V_148 ;
}
F_19 ( V_10 , V_16 , F_63 ( V_3 ) ) ;
F_54 ( L_14 , V_3 , V_134 ) ;
V_143:
V_16 = V_152 ;
switch ( V_77 -> V_153 ) {
case V_154 :
V_16 |= V_155 << V_156 ;
break;
case V_157 :
V_16 |= V_158 << V_156 ;
break;
}
if ( V_77 -> V_87 )
V_16 |= V_44 ;
if ( V_77 -> V_159 == V_160 )
V_16 |= V_161 ;
F_13 ( V_10 , V_16 , F_64 ( V_3 ) ) ;
}
static void F_65 ( struct V_1 * V_2 , int V_3 ,
struct V_162 * V_163 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_159 , V_150 , V_153 ;
T_4 V_16 ;
V_159 = F_7 ( V_10 , V_164 ) ;
V_150 = F_7 ( V_10 , V_165 ) ;
V_153 = F_7 ( V_10 , V_166 ) ;
V_153 >>= ( V_3 * V_167 ) ;
V_153 &= V_168 ;
V_163 -> V_87 = 0 ;
if ( V_3 == 7 ) {
V_163 -> V_87 = V_10 -> V_62 [ V_3 ] . V_87 ;
V_163 -> V_159 = 1 ;
} else {
V_163 -> V_87 = 1 ;
V_163 -> V_159 = ! ! ( V_159 & ( 1 << V_3 ) ) ;
}
V_16 = F_7 ( V_10 , F_64 ( V_3 ) ) ;
V_16 |= V_152 ;
if ( V_163 -> V_87 )
V_16 |= V_44 ;
else
V_16 &= ~ V_44 ;
F_13 ( V_10 , V_16 , F_64 ( V_3 ) ) ;
switch ( V_153 ) {
case V_169 :
V_163 -> V_153 = V_170 ;
break;
case V_158 :
V_163 -> V_153 = V_157 ;
break;
case V_155 :
V_163 -> V_153 = V_154 ;
break;
}
if ( ( V_150 & ( 1 << V_3 ) ) &&
( V_150 & ( 1 << ( V_3 + V_171 ) ) ) ) {
V_163 -> V_151 = 1 ;
V_163 -> V_150 = 1 ;
}
if ( V_150 & ( 1 << V_3 ) )
V_163 -> V_150 = 1 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
F_45 ( V_10 ) ;
for ( V_3 = 0 ; V_3 < V_116 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 ||
F_31 ( V_2 , V_3 ) )
F_28 ( V_2 , V_3 , NULL ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
int V_70 ;
V_70 = F_43 ( V_10 ) ;
if ( V_70 ) {
F_51 ( L_15 , V_172 ) ;
return V_70 ;
}
if ( V_10 -> V_22 . V_57 == 1 )
F_17 ( V_2 , true ) ;
for ( V_3 = 0 ; V_3 < V_116 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 )
F_23 ( V_2 , V_3 , NULL ) ;
else if ( F_31 ( V_2 , V_3 ) )
F_14 ( V_2 , V_3 ) ;
}
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , int V_3 ,
struct V_173 * V_174 )
{
struct V_175 * V_69 = V_2 -> V_55 [ V_2 -> V_56 ] . V_176 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_173 V_177 ;
V_69 -> V_178 -> V_179 ( V_69 , & V_177 ) ;
V_174 -> V_71 = V_177 . V_71 ;
memset ( & V_174 -> V_180 , 0 , sizeof( V_174 -> V_180 ) ) ;
if ( V_177 . V_181 & V_182 )
memcpy ( & V_174 -> V_180 , V_177 . V_180 , sizeof( V_174 -> V_180 ) ) ;
if ( V_10 -> V_66 & ( 1 << V_3 ) )
V_174 -> V_181 = V_177 . V_181 ;
else
V_174 -> V_181 = 0 ;
}
static int F_69 ( struct V_1 * V_2 , int V_3 ,
struct V_173 * V_174 )
{
struct V_175 * V_69 = V_2 -> V_55 [ V_2 -> V_56 ] . V_176 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_21 = V_2 -> V_55 [ V_2 -> V_56 ] . V_21 ;
struct V_173 V_177 ;
V_69 -> V_178 -> V_179 ( V_69 , & V_177 ) ;
if ( V_174 -> V_181 & ~ V_177 . V_71 )
return - V_183 ;
if ( V_174 -> V_181 )
V_10 -> V_66 |= ( 1 << V_3 ) ;
else
V_10 -> V_66 &= ~ ( 1 << V_3 ) ;
if ( V_10 -> V_66 && V_10 -> V_66 != ( 1 << V_21 ) )
V_10 -> V_66 |= ( 1 << V_21 ) ;
else
V_10 -> V_66 &= ~ ( 1 << V_21 ) ;
return V_69 -> V_178 -> V_184 ( V_69 , V_174 ) ;
}
static int T_10 F_70 ( void )
{
F_71 ( & V_185 ) ;
return 0 ;
}
static void T_11 F_72 ( void )
{
F_73 ( & V_185 ) ;
}
