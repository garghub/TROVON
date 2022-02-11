static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_2 * V_5 )
{
struct V_6 V_7 [ 2 ] ;
T_2 V_8 [ 2 ] ;
int V_9 ;
if ( ! V_2 -> V_10 ) {
F_2 ( & V_2 -> V_11 , L_1 , V_12 ) ;
return - V_13 ;
}
F_3 ( & V_2 -> V_11 , L_2 ,
V_12 , V_3 , V_4 ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
V_8 [ 0 ] = ( V_4 >> 8 ) & 0xff ;
V_8 [ 1 ] = V_4 & 0xff ;
V_7 [ 0 ] . V_4 = V_2 -> V_4 ;
V_7 [ 0 ] . V_14 = 0 ;
V_7 [ 0 ] . V_3 = V_15 ;
V_7 [ 0 ] . V_5 = V_8 ;
V_7 [ 1 ] . V_4 = V_2 -> V_4 ;
V_7 [ 1 ] . V_3 = V_3 ;
V_7 [ 1 ] . V_14 = V_16 ;
V_7 [ 1 ] . V_5 = V_5 ;
V_9 = F_4 ( V_2 -> V_10 , V_7 , F_5 ( V_7 ) ) ;
if ( V_9 != 2 ) {
if ( V_9 >= 0 )
V_9 = - V_17 ;
goto error;
}
return 0 ;
error:
F_2 ( & V_2 -> V_11 , L_3 , V_4 , V_9 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 type , T_1 V_18 ,
T_1 * V_19 )
{
T_2 V_20 [ V_21 ] ;
int V_9 ;
F_3 ( & V_2 -> V_11 , L_4 ,
V_12 , type , V_18 ) ;
if ( type != V_22 && type != V_23 ) {
F_2 ( & V_2 -> V_11 , L_5 ,
V_12 ) ;
return - V_24 ;
}
memset ( V_20 , 0 , sizeof( V_20 ) ) ;
V_9 = F_1 ( V_2 , type , V_18 , V_20 ) ;
if ( V_9 )
goto error;
if ( type == V_22 )
* V_19 = ( T_2 ) V_20 [ 0 ] ;
else
* V_19 = V_20 [ 0 ] << 8 | V_20 [ 1 ] ;
F_3 ( & V_2 -> V_11 , L_6 , V_12 , * V_19 ) ;
return 0 ;
error:
F_2 ( & V_2 -> V_11 , L_7 , V_18 , V_9 ) ;
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_20 )
{
struct V_6 V_7 ;
const int V_25 = 1 ;
int V_26 ;
V_7 . V_4 = V_2 -> V_4 ;
V_7 . V_14 = 0 ;
V_7 . V_3 = V_3 ;
V_7 . V_5 = V_20 ;
V_26 = F_4 ( V_2 -> V_10 , & V_7 , 1 ) ;
return V_26 == V_25 ? 0 : - V_17 ;
}
static int
F_8 ( struct V_1 * V_2 , T_1 V_27 , T_1 V_18 , T_1 V_19 )
{
int V_26 ;
unsigned char V_20 [ 4 ] = { 0 } ;
T_1 * V_28 ;
const T_1 V_3 = V_27 + sizeof( T_1 ) ;
F_3 ( & V_2 -> V_11 ,
L_8 ,
V_12 , V_27 , V_18 , V_19 ) ;
if ( ! V_2 -> V_10 ) {
F_2 ( & V_2 -> V_11 , L_1 , V_12 ) ;
return - V_13 ;
}
if ( V_27 != V_22 && V_27 != V_23 ) {
F_2 ( & V_2 -> V_11 , L_9 , V_12 ) ;
return - V_24 ;
}
V_28 = ( T_1 * ) V_20 ;
* V_28 = F_9 ( V_18 ) ;
if ( V_27 == V_22 ) {
V_20 [ 2 ] = ( T_2 ) ( V_19 ) ;
} else {
T_1 * V_29 = ( T_1 * ) & V_20 [ 2 ] ;
* V_29 = F_10 ( V_19 ) ;
}
V_26 = F_7 ( V_2 , V_3 , V_20 ) ;
if ( V_26 )
F_2 ( & V_2 -> V_11 ,
L_10 ,
V_19 , V_18 , V_26 ) ;
return V_26 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
T_1 V_32 ;
if ( V_31 -> V_33 == 0 )
return 0 ;
V_32 = sizeof( T_1 ) + V_31 -> V_33 ;
V_31 -> V_34 . V_4 = F_9 ( V_31 -> V_34 . V_4 ) ;
V_31 -> V_33 = 0 ;
return F_7 ( V_2 , V_32 , ( T_2 * ) & V_31 -> V_34 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
const struct V_35 * V_36 )
{
int V_32 ;
T_1 * V_37 ;
switch ( V_36 -> type ) {
case V_22 :
V_32 = 1 ;
V_31 -> V_34 . V_20 [ V_31 -> V_33 ] = ( T_2 ) V_36 -> V_19 ;
break;
case V_23 :
V_32 = 2 ;
V_37 = ( T_1 * ) & V_31 -> V_34 . V_20 [ V_31 -> V_33 ] ;
* V_37 = F_9 ( ( T_1 ) V_36 -> V_19 ) ;
break;
default:
return - V_24 ;
}
if ( V_31 -> V_33 == 0 )
V_31 -> V_34 . V_4 = V_36 -> V_38 ;
V_31 -> V_33 += V_32 ;
if ( V_31 -> V_33 + sizeof( T_1 ) >= V_39 )
F_11 ( V_2 , V_31 ) ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
const struct V_35 * V_36 )
{
if ( V_31 -> V_33 == 0 )
return 1 ;
return V_31 -> V_34 . V_4 + V_31 -> V_33 == V_36 -> V_38 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_35 * V_40 )
{
const struct V_35 * V_36 = V_40 ;
struct V_30 V_31 ;
int V_9 ;
V_31 . V_33 = 0 ;
for (; V_36 -> type != V_41 ; V_36 ++ ) {
switch ( V_36 -> type & V_42 ) {
case V_43 :
V_9 = F_11 ( V_2 , & V_31 ) ;
if ( V_9 )
return V_9 ;
F_15 ( V_36 -> V_19 ) ;
break;
default:
if ( ! F_13 ( V_2 ,
& V_31 , V_36 ) ) {
V_9 = F_11 ( V_2 , & V_31 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_12 ( V_2 , & V_31 , V_36 ) ;
if ( V_9 ) {
F_2 ( & V_2 -> V_11 , L_11 ,
V_12 ) ;
return V_9 ;
}
break;
}
}
return F_11 ( V_2 , & V_31 ) ;
}
static int F_16 ( int V_44 ,
const struct V_45 * V_46 )
{
int V_47 = V_48 ;
int V_49 ;
if ( V_44 == 0 )
return 0 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
if ( ! V_46 [ V_49 ] . V_44 )
break;
if ( abs ( V_46 [ V_49 ] . V_44 - V_44 ) < V_47 )
V_47 = abs ( V_46 [ V_49 ] . V_44 - V_44 ) ;
}
return V_47 ;
}
static int F_17 ( int V_44 ,
const struct V_45 * V_46 )
{
int V_51 = 0 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
if ( ! V_46 [ V_49 ] . V_44 )
break;
if ( abs ( V_46 [ V_49 ] . V_44 - V_44 )
< abs ( V_46 [ V_51 ] . V_44 - V_44 ) )
V_51 = V_49 ;
}
return V_51 ;
}
static int F_18 ( struct V_52 * V_53 ,
T_1 * V_54 , T_1 * V_55 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
int V_26 ;
F_3 ( & V_2 -> V_11 , L_12 ,
V_12 , * V_54 ) ;
V_26 = F_8 ( V_2 , V_23 ,
V_56 , * V_54 >> 1 ) ;
if ( V_26 )
return V_26 ;
F_3 ( & V_2 -> V_11 , L_13 ,
V_12 , * V_55 ) ;
return F_8 ( V_2 , V_23 , V_57 , * V_55 ) ;
}
static int F_20 ( struct V_52 * V_53 , int V_58 , int V_59 ,
int V_60 , T_1 * V_54 , T_1 * V_55 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
int V_62 , V_26 ;
F_3 ( & V_2 -> V_11 , L_14 ,
V_12 , V_58 , V_59 , V_60 ) ;
if ( V_11 -> V_63 ) {
if ( V_58 > * V_55 - V_64 )
V_58 = * V_55 - V_64 ;
} else {
if ( * V_55 < V_58 + V_64 )
* V_55 = ( T_1 ) V_58 + V_64 ;
}
V_26 = F_18 ( V_53 , V_54 , V_55 ) ;
if ( V_26 )
return V_26 ;
V_62 = V_58 << 4 ;
V_26 = F_8 ( V_2 , V_22 ,
V_65 + 2 , V_62 & 0xFF ) ;
if ( V_26 )
return V_26 ;
V_26 = F_8 ( V_2 , V_22 ,
V_65 + 1 , ( V_62 >> 8 ) & 0xFF ) ;
if ( V_26 )
return V_26 ;
V_26 = F_8 ( V_2 , V_22 ,
V_65 , ( V_62 >> 16 ) & 0x0F ) ;
if ( V_26 )
return V_26 ;
if ( V_60 ) {
V_26 = F_8 ( V_2 , V_23 ,
V_66 , V_60 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_8 ( V_2 , V_23 ,
V_67 , V_60 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_8 ( V_2 , V_23 ,
V_68 , V_60 ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_8 ( V_2 , V_23 , V_69 ,
V_59 & 0x07ff ) ;
if ( V_26 )
return V_26 ;
V_11 -> V_59 = V_59 ;
V_11 -> V_58 = V_58 ;
V_11 -> V_70 = V_60 ;
return 0 ;
}
static int F_22 ( struct V_52 * V_53 , int V_58 , int V_59 ,
int V_60 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
const struct V_71 * V_72 ;
T_1 V_54 , V_55 ;
int V_26 ;
F_23 ( & V_11 -> V_73 ) ;
V_58 = F_24 ( int , V_58 , 0 , V_74 ) ;
V_59 = F_24 ( int , V_59 , 0 , V_75 ) ;
V_60 = F_24 ( int , V_60 , 0 , V_76 ) ;
V_72 = & V_11 -> V_77 [ V_11 -> V_78 ] ;
V_54 = V_72 -> V_79 [ V_11 -> V_51 ] . V_80 ;
V_55 = V_72 -> V_79 [ V_11 -> V_51 ] . V_81 ;
V_26 = F_20 ( V_53 , V_58 , V_59 , V_60 , & V_54 , & V_55 ) ;
F_25 ( & V_11 -> V_73 ) ;
return V_26 ;
}
static int F_26 ( struct V_52 * V_53 ,
struct V_82 * V_58 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
int V_59 = V_58 -> V_59 ;
F_3 ( & V_2 -> V_11 , L_15 , V_12 ,
V_58 -> V_59 , V_58 -> V_83 ) ;
V_58 -> V_84 = V_11 -> V_70 ;
V_58 -> V_85 = ( ( ( V_59 & 0x700 ) >> 8 ) + 1 ) * ( V_59 & 0xFF ) ;
return 0 ;
}
static int F_27 ( struct V_52 * V_53 ,
struct V_86 * V_58 )
{
return F_22 ( V_53 , V_58 -> V_87 [ 0 ] ,
V_58 -> V_59 [ 0 ] , V_58 -> V_59 [ 1 ] ) ;
}
static int F_28 ( struct V_52 * V_53 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
T_3 V_32 = V_88 - V_89 + 1 ;
int V_90 ;
T_1 V_91 = 0 ;
if ( ! V_11 -> V_92 ) {
V_11 -> V_92 = F_29 ( & V_2 -> V_11 , V_32 , V_93 ) ;
if ( ! V_11 -> V_92 ) {
F_2 ( & V_2 -> V_11 , L_16 ,
V_12 ) ;
V_90 = - V_94 ;
goto V_95;
}
V_90 = F_8 ( V_2 , V_22 , V_96 ,
0x01 ) ;
if ( V_90 )
goto V_97;
V_90 = F_6 ( V_2 , V_22 ,
V_98 , & V_91 ) ;
if ( V_90 )
goto V_99;
V_90 = F_8 ( V_2 , V_22 , V_98 ,
V_91 & ~ V_100 ) ;
if ( V_90 )
goto V_99;
V_90 = F_8 ( V_2 , V_22 , V_101 ,
V_102 |
V_103 ) ;
if ( V_90 )
goto V_99;
V_90 = F_8 ( V_2 , V_23 ,
V_104 ,
V_89 ) ;
if ( V_90 )
goto V_99;
V_90 = F_8 ( V_2 , V_23 ,
V_105 ,
V_88 ) ;
if ( V_90 )
goto V_99;
V_90 = F_8 ( V_2 , V_22 , V_106 ,
V_107 ) ;
if ( V_90 )
goto V_99;
F_30 ( 5000 , 5500 ) ;
V_90 = F_1 ( V_2 , V_32 , V_89 ,
V_11 -> V_92 ) ;
if ( V_90 )
goto V_99;
V_90 = F_8 ( V_2 , V_22 , V_98 ,
V_91 | V_100 ) ;
if ( V_90 )
goto V_99;
V_90 = F_8 ( V_2 , 1 , V_96 , 0x00 ) ;
if ( V_90 ) {
F_2 ( & V_2 -> V_11 , L_17 ,
V_12 ) ;
goto V_99;
}
}
return 0 ;
V_99:
F_8 ( V_2 , V_22 , V_98 ,
V_91 | V_100 ) ;
F_8 ( V_2 , 1 , V_96 , 0x00 ) ;
V_97:
F_31 ( & V_2 -> V_11 , V_11 -> V_92 ) ;
V_11 -> V_92 = NULL ;
V_95:
F_2 ( & V_2 -> V_11 , L_18 , V_12 ) ;
return V_90 ;
}
static int F_32 ( struct V_52 * V_53 ,
struct V_108 * V_109 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
T_3 V_32 = V_88 - V_89 + 1 ;
int V_90 ;
F_23 ( & V_11 -> V_73 ) ;
if ( ! V_11 -> V_92 ) {
F_2 ( & V_2 -> V_11 , L_19 , V_12 ) ;
F_25 ( & V_11 -> V_73 ) ;
return - V_110 ;
}
if ( F_33 ( V_109 -> V_20 , V_11 -> V_92 ,
F_34 ( V_111 , V_109 -> V_32 , V_32 ) ) ) {
V_90 = - V_110 ;
F_2 ( & V_2 -> V_11 , L_18 , V_12 ) ;
F_25 ( & V_11 -> V_73 ) ;
return V_90 ;
}
V_109 -> V_32 = V_32 ;
F_25 ( & V_11 -> V_73 ) ;
return 0 ;
}
static int F_35 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
int V_26 ;
F_3 ( & V_2 -> V_11 , L_20 , V_12 ) ;
V_11 -> V_51 = 0 ;
V_11 -> V_58 = 256 ;
V_11 -> V_59 = 16 ;
V_11 -> V_70 = 1024 ;
V_11 -> V_63 = false ;
F_3 ( & V_2 -> V_11 , L_21 ,
V_12 ) ;
V_26 = F_14 ( V_2 , V_112 ) ;
if ( V_26 )
return V_26 ;
return F_28 ( V_53 ) ;
}
static int F_36 ( struct V_52 * V_53 , T_3 V_19 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
int V_26 ;
F_23 ( & V_11 -> V_73 ) ;
V_26 = F_35 ( V_53 ) ;
F_25 ( & V_11 -> V_73 ) ;
return V_26 ;
}
static void F_37 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_113 * V_31 ;
F_3 ( & V_2 -> V_11 , L_22 , V_12 ) ;
V_11 -> V_58 = 0 ;
V_11 -> V_59 = 0 ;
V_11 -> V_70 = 0 ;
V_11 -> V_63 = false ;
F_25 ( & V_11 -> V_73 ) ;
V_31 = F_38 ( V_53 -> V_114 ,
V_115 ) ;
if ( V_31 )
F_39 ( V_31 , V_116 ) ;
F_23 ( & V_11 -> V_73 ) ;
}
static int F_40 ( struct V_52 * V_53 , unsigned int * V_117 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
int V_26 = 0 , V_58 ;
T_1 V_55 , V_20 ;
if ( V_11 -> V_58 == 0 ) {
V_26 = F_6 ( V_2 , V_23 ,
V_65 + 1 , & V_20 ) ;
if ( V_26 )
return V_26 ;
V_58 = V_20 ;
V_58 >>= 4 ;
} else {
V_58 = V_11 -> V_58 ;
}
V_26 = F_6 ( V_2 , V_23 , V_57 , & V_55 ) ;
if ( V_26 || V_55 == 0 )
V_55 = V_118 ;
* V_117 = ( V_58 * 33333 / V_55 ) ;
if ( * V_117 > V_119 )
* V_117 = * V_117 - V_119 ;
else
* V_117 = V_119 ;
return 0 ;
}
static long F_41 ( struct V_52 * V_53 , unsigned int V_120 , void * V_121 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
switch ( V_120 ) {
case V_122 :
return F_27 ( V_53 , (struct V_86 * ) V_121 ) ;
case V_123 :
return F_32 ( V_53 , V_121 ) ;
case V_124 :
return F_40 ( V_53 , ( unsigned int * ) V_121 ) ;
case V_125 :
return F_26 ( V_53 ,
(struct V_82 * ) V_121 ) ;
default:
F_3 ( & V_2 -> V_11 , L_23 , V_120 ) ;
return - V_24 ;
}
}
static int F_42 ( struct V_52 * V_53 , bool V_126 )
{
int V_26 = 0 ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
if ( ! V_11 || ! V_11 -> V_127 )
return - V_13 ;
if ( V_11 -> V_127 -> V_128 )
return V_11 -> V_127 -> V_128 ( V_53 , V_126 ) ;
if ( V_11 -> V_127 -> V_129 ) {
V_26 = V_11 -> V_127 -> V_129 ( V_53 , V_126 ) ;
if ( V_26 ) {
F_2 ( & V_2 -> V_11 ,
L_24 ,
V_126 ? L_25 : L_26 ) ;
return V_26 ;
}
}
if ( V_11 -> V_127 -> V_130 ) {
V_26 = V_11 -> V_127 -> V_130 ( V_53 , V_126 ) ;
if ( V_26 ) {
F_2 ( & V_2 -> V_11 ,
L_27 ,
V_126 ? L_25 : L_26 ) ;
return V_26 ;
}
}
if ( V_11 -> V_127 -> V_131 ) {
V_26 = V_11 -> V_127 -> V_131 ( V_53 , V_126 ) ;
if ( V_26 ) {
F_2 ( & V_2 -> V_11 ,
L_28 ,
V_126 ? L_25 : L_26 ) ;
if ( V_11 -> V_127 -> V_130 )
V_11 -> V_127 -> V_130 ( V_53 , 0 ) ;
return V_26 ;
}
}
if ( V_126 )
F_15 ( 20 ) ;
return V_26 ;
}
static int F_43 ( struct V_52 * V_53 , bool V_126 )
{
struct V_1 * V_2 ;
struct V_61 * V_11 ;
if ( ! V_53 )
return - V_24 ;
V_2 = F_19 ( V_53 ) ;
V_11 = F_21 ( V_53 ) ;
if ( ! V_2 || ! V_11 || ! V_11 -> V_127 )
return - V_13 ;
if ( V_11 -> V_127 -> V_132 )
return V_11 -> V_127 -> V_132 ( V_53 , V_126 ) ;
if ( V_11 -> V_127 -> V_133 )
return V_11 -> V_127 -> V_133 ( V_53 , V_126 ) ;
F_2 ( & V_2 -> V_11 , L_29 ) ;
return - V_24 ;
}
static int F_44 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
int V_26 ;
F_3 ( & V_2 -> V_11 , L_20 , V_12 ) ;
V_26 = F_42 ( V_53 , 1 ) ;
if ( V_26 ) {
F_2 ( & V_2 -> V_11 , L_30 , V_26 ) ;
goto V_134;
}
V_26 = V_11 -> V_127 -> V_135 ( V_53 , 1 ) ;
if ( V_26 ) {
F_2 ( & V_2 -> V_11 , L_31 , V_26 ) ;
goto V_136;
}
V_26 = F_43 ( V_53 , 1 ) ;
if ( V_26 ) {
F_2 ( & V_2 -> V_11 , L_32 , V_26 ) ;
goto V_137;
}
F_30 ( 2000 , 2500 ) ;
return 0 ;
V_137:
V_11 -> V_127 -> V_135 ( V_53 , 0 ) ;
V_136:
F_42 ( V_53 , 0 ) ;
V_134:
F_2 ( & V_2 -> V_11 , L_33 ) ;
return V_26 ;
}
static int F_45 ( struct V_52 * V_53 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
int V_26 ;
F_3 ( & V_2 -> V_11 , L_20 , V_12 ) ;
V_26 = V_11 -> V_127 -> V_135 ( V_53 , 0 ) ;
if ( V_26 )
F_2 ( & V_2 -> V_11 , L_34 ) ;
V_26 = F_43 ( V_53 , 0 ) ;
if ( V_26 )
F_2 ( & V_2 -> V_11 , L_35 ) ;
V_26 = F_42 ( V_53 , 0 ) ;
if ( V_26 )
F_2 ( & V_2 -> V_11 , L_36 ) ;
return V_26 ;
}
static int F_46 ( struct V_52 * V_53 , int V_138 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
int V_26 , V_90 = 0 ;
if ( V_138 == 0 ) {
F_37 ( V_53 ) ;
if ( V_11 -> V_139 && V_11 -> V_139 -> F_45 )
V_90 = V_11 -> V_139 -> F_45 ( V_53 ) ;
V_26 = F_45 ( V_53 ) ;
if ( V_90 != 0 && V_26 == 0 )
V_26 = V_90 ;
} else {
V_26 = F_44 ( V_53 ) ;
if ( V_26 )
F_45 ( V_53 ) ;
if ( V_11 -> V_139 && V_11 -> V_139 -> F_44 ) {
V_26 = V_11 -> V_139 -> F_44 ( V_53 ) ;
if ( V_26 ) {
F_45 ( V_53 ) ;
return V_26 ;
}
}
return F_35 ( V_53 ) ;
}
return V_26 ;
}
static int F_47 ( struct V_52 * V_53 , int V_138 )
{
int V_26 ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
F_23 ( & V_11 -> V_73 ) ;
V_26 = F_46 ( V_53 , V_138 ) ;
F_25 ( & V_11 -> V_73 ) ;
if ( ! V_26 && V_138 )
F_39 ( V_11 -> V_140 , V_141 ) ;
return V_26 ;
}
static int F_48 ( struct V_52 * V_53 , int V_18 , int type ,
const struct V_35 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
const struct V_35 * V_36 ;
T_1 V_19 ;
for ( V_36 = V_40 ; V_36 -> type != V_41 ; V_36 ++ ) {
if ( V_36 -> V_38 == V_18 ) {
if ( type == V_22 )
return V_36 -> V_19 ;
if ( type == V_23 &&
V_36 [ 1 ] . type != V_41 )
return V_36 [ 0 ] . V_19 << 8 | V_36 [ 1 ] . V_19 ;
}
}
if ( F_6 ( V_2 , type , V_18 , & V_19 ) ) {
F_2 ( & V_2 -> V_11 , L_37 , V_18 ) ;
return - V_17 ;
}
return V_19 ;
}
static inline int F_49 ( struct V_52 * V_53 , int V_18 ,
const struct V_35 * V_40 )
{
return F_48 ( V_53 , V_18 , V_23 , V_40 ) ;
}
static inline int F_50 ( struct V_52 * V_53 , int V_18 ,
const struct V_35 * V_40 )
{
return F_48 ( V_53 , V_18 , V_22 , V_40 ) ;
}
static int F_51 ( struct V_52 * V_53 ,
int * V_142 ,
const struct V_35 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
unsigned int V_143 ;
unsigned int V_144 ;
unsigned int V_145 ;
unsigned int V_146 [] = { 2 , 3 , 4 , 5 , 6 , 8 , 12 , 16 } ;
int V_26 ;
V_26 = F_50 ( V_53 , V_147 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 & V_148 )
* V_142 /= 2 ;
V_26 = F_50 ( V_53 , V_149 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_143 = V_26 & V_150 ;
* V_142 = * V_142 * 2 / V_146 [ V_143 ] ;
V_26 = F_49 ( V_53 , V_151 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_144 = V_26 ;
* V_142 *= V_144 & V_152 ;
V_26 = F_50 ( V_53 , V_153 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_145 = V_26 & V_154 ;
* V_142 /= ( V_145 + 3 ) ;
V_26 = F_50 ( V_53 , V_155 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 & V_156 )
* V_142 /= 2 ;
F_3 ( & V_2 -> V_11 , L_38 , V_12 , * V_142 ) ;
return 0 ;
}
static int F_52 ( struct V_52 * V_53 , int * V_142 ,
const struct V_35 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
unsigned int V_143 ;
unsigned int V_144 ;
unsigned int V_146 [] = { 2 , 3 , 4 , 5 , 6 , 8 , 12 , 16 } ;
int V_26 ;
V_26 = F_50 ( V_53 , V_157 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 & V_158 )
* V_142 /= 2 ;
V_26 = F_50 ( V_53 , V_159 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_143 = ( V_26 & V_160 ) ;
* V_142 = * V_142 * 2 / V_146 [ V_143 ] ;
V_26 = F_49 ( V_53 , V_161 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_144 = V_26 ;
* V_142 *= V_144 & V_162 ;
F_3 ( & V_2 -> V_11 , L_38 , V_12 , * V_142 ) ;
return 0 ;
}
static int F_53 ( struct V_52 * V_53 , int * V_142 ,
const struct V_35 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
unsigned int V_163 ;
int V_26 ;
V_26 = F_50 ( V_53 , V_164 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_163 = ( V_26 & V_165 ) + 1 ;
* V_142 /= V_163 ;
F_3 ( & V_2 -> V_11 , L_38 , V_12 , * V_142 ) ;
return 0 ;
}
static int F_54 ( struct V_52 * V_53 , int * V_142 ,
const struct V_35 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
unsigned int V_166 ;
unsigned int V_167 ;
unsigned int V_168 [] = { 2 , 3 , 4 , 5 , 6 , 7 , 8 , 10 } ;
int V_26 ;
V_26 = F_50 ( V_53 , V_169 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_166 = ( V_26 & V_170 ) + 1 ;
* V_142 /= V_166 ;
V_26 = F_50 ( V_53 , V_171 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_167 = V_26 & V_172 ;
* V_142 *= 2 / V_168 [ V_167 ] ;
F_3 ( & V_2 -> V_11 , L_38 , V_12 , * V_142 ) ;
return 0 ;
}
static int F_55 ( struct V_52 * V_53 ,
struct V_173 * V_174 ,
const struct V_35 * V_40 )
{
const unsigned int V_175 = 19200000 ;
struct V_176 * V_177 = & V_174 -> V_20 ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
struct V_178 * V_179 = & V_2 -> V_11 ;
const struct V_71 * V_72 =
& V_11 -> V_77 [ V_11 -> V_78 ] ;
unsigned int V_180 ;
unsigned int V_181 ;
unsigned int V_166 ;
unsigned int V_182 ;
unsigned int V_183 = V_175 ;
T_1 V_54 ;
int V_26 ;
memset ( & V_174 -> V_20 , 0 , sizeof( V_174 -> V_20 ) ) ;
V_26 = F_50 ( V_53 , V_184 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
F_3 ( V_179 , L_39 , V_12 , V_26 ) ;
V_180 = V_26 & V_185 ;
V_26 = F_50 ( V_53 , V_186 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
F_3 ( V_179 , L_40 , V_12 , V_26 ) ;
V_181 = V_26 & V_187 ;
if ( V_181 ) {
V_26 = F_52 ( V_53 , & V_183 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_53 ( V_53 , & V_183 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
} else if ( V_180 ) {
V_26 = F_52 ( V_53 , & V_183 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_54 ( V_53 , & V_183 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
} else {
V_26 = F_51 ( V_53 , & V_183 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_26 = F_50 ( V_53 , V_188 , V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
F_3 ( V_179 , L_41 , V_12 , V_26 ) ;
V_166 = V_26 & V_189 ;
V_166 >>= V_190 ;
if ( V_166 == 1 )
V_183 /= 2 ;
else if ( V_166 == 2 )
V_183 /= 4 ;
V_182 = V_26 & V_191 ;
V_182 >>= V_192 ;
if ( V_182 > 1 )
V_183 /= V_182 ;
F_3 ( V_179 , L_42 , V_12 , V_183 ) ;
V_11 -> V_193 = V_183 ;
V_177 -> V_193 = V_183 ;
V_177 -> V_194 =
V_72 -> V_79 [ V_11 -> V_51 ] . V_81 ;
V_177 -> V_195 = V_72 -> V_79 [ V_11 -> V_51 ] . V_80 ;
V_177 -> V_196 = 0 ;
V_177 -> V_197 = V_64 ;
V_26 = F_6 ( V_2 , V_23 , V_56 , & V_54 ) ;
if ( V_26 < 0 )
return V_26 ;
V_177 -> V_54 = V_54 ;
F_3 ( & V_2 -> V_11 , L_43 , V_12 , V_54 ) ;
V_177 -> V_198 = 0 ;
V_177 -> V_199 = 0 ;
V_177 -> V_200 = V_72 -> V_201 ?
V_202 : V_203 ;
V_26 = F_50 ( V_53 , V_204 , V_72 -> V_205 ) ;
if ( V_26 < 0 )
return V_26 ;
V_177 -> V_206 = ( V_26 + 1 ) / 2 ;
V_26 = F_50 ( V_53 , V_207 , V_72 -> V_205 ) ;
if ( V_26 < 0 )
return V_26 ;
V_177 -> V_208 = ( V_26 + 1 ) / 2 ;
V_26 = F_49 ( V_53 , V_209 ,
V_72 -> V_205 ) ;
if ( V_26 < 0 )
return V_26 ;
V_177 -> V_210 = V_26 ;
V_26 = F_49 ( V_53 , V_211 , V_72 -> V_205 ) ;
if ( V_26 < 0 )
return V_26 ;
V_177 -> V_212 = V_26 ;
V_26 = F_49 ( V_53 , V_213 , V_72 -> V_205 ) ;
if ( V_26 < 0 )
return V_26 ;
V_177 -> V_214 = V_26 ;
V_26 = F_49 ( V_53 , V_215 , V_72 -> V_205 ) ;
if ( V_26 < 0 )
return V_26 ;
V_177 -> V_216 = V_26 ;
V_26 = F_49 ( V_53 , V_217 ,
V_72 -> V_205 ) ;
if ( V_26 < 0 )
return V_26 ;
V_177 -> V_218 = V_26 ;
V_26 = F_49 ( V_53 , V_219 ,
V_72 -> V_205 ) ;
if ( V_26 < 0 )
return V_26 ;
V_177 -> V_220 = V_26 ;
return 0 ;
}
static int F_56 ( struct V_71 const * V_72 , const T_3 V_221 ,
const T_3 V_222 )
{
int V_223 ;
int F_56 ;
if ( V_221 == 0 || V_222 == 0 ||
V_72 -> V_224 < V_221 || V_72 -> V_225 < V_222 )
return - 1 ;
V_223 = V_72 -> V_224 << 13 ;
V_223 /= V_221 ;
V_223 *= V_222 ;
V_223 /= V_72 -> V_225 ;
F_56 = abs ( V_223 - 8192 ) ;
if ( F_56 > V_226 )
return - 1 ;
return F_56 ;
}
static int F_57 ( struct V_52 * V_53 , int V_221 , int V_222 )
{
int V_49 ;
int V_227 = - 1 ;
int V_228 ;
int V_229 ;
int V_230 = V_48 ;
int V_231 = V_48 ;
int V_232 = V_48 ;
const struct V_71 * V_233 = NULL ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
F_3 ( & V_2 -> V_11 , L_44 , V_12 , V_221 , V_222 ) ;
for ( V_49 = 0 ; V_49 < V_11 -> V_234 ; V_49 ++ ) {
V_233 = & V_11 -> V_77 [ V_49 ] ;
V_228 = F_56 ( V_233 , V_221 , V_222 ) ;
F_3 ( & V_2 -> V_11 ,
L_45 , V_233 -> V_235 ,
V_49 , V_233 -> V_224 , V_233 -> V_225 , V_228 ) ;
if ( V_228 == - 1 )
continue;
if ( V_228 < V_231 ) {
V_231 = V_228 ;
V_232 = V_233 -> V_224 ;
V_230 = F_16 ( V_11 -> V_44 ,
V_233 -> V_79 ) ;
V_227 = V_49 ;
}
if ( V_228 == V_231 ) {
V_229 = F_16 ( V_11 -> V_44 ,
V_233 -> V_79 ) ;
if ( V_229 < V_230 ) {
V_230 = V_229 ;
V_227 = V_49 ;
}
if ( V_233 -> V_224 < V_232 ) {
V_232 = V_233 -> V_224 ;
V_227 = V_49 ;
}
}
}
return V_227 ;
}
static int F_58 ( struct V_52 * V_53 ,
struct V_236 * V_237 ,
struct V_238 * V_239 )
{
struct V_240 * V_241 = & V_239 -> V_239 ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_173 * V_242 = NULL ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
const struct V_71 * V_72 ;
int V_26 ;
int V_227 ;
if ( V_239 -> V_243 )
return - V_24 ;
if ( ! V_241 )
return - V_24 ;
V_242 = F_59 ( V_53 ) ;
if ( V_242 == NULL )
return - V_24 ;
F_23 ( & V_11 -> V_73 ) ;
if ( ( V_241 -> V_224 > V_244 ) ||
( V_241 -> V_225 > V_245 ) ) {
V_241 -> V_224 = V_244 ;
V_241 -> V_225 = V_245 ;
} else {
V_227 = F_57 ( V_53 , V_241 -> V_224 , V_241 -> V_225 ) ;
if ( V_227 == - 1 )
V_227 = V_11 -> V_234 - 1 ;
V_241 -> V_224 = V_11 -> V_77 [ V_227 ] . V_224 ;
V_241 -> V_225 = V_11 -> V_77 [ V_227 ] . V_225 ;
}
V_241 -> V_246 = V_247 ;
if ( V_239 -> V_248 == V_249 ) {
V_237 -> V_250 = * V_241 ;
F_25 ( & V_11 -> V_73 ) ;
return 0 ;
}
V_11 -> V_78 = F_57 ( V_53 , V_241 -> V_224 , V_241 -> V_225 ) ;
if ( V_11 -> V_78 == - 1 ) {
V_26 = - V_24 ;
goto V_251;
}
V_72 = & V_11 -> V_77 [ V_11 -> V_78 ] ;
F_3 ( & V_2 -> V_11 , L_46 ,
V_12 , V_72 -> V_224 , V_72 -> V_225 ) ;
V_11 -> V_51 = F_17 ( V_11 -> V_44 , V_72 -> V_79 ) ;
V_11 -> V_44 = V_72 -> V_79 [ V_11 -> V_51 ] . V_44 ;
V_11 -> V_205 = V_72 -> V_79 [ V_11 -> V_51 ] . V_205 ;
if ( ! V_11 -> V_205 )
V_11 -> V_205 = V_72 -> V_205 ;
V_26 = F_14 ( V_2 , V_11 -> V_205 ) ;
if ( V_26 )
goto V_251;
V_11 -> V_80 = V_72 -> V_79 [ V_11 -> V_51 ] . V_80 ;
V_11 -> V_81 = V_72 -> V_79 [ V_11 -> V_51 ] . V_81 ;
V_242 -> V_252 = V_72 -> V_224 * 10 / 8 ;
V_242 -> V_253 = 2 ;
V_242 -> V_254 = V_255 ;
V_26 = F_20 ( V_53 , V_11 -> V_58 , V_11 -> V_59 ,
V_11 -> V_70 , & V_11 -> V_80 ,
& V_11 -> V_81 ) ;
if ( V_26 )
goto V_251;
V_26 = F_55 ( V_53 , V_242 , V_11 -> V_205 ) ;
V_251:
F_25 ( & V_11 -> V_73 ) ;
return V_26 ;
}
static int F_60 ( struct V_52 * V_53 ,
struct V_236 * V_237 ,
struct V_238 * V_239 )
{
struct V_240 * V_241 = & V_239 -> V_239 ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
if ( V_239 -> V_243 )
return - V_24 ;
if ( ! V_241 )
return - V_24 ;
F_23 ( & V_11 -> V_73 ) ;
V_241 -> V_224 = V_11 -> V_77 [ V_11 -> V_78 ] . V_224 ;
V_241 -> V_225 = V_11 -> V_77 [ V_11 -> V_78 ] . V_225 ;
V_241 -> V_246 = V_247 ;
F_25 ( & V_11 -> V_73 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , T_1 * V_256 )
{
struct V_257 * V_10 = V_2 -> V_10 ;
T_1 V_258 = 0 ;
T_1 V_259 = 0 ;
int V_26 ;
if ( ! F_62 ( V_10 , V_260 ) )
return - V_13 ;
F_3 ( & V_2 -> V_11 , L_47 , V_12 ) ;
V_26 = F_6 ( V_2 , V_22 , V_261 , & V_258 ) ;
if ( V_26 )
return V_26 ;
F_3 ( & V_2 -> V_11 , L_48 , V_12 , V_258 ) ;
V_26 = F_6 ( V_2 , V_22 , V_262 , & V_259 ) ;
if ( V_26 )
return V_26 ;
F_3 ( & V_2 -> V_11 , L_49 , V_12 , V_259 ) ;
* V_256 = ( V_258 << 8 ) | V_259 ;
F_3 ( & V_2 -> V_11 , L_50 , V_12 , * V_256 ) ;
F_63 ( & V_2 -> V_11 , L_50 , V_12 , * V_256 ) ;
if ( * V_256 != V_263 )
return - V_13 ;
return F_8 ( V_2 , V_22 , V_96 , 0 ) ;
}
static void F_64 ( struct V_52 * V_53 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
T_1 V_224 = V_11 -> V_77 [ V_11 -> V_78 ] . V_224 ;
T_1 V_225 = V_11 -> V_77 [ V_11 -> V_78 ] . V_225 ;
F_3 ( & V_2 -> V_11 , L_51 ) ;
F_3 ( & V_2 -> V_11 , L_52 , V_224 ) ;
F_3 ( & V_2 -> V_11 , L_53 , V_225 ) ;
F_3 ( & V_2 -> V_11 , L_54 , V_11 -> V_80 ) ;
F_3 ( & V_2 -> V_11 , L_55 , V_11 -> V_81 ) ;
F_3 ( & V_2 -> V_11 , L_56 , V_11 -> V_193 ) ;
F_3 ( & V_2 -> V_11 , L_57 , V_11 -> V_193 /
( V_11 -> V_80 / 2 ) / V_11 -> V_81 ) ;
F_3 ( & V_2 -> V_11 , L_58 ,
1000 * ( V_11 -> V_80 - V_224 ) /
( V_11 -> V_193 / 1000000 ) ) ;
F_3 ( & V_2 -> V_11 , L_59 ,
( V_11 -> V_81 - V_225 ) * V_11 -> V_80 /
( V_11 -> V_193 / 1000000 ) ) ;
}
static int F_65 ( struct V_52 * V_53 , int V_264 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
int V_26 ;
T_1 V_19 ;
F_3 ( & V_2 -> V_11 , L_60 , V_12 , V_264 ) ;
V_26 = F_6 ( V_2 , V_22 , V_265 , & V_19 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_8 ( V_2 , V_22 , V_265 ,
V_11 -> V_266 ? V_19 | V_267 :
V_19 & ~ V_267 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_6 ( V_2 , V_22 , V_268 , & V_19 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_8 ( V_2 , V_22 , V_268 ,
V_11 -> V_269 ? V_19 | V_267 :
V_19 & ~ V_267 ) ;
if ( V_26 )
return V_26 ;
F_23 ( & V_11 -> V_73 ) ;
if ( V_264 ) {
F_64 ( V_53 ) ;
V_26 = F_14 ( V_2 , V_270 ) ;
if ( V_26 != 0 ) {
F_2 ( & V_2 -> V_11 , L_61 ) ;
goto V_251;
}
V_11 -> V_271 = 1 ;
} else {
V_26 = F_14 ( V_2 , V_272 ) ;
if ( V_26 != 0 ) {
F_2 ( & V_2 -> V_11 , L_61 ) ;
goto V_251;
}
V_11 -> V_271 = 0 ;
V_11 -> V_51 = 0 ;
V_11 -> V_44 = 0 ;
}
V_251:
F_25 ( & V_11 -> V_73 ) ;
return V_26 ;
}
static int F_66 ( struct V_61 * V_11 ,
T_1 V_273 )
{
if ( V_273 == V_263 )
#ifdef F_67
V_11 -> V_139 = & V_274 [ V_275 ] ;
#else
V_11 -> V_139 = & V_274 [ V_276 ] ;
#endif
else
return - V_13 ;
if ( V_11 -> V_139 && V_11 -> V_139 -> V_277 )
return V_11 -> V_139 -> V_277 ( & V_11 -> V_53 ) ;
return 0 ;
}
static int F_68 ( struct V_52 * V_53 ,
int V_278 , void * V_279 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
T_1 V_273 ;
int V_26 ;
if ( V_279 == NULL )
return - V_13 ;
V_11 -> V_127 = V_279 ;
F_23 ( & V_11 -> V_73 ) ;
if ( V_11 -> V_127 -> V_280 ) {
V_26 = V_11 -> V_127 -> V_280 ( V_2 ) ;
if ( V_26 ) {
F_25 ( & V_11 -> V_73 ) ;
F_2 ( & V_2 -> V_11 , L_62 , V_26 ) ;
return V_26 ;
}
}
V_26 = F_46 ( V_53 , 1 ) ;
if ( V_26 ) {
F_2 ( & V_2 -> V_11 , L_63 , V_26 ) ;
F_25 ( & V_11 -> V_73 ) ;
return V_26 ;
}
V_26 = V_11 -> V_127 -> V_281 ( V_53 , 1 ) ;
if ( V_26 )
goto V_282;
V_26 = F_61 ( V_2 , & V_273 ) ;
if ( V_26 ) {
F_2 ( & V_2 -> V_11 , L_64 , V_26 ) ;
goto V_283;
}
V_11 -> V_273 = V_273 ;
V_26 = F_46 ( V_53 , 0 ) ;
if ( V_26 ) {
V_11 -> V_127 -> V_281 ( V_53 , 0 ) ;
F_2 ( & V_2 -> V_11 , L_65 , V_26 ) ;
goto V_284;
}
V_26 = F_66 ( V_11 , V_11 -> V_273 ) ;
if ( V_26 ) {
V_11 -> V_127 -> V_281 ( V_53 , 0 ) ;
F_2 ( & V_2 -> V_11 , L_66 , V_26 ) ;
goto V_284;
}
F_25 ( & V_11 -> V_73 ) ;
return V_26 ;
V_283:
V_11 -> V_127 -> V_281 ( V_53 , 0 ) ;
V_282:
F_46 ( V_53 , 0 ) ;
V_284:
if ( V_11 -> V_127 -> V_285 )
V_11 -> V_127 -> V_285 () ;
F_25 ( & V_11 -> V_73 ) ;
F_2 ( & V_2 -> V_11 , L_67 ) ;
return V_26 ;
}
static int
F_69 ( struct V_52 * V_53 ,
struct V_236 * V_237 ,
struct V_286 * V_246 )
{
if ( V_246 -> V_33 )
return - V_24 ;
V_246 -> V_246 = V_247 ;
return 0 ;
}
static int
F_70 ( struct V_52 * V_53 ,
struct V_236 * V_237 ,
struct V_287 * V_288 )
{
int V_33 = V_288 -> V_33 ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
F_23 ( & V_11 -> V_73 ) ;
if ( V_33 >= V_11 -> V_234 ) {
F_25 ( & V_11 -> V_73 ) ;
return - V_24 ;
}
V_288 -> V_289 = V_11 -> V_77 [ V_33 ] . V_224 ;
V_288 -> V_290 = V_11 -> V_77 [ V_33 ] . V_225 ;
V_288 -> V_291 = V_11 -> V_77 [ V_33 ] . V_224 ;
V_288 -> V_292 = V_11 -> V_77 [ V_33 ] . V_225 ;
F_25 ( & V_11 -> V_73 ) ;
return 0 ;
}
static int F_71 ( struct V_113 * V_31 )
{
struct V_61 * V_11 = F_72 (
V_31 -> V_293 , struct V_61 , V_114 ) ;
struct V_1 * V_2 = F_19 ( & V_11 -> V_53 ) ;
switch ( V_31 -> V_256 ) {
case V_294 :
switch ( V_31 -> V_19 ) {
case V_295 :
V_11 -> V_77 = V_296 ;
V_11 -> V_234 = F_5 ( V_296 ) ;
break;
case V_297 :
V_11 -> V_77 = V_298 ;
V_11 -> V_234 = F_5 ( V_298 ) ;
break;
default:
V_11 -> V_77 = V_299 ;
V_11 -> V_234 =
F_5 ( V_299 ) ;
}
V_11 -> V_78 = 0 ;
V_11 -> V_51 = 0 ;
return 0 ;
case V_300 :
if ( V_11 -> V_139 && V_11 -> V_139 -> V_301 )
return V_11 -> V_139 -> V_301 ( & V_11 -> V_53 ,
V_31 -> V_19 ) ;
return 0 ;
case V_115 :
if ( V_31 -> V_19 == V_116 )
V_11 -> V_63 = false ;
else if ( V_31 -> V_19 == V_302 )
V_11 -> V_63 = true ;
return 0 ;
case V_303 :
V_11 -> V_266 = V_31 -> V_19 ;
return 0 ;
case V_304 :
V_11 -> V_269 = V_31 -> V_19 ;
return 0 ;
default:
F_2 ( & V_2 -> V_11 , L_68 ,
V_12 , V_31 -> V_256 ) ;
return - V_24 ;
}
}
static int F_73 ( struct V_113 * V_31 )
{
struct V_61 * V_11 = F_72 (
V_31 -> V_293 , struct V_61 , V_114 ) ;
struct V_1 * V_2 = F_19 ( & V_11 -> V_53 ) ;
int V_305 , V_306 ;
int V_49 = V_11 -> V_78 ;
switch ( V_31 -> V_256 ) {
case V_307 :
if ( V_11 -> V_139 && V_11 -> V_139 -> V_308 )
return V_11 -> V_139 -> V_308 ( & V_11 -> V_53 ,
& ( V_31 -> V_19 ) ) ;
return 0 ;
case V_309 :
V_305 = F_50 ( & V_11 -> V_53 , V_204 ,
V_11 -> V_77 [ V_49 ] . V_205 ) ;
if ( V_305 < 0 )
return V_305 ;
V_306 = F_50 ( & V_11 -> V_53 , V_310 ,
V_11 -> V_77 [ V_49 ] . V_205 ) ;
if ( V_306 < 0 )
return V_306 ;
V_31 -> V_19 = F_74 ( V_305 + ( V_306 ) ) - 2 ;
return 0 ;
case V_311 :
V_305 = F_50 ( & V_11 -> V_53 , V_207 ,
V_11 -> V_77 [ V_49 ] . V_205 ) ;
if ( V_305 < 0 )
return V_305 ;
V_306 = F_50 ( & V_11 -> V_53 , V_312 ,
V_11 -> V_77 [ V_49 ] . V_205 ) ;
if ( V_306 < 0 )
return V_306 ;
V_31 -> V_19 = F_74 ( V_305 + ( V_306 ) ) - 2 ;
return 0 ;
case V_303 :
V_31 -> V_19 = V_11 -> V_266 ;
break;
case V_304 :
V_31 -> V_19 = V_11 -> V_269 ;
break;
case V_313 :
V_31 -> V_19 = V_11 -> V_58 ;
break;
default:
F_75 ( & V_2 -> V_11 ,
L_68 , V_12 , V_31 -> V_256 ) ;
return - V_24 ;
}
return 0 ;
}
static int
F_76 ( struct V_52 * V_53 ,
struct V_314 * V_315 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
const struct V_71 * V_72 =
& V_11 -> V_77 [ V_11 -> V_78 ] ;
F_23 ( & V_11 -> V_73 ) ;
V_315 -> V_315 . V_316 = V_72 -> V_79 [ V_11 -> V_51 ] . V_44 ;
V_315 -> V_315 . V_317 = 1 ;
F_25 ( & V_11 -> V_73 ) ;
return 0 ;
}
static int F_77 ( struct V_52 * V_53 ,
struct V_314 * V_315 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
struct V_1 * V_2 = F_19 ( V_53 ) ;
const struct V_71 * V_72 =
& V_11 -> V_77 [ V_11 -> V_78 ] ;
struct V_173 * V_174 = NULL ;
unsigned int V_51 ;
int V_26 = 0 ;
int V_44 ;
V_174 = F_59 ( V_53 ) ;
if ( V_174 == NULL )
return - V_24 ;
if ( ! V_315 -> V_315 . V_317 )
V_315 -> V_315 . V_317 = 1 ;
V_44 = V_315 -> V_315 . V_316 / V_315 -> V_315 . V_317 ;
if ( ! V_11 -> V_271 ) {
V_11 -> V_44 = V_44 ;
return 0 ;
}
if ( V_44 == V_72 -> V_79 [ V_11 -> V_51 ] . V_44 )
return 0 ;
V_51 = F_17 ( V_44 , V_72 -> V_79 ) ;
if ( V_72 -> V_79 [ V_51 ] . V_205 &&
V_72 -> V_79 [ V_51 ] . V_205 != V_11 -> V_205 ) {
F_2 ( & V_2 -> V_11 ,
L_69 ) ;
return - V_318 ;
}
V_11 -> V_51 = V_51 ;
V_11 -> V_44 = V_72 -> V_79 [ V_11 -> V_51 ] . V_44 ;
V_11 -> V_80 =
V_72 -> V_79 [ V_11 -> V_51 ] . V_80 ;
V_11 -> V_81 =
V_72 -> V_79 [ V_11 -> V_51 ] . V_81 ;
V_26 = F_18 ( V_53 ,
& V_11 -> V_80 , & V_11 -> V_81 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_55 ( V_53 , V_174 , V_11 -> V_205 ) ;
if ( V_26 )
return V_26 ;
V_315 -> V_315 . V_316 = V_72 -> V_79 [ V_11 -> V_51 ] . V_44 ;
V_315 -> V_315 . V_317 = 1 ;
F_64 ( V_53 ) ;
return V_26 ;
}
static int F_78 ( struct V_52 * V_53 ,
struct V_314 * V_315 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
int V_26 ;
F_23 ( & V_11 -> V_73 ) ;
V_26 = F_77 ( V_53 , V_315 ) ;
F_25 ( & V_11 -> V_73 ) ;
return V_26 ;
}
static int F_79 ( struct V_52 * V_53 , T_3 * V_319 )
{
struct V_61 * V_11 = F_21 ( V_53 ) ;
F_23 ( & V_11 -> V_73 ) ;
* V_319 = V_11 -> V_77 [ V_11 -> V_78 ] . V_320 ;
F_25 ( & V_11 -> V_73 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = F_81 ( V_2 ) ;
struct V_61 * V_11 = F_21 ( V_53 ) ;
if ( V_11 -> V_127 -> V_285 )
V_11 -> V_127 -> V_285 () ;
F_82 ( & V_11 -> V_53 . V_321 ) ;
F_83 ( & V_11 -> V_114 ) ;
V_11 -> V_127 -> V_281 ( V_53 , 0 ) ;
F_84 ( V_53 ) ;
F_85 ( V_11 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
const struct V_322 * V_256 )
{
struct V_61 * V_11 ;
unsigned int V_49 ;
int V_26 = 0 ;
struct V_323 * V_279 ;
F_3 ( & V_2 -> V_11 , L_22 , V_12 ) ;
V_11 = F_87 ( sizeof( * V_11 ) , V_93 ) ;
if ( ! V_11 ) {
F_2 ( & V_2 -> V_11 , L_70 , V_12 ) ;
return - V_94 ;
}
F_88 ( & V_11 -> V_73 ) ;
if ( V_256 )
V_11 -> V_324 = V_256 -> V_325 ;
V_11 -> V_78 = 0 ;
V_11 -> V_273 = V_326 ;
V_11 -> V_139 = & V_274 [ V_275 ] ;
F_89 ( & ( V_11 -> V_53 ) , V_2 , & V_327 ) ;
if ( F_90 ( & V_2 -> V_11 ) ) {
V_279 = F_91 ( & V_11 -> V_53 ,
V_328 ,
V_329 ) ;
if ( ! V_279 ) {
F_2 ( & V_2 -> V_11 ,
L_71 ,
V_12 ) ;
goto V_330;
}
V_26 = F_68 ( & V_11 -> V_53 , V_2 -> V_278 , V_279 ) ;
if ( V_26 ) {
F_2 ( & V_2 -> V_11 ,
L_72 , V_12 ) ;
goto V_330;
}
V_26 = F_92 ( & V_11 -> V_53 , V_279 , V_331 ) ;
if ( V_26 ) {
F_2 ( & V_2 -> V_11 ,
L_73 , V_12 ) ;
goto V_330;
}
}
snprintf ( V_11 -> V_53 . V_332 , sizeof( V_11 -> V_53 . V_332 ) , L_74 ,
V_333 , V_11 -> V_273 ,
F_93 ( V_2 -> V_10 ) , V_2 -> V_4 ) ;
V_11 -> V_53 . V_14 |= V_334 ;
V_11 -> V_243 . V_14 = V_335 ;
V_11 -> V_239 . V_246 = V_247 ;
V_11 -> V_53 . V_321 . V_336 = & V_337 ;
V_11 -> V_53 . V_321 . V_338 = V_339 ;
V_26 = F_94 ( & V_11 -> V_114 , F_5 ( V_340 ) + 1 ) ;
if ( V_26 ) {
F_80 ( V_2 ) ;
return V_26 ;
}
V_11 -> V_140 = F_95 ( & V_11 -> V_114 ,
& V_341 , NULL ) ;
for ( V_49 = 0 ; V_49 < F_5 ( V_340 ) ; V_49 ++ )
F_95 ( & V_11 -> V_114 , & V_340 [ V_49 ] , NULL ) ;
if ( V_11 -> V_114 . error ) {
F_80 ( V_2 ) ;
return V_11 -> V_114 . error ;
}
V_11 -> V_114 . V_342 = & V_11 -> V_73 ;
V_11 -> V_53 . V_114 = & V_11 -> V_114 ;
F_96 ( & V_11 -> V_114 ) ;
V_26 = F_97 ( & V_11 -> V_53 . V_321 , 1 , & V_11 -> V_243 ) ;
if ( V_26 ) {
F_80 ( V_2 ) ;
return V_26 ;
}
return 0 ;
V_330:
F_84 ( & V_11 -> V_53 ) ;
F_85 ( V_11 ) ;
return V_26 ;
}
static T_4 int F_98 ( void )
{
return F_99 ( & V_343 ) ;
}
static T_5 void F_100 ( void )
{
F_101 ( & V_343 ) ;
}
