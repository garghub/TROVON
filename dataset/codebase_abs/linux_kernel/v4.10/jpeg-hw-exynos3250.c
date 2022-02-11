void F_1 ( void T_1 * V_1 )
{
T_2 V_2 = 1 ;
int V_3 = 1000 ;
F_2 ( 1 , V_1 + V_4 ) ;
while ( V_2 != 0 && -- V_3 > 0 ) {
F_3 ( 1 ) ;
F_4 () ;
V_2 = F_5 ( V_1 + V_4 ) ;
}
V_2 = 0 ;
V_3 = 1000 ;
while ( V_2 != 1 && -- V_3 > 0 ) {
F_2 ( 1 , V_1 + V_5 ) ;
F_3 ( 1 ) ;
F_4 () ;
V_2 = F_5 ( V_1 + V_5 ) ;
}
F_2 ( 0 , V_1 + V_5 ) ;
}
void F_6 ( void T_1 * V_1 )
{
F_2 ( V_6 , V_1 + V_7 ) ;
}
void F_7 ( void T_1 * V_1 )
{
F_2 ( ( ( V_8 << V_9 ) &
V_10 ) |
( ( V_8 << V_11 ) &
V_12 ) |
( ( V_8 << V_13 ) &
V_14 ) ,
V_1 + V_15 ) ;
}
void F_8 ( void T_1 * V_16 )
{
T_2 V_2 ;
V_2 = F_5 ( V_16 + V_17 ) & ~ V_18 ;
F_2 ( V_2 | V_19 , V_16 + V_17 ) ;
}
void F_9 ( void T_1 * V_1 , unsigned int V_20 )
{
T_2 V_2 ;
V_2 = F_5 ( V_1 + V_17 ) &
V_21 ;
switch ( V_20 ) {
case V_22 :
V_2 |= V_23 ;
break;
case V_24 :
V_2 |= V_23 | V_25 ;
break;
case V_26 :
V_2 |= V_27 ;
break;
case V_28 :
V_2 |= V_27 | V_25 ;
break;
case V_29 :
V_2 |= V_30 ;
break;
case V_31 :
V_2 |= V_30 |
V_32 ;
break;
case V_33 :
V_2 |= V_34 ;
break;
case V_35 :
V_2 |= V_34 |
V_32 ;
break;
case V_36 :
V_2 |= V_37 | V_38 ;
break;
case V_39 :
V_2 |= V_37 | V_40 ;
break;
case V_41 :
V_2 |= V_42 ;
break;
default:
break;
}
F_2 ( V_2 , V_1 + V_17 ) ;
}
void F_10 ( void T_1 * V_1 , bool V_43 )
{
T_2 V_2 ;
V_2 = F_5 ( V_1 + V_17 ) ;
if ( V_43 )
V_2 |= V_44 ;
else
V_2 &= ~ V_21 ;
F_2 ( V_2 , V_1 + V_17 ) ;
}
void F_11 ( void T_1 * V_1 , unsigned int V_45 )
{
T_2 V_2 , V_46 ;
if ( V_45 == V_47 )
V_46 = V_48 ;
else
V_46 = V_49 ;
V_2 = F_5 ( V_1 + V_50 ) ;
V_2 &= ~ V_51 ;
V_2 |= V_46 ;
F_2 ( V_2 , V_1 + V_50 ) ;
}
void F_12 ( void T_1 * V_1 , unsigned int V_45 )
{
T_2 V_2 , V_46 = 0 ;
switch ( V_45 ) {
case V_52 :
V_46 = V_53 ;
break;
case V_54 :
V_46 = V_55 ;
break;
case V_56 :
V_46 = V_57 ;
break;
}
V_2 = F_5 ( V_1 + V_50 ) ;
V_2 &= ~ V_58 ;
V_2 |= V_46 ;
F_2 ( V_2 , V_1 + V_50 ) ;
}
unsigned int F_13 ( void T_1 * V_1 )
{
return F_5 ( V_1 + V_50 ) &
V_58 ;
}
void F_14 ( void T_1 * V_1 , unsigned int V_59 )
{
T_2 V_2 ;
V_2 = V_59 & V_60 ;
F_2 ( V_2 , V_1 + V_5 ) ;
}
void F_15 ( void T_1 * V_1 , unsigned int V_61 , unsigned int V_62 )
{
unsigned long V_2 ;
V_2 = F_5 ( V_1 + V_63 ) ;
V_2 &= ~ F_16 ( V_61 ) ;
V_2 |= ( V_62 << F_17 ( V_61 ) ) &
F_16 ( V_61 ) ;
F_2 ( V_2 , V_1 + V_63 ) ;
}
void F_18 ( void T_1 * V_1 , unsigned int V_61 )
{
unsigned long V_2 ;
V_2 = F_5 ( V_1 + V_63 ) ;
V_2 &= ~ F_19 ( V_61 ) ;
V_2 |= ( 0 << F_20 ( V_61 ) ) &
F_19 ( V_61 ) ;
F_2 ( V_2 , V_1 + V_63 ) ;
}
void F_21 ( void T_1 * V_1 , unsigned int V_61 )
{
unsigned long V_2 ;
V_2 = F_5 ( V_1 + V_63 ) ;
V_2 &= ~ F_22 ( V_61 ) ;
V_2 |= ( 0 << F_23 ( V_61 ) ) &
F_22 ( V_61 ) ;
F_2 ( V_2 , V_1 + V_63 ) ;
}
void F_24 ( void T_1 * V_1 , unsigned int V_64 )
{
T_2 V_2 ;
V_2 = V_64 & V_65 ;
F_2 ( V_2 , V_1 + V_66 ) ;
}
void F_25 ( void T_1 * V_1 , unsigned int V_67 )
{
T_2 V_2 ;
V_2 = V_67 & V_68 ;
F_2 ( V_2 , V_1 + V_69 ) ;
}
void F_26 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = F_5 ( V_1 + V_70 ) ;
V_2 |= ( V_71 |
V_72 |
V_73 |
V_74 |
V_75 |
V_76 |
V_77 ) ;
F_2 ( V_2 , V_1 + V_70 ) ;
}
void F_27 ( void T_1 * V_1 , unsigned int V_78 )
{
T_2 V_2 ;
V_2 = V_78 & V_79 ;
F_2 ( V_2 , V_1 + V_80 ) ;
}
void F_28 ( void T_1 * V_1 , unsigned int V_20 )
{
T_2 V_2 ;
switch ( V_20 ) {
case V_22 :
V_2 = V_81 ;
break;
case V_24 :
V_2 = V_81 | V_82 ;
break;
case V_26 :
V_2 = V_83 ;
break;
case V_28 :
V_2 = V_83 | V_82 ;
break;
case V_29 :
V_2 = V_84 ;
break;
case V_31 :
V_2 = V_84 |
V_85 ;
break;
case V_33 :
V_2 = V_86 ;
break;
case V_35 :
V_2 = V_86 |
V_85 ;
break;
case V_36 :
V_2 = V_87 | V_88 ;
break;
case V_39 :
V_2 = V_87 | V_89 ;
break;
case V_41 :
V_2 = V_90 ;
break;
default:
V_2 = 0 ;
break;
}
F_2 ( V_2 , V_1 + V_91 ) ;
}
void F_29 ( void T_1 * V_1 , unsigned int V_92 )
{
F_2 ( V_92 , V_1 + V_93 ) ;
}
void F_30 ( void T_1 * V_1 , struct V_94 * V_95 )
{
F_2 ( V_95 -> V_64 , V_1 + V_96 ) ;
F_2 ( V_95 -> V_97 , V_1 + V_98 ) ;
F_2 ( V_95 -> V_99 , V_1 + V_100 ) ;
}
void F_31 ( void T_1 * V_1 , unsigned int V_101 ,
unsigned int V_102 )
{
T_2 V_103 = 0 , V_104 = 0 , V_105 = 0 ;
switch ( V_101 ) {
case V_22 :
V_103 = 4 * V_102 ;
break;
case V_26 :
case V_28 :
case V_29 :
case V_31 :
case V_33 :
case V_35 :
V_103 = 2 * V_102 ;
break;
case V_36 :
case V_39 :
V_103 = V_102 ;
V_105 = V_103 ;
break;
case V_41 :
V_103 = V_102 ;
V_105 = V_104 = V_103 / 2 ;
break;
default:
break;
}
F_2 ( V_103 , V_1 + V_106 ) ;
F_2 ( V_105 , V_1 + V_107 ) ;
F_2 ( V_104 , V_1 + V_108 ) ;
}
void F_32 ( void T_1 * V_1 , unsigned int V_109 ,
unsigned int V_110 )
{
T_2 V_2 ;
V_2 = ( V_110 << V_111 ) &
V_112 ;
V_2 |= ( V_109 << V_113 ) &
V_114 ;
F_2 ( V_2 , V_1 + V_115 ) ;
V_2 = ( V_110 << V_116 ) &
V_117 ;
V_2 |= ( V_109 << V_118 ) &
V_119 ;
F_2 ( V_2 , V_1 + V_120 ) ;
V_2 = ( V_110 << V_121 ) &
V_122 ;
V_2 |= ( V_109 << V_123 ) &
V_124 ;
F_2 ( V_2 , V_1 + V_125 ) ;
}
void F_33 ( void T_1 * V_16 , unsigned int V_45 )
{
if ( V_45 == V_47 ) {
F_2 ( V_126 ,
V_16 + F_34 ( 1 ) ) ;
F_2 ( V_127 ,
V_16 + F_34 ( 2 ) ) ;
F_2 ( V_128 ,
V_16 + F_34 ( 3 ) ) ;
} else {
F_2 ( V_129 ,
V_16 + F_34 ( 1 ) ) ;
F_2 ( V_130 ,
V_16 + F_34 ( 2 ) ) ;
F_2 ( V_131 ,
V_16 + F_34 ( 3 ) ) ;
}
}
void F_35 ( void T_1 * V_1 )
{
F_2 ( 1 , V_1 + V_132 ) ;
}
void F_36 ( void T_1 * V_1 )
{
F_2 ( 1 , V_1 + V_133 ) ;
}
unsigned int F_37 ( void T_1 * V_1 )
{
return F_5 ( V_1 + V_134 ) ;
}
void F_38 ( void T_1 * V_1 ,
unsigned int V_135 )
{
return F_2 ( V_135 , V_1 + V_134 ) ;
}
unsigned int F_39 ( void T_1 * V_1 )
{
return F_5 ( V_1 + V_136 ) & V_137 ;
}
unsigned int F_40 ( void T_1 * V_1 )
{
return F_5 ( V_1 + V_138 ) & V_139 ;
}
void F_41 ( void T_1 * V_1 ,
unsigned int V_78 )
{
F_2 ( V_78 & V_140 ,
V_1 + V_141 ) ;
}
void F_42 ( void T_1 * V_1 ,
unsigned int V_142 )
{
switch ( V_142 ) {
case 1 :
default:
V_142 = V_143 ;
break;
case 2 :
V_142 = V_144 ;
break;
case 4 :
V_142 = V_145 ;
break;
case 8 :
V_142 = V_146 ;
break;
}
F_2 ( V_142 & V_147 ,
V_1 + V_148 ) ;
}
void F_43 ( void T_1 * V_1 , unsigned int V_149 )
{
V_149 &= V_150 ;
F_2 ( V_151 | V_149 ,
V_1 + V_152 ) ;
}
unsigned int F_44 ( void T_1 * V_1 )
{
return F_5 ( V_1 + V_153 ) ;
}
void F_45 ( void T_1 * V_1 )
{
F_2 ( V_151 , V_1 + V_153 ) ;
}
