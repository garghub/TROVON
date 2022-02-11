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
T_2 V_50 , T_2 V_51 )
{
int V_30 ;
F_9 ( 1 , L_6 , V_31 , V_50 , V_51 ) ;
F_9 ( 1 , L_7 ,
V_31 ,
V_52 [ V_8 -> V_53 ] . V_54 ) ;
V_30 = F_10 ( V_8 , V_55 , V_50 ) ;
if ( V_30 == V_19 )
V_30 = F_10 ( V_8 , V_56 , V_51 ) ;
return V_30 ;
}
static int F_14 ( struct V_7 * V_8 , T_2 V_57 )
{
F_9 ( 1 , L_8 , V_31 , V_57 ,
V_57 == V_58 ? L_9 : L_10 ) ;
if ( ( V_57 != V_58 ) && ( V_57 != V_59 ) ) {
V_57 = V_59 ;
F_4 ( V_17
L_11 ,
V_31 ) ;
}
return F_10 ( V_8 , V_60 , V_57 ) ;
}
static int F_15 ( struct V_7 * V_8 , T_3 V_61 )
{
T_2 V_62 ;
F_9 ( 1 , L_12 , V_31 , V_61 ) ;
if ( ( V_61 > V_63 . V_64 . V_65 ) ||
( V_61 < V_63 . V_64 . V_66 ) )
return V_67 ;
V_62 = ( T_2 ) ( V_61 / 15625 ) ;
return F_10 ( V_8 , V_68 , V_62 ) ;
}
static int F_16 ( struct V_7 * V_8 , T_3 V_69 )
{
T_3 V_62 = ( V_69 * 1024 ) / 1000 ;
F_9 ( 1 , L_13 ,
V_31 , V_69 , V_62 ) ;
return F_10 ( V_8 , V_70 , V_62 ) ;
}
static int F_17 ( struct V_7 * V_8 , T_2 * V_71 )
{
return F_5 ( V_8 , V_72 , V_71 ) ;
}
static int F_18 ( struct V_7 * V_8 , T_3 * V_73 )
{
int V_41 ;
T_2 V_74 ;
T_3 V_75 ;
V_41 = F_5 ( V_8 , V_76 , & V_74 ) ;
if ( V_41 != V_19 )
return V_41 ;
V_75 = ( T_3 ) V_74 ;
( * V_73 ) = ( V_75 * 15625 ) / 1000 ;
return V_41 ;
}
static int F_19 ( struct V_7 * V_8 , T_2 * V_77 )
{
return F_5 ( V_8 , V_78 , V_77 ) ;
}
static int F_20 ( struct V_7 * V_8 ,
T_1 * V_79 , T_1 * V_80 ,
T_1 * V_81 , T_1 * V_82 )
{
T_2 V_83 ;
int V_41 ;
V_41 = F_5 ( V_8 , V_84 , & V_83 ) ;
if ( V_41 != V_19 )
return V_41 ;
( * V_79 ) = ( V_83 >> 12 ) & 0x0F ;
( * V_80 ) = ( V_83 >> 8 ) & 0x0F ;
( * V_81 ) = ( V_83 >> 4 ) & 0x0F ;
( * V_82 ) = V_83 & 0x0F ;
return 0 ;
}
static int F_21 ( struct V_7 * V_8 , T_2 * V_85 )
{
return F_5 ( V_8 , V_86 , V_85 ) ;
}
static int F_22 ( struct V_7 * V_8 , T_3 * V_87 )
{
T_2 V_74 ;
int V_41 ;
V_41 = F_5 ( V_8 , V_88 , & V_74 ) ;
if ( V_41 != V_19 )
return V_41 ;
( * V_87 ) = ( ( V_74 & 0x0fff ) * 763 ) / 100 ;
return V_41 ;
}
static int F_23 ( struct V_7 * V_8 , T_2 * V_89 )
{
return F_5 ( V_8 , V_90 , V_89 ) ;
}
static int F_24 ( struct V_7 * V_8 , T_2 * V_91 )
{
return F_5 ( V_8 , V_92 , V_91 ) ;
}
static int F_25 ( struct V_7 * V_8 , T_2 * V_93 )
{
return F_5 ( V_8 , V_94 , V_93 ) ;
}
static int F_26 ( struct V_7 * V_8 , T_2 * V_95 )
{
return F_5 ( V_8 , V_96 , V_95 ) ;
}
static T_2 F_27 ( struct V_7 * V_8 )
{
T_2 V_97 = 0 ;
int V_98 = 40 ;
while ( ( V_97 == 0 ) && ( V_98 > 0 ) ) {
F_19 ( V_8 , & V_97 ) ;
if ( V_97 != 1 ) {
F_6 ( 5 ) ;
V_98 -- ;
}
}
return V_97 ;
}
static int F_28 ( struct V_7 * V_8 , T_3 V_61 , int V_99 )
{
int V_100 = 0 ;
F_9 ( 1 , L_12 , V_31 , V_61 ) ;
if ( F_15 ( V_8 , V_61 ) != V_19 )
return 0 ;
if ( V_99 == V_101 ) {
if ( F_27 ( V_8 ) == 1 )
V_100 = 1 ;
}
return V_100 ;
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
switch ( V_8 -> V_102 ) {
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
const struct V_103 * V_104 ;
int V_30 ;
const struct V_1 * V_105 =
F_1 ( V_8 -> V_2 ) ;
V_8 -> V_106 = V_105 -> V_107 ;
V_8 -> V_108 = V_105 -> V_108 ;
V_8 -> V_109 = V_105 -> V_109 ;
F_4 ( V_110 L_14 ,
V_105 -> V_111 ) ;
V_30 = F_31 ( & V_104 , V_105 -> V_111 ,
V_8 -> V_14 . V_16 -> V_112 . V_113 ) ;
if ( V_30 ) {
F_4 ( V_17 L_15 ) ;
V_30 = V_37 ;
goto V_114;
} else {
F_4 ( V_115 L_16 ,
V_104 -> V_116 ) ;
V_30 = V_19 ;
}
if ( V_104 -> V_116 != V_105 -> V_116 ) {
F_4 ( V_17 L_17 ) ;
V_30 = V_37 ;
} else {
F_4 ( V_110 L_18 ) ;
V_30 = F_11 ( V_28 , V_104 -> V_83 ) ;
if ( V_19 == V_30 )
V_30 = F_29 ( V_28 ) ;
if ( V_19 == V_30 )
F_4 ( V_110 L_19 ) ;
else
F_4 ( V_17 L_20 ) ;
}
V_114:
F_32 ( V_104 ) ;
return V_30 ;
}
static void F_33 ( struct V_7 * V_8 )
{
T_2 V_71 ;
T_3 V_73 = 0 ;
T_2 V_77 ;
T_3 V_87 = 0 ;
T_2 V_89 ;
T_2 V_91 ;
T_2 V_93 ;
T_2 V_95 ;
T_1 V_79 = 0 , V_80 = 0 ;
T_1 V_81 = 0 , V_82 = 0 ;
T_2 V_117 = 0 ;
T_2 V_118 ;
F_6 ( 100 ) ;
F_17 ( V_8 , & V_71 ) ;
F_9 ( 1 , L_21 , V_71 ) ;
F_18 ( V_8 , & V_73 ) ;
F_9 ( 1 , L_22 , V_73 ) ;
F_19 ( V_8 , & V_77 ) ;
F_9 ( 1 , L_23 ,
V_77 ) ;
F_20 ( V_8 , & V_79 , & V_80 ,
& V_81 , & V_82 ) ;
F_21 ( V_8 , & V_117 ) ;
F_9 ( 1 , L_24 ,
V_79 , V_80 ,
V_81 , V_82 , V_117 ) ;
F_22 ( V_8 , & V_87 ) ;
F_9 ( 1 , L_25 , V_87 ) ;
F_23 ( V_8 , & V_89 ) ;
F_9 ( 1 , L_26 , V_89 ) ;
F_24 ( V_8 , & V_91 ) ;
F_9 ( 1 , L_27 , V_91 & 0x07 ) ;
F_25 ( V_8 , & V_93 ) ;
F_9 ( 1 , L_28 , V_93 & 0x3f ) ;
F_26 ( V_8 , & V_95 ) ;
F_9 ( 1 , L_29 , V_95 / 256 ,
( V_95 % 256 ) * 100 / 256 ) ;
if ( V_8 -> V_106 ) {
F_5 ( V_8 , V_8 -> V_106 , & V_118 ) ;
F_9 ( 1 , L_30 , V_118 ) ;
}
}
static int F_34 ( struct V_27 * V_28 )
{
int V_30 , V_119 ;
struct V_7 * V_8 = V_28 -> V_29 ;
T_3 V_120 = V_28 -> V_121 . V_122 ;
T_3 V_123 = V_28 -> V_121 . V_124 ;
T_3 V_125 = V_28 -> V_121 . V_126 ;
if ( F_35 ( V_28 , 0 ) != V_19 ) {
F_9 ( 1 , L_31 ) ;
return - V_127 ;
}
F_9 ( 1 , L_32 , V_31 , V_123 ) ;
switch ( V_125 ) {
case V_128 :
F_9 ( 1 , L_33 , V_31 ) ;
V_8 -> V_57 = V_58 ;
V_8 -> V_61 = V_123 - 1750000 ;
V_8 -> V_53 = V_129 ;
break;
case V_130 :
F_9 ( 1 , L_34 , V_31 ) ;
V_8 -> V_57 = V_59 ;
V_8 -> V_61 = V_123 - 1750000 ;
V_8 -> V_53 = V_129 ;
break;
case V_131 :
if ( ! V_120 )
V_120 = 6000000 ;
case V_132 :
case V_133 :
case V_134 :
F_9 ( 1 , L_35 , V_31 ) ;
switch ( V_120 ) {
case 6000000 :
V_8 -> V_53 = V_129 ;
V_8 -> V_61 = V_123 - 1750000 ;
break;
case 7000000 :
V_8 -> V_53 = V_135 ;
V_8 -> V_61 = V_123 - 2250000 ;
break;
case 8000000 :
V_8 -> V_53 = V_136 ;
V_8 -> V_61 = V_123 - 2750000 ;
break;
default:
F_4 ( V_17 L_36 ) ;
return - V_127 ;
}
V_8 -> V_57 = V_58 ;
case V_137 :
case V_138 :
F_9 ( 1 , L_34 , V_31 ) ;
V_8 -> V_57 = V_59 ;
if ( V_120 <= 6000000 ) {
V_8 -> V_53 = V_129 ;
V_8 -> V_61 = V_123 - 1750000 ;
V_119 = 6 ;
} else if ( V_120 <= 7000000 ) {
V_8 -> V_53 = V_135 ;
V_8 -> V_61 = V_123 - 2250000 ;
V_119 = 7 ;
} else {
V_8 -> V_53 = V_139 ;
V_8 -> V_61 = V_123 - 2750000 ;
V_119 = 8 ;
}
F_9 ( 1 , L_37 , V_31 ,
V_119 , V_120 ) ;
break;
default:
F_4 ( V_17 L_38 ) ;
return - V_127 ;
}
F_9 ( 1 , L_39 ,
V_31 , V_123 , V_8 -> V_61 ) ;
V_30 = F_14 ( V_8 , V_8 -> V_57 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17
L_40 ,
V_8 -> V_57 ) ;
return - V_25 ;
}
V_30 = F_13 ( V_8 ,
V_52 [ V_8 -> V_53 ] . V_50 ,
V_52 [ V_8 -> V_53 ] . V_51 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_41 ) ;
return - V_25 ;
}
V_30 = F_16 ( V_8 , V_8 -> V_140 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_42 ,
V_8 -> V_140 ) ;
return - V_141 ;
}
F_10 ( V_8 , V_142 , 0x8a ) ;
F_28 ( V_8 , V_8 -> V_61 , V_143 ) ;
if ( V_144 )
F_33 ( V_8 ) ;
V_8 -> V_145 = V_120 ;
return 0 ;
}
static int F_36 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 ;
T_2 V_146 ;
V_30 = F_5 ( V_8 , V_147 , & V_146 ) ;
if ( V_30 == V_19 ) {
if ( V_146 == V_148 )
V_30 = V_37 ;
else
V_30 = V_19 ;
}
F_9 ( 1 , L_43 , V_31 ,
V_30 == V_19 ? L_44 : L_45 , V_146 ) ;
return V_30 ;
}
static int F_37 ( struct V_27 * V_28 ,
struct V_149 * V_150 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
T_2 V_151 ;
int V_30 ;
F_9 ( 1 , L_46 ,
V_31 , V_150 -> V_124 ) ;
V_8 -> V_57 = V_150 -> V_99 ;
if ( V_150 -> V_99 > V_59 )
V_8 -> V_57 = V_59 ;
V_8 -> V_61 = V_150 -> V_124 * 62500 ;
if ( V_150 -> V_152 & V_153 ) {
V_8 -> V_53 = V_154 ;
goto V_155;
}
if ( V_150 -> V_152 & V_156 ) {
V_8 -> V_53 = V_157 ;
goto V_155;
}
if ( V_150 -> V_152 & V_158 ) {
V_8 -> V_53 = V_159 ;
goto V_155;
}
if ( V_150 -> V_152 & V_160 ) {
V_8 -> V_53 = V_161 ;
goto V_155;
}
if ( V_150 -> V_152 & V_162 ) {
V_8 -> V_53 = V_163 ;
goto V_155;
}
if ( V_150 -> V_152 & V_164 ) {
V_8 -> V_53 = V_165 ;
goto V_155;
}
if ( V_150 -> V_152 & V_166 ) {
V_8 -> V_53 = V_167 ;
goto V_155;
}
V_155:
V_30 = F_14 ( V_8 , V_8 -> V_57 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17
L_40 ,
V_8 -> V_57 ) ;
return - V_25 ;
}
V_30 = F_13 ( V_8 ,
V_52 [ V_8 -> V_53 ] . V_50 ,
V_52 [ V_8 -> V_53 ] . V_51 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_41 ) ;
return - V_25 ;
}
F_10 ( V_8 , V_142 , 0x09 ) ;
F_28 ( V_8 , V_8 -> V_61 , V_101 ) ;
if ( V_144 )
F_33 ( V_8 ) ;
if ( V_8 -> V_106 != 0 ) {
F_7 ( 20 ) ;
F_5 ( V_8 , V_8 -> V_106 , & V_151 ) ;
if ( V_151 > 63 ) {
F_9 ( 1 , L_47 ,
V_151 ) ;
if ( F_35 ( V_28 , 1 ) != V_19 ) {
F_4 ( V_17 L_48 ) ;
return - V_25 ;
}
goto V_155;
}
}
return 0 ;
}
static int F_38 ( struct V_27 * V_28 ,
struct V_149 * V_150 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = - V_127 ;
T_1 V_168 ;
F_9 ( 1 , L_49 ,
V_31 , V_150 -> V_124 ) ;
if ( V_8 -> V_168 == V_169 ) {
F_9 ( 1 , L_50 , V_31 ) ;
return - V_127 ;
}
if ( V_8 -> V_168 == V_170 )
V_168 = V_171 ;
else if ( V_8 -> V_168 == V_172 )
V_168 = V_173 ;
else if ( V_8 -> V_168 == V_174 )
V_168 = V_175 ;
else {
F_9 ( 1 , L_51 , V_31 ,
V_8 -> V_168 ) ;
return - V_127 ;
}
V_8 -> V_61 = V_150 -> V_124 * 125 / 2 ;
V_8 -> V_57 = V_58 ;
V_30 = F_13 ( V_8 , V_52 [ V_168 ] . V_50 ,
V_52 [ V_168 ] . V_51 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_41 ) ;
return - V_25 ;
}
V_30 = F_14 ( V_8 , V_8 -> V_57 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17
L_40 ,
V_8 -> V_57 ) ;
return - V_25 ;
}
if ( ( V_8 -> V_168 == V_170 ) ||
( V_8 -> V_168 == V_172 ) )
F_10 ( V_8 , V_142 , 0x09 ) ;
else if ( V_8 -> V_168 == V_174 )
F_10 ( V_8 , V_142 , 0x06 ) ;
F_28 ( V_8 , V_8 -> V_61 , V_101 ) ;
return 0 ;
}
static int F_39 ( struct V_27 * V_28 ,
struct V_149 * V_150 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = - V_127 ;
if ( V_8 -> V_14 . V_16 == NULL )
return - V_127 ;
if ( F_35 ( V_28 , 0 ) != V_19 ) {
F_9 ( 1 , L_31 ) ;
return - V_127 ;
}
switch ( V_150 -> V_99 ) {
case V_176 :
V_30 = F_38 ( V_28 , V_150 ) ;
break;
case V_177 :
case V_178 :
V_30 = F_37 ( V_28 , V_150 ) ;
break;
}
return V_30 ;
}
static int F_40 ( struct V_27 * V_28 , T_3 * V_123 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
* V_123 = V_8 -> V_61 ;
return 0 ;
}
static int F_41 ( struct V_27 * V_28 , T_3 * V_123 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
* V_123 = V_8 -> V_140 * 1000 ;
return 0 ;
}
static int F_42 ( struct V_27 * V_28 , T_3 * V_120 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
* V_120 = V_8 -> V_145 ;
return 0 ;
}
static int F_43 ( struct V_27 * V_28 , T_3 * V_179 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
T_2 V_77 = 0 ;
F_19 ( V_8 , & V_77 ) ;
F_9 ( 1 , L_52 , V_31 , V_77 ) ;
* V_179 = V_77 ;
return 0 ;
}
static int F_35 ( struct V_27 * V_28 , int V_180 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = V_19 ;
T_2 V_151 ;
T_2 V_181 ;
if ( V_180 || F_36 ( V_28 ) != V_19 ) {
V_182:
V_30 = F_30 ( V_28 ) ;
if ( V_30 != V_19 )
return V_30 ;
F_7 ( 20 ) ;
if ( V_8 -> V_109 ) {
if ( F_5 ( V_8 , V_183 , & V_181 )
!= V_19 ) {
F_9 ( 1 , L_53 ,
V_31 ) ;
goto V_182;
}
if ( V_181 == 0 ) {
F_9 ( 1 , L_54 ,
V_31 , V_181 ) ;
goto V_182;
}
}
V_30 |= F_12 ( V_8 ) ;
if ( V_30 != V_19 )
goto V_182;
F_6 ( 100 ) ;
if ( V_8 -> V_108 ) {
if ( F_5 ( V_8 , V_184 , & V_181 ) != V_19 ) {
F_9 ( 1 , L_55 ,
V_31 ) ;
goto V_182;
}
if ( V_181 == 0 ) {
F_9 ( 1 , L_56 , V_31 , V_181 ) ;
goto V_182;
}
}
if ( V_8 -> V_106 ) {
F_5 ( V_8 , V_8 -> V_106 ,
& V_151 ) ;
if ( V_151 > 63 ) {
F_4 ( V_17 L_57 ) ;
goto V_182;
}
}
V_30 |= F_10 ( V_8 , V_60 , V_59 ) ;
}
return V_30 ;
}
static int F_44 ( struct V_27 * V_28 )
{
int V_30 ;
F_9 ( 1 , L_3 , V_31 ) ;
if ( V_185 )
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
if ( V_144 )
F_33 ( V_8 ) ;
return 0 ;
}
static int F_46 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
F_47 ( & V_186 ) ;
if ( V_8 )
F_48 ( V_8 ) ;
F_49 ( & V_186 ) ;
V_28 -> V_29 = NULL ;
return 0 ;
}
static int F_50 ( struct V_27 * V_28 , void * V_187 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
struct V_188 * V_189 = V_187 ;
F_9 ( 1 , L_3 , V_31 ) ;
if ( V_189 -> V_140 )
V_8 -> V_140 = V_189 -> V_140 ;
if ( V_189 -> V_168 )
V_8 -> V_168 = V_189 -> V_168 ;
return 0 ;
}
struct V_27 * F_51 ( struct V_27 * V_28 ,
struct V_190 * V_191 ,
const struct V_188 * V_192 )
{
struct V_7 * V_8 = NULL ;
int V_193 ;
T_2 V_146 = 0 ;
F_9 ( 1 , L_60 , V_31 ,
V_191 ? F_52 ( V_191 ) : - 1 ,
V_192 ? V_192 -> V_194 : - 1 ) ;
F_47 ( & V_186 ) ;
V_193 = F_53 ( struct V_7 , V_8 ,
V_195 ,
V_191 , V_192 -> V_194 , L_61 ) ;
switch ( V_193 ) {
case 0 :
goto V_196;
break;
case 1 :
V_8 -> V_145 = 6000000 ;
V_28 -> V_29 = V_8 ;
break;
default:
V_28 -> V_29 = V_8 ;
break;
}
if ( V_8 -> V_140 == 0 ) {
V_8 -> V_140 = V_192 -> V_140 ;
}
if ( V_8 -> V_102 == 0 )
V_8 -> V_102 = V_192 -> V_102 ;
if ( V_8 -> V_168 == 0 )
V_8 -> V_168 = V_192 -> V_168 ;
if ( ( V_8 -> V_2 == 0 ) || ( V_192 -> V_2 ) )
V_8 -> V_2 = ( V_192 -> V_2 ) ? V_192 -> V_2 : 0 ;
if ( F_5 ( V_8 , V_147 , & V_146 ) != V_19 )
goto V_196;
switch ( V_146 ) {
case V_197 :
F_4 ( V_110
L_62 ,
V_192 -> V_194 ) ;
F_4 ( V_110
L_63 ) ;
break;
case V_148 :
F_4 ( V_110
L_62 ,
V_192 -> V_194 ) ;
F_4 ( V_110
L_64 ) ;
break;
default:
F_4 ( V_17
L_65 ,
V_192 -> V_194 , V_146 ) ;
goto V_196;
}
F_49 ( & V_186 ) ;
memcpy ( & V_28 -> V_198 . V_199 , & V_63 ,
sizeof( struct V_200 ) ) ;
return V_28 ;
V_196:
F_49 ( & V_186 ) ;
F_46 ( V_28 ) ;
return NULL ;
}
