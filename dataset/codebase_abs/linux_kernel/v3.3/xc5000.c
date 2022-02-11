static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
struct V_5 V_6 = { . V_7 = V_2 -> V_8 . V_7 ,
. V_9 = 0 , . V_3 = V_3 , . V_4 = V_4 } ;
if ( F_2 ( V_2 -> V_8 . V_10 , & V_6 , 1 ) != 1 ) {
F_3 ( V_11 L_1 , V_4 ) ;
return V_12 ;
}
return V_13 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 V_14 , T_2 * V_15 )
{
T_1 V_3 [ 2 ] = { V_14 >> 8 , V_14 & 0xff } ;
T_1 V_16 [ 2 ] = { 0 , 0 } ;
struct V_5 V_6 [ 2 ] = {
{ . V_7 = V_2 -> V_8 . V_7 ,
. V_9 = 0 , . V_3 = & V_3 [ 0 ] , . V_4 = 2 } ,
{ . V_7 = V_2 -> V_8 . V_7 ,
. V_9 = V_17 , . V_3 = & V_16 [ 0 ] , . V_4 = 2 } ,
} ;
if ( F_2 ( V_2 -> V_8 . V_10 , V_6 , 2 ) != 2 ) {
F_3 ( V_18 L_2 ) ;
return - V_19 ;
}
* V_15 = ( V_16 [ 0 ] << 8 ) | V_16 [ 1 ] ;
return V_13 ;
}
static void F_5 ( int V_20 )
{
F_6 ( V_20 ) ;
}
static int F_7 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_24 ;
F_8 ( 1 , L_3 , V_25 ) ;
if ( V_22 -> V_26 ) {
V_24 = V_22 -> V_26 ( ( ( V_22 -> V_27 ) && ( V_22 -> V_27 -> V_2 ) ) ?
V_22 -> V_27 -> V_2 :
V_2 -> V_8 . V_10 -> V_28 ,
V_29 ,
V_30 , 0 ) ;
if ( V_24 ) {
F_3 ( V_11 L_4 ) ;
return V_31 ;
}
} else {
F_3 ( V_11 L_5 ) ;
return V_31 ;
}
return V_13 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_32 , T_2 V_33 )
{
T_1 V_3 [ 4 ] ;
int V_34 = 100 ;
int V_35 ;
V_3 [ 0 ] = ( V_32 >> 8 ) & 0xFF ;
V_3 [ 1 ] = V_32 & 0xFF ;
V_3 [ 2 ] = ( V_33 >> 8 ) & 0xFF ;
V_3 [ 3 ] = V_33 & 0xFF ;
V_35 = F_1 ( V_2 , V_3 , 4 ) ;
if ( V_35 == V_13 ) {
while ( ( V_34 > 0 ) && ( V_35 == V_13 ) ) {
V_35 = F_4 ( V_2 , V_36 , ( T_2 * ) V_3 ) ;
if ( V_35 == V_13 ) {
if ( ( V_3 [ 0 ] == 0 ) && ( V_3 [ 1 ] == 0 ) ) {
break;
} else {
F_5 ( 5 ) ;
V_34 -- ;
}
}
}
}
if ( V_34 < 0 )
V_35 = V_12 ;
return V_35 ;
}
static int F_10 ( struct V_21 * V_22 , const T_1 * V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_38 , V_39 , V_35 ;
unsigned int V_4 , V_40 , V_41 ;
T_1 V_3 [ V_42 ] ;
V_41 = 0 ;
while ( ( V_37 [ V_41 ] != 0xFF ) ||
( V_37 [ V_41 + 1 ] != 0xFF ) ) {
V_4 = V_37 [ V_41 ] * 256 + V_37 [ V_41 + 1 ] ;
if ( V_4 == 0x0000 ) {
V_35 = F_7 ( V_22 ) ;
V_41 += 2 ;
if ( V_35 != V_13 )
return V_35 ;
} else if ( V_4 & 0x8000 ) {
F_5 ( V_4 & 0x7FFF ) ;
V_41 += 2 ;
} else {
V_41 += 2 ;
V_3 [ 0 ] = V_37 [ V_41 ] ;
V_3 [ 1 ] = V_37 [ V_41 + 1 ] ;
V_40 = 2 ;
while ( V_40 < V_4 ) {
if ( ( V_4 - V_40 ) > V_42 - 2 )
V_39 =
V_42 ;
else
V_39 = ( V_4 - V_40 + 2 ) ;
for ( V_38 = 2 ; V_38 < V_39 ; V_38 ++ ) {
V_3 [ V_38 ] = V_37 [ V_41 + V_40 +
V_38 - 2 ] ;
}
V_35 = F_1 ( V_2 , V_3 ,
V_39 ) ;
if ( V_35 != V_13 )
return V_35 ;
V_40 += V_39 - 2 ;
}
V_41 += V_4 ;
}
}
return V_13 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_8 ( 1 , L_3 , V_25 ) ;
return F_9 ( V_2 , V_43 , 0 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
T_2 V_44 , T_2 V_45 )
{
int V_24 ;
F_8 ( 1 , L_6 , V_25 , V_44 , V_45 ) ;
F_8 ( 1 , L_7 ,
V_25 ,
V_46 [ V_2 -> V_47 ] . V_48 ) ;
V_24 = F_9 ( V_2 , V_49 , V_44 ) ;
if ( V_24 == V_13 )
V_24 = F_9 ( V_2 , V_50 , V_45 ) ;
return V_24 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_51 )
{
F_8 ( 1 , L_8 , V_25 , V_51 ,
V_51 == V_52 ? L_9 : L_10 ) ;
if ( ( V_51 != V_52 ) && ( V_51 != V_53 ) ) {
V_51 = V_53 ;
F_3 ( V_11
L_11 ,
V_25 ) ;
}
return F_9 ( V_2 , V_54 , V_51 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_3 V_55 )
{
T_2 V_56 ;
F_8 ( 1 , L_12 , V_25 , V_55 ) ;
if ( ( V_55 > V_57 . V_58 . V_59 ) ||
( V_55 < V_57 . V_58 . V_60 ) )
return V_61 ;
V_56 = ( T_2 ) ( V_55 / 15625 ) ;
return F_9 ( V_2 , V_62 , V_56 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_3 V_63 )
{
T_3 V_56 = ( V_63 * 1024 ) / 1000 ;
F_8 ( 1 , L_13 ,
V_25 , V_63 , V_56 ) ;
return F_9 ( V_2 , V_64 , V_56 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_2 * V_65 )
{
return F_4 ( V_2 , V_66 , V_65 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_3 * V_67 )
{
int V_35 ;
T_2 V_68 ;
T_3 V_69 ;
V_35 = F_4 ( V_2 , V_70 , & V_68 ) ;
if ( V_35 != V_13 )
return V_35 ;
V_69 = ( T_3 ) V_68 ;
( * V_67 ) = ( V_69 * 15625 ) / 1000 ;
return V_35 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 * V_71 )
{
return F_4 ( V_2 , V_72 , V_71 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
T_1 * V_73 , T_1 * V_74 ,
T_1 * V_75 , T_1 * V_76 )
{
T_2 V_77 ;
int V_35 ;
V_35 = F_4 ( V_2 , V_78 , & V_77 ) ;
if ( V_35 != V_13 )
return V_35 ;
( * V_73 ) = ( V_77 >> 12 ) & 0x0F ;
( * V_74 ) = ( V_77 >> 8 ) & 0x0F ;
( * V_75 ) = ( V_77 >> 4 ) & 0x0F ;
( * V_76 ) = V_77 & 0x0F ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_2 * V_79 )
{
return F_4 ( V_2 , V_80 , V_79 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_3 * V_81 )
{
T_2 V_68 ;
int V_35 ;
V_35 = F_4 ( V_2 , V_82 , & V_68 ) ;
if ( V_35 != V_13 )
return V_35 ;
( * V_81 ) = ( ( V_68 & 0x0fff ) * 763 ) / 100 ;
return V_35 ;
}
static int F_22 ( struct V_1 * V_2 , T_2 * V_83 )
{
return F_4 ( V_2 , V_84 , V_83 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_2 * V_85 )
{
return F_4 ( V_2 , V_86 , V_85 ) ;
}
static T_2 F_24 ( struct V_1 * V_2 )
{
T_2 V_87 = 0 ;
int V_88 = 40 ;
while ( ( V_87 == 0 ) && ( V_88 > 0 ) ) {
F_18 ( V_2 , & V_87 ) ;
if ( V_87 != 1 ) {
F_5 ( 5 ) ;
V_88 -- ;
}
}
return V_87 ;
}
static int F_25 ( struct V_1 * V_2 , T_3 V_55 , int V_89 )
{
int V_90 = 0 ;
F_8 ( 1 , L_12 , V_25 , V_55 ) ;
if ( F_14 ( V_2 , V_55 ) != V_13 )
return 0 ;
if ( V_89 == V_91 ) {
if ( F_24 ( V_2 ) == 1 )
V_90 = 1 ;
}
return V_90 ;
}
static int F_26 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
const struct V_92 * V_93 ;
int V_24 ;
F_3 ( V_94 L_14 ,
V_95 ) ;
V_24 = F_27 ( & V_93 , V_95 ,
V_2 -> V_8 . V_10 -> V_96 . V_97 ) ;
if ( V_24 ) {
F_3 ( V_11 L_15 ) ;
V_24 = V_31 ;
goto V_98;
} else {
F_3 ( V_99 L_16 ,
V_93 -> V_100 ) ;
V_24 = V_13 ;
}
if ( V_93 -> V_100 != V_101 ) {
F_3 ( V_11 L_17 ) ;
V_24 = V_31 ;
} else {
F_3 ( V_94 L_18 ) ;
V_24 = F_10 ( V_22 , V_93 -> V_77 ) ;
F_3 ( V_94 L_19 ) ;
}
V_98:
F_28 ( V_93 ) ;
return V_24 ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_2 V_65 ;
T_3 V_67 = 0 ;
T_2 V_71 ;
T_3 V_81 = 0 ;
T_2 V_83 ;
T_2 V_85 ;
T_1 V_73 = 0 , V_74 = 0 ;
T_1 V_75 = 0 , V_76 = 0 ;
T_2 V_102 = 0 ;
F_5 ( 100 ) ;
F_16 ( V_2 , & V_65 ) ;
F_8 ( 1 , L_20 , V_65 ) ;
F_17 ( V_2 , & V_67 ) ;
F_8 ( 1 , L_21 , V_67 ) ;
F_18 ( V_2 , & V_71 ) ;
F_8 ( 1 , L_22 ,
V_71 ) ;
F_19 ( V_2 , & V_73 , & V_74 ,
& V_75 , & V_76 ) ;
F_20 ( V_2 , & V_102 ) ;
F_8 ( 1 , L_23 ,
V_73 , V_74 ,
V_75 , V_76 , V_102 ) ;
F_21 ( V_2 , & V_81 ) ;
F_8 ( 1 , L_24 , V_81 ) ;
F_22 ( V_2 , & V_83 ) ;
F_8 ( 1 , L_25 , V_83 ) ;
F_23 ( V_2 , & V_85 ) ;
F_8 ( 1 , L_26 , V_85 ) ;
}
static int F_30 ( struct V_21 * V_22 )
{
int V_24 , V_103 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_3 V_104 = V_22 -> V_105 . V_106 ;
T_3 V_107 = V_22 -> V_105 . V_108 ;
T_3 V_109 = V_22 -> V_105 . V_110 ;
if ( F_31 ( V_22 ) != V_13 ) {
if ( F_32 ( V_22 ) != V_13 ) {
F_8 ( 1 , L_27 ) ;
return - V_111 ;
}
}
F_8 ( 1 , L_28 , V_25 , V_107 ) ;
switch ( V_109 ) {
case V_112 :
F_8 ( 1 , L_29 , V_25 ) ;
V_2 -> V_51 = V_52 ;
V_2 -> V_55 = V_107 - 1750000 ;
V_2 -> V_47 = V_113 ;
break;
case V_114 :
F_8 ( 1 , L_30 , V_25 ) ;
V_2 -> V_51 = V_53 ;
V_2 -> V_55 = V_107 - 1750000 ;
V_2 -> V_47 = V_113 ;
break;
case V_115 :
case V_116 :
F_8 ( 1 , L_31 , V_25 ) ;
switch ( V_104 ) {
case 6000000 :
V_2 -> V_47 = V_113 ;
V_2 -> V_55 = V_107 - 1750000 ;
break;
case 7000000 :
V_2 -> V_47 = V_117 ;
V_2 -> V_55 = V_107 - 2250000 ;
break;
case 8000000 :
V_2 -> V_47 = V_118 ;
V_2 -> V_55 = V_107 - 2750000 ;
break;
default:
F_3 ( V_11 L_32 ) ;
return - V_111 ;
}
V_2 -> V_51 = V_52 ;
case V_119 :
case V_120 :
F_8 ( 1 , L_30 , V_25 ) ;
V_2 -> V_51 = V_53 ;
if ( V_104 <= 6000000 ) {
V_2 -> V_47 = V_113 ;
V_2 -> V_55 = V_107 - 1750000 ;
V_103 = 6 ;
} else if ( V_104 <= 7000000 ) {
V_2 -> V_47 = V_117 ;
V_2 -> V_55 = V_107 - 2250000 ;
V_103 = 7 ;
} else {
V_2 -> V_47 = V_121 ;
V_2 -> V_55 = V_107 - 2750000 ;
V_103 = 8 ;
}
F_8 ( 1 , L_33 , V_25 ,
V_103 , V_104 ) ;
break;
default:
F_3 ( V_11 L_34 ) ;
return - V_111 ;
}
F_8 ( 1 , L_35 ,
V_25 , V_107 , V_2 -> V_55 ) ;
V_24 = F_13 ( V_2 , V_2 -> V_51 ) ;
if ( V_24 != V_13 ) {
F_3 ( V_11
L_36 ,
V_2 -> V_51 ) ;
return - V_19 ;
}
V_24 = F_12 ( V_2 ,
V_46 [ V_2 -> V_47 ] . V_44 ,
V_46 [ V_2 -> V_47 ] . V_45 ) ;
if ( V_24 != V_13 ) {
F_3 ( V_11 L_37 ) ;
return - V_19 ;
}
V_24 = F_15 ( V_2 , V_2 -> V_122 ) ;
if ( V_24 != V_13 ) {
F_3 ( V_11 L_38 ,
V_2 -> V_122 ) ;
return - V_123 ;
}
F_9 ( V_2 , V_124 , 0x8a ) ;
F_25 ( V_2 , V_2 -> V_55 , V_125 ) ;
if ( V_126 )
F_29 ( V_2 ) ;
V_2 -> V_127 = V_104 ;
return 0 ;
}
static int F_31 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_24 ;
T_2 V_128 ;
V_24 = F_4 ( V_2 , V_129 , & V_128 ) ;
if ( V_24 == V_13 ) {
if ( V_128 == V_130 )
V_24 = V_31 ;
else
V_24 = V_13 ;
}
F_8 ( 1 , L_39 , V_25 ,
V_24 == V_13 ? L_40 : L_41 , V_128 ) ;
return V_24 ;
}
static int F_33 ( struct V_21 * V_22 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_24 ;
F_8 ( 1 , L_42 ,
V_25 , V_132 -> V_108 ) ;
V_2 -> V_51 = V_132 -> V_89 ;
if ( V_132 -> V_89 > V_53 )
V_2 -> V_51 = V_53 ;
V_2 -> V_55 = V_132 -> V_108 * 62500 ;
if ( V_132 -> V_133 & V_134 ) {
V_2 -> V_47 = V_135 ;
goto V_136;
}
if ( V_132 -> V_133 & V_137 ) {
V_2 -> V_47 = V_138 ;
goto V_136;
}
if ( V_132 -> V_133 & V_139 ) {
V_2 -> V_47 = V_140 ;
goto V_136;
}
if ( V_132 -> V_133 & V_141 ) {
V_2 -> V_47 = V_142 ;
goto V_136;
}
if ( V_132 -> V_133 & V_143 ) {
V_2 -> V_47 = V_144 ;
goto V_136;
}
if ( V_132 -> V_133 & V_145 ) {
V_2 -> V_47 = V_146 ;
goto V_136;
}
if ( V_132 -> V_133 & V_147 ) {
V_2 -> V_47 = V_148 ;
goto V_136;
}
V_136:
V_24 = F_13 ( V_2 , V_2 -> V_51 ) ;
if ( V_24 != V_13 ) {
F_3 ( V_11
L_36 ,
V_2 -> V_51 ) ;
return - V_19 ;
}
V_24 = F_12 ( V_2 ,
V_46 [ V_2 -> V_47 ] . V_44 ,
V_46 [ V_2 -> V_47 ] . V_45 ) ;
if ( V_24 != V_13 ) {
F_3 ( V_11 L_37 ) ;
return - V_19 ;
}
F_9 ( V_2 , V_124 , 0x09 ) ;
F_25 ( V_2 , V_2 -> V_55 , V_91 ) ;
if ( V_126 )
F_29 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_21 * V_22 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_24 = - V_111 ;
T_1 V_149 ;
F_8 ( 1 , L_43 ,
V_25 , V_132 -> V_108 ) ;
if ( V_2 -> V_149 == V_150 ) {
F_8 ( 1 , L_44 , V_25 ) ;
return - V_111 ;
}
if ( V_2 -> V_149 == V_151 )
V_149 = V_152 ;
else if ( V_2 -> V_149 == V_153 )
V_149 = V_154 ;
else if ( V_2 -> V_149 == V_155 )
V_149 = V_156 ;
else {
F_8 ( 1 , L_45 , V_25 ,
V_2 -> V_149 ) ;
return - V_111 ;
}
V_2 -> V_55 = V_132 -> V_108 * 125 / 2 ;
V_2 -> V_51 = V_52 ;
V_24 = F_12 ( V_2 , V_46 [ V_149 ] . V_44 ,
V_46 [ V_149 ] . V_45 ) ;
if ( V_24 != V_13 ) {
F_3 ( V_11 L_37 ) ;
return - V_19 ;
}
V_24 = F_13 ( V_2 , V_2 -> V_51 ) ;
if ( V_24 != V_13 ) {
F_3 ( V_11
L_36 ,
V_2 -> V_51 ) ;
return - V_19 ;
}
if ( ( V_2 -> V_149 == V_151 ) ||
( V_2 -> V_149 == V_153 ) )
F_9 ( V_2 , V_124 , 0x09 ) ;
else if ( V_2 -> V_149 == V_155 )
F_9 ( V_2 , V_124 , 0x06 ) ;
F_25 ( V_2 , V_2 -> V_55 , V_91 ) ;
return 0 ;
}
static int F_35 ( struct V_21 * V_22 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_24 = - V_111 ;
if ( V_2 -> V_8 . V_10 == NULL )
return - V_111 ;
if ( F_31 ( V_22 ) != V_13 ) {
if ( F_32 ( V_22 ) != V_13 ) {
F_8 ( 1 , L_27 ) ;
return - V_111 ;
}
}
switch ( V_132 -> V_89 ) {
case V_157 :
V_24 = F_34 ( V_22 , V_132 ) ;
break;
case V_158 :
case V_159 :
V_24 = F_33 ( V_22 , V_132 ) ;
break;
}
return V_24 ;
}
static int F_36 ( struct V_21 * V_22 , T_3 * V_107 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_8 ( 1 , L_3 , V_25 ) ;
* V_107 = V_2 -> V_55 ;
return 0 ;
}
static int F_37 ( struct V_21 * V_22 , T_3 * V_107 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_8 ( 1 , L_3 , V_25 ) ;
* V_107 = V_2 -> V_122 * 1000 ;
return 0 ;
}
static int F_38 ( struct V_21 * V_22 , T_3 * V_104 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_8 ( 1 , L_3 , V_25 ) ;
* V_104 = V_2 -> V_127 ;
return 0 ;
}
static int F_39 ( struct V_21 * V_22 , T_3 * V_160 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_2 V_71 = 0 ;
F_18 ( V_2 , & V_71 ) ;
F_8 ( 1 , L_46 , V_25 , V_71 ) ;
* V_160 = V_71 ;
return 0 ;
}
static int F_32 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_24 = 0 ;
if ( F_31 ( V_22 ) != V_13 ) {
V_24 = F_26 ( V_22 ) ;
if ( V_24 != V_13 )
return V_24 ;
}
V_24 |= F_11 ( V_2 ) ;
F_5 ( 100 ) ;
V_24 |= F_9 ( V_2 , V_54 , V_53 ) ;
return V_24 ;
}
static int F_40 ( struct V_21 * V_22 )
{
int V_24 ;
F_8 ( 1 , L_3 , V_25 ) ;
if ( V_161 )
return 0 ;
V_24 = F_7 ( V_22 ) ;
if ( V_24 != V_13 ) {
F_3 ( V_11
L_47 ,
V_25 ) ;
return - V_19 ;
} else
return V_13 ;
}
static int F_41 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_8 ( 1 , L_3 , V_25 ) ;
if ( F_32 ( V_22 ) != V_13 ) {
F_3 ( V_11 L_48 ) ;
return - V_19 ;
}
if ( V_126 )
F_29 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_8 ( 1 , L_3 , V_25 ) ;
F_43 ( & V_162 ) ;
if ( V_2 )
F_44 ( V_2 ) ;
F_45 ( & V_162 ) ;
V_22 -> V_23 = NULL ;
return 0 ;
}
static int F_46 ( struct V_21 * V_22 , void * V_163 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_164 * V_165 = V_163 ;
F_8 ( 1 , L_3 , V_25 ) ;
if ( V_165 -> V_122 )
V_2 -> V_122 = V_165 -> V_122 ;
if ( V_165 -> V_149 )
V_2 -> V_149 = V_165 -> V_149 ;
return 0 ;
}
struct V_21 * F_47 ( struct V_21 * V_22 ,
struct V_166 * V_167 ,
const struct V_164 * V_168 )
{
struct V_1 * V_2 = NULL ;
int V_169 ;
T_2 V_128 = 0 ;
F_8 ( 1 , L_49 , V_25 ,
V_167 ? F_48 ( V_167 ) : - 1 ,
V_168 ? V_168 -> V_170 : - 1 ) ;
F_43 ( & V_162 ) ;
V_169 = F_49 ( struct V_1 , V_2 ,
V_171 ,
V_167 , V_168 -> V_170 , L_50 ) ;
switch ( V_169 ) {
case 0 :
goto V_172;
break;
case 1 :
V_2 -> V_127 = 6000000 ;
V_22 -> V_23 = V_2 ;
break;
default:
V_22 -> V_23 = V_2 ;
break;
}
if ( V_2 -> V_122 == 0 ) {
V_2 -> V_122 = V_168 -> V_122 ;
}
if ( V_2 -> V_149 == 0 )
V_2 -> V_149 = V_168 -> V_149 ;
if ( F_4 ( V_2 , V_129 , & V_128 ) != V_13 )
goto V_172;
switch ( V_128 ) {
case V_173 :
F_3 ( V_94
L_51 ,
V_168 -> V_170 ) ;
F_3 ( V_94
L_52 ) ;
break;
case V_130 :
F_3 ( V_94
L_51 ,
V_168 -> V_170 ) ;
F_3 ( V_94
L_53 ) ;
break;
default:
F_3 ( V_11
L_54 ,
V_168 -> V_170 , V_128 ) ;
goto V_172;
}
F_45 ( & V_162 ) ;
memcpy ( & V_22 -> V_174 . V_175 , & V_57 ,
sizeof( struct V_176 ) ) ;
return V_22 ;
V_172:
F_45 ( & V_162 ) ;
F_42 ( V_22 ) ;
return NULL ;
}
