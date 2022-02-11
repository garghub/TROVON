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
static void F_132 ( struct V_1 * V_54 )
{
if ( V_54 -> V_152 == V_211 )
V_54 -> V_55 = V_212 << 8 ;
V_54 -> V_213 = 2 ;
}
static void F_133 ( struct V_1 * V_2 )
{
T_3 V_74 ;
if ( F_5 ( V_2 , 0xF4 , & V_74 ) == 0 && ! ( V_74 & 0x02 ) ) {
F_6 ( & V_2 -> V_2 , L_82 ) ;
F_7 ( V_2 , 0xF4 , V_74 | 0x02 ) ;
}
}
static void F_134 ( struct V_1 * V_2 )
{
if ( V_214 ) {
F_68 ( V_2 , 0x98 , 0x1 ) ;
F_135 ( 50 ) ;
}
}
static void F_136 ( struct V_1 * V_2 )
{
F_137 () ;
F_52 ( & V_2 -> V_2 , L_83 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
if ( V_2 -> V_87 ) {
F_52 ( & V_2 -> V_2 , L_84 ) ;
V_2 -> V_87 -> V_88 |= V_215 ;
}
}
static void F_139 ( struct V_1 * V_216 )
{
struct V_1 * V_217 ;
V_217 = F_115 ( V_216 -> V_51 , F_116 ( 1 , 0 ) ) ;
if ( V_217 ) {
if ( V_217 -> V_91 == 0x9602 )
F_138 ( V_217 ) ;
F_17 ( V_217 ) ;
}
}
static int F_140 ( struct V_1 * V_2 )
{
int V_39 , V_218 = V_219 ;
V_39 = F_141 ( V_2 , V_220 ) ;
while ( V_39 && V_218 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_221 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_85 ,
V_33 & V_222 ?
L_86 : L_87 ) ;
return ( V_33 & V_222 ) != 0 ;
}
V_39 = F_142 ( V_2 , V_39 ,
V_220 ) ;
}
return 0 ;
}
static void F_143 ( struct V_1 * V_2 )
{
if ( V_2 -> V_87 && ! F_140 ( V_2 ) ) {
F_52 ( & V_2 -> V_2 , L_84 ) ;
V_2 -> V_87 -> V_88 |= V_215 ;
}
}
static void F_144 ( struct V_1 * V_2 )
{
struct V_1 * V_54 ;
if ( ! V_2 -> V_87 )
return;
V_54 = F_115 ( V_2 -> V_51 , 0 ) ;
if ( ! V_54 )
return;
if ( ! F_140 ( V_2 ) && ! F_140 ( V_54 ) ) {
F_52 ( & V_2 -> V_2 , L_84 ) ;
V_2 -> V_87 -> V_88 |= V_215 ;
}
F_17 ( V_54 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
int V_39 , V_218 = V_219 ;
V_39 = F_141 ( V_2 , V_220 ) ;
while ( V_39 && V_218 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_221 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_88 ) ;
F_7 ( V_2 , V_39 + V_221 ,
V_33 | V_222 ) ;
}
V_39 = F_142 ( V_2 , V_39 ,
V_220 ) ;
}
}
static void F_146 ( struct V_1 * V_2 )
{
const char * V_223 = F_147 ( V_224 ) ;
if ( V_223 &&
( strstr ( V_223 , L_89 ) ||
strstr ( V_223 , L_90 ) ) ) {
F_6 ( & V_2 -> V_2 , L_91 ) ;
V_2 -> V_156 = 1 ;
}
}
static void F_148 ( struct V_1 * V_2 )
{
T_1 V_225 ;
if ( ! F_149 ( V_2 , V_226 ) )
return;
F_10 ( V_2 , 0x74 , & V_225 ) ;
if ( V_225 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_150 ( V_227 L_92 ) ;
V_225 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_68 ( V_2 , 0x74 , V_225 ) ;
}
}
static int F_151 ( struct V_1 * V_2 )
{
int V_39 , V_218 = V_219 ;
int V_228 = 0 ;
V_39 = F_141 ( V_2 , V_220 ) ;
while ( V_39 && V_218 -- ) {
T_3 V_33 ;
if ( V_228 < 1 )
V_228 = 1 ;
if ( F_5 ( V_2 , V_39 + V_221 ,
& V_33 ) == 0 ) {
if ( V_33 & V_222 ) {
if ( V_228 < 2 ) {
V_228 = 2 ;
break;
}
}
}
V_39 = F_142 ( V_2 , V_39 ,
V_220 ) ;
}
return V_228 ;
}
static int F_152 ( struct V_1 * V_216 )
{
struct V_1 * V_2 ;
int V_39 ;
int V_29 , V_229 ;
int V_228 = 0 ;
V_229 = V_216 -> V_86 >> 3 ;
for ( V_29 = V_229 + 1 ; V_29 < 0x20 ; V_29 ++ ) {
V_2 = F_115 ( V_216 -> V_51 , F_116 ( V_29 , 0 ) ) ;
if ( ! V_2 )
continue;
V_39 = F_141 ( V_2 , V_230 ) ;
if ( V_39 != 0 ) {
F_17 ( V_2 ) ;
break;
}
if ( F_151 ( V_2 ) ) {
V_228 = 1 ;
F_17 ( V_2 ) ;
break;
}
F_17 ( V_2 ) ;
}
return V_228 ;
}
static int F_153 ( struct V_1 * V_2 )
{
int V_39 , V_231 ;
int V_36 = 0 ;
T_2 V_33 , V_232 ;
V_39 = F_141 ( V_2 , V_230 ) ;
if ( ! V_39 )
goto V_233;
F_33 ( V_2 , V_39 + V_234 , & V_33 ) ;
V_231 = ( ( V_33 >> 10 ) & 1 ) ?
V_235 : V_236 ;
F_33 ( V_2 , V_39 + V_231 , & V_232 ) ;
if ( V_232 & ( 1 << 6 ) )
V_36 = 1 ;
V_233:
return V_36 ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_1 * V_216 ;
int V_39 ;
int V_29 , V_229 ;
int V_228 = 0 ;
V_229 = V_2 -> V_86 >> 3 ;
for ( V_29 = V_229 ; V_29 >= 0 ; V_29 -- ) {
V_216 = F_115 ( V_2 -> V_51 , F_116 ( V_29 , 0 ) ) ;
if ( ! V_216 )
continue;
V_39 = F_141 ( V_216 , V_230 ) ;
if ( V_39 != 0 ) {
V_228 = 1 ;
break;
}
F_17 ( V_216 ) ;
}
if ( ! V_228 )
return;
if ( V_216 == V_2 && F_153 ( V_216 ) &&
F_152 ( V_216 ) )
goto V_233;
if ( F_140 ( V_216 ) )
goto V_233;
F_145 ( V_2 ) ;
V_233:
F_17 ( V_216 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
int V_39 , V_218 = V_219 ;
V_39 = F_141 ( V_2 , V_220 ) ;
while ( V_39 && V_218 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_221 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_93 ) ;
F_7 ( V_2 , V_39 + V_221 ,
V_33 & ~ V_222 ) ;
}
V_39 = F_142 ( V_2 , V_39 ,
V_220 ) ;
}
}
static void F_156 ( struct V_1 * V_2 , int V_237 )
{
struct V_1 * V_216 ;
int V_39 ;
int V_228 ;
if ( ! F_157 () )
return;
V_228 = F_151 ( V_2 ) ;
if ( V_228 == 0 )
return;
V_216 = F_158 ( 0 , F_116 ( 0 , 0 ) ) ;
if ( V_216 == NULL ) {
F_52 ( & V_2 -> V_2 , L_94 ) ;
return;
}
V_39 = F_141 ( V_216 , V_230 ) ;
if ( V_39 != 0 ) {
if ( V_228 == 1 ) {
if ( V_237 )
F_145 ( V_2 ) ;
else
F_154 ( V_2 ) ;
}
goto V_233;
}
if ( V_228 == 1 )
goto V_233;
F_155 ( V_2 ) ;
V_233:
F_17 ( V_216 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
return F_156 ( V_2 , 1 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
return F_156 ( V_2 , 0 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
V_2 -> V_112 |= V_238 ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( V_239 , V_240 ,
NULL ) ;
if ( ! V_18 )
return;
if ( ( V_18 -> V_22 < 0x3B ) && ( V_18 -> V_22 >= 0x30 ) )
V_2 -> V_112 |= V_238 ;
F_17 ( V_18 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 < 0x18 ) {
F_6 ( & V_2 -> V_2 , L_95 ) ;
V_2 -> V_112 |= V_238 ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
V_2 -> V_241 = 1 ;
}
static void F_165 ( struct V_1 * V_2 )
{
T_3 V_242 ;
T_3 V_243 ;
T_3 V_244 ;
if ( F_96 ( V_2 -> V_86 ) )
return;
F_5 ( V_2 , 0xB7 , & V_244 ) ;
if ( V_244 & 0x02 )
return;
F_5 ( V_2 , 0x8E , & V_242 ) ;
F_7 ( V_2 , 0x8E , 0xAA ) ;
F_5 ( V_2 , 0x8D , & V_243 ) ;
F_7 ( V_2 , 0x8D , 0xB7 ) ;
F_7 ( V_2 , 0xB7 , V_244 | 0x02 ) ;
F_7 ( V_2 , 0x8E , V_242 ) ;
F_7 ( V_2 , 0x8D , V_243 ) ;
F_166 ( & V_2 -> V_2 , L_96 ) ;
F_166 ( & V_2 -> V_2 , L_97 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
T_3 V_242 ;
T_3 V_244 ;
if ( F_96 ( V_2 -> V_86 ) )
return;
if ( V_2 -> V_91 == V_245 ||
V_2 -> V_91 == V_246 ) {
F_7 ( V_2 , 0xf9 , 0xfc ) ;
F_7 ( V_2 , 0x150 , 0x10 ) ;
F_7 ( V_2 , 0xf9 , 0x00 ) ;
F_7 ( V_2 , 0xfc , 0x01 ) ;
F_7 ( V_2 , 0xe1 , 0x32 ) ;
F_7 ( V_2 , 0xfc , 0x00 ) ;
F_166 ( & V_2 -> V_2 , L_98 ) ;
}
F_5 ( V_2 , 0xCB , & V_244 ) ;
if ( V_244 & 0x02 )
return;
F_5 ( V_2 , 0xCA , & V_242 ) ;
F_7 ( V_2 , 0xCA , 0x57 ) ;
F_7 ( V_2 , 0xCB , V_244 | 0x02 ) ;
F_7 ( V_2 , 0xCA , V_242 ) ;
F_166 ( & V_2 -> V_2 , L_99 ) ;
F_166 ( & V_2 -> V_2 , L_97 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
T_1 V_247 ;
F_10 ( V_2 , V_248 , & V_247 ) ;
F_68 ( V_2 , V_248 , V_247 | V_249 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
T_1 V_55 = V_2 -> V_55 ;
V_2 -> V_55 = V_250 << 8 ;
F_6 ( & V_2 -> V_2 , L_100 ,
V_55 , V_2 -> V_55 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
V_2 -> V_213 = 1 ;
}
static void F_171 ( struct V_1 * V_2 )
{
int V_251 ;
T_2 V_252 ;
if ( V_253 == V_254 ||
V_253 == V_255 )
return;
V_251 = F_33 ( V_2 , 0x48 , & V_252 ) ;
if ( V_251 ) {
F_172 ( & V_2 -> V_2 , L_101 ) ;
return;
}
if ( ! ( V_252 & ( 1 << 10 ) ) )
return;
V_252 &= ~ ( 1 << 10 ) ;
V_251 = F_54 ( V_2 , 0x48 , V_252 ) ;
if ( V_251 ) {
F_172 ( & V_2 -> V_2 , L_102 ) ;
return;
}
F_173 ( L_103 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
int V_256 ;
T_3 V_76 ;
V_256 = F_5 ( V_2 , 0x00D0 , & V_76 ) ;
if ( V_256 )
return;
V_2 -> V_31 [ 2 ] . V_36 = V_2 -> V_31 [ 2 ] . V_37 + ( ( V_257 ) 1 << V_76 ) - 1 ;
V_256 = F_5 ( V_2 , 0x00D1 , & V_76 ) ;
if ( V_256 )
return;
V_2 -> V_31 [ 4 ] . V_36 = V_2 -> V_31 [ 4 ] . V_37 + ( ( V_257 ) 1 << V_76 ) - 1 ;
}
static T_6 F_175 ( struct V_1 * V_2 ,
void (* F_176)( struct V_1 * V_2 ) )
{
T_6 V_258 = 0 ;
F_177 ( & V_2 -> V_2 , L_104 , F_176 ) ;
if ( V_259 ) {
F_178 ( L_105 ,
F_176 , F_179 ( V_260 ) , F_180 ( & V_2 -> V_2 ) ) ;
V_258 = F_181 () ;
}
return V_258 ;
}
static void F_182 ( struct V_1 * V_2 , T_6 V_258 ,
void (* F_176)( struct V_1 * V_2 ) )
{
T_6 V_261 , V_262 ;
unsigned long long V_263 ;
if ( V_259 ) {
V_262 = F_181 () ;
V_261 = F_183 ( V_262 , V_258 ) ;
V_263 = ( unsigned long long ) F_184 ( V_261 ) >> 10 ;
F_178 ( L_106 ,
F_176 , V_263 , F_180 ( & V_2 -> V_2 ) ) ;
}
}
static void F_185 ( struct V_1 * V_2 )
{
void T_4 * V_264 = F_186 ( V_2 , 0 , 0 ) ;
if ( V_264 == NULL ) {
F_52 ( & V_2 -> V_2 , L_107 ) ;
return;
}
if ( F_87 ( V_264 + V_265 ) != 0 ) {
F_52 ( & V_2 -> V_2 , L_108 ) ;
F_88 ( 0 , V_264 + V_265 ) ;
}
F_187 ( V_2 , V_264 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
V_2 -> V_266 = 0 ;
}
static void F_189 ( struct V_1 * V_2 )
{
V_2 -> V_267 = 1 ;
}
static void F_190 ( struct V_1 * V_54 )
{
T_7 T_4 * V_268 ;
T_2 V_269 ;
T_2 V_270 ;
T_2 V_271 ;
T_1 V_272 ;
T_1 V_273 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < F_191 ( V_274 ) ; V_29 ++ ) {
if ( V_54 -> V_91 == V_274 [ V_29 ] ) {
V_54 -> V_267 = 1 ;
return;
}
}
if ( V_54 -> V_91 == V_275 )
return;
if ( V_54 -> V_91 != V_276 &&
V_54 -> V_91 != V_277 )
return;
if ( F_192 ( V_54 ) ) {
F_52 ( & V_54 -> V_2 , L_109 ) ;
return;
}
V_268 = F_118 ( F_100 ( V_54 , 0 ) , 4 ) ;
if ( ! V_268 ) {
F_52 ( & V_54 -> V_2 , L_110 ) ;
goto V_233;
}
V_272 = F_193 ( V_268 ) ;
V_273 = F_193 ( V_268 + 1 ) ;
V_269 = V_272 & 0xffff ;
V_270 = V_272 >> 16 ;
V_271 = V_273 & 0xffff ;
if ( V_270 > V_278 ||
V_270 < V_279 ) {
F_52 ( & V_54 -> V_2 , L_111 ,
V_269 , V_270 , V_271 , V_54 -> V_91 ==
V_276 ? 12 : 14 ) ;
V_54 -> V_267 = 1 ;
}
F_90 ( V_268 ) ;
V_233:
F_194 ( V_54 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
V_2 -> V_112 |= V_280 ;
}
static void F_196 ( struct V_1 * V_2 )
{
if ( ! F_197 ( V_2 -> V_51 ) )
V_2 -> V_112 |= V_281 ;
}
static void F_198 ( struct V_1 * V_54 )
{
if ( V_54 -> V_241 &&
( V_54 -> V_91 != V_282 ||
V_54 -> V_22 <= 1 ) )
V_54 -> V_156 = 1 ;
}
static void F_199 ( struct V_1 * V_2 )
{
F_200 ( V_2 , 8192 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
T_8 V_283 , V_284 , V_285 , V_286 ;
if ( ! F_202 ( V_287 , L_112 ) )
return;
if ( F_203 ( V_2 ) != V_288 )
return;
V_283 = F_204 ( & V_2 -> V_2 ) ;
if ( ! V_283 )
return;
if ( F_205 ( F_206 ( V_283 , L_113 , & V_284 ) )
|| F_205 ( F_206 ( V_283 , L_114 , & V_285 ) )
|| F_205 ( F_206 ( V_283 , L_115 , & V_286 ) ) )
return;
F_6 ( & V_2 -> V_2 , L_116 ) ;
F_207 ( V_284 , NULL , 1 ) ;
F_207 ( V_285 , NULL , 0 ) ;
F_208 ( 300 ) ;
F_207 ( V_286 , NULL , 0 ) ;
F_207 ( V_284 , NULL , 0 ) ;
F_207 ( V_286 , NULL , 0 ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
struct V_1 * V_289 = NULL ;
struct V_1 * V_290 = NULL ;
if ( ! F_202 ( V_287 , L_112 ) )
return;
if ( F_203 ( V_2 ) != V_291 )
return;
V_289 = F_115 ( V_2 -> V_51 , 0x0 ) ;
if ( V_289 == V_2 )
goto V_233;
if ( ! V_289 || ! V_289 -> V_87 )
goto V_233;
V_290 = F_115 ( V_289 -> V_87 , 0x0 ) ;
if ( ! V_290 )
goto V_233;
if ( V_290 -> V_163 != V_7
|| ( V_290 -> V_91 != V_292 &&
V_290 -> V_91 != V_282 &&
V_290 -> V_91 != V_293 &&
V_290 -> V_91 != V_294 )
|| V_290 -> V_55 != V_295 << 8 )
goto V_233;
F_6 ( & V_2 -> V_2 , L_117 ) ;
F_210 ( & V_2 -> V_2 , & V_290 -> V_2 ) ;
V_233:
F_17 ( V_290 ) ;
F_17 ( V_289 ) ;
}
static void F_211 ( struct V_1 * V_2 , struct V_296 * V_297 ,
struct V_296 * V_36 )
{
T_6 V_258 ;
for (; V_297 < V_36 ; V_297 ++ )
if ( ( V_297 -> V_55 == ( T_1 ) ( V_2 -> V_55 >> V_297 -> V_298 ) ||
V_297 -> V_55 == ( T_1 ) V_299 ) &&
( V_297 -> V_163 == V_2 -> V_163 ||
V_297 -> V_163 == ( T_2 ) V_299 ) &&
( V_297 -> V_91 == V_2 -> V_91 ||
V_297 -> V_91 == ( T_2 ) V_299 ) ) {
V_258 = F_175 ( V_2 , V_297 -> V_300 ) ;
V_297 -> V_300 ( V_2 ) ;
F_182 ( V_2 , V_258 , V_297 -> V_300 ) ;
}
}
void F_212 ( enum V_301 V_302 , struct V_1 * V_2 )
{
struct V_296 * V_37 , * V_36 ;
switch ( V_302 ) {
case V_303 :
V_37 = V_304 ;
V_36 = V_305 ;
break;
case V_306 :
V_37 = V_307 ;
V_36 = V_308 ;
break;
case V_309 :
if ( ! V_310 )
return;
V_37 = V_311 ;
V_36 = V_312 ;
break;
case V_313 :
V_37 = V_314 ;
V_36 = V_315 ;
break;
case V_316 :
V_37 = V_317 ;
V_36 = V_318 ;
break;
case V_319 :
V_37 = V_320 ;
V_36 = V_321 ;
break;
case V_322 :
V_37 = V_323 ;
V_36 = V_324 ;
break;
case V_325 :
V_37 = V_326 ;
V_36 = V_327 ;
break;
default:
return;
}
F_211 ( V_2 , V_37 , V_36 ) ;
}
static int T_9 F_213 ( void )
{
struct V_1 * V_2 = NULL ;
T_3 V_328 = 0 ;
T_3 V_80 ;
if ( V_329 )
F_150 ( V_330 L_118 ,
V_329 << 2 ) ;
V_310 = true ;
F_214 (dev) {
F_212 ( V_309 , V_2 ) ;
if ( ! V_329 ) {
F_5 ( V_2 , V_331 , & V_80 ) ;
if ( ! V_328 )
V_328 = V_80 ;
if ( ! V_80 || V_328 == V_80 )
continue;
F_150 ( V_330 L_119 ,
V_328 << 2 , V_80 << 2 ,
V_332 << 2 ) ;
V_329 = V_332 ;
}
}
if ( ! V_329 ) {
F_150 ( V_330 L_120 ,
V_328 << 2 , V_332 << 2 ) ;
V_329 = V_328 ? V_328 : V_332 ;
}
return 0 ;
}
static int F_215 ( struct V_1 * V_2 , int V_333 )
{
if ( V_333 )
return 0 ;
if ( ! F_216 ( V_2 ) )
F_172 ( & V_2 -> V_2 , L_121 ) ;
F_217 ( V_2 , V_334 , V_335 ) ;
F_208 ( 100 ) ;
return 0 ;
}
static int F_218 ( struct V_1 * V_2 , int V_333 )
{
void T_4 * V_336 ;
unsigned long V_337 ;
T_1 V_76 ;
if ( V_333 )
return 0 ;
V_336 = F_186 ( V_2 , 0 , 0 ) ;
if ( ! V_336 )
return - V_338 ;
F_219 ( 0x00000002 , V_336 + V_339 ) ;
F_219 ( 0x00000005 , V_336 + V_340 ) ;
V_76 = F_220 ( V_336 + V_341 ) & 0xfffffffe ;
F_219 ( V_76 , V_336 + V_341 ) ;
V_337 = V_342 + F_221 ( V_343 ) ;
do {
V_76 = F_220 ( V_336 + V_344 ) ;
if ( ( V_76 & 0xb0000000 ) == 0 )
goto V_345;
F_208 ( 10 ) ;
} while ( F_222 ( V_342 , V_337 ) );
F_52 ( & V_2 -> V_2 , L_122 ) ;
V_345:
F_219 ( 0x00000002 , V_336 + V_346 ) ;
F_187 ( V_2 , V_336 ) ;
return 0 ;
}
static int F_223 ( struct V_1 * V_2 , int V_333 )
{
T_2 V_347 ;
T_2 V_348 ;
if ( ( V_2 -> V_91 & 0xf000 ) != 0x4000 )
return - V_349 ;
if ( V_333 )
return 0 ;
F_33 ( V_2 , V_78 , & V_347 ) ;
F_54 ( V_2 , V_78 ,
V_347 | V_350 ) ;
F_224 ( V_2 ) ;
F_33 ( V_2 , V_2 -> V_351 + V_352 , & V_348 ) ;
if ( ( V_348 & V_353 ) == 0 )
F_54 ( V_2 , V_2 -> V_351 + V_352 ,
V_348 |
V_353 |
V_354 ) ;
if ( ! F_216 ( V_2 ) )
F_172 ( & V_2 -> V_2 , L_121 ) ;
F_217 ( V_2 , V_334 , V_335 ) ;
F_208 ( 100 ) ;
F_225 ( V_2 ) ;
F_54 ( V_2 , V_78 , V_347 ) ;
return 0 ;
}
int F_226 ( struct V_1 * V_2 , int V_333 )
{
const struct V_355 * V_29 ;
for ( V_29 = V_355 ; V_29 -> V_356 ; V_29 ++ ) {
if ( ( V_29 -> V_163 == V_2 -> V_163 ||
V_29 -> V_163 == ( T_2 ) V_299 ) &&
( V_29 -> V_91 == V_2 -> V_91 ||
V_29 -> V_91 == ( T_2 ) V_299 ) )
return V_29 -> V_356 ( V_2 , V_333 ) ;
}
return - V_349 ;
}
static void F_227 ( struct V_1 * V_2 )
{
if ( F_96 ( V_2 -> V_86 ) != 0 )
F_228 ( V_2 , F_116 ( F_63 ( V_2 -> V_86 ) , 0 ) ) ;
}
static void F_229 ( struct V_1 * V_2 )
{
if ( F_96 ( V_2 -> V_86 ) != 1 )
F_228 ( V_2 , F_116 ( F_63 ( V_2 -> V_86 ) , 1 ) ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
const struct V_357 * V_358 ;
V_358 = F_231 ( V_359 , V_2 ) ;
if ( V_358 )
F_228 ( V_2 , V_358 -> V_360 ) ;
}
static void F_232 ( struct V_1 * V_54 )
{
if ( ! F_197 ( V_54 -> V_51 ) &&
V_54 -> V_152 == V_211 &&
! F_233 ( V_54 ) && F_233 ( V_54 -> V_51 -> V_361 ) &&
F_203 ( V_54 -> V_51 -> V_361 ) != V_362 )
V_54 -> V_112 |= V_363 ;
}
static void F_234 ( struct V_1 * V_54 )
{
F_228 ( V_54 , F_116 ( 0x10 , 0x0 ) ) ;
F_228 ( V_54 , F_116 ( 0x11 , 0x0 ) ) ;
F_228 ( V_54 , F_116 ( 0x12 , 0x3 ) ) ;
}
static void F_235 ( struct V_1 * V_54 )
{
T_1 V_55 = V_54 -> V_55 ;
V_54 -> V_55 = ( V_364 << 8 ) | 0x01 ;
F_6 ( & V_54 -> V_2 , L_123 ,
V_55 , V_54 -> V_55 ) ;
}
static void F_236 ( struct V_1 * V_54 )
{
struct V_1 * V_365 = F_237 ( V_54 ) ;
if ( ! V_365 ) {
F_52 ( & V_54 -> V_2 , L_124 ) ;
return;
}
F_6 ( & V_365 -> V_2 , L_125 ,
F_180 ( & V_54 -> V_2 ) ) ;
F_238 ( V_365 , V_334 ,
V_366 |
V_367 , 0 ) ;
}
static void F_239 ( struct V_1 * V_54 )
{
if ( ( V_54 -> V_91 & 0xff00 ) == 0x5400 )
F_236 ( V_54 ) ;
}
static int F_240 ( struct V_1 * V_2 , T_2 V_368 )
{
#ifdef F_241
struct V_369 * V_370 = NULL ;
T_10 V_371 ;
if ( ! V_2 -> V_153 || ! F_197 ( V_2 -> V_51 ) )
return - V_372 ;
V_371 = F_242 ( L_126 , 0 , & V_370 ) ;
if ( F_205 ( V_371 ) )
return - V_372 ;
V_368 &= ( V_373 | V_374 | V_375 | V_376 ) ;
return V_368 & ~ ( V_373 | V_374 ) ? 0 : 1 ;
#else
return - V_372 ;
#endif
}
static int F_243 ( struct V_1 * V_2 , T_2 V_368 )
{
V_368 &= ~ ( V_377 | V_378 | V_373 |
V_374 | V_379 | V_376 ) ;
return V_368 ? 0 : 1 ;
}
static bool F_244 ( struct V_1 * V_2 )
{
int V_29 ;
if ( ! F_233 ( V_2 ) || F_203 ( V_2 ) != V_380 )
return false ;
for ( V_29 = 0 ; V_29 < F_191 ( V_381 ) ; V_29 ++ )
if ( V_381 [ V_29 ] == V_2 -> V_91 )
return true ;
return false ;
}
static int F_245 ( struct V_1 * V_2 , T_2 V_368 )
{
T_2 V_33 = V_2 -> V_112 & V_382 ?
V_383 : 0 ;
if ( ! F_244 ( V_2 ) )
return - V_349 ;
return V_368 & ~ V_33 ? 0 : 1 ;
}
static int F_246 ( struct V_1 * V_2 , T_2 V_368 )
{
T_2 V_33 = ( V_373 | V_374 | V_379 | V_377 ) ;
int V_384 = V_368 & ~ V_33 ? 0 : 1 ;
F_6 ( & V_2 -> V_2 , L_127 , V_384 ) ;
return V_384 ;
}
static bool F_247 ( struct V_1 * V_2 )
{
if ( ! F_233 ( V_2 ) || F_203 ( V_2 ) != V_380 )
return false ;
switch ( V_2 -> V_91 ) {
case 0xa110 ... 0xa11f : case 0xa167 ... 0xa16a :
case 0xa290 ... 0xa29f : case 0xa2e7 ... 0xa2ee :
return true ;
}
return false ;
}
static int F_248 ( struct V_1 * V_2 , T_2 V_368 )
{
int V_39 ;
T_1 V_385 , V_232 ;
if ( ! F_247 ( V_2 ) )
return - V_349 ;
V_39 = F_249 ( V_2 , V_386 ) ;
if ( ! V_39 )
return - V_349 ;
F_10 ( V_2 , V_39 + V_387 , & V_385 ) ;
V_368 &= ( V_385 | V_375 ) ;
F_10 ( V_2 , V_39 + V_388 , & V_232 ) ;
return V_368 & ~ V_232 ? 0 : 1 ;
}
static int F_250 ( struct V_1 * V_2 , T_2 V_368 )
{
V_368 &= ~ ( V_377 | V_378 | V_373 |
V_374 | V_379 | V_376 ) ;
return V_368 ? 0 : 1 ;
}
int F_251 ( struct V_1 * V_2 , T_2 V_368 )
{
const struct V_389 * V_29 ;
int V_384 ;
for ( V_29 = V_389 ; V_29 -> V_390 ; V_29 ++ ) {
if ( ( V_29 -> V_163 == V_2 -> V_163 ||
V_29 -> V_163 == ( T_2 ) V_299 ) &&
( V_29 -> V_91 == V_2 -> V_91 ||
V_29 -> V_91 == ( T_2 ) V_299 ) ) {
V_384 = V_29 -> V_390 ( V_2 , V_368 ) ;
if ( V_384 >= 0 )
return V_384 ;
}
}
return - V_349 ;
}
static int F_252 ( struct V_1 * V_2 )
{
T_1 V_134 , V_391 , V_392 ;
void T_4 * V_393 ;
F_253 ( V_2 -> V_51 , F_116 ( 31 , 0 ) ,
V_394 , & V_134 ) ;
if ( ! ( V_134 & V_395 ) )
return - V_396 ;
V_393 = F_85 ( V_134 & V_397 ,
F_254 ( V_398 ) ) ;
if ( ! V_393 )
return - V_338 ;
V_391 = F_87 ( V_393 + V_399 ) ;
V_391 &= V_400 | V_401 ;
if ( V_391 != ( V_400 | V_401 ) ) {
V_392 = F_87 ( V_393 + V_398 ) ;
if ( V_392 & V_402 ) {
F_6 ( & V_2 -> V_2 , L_128 ) ;
V_392 &= ~ V_402 ;
F_88 ( V_392 , V_393 + V_398 ) ;
}
}
F_90 ( V_393 ) ;
return 0 ;
}
static void F_255 ( struct V_1 * V_2 )
{
T_1 V_403 ;
F_10 ( V_2 , V_404 , & V_403 ) ;
if ( ! ( V_403 & V_405 ) ) {
F_6 ( & V_2 -> V_2 , L_129 ) ;
V_403 |= V_405 ;
F_54 ( V_2 , V_404 , V_403 ) ;
}
}
static int F_256 ( struct V_1 * V_2 )
{
if ( ! F_244 ( V_2 ) )
return - V_349 ;
if ( F_252 ( V_2 ) ) {
F_52 ( & V_2 -> V_2 , L_130 ) ;
return 0 ;
}
F_255 ( V_2 ) ;
V_2 -> V_112 |= V_382 ;
F_6 ( & V_2 -> V_2 , L_131 ) ;
return 0 ;
}
static int F_257 ( struct V_1 * V_2 )
{
int V_39 ;
T_1 V_385 , V_232 ;
if ( ! F_247 ( V_2 ) )
return - V_349 ;
V_39 = F_249 ( V_2 , V_386 ) ;
if ( ! V_39 )
return - V_349 ;
F_10 ( V_2 , V_39 + V_387 , & V_385 ) ;
F_10 ( V_2 , V_39 + V_388 , & V_232 ) ;
V_232 |= ( V_385 & V_377 ) ;
V_232 |= ( V_385 & V_373 ) ;
V_232 |= ( V_385 & V_374 ) ;
V_232 |= ( V_385 & V_379 ) ;
F_68 ( V_2 , V_39 + V_388 , V_232 ) ;
F_6 ( & V_2 -> V_2 , L_132 ) ;
return 0 ;
}
int F_258 ( struct V_1 * V_2 )
{
const struct V_406 * V_29 ;
int V_384 ;
for ( V_29 = V_406 ; V_29 -> V_407 ; V_29 ++ ) {
if ( ( V_29 -> V_163 == V_2 -> V_163 ||
V_29 -> V_163 == ( T_2 ) V_299 ) &&
( V_29 -> V_91 == V_2 -> V_91 ||
V_29 -> V_91 == ( T_2 ) V_299 ) ) {
V_384 = V_29 -> V_407 ( V_2 ) ;
if ( V_384 >= 0 )
return V_384 ;
}
}
return - V_349 ;
}
static void F_259 ( struct V_1 * V_54 )
{
int V_39 , V_29 = 0 ;
T_3 V_408 ;
T_2 V_409 , * V_385 ;
struct V_410 * V_411 ;
if ( V_54 -> V_412 || F_149 ( V_54 , V_413 ) )
return;
V_39 = F_149 ( V_54 , V_414 ) ;
if ( ! V_39 )
return;
F_5 ( V_54 , V_39 + 1 , & V_408 ) ;
if ( V_408 )
return;
V_39 = 0x50 ;
F_33 ( V_54 , V_39 , & V_409 ) ;
if ( V_409 == ( 0x0000 | V_413 ) ) {
T_1 V_371 ;
#ifndef F_260
#define F_260 7
#endif
int V_40 = F_260 * sizeof( T_2 ) ;
V_54 -> V_412 = V_39 ;
F_33 ( V_54 , V_39 + V_415 , & V_409 ) ;
V_54 -> V_416 = V_409 ;
F_33 ( V_54 , V_39 + V_417 , & V_409 ) ;
V_54 -> V_213 = V_409 & V_418 ;
V_54 -> V_28 = V_419 ;
if ( F_10 ( V_54 , V_420 , & V_371 ) !=
V_421 || ( V_371 == 0xffffffff ) )
V_54 -> V_28 = V_420 ;
if ( F_261 ( V_54 , V_413 ) )
return;
V_411 = F_262 ( sizeof( * V_411 ) + V_40 , V_422 ) ;
if ( ! V_411 )
return;
V_411 -> V_385 . V_423 = V_413 ;
V_411 -> V_385 . V_424 = 0 ;
V_411 -> V_385 . V_40 = V_40 ;
V_385 = ( T_2 * ) & V_411 -> V_385 . V_425 [ 0 ] ;
F_263 ( V_54 , V_334 , & V_385 [ V_29 ++ ] ) ;
F_263 ( V_54 , V_426 , & V_385 [ V_29 ++ ] ) ;
F_263 ( V_54 , V_427 , & V_385 [ V_29 ++ ] ) ;
F_263 ( V_54 , V_428 , & V_385 [ V_29 ++ ] ) ;
F_263 ( V_54 , V_429 , & V_385 [ V_29 ++ ] ) ;
F_263 ( V_54 , V_430 , & V_385 [ V_29 ++ ] ) ;
F_263 ( V_54 , V_431 , & V_385 [ V_29 ++ ] ) ;
F_264 ( & V_411 -> V_432 , & V_54 -> V_433 ) ;
}
}
static void F_265 ( struct V_1 * V_54 )
{
if ( V_54 -> V_51 -> V_434 && F_266 ( V_54 -> V_51 ) >= 0x10000 )
V_54 -> V_51 -> V_88 |= V_435 ;
}
