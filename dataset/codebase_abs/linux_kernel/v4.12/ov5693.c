static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
struct V_6 V_7 ;
T_1 V_8 [ 2 ] ;
V_8 [ 0 ] = V_3 ;
V_8 [ 1 ] = V_4 ;
V_7 . V_9 = V_10 ;
V_7 . V_11 = 0 ;
V_7 . V_12 = 2 ;
V_7 . V_8 = & V_8 [ 0 ] ;
V_5 = F_2 ( V_2 -> V_13 , & V_7 , 1 ) ;
if ( V_5 != 1 ) {
F_3 ( & V_2 -> V_14 , L_1 ,
V_15 , V_5 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_6 V_7 ;
T_1 V_8 [ 2 ] ;
V_8 [ 0 ] = V_3 ;
V_8 [ 1 ] = V_4 ;
V_7 . V_9 = V_17 ;
V_7 . V_11 = 0 ;
V_7 . V_12 = 0x02 ;
V_7 . V_8 = & V_8 [ 0 ] ;
if ( F_2 ( V_2 -> V_13 , & V_7 , 1 ) != 1 )
return - V_16 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_6 V_7 [ 2 ] ;
T_1 V_8 [ 2 ] ;
V_8 [ 0 ] = V_3 ;
V_8 [ 1 ] = 0 ;
V_7 [ 0 ] . V_9 = V_17 ;
V_7 [ 0 ] . V_11 = 0 ;
V_7 [ 0 ] . V_12 = 0x01 ;
V_7 [ 0 ] . V_8 = & V_8 [ 0 ] ;
V_7 [ 1 ] . V_9 = 0x0c ;
V_7 [ 1 ] . V_11 = V_18 ;
V_7 [ 1 ] . V_12 = 0x01 ;
V_7 [ 1 ] . V_8 = & V_8 [ 1 ] ;
* V_4 = 0 ;
if ( F_2 ( V_2 -> V_13 , V_7 , 2 ) != 2 )
return - V_16 ;
* V_4 = V_8 [ 1 ] ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_2 V_19 , T_2 V_3 , T_2 * V_4 )
{
int V_5 ;
struct V_6 V_7 [ 2 ] ;
unsigned char V_20 [ 6 ] ;
if ( ! V_2 -> V_13 ) {
F_3 ( & V_2 -> V_14 , L_2 ,
V_15 ) ;
return - V_21 ;
}
if ( V_19 != V_22 && V_19 != V_23
&& V_19 != V_24 ) {
F_3 ( & V_2 -> V_14 , L_3 ,
V_15 ) ;
return - V_25 ;
}
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
V_7 [ 0 ] . V_9 = V_2 -> V_9 ;
V_7 [ 0 ] . V_11 = 0 ;
V_7 [ 0 ] . V_12 = V_26 ;
V_7 [ 0 ] . V_8 = V_20 ;
V_20 [ 0 ] = ( T_1 ) ( V_3 >> 8 ) ;
V_20 [ 1 ] = ( T_1 ) ( V_3 & 0xff ) ;
V_7 [ 1 ] . V_9 = V_2 -> V_9 ;
V_7 [ 1 ] . V_12 = V_19 ;
V_7 [ 1 ] . V_11 = V_18 ;
V_7 [ 1 ] . V_8 = V_20 ;
V_5 = F_2 ( V_2 -> V_13 , V_7 , 2 ) ;
if ( V_5 != 2 ) {
if ( V_5 >= 0 )
V_5 = - V_16 ;
F_3 ( & V_2 -> V_14 ,
L_4 , V_3 , V_5 ) ;
return V_5 ;
}
* V_4 = 0 ;
if ( V_19 == V_22 )
* V_4 = ( T_1 ) V_20 [ 0 ] ;
else if ( V_19 == V_23 )
* V_4 = F_7 ( * ( T_2 * ) & V_20 [ 0 ] ) ;
else
* V_4 = F_8 ( * ( V_27 * ) & V_20 [ 0 ] ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_12 , T_1 * V_20 )
{
struct V_6 V_7 ;
const int V_28 = 1 ;
int V_29 ;
V_7 . V_9 = V_2 -> V_9 ;
V_7 . V_11 = 0 ;
V_7 . V_12 = V_12 ;
V_7 . V_8 = V_20 ;
V_29 = F_2 ( V_2 -> V_13 , & V_7 , 1 ) ;
return V_29 == V_28 ? 0 : - V_16 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_20 )
{
struct V_6 V_7 ;
const int V_28 = 1 ;
int V_29 ;
T_2 V_4 ;
V_4 = F_11 ( V_20 ) ;
V_7 . V_9 = V_10 ;
V_7 . V_11 = 0 ;
V_7 . V_12 = V_23 ;
V_7 . V_8 = ( T_1 * ) & V_4 ;
V_29 = F_2 ( V_2 -> V_13 , & V_7 , 1 ) ;
return V_29 == V_28 ? 0 : - V_16 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_30 , V_29 ;
struct V_6 V_7 ;
T_2 V_31 = 0 , V_20 ;
for ( V_30 = 0 ; V_30 < 4 ; V_30 ++ ) {
V_7 . V_9 = V_10 ;
V_7 . V_11 = V_18 ;
V_7 . V_12 = sizeof( V_20 ) ;
V_7 . V_8 = ( T_1 * ) & V_20 ;
V_29 = F_2 ( V_2 -> V_13 , & V_7 , 1 ) ;
if ( V_30 == 0 && V_29 == - V_32 ) {
V_31 = 0 ;
continue;
}
if ( V_30 == 0 )
V_31 = V_20 ;
if ( V_20 != V_31 )
return V_33 ;
}
return V_29 == 1 ? V_34 : V_29 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_19 ,
T_2 V_3 , T_2 V_4 )
{
int V_29 ;
unsigned char V_20 [ 4 ] = { 0 } ;
T_2 * V_35 = ( T_2 * ) V_20 ;
const T_2 V_12 = V_19 + sizeof( T_2 ) ;
if ( V_19 != V_22 && V_19 != V_23 ) {
F_3 ( & V_2 -> V_14 ,
L_5 , V_15 ) ;
return - V_25 ;
}
* V_35 = F_11 ( V_3 ) ;
if ( V_19 == V_22 ) {
V_20 [ 2 ] = ( T_1 ) ( V_4 ) ;
} else {
T_2 * V_36 = ( T_2 * ) & V_20 [ 2 ] ;
* V_36 = F_11 ( V_4 ) ;
}
V_29 = F_9 ( V_2 , V_12 , V_20 ) ;
if ( V_29 )
F_3 ( & V_2 -> V_14 ,
L_6 ,
V_4 , V_3 , V_29 ) ;
return V_29 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
T_2 V_39 ;
if ( V_38 -> V_40 == 0 )
return 0 ;
V_39 = sizeof( T_2 ) + V_38 -> V_40 ;
V_38 -> V_41 . V_9 = F_11 ( V_38 -> V_41 . V_9 ) ;
V_38 -> V_40 = 0 ;
return F_9 ( V_2 , V_39 , ( T_1 * ) & V_38 -> V_41 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
const struct V_42 * V_43 )
{
int V_39 ;
T_2 * V_44 ;
switch ( V_43 -> type ) {
case V_22 :
V_39 = 1 ;
V_38 -> V_41 . V_20 [ V_38 -> V_40 ] = ( T_1 ) V_43 -> V_4 ;
break;
case V_23 :
V_39 = 2 ;
V_44 = ( T_2 * ) & V_38 -> V_41 . V_20 [ V_38 -> V_40 ] ;
* V_44 = F_11 ( ( T_2 ) V_43 -> V_4 ) ;
break;
default:
return - V_25 ;
}
if ( V_38 -> V_40 == 0 )
V_38 -> V_41 . V_9 = V_43 -> V_3 ;
V_38 -> V_40 += V_39 ;
if ( V_38 -> V_40 + sizeof( T_2 ) >= V_45 )
return F_14 ( V_2 , V_38 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
const struct V_42 * V_43 )
{
if ( V_38 -> V_40 == 0 )
return 1 ;
return V_38 -> V_41 . V_9 + V_38 -> V_40 == V_43 -> V_3 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_42 * V_46 )
{
const struct V_42 * V_43 = V_46 ;
struct V_37 V_38 ;
int V_5 ;
V_38 . V_40 = 0 ;
for (; V_43 -> type != V_47 ; V_43 ++ ) {
switch ( V_43 -> type & V_48 ) {
case V_49 :
V_5 = F_14 ( V_2 , & V_38 ) ;
if ( V_5 )
return V_5 ;
F_18 ( V_43 -> V_4 ) ;
break;
default:
if ( ! F_16 ( V_2 , & V_38 ,
V_43 ) ) {
V_5 = F_14 ( V_2 , & V_38 ) ;
if ( V_5 )
return V_5 ;
}
V_5 = F_15 ( V_2 , & V_38 , V_43 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_14 ,
L_7 ,
V_15 ) ;
return V_5 ;
}
break;
}
}
return F_14 ( V_2 , & V_38 ) ;
}
static int F_19 ( struct V_50 * V_51 , T_3 * V_4 )
{
* V_4 = ( V_52 << 16 ) | V_53 ;
return 0 ;
}
static int F_20 ( struct V_50 * V_51 , T_3 * V_4 )
{
* V_4 = ( V_54 << 16 ) | V_55 ;
return 0 ;
}
static int F_21 ( struct V_50 * V_51 , T_3 * V_4 )
{
* V_4 = ( V_54 << 24 ) |
( V_55 << 16 ) |
( V_54 << 8 ) | V_55 ;
return 0 ;
}
static int F_22 ( struct V_50 * V_51 , T_3 * V_4 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
* V_4 = V_57 [ V_14 -> V_58 ] . V_59 ;
return 0 ;
}
static int F_24 ( struct V_50 * V_51 , T_3 * V_4 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
* V_4 = V_57 [ V_14 -> V_58 ] . V_60 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
const struct V_63 * V_64 )
{
struct V_50 * V_51 = F_26 ( V_2 ) ;
struct V_56 * V_14 = F_23 ( V_51 ) ;
struct V_65 * V_8 = & V_62 -> V_20 ;
unsigned int V_66 ;
T_2 V_67 ;
int V_29 ;
if ( V_62 == NULL )
return - V_25 ;
V_66 = V_64 -> V_68 * 1000000 ;
V_14 -> V_69 = V_66 ;
V_8 -> V_69 = V_66 ;
V_8 -> V_70 = V_71 ;
V_8 -> V_72 =
V_73 ;
V_8 -> V_74 = V_75 ;
V_8 -> V_76 =
V_77 ;
V_8 -> V_78 = V_75 ;
V_8 -> V_79 = V_64 -> V_80 ;
V_8 -> V_81 = V_64 -> V_82 ;
V_8 -> V_83 = V_64 -> V_84 ;
V_29 = F_6 ( V_2 , V_23 ,
V_85 , & V_67 ) ;
if ( V_29 )
return V_29 ;
V_8 -> V_86 = V_67 ;
V_29 = F_6 ( V_2 , V_23 ,
V_87 , & V_67 ) ;
if ( V_29 )
return V_29 ;
V_8 -> V_88 = V_67 ;
V_29 = F_6 ( V_2 , V_23 ,
V_89 , & V_67 ) ;
if ( V_29 )
return V_29 ;
V_8 -> V_90 = V_67 ;
V_29 = F_6 ( V_2 , V_23 ,
V_91 , & V_67 ) ;
if ( V_29 )
return V_29 ;
V_8 -> V_92 = V_67 ;
V_29 = F_6 ( V_2 , V_23 ,
V_93 , & V_67 ) ;
if ( V_29 )
return V_29 ;
V_8 -> V_94 = V_67 ;
V_29 = F_6 ( V_2 , V_23 ,
V_95 , & V_67 ) ;
if ( V_29 )
return V_29 ;
V_8 -> V_96 = V_67 ;
V_8 -> V_97 = V_64 -> V_59 ?
V_64 -> V_59 : 1 ;
V_8 -> V_98 = V_64 -> V_60 ?
V_64 -> V_60 : 1 ;
return 0 ;
}
static long F_27 ( struct V_50 * V_51 , int V_99 ,
int V_100 , int V_101 )
{
struct V_1 * V_2 = F_28 ( V_51 ) ;
struct V_56 * V_14 = F_23 ( V_51 ) ;
T_2 V_102 , V_103 ;
int V_29 , V_104 ;
V_103 = V_57 [ V_14 -> V_58 ] . V_82 ;
V_102 = V_57 [ V_14 -> V_58 ] . V_80 ;
if ( V_99 > ( 1 << 15 ) ) {
V_103 = V_103 * 2 ;
V_99 = ( int ) V_99 / 2 ;
}
V_29 = F_13 ( V_2 , V_22 ,
V_105 , 0x00 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_105 ) ;
return V_29 ;
}
V_29 = F_13 ( V_2 , V_22 ,
V_106 , ( V_103 >> 8 ) & 0xFF ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_106 ) ;
return V_29 ;
}
V_29 = F_13 ( V_2 , V_22 ,
V_107 , V_103 & 0xFF ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_107 ) ;
return V_29 ;
}
if ( V_99 > V_102 - V_108 )
V_102 = ( T_2 ) V_99 + V_108 ;
V_29 = F_13 ( V_2 , V_22 ,
V_109 , ( V_102 >> 8 ) & 0xFF ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_109 ) ;
return V_29 ;
}
V_29 = F_13 ( V_2 , V_22 ,
V_110 , V_102 & 0xFF ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_110 ) ;
return V_29 ;
}
V_104 = V_99 << 4 ;
V_29 = F_13 ( V_2 , V_22 ,
V_111 , V_104 & 0xFF ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_111 ) ;
return V_29 ;
}
V_29 = F_13 ( V_2 , V_22 ,
V_112 , ( V_104 >> 8 ) & 0xFF ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_112 ) ;
return V_29 ;
}
V_29 = F_13 ( V_2 , V_22 ,
V_113 , ( V_104 >> 16 ) & 0x0F ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_113 ) ;
return V_29 ;
}
V_29 = F_13 ( V_2 , V_22 ,
V_114 , V_100 & 0xff ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_114 ) ;
return V_29 ;
}
V_29 = F_13 ( V_2 , V_22 ,
V_115 , ( V_100 >> 8 ) & 0xff ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_115 ) ;
return V_29 ;
}
if ( V_101 ) {
V_29 = F_13 ( V_2 , V_23 ,
V_116 , V_101 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_116 ) ;
return V_29 ;
}
V_29 = F_13 ( V_2 , V_23 ,
V_117 , V_101 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_116 ) ;
return V_29 ;
}
V_29 = F_13 ( V_2 , V_23 ,
V_118 , V_101 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_8 ,
V_15 , V_116 ) ;
return V_29 ;
}
}
V_29 = F_13 ( V_2 , V_22 ,
V_105 , 0x10 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_13 ( V_2 , V_22 ,
V_105 , 0xa0 ) ;
if ( V_29 )
return V_29 ;
return V_29 ;
}
static int F_29 ( struct V_50 * V_51 , int V_119 ,
int V_100 , int V_101 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
int V_29 ;
F_30 ( & V_14 -> V_120 ) ;
V_29 = F_27 ( V_51 , V_119 , V_100 , V_101 ) ;
F_31 ( & V_14 -> V_120 ) ;
return V_29 ;
}
static long F_32 ( struct V_50 * V_51 ,
struct V_121 * V_119 )
{
T_2 V_99 = V_119 -> V_122 [ 0 ] ;
T_2 V_123 = V_119 -> V_100 [ 0 ] ;
T_2 V_124 = V_119 -> V_100 [ 1 ] ;
if ( V_123 == 0 ) {
struct V_1 * V_2 = F_28 ( V_51 ) ;
F_33 ( V_2 , L_9 , V_15 ) ;
return - V_25 ;
}
return F_29 ( V_51 , V_99 , V_123 , V_124 ) ;
}
static int F_34 ( struct V_1 * V_2 , T_2 V_39 ,
T_2 V_9 , T_1 * V_8 )
{
T_2 V_40 ;
int V_29 ;
T_2 * V_125 = 0 ;
for ( V_40 = 0 ; V_40 <= V_39 ; V_40 ++ ) {
V_125 = ( T_2 * ) ( V_8 + V_40 ) ;
V_29 =
F_6 ( V_2 , V_22 , V_9 + V_40 ,
V_125 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_35 ( struct V_50 * V_51 , T_1 * V_8 )
{
struct V_1 * V_2 = F_28 ( V_51 ) ;
struct V_56 * V_14 = F_23 ( V_51 ) ;
int V_29 ;
int V_30 ;
T_1 * V_126 = V_8 ;
V_14 -> V_127 = 0 ;
for ( V_30 = 1 ; V_30 < V_128 ; V_30 ++ ) {
V_29 = F_13 ( V_2 , V_22 , V_129 , ( V_30 | 0xc0 ) ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_10 ) ;
return V_29 ;
}
V_29 = F_13 ( V_2 , V_22 , V_130 , V_131 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 ,
L_11 ) ;
return V_29 ;
}
V_29 = F_34 ( V_2 , V_132 ,
V_133 ,
V_126 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_12 ) ;
return V_29 ;
}
if ( 21 == V_30 ) {
if ( ( * V_126 ) == 0 ) {
V_14 -> V_127 = 320 ;
break;
} else {
V_126 = V_8 ;
continue;
}
} else if ( 24 == V_30 ) {
if ( ( * V_126 ) == 0 ) {
V_14 -> V_127 = 32 ;
break;
} else {
V_126 = V_8 ;
continue;
}
} else if ( 27 == V_30 ) {
if ( ( * V_126 ) == 0 ) {
V_14 -> V_127 = 32 ;
break;
} else {
V_14 -> V_127 = 0 ;
break;
}
}
V_126 = V_126 + V_132 ;
}
return 0 ;
}
static void * F_36 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_28 ( V_51 ) ;
T_1 * V_8 ;
int V_29 ;
V_8 = F_37 ( & V_2 -> V_14 , ( V_134 + 16 ) , V_135 ) ;
if ( ! V_8 )
return F_38 ( - V_136 ) ;
V_29 = F_13 ( V_2 , V_22 , V_137 , 0x00 ) ;
V_29 = F_13 ( V_2 , V_22 ,
V_138 , V_139 ) ;
V_29 = F_35 ( V_51 , V_8 ) ;
V_29 = F_13 ( V_2 , V_22 , V_137 , 0x0f ) ;
V_29 = F_13 ( V_2 , V_22 ,
V_138 , V_140 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_13 ) ;
return F_38 ( V_29 ) ;
}
return V_8 ;
}
static int F_39 ( struct V_50 * V_51 ,
struct V_141 * V_142 )
{
struct V_1 * V_2 = F_28 ( V_51 ) ;
struct V_56 * V_14 = F_23 ( V_51 ) ;
T_1 T_4 * V_143 = V_142 -> V_20 ;
V_27 V_144 = V_142 -> V_39 ;
int V_29 ;
if ( ! V_144 )
goto V_145;
if ( F_40 ( V_14 -> V_146 ) ) {
F_3 ( & V_2 -> V_14 , L_14 ) ;
return F_41 ( V_14 -> V_146 ) ;
}
if ( V_144 > V_134 )
V_144 = V_134 ;
V_29 = F_42 ( V_143 , V_14 -> V_146 , V_144 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_15 ,
V_15 ) ;
return - V_147 ;
}
F_43 ( L_16 , V_15 , V_144 ) ;
V_145:
V_142 -> V_39 = V_14 -> V_127 ;
return 0 ;
}
static long F_44 ( struct V_50 * V_51 , unsigned int V_148 , void * V_149 )
{
switch ( V_148 ) {
case V_150 :
return F_32 ( V_51 , V_149 ) ;
case V_151 :
return F_39 ( V_51 , V_149 ) ;
default:
return - V_25 ;
}
return 0 ;
}
static int F_45 ( struct V_50 * V_51 , T_3 * V_152 )
{
struct V_1 * V_2 = F_28 ( V_51 ) ;
T_2 V_153 , V_154 ;
int V_29 ;
V_29 = F_6 ( V_2 , V_22 ,
V_111 ,
& V_153 ) ;
if ( V_29 )
goto V_5;
V_29 = F_6 ( V_2 , V_22 ,
V_112 ,
& V_154 ) ;
if ( V_29 )
goto V_5;
V_153 += V_154 << 8 ;
V_29 = F_6 ( V_2 , V_22 ,
V_113 ,
& V_154 ) ;
if ( V_29 )
goto V_5;
* V_152 = V_153 + ( ( ( V_27 ) V_154 << 16 ) ) ;
V_5:
return V_29 ;
}
int F_46 ( struct V_50 * V_51 , T_2 V_4 )
{
struct V_1 * V_2 = F_28 ( V_51 ) ;
int V_29 = - V_25 ;
T_1 V_155 ;
V_29 = F_5 ( V_2 , V_156 , & V_155 ) ;
if ( V_29 )
return V_29 ;
V_155 = ( V_155 & V_157 ) |
( ( V_4 >> 8 ) & ~ V_157 ) ;
V_29 = F_4 ( V_2 , V_156 , V_155 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_4 ( V_2 , V_158 , ( V_4 & 0xff ) ) ;
if ( V_29 )
return V_29 ;
V_155 = V_159 / V_160
- V_161 ;
V_29 = F_4 ( V_2 , V_162 , V_155 ) ;
return V_29 ;
}
int F_47 ( struct V_50 * V_51 , T_3 V_152 )
{
int V_29 ;
V_152 = F_48 ( V_152 , V_163 ) ;
V_29 = F_46 ( V_51 , V_152 ) ;
return V_29 ;
}
static int F_49 ( struct V_50 * V_51 , T_3 V_152 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
struct V_1 * V_2 = F_28 ( V_51 ) ;
int V_29 = 0 ;
F_50 ( & V_2 -> V_14 , L_17 , V_15 , V_152 ) ;
V_152 = F_51 ( V_152 , 0 , V_164 ) ;
if ( V_14 -> V_165 == V_34 ) {
if ( V_14 -> V_166 ) {
V_29 = F_10 ( V_2 , V_167 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_10 ( V_2 , V_168 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_10 ( V_2 , V_169 ) ;
if ( V_29 )
return V_29 ;
V_14 -> V_166 = false ;
}
V_29 = F_10 ( V_2 ,
F_52 ( V_152 , V_170 ) ) ;
} else if ( V_14 -> V_165 == V_33 ) {
F_47 ( V_51 , V_152 ) ;
}
if ( V_29 == 0 ) {
V_14 -> V_171 = V_152 - V_14 -> V_172 ;
V_14 -> V_172 = V_152 ;
F_53 ( & ( V_14 -> V_173 ) ) ;
} else
F_3 ( & V_2 -> V_14 ,
L_18 , V_15 , V_29 ) ;
return V_29 ;
}
static int F_54 ( struct V_50 * V_51 , T_3 V_152 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
return F_49 ( V_51 , V_14 -> V_172 + V_152 ) ;
}
static int F_55 ( struct V_50 * V_51 , T_3 * V_152 )
{
V_27 V_174 = 0 ;
struct V_56 * V_14 = F_23 ( V_51 ) ;
struct V_175 V_176 ;
const struct V_175 V_177 = {
0 ,
F_48 ( ( V_27 ) abs ( V_14 -> V_171 ) * V_178 ,
( V_27 ) V_179 ) ,
} ;
F_53 ( & V_176 ) ;
V_176 = F_56 ( V_176 , ( V_14 -> V_173 ) ) ;
if ( F_57 ( & V_176 , & V_177 ) <= 0 ) {
V_174 |= V_180 ;
V_174 |= V_181 ;
} else {
V_174 |= V_182 ;
V_174 |= V_183 ;
}
* V_152 = V_174 ;
return 0 ;
}
static int F_58 ( struct V_50 * V_51 , T_3 * V_152 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
T_3 V_4 ;
F_55 ( V_51 , & V_4 ) ;
if ( V_4 & V_180 )
* V_152 = V_14 -> V_172 - V_14 -> V_171 ;
else
* V_152 = V_14 -> V_172 ;
return 0 ;
}
static int F_59 ( struct V_50 * V_51 , T_3 V_152 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
V_14 -> V_171 = V_152 ;
V_14 -> V_166 = true ;
return 0 ;
}
static int F_60 ( struct V_50 * V_51 , T_3 V_152 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
V_14 -> V_171 = V_152 ;
V_14 -> V_166 = true ;
return 0 ;
}
static int F_61 ( struct V_184 * V_38 )
{
struct V_56 * V_14 =
F_62 ( V_38 -> V_185 , struct V_56 , V_186 ) ;
struct V_1 * V_2 = F_28 ( & V_14 -> V_51 ) ;
int V_29 = 0 ;
switch ( V_38 -> V_187 ) {
case V_188 :
F_50 ( & V_2 -> V_14 , L_19 ,
V_15 , V_38 -> V_4 ) ;
V_29 = F_49 ( & V_14 -> V_51 , V_38 -> V_4 ) ;
break;
case V_189 :
F_50 ( & V_2 -> V_14 , L_20 ,
V_15 , V_38 -> V_4 ) ;
V_29 = F_54 ( & V_14 -> V_51 , V_38 -> V_4 ) ;
break;
case V_190 :
V_29 = F_59 ( & V_14 -> V_51 , V_38 -> V_4 ) ;
break;
case V_191 :
V_29 = F_60 ( & V_14 -> V_51 , V_38 -> V_4 ) ;
break;
default:
V_29 = - V_25 ;
}
return V_29 ;
}
static int F_63 ( struct V_184 * V_38 )
{
struct V_56 * V_14 =
F_62 ( V_38 -> V_185 , struct V_56 , V_186 ) ;
int V_29 = 0 ;
switch ( V_38 -> V_187 ) {
case V_192 :
V_29 = F_45 ( & V_14 -> V_51 , & V_38 -> V_4 ) ;
break;
case V_193 :
V_29 = F_19 ( & V_14 -> V_51 , & V_38 -> V_4 ) ;
break;
case V_194 :
V_29 = F_20 ( & V_14 -> V_51 , & V_38 -> V_4 ) ;
break;
case V_195 :
V_29 = F_21 ( & V_14 -> V_51 , & V_38 -> V_4 ) ;
break;
case V_188 :
V_29 = F_58 ( & V_14 -> V_51 , & V_38 -> V_4 ) ;
break;
case V_196 :
V_29 = F_55 ( & V_14 -> V_51 , & V_38 -> V_4 ) ;
break;
case V_197 :
V_29 = F_22 ( & V_14 -> V_51 , & V_38 -> V_4 ) ;
break;
case V_198 :
V_29 = F_24 ( & V_14 -> V_51 , & V_38 -> V_4 ) ;
break;
default:
V_29 = - V_25 ;
}
return V_29 ;
}
static int F_64 ( struct V_50 * V_51 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
struct V_1 * V_2 = F_28 ( V_51 ) ;
int V_29 ;
F_65 ( L_21 , V_15 ) ;
F_30 ( & V_14 -> V_120 ) ;
V_14 -> V_166 = false ;
if ( V_14 -> V_165 == V_33 ) {
V_29 = F_1 ( V_2 , 0x01 , 0x01 ) ;
if ( V_29 )
F_3 ( & V_2 -> V_14 ,
L_22 ) ;
V_29 = F_4 ( V_2 , V_156 ,
V_199 ) ;
if ( V_29 )
F_3 ( & V_2 -> V_14 ,
L_23 ) ;
V_29 = F_4 ( V_2 , V_200 ,
V_201 ) ;
if ( V_29 )
F_3 ( & V_2 -> V_14 ,
L_24 ) ;
}
if ( V_14 -> V_165 == V_33 ) {
V_14 -> V_172 = V_202 ;
F_49 ( V_51 , V_202 ) ;
} else {
V_14 -> V_172 = 0 ;
F_49 ( V_51 , 0 ) ;
}
F_31 ( & V_14 -> V_120 ) ;
return 0 ;
}
static int F_66 ( struct V_50 * V_51 , bool V_203 )
{
int V_29 ;
struct V_56 * V_14 = F_23 ( V_51 ) ;
if ( ! V_14 || ! V_14 -> V_204 )
return - V_21 ;
if ( V_14 -> V_204 -> F_66 )
return V_14 -> V_204 -> F_66 ( V_51 , V_203 ) ;
if ( V_203 ) {
V_29 = V_14 -> V_204 -> V_205 ( V_51 , 1 ) ;
V_14 -> V_204 -> V_206 ( V_51 , 1 ) ;
if ( V_29 == 0 ) {
V_29 = V_14 -> V_204 -> V_207 ( V_51 , 1 ) ;
if ( V_29 ) {
V_14 -> V_204 -> V_206 ( V_51 , 0 ) ;
V_29 = V_14 -> V_204 -> V_205 ( V_51 , 0 ) ;
}
}
} else {
V_14 -> V_204 -> V_206 ( V_51 , 0 ) ;
V_29 = V_14 -> V_204 -> V_207 ( V_51 , 0 ) ;
V_29 |= V_14 -> V_204 -> V_205 ( V_51 , 0 ) ;
}
return V_29 ;
}
static int F_67 ( struct V_50 * V_51 , bool V_203 )
{
int V_29 ;
struct V_56 * V_14 = F_23 ( V_51 ) ;
if ( ! V_14 || ! V_14 -> V_204 )
return - V_21 ;
if ( V_14 -> V_204 -> F_67 )
return V_14 -> V_204 -> F_67 ( V_51 , V_203 ) ;
V_29 = V_14 -> V_204 -> V_208 ( V_51 , V_203 ) ;
return V_29 ;
}
static int F_68 ( struct V_50 * V_51 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
struct V_1 * V_2 = F_28 ( V_51 ) ;
int V_29 ;
if ( NULL == V_14 -> V_204 ) {
F_3 ( & V_2 -> V_14 ,
L_25 ) ;
return - V_21 ;
}
V_29 = F_66 ( V_51 , 1 ) ;
if ( V_29 )
goto V_209;
F_69 ( 10000 , 11000 ) ;
V_29 = F_67 ( V_51 , 1 ) ;
if ( V_29 ) {
V_29 = F_67 ( V_51 , 1 ) ;
if ( V_29 )
goto V_209;
}
V_29 = V_14 -> V_204 -> V_210 ( V_51 , 1 ) ;
if ( V_29 )
goto V_211;
F_70 ( V_212 ) ;
return 0 ;
V_211:
F_67 ( V_51 , 0 ) ;
V_209:
F_66 ( V_51 , 0 ) ;
F_3 ( & V_2 -> V_14 , L_26 ) ;
return V_29 ;
}
static int F_71 ( struct V_50 * V_51 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
struct V_1 * V_2 = F_28 ( V_51 ) ;
int V_29 = 0 ;
V_14 -> V_172 = V_213 ;
if ( NULL == V_14 -> V_204 ) {
F_3 ( & V_2 -> V_14 ,
L_25 ) ;
return - V_21 ;
}
V_29 = V_14 -> V_204 -> V_210 ( V_51 , 0 ) ;
if ( V_29 )
F_3 ( & V_2 -> V_14 , L_27 ) ;
V_29 = F_67 ( V_51 , 0 ) ;
if ( V_29 ) {
V_29 = F_67 ( V_51 , 0 ) ;
if ( V_29 )
F_3 ( & V_2 -> V_14 , L_28 ) ;
}
V_29 = F_66 ( V_51 , 0 ) ;
if ( V_29 )
F_3 ( & V_2 -> V_14 , L_29 ) ;
return V_29 ;
}
static int F_72 ( struct V_50 * V_51 )
{
static const int V_214 = 4 ;
int V_30 , V_29 ;
for ( V_30 = 0 ; V_30 < V_214 ; V_30 ++ ) {
V_29 = F_68 ( V_51 ) ;
if ( ! V_29 )
return 0 ;
F_71 ( V_51 ) ;
}
return V_29 ;
}
static int F_73 ( struct V_50 * V_51 , int V_215 )
{
int V_29 ;
F_65 ( L_30 , V_15 , V_215 ) ;
if ( V_215 == 0 )
return F_71 ( V_51 ) ;
else {
V_29 = F_72 ( V_51 ) ;
if ( ! V_29 ) {
V_29 = F_64 ( V_51 ) ;
V_57 = V_216 ;
V_217 = V_218 ;
}
}
return V_29 ;
}
static int F_74 ( struct V_63 * V_64 , V_27 V_219 , V_27 V_220 )
{
int V_221 ;
int F_74 ;
if ( V_219 == 0 || V_220 == 0 ||
V_64 -> V_222 < V_219 || V_64 -> V_223 < V_220 )
return - 1 ;
V_221 = V_64 -> V_222 << 13 ;
V_221 /= V_219 ;
V_221 *= V_220 ;
V_221 /= V_64 -> V_223 ;
F_74 = abs ( V_221 - 8192 ) ;
if ( F_74 > V_224 )
return - 1 ;
return F_74 ;
}
static int F_75 ( int V_219 , int V_220 )
{
int V_30 ;
int V_225 = - 1 ;
int V_226 ;
int V_227 = V_228 ;
int V_229 = V_228 ;
struct V_63 * V_230 = NULL ;
for ( V_30 = 0 ; V_30 < V_217 ; V_30 ++ ) {
V_230 = & V_57 [ V_30 ] ;
V_226 = F_74 ( V_230 , V_219 , V_220 ) ;
if ( V_226 == - 1 )
continue;
if ( V_226 < V_227 ) {
V_227 = V_226 ;
V_225 = V_30 ;
V_229 = V_57 [ V_30 ] . V_222 ;
continue;
}
if ( V_226 == V_227 && V_57 [ V_30 ] . V_222 < V_229 )
V_225 = V_30 ;
}
return V_225 ;
}
static int F_76 ( int V_219 , int V_220 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_217 ; V_30 ++ ) {
if ( V_219 != V_57 [ V_30 ] . V_222 )
continue;
if ( V_220 != V_57 [ V_30 ] . V_223 )
continue;
return V_30 ;
}
return - 1 ;
}
static int F_77 ( struct V_50 * V_51 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
struct V_1 * V_2 = F_28 ( V_51 ) ;
int V_29 = 0 ;
V_29 = F_13 ( V_2 , V_22 ,
V_231 , 0x01 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_31 ) ;
return V_29 ;
}
V_29 = F_17 ( V_2 , V_232 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_32 ) ;
return V_29 ;
}
V_29 = F_17 ( V_2 , V_57 [ V_14 -> V_58 ] . V_233 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_32 ) ;
return V_29 ;
}
return V_29 ;
}
static int F_78 ( struct V_50 * V_51 ,
struct V_234 * V_235 ,
struct V_236 * V_237 )
{
struct V_238 * V_239 = & V_237 -> V_237 ;
struct V_56 * V_14 = F_23 ( V_51 ) ;
struct V_1 * V_2 = F_28 ( V_51 ) ;
struct V_61 * V_240 = NULL ;
int V_29 = 0 ;
int V_225 ;
if ( V_237 -> V_241 )
return - V_25 ;
if ( ! V_239 )
return - V_25 ;
V_240 = F_79 ( V_51 ) ;
if ( V_240 == NULL )
return - V_25 ;
F_30 ( & V_14 -> V_120 ) ;
V_225 = F_75 ( V_239 -> V_222 , V_239 -> V_223 ) ;
if ( V_225 == - 1 ) {
V_239 -> V_222 = V_57 [ V_217 - 1 ] . V_222 ;
V_239 -> V_223 = V_57 [ V_217 - 1 ] . V_223 ;
} else {
V_239 -> V_222 = V_57 [ V_225 ] . V_222 ;
V_239 -> V_223 = V_57 [ V_225 ] . V_223 ;
}
V_239 -> V_242 = V_243 ;
if ( V_237 -> V_244 == V_245 ) {
V_235 -> V_246 = * V_239 ;
F_31 ( & V_14 -> V_120 ) ;
return 0 ;
}
V_14 -> V_58 = F_76 ( V_239 -> V_222 , V_239 -> V_223 ) ;
if ( V_14 -> V_58 == - 1 ) {
F_3 ( & V_2 -> V_14 , L_33 ) ;
F_31 ( & V_14 -> V_120 ) ;
return - V_25 ;
}
V_29 = F_77 ( V_51 ) ;
if ( V_29 ) {
int V_30 = 0 ;
F_3 ( & V_2 -> V_14 , L_34 ) ;
for ( V_30 = 0 ; V_30 < V_247 ; V_30 ++ ) {
F_3 ( & V_2 -> V_14 ,
L_35 ,
V_30 + 1 , V_247 ) ;
F_71 ( V_51 ) ;
V_29 = F_72 ( V_51 ) ;
if ( ! V_29 ) {
F_31 ( & V_14 -> V_120 ) ;
F_64 ( V_51 ) ;
F_30 ( & V_14 -> V_120 ) ;
} else {
F_3 ( & V_2 -> V_14 , L_36 ) ;
continue;
}
V_29 = F_77 ( V_51 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_37 ) ;
} else {
F_3 ( & V_2 -> V_14 , L_38 ) ;
break;
}
}
}
V_29 = F_13 ( V_2 , V_22 , V_138 ,
V_140 ) ;
if ( V_29 )
F_80 ( & V_2 -> V_14 , L_39 ) ;
V_29 = F_25 ( V_2 , V_240 ,
& V_57 [ V_14 -> V_58 ] ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_40 ) ;
goto V_5;
}
V_240 -> V_248 = V_239 -> V_222 * 10 / 8 ;
V_240 -> V_249 = 1 ;
V_240 -> V_250 = & V_251 ;
V_5:
F_31 ( & V_14 -> V_120 ) ;
return V_29 ;
}
static int F_81 ( struct V_50 * V_51 ,
struct V_234 * V_235 ,
struct V_236 * V_237 )
{
struct V_238 * V_239 = & V_237 -> V_237 ;
struct V_56 * V_14 = F_23 ( V_51 ) ;
if ( V_237 -> V_241 )
return - V_25 ;
if ( ! V_239 )
return - V_25 ;
V_239 -> V_222 = V_57 [ V_14 -> V_58 ] . V_222 ;
V_239 -> V_223 = V_57 [ V_14 -> V_58 ] . V_223 ;
V_239 -> V_242 = V_243 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_252 * V_13 = V_2 -> V_13 ;
T_2 V_253 , V_254 ;
int V_29 ;
T_2 V_187 ;
T_1 V_255 ;
if ( ! F_83 ( V_13 , V_256 ) )
return - V_21 ;
V_29 = F_6 ( V_2 , V_22 ,
V_257 , & V_253 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_41 , V_253 ) ;
return - V_21 ;
}
V_29 = F_6 ( V_2 , V_22 ,
V_258 , & V_254 ) ;
V_187 = ( ( ( ( T_2 ) V_253 ) << 8 ) | ( T_2 ) V_254 ) ;
if ( V_187 != V_259 ) {
F_3 ( & V_2 -> V_14 , L_42 , V_187 ) ;
return - V_21 ;
}
V_29 = F_6 ( V_2 , V_22 ,
V_260 , & V_253 ) ;
V_255 = ( T_1 ) V_253 & 0x0f ;
F_50 ( & V_2 -> V_14 , L_43 , V_255 ) ;
F_50 ( & V_2 -> V_14 , L_44 ) ;
return 0 ;
}
static int F_84 ( struct V_50 * V_51 , int V_261 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
struct V_1 * V_2 = F_28 ( V_51 ) ;
int V_29 ;
F_30 ( & V_14 -> V_120 ) ;
V_29 = F_13 ( V_2 , V_22 , V_138 ,
V_261 ? V_139 :
V_140 ) ;
F_31 ( & V_14 -> V_120 ) ;
return V_29 ;
}
static int F_85 ( struct V_50 * V_51 ,
int V_262 , void * V_204 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
struct V_1 * V_2 = F_28 ( V_51 ) ;
int V_29 = 0 ;
if ( V_204 == NULL )
return - V_21 ;
V_14 -> V_204 =
(struct V_263 * ) V_204 ;
F_30 ( & V_14 -> V_120 ) ;
V_29 = F_71 ( V_51 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_45 ) ;
goto V_264;
}
V_29 = F_72 ( V_51 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_46 ) ;
goto V_265;
}
if ( ! V_14 -> V_165 )
V_14 -> V_165 = F_12 ( V_2 ) ;
V_29 = V_14 -> V_204 -> V_266 ( V_51 , 1 ) ;
if ( V_29 )
goto V_267;
V_29 = F_82 ( V_2 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_47 ) ;
goto V_267;
}
V_14 -> V_146 = F_36 ( V_51 ) ;
V_29 = F_71 ( V_51 ) ;
if ( V_29 ) {
F_3 ( & V_2 -> V_14 , L_45 ) ;
goto V_267;
}
F_31 ( & V_14 -> V_120 ) ;
return V_29 ;
V_267:
V_14 -> V_204 -> V_266 ( V_51 , 0 ) ;
V_265:
F_71 ( V_51 ) ;
F_3 ( & V_2 -> V_14 , L_48 ) ;
V_264:
F_31 ( & V_14 -> V_120 ) ;
return V_29 ;
}
static int F_86 ( struct V_50 * V_51 ,
struct V_268 * V_269 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
struct V_1 * V_2 = F_28 ( V_51 ) ;
if ( ! V_269 )
return - V_25 ;
if ( V_269 -> type != V_270 ) {
F_3 ( & V_2 -> V_14 , L_49 ) ;
return - V_25 ;
}
memset ( V_269 , 0 , sizeof( * V_269 ) ) ;
V_269 -> type = V_270 ;
if ( V_14 -> V_58 >= 0 && V_14 -> V_58 < V_217 ) {
V_269 -> V_271 . V_272 . V_273 = V_274 ;
V_269 -> V_271 . V_272 . V_275 . V_276 = 1 ;
V_269 -> V_271 . V_272 . V_277 = V_14 -> V_278 ;
V_269 -> V_271 . V_272 . V_275 . V_279 =
V_57 [ V_14 -> V_58 ] . V_280 ;
}
return 0 ;
}
static int F_87 ( struct V_50 * V_51 ,
struct V_268 * V_269 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
V_14 -> V_278 = V_269 -> V_271 . V_272 . V_277 ;
F_30 ( & V_14 -> V_120 ) ;
switch ( V_14 -> V_278 ) {
case V_281 :
V_57 = V_282 ;
V_217 = V_283 ;
break;
case V_284 :
V_57 = V_285 ;
V_217 = V_286 ;
break;
default:
V_57 = V_216 ;
V_217 = V_218 ;
}
F_31 ( & V_14 -> V_120 ) ;
return 0 ;
}
static int F_88 ( struct V_50 * V_51 ,
struct V_287 * V_288 )
{
struct V_56 * V_14 = F_23 ( V_51 ) ;
V_288 -> V_288 . V_276 = 1 ;
V_288 -> V_288 . V_279 = V_57 [ V_14 -> V_58 ] . V_280 ;
return 0 ;
}
static int F_89 ( struct V_50 * V_51 ,
struct V_234 * V_235 ,
struct V_289 * V_242 )
{
if ( V_242 -> V_40 >= V_290 )
return - V_25 ;
V_242 -> V_242 = V_243 ;
return 0 ;
}
static int F_90 ( struct V_50 * V_51 ,
struct V_234 * V_235 ,
struct V_291 * V_292 )
{
int V_40 = V_292 -> V_40 ;
if ( V_40 >= V_217 )
return - V_25 ;
V_292 -> V_293 = V_57 [ V_40 ] . V_222 ;
V_292 -> V_294 = V_57 [ V_40 ] . V_223 ;
V_292 -> V_295 = V_57 [ V_40 ] . V_222 ;
V_292 -> V_296 = V_57 [ V_40 ] . V_223 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_26 ( V_2 ) ;
struct V_56 * V_14 = F_23 ( V_51 ) ;
F_50 ( & V_2 -> V_14 , L_50 ) ;
V_14 -> V_204 -> V_266 ( V_51 , 0 ) ;
F_92 ( V_51 ) ;
F_93 ( V_51 ) ;
F_94 ( & V_14 -> V_51 . V_297 ) ;
F_95 ( & V_14 -> V_186 ) ;
F_96 ( V_14 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
const struct V_298 * V_187 )
{
struct V_56 * V_14 ;
int V_299 ;
int V_29 = 0 ;
void * V_300 = V_2 -> V_14 . V_204 ;
struct V_301 * V_302 ;
unsigned int V_30 ;
V_299 = F_98 ( & V_2 -> V_14 , L_51 , - 1 ) ;
if ( V_299 != - 1 ) {
F_99 ( & V_2 -> V_14 ,
L_52 ,
V_2 -> V_9 , V_299 ) ;
V_2 -> V_9 = V_299 ;
}
V_14 = F_100 ( sizeof( * V_14 ) , V_135 ) ;
if ( ! V_14 ) {
F_3 ( & V_2 -> V_14 , L_53 ) ;
return - V_136 ;
}
F_101 ( & V_14 -> V_120 ) ;
V_14 -> V_58 = 0 ;
F_102 ( & ( V_14 -> V_51 ) , V_2 , & V_303 ) ;
V_302 = F_103 ( & V_2 -> V_14 ) ;
if ( V_302 ) {
V_302 -> V_304 . V_11 . V_305 = 0 ;
V_300 = F_104 ( & V_14 -> V_51 ,
V_306 ,
V_307 ) ;
}
if ( ! V_300 )
goto V_308;
V_29 = F_85 ( & V_14 -> V_51 , V_2 -> V_262 , V_300 ) ;
if ( V_29 )
goto V_308;
V_29 = F_105 ( & V_14 -> V_51 , V_300 , V_309 ) ;
if ( V_29 )
goto V_308;
V_14 -> V_51 . V_11 |= V_310 ;
V_14 -> V_241 . V_11 = V_311 ;
V_14 -> V_237 . V_242 = V_243 ;
V_14 -> V_51 . V_297 . V_312 = V_313 ;
V_29 =
F_106 ( & V_14 -> V_186 ,
F_107 ( V_314 ) ) ;
if ( V_29 ) {
F_91 ( V_2 ) ;
return V_29 ;
}
for ( V_30 = 0 ; V_30 < F_107 ( V_314 ) ; V_30 ++ )
F_108 ( & V_14 -> V_186 , & V_314 [ V_30 ] ,
NULL ) ;
if ( V_14 -> V_186 . error ) {
F_91 ( V_2 ) ;
return V_14 -> V_186 . error ;
}
V_14 -> V_186 . V_315 = & V_14 -> V_120 ;
V_14 -> V_51 . V_186 = & V_14 -> V_186 ;
V_29 = F_109 ( & V_14 -> V_51 . V_297 , 1 , & V_14 -> V_241 ) ;
if ( V_29 )
F_91 ( V_2 ) ;
return V_29 ;
V_308:
F_92 ( & V_14 -> V_51 ) ;
F_96 ( V_14 ) ;
return V_29 ;
}
static int F_110 ( void )
{
return F_111 ( & V_316 ) ;
}
static void F_112 ( void )
{
F_113 ( & V_316 ) ;
}
