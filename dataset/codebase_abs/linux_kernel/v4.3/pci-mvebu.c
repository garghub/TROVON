static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline bool F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_6 != - 1 && V_2 -> V_7 != - 1 ;
}
static bool F_6 ( struct V_1 * V_2 )
{
return ! ( F_3 ( V_2 , V_8 ) & V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_10 )
{
T_1 V_11 ;
V_11 = F_3 ( V_2 , V_8 ) ;
V_11 &= ~ V_12 ;
V_11 |= V_10 << 8 ;
F_1 ( V_2 , V_11 , V_8 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_10 )
{
T_1 V_11 ;
V_11 = F_3 ( V_2 , V_8 ) ;
V_11 &= ~ V_13 ;
V_11 |= V_10 << 16 ;
F_1 ( V_2 , V_11 , V_8 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
const struct V_14 * V_15 ;
T_1 V_16 ;
int V_17 ;
V_15 = F_10 () ;
for ( V_17 = 1 ; V_17 < 3 ; V_17 ++ ) {
F_1 ( V_2 , 0 , F_11 ( V_17 ) ) ;
F_1 ( V_2 , 0 , F_12 ( V_17 ) ) ;
F_1 ( V_2 , 0 , F_13 ( V_17 ) ) ;
}
for ( V_17 = 0 ; V_17 < 5 ; V_17 ++ ) {
F_1 ( V_2 , 0 , F_14 ( V_17 ) ) ;
F_1 ( V_2 , 0 , F_15 ( V_17 ) ) ;
F_1 ( V_2 , 0 , F_16 ( V_17 ) ) ;
}
F_1 ( V_2 , 0 , V_18 ) ;
F_1 ( V_2 , 0 , V_19 ) ;
F_1 ( V_2 , 0 , V_20 ) ;
V_16 = 0 ;
for ( V_17 = 0 ; V_17 < V_15 -> V_21 ; V_17 ++ ) {
const struct V_22 * V_23 = V_15 -> V_23 + V_17 ;
F_1 ( V_2 , V_23 -> V_5 & 0xffff0000 ,
F_15 ( V_17 ) ) ;
F_1 ( V_2 , 0 , F_16 ( V_17 ) ) ;
F_1 ( V_2 ,
( ( V_23 -> V_16 - 1 ) & 0xffff0000 ) |
( V_23 -> V_24 << 8 ) |
( V_15 -> V_25 << 4 ) | 1 ,
F_14 ( V_17 ) ) ;
V_16 += V_23 -> V_16 ;
}
if ( ( V_16 & ( V_16 - 1 ) ) != 0 )
V_16 = 1 << F_17 ( V_16 ) ;
F_1 ( V_2 , V_15 -> V_23 [ 0 ] . V_5 , F_12 ( 1 ) ) ;
F_1 ( V_2 , 0 , F_13 ( 1 ) ) ;
F_1 ( V_2 , ( ( V_16 - 1 ) & 0xffff0000 ) | 1 ,
F_11 ( 1 ) ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_26 , V_27 ;
F_9 ( V_2 ) ;
V_26 = F_3 ( V_2 , V_28 ) ;
V_26 |= V_29 ;
V_26 |= V_30 ;
V_26 |= V_31 ;
F_1 ( V_2 , V_26 , V_28 ) ;
V_27 = F_3 ( V_2 , V_32 ) ;
V_27 |= V_33 ;
F_1 ( V_2 , V_27 , V_32 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
T_1 V_36 , int V_37 , int V_16 , T_1 * V_3 )
{
F_1 ( V_2 , F_20 ( V_35 -> V_38 , V_36 , V_37 ) ,
V_39 ) ;
* V_3 = F_3 ( V_2 , V_40 ) ;
if ( V_16 == 1 )
* V_3 = ( * V_3 >> ( 8 * ( V_37 & 3 ) ) ) & 0xff ;
else if ( V_16 == 2 )
* V_3 = ( * V_3 >> ( 8 * ( V_37 & 3 ) ) ) & 0xffff ;
return V_41 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
T_1 V_36 , int V_37 , int V_16 , T_1 V_3 )
{
T_1 V_42 , V_43 = 8 * ( V_37 & 3 ) ;
F_1 ( V_2 , F_20 ( V_35 -> V_38 , V_36 , V_37 ) ,
V_39 ) ;
V_42 = F_3 ( V_2 , V_40 ) ;
if ( V_16 == 4 )
V_42 = V_3 ;
else if ( V_16 == 2 )
V_42 = ( V_42 & ~ ( 0xffff << V_43 ) ) | ( ( V_3 & 0xffff ) << V_43 ) ;
else if ( V_16 == 1 )
V_42 = ( V_42 & ~ ( 0xff << V_43 ) ) | ( ( V_3 & 0xff ) << V_43 ) ;
else
return V_44 ;
F_1 ( V_2 , V_42 , V_40 ) ;
return V_41 ;
}
static void F_22 ( struct V_1 * V_2 ,
T_2 V_5 , T_3 V_16 )
{
while ( V_16 ) {
T_3 V_45 = 1 << ( F_17 ( V_16 ) - 1 ) ;
F_23 ( V_5 , V_45 ) ;
V_5 += V_45 ;
V_16 -= V_45 ;
}
}
static void F_24 ( struct V_1 * V_2 ,
unsigned int V_46 , unsigned int V_47 ,
T_2 V_5 , T_3 V_16 ,
T_2 V_48 )
{
T_3 V_49 = 0 ;
while ( V_16 ) {
T_3 V_45 = 1 << ( F_17 ( V_16 ) - 1 ) ;
int V_50 ;
V_50 = F_25 ( V_46 , V_47 , V_5 ,
V_45 , V_48 ) ;
if ( V_50 ) {
T_2 V_51 = V_5 + V_45 - 1 ;
F_26 ( & V_2 -> V_52 -> V_53 -> V_54 ,
L_1 ,
& V_5 , & V_51 , V_50 ) ;
F_22 ( V_2 , V_5 - V_49 ,
V_49 ) ;
return;
}
V_16 -= V_45 ;
V_49 += V_45 ;
V_5 += V_45 ;
if ( V_48 != V_55 )
V_48 += V_45 ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
T_2 V_56 ;
if ( V_2 -> V_57 . V_58 < V_2 -> V_57 . V_56 ||
V_2 -> V_57 . V_59 < V_2 -> V_57 . V_60 ||
! ( V_2 -> V_57 . V_61 & V_29 ) ) {
if ( V_2 -> V_62 ) {
F_22 ( V_2 , V_2 -> V_62 ,
V_2 -> V_63 ) ;
V_2 -> V_62 = 0 ;
V_2 -> V_63 = 0 ;
}
return;
}
if ( ! F_5 ( V_2 ) ) {
F_28 ( & V_2 -> V_52 -> V_53 -> V_54 ,
L_2 ) ;
return;
}
V_56 = ( ( V_2 -> V_57 . V_56 & 0xF0 ) << 8 ) |
( V_2 -> V_57 . V_60 << 16 ) ;
V_2 -> V_62 = V_2 -> V_52 -> V_64 . V_65 + V_56 ;
V_2 -> V_63 = ( ( 0xFFF | ( ( V_2 -> V_57 . V_58 & 0xF0 ) << 8 ) |
( V_2 -> V_57 . V_59 << 16 ) ) -
V_56 ) + 1 ;
F_24 ( V_2 , V_2 -> V_6 , V_2 -> V_7 ,
V_2 -> V_62 , V_2 -> V_63 ,
V_56 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 . V_66 < V_2 -> V_57 . V_67 ||
! ( V_2 -> V_57 . V_61 & V_30 ) ) {
if ( V_2 -> V_68 ) {
F_22 ( V_2 , V_2 -> V_68 ,
V_2 -> V_69 ) ;
V_2 -> V_68 = 0 ;
V_2 -> V_69 = 0 ;
}
return;
}
V_2 -> V_68 = ( ( V_2 -> V_57 . V_67 & 0xFFF0 ) << 16 ) ;
V_2 -> V_69 =
( ( ( V_2 -> V_57 . V_66 & 0xFFF0 ) << 16 ) | 0xFFFFF ) -
V_2 -> V_68 + 1 ;
F_24 ( V_2 , V_2 -> V_70 , V_2 -> V_71 ,
V_2 -> V_68 , V_2 -> V_69 ,
V_55 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_72 * V_57 = & V_2 -> V_57 ;
memset ( V_57 , 0 , sizeof( struct V_72 ) ) ;
V_57 -> V_73 = V_74 ;
V_57 -> V_75 = V_76 ;
V_57 -> V_77 = F_3 ( V_2 , V_78 ) >> 16 ;
V_57 -> V_79 = F_3 ( V_2 , V_80 ) & 0xff ;
V_57 -> V_81 = V_82 ;
V_57 -> V_83 = 0x10 ;
V_57 -> V_56 = V_84 ;
V_57 -> V_58 = V_84 ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned int V_37 , int V_16 , T_1 * V_85 )
{
struct V_72 * V_57 = & V_2 -> V_57 ;
switch ( V_37 & ~ 3 ) {
case V_86 :
* V_85 = V_57 -> V_77 << 16 | V_57 -> V_75 ;
break;
case V_87 :
* V_85 = V_57 -> V_61 ;
break;
case V_88 :
* V_85 = V_57 -> V_73 << 16 | V_57 -> V_89 << 8 |
V_57 -> V_79 ;
break;
case V_90 :
* V_85 = V_57 -> V_91 << 24 | V_57 -> V_81 << 16 |
V_57 -> V_92 << 8 | V_57 -> V_83 ;
break;
case V_93 ... V_94 :
* V_85 = V_57 -> V_95 [ ( ( V_37 & ~ 3 ) - V_93 ) / 4 ] ;
break;
case V_96 :
* V_85 = ( V_57 -> V_97 << 24 |
V_57 -> V_98 << 16 |
V_57 -> V_99 << 8 |
V_57 -> V_100 ) ;
break;
case V_101 :
if ( ! F_5 ( V_2 ) )
* V_85 = V_57 -> V_102 << 16 ;
else
* V_85 = ( V_57 -> V_102 << 16 |
V_57 -> V_58 << 8 |
V_57 -> V_56 ) ;
break;
case V_103 :
* V_85 = ( V_57 -> V_66 << 16 | V_57 -> V_67 ) ;
break;
case V_104 :
* V_85 = 0 ;
break;
case V_105 :
* V_85 = ( V_57 -> V_59 << 16 | V_57 -> V_60 ) ;
break;
case V_106 :
* V_85 = 0 ;
break;
case V_107 :
* V_85 = 0 ;
break;
default:
* V_85 = 0xffffffff ;
return V_44 ;
}
if ( V_16 == 2 )
* V_85 = ( * V_85 >> ( 8 * ( V_37 & 3 ) ) ) & 0xffff ;
else if ( V_16 == 1 )
* V_85 = ( * V_85 >> ( 8 * ( V_37 & 3 ) ) ) & 0xff ;
return V_41 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned int V_37 , int V_16 , T_1 V_85 )
{
struct V_72 * V_57 = & V_2 -> V_57 ;
T_1 V_27 , V_4 ;
int V_108 ;
if ( V_16 == 4 )
V_27 = 0x0 ;
else if ( V_16 == 2 )
V_27 = ~ ( 0xffff << ( ( V_37 & 3 ) * 8 ) ) ;
else if ( V_16 == 1 )
V_27 = ~ ( 0xff << ( ( V_37 & 3 ) * 8 ) ) ;
else
return V_44 ;
V_108 = F_31 ( V_2 , V_37 & ~ 3 , 4 , & V_4 ) ;
if ( V_108 )
return V_108 ;
V_85 = ( V_4 & V_27 ) | V_85 << ( ( V_37 & 3 ) * 8 ) ;
switch ( V_37 & ~ 3 ) {
case V_87 :
{
T_1 V_109 = V_57 -> V_61 ;
if ( ! F_5 ( V_2 ) )
V_85 &= ~ V_29 ;
V_57 -> V_61 = V_85 & 0xffff ;
if ( ( V_109 ^ V_57 -> V_61 ) & V_29 )
F_27 ( V_2 ) ;
if ( ( V_109 ^ V_57 -> V_61 ) & V_30 )
F_29 ( V_2 ) ;
break;
}
case V_93 ... V_94 :
V_57 -> V_95 [ ( ( V_37 & ~ 3 ) - V_93 ) / 4 ] = V_85 ;
break;
case V_101 :
V_57 -> V_56 = ( V_85 & 0xff ) | V_84 ;
V_57 -> V_58 = ( ( V_85 >> 8 ) & 0xff ) | V_84 ;
F_27 ( V_2 ) ;
break;
case V_103 :
V_57 -> V_67 = V_85 & 0xffff ;
V_57 -> V_66 = V_85 >> 16 ;
F_29 ( V_2 ) ;
break;
case V_105 :
V_57 -> V_60 = V_85 & 0xffff ;
V_57 -> V_59 = V_85 >> 16 ;
F_27 ( V_2 ) ;
break;
case V_96 :
V_57 -> V_100 = V_85 & 0xff ;
V_57 -> V_99 = ( V_85 >> 8 ) & 0xff ;
V_57 -> V_98 = ( V_85 >> 16 ) & 0xff ;
V_57 -> V_97 = ( V_85 >> 24 ) & 0xff ;
F_7 ( V_2 , V_57 -> V_99 ) ;
break;
default:
break;
}
return V_41 ;
}
static inline struct V_110 * F_33 ( struct V_111 * V_112 )
{
return V_112 -> V_113 ;
}
static struct V_1 * F_34 ( struct V_110 * V_52 ,
struct V_34 * V_35 ,
int V_36 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_52 -> V_114 ; V_17 ++ ) {
struct V_1 * V_2 = & V_52 -> V_115 [ V_17 ] ;
if ( V_35 -> V_38 == 0 && V_2 -> V_36 == V_36 )
return V_2 ;
if ( V_35 -> V_38 != 0 &&
V_35 -> V_38 >= V_2 -> V_57 . V_99 &&
V_35 -> V_38 <= V_2 -> V_57 . V_98 )
return V_2 ;
}
return NULL ;
}
static int F_35 ( struct V_34 * V_35 , T_1 V_36 ,
int V_37 , int V_16 , T_1 V_3 )
{
struct V_110 * V_52 = F_33 ( V_35 -> V_116 ) ;
struct V_1 * V_2 ;
int V_50 ;
V_2 = F_34 ( V_52 , V_35 , V_36 ) ;
if ( ! V_2 )
return V_117 ;
if ( V_35 -> V_38 == 0 )
return F_32 ( V_2 , V_37 , V_16 , V_3 ) ;
if ( ! F_6 ( V_2 ) )
return V_117 ;
if ( V_35 -> V_38 == V_2 -> V_57 . V_99 &&
F_36 ( V_36 ) != 0 )
return V_117 ;
V_50 = F_21 ( V_2 , V_35 , V_36 ,
V_37 , V_16 , V_3 ) ;
return V_50 ;
}
static int F_37 ( struct V_34 * V_35 , T_1 V_36 , int V_37 ,
int V_16 , T_1 * V_3 )
{
struct V_110 * V_52 = F_33 ( V_35 -> V_116 ) ;
struct V_1 * V_2 ;
int V_50 ;
V_2 = F_34 ( V_52 , V_35 , V_36 ) ;
if ( ! V_2 ) {
* V_3 = 0xffffffff ;
return V_117 ;
}
if ( V_35 -> V_38 == 0 )
return F_31 ( V_2 , V_37 , V_16 , V_3 ) ;
if ( ! F_6 ( V_2 ) ) {
* V_3 = 0xffffffff ;
return V_117 ;
}
if ( V_35 -> V_38 == V_2 -> V_57 . V_99 &&
F_36 ( V_36 ) != 0 ) {
* V_3 = 0xffffffff ;
return V_117 ;
}
V_50 = F_19 ( V_2 , V_35 , V_36 ,
V_37 , V_16 , V_3 ) ;
return V_50 ;
}
static int F_38 ( int V_10 , struct V_111 * V_112 )
{
struct V_110 * V_52 = F_33 ( V_112 ) ;
int V_17 ;
V_52 -> V_118 . V_119 = L_3 ;
V_52 -> V_120 . V_119 = L_4 ;
if ( F_39 ( & V_121 , & V_52 -> V_118 ) )
return 0 ;
if ( F_40 ( & V_52 -> V_120 ) != 0 ) {
if ( F_39 ( & V_122 , & V_52 -> V_120 ) ) {
F_41 ( & V_52 -> V_118 ) ;
return 0 ;
}
F_42 ( & V_112 -> V_123 , & V_52 -> V_120 ,
V_112 -> V_124 ) ;
}
F_42 ( & V_112 -> V_123 , & V_52 -> V_118 , V_112 -> V_125 ) ;
F_43 ( & V_112 -> V_123 , & V_52 -> V_126 ) ;
for ( V_17 = 0 ; V_17 < V_52 -> V_114 ; V_17 ++ ) {
struct V_1 * V_2 = & V_52 -> V_115 [ V_17 ] ;
if ( ! V_2 -> V_5 )
continue;
F_18 ( V_2 ) ;
}
return 1 ;
}
static T_4 F_44 ( struct V_127 * V_54 ,
const struct V_128 * V_129 ,
T_4 V_65 ,
T_4 V_16 ,
T_4 V_130 )
{
if ( V_54 -> V_35 -> V_38 != 0 )
return V_65 ;
if ( V_129 -> V_131 & V_132 )
return F_45 ( V_65 , F_46 ( T_4 , V_133 ,
F_47 ( V_16 ) ) ) ;
else if ( V_129 -> V_131 & V_134 )
return F_45 ( V_65 , F_46 ( T_4 , V_135 ,
F_47 ( V_16 ) ) ) ;
else
return V_65 ;
}
static void F_48 ( struct V_110 * V_52 )
{
struct V_136 V_137 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
#ifdef F_49
V_137 . V_138 = V_52 -> V_139 ;
#endif
V_137 . V_140 = 1 ;
V_137 . V_113 = ( void * * ) & V_52 ;
V_137 . V_141 = F_38 ;
V_137 . V_142 = V_143 ;
V_137 . V_144 = & V_145 ;
V_137 . V_146 = F_44 ;
F_50 ( & V_52 -> V_53 -> V_54 , & V_137 ) ;
}
static void T_5 * F_51 ( struct V_147 * V_53 ,
struct V_148 * V_149 ,
struct V_1 * V_2 )
{
struct V_128 V_150 ;
int V_50 = 0 ;
V_50 = F_52 ( V_149 , 0 , & V_150 ) ;
if ( V_50 )
return F_53 ( V_50 ) ;
return F_54 ( & V_53 -> V_54 , & V_150 ) ;
}
static int F_55 ( struct V_148 * V_149 , int V_36 ,
unsigned long type ,
unsigned int * V_151 ,
unsigned int * V_152 )
{
const int V_153 = 3 , V_154 = 2 ;
const T_6 * V_155 ;
int V_156 , V_157 , V_158 , V_159 , V_17 ;
* V_151 = - 1 ;
* V_152 = - 1 ;
V_155 = F_56 ( V_149 , L_5 , & V_156 ) ;
if ( ! V_155 )
return - V_160 ;
V_159 = F_57 ( V_149 ) ;
V_158 = V_159 + V_153 + V_154 ;
V_157 = V_156 / sizeof( T_6 ) / V_158 ;
for ( V_17 = 0 ; V_17 < V_157 ; V_17 ++ , V_155 += V_158 ) {
T_1 V_131 = F_58 ( V_155 , 1 ) ;
T_1 V_161 = F_58 ( V_155 + 1 , 1 ) ;
T_7 V_162 = F_58 ( V_155 + V_153 , V_159 ) ;
unsigned long V_163 ;
if ( F_59 ( V_131 ) == V_164 )
V_163 = V_132 ;
else if ( F_59 ( V_131 ) == V_165 )
V_163 = V_134 ;
else
continue;
if ( V_161 == F_36 ( V_36 ) && type == V_163 ) {
* V_151 = F_60 ( V_162 ) ;
* V_152 = F_61 ( V_162 ) ;
return 0 ;
}
}
return - V_166 ;
}
static void F_62 ( struct V_110 * V_52 )
{
struct V_148 * V_167 ;
V_167 = F_63 ( V_52 -> V_53 -> V_54 . V_168 ,
L_6 , 0 ) ;
if ( ! V_167 )
return;
V_52 -> V_139 = F_64 ( V_167 ) ;
F_65 ( V_167 ) ;
if ( V_52 -> V_139 )
V_52 -> V_139 -> V_54 = & V_52 -> V_53 -> V_54 ;
}
static int F_66 ( struct V_77 * V_54 )
{
struct V_110 * V_52 ;
int V_17 ;
V_52 = F_67 ( V_54 ) ;
for ( V_17 = 0 ; V_17 < V_52 -> V_114 ; V_17 ++ ) {
struct V_1 * V_2 = V_52 -> V_115 + V_17 ;
V_2 -> V_169 = F_3 ( V_2 , V_8 ) ;
}
return 0 ;
}
static int F_68 ( struct V_77 * V_54 )
{
struct V_110 * V_52 ;
int V_17 ;
V_52 = F_67 ( V_54 ) ;
for ( V_17 = 0 ; V_17 < V_52 -> V_114 ; V_17 ++ ) {
struct V_1 * V_2 = V_52 -> V_115 + V_17 ;
F_1 ( V_2 , V_2 -> V_169 , V_8 ) ;
F_18 ( V_2 ) ;
}
return 0 ;
}
static int F_69 ( struct V_147 * V_53 )
{
struct V_110 * V_52 ;
struct V_148 * V_149 = V_53 -> V_54 . V_168 ;
struct V_148 * V_170 ;
int V_17 , V_50 ;
V_52 = F_70 ( & V_53 -> V_54 , sizeof( struct V_110 ) ,
V_171 ) ;
if ( ! V_52 )
return - V_172 ;
V_52 -> V_53 = V_53 ;
F_71 ( V_53 , V_52 ) ;
F_72 ( & V_52 -> V_118 ) ;
if ( F_40 ( & V_52 -> V_118 ) == 0 ) {
F_26 ( & V_53 -> V_54 , L_7 ) ;
return - V_160 ;
}
F_73 ( & V_52 -> V_64 ) ;
if ( F_40 ( & V_52 -> V_64 ) != 0 ) {
V_52 -> V_120 . V_131 = V_52 -> V_64 . V_131 ;
V_52 -> V_120 . V_65 = V_173 ;
V_52 -> V_120 . V_51 = F_74 ( T_4 ,
V_174 ,
F_40 ( & V_52 -> V_64 ) ) ;
} else
V_52 -> V_120 = V_52 -> V_64 ;
V_50 = F_75 ( V_149 , & V_52 -> V_126 ) ;
if ( V_50 ) {
F_26 ( & V_53 -> V_54 , L_8 ,
V_50 ) ;
return V_50 ;
}
V_17 = 0 ;
F_76 (pdev->dev.of_node, child) {
if ( ! F_77 ( V_170 ) )
continue;
V_17 ++ ;
}
V_52 -> V_115 = F_70 ( & V_53 -> V_54 , V_17 *
sizeof( struct V_1 ) ,
V_171 ) ;
if ( ! V_52 -> V_115 )
return - V_172 ;
V_17 = 0 ;
F_76 (pdev->dev.of_node, child) {
struct V_1 * V_2 = & V_52 -> V_115 [ V_17 ] ;
enum V_175 V_131 ;
if ( ! F_77 ( V_170 ) )
continue;
V_2 -> V_52 = V_52 ;
if ( F_78 ( V_170 , L_9 ,
& V_2 -> V_2 ) ) {
F_79 ( & V_53 -> V_54 ,
L_10 ) ;
continue;
}
if ( F_78 ( V_170 , L_11 ,
& V_2 -> V_176 ) )
V_2 -> V_176 = 0 ;
V_2 -> V_119 = F_80 ( V_171 , L_12 ,
V_2 -> V_2 , V_2 -> V_176 ) ;
V_2 -> V_36 = F_81 ( V_170 ) ;
if ( V_2 -> V_36 < 0 )
continue;
V_50 = F_55 ( V_149 , V_2 -> V_36 , V_134 ,
& V_2 -> V_70 , & V_2 -> V_71 ) ;
if ( V_50 < 0 ) {
F_26 ( & V_53 -> V_54 , L_13 ,
V_2 -> V_2 , V_2 -> V_176 ) ;
continue;
}
if ( F_40 ( & V_52 -> V_64 ) != 0 )
F_55 ( V_149 , V_2 -> V_36 , V_132 ,
& V_2 -> V_6 , & V_2 -> V_7 ) ;
else {
V_2 -> V_6 = - 1 ;
V_2 -> V_7 = - 1 ;
}
V_2 -> V_177 = F_82 ( V_170 ,
L_14 , 0 , & V_131 ) ;
if ( F_83 ( V_2 -> V_177 ) ) {
T_1 V_178 = 20000 ;
V_2 -> V_179 = V_131 & V_180 ;
V_2 -> V_181 = F_80 ( V_171 ,
L_15 , V_2 -> V_2 , V_2 -> V_176 ) ;
F_78 ( V_170 , L_16 ,
& V_178 ) ;
V_50 = F_84 ( & V_53 -> V_54 ,
V_2 -> V_177 , V_182 , V_2 -> V_181 ) ;
if ( V_50 ) {
if ( V_50 == - V_183 )
return V_50 ;
continue;
}
F_85 ( V_2 -> V_177 ,
( V_2 -> V_179 ) ? 1 : 0 ) ;
F_86 ( V_178 / 1000 ) ;
}
V_2 -> V_184 = F_87 ( V_170 , NULL ) ;
if ( F_88 ( V_2 -> V_184 ) ) {
F_26 ( & V_53 -> V_54 , L_17 ,
V_2 -> V_2 , V_2 -> V_176 ) ;
continue;
}
V_50 = F_89 ( V_2 -> V_184 ) ;
if ( V_50 )
continue;
V_2 -> V_5 = F_51 ( V_53 , V_170 , V_2 ) ;
if ( F_88 ( V_2 -> V_5 ) ) {
F_26 ( & V_53 -> V_54 , L_18 ,
V_2 -> V_2 , V_2 -> V_176 ) ;
V_2 -> V_5 = NULL ;
F_90 ( V_2 -> V_184 ) ;
continue;
}
F_8 ( V_2 , 1 ) ;
V_2 -> V_185 = V_170 ;
F_30 ( V_2 ) ;
V_17 ++ ;
}
V_52 -> V_114 = V_17 ;
for ( V_17 = 0 ; V_17 < ( V_174 - V_133 ) ; V_17 += V_133 )
F_91 ( V_17 , V_52 -> V_64 . V_65 + V_17 ) ;
F_62 ( V_52 ) ;
F_48 ( V_52 ) ;
F_71 ( V_53 , V_52 ) ;
return 0 ;
}
