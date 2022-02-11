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
if ( V_2 -> V_16 -> V_17 ) {
V_2 -> V_14 = V_18 ;
} else {
F_10 ( V_2 ) ;
F_11 ( V_2 -> V_19 ) ;
F_12 ( V_2 -> V_19 , V_20 ) ;
F_13 ( V_2 -> V_19 ) ;
}
V_10 = V_21 ;
}
if ( F_8 ( V_12 & F_14 ( V_2 ) ) ) {
F_4 ( V_2 -> V_6 , L_3 ) ;
F_15 ( V_2 ) ;
F_11 ( V_2 -> V_19 ) ;
F_12 ( V_2 -> V_19 , V_20 ) ;
F_13 ( V_2 -> V_19 ) ;
V_10 = V_21 ;
}
if ( F_8 ( V_12 & F_16 ( V_2 ) ) ) {
if ( ! V_2 -> V_16 -> V_17 ) {
F_4 ( V_2 -> V_6 , L_4 ) ;
return - V_22 ;
}
V_13 = F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
V_2 -> V_14 = V_23 ;
V_10 = V_21 ;
}
if ( F_8 ( V_12 &
F_19 ( V_2 ) ) ) {
F_4 ( V_2 -> V_6 , L_5 ) ;
F_11 ( V_2 -> V_19 ) ;
F_12 ( V_2 -> V_19 , V_20 ) ;
F_13 ( V_2 -> V_19 ) ;
V_10 = V_21 ;
}
return V_10 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned long V_24 )
{
int V_25 , V_26 , V_27 , V_10 ;
int V_28 = V_2 -> V_29 ;
if ( V_28 < 0 ) {
V_27 = - 1 ;
V_28 = - V_28 ;
} else {
V_27 = 1 ;
}
V_27 *= ( int ) F_21 ( ( V_30 ) V_24 *
( V_30 ) V_28 + 500000 , 1000000 ) ;
V_25 = V_24 + V_27 ;
if ( ! V_25 )
return - V_31 ;
V_10 = F_22 ( V_2 -> V_32 , V_25 ) ;
if ( V_10 < 0 )
return V_10 ;
V_26 = F_23 ( V_2 -> V_32 ) ;
if ( ! V_26 )
return - V_31 ;
V_27 = V_26 - V_24 ;
if ( V_27 < 0 ) {
V_27 = - V_27 ;
V_28 = - 1 ;
} else {
V_28 = 1 ;
}
V_28 *= ( int ) F_21 ( ( V_30 ) V_27 * 1000000 + V_24 / 2 ,
V_24 ) ;
V_2 -> V_29 = V_28 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_35 ;
unsigned int V_12 ;
F_25 ( & V_2 -> V_36 ) ;
if ( V_34 ) {
switch ( V_34 -> V_24 ) {
case 22050 :
V_2 -> V_37 . V_38 . V_12 [ 3 ] =
V_39 ;
break;
case 44100 :
V_2 -> V_37 . V_38 . V_12 [ 3 ] =
V_40 ;
break;
case 88200 :
V_2 -> V_37 . V_38 . V_12 [ 3 ] =
V_41 ;
break;
case 176400 :
V_2 -> V_37 . V_38 . V_12 [ 3 ] =
V_42 ;
break;
case 24000 :
V_2 -> V_37 . V_38 . V_12 [ 3 ] =
V_43 ;
break;
case 48000 :
V_2 -> V_37 . V_38 . V_12 [ 3 ] =
V_44 ;
break;
case 96000 :
V_2 -> V_37 . V_38 . V_12 [ 3 ] =
V_45 ;
break;
case 192000 :
V_2 -> V_37 . V_38 . V_12 [ 3 ] =
V_46 ;
break;
case 32000 :
V_2 -> V_37 . V_38 . V_12 [ 3 ] =
V_47 ;
break;
default:
V_2 -> V_37 . V_38 . V_12 [ 3 ] =
V_48 ;
break;
}
}
if ( V_2 -> V_37 . V_38 . V_12 [ 0 ] & V_49 )
V_2 -> V_37 . V_50 =
V_51 ;
else
V_2 -> V_37 . V_50 =
V_52 ;
if ( V_2 -> V_37 . V_50 ==
V_52 )
F_26 ( V_2 , 0 ) ;
else
F_26 ( V_2 , 1 ) ;
for ( V_35 = 0 ; V_35 < 6 ; ++ V_35 ) {
V_12 =
V_2 -> V_37 . V_38 . V_12 [ 0 + ( V_35 * 4 ) ] & 0xf ;
V_12 |=
V_2 -> V_37 . V_38 . V_12 [ 1 + ( V_35 * 4 ) ] << 8 ;
V_12 |=
V_2 -> V_37 . V_38 . V_12 [ 2 + ( V_35 * 4 ) ] << 16 ;
V_12 |=
V_2 -> V_37 . V_38 . V_12 [ 3 + ( V_35 * 4 ) ] << 24 ;
F_27 ( V_2 , V_35 , V_12 ) ;
}
F_28 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_4 < V_5 )
F_29 ( V_2 ) ;
else
F_30 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_53 ;
V_53 = V_2 -> V_54 / V_34 -> V_24 ;
if ( ( V_53 % 128 ) || ( V_53 <= 0 ) ) {
F_4 ( V_2 -> V_6 , L_6 ,
V_55 , V_53 ) ;
return - V_31 ;
}
switch ( V_34 -> V_56 ) {
case V_57 :
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
break;
case V_58 :
F_35 ( V_2 ) ;
F_33 ( V_2 ) ;
F_36 ( V_2 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_7 ) ;
return - V_31 ;
}
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_24 ( V_2 , V_34 ) ;
F_26 ( V_2 , 0 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( V_2 -> V_37 . V_50 ==
V_51 )
F_47 ( V_2 ) ;
else
F_48 ( V_2 ) ;
F_49 ( V_2 , V_34 -> V_59 / 2 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 , V_53 / 128 ) ;
F_52 ( V_2 ) ;
if ( V_2 -> V_4 < V_5 )
F_53 ( V_2 ) ;
else
F_54 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_60 , V_61 , V_53 ;
if ( ( V_2 -> V_62 & V_63 ) ==
V_64 )
V_61 = 32 ;
else
V_61 = F_56 ( V_34 -> V_56 ) ;
V_60 = V_61 * V_34 -> V_59 ;
V_53 = V_2 -> V_54 / V_34 -> V_24 ;
if ( ( V_61 == 32 ) && ( V_53 % 128 ) ) {
F_4 ( V_2 -> V_6 , L_8 , V_55 ) ;
return - V_31 ;
}
if ( ( V_61 == 16 ) && ( V_53 % 64 ) ) {
F_4 ( V_2 -> V_6 , L_8 , V_55 ) ;
return - V_31 ;
}
switch ( V_61 ) {
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
return - V_31 ;
}
switch ( V_34 -> V_56 ) {
case V_57 :
F_32 ( V_2 ) ;
break;
case V_58 :
F_35 ( V_2 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_7 ) ;
return - V_31 ;
}
F_50 ( V_2 ) ;
F_51 ( V_2 , V_53 / ( 2 * V_60 ) ) ;
if ( ( V_34 -> V_59 % 2 ) || ( V_34 -> V_59 < 2 ) ||
( V_34 -> V_59 > 10 ) ) {
F_4 ( V_2 -> V_6 , L_10 , V_55 ) ;
return - V_31 ;
}
F_49 ( V_2 , V_34 -> V_59 / 2 ) ;
F_43 ( V_2 ) ;
F_46 ( V_2 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_65 ;
int V_66 ;
unsigned int V_67 [ 4 ] = {
0x04060002 , 0x0C0E080A , 0x14161012 , 0x1C1E181A } ;
int V_68 , V_10 ;
V_65 =
F_60 ( V_2 ) ;
V_66 =
F_61 ( V_34 ) ;
F_35 ( V_2 ) ;
F_57 ( V_2 ) ;
F_49 ( V_2 , V_66 / 4 / 2 ) ;
F_46 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 , V_65 ) ;
F_65 ( V_2 , V_67 ) ;
F_66 ( V_2 , 1_2 , V_67 [ V_69 ] ) ;
F_66 ( V_2 , 3_4 , V_67 [ V_70 ] ) ;
F_66 ( V_2 , 5_6 , V_67 [ V_71 ] ) ;
F_66 ( V_2 , 7_8 , V_67 [ V_72 ] ) ;
V_68 = V_34 -> V_24 * V_65 * 8 ;
F_25 ( & V_2 -> V_36 ) ;
V_10 = F_20 ( V_2 , V_68 ) ;
if ( ! V_10 )
V_2 -> V_54 = V_68 ;
F_28 ( & V_2 -> V_36 ) ;
return 0 ;
}
static int F_67 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
V_76 -> type = V_77 ;
V_76 -> V_3 = 1 ;
return 0 ;
}
static int F_68 ( struct V_73 * V_74 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = F_69 ( V_74 ) ;
struct V_82 * V_83 = F_70 ( V_81 ) ;
struct V_1 * V_2 = V_83 -> V_84 . V_85 ;
struct V_86 * V_38 = & V_2 -> V_37 . V_38 ;
F_25 ( & V_2 -> V_36 ) ;
V_79 -> V_87 . V_38 . V_12 [ 0 ] = V_38 -> V_12 [ 0 ] ;
V_79 -> V_87 . V_38 . V_12 [ 1 ] = V_38 -> V_12 [ 1 ] ;
V_79 -> V_87 . V_38 . V_12 [ 2 ] = V_38 -> V_12 [ 2 ] ;
V_79 -> V_87 . V_38 . V_12 [ 3 ] = V_38 -> V_12 [ 3 ] ;
F_28 ( & V_2 -> V_36 ) ;
return 0 ;
}
static int F_71 ( struct V_73 * V_74 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = F_69 ( V_74 ) ;
struct V_82 * V_83 = F_70 ( V_81 ) ;
struct V_1 * V_2 = V_83 -> V_84 . V_85 ;
struct V_86 * V_38 = & V_2 -> V_37 . V_38 ;
F_25 ( & V_2 -> V_36 ) ;
V_38 -> V_12 [ 0 ] = V_79 -> V_87 . V_38 . V_12 [ 0 ] ;
V_38 -> V_12 [ 1 ] = V_79 -> V_87 . V_38 . V_12 [ 1 ] ;
V_38 -> V_12 [ 2 ] = V_79 -> V_87 . V_38 . V_12 [ 2 ] ;
V_38 -> V_12 [ 3 ] = V_79 -> V_87 . V_38 . V_12 [ 3 ] ;
F_28 ( & V_2 -> V_36 ) ;
F_24 ( V_2 , NULL ) ;
return 0 ;
}
static int F_72 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
V_76 -> type = V_88 ;
V_76 -> V_3 = 1 ;
V_76 -> V_87 . integer . V_89 = V_90 ;
V_76 -> V_87 . integer . V_91 = V_92 ;
V_76 -> V_87 . integer . V_93 = 1 ;
return 0 ;
}
static int F_73 ( struct V_73 * V_74 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = F_69 ( V_74 ) ;
struct V_82 * V_83 = F_70 ( V_81 ) ;
struct V_1 * V_2 = V_83 -> V_84 . V_85 ;
F_25 ( & V_2 -> V_36 ) ;
V_79 -> V_87 . integer . V_87 [ 0 ] = V_2 -> V_29 ;
F_28 ( & V_2 -> V_36 ) ;
return 0 ;
}
static int F_74 ( struct V_73 * V_74 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = F_69 ( V_74 ) ;
struct V_82 * V_83 = F_70 ( V_81 ) ;
struct V_1 * V_2 = V_83 -> V_84 . V_85 ;
int V_10 = 0 ;
if ( ( V_79 -> V_87 . integer . V_87 [ 0 ] < V_90 ) ||
( V_79 -> V_87 . integer . V_87 [ 0 ] > V_92 ) )
return - V_31 ;
F_25 ( & V_2 -> V_36 ) ;
V_2 -> V_29 = V_79 -> V_87 . integer . V_87 [ 0 ] ;
if ( V_2 -> V_54 )
V_10 = F_20 ( V_2 , V_2 -> V_54 ) ;
F_28 ( & V_2 -> V_36 ) ;
return V_10 ;
}
static int F_75 ( struct V_94 * V_19 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 = F_70 ( V_81 ) ;
struct V_1 * V_2 = V_83 -> V_84 . V_85 ;
int V_10 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_29 = 0 ;
if ( ! F_76 ( V_2 ) )
return 0 ;
V_10 = F_77 ( V_19 -> V_34 , 0 ,
V_95 ,
V_96 ,
V_2 , V_95 ,
- 1 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_77 ( V_19 -> V_34 , 0 ,
V_97 ,
V_98 ,
V_2 , V_97 ,
- 1 ) ;
}
static int F_78 ( struct V_80 * V_81 , int V_99 ,
unsigned int V_68 , int V_100 )
{
struct V_82 * V_83 = F_70 ( V_81 ) ;
struct V_1 * V_2 = V_83 -> V_84 . V_85 ;
int V_10 ;
if ( F_76 ( V_2 ) || ( V_100 == V_101 ) )
return 0 ;
if ( V_99 != 0 )
return - V_31 ;
F_25 ( & V_2 -> V_36 ) ;
V_10 = F_20 ( V_2 , V_68 ) ;
if ( ! V_10 )
V_2 -> V_54 = V_68 ;
F_28 ( & V_2 -> V_36 ) ;
return V_10 ;
}
static int F_79 ( struct V_94 * V_19 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 = F_70 ( V_81 ) ;
struct V_1 * V_2 = V_83 -> V_84 . V_85 ;
struct V_33 * V_34 = V_19 -> V_34 ;
int V_102 , V_103 ;
int V_10 ;
if ( V_2 -> V_14 != V_15 ) {
F_4 ( V_2 -> V_6 , L_11 , V_55 ,
V_2 -> V_14 ) ;
return - V_31 ;
}
if ( V_2 -> V_16 -> type == V_104 ) {
V_102 =
F_61 ( V_34 ) / 4 ;
} else {
V_102 = V_34 -> V_59 * V_105 ;
}
if ( V_2 -> V_4 < V_5 ) {
V_103 = V_106 - V_102 ;
} else {
V_103 = V_102 ;
}
if ( ( ! V_103 % 2 ) || ( V_103 != 1 && V_102 % 2 ) ||
( V_103 > F_80 ( V_2 ) ) ) {
F_4 ( V_2 -> V_6 , L_12 , V_103 ) ;
return - V_31 ;
}
F_81 ( V_2 , V_103 ) ;
switch ( V_2 -> V_16 -> type ) {
case V_107 :
V_10 = F_31 ( V_2 , V_34 ) ;
break;
case V_108 :
V_10 = F_55 ( V_2 , V_34 ) ;
break;
case V_109 :
V_10 = F_31 ( V_2 , V_34 ) ;
break;
case V_104 :
V_10 = F_59 ( V_2 , V_34 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_13 ) ;
return - V_31 ;
}
if ( V_10 )
return V_10 ;
switch ( V_2 -> V_62 & V_110 ) {
case V_111 :
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
break;
case V_112 :
F_84 ( V_2 ) ;
F_83 ( V_2 ) ;
break;
case V_113 :
F_82 ( V_2 ) ;
F_85 ( V_2 ) ;
break;
case V_114 :
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
break;
}
switch ( V_2 -> V_62 & V_63 ) {
case V_64 :
F_62 ( V_2 ) ;
F_86 ( V_2 ) ;
break;
case V_115 :
F_62 ( V_2 ) ;
F_87 ( V_2 ) ;
break;
case V_116 :
F_88 ( V_2 ) ;
F_87 ( V_2 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_7 ) ;
return - V_31 ;
}
F_89 ( V_2 , 0 ) ;
F_90 ( V_2 ) ;
return F_1 ( V_2 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_14 != V_15 ) {
F_4 ( V_2 -> V_6 , L_14 , V_55 ) ;
return - V_31 ;
}
V_10 = F_92 ( V_2 -> V_32 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 , L_15 , V_55 ) ;
return V_10 ;
}
F_7 ( V_2 , F_6 ( V_2 ) ) ;
F_93 ( V_2 ) ;
F_94 ( V_2 ) ;
if ( V_2 -> V_16 -> V_17 ) {
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
}
F_90 ( V_2 ) ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
F_97 ( V_2 ) ;
if ( V_2 -> V_4 < V_5 )
if ( F_98 ( V_2 ) )
F_54 ( V_2 ) ;
if ( V_2 -> V_4 < V_5 )
F_29 ( V_2 ) ;
else
F_30 ( V_2 ) ;
V_2 -> V_14 = V_23 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_14 == V_15 ) {
F_4 ( V_2 -> V_6 , L_14 , V_55 ) ;
return - V_31 ;
}
F_100 ( V_2 ) ;
F_90 ( V_2 ) ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
F_101 ( V_2 , F_102 ( V_2 ) ) ;
F_103 ( V_2 -> V_32 ) ;
V_2 -> V_14 = V_15 ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_117 ) {
V_10 = F_105 ( V_2 -> V_117 , 1 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 ,
L_16 ,
V_55 ) ;
return V_10 ;
}
}
F_106 ( V_2 ) ;
F_50 ( V_2 ) ;
F_52 ( V_2 ) ;
F_107 ( V_2 ) ;
return 0 ;
}
static int F_108 ( struct V_94 * V_19 ,
int V_118 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_70 ( V_81 ) ;
struct V_1 * V_2 = V_83 -> V_84 . V_85 ;
switch ( V_118 ) {
case V_119 :
return F_91 ( V_2 ) ;
case V_120 :
return F_99 ( V_2 ) ;
case V_121 :
return F_104 ( V_2 ) ;
default:
return - V_31 ;
}
}
static void F_109 ( struct V_94 * V_19 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 = F_70 ( V_81 ) ;
struct V_1 * V_2 = V_83 -> V_84 . V_85 ;
if ( V_2 -> V_14 != V_15 )
F_99 ( V_2 ) ;
V_2 -> V_19 = NULL ;
}
static int F_110 ( struct V_122 * V_123 ,
struct V_1 * V_2 )
{
struct V_124 * V_125 = V_123 -> V_6 . V_126 ;
struct V_127 * V_127 ;
struct V_128 V_129 [ 2 ] = {
F_111 ( V_130 ,
8 + V_2 -> V_16 -> V_131 ,
8 + V_2 -> V_16 -> V_131 ) ,
F_111 (SYS_CFG_AUDIO_GLUE, 0 , 1 )
} ;
V_127 = F_112 ( V_125 , L_17 ) ;
if ( F_113 ( V_127 ) ) {
F_4 ( & V_123 -> V_6 , L_18 ) ;
return F_114 ( V_127 ) ;
}
V_2 -> V_117 = F_115 ( V_127 , V_129 [ 0 ] ) ;
V_2 -> V_132 = F_115 ( V_127 , V_129 [ 1 ] ) ;
return 0 ;
}
static int F_116 ( struct V_122 * V_123 ,
struct V_1 * V_2 )
{
struct V_133 * V_16 ;
struct V_134 * V_6 = & V_123 -> V_6 ;
struct V_124 * V_135 = V_123 -> V_6 . V_126 ;
const char * V_136 ;
V_16 = F_117 ( V_6 , sizeof( * V_16 ) , V_137 ) ;
if ( ! V_16 )
return - V_138 ;
if ( F_118 ( V_135 , L_19 , & V_2 -> V_4 ) ||
V_2 -> V_4 == V_139 ) {
F_4 ( V_6 , L_20 ) ;
return - V_31 ;
}
if ( V_2 -> V_4 >= V_5 )
V_16 -> V_17 = 1 ;
if ( F_118 ( V_135 , L_21 , & V_16 -> V_131 ) ) {
F_4 ( V_6 , L_22 ) ;
return - V_31 ;
}
if ( F_119 ( V_135 , L_23 , & V_136 ) ) {
F_4 ( V_6 , L_24 ) ;
return - V_31 ;
}
if ( strcasecmp ( V_136 , L_25 ) == 0 )
V_16 -> type = V_107 ;
else if ( strcasecmp ( V_136 , L_26 ) == 0 )
V_16 -> type = V_108 ;
else if ( strcasecmp ( V_136 , L_27 ) == 0 )
V_16 -> type = V_109 ;
else if ( strcasecmp ( V_136 , L_28 ) == 0 )
V_16 -> type = V_104 ;
else
V_16 -> type = V_140 ;
V_2 -> V_16 = V_16 ;
if ( F_110 ( V_123 , V_2 ) )
return - V_31 ;
return 0 ;
}
int F_120 ( struct V_122 * V_123 ,
struct V_1 * V_2 )
{
int V_10 = 0 ;
V_2 -> V_6 = & V_123 -> V_6 ;
V_2 -> V_14 = V_15 ;
V_2 -> V_141 = & V_142 ;
V_10 = F_116 ( V_123 , V_2 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 -> V_6 , L_29 ) ;
return V_10 ;
}
if ( F_76 ( V_2 ) )
V_2 -> V_143 = & V_144 ;
else
V_2 -> V_143 = & V_145 ;
V_2 -> V_32 = F_121 ( V_123 -> V_6 . V_126 , 0 ) ;
if ( F_113 ( V_2 -> V_32 ) )
V_10 = F_114 ( V_2 -> V_32 ) ;
if ( V_2 -> V_117 ) {
V_10 = F_105 ( V_2 -> V_117 , 1 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 ,
L_16 ,
V_55 ) ;
return V_10 ;
}
}
if ( V_2 -> V_132 &&
( V_2 -> V_16 -> V_131 == V_146 ) ) {
V_10 = F_105 ( V_2 -> V_132 , V_2 -> V_16 -> V_131 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 ,
L_30 , V_55 ) ;
return V_10 ;
}
}
V_10 = F_122 ( & V_123 -> V_6 , V_2 -> V_8 ,
F_5 , V_147 ,
F_123 ( & V_123 -> V_6 ) , V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
F_124 ( & V_2 -> V_36 ) ;
F_106 ( V_2 ) ;
F_50 ( V_2 ) ;
F_52 ( V_2 ) ;
F_107 ( V_2 ) ;
if ( F_98 ( V_2 ) ) {
V_2 -> V_37 . V_38 . V_12 [ 0 ] = 0x00 ;
V_2 -> V_37 . V_38 . V_12 [ 1 ] =
V_148 ;
V_2 -> V_37 . V_38 . V_12 [ 2 ] =
V_149 ;
V_2 -> V_37 . V_38 . V_12 [ 3 ] =
V_48 ;
V_2 -> V_37 . V_38 . V_12 [ 4 ] =
V_150 |
V_151 ;
V_2 -> V_152 = F_125 ( V_153 ) ;
V_2 -> V_154 = V_153 [ 0 ] ;
} else {
V_2 -> V_152 = F_125 ( V_155 ) ;
V_2 -> V_154 = V_155 [ 0 ] ;
}
return 0 ;
}
