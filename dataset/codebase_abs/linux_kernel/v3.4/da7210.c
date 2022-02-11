static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_4 -> V_7 . integer . V_7 [ 0 ] ) {
if ( F_3 ( V_6 , V_8 ) & V_9 ) {
F_4 ( V_6 -> V_10 ,
L_1 ) ;
return - V_11 ;
}
}
return F_5 ( V_2 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_12 ;
if ( V_4 -> V_7 . integer . V_7 [ 0 ] ) {
if ( F_3 ( V_6 , V_13 ) & V_14 )
goto V_15;
if ( ( F_3 ( V_6 , V_16 ) &
( V_17 | V_18 | V_19 |
V_20 ) ) != ( V_17 |
V_18 | V_19 | V_20 ) )
goto V_15;
V_12 = F_3 ( V_6 , V_21 ) ;
if ( ( ( V_12 & V_22 ) < V_23 ) ||
( ( ( V_12 & V_24 ) >> 4 ) <
V_23 ) )
goto V_15;
if ( ( ( F_3 ( V_6 , V_25 ) & V_26 ) <
V_27 ) ||
( ( F_3 ( V_6 , V_28 ) & V_29 ) <
V_27 ) )
goto V_15;
}
return F_5 ( V_2 , V_4 ) ;
V_15:
return - V_11 ;
}
static bool F_7 ( struct V_30 * V_10 , unsigned int V_31 )
{
switch ( V_31 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return false ;
default:
return true ;
}
}
static bool F_8 ( struct V_30 * V_10 ,
unsigned int V_31 )
{
switch ( V_31 ) {
case V_36 :
return true ;
default:
return false ;
}
}
static int F_9 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 = V_38 -> V_45 ;
struct V_5 * V_6 = V_44 -> V_6 ;
T_2 V_46 ;
T_2 V_47 , V_48 ;
F_10 ( V_6 , V_49 ,
V_50 | V_51 ) ;
F_10 ( V_6 , V_52 , V_53 | V_54 ) ;
V_46 = 0xFC & F_3 ( V_6 , V_55 ) ;
switch ( F_11 ( V_40 ) ) {
case V_56 :
V_46 |= V_57 ;
break;
case V_58 :
V_46 |= V_59 ;
break;
case V_60 :
V_46 |= V_61 ;
break;
case V_62 :
V_46 |= V_63 ;
break;
default:
return - V_11 ;
}
F_10 ( V_6 , V_55 , V_46 ) ;
switch ( F_12 ( V_40 ) ) {
case 8000 :
V_47 = V_64 ;
V_48 = V_65 ;
break;
case 11025 :
V_47 = V_66 ;
V_48 = 0 ;
break;
case 12000 :
V_47 = V_67 ;
V_48 = V_65 ;
break;
case 16000 :
V_47 = V_68 ;
V_48 = V_65 ;
break;
case 22050 :
V_47 = V_69 ;
V_48 = 0 ;
break;
case 32000 :
V_47 = V_70 ;
V_48 = V_65 ;
break;
case 44100 :
V_47 = V_71 ;
V_48 = 0 ;
break;
case 48000 :
V_47 = V_72 ;
V_48 = V_65 ;
break;
case 88200 :
V_47 = V_73 ;
V_48 = 0 ;
break;
case 96000 :
V_47 = V_74 ;
V_48 = V_65 ;
break;
default:
return - V_11 ;
}
F_13 ( V_6 , V_75 , V_76 , 0 ) ;
F_13 ( V_6 , V_77 , V_78 , V_47 ) ;
F_13 ( V_6 , V_79 , V_65 , V_48 ) ;
F_13 ( V_6 , V_75 ,
V_76 , V_76 ) ;
return 0 ;
}
static int F_14 ( struct V_41 * V_80 , T_2 V_81 )
{
struct V_5 * V_6 = V_80 -> V_6 ;
T_2 V_46 ;
T_2 V_82 ;
V_46 = 0x7f & F_3 ( V_6 , V_55 ) ;
V_82 = 0xfc & F_3 ( V_6 , V_52 ) ;
switch ( V_81 & V_83 ) {
case V_84 :
V_46 |= V_85 ;
break;
case V_86 :
V_46 |= V_87 ;
break;
default:
return - V_11 ;
}
switch ( V_81 & V_88 ) {
case V_89 :
V_82 |= V_90 ;
break;
case V_91 :
V_82 |= V_92 ;
break;
case V_93 :
V_82 |= V_94 ;
break;
default:
return - V_11 ;
}
V_46 |= V_95 ;
F_10 ( V_6 , V_55 , V_46 ) ;
F_10 ( V_6 , V_52 , V_82 ) ;
return 0 ;
}
static int F_15 ( struct V_41 * V_42 , int V_96 )
{
struct V_5 * V_6 = V_42 -> V_6 ;
T_1 V_97 = F_3 ( V_6 , V_98 ) & 0xFB ;
if ( V_96 )
F_10 ( V_6 , V_98 , V_97 | 0x4 ) ;
else
F_10 ( V_6 , V_98 , V_97 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_99 * V_100 = F_17 ( V_6 ) ;
int V_101 ;
F_18 ( V_6 -> V_10 , L_2 , V_102 ) ;
V_6 -> V_103 = V_100 -> V_104 ;
V_101 = F_19 ( V_6 , 8 , 8 , V_105 ) ;
if ( V_101 < 0 ) {
F_20 ( V_6 -> V_10 , L_3 , V_101 ) ;
return V_101 ;
}
F_10 ( V_6 , V_75 , 0 ) ;
F_10 ( V_6 , V_79 ,
V_106 | V_65 ) ;
F_10 ( V_6 , V_107 , V_108 | V_109 ) ;
F_10 ( V_6 , V_110 , V_111 ) ;
F_10 ( V_6 , V_112 , V_113 ) ;
F_10 ( V_6 , V_114 , V_115 ) ;
F_10 ( V_6 , V_13 , V_116 | V_117 ) ;
F_10 ( V_6 , V_118 ,
V_119 | V_120 |
V_121 | V_122 ) ;
F_10 ( V_6 , V_123 , V_124 ) ;
F_10 ( V_6 , V_125 , V_126 ) ;
F_10 ( V_6 , V_127 ,
V_128 | V_129 |
V_130 | V_131 | V_132 ) ;
F_10 ( V_6 , V_133 , V_134 ) ;
F_10 ( V_6 , V_135 , V_136 ) ;
F_10 ( V_6 , V_137 , V_138 ) ;
F_10 ( V_6 , V_139 , V_140 |
V_141 | V_142 ) ;
F_10 ( V_6 , V_25 , V_143 ) ;
F_10 ( V_6 , V_28 , V_144 ) ;
F_10 ( V_6 , V_145 , V_146 ) ;
F_10 ( V_6 , V_77 , V_72 ) ;
F_10 ( V_6 , V_147 , 0xE5 ) ;
F_10 ( V_6 , V_148 , 0x99 ) ;
F_10 ( V_6 , V_79 , 0x0A |
V_106 | V_65 ) ;
F_13 ( V_6 , V_77 , V_149 , V_149 ) ;
F_21 ( V_100 -> V_104 , V_32 , 0x8B ) ;
F_21 ( V_100 -> V_104 , V_33 , 0xB4 ) ;
F_21 ( V_100 -> V_104 , V_34 , 0x01 ) ;
F_21 ( V_100 -> V_104 , V_35 , 0x7C ) ;
F_21 ( V_100 -> V_104 , V_32 , 0x00 ) ;
F_21 ( V_100 -> V_104 , V_33 , 0x00 ) ;
F_10 ( V_6 , V_75 , V_76 ) ;
F_18 ( V_6 -> V_10 , L_2 , V_102 ) ;
return 0 ;
}
static int T_3 F_22 ( struct V_150 * V_151 ,
const struct V_152 * V_153 )
{
struct V_99 * V_100 ;
int V_101 ;
V_100 = F_23 ( & V_151 -> V_10 , sizeof( struct V_99 ) ,
V_154 ) ;
if ( ! V_100 )
return - V_155 ;
F_24 ( V_151 , V_100 ) ;
V_100 -> V_104 = F_25 ( V_151 , & V_156 ) ;
if ( F_26 ( V_100 -> V_104 ) ) {
V_101 = F_27 ( V_100 -> V_104 ) ;
F_20 ( & V_151 -> V_10 , L_4 , V_101 ) ;
return V_101 ;
}
V_101 = F_28 ( & V_151 -> V_10 ,
& V_157 , & V_158 , 1 ) ;
if ( V_101 < 0 ) {
F_20 ( & V_151 -> V_10 , L_5 , V_101 ) ;
goto V_159;
}
return V_101 ;
V_159:
F_29 ( V_100 -> V_104 ) ;
return V_101 ;
}
static int T_4 F_30 ( struct V_150 * V_160 )
{
struct V_99 * V_100 = F_31 ( V_160 ) ;
F_32 ( & V_160 -> V_10 ) ;
F_29 ( V_100 -> V_104 ) ;
return 0 ;
}
static int T_5 F_33 ( void )
{
int V_101 = 0 ;
#if F_34 ( V_161 ) || F_34 ( V_162 )
V_101 = F_35 ( & V_163 ) ;
#endif
return V_101 ;
}
static void T_6 F_36 ( void )
{
#if F_34 ( V_161 ) || F_34 ( V_162 )
F_37 ( & V_163 ) ;
#endif
}
