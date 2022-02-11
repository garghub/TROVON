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
return true ;
default:
return false ;
}
}
static bool F_3 ( const struct V_2 * V_3 )
{
return V_3 -> V_5 == V_9 ;
}
static T_1 F_4 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_9 :
return V_10 ;
default:
return V_11 ;
}
}
static T_1
F_5 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_9 :
return V_12 ;
default:
return V_13 ;
}
}
static bool F_6 ( const struct V_2 * V_3 )
{
T_1 V_14 ;
switch ( V_3 -> V_5 ) {
case V_9 :
V_14 = V_15 ;
break;
default:
V_14 = V_16 ;
break;
}
return ( F_7 ( V_3 , V_17 ) & V_14 ) == V_14 ;
}
static void F_8 ( const struct V_2 * V_3 ,
T_1 * V_18 )
{
T_1 V_14 ;
switch ( V_3 -> V_5 ) {
case V_9 :
V_14 = V_19 ;
break;
default:
V_14 = V_20 ;
break;
}
* V_18 &= ~ V_14 ;
}
static void F_9 ( const struct V_2 * V_3 ,
T_1 * V_18 , T_1 V_21 )
{
switch ( V_3 -> V_5 ) {
case V_9 :
* V_18 |= F_10 ( V_21 ) ;
break;
default:
* V_18 |= F_11 ( V_21 ) ;
break;
}
}
static T_1 F_12 ( const struct V_2 * V_3 ,
T_1 V_22 , T_2 V_23 )
{
switch ( V_3 -> V_5 ) {
case V_9 :
return V_22
| V_24
| F_13 ( V_23 > 32 ? 8 : V_23 )
| V_25 ;
default:
return V_22
| V_26
| F_14 ( V_23 > 16 ? V_23 - 16 : V_23 )
| V_25
| ( V_23 > 16 ? V_27 : 0 ) ;
}
}
static T_1 F_15 ( struct V_2 * V_3 , unsigned V_28 )
{
F_16 ( ! V_3 -> V_29 ) ;
return F_17 ( V_3 -> V_29 + V_28 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
unsigned V_28 , T_1 V_30 )
{
F_16 ( ! V_3 -> V_29 ) ;
F_19 ( V_30 , V_3 -> V_29 + V_28 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
const struct V_1 * V_31 ;
T_1 V_30 ;
V_31 = F_1 ( V_3 ) ;
V_3 -> V_29 = V_3 -> V_32 + V_31 -> V_28 ;
V_30 = V_33 | V_34 ;
F_18 ( V_3 , V_31 -> V_35 , V_30 ) ;
if ( V_3 -> V_36 -> V_37 ) {
F_18 ( V_3 , V_31 -> V_38 , 1 ) ;
if ( V_31 -> V_39 >= 0 ) {
V_30 = F_15 ( V_3 ,
V_31 -> V_39 ) ;
V_30 |= V_40 ;
F_18 ( V_3 ,
V_31 -> V_39 , V_30 ) ;
}
}
}
static void F_21 ( struct V_2 * V_3 , bool V_41 )
{
const struct V_1 * V_31 ;
T_1 V_30 ;
V_31 = F_1 ( V_3 ) ;
V_30 = F_15 ( V_3 , V_31 -> V_35 ) ;
if ( V_41 )
V_30 &= ~ V_34 ;
else
V_30 |= V_34 ;
F_18 ( V_3 , V_31 -> V_35 , V_30 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_42 * V_43 = V_3 -> V_44 ;
if ( V_3 -> V_5 == V_45 ) {
F_23 ( V_3 , V_17 , V_3 -> V_44 -> V_46 ) ;
return;
}
if ( V_43 -> V_47 ) {
V_43 -> V_47 ( V_48 ) ;
return;
}
if ( F_24 ( V_43 -> V_49 ) ) {
F_25 ( V_43 -> V_49 , V_43 -> V_50 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_21 ( V_3 , true ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_42 * V_43 = V_3 -> V_44 ;
if ( V_3 -> V_5 == V_45 )
return;
if ( V_43 -> V_47 ) {
V_43 -> V_47 ( V_51 ) ;
return;
}
if ( F_24 ( V_43 -> V_49 ) ) {
F_25 ( V_43 -> V_49 , ! V_43 -> V_50 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_21 ( V_3 , false ) ;
}
int F_27 ( struct V_2 * V_3 )
{
unsigned long V_52 = V_53 << 1 ;
do {
while ( F_7 ( V_3 , V_17 ) & V_54 )
F_7 ( V_3 , V_55 ) ;
} while ( ( F_7 ( V_3 , V_17 ) & V_56 ) && -- V_52 );
F_28 ( V_3 , V_57 ) ;
return V_52 ;
}
static int F_29 ( struct V_2 * V_3 )
{
T_2 V_58 = V_3 -> V_58 ;
if ( F_6 ( V_3 )
|| ( V_3 -> V_59 == V_3 -> V_60 ) )
return 0 ;
F_23 ( V_3 , V_55 , 0 ) ;
V_3 -> V_59 += V_58 ;
return 1 ;
}
static int F_30 ( struct V_2 * V_3 )
{
T_2 V_58 = V_3 -> V_58 ;
while ( ( F_7 ( V_3 , V_17 ) & V_54 )
&& ( V_3 -> V_61 < V_3 -> V_62 ) ) {
F_7 ( V_3 , V_55 ) ;
V_3 -> V_61 += V_58 ;
}
return V_3 -> V_61 == V_3 -> V_62 ;
}
static int F_31 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_59 == V_3 -> V_60 ) )
return 0 ;
F_23 ( V_3 , V_55 , * ( T_2 * ) ( V_3 -> V_59 ) ) ;
++ V_3 -> V_59 ;
return 1 ;
}
static int F_32 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_17 ) & V_54 )
&& ( V_3 -> V_61 < V_3 -> V_62 ) ) {
* ( T_2 * ) ( V_3 -> V_61 ) = F_7 ( V_3 , V_55 ) ;
++ V_3 -> V_61 ;
}
return V_3 -> V_61 == V_3 -> V_62 ;
}
static int F_33 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_59 == V_3 -> V_60 ) )
return 0 ;
F_23 ( V_3 , V_55 , * ( V_63 * ) ( V_3 -> V_59 ) ) ;
V_3 -> V_59 += 2 ;
return 1 ;
}
static int F_34 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_17 ) & V_54 )
&& ( V_3 -> V_61 < V_3 -> V_62 ) ) {
* ( V_63 * ) ( V_3 -> V_61 ) = F_7 ( V_3 , V_55 ) ;
V_3 -> V_61 += 2 ;
}
return V_3 -> V_61 == V_3 -> V_62 ;
}
static int F_35 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_59 == V_3 -> V_60 ) )
return 0 ;
F_23 ( V_3 , V_55 , * ( T_1 * ) ( V_3 -> V_59 ) ) ;
V_3 -> V_59 += 4 ;
return 1 ;
}
static int F_36 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_17 ) & V_54 )
&& ( V_3 -> V_61 < V_3 -> V_62 ) ) {
* ( T_1 * ) ( V_3 -> V_61 ) = F_7 ( V_3 , V_55 ) ;
V_3 -> V_61 += 4 ;
}
return V_3 -> V_61 == V_3 -> V_62 ;
}
void * F_37 ( struct V_2 * V_3 )
{
struct V_64 * V_65 = V_3 -> V_66 ;
struct V_67 * V_68 = V_3 -> V_69 ;
if ( V_68 -> V_70 . V_71 != & V_65 -> V_72 ) {
V_3 -> V_69 =
F_38 ( V_68 -> V_70 . V_71 ,
struct V_67 ,
V_70 ) ;
return V_73 ;
} else
return V_74 ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_67 * V_75 ;
struct V_64 * V_65 ;
V_65 = V_3 -> V_66 ;
V_3 -> V_66 = NULL ;
V_3 -> V_69 = NULL ;
V_75 = F_40 ( & V_65 -> V_72 , struct V_67 ,
V_70 ) ;
if ( V_75 -> V_76 )
F_41 ( V_75 -> V_76 ) ;
if ( ! V_75 -> V_77 )
F_26 ( V_3 ) ;
else {
struct V_64 * V_78 ;
V_78 = F_42 ( V_3 -> V_79 ) ;
if ( V_78 && V_78 -> V_80 != V_65 -> V_80 )
V_78 = NULL ;
if ( ! V_78 || V_65 -> V_81 == V_82 )
F_26 ( V_3 ) ;
}
V_3 -> V_44 = NULL ;
F_43 ( V_3 -> V_79 ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_42 * V_43 = V_3 -> V_44 ;
T_1 V_18 ;
V_18 = F_7 ( V_3 , V_83 ) & ~ V_3 -> V_84 ;
V_18 &= ~ V_20 ;
V_18 |= V_43 -> V_21 ;
F_23 ( V_3 , V_83 , V_18 ) ;
}
static void F_45 ( struct V_2 * V_3 , const char * V_65 )
{
F_28 ( V_3 , V_3 -> V_85 ) ;
F_44 ( V_3 ) ;
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_86 , 0 ) ;
F_27 ( V_3 ) ;
F_23 ( V_3 , V_87 ,
F_7 ( V_3 , V_87 ) & ~ V_25 ) ;
F_47 ( & V_3 -> V_88 -> V_89 , L_1 , V_65 ) ;
V_3 -> V_66 -> V_81 = V_82 ;
F_48 ( & V_3 -> V_90 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
F_28 ( V_3 , V_3 -> V_85 ) ;
F_44 ( V_3 ) ;
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_86 , 0 ) ;
V_3 -> V_66 -> V_91 += V_3 -> V_92 -
( V_3 -> V_62 - V_3 -> V_61 ) ;
V_3 -> V_66 -> V_81 = F_37 ( V_3 ) ;
F_48 ( & V_3 -> V_90 ) ;
}
static T_3 F_50 ( struct V_2 * V_3 )
{
T_1 V_93 = ( F_7 ( V_3 , V_83 ) & V_94 ) ?
V_3 -> V_95 : V_3 -> V_95 & ~ V_96 ;
T_1 V_97 = F_7 ( V_3 , V_17 ) & V_93 ;
if ( V_97 & V_57 ) {
F_45 ( V_3 , L_2 ) ;
return V_98 ;
}
if ( V_97 & V_99 ) {
F_23 ( V_3 , V_17 , V_99 ) ;
if ( V_3 -> V_100 ( V_3 ) ) {
F_49 ( V_3 ) ;
return V_98 ;
}
}
do {
if ( V_3 -> V_100 ( V_3 ) ) {
F_49 ( V_3 ) ;
return V_98 ;
}
} while ( V_3 -> V_101 ( V_3 ) );
if ( V_3 -> V_100 ( V_3 ) ) {
F_49 ( V_3 ) ;
return V_98 ;
}
if ( V_3 -> V_59 == V_3 -> V_60 ) {
T_1 V_102 ;
T_1 V_18 ;
V_18 = F_7 ( V_3 , V_83 ) ;
V_18 &= ~ V_94 ;
if ( F_46 ( V_3 ) ) {
T_1 V_103 ;
F_8 ( V_3 , & V_18 ) ;
V_102 = V_3 -> V_62 - V_3 -> V_61 ;
switch ( V_3 -> V_58 ) {
case 4 :
V_102 >>= 1 ;
case 2 :
V_102 >>= 1 ;
}
V_103 = F_5 ( V_3 ) ;
if ( V_103 > V_102 )
V_103 = V_102 ;
F_9 ( V_3 , & V_18 , V_103 ) ;
}
F_23 ( V_3 , V_83 , V_18 ) ;
}
return V_98 ;
}
static T_3 F_51 ( int V_104 , void * V_105 )
{
struct V_2 * V_3 = V_105 ;
T_1 V_18 ;
T_1 V_14 = V_3 -> V_95 ;
T_1 V_106 ;
if ( F_52 ( & V_3 -> V_88 -> V_89 ) )
return V_107 ;
V_106 = F_7 ( V_3 , V_17 ) ;
if ( V_106 == ~ 0 )
return V_107 ;
V_18 = F_7 ( V_3 , V_83 ) ;
if ( ! ( V_18 & V_94 ) )
V_14 &= ~ V_96 ;
if ( ! ( V_18 & V_108 ) )
V_14 &= ~ V_99 ;
if ( ! ( V_106 & V_14 ) )
return V_107 ;
if ( ! V_3 -> V_66 ) {
F_23 ( V_3 , V_87 ,
F_7 ( V_3 , V_87 )
& ~ V_25 ) ;
F_23 ( V_3 , V_83 ,
F_7 ( V_3 , V_83 )
& ~ V_3 -> V_84 ) ;
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_86 , 0 ) ;
F_28 ( V_3 , V_3 -> V_85 ) ;
F_47 ( & V_3 -> V_88 -> V_89 ,
L_3 ) ;
return V_98 ;
}
return V_3 -> V_109 ( V_3 ) ;
}
static unsigned int F_53 ( int V_110 , T_1 * V_111 )
{
unsigned long V_112 = 200000000 ;
unsigned long V_113 = V_112 / 2 ;
unsigned long V_114 = V_113 / 2 ;
unsigned long V_115 = V_113 * 2 / 5 ;
unsigned long V_116 ;
unsigned long V_117 , V_118 , V_119 ;
long V_120 , V_121 , V_122 ;
T_1 V_123 ;
V_123 = ( 1 << 24 ) >> 1 ;
V_118 = F_54 ( V_114 , V_110 ) ;
if ( V_118 > 256 ) {
V_116 = F_55 ( V_118 - 1 ) ;
if ( V_116 > 9 ) {
V_118 >>= V_116 - 9 ;
V_123 >>= V_116 - 9 ;
}
V_118 += V_118 & 1 ;
}
V_116 = F_56 ( V_118 ) ;
V_118 >>= V_116 ;
V_123 >>= V_116 ;
V_121 = abs ( V_114 / ( 1 << ( 24 - F_55 ( V_123 ) ) ) / V_118 - V_110 ) ;
V_119 = F_54 ( V_115 , V_110 ) ;
V_122 = abs ( V_115 / V_119 - V_110 ) ;
if ( V_122 >= V_121 || V_119 > 256 ) {
V_120 = V_121 ;
V_117 = V_118 ;
} else {
V_120 = V_122 ;
V_117 = V_119 ;
V_123 = ( 1 << 24 ) * 2 / 5 ;
}
if ( V_113 / V_110 >= 80 ) {
T_4 V_124 ;
T_1 V_125 ;
V_118 = F_54 ( V_113 , V_110 ) ;
V_125 = ( 1 << 24 ) / V_118 ;
V_124 = ( T_4 ) V_113 * V_125 ;
F_57 ( V_124 , 1 << 24 ) ;
V_121 = abs ( V_124 - V_110 ) ;
if ( V_121 < V_120 ) {
V_117 = 1 ;
V_123 = V_125 ;
}
}
* V_111 = V_123 ;
return V_117 - 1 ;
}
static unsigned int F_58 ( struct V_2 * V_3 , int V_110 )
{
unsigned long V_126 = V_3 -> V_127 ;
const struct V_128 * V_129 = V_3 -> V_129 ;
V_110 = F_59 ( int , V_126 , V_110 ) ;
if ( V_129 -> type == V_130 || V_129 -> type == V_45 )
return ( V_126 / ( 2 * V_110 ) - 1 ) & 0xff ;
else
return ( V_126 / V_110 - 1 ) & 0xfff ;
}
static unsigned int F_60 ( struct V_2 * V_3 ,
struct V_42 * V_43 , int V_110 )
{
unsigned int V_22 ;
switch ( V_3 -> V_5 ) {
case V_9 :
V_22 = F_53 ( V_110 , & V_43 -> V_131 ) ;
break;
default:
V_22 = F_58 ( V_3 , V_110 ) ;
break;
}
return V_22 << 8 ;
}
static void V_90 ( unsigned long V_132 )
{
struct V_2 * V_3 = (struct V_2 * ) V_132 ;
struct V_64 * V_133 = NULL ;
struct V_67 * V_134 = NULL ;
struct V_67 * V_135 = NULL ;
struct V_42 * V_43 = NULL ;
T_1 V_22 = 0 ;
T_2 V_23 = 0 ;
T_1 V_136 = 0 ;
T_1 V_137 ;
T_1 V_138 ;
T_1 V_139 = V_3 -> V_44 -> V_140 ;
T_1 V_141 = V_3 -> V_44 -> V_142 ;
T_1 V_143 = F_4 ( V_3 ) ;
V_133 = V_3 -> V_66 ;
V_134 = V_3 -> V_69 ;
V_43 = V_3 -> V_44 ;
if ( V_133 -> V_81 == V_82 ) {
V_133 -> V_106 = - V_144 ;
F_39 ( V_3 ) ;
return;
}
if ( V_133 -> V_81 == V_74 ) {
V_133 -> V_106 = 0 ;
F_39 ( V_3 ) ;
return;
}
if ( V_133 -> V_81 == V_73 ) {
V_135 = F_38 ( V_134 -> V_70 . V_145 ,
struct V_67 ,
V_70 ) ;
if ( V_135 -> V_76 )
F_41 ( V_135 -> V_76 ) ;
if ( V_135 -> V_77 )
F_26 ( V_3 ) ;
}
if ( ! F_61 ( V_134 -> V_92 ) && V_43 -> V_37 ) {
if ( V_133 -> V_146
|| V_134 -> V_147 || V_134 -> V_148 ) {
F_47 ( & V_3 -> V_88 -> V_89 ,
L_4
L_5 ,
V_134 -> V_92 , V_149 ) ;
V_133 -> V_106 = - V_150 ;
F_39 ( V_3 ) ;
return;
}
F_62 ( & V_133 -> V_80 -> V_89 ,
L_6
L_7 ,
( long ) V_3 -> V_92 , V_149 ) ;
}
if ( F_27 ( V_3 ) == 0 ) {
F_47 ( & V_3 -> V_88 -> V_89 , L_8 ) ;
V_133 -> V_106 = - V_144 ;
F_39 ( V_3 ) ;
return;
}
V_3 -> V_58 = V_43 -> V_58 ;
V_3 -> V_59 = ( void * ) V_134 -> V_151 ;
V_3 -> V_60 = V_3 -> V_59 + V_134 -> V_92 ;
V_3 -> V_61 = V_134 -> V_152 ;
V_3 -> V_62 = V_3 -> V_61 + V_134 -> V_92 ;
V_3 -> V_147 = V_134 -> V_147 ;
V_3 -> V_148 = V_134 -> V_148 ;
V_3 -> V_92 = V_134 -> V_92 ;
V_3 -> V_101 = V_3 -> V_59 ? V_43 -> V_101 : F_29 ;
V_3 -> V_100 = V_3 -> V_61 ? V_43 -> V_100 : F_30 ;
V_137 = V_43 -> V_137 ;
if ( V_134 -> V_153 || V_134 -> V_154 ) {
V_23 = V_43 -> V_154 ;
V_136 = V_43 -> V_153 ;
if ( V_134 -> V_153 )
V_136 = V_134 -> V_153 ;
if ( V_134 -> V_154 )
V_23 = V_134 -> V_154 ;
V_22 = F_60 ( V_3 , V_43 , V_136 ) ;
if ( V_23 <= 8 ) {
V_3 -> V_58 = 1 ;
V_3 -> V_100 = V_3 -> V_100 != F_30 ?
F_32 : F_30 ;
V_3 -> V_101 = V_3 -> V_101 != F_29 ?
F_31 : F_29 ;
} else if ( V_23 <= 16 ) {
V_3 -> V_58 = 2 ;
V_3 -> V_100 = V_3 -> V_100 != F_30 ?
F_34 : F_30 ;
V_3 -> V_101 = V_3 -> V_101 != F_29 ?
F_33 : F_29 ;
} else if ( V_23 <= 32 ) {
V_3 -> V_58 = 4 ;
V_3 -> V_100 = V_3 -> V_100 != F_30 ?
F_36 : F_30 ;
V_3 -> V_101 = V_3 -> V_101 != F_29 ?
F_35 : F_29 ;
}
if ( V_43 -> V_37 ) {
if ( F_63 ( V_43 ,
V_133 -> V_80 ,
V_23 , & V_141 ,
& V_139 ) )
F_62 ( & V_133 -> V_80 -> V_89 ,
L_9 ) ;
}
V_137 = F_12 ( V_3 , V_22 , V_23 ) ;
}
V_133 -> V_81 = V_73 ;
V_3 -> V_155 = 0 ;
if ( F_61 ( V_3 -> V_92 ) )
V_3 -> V_155 = F_64 ( V_3 ) ;
if ( V_3 -> V_155 ) {
V_3 -> V_109 = V_156 ;
F_65 ( V_3 , V_141 ) ;
V_138 = V_43 -> V_138 | V_139 | V_3 -> V_157 ;
F_23 ( V_3 , V_17 , V_3 -> V_85 ) ;
F_66 ( V_3 ) ;
} else {
V_3 -> V_109 = F_50 ;
V_138 = V_43 -> V_138 | V_43 -> V_21 | V_3 -> V_84 ;
F_28 ( V_3 , V_3 -> V_85 ) ;
}
if ( F_2 ( V_3 ) ) {
if ( ( F_7 ( V_3 , V_158 ) & 0xff )
!= V_43 -> V_159 )
F_23 ( V_3 , V_158 ,
V_43 -> V_159 ) ;
if ( ( F_7 ( V_3 , V_160 ) & 0xffff )
!= V_43 -> V_161 )
F_23 ( V_3 , V_160 ,
V_43 -> V_161 ) ;
}
if ( F_3 ( V_3 ) &&
( F_7 ( V_3 , V_162 ) != V_43 -> V_131 ) )
F_23 ( V_3 , V_162 , V_43 -> V_131 ) ;
if ( ( F_7 ( V_3 , V_87 ) != V_137 )
|| ( F_7 ( V_3 , V_83 ) & V_143 )
!= ( V_138 & V_143 ) ) {
F_23 ( V_3 , V_87 , V_137 & ~ V_25 ) ;
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_86 , V_43 -> V_163 ) ;
F_23 ( V_3 , V_83 , V_138 & V_143 ) ;
F_23 ( V_3 , V_87 , V_137 ) ;
} else {
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_86 , V_43 -> V_163 ) ;
}
F_22 ( V_3 ) ;
F_23 ( V_3 , V_83 , V_138 ) ;
}
static int F_67 ( struct V_164 * V_79 ,
struct V_64 * V_65 )
{
struct V_2 * V_3 = F_68 ( V_79 ) ;
V_3 -> V_66 = V_65 ;
V_3 -> V_66 -> V_81 = V_165 ;
V_3 -> V_69 = F_38 ( V_3 -> V_66 -> V_72 . V_71 ,
struct V_67 ,
V_70 ) ;
V_3 -> V_44 = F_69 ( V_3 -> V_66 -> V_80 ) ;
F_48 ( & V_3 -> V_90 ) ;
return 0 ;
}
static int F_70 ( struct V_164 * V_79 )
{
struct V_2 * V_3 = F_68 ( V_79 ) ;
F_23 ( V_3 , V_87 ,
F_7 ( V_3 , V_87 ) & ~ V_25 ) ;
return 0 ;
}
static int F_71 ( struct V_166 * V_80 , struct V_42 * V_43 ,
struct V_167 * V_168 )
{
int V_169 = 0 ;
if ( V_43 == NULL || V_168 == NULL )
return 0 ;
if ( F_24 ( V_43 -> V_49 ) )
F_72 ( V_43 -> V_49 ) ;
if ( V_168 -> V_47 ) {
V_43 -> V_47 = V_168 -> V_47 ;
return 0 ;
}
if ( F_24 ( V_168 -> V_49 ) ) {
V_169 = F_73 ( V_168 -> V_49 , L_10 ) ;
if ( V_169 ) {
F_47 ( & V_80 -> V_89 , L_11 ,
V_168 -> V_49 ) ;
return V_169 ;
}
V_43 -> V_49 = V_168 -> V_49 ;
V_43 -> V_50 = V_80 -> V_170 & V_171 ;
V_169 = F_74 ( V_43 -> V_49 ,
! V_43 -> V_50 ) ;
}
return V_169 ;
}
static int F_75 ( struct V_166 * V_80 )
{
struct V_167 * V_168 = NULL ;
struct V_42 * V_43 ;
const struct V_1 * V_31 ;
struct V_2 * V_3 = F_68 ( V_80 -> V_79 ) ;
unsigned int V_22 ;
T_5 V_172 , V_173 , V_174 ;
switch ( V_3 -> V_5 ) {
case V_9 :
V_172 = V_175 ;
V_173 = 0 ;
V_174 = V_12 ;
break;
case V_6 :
case V_7 :
case V_8 :
V_31 = F_1 ( V_3 ) ;
V_172 = V_31 -> V_176 ;
V_173 = V_31 -> V_177 ;
V_174 = V_31 -> V_178 ;
break;
default:
V_172 = V_179 ;
V_173 = 0 ;
V_174 = V_13 ;
break;
}
V_43 = F_69 ( V_80 ) ;
if ( ! V_43 ) {
V_43 = F_76 ( sizeof( struct V_42 ) , V_180 ) ;
if ( ! V_43 )
return - V_181 ;
if ( V_3 -> V_5 == V_45 ) {
if ( V_80 -> V_182 > 4 ) {
F_47 ( & V_80 -> V_89 ,
L_12 ) ;
F_77 ( V_43 ) ;
return - V_150 ;
}
V_43 -> V_46 = V_80 -> V_182 ;
} else
V_43 -> V_49 = - 1 ;
V_43 -> V_37 = 0 ;
V_43 -> V_163 = V_183 ;
}
V_168 = V_80 -> V_184 ;
V_43 -> V_138 = 0 ;
if ( V_168 ) {
if ( V_168 -> V_163 )
V_43 -> V_163 = V_168 -> V_163 ;
if ( V_168 -> V_185 )
V_172 = V_168 -> V_185 ;
if ( V_168 -> V_186 )
V_173 = V_168 -> V_186 ;
if ( V_168 -> V_178 )
V_174 = V_168 -> V_178 ;
V_43 -> V_37 = V_3 -> V_36 -> V_37 ;
V_43 -> V_140 = 0 ;
if ( V_168 -> V_187 )
V_43 -> V_138 = V_188 ;
} else if ( F_78 ( & V_80 -> V_89 ) ) {
V_43 -> V_37 = V_3 -> V_36 -> V_37 ;
}
V_43 -> V_159 = F_79 ( V_174 ) ;
V_43 -> V_161 = F_80 ( V_172 )
| F_81 ( V_173 ) ;
if ( V_43 -> V_37 ) {
if ( F_63 ( V_43 , V_80 ,
V_80 -> V_154 ,
& V_43 -> V_142 ,
& V_43 -> V_140 ) ) {
F_82 ( & V_80 -> V_89 ,
L_13 ) ;
}
}
V_22 = F_60 ( V_3 , V_43 , V_80 -> V_189 ) ;
V_43 -> V_153 = V_80 -> V_189 ;
V_43 -> V_137 = F_12 ( V_3 , V_22 ,
V_80 -> V_154 ) ;
switch ( V_3 -> V_5 ) {
case V_9 :
V_43 -> V_21 = ( F_10 ( V_174 )
& V_19 )
| ( F_83 ( V_172 )
& V_190 ) ;
break;
default:
V_43 -> V_21 = ( F_11 ( V_174 ) & V_20 ) |
( F_84 ( V_172 ) & V_191 ) ;
break;
}
V_43 -> V_138 &= ~ ( V_192 | V_193 ) ;
V_43 -> V_138 |= ( ( ( V_80 -> V_170 & V_194 ) != 0 ) ? V_193 : 0 )
| ( ( ( V_80 -> V_170 & V_195 ) != 0 ) ? V_192 : 0 ) ;
if ( V_80 -> V_170 & V_196 )
V_43 -> V_138 |= V_188 ;
if ( ! F_46 ( V_3 ) )
F_85 ( & V_80 -> V_89 , L_14 ,
V_3 -> V_127
/ ( 1 + ( ( V_43 -> V_137 & F_86 ( 0xfff ) ) >> 8 ) ) ,
V_43 -> V_37 ? L_15 : L_16 ) ;
else
F_85 ( & V_80 -> V_89 , L_14 ,
V_3 -> V_127 / 2
/ ( 1 + ( ( V_43 -> V_137 & F_86 ( 0x0ff ) ) >> 8 ) ) ,
V_43 -> V_37 ? L_15 : L_16 ) ;
if ( V_80 -> V_154 <= 8 ) {
V_43 -> V_58 = 1 ;
V_43 -> V_100 = F_32 ;
V_43 -> V_101 = F_31 ;
} else if ( V_80 -> V_154 <= 16 ) {
V_43 -> V_58 = 2 ;
V_43 -> V_100 = F_34 ;
V_43 -> V_101 = F_33 ;
} else if ( V_80 -> V_154 <= 32 ) {
if ( ! F_3 ( V_3 ) )
V_43 -> V_137 |= V_27 ;
V_43 -> V_58 = 4 ;
V_43 -> V_100 = F_36 ;
V_43 -> V_101 = F_35 ;
}
V_43 -> V_154 = V_80 -> V_154 ;
F_87 ( V_80 , V_43 ) ;
if ( V_3 -> V_5 == V_45 )
return 0 ;
return F_71 ( V_80 , V_43 , V_168 ) ;
}
static void F_88 ( struct V_166 * V_80 )
{
struct V_42 * V_43 = F_69 ( V_80 ) ;
struct V_2 * V_3 = F_68 ( V_80 -> V_79 ) ;
if ( ! V_43 )
return;
if ( V_3 -> V_5 != V_45 && F_24 ( V_43 -> V_49 ) )
F_72 ( V_43 -> V_49 ) ;
F_77 ( V_43 ) ;
}
static bool F_89 ( struct V_197 * V_198 , void * V_199 )
{
struct V_200 * V_89 = V_199 ;
if ( V_89 != V_198 -> V_200 -> V_89 -> V_201 )
return false ;
return true ;
}
static struct V_202 *
F_90 ( struct V_203 * V_88 )
{
struct V_202 * V_204 ;
struct V_205 * V_206 ;
struct V_128 * V_129 ;
struct V_207 * V_208 ;
const struct V_209 * V_210 = NULL ;
const struct V_211 * V_212 = NULL ;
int V_213 , type ;
if ( ! F_78 ( & V_88 -> V_89 ) ||
F_91 ( F_78 ( & V_88 -> V_89 ) , & V_206 ) )
return NULL ;
if ( F_92 ( V_88 -> V_89 . V_201 ) )
V_212 = F_93 ( V_214 ,
F_94 ( V_88 -> V_89 . V_201 ) ) ;
else
V_210 = F_95 ( V_88 -> V_89 . V_215 -> V_216 ,
& V_88 -> V_89 ) ;
if ( V_210 )
type = ( int ) V_210 -> V_2 ;
else if ( V_212 )
type = ( int ) V_212 -> V_2 ;
else
return NULL ;
V_204 = F_96 ( & V_88 -> V_89 , sizeof( * V_204 ) , V_180 ) ;
if ( ! V_204 )
return NULL ;
V_208 = F_97 ( V_88 , V_217 , 0 ) ;
if ( ! V_208 )
return NULL ;
V_129 = & V_204 -> V_129 ;
V_129 -> V_218 = V_208 -> V_219 ;
V_129 -> V_220 = F_98 ( & V_88 -> V_89 , V_208 ) ;
if ( F_99 ( V_129 -> V_220 ) )
return NULL ;
if ( V_212 ) {
V_204 -> V_221 = V_88 -> V_89 . V_201 ;
V_204 -> V_222 = V_88 -> V_89 . V_201 ;
V_204 -> V_223 = F_89 ;
}
V_129 -> V_224 = F_100 ( & V_88 -> V_89 , NULL ) ;
V_129 -> V_104 = F_101 ( V_88 , 0 ) ;
V_129 -> type = type ;
V_129 -> V_88 = V_88 ;
V_129 -> V_225 = - 1 ;
if ( V_206 -> V_226 . V_227 && ! F_102 ( V_206 -> V_226 . V_227 , 0 , & V_213 ) )
V_129 -> V_225 = V_213 ;
V_204 -> V_228 = 1 ;
V_204 -> V_37 = true ;
return V_204 ;
}
static inline struct V_202 *
F_90 ( struct V_203 * V_88 )
{
return NULL ;
}
static int F_103 ( struct V_203 * V_88 )
{
struct V_200 * V_89 = & V_88 -> V_89 ;
struct V_202 * V_229 ;
struct V_164 * V_79 ;
struct V_2 * V_3 ;
struct V_128 * V_129 ;
int V_106 ;
T_1 V_230 ;
V_229 = F_104 ( V_89 ) ;
if ( ! V_229 ) {
V_229 = F_90 ( V_88 ) ;
if ( ! V_229 ) {
F_47 ( & V_88 -> V_89 , L_17 ) ;
return - V_231 ;
}
}
V_129 = F_105 ( V_88 -> V_232 , V_88 -> V_233 ) ;
if ( ! V_129 )
V_129 = & V_229 -> V_129 ;
if ( ! V_129 -> V_220 ) {
F_47 ( & V_88 -> V_89 , L_18 ) ;
return - V_231 ;
}
V_79 = F_106 ( V_89 , sizeof( struct V_2 ) ) ;
if ( ! V_79 ) {
F_47 ( & V_88 -> V_89 , L_19 ) ;
F_107 ( V_129 ) ;
return - V_181 ;
}
V_3 = F_68 ( V_79 ) ;
V_3 -> V_79 = V_79 ;
V_3 -> V_36 = V_229 ;
V_3 -> V_88 = V_88 ;
V_3 -> V_129 = V_129 ;
V_79 -> V_89 . V_201 = & V_88 -> V_89 ;
V_79 -> V_89 . V_234 = V_88 -> V_89 . V_234 ;
V_79 -> V_235 = V_195 | V_194 | V_171 | V_196 ;
V_79 -> V_236 = V_129 -> V_225 ;
V_79 -> V_228 = V_229 -> V_228 ;
V_79 -> V_237 = V_238 ;
V_79 -> F_88 = F_88 ;
V_79 -> F_75 = F_75 ;
V_79 -> V_239 = F_67 ;
V_79 -> V_240 = F_70 ;
V_79 -> V_241 = true ;
V_3 -> V_5 = V_129 -> type ;
V_3 -> V_32 = V_129 -> V_220 ;
V_3 -> V_242 = V_129 -> V_218 + V_55 ;
if ( F_46 ( V_3 ) ) {
switch ( V_3 -> V_5 ) {
case V_9 :
V_79 -> V_243 = F_108 ( 4 , 32 ) ;
break;
default:
V_79 -> V_243 = F_108 ( 4 , 16 ) ;
break;
}
V_3 -> V_84 = V_94 | V_244 ;
V_3 -> V_157 = 0 ;
V_3 -> V_85 = V_57 ;
V_3 -> V_95 = V_245 | V_96 | V_57 ;
} else {
V_79 -> V_243 = F_108 ( 4 , 32 ) ;
V_3 -> V_84 = V_94 | V_244 | V_108 ;
V_3 -> V_157 = V_246 ;
V_3 -> V_85 = V_57 | V_99 ;
V_3 -> V_95 = V_99 | V_245 | V_96 | V_57 ;
}
V_106 = F_109 ( V_129 -> V_104 , F_51 , V_247 , F_110 ( V_89 ) ,
V_3 ) ;
if ( V_106 < 0 ) {
F_47 ( & V_88 -> V_89 , L_20 , V_129 -> V_104 ) ;
goto V_248;
}
if ( V_229 -> V_37 ) {
V_106 = F_111 ( V_3 ) ;
if ( V_106 ) {
F_85 ( V_89 , L_21 ) ;
V_229 -> V_37 = false ;
}
}
F_112 ( V_129 -> V_224 ) ;
V_3 -> V_127 = F_113 ( V_129 -> V_224 ) ;
F_23 ( V_3 , V_87 , 0 ) ;
switch ( V_3 -> V_5 ) {
case V_9 :
V_230 = F_10 ( V_12 )
| F_83 ( V_175 ) ;
F_23 ( V_3 , V_83 , V_230 ) ;
F_23 ( V_3 , V_87 ,
V_24
| F_13 ( 8 ) ) ;
break;
default:
V_230 = F_11 ( V_13 ) |
F_84 ( V_179 ) ;
F_23 ( V_3 , V_83 , V_230 ) ;
V_230 = F_86 ( 2 ) | V_26 | F_14 ( 8 ) ;
F_23 ( V_3 , V_87 , V_230 ) ;
break;
}
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_86 , 0 ) ;
if ( ! F_3 ( V_3 ) )
F_23 ( V_3 , V_249 , 0 ) ;
if ( F_2 ( V_3 ) )
F_20 ( V_3 ) ;
F_114 ( & V_3 -> V_90 , V_90 ,
( unsigned long ) V_3 ) ;
F_115 ( & V_88 -> V_89 , 50 ) ;
F_116 ( & V_88 -> V_89 ) ;
F_117 ( & V_88 -> V_89 ) ;
F_118 ( & V_88 -> V_89 ) ;
F_119 ( V_88 , V_3 ) ;
V_106 = F_120 ( & V_88 -> V_89 , V_79 ) ;
if ( V_106 != 0 ) {
F_47 ( & V_88 -> V_89 , L_22 ) ;
goto V_250;
}
return V_106 ;
V_250:
F_121 ( V_129 -> V_224 ) ;
F_122 ( V_3 ) ;
F_123 ( V_129 -> V_104 , V_3 ) ;
V_248:
F_124 ( V_79 ) ;
F_107 ( V_129 ) ;
return V_106 ;
}
static int F_125 ( struct V_203 * V_88 )
{
struct V_2 * V_3 = F_126 ( V_88 ) ;
struct V_128 * V_129 ;
if ( ! V_3 )
return 0 ;
V_129 = V_3 -> V_129 ;
F_127 ( & V_88 -> V_89 ) ;
F_23 ( V_3 , V_87 , 0 ) ;
F_121 ( V_129 -> V_224 ) ;
if ( V_3 -> V_36 -> V_37 )
F_122 ( V_3 ) ;
F_128 ( & V_88 -> V_89 ) ;
F_129 ( & V_88 -> V_89 ) ;
F_123 ( V_129 -> V_104 , V_3 ) ;
F_107 ( V_129 ) ;
return 0 ;
}
static void F_130 ( struct V_203 * V_88 )
{
int V_106 = 0 ;
if ( ( V_106 = F_125 ( V_88 ) ) != 0 )
F_47 ( & V_88 -> V_89 , L_23 , V_106 ) ;
}
static int F_131 ( struct V_200 * V_89 )
{
struct V_2 * V_3 = F_132 ( V_89 ) ;
struct V_128 * V_129 = V_3 -> V_129 ;
int V_106 = 0 ;
V_106 = F_133 ( V_3 -> V_79 ) ;
if ( V_106 != 0 )
return V_106 ;
F_23 ( V_3 , V_87 , 0 ) ;
if ( ! F_52 ( V_89 ) )
F_121 ( V_129 -> V_224 ) ;
return 0 ;
}
static int F_134 ( struct V_200 * V_89 )
{
struct V_2 * V_3 = F_132 ( V_89 ) ;
struct V_128 * V_129 = V_3 -> V_129 ;
int V_106 = 0 ;
F_135 ( V_3 ) ;
if ( ! F_52 ( V_89 ) )
F_112 ( V_129 -> V_224 ) ;
if ( F_2 ( V_3 ) )
F_20 ( V_3 ) ;
V_106 = F_136 ( V_3 -> V_79 ) ;
if ( V_106 != 0 ) {
F_47 ( V_89 , L_24 , V_106 ) ;
return V_106 ;
}
return 0 ;
}
static int F_137 ( struct V_200 * V_89 )
{
struct V_2 * V_3 = F_132 ( V_89 ) ;
F_121 ( V_3 -> V_129 -> V_224 ) ;
return 0 ;
}
static int F_138 ( struct V_200 * V_89 )
{
struct V_2 * V_3 = F_132 ( V_89 ) ;
F_112 ( V_3 -> V_129 -> V_224 ) ;
return 0 ;
}
static int T_6 F_139 ( void )
{
return F_140 ( & V_215 ) ;
}
static void T_7 F_141 ( void )
{
F_142 ( & V_215 ) ;
}
