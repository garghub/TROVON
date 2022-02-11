static bool F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static T_1 F_3 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_5 :
return V_6 ;
default:
return V_7 ;
}
}
static T_1
F_4 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_5 :
return V_8 ;
default:
return V_9 ;
}
}
static bool F_5 ( const struct V_1 * V_2 )
{
T_1 V_10 ;
switch ( V_2 -> V_3 ) {
case V_5 :
V_10 = V_11 ;
break;
default:
V_10 = V_12 ;
break;
}
return ( F_6 ( V_2 , V_13 ) & V_10 ) == V_10 ;
}
static void F_7 ( const struct V_1 * V_2 ,
T_1 * V_14 )
{
T_1 V_10 ;
switch ( V_2 -> V_3 ) {
case V_5 :
V_10 = V_15 ;
break;
default:
V_10 = V_16 ;
break;
}
* V_14 &= ~ V_10 ;
}
static void F_8 ( const struct V_1 * V_2 ,
T_1 * V_14 , T_1 V_17 )
{
switch ( V_2 -> V_3 ) {
case V_5 :
* V_14 |= F_9 ( V_17 ) ;
break;
default:
* V_14 |= F_10 ( V_17 ) ;
break;
}
}
static T_1 F_11 ( const struct V_1 * V_2 ,
T_1 V_18 , T_2 V_19 )
{
switch ( V_2 -> V_3 ) {
case V_5 :
return V_18
| V_20
| F_12 ( V_19 > 32 ? 8 : V_19 )
| V_21 ;
default:
return V_18
| V_22
| F_13 ( V_19 > 16 ? V_19 - 16 : V_19 )
| V_21
| ( V_19 > 16 ? V_23 : 0 ) ;
}
}
static T_1 F_14 ( struct V_1 * V_2 , unsigned V_24 )
{
F_15 ( ! V_2 -> V_25 ) ;
return F_16 ( V_2 -> V_25 + V_24 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned V_24 , T_1 V_26 )
{
F_15 ( ! V_2 -> V_25 ) ;
F_18 ( V_26 , V_2 -> V_25 + V_24 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned V_24 = 0x400 ;
T_1 V_26 , V_27 ;
V_27 = F_16 ( V_2 -> V_28 + V_24 + V_29 ) ;
V_26 = V_27 | V_30 ;
F_18 ( V_26 , V_2 -> V_28 + V_24 + V_29 ) ;
V_26 = F_16 ( V_2 -> V_28 + V_24 + V_29 ) ;
if ( V_26 != ( V_27 | V_30 ) ) {
V_24 = 0x800 ;
goto V_31;
}
V_27 = F_16 ( V_2 -> V_28 + V_24 + V_29 ) ;
V_26 = V_27 & ~ V_30 ;
F_18 ( V_26 , V_2 -> V_28 + V_24 + V_29 ) ;
V_26 = F_16 ( V_2 -> V_28 + V_24 + V_29 ) ;
if ( V_26 != ( V_27 & ~ V_30 ) ) {
V_24 = 0x800 ;
goto V_31;
}
V_31:
V_2 -> V_25 = V_2 -> V_28 + V_24 ;
V_26 = V_30 | V_32 ;
F_17 ( V_2 , V_29 , V_26 ) ;
if ( V_2 -> V_33 -> V_34 ) {
F_17 ( V_2 , V_35 , 1 ) ;
V_26 = F_14 ( V_2 , V_36 ) ;
V_26 |= V_37 ;
F_17 ( V_2 , V_36 , V_26 ) ;
}
}
static void F_20 ( struct V_1 * V_2 , bool V_38 )
{
T_1 V_26 ;
V_26 = F_14 ( V_2 , V_29 ) ;
if ( V_38 )
V_26 &= ~ V_32 ;
else
V_26 |= V_32 ;
F_17 ( V_2 , V_29 , V_26 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_41 ;
if ( V_2 -> V_3 == V_42 ) {
F_22 ( V_2 , V_13 , V_2 -> V_41 -> V_43 ) ;
return;
}
if ( V_40 -> V_44 ) {
V_40 -> V_44 ( V_45 ) ;
return;
}
if ( F_23 ( V_40 -> V_46 ) ) {
F_24 ( V_40 -> V_46 , V_40 -> V_47 ) ;
return;
}
if ( F_1 ( V_2 ) )
F_20 ( V_2 , true ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_41 ;
if ( V_2 -> V_3 == V_42 )
return;
if ( V_40 -> V_44 ) {
V_40 -> V_44 ( V_48 ) ;
return;
}
if ( F_23 ( V_40 -> V_46 ) ) {
F_24 ( V_40 -> V_46 , ! V_40 -> V_47 ) ;
return;
}
if ( F_1 ( V_2 ) )
F_20 ( V_2 , false ) ;
}
int F_26 ( struct V_1 * V_2 )
{
unsigned long V_49 = V_50 << 1 ;
do {
while ( F_6 ( V_2 , V_13 ) & V_51 )
F_6 ( V_2 , V_52 ) ;
} while ( ( F_6 ( V_2 , V_13 ) & V_53 ) && -- V_49 );
F_27 ( V_2 , V_54 ) ;
return V_49 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_2 V_55 = V_2 -> V_55 ;
if ( F_5 ( V_2 )
|| ( V_2 -> V_56 == V_2 -> V_57 ) )
return 0 ;
F_22 ( V_2 , V_52 , 0 ) ;
V_2 -> V_56 += V_55 ;
return 1 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_2 V_55 = V_2 -> V_55 ;
while ( ( F_6 ( V_2 , V_13 ) & V_51 )
&& ( V_2 -> V_58 < V_2 -> V_59 ) ) {
F_6 ( V_2 , V_52 ) ;
V_2 -> V_58 += V_55 ;
}
return V_2 -> V_58 == V_2 -> V_59 ;
}
static int F_30 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 )
|| ( V_2 -> V_56 == V_2 -> V_57 ) )
return 0 ;
F_22 ( V_2 , V_52 , * ( T_2 * ) ( V_2 -> V_56 ) ) ;
++ V_2 -> V_56 ;
return 1 ;
}
static int F_31 ( struct V_1 * V_2 )
{
while ( ( F_6 ( V_2 , V_13 ) & V_51 )
&& ( V_2 -> V_58 < V_2 -> V_59 ) ) {
* ( T_2 * ) ( V_2 -> V_58 ) = F_6 ( V_2 , V_52 ) ;
++ V_2 -> V_58 ;
}
return V_2 -> V_58 == V_2 -> V_59 ;
}
static int F_32 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 )
|| ( V_2 -> V_56 == V_2 -> V_57 ) )
return 0 ;
F_22 ( V_2 , V_52 , * ( V_60 * ) ( V_2 -> V_56 ) ) ;
V_2 -> V_56 += 2 ;
return 1 ;
}
static int F_33 ( struct V_1 * V_2 )
{
while ( ( F_6 ( V_2 , V_13 ) & V_51 )
&& ( V_2 -> V_58 < V_2 -> V_59 ) ) {
* ( V_60 * ) ( V_2 -> V_58 ) = F_6 ( V_2 , V_52 ) ;
V_2 -> V_58 += 2 ;
}
return V_2 -> V_58 == V_2 -> V_59 ;
}
static int F_34 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 )
|| ( V_2 -> V_56 == V_2 -> V_57 ) )
return 0 ;
F_22 ( V_2 , V_52 , * ( T_1 * ) ( V_2 -> V_56 ) ) ;
V_2 -> V_56 += 4 ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 )
{
while ( ( F_6 ( V_2 , V_13 ) & V_51 )
&& ( V_2 -> V_58 < V_2 -> V_59 ) ) {
* ( T_1 * ) ( V_2 -> V_58 ) = F_6 ( V_2 , V_52 ) ;
V_2 -> V_58 += 4 ;
}
return V_2 -> V_58 == V_2 -> V_59 ;
}
void * F_36 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_63 ;
struct V_64 * V_65 = V_2 -> V_66 ;
if ( V_65 -> V_67 . V_68 != & V_62 -> V_69 ) {
V_2 -> V_66 =
F_37 ( V_65 -> V_67 . V_68 ,
struct V_64 ,
V_67 ) ;
return V_70 ;
} else
return V_71 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_64 * V_72 ;
struct V_61 * V_62 ;
V_62 = V_2 -> V_63 ;
V_2 -> V_63 = NULL ;
V_2 -> V_66 = NULL ;
V_72 = F_39 ( & V_62 -> V_69 , struct V_64 ,
V_67 ) ;
if ( V_72 -> V_73 )
F_40 ( V_72 -> V_73 ) ;
if ( ! V_72 -> V_74 )
F_25 ( V_2 ) ;
else {
struct V_61 * V_75 ;
V_75 = F_41 ( V_2 -> V_76 ) ;
if ( V_75 && V_75 -> V_77 != V_62 -> V_77 )
V_75 = NULL ;
if ( ! V_75 || V_62 -> V_78 == V_79 )
F_25 ( V_2 ) ;
}
V_2 -> V_41 = NULL ;
F_42 ( V_2 -> V_76 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_41 ;
T_1 V_14 ;
V_14 = F_6 ( V_2 , V_80 ) & ~ V_2 -> V_81 ;
V_14 &= ~ V_16 ;
V_14 |= V_40 -> V_17 ;
F_22 ( V_2 , V_80 , V_14 ) ;
}
static void F_44 ( struct V_1 * V_2 , const char * V_62 )
{
F_27 ( V_2 , V_2 -> V_82 ) ;
F_43 ( V_2 ) ;
if ( ! F_45 ( V_2 ) )
F_22 ( V_2 , V_83 , 0 ) ;
F_26 ( V_2 ) ;
F_22 ( V_2 , V_84 ,
F_6 ( V_2 , V_84 ) & ~ V_21 ) ;
F_46 ( & V_2 -> V_85 -> V_86 , L_1 , V_62 ) ;
V_2 -> V_63 -> V_78 = V_79 ;
F_47 ( & V_2 -> V_87 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_2 -> V_82 ) ;
F_43 ( V_2 ) ;
if ( ! F_45 ( V_2 ) )
F_22 ( V_2 , V_83 , 0 ) ;
V_2 -> V_63 -> V_88 += V_2 -> V_89 -
( V_2 -> V_59 - V_2 -> V_58 ) ;
V_2 -> V_63 -> V_78 = F_36 ( V_2 ) ;
F_47 ( & V_2 -> V_87 ) ;
}
static T_3 F_49 ( struct V_1 * V_2 )
{
T_1 V_90 = ( F_6 ( V_2 , V_80 ) & V_91 ) ?
V_2 -> V_92 : V_2 -> V_92 & ~ V_93 ;
T_1 V_94 = F_6 ( V_2 , V_13 ) & V_90 ;
if ( V_94 & V_54 ) {
F_44 ( V_2 , L_2 ) ;
return V_95 ;
}
if ( V_94 & V_96 ) {
F_22 ( V_2 , V_13 , V_96 ) ;
if ( V_2 -> V_97 ( V_2 ) ) {
F_48 ( V_2 ) ;
return V_95 ;
}
}
do {
if ( V_2 -> V_97 ( V_2 ) ) {
F_48 ( V_2 ) ;
return V_95 ;
}
} while ( V_2 -> V_98 ( V_2 ) );
if ( V_2 -> V_97 ( V_2 ) ) {
F_48 ( V_2 ) ;
return V_95 ;
}
if ( V_2 -> V_56 == V_2 -> V_57 ) {
T_1 V_99 ;
T_1 V_14 ;
V_14 = F_6 ( V_2 , V_80 ) ;
V_14 &= ~ V_91 ;
if ( F_45 ( V_2 ) ) {
T_1 V_100 ;
F_7 ( V_2 , & V_14 ) ;
V_99 = V_2 -> V_59 - V_2 -> V_58 ;
switch ( V_2 -> V_55 ) {
case 4 :
V_99 >>= 1 ;
case 2 :
V_99 >>= 1 ;
}
V_100 = F_4 ( V_2 ) ;
if ( V_100 > V_99 )
V_100 = V_99 ;
F_8 ( V_2 , & V_14 , V_100 ) ;
}
F_22 ( V_2 , V_80 , V_14 ) ;
}
return V_95 ;
}
static T_3 F_50 ( int V_101 , void * V_102 )
{
struct V_1 * V_2 = V_102 ;
T_1 V_14 ;
T_1 V_10 = V_2 -> V_92 ;
T_1 V_103 ;
if ( F_51 ( & V_2 -> V_85 -> V_86 ) )
return V_104 ;
V_103 = F_6 ( V_2 , V_13 ) ;
if ( V_103 == ~ 0 )
return V_104 ;
V_14 = F_6 ( V_2 , V_80 ) ;
if ( ! ( V_14 & V_91 ) )
V_10 &= ~ V_93 ;
if ( ! ( V_103 & V_10 ) )
return V_104 ;
if ( ! V_2 -> V_63 ) {
F_22 ( V_2 , V_84 ,
F_6 ( V_2 , V_84 )
& ~ V_21 ) ;
F_22 ( V_2 , V_80 ,
F_6 ( V_2 , V_80 )
& ~ V_2 -> V_81 ) ;
if ( ! F_45 ( V_2 ) )
F_22 ( V_2 , V_83 , 0 ) ;
F_27 ( V_2 , V_2 -> V_82 ) ;
F_46 ( & V_2 -> V_85 -> V_86 ,
L_3 ) ;
return V_95 ;
}
return V_2 -> V_105 ( V_2 ) ;
}
static unsigned int F_52 ( int V_106 , T_1 * V_107 )
{
unsigned long V_108 = 200000000 ;
unsigned long V_109 = V_108 / 2 ;
unsigned long V_110 = V_109 / 2 ;
unsigned long V_111 = V_109 * 2 / 5 ;
unsigned long V_112 ;
unsigned long V_113 , V_114 , V_115 ;
long V_116 , V_117 , V_118 ;
T_1 V_119 ;
V_119 = ( 1 << 24 ) >> 1 ;
V_114 = F_53 ( V_110 , V_106 ) ;
if ( V_114 > 256 ) {
V_112 = F_54 ( V_114 - 1 ) ;
if ( V_112 > 9 ) {
V_114 >>= V_112 - 9 ;
V_119 >>= V_112 - 9 ;
}
V_114 += V_114 & 1 ;
}
V_112 = F_55 ( V_114 ) ;
V_114 >>= V_112 ;
V_119 >>= V_112 ;
V_117 = abs ( V_110 / ( 1 << ( 24 - F_54 ( V_119 ) ) ) / V_114 - V_106 ) ;
V_115 = F_53 ( V_111 , V_106 ) ;
V_118 = abs ( V_111 / V_115 - V_106 ) ;
if ( V_118 >= V_117 || V_115 > 256 ) {
V_116 = V_117 ;
V_113 = V_114 ;
} else {
V_116 = V_118 ;
V_113 = V_115 ;
V_119 = ( 1 << 24 ) * 2 / 5 ;
}
if ( V_109 / V_106 >= 80 ) {
T_4 V_120 ;
T_1 V_121 ;
V_114 = F_53 ( V_109 , V_106 ) ;
V_121 = ( 1 << 24 ) / V_114 ;
V_120 = ( T_4 ) V_109 * V_121 ;
F_56 ( V_120 , 1 << 24 ) ;
V_117 = abs ( V_120 - V_106 ) ;
if ( V_117 < V_116 ) {
V_113 = 1 ;
V_119 = V_121 ;
}
}
* V_107 = V_119 ;
return V_113 - 1 ;
}
static unsigned int F_57 ( struct V_1 * V_2 , int V_106 )
{
unsigned long V_122 = V_2 -> V_123 ;
const struct V_124 * V_125 = V_2 -> V_125 ;
V_106 = F_58 ( int , V_122 , V_106 ) ;
if ( V_125 -> type == V_126 || V_125 -> type == V_42 )
return ( V_122 / ( 2 * V_106 ) - 1 ) & 0xff ;
else
return ( V_122 / V_106 - 1 ) & 0xfff ;
}
static unsigned int F_59 ( struct V_1 * V_2 ,
struct V_39 * V_40 , int V_106 )
{
unsigned int V_18 ;
switch ( V_2 -> V_3 ) {
case V_5 :
V_18 = F_52 ( V_106 , & V_40 -> V_127 ) ;
break;
default:
V_18 = F_57 ( V_2 , V_106 ) ;
break;
}
return V_18 << 8 ;
}
static void V_87 ( unsigned long V_128 )
{
struct V_1 * V_2 = (struct V_1 * ) V_128 ;
struct V_61 * V_129 = NULL ;
struct V_64 * V_130 = NULL ;
struct V_64 * V_131 = NULL ;
struct V_39 * V_40 = NULL ;
T_1 V_18 = 0 ;
T_2 V_19 = 0 ;
T_1 V_132 = 0 ;
T_1 V_133 ;
T_1 V_134 ;
T_1 V_135 = V_2 -> V_41 -> V_136 ;
T_1 V_137 = V_2 -> V_41 -> V_138 ;
T_1 V_139 = F_3 ( V_2 ) ;
V_129 = V_2 -> V_63 ;
V_130 = V_2 -> V_66 ;
V_40 = V_2 -> V_41 ;
if ( V_129 -> V_78 == V_79 ) {
V_129 -> V_103 = - V_140 ;
F_38 ( V_2 ) ;
return;
}
if ( V_129 -> V_78 == V_71 ) {
V_129 -> V_103 = 0 ;
F_38 ( V_2 ) ;
return;
}
if ( V_129 -> V_78 == V_70 ) {
V_131 = F_37 ( V_130 -> V_67 . V_141 ,
struct V_64 ,
V_67 ) ;
if ( V_131 -> V_73 )
F_40 ( V_131 -> V_73 ) ;
if ( V_131 -> V_74 )
F_25 ( V_2 ) ;
}
if ( ! F_60 ( V_130 -> V_89 ) && V_40 -> V_34 ) {
if ( V_129 -> V_142
|| V_130 -> V_143 || V_130 -> V_144 ) {
F_46 ( & V_2 -> V_85 -> V_86 ,
L_4
L_5 ,
V_130 -> V_89 , V_145 ) ;
V_129 -> V_103 = - V_146 ;
F_38 ( V_2 ) ;
return;
}
F_61 ( & V_129 -> V_77 -> V_86 ,
L_6
L_7 ,
( long ) V_2 -> V_89 , V_145 ) ;
}
if ( F_26 ( V_2 ) == 0 ) {
F_46 ( & V_2 -> V_85 -> V_86 , L_8 ) ;
V_129 -> V_103 = - V_140 ;
F_38 ( V_2 ) ;
return;
}
V_2 -> V_55 = V_40 -> V_55 ;
V_2 -> V_56 = ( void * ) V_130 -> V_147 ;
V_2 -> V_57 = V_2 -> V_56 + V_130 -> V_89 ;
V_2 -> V_58 = V_130 -> V_148 ;
V_2 -> V_59 = V_2 -> V_58 + V_130 -> V_89 ;
V_2 -> V_143 = V_130 -> V_143 ;
V_2 -> V_144 = V_130 -> V_144 ;
V_2 -> V_89 = V_130 -> V_89 ;
V_2 -> V_98 = V_2 -> V_56 ? V_40 -> V_98 : F_28 ;
V_2 -> V_97 = V_2 -> V_58 ? V_40 -> V_97 : F_29 ;
V_133 = V_40 -> V_133 ;
if ( V_130 -> V_149 || V_130 -> V_150 ) {
V_19 = V_40 -> V_150 ;
V_132 = V_40 -> V_149 ;
if ( V_130 -> V_149 )
V_132 = V_130 -> V_149 ;
if ( V_130 -> V_150 )
V_19 = V_130 -> V_150 ;
V_18 = F_59 ( V_2 , V_40 , V_132 ) ;
if ( V_19 <= 8 ) {
V_2 -> V_55 = 1 ;
V_2 -> V_97 = V_2 -> V_97 != F_29 ?
F_31 : F_29 ;
V_2 -> V_98 = V_2 -> V_98 != F_28 ?
F_30 : F_28 ;
} else if ( V_19 <= 16 ) {
V_2 -> V_55 = 2 ;
V_2 -> V_97 = V_2 -> V_97 != F_29 ?
F_33 : F_29 ;
V_2 -> V_98 = V_2 -> V_98 != F_28 ?
F_32 : F_28 ;
} else if ( V_19 <= 32 ) {
V_2 -> V_55 = 4 ;
V_2 -> V_97 = V_2 -> V_97 != F_29 ?
F_35 : F_29 ;
V_2 -> V_98 = V_2 -> V_98 != F_28 ?
F_34 : F_28 ;
}
if ( V_40 -> V_34 ) {
if ( F_62 ( V_40 ,
V_129 -> V_77 ,
V_19 , & V_137 ,
& V_135 ) )
F_61 ( & V_129 -> V_77 -> V_86 ,
L_9 ) ;
}
V_133 = F_11 ( V_2 , V_18 , V_19 ) ;
}
V_129 -> V_78 = V_70 ;
V_2 -> V_151 = 0 ;
if ( F_60 ( V_2 -> V_89 ) )
V_2 -> V_151 = F_63 ( V_2 ) ;
if ( V_2 -> V_151 ) {
V_2 -> V_105 = V_152 ;
F_64 ( V_2 , V_137 ) ;
V_134 = V_40 -> V_134 | V_135 | V_2 -> V_153 ;
F_22 ( V_2 , V_13 , V_2 -> V_82 ) ;
F_65 ( V_2 ) ;
} else {
V_2 -> V_105 = F_49 ;
V_134 = V_40 -> V_134 | V_40 -> V_17 | V_2 -> V_81 ;
F_27 ( V_2 , V_2 -> V_82 ) ;
}
if ( F_1 ( V_2 ) ) {
if ( ( F_6 ( V_2 , V_154 ) & 0xff )
!= V_40 -> V_155 )
F_22 ( V_2 , V_154 ,
V_40 -> V_155 ) ;
if ( ( F_6 ( V_2 , V_156 ) & 0xffff )
!= V_40 -> V_157 )
F_22 ( V_2 , V_156 ,
V_40 -> V_157 ) ;
}
if ( F_2 ( V_2 ) &&
( F_6 ( V_2 , V_158 ) != V_40 -> V_127 ) )
F_22 ( V_2 , V_158 , V_40 -> V_127 ) ;
if ( ( F_6 ( V_2 , V_84 ) != V_133 )
|| ( F_6 ( V_2 , V_80 ) & V_139 )
!= ( V_134 & V_139 ) ) {
F_22 ( V_2 , V_84 , V_133 & ~ V_21 ) ;
if ( ! F_45 ( V_2 ) )
F_22 ( V_2 , V_83 , V_40 -> V_159 ) ;
F_22 ( V_2 , V_80 , V_134 & V_139 ) ;
F_22 ( V_2 , V_84 , V_133 ) ;
} else {
if ( ! F_45 ( V_2 ) )
F_22 ( V_2 , V_83 , V_40 -> V_159 ) ;
}
F_21 ( V_2 ) ;
F_22 ( V_2 , V_80 , V_134 ) ;
}
static int F_66 ( struct V_160 * V_76 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_67 ( V_76 ) ;
V_2 -> V_63 = V_62 ;
V_2 -> V_63 -> V_78 = V_161 ;
V_2 -> V_66 = F_37 ( V_2 -> V_63 -> V_69 . V_68 ,
struct V_64 ,
V_67 ) ;
V_2 -> V_41 = F_68 ( V_2 -> V_63 -> V_77 ) ;
F_47 ( & V_2 -> V_87 ) ;
return 0 ;
}
static int F_69 ( struct V_160 * V_76 )
{
struct V_1 * V_2 = F_67 ( V_76 ) ;
F_22 ( V_2 , V_84 ,
F_6 ( V_2 , V_84 ) & ~ V_21 ) ;
return 0 ;
}
static int F_70 ( struct V_162 * V_77 , struct V_39 * V_40 ,
struct V_163 * V_164 )
{
int V_165 = 0 ;
if ( V_40 == NULL || V_164 == NULL )
return 0 ;
if ( F_23 ( V_40 -> V_46 ) )
F_71 ( V_40 -> V_46 ) ;
if ( V_164 -> V_44 ) {
V_40 -> V_44 = V_164 -> V_44 ;
return 0 ;
}
if ( F_23 ( V_164 -> V_46 ) ) {
V_165 = F_72 ( V_164 -> V_46 , L_10 ) ;
if ( V_165 ) {
F_46 ( & V_77 -> V_86 , L_11 ,
V_164 -> V_46 ) ;
return V_165 ;
}
V_40 -> V_46 = V_164 -> V_46 ;
V_40 -> V_47 = V_77 -> V_166 & V_167 ;
V_165 = F_73 ( V_40 -> V_46 ,
! V_40 -> V_47 ) ;
}
return V_165 ;
}
static int F_74 ( struct V_162 * V_77 )
{
struct V_163 * V_164 = NULL ;
struct V_39 * V_40 ;
struct V_1 * V_2 = F_67 ( V_77 -> V_76 ) ;
unsigned int V_18 ;
T_5 V_168 , V_169 , V_170 ;
switch ( V_2 -> V_3 ) {
case V_5 :
V_168 = V_171 ;
V_169 = 0 ;
V_170 = V_8 ;
break;
case V_4 :
V_168 = V_172 ;
V_169 = V_173 ;
V_170 = V_174 ;
break;
default:
V_168 = V_175 ;
V_169 = 0 ;
V_170 = V_9 ;
break;
}
V_40 = F_68 ( V_77 ) ;
if ( ! V_40 ) {
V_40 = F_75 ( sizeof( struct V_39 ) , V_176 ) ;
if ( ! V_40 )
return - V_177 ;
if ( V_2 -> V_3 == V_42 ) {
if ( V_77 -> V_178 > 4 ) {
F_46 ( & V_77 -> V_86 ,
L_12 ) ;
F_76 ( V_40 ) ;
return - V_146 ;
}
V_40 -> V_43 = V_77 -> V_178 ;
} else
V_40 -> V_46 = - 1 ;
V_40 -> V_34 = 0 ;
V_40 -> V_159 = V_179 ;
}
V_164 = V_77 -> V_180 ;
V_40 -> V_134 = 0 ;
if ( V_164 ) {
if ( V_164 -> V_159 )
V_40 -> V_159 = V_164 -> V_159 ;
if ( V_164 -> V_181 )
V_168 = V_164 -> V_181 ;
if ( V_164 -> V_182 )
V_169 = V_164 -> V_182 ;
if ( V_164 -> V_183 )
V_170 = V_164 -> V_183 ;
V_40 -> V_34 = V_2 -> V_33 -> V_34 ;
V_40 -> V_136 = 0 ;
if ( V_164 -> V_184 )
V_40 -> V_134 = V_185 ;
} else if ( F_77 ( & V_77 -> V_86 ) ) {
V_40 -> V_34 = V_2 -> V_33 -> V_34 ;
}
V_40 -> V_155 = F_78 ( V_170 ) ;
V_40 -> V_157 = F_79 ( V_168 )
| F_80 ( V_169 ) ;
if ( V_40 -> V_34 ) {
if ( F_62 ( V_40 , V_77 ,
V_77 -> V_150 ,
& V_40 -> V_138 ,
& V_40 -> V_136 ) ) {
F_81 ( & V_77 -> V_86 ,
L_13 ) ;
}
}
V_18 = F_59 ( V_2 , V_40 , V_77 -> V_186 ) ;
V_40 -> V_149 = V_77 -> V_186 ;
V_40 -> V_133 = F_11 ( V_2 , V_18 ,
V_77 -> V_150 ) ;
switch ( V_2 -> V_3 ) {
case V_5 :
V_40 -> V_17 = ( F_9 ( V_170 )
& V_15 )
| ( F_82 ( V_168 )
& V_187 ) ;
break;
default:
V_40 -> V_17 = ( F_10 ( V_170 ) & V_16 ) |
( F_83 ( V_168 ) & V_188 ) ;
break;
}
V_40 -> V_134 &= ~ ( V_189 | V_190 ) ;
V_40 -> V_134 |= ( ( ( V_77 -> V_166 & V_191 ) != 0 ) ? V_190 : 0 )
| ( ( ( V_77 -> V_166 & V_192 ) != 0 ) ? V_189 : 0 ) ;
if ( V_77 -> V_166 & V_193 )
V_40 -> V_134 |= V_185 ;
if ( ! F_45 ( V_2 ) )
F_84 ( & V_77 -> V_86 , L_14 ,
V_2 -> V_123
/ ( 1 + ( ( V_40 -> V_133 & F_85 ( 0xfff ) ) >> 8 ) ) ,
V_40 -> V_34 ? L_15 : L_16 ) ;
else
F_84 ( & V_77 -> V_86 , L_14 ,
V_2 -> V_123 / 2
/ ( 1 + ( ( V_40 -> V_133 & F_85 ( 0x0ff ) ) >> 8 ) ) ,
V_40 -> V_34 ? L_15 : L_16 ) ;
if ( V_77 -> V_150 <= 8 ) {
V_40 -> V_55 = 1 ;
V_40 -> V_97 = F_31 ;
V_40 -> V_98 = F_30 ;
} else if ( V_77 -> V_150 <= 16 ) {
V_40 -> V_55 = 2 ;
V_40 -> V_97 = F_33 ;
V_40 -> V_98 = F_32 ;
} else if ( V_77 -> V_150 <= 32 ) {
if ( ! F_2 ( V_2 ) )
V_40 -> V_133 |= V_23 ;
V_40 -> V_55 = 4 ;
V_40 -> V_97 = F_35 ;
V_40 -> V_98 = F_34 ;
}
V_40 -> V_150 = V_77 -> V_150 ;
F_86 ( V_77 , V_40 ) ;
if ( V_2 -> V_3 == V_42 )
return 0 ;
return F_70 ( V_77 , V_40 , V_164 ) ;
}
static void F_87 ( struct V_162 * V_77 )
{
struct V_39 * V_40 = F_68 ( V_77 ) ;
struct V_1 * V_2 = F_67 ( V_77 -> V_76 ) ;
if ( ! V_40 )
return;
if ( V_2 -> V_3 != V_42 && F_23 ( V_40 -> V_46 ) )
F_71 ( V_40 -> V_46 ) ;
F_76 ( V_40 ) ;
}
static struct V_194 *
F_88 ( struct V_195 * V_85 )
{
struct V_194 * V_196 ;
struct V_197 * V_198 ;
struct V_124 * V_125 ;
struct V_199 * V_200 ;
int V_201 ;
if ( ! F_77 ( & V_85 -> V_86 ) ||
F_89 ( F_77 ( & V_85 -> V_86 ) , & V_198 ) )
return NULL ;
V_196 = F_90 ( & V_85 -> V_86 , sizeof( * V_196 ) , V_176 ) ;
if ( ! V_196 )
return NULL ;
V_200 = F_91 ( V_85 , V_202 , 0 ) ;
if ( ! V_200 )
return NULL ;
V_125 = & V_196 -> V_125 ;
V_125 -> V_203 = V_200 -> V_204 ;
V_125 -> V_205 = F_92 ( & V_85 -> V_86 , V_200 ) ;
if ( F_93 ( V_125 -> V_205 ) )
return NULL ;
V_125 -> V_206 = F_94 ( & V_85 -> V_86 , NULL ) ;
V_125 -> V_101 = F_95 ( V_85 , 0 ) ;
V_125 -> type = V_4 ;
V_125 -> V_85 = V_85 ;
V_125 -> V_207 = - 1 ;
if ( V_198 -> V_208 . V_209 && ! F_96 ( V_198 -> V_208 . V_209 , 0 , & V_201 ) )
V_125 -> V_207 = V_201 ;
V_196 -> V_210 = 1 ;
V_196 -> V_34 = true ;
return V_196 ;
}
static inline struct V_194 *
F_88 ( struct V_195 * V_85 )
{
return NULL ;
}
static int F_97 ( struct V_195 * V_85 )
{
struct V_211 * V_86 = & V_85 -> V_86 ;
struct V_194 * V_212 ;
struct V_160 * V_76 ;
struct V_1 * V_2 ;
struct V_124 * V_125 ;
int V_103 ;
T_1 V_213 ;
V_212 = F_98 ( V_86 ) ;
if ( ! V_212 ) {
V_212 = F_88 ( V_85 ) ;
if ( ! V_212 ) {
F_46 ( & V_85 -> V_86 , L_17 ) ;
return - V_214 ;
}
}
V_125 = F_99 ( V_85 -> V_215 , V_85 -> V_216 ) ;
if ( ! V_125 )
V_125 = & V_212 -> V_125 ;
if ( ! V_125 -> V_205 ) {
F_46 ( & V_85 -> V_86 , L_18 ) ;
return - V_214 ;
}
V_76 = F_100 ( V_86 , sizeof( struct V_1 ) + 16 ) ;
if ( ! V_76 ) {
F_46 ( & V_85 -> V_86 , L_19 ) ;
F_101 ( V_125 ) ;
return - V_177 ;
}
V_2 = F_67 ( V_76 ) ;
V_2 -> V_76 = V_76 ;
V_2 -> V_33 = V_212 ;
V_2 -> V_85 = V_85 ;
V_2 -> V_125 = V_125 ;
V_76 -> V_86 . V_217 = & V_85 -> V_86 ;
V_76 -> V_86 . V_218 = V_85 -> V_86 . V_218 ;
V_76 -> V_219 = V_192 | V_191 | V_167 | V_193 ;
V_76 -> V_220 = V_125 -> V_207 ;
V_76 -> V_210 = V_212 -> V_210 ;
V_76 -> V_221 = V_222 ;
V_76 -> F_87 = F_87 ;
V_76 -> F_74 = F_74 ;
V_76 -> V_223 = F_66 ;
V_76 -> V_224 = F_69 ;
V_76 -> V_225 = true ;
V_2 -> V_3 = V_125 -> type ;
V_2 -> V_226 = ( T_1 * ) F_102 ( & V_2 [ 1 ] , V_222 ) ;
V_2 -> V_28 = V_125 -> V_205 ;
V_2 -> V_227 = V_125 -> V_203 + V_52 ;
if ( F_45 ( V_2 ) ) {
switch ( V_2 -> V_3 ) {
case V_5 :
V_76 -> V_228 = F_103 ( 4 , 32 ) ;
break;
default:
V_76 -> V_228 = F_103 ( 4 , 16 ) ;
break;
}
V_2 -> V_81 = V_91 | V_229 ;
V_2 -> V_153 = 0 ;
V_2 -> V_82 = V_54 ;
V_2 -> V_92 = V_230 | V_93 | V_54 ;
} else {
V_76 -> V_228 = F_103 ( 4 , 32 ) ;
V_2 -> V_81 = V_91 | V_229 | V_231 ;
V_2 -> V_153 = V_232 ;
V_2 -> V_82 = V_54 | V_96 ;
V_2 -> V_92 = V_96 | V_230 | V_93 | V_54 ;
}
V_103 = F_104 ( V_125 -> V_101 , F_50 , V_233 , F_105 ( V_86 ) ,
V_2 ) ;
if ( V_103 < 0 ) {
F_46 ( & V_85 -> V_86 , L_20 , V_125 -> V_101 ) ;
goto V_234;
}
V_2 -> V_235 = - 1 ;
V_2 -> V_236 = - 1 ;
if ( V_212 -> V_34 ) {
V_103 = F_106 ( V_2 ) ;
if ( V_103 ) {
F_84 ( V_86 , L_21 ) ;
V_212 -> V_34 = false ;
}
}
F_107 ( V_125 -> V_206 ) ;
V_2 -> V_123 = F_108 ( V_125 -> V_206 ) ;
F_22 ( V_2 , V_84 , 0 ) ;
switch ( V_2 -> V_3 ) {
case V_5 :
V_213 = F_9 ( V_8 )
| F_82 ( V_171 ) ;
F_22 ( V_2 , V_80 , V_213 ) ;
F_22 ( V_2 , V_84 ,
V_20
| F_12 ( 8 ) ) ;
break;
default:
V_213 = F_10 ( V_9 ) |
F_83 ( V_175 ) ;
F_22 ( V_2 , V_80 , V_213 ) ;
V_213 = F_85 ( 2 ) | V_22 | F_13 ( 8 ) ;
F_22 ( V_2 , V_84 , V_213 ) ;
break;
}
if ( ! F_45 ( V_2 ) )
F_22 ( V_2 , V_83 , 0 ) ;
if ( ! F_2 ( V_2 ) )
F_22 ( V_2 , V_237 , 0 ) ;
if ( F_1 ( V_2 ) )
F_19 ( V_2 ) ;
F_109 ( & V_2 -> V_87 , V_87 ,
( unsigned long ) V_2 ) ;
F_110 ( & V_85 -> V_86 , 50 ) ;
F_111 ( & V_85 -> V_86 ) ;
F_112 ( & V_85 -> V_86 ) ;
F_113 ( & V_85 -> V_86 ) ;
F_114 ( V_85 , V_2 ) ;
V_103 = F_115 ( & V_85 -> V_86 , V_76 ) ;
if ( V_103 != 0 ) {
F_46 ( & V_85 -> V_86 , L_22 ) ;
goto V_238;
}
return V_103 ;
V_238:
F_116 ( V_125 -> V_206 ) ;
F_117 ( V_2 ) ;
F_118 ( V_125 -> V_101 , V_2 ) ;
V_234:
F_119 ( V_76 ) ;
F_101 ( V_125 ) ;
return V_103 ;
}
static int F_120 ( struct V_195 * V_85 )
{
struct V_1 * V_2 = F_121 ( V_85 ) ;
struct V_124 * V_125 ;
if ( ! V_2 )
return 0 ;
V_125 = V_2 -> V_125 ;
F_122 ( & V_85 -> V_86 ) ;
F_22 ( V_2 , V_84 , 0 ) ;
F_116 ( V_125 -> V_206 ) ;
if ( V_2 -> V_33 -> V_34 )
F_117 ( V_2 ) ;
F_123 ( & V_85 -> V_86 ) ;
F_124 ( & V_85 -> V_86 ) ;
F_118 ( V_125 -> V_101 , V_2 ) ;
F_101 ( V_125 ) ;
return 0 ;
}
static void F_125 ( struct V_195 * V_85 )
{
int V_103 = 0 ;
if ( ( V_103 = F_120 ( V_85 ) ) != 0 )
F_46 ( & V_85 -> V_86 , L_23 , V_103 ) ;
}
static int F_126 ( struct V_211 * V_86 )
{
struct V_1 * V_2 = F_127 ( V_86 ) ;
struct V_124 * V_125 = V_2 -> V_125 ;
int V_103 = 0 ;
V_103 = F_128 ( V_2 -> V_76 ) ;
if ( V_103 != 0 )
return V_103 ;
F_22 ( V_2 , V_84 , 0 ) ;
if ( ! F_51 ( V_86 ) )
F_116 ( V_125 -> V_206 ) ;
return 0 ;
}
static int F_129 ( struct V_211 * V_86 )
{
struct V_1 * V_2 = F_127 ( V_86 ) ;
struct V_124 * V_125 = V_2 -> V_125 ;
int V_103 = 0 ;
F_130 ( V_2 ) ;
if ( ! F_51 ( V_86 ) )
F_107 ( V_125 -> V_206 ) ;
if ( F_1 ( V_2 ) )
F_19 ( V_2 ) ;
V_103 = F_131 ( V_2 -> V_76 ) ;
if ( V_103 != 0 ) {
F_46 ( V_86 , L_24 , V_103 ) ;
return V_103 ;
}
return 0 ;
}
static int F_132 ( struct V_211 * V_86 )
{
struct V_1 * V_2 = F_127 ( V_86 ) ;
F_116 ( V_2 -> V_125 -> V_206 ) ;
return 0 ;
}
static int F_133 ( struct V_211 * V_86 )
{
struct V_1 * V_2 = F_127 ( V_86 ) ;
F_107 ( V_2 -> V_125 -> V_206 ) ;
return 0 ;
}
static int T_6 F_134 ( void )
{
return F_135 ( & V_239 ) ;
}
static void T_7 F_136 ( void )
{
F_137 ( & V_239 ) ;
}
