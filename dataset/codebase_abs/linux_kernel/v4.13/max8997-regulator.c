static inline void F_1 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 ) & 0x1 ;
int V_5 = ( ( V_2 -> V_4 ) >> 1 ) & 0x1 ;
int V_6 = ( ( V_2 -> V_4 ) >> 2 ) & 0x1 ;
F_2 ( V_2 -> V_7 [ 0 ] , V_6 ) ;
F_2 ( V_2 -> V_7 [ 1 ] , V_5 ) ;
F_2 ( V_2 -> V_7 [ 2 ] , V_3 ) ;
}
static int F_3 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
int V_11 = F_4 ( V_9 ) ;
if ( V_11 != V_12 )
goto V_13;
switch ( V_10 ) {
case 0x00 :
return 4200000 ;
case 0x01 ... 0x0E :
return 4000000 + 20000 * ( V_10 - 0x01 ) ;
case 0x0F :
return 4350000 ;
default:
return - V_14 ;
}
V_13:
return - V_14 ;
}
static int F_5 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
const struct V_15 * V_16 ;
int V_11 = F_4 ( V_9 ) ;
int V_17 ;
if ( V_11 >= F_6 ( V_18 ) ||
V_11 < 0 )
return - V_14 ;
V_16 = V_18 [ V_11 ] ;
if ( V_16 == NULL )
return - V_14 ;
V_17 = V_16 -> V_19 + V_16 -> V_20 * V_10 ;
if ( V_17 > V_16 -> V_21 )
return - V_14 ;
return V_17 ;
}
static int F_7 ( struct V_8 * V_9 ,
int * V_22 , int * V_23 , int * V_24 )
{
int V_11 = F_4 ( V_9 ) ;
switch ( V_11 ) {
case V_25 ... V_26 :
* V_22 = V_27 + ( V_11 - V_25 ) ;
* V_23 = 0xC0 ;
* V_24 = 0xC0 ;
break;
case V_28 :
* V_22 = V_29 ;
* V_23 = 0x01 ;
* V_24 = 0x01 ;
break;
case V_30 :
* V_22 = V_31 ;
* V_23 = 0x01 ;
* V_24 = 0x01 ;
break;
case V_32 :
* V_22 = V_33 ;
* V_23 = 0x01 ;
* V_24 = 0x01 ;
break;
case V_34 :
* V_22 = V_35 ;
* V_23 = 0x01 ;
* V_24 = 0x01 ;
break;
case V_36 :
* V_22 = V_37 ;
* V_23 = 0x01 ;
* V_24 = 0x01 ;
break;
case V_38 :
* V_22 = V_39 ;
* V_23 = 0x01 ;
* V_24 = 0x01 ;
break;
case V_40 :
* V_22 = V_41 ;
* V_23 = 0x01 ;
* V_24 = 0x01 ;
break;
case V_42 ... V_43 :
* V_22 = V_44 ;
* V_23 = 0x01 << ( V_11 - V_42 ) ;
* V_24 = 0x01 << ( V_11 - V_42 ) ;
break;
case V_45 :
* V_22 = V_46 ;
* V_23 = 0x80 ;
* V_24 = 0x80 ;
break;
case V_47 ... V_48 :
* V_22 = V_49 ;
* V_23 = 0x40 << ( V_11 - V_47 ) ;
* V_24 = 0x40 << ( V_11 - V_47 ) ;
break;
case V_50 :
* V_22 = V_51 ;
* V_23 = 0x40 ;
* V_24 = 0x40 ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_52 * V_53 = V_2 -> V_54 -> V_53 ;
int V_55 , V_22 , V_23 , V_24 ;
T_1 V_17 ;
V_55 = F_7 ( V_9 , & V_22 , & V_23 , & V_24 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_10 ( V_53 , V_22 , & V_17 ) ;
if ( V_55 )
return V_55 ;
return ( V_17 & V_23 ) == V_24 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_52 * V_53 = V_2 -> V_54 -> V_53 ;
int V_55 , V_22 , V_23 , V_24 ;
V_55 = F_7 ( V_9 , & V_22 , & V_23 , & V_24 ) ;
if ( V_55 )
return V_55 ;
return F_12 ( V_53 , V_22 , V_24 , V_23 ) ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_52 * V_53 = V_2 -> V_54 -> V_53 ;
int V_55 , V_22 , V_23 , V_24 ;
V_55 = F_7 ( V_9 , & V_22 , & V_23 , & V_24 ) ;
if ( V_55 )
return V_55 ;
return F_12 ( V_53 , V_22 , ~ V_24 , V_23 ) ;
}
static int F_14 ( struct V_8 * V_9 ,
int * V_56 , int * V_57 , int * V_58 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_11 = F_4 ( V_9 ) ;
int V_22 , V_59 = 0 , V_23 = 0x3f ;
switch ( V_11 ) {
case V_25 ... V_26 :
V_22 = V_27 + ( V_11 - V_25 ) ;
break;
case V_28 :
V_22 = V_60 ;
if ( V_2 -> V_61 )
V_22 += V_2 -> V_4 ;
break;
case V_30 :
V_22 = V_62 ;
if ( V_2 -> V_63 )
V_22 += V_2 -> V_4 ;
break;
case V_32 :
V_22 = V_64 ;
break;
case V_34 :
V_22 = V_65 ;
break;
case V_36 :
V_22 = V_66 ;
if ( V_2 -> V_67 )
V_22 += V_2 -> V_4 ;
break;
case V_40 :
V_22 = V_68 ;
break;
case V_47 ... V_48 :
V_22 = V_49 ;
V_59 = ( V_11 == V_48 ) ? 2 : 0 ;
V_23 = 0x3 ;
break;
case V_12 :
V_22 = V_69 ;
V_59 = 0 ;
V_23 = 0xf ;
break;
case V_50 :
V_22 = V_70 ;
V_59 = 0 ;
V_23 = 0xf ;
break;
case V_71 :
V_22 = V_72 ;
V_59 = 0 ;
V_23 = 0xf ;
break;
default:
return - V_14 ;
}
* V_56 = V_22 ;
* V_57 = V_59 ;
* V_58 = V_23 ;
return 0 ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_52 * V_53 = V_2 -> V_54 -> V_53 ;
int V_22 , V_59 , V_23 , V_55 ;
T_1 V_17 ;
V_55 = F_14 ( V_9 , & V_22 , & V_59 , & V_23 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_10 ( V_53 , V_22 , & V_17 ) ;
if ( V_55 )
return V_55 ;
V_17 >>= V_59 ;
V_17 &= V_23 ;
return V_17 ;
}
static inline int F_16 (
const struct V_15 * V_16 ,
int V_73 , int V_74 )
{
int V_75 ;
if ( V_16 == NULL )
return - V_14 ;
if ( V_74 < V_16 -> V_19 || V_73 > V_16 -> V_21 )
return - V_14 ;
if ( V_73 < V_16 -> V_19 )
V_73 = V_16 -> V_19 ;
V_75 = F_17 ( V_73 - V_16 -> V_19 , V_16 -> V_20 ) ;
if ( V_16 -> V_19 + V_16 -> V_20 * V_75 > V_74 )
return - V_14 ;
return V_75 ;
}
static int F_18 ( struct V_8 * V_9 ,
int V_76 , int V_77 , unsigned * V_10 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_52 * V_53 = V_2 -> V_54 -> V_53 ;
int V_11 = F_4 ( V_9 ) ;
int V_78 , V_79 ;
int V_22 , V_59 = 0 , V_23 , V_55 = 0 ;
T_1 V_17 = 0x0 ;
if ( V_11 != V_12 )
return - V_14 ;
V_55 = F_14 ( V_9 , & V_22 , & V_59 , & V_23 ) ;
if ( V_55 )
return V_55 ;
if ( V_77 < 4000000 || V_76 > 4350000 )
return - V_14 ;
if ( V_76 <= 4000000 )
V_17 = 0x1 ;
else if ( V_76 <= 4200000 && V_77 >= 4200000 )
V_17 = 0x0 ;
else {
V_78 = ( V_76 - 4000001 ) / 20000 + 2 ;
V_79 = ( V_77 - 4000000 ) / 20000 + 1 ;
if ( V_78 > V_79 )
return - V_14 ;
if ( V_78 < 0xf )
V_17 = V_78 ;
else {
if ( V_79 >= 0xf )
V_17 = 0xf ;
else
return - V_14 ;
}
}
* V_10 = V_17 ;
V_55 = F_12 ( V_53 , V_22 , V_17 << V_59 , V_23 ) ;
return V_55 ;
}
static int F_19 ( struct V_8 * V_9 ,
int V_76 , int V_77 , unsigned * V_10 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_52 * V_53 = V_2 -> V_54 -> V_53 ;
const struct V_15 * V_16 ;
int V_11 = F_4 ( V_9 ) ;
int V_75 , V_22 , V_59 , V_23 , V_55 ;
switch ( V_11 ) {
case V_25 ... V_26 :
break;
case V_28 ... V_36 :
break;
case V_38 :
return - V_14 ;
case V_40 :
break;
case V_50 :
break;
case V_71 :
break;
default:
return - V_14 ;
}
V_16 = V_18 [ V_11 ] ;
V_75 = F_16 ( V_16 , V_76 , V_77 ) ;
if ( V_75 < 0 )
return V_75 ;
V_55 = F_14 ( V_9 , & V_22 , & V_59 , & V_23 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_12 ( V_53 , V_22 , V_75 << V_59 , V_23 << V_59 ) ;
* V_10 = V_75 ;
return V_55 ;
}
static int F_20 ( struct V_8 * V_9 ,
unsigned int V_80 ,
unsigned int V_81 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_11 = F_4 ( V_9 ) ;
const struct V_15 * V_16 = V_18 [ V_11 ] ;
if ( V_80 >= V_81 )
return 0 ;
switch ( V_11 ) {
case V_28 :
if ( V_2 -> V_61 )
return 0 ;
break;
case V_30 :
if ( V_2 -> V_63 )
return 0 ;
break;
case V_36 :
if ( V_2 -> V_67 )
return 0 ;
break;
}
switch ( V_11 ) {
case V_28 :
case V_30 :
case V_34 :
case V_36 :
return F_17 ( V_16 -> V_20 * ( V_81 - V_80 ) ,
V_2 -> V_82 * 1000 ) ;
}
return 0 ;
}
static int F_21 ( struct V_8 * V_9 ,
T_1 V_83 , int * V_84 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_11 = F_4 ( V_9 ) ;
T_1 * V_85 [ 3 ] ;
bool V_86 [ 3 ] ;
int V_87 [ 8 ] ;
int V_88 = V_89 ;
int V_75 ;
* V_84 = - 1 ;
switch ( V_11 ) {
case V_28 :
V_11 = 0 ;
break;
case V_30 :
V_11 = 1 ;
break;
case V_36 :
V_11 = 2 ;
break;
default:
return - V_14 ;
}
V_85 [ 0 ] = V_2 -> V_90 ;
V_85 [ 1 ] = V_2 -> V_91 ;
V_85 [ 2 ] = V_2 -> V_92 ;
V_86 [ 0 ] = V_2 -> V_61 ;
V_86 [ 1 ] = V_2 -> V_63 ;
V_86 [ 2 ] = V_2 -> V_67 ;
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ ) {
int V_93 ;
if ( V_83 != ( V_85 [ V_11 ] ) [ V_75 ] ) {
V_87 [ V_75 ] = - 1 ;
continue;
}
V_87 [ V_75 ] = 0 ;
for ( V_93 = 0 ; V_93 < 3 ; V_93 ++ ) {
int V_94 ;
if ( V_93 == V_11 )
continue;
if ( V_86 [ V_93 ] == false )
continue;
V_94 = ( V_85 [ V_93 ] ) [ V_75 ] -
( V_85 [ V_93 ] ) [ V_2 -> V_4 ] ;
if ( V_94 > 0 )
V_87 [ V_75 ] += V_94 ;
else if ( V_94 < 0 )
V_87 [ V_75 ] -= V_94 ;
}
if ( V_87 [ V_75 ] == 0 ) {
* V_84 = V_75 ;
return 0 ;
}
if ( V_87 [ V_75 ] < V_88 ) {
V_88 = V_87 [ V_75 ] ;
* V_84 = V_75 ;
}
}
if ( * V_84 == - 1 )
return - V_14 ;
return V_87 [ * V_84 ] ;
}
static int F_22 ( struct V_8 * V_9 ,
int V_76 , int V_77 , unsigned * V_10 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_11 = F_4 ( V_9 ) ;
const struct V_15 * V_16 ;
int V_83 , V_95 , V_96 , V_97 , V_98 , V_99 ;
bool V_100 = false ;
if ( V_11 < V_28 || V_11 > V_40 )
return - V_14 ;
switch ( V_11 ) {
case V_28 :
if ( V_2 -> V_61 )
V_100 = true ;
break;
case V_30 :
if ( V_2 -> V_63 )
V_100 = true ;
break;
case V_36 :
if ( V_2 -> V_67 )
V_100 = true ;
break;
}
if ( ! V_100 )
return F_19 ( V_9 , V_76 , V_77 ,
V_10 ) ;
V_16 = V_18 [ V_11 ] ;
V_83 = F_16 ( V_16 , V_76 , V_77 ) ;
if ( V_83 < 0 )
return V_83 ;
V_99 = V_89 ;
V_98 = - 1 ;
V_97 = - 1 ;
do {
V_96 = F_21 ( V_9 , V_83 , & V_95 ) ;
if ( V_96 == 0 )
goto V_101;
if ( V_99 > V_96 ) {
V_98 = V_95 ;
V_97 = V_83 ;
V_99 = V_96 ;
}
V_83 ++ ;
} while ( V_16 -> V_19 + V_16 -> V_20 * V_83 <= V_16 -> V_21 );
V_95 = V_98 ;
V_83 = V_97 ;
if ( V_2 -> V_102 == false )
return - V_14 ;
F_23 ( & V_9 -> V_103 ,
L_1 ,
V_2 -> V_4 , V_98 ) ;
V_101:
if ( V_95 < 0 || V_83 < 0 )
return - V_14 ;
V_2 -> V_4 = V_95 ;
F_1 ( V_2 ) ;
* V_10 = V_83 ;
return 0 ;
}
static int F_24 ( struct V_8 * V_9 ,
unsigned V_10 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_52 * V_53 = V_2 -> V_54 -> V_53 ;
int V_11 = F_4 ( V_9 ) ;
int V_22 , V_59 = 0 , V_23 , V_55 ;
if ( V_11 != V_47 && V_11 != V_48 )
return - V_14 ;
V_55 = F_14 ( V_9 , & V_22 , & V_59 , & V_23 ) ;
if ( V_55 )
return V_55 ;
return F_12 ( V_53 , V_22 , V_10 << V_59 , V_23 << V_59 ) ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_52 * V_53 = V_2 -> V_54 -> V_53 ;
int V_55 , V_22 , V_23 , V_24 ;
int V_11 = F_4 ( V_9 ) ;
V_55 = F_7 ( V_9 , & V_22 , & V_23 , & V_24 ) ;
if ( V_55 )
return V_55 ;
F_10 ( V_53 , V_22 , & V_2 -> V_104 [ V_11 ] ) ;
if ( V_11 == V_25 ||
V_11 == V_105 ||
V_11 == V_26 ) {
F_26 ( & V_9 -> V_103 , L_2 ,
V_9 -> V_16 -> V_106 ) ;
return F_12 ( V_53 , V_22 , 0x40 , V_23 ) ;
}
F_26 ( & V_9 -> V_103 , L_3 ,
V_9 -> V_16 -> V_106 , V_2 -> V_104 [ V_11 ] & V_23 ,
( ~ V_24 ) & V_23 ) ;
return F_12 ( V_53 , V_22 , ~ V_24 , V_23 ) ;
}
static int F_27 ( struct V_8 * V_9 ,
int V_107 , int V_108 )
{
unsigned V_109 ;
int V_11 = F_4 ( V_9 ) ;
if ( V_11 != V_50 && V_11 != V_71 )
return - V_14 ;
return F_19 ( V_9 , V_107 , V_108 , & V_109 ) ;
}
static int F_28 ( struct V_8 * V_9 )
{
int V_110 , V_11 = F_4 ( V_9 ) ;
if ( V_11 != V_50 && V_11 != V_71 )
return - V_14 ;
V_110 = F_15 ( V_9 ) ;
if ( V_110 < 0 )
return V_110 ;
return F_5 ( V_9 , V_110 ) ;
}
static int F_29 ( struct V_111 * V_112 ,
struct V_113 * V_114 ,
struct V_115 * V_116 )
{
int V_75 , V_117 ;
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
V_117 = F_30 ( V_116 ,
L_4 , V_75 ) ;
if ( ! F_31 ( V_117 ) ) {
F_32 ( & V_112 -> V_103 , L_5 , V_75 , V_117 ) ;
return - V_14 ;
}
V_114 -> V_7 [ V_75 ] = V_117 ;
}
return 0 ;
}
static int F_33 ( struct V_111 * V_112 ,
struct V_113 * V_114 )
{
struct V_118 * V_54 = F_34 ( V_112 -> V_103 . V_119 ) ;
struct V_115 * V_116 , * V_120 , * V_121 ;
struct V_122 * V_123 ;
unsigned int V_75 , V_124 = 1 , V_55 ;
V_116 = V_54 -> V_103 -> V_125 ;
if ( ! V_116 ) {
F_32 ( & V_112 -> V_103 , L_6 ) ;
return - V_126 ;
}
V_120 = F_35 ( V_116 , L_7 ) ;
if ( ! V_120 ) {
F_32 ( & V_112 -> V_103 , L_8 ) ;
return - V_14 ;
}
V_114 -> V_127 = F_36 ( V_120 ) ;
V_123 = F_37 ( & V_112 -> V_103 , sizeof( * V_123 ) *
V_114 -> V_127 , V_128 ) ;
if ( ! V_123 ) {
F_38 ( V_120 ) ;
return - V_129 ;
}
V_114 -> V_130 = V_123 ;
F_39 (regulators_np, reg_np) {
for ( V_75 = 0 ; V_75 < F_6 ( V_130 ) ; V_75 ++ )
if ( ! F_40 ( V_121 -> V_106 , V_130 [ V_75 ] . V_106 ) )
break;
if ( V_75 == F_6 ( V_130 ) ) {
F_23 ( & V_112 -> V_103 , L_9 ,
V_121 -> V_106 ) ;
continue;
}
V_123 -> V_131 = V_75 ;
V_123 -> V_132 = F_41 ( & V_112 -> V_103 ,
V_121 ,
& V_130 [ V_75 ] ) ;
V_123 -> V_133 = V_121 ;
V_123 ++ ;
}
F_38 ( V_120 ) ;
if ( F_42 ( V_116 , L_10 , NULL ) )
V_114 -> V_61 = true ;
if ( F_42 ( V_116 , L_11 , NULL ) )
V_114 -> V_63 = true ;
if ( F_42 ( V_116 , L_12 , NULL ) )
V_114 -> V_67 = true ;
if ( V_114 -> V_61 || V_114 -> V_63 ||
V_114 -> V_67 ) {
V_55 = F_29 ( V_112 , V_114 , V_116 ) ;
if ( V_55 )
return - V_14 ;
if ( F_43 ( V_116 ,
L_13 ,
& V_114 -> V_134 ) ) {
V_114 -> V_134 = 0 ;
} else {
if ( V_114 -> V_134 >= 8 ) {
V_114 -> V_134 = 0 ;
F_44 ( & V_112 -> V_103 , L_14 ) ;
}
}
if ( F_42 ( V_116 ,
L_15 , NULL ) )
V_114 -> V_102 = true ;
V_124 = 8 ;
}
if ( F_45 ( V_116 ,
L_16 ,
V_114 -> V_135 , V_124 ) ) {
F_32 ( & V_112 -> V_103 , L_17 ) ;
return - V_14 ;
}
if ( F_45 ( V_116 ,
L_18 ,
V_114 -> V_136 , V_124 ) ) {
F_32 ( & V_112 -> V_103 , L_19 ) ;
return - V_14 ;
}
if ( F_45 ( V_116 ,
L_20 ,
V_114 -> V_137 , V_124 ) ) {
F_32 ( & V_112 -> V_103 , L_21 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_33 ( struct V_111 * V_112 ,
struct V_113 * V_114 )
{
return 0 ;
}
static int F_46 ( struct V_111 * V_112 )
{
struct V_118 * V_54 = F_34 ( V_112 -> V_103 . V_119 ) ;
struct V_113 * V_114 = V_54 -> V_114 ;
struct V_138 V_139 = { } ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_52 * V_53 ;
int V_75 , V_55 , V_140 ;
T_1 V_141 = 0 , V_142 = 0 , V_143 = 0 ;
if ( ! V_114 ) {
F_32 ( & V_112 -> V_103 , L_22 ) ;
return - V_126 ;
}
if ( V_54 -> V_103 -> V_125 ) {
V_55 = F_33 ( V_112 , V_114 ) ;
if ( V_55 )
return V_55 ;
}
V_2 = F_37 ( & V_112 -> V_103 , sizeof( struct V_1 ) ,
V_128 ) ;
if ( ! V_2 )
return - V_129 ;
V_2 -> V_103 = & V_112 -> V_103 ;
V_2 -> V_54 = V_54 ;
V_2 -> V_127 = V_114 -> V_127 ;
F_47 ( V_112 , V_2 ) ;
V_53 = V_2 -> V_54 -> V_53 ;
V_2 -> V_4 = V_114 -> V_134 ;
V_2 -> V_61 = V_114 -> V_61 ;
V_2 -> V_63 = V_114 -> V_63 ;
V_2 -> V_67 = V_114 -> V_67 ;
memcpy ( V_2 -> V_7 , V_114 -> V_7 , sizeof( int ) * 3 ) ;
V_2 -> V_102 = V_114 -> V_102 ;
V_140 = ( V_114 -> V_61 || V_114 -> V_63 ||
V_114 -> V_67 ) ? 8 : 1 ;
for ( V_75 = 0 ; V_75 < V_140 ; V_75 ++ ) {
V_2 -> V_90 [ V_75 ] = V_55 =
F_16 (
& V_144 ,
V_114 -> V_135 [ V_75 ] ,
V_114 -> V_135 [ V_75 ] +
V_144 . V_20 ) ;
if ( V_55 < 0 )
return V_55 ;
V_2 -> V_91 [ V_75 ] = V_55 =
F_16 (
& V_144 ,
V_114 -> V_136 [ V_75 ] ,
V_114 -> V_136 [ V_75 ] +
V_144 . V_20 ) ;
if ( V_55 < 0 )
return V_55 ;
V_2 -> V_92 [ V_75 ] = V_55 =
F_16 (
& V_144 ,
V_114 -> V_137 [ V_75 ] ,
V_114 -> V_137 [ V_75 ] +
V_144 . V_20 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_141 < V_2 -> V_90 [ V_75 ] )
V_141 = V_2 -> V_90 [ V_75 ] ;
if ( V_142 < V_2 -> V_91 [ V_75 ] )
V_142 = V_2 -> V_91 [ V_75 ] ;
if ( V_143 < V_2 -> V_92 [ V_75 ] )
V_143 = V_2 -> V_92 [ V_75 ] ;
}
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ ) {
F_12 ( V_53 , V_60 + V_75 ,
V_141 , 0x3f ) ;
F_12 ( V_53 , V_62 + V_75 ,
V_142 , 0x3f ) ;
F_12 ( V_53 , V_66 + V_75 ,
V_143 , 0x3f ) ;
}
for ( V_75 = 0 ; V_75 < V_140 ; V_75 ++ ) {
F_12 ( V_53 , V_60 + V_75 ,
V_2 -> V_90 [ V_75 ] ,
0x3f ) ;
F_12 ( V_53 , V_62 + V_75 ,
V_2 -> V_91 [ V_75 ] ,
0x3f ) ;
F_12 ( V_53 , V_66 + V_75 ,
V_2 -> V_92 [ V_75 ] ,
0x3f ) ;
}
if ( V_114 -> V_61 || V_114 -> V_63 ||
V_114 -> V_67 ) {
if ( ! F_31 ( V_114 -> V_7 [ 0 ] ) ||
! F_31 ( V_114 -> V_7 [ 1 ] ) ||
! F_31 ( V_114 -> V_7 [ 2 ] ) ) {
F_32 ( & V_112 -> V_103 , L_23 ) ;
return - V_14 ;
}
V_55 = F_48 ( & V_112 -> V_103 , V_114 -> V_7 [ 0 ] ,
L_24 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_48 ( & V_112 -> V_103 , V_114 -> V_7 [ 1 ] ,
L_25 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_48 ( & V_112 -> V_103 , V_114 -> V_7 [ 2 ] ,
L_26 ) ;
if ( V_55 )
return V_55 ;
F_49 ( V_114 -> V_7 [ 0 ] ,
( V_2 -> V_4 >> 2 )
& 0x1 ) ;
F_49 ( V_114 -> V_7 [ 1 ] ,
( V_2 -> V_4 >> 1 )
& 0x1 ) ;
F_49 ( V_114 -> V_7 [ 2 ] ,
( V_2 -> V_4 >> 0 )
& 0x1 ) ;
}
F_12 ( V_53 , V_29 , ( V_114 -> V_61 ) ?
( 1 << 1 ) : ( 0 << 1 ) , 1 << 1 ) ;
F_12 ( V_53 , V_31 , ( V_114 -> V_63 ) ?
( 1 << 1 ) : ( 0 << 1 ) , 1 << 1 ) ;
F_12 ( V_53 , V_37 , ( V_114 -> V_67 ) ?
( 1 << 1 ) : ( 0 << 1 ) , 1 << 1 ) ;
V_2 -> V_82 = 10 ;
F_50 ( V_53 , V_145 , ( 0xf << 4 ) | 0x9 ) ;
for ( V_75 = 0 ; V_75 < V_114 -> V_127 ; V_75 ++ ) {
const struct V_15 * V_16 ;
int V_131 = V_114 -> V_130 [ V_75 ] . V_131 ;
V_16 = V_18 [ V_131 ] ;
if ( V_16 ) {
V_130 [ V_131 ] . V_146 =
( V_16 -> V_21 - V_16 -> V_19 ) / V_16 -> V_20 + 1 ;
} else if ( V_131 == V_47 || V_131 == V_48 ) {
V_130 [ V_131 ] . V_147 = V_148 ;
V_130 [ V_131 ] . V_146 = F_6 ( V_148 ) ;
} else if ( V_131 == V_12 ) {
V_130 [ V_131 ] . V_146 = 16 ;
}
V_139 . V_103 = V_2 -> V_103 ;
V_139 . V_149 = V_114 -> V_130 [ V_75 ] . V_132 ;
V_139 . V_150 = V_2 ;
V_139 . V_125 = V_114 -> V_130 [ V_75 ] . V_133 ;
V_9 = F_51 ( & V_112 -> V_103 , & V_130 [ V_131 ] ,
& V_139 ) ;
if ( F_52 ( V_9 ) ) {
F_32 ( V_2 -> V_103 , L_27 ,
V_131 ) ;
return F_53 ( V_9 ) ;
}
}
return 0 ;
}
static int T_2 F_54 ( void )
{
return F_55 ( & V_151 ) ;
}
static void T_3 F_56 ( void )
{
F_57 ( & V_151 ) ;
}
