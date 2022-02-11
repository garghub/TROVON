static void F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
int V_4 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
V_5 = F_2 ( V_1 -> V_7 ,
F_3 ( V_1 -> V_7 , 0 ) , V_2 ,
V_8 | V_9 | V_10 ,
V_3 , 0 , NULL , 0 , 1000 ) ;
if ( V_5 < 0 ) {
if ( ! V_4 )
F_4 ( L_1 ,
V_2 , V_3 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_5 ( struct V_1 * V_1 , T_1 V_2 , int V_4 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
if ( V_11 < V_12 ) {
F_4 ( L_2 ) ;
V_1 -> V_6 = - V_13 ;
return;
}
V_5 = F_2 ( V_1 -> V_7 ,
F_6 ( V_1 -> V_7 , 0 ) , V_2 ,
V_14 | V_9 | V_10 ,
0 , 0 , V_1 -> V_15 , V_12 , 1000 ) ;
if ( V_5 < 0 ) {
if ( ! V_4 )
F_4 ( L_3 ,
V_2 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_7 ( struct V_1 * V_1 ,
T_1 V_16 , T_1 V_17 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
V_5 = F_2 ( V_1 -> V_7 ,
F_3 ( V_1 -> V_7 , 0 ) ,
V_18 ,
V_8 | V_9 | V_10 ,
V_17 , V_16 , NULL , 0 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( L_4 ,
V_16 , V_17 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static int F_8 ( struct V_1 * V_1 , T_1 V_16 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return V_1 -> V_6 ;
if ( V_11 < 2 ) {
F_4 ( L_2 ) ;
V_1 -> V_6 = - V_13 ;
return V_1 -> V_6 ;
}
V_5 = F_2 ( V_1 -> V_7 ,
F_6 ( V_1 -> V_7 , 0 ) ,
V_19 ,
V_14 | V_9 | V_10 ,
0 , V_16 , V_1 -> V_15 , 2 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( L_5 ,
V_16 , V_5 ) ;
V_1 -> V_6 = V_5 ;
return V_5 ;
}
return V_1 -> V_15 [ 0 ] | ( V_1 -> V_15 [ 1 ] << 8 ) ;
}
static void F_9 ( struct V_1 * V_1 , T_2 V_20 )
{
F_1 ( V_1 , V_21 , V_20 , 0 ) ;
}
static void F_10 ( struct V_1 * V_1 , T_2 V_20 )
{
T_1 V_22 = 63 - V_20 ;
F_7 ( V_1 , V_23 , V_22 ) ;
F_7 ( V_1 , V_24 , V_22 ) ;
F_7 ( V_1 , V_25 , V_22 ) ;
}
static void F_11 ( struct V_1 * V_1 , T_2 V_20 , T_2 V_26 )
{
struct V_27 * V_27 = (struct V_27 * ) V_1 ;
int V_28 = V_20 << 6 ;
T_3 V_29 , V_30 , V_31 ;
V_27 -> V_32 = V_33 ;
if ( V_26 == V_34 )
V_28 = V_28 - V_28 % 106667 ;
if ( V_26 == V_35 )
V_28 = V_28 - V_28 % 88889 ;
V_29 = ( V_28 >> 16 ) ;
V_30 = ( V_28 >> 8 ) ;
V_31 = V_28 ;
F_7 ( V_1 , V_36 , V_31 ) ;
F_7 ( V_1 , V_37 , V_30 ) ;
F_7 ( V_1 , V_38 , V_29 ) ;
}
static int F_12 ( struct V_1 * V_1 ,
const struct V_39 * V_40 )
{
struct V_27 * V_27 = (struct V_27 * ) V_1 ;
struct V_41 * V_41 = & V_1 -> V_41 ;
T_3 * V_42 = V_1 -> V_15 ;
int V_43 , V_44 , V_45 ;
int V_46 [ V_47 ] , V_48 [ V_47 ] ;
F_5 ( V_1 , V_49 , 1 ) ;
if ( V_1 -> V_6 ) {
F_13 ( V_1 -> V_7 ) ;
V_1 -> V_6 = 0 ;
F_5 ( V_1 , V_49 , 0 ) ;
}
F_1 ( V_1 , V_50 , 0 , 0 ) ;
if ( V_1 -> V_6 )
return V_1 -> V_6 ;
if ( V_42 [ 1 ] != 0x41 ) {
F_4 ( L_6 ) ;
return - V_51 ;
}
if ( ! ( V_42 [ 2 ] & V_52 ) ) {
F_4 ( L_7 ) ;
return - V_51 ;
}
if ( V_42 [ 3 ] )
F_14 ( L_8 , V_42 [ 3 ] ) ;
V_45 = V_42 [ 4 ] | ( V_42 [ 5 ] << 8 ) ;
if ( V_45 > V_47 ) {
F_4 ( L_9 ) ;
return - V_51 ;
}
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
V_46 [ V_43 ] = V_42 [ 6 + V_43 * 4 + 0 ] | ( V_42 [ 6 + V_43 * 4 + 1 ] << 8 ) ;
V_48 [ V_43 ] = V_42 [ 6 + V_43 * 4 + 2 ] | ( V_42 [ 6 + V_43 * 4 + 3 ] << 8 ) ;
}
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
V_27 -> V_53 [ V_43 ] . V_54 = V_46 [ V_43 ] ;
V_27 -> V_53 [ V_43 ] . V_55 = V_48 [ V_43 ] ;
V_27 -> V_53 [ V_43 ] . V_56 = V_57 ;
V_27 -> V_53 [ V_43 ] . V_58 = V_59 ;
V_27 -> V_53 [ V_43 ] . V_60 = 1 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
if ( V_46 [ V_44 ] / 2 == V_46 [ V_43 ] &&
V_48 [ V_44 ] / 2 == V_48 [ V_43 ] ) {
V_27 -> V_53 [ V_43 ] . V_60 = 2 ;
break;
}
}
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
if ( V_46 [ V_44 ] / 4 == V_46 [ V_43 ] &&
V_48 [ V_44 ] / 4 == V_48 [ V_43 ] ) {
V_27 -> V_53 [ V_43 ] . V_60 = 4 ;
break;
}
}
if ( V_27 -> V_53 [ V_43 ] . V_60 == 1 ) {
V_27 -> V_53 [ V_43 ] . V_61 = V_62 ;
V_27 -> V_53 [ V_43 ] . V_63 = V_46 [ V_43 ] ;
V_27 -> V_53 [ V_43 ] . V_64 = V_46 [ V_43 ] * V_48 [ V_43 ] ;
F_14 ( L_10 ,
V_46 [ V_43 ] , V_48 [ V_43 ] ) ;
} else {
V_27 -> V_53 [ V_43 ] . V_61 = V_65 ;
V_27 -> V_53 [ V_43 ] . V_63 = 0 ;
V_27 -> V_53 [ V_43 ] . V_64 = V_46 [ V_43 ] * V_48 [ V_43 ] * 3 ;
F_14 ( L_11 ,
V_46 [ V_43 ] , V_48 [ V_43 ] ,
V_27 -> V_53 [ V_43 ] . V_60 * V_27 -> V_53 [ V_43 ] . V_60 ) ;
}
}
V_41 -> V_66 = V_27 -> V_53 ;
V_41 -> V_67 = V_45 ;
V_41 -> V_68 = 1 ;
V_41 -> V_69 = V_70 ;
V_41 -> V_71 = 4 ;
V_27 -> V_72 = 0x2d ;
F_5 ( V_1 , V_73 , 1 ) ;
V_27 -> V_74 = ! ! V_1 -> V_6 ;
V_1 -> V_6 = 0 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_1 )
{
V_1 -> V_75 = 1 ;
return V_1 -> V_6 ;
}
static int F_17 ( struct V_1 * V_1 )
{
struct V_27 * V_27 = (struct V_27 * ) V_1 ;
int V_76 = V_1 -> V_41 . V_66 [ V_1 -> V_77 ] . V_60 ;
int V_78 = 0 ;
F_1 ( V_1 , V_79 , 1 , 1 ) ;
if ( V_1 -> V_6 ) {
F_13 ( V_1 -> V_7 ) ;
V_1 -> V_6 = 0 ;
F_1 ( V_1 , V_79 , 1 , 0 ) ;
}
F_1 ( V_1 , V_50 , 1 , 0 ) ;
F_7 ( V_1 , V_80 , 0x05 ) ;
F_1 ( V_1 , V_81 ,
V_1 -> V_82 . V_54 * V_76 , 0 ) ;
F_1 ( V_1 , V_83 ,
V_1 -> V_82 . V_55 * V_76 , 0 ) ;
switch ( V_76 ) {
case 1 :
V_78 = 0x03 ; break;
case 2 :
V_78 = V_84 << 4 ; break;
case 4 :
V_78 = ( V_84 << 4 ) | 0x02 ; break;
}
F_7 ( V_1 , V_85 , V_78 ) ;
F_7 ( V_1 , V_86 , V_27 -> V_72 ) ;
V_27 -> V_87 = 0 ;
V_27 -> V_88 = 0 ;
V_27 -> V_89 = 0 ;
V_27 -> V_90 = 0 ;
V_27 -> V_91 = 0 ;
V_27 -> V_32 = V_92 ;
F_1 ( V_1 , V_93 , 0 , 0 ) ;
return V_1 -> V_6 ;
}
static void F_18 ( struct V_1 * V_1 )
{
F_1 ( V_1 , V_94 , 0 , 0 ) ;
F_1 ( V_1 , V_50 , 0 , 0 ) ;
F_1 ( V_1 , V_79 , 0 , 0 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_27 * V_27 = (struct V_27 * ) V_1 ;
unsigned int V_95 , V_96 ;
int V_97 , V_98 ;
if ( V_27 -> V_89 ) {
F_18 ( V_1 ) ;
F_17 ( V_1 ) ;
V_27 -> V_89 = 0 ;
}
V_27 -> V_90 ++ ;
if ( V_27 -> V_90 < 20 )
return;
F_8 ( V_1 , V_99 ) ;
F_8 ( V_1 , V_100 ) ;
F_8 ( V_1 , V_101 ) ;
F_8 ( V_1 , V_102 ) ;
V_95 = 256 * F_8 ( V_1 , V_99 ) +
F_8 ( V_1 , V_100 ) ;
V_96 = 256 * F_8 ( V_1 , V_101 ) +
F_8 ( V_1 , V_102 ) ;
V_97 = V_27 -> V_72 ;
if ( V_96 > 10 ) {
while ( V_96 >= 10 && V_27 -> V_72 < 63 ) {
V_27 -> V_72 ++ ;
V_96 /= 2 ;
}
} else if ( V_95 > 20 ) {
while ( V_95 >= 20 && V_27 -> V_72 > 0 ) {
V_27 -> V_72 -- ;
V_95 /= 2 ;
}
}
if ( V_27 -> V_72 > V_97 )
V_98 = 1 ;
else
V_98 = - 1 ;
if ( V_27 -> V_91 &&
V_27 -> V_91 != V_98 )
V_27 -> V_72 = V_97 + ( V_27 -> V_72 - V_97 ) / 2 ;
if ( V_27 -> V_72 != V_97 ) {
V_27 -> V_91 = V_98 ;
F_7 ( V_1 , V_86 , V_27 -> V_72 ) ;
}
V_27 -> V_90 = 0 ;
}
static void F_20 ( struct V_1 * V_1 , T_3 * V_103 , int V_104 )
{
struct V_27 * V_27 = (struct V_27 * ) V_1 ;
switch ( V_27 -> V_32 ) {
case V_33 :
V_27 -> V_32 = V_105 ;
break;
case V_105 :
V_1 -> V_106 = V_107 ;
V_27 -> V_32 = V_92 ;
break;
case V_92 :
break;
}
F_21 ( V_1 , V_108 , V_103 , V_104 ) ;
}
static void F_22 ( struct V_1 * V_1 , T_3 * V_103 , int V_104 )
{
struct V_27 * V_27 = (struct V_27 * ) V_1 ;
int V_109 = V_1 -> V_82 . V_54 * V_1 -> V_82 . V_55 ;
int V_43 , V_110 , V_111 , V_112 , V_113 , V_114 ;
if ( V_27 -> V_89 )
return;
if ( V_1 -> V_106 == V_108 && V_104 == 1024 ) {
V_1 -> V_106 = V_107 ;
return;
}
V_43 = 0 ;
while ( V_43 < V_104 ) {
if ( V_27 -> V_87 < 4 ) {
V_114 = 4 - V_27 -> V_87 ;
if ( V_114 > V_104 - V_43 )
V_114 = V_104 - V_43 ;
memcpy ( & V_27 -> V_115 [ V_27 -> V_87 ] , & V_103 [ V_43 ] , V_114 ) ;
V_27 -> V_87 += V_114 ;
V_43 += V_114 ;
if ( V_27 -> V_87 < 4 )
break;
}
V_111 = V_27 -> V_115 [ 3 ] + ( V_27 -> V_115 [ 2 ] << 8 ) ;
V_112 = V_27 -> V_115 [ 1 ] + ( ( V_27 -> V_115 [ 0 ] & 0x3f ) << 8 ) ;
V_113 = ( V_27 -> V_115 [ 0 ] & 0xc0 ) >> 6 ;
V_110 = ( ( V_111 + 47 ) >> 4 ) << 1 ;
if ( V_110 > 1024 ) {
F_4 ( L_12 ,
V_110 ) ;
goto error;
}
if ( V_113 == 3 ) {
F_4 ( L_13 ) ;
goto error;
}
V_114 = V_110 - V_27 -> V_87 ;
if ( V_114 > V_104 - V_43 )
V_114 = V_104 - V_43 ;
memcpy ( & V_27 -> V_115 [ V_27 -> V_87 ] , & V_103 [ V_43 ] , V_114 ) ;
V_27 -> V_87 += V_114 ;
V_43 += V_114 ;
if ( V_27 -> V_87 < V_110 )
break;
V_27 -> V_88 += V_112 ;
V_27 -> V_87 = 0 ;
switch ( V_113 ) {
case 0 :
F_21 ( V_1 , V_116 , V_27 -> V_115 ,
V_110 ) ;
break;
case 1 :
if ( V_27 -> V_88 != V_109 ) {
F_4 ( L_14 ,
V_27 -> V_88 , V_109 ) ;
goto error;
}
F_20 ( V_1 , V_27 -> V_115 , V_110 ) ;
return;
case 2 :
F_21 ( V_1 , V_117 , V_27 -> V_115 ,
V_110 ) ;
V_27 -> V_88 = V_112 ;
break;
}
}
return;
error:
V_27 -> V_89 = 1 ;
F_21 ( V_1 , V_117 , NULL , 0 ) ;
F_21 ( V_1 , V_108 , NULL , 0 ) ;
}
static void F_23 ( struct V_1 * V_1 , T_3 * V_103 , int V_104 )
{
struct V_41 * V_41 = & V_1 -> V_41 ;
int V_109 = V_41 -> V_66 [ V_1 -> V_77 ] . V_64 ;
if ( V_1 -> V_118 == 0 ) {
F_21 ( V_1 , V_117 , V_103 , V_104 ) ;
return;
}
if ( V_1 -> V_118 + V_104 >= V_109 ) {
F_20 ( V_1 , V_103 , V_104 ) ;
return;
}
F_21 ( V_1 , V_116 , V_103 , V_104 ) ;
}
static void F_24 ( struct V_1 * V_1 , T_3 * V_103 , int V_104 )
{
int V_76 = V_1 -> V_41 . V_66 [ V_1 -> V_77 ] . V_60 ;
if ( V_104 == 0 )
return;
if ( V_76 == 1 )
F_23 ( V_1 , V_103 , V_104 ) ;
else
F_22 ( V_1 , V_103 , V_104 ) ;
}
static int F_25 ( struct V_1 * V_1 , T_3 * V_103 , int V_104 )
{
struct V_27 * V_27 = (struct V_27 * ) V_1 ;
T_3 V_119 ;
if ( V_104 != 2 )
return - V_120 ;
switch ( V_103 [ 0 ] ) {
case 0 :
case 1 :
V_119 = V_103 [ 0 ] ;
break;
default:
return - V_120 ;
}
if ( V_27 -> V_121 != V_119 ) {
F_26 ( V_1 -> V_122 , V_123 , V_119 ) ;
F_27 ( V_1 -> V_122 ) ;
V_27 -> V_121 = V_119 ;
}
return 0 ;
}
static int F_28 ( struct V_124 * V_125 )
{
struct V_1 * V_1 =
F_29 ( V_125 -> V_126 , struct V_1 , V_127 ) ;
struct V_27 * V_27 = (struct V_27 * ) V_1 ;
V_1 -> V_6 = 0 ;
if ( ! V_1 -> V_128 )
return 0 ;
switch ( V_125 -> V_40 ) {
case V_129 :
F_9 ( V_1 , V_125 -> V_20 ) ;
break;
case V_130 :
F_10 ( V_1 , V_125 -> V_20 ) ;
break;
case V_131 :
F_11 ( V_1 , V_125 -> V_20 , V_27 -> V_26 -> V_20 ) ;
break;
}
return V_1 -> V_6 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_27 * V_27 = (struct V_27 * ) V_1 ;
struct V_132 * V_133 = & V_1 -> V_127 ;
V_1 -> V_134 . V_127 = V_133 ;
F_31 ( V_133 , 4 ) ;
if ( V_27 -> V_74 )
F_32 ( V_133 , & V_135 ,
V_129 , 0 , 255 , 1 , 15 ) ;
F_32 ( V_133 , & V_135 ,
V_130 , 0 , 50 , 1 , 25 ) ;
V_27 -> V_136 = F_32 ( V_133 , & V_135 ,
V_131 , 0 , 32767 , 1 , 15000 ) ;
V_27 -> V_26 = F_33 ( V_133 , & V_135 ,
V_137 ,
V_35 , 0 , 0 ) ;
if ( V_133 -> error ) {
F_4 ( L_15 ) ;
return V_133 -> error ;
}
F_34 ( 2 , & V_27 -> V_136 ) ;
return 0 ;
}
static int F_35 ( struct V_138 * V_139 ,
const struct V_39 * V_40 )
{
return F_36 ( V_139 , V_40 , & V_140 , sizeof( struct V_27 ) ,
V_141 ) ;
}
static int F_37 ( struct V_138 * V_139 )
{
return 0 ;
}
static int F_38 ( struct V_138 * V_139 )
{
return 0 ;
}
