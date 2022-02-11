static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 * V_5 )
{
int V_6 ;
struct V_7 V_8 [ 2 ] ;
unsigned char V_9 [ 4 ] ;
if ( ! V_2 -> V_10 ) {
F_2 ( V_2 , L_1 , V_11 ) ;
return - V_12 ;
}
if ( V_3 != V_13 && V_3 != V_14
&& V_3 != V_15 ) {
F_2 ( V_2 , L_2 , V_11 ) ;
return - V_16 ;
}
V_8 [ 0 ] . V_17 = V_2 -> V_17 ;
V_8 [ 0 ] . V_18 = 0 ;
V_8 [ 0 ] . V_19 = V_20 ;
V_8 [ 0 ] . V_21 = V_9 ;
V_9 [ 0 ] = ( T_1 ) ( V_4 >> 8 ) ;
V_9 [ 1 ] = ( T_1 ) ( V_4 & 0xff ) ;
V_8 [ 1 ] . V_17 = V_2 -> V_17 ;
V_8 [ 1 ] . V_19 = V_3 ;
V_8 [ 1 ] . V_18 = V_22 ;
V_8 [ 1 ] . V_21 = V_9 ;
V_6 = F_3 ( V_2 -> V_10 , V_8 , 2 ) ;
if ( V_6 >= 0 ) {
* V_5 = 0 ;
if ( V_3 == V_13 )
* V_5 = V_9 [ 0 ] ;
else if ( V_3 == V_14 )
* V_5 = V_9 [ 1 ] + ( V_9 [ 0 ] << 8 ) ;
else
* V_5 = V_9 [ 3 ] + ( V_9 [ 2 ] << 8 ) +
( V_9 [ 1 ] << 16 ) + ( V_9 [ 0 ] << 24 ) ;
return 0 ;
}
F_4 ( & V_2 -> V_23 , L_3 , V_4 , V_6 ) ;
return V_6 ;
}
static int
F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_2 V_5 )
{
int V_24 ;
struct V_7 V_8 ;
unsigned char V_9 [ 6 ] = { 0 } ;
T_1 * V_25 ;
int V_26 = 0 ;
if ( ! V_2 -> V_10 ) {
F_2 ( V_2 , L_1 , V_11 ) ;
return - V_12 ;
}
if ( V_3 != V_13 && V_3 != V_14
&& V_3 != V_15 ) {
F_2 ( V_2 , L_4 , V_11 ) ;
return - V_16 ;
}
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_27:
V_8 . V_17 = V_2 -> V_17 ;
V_8 . V_18 = 0 ;
V_8 . V_19 = 2 + V_3 ;
V_8 . V_21 = V_9 ;
V_25 = ( T_1 * ) V_9 ;
* V_25 = F_6 ( V_4 ) ;
if ( V_3 == V_13 ) {
V_9 [ 2 ] = ( V_28 ) ( V_5 ) ;
} else if ( V_3 == V_14 ) {
T_1 * V_29 = ( T_1 * ) & V_9 [ 2 ] ;
* V_29 = F_7 ( ( T_1 ) V_5 ) ;
} else {
T_2 * V_29 = ( T_2 * ) & V_9 [ 2 ] ;
* V_29 = F_8 ( V_5 ) ;
}
V_24 = F_3 ( V_2 -> V_10 , & V_8 , 1 ) ;
F_9 ( 1 ) ;
if ( V_24 >= 0 )
return 0 ;
F_4 ( & V_2 -> V_23 , L_5 ,
V_5 , V_4 , V_24 ) ;
if ( V_26 <= V_30 ) {
F_10 ( & V_2 -> V_23 , L_6 , V_26 ) ;
V_26 ++ ;
F_11 ( 20 ) ;
goto V_27;
}
return V_24 ;
}
static int
F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_2 V_31 , T_2 V_32 )
{
int V_6 ;
T_2 V_5 ;
if ( V_31 == 0 )
return 0 ;
switch ( V_3 ) {
case V_13 :
if ( V_31 & ~ 0xff )
return - V_16 ;
break;
case V_14 :
if ( V_31 & ~ 0xffff )
return - V_16 ;
break;
case V_15 :
break;
default:
return - V_16 ;
}
V_6 = F_1 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( V_6 ) {
F_2 ( V_2 , L_7 ) ;
return - V_16 ;
}
V_5 &= ~ V_31 ;
V_32 <<= F_13 ( V_31 ) - 1 ;
V_5 |= V_32 & V_31 ;
V_6 = F_5 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 ) {
F_2 ( V_2 , L_8 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_7 V_8 ;
const int V_24 = 1 ;
int V_35 ;
int V_26 = 0 ;
if ( V_34 -> V_36 == 0 )
return 0 ;
V_27:
V_8 . V_17 = V_2 -> V_17 ;
V_8 . V_18 = 0 ;
V_8 . V_19 = 2 + V_34 -> V_36 ;
V_34 -> V_37 . V_17 = F_6 ( V_34 -> V_37 . V_17 ) ;
V_8 . V_21 = ( V_28 * ) & V_34 -> V_37 ;
V_35 = F_3 ( V_2 -> V_10 , & V_8 , V_24 ) ;
if ( V_35 != V_24 ) {
if ( ++ V_26 <= V_30 ) {
F_10 ( & V_2 -> V_23 , L_9 , V_26 ) ;
F_11 ( 20 ) ;
goto V_27;
}
F_4 ( & V_2 -> V_23 , L_10 , V_11 ) ;
return - V_38 ;
}
V_34 -> V_36 = 0 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
const struct V_39 * V_40 )
{
T_1 * V_41 ;
T_2 * V_42 ;
int V_6 ;
if ( V_34 -> V_36 + V_40 -> V_43 >= V_44 ) {
V_6 = F_14 ( V_2 , V_34 ) ;
if ( V_6 )
return V_6 ;
}
switch ( V_40 -> V_43 ) {
case V_13 :
V_34 -> V_37 . V_9 [ V_34 -> V_36 ] = ( V_28 ) V_40 -> V_5 ;
break;
case V_14 :
V_41 = ( T_1 * ) & V_34 -> V_37 . V_9 [ V_34 -> V_36 ] ;
* V_41 = F_6 ( ( T_1 ) V_40 -> V_5 ) ;
break;
case V_15 :
V_42 = ( T_2 * ) & V_34 -> V_37 . V_9 [ V_34 -> V_36 ] ;
* V_42 = F_16 ( V_40 -> V_5 ) ;
break;
default:
return - V_16 ;
}
if ( V_34 -> V_36 == 0 )
V_34 -> V_37 . V_17 = V_40 -> V_4 ;
V_34 -> V_36 += V_40 -> V_43 ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
const struct V_39 * V_40 )
{
if ( V_34 -> V_36 == 0 )
return 1 ;
return V_34 -> V_37 . V_17 + V_34 -> V_36 == V_40 -> V_4 ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_39 * V_45 ,
int V_46 )
{
const struct V_39 * V_40 = V_45 ;
struct V_33 V_34 ;
int V_6 ;
if ( V_46 == V_47 ) {
V_6 = F_19 ( V_2 , V_48 ) ;
if ( V_6 )
return V_6 ;
}
V_34 . V_36 = 0 ;
for (; V_40 -> V_43 != V_49 ; V_40 ++ ) {
switch ( V_40 -> V_43 & V_50 ) {
case V_51 :
V_6 = F_14 ( V_2 , & V_34 ) ;
if ( V_6 )
return V_6 ;
F_11 ( V_40 -> V_5 ) ;
break;
case V_52 :
V_6 = F_14 ( V_2 , & V_34 ) ;
V_6 |= F_12 ( V_2 ,
V_40 -> V_43 &
~ V_52 ,
V_40 -> V_4 , V_40 -> V_5 ,
V_40 -> V_53 ) ;
if ( V_6 ) {
F_4 ( & V_2 -> V_23 , L_11 ,
V_11 ) ;
return - V_16 ;
}
break;
default:
if ( ! F_17 ( V_2 , & V_34 ,
V_40 ) ) {
V_6 = F_14 ( V_2 , & V_34 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_15 ( V_2 , & V_34 , V_40 ) ;
if ( V_6 ) {
F_2 ( V_2 , L_12 ,
V_11 ) ;
return V_6 ;
}
break;
}
}
V_6 = F_14 ( V_2 , & V_34 ) ;
if ( V_6 )
return V_6 ;
if ( V_46 == V_54 )
return F_19 ( V_2 , V_48 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_55 )
{
int V_35 ;
unsigned int V_5 ;
while ( V_55 -- > 0 ) {
V_35 = F_1 ( V_2 , V_14 , 0x0080 , & V_5 ) ;
if ( V_35 )
return V_35 ;
if ( ( V_5 & 0x2 ) == 0 )
return 0 ;
F_11 ( 20 ) ;
}
return - V_16 ;
}
static int F_20 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_21 ( V_57 ) ;
return F_18 ( V_2 ,
V_58 , V_54 ) ;
}
static int F_22 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_21 ( V_57 ) ;
return F_18 ( V_2 , V_59 , V_47 ) ;
}
static int F_23 ( struct V_56 * V_57 , bool V_60 )
{
int V_35 ;
struct V_61 * V_23 = F_24 ( V_57 ) ;
if ( ! V_23 || ! V_23 -> V_62 )
return - V_12 ;
if ( V_23 -> V_62 -> F_23 )
return V_23 -> V_62 -> F_23 ( V_57 , V_60 ) ;
if ( V_60 ) {
V_35 = V_23 -> V_62 -> V_63 ( V_57 , 1 ) ;
if ( V_35 == 0 ) {
V_35 = V_23 -> V_62 -> V_64 ( V_57 , 1 ) ;
if ( V_35 )
V_35 = V_23 -> V_62 -> V_63 ( V_57 , 0 ) ;
}
} else {
V_35 = V_23 -> V_62 -> V_63 ( V_57 , 0 ) ;
V_35 = V_23 -> V_62 -> V_64 ( V_57 , 0 ) ;
}
return V_35 ;
}
static int F_25 ( struct V_56 * V_57 , bool V_60 )
{
int V_35 ;
struct V_61 * V_23 = F_24 ( V_57 ) ;
if ( ! V_23 || ! V_23 -> V_62 )
return - V_12 ;
if ( V_23 -> V_62 -> F_25 )
return V_23 -> V_62 -> F_25 ( V_57 , V_60 ) ;
if ( V_60 ) {
V_35 = V_23 -> V_62 -> V_65 ( V_57 , 0 ) ;
V_35 = V_23 -> V_62 -> V_66 ( V_57 , 0 ) ;
F_11 ( 60 ) ;
V_35 |= V_23 -> V_62 -> V_65 ( V_57 , 1 ) ;
V_35 |= V_23 -> V_62 -> V_66 ( V_57 , 1 ) ;
} else {
V_35 = V_23 -> V_62 -> V_65 ( V_57 , 0 ) ;
V_35 = V_23 -> V_62 -> V_66 ( V_57 , 0 ) ;
}
return V_35 ;
}
static int F_26 ( struct V_56 * V_57 )
{
struct V_61 * V_23 = F_24 ( V_57 ) ;
struct V_1 * V_2 = F_21 ( V_57 ) ;
int V_35 ;
if ( NULL == V_23 -> V_62 ) {
F_4 ( & V_2 -> V_23 , L_13 ) ;
return - V_12 ;
}
V_35 = F_23 ( V_57 , 1 ) ;
if ( V_35 )
goto V_67;
V_35 = V_23 -> V_62 -> V_68 ( V_57 , 1 ) ;
if ( V_35 )
goto V_69;
V_35 = F_25 ( V_57 , 1 ) ;
if ( V_35 )
F_4 ( & V_2 -> V_23 , L_14 ) ;
F_11 ( 50 ) ;
return 0 ;
V_69:
V_23 -> V_62 -> V_68 ( V_57 , 0 ) ;
V_67:
F_23 ( V_57 , 0 ) ;
F_4 ( & V_2 -> V_23 , L_15 ) ;
return V_35 ;
}
static int F_27 ( struct V_56 * V_57 )
{
struct V_61 * V_23 = F_24 ( V_57 ) ;
struct V_1 * V_2 = F_21 ( V_57 ) ;
int V_35 ;
if ( NULL == V_23 -> V_62 ) {
F_4 ( & V_2 -> V_23 , L_13 ) ;
return - V_12 ;
}
V_35 = V_23 -> V_62 -> V_68 ( V_57 , 0 ) ;
if ( V_35 )
F_4 ( & V_2 -> V_23 , L_16 ) ;
V_35 = F_25 ( V_57 , 0 ) ;
if ( V_35 )
F_4 ( & V_2 -> V_23 , L_14 ) ;
V_35 = F_23 ( V_57 , 0 ) ;
if ( V_35 )
F_4 ( & V_2 -> V_23 , L_17 ) ;
F_11 ( 20 ) ;
return V_35 ;
}
static int F_28 ( struct V_56 * V_57 , int V_70 )
{
if ( V_70 == 0 )
return F_27 ( V_57 ) ;
else {
if ( F_26 ( V_57 ) )
return - V_16 ;
return F_22 ( V_57 ) ;
}
}
static int F_29 ( struct V_71 const * V_72 , T_2 V_73 , T_2 V_74 )
{
unsigned int V_75 ;
unsigned int V_76 ;
int V_77 ;
if ( V_73 == 0 )
return - 1 ;
V_75 = ( V_72 -> V_78 << 13 ) / V_73 ;
if ( V_74 == 0 )
return - 1 ;
V_76 = ( V_72 -> V_79 << 13 ) / V_74 ;
if ( V_76 == 0 )
return - 1 ;
V_77 = abs ( ( ( V_75 << 13 ) / V_76 ) - 8192 ) ;
if ( ( V_75 < 8192 ) || ( V_76 < 8192 ) ||
( V_77 > V_80 ) )
return - 1 ;
return V_75 + V_76 ;
}
static int F_30 ( int V_73 , int V_74 )
{
int V_81 ;
int V_82 = - 1 ;
int V_83 ;
int V_84 = V_85 ;
const struct V_71 * V_86 = NULL ;
for ( V_81 = 0 ; V_81 < F_31 ( V_87 ) ; V_81 ++ ) {
V_86 = & V_87 [ V_81 ] ;
V_83 = F_29 ( V_86 , V_73 , V_74 ) ;
if ( V_83 == - 1 )
continue;
if ( V_83 < V_84 ) {
V_84 = V_83 ;
V_82 = V_81 ;
}
}
return V_82 ;
}
static int F_32 ( T_2 * V_73 , T_2 * V_74 )
{
int V_82 = 0 ;
if ( ( * V_73 > V_88 )
|| ( * V_74 > V_89 ) ) {
* V_73 = V_88 ;
* V_74 = V_89 ;
} else {
V_82 = F_30 ( * V_73 , * V_74 ) ;
if ( V_82 == - 1 )
V_82 = F_31 ( V_87 ) - 1 ;
* V_73 = V_87 [ V_82 ] . V_78 ;
* V_74 = V_87 [ V_82 ] . V_79 ;
}
return 0 ;
}
static struct V_71 * F_33 ( T_2 V_73 , T_2 V_74 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_90 ; V_36 ++ ) {
if ( ( V_87 [ V_36 ] . V_78 == V_73 ) &&
( V_87 [ V_36 ] . V_79 == V_74 ) )
break;
}
if ( V_36 >= V_90 )
return NULL ;
return & V_87 [ V_36 ] ;
}
static int F_34 ( struct V_56 * V_57 , int * V_91 , int * V_92 )
{
struct V_61 * V_23 = F_24 ( V_57 ) ;
unsigned short V_93 ;
unsigned short V_94 ;
switch ( V_23 -> V_72 ) {
case V_95 :
V_93 = V_96 ;
V_94 = V_97 ;
break;
case V_98 :
V_93 = V_99 ;
V_94 = V_100 ;
break;
case V_101 :
V_93 = V_88 ;
V_94 = V_89 ;
break;
default:
F_2 ( V_57 , L_18 , V_11 ,
V_23 -> V_72 ) ;
return - V_16 ;
}
if ( V_91 != NULL )
* V_91 = V_93 ;
if ( V_92 != NULL )
* V_92 = V_94 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_102 * V_103 ,
const struct V_71 * V_72 )
{
struct V_104 * V_21 = & V_103 -> V_9 ;
T_2 V_105 ;
int V_35 ;
if ( V_103 == NULL )
return - V_16 ;
V_35 = F_1 ( V_2 , V_15 ,
V_106 , & V_105 ) ;
if ( V_35 )
return V_35 ;
V_21 -> V_107 = V_105 ;
V_21 -> V_108 = V_109 ;
V_21 -> V_110 =
V_111 ;
V_21 -> V_112 = V_113 ;
V_21 -> V_114 =
V_115 ;
V_21 -> V_116 = V_113 ;
V_21 -> V_117 = V_72 -> V_118 ;
V_21 -> V_119 = V_72 -> V_120 ;
V_21 -> V_121 = V_72 -> V_122 ;
V_35 = F_1 ( V_2 , V_14 ,
V_123 , & V_105 ) ;
if ( V_35 )
return V_35 ;
V_21 -> V_124 = V_105 ;
V_35 = F_1 ( V_2 , V_14 ,
V_125 , & V_105 ) ;
if ( V_35 )
return V_35 ;
V_21 -> V_126 = V_105 ;
V_35 = F_1 ( V_2 , V_14 ,
V_127 , & V_105 ) ;
if ( V_35 )
return V_35 ;
V_21 -> V_128 = V_105 ;
V_35 = F_1 ( V_2 , V_14 ,
V_129 , & V_105 ) ;
if ( V_35 )
return V_35 ;
V_21 -> V_130 = V_105 ;
V_35 = F_1 ( V_2 , V_14 ,
V_131 , & V_105 ) ;
if ( V_35 )
return V_35 ;
V_21 -> V_132 = V_105 ;
V_35 = F_1 ( V_2 , V_14 ,
V_133 , & V_105 ) ;
if ( V_35 )
return V_35 ;
V_21 -> V_134 = V_105 ;
V_35 = F_1 ( V_2 , V_14 ,
V_135 , & V_105 ) ;
if ( V_35 )
return V_35 ;
V_21 -> V_119 = V_105 ;
V_35 = F_1 ( V_2 , V_14 ,
V_136 , & V_105 ) ;
if ( V_35 )
return V_35 ;
V_21 -> V_117 = V_105 ;
V_21 -> V_137 = V_72 -> V_138 ?
V_72 -> V_138 : 1 ;
V_21 -> V_139 = V_72 -> V_140 ?
V_72 -> V_140 : 1 ;
return 0 ;
}
static int F_36 ( struct V_56 * V_57 ,
struct V_141 * V_142 ,
struct V_143 * V_144 )
{
struct V_145 * V_146 = & V_144 -> V_144 ;
int V_78 , V_79 ;
int V_35 ;
if ( V_144 -> V_147 )
return - V_16 ;
V_146 -> V_148 = V_149 ;
V_35 = F_34 ( V_57 , & V_78 , & V_79 ) ;
if ( V_35 )
return V_35 ;
V_146 -> V_78 = V_78 ;
V_146 -> V_79 = V_79 ;
return 0 ;
}
static int F_37 ( struct V_56 * V_57 ,
struct V_141 * V_142 ,
struct V_143 * V_144 )
{
struct V_145 * V_146 = & V_144 -> V_144 ;
struct V_1 * V_150 = F_21 ( V_57 ) ;
struct V_61 * V_23 = F_24 ( V_57 ) ;
struct V_71 * V_151 ;
T_2 V_78 = V_146 -> V_78 ;
T_2 V_79 = V_146 -> V_79 ;
struct V_102 * V_152 = NULL ;
int V_35 ;
if ( V_144 -> V_147 )
return - V_16 ;
V_23 -> V_153 = 0 ;
V_23 -> V_154 = V_155 ;
V_152 = F_38 ( V_57 ) ;
if ( V_152 == NULL )
return - V_16 ;
F_32 ( & V_78 , & V_79 ) ;
if ( V_144 -> V_156 == V_157 ) {
V_142 -> V_158 = * V_146 ;
return 0 ;
}
V_151 = F_33 ( V_78 , V_79 ) ;
if ( F_39 ( ! V_151 ) ) {
F_40 ( 1 ) ;
return - V_16 ;
}
switch ( V_151 -> V_72 ) {
case V_95 :
V_35 = F_18 ( V_150 , V_159 , V_160 ) ;
V_35 += F_12 ( V_150 , V_14 , V_161 ,
V_162 , V_163 ) ;
break;
case V_98 :
V_35 = F_18 ( V_150 , V_164 , V_160 ) ;
V_35 += F_12 ( V_150 , V_14 , V_161 ,
V_162 , V_163 ) ;
break;
case V_101 :
V_35 = F_18 ( V_150 , V_165 , V_160 ) ;
V_35 += F_12 ( V_150 , V_14 , V_161 ,
V_162 , V_163 ) ;
break;
default:
F_2 ( V_57 , L_19 , V_151 -> V_72 ) ;
return - V_16 ;
}
if ( V_35 )
return - V_16 ;
V_35 = F_18 ( V_150 , V_166 , V_54 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( F_20 ( V_57 ) )
return - V_16 ;
if ( V_23 -> V_72 != V_151 -> V_72 ) {
int V_36 ;
if ( V_78 <= 640 ) {
V_23 -> V_167 = 0x00 ;
} else {
V_23 -> V_167 = 0x01 ;
}
for ( V_36 = 0 ; V_36 < V_90 ; V_36 ++ ) {
if ( ( V_78 == V_87 [ V_36 ] . V_78 ) &&
( V_79 == V_87 [ V_36 ] . V_79 ) ) {
V_87 [ V_36 ] . V_168 = true ;
continue;
}
V_87 [ V_36 ] . V_168 = false ;
}
}
V_35 = F_35 ( V_150 , V_152 ,
& V_87 [ V_151 -> V_72 ] ) ;
if ( V_35 ) {
F_4 ( & V_150 -> V_23 , L_20 ) ;
return - V_16 ;
}
V_23 -> V_72 = V_151 -> V_72 ;
V_146 -> V_78 = V_78 ;
V_146 -> V_79 = V_79 ;
V_146 -> V_148 = V_149 ;
return 0 ;
}
static int F_41 ( struct V_56 * V_57 , T_3 * V_5 )
{
* V_5 = ( V_169 << 16 ) | V_170 ;
return 0 ;
}
static int F_42 ( struct V_56 * V_57 , T_3 * V_5 )
{
* V_5 = ( V_171 << 16 ) | V_172 ;
return 0 ;
}
static int F_43 ( struct V_56 * V_57 , T_3 * V_5 )
{
* V_5 = ( V_171 << 24 ) |
( V_172 << 16 ) |
( V_171 << 8 ) | V_172 ;
return 0 ;
}
static int F_44 ( struct V_56 * V_57 , T_3 * V_5 )
{
struct V_1 * V_150 = F_21 ( V_57 ) ;
int V_35 ;
T_2 V_9 ;
V_35 = F_1 ( V_150 , V_14 ,
( T_2 ) V_161 , & V_9 ) ;
if ( V_35 )
return V_35 ;
* V_5 = ! ! ( V_9 & V_173 ) ;
return 0 ;
}
static int F_45 ( struct V_56 * V_57 , T_3 * V_5 )
{
struct V_1 * V_150 = F_21 ( V_57 ) ;
int V_35 ;
T_2 V_9 ;
V_35 = F_1 ( V_150 , V_14 ,
( T_2 ) V_161 , & V_9 ) ;
if ( V_35 )
return V_35 ;
* V_5 = ! ! ( V_9 & V_174 ) ;
return 0 ;
}
static long F_46 ( struct V_56 * V_57 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = F_21 ( V_57 ) ;
struct V_61 * V_23 = F_24 ( V_57 ) ;
int V_35 = 0 ;
unsigned int V_177 = 0 ;
unsigned int V_178 = 0 ;
unsigned int V_179 = 0 ;
unsigned int V_180 = 0 ;
unsigned int V_181 , V_182 ;
T_2 V_183 = 0 ;
T_1 V_184 [ 3 ] ;
F_10 ( & V_2 -> V_23 , L_21 , V_11 ,
V_176 -> V_185 [ 0 ] , V_176 -> V_186 [ 0 ] ,
V_176 -> V_186 [ 1 ] ) ;
V_177 = V_176 -> V_185 [ 0 ] ;
V_179 = V_87 [ V_23 -> V_72 ] . V_118 ;
V_181 = V_176 -> V_186 [ 0 ] ;
V_182 = V_176 -> V_186 [ 1 ] ;
if ( ! V_23 -> V_153 ) {
V_23 -> V_154 = V_177 ;
V_23 -> V_187 = V_181 ;
V_23 -> V_188 = V_182 ;
}
if ( V_179 < V_177 + 6 )
V_179 = V_177 + 6 ;
if ( V_179 < V_180 )
V_179 = V_180 ;
V_35 = F_5 ( V_2 , V_14 , 0x300A , V_179 ) ;
if ( V_35 ) {
F_2 ( V_2 , L_22 , V_11 ) ;
return - V_16 ;
}
V_184 [ 0 ] = V_189 ;
V_184 [ 1 ] = ( T_1 ) V_177 ;
V_184 [ 2 ] = ( T_1 ) V_178 ;
V_35 = F_5 ( V_2 , V_14 ,
V_189 , ( T_1 ) ( V_177 ) ) ;
if ( V_35 ) {
F_2 ( V_2 , L_23 , V_11 ) ;
return - V_16 ;
}
if ( V_182 >= 16 || V_182 <= 1 )
V_182 = 1 ;
V_183 = ( T_1 ) ( ( V_182 << 12 ) | ( T_1 ) V_181 ) ;
V_35 = F_5 ( V_2 , V_14 ,
V_190 , V_183 ) ;
if ( V_35 ) {
F_2 ( V_2 , L_24 ,
V_11 ) ;
return - V_16 ;
}
return V_35 ;
}
static long F_47 ( struct V_56 * V_57 , unsigned int V_191 , void * V_192 )
{
switch ( V_191 ) {
case V_193 :
return F_46 ( V_57 , V_192 ) ;
default:
return - V_16 ;
}
return 0 ;
}
static int F_48 ( struct V_56 * V_57 , T_3 * V_194 )
{
struct V_1 * V_2 = F_21 ( V_57 ) ;
T_2 V_195 ;
int V_35 ;
V_35 = F_1 ( V_2 , V_14 ,
V_189 , & V_195 ) ;
if ( V_35 )
return V_35 ;
* V_194 = V_195 ;
return 0 ;
}
static int F_49 ( struct V_56 * V_57 , T_3 * V_5 )
{
* V_5 = 1 ;
return 0 ;
}
static int F_50 ( struct V_56 * V_57 , T_3 V_5 )
{
struct V_1 * V_2 = F_21 ( V_57 ) ;
int V_35 ;
switch ( V_5 ) {
case V_196 :
V_35 = F_18 ( V_2 , V_197 ,
V_160 ) ;
if ( V_35 ) {
F_4 ( & V_2 -> V_23 , L_25 ) ;
return V_35 ;
}
break;
case V_198 :
default:
V_35 = F_18 ( V_2 , V_199 ,
V_160 ) ;
if ( V_35 ) {
F_4 ( & V_2 -> V_23 , L_26 ) ;
return V_35 ;
}
}
return 0 ;
}
static int F_51 ( struct V_56 * V_57 ,
struct V_141 * V_142 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_21 ( V_57 ) ;
struct V_39 V_202 ;
int V_78 , V_79 ;
int V_203 , V_204 ;
int V_205 , V_206 , V_207 , V_208 ;
int V_209 , V_210 , V_211 , V_212 ;
int V_81 , V_213 ;
int V_35 ;
if ( V_201 -> V_156 != V_157 &&
V_201 -> V_156 != V_214 )
return - V_16 ;
V_205 = V_201 -> V_215 . V_216 ;
V_206 = V_201 -> V_215 . V_217 ;
V_207 = V_201 -> V_215 . V_216 + V_201 -> V_215 . V_78 - 1 ;
V_208 = V_201 -> V_215 . V_217 + V_201 -> V_215 . V_79 - 1 ;
V_35 = F_34 ( V_57 , & V_78 , & V_79 ) ;
if ( V_35 )
return V_35 ;
V_203 = V_78 / 5 ;
V_204 = V_79 / 5 ;
if ( V_203 && V_204 ) {
V_209 = V_205 / V_203 ;
V_210 = V_206 / V_204 ;
V_211 = V_207 / V_203 ;
V_212 = V_208 / V_204 ;
} else {
F_4 ( & V_2 -> V_23 , L_27 ) ;
return - V_16 ;
}
F_52 ( int , V_209 , 0 , 4 ) ;
F_52 ( int , V_210 , 0 , 4 ) ;
F_52 ( int , V_211 , 0 , 4 ) ;
F_52 ( int , V_212 , 0 , 4 ) ;
V_35 = F_18 ( V_2 , V_197 , V_160 ) ;
if ( V_35 ) {
F_4 ( & V_2 -> V_23 , L_25 ) ;
return V_35 ;
}
for ( V_81 = V_210 ; V_81 <= V_212 ; V_81 ++ ) {
for ( V_213 = V_209 ; V_213 <= V_211 ; V_213 ++ ) {
V_202 = V_218 [ V_81 ] [ V_213 ] ;
V_35 = F_5 ( V_2 , V_202 . V_43 ,
V_202 . V_4 , V_202 . V_5 ) ;
if ( V_35 ) {
F_4 ( & V_2 -> V_23 , L_28 ) ;
return V_35 ;
}
}
}
return 0 ;
}
static int F_53 ( struct V_56 * V_57 , T_3 * V_5 )
{
struct V_61 * V_23 = F_24 ( V_57 ) ;
* V_5 = V_87 [ V_23 -> V_72 ] . V_138 ;
return 0 ;
}
static int F_54 ( struct V_56 * V_57 , T_3 * V_5 )
{
struct V_61 * V_23 = F_24 ( V_57 ) ;
* V_5 = V_87 [ V_23 -> V_72 ] . V_140 ;
return 0 ;
}
static int F_55 ( struct V_56 * V_57 , T_3 V_5 )
{
struct V_1 * V_150 = F_21 ( V_57 ) ;
T_3 V_219 = 0x37 ;
int V_6 ;
if ( V_5 < - 2 || V_5 > 2 )
return - V_16 ;
V_219 += 0x10 * V_5 ;
F_10 ( & V_150 -> V_23 , L_29 , V_11 , V_5 , V_219 ) ;
V_6 = F_5 ( V_150 , V_14 , 0x098E , 0xC87A ) ;
if ( V_6 ) {
F_4 ( & V_150 -> V_23 , L_30 , V_11 ) ;
return V_6 ;
}
V_6 = F_5 ( V_150 , V_13 , 0xC87A , ( T_2 ) V_219 ) ;
if ( V_6 ) {
F_4 ( & V_150 -> V_23 , L_31 ,
V_11 ) ;
return V_6 ;
}
F_56 ( 10 ) ;
return 0 ;
}
static int F_57 ( struct V_56 * V_57 , T_3 * V_5 )
{
struct V_1 * V_150 = F_21 ( V_57 ) ;
int V_6 ;
T_2 V_219 ;
V_6 = F_5 ( V_150 , V_14 , 0x098E , 0xC87A ) ;
if ( V_6 ) {
F_4 ( & V_150 -> V_23 , L_30 , V_11 ) ;
return V_6 ;
}
V_6 = F_1 ( V_150 , V_13 , 0xC87A , & V_219 ) ;
if ( V_6 ) {
F_4 ( & V_150 -> V_23 , L_32 ,
V_11 ) ;
return V_6 ;
}
V_219 -= 0x17 ;
V_219 /= 0x10 ;
* V_5 = ( T_3 ) V_219 - 2 ;
F_10 ( & V_150 -> V_23 , L_33 , V_11 , * V_5 ) ;
return 0 ;
}
static int F_58 ( struct V_56 * V_57 , T_3 V_5 )
{
V_220 = V_5 ;
return 0 ;
}
static int F_59 ( struct V_56 * V_57 , T_3 * V_5 )
{
if ( V_220 )
return V_221 | V_222
| V_223 ;
return 0 ;
}
static int F_60 ( struct V_224 * V_34 )
{
struct V_61 * V_23 =
F_61 ( V_34 -> V_225 , struct V_61 , V_226 ) ;
struct V_1 * V_2 = F_21 ( & V_23 -> V_57 ) ;
int V_35 = 0 ;
switch ( V_34 -> V_227 ) {
case V_228 :
F_10 ( & V_2 -> V_23 , L_34 ,
V_11 , V_34 -> V_5 ) ;
V_35 = F_62 ( & V_23 -> V_57 , V_34 -> V_5 ) ;
break;
case V_229 :
F_10 ( & V_2 -> V_23 , L_35 ,
V_11 , V_34 -> V_5 ) ;
V_35 = F_63 ( & V_23 -> V_57 , V_34 -> V_5 ) ;
break;
#ifndef F_64
case V_230 :
V_35 = F_50 ( & V_23 -> V_57 , V_34 -> V_5 ) ;
break;
#endif
case V_231 :
V_35 = F_55 ( & V_23 -> V_57 , V_34 -> V_5 ) ;
break;
case V_232 :
V_35 = F_58 ( & V_23 -> V_57 , V_34 -> V_5 ) ;
break;
default:
V_35 = - V_16 ;
}
return V_35 ;
}
static int F_65 ( struct V_224 * V_34 )
{
struct V_61 * V_23 =
F_61 ( V_34 -> V_225 , struct V_61 , V_226 ) ;
int V_35 = 0 ;
switch ( V_34 -> V_227 ) {
case V_228 :
V_35 = F_45 ( & V_23 -> V_57 , & V_34 -> V_5 ) ;
break;
case V_229 :
V_35 = F_44 ( & V_23 -> V_57 , & V_34 -> V_5 ) ;
break;
case V_233 :
V_35 = F_41 ( & V_23 -> V_57 , & V_34 -> V_5 ) ;
break;
case V_234 :
V_35 = F_42 ( & V_23 -> V_57 , & V_34 -> V_5 ) ;
break;
case V_235 :
V_35 = F_43 ( & V_23 -> V_57 , & V_34 -> V_5 ) ;
break;
case V_236 :
V_35 = F_48 ( & V_23 -> V_57 , & V_34 -> V_5 ) ;
break;
#ifndef F_64
case V_237 :
V_35 = F_49 ( & V_23 -> V_57 , & V_34 -> V_5 ) ;
break;
#endif
case V_238 :
V_35 = F_53 ( & V_23 -> V_57 , & V_34 -> V_5 ) ;
break;
case V_239 :
V_35 = F_54 ( & V_23 -> V_57 , & V_34 -> V_5 ) ;
break;
case V_231 :
V_35 = F_57 ( & V_23 -> V_57 , & V_34 -> V_5 ) ;
break;
case V_232 :
V_35 = F_59 ( & V_23 -> V_57 , & V_34 -> V_5 ) ;
break;
default:
V_35 = - V_16 ;
}
return V_35 ;
}
static int F_66 ( struct V_61 * V_23 , struct V_1 * V_2 )
{
struct V_240 * V_10 = V_2 -> V_10 ;
T_2 V_241 ;
if ( ! F_67 ( V_10 , V_242 ) ) {
F_4 ( & V_2 -> V_23 , L_36 , V_11 ) ;
return - V_12 ;
}
F_1 ( V_2 , V_14 , ( T_2 ) V_243 , & V_241 ) ;
V_23 -> V_244 = V_241 ;
if ( V_241 != V_245 ) {
F_4 ( & V_2 -> V_23 , L_37 ,
V_11 , V_2 -> V_17 ) ;
return - V_12 ;
}
return 0 ;
}
static int
F_68 ( struct V_56 * V_57 , int V_246 , void * V_62 )
{
struct V_61 * V_23 = F_24 ( V_57 ) ;
struct V_1 * V_2 = F_21 ( V_57 ) ;
int V_35 ;
if ( NULL == V_62 )
return - V_12 ;
V_23 -> V_62 =
(struct V_247 * ) V_62 ;
if ( V_23 -> V_62 -> V_248 ) {
V_35 = V_23 -> V_62 -> V_248 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , L_38 ) ;
return V_35 ;
}
}
V_35 = F_26 ( V_57 ) ;
if ( V_35 ) {
F_2 ( V_2 , L_39 ) ;
return V_35 ;
}
V_35 = F_66 ( V_23 , V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , L_40 ) ;
goto V_249;
}
V_35 = V_23 -> V_62 -> V_250 ( V_57 , 1 ) ;
if ( V_35 )
goto V_251;
V_35 = F_20 ( V_57 ) ;
if ( V_35 ) {
F_2 ( V_2 , L_41 ) ;
return V_35 ;
}
V_35 = F_27 ( V_57 ) ;
if ( V_35 ) {
F_2 ( V_2 , L_42 ) ;
return V_35 ;
}
return V_35 ;
V_251:
V_23 -> V_62 -> V_250 ( V_57 , 0 ) ;
V_249:
F_27 ( V_57 ) ;
F_4 ( & V_2 -> V_23 , L_43 ) ;
return V_35 ;
}
static int F_63 ( struct V_56 * V_57 , int V_194 )
{
struct V_1 * V_150 = F_21 ( V_57 ) ;
struct V_61 * V_23 = F_24 ( V_57 ) ;
int V_6 ;
V_6 = F_5 ( V_150 , V_14 , 0x098E , 0xC850 ) ;
if ( V_194 ) {
V_6 += F_12 ( V_150 , V_13 , 0xC850 , 0x01 , 0x01 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC851 , 0x01 , 0x01 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC888 , 0x01 , 0x01 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC889 , 0x01 , 0x01 ) ;
V_6 += F_12 ( V_150 , V_14 , V_161 ,
V_173 , V_252 ) ;
V_23 -> V_253 = V_254 ;
} else {
V_6 += F_12 ( V_150 , V_13 , 0xC850 , 0x01 , 0x00 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC851 , 0x01 , 0x00 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC888 , 0x01 , 0x00 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC889 , 0x01 , 0x00 ) ;
V_6 += F_12 ( V_150 , V_14 , V_161 ,
V_173 , V_255 ) ;
V_23 -> V_253 = V_256 ;
}
V_6 += F_5 ( V_150 , V_13 , 0x8404 , 0x06 ) ;
F_56 ( 10 ) ;
return ! ! V_6 ;
}
static int F_62 ( struct V_56 * V_57 , int V_194 )
{
struct V_1 * V_150 = F_21 ( V_57 ) ;
int V_6 ;
V_6 = F_5 ( V_150 , V_14 , 0x098E , 0xC850 ) ;
if ( V_194 >= 1 ) {
V_6 += F_12 ( V_150 , V_13 , 0xC850 , 0x02 , 0x01 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC851 , 0x02 , 0x01 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC888 , 0x02 , 0x01 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC889 , 0x02 , 0x01 ) ;
V_6 += F_12 ( V_150 , V_14 , V_161 ,
V_174 , V_252 ) ;
} else {
V_6 += F_12 ( V_150 , V_13 , 0xC850 , 0x02 , 0x00 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC851 , 0x02 , 0x00 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC888 , 0x02 , 0x00 ) ;
V_6 += F_12 ( V_150 , V_13 , 0xC889 , 0x02 , 0x00 ) ;
V_6 += F_12 ( V_150 , V_14 , V_161 ,
V_174 , V_255 ) ;
}
V_6 += F_5 ( V_150 , V_13 , 0x8404 , 0x06 ) ;
F_56 ( 10 ) ;
return ! ! V_6 ;
}
static int F_69 ( struct V_56 * V_57 ,
struct V_257 * V_258 )
{
return 0 ;
}
static int F_70 ( struct V_56 * V_57 ,
struct V_259 * V_260 )
{
struct V_61 * V_23 = F_24 ( V_57 ) ;
V_260 -> V_260 . V_261 = 1 ;
V_260 -> V_260 . V_262 = V_87 [ V_23 -> V_72 ] . V_263 ;
return 0 ;
}
static int F_71 ( struct V_56 * V_57 , int V_264 )
{
int V_35 ;
struct V_1 * V_150 = F_21 ( V_57 ) ;
struct V_61 * V_23 = F_24 ( V_57 ) ;
struct V_175 V_176 ;
if ( V_264 ) {
V_35 = F_18 ( V_150 , V_166 ,
V_54 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_23 -> V_154 > V_265 ) {
V_176 . V_185 [ 0 ] = V_23 -> V_154 ;
V_176 . V_186 [ 0 ] = V_23 -> V_187 ;
V_176 . V_186 [ 1 ] = V_23 -> V_188 ;
F_46 ( V_57 , & V_176 ) ;
}
V_23 -> V_153 = 1 ;
} else {
V_23 -> V_153 = 0 ;
V_35 = F_20 ( V_57 ) ;
}
return V_35 ;
}
static int F_72 ( struct V_56 * V_57 ,
struct V_141 * V_142 ,
struct V_266 * V_148 )
{
if ( V_148 -> V_36 )
return - V_16 ;
V_148 -> V_148 = V_149 ;
return 0 ;
}
static int F_73 ( struct V_56 * V_57 ,
struct V_141 * V_142 ,
struct V_267 * V_268 )
{
unsigned int V_36 = V_268 -> V_36 ;
if ( V_36 >= V_90 )
return - V_16 ;
V_268 -> V_269 = V_87 [ V_36 ] . V_78 ;
V_268 -> V_270 = V_87 [ V_36 ] . V_79 ;
V_268 -> V_271 = V_87 [ V_36 ] . V_78 ;
V_268 -> V_272 = V_87 [ V_36 ] . V_79 ;
return 0 ;
}
static int F_74 ( struct V_56 * V_57 , T_2 * V_273 )
{
int V_36 ;
struct V_61 * V_274 = F_24 ( V_57 ) ;
if ( V_273 == NULL )
return - V_16 ;
for ( V_36 = 0 ; V_36 < V_90 ; V_36 ++ ) {
if ( V_87 [ V_36 ] . V_72 == V_274 -> V_72 )
break;
}
if ( V_36 >= V_90 )
return - V_16 ;
* V_273 = V_87 [ V_36 ] . V_275 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_61 * V_23 ;
struct V_56 * V_57 = F_76 ( V_2 ) ;
V_23 = F_61 ( V_57 , struct V_61 , V_57 ) ;
V_23 -> V_62 -> V_250 ( V_57 , 0 ) ;
if ( V_23 -> V_62 -> V_276 )
V_23 -> V_62 -> V_276 () ;
F_77 ( V_57 ) ;
F_78 ( & V_23 -> V_57 . V_277 ) ;
F_79 ( & V_23 -> V_226 ) ;
F_80 ( V_23 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
const struct V_278 * V_227 )
{
struct V_61 * V_23 ;
int V_35 = 0 ;
unsigned int V_81 ;
void * V_279 ;
V_23 = F_82 ( sizeof( * V_23 ) , V_280 ) ;
if ( ! V_23 ) {
F_4 ( & V_2 -> V_23 , L_44 ) ;
return - V_281 ;
}
F_83 ( & V_23 -> V_57 , V_2 , & V_282 ) ;
V_279 = V_2 -> V_23 . V_62 ;
if ( F_84 ( & V_2 -> V_23 ) )
V_279 = F_85 ( & V_23 -> V_57 ,
V_283 ,
V_284 ) ;
if ( V_279 )
V_35 = F_68 ( & V_23 -> V_57 , V_2 -> V_246 , V_279 ) ;
if ( ! V_279 || V_35 ) {
F_77 ( & V_23 -> V_57 ) ;
F_80 ( V_23 ) ;
return V_35 ;
}
V_35 = F_86 ( & V_23 -> V_57 , V_279 , V_285 ) ;
if ( V_35 ) {
F_77 ( & V_23 -> V_57 ) ;
F_80 ( V_23 ) ;
return V_35 ;
}
V_23 -> V_57 . V_18 |= V_286 ;
V_23 -> V_147 . V_18 = V_287 ;
V_23 -> V_144 . V_148 = V_149 ;
V_23 -> V_57 . V_277 . V_288 = V_289 ;
V_35 =
F_87 ( & V_23 -> V_226 ,
F_31 ( V_290 ) ) ;
if ( V_35 ) {
F_75 ( V_2 ) ;
return V_35 ;
}
for ( V_81 = 0 ; V_81 < F_31 ( V_290 ) ; V_81 ++ )
F_88 ( & V_23 -> V_226 , & V_290 [ V_81 ] ,
NULL ) ;
if ( V_23 -> V_226 . error ) {
F_75 ( V_2 ) ;
return V_23 -> V_226 . error ;
}
V_23 -> V_226 . V_291 = & V_23 -> V_292 ;
V_23 -> V_57 . V_226 = & V_23 -> V_226 ;
V_35 = F_89 ( & V_23 -> V_57 . V_277 , 1 , & V_23 -> V_147 ) ;
if ( V_35 ) {
F_75 ( V_2 ) ;
return V_35 ;
}
return 0 ;
}
static T_4 int F_90 ( void )
{
return F_91 ( & V_293 ) ;
}
static T_5 void F_92 ( void )
{
F_93 ( & V_293 ) ;
}
