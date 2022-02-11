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
return V_18 ;
}
return V_19 ;
}
static int F_5 ( struct V_7 * V_8 , T_2 V_20 , T_2 * V_21 )
{
T_1 V_9 [ 2 ] = { V_20 >> 8 , V_20 & 0xff } ;
T_1 V_22 [ 2 ] = { 0 , 0 } ;
struct V_11 V_12 [ 2 ] = {
{ . V_13 = V_8 -> V_14 . V_13 ,
. V_15 = 0 , . V_9 = & V_9 [ 0 ] , . V_10 = 2 } ,
{ . V_13 = V_8 -> V_14 . V_13 ,
. V_15 = V_23 , . V_9 = & V_22 [ 0 ] , . V_10 = 2 } ,
} ;
if ( F_3 ( V_8 -> V_14 . V_16 , V_12 , 2 ) != 2 ) {
F_4 ( V_24 L_2 ) ;
return - V_25 ;
}
* V_21 = ( V_22 [ 0 ] << 8 ) | V_22 [ 1 ] ;
return V_19 ;
}
static void F_6 ( int V_26 )
{
F_7 ( V_26 ) ;
}
static int F_8 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 ;
F_9 ( 1 , L_3 , V_31 ) ;
if ( V_28 -> V_32 ) {
V_30 = V_28 -> V_32 ( ( ( V_28 -> V_33 ) && ( V_28 -> V_33 -> V_8 ) ) ?
V_28 -> V_33 -> V_8 :
V_8 -> V_14 . V_16 -> V_34 ,
V_35 ,
V_36 , 0 ) ;
if ( V_30 ) {
F_4 ( V_17 L_4 ) ;
return V_37 ;
}
} else {
F_4 ( V_17 L_5 ) ;
return V_37 ;
}
return V_19 ;
}
static int F_10 ( struct V_7 * V_8 , T_2 V_38 , T_2 V_39 )
{
T_1 V_9 [ 4 ] ;
int V_40 = 100 ;
int V_41 ;
V_9 [ 0 ] = ( V_38 >> 8 ) & 0xFF ;
V_9 [ 1 ] = V_38 & 0xFF ;
V_9 [ 2 ] = ( V_39 >> 8 ) & 0xFF ;
V_9 [ 3 ] = V_39 & 0xFF ;
V_41 = F_2 ( V_8 , V_9 , 4 ) ;
if ( V_41 == V_19 ) {
while ( ( V_40 > 0 ) && ( V_41 == V_19 ) ) {
V_41 = F_5 ( V_8 , V_42 , ( T_2 * ) V_9 ) ;
if ( V_41 == V_19 ) {
if ( ( V_9 [ 0 ] == 0 ) && ( V_9 [ 1 ] == 0 ) ) {
break;
} else {
F_6 ( 5 ) ;
V_40 -- ;
}
}
}
}
if ( V_40 <= 0 )
V_41 = V_18 ;
return V_41 ;
}
static int F_11 ( struct V_27 * V_28 , const T_1 * V_43 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_44 , V_45 , V_41 ;
unsigned int V_10 , V_46 , V_47 ;
T_1 V_9 [ V_48 ] ;
V_47 = 0 ;
while ( ( V_43 [ V_47 ] != 0xFF ) ||
( V_43 [ V_47 + 1 ] != 0xFF ) ) {
V_10 = V_43 [ V_47 ] * 256 + V_43 [ V_47 + 1 ] ;
if ( V_10 == 0x0000 ) {
V_41 = F_8 ( V_28 ) ;
V_47 += 2 ;
if ( V_41 != V_19 )
return V_41 ;
} else if ( V_10 & 0x8000 ) {
F_6 ( V_10 & 0x7FFF ) ;
V_47 += 2 ;
} else {
V_47 += 2 ;
V_9 [ 0 ] = V_43 [ V_47 ] ;
V_9 [ 1 ] = V_43 [ V_47 + 1 ] ;
V_46 = 2 ;
while ( V_46 < V_10 ) {
if ( ( V_10 - V_46 ) > V_48 - 2 )
V_45 =
V_48 ;
else
V_45 = ( V_10 - V_46 + 2 ) ;
for ( V_44 = 2 ; V_44 < V_45 ; V_44 ++ ) {
V_9 [ V_44 ] = V_43 [ V_47 + V_46 +
V_44 - 2 ] ;
}
V_41 = F_2 ( V_8 , V_9 ,
V_45 ) ;
if ( V_41 != V_19 )
return V_41 ;
V_46 += V_45 - 2 ;
}
V_47 += V_10 ;
}
}
return V_19 ;
}
static int F_12 ( struct V_7 * V_8 )
{
F_9 ( 1 , L_3 , V_31 ) ;
return F_10 ( V_8 , V_49 , 0 ) ;
}
static int F_13 ( struct V_7 * V_8 ,
T_2 V_50 , T_2 V_51 , T_1 V_52 )
{
int V_30 ;
F_9 ( 1 , L_6 , V_31 , V_50 , V_51 ) ;
if ( V_52 ) {
F_9 ( 1 , L_7 ,
V_31 ,
V_53 [ V_52 ] . V_54 ) ;
} else {
F_9 ( 1 , L_7 ,
V_31 ,
V_53 [ V_8 -> V_55 ] . V_54 ) ;
}
V_30 = F_10 ( V_8 , V_56 , V_50 ) ;
if ( V_30 == V_19 )
V_30 = F_10 ( V_8 , V_57 , V_51 ) ;
return V_30 ;
}
static int F_14 ( struct V_7 * V_8 , T_2 V_58 )
{
F_9 ( 1 , L_8 , V_31 , V_58 ,
V_58 == V_59 ? L_9 : L_10 ) ;
if ( ( V_58 != V_59 ) && ( V_58 != V_60 ) ) {
V_58 = V_60 ;
F_4 ( V_17
L_11 ,
V_31 ) ;
}
return F_10 ( V_8 , V_61 , V_58 ) ;
}
static int F_15 ( struct V_7 * V_8 , T_3 V_62 )
{
T_2 V_63 ;
F_9 ( 1 , L_12 , V_31 , V_62 ) ;
if ( ( V_62 > V_64 . V_65 . V_66 ) ||
( V_62 < V_64 . V_65 . V_67 ) )
return V_68 ;
V_63 = ( T_2 ) ( V_62 / 15625 ) ;
return F_10 ( V_8 , V_69 , V_63 ) ;
}
static int F_16 ( struct V_7 * V_8 , T_3 V_70 )
{
T_3 V_63 = ( V_70 * 1024 ) / 1000 ;
F_9 ( 1 , L_13 ,
V_31 , V_70 , V_63 ) ;
return F_10 ( V_8 , V_71 , V_63 ) ;
}
static int F_17 ( struct V_7 * V_8 , T_2 * V_72 )
{
return F_5 ( V_8 , V_73 , V_72 ) ;
}
static int F_18 ( struct V_7 * V_8 , T_3 * V_74 )
{
int V_41 ;
T_2 V_75 ;
T_3 V_76 ;
V_41 = F_5 ( V_8 , V_77 , & V_75 ) ;
if ( V_41 != V_19 )
return V_41 ;
V_76 = ( T_3 ) V_75 ;
( * V_74 ) = ( V_76 * 15625 ) / 1000 ;
return V_41 ;
}
static int F_19 ( struct V_7 * V_8 , T_2 * V_78 )
{
return F_5 ( V_8 , V_79 , V_78 ) ;
}
static int F_20 ( struct V_7 * V_8 ,
T_1 * V_80 , T_1 * V_81 ,
T_1 * V_82 , T_1 * V_83 )
{
T_2 V_84 ;
int V_41 ;
V_41 = F_5 ( V_8 , V_85 , & V_84 ) ;
if ( V_41 != V_19 )
return V_41 ;
( * V_80 ) = ( V_84 >> 12 ) & 0x0F ;
( * V_81 ) = ( V_84 >> 8 ) & 0x0F ;
( * V_82 ) = ( V_84 >> 4 ) & 0x0F ;
( * V_83 ) = V_84 & 0x0F ;
return 0 ;
}
static int F_21 ( struct V_7 * V_8 , T_2 * V_86 )
{
return F_5 ( V_8 , V_87 , V_86 ) ;
}
static int F_22 ( struct V_7 * V_8 , T_3 * V_88 )
{
T_2 V_75 ;
int V_41 ;
V_41 = F_5 ( V_8 , V_89 , & V_75 ) ;
if ( V_41 != V_19 )
return V_41 ;
( * V_88 ) = ( ( V_75 & 0x0fff ) * 763 ) / 100 ;
return V_41 ;
}
static int F_23 ( struct V_7 * V_8 , T_2 * V_90 )
{
return F_5 ( V_8 , V_91 , V_90 ) ;
}
static int F_24 ( struct V_7 * V_8 , T_2 * V_92 )
{
return F_5 ( V_8 , V_93 , V_92 ) ;
}
static int F_25 ( struct V_7 * V_8 , T_2 * V_94 )
{
return F_5 ( V_8 , V_95 , V_94 ) ;
}
static int F_26 ( struct V_7 * V_8 , T_2 * V_96 )
{
return F_5 ( V_8 , V_97 , V_96 ) ;
}
static T_2 F_27 ( struct V_7 * V_8 )
{
T_2 V_98 = 0 ;
int V_99 = 40 ;
while ( ( V_98 == 0 ) && ( V_99 > 0 ) ) {
F_19 ( V_8 , & V_98 ) ;
if ( V_98 != 1 ) {
F_6 ( 5 ) ;
V_99 -- ;
}
}
return V_98 ;
}
static int F_28 ( struct V_7 * V_8 , T_3 V_62 , int V_100 )
{
int V_101 = 0 ;
F_9 ( 1 , L_12 , V_31 , V_62 ) ;
if ( F_15 ( V_8 , V_62 ) != V_19 )
return 0 ;
if ( V_100 == V_102 ) {
if ( F_27 ( V_8 ) == 1 )
V_101 = 1 ;
}
return V_101 ;
}
static int F_29 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = V_19 ;
switch ( V_8 -> V_2 ) {
default:
case V_3 :
break;
case V_5 :
switch ( V_8 -> V_103 ) {
default:
case 32000 :
break;
case 31875 :
V_30 = F_10 ( V_8 , 0x000f , 0x8081 ) ;
break;
}
break;
}
return V_30 ;
}
static int F_30 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
const struct V_104 * V_105 ;
int V_30 ;
const struct V_1 * V_106 =
F_1 ( V_8 -> V_2 ) ;
V_8 -> V_107 = V_106 -> V_108 ;
V_8 -> V_109 = V_106 -> V_109 ;
V_8 -> V_110 = V_106 -> V_110 ;
F_4 ( V_111 L_14 ,
V_106 -> V_112 ) ;
V_30 = F_31 ( & V_105 , V_106 -> V_112 ,
V_8 -> V_14 . V_16 -> V_113 . V_114 ) ;
if ( V_30 ) {
F_4 ( V_17 L_15 ) ;
V_30 = V_37 ;
goto V_115;
} else {
F_4 ( V_116 L_16 ,
V_105 -> V_117 ) ;
V_30 = V_19 ;
}
if ( V_105 -> V_117 != V_106 -> V_117 ) {
F_4 ( V_17 L_17 ) ;
V_30 = V_37 ;
} else {
F_4 ( V_111 L_18 ) ;
V_30 = F_11 ( V_28 , V_105 -> V_84 ) ;
if ( V_19 == V_30 )
V_30 = F_29 ( V_28 ) ;
if ( V_19 == V_30 )
F_4 ( V_111 L_19 ) ;
else
F_4 ( V_17 L_20 ) ;
}
V_115:
F_32 ( V_105 ) ;
return V_30 ;
}
static void F_33 ( struct V_7 * V_8 )
{
T_2 V_72 ;
T_3 V_74 = 0 ;
T_2 V_78 ;
T_3 V_88 = 0 ;
T_2 V_90 ;
T_2 V_92 ;
T_2 V_94 ;
T_2 V_96 ;
T_1 V_80 = 0 , V_81 = 0 ;
T_1 V_82 = 0 , V_83 = 0 ;
T_2 V_118 = 0 ;
T_2 V_119 ;
F_6 ( 100 ) ;
F_17 ( V_8 , & V_72 ) ;
F_9 ( 1 , L_21 , V_72 ) ;
F_18 ( V_8 , & V_74 ) ;
F_9 ( 1 , L_22 , V_74 ) ;
F_19 ( V_8 , & V_78 ) ;
F_9 ( 1 , L_23 ,
V_78 ) ;
F_20 ( V_8 , & V_80 , & V_81 ,
& V_82 , & V_83 ) ;
F_21 ( V_8 , & V_118 ) ;
F_9 ( 1 , L_24 ,
V_80 , V_81 ,
V_82 , V_83 , V_118 ) ;
F_22 ( V_8 , & V_88 ) ;
F_9 ( 1 , L_25 , V_88 ) ;
F_23 ( V_8 , & V_90 ) ;
F_9 ( 1 , L_26 , V_90 ) ;
F_24 ( V_8 , & V_92 ) ;
F_9 ( 1 , L_27 , V_92 & 0x07 ) ;
F_25 ( V_8 , & V_94 ) ;
F_9 ( 1 , L_28 , V_94 & 0x3f ) ;
F_26 ( V_8 , & V_96 ) ;
F_9 ( 1 , L_29 , V_96 / 256 ,
( V_96 % 256 ) * 100 / 256 ) ;
if ( V_8 -> V_107 ) {
F_5 ( V_8 , V_8 -> V_107 , & V_119 ) ;
F_9 ( 1 , L_30 , V_119 ) ;
}
}
static int F_34 ( struct V_27 * V_28 )
{
int V_30 , V_120 ;
struct V_7 * V_8 = V_28 -> V_29 ;
T_3 V_121 = V_28 -> V_122 . V_123 ;
T_3 V_124 = V_28 -> V_122 . V_125 ;
T_3 V_126 = V_28 -> V_122 . V_127 ;
if ( F_35 ( V_28 , 0 ) != V_19 ) {
F_9 ( 1 , L_31 ) ;
return - V_128 ;
}
F_9 ( 1 , L_32 , V_31 , V_124 ) ;
switch ( V_126 ) {
case V_129 :
F_9 ( 1 , L_33 , V_31 ) ;
V_8 -> V_58 = V_59 ;
V_8 -> V_62 = V_124 - 1750000 ;
V_8 -> V_55 = V_130 ;
break;
case V_131 :
F_9 ( 1 , L_34 , V_31 ) ;
V_8 -> V_58 = V_60 ;
V_8 -> V_62 = V_124 - 1750000 ;
V_8 -> V_55 = V_130 ;
break;
case V_132 :
if ( ! V_121 )
V_121 = 6000000 ;
case V_133 :
case V_134 :
case V_135 :
F_9 ( 1 , L_35 , V_31 ) ;
switch ( V_121 ) {
case 6000000 :
V_8 -> V_55 = V_130 ;
V_8 -> V_62 = V_124 - 1750000 ;
break;
case 7000000 :
V_8 -> V_55 = V_136 ;
V_8 -> V_62 = V_124 - 2250000 ;
break;
case 8000000 :
V_8 -> V_55 = V_137 ;
V_8 -> V_62 = V_124 - 2750000 ;
break;
default:
F_4 ( V_17 L_36 ) ;
return - V_128 ;
}
V_8 -> V_58 = V_59 ;
break;
case V_138 :
case V_139 :
F_9 ( 1 , L_34 , V_31 ) ;
V_8 -> V_58 = V_60 ;
if ( V_121 <= 6000000 ) {
V_8 -> V_55 = V_130 ;
V_8 -> V_62 = V_124 - 1750000 ;
V_120 = 6 ;
} else if ( V_121 <= 7000000 ) {
V_8 -> V_55 = V_136 ;
V_8 -> V_62 = V_124 - 2250000 ;
V_120 = 7 ;
} else {
V_8 -> V_55 = V_140 ;
V_8 -> V_62 = V_124 - 2750000 ;
V_120 = 8 ;
}
F_9 ( 1 , L_37 , V_31 ,
V_120 , V_121 ) ;
break;
default:
F_4 ( V_17 L_38 ) ;
return - V_128 ;
}
F_9 ( 1 , L_39 ,
V_31 , V_124 , V_8 -> V_62 ) ;
V_30 = F_14 ( V_8 , V_8 -> V_58 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17
L_40 ,
V_8 -> V_58 ) ;
return - V_25 ;
}
V_30 = F_13 ( V_8 ,
V_53 [ V_8 -> V_55 ] . V_50 ,
V_53 [ V_8 -> V_55 ] . V_51 , 0 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_41 ) ;
return - V_25 ;
}
V_30 = F_16 ( V_8 , V_8 -> V_141 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_42 ,
V_8 -> V_141 ) ;
return - V_142 ;
}
F_10 ( V_8 , V_143 , 0x8a ) ;
F_28 ( V_8 , V_8 -> V_62 , V_144 ) ;
if ( V_145 )
F_33 ( V_8 ) ;
V_8 -> V_146 = V_121 ;
return 0 ;
}
static int F_36 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 ;
T_2 V_147 ;
V_30 = F_5 ( V_8 , V_148 , & V_147 ) ;
if ( V_30 == V_19 ) {
if ( V_147 == V_149 )
V_30 = V_37 ;
else
V_30 = V_19 ;
}
F_9 ( 1 , L_43 , V_31 ,
V_30 == V_19 ? L_44 : L_45 , V_147 ) ;
return V_30 ;
}
static int F_37 ( struct V_27 * V_28 ,
struct V_150 * V_151 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
T_2 V_152 ;
int V_30 ;
F_9 ( 1 , L_46 ,
V_31 , V_151 -> V_125 ) ;
V_8 -> V_58 = V_151 -> V_100 ;
if ( V_151 -> V_100 > V_60 )
V_8 -> V_58 = V_60 ;
V_8 -> V_62 = V_151 -> V_125 * 62500 ;
if ( V_151 -> V_153 & V_154 ) {
V_8 -> V_55 = V_155 ;
goto V_156;
}
if ( V_151 -> V_153 & V_157 ) {
V_8 -> V_55 = V_158 ;
goto V_156;
}
if ( V_151 -> V_153 & V_159 ) {
V_8 -> V_55 = V_160 ;
goto V_156;
}
if ( V_151 -> V_153 & V_161 ) {
V_8 -> V_55 = V_162 ;
goto V_156;
}
if ( V_151 -> V_153 & V_163 ) {
V_8 -> V_55 = V_164 ;
goto V_156;
}
if ( V_151 -> V_153 & V_165 ) {
V_8 -> V_55 = V_166 ;
goto V_156;
}
if ( V_151 -> V_153 & V_167 ) {
V_8 -> V_55 = V_168 ;
goto V_156;
}
V_156:
V_30 = F_14 ( V_8 , V_8 -> V_58 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17
L_40 ,
V_8 -> V_58 ) ;
return - V_25 ;
}
V_30 = F_13 ( V_8 ,
V_53 [ V_8 -> V_55 ] . V_50 ,
V_53 [ V_8 -> V_55 ] . V_51 , 0 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_41 ) ;
return - V_25 ;
}
F_10 ( V_8 , V_143 , 0x09 ) ;
F_28 ( V_8 , V_8 -> V_62 , V_102 ) ;
if ( V_145 )
F_33 ( V_8 ) ;
if ( V_8 -> V_107 != 0 ) {
F_7 ( 20 ) ;
F_5 ( V_8 , V_8 -> V_107 , & V_152 ) ;
if ( V_152 > 63 ) {
F_9 ( 1 , L_47 ,
V_152 ) ;
if ( F_35 ( V_28 , 1 ) != V_19 ) {
F_4 ( V_17 L_48 ) ;
return - V_25 ;
}
goto V_156;
}
}
return 0 ;
}
static int F_38 ( struct V_27 * V_28 ,
struct V_150 * V_151 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = - V_128 ;
T_1 V_169 ;
F_9 ( 1 , L_49 ,
V_31 , V_151 -> V_125 ) ;
if ( V_8 -> V_169 == V_170 ) {
F_9 ( 1 , L_50 , V_31 ) ;
return - V_128 ;
}
if ( V_8 -> V_169 == V_171 )
V_169 = V_172 ;
else if ( V_8 -> V_169 == V_173 )
V_169 = V_174 ;
else if ( V_8 -> V_169 == V_175 )
V_169 = V_176 ;
else {
F_9 ( 1 , L_51 , V_31 ,
V_8 -> V_169 ) ;
return - V_128 ;
}
V_8 -> V_62 = V_151 -> V_125 * 125 / 2 ;
V_8 -> V_58 = V_59 ;
V_30 = F_13 ( V_8 , V_53 [ V_169 ] . V_50 ,
V_53 [ V_169 ] . V_51 , V_169 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_41 ) ;
return - V_25 ;
}
V_30 = F_14 ( V_8 , V_8 -> V_58 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17
L_40 ,
V_8 -> V_58 ) ;
return - V_25 ;
}
if ( ( V_8 -> V_169 == V_171 ) ||
( V_8 -> V_169 == V_173 ) )
F_10 ( V_8 , V_143 , 0x09 ) ;
else if ( V_8 -> V_169 == V_175 )
F_10 ( V_8 , V_143 , 0x06 ) ;
F_28 ( V_8 , V_8 -> V_62 , V_102 ) ;
return 0 ;
}
static int F_39 ( struct V_27 * V_28 ,
struct V_150 * V_151 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = - V_128 ;
if ( V_8 -> V_14 . V_16 == NULL )
return - V_128 ;
if ( F_35 ( V_28 , 0 ) != V_19 ) {
F_9 ( 1 , L_31 ) ;
return - V_128 ;
}
switch ( V_151 -> V_100 ) {
case V_177 :
V_30 = F_38 ( V_28 , V_151 ) ;
break;
case V_178 :
case V_179 :
V_30 = F_37 ( V_28 , V_151 ) ;
break;
}
return V_30 ;
}
static int F_40 ( struct V_27 * V_28 , T_3 * V_124 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
* V_124 = V_8 -> V_62 ;
return 0 ;
}
static int F_41 ( struct V_27 * V_28 , T_3 * V_124 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
* V_124 = V_8 -> V_141 * 1000 ;
return 0 ;
}
static int F_42 ( struct V_27 * V_28 , T_3 * V_121 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
* V_121 = V_8 -> V_146 ;
return 0 ;
}
static int F_43 ( struct V_27 * V_28 , T_3 * V_180 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
T_2 V_78 = 0 ;
F_19 ( V_8 , & V_78 ) ;
F_9 ( 1 , L_52 , V_31 , V_78 ) ;
* V_180 = V_78 ;
return 0 ;
}
static int F_35 ( struct V_27 * V_28 , int V_181 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = V_19 ;
T_2 V_152 ;
T_2 V_182 ;
if ( V_181 || F_36 ( V_28 ) != V_19 ) {
V_183:
V_30 = F_30 ( V_28 ) ;
if ( V_30 != V_19 )
return V_30 ;
F_7 ( 20 ) ;
if ( V_8 -> V_110 ) {
if ( F_5 ( V_8 , V_184 , & V_182 )
!= V_19 ) {
F_9 ( 1 , L_53 ,
V_31 ) ;
goto V_183;
}
if ( V_182 == 0 ) {
F_9 ( 1 , L_54 ,
V_31 , V_182 ) ;
goto V_183;
}
}
V_30 |= F_12 ( V_8 ) ;
if ( V_30 != V_19 )
goto V_183;
F_6 ( 100 ) ;
if ( V_8 -> V_109 ) {
if ( F_5 ( V_8 , V_185 , & V_182 ) != V_19 ) {
F_9 ( 1 , L_55 ,
V_31 ) ;
goto V_183;
}
if ( V_182 == 0 ) {
F_9 ( 1 , L_56 , V_31 , V_182 ) ;
goto V_183;
}
}
if ( V_8 -> V_107 ) {
F_5 ( V_8 , V_8 -> V_107 ,
& V_152 ) ;
if ( V_152 > 63 ) {
F_4 ( V_17 L_57 ) ;
goto V_183;
}
}
V_30 |= F_10 ( V_8 , V_61 , V_60 ) ;
}
return V_30 ;
}
static int F_44 ( struct V_27 * V_28 )
{
int V_30 ;
F_9 ( 1 , L_3 , V_31 ) ;
if ( V_186 )
return 0 ;
V_30 = F_8 ( V_28 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17
L_58 ,
V_31 ) ;
return - V_25 ;
} else
return V_19 ;
}
static int F_45 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
if ( F_35 ( V_28 , 0 ) != V_19 ) {
F_4 ( V_17 L_59 ) ;
return - V_25 ;
}
if ( V_145 )
F_33 ( V_8 ) ;
return 0 ;
}
static int F_46 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
F_47 ( & V_187 ) ;
if ( V_8 )
F_48 ( V_8 ) ;
F_49 ( & V_187 ) ;
V_28 -> V_29 = NULL ;
return 0 ;
}
static int F_50 ( struct V_27 * V_28 , void * V_188 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
struct V_189 * V_190 = V_188 ;
F_9 ( 1 , L_3 , V_31 ) ;
if ( V_190 -> V_141 )
V_8 -> V_141 = V_190 -> V_141 ;
if ( V_190 -> V_169 )
V_8 -> V_169 = V_190 -> V_169 ;
return 0 ;
}
struct V_27 * F_51 ( struct V_27 * V_28 ,
struct V_191 * V_192 ,
const struct V_189 * V_193 )
{
struct V_7 * V_8 = NULL ;
int V_194 ;
T_2 V_147 = 0 ;
F_9 ( 1 , L_60 , V_31 ,
V_192 ? F_52 ( V_192 ) : - 1 ,
V_193 ? V_193 -> V_195 : - 1 ) ;
F_47 ( & V_187 ) ;
V_194 = F_53 ( struct V_7 , V_8 ,
V_196 ,
V_192 , V_193 -> V_195 , L_61 ) ;
switch ( V_194 ) {
case 0 :
goto V_197;
break;
case 1 :
V_8 -> V_146 = 6000000 ;
V_28 -> V_29 = V_8 ;
break;
default:
V_28 -> V_29 = V_8 ;
break;
}
if ( V_8 -> V_141 == 0 ) {
V_8 -> V_141 = V_193 -> V_141 ;
}
if ( V_8 -> V_103 == 0 )
V_8 -> V_103 = V_193 -> V_103 ;
if ( V_8 -> V_169 == 0 )
V_8 -> V_169 = V_193 -> V_169 ;
if ( ( V_8 -> V_2 == 0 ) || ( V_193 -> V_2 ) )
V_8 -> V_2 = ( V_193 -> V_2 ) ? V_193 -> V_2 : 0 ;
if ( F_5 ( V_8 , V_148 , & V_147 ) != V_19 )
goto V_197;
switch ( V_147 ) {
case V_198 :
F_4 ( V_111
L_62 ,
V_193 -> V_195 ) ;
F_4 ( V_111
L_63 ) ;
break;
case V_149 :
F_4 ( V_111
L_62 ,
V_193 -> V_195 ) ;
F_4 ( V_111
L_64 ) ;
break;
default:
F_4 ( V_17
L_65 ,
V_193 -> V_195 , V_147 ) ;
goto V_197;
}
F_49 ( & V_187 ) ;
memcpy ( & V_28 -> V_199 . V_200 , & V_64 ,
sizeof( struct V_201 ) ) ;
return V_28 ;
V_197:
F_49 ( & V_187 ) ;
F_46 ( V_28 ) ;
return NULL ;
}
