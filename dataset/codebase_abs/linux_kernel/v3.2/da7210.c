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
static int F_7 ( struct V_5 * V_6 ,
unsigned int V_30 )
{
switch ( V_30 ) {
case V_31 :
return 1 ;
default:
return 0 ;
}
}
static int F_8 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = V_33 -> V_40 ;
struct V_5 * V_6 = V_39 -> V_6 ;
T_2 V_41 ;
T_2 V_42 , V_43 ;
F_9 ( V_6 , V_44 ,
V_45 | V_46 ) ;
F_9 ( V_6 , V_47 , V_48 | V_49 ) ;
V_41 = 0xFC & F_3 ( V_6 , V_50 ) ;
switch ( F_10 ( V_35 ) ) {
case V_51 :
V_41 |= V_52 ;
break;
case V_53 :
V_41 |= V_54 ;
break;
case V_55 :
V_41 |= V_56 ;
break;
case V_57 :
V_41 |= V_58 ;
break;
default:
return - V_11 ;
}
F_9 ( V_6 , V_50 , V_41 ) ;
switch ( F_11 ( V_35 ) ) {
case 8000 :
V_42 = V_59 ;
V_43 = V_60 ;
break;
case 11025 :
V_42 = V_61 ;
V_43 = 0 ;
break;
case 12000 :
V_42 = V_62 ;
V_43 = V_60 ;
break;
case 16000 :
V_42 = V_63 ;
V_43 = V_60 ;
break;
case 22050 :
V_42 = V_64 ;
V_43 = 0 ;
break;
case 32000 :
V_42 = V_65 ;
V_43 = V_60 ;
break;
case 44100 :
V_42 = V_66 ;
V_43 = 0 ;
break;
case 48000 :
V_42 = V_67 ;
V_43 = V_60 ;
break;
case 88200 :
V_42 = V_68 ;
V_43 = 0 ;
break;
case 96000 :
V_42 = V_69 ;
V_43 = V_60 ;
break;
default:
return - V_11 ;
}
F_12 ( V_6 , V_70 , V_71 , 0 ) ;
F_12 ( V_6 , V_72 , V_73 , V_42 ) ;
F_12 ( V_6 , V_74 , V_60 , V_43 ) ;
F_12 ( V_6 , V_70 ,
V_71 , V_71 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_75 , T_2 V_76 )
{
struct V_5 * V_6 = V_75 -> V_6 ;
T_2 V_41 ;
T_2 V_77 ;
V_41 = 0x7f & F_3 ( V_6 , V_50 ) ;
V_77 = 0xfc & F_3 ( V_6 , V_47 ) ;
switch ( V_76 & V_78 ) {
case V_79 :
V_41 |= V_80 ;
break;
case V_81 :
V_41 |= V_82 ;
break;
default:
return - V_11 ;
}
switch ( V_76 & V_83 ) {
case V_84 :
V_77 |= V_85 ;
break;
case V_86 :
V_77 |= V_87 ;
break;
case V_88 :
V_77 |= V_89 ;
break;
default:
return - V_11 ;
}
V_41 |= V_90 ;
F_9 ( V_6 , V_50 , V_41 ) ;
F_9 ( V_6 , V_47 , V_77 ) ;
return 0 ;
}
static int F_14 ( struct V_36 * V_37 , int V_91 )
{
struct V_5 * V_6 = V_37 -> V_6 ;
T_1 V_92 = F_3 ( V_6 , V_93 ) & 0xFB ;
if ( V_91 )
F_9 ( V_6 , V_93 , V_92 | 0x4 ) ;
else
F_9 ( V_6 , V_93 , V_92 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_94 * V_95 = F_16 ( V_6 ) ;
int V_96 ;
F_17 ( V_6 -> V_10 , L_2 , V_97 ) ;
V_96 = F_18 ( V_6 , 8 , 8 , V_95 -> V_98 ) ;
if ( V_96 < 0 ) {
F_19 ( V_6 -> V_10 , L_3 , V_96 ) ;
return V_96 ;
}
F_9 ( V_6 , V_70 , 0 ) ;
F_9 ( V_6 , V_74 ,
V_99 | V_60 ) ;
F_9 ( V_6 , V_100 , V_101 | V_102 ) ;
F_9 ( V_6 , V_103 , V_104 ) ;
F_9 ( V_6 , V_105 , V_106 ) ;
F_9 ( V_6 , V_107 , V_108 ) ;
F_9 ( V_6 , V_13 , V_109 | V_110 ) ;
F_9 ( V_6 , V_111 ,
V_112 | V_113 |
V_114 | V_115 ) ;
F_9 ( V_6 , V_116 , V_117 ) ;
F_9 ( V_6 , V_118 , V_119 ) ;
F_9 ( V_6 , V_120 ,
V_121 | V_122 |
V_123 | V_124 | V_125 ) ;
F_9 ( V_6 , V_126 , V_127 ) ;
F_9 ( V_6 , V_128 , V_129 ) ;
F_9 ( V_6 , V_130 , V_131 ) ;
F_9 ( V_6 , V_132 , V_133 |
V_134 | V_135 ) ;
F_9 ( V_6 , V_72 , V_67 ) ;
F_9 ( V_6 , V_136 , 0xE5 ) ;
F_9 ( V_6 , V_137 , 0x99 ) ;
F_9 ( V_6 , V_74 , 0x0A |
V_99 | V_60 ) ;
F_12 ( V_6 , V_72 , V_138 , V_138 ) ;
F_9 ( V_6 , V_139 , 0x8B ) ;
F_9 ( V_6 , V_140 , 0xB4 ) ;
F_9 ( V_6 , V_141 , 0x01 ) ;
F_9 ( V_6 , V_142 , 0x7C ) ;
F_9 ( V_6 , V_139 , 0x00 ) ;
F_9 ( V_6 , V_140 , 0x00 ) ;
F_9 ( V_6 , V_70 , V_71 ) ;
F_17 ( V_6 -> V_10 , L_2 , V_97 ) ;
return 0 ;
}
static int T_3 F_20 ( struct V_143 * V_144 ,
const struct V_145 * V_146 )
{
struct V_94 * V_95 ;
int V_96 ;
V_95 = F_21 ( sizeof( struct V_94 ) , V_147 ) ;
if ( ! V_95 )
return - V_148 ;
F_22 ( V_144 , V_95 ) ;
V_95 -> V_98 = V_149 ;
V_96 = F_23 ( & V_144 -> V_10 ,
& V_150 , & V_151 , 1 ) ;
if ( V_96 < 0 )
F_24 ( V_95 ) ;
return V_96 ;
}
static int T_4 F_25 ( struct V_143 * V_152 )
{
F_26 ( & V_152 -> V_10 ) ;
F_24 ( F_27 ( V_152 ) ) ;
return 0 ;
}
static int T_5 F_28 ( void )
{
int V_96 = 0 ;
#if F_29 ( V_153 ) || F_29 ( V_154 )
V_96 = F_30 ( & V_155 ) ;
#endif
return V_96 ;
}
static void T_6 F_31 ( void )
{
#if F_29 ( V_153 ) || F_29 ( V_154 )
F_32 ( & V_155 ) ;
#endif
}
