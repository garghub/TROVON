static T_1 F_1 ( int V_1 , void * V_2 )
{
T_1 V_3 = V_4 ;
struct V_5 * V_6 = V_2 ;
unsigned int V_7 ;
unsigned int V_8 ;
F_2 ( & V_6 -> V_9 ) ;
if ( ! V_6 -> V_10 )
goto V_11;
F_3 ( V_6 -> V_10 ) ;
if ( V_6 -> V_12 == V_13 )
goto V_14;
V_7 = F_4 ( V_6 ) ;
F_5 ( V_6 , V_7 ) ;
if ( F_6 ( V_7 & F_7 ( V_6 ) ) ) {
F_8 ( V_6 -> V_15 , L_1 ) ;
if ( V_6 -> V_16 ) {
V_6 -> V_12 = V_17 ;
} else {
F_9 ( V_6 ) ;
F_10 ( V_6 -> V_10 , V_18 ) ;
}
V_3 = V_19 ;
}
if ( F_6 ( V_7 & F_11 ( V_6 ) ) ) {
F_8 ( V_6 -> V_15 , L_2 ) ;
F_12 ( V_6 ) ;
F_10 ( V_6 -> V_10 , V_18 ) ;
V_3 = V_19 ;
}
if ( F_6 ( V_7 & F_13 ( V_6 ) ) ) {
if ( ! V_6 -> V_16 ) {
F_8 ( V_6 -> V_15 ,
L_3 ) ;
V_3 = - V_20 ;
goto V_14;
}
V_8 = F_14 ( V_6 ) ;
F_15 ( V_6 -> V_15 , L_4 ,
V_8 ) ;
F_16 ( V_6 ) ;
V_6 -> V_12 = V_21 ;
V_3 = V_19 ;
}
if ( F_6 ( V_7 &
F_17 ( V_6 ) ) ) {
F_8 ( V_6 -> V_15 , L_5 ) ;
F_10 ( V_6 -> V_10 , V_18 ) ;
V_3 = V_19 ;
}
V_14:
F_18 ( V_6 -> V_10 ) ;
V_11:
F_19 ( & V_6 -> V_9 ) ;
return V_3 ;
}
static int F_20 ( struct V_5 * V_6 , unsigned long V_22 )
{
int V_23 , V_24 , V_25 , V_3 ;
int V_26 = V_6 -> V_27 ;
if ( V_26 < 0 ) {
V_25 = - 1 ;
V_26 = - V_26 ;
} else {
V_25 = 1 ;
}
V_25 *= ( int ) F_21 ( ( V_28 ) V_22 *
( V_28 ) V_26 + 500000 , 1000000 ) ;
V_23 = V_22 + V_25 ;
if ( ! V_23 )
return - V_29 ;
V_3 = F_22 ( V_6 -> V_30 , V_23 ) ;
if ( V_3 < 0 )
return V_3 ;
V_24 = F_23 ( V_6 -> V_30 ) ;
if ( ! V_24 )
return - V_29 ;
V_25 = V_24 - V_22 ;
if ( V_25 < 0 ) {
V_25 = - V_25 ;
V_26 = - 1 ;
} else {
V_26 = 1 ;
}
V_26 *= ( int ) F_21 ( ( V_28 ) V_25 * 1000000 + V_22 / 2 ,
V_22 ) ;
V_6 -> V_27 = V_26 ;
return 0 ;
}
static void F_24 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
int V_33 ;
unsigned int V_7 ;
F_25 ( & V_6 -> V_34 ) ;
if ( V_32 ) {
switch ( V_32 -> V_22 ) {
case 22050 :
V_6 -> V_35 . V_36 . V_7 [ 3 ] =
V_37 ;
break;
case 44100 :
V_6 -> V_35 . V_36 . V_7 [ 3 ] =
V_38 ;
break;
case 88200 :
V_6 -> V_35 . V_36 . V_7 [ 3 ] =
V_39 ;
break;
case 176400 :
V_6 -> V_35 . V_36 . V_7 [ 3 ] =
V_40 ;
break;
case 24000 :
V_6 -> V_35 . V_36 . V_7 [ 3 ] =
V_41 ;
break;
case 48000 :
V_6 -> V_35 . V_36 . V_7 [ 3 ] =
V_42 ;
break;
case 96000 :
V_6 -> V_35 . V_36 . V_7 [ 3 ] =
V_43 ;
break;
case 192000 :
V_6 -> V_35 . V_36 . V_7 [ 3 ] =
V_44 ;
break;
case 32000 :
V_6 -> V_35 . V_36 . V_7 [ 3 ] =
V_45 ;
break;
default:
V_6 -> V_35 . V_36 . V_7 [ 3 ] =
V_46 ;
break;
}
}
if ( V_6 -> V_35 . V_36 . V_7 [ 0 ] & V_47 )
V_6 -> V_35 . V_48 =
V_49 ;
else
V_6 -> V_35 . V_48 =
V_50 ;
if ( V_6 -> V_35 . V_48 ==
V_50 )
F_26 ( V_6 , 0 ) ;
else
F_26 ( V_6 , 1 ) ;
for ( V_33 = 0 ; V_33 < 6 ; ++ V_33 ) {
V_7 =
V_6 -> V_35 . V_36 . V_7 [ 0 + ( V_33 * 4 ) ] & 0xf ;
V_7 |=
V_6 -> V_35 . V_36 . V_7 [ 1 + ( V_33 * 4 ) ] << 8 ;
V_7 |=
V_6 -> V_35 . V_36 . V_7 [ 2 + ( V_33 * 4 ) ] << 16 ;
V_7 |=
V_6 -> V_35 . V_36 . V_7 [ 3 + ( V_33 * 4 ) ] << 24 ;
F_27 ( V_6 , V_33 , V_7 ) ;
}
F_28 ( & V_6 -> V_34 ) ;
if ( V_6 -> V_51 < V_52 )
F_29 ( V_6 ) ;
else
F_30 ( V_6 ) ;
}
static int F_31 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
int V_53 ;
V_53 = V_6 -> V_54 / V_32 -> V_22 ;
if ( ( V_53 % 128 ) || ( V_53 <= 0 ) ) {
F_8 ( V_6 -> V_15 , L_6 ,
V_55 , V_53 ) ;
return - V_29 ;
}
switch ( V_32 -> V_56 ) {
case V_57 :
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
F_34 ( V_6 ) ;
break;
case V_58 :
F_35 ( V_6 ) ;
F_33 ( V_6 ) ;
F_36 ( V_6 ) ;
break;
default:
F_8 ( V_6 -> V_15 , L_7 ) ;
return - V_29 ;
}
F_37 ( V_6 ) ;
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
F_40 ( V_6 ) ;
F_41 ( V_6 ) ;
F_42 ( V_6 ) ;
F_24 ( V_6 , V_32 ) ;
F_26 ( V_6 , 0 ) ;
F_43 ( V_6 ) ;
F_44 ( V_6 ) ;
F_45 ( V_6 ) ;
F_46 ( V_6 ) ;
if ( V_6 -> V_35 . V_48 ==
V_49 )
F_47 ( V_6 ) ;
else
F_48 ( V_6 ) ;
F_49 ( V_6 , V_32 -> V_59 / 2 ) ;
F_50 ( V_6 ) ;
F_51 ( V_6 , V_53 / 128 ) ;
F_52 ( V_6 ) ;
if ( V_6 -> V_51 < V_52 )
F_53 ( V_6 ) ;
else
F_54 ( V_6 ) ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
int V_60 , V_61 , V_53 ;
if ( ( V_6 -> V_62 & V_63 ) ==
V_64 )
V_61 = 32 ;
else
V_61 = F_56 ( V_32 -> V_56 ) ;
V_60 = V_61 * V_32 -> V_59 ;
V_53 = V_6 -> V_54 / V_32 -> V_22 ;
if ( ( V_61 == 32 ) && ( V_53 % 128 ) ) {
F_8 ( V_6 -> V_15 , L_8 , V_55 ) ;
return - V_29 ;
}
if ( ( V_61 == 16 ) && ( V_53 % 64 ) ) {
F_8 ( V_6 -> V_15 , L_8 , V_55 ) ;
return - V_29 ;
}
switch ( V_61 ) {
case 32 :
F_33 ( V_6 ) ;
F_57 ( V_6 ) ;
break;
case 16 :
F_58 ( V_6 ) ;
F_34 ( V_6 ) ;
break;
default:
F_8 ( V_6 -> V_15 , L_9 ) ;
return - V_29 ;
}
switch ( V_32 -> V_56 ) {
case V_57 :
F_32 ( V_6 ) ;
break;
case V_58 :
F_35 ( V_6 ) ;
break;
default:
F_8 ( V_6 -> V_15 , L_7 ) ;
return - V_29 ;
}
F_50 ( V_6 ) ;
F_51 ( V_6 , V_53 / ( 2 * V_60 ) ) ;
if ( ( V_32 -> V_59 % 2 ) || ( V_32 -> V_59 < 2 ) ||
( V_32 -> V_59 > 10 ) ) {
F_8 ( V_6 -> V_15 , L_10 , V_55 ) ;
return - V_29 ;
}
F_49 ( V_6 , V_32 -> V_59 / 2 ) ;
F_43 ( V_6 ) ;
F_46 ( V_6 ) ;
F_53 ( V_6 ) ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
int V_65 ;
int V_66 ;
unsigned int V_67 [ 4 ] = {
0x04060002 , 0x0C0E080A , 0x14161012 , 0x1C1E181A } ;
int V_68 , V_3 ;
V_65 =
F_60 ( V_6 ) ;
V_66 =
F_61 ( V_32 ) ;
F_35 ( V_6 ) ;
F_57 ( V_6 ) ;
F_49 ( V_6 , V_66 / 4 / 2 ) ;
F_46 ( V_6 ) ;
F_62 ( V_6 ) ;
F_63 ( V_6 ) ;
F_64 ( V_6 , V_65 ) ;
F_65 ( V_6 , V_67 ) ;
F_66 ( V_6 , 1_2 , V_67 [ V_69 ] ) ;
F_66 ( V_6 , 3_4 , V_67 [ V_70 ] ) ;
F_66 ( V_6 , 5_6 , V_67 [ V_71 ] ) ;
F_66 ( V_6 , 7_8 , V_67 [ V_72 ] ) ;
V_68 = V_32 -> V_22 * V_65 * 8 ;
F_25 ( & V_6 -> V_34 ) ;
V_3 = F_20 ( V_6 , V_68 ) ;
if ( ! V_3 )
V_6 -> V_54 = V_68 ;
F_28 ( & V_6 -> V_34 ) ;
return 0 ;
}
static int F_67 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
V_76 -> type = V_77 ;
V_76 -> V_78 = 1 ;
return 0 ;
}
static int F_68 ( struct V_73 * V_74 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = F_69 ( V_74 ) ;
struct V_83 * V_84 = F_70 ( V_82 ) ;
struct V_5 * V_6 = V_84 -> V_85 . V_86 ;
struct V_87 * V_36 = & V_6 -> V_35 . V_36 ;
F_25 ( & V_6 -> V_34 ) ;
V_80 -> V_88 . V_36 . V_7 [ 0 ] = V_36 -> V_7 [ 0 ] ;
V_80 -> V_88 . V_36 . V_7 [ 1 ] = V_36 -> V_7 [ 1 ] ;
V_80 -> V_88 . V_36 . V_7 [ 2 ] = V_36 -> V_7 [ 2 ] ;
V_80 -> V_88 . V_36 . V_7 [ 3 ] = V_36 -> V_7 [ 3 ] ;
F_28 ( & V_6 -> V_34 ) ;
return 0 ;
}
static int F_71 ( struct V_73 * V_74 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = F_69 ( V_74 ) ;
struct V_83 * V_84 = F_70 ( V_82 ) ;
struct V_5 * V_6 = V_84 -> V_85 . V_86 ;
struct V_87 * V_36 = & V_6 -> V_35 . V_36 ;
unsigned long V_89 ;
F_25 ( & V_6 -> V_34 ) ;
V_36 -> V_7 [ 0 ] = V_80 -> V_88 . V_36 . V_7 [ 0 ] ;
V_36 -> V_7 [ 1 ] = V_80 -> V_88 . V_36 . V_7 [ 1 ] ;
V_36 -> V_7 [ 2 ] = V_80 -> V_88 . V_36 . V_7 [ 2 ] ;
V_36 -> V_7 [ 3 ] = V_80 -> V_88 . V_36 . V_7 [ 3 ] ;
F_28 ( & V_6 -> V_34 ) ;
F_72 ( & V_6 -> V_9 , V_89 ) ;
if ( V_6 -> V_10 && V_6 -> V_10 -> V_32 )
F_24 ( V_6 ,
V_6 -> V_10 -> V_32 ) ;
else
F_24 ( V_6 , NULL ) ;
F_73 ( & V_6 -> V_9 , V_89 ) ;
return 0 ;
}
static int F_74 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
V_76 -> type = V_90 ;
V_76 -> V_78 = 1 ;
V_76 -> V_88 . integer . V_91 = V_92 ;
V_76 -> V_88 . integer . V_93 = V_94 ;
V_76 -> V_88 . integer . V_95 = 1 ;
return 0 ;
}
static int F_75 ( struct V_73 * V_74 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = F_69 ( V_74 ) ;
struct V_83 * V_84 = F_70 ( V_82 ) ;
struct V_5 * V_6 = V_84 -> V_85 . V_86 ;
F_25 ( & V_6 -> V_34 ) ;
V_80 -> V_88 . integer . V_88 [ 0 ] = V_6 -> V_27 ;
F_28 ( & V_6 -> V_34 ) ;
return 0 ;
}
static int F_76 ( struct V_73 * V_74 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = F_69 ( V_74 ) ;
struct V_83 * V_84 = F_70 ( V_82 ) ;
struct V_5 * V_6 = V_84 -> V_85 . V_86 ;
int V_3 = 0 ;
if ( ( V_80 -> V_88 . integer . V_88 [ 0 ] < V_92 ) ||
( V_80 -> V_88 . integer . V_88 [ 0 ] > V_94 ) )
return - V_29 ;
F_25 ( & V_6 -> V_34 ) ;
V_6 -> V_27 = V_80 -> V_88 . integer . V_88 [ 0 ] ;
if ( V_6 -> V_54 )
V_3 = F_20 ( V_6 , V_6 -> V_54 ) ;
F_28 ( & V_6 -> V_34 ) ;
return V_3 ;
}
static int F_77 ( struct V_96 * V_10 ,
struct V_81 * V_82 )
{
struct V_83 * V_84 = F_70 ( V_82 ) ;
struct V_5 * V_6 = V_84 -> V_85 . V_86 ;
unsigned long V_89 ;
int V_3 ;
F_72 ( & V_6 -> V_9 , V_89 ) ;
V_6 -> V_10 = V_10 ;
F_73 ( & V_6 -> V_9 , V_89 ) ;
V_6 -> V_27 = 0 ;
if ( ! F_78 ( V_6 ) )
return 0 ;
V_3 = F_79 ( V_10 -> V_32 , 0 ,
V_97 ,
V_98 ,
V_6 , V_97 ,
- 1 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_79 ( V_10 -> V_32 , 0 ,
V_99 ,
V_100 ,
V_6 , V_99 ,
- 1 ) ;
}
static int F_80 ( struct V_81 * V_82 , int V_101 ,
unsigned int V_68 , int V_102 )
{
struct V_83 * V_84 = F_70 ( V_82 ) ;
struct V_5 * V_6 = V_84 -> V_85 . V_86 ;
int V_3 ;
if ( F_78 ( V_6 ) || ( V_102 == V_103 ) )
return 0 ;
if ( V_101 != 0 )
return - V_29 ;
F_25 ( & V_6 -> V_34 ) ;
V_3 = F_20 ( V_6 , V_68 ) ;
if ( ! V_3 )
V_6 -> V_54 = V_68 ;
F_28 ( & V_6 -> V_34 ) ;
return V_3 ;
}
static int F_81 ( struct V_96 * V_10 ,
struct V_81 * V_82 )
{
struct V_83 * V_84 = F_70 ( V_82 ) ;
struct V_5 * V_6 = V_84 -> V_85 . V_86 ;
struct V_31 * V_32 = V_10 -> V_32 ;
int V_104 , V_105 ;
int V_3 ;
if ( V_6 -> V_12 != V_13 ) {
F_8 ( V_6 -> V_15 , L_11 , V_55 ,
V_6 -> V_12 ) ;
return - V_29 ;
}
if ( V_6 -> type == V_106 ) {
V_104 =
F_61 ( V_32 ) / 4 ;
} else {
V_104 = V_32 -> V_59 * V_107 ;
}
if ( V_6 -> V_51 < V_52 ) {
V_105 = V_108 - V_104 ;
} else {
V_105 = V_104 ;
}
if ( ( ! V_105 % 2 ) || ( V_105 != 1 && V_104 % 2 ) ||
( V_105 > F_82 ( V_6 ) ) ) {
F_8 ( V_6 -> V_15 , L_12 ,
V_105 ) ;
return - V_29 ;
}
F_83 ( V_6 , V_105 ) ;
switch ( V_6 -> type ) {
case V_109 :
V_3 = F_31 ( V_6 , V_32 ) ;
break;
case V_110 :
V_3 = F_55 ( V_6 , V_32 ) ;
break;
case V_111 :
V_3 = F_31 ( V_6 , V_32 ) ;
break;
case V_106 :
V_3 = F_59 ( V_6 , V_32 ) ;
break;
default:
F_8 ( V_6 -> V_15 , L_13 ) ;
return - V_29 ;
}
if ( V_3 )
return V_3 ;
switch ( V_6 -> V_62 & V_112 ) {
case V_113 :
F_84 ( V_6 ) ;
F_85 ( V_6 ) ;
break;
case V_114 :
F_86 ( V_6 ) ;
F_85 ( V_6 ) ;
break;
case V_115 :
F_84 ( V_6 ) ;
F_87 ( V_6 ) ;
break;
case V_116 :
F_86 ( V_6 ) ;
F_87 ( V_6 ) ;
break;
}
switch ( V_6 -> V_62 & V_63 ) {
case V_64 :
F_62 ( V_6 ) ;
F_88 ( V_6 ) ;
break;
case V_117 :
F_62 ( V_6 ) ;
F_89 ( V_6 ) ;
break;
case V_118 :
F_90 ( V_6 ) ;
F_89 ( V_6 ) ;
break;
default:
F_8 ( V_6 -> V_15 , L_7 ) ;
return - V_29 ;
}
F_91 ( V_6 , 0 ) ;
return F_92 ( V_6 ) ;
}
static int F_93 ( struct V_5 * V_6 )
{
int V_3 ;
if ( V_6 -> V_12 != V_13 ) {
F_8 ( V_6 -> V_15 , L_14 , V_55 ) ;
return - V_29 ;
}
V_3 = F_94 ( V_6 -> V_30 ) ;
if ( V_3 ) {
F_8 ( V_6 -> V_15 , L_15 , V_55 ) ;
return V_3 ;
}
F_5 ( V_6 , F_4 ( V_6 ) ) ;
F_95 ( V_6 ) ;
F_96 ( V_6 ) ;
if ( V_6 -> V_16 ) {
F_97 ( V_6 ) ;
F_98 ( V_6 ) ;
}
V_3 = F_92 ( V_6 ) ;
if ( V_3 < 0 ) {
F_99 ( V_6 -> V_30 ) ;
return V_3 ;
}
F_100 ( V_6 ) ;
if ( V_6 -> V_51 < V_52 )
if ( F_101 ( V_6 ) )
F_54 ( V_6 ) ;
if ( V_6 -> V_51 < V_52 )
F_29 ( V_6 ) ;
else
F_30 ( V_6 ) ;
V_6 -> V_12 = V_21 ;
return 0 ;
}
static int F_102 ( struct V_5 * V_6 )
{
int V_3 ;
if ( V_6 -> V_12 == V_13 ) {
F_8 ( V_6 -> V_15 , L_14 , V_55 ) ;
return - V_29 ;
}
F_103 ( V_6 ) ;
V_3 = F_92 ( V_6 ) ;
if ( V_3 < 0 )
return V_3 ;
F_104 ( V_6 , F_105 ( V_6 ) ) ;
F_99 ( V_6 -> V_30 ) ;
V_6 -> V_12 = V_13 ;
return 0 ;
}
int F_106 ( struct V_5 * V_6 )
{
int V_3 ;
if ( V_6 -> V_119 ) {
V_3 = F_107 ( V_6 -> V_119 , 1 ) ;
if ( V_3 ) {
F_8 ( V_6 -> V_15 ,
L_16 ,
V_55 ) ;
return V_3 ;
}
}
F_108 ( V_6 ) ;
F_50 ( V_6 ) ;
F_52 ( V_6 ) ;
F_109 ( V_6 ) ;
return 0 ;
}
static int F_110 ( struct V_96 * V_10 ,
int V_120 , struct V_81 * V_82 )
{
struct V_83 * V_84 = F_70 ( V_82 ) ;
struct V_5 * V_6 = V_84 -> V_85 . V_86 ;
switch ( V_120 ) {
case V_121 :
return F_93 ( V_6 ) ;
case V_122 :
return F_102 ( V_6 ) ;
case V_123 :
return F_106 ( V_6 ) ;
default:
return - V_29 ;
}
}
static void F_111 ( struct V_96 * V_10 ,
struct V_81 * V_82 )
{
struct V_83 * V_84 = F_70 ( V_82 ) ;
struct V_5 * V_6 = V_84 -> V_85 . V_86 ;
unsigned long V_89 ;
F_72 ( & V_6 -> V_9 , V_89 ) ;
if ( V_6 -> V_12 != V_13 )
F_102 ( V_6 ) ;
V_6 -> V_10 = NULL ;
F_73 ( & V_6 -> V_9 , V_89 ) ;
}
static int F_112 ( struct V_124 * V_125 ,
struct V_5 * V_6 )
{
struct V_126 * V_127 = V_125 -> V_15 . V_128 ;
struct V_129 * V_129 ;
struct V_130 V_131 [ 2 ] = {
F_113 ( V_132 ,
8 + V_6 -> V_133 ,
8 + V_6 -> V_133 ) ,
F_113 (SYS_CFG_AUDIO_GLUE, 0 , 1 )
} ;
V_129 = F_114 ( V_127 , L_17 ) ;
if ( F_115 ( V_129 ) ) {
F_8 ( & V_125 -> V_15 , L_18 ) ;
return F_116 ( V_129 ) ;
}
V_6 -> V_119 = F_117 ( V_129 , V_131 [ 0 ] ) ;
V_6 -> V_134 = F_117 ( V_129 , V_131 [ 1 ] ) ;
return 0 ;
}
int F_118 ( struct V_124 * V_125 ,
struct V_5 * V_6 )
{
int V_3 = 0 ;
V_6 -> V_15 = & V_125 -> V_15 ;
V_6 -> V_12 = V_13 ;
V_6 -> V_135 = & V_136 ;
V_3 = F_112 ( V_125 , V_6 ) ;
if ( V_3 < 0 ) {
F_8 ( V_6 -> V_15 , L_19 ) ;
return V_3 ;
}
if ( V_6 -> V_51 >= V_52 )
V_6 -> V_16 = 1 ;
if ( F_78 ( V_6 ) )
V_6 -> V_137 = & V_138 ;
else
V_6 -> V_137 = & V_139 ;
V_6 -> V_30 = F_119 ( V_125 -> V_15 . V_128 , 0 ) ;
if ( F_115 ( V_6 -> V_30 ) ) {
F_8 ( V_6 -> V_15 , L_20 ) ;
V_3 = F_116 ( V_6 -> V_30 ) ;
}
if ( V_6 -> V_119 ) {
V_3 = F_107 ( V_6 -> V_119 , 1 ) ;
if ( V_3 ) {
F_8 ( V_6 -> V_15 ,
L_16 ,
V_55 ) ;
return V_3 ;
}
}
if ( V_6 -> V_134 &&
( V_6 -> V_133 == V_140 ) ) {
V_3 = F_107 ( V_6 -> V_134 , V_6 -> V_133 ) ;
if ( V_3 ) {
F_8 ( V_6 -> V_15 ,
L_21 , V_55 ) ;
return V_3 ;
}
}
V_3 = F_120 ( & V_125 -> V_15 , V_6 -> V_1 ,
F_1 , V_141 ,
F_121 ( & V_125 -> V_15 ) , V_6 ) ;
if ( V_3 < 0 ) {
F_8 ( V_6 -> V_15 , L_22 , V_6 -> V_1 ) ;
return V_3 ;
}
F_122 ( & V_6 -> V_34 ) ;
F_123 ( & V_6 -> V_9 ) ;
F_108 ( V_6 ) ;
F_50 ( V_6 ) ;
F_52 ( V_6 ) ;
F_109 ( V_6 ) ;
if ( F_101 ( V_6 ) ) {
V_6 -> V_35 . V_36 . V_7 [ 0 ] = 0x00 ;
V_6 -> V_35 . V_36 . V_7 [ 1 ] =
V_142 ;
V_6 -> V_35 . V_36 . V_7 [ 2 ] =
V_143 ;
V_6 -> V_35 . V_36 . V_7 [ 3 ] =
V_46 ;
V_6 -> V_35 . V_36 . V_7 [ 4 ] =
V_144 |
V_145 ;
V_6 -> V_146 = F_124 ( V_147 ) ;
V_6 -> V_148 = V_147 [ 0 ] ;
} else {
V_6 -> V_146 = F_124 ( V_149 ) ;
V_6 -> V_148 = V_149 [ 0 ] ;
}
return 0 ;
}
