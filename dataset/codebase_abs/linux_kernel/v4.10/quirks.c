static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 1 ;
}
static void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_4 = 1 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_1 * V_5 = NULL ;
unsigned char V_6 ;
while ( ( V_5 = F_4 ( V_7 , V_8 , V_5 ) ) ) {
F_5 ( V_5 , 0x82 , & V_6 ) ;
if ( ! ( V_6 & 1 << 1 ) ) {
F_6 ( & V_5 -> V_2 , L_1 ) ;
V_6 |= 1 << 1 ;
F_7 ( V_5 , 0x82 , V_6 ) ;
}
}
}
static void F_8 ( struct V_1 * V_2 )
{
if ( ! V_9 ) {
V_9 = 1 ;
F_6 ( & V_2 -> V_2 , L_2 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_10 ;
T_2 V_11 ;
F_10 ( V_2 , 0x40 , & V_10 ) ;
V_10 = V_10 & 0xff80 ;
V_11 = F_11 ( V_10 ) ;
if ( V_11 & 0x10 ) {
F_6 ( & V_2 -> V_2 , V_12 L_3 ) ;
F_12 ( 0x10 , V_10 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_14 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_4 ) ;
V_13 |= V_14 ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
T_3 V_15 ;
F_5 ( V_2 , 0x08 , & V_15 ) ;
if ( V_15 == 0x13 ) {
F_6 ( & V_2 -> V_2 , L_5 ) ;
V_13 |= V_16 ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_17 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_6 ) ;
V_13 |= V_17 ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
T_3 V_19 ;
V_18 = F_4 ( V_20 , V_21 , NULL ) ;
if ( V_18 != NULL ) {
if ( V_18 -> V_22 < 0x40 || V_18 -> V_22 > 0x42 )
goto exit;
} else {
V_18 = F_4 ( V_20 , V_23 , NULL ) ;
if ( V_18 == NULL )
goto exit;
if ( V_18 -> V_22 < 0x10 || V_18 -> V_22 > 0x12 )
goto exit;
}
F_5 ( V_2 , 0x76 , & V_19 ) ;
V_19 &= ~ ( 1 << 5 ) ;
V_19 |= ( 1 << 4 ) ;
F_7 ( V_2 , 0x76 , V_19 ) ;
F_6 ( & V_2 -> V_2 , L_7 ) ;
exit:
F_17 ( V_18 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_24 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_6 ) ;
V_13 |= V_24 ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_25 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_6 ) ;
V_13 |= V_25 ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_26 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_6 ) ;
V_13 |= V_26 | V_17 ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_27 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_6 ) ;
V_13 |= V_27 ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_28 = 0xA0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_28 = 0x600 ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
struct V_31 * V_32 = & V_2 -> V_31 [ V_29 ] ;
if ( V_32 -> V_33 & V_34 && F_25 ( V_32 ) < V_35 ) {
V_32 -> V_36 = V_35 - 1 ;
V_32 -> V_37 = 0 ;
V_32 -> V_33 |= V_38 ;
F_6 ( & V_2 -> V_2 , L_8 ,
V_29 , V_32 ) ;
}
}
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_31 [ 0 ] ;
if ( ( V_32 -> V_37 & 0x3ffffff ) || V_32 -> V_36 != V_32 -> V_37 + 0x3ffffff ) {
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0x3ffffff ;
}
}
static void F_27 ( struct V_1 * V_2 , int V_39 , unsigned V_40 ,
const char * V_41 )
{
T_1 V_42 ;
struct V_43 V_44 ;
struct V_31 * V_45 = V_2 -> V_31 + V_39 ;
F_10 ( V_2 , V_46 + ( V_39 << 2 ) , & V_42 ) ;
if ( ! V_42 )
return;
V_45 -> V_41 = F_28 ( V_2 ) ;
V_45 -> V_33 = V_42 & ~ V_47 ;
V_45 -> V_33 |=
( V_48 | V_49 | V_50 ) ;
V_42 &= ~ ( V_40 - 1 ) ;
V_44 . V_37 = V_42 ;
V_44 . V_36 = V_42 + V_40 - 1 ;
F_29 ( V_2 -> V_51 , V_45 , & V_44 ) ;
F_6 ( & V_2 -> V_2 , V_12 L_9 ,
V_41 , V_46 + ( V_39 << 2 ) , V_45 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
static char * V_41 = L_10 ;
if ( F_31 ( V_2 , 0 ) != 8 ) {
F_27 ( V_2 , 0 , 8 , V_41 ) ;
F_27 ( V_2 , 1 , 256 , V_41 ) ;
F_27 ( V_2 , 2 , 64 , V_41 ) ;
F_6 ( & V_2 -> V_2 , L_11 ,
V_41 ) ;
}
}
static void F_32 ( struct V_1 * V_2 , int V_52 ,
unsigned V_40 , int V_53 , const char * V_41 )
{
T_2 V_42 ;
struct V_43 V_44 ;
struct V_31 * V_45 = V_2 -> V_31 + V_53 ;
F_33 ( V_2 , V_52 , & V_42 ) ;
V_42 &= ~ ( V_40 - 1 ) ;
if ( ! V_42 )
return;
V_45 -> V_41 = F_28 ( V_2 ) ;
V_45 -> V_33 = V_48 ;
V_44 . V_37 = V_42 ;
V_44 . V_36 = V_42 + V_40 - 1 ;
F_29 ( V_2 -> V_51 , V_45 , & V_44 ) ;
if ( ! F_34 ( V_2 , V_53 ) )
F_6 ( & V_2 -> V_2 , L_12 , V_45 , V_41 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_13 ) ;
F_36 ( 0x3b0 , 0x0C , L_14 ) ;
F_36 ( 0x3d3 , 0x01 , L_14 ) ;
}
static void F_37 ( struct V_1 * V_54 )
{
T_1 V_55 = V_54 -> V_55 ;
V_54 -> V_55 = V_56 ;
F_6 ( & V_54 -> V_2 , L_15 ,
V_55 , V_54 -> V_55 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_32 ( V_2 , 0xE0 , 64 , V_57 , L_16 ) ;
F_32 ( V_2 , 0xE2 , 32 , V_57 + 1 , L_17 ) ;
}
static void F_39 ( struct V_1 * V_2 , const char * V_41 , unsigned int V_52 , unsigned int V_58 )
{
T_1 V_59 ;
T_1 V_60 , V_40 , V_61 ;
F_10 ( V_2 , V_52 , & V_59 ) ;
if ( ( V_59 & V_58 ) != V_58 )
return;
V_60 = ( V_59 >> 16 ) & 15 ;
V_61 = V_59 & 0xffff ;
V_40 = 16 ;
for (; ; ) {
unsigned V_62 = V_40 >> 1 ;
if ( ( V_62 & V_60 ) == V_62 )
break;
V_40 = V_62 ;
}
V_61 &= - V_40 ;
F_6 ( & V_2 -> V_2 , L_18 , V_41 , V_61 ,
V_61 + V_40 - 1 ) ;
}
static void F_40 ( struct V_1 * V_2 , const char * V_41 , unsigned int V_52 , unsigned int V_58 )
{
T_1 V_59 ;
T_1 V_60 , V_40 , V_61 ;
F_10 ( V_2 , V_52 , & V_59 ) ;
if ( ( V_59 & V_58 ) != V_58 )
return;
V_61 = V_59 & 0xffff0000 ;
V_60 = ( V_59 & 0x3f ) << 16 ;
V_40 = 128 << 16 ;
for (; ; ) {
unsigned V_62 = V_40 >> 1 ;
if ( ( V_62 & V_60 ) == V_62 )
break;
V_40 = V_62 ;
}
V_61 &= - V_40 ;
F_6 ( & V_2 -> V_2 , L_19 , V_41 , V_61 ,
V_61 + V_40 - 1 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_1 V_63 ;
F_32 ( V_2 , 0x40 , 64 , V_57 , L_20 ) ;
F_32 ( V_2 , 0x90 , 16 , V_57 + 1 , L_21 ) ;
F_10 ( V_2 , 0x5c , & V_63 ) ;
F_39 ( V_2 , L_22 , 0x60 , 3 << 21 ) ;
F_39 ( V_2 , L_23 , 0x64 , 3 << 21 ) ;
if ( V_63 & ( 1 << 29 ) ) {
F_39 ( V_2 , L_24 , 0x68 , 1 << 20 ) ;
F_40 ( V_2 , L_25 , 0x6c , 1 << 7 ) ;
}
if ( V_63 & ( 1 << 30 ) ) {
F_39 ( V_2 , L_26 , 0x70 , 1 << 20 ) ;
F_40 ( V_2 , L_27 , 0x74 , 1 << 7 ) ;
}
F_39 ( V_2 , L_28 , 0x78 , 1 << 20 ) ;
F_39 ( V_2 , L_29 , 0x7c , 1 << 20 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_3 V_58 ;
F_5 ( V_2 , V_64 , & V_58 ) ;
if ( V_58 & V_65 )
F_32 ( V_2 , V_66 , 128 , V_57 ,
L_30 ) ;
F_5 ( V_2 , V_67 , & V_58 ) ;
if ( V_58 & V_68 )
F_32 ( V_2 , V_69 , 64 , V_57 + 1 ,
L_31 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
T_3 V_58 ;
F_5 ( V_2 , V_64 , & V_58 ) ;
if ( V_58 & V_70 )
F_32 ( V_2 , V_66 , 128 , V_57 ,
L_32 ) ;
F_5 ( V_2 , V_71 , & V_58 ) ;
if ( V_58 & V_72 )
F_32 ( V_2 , V_73 , 64 , V_57 + 1 ,
L_33 ) ;
}
static void F_44 ( struct V_1 * V_2 , unsigned V_74 , const char * V_41 , int V_75 )
{
T_1 V_76 ;
T_1 V_40 , V_61 ;
F_10 ( V_2 , V_74 , & V_76 ) ;
if ( ! ( V_76 & 1 ) )
return;
V_61 = V_76 & 0xfffc ;
if ( V_75 ) {
V_40 = 16 ;
} else {
V_40 = 128 ;
}
V_61 &= ~ ( V_40 - 1 ) ;
F_6 ( & V_2 -> V_2 , L_18 , V_41 , V_61 , V_61 + V_40 - 1 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_44 ( V_2 , 0x84 , L_34 , 0 ) ;
F_44 ( V_2 , 0x88 , L_35 , 1 ) ;
}
static void F_46 ( struct V_1 * V_2 , unsigned V_74 , const char * V_41 )
{
T_1 V_76 ;
T_1 V_60 , V_61 ;
F_10 ( V_2 , V_74 , & V_76 ) ;
if ( ! ( V_76 & 1 ) )
return;
V_61 = V_76 & 0xfffc ;
V_60 = ( V_76 >> 16 ) & 0xfc ;
V_60 |= 3 ;
F_6 ( & V_2 -> V_2 , L_36 , V_41 , V_61 , V_60 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_46 ( V_2 , 0x84 , L_37 ) ;
F_46 ( V_2 , 0x88 , L_38 ) ;
F_46 ( V_2 , 0x8c , L_39 ) ;
F_46 ( V_2 , 0x90 , L_40 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 & 0x10 )
F_32 ( V_2 , 0x48 , 256 , V_57 ,
L_41 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_48 ( V_2 ) ;
F_32 ( V_2 , 0x70 , 128 , V_57 + 1 ,
L_42 ) ;
F_32 ( V_2 , 0x90 , 16 , V_57 + 2 , L_43 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_32 ( V_2 , 0x88 , 128 , V_57 , L_44 ) ;
F_32 ( V_2 , 0xd0 , 16 , V_57 + 1 , L_45 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_1 * V_54 ;
T_2 V_77 ;
F_52 ( & V_2 -> V_2 , L_46 ) ;
F_53 (pdev, &dev->subordinate->devices, bus_list) {
F_33 ( V_54 , V_78 , & V_77 ) ;
if ( V_77 & V_79 )
F_54 ( V_54 , V_78 , V_77 & ~ V_79 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
T_3 V_80 ;
if ( V_81 < 1 )
V_80 = 0 ;
else
V_80 = 0x1f ;
F_6 ( & V_2 -> V_2 , L_47 ,
V_80 == 0 ? L_48 : L_49 ) ;
F_7 ( V_2 , 0x58 , V_80 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_3 V_82 ;
#define F_57 8
F_5 ( V_2 , 0x5B , & V_82 ) ;
if ( ! ( V_82 & F_57 ) ) {
F_6 ( & V_2 -> V_2 , L_50 ) ;
F_7 ( V_2 , 0x5B , V_82 | F_57 ) ;
}
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 >= 0x02 ) {
F_52 ( & V_2 -> V_2 , L_51 ) ;
F_52 ( & V_2 -> V_2 , L_52 ) ;
}
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 == 0xa118 )
V_2 -> V_84 -> V_85 = V_2 -> V_86 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( V_2 -> V_87 && V_2 -> V_22 <= 0x12 ) {
F_6 ( & V_2 -> V_2 , L_53 ,
V_2 -> V_22 ) ;
V_2 -> V_87 -> V_88 |= V_89 ;
}
}
static void F_61 ( struct V_1 * V_5 )
{
T_3 V_90 ;
F_5 ( V_5 , 0x42 , & V_90 ) ;
V_90 &= 0xf ;
if ( V_90 && ( V_90 != 2 ) )
V_5 -> V_90 = V_90 ;
}
static void F_62 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_91 ) {
case V_21 :
V_92 = F_63 ( V_2 -> V_86 ) ;
V_93 = F_63 ( V_2 -> V_86 ) ;
break;
case V_94 :
case V_95 :
V_92 = 15 ;
break;
case V_96 :
V_92 = 16 ;
break;
case V_23 :
case V_97 :
case V_98 :
case V_99 :
V_92 = 17 ;
break;
}
}
static void F_64 ( struct V_1 * V_2 )
{
T_3 V_90 , V_100 ;
if ( V_92 == - 1 )
return;
V_100 = V_2 -> V_90 ;
if ( ! V_100 || V_100 > 15 )
return;
if ( V_2 -> V_51 -> V_101 != 0 || F_63 ( V_2 -> V_86 ) > V_93 ||
F_63 ( V_2 -> V_86 ) < V_92 )
return;
F_5 ( V_2 , V_102 , & V_90 ) ;
if ( V_100 != V_90 ) {
F_6 ( & V_2 -> V_2 , L_54 ,
V_90 , V_100 ) ;
F_65 ( 15 ) ;
F_7 ( V_2 , V_102 , V_100 ) ;
}
}
static void F_66 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0xfc , 0 ) ;
F_33 ( V_2 , V_103 , & V_2 -> V_91 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_68 ( V_2 , V_104 , 0 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_1 V_105 ;
F_10 ( V_2 , 0x4C , & V_105 ) ;
if ( ( V_105 & 6 ) != 6 ) {
V_105 |= 6 ;
F_52 ( & V_2 -> V_2 , L_55 ) ;
F_68 ( V_2 , 0x4C , V_105 ) ;
F_10 ( V_2 , 0x84 , & V_105 ) ;
V_105 |= ( 1 << 23 ) ;
F_68 ( V_2 , 0x84 , V_105 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_31 [ 1 ] ;
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0xffffff ;
}
static void F_71 ( struct V_1 * V_2 )
{
V_2 -> V_106 = 1 ;
}
static void F_72 ( struct V_1 * V_2 )
{
T_3 V_74 ;
F_5 ( V_2 , 0x41 , & V_74 ) ;
if ( V_74 & 2 ) {
V_74 &= ~ 2 ;
F_6 ( & V_2 -> V_2 , L_56 ,
V_74 ) ;
F_7 ( V_2 , 0x41 , V_74 ) ;
}
}
static void F_73 ( struct V_1 * V_54 )
{
T_2 V_107 ;
if ( V_54 -> V_22 != 0x04 )
return;
F_33 ( V_54 , 0x40 , & V_107 ) ;
if ( V_107 & ( 1 << 6 ) ) {
V_107 &= ~ ( 1 << 6 ) ;
F_54 ( V_54 , 0x40 , V_107 ) ;
F_6 ( & V_54 -> V_2 , L_57 ) ;
}
}
static void F_74 ( struct V_1 * V_54 )
{
T_3 V_80 ;
F_5 ( V_54 , V_108 , & V_80 ) ;
if ( V_80 == 0x01 ) {
F_5 ( V_54 , 0x40 , & V_80 ) ;
F_7 ( V_54 , 0x40 , V_80 | 1 ) ;
F_7 ( V_54 , 0x9 , 1 ) ;
F_7 ( V_54 , 0xa , 6 ) ;
F_7 ( V_54 , 0x40 , V_80 ) ;
V_54 -> V_55 = V_109 ;
F_6 ( & V_54 -> V_2 , L_58 ) ;
}
}
static void F_75 ( struct V_1 * V_54 )
{
T_3 V_110 ;
F_5 ( V_54 , V_111 , & V_110 ) ;
if ( V_110 & 5 ) {
V_110 &= ~ 5 ;
V_54 -> V_55 &= ~ 5 ;
F_7 ( V_54 , V_111 , V_110 ) ;
}
}
static void F_76 ( struct V_1 * V_54 )
{
T_3 V_110 ;
F_5 ( V_54 , V_111 , & V_110 ) ;
if ( ( ( V_110 & 1 ) && ! ( V_110 & 4 ) ) || ( ( V_110 & 4 ) && ! ( V_110 & 1 ) ) ) {
F_6 ( & V_54 -> V_2 , L_59 ) ;
V_110 &= ~ 5 ;
V_54 -> V_55 &= ~ 5 ;
F_7 ( V_54 , V_111 , V_110 ) ;
}
}
static void F_77 ( struct V_1 * V_54 )
{
V_54 -> V_112 |= V_113 ;
}
static void F_78 ( struct V_1 * V_2 )
{
V_2 -> V_55 = V_114 << 8 ;
}
static void F_79 ( struct V_1 * V_2 )
{
if ( F_80 ( V_2 -> V_115 == V_116 ) ) {
if ( V_2 -> V_91 == V_117 )
switch ( V_2 -> V_83 ) {
case 0x8025 :
case 0x8070 :
case 0x8088 :
case 0x1626 :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_119 )
switch ( V_2 -> V_83 ) {
case 0x80b1 :
case 0x80b2 :
case 0x8093 :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_120 )
switch ( V_2 -> V_83 ) {
case 0x8030 :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_121 )
switch ( V_2 -> V_83 ) {
case 0x8070 :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_122 )
switch ( V_2 -> V_83 ) {
case 0x80c9 :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_123 )
switch ( V_2 -> V_83 ) {
case 0x1751 :
case 0x1821 :
case 0x1897 :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_124 )
switch ( V_2 -> V_83 ) {
case 0x184b :
case 0x186a :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_125 )
switch ( V_2 -> V_83 ) {
case 0x80f2 :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_126 )
switch ( V_2 -> V_83 ) {
case 0x1882 :
case 0x1977 :
V_118 = 1 ;
}
} else if ( F_80 ( V_2 -> V_115 == V_127 ) ) {
if ( V_2 -> V_91 == V_124 )
switch ( V_2 -> V_83 ) {
case 0x088C :
case 0x0890 :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_125 )
switch ( V_2 -> V_83 ) {
case 0x12bc :
case 0x12bd :
case 0x006a :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_128 )
switch ( V_2 -> V_83 ) {
case 0x12bf :
V_118 = 1 ;
}
} else if ( F_80 ( V_2 -> V_115 == V_129 ) ) {
if ( V_2 -> V_91 == V_124 )
switch ( V_2 -> V_83 ) {
case 0xC00C :
V_118 = 1 ;
}
} else if ( F_80 ( V_2 -> V_115 == V_130 ) ) {
if ( V_2 -> V_91 == V_124 )
switch ( V_2 -> V_83 ) {
case 0x0058 :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_131 )
switch ( V_2 -> V_83 ) {
case 0xB16C :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_132 )
switch ( V_2 -> V_83 ) {
case 0x00b8 :
case 0x00b9 :
case 0x00ba :
V_118 = 1 ;
}
else if ( V_2 -> V_91 == V_133 )
switch ( V_2 -> V_83 ) {
case 0x001A :
V_118 = 1 ;
}
}
}
static void F_81 ( struct V_1 * V_2 )
{
T_2 V_76 ;
if ( F_82 ( ! V_118 ) )
return;
F_33 ( V_2 , 0xF2 , & V_76 ) ;
if ( V_76 & 0x8 ) {
F_54 ( V_2 , 0xF2 , V_76 & ( ~ 0x8 ) ) ;
F_33 ( V_2 , 0xF2 , & V_76 ) ;
if ( V_76 & 0x8 )
F_6 ( & V_2 -> V_2 , L_60 ,
V_76 ) ;
else
F_6 ( & V_2 -> V_2 , L_61 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
T_1 V_134 ;
if ( F_82 ( ! V_118 ) )
return;
F_84 ( V_135 ) ;
F_10 ( V_2 , 0xF0 , & V_134 ) ;
V_135 = F_85 ( V_134 & 0xFFFFC000 , 0x4000 ) ;
if ( V_135 == NULL )
return;
}
static void F_86 ( struct V_1 * V_2 )
{
T_1 V_76 ;
if ( F_82 ( ! V_118 || ! V_135 ) )
return;
V_76 = F_87 ( V_135 + 0x3418 ) ;
F_88 ( V_76 & 0xFFFFFFF7 , V_135 + 0x3418 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( F_82 ( ! V_118 || ! V_135 ) )
return;
F_90 ( V_135 ) ;
V_135 = NULL ;
F_6 ( & V_2 -> V_2 , L_62 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_83 ( V_2 ) ;
F_86 ( V_2 ) ;
F_89 ( V_2 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
T_3 V_76 = 0 ;
F_5 ( V_2 , 0x77 , & V_76 ) ;
if ( V_76 & 0x10 ) {
F_6 ( & V_2 -> V_2 , L_63 ) ;
F_7 ( V_2 , 0x77 , V_76 & ~ 0x10 ) ;
}
}
static void F_93 ( struct V_1 * V_2 )
{
T_3 V_74 ;
T_2 V_136 ;
F_5 ( V_2 , V_137 , & V_74 ) ;
F_7 ( V_2 , V_137 , V_74 | ( 1 << 6 ) ) ;
F_33 ( V_2 , V_103 , & V_136 ) ;
if ( ( ( V_136 & 0xfff0 ) != 0x0960 ) && ( V_136 != 0x0018 ) ) {
F_7 ( V_2 , V_137 , V_74 ) ;
return;
}
V_2 -> V_91 = V_136 ;
F_92 ( V_2 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
T_3 V_76 ;
int V_138 = 0 ;
if ( F_82 ( V_2 -> V_115 == V_116 ) ) {
if ( V_2 -> V_91 == V_94 )
V_138 = 1 ;
}
if ( ! V_138 )
return;
F_5 ( V_2 , 0x50 , & V_76 ) ;
if ( V_76 & 0xc0 ) {
F_7 ( V_2 , 0x50 , V_76 & ( ~ 0xc0 ) ) ;
F_5 ( V_2 , 0x50 , & V_76 ) ;
if ( V_76 & 0xc0 )
F_6 ( & V_2 -> V_2 , L_64 ,
V_76 ) ;
else
F_6 ( & V_2 -> V_2 , L_65 ) ;
}
}
static void F_95 ( struct V_1 * V_54 )
{
T_1 V_139 , V_140 , V_55 ;
T_3 V_141 ;
if ( F_96 ( V_54 -> V_86 ) )
return;
F_10 ( V_54 , 0x40 , & V_139 ) ;
F_10 ( V_54 , 0x80 , & V_140 ) ;
V_139 &= ~ 0x00CFF302 ;
V_140 &= ~ ( 1 << 24 ) ;
switch ( V_54 -> V_91 ) {
case V_142 :
case V_143 :
case V_144 :
V_139 |= 0x0002A100 ;
break;
case V_145 :
case V_146 :
V_140 |= ( 1 << 24 ) ;
case V_147 :
case V_148 :
case V_149 :
V_139 |= 0x00C2A1B3 ;
break;
case V_150 :
V_139 |= 0x00C00000 ;
break;
}
F_68 ( V_54 , 0x40 , V_139 ) ;
F_68 ( V_54 , 0x80 , V_140 ) ;
F_5 ( V_54 , V_151 , & V_141 ) ;
V_54 -> V_152 = V_141 & 0x7f ;
V_54 -> V_153 = ! ! ( V_141 & 0x80 ) ;
F_10 ( V_54 , V_154 , & V_55 ) ;
V_54 -> V_55 = V_55 >> 8 ;
}
static void F_97 ( struct V_1 * V_2 )
{
if ( V_2 -> V_153 ) {
F_98 ( & V_2 -> V_2 ) ;
F_6 ( & V_2 -> V_2 , L_66 ) ;
}
}
static void F_99 ( struct V_1 * V_54 )
{
int V_29 ;
if ( ( V_54 -> V_55 >> 8 ) != 0xff00 )
return;
if ( F_100 ( V_54 , 0 ) && F_31 ( V_54 , 0 ) )
F_101 ( & V_155 , & V_54 -> V_31 [ 0 ] ) ;
for ( V_29 = 1 ; V_29 < 6 ; V_29 ++ )
memset ( & V_54 -> V_31 [ V_29 ] , 0 , sizeof( V_54 -> V_31 [ V_29 ] ) ) ;
}
static void F_102 ( struct V_1 * V_54 )
{
V_54 -> V_156 = 1 ;
}
static void F_103 ( struct V_1 * V_2 )
{
V_2 -> V_156 = 1 ;
F_52 ( & V_2 -> V_2 , L_67 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
V_157 = 120 ;
V_2 -> V_158 = 1 ;
}
static void F_105 ( struct V_1 * V_2 )
{
if ( V_159 || V_160 )
return;
V_2 -> V_161 = V_162 ;
F_6 ( & V_2 -> V_2 , L_68 ,
V_2 -> V_163 , V_2 -> V_91 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
T_2 V_164 ;
if ( V_159 )
return;
F_33 ( V_2 , V_165 , & V_164 ) ;
V_164 |= V_166 ;
F_54 ( V_2 , V_165 , V_164 ) ;
F_6 ( & V_2 -> V_2 , L_69 ,
V_2 -> V_163 , V_2 -> V_91 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
T_1 V_167 ;
T_3 V_90 ;
if ( V_159 )
return;
F_10 ( V_2 , V_168 , & V_167 ) ;
F_68 ( V_2 , V_168 , V_167 |
V_169 ) ;
for ( V_90 = 0x10 ; V_90 < 0x10 + 32 ; V_90 ++ ) {
F_108 ( V_90 , V_170 ) ;
F_108 ( 0x00 , V_171 ) ;
}
F_68 ( V_2 , V_168 , V_167 ) ;
F_6 ( & V_2 -> V_2 , L_69 ,
V_2 -> V_163 , V_2 -> V_91 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
T_1 V_167 ;
if ( V_159 )
return;
if ( ( V_2 -> V_22 == V_172 ) ||
( V_2 -> V_22 == V_173 ) )
return;
F_10 ( V_2 , V_174 , & V_167 ) ;
V_167 &= ~ V_175 ;
F_68 ( V_2 , V_174 , V_167 ) ;
F_6 ( & V_2 -> V_2 , L_69 ,
V_2 -> V_163 , V_2 -> V_91 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
T_2 V_164 ;
if ( V_159 )
return;
F_33 ( V_2 , V_176 , & V_164 ) ;
if ( ! V_164 ) {
F_6 ( & V_2 -> V_2 , L_70 ,
V_2 -> V_163 , V_2 -> V_91 ) ;
return;
}
F_54 ( V_2 , V_176 , 0 ) ;
F_6 ( & V_2 -> V_2 , L_69 ,
V_2 -> V_163 , V_2 -> V_91 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_31 [ 0 ] ;
if ( V_32 -> V_37 & 0x8 ) {
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0xf ;
}
}
static void F_112 ( struct V_1 * V_2 )
{
unsigned int V_177 ;
if ( V_2 -> V_22 >= 2 )
return;
for ( V_177 = 0 ; V_177 <= 1 ; V_177 ++ )
if ( F_31 ( V_2 , V_177 ) == 0x80 &&
( F_100 ( V_2 , V_177 ) & 0x80 ) ) {
struct V_31 * V_32 = & V_2 -> V_31 [ V_177 ] ;
F_6 ( & V_2 -> V_2 , L_71 ,
V_177 ) ;
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0xff ;
}
}
static void F_113 ( struct V_1 * V_2 )
{
unsigned int V_178 = ( V_2 -> V_83 & 0xf0 ) >> 4 ;
unsigned int V_179 = V_2 -> V_83 & 0xf ;
switch ( V_2 -> V_91 ) {
case V_180 :
if ( V_2 -> V_115 == V_181 &&
V_2 -> V_83 == 0x0299 )
return;
case V_182 :
case V_183 :
case V_184 :
case V_185 :
if ( V_178 ) {
F_6 ( & V_2 -> V_2 , L_72 ,
V_2 -> V_91 , V_178 , V_179 ) ;
V_2 -> V_55 = ( V_186 << 8 ) |
( V_2 -> V_55 & 0xff ) ;
}
}
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_1 * V_187 ;
if ( ! F_96 ( V_2 -> V_86 ) )
return;
V_187 = F_115 ( V_2 -> V_51 , F_116 ( F_63 ( V_2 -> V_86 ) , 0 ) ) ;
if ( ! V_187 )
return;
if ( V_187 -> V_188 && V_2 -> V_55 == V_187 -> V_55 &&
V_2 -> V_163 == V_187 -> V_163 && V_2 -> V_91 == V_187 -> V_91 )
V_2 -> V_112 |= V_189 ;
F_17 ( V_187 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
T_2 V_77 , V_190 ;
T_3 T_4 * V_191 ;
T_3 V_192 ;
switch ( V_2 -> V_91 ) {
case 0x1029 :
case 0x1030 ... 0x1034 :
case 0x1038 ... 0x103E :
case 0x1050 ... 0x1057 :
case 0x1059 :
case 0x1064 ... 0x106B :
case 0x1091 ... 0x1095 :
case 0x1209 :
case 0x1229 :
case 0x2449 :
case 0x2459 :
case 0x245D :
case 0x27DC :
break;
default:
return;
}
F_33 ( V_2 , V_78 , & V_77 ) ;
if ( ! ( V_77 & V_193 ) || ! F_100 ( V_2 , 0 ) )
return;
if ( V_2 -> V_194 ) {
F_33 ( V_2 , V_2 -> V_194 + V_195 , & V_190 ) ;
if ( ( V_190 & V_196 ) != V_197 )
return;
}
V_191 = F_118 ( F_100 ( V_2 , 0 ) , 8 ) ;
if ( ! V_191 ) {
F_52 ( & V_2 -> V_2 , L_73 ) ;
return;
}
V_192 = F_119 ( V_191 + 3 ) ;
if ( V_192 == 0 ) {
F_52 ( & V_2 -> V_2 , L_74 ) ;
F_120 ( 1 , V_191 + 3 ) ;
}
F_90 ( V_191 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_75 ) ;
F_122 ( V_2 , V_198 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
T_1 V_55 = V_2 -> V_55 ;
if ( V_55 )
return;
V_2 -> V_55 = V_199 << 8 ;
F_6 ( & V_2 -> V_2 , L_76 ,
V_55 , V_2 -> V_55 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
T_2 V_200 ;
F_33 ( V_2 , 0x40 , & V_200 ) ;
if ( V_200 & 0x200 ) {
F_6 ( & V_2 -> V_2 , L_77 ) ;
V_2 -> V_201 = 1 ;
}
}
static void F_125 ( struct V_1 * V_2 )
{
T_5 V_202 ;
if ( F_5 ( V_2 , 0xf41 , & V_202 ) == 0 ) {
if ( ! ( V_202 & 0x20 ) ) {
F_7 ( V_2 , 0xf41 , V_202 | 0x20 ) ;
F_6 ( & V_2 -> V_2 , L_78 ) ;
}
}
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_1 * V_18 = F_4 ( V_20 ,
V_203 , NULL ) ;
T_5 V_202 ;
V_18 = F_4 ( V_20 , V_203 , V_18 ) ;
if ( ! V_18 )
return;
F_17 ( V_18 ) ;
if ( F_5 ( V_2 , 0x76 , & V_202 ) == 0 ) {
if ( V_202 & 0x40 ) {
F_7 ( V_2 , 0x76 , V_202 ^ 0x40 ) ;
F_6 ( & V_2 -> V_2 , L_79 ) ;
}
}
if ( F_5 ( V_2 , 0x72 , & V_202 ) == 0 ) {
if ( V_202 != 0 ) {
F_7 ( V_2 , 0x72 , 0x0 ) ;
F_7 ( V_2 , 0x75 , 0x1 ) ;
F_7 ( V_2 , 0x77 , 0x0 ) ;
F_6 ( & V_2 -> V_2 , L_80 ) ;
}
}
}
static void F_127 ( struct V_1 * V_2 )
{
if ( V_2 -> V_188 ) {
V_2 -> V_188 -> V_204 = 0 ;
F_52 ( & V_2 -> V_2 , V_12 L_81 ) ;
}
}
static void F_128 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_91 == V_205 ) ||
( V_2 -> V_91 == V_206 ) ||
( V_2 -> V_91 == V_207 ) ||
( V_2 -> V_91 == V_208 ) ||
( ( V_2 -> V_91 == V_209 ) &&
( V_2 -> V_22 & 0xf0 ) == 0x0 ) ) {
if ( V_2 -> V_188 )
V_2 -> V_188 -> V_204 = 0x80 ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_10 ( V_2 , 0xf4 , & V_15 ) ;
if ( V_15 == 0x05719000 ) {
int V_210 = F_130 ( V_2 ) ;
if ( V_210 > 2048 )
F_131 ( V_2 , 2048 ) ;
}
}
static void F_132 ( struct V_1 * V_2 )
{
T_3 V_74 ;
if ( F_5 ( V_2 , 0xF4 , & V_74 ) == 0 && ! ( V_74 & 0x02 ) ) {
F_6 ( & V_2 -> V_2 , L_82 ) ;
F_7 ( V_2 , 0xF4 , V_74 | 0x02 ) ;
}
}
static void F_133 ( struct V_1 * V_2 )
{
if ( V_211 ) {
F_68 ( V_2 , 0x98 , 0x1 ) ;
F_134 ( 50 ) ;
}
}
static void F_135 ( struct V_1 * V_2 )
{
F_136 () ;
F_52 ( & V_2 -> V_2 , L_83 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
if ( V_2 -> V_87 ) {
F_52 ( & V_2 -> V_2 , L_84 ) ;
V_2 -> V_87 -> V_88 |= V_212 ;
}
}
static void F_138 ( struct V_1 * V_213 )
{
struct V_1 * V_214 ;
V_214 = F_115 ( V_213 -> V_51 , F_116 ( 1 , 0 ) ) ;
if ( V_214 ) {
if ( V_214 -> V_91 == 0x9602 )
F_137 ( V_214 ) ;
F_17 ( V_214 ) ;
}
}
static int F_139 ( struct V_1 * V_2 )
{
int V_39 , V_215 = V_216 ;
V_39 = F_140 ( V_2 , V_217 ) ;
while ( V_39 && V_215 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_218 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_85 ,
V_33 & V_219 ?
L_86 : L_87 ) ;
return ( V_33 & V_219 ) != 0 ;
}
V_39 = F_141 ( V_2 , V_39 ,
V_217 ) ;
}
return 0 ;
}
static void F_142 ( struct V_1 * V_2 )
{
if ( V_2 -> V_87 && ! F_139 ( V_2 ) ) {
F_52 ( & V_2 -> V_2 , L_84 ) ;
V_2 -> V_87 -> V_88 |= V_212 ;
}
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_1 * V_54 ;
if ( ! V_2 -> V_87 )
return;
V_54 = F_115 ( V_2 -> V_51 , 0 ) ;
if ( ! V_54 )
return;
if ( ! F_139 ( V_2 ) && ! F_139 ( V_54 ) ) {
F_52 ( & V_2 -> V_2 , L_84 ) ;
V_2 -> V_87 -> V_88 |= V_212 ;
}
F_17 ( V_54 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
int V_39 , V_215 = V_216 ;
V_39 = F_140 ( V_2 , V_217 ) ;
while ( V_39 && V_215 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_218 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_88 ) ;
F_7 ( V_2 , V_39 + V_218 ,
V_33 | V_219 ) ;
}
V_39 = F_141 ( V_2 , V_39 ,
V_217 ) ;
}
}
static void F_145 ( struct V_1 * V_2 )
{
const char * V_220 = F_146 ( V_221 ) ;
if ( V_220 &&
( strstr ( V_220 , L_89 ) ||
strstr ( V_220 , L_90 ) ) ) {
F_6 ( & V_2 -> V_2 , L_91 ) ;
V_2 -> V_156 = 1 ;
}
}
static void F_147 ( struct V_1 * V_2 )
{
T_1 V_222 ;
if ( ! F_148 ( V_2 , V_223 ) )
return;
F_10 ( V_2 , 0x74 , & V_222 ) ;
if ( V_222 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_149 ( V_224 L_92 ) ;
V_222 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_68 ( V_2 , 0x74 , V_222 ) ;
}
}
static int F_150 ( struct V_1 * V_2 )
{
int V_39 , V_215 = V_216 ;
int V_225 = 0 ;
V_39 = F_140 ( V_2 , V_217 ) ;
while ( V_39 && V_215 -- ) {
T_3 V_33 ;
if ( V_225 < 1 )
V_225 = 1 ;
if ( F_5 ( V_2 , V_39 + V_218 ,
& V_33 ) == 0 ) {
if ( V_33 & V_219 ) {
if ( V_225 < 2 ) {
V_225 = 2 ;
break;
}
}
}
V_39 = F_141 ( V_2 , V_39 ,
V_217 ) ;
}
return V_225 ;
}
static int F_151 ( struct V_1 * V_213 )
{
struct V_1 * V_2 ;
int V_39 ;
int V_29 , V_226 ;
int V_225 = 0 ;
V_226 = V_213 -> V_86 >> 3 ;
for ( V_29 = V_226 + 1 ; V_29 < 0x20 ; V_29 ++ ) {
V_2 = F_115 ( V_213 -> V_51 , F_116 ( V_29 , 0 ) ) ;
if ( ! V_2 )
continue;
V_39 = F_140 ( V_2 , V_227 ) ;
if ( V_39 != 0 ) {
F_17 ( V_2 ) ;
break;
}
if ( F_150 ( V_2 ) ) {
V_225 = 1 ;
F_17 ( V_2 ) ;
break;
}
F_17 ( V_2 ) ;
}
return V_225 ;
}
static int F_152 ( struct V_1 * V_2 )
{
int V_39 , V_228 ;
int V_36 = 0 ;
T_2 V_33 , V_229 ;
V_39 = F_140 ( V_2 , V_227 ) ;
if ( ! V_39 )
goto V_230;
F_33 ( V_2 , V_39 + V_231 , & V_33 ) ;
V_228 = ( ( V_33 >> 10 ) & 1 ) ?
V_232 : V_233 ;
F_33 ( V_2 , V_39 + V_228 , & V_229 ) ;
if ( V_229 & ( 1 << 6 ) )
V_36 = 1 ;
V_230:
return V_36 ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_1 * V_213 ;
int V_39 ;
int V_29 , V_226 ;
int V_225 = 0 ;
V_226 = V_2 -> V_86 >> 3 ;
for ( V_29 = V_226 ; V_29 >= 0 ; V_29 -- ) {
V_213 = F_115 ( V_2 -> V_51 , F_116 ( V_29 , 0 ) ) ;
if ( ! V_213 )
continue;
V_39 = F_140 ( V_213 , V_227 ) ;
if ( V_39 != 0 ) {
V_225 = 1 ;
break;
}
F_17 ( V_213 ) ;
}
if ( ! V_225 )
return;
if ( V_213 == V_2 && F_152 ( V_213 ) &&
F_151 ( V_213 ) )
goto V_230;
if ( F_139 ( V_213 ) )
goto V_230;
F_144 ( V_2 ) ;
V_230:
F_17 ( V_213 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
int V_39 , V_215 = V_216 ;
V_39 = F_140 ( V_2 , V_217 ) ;
while ( V_39 && V_215 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_218 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_93 ) ;
F_7 ( V_2 , V_39 + V_218 ,
V_33 & ~ V_219 ) ;
}
V_39 = F_141 ( V_2 , V_39 ,
V_217 ) ;
}
}
static void F_155 ( struct V_1 * V_2 , int V_234 )
{
struct V_1 * V_213 ;
int V_39 ;
int V_225 ;
if ( ! F_156 () )
return;
V_225 = F_150 ( V_2 ) ;
if ( V_225 == 0 )
return;
V_213 = F_157 ( 0 , F_116 ( 0 , 0 ) ) ;
if ( V_213 == NULL ) {
F_52 ( & V_2 -> V_2 , L_94 ) ;
return;
}
V_39 = F_140 ( V_213 , V_227 ) ;
if ( V_39 != 0 ) {
if ( V_225 == 1 ) {
if ( V_234 )
F_144 ( V_2 ) ;
else
F_153 ( V_2 ) ;
}
goto V_230;
}
if ( V_225 == 1 )
goto V_230;
F_154 ( V_2 ) ;
V_230:
F_17 ( V_213 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
return F_155 ( V_2 , 1 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
return F_155 ( V_2 , 0 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
V_2 -> V_112 |= V_235 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( V_236 , V_237 ,
NULL ) ;
if ( ! V_18 )
return;
if ( ( V_18 -> V_22 < 0x3B ) && ( V_18 -> V_22 >= 0x30 ) )
V_2 -> V_112 |= V_235 ;
F_17 ( V_18 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 < 0x18 ) {
F_6 ( & V_2 -> V_2 , L_95 ) ;
V_2 -> V_112 |= V_235 ;
}
}
static void F_163 ( struct V_1 * V_2 )
{
V_2 -> V_238 = 1 ;
}
static void F_164 ( struct V_1 * V_2 )
{
T_3 V_239 ;
T_3 V_240 ;
T_3 V_241 ;
if ( F_96 ( V_2 -> V_86 ) )
return;
F_5 ( V_2 , 0xB7 , & V_241 ) ;
if ( V_241 & 0x02 )
return;
F_5 ( V_2 , 0x8E , & V_239 ) ;
F_7 ( V_2 , 0x8E , 0xAA ) ;
F_5 ( V_2 , 0x8D , & V_240 ) ;
F_7 ( V_2 , 0x8D , 0xB7 ) ;
F_7 ( V_2 , 0xB7 , V_241 | 0x02 ) ;
F_7 ( V_2 , 0x8E , V_239 ) ;
F_7 ( V_2 , 0x8D , V_240 ) ;
F_165 ( & V_2 -> V_2 , L_96 ) ;
F_165 ( & V_2 -> V_2 , L_97 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
T_3 V_239 ;
T_3 V_241 ;
if ( F_96 ( V_2 -> V_86 ) )
return;
if ( V_2 -> V_91 == V_242 ||
V_2 -> V_91 == V_243 ) {
F_7 ( V_2 , 0xf9 , 0xfc ) ;
F_7 ( V_2 , 0x150 , 0x10 ) ;
F_7 ( V_2 , 0xf9 , 0x00 ) ;
F_7 ( V_2 , 0xfc , 0x01 ) ;
F_7 ( V_2 , 0xe1 , 0x32 ) ;
F_7 ( V_2 , 0xfc , 0x00 ) ;
F_165 ( & V_2 -> V_2 , L_98 ) ;
}
F_5 ( V_2 , 0xCB , & V_241 ) ;
if ( V_241 & 0x02 )
return;
F_5 ( V_2 , 0xCA , & V_239 ) ;
F_7 ( V_2 , 0xCA , 0x57 ) ;
F_7 ( V_2 , 0xCB , V_241 | 0x02 ) ;
F_7 ( V_2 , 0xCA , V_239 ) ;
F_165 ( & V_2 -> V_2 , L_99 ) ;
F_165 ( & V_2 -> V_2 , L_97 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
T_1 V_244 ;
F_10 ( V_2 , V_245 , & V_244 ) ;
F_68 ( V_2 , V_245 , V_244 | V_246 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
T_1 V_55 = V_2 -> V_55 ;
V_2 -> V_55 = V_247 << 8 ;
F_6 ( & V_2 -> V_2 , L_100 ,
V_55 , V_2 -> V_55 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
V_2 -> V_248 = 1 ;
}
static void F_170 ( struct V_1 * V_2 )
{
int V_249 ;
T_2 V_250 ;
if ( V_251 == V_252 ||
V_251 == V_253 )
return;
V_249 = F_33 ( V_2 , 0x48 , & V_250 ) ;
if ( V_249 ) {
F_171 ( & V_2 -> V_2 , L_101 ) ;
return;
}
if ( ! ( V_250 & ( 1 << 10 ) ) )
return;
V_250 &= ~ ( 1 << 10 ) ;
V_249 = F_54 ( V_2 , 0x48 , V_250 ) ;
if ( V_249 ) {
F_171 ( & V_2 -> V_2 , L_102 ) ;
return;
}
F_172 ( L_103 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
int V_254 ;
T_3 V_76 ;
V_254 = F_5 ( V_2 , 0x00D0 , & V_76 ) ;
if ( V_254 )
return;
V_2 -> V_31 [ 2 ] . V_36 = V_2 -> V_31 [ 2 ] . V_37 + ( ( V_255 ) 1 << V_76 ) - 1 ;
V_254 = F_5 ( V_2 , 0x00D1 , & V_76 ) ;
if ( V_254 )
return;
V_2 -> V_31 [ 4 ] . V_36 = V_2 -> V_31 [ 4 ] . V_37 + ( ( V_255 ) 1 << V_76 ) - 1 ;
}
static T_6 F_174 ( struct V_1 * V_2 ,
void (* F_175)( struct V_1 * V_2 ) )
{
T_6 V_256 = 0 ;
F_176 ( & V_2 -> V_2 , L_104 , F_175 ) ;
if ( V_257 ) {
F_177 ( L_105 ,
F_175 , F_178 ( V_258 ) , F_179 ( & V_2 -> V_2 ) ) ;
V_256 = F_180 () ;
}
return V_256 ;
}
static void F_181 ( struct V_1 * V_2 , T_6 V_256 ,
void (* F_175)( struct V_1 * V_2 ) )
{
T_6 V_259 , V_260 ;
unsigned long long V_261 ;
if ( V_257 ) {
V_260 = F_180 () ;
V_259 = F_182 ( V_260 , V_256 ) ;
V_261 = ( unsigned long long ) F_183 ( V_259 ) >> 10 ;
F_177 ( L_106 ,
F_175 , V_261 , F_179 ( & V_2 -> V_2 ) ) ;
}
}
static void F_184 ( struct V_1 * V_2 )
{
void T_4 * V_262 = F_185 ( V_2 , 0 , 0 ) ;
if ( V_262 == NULL ) {
F_52 ( & V_2 -> V_2 , L_107 ) ;
return;
}
if ( F_87 ( V_262 + V_263 ) != 0 ) {
F_52 ( & V_2 -> V_2 , L_108 ) ;
F_88 ( 0 , V_262 + V_263 ) ;
}
F_186 ( V_2 , V_262 ) ;
}
static void F_187 ( struct V_1 * V_2 )
{
V_2 -> V_264 = 0 ;
}
static void F_188 ( struct V_1 * V_2 )
{
V_2 -> V_265 = 1 ;
}
static void F_189 ( struct V_1 * V_54 )
{
T_7 T_4 * V_266 ;
T_2 V_267 ;
T_2 V_268 ;
T_2 V_269 ;
T_1 V_270 ;
T_1 V_271 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < F_190 ( V_272 ) ; V_29 ++ ) {
if ( V_54 -> V_91 == V_272 [ V_29 ] ) {
V_54 -> V_265 = 1 ;
return;
}
}
if ( V_54 -> V_91 == V_273 )
return;
if ( V_54 -> V_91 != V_274 &&
V_54 -> V_91 != V_275 )
return;
if ( F_191 ( V_54 ) ) {
F_52 ( & V_54 -> V_2 , L_109 ) ;
return;
}
V_266 = F_118 ( F_100 ( V_54 , 0 ) , 4 ) ;
if ( ! V_266 ) {
F_52 ( & V_54 -> V_2 , L_110 ) ;
goto V_230;
}
V_270 = F_192 ( V_266 ) ;
V_271 = F_192 ( V_266 + 1 ) ;
V_267 = V_270 & 0xffff ;
V_268 = V_270 >> 16 ;
V_269 = V_271 & 0xffff ;
if ( V_268 > V_276 ||
V_268 < V_277 ) {
F_52 ( & V_54 -> V_2 , L_111 ,
V_267 , V_268 , V_269 , V_54 -> V_91 ==
V_274 ? 12 : 14 ) ;
V_54 -> V_265 = 1 ;
}
F_90 ( V_266 ) ;
V_230:
F_193 ( V_54 ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
V_2 -> V_112 |= V_278 ;
}
static void F_195 ( struct V_1 * V_2 )
{
if ( ! F_196 ( V_2 -> V_51 ) )
V_2 -> V_112 |= V_279 ;
}
static void F_197 ( struct V_1 * V_54 )
{
if ( V_54 -> V_238 &&
( V_54 -> V_91 != V_280 ||
V_54 -> V_22 <= 1 ) )
V_54 -> V_156 = 1 ;
}
static void F_198 ( struct V_1 * V_2 )
{
F_199 ( V_2 , 8192 ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
T_8 V_281 , V_282 , V_283 , V_284 ;
if ( ! F_201 ( V_285 , L_112 ) )
return;
if ( F_202 ( V_2 ) != V_286 )
return;
V_281 = F_203 ( & V_2 -> V_2 ) ;
if ( ! V_281 )
return;
if ( F_204 ( F_205 ( V_281 , L_113 , & V_282 ) )
|| F_204 ( F_205 ( V_281 , L_114 , & V_283 ) )
|| F_204 ( F_205 ( V_281 , L_115 , & V_284 ) ) )
return;
F_6 ( & V_2 -> V_2 , L_116 ) ;
F_206 ( V_282 , NULL , 1 ) ;
F_206 ( V_283 , NULL , 0 ) ;
F_207 ( 300 ) ;
F_206 ( V_284 , NULL , 0 ) ;
F_206 ( V_282 , NULL , 0 ) ;
F_206 ( V_284 , NULL , 0 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_1 * V_287 = NULL ;
struct V_1 * V_288 = NULL ;
if ( ! F_201 ( V_285 , L_112 ) )
return;
if ( F_202 ( V_2 ) != V_289 )
return;
V_287 = F_115 ( V_2 -> V_51 , 0x0 ) ;
if ( V_287 == V_2 )
goto V_230;
if ( ! V_287 || ! V_287 -> V_87 )
goto V_230;
V_288 = F_115 ( V_287 -> V_87 , 0x0 ) ;
if ( ! V_288 )
goto V_230;
if ( V_288 -> V_163 != V_7
|| ( V_288 -> V_91 != V_290 &&
V_288 -> V_91 != V_280 &&
V_288 -> V_91 != V_291 &&
V_288 -> V_91 != V_292 )
|| V_288 -> V_55 != V_293 << 8 )
goto V_230;
F_6 ( & V_2 -> V_2 , L_117 ) ;
F_209 ( & V_2 -> V_2 , & V_288 -> V_2 ) ;
V_230:
F_17 ( V_288 ) ;
F_17 ( V_287 ) ;
}
static void F_210 ( struct V_1 * V_2 , struct V_294 * V_295 ,
struct V_294 * V_36 )
{
T_6 V_256 ;
for (; V_295 < V_36 ; V_295 ++ )
if ( ( V_295 -> V_55 == ( T_1 ) ( V_2 -> V_55 >> V_295 -> V_296 ) ||
V_295 -> V_55 == ( T_1 ) V_297 ) &&
( V_295 -> V_163 == V_2 -> V_163 ||
V_295 -> V_163 == ( T_2 ) V_297 ) &&
( V_295 -> V_91 == V_2 -> V_91 ||
V_295 -> V_91 == ( T_2 ) V_297 ) ) {
V_256 = F_174 ( V_2 , V_295 -> V_298 ) ;
V_295 -> V_298 ( V_2 ) ;
F_181 ( V_2 , V_256 , V_295 -> V_298 ) ;
}
}
void F_211 ( enum V_299 V_300 , struct V_1 * V_2 )
{
struct V_294 * V_37 , * V_36 ;
switch ( V_300 ) {
case V_301 :
V_37 = V_302 ;
V_36 = V_303 ;
break;
case V_304 :
V_37 = V_305 ;
V_36 = V_306 ;
break;
case V_307 :
if ( ! V_308 )
return;
V_37 = V_309 ;
V_36 = V_310 ;
break;
case V_311 :
V_37 = V_312 ;
V_36 = V_313 ;
break;
case V_314 :
V_37 = V_315 ;
V_36 = V_316 ;
break;
case V_317 :
V_37 = V_318 ;
V_36 = V_319 ;
break;
case V_320 :
V_37 = V_321 ;
V_36 = V_322 ;
break;
case V_323 :
V_37 = V_324 ;
V_36 = V_325 ;
break;
default:
return;
}
F_210 ( V_2 , V_37 , V_36 ) ;
}
static int T_9 F_212 ( void )
{
struct V_1 * V_2 = NULL ;
T_3 V_326 = 0 ;
T_3 V_80 ;
if ( V_327 )
F_149 ( V_328 L_118 ,
V_327 << 2 ) ;
V_308 = true ;
F_213 (dev) {
F_211 ( V_307 , V_2 ) ;
if ( ! V_327 ) {
F_5 ( V_2 , V_329 , & V_80 ) ;
if ( ! V_326 )
V_326 = V_80 ;
if ( ! V_80 || V_326 == V_80 )
continue;
F_149 ( V_328 L_119 ,
V_326 << 2 , V_80 << 2 ,
V_330 << 2 ) ;
V_327 = V_330 ;
}
}
if ( ! V_327 ) {
F_149 ( V_328 L_120 ,
V_326 << 2 , V_330 << 2 ) ;
V_327 = V_326 ? V_326 : V_330 ;
}
return 0 ;
}
static int F_214 ( struct V_1 * V_2 , int V_331 )
{
if ( V_331 )
return 0 ;
if ( ! F_215 ( V_2 ) )
F_171 ( & V_2 -> V_2 , L_121 ) ;
F_216 ( V_2 , V_332 , V_333 ) ;
F_207 ( 100 ) ;
return 0 ;
}
static int F_217 ( struct V_1 * V_2 , int V_331 )
{
void T_4 * V_334 ;
unsigned long V_335 ;
T_1 V_76 ;
if ( V_331 )
return 0 ;
V_334 = F_185 ( V_2 , 0 , 0 ) ;
if ( ! V_334 )
return - V_336 ;
F_218 ( 0x00000002 , V_334 + V_337 ) ;
F_218 ( 0x00000005 , V_334 + V_338 ) ;
V_76 = F_219 ( V_334 + V_339 ) & 0xfffffffe ;
F_218 ( V_76 , V_334 + V_339 ) ;
V_335 = V_340 + F_220 ( V_341 ) ;
do {
V_76 = F_219 ( V_334 + V_342 ) ;
if ( ( V_76 & 0xb0000000 ) == 0 )
goto V_343;
F_207 ( 10 ) ;
} while ( F_221 ( V_340 , V_335 ) );
F_52 ( & V_2 -> V_2 , L_122 ) ;
V_343:
F_218 ( 0x00000002 , V_334 + V_344 ) ;
F_186 ( V_2 , V_334 ) ;
return 0 ;
}
static int F_222 ( struct V_1 * V_2 , int V_331 )
{
T_2 V_345 ;
T_2 V_346 ;
if ( ( V_2 -> V_91 & 0xf000 ) != 0x4000 )
return - V_347 ;
if ( V_331 )
return 0 ;
F_33 ( V_2 , V_78 , & V_345 ) ;
F_54 ( V_2 , V_78 ,
V_345 | V_348 ) ;
F_223 ( V_2 ) ;
F_33 ( V_2 , V_2 -> V_349 + V_350 , & V_346 ) ;
if ( ( V_346 & V_351 ) == 0 )
F_54 ( V_2 , V_2 -> V_349 + V_350 ,
V_346 |
V_351 |
V_352 ) ;
if ( ! F_215 ( V_2 ) )
F_171 ( & V_2 -> V_2 , L_121 ) ;
F_216 ( V_2 , V_332 , V_333 ) ;
F_207 ( 100 ) ;
F_224 ( V_2 ) ;
F_54 ( V_2 , V_78 , V_345 ) ;
return 0 ;
}
int F_225 ( struct V_1 * V_2 , int V_331 )
{
const struct V_353 * V_29 ;
for ( V_29 = V_353 ; V_29 -> V_354 ; V_29 ++ ) {
if ( ( V_29 -> V_163 == V_2 -> V_163 ||
V_29 -> V_163 == ( T_2 ) V_297 ) &&
( V_29 -> V_91 == V_2 -> V_91 ||
V_29 -> V_91 == ( T_2 ) V_297 ) )
return V_29 -> V_354 ( V_2 , V_331 ) ;
}
return - V_347 ;
}
static void F_226 ( struct V_1 * V_2 )
{
if ( F_96 ( V_2 -> V_86 ) != 0 )
F_227 ( V_2 , F_116 ( F_63 ( V_2 -> V_86 ) , 0 ) ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
if ( F_96 ( V_2 -> V_86 ) != 1 )
F_227 ( V_2 , F_116 ( F_63 ( V_2 -> V_86 ) , 1 ) ) ;
}
static void F_229 ( struct V_1 * V_2 )
{
const struct V_355 * V_356 ;
V_356 = F_230 ( V_357 , V_2 ) ;
if ( V_356 )
F_227 ( V_2 , V_356 -> V_358 ) ;
}
static void F_231 ( struct V_1 * V_54 )
{
if ( ! F_196 ( V_54 -> V_51 ) &&
V_54 -> V_152 == V_359 &&
! F_232 ( V_54 ) && F_232 ( V_54 -> V_51 -> V_360 ) &&
F_202 ( V_54 -> V_51 -> V_360 ) != V_361 )
V_54 -> V_112 |= V_362 ;
}
static void F_233 ( struct V_1 * V_54 )
{
F_227 ( V_54 , F_116 ( 0x10 , 0x0 ) ) ;
F_227 ( V_54 , F_116 ( 0x11 , 0x0 ) ) ;
F_227 ( V_54 , F_116 ( 0x12 , 0x3 ) ) ;
}
static void F_234 ( struct V_1 * V_54 )
{
T_1 V_55 = V_54 -> V_55 ;
V_54 -> V_55 = ( V_363 << 8 ) | 0x01 ;
F_6 ( & V_54 -> V_2 , L_123 ,
V_55 , V_54 -> V_55 ) ;
}
static void F_235 ( struct V_1 * V_54 )
{
struct V_1 * V_364 = F_236 ( V_54 ) ;
if ( ! V_364 ) {
F_52 ( & V_54 -> V_2 , L_124 ) ;
return;
}
F_6 ( & V_364 -> V_2 , L_125 ,
F_179 ( & V_54 -> V_2 ) ) ;
F_237 ( V_364 , V_332 ,
V_365 |
V_366 , 0 ) ;
}
static void F_238 ( struct V_1 * V_54 )
{
if ( ( V_54 -> V_91 & 0xff00 ) == 0x5400 )
F_235 ( V_54 ) ;
}
static int F_239 ( struct V_1 * V_2 , T_2 V_367 )
{
#ifdef F_240
struct V_368 * V_369 = NULL ;
T_10 V_370 ;
if ( ! V_2 -> V_153 || ! F_196 ( V_2 -> V_51 ) )
return - V_371 ;
V_370 = F_241 ( L_126 , 0 , & V_369 ) ;
if ( F_204 ( V_370 ) )
return - V_371 ;
V_367 &= ( V_372 | V_373 | V_374 | V_375 ) ;
return V_367 & ~ ( V_372 | V_373 ) ? 0 : 1 ;
#else
return - V_371 ;
#endif
}
static int F_242 ( struct V_1 * V_2 , T_2 V_367 )
{
V_367 &= ~ ( V_376 | V_377 | V_372 |
V_373 | V_378 | V_375 ) ;
return V_367 ? 0 : 1 ;
}
static bool F_243 ( struct V_1 * V_2 )
{
int V_29 ;
if ( ! F_232 ( V_2 ) || F_202 ( V_2 ) != V_379 )
return false ;
for ( V_29 = 0 ; V_29 < F_190 ( V_380 ) ; V_29 ++ )
if ( V_380 [ V_29 ] == V_2 -> V_91 )
return true ;
return false ;
}
static int F_244 ( struct V_1 * V_2 , T_2 V_367 )
{
T_2 V_33 = V_2 -> V_112 & V_381 ?
V_382 : 0 ;
if ( ! F_243 ( V_2 ) )
return - V_347 ;
return V_367 & ~ V_33 ? 0 : 1 ;
}
static bool F_245 ( struct V_1 * V_2 )
{
return F_232 ( V_2 ) &&
F_202 ( V_2 ) == V_379 &&
( ( V_2 -> V_91 & ~ 0xf ) == 0xa110 ||
( V_2 -> V_91 >= 0xa167 && V_2 -> V_91 <= 0xa16a ) ) ;
}
static int F_246 ( struct V_1 * V_2 , T_2 V_367 )
{
int V_39 ;
T_1 V_383 , V_229 ;
if ( ! F_245 ( V_2 ) )
return - V_347 ;
V_39 = F_247 ( V_2 , V_384 ) ;
if ( ! V_39 )
return - V_347 ;
F_10 ( V_2 , V_39 + V_385 , & V_383 ) ;
V_367 &= ( V_383 | V_374 ) ;
F_10 ( V_2 , V_39 + V_386 , & V_229 ) ;
return V_367 & ~ V_229 ? 0 : 1 ;
}
static int F_248 ( struct V_1 * V_2 , T_2 V_367 )
{
V_367 &= ~ ( V_376 | V_377 | V_372 |
V_373 | V_378 | V_375 ) ;
return V_367 ? 0 : 1 ;
}
int F_249 ( struct V_1 * V_2 , T_2 V_367 )
{
const struct V_387 * V_29 ;
int V_388 ;
for ( V_29 = V_387 ; V_29 -> V_389 ; V_29 ++ ) {
if ( ( V_29 -> V_163 == V_2 -> V_163 ||
V_29 -> V_163 == ( T_2 ) V_297 ) &&
( V_29 -> V_91 == V_2 -> V_91 ||
V_29 -> V_91 == ( T_2 ) V_297 ) ) {
V_388 = V_29 -> V_389 ( V_2 , V_367 ) ;
if ( V_388 >= 0 )
return V_388 ;
}
}
return - V_347 ;
}
static int F_250 ( struct V_1 * V_2 )
{
T_1 V_134 , V_390 , V_391 ;
void T_4 * V_392 ;
F_251 ( V_2 -> V_51 , F_116 ( 31 , 0 ) ,
V_393 , & V_134 ) ;
if ( ! ( V_134 & V_394 ) )
return - V_395 ;
V_392 = F_85 ( V_134 & V_396 ,
F_252 ( V_397 ) ) ;
if ( ! V_392 )
return - V_336 ;
V_390 = F_87 ( V_392 + V_398 ) ;
V_390 &= V_399 | V_400 ;
if ( V_390 != ( V_399 | V_400 ) ) {
V_391 = F_87 ( V_392 + V_397 ) ;
if ( V_391 & V_401 ) {
F_6 ( & V_2 -> V_2 , L_127 ) ;
V_391 &= ~ V_401 ;
F_88 ( V_391 , V_392 + V_397 ) ;
}
}
F_90 ( V_392 ) ;
return 0 ;
}
static void F_253 ( struct V_1 * V_2 )
{
T_1 V_402 ;
F_10 ( V_2 , V_403 , & V_402 ) ;
if ( ! ( V_402 & V_404 ) ) {
F_6 ( & V_2 -> V_2 , L_128 ) ;
V_402 |= V_404 ;
F_54 ( V_2 , V_403 , V_402 ) ;
}
}
static int F_254 ( struct V_1 * V_2 )
{
if ( ! F_243 ( V_2 ) )
return - V_347 ;
if ( F_250 ( V_2 ) ) {
F_52 ( & V_2 -> V_2 , L_129 ) ;
return 0 ;
}
F_253 ( V_2 ) ;
V_2 -> V_112 |= V_381 ;
F_6 ( & V_2 -> V_2 , L_130 ) ;
return 0 ;
}
static int F_255 ( struct V_1 * V_2 )
{
int V_39 ;
T_1 V_383 , V_229 ;
if ( ! F_245 ( V_2 ) )
return - V_347 ;
V_39 = F_247 ( V_2 , V_384 ) ;
if ( ! V_39 )
return - V_347 ;
F_10 ( V_2 , V_39 + V_385 , & V_383 ) ;
F_10 ( V_2 , V_39 + V_386 , & V_229 ) ;
V_229 |= ( V_383 & V_376 ) ;
V_229 |= ( V_383 & V_372 ) ;
V_229 |= ( V_383 & V_373 ) ;
V_229 |= ( V_383 & V_378 ) ;
F_68 ( V_2 , V_39 + V_386 , V_229 ) ;
F_6 ( & V_2 -> V_2 , L_131 ) ;
return 0 ;
}
int F_256 ( struct V_1 * V_2 )
{
const struct V_405 * V_29 ;
int V_388 ;
for ( V_29 = V_405 ; V_29 -> V_406 ; V_29 ++ ) {
if ( ( V_29 -> V_163 == V_2 -> V_163 ||
V_29 -> V_163 == ( T_2 ) V_297 ) &&
( V_29 -> V_91 == V_2 -> V_91 ||
V_29 -> V_91 == ( T_2 ) V_297 ) ) {
V_388 = V_29 -> V_406 ( V_2 ) ;
if ( V_388 >= 0 )
return V_388 ;
}
}
return - V_347 ;
}
static void F_257 ( struct V_1 * V_54 )
{
int V_39 , V_29 = 0 ;
T_3 V_407 ;
T_2 V_408 , * V_383 ;
struct V_409 * V_410 ;
if ( V_54 -> V_411 || F_148 ( V_54 , V_412 ) )
return;
V_39 = F_148 ( V_54 , V_413 ) ;
if ( ! V_39 )
return;
F_5 ( V_54 , V_39 + 1 , & V_407 ) ;
if ( V_407 )
return;
V_39 = 0x50 ;
F_33 ( V_54 , V_39 , & V_408 ) ;
if ( V_408 == ( 0x0000 | V_412 ) ) {
T_1 V_370 ;
#ifndef F_258
#define F_258 7
#endif
int V_40 = F_258 * sizeof( T_2 ) ;
V_54 -> V_411 = V_39 ;
F_33 ( V_54 , V_39 + V_414 , & V_408 ) ;
V_54 -> V_415 = V_408 ;
F_33 ( V_54 , V_39 + V_416 , & V_408 ) ;
V_54 -> V_248 = V_408 & V_417 ;
V_54 -> V_28 = V_418 ;
if ( F_10 ( V_54 , V_419 , & V_370 ) !=
V_420 || ( V_370 == 0xffffffff ) )
V_54 -> V_28 = V_419 ;
if ( F_259 ( V_54 , V_412 ) )
return;
V_410 = F_260 ( sizeof( * V_410 ) + V_40 , V_421 ) ;
if ( ! V_410 )
return;
V_410 -> V_383 . V_422 = V_412 ;
V_410 -> V_383 . V_423 = 0 ;
V_410 -> V_383 . V_40 = V_40 ;
V_383 = ( T_2 * ) & V_410 -> V_383 . V_424 [ 0 ] ;
F_261 ( V_54 , V_332 , & V_383 [ V_29 ++ ] ) ;
F_261 ( V_54 , V_425 , & V_383 [ V_29 ++ ] ) ;
F_261 ( V_54 , V_426 , & V_383 [ V_29 ++ ] ) ;
F_261 ( V_54 , V_427 , & V_383 [ V_29 ++ ] ) ;
F_261 ( V_54 , V_428 , & V_383 [ V_29 ++ ] ) ;
F_261 ( V_54 , V_429 , & V_383 [ V_29 ++ ] ) ;
F_261 ( V_54 , V_430 , & V_383 [ V_29 ++ ] ) ;
F_262 ( & V_410 -> V_431 , & V_54 -> V_432 ) ;
}
}
static void F_263 ( struct V_1 * V_54 )
{
if ( V_54 -> V_51 -> V_433 && F_264 ( V_54 -> V_51 ) >= 0x10000 )
V_54 -> V_51 -> V_88 |= V_434 ;
}
