static inline const struct V_1 * F_1 ( int V_2 )
{
switch ( V_2 ) {
default:
case V_3 :
return & V_4 ;
case V_5 :
return & V_6 ;
}
}
static int F_2 ( struct V_7 * V_8 , T_1 * V_9 , int V_10 )
{
struct V_11 V_12 = { . V_13 = V_8 -> V_14 . V_13 ,
. V_15 = 0 , . V_9 = V_9 , . V_10 = V_10 } ;
if ( F_3 ( V_8 -> V_14 . V_16 , & V_12 , 1 ) != 1 ) {
F_4 ( V_17 L_1 , V_10 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_5 ( struct V_7 * V_8 , T_2 V_19 , T_2 * V_20 )
{
T_1 V_9 [ 2 ] = { V_19 >> 8 , V_19 & 0xff } ;
T_1 V_21 [ 2 ] = { 0 , 0 } ;
struct V_11 V_12 [ 2 ] = {
{ . V_13 = V_8 -> V_14 . V_13 ,
. V_15 = 0 , . V_9 = & V_9 [ 0 ] , . V_10 = 2 } ,
{ . V_13 = V_8 -> V_14 . V_13 ,
. V_15 = V_22 , . V_9 = & V_21 [ 0 ] , . V_10 = 2 } ,
} ;
if ( F_3 ( V_8 -> V_14 . V_16 , V_12 , 2 ) != 2 ) {
F_4 ( V_23 L_2 ) ;
return - V_18 ;
}
* V_20 = ( V_21 [ 0 ] << 8 ) | V_21 [ 1 ] ;
return 0 ;
}
static int F_6 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 ;
F_7 ( 1 , L_3 , V_28 ) ;
if ( V_25 -> V_29 ) {
V_27 = V_25 -> V_29 ( ( ( V_25 -> V_30 ) && ( V_25 -> V_30 -> V_8 ) ) ?
V_25 -> V_30 -> V_8 :
V_8 -> V_14 . V_16 -> V_31 ,
V_32 ,
V_33 , 0 ) ;
if ( V_27 ) {
F_4 ( V_17 L_4 ) ;
return V_27 ;
}
} else {
F_4 ( V_17 L_5 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_8 ( struct V_7 * V_8 , T_2 V_35 , T_2 V_36 )
{
T_1 V_9 [ 4 ] ;
int V_37 = 100 ;
int V_38 ;
V_9 [ 0 ] = ( V_35 >> 8 ) & 0xFF ;
V_9 [ 1 ] = V_35 & 0xFF ;
V_9 [ 2 ] = ( V_36 >> 8 ) & 0xFF ;
V_9 [ 3 ] = V_36 & 0xFF ;
V_38 = F_2 ( V_8 , V_9 , 4 ) ;
if ( V_38 == 0 ) {
while ( ( V_37 > 0 ) && ( V_38 == 0 ) ) {
V_38 = F_5 ( V_8 , V_39 , ( T_2 * ) V_9 ) ;
if ( V_38 == 0 ) {
if ( ( V_9 [ 0 ] == 0 ) && ( V_9 [ 1 ] == 0 ) ) {
break;
} else {
F_9 ( 5 ) ;
V_37 -- ;
}
}
}
}
if ( V_37 <= 0 )
V_38 = - V_18 ;
return V_38 ;
}
static int F_10 ( struct V_24 * V_25 , const T_1 * V_40 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_41 , V_42 , V_38 ;
unsigned int V_10 , V_43 , V_44 ;
T_1 V_9 [ V_45 ] ;
V_44 = 0 ;
while ( ( V_40 [ V_44 ] != 0xFF ) ||
( V_40 [ V_44 + 1 ] != 0xFF ) ) {
V_10 = V_40 [ V_44 ] * 256 + V_40 [ V_44 + 1 ] ;
if ( V_10 == 0x0000 ) {
V_38 = F_6 ( V_25 ) ;
V_44 += 2 ;
if ( V_38 != 0 )
return V_38 ;
} else if ( V_10 & 0x8000 ) {
F_9 ( V_10 & 0x7FFF ) ;
V_44 += 2 ;
} else {
V_44 += 2 ;
V_9 [ 0 ] = V_40 [ V_44 ] ;
V_9 [ 1 ] = V_40 [ V_44 + 1 ] ;
V_43 = 2 ;
while ( V_43 < V_10 ) {
if ( ( V_10 - V_43 ) > V_45 - 2 )
V_42 =
V_45 ;
else
V_42 = ( V_10 - V_43 + 2 ) ;
for ( V_41 = 2 ; V_41 < V_42 ; V_41 ++ ) {
V_9 [ V_41 ] = V_40 [ V_44 + V_43 +
V_41 - 2 ] ;
}
V_38 = F_2 ( V_8 , V_9 ,
V_42 ) ;
if ( V_38 != 0 )
return V_38 ;
V_43 += V_42 - 2 ;
}
V_44 += V_10 ;
}
}
return 0 ;
}
static int F_11 ( struct V_7 * V_8 )
{
F_7 ( 1 , L_3 , V_28 ) ;
return F_8 ( V_8 , V_46 , 0 ) ;
}
static int F_12 ( struct V_7 * V_8 ,
T_2 V_47 , T_2 V_48 , T_1 V_49 )
{
int V_27 ;
F_7 ( 1 , L_6 , V_28 , V_47 , V_48 ) ;
if ( V_49 ) {
F_7 ( 1 , L_7 ,
V_28 ,
V_50 [ V_49 ] . V_51 ) ;
} else {
F_7 ( 1 , L_7 ,
V_28 ,
V_50 [ V_8 -> V_52 ] . V_51 ) ;
}
V_27 = F_8 ( V_8 , V_53 , V_47 ) ;
if ( V_27 == 0 )
V_27 = F_8 ( V_8 , V_54 , V_48 ) ;
return V_27 ;
}
static int F_13 ( struct V_7 * V_8 , T_2 V_55 )
{
F_7 ( 1 , L_8 , V_28 , V_55 ,
V_55 == V_56 ? L_9 : L_10 ) ;
if ( ( V_55 != V_56 ) && ( V_55 != V_57 ) ) {
V_55 = V_57 ;
F_4 ( V_17
L_11 ,
V_28 ) ;
}
return F_8 ( V_8 , V_58 , V_55 ) ;
}
static int F_14 ( struct V_7 * V_8 , T_3 V_59 )
{
T_2 V_60 ;
F_7 ( 1 , L_12 , V_28 , V_59 ) ;
if ( ( V_59 > V_61 . V_62 . V_63 ) ||
( V_59 < V_61 . V_62 . V_64 ) )
return - V_34 ;
V_60 = ( T_2 ) ( V_59 / 15625 ) ;
return F_8 ( V_8 , V_65 , V_60 ) ;
}
static int F_15 ( struct V_7 * V_8 , T_3 V_66 )
{
T_3 V_60 = ( V_66 * 1024 ) / 1000 ;
F_7 ( 1 , L_13 ,
V_28 , V_66 , V_60 ) ;
return F_8 ( V_8 , V_67 , V_60 ) ;
}
static int F_16 ( struct V_7 * V_8 , T_2 * V_68 )
{
return F_5 ( V_8 , V_69 , V_68 ) ;
}
static int F_17 ( struct V_7 * V_8 , T_3 * V_70 )
{
int V_38 ;
T_2 V_71 ;
T_3 V_72 ;
V_38 = F_5 ( V_8 , V_73 , & V_71 ) ;
if ( V_38 != 0 )
return V_38 ;
V_72 = ( T_3 ) V_71 ;
( * V_70 ) = ( V_72 * 15625 ) / 1000 ;
return V_38 ;
}
static int F_18 ( struct V_7 * V_8 , T_2 * V_74 )
{
return F_5 ( V_8 , V_75 , V_74 ) ;
}
static int F_19 ( struct V_7 * V_8 ,
T_1 * V_76 , T_1 * V_77 ,
T_1 * V_78 , T_1 * V_79 )
{
T_2 V_80 ;
int V_38 ;
V_38 = F_5 ( V_8 , V_81 , & V_80 ) ;
if ( V_38 != 0 )
return V_38 ;
( * V_76 ) = ( V_80 >> 12 ) & 0x0F ;
( * V_77 ) = ( V_80 >> 8 ) & 0x0F ;
( * V_78 ) = ( V_80 >> 4 ) & 0x0F ;
( * V_79 ) = V_80 & 0x0F ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 , T_2 * V_82 )
{
return F_5 ( V_8 , V_83 , V_82 ) ;
}
static int F_21 ( struct V_7 * V_8 , T_3 * V_84 )
{
T_2 V_71 ;
int V_38 ;
V_38 = F_5 ( V_8 , V_85 , & V_71 ) ;
if ( V_38 != 0 )
return V_38 ;
( * V_84 ) = ( ( V_71 & 0x0fff ) * 763 ) / 100 ;
return V_38 ;
}
static int F_22 ( struct V_7 * V_8 , T_2 * V_86 )
{
return F_5 ( V_8 , V_87 , V_86 ) ;
}
static int F_23 ( struct V_7 * V_8 , T_2 * V_88 )
{
return F_5 ( V_8 , V_89 , V_88 ) ;
}
static int F_24 ( struct V_7 * V_8 , T_2 * V_90 )
{
return F_5 ( V_8 , V_91 , V_90 ) ;
}
static int F_25 ( struct V_7 * V_8 , T_2 * V_92 )
{
return F_5 ( V_8 , V_93 , V_92 ) ;
}
static int F_26 ( struct V_7 * V_8 , T_3 V_59 , int V_94 )
{
F_7 ( 1 , L_12 , V_28 , V_59 ) ;
if ( F_14 ( V_8 , V_59 ) != 0 )
return - V_18 ;
return 0 ;
}
static int F_27 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 = 0 ;
switch ( V_8 -> V_2 ) {
default:
case V_3 :
break;
case V_5 :
switch ( V_8 -> V_95 ) {
default:
case 32000 :
break;
case 31875 :
V_27 = F_8 ( V_8 , 0x000f , 0x8081 ) ;
break;
}
break;
}
return V_27 ;
}
static int F_28 ( struct V_24 * V_25 ,
const struct V_1 * V_96 ,
const struct V_97 * V_98 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 ;
F_7 ( 1 , L_14 ,
V_96 -> V_51 ) ;
V_8 -> V_99 = V_96 -> V_100 ;
V_8 -> V_101 = V_96 -> V_101 ;
V_8 -> V_102 = V_96 -> V_102 ;
F_7 ( 1 , L_15 ) ;
V_27 = F_10 ( V_25 , V_98 -> V_80 ) ;
if ( ! V_27 ) {
V_27 = F_27 ( V_25 ) ;
F_7 ( 1 , L_16 ) ;
} else
F_4 ( V_17 L_17 ) ;
return V_27 ;
}
static void F_29 ( struct V_7 * V_8 )
{
T_2 V_68 ;
T_3 V_70 = 0 ;
T_2 V_74 ;
T_3 V_84 = 0 ;
T_2 V_86 ;
T_2 V_88 ;
T_2 V_90 ;
T_2 V_92 ;
T_1 V_76 = 0 , V_77 = 0 ;
T_1 V_78 = 0 , V_79 = 0 ;
T_2 V_103 = 0 ;
T_2 V_104 ;
F_9 ( 100 ) ;
F_16 ( V_8 , & V_68 ) ;
F_7 ( 1 , L_18 , V_68 ) ;
F_17 ( V_8 , & V_70 ) ;
F_7 ( 1 , L_19 , V_70 ) ;
F_18 ( V_8 , & V_74 ) ;
F_7 ( 1 , L_20 ,
V_74 ) ;
F_19 ( V_8 , & V_76 , & V_77 ,
& V_78 , & V_79 ) ;
F_20 ( V_8 , & V_103 ) ;
F_7 ( 1 , L_21 ,
V_76 , V_77 ,
V_78 , V_79 , V_103 ) ;
F_21 ( V_8 , & V_84 ) ;
F_7 ( 1 , L_22 , V_84 ) ;
F_22 ( V_8 , & V_86 ) ;
F_7 ( 1 , L_23 , V_86 ) ;
F_23 ( V_8 , & V_88 ) ;
F_7 ( 1 , L_24 , V_88 & 0x07 ) ;
F_24 ( V_8 , & V_90 ) ;
F_7 ( 1 , L_25 , V_90 & 0x3f ) ;
F_25 ( V_8 , & V_92 ) ;
F_7 ( 1 , L_26 , V_92 / 256 ,
( V_92 % 256 ) * 100 / 256 ) ;
if ( V_8 -> V_99 ) {
F_5 ( V_8 , V_8 -> V_99 , & V_104 ) ;
F_7 ( 1 , L_27 , V_104 ) ;
}
}
static int F_30 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 ;
T_3 V_105 = V_25 -> V_106 . V_107 ;
V_27 = F_13 ( V_8 , V_8 -> V_55 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17
L_28 ,
V_8 -> V_55 ) ;
return - V_18 ;
}
V_27 = F_12 ( V_8 ,
V_50 [ V_8 -> V_52 ] . V_47 ,
V_50 [ V_8 -> V_52 ] . V_48 , 0 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17 L_29 ) ;
return - V_18 ;
}
V_27 = F_15 ( V_8 , V_8 -> V_108 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17 L_30 ,
V_8 -> V_108 ) ;
return - V_109 ;
}
F_7 ( 1 , L_31 ,
V_28 , V_8 -> V_110 ) ;
F_8 ( V_8 , V_111 , V_8 -> V_110 ) ;
F_26 ( V_8 , V_8 -> V_59 , V_112 ) ;
if ( V_113 )
F_29 ( V_8 ) ;
V_8 -> V_114 = V_105 ;
return 0 ;
}
static int F_31 ( struct V_24 * V_25 )
{
int V_115 ;
struct V_7 * V_8 = V_25 -> V_26 ;
T_3 V_105 = V_25 -> V_106 . V_107 ;
T_3 V_116 = V_25 -> V_106 . V_117 ;
T_3 V_118 = V_25 -> V_106 . V_119 ;
if ( F_32 ( V_25 , 0 ) != 0 ) {
F_7 ( 1 , L_32 ) ;
return - V_34 ;
}
F_7 ( 1 , L_33 , V_28 , V_116 ) ;
switch ( V_118 ) {
case V_120 :
F_7 ( 1 , L_34 , V_28 ) ;
V_8 -> V_55 = V_56 ;
V_8 -> V_121 = 1750000 ;
V_8 -> V_52 = V_122 ;
break;
case V_123 :
F_7 ( 1 , L_35 , V_28 ) ;
V_8 -> V_55 = V_57 ;
V_8 -> V_121 = 1750000 ;
V_8 -> V_52 = V_122 ;
break;
case V_124 :
if ( ! V_105 )
V_105 = 6000000 ;
case V_125 :
case V_126 :
case V_127 :
F_7 ( 1 , L_36 , V_28 ) ;
switch ( V_105 ) {
case 6000000 :
V_8 -> V_52 = V_122 ;
V_8 -> V_121 = 1750000 ;
break;
case 7000000 :
V_8 -> V_52 = V_128 ;
V_8 -> V_121 = 2250000 ;
break;
case 8000000 :
V_8 -> V_52 = V_129 ;
V_8 -> V_121 = 2750000 ;
break;
default:
F_4 ( V_17 L_37 ) ;
return - V_34 ;
}
V_8 -> V_55 = V_56 ;
break;
case V_130 :
case V_131 :
F_7 ( 1 , L_35 , V_28 ) ;
V_8 -> V_55 = V_57 ;
if ( V_105 <= 6000000 ) {
V_8 -> V_52 = V_122 ;
V_8 -> V_121 = 1750000 ;
V_115 = 6 ;
} else if ( V_105 <= 7000000 ) {
V_8 -> V_52 = V_128 ;
V_8 -> V_121 = 2250000 ;
V_115 = 7 ;
} else {
V_8 -> V_52 = V_132 ;
V_8 -> V_121 = 2750000 ;
V_115 = 8 ;
}
F_7 ( 1 , L_38 , V_28 ,
V_115 , V_105 ) ;
break;
default:
F_4 ( V_17 L_39 ) ;
return - V_34 ;
}
V_8 -> V_59 = V_116 - V_8 -> V_121 ;
V_8 -> V_94 = V_133 ;
F_7 ( 1 , L_40 ,
V_28 , V_116 , V_8 -> V_59 ) ;
return F_30 ( V_25 ) ;
}
static int F_33 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 ;
T_2 V_134 ;
V_27 = F_5 ( V_8 , V_135 , & V_134 ) ;
if ( V_27 == 0 ) {
if ( V_134 == V_136 )
V_27 = - V_137 ;
else
V_27 = 0 ;
}
F_7 ( 1 , L_41 , V_28 ,
V_27 == 0 ? L_42 : L_43 , V_134 ) ;
return V_27 ;
}
static void F_34 ( struct V_24 * V_25 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_44 ,
V_28 , V_139 -> V_117 ) ;
V_8 -> V_55 = V_139 -> V_94 ;
if ( V_139 -> V_94 > V_57 )
V_8 -> V_55 = V_57 ;
V_8 -> V_59 = V_139 -> V_117 * 62500 ;
if ( V_139 -> V_140 & V_141 ) {
V_8 -> V_52 = V_142 ;
return;
}
if ( V_139 -> V_140 & V_143 ) {
V_8 -> V_52 = V_144 ;
return;
}
if ( V_139 -> V_140 & V_145 ) {
V_8 -> V_52 = V_146 ;
return;
}
if ( V_139 -> V_140 & V_147 ) {
V_8 -> V_52 = V_148 ;
return;
}
if ( V_139 -> V_140 & V_149 ) {
V_8 -> V_52 = V_150 ;
return;
}
if ( V_139 -> V_140 & V_151 ) {
V_8 -> V_52 = V_152 ;
return;
}
if ( V_139 -> V_140 & V_153 ) {
V_8 -> V_52 = V_154 ;
return;
}
}
static int F_35 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
T_2 V_155 ;
int V_27 ;
V_156:
V_27 = F_13 ( V_8 , V_8 -> V_55 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17
L_28 ,
V_8 -> V_55 ) ;
return - V_18 ;
}
V_27 = F_12 ( V_8 ,
V_50 [ V_8 -> V_52 ] . V_47 ,
V_50 [ V_8 -> V_52 ] . V_48 , 0 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17 L_29 ) ;
return - V_18 ;
}
F_8 ( V_8 , V_111 , 0x09 ) ;
F_26 ( V_8 , V_8 -> V_59 , V_157 ) ;
if ( V_113 )
F_29 ( V_8 ) ;
if ( V_8 -> V_99 != 0 ) {
F_9 ( 20 ) ;
F_5 ( V_8 , V_8 -> V_99 , & V_155 ) ;
if ( V_155 > 63 ) {
F_7 ( 1 , L_45 ,
V_155 ) ;
if ( F_32 ( V_25 , 1 ) != 0 ) {
F_4 ( V_17 L_46 ) ;
return - V_18 ;
}
goto V_156;
}
}
return 0 ;
}
static int F_36 ( struct V_24 * V_25 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_47 ,
V_28 , V_139 -> V_117 ) ;
if ( V_8 -> V_158 == V_159 ) {
F_7 ( 1 , L_48 , V_28 ) ;
return - V_34 ;
}
V_8 -> V_59 = V_139 -> V_117 * 125 / 2 ;
V_8 -> V_55 = V_56 ;
return 0 ;
}
static int F_37 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 ;
T_1 V_158 ;
if ( V_8 -> V_158 == V_160 )
V_158 = V_161 ;
else if ( V_8 -> V_158 == V_162 )
V_158 = V_163 ;
else if ( V_8 -> V_158 == V_164 )
V_158 = V_165 ;
else {
F_7 ( 1 , L_49 , V_28 ,
V_8 -> V_158 ) ;
return - V_34 ;
}
V_27 = F_12 ( V_8 , V_50 [ V_158 ] . V_47 ,
V_50 [ V_158 ] . V_48 , V_158 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17 L_29 ) ;
return - V_18 ;
}
V_27 = F_13 ( V_8 , V_8 -> V_55 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17
L_28 ,
V_8 -> V_55 ) ;
return - V_18 ;
}
if ( ( V_8 -> V_158 == V_160 ) ||
( V_8 -> V_158 == V_162 ) )
F_8 ( V_8 , V_111 , 0x09 ) ;
else if ( V_8 -> V_158 == V_164 )
F_8 ( V_8 , V_111 , 0x06 ) ;
F_26 ( V_8 , V_8 -> V_59 , V_157 ) ;
return 0 ;
}
static int F_38 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
if ( F_32 ( V_25 , 0 ) != 0 ) {
F_7 ( 1 , L_32 ) ;
return - V_34 ;
}
switch ( V_8 -> V_94 ) {
case V_166 :
return F_37 ( V_25 ) ;
case V_167 :
return F_35 ( V_25 ) ;
case V_133 :
return F_30 ( V_25 ) ;
}
return 0 ;
}
static int F_39 ( struct V_24 * V_25 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 ;
if ( V_8 -> V_14 . V_16 == NULL )
return - V_34 ;
switch ( V_139 -> V_94 ) {
case V_166 :
V_27 = F_36 ( V_25 , V_139 ) ;
if ( V_27 )
return V_27 ;
break;
case V_167 :
F_34 ( V_25 , V_139 ) ;
break;
default:
break;
}
V_8 -> V_94 = V_139 -> V_94 ;
return F_38 ( V_25 ) ;
}
static int F_40 ( struct V_24 * V_25 , T_3 * V_116 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
* V_116 = V_8 -> V_59 + V_8 -> V_121 ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 , T_3 * V_116 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
* V_116 = V_8 -> V_108 * 1000 ;
return 0 ;
}
static int F_42 ( struct V_24 * V_25 , T_3 * V_105 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
* V_105 = V_8 -> V_114 ;
return 0 ;
}
static int F_43 ( struct V_24 * V_25 , T_3 * V_168 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
T_2 V_74 = 0 ;
F_18 ( V_8 , & V_74 ) ;
F_7 ( 1 , L_50 , V_28 , V_74 ) ;
* V_168 = V_74 ;
return 0 ;
}
static int F_32 ( struct V_24 * V_25 , int V_169 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
const struct V_1 * V_96 = F_1 ( V_8 -> V_2 ) ;
const struct V_97 * V_98 ;
int V_27 , V_41 ;
T_2 V_155 ;
T_2 V_170 ;
F_44 ( & V_8 -> V_171 ) ;
if ( ! V_169 && F_33 ( V_25 ) == 0 )
return 0 ;
if ( ! V_8 -> V_97 ) {
V_27 = F_45 ( & V_98 , V_96 -> V_51 ,
V_8 -> V_14 . V_16 -> V_172 . V_173 ) ;
if ( V_27 ) {
F_46 ( L_51 , V_27 ) ;
return V_27 ;
}
F_7 ( 1 , L_52 , V_98 -> V_174 ) ;
if ( V_98 -> V_174 != V_96 -> V_174 ) {
F_46 ( L_53 ) ;
F_47 ( V_98 ) ;
return - V_34 ;
}
V_8 -> V_97 = V_98 ;
} else
V_98 = V_8 -> V_97 ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ ) {
if ( V_41 )
F_4 ( V_175 L_54 ) ;
V_27 = F_28 ( V_25 , V_96 , V_98 ) ;
if ( V_27 != 0 )
goto V_176;
F_9 ( 20 ) ;
if ( V_8 -> V_102 ) {
if ( F_5 ( V_8 , V_177 , & V_170 ) ) {
F_4 ( V_17
L_55 ) ;
continue;
}
if ( ! V_170 ) {
F_4 ( V_17
L_56 ,
V_170 ) ;
continue;
}
}
V_27 = F_11 ( V_8 ) ;
if ( V_27 ) {
F_4 ( V_17 L_57 ) ;
continue;
}
F_9 ( 100 ) ;
if ( V_8 -> V_101 ) {
if ( F_5 ( V_8 , V_178 , & V_170 ) ) {
F_4 ( V_17
L_58 ) ;
continue;
}
if ( ! V_170 ) {
F_4 ( V_17
L_59 ,
V_170 ) ;
continue;
}
}
if ( V_8 -> V_99 ) {
F_5 ( V_8 , V_8 -> V_99 ,
& V_155 ) ;
if ( V_155 > 63 ) {
F_4 ( V_17
L_60 ) ;
continue;
}
}
V_27 = F_8 ( V_8 , V_58 , V_57 ) ;
if ( ! V_27 )
break;
F_4 ( V_17 L_61 ) ;
}
V_176:
if ( ! V_27 )
F_4 ( V_179 L_62 ,
V_96 -> V_51 ) ;
else
F_4 ( V_175 L_63 ) ;
return V_27 ;
}
static void F_48 ( struct V_180 * V_171 )
{
struct V_7 * V_8 = F_49 ( V_171 , struct V_7 ,
V_171 . V_181 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
int V_27 ;
F_7 ( 1 , L_3 , V_28 ) ;
V_27 = F_6 ( V_25 ) ;
if ( V_27 != 0 )
F_4 ( V_17
L_64 ,
V_28 ) ;
}
static int F_50 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
if ( V_182 )
return 0 ;
F_51 ( & V_8 -> V_171 ,
F_52 ( V_183 ) ) ;
return 0 ;
}
static int F_53 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 ;
F_7 ( 1 , L_3 , V_28 ) ;
F_44 ( & V_8 -> V_171 ) ;
V_27 = F_6 ( V_25 ) ;
if ( V_27 != 0 )
F_4 ( V_17
L_64 ,
V_28 ) ;
return 0 ;
}
static int F_54 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
if ( ! V_8 -> V_97 )
return 0 ;
return F_38 ( V_25 ) ;
}
static int F_55 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
if ( F_32 ( V_25 , 0 ) != 0 ) {
F_4 ( V_17 L_65 ) ;
return - V_18 ;
}
if ( V_113 )
F_29 ( V_8 ) ;
return 0 ;
}
static void F_56 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
F_57 ( & V_184 ) ;
if ( V_8 ) {
F_44 ( & V_8 -> V_171 ) ;
if ( V_8 -> V_97 ) {
F_47 ( V_8 -> V_97 ) ;
V_8 -> V_97 = NULL ;
}
F_58 ( V_8 ) ;
}
F_59 ( & V_184 ) ;
V_25 -> V_26 = NULL ;
}
static int F_60 ( struct V_24 * V_25 , void * V_185 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
struct V_186 * V_187 = V_185 ;
F_7 ( 1 , L_3 , V_28 ) ;
if ( V_187 -> V_108 )
V_8 -> V_108 = V_187 -> V_108 ;
if ( V_187 -> V_158 )
V_8 -> V_158 = V_187 -> V_158 ;
if ( V_187 -> V_110 )
V_8 -> V_110 = V_187 -> V_110 ;
return 0 ;
}
struct V_24 * F_61 ( struct V_24 * V_25 ,
struct V_188 * V_189 ,
const struct V_186 * V_190 )
{
struct V_7 * V_8 = NULL ;
int V_191 ;
T_2 V_134 = 0 ;
F_7 ( 1 , L_66 , V_28 ,
V_189 ? F_62 ( V_189 ) : - 1 ,
V_190 ? V_190 -> V_192 : - 1 ) ;
F_57 ( & V_184 ) ;
V_191 = F_63 ( struct V_7 , V_8 ,
V_193 ,
V_189 , V_190 -> V_192 , L_67 ) ;
switch ( V_191 ) {
case 0 :
goto V_194;
case 1 :
V_8 -> V_114 = 6000000 ;
V_25 -> V_26 = V_8 ;
V_8 -> V_25 = V_25 ;
F_64 ( & V_8 -> V_171 , F_48 ) ;
break;
default:
V_25 -> V_26 = V_8 ;
break;
}
if ( V_8 -> V_108 == 0 ) {
V_8 -> V_108 = V_190 -> V_108 ;
}
if ( V_8 -> V_95 == 0 )
V_8 -> V_95 = V_190 -> V_95 ;
if ( V_8 -> V_158 == 0 )
V_8 -> V_158 = V_190 -> V_158 ;
if ( ( V_8 -> V_2 == 0 ) || ( V_190 -> V_2 ) )
V_8 -> V_2 = ( V_190 -> V_2 ) ? V_190 -> V_2 : 0 ;
if ( ( V_8 -> V_110 == 0 ) || ( V_190 -> V_110 ) )
V_8 -> V_110 = ( V_190 -> V_110 ) ? V_190 -> V_110 : 0x8a ;
if ( F_5 ( V_8 , V_135 , & V_134 ) != 0 )
goto V_194;
switch ( V_134 ) {
case V_195 :
F_4 ( V_179
L_68 ,
V_190 -> V_192 ) ;
F_4 ( V_179
L_69 ) ;
break;
case V_136 :
F_4 ( V_179
L_68 ,
V_190 -> V_192 ) ;
F_4 ( V_179
L_70 ) ;
break;
default:
F_4 ( V_17
L_71 ,
V_190 -> V_192 , V_134 ) ;
goto V_194;
}
F_59 ( & V_184 ) ;
memcpy ( & V_25 -> V_196 . V_197 , & V_61 ,
sizeof( struct V_198 ) ) ;
return V_25 ;
V_194:
F_59 ( & V_184 ) ;
F_56 ( V_25 ) ;
return NULL ;
}
