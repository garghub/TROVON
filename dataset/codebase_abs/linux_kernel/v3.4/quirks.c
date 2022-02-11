static void T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 1 ;
}
static void T_1 F_2 ( struct V_1 * V_2 )
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
static void T_1 F_8 ( struct V_1 * V_2 )
{
if ( ! V_9 ) {
V_9 = 1 ;
F_6 ( & V_2 -> V_2 , L_2 ) ;
}
}
static void T_1 F_9 ( struct V_1 * V_2 )
{
T_2 V_10 ;
T_3 V_11 ;
F_10 ( V_2 , 0x40 , & V_10 ) ;
V_10 = V_10 & 0xff80 ;
V_11 = F_11 ( V_10 ) ;
if ( V_11 & 0x10 ) {
F_6 ( & V_2 -> V_2 , V_12 L_3 ) ;
F_12 ( 0x10 , V_10 ) ;
}
}
static void T_1 F_13 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_14 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_4 ) ;
V_13 |= V_14 ;
}
}
static void T_1 F_14 ( struct V_1 * V_2 )
{
T_4 V_15 ;
F_5 ( V_2 , 0x08 , & V_15 ) ;
if ( V_15 == 0x13 ) {
F_6 ( & V_2 -> V_2 , L_5 ) ;
V_13 |= V_16 ;
}
}
static void T_1 F_15 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_17 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_6 ) ;
V_13 |= V_17 ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
T_4 V_19 ;
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
static void T_1 F_18 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_24 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_6 ) ;
V_13 |= V_24 ;
}
}
static void T_1 F_19 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_25 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_6 ) ;
V_13 |= V_25 ;
}
}
static void T_5 F_20 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_26 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_6 ) ;
V_13 |= V_26 | V_17 ;
}
}
static void T_1 F_21 ( struct V_1 * V_2 )
{
if ( ( V_13 & V_27 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_6 ) ;
V_13 |= V_27 ;
}
}
static void T_1 F_22 ( struct V_1 * V_2 )
{
V_2 -> V_28 = 0xA0 ;
}
static void T_1 F_23 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_29 [ 0 ] ;
if ( ( V_30 -> V_31 & 0x3ffffff ) || V_30 -> V_32 != V_30 -> V_31 + 0x3ffffff ) {
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0x3ffffff ;
}
}
static void T_1 F_24 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 , 0 ) != 8 ) {
struct V_29 * V_33 = & V_2 -> V_29 [ 0 ] ;
V_33 -> V_32 = V_33 -> V_31 + 8 - 1 ;
F_6 ( & V_2 -> V_2 , L_8
L_9 ) ;
}
}
static void T_1 F_26 ( struct V_1 * V_2 , unsigned V_34 ,
unsigned V_35 , int V_36 , const char * V_37 )
{
V_34 &= ~ ( V_35 - 1 ) ;
if ( V_34 ) {
struct V_38 V_39 ;
struct V_29 * V_33 = V_2 -> V_29 + V_36 ;
V_33 -> V_37 = F_27 ( V_2 ) ;
V_33 -> V_31 = V_34 ;
V_33 -> V_32 = V_34 + V_35 - 1 ;
V_33 -> V_40 = V_41 ;
V_39 . V_31 = V_33 -> V_31 ;
V_39 . V_32 = V_33 -> V_32 ;
F_28 ( V_2 , V_33 , & V_39 ) ;
if ( F_29 ( V_2 , V_36 ) == 0 )
F_6 ( & V_2 -> V_2 , L_10 ,
V_33 , V_37 ) ;
}
}
static void T_1 F_30 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_11 ) ;
F_31 ( 0x3b0 , 0x0C , L_12 ) ;
F_31 ( 0x3d3 , 0x01 , L_12 ) ;
}
static void T_1 F_32 ( struct V_1 * V_2 )
{
T_3 V_34 ;
F_33 ( V_2 , 0xE0 , & V_34 ) ;
F_26 ( V_2 , V_34 , 64 , V_42 , L_13 ) ;
F_33 ( V_2 , 0xE2 , & V_34 ) ;
F_26 ( V_2 , V_34 , 32 , V_42 + 1 , L_14 ) ;
}
static void F_34 ( struct V_1 * V_2 , const char * V_37 , unsigned int V_43 , unsigned int V_44 )
{
T_2 V_45 ;
T_2 V_46 , V_35 , V_47 ;
F_10 ( V_2 , V_43 , & V_45 ) ;
if ( ( V_45 & V_44 ) != V_44 )
return;
V_46 = ( V_45 >> 16 ) & 15 ;
V_47 = V_45 & 0xffff ;
V_35 = 16 ;
for (; ; ) {
unsigned V_48 = V_35 >> 1 ;
if ( ( V_48 & V_46 ) == V_48 )
break;
V_35 = V_48 ;
}
V_47 &= - V_35 ;
F_6 ( & V_2 -> V_2 , L_15 , V_37 , V_47 , V_47 + V_35 - 1 ) ;
}
static void F_35 ( struct V_1 * V_2 , const char * V_37 , unsigned int V_43 , unsigned int V_44 )
{
T_2 V_45 ;
T_2 V_46 , V_35 , V_47 ;
F_10 ( V_2 , V_43 , & V_45 ) ;
if ( ( V_45 & V_44 ) != V_44 )
return;
V_47 = V_45 & 0xffff0000 ;
V_46 = ( V_45 & 0x3f ) << 16 ;
V_35 = 128 << 16 ;
for (; ; ) {
unsigned V_48 = V_35 >> 1 ;
if ( ( V_48 & V_46 ) == V_48 )
break;
V_35 = V_48 ;
}
V_47 &= - V_35 ;
F_6 ( & V_2 -> V_2 , L_16 , V_37 , V_47 , V_47 + V_35 - 1 ) ;
}
static void T_1 F_36 ( struct V_1 * V_2 )
{
T_2 V_34 , V_49 ;
F_10 ( V_2 , 0x40 , & V_34 ) ;
F_26 ( V_2 , V_34 , 64 , V_42 , L_17 ) ;
F_10 ( V_2 , 0x90 , & V_34 ) ;
F_26 ( V_2 , V_34 , 16 , V_42 + 1 , L_18 ) ;
F_10 ( V_2 , 0x5c , & V_49 ) ;
F_34 ( V_2 , L_19 , 0x60 , 3 << 21 ) ;
F_34 ( V_2 , L_20 , 0x64 , 3 << 21 ) ;
if ( V_49 & ( 1 << 29 ) ) {
F_34 ( V_2 , L_21 , 0x68 , 1 << 20 ) ;
F_35 ( V_2 , L_22 , 0x6c , 1 << 7 ) ;
}
if ( V_49 & ( 1 << 30 ) ) {
F_34 ( V_2 , L_23 , 0x70 , 1 << 20 ) ;
F_35 ( V_2 , L_24 , 0x74 , 1 << 7 ) ;
}
F_34 ( V_2 , L_25 , 0x78 , 1 << 20 ) ;
F_34 ( V_2 , L_26 , 0x7c , 1 << 20 ) ;
}
static void T_1 F_37 ( struct V_1 * V_2 )
{
T_2 V_34 ;
T_4 V_44 ;
F_5 ( V_2 , V_50 , & V_44 ) ;
if ( V_44 & V_51 ) {
F_10 ( V_2 , V_52 , & V_34 ) ;
V_34 &= V_53 ;
if ( V_34 >= V_54 )
F_26 ( V_2 , V_34 , 128 , V_42 ,
L_27 ) ;
}
F_5 ( V_2 , V_55 , & V_44 ) ;
if ( V_44 & V_56 ) {
F_10 ( V_2 , V_57 , & V_34 ) ;
V_34 &= V_53 ;
if ( V_34 >= V_54 )
F_26 ( V_2 , V_34 , 64 ,
V_42 + 1 , L_28 ) ;
}
}
static void T_1 F_38 ( struct V_1 * V_2 )
{
T_2 V_34 ;
T_4 V_44 ;
F_5 ( V_2 , V_50 , & V_44 ) ;
if ( V_44 & V_58 ) {
F_10 ( V_2 , V_52 , & V_34 ) ;
V_34 &= V_53 ;
if ( V_34 >= V_54 )
F_26 ( V_2 , V_34 , 128 , V_42 ,
L_29 ) ;
}
F_5 ( V_2 , V_59 , & V_44 ) ;
if ( V_44 & V_60 ) {
F_10 ( V_2 , V_61 , & V_34 ) ;
V_34 &= V_53 ;
if ( V_34 >= V_54 )
F_26 ( V_2 , V_34 , 64 ,
V_42 + 1 , L_30 ) ;
}
}
static void T_1 F_39 ( struct V_1 * V_2 , unsigned V_62 , const char * V_37 , int V_63 )
{
T_2 V_64 ;
T_2 V_35 , V_47 ;
F_10 ( V_2 , V_62 , & V_64 ) ;
if ( ! ( V_64 & 1 ) )
return;
V_47 = V_64 & 0xfffc ;
if ( V_63 ) {
V_35 = 16 ;
} else {
V_35 = 128 ;
}
V_47 &= ~ ( V_35 - 1 ) ;
F_6 ( & V_2 -> V_2 , L_15 , V_37 , V_47 , V_47 + V_35 - 1 ) ;
}
static void T_1 F_40 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_39 ( V_2 , 0x84 , L_31 , 0 ) ;
F_39 ( V_2 , 0x88 , L_32 , 1 ) ;
}
static void T_1 F_41 ( struct V_1 * V_2 , unsigned V_62 , const char * V_37 )
{
T_2 V_64 ;
T_2 V_46 , V_47 ;
F_10 ( V_2 , V_62 , & V_64 ) ;
if ( ! ( V_64 & 1 ) )
return;
V_47 = V_64 & 0xfffc ;
V_46 = ( V_64 >> 16 ) & 0xfc ;
V_46 |= 3 ;
F_6 ( & V_2 -> V_2 , L_33 , V_37 , V_47 , V_46 ) ;
}
static void T_1 F_42 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_41 ( V_2 , 0x84 , L_34 ) ;
F_41 ( V_2 , 0x88 , L_35 ) ;
F_41 ( V_2 , 0x8c , L_36 ) ;
F_41 ( V_2 , 0x90 , L_37 ) ;
}
static void T_1 F_43 ( struct V_1 * V_2 )
{
T_2 V_34 ;
if ( V_2 -> V_22 & 0x10 ) {
F_10 ( V_2 , 0x48 , & V_34 ) ;
V_34 &= V_53 ;
F_26 ( V_2 , V_34 , 256 , V_42 , L_38 ) ;
}
}
static void T_1 F_44 ( struct V_1 * V_2 )
{
T_3 V_65 ;
T_2 V_66 ;
F_43 ( V_2 ) ;
F_33 ( V_2 , 0x70 , & V_65 ) ;
V_65 &= V_53 ;
F_26 ( V_2 , V_65 , 128 , V_42 + 1 , L_39 ) ;
F_10 ( V_2 , 0x90 , & V_66 ) ;
V_66 &= V_53 ;
F_26 ( V_2 , V_66 , 16 , V_42 + 2 , L_40 ) ;
}
static void T_1 F_45 ( struct V_1 * V_2 )
{
T_3 V_67 , V_66 ;
F_33 ( V_2 , 0x88 , & V_67 ) ;
V_67 &= V_53 ;
F_26 ( V_2 , V_67 , 128 , V_42 , L_41 ) ;
F_33 ( V_2 , 0xd0 , & V_66 ) ;
V_66 &= V_53 ;
F_26 ( V_2 , V_66 , 16 , V_42 + 1 , L_42 ) ;
}
static void T_1 F_46 ( struct V_1 * V_2 )
{
struct V_1 * V_68 ;
T_3 V_69 ;
F_47 ( & V_2 -> V_2 , L_43
L_44 ) ;
F_48 (pdev, &dev->subordinate->devices, bus_list) {
F_33 ( V_68 , V_70 , & V_69 ) ;
if ( V_69 & V_71 )
F_49 ( V_68 , V_70 , V_69 & ~ V_71 ) ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
T_4 V_72 ;
if ( V_73 < 1 )
V_72 = 0 ;
else
V_72 = 0x1f ;
F_6 ( & V_2 -> V_2 , L_45 ,
V_72 == 0 ? L_46 : L_47 ) ;
F_7 ( V_2 , 0x58 , V_72 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_4 V_74 ;
#define F_52 8
F_5 ( V_2 , 0x5B , & V_74 ) ;
if ( ! ( V_74 & F_52 ) ) {
F_6 ( & V_2 -> V_2 , L_48 ) ;
F_7 ( V_2 , 0x5B , V_74 | F_52 ) ;
}
}
static void T_1 F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 >= 0x02 ) {
F_47 ( & V_2 -> V_2 , L_49 ) ;
F_47 ( & V_2 -> V_2 , L_50 ) ;
}
}
static void T_5 F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 == 0 && V_2 -> V_76 -> V_77 == 0 )
V_78 = 1 ;
}
static void T_5 F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 && V_2 -> V_22 <= 0x12 ) {
F_6 ( & V_2 -> V_2 , L_51
L_52 , V_2 -> V_22 ) ;
V_2 -> V_79 -> V_80 |= V_81 ;
}
}
static void T_1 F_56 ( struct V_1 * V_5 )
{
T_4 V_82 ;
F_5 ( V_5 , 0x42 , & V_82 ) ;
V_82 &= 0xf ;
if ( V_82 && ( V_82 != 2 ) )
V_5 -> V_82 = V_82 ;
}
static void F_57 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_83 ) {
case V_21 :
V_84 = F_58 ( V_2 -> V_75 ) ;
V_85 = F_58 ( V_2 -> V_75 ) ;
break;
case V_86 :
case V_87 :
V_84 = 15 ;
break;
case V_88 :
V_84 = 16 ;
break;
case V_23 :
case V_89 :
case V_90 :
case V_91 :
V_84 = 17 ;
break;
}
}
static void F_59 ( struct V_1 * V_2 )
{
T_4 V_82 , V_92 ;
if ( V_84 == - 1 )
return;
V_92 = V_2 -> V_82 ;
if ( ! V_92 || V_92 > 15 )
return;
if ( V_2 -> V_76 -> V_77 != 0 || F_58 ( V_2 -> V_75 ) > V_85 ||
F_58 ( V_2 -> V_75 ) < V_84 )
return;
F_5 ( V_2 , V_93 , & V_82 ) ;
if ( V_92 != V_82 ) {
F_6 ( & V_2 -> V_2 , L_53 ,
V_82 , V_92 ) ;
F_60 ( 15 ) ;
F_7 ( V_2 , V_93 , V_92 ) ;
}
}
static void T_1 F_61 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0xfc , 0 ) ;
F_33 ( V_2 , V_94 , & V_2 -> V_83 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 , V_95 , 0 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
T_2 V_96 ;
F_10 ( V_2 , 0x4C , & V_96 ) ;
if ( ( V_96 & 6 ) != 6 ) {
V_96 |= 6 ;
F_47 ( & V_2 -> V_2 , L_54 ) ;
F_63 ( V_2 , 0x4C , V_96 ) ;
F_10 ( V_2 , 0x84 , & V_96 ) ;
V_96 |= ( 1 << 23 ) ;
F_63 ( V_2 , 0x84 , V_96 ) ;
}
}
static void T_1 F_65 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_29 [ 1 ] ;
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0xffffff ;
}
static void T_1 F_66 ( struct V_1 * V_2 )
{
V_2 -> V_97 = 1 ;
}
static void F_67 ( struct V_1 * V_2 )
{
T_4 V_62 ;
F_5 ( V_2 , 0x41 , & V_62 ) ;
if ( V_62 & 2 ) {
V_62 &= ~ 2 ;
F_6 ( & V_2 -> V_2 , L_55 , V_62 ) ;
F_7 ( V_2 , 0x41 , V_62 ) ;
}
}
static void F_68 ( struct V_1 * V_68 )
{
T_3 V_98 ;
if ( V_68 -> V_22 != 0x04 )
return;
F_33 ( V_68 , 0x40 , & V_98 ) ;
if ( V_98 & ( 1 << 6 ) ) {
V_98 &= ~ ( 1 << 6 ) ;
F_49 ( V_68 , 0x40 , V_98 ) ;
F_6 ( & V_68 -> V_2 , L_56 ) ;
}
}
static void T_1 F_69 ( struct V_1 * V_68 )
{
T_4 V_72 ;
F_5 ( V_68 , V_99 , & V_72 ) ;
if ( V_72 == 0x01 ) {
F_5 ( V_68 , 0x40 , & V_72 ) ;
F_7 ( V_68 , 0x40 , V_72 | 1 ) ;
F_7 ( V_68 , 0x9 , 1 ) ;
F_7 ( V_68 , 0xa , 6 ) ;
F_7 ( V_68 , 0x40 , V_72 ) ;
V_68 -> V_100 = V_101 ;
F_6 ( & V_68 -> V_2 , L_57 ) ;
}
}
static void T_1 F_70 ( struct V_1 * V_68 )
{
T_4 V_102 ;
F_5 ( V_68 , V_103 , & V_102 ) ;
if ( V_102 & 5 ) {
V_102 &= ~ 5 ;
V_68 -> V_100 &= ~ 5 ;
F_7 ( V_68 , V_103 , V_102 ) ;
}
}
static void T_5 F_71 ( struct V_1 * V_68 )
{
T_4 V_102 ;
F_5 ( V_68 , V_103 , & V_102 ) ;
if ( ( ( V_102 & 1 ) && ! ( V_102 & 4 ) ) || ( ( V_102 & 4 ) && ! ( V_102 & 1 ) ) ) {
F_6 ( & V_68 -> V_2 , L_58 ) ;
V_102 &= ~ 5 ;
V_68 -> V_100 &= ~ 5 ;
F_7 ( V_68 , V_103 , V_102 ) ;
}
}
static void T_1 F_72 ( struct V_1 * V_68 )
{
V_68 -> V_104 |= V_105 ;
}
static void T_5 F_73 ( struct V_1 * V_2 )
{
V_2 -> V_100 = V_106 << 8 ;
}
static void T_5 F_74 ( struct V_1 * V_2 )
{
if ( F_75 ( V_2 -> V_107 == V_108 ) ) {
if ( V_2 -> V_83 == V_109 )
switch( V_2 -> V_110 ) {
case 0x8025 :
case 0x8070 :
case 0x8088 :
case 0x1626 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_112 )
switch( V_2 -> V_110 ) {
case 0x80b1 :
case 0x80b2 :
case 0x8093 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_113 )
switch( V_2 -> V_110 ) {
case 0x8030 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_114 )
switch ( V_2 -> V_110 ) {
case 0x8070 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_115 )
switch ( V_2 -> V_110 ) {
case 0x80c9 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_116 )
switch ( V_2 -> V_110 ) {
case 0x1751 :
case 0x1821 :
case 0x1897 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_117 )
switch ( V_2 -> V_110 ) {
case 0x184b :
case 0x186a :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_118 )
switch ( V_2 -> V_110 ) {
case 0x80f2 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_119 )
switch ( V_2 -> V_110 ) {
case 0x1882 :
case 0x1977 :
V_111 = 1 ;
}
} else if ( F_75 ( V_2 -> V_107 == V_120 ) ) {
if ( V_2 -> V_83 == V_117 )
switch( V_2 -> V_110 ) {
case 0x088C :
case 0x0890 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_118 )
switch ( V_2 -> V_110 ) {
case 0x12bc :
case 0x12bd :
case 0x006a :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_121 )
switch ( V_2 -> V_110 ) {
case 0x12bf :
V_111 = 1 ;
}
} else if ( F_75 ( V_2 -> V_107 == V_122 ) ) {
if ( V_2 -> V_83 == V_117 )
switch( V_2 -> V_110 ) {
case 0xC00C :
V_111 = 1 ;
}
} else if ( F_75 ( V_2 -> V_107 == V_123 ) ) {
if ( V_2 -> V_83 == V_117 )
switch( V_2 -> V_110 ) {
case 0x0058 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_124 )
switch( V_2 -> V_110 ) {
case 0xB16C :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_125 )
switch( V_2 -> V_110 ) {
case 0x00b8 :
case 0x00b9 :
case 0x00ba :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_126 )
switch ( V_2 -> V_110 ) {
case 0x001A :
V_111 = 1 ;
}
}
}
static void F_76 ( struct V_1 * V_2 )
{
T_3 V_64 ;
if ( F_77 ( ! V_111 ) )
return;
F_33 ( V_2 , 0xF2 , & V_64 ) ;
if ( V_64 & 0x8 ) {
F_49 ( V_2 , 0xF2 , V_64 & ( ~ 0x8 ) ) ;
F_33 ( V_2 , 0xF2 , & V_64 ) ;
if ( V_64 & 0x8 )
F_6 ( & V_2 -> V_2 , L_59 , V_64 ) ;
else
F_6 ( & V_2 -> V_2 , L_60 ) ;
}
}
static void F_78 ( struct V_1 * V_2 )
{
T_2 V_127 ;
if ( F_77 ( ! V_111 ) )
return;
F_79 ( V_128 ) ;
F_10 ( V_2 , 0xF0 , & V_127 ) ;
V_128 = F_80 ( V_127 & 0xFFFFC000 , 0x4000 ) ;
if ( V_128 == NULL )
return;
}
static void F_81 ( struct V_1 * V_2 )
{
T_2 V_64 ;
if ( F_77 ( ! V_111 || ! V_128 ) )
return;
V_64 = F_82 ( V_128 + 0x3418 ) ;
F_83 ( V_64 & 0xFFFFFFF7 , V_128 + 0x3418 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( F_77 ( ! V_111 || ! V_128 ) )
return;
F_85 ( V_128 ) ;
V_128 = NULL ;
F_6 ( & V_2 -> V_2 , L_61 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_78 ( V_2 ) ;
F_81 ( V_2 ) ;
F_84 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
T_4 V_64 = 0 ;
F_5 ( V_2 , 0x77 , & V_64 ) ;
if ( V_64 & 0x10 ) {
F_6 ( & V_2 -> V_2 , L_62 ) ;
F_7 ( V_2 , 0x77 , V_64 & ~ 0x10 ) ;
}
}
static void F_88 ( struct V_1 * V_2 )
{
T_4 V_62 ;
T_3 V_129 ;
F_5 ( V_2 , V_130 , & V_62 ) ;
F_7 ( V_2 , V_130 , V_62 | ( 1 << 6 ) ) ;
F_33 ( V_2 , V_94 , & V_129 ) ;
if ( ( ( V_129 & 0xfff0 ) != 0x0960 ) && ( V_129 != 0x0018 ) ) {
F_7 ( V_2 , V_130 , V_62 ) ;
return;
}
V_2 -> V_83 = V_129 ;
F_87 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
T_4 V_64 ;
int V_131 = 0 ;
if ( F_77 ( V_2 -> V_107 == V_108 ) ) {
if ( V_2 -> V_83 == V_86 )
V_131 = 1 ;
}
if ( ! V_131 )
return;
F_5 ( V_2 , 0x50 , & V_64 ) ;
if ( V_64 & 0xc0 ) {
F_7 ( V_2 , 0x50 , V_64 & ( ~ 0xc0 ) ) ;
F_5 ( V_2 , 0x50 , & V_64 ) ;
if ( V_64 & 0xc0 )
F_6 ( & V_2 -> V_2 , L_63 , V_64 ) ;
else
F_6 ( & V_2 -> V_2 , L_64 ) ;
}
}
static void F_90 ( struct V_1 * V_68 )
{
T_2 V_132 , V_133 , V_100 ;
T_4 V_134 ;
if ( F_91 ( V_68 -> V_75 ) )
return;
F_10 ( V_68 , 0x40 , & V_132 ) ;
F_10 ( V_68 , 0x80 , & V_133 ) ;
V_132 &= ~ 0x00CFF302 ;
V_133 &= ~ ( 1 << 24 ) ;
switch ( V_68 -> V_83 ) {
case V_135 :
case V_136 :
case V_137 :
V_132 |= 0x0002A100 ;
break;
case V_138 :
case V_139 :
V_133 |= ( 1 << 24 ) ;
case V_140 :
case V_141 :
case V_142 :
V_132 |= 0x00C2A1B3 ;
break;
case V_143 :
V_132 |= 0x00C00000 ;
break;
}
F_63 ( V_68 , 0x40 , V_132 ) ;
F_63 ( V_68 , 0x80 , V_133 ) ;
F_5 ( V_68 , V_144 , & V_134 ) ;
V_68 -> V_145 = V_134 & 0x7f ;
V_68 -> V_146 = ! ! ( V_134 & 0x80 ) ;
F_10 ( V_68 , V_147 , & V_100 ) ;
V_68 -> V_100 = V_100 >> 8 ;
}
static void T_5 F_92 ( struct V_1 * V_68 )
{
int V_148 ;
if ( ( V_68 -> V_100 >> 8 ) != 0xff00 )
return;
if ( F_93 ( V_68 , 0 ) && F_25 ( V_68 , 0 ) )
F_94 ( & V_149 , & V_68 -> V_29 [ 0 ] ) ;
for ( V_148 = 1 ; V_148 < 6 ; V_148 ++ ) {
memset ( & V_68 -> V_29 [ V_148 ] , 0 , sizeof( V_68 -> V_29 [ V_148 ] ) ) ;
}
}
static void T_1 F_95 ( struct V_1 * V_68 )
{
F_96 ( V_68 ) ;
V_68 -> V_150 = 1 ;
}
static void T_1 F_97 ( struct V_1 * V_2 )
{
F_96 ( V_2 ) ;
V_2 -> V_150 = 1 ;
F_47 ( & V_2 -> V_2 , L_65 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
V_151 = 120 ;
V_2 -> V_152 = 1 ;
}
static void F_99 ( struct V_1 * V_2 )
{
if ( V_153 || V_154 )
return;
V_2 -> V_155 = V_156 ;
F_6 ( & V_2 -> V_2 , L_66 ,
V_2 -> V_157 , V_2 -> V_83 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
T_3 V_158 ;
if ( V_153 )
return;
F_33 ( V_2 , V_159 , & V_158 ) ;
V_158 |= V_160 ;
F_49 ( V_2 , V_159 , V_158 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_157 , V_2 -> V_83 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
T_2 V_161 ;
T_4 V_82 ;
if ( V_153 )
return;
F_10 ( V_2 , V_162 , & V_161 ) ;
F_63 ( V_2 , V_162 , V_161 |
V_163 ) ;
for ( V_82 = 0x10 ; V_82 < 0x10 + 32 ; V_82 ++ ) {
F_102 ( V_82 , V_164 ) ;
F_102 ( 0x00 , V_165 ) ;
}
F_63 ( V_2 , V_162 , V_161 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_157 , V_2 -> V_83 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
T_2 V_161 ;
if ( V_153 )
return;
if ( ( V_2 -> V_22 == V_166 ) ||
( V_2 -> V_22 == V_167 ) )
return;
F_10 ( V_2 , V_168 , & V_161 ) ;
V_161 &= ~ V_169 ;
F_63 ( V_2 , V_168 , V_161 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_157 , V_2 -> V_83 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
T_3 V_158 ;
if ( V_153 )
return;
F_33 ( V_2 , V_170 , & V_158 ) ;
if ( ! V_158 ) {
F_6 ( & V_2 -> V_2 , L_68
L_69 , V_2 -> V_157 , V_2 -> V_83 ) ;
return;
}
F_49 ( V_2 , V_170 , 0 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_157 , V_2 -> V_83 ) ;
}
static void T_5 F_105 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_29 [ 0 ] ;
if ( V_30 -> V_31 & 0x8 ) {
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0xf ;
}
}
static void T_1 F_106 ( struct V_1 * V_2 )
{
unsigned int V_171 = ( V_2 -> V_110 & 0xf0 ) >> 4 ;
unsigned int V_172 = V_2 -> V_110 & 0xf ;
switch ( V_2 -> V_83 ) {
case V_173 :
if ( V_2 -> V_107 == V_174 &&
V_2 -> V_110 == 0x0299 )
return;
case V_175 :
case V_176 :
case V_177 :
case V_178 :
if ( V_171 ) {
F_6 ( & V_2 -> V_2 , L_70
L_71
L_72 ,
V_2 -> V_83 , V_171 , V_172 ) ;
V_2 -> V_100 = ( V_179 << 8 ) |
( V_2 -> V_100 & 0xff ) ;
}
}
}
static void T_1 F_107 ( struct V_1 * V_2 )
{
T_3 V_69 , V_180 ;
T_4 T_6 * V_181 ;
T_4 V_182 ;
int V_67 ;
switch ( V_2 -> V_83 ) {
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
F_33 ( V_2 , V_70 , & V_69 ) ;
if ( ! ( V_69 & V_183 ) || ! F_93 ( V_2 , 0 ) )
return;
V_67 = F_108 ( V_2 , V_184 ) ;
if ( V_67 ) {
F_33 ( V_2 , V_67 + V_185 , & V_180 ) ;
if ( ( V_180 & V_186 ) != V_187 )
return;
}
V_181 = F_109 ( F_93 ( V_2 , 0 ) , 8 ) ;
if ( ! V_181 ) {
F_47 ( & V_2 -> V_2 , L_73 ) ;
return;
}
V_182 = F_110 ( V_181 + 3 ) ;
if ( V_182 == 0 ) {
F_47 ( & V_2 -> V_2 , L_74
L_75 ) ;
F_111 ( 1 , V_181 + 3 ) ;
}
F_85 ( V_181 ) ;
}
static void T_1 F_112 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_76 ) ;
F_113 ( V_2 , V_188 ) ;
}
static void T_1 F_114 ( struct V_1 * V_2 )
{
if ( V_2 -> V_100 == V_189 ) {
F_6 ( & V_2 -> V_2 , L_77 ) ;
V_2 -> V_100 = V_190 ;
}
}
static void T_1 F_115 ( struct V_1 * V_2 )
{
T_3 V_191 ;
T_4 V_192 , V_193 ;
unsigned long V_47 , V_194 ;
struct V_29 * V_33 = V_2 -> V_29 + V_42 ;
F_33 ( V_2 , 0x40 , & V_191 ) ;
if ( V_191 & 0x200 ) {
F_6 ( & V_2 -> V_2 , L_78 ) ;
F_5 ( V_2 , V_195 , & V_192 ) ;
F_5 ( V_2 , V_196 , & V_193 ) ;
V_47 = ( V_192 & ( V_197 | 0x0c ) ) << 8 ;
V_194 = ( V_193 & ( V_197 | 0x0c ) ) << 8 ;
if ( V_47 <= V_194 ) {
V_33 -> V_31 = V_47 ;
V_33 -> V_32 = V_194 + 0x3ff ;
}
}
}
static void T_1 F_116 ( struct V_1 * V_2 )
{
T_3 V_191 , V_198 , V_199 ;
struct V_29 * V_33 = V_2 -> V_29 + V_42 ;
F_33 ( V_2 , 0x40 , & V_191 ) ;
if ( V_191 & 0x200 ) {
F_33 ( V_2 , V_195 , & V_198 ) ;
V_199 = V_198 | ( V_33 -> V_31 >> 8 ) | ( V_33 -> V_32 & 0xfc00 ) ;
if ( V_198 != V_199 ) {
F_6 ( & V_2 -> V_2 , L_79 ,
V_198 , V_199 ) ;
F_49 ( V_2 , V_195 , V_199 ) ;
}
}
}
static void F_117 ( struct V_1 * V_2 )
{
T_7 V_200 ;
if ( F_5 ( V_2 , 0xf41 , & V_200 ) == 0 ) {
if ( ! ( V_200 & 0x20 ) ) {
F_7 ( V_2 , 0xf41 , V_200 | 0x20 ) ;
F_6 ( & V_2 -> V_2 ,
L_80 ) ;
}
}
}
static void T_1 F_118 ( struct V_1 * V_2 )
{
struct V_1 * V_18 = F_4 ( V_20 ,
V_201 , NULL ) ;
T_7 V_200 ;
V_18 = F_4 ( V_20 , V_201 , V_18 ) ;
if ( ! V_18 )
return;
F_17 ( V_18 ) ;
if ( F_5 ( V_2 , 0x76 , & V_200 ) == 0 ) {
if ( V_200 & 0x40 ) {
F_7 ( V_2 , 0x76 , V_200 ^ 0x40 ) ;
F_6 ( & V_2 -> V_2 ,
L_81 ) ;
}
}
if ( F_5 ( V_2 , 0x72 , & V_200 ) == 0 ) {
if ( V_200 != 0 ) {
F_7 ( V_2 , 0x72 , 0x0 ) ;
F_7 ( V_2 , 0x75 , 0x1 ) ;
F_7 ( V_2 , 0x77 , 0x0 ) ;
F_6 ( & V_2 -> V_2 ,
L_82 ) ;
}
}
}
static void T_1 F_119 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_83 == V_202 ) ||
( V_2 -> V_83 == V_203 ) ||
( V_2 -> V_83 == V_204 ) ||
( V_2 -> V_83 == V_205 ) ||
( ( V_2 -> V_83 == V_206 ) &&
( V_2 -> V_22 & 0xf0 ) == 0x0 ) ) {
if ( V_2 -> V_207 )
V_2 -> V_207 -> V_208 = 0x80 ;
}
}
static void T_1 F_120 ( struct V_1 * V_2 )
{
T_2 V_15 ;
F_10 ( V_2 , 0xf4 , & V_15 ) ;
if ( V_15 == 0x05719000 ) {
int V_209 = F_121 ( V_2 ) ;
if ( V_209 > 2048 )
F_122 ( V_2 , 2048 ) ;
}
}
static void T_1 F_123 ( struct V_1 * V_2 )
{
T_4 V_62 ;
if ( F_5 ( V_2 , 0xF4 , & V_62 ) == 0 && ! ( V_62 & 0x02 ) ) {
F_6 ( & V_2 -> V_2 , L_83 ) ;
F_7 ( V_2 , 0xF4 , V_62 | 0x02 ) ;
}
}
static void T_1 F_124 ( struct V_1 * V_2 )
{
if ( V_210 ) {
F_63 ( V_2 , 0x98 , 0x1 ) ;
F_125 ( 50 ) ;
}
}
static void T_5 F_126 ( struct V_1 * V_2 )
{
F_127 () ;
F_47 ( & V_2 -> V_2 , L_84 ) ;
}
static void T_1 F_128 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 ) {
F_47 ( & V_2 -> V_2 , L_85
L_86 ) ;
V_2 -> V_79 -> V_80 |= V_211 ;
}
}
static void T_1 F_129 ( struct V_1 * V_212 )
{
struct V_1 * V_213 ;
V_213 = F_130 ( V_212 -> V_76 , F_131 ( 1 , 0 ) ) ;
if ( V_213 ) {
if ( V_213 -> V_83 == 0x9602 )
F_128 ( V_213 ) ;
F_17 ( V_213 ) ;
}
}
static int T_1 F_132 ( struct V_1 * V_2 )
{
int V_214 , V_215 = 48 ;
V_214 = F_133 ( V_2 , V_216 ) ;
while ( V_214 && V_215 -- ) {
T_4 V_40 ;
if ( F_5 ( V_2 , V_214 + V_217 ,
& V_40 ) == 0 )
{
F_6 ( & V_2 -> V_2 , L_87 ,
V_40 & V_218 ?
L_88 : L_89 ) ;
return ( V_40 & V_218 ) != 0 ;
}
V_214 = F_134 ( V_2 , V_214 ,
V_216 ) ;
}
return 0 ;
}
static void T_1 F_135 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 && ! F_132 ( V_2 ) ) {
F_47 ( & V_2 -> V_2 , L_85
L_86 ) ;
V_2 -> V_79 -> V_80 |= V_211 ;
}
}
static void T_1 F_136 ( struct V_1 * V_2 )
{
struct V_1 * V_68 ;
if ( ! V_2 -> V_79 )
return;
V_68 = F_130 ( V_2 -> V_76 , 0 ) ;
if ( ! V_68 )
return;
if ( ! F_132 ( V_2 ) && ! F_132 ( V_68 ) ) {
F_47 ( & V_2 -> V_2 , L_85
L_86 ) ;
V_2 -> V_79 -> V_80 |= V_211 ;
}
F_17 ( V_68 ) ;
}
static void T_1 F_137 ( struct V_1 * V_2 )
{
int V_214 , V_215 = 48 ;
V_214 = F_133 ( V_2 , V_216 ) ;
while ( V_214 && V_215 -- ) {
T_4 V_40 ;
if ( F_5 ( V_2 , V_214 + V_217 ,
& V_40 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_90 ) ;
F_7 ( V_2 , V_214 + V_217 ,
V_40 | V_218 ) ;
}
V_214 = F_134 ( V_2 , V_214 ,
V_216 ) ;
}
}
static void T_1 F_138 ( struct V_1 * V_2 )
{
const char * V_219 = F_139 ( V_220 ) ;
if ( V_219 &&
( strstr ( V_219 , L_91 ) ||
strstr ( V_219 , L_92 ) ) ) {
F_6 ( & V_2 -> V_2 ,
L_93 ) ;
V_2 -> V_150 = 1 ;
}
}
static void T_1 F_140 ( struct V_1 * V_2 )
{
T_2 V_221 ;
if ( ! F_108 ( V_2 , V_222 ) )
return;
F_10 ( V_2 , 0x74 , & V_221 ) ;
if ( V_221 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_141 ( V_223 L_94 ) ;
V_221 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_63 ( V_2 , 0x74 , V_221 ) ;
}
}
static int T_1 F_142 ( struct V_1 * V_2 )
{
int V_214 , V_215 = 48 ;
int V_224 = 0 ;
V_214 = F_133 ( V_2 , V_216 ) ;
while ( V_214 && V_215 -- ) {
T_4 V_40 ;
if ( V_224 < 1 )
V_224 = 1 ;
if ( F_5 ( V_2 , V_214 + V_217 ,
& V_40 ) == 0 ) {
if ( V_40 & V_218 ) {
if ( V_224 < 2 ) {
V_224 = 2 ;
break;
}
}
}
V_214 = F_134 ( V_2 , V_214 ,
V_216 ) ;
}
return V_224 ;
}
static int T_1 F_143 ( struct V_1 * V_212 )
{
struct V_1 * V_2 ;
int V_214 ;
int V_148 , V_225 ;
int V_224 = 0 ;
V_225 = V_212 -> V_75 >> 3 ;
for ( V_148 = V_225 + 1 ; V_148 < 0x20 ; V_148 ++ ) {
V_2 = F_130 ( V_212 -> V_76 , F_131 ( V_148 , 0 ) ) ;
if ( ! V_2 )
continue;
V_214 = F_133 ( V_2 , V_226 ) ;
if ( V_214 != 0 ) {
F_17 ( V_2 ) ;
break;
}
if ( F_142 ( V_2 ) ) {
V_224 = 1 ;
F_17 ( V_2 ) ;
break;
}
F_17 ( V_2 ) ;
}
return V_224 ;
}
static int T_1 F_144 ( struct V_1 * V_2 )
{
int V_214 , V_227 ;
int V_32 = 0 ;
T_3 V_40 , V_228 ;
V_214 = F_133 ( V_2 , V_226 ) ;
if ( ! V_214 )
goto V_229;
F_33 ( V_2 , V_214 + V_230 , & V_40 ) ;
V_227 = ( ( V_40 >> 10 ) & 1 ) ?
V_231 : V_232 ;
F_33 ( V_2 , V_214 + V_227 , & V_228 ) ;
if ( V_228 & ( 1 << 6 ) )
V_32 = 1 ;
V_229:
return V_32 ;
}
static void T_1 F_145 ( struct V_1 * V_2 )
{
struct V_1 * V_212 ;
int V_214 ;
int V_148 , V_225 ;
int V_224 = 0 ;
V_225 = V_2 -> V_75 >> 3 ;
for ( V_148 = V_225 ; V_148 >= 0 ; V_148 -- ) {
V_212 = F_130 ( V_2 -> V_76 , F_131 ( V_148 , 0 ) ) ;
if ( ! V_212 )
continue;
V_214 = F_133 ( V_212 , V_226 ) ;
if ( V_214 != 0 ) {
V_224 = 1 ;
break;
}
F_17 ( V_212 ) ;
}
if ( ! V_224 )
return;
if ( V_212 == V_2 && F_144 ( V_212 ) &&
F_143 ( V_212 ) )
goto V_229;
if ( F_132 ( V_212 ) )
goto V_229;
F_137 ( V_2 ) ;
V_229:
F_17 ( V_212 ) ;
}
static void T_1 F_146 ( struct V_1 * V_2 )
{
int V_214 , V_215 = 48 ;
V_214 = F_133 ( V_2 , V_216 ) ;
while ( V_214 && V_215 -- ) {
T_4 V_40 ;
if ( F_5 ( V_2 , V_214 + V_217 ,
& V_40 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_95 ) ;
F_7 ( V_2 , V_214 + V_217 ,
V_40 & ~ V_218 ) ;
}
V_214 = F_134 ( V_2 , V_214 ,
V_216 ) ;
}
}
static void T_1 F_147 ( struct V_1 * V_2 , int V_233 )
{
struct V_1 * V_212 ;
int V_214 ;
int V_224 ;
if ( ! F_148 () )
return;
V_224 = F_142 ( V_2 ) ;
if ( V_224 == 0 )
return;
V_212 = F_149 ( 0 , F_131 ( 0 , 0 ) ) ;
if ( V_212 == NULL ) {
F_47 ( & V_2 -> V_2 ,
L_96 ) ;
return;
}
V_214 = F_133 ( V_212 , V_226 ) ;
if ( V_214 != 0 ) {
if ( V_224 == 1 ) {
if ( V_233 )
F_137 ( V_2 ) ;
else
F_145 ( V_2 ) ;
}
return;
}
if ( V_224 == 1 )
return;
F_146 ( V_2 ) ;
}
static void T_1 F_150 ( struct V_1 * V_2 )
{
return F_147 ( V_2 , 1 ) ;
}
static void T_1 F_151 ( struct V_1 * V_2 )
{
return F_147 ( V_2 , 0 ) ;
}
static void T_1 F_152 ( struct V_1 * V_2 )
{
V_2 -> V_104 |= V_234 ;
}
static void T_1 F_153 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( V_235 , V_236 ,
NULL ) ;
if ( ! V_18 )
return;
if ( ( V_18 -> V_22 < 0x3B ) && ( V_18 -> V_22 >= 0x30 ) )
V_2 -> V_104 |= V_234 ;
F_17 ( V_18 ) ;
}
static void T_1 F_154 ( struct V_1 * V_2 )
{
V_2 -> V_237 = 1 ;
}
static void F_155 ( struct V_1 * V_2 )
{
T_4 V_238 ;
T_4 V_239 ;
T_4 V_240 ;
if ( F_91 ( V_2 -> V_75 ) )
return;
F_5 ( V_2 , 0xB7 , & V_240 ) ;
if ( V_240 & 0x02 )
return;
F_5 ( V_2 , 0x8E , & V_238 ) ;
F_7 ( V_2 , 0x8E , 0xAA ) ;
F_5 ( V_2 , 0x8D , & V_239 ) ;
F_7 ( V_2 , 0x8D , 0xB7 ) ;
F_7 ( V_2 , 0xB7 , V_240 | 0x02 ) ;
F_7 ( V_2 , 0x8E , V_238 ) ;
F_7 ( V_2 , 0x8D , V_239 ) ;
F_156 ( & V_2 -> V_2 , L_97 ) ;
F_156 ( & V_2 -> V_2 , L_98 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
T_4 V_238 ;
T_4 V_240 ;
if ( F_91 ( V_2 -> V_75 ) )
return;
if ( V_2 -> V_83 == V_241 ) {
F_7 ( V_2 , 0xf9 , 0xfc ) ;
F_7 ( V_2 , 0x150 , 0x10 ) ;
F_7 ( V_2 , 0xf9 , 0x00 ) ;
F_7 ( V_2 , 0xfc , 0x01 ) ;
F_7 ( V_2 , 0xe1 , 0x32 ) ;
F_7 ( V_2 , 0xfc , 0x00 ) ;
F_156 ( & V_2 -> V_2 , L_99 ) ;
}
F_5 ( V_2 , 0xCB , & V_240 ) ;
if ( V_240 & 0x02 )
return;
F_5 ( V_2 , 0xCA , & V_238 ) ;
F_7 ( V_2 , 0xCA , 0x57 ) ;
F_7 ( V_2 , 0xCB , V_240 | 0x02 ) ;
F_7 ( V_2 , 0xCA , V_238 ) ;
F_156 ( & V_2 -> V_2 , L_100 ) ;
F_156 ( & V_2 -> V_2 , L_98 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
T_2 V_242 ;
F_10 ( V_2 , V_243 , & V_242 ) ;
F_63 ( V_2 , V_243 , V_242 | V_244 ) ;
}
static void T_1 F_159 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_101 ) ;
V_2 -> V_100 = V_245 ;
}
static void T_1 F_160 ( struct V_1 * V_2 )
{
V_2 -> V_246 = 1 ;
}
static void T_1 F_161 ( struct V_1 * V_2 )
{
int V_247 ;
T_3 V_248 ;
if ( V_249 == V_250 )
return;
V_247 = F_33 ( V_2 , 0x48 , & V_248 ) ;
if ( V_247 ) {
F_162 ( & V_2 -> V_2 , L_102
L_103 ) ;
return;
}
if ( ! ( V_248 & ( 1 << 10 ) ) )
return;
V_248 &= ~ ( 1 << 10 ) ;
V_247 = F_49 ( V_2 , 0x48 , V_248 ) ;
if ( V_247 ) {
F_162 ( & V_2 -> V_2 , L_104
L_103 ) ;
return;
}
F_163 ( L_105
L_106 ) ;
}
static void F_164 ( void (* F_165)( struct V_1 * V_2 ) , struct V_1 * V_2 )
{
T_8 V_251 , V_252 , V_253 ;
unsigned long long V_254 ;
F_141 ( V_255 L_107 ,
F_165 , F_166 ( V_256 ) , F_167 ( & V_2 -> V_2 ) ) ;
V_251 = F_168 () ;
F_165 ( V_2 ) ;
V_253 = F_168 () ;
V_252 = F_169 ( V_253 , V_251 ) ;
V_254 = ( unsigned long long ) F_170 ( V_252 ) >> 10 ;
F_141 ( V_255 L_108 ,
F_165 , V_254 , F_167 ( & V_2 -> V_2 ) ) ;
}
static void T_1 F_171 ( struct V_1 * V_2 )
{
void T_6 * V_257 = F_172 ( V_2 , 0 , 0 ) ;
if ( V_257 == NULL ) {
F_47 ( & V_2 -> V_2 , L_109 ) ;
return;
}
if ( F_82 ( V_257 + V_258 ) != 0 ) {
F_47 ( & V_2 -> V_2 , L_110
L_75 ) ;
F_83 ( 0 , V_257 + V_258 ) ;
}
F_173 ( V_2 , V_257 ) ;
}
static void F_174 ( struct V_1 * V_2 , struct V_259 * V_260 ,
struct V_259 * V_32 )
{
for (; V_260 < V_32 ; V_260 ++ )
if ( ( V_260 -> V_100 == ( T_2 ) ( V_2 -> V_100 >> V_260 -> V_261 ) ||
V_260 -> V_100 == ( T_2 ) V_262 ) &&
( V_260 -> V_157 == V_2 -> V_157 ||
V_260 -> V_157 == ( T_3 ) V_262 ) &&
( V_260 -> V_83 == V_2 -> V_83 ||
V_260 -> V_83 == ( T_3 ) V_262 ) ) {
F_175 ( & V_2 -> V_2 , L_111 , V_260 -> V_263 ) ;
if ( V_264 )
F_164 ( V_260 -> V_263 , V_2 ) ;
else
V_260 -> V_263 ( V_2 ) ;
}
}
void F_176 ( enum V_265 V_266 , struct V_1 * V_2 )
{
struct V_259 * V_31 , * V_32 ;
switch( V_266 ) {
case V_267 :
V_31 = V_268 ;
V_32 = V_269 ;
break;
case V_270 :
V_31 = V_271 ;
V_32 = V_272 ;
break;
case V_273 :
V_31 = V_274 ;
V_32 = V_275 ;
break;
case V_276 :
V_31 = V_277 ;
V_32 = V_278 ;
break;
case V_279 :
V_31 = V_280 ;
V_32 = V_281 ;
break;
case V_282 :
V_31 = V_283 ;
V_32 = V_284 ;
break;
case V_285 :
V_31 = V_286 ;
V_32 = V_287 ;
break;
default:
return;
}
F_174 ( V_2 , V_31 , V_32 ) ;
}
static int T_5 F_177 ( void )
{
struct V_1 * V_2 = NULL ;
T_4 V_288 = 0 ;
T_4 V_72 ;
if ( V_289 )
F_141 ( V_255 L_112 ,
V_289 << 2 ) ;
F_178 (dev) {
F_176 ( V_273 , V_2 ) ;
if ( ! V_289 ) {
F_5 ( V_2 , V_290 , & V_72 ) ;
if ( ! V_288 )
V_288 = V_72 ;
if ( ! V_72 || V_288 == V_72 )
continue;
F_141 ( V_255 L_113
L_114 , V_288 << 2 , V_72 << 2 ,
V_291 << 2 ) ;
V_289 = V_291 ;
}
}
if ( ! V_289 ) {
F_141 ( V_255 L_115 ,
V_288 << 2 , V_291 << 2 ) ;
V_289 = V_288 ? V_288 : V_291 ;
}
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , int V_292 )
{
int V_214 ;
if ( V_2 -> V_100 == V_293 ) {
V_214 = F_108 ( V_2 , V_294 ) ;
if ( ! V_214 )
return - V_295 ;
if ( V_292 )
return 0 ;
F_7 ( V_2 , V_214 + 0x4 , 1 ) ;
F_180 ( 100 ) ;
return 0 ;
} else {
return - V_295 ;
}
}
static int F_181 ( struct V_1 * V_2 , int V_292 )
{
int V_214 ;
V_214 = F_108 ( V_2 , V_296 ) ;
if ( ! V_214 )
return - V_295 ;
if ( V_292 )
return 0 ;
F_49 ( V_2 , V_214 + V_297 ,
V_298 ) ;
F_180 ( 100 ) ;
return 0 ;
}
int F_182 ( struct V_1 * V_2 , int V_292 )
{
const struct V_299 * V_148 ;
for ( V_148 = V_299 ; V_148 -> V_300 ; V_148 ++ ) {
if ( ( V_148 -> V_157 == V_2 -> V_157 ||
V_148 -> V_157 == ( T_3 ) V_262 ) &&
( V_148 -> V_83 == V_2 -> V_83 ||
V_148 -> V_83 == ( T_3 ) V_262 ) )
return V_148 -> V_300 ( V_2 , V_292 ) ;
}
return - V_295 ;
}
