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
if ( V_2 -> V_82 == 0 && V_2 -> V_51 -> V_83 == 0 )
V_84 = 1 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_85 && V_2 -> V_22 <= 0x12 ) {
F_6 ( & V_2 -> V_2 , L_52 ,
V_2 -> V_22 ) ;
V_2 -> V_85 -> V_86 |= V_87 ;
}
}
static void F_60 ( struct V_1 * V_5 )
{
T_3 V_88 ;
F_5 ( V_5 , 0x42 , & V_88 ) ;
V_88 &= 0xf ;
if ( V_88 && ( V_88 != 2 ) )
V_5 -> V_88 = V_88 ;
}
static void F_61 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_89 ) {
case V_21 :
V_90 = F_62 ( V_2 -> V_82 ) ;
V_91 = F_62 ( V_2 -> V_82 ) ;
break;
case V_92 :
case V_93 :
V_90 = 15 ;
break;
case V_94 :
V_90 = 16 ;
break;
case V_23 :
case V_95 :
case V_96 :
case V_97 :
V_90 = 17 ;
break;
}
}
static void F_63 ( struct V_1 * V_2 )
{
T_3 V_88 , V_98 ;
if ( V_90 == - 1 )
return;
V_98 = V_2 -> V_88 ;
if ( ! V_98 || V_98 > 15 )
return;
if ( V_2 -> V_51 -> V_83 != 0 || F_62 ( V_2 -> V_82 ) > V_91 ||
F_62 ( V_2 -> V_82 ) < V_90 )
return;
F_5 ( V_2 , V_99 , & V_88 ) ;
if ( V_98 != V_88 ) {
F_6 ( & V_2 -> V_2 , L_53 ,
V_88 , V_98 ) ;
F_64 ( 15 ) ;
F_7 ( V_2 , V_99 , V_98 ) ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0xfc , 0 ) ;
F_32 ( V_2 , V_100 , & V_2 -> V_89 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_67 ( V_2 , V_101 , 0 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
T_1 V_102 ;
F_10 ( V_2 , 0x4C , & V_102 ) ;
if ( ( V_102 & 6 ) != 6 ) {
V_102 |= 6 ;
F_51 ( & V_2 -> V_2 , L_54 ) ;
F_67 ( V_2 , 0x4C , V_102 ) ;
F_10 ( V_2 , 0x84 , & V_102 ) ;
V_102 |= ( 1 << 23 ) ;
F_67 ( V_2 , 0x84 , V_102 ) ;
}
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_31 [ 1 ] ;
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0xffffff ;
}
static void F_70 ( struct V_1 * V_2 )
{
V_2 -> V_103 = 1 ;
}
static void F_71 ( struct V_1 * V_2 )
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
static void F_72 ( struct V_1 * V_54 )
{
T_2 V_104 ;
if ( V_54 -> V_22 != 0x04 )
return;
F_32 ( V_54 , 0x40 , & V_104 ) ;
if ( V_104 & ( 1 << 6 ) ) {
V_104 &= ~ ( 1 << 6 ) ;
F_53 ( V_54 , 0x40 , V_104 ) ;
F_6 ( & V_54 -> V_2 , L_56 ) ;
}
}
static void F_73 ( struct V_1 * V_54 )
{
T_3 V_79 ;
F_5 ( V_54 , V_105 , & V_79 ) ;
if ( V_79 == 0x01 ) {
F_5 ( V_54 , 0x40 , & V_79 ) ;
F_7 ( V_54 , 0x40 , V_79 | 1 ) ;
F_7 ( V_54 , 0x9 , 1 ) ;
F_7 ( V_54 , 0xa , 6 ) ;
F_7 ( V_54 , 0x40 , V_79 ) ;
V_54 -> V_55 = V_106 ;
F_6 ( & V_54 -> V_2 , L_57 ) ;
}
}
static void F_74 ( struct V_1 * V_54 )
{
T_3 V_107 ;
F_5 ( V_54 , V_108 , & V_107 ) ;
if ( V_107 & 5 ) {
V_107 &= ~ 5 ;
V_54 -> V_55 &= ~ 5 ;
F_7 ( V_54 , V_108 , V_107 ) ;
}
}
static void F_75 ( struct V_1 * V_54 )
{
T_3 V_107 ;
F_5 ( V_54 , V_108 , & V_107 ) ;
if ( ( ( V_107 & 1 ) && ! ( V_107 & 4 ) ) || ( ( V_107 & 4 ) && ! ( V_107 & 1 ) ) ) {
F_6 ( & V_54 -> V_2 , L_58 ) ;
V_107 &= ~ 5 ;
V_54 -> V_55 &= ~ 5 ;
F_7 ( V_54 , V_108 , V_107 ) ;
}
}
static void F_76 ( struct V_1 * V_54 )
{
V_54 -> V_109 |= V_110 ;
}
static void F_77 ( struct V_1 * V_2 )
{
V_2 -> V_55 = V_111 << 8 ;
}
static void F_78 ( struct V_1 * V_2 )
{
if ( F_79 ( V_2 -> V_112 == V_113 ) ) {
if ( V_2 -> V_89 == V_114 )
switch ( V_2 -> V_115 ) {
case 0x8025 :
case 0x8070 :
case 0x8088 :
case 0x1626 :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_117 )
switch ( V_2 -> V_115 ) {
case 0x80b1 :
case 0x80b2 :
case 0x8093 :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_118 )
switch ( V_2 -> V_115 ) {
case 0x8030 :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_119 )
switch ( V_2 -> V_115 ) {
case 0x8070 :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_120 )
switch ( V_2 -> V_115 ) {
case 0x80c9 :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_121 )
switch ( V_2 -> V_115 ) {
case 0x1751 :
case 0x1821 :
case 0x1897 :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_122 )
switch ( V_2 -> V_115 ) {
case 0x184b :
case 0x186a :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_123 )
switch ( V_2 -> V_115 ) {
case 0x80f2 :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_124 )
switch ( V_2 -> V_115 ) {
case 0x1882 :
case 0x1977 :
V_116 = 1 ;
}
} else if ( F_79 ( V_2 -> V_112 == V_125 ) ) {
if ( V_2 -> V_89 == V_122 )
switch ( V_2 -> V_115 ) {
case 0x088C :
case 0x0890 :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_123 )
switch ( V_2 -> V_115 ) {
case 0x12bc :
case 0x12bd :
case 0x006a :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_126 )
switch ( V_2 -> V_115 ) {
case 0x12bf :
V_116 = 1 ;
}
} else if ( F_79 ( V_2 -> V_112 == V_127 ) ) {
if ( V_2 -> V_89 == V_122 )
switch ( V_2 -> V_115 ) {
case 0xC00C :
V_116 = 1 ;
}
} else if ( F_79 ( V_2 -> V_112 == V_128 ) ) {
if ( V_2 -> V_89 == V_122 )
switch ( V_2 -> V_115 ) {
case 0x0058 :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_129 )
switch ( V_2 -> V_115 ) {
case 0xB16C :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_130 )
switch ( V_2 -> V_115 ) {
case 0x00b8 :
case 0x00b9 :
case 0x00ba :
V_116 = 1 ;
}
else if ( V_2 -> V_89 == V_131 )
switch ( V_2 -> V_115 ) {
case 0x001A :
V_116 = 1 ;
}
}
}
static void F_80 ( struct V_1 * V_2 )
{
T_2 V_75 ;
if ( F_81 ( ! V_116 ) )
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
static void F_82 ( struct V_1 * V_2 )
{
T_1 V_132 ;
if ( F_81 ( ! V_116 ) )
return;
F_83 ( V_133 ) ;
F_10 ( V_2 , 0xF0 , & V_132 ) ;
V_133 = F_84 ( V_132 & 0xFFFFC000 , 0x4000 ) ;
if ( V_133 == NULL )
return;
}
static void F_85 ( struct V_1 * V_2 )
{
T_1 V_75 ;
if ( F_81 ( ! V_116 || ! V_133 ) )
return;
V_75 = F_86 ( V_133 + 0x3418 ) ;
F_87 ( V_75 & 0xFFFFFFF7 , V_133 + 0x3418 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
if ( F_81 ( ! V_116 || ! V_133 ) )
return;
F_89 ( V_133 ) ;
V_133 = NULL ;
F_6 ( & V_2 -> V_2 , L_61 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_82 ( V_2 ) ;
F_85 ( V_2 ) ;
F_88 ( V_2 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
T_3 V_75 = 0 ;
F_5 ( V_2 , 0x77 , & V_75 ) ;
if ( V_75 & 0x10 ) {
F_6 ( & V_2 -> V_2 , L_62 ) ;
F_7 ( V_2 , 0x77 , V_75 & ~ 0x10 ) ;
}
}
static void F_92 ( struct V_1 * V_2 )
{
T_3 V_73 ;
T_2 V_134 ;
F_5 ( V_2 , V_135 , & V_73 ) ;
F_7 ( V_2 , V_135 , V_73 | ( 1 << 6 ) ) ;
F_32 ( V_2 , V_100 , & V_134 ) ;
if ( ( ( V_134 & 0xfff0 ) != 0x0960 ) && ( V_134 != 0x0018 ) ) {
F_7 ( V_2 , V_135 , V_73 ) ;
return;
}
V_2 -> V_89 = V_134 ;
F_91 ( V_2 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
T_3 V_75 ;
int V_136 = 0 ;
if ( F_81 ( V_2 -> V_112 == V_113 ) ) {
if ( V_2 -> V_89 == V_92 )
V_136 = 1 ;
}
if ( ! V_136 )
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
static void F_94 ( struct V_1 * V_54 )
{
T_1 V_137 , V_138 , V_55 ;
T_3 V_139 ;
if ( F_95 ( V_54 -> V_82 ) )
return;
F_10 ( V_54 , 0x40 , & V_137 ) ;
F_10 ( V_54 , 0x80 , & V_138 ) ;
V_137 &= ~ 0x00CFF302 ;
V_138 &= ~ ( 1 << 24 ) ;
switch ( V_54 -> V_89 ) {
case V_140 :
case V_141 :
case V_142 :
V_137 |= 0x0002A100 ;
break;
case V_143 :
case V_144 :
V_138 |= ( 1 << 24 ) ;
case V_145 :
case V_146 :
case V_147 :
V_137 |= 0x00C2A1B3 ;
break;
case V_148 :
V_137 |= 0x00C00000 ;
break;
}
F_67 ( V_54 , 0x40 , V_137 ) ;
F_67 ( V_54 , 0x80 , V_138 ) ;
F_5 ( V_54 , V_149 , & V_139 ) ;
V_54 -> V_150 = V_139 & 0x7f ;
V_54 -> V_151 = ! ! ( V_139 & 0x80 ) ;
F_10 ( V_54 , V_152 , & V_55 ) ;
V_54 -> V_55 = V_55 >> 8 ;
}
static void F_96 ( struct V_1 * V_54 )
{
int V_29 ;
if ( ( V_54 -> V_55 >> 8 ) != 0xff00 )
return;
if ( F_97 ( V_54 , 0 ) && F_30 ( V_54 , 0 ) )
F_98 ( & V_153 , & V_54 -> V_31 [ 0 ] ) ;
for ( V_29 = 1 ; V_29 < 6 ; V_29 ++ )
memset ( & V_54 -> V_31 [ V_29 ] , 0 , sizeof( V_54 -> V_31 [ V_29 ] ) ) ;
}
static void F_99 ( struct V_1 * V_54 )
{
F_100 ( V_54 ) ;
V_54 -> V_154 = 1 ;
}
static void F_101 ( struct V_1 * V_2 )
{
F_100 ( V_2 ) ;
V_2 -> V_154 = 1 ;
F_51 ( & V_2 -> V_2 , L_65 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
V_155 = 120 ;
V_2 -> V_156 = 1 ;
}
static void F_103 ( struct V_1 * V_2 )
{
if ( V_157 || V_158 )
return;
V_2 -> V_159 = V_160 ;
F_6 ( & V_2 -> V_2 , L_66 ,
V_2 -> V_161 , V_2 -> V_89 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
T_2 V_162 ;
if ( V_157 )
return;
F_32 ( V_2 , V_163 , & V_162 ) ;
V_162 |= V_164 ;
F_53 ( V_2 , V_163 , V_162 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_161 , V_2 -> V_89 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_1 V_165 ;
T_3 V_88 ;
if ( V_157 )
return;
F_10 ( V_2 , V_166 , & V_165 ) ;
F_67 ( V_2 , V_166 , V_165 |
V_167 ) ;
for ( V_88 = 0x10 ; V_88 < 0x10 + 32 ; V_88 ++ ) {
F_106 ( V_88 , V_168 ) ;
F_106 ( 0x00 , V_169 ) ;
}
F_67 ( V_2 , V_166 , V_165 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_161 , V_2 -> V_89 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
T_1 V_165 ;
if ( V_157 )
return;
if ( ( V_2 -> V_22 == V_170 ) ||
( V_2 -> V_22 == V_171 ) )
return;
F_10 ( V_2 , V_172 , & V_165 ) ;
V_165 &= ~ V_173 ;
F_67 ( V_2 , V_172 , V_165 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_161 , V_2 -> V_89 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
T_2 V_162 ;
if ( V_157 )
return;
F_32 ( V_2 , V_174 , & V_162 ) ;
if ( ! V_162 ) {
F_6 ( & V_2 -> V_2 , L_68 ,
V_2 -> V_161 , V_2 -> V_89 ) ;
return;
}
F_53 ( V_2 , V_174 , 0 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_161 , V_2 -> V_89 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_31 [ 0 ] ;
if ( V_32 -> V_37 & 0x8 ) {
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0xf ;
}
}
static void F_110 ( struct V_1 * V_2 )
{
unsigned int V_175 ;
if ( V_2 -> V_22 >= 2 )
return;
for ( V_175 = 0 ; V_175 <= 1 ; V_175 ++ )
if ( F_30 ( V_2 , V_175 ) == 0x80 &&
( F_97 ( V_2 , V_175 ) & 0x80 ) ) {
struct V_31 * V_32 = & V_2 -> V_31 [ V_175 ] ;
F_6 ( & V_2 -> V_2 , L_69 ,
V_175 ) ;
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0xff ;
}
}
static void F_111 ( struct V_1 * V_2 )
{
unsigned int V_176 = ( V_2 -> V_115 & 0xf0 ) >> 4 ;
unsigned int V_177 = V_2 -> V_115 & 0xf ;
switch ( V_2 -> V_89 ) {
case V_178 :
if ( V_2 -> V_112 == V_179 &&
V_2 -> V_115 == 0x0299 )
return;
case V_180 :
case V_181 :
case V_182 :
case V_183 :
if ( V_176 ) {
F_6 ( & V_2 -> V_2 , L_70 ,
V_2 -> V_89 , V_176 , V_177 ) ;
V_2 -> V_55 = ( V_184 << 8 ) |
( V_2 -> V_55 & 0xff ) ;
}
}
}
static void F_112 ( struct V_1 * V_2 )
{
T_2 V_76 , V_185 ;
T_3 T_4 * V_186 ;
T_3 V_187 ;
switch ( V_2 -> V_89 ) {
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
if ( ! ( V_76 & V_188 ) || ! F_97 ( V_2 , 0 ) )
return;
if ( V_2 -> V_189 ) {
F_32 ( V_2 , V_2 -> V_189 + V_190 , & V_185 ) ;
if ( ( V_185 & V_191 ) != V_192 )
return;
}
V_186 = F_113 ( F_97 ( V_2 , 0 ) , 8 ) ;
if ( ! V_186 ) {
F_51 ( & V_2 -> V_2 , L_71 ) ;
return;
}
V_187 = F_114 ( V_186 + 3 ) ;
if ( V_187 == 0 ) {
F_51 ( & V_2 -> V_2 , L_72 ) ;
F_115 ( 1 , V_186 + 3 ) ;
}
F_89 ( V_186 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_73 ) ;
F_117 ( V_2 , V_193 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
if ( V_2 -> V_55 == V_194 ) {
F_6 ( & V_2 -> V_2 , L_74 ) ;
V_2 -> V_55 = V_195 ;
}
}
static void F_119 ( struct V_1 * V_2 )
{
T_2 V_196 ;
F_32 ( V_2 , 0x40 , & V_196 ) ;
if ( V_196 & 0x200 ) {
F_6 ( & V_2 -> V_2 , L_75 ) ;
V_2 -> V_197 = 1 ;
}
}
static void F_120 ( struct V_1 * V_2 )
{
T_5 V_198 ;
if ( F_5 ( V_2 , 0xf41 , & V_198 ) == 0 ) {
if ( ! ( V_198 & 0x20 ) ) {
F_7 ( V_2 , 0xf41 , V_198 | 0x20 ) ;
F_6 ( & V_2 -> V_2 , L_76 ) ;
}
}
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_1 * V_18 = F_4 ( V_20 ,
V_199 , NULL ) ;
T_5 V_198 ;
V_18 = F_4 ( V_20 , V_199 , V_18 ) ;
if ( ! V_18 )
return;
F_17 ( V_18 ) ;
if ( F_5 ( V_2 , 0x76 , & V_198 ) == 0 ) {
if ( V_198 & 0x40 ) {
F_7 ( V_2 , 0x76 , V_198 ^ 0x40 ) ;
F_6 ( & V_2 -> V_2 , L_77 ) ;
}
}
if ( F_5 ( V_2 , 0x72 , & V_198 ) == 0 ) {
if ( V_198 != 0 ) {
F_7 ( V_2 , 0x72 , 0x0 ) ;
F_7 ( V_2 , 0x75 , 0x1 ) ;
F_7 ( V_2 , 0x77 , 0x0 ) ;
F_6 ( & V_2 -> V_2 , L_78 ) ;
}
}
}
static void F_122 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_89 == V_200 ) ||
( V_2 -> V_89 == V_201 ) ||
( V_2 -> V_89 == V_202 ) ||
( V_2 -> V_89 == V_203 ) ||
( ( V_2 -> V_89 == V_204 ) &&
( V_2 -> V_22 & 0xf0 ) == 0x0 ) ) {
if ( V_2 -> V_205 )
V_2 -> V_205 -> V_206 = 0x80 ;
}
}
static void F_123 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_10 ( V_2 , 0xf4 , & V_15 ) ;
if ( V_15 == 0x05719000 ) {
int V_207 = F_124 ( V_2 ) ;
if ( V_207 > 2048 )
F_125 ( V_2 , 2048 ) ;
}
}
static void F_126 ( struct V_1 * V_2 )
{
T_3 V_73 ;
if ( F_5 ( V_2 , 0xF4 , & V_73 ) == 0 && ! ( V_73 & 0x02 ) ) {
F_6 ( & V_2 -> V_2 , L_79 ) ;
F_7 ( V_2 , 0xF4 , V_73 | 0x02 ) ;
}
}
static void F_127 ( struct V_1 * V_2 )
{
if ( V_208 ) {
F_67 ( V_2 , 0x98 , 0x1 ) ;
F_128 ( 50 ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
F_130 () ;
F_51 ( & V_2 -> V_2 , L_80 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
if ( V_2 -> V_85 ) {
F_51 ( & V_2 -> V_2 , L_81 ) ;
V_2 -> V_85 -> V_86 |= V_209 ;
}
}
static void F_132 ( struct V_1 * V_210 )
{
struct V_1 * V_211 ;
V_211 = F_133 ( V_210 -> V_51 , F_134 ( 1 , 0 ) ) ;
if ( V_211 ) {
if ( V_211 -> V_89 == 0x9602 )
F_131 ( V_211 ) ;
F_17 ( V_211 ) ;
}
}
static int F_135 ( struct V_1 * V_2 )
{
int V_39 , V_212 = 48 ;
V_39 = F_136 ( V_2 , V_213 ) ;
while ( V_39 && V_212 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_214 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_82 ,
V_33 & V_215 ?
L_83 : L_84 ) ;
return ( V_33 & V_215 ) != 0 ;
}
V_39 = F_137 ( V_2 , V_39 ,
V_213 ) ;
}
return 0 ;
}
static void F_138 ( struct V_1 * V_2 )
{
if ( V_2 -> V_85 && ! F_135 ( V_2 ) ) {
F_51 ( & V_2 -> V_2 , L_81 ) ;
V_2 -> V_85 -> V_86 |= V_209 ;
}
}
static void F_139 ( struct V_1 * V_2 )
{
struct V_1 * V_54 ;
if ( ! V_2 -> V_85 )
return;
V_54 = F_133 ( V_2 -> V_51 , 0 ) ;
if ( ! V_54 )
return;
if ( ! F_135 ( V_2 ) && ! F_135 ( V_54 ) ) {
F_51 ( & V_2 -> V_2 , L_81 ) ;
V_2 -> V_85 -> V_86 |= V_209 ;
}
F_17 ( V_54 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
int V_39 , V_212 = 48 ;
V_39 = F_136 ( V_2 , V_213 ) ;
while ( V_39 && V_212 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_214 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_85 ) ;
F_7 ( V_2 , V_39 + V_214 ,
V_33 | V_215 ) ;
}
V_39 = F_137 ( V_2 , V_39 ,
V_213 ) ;
}
}
static void F_141 ( struct V_1 * V_2 )
{
const char * V_216 = F_142 ( V_217 ) ;
if ( V_216 &&
( strstr ( V_216 , L_86 ) ||
strstr ( V_216 , L_87 ) ) ) {
F_6 ( & V_2 -> V_2 , L_88 ) ;
V_2 -> V_154 = 1 ;
}
}
static void F_143 ( struct V_1 * V_2 )
{
T_1 V_218 ;
if ( ! F_144 ( V_2 , V_219 ) )
return;
F_10 ( V_2 , 0x74 , & V_218 ) ;
if ( V_218 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_145 ( V_220 L_89 ) ;
V_218 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_67 ( V_2 , 0x74 , V_218 ) ;
}
}
static int F_146 ( struct V_1 * V_2 )
{
int V_39 , V_212 = 48 ;
int V_221 = 0 ;
V_39 = F_136 ( V_2 , V_213 ) ;
while ( V_39 && V_212 -- ) {
T_3 V_33 ;
if ( V_221 < 1 )
V_221 = 1 ;
if ( F_5 ( V_2 , V_39 + V_214 ,
& V_33 ) == 0 ) {
if ( V_33 & V_215 ) {
if ( V_221 < 2 ) {
V_221 = 2 ;
break;
}
}
}
V_39 = F_137 ( V_2 , V_39 ,
V_213 ) ;
}
return V_221 ;
}
static int F_147 ( struct V_1 * V_210 )
{
struct V_1 * V_2 ;
int V_39 ;
int V_29 , V_222 ;
int V_221 = 0 ;
V_222 = V_210 -> V_82 >> 3 ;
for ( V_29 = V_222 + 1 ; V_29 < 0x20 ; V_29 ++ ) {
V_2 = F_133 ( V_210 -> V_51 , F_134 ( V_29 , 0 ) ) ;
if ( ! V_2 )
continue;
V_39 = F_136 ( V_2 , V_223 ) ;
if ( V_39 != 0 ) {
F_17 ( V_2 ) ;
break;
}
if ( F_146 ( V_2 ) ) {
V_221 = 1 ;
F_17 ( V_2 ) ;
break;
}
F_17 ( V_2 ) ;
}
return V_221 ;
}
static int F_148 ( struct V_1 * V_2 )
{
int V_39 , V_224 ;
int V_36 = 0 ;
T_2 V_33 , V_225 ;
V_39 = F_136 ( V_2 , V_223 ) ;
if ( ! V_39 )
goto V_226;
F_32 ( V_2 , V_39 + V_227 , & V_33 ) ;
V_224 = ( ( V_33 >> 10 ) & 1 ) ?
V_228 : V_229 ;
F_32 ( V_2 , V_39 + V_224 , & V_225 ) ;
if ( V_225 & ( 1 << 6 ) )
V_36 = 1 ;
V_226:
return V_36 ;
}
static void F_149 ( struct V_1 * V_2 )
{
struct V_1 * V_210 ;
int V_39 ;
int V_29 , V_222 ;
int V_221 = 0 ;
V_222 = V_2 -> V_82 >> 3 ;
for ( V_29 = V_222 ; V_29 >= 0 ; V_29 -- ) {
V_210 = F_133 ( V_2 -> V_51 , F_134 ( V_29 , 0 ) ) ;
if ( ! V_210 )
continue;
V_39 = F_136 ( V_210 , V_223 ) ;
if ( V_39 != 0 ) {
V_221 = 1 ;
break;
}
F_17 ( V_210 ) ;
}
if ( ! V_221 )
return;
if ( V_210 == V_2 && F_148 ( V_210 ) &&
F_147 ( V_210 ) )
goto V_226;
if ( F_135 ( V_210 ) )
goto V_226;
F_140 ( V_2 ) ;
V_226:
F_17 ( V_210 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
int V_39 , V_212 = 48 ;
V_39 = F_136 ( V_2 , V_213 ) ;
while ( V_39 && V_212 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_214 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_90 ) ;
F_7 ( V_2 , V_39 + V_214 ,
V_33 & ~ V_215 ) ;
}
V_39 = F_137 ( V_2 , V_39 ,
V_213 ) ;
}
}
static void F_151 ( struct V_1 * V_2 , int V_230 )
{
struct V_1 * V_210 ;
int V_39 ;
int V_221 ;
if ( ! F_152 () )
return;
V_221 = F_146 ( V_2 ) ;
if ( V_221 == 0 )
return;
V_210 = F_153 ( 0 , F_134 ( 0 , 0 ) ) ;
if ( V_210 == NULL ) {
F_51 ( & V_2 -> V_2 , L_91 ) ;
return;
}
V_39 = F_136 ( V_210 , V_223 ) ;
if ( V_39 != 0 ) {
if ( V_221 == 1 ) {
if ( V_230 )
F_140 ( V_2 ) ;
else
F_149 ( V_2 ) ;
}
goto V_226;
}
if ( V_221 == 1 )
goto V_226;
F_150 ( V_2 ) ;
V_226:
F_17 ( V_210 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
return F_151 ( V_2 , 1 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
return F_151 ( V_2 , 0 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
V_2 -> V_109 |= V_231 ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( V_232 , V_233 ,
NULL ) ;
if ( ! V_18 )
return;
if ( ( V_18 -> V_22 < 0x3B ) && ( V_18 -> V_22 >= 0x30 ) )
V_2 -> V_109 |= V_231 ;
F_17 ( V_18 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 < 0x18 ) {
F_6 ( & V_2 -> V_2 , L_92 ) ;
V_2 -> V_109 |= V_231 ;
}
}
static void F_159 ( struct V_1 * V_2 )
{
V_2 -> V_234 = 1 ;
}
static void F_160 ( struct V_1 * V_2 )
{
T_3 V_235 ;
T_3 V_236 ;
T_3 V_237 ;
if ( F_95 ( V_2 -> V_82 ) )
return;
F_5 ( V_2 , 0xB7 , & V_237 ) ;
if ( V_237 & 0x02 )
return;
F_5 ( V_2 , 0x8E , & V_235 ) ;
F_7 ( V_2 , 0x8E , 0xAA ) ;
F_5 ( V_2 , 0x8D , & V_236 ) ;
F_7 ( V_2 , 0x8D , 0xB7 ) ;
F_7 ( V_2 , 0xB7 , V_237 | 0x02 ) ;
F_7 ( V_2 , 0x8E , V_235 ) ;
F_7 ( V_2 , 0x8D , V_236 ) ;
F_161 ( & V_2 -> V_2 , L_93 ) ;
F_161 ( & V_2 -> V_2 , L_94 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
T_3 V_235 ;
T_3 V_237 ;
if ( F_95 ( V_2 -> V_82 ) )
return;
if ( V_2 -> V_89 == V_238 ||
V_2 -> V_89 == V_239 ) {
F_7 ( V_2 , 0xf9 , 0xfc ) ;
F_7 ( V_2 , 0x150 , 0x10 ) ;
F_7 ( V_2 , 0xf9 , 0x00 ) ;
F_7 ( V_2 , 0xfc , 0x01 ) ;
F_7 ( V_2 , 0xe1 , 0x32 ) ;
F_7 ( V_2 , 0xfc , 0x00 ) ;
F_161 ( & V_2 -> V_2 , L_95 ) ;
}
F_5 ( V_2 , 0xCB , & V_237 ) ;
if ( V_237 & 0x02 )
return;
F_5 ( V_2 , 0xCA , & V_235 ) ;
F_7 ( V_2 , 0xCA , 0x57 ) ;
F_7 ( V_2 , 0xCB , V_237 | 0x02 ) ;
F_7 ( V_2 , 0xCA , V_235 ) ;
F_161 ( & V_2 -> V_2 , L_96 ) ;
F_161 ( & V_2 -> V_2 , L_94 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
T_1 V_240 ;
F_10 ( V_2 , V_241 , & V_240 ) ;
F_67 ( V_2 , V_241 , V_240 | V_242 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_97 ) ;
V_2 -> V_55 = V_243 ;
}
static void F_165 ( struct V_1 * V_2 )
{
V_2 -> V_244 = 1 ;
}
static void F_166 ( struct V_1 * V_2 )
{
int V_245 ;
T_2 V_246 ;
if ( V_247 == V_248 )
return;
V_245 = F_32 ( V_2 , 0x48 , & V_246 ) ;
if ( V_245 ) {
F_167 ( & V_2 -> V_2 , L_98 ) ;
return;
}
if ( ! ( V_246 & ( 1 << 10 ) ) )
return;
V_246 &= ~ ( 1 << 10 ) ;
V_245 = F_53 ( V_2 , 0x48 , V_246 ) ;
if ( V_245 ) {
F_167 ( & V_2 -> V_2 , L_99 ) ;
return;
}
F_168 ( L_100 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
int V_249 ;
T_3 V_75 ;
V_249 = F_5 ( V_2 , 0x00D0 , & V_75 ) ;
if ( V_249 )
return;
V_2 -> V_31 [ 2 ] . V_36 = V_2 -> V_31 [ 2 ] . V_37 + ( ( V_250 ) 1 << V_75 ) - 1 ;
V_249 = F_5 ( V_2 , 0x00D1 , & V_75 ) ;
if ( V_249 )
return;
V_2 -> V_31 [ 4 ] . V_36 = V_2 -> V_31 [ 4 ] . V_37 + ( ( V_250 ) 1 << V_75 ) - 1 ;
}
static T_6 F_170 ( struct V_1 * V_2 ,
void (* F_171)( struct V_1 * V_2 ) )
{
T_6 V_251 = F_172 ( 0 , 0 ) ;
F_173 ( & V_2 -> V_2 , L_101 , F_171 ) ;
if ( V_252 ) {
F_174 ( L_102 ,
F_171 , F_175 ( V_253 ) , F_176 ( & V_2 -> V_2 ) ) ;
V_251 = F_177 () ;
}
return V_251 ;
}
static void F_178 ( struct V_1 * V_2 , T_6 V_251 ,
void (* F_171)( struct V_1 * V_2 ) )
{
T_6 V_254 , V_255 ;
unsigned long long V_256 ;
if ( V_252 ) {
V_255 = F_177 () ;
V_254 = F_179 ( V_255 , V_251 ) ;
V_256 = ( unsigned long long ) F_180 ( V_254 ) >> 10 ;
F_174 ( L_103 ,
F_171 , V_256 , F_176 ( & V_2 -> V_2 ) ) ;
}
}
static void F_181 ( struct V_1 * V_2 )
{
void T_4 * V_257 = F_182 ( V_2 , 0 , 0 ) ;
if ( V_257 == NULL ) {
F_51 ( & V_2 -> V_2 , L_104 ) ;
return;
}
if ( F_86 ( V_257 + V_258 ) != 0 ) {
F_51 ( & V_2 -> V_2 , L_105 ) ;
F_87 ( 0 , V_257 + V_258 ) ;
}
F_183 ( V_2 , V_257 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
V_2 -> V_259 = 0 ;
}
static void F_185 ( struct V_1 * V_2 )
{
V_2 -> V_260 = 1 ;
}
static void F_186 ( struct V_1 * V_2 )
{
V_2 -> V_109 |= V_261 ;
}
static void F_187 ( struct V_1 * V_2 )
{
if ( ! F_188 ( V_2 -> V_51 ) )
V_2 -> V_109 |= V_262 ;
}
static void F_189 ( struct V_1 * V_2 )
{
T_7 V_263 , V_264 , V_265 , V_266 ;
if ( ! F_190 ( V_267 , L_106 ) )
return;
if ( F_191 ( V_2 ) != V_268 )
return;
V_263 = F_192 ( & V_2 -> V_2 ) ;
if ( ! V_263 )
return;
if ( F_193 ( F_194 ( V_263 , L_107 , & V_264 ) )
|| F_193 ( F_194 ( V_263 , L_108 , & V_265 ) )
|| F_193 ( F_194 ( V_263 , L_109 , & V_266 ) ) )
return;
F_6 ( & V_2 -> V_2 , L_110 ) ;
F_195 ( V_264 , NULL , 1 ) ;
F_195 ( V_265 , NULL , 0 ) ;
F_196 ( 300 ) ;
F_195 ( V_266 , NULL , 0 ) ;
F_195 ( V_264 , NULL , 0 ) ;
F_195 ( V_266 , NULL , 0 ) ;
}
static void F_197 ( struct V_1 * V_2 )
{
struct V_1 * V_269 = NULL ;
struct V_1 * V_270 = NULL ;
if ( ! F_190 ( V_267 , L_106 ) )
return;
if ( F_191 ( V_2 ) != V_271 )
return;
V_269 = F_133 ( V_2 -> V_51 , 0x0 ) ;
if ( V_269 == V_2 )
goto V_226;
if ( ! V_269 || ! V_269 -> V_85 )
goto V_226;
V_270 = F_133 ( V_269 -> V_85 , 0x0 ) ;
if ( ! V_270 )
goto V_226;
if ( V_270 -> V_161 != V_7
|| ( V_270 -> V_89 != 0x1547 && V_270 -> V_89 != 0x156c )
|| V_270 -> V_112 != 0x2222
|| V_270 -> V_115 != 0x1111 )
goto V_226;
F_6 ( & V_2 -> V_2 , L_111 ) ;
F_198 ( & V_2 -> V_2 , & V_270 -> V_2 ) ;
V_226:
F_17 ( V_270 ) ;
F_17 ( V_269 ) ;
}
static void F_199 ( struct V_1 * V_2 , struct V_272 * V_273 ,
struct V_272 * V_36 )
{
T_6 V_251 ;
for (; V_273 < V_36 ; V_273 ++ )
if ( ( V_273 -> V_55 == ( T_1 ) ( V_2 -> V_55 >> V_273 -> V_274 ) ||
V_273 -> V_55 == ( T_1 ) V_275 ) &&
( V_273 -> V_161 == V_2 -> V_161 ||
V_273 -> V_161 == ( T_2 ) V_275 ) &&
( V_273 -> V_89 == V_2 -> V_89 ||
V_273 -> V_89 == ( T_2 ) V_275 ) ) {
V_251 = F_170 ( V_2 , V_273 -> V_276 ) ;
V_273 -> V_276 ( V_2 ) ;
F_178 ( V_2 , V_251 , V_273 -> V_276 ) ;
}
}
void F_200 ( enum V_277 V_278 , struct V_1 * V_2 )
{
struct V_272 * V_37 , * V_36 ;
switch ( V_278 ) {
case V_279 :
V_37 = V_280 ;
V_36 = V_281 ;
break;
case V_282 :
V_37 = V_283 ;
V_36 = V_284 ;
break;
case V_285 :
if ( ! V_286 )
return;
V_37 = V_287 ;
V_36 = V_288 ;
break;
case V_289 :
V_37 = V_290 ;
V_36 = V_291 ;
break;
case V_292 :
V_37 = V_293 ;
V_36 = V_294 ;
break;
case V_295 :
V_37 = V_296 ;
V_36 = V_297 ;
break;
case V_298 :
V_37 = V_299 ;
V_36 = V_300 ;
break;
case V_301 :
V_37 = V_302 ;
V_36 = V_303 ;
break;
default:
return;
}
F_199 ( V_2 , V_37 , V_36 ) ;
}
static int T_8 F_201 ( void )
{
struct V_1 * V_2 = NULL ;
T_3 V_304 = 0 ;
T_3 V_79 ;
if ( V_305 )
F_145 ( V_306 L_112 ,
V_305 << 2 ) ;
V_286 = true ;
F_202 (dev) {
F_200 ( V_285 , V_2 ) ;
if ( ! V_305 ) {
F_5 ( V_2 , V_307 , & V_79 ) ;
if ( ! V_304 )
V_304 = V_79 ;
if ( ! V_79 || V_304 == V_79 )
continue;
F_145 ( V_306 L_113 ,
V_304 << 2 , V_79 << 2 ,
V_308 << 2 ) ;
V_305 = V_308 ;
}
}
if ( ! V_305 ) {
F_145 ( V_306 L_114 ,
V_304 << 2 , V_308 << 2 ) ;
V_305 = V_304 ? V_304 : V_308 ;
}
return 0 ;
}
static int F_203 ( struct V_1 * V_2 , int V_309 )
{
int V_39 ;
if ( V_2 -> V_55 == V_310 ) {
V_39 = F_144 ( V_2 , V_311 ) ;
if ( ! V_39 )
return - V_312 ;
if ( V_309 )
return 0 ;
F_7 ( V_2 , V_39 + 0x4 , 1 ) ;
F_196 ( 100 ) ;
return 0 ;
} else {
return - V_312 ;
}
}
static int F_204 ( struct V_1 * V_2 , int V_309 )
{
if ( V_309 )
return 0 ;
if ( ! F_205 ( V_2 ) )
F_167 ( & V_2 -> V_2 , L_115 ) ;
F_206 ( V_2 , V_313 , V_314 ) ;
F_196 ( 100 ) ;
return 0 ;
}
static int F_207 ( struct V_1 * V_2 , int V_309 )
{
void T_4 * V_315 ;
unsigned long V_316 ;
T_1 V_75 ;
if ( V_309 )
return 0 ;
V_315 = F_182 ( V_2 , 0 , 0 ) ;
if ( ! V_315 )
return - V_317 ;
F_208 ( 0x00000002 , V_315 + V_318 ) ;
F_208 ( 0x00000005 , V_315 + V_319 ) ;
V_75 = F_209 ( V_315 + V_320 ) & 0xfffffffe ;
F_208 ( V_75 , V_315 + V_320 ) ;
V_316 = V_321 + F_210 ( V_322 ) ;
do {
V_75 = F_209 ( V_315 + V_323 ) ;
if ( ( V_75 & 0xb0000000 ) == 0 )
goto V_324;
F_196 ( 10 ) ;
} while ( F_211 ( V_321 , V_316 ) );
F_51 ( & V_2 -> V_2 , L_116 ) ;
V_324:
F_208 ( 0x00000002 , V_315 + V_325 ) ;
F_183 ( V_2 , V_315 ) ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 , int V_309 )
{
T_2 V_326 ;
T_2 V_327 ;
if ( ( V_2 -> V_89 & 0xf000 ) != 0x4000 )
return - V_312 ;
if ( V_309 )
return 0 ;
F_32 ( V_2 , V_77 , & V_326 ) ;
F_53 ( V_2 , V_77 ,
V_326 | V_328 ) ;
F_213 ( V_2 ) ;
F_32 ( V_2 , V_2 -> V_329 + V_330 , & V_327 ) ;
if ( ( V_327 & V_331 ) == 0 )
F_53 ( V_2 , V_2 -> V_329 + V_330 ,
V_327 |
V_331 |
V_332 ) ;
if ( ! F_205 ( V_2 ) )
F_167 ( & V_2 -> V_2 , L_115 ) ;
F_206 ( V_2 , V_313 , V_314 ) ;
F_196 ( 100 ) ;
F_214 ( V_2 ) ;
F_53 ( V_2 , V_77 , V_326 ) ;
return 0 ;
}
int F_215 ( struct V_1 * V_2 , int V_309 )
{
const struct V_333 * V_29 ;
for ( V_29 = V_333 ; V_29 -> V_334 ; V_29 ++ ) {
if ( ( V_29 -> V_161 == V_2 -> V_161 ||
V_29 -> V_161 == ( T_2 ) V_275 ) &&
( V_29 -> V_89 == V_2 -> V_89 ||
V_29 -> V_89 == ( T_2 ) V_275 ) )
return V_29 -> V_334 ( V_2 , V_309 ) ;
}
return - V_312 ;
}
static void F_216 ( struct V_1 * V_2 )
{
if ( F_95 ( V_2 -> V_82 ) != 0 ) {
V_2 -> V_335 = F_134 ( F_62 ( V_2 -> V_82 ) , 0 ) ;
V_2 -> V_109 |= V_336 ;
}
}
static void F_217 ( struct V_1 * V_2 )
{
if ( F_95 ( V_2 -> V_82 ) != 1 ) {
V_2 -> V_335 = F_134 ( F_62 ( V_2 -> V_82 ) , 1 ) ;
V_2 -> V_109 |= V_336 ;
}
}
static void F_218 ( struct V_1 * V_2 )
{
const struct V_337 * V_338 ;
V_338 = F_219 ( V_339 , V_2 ) ;
if ( V_338 ) {
V_2 -> V_335 = V_338 -> V_340 ;
V_2 -> V_109 |= V_336 ;
F_6 ( & V_2 -> V_2 , L_117 ,
F_62 ( V_2 -> V_335 ) ,
F_95 ( V_2 -> V_335 ) ) ;
}
}
static void F_220 ( struct V_1 * V_54 )
{
if ( ! F_188 ( V_54 -> V_51 ) &&
V_54 -> V_150 == V_341 &&
! F_221 ( V_54 ) && F_221 ( V_54 -> V_51 -> V_342 ) &&
F_191 ( V_54 -> V_51 -> V_342 ) != V_343 )
V_54 -> V_109 |= V_344 ;
}
static int F_222 ( struct V_1 * V_2 , T_2 V_345 )
{
#ifdef F_223
struct V_346 * V_347 = NULL ;
T_9 V_348 ;
if ( ! V_2 -> V_151 || ! F_188 ( V_2 -> V_51 ) )
return - V_349 ;
V_348 = F_224 ( L_118 , 0 , & V_347 ) ;
if ( F_193 ( V_348 ) )
return - V_349 ;
V_345 &= ( V_350 | V_351 | V_352 | V_353 ) ;
return V_345 & ~ ( V_350 | V_351 ) ? 0 : 1 ;
#else
return - V_349 ;
#endif
}
static bool F_225 ( struct V_1 * V_2 )
{
int V_29 ;
if ( ! F_221 ( V_2 ) || F_191 ( V_2 ) != V_354 )
return false ;
for ( V_29 = 0 ; V_29 < F_226 ( V_355 ) ; V_29 ++ )
if ( V_355 [ V_29 ] == V_2 -> V_89 )
return true ;
return false ;
}
static int F_227 ( struct V_1 * V_2 , T_2 V_345 )
{
T_2 V_33 = V_2 -> V_109 & V_356 ?
V_357 : 0 ;
if ( ! F_225 ( V_2 ) )
return - V_312 ;
return V_345 & ~ V_33 ? 0 : 1 ;
}
static int F_228 ( struct V_1 * V_2 , T_2 V_345 )
{
V_345 &= ~ ( V_358 | V_359 | V_350 |
V_351 | V_360 | V_353 ) ;
return V_345 ? 0 : 1 ;
}
int F_229 ( struct V_1 * V_2 , T_2 V_345 )
{
const struct V_361 * V_29 ;
int V_362 ;
for ( V_29 = V_361 ; V_29 -> V_363 ; V_29 ++ ) {
if ( ( V_29 -> V_161 == V_2 -> V_161 ||
V_29 -> V_161 == ( T_2 ) V_275 ) &&
( V_29 -> V_89 == V_2 -> V_89 ||
V_29 -> V_89 == ( T_2 ) V_275 ) ) {
V_362 = V_29 -> V_363 ( V_2 , V_345 ) ;
if ( V_362 >= 0 )
return V_362 ;
}
}
return - V_312 ;
}
static int F_230 ( struct V_1 * V_2 )
{
T_1 V_132 , V_364 , V_365 ;
void T_4 * V_366 ;
F_231 ( V_2 -> V_51 , F_134 ( 31 , 0 ) ,
V_367 , & V_132 ) ;
if ( ! ( V_132 & V_368 ) )
return - V_369 ;
V_366 = F_84 ( V_132 & V_370 ,
F_232 ( V_371 ) ) ;
if ( ! V_366 )
return - V_317 ;
V_364 = F_86 ( V_366 + V_372 ) ;
V_364 &= V_373 | V_374 ;
if ( V_364 != ( V_373 | V_374 ) ) {
V_365 = F_86 ( V_366 + V_371 ) ;
if ( V_365 & V_375 ) {
F_6 ( & V_2 -> V_2 , L_119 ) ;
V_365 &= ~ V_375 ;
F_87 ( V_365 , V_366 + V_371 ) ;
}
}
F_89 ( V_366 ) ;
return 0 ;
}
static void F_233 ( struct V_1 * V_2 )
{
T_1 V_376 ;
F_10 ( V_2 , V_377 , & V_376 ) ;
if ( ! ( V_376 & V_378 ) ) {
F_6 ( & V_2 -> V_2 , L_120 ) ;
V_376 |= V_378 ;
F_53 ( V_2 , V_377 , V_376 ) ;
}
}
static int F_234 ( struct V_1 * V_2 )
{
if ( ! F_225 ( V_2 ) )
return - V_312 ;
if ( F_230 ( V_2 ) ) {
F_51 ( & V_2 -> V_2 , L_121 ) ;
return 0 ;
}
F_233 ( V_2 ) ;
V_2 -> V_109 |= V_356 ;
F_6 ( & V_2 -> V_2 , L_122 ) ;
return 0 ;
}
void F_235 ( struct V_1 * V_2 )
{
const struct V_379 * V_29 ;
int V_362 ;
for ( V_29 = V_379 ; V_29 -> V_380 ; V_29 ++ ) {
if ( ( V_29 -> V_161 == V_2 -> V_161 ||
V_29 -> V_161 == ( T_2 ) V_275 ) &&
( V_29 -> V_89 == V_2 -> V_89 ||
V_29 -> V_89 == ( T_2 ) V_275 ) ) {
V_362 = V_29 -> V_380 ( V_2 ) ;
if ( V_362 >= 0 )
return;
}
}
}
