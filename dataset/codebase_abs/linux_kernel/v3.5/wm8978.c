static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 == V_4 ;
}
static void F_2 ( struct V_5 * V_6 ,
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
F_3 ( V_6 -> V_2 ,
L_1 ,
V_13 ) ;
V_8 -> V_16 = V_13 ;
V_14 = V_9 - V_10 * V_13 ;
V_11 = V_17 * ( long long ) V_14 + V_10 / 2 ;
F_4 ( V_11 , V_10 ) ;
V_12 = V_11 & 0xFFFFFFFF ;
V_8 -> V_12 = V_12 ;
}
static int F_5 ( unsigned int V_18 , unsigned int V_19 ,
unsigned int * V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_6 ( V_22 ) ; V_21 ++ ) {
unsigned int V_23 = 4 * V_18 * V_22 [ V_21 ] /
V_24 [ V_21 ] ;
if ( 3 * V_19 <= V_23 && V_23 < 13 * V_19 ) {
* V_20 = V_23 / 4 ;
return V_21 ;
}
}
return - V_25 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_26 * V_27 = F_8 ( V_6 ) ;
struct V_7 V_8 ;
unsigned int V_28 = V_27 -> V_28 , V_19 = V_27 -> V_19 ,
V_29 = V_27 -> V_29 ;
unsigned int V_30 ;
if ( ! V_19 )
return - V_25 ;
if ( V_28 ) {
unsigned int V_31 ;
V_27 -> V_32 = - 1 ;
if ( 16 * V_28 < 3 * V_19 || 4 * V_28 >= 13 * V_19 )
return - V_25 ;
if ( 4 * V_28 < 3 * V_19 )
V_31 = ( 3 * V_19 / 4 + V_28 - 1 ) / V_28 ;
else
V_31 = 1 ;
F_9 ( V_6 -> V_2 , L_2 , V_33 , V_31 ) ;
F_10 ( V_6 , V_34 , 0x30 ,
( V_31 - 1 ) << 4 ) ;
V_27 -> V_20 = V_28 * V_31 ;
} else if ( V_29 ) {
int V_35 = F_5 ( V_29 , V_19 , & V_27 -> V_20 ) ;
if ( V_35 < 0 )
return V_35 ;
V_27 -> V_32 = V_35 ;
F_10 ( V_6 , V_34 , 7 , 0 ) ;
} else {
return - V_25 ;
}
V_30 = V_27 -> V_20 * 4 ;
F_9 ( V_6 -> V_2 , L_3 , V_33 ,
V_27 -> V_19 , V_27 -> V_20 ) ;
F_2 ( V_6 , & V_8 , V_30 , V_27 -> V_19 ) ;
F_9 ( V_6 -> V_2 , L_4 ,
V_33 , V_8 . V_16 , V_8 . V_12 , V_8 . V_15 ) ;
F_10 ( V_6 , V_36 , 0x20 , 0 ) ;
F_11 ( V_6 , V_37 , ( V_8 . V_15 << 4 ) | V_8 . V_16 ) ;
F_11 ( V_6 , V_38 , V_8 . V_12 >> 18 ) ;
F_11 ( V_6 , V_39 , ( V_8 . V_12 >> 9 ) & 0x1ff ) ;
F_11 ( V_6 , V_40 , V_8 . V_12 & 0x1ff ) ;
F_10 ( V_6 , V_36 , 0x20 , 0x20 ) ;
if ( V_28 )
F_10 ( V_6 , V_34 , 7 , 4 ) ;
return 0 ;
}
static int F_12 ( struct V_41 * V_42 ,
int V_43 , int div )
{
struct V_5 * V_6 = V_42 -> V_6 ;
struct V_26 * V_27 = F_8 ( V_6 ) ;
int V_44 = 0 ;
switch ( V_43 ) {
case V_45 :
V_27 -> V_28 = div ;
if ( V_27 -> V_19 )
V_44 = F_7 ( V_6 ) ;
break;
case V_46 :
if ( div & ~ 0x1c )
return - V_25 ;
F_10 ( V_6 , V_47 , 0x1c , div ) ;
break;
default:
return - V_25 ;
}
F_9 ( V_6 -> V_2 , L_5 , V_33 , V_43 , div ) ;
return V_44 ;
}
static int F_13 ( struct V_41 * V_42 , int V_48 ,
unsigned int V_49 , int V_50 )
{
struct V_5 * V_6 = V_42 -> V_6 ;
struct V_26 * V_27 = F_8 ( V_6 ) ;
int V_44 = 0 ;
F_9 ( V_6 -> V_2 , L_6 , V_33 , V_48 , V_49 ) ;
if ( V_49 ) {
V_27 -> V_19 = V_49 ;
if ( V_27 -> V_28 )
V_44 = F_7 ( V_6 ) ;
if ( ! V_44 )
V_27 -> V_51 = V_48 ;
}
if ( V_27 -> V_51 == V_52 && ( ! V_49 || V_48 == V_53 ) ) {
F_10 ( V_6 , V_47 , 0x100 , 0 ) ;
F_10 ( V_6 , V_34 , 7 , 0 ) ;
F_10 ( V_6 , V_36 , 0x20 , 0 ) ;
V_27 -> V_51 = V_53 ;
V_27 -> V_20 = 0 ;
V_27 -> V_28 = 0 ;
}
return V_44 ;
}
static int F_14 ( struct V_41 * V_42 , unsigned int V_54 )
{
struct V_5 * V_6 = V_42 -> V_6 ;
T_2 V_55 = F_15 ( V_6 , V_56 ) & ~ 0x198 ;
T_2 V_57 = F_15 ( V_6 , V_47 ) ;
F_9 ( V_6 -> V_2 , L_7 , V_33 ) ;
switch ( V_54 & V_58 ) {
case V_59 :
V_57 |= 1 ;
break;
case V_60 :
V_57 &= ~ 1 ;
break;
default:
return - V_25 ;
}
switch ( V_54 & V_61 ) {
case V_62 :
V_55 |= 0x10 ;
break;
case V_63 :
break;
case V_64 :
V_55 |= 0x8 ;
break;
case V_65 :
V_55 |= 0x18 ;
break;
default:
return - V_25 ;
}
switch ( V_54 & V_66 ) {
case V_67 :
break;
case V_68 :
V_55 |= 0x180 ;
break;
case V_69 :
V_55 |= 0x100 ;
break;
case V_70 :
V_55 |= 0x80 ;
break;
default:
return - V_25 ;
}
F_11 ( V_6 , V_56 , V_55 ) ;
F_11 ( V_6 , V_47 , V_57 ) ;
return 0 ;
}
static int F_16 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_41 * V_75 )
{
struct V_5 * V_6 = V_75 -> V_6 ;
struct V_26 * V_27 = F_8 ( V_6 ) ;
T_2 V_76 = F_15 ( V_6 , V_56 ) & ~ 0x60 ;
T_2 V_77 = F_15 ( V_6 , V_78 ) & ~ 0xe ;
T_2 V_79 = F_15 ( V_6 , V_47 ) ;
enum V_80 V_81 = V_79 & 0x100 ?
V_52 : V_53 ;
unsigned int V_82 , V_83 , V_84 = V_85 ;
int V_21 , V_86 = 0 ;
if ( ! V_27 -> V_19 )
return - V_25 ;
switch ( F_17 ( V_74 ) ) {
case V_87 :
break;
case V_88 :
V_76 |= 0x20 ;
break;
case V_89 :
V_76 |= 0x40 ;
break;
case V_90 :
V_76 |= 0x60 ;
break;
}
switch ( F_18 ( V_74 ) ) {
case 8000 :
V_77 |= 0x5 << 1 ;
break;
case 11025 :
V_77 |= 0x4 << 1 ;
break;
case 16000 :
V_77 |= 0x3 << 1 ;
break;
case 22050 :
V_77 |= 0x2 << 1 ;
break;
case 32000 :
V_77 |= 0x1 << 1 ;
break;
case 44100 :
case 48000 :
break;
}
V_27 -> V_29 = F_18 ( V_74 ) * 256 ;
if ( V_27 -> V_51 == V_53 ) {
V_27 -> V_32 = - 1 ;
V_82 = V_27 -> V_19 ;
} else {
if ( ! V_27 -> V_20 ) {
int V_44 = F_7 ( V_6 ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_82 = V_27 -> V_20 ;
}
if ( V_27 -> V_32 < 0 ) {
if ( V_82 < V_27 -> V_29 || V_82 > 12 * V_27 -> V_29 )
return - V_25 ;
for ( V_21 = 0 ; V_21 < F_6 ( V_22 ) ; V_21 ++ ) {
V_83 = abs ( V_27 -> V_29 * 3 -
V_82 * 3 * V_24 [ V_21 ] / V_22 [ V_21 ] ) ;
if ( V_83 < V_84 ) {
V_84 = V_83 ;
V_86 = V_21 ;
}
if ( ! V_83 )
break;
}
} else {
V_86 = V_27 -> V_32 ;
V_83 = 0 ;
}
if ( V_83 )
F_3 ( V_6 -> V_2 , L_8 ,
V_82 * V_24 [ V_86 ] / V_22 [ V_86 ] / 256 ,
V_27 -> V_51 == V_53 ?
L_9 : L_10 ) ;
F_9 ( V_6 -> V_2 , L_11 , V_33 ,
F_17 ( V_74 ) , F_18 ( V_74 ) , V_86 ) ;
F_10 ( V_6 , V_47 , 0xe0 , V_86 << 5 ) ;
F_11 ( V_6 , V_56 , V_76 ) ;
F_11 ( V_6 , V_78 , V_77 ) ;
if ( V_27 -> V_51 != V_81 ) {
if ( V_27 -> V_51 == V_52 )
F_10 ( V_6 , V_47 ,
0x100 , 0x100 ) ;
else
F_10 ( V_6 , V_47 , 0x100 , 0 ) ;
}
return 0 ;
}
static int F_19 ( struct V_41 * V_75 , int V_91 )
{
struct V_5 * V_6 = V_75 -> V_6 ;
F_9 ( V_6 -> V_2 , L_12 , V_33 , V_91 ) ;
if ( V_91 )
F_10 ( V_6 , V_92 , 0x40 , 0x40 ) ;
else
F_10 ( V_6 , V_92 , 0x40 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
enum V_93 V_94 )
{
T_2 V_95 = F_15 ( V_6 , V_36 ) & ~ 3 ;
switch ( V_94 ) {
case V_96 :
case V_97 :
V_95 |= 1 ;
F_11 ( V_6 , V_36 , V_95 ) ;
break;
case V_98 :
V_95 |= 0xc ;
if ( V_6 -> V_99 . V_100 == V_101 ) {
F_11 ( V_6 , V_36 ,
V_95 | 0x3 ) ;
F_21 ( 100 ) ;
}
V_95 |= 0x2 ;
F_11 ( V_6 , V_36 , V_95 ) ;
break;
case V_101 :
F_10 ( V_6 , V_36 , ~ 0x20 , 0 ) ;
F_11 ( V_6 , V_102 , 0 ) ;
F_11 ( V_6 , V_103 , 0 ) ;
break;
}
F_9 ( V_6 -> V_2 , L_13 , V_33 , V_94 , V_95 ) ;
V_6 -> V_99 . V_100 = V_94 ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_26 * V_27 = F_8 ( V_6 ) ;
F_20 ( V_6 , V_101 ) ;
F_11 ( V_6 , V_36 , 0 ) ;
F_23 ( V_27 -> V_104 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_26 * V_27 = F_8 ( V_6 ) ;
F_25 ( V_27 -> V_104 ) ;
F_20 ( V_6 , V_98 ) ;
if ( V_27 -> V_20 )
F_10 ( V_6 , V_36 , 0x20 , 0x20 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
struct V_26 * V_27 = F_8 ( V_6 ) ;
int V_44 = 0 , V_21 ;
V_27 -> V_51 = V_52 ;
V_6 -> V_105 = V_27 -> V_104 ;
V_44 = F_27 ( V_6 , 7 , 9 , V_106 ) ;
if ( V_44 < 0 ) {
F_28 ( V_6 -> V_2 , L_14 , V_44 ) ;
return V_44 ;
}
for ( V_21 = 0 ; V_21 < F_6 ( V_107 ) ; V_21 ++ )
F_10 ( V_6 , V_107 [ V_21 ] , 0x100 , 0x100 ) ;
F_20 ( V_6 , V_98 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
F_20 ( V_6 , V_101 ) ;
return 0 ;
}
static T_3 int F_30 ( struct V_108 * V_109 ,
const struct V_110 * V_111 )
{
struct V_26 * V_27 ;
int V_44 ;
V_27 = F_31 ( & V_109 -> V_2 , sizeof( struct V_26 ) ,
V_112 ) ;
if ( V_27 == NULL )
return - V_113 ;
V_27 -> V_104 = F_32 ( V_109 , & V_114 ) ;
if ( F_33 ( V_27 -> V_104 ) ) {
V_44 = F_34 ( V_27 -> V_104 ) ;
F_28 ( & V_109 -> V_2 , L_15 , V_44 ) ;
return V_44 ;
}
F_35 ( V_109 , V_27 ) ;
V_44 = F_36 ( V_27 -> V_104 , V_4 , 0 ) ;
if ( V_44 != 0 ) {
F_28 ( & V_109 -> V_2 , L_16 , V_44 ) ;
goto V_115;
}
V_44 = F_37 ( & V_109 -> V_2 ,
& V_116 , & V_117 , 1 ) ;
if ( V_44 != 0 ) {
F_28 ( & V_109 -> V_2 , L_17 , V_44 ) ;
goto V_115;
}
return 0 ;
V_115:
F_38 ( V_27 -> V_104 ) ;
return V_44 ;
}
static T_4 int F_39 ( struct V_108 * V_118 )
{
struct V_26 * V_27 = F_40 ( V_118 ) ;
F_41 ( & V_118 -> V_2 ) ;
F_38 ( V_27 -> V_104 ) ;
return 0 ;
}
static int T_5 F_42 ( void )
{
int V_44 = 0 ;
V_44 = F_43 ( & V_119 ) ;
if ( V_44 != 0 ) {
F_44 ( V_120 L_18 ,
V_44 ) ;
}
return V_44 ;
}
static void T_6 F_45 ( void )
{
F_46 ( & V_119 ) ;
}
