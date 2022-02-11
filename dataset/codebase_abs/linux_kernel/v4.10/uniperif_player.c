static T_1 F_1 ( int V_1 , void * V_2 )
{
T_1 V_3 = V_4 ;
struct V_5 * V_6 = V_2 ;
unsigned int V_7 ;
unsigned int V_8 ;
if ( V_6 -> V_9 == V_10 ) {
return V_4 ;
}
V_7 = F_2 ( V_6 ) ;
F_3 ( V_6 , V_7 ) ;
if ( F_4 ( V_7 & F_5 ( V_6 ) ) ) {
F_6 ( V_6 -> V_11 , L_1 ) ;
if ( V_6 -> V_12 ) {
V_6 -> V_9 = V_13 ;
} else {
F_7 ( V_6 ) ;
F_8 ( V_6 -> V_14 ) ;
F_9 ( V_6 -> V_14 , V_15 ) ;
F_10 ( V_6 -> V_14 ) ;
}
V_3 = V_16 ;
}
if ( F_4 ( V_7 & F_11 ( V_6 ) ) ) {
F_6 ( V_6 -> V_11 , L_2 ) ;
F_12 ( V_6 ) ;
F_8 ( V_6 -> V_14 ) ;
F_9 ( V_6 -> V_14 , V_15 ) ;
F_10 ( V_6 -> V_14 ) ;
V_3 = V_16 ;
}
if ( F_4 ( V_7 & F_13 ( V_6 ) ) ) {
if ( ! V_6 -> V_12 ) {
F_6 ( V_6 -> V_11 ,
L_3 ) ;
return - V_17 ;
}
V_8 = F_14 ( V_6 ) ;
F_15 ( V_6 -> V_11 , L_4 ,
V_8 ) ;
F_16 ( V_6 ) ;
V_6 -> V_9 = V_18 ;
V_3 = V_16 ;
}
if ( F_4 ( V_7 &
F_17 ( V_6 ) ) ) {
F_6 ( V_6 -> V_11 , L_5 ) ;
F_8 ( V_6 -> V_14 ) ;
F_9 ( V_6 -> V_14 , V_15 ) ;
F_10 ( V_6 -> V_14 ) ;
V_3 = V_16 ;
}
return V_3 ;
}
static int F_18 ( struct V_5 * V_6 , unsigned long V_19 )
{
int V_20 , V_21 , V_22 , V_3 ;
int V_23 = V_6 -> V_24 ;
if ( V_23 < 0 ) {
V_22 = - 1 ;
V_23 = - V_23 ;
} else {
V_22 = 1 ;
}
V_22 *= ( int ) F_19 ( ( V_25 ) V_19 *
( V_25 ) V_23 + 500000 , 1000000 ) ;
V_20 = V_19 + V_22 ;
if ( ! V_20 )
return - V_26 ;
V_3 = F_20 ( V_6 -> V_27 , V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
V_21 = F_21 ( V_6 -> V_27 ) ;
if ( ! V_21 )
return - V_26 ;
V_22 = V_21 - V_19 ;
if ( V_22 < 0 ) {
V_22 = - V_22 ;
V_23 = - 1 ;
} else {
V_23 = 1 ;
}
V_23 *= ( int ) F_19 ( ( V_25 ) V_22 * 1000000 + V_19 / 2 ,
V_19 ) ;
V_6 -> V_24 = V_23 ;
return 0 ;
}
static void F_22 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_30 ;
unsigned int V_7 ;
F_23 ( & V_6 -> V_31 ) ;
if ( V_29 ) {
switch ( V_29 -> V_19 ) {
case 22050 :
V_6 -> V_32 . V_33 . V_7 [ 3 ] =
V_34 ;
break;
case 44100 :
V_6 -> V_32 . V_33 . V_7 [ 3 ] =
V_35 ;
break;
case 88200 :
V_6 -> V_32 . V_33 . V_7 [ 3 ] =
V_36 ;
break;
case 176400 :
V_6 -> V_32 . V_33 . V_7 [ 3 ] =
V_37 ;
break;
case 24000 :
V_6 -> V_32 . V_33 . V_7 [ 3 ] =
V_38 ;
break;
case 48000 :
V_6 -> V_32 . V_33 . V_7 [ 3 ] =
V_39 ;
break;
case 96000 :
V_6 -> V_32 . V_33 . V_7 [ 3 ] =
V_40 ;
break;
case 192000 :
V_6 -> V_32 . V_33 . V_7 [ 3 ] =
V_41 ;
break;
case 32000 :
V_6 -> V_32 . V_33 . V_7 [ 3 ] =
V_42 ;
break;
default:
V_6 -> V_32 . V_33 . V_7 [ 3 ] =
V_43 ;
break;
}
}
if ( V_6 -> V_32 . V_33 . V_7 [ 0 ] & V_44 )
V_6 -> V_32 . V_45 =
V_46 ;
else
V_6 -> V_32 . V_45 =
V_47 ;
if ( V_6 -> V_32 . V_45 ==
V_47 )
F_24 ( V_6 , 0 ) ;
else
F_24 ( V_6 , 1 ) ;
for ( V_30 = 0 ; V_30 < 6 ; ++ V_30 ) {
V_7 =
V_6 -> V_32 . V_33 . V_7 [ 0 + ( V_30 * 4 ) ] & 0xf ;
V_7 |=
V_6 -> V_32 . V_33 . V_7 [ 1 + ( V_30 * 4 ) ] << 8 ;
V_7 |=
V_6 -> V_32 . V_33 . V_7 [ 2 + ( V_30 * 4 ) ] << 16 ;
V_7 |=
V_6 -> V_32 . V_33 . V_7 [ 3 + ( V_30 * 4 ) ] << 24 ;
F_25 ( V_6 , V_30 , V_7 ) ;
}
F_26 ( & V_6 -> V_31 ) ;
if ( V_6 -> V_48 < V_49 )
F_27 ( V_6 ) ;
else
F_28 ( V_6 ) ;
}
static int F_29 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_50 ;
V_50 = V_6 -> V_51 / V_29 -> V_19 ;
if ( ( V_50 % 128 ) || ( V_50 <= 0 ) ) {
F_6 ( V_6 -> V_11 , L_6 ,
V_52 , V_50 ) ;
return - V_26 ;
}
switch ( V_29 -> V_53 ) {
case V_54 :
F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
break;
case V_55 :
F_33 ( V_6 ) ;
F_31 ( V_6 ) ;
F_34 ( V_6 ) ;
break;
default:
F_6 ( V_6 -> V_11 , L_7 ) ;
return - V_26 ;
}
F_35 ( V_6 ) ;
F_36 ( V_6 ) ;
F_37 ( V_6 ) ;
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
F_40 ( V_6 ) ;
F_22 ( V_6 , V_29 ) ;
F_24 ( V_6 , 0 ) ;
F_41 ( V_6 ) ;
F_42 ( V_6 ) ;
F_43 ( V_6 ) ;
F_44 ( V_6 ) ;
if ( V_6 -> V_32 . V_45 ==
V_46 )
F_45 ( V_6 ) ;
else
F_46 ( V_6 ) ;
F_47 ( V_6 , V_29 -> V_56 / 2 ) ;
F_48 ( V_6 ) ;
F_49 ( V_6 , V_50 / 128 ) ;
F_50 ( V_6 ) ;
if ( V_6 -> V_48 < V_49 )
F_51 ( V_6 ) ;
else
F_52 ( V_6 ) ;
return 0 ;
}
static int F_53 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_57 , V_58 , V_50 ;
if ( ( V_6 -> V_59 & V_60 ) ==
V_61 )
V_58 = 32 ;
else
V_58 = F_54 ( V_29 -> V_53 ) ;
V_57 = V_58 * V_29 -> V_56 ;
V_50 = V_6 -> V_51 / V_29 -> V_19 ;
if ( ( V_58 == 32 ) && ( V_50 % 128 ) ) {
F_6 ( V_6 -> V_11 , L_8 , V_52 ) ;
return - V_26 ;
}
if ( ( V_58 == 16 ) && ( V_50 % 64 ) ) {
F_6 ( V_6 -> V_11 , L_8 , V_52 ) ;
return - V_26 ;
}
switch ( V_58 ) {
case 32 :
F_31 ( V_6 ) ;
F_55 ( V_6 ) ;
break;
case 16 :
F_56 ( V_6 ) ;
F_32 ( V_6 ) ;
break;
default:
F_6 ( V_6 -> V_11 , L_9 ) ;
return - V_26 ;
}
switch ( V_29 -> V_53 ) {
case V_54 :
F_30 ( V_6 ) ;
break;
case V_55 :
F_33 ( V_6 ) ;
break;
default:
F_6 ( V_6 -> V_11 , L_7 ) ;
return - V_26 ;
}
F_48 ( V_6 ) ;
F_49 ( V_6 , V_50 / ( 2 * V_57 ) ) ;
if ( ( V_29 -> V_56 % 2 ) || ( V_29 -> V_56 < 2 ) ||
( V_29 -> V_56 > 10 ) ) {
F_6 ( V_6 -> V_11 , L_10 , V_52 ) ;
return - V_26 ;
}
F_47 ( V_6 , V_29 -> V_56 / 2 ) ;
F_41 ( V_6 ) ;
F_44 ( V_6 ) ;
F_51 ( V_6 ) ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
int V_62 ;
int V_63 ;
unsigned int V_64 [ 4 ] = {
0x04060002 , 0x0C0E080A , 0x14161012 , 0x1C1E181A } ;
int V_65 , V_3 ;
V_62 =
F_58 ( V_6 ) ;
V_63 =
F_59 ( V_29 ) ;
F_33 ( V_6 ) ;
F_55 ( V_6 ) ;
F_47 ( V_6 , V_63 / 4 / 2 ) ;
F_44 ( V_6 ) ;
F_60 ( V_6 ) ;
F_61 ( V_6 ) ;
F_62 ( V_6 , V_62 ) ;
F_63 ( V_6 , V_64 ) ;
F_64 ( V_6 , 1_2 , V_64 [ V_66 ] ) ;
F_64 ( V_6 , 3_4 , V_64 [ V_67 ] ) ;
F_64 ( V_6 , 5_6 , V_64 [ V_68 ] ) ;
F_64 ( V_6 , 7_8 , V_64 [ V_69 ] ) ;
V_65 = V_29 -> V_19 * V_62 * 8 ;
F_23 ( & V_6 -> V_31 ) ;
V_3 = F_18 ( V_6 , V_65 ) ;
if ( ! V_3 )
V_6 -> V_51 = V_65 ;
F_26 ( & V_6 -> V_31 ) ;
return 0 ;
}
static int F_65 ( struct V_70 * V_71 ,
struct V_72 * V_73 )
{
V_73 -> type = V_74 ;
V_73 -> V_75 = 1 ;
return 0 ;
}
static int F_66 ( struct V_70 * V_71 ,
struct V_76 * V_77 )
{
struct V_78 * V_79 = F_67 ( V_71 ) ;
struct V_80 * V_81 = F_68 ( V_79 ) ;
struct V_5 * V_6 = V_81 -> V_82 . V_83 ;
struct V_84 * V_33 = & V_6 -> V_32 . V_33 ;
F_23 ( & V_6 -> V_31 ) ;
V_77 -> V_85 . V_33 . V_7 [ 0 ] = V_33 -> V_7 [ 0 ] ;
V_77 -> V_85 . V_33 . V_7 [ 1 ] = V_33 -> V_7 [ 1 ] ;
V_77 -> V_85 . V_33 . V_7 [ 2 ] = V_33 -> V_7 [ 2 ] ;
V_77 -> V_85 . V_33 . V_7 [ 3 ] = V_33 -> V_7 [ 3 ] ;
F_26 ( & V_6 -> V_31 ) ;
return 0 ;
}
static int F_69 ( struct V_70 * V_71 ,
struct V_76 * V_77 )
{
struct V_78 * V_79 = F_67 ( V_71 ) ;
struct V_80 * V_81 = F_68 ( V_79 ) ;
struct V_5 * V_6 = V_81 -> V_82 . V_83 ;
struct V_84 * V_33 = & V_6 -> V_32 . V_33 ;
F_23 ( & V_6 -> V_31 ) ;
V_33 -> V_7 [ 0 ] = V_77 -> V_85 . V_33 . V_7 [ 0 ] ;
V_33 -> V_7 [ 1 ] = V_77 -> V_85 . V_33 . V_7 [ 1 ] ;
V_33 -> V_7 [ 2 ] = V_77 -> V_85 . V_33 . V_7 [ 2 ] ;
V_33 -> V_7 [ 3 ] = V_77 -> V_85 . V_33 . V_7 [ 3 ] ;
F_26 ( & V_6 -> V_31 ) ;
if ( V_6 -> V_14 && V_6 -> V_14 -> V_29 )
F_22 ( V_6 ,
V_6 -> V_14 -> V_29 ) ;
else
F_22 ( V_6 , NULL ) ;
return 0 ;
}
static int F_70 ( struct V_70 * V_71 ,
struct V_72 * V_73 )
{
V_73 -> type = V_86 ;
V_73 -> V_75 = 1 ;
V_73 -> V_85 . integer . V_87 = V_88 ;
V_73 -> V_85 . integer . V_89 = V_90 ;
V_73 -> V_85 . integer . V_91 = 1 ;
return 0 ;
}
static int F_71 ( struct V_70 * V_71 ,
struct V_76 * V_77 )
{
struct V_78 * V_79 = F_67 ( V_71 ) ;
struct V_80 * V_81 = F_68 ( V_79 ) ;
struct V_5 * V_6 = V_81 -> V_82 . V_83 ;
F_23 ( & V_6 -> V_31 ) ;
V_77 -> V_85 . integer . V_85 [ 0 ] = V_6 -> V_24 ;
F_26 ( & V_6 -> V_31 ) ;
return 0 ;
}
static int F_72 ( struct V_70 * V_71 ,
struct V_76 * V_77 )
{
struct V_78 * V_79 = F_67 ( V_71 ) ;
struct V_80 * V_81 = F_68 ( V_79 ) ;
struct V_5 * V_6 = V_81 -> V_82 . V_83 ;
int V_3 = 0 ;
if ( ( V_77 -> V_85 . integer . V_85 [ 0 ] < V_88 ) ||
( V_77 -> V_85 . integer . V_85 [ 0 ] > V_90 ) )
return - V_26 ;
F_23 ( & V_6 -> V_31 ) ;
V_6 -> V_24 = V_77 -> V_85 . integer . V_85 [ 0 ] ;
if ( V_6 -> V_51 )
V_3 = F_18 ( V_6 , V_6 -> V_51 ) ;
F_26 ( & V_6 -> V_31 ) ;
return V_3 ;
}
static int F_73 ( struct V_92 * V_14 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = F_68 ( V_79 ) ;
struct V_5 * V_6 = V_81 -> V_82 . V_83 ;
int V_3 ;
V_6 -> V_14 = V_14 ;
V_6 -> V_24 = 0 ;
if ( ! F_74 ( V_6 ) )
return 0 ;
V_3 = F_75 ( V_14 -> V_29 , 0 ,
V_93 ,
V_94 ,
V_6 , V_93 ,
- 1 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_75 ( V_14 -> V_29 , 0 ,
V_95 ,
V_96 ,
V_6 , V_95 ,
- 1 ) ;
}
static int F_76 ( struct V_78 * V_79 , int V_97 ,
unsigned int V_65 , int V_98 )
{
struct V_80 * V_81 = F_68 ( V_79 ) ;
struct V_5 * V_6 = V_81 -> V_82 . V_83 ;
int V_3 ;
if ( F_74 ( V_6 ) || ( V_98 == V_99 ) )
return 0 ;
if ( V_97 != 0 )
return - V_26 ;
F_23 ( & V_6 -> V_31 ) ;
V_3 = F_18 ( V_6 , V_65 ) ;
if ( ! V_3 )
V_6 -> V_51 = V_65 ;
F_26 ( & V_6 -> V_31 ) ;
return V_3 ;
}
static int F_77 ( struct V_92 * V_14 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = F_68 ( V_79 ) ;
struct V_5 * V_6 = V_81 -> V_82 . V_83 ;
struct V_28 * V_29 = V_14 -> V_29 ;
int V_100 , V_101 ;
int V_3 ;
if ( V_6 -> V_9 != V_10 ) {
F_6 ( V_6 -> V_11 , L_11 , V_52 ,
V_6 -> V_9 ) ;
return - V_26 ;
}
if ( V_6 -> type == V_102 ) {
V_100 =
F_59 ( V_29 ) / 4 ;
} else {
V_100 = V_29 -> V_56 * V_103 ;
}
if ( V_6 -> V_48 < V_49 ) {
V_101 = V_104 - V_100 ;
} else {
V_101 = V_100 ;
}
if ( ( ! V_101 % 2 ) || ( V_101 != 1 && V_100 % 2 ) ||
( V_101 > F_78 ( V_6 ) ) ) {
F_6 ( V_6 -> V_11 , L_12 ,
V_101 ) ;
return - V_26 ;
}
F_79 ( V_6 , V_101 ) ;
switch ( V_6 -> type ) {
case V_105 :
V_3 = F_29 ( V_6 , V_29 ) ;
break;
case V_106 :
V_3 = F_53 ( V_6 , V_29 ) ;
break;
case V_107 :
V_3 = F_29 ( V_6 , V_29 ) ;
break;
case V_102 :
V_3 = F_57 ( V_6 , V_29 ) ;
break;
default:
F_6 ( V_6 -> V_11 , L_13 ) ;
return - V_26 ;
}
if ( V_3 )
return V_3 ;
switch ( V_6 -> V_59 & V_108 ) {
case V_109 :
F_80 ( V_6 ) ;
F_81 ( V_6 ) ;
break;
case V_110 :
F_82 ( V_6 ) ;
F_81 ( V_6 ) ;
break;
case V_111 :
F_80 ( V_6 ) ;
F_83 ( V_6 ) ;
break;
case V_112 :
F_82 ( V_6 ) ;
F_83 ( V_6 ) ;
break;
}
switch ( V_6 -> V_59 & V_60 ) {
case V_61 :
F_60 ( V_6 ) ;
F_84 ( V_6 ) ;
break;
case V_113 :
F_60 ( V_6 ) ;
F_85 ( V_6 ) ;
break;
case V_114 :
F_86 ( V_6 ) ;
F_85 ( V_6 ) ;
break;
default:
F_6 ( V_6 -> V_11 , L_7 ) ;
return - V_26 ;
}
F_87 ( V_6 , 0 ) ;
return F_88 ( V_6 ) ;
}
static int F_89 ( struct V_5 * V_6 )
{
int V_3 ;
if ( V_6 -> V_9 != V_10 ) {
F_6 ( V_6 -> V_11 , L_14 , V_52 ) ;
return - V_26 ;
}
V_3 = F_90 ( V_6 -> V_27 ) ;
if ( V_3 ) {
F_6 ( V_6 -> V_11 , L_15 , V_52 ) ;
return V_3 ;
}
F_3 ( V_6 , F_2 ( V_6 ) ) ;
F_91 ( V_6 ) ;
F_92 ( V_6 ) ;
if ( V_6 -> V_12 ) {
F_93 ( V_6 ) ;
F_94 ( V_6 ) ;
}
V_3 = F_88 ( V_6 ) ;
if ( V_3 < 0 ) {
F_95 ( V_6 -> V_27 ) ;
return V_3 ;
}
F_96 ( V_6 ) ;
if ( V_6 -> V_48 < V_49 )
if ( F_97 ( V_6 ) )
F_52 ( V_6 ) ;
if ( V_6 -> V_48 < V_49 )
F_27 ( V_6 ) ;
else
F_28 ( V_6 ) ;
V_6 -> V_9 = V_18 ;
return 0 ;
}
static int F_98 ( struct V_5 * V_6 )
{
int V_3 ;
if ( V_6 -> V_9 == V_10 ) {
F_6 ( V_6 -> V_11 , L_14 , V_52 ) ;
return - V_26 ;
}
F_99 ( V_6 ) ;
V_3 = F_88 ( V_6 ) ;
if ( V_3 < 0 )
return V_3 ;
F_100 ( V_6 , F_101 ( V_6 ) ) ;
F_95 ( V_6 -> V_27 ) ;
V_6 -> V_9 = V_10 ;
return 0 ;
}
int F_102 ( struct V_5 * V_6 )
{
int V_3 ;
if ( V_6 -> V_115 ) {
V_3 = F_103 ( V_6 -> V_115 , 1 ) ;
if ( V_3 ) {
F_6 ( V_6 -> V_11 ,
L_16 ,
V_52 ) ;
return V_3 ;
}
}
F_104 ( V_6 ) ;
F_48 ( V_6 ) ;
F_50 ( V_6 ) ;
F_105 ( V_6 ) ;
return 0 ;
}
static int F_106 ( struct V_92 * V_14 ,
int V_116 , struct V_78 * V_79 )
{
struct V_80 * V_81 = F_68 ( V_79 ) ;
struct V_5 * V_6 = V_81 -> V_82 . V_83 ;
switch ( V_116 ) {
case V_117 :
return F_89 ( V_6 ) ;
case V_118 :
return F_98 ( V_6 ) ;
case V_119 :
return F_102 ( V_6 ) ;
default:
return - V_26 ;
}
}
static void F_107 ( struct V_92 * V_14 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = F_68 ( V_79 ) ;
struct V_5 * V_6 = V_81 -> V_82 . V_83 ;
if ( V_6 -> V_9 != V_10 )
F_98 ( V_6 ) ;
V_6 -> V_14 = NULL ;
}
static int F_108 ( struct V_120 * V_121 ,
struct V_5 * V_6 )
{
struct V_122 * V_123 = V_121 -> V_11 . V_124 ;
struct V_125 * V_125 ;
struct V_126 V_127 [ 2 ] = {
F_109 ( V_128 ,
8 + V_6 -> V_129 ,
8 + V_6 -> V_129 ) ,
F_109 (SYS_CFG_AUDIO_GLUE, 0 , 1 )
} ;
V_125 = F_110 ( V_123 , L_17 ) ;
if ( F_111 ( V_125 ) ) {
F_6 ( & V_121 -> V_11 , L_18 ) ;
return F_112 ( V_125 ) ;
}
V_6 -> V_115 = F_113 ( V_125 , V_127 [ 0 ] ) ;
V_6 -> V_130 = F_113 ( V_125 , V_127 [ 1 ] ) ;
return 0 ;
}
int F_114 ( struct V_120 * V_121 ,
struct V_5 * V_6 )
{
int V_3 = 0 ;
V_6 -> V_11 = & V_121 -> V_11 ;
V_6 -> V_9 = V_10 ;
V_6 -> V_131 = & V_132 ;
V_3 = F_108 ( V_121 , V_6 ) ;
if ( V_3 < 0 ) {
F_6 ( V_6 -> V_11 , L_19 ) ;
return V_3 ;
}
if ( V_6 -> V_48 >= V_49 )
V_6 -> V_12 = 1 ;
if ( F_74 ( V_6 ) )
V_6 -> V_133 = & V_134 ;
else
V_6 -> V_133 = & V_135 ;
V_6 -> V_27 = F_115 ( V_121 -> V_11 . V_124 , 0 ) ;
if ( F_111 ( V_6 -> V_27 ) ) {
F_6 ( V_6 -> V_11 , L_20 ) ;
V_3 = F_112 ( V_6 -> V_27 ) ;
}
if ( V_6 -> V_115 ) {
V_3 = F_103 ( V_6 -> V_115 , 1 ) ;
if ( V_3 ) {
F_6 ( V_6 -> V_11 ,
L_16 ,
V_52 ) ;
return V_3 ;
}
}
if ( V_6 -> V_130 &&
( V_6 -> V_129 == V_136 ) ) {
V_3 = F_103 ( V_6 -> V_130 , V_6 -> V_129 ) ;
if ( V_3 ) {
F_6 ( V_6 -> V_11 ,
L_21 , V_52 ) ;
return V_3 ;
}
}
V_3 = F_116 ( & V_121 -> V_11 , V_6 -> V_1 ,
F_1 , V_137 ,
F_117 ( & V_121 -> V_11 ) , V_6 ) ;
if ( V_3 < 0 ) {
F_6 ( V_6 -> V_11 , L_22 , V_6 -> V_1 ) ;
return V_3 ;
}
F_118 ( & V_6 -> V_31 ) ;
F_104 ( V_6 ) ;
F_48 ( V_6 ) ;
F_50 ( V_6 ) ;
F_105 ( V_6 ) ;
if ( F_97 ( V_6 ) ) {
V_6 -> V_32 . V_33 . V_7 [ 0 ] = 0x00 ;
V_6 -> V_32 . V_33 . V_7 [ 1 ] =
V_138 ;
V_6 -> V_32 . V_33 . V_7 [ 2 ] =
V_139 ;
V_6 -> V_32 . V_33 . V_7 [ 3 ] =
V_43 ;
V_6 -> V_32 . V_33 . V_7 [ 4 ] =
V_140 |
V_141 ;
V_6 -> V_142 = F_119 ( V_143 ) ;
V_6 -> V_144 = V_143 [ 0 ] ;
} else {
V_6 -> V_142 = F_119 ( V_145 ) ;
V_6 -> V_144 = V_145 [ 0 ] ;
}
return 0 ;
}
