static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 * V_4 = V_2 -> V_5 ;
F_2 ( V_3 >= F_3 ( V_6 ) ) ;
return V_4 [ V_3 ] ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
T_2 * V_4 = V_2 -> V_5 ;
T_2 V_8 [ 2 ] ;
F_2 ( V_2 -> V_9 -> V_10 ) ;
V_8 [ 0 ] = V_3 & 0xff ;
V_8 [ 1 ] = V_7 & 0xff ;
if ( V_3 >= V_2 -> V_9 -> V_11 )
return - V_12 ;
if ( 2 != V_2 -> V_13 ( V_2 -> V_14 , V_8 , 2 ) )
return - V_12 ;
V_4 [ V_3 ] = V_7 ;
return 0 ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_15 == V_3 )
return F_6 ( V_2 -> V_14 , V_3 ) ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
int V_20 = V_17 -> V_21 == V_22 ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_20 ) {
F_8 ( V_2 , V_23 , 0x1F , 0x10 ) ;
F_8 ( V_2 , V_24 , 0x1F , 0x10 ) ;
} else {
F_8 ( V_2 , V_25 , 0x7 , 0x7 ) ;
F_8 ( V_2 , V_26 , 0x7 , 0x7 ) ;
F_8 ( V_2 , V_27 , 0x1F , 0x1 ) ;
F_8 ( V_2 , V_28 , 0x1F , 0x1 ) ;
}
return 0 ;
}
static int F_9 ( struct V_16 * V_17 ,
struct V_29 * V_30 ,
struct V_18 * V_19 )
{
struct V_31 * V_32 = V_17 -> V_33 ;
struct V_1 * V_2 = V_32 -> V_2 ;
T_1 V_34 ;
T_1 V_35 , V_36 , V_37 ;
T_1 V_38 , V_39 ;
F_4 ( V_2 , V_40 ,
V_41 | V_42 ) ;
F_4 ( V_2 , V_43 , V_44 | V_45 ) ;
V_34 = 0xFC & F_5 ( V_2 , V_46 ) ;
switch ( F_10 ( V_30 ) ) {
case V_47 :
V_34 |= V_48 ;
break;
case V_49 :
V_34 |= V_50 ;
break;
default:
return - V_51 ;
}
F_4 ( V_2 , V_46 , V_34 ) ;
V_35 = ( V_22 == V_17 -> V_21 ) ?
V_52 : V_53 ;
switch ( F_11 ( V_30 ) ) {
case 8000 :
V_38 = V_54 ;
V_36 = V_55 | V_56 ;
V_37 = V_57 | V_56 ;
V_39 = V_58 ;
break;
case 11025 :
V_38 = V_59 ;
V_36 = V_55 | V_56 ;
V_37 = V_57 | V_56 ;
V_39 = 0 ;
break;
case 12000 :
V_38 = V_60 ;
V_36 = V_55 | V_56 ;
V_37 = V_57 | V_56 ;
V_39 = V_58 ;
break;
case 16000 :
V_38 = V_61 ;
V_36 = V_55 | V_56 ;
V_37 = V_57 | V_56 ;
V_39 = V_58 ;
break;
case 22050 :
V_38 = V_62 ;
V_36 = V_56 ;
V_37 = 0 ;
V_39 = 0 ;
break;
case 32000 :
V_38 = V_63 ;
V_36 = V_56 ;
V_37 = 0 ;
V_39 = V_58 ;
break;
case 44100 :
V_38 = V_64 ;
V_36 = V_56 ;
V_37 = 0 ;
V_39 = 0 ;
break;
case 48000 :
V_38 = V_65 ;
V_36 = V_56 ;
V_37 = 0 ;
V_39 = V_58 ;
break;
case 88200 :
V_38 = V_66 ;
V_36 = V_56 ;
V_37 = 0 ;
V_39 = 0 ;
break;
case 96000 :
V_38 = V_67 ;
V_36 = V_56 ;
V_37 = 0 ;
V_39 = V_58 ;
break;
default:
return - V_51 ;
}
F_8 ( V_2 , V_68 , V_69 , 0 ) ;
F_8 ( V_2 , V_35 , V_36 , V_37 ) ;
F_8 ( V_2 , V_70 , V_71 , V_38 ) ;
F_8 ( V_2 , V_72 , V_58 , V_39 ) ;
F_8 ( V_2 , V_68 ,
V_69 , V_69 ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_73 , T_1 V_74 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
T_1 V_34 ;
T_1 V_75 ;
V_34 = 0x7f & F_5 ( V_2 , V_46 ) ;
V_75 = 0xfc & F_5 ( V_2 , V_43 ) ;
switch ( V_74 & V_76 ) {
case V_77 :
V_34 |= V_78 ;
break;
default:
return - V_51 ;
}
switch ( V_74 & V_79 ) {
case V_80 :
V_75 |= V_81 ;
break;
default:
return - V_51 ;
}
V_34 |= V_82 ;
F_4 ( V_2 , V_46 , V_34 ) ;
F_4 ( V_2 , V_43 , V_75 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = F_14 ( V_2 ) ;
F_15 ( V_2 -> V_85 , L_1 , V_86 ) ;
V_2 -> V_14 = V_84 -> V_14 ;
V_2 -> V_13 = ( V_87 ) V_88 ;
F_4 ( V_2 , V_68 , 0 ) ;
F_4 ( V_2 , V_72 ,
V_89 | V_58 ) ;
F_4 ( V_2 , V_25 , V_90 | V_91 ) ;
F_4 ( V_2 , V_26 , V_92 ) ;
F_4 ( V_2 , V_27 , V_93 ) ;
F_4 ( V_2 , V_28 , V_94 ) ;
F_4 ( V_2 , V_95 , V_96 | V_97 ) ;
F_4 ( V_2 , V_98 ,
V_99 | V_100 |
V_101 | V_102 ) ;
F_4 ( V_2 , V_23 , V_103 ) ;
F_4 ( V_2 , V_24 , V_104 ) ;
F_4 ( V_2 , V_105 ,
V_106 | V_107 |
V_108 | V_109 | V_110 ) ;
F_4 ( V_2 , V_70 , V_65 ) ;
F_4 ( V_2 , V_111 , 0xE5 ) ;
F_4 ( V_2 , V_112 , 0x99 ) ;
F_4 ( V_2 , V_72 , 0x0A |
V_89 | V_58 ) ;
F_8 ( V_2 , V_70 , V_113 , V_113 ) ;
F_4 ( V_2 , V_114 , 0x8B ) ;
F_4 ( V_2 , V_115 , 0xB4 ) ;
F_4 ( V_2 , V_116 , 0x01 ) ;
F_4 ( V_2 , V_117 , 0x7C ) ;
F_4 ( V_2 , V_114 , 0x00 ) ;
F_4 ( V_2 , V_115 , 0x00 ) ;
F_4 ( V_2 , V_68 , V_69 ) ;
F_16 ( V_2 , V_118 ,
F_3 ( V_118 ) ) ;
F_15 ( V_2 -> V_85 , L_1 , V_86 ) ;
return 0 ;
}
static int T_3 F_17 ( struct V_119 * V_120 ,
const struct V_121 * V_122 )
{
struct V_83 * V_84 ;
int V_123 ;
V_84 = F_18 ( sizeof( struct V_83 ) , V_124 ) ;
if ( ! V_84 )
return - V_125 ;
F_19 ( V_120 , V_84 ) ;
V_84 -> V_14 = V_120 ;
V_84 -> V_126 = V_127 ;
V_123 = F_20 ( & V_120 -> V_85 ,
& V_128 , & V_129 , 1 ) ;
if ( V_123 < 0 )
F_21 ( V_84 ) ;
return V_123 ;
}
static int T_4 F_22 ( struct V_119 * V_130 )
{
F_23 ( & V_130 -> V_85 ) ;
F_21 ( F_24 ( V_130 ) ) ;
return 0 ;
}
static int T_5 F_25 ( void )
{
int V_123 = 0 ;
#if F_26 ( V_131 ) || F_26 ( V_132 )
V_123 = F_27 ( & V_133 ) ;
#endif
return V_123 ;
}
static void T_6 F_28 ( void )
{
#if F_26 ( V_131 ) || F_26 ( V_132 )
F_29 ( & V_133 ) ;
#endif
}
