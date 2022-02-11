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
T_1 V_55 = V_54 -> V_55 ;
V_54 -> V_55 = ( V_56 << 8 ) | 0xfe ;
F_6 ( & V_54 -> V_2 , L_15 ,
V_55 , V_54 -> V_55 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_31 ( V_2 , 0xE0 , 64 , V_57 , L_16 ) ;
F_31 ( V_2 , 0xE2 , 32 , V_57 + 1 , L_17 ) ;
}
static void F_38 ( struct V_1 * V_2 , const char * V_41 , unsigned int V_52 , unsigned int V_58 )
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
static void F_39 ( struct V_1 * V_2 , const char * V_41 , unsigned int V_52 , unsigned int V_58 )
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
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_63 ;
F_31 ( V_2 , 0x40 , 64 , V_57 , L_20 ) ;
F_31 ( V_2 , 0x90 , 16 , V_57 + 1 , L_21 ) ;
F_10 ( V_2 , 0x5c , & V_63 ) ;
F_38 ( V_2 , L_22 , 0x60 , 3 << 21 ) ;
F_38 ( V_2 , L_23 , 0x64 , 3 << 21 ) ;
if ( V_63 & ( 1 << 29 ) ) {
F_38 ( V_2 , L_24 , 0x68 , 1 << 20 ) ;
F_39 ( V_2 , L_25 , 0x6c , 1 << 7 ) ;
}
if ( V_63 & ( 1 << 30 ) ) {
F_38 ( V_2 , L_26 , 0x70 , 1 << 20 ) ;
F_39 ( V_2 , L_27 , 0x74 , 1 << 7 ) ;
}
F_38 ( V_2 , L_28 , 0x78 , 1 << 20 ) ;
F_38 ( V_2 , L_29 , 0x7c , 1 << 20 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_3 V_58 ;
F_5 ( V_2 , V_64 , & V_58 ) ;
if ( V_58 & V_65 )
F_31 ( V_2 , V_66 , 128 , V_57 ,
L_30 ) ;
F_5 ( V_2 , V_67 , & V_58 ) ;
if ( V_58 & V_68 )
F_31 ( V_2 , V_69 , 64 , V_57 + 1 ,
L_31 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_3 V_58 ;
F_5 ( V_2 , V_64 , & V_58 ) ;
if ( V_58 & V_70 )
F_31 ( V_2 , V_66 , 128 , V_57 ,
L_32 ) ;
F_5 ( V_2 , V_71 , & V_58 ) ;
if ( V_58 & V_72 )
F_31 ( V_2 , V_73 , 64 , V_57 + 1 ,
L_33 ) ;
}
static void F_43 ( struct V_1 * V_2 , unsigned V_74 , const char * V_41 , int V_75 )
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
static void F_44 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
F_43 ( V_2 , 0x84 , L_34 , 0 ) ;
F_43 ( V_2 , 0x88 , L_35 , 1 ) ;
}
static void F_45 ( struct V_1 * V_2 , unsigned V_74 , const char * V_41 )
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
static void F_46 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
F_45 ( V_2 , 0x84 , L_37 ) ;
F_45 ( V_2 , 0x88 , L_38 ) ;
F_45 ( V_2 , 0x8c , L_39 ) ;
F_45 ( V_2 , 0x90 , L_40 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 & 0x10 )
F_31 ( V_2 , 0x48 , 256 , V_57 ,
L_41 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_47 ( V_2 ) ;
F_31 ( V_2 , 0x70 , 128 , V_57 + 1 ,
L_42 ) ;
F_31 ( V_2 , 0x90 , 16 , V_57 + 2 , L_43 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_31 ( V_2 , 0x88 , 128 , V_57 , L_44 ) ;
F_31 ( V_2 , 0xd0 , 16 , V_57 + 1 , L_45 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_1 * V_54 ;
T_2 V_77 ;
F_51 ( & V_2 -> V_2 , L_46 ) ;
F_52 (pdev, &dev->subordinate->devices, bus_list) {
F_32 ( V_54 , V_78 , & V_77 ) ;
if ( V_77 & V_79 )
F_53 ( V_54 , V_78 , V_77 & ~ V_79 ) ;
}
}
static void F_54 ( struct V_1 * V_2 )
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
static void F_55 ( struct V_1 * V_2 )
{
T_3 V_82 ;
#define F_56 8
F_5 ( V_2 , 0x5B , & V_82 ) ;
if ( ! ( V_82 & F_56 ) ) {
F_6 ( & V_2 -> V_2 , L_50 ) ;
F_7 ( V_2 , 0x5B , V_82 | F_56 ) ;
}
}
static void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 >= 0x02 ) {
F_51 ( & V_2 -> V_2 , L_51 ) ;
F_51 ( & V_2 -> V_2 , L_52 ) ;
}
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 && V_2 -> V_22 <= 0x12 ) {
F_6 ( & V_2 -> V_2 , L_53 ,
V_2 -> V_22 ) ;
V_2 -> V_83 -> V_84 |= V_85 ;
}
}
static void F_59 ( struct V_1 * V_5 )
{
T_3 V_86 ;
F_5 ( V_5 , 0x42 , & V_86 ) ;
V_86 &= 0xf ;
if ( V_86 && ( V_86 != 2 ) )
V_5 -> V_86 = V_86 ;
}
static void F_60 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_87 ) {
case V_21 :
V_88 = F_61 ( V_2 -> V_89 ) ;
V_90 = F_61 ( V_2 -> V_89 ) ;
break;
case V_91 :
case V_92 :
V_88 = 15 ;
break;
case V_93 :
V_88 = 16 ;
break;
case V_23 :
case V_94 :
case V_95 :
case V_96 :
V_88 = 17 ;
break;
}
}
static void F_62 ( struct V_1 * V_2 )
{
T_3 V_86 , V_97 ;
if ( V_88 == - 1 )
return;
V_97 = V_2 -> V_86 ;
if ( ! V_97 || V_97 > 15 )
return;
if ( V_2 -> V_51 -> V_98 != 0 || F_61 ( V_2 -> V_89 ) > V_90 ||
F_61 ( V_2 -> V_89 ) < V_88 )
return;
F_5 ( V_2 , V_99 , & V_86 ) ;
if ( V_97 != V_86 ) {
F_6 ( & V_2 -> V_2 , L_54 ,
V_86 , V_97 ) ;
F_63 ( 15 ) ;
F_7 ( V_2 , V_99 , V_97 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0xfc , 0 ) ;
F_32 ( V_2 , V_100 , & V_2 -> V_87 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_66 ( V_2 , V_101 , 0 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
T_1 V_102 ;
F_10 ( V_2 , 0x4C , & V_102 ) ;
if ( ( V_102 & 6 ) != 6 ) {
V_102 |= 6 ;
F_51 ( & V_2 -> V_2 , L_55 ) ;
F_66 ( V_2 , 0x4C , V_102 ) ;
F_10 ( V_2 , 0x84 , & V_102 ) ;
V_102 |= ( 1 << 23 ) ;
F_66 ( V_2 , 0x84 , V_102 ) ;
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
V_2 -> V_103 = 1 ;
}
static void F_70 ( struct V_1 * V_2 )
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
static void F_71 ( struct V_1 * V_54 )
{
T_2 V_104 ;
if ( V_54 -> V_22 != 0x04 )
return;
F_32 ( V_54 , 0x40 , & V_104 ) ;
if ( V_104 & ( 1 << 6 ) ) {
V_104 &= ~ ( 1 << 6 ) ;
F_53 ( V_54 , 0x40 , V_104 ) ;
F_6 ( & V_54 -> V_2 , L_57 ) ;
}
}
static void F_72 ( struct V_1 * V_54 )
{
T_3 V_80 ;
F_5 ( V_54 , V_105 , & V_80 ) ;
if ( V_80 == 0x01 ) {
F_5 ( V_54 , 0x40 , & V_80 ) ;
F_7 ( V_54 , 0x40 , V_80 | 1 ) ;
F_7 ( V_54 , 0x9 , 1 ) ;
F_7 ( V_54 , 0xa , 6 ) ;
F_7 ( V_54 , 0x40 , V_80 ) ;
V_54 -> V_55 = V_106 ;
F_6 ( & V_54 -> V_2 , L_58 ) ;
}
}
static void F_73 ( struct V_1 * V_54 )
{
T_3 V_107 ;
F_5 ( V_54 , V_108 , & V_107 ) ;
if ( V_107 & 5 ) {
V_107 &= ~ 5 ;
V_54 -> V_55 &= ~ 5 ;
F_7 ( V_54 , V_108 , V_107 ) ;
}
}
static void F_74 ( struct V_1 * V_54 )
{
T_3 V_107 ;
F_5 ( V_54 , V_108 , & V_107 ) ;
if ( ( ( V_107 & 1 ) && ! ( V_107 & 4 ) ) || ( ( V_107 & 4 ) && ! ( V_107 & 1 ) ) ) {
F_6 ( & V_54 -> V_2 , L_59 ) ;
V_107 &= ~ 5 ;
V_54 -> V_55 &= ~ 5 ;
F_7 ( V_54 , V_108 , V_107 ) ;
}
}
static void F_75 ( struct V_1 * V_54 )
{
V_54 -> V_109 |= V_110 ;
}
static void F_76 ( struct V_1 * V_2 )
{
V_2 -> V_55 = V_111 << 8 ;
}
static void F_77 ( struct V_1 * V_2 )
{
if ( F_78 ( V_2 -> V_112 == V_113 ) ) {
if ( V_2 -> V_87 == V_114 )
switch ( V_2 -> V_115 ) {
case 0x8025 :
case 0x8070 :
case 0x8088 :
case 0x1626 :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_117 )
switch ( V_2 -> V_115 ) {
case 0x80b1 :
case 0x80b2 :
case 0x8093 :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_118 )
switch ( V_2 -> V_115 ) {
case 0x8030 :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_119 )
switch ( V_2 -> V_115 ) {
case 0x8070 :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_120 )
switch ( V_2 -> V_115 ) {
case 0x80c9 :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_121 )
switch ( V_2 -> V_115 ) {
case 0x1751 :
case 0x1821 :
case 0x1897 :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_122 )
switch ( V_2 -> V_115 ) {
case 0x184b :
case 0x186a :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_123 )
switch ( V_2 -> V_115 ) {
case 0x80f2 :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_124 )
switch ( V_2 -> V_115 ) {
case 0x1882 :
case 0x1977 :
V_116 = 1 ;
}
} else if ( F_78 ( V_2 -> V_112 == V_125 ) ) {
if ( V_2 -> V_87 == V_122 )
switch ( V_2 -> V_115 ) {
case 0x088C :
case 0x0890 :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_123 )
switch ( V_2 -> V_115 ) {
case 0x12bc :
case 0x12bd :
case 0x006a :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_126 )
switch ( V_2 -> V_115 ) {
case 0x12bf :
V_116 = 1 ;
}
} else if ( F_78 ( V_2 -> V_112 == V_127 ) ) {
if ( V_2 -> V_87 == V_122 )
switch ( V_2 -> V_115 ) {
case 0xC00C :
V_116 = 1 ;
}
} else if ( F_78 ( V_2 -> V_112 == V_128 ) ) {
if ( V_2 -> V_87 == V_122 )
switch ( V_2 -> V_115 ) {
case 0x0058 :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_129 )
switch ( V_2 -> V_115 ) {
case 0xB16C :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_130 )
switch ( V_2 -> V_115 ) {
case 0x00b8 :
case 0x00b9 :
case 0x00ba :
V_116 = 1 ;
}
else if ( V_2 -> V_87 == V_131 )
switch ( V_2 -> V_115 ) {
case 0x001A :
V_116 = 1 ;
}
}
}
static void F_79 ( struct V_1 * V_2 )
{
T_2 V_76 ;
if ( F_80 ( ! V_116 ) )
return;
F_32 ( V_2 , 0xF2 , & V_76 ) ;
if ( V_76 & 0x8 ) {
F_53 ( V_2 , 0xF2 , V_76 & ( ~ 0x8 ) ) ;
F_32 ( V_2 , 0xF2 , & V_76 ) ;
if ( V_76 & 0x8 )
F_6 ( & V_2 -> V_2 , L_60 ,
V_76 ) ;
else
F_6 ( & V_2 -> V_2 , L_61 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
T_1 V_132 ;
if ( F_80 ( ! V_116 ) )
return;
F_82 ( V_133 ) ;
F_10 ( V_2 , 0xF0 , & V_132 ) ;
V_133 = F_83 ( V_132 & 0xFFFFC000 , 0x4000 ) ;
if ( V_133 == NULL )
return;
}
static void F_84 ( struct V_1 * V_2 )
{
T_1 V_76 ;
if ( F_80 ( ! V_116 || ! V_133 ) )
return;
V_76 = F_85 ( V_133 + 0x3418 ) ;
F_86 ( V_76 & 0xFFFFFFF7 , V_133 + 0x3418 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
if ( F_80 ( ! V_116 || ! V_133 ) )
return;
F_88 ( V_133 ) ;
V_133 = NULL ;
F_6 ( & V_2 -> V_2 , L_62 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_81 ( V_2 ) ;
F_84 ( V_2 ) ;
F_87 ( V_2 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
T_3 V_76 = 0 ;
F_5 ( V_2 , 0x77 , & V_76 ) ;
if ( V_76 & 0x10 ) {
F_6 ( & V_2 -> V_2 , L_63 ) ;
F_7 ( V_2 , 0x77 , V_76 & ~ 0x10 ) ;
}
}
static void F_91 ( struct V_1 * V_2 )
{
T_3 V_74 ;
T_2 V_134 ;
F_5 ( V_2 , V_135 , & V_74 ) ;
F_7 ( V_2 , V_135 , V_74 | ( 1 << 6 ) ) ;
F_32 ( V_2 , V_100 , & V_134 ) ;
if ( ( ( V_134 & 0xfff0 ) != 0x0960 ) && ( V_134 != 0x0018 ) ) {
F_7 ( V_2 , V_135 , V_74 ) ;
return;
}
V_2 -> V_87 = V_134 ;
F_90 ( V_2 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
T_3 V_76 ;
int V_136 = 0 ;
if ( F_80 ( V_2 -> V_112 == V_113 ) ) {
if ( V_2 -> V_87 == V_91 )
V_136 = 1 ;
}
if ( ! V_136 )
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
static void F_93 ( struct V_1 * V_54 )
{
T_1 V_137 , V_138 , V_55 ;
T_3 V_139 ;
if ( F_94 ( V_54 -> V_89 ) )
return;
F_10 ( V_54 , 0x40 , & V_137 ) ;
F_10 ( V_54 , 0x80 , & V_138 ) ;
V_137 &= ~ 0x00CFF302 ;
V_138 &= ~ ( 1 << 24 ) ;
switch ( V_54 -> V_87 ) {
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
F_66 ( V_54 , 0x40 , V_137 ) ;
F_66 ( V_54 , 0x80 , V_138 ) ;
F_5 ( V_54 , V_149 , & V_139 ) ;
V_54 -> V_150 = V_139 & 0x7f ;
V_54 -> V_151 = ! ! ( V_139 & 0x80 ) ;
F_10 ( V_54 , V_152 , & V_55 ) ;
V_54 -> V_55 = V_55 >> 8 ;
}
static void F_95 ( struct V_1 * V_2 )
{
if ( V_2 -> V_151 ) {
F_96 ( & V_2 -> V_2 ) ;
F_6 ( & V_2 -> V_2 , L_66 ) ;
}
}
static void F_97 ( struct V_1 * V_54 )
{
int V_29 ;
if ( ( V_54 -> V_55 >> 8 ) != 0xff00 )
return;
if ( F_98 ( V_54 , 0 ) && F_30 ( V_54 , 0 ) )
F_99 ( & V_153 , & V_54 -> V_31 [ 0 ] ) ;
for ( V_29 = 1 ; V_29 < 6 ; V_29 ++ )
memset ( & V_54 -> V_31 [ V_29 ] , 0 , sizeof( V_54 -> V_31 [ V_29 ] ) ) ;
}
static void F_100 ( struct V_1 * V_54 )
{
V_54 -> V_154 = 1 ;
}
static void F_101 ( struct V_1 * V_2 )
{
V_2 -> V_154 = 1 ;
F_51 ( & V_2 -> V_2 , L_67 ) ;
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
F_6 ( & V_2 -> V_2 , L_68 ,
V_2 -> V_161 , V_2 -> V_87 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
T_2 V_162 ;
if ( V_157 )
return;
F_32 ( V_2 , V_163 , & V_162 ) ;
V_162 |= V_164 ;
F_53 ( V_2 , V_163 , V_162 ) ;
F_6 ( & V_2 -> V_2 , L_69 ,
V_2 -> V_161 , V_2 -> V_87 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_1 V_165 ;
T_3 V_86 ;
if ( V_157 )
return;
F_10 ( V_2 , V_166 , & V_165 ) ;
F_66 ( V_2 , V_166 , V_165 |
V_167 ) ;
for ( V_86 = 0x10 ; V_86 < 0x10 + 32 ; V_86 ++ ) {
F_106 ( V_86 , V_168 ) ;
F_106 ( 0x00 , V_169 ) ;
}
F_66 ( V_2 , V_166 , V_165 ) ;
F_6 ( & V_2 -> V_2 , L_69 ,
V_2 -> V_161 , V_2 -> V_87 ) ;
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
F_66 ( V_2 , V_172 , V_165 ) ;
F_6 ( & V_2 -> V_2 , L_69 ,
V_2 -> V_161 , V_2 -> V_87 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
T_2 V_162 ;
if ( V_157 )
return;
F_32 ( V_2 , V_174 , & V_162 ) ;
if ( ! V_162 ) {
F_6 ( & V_2 -> V_2 , L_70 ,
V_2 -> V_161 , V_2 -> V_87 ) ;
return;
}
F_53 ( V_2 , V_174 , 0 ) ;
F_6 ( & V_2 -> V_2 , L_69 ,
V_2 -> V_161 , V_2 -> V_87 ) ;
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
( F_98 ( V_2 , V_175 ) & 0x80 ) ) {
struct V_31 * V_32 = & V_2 -> V_31 [ V_175 ] ;
F_6 ( & V_2 -> V_2 , L_71 ,
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
switch ( V_2 -> V_87 ) {
case V_178 :
if ( V_2 -> V_112 == V_179 &&
V_2 -> V_115 == 0x0299 )
return;
case V_180 :
case V_181 :
case V_182 :
case V_183 :
if ( V_176 ) {
F_6 ( & V_2 -> V_2 , L_72 ,
V_2 -> V_87 , V_176 , V_177 ) ;
V_2 -> V_55 = ( V_184 << 8 ) |
( V_2 -> V_55 & 0xff ) ;
}
}
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_1 * V_185 ;
if ( ! F_94 ( V_2 -> V_89 ) )
return;
V_185 = F_113 ( V_2 -> V_51 , F_114 ( F_61 ( V_2 -> V_89 ) , 0 ) ) ;
if ( ! V_185 )
return;
if ( V_185 -> V_186 && V_2 -> V_55 == V_185 -> V_55 &&
V_2 -> V_161 == V_185 -> V_161 && V_2 -> V_87 == V_185 -> V_87 )
V_2 -> V_109 |= V_187 ;
F_17 ( V_185 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
T_2 V_77 , V_188 ;
T_3 T_4 * V_189 ;
T_3 V_190 ;
switch ( V_2 -> V_87 ) {
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
F_32 ( V_2 , V_78 , & V_77 ) ;
if ( ! ( V_77 & V_191 ) || ! F_98 ( V_2 , 0 ) )
return;
if ( V_2 -> V_192 ) {
F_32 ( V_2 , V_2 -> V_192 + V_193 , & V_188 ) ;
if ( ( V_188 & V_194 ) != V_195 )
return;
}
V_189 = F_116 ( F_98 ( V_2 , 0 ) , 8 ) ;
if ( ! V_189 ) {
F_51 ( & V_2 -> V_2 , L_73 ) ;
return;
}
V_190 = F_117 ( V_189 + 3 ) ;
if ( V_190 == 0 ) {
F_51 ( & V_2 -> V_2 , L_74 ) ;
F_118 ( 1 , V_189 + 3 ) ;
}
F_88 ( V_189 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_75 ) ;
F_120 ( V_2 , V_196 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_55 = V_2 -> V_55 ;
if ( V_55 )
return;
V_2 -> V_55 = V_197 << 8 ;
F_6 ( & V_2 -> V_2 , L_76 ,
V_55 , V_2 -> V_55 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
T_2 V_198 ;
F_32 ( V_2 , 0x40 , & V_198 ) ;
if ( V_198 & 0x200 ) {
F_6 ( & V_2 -> V_2 , L_77 ) ;
V_2 -> V_199 = 1 ;
}
}
static void F_123 ( struct V_1 * V_2 )
{
T_5 V_200 ;
if ( F_5 ( V_2 , 0xf41 , & V_200 ) == 0 ) {
if ( ! ( V_200 & 0x20 ) ) {
F_7 ( V_2 , 0xf41 , V_200 | 0x20 ) ;
F_6 ( & V_2 -> V_2 , L_78 ) ;
}
}
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_1 * V_18 = F_4 ( V_20 ,
V_201 , NULL ) ;
T_5 V_200 ;
V_18 = F_4 ( V_20 , V_201 , V_18 ) ;
if ( ! V_18 )
return;
F_17 ( V_18 ) ;
if ( F_5 ( V_2 , 0x76 , & V_200 ) == 0 ) {
if ( V_200 & 0x40 ) {
F_7 ( V_2 , 0x76 , V_200 ^ 0x40 ) ;
F_6 ( & V_2 -> V_2 , L_79 ) ;
}
}
if ( F_5 ( V_2 , 0x72 , & V_200 ) == 0 ) {
if ( V_200 != 0 ) {
F_7 ( V_2 , 0x72 , 0x0 ) ;
F_7 ( V_2 , 0x75 , 0x1 ) ;
F_7 ( V_2 , 0x77 , 0x0 ) ;
F_6 ( & V_2 -> V_2 , L_80 ) ;
}
}
}
static void F_125 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_87 == V_202 ) ||
( V_2 -> V_87 == V_203 ) ||
( V_2 -> V_87 == V_204 ) ||
( V_2 -> V_87 == V_205 ) ||
( ( V_2 -> V_87 == V_206 ) &&
( V_2 -> V_22 & 0xf0 ) == 0x0 ) ) {
if ( V_2 -> V_186 )
V_2 -> V_186 -> V_207 = 0x80 ;
}
}
static void F_126 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_10 ( V_2 , 0xf4 , & V_15 ) ;
if ( V_15 == 0x05719000 ) {
int V_208 = F_127 ( V_2 ) ;
if ( V_208 > 2048 )
F_128 ( V_2 , 2048 ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
T_3 V_74 ;
if ( F_5 ( V_2 , 0xF4 , & V_74 ) == 0 && ! ( V_74 & 0x02 ) ) {
F_6 ( & V_2 -> V_2 , L_81 ) ;
F_7 ( V_2 , 0xF4 , V_74 | 0x02 ) ;
}
}
static void F_130 ( struct V_1 * V_2 )
{
if ( V_209 ) {
F_66 ( V_2 , 0x98 , 0x1 ) ;
F_131 ( 50 ) ;
}
}
static void F_132 ( struct V_1 * V_2 )
{
F_133 () ;
F_51 ( & V_2 -> V_2 , L_82 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 ) {
F_51 ( & V_2 -> V_2 , L_83 ) ;
V_2 -> V_83 -> V_84 |= V_210 ;
}
}
static void F_135 ( struct V_1 * V_211 )
{
struct V_1 * V_212 ;
V_212 = F_113 ( V_211 -> V_51 , F_114 ( 1 , 0 ) ) ;
if ( V_212 ) {
if ( V_212 -> V_87 == 0x9602 )
F_134 ( V_212 ) ;
F_17 ( V_212 ) ;
}
}
static int F_136 ( struct V_1 * V_2 )
{
int V_39 , V_213 = V_214 ;
V_39 = F_137 ( V_2 , V_215 ) ;
while ( V_39 && V_213 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_216 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_84 ,
V_33 & V_217 ?
L_85 : L_86 ) ;
return ( V_33 & V_217 ) != 0 ;
}
V_39 = F_138 ( V_2 , V_39 ,
V_215 ) ;
}
return 0 ;
}
static void F_139 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 && ! F_136 ( V_2 ) ) {
F_51 ( & V_2 -> V_2 , L_83 ) ;
V_2 -> V_83 -> V_84 |= V_210 ;
}
}
static void F_140 ( struct V_1 * V_2 )
{
struct V_1 * V_54 ;
if ( ! V_2 -> V_83 )
return;
V_54 = F_113 ( V_2 -> V_51 , 0 ) ;
if ( ! V_54 )
return;
if ( ! F_136 ( V_2 ) && ! F_136 ( V_54 ) ) {
F_51 ( & V_2 -> V_2 , L_83 ) ;
V_2 -> V_83 -> V_84 |= V_210 ;
}
F_17 ( V_54 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
int V_39 , V_213 = V_214 ;
V_39 = F_137 ( V_2 , V_215 ) ;
while ( V_39 && V_213 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_216 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_87 ) ;
F_7 ( V_2 , V_39 + V_216 ,
V_33 | V_217 ) ;
}
V_39 = F_138 ( V_2 , V_39 ,
V_215 ) ;
}
}
static void F_142 ( struct V_1 * V_2 )
{
const char * V_218 = F_143 ( V_219 ) ;
if ( V_218 &&
( strstr ( V_218 , L_88 ) ||
strstr ( V_218 , L_89 ) ) ) {
F_6 ( & V_2 -> V_2 , L_90 ) ;
V_2 -> V_154 = 1 ;
}
}
static void F_144 ( struct V_1 * V_2 )
{
T_1 V_220 ;
if ( ! F_145 ( V_2 , V_221 ) )
return;
F_10 ( V_2 , 0x74 , & V_220 ) ;
if ( V_220 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_146 ( V_222 L_91 ) ;
V_220 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_66 ( V_2 , 0x74 , V_220 ) ;
}
}
static int F_147 ( struct V_1 * V_2 )
{
int V_39 , V_213 = V_214 ;
int V_223 = 0 ;
V_39 = F_137 ( V_2 , V_215 ) ;
while ( V_39 && V_213 -- ) {
T_3 V_33 ;
if ( V_223 < 1 )
V_223 = 1 ;
if ( F_5 ( V_2 , V_39 + V_216 ,
& V_33 ) == 0 ) {
if ( V_33 & V_217 ) {
if ( V_223 < 2 ) {
V_223 = 2 ;
break;
}
}
}
V_39 = F_138 ( V_2 , V_39 ,
V_215 ) ;
}
return V_223 ;
}
static int F_148 ( struct V_1 * V_211 )
{
struct V_1 * V_2 ;
int V_39 ;
int V_29 , V_224 ;
int V_223 = 0 ;
V_224 = V_211 -> V_89 >> 3 ;
for ( V_29 = V_224 + 1 ; V_29 < 0x20 ; V_29 ++ ) {
V_2 = F_113 ( V_211 -> V_51 , F_114 ( V_29 , 0 ) ) ;
if ( ! V_2 )
continue;
V_39 = F_137 ( V_2 , V_225 ) ;
if ( V_39 != 0 ) {
F_17 ( V_2 ) ;
break;
}
if ( F_147 ( V_2 ) ) {
V_223 = 1 ;
F_17 ( V_2 ) ;
break;
}
F_17 ( V_2 ) ;
}
return V_223 ;
}
static int F_149 ( struct V_1 * V_2 )
{
int V_39 , V_226 ;
int V_36 = 0 ;
T_2 V_33 , V_227 ;
V_39 = F_137 ( V_2 , V_225 ) ;
if ( ! V_39 )
goto V_228;
F_32 ( V_2 , V_39 + V_229 , & V_33 ) ;
V_226 = ( ( V_33 >> 10 ) & 1 ) ?
V_230 : V_231 ;
F_32 ( V_2 , V_39 + V_226 , & V_227 ) ;
if ( V_227 & ( 1 << 6 ) )
V_36 = 1 ;
V_228:
return V_36 ;
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_1 * V_211 ;
int V_39 ;
int V_29 , V_224 ;
int V_223 = 0 ;
V_224 = V_2 -> V_89 >> 3 ;
for ( V_29 = V_224 ; V_29 >= 0 ; V_29 -- ) {
V_211 = F_113 ( V_2 -> V_51 , F_114 ( V_29 , 0 ) ) ;
if ( ! V_211 )
continue;
V_39 = F_137 ( V_211 , V_225 ) ;
if ( V_39 != 0 ) {
V_223 = 1 ;
break;
}
F_17 ( V_211 ) ;
}
if ( ! V_223 )
return;
if ( V_211 == V_2 && F_149 ( V_211 ) &&
F_148 ( V_211 ) )
goto V_228;
if ( F_136 ( V_211 ) )
goto V_228;
F_141 ( V_2 ) ;
V_228:
F_17 ( V_211 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
int V_39 , V_213 = V_214 ;
V_39 = F_137 ( V_2 , V_215 ) ;
while ( V_39 && V_213 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_39 + V_216 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_92 ) ;
F_7 ( V_2 , V_39 + V_216 ,
V_33 & ~ V_217 ) ;
}
V_39 = F_138 ( V_2 , V_39 ,
V_215 ) ;
}
}
static void F_152 ( struct V_1 * V_2 , int V_232 )
{
struct V_1 * V_211 ;
int V_39 ;
int V_223 ;
if ( ! F_153 () )
return;
V_223 = F_147 ( V_2 ) ;
if ( V_223 == 0 )
return;
V_211 = F_154 ( 0 , F_114 ( 0 , 0 ) ) ;
if ( V_211 == NULL ) {
F_51 ( & V_2 -> V_2 , L_93 ) ;
return;
}
V_39 = F_137 ( V_211 , V_225 ) ;
if ( V_39 != 0 ) {
if ( V_223 == 1 ) {
if ( V_232 )
F_141 ( V_2 ) ;
else
F_150 ( V_2 ) ;
}
goto V_228;
}
if ( V_223 == 1 )
goto V_228;
F_151 ( V_2 ) ;
V_228:
F_17 ( V_211 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
return F_152 ( V_2 , 1 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
return F_152 ( V_2 , 0 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
V_2 -> V_109 |= V_233 ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( V_234 , V_235 ,
NULL ) ;
if ( ! V_18 )
return;
if ( ( V_18 -> V_22 < 0x3B ) && ( V_18 -> V_22 >= 0x30 ) )
V_2 -> V_109 |= V_233 ;
F_17 ( V_18 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 < 0x18 ) {
F_6 ( & V_2 -> V_2 , L_94 ) ;
V_2 -> V_109 |= V_233 ;
}
}
static void F_160 ( struct V_1 * V_2 )
{
V_2 -> V_236 = 1 ;
}
static void F_161 ( struct V_1 * V_2 )
{
T_3 V_237 ;
T_3 V_238 ;
T_3 V_239 ;
if ( F_94 ( V_2 -> V_89 ) )
return;
F_5 ( V_2 , 0xB7 , & V_239 ) ;
if ( V_239 & 0x02 )
return;
F_5 ( V_2 , 0x8E , & V_237 ) ;
F_7 ( V_2 , 0x8E , 0xAA ) ;
F_5 ( V_2 , 0x8D , & V_238 ) ;
F_7 ( V_2 , 0x8D , 0xB7 ) ;
F_7 ( V_2 , 0xB7 , V_239 | 0x02 ) ;
F_7 ( V_2 , 0x8E , V_237 ) ;
F_7 ( V_2 , 0x8D , V_238 ) ;
F_162 ( & V_2 -> V_2 , L_95 ) ;
F_162 ( & V_2 -> V_2 , L_96 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
T_3 V_237 ;
T_3 V_239 ;
if ( F_94 ( V_2 -> V_89 ) )
return;
if ( V_2 -> V_87 == V_240 ||
V_2 -> V_87 == V_241 ) {
F_7 ( V_2 , 0xf9 , 0xfc ) ;
F_7 ( V_2 , 0x150 , 0x10 ) ;
F_7 ( V_2 , 0xf9 , 0x00 ) ;
F_7 ( V_2 , 0xfc , 0x01 ) ;
F_7 ( V_2 , 0xe1 , 0x32 ) ;
F_7 ( V_2 , 0xfc , 0x00 ) ;
F_162 ( & V_2 -> V_2 , L_97 ) ;
}
F_5 ( V_2 , 0xCB , & V_239 ) ;
if ( V_239 & 0x02 )
return;
F_5 ( V_2 , 0xCA , & V_237 ) ;
F_7 ( V_2 , 0xCA , 0x57 ) ;
F_7 ( V_2 , 0xCB , V_239 | 0x02 ) ;
F_7 ( V_2 , 0xCA , V_237 ) ;
F_162 ( & V_2 -> V_2 , L_98 ) ;
F_162 ( & V_2 -> V_2 , L_96 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
T_1 V_242 ;
F_10 ( V_2 , V_243 , & V_242 ) ;
F_66 ( V_2 , V_243 , V_242 | V_244 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
T_1 V_55 = V_2 -> V_55 ;
V_2 -> V_55 = V_245 << 8 ;
F_6 ( & V_2 -> V_2 , L_99 ,
V_55 , V_2 -> V_55 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
V_2 -> V_246 = 1 ;
}
static void F_167 ( struct V_1 * V_2 )
{
int V_247 ;
T_2 V_248 ;
if ( V_249 == V_250 ||
V_249 == V_251 )
return;
V_247 = F_32 ( V_2 , 0x48 , & V_248 ) ;
if ( V_247 ) {
F_168 ( & V_2 -> V_2 , L_100 ) ;
return;
}
if ( ! ( V_248 & ( 1 << 10 ) ) )
return;
V_248 &= ~ ( 1 << 10 ) ;
V_247 = F_53 ( V_2 , 0x48 , V_248 ) ;
if ( V_247 ) {
F_168 ( & V_2 -> V_2 , L_101 ) ;
return;
}
F_169 ( L_102 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
int V_252 ;
T_3 V_76 ;
V_252 = F_5 ( V_2 , 0x00D0 , & V_76 ) ;
if ( V_252 )
return;
V_2 -> V_31 [ 2 ] . V_36 = V_2 -> V_31 [ 2 ] . V_37 + ( ( V_253 ) 1 << V_76 ) - 1 ;
V_252 = F_5 ( V_2 , 0x00D1 , & V_76 ) ;
if ( V_252 )
return;
V_2 -> V_31 [ 4 ] . V_36 = V_2 -> V_31 [ 4 ] . V_37 + ( ( V_253 ) 1 << V_76 ) - 1 ;
}
static T_6 F_171 ( struct V_1 * V_2 ,
void (* F_172)( struct V_1 * V_2 ) )
{
T_6 V_254 = F_173 ( 0 , 0 ) ;
F_174 ( & V_2 -> V_2 , L_103 , F_172 ) ;
if ( V_255 ) {
F_175 ( L_104 ,
F_172 , F_176 ( V_256 ) , F_177 ( & V_2 -> V_2 ) ) ;
V_254 = F_178 () ;
}
return V_254 ;
}
static void F_179 ( struct V_1 * V_2 , T_6 V_254 ,
void (* F_172)( struct V_1 * V_2 ) )
{
T_6 V_257 , V_258 ;
unsigned long long V_259 ;
if ( V_255 ) {
V_258 = F_178 () ;
V_257 = F_180 ( V_258 , V_254 ) ;
V_259 = ( unsigned long long ) F_181 ( V_257 ) >> 10 ;
F_175 ( L_105 ,
F_172 , V_259 , F_177 ( & V_2 -> V_2 ) ) ;
}
}
static void F_182 ( struct V_1 * V_2 )
{
void T_4 * V_260 = F_183 ( V_2 , 0 , 0 ) ;
if ( V_260 == NULL ) {
F_51 ( & V_2 -> V_2 , L_106 ) ;
return;
}
if ( F_85 ( V_260 + V_261 ) != 0 ) {
F_51 ( & V_2 -> V_2 , L_107 ) ;
F_86 ( 0 , V_260 + V_261 ) ;
}
F_184 ( V_2 , V_260 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
V_2 -> V_262 = 0 ;
}
static void F_186 ( struct V_1 * V_2 )
{
V_2 -> V_263 = 1 ;
}
static void F_187 ( struct V_1 * V_2 )
{
V_2 -> V_109 |= V_264 ;
}
static void F_188 ( struct V_1 * V_2 )
{
if ( ! F_189 ( V_2 -> V_51 ) )
V_2 -> V_109 |= V_265 ;
}
static void F_190 ( struct V_1 * V_2 )
{
T_7 V_266 , V_267 , V_268 , V_269 ;
if ( ! F_191 ( V_270 , L_108 ) )
return;
if ( F_192 ( V_2 ) != V_271 )
return;
V_266 = F_193 ( & V_2 -> V_2 ) ;
if ( ! V_266 )
return;
if ( F_194 ( F_195 ( V_266 , L_109 , & V_267 ) )
|| F_194 ( F_195 ( V_266 , L_110 , & V_268 ) )
|| F_194 ( F_195 ( V_266 , L_111 , & V_269 ) ) )
return;
F_6 ( & V_2 -> V_2 , L_112 ) ;
F_196 ( V_267 , NULL , 1 ) ;
F_196 ( V_268 , NULL , 0 ) ;
F_197 ( 300 ) ;
F_196 ( V_269 , NULL , 0 ) ;
F_196 ( V_267 , NULL , 0 ) ;
F_196 ( V_269 , NULL , 0 ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_1 * V_272 = NULL ;
struct V_1 * V_273 = NULL ;
if ( ! F_191 ( V_270 , L_108 ) )
return;
if ( F_192 ( V_2 ) != V_274 )
return;
V_272 = F_113 ( V_2 -> V_51 , 0x0 ) ;
if ( V_272 == V_2 )
goto V_228;
if ( ! V_272 || ! V_272 -> V_83 )
goto V_228;
V_273 = F_113 ( V_272 -> V_83 , 0x0 ) ;
if ( ! V_273 )
goto V_228;
if ( V_273 -> V_161 != V_7
|| ( V_273 -> V_87 != 0x1547 && V_273 -> V_87 != 0x156c )
|| V_273 -> V_112 != 0x2222
|| V_273 -> V_115 != 0x1111 )
goto V_228;
F_6 ( & V_2 -> V_2 , L_113 ) ;
F_199 ( & V_2 -> V_2 , & V_273 -> V_2 ) ;
V_228:
F_17 ( V_273 ) ;
F_17 ( V_272 ) ;
}
static void F_200 ( struct V_1 * V_2 , struct V_275 * V_276 ,
struct V_275 * V_36 )
{
T_6 V_254 ;
for (; V_276 < V_36 ; V_276 ++ )
if ( ( V_276 -> V_55 == ( T_1 ) ( V_2 -> V_55 >> V_276 -> V_277 ) ||
V_276 -> V_55 == ( T_1 ) V_278 ) &&
( V_276 -> V_161 == V_2 -> V_161 ||
V_276 -> V_161 == ( T_2 ) V_278 ) &&
( V_276 -> V_87 == V_2 -> V_87 ||
V_276 -> V_87 == ( T_2 ) V_278 ) ) {
V_254 = F_171 ( V_2 , V_276 -> V_279 ) ;
V_276 -> V_279 ( V_2 ) ;
F_179 ( V_2 , V_254 , V_276 -> V_279 ) ;
}
}
void F_201 ( enum V_280 V_281 , struct V_1 * V_2 )
{
struct V_275 * V_37 , * V_36 ;
switch ( V_281 ) {
case V_282 :
V_37 = V_283 ;
V_36 = V_284 ;
break;
case V_285 :
V_37 = V_286 ;
V_36 = V_287 ;
break;
case V_288 :
if ( ! V_289 )
return;
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
case V_304 :
V_37 = V_305 ;
V_36 = V_306 ;
break;
default:
return;
}
F_200 ( V_2 , V_37 , V_36 ) ;
}
static int T_8 F_202 ( void )
{
struct V_1 * V_2 = NULL ;
T_3 V_307 = 0 ;
T_3 V_80 ;
if ( V_308 )
F_146 ( V_309 L_114 ,
V_308 << 2 ) ;
V_289 = true ;
F_203 (dev) {
F_201 ( V_288 , V_2 ) ;
if ( ! V_308 ) {
F_5 ( V_2 , V_310 , & V_80 ) ;
if ( ! V_307 )
V_307 = V_80 ;
if ( ! V_80 || V_307 == V_80 )
continue;
F_146 ( V_309 L_115 ,
V_307 << 2 , V_80 << 2 ,
V_311 << 2 ) ;
V_308 = V_311 ;
}
}
if ( ! V_308 ) {
F_146 ( V_309 L_116 ,
V_307 << 2 , V_311 << 2 ) ;
V_308 = V_307 ? V_307 : V_311 ;
}
return 0 ;
}
static int F_204 ( struct V_1 * V_2 , int V_312 )
{
if ( V_312 )
return 0 ;
if ( ! F_205 ( V_2 ) )
F_168 ( & V_2 -> V_2 , L_117 ) ;
F_206 ( V_2 , V_313 , V_314 ) ;
F_197 ( 100 ) ;
return 0 ;
}
static int F_207 ( struct V_1 * V_2 , int V_312 )
{
void T_4 * V_315 ;
unsigned long V_316 ;
T_1 V_76 ;
if ( V_312 )
return 0 ;
V_315 = F_183 ( V_2 , 0 , 0 ) ;
if ( ! V_315 )
return - V_317 ;
F_208 ( 0x00000002 , V_315 + V_318 ) ;
F_208 ( 0x00000005 , V_315 + V_319 ) ;
V_76 = F_209 ( V_315 + V_320 ) & 0xfffffffe ;
F_208 ( V_76 , V_315 + V_320 ) ;
V_316 = V_321 + F_210 ( V_322 ) ;
do {
V_76 = F_209 ( V_315 + V_323 ) ;
if ( ( V_76 & 0xb0000000 ) == 0 )
goto V_324;
F_197 ( 10 ) ;
} while ( F_211 ( V_321 , V_316 ) );
F_51 ( & V_2 -> V_2 , L_118 ) ;
V_324:
F_208 ( 0x00000002 , V_315 + V_325 ) ;
F_184 ( V_2 , V_315 ) ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 , int V_312 )
{
T_2 V_326 ;
T_2 V_327 ;
if ( ( V_2 -> V_87 & 0xf000 ) != 0x4000 )
return - V_328 ;
if ( V_312 )
return 0 ;
F_32 ( V_2 , V_78 , & V_326 ) ;
F_53 ( V_2 , V_78 ,
V_326 | V_329 ) ;
F_213 ( V_2 ) ;
F_32 ( V_2 , V_2 -> V_330 + V_331 , & V_327 ) ;
if ( ( V_327 & V_332 ) == 0 )
F_53 ( V_2 , V_2 -> V_330 + V_331 ,
V_327 |
V_332 |
V_333 ) ;
if ( ! F_205 ( V_2 ) )
F_168 ( & V_2 -> V_2 , L_117 ) ;
F_206 ( V_2 , V_313 , V_314 ) ;
F_197 ( 100 ) ;
F_214 ( V_2 ) ;
F_53 ( V_2 , V_78 , V_326 ) ;
return 0 ;
}
int F_215 ( struct V_1 * V_2 , int V_312 )
{
const struct V_334 * V_29 ;
for ( V_29 = V_334 ; V_29 -> V_335 ; V_29 ++ ) {
if ( ( V_29 -> V_161 == V_2 -> V_161 ||
V_29 -> V_161 == ( T_2 ) V_278 ) &&
( V_29 -> V_87 == V_2 -> V_87 ||
V_29 -> V_87 == ( T_2 ) V_278 ) )
return V_29 -> V_335 ( V_2 , V_312 ) ;
}
return - V_328 ;
}
static void F_216 ( struct V_1 * V_2 )
{
if ( F_94 ( V_2 -> V_89 ) != 0 ) {
V_2 -> V_336 = F_114 ( F_61 ( V_2 -> V_89 ) , 0 ) ;
V_2 -> V_109 |= V_337 ;
}
}
static void F_217 ( struct V_1 * V_2 )
{
if ( F_94 ( V_2 -> V_89 ) != 1 ) {
V_2 -> V_336 = F_114 ( F_61 ( V_2 -> V_89 ) , 1 ) ;
V_2 -> V_109 |= V_337 ;
}
}
static void F_218 ( struct V_1 * V_2 )
{
const struct V_338 * V_339 ;
V_339 = F_219 ( V_340 , V_2 ) ;
if ( V_339 ) {
V_2 -> V_336 = V_339 -> V_341 ;
V_2 -> V_109 |= V_337 ;
F_6 ( & V_2 -> V_2 , L_119 ,
F_61 ( V_2 -> V_336 ) ,
F_94 ( V_2 -> V_336 ) ) ;
}
}
static void F_220 ( struct V_1 * V_54 )
{
if ( ! F_189 ( V_54 -> V_51 ) &&
V_54 -> V_150 == V_342 &&
! F_221 ( V_54 ) && F_221 ( V_54 -> V_51 -> V_343 ) &&
F_192 ( V_54 -> V_51 -> V_343 ) != V_344 )
V_54 -> V_109 |= V_345 ;
}
static void F_222 ( struct V_1 * V_54 )
{
T_1 V_55 = V_54 -> V_55 ;
V_54 -> V_55 = ( V_346 << 8 ) | 0x01 ;
F_6 ( & V_54 -> V_2 , L_120 ,
V_55 , V_54 -> V_55 ) ;
}
static void F_223 ( struct V_1 * V_54 )
{
struct V_1 * V_347 = F_224 ( V_54 ) ;
if ( ! V_347 ) {
F_51 ( & V_54 -> V_2 , L_121 ) ;
return;
}
F_6 ( & V_347 -> V_2 , L_122 ,
F_177 ( & V_54 -> V_2 ) ) ;
F_225 ( V_347 , V_313 ,
V_348 |
V_349 , 0 ) ;
}
static void F_226 ( struct V_1 * V_54 )
{
if ( ( V_54 -> V_87 & 0xff00 ) == 0x5400 )
F_223 ( V_54 ) ;
}
static int F_227 ( struct V_1 * V_2 , T_2 V_350 )
{
#ifdef F_228
struct V_351 * V_352 = NULL ;
T_9 V_353 ;
if ( ! V_2 -> V_151 || ! F_189 ( V_2 -> V_51 ) )
return - V_354 ;
V_353 = F_229 ( L_123 , 0 , & V_352 ) ;
if ( F_194 ( V_353 ) )
return - V_354 ;
V_350 &= ( V_355 | V_356 | V_357 | V_358 ) ;
return V_350 & ~ ( V_355 | V_356 ) ? 0 : 1 ;
#else
return - V_354 ;
#endif
}
static bool F_230 ( struct V_1 * V_2 )
{
int V_29 ;
if ( ! F_221 ( V_2 ) || F_192 ( V_2 ) != V_359 )
return false ;
for ( V_29 = 0 ; V_29 < F_231 ( V_360 ) ; V_29 ++ )
if ( V_360 [ V_29 ] == V_2 -> V_87 )
return true ;
return false ;
}
static int F_232 ( struct V_1 * V_2 , T_2 V_350 )
{
T_2 V_33 = V_2 -> V_109 & V_361 ?
V_362 : 0 ;
if ( ! F_230 ( V_2 ) )
return - V_328 ;
return V_350 & ~ V_33 ? 0 : 1 ;
}
static int F_233 ( struct V_1 * V_2 , T_2 V_350 )
{
V_350 &= ~ ( V_363 | V_364 | V_355 |
V_356 | V_365 | V_358 ) ;
return V_350 ? 0 : 1 ;
}
int F_234 ( struct V_1 * V_2 , T_2 V_350 )
{
const struct V_366 * V_29 ;
int V_367 ;
for ( V_29 = V_366 ; V_29 -> V_368 ; V_29 ++ ) {
if ( ( V_29 -> V_161 == V_2 -> V_161 ||
V_29 -> V_161 == ( T_2 ) V_278 ) &&
( V_29 -> V_87 == V_2 -> V_87 ||
V_29 -> V_87 == ( T_2 ) V_278 ) ) {
V_367 = V_29 -> V_368 ( V_2 , V_350 ) ;
if ( V_367 >= 0 )
return V_367 ;
}
}
return - V_328 ;
}
static int F_235 ( struct V_1 * V_2 )
{
T_1 V_132 , V_369 , V_370 ;
void T_4 * V_371 ;
F_236 ( V_2 -> V_51 , F_114 ( 31 , 0 ) ,
V_372 , & V_132 ) ;
if ( ! ( V_132 & V_373 ) )
return - V_374 ;
V_371 = F_83 ( V_132 & V_375 ,
F_237 ( V_376 ) ) ;
if ( ! V_371 )
return - V_317 ;
V_369 = F_85 ( V_371 + V_377 ) ;
V_369 &= V_378 | V_379 ;
if ( V_369 != ( V_378 | V_379 ) ) {
V_370 = F_85 ( V_371 + V_376 ) ;
if ( V_370 & V_380 ) {
F_6 ( & V_2 -> V_2 , L_124 ) ;
V_370 &= ~ V_380 ;
F_86 ( V_370 , V_371 + V_376 ) ;
}
}
F_88 ( V_371 ) ;
return 0 ;
}
static void F_238 ( struct V_1 * V_2 )
{
T_1 V_381 ;
F_10 ( V_2 , V_382 , & V_381 ) ;
if ( ! ( V_381 & V_383 ) ) {
F_6 ( & V_2 -> V_2 , L_125 ) ;
V_381 |= V_383 ;
F_53 ( V_2 , V_382 , V_381 ) ;
}
}
static int F_239 ( struct V_1 * V_2 )
{
if ( ! F_230 ( V_2 ) )
return - V_328 ;
if ( F_235 ( V_2 ) ) {
F_51 ( & V_2 -> V_2 , L_126 ) ;
return 0 ;
}
F_238 ( V_2 ) ;
V_2 -> V_109 |= V_361 ;
F_6 ( & V_2 -> V_2 , L_127 ) ;
return 0 ;
}
void F_240 ( struct V_1 * V_2 )
{
const struct V_384 * V_29 ;
int V_367 ;
for ( V_29 = V_384 ; V_29 -> V_385 ; V_29 ++ ) {
if ( ( V_29 -> V_161 == V_2 -> V_161 ||
V_29 -> V_161 == ( T_2 ) V_278 ) &&
( V_29 -> V_87 == V_2 -> V_87 ||
V_29 -> V_87 == ( T_2 ) V_278 ) ) {
V_367 = V_29 -> V_385 ( V_2 ) ;
if ( V_367 >= 0 )
return;
}
}
}
static void F_241 ( struct V_1 * V_54 )
{
int V_39 , V_29 = 0 ;
T_3 V_386 ;
T_2 V_387 , * V_388 ;
struct V_389 * V_390 ;
if ( V_54 -> V_391 || F_145 ( V_54 , V_392 ) )
return;
V_39 = F_145 ( V_54 , V_393 ) ;
if ( ! V_39 )
return;
F_5 ( V_54 , V_39 + 1 , & V_386 ) ;
if ( V_386 )
return;
V_39 = 0x50 ;
F_32 ( V_54 , V_39 , & V_387 ) ;
if ( V_387 == ( 0x0000 | V_392 ) ) {
T_1 V_353 ;
#ifndef F_242
#define F_242 7
#endif
int V_40 = F_242 * sizeof( T_2 ) ;
V_54 -> V_391 = V_39 ;
F_32 ( V_54 , V_39 + V_394 , & V_387 ) ;
V_54 -> V_395 = V_387 ;
F_32 ( V_54 , V_39 + V_396 , & V_387 ) ;
V_54 -> V_246 = V_387 & V_397 ;
V_54 -> V_28 = V_398 ;
if ( F_10 ( V_54 , V_399 , & V_353 ) !=
V_400 || ( V_353 == 0xffffffff ) )
V_54 -> V_28 = V_399 ;
if ( F_243 ( V_54 , V_392 ) )
return;
V_390 = F_244 ( sizeof( * V_390 ) + V_40 , V_401 ) ;
if ( ! V_390 )
return;
V_390 -> V_388 . V_402 = V_392 ;
V_390 -> V_388 . V_403 = 0 ;
V_390 -> V_388 . V_40 = V_40 ;
V_388 = ( T_2 * ) & V_390 -> V_388 . V_404 [ 0 ] ;
F_245 ( V_54 , V_313 , & V_388 [ V_29 ++ ] ) ;
F_245 ( V_54 , V_405 , & V_388 [ V_29 ++ ] ) ;
F_245 ( V_54 , V_406 , & V_388 [ V_29 ++ ] ) ;
F_245 ( V_54 , V_407 , & V_388 [ V_29 ++ ] ) ;
F_245 ( V_54 , V_408 , & V_388 [ V_29 ++ ] ) ;
F_245 ( V_54 , V_409 , & V_388 [ V_29 ++ ] ) ;
F_245 ( V_54 , V_410 , & V_388 [ V_29 ++ ] ) ;
F_246 ( & V_390 -> V_411 , & V_54 -> V_412 ) ;
}
}
