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
F_26 ( & V_2 -> V_51 -> V_52 -> V_53 ,
L_1 ,
V_5 , V_45 , V_50 ) ;
F_22 ( V_2 , V_5 - V_49 ,
V_49 ) ;
return;
}
V_16 -= V_45 ;
V_49 += V_45 ;
V_5 += V_45 ;
if ( V_48 != V_54 )
V_48 += V_45 ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
T_2 V_55 ;
if ( V_2 -> V_56 . V_57 < V_2 -> V_56 . V_55 ||
V_2 -> V_56 . V_58 < V_2 -> V_56 . V_59 ||
! ( V_2 -> V_56 . V_60 & V_29 ) ) {
if ( V_2 -> V_61 ) {
F_22 ( V_2 , V_2 -> V_61 ,
V_2 -> V_62 ) ;
V_2 -> V_61 = 0 ;
V_2 -> V_62 = 0 ;
}
return;
}
if ( ! F_5 ( V_2 ) ) {
F_28 ( & V_2 -> V_51 -> V_52 -> V_53 ,
L_2 ) ;
return;
}
V_55 = ( ( V_2 -> V_56 . V_55 & 0xF0 ) << 8 ) |
( V_2 -> V_56 . V_59 << 16 ) ;
V_2 -> V_61 = V_2 -> V_51 -> V_63 . V_64 + V_55 ;
V_2 -> V_62 = ( ( 0xFFF | ( ( V_2 -> V_56 . V_57 & 0xF0 ) << 8 ) |
( V_2 -> V_56 . V_58 << 16 ) ) -
V_55 ) + 1 ;
F_24 ( V_2 , V_2 -> V_6 , V_2 -> V_7 ,
V_2 -> V_61 , V_2 -> V_62 ,
V_55 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_56 . V_65 < V_2 -> V_56 . V_66 ||
! ( V_2 -> V_56 . V_60 & V_30 ) ) {
if ( V_2 -> V_67 ) {
F_22 ( V_2 , V_2 -> V_67 ,
V_2 -> V_68 ) ;
V_2 -> V_67 = 0 ;
V_2 -> V_68 = 0 ;
}
return;
}
V_2 -> V_67 = ( ( V_2 -> V_56 . V_66 & 0xFFF0 ) << 16 ) ;
V_2 -> V_68 =
( ( ( V_2 -> V_56 . V_65 & 0xFFF0 ) << 16 ) | 0xFFFFF ) -
V_2 -> V_67 + 1 ;
F_24 ( V_2 , V_2 -> V_69 , V_2 -> V_70 ,
V_2 -> V_67 , V_2 -> V_68 ,
V_54 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_71 * V_56 = & V_2 -> V_56 ;
memset ( V_56 , 0 , sizeof( struct V_71 ) ) ;
V_56 -> V_72 = V_73 ;
V_56 -> V_74 = V_75 ;
V_56 -> V_76 = F_3 ( V_2 , V_77 ) >> 16 ;
V_56 -> V_78 = F_3 ( V_2 , V_79 ) & 0xff ;
V_56 -> V_80 = V_81 ;
V_56 -> V_82 = 0x10 ;
V_56 -> V_55 = V_83 ;
V_56 -> V_57 = V_83 ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned int V_37 , int V_16 , T_1 * V_84 )
{
struct V_71 * V_56 = & V_2 -> V_56 ;
switch ( V_37 & ~ 3 ) {
case V_85 :
* V_84 = V_56 -> V_76 << 16 | V_56 -> V_74 ;
break;
case V_86 :
* V_84 = V_56 -> V_60 ;
break;
case V_87 :
* V_84 = V_56 -> V_72 << 16 | V_56 -> V_88 << 8 |
V_56 -> V_78 ;
break;
case V_89 :
* V_84 = V_56 -> V_90 << 24 | V_56 -> V_80 << 16 |
V_56 -> V_91 << 8 | V_56 -> V_82 ;
break;
case V_92 ... V_93 :
* V_84 = V_56 -> V_94 [ ( ( V_37 & ~ 3 ) - V_92 ) / 4 ] ;
break;
case V_95 :
* V_84 = ( V_56 -> V_96 << 24 |
V_56 -> V_97 << 16 |
V_56 -> V_98 << 8 |
V_56 -> V_99 ) ;
break;
case V_100 :
if ( ! F_5 ( V_2 ) )
* V_84 = V_56 -> V_101 << 16 ;
else
* V_84 = ( V_56 -> V_101 << 16 |
V_56 -> V_57 << 8 |
V_56 -> V_55 ) ;
break;
case V_102 :
* V_84 = ( V_56 -> V_65 << 16 | V_56 -> V_66 ) ;
break;
case V_103 :
* V_84 = 0 ;
break;
case V_104 :
* V_84 = ( V_56 -> V_58 << 16 | V_56 -> V_59 ) ;
break;
case V_105 :
* V_84 = 0 ;
break;
case V_106 :
* V_84 = 0 ;
break;
default:
* V_84 = 0xffffffff ;
return V_44 ;
}
if ( V_16 == 2 )
* V_84 = ( * V_84 >> ( 8 * ( V_37 & 3 ) ) ) & 0xffff ;
else if ( V_16 == 1 )
* V_84 = ( * V_84 >> ( 8 * ( V_37 & 3 ) ) ) & 0xff ;
return V_41 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned int V_37 , int V_16 , T_1 V_84 )
{
struct V_71 * V_56 = & V_2 -> V_56 ;
T_1 V_27 , V_4 ;
int V_107 ;
if ( V_16 == 4 )
V_27 = 0x0 ;
else if ( V_16 == 2 )
V_27 = ~ ( 0xffff << ( ( V_37 & 3 ) * 8 ) ) ;
else if ( V_16 == 1 )
V_27 = ~ ( 0xff << ( ( V_37 & 3 ) * 8 ) ) ;
else
return V_44 ;
V_107 = F_31 ( V_2 , V_37 & ~ 3 , 4 , & V_4 ) ;
if ( V_107 )
return V_107 ;
V_84 = ( V_4 & V_27 ) | V_84 << ( ( V_37 & 3 ) * 8 ) ;
switch ( V_37 & ~ 3 ) {
case V_86 :
{
T_1 V_108 = V_56 -> V_60 ;
if ( ! F_5 ( V_2 ) )
V_84 &= ~ V_29 ;
V_56 -> V_60 = V_84 & 0xffff ;
if ( ( V_108 ^ V_56 -> V_60 ) & V_29 )
F_27 ( V_2 ) ;
if ( ( V_108 ^ V_56 -> V_60 ) & V_30 )
F_29 ( V_2 ) ;
break;
}
case V_92 ... V_93 :
V_56 -> V_94 [ ( ( V_37 & ~ 3 ) - V_92 ) / 4 ] = V_84 ;
break;
case V_100 :
V_56 -> V_55 = ( V_84 & 0xff ) | V_83 ;
V_56 -> V_57 = ( ( V_84 >> 8 ) & 0xff ) | V_83 ;
F_27 ( V_2 ) ;
break;
case V_102 :
V_56 -> V_66 = V_84 & 0xffff ;
V_56 -> V_65 = V_84 >> 16 ;
F_29 ( V_2 ) ;
break;
case V_104 :
V_56 -> V_59 = V_84 & 0xffff ;
V_56 -> V_58 = V_84 >> 16 ;
F_27 ( V_2 ) ;
break;
case V_95 :
V_56 -> V_99 = V_84 & 0xff ;
V_56 -> V_98 = ( V_84 >> 8 ) & 0xff ;
V_56 -> V_97 = ( V_84 >> 16 ) & 0xff ;
V_56 -> V_96 = ( V_84 >> 24 ) & 0xff ;
F_7 ( V_2 , V_56 -> V_98 ) ;
break;
default:
break;
}
return V_41 ;
}
static inline struct V_109 * F_33 ( struct V_110 * V_111 )
{
return V_111 -> V_112 ;
}
static struct V_1 *
F_34 ( struct V_109 * V_51 , struct V_34 * V_35 ,
int V_36 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_51 -> V_113 ; V_17 ++ ) {
struct V_1 * V_2 = & V_51 -> V_114 [ V_17 ] ;
if ( V_35 -> V_38 == 0 && V_2 -> V_36 == V_36 )
return V_2 ;
if ( V_35 -> V_38 != 0 &&
V_35 -> V_38 >= V_2 -> V_56 . V_98 &&
V_35 -> V_38 <= V_2 -> V_56 . V_97 )
return V_2 ;
}
return NULL ;
}
static int F_35 ( struct V_34 * V_35 , T_1 V_36 ,
int V_37 , int V_16 , T_1 V_3 )
{
struct V_109 * V_51 = F_33 ( V_35 -> V_115 ) ;
struct V_1 * V_2 ;
unsigned long V_116 ;
int V_50 ;
V_2 = F_34 ( V_51 , V_35 , V_36 ) ;
if ( ! V_2 )
return V_117 ;
if ( V_35 -> V_38 == 0 )
return F_32 ( V_2 , V_37 , V_16 , V_3 ) ;
if ( ! F_6 ( V_2 ) )
return V_117 ;
if ( V_35 -> V_38 == V_2 -> V_56 . V_98 &&
F_36 ( V_36 ) != 0 )
return V_117 ;
F_37 ( & V_2 -> V_118 , V_116 ) ;
V_50 = F_21 ( V_2 , V_35 , V_36 ,
V_37 , V_16 , V_3 ) ;
F_38 ( & V_2 -> V_118 , V_116 ) ;
return V_50 ;
}
static int F_39 ( struct V_34 * V_35 , T_1 V_36 , int V_37 ,
int V_16 , T_1 * V_3 )
{
struct V_109 * V_51 = F_33 ( V_35 -> V_115 ) ;
struct V_1 * V_2 ;
unsigned long V_116 ;
int V_50 ;
V_2 = F_34 ( V_51 , V_35 , V_36 ) ;
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
if ( V_35 -> V_38 == V_2 -> V_56 . V_98 &&
F_36 ( V_36 ) != 0 ) {
* V_3 = 0xffffffff ;
return V_117 ;
}
F_37 ( & V_2 -> V_118 , V_116 ) ;
V_50 = F_19 ( V_2 , V_35 , V_36 ,
V_37 , V_16 , V_3 ) ;
F_38 ( & V_2 -> V_118 , V_116 ) ;
return V_50 ;
}
static int F_40 ( int V_10 , struct V_110 * V_111 )
{
struct V_109 * V_51 = F_33 ( V_111 ) ;
int V_17 ;
int V_119 = 0 ;
#ifdef F_41
V_119 = V_111 -> V_119 ;
#endif
snprintf ( V_51 -> V_120 , sizeof( V_51 -> V_120 ) , L_3 ,
V_119 ) ;
V_51 -> V_121 . V_122 = V_51 -> V_120 ;
snprintf ( V_51 -> V_123 , sizeof( V_51 -> V_123 ) , L_4 , V_119 ) ;
V_51 -> V_124 . V_122 = V_51 -> V_123 ;
if ( F_42 ( & V_125 , & V_51 -> V_121 ) )
return 0 ;
if ( F_43 ( & V_51 -> V_124 ) != 0 ) {
if ( F_42 ( & V_126 , & V_51 -> V_124 ) ) {
F_44 ( & V_51 -> V_121 ) ;
return 0 ;
}
F_45 ( & V_111 -> V_127 , & V_51 -> V_124 ,
V_111 -> V_128 ) ;
}
F_45 ( & V_111 -> V_127 , & V_51 -> V_121 , V_111 -> V_129 ) ;
F_46 ( & V_111 -> V_127 , & V_51 -> V_130 ) ;
for ( V_17 = 0 ; V_17 < V_51 -> V_113 ; V_17 ++ ) {
struct V_1 * V_2 = & V_51 -> V_114 [ V_17 ] ;
if ( ! V_2 -> V_5 )
continue;
F_18 ( V_2 ) ;
}
return 1 ;
}
static struct V_34 * F_47 ( int V_10 , struct V_110 * V_111 )
{
struct V_109 * V_51 = F_33 ( V_111 ) ;
struct V_34 * V_35 ;
V_35 = F_48 ( & V_51 -> V_52 -> V_53 , V_111 -> V_131 ,
& V_132 , V_111 , & V_111 -> V_127 ) ;
if ( ! V_35 )
return NULL ;
F_49 ( V_35 ) ;
return V_35 ;
}
static void F_50 ( struct V_34 * V_35 )
{
struct V_109 * V_51 = F_33 ( V_35 -> V_115 ) ;
V_35 -> V_133 = V_51 -> V_133 ;
}
static T_4 F_51 ( struct V_134 * V_53 ,
const struct V_135 * V_136 ,
T_4 V_64 ,
T_4 V_16 ,
T_4 V_137 )
{
if ( V_53 -> V_35 -> V_38 != 0 )
return V_64 ;
if ( V_136 -> V_116 & V_138 )
return F_52 ( V_64 , F_53 ( T_4 , V_139 ,
F_54 ( V_16 ) ) ) ;
else if ( V_136 -> V_116 & V_140 )
return F_52 ( V_64 , F_53 ( T_4 , V_141 ,
F_54 ( V_16 ) ) ) ;
else
return V_64 ;
}
static void F_55 ( struct V_109 * V_51 )
{
struct V_142 V_143 ;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_143 . V_144 = 1 ;
V_143 . V_112 = ( void * * ) & V_51 ;
V_143 . V_145 = F_40 ;
V_143 . V_146 = F_47 ;
V_143 . V_147 = V_148 ;
V_143 . V_149 = & V_132 ;
V_143 . V_150 = F_51 ;
V_143 . V_151 = F_50 ;
F_56 ( & V_143 ) ;
}
static void T_5 * F_57 ( struct V_152 * V_52 ,
struct V_153 * V_154 , struct V_1 * V_2 )
{
struct V_135 V_155 ;
int V_50 = 0 ;
V_50 = F_58 ( V_154 , 0 , & V_155 ) ;
if ( V_50 )
return F_59 ( V_50 ) ;
return F_60 ( & V_52 -> V_53 , & V_155 ) ;
}
static int F_61 ( struct V_153 * V_154 , int V_36 ,
unsigned long type ,
unsigned int * V_156 ,
unsigned int * V_157 )
{
const int V_158 = 3 , V_159 = 2 ;
const T_6 * V_160 ;
int V_161 , V_162 , V_163 , V_164 , V_17 ;
* V_156 = - 1 ;
* V_157 = - 1 ;
V_160 = F_62 ( V_154 , L_5 , & V_161 ) ;
if ( ! V_160 )
return - V_165 ;
V_164 = F_63 ( V_154 ) ;
V_163 = V_164 + V_158 + V_159 ;
V_162 = V_161 / sizeof( T_6 ) / V_163 ;
for ( V_17 = 0 ; V_17 < V_162 ; V_17 ++ ) {
T_1 V_116 = F_64 ( V_160 , 1 ) ;
T_1 V_166 = F_64 ( V_160 + 1 , 1 ) ;
T_7 V_167 = F_64 ( V_160 + V_158 , V_164 ) ;
unsigned long V_168 ;
if ( F_65 ( V_116 ) == V_169 )
V_168 = V_138 ;
else if ( F_65 ( V_116 ) == V_170 )
V_168 = V_140 ;
if ( V_166 == F_36 ( V_36 ) && type == V_168 ) {
* V_156 = F_66 ( V_167 ) ;
* V_157 = F_67 ( V_167 ) ;
return 0 ;
}
V_160 += V_163 ;
}
return - V_171 ;
}
static void F_68 ( struct V_109 * V_51 )
{
struct V_153 * V_172 ;
V_172 = F_69 ( V_51 -> V_52 -> V_53 . V_173 ,
L_6 , 0 ) ;
if ( ! V_172 )
return;
V_51 -> V_133 = F_70 ( V_172 ) ;
if ( V_51 -> V_133 )
V_51 -> V_133 -> V_53 = & V_51 -> V_52 -> V_53 ;
}
static int F_71 ( struct V_152 * V_52 )
{
struct V_109 * V_51 ;
struct V_153 * V_154 = V_52 -> V_53 . V_173 ;
struct V_153 * V_174 ;
int V_17 , V_50 ;
V_51 = F_72 ( & V_52 -> V_53 , sizeof( struct V_109 ) ,
V_175 ) ;
if ( ! V_51 )
return - V_176 ;
V_51 -> V_52 = V_52 ;
F_73 ( V_52 , V_51 ) ;
F_74 ( & V_51 -> V_121 ) ;
if ( F_43 ( & V_51 -> V_121 ) == 0 ) {
F_26 ( & V_52 -> V_53 , L_7 ) ;
return - V_165 ;
}
F_75 ( & V_51 -> V_63 ) ;
if ( F_43 ( & V_51 -> V_63 ) != 0 ) {
V_51 -> V_124 . V_116 = V_51 -> V_63 . V_116 ;
V_51 -> V_124 . V_64 = V_177 ;
V_51 -> V_124 . V_178 = F_76 ( T_4 ,
V_179 ,
F_43 ( & V_51 -> V_63 ) ) ;
} else
V_51 -> V_124 = V_51 -> V_63 ;
V_50 = F_77 ( V_154 , & V_51 -> V_130 ) ;
if ( V_50 ) {
F_26 ( & V_52 -> V_53 , L_8 ,
V_50 ) ;
return V_50 ;
}
V_17 = 0 ;
F_78 (pdev->dev.of_node, child) {
if ( ! F_79 ( V_174 ) )
continue;
V_17 ++ ;
}
V_51 -> V_114 = F_72 ( & V_52 -> V_53 , V_17 *
sizeof( struct V_1 ) ,
V_175 ) ;
if ( ! V_51 -> V_114 )
return - V_176 ;
V_17 = 0 ;
F_78 (pdev->dev.of_node, child) {
struct V_1 * V_2 = & V_51 -> V_114 [ V_17 ] ;
enum V_180 V_116 ;
if ( ! F_79 ( V_174 ) )
continue;
V_2 -> V_51 = V_51 ;
if ( F_80 ( V_174 , L_9 ,
& V_2 -> V_2 ) ) {
F_81 ( & V_52 -> V_53 ,
L_10 ) ;
continue;
}
if ( F_80 ( V_174 , L_11 ,
& V_2 -> V_181 ) )
V_2 -> V_181 = 0 ;
V_2 -> V_122 = F_82 ( V_175 , L_12 ,
V_2 -> V_2 , V_2 -> V_181 ) ;
V_2 -> V_36 = F_83 ( V_174 ) ;
if ( V_2 -> V_36 < 0 )
continue;
V_50 = F_61 ( V_154 , V_2 -> V_36 , V_140 ,
& V_2 -> V_69 , & V_2 -> V_70 ) ;
if ( V_50 < 0 ) {
F_26 ( & V_52 -> V_53 , L_13 ,
V_2 -> V_2 , V_2 -> V_181 ) ;
continue;
}
if ( F_43 ( & V_51 -> V_63 ) != 0 )
F_61 ( V_154 , V_2 -> V_36 , V_138 ,
& V_2 -> V_6 , & V_2 -> V_7 ) ;
else {
V_2 -> V_6 = - 1 ;
V_2 -> V_7 = - 1 ;
}
V_2 -> V_182 = F_84 ( V_174 ,
L_14 , 0 , & V_116 ) ;
if ( F_85 ( V_2 -> V_182 ) ) {
T_1 V_183 = 20000 ;
V_2 -> V_184 = V_116 & V_185 ;
V_2 -> V_186 = F_82 ( V_175 ,
L_15 , V_2 -> V_2 , V_2 -> V_181 ) ;
F_80 ( V_174 , L_16 ,
& V_183 ) ;
V_50 = F_86 ( & V_52 -> V_53 ,
V_2 -> V_182 , V_187 , V_2 -> V_186 ) ;
if ( V_50 ) {
if ( V_50 == - V_188 )
return V_50 ;
continue;
}
F_87 ( V_2 -> V_182 ,
( V_2 -> V_184 ) ? 1 : 0 ) ;
F_88 ( V_183 / 1000 ) ;
}
V_2 -> V_189 = F_89 ( V_174 , NULL ) ;
if ( F_90 ( V_2 -> V_189 ) ) {
F_26 ( & V_52 -> V_53 , L_17 ,
V_2 -> V_2 , V_2 -> V_181 ) ;
continue;
}
V_50 = F_91 ( V_2 -> V_189 ) ;
if ( V_50 )
continue;
V_2 -> V_5 = F_57 ( V_52 , V_174 , V_2 ) ;
if ( F_90 ( V_2 -> V_5 ) ) {
F_26 ( & V_52 -> V_53 , L_18 ,
V_2 -> V_2 , V_2 -> V_181 ) ;
V_2 -> V_5 = NULL ;
F_92 ( V_2 -> V_189 ) ;
continue;
}
F_8 ( V_2 , 1 ) ;
V_2 -> V_190 = V_174 ;
F_93 ( & V_2 -> V_118 ) ;
F_30 ( V_2 ) ;
V_17 ++ ;
}
V_51 -> V_113 = V_17 ;
for ( V_17 = 0 ; V_17 < ( V_179 - V_139 ) ; V_17 += V_139 )
F_94 ( V_17 , V_51 -> V_63 . V_64 + V_17 ) ;
F_68 ( V_51 ) ;
F_55 ( V_51 ) ;
return 0 ;
}
