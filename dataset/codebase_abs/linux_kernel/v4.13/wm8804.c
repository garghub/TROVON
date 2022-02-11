static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
switch ( V_5 ) {
case V_11 :
if ( ! V_10 -> V_12 )
F_4 ( V_7 , V_13 , 0x10 , 0x0 ) ;
V_10 -> V_12 ++ ;
break;
case V_14 :
V_10 -> V_12 -- ;
if ( ! V_10 -> V_12 )
F_4 ( V_7 , V_13 , 0x10 , 0x10 ) ;
break;
}
return 0 ;
}
static int F_5 ( struct V_3 * V_4 ,
struct V_15 * V_16 )
{
struct V_6 * V_7 = F_6 ( V_4 ) ;
struct V_17 * V_8 = F_7 ( V_7 ) ;
struct V_18 * V_19 = (struct V_18 * ) V_4 -> V_20 ;
unsigned int V_21 = V_16 -> V_22 . V_23 . V_24 [ 0 ] << V_19 -> V_25 ;
unsigned int V_26 = 1 << V_19 -> V_25 ;
unsigned int V_27 ;
if ( V_21 != 0 && V_21 != V_26 )
return - V_28 ;
F_8 ( V_8 ) ;
if ( F_9 ( V_7 , V_19 -> V_29 , V_26 , V_21 ) ) {
V_27 = F_10 ( V_7 , V_13 ) & 0x4 ;
F_4 ( V_7 , V_13 , 0x4 , 0x4 ) ;
F_4 ( V_7 , V_19 -> V_29 , V_26 , V_21 ) ;
F_4 ( V_7 , V_13 , 0x4 , V_27 ) ;
}
F_11 ( V_8 ) ;
return 0 ;
}
static bool F_12 ( struct V_30 * V_31 , unsigned int V_29 )
{
switch ( V_29 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
return true ;
default:
return false ;
}
}
static int F_13 ( struct V_9 * V_10 )
{
return F_14 ( V_10 -> V_42 , V_32 , 0x0 ) ;
}
static int F_15 ( struct V_43 * V_44 , unsigned int V_45 )
{
struct V_6 * V_7 ;
T_1 V_46 , V_47 , V_48 , V_49 ;
V_7 = V_44 -> V_7 ;
switch ( V_45 & V_50 ) {
case V_51 :
V_46 = 0x2 ;
break;
case V_52 :
V_46 = 0x0 ;
break;
case V_53 :
V_46 = 0x1 ;
break;
case V_54 :
case V_55 :
V_46 = 0x3 ;
break;
default:
F_16 ( V_44 -> V_31 , L_1 ) ;
return - V_28 ;
}
F_4 ( V_7 , V_56 , 0x3 , V_46 ) ;
F_4 ( V_7 , V_57 , 0x3 , V_46 ) ;
switch ( V_45 & V_58 ) {
case V_59 :
V_47 = 1 ;
break;
case V_60 :
V_47 = 0 ;
break;
default:
F_16 ( V_44 -> V_31 , L_2 ) ;
return - V_28 ;
}
F_4 ( V_7 , V_57 , 0x40 , V_47 << 6 ) ;
V_48 = V_49 = 0 ;
switch ( V_45 & V_61 ) {
case V_62 :
break;
case V_63 :
V_48 = V_49 = 1 ;
break;
case V_64 :
V_48 = 1 ;
break;
case V_65 :
V_49 = 1 ;
break;
default:
F_16 ( V_44 -> V_31 , L_3 ) ;
return - V_28 ;
}
F_4 ( V_7 , V_56 , 0x10 | 0x20 ,
( V_48 << 4 ) | ( V_49 << 5 ) ) ;
F_4 ( V_7 , V_57 , 0x10 | 0x20 ,
( V_48 << 4 ) | ( V_49 << 5 ) ) ;
return 0 ;
}
static int F_17 ( struct V_66 * V_67 ,
struct V_68 * V_69 ,
struct V_43 * V_44 )
{
struct V_6 * V_7 ;
T_1 V_70 ;
V_7 = V_44 -> V_7 ;
switch ( F_18 ( V_69 ) ) {
case 16 :
V_70 = 0x0 ;
break;
case 20 :
V_70 = 0x1 ;
break;
case 24 :
V_70 = 0x2 ;
break;
default:
F_16 ( V_44 -> V_31 , L_4 ,
F_18 ( V_69 ) ) ;
return - V_28 ;
}
F_4 ( V_7 , V_56 , 0xc , V_70 << 2 ) ;
F_4 ( V_7 , V_57 , 0xc , V_70 << 2 ) ;
return 0 ;
}
static int F_19 ( struct V_71 * V_71 , unsigned int V_72 ,
unsigned int V_73 , unsigned int V_74 )
{
T_2 V_75 ;
unsigned long int V_76 , V_77 , V_78 , V_79 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < F_20 ( V_81 ) ; V_80 ++ ) {
V_79 = V_72 * V_81 [ V_80 ] . div ;
if ( ( V_79 >= 90000000 && V_79 <= 100000000 ) &&
( V_74 == V_81 [ V_80 ] . V_82 ) ) {
V_71 -> V_83 = V_81 [ V_80 ] . V_83 ;
V_71 -> V_82 = V_81 [ V_80 ] . V_82 ;
V_72 *= V_81 [ V_80 ] . div ;
break;
}
}
if ( V_80 == F_20 ( V_81 ) ) {
F_21 ( L_5 ,
V_84 , V_72 ) ;
return - V_28 ;
}
V_71 -> V_85 = 0 ;
V_77 = V_72 / V_73 ;
if ( V_77 < 5 ) {
V_73 >>= 1 ;
V_71 -> V_85 = 1 ;
V_77 = V_72 / V_73 ;
}
if ( V_77 < 5 || V_77 > 13 ) {
F_21 ( L_6 ,
V_84 , V_77 ) ;
return - V_28 ;
}
V_71 -> V_86 = V_77 ;
V_78 = V_72 % V_73 ;
V_75 = V_87 * ( T_2 ) V_78 ;
F_22 ( V_75 , V_73 ) ;
V_76 = V_75 & 0xffffffff ;
if ( ( V_76 % 10 ) >= 5 )
V_76 += 5 ;
V_76 /= 10 ;
V_71 -> V_88 = V_76 ;
return 0 ;
}
static int F_23 ( struct V_43 * V_44 , int V_89 ,
int V_73 , unsigned int V_90 ,
unsigned int V_91 )
{
struct V_6 * V_7 = V_44 -> V_7 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
bool V_92 ;
if ( ! V_90 || ! V_91 ) {
F_24 ( V_10 -> V_42 , V_13 ,
0x1 , 0x1 , & V_92 ) ;
if ( V_92 )
F_25 ( V_10 -> V_31 ) ;
} else {
int V_93 ;
struct V_71 V_71 ;
V_93 = F_19 ( & V_71 , V_91 , V_90 ,
V_10 -> V_74 ) ;
if ( V_93 )
return V_93 ;
F_24 ( V_10 -> V_42 , V_13 ,
0x1 , 0x1 , & V_92 ) ;
if ( ! V_92 )
F_26 ( V_10 -> V_31 ) ;
F_4 ( V_7 , V_94 , 0xf | 0x10 ,
V_71 . V_86 | ( V_71 . V_85 << 4 ) ) ;
F_4 ( V_7 , V_95 , 0x3 | 0x8 ,
V_71 . V_83 | ( V_71 . V_82 << 3 ) ) ;
F_27 ( V_7 , V_96 , V_71 . V_88 & 0xff ) ;
F_27 ( V_7 , V_97 , ( V_71 . V_88 >> 8 ) & 0xff ) ;
F_27 ( V_7 , V_98 , V_71 . V_88 >> 16 ) ;
F_4 ( V_7 , V_13 , 0x1 , 0 ) ;
}
return 0 ;
}
static int F_28 ( struct V_43 * V_44 ,
int V_99 , unsigned int V_100 , int V_101 )
{
struct V_6 * V_7 ;
V_7 = V_44 -> V_7 ;
switch ( V_99 ) {
case V_102 :
if ( ( V_100 >= 10000000 && V_100 <= 14400000 )
|| ( V_100 >= 16280000 && V_100 <= 27000000 ) )
F_4 ( V_7 , V_103 , 0x80 , 0x80 ) ;
else {
F_16 ( V_44 -> V_31 , L_7
L_8 , V_100 ) ;
return - V_28 ;
}
break;
case V_104 :
F_4 ( V_7 , V_103 , 0x80 , 0 ) ;
break;
case V_105 :
F_4 ( V_7 , V_103 , 0x8 , 0 ) ;
break;
case V_106 :
F_4 ( V_7 , V_103 , 0x8 , 0x8 ) ;
break;
default:
F_16 ( V_44 -> V_31 , L_9 , V_99 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_29 ( struct V_43 * V_44 ,
int V_107 , int div )
{
struct V_6 * V_7 ;
struct V_9 * V_10 ;
V_7 = V_44 -> V_7 ;
switch ( V_107 ) {
case V_108 :
F_4 ( V_7 , V_95 , 0x30 ,
( div & 0x3 ) << 4 ) ;
break;
case V_109 :
V_10 = F_3 ( V_7 ) ;
V_10 -> V_74 = div ;
break;
default:
F_16 ( V_44 -> V_31 , L_10 , V_107 ) ;
return - V_28 ;
}
return 0 ;
}
int F_30 ( struct V_30 * V_31 , struct V_42 * V_42 )
{
struct V_9 * V_10 ;
unsigned int V_110 , V_111 ;
int V_80 , V_93 ;
V_10 = F_31 ( V_31 , sizeof( * V_10 ) , V_112 ) ;
if ( ! V_10 )
return - V_113 ;
F_32 ( V_31 , V_10 ) ;
V_10 -> V_31 = V_31 ;
V_10 -> V_42 = V_42 ;
V_10 -> V_114 = F_33 ( V_31 , L_11 ,
V_115 ) ;
if ( F_34 ( V_10 -> V_114 ) ) {
V_93 = F_35 ( V_10 -> V_114 ) ;
F_16 ( V_31 , L_12 , V_93 ) ;
return V_93 ;
}
for ( V_80 = 0 ; V_80 < F_20 ( V_10 -> V_116 ) ; V_80 ++ )
V_10 -> V_116 [ V_80 ] . V_117 = V_118 [ V_80 ] ;
V_93 = F_36 ( V_31 , F_20 ( V_10 -> V_116 ) ,
V_10 -> V_116 ) ;
if ( V_93 ) {
F_16 ( V_31 , L_13 , V_93 ) ;
return V_93 ;
}
V_10 -> V_119 [ 0 ] . V_120 = V_121 ;
V_10 -> V_119 [ 1 ] . V_120 = V_122 ;
for ( V_80 = 0 ; V_80 < F_20 ( V_10 -> V_116 ) ; V_80 ++ ) {
struct V_123 * V_123 = V_10 -> V_116 [ V_80 ] . V_124 ;
V_93 = F_37 ( V_123 ,
& V_10 -> V_119 [ V_80 ] ) ;
if ( V_93 != 0 ) {
F_16 ( V_31 ,
L_14 ,
V_93 ) ;
return V_93 ;
}
}
V_93 = F_38 ( F_20 ( V_10 -> V_116 ) ,
V_10 -> V_116 ) ;
if ( V_93 ) {
F_16 ( V_31 , L_15 , V_93 ) ;
return V_93 ;
}
if ( V_10 -> V_114 )
F_39 ( V_10 -> V_114 , 1 ) ;
V_93 = F_40 ( V_42 , V_32 , & V_110 ) ;
if ( V_93 < 0 ) {
F_16 ( V_31 , L_16 , V_93 ) ;
goto V_125;
}
V_93 = F_40 ( V_42 , V_33 , & V_111 ) ;
if ( V_93 < 0 ) {
F_16 ( V_31 , L_16 , V_93 ) ;
goto V_125;
}
V_111 = ( V_111 << 8 ) | V_110 ;
if ( V_111 != 0x8805 ) {
F_16 ( V_31 , L_17 , V_111 ) ;
V_93 = - V_28 ;
goto V_125;
}
V_93 = F_40 ( V_42 , V_34 , & V_110 ) ;
if ( V_93 < 0 ) {
F_16 ( V_31 , L_18 ,
V_93 ) ;
goto V_125;
}
F_41 ( V_31 , L_19 , V_110 + 'A' ) ;
if ( ! V_10 -> V_114 ) {
V_93 = F_13 ( V_10 ) ;
if ( V_93 < 0 ) {
F_16 ( V_31 , L_20 , V_93 ) ;
goto V_125;
}
}
V_93 = F_42 ( V_31 , & V_126 ,
& V_127 , 1 ) ;
if ( V_93 < 0 ) {
F_16 ( V_31 , L_21 , V_93 ) ;
goto V_125;
}
F_43 ( V_31 ) ;
F_44 ( V_31 ) ;
F_45 ( V_31 ) ;
return 0 ;
V_125:
F_46 ( F_20 ( V_10 -> V_116 ) , V_10 -> V_116 ) ;
return V_93 ;
}
void F_47 ( struct V_30 * V_31 )
{
F_48 ( V_31 ) ;
F_49 ( V_31 ) ;
}
static int F_50 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = F_51 ( V_31 ) ;
int V_93 ;
V_93 = F_38 ( F_20 ( V_10 -> V_116 ) ,
V_10 -> V_116 ) ;
if ( V_93 ) {
F_16 ( V_10 -> V_31 , L_15 , V_93 ) ;
return V_93 ;
}
F_52 ( V_10 -> V_42 ) ;
F_53 ( V_10 -> V_42 , V_13 , 0x8 , 0x0 ) ;
return 0 ;
}
static int F_54 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = F_51 ( V_31 ) ;
F_53 ( V_10 -> V_42 , V_13 , 0x8 , 0x8 ) ;
F_46 ( F_20 ( V_10 -> V_116 ) ,
V_10 -> V_116 ) ;
return 0 ;
}
