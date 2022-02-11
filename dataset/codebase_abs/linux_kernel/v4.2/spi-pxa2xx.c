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
return true ;
default:
return false ;
}
}
static bool F_3 ( const struct V_2 * V_3 )
{
return V_3 -> V_5 == V_8 ;
}
static T_1 F_4 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_8 :
return V_9 ;
default:
return V_10 ;
}
}
static T_1
F_5 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_8 :
return V_11 ;
default:
return V_12 ;
}
}
static bool F_6 ( const struct V_2 * V_3 )
{
T_1 V_13 ;
switch ( V_3 -> V_5 ) {
case V_8 :
V_13 = V_14 ;
break;
default:
V_13 = V_15 ;
break;
}
return ( F_7 ( V_3 , V_16 ) & V_13 ) == V_13 ;
}
static void F_8 ( const struct V_2 * V_3 ,
T_1 * V_17 )
{
T_1 V_13 ;
switch ( V_3 -> V_5 ) {
case V_8 :
V_13 = V_18 ;
break;
default:
V_13 = V_19 ;
break;
}
* V_17 &= ~ V_13 ;
}
static void F_9 ( const struct V_2 * V_3 ,
T_1 * V_17 , T_1 V_20 )
{
switch ( V_3 -> V_5 ) {
case V_8 :
* V_17 |= F_10 ( V_20 ) ;
break;
default:
* V_17 |= F_11 ( V_20 ) ;
break;
}
}
static T_1 F_12 ( const struct V_2 * V_3 ,
T_1 V_21 , T_2 V_22 )
{
switch ( V_3 -> V_5 ) {
case V_8 :
return V_21
| V_23
| F_13 ( V_22 > 32 ? 8 : V_22 )
| V_24 ;
default:
return V_21
| V_25
| F_14 ( V_22 > 16 ? V_22 - 16 : V_22 )
| V_24
| ( V_22 > 16 ? V_26 : 0 ) ;
}
}
static T_1 F_15 ( struct V_2 * V_3 , unsigned V_27 )
{
F_16 ( ! V_3 -> V_28 ) ;
return F_17 ( V_3 -> V_28 + V_27 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
unsigned V_27 , T_1 V_29 )
{
F_16 ( ! V_3 -> V_28 ) ;
F_19 ( V_29 , V_3 -> V_28 + V_27 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
const struct V_1 * V_30 ;
T_1 V_29 ;
V_30 = F_1 ( V_3 ) ;
V_3 -> V_28 = V_3 -> V_31 + V_30 -> V_27 ;
V_29 = V_32 | V_33 ;
F_18 ( V_3 , V_30 -> V_34 , V_29 ) ;
if ( V_3 -> V_35 -> V_36 ) {
F_18 ( V_3 , V_30 -> V_37 , 1 ) ;
if ( V_30 -> V_38 >= 0 ) {
V_29 = F_15 ( V_3 ,
V_30 -> V_38 ) ;
V_29 |= V_39 ;
F_18 ( V_3 ,
V_30 -> V_38 , V_29 ) ;
}
}
}
static void F_21 ( struct V_2 * V_3 , bool V_40 )
{
const struct V_1 * V_30 ;
T_1 V_29 ;
V_30 = F_1 ( V_3 ) ;
V_29 = F_15 ( V_3 , V_30 -> V_34 ) ;
if ( V_40 )
V_29 &= ~ V_33 ;
else
V_29 |= V_33 ;
F_18 ( V_3 , V_30 -> V_34 , V_29 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_41 * V_42 = V_3 -> V_43 ;
if ( V_3 -> V_5 == V_44 ) {
F_23 ( V_3 , V_16 , V_3 -> V_43 -> V_45 ) ;
return;
}
if ( V_42 -> V_46 ) {
V_42 -> V_46 ( V_47 ) ;
return;
}
if ( F_24 ( V_42 -> V_48 ) ) {
F_25 ( V_42 -> V_48 , V_42 -> V_49 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_21 ( V_3 , true ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_41 * V_42 = V_3 -> V_43 ;
if ( V_3 -> V_5 == V_44 )
return;
if ( V_42 -> V_46 ) {
V_42 -> V_46 ( V_50 ) ;
return;
}
if ( F_24 ( V_42 -> V_48 ) ) {
F_25 ( V_42 -> V_48 , ! V_42 -> V_49 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_21 ( V_3 , false ) ;
}
int F_27 ( struct V_2 * V_3 )
{
unsigned long V_51 = V_52 << 1 ;
do {
while ( F_7 ( V_3 , V_16 ) & V_53 )
F_7 ( V_3 , V_54 ) ;
} while ( ( F_7 ( V_3 , V_16 ) & V_55 ) && -- V_51 );
F_28 ( V_3 , V_56 ) ;
return V_51 ;
}
static int F_29 ( struct V_2 * V_3 )
{
T_2 V_57 = V_3 -> V_57 ;
if ( F_6 ( V_3 )
|| ( V_3 -> V_58 == V_3 -> V_59 ) )
return 0 ;
F_23 ( V_3 , V_54 , 0 ) ;
V_3 -> V_58 += V_57 ;
return 1 ;
}
static int F_30 ( struct V_2 * V_3 )
{
T_2 V_57 = V_3 -> V_57 ;
while ( ( F_7 ( V_3 , V_16 ) & V_53 )
&& ( V_3 -> V_60 < V_3 -> V_61 ) ) {
F_7 ( V_3 , V_54 ) ;
V_3 -> V_60 += V_57 ;
}
return V_3 -> V_60 == V_3 -> V_61 ;
}
static int F_31 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_58 == V_3 -> V_59 ) )
return 0 ;
F_23 ( V_3 , V_54 , * ( T_2 * ) ( V_3 -> V_58 ) ) ;
++ V_3 -> V_58 ;
return 1 ;
}
static int F_32 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_16 ) & V_53 )
&& ( V_3 -> V_60 < V_3 -> V_61 ) ) {
* ( T_2 * ) ( V_3 -> V_60 ) = F_7 ( V_3 , V_54 ) ;
++ V_3 -> V_60 ;
}
return V_3 -> V_60 == V_3 -> V_61 ;
}
static int F_33 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_58 == V_3 -> V_59 ) )
return 0 ;
F_23 ( V_3 , V_54 , * ( V_62 * ) ( V_3 -> V_58 ) ) ;
V_3 -> V_58 += 2 ;
return 1 ;
}
static int F_34 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_16 ) & V_53 )
&& ( V_3 -> V_60 < V_3 -> V_61 ) ) {
* ( V_62 * ) ( V_3 -> V_60 ) = F_7 ( V_3 , V_54 ) ;
V_3 -> V_60 += 2 ;
}
return V_3 -> V_60 == V_3 -> V_61 ;
}
static int F_35 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_58 == V_3 -> V_59 ) )
return 0 ;
F_23 ( V_3 , V_54 , * ( T_1 * ) ( V_3 -> V_58 ) ) ;
V_3 -> V_58 += 4 ;
return 1 ;
}
static int F_36 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_16 ) & V_53 )
&& ( V_3 -> V_60 < V_3 -> V_61 ) ) {
* ( T_1 * ) ( V_3 -> V_60 ) = F_7 ( V_3 , V_54 ) ;
V_3 -> V_60 += 4 ;
}
return V_3 -> V_60 == V_3 -> V_61 ;
}
void * F_37 ( struct V_2 * V_3 )
{
struct V_63 * V_64 = V_3 -> V_65 ;
struct V_66 * V_67 = V_3 -> V_68 ;
if ( V_67 -> V_69 . V_70 != & V_64 -> V_71 ) {
V_3 -> V_68 =
F_38 ( V_67 -> V_69 . V_70 ,
struct V_66 ,
V_69 ) ;
return V_72 ;
} else
return V_73 ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_66 * V_74 ;
struct V_63 * V_64 ;
V_64 = V_3 -> V_65 ;
V_3 -> V_65 = NULL ;
V_3 -> V_68 = NULL ;
V_74 = F_40 ( & V_64 -> V_71 , struct V_66 ,
V_69 ) ;
if ( V_74 -> V_75 )
F_41 ( V_74 -> V_75 ) ;
if ( ! V_74 -> V_76 )
F_26 ( V_3 ) ;
else {
struct V_63 * V_77 ;
V_77 = F_42 ( V_3 -> V_78 ) ;
if ( V_77 && V_77 -> V_79 != V_64 -> V_79 )
V_77 = NULL ;
if ( ! V_77 || V_64 -> V_80 == V_81 )
F_26 ( V_3 ) ;
}
V_3 -> V_43 = NULL ;
F_43 ( V_3 -> V_78 ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_41 * V_42 = V_3 -> V_43 ;
T_1 V_17 ;
V_17 = F_7 ( V_3 , V_82 ) & ~ V_3 -> V_83 ;
V_17 &= ~ V_19 ;
V_17 |= V_42 -> V_20 ;
F_23 ( V_3 , V_82 , V_17 ) ;
}
static void F_45 ( struct V_2 * V_3 , const char * V_64 )
{
F_28 ( V_3 , V_3 -> V_84 ) ;
F_44 ( V_3 ) ;
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_85 , 0 ) ;
F_27 ( V_3 ) ;
F_23 ( V_3 , V_86 ,
F_7 ( V_3 , V_86 ) & ~ V_24 ) ;
F_47 ( & V_3 -> V_87 -> V_88 , L_1 , V_64 ) ;
V_3 -> V_65 -> V_80 = V_81 ;
F_48 ( & V_3 -> V_89 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
F_28 ( V_3 , V_3 -> V_84 ) ;
F_44 ( V_3 ) ;
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_85 , 0 ) ;
V_3 -> V_65 -> V_90 += V_3 -> V_91 -
( V_3 -> V_61 - V_3 -> V_60 ) ;
V_3 -> V_65 -> V_80 = F_37 ( V_3 ) ;
F_48 ( & V_3 -> V_89 ) ;
}
static T_3 F_50 ( struct V_2 * V_3 )
{
T_1 V_92 = ( F_7 ( V_3 , V_82 ) & V_93 ) ?
V_3 -> V_94 : V_3 -> V_94 & ~ V_95 ;
T_1 V_96 = F_7 ( V_3 , V_16 ) & V_92 ;
if ( V_96 & V_56 ) {
F_45 ( V_3 , L_2 ) ;
return V_97 ;
}
if ( V_96 & V_98 ) {
F_23 ( V_3 , V_16 , V_98 ) ;
if ( V_3 -> V_99 ( V_3 ) ) {
F_49 ( V_3 ) ;
return V_97 ;
}
}
do {
if ( V_3 -> V_99 ( V_3 ) ) {
F_49 ( V_3 ) ;
return V_97 ;
}
} while ( V_3 -> V_100 ( V_3 ) );
if ( V_3 -> V_99 ( V_3 ) ) {
F_49 ( V_3 ) ;
return V_97 ;
}
if ( V_3 -> V_58 == V_3 -> V_59 ) {
T_1 V_101 ;
T_1 V_17 ;
V_17 = F_7 ( V_3 , V_82 ) ;
V_17 &= ~ V_93 ;
if ( F_46 ( V_3 ) ) {
T_1 V_102 ;
F_8 ( V_3 , & V_17 ) ;
V_101 = V_3 -> V_61 - V_3 -> V_60 ;
switch ( V_3 -> V_57 ) {
case 4 :
V_101 >>= 1 ;
case 2 :
V_101 >>= 1 ;
}
V_102 = F_5 ( V_3 ) ;
if ( V_102 > V_101 )
V_102 = V_101 ;
F_9 ( V_3 , & V_17 , V_102 ) ;
}
F_23 ( V_3 , V_82 , V_17 ) ;
}
return V_97 ;
}
static T_3 F_51 ( int V_103 , void * V_104 )
{
struct V_2 * V_3 = V_104 ;
T_1 V_17 ;
T_1 V_13 = V_3 -> V_94 ;
T_1 V_105 ;
if ( F_52 ( & V_3 -> V_87 -> V_88 ) )
return V_106 ;
V_105 = F_7 ( V_3 , V_16 ) ;
if ( V_105 == ~ 0 )
return V_106 ;
V_17 = F_7 ( V_3 , V_82 ) ;
if ( ! ( V_17 & V_93 ) )
V_13 &= ~ V_95 ;
if ( ! ( V_105 & V_13 ) )
return V_106 ;
if ( ! V_3 -> V_65 ) {
F_23 ( V_3 , V_86 ,
F_7 ( V_3 , V_86 )
& ~ V_24 ) ;
F_23 ( V_3 , V_82 ,
F_7 ( V_3 , V_82 )
& ~ V_3 -> V_83 ) ;
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_85 , 0 ) ;
F_28 ( V_3 , V_3 -> V_84 ) ;
F_47 ( & V_3 -> V_87 -> V_88 ,
L_3 ) ;
return V_97 ;
}
return V_3 -> V_107 ( V_3 ) ;
}
static unsigned int F_53 ( int V_108 , T_1 * V_109 )
{
unsigned long V_110 = 200000000 ;
unsigned long V_111 = V_110 / 2 ;
unsigned long V_112 = V_111 / 2 ;
unsigned long V_113 = V_111 * 2 / 5 ;
unsigned long V_114 ;
unsigned long V_115 , V_116 , V_117 ;
long V_118 , V_119 , V_120 ;
T_1 V_121 ;
V_121 = ( 1 << 24 ) >> 1 ;
V_116 = F_54 ( V_112 , V_108 ) ;
if ( V_116 > 256 ) {
V_114 = F_55 ( V_116 - 1 ) ;
if ( V_114 > 9 ) {
V_116 >>= V_114 - 9 ;
V_121 >>= V_114 - 9 ;
}
V_116 += V_116 & 1 ;
}
V_114 = F_56 ( V_116 ) ;
V_116 >>= V_114 ;
V_121 >>= V_114 ;
V_119 = abs ( V_112 / ( 1 << ( 24 - F_55 ( V_121 ) ) ) / V_116 - V_108 ) ;
V_117 = F_54 ( V_113 , V_108 ) ;
V_120 = abs ( V_113 / V_117 - V_108 ) ;
if ( V_120 >= V_119 || V_117 > 256 ) {
V_118 = V_119 ;
V_115 = V_116 ;
} else {
V_118 = V_120 ;
V_115 = V_117 ;
V_121 = ( 1 << 24 ) * 2 / 5 ;
}
if ( V_111 / V_108 >= 80 ) {
T_4 V_122 ;
T_1 V_123 ;
V_116 = F_54 ( V_111 , V_108 ) ;
V_123 = ( 1 << 24 ) / V_116 ;
V_122 = ( T_4 ) V_111 * V_123 ;
F_57 ( V_122 , 1 << 24 ) ;
V_119 = abs ( V_122 - V_108 ) ;
if ( V_119 < V_118 ) {
V_115 = 1 ;
V_121 = V_123 ;
}
}
* V_109 = V_121 ;
return V_115 - 1 ;
}
static unsigned int F_58 ( struct V_2 * V_3 , int V_108 )
{
unsigned long V_124 = V_3 -> V_125 ;
const struct V_126 * V_127 = V_3 -> V_127 ;
V_108 = F_59 ( int , V_124 , V_108 ) ;
if ( V_127 -> type == V_128 || V_127 -> type == V_44 )
return ( V_124 / ( 2 * V_108 ) - 1 ) & 0xff ;
else
return ( V_124 / V_108 - 1 ) & 0xfff ;
}
static unsigned int F_60 ( struct V_2 * V_3 ,
struct V_41 * V_42 , int V_108 )
{
unsigned int V_21 ;
switch ( V_3 -> V_5 ) {
case V_8 :
V_21 = F_53 ( V_108 , & V_42 -> V_129 ) ;
break;
default:
V_21 = F_58 ( V_3 , V_108 ) ;
break;
}
return V_21 << 8 ;
}
static void V_89 ( unsigned long V_130 )
{
struct V_2 * V_3 = (struct V_2 * ) V_130 ;
struct V_63 * V_131 = NULL ;
struct V_66 * V_132 = NULL ;
struct V_66 * V_133 = NULL ;
struct V_41 * V_42 = NULL ;
T_1 V_21 = 0 ;
T_2 V_22 = 0 ;
T_1 V_134 = 0 ;
T_1 V_135 ;
T_1 V_136 ;
T_1 V_137 = V_3 -> V_43 -> V_138 ;
T_1 V_139 = V_3 -> V_43 -> V_140 ;
T_1 V_141 = F_4 ( V_3 ) ;
V_131 = V_3 -> V_65 ;
V_132 = V_3 -> V_68 ;
V_42 = V_3 -> V_43 ;
if ( V_131 -> V_80 == V_81 ) {
V_131 -> V_105 = - V_142 ;
F_39 ( V_3 ) ;
return;
}
if ( V_131 -> V_80 == V_73 ) {
V_131 -> V_105 = 0 ;
F_39 ( V_3 ) ;
return;
}
if ( V_131 -> V_80 == V_72 ) {
V_133 = F_38 ( V_132 -> V_69 . V_143 ,
struct V_66 ,
V_69 ) ;
if ( V_133 -> V_75 )
F_41 ( V_133 -> V_75 ) ;
if ( V_133 -> V_76 )
F_26 ( V_3 ) ;
}
if ( ! F_61 ( V_132 -> V_91 ) && V_42 -> V_36 ) {
if ( V_131 -> V_144
|| V_132 -> V_145 || V_132 -> V_146 ) {
F_47 ( & V_3 -> V_87 -> V_88 ,
L_4
L_5 ,
V_132 -> V_91 , V_147 ) ;
V_131 -> V_105 = - V_148 ;
F_39 ( V_3 ) ;
return;
}
F_62 ( & V_131 -> V_79 -> V_88 ,
L_6
L_7 ,
( long ) V_3 -> V_91 , V_147 ) ;
}
if ( F_27 ( V_3 ) == 0 ) {
F_47 ( & V_3 -> V_87 -> V_88 , L_8 ) ;
V_131 -> V_105 = - V_142 ;
F_39 ( V_3 ) ;
return;
}
V_3 -> V_57 = V_42 -> V_57 ;
V_3 -> V_58 = ( void * ) V_132 -> V_149 ;
V_3 -> V_59 = V_3 -> V_58 + V_132 -> V_91 ;
V_3 -> V_60 = V_132 -> V_150 ;
V_3 -> V_61 = V_3 -> V_60 + V_132 -> V_91 ;
V_3 -> V_145 = V_132 -> V_145 ;
V_3 -> V_146 = V_132 -> V_146 ;
V_3 -> V_91 = V_132 -> V_91 ;
V_3 -> V_100 = V_3 -> V_58 ? V_42 -> V_100 : F_29 ;
V_3 -> V_99 = V_3 -> V_60 ? V_42 -> V_99 : F_30 ;
V_135 = V_42 -> V_135 ;
if ( V_132 -> V_151 || V_132 -> V_152 ) {
V_22 = V_42 -> V_152 ;
V_134 = V_42 -> V_151 ;
if ( V_132 -> V_151 )
V_134 = V_132 -> V_151 ;
if ( V_132 -> V_152 )
V_22 = V_132 -> V_152 ;
V_21 = F_60 ( V_3 , V_42 , V_134 ) ;
if ( V_22 <= 8 ) {
V_3 -> V_57 = 1 ;
V_3 -> V_99 = V_3 -> V_99 != F_30 ?
F_32 : F_30 ;
V_3 -> V_100 = V_3 -> V_100 != F_29 ?
F_31 : F_29 ;
} else if ( V_22 <= 16 ) {
V_3 -> V_57 = 2 ;
V_3 -> V_99 = V_3 -> V_99 != F_30 ?
F_34 : F_30 ;
V_3 -> V_100 = V_3 -> V_100 != F_29 ?
F_33 : F_29 ;
} else if ( V_22 <= 32 ) {
V_3 -> V_57 = 4 ;
V_3 -> V_99 = V_3 -> V_99 != F_30 ?
F_36 : F_30 ;
V_3 -> V_100 = V_3 -> V_100 != F_29 ?
F_35 : F_29 ;
}
if ( V_42 -> V_36 ) {
if ( F_63 ( V_42 ,
V_131 -> V_79 ,
V_22 , & V_139 ,
& V_137 ) )
F_62 ( & V_131 -> V_79 -> V_88 ,
L_9 ) ;
}
V_135 = F_12 ( V_3 , V_21 , V_22 ) ;
}
V_131 -> V_80 = V_72 ;
V_3 -> V_153 = 0 ;
if ( F_61 ( V_3 -> V_91 ) )
V_3 -> V_153 = F_64 ( V_3 ) ;
if ( V_3 -> V_153 ) {
V_3 -> V_107 = V_154 ;
F_65 ( V_3 , V_139 ) ;
V_136 = V_42 -> V_136 | V_137 | V_3 -> V_155 ;
F_23 ( V_3 , V_16 , V_3 -> V_84 ) ;
F_66 ( V_3 ) ;
} else {
V_3 -> V_107 = F_50 ;
V_136 = V_42 -> V_136 | V_42 -> V_20 | V_3 -> V_83 ;
F_28 ( V_3 , V_3 -> V_84 ) ;
}
if ( F_2 ( V_3 ) ) {
if ( ( F_7 ( V_3 , V_156 ) & 0xff )
!= V_42 -> V_157 )
F_23 ( V_3 , V_156 ,
V_42 -> V_157 ) ;
if ( ( F_7 ( V_3 , V_158 ) & 0xffff )
!= V_42 -> V_159 )
F_23 ( V_3 , V_158 ,
V_42 -> V_159 ) ;
}
if ( F_3 ( V_3 ) &&
( F_7 ( V_3 , V_160 ) != V_42 -> V_129 ) )
F_23 ( V_3 , V_160 , V_42 -> V_129 ) ;
if ( ( F_7 ( V_3 , V_86 ) != V_135 )
|| ( F_7 ( V_3 , V_82 ) & V_141 )
!= ( V_136 & V_141 ) ) {
F_23 ( V_3 , V_86 , V_135 & ~ V_24 ) ;
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_85 , V_42 -> V_161 ) ;
F_23 ( V_3 , V_82 , V_136 & V_141 ) ;
F_23 ( V_3 , V_86 , V_135 ) ;
} else {
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_85 , V_42 -> V_161 ) ;
}
F_22 ( V_3 ) ;
F_23 ( V_3 , V_82 , V_136 ) ;
}
static int F_67 ( struct V_162 * V_78 ,
struct V_63 * V_64 )
{
struct V_2 * V_3 = F_68 ( V_78 ) ;
V_3 -> V_65 = V_64 ;
V_3 -> V_65 -> V_80 = V_163 ;
V_3 -> V_68 = F_38 ( V_3 -> V_65 -> V_71 . V_70 ,
struct V_66 ,
V_69 ) ;
V_3 -> V_43 = F_69 ( V_3 -> V_65 -> V_79 ) ;
F_48 ( & V_3 -> V_89 ) ;
return 0 ;
}
static int F_70 ( struct V_162 * V_78 )
{
struct V_2 * V_3 = F_68 ( V_78 ) ;
F_23 ( V_3 , V_86 ,
F_7 ( V_3 , V_86 ) & ~ V_24 ) ;
return 0 ;
}
static int F_71 ( struct V_164 * V_79 , struct V_41 * V_42 ,
struct V_165 * V_166 )
{
int V_167 = 0 ;
if ( V_42 == NULL || V_166 == NULL )
return 0 ;
if ( F_24 ( V_42 -> V_48 ) )
F_72 ( V_42 -> V_48 ) ;
if ( V_166 -> V_46 ) {
V_42 -> V_46 = V_166 -> V_46 ;
return 0 ;
}
if ( F_24 ( V_166 -> V_48 ) ) {
V_167 = F_73 ( V_166 -> V_48 , L_10 ) ;
if ( V_167 ) {
F_47 ( & V_79 -> V_88 , L_11 ,
V_166 -> V_48 ) ;
return V_167 ;
}
V_42 -> V_48 = V_166 -> V_48 ;
V_42 -> V_49 = V_79 -> V_168 & V_169 ;
V_167 = F_74 ( V_42 -> V_48 ,
! V_42 -> V_49 ) ;
}
return V_167 ;
}
static int F_75 ( struct V_164 * V_79 )
{
struct V_165 * V_166 = NULL ;
struct V_41 * V_42 ;
const struct V_1 * V_30 ;
struct V_2 * V_3 = F_68 ( V_79 -> V_78 ) ;
unsigned int V_21 ;
T_5 V_170 , V_171 , V_172 ;
switch ( V_3 -> V_5 ) {
case V_8 :
V_170 = V_173 ;
V_171 = 0 ;
V_172 = V_11 ;
break;
case V_6 :
case V_7 :
V_30 = F_1 ( V_3 ) ;
V_170 = V_30 -> V_174 ;
V_171 = V_30 -> V_175 ;
V_172 = V_30 -> V_176 ;
break;
default:
V_170 = V_177 ;
V_171 = 0 ;
V_172 = V_12 ;
break;
}
V_42 = F_69 ( V_79 ) ;
if ( ! V_42 ) {
V_42 = F_76 ( sizeof( struct V_41 ) , V_178 ) ;
if ( ! V_42 )
return - V_179 ;
if ( V_3 -> V_5 == V_44 ) {
if ( V_79 -> V_180 > 4 ) {
F_47 ( & V_79 -> V_88 ,
L_12 ) ;
F_77 ( V_42 ) ;
return - V_148 ;
}
V_42 -> V_45 = V_79 -> V_180 ;
} else
V_42 -> V_48 = - 1 ;
V_42 -> V_36 = 0 ;
V_42 -> V_161 = V_181 ;
}
V_166 = V_79 -> V_182 ;
V_42 -> V_136 = 0 ;
if ( V_166 ) {
if ( V_166 -> V_161 )
V_42 -> V_161 = V_166 -> V_161 ;
if ( V_166 -> V_183 )
V_170 = V_166 -> V_183 ;
if ( V_166 -> V_184 )
V_171 = V_166 -> V_184 ;
if ( V_166 -> V_176 )
V_172 = V_166 -> V_176 ;
V_42 -> V_36 = V_3 -> V_35 -> V_36 ;
V_42 -> V_138 = 0 ;
if ( V_166 -> V_185 )
V_42 -> V_136 = V_186 ;
} else if ( F_78 ( & V_79 -> V_88 ) ) {
V_42 -> V_36 = V_3 -> V_35 -> V_36 ;
}
V_42 -> V_157 = F_79 ( V_172 ) ;
V_42 -> V_159 = F_80 ( V_170 )
| F_81 ( V_171 ) ;
if ( V_42 -> V_36 ) {
if ( F_63 ( V_42 , V_79 ,
V_79 -> V_152 ,
& V_42 -> V_140 ,
& V_42 -> V_138 ) ) {
F_82 ( & V_79 -> V_88 ,
L_13 ) ;
}
}
V_21 = F_60 ( V_3 , V_42 , V_79 -> V_187 ) ;
V_42 -> V_151 = V_79 -> V_187 ;
V_42 -> V_135 = F_12 ( V_3 , V_21 ,
V_79 -> V_152 ) ;
switch ( V_3 -> V_5 ) {
case V_8 :
V_42 -> V_20 = ( F_10 ( V_172 )
& V_18 )
| ( F_83 ( V_170 )
& V_188 ) ;
break;
default:
V_42 -> V_20 = ( F_11 ( V_172 ) & V_19 ) |
( F_84 ( V_170 ) & V_189 ) ;
break;
}
V_42 -> V_136 &= ~ ( V_190 | V_191 ) ;
V_42 -> V_136 |= ( ( ( V_79 -> V_168 & V_192 ) != 0 ) ? V_191 : 0 )
| ( ( ( V_79 -> V_168 & V_193 ) != 0 ) ? V_190 : 0 ) ;
if ( V_79 -> V_168 & V_194 )
V_42 -> V_136 |= V_186 ;
if ( ! F_46 ( V_3 ) )
F_85 ( & V_79 -> V_88 , L_14 ,
V_3 -> V_125
/ ( 1 + ( ( V_42 -> V_135 & F_86 ( 0xfff ) ) >> 8 ) ) ,
V_42 -> V_36 ? L_15 : L_16 ) ;
else
F_85 ( & V_79 -> V_88 , L_14 ,
V_3 -> V_125 / 2
/ ( 1 + ( ( V_42 -> V_135 & F_86 ( 0x0ff ) ) >> 8 ) ) ,
V_42 -> V_36 ? L_15 : L_16 ) ;
if ( V_79 -> V_152 <= 8 ) {
V_42 -> V_57 = 1 ;
V_42 -> V_99 = F_32 ;
V_42 -> V_100 = F_31 ;
} else if ( V_79 -> V_152 <= 16 ) {
V_42 -> V_57 = 2 ;
V_42 -> V_99 = F_34 ;
V_42 -> V_100 = F_33 ;
} else if ( V_79 -> V_152 <= 32 ) {
if ( ! F_3 ( V_3 ) )
V_42 -> V_135 |= V_26 ;
V_42 -> V_57 = 4 ;
V_42 -> V_99 = F_36 ;
V_42 -> V_100 = F_35 ;
}
V_42 -> V_152 = V_79 -> V_152 ;
F_87 ( V_79 , V_42 ) ;
if ( V_3 -> V_5 == V_44 )
return 0 ;
return F_71 ( V_79 , V_42 , V_166 ) ;
}
static void F_88 ( struct V_164 * V_79 )
{
struct V_41 * V_42 = F_69 ( V_79 ) ;
struct V_2 * V_3 = F_68 ( V_79 -> V_78 ) ;
if ( ! V_42 )
return;
if ( V_3 -> V_5 != V_44 && F_24 ( V_42 -> V_48 ) )
F_72 ( V_42 -> V_48 ) ;
F_77 ( V_42 ) ;
}
static struct V_195 *
F_89 ( struct V_196 * V_87 )
{
struct V_195 * V_197 ;
struct V_198 * V_199 ;
struct V_126 * V_127 ;
struct V_200 * V_201 ;
const struct V_202 * V_203 ;
int V_204 , type ;
if ( ! F_78 ( & V_87 -> V_88 ) ||
F_90 ( F_78 ( & V_87 -> V_88 ) , & V_199 ) )
return NULL ;
V_203 = F_91 ( V_87 -> V_88 . V_205 -> V_206 , & V_87 -> V_88 ) ;
if ( V_203 )
type = ( int ) V_203 -> V_2 ;
else
return NULL ;
V_197 = F_92 ( & V_87 -> V_88 , sizeof( * V_197 ) , V_178 ) ;
if ( ! V_197 )
return NULL ;
V_201 = F_93 ( V_87 , V_207 , 0 ) ;
if ( ! V_201 )
return NULL ;
V_127 = & V_197 -> V_127 ;
V_127 -> V_208 = V_201 -> V_209 ;
V_127 -> V_210 = F_94 ( & V_87 -> V_88 , V_201 ) ;
if ( F_95 ( V_127 -> V_210 ) )
return NULL ;
V_127 -> V_211 = F_96 ( & V_87 -> V_88 , NULL ) ;
V_127 -> V_103 = F_97 ( V_87 , 0 ) ;
V_127 -> type = type ;
V_127 -> V_87 = V_87 ;
V_127 -> V_212 = - 1 ;
if ( V_199 -> V_213 . V_214 && ! F_98 ( V_199 -> V_213 . V_214 , 0 , & V_204 ) )
V_127 -> V_212 = V_204 ;
V_197 -> V_215 = 1 ;
V_197 -> V_36 = true ;
return V_197 ;
}
static inline struct V_195 *
F_89 ( struct V_196 * V_87 )
{
return NULL ;
}
static int F_99 ( struct V_196 * V_87 )
{
struct V_216 * V_88 = & V_87 -> V_88 ;
struct V_195 * V_217 ;
struct V_162 * V_78 ;
struct V_2 * V_3 ;
struct V_126 * V_127 ;
int V_105 ;
T_1 V_218 ;
V_217 = F_100 ( V_88 ) ;
if ( ! V_217 ) {
V_217 = F_89 ( V_87 ) ;
if ( ! V_217 ) {
F_47 ( & V_87 -> V_88 , L_17 ) ;
return - V_219 ;
}
}
V_127 = F_101 ( V_87 -> V_203 , V_87 -> V_220 ) ;
if ( ! V_127 )
V_127 = & V_217 -> V_127 ;
if ( ! V_127 -> V_210 ) {
F_47 ( & V_87 -> V_88 , L_18 ) ;
return - V_219 ;
}
V_78 = F_102 ( V_88 , sizeof( struct V_2 ) + 16 ) ;
if ( ! V_78 ) {
F_47 ( & V_87 -> V_88 , L_19 ) ;
F_103 ( V_127 ) ;
return - V_179 ;
}
V_3 = F_68 ( V_78 ) ;
V_3 -> V_78 = V_78 ;
V_3 -> V_35 = V_217 ;
V_3 -> V_87 = V_87 ;
V_3 -> V_127 = V_127 ;
V_78 -> V_88 . V_221 = & V_87 -> V_88 ;
V_78 -> V_88 . V_222 = V_87 -> V_88 . V_222 ;
V_78 -> V_223 = V_193 | V_192 | V_169 | V_194 ;
V_78 -> V_224 = V_127 -> V_212 ;
V_78 -> V_215 = V_217 -> V_215 ;
V_78 -> V_225 = V_226 ;
V_78 -> F_88 = F_88 ;
V_78 -> F_75 = F_75 ;
V_78 -> V_227 = F_67 ;
V_78 -> V_228 = F_70 ;
V_78 -> V_229 = true ;
V_3 -> V_5 = V_127 -> type ;
V_3 -> V_230 = ( T_1 * ) F_104 ( & V_3 [ 1 ] , V_226 ) ;
V_3 -> V_31 = V_127 -> V_210 ;
V_3 -> V_231 = V_127 -> V_208 + V_54 ;
if ( F_46 ( V_3 ) ) {
switch ( V_3 -> V_5 ) {
case V_8 :
V_78 -> V_232 = F_105 ( 4 , 32 ) ;
break;
default:
V_78 -> V_232 = F_105 ( 4 , 16 ) ;
break;
}
V_3 -> V_83 = V_93 | V_233 ;
V_3 -> V_155 = 0 ;
V_3 -> V_84 = V_56 ;
V_3 -> V_94 = V_234 | V_95 | V_56 ;
} else {
V_78 -> V_232 = F_105 ( 4 , 32 ) ;
V_3 -> V_83 = V_93 | V_233 | V_235 ;
V_3 -> V_155 = V_236 ;
V_3 -> V_84 = V_56 | V_98 ;
V_3 -> V_94 = V_98 | V_234 | V_95 | V_56 ;
}
V_105 = F_106 ( V_127 -> V_103 , F_51 , V_237 , F_107 ( V_88 ) ,
V_3 ) ;
if ( V_105 < 0 ) {
F_47 ( & V_87 -> V_88 , L_20 , V_127 -> V_103 ) ;
goto V_238;
}
V_3 -> V_239 = - 1 ;
V_3 -> V_240 = - 1 ;
if ( V_217 -> V_36 ) {
V_105 = F_108 ( V_3 ) ;
if ( V_105 ) {
F_85 ( V_88 , L_21 ) ;
V_217 -> V_36 = false ;
}
}
F_109 ( V_127 -> V_211 ) ;
V_3 -> V_125 = F_110 ( V_127 -> V_211 ) ;
F_23 ( V_3 , V_86 , 0 ) ;
switch ( V_3 -> V_5 ) {
case V_8 :
V_218 = F_10 ( V_11 )
| F_83 ( V_173 ) ;
F_23 ( V_3 , V_82 , V_218 ) ;
F_23 ( V_3 , V_86 ,
V_23
| F_13 ( 8 ) ) ;
break;
default:
V_218 = F_11 ( V_12 ) |
F_84 ( V_177 ) ;
F_23 ( V_3 , V_82 , V_218 ) ;
V_218 = F_86 ( 2 ) | V_25 | F_14 ( 8 ) ;
F_23 ( V_3 , V_86 , V_218 ) ;
break;
}
if ( ! F_46 ( V_3 ) )
F_23 ( V_3 , V_85 , 0 ) ;
if ( ! F_3 ( V_3 ) )
F_23 ( V_3 , V_241 , 0 ) ;
if ( F_2 ( V_3 ) )
F_20 ( V_3 ) ;
F_111 ( & V_3 -> V_89 , V_89 ,
( unsigned long ) V_3 ) ;
F_112 ( & V_87 -> V_88 , 50 ) ;
F_113 ( & V_87 -> V_88 ) ;
F_114 ( & V_87 -> V_88 ) ;
F_115 ( & V_87 -> V_88 ) ;
F_116 ( V_87 , V_3 ) ;
V_105 = F_117 ( & V_87 -> V_88 , V_78 ) ;
if ( V_105 != 0 ) {
F_47 ( & V_87 -> V_88 , L_22 ) ;
goto V_242;
}
return V_105 ;
V_242:
F_118 ( V_127 -> V_211 ) ;
F_119 ( V_3 ) ;
F_120 ( V_127 -> V_103 , V_3 ) ;
V_238:
F_121 ( V_78 ) ;
F_103 ( V_127 ) ;
return V_105 ;
}
static int F_122 ( struct V_196 * V_87 )
{
struct V_2 * V_3 = F_123 ( V_87 ) ;
struct V_126 * V_127 ;
if ( ! V_3 )
return 0 ;
V_127 = V_3 -> V_127 ;
F_124 ( & V_87 -> V_88 ) ;
F_23 ( V_3 , V_86 , 0 ) ;
F_118 ( V_127 -> V_211 ) ;
if ( V_3 -> V_35 -> V_36 )
F_119 ( V_3 ) ;
F_125 ( & V_87 -> V_88 ) ;
F_126 ( & V_87 -> V_88 ) ;
F_120 ( V_127 -> V_103 , V_3 ) ;
F_103 ( V_127 ) ;
return 0 ;
}
static void F_127 ( struct V_196 * V_87 )
{
int V_105 = 0 ;
if ( ( V_105 = F_122 ( V_87 ) ) != 0 )
F_47 ( & V_87 -> V_88 , L_23 , V_105 ) ;
}
static int F_128 ( struct V_216 * V_88 )
{
struct V_2 * V_3 = F_129 ( V_88 ) ;
struct V_126 * V_127 = V_3 -> V_127 ;
int V_105 = 0 ;
V_105 = F_130 ( V_3 -> V_78 ) ;
if ( V_105 != 0 )
return V_105 ;
F_23 ( V_3 , V_86 , 0 ) ;
if ( ! F_52 ( V_88 ) )
F_118 ( V_127 -> V_211 ) ;
return 0 ;
}
static int F_131 ( struct V_216 * V_88 )
{
struct V_2 * V_3 = F_129 ( V_88 ) ;
struct V_126 * V_127 = V_3 -> V_127 ;
int V_105 = 0 ;
F_132 ( V_3 ) ;
if ( ! F_52 ( V_88 ) )
F_109 ( V_127 -> V_211 ) ;
if ( F_2 ( V_3 ) )
F_20 ( V_3 ) ;
V_105 = F_133 ( V_3 -> V_78 ) ;
if ( V_105 != 0 ) {
F_47 ( V_88 , L_24 , V_105 ) ;
return V_105 ;
}
return 0 ;
}
static int F_134 ( struct V_216 * V_88 )
{
struct V_2 * V_3 = F_129 ( V_88 ) ;
F_118 ( V_3 -> V_127 -> V_211 ) ;
return 0 ;
}
static int F_135 ( struct V_216 * V_88 )
{
struct V_2 * V_3 = F_129 ( V_88 ) ;
F_109 ( V_3 -> V_127 -> V_211 ) ;
return 0 ;
}
static int T_6 F_136 ( void )
{
return F_137 ( & V_205 ) ;
}
static void T_7 F_138 ( void )
{
F_139 ( & V_205 ) ;
}
