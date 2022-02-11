static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_2 ( V_4 , V_5 ,
F_3 ( V_5 ) ) ;
F_4 ( V_4 , V_6 , F_3 ( V_6 ) ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 , unsigned int V_9 , unsigned int V_10 )
{
T_1 V_11 ;
unsigned int V_12 , V_13 , V_14 ;
V_13 = V_9 / V_10 ;
if ( V_13 < 6 ) {
V_10 >>= 1 ;
V_8 -> V_15 = 1 ;
V_13 = V_9 / V_10 ;
} else {
V_8 -> V_15 = 0 ;
}
if ( V_13 < 6 || V_13 > 12 )
F_6 ( V_2 -> V_16 ,
L_1 ,
V_13 ) ;
V_8 -> V_17 = V_13 ;
V_14 = V_9 - V_10 * V_13 ;
V_11 = V_18 * ( long long ) V_14 + V_10 / 2 ;
F_7 ( V_11 , V_10 ) ;
V_12 = V_11 & 0xFFFFFFFF ;
V_8 -> V_12 = V_12 ;
}
static int F_8 ( unsigned int V_19 , unsigned int V_20 ,
unsigned int * V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < F_3 ( V_23 ) ; V_22 ++ ) {
unsigned int V_24 = 4 * V_19 * V_23 [ V_22 ] /
V_25 [ V_22 ] ;
if ( 3 * V_20 <= V_24 && V_24 < 13 * V_20 ) {
* V_21 = V_24 / 4 ;
return V_22 ;
}
}
return - V_26 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_10 ( V_2 ) ;
struct V_7 V_8 ;
unsigned int V_29 = V_28 -> V_29 , V_20 = V_28 -> V_20 ,
V_30 = V_28 -> V_30 ;
unsigned int V_31 ;
if ( ! V_20 )
return - V_26 ;
if ( V_29 ) {
unsigned int V_32 ;
V_28 -> V_33 = - 1 ;
if ( 16 * V_29 < 3 * V_20 || 4 * V_29 >= 13 * V_20 )
return - V_26 ;
if ( 4 * V_29 < 3 * V_20 )
V_32 = ( 3 * V_20 / 4 + V_29 - 1 ) / V_29 ;
else
V_32 = 1 ;
F_11 ( V_2 -> V_16 , L_2 , V_34 , V_32 ) ;
F_12 ( V_2 , V_35 , 0x30 ,
( V_32 - 1 ) << 4 ) ;
V_28 -> V_21 = V_29 * V_32 ;
} else if ( V_30 ) {
int V_36 = F_8 ( V_30 , V_20 , & V_28 -> V_21 ) ;
if ( V_36 < 0 )
return V_36 ;
V_28 -> V_33 = V_36 ;
F_12 ( V_2 , V_35 , 7 , 0 ) ;
} else {
return - V_26 ;
}
V_31 = V_28 -> V_21 * 4 ;
F_11 ( V_2 -> V_16 , L_3 , V_34 ,
V_28 -> V_20 , V_28 -> V_21 ) ;
F_5 ( V_2 , & V_8 , V_31 , V_28 -> V_20 ) ;
F_11 ( V_2 -> V_16 , L_4 ,
V_34 , V_8 . V_17 , V_8 . V_12 , V_8 . V_15 ) ;
F_12 ( V_2 , V_37 , 0x20 , 0 ) ;
F_13 ( V_2 , V_38 , ( V_8 . V_15 << 4 ) | V_8 . V_17 ) ;
F_13 ( V_2 , V_39 , V_8 . V_12 >> 18 ) ;
F_13 ( V_2 , V_40 , ( V_8 . V_12 >> 9 ) & 0x1ff ) ;
F_13 ( V_2 , V_41 , V_8 . V_12 & 0x1ff ) ;
F_12 ( V_2 , V_37 , 0x20 , 0x20 ) ;
if ( V_29 )
F_12 ( V_2 , V_35 , 7 , 4 ) ;
return 0 ;
}
static int F_14 ( struct V_42 * V_43 ,
int V_44 , int div )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_27 * V_28 = F_10 ( V_2 ) ;
int V_45 = 0 ;
switch ( V_44 ) {
case V_46 :
V_28 -> V_29 = div ;
if ( V_28 -> V_20 )
V_45 = F_9 ( V_2 ) ;
break;
case V_47 :
if ( div & ~ 0x1c )
return - V_26 ;
F_12 ( V_2 , V_48 , 0x1c , div ) ;
break;
default:
return - V_26 ;
}
F_11 ( V_2 -> V_16 , L_5 , V_34 , V_44 , div ) ;
return V_45 ;
}
static int F_15 ( struct V_42 * V_43 , int V_49 ,
unsigned int V_50 , int V_51 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_27 * V_28 = F_10 ( V_2 ) ;
int V_45 = 0 ;
F_11 ( V_2 -> V_16 , L_6 , V_34 , V_49 , V_50 ) ;
if ( V_50 ) {
V_28 -> V_20 = V_50 ;
if ( V_28 -> V_29 )
V_45 = F_9 ( V_2 ) ;
if ( ! V_45 )
V_28 -> V_52 = V_49 ;
}
if ( V_28 -> V_52 == V_53 && ( ! V_50 || V_49 == V_54 ) ) {
F_12 ( V_2 , V_48 , 0x100 , 0 ) ;
F_12 ( V_2 , V_35 , 7 , 0 ) ;
F_12 ( V_2 , V_37 , 0x20 , 0 ) ;
V_28 -> V_52 = V_54 ;
V_28 -> V_21 = 0 ;
V_28 -> V_29 = 0 ;
}
return V_45 ;
}
static int F_16 ( struct V_42 * V_43 , unsigned int V_55 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
T_2 V_56 = F_17 ( V_2 , V_57 ) & ~ 0x198 ;
T_2 V_58 = F_17 ( V_2 , V_48 ) ;
F_11 ( V_2 -> V_16 , L_7 , V_34 ) ;
switch ( V_55 & V_59 ) {
case V_60 :
V_58 |= 1 ;
break;
case V_61 :
V_58 &= ~ 1 ;
break;
default:
return - V_26 ;
}
switch ( V_55 & V_62 ) {
case V_63 :
V_56 |= 0x10 ;
break;
case V_64 :
break;
case V_65 :
V_56 |= 0x8 ;
break;
case V_66 :
V_56 |= 0x18 ;
break;
default:
return - V_26 ;
}
switch ( V_55 & V_67 ) {
case V_68 :
break;
case V_69 :
V_56 |= 0x180 ;
break;
case V_70 :
V_56 |= 0x100 ;
break;
case V_71 :
V_56 |= 0x80 ;
break;
default:
return - V_26 ;
}
F_13 ( V_2 , V_57 , V_56 ) ;
F_13 ( V_2 , V_48 , V_58 ) ;
return 0 ;
}
static int F_18 ( struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_42 * V_76 )
{
struct V_77 * V_78 = V_73 -> V_79 ;
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_27 * V_28 = F_10 ( V_2 ) ;
T_2 V_80 = F_17 ( V_2 , V_57 ) & ~ 0x60 ;
T_2 V_81 = F_17 ( V_2 , V_82 ) & ~ 0xe ;
T_2 V_83 = F_17 ( V_2 , V_48 ) ;
enum V_84 V_85 = V_83 & 0x100 ?
V_53 : V_54 ;
unsigned int V_86 , V_87 , V_88 = V_89 ;
int V_22 , V_90 = 0 ;
if ( ! V_28 -> V_20 )
return - V_26 ;
switch ( F_19 ( V_75 ) ) {
case V_91 :
break;
case V_92 :
V_80 |= 0x20 ;
break;
case V_93 :
V_80 |= 0x40 ;
break;
case V_94 :
V_80 |= 0x60 ;
break;
}
switch ( F_20 ( V_75 ) ) {
case 8000 :
V_81 |= 0x5 << 1 ;
break;
case 11025 :
V_81 |= 0x4 << 1 ;
break;
case 16000 :
V_81 |= 0x3 << 1 ;
break;
case 22050 :
V_81 |= 0x2 << 1 ;
break;
case 32000 :
V_81 |= 0x1 << 1 ;
break;
case 44100 :
case 48000 :
break;
}
V_28 -> V_30 = F_20 ( V_75 ) * 256 ;
if ( V_28 -> V_52 == V_54 ) {
V_28 -> V_33 = - 1 ;
V_86 = V_28 -> V_20 ;
} else {
if ( ! V_28 -> V_21 ) {
int V_45 = F_9 ( V_2 ) ;
if ( V_45 < 0 )
return V_45 ;
}
V_86 = V_28 -> V_21 ;
}
if ( V_28 -> V_33 < 0 ) {
if ( V_86 < V_28 -> V_30 || V_86 > 12 * V_28 -> V_30 )
return - V_26 ;
for ( V_22 = 0 ; V_22 < F_3 ( V_23 ) ; V_22 ++ ) {
V_87 = abs ( V_28 -> V_30 * 3 -
V_86 * 3 * V_25 [ V_22 ] / V_23 [ V_22 ] ) ;
if ( V_87 < V_88 ) {
V_88 = V_87 ;
V_90 = V_22 ;
}
if ( ! V_87 )
break;
}
} else {
V_90 = V_28 -> V_33 ;
V_87 = 0 ;
}
if ( V_87 )
F_6 ( V_2 -> V_16 , L_8 ,
V_86 * V_25 [ V_90 ] / V_23 [ V_90 ] / 256 ,
V_28 -> V_52 == V_54 ?
L_9 : L_10 ) ;
F_11 ( V_2 -> V_16 , L_11 , V_34 ,
F_19 ( V_75 ) , F_20 ( V_75 ) , V_90 ) ;
F_12 ( V_2 , V_48 , 0xe0 , V_90 << 5 ) ;
F_13 ( V_2 , V_57 , V_80 ) ;
F_13 ( V_2 , V_82 , V_81 ) ;
if ( V_28 -> V_52 != V_85 ) {
if ( V_28 -> V_52 == V_53 )
F_12 ( V_2 , V_48 ,
0x100 , 0x100 ) ;
else
F_12 ( V_2 , V_48 , 0x100 , 0 ) ;
}
return 0 ;
}
static int F_21 ( struct V_42 * V_76 , int V_95 )
{
struct V_1 * V_2 = V_76 -> V_2 ;
F_11 ( V_2 -> V_16 , L_12 , V_34 , V_95 ) ;
if ( V_95 )
F_12 ( V_2 , V_96 , 0x40 , 0x40 ) ;
else
F_12 ( V_2 , V_96 , 0x40 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
enum V_97 V_98 )
{
T_2 V_99 = F_17 ( V_2 , V_37 ) & ~ 3 ;
switch ( V_98 ) {
case V_100 :
case V_101 :
V_99 |= 1 ;
F_13 ( V_2 , V_37 , V_99 ) ;
break;
case V_102 :
V_99 |= 0xc ;
if ( V_2 -> V_4 . V_103 == V_104 ) {
F_13 ( V_2 , V_37 ,
V_99 | 0x3 ) ;
F_23 ( 100 ) ;
}
V_99 |= 0x2 ;
F_13 ( V_2 , V_37 , V_99 ) ;
break;
case V_104 :
F_12 ( V_2 , V_37 , ~ 0x20 , 0 ) ;
F_13 ( V_2 , V_105 , 0 ) ;
F_13 ( V_2 , V_106 , 0 ) ;
break;
}
F_11 ( V_2 -> V_16 , L_13 , V_34 , V_98 , V_99 ) ;
V_2 -> V_4 . V_103 = V_98 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_104 ) ;
F_13 ( V_2 , V_37 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_10 ( V_2 ) ;
int V_22 ;
T_2 * V_107 = V_2 -> V_108 ;
for ( V_22 = 0 ; V_22 < F_3 ( V_109 ) ; V_22 ++ ) {
if ( V_22 == V_110 )
continue;
if ( V_107 [ V_22 ] != V_109 [ V_22 ] )
F_13 ( V_2 , V_22 , V_107 [ V_22 ] ) ;
}
F_22 ( V_2 , V_102 ) ;
if ( V_28 -> V_21 )
F_12 ( V_2 , V_37 , 0x20 , 0x20 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_10 ( V_2 ) ;
int V_45 = 0 , V_22 ;
V_28 -> V_52 = V_53 ;
V_45 = F_27 ( V_2 , 7 , 9 , V_111 ) ;
if ( V_45 < 0 ) {
F_28 ( V_2 -> V_16 , L_14 , V_45 ) ;
return V_45 ;
}
for ( V_22 = 0 ; V_22 < F_3 ( V_112 ) ; V_22 ++ )
F_12 ( V_2 , V_112 [ V_22 ] , 0x100 , 0x100 ) ;
V_45 = F_13 ( V_2 , V_110 , 0 ) ;
if ( V_45 < 0 ) {
F_28 ( V_2 -> V_16 , L_15 ) ;
return V_45 ;
}
F_22 ( V_2 , V_102 ) ;
F_29 ( V_2 , V_113 ,
F_3 ( V_113 ) ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_104 ) ;
return 0 ;
}
static T_3 int F_31 ( struct V_114 * V_115 ,
const struct V_116 * V_117 )
{
struct V_27 * V_28 ;
int V_45 ;
V_28 = F_32 ( sizeof( struct V_27 ) , V_118 ) ;
if ( V_28 == NULL )
return - V_119 ;
F_33 ( V_115 , V_28 ) ;
V_45 = F_34 ( & V_115 -> V_16 ,
& V_120 , & V_121 , 1 ) ;
if ( V_45 < 0 )
F_35 ( V_28 ) ;
return V_45 ;
}
static T_4 int F_36 ( struct V_114 * V_122 )
{
F_37 ( & V_122 -> V_16 ) ;
F_35 ( F_38 ( V_122 ) ) ;
return 0 ;
}
static int T_5 F_39 ( void )
{
int V_45 = 0 ;
#if F_40 ( V_123 ) || F_40 ( V_124 )
V_45 = F_41 ( & V_125 ) ;
if ( V_45 != 0 ) {
F_42 ( V_126 L_16 ,
V_45 ) ;
}
#endif
return V_45 ;
}
static void T_6 F_43 ( void )
{
#if F_40 ( V_123 ) || F_40 ( V_124 )
F_44 ( & V_125 ) ;
#endif
}
