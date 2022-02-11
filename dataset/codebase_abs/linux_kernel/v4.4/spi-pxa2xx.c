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
return true ;
default:
return false ;
}
}
static bool F_3 ( const struct V_2 * V_3 )
{
return V_3 -> V_5 == V_10 ;
}
static T_1 F_4 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_10 :
return V_11 ;
default:
return V_12 ;
}
}
static T_1
F_5 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_10 :
return V_13 ;
default:
return V_14 ;
}
}
static bool F_6 ( const struct V_2 * V_3 )
{
T_1 V_15 ;
switch ( V_3 -> V_5 ) {
case V_10 :
V_15 = V_16 ;
break;
default:
V_15 = V_17 ;
break;
}
return ( F_7 ( V_3 , V_18 ) & V_15 ) == V_15 ;
}
static void F_8 ( const struct V_2 * V_3 ,
T_1 * V_19 )
{
T_1 V_15 ;
switch ( V_3 -> V_5 ) {
case V_10 :
V_15 = V_20 ;
break;
default:
V_15 = V_21 ;
break;
}
* V_19 &= ~ V_15 ;
}
static void F_9 ( const struct V_2 * V_3 ,
T_1 * V_19 , T_1 V_22 )
{
switch ( V_3 -> V_5 ) {
case V_10 :
* V_19 |= F_10 ( V_22 ) ;
break;
default:
* V_19 |= F_11 ( V_22 ) ;
break;
}
}
static T_1 F_12 ( const struct V_2 * V_3 ,
T_1 V_23 , T_2 V_24 )
{
switch ( V_3 -> V_5 ) {
case V_10 :
return V_23
| V_25
| F_13 ( V_24 > 32 ? 8 : V_24 )
| V_26 ;
default:
return V_23
| V_27
| F_14 ( V_24 > 16 ? V_24 - 16 : V_24 )
| V_26
| ( V_24 > 16 ? V_28 : 0 ) ;
}
}
static T_1 F_15 ( struct V_2 * V_3 , unsigned V_29 )
{
F_16 ( ! V_3 -> V_30 ) ;
return F_17 ( V_3 -> V_30 + V_29 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
unsigned V_29 , T_1 V_31 )
{
F_16 ( ! V_3 -> V_30 ) ;
F_19 ( V_31 , V_3 -> V_30 + V_29 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
const struct V_1 * V_32 ;
T_1 V_31 ;
V_32 = F_1 ( V_3 ) ;
V_3 -> V_30 = V_3 -> V_33 + V_32 -> V_29 ;
V_31 = F_15 ( V_3 , V_32 -> V_34 ) ;
V_31 &= ~ ( V_35 | V_36 ) ;
V_31 |= V_35 | V_36 ;
F_18 ( V_3 , V_32 -> V_34 , V_31 ) ;
if ( V_3 -> V_37 -> V_38 ) {
F_18 ( V_3 , V_32 -> V_39 , 1 ) ;
if ( V_32 -> V_40 >= 0 ) {
V_31 = F_15 ( V_3 ,
V_32 -> V_40 ) ;
V_31 |= V_41 ;
F_18 ( V_3 ,
V_32 -> V_40 , V_31 ) ;
}
}
}
static void F_21 ( struct V_2 * V_3 , bool V_42 )
{
const struct V_1 * V_32 ;
T_1 V_31 , V_43 ;
V_32 = F_1 ( V_3 ) ;
V_31 = F_15 ( V_3 , V_32 -> V_34 ) ;
if ( V_42 ) {
V_43 = V_3 -> V_44 -> V_45 -> V_46 ;
V_43 <<= V_47 ;
if ( V_43 != ( V_31 & V_48 ) ) {
V_31 &= ~ V_48 ;
V_31 |= V_43 ;
F_18 ( V_3 ,
V_32 -> V_34 , V_31 ) ;
F_22 ( 1000000000 /
( V_3 -> V_49 -> V_50 / 2 ) ) ;
}
V_31 &= ~ V_36 ;
} else {
V_31 |= V_36 ;
}
F_18 ( V_3 , V_32 -> V_34 , V_31 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_51 * V_52 = V_3 -> V_53 ;
if ( V_3 -> V_5 == V_54 ) {
F_24 ( V_3 , V_18 , V_3 -> V_53 -> V_55 ) ;
return;
}
if ( V_52 -> V_56 ) {
V_52 -> V_56 ( V_57 ) ;
return;
}
if ( F_25 ( V_52 -> V_58 ) ) {
F_26 ( V_52 -> V_58 , V_52 -> V_59 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_21 ( V_3 , true ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_51 * V_52 = V_3 -> V_53 ;
if ( V_3 -> V_5 == V_54 )
return;
if ( V_52 -> V_56 ) {
V_52 -> V_56 ( V_60 ) ;
return;
}
if ( F_25 ( V_52 -> V_58 ) ) {
F_26 ( V_52 -> V_58 , ! V_52 -> V_59 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_21 ( V_3 , false ) ;
}
int F_28 ( struct V_2 * V_3 )
{
unsigned long V_61 = V_62 << 1 ;
do {
while ( F_7 ( V_3 , V_18 ) & V_63 )
F_7 ( V_3 , V_64 ) ;
} while ( ( F_7 ( V_3 , V_18 ) & V_65 ) && -- V_61 );
F_29 ( V_3 , V_66 ) ;
return V_61 ;
}
static int F_30 ( struct V_2 * V_3 )
{
T_2 V_67 = V_3 -> V_67 ;
if ( F_6 ( V_3 )
|| ( V_3 -> V_68 == V_3 -> V_69 ) )
return 0 ;
F_24 ( V_3 , V_64 , 0 ) ;
V_3 -> V_68 += V_67 ;
return 1 ;
}
static int F_31 ( struct V_2 * V_3 )
{
T_2 V_67 = V_3 -> V_67 ;
while ( ( F_7 ( V_3 , V_18 ) & V_63 )
&& ( V_3 -> V_70 < V_3 -> V_71 ) ) {
F_7 ( V_3 , V_64 ) ;
V_3 -> V_70 += V_67 ;
}
return V_3 -> V_70 == V_3 -> V_71 ;
}
static int F_32 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_68 == V_3 -> V_69 ) )
return 0 ;
F_24 ( V_3 , V_64 , * ( T_2 * ) ( V_3 -> V_68 ) ) ;
++ V_3 -> V_68 ;
return 1 ;
}
static int F_33 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_18 ) & V_63 )
&& ( V_3 -> V_70 < V_3 -> V_71 ) ) {
* ( T_2 * ) ( V_3 -> V_70 ) = F_7 ( V_3 , V_64 ) ;
++ V_3 -> V_70 ;
}
return V_3 -> V_70 == V_3 -> V_71 ;
}
static int F_34 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_68 == V_3 -> V_69 ) )
return 0 ;
F_24 ( V_3 , V_64 , * ( V_72 * ) ( V_3 -> V_68 ) ) ;
V_3 -> V_68 += 2 ;
return 1 ;
}
static int F_35 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_18 ) & V_63 )
&& ( V_3 -> V_70 < V_3 -> V_71 ) ) {
* ( V_72 * ) ( V_3 -> V_70 ) = F_7 ( V_3 , V_64 ) ;
V_3 -> V_70 += 2 ;
}
return V_3 -> V_70 == V_3 -> V_71 ;
}
static int F_36 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_68 == V_3 -> V_69 ) )
return 0 ;
F_24 ( V_3 , V_64 , * ( T_1 * ) ( V_3 -> V_68 ) ) ;
V_3 -> V_68 += 4 ;
return 1 ;
}
static int F_37 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_18 ) & V_63 )
&& ( V_3 -> V_70 < V_3 -> V_71 ) ) {
* ( T_1 * ) ( V_3 -> V_70 ) = F_7 ( V_3 , V_64 ) ;
V_3 -> V_70 += 4 ;
}
return V_3 -> V_70 == V_3 -> V_71 ;
}
void * F_38 ( struct V_2 * V_3 )
{
struct V_73 * V_74 = V_3 -> V_44 ;
struct V_75 * V_76 = V_3 -> V_77 ;
if ( V_76 -> V_78 . V_79 != & V_74 -> V_80 ) {
V_3 -> V_77 =
F_39 ( V_76 -> V_78 . V_79 ,
struct V_75 ,
V_78 ) ;
return V_81 ;
} else
return V_82 ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_75 * V_83 ;
struct V_73 * V_74 ;
V_74 = V_3 -> V_44 ;
V_3 -> V_44 = NULL ;
V_3 -> V_77 = NULL ;
V_83 = F_41 ( & V_74 -> V_80 , struct V_75 ,
V_78 ) ;
if ( V_83 -> V_84 )
F_42 ( V_83 -> V_84 ) ;
if ( ! V_83 -> V_85 )
F_27 ( V_3 ) ;
else {
struct V_73 * V_86 ;
V_86 = F_43 ( V_3 -> V_49 ) ;
if ( V_86 && V_86 -> V_45 != V_74 -> V_45 )
V_86 = NULL ;
if ( ! V_86 || V_74 -> V_87 == V_88 )
F_27 ( V_3 ) ;
}
V_3 -> V_53 = NULL ;
F_44 ( V_3 -> V_49 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_51 * V_52 = V_3 -> V_53 ;
T_1 V_19 ;
V_19 = F_7 ( V_3 , V_89 ) & ~ V_3 -> V_90 ;
V_19 &= ~ V_21 ;
V_19 |= V_52 -> V_22 ;
F_24 ( V_3 , V_89 , V_19 ) ;
}
static void F_46 ( struct V_2 * V_3 , const char * V_74 )
{
F_29 ( V_3 , V_3 -> V_91 ) ;
F_45 ( V_3 ) ;
if ( ! F_47 ( V_3 ) )
F_24 ( V_3 , V_92 , 0 ) ;
F_28 ( V_3 ) ;
F_24 ( V_3 , V_93 ,
F_7 ( V_3 , V_93 ) & ~ V_26 ) ;
F_48 ( & V_3 -> V_94 -> V_95 , L_1 , V_74 ) ;
V_3 -> V_44 -> V_87 = V_88 ;
F_49 ( & V_3 -> V_96 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
F_29 ( V_3 , V_3 -> V_91 ) ;
F_45 ( V_3 ) ;
if ( ! F_47 ( V_3 ) )
F_24 ( V_3 , V_92 , 0 ) ;
V_3 -> V_44 -> V_97 += V_3 -> V_98 -
( V_3 -> V_71 - V_3 -> V_70 ) ;
V_3 -> V_44 -> V_87 = F_38 ( V_3 ) ;
F_49 ( & V_3 -> V_96 ) ;
}
static T_3 F_51 ( struct V_2 * V_3 )
{
T_1 V_99 = ( F_7 ( V_3 , V_89 ) & V_100 ) ?
V_3 -> V_101 : V_3 -> V_101 & ~ V_102 ;
T_1 V_103 = F_7 ( V_3 , V_18 ) & V_99 ;
if ( V_103 & V_66 ) {
F_46 ( V_3 , L_2 ) ;
return V_104 ;
}
if ( V_103 & V_105 ) {
F_24 ( V_3 , V_18 , V_105 ) ;
if ( V_3 -> V_106 ( V_3 ) ) {
F_50 ( V_3 ) ;
return V_104 ;
}
}
do {
if ( V_3 -> V_106 ( V_3 ) ) {
F_50 ( V_3 ) ;
return V_104 ;
}
} while ( V_3 -> V_107 ( V_3 ) );
if ( V_3 -> V_106 ( V_3 ) ) {
F_50 ( V_3 ) ;
return V_104 ;
}
if ( V_3 -> V_68 == V_3 -> V_69 ) {
T_1 V_108 ;
T_1 V_19 ;
V_19 = F_7 ( V_3 , V_89 ) ;
V_19 &= ~ V_100 ;
if ( F_47 ( V_3 ) ) {
T_1 V_109 ;
F_8 ( V_3 , & V_19 ) ;
V_108 = V_3 -> V_71 - V_3 -> V_70 ;
switch ( V_3 -> V_67 ) {
case 4 :
V_108 >>= 1 ;
case 2 :
V_108 >>= 1 ;
}
V_109 = F_5 ( V_3 ) ;
if ( V_109 > V_108 )
V_109 = V_108 ;
F_9 ( V_3 , & V_19 , V_109 ) ;
}
F_24 ( V_3 , V_89 , V_19 ) ;
}
return V_104 ;
}
static T_3 F_52 ( int V_110 , void * V_111 )
{
struct V_2 * V_3 = V_111 ;
T_1 V_19 ;
T_1 V_15 = V_3 -> V_101 ;
T_1 V_112 ;
if ( F_53 ( & V_3 -> V_94 -> V_95 ) )
return V_113 ;
V_112 = F_7 ( V_3 , V_18 ) ;
if ( V_112 == ~ 0 )
return V_113 ;
V_19 = F_7 ( V_3 , V_89 ) ;
if ( ! ( V_19 & V_100 ) )
V_15 &= ~ V_102 ;
if ( ! ( V_19 & V_114 ) )
V_15 &= ~ V_105 ;
if ( ! ( V_112 & V_15 ) )
return V_113 ;
if ( ! V_3 -> V_44 ) {
F_24 ( V_3 , V_93 ,
F_7 ( V_3 , V_93 )
& ~ V_26 ) ;
F_24 ( V_3 , V_89 ,
F_7 ( V_3 , V_89 )
& ~ V_3 -> V_90 ) ;
if ( ! F_47 ( V_3 ) )
F_24 ( V_3 , V_92 , 0 ) ;
F_29 ( V_3 , V_3 -> V_91 ) ;
F_48 ( & V_3 -> V_94 -> V_95 ,
L_3 ) ;
return V_104 ;
}
return V_3 -> V_115 ( V_3 ) ;
}
static unsigned int F_54 ( int V_116 , T_1 * V_117 )
{
unsigned long V_118 = 200000000 ;
unsigned long V_119 = V_118 / 2 ;
unsigned long V_120 = V_119 / 2 ;
unsigned long V_121 = V_119 * 2 / 5 ;
unsigned long V_122 ;
unsigned long V_123 , V_124 , V_125 ;
long V_126 , V_127 , V_128 ;
T_1 V_129 ;
V_129 = ( 1 << 24 ) >> 1 ;
V_124 = F_55 ( V_120 , V_116 ) ;
if ( V_124 > 256 ) {
V_122 = F_56 ( V_124 - 1 ) ;
if ( V_122 > 9 ) {
V_124 >>= V_122 - 9 ;
V_129 >>= V_122 - 9 ;
}
V_124 += V_124 & 1 ;
}
V_122 = F_57 ( V_124 ) ;
V_124 >>= V_122 ;
V_129 >>= V_122 ;
V_127 = abs ( V_120 / ( 1 << ( 24 - F_56 ( V_129 ) ) ) / V_124 - V_116 ) ;
V_125 = F_55 ( V_121 , V_116 ) ;
V_128 = abs ( V_121 / V_125 - V_116 ) ;
if ( V_128 >= V_127 || V_125 > 256 ) {
V_126 = V_127 ;
V_123 = V_124 ;
} else {
V_126 = V_128 ;
V_123 = V_125 ;
V_129 = ( 1 << 24 ) * 2 / 5 ;
}
if ( V_119 / V_116 >= 80 ) {
T_4 V_130 ;
T_1 V_131 ;
V_124 = F_55 ( V_119 , V_116 ) ;
V_131 = ( 1 << 24 ) / V_124 ;
V_130 = ( T_4 ) V_119 * V_131 ;
F_58 ( V_130 , 1 << 24 ) ;
V_127 = abs ( V_130 - V_116 ) ;
if ( V_127 < V_126 ) {
V_123 = 1 ;
V_129 = V_131 ;
}
}
* V_117 = V_129 ;
return V_123 - 1 ;
}
static unsigned int F_59 ( struct V_2 * V_3 , int V_116 )
{
unsigned long V_132 = V_3 -> V_49 -> V_50 ;
const struct V_133 * V_134 = V_3 -> V_134 ;
V_116 = F_60 ( int , V_132 , V_116 ) ;
if ( V_134 -> type == V_135 || V_134 -> type == V_54 )
return ( V_132 / ( 2 * V_116 ) - 1 ) & 0xff ;
else
return ( V_132 / V_116 - 1 ) & 0xfff ;
}
static unsigned int F_61 ( struct V_2 * V_3 ,
int V_116 )
{
struct V_51 * V_52 = V_3 -> V_53 ;
unsigned int V_23 ;
switch ( V_3 -> V_5 ) {
case V_10 :
V_23 = F_54 ( V_116 , & V_52 -> V_136 ) ;
break;
default:
V_23 = F_59 ( V_3 , V_116 ) ;
break;
}
return V_23 << 8 ;
}
static void V_96 ( unsigned long V_137 )
{
struct V_2 * V_3 = (struct V_2 * ) V_137 ;
struct V_73 * V_138 = NULL ;
struct V_75 * V_139 = NULL ;
struct V_75 * V_140 = NULL ;
struct V_51 * V_52 = NULL ;
T_1 V_23 = 0 ;
T_2 V_24 = 0 ;
T_1 V_141 = 0 ;
T_1 V_142 ;
T_1 V_143 ;
T_1 V_144 = V_3 -> V_53 -> V_145 ;
T_1 V_146 = V_3 -> V_53 -> V_147 ;
T_1 V_148 = F_4 ( V_3 ) ;
V_138 = V_3 -> V_44 ;
V_139 = V_3 -> V_77 ;
V_52 = V_3 -> V_53 ;
if ( V_138 -> V_87 == V_88 ) {
V_138 -> V_112 = - V_149 ;
F_40 ( V_3 ) ;
return;
}
if ( V_138 -> V_87 == V_82 ) {
V_138 -> V_112 = 0 ;
F_40 ( V_3 ) ;
return;
}
if ( V_138 -> V_87 == V_81 ) {
V_140 = F_39 ( V_139 -> V_78 . V_150 ,
struct V_75 ,
V_78 ) ;
if ( V_140 -> V_84 )
F_42 ( V_140 -> V_84 ) ;
if ( V_140 -> V_85 )
F_27 ( V_3 ) ;
}
if ( ! F_62 ( V_139 -> V_98 ) && V_52 -> V_38 ) {
if ( V_138 -> V_151
|| V_139 -> V_152 || V_139 -> V_153 ) {
F_48 ( & V_3 -> V_94 -> V_95 ,
L_4
L_5 ,
V_139 -> V_98 , V_154 ) ;
V_138 -> V_112 = - V_155 ;
F_40 ( V_3 ) ;
return;
}
F_63 ( & V_138 -> V_45 -> V_95 ,
L_6
L_7 ,
( long ) V_3 -> V_98 , V_154 ) ;
}
if ( F_28 ( V_3 ) == 0 ) {
F_48 ( & V_3 -> V_94 -> V_95 , L_8 ) ;
V_138 -> V_112 = - V_149 ;
F_40 ( V_3 ) ;
return;
}
V_3 -> V_67 = V_52 -> V_67 ;
V_3 -> V_68 = ( void * ) V_139 -> V_156 ;
V_3 -> V_69 = V_3 -> V_68 + V_139 -> V_98 ;
V_3 -> V_70 = V_139 -> V_157 ;
V_3 -> V_71 = V_3 -> V_70 + V_139 -> V_98 ;
V_3 -> V_152 = V_139 -> V_152 ;
V_3 -> V_153 = V_139 -> V_153 ;
V_3 -> V_98 = V_139 -> V_98 ;
V_3 -> V_107 = V_3 -> V_68 ? V_52 -> V_107 : F_30 ;
V_3 -> V_106 = V_3 -> V_70 ? V_52 -> V_106 : F_31 ;
V_24 = V_139 -> V_158 ;
V_141 = V_139 -> V_159 ;
V_23 = F_61 ( V_3 , V_141 ) ;
if ( V_24 <= 8 ) {
V_3 -> V_67 = 1 ;
V_3 -> V_106 = V_3 -> V_106 != F_31 ?
F_33 : F_31 ;
V_3 -> V_107 = V_3 -> V_107 != F_30 ?
F_32 : F_30 ;
} else if ( V_24 <= 16 ) {
V_3 -> V_67 = 2 ;
V_3 -> V_106 = V_3 -> V_106 != F_31 ?
F_35 : F_31 ;
V_3 -> V_107 = V_3 -> V_107 != F_30 ?
F_34 : F_30 ;
} else if ( V_24 <= 32 ) {
V_3 -> V_67 = 4 ;
V_3 -> V_106 = V_3 -> V_106 != F_31 ?
F_37 : F_31 ;
V_3 -> V_107 = V_3 -> V_107 != F_30 ?
F_36 : F_30 ;
}
if ( V_52 -> V_38 ) {
if ( F_64 ( V_52 ,
V_138 -> V_45 ,
V_24 , & V_146 ,
& V_144 ) )
F_63 ( & V_138 -> V_45 -> V_95 ,
L_9 ) ;
}
V_142 = F_12 ( V_3 , V_23 , V_24 ) ;
if ( ! F_47 ( V_3 ) )
F_65 ( & V_138 -> V_45 -> V_95 , L_10 ,
V_3 -> V_49 -> V_50
/ ( 1 + ( ( V_142 & F_66 ( 0xfff ) ) >> 8 ) ) ,
V_52 -> V_38 ? L_11 : L_12 ) ;
else
F_65 ( & V_138 -> V_45 -> V_95 , L_10 ,
V_3 -> V_49 -> V_50 / 2
/ ( 1 + ( ( V_142 & F_66 ( 0x0ff ) ) >> 8 ) ) ,
V_52 -> V_38 ? L_11 : L_12 ) ;
V_138 -> V_87 = V_81 ;
V_3 -> V_160 = 0 ;
if ( F_62 ( V_3 -> V_98 ) )
V_3 -> V_160 = F_67 ( V_3 ) ;
if ( V_3 -> V_160 ) {
V_3 -> V_115 = V_161 ;
F_68 ( V_3 , V_146 ) ;
V_143 = V_52 -> V_143 | V_144 | V_3 -> V_162 ;
F_24 ( V_3 , V_18 , V_3 -> V_91 ) ;
F_69 ( V_3 ) ;
} else {
V_3 -> V_115 = F_51 ;
V_143 = V_52 -> V_143 | V_52 -> V_22 | V_3 -> V_90 ;
F_29 ( V_3 , V_3 -> V_91 ) ;
}
if ( F_2 ( V_3 ) ) {
if ( ( F_7 ( V_3 , V_163 ) & 0xff )
!= V_52 -> V_164 )
F_24 ( V_3 , V_163 ,
V_52 -> V_164 ) ;
if ( ( F_7 ( V_3 , V_165 ) & 0xffff )
!= V_52 -> V_166 )
F_24 ( V_3 , V_165 ,
V_52 -> V_166 ) ;
}
if ( F_3 ( V_3 ) &&
( F_7 ( V_3 , V_167 ) != V_52 -> V_136 ) )
F_24 ( V_3 , V_167 , V_52 -> V_136 ) ;
if ( ( F_7 ( V_3 , V_93 ) != V_142 )
|| ( F_7 ( V_3 , V_89 ) & V_148 )
!= ( V_143 & V_148 ) ) {
F_24 ( V_3 , V_93 , V_142 & ~ V_26 ) ;
if ( ! F_47 ( V_3 ) )
F_24 ( V_3 , V_92 , V_52 -> V_168 ) ;
F_24 ( V_3 , V_89 , V_143 & V_148 ) ;
F_24 ( V_3 , V_93 , V_142 ) ;
} else {
if ( ! F_47 ( V_3 ) )
F_24 ( V_3 , V_92 , V_52 -> V_168 ) ;
}
F_23 ( V_3 ) ;
F_24 ( V_3 , V_89 , V_143 ) ;
}
static int F_70 ( struct V_169 * V_49 ,
struct V_73 * V_74 )
{
struct V_2 * V_3 = F_71 ( V_49 ) ;
V_3 -> V_44 = V_74 ;
V_3 -> V_44 -> V_87 = V_170 ;
V_3 -> V_77 = F_39 ( V_3 -> V_44 -> V_80 . V_79 ,
struct V_75 ,
V_78 ) ;
V_3 -> V_53 = F_72 ( V_3 -> V_44 -> V_45 ) ;
F_49 ( & V_3 -> V_96 ) ;
return 0 ;
}
static int F_73 ( struct V_169 * V_49 )
{
struct V_2 * V_3 = F_71 ( V_49 ) ;
F_24 ( V_3 , V_93 ,
F_7 ( V_3 , V_93 ) & ~ V_26 ) ;
return 0 ;
}
static int F_74 ( struct V_171 * V_45 , struct V_51 * V_52 ,
struct V_172 * V_173 )
{
int V_174 = 0 ;
if ( V_52 == NULL || V_173 == NULL )
return 0 ;
if ( F_25 ( V_52 -> V_58 ) )
F_75 ( V_52 -> V_58 ) ;
if ( V_173 -> V_56 ) {
V_52 -> V_56 = V_173 -> V_56 ;
return 0 ;
}
if ( F_25 ( V_173 -> V_58 ) ) {
V_174 = F_76 ( V_173 -> V_58 , L_13 ) ;
if ( V_174 ) {
F_48 ( & V_45 -> V_95 , L_14 ,
V_173 -> V_58 ) ;
return V_174 ;
}
V_52 -> V_58 = V_173 -> V_58 ;
V_52 -> V_59 = V_45 -> V_175 & V_176 ;
V_174 = F_77 ( V_52 -> V_58 ,
! V_52 -> V_59 ) ;
}
return V_174 ;
}
static int F_78 ( struct V_171 * V_45 )
{
struct V_172 * V_173 = NULL ;
struct V_51 * V_52 ;
const struct V_1 * V_32 ;
struct V_2 * V_3 = F_71 ( V_45 -> V_49 ) ;
T_5 V_177 , V_178 , V_179 ;
switch ( V_3 -> V_5 ) {
case V_10 :
V_177 = V_180 ;
V_178 = 0 ;
V_179 = V_13 ;
break;
case V_6 :
case V_7 :
case V_8 :
case V_9 :
V_32 = F_1 ( V_3 ) ;
V_177 = V_32 -> V_181 ;
V_178 = V_32 -> V_182 ;
V_179 = V_32 -> V_183 ;
break;
default:
V_177 = V_184 ;
V_178 = 0 ;
V_179 = V_14 ;
break;
}
V_52 = F_72 ( V_45 ) ;
if ( ! V_52 ) {
V_52 = F_79 ( sizeof( struct V_51 ) , V_185 ) ;
if ( ! V_52 )
return - V_186 ;
if ( V_3 -> V_5 == V_54 ) {
if ( V_45 -> V_46 > 4 ) {
F_48 ( & V_45 -> V_95 ,
L_15 ) ;
F_80 ( V_52 ) ;
return - V_155 ;
}
V_52 -> V_55 = V_45 -> V_46 ;
} else
V_52 -> V_58 = - 1 ;
V_52 -> V_38 = 0 ;
V_52 -> V_168 = V_187 ;
}
V_173 = V_45 -> V_188 ;
V_52 -> V_143 = 0 ;
if ( V_173 ) {
if ( V_173 -> V_168 )
V_52 -> V_168 = V_173 -> V_168 ;
if ( V_173 -> V_189 )
V_177 = V_173 -> V_189 ;
if ( V_173 -> V_190 )
V_178 = V_173 -> V_190 ;
if ( V_173 -> V_183 )
V_179 = V_173 -> V_183 ;
V_52 -> V_38 = V_3 -> V_37 -> V_38 ;
V_52 -> V_145 = 0 ;
if ( V_173 -> V_191 )
V_52 -> V_143 = V_192 ;
} else if ( F_81 ( & V_45 -> V_95 ) ) {
V_52 -> V_38 = V_3 -> V_37 -> V_38 ;
}
V_52 -> V_164 = F_82 ( V_179 ) ;
V_52 -> V_166 = F_83 ( V_177 )
| F_84 ( V_178 ) ;
if ( V_52 -> V_38 ) {
if ( F_64 ( V_52 , V_45 ,
V_45 -> V_158 ,
& V_52 -> V_147 ,
& V_52 -> V_145 ) ) {
F_85 ( & V_45 -> V_95 ,
L_16 ) ;
}
}
switch ( V_3 -> V_5 ) {
case V_10 :
V_52 -> V_22 = ( F_10 ( V_179 )
& V_20 )
| ( F_86 ( V_177 )
& V_193 ) ;
break;
default:
V_52 -> V_22 = ( F_11 ( V_179 ) & V_21 ) |
( F_87 ( V_177 ) & V_194 ) ;
break;
}
V_52 -> V_143 &= ~ ( V_195 | V_196 ) ;
V_52 -> V_143 |= ( ( ( V_45 -> V_175 & V_197 ) != 0 ) ? V_196 : 0 )
| ( ( ( V_45 -> V_175 & V_198 ) != 0 ) ? V_195 : 0 ) ;
if ( V_45 -> V_175 & V_199 )
V_52 -> V_143 |= V_192 ;
if ( V_45 -> V_158 <= 8 ) {
V_52 -> V_67 = 1 ;
V_52 -> V_106 = F_33 ;
V_52 -> V_107 = F_32 ;
} else if ( V_45 -> V_158 <= 16 ) {
V_52 -> V_67 = 2 ;
V_52 -> V_106 = F_35 ;
V_52 -> V_107 = F_34 ;
} else if ( V_45 -> V_158 <= 32 ) {
V_52 -> V_67 = 4 ;
V_52 -> V_106 = F_37 ;
V_52 -> V_107 = F_36 ;
}
F_88 ( V_45 , V_52 ) ;
if ( V_3 -> V_5 == V_54 )
return 0 ;
return F_74 ( V_45 , V_52 , V_173 ) ;
}
static void F_89 ( struct V_171 * V_45 )
{
struct V_51 * V_52 = F_72 ( V_45 ) ;
struct V_2 * V_3 = F_71 ( V_45 -> V_49 ) ;
if ( ! V_52 )
return;
if ( V_3 -> V_5 != V_54 && F_25 ( V_52 -> V_58 ) )
F_75 ( V_52 -> V_58 ) ;
F_80 ( V_52 ) ;
}
static int F_90 ( struct V_200 * V_201 )
{
unsigned int V_202 ;
int V_203 = - 1 ;
if ( V_201 && V_201 -> V_204 . V_205 &&
! F_91 ( V_201 -> V_204 . V_205 , 0 , & V_202 ) )
V_203 = V_202 ;
return V_203 ;
}
static int F_90 ( struct V_200 * V_201 )
{
return - 1 ;
}
static bool F_92 ( struct V_206 * V_207 , void * V_208 )
{
struct V_209 * V_95 = V_208 ;
if ( V_95 != V_207 -> V_209 -> V_95 -> V_210 )
return false ;
return true ;
}
static struct V_211 *
F_93 ( struct V_212 * V_94 )
{
struct V_211 * V_213 ;
struct V_200 * V_201 ;
struct V_133 * V_134 ;
struct V_214 * V_215 ;
const struct V_216 * V_217 = NULL ;
const struct V_218 * V_219 = NULL ;
int type ;
V_201 = F_94 ( & V_94 -> V_95 ) ;
if ( F_95 ( V_94 -> V_95 . V_210 ) )
V_219 = F_96 ( V_220 ,
F_97 ( V_94 -> V_95 . V_210 ) ) ;
else if ( V_201 )
V_217 = F_98 ( V_94 -> V_95 . V_221 -> V_222 ,
& V_94 -> V_95 ) ;
else
return NULL ;
if ( V_217 )
type = ( int ) V_217 -> V_2 ;
else if ( V_219 )
type = ( int ) V_219 -> V_2 ;
else
return NULL ;
V_213 = F_99 ( & V_94 -> V_95 , sizeof( * V_213 ) , V_185 ) ;
if ( ! V_213 )
return NULL ;
V_215 = F_100 ( V_94 , V_223 , 0 ) ;
if ( ! V_215 )
return NULL ;
V_134 = & V_213 -> V_134 ;
V_134 -> V_224 = V_215 -> V_225 ;
V_134 -> V_226 = F_101 ( & V_94 -> V_95 , V_215 ) ;
if ( F_102 ( V_134 -> V_226 ) )
return NULL ;
if ( V_219 ) {
V_213 -> V_227 = V_94 -> V_95 . V_210 ;
V_213 -> V_228 = V_94 -> V_95 . V_210 ;
V_213 -> V_229 = F_92 ;
}
V_134 -> V_230 = F_103 ( & V_94 -> V_95 , NULL ) ;
V_134 -> V_110 = F_104 ( V_94 , 0 ) ;
V_134 -> type = type ;
V_134 -> V_94 = V_94 ;
V_134 -> V_203 = F_90 ( V_201 ) ;
V_213 -> V_231 = 1 ;
V_213 -> V_38 = true ;
return V_213 ;
}
static inline struct V_211 *
F_93 ( struct V_212 * V_94 )
{
return NULL ;
}
static int F_105 ( struct V_212 * V_94 )
{
struct V_209 * V_95 = & V_94 -> V_95 ;
struct V_211 * V_232 ;
struct V_169 * V_49 ;
struct V_2 * V_3 ;
struct V_133 * V_134 ;
const struct V_1 * V_32 ;
int V_112 ;
T_1 V_233 ;
V_232 = F_106 ( V_95 ) ;
if ( ! V_232 ) {
V_232 = F_93 ( V_94 ) ;
if ( ! V_232 ) {
F_48 ( & V_94 -> V_95 , L_17 ) ;
return - V_234 ;
}
}
V_134 = F_107 ( V_94 -> V_235 , V_94 -> V_236 ) ;
if ( ! V_134 )
V_134 = & V_232 -> V_134 ;
if ( ! V_134 -> V_226 ) {
F_48 ( & V_94 -> V_95 , L_18 ) ;
return - V_234 ;
}
V_49 = F_108 ( V_95 , sizeof( struct V_2 ) ) ;
if ( ! V_49 ) {
F_48 ( & V_94 -> V_95 , L_19 ) ;
F_109 ( V_134 ) ;
return - V_186 ;
}
V_3 = F_71 ( V_49 ) ;
V_3 -> V_49 = V_49 ;
V_3 -> V_37 = V_232 ;
V_3 -> V_94 = V_94 ;
V_3 -> V_134 = V_134 ;
V_49 -> V_95 . V_210 = & V_94 -> V_95 ;
V_49 -> V_95 . V_237 = V_94 -> V_95 . V_237 ;
V_49 -> V_238 = V_198 | V_197 | V_176 | V_199 ;
V_49 -> V_239 = V_134 -> V_203 ;
V_49 -> V_240 = V_241 ;
V_49 -> F_89 = F_89 ;
V_49 -> F_78 = F_78 ;
V_49 -> V_242 = F_70 ;
V_49 -> V_243 = F_73 ;
V_49 -> V_244 = true ;
V_3 -> V_5 = V_134 -> type ;
V_3 -> V_33 = V_134 -> V_226 ;
V_3 -> V_245 = V_134 -> V_224 + V_64 ;
if ( F_47 ( V_3 ) ) {
switch ( V_3 -> V_5 ) {
case V_10 :
V_49 -> V_246 = F_110 ( 4 , 32 ) ;
break;
default:
V_49 -> V_246 = F_110 ( 4 , 16 ) ;
break;
}
V_3 -> V_90 = V_100 | V_247 ;
V_3 -> V_162 = 0 ;
V_3 -> V_91 = V_66 ;
V_3 -> V_101 = V_248 | V_102 | V_66 ;
} else {
V_49 -> V_246 = F_110 ( 4 , 32 ) ;
V_3 -> V_90 = V_100 | V_247 | V_114 ;
V_3 -> V_162 = V_249 ;
V_3 -> V_91 = V_66 | V_105 ;
V_3 -> V_101 = V_105 | V_248 | V_102 | V_66 ;
}
V_112 = F_111 ( V_134 -> V_110 , F_52 , V_250 , F_112 ( V_95 ) ,
V_3 ) ;
if ( V_112 < 0 ) {
F_48 ( & V_94 -> V_95 , L_20 , V_134 -> V_110 ) ;
goto V_251;
}
if ( V_232 -> V_38 ) {
V_112 = F_113 ( V_3 ) ;
if ( V_112 ) {
F_65 ( V_95 , L_21 ) ;
V_232 -> V_38 = false ;
}
}
F_114 ( V_134 -> V_230 ) ;
V_49 -> V_50 = F_115 ( V_134 -> V_230 ) ;
F_24 ( V_3 , V_93 , 0 ) ;
switch ( V_3 -> V_5 ) {
case V_10 :
V_233 = F_10 ( V_13 )
| F_86 ( V_180 ) ;
F_24 ( V_3 , V_89 , V_233 ) ;
F_24 ( V_3 , V_93 ,
V_25
| F_13 ( 8 ) ) ;
break;
default:
V_233 = F_11 ( V_14 ) |
F_87 ( V_184 ) ;
F_24 ( V_3 , V_89 , V_233 ) ;
V_233 = F_66 ( 2 ) | V_27 | F_14 ( 8 ) ;
F_24 ( V_3 , V_93 , V_233 ) ;
break;
}
if ( ! F_47 ( V_3 ) )
F_24 ( V_3 , V_92 , 0 ) ;
if ( ! F_3 ( V_3 ) )
F_24 ( V_3 , V_252 , 0 ) ;
if ( F_2 ( V_3 ) )
F_20 ( V_3 ) ;
if ( F_2 ( V_3 ) ) {
F_20 ( V_3 ) ;
V_32 = F_1 ( V_3 ) ;
if ( V_32 -> V_253 >= 0 ) {
V_233 = F_15 ( V_3 ,
V_32 -> V_253 ) ;
V_233 &= V_254 ;
V_233 >>= V_255 ;
V_232 -> V_231 = F_116 ( V_233 ) ;
}
}
V_49 -> V_231 = V_232 -> V_231 ;
F_117 ( & V_3 -> V_96 , V_96 ,
( unsigned long ) V_3 ) ;
F_118 ( & V_94 -> V_95 , 50 ) ;
F_119 ( & V_94 -> V_95 ) ;
F_120 ( & V_94 -> V_95 ) ;
F_121 ( & V_94 -> V_95 ) ;
F_122 ( V_94 , V_3 ) ;
V_112 = F_123 ( & V_94 -> V_95 , V_49 ) ;
if ( V_112 != 0 ) {
F_48 ( & V_94 -> V_95 , L_22 ) ;
goto V_256;
}
return V_112 ;
V_256:
F_124 ( V_134 -> V_230 ) ;
F_125 ( V_3 ) ;
F_126 ( V_134 -> V_110 , V_3 ) ;
V_251:
F_127 ( V_49 ) ;
F_109 ( V_134 ) ;
return V_112 ;
}
static int F_128 ( struct V_212 * V_94 )
{
struct V_2 * V_3 = F_129 ( V_94 ) ;
struct V_133 * V_134 ;
if ( ! V_3 )
return 0 ;
V_134 = V_3 -> V_134 ;
F_130 ( & V_94 -> V_95 ) ;
F_24 ( V_3 , V_93 , 0 ) ;
F_124 ( V_134 -> V_230 ) ;
if ( V_3 -> V_37 -> V_38 )
F_125 ( V_3 ) ;
F_131 ( & V_94 -> V_95 ) ;
F_132 ( & V_94 -> V_95 ) ;
F_126 ( V_134 -> V_110 , V_3 ) ;
F_109 ( V_134 ) ;
return 0 ;
}
static void F_133 ( struct V_212 * V_94 )
{
int V_112 = 0 ;
if ( ( V_112 = F_128 ( V_94 ) ) != 0 )
F_48 ( & V_94 -> V_95 , L_23 , V_112 ) ;
}
static int F_134 ( struct V_209 * V_95 )
{
struct V_2 * V_3 = F_135 ( V_95 ) ;
struct V_133 * V_134 = V_3 -> V_134 ;
int V_112 = 0 ;
V_112 = F_136 ( V_3 -> V_49 ) ;
if ( V_112 != 0 )
return V_112 ;
F_24 ( V_3 , V_93 , 0 ) ;
if ( ! F_53 ( V_95 ) )
F_124 ( V_134 -> V_230 ) ;
return 0 ;
}
static int F_137 ( struct V_209 * V_95 )
{
struct V_2 * V_3 = F_135 ( V_95 ) ;
struct V_133 * V_134 = V_3 -> V_134 ;
int V_112 = 0 ;
if ( ! F_53 ( V_95 ) )
F_114 ( V_134 -> V_230 ) ;
if ( F_2 ( V_3 ) )
F_20 ( V_3 ) ;
V_112 = F_138 ( V_3 -> V_49 ) ;
if ( V_112 != 0 ) {
F_48 ( V_95 , L_24 , V_112 ) ;
return V_112 ;
}
return 0 ;
}
static int F_139 ( struct V_209 * V_95 )
{
struct V_2 * V_3 = F_135 ( V_95 ) ;
F_124 ( V_3 -> V_134 -> V_230 ) ;
return 0 ;
}
static int F_140 ( struct V_209 * V_95 )
{
struct V_2 * V_3 = F_135 ( V_95 ) ;
F_114 ( V_3 -> V_134 -> V_230 ) ;
return 0 ;
}
static int T_6 F_141 ( void )
{
return F_142 ( & V_221 ) ;
}
static void T_7 F_143 ( void )
{
F_144 ( & V_221 ) ;
}
