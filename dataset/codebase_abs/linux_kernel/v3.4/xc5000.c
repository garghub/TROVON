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
if ( V_40 < 0 )
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
static T_2 F_25 ( struct V_7 * V_8 )
{
T_2 V_93 = 0 ;
int V_94 = 40 ;
while ( ( V_93 == 0 ) && ( V_94 > 0 ) ) {
F_19 ( V_8 , & V_93 ) ;
if ( V_93 != 1 ) {
F_6 ( 5 ) ;
V_94 -- ;
}
}
return V_93 ;
}
static int F_26 ( struct V_7 * V_8 , T_3 V_61 , int V_95 )
{
int V_96 = 0 ;
F_9 ( 1 , L_12 , V_31 , V_61 ) ;
if ( F_15 ( V_8 , V_61 ) != V_19 )
return 0 ;
if ( V_95 == V_97 ) {
if ( F_25 ( V_8 ) == 1 )
V_96 = 1 ;
}
return V_96 ;
}
static int F_27 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = V_19 ;
switch ( V_8 -> V_2 ) {
default:
case V_3 :
break;
case V_5 :
switch ( V_8 -> V_98 ) {
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
static int F_28 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
const struct V_99 * V_100 ;
int V_30 ;
const struct V_1 * V_101 =
F_1 ( V_8 -> V_2 ) ;
F_4 ( V_102 L_14 ,
V_101 -> V_103 ) ;
V_30 = F_29 ( & V_100 , V_101 -> V_103 ,
V_8 -> V_14 . V_16 -> V_104 . V_105 ) ;
if ( V_30 ) {
F_4 ( V_17 L_15 ) ;
V_30 = V_37 ;
goto V_106;
} else {
F_4 ( V_107 L_16 ,
V_100 -> V_108 ) ;
V_30 = V_19 ;
}
if ( V_100 -> V_108 != V_101 -> V_108 ) {
F_4 ( V_17 L_17 ) ;
V_30 = V_37 ;
} else {
F_4 ( V_102 L_18 ) ;
V_30 = F_11 ( V_28 , V_100 -> V_83 ) ;
if ( V_19 == V_30 )
V_30 = F_27 ( V_28 ) ;
F_4 ( V_102 L_19 ) ;
}
V_106:
F_30 ( V_100 ) ;
return V_30 ;
}
static void F_31 ( struct V_7 * V_8 )
{
T_2 V_71 ;
T_3 V_73 = 0 ;
T_2 V_77 ;
T_3 V_87 = 0 ;
T_2 V_89 ;
T_2 V_91 ;
T_1 V_79 = 0 , V_80 = 0 ;
T_1 V_81 = 0 , V_82 = 0 ;
T_2 V_109 = 0 ;
F_6 ( 100 ) ;
F_17 ( V_8 , & V_71 ) ;
F_9 ( 1 , L_20 , V_71 ) ;
F_18 ( V_8 , & V_73 ) ;
F_9 ( 1 , L_21 , V_73 ) ;
F_19 ( V_8 , & V_77 ) ;
F_9 ( 1 , L_22 ,
V_77 ) ;
F_20 ( V_8 , & V_79 , & V_80 ,
& V_81 , & V_82 ) ;
F_21 ( V_8 , & V_109 ) ;
F_9 ( 1 , L_23 ,
V_79 , V_80 ,
V_81 , V_82 , V_109 ) ;
F_22 ( V_8 , & V_87 ) ;
F_9 ( 1 , L_24 , V_87 ) ;
F_23 ( V_8 , & V_89 ) ;
F_9 ( 1 , L_25 , V_89 ) ;
F_24 ( V_8 , & V_91 ) ;
F_9 ( 1 , L_26 , V_91 ) ;
}
static int F_32 ( struct V_27 * V_28 )
{
int V_30 , V_110 ;
struct V_7 * V_8 = V_28 -> V_29 ;
T_3 V_111 = V_28 -> V_112 . V_113 ;
T_3 V_114 = V_28 -> V_112 . V_115 ;
T_3 V_116 = V_28 -> V_112 . V_117 ;
if ( F_33 ( V_28 ) != V_19 ) {
if ( F_34 ( V_28 ) != V_19 ) {
F_9 ( 1 , L_27 ) ;
return - V_118 ;
}
}
F_9 ( 1 , L_28 , V_31 , V_114 ) ;
switch ( V_116 ) {
case V_119 :
F_9 ( 1 , L_29 , V_31 ) ;
V_8 -> V_57 = V_58 ;
V_8 -> V_61 = V_114 - 1750000 ;
V_8 -> V_53 = V_120 ;
break;
case V_121 :
F_9 ( 1 , L_30 , V_31 ) ;
V_8 -> V_57 = V_59 ;
V_8 -> V_61 = V_114 - 1750000 ;
V_8 -> V_53 = V_120 ;
break;
case V_122 :
case V_123 :
F_9 ( 1 , L_31 , V_31 ) ;
switch ( V_111 ) {
case 6000000 :
V_8 -> V_53 = V_120 ;
V_8 -> V_61 = V_114 - 1750000 ;
break;
case 7000000 :
V_8 -> V_53 = V_124 ;
V_8 -> V_61 = V_114 - 2250000 ;
break;
case 8000000 :
V_8 -> V_53 = V_125 ;
V_8 -> V_61 = V_114 - 2750000 ;
break;
default:
F_4 ( V_17 L_32 ) ;
return - V_118 ;
}
V_8 -> V_57 = V_58 ;
case V_126 :
case V_127 :
F_9 ( 1 , L_30 , V_31 ) ;
V_8 -> V_57 = V_59 ;
if ( V_111 <= 6000000 ) {
V_8 -> V_53 = V_120 ;
V_8 -> V_61 = V_114 - 1750000 ;
V_110 = 6 ;
} else if ( V_111 <= 7000000 ) {
V_8 -> V_53 = V_124 ;
V_8 -> V_61 = V_114 - 2250000 ;
V_110 = 7 ;
} else {
V_8 -> V_53 = V_128 ;
V_8 -> V_61 = V_114 - 2750000 ;
V_110 = 8 ;
}
F_9 ( 1 , L_33 , V_31 ,
V_110 , V_111 ) ;
break;
default:
F_4 ( V_17 L_34 ) ;
return - V_118 ;
}
F_9 ( 1 , L_35 ,
V_31 , V_114 , V_8 -> V_61 ) ;
V_30 = F_14 ( V_8 , V_8 -> V_57 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17
L_36 ,
V_8 -> V_57 ) ;
return - V_25 ;
}
V_30 = F_13 ( V_8 ,
V_52 [ V_8 -> V_53 ] . V_50 ,
V_52 [ V_8 -> V_53 ] . V_51 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_37 ) ;
return - V_25 ;
}
V_30 = F_16 ( V_8 , V_8 -> V_129 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_38 ,
V_8 -> V_129 ) ;
return - V_130 ;
}
F_10 ( V_8 , V_131 , 0x8a ) ;
F_26 ( V_8 , V_8 -> V_61 , V_132 ) ;
if ( V_133 )
F_31 ( V_8 ) ;
V_8 -> V_134 = V_111 ;
return 0 ;
}
static int F_33 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 ;
T_2 V_135 ;
V_30 = F_5 ( V_8 , V_136 , & V_135 ) ;
if ( V_30 == V_19 ) {
if ( V_135 == V_137 )
V_30 = V_37 ;
else
V_30 = V_19 ;
}
F_9 ( 1 , L_39 , V_31 ,
V_30 == V_19 ? L_40 : L_41 , V_135 ) ;
return V_30 ;
}
static int F_35 ( struct V_27 * V_28 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 ;
F_9 ( 1 , L_42 ,
V_31 , V_139 -> V_115 ) ;
V_8 -> V_57 = V_139 -> V_95 ;
if ( V_139 -> V_95 > V_59 )
V_8 -> V_57 = V_59 ;
V_8 -> V_61 = V_139 -> V_115 * 62500 ;
if ( V_139 -> V_140 & V_141 ) {
V_8 -> V_53 = V_142 ;
goto V_143;
}
if ( V_139 -> V_140 & V_144 ) {
V_8 -> V_53 = V_145 ;
goto V_143;
}
if ( V_139 -> V_140 & V_146 ) {
V_8 -> V_53 = V_147 ;
goto V_143;
}
if ( V_139 -> V_140 & V_148 ) {
V_8 -> V_53 = V_149 ;
goto V_143;
}
if ( V_139 -> V_140 & V_150 ) {
V_8 -> V_53 = V_151 ;
goto V_143;
}
if ( V_139 -> V_140 & V_152 ) {
V_8 -> V_53 = V_153 ;
goto V_143;
}
if ( V_139 -> V_140 & V_154 ) {
V_8 -> V_53 = V_155 ;
goto V_143;
}
V_143:
V_30 = F_14 ( V_8 , V_8 -> V_57 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17
L_36 ,
V_8 -> V_57 ) ;
return - V_25 ;
}
V_30 = F_13 ( V_8 ,
V_52 [ V_8 -> V_53 ] . V_50 ,
V_52 [ V_8 -> V_53 ] . V_51 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_37 ) ;
return - V_25 ;
}
F_10 ( V_8 , V_131 , 0x09 ) ;
F_26 ( V_8 , V_8 -> V_61 , V_97 ) ;
if ( V_133 )
F_31 ( V_8 ) ;
return 0 ;
}
static int F_36 ( struct V_27 * V_28 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = - V_118 ;
T_1 V_156 ;
F_9 ( 1 , L_43 ,
V_31 , V_139 -> V_115 ) ;
if ( V_8 -> V_156 == V_157 ) {
F_9 ( 1 , L_44 , V_31 ) ;
return - V_118 ;
}
if ( V_8 -> V_156 == V_158 )
V_156 = V_159 ;
else if ( V_8 -> V_156 == V_160 )
V_156 = V_161 ;
else if ( V_8 -> V_156 == V_162 )
V_156 = V_163 ;
else {
F_9 ( 1 , L_45 , V_31 ,
V_8 -> V_156 ) ;
return - V_118 ;
}
V_8 -> V_61 = V_139 -> V_115 * 125 / 2 ;
V_8 -> V_57 = V_58 ;
V_30 = F_13 ( V_8 , V_52 [ V_156 ] . V_50 ,
V_52 [ V_156 ] . V_51 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17 L_37 ) ;
return - V_25 ;
}
V_30 = F_14 ( V_8 , V_8 -> V_57 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17
L_36 ,
V_8 -> V_57 ) ;
return - V_25 ;
}
if ( ( V_8 -> V_156 == V_158 ) ||
( V_8 -> V_156 == V_160 ) )
F_10 ( V_8 , V_131 , 0x09 ) ;
else if ( V_8 -> V_156 == V_162 )
F_10 ( V_8 , V_131 , 0x06 ) ;
F_26 ( V_8 , V_8 -> V_61 , V_97 ) ;
return 0 ;
}
static int F_37 ( struct V_27 * V_28 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = - V_118 ;
if ( V_8 -> V_14 . V_16 == NULL )
return - V_118 ;
if ( F_33 ( V_28 ) != V_19 ) {
if ( F_34 ( V_28 ) != V_19 ) {
F_9 ( 1 , L_27 ) ;
return - V_118 ;
}
}
switch ( V_139 -> V_95 ) {
case V_164 :
V_30 = F_36 ( V_28 , V_139 ) ;
break;
case V_165 :
case V_166 :
V_30 = F_35 ( V_28 , V_139 ) ;
break;
}
return V_30 ;
}
static int F_38 ( struct V_27 * V_28 , T_3 * V_114 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
* V_114 = V_8 -> V_61 ;
return 0 ;
}
static int F_39 ( struct V_27 * V_28 , T_3 * V_114 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
* V_114 = V_8 -> V_129 * 1000 ;
return 0 ;
}
static int F_40 ( struct V_27 * V_28 , T_3 * V_111 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
* V_111 = V_8 -> V_134 ;
return 0 ;
}
static int F_41 ( struct V_27 * V_28 , T_3 * V_167 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
T_2 V_77 = 0 ;
F_19 ( V_8 , & V_77 ) ;
F_9 ( 1 , L_46 , V_31 , V_77 ) ;
* V_167 = V_77 ;
return 0 ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = 0 ;
if ( F_33 ( V_28 ) != V_19 ) {
V_30 = F_28 ( V_28 ) ;
if ( V_30 != V_19 )
return V_30 ;
}
V_30 |= F_12 ( V_8 ) ;
F_6 ( 100 ) ;
V_30 |= F_10 ( V_8 , V_60 , V_59 ) ;
return V_30 ;
}
static int F_42 ( struct V_27 * V_28 )
{
int V_30 ;
F_9 ( 1 , L_3 , V_31 ) ;
if ( V_168 )
return 0 ;
V_30 = F_8 ( V_28 ) ;
if ( V_30 != V_19 ) {
F_4 ( V_17
L_47 ,
V_31 ) ;
return - V_25 ;
} else
return V_19 ;
}
static int F_43 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
if ( F_34 ( V_28 ) != V_19 ) {
F_4 ( V_17 L_48 ) ;
return - V_25 ;
}
if ( V_133 )
F_31 ( V_8 ) ;
return 0 ;
}
static int F_44 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
F_9 ( 1 , L_3 , V_31 ) ;
F_45 ( & V_169 ) ;
if ( V_8 )
F_46 ( V_8 ) ;
F_47 ( & V_169 ) ;
V_28 -> V_29 = NULL ;
return 0 ;
}
static int F_48 ( struct V_27 * V_28 , void * V_170 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
struct V_171 * V_172 = V_170 ;
F_9 ( 1 , L_3 , V_31 ) ;
if ( V_172 -> V_129 )
V_8 -> V_129 = V_172 -> V_129 ;
if ( V_172 -> V_156 )
V_8 -> V_156 = V_172 -> V_156 ;
return 0 ;
}
struct V_27 * F_49 ( struct V_27 * V_28 ,
struct V_173 * V_174 ,
const struct V_171 * V_175 )
{
struct V_7 * V_8 = NULL ;
int V_176 ;
T_2 V_135 = 0 ;
F_9 ( 1 , L_49 , V_31 ,
V_174 ? F_50 ( V_174 ) : - 1 ,
V_175 ? V_175 -> V_177 : - 1 ) ;
F_45 ( & V_169 ) ;
V_176 = F_51 ( struct V_7 , V_8 ,
V_178 ,
V_174 , V_175 -> V_177 , L_50 ) ;
switch ( V_176 ) {
case 0 :
goto V_179;
break;
case 1 :
V_8 -> V_134 = 6000000 ;
V_28 -> V_29 = V_8 ;
break;
default:
V_28 -> V_29 = V_8 ;
break;
}
if ( V_8 -> V_129 == 0 ) {
V_8 -> V_129 = V_175 -> V_129 ;
}
if ( V_8 -> V_98 == 0 )
V_8 -> V_98 = V_175 -> V_98 ;
if ( V_8 -> V_156 == 0 )
V_8 -> V_156 = V_175 -> V_156 ;
if ( ( V_8 -> V_2 == 0 ) || ( V_175 -> V_2 ) )
V_8 -> V_2 = ( V_175 -> V_2 ) ? V_175 -> V_2 : 0 ;
if ( F_5 ( V_8 , V_136 , & V_135 ) != V_19 )
goto V_179;
switch ( V_135 ) {
case V_180 :
F_4 ( V_102
L_51 ,
V_175 -> V_177 ) ;
F_4 ( V_102
L_52 ) ;
break;
case V_137 :
F_4 ( V_102
L_51 ,
V_175 -> V_177 ) ;
F_4 ( V_102
L_53 ) ;
break;
default:
F_4 ( V_17
L_54 ,
V_175 -> V_177 , V_135 ) ;
goto V_179;
}
F_47 ( & V_169 ) ;
memcpy ( & V_28 -> V_181 . V_182 , & V_63 ,
sizeof( struct V_183 ) ) ;
return V_28 ;
V_179:
F_47 ( & V_169 ) ;
F_44 ( V_28 ) ;
return NULL ;
}
