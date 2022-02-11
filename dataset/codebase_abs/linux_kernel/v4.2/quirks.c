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
int V_29 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
struct V_31 * V_32 = & V_2 -> V_31 [ V_29 ] ;
if ( V_32 -> V_33 & V_34 && F_24 ( V_32 ) < V_35 ) {
V_32 -> V_36 = V_35 - 1 ;
V_32 -> V_37 = 0 ;
V_32 -> V_33 |= V_38 ;
F_6 ( & V_2 -> V_2 , L_8 ,
V_29 , V_32 ) ;
}
}
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_31 [ 0 ] ;
if ( ( V_32 -> V_37 & 0x3ffffff ) || V_32 -> V_36 != V_32 -> V_37 + 0x3ffffff ) {
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0x3ffffff ;
}
}
static void F_26 ( struct V_1 * V_2 , int V_39 , unsigned V_40 ,
const char * V_41 )
{
T_1 V_42 ;
struct V_43 V_44 ;
struct V_31 * V_45 = V_2 -> V_31 + V_39 ;
F_10 ( V_2 , V_46 + ( V_39 << 2 ) , & V_42 ) ;
if ( ! V_42 )
return;
V_45 -> V_41 = F_27 ( V_2 ) ;
V_45 -> V_33 = V_42 & ~ V_47 ;
V_45 -> V_33 |=
( V_48 | V_49 | V_50 ) ;
V_42 &= ~ ( V_40 - 1 ) ;
V_44 . V_37 = V_42 ;
V_44 . V_36 = V_42 + V_40 - 1 ;
F_28 ( V_2 -> V_51 , V_45 , & V_44 ) ;
F_6 ( & V_2 -> V_2 , V_12 L_9 ,
V_41 , V_46 + ( V_39 << 2 ) , V_45 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
static char * V_41 = L_10 ;
if ( F_30 ( V_2 , 0 ) != 8 ) {
F_26 ( V_2 , 0 , 8 , V_41 ) ;
F_26 ( V_2 , 1 , 256 , V_41 ) ;
F_26 ( V_2 , 2 , 64 , V_41 ) ;
F_6 ( & V_2 -> V_2 , L_11 ,
V_41 ) ;
}
}
static void F_31 ( struct V_1 * V_2 , int V_52 ,
unsigned V_40 , int V_53 , const char * V_41 )
{
T_2 V_42 ;
struct V_43 V_44 ;
struct V_31 * V_45 = V_2 -> V_31 + V_53 ;
F_32 ( V_2 , V_52 , & V_42 ) ;
V_42 &= ~ ( V_40 - 1 ) ;
if ( ! V_42 )
return;
V_45 -> V_41 = F_27 ( V_2 ) ;
V_45 -> V_33 = V_48 ;
V_44 . V_37 = V_42 ;
V_44 . V_36 = V_42 + V_40 - 1 ;
F_28 ( V_2 -> V_51 , V_45 , & V_44 ) ;
if ( ! F_33 ( V_2 , V_53 ) )
F_6 ( & V_2 -> V_2 , L_12 , V_45 , V_41 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_13 ) ;
F_35 ( 0x3b0 , 0x0C , L_14 ) ;
F_35 ( 0x3d3 , 0x01 , L_14 ) ;
}
static void F_36 ( struct V_1 * V_54 )
{
V_54 -> V_55 = 0x0c03fe ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_31 ( V_2 , 0xE0 , 64 , V_56 , L_15 ) ;
F_31 ( V_2 , 0xE2 , 32 , V_56 + 1 , L_16 ) ;
}
static void F_38 ( struct V_1 * V_2 , const char * V_41 , unsigned int V_52 , unsigned int V_57 )
{
T_1 V_58 ;
T_1 V_59 , V_40 , V_60 ;
F_10 ( V_2 , V_52 , & V_58 ) ;
if ( ( V_58 & V_57 ) != V_57 )
return;
V_59 = ( V_58 >> 16 ) & 15 ;
V_60 = V_58 & 0xffff ;
V_40 = 16 ;
for (; ; ) {
unsigned V_61 = V_40 >> 1 ;
if ( ( V_61 & V_59 ) == V_61 )
break;
V_40 = V_61 ;
}
V_60 &= - V_40 ;
F_6 ( & V_2 -> V_2 , L_17 , V_41 , V_60 ,
V_60 + V_40 - 1 ) ;
}
static void F_39 ( struct V_1 * V_2 , const char * V_41 , unsigned int V_52 , unsigned int V_57 )
{
T_1 V_58 ;
T_1 V_59 , V_40 , V_60 ;
F_10 ( V_2 , V_52 , & V_58 ) ;
if ( ( V_58 & V_57 ) != V_57 )
return;
V_60 = V_58 & 0xffff0000 ;
V_59 = ( V_58 & 0x3f ) << 16 ;
V_40 = 128 << 16 ;
for (; ; ) {
unsigned V_61 = V_40 >> 1 ;
if ( ( V_61 & V_59 ) == V_61 )
break;
V_40 = V_61 ;
}
V_60 &= - V_40 ;
F_6 ( & V_2 -> V_2 , L_18 , V_41 , V_60 ,
V_60 + V_40 - 1 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_62 ;
F_31 ( V_2 , 0x40 , 64 , V_56 , L_19 ) ;
F_31 ( V_2 , 0x90 , 16 , V_56 + 1 , L_20 ) ;
F_10 ( V_2 , 0x5c , & V_62 ) ;
F_38 ( V_2 , L_21 , 0x60 , 3 << 21 ) ;
F_38 ( V_2 , L_22 , 0x64 , 3 << 21 ) ;
if ( V_62 & ( 1 << 29 ) ) {
F_38 ( V_2 , L_23 , 0x68 , 1 << 20 ) ;
F_39 ( V_2 , L_24 , 0x6c , 1 << 7 ) ;
}
if ( V_62 & ( 1 << 30 ) ) {
F_38 ( V_2 , L_25 , 0x70 , 1 << 20 ) ;
F_39 ( V_2 , L_26 , 0x74 , 1 << 7 ) ;
}
F_38 ( V_2 , L_27 , 0x78 , 1 << 20 ) ;
F_38 ( V_2 , L_28 , 0x7c , 1 << 20 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_3 V_57 ;
F_5 ( V_2 , V_63 , & V_57 ) ;
if ( V_57 & V_64 )
F_31 ( V_2 , V_65 , 128 , V_56 ,
L_29 ) ;
F_5 ( V_2 , V_66 , & V_57 ) ;
if ( V_57 & V_67 )
F_31 ( V_2 , V_68 , 64 , V_56 + 1 ,
L_30 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_3 V_57 ;
F_5 ( V_2 , V_63 , & V_57 ) ;
if ( V_57 & V_69 )
F_31 ( V_2 , V_65 , 128 , V_56 ,
L_31 ) ;
F_5 ( V_2 , V_70 , & V_57 ) ;
if ( V_57 & V_71 )
F_31 ( V_2 , V_72 , 64 , V_56 + 1 ,
L_32 ) ;
}
static void F_43 ( struct V_1 * V_2 , unsigned V_73 , const char * V_41 , int V_74 )
{
T_1 V_75 ;
T_1 V_40 , V_60 ;
F_10 ( V_2 , V_73 , & V_75 ) ;
if ( ! ( V_75 & 1 ) )
return;
V_60 = V_75 & 0xfffc ;
if ( V_74 ) {
V_40 = 16 ;
} else {
V_40 = 128 ;
}
V_60 &= ~ ( V_40 - 1 ) ;
F_6 ( & V_2 -> V_2 , L_17 , V_41 , V_60 , V_60 + V_40 - 1 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
F_43 ( V_2 , 0x84 , L_33 , 0 ) ;
F_43 ( V_2 , 0x88 , L_34 , 1 ) ;
}
static void F_45 ( struct V_1 * V_2 , unsigned V_73 , const char * V_41 )
{
T_1 V_75 ;
T_1 V_59 , V_60 ;
F_10 ( V_2 , V_73 , & V_75 ) ;
if ( ! ( V_75 & 1 ) )
return;
V_60 = V_75 & 0xfffc ;
V_59 = ( V_75 >> 16 ) & 0xfc ;
V_59 |= 3 ;
F_6 ( & V_2 -> V_2 , L_35 , V_41 , V_60 , V_59 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
F_45 ( V_2 , 0x84 , L_36 ) ;
F_45 ( V_2 , 0x88 , L_37 ) ;
F_45 ( V_2 , 0x8c , L_38 ) ;
F_45 ( V_2 , 0x90 , L_39 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 & 0x10 )
F_31 ( V_2 , 0x48 , 256 , V_56 ,
L_40 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_47 ( V_2 ) ;
F_31 ( V_2 , 0x70 , 128 , V_56 + 1 ,
L_41 ) ;
F_31 ( V_2 , 0x90 , 16 , V_56 + 2 , L_42 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_31 ( V_2 , 0x88 , 128 , V_56 , L_43 ) ;
F_31 ( V_2 , 0xd0 , 16 , V_56 + 1 , L_44 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_1 * V_54 ;
T_2 V_76 ;
F_51 ( & V_2 -> V_2 , L_45 ) ;
F_52 (pdev, &dev->subordinate->devices, bus_list) {
F_32 ( V_54 , V_77 , & V_76 ) ;
if ( V_76 & V_78 )
F_53 ( V_54 , V_77 , V_76 & ~ V_78 ) ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
T_3 V_79 ;
if ( V_80 < 1 )
V_79 = 0 ;
else
V_79 = 0x1f ;
F_6 ( & V_2 -> V_2 , L_46 ,
V_79 == 0 ? L_47 : L_48 ) ;
F_7 ( V_2 , 0x58 , V_79 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
T_3 V_81 ;
#define F_56 8
F_5 ( V_2 , 0x5B , & V_81 ) ;
if ( ! ( V_81 & F_56 ) ) {
F_6 ( & V_2 -> V_2 , L_49 ) ;
F_7 ( V_2 , 0x5B , V_81 | F_56 ) ;
}
}
static void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 >= 0x02 ) {
F_51 ( & V_2 -> V_2 , L_50 ) ;
F_51 ( & V_2 -> V_2 , L_51 ) ;
}
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 && V_2 -> V_22 <= 0x12 ) {
F_6 ( & V_2 -> V_2 , L_52 ,
V_2 -> V_22 ) ;
V_2 -> V_82 -> V_83 |= V_84 ;
}
}
static void F_59 ( struct V_1 * V_5 )
{
T_3 V_85 ;
F_5 ( V_5 , 0x42 , & V_85 ) ;
V_85 &= 0xf ;
if ( V_85 && ( V_85 != 2 ) )
V_5 -> V_85 = V_85 ;
}
static void F_60 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_86 ) {
case V_21 :
V_87 = F_61 ( V_2 -> V_88 ) ;
V_89 = F_61 ( V_2 -> V_88 ) ;
break;
case V_90 :
case V_91 :
V_87 = 15 ;
break;
case V_92 :
V_87 = 16 ;
break;
case V_23 :
case V_93 :
case V_94 :
case V_95 :
V_87 = 17 ;
break;
}
}
static void F_62 ( struct V_1 * V_2 )
{
T_3 V_85 , V_96 ;
if ( V_87 == - 1 )
return;
V_96 = V_2 -> V_85 ;
if ( ! V_96 || V_96 > 15 )
return;
if ( V_2 -> V_51 -> V_97 != 0 || F_61 ( V_2 -> V_88 ) > V_89 ||
F_61 ( V_2 -> V_88 ) < V_87 )
return;
F_5 ( V_2 , V_98 , & V_85 ) ;
if ( V_96 != V_85 ) {
F_6 ( & V_2 -> V_2 , L_53 ,
V_85 , V_96 ) ;
F_63 ( 15 ) ;
F_7 ( V_2 , V_98 , V_96 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0xfc , 0 ) ;
F_32 ( V_2 , V_99 , & V_2 -> V_86 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_66 ( V_2 , V_100 , 0 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
T_1 V_101 ;
F_10 ( V_2 , 0x4C , & V_101 ) ;
if ( ( V_101 & 6 ) != 6 ) {
V_101 |= 6 ;
F_51 ( & V_2 -> V_2 , L_54 ) ;
F_66 ( V_2 , 0x4C , V_101 ) ;
F_10 ( V_2 , 0x84 , & V_101 ) ;
V_101 |= ( 1 << 23 ) ;
F_66 ( V_2 , 0x84 , V_101 ) ;
}
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_31 [ 1 ] ;
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0xffffff ;
}
static void F_69 ( struct V_1 * V_2 )
{
V_2 -> V_102 = 1 ;
}
static void F_70 ( struct V_1 * V_2 )
{
T_3 V_73 ;
F_5 ( V_2 , 0x41 , & V_73 ) ;
if ( V_73 & 2 ) {
V_73 &= ~ 2 ;
F_6 ( & V_2 -> V_2 , L_55 ,
V_73 ) ;
F_7 ( V_2 , 0x41 , V_73 ) ;
}
}
static void F_71 ( struct V_1 * V_54 )
{
T_2 V_103 ;
if ( V_54 -> V_22 != 0x04 )
return;
F_32 ( V_54 , 0x40 , & V_103 ) ;
if ( V_103 & ( 1 << 6 ) ) {
V_103 &= ~ ( 1 << 6 ) ;
F_53 ( V_54 , 0x40 , V_103 ) ;
F_6 ( & V_54 -> V_2 , L_56 ) ;
}
}
static void F_72 ( struct V_1 * V_54 )
{
T_3 V_79 ;
F_5 ( V_54 , V_104 , & V_79 ) ;
if ( V_79 == 0x01 ) {
F_5 ( V_54 , 0x40 , & V_79 ) ;
F_7 ( V_54 , 0x40 , V_79 | 1 ) ;
F_7 ( V_54 , 0x9 , 1 ) ;
F_7 ( V_54 , 0xa , 6 ) ;
F_7 ( V_54 , 0x40 , V_79 ) ;
V_54 -> V_55 = V_105 ;
F_6 ( & V_54 -> V_2 , L_57 ) ;
}
}
static void F_73 ( struct V_1 * V_54 )
{
T_3 V_106 ;
F_5 ( V_54 , V_107 , & V_106 ) ;
if ( V_106 & 5 ) {
V_106 &= ~ 5 ;
V_54 -> V_55 &= ~ 5 ;
F_7 ( V_54 , V_107 , V_106 ) ;
}
}
static void F_74 ( struct V_1 * V_54 )
{
T_3 V_106 ;
F_5 ( V_54 , V_107 , & V_106 ) ;
if ( ( ( V_106 & 1 ) && ! ( V_106 & 4 ) ) || ( ( V_106 & 4 ) && ! ( V_106 & 1 ) ) ) {
F_6 ( & V_54 -> V_2 , L_58 ) ;
V_106 &= ~ 5 ;
V_54 -> V_55 &= ~ 5 ;
F_7 ( V_54 , V_107 , V_106 ) ;
}
}
static void F_75 ( struct V_1 * V_54 )
{
V_54 -> V_108 |= V_109 ;
}
static void F_76 ( struct V_1 * V_2 )
{
V_2 -> V_55 = V_110 << 8 ;
}
static void F_77 ( struct V_1 * V_2 )
{
if ( F_78 ( V_2 -> V_111 == V_112 ) ) {
if ( V_2 -> V_86 == V_113 )
switch ( V_2 -> V_114 ) {
case 0x8025 :
case 0x8070 :
case 0x8088 :
case 0x1626 :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_116 )
switch ( V_2 -> V_114 ) {
case 0x80b1 :
case 0x80b2 :
case 0x8093 :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_117 )
switch ( V_2 -> V_114 ) {
case 0x8030 :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_118 )
switch ( V_2 -> V_114 ) {
case 0x8070 :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_119 )
switch ( V_2 -> V_114 ) {
case 0x80c9 :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_120 )
switch ( V_2 -> V_114 ) {
case 0x1751 :
case 0x1821 :
case 0x1897 :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_121 )
switch ( V_2 -> V_114 ) {
case 0x184b :
case 0x186a :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_122 )
switch ( V_2 -> V_114 ) {
case 0x80f2 :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_123 )
switch ( V_2 -> V_114 ) {
case 0x1882 :
case 0x1977 :
V_115 = 1 ;
}
} else if ( F_78 ( V_2 -> V_111 == V_124 ) ) {
if ( V_2 -> V_86 == V_121 )
switch ( V_2 -> V_114 ) {
case 0x088C :
case 0x0890 :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_122 )
switch ( V_2 -> V_114 ) {
case 0x12bc :
case 0x12bd :
case 0x006a :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_125 )
switch ( V_2 -> V_114 ) {
case 0x12bf :
V_115 = 1 ;
}
} else if ( F_78 ( V_2 -> V_111 == V_126 ) ) {
if ( V_2 -> V_86 == V_121 )
switch ( V_2 -> V_114 ) {
case 0xC00C :
V_115 = 1 ;
}
} else if ( F_78 ( V_2 -> V_111 == V_127 ) ) {
if ( V_2 -> V_86 == V_121 )
switch ( V_2 -> V_114 ) {
case 0x0058 :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_128 )
switch ( V_2 -> V_114 ) {
case 0xB16C :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_129 )
switch ( V_2 -> V_114 ) {
case 0x00b8 :
case 0x00b9 :
case 0x00ba :
V_115 = 1 ;
}
else if ( V_2 -> V_86 == V_130 )
switch ( V_2 -> V_114 ) {
case 0x001A :
V_115 = 1 ;
}
}
}
static void F_79 ( struct V_1 * V_2 )
{
T_2 V_75 ;
if ( F_80 ( ! V_115 ) )
return;
F_32 ( V_2 , 0xF2 , & V_75 ) ;
if ( V_75 & 0x8 ) {
F_53 ( V_2 , 0xF2 , V_75 & ( ~ 0x8 ) ) ;
F_32 ( V_2 , 0xF2 , & V_75 ) ;
if ( V_75 & 0x8 )
F_6 ( & V_2 -> V_2 , L_59 ,
V_75 ) ;
else
F_6 ( & V_2 -> V_2 , L_60 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
T_1 V_131 ;
if ( F_80 ( ! V_115 ) )
return;
F_82 ( V_132 ) ;
F_10 ( V_2 , 0xF0 , & V_131 ) ;
V_132 = F_83 ( V_131 & 0xFFFFC000 , 0x4000 ) ;
if ( V_132 == NULL )
return;
}
static void F_84 ( struct V_1 * V_2 )
{
T_1 V_75 ;
if ( F_80 ( ! V_115 || ! V_132 ) )
return;
V_75 = F_85 ( V_132 + 0x3418 ) ;
F_86 ( V_75 & 0xFFFFFFF7 , V_132 + 0x3418 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
if ( F_80 ( ! V_115 || ! V_132 ) )
return;
F_88 ( V_132 ) ;
V_132 = NULL ;
F_6 ( & V_2 -> V_2 , L_61 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_81 ( V_2 ) ;
F_84 ( V_2 ) ;
F_87 ( V_2 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
T_3 V_75 = 0 ;
F_5 ( V_2 , 0x77 , & V_75 ) ;
if ( V_75 & 0x10 ) {
F_6 ( & V_2 -> V_2 , L_62 ) ;
F_7 ( V_2 , 0x77 , V_75 & ~ 0x10 ) ;
}
}
static void F_91 ( struct V_1 * V_2 )
{
T_3 V_73 ;
T_2 V_133 ;
F_5 ( V_2 , V_134 , & V_73 ) ;
F_7 ( V_2 , V_134 , V_73 | ( 1 << 6 ) ) ;
F_32 ( V_2 , V_99 , & V_133 ) ;
if ( ( ( V_133 & 0xfff0 ) != 0x0960 ) && ( V_133 != 0x0018 ) ) {
F_7 ( V_2 , V_134 , V_73 ) ;
return;
}
V_2 -> V_86 = V_133 ;
F_90 ( V_2 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
T_3 V_75 ;
int V_135 = 0 ;
if ( F_80 ( V_2 -> V_111 == V_112 ) ) {
if ( V_2 -> V_86 == V_90 )
V_135 = 1 ;
}
if ( ! V_135 )
return;
F_5 ( V_2 , 0x50 , & V_75 ) ;
if ( V_75 & 0xc0 ) {
F_7 ( V_2 , 0x50 , V_75 & ( ~ 0xc0 ) ) ;
F_5 ( V_2 , 0x50 , & V_75 ) ;
if ( V_75 & 0xc0 )
F_6 ( & V_2 -> V_2 , L_63 ,
V_75 ) ;
else
F_6 ( & V_2 -> V_2 , L_64 ) ;
}
}
static void F_93 ( struct V_1 * V_54 )
{
T_1 V_136 , V_137 , V_55 ;
T_3 V_138 ;
if ( F_94 ( V_54 -> V_88 ) )
return;
F_10 ( V_54 , 0x40 , & V_136 ) ;
F_10 ( V_54 , 0x80 , & V_137 ) ;
V_136 &= ~ 0x00CFF302 ;
V_137 &= ~ ( 1 << 24 ) ;
switch ( V_54 -> V_86 ) {
case V_139 :
case V_140 :
case V_141 :
V_136 |= 0x0002A100 ;
break;
case V_142 :
case V_143 :
V_137 |= ( 1 << 24 ) ;
case V_144 :
case V_145 :
case V_146 :
V_136 |= 0x00C2A1B3 ;
break;
case V_147 :
V_136 |= 0x00C00000 ;
break;
}
F_66 ( V_54 , 0x40 , V_136 ) ;
F_66 ( V_54 , 0x80 , V_137 ) ;
F_5 ( V_54 , V_148 , & V_138 ) ;
V_54 -> V_149 = V_138 & 0x7f ;
V_54 -> V_150 = ! ! ( V_138 & 0x80 ) ;
F_10 ( V_54 , V_151 , & V_55 ) ;
V_54 -> V_55 = V_55 >> 8 ;
}
static void F_95 ( struct V_1 * V_54 )
{
int V_29 ;
if ( ( V_54 -> V_55 >> 8 ) != 0xff00 )
return;
if ( F_96 ( V_54 , 0 ) && F_30 ( V_54 , 0 ) )
F_97 ( & V_152 , & V_54 -> V_31 [ 0 ] ) ;
for ( V_29 = 1 ; V_29 < 6 ; V_29 ++ )
memset ( & V_54 -> V_31 [ V_29 ] , 0 , sizeof( V_54 -> V_31 [ V_29 ] ) ) ;
}
static void F_98 ( struct V_1 * V_54 )
{
V_54 -> V_153 = 1 ;
}
static void F_99 ( struct V_1 * V_2 )
{
V_2 -> V_153 = 1 ;
F_51 ( & V_2 -> V_2 , L_65 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
V_154 = 120 ;
V_2 -> V_155 = 1 ;
}
static void F_101 ( struct V_1 * V_2 )
{
if ( V_156 || V_157 )
return;
V_2 -> V_158 = V_159 ;
F_6 ( & V_2 -> V_2 , L_66 ,
V_2 -> V_160 , V_2 -> V_86 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
T_2 V_161 ;
if ( V_156 )
return;
F_32 ( V_2 , V_162 , & V_161 ) ;
V_161 |= V_163 ;
F_53 ( V_2 , V_162 , V_161 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_160 , V_2 -> V_86 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
T_1 V_164 ;
T_3 V_85 ;
if ( V_156 )
return;
F_10 ( V_2 , V_165 , & V_164 ) ;
F_66 ( V_2 , V_165 , V_164 |
V_166 ) ;
for ( V_85 = 0x10 ; V_85 < 0x10 + 32 ; V_85 ++ ) {
F_104 ( V_85 , V_167 ) ;
F_104 ( 0x00 , V_168 ) ;
}
F_66 ( V_2 , V_165 , V_164 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_160 , V_2 -> V_86 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_1 V_164 ;
if ( V_156 )
return;
if ( ( V_2 -> V_22 == V_169 ) ||
( V_2 -> V_22 == V_170 ) )
return;
F_10 ( V_2 , V_171 , & V_164 ) ;
V_164 &= ~ V_172 ;
F_66 ( V_2 , V_171 , V_164 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_160 , V_2 -> V_86 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
T_2 V_161 ;
if ( V_156 )
return;
F_32 ( V_2 , V_173 , & V_161 ) ;
if ( ! V_161 ) {
F_6 ( & V_2 -> V_2 , L_68 ,
V_2 -> V_160 , V_2 -> V_86 ) ;
return;
}
F_53 ( V_2 , V_173 , 0 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_160 , V_2 -> V_86 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_31 [ 0 ] ;
if ( V_32 -> V_37 & 0x8 ) {
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0xf ;
}
}
static void F_108 ( struct V_1 * V_2 )
{
unsigned int V_174 ;
if ( V_2 -> V_22 >= 2 )
return;
for ( V_174 = 0 ; V_174 <= 1 ; V_174 ++ )
if ( F_30 ( V_2 , V_174 ) == 0x80 &&
( F_96 ( V_2 , V_174 ) & 0x80 ) ) {
struct V_31 * V_32 = & V_2 -> V_31 [ V_174 ] ;
F_6 ( & V_2 -> V_2 , L_69 ,
V_174 ) ;
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0xff ;
}
}
static void F_109 ( struct V_1 * V_2 )
{
unsigned int V_175 = ( V_2 -> V_114 & 0xf0 ) >> 4 ;
unsigned int V_176 = V_2 -> V_114 & 0xf ;
switch ( V_2 -> V_86 ) {
case V_177 :
if ( V_2 -> V_111 == V_178 &&
V_2 -> V_114 == 0x0299 )
return;
case V_179 :
case V_180 :
case V_181 :
case V_182 :
if ( V_175 ) {
F_6 ( & V_2 -> V_2 , L_70 ,
V_2 -> V_86 , V_175 , V_176 ) ;
V_2 -> V_55 = ( V_183 << 8 ) |
( V_2 -> V_55 & 0xff ) ;
}
}
}
static void F_110 ( struct V_1 * V_2 )
{
T_2 V_76 , V_184 ;
T_3 T_4 * V_185 ;
T_3 V_186 ;
switch ( V_2 -> V_86 ) {
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
F_32 ( V_2 , V_77 , & V_76 ) ;
if ( ! ( V_76 & V_187 ) || ! F_96 ( V_2 , 0 ) )
return;
if ( V_2 -> V_188 ) {
F_32 ( V_2 , V_2 -> V_188 + V_189 , & V_184 ) ;
if ( ( V_184 & V_190 ) != V_191 )
return;
}
V_185 = F_111 ( F_96 ( V_2 , 0 ) , 8 ) ;
if ( ! V_185 ) {
F_51 ( & V_2 -> V_2 , L_71 ) ;
return;
}
V_186 = F_112 ( V_185 + 3 ) ;
if ( V_186 == 0 ) {
F_51 ( & V_2 -> V_2 , L_72 ) ;
F_113 ( 1 , V_185 + 3 ) ;
}
F_88 ( V_185 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_73 ) ;
F_115 ( V_2 , V_192 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
if ( V_2 -> V_55 == V_193 ) {
F_6 ( & V_2 -> V_2 , L_74 ) ;
V_2 -> V_55 = V_194 ;
}
}
static void F_117 ( struct V_1 * V_2 )
{
T_2 V_195 ;
F_32 ( V_2 , 0x40 , & V_195 ) ;
if ( V_195 & 0x200 ) {
F_6 ( & V_2 -> V_2 , L_75 ) ;
V_2 -> V_196 = 1 ;
}
}
static void F_118 ( struct V_1 * V_2 )
{
T_5 V_197 ;
if ( F_5 ( V_2 , 0xf41 , & V_197 ) == 0 ) {
if ( ! ( V_197 & 0x20 ) ) {
F_7 ( V_2 , 0xf41 , V_197 | 0x20 ) ;
F_6 ( & V_2 -> V_2 , L_76 ) ;
}
}
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_1 * V_18 = F_4 ( V_20 ,
V_198 , NULL ) ;
T_5 V_197 ;
V_18 = F_4 ( V_20 , V_198 , V_18 ) ;
if ( ! V_18 )
return;
F_17 ( V_18 ) ;
if ( F_5 ( V_2 , 0x76 , & V_197 ) == 0 ) {
if ( V_197 & 0x40 ) {
F_7 ( V_2 , 0x76 , V_197 ^ 0x40 ) ;
F_6 ( & V_2 -> V_2 , L_77 ) ;
}
}
if ( F_5 ( V_2 , 0x72 , & V_197 ) == 0 ) {
if ( V_197 != 0 ) {
F_7 ( V_2 , 0x72 , 0x0 ) ;
F_7 ( V_2 , 0x75 , 0x1 ) ;
F_7 ( V_2 , 0x77 , 0x0 ) ;
F_6 ( & V_2 -> V_2 , L_78 ) ;
}
}
}
static void F_120 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_86 == V_199 ) ||
( V_2 -> V_86 == V_200 ) ||
( V_2 -> V_86 == V_201 ) ||
( V_2 -> V_86 == V_202 ) ||
( ( V_2 -> V_86 == V_203 ) &&
( V_2 -> V_22 & 0xf0 ) == 0x0 ) ) {
if ( V_2 -> V_204 )
V_2 -> V_204 -> V_205 = 0x80 ;
}
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_10 ( V_2 , 0xf4 , & V_15 ) ;
if ( V_15 == 0x05719000 ) {
int V_206 = F_122 ( V_2 ) ;
if ( V_206 > 2048 )
F_123 ( V_2 , 2048 ) ;
}
}
static void F_124 ( struct V_1 * V_2 )
{
T_3 V_73 ;
if ( F_5 ( V_2 , 0xF4 , & V_73 ) == 0 && ! ( V_73 & 0x02 ) ) {
F_6 ( & V_2 -> V_2 , L_79 ) ;
F_7 ( V_2 , 0xF4 , V_73 | 0x02 ) ;
}
}
static void F_125 ( struct V_1 * V_2 )
{
if ( V_207 ) {
F_66 ( V_2 , 0x98 , 0x1 ) ;
F_126 ( 50 ) ;
}
}
static void F_127 ( struct V_1 * V_2 )
{
F_128 () ;
F_51 ( & V_2 -> V_2 , L_80 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 ) {
F_51 ( & V_2 -> V_2 , L_81 ) ;
V_2 -> V_82 -> V_83 |= V_208 ;
}
}
static void F_130 ( struct V_1 * V_209 )
{
struct V_1 * V_210 ;
V_210 = F_131 ( V_209 -> V_51 , F_132 ( 1 , 0 ) ) ;
if ( V_210 ) {
if ( V_210 -> V_86 == 0x9602 )
F_129 ( V_210 ) ;
F_17 ( V_210 ) ;
}
}
static int F_133 ( struct V_1 * V_2 )
{
int V_39 , V_211 = 48 ;
V_39 = F_134 ( V_2 , V_212 ) ;
while ( V_39 && V_211 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_213 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_82 ,
V_33 & V_214 ?
L_83 : L_84 ) ;
return ( V_33 & V_214 ) != 0 ;
}
V_39 = F_135 ( V_2 , V_39 ,
V_212 ) ;
}
return 0 ;
}
static void F_136 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 && ! F_133 ( V_2 ) ) {
F_51 ( & V_2 -> V_2 , L_81 ) ;
V_2 -> V_82 -> V_83 |= V_208 ;
}
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_1 * V_54 ;
if ( ! V_2 -> V_82 )
return;
V_54 = F_131 ( V_2 -> V_51 , 0 ) ;
if ( ! V_54 )
return;
if ( ! F_133 ( V_2 ) && ! F_133 ( V_54 ) ) {
F_51 ( & V_2 -> V_2 , L_81 ) ;
V_2 -> V_82 -> V_83 |= V_208 ;
}
F_17 ( V_54 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
int V_39 , V_211 = 48 ;
V_39 = F_134 ( V_2 , V_212 ) ;
while ( V_39 && V_211 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_213 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_85 ) ;
F_7 ( V_2 , V_39 + V_213 ,
V_33 | V_214 ) ;
}
V_39 = F_135 ( V_2 , V_39 ,
V_212 ) ;
}
}
static void F_139 ( struct V_1 * V_2 )
{
const char * V_215 = F_140 ( V_216 ) ;
if ( V_215 &&
( strstr ( V_215 , L_86 ) ||
strstr ( V_215 , L_87 ) ) ) {
F_6 ( & V_2 -> V_2 , L_88 ) ;
V_2 -> V_153 = 1 ;
}
}
static void F_141 ( struct V_1 * V_2 )
{
T_1 V_217 ;
if ( ! F_142 ( V_2 , V_218 ) )
return;
F_10 ( V_2 , 0x74 , & V_217 ) ;
if ( V_217 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_143 ( V_219 L_89 ) ;
V_217 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_66 ( V_2 , 0x74 , V_217 ) ;
}
}
static int F_144 ( struct V_1 * V_2 )
{
int V_39 , V_211 = 48 ;
int V_220 = 0 ;
V_39 = F_134 ( V_2 , V_212 ) ;
while ( V_39 && V_211 -- ) {
T_3 V_33 ;
if ( V_220 < 1 )
V_220 = 1 ;
if ( F_5 ( V_2 , V_39 + V_213 ,
& V_33 ) == 0 ) {
if ( V_33 & V_214 ) {
if ( V_220 < 2 ) {
V_220 = 2 ;
break;
}
}
}
V_39 = F_135 ( V_2 , V_39 ,
V_212 ) ;
}
return V_220 ;
}
static int F_145 ( struct V_1 * V_209 )
{
struct V_1 * V_2 ;
int V_39 ;
int V_29 , V_221 ;
int V_220 = 0 ;
V_221 = V_209 -> V_88 >> 3 ;
for ( V_29 = V_221 + 1 ; V_29 < 0x20 ; V_29 ++ ) {
V_2 = F_131 ( V_209 -> V_51 , F_132 ( V_29 , 0 ) ) ;
if ( ! V_2 )
continue;
V_39 = F_134 ( V_2 , V_222 ) ;
if ( V_39 != 0 ) {
F_17 ( V_2 ) ;
break;
}
if ( F_144 ( V_2 ) ) {
V_220 = 1 ;
F_17 ( V_2 ) ;
break;
}
F_17 ( V_2 ) ;
}
return V_220 ;
}
static int F_146 ( struct V_1 * V_2 )
{
int V_39 , V_223 ;
int V_36 = 0 ;
T_2 V_33 , V_224 ;
V_39 = F_134 ( V_2 , V_222 ) ;
if ( ! V_39 )
goto V_225;
F_32 ( V_2 , V_39 + V_226 , & V_33 ) ;
V_223 = ( ( V_33 >> 10 ) & 1 ) ?
V_227 : V_228 ;
F_32 ( V_2 , V_39 + V_223 , & V_224 ) ;
if ( V_224 & ( 1 << 6 ) )
V_36 = 1 ;
V_225:
return V_36 ;
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_1 * V_209 ;
int V_39 ;
int V_29 , V_221 ;
int V_220 = 0 ;
V_221 = V_2 -> V_88 >> 3 ;
for ( V_29 = V_221 ; V_29 >= 0 ; V_29 -- ) {
V_209 = F_131 ( V_2 -> V_51 , F_132 ( V_29 , 0 ) ) ;
if ( ! V_209 )
continue;
V_39 = F_134 ( V_209 , V_222 ) ;
if ( V_39 != 0 ) {
V_220 = 1 ;
break;
}
F_17 ( V_209 ) ;
}
if ( ! V_220 )
return;
if ( V_209 == V_2 && F_146 ( V_209 ) &&
F_145 ( V_209 ) )
goto V_225;
if ( F_133 ( V_209 ) )
goto V_225;
F_138 ( V_2 ) ;
V_225:
F_17 ( V_209 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
int V_39 , V_211 = 48 ;
V_39 = F_134 ( V_2 , V_212 ) ;
while ( V_39 && V_211 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_213 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_90 ) ;
F_7 ( V_2 , V_39 + V_213 ,
V_33 & ~ V_214 ) ;
}
V_39 = F_135 ( V_2 , V_39 ,
V_212 ) ;
}
}
static void F_149 ( struct V_1 * V_2 , int V_229 )
{
struct V_1 * V_209 ;
int V_39 ;
int V_220 ;
if ( ! F_150 () )
return;
V_220 = F_144 ( V_2 ) ;
if ( V_220 == 0 )
return;
V_209 = F_151 ( 0 , F_132 ( 0 , 0 ) ) ;
if ( V_209 == NULL ) {
F_51 ( & V_2 -> V_2 , L_91 ) ;
return;
}
V_39 = F_134 ( V_209 , V_222 ) ;
if ( V_39 != 0 ) {
if ( V_220 == 1 ) {
if ( V_229 )
F_138 ( V_2 ) ;
else
F_147 ( V_2 ) ;
}
goto V_225;
}
if ( V_220 == 1 )
goto V_225;
F_148 ( V_2 ) ;
V_225:
F_17 ( V_209 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
return F_149 ( V_2 , 1 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
return F_149 ( V_2 , 0 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
V_2 -> V_108 |= V_230 ;
}
static void F_155 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( V_231 , V_232 ,
NULL ) ;
if ( ! V_18 )
return;
if ( ( V_18 -> V_22 < 0x3B ) && ( V_18 -> V_22 >= 0x30 ) )
V_2 -> V_108 |= V_230 ;
F_17 ( V_18 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 < 0x18 ) {
F_6 ( & V_2 -> V_2 , L_92 ) ;
V_2 -> V_108 |= V_230 ;
}
}
static void F_157 ( struct V_1 * V_2 )
{
V_2 -> V_233 = 1 ;
}
static void F_158 ( struct V_1 * V_2 )
{
T_3 V_234 ;
T_3 V_235 ;
T_3 V_236 ;
if ( F_94 ( V_2 -> V_88 ) )
return;
F_5 ( V_2 , 0xB7 , & V_236 ) ;
if ( V_236 & 0x02 )
return;
F_5 ( V_2 , 0x8E , & V_234 ) ;
F_7 ( V_2 , 0x8E , 0xAA ) ;
F_5 ( V_2 , 0x8D , & V_235 ) ;
F_7 ( V_2 , 0x8D , 0xB7 ) ;
F_7 ( V_2 , 0xB7 , V_236 | 0x02 ) ;
F_7 ( V_2 , 0x8E , V_234 ) ;
F_7 ( V_2 , 0x8D , V_235 ) ;
F_159 ( & V_2 -> V_2 , L_93 ) ;
F_159 ( & V_2 -> V_2 , L_94 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
T_3 V_234 ;
T_3 V_236 ;
if ( F_94 ( V_2 -> V_88 ) )
return;
if ( V_2 -> V_86 == V_237 ||
V_2 -> V_86 == V_238 ) {
F_7 ( V_2 , 0xf9 , 0xfc ) ;
F_7 ( V_2 , 0x150 , 0x10 ) ;
F_7 ( V_2 , 0xf9 , 0x00 ) ;
F_7 ( V_2 , 0xfc , 0x01 ) ;
F_7 ( V_2 , 0xe1 , 0x32 ) ;
F_7 ( V_2 , 0xfc , 0x00 ) ;
F_159 ( & V_2 -> V_2 , L_95 ) ;
}
F_5 ( V_2 , 0xCB , & V_236 ) ;
if ( V_236 & 0x02 )
return;
F_5 ( V_2 , 0xCA , & V_234 ) ;
F_7 ( V_2 , 0xCA , 0x57 ) ;
F_7 ( V_2 , 0xCB , V_236 | 0x02 ) ;
F_7 ( V_2 , 0xCA , V_234 ) ;
F_159 ( & V_2 -> V_2 , L_96 ) ;
F_159 ( & V_2 -> V_2 , L_94 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
T_1 V_239 ;
F_10 ( V_2 , V_240 , & V_239 ) ;
F_66 ( V_2 , V_240 , V_239 | V_241 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_97 ) ;
V_2 -> V_55 = V_242 ;
}
static void F_163 ( struct V_1 * V_2 )
{
V_2 -> V_243 = 1 ;
}
static void F_164 ( struct V_1 * V_2 )
{
int V_244 ;
T_2 V_245 ;
if ( V_246 == V_247 )
return;
V_244 = F_32 ( V_2 , 0x48 , & V_245 ) ;
if ( V_244 ) {
F_165 ( & V_2 -> V_2 , L_98 ) ;
return;
}
if ( ! ( V_245 & ( 1 << 10 ) ) )
return;
V_245 &= ~ ( 1 << 10 ) ;
V_244 = F_53 ( V_2 , 0x48 , V_245 ) ;
if ( V_244 ) {
F_165 ( & V_2 -> V_2 , L_99 ) ;
return;
}
F_166 ( L_100 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
int V_248 ;
T_3 V_75 ;
V_248 = F_5 ( V_2 , 0x00D0 , & V_75 ) ;
if ( V_248 )
return;
V_2 -> V_31 [ 2 ] . V_36 = V_2 -> V_31 [ 2 ] . V_37 + ( ( V_249 ) 1 << V_75 ) - 1 ;
V_248 = F_5 ( V_2 , 0x00D1 , & V_75 ) ;
if ( V_248 )
return;
V_2 -> V_31 [ 4 ] . V_36 = V_2 -> V_31 [ 4 ] . V_37 + ( ( V_249 ) 1 << V_75 ) - 1 ;
}
static T_6 F_168 ( struct V_1 * V_2 ,
void (* F_169)( struct V_1 * V_2 ) )
{
T_6 V_250 = F_170 ( 0 , 0 ) ;
F_171 ( & V_2 -> V_2 , L_101 , F_169 ) ;
if ( V_251 ) {
F_172 ( L_102 ,
F_169 , F_173 ( V_252 ) , F_174 ( & V_2 -> V_2 ) ) ;
V_250 = F_175 () ;
}
return V_250 ;
}
static void F_176 ( struct V_1 * V_2 , T_6 V_250 ,
void (* F_169)( struct V_1 * V_2 ) )
{
T_6 V_253 , V_254 ;
unsigned long long V_255 ;
if ( V_251 ) {
V_254 = F_175 () ;
V_253 = F_177 ( V_254 , V_250 ) ;
V_255 = ( unsigned long long ) F_178 ( V_253 ) >> 10 ;
F_172 ( L_103 ,
F_169 , V_255 , F_174 ( & V_2 -> V_2 ) ) ;
}
}
static void F_179 ( struct V_1 * V_2 )
{
void T_4 * V_256 = F_180 ( V_2 , 0 , 0 ) ;
if ( V_256 == NULL ) {
F_51 ( & V_2 -> V_2 , L_104 ) ;
return;
}
if ( F_85 ( V_256 + V_257 ) != 0 ) {
F_51 ( & V_2 -> V_2 , L_105 ) ;
F_86 ( 0 , V_256 + V_257 ) ;
}
F_181 ( V_2 , V_256 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
V_2 -> V_258 = 0 ;
}
static void F_183 ( struct V_1 * V_2 )
{
V_2 -> V_259 = 1 ;
}
static void F_184 ( struct V_1 * V_2 )
{
V_2 -> V_108 |= V_260 ;
}
static void F_185 ( struct V_1 * V_2 )
{
if ( ! F_186 ( V_2 -> V_51 ) )
V_2 -> V_108 |= V_261 ;
}
static void F_187 ( struct V_1 * V_2 )
{
T_7 V_262 , V_263 , V_264 , V_265 ;
if ( ! F_188 ( V_266 , L_106 ) )
return;
if ( F_189 ( V_2 ) != V_267 )
return;
V_262 = F_190 ( & V_2 -> V_2 ) ;
if ( ! V_262 )
return;
if ( F_191 ( F_192 ( V_262 , L_107 , & V_263 ) )
|| F_191 ( F_192 ( V_262 , L_108 , & V_264 ) )
|| F_191 ( F_192 ( V_262 , L_109 , & V_265 ) ) )
return;
F_6 ( & V_2 -> V_2 , L_110 ) ;
F_193 ( V_263 , NULL , 1 ) ;
F_193 ( V_264 , NULL , 0 ) ;
F_194 ( 300 ) ;
F_193 ( V_265 , NULL , 0 ) ;
F_193 ( V_263 , NULL , 0 ) ;
F_193 ( V_265 , NULL , 0 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
struct V_1 * V_268 = NULL ;
struct V_1 * V_269 = NULL ;
if ( ! F_188 ( V_266 , L_106 ) )
return;
if ( F_189 ( V_2 ) != V_270 )
return;
V_268 = F_131 ( V_2 -> V_51 , 0x0 ) ;
if ( V_268 == V_2 )
goto V_225;
if ( ! V_268 || ! V_268 -> V_82 )
goto V_225;
V_269 = F_131 ( V_268 -> V_82 , 0x0 ) ;
if ( ! V_269 )
goto V_225;
if ( V_269 -> V_160 != V_7
|| ( V_269 -> V_86 != 0x1547 && V_269 -> V_86 != 0x156c )
|| V_269 -> V_111 != 0x2222
|| V_269 -> V_114 != 0x1111 )
goto V_225;
F_6 ( & V_2 -> V_2 , L_111 ) ;
F_196 ( & V_2 -> V_2 , & V_269 -> V_2 ) ;
V_225:
F_17 ( V_269 ) ;
F_17 ( V_268 ) ;
}
static void F_197 ( struct V_1 * V_2 , struct V_271 * V_272 ,
struct V_271 * V_36 )
{
T_6 V_250 ;
for (; V_272 < V_36 ; V_272 ++ )
if ( ( V_272 -> V_55 == ( T_1 ) ( V_2 -> V_55 >> V_272 -> V_273 ) ||
V_272 -> V_55 == ( T_1 ) V_274 ) &&
( V_272 -> V_160 == V_2 -> V_160 ||
V_272 -> V_160 == ( T_2 ) V_274 ) &&
( V_272 -> V_86 == V_2 -> V_86 ||
V_272 -> V_86 == ( T_2 ) V_274 ) ) {
V_250 = F_168 ( V_2 , V_272 -> V_275 ) ;
V_272 -> V_275 ( V_2 ) ;
F_176 ( V_2 , V_250 , V_272 -> V_275 ) ;
}
}
void F_198 ( enum V_276 V_277 , struct V_1 * V_2 )
{
struct V_271 * V_37 , * V_36 ;
switch ( V_277 ) {
case V_278 :
V_37 = V_279 ;
V_36 = V_280 ;
break;
case V_281 :
V_37 = V_282 ;
V_36 = V_283 ;
break;
case V_284 :
if ( ! V_285 )
return;
V_37 = V_286 ;
V_36 = V_287 ;
break;
case V_288 :
V_37 = V_289 ;
V_36 = V_290 ;
break;
case V_291 :
V_37 = V_292 ;
V_36 = V_293 ;
break;
case V_294 :
V_37 = V_295 ;
V_36 = V_296 ;
break;
case V_297 :
V_37 = V_298 ;
V_36 = V_299 ;
break;
case V_300 :
V_37 = V_301 ;
V_36 = V_302 ;
break;
default:
return;
}
F_197 ( V_2 , V_37 , V_36 ) ;
}
static int T_8 F_199 ( void )
{
struct V_1 * V_2 = NULL ;
T_3 V_303 = 0 ;
T_3 V_79 ;
if ( V_304 )
F_143 ( V_305 L_112 ,
V_304 << 2 ) ;
V_285 = true ;
F_200 (dev) {
F_198 ( V_284 , V_2 ) ;
if ( ! V_304 ) {
F_5 ( V_2 , V_306 , & V_79 ) ;
if ( ! V_303 )
V_303 = V_79 ;
if ( ! V_79 || V_303 == V_79 )
continue;
F_143 ( V_305 L_113 ,
V_303 << 2 , V_79 << 2 ,
V_307 << 2 ) ;
V_304 = V_307 ;
}
}
if ( ! V_304 ) {
F_143 ( V_305 L_114 ,
V_303 << 2 , V_307 << 2 ) ;
V_304 = V_303 ? V_303 : V_307 ;
}
return 0 ;
}
static int F_201 ( struct V_1 * V_2 , int V_308 )
{
int V_39 ;
if ( V_2 -> V_55 == V_309 ) {
V_39 = F_142 ( V_2 , V_310 ) ;
if ( ! V_39 )
return - V_311 ;
if ( V_308 )
return 0 ;
F_7 ( V_2 , V_39 + 0x4 , 1 ) ;
F_194 ( 100 ) ;
return 0 ;
} else {
return - V_311 ;
}
}
static int F_202 ( struct V_1 * V_2 , int V_308 )
{
if ( V_308 )
return 0 ;
if ( ! F_203 ( V_2 ) )
F_165 ( & V_2 -> V_2 , L_115 ) ;
F_204 ( V_2 , V_312 , V_313 ) ;
F_194 ( 100 ) ;
return 0 ;
}
static int F_205 ( struct V_1 * V_2 , int V_308 )
{
void T_4 * V_314 ;
unsigned long V_315 ;
T_1 V_75 ;
if ( V_308 )
return 0 ;
V_314 = F_180 ( V_2 , 0 , 0 ) ;
if ( ! V_314 )
return - V_316 ;
F_206 ( 0x00000002 , V_314 + V_317 ) ;
F_206 ( 0x00000005 , V_314 + V_318 ) ;
V_75 = F_207 ( V_314 + V_319 ) & 0xfffffffe ;
F_206 ( V_75 , V_314 + V_319 ) ;
V_315 = V_320 + F_208 ( V_321 ) ;
do {
V_75 = F_207 ( V_314 + V_322 ) ;
if ( ( V_75 & 0xb0000000 ) == 0 )
goto V_323;
F_194 ( 10 ) ;
} while ( F_209 ( V_320 , V_315 ) );
F_51 ( & V_2 -> V_2 , L_116 ) ;
V_323:
F_206 ( 0x00000002 , V_314 + V_324 ) ;
F_181 ( V_2 , V_314 ) ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 , int V_308 )
{
T_2 V_325 ;
T_2 V_326 ;
if ( ( V_2 -> V_86 & 0xf000 ) != 0x4000 )
return - V_311 ;
if ( V_308 )
return 0 ;
F_32 ( V_2 , V_77 , & V_325 ) ;
F_53 ( V_2 , V_77 ,
V_325 | V_327 ) ;
F_211 ( V_2 ) ;
F_32 ( V_2 , V_2 -> V_328 + V_329 , & V_326 ) ;
if ( ( V_326 & V_330 ) == 0 )
F_53 ( V_2 , V_2 -> V_328 + V_329 ,
V_326 |
V_330 |
V_331 ) ;
if ( ! F_203 ( V_2 ) )
F_165 ( & V_2 -> V_2 , L_115 ) ;
F_204 ( V_2 , V_312 , V_313 ) ;
F_194 ( 100 ) ;
F_212 ( V_2 ) ;
F_53 ( V_2 , V_77 , V_325 ) ;
return 0 ;
}
int F_213 ( struct V_1 * V_2 , int V_308 )
{
const struct V_332 * V_29 ;
for ( V_29 = V_332 ; V_29 -> V_333 ; V_29 ++ ) {
if ( ( V_29 -> V_160 == V_2 -> V_160 ||
V_29 -> V_160 == ( T_2 ) V_274 ) &&
( V_29 -> V_86 == V_2 -> V_86 ||
V_29 -> V_86 == ( T_2 ) V_274 ) )
return V_29 -> V_333 ( V_2 , V_308 ) ;
}
return - V_311 ;
}
static void F_214 ( struct V_1 * V_2 )
{
if ( F_94 ( V_2 -> V_88 ) != 0 ) {
V_2 -> V_334 = F_132 ( F_61 ( V_2 -> V_88 ) , 0 ) ;
V_2 -> V_108 |= V_335 ;
}
}
static void F_215 ( struct V_1 * V_2 )
{
if ( F_94 ( V_2 -> V_88 ) != 1 ) {
V_2 -> V_334 = F_132 ( F_61 ( V_2 -> V_88 ) , 1 ) ;
V_2 -> V_108 |= V_335 ;
}
}
static void F_216 ( struct V_1 * V_2 )
{
const struct V_336 * V_337 ;
V_337 = F_217 ( V_338 , V_2 ) ;
if ( V_337 ) {
V_2 -> V_334 = V_337 -> V_339 ;
V_2 -> V_108 |= V_335 ;
F_6 ( & V_2 -> V_2 , L_117 ,
F_61 ( V_2 -> V_334 ) ,
F_94 ( V_2 -> V_334 ) ) ;
}
}
static void F_218 ( struct V_1 * V_54 )
{
if ( ! F_186 ( V_54 -> V_51 ) &&
V_54 -> V_149 == V_340 &&
! F_219 ( V_54 ) && F_219 ( V_54 -> V_51 -> V_341 ) &&
F_189 ( V_54 -> V_51 -> V_341 ) != V_342 )
V_54 -> V_108 |= V_343 ;
}
static int F_220 ( struct V_1 * V_2 , T_2 V_344 )
{
#ifdef F_221
struct V_345 * V_346 = NULL ;
T_9 V_347 ;
if ( ! V_2 -> V_150 || ! F_186 ( V_2 -> V_51 ) )
return - V_348 ;
V_347 = F_222 ( L_118 , 0 , & V_346 ) ;
if ( F_191 ( V_347 ) )
return - V_348 ;
V_344 &= ( V_349 | V_350 | V_351 | V_352 ) ;
return V_344 & ~ ( V_349 | V_350 ) ? 0 : 1 ;
#else
return - V_348 ;
#endif
}
static bool F_223 ( struct V_1 * V_2 )
{
int V_29 ;
if ( ! F_219 ( V_2 ) || F_189 ( V_2 ) != V_353 )
return false ;
for ( V_29 = 0 ; V_29 < F_224 ( V_354 ) ; V_29 ++ )
if ( V_354 [ V_29 ] == V_2 -> V_86 )
return true ;
return false ;
}
static int F_225 ( struct V_1 * V_2 , T_2 V_344 )
{
T_2 V_33 = V_2 -> V_108 & V_355 ?
V_356 : 0 ;
if ( ! F_223 ( V_2 ) )
return - V_311 ;
return V_344 & ~ V_33 ? 0 : 1 ;
}
static int F_226 ( struct V_1 * V_2 , T_2 V_344 )
{
V_344 &= ~ ( V_357 | V_358 | V_349 |
V_350 | V_359 | V_352 ) ;
return V_344 ? 0 : 1 ;
}
int F_227 ( struct V_1 * V_2 , T_2 V_344 )
{
const struct V_360 * V_29 ;
int V_361 ;
for ( V_29 = V_360 ; V_29 -> V_362 ; V_29 ++ ) {
if ( ( V_29 -> V_160 == V_2 -> V_160 ||
V_29 -> V_160 == ( T_2 ) V_274 ) &&
( V_29 -> V_86 == V_2 -> V_86 ||
V_29 -> V_86 == ( T_2 ) V_274 ) ) {
V_361 = V_29 -> V_362 ( V_2 , V_344 ) ;
if ( V_361 >= 0 )
return V_361 ;
}
}
return - V_311 ;
}
static int F_228 ( struct V_1 * V_2 )
{
T_1 V_131 , V_363 , V_364 ;
void T_4 * V_365 ;
F_229 ( V_2 -> V_51 , F_132 ( 31 , 0 ) ,
V_366 , & V_131 ) ;
if ( ! ( V_131 & V_367 ) )
return - V_368 ;
V_365 = F_83 ( V_131 & V_369 ,
F_230 ( V_370 ) ) ;
if ( ! V_365 )
return - V_316 ;
V_363 = F_85 ( V_365 + V_371 ) ;
V_363 &= V_372 | V_373 ;
if ( V_363 != ( V_372 | V_373 ) ) {
V_364 = F_85 ( V_365 + V_370 ) ;
if ( V_364 & V_374 ) {
F_6 ( & V_2 -> V_2 , L_119 ) ;
V_364 &= ~ V_374 ;
F_86 ( V_364 , V_365 + V_370 ) ;
}
}
F_88 ( V_365 ) ;
return 0 ;
}
static void F_231 ( struct V_1 * V_2 )
{
T_1 V_375 ;
F_10 ( V_2 , V_376 , & V_375 ) ;
if ( ! ( V_375 & V_377 ) ) {
F_6 ( & V_2 -> V_2 , L_120 ) ;
V_375 |= V_377 ;
F_53 ( V_2 , V_376 , V_375 ) ;
}
}
static int F_232 ( struct V_1 * V_2 )
{
if ( ! F_223 ( V_2 ) )
return - V_311 ;
if ( F_228 ( V_2 ) ) {
F_51 ( & V_2 -> V_2 , L_121 ) ;
return 0 ;
}
F_231 ( V_2 ) ;
V_2 -> V_108 |= V_355 ;
F_6 ( & V_2 -> V_2 , L_122 ) ;
return 0 ;
}
void F_233 ( struct V_1 * V_2 )
{
const struct V_378 * V_29 ;
int V_361 ;
for ( V_29 = V_378 ; V_29 -> V_379 ; V_29 ++ ) {
if ( ( V_29 -> V_160 == V_2 -> V_160 ||
V_29 -> V_160 == ( T_2 ) V_274 ) &&
( V_29 -> V_86 == V_2 -> V_86 ||
V_29 -> V_86 == ( T_2 ) V_274 ) ) {
V_361 = V_29 -> V_379 ( V_2 ) ;
if ( V_361 >= 0 )
return;
}
}
}
