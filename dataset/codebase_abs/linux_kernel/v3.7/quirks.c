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
static void T_1 F_20 ( struct V_1 * V_2 )
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
static void T_1 F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 == 0 && V_2 -> V_76 -> V_77 == 0 )
V_78 = 1 ;
}
static void T_1 F_55 ( struct V_1 * V_2 )
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
static void F_69 ( struct V_1 * V_68 )
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
static void T_1 F_71 ( struct V_1 * V_68 )
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
static void T_1 F_73 ( struct V_1 * V_2 )
{
V_2 -> V_100 = V_106 << 8 ;
}
static void T_1 F_74 ( struct V_1 * V_2 )
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
static void T_1 F_92 ( struct V_1 * V_68 )
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
static void T_1 F_105 ( struct V_1 * V_2 )
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
T_4 T_5 * V_181 ;
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
F_33 ( V_2 , 0x40 , & V_191 ) ;
if ( V_191 & 0x200 ) {
F_6 ( & V_2 -> V_2 , L_78 ) ;
V_2 -> V_192 = 1 ;
}
}
static void F_116 ( struct V_1 * V_2 )
{
T_6 V_193 ;
if ( F_5 ( V_2 , 0xf41 , & V_193 ) == 0 ) {
if ( ! ( V_193 & 0x20 ) ) {
F_7 ( V_2 , 0xf41 , V_193 | 0x20 ) ;
F_6 ( & V_2 -> V_2 ,
L_79 ) ;
}
}
}
static void T_1 F_117 ( struct V_1 * V_2 )
{
struct V_1 * V_18 = F_4 ( V_20 ,
V_194 , NULL ) ;
T_6 V_193 ;
V_18 = F_4 ( V_20 , V_194 , V_18 ) ;
if ( ! V_18 )
return;
F_17 ( V_18 ) ;
if ( F_5 ( V_2 , 0x76 , & V_193 ) == 0 ) {
if ( V_193 & 0x40 ) {
F_7 ( V_2 , 0x76 , V_193 ^ 0x40 ) ;
F_6 ( & V_2 -> V_2 ,
L_80 ) ;
}
}
if ( F_5 ( V_2 , 0x72 , & V_193 ) == 0 ) {
if ( V_193 != 0 ) {
F_7 ( V_2 , 0x72 , 0x0 ) ;
F_7 ( V_2 , 0x75 , 0x1 ) ;
F_7 ( V_2 , 0x77 , 0x0 ) ;
F_6 ( & V_2 -> V_2 ,
L_81 ) ;
}
}
}
static void T_1 F_118 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_83 == V_195 ) ||
( V_2 -> V_83 == V_196 ) ||
( V_2 -> V_83 == V_197 ) ||
( V_2 -> V_83 == V_198 ) ||
( ( V_2 -> V_83 == V_199 ) &&
( V_2 -> V_22 & 0xf0 ) == 0x0 ) ) {
if ( V_2 -> V_200 )
V_2 -> V_200 -> V_201 = 0x80 ;
}
}
static void F_119 ( struct V_1 * V_2 )
{
T_2 V_15 ;
F_10 ( V_2 , 0xf4 , & V_15 ) ;
if ( V_15 == 0x05719000 ) {
int V_202 = F_120 ( V_2 ) ;
if ( V_202 > 2048 )
F_121 ( V_2 , 2048 ) ;
}
}
static void T_1 F_122 ( struct V_1 * V_2 )
{
T_4 V_62 ;
if ( F_5 ( V_2 , 0xF4 , & V_62 ) == 0 && ! ( V_62 & 0x02 ) ) {
F_6 ( & V_2 -> V_2 , L_82 ) ;
F_7 ( V_2 , 0xF4 , V_62 | 0x02 ) ;
}
}
static void T_1 F_123 ( struct V_1 * V_2 )
{
if ( V_203 ) {
F_63 ( V_2 , 0x98 , 0x1 ) ;
F_124 ( 50 ) ;
}
}
static void T_1 F_125 ( struct V_1 * V_2 )
{
F_126 () ;
F_47 ( & V_2 -> V_2 , L_83 ) ;
}
static void T_1 F_127 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 ) {
F_47 ( & V_2 -> V_2 , L_84
L_85 ) ;
V_2 -> V_79 -> V_80 |= V_204 ;
}
}
static void T_1 F_128 ( struct V_1 * V_205 )
{
struct V_1 * V_206 ;
V_206 = F_129 ( V_205 -> V_76 , F_130 ( 1 , 0 ) ) ;
if ( V_206 ) {
if ( V_206 -> V_83 == 0x9602 )
F_127 ( V_206 ) ;
F_17 ( V_206 ) ;
}
}
static int F_131 ( struct V_1 * V_2 )
{
int V_207 , V_208 = 48 ;
V_207 = F_132 ( V_2 , V_209 ) ;
while ( V_207 && V_208 -- ) {
T_4 V_40 ;
if ( F_5 ( V_2 , V_207 + V_210 ,
& V_40 ) == 0 )
{
F_6 ( & V_2 -> V_2 , L_86 ,
V_40 & V_211 ?
L_87 : L_88 ) ;
return ( V_40 & V_211 ) != 0 ;
}
V_207 = F_133 ( V_2 , V_207 ,
V_209 ) ;
}
return 0 ;
}
static void F_134 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 && ! F_131 ( V_2 ) ) {
F_47 ( & V_2 -> V_2 , L_84
L_85 ) ;
V_2 -> V_79 -> V_80 |= V_204 ;
}
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_1 * V_68 ;
if ( ! V_2 -> V_79 )
return;
V_68 = F_129 ( V_2 -> V_76 , 0 ) ;
if ( ! V_68 )
return;
if ( ! F_131 ( V_2 ) && ! F_131 ( V_68 ) ) {
F_47 ( & V_2 -> V_2 , L_84
L_85 ) ;
V_2 -> V_79 -> V_80 |= V_204 ;
}
F_17 ( V_68 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
int V_207 , V_208 = 48 ;
V_207 = F_132 ( V_2 , V_209 ) ;
while ( V_207 && V_208 -- ) {
T_4 V_40 ;
if ( F_5 ( V_2 , V_207 + V_210 ,
& V_40 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_89 ) ;
F_7 ( V_2 , V_207 + V_210 ,
V_40 | V_211 ) ;
}
V_207 = F_133 ( V_2 , V_207 ,
V_209 ) ;
}
}
static void T_1 F_137 ( struct V_1 * V_2 )
{
const char * V_212 = F_138 ( V_213 ) ;
if ( V_212 &&
( strstr ( V_212 , L_90 ) ||
strstr ( V_212 , L_91 ) ) ) {
F_6 ( & V_2 -> V_2 ,
L_92 ) ;
V_2 -> V_150 = 1 ;
}
}
static void T_1 F_139 ( struct V_1 * V_2 )
{
T_2 V_214 ;
if ( ! F_108 ( V_2 , V_215 ) )
return;
F_10 ( V_2 , 0x74 , & V_214 ) ;
if ( V_214 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_140 ( V_216 L_93 ) ;
V_214 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_63 ( V_2 , 0x74 , V_214 ) ;
}
}
static int F_141 ( struct V_1 * V_2 )
{
int V_207 , V_208 = 48 ;
int V_217 = 0 ;
V_207 = F_132 ( V_2 , V_209 ) ;
while ( V_207 && V_208 -- ) {
T_4 V_40 ;
if ( V_217 < 1 )
V_217 = 1 ;
if ( F_5 ( V_2 , V_207 + V_210 ,
& V_40 ) == 0 ) {
if ( V_40 & V_211 ) {
if ( V_217 < 2 ) {
V_217 = 2 ;
break;
}
}
}
V_207 = F_133 ( V_2 , V_207 ,
V_209 ) ;
}
return V_217 ;
}
static int F_142 ( struct V_1 * V_205 )
{
struct V_1 * V_2 ;
int V_207 ;
int V_148 , V_218 ;
int V_217 = 0 ;
V_218 = V_205 -> V_75 >> 3 ;
for ( V_148 = V_218 + 1 ; V_148 < 0x20 ; V_148 ++ ) {
V_2 = F_129 ( V_205 -> V_76 , F_130 ( V_148 , 0 ) ) ;
if ( ! V_2 )
continue;
V_207 = F_132 ( V_2 , V_219 ) ;
if ( V_207 != 0 ) {
F_17 ( V_2 ) ;
break;
}
if ( F_141 ( V_2 ) ) {
V_217 = 1 ;
F_17 ( V_2 ) ;
break;
}
F_17 ( V_2 ) ;
}
return V_217 ;
}
static int F_143 ( struct V_1 * V_2 )
{
int V_207 , V_220 ;
int V_32 = 0 ;
T_3 V_40 , V_221 ;
V_207 = F_132 ( V_2 , V_219 ) ;
if ( ! V_207 )
goto V_222;
F_33 ( V_2 , V_207 + V_223 , & V_40 ) ;
V_220 = ( ( V_40 >> 10 ) & 1 ) ?
V_224 : V_225 ;
F_33 ( V_2 , V_207 + V_220 , & V_221 ) ;
if ( V_221 & ( 1 << 6 ) )
V_32 = 1 ;
V_222:
return V_32 ;
}
static void F_144 ( struct V_1 * V_2 )
{
struct V_1 * V_205 ;
int V_207 ;
int V_148 , V_218 ;
int V_217 = 0 ;
V_218 = V_2 -> V_75 >> 3 ;
for ( V_148 = V_218 ; V_148 >= 0 ; V_148 -- ) {
V_205 = F_129 ( V_2 -> V_76 , F_130 ( V_148 , 0 ) ) ;
if ( ! V_205 )
continue;
V_207 = F_132 ( V_205 , V_219 ) ;
if ( V_207 != 0 ) {
V_217 = 1 ;
break;
}
F_17 ( V_205 ) ;
}
if ( ! V_217 )
return;
if ( V_205 == V_2 && F_143 ( V_205 ) &&
F_142 ( V_205 ) )
goto V_222;
if ( F_131 ( V_205 ) )
goto V_222;
F_136 ( V_2 ) ;
V_222:
F_17 ( V_205 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
int V_207 , V_208 = 48 ;
V_207 = F_132 ( V_2 , V_209 ) ;
while ( V_207 && V_208 -- ) {
T_4 V_40 ;
if ( F_5 ( V_2 , V_207 + V_210 ,
& V_40 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_94 ) ;
F_7 ( V_2 , V_207 + V_210 ,
V_40 & ~ V_211 ) ;
}
V_207 = F_133 ( V_2 , V_207 ,
V_209 ) ;
}
}
static void F_146 ( struct V_1 * V_2 , int V_226 )
{
struct V_1 * V_205 ;
int V_207 ;
int V_217 ;
if ( ! F_147 () )
return;
V_217 = F_141 ( V_2 ) ;
if ( V_217 == 0 )
return;
V_205 = F_148 ( 0 , F_130 ( 0 , 0 ) ) ;
if ( V_205 == NULL ) {
F_47 ( & V_2 -> V_2 ,
L_95 ) ;
return;
}
V_207 = F_132 ( V_205 , V_219 ) ;
if ( V_207 != 0 ) {
if ( V_217 == 1 ) {
if ( V_226 )
F_136 ( V_2 ) ;
else
F_144 ( V_2 ) ;
}
goto V_222;
}
if ( V_217 == 1 )
goto V_222;
F_145 ( V_2 ) ;
V_222:
F_17 ( V_205 ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
return F_146 ( V_2 , 1 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
return F_146 ( V_2 , 0 ) ;
}
static void T_1 F_151 ( struct V_1 * V_2 )
{
V_2 -> V_104 |= V_227 ;
}
static void T_1 F_152 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( V_228 , V_229 ,
NULL ) ;
if ( ! V_18 )
return;
if ( ( V_18 -> V_22 < 0x3B ) && ( V_18 -> V_22 >= 0x30 ) )
V_2 -> V_104 |= V_227 ;
F_17 ( V_18 ) ;
}
static void T_1 F_153 ( struct V_1 * V_2 )
{
V_2 -> V_230 = 1 ;
}
static void F_154 ( struct V_1 * V_2 )
{
T_4 V_231 ;
T_4 V_232 ;
T_4 V_233 ;
if ( F_91 ( V_2 -> V_75 ) )
return;
F_5 ( V_2 , 0xB7 , & V_233 ) ;
if ( V_233 & 0x02 )
return;
F_5 ( V_2 , 0x8E , & V_231 ) ;
F_7 ( V_2 , 0x8E , 0xAA ) ;
F_5 ( V_2 , 0x8D , & V_232 ) ;
F_7 ( V_2 , 0x8D , 0xB7 ) ;
F_7 ( V_2 , 0xB7 , V_233 | 0x02 ) ;
F_7 ( V_2 , 0x8E , V_231 ) ;
F_7 ( V_2 , 0x8D , V_232 ) ;
F_155 ( & V_2 -> V_2 , L_96 ) ;
F_155 ( & V_2 -> V_2 , L_97 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
T_4 V_231 ;
T_4 V_233 ;
if ( F_91 ( V_2 -> V_75 ) )
return;
if ( V_2 -> V_83 == V_234 ) {
F_7 ( V_2 , 0xf9 , 0xfc ) ;
F_7 ( V_2 , 0x150 , 0x10 ) ;
F_7 ( V_2 , 0xf9 , 0x00 ) ;
F_7 ( V_2 , 0xfc , 0x01 ) ;
F_7 ( V_2 , 0xe1 , 0x32 ) ;
F_7 ( V_2 , 0xfc , 0x00 ) ;
F_155 ( & V_2 -> V_2 , L_98 ) ;
}
F_5 ( V_2 , 0xCB , & V_233 ) ;
if ( V_233 & 0x02 )
return;
F_5 ( V_2 , 0xCA , & V_231 ) ;
F_7 ( V_2 , 0xCA , 0x57 ) ;
F_7 ( V_2 , 0xCB , V_233 | 0x02 ) ;
F_7 ( V_2 , 0xCA , V_231 ) ;
F_155 ( & V_2 -> V_2 , L_99 ) ;
F_155 ( & V_2 -> V_2 , L_97 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
T_2 V_235 ;
F_10 ( V_2 , V_236 , & V_235 ) ;
F_63 ( V_2 , V_236 , V_235 | V_237 ) ;
}
static void T_1 F_158 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_100 ) ;
V_2 -> V_100 = V_238 ;
}
static void T_1 F_159 ( struct V_1 * V_2 )
{
V_2 -> V_239 = 1 ;
}
static void T_1 F_160 ( struct V_1 * V_2 )
{
int V_240 ;
T_3 V_241 ;
if ( V_242 == V_243 )
return;
V_240 = F_33 ( V_2 , 0x48 , & V_241 ) ;
if ( V_240 ) {
F_161 ( & V_2 -> V_2 , L_101
L_102 ) ;
return;
}
if ( ! ( V_241 & ( 1 << 10 ) ) )
return;
V_241 &= ~ ( 1 << 10 ) ;
V_240 = F_49 ( V_2 , 0x48 , V_241 ) ;
if ( V_240 ) {
F_161 ( & V_2 -> V_2 , L_103
L_102 ) ;
return;
}
F_162 ( L_104
L_105 ) ;
}
static T_7 F_163 ( struct V_1 * V_2 ,
void (* F_164)( struct V_1 * V_2 ) )
{
T_7 V_244 = F_165 ( 0 , 0 ) ;
F_166 ( & V_2 -> V_2 , L_106 , F_164 ) ;
if ( V_245 ) {
F_167 ( L_107 ,
F_164 , F_168 ( V_246 ) , F_169 ( & V_2 -> V_2 ) ) ;
V_244 = F_170 () ;
}
return V_244 ;
}
static void F_171 ( struct V_1 * V_2 , T_7 V_244 ,
void (* F_164)( struct V_1 * V_2 ) )
{
T_7 V_247 , V_248 ;
unsigned long long V_249 ;
if ( V_245 ) {
V_248 = F_170 () ;
V_247 = F_172 ( V_248 , V_244 ) ;
V_249 = ( unsigned long long ) F_173 ( V_247 ) >> 10 ;
F_167 ( L_108 ,
F_164 , V_249 , F_169 ( & V_2 -> V_2 ) ) ;
}
}
static void T_1 F_174 ( struct V_1 * V_2 )
{
void T_5 * V_250 = F_175 ( V_2 , 0 , 0 ) ;
if ( V_250 == NULL ) {
F_47 ( & V_2 -> V_2 , L_109 ) ;
return;
}
if ( F_82 ( V_250 + V_251 ) != 0 ) {
F_47 ( & V_2 -> V_2 , L_110
L_75 ) ;
F_83 ( 0 , V_250 + V_251 ) ;
}
F_176 ( V_2 , V_250 ) ;
}
static void T_1 F_177 ( struct V_1 * V_2 )
{
V_2 -> V_252 = 1 ;
}
static void F_178 ( struct V_1 * V_2 , struct V_253 * V_254 ,
struct V_253 * V_32 )
{
T_7 V_244 ;
for (; V_254 < V_32 ; V_254 ++ )
if ( ( V_254 -> V_100 == ( T_2 ) ( V_2 -> V_100 >> V_254 -> V_255 ) ||
V_254 -> V_100 == ( T_2 ) V_256 ) &&
( V_254 -> V_157 == V_2 -> V_157 ||
V_254 -> V_157 == ( T_3 ) V_256 ) &&
( V_254 -> V_83 == V_2 -> V_83 ||
V_254 -> V_83 == ( T_3 ) V_256 ) ) {
V_244 = F_163 ( V_2 , V_254 -> V_257 ) ;
V_254 -> V_257 ( V_2 ) ;
F_171 ( V_2 , V_244 , V_254 -> V_257 ) ;
}
}
void F_179 ( enum V_258 V_259 , struct V_1 * V_2 )
{
struct V_253 * V_31 , * V_32 ;
switch( V_259 ) {
case V_260 :
V_31 = V_261 ;
V_32 = V_262 ;
break;
case V_263 :
V_31 = V_264 ;
V_32 = V_265 ;
break;
case V_266 :
if ( ! V_267 )
return;
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
default:
return;
}
F_178 ( V_2 , V_31 , V_32 ) ;
}
static int T_8 F_180 ( void )
{
struct V_1 * V_2 = NULL ;
T_4 V_282 = 0 ;
T_4 V_72 ;
if ( V_283 )
F_140 ( V_284 L_111 ,
V_283 << 2 ) ;
V_267 = true ;
F_181 (dev) {
F_179 ( V_266 , V_2 ) ;
if ( ! V_283 ) {
F_5 ( V_2 , V_285 , & V_72 ) ;
if ( ! V_282 )
V_282 = V_72 ;
if ( ! V_72 || V_282 == V_72 )
continue;
F_140 ( V_284 L_112
L_113 , V_282 << 2 , V_72 << 2 ,
V_286 << 2 ) ;
V_283 = V_286 ;
}
}
if ( ! V_283 ) {
F_140 ( V_284 L_114 ,
V_282 << 2 , V_286 << 2 ) ;
V_283 = V_282 ? V_282 : V_286 ;
}
return 0 ;
}
static int F_182 ( struct V_1 * V_2 , int V_287 )
{
int V_207 ;
if ( V_2 -> V_100 == V_288 ) {
V_207 = F_108 ( V_2 , V_289 ) ;
if ( ! V_207 )
return - V_290 ;
if ( V_287 )
return 0 ;
F_7 ( V_2 , V_207 + 0x4 , 1 ) ;
F_183 ( 100 ) ;
return 0 ;
} else {
return - V_290 ;
}
}
static int F_184 ( struct V_1 * V_2 , int V_287 )
{
int V_148 ;
T_3 V_291 ;
if ( V_287 )
return 0 ;
for ( V_148 = 0 ; V_148 < 4 ; V_148 ++ ) {
if ( V_148 )
F_183 ( ( 1 << ( V_148 - 1 ) ) * 100 ) ;
F_185 ( V_2 , V_292 , & V_291 ) ;
if ( ! ( V_291 & V_293 ) )
goto V_294;
}
F_161 ( & V_2 -> V_2 , L_115
L_116 ) ;
V_294:
F_186 ( V_2 , V_295 , V_296 ) ;
F_183 ( 100 ) ;
return 0 ;
}
static int F_187 ( struct V_1 * V_2 , int V_287 )
{
void T_5 * V_297 ;
unsigned long V_298 ;
T_2 V_64 ;
if ( V_287 )
return 0 ;
V_297 = F_175 ( V_2 , 0 , 0 ) ;
if ( ! V_297 )
return - V_299 ;
F_188 ( 0x00000002 , V_297 + V_300 ) ;
F_188 ( 0x00000005 , V_297 + V_301 ) ;
V_64 = F_189 ( V_297 + V_302 ) & 0xfffffffe ;
F_188 ( V_64 , V_297 + V_302 ) ;
V_298 = V_303 + F_190 ( V_304 ) ;
do {
V_64 = F_189 ( V_297 + V_305 ) ;
if ( ( V_64 & 0xb0000000 ) == 0 )
goto V_306;
F_183 ( 10 ) ;
} while ( F_191 ( V_303 , V_298 ) );
F_47 ( & V_2 -> V_2 , L_117 ) ;
V_306:
F_188 ( 0x00000002 , V_297 + V_307 ) ;
F_176 ( V_2 , V_297 ) ;
return 0 ;
}
int F_192 ( struct V_1 * V_2 , int V_287 )
{
const struct V_308 * V_148 ;
for ( V_148 = V_308 ; V_148 -> V_309 ; V_148 ++ ) {
if ( ( V_148 -> V_157 == V_2 -> V_157 ||
V_148 -> V_157 == ( T_3 ) V_256 ) &&
( V_148 -> V_83 == V_2 -> V_83 ||
V_148 -> V_83 == ( T_3 ) V_256 ) )
return V_148 -> V_309 ( V_2 , V_287 ) ;
}
return - V_290 ;
}
static struct V_1 * F_193 ( struct V_1 * V_2 )
{
if ( ! F_91 ( V_2 -> V_75 ) )
return F_194 ( V_2 ) ;
return F_129 ( V_2 -> V_76 , F_130 ( F_58 ( V_2 -> V_75 ) , 0 ) ) ;
}
struct V_1 * F_195 ( struct V_1 * V_2 )
{
const struct V_310 * V_148 ;
for ( V_148 = V_310 ; V_148 -> V_311 ; V_148 ++ ) {
if ( ( V_148 -> V_157 == V_2 -> V_157 ||
V_148 -> V_157 == ( T_3 ) V_256 ) &&
( V_148 -> V_83 == V_2 -> V_83 ||
V_148 -> V_83 == ( T_3 ) V_256 ) )
return V_148 -> V_311 ( V_2 ) ;
}
return F_194 ( V_2 ) ;
}
int F_196 ( struct V_1 * V_2 , T_3 V_312 )
{
const struct V_313 * V_148 ;
int V_314 ;
for ( V_148 = V_313 ; V_148 -> V_315 ; V_148 ++ ) {
if ( ( V_148 -> V_157 == V_2 -> V_157 ||
V_148 -> V_157 == ( T_3 ) V_256 ) &&
( V_148 -> V_83 == V_2 -> V_83 ||
V_148 -> V_83 == ( T_3 ) V_256 ) ) {
V_314 = V_148 -> V_315 ( V_2 , V_312 ) ;
if ( V_314 >= 0 )
return V_314 ;
}
}
return - V_290 ;
}
