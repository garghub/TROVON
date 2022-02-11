static void T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
T_2 V_6 , V_7 ;
T_3 V_8 ;
if ( ! F_2 ( V_2 ) )
return;
if ( V_2 -> V_9 == V_10 &&
( V_2 -> V_11 >> 8 ) == V_12 ) {
F_3 ( & V_2 -> V_2 ,
L_1 ) ;
return;
}
F_4 ( & V_2 -> V_2 ,
L_2 ) ;
F_5 ( V_2 , V_13 , & V_8 ) ;
V_8 &= ~ V_14 ;
F_6 ( V_2 , V_13 , V_8 ) ;
V_6 = F_7 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
V_5 = & V_2 -> V_4 [ V_3 ] ;
if ( ! ( V_5 -> V_16 & V_17 ) )
continue;
V_7 = F_8 ( V_5 ) ;
if ( V_7 < V_6 ) {
V_7 = V_6 ;
F_4 ( & V_2 -> V_2 ,
L_3 ,
V_3 , ( unsigned long long ) V_7 ) ;
}
V_5 -> V_18 = V_7 - 1 ;
V_5 -> V_19 = 0 ;
}
if ( V_2 -> V_9 == V_20 &&
( V_2 -> V_11 >> 8 ) == V_21 ) {
for ( V_3 = V_15 ; V_3 < V_22 ; V_3 ++ ) {
V_5 = & V_2 -> V_4 [ V_3 ] ;
if ( ! ( V_5 -> V_16 & V_17 ) )
continue;
V_5 -> V_18 = F_8 ( V_5 ) - 1 ;
V_5 -> V_19 = 0 ;
}
F_9 ( V_2 ) ;
}
}
static void T_1 F_10 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_11 >> 8 ) == V_12 )
V_2 -> V_23 = 1 ;
}
static void T_1 F_11 ( struct V_1 * V_2 )
{
V_2 -> V_24 = 1 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_1 * V_25 = NULL ;
unsigned char V_26 ;
while ( ( V_25 = F_13 ( V_27 , V_28 , V_25 ) ) ) {
F_14 ( V_25 , 0x82 , & V_26 ) ;
if ( ! ( V_26 & 1 << 1 ) ) {
F_4 ( & V_25 -> V_2 , L_4 ) ;
V_26 |= 1 << 1 ;
F_15 ( V_25 , 0x82 , V_26 ) ;
}
}
}
static void T_1 F_16 ( struct V_1 * V_2 )
{
if ( ! V_29 ) {
V_29 = 1 ;
F_4 ( & V_2 -> V_2 , L_5 ) ;
}
}
static void T_1 F_17 ( struct V_1 * V_2 )
{
T_4 V_30 ;
T_3 V_31 ;
F_18 ( V_2 , 0x40 , & V_30 ) ;
V_30 = V_30 & 0xff80 ;
V_31 = F_19 ( V_30 ) ;
if ( V_31 & 0x10 ) {
F_4 ( & V_2 -> V_2 , V_32 L_6 ) ;
F_20 ( 0x10 , V_30 ) ;
}
}
static void T_1 F_21 ( struct V_1 * V_2 )
{
if ( ( V_33 & V_34 ) == 0 ) {
F_4 ( & V_2 -> V_2 , L_7 ) ;
V_33 |= V_34 ;
}
}
static void T_1 F_22 ( struct V_1 * V_2 )
{
T_5 V_35 ;
F_14 ( V_2 , 0x08 , & V_35 ) ;
if ( V_35 == 0x13 ) {
F_4 ( & V_2 -> V_2 , L_8 ) ;
V_33 |= V_36 ;
}
}
static void T_1 F_23 ( struct V_1 * V_2 )
{
if ( ( V_33 & V_37 ) == 0 ) {
F_4 ( & V_2 -> V_2 , L_9 ) ;
V_33 |= V_37 ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_1 * V_38 ;
T_5 V_39 ;
V_38 = F_13 ( V_40 , V_41 , NULL ) ;
if ( V_38 != NULL ) {
if ( V_38 -> V_42 < 0x40 || V_38 -> V_42 > 0x42 )
goto exit;
} else {
V_38 = F_13 ( V_40 , V_43 , NULL ) ;
if ( V_38 == NULL )
goto exit;
if ( V_38 -> V_42 < 0x10 || V_38 -> V_42 > 0x12 )
goto exit;
}
F_14 ( V_2 , 0x76 , & V_39 ) ;
V_39 &= ~ ( 1 << 5 ) ;
V_39 |= ( 1 << 4 ) ;
F_15 ( V_2 , 0x76 , V_39 ) ;
F_4 ( & V_2 -> V_2 , L_10 ) ;
exit:
F_25 ( V_38 ) ;
}
static void T_1 F_26 ( struct V_1 * V_2 )
{
if ( ( V_33 & V_44 ) == 0 ) {
F_4 ( & V_2 -> V_2 , L_9 ) ;
V_33 |= V_44 ;
}
}
static void T_1 F_27 ( struct V_1 * V_2 )
{
if ( ( V_33 & V_45 ) == 0 ) {
F_4 ( & V_2 -> V_2 , L_9 ) ;
V_33 |= V_45 ;
}
}
static void T_6 F_28 ( struct V_1 * V_2 )
{
if ( ( V_33 & V_46 ) == 0 ) {
F_4 ( & V_2 -> V_2 , L_9 ) ;
V_33 |= V_46 | V_37 ;
}
}
static void T_1 F_29 ( struct V_1 * V_2 )
{
if ( ( V_33 & V_47 ) == 0 ) {
F_4 ( & V_2 -> V_2 , L_9 ) ;
V_33 |= V_47 ;
}
}
static void T_1 F_30 ( struct V_1 * V_2 )
{
V_2 -> V_48 = 0xA0 ;
}
static void T_1 F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_4 [ 0 ] ;
if ( ( V_5 -> V_19 & 0x3ffffff ) || V_5 -> V_18 != V_5 -> V_19 + 0x3ffffff ) {
V_5 -> V_19 = 0 ;
V_5 -> V_18 = 0x3ffffff ;
}
}
static void T_1 F_32 ( struct V_1 * V_2 )
{
if ( F_33 ( V_2 , 0 ) != 8 ) {
struct V_4 * V_49 = & V_2 -> V_4 [ 0 ] ;
V_49 -> V_18 = V_49 -> V_19 + 8 - 1 ;
F_4 ( & V_2 -> V_2 , L_11
L_12 ) ;
}
}
static void T_1 F_34 ( struct V_1 * V_2 , unsigned V_50 ,
unsigned V_7 , int V_51 , const char * V_52 )
{
V_50 &= ~ ( V_7 - 1 ) ;
if ( V_50 ) {
struct V_53 V_54 ;
struct V_4 * V_49 = V_2 -> V_4 + V_51 ;
V_49 -> V_52 = F_35 ( V_2 ) ;
V_49 -> V_19 = V_50 ;
V_49 -> V_18 = V_50 + V_7 - 1 ;
V_49 -> V_16 = V_55 ;
V_54 . V_19 = V_49 -> V_19 ;
V_54 . V_18 = V_49 -> V_18 ;
F_36 ( V_2 , V_49 , & V_54 ) ;
if ( F_37 ( V_2 , V_51 ) == 0 )
F_4 ( & V_2 -> V_2 , L_13 ,
V_49 , V_52 ) ;
}
}
static void T_1 F_38 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_2 , L_14 ) ;
F_39 ( 0x3b0 , 0x0C , L_15 ) ;
F_39 ( 0x3d3 , 0x01 , L_15 ) ;
}
static void T_1 F_40 ( struct V_1 * V_2 )
{
T_3 V_50 ;
F_5 ( V_2 , 0xE0 , & V_50 ) ;
F_34 ( V_2 , V_50 , 64 , V_15 , L_16 ) ;
F_5 ( V_2 , 0xE2 , & V_50 ) ;
F_34 ( V_2 , V_50 , 32 , V_15 + 1 , L_17 ) ;
}
static void F_41 ( struct V_1 * V_2 , const char * V_52 , unsigned int V_56 , unsigned int V_57 )
{
T_4 V_58 ;
T_4 V_59 , V_7 , V_60 ;
F_18 ( V_2 , V_56 , & V_58 ) ;
if ( ( V_58 & V_57 ) != V_57 )
return;
V_59 = ( V_58 >> 16 ) & 15 ;
V_60 = V_58 & 0xffff ;
V_7 = 16 ;
for (; ; ) {
unsigned V_61 = V_7 >> 1 ;
if ( ( V_61 & V_59 ) == V_61 )
break;
V_7 = V_61 ;
}
V_60 &= - V_7 ;
F_4 ( & V_2 -> V_2 , L_18 , V_52 , V_60 , V_60 + V_7 - 1 ) ;
}
static void F_42 ( struct V_1 * V_2 , const char * V_52 , unsigned int V_56 , unsigned int V_57 )
{
T_4 V_58 ;
T_4 V_59 , V_7 , V_60 ;
F_18 ( V_2 , V_56 , & V_58 ) ;
if ( ( V_58 & V_57 ) != V_57 )
return;
V_60 = V_58 & 0xffff0000 ;
V_59 = ( V_58 & 0x3f ) << 16 ;
V_7 = 128 << 16 ;
for (; ; ) {
unsigned V_61 = V_7 >> 1 ;
if ( ( V_61 & V_59 ) == V_61 )
break;
V_7 = V_61 ;
}
V_60 &= - V_7 ;
F_4 ( & V_2 -> V_2 , L_19 , V_52 , V_60 , V_60 + V_7 - 1 ) ;
}
static void T_1 F_43 ( struct V_1 * V_2 )
{
T_4 V_50 , V_62 ;
F_18 ( V_2 , 0x40 , & V_50 ) ;
F_34 ( V_2 , V_50 , 64 , V_15 , L_20 ) ;
F_18 ( V_2 , 0x90 , & V_50 ) ;
F_34 ( V_2 , V_50 , 16 , V_15 + 1 , L_21 ) ;
F_18 ( V_2 , 0x5c , & V_62 ) ;
F_41 ( V_2 , L_22 , 0x60 , 3 << 21 ) ;
F_41 ( V_2 , L_23 , 0x64 , 3 << 21 ) ;
if ( V_62 & ( 1 << 29 ) ) {
F_41 ( V_2 , L_24 , 0x68 , 1 << 20 ) ;
F_42 ( V_2 , L_25 , 0x6c , 1 << 7 ) ;
}
if ( V_62 & ( 1 << 30 ) ) {
F_41 ( V_2 , L_26 , 0x70 , 1 << 20 ) ;
F_42 ( V_2 , L_27 , 0x74 , 1 << 7 ) ;
}
F_41 ( V_2 , L_28 , 0x78 , 1 << 20 ) ;
F_41 ( V_2 , L_29 , 0x7c , 1 << 20 ) ;
}
static void T_1 F_44 ( struct V_1 * V_2 )
{
T_4 V_50 ;
T_5 V_57 ;
F_14 ( V_2 , V_63 , & V_57 ) ;
if ( V_57 & V_64 ) {
F_18 ( V_2 , V_65 , & V_50 ) ;
V_50 &= V_66 ;
if ( V_50 >= V_67 )
F_34 ( V_2 , V_50 , 128 , V_15 ,
L_30 ) ;
}
F_14 ( V_2 , V_68 , & V_57 ) ;
if ( V_57 & V_69 ) {
F_18 ( V_2 , V_70 , & V_50 ) ;
V_50 &= V_66 ;
if ( V_50 >= V_67 )
F_34 ( V_2 , V_50 , 64 ,
V_15 + 1 , L_31 ) ;
}
}
static void T_1 F_45 ( struct V_1 * V_2 )
{
T_4 V_50 ;
T_5 V_57 ;
F_14 ( V_2 , V_63 , & V_57 ) ;
if ( V_57 & V_71 ) {
F_18 ( V_2 , V_65 , & V_50 ) ;
V_50 &= V_66 ;
if ( V_50 >= V_67 )
F_34 ( V_2 , V_50 , 128 , V_15 ,
L_32 ) ;
}
F_14 ( V_2 , V_72 , & V_57 ) ;
if ( V_57 & V_73 ) {
F_18 ( V_2 , V_74 , & V_50 ) ;
V_50 &= V_66 ;
if ( V_50 >= V_67 )
F_34 ( V_2 , V_50 , 64 ,
V_15 + 1 , L_33 ) ;
}
}
static void T_1 F_46 ( struct V_1 * V_2 , unsigned V_75 , const char * V_52 , int V_76 )
{
T_4 V_77 ;
T_4 V_7 , V_60 ;
F_18 ( V_2 , V_75 , & V_77 ) ;
if ( ! ( V_77 & 1 ) )
return;
V_60 = V_77 & 0xfffc ;
if ( V_76 ) {
V_7 = 16 ;
} else {
V_7 = 128 ;
}
V_60 &= ~ ( V_7 - 1 ) ;
F_4 ( & V_2 -> V_2 , L_18 , V_52 , V_60 , V_60 + V_7 - 1 ) ;
}
static void T_1 F_47 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
F_46 ( V_2 , 0x84 , L_34 , 0 ) ;
F_46 ( V_2 , 0x88 , L_35 , 1 ) ;
}
static void T_1 F_48 ( struct V_1 * V_2 , unsigned V_75 , const char * V_52 )
{
T_4 V_77 ;
T_4 V_59 , V_60 ;
F_18 ( V_2 , V_75 , & V_77 ) ;
if ( ! ( V_77 & 1 ) )
return;
V_60 = V_77 & 0xfffc ;
V_59 = ( V_77 >> 16 ) & 0xfc ;
V_59 |= 3 ;
F_4 ( & V_2 -> V_2 , L_36 , V_52 , V_60 , V_59 ) ;
}
static void T_1 F_49 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
F_48 ( V_2 , 0x84 , L_37 ) ;
F_48 ( V_2 , 0x88 , L_38 ) ;
F_48 ( V_2 , 0x8c , L_39 ) ;
F_48 ( V_2 , 0x90 , L_40 ) ;
}
static void T_1 F_50 ( struct V_1 * V_2 )
{
T_4 V_50 ;
if ( V_2 -> V_42 & 0x10 ) {
F_18 ( V_2 , 0x48 , & V_50 ) ;
V_50 &= V_66 ;
F_34 ( V_2 , V_50 , 256 , V_15 , L_41 ) ;
}
}
static void T_1 F_51 ( struct V_1 * V_2 )
{
T_3 V_78 ;
T_4 V_79 ;
F_50 ( V_2 ) ;
F_5 ( V_2 , 0x70 , & V_78 ) ;
V_78 &= V_66 ;
F_34 ( V_2 , V_78 , 128 , V_15 + 1 , L_42 ) ;
F_18 ( V_2 , 0x90 , & V_79 ) ;
V_79 &= V_66 ;
F_34 ( V_2 , V_79 , 16 , V_15 + 2 , L_43 ) ;
}
static void T_1 F_52 ( struct V_1 * V_2 )
{
T_3 V_80 , V_79 ;
F_5 ( V_2 , 0x88 , & V_80 ) ;
V_80 &= V_66 ;
F_34 ( V_2 , V_80 , 128 , V_15 , L_44 ) ;
F_5 ( V_2 , 0xd0 , & V_79 ) ;
V_79 &= V_66 ;
F_34 ( V_2 , V_79 , 16 , V_15 + 1 , L_45 ) ;
}
static void T_1 F_53 ( struct V_1 * V_2 )
{
struct V_1 * V_81 ;
T_3 V_8 ;
F_3 ( & V_2 -> V_2 , L_46
L_47 ) ;
F_54 (pdev, &dev->subordinate->devices, bus_list) {
F_5 ( V_81 , V_13 , & V_8 ) ;
if ( V_8 & V_82 )
F_6 ( V_81 , V_13 , V_8 & ~ V_82 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
T_5 V_83 ;
if ( V_84 < 1 )
V_83 = 0 ;
else
V_83 = 0x1f ;
F_4 ( & V_2 -> V_2 , L_48 ,
V_83 == 0 ? L_49 : L_50 ) ;
F_15 ( V_2 , 0x58 , V_83 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_5 V_85 ;
#define F_57 8
F_14 ( V_2 , 0x5B , & V_85 ) ;
if ( ! ( V_85 & F_57 ) ) {
F_4 ( & V_2 -> V_2 , L_51 ) ;
F_15 ( V_2 , 0x5B , V_85 | F_57 ) ;
}
}
static void T_1 F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 >= 0x02 ) {
F_3 ( & V_2 -> V_2 , L_52 ) ;
F_3 ( & V_2 -> V_2 , L_53 ) ;
}
}
static void T_6 F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_86 == 0 && V_2 -> V_87 -> V_88 == 0 )
V_89 = 1 ;
}
static void T_6 F_60 ( struct V_1 * V_2 )
{
if ( V_2 -> V_90 && V_2 -> V_42 <= 0x12 ) {
F_4 ( & V_2 -> V_2 , L_54
L_55 , V_2 -> V_42 ) ;
V_2 -> V_90 -> V_91 |= V_92 ;
}
}
static void T_1 F_61 ( struct V_1 * V_25 )
{
T_5 V_93 ;
F_14 ( V_25 , 0x42 , & V_93 ) ;
V_93 &= 0xf ;
if ( V_93 && ( V_93 != 2 ) )
V_25 -> V_93 = V_93 ;
}
static void F_62 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_94 ) {
case V_41 :
V_95 = F_63 ( V_2 -> V_86 ) ;
V_96 = F_63 ( V_2 -> V_86 ) ;
break;
case V_97 :
case V_98 :
V_95 = 15 ;
break;
case V_99 :
V_95 = 16 ;
break;
case V_43 :
case V_100 :
case V_101 :
case V_102 :
V_95 = 17 ;
break;
}
}
static void F_64 ( struct V_1 * V_2 )
{
T_5 V_93 , V_103 ;
if ( V_95 == - 1 )
return;
V_103 = V_2 -> V_93 ;
if ( ! V_103 || V_103 > 15 )
return;
if ( V_2 -> V_87 -> V_88 != 0 || F_63 ( V_2 -> V_86 ) > V_96 ||
F_63 ( V_2 -> V_86 ) < V_95 )
return;
F_14 ( V_2 , V_104 , & V_93 ) ;
if ( V_103 != V_93 ) {
F_4 ( & V_2 -> V_2 , L_56 ,
V_93 , V_103 ) ;
F_65 ( 15 ) ;
F_15 ( V_2 , V_104 , V_103 ) ;
}
}
static void T_1 F_66 ( struct V_1 * V_2 )
{
F_15 ( V_2 , 0xfc , 0 ) ;
F_5 ( V_2 , V_105 , & V_2 -> V_94 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
if ( ( V_106 << 8 ) ^ V_2 -> V_11 )
return;
F_68 ( V_2 , V_107 , 0 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_4 V_108 ;
F_18 ( V_2 , 0x4C , & V_108 ) ;
if ( ( V_108 & 6 ) != 6 ) {
V_108 |= 6 ;
F_3 ( & V_2 -> V_2 , L_57 ) ;
F_68 ( V_2 , 0x4C , V_108 ) ;
F_18 ( V_2 , 0x84 , & V_108 ) ;
V_108 |= ( 1 << 23 ) ;
F_68 ( V_2 , 0x84 , V_108 ) ;
}
}
static void T_1 F_70 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_4 [ 1 ] ;
V_5 -> V_19 = 0 ;
V_5 -> V_18 = 0xffffff ;
}
static void T_1 F_71 ( struct V_1 * V_2 )
{
V_2 -> V_109 = 1 ;
}
static void F_72 ( struct V_1 * V_2 )
{
T_5 V_75 ;
F_14 ( V_2 , 0x41 , & V_75 ) ;
if ( V_75 & 2 ) {
V_75 &= ~ 2 ;
F_4 ( & V_2 -> V_2 , L_58 , V_75 ) ;
F_15 ( V_2 , 0x41 , V_75 ) ;
}
}
static void F_73 ( struct V_1 * V_81 )
{
T_3 V_110 ;
if ( V_81 -> V_42 != 0x04 )
return;
F_5 ( V_81 , 0x40 , & V_110 ) ;
if ( V_110 & ( 1 << 6 ) ) {
V_110 &= ~ ( 1 << 6 ) ;
F_6 ( V_81 , 0x40 , V_110 ) ;
F_4 ( & V_81 -> V_2 , L_59 ) ;
}
}
static void T_1 F_74 ( struct V_1 * V_81 )
{
T_5 V_83 ;
F_14 ( V_81 , V_111 , & V_83 ) ;
if ( V_83 == 0x01 ) {
F_14 ( V_81 , 0x40 , & V_83 ) ;
F_15 ( V_81 , 0x40 , V_83 | 1 ) ;
F_15 ( V_81 , 0x9 , 1 ) ;
F_15 ( V_81 , 0xa , 6 ) ;
F_15 ( V_81 , 0x40 , V_83 ) ;
V_81 -> V_11 = V_112 ;
F_4 ( & V_81 -> V_2 , L_60 ) ;
}
}
static void T_1 F_75 ( struct V_1 * V_81 )
{
T_5 V_113 ;
F_14 ( V_81 , V_114 , & V_113 ) ;
if ( V_113 & 5 ) {
V_113 &= ~ 5 ;
V_81 -> V_11 &= ~ 5 ;
F_15 ( V_81 , V_114 , V_113 ) ;
}
}
static void T_6 F_76 ( struct V_1 * V_81 )
{
T_5 V_113 ;
F_14 ( V_81 , V_114 , & V_113 ) ;
if ( ( ( V_113 & 1 ) && ! ( V_113 & 4 ) ) || ( ( V_113 & 4 ) && ! ( V_113 & 1 ) ) ) {
F_4 ( & V_81 -> V_2 , L_61 ) ;
V_113 &= ~ 5 ;
V_81 -> V_11 &= ~ 5 ;
F_15 ( V_81 , V_114 , V_113 ) ;
}
}
static void T_1 F_77 ( struct V_1 * V_81 )
{
if ( ( V_81 -> V_11 >> 8 ) == V_115 )
V_81 -> V_116 |= V_117 ;
}
static void T_6 F_78 ( struct V_1 * V_2 )
{
V_2 -> V_11 = V_118 << 8 ;
}
static void T_6 F_79 ( struct V_1 * V_2 )
{
if ( F_80 ( V_2 -> V_119 == V_120 ) ) {
if ( V_2 -> V_94 == V_121 )
switch( V_2 -> V_122 ) {
case 0x8025 :
case 0x8070 :
case 0x8088 :
case 0x1626 :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_124 )
switch( V_2 -> V_122 ) {
case 0x80b1 :
case 0x80b2 :
case 0x8093 :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_125 )
switch( V_2 -> V_122 ) {
case 0x8030 :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_126 )
switch ( V_2 -> V_122 ) {
case 0x8070 :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_127 )
switch ( V_2 -> V_122 ) {
case 0x80c9 :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_128 )
switch ( V_2 -> V_122 ) {
case 0x1751 :
case 0x1821 :
case 0x1897 :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_129 )
switch ( V_2 -> V_122 ) {
case 0x184b :
case 0x186a :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_130 )
switch ( V_2 -> V_122 ) {
case 0x80f2 :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_131 )
switch ( V_2 -> V_122 ) {
case 0x1882 :
case 0x1977 :
V_123 = 1 ;
}
} else if ( F_80 ( V_2 -> V_119 == V_132 ) ) {
if ( V_2 -> V_94 == V_129 )
switch( V_2 -> V_122 ) {
case 0x088C :
case 0x0890 :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_130 )
switch ( V_2 -> V_122 ) {
case 0x12bc :
case 0x12bd :
case 0x006a :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_133 )
switch ( V_2 -> V_122 ) {
case 0x12bf :
V_123 = 1 ;
}
} else if ( F_80 ( V_2 -> V_119 == V_134 ) ) {
if ( V_2 -> V_94 == V_129 )
switch( V_2 -> V_122 ) {
case 0xC00C :
V_123 = 1 ;
}
} else if ( F_80 ( V_2 -> V_119 == V_135 ) ) {
if ( V_2 -> V_94 == V_129 )
switch( V_2 -> V_122 ) {
case 0x0058 :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_136 )
switch( V_2 -> V_122 ) {
case 0xB16C :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_137 )
switch( V_2 -> V_122 ) {
case 0x00b8 :
case 0x00b9 :
case 0x00ba :
V_123 = 1 ;
}
else if ( V_2 -> V_94 == V_138 )
switch ( V_2 -> V_122 ) {
case 0x001A :
V_123 = 1 ;
}
}
}
static void F_81 ( struct V_1 * V_2 )
{
T_3 V_77 ;
if ( F_82 ( ! V_123 ) )
return;
F_5 ( V_2 , 0xF2 , & V_77 ) ;
if ( V_77 & 0x8 ) {
F_6 ( V_2 , 0xF2 , V_77 & ( ~ 0x8 ) ) ;
F_5 ( V_2 , 0xF2 , & V_77 ) ;
if ( V_77 & 0x8 )
F_4 ( & V_2 -> V_2 , L_62 , V_77 ) ;
else
F_4 ( & V_2 -> V_2 , L_63 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
T_4 V_139 ;
if ( F_82 ( ! V_123 ) )
return;
F_84 ( V_140 ) ;
F_18 ( V_2 , 0xF0 , & V_139 ) ;
V_140 = F_85 ( V_139 & 0xFFFFC000 , 0x4000 ) ;
if ( V_140 == NULL )
return;
}
static void F_86 ( struct V_1 * V_2 )
{
T_4 V_77 ;
if ( F_82 ( ! V_123 || ! V_140 ) )
return;
V_77 = F_87 ( V_140 + 0x3418 ) ;
F_88 ( V_77 & 0xFFFFFFF7 , V_140 + 0x3418 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( F_82 ( ! V_123 || ! V_140 ) )
return;
F_90 ( V_140 ) ;
V_140 = NULL ;
F_4 ( & V_2 -> V_2 , L_64 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_83 ( V_2 ) ;
F_86 ( V_2 ) ;
F_89 ( V_2 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
T_5 V_77 = 0 ;
F_14 ( V_2 , 0x77 , & V_77 ) ;
if ( V_77 & 0x10 ) {
F_4 ( & V_2 -> V_2 , L_65 ) ;
F_15 ( V_2 , 0x77 , V_77 & ~ 0x10 ) ;
}
}
static void F_93 ( struct V_1 * V_2 )
{
T_5 V_75 ;
T_3 V_141 ;
F_14 ( V_2 , V_142 , & V_75 ) ;
F_15 ( V_2 , V_142 , V_75 | ( 1 << 6 ) ) ;
F_5 ( V_2 , V_105 , & V_141 ) ;
if ( ( ( V_141 & 0xfff0 ) != 0x0960 ) && ( V_141 != 0x0018 ) ) {
F_15 ( V_2 , V_142 , V_75 ) ;
return;
}
V_2 -> V_94 = V_141 ;
F_92 ( V_2 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
T_5 V_77 ;
int V_143 = 0 ;
if ( F_82 ( V_2 -> V_119 == V_120 ) ) {
if ( V_2 -> V_94 == V_97 )
V_143 = 1 ;
}
if ( ! V_143 )
return;
F_14 ( V_2 , 0x50 , & V_77 ) ;
if ( V_77 & 0xc0 ) {
F_15 ( V_2 , 0x50 , V_77 & ( ~ 0xc0 ) ) ;
F_14 ( V_2 , 0x50 , & V_77 ) ;
if ( V_77 & 0xc0 )
F_4 ( & V_2 -> V_2 , L_66 , V_77 ) ;
else
F_4 ( & V_2 -> V_2 , L_67 ) ;
}
}
static void F_95 ( struct V_1 * V_81 )
{
T_4 V_144 , V_145 , V_11 ;
T_5 V_146 ;
if ( F_96 ( V_81 -> V_86 ) )
return;
F_18 ( V_81 , 0x40 , & V_144 ) ;
F_18 ( V_81 , 0x80 , & V_145 ) ;
V_144 &= ~ 0x00CFF302 ;
V_145 &= ~ ( 1 << 24 ) ;
switch ( V_81 -> V_94 ) {
case V_147 :
case V_148 :
case V_149 :
V_144 |= 0x0002A100 ;
break;
case V_150 :
case V_151 :
V_145 |= ( 1 << 24 ) ;
case V_152 :
case V_153 :
case V_154 :
V_144 |= 0x00C2A1B3 ;
break;
case V_155 :
V_144 |= 0x00C00000 ;
break;
}
F_68 ( V_81 , 0x40 , V_144 ) ;
F_68 ( V_81 , 0x80 , V_145 ) ;
F_14 ( V_81 , V_156 , & V_146 ) ;
V_81 -> V_9 = V_146 & 0x7f ;
V_81 -> V_157 = ! ! ( V_146 & 0x80 ) ;
F_18 ( V_81 , V_158 , & V_11 ) ;
V_81 -> V_11 = V_11 >> 8 ;
}
static void T_6 F_97 ( struct V_1 * V_81 )
{
int V_3 ;
if ( ( V_81 -> V_11 >> 8 ) != 0xff00 )
return;
if ( F_98 ( V_81 , 0 ) && F_33 ( V_81 , 0 ) )
F_99 ( & V_159 , & V_81 -> V_4 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < 6 ; V_3 ++ ) {
memset ( & V_81 -> V_4 [ V_3 ] , 0 , sizeof( V_81 -> V_4 [ V_3 ] ) ) ;
}
}
static void T_1 F_100 ( struct V_1 * V_81 )
{
F_101 ( V_81 ) ;
V_81 -> V_160 = 1 ;
}
static void T_1 F_102 ( struct V_1 * V_2 )
{
F_101 ( V_2 ) ;
V_2 -> V_160 = 1 ;
F_3 ( & V_2 -> V_2 , L_68 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
V_161 = 120 ;
V_2 -> V_162 = 1 ;
}
static void F_104 ( struct V_1 * V_2 )
{
if ( V_163 || V_164 )
return;
V_2 -> V_165 = V_166 ;
F_4 ( & V_2 -> V_2 , L_69 ,
V_2 -> V_167 , V_2 -> V_94 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_3 V_168 ;
if ( V_163 )
return;
F_5 ( V_2 , V_169 , & V_168 ) ;
V_168 |= V_170 ;
F_6 ( V_2 , V_169 , V_168 ) ;
F_4 ( & V_2 -> V_2 , L_70 ,
V_2 -> V_167 , V_2 -> V_94 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
T_4 V_171 ;
T_5 V_93 ;
if ( V_163 )
return;
F_18 ( V_2 , V_172 , & V_171 ) ;
F_68 ( V_2 , V_172 , V_171 |
V_173 ) ;
for ( V_93 = 0x10 ; V_93 < 0x10 + 32 ; V_93 ++ ) {
F_107 ( V_93 , V_174 ) ;
F_107 ( 0x00 , V_175 ) ;
}
F_68 ( V_2 , V_172 , V_171 ) ;
F_4 ( & V_2 -> V_2 , L_70 ,
V_2 -> V_167 , V_2 -> V_94 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
T_4 V_171 ;
if ( V_163 )
return;
if ( ( V_2 -> V_42 == V_176 ) ||
( V_2 -> V_42 == V_177 ) )
return;
F_18 ( V_2 , V_178 , & V_171 ) ;
V_171 &= ~ V_179 ;
F_68 ( V_2 , V_178 , V_171 ) ;
F_4 ( & V_2 -> V_2 , L_70 ,
V_2 -> V_167 , V_2 -> V_94 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
T_3 V_168 ;
if ( V_163 )
return;
F_5 ( V_2 , V_180 , & V_168 ) ;
if ( ! V_168 ) {
F_4 ( & V_2 -> V_2 , L_71
L_72 , V_2 -> V_167 , V_2 -> V_94 ) ;
return;
}
F_6 ( V_2 , V_180 , 0 ) ;
F_4 ( & V_2 -> V_2 , L_70 ,
V_2 -> V_167 , V_2 -> V_94 ) ;
}
static void T_6 F_110 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_4 [ 0 ] ;
if ( V_5 -> V_19 & 0x8 ) {
V_5 -> V_19 = 0 ;
V_5 -> V_18 = 0xf ;
}
}
static void T_1 F_111 ( struct V_1 * V_2 )
{
unsigned int V_181 = ( V_2 -> V_122 & 0xf0 ) >> 4 ;
unsigned int V_182 = V_2 -> V_122 & 0xf ;
switch ( V_2 -> V_94 ) {
case V_183 :
if ( V_2 -> V_119 == V_184 &&
V_2 -> V_122 == 0x0299 )
return;
case V_185 :
case V_186 :
case V_187 :
case V_188 :
if ( ( V_2 -> V_11 >> 8 ) == V_189 &&
V_181 ) {
F_4 ( & V_2 -> V_2 , L_73
L_74
L_75 ,
V_2 -> V_94 , V_181 , V_182 ) ;
V_2 -> V_11 = ( V_190 << 8 ) |
( V_2 -> V_11 & 0xff ) ;
}
}
}
static void T_1 F_112 ( struct V_1 * V_2 )
{
T_3 V_8 , V_191 ;
T_5 T_7 * V_192 ;
T_5 V_193 ;
int V_80 ;
switch ( V_2 -> V_94 ) {
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
F_5 ( V_2 , V_13 , & V_8 ) ;
if ( ! ( V_8 & V_14 ) || ! F_98 ( V_2 , 0 ) )
return;
V_80 = F_113 ( V_2 , V_194 ) ;
if ( V_80 ) {
F_5 ( V_2 , V_80 + V_195 , & V_191 ) ;
if ( ( V_191 & V_196 ) != V_197 )
return;
}
V_192 = F_114 ( F_98 ( V_2 , 0 ) , 8 ) ;
if ( ! V_192 ) {
F_3 ( & V_2 -> V_2 , L_76 ) ;
return;
}
V_193 = F_115 ( V_192 + 3 ) ;
if ( V_193 == 0 ) {
F_3 ( & V_2 -> V_2 , L_77
L_78 ) ;
F_116 ( 1 , V_192 + 3 ) ;
}
F_90 ( V_192 ) ;
}
static void T_1 F_117 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_2 , L_79 ) ;
F_118 ( V_2 , V_198 ) ;
}
static void T_1 F_119 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == V_199 ) {
F_4 ( & V_2 -> V_2 , L_80 ) ;
V_2 -> V_11 = V_200 ;
}
}
static void T_1 F_120 ( struct V_1 * V_2 )
{
T_3 V_201 ;
T_5 V_202 , V_203 ;
unsigned long V_60 , V_204 ;
struct V_4 * V_49 = V_2 -> V_4 + V_15 ;
F_5 ( V_2 , 0x40 , & V_201 ) ;
if ( V_201 & 0x200 ) {
F_4 ( & V_2 -> V_2 , L_81 ) ;
F_14 ( V_2 , V_205 , & V_202 ) ;
F_14 ( V_2 , V_206 , & V_203 ) ;
V_60 = ( V_202 & ( V_207 | 0x0c ) ) << 8 ;
V_204 = ( V_203 & ( V_207 | 0x0c ) ) << 8 ;
if ( V_60 <= V_204 ) {
V_49 -> V_19 = V_60 ;
V_49 -> V_18 = V_204 + 0x3ff ;
}
}
}
static void T_1 F_121 ( struct V_1 * V_2 )
{
T_3 V_201 , V_208 , V_209 ;
struct V_4 * V_49 = V_2 -> V_4 + V_15 ;
F_5 ( V_2 , 0x40 , & V_201 ) ;
if ( V_201 & 0x200 ) {
F_5 ( V_2 , V_205 , & V_208 ) ;
V_209 = V_208 | ( V_49 -> V_19 >> 8 ) | ( V_49 -> V_18 & 0xfc00 ) ;
if ( V_208 != V_209 ) {
F_4 ( & V_2 -> V_2 , L_82 ,
V_208 , V_209 ) ;
F_6 ( V_2 , V_205 , V_209 ) ;
}
}
}
static void F_122 ( struct V_1 * V_2 )
{
T_8 V_210 ;
if ( F_14 ( V_2 , 0xf41 , & V_210 ) == 0 ) {
if ( ! ( V_210 & 0x20 ) ) {
F_15 ( V_2 , 0xf41 , V_210 | 0x20 ) ;
F_4 ( & V_2 -> V_2 ,
L_83 ) ;
}
}
}
static void T_1 F_123 ( struct V_1 * V_2 )
{
struct V_1 * V_38 = F_13 ( V_40 ,
V_211 , NULL ) ;
T_8 V_210 ;
V_38 = F_13 ( V_40 , V_211 , V_38 ) ;
if ( ! V_38 )
return;
F_25 ( V_38 ) ;
if ( F_14 ( V_2 , 0x76 , & V_210 ) == 0 ) {
if ( V_210 & 0x40 ) {
F_15 ( V_2 , 0x76 , V_210 ^ 0x40 ) ;
F_4 ( & V_2 -> V_2 ,
L_84 ) ;
}
}
if ( F_14 ( V_2 , 0x72 , & V_210 ) == 0 ) {
if ( V_210 != 0 ) {
F_15 ( V_2 , 0x72 , 0x0 ) ;
F_15 ( V_2 , 0x75 , 0x1 ) ;
F_15 ( V_2 , 0x77 , 0x0 ) ;
F_4 ( & V_2 -> V_2 ,
L_85 ) ;
}
}
}
static void T_1 F_124 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_94 == V_212 ) ||
( V_2 -> V_94 == V_213 ) ||
( V_2 -> V_94 == V_214 ) ||
( V_2 -> V_94 == V_215 ) ||
( ( V_2 -> V_94 == V_216 ) &&
( V_2 -> V_42 & 0xf0 ) == 0x0 ) ) {
if ( V_2 -> V_217 )
V_2 -> V_217 -> V_218 = 0x80 ;
}
}
static void T_1 F_125 ( struct V_1 * V_2 )
{
T_5 V_75 ;
if ( F_14 ( V_2 , 0xF4 , & V_75 ) == 0 && ! ( V_75 & 0x02 ) ) {
F_4 ( & V_2 -> V_2 , L_86 ) ;
F_15 ( V_2 , 0xF4 , V_75 | 0x02 ) ;
}
}
static void T_1 F_126 ( struct V_1 * V_2 )
{
if ( V_219 ) {
F_68 ( V_2 , 0x98 , 0x1 ) ;
F_127 ( 50 ) ;
}
}
static void T_6 F_128 ( struct V_1 * V_2 )
{
F_129 () ;
F_3 ( & V_2 -> V_2 , L_87 ) ;
}
static void T_1 F_130 ( struct V_1 * V_2 )
{
if ( V_2 -> V_90 ) {
F_3 ( & V_2 -> V_2 , L_88
L_89 ) ;
V_2 -> V_90 -> V_91 |= V_220 ;
}
}
static void T_1 F_131 ( struct V_1 * V_221 )
{
struct V_1 * V_222 ;
V_222 = F_132 ( V_221 -> V_87 , F_133 ( 1 , 0 ) ) ;
if ( V_222 ) {
if ( V_222 -> V_94 == 0x9602 )
F_130 ( V_222 ) ;
F_25 ( V_222 ) ;
}
}
static int T_1 F_134 ( struct V_1 * V_2 )
{
int V_223 , V_224 = 48 ;
V_223 = F_135 ( V_2 , V_225 ) ;
while ( V_223 && V_224 -- ) {
T_5 V_16 ;
if ( F_14 ( V_2 , V_223 + V_226 ,
& V_16 ) == 0 )
{
F_4 ( & V_2 -> V_2 , L_90 ,
V_16 & V_227 ?
L_91 : L_92 ) ;
return ( V_16 & V_227 ) != 0 ;
}
V_223 = F_136 ( V_2 , V_223 ,
V_225 ) ;
}
return 0 ;
}
static void T_1 F_137 ( struct V_1 * V_2 )
{
if ( V_2 -> V_90 && ! F_134 ( V_2 ) ) {
F_3 ( & V_2 -> V_2 , L_88
L_89 ) ;
V_2 -> V_90 -> V_91 |= V_220 ;
}
}
static void T_1 F_138 ( struct V_1 * V_2 )
{
struct V_1 * V_81 ;
if ( ! V_2 -> V_90 )
return;
V_81 = F_132 ( V_2 -> V_87 , 0 ) ;
if ( ! V_81 )
return;
if ( ! F_134 ( V_2 ) && ! F_134 ( V_81 ) ) {
F_3 ( & V_2 -> V_2 , L_88
L_89 ) ;
V_2 -> V_90 -> V_91 |= V_220 ;
}
F_25 ( V_81 ) ;
}
static void T_1 F_139 ( struct V_1 * V_2 )
{
int V_223 , V_224 = 48 ;
V_223 = F_135 ( V_2 , V_225 ) ;
while ( V_223 && V_224 -- ) {
T_5 V_16 ;
if ( F_14 ( V_2 , V_223 + V_226 ,
& V_16 ) == 0 ) {
F_4 ( & V_2 -> V_2 , L_93 ) ;
F_15 ( V_2 , V_223 + V_226 ,
V_16 | V_227 ) ;
}
V_223 = F_136 ( V_2 , V_223 ,
V_225 ) ;
}
}
static void T_1 F_140 ( struct V_1 * V_2 )
{
const char * V_228 = F_141 ( V_229 ) ;
if ( V_228 &&
( strstr ( V_228 , L_94 ) ||
strstr ( V_228 , L_95 ) ) ) {
F_4 ( & V_2 -> V_2 ,
L_96 ) ;
V_2 -> V_160 = 1 ;
}
}
static void T_1 F_142 ( struct V_1 * V_2 )
{
T_4 V_230 ;
if ( ! F_113 ( V_2 , V_231 ) )
return;
F_18 ( V_2 , 0x74 , & V_230 ) ;
if ( V_230 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_143 ( V_232 L_97 ) ;
V_230 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_68 ( V_2 , 0x74 , V_230 ) ;
}
}
static int T_1 F_144 ( struct V_1 * V_2 )
{
int V_223 , V_224 = 48 ;
int V_233 = 0 ;
V_223 = F_135 ( V_2 , V_225 ) ;
while ( V_223 && V_224 -- ) {
T_5 V_16 ;
if ( V_233 < 1 )
V_233 = 1 ;
if ( F_14 ( V_2 , V_223 + V_226 ,
& V_16 ) == 0 ) {
if ( V_16 & V_227 ) {
if ( V_233 < 2 ) {
V_233 = 2 ;
break;
}
}
}
V_223 = F_136 ( V_2 , V_223 ,
V_225 ) ;
}
return V_233 ;
}
static int T_1 F_145 ( struct V_1 * V_221 )
{
struct V_1 * V_2 ;
int V_223 ;
int V_3 , V_234 ;
int V_233 = 0 ;
V_234 = V_221 -> V_86 >> 3 ;
for ( V_3 = V_234 + 1 ; V_3 < 0x20 ; V_3 ++ ) {
V_2 = F_132 ( V_221 -> V_87 , F_133 ( V_3 , 0 ) ) ;
if ( ! V_2 )
continue;
V_223 = F_135 ( V_2 , V_235 ) ;
if ( V_223 != 0 ) {
F_25 ( V_2 ) ;
break;
}
if ( F_144 ( V_2 ) ) {
V_233 = 1 ;
F_25 ( V_2 ) ;
break;
}
F_25 ( V_2 ) ;
}
return V_233 ;
}
static int T_1 F_146 ( struct V_1 * V_2 )
{
int V_223 , V_236 ;
int V_18 = 0 ;
T_3 V_16 , V_237 ;
V_223 = F_135 ( V_2 , V_235 ) ;
if ( ! V_223 )
goto V_238;
F_5 ( V_2 , V_223 + V_239 , & V_16 ) ;
V_236 = ( ( V_16 >> 10 ) & 1 ) ?
V_240 : V_241 ;
F_5 ( V_2 , V_223 + V_236 , & V_237 ) ;
if ( V_237 & ( 1 << 6 ) )
V_18 = 1 ;
V_238:
return V_18 ;
}
static void T_1 F_147 ( struct V_1 * V_2 )
{
struct V_1 * V_221 ;
int V_223 ;
int V_3 , V_234 ;
int V_233 = 0 ;
V_234 = V_2 -> V_86 >> 3 ;
for ( V_3 = V_234 ; V_3 >= 0 ; V_3 -- ) {
V_221 = F_132 ( V_2 -> V_87 , F_133 ( V_3 , 0 ) ) ;
if ( ! V_221 )
continue;
V_223 = F_135 ( V_221 , V_235 ) ;
if ( V_223 != 0 ) {
V_233 = 1 ;
break;
}
F_25 ( V_221 ) ;
}
if ( ! V_233 )
return;
if ( V_221 == V_2 && F_146 ( V_221 ) &&
F_145 ( V_221 ) )
goto V_238;
if ( F_134 ( V_221 ) )
goto V_238;
F_139 ( V_2 ) ;
V_238:
F_25 ( V_221 ) ;
}
static void T_1 F_148 ( struct V_1 * V_2 )
{
int V_223 , V_224 = 48 ;
V_223 = F_135 ( V_2 , V_225 ) ;
while ( V_223 && V_224 -- ) {
T_5 V_16 ;
if ( F_14 ( V_2 , V_223 + V_226 ,
& V_16 ) == 0 ) {
F_4 ( & V_2 -> V_2 , L_98 ) ;
F_15 ( V_2 , V_223 + V_226 ,
V_16 & ~ V_227 ) ;
}
V_223 = F_136 ( V_2 , V_223 ,
V_225 ) ;
}
}
static void T_1 F_149 ( struct V_1 * V_2 , int V_242 )
{
struct V_1 * V_221 ;
int V_223 ;
int V_233 ;
if ( ! F_150 () )
return;
V_233 = F_144 ( V_2 ) ;
if ( V_233 == 0 )
return;
V_221 = F_151 ( 0 , F_133 ( 0 , 0 ) ) ;
if ( V_221 == NULL ) {
F_3 ( & V_2 -> V_2 ,
L_99 ) ;
return;
}
V_223 = F_135 ( V_221 , V_235 ) ;
if ( V_223 != 0 ) {
if ( V_233 == 1 ) {
if ( V_242 )
F_139 ( V_2 ) ;
else
F_147 ( V_2 ) ;
}
return;
}
if ( V_233 == 1 )
return;
F_148 ( V_2 ) ;
}
static void T_1 F_152 ( struct V_1 * V_2 )
{
return F_149 ( V_2 , 1 ) ;
}
static void T_1 F_153 ( struct V_1 * V_2 )
{
return F_149 ( V_2 , 0 ) ;
}
static void T_1 F_154 ( struct V_1 * V_2 )
{
V_2 -> V_116 |= V_243 ;
}
static void T_1 F_155 ( struct V_1 * V_2 )
{
struct V_1 * V_38 ;
V_38 = F_13 ( V_244 , V_245 ,
NULL ) ;
if ( ! V_38 )
return;
if ( ( V_38 -> V_42 < 0x3B ) && ( V_38 -> V_42 >= 0x30 ) )
V_2 -> V_116 |= V_243 ;
F_25 ( V_38 ) ;
}
static void T_1 F_156 ( struct V_1 * V_2 )
{
V_2 -> V_246 = 1 ;
}
static void F_157 ( struct V_1 * V_2 )
{
T_5 V_247 ;
T_5 V_248 ;
T_5 V_249 ;
if ( F_96 ( V_2 -> V_86 ) )
return;
F_14 ( V_2 , 0xB7 , & V_249 ) ;
if ( V_249 & 0x02 )
return;
F_14 ( V_2 , 0x8E , & V_247 ) ;
F_15 ( V_2 , 0x8E , 0xAA ) ;
F_14 ( V_2 , 0x8D , & V_248 ) ;
F_15 ( V_2 , 0x8D , 0xB7 ) ;
F_15 ( V_2 , 0xB7 , V_249 | 0x02 ) ;
F_15 ( V_2 , 0x8E , V_247 ) ;
F_15 ( V_2 , 0x8D , V_248 ) ;
F_158 ( & V_2 -> V_2 , L_100 ) ;
F_158 ( & V_2 -> V_2 , L_101 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
T_5 V_247 ;
T_5 V_249 ;
if ( F_96 ( V_2 -> V_86 ) )
return;
if ( V_2 -> V_94 == V_250 ) {
F_15 ( V_2 , 0xf9 , 0xfc ) ;
F_15 ( V_2 , 0x150 , 0x10 ) ;
F_15 ( V_2 , 0xf9 , 0x00 ) ;
F_15 ( V_2 , 0xfc , 0x01 ) ;
F_15 ( V_2 , 0xe1 , 0x32 ) ;
F_15 ( V_2 , 0xfc , 0x00 ) ;
F_158 ( & V_2 -> V_2 , L_102 ) ;
}
F_14 ( V_2 , 0xCB , & V_249 ) ;
if ( V_249 & 0x02 )
return;
F_14 ( V_2 , 0xCA , & V_247 ) ;
F_15 ( V_2 , 0xCA , 0x57 ) ;
F_15 ( V_2 , 0xCB , V_249 | 0x02 ) ;
F_15 ( V_2 , 0xCA , V_247 ) ;
F_158 ( & V_2 -> V_2 , L_103 ) ;
F_158 ( & V_2 -> V_2 , L_101 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
T_4 V_251 ;
F_18 ( V_2 , V_252 , & V_251 ) ;
F_68 ( V_2 , V_252 , V_251 | V_253 ) ;
}
static void T_1 F_161 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == V_199 ) {
F_4 ( & V_2 -> V_2 , L_104 ) ;
V_2 -> V_11 = V_254 ;
}
}
static void T_1 F_162 ( struct V_1 * V_2 )
{
V_2 -> V_255 = 1 ;
}
static void T_1 F_163 ( struct V_1 * V_2 )
{
int V_256 ;
T_3 V_257 ;
if ( V_258 == V_259 )
return;
V_256 = F_5 ( V_2 , 0x48 , & V_257 ) ;
if ( V_256 ) {
F_164 ( & V_2 -> V_2 , L_105
L_106 ) ;
return;
}
if ( ! ( V_257 & ( 1 << 10 ) ) )
return;
V_257 &= ~ ( 1 << 10 ) ;
V_256 = F_6 ( V_2 , 0x48 , V_257 ) ;
if ( V_256 ) {
F_164 ( & V_2 -> V_2 , L_107
L_106 ) ;
return;
}
F_165 ( L_108
L_109 ) ;
}
static void F_166 ( struct V_1 * V_2 , struct V_260 * V_261 ,
struct V_260 * V_18 )
{
while ( V_261 < V_18 ) {
if ( ( V_261 -> V_167 == V_2 -> V_167 || V_261 -> V_167 == ( T_3 ) V_262 ) &&
( V_261 -> V_94 == V_2 -> V_94 || V_261 -> V_94 == ( T_3 ) V_262 ) ) {
F_167 ( & V_2 -> V_2 , L_110 , V_261 -> V_263 ) ;
V_261 -> V_263 ( V_2 ) ;
}
V_261 ++ ;
}
}
void F_168 ( enum V_264 V_265 , struct V_1 * V_2 )
{
struct V_260 * V_19 , * V_18 ;
switch( V_265 ) {
case V_266 :
V_19 = V_267 ;
V_18 = V_268 ;
break;
case V_269 :
V_19 = V_270 ;
V_18 = V_271 ;
break;
case V_272 :
V_19 = V_273 ;
V_18 = V_274 ;
break;
case V_275 :
V_19 = V_276 ;
V_18 = V_277 ;
break;
case V_278 :
V_19 = V_279 ;
V_18 = V_280 ;
break;
case V_281 :
V_19 = V_282 ;
V_18 = V_283 ;
break;
case V_284 :
V_19 = V_285 ;
V_18 = V_286 ;
break;
default:
return;
}
F_166 ( V_2 , V_19 , V_18 ) ;
}
static int T_6 F_169 ( void )
{
struct V_1 * V_2 = NULL ;
T_5 V_287 = 0 ;
T_5 V_83 ;
if ( V_288 )
F_143 ( V_289 L_111 ,
V_288 << 2 ) ;
F_170 (dev) {
F_168 ( V_272 , V_2 ) ;
if ( ! V_288 ) {
F_14 ( V_2 , V_290 , & V_83 ) ;
if ( ! V_287 )
V_287 = V_83 ;
if ( ! V_83 || V_287 == V_83 )
continue;
F_143 ( V_289 L_112
L_113 , V_287 << 2 , V_83 << 2 ,
V_291 << 2 ) ;
V_288 = V_291 ;
}
}
if ( ! V_288 ) {
F_143 ( V_289 L_114 ,
V_287 << 2 , V_291 << 2 ) ;
V_288 = V_287 ? V_287 : V_291 ;
}
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , int V_292 )
{
int V_223 ;
if ( V_2 -> V_11 == V_293 ) {
V_223 = F_113 ( V_2 , V_294 ) ;
if ( ! V_223 )
return - V_295 ;
if ( V_292 )
return 0 ;
F_15 ( V_2 , V_223 + 0x4 , 1 ) ;
F_172 ( 100 ) ;
return 0 ;
} else {
return - V_295 ;
}
}
static int F_173 ( struct V_1 * V_2 , int V_292 )
{
int V_223 ;
V_223 = F_113 ( V_2 , V_296 ) ;
if ( ! V_223 )
return - V_295 ;
if ( V_292 )
return 0 ;
F_6 ( V_2 , V_223 + V_297 ,
V_298 ) ;
F_172 ( 100 ) ;
return 0 ;
}
int F_174 ( struct V_1 * V_2 , int V_292 )
{
const struct V_299 * V_3 ;
for ( V_3 = V_299 ; V_3 -> V_300 ; V_3 ++ ) {
if ( ( V_3 -> V_167 == V_2 -> V_167 ||
V_3 -> V_167 == ( T_3 ) V_262 ) &&
( V_3 -> V_94 == V_2 -> V_94 ||
V_3 -> V_94 == ( T_3 ) V_262 ) )
return V_3 -> V_300 ( V_2 , V_292 ) ;
}
return - V_295 ;
}
