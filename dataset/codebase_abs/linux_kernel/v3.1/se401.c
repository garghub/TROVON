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
V_5 ( L_1 ,
V_2 , V_3 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_4 ( struct V_1 * V_1 , T_1 V_2 , int V_4 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
if ( V_11 < V_12 ) {
V_5 ( L_2 ) ;
V_1 -> V_6 = - V_13 ;
return;
}
V_5 = F_2 ( V_1 -> V_7 ,
F_5 ( V_1 -> V_7 , 0 ) , V_2 ,
V_14 | V_9 | V_10 ,
0 , 0 , V_1 -> V_15 , V_12 , 1000 ) ;
if ( V_5 < 0 ) {
if ( ! V_4 )
V_5 ( L_3 , V_2 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_6 ( struct V_1 * V_1 ,
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
V_5 ( L_4 ,
V_16 , V_17 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static int F_7 ( struct V_1 * V_1 , T_1 V_16 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return V_1 -> V_6 ;
if ( V_11 < 2 ) {
V_5 ( L_2 ) ;
V_1 -> V_6 = - V_13 ;
return V_1 -> V_6 ;
}
V_5 = F_2 ( V_1 -> V_7 ,
F_5 ( V_1 -> V_7 , 0 ) ,
V_19 ,
V_14 | V_9 | V_10 ,
0 , V_16 , V_1 -> V_15 , 2 , 1000 ) ;
if ( V_5 < 0 ) {
V_5 ( L_5 , V_16 , V_5 ) ;
V_1 -> V_6 = V_5 ;
return V_5 ;
}
return V_1 -> V_15 [ 0 ] | ( V_1 -> V_15 [ 1 ] << 8 ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
struct V_20 * V_20 = (struct V_20 * ) V_1 ;
if ( V_1 -> V_21 & ( 1 << V_22 ) )
return;
F_1 ( V_1 , V_23 ,
V_20 -> V_24 [ V_22 ] . V_25 , 0 ) ;
}
static void F_9 ( struct V_1 * V_1 )
{
struct V_20 * V_20 = (struct V_20 * ) V_1 ;
T_1 V_26 = 63 - V_20 -> V_24 [ V_27 ] . V_25 ;
F_6 ( V_1 , V_28 , V_26 ) ;
F_6 ( V_1 , V_29 , V_26 ) ;
F_6 ( V_1 , V_30 , V_26 ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
struct V_20 * V_20 = (struct V_20 * ) V_1 ;
int V_31 = V_20 -> V_24 [ V_32 ] . V_25 << 6 ;
T_2 V_33 , V_34 , V_35 ;
V_20 -> V_36 = V_37 ;
if ( V_20 -> V_24 [ V_38 ] . V_25 == V_39 )
V_31 = V_31 - V_31 % 106667 ;
if ( V_20 -> V_24 [ V_38 ] . V_25 == V_40 )
V_31 = V_31 - V_31 % 88889 ;
V_33 = ( V_31 >> 16 ) ;
V_34 = ( V_31 >> 8 ) ;
V_35 = V_31 ;
F_6 ( V_1 , V_41 , V_35 ) ;
F_6 ( V_1 , V_42 , V_34 ) ;
F_6 ( V_1 , V_43 , V_33 ) ;
}
static int F_11 ( struct V_1 * V_1 ,
const struct V_44 * V_45 )
{
struct V_20 * V_20 = (struct V_20 * ) V_1 ;
struct V_46 * V_46 = & V_1 -> V_46 ;
T_2 * V_47 = V_1 -> V_15 ;
int V_48 , V_49 , V_50 ;
int V_51 [ V_52 ] , V_53 [ V_52 ] ;
F_4 ( V_1 , V_54 , 1 ) ;
if ( V_1 -> V_6 ) {
F_12 ( V_1 -> V_7 ) ;
V_1 -> V_6 = 0 ;
F_4 ( V_1 , V_54 , 0 ) ;
}
F_1 ( V_1 , V_55 , 0 , 0 ) ;
if ( V_1 -> V_6 )
return V_1 -> V_6 ;
if ( V_47 [ 1 ] != 0x41 ) {
V_5 ( L_6 ) ;
return - V_56 ;
}
if ( ! ( V_47 [ 2 ] & V_57 ) ) {
V_5 ( L_7 ) ;
return - V_56 ;
}
if ( V_47 [ 3 ] )
F_13 ( L_8 , V_47 [ 3 ] ) ;
V_50 = V_47 [ 4 ] | ( V_47 [ 5 ] << 8 ) ;
if ( V_50 > V_52 ) {
V_5 ( L_9 ) ;
return - V_56 ;
}
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
V_51 [ V_48 ] = V_47 [ 6 + V_48 * 4 + 0 ] | ( V_47 [ 6 + V_48 * 4 + 1 ] << 8 ) ;
V_53 [ V_48 ] = V_47 [ 6 + V_48 * 4 + 2 ] | ( V_47 [ 6 + V_48 * 4 + 3 ] << 8 ) ;
}
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
V_20 -> V_58 [ V_48 ] . V_59 = V_51 [ V_48 ] ;
V_20 -> V_58 [ V_48 ] . V_60 = V_53 [ V_48 ] ;
V_20 -> V_58 [ V_48 ] . V_61 = V_62 ;
V_20 -> V_58 [ V_48 ] . V_63 = V_64 ;
V_20 -> V_58 [ V_48 ] . V_65 = 1 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
if ( V_51 [ V_49 ] / 2 == V_51 [ V_48 ] &&
V_53 [ V_49 ] / 2 == V_53 [ V_48 ] ) {
V_20 -> V_58 [ V_48 ] . V_65 = 2 ;
break;
}
}
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
if ( V_51 [ V_49 ] / 4 == V_51 [ V_48 ] &&
V_53 [ V_49 ] / 4 == V_53 [ V_48 ] ) {
V_20 -> V_58 [ V_48 ] . V_65 = 4 ;
break;
}
}
if ( V_20 -> V_58 [ V_48 ] . V_65 == 1 ) {
V_20 -> V_58 [ V_48 ] . V_66 = V_67 ;
V_20 -> V_58 [ V_48 ] . V_68 = V_51 [ V_48 ] ;
V_20 -> V_58 [ V_48 ] . V_69 = V_51 [ V_48 ] * V_53 [ V_48 ] ;
F_13 ( L_10 , V_51 [ V_48 ] , V_53 [ V_48 ] ) ;
} else {
V_20 -> V_58 [ V_48 ] . V_66 = V_70 ;
V_20 -> V_58 [ V_48 ] . V_68 = 0 ;
V_20 -> V_58 [ V_48 ] . V_69 = V_51 [ V_48 ] * V_53 [ V_48 ] * 3 ;
F_13 ( L_11 ,
V_51 [ V_48 ] , V_53 [ V_48 ] ,
V_20 -> V_58 [ V_48 ] . V_65 * V_20 -> V_58 [ V_48 ] . V_65 ) ;
}
}
V_46 -> V_71 = V_20 -> V_58 ;
V_46 -> V_72 = V_50 ;
V_46 -> V_73 = 1 ;
V_46 -> V_74 = V_75 ;
V_46 -> V_76 = 4 ;
V_46 -> V_24 = V_20 -> V_24 ;
V_1 -> V_77 = 1 ;
V_20 -> V_78 = 0x2d ;
F_4 ( V_1 , V_79 , 1 ) ;
if ( V_1 -> V_6 ) {
V_1 -> V_21 = ( 1 << V_22 ) ;
V_1 -> V_6 = 0 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_20 * V_20 = (struct V_20 * ) V_1 ;
int V_80 = V_1 -> V_46 . V_71 [ V_1 -> V_81 ] . V_65 ;
int V_82 = 0 ;
F_1 ( V_1 , V_83 , 1 , 1 ) ;
if ( V_1 -> V_6 ) {
F_12 ( V_1 -> V_7 ) ;
V_1 -> V_6 = 0 ;
F_1 ( V_1 , V_83 , 1 , 0 ) ;
}
F_1 ( V_1 , V_55 , 1 , 0 ) ;
F_6 ( V_1 , V_84 , 0x05 ) ;
F_1 ( V_1 , V_85 ,
V_1 -> V_59 * V_80 , 0 ) ;
F_1 ( V_1 , V_86 ,
V_1 -> V_60 * V_80 , 0 ) ;
switch ( V_80 ) {
case 1 :
V_82 = 0x03 ; break;
case 2 :
V_82 = V_87 << 4 ; break;
case 4 :
V_82 = ( V_87 << 4 ) | 0x02 ; break;
}
F_6 ( V_1 , V_88 , V_82 ) ;
F_8 ( V_1 ) ;
F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
F_6 ( V_1 , V_89 , V_20 -> V_78 ) ;
V_20 -> V_90 = 0 ;
V_20 -> V_91 = 0 ;
V_20 -> V_92 = 0 ;
V_20 -> V_93 = 0 ;
V_20 -> V_94 = 0 ;
V_20 -> V_36 = V_95 ;
F_1 ( V_1 , V_96 , 0 , 0 ) ;
return V_1 -> V_6 ;
}
static void F_16 ( struct V_1 * V_1 )
{
F_1 ( V_1 , V_97 , 0 , 0 ) ;
F_1 ( V_1 , V_55 , 0 , 0 ) ;
F_1 ( V_1 , V_83 , 0 , 0 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_20 * V_20 = (struct V_20 * ) V_1 ;
unsigned int V_98 , V_99 ;
int V_100 , V_101 ;
if ( V_20 -> V_92 ) {
F_16 ( V_1 ) ;
F_15 ( V_1 ) ;
V_20 -> V_92 = 0 ;
}
V_20 -> V_93 ++ ;
if ( V_20 -> V_93 < 20 )
return;
F_7 ( V_1 , V_102 ) ;
F_7 ( V_1 , V_103 ) ;
F_7 ( V_1 , V_104 ) ;
F_7 ( V_1 , V_105 ) ;
V_98 = 256 * F_7 ( V_1 , V_102 ) +
F_7 ( V_1 , V_103 ) ;
V_99 = 256 * F_7 ( V_1 , V_104 ) +
F_7 ( V_1 , V_105 ) ;
V_100 = V_20 -> V_78 ;
if ( V_99 > 10 ) {
while ( V_99 >= 10 && V_20 -> V_78 < 63 ) {
V_20 -> V_78 ++ ;
V_99 /= 2 ;
}
} else if ( V_98 > 20 ) {
while ( V_98 >= 20 && V_20 -> V_78 > 0 ) {
V_20 -> V_78 -- ;
V_98 /= 2 ;
}
}
if ( V_20 -> V_78 > V_100 )
V_101 = 1 ;
else
V_101 = - 1 ;
if ( V_20 -> V_94 &&
V_20 -> V_94 != V_101 )
V_20 -> V_78 = V_100 + ( V_20 -> V_78 - V_100 ) / 2 ;
if ( V_20 -> V_78 != V_100 ) {
V_20 -> V_94 = V_101 ;
F_6 ( V_1 , V_89 , V_20 -> V_78 ) ;
}
V_20 -> V_93 = 0 ;
}
static void F_18 ( struct V_1 * V_1 , T_2 * V_106 , int V_107 )
{
struct V_20 * V_20 = (struct V_20 * ) V_1 ;
switch ( V_20 -> V_36 ) {
case V_37 :
V_20 -> V_36 = V_108 ;
break;
case V_108 :
V_1 -> V_109 = V_110 ;
V_20 -> V_36 = V_95 ;
break;
case V_95 :
break;
}
F_19 ( V_1 , V_111 , V_106 , V_107 ) ;
}
static void F_20 ( struct V_1 * V_1 , T_2 * V_106 , int V_107 )
{
struct V_20 * V_20 = (struct V_20 * ) V_1 ;
int V_112 = V_1 -> V_59 * V_1 -> V_60 ;
int V_48 , V_113 , V_114 , V_115 , F_13 , V_116 ;
if ( V_20 -> V_92 )
return;
if ( V_1 -> V_109 == V_111 && V_107 == 1024 ) {
V_1 -> V_109 = V_110 ;
return;
}
V_48 = 0 ;
while ( V_48 < V_107 ) {
if ( V_20 -> V_90 < 4 ) {
V_116 = 4 - V_20 -> V_90 ;
if ( V_116 > V_107 - V_48 )
V_116 = V_107 - V_48 ;
memcpy ( & V_20 -> V_117 [ V_20 -> V_90 ] , & V_106 [ V_48 ] , V_116 ) ;
V_20 -> V_90 += V_116 ;
V_48 += V_116 ;
if ( V_20 -> V_90 < 4 )
break;
}
V_114 = V_20 -> V_117 [ 3 ] + ( V_20 -> V_117 [ 2 ] << 8 ) ;
V_115 = V_20 -> V_117 [ 1 ] + ( ( V_20 -> V_117 [ 0 ] & 0x3f ) << 8 ) ;
F_13 = ( V_20 -> V_117 [ 0 ] & 0xc0 ) >> 6 ;
V_113 = ( ( V_114 + 47 ) >> 4 ) << 1 ;
if ( V_113 > 1024 ) {
V_5 ( L_12 , V_113 ) ;
goto error;
}
if ( F_13 == 3 ) {
V_5 ( L_13 ) ;
goto error;
}
V_116 = V_113 - V_20 -> V_90 ;
if ( V_116 > V_107 - V_48 )
V_116 = V_107 - V_48 ;
memcpy ( & V_20 -> V_117 [ V_20 -> V_90 ] , & V_106 [ V_48 ] , V_116 ) ;
V_20 -> V_90 += V_116 ;
V_48 += V_116 ;
if ( V_20 -> V_90 < V_113 )
break;
V_20 -> V_91 += V_115 ;
V_20 -> V_90 = 0 ;
switch ( F_13 ) {
case 0 :
F_19 ( V_1 , V_118 , V_20 -> V_117 ,
V_113 ) ;
break;
case 1 :
if ( V_20 -> V_91 != V_112 ) {
V_5 ( L_14 ,
V_20 -> V_91 , V_112 ) ;
goto error;
}
F_18 ( V_1 , V_20 -> V_117 , V_113 ) ;
return;
case 2 :
F_19 ( V_1 , V_119 , V_20 -> V_117 ,
V_113 ) ;
V_20 -> V_91 = V_115 ;
break;
}
}
return;
error:
V_20 -> V_92 = 1 ;
F_19 ( V_1 , V_119 , NULL , 0 ) ;
F_19 ( V_1 , V_111 , NULL , 0 ) ;
}
static void F_21 ( struct V_1 * V_1 , T_2 * V_106 , int V_107 )
{
struct V_46 * V_46 = & V_1 -> V_46 ;
int V_112 = V_46 -> V_71 [ V_1 -> V_81 ] . V_69 ;
if ( V_1 -> V_120 == 0 ) {
F_19 ( V_1 , V_119 , V_106 , V_107 ) ;
return;
}
if ( V_1 -> V_120 + V_107 >= V_112 ) {
F_18 ( V_1 , V_106 , V_107 ) ;
return;
}
F_19 ( V_1 , V_118 , V_106 , V_107 ) ;
}
static void F_22 ( struct V_1 * V_1 , T_2 * V_106 , int V_107 )
{
int V_80 = V_1 -> V_46 . V_71 [ V_1 -> V_81 ] . V_65 ;
if ( V_107 == 0 )
return;
if ( V_80 == 1 )
F_21 ( V_1 , V_106 , V_107 ) ;
else
F_20 ( V_1 , V_106 , V_107 ) ;
}
static int F_23 ( struct V_1 * V_1 ,
struct V_121 * V_122 )
{
switch ( V_122 -> V_45 ) {
case V_123 :
switch ( V_122 -> V_124 ) {
case V_125 :
strcpy ( ( char * ) V_122 -> V_126 , L_15 ) ;
return 0 ;
case V_39 :
strcpy ( ( char * ) V_122 -> V_126 , L_16 ) ;
return 0 ;
case V_40 :
strcpy ( ( char * ) V_122 -> V_126 , L_17 ) ;
return 0 ;
}
break;
}
return - V_127 ;
}
static int F_24 ( struct V_1 * V_1 , T_2 * V_106 , int V_107 )
{
struct V_20 * V_20 = (struct V_20 * ) V_1 ;
T_2 V_128 ;
if ( V_107 != 2 )
return - V_127 ;
switch ( V_106 [ 0 ] ) {
case 0 :
case 1 :
V_128 = V_106 [ 0 ] ;
break;
default:
return - V_127 ;
}
if ( V_20 -> V_129 != V_128 ) {
F_25 ( V_1 -> V_130 , V_131 , V_128 ) ;
F_26 ( V_1 -> V_130 ) ;
V_20 -> V_129 = V_128 ;
}
return 0 ;
}
static int F_27 ( struct V_132 * V_133 ,
const struct V_44 * V_45 )
{
return F_28 ( V_133 , V_45 , & V_134 , sizeof( struct V_20 ) ,
V_135 ) ;
}
static int F_29 ( struct V_132 * V_133 )
{
return 0 ;
}
static int F_30 ( struct V_132 * V_133 )
{
return 0 ;
}
static int T_3 F_31 ( void )
{
return F_32 ( & V_136 ) ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_136 ) ;
}
