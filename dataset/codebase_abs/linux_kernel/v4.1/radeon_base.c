static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_2 -> V_5 )
return;
F_2 ( V_4 , V_2 -> V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
void T_1 * V_6 ;
T_2 V_7 ;
T_3 V_8 ;
T_4 V_9 ;
unsigned int V_10 ;
V_10 = F_4 ( V_11 ) ;
V_10 &= 0x00ffffffu ;
V_10 |= 0x04 << 24 ;
F_5 ( V_11 , V_10 ) ;
V_10 = F_4 ( V_11 ) ;
V_6 = F_6 ( V_4 , & V_9 ) ;
if ( ! V_6 ) {
F_7 ( V_12 L_1 ,
F_8 ( V_2 -> V_13 ) ) ;
return - V_14 ;
}
V_2 -> V_5 = V_6 ;
if ( F_9 ( 0 ) != 0xaa55 ) {
F_7 ( V_15 L_2
L_3 ,
F_8 ( V_2 -> V_13 ) , F_9 ( 0 ) ) ;
goto V_16;
}
V_7 = F_9 ( 0x18 ) ;
if ( F_10 ( V_7 ) != ( ( 'R' << 24 ) | ( 'I' << 16 ) | ( 'C' << 8 ) | 'P' ) ) {
F_7 ( V_17 L_4
L_5 , F_8 ( V_2 -> V_13 ) , F_10 ( V_7 ) ) ;
goto V_18;
}
V_8 = F_11 ( V_7 + 0x14 ) ;
switch( V_8 ) {
case 0 :
F_7 ( V_19 L_6 ) ;
break;
case 1 :
F_7 ( V_19 L_7 ) ;
goto V_16;
case 2 :
F_7 ( V_19 L_8 ) ;
goto V_16;
default:
F_7 ( V_19 L_9 , V_8 ) ;
goto V_16;
}
V_18:
V_2 -> V_20 = F_9 ( 0x48 ) ;
return 0 ;
V_16:
V_2 -> V_5 = NULL ;
F_1 ( V_2 , V_4 ) ;
return - V_21 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_5 V_22 ;
void T_1 * V_23 = NULL ;
for( V_22 = 0x000c0000 ; V_22 < 0x000f0000 ; V_22 += 0x00001000 ) {
V_23 = F_13 ( V_22 , 0x10000 ) ;
if ( V_23 == NULL )
return - V_14 ;
if ( F_14 ( V_23 ) == 0x55 && F_14 ( V_23 + 1 ) == 0xaa )
break;
F_15 ( V_23 ) ;
V_23 = NULL ;
}
if ( V_23 == NULL )
return - V_21 ;
V_2 -> V_5 = V_23 ;
V_2 -> V_20 = F_9 ( 0x48 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
const T_5 * V_27 ;
if ( V_25 == NULL )
return - V_28 ;
V_27 = F_17 ( V_25 , L_10 , NULL ) ;
if ( ! V_27 || ! * V_27 ) {
F_7 ( V_17 L_11 ) ;
return - V_29 ;
}
V_2 -> V_30 . V_31 = ( * V_27 ) / 10 ;
V_27 = F_17 ( V_25 , L_12 , NULL ) ;
if ( V_27 && * V_27 )
V_2 -> V_30 . V_32 = ( * V_27 ) / 10 ;
V_27 = F_17 ( V_25 , L_13 , NULL ) ;
if ( V_27 && * V_27 )
V_2 -> V_30 . V_33 = ( * V_27 ) / 10 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned char V_34 ;
unsigned V_35 , V_36 , V_37 ;
unsigned V_32 , V_33 , V_38 , V_39 ;
int V_40 , V_41 , V_42 , V_43 , V_44 , V_45 ;
unsigned long long V_46 , V_47 ;
long V_48 ;
struct V_49 V_50 , V_51 ;
long V_52 , V_53 ;
int V_54 ;
V_38 = F_19 ( V_55 ) ;
F_20 () ;
for( V_54 = 0 ; V_54 < 1000000 ; V_54 ++ )
if ( ( ( F_4 ( V_56 ) >> 16 ) & 0x3ff ) == 0 )
break;
F_21 ( & V_50 ) ;
for( V_54 = 0 ; V_54 < 1000000 ; V_54 ++ )
if ( ( ( F_4 ( V_56 ) >> 16 ) & 0x3ff ) != 0 )
break;
for( V_54 = 0 ; V_54 < 1000000 ; V_54 ++ )
if ( ( ( F_4 ( V_56 ) >> 16 ) & 0x3ff ) == 0 )
break;
F_21 ( & V_51 ) ;
F_22 () ;
V_52 = V_51 . V_57 - V_50 . V_57 ;
if ( V_52 > 10 )
return - 1 ;
V_53 = V_51 . V_58 - V_50 . V_58 ;
V_53 += V_52 * 1000000 ;
if ( V_53 < 0 )
V_53 = - V_53 ;
V_46 = 1000000 / V_53 ;
V_40 = ( ( F_4 ( V_59 ) & 0x1ff ) + 1 ) * 8 ;
V_41 = ( ( F_4 ( V_60 ) & 0x3ff ) + 1 ) ;
V_47 = ( long long ) V_40 * ( long long ) V_41 * V_46 ;
switch( ( F_23 ( V_61 ) & 0x30000 ) >> 16 ) {
case 0 :
default:
V_42 = 1 ;
V_43 = 1 ;
break;
case 1 :
V_45 = ( ( F_23 ( V_62 ) >> 16 ) & 0xff ) ;
V_44 = ( F_23 ( V_62 ) & 0xff ) ;
V_42 = 2 * V_45 ;
V_43 = 2 * V_44 ;
break;
case 2 :
V_45 = ( ( F_23 ( V_62 ) >> 8 ) & 0xff ) ;
V_44 = ( F_23 ( V_62 ) & 0xff ) ;
V_42 = 2 * V_45 ;
V_43 = 2 * V_44 ;
break;
}
V_34 = F_24 ( V_63 + 1 ) & 0x3 ;
F_25 ( V_2 ) ;
V_45 = ( F_23 ( V_64 + V_34 ) & 0x7ff ) ;
V_44 = ( F_23 ( V_61 ) & 0x3ff ) ;
V_42 *= V_45 ;
V_43 *= V_44 ;
switch ( ( F_23 ( V_64 + V_34 ) >> 16 ) & 0x7 ) {
case 1 :
V_43 *= 2 ;
break;
case 2 :
V_43 *= 4 ;
break;
case 3 :
V_43 *= 8 ;
break;
case 4 :
V_43 *= 3 ;
break;
case 6 :
V_43 *= 6 ;
break;
case 7 :
V_43 *= 12 ;
break;
}
V_47 *= V_43 ;
F_26 ( V_47 , 1000 * V_42 ) ;
V_48 = V_47 ;
if ( ( V_48 > 26900 ) && ( V_48 < 27100 ) )
V_48 = 2700 ;
else if ( ( V_48 > 14200 ) && ( V_48 < 14400 ) )
V_48 = 1432 ;
else if ( ( V_48 > 29400 ) && ( V_48 < 29600 ) )
V_48 = 2950 ;
else {
F_7 ( V_17 L_14 , V_48 ) ;
return - 1 ;
}
V_38 = F_23 ( V_62 ) ;
V_39 = F_23 ( V_61 ) & 0x3ff ;
V_35 = ( V_38 & 0xff0000 ) >> 16 ;
V_36 = ( V_38 & 0xff00 ) >> 8 ;
V_37 = ( V_38 & 0xff ) ;
V_32 = F_27 ( ( 2 * V_35 * V_48 ) , ( 2 * V_37 ) ) ;
V_33 = F_27 ( ( 2 * V_36 * V_48 ) , ( 2 * V_37 ) ) ;
V_2 -> V_30 . V_31 = V_48 ;
V_2 -> V_30 . V_39 = V_39 ;
V_2 -> V_30 . V_32 = V_32 ;
V_2 -> V_30 . V_33 = V_33 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_65 ) {
case V_66 :
case V_67 :
V_2 -> V_30 . V_68 = 35000 ;
V_2 -> V_30 . V_69 = 12000 ;
V_2 -> V_30 . V_33 = 23000 ;
V_2 -> V_30 . V_32 = 23000 ;
V_2 -> V_30 . V_31 = 2700 ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_2 -> V_30 . V_68 = 35000 ;
V_2 -> V_30 . V_69 = 12000 ;
V_2 -> V_30 . V_33 = 27500 ;
V_2 -> V_30 . V_32 = 27500 ;
V_2 -> V_30 . V_31 = 2700 ;
break;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
V_2 -> V_30 . V_68 = 35000 ;
V_2 -> V_30 . V_69 = 12000 ;
V_2 -> V_30 . V_33 = 25000 ;
V_2 -> V_30 . V_32 = 25000 ;
V_2 -> V_30 . V_31 = 2700 ;
break;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
V_2 -> V_30 . V_68 = 40000 ;
V_2 -> V_30 . V_69 = 20000 ;
V_2 -> V_30 . V_33 = 27000 ;
V_2 -> V_30 . V_32 = 27000 ;
V_2 -> V_30 . V_31 = 2700 ;
break;
case V_83 :
case V_84 :
case V_85 :
case V_86 :
default:
V_2 -> V_30 . V_68 = 35000 ;
V_2 -> V_30 . V_69 = 12000 ;
V_2 -> V_30 . V_33 = 16600 ;
V_2 -> V_30 . V_32 = 16600 ;
V_2 -> V_30 . V_31 = 2700 ;
break;
}
V_2 -> V_30 . V_39 = F_23 ( V_61 ) & V_87 ;
#if F_29 ( V_88 ) || F_29 ( V_89 )
if ( ! V_90 && F_16 ( V_2 ) == 0 ) {
F_7 ( V_19 L_15 ) ;
goto V_91;
}
#endif
if ( ! V_90 && V_2 -> V_5 ) {
T_2 V_92 = F_9 ( V_2 -> V_20 + 0x30 ) ;
V_2 -> V_30 . V_32 = F_9 ( V_92 + 0x08 ) ;
V_2 -> V_30 . V_33 = F_9 ( V_92 + 0x0a ) ;
V_2 -> V_30 . V_31 = F_9 ( V_92 + 0x0e ) ;
V_2 -> V_30 . V_39 = F_9 ( V_92 + 0x10 ) ;
V_2 -> V_30 . V_69 = F_10 ( V_92 + 0x12 ) ;
V_2 -> V_30 . V_68 = F_10 ( V_92 + 0x16 ) ;
F_7 ( V_19 L_16 ) ;
goto V_91;
}
if ( F_18 ( V_2 ) == 0 ) {
F_7 ( V_19 L_17 ) ;
goto V_91;
}
F_7 ( V_19 L_18 ) ;
V_91:
if ( V_2 -> V_30 . V_33 == 0 )
V_2 -> V_30 . V_33 = 20000 ;
if ( V_2 -> V_30 . V_32 == 0 )
V_2 -> V_30 . V_32 = 20000 ;
F_7 ( L_19 ,
V_2 -> V_30 . V_31 / 100 , V_2 -> V_30 . V_31 % 100 ,
V_2 -> V_30 . V_39 ,
V_2 -> V_30 . V_33 / 100 , V_2 -> V_30 . V_33 % 100 ,
V_2 -> V_30 . V_32 / 100 , V_2 -> V_30 . V_32 % 100 ) ;
F_7 ( L_20 , V_2 -> V_30 . V_69 , V_2 -> V_30 . V_68 ) ;
}
static int F_30 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_97 ;
struct V_93 V_98 ;
int V_99 , V_100 ;
unsigned int V_101 ;
if ( F_31 ( V_2 , & V_98 , V_94 ) )
return - V_29 ;
switch ( V_98 . V_102 ) {
case 0 ... 8 :
V_98 . V_102 = 8 ;
break;
case 9 ... 16 :
V_98 . V_102 = 16 ;
break;
case 17 ... 24 :
#if 0
v.bits_per_pixel = 24;
break;
#endif
return - V_29 ;
case 25 ... 32 :
V_98 . V_102 = 32 ;
break;
default:
return - V_29 ;
}
switch ( F_32 ( & V_98 ) ) {
case 8 :
V_99 = V_100 = 1 ;
V_98 . V_103 . V_104 = V_98 . V_105 . V_104 = V_98 . V_106 . V_104 = 0 ;
V_98 . V_103 . V_107 = V_98 . V_105 . V_107 = V_98 . V_106 . V_107 = 8 ;
V_98 . V_108 . V_104 = V_98 . V_108 . V_107 = 0 ;
break;
case 15 :
V_99 = 2 ;
V_100 = 1 ;
V_98 . V_103 . V_104 = 10 ;
V_98 . V_105 . V_104 = 5 ;
V_98 . V_106 . V_104 = 0 ;
V_98 . V_103 . V_107 = V_98 . V_105 . V_107 = V_98 . V_106 . V_107 = 5 ;
V_98 . V_108 . V_104 = V_98 . V_108 . V_107 = 0 ;
break;
case 16 :
V_99 = 2 ;
V_100 = 1 ;
V_98 . V_103 . V_104 = 11 ;
V_98 . V_105 . V_104 = 5 ;
V_98 . V_106 . V_104 = 0 ;
V_98 . V_103 . V_107 = 5 ;
V_98 . V_105 . V_107 = 6 ;
V_98 . V_106 . V_107 = 5 ;
V_98 . V_108 . V_104 = V_98 . V_108 . V_107 = 0 ;
break;
case 24 :
V_99 = 4 ;
V_100 = 1 ;
V_98 . V_103 . V_104 = 16 ;
V_98 . V_105 . V_104 = 8 ;
V_98 . V_106 . V_104 = 0 ;
V_98 . V_103 . V_107 = V_98 . V_106 . V_107 = V_98 . V_105 . V_107 = 8 ;
V_98 . V_108 . V_104 = V_98 . V_108 . V_107 = 0 ;
break;
case 32 :
V_99 = 4 ;
V_100 = 1 ;
V_98 . V_103 . V_104 = 16 ;
V_98 . V_105 . V_104 = 8 ;
V_98 . V_106 . V_104 = 0 ;
V_98 . V_103 . V_107 = V_98 . V_106 . V_107 = V_98 . V_105 . V_107 = 8 ;
V_98 . V_108 . V_104 = 24 ;
V_98 . V_108 . V_107 = 8 ;
break;
default:
F_7 ( L_21 ,
V_94 -> V_109 , V_94 -> V_110 , V_94 -> V_102 ) ;
return - V_29 ;
}
if ( V_98 . V_111 < V_98 . V_110 )
V_98 . V_111 = V_98 . V_110 ;
if ( V_98 . V_112 < V_98 . V_109 )
V_98 . V_112 = V_98 . V_109 ;
if ( V_2 -> V_96 -> V_113 & V_114 ) {
V_98 . V_112 = V_98 . V_112 & ~ 7ul ;
} else {
V_101 = ( ( V_98 . V_112 * ( ( V_98 . V_102 + 1 ) / 8 ) + 0x3f )
& ~ ( 0x3f ) ) >> 6 ;
V_98 . V_112 = ( V_101 << 6 ) / ( ( V_98 . V_102 + 1 ) / 8 ) ;
}
if ( ( ( V_98 . V_112 * V_98 . V_111 * V_99 ) / V_100 ) > V_2 -> V_115 )
return - V_29 ;
if ( V_98 . V_112 < V_98 . V_109 )
V_98 . V_109 = V_98 . V_112 ;
if ( V_98 . V_116 > V_98 . V_112 - V_98 . V_109 )
V_98 . V_116 = V_98 . V_112 - V_98 . V_109 - 1 ;
if ( V_98 . V_117 > V_98 . V_111 - V_98 . V_110 )
V_98 . V_117 = V_98 . V_111 - V_98 . V_110 - 1 ;
V_98 . V_103 . V_118 = V_98 . V_105 . V_118 = V_98 . V_106 . V_118 =
V_98 . V_108 . V_104 = V_98 . V_108 . V_107 =
V_98 . V_108 . V_118 = 0 ;
memcpy ( V_94 , & V_98 , sizeof( V_98 ) ) ;
return 0 ;
}
static int F_33 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_97 ;
if ( ( V_94 -> V_116 + V_96 -> V_94 . V_109 > V_96 -> V_94 . V_112 )
|| ( V_94 -> V_117 + V_96 -> V_94 . V_110 > V_96 -> V_94 . V_111 ) )
return - V_29 ;
if ( V_2 -> V_119 )
return 0 ;
F_34 ( 2 ) ;
F_5 ( V_120 , ( V_94 -> V_117 * V_96 -> V_121 . V_122 +
V_94 -> V_116 * V_96 -> V_94 . V_102 / 8 ) & ~ 7 ) ;
return 0 ;
}
static int F_35 ( struct V_95 * V_96 , unsigned int V_123 ,
unsigned long V_124 )
{
struct V_1 * V_2 = V_96 -> V_97 ;
unsigned int V_38 ;
T_5 V_125 = 0 ;
int V_126 ;
switch ( V_123 ) {
case V_127 :
if ( ! V_2 -> V_128 )
return - V_29 ;
V_126 = F_36 ( V_125 , ( V_129 V_130 * ) V_124 ) ;
if ( V_126 )
return V_126 ;
F_34 ( 2 ) ;
if ( V_125 & 0x01 ) {
V_38 = F_4 ( V_131 ) ;
V_38 |= ( V_132 | V_133 ) ;
} else {
V_38 = F_4 ( V_131 ) ;
V_38 &= ~ ( V_132 | V_133 ) ;
}
F_5 ( V_131 , V_38 ) ;
if ( V_125 & 0x02 ) {
V_38 = F_4 ( V_134 ) ;
V_38 |= V_135 ;
V_136 = 1 ;
} else {
V_38 = F_4 ( V_134 ) ;
V_38 &= ~ V_135 ;
V_136 = 0 ;
}
F_5 ( V_134 , V_38 ) ;
return 0 ;
case V_137 :
if ( ! V_2 -> V_128 )
return - V_29 ;
V_38 = F_4 ( V_131 ) ;
if ( ( V_132 | V_133 ) & V_38 )
V_125 |= 0x01 ;
V_38 = F_4 ( V_134 ) ;
if ( V_135 & V_38 )
V_125 |= 0x02 ;
return F_37 ( V_125 , ( V_129 V_130 * ) V_124 ) ;
default:
return - V_29 ;
}
return - V_29 ;
}
int F_38 ( struct V_1 * V_2 , int V_138 , int V_139 )
{
T_5 V_27 ;
T_5 V_140 ;
int V_141 = 0 ;
if ( V_2 -> V_142 )
return 0 ;
F_39 () ;
V_27 = F_4 ( V_134 ) ;
V_27 &= ~ ( V_143 | V_144 |
V_145 ) ;
switch ( V_138 ) {
case V_146 :
V_27 |= ( V_143 | V_145 ) ;
break;
case V_147 :
V_27 |= ( V_143 | V_144 ) ;
break;
case V_148 :
V_27 |= ( V_143 | V_145 |
V_144 ) ;
break;
case V_149 :
V_27 |= V_143 ;
break;
case V_150 :
default:
V_141 = 1 ;
}
F_5 ( V_134 , V_27 ) ;
switch ( V_2 -> V_151 ) {
case V_152 :
if ( V_141 )
F_40 ( V_153 , ( V_154 | V_155 ) ,
~ ( V_154 | V_155 ) ) ;
else {
if ( V_139 || V_138 == V_149 )
break;
F_40 ( V_153 , 0 , ~ ( V_154 | V_155 ) ) ;
}
break;
case V_156 :
F_41 ( & V_2 -> V_157 ) ;
V_27 = F_4 ( V_131 ) ;
if ( V_141 ) {
T_5 V_158 = ( V_27 & ~ V_159 ) | V_133 | V_132
| V_160 | ( V_2 -> V_161 . V_162
& ( V_163 | V_164 ) ) ;
if ( ( V_27 ^ V_158 ) == V_159 )
F_5 ( V_131 , V_158 ) ;
else if ( ( V_27 ^ V_158 ) != 0 ) {
F_5 ( V_131 , V_158
& ~ ( V_132 | V_164 ) ) ;
V_2 -> V_161 . V_162 &= ~ V_165 ;
V_2 -> V_161 . V_162 |=
V_158 & V_165 ;
if ( V_139 ) {
F_42 ( V_2 -> V_166 . V_167 ) ;
F_5 ( V_131 , V_158 ) ;
}
else {
V_2 -> V_168 = V_158 ;
F_43 ( & V_2 -> V_157 ,
V_169 +
F_44 ( V_2 -> V_166 . V_167 ) ) ;
}
}
} else {
V_27 |= V_159 ;
F_5 ( V_131 , V_27 ) ;
if ( V_139 || V_138 == V_149 )
break;
V_140 = F_23 ( V_170 ) ;
if ( V_2 -> V_128 || V_2 -> V_171 )
F_45 ( V_170 , 0 , ~ V_172 ) ;
V_27 &= ~ ( V_164 ) ;
F_5 ( V_131 , V_27 ) ;
F_46 ( 100 ) ;
V_27 &= ~ ( V_132 | V_160 ) ;
F_5 ( V_131 , V_27 ) ;
V_27 &= ~ V_163 ;
V_2 -> V_168 = V_27 ;
F_43 ( & V_2 -> V_157 ,
V_169 +
F_44 ( V_2 -> V_166 . V_167 ) ) ;
V_2 -> V_161 . V_162 &= ~ V_165 ;
V_2 -> V_161 . V_162 |= V_27 & V_165 ;
if ( V_2 -> V_128 || V_2 -> V_171 )
F_47 ( V_170 , V_140 ) ;
}
break;
case V_173 :
default:
break;
}
return 0 ;
}
static int F_48 ( int V_138 , struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_97 ;
if ( V_2 -> V_119 )
return 0 ;
return F_38 ( V_2 , V_138 , 0 ) ;
}
static int F_49 ( unsigned V_174 , unsigned V_103 , unsigned V_105 ,
unsigned V_106 , unsigned V_108 ,
struct V_1 * V_2 )
{
T_5 V_175 ;
unsigned int V_54 ;
if ( V_174 > 255 )
return - V_29 ;
V_103 >>= 8 ;
V_105 >>= 8 ;
V_106 >>= 8 ;
V_2 -> V_176 [ V_174 ] . V_103 = V_103 ;
V_2 -> V_176 [ V_174 ] . V_105 = V_105 ;
V_2 -> V_176 [ V_174 ] . V_106 = V_106 ;
V_175 = V_174 ;
if ( ! V_2 -> V_119 ) {
F_34 ( 9 ) ;
if ( V_2 -> V_177 == 16 ) {
V_175 = V_174 * 8 ;
if ( V_2 -> V_178 == 16 && V_174 > 63 )
return - V_29 ;
if ( V_2 -> V_178 == 15 && V_174 > 31 )
return - V_29 ;
if ( V_2 -> V_178 == 16 ) {
F_5 ( V_179 , V_175 >> 1 ) ;
F_5 ( V_180 ,
( V_2 -> V_176 [ V_174 >> 1 ] . V_103 << 16 ) |
( V_105 << 8 ) |
( V_2 -> V_176 [ V_174 >> 1 ] . V_106 ) ) ;
V_105 = V_2 -> V_176 [ V_174 << 1 ] . V_105 ;
}
}
if ( V_2 -> V_178 != 16 || V_174 < 32 ) {
F_5 ( V_179 , V_175 ) ;
F_5 ( V_180 , ( V_103 << 16 ) |
( V_105 << 8 ) | V_106 ) ;
}
}
if ( V_174 < 16 ) {
T_5 * V_181 = V_2 -> V_96 -> V_182 ;
switch ( V_2 -> V_178 ) {
case 15 :
V_181 [ V_174 ] = ( V_174 << 10 ) | ( V_174 << 5 ) | V_174 ;
break;
case 16 :
V_181 [ V_174 ] = ( V_174 << 11 ) | ( V_174 << 5 ) | V_174 ;
break;
case 24 :
V_181 [ V_174 ] = ( V_174 << 16 ) | ( V_174 << 8 ) | V_174 ;
break;
case 32 :
V_54 = ( V_174 << 8 ) | V_174 ;
V_181 [ V_174 ] = ( V_54 << 16 ) | V_54 ;
break;
}
}
return 0 ;
}
static int F_50 ( unsigned V_174 , unsigned V_103 , unsigned V_105 ,
unsigned V_106 , unsigned V_108 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_97 ;
T_5 V_183 , V_184 = 0 ;
int V_126 ;
if ( ! V_2 -> V_119 ) {
if ( V_2 -> V_128 ) {
V_184 = F_23 ( V_185 ) ;
F_47 ( V_185 ,
V_184 & ~ V_186 ) ;
}
if ( V_2 -> V_187 ) {
V_183 = F_4 ( V_188 ) ;
V_183 &= ~ V_189 ;
F_5 ( V_188 , V_183 ) ;
}
}
V_126 = F_49 ( V_174 , V_103 , V_105 , V_106 , V_108 , V_2 ) ;
if ( ! V_2 -> V_119 && V_2 -> V_128 )
F_47 ( V_185 , V_184 ) ;
return V_126 ;
}
static int F_51 ( struct V_190 * V_191 , struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_97 ;
T_2 * V_103 , * V_105 , * V_106 , * V_108 ;
T_5 V_183 , V_184 = 0 ;
int V_54 , V_192 , V_126 = 0 ;
if ( ! V_2 -> V_119 ) {
if ( V_2 -> V_128 ) {
V_184 = F_23 ( V_185 ) ;
F_47 ( V_185 ,
V_184 & ~ V_186 ) ;
}
if ( V_2 -> V_187 ) {
V_183 = F_4 ( V_188 ) ;
V_183 &= ~ V_189 ;
F_5 ( V_188 , V_183 ) ;
}
}
V_103 = V_191 -> V_103 ;
V_105 = V_191 -> V_105 ;
V_106 = V_191 -> V_106 ;
V_108 = V_191 -> V_108 ;
V_192 = V_191 -> V_192 ;
for ( V_54 = 0 ; V_54 < V_191 -> V_193 ; V_54 ++ ) {
T_6 V_194 , V_195 , V_196 , V_197 = 0xffff ;
V_194 = * V_103 ++ ;
V_195 = * V_105 ++ ;
V_196 = * V_106 ++ ;
if ( V_108 )
V_197 = * V_108 ++ ;
V_126 = F_49 ( V_192 ++ , V_194 , V_195 , V_196 , V_197 ,
V_2 ) ;
if ( V_126 )
break;
}
if ( ! V_2 -> V_119 && V_2 -> V_128 )
F_47 ( V_185 , V_184 ) ;
return V_126 ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_198 * V_199 )
{
V_199 -> V_200 = F_4 ( V_201 ) ;
V_199 -> V_202 = F_4 ( V_134 ) ;
V_199 -> V_203 = F_4 ( V_204 ) ;
V_199 -> V_205 = F_4 ( V_206 ) ;
V_199 -> V_207 = F_4 ( V_59 ) ;
V_199 -> V_208 = F_4 ( V_209 ) ;
V_199 -> V_210 = F_4 ( V_60 ) ;
V_199 -> V_211 = F_4 ( V_212 ) ;
V_199 -> V_213 = F_4 ( V_214 ) ;
V_199 -> V_215 = F_4 ( V_216 ) ;
V_199 -> V_217 = F_4 ( V_218 ) ;
V_199 -> V_219 = F_4 ( V_220 ) ;
V_199 -> V_221 = F_4 ( V_153 ) ;
V_199 -> V_222 = F_4 ( V_223 ) ;
V_199 -> V_224 = F_4 ( V_225 ) ;
V_199 -> V_226 = F_4 ( V_227 ) ;
V_199 -> V_228 = F_4 ( V_229 ) ;
V_199 -> V_162 = F_4 ( V_131 ) ;
V_199 -> V_230 = F_4 ( V_231 ) ;
V_199 -> V_232 = F_4 ( V_233 ) ;
V_199 -> V_234 = F_4 ( V_235 ) ;
V_199 -> V_236 = F_23 ( V_185 ) ;
V_199 -> V_237 = F_4 ( V_63 ) & ~ 0x3f ;
F_25 ( V_2 ) ;
V_199 -> V_238 = F_23 ( V_239 ) ;
V_199 -> V_240 = F_23 ( V_61 ) ;
}
static void F_53 ( struct V_1 * V_2 , struct V_198 * V_241 )
{
int V_54 ;
F_34 ( 20 ) ;
if ( V_2 -> V_128 ) {
if ( ( V_241 -> V_240 == ( F_23 ( V_61 ) & V_87 ) ) &&
( V_241 -> V_238 == ( F_23 ( V_239 ) &
( V_242 | V_243 ) ) ) ) {
F_40 ( V_63 ,
V_241 -> V_237 & V_244 ,
~ V_244 ) ;
F_25 ( V_2 ) ;
F_54 ( V_2 ) ;
return;
}
}
F_45 ( V_185 , V_245 , ~ V_246 ) ;
F_45 ( V_247 ,
V_248 | V_249 | V_250 ,
~ ( V_248 | V_249 | V_250 ) ) ;
F_40 ( V_63 ,
V_241 -> V_237 & V_244 ,
~ V_244 ) ;
F_25 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( F_55 ( V_2 ) ||
V_2 -> V_251 == V_252 ||
V_2 -> V_251 == V_253 ||
V_2 -> V_251 == V_254 ) {
if ( V_241 -> V_240 & V_255 ) {
F_45 ( V_61 , V_241 -> V_240 , 0 ) ;
} else {
F_45 ( V_61 ,
( V_241 -> V_240 << V_256 ) ,
~ V_255 ) ;
}
} else
F_45 ( V_61 , V_241 -> V_240 , ~ V_87 ) ;
F_45 ( V_239 , V_241 -> V_238 , ~ V_243 ) ;
F_45 ( V_239 , V_241 -> V_238 , ~ V_242 ) ;
while ( F_23 ( V_61 ) & V_257 )
;
F_45 ( V_61 , V_258 , ~ V_258 ) ;
for ( V_54 = 0 ; ( V_54 < 10000 && F_23 ( V_61 ) & V_257 ) ; V_54 ++ )
;
F_47 ( V_259 , 0 ) ;
F_45 ( V_247 , 0 ,
~ ( V_248 | V_260 | V_249 | V_250 ) ) ;
F_42 ( 5 ) ;
F_45 ( V_185 , V_261 , ~ V_246 ) ;
}
static void F_56 ( unsigned long V_262 )
{
struct V_1 * V_2 = (struct V_1 * ) V_262 ;
F_39 () ;
F_5 ( V_131 , V_2 -> V_168 ) ;
}
void F_57 ( struct V_1 * V_2 , struct V_198 * V_241 ,
int V_263 )
{
int V_54 ;
int V_264 = F_58 ( V_2 ) ;
if ( V_265 )
return;
if ( ! V_263 )
F_38 ( V_2 , V_149 , 0 ) ;
F_34 ( 31 ) ;
for ( V_54 = 0 ; V_54 < 10 ; V_54 ++ )
F_5 ( V_266 [ V_54 ] . V_267 , V_266 [ V_54 ] . V_27 ) ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
F_5 ( V_268 + 0x10 * V_54 , V_241 -> V_269 [ V_54 ] ) ;
F_5 ( V_270 + 0x10 * V_54 , V_241 -> V_271 [ V_54 ] ) ;
F_5 ( V_272 + 0x10 * V_54 , V_241 -> V_273 [ V_54 ] ) ;
}
F_5 ( V_201 , V_241 -> V_200 ) ;
F_40 ( V_134 , V_241 -> V_202 ,
~ ( V_144 | V_145 | V_143 ) ) ;
F_5 ( V_204 , V_241 -> V_203 ) ;
F_40 ( V_206 , V_241 -> V_205 , V_274 | V_275 ) ;
F_5 ( V_59 , V_241 -> V_207 ) ;
F_5 ( V_209 , V_241 -> V_208 ) ;
F_5 ( V_60 , V_241 -> V_210 ) ;
F_5 ( V_212 , V_241 -> V_211 ) ;
F_5 ( V_120 , 0 ) ;
F_5 ( V_276 , 0 ) ;
F_5 ( V_214 , V_241 -> V_213 ) ;
F_5 ( V_216 , V_241 -> V_215 ) ;
F_53 ( V_2 , V_241 ) ;
if ( ( V_264 == V_152 ) || ( V_264 == V_156 ) ) {
F_34 ( 10 ) ;
F_5 ( V_218 , V_241 -> V_217 ) ;
F_5 ( V_220 , V_241 -> V_219 ) ;
F_5 ( V_223 , V_241 -> V_222 ) ;
F_5 ( V_227 , V_241 -> V_226 ) ;
F_5 ( V_225 , V_241 -> V_224 ) ;
F_5 ( V_229 , V_241 -> V_228 ) ;
F_5 ( V_153 , V_241 -> V_221 ) ;
F_5 ( V_233 , V_241 -> V_232 ) ;
F_5 ( V_235 , V_241 -> V_234 ) ;
}
if ( ! V_263 )
F_38 ( V_2 , V_150 , 0 ) ;
F_34 ( 2 ) ;
F_47 ( V_185 , V_241 -> V_236 ) ;
return;
}
static void F_59 ( struct V_1 * V_2 , struct V_198 * V_277 ,
unsigned long V_278 )
{
const struct {
int V_279 ;
int V_280 ;
} * V_281 ,
V_282 [] = {
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 4 , 2 } ,
{ 8 , 3 } ,
{ 3 , 4 } ,
{ 16 , 5 } ,
{ 6 , 6 } ,
{ 12 , 7 } ,
{ 0 , 0 } ,
} ;
int V_283 , V_284 = 0 ;
int V_285 = 0 ;
#if 1
while ( V_2 -> V_187 ) {
T_5 V_286 = F_4 ( V_287 ) ;
T_5 V_288 ;
int V_289 ;
if ( ( V_286 & V_290 ) == 0 )
break;
if ( V_2 -> V_251 == V_291 || F_55 ( V_2 ) ) {
V_289 = ( V_286 >> 10 ) & 0x3 ;
if ( V_289 == 3 ) {
V_288 = F_4 ( V_292 ) ;
V_289 = ( V_288 >> 12 ) & 0x3 ;
}
} else
V_289 = ( V_286 >> 13 ) & 0x1 ;
if ( V_289 == 1 )
break;
V_285 = 1 ;
break;
}
#else
V_285 = 1 ;
#endif
if ( V_278 > V_2 -> V_30 . V_68 )
V_278 = V_2 -> V_30 . V_68 ;
if ( V_278 * 12 < V_2 -> V_30 . V_69 )
V_278 = V_2 -> V_30 . V_69 / 12 ;
F_60 ( L_22 ,
V_278 , V_2 -> V_30 . V_69 , V_2 -> V_30 . V_68 ) ;
for ( V_281 = & V_282 [ 0 ] ; V_281 -> V_279 ; ++ V_281 ) {
V_284 = V_281 -> V_279 * V_278 ;
if ( V_285 && ( V_281 -> V_279 & 1 ) )
continue;
if ( V_284 >= V_2 -> V_30 . V_69 &&
V_284 <= V_2 -> V_30 . V_68 )
break;
}
if ( ! V_281 -> V_279 ) {
V_281 = & V_282 [ V_281 -> V_280 ] ;
V_284 = V_281 -> V_279 * V_278 ;
}
F_60 ( L_23 ,
V_2 -> V_30 . V_39 , V_2 -> V_30 . V_31 ,
V_284 ) ;
if ( ! V_281 -> V_279 ) {
V_281 = & V_282 [ V_281 -> V_280 ] ;
V_284 = V_281 -> V_279 * V_278 ;
}
F_60 ( L_23 ,
V_2 -> V_30 . V_39 , V_2 -> V_30 . V_31 ,
V_284 ) ;
V_283 = F_27 ( V_2 -> V_30 . V_39 * V_284 ,
V_2 -> V_30 . V_31 ) ;
V_277 -> V_240 = V_2 -> V_30 . V_39 ;
V_277 -> V_238 = V_283 | ( V_281 -> V_280 << 16 ) ;
F_60 ( L_24 , V_281 -> V_280 ) ;
F_60 ( L_25 , V_283 ) ;
F_60 ( L_26 , V_277 -> V_238 ) ;
}
static int F_61 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_97 ;
struct V_93 * V_241 = & V_96 -> V_94 ;
struct V_198 * V_293 ;
int V_40 , V_41 , V_294 , V_295 ,
V_296 , V_297 , V_298 , V_299 , V_300 ;
T_3 V_301 [] = { 0 , 0x12 , 9 , 9 , 6 , 5 } ;
T_3 V_302 [] = { 2 , 2 , 0 , 0 , 5 , 5 } ;
T_5 V_303 , V_304 , V_305 , V_306 , V_307 ;
int V_54 , V_278 ;
int V_308 = 0 ;
int V_309 = 0 ;
int V_310 , V_311 , V_312 , V_313 , V_314 ;
int V_264 = F_58 ( V_2 ) ;
int V_178 = F_32 ( V_241 ) ;
int V_315 = 0 ;
V_293 = F_62 ( sizeof( struct V_198 ) , V_316 ) ;
if ( ! V_293 )
return - V_14 ;
F_39 () ;
V_294 = V_241 -> V_109 + V_241 -> V_317 ;
V_295 = V_294 + V_241 -> V_318 ;
V_40 = V_295 + V_241 -> V_319 ;
V_297 = V_241 -> V_110 + V_241 -> V_320 ;
V_298 = V_297 + V_241 -> V_321 ;
V_41 = V_298 + V_241 -> V_322 ;
V_307 = V_241 -> V_323 ;
V_303 = V_241 -> V_303 ;
V_304 = V_303 & V_324 ? 0 : 1 ;
V_305 = V_303 & V_325 ? 0 : 1 ;
if ( V_264 == V_152 || V_264 == V_156 ) {
if ( V_2 -> V_166 . V_109 < V_241 -> V_109 )
V_241 -> V_109 = V_2 -> V_166 . V_109 ;
if ( V_2 -> V_166 . V_110 < V_241 -> V_110 )
V_241 -> V_110 = V_2 -> V_166 . V_110 ;
V_40 = V_241 -> V_109 + V_2 -> V_166 . V_326 ;
V_294 = V_241 -> V_109 + V_2 -> V_166 . V_327 ;
V_295 = V_294 + V_2 -> V_166 . V_328 ;
V_41 = V_241 -> V_110 + V_2 -> V_166 . V_329 ;
V_297 = V_241 -> V_110 + V_2 -> V_166 . V_330 ;
V_298 = V_297 + V_2 -> V_166 . V_331 ;
V_304 = ! V_2 -> V_166 . V_332 ;
V_305 = ! V_2 -> V_166 . V_333 ;
V_307 = 100000000 / V_2 -> V_166 . clock ;
if ( V_2 -> V_166 . V_334 ) {
V_309 = 1 ;
V_293 -> V_238 = V_2 -> V_166 . V_335 |
( V_2 -> V_166 . V_336 << 16 ) ;
V_293 -> V_240 = V_2 -> V_166 . V_337 ;
}
}
V_306 = 1000000000 / V_307 ;
V_278 = V_306 / 10 ;
F_60 ( L_27 ,
V_294 , V_295 , V_40 ) ;
F_60 ( L_28 ,
V_297 , V_298 , V_41 ) ;
V_313 = ( V_295 - V_294 ) / 8 ;
V_314 = V_298 - V_297 ;
if ( V_313 == 0 )
V_313 = 1 ;
else if ( V_313 > 0x3f )
V_313 = 0x3f ;
if ( V_314 == 0 )
V_314 = 1 ;
else if ( V_314 > 0x1f )
V_314 = 0x1f ;
V_296 = V_241 -> V_303 & V_324 ? 0 : 1 ;
V_299 = V_241 -> V_303 & V_325 ? 0 : 1 ;
V_300 = V_241 -> V_303 & V_338 ? ( 1 << 4 ) : 0 ;
V_308 = F_63 ( V_178 ) ;
V_312 = V_241 -> V_102 >> 3 ;
if ( ( V_264 == V_152 ) || ( V_264 == V_156 ) )
V_311 = V_302 [ V_308 - 1 ] ;
else
V_311 = V_301 [ V_308 - 1 ] ;
V_310 = V_294 - 8 + V_311 ;
V_293 -> V_200 = V_339 | V_340 |
( V_308 << 8 ) ;
V_293 -> V_203 = V_2 -> V_161 . V_203 ;
V_293 -> V_203 &= 0xfffffff0 ;
if ( ( V_264 == V_152 ) || ( V_264 == V_156 ) ) {
V_293 -> V_202 = V_341 | V_342 ;
if ( V_136 )
V_293 -> V_202 |= V_135 ;
V_293 -> V_200 &= ~ ( V_343 |
V_344 ) ;
} else {
V_293 -> V_202 = V_341 | V_342 |
V_135 ;
}
V_293 -> V_205 = V_345 | V_346 |
V_347 ;
V_293 -> V_207 = ( ( ( ( V_40 / 8 ) - 1 ) & 0x3ff ) |
( ( ( V_241 -> V_109 / 8 ) - 1 ) << 16 ) ) ;
V_293 -> V_208 = ( ( V_310 & 0x1fff ) |
( V_313 << 16 ) | ( V_304 << 23 ) ) ;
V_293 -> V_210 = ( ( V_41 - 1 ) & 0xffff ) |
( ( V_241 -> V_110 - 1 ) << 16 ) ;
V_293 -> V_211 = ( ( ( V_297 - 1 ) & 0xfff ) |
( V_314 << 16 ) | ( V_305 << 23 ) ) ;
if ( ! ( V_96 -> V_113 & V_114 ) ) {
V_2 -> V_101 = ( ( V_241 -> V_112 * ( ( V_241 -> V_102 + 1 ) / 8 ) + 0x3f )
& ~ ( 0x3f ) ) >> 6 ;
V_293 -> V_213 = ( V_2 -> V_101 << 3 ) / ( ( V_241 -> V_102 + 1 ) / 8 ) ;
} else
V_293 -> V_213 = ( V_241 -> V_112 >> 3 ) ;
V_293 -> V_213 |= ( V_293 -> V_213 << 16 ) ;
V_293 -> V_215 = 0 ;
#if F_29 ( V_348 )
switch ( V_241 -> V_102 ) {
case 16 :
V_293 -> V_215 |= V_349 ;
V_293 -> V_215 |= V_350 ;
break;
case 24 :
case 32 :
V_293 -> V_215 |= V_351 ;
V_293 -> V_215 |= V_352 ;
break;
}
#endif
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
V_293 -> V_269 [ V_54 ] = 0 ;
V_293 -> V_271 [ V_54 ] = 0x1f ;
V_293 -> V_273 [ V_54 ] = 0 ;
}
F_60 ( L_29 ,
V_293 -> V_207 , V_293 -> V_208 ) ;
F_60 ( L_30 ,
V_293 -> V_210 , V_293 -> V_211 ) ;
V_2 -> V_177 = V_241 -> V_102 ;
V_2 -> V_178 = V_178 ;
F_60 ( L_31 , ( unsigned long ) V_307 ) ;
F_60 ( L_32 , ( unsigned long ) V_278 ) ;
V_293 -> V_237 = 0x300 ;
if ( ! V_309 )
F_59 ( V_2 , V_293 , V_278 ) ;
V_293 -> V_236 = V_2 -> V_161 . V_236 ;
if ( ( V_264 == V_152 ) || ( V_264 == V_156 ) ) {
unsigned int V_353 , V_354 ;
if ( V_241 -> V_109 > V_2 -> V_166 . V_109 )
V_241 -> V_109 = V_2 -> V_166 . V_109 ;
if ( V_241 -> V_110 > V_2 -> V_166 . V_110 )
V_241 -> V_110 = V_2 -> V_166 . V_110 ;
V_293 -> V_224 = ( ( ( V_2 -> V_166 . V_109 / 8 ) - 1 )
<< V_355 ) ;
V_293 -> V_228 = ( ( V_2 -> V_166 . V_110 - 1 )
<< V_356 ) ;
if ( V_241 -> V_109 != V_2 -> V_166 . V_109 ) {
V_353 = F_27 ( V_241 -> V_109 * V_357 ,
V_2 -> V_166 . V_109 ) ;
V_293 -> V_224 = ( ( ( ( ( unsigned long ) V_353 ) & V_358 ) ) |
( V_293 -> V_224 &
( V_359 | V_360 |
V_361 ) ) ) ;
V_293 -> V_224 |= ( V_362 |
V_363 ) ;
V_315 = 1 ;
}
V_293 -> V_224 &= ~ V_364 ;
if ( V_241 -> V_110 != V_2 -> V_166 . V_110 ) {
V_354 = F_27 ( V_241 -> V_110 * V_365 ,
V_2 -> V_166 . V_110 ) ;
V_293 -> V_228 = ( ( ( ( ( unsigned long ) V_354 ) & V_366 ) ) |
( V_293 -> V_228 &
( V_367 | V_368 ) ) ) ;
V_293 -> V_228 |= ( V_369 |
V_370 ) ;
V_315 = 1 ;
}
V_293 -> V_228 &= ~ V_371 ;
V_293 -> V_221 = ( V_2 -> V_161 . V_221 & ( T_5 )
~ ( V_372 |
V_373 |
V_374 |
V_375 |
V_376 |
V_377 |
V_378 |
V_379 ) ) ;
V_293 -> V_221 |= ( V_380 |
V_381 |
V_382 ) ;
if ( F_55 ( V_2 ) ||
( V_2 -> V_251 == V_291 ) ) {
V_293 -> V_221 &= ~ V_383 ;
if ( V_315 )
V_293 -> V_221 |= V_384 ;
else
V_293 -> V_221 |= V_385 ;
} else
V_293 -> V_221 |= V_386 ;
V_293 -> V_162 = V_2 -> V_161 . V_162 ;
V_293 -> V_230 = V_2 -> V_161 . V_230 ;
V_293 -> V_232 = V_2 -> V_161 . V_232 ;
V_293 -> V_234 = V_2 -> V_161 . V_234 ;
if ( V_264 == V_156 ) {
V_293 -> V_162 |= ( V_132 | V_133 ) ;
V_293 -> V_221 &= ~ ( V_154 | V_155 ) ;
} else {
V_293 -> V_221 |= ( V_154 | V_155 ) ;
V_293 -> V_234 &= ~ ( V_387 ) ;
if ( F_55 ( V_2 ) ||
( V_2 -> V_251 == V_291 ) || ! V_2 -> V_187 )
V_293 -> V_234 &= ~ V_388 ;
else
V_293 -> V_234 |= V_388 ;
V_293 -> V_202 &= ~ V_135 ;
}
V_293 -> V_217 = ( ( ( V_2 -> V_166 . V_326 / 8 ) & 0x3ff ) |
( ( ( V_241 -> V_109 / 8 ) - 1 ) << 16 ) ) ;
V_293 -> V_219 = ( V_2 -> V_166 . V_329 & 0xffff ) |
( ( V_241 -> V_110 - 1 ) << 16 ) ;
V_293 -> V_222 = ( ( V_2 -> V_166 . V_327 & 0x1fff ) |
( V_313 << 16 ) | ( V_304 << 23 ) ) ;
V_293 -> V_226 = ( ( V_2 -> V_166 . V_330 & 0xfff ) |
( V_314 << 16 ) | ( V_305 << 23 ) ) ;
}
if ( ! V_2 -> V_119 ) {
memcpy ( & V_2 -> V_389 , V_293 , sizeof( * V_293 ) ) ;
F_57 ( V_2 , V_293 , 0 ) ;
if ( ! ( V_96 -> V_113 & V_114 ) )
F_64 ( V_2 ) ;
}
if ( ! ( V_96 -> V_113 & V_114 ) )
V_96 -> V_121 . V_122 = V_2 -> V_101 * 64 ;
else
V_96 -> V_121 . V_122 = V_241 -> V_112
* ( ( V_241 -> V_102 + 1 ) / 8 ) ;
V_96 -> V_121 . V_390 = V_2 -> V_178 == 8 ? V_391
: V_392 ;
#ifdef F_65
F_66 ( V_2 -> V_393 , V_241 -> V_109 , V_241 -> V_110 ,
V_2 -> V_178 , V_96 -> V_121 . V_122 ) ;
#endif
F_67 ( V_293 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_95 * V_96 = V_2 -> V_96 ;
V_96 -> V_97 = V_2 ;
V_96 -> V_182 = V_2 -> V_182 ;
V_96 -> V_113 = V_394
| V_395
| V_396
| V_397
| V_398 ;
V_96 -> V_399 = & V_400 ;
V_96 -> V_401 = V_2 -> V_402 ;
V_96 -> V_403 = V_2 -> V_115 ;
F_69 ( V_96 -> V_121 . V_404 , V_2 -> V_405 , sizeof( V_96 -> V_121 . V_404 ) ) ;
V_96 -> V_121 . V_406 = V_2 -> V_393 ;
V_96 -> V_121 . V_407 = V_2 -> V_408 ;
V_96 -> V_121 . type = V_409 ;
V_96 -> V_121 . V_390 = V_391 ;
V_96 -> V_121 . V_410 = 8 ;
V_96 -> V_121 . V_411 = 1 ;
V_96 -> V_121 . V_412 = 0 ;
V_96 -> V_121 . V_413 = 0 ;
V_96 -> V_121 . V_414 = V_2 -> V_415 ;
V_96 -> V_121 . V_416 = V_417 ;
V_96 -> V_121 . V_418 = V_419 ;
F_70 ( & V_96 -> V_191 , 256 , 0 ) ;
if ( V_420 )
V_96 -> V_113 |= V_114 ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
T_5 V_421 , V_422 = 0 ;
T_5 V_423 ;
T_5 V_424 , V_425 ;
T_5 V_426 ;
if ( V_2 -> V_187 ) {
V_422 = F_4 ( V_427 ) ;
F_5 ( V_427 , V_422 | V_428 ) ;
}
V_421 = F_4 ( V_201 ) ;
V_423 = F_4 ( V_134 ) ;
F_5 ( V_134 , V_423 | V_143 ) ;
F_5 ( V_201 , V_421 | V_429 ) ;
F_72 ( 100 ) ;
V_424 = F_4 ( V_430 ) ;
V_425 = F_4 ( V_431 ) ;
#ifdef F_73
F_5 ( V_432 ,
( ( V_424 + V_425 - 1 ) & 0xffff0000 ) | ( V_424 >> 16 ) ) ;
V_2 -> V_433 = V_424 ;
#else
F_5 ( V_432 , 0x7fff0000 ) ;
V_2 -> V_433 = 0 ;
#endif
V_426 = V_424 + V_425 ;
if ( V_426 & 0xf0000000 )
V_426 = ( V_424 | 0x0fffffff ) + 1 ;
#ifdef F_73
F_5 ( V_434 , 0xffff0000 | ( V_426 >> 16 ) ) ;
#else
F_5 ( V_434 , 0xffffe000 ) ;
#endif
#ifdef F_73
F_5 ( V_435 , V_424 ) ;
if ( V_2 -> V_187 )
F_5 ( V_436 , V_424 ) ;
F_5 ( V_437 , V_424 ) ;
#else
F_5 ( V_435 , 0 ) ;
if ( V_2 -> V_187 )
F_5 ( V_436 , 0 ) ;
F_5 ( V_437 , 0 ) ;
#endif
F_72 ( 100 ) ;
F_5 ( V_201 , V_421 ) ;
F_5 ( V_134 , V_423 ) ;
if ( V_2 -> V_187 )
F_5 ( V_427 , V_422 ) ;
F_60 ( L_33 ,
V_424 ,
( ( V_424 + V_425 - 1 ) & 0xffff0000 ) | ( V_424 >> 16 ) ,
0xffff0000 | ( V_426 >> 16 ) ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
T_5 V_38 ;
if ( ( V_2 -> V_251 == V_438 ) ||
( V_2 -> V_251 == V_439 ) ||
( V_2 -> V_251 == V_252 ) ||
( V_2 -> V_251 == V_440 ) ||
( V_2 -> V_251 == V_253 ) ||
( V_2 -> V_251 == V_254 ) ) {
T_5 V_441 = F_4 ( V_442 ) ;
V_38 = ( ( ( ( V_441 >> 16 ) - ( V_441 & 0xffff ) + 1 ) << 6 ) * 1024 ) ;
F_34 ( 6 ) ;
F_5 ( V_432 , V_441 ) ;
F_5 ( V_435 , ( V_441 & 0xffff ) << 16 ) ;
F_5 ( V_436 , ( V_441 & 0xffff ) << 16 ) ;
F_5 ( V_437 , ( V_441 & 0xffff ) << 16 ) ;
F_5 ( V_443 , F_4 ( V_443 ) & ~ 0x7f0000 ) ;
if ( ( V_2 -> V_251 == V_438 ) ||
( V_2 -> V_251 == V_439 ) ) {
F_40 ( V_204 , V_444 ,
~ V_444 ) ;
}
} else {
V_38 = F_4 ( V_445 ) ;
}
V_2 -> V_408 = V_38 & V_446 ;
if ( V_2 -> V_408 == 0 ) {
switch ( V_2 -> V_13 -> V_447 ) {
case V_448 :
case V_449 :
V_2 -> V_408 = 8192 * 1024 ;
break;
default:
break;
}
}
if ( V_2 -> V_171 || ( V_2 -> V_251 >= V_450 ) ||
( F_4 ( V_451 ) & ( 1 << 30 ) ) )
V_2 -> V_452 = 1 ;
else
V_2 -> V_452 = 0 ;
V_38 = F_4 ( V_453 ) ;
if ( F_55 ( V_2 ) ) {
V_38 &= V_454 ;
switch ( V_38 ) {
case 0 : V_2 -> V_455 = 64 ; break;
case 1 : V_2 -> V_455 = 128 ; break;
case 2 : V_2 -> V_455 = 256 ; break;
default: V_2 -> V_455 = 128 ; break;
}
} else if ( ( V_2 -> V_251 == V_456 ) ||
( V_2 -> V_251 == V_438 ) ||
( V_2 -> V_251 == V_439 ) ) {
if ( V_38 & V_457 )
V_2 -> V_455 = 32 ;
else
V_2 -> V_455 = 64 ;
} else {
if ( V_38 & V_458 )
V_2 -> V_455 = 128 ;
else
V_2 -> V_455 = 64 ;
}
F_60 ( L_34 ,
F_8 ( V_2 -> V_13 ) ,
V_2 -> V_408 / 1024 ,
V_2 -> V_452 ? L_35 : L_36 ,
V_2 -> V_455 ) ;
}
static T_7 F_75 ( char * V_459 , T_8 V_460 , T_4 V_461 , const T_3 * V_462 )
{
return F_76 ( V_459 , V_461 , & V_460 , V_462 , V_463 ) ;
}
static T_7 F_77 ( struct V_464 * V_465 , struct V_466 * V_467 ,
struct V_468 * V_469 ,
char * V_459 , T_8 V_460 , T_4 V_461 )
{
struct V_447 * V_4 = F_78 ( V_467 , struct V_447 , V_467 ) ;
struct V_3 * V_13 = F_79 ( V_4 ) ;
struct V_95 * V_96 = F_80 ( V_13 ) ;
struct V_1 * V_2 = V_96 -> V_97 ;
return F_75 ( V_459 , V_460 , V_461 , V_2 -> V_470 ) ;
}
static T_7 F_81 ( struct V_464 * V_465 , struct V_466 * V_467 ,
struct V_468 * V_469 ,
char * V_459 , T_8 V_460 , T_4 V_461 )
{
struct V_447 * V_4 = F_78 ( V_467 , struct V_447 , V_467 ) ;
struct V_3 * V_13 = F_79 ( V_4 ) ;
struct V_95 * V_96 = F_80 ( V_13 ) ;
struct V_1 * V_2 = V_96 -> V_97 ;
return F_75 ( V_459 , V_460 , V_461 , V_2 -> V_471 ) ;
}
static int F_82 ( struct V_3 * V_13 ,
const struct V_472 * V_473 )
{
struct V_95 * V_96 ;
struct V_1 * V_2 ;
int V_474 ;
unsigned char V_475 , V_476 ;
int V_477 = 0 ;
F_60 ( L_37 ) ;
V_474 = F_83 ( V_13 ) ;
if ( V_474 < 0 ) {
F_7 ( V_12 L_38 ,
F_8 ( V_13 ) ) ;
goto V_478;
}
V_96 = F_84 ( sizeof( struct V_1 ) , & V_13 -> V_4 ) ;
if ( ! V_96 ) {
F_7 ( V_12 L_39 ,
F_8 ( V_13 ) ) ;
V_474 = - V_14 ;
goto V_479;
}
V_2 = V_96 -> V_97 ;
V_2 -> V_96 = V_96 ;
V_2 -> V_13 = V_13 ;
F_85 ( & V_2 -> V_480 ) ;
F_86 ( & V_2 -> V_157 ) ;
V_2 -> V_157 . V_481 = F_56 ;
V_2 -> V_157 . V_262 = ( unsigned long ) V_2 ;
V_475 = V_473 -> V_447 >> 8 ;
V_476 = V_473 -> V_447 & 0xff ;
if ( isprint ( V_475 ) && isprint ( V_476 ) )
snprintf ( V_2 -> V_405 , sizeof( V_2 -> V_405 ) ,
L_40 , V_473 -> V_447 & 0xffff , V_475 , V_476 ) ;
else
snprintf ( V_2 -> V_405 , sizeof( V_2 -> V_405 ) ,
L_41 , V_473 -> V_447 & 0xffff ) ;
V_2 -> V_251 = V_473 -> V_482 & V_483 ;
V_2 -> V_65 = V_13 -> V_447 ;
V_2 -> V_187 = ( V_473 -> V_482 & V_484 ) != 0 ;
V_2 -> V_128 = ( V_473 -> V_482 & V_485 ) != 0 ;
V_2 -> V_171 = ( V_473 -> V_482 & V_486 ) != 0 ;
V_2 -> V_393 = F_87 ( V_13 , 0 ) ;
V_2 -> V_415 = F_87 ( V_13 , 2 ) ;
V_474 = F_88 ( V_13 , 0 , L_42 ) ;
if ( V_474 < 0 ) {
F_7 ( V_12 L_43 ,
F_8 ( V_2 -> V_13 ) ) ;
goto V_487;
}
V_474 = F_88 ( V_13 , 2 , L_44 ) ;
if ( V_474 < 0 ) {
F_7 ( V_12 L_45 ,
F_8 ( V_2 -> V_13 ) ) ;
goto V_488;
}
V_2 -> V_489 = F_13 ( V_2 -> V_415 , V_417 ) ;
if ( ! V_2 -> V_489 ) {
F_7 ( V_12 L_46 ,
F_8 ( V_2 -> V_13 ) ) ;
V_474 = - V_490 ;
goto V_491;
}
V_2 -> V_433 = F_4 ( V_432 ) << 16 ;
V_2 -> V_492 = 0 ;
if ( V_2 -> V_251 == V_450 &&
( F_4 ( V_493 ) & V_494 )
== V_495 )
V_2 -> V_492 |= V_496 ;
if ( V_2 -> V_251 == V_497 ||
V_2 -> V_251 == V_439 )
V_2 -> V_492 |= V_498 ;
if ( V_2 -> V_251 == V_456 ||
V_2 -> V_251 == V_438 ||
V_2 -> V_251 == V_439 )
V_2 -> V_492 |= V_499 ;
#if F_29 ( V_88 ) || F_29 ( V_89 )
V_2 -> V_26 = F_89 ( V_13 ) ;
if ( V_2 -> V_26 == NULL )
F_7 ( V_17 L_47 ,
F_8 ( V_2 -> V_13 ) ) ;
#endif
#ifdef V_88
F_71 ( V_2 ) ;
#endif
F_74 ( V_2 ) ;
V_2 -> V_115 = F_90 (unsigned long, MAX_MAPPED_VRAM, rinfo->video_ram) ;
do {
V_2 -> V_402 = F_13 ( V_2 -> V_393 ,
V_2 -> V_115 ) ;
} while ( V_2 -> V_402 == NULL &&
( ( V_2 -> V_115 /= 2 ) >= V_500 ) );
if ( V_2 -> V_402 == NULL ) {
F_7 ( V_12 L_48 ,
F_8 ( V_2 -> V_13 ) ) ;
V_474 = - V_490 ;
goto V_501;
}
F_60 ( L_49 , F_8 ( V_2 -> V_13 ) ,
V_2 -> V_115 / 1024 ) ;
if ( ! V_2 -> V_128 )
F_3 ( V_2 , V_13 ) ;
#ifdef F_91
if ( V_2 -> V_5 == NULL )
F_12 ( V_2 ) ;
#endif
if ( V_2 -> V_5 == NULL && V_2 -> V_128 )
F_3 ( V_2 , V_13 ) ;
F_28 ( V_2 ) ;
#ifdef F_92
F_93 ( V_2 ) ;
#endif
F_68 ( V_2 ) ;
F_94 ( V_2 , V_502 , V_503 ) ;
F_95 ( V_2 , V_504 ) ;
if ( V_2 -> V_470 )
V_477 |= F_96 ( & V_2 -> V_13 -> V_4 . V_467 ,
& V_505 ) ;
if ( V_2 -> V_471 )
V_477 |= F_96 ( & V_2 -> V_13 -> V_4 . V_467 ,
& V_506 ) ;
if ( V_477 )
F_97 ( L_50 ,
V_507 ) ;
F_52 ( V_2 , & V_2 -> V_161 ) ;
memcpy ( & V_2 -> V_389 , & V_2 -> V_161 , sizeof( struct V_198 ) ) ;
if ( V_508 < - 1 ) {
F_98 ( V_2 , V_2 -> V_128 ? 1 : - 1 , V_509 , V_510 ) ;
} else
F_98 ( V_2 , V_508 , V_509 , V_510 ) ;
F_99 ( V_13 , V_96 ) ;
V_474 = F_100 ( V_96 ) ;
if ( V_474 < 0 ) {
F_7 ( V_12 L_51 ,
F_8 ( V_2 -> V_13 ) ) ;
goto V_511;
}
#ifdef F_101
V_2 -> V_512 = V_513 ? - 1 : F_102 ( V_2 -> V_393 ,
V_2 -> V_408 ,
V_514 , 1 ) ;
#endif
if ( V_515 )
F_103 ( V_2 ) ;
F_7 ( L_52 , F_8 ( V_2 -> V_13 ) , V_2 -> V_405 ) ;
if ( V_2 -> V_5 )
F_1 ( V_2 , V_13 ) ;
F_60 ( L_53 ) ;
return 0 ;
V_511:
F_15 ( V_2 -> V_402 ) ;
V_501:
F_67 ( V_2 -> V_470 ) ;
F_67 ( V_2 -> V_471 ) ;
if ( V_2 -> V_516 )
F_104 ( V_2 -> V_516 ) ;
F_105 ( & V_96 -> V_191 ) ;
#ifdef F_92
F_106 ( V_2 ) ;
#endif
if ( V_2 -> V_5 )
F_1 ( V_2 , V_13 ) ;
F_15 ( V_2 -> V_489 ) ;
V_491:
F_107 ( V_13 , 2 ) ;
V_488:
F_107 ( V_13 , 0 ) ;
V_487:
F_108 ( V_96 ) ;
V_479:
V_478:
return V_474 ;
}
static void F_109 ( struct V_3 * V_13 )
{
struct V_95 * V_96 = F_80 ( V_13 ) ;
struct V_1 * V_2 = V_96 -> V_97 ;
if ( ! V_2 )
return;
F_110 ( V_2 ) ;
if ( V_2 -> V_470 )
F_111 ( & V_2 -> V_13 -> V_4 . V_467 , & V_505 ) ;
if ( V_2 -> V_471 )
F_111 ( & V_2 -> V_13 -> V_4 . V_467 , & V_506 ) ;
#if 0
radeon_write_mode (rinfo, &rinfo->init_state, 1);
#endif
F_41 ( & V_2 -> V_157 ) ;
#ifdef F_101
if ( V_2 -> V_512 >= 0 )
F_112 ( V_2 -> V_512 , 0 , 0 ) ;
#endif
F_113 ( V_96 ) ;
F_114 ( V_2 ) ;
F_15 ( V_2 -> V_489 ) ;
F_15 ( V_2 -> V_402 ) ;
F_107 ( V_13 , 2 ) ;
F_107 ( V_13 , 0 ) ;
F_67 ( V_2 -> V_470 ) ;
F_67 ( V_2 -> V_471 ) ;
if ( V_2 -> V_516 )
F_104 ( V_2 -> V_516 ) ;
#ifdef F_92
F_106 ( V_2 ) ;
#endif
F_105 ( & V_96 -> V_191 ) ;
F_108 ( V_96 ) ;
}
static int T_9 F_115 ( char * V_517 )
{
char * V_518 ;
if ( ! V_517 || ! * V_517 )
return 0 ;
while ( ( V_518 = F_116 ( & V_517 , L_54 ) ) != NULL ) {
if ( ! * V_518 )
continue;
if ( ! strncmp ( V_518 , L_55 , 7 ) ) {
V_420 = 1 ;
} else if ( ! strncmp ( V_518 , L_56 , 6 ) ) {
V_136 = 1 ;
} else if ( ! strncmp ( V_518 , L_57 , 9 ) ) {
V_519 = 1 ;
} else if ( ! strncmp ( V_518 , L_58 , 11 ) ) {
V_520 = F_117 ( ( V_518 + 11 ) , NULL , 0 ) ;
} else if ( ! strncmp ( V_518 , L_59 , 10 ) ) {
V_515 = F_117 ( V_518 + 10 , NULL , 0 ) ;
#ifdef F_101
} else if ( ! strncmp ( V_518 , L_60 , 6 ) ) {
V_513 = 1 ;
#endif
} else if ( ! strncmp ( V_518 , L_61 , 9 ) ) {
V_265 = 1 ;
} else if ( ! strncmp ( V_518 , L_62 , 17 ) ) {
V_90 = 1 ;
} else if ( ! strncmp ( V_518 , L_63 , 11 ) ) {
V_503 = 1 ;
#if F_29 ( V_521 ) && F_29 ( F_91 )
} else if ( ! strncmp ( V_518 , L_64 , 11 ) ) {
V_510 = 1 ;
} else if ( ! strncmp ( V_518 , L_65 , 14 ) ) {
V_509 = 1 ;
#endif
} else
V_504 = V_518 ;
}
return 0 ;
}
static int T_9 F_118 ( void )
{
#ifndef F_119
char * V_522 = NULL ;
if ( F_120 ( L_66 , & V_522 ) )
return - V_28 ;
F_115 ( V_522 ) ;
#endif
return F_121 ( & V_523 ) ;
}
static void T_10 F_122 ( void )
{
F_123 ( & V_523 ) ;
}
