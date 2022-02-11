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
static T_2 F_26 ( struct V_7 * V_8 )
{
T_2 V_94 = 0 ;
int V_95 = 40 ;
while ( ( V_94 == 0 ) && ( V_95 > 0 ) ) {
F_18 ( V_8 , & V_94 ) ;
if ( V_94 != 1 ) {
F_9 ( 5 ) ;
V_95 -- ;
}
}
return V_94 ;
}
static int F_27 ( struct V_7 * V_8 , T_3 V_59 , int V_96 )
{
int V_97 = 0 ;
F_7 ( 1 , L_12 , V_28 , V_59 ) ;
if ( F_14 ( V_8 , V_59 ) != 0 )
return 0 ;
if ( V_96 == V_98 ) {
if ( F_26 ( V_8 ) == 1 )
V_97 = 1 ;
}
return V_97 ;
}
static int F_28 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 = 0 ;
switch ( V_8 -> V_2 ) {
default:
case V_3 :
break;
case V_5 :
switch ( V_8 -> V_99 ) {
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
static int F_29 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
const struct V_100 * V_101 ;
int V_27 ;
const struct V_1 * V_102 =
F_1 ( V_8 -> V_2 ) ;
V_8 -> V_103 = V_102 -> V_104 ;
V_8 -> V_105 = V_102 -> V_105 ;
V_8 -> V_106 = V_102 -> V_106 ;
F_4 ( V_107 L_14 ,
V_102 -> V_51 ) ;
V_27 = F_30 ( & V_101 , V_102 -> V_51 ,
V_8 -> V_14 . V_16 -> V_108 . V_109 ) ;
if ( V_27 ) {
F_4 ( V_17 L_15 ) ;
goto V_110;
} else {
F_4 ( V_111 L_16 ,
V_101 -> V_112 ) ;
V_27 = 0 ;
}
if ( V_101 -> V_112 != V_102 -> V_112 ) {
F_4 ( V_17 L_17 ) ;
V_27 = - V_34 ;
} else {
F_4 ( V_107 L_18 ) ;
V_27 = F_10 ( V_25 , V_101 -> V_80 ) ;
if ( 0 == V_27 )
V_27 = F_28 ( V_25 ) ;
if ( 0 == V_27 )
F_4 ( V_107 L_19 ) ;
else
F_4 ( V_17 L_20 ) ;
}
V_110:
F_31 ( V_101 ) ;
return V_27 ;
}
static void F_32 ( struct V_7 * V_8 )
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
T_2 V_113 = 0 ;
T_2 V_114 ;
F_9 ( 100 ) ;
F_16 ( V_8 , & V_68 ) ;
F_7 ( 1 , L_21 , V_68 ) ;
F_17 ( V_8 , & V_70 ) ;
F_7 ( 1 , L_22 , V_70 ) ;
F_18 ( V_8 , & V_74 ) ;
F_7 ( 1 , L_23 ,
V_74 ) ;
F_19 ( V_8 , & V_76 , & V_77 ,
& V_78 , & V_79 ) ;
F_20 ( V_8 , & V_113 ) ;
F_7 ( 1 , L_24 ,
V_76 , V_77 ,
V_78 , V_79 , V_113 ) ;
F_21 ( V_8 , & V_84 ) ;
F_7 ( 1 , L_25 , V_84 ) ;
F_22 ( V_8 , & V_86 ) ;
F_7 ( 1 , L_26 , V_86 ) ;
F_23 ( V_8 , & V_88 ) ;
F_7 ( 1 , L_27 , V_88 & 0x07 ) ;
F_24 ( V_8 , & V_90 ) ;
F_7 ( 1 , L_28 , V_90 & 0x3f ) ;
F_25 ( V_8 , & V_92 ) ;
F_7 ( 1 , L_29 , V_92 / 256 ,
( V_92 % 256 ) * 100 / 256 ) ;
if ( V_8 -> V_103 ) {
F_5 ( V_8 , V_8 -> V_103 , & V_114 ) ;
F_7 ( 1 , L_30 , V_114 ) ;
}
}
static int F_33 ( struct V_24 * V_25 )
{
int V_27 , V_115 ;
struct V_7 * V_8 = V_25 -> V_26 ;
T_3 V_116 = V_25 -> V_117 . V_118 ;
T_3 V_119 = V_25 -> V_117 . V_120 ;
T_3 V_121 = V_25 -> V_117 . V_122 ;
if ( F_34 ( V_25 , 0 ) != 0 ) {
F_7 ( 1 , L_31 ) ;
return - V_34 ;
}
F_7 ( 1 , L_32 , V_28 , V_119 ) ;
switch ( V_121 ) {
case V_123 :
F_7 ( 1 , L_33 , V_28 ) ;
V_8 -> V_55 = V_56 ;
V_8 -> V_59 = V_119 - 1750000 ;
V_8 -> V_52 = V_124 ;
break;
case V_125 :
F_7 ( 1 , L_34 , V_28 ) ;
V_8 -> V_55 = V_57 ;
V_8 -> V_59 = V_119 - 1750000 ;
V_8 -> V_52 = V_124 ;
break;
case V_126 :
if ( ! V_116 )
V_116 = 6000000 ;
case V_127 :
case V_128 :
case V_129 :
F_7 ( 1 , L_35 , V_28 ) ;
switch ( V_116 ) {
case 6000000 :
V_8 -> V_52 = V_124 ;
V_8 -> V_59 = V_119 - 1750000 ;
break;
case 7000000 :
V_8 -> V_52 = V_130 ;
V_8 -> V_59 = V_119 - 2250000 ;
break;
case 8000000 :
V_8 -> V_52 = V_131 ;
V_8 -> V_59 = V_119 - 2750000 ;
break;
default:
F_4 ( V_17 L_36 ) ;
return - V_34 ;
}
V_8 -> V_55 = V_56 ;
break;
case V_132 :
case V_133 :
F_7 ( 1 , L_34 , V_28 ) ;
V_8 -> V_55 = V_57 ;
if ( V_116 <= 6000000 ) {
V_8 -> V_52 = V_124 ;
V_8 -> V_59 = V_119 - 1750000 ;
V_115 = 6 ;
} else if ( V_116 <= 7000000 ) {
V_8 -> V_52 = V_130 ;
V_8 -> V_59 = V_119 - 2250000 ;
V_115 = 7 ;
} else {
V_8 -> V_52 = V_134 ;
V_8 -> V_59 = V_119 - 2750000 ;
V_115 = 8 ;
}
F_7 ( 1 , L_37 , V_28 ,
V_115 , V_116 ) ;
break;
default:
F_4 ( V_17 L_38 ) ;
return - V_34 ;
}
F_7 ( 1 , L_39 ,
V_28 , V_119 , V_8 -> V_59 ) ;
V_27 = F_13 ( V_8 , V_8 -> V_55 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17
L_40 ,
V_8 -> V_55 ) ;
return - V_18 ;
}
V_27 = F_12 ( V_8 ,
V_50 [ V_8 -> V_52 ] . V_47 ,
V_50 [ V_8 -> V_52 ] . V_48 , 0 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17 L_41 ) ;
return - V_18 ;
}
V_27 = F_15 ( V_8 , V_8 -> V_135 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17 L_42 ,
V_8 -> V_135 ) ;
return - V_136 ;
}
F_8 ( V_8 , V_137 , 0x8a ) ;
F_27 ( V_8 , V_8 -> V_59 , V_138 ) ;
if ( V_139 )
F_32 ( V_8 ) ;
V_8 -> V_140 = V_116 ;
return 0 ;
}
static int F_35 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 ;
T_2 V_141 ;
V_27 = F_5 ( V_8 , V_142 , & V_141 ) ;
if ( V_27 == 0 ) {
if ( V_141 == V_143 )
V_27 = - V_144 ;
else
V_27 = 0 ;
}
F_7 ( 1 , L_43 , V_28 ,
V_27 == 0 ? L_44 : L_45 , V_141 ) ;
return V_27 ;
}
static int F_36 ( struct V_24 * V_25 ,
struct V_145 * V_146 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
T_2 V_147 ;
int V_27 ;
F_7 ( 1 , L_46 ,
V_28 , V_146 -> V_120 ) ;
V_8 -> V_55 = V_146 -> V_96 ;
if ( V_146 -> V_96 > V_57 )
V_8 -> V_55 = V_57 ;
V_8 -> V_59 = V_146 -> V_120 * 62500 ;
if ( V_146 -> V_148 & V_149 ) {
V_8 -> V_52 = V_150 ;
goto V_151;
}
if ( V_146 -> V_148 & V_152 ) {
V_8 -> V_52 = V_153 ;
goto V_151;
}
if ( V_146 -> V_148 & V_154 ) {
V_8 -> V_52 = V_155 ;
goto V_151;
}
if ( V_146 -> V_148 & V_156 ) {
V_8 -> V_52 = V_157 ;
goto V_151;
}
if ( V_146 -> V_148 & V_158 ) {
V_8 -> V_52 = V_159 ;
goto V_151;
}
if ( V_146 -> V_148 & V_160 ) {
V_8 -> V_52 = V_161 ;
goto V_151;
}
if ( V_146 -> V_148 & V_162 ) {
V_8 -> V_52 = V_163 ;
goto V_151;
}
V_151:
V_27 = F_13 ( V_8 , V_8 -> V_55 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17
L_40 ,
V_8 -> V_55 ) ;
return - V_18 ;
}
V_27 = F_12 ( V_8 ,
V_50 [ V_8 -> V_52 ] . V_47 ,
V_50 [ V_8 -> V_52 ] . V_48 , 0 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17 L_41 ) ;
return - V_18 ;
}
F_8 ( V_8 , V_137 , 0x09 ) ;
F_27 ( V_8 , V_8 -> V_59 , V_98 ) ;
if ( V_139 )
F_32 ( V_8 ) ;
if ( V_8 -> V_103 != 0 ) {
F_9 ( 20 ) ;
F_5 ( V_8 , V_8 -> V_103 , & V_147 ) ;
if ( V_147 > 63 ) {
F_7 ( 1 , L_47 ,
V_147 ) ;
if ( F_34 ( V_25 , 1 ) != 0 ) {
F_4 ( V_17 L_48 ) ;
return - V_18 ;
}
goto V_151;
}
}
return 0 ;
}
static int F_37 ( struct V_24 * V_25 ,
struct V_145 * V_146 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 = - V_34 ;
T_1 V_164 ;
F_7 ( 1 , L_49 ,
V_28 , V_146 -> V_120 ) ;
if ( V_8 -> V_164 == V_165 ) {
F_7 ( 1 , L_50 , V_28 ) ;
return - V_34 ;
}
if ( V_8 -> V_164 == V_166 )
V_164 = V_167 ;
else if ( V_8 -> V_164 == V_168 )
V_164 = V_169 ;
else if ( V_8 -> V_164 == V_170 )
V_164 = V_171 ;
else {
F_7 ( 1 , L_51 , V_28 ,
V_8 -> V_164 ) ;
return - V_34 ;
}
V_8 -> V_59 = V_146 -> V_120 * 125 / 2 ;
V_8 -> V_55 = V_56 ;
V_27 = F_12 ( V_8 , V_50 [ V_164 ] . V_47 ,
V_50 [ V_164 ] . V_48 , V_164 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17 L_41 ) ;
return - V_18 ;
}
V_27 = F_13 ( V_8 , V_8 -> V_55 ) ;
if ( V_27 != 0 ) {
F_4 ( V_17
L_40 ,
V_8 -> V_55 ) ;
return - V_18 ;
}
if ( ( V_8 -> V_164 == V_166 ) ||
( V_8 -> V_164 == V_168 ) )
F_8 ( V_8 , V_137 , 0x09 ) ;
else if ( V_8 -> V_164 == V_170 )
F_8 ( V_8 , V_137 , 0x06 ) ;
F_27 ( V_8 , V_8 -> V_59 , V_98 ) ;
return 0 ;
}
static int F_38 ( struct V_24 * V_25 ,
struct V_145 * V_146 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 = - V_34 ;
if ( V_8 -> V_14 . V_16 == NULL )
return - V_34 ;
if ( F_34 ( V_25 , 0 ) != 0 ) {
F_7 ( 1 , L_31 ) ;
return - V_34 ;
}
switch ( V_146 -> V_96 ) {
case V_172 :
V_27 = F_37 ( V_25 , V_146 ) ;
break;
case V_173 :
case V_174 :
V_27 = F_36 ( V_25 , V_146 ) ;
break;
}
return V_27 ;
}
static int F_39 ( struct V_24 * V_25 , T_3 * V_119 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
* V_119 = V_8 -> V_59 ;
return 0 ;
}
static int F_40 ( struct V_24 * V_25 , T_3 * V_119 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
* V_119 = V_8 -> V_135 * 1000 ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 , T_3 * V_116 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
* V_116 = V_8 -> V_140 ;
return 0 ;
}
static int F_42 ( struct V_24 * V_25 , T_3 * V_175 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
T_2 V_74 = 0 ;
F_18 ( V_8 , & V_74 ) ;
F_7 ( 1 , L_52 , V_28 , V_74 ) ;
* V_175 = V_74 ;
return 0 ;
}
static int F_34 ( struct V_24 * V_25 , int V_176 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
int V_27 = 0 ;
T_2 V_147 ;
T_2 V_177 ;
F_43 ( & V_8 -> V_178 ) ;
if ( V_176 || F_35 ( V_25 ) != 0 ) {
V_179:
V_27 = F_29 ( V_25 ) ;
if ( V_27 != 0 )
return V_27 ;
F_9 ( 20 ) ;
if ( V_8 -> V_106 ) {
if ( F_5 ( V_8 , V_180 , & V_177 )
!= 0 ) {
F_7 ( 1 , L_53 ,
V_28 ) ;
goto V_179;
}
if ( V_177 == 0 ) {
F_7 ( 1 , L_54 ,
V_28 , V_177 ) ;
goto V_179;
}
}
V_27 |= F_11 ( V_8 ) ;
if ( V_27 != 0 )
goto V_179;
F_9 ( 100 ) ;
if ( V_8 -> V_105 ) {
if ( F_5 ( V_8 , V_181 , & V_177 ) != 0 ) {
F_7 ( 1 , L_55 ,
V_28 ) ;
goto V_179;
}
if ( V_177 == 0 ) {
F_7 ( 1 , L_56 , V_28 , V_177 ) ;
goto V_179;
}
}
if ( V_8 -> V_103 ) {
F_5 ( V_8 , V_8 -> V_103 ,
& V_147 ) ;
if ( V_147 > 63 ) {
F_4 ( V_17 L_57 ) ;
goto V_179;
}
}
V_27 |= F_8 ( V_8 , V_58 , V_57 ) ;
}
return V_27 ;
}
static void F_44 ( struct V_182 * V_178 )
{
struct V_7 * V_8 = F_45 ( V_178 , struct V_7 ,
V_178 . V_183 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
int V_27 ;
F_7 ( 1 , L_3 , V_28 ) ;
V_27 = F_6 ( V_25 ) ;
if ( V_27 != 0 )
F_4 ( V_17
L_58 ,
V_28 ) ;
}
static int F_46 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
if ( V_184 )
return 0 ;
F_47 ( & V_8 -> V_178 ,
F_48 ( V_185 ) ) ;
return 0 ;
}
static int F_49 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
if ( F_34 ( V_25 , 0 ) != 0 ) {
F_4 ( V_17 L_59 ) ;
return - V_18 ;
}
if ( V_139 )
F_32 ( V_8 ) ;
return 0 ;
}
static int F_50 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
F_7 ( 1 , L_3 , V_28 ) ;
F_51 ( & V_186 ) ;
if ( V_8 ) {
F_43 ( & V_8 -> V_178 ) ;
F_52 ( V_8 ) ;
}
F_53 ( & V_186 ) ;
V_25 -> V_26 = NULL ;
return 0 ;
}
static int F_54 ( struct V_24 * V_25 , void * V_187 )
{
struct V_7 * V_8 = V_25 -> V_26 ;
struct V_188 * V_189 = V_187 ;
F_7 ( 1 , L_3 , V_28 ) ;
if ( V_189 -> V_135 )
V_8 -> V_135 = V_189 -> V_135 ;
if ( V_189 -> V_164 )
V_8 -> V_164 = V_189 -> V_164 ;
return 0 ;
}
struct V_24 * F_55 ( struct V_24 * V_25 ,
struct V_190 * V_191 ,
const struct V_188 * V_192 )
{
struct V_7 * V_8 = NULL ;
int V_193 ;
T_2 V_141 = 0 ;
F_7 ( 1 , L_60 , V_28 ,
V_191 ? F_56 ( V_191 ) : - 1 ,
V_192 ? V_192 -> V_194 : - 1 ) ;
F_51 ( & V_186 ) ;
V_193 = F_57 ( struct V_7 , V_8 ,
V_195 ,
V_191 , V_192 -> V_194 , L_61 ) ;
switch ( V_193 ) {
case 0 :
goto V_196;
break;
case 1 :
V_8 -> V_140 = 6000000 ;
V_25 -> V_26 = V_8 ;
V_8 -> V_25 = V_25 ;
F_58 ( & V_8 -> V_178 , F_44 ) ;
break;
default:
V_25 -> V_26 = V_8 ;
break;
}
if ( V_8 -> V_135 == 0 ) {
V_8 -> V_135 = V_192 -> V_135 ;
}
if ( V_8 -> V_99 == 0 )
V_8 -> V_99 = V_192 -> V_99 ;
if ( V_8 -> V_164 == 0 )
V_8 -> V_164 = V_192 -> V_164 ;
if ( ( V_8 -> V_2 == 0 ) || ( V_192 -> V_2 ) )
V_8 -> V_2 = ( V_192 -> V_2 ) ? V_192 -> V_2 : 0 ;
if ( F_5 ( V_8 , V_142 , & V_141 ) != 0 )
goto V_196;
switch ( V_141 ) {
case V_197 :
F_4 ( V_107
L_62 ,
V_192 -> V_194 ) ;
F_4 ( V_107
L_63 ) ;
break;
case V_143 :
F_4 ( V_107
L_62 ,
V_192 -> V_194 ) ;
F_4 ( V_107
L_64 ) ;
break;
default:
F_4 ( V_17
L_65 ,
V_192 -> V_194 , V_141 ) ;
goto V_196;
}
F_53 ( & V_186 ) ;
memcpy ( & V_25 -> V_198 . V_199 , & V_61 ,
sizeof( struct V_200 ) ) ;
return V_25 ;
V_196:
F_53 ( & V_186 ) ;
F_50 ( V_25 ) ;
return NULL ;
}
