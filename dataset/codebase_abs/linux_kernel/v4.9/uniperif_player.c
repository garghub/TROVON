static inline int F_1 ( struct V_1 * V_2 )
{
int V_3 = 10 ;
if ( V_2 -> V_4 < V_5 ) {
while ( F_2 ( V_2 ) && V_3 ) {
F_3 ( 5 ) ;
V_3 -- ;
}
}
if ( ! V_3 ) {
F_4 ( V_2 -> V_6 , L_1 ) ;
return - V_7 ;
}
return 0 ;
}
static T_1 F_5 ( int V_8 , void * V_9 )
{
T_1 V_10 = V_11 ;
struct V_1 * V_2 = V_9 ;
unsigned int V_12 ;
unsigned int V_13 ;
if ( V_2 -> V_14 == V_15 ) {
return V_11 ;
}
V_12 = F_6 ( V_2 ) ;
F_7 ( V_2 , V_12 ) ;
if ( F_8 ( V_12 & F_9 ( V_2 ) ) ) {
F_4 ( V_2 -> V_6 , L_2 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_14 = V_17 ;
} else {
F_10 ( V_2 ) ;
F_11 ( V_2 -> V_18 ) ;
F_12 ( V_2 -> V_18 , V_19 ) ;
F_13 ( V_2 -> V_18 ) ;
}
V_10 = V_20 ;
}
if ( F_8 ( V_12 & F_14 ( V_2 ) ) ) {
F_4 ( V_2 -> V_6 , L_3 ) ;
F_15 ( V_2 ) ;
F_11 ( V_2 -> V_18 ) ;
F_12 ( V_2 -> V_18 , V_19 ) ;
F_13 ( V_2 -> V_18 ) ;
V_10 = V_20 ;
}
if ( F_8 ( V_12 & F_16 ( V_2 ) ) ) {
if ( ! V_2 -> V_16 ) {
F_4 ( V_2 -> V_6 , L_4 ) ;
return - V_21 ;
}
V_13 = F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
V_2 -> V_14 = V_22 ;
V_10 = V_20 ;
}
if ( F_8 ( V_12 &
F_19 ( V_2 ) ) ) {
F_4 ( V_2 -> V_6 , L_5 ) ;
F_11 ( V_2 -> V_18 ) ;
F_12 ( V_2 -> V_18 , V_19 ) ;
F_13 ( V_2 -> V_18 ) ;
V_10 = V_20 ;
}
return V_10 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned long V_23 )
{
int V_24 , V_25 , V_26 , V_10 ;
int V_27 = V_2 -> V_28 ;
if ( V_27 < 0 ) {
V_26 = - 1 ;
V_27 = - V_27 ;
} else {
V_26 = 1 ;
}
V_26 *= ( int ) F_21 ( ( V_29 ) V_23 *
( V_29 ) V_27 + 500000 , 1000000 ) ;
V_24 = V_23 + V_26 ;
if ( ! V_24 )
return - V_30 ;
V_10 = F_22 ( V_2 -> V_31 , V_24 ) ;
if ( V_10 < 0 )
return V_10 ;
V_25 = F_23 ( V_2 -> V_31 ) ;
if ( ! V_25 )
return - V_30 ;
V_26 = V_25 - V_23 ;
if ( V_26 < 0 ) {
V_26 = - V_26 ;
V_27 = - 1 ;
} else {
V_27 = 1 ;
}
V_27 *= ( int ) F_21 ( ( V_29 ) V_26 * 1000000 + V_23 / 2 ,
V_23 ) ;
V_2 -> V_28 = V_27 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
int V_34 ;
unsigned int V_12 ;
F_25 ( & V_2 -> V_35 ) ;
if ( V_33 ) {
switch ( V_33 -> V_23 ) {
case 22050 :
V_2 -> V_36 . V_37 . V_12 [ 3 ] =
V_38 ;
break;
case 44100 :
V_2 -> V_36 . V_37 . V_12 [ 3 ] =
V_39 ;
break;
case 88200 :
V_2 -> V_36 . V_37 . V_12 [ 3 ] =
V_40 ;
break;
case 176400 :
V_2 -> V_36 . V_37 . V_12 [ 3 ] =
V_41 ;
break;
case 24000 :
V_2 -> V_36 . V_37 . V_12 [ 3 ] =
V_42 ;
break;
case 48000 :
V_2 -> V_36 . V_37 . V_12 [ 3 ] =
V_43 ;
break;
case 96000 :
V_2 -> V_36 . V_37 . V_12 [ 3 ] =
V_44 ;
break;
case 192000 :
V_2 -> V_36 . V_37 . V_12 [ 3 ] =
V_45 ;
break;
case 32000 :
V_2 -> V_36 . V_37 . V_12 [ 3 ] =
V_46 ;
break;
default:
V_2 -> V_36 . V_37 . V_12 [ 3 ] =
V_47 ;
break;
}
}
if ( V_2 -> V_36 . V_37 . V_12 [ 0 ] & V_48 )
V_2 -> V_36 . V_49 =
V_50 ;
else
V_2 -> V_36 . V_49 =
V_51 ;
if ( V_2 -> V_36 . V_49 ==
V_51 )
F_26 ( V_2 , 0 ) ;
else
F_26 ( V_2 , 1 ) ;
for ( V_34 = 0 ; V_34 < 6 ; ++ V_34 ) {
V_12 =
V_2 -> V_36 . V_37 . V_12 [ 0 + ( V_34 * 4 ) ] & 0xf ;
V_12 |=
V_2 -> V_36 . V_37 . V_12 [ 1 + ( V_34 * 4 ) ] << 8 ;
V_12 |=
V_2 -> V_36 . V_37 . V_12 [ 2 + ( V_34 * 4 ) ] << 16 ;
V_12 |=
V_2 -> V_36 . V_37 . V_12 [ 3 + ( V_34 * 4 ) ] << 24 ;
F_27 ( V_2 , V_34 , V_12 ) ;
}
F_28 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_4 < V_5 )
F_29 ( V_2 ) ;
else
F_30 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
int V_52 ;
V_52 = V_2 -> V_53 / V_33 -> V_23 ;
if ( ( V_52 % 128 ) || ( V_52 <= 0 ) ) {
F_4 ( V_2 -> V_6 , L_6 ,
V_54 , V_52 ) ;
return - V_30 ;
}
switch ( V_33 -> V_55 ) {
case V_56 :
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
break;
case V_57 :
F_35 ( V_2 ) ;
F_33 ( V_2 ) ;
F_36 ( V_2 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_7 ) ;
return - V_30 ;
}
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_24 ( V_2 , V_33 ) ;
F_26 ( V_2 , 0 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( V_2 -> V_36 . V_49 ==
V_50 )
F_47 ( V_2 ) ;
else
F_48 ( V_2 ) ;
F_49 ( V_2 , V_33 -> V_58 / 2 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 , V_52 / 128 ) ;
F_52 ( V_2 ) ;
if ( V_2 -> V_4 < V_5 )
F_53 ( V_2 ) ;
else
F_54 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
int V_59 , V_60 , V_52 ;
if ( ( V_2 -> V_61 & V_62 ) ==
V_63 )
V_60 = 32 ;
else
V_60 = F_56 ( V_33 -> V_55 ) ;
V_59 = V_60 * V_33 -> V_58 ;
V_52 = V_2 -> V_53 / V_33 -> V_23 ;
if ( ( V_60 == 32 ) && ( V_52 % 128 ) ) {
F_4 ( V_2 -> V_6 , L_8 , V_54 ) ;
return - V_30 ;
}
if ( ( V_60 == 16 ) && ( V_52 % 64 ) ) {
F_4 ( V_2 -> V_6 , L_8 , V_54 ) ;
return - V_30 ;
}
switch ( V_60 ) {
case 32 :
F_33 ( V_2 ) ;
F_57 ( V_2 ) ;
break;
case 16 :
F_58 ( V_2 ) ;
F_34 ( V_2 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_9 ) ;
return - V_30 ;
}
switch ( V_33 -> V_55 ) {
case V_56 :
F_32 ( V_2 ) ;
break;
case V_57 :
F_35 ( V_2 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_7 ) ;
return - V_30 ;
}
F_50 ( V_2 ) ;
F_51 ( V_2 , V_52 / ( 2 * V_59 ) ) ;
if ( ( V_33 -> V_58 % 2 ) || ( V_33 -> V_58 < 2 ) ||
( V_33 -> V_58 > 10 ) ) {
F_4 ( V_2 -> V_6 , L_10 , V_54 ) ;
return - V_30 ;
}
F_49 ( V_2 , V_33 -> V_58 / 2 ) ;
F_43 ( V_2 ) ;
F_46 ( V_2 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
int V_64 ;
int V_65 ;
unsigned int V_66 [ 4 ] = {
0x04060002 , 0x0C0E080A , 0x14161012 , 0x1C1E181A } ;
int V_67 , V_10 ;
V_64 =
F_60 ( V_2 ) ;
V_65 =
F_61 ( V_33 ) ;
F_35 ( V_2 ) ;
F_57 ( V_2 ) ;
F_49 ( V_2 , V_65 / 4 / 2 ) ;
F_46 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 , V_64 ) ;
F_65 ( V_2 , V_66 ) ;
F_66 ( V_2 , 1_2 , V_66 [ V_68 ] ) ;
F_66 ( V_2 , 3_4 , V_66 [ V_69 ] ) ;
F_66 ( V_2 , 5_6 , V_66 [ V_70 ] ) ;
F_66 ( V_2 , 7_8 , V_66 [ V_71 ] ) ;
V_67 = V_33 -> V_23 * V_64 * 8 ;
F_25 ( & V_2 -> V_35 ) ;
V_10 = F_20 ( V_2 , V_67 ) ;
if ( ! V_10 )
V_2 -> V_53 = V_67 ;
F_28 ( & V_2 -> V_35 ) ;
return 0 ;
}
static int F_67 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
V_75 -> type = V_76 ;
V_75 -> V_3 = 1 ;
return 0 ;
}
static int F_68 ( struct V_72 * V_73 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = F_69 ( V_73 ) ;
struct V_81 * V_82 = F_70 ( V_80 ) ;
struct V_1 * V_2 = V_82 -> V_83 . V_84 ;
struct V_85 * V_37 = & V_2 -> V_36 . V_37 ;
F_25 ( & V_2 -> V_35 ) ;
V_78 -> V_86 . V_37 . V_12 [ 0 ] = V_37 -> V_12 [ 0 ] ;
V_78 -> V_86 . V_37 . V_12 [ 1 ] = V_37 -> V_12 [ 1 ] ;
V_78 -> V_86 . V_37 . V_12 [ 2 ] = V_37 -> V_12 [ 2 ] ;
V_78 -> V_86 . V_37 . V_12 [ 3 ] = V_37 -> V_12 [ 3 ] ;
F_28 ( & V_2 -> V_35 ) ;
return 0 ;
}
static int F_71 ( struct V_72 * V_73 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = F_69 ( V_73 ) ;
struct V_81 * V_82 = F_70 ( V_80 ) ;
struct V_1 * V_2 = V_82 -> V_83 . V_84 ;
struct V_85 * V_37 = & V_2 -> V_36 . V_37 ;
F_25 ( & V_2 -> V_35 ) ;
V_37 -> V_12 [ 0 ] = V_78 -> V_86 . V_37 . V_12 [ 0 ] ;
V_37 -> V_12 [ 1 ] = V_78 -> V_86 . V_37 . V_12 [ 1 ] ;
V_37 -> V_12 [ 2 ] = V_78 -> V_86 . V_37 . V_12 [ 2 ] ;
V_37 -> V_12 [ 3 ] = V_78 -> V_86 . V_37 . V_12 [ 3 ] ;
F_28 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_18 && V_2 -> V_18 -> V_33 )
F_24 ( V_2 ,
V_2 -> V_18 -> V_33 ) ;
else
F_24 ( V_2 , NULL ) ;
return 0 ;
}
static int F_72 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
V_75 -> type = V_87 ;
V_75 -> V_3 = 1 ;
V_75 -> V_86 . integer . V_88 = V_89 ;
V_75 -> V_86 . integer . V_90 = V_91 ;
V_75 -> V_86 . integer . V_92 = 1 ;
return 0 ;
}
static int F_73 ( struct V_72 * V_73 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = F_69 ( V_73 ) ;
struct V_81 * V_82 = F_70 ( V_80 ) ;
struct V_1 * V_2 = V_82 -> V_83 . V_84 ;
F_25 ( & V_2 -> V_35 ) ;
V_78 -> V_86 . integer . V_86 [ 0 ] = V_2 -> V_28 ;
F_28 ( & V_2 -> V_35 ) ;
return 0 ;
}
static int F_74 ( struct V_72 * V_73 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = F_69 ( V_73 ) ;
struct V_81 * V_82 = F_70 ( V_80 ) ;
struct V_1 * V_2 = V_82 -> V_83 . V_84 ;
int V_10 = 0 ;
if ( ( V_78 -> V_86 . integer . V_86 [ 0 ] < V_89 ) ||
( V_78 -> V_86 . integer . V_86 [ 0 ] > V_91 ) )
return - V_30 ;
F_25 ( & V_2 -> V_35 ) ;
V_2 -> V_28 = V_78 -> V_86 . integer . V_86 [ 0 ] ;
if ( V_2 -> V_53 )
V_10 = F_20 ( V_2 , V_2 -> V_53 ) ;
F_28 ( & V_2 -> V_35 ) ;
return V_10 ;
}
static int F_75 ( struct V_93 * V_18 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = F_70 ( V_80 ) ;
struct V_1 * V_2 = V_82 -> V_83 . V_84 ;
int V_10 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_28 = 0 ;
if ( ! F_76 ( V_2 ) )
return 0 ;
V_10 = F_77 ( V_18 -> V_33 , 0 ,
V_94 ,
V_95 ,
V_2 , V_94 ,
- 1 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_77 ( V_18 -> V_33 , 0 ,
V_96 ,
V_97 ,
V_2 , V_96 ,
- 1 ) ;
}
static int F_78 ( struct V_79 * V_80 , int V_98 ,
unsigned int V_67 , int V_99 )
{
struct V_81 * V_82 = F_70 ( V_80 ) ;
struct V_1 * V_2 = V_82 -> V_83 . V_84 ;
int V_10 ;
if ( F_76 ( V_2 ) || ( V_99 == V_100 ) )
return 0 ;
if ( V_98 != 0 )
return - V_30 ;
F_25 ( & V_2 -> V_35 ) ;
V_10 = F_20 ( V_2 , V_67 ) ;
if ( ! V_10 )
V_2 -> V_53 = V_67 ;
F_28 ( & V_2 -> V_35 ) ;
return V_10 ;
}
static int F_79 ( struct V_93 * V_18 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = F_70 ( V_80 ) ;
struct V_1 * V_2 = V_82 -> V_83 . V_84 ;
struct V_32 * V_33 = V_18 -> V_33 ;
int V_101 , V_102 ;
int V_10 ;
if ( V_2 -> V_14 != V_15 ) {
F_4 ( V_2 -> V_6 , L_11 , V_54 ,
V_2 -> V_14 ) ;
return - V_30 ;
}
if ( V_2 -> type == V_103 ) {
V_101 =
F_61 ( V_33 ) / 4 ;
} else {
V_101 = V_33 -> V_58 * V_104 ;
}
if ( V_2 -> V_4 < V_5 ) {
V_102 = V_105 - V_101 ;
} else {
V_102 = V_101 ;
}
if ( ( ! V_102 % 2 ) || ( V_102 != 1 && V_101 % 2 ) ||
( V_102 > F_80 ( V_2 ) ) ) {
F_4 ( V_2 -> V_6 , L_12 , V_102 ) ;
return - V_30 ;
}
F_81 ( V_2 , V_102 ) ;
switch ( V_2 -> type ) {
case V_106 :
V_10 = F_31 ( V_2 , V_33 ) ;
break;
case V_107 :
V_10 = F_55 ( V_2 , V_33 ) ;
break;
case V_108 :
V_10 = F_31 ( V_2 , V_33 ) ;
break;
case V_103 :
V_10 = F_59 ( V_2 , V_33 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_13 ) ;
return - V_30 ;
}
if ( V_10 )
return V_10 ;
switch ( V_2 -> V_61 & V_109 ) {
case V_110 :
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
break;
case V_111 :
F_84 ( V_2 ) ;
F_83 ( V_2 ) ;
break;
case V_112 :
F_82 ( V_2 ) ;
F_85 ( V_2 ) ;
break;
case V_113 :
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
break;
}
switch ( V_2 -> V_61 & V_62 ) {
case V_63 :
F_62 ( V_2 ) ;
F_86 ( V_2 ) ;
break;
case V_114 :
F_62 ( V_2 ) ;
F_87 ( V_2 ) ;
break;
case V_115 :
F_88 ( V_2 ) ;
F_87 ( V_2 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_7 ) ;
return - V_30 ;
}
F_89 ( V_2 , 0 ) ;
F_90 ( V_2 ) ;
return F_1 ( V_2 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_14 != V_15 ) {
F_4 ( V_2 -> V_6 , L_14 , V_54 ) ;
return - V_30 ;
}
V_10 = F_92 ( V_2 -> V_31 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 , L_15 , V_54 ) ;
return V_10 ;
}
F_7 ( V_2 , F_6 ( V_2 ) ) ;
F_93 ( V_2 ) ;
F_94 ( V_2 ) ;
if ( V_2 -> V_16 ) {
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
}
F_90 ( V_2 ) ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 ) {
F_97 ( V_2 -> V_31 ) ;
return V_10 ;
}
F_98 ( V_2 ) ;
if ( V_2 -> V_4 < V_5 )
if ( F_99 ( V_2 ) )
F_54 ( V_2 ) ;
if ( V_2 -> V_4 < V_5 )
F_29 ( V_2 ) ;
else
F_30 ( V_2 ) ;
V_2 -> V_14 = V_22 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_14 == V_15 ) {
F_4 ( V_2 -> V_6 , L_14 , V_54 ) ;
return - V_30 ;
}
F_101 ( V_2 ) ;
F_90 ( V_2 ) ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
F_102 ( V_2 , F_103 ( V_2 ) ) ;
F_97 ( V_2 -> V_31 ) ;
V_2 -> V_14 = V_15 ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_116 ) {
V_10 = F_105 ( V_2 -> V_116 , 1 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 ,
L_16 ,
V_54 ) ;
return V_10 ;
}
}
F_106 ( V_2 ) ;
F_50 ( V_2 ) ;
F_52 ( V_2 ) ;
F_107 ( V_2 ) ;
return 0 ;
}
static int F_108 ( struct V_93 * V_18 ,
int V_117 , struct V_79 * V_80 )
{
struct V_81 * V_82 = F_70 ( V_80 ) ;
struct V_1 * V_2 = V_82 -> V_83 . V_84 ;
switch ( V_117 ) {
case V_118 :
return F_91 ( V_2 ) ;
case V_119 :
return F_100 ( V_2 ) ;
case V_120 :
return F_104 ( V_2 ) ;
default:
return - V_30 ;
}
}
static void F_109 ( struct V_93 * V_18 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = F_70 ( V_80 ) ;
struct V_1 * V_2 = V_82 -> V_83 . V_84 ;
if ( V_2 -> V_14 != V_15 )
F_100 ( V_2 ) ;
V_2 -> V_18 = NULL ;
}
static int F_110 ( struct V_121 * V_122 ,
struct V_1 * V_2 )
{
struct V_123 * V_124 = V_122 -> V_6 . V_125 ;
struct V_126 * V_126 ;
struct V_127 V_128 [ 2 ] = {
F_111 ( V_129 ,
8 + V_2 -> V_130 ,
8 + V_2 -> V_130 ) ,
F_111 (SYS_CFG_AUDIO_GLUE, 0 , 1 )
} ;
V_126 = F_112 ( V_124 , L_17 ) ;
if ( F_113 ( V_126 ) ) {
F_4 ( & V_122 -> V_6 , L_18 ) ;
return F_114 ( V_126 ) ;
}
V_2 -> V_116 = F_115 ( V_126 , V_128 [ 0 ] ) ;
V_2 -> V_131 = F_115 ( V_126 , V_128 [ 1 ] ) ;
return 0 ;
}
int F_116 ( struct V_121 * V_122 ,
struct V_1 * V_2 )
{
int V_10 = 0 ;
V_2 -> V_6 = & V_122 -> V_6 ;
V_2 -> V_14 = V_15 ;
V_2 -> V_132 = & V_133 ;
V_10 = F_110 ( V_122 , V_2 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 -> V_6 , L_19 ) ;
return V_10 ;
}
if ( V_2 -> V_4 >= V_5 )
V_2 -> V_16 = 1 ;
if ( F_76 ( V_2 ) )
V_2 -> V_134 = & V_135 ;
else
V_2 -> V_134 = & V_136 ;
V_2 -> V_31 = F_117 ( V_122 -> V_6 . V_125 , 0 ) ;
if ( F_113 ( V_2 -> V_31 ) )
V_10 = F_114 ( V_2 -> V_31 ) ;
if ( V_2 -> V_116 ) {
V_10 = F_105 ( V_2 -> V_116 , 1 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 ,
L_16 ,
V_54 ) ;
return V_10 ;
}
}
if ( V_2 -> V_131 &&
( V_2 -> V_130 == V_137 ) ) {
V_10 = F_105 ( V_2 -> V_131 , V_2 -> V_130 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 ,
L_20 , V_54 ) ;
return V_10 ;
}
}
V_10 = F_118 ( & V_122 -> V_6 , V_2 -> V_8 ,
F_5 , V_138 ,
F_119 ( & V_122 -> V_6 ) , V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
F_120 ( & V_2 -> V_35 ) ;
F_106 ( V_2 ) ;
F_50 ( V_2 ) ;
F_52 ( V_2 ) ;
F_107 ( V_2 ) ;
if ( F_99 ( V_2 ) ) {
V_2 -> V_36 . V_37 . V_12 [ 0 ] = 0x00 ;
V_2 -> V_36 . V_37 . V_12 [ 1 ] =
V_139 ;
V_2 -> V_36 . V_37 . V_12 [ 2 ] =
V_140 ;
V_2 -> V_36 . V_37 . V_12 [ 3 ] =
V_47 ;
V_2 -> V_36 . V_37 . V_12 [ 4 ] =
V_141 |
V_142 ;
V_2 -> V_143 = F_121 ( V_144 ) ;
V_2 -> V_145 = V_144 [ 0 ] ;
} else {
V_2 -> V_143 = F_121 ( V_146 ) ;
V_2 -> V_145 = V_146 [ 0 ] ;
}
return 0 ;
}
