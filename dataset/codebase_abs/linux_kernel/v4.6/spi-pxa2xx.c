static inline const struct V_1
* F_1 ( const struct V_2 * V_3 )
{
return & V_4 [ V_3 -> V_5 - V_6 ] ;
}
static bool F_2 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return true ;
default:
return false ;
}
}
static bool F_3 ( const struct V_2 * V_3 )
{
return V_3 -> V_5 == V_11 ;
}
static T_1 F_4 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_11 :
return V_12 ;
default:
return V_13 ;
}
}
static T_1
F_5 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_11 :
return V_14 ;
default:
return V_15 ;
}
}
static bool F_6 ( const struct V_2 * V_3 )
{
T_1 V_16 ;
switch ( V_3 -> V_5 ) {
case V_11 :
V_16 = V_17 ;
break;
default:
V_16 = V_18 ;
break;
}
return ( F_7 ( V_3 , V_19 ) & V_16 ) == V_16 ;
}
static void F_8 ( const struct V_2 * V_3 ,
T_1 * V_20 )
{
T_1 V_16 ;
switch ( V_3 -> V_5 ) {
case V_11 :
V_16 = V_21 ;
break;
default:
V_16 = V_22 ;
break;
}
* V_20 &= ~ V_16 ;
}
static void F_9 ( const struct V_2 * V_3 ,
T_1 * V_20 , T_1 V_23 )
{
switch ( V_3 -> V_5 ) {
case V_11 :
* V_20 |= F_10 ( V_23 ) ;
break;
default:
* V_20 |= F_11 ( V_23 ) ;
break;
}
}
static T_1 F_12 ( const struct V_2 * V_3 ,
T_1 V_24 , T_2 V_25 )
{
switch ( V_3 -> V_5 ) {
case V_11 :
return V_24
| V_26
| F_13 ( V_25 > 32 ? 8 : V_25 )
| V_27 ;
default:
return V_24
| V_28
| F_14 ( V_25 > 16 ? V_25 - 16 : V_25 )
| V_27
| ( V_25 > 16 ? V_29 : 0 ) ;
}
}
static T_1 F_15 ( struct V_2 * V_3 , unsigned V_30 )
{
F_16 ( ! V_3 -> V_31 ) ;
return F_17 ( V_3 -> V_31 + V_30 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
unsigned V_30 , T_1 V_32 )
{
F_16 ( ! V_3 -> V_31 ) ;
F_19 ( V_32 , V_3 -> V_31 + V_30 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
const struct V_1 * V_33 ;
T_1 V_32 ;
V_33 = F_1 ( V_3 ) ;
V_3 -> V_31 = V_3 -> V_34 + V_33 -> V_30 ;
V_32 = F_15 ( V_3 , V_33 -> V_35 ) ;
V_32 &= ~ ( V_36 | V_37 ) ;
V_32 |= V_36 | V_37 ;
F_18 ( V_3 , V_33 -> V_35 , V_32 ) ;
if ( V_3 -> V_38 -> V_39 ) {
F_18 ( V_3 , V_33 -> V_40 , 1 ) ;
if ( V_33 -> V_41 >= 0 ) {
V_32 = F_15 ( V_3 ,
V_33 -> V_41 ) ;
V_32 |= V_42 ;
F_18 ( V_3 ,
V_33 -> V_41 , V_32 ) ;
}
}
}
static void F_21 ( struct V_2 * V_3 ,
const struct V_1 * V_33 )
{
T_1 V_32 , V_43 ;
if ( ! V_33 -> V_44 )
return;
V_32 = F_15 ( V_3 , V_33 -> V_35 ) ;
V_43 = V_3 -> V_45 -> V_46 -> V_47 ;
V_43 <<= V_33 -> V_48 ;
if ( V_43 != ( V_32 & V_33 -> V_44 ) ) {
V_32 &= ~ V_33 -> V_44 ;
V_32 |= V_43 ;
F_18 ( V_3 ,
V_33 -> V_35 , V_32 ) ;
F_22 ( 1000000000 /
( V_3 -> V_49 -> V_50 / 2 ) ) ;
}
}
static void F_23 ( struct V_2 * V_3 , bool V_51 )
{
const struct V_1 * V_33 ;
T_1 V_32 ;
V_33 = F_1 ( V_3 ) ;
if ( V_51 )
F_21 ( V_3 , V_33 ) ;
V_32 = F_15 ( V_3 , V_33 -> V_35 ) ;
if ( V_51 )
V_32 &= ~ V_37 ;
else
V_32 |= V_37 ;
F_18 ( V_3 , V_33 -> V_35 , V_32 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_52 * V_53 = V_3 -> V_54 ;
if ( V_3 -> V_5 == V_55 ) {
F_25 ( V_3 , V_19 , V_3 -> V_54 -> V_56 ) ;
return;
}
if ( V_53 -> V_57 ) {
V_53 -> V_57 ( V_58 ) ;
return;
}
if ( F_26 ( V_53 -> V_59 ) ) {
F_27 ( V_53 -> V_59 , V_53 -> V_60 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_23 ( V_3 , true ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_52 * V_53 = V_3 -> V_54 ;
if ( V_3 -> V_5 == V_55 )
return;
if ( V_53 -> V_57 ) {
V_53 -> V_57 ( V_61 ) ;
return;
}
if ( F_26 ( V_53 -> V_59 ) ) {
F_27 ( V_53 -> V_59 , ! V_53 -> V_60 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_23 ( V_3 , false ) ;
}
int F_29 ( struct V_2 * V_3 )
{
unsigned long V_62 = V_63 << 1 ;
do {
while ( F_7 ( V_3 , V_19 ) & V_64 )
F_7 ( V_3 , V_65 ) ;
} while ( ( F_7 ( V_3 , V_19 ) & V_66 ) && -- V_62 );
F_30 ( V_3 , V_67 ) ;
return V_62 ;
}
static int F_31 ( struct V_2 * V_3 )
{
T_2 V_68 = V_3 -> V_68 ;
if ( F_6 ( V_3 )
|| ( V_3 -> V_69 == V_3 -> V_70 ) )
return 0 ;
F_25 ( V_3 , V_65 , 0 ) ;
V_3 -> V_69 += V_68 ;
return 1 ;
}
static int F_32 ( struct V_2 * V_3 )
{
T_2 V_68 = V_3 -> V_68 ;
while ( ( F_7 ( V_3 , V_19 ) & V_64 )
&& ( V_3 -> V_71 < V_3 -> V_72 ) ) {
F_7 ( V_3 , V_65 ) ;
V_3 -> V_71 += V_68 ;
}
return V_3 -> V_71 == V_3 -> V_72 ;
}
static int F_33 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_69 == V_3 -> V_70 ) )
return 0 ;
F_25 ( V_3 , V_65 , * ( T_2 * ) ( V_3 -> V_69 ) ) ;
++ V_3 -> V_69 ;
return 1 ;
}
static int F_34 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_19 ) & V_64 )
&& ( V_3 -> V_71 < V_3 -> V_72 ) ) {
* ( T_2 * ) ( V_3 -> V_71 ) = F_7 ( V_3 , V_65 ) ;
++ V_3 -> V_71 ;
}
return V_3 -> V_71 == V_3 -> V_72 ;
}
static int F_35 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_69 == V_3 -> V_70 ) )
return 0 ;
F_25 ( V_3 , V_65 , * ( V_73 * ) ( V_3 -> V_69 ) ) ;
V_3 -> V_69 += 2 ;
return 1 ;
}
static int F_36 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_19 ) & V_64 )
&& ( V_3 -> V_71 < V_3 -> V_72 ) ) {
* ( V_73 * ) ( V_3 -> V_71 ) = F_7 ( V_3 , V_65 ) ;
V_3 -> V_71 += 2 ;
}
return V_3 -> V_71 == V_3 -> V_72 ;
}
static int F_37 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_69 == V_3 -> V_70 ) )
return 0 ;
F_25 ( V_3 , V_65 , * ( T_1 * ) ( V_3 -> V_69 ) ) ;
V_3 -> V_69 += 4 ;
return 1 ;
}
static int F_38 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_19 ) & V_64 )
&& ( V_3 -> V_71 < V_3 -> V_72 ) ) {
* ( T_1 * ) ( V_3 -> V_71 ) = F_7 ( V_3 , V_65 ) ;
V_3 -> V_71 += 4 ;
}
return V_3 -> V_71 == V_3 -> V_72 ;
}
void * F_39 ( struct V_2 * V_3 )
{
struct V_74 * V_75 = V_3 -> V_45 ;
struct V_76 * V_77 = V_3 -> V_78 ;
if ( V_77 -> V_79 . V_80 != & V_75 -> V_81 ) {
V_3 -> V_78 =
F_40 ( V_77 -> V_79 . V_80 ,
struct V_76 ,
V_79 ) ;
return V_82 ;
} else
return V_83 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_76 * V_84 ;
struct V_74 * V_75 ;
unsigned long V_85 ;
V_75 = V_3 -> V_45 ;
V_3 -> V_45 = NULL ;
V_3 -> V_78 = NULL ;
V_84 = F_42 ( & V_75 -> V_81 , struct V_76 ,
V_79 ) ;
if ( V_84 -> V_86 )
F_43 ( V_84 -> V_86 ) ;
V_85 = V_87 + F_44 ( 10 ) ;
while ( F_7 ( V_3 , V_19 ) & V_66 &&
! F_45 ( V_87 , V_85 ) )
F_46 () ;
if ( ! V_84 -> V_88 )
F_28 ( V_3 ) ;
else {
struct V_74 * V_89 ;
V_89 = F_47 ( V_3 -> V_49 ) ;
if ( V_89 && V_89 -> V_46 != V_75 -> V_46 )
V_89 = NULL ;
if ( ! V_89 || V_75 -> V_90 == V_91 )
F_28 ( V_3 ) ;
}
V_3 -> V_54 = NULL ;
F_48 ( V_3 -> V_49 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_52 * V_53 = V_3 -> V_54 ;
T_1 V_20 ;
V_20 = F_7 ( V_3 , V_92 ) & ~ V_3 -> V_93 ;
V_20 &= ~ V_22 ;
V_20 |= V_53 -> V_23 ;
F_25 ( V_3 , V_92 , V_20 ) ;
}
static void F_50 ( struct V_2 * V_3 , const char * V_75 )
{
F_30 ( V_3 , V_3 -> V_94 ) ;
F_49 ( V_3 ) ;
if ( ! F_51 ( V_3 ) )
F_25 ( V_3 , V_95 , 0 ) ;
F_29 ( V_3 ) ;
F_25 ( V_3 , V_96 ,
F_7 ( V_3 , V_96 ) & ~ V_27 ) ;
F_52 ( & V_3 -> V_97 -> V_98 , L_1 , V_75 ) ;
V_3 -> V_45 -> V_90 = V_91 ;
F_53 ( & V_3 -> V_99 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
F_30 ( V_3 , V_3 -> V_94 ) ;
F_49 ( V_3 ) ;
if ( ! F_51 ( V_3 ) )
F_25 ( V_3 , V_95 , 0 ) ;
V_3 -> V_45 -> V_100 += V_3 -> V_101 -
( V_3 -> V_72 - V_3 -> V_71 ) ;
V_3 -> V_45 -> V_90 = F_39 ( V_3 ) ;
F_53 ( & V_3 -> V_99 ) ;
}
static T_3 F_55 ( struct V_2 * V_3 )
{
T_1 V_102 = ( F_7 ( V_3 , V_92 ) & V_103 ) ?
V_3 -> V_104 : V_3 -> V_104 & ~ V_105 ;
T_1 V_106 = F_7 ( V_3 , V_19 ) & V_102 ;
if ( V_106 & V_67 ) {
F_50 ( V_3 , L_2 ) ;
return V_107 ;
}
if ( V_106 & V_108 ) {
F_25 ( V_3 , V_19 , V_108 ) ;
if ( V_3 -> V_109 ( V_3 ) ) {
F_54 ( V_3 ) ;
return V_107 ;
}
}
do {
if ( V_3 -> V_109 ( V_3 ) ) {
F_54 ( V_3 ) ;
return V_107 ;
}
} while ( V_3 -> V_110 ( V_3 ) );
if ( V_3 -> V_109 ( V_3 ) ) {
F_54 ( V_3 ) ;
return V_107 ;
}
if ( V_3 -> V_69 == V_3 -> V_70 ) {
T_1 V_111 ;
T_1 V_20 ;
V_20 = F_7 ( V_3 , V_92 ) ;
V_20 &= ~ V_103 ;
if ( F_51 ( V_3 ) ) {
T_1 V_112 ;
F_8 ( V_3 , & V_20 ) ;
V_111 = V_3 -> V_72 - V_3 -> V_71 ;
switch ( V_3 -> V_68 ) {
case 4 :
V_111 >>= 1 ;
case 2 :
V_111 >>= 1 ;
}
V_112 = F_5 ( V_3 ) ;
if ( V_112 > V_111 )
V_112 = V_111 ;
F_9 ( V_3 , & V_20 , V_112 ) ;
}
F_25 ( V_3 , V_92 , V_20 ) ;
}
return V_107 ;
}
static T_3 F_56 ( int V_113 , void * V_114 )
{
struct V_2 * V_3 = V_114 ;
T_1 V_20 ;
T_1 V_16 = V_3 -> V_104 ;
T_1 V_115 ;
if ( F_57 ( & V_3 -> V_97 -> V_98 ) )
return V_116 ;
V_115 = F_7 ( V_3 , V_19 ) ;
if ( V_115 == ~ 0 )
return V_116 ;
V_20 = F_7 ( V_3 , V_92 ) ;
if ( ! ( V_20 & V_103 ) )
V_16 &= ~ V_105 ;
if ( ! ( V_20 & V_117 ) )
V_16 &= ~ V_108 ;
if ( ! ( V_115 & V_16 ) )
return V_116 ;
if ( ! V_3 -> V_45 ) {
F_25 ( V_3 , V_96 ,
F_7 ( V_3 , V_96 )
& ~ V_27 ) ;
F_25 ( V_3 , V_92 ,
F_7 ( V_3 , V_92 )
& ~ V_3 -> V_93 ) ;
if ( ! F_51 ( V_3 ) )
F_25 ( V_3 , V_95 , 0 ) ;
F_30 ( V_3 , V_3 -> V_94 ) ;
F_52 ( & V_3 -> V_97 -> V_98 ,
L_3 ) ;
return V_107 ;
}
return V_3 -> V_118 ( V_3 ) ;
}
static unsigned int F_58 ( int V_119 , T_1 * V_120 )
{
unsigned long V_121 = 200000000 ;
unsigned long V_122 = V_121 / 2 ;
unsigned long V_123 = V_122 / 2 ;
unsigned long V_124 = V_122 * 2 / 5 ;
unsigned long V_125 ;
unsigned long V_126 , V_127 , V_128 ;
long V_129 , V_130 , V_131 ;
T_1 V_132 ;
V_132 = ( 1 << 24 ) >> 1 ;
V_127 = F_59 ( V_123 , V_119 ) ;
if ( V_127 > 256 ) {
V_125 = F_60 ( V_127 - 1 ) ;
if ( V_125 > 9 ) {
V_127 >>= V_125 - 9 ;
V_132 >>= V_125 - 9 ;
}
V_127 += V_127 & 1 ;
}
V_125 = F_61 ( V_127 ) ;
V_127 >>= V_125 ;
V_132 >>= V_125 ;
V_130 = abs ( V_123 / ( 1 << ( 24 - F_60 ( V_132 ) ) ) / V_127 - V_119 ) ;
V_128 = F_59 ( V_124 , V_119 ) ;
V_131 = abs ( V_124 / V_128 - V_119 ) ;
if ( V_131 >= V_130 || V_128 > 256 ) {
V_129 = V_130 ;
V_126 = V_127 ;
} else {
V_129 = V_131 ;
V_126 = V_128 ;
V_132 = ( 1 << 24 ) * 2 / 5 ;
}
if ( V_122 / V_119 >= 80 ) {
T_4 V_133 ;
T_1 V_134 ;
V_127 = F_59 ( V_122 , V_119 ) ;
V_134 = ( 1 << 24 ) / V_127 ;
V_133 = ( T_4 ) V_122 * V_134 ;
F_62 ( V_133 , 1 << 24 ) ;
V_130 = abs ( V_133 - V_119 ) ;
if ( V_130 < V_129 ) {
V_126 = 1 ;
V_132 = V_134 ;
}
}
* V_120 = V_132 ;
return V_126 - 1 ;
}
static unsigned int F_63 ( struct V_2 * V_3 , int V_119 )
{
unsigned long V_135 = V_3 -> V_49 -> V_50 ;
const struct V_136 * V_137 = V_3 -> V_137 ;
V_119 = F_64 ( int , V_135 , V_119 ) ;
if ( V_137 -> type == V_138 || V_137 -> type == V_55 )
return ( V_135 / ( 2 * V_119 ) - 1 ) & 0xff ;
else
return ( V_135 / V_119 - 1 ) & 0xfff ;
}
static unsigned int F_65 ( struct V_2 * V_3 ,
int V_119 )
{
struct V_52 * V_53 = V_3 -> V_54 ;
unsigned int V_24 ;
switch ( V_3 -> V_5 ) {
case V_11 :
V_24 = F_58 ( V_119 , & V_53 -> V_139 ) ;
break;
default:
V_24 = F_63 ( V_3 , V_119 ) ;
break;
}
return V_24 << 8 ;
}
static void V_99 ( unsigned long V_140 )
{
struct V_2 * V_3 = (struct V_2 * ) V_140 ;
struct V_74 * V_141 = NULL ;
struct V_76 * V_142 = NULL ;
struct V_76 * V_143 = NULL ;
struct V_52 * V_53 = NULL ;
T_1 V_24 = 0 ;
T_2 V_25 = 0 ;
T_1 V_144 = 0 ;
T_1 V_145 ;
T_1 V_146 ;
T_1 V_147 = V_3 -> V_54 -> V_148 ;
T_1 V_149 = V_3 -> V_54 -> V_150 ;
T_1 V_151 = F_4 ( V_3 ) ;
V_141 = V_3 -> V_45 ;
V_142 = V_3 -> V_78 ;
V_53 = V_3 -> V_54 ;
if ( V_141 -> V_90 == V_91 ) {
V_141 -> V_115 = - V_152 ;
F_41 ( V_3 ) ;
return;
}
if ( V_141 -> V_90 == V_83 ) {
V_141 -> V_115 = 0 ;
F_41 ( V_3 ) ;
return;
}
if ( V_141 -> V_90 == V_82 ) {
V_143 = F_40 ( V_142 -> V_79 . V_153 ,
struct V_76 ,
V_79 ) ;
if ( V_143 -> V_86 )
F_43 ( V_143 -> V_86 ) ;
if ( V_143 -> V_88 )
F_28 ( V_3 ) ;
}
if ( ! F_66 ( V_142 -> V_101 ) && V_53 -> V_39 ) {
if ( V_141 -> V_154
|| V_142 -> V_155 || V_142 -> V_156 ) {
F_52 ( & V_3 -> V_97 -> V_98 ,
L_4
L_5 ,
V_142 -> V_101 , V_157 ) ;
V_141 -> V_115 = - V_158 ;
F_41 ( V_3 ) ;
return;
}
F_67 ( & V_141 -> V_46 -> V_98 ,
L_6
L_7 ,
( long ) V_3 -> V_101 , V_157 ) ;
}
if ( F_29 ( V_3 ) == 0 ) {
F_52 ( & V_3 -> V_97 -> V_98 , L_8 ) ;
V_141 -> V_115 = - V_152 ;
F_41 ( V_3 ) ;
return;
}
V_3 -> V_68 = V_53 -> V_68 ;
V_3 -> V_69 = ( void * ) V_142 -> V_159 ;
V_3 -> V_70 = V_3 -> V_69 + V_142 -> V_101 ;
V_3 -> V_71 = V_142 -> V_160 ;
V_3 -> V_72 = V_3 -> V_71 + V_142 -> V_101 ;
V_3 -> V_101 = V_142 -> V_101 ;
V_3 -> V_110 = V_3 -> V_69 ? V_53 -> V_110 : F_31 ;
V_3 -> V_109 = V_3 -> V_71 ? V_53 -> V_109 : F_32 ;
V_25 = V_142 -> V_161 ;
V_144 = V_142 -> V_162 ;
V_24 = F_65 ( V_3 , V_144 ) ;
if ( V_25 <= 8 ) {
V_3 -> V_68 = 1 ;
V_3 -> V_109 = V_3 -> V_109 != F_32 ?
F_34 : F_32 ;
V_3 -> V_110 = V_3 -> V_110 != F_31 ?
F_33 : F_31 ;
} else if ( V_25 <= 16 ) {
V_3 -> V_68 = 2 ;
V_3 -> V_109 = V_3 -> V_109 != F_32 ?
F_36 : F_32 ;
V_3 -> V_110 = V_3 -> V_110 != F_31 ?
F_35 : F_31 ;
} else if ( V_25 <= 32 ) {
V_3 -> V_68 = 4 ;
V_3 -> V_109 = V_3 -> V_109 != F_32 ?
F_38 : F_32 ;
V_3 -> V_110 = V_3 -> V_110 != F_31 ?
F_37 : F_31 ;
}
if ( V_53 -> V_39 ) {
if ( F_68 ( V_53 ,
V_141 -> V_46 ,
V_25 , & V_149 ,
& V_147 ) )
F_67 ( & V_141 -> V_46 -> V_98 ,
L_9 ) ;
}
V_141 -> V_90 = V_82 ;
V_3 -> V_163 = 0 ;
if ( F_66 ( V_3 -> V_101 ) )
V_3 -> V_163 = F_69 ( V_3 ) ;
if ( V_3 -> V_163 ) {
V_3 -> V_118 = V_164 ;
F_70 ( V_3 , V_149 ) ;
V_146 = V_53 -> V_146 | V_147 | V_3 -> V_165 ;
F_25 ( V_3 , V_19 , V_3 -> V_94 ) ;
F_71 ( V_3 ) ;
} else {
V_3 -> V_118 = F_55 ;
V_146 = V_53 -> V_146 | V_53 -> V_23 | V_3 -> V_93 ;
F_30 ( V_3 , V_3 -> V_94 ) ;
}
V_145 = F_12 ( V_3 , V_24 , V_25 ) ;
if ( ! F_51 ( V_3 ) )
F_72 ( & V_141 -> V_46 -> V_98 , L_10 ,
V_3 -> V_49 -> V_50
/ ( 1 + ( ( V_145 & F_73 ( 0xfff ) ) >> 8 ) ) ,
V_3 -> V_163 ? L_11 : L_12 ) ;
else
F_72 ( & V_141 -> V_46 -> V_98 , L_10 ,
V_3 -> V_49 -> V_50 / 2
/ ( 1 + ( ( V_145 & F_73 ( 0x0ff ) ) >> 8 ) ) ,
V_3 -> V_163 ? L_11 : L_12 ) ;
if ( F_2 ( V_3 ) ) {
if ( ( F_7 ( V_3 , V_166 ) & 0xff )
!= V_53 -> V_167 )
F_25 ( V_3 , V_166 ,
V_53 -> V_167 ) ;
if ( ( F_7 ( V_3 , V_168 ) & 0xffff )
!= V_53 -> V_169 )
F_25 ( V_3 , V_168 ,
V_53 -> V_169 ) ;
}
if ( F_3 ( V_3 ) &&
( F_7 ( V_3 , V_170 ) != V_53 -> V_139 ) )
F_25 ( V_3 , V_170 , V_53 -> V_139 ) ;
if ( ( F_7 ( V_3 , V_96 ) != V_145 )
|| ( F_7 ( V_3 , V_92 ) & V_151 )
!= ( V_146 & V_151 ) ) {
F_25 ( V_3 , V_96 , V_145 & ~ V_27 ) ;
if ( ! F_51 ( V_3 ) )
F_25 ( V_3 , V_95 , V_53 -> V_85 ) ;
F_25 ( V_3 , V_92 , V_146 & V_151 ) ;
F_25 ( V_3 , V_96 , V_145 ) ;
} else {
if ( ! F_51 ( V_3 ) )
F_25 ( V_3 , V_95 , V_53 -> V_85 ) ;
}
F_24 ( V_3 ) ;
F_25 ( V_3 , V_92 , V_146 ) ;
}
static int F_74 ( struct V_171 * V_49 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_75 ( V_49 ) ;
V_3 -> V_45 = V_75 ;
V_3 -> V_45 -> V_90 = V_172 ;
V_3 -> V_78 = F_40 ( V_3 -> V_45 -> V_81 . V_80 ,
struct V_76 ,
V_79 ) ;
V_3 -> V_54 = F_76 ( V_3 -> V_45 -> V_46 ) ;
F_53 ( & V_3 -> V_99 ) ;
return 0 ;
}
static int F_77 ( struct V_171 * V_49 )
{
struct V_2 * V_3 = F_75 ( V_49 ) ;
F_25 ( V_3 , V_96 ,
F_7 ( V_3 , V_96 ) & ~ V_27 ) ;
return 0 ;
}
static int F_78 ( struct V_173 * V_46 , struct V_52 * V_53 ,
struct V_174 * V_175 )
{
int V_176 = 0 ;
if ( V_53 == NULL || V_175 == NULL )
return 0 ;
if ( F_26 ( V_53 -> V_59 ) )
F_79 ( V_53 -> V_59 ) ;
if ( V_175 -> V_57 ) {
V_53 -> V_57 = V_175 -> V_57 ;
return 0 ;
}
if ( F_26 ( V_175 -> V_59 ) ) {
V_176 = F_80 ( V_175 -> V_59 , L_13 ) ;
if ( V_176 ) {
F_52 ( & V_46 -> V_98 , L_14 ,
V_175 -> V_59 ) ;
return V_176 ;
}
V_53 -> V_59 = V_175 -> V_59 ;
V_53 -> V_60 = V_46 -> V_177 & V_178 ;
V_176 = F_81 ( V_53 -> V_59 ,
! V_53 -> V_60 ) ;
}
return V_176 ;
}
static int F_82 ( struct V_173 * V_46 )
{
struct V_174 * V_175 = NULL ;
struct V_52 * V_53 ;
const struct V_1 * V_33 ;
struct V_2 * V_3 = F_75 ( V_46 -> V_49 ) ;
T_5 V_179 , V_180 , V_181 ;
switch ( V_3 -> V_5 ) {
case V_11 :
V_179 = V_182 ;
V_180 = 0 ;
V_181 = V_14 ;
break;
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
V_33 = F_1 ( V_3 ) ;
V_179 = V_33 -> V_183 ;
V_180 = V_33 -> V_184 ;
V_181 = V_33 -> V_185 ;
break;
default:
V_179 = V_186 ;
V_180 = 0 ;
V_181 = V_15 ;
break;
}
V_53 = F_76 ( V_46 ) ;
if ( ! V_53 ) {
V_53 = F_83 ( sizeof( struct V_52 ) , V_187 ) ;
if ( ! V_53 )
return - V_188 ;
if ( V_3 -> V_5 == V_55 ) {
if ( V_46 -> V_47 > 4 ) {
F_52 ( & V_46 -> V_98 ,
L_15 ) ;
F_84 ( V_53 ) ;
return - V_158 ;
}
V_53 -> V_56 = V_46 -> V_47 ;
} else
V_53 -> V_59 = - 1 ;
V_53 -> V_39 = 0 ;
V_53 -> V_85 = V_189 ;
}
V_175 = V_46 -> V_190 ;
V_53 -> V_146 = 0 ;
if ( V_175 ) {
if ( V_175 -> V_85 )
V_53 -> V_85 = V_175 -> V_85 ;
if ( V_175 -> V_191 )
V_179 = V_175 -> V_191 ;
if ( V_175 -> V_192 )
V_180 = V_175 -> V_192 ;
if ( V_175 -> V_185 )
V_181 = V_175 -> V_185 ;
V_53 -> V_39 = V_3 -> V_38 -> V_39 ;
V_53 -> V_148 = 0 ;
if ( V_175 -> V_193 )
V_53 -> V_146 = V_194 ;
} else if ( F_85 ( & V_46 -> V_98 ) ) {
V_53 -> V_39 = V_3 -> V_38 -> V_39 ;
}
V_53 -> V_167 = F_86 ( V_181 ) ;
V_53 -> V_169 = F_87 ( V_179 )
| F_88 ( V_180 ) ;
if ( V_53 -> V_39 ) {
if ( F_68 ( V_53 , V_46 ,
V_46 -> V_161 ,
& V_53 -> V_150 ,
& V_53 -> V_148 ) ) {
F_89 ( & V_46 -> V_98 ,
L_16 ) ;
}
}
switch ( V_3 -> V_5 ) {
case V_11 :
V_53 -> V_23 = ( F_10 ( V_181 )
& V_21 )
| ( F_90 ( V_179 )
& V_195 ) ;
break;
default:
V_53 -> V_23 = ( F_11 ( V_181 ) & V_22 ) |
( F_91 ( V_179 ) & V_196 ) ;
break;
}
V_53 -> V_146 &= ~ ( V_197 | V_198 ) ;
V_53 -> V_146 |= ( ( ( V_46 -> V_177 & V_199 ) != 0 ) ? V_198 : 0 )
| ( ( ( V_46 -> V_177 & V_200 ) != 0 ) ? V_197 : 0 ) ;
if ( V_46 -> V_177 & V_201 )
V_53 -> V_146 |= V_194 ;
if ( V_46 -> V_161 <= 8 ) {
V_53 -> V_68 = 1 ;
V_53 -> V_109 = F_34 ;
V_53 -> V_110 = F_33 ;
} else if ( V_46 -> V_161 <= 16 ) {
V_53 -> V_68 = 2 ;
V_53 -> V_109 = F_36 ;
V_53 -> V_110 = F_35 ;
} else if ( V_46 -> V_161 <= 32 ) {
V_53 -> V_68 = 4 ;
V_53 -> V_109 = F_38 ;
V_53 -> V_110 = F_37 ;
}
F_92 ( V_46 , V_53 ) ;
if ( V_3 -> V_5 == V_55 )
return 0 ;
return F_78 ( V_46 , V_53 , V_175 ) ;
}
static void F_93 ( struct V_173 * V_46 )
{
struct V_52 * V_53 = F_76 ( V_46 ) ;
struct V_2 * V_3 = F_75 ( V_46 -> V_49 ) ;
if ( ! V_53 )
return;
if ( V_3 -> V_5 != V_55 && F_26 ( V_53 -> V_59 ) )
F_79 ( V_53 -> V_59 ) ;
F_84 ( V_53 ) ;
}
static int F_94 ( struct V_202 * V_203 )
{
unsigned int V_204 ;
int V_205 = - 1 ;
if ( V_203 && V_203 -> V_206 . V_207 &&
! F_95 ( V_203 -> V_206 . V_207 , 0 , & V_204 ) )
V_205 = V_204 ;
return V_205 ;
}
static int F_94 ( struct V_202 * V_203 )
{
return - 1 ;
}
static bool F_96 ( struct V_208 * V_209 , void * V_210 )
{
struct V_211 * V_98 = V_210 ;
if ( V_98 != V_209 -> V_211 -> V_98 -> V_212 )
return false ;
return true ;
}
static struct V_213 *
F_97 ( struct V_214 * V_97 )
{
struct V_213 * V_215 ;
struct V_202 * V_203 ;
struct V_136 * V_137 ;
struct V_216 * V_217 ;
const struct V_218 * V_219 = NULL ;
const struct V_220 * V_221 = NULL ;
int type ;
V_203 = F_98 ( & V_97 -> V_98 ) ;
if ( F_99 ( V_97 -> V_98 . V_212 ) )
V_221 = F_100 ( V_222 ,
F_101 ( V_97 -> V_98 . V_212 ) ) ;
else if ( V_203 )
V_219 = F_102 ( V_97 -> V_98 . V_223 -> V_224 ,
& V_97 -> V_98 ) ;
else
return NULL ;
if ( V_219 )
type = ( int ) V_219 -> V_2 ;
else if ( V_221 )
type = ( int ) V_221 -> V_2 ;
else
return NULL ;
V_215 = F_103 ( & V_97 -> V_98 , sizeof( * V_215 ) , V_187 ) ;
if ( ! V_215 )
return NULL ;
V_217 = F_104 ( V_97 , V_225 , 0 ) ;
if ( ! V_217 )
return NULL ;
V_137 = & V_215 -> V_137 ;
V_137 -> V_226 = V_217 -> V_227 ;
V_137 -> V_228 = F_105 ( & V_97 -> V_98 , V_217 ) ;
if ( F_106 ( V_137 -> V_228 ) )
return NULL ;
if ( V_221 ) {
V_215 -> V_229 = V_97 -> V_98 . V_212 ;
V_215 -> V_230 = V_97 -> V_98 . V_212 ;
V_215 -> V_231 = F_96 ;
}
V_137 -> V_232 = F_107 ( & V_97 -> V_98 , NULL ) ;
V_137 -> V_113 = F_108 ( V_97 , 0 ) ;
V_137 -> type = type ;
V_137 -> V_97 = V_97 ;
V_137 -> V_205 = F_94 ( V_203 ) ;
V_215 -> V_233 = 1 ;
V_215 -> V_39 = true ;
return V_215 ;
}
static inline struct V_213 *
F_97 ( struct V_214 * V_97 )
{
return NULL ;
}
static int F_109 ( struct V_171 * V_49 , unsigned V_43 )
{
struct V_2 * V_3 = F_75 ( V_49 ) ;
if ( F_110 ( & V_3 -> V_97 -> V_98 ) ) {
switch ( V_3 -> V_5 ) {
case V_7 :
case V_8 :
return V_43 - 1 ;
default:
break;
}
}
return V_43 ;
}
static int F_111 ( struct V_214 * V_97 )
{
struct V_211 * V_98 = & V_97 -> V_98 ;
struct V_213 * V_234 ;
struct V_171 * V_49 ;
struct V_2 * V_3 ;
struct V_136 * V_137 ;
const struct V_1 * V_33 ;
int V_115 ;
T_1 V_235 ;
V_234 = F_112 ( V_98 ) ;
if ( ! V_234 ) {
V_234 = F_97 ( V_97 ) ;
if ( ! V_234 ) {
F_52 ( & V_97 -> V_98 , L_17 ) ;
return - V_236 ;
}
}
V_137 = F_113 ( V_97 -> V_237 , V_97 -> V_238 ) ;
if ( ! V_137 )
V_137 = & V_234 -> V_137 ;
if ( ! V_137 -> V_228 ) {
F_52 ( & V_97 -> V_98 , L_18 ) ;
return - V_236 ;
}
V_49 = F_114 ( V_98 , sizeof( struct V_2 ) ) ;
if ( ! V_49 ) {
F_52 ( & V_97 -> V_98 , L_19 ) ;
F_115 ( V_137 ) ;
return - V_188 ;
}
V_3 = F_75 ( V_49 ) ;
V_3 -> V_49 = V_49 ;
V_3 -> V_38 = V_234 ;
V_3 -> V_97 = V_97 ;
V_3 -> V_137 = V_137 ;
V_49 -> V_98 . V_212 = & V_97 -> V_98 ;
V_49 -> V_98 . V_239 = V_97 -> V_98 . V_239 ;
V_49 -> V_240 = V_200 | V_199 | V_178 | V_201 ;
V_49 -> V_241 = V_137 -> V_205 ;
V_49 -> V_242 = V_243 ;
V_49 -> F_93 = F_93 ;
V_49 -> F_82 = F_82 ;
V_49 -> V_244 = F_74 ;
V_49 -> V_245 = F_77 ;
V_49 -> V_246 = F_109 ;
V_49 -> V_247 = true ;
V_3 -> V_5 = V_137 -> type ;
V_3 -> V_34 = V_137 -> V_228 ;
V_3 -> V_248 = V_137 -> V_226 + V_65 ;
if ( F_51 ( V_3 ) ) {
switch ( V_3 -> V_5 ) {
case V_11 :
V_49 -> V_249 = F_116 ( 4 , 32 ) ;
break;
default:
V_49 -> V_249 = F_116 ( 4 , 16 ) ;
break;
}
V_3 -> V_93 = V_103 | V_250 ;
V_3 -> V_165 = 0 ;
V_3 -> V_94 = V_67 ;
V_3 -> V_104 = V_251 | V_105 | V_67 ;
} else {
V_49 -> V_249 = F_116 ( 4 , 32 ) ;
V_3 -> V_93 = V_103 | V_250 | V_117 ;
V_3 -> V_165 = V_252 ;
V_3 -> V_94 = V_67 | V_108 ;
V_3 -> V_104 = V_108 | V_251 | V_105 | V_67 ;
}
V_115 = F_117 ( V_137 -> V_113 , F_56 , V_253 , F_118 ( V_98 ) ,
V_3 ) ;
if ( V_115 < 0 ) {
F_52 ( & V_97 -> V_98 , L_20 , V_137 -> V_113 ) ;
goto V_254;
}
if ( V_234 -> V_39 ) {
V_115 = F_119 ( V_3 ) ;
if ( V_115 ) {
F_72 ( V_98 , L_21 ) ;
V_234 -> V_39 = false ;
}
}
F_120 ( V_137 -> V_232 ) ;
V_49 -> V_50 = F_121 ( V_137 -> V_232 ) ;
F_25 ( V_3 , V_96 , 0 ) ;
switch ( V_3 -> V_5 ) {
case V_11 :
V_235 = F_10 ( V_14 )
| F_90 ( V_182 ) ;
F_25 ( V_3 , V_92 , V_235 ) ;
F_25 ( V_3 , V_96 ,
V_26
| F_13 ( 8 ) ) ;
break;
default:
V_235 = F_11 ( V_15 ) |
F_91 ( V_186 ) ;
F_25 ( V_3 , V_92 , V_235 ) ;
V_235 = F_73 ( 2 ) | V_28 | F_14 ( 8 ) ;
F_25 ( V_3 , V_96 , V_235 ) ;
break;
}
if ( ! F_51 ( V_3 ) )
F_25 ( V_3 , V_95 , 0 ) ;
if ( ! F_3 ( V_3 ) )
F_25 ( V_3 , V_255 , 0 ) ;
if ( F_2 ( V_3 ) ) {
F_20 ( V_3 ) ;
V_33 = F_1 ( V_3 ) ;
if ( V_33 -> V_256 >= 0 ) {
V_235 = F_15 ( V_3 ,
V_33 -> V_256 ) ;
V_235 &= V_257 ;
V_235 >>= V_258 ;
V_234 -> V_233 = F_122 ( V_235 ) ;
} else if ( V_33 -> V_259 ) {
V_234 -> V_233 = V_33 -> V_259 ;
}
}
V_49 -> V_233 = V_234 -> V_233 ;
F_123 ( & V_3 -> V_99 , V_99 ,
( unsigned long ) V_3 ) ;
F_124 ( & V_97 -> V_98 , 50 ) ;
F_125 ( & V_97 -> V_98 ) ;
F_126 ( & V_97 -> V_98 ) ;
F_127 ( & V_97 -> V_98 ) ;
F_128 ( V_97 , V_3 ) ;
V_115 = F_129 ( & V_97 -> V_98 , V_49 ) ;
if ( V_115 != 0 ) {
F_52 ( & V_97 -> V_98 , L_22 ) ;
goto V_260;
}
return V_115 ;
V_260:
F_130 ( V_137 -> V_232 ) ;
F_131 ( V_3 ) ;
F_132 ( V_137 -> V_113 , V_3 ) ;
V_254:
F_133 ( V_49 ) ;
F_115 ( V_137 ) ;
return V_115 ;
}
static int F_134 ( struct V_214 * V_97 )
{
struct V_2 * V_3 = F_135 ( V_97 ) ;
struct V_136 * V_137 ;
if ( ! V_3 )
return 0 ;
V_137 = V_3 -> V_137 ;
F_136 ( & V_97 -> V_98 ) ;
F_25 ( V_3 , V_96 , 0 ) ;
F_130 ( V_137 -> V_232 ) ;
if ( V_3 -> V_38 -> V_39 )
F_131 ( V_3 ) ;
F_137 ( & V_97 -> V_98 ) ;
F_138 ( & V_97 -> V_98 ) ;
F_132 ( V_137 -> V_113 , V_3 ) ;
F_115 ( V_137 ) ;
return 0 ;
}
static void F_139 ( struct V_214 * V_97 )
{
int V_115 = 0 ;
if ( ( V_115 = F_134 ( V_97 ) ) != 0 )
F_52 ( & V_97 -> V_98 , L_23 , V_115 ) ;
}
static int F_140 ( struct V_211 * V_98 )
{
struct V_2 * V_3 = F_141 ( V_98 ) ;
struct V_136 * V_137 = V_3 -> V_137 ;
int V_115 = 0 ;
V_115 = F_142 ( V_3 -> V_49 ) ;
if ( V_115 != 0 )
return V_115 ;
F_25 ( V_3 , V_96 , 0 ) ;
if ( ! F_57 ( V_98 ) )
F_130 ( V_137 -> V_232 ) ;
return 0 ;
}
static int F_143 ( struct V_211 * V_98 )
{
struct V_2 * V_3 = F_141 ( V_98 ) ;
struct V_136 * V_137 = V_3 -> V_137 ;
int V_115 = 0 ;
if ( ! F_57 ( V_98 ) )
F_120 ( V_137 -> V_232 ) ;
if ( F_2 ( V_3 ) )
F_20 ( V_3 ) ;
V_115 = F_144 ( V_3 -> V_49 ) ;
if ( V_115 != 0 ) {
F_52 ( V_98 , L_24 , V_115 ) ;
return V_115 ;
}
return 0 ;
}
static int F_145 ( struct V_211 * V_98 )
{
struct V_2 * V_3 = F_141 ( V_98 ) ;
F_130 ( V_3 -> V_137 -> V_232 ) ;
return 0 ;
}
static int F_146 ( struct V_211 * V_98 )
{
struct V_2 * V_3 = F_141 ( V_98 ) ;
F_120 ( V_3 -> V_137 -> V_232 ) ;
return 0 ;
}
static int T_6 F_147 ( void )
{
return F_148 ( & V_223 ) ;
}
static void T_7 F_149 ( void )
{
F_150 ( & V_223 ) ;
}
