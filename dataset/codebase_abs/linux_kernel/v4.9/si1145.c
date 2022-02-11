static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
unsigned long V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_5 , V_8 ,
V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( V_10 ) ;
V_6 = V_11 + V_12 * V_13 / 1000 ;
while ( true ) {
V_7 = F_4 ( V_2 -> V_5 ,
V_14 ) ;
if ( V_7 <= 0 )
return V_7 ;
if ( F_5 ( V_11 , V_6 ) ) {
F_6 ( V_4 , L_1 ) ;
return - V_15 ;
}
F_3 ( V_10 ) ;
continue;
}
}
static int F_7 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
unsigned long V_6 ;
int V_7 ;
F_8 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_18 < 0 ) {
V_7 = F_1 ( V_2 ) ;
if ( V_7 < 0 ) {
F_9 ( V_4 , L_2 ,
V_7 ) ;
goto V_19;
}
V_2 -> V_18 = 0 ;
}
V_7 = F_2 ( V_2 -> V_5 , V_8 , V_16 ) ;
if ( V_7 ) {
F_6 ( V_4 , L_3 , V_7 ) ;
goto V_19;
}
F_3 ( V_10 ) ;
V_6 = V_11 + V_12 * V_13 / 1000 ;
while ( true ) {
V_7 = F_4 ( V_2 -> V_5 ,
V_14 ) ;
if ( V_7 < 0 ) {
F_6 ( V_4 , L_4 , V_7 ) ;
break;
}
if ( ( V_7 & ~ V_20 ) == 0 ) {
if ( V_7 == V_2 -> V_18 ) {
if ( F_5 ( V_11 , V_6 ) ) {
F_6 ( V_4 , L_5 ,
V_16 ) ;
V_7 = - V_15 ;
break;
}
F_3 ( V_10 ) ;
continue;
}
if ( V_7 == ( ( V_2 -> V_18 + 1 ) &
V_20 ) ) {
V_2 -> V_18 = V_7 ;
V_7 = 0 ;
break;
}
F_6 ( V_4 , L_6 ,
V_7 , ( V_2 -> V_18 + 1 ) &
V_20 ) ;
V_7 = - V_21 ;
} else {
if ( V_7 == V_22 ) {
F_6 ( V_4 , L_7 ,
V_16 ) ;
V_7 = - V_23 ;
} else {
F_10 ( V_4 , L_8 ,
V_7 , V_16 ) ;
V_7 = - V_24 ;
}
}
V_2 -> V_18 = - 1 ;
break;
}
V_19:
F_11 ( & V_2 -> V_17 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_25 , T_1 V_26 ,
T_1 V_27 )
{
int V_7 ;
V_7 = F_2 ( V_2 -> V_5 ,
V_28 , V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_7 ( V_2 , V_25 | ( V_26 & 0x1F ) ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_27 )
{
return F_12 ( V_2 , V_29 , V_26 , V_27 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_26 )
{
int V_7 ;
V_7 = F_7 ( V_2 , V_30 | ( V_26 & 0x1F ) ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_2 -> V_5 , V_31 ) ;
}
static T_2 F_15 ( T_1 V_32 )
{
T_2 V_33 = 0 ;
T_1 V_34 = 0 ;
if ( V_32 < 8 )
return 0 ;
V_34 = ( V_32 & 0xf0 ) >> 4 ;
V_33 = 0x10 | ( V_32 & 0x0f ) ;
if ( V_34 >= 4 )
return V_33 << ( V_34 - 4 ) ;
return V_33 >> ( 4 - V_34 ) ;
}
static T_1 F_16 ( T_2 V_32 )
{
T_3 V_34 = 0 ;
T_3 V_35 = 0 ;
T_3 V_36 = V_32 ;
if ( V_32 == 0x0000 )
return 0x00 ;
if ( V_32 == 0x0001 )
return 0x08 ;
while ( 1 ) {
V_36 >>= 1 ;
V_34 += 1 ;
if ( V_36 == 1 )
break;
}
if ( V_34 < 5 ) {
V_35 = V_32 << ( 4 - V_34 ) ;
return ( V_34 << 4 ) | ( V_35 & 0xF ) ;
}
V_35 = V_32 >> ( V_34 - 5 ) ;
if ( V_35 & 1 ) {
V_35 += 2 ;
if ( V_35 & 0x0040 ) {
V_34 += 1 ;
V_35 >>= 1 ;
}
}
return ( V_34 << 4 ) | ( ( V_35 >> 1 ) & 0xF ) ;
}
static int F_17 ( struct V_1 * V_2 , int V_37 )
{
if ( V_2 -> V_38 -> V_39 )
return F_18 ( V_2 -> V_5 ,
V_40 , V_37 ) ;
else
return F_2 ( V_2 -> V_5 ,
V_40 , V_37 ) ;
}
static int F_19 ( struct V_1 * V_2 , int * V_41 , int * V_42 )
{
* V_41 = 32000 ;
if ( V_2 -> V_38 -> V_39 )
* V_42 = V_2 -> V_43 ;
else
* V_42 = F_15 ( V_2 -> V_43 ) ;
return V_44 ;
}
static int F_20 ( struct V_1 * V_2 , int V_41 )
{
int V_7 = 0 ;
int V_43 ;
if ( V_41 <= 0 || V_41 > 32000 )
return - V_45 ;
V_43 = 32000 / V_41 ;
F_8 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_47 ) {
V_7 = F_17 ( V_2 , V_43 ) ;
if ( V_7 )
goto V_19;
}
if ( V_2 -> V_38 -> V_39 )
V_2 -> V_43 = V_43 ;
else
V_2 -> V_43 = F_16 ( V_43 ) ;
V_19:
F_11 ( & V_2 -> V_46 ) ;
return V_7 ;
}
static T_4 F_21 ( int V_48 , void * V_49 )
{
struct V_50 * V_51 = V_49 ;
struct V_52 * V_53 = V_51 -> V_53 ;
struct V_1 * V_2 = F_22 ( V_53 ) ;
T_1 V_54 [ 24 ] ;
int V_55 , V_56 = 0 ;
int V_7 ;
T_1 V_57 = 0 ;
if ( ! V_2 -> V_47 ) {
V_7 = F_7 ( V_2 , V_58 ) ;
if ( V_7 < 0 && V_7 != - V_24 )
goto V_59;
} else {
V_57 = V_7 = F_4 ( V_2 -> V_5 ,
V_60 ) ;
if ( V_7 < 0 )
goto V_59;
if ( ! ( V_57 & V_61 ) )
goto V_59;
}
F_23 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
int V_62 = 1 ;
while ( V_55 + V_62 < V_53 -> V_63 ) {
if ( ! F_24 ( V_55 + V_62 , V_53 -> V_64 ) )
break;
if ( V_53 -> V_65 [ V_55 + V_62 ] . V_66 !=
V_53 -> V_65 [ V_55 ] . V_66 + 2 * V_62 )
break;
V_62 ++ ;
}
V_7 = F_25 (
V_2 -> V_5 , V_53 -> V_65 [ V_55 ] . V_66 ,
sizeof( T_2 ) * V_62 , & V_54 [ V_56 ] ) ;
if ( V_7 < 0 )
goto V_59;
V_56 += V_62 * sizeof( T_2 ) ;
V_55 += V_62 - 1 ;
}
if ( V_2 -> V_47 ) {
V_7 = F_2 ( V_2 -> V_5 ,
V_60 ,
V_57 & V_61 ) ;
if ( V_7 < 0 )
goto V_59;
}
F_26 ( V_53 , V_54 ,
F_27 ( V_53 ) ) ;
V_59:
F_28 ( V_53 -> V_67 ) ;
return V_68 ;
}
static int F_29 ( struct V_52 * V_53 , unsigned long V_69 )
{
struct V_1 * V_2 = F_22 ( V_53 ) ;
T_1 V_70 = 0 , V_71 ;
int V_7 ;
int V_55 ;
if ( V_2 -> V_69 == V_69 )
return 0 ;
F_23 (i, &scan_mask, indio_dev->masklength) {
switch ( V_53 -> V_65 [ V_55 ] . V_66 ) {
case V_72 :
V_70 |= V_73 ;
break;
case V_74 :
V_70 |= V_75 ;
break;
case V_76 :
V_70 |= V_77 ;
break;
case V_78 :
V_70 |= V_79 ;
break;
case V_80 :
V_70 |= V_81 ;
break;
case V_82 :
switch ( V_53 -> V_65 [ V_55 ] . type ) {
case V_83 :
V_70 |= V_84 ;
break;
default:
V_70 |= V_85 ;
if ( V_53 -> V_65 [ V_55 ] . type == V_86 )
V_71 = V_87 ;
else
V_71 = V_88 ;
V_7 = F_13 ( V_2 ,
V_89 , V_71 ) ;
if ( V_7 < 0 )
return V_7 ;
break;
}
}
}
V_2 -> V_69 = V_69 ;
V_7 = F_13 ( V_2 , V_90 , V_70 ) ;
return V_7 < 0 ? V_7 : 0 ;
}
static int F_30 ( struct V_52 * V_53 ,
struct V_91 const * V_92 )
{
struct V_1 * V_2 = F_22 ( V_53 ) ;
T_1 V_16 ;
int V_7 ;
V_7 = F_29 ( V_53 , F_31 ( V_92 -> V_93 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_16 = ( V_92 -> type == V_94 ) ? V_95 :
V_96 ;
V_7 = F_7 ( V_2 , V_16 ) ;
if ( V_7 < 0 && V_7 != - V_24 )
return V_7 ;
return F_32 ( V_2 -> V_5 , V_92 -> V_66 ) ;
}
static int F_33 ( int V_97 )
{
return 128 >> V_97 ;
}
static int F_34 ( int V_41 , int V_42 )
{
V_41 = F_35 ( V_41 , V_98 ,
F_36 ( V_98 ) ) ;
if ( V_41 < 0 || V_41 > 5 || V_42 != 0 )
return - V_23 ;
return V_41 ;
}
static int F_37 ( int V_41 , int V_42 )
{
V_41 = F_35 ( V_41 , V_99 ,
F_36 ( V_99 ) ) ;
if ( V_41 < 0 || V_41 > 7 || V_42 != 0 )
return - V_23 ;
return V_41 ;
}
static int F_38 ( struct V_52 * V_53 ,
struct V_91 const * V_92 ,
int * V_41 , int * V_42 , long V_100 )
{
struct V_1 * V_2 = F_22 ( V_53 ) ;
int V_7 ;
T_1 V_70 ;
switch ( V_100 ) {
case V_101 :
switch ( V_92 -> type ) {
case V_102 :
case V_94 :
case V_103 :
case V_86 :
case V_83 :
V_7 = F_39 ( V_53 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_30 ( V_53 , V_92 ) ;
F_40 ( V_53 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_41 = V_7 ;
return V_104 ;
case V_105 :
V_7 = F_4 ( V_2 -> V_5 ,
F_41 ( V_92 -> V_106 ) ) ;
if ( V_7 < 0 )
return V_7 ;
* V_41 = ( V_7 >> F_42 ( V_92 -> V_106 ) )
& 0x0f ;
return V_104 ;
default:
return - V_23 ;
}
case V_107 :
switch ( V_92 -> type ) {
case V_94 :
V_70 = V_108 ;
break;
case V_102 :
if ( V_92 -> V_109 == V_110 )
V_70 = V_111 ;
else
V_70 = V_112 ;
break;
case V_86 :
* V_41 = 28 ;
* V_42 = 571429 ;
return V_113 ;
case V_83 :
* V_41 = 0 ;
* V_42 = 10000 ;
return V_113 ;
default:
return - V_23 ;
}
V_7 = F_14 ( V_2 , V_70 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_41 = F_33 ( V_7 & 0x07 ) ;
return V_104 ;
case V_114 :
switch ( V_92 -> type ) {
case V_86 :
* V_41 = - 256 - 11136 + 25 * 35 ;
return V_104 ;
default:
V_7 = F_14 ( V_2 , V_115 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_41 = - F_15 ( V_7 ) ;
return V_104 ;
}
case V_116 :
return F_19 ( V_2 , V_41 , V_42 ) ;
default:
return - V_23 ;
}
}
static int F_43 ( struct V_52 * V_53 ,
struct V_91 const * V_92 ,
int V_41 , int V_42 , long V_100 )
{
struct V_1 * V_2 = F_22 ( V_53 ) ;
T_1 V_117 , V_118 , V_119 ;
int V_7 ;
switch ( V_100 ) {
case V_107 :
switch ( V_92 -> type ) {
case V_94 :
V_41 = F_34 ( V_41 , V_42 ) ;
if ( V_41 < 0 )
return V_41 ;
V_117 = V_108 ;
V_118 = V_120 ;
break;
case V_102 :
V_41 = F_37 ( V_41 , V_42 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_92 -> V_109 == V_110 ) {
V_117 = V_111 ;
V_118 = V_121 ;
} else {
V_117 = V_112 ;
V_118 = V_122 ;
}
break;
default:
return - V_23 ;
}
V_7 = F_39 ( V_53 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_13 ( V_2 , V_117 , V_41 ) ;
if ( V_7 < 0 ) {
F_40 ( V_53 ) ;
return V_7 ;
}
V_7 = F_13 ( V_2 , V_118 , ( ~ V_41 & 0x07 ) << 4 ) ;
F_40 ( V_53 ) ;
return V_7 ;
case V_101 :
if ( V_92 -> type != V_105 )
return - V_23 ;
if ( V_41 < 0 || V_41 > 15 || V_42 != 0 )
return - V_23 ;
V_117 = F_41 ( V_92 -> V_106 ) ;
V_119 = F_42 ( V_92 -> V_106 ) ;
V_7 = F_39 ( V_53 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_5 , V_117 ) ;
if ( V_7 < 0 ) {
F_40 ( V_53 ) ;
return V_7 ;
}
V_7 = F_2 ( V_2 -> V_5 , V_117 ,
( V_7 & ~ ( 0x0f << V_119 ) ) |
( ( V_41 & 0x0f ) << V_119 ) ) ;
F_40 ( V_53 ) ;
return V_7 ;
case V_116 :
return F_20 ( V_2 , V_41 ) ;
default:
return - V_23 ;
}
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_123 * V_5 = V_2 -> V_5 ;
int V_7 ;
V_7 = F_2 ( V_5 , V_8 ,
V_124 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( V_12 ) ;
V_7 = F_2 ( V_5 , V_125 , 0x17 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( V_12 ) ;
V_7 = F_17 ( V_2 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_20 ( V_2 , 10 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_2 -> V_38 -> V_126 ) {
case 3 :
V_7 = F_2 ( V_5 ,
V_127 ,
V_128 ) ;
if ( V_7 < 0 )
return V_7 ;
case 2 :
V_7 = F_2 ( V_5 ,
V_129 ,
( V_128 << 4 ) |
V_128 ) ;
break;
case 1 :
V_7 = F_2 ( V_5 ,
V_129 ,
V_128 ) ;
break;
default:
V_7 = 0 ;
break;
}
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_130 ,
V_131 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_108 , 0x01 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_120 , 0x06 << 4 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_132 ,
V_133 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_112 , 0x03 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_122 ,
0x04 << 4 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_134 ,
V_133 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_111 , 0x01 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_121 ,
0x06 << 4 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_2 -> V_38 == & V_135 [ V_136 ] ||
V_2 -> V_38 == & V_135 [ V_137 ] ||
V_2 -> V_38 == & V_135 [ V_138 ] ||
V_2 -> V_38 == & V_135 [ V_139 ] ) {
V_7 = F_2 ( V_2 -> V_5 ,
V_140 ,
V_141 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_2 ( V_2 -> V_5 ,
V_142 , V_143 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_2 ( V_2 -> V_5 ,
V_144 , V_145 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_2 ( V_2 -> V_5 ,
V_146 , V_147 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_45 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_22 ( V_53 ) ;
int V_7 ;
F_8 ( & V_2 -> V_46 ) ;
V_7 = F_29 ( V_53 , * V_53 -> V_64 ) ;
F_11 ( & V_2 -> V_46 ) ;
return V_7 ;
}
static bool F_46 ( struct V_52 * V_53 ,
const unsigned long * V_69 )
{
struct V_1 * V_2 = F_22 ( V_53 ) ;
unsigned int V_148 = 0 ;
int V_55 ;
F_23 (i, scan_mask, data->part_info->num_channels) {
if ( V_53 -> V_65 [ V_55 ] . V_66 == V_82 )
V_148 ++ ;
}
return V_148 <= 1 ;
}
static int F_47 ( struct V_149 * V_67 , bool V_150 )
{
struct V_52 * V_53 = F_48 ( V_67 ) ;
struct V_1 * V_2 = F_22 ( V_53 ) ;
int V_151 = 0 , V_7 ;
F_8 ( & V_2 -> V_46 ) ;
if ( V_150 ) {
V_2 -> V_47 = true ;
V_151 = F_2 ( V_2 -> V_5 ,
V_152 , V_153 ) ;
if ( V_151 < 0 )
goto V_154;
V_151 = F_2 ( V_2 -> V_5 ,
V_155 , V_61 ) ;
if ( V_151 < 0 )
goto V_154;
V_151 = F_17 ( V_2 , V_2 -> V_43 ) ;
if ( V_151 < 0 )
goto V_154;
V_151 = F_7 ( V_2 , V_156 ) ;
if ( V_151 < 0 )
goto V_154;
} else {
V_154:
V_7 = F_7 ( V_2 , V_157 ) ;
if ( V_7 < 0 && ! V_151 )
V_151 = V_7 ;
V_7 = F_17 ( V_2 , 0 ) ;
if ( V_7 < 0 && ! V_151 )
V_151 = V_7 ;
V_7 = F_2 ( V_2 -> V_5 ,
V_155 , 0 ) ;
if ( V_7 < 0 && ! V_151 )
V_151 = V_7 ;
V_7 = F_2 ( V_2 -> V_5 ,
V_152 , 0 ) ;
if ( V_7 < 0 && ! V_151 )
V_151 = V_7 ;
V_2 -> V_47 = false ;
}
F_11 ( & V_2 -> V_46 ) ;
return V_151 ;
}
static int F_49 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_22 ( V_53 ) ;
struct V_123 * V_5 = V_2 -> V_5 ;
struct V_149 * V_67 ;
int V_7 ;
V_67 = F_50 ( & V_5 -> V_4 ,
L_9 , V_53 -> V_158 , V_53 -> V_159 ) ;
if ( ! V_67 )
return - V_160 ;
V_67 -> V_4 . V_161 = & V_5 -> V_4 ;
V_67 -> V_162 = & V_163 ;
F_51 ( V_67 , V_53 ) ;
V_7 = F_52 ( & V_5 -> V_4 , V_5 -> V_48 ,
V_164 ,
V_165 ,
L_10 ,
V_67 ) ;
if ( V_7 < 0 ) {
F_9 ( & V_5 -> V_4 , L_11 ) ;
return V_7 ;
}
V_7 = F_53 ( V_67 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_67 = V_67 ;
V_53 -> V_67 = F_54 ( V_2 -> V_67 ) ;
return 0 ;
}
static void F_55 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_22 ( V_53 ) ;
if ( V_2 -> V_67 ) {
F_56 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
}
static int F_57 ( struct V_123 * V_5 ,
const struct V_166 * V_159 )
{
struct V_1 * V_2 ;
struct V_52 * V_53 ;
T_1 V_167 , V_168 , V_169 ;
int V_7 ;
V_53 = F_58 ( & V_5 -> V_4 , sizeof( * V_2 ) ) ;
if ( ! V_53 )
return - V_160 ;
V_2 = F_22 ( V_53 ) ;
F_59 ( V_5 , V_53 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_38 = & V_135 [ V_159 -> V_170 ] ;
V_167 = V_7 = F_4 ( V_2 -> V_5 ,
V_171 ) ;
if ( V_7 < 0 )
return V_7 ;
V_168 = V_7 = F_4 ( V_2 -> V_5 ,
V_172 ) ;
if ( V_7 < 0 )
return V_7 ;
V_169 = V_7 = F_4 ( V_2 -> V_5 ,
V_173 ) ;
if ( V_7 < 0 )
return V_7 ;
F_60 ( & V_5 -> V_4 , L_12 ,
V_167 , V_168 , V_169 ) ;
if ( V_167 != V_2 -> V_38 -> V_174 ) {
F_9 ( & V_5 -> V_4 , L_13 ,
V_167 , V_2 -> V_38 -> V_174 ) ;
return - V_175 ;
}
V_53 -> V_4 . V_161 = & V_5 -> V_4 ;
V_53 -> V_158 = V_159 -> V_158 ;
V_53 -> V_65 = V_2 -> V_38 -> V_65 ;
V_53 -> V_176 = V_2 -> V_38 -> V_176 ;
V_53 -> V_177 = V_2 -> V_38 -> V_178 ;
V_53 -> V_179 = V_180 ;
F_61 ( & V_2 -> V_46 ) ;
F_61 ( & V_2 -> V_17 ) ;
V_7 = F_44 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_62 ( V_53 , NULL ,
F_21 , & V_181 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_5 -> V_48 ) {
V_7 = F_49 ( V_53 ) ;
if ( V_7 < 0 )
goto V_182;
} else {
F_60 ( & V_5 -> V_4 , L_14 ) ;
}
V_7 = F_63 ( V_53 ) ;
if ( V_7 < 0 )
goto V_183;
return 0 ;
V_183:
F_55 ( V_53 ) ;
V_182:
F_64 ( V_53 ) ;
return V_7 ;
}
static int F_65 ( struct V_123 * V_5 )
{
struct V_52 * V_53 = F_66 ( V_5 ) ;
F_67 ( V_53 ) ;
F_55 ( V_53 ) ;
F_64 ( V_53 ) ;
return 0 ;
}
