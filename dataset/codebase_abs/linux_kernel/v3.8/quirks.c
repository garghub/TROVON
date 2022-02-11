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
struct V_29 * V_30 = & V_2 -> V_29 [ 0 ] ;
if ( ( V_30 -> V_31 & 0x3ffffff ) || V_30 -> V_32 != V_30 -> V_31 + 0x3ffffff ) {
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0x3ffffff ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 , 0 ) != 8 ) {
struct V_29 * V_33 = & V_2 -> V_29 [ 0 ] ;
V_33 -> V_32 = V_33 -> V_31 + 8 - 1 ;
F_6 ( & V_2 -> V_2 , L_8
L_9 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , unsigned V_34 ,
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
static void F_30 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_11 ) ;
F_31 ( 0x3b0 , 0x0C , L_12 ) ;
F_31 ( 0x3d3 , 0x01 , L_12 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_2 V_34 ;
F_33 ( V_2 , 0xE0 , & V_34 ) ;
F_26 ( V_2 , V_34 , 64 , V_42 , L_13 ) ;
F_33 ( V_2 , 0xE2 , & V_34 ) ;
F_26 ( V_2 , V_34 , 32 , V_42 + 1 , L_14 ) ;
}
static void F_34 ( struct V_1 * V_2 , const char * V_37 , unsigned int V_43 , unsigned int V_44 )
{
T_1 V_45 ;
T_1 V_46 , V_35 , V_47 ;
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
T_1 V_45 ;
T_1 V_46 , V_35 , V_47 ;
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
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_34 , V_49 ;
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
static void F_37 ( struct V_1 * V_2 )
{
T_1 V_34 ;
T_3 V_44 ;
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
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_34 ;
T_3 V_44 ;
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
static void F_39 ( struct V_1 * V_2 , unsigned V_62 , const char * V_37 , int V_63 )
{
T_1 V_64 ;
T_1 V_35 , V_47 ;
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
static void F_40 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_39 ( V_2 , 0x84 , L_31 , 0 ) ;
F_39 ( V_2 , 0x88 , L_32 , 1 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned V_62 , const char * V_37 )
{
T_1 V_64 ;
T_1 V_46 , V_47 ;
F_10 ( V_2 , V_62 , & V_64 ) ;
if ( ! ( V_64 & 1 ) )
return;
V_47 = V_64 & 0xfffc ;
V_46 = ( V_64 >> 16 ) & 0xfc ;
V_46 |= 3 ;
F_6 ( & V_2 -> V_2 , L_33 , V_37 , V_47 , V_46 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_41 ( V_2 , 0x84 , L_34 ) ;
F_41 ( V_2 , 0x88 , L_35 ) ;
F_41 ( V_2 , 0x8c , L_36 ) ;
F_41 ( V_2 , 0x90 , L_37 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
T_1 V_34 ;
if ( V_2 -> V_22 & 0x10 ) {
F_10 ( V_2 , 0x48 , & V_34 ) ;
V_34 &= V_53 ;
F_26 ( V_2 , V_34 , 256 , V_42 , L_38 ) ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
T_2 V_65 ;
T_1 V_66 ;
F_43 ( V_2 ) ;
F_33 ( V_2 , 0x70 , & V_65 ) ;
V_65 &= V_53 ;
F_26 ( V_2 , V_65 , 128 , V_42 + 1 , L_39 ) ;
F_10 ( V_2 , 0x90 , & V_66 ) ;
V_66 &= V_53 ;
F_26 ( V_2 , V_66 , 16 , V_42 + 2 , L_40 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_2 V_67 , V_66 ;
F_33 ( V_2 , 0x88 , & V_67 ) ;
V_67 &= V_53 ;
F_26 ( V_2 , V_67 , 128 , V_42 , L_41 ) ;
F_33 ( V_2 , 0xd0 , & V_66 ) ;
V_66 &= V_53 ;
F_26 ( V_2 , V_66 , 16 , V_42 + 1 , L_42 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_1 * V_68 ;
T_2 V_69 ;
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
T_3 V_72 ;
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
T_3 V_74 ;
#define F_52 8
F_5 ( V_2 , 0x5B , & V_74 ) ;
if ( ! ( V_74 & F_52 ) ) {
F_6 ( & V_2 -> V_2 , L_48 ) ;
F_7 ( V_2 , 0x5B , V_74 | F_52 ) ;
}
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 >= 0x02 ) {
F_47 ( & V_2 -> V_2 , L_49 ) ;
F_47 ( & V_2 -> V_2 , L_50 ) ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 == 0 && V_2 -> V_76 -> V_77 == 0 )
V_78 = 1 ;
}
static void F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 && V_2 -> V_22 <= 0x12 ) {
F_6 ( & V_2 -> V_2 , L_51
L_52 , V_2 -> V_22 ) ;
V_2 -> V_79 -> V_80 |= V_81 ;
}
}
static void F_56 ( struct V_1 * V_5 )
{
T_3 V_82 ;
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
T_3 V_82 , V_92 ;
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
static void F_61 ( struct V_1 * V_2 )
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
T_1 V_96 ;
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
static void F_65 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_29 [ 1 ] ;
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0xffffff ;
}
static void F_66 ( struct V_1 * V_2 )
{
V_2 -> V_97 = 1 ;
}
static void F_67 ( struct V_1 * V_2 )
{
T_3 V_62 ;
F_5 ( V_2 , 0x41 , & V_62 ) ;
if ( V_62 & 2 ) {
V_62 &= ~ 2 ;
F_6 ( & V_2 -> V_2 , L_55 , V_62 ) ;
F_7 ( V_2 , 0x41 , V_62 ) ;
}
}
static void F_68 ( struct V_1 * V_68 )
{
T_2 V_98 ;
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
T_3 V_72 ;
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
static void F_70 ( struct V_1 * V_68 )
{
T_3 V_102 ;
F_5 ( V_68 , V_103 , & V_102 ) ;
if ( V_102 & 5 ) {
V_102 &= ~ 5 ;
V_68 -> V_100 &= ~ 5 ;
F_7 ( V_68 , V_103 , V_102 ) ;
}
}
static void F_71 ( struct V_1 * V_68 )
{
T_3 V_102 ;
F_5 ( V_68 , V_103 , & V_102 ) ;
if ( ( ( V_102 & 1 ) && ! ( V_102 & 4 ) ) || ( ( V_102 & 4 ) && ! ( V_102 & 1 ) ) ) {
F_6 ( & V_68 -> V_2 , L_58 ) ;
V_102 &= ~ 5 ;
V_68 -> V_100 &= ~ 5 ;
F_7 ( V_68 , V_103 , V_102 ) ;
}
}
static void F_72 ( struct V_1 * V_68 )
{
V_68 -> V_104 |= V_105 ;
}
static void F_73 ( struct V_1 * V_2 )
{
V_2 -> V_100 = V_106 << 8 ;
}
static void F_74 ( struct V_1 * V_2 )
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
T_2 V_64 ;
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
T_1 V_127 ;
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
T_1 V_64 ;
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
T_3 V_64 = 0 ;
F_5 ( V_2 , 0x77 , & V_64 ) ;
if ( V_64 & 0x10 ) {
F_6 ( & V_2 -> V_2 , L_62 ) ;
F_7 ( V_2 , 0x77 , V_64 & ~ 0x10 ) ;
}
}
static void F_88 ( struct V_1 * V_2 )
{
T_3 V_62 ;
T_2 V_129 ;
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
T_3 V_64 ;
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
T_1 V_132 , V_133 , V_100 ;
T_3 V_134 ;
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
static void F_92 ( struct V_1 * V_68 )
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
static void F_95 ( struct V_1 * V_68 )
{
F_96 ( V_68 ) ;
V_68 -> V_150 = 1 ;
}
static void F_97 ( struct V_1 * V_2 )
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
T_2 V_158 ;
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
T_1 V_161 ;
T_3 V_82 ;
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
T_1 V_161 ;
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
T_2 V_158 ;
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
static void F_105 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_29 [ 0 ] ;
if ( V_30 -> V_31 & 0x8 ) {
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0xf ;
}
}
static void F_106 ( struct V_1 * V_2 )
{
unsigned int V_171 ;
if ( V_2 -> V_22 >= 2 )
return;
for ( V_171 = 0 ; V_171 <= 1 ; V_171 ++ )
if ( F_25 ( V_2 , V_171 ) == 0x80 &&
( F_93 ( V_2 , V_171 ) & 0x80 ) ) {
struct V_29 * V_30 = & V_2 -> V_29 [ V_171 ] ;
F_6 ( & V_2 -> V_2 ,
L_70 ,
V_171 ) ;
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0xff ;
}
}
static void F_107 ( struct V_1 * V_2 )
{
unsigned int V_172 = ( V_2 -> V_110 & 0xf0 ) >> 4 ;
unsigned int V_173 = V_2 -> V_110 & 0xf ;
switch ( V_2 -> V_83 ) {
case V_174 :
if ( V_2 -> V_107 == V_175 &&
V_2 -> V_110 == 0x0299 )
return;
case V_176 :
case V_177 :
case V_178 :
case V_179 :
if ( V_172 ) {
F_6 ( & V_2 -> V_2 , L_71
L_72
L_73 ,
V_2 -> V_83 , V_172 , V_173 ) ;
V_2 -> V_100 = ( V_180 << 8 ) |
( V_2 -> V_100 & 0xff ) ;
}
}
}
static void F_108 ( struct V_1 * V_2 )
{
T_2 V_69 , V_181 ;
T_3 T_4 * V_182 ;
T_3 V_183 ;
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
if ( ! ( V_69 & V_184 ) || ! F_93 ( V_2 , 0 ) )
return;
V_67 = F_109 ( V_2 , V_185 ) ;
if ( V_67 ) {
F_33 ( V_2 , V_67 + V_186 , & V_181 ) ;
if ( ( V_181 & V_187 ) != V_188 )
return;
}
V_182 = F_110 ( F_93 ( V_2 , 0 ) , 8 ) ;
if ( ! V_182 ) {
F_47 ( & V_2 -> V_2 , L_74 ) ;
return;
}
V_183 = F_111 ( V_182 + 3 ) ;
if ( V_183 == 0 ) {
F_47 ( & V_2 -> V_2 , L_75
L_76 ) ;
F_112 ( 1 , V_182 + 3 ) ;
}
F_85 ( V_182 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_77 ) ;
F_114 ( V_2 , V_189 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
if ( V_2 -> V_100 == V_190 ) {
F_6 ( & V_2 -> V_2 , L_78 ) ;
V_2 -> V_100 = V_191 ;
}
}
static void F_116 ( struct V_1 * V_2 )
{
T_2 V_192 ;
F_33 ( V_2 , 0x40 , & V_192 ) ;
if ( V_192 & 0x200 ) {
F_6 ( & V_2 -> V_2 , L_79 ) ;
V_2 -> V_193 = 1 ;
}
}
static void F_117 ( struct V_1 * V_2 )
{
T_5 V_194 ;
if ( F_5 ( V_2 , 0xf41 , & V_194 ) == 0 ) {
if ( ! ( V_194 & 0x20 ) ) {
F_7 ( V_2 , 0xf41 , V_194 | 0x20 ) ;
F_6 ( & V_2 -> V_2 ,
L_80 ) ;
}
}
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_1 * V_18 = F_4 ( V_20 ,
V_195 , NULL ) ;
T_5 V_194 ;
V_18 = F_4 ( V_20 , V_195 , V_18 ) ;
if ( ! V_18 )
return;
F_17 ( V_18 ) ;
if ( F_5 ( V_2 , 0x76 , & V_194 ) == 0 ) {
if ( V_194 & 0x40 ) {
F_7 ( V_2 , 0x76 , V_194 ^ 0x40 ) ;
F_6 ( & V_2 -> V_2 ,
L_81 ) ;
}
}
if ( F_5 ( V_2 , 0x72 , & V_194 ) == 0 ) {
if ( V_194 != 0 ) {
F_7 ( V_2 , 0x72 , 0x0 ) ;
F_7 ( V_2 , 0x75 , 0x1 ) ;
F_7 ( V_2 , 0x77 , 0x0 ) ;
F_6 ( & V_2 -> V_2 ,
L_82 ) ;
}
}
}
static void F_119 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_83 == V_196 ) ||
( V_2 -> V_83 == V_197 ) ||
( V_2 -> V_83 == V_198 ) ||
( V_2 -> V_83 == V_199 ) ||
( ( V_2 -> V_83 == V_200 ) &&
( V_2 -> V_22 & 0xf0 ) == 0x0 ) ) {
if ( V_2 -> V_201 )
V_2 -> V_201 -> V_202 = 0x80 ;
}
}
static void F_120 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_10 ( V_2 , 0xf4 , & V_15 ) ;
if ( V_15 == 0x05719000 ) {
int V_203 = F_121 ( V_2 ) ;
if ( V_203 > 2048 )
F_122 ( V_2 , 2048 ) ;
}
}
static void F_123 ( struct V_1 * V_2 )
{
T_3 V_62 ;
if ( F_5 ( V_2 , 0xF4 , & V_62 ) == 0 && ! ( V_62 & 0x02 ) ) {
F_6 ( & V_2 -> V_2 , L_83 ) ;
F_7 ( V_2 , 0xF4 , V_62 | 0x02 ) ;
}
}
static void F_124 ( struct V_1 * V_2 )
{
if ( V_204 ) {
F_63 ( V_2 , 0x98 , 0x1 ) ;
F_125 ( 50 ) ;
}
}
static void F_126 ( struct V_1 * V_2 )
{
F_127 () ;
F_47 ( & V_2 -> V_2 , L_84 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 ) {
F_47 ( & V_2 -> V_2 , L_85
L_86 ) ;
V_2 -> V_79 -> V_80 |= V_205 ;
}
}
static void F_129 ( struct V_1 * V_206 )
{
struct V_1 * V_207 ;
V_207 = F_130 ( V_206 -> V_76 , F_131 ( 1 , 0 ) ) ;
if ( V_207 ) {
if ( V_207 -> V_83 == 0x9602 )
F_128 ( V_207 ) ;
F_17 ( V_207 ) ;
}
}
static int F_132 ( struct V_1 * V_2 )
{
int V_208 , V_209 = 48 ;
V_208 = F_133 ( V_2 , V_210 ) ;
while ( V_208 && V_209 -- ) {
T_3 V_40 ;
if ( F_5 ( V_2 , V_208 + V_211 ,
& V_40 ) == 0 )
{
F_6 ( & V_2 -> V_2 , L_87 ,
V_40 & V_212 ?
L_88 : L_89 ) ;
return ( V_40 & V_212 ) != 0 ;
}
V_208 = F_134 ( V_2 , V_208 ,
V_210 ) ;
}
return 0 ;
}
static void F_135 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 && ! F_132 ( V_2 ) ) {
F_47 ( & V_2 -> V_2 , L_85
L_86 ) ;
V_2 -> V_79 -> V_80 |= V_205 ;
}
}
static void F_136 ( struct V_1 * V_2 )
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
V_2 -> V_79 -> V_80 |= V_205 ;
}
F_17 ( V_68 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
int V_208 , V_209 = 48 ;
V_208 = F_133 ( V_2 , V_210 ) ;
while ( V_208 && V_209 -- ) {
T_3 V_40 ;
if ( F_5 ( V_2 , V_208 + V_211 ,
& V_40 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_90 ) ;
F_7 ( V_2 , V_208 + V_211 ,
V_40 | V_212 ) ;
}
V_208 = F_134 ( V_2 , V_208 ,
V_210 ) ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
const char * V_213 = F_139 ( V_214 ) ;
if ( V_213 &&
( strstr ( V_213 , L_91 ) ||
strstr ( V_213 , L_92 ) ) ) {
F_6 ( & V_2 -> V_2 ,
L_93 ) ;
V_2 -> V_150 = 1 ;
}
}
static void F_140 ( struct V_1 * V_2 )
{
T_1 V_215 ;
if ( ! F_109 ( V_2 , V_216 ) )
return;
F_10 ( V_2 , 0x74 , & V_215 ) ;
if ( V_215 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_141 ( V_217 L_94 ) ;
V_215 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_63 ( V_2 , 0x74 , V_215 ) ;
}
}
static int F_142 ( struct V_1 * V_2 )
{
int V_208 , V_209 = 48 ;
int V_218 = 0 ;
V_208 = F_133 ( V_2 , V_210 ) ;
while ( V_208 && V_209 -- ) {
T_3 V_40 ;
if ( V_218 < 1 )
V_218 = 1 ;
if ( F_5 ( V_2 , V_208 + V_211 ,
& V_40 ) == 0 ) {
if ( V_40 & V_212 ) {
if ( V_218 < 2 ) {
V_218 = 2 ;
break;
}
}
}
V_208 = F_134 ( V_2 , V_208 ,
V_210 ) ;
}
return V_218 ;
}
static int F_143 ( struct V_1 * V_206 )
{
struct V_1 * V_2 ;
int V_208 ;
int V_148 , V_219 ;
int V_218 = 0 ;
V_219 = V_206 -> V_75 >> 3 ;
for ( V_148 = V_219 + 1 ; V_148 < 0x20 ; V_148 ++ ) {
V_2 = F_130 ( V_206 -> V_76 , F_131 ( V_148 , 0 ) ) ;
if ( ! V_2 )
continue;
V_208 = F_133 ( V_2 , V_220 ) ;
if ( V_208 != 0 ) {
F_17 ( V_2 ) ;
break;
}
if ( F_142 ( V_2 ) ) {
V_218 = 1 ;
F_17 ( V_2 ) ;
break;
}
F_17 ( V_2 ) ;
}
return V_218 ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_208 , V_221 ;
int V_32 = 0 ;
T_2 V_40 , V_222 ;
V_208 = F_133 ( V_2 , V_220 ) ;
if ( ! V_208 )
goto V_223;
F_33 ( V_2 , V_208 + V_224 , & V_40 ) ;
V_221 = ( ( V_40 >> 10 ) & 1 ) ?
V_225 : V_226 ;
F_33 ( V_2 , V_208 + V_221 , & V_222 ) ;
if ( V_222 & ( 1 << 6 ) )
V_32 = 1 ;
V_223:
return V_32 ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_1 * V_206 ;
int V_208 ;
int V_148 , V_219 ;
int V_218 = 0 ;
V_219 = V_2 -> V_75 >> 3 ;
for ( V_148 = V_219 ; V_148 >= 0 ; V_148 -- ) {
V_206 = F_130 ( V_2 -> V_76 , F_131 ( V_148 , 0 ) ) ;
if ( ! V_206 )
continue;
V_208 = F_133 ( V_206 , V_220 ) ;
if ( V_208 != 0 ) {
V_218 = 1 ;
break;
}
F_17 ( V_206 ) ;
}
if ( ! V_218 )
return;
if ( V_206 == V_2 && F_144 ( V_206 ) &&
F_143 ( V_206 ) )
goto V_223;
if ( F_132 ( V_206 ) )
goto V_223;
F_137 ( V_2 ) ;
V_223:
F_17 ( V_206 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
int V_208 , V_209 = 48 ;
V_208 = F_133 ( V_2 , V_210 ) ;
while ( V_208 && V_209 -- ) {
T_3 V_40 ;
if ( F_5 ( V_2 , V_208 + V_211 ,
& V_40 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_95 ) ;
F_7 ( V_2 , V_208 + V_211 ,
V_40 & ~ V_212 ) ;
}
V_208 = F_134 ( V_2 , V_208 ,
V_210 ) ;
}
}
static void F_147 ( struct V_1 * V_2 , int V_227 )
{
struct V_1 * V_206 ;
int V_208 ;
int V_218 ;
if ( ! F_148 () )
return;
V_218 = F_142 ( V_2 ) ;
if ( V_218 == 0 )
return;
V_206 = F_149 ( 0 , F_131 ( 0 , 0 ) ) ;
if ( V_206 == NULL ) {
F_47 ( & V_2 -> V_2 ,
L_96 ) ;
return;
}
V_208 = F_133 ( V_206 , V_220 ) ;
if ( V_208 != 0 ) {
if ( V_218 == 1 ) {
if ( V_227 )
F_137 ( V_2 ) ;
else
F_145 ( V_2 ) ;
}
goto V_223;
}
if ( V_218 == 1 )
goto V_223;
F_146 ( V_2 ) ;
V_223:
F_17 ( V_206 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
return F_147 ( V_2 , 1 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
return F_147 ( V_2 , 0 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
V_2 -> V_104 |= V_228 ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( V_229 , V_230 ,
NULL ) ;
if ( ! V_18 )
return;
if ( ( V_18 -> V_22 < 0x3B ) && ( V_18 -> V_22 >= 0x30 ) )
V_2 -> V_104 |= V_228 ;
F_17 ( V_18 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
V_2 -> V_231 = 1 ;
}
static void F_155 ( struct V_1 * V_2 )
{
T_3 V_232 ;
T_3 V_233 ;
T_3 V_234 ;
if ( F_91 ( V_2 -> V_75 ) )
return;
F_5 ( V_2 , 0xB7 , & V_234 ) ;
if ( V_234 & 0x02 )
return;
F_5 ( V_2 , 0x8E , & V_232 ) ;
F_7 ( V_2 , 0x8E , 0xAA ) ;
F_5 ( V_2 , 0x8D , & V_233 ) ;
F_7 ( V_2 , 0x8D , 0xB7 ) ;
F_7 ( V_2 , 0xB7 , V_234 | 0x02 ) ;
F_7 ( V_2 , 0x8E , V_232 ) ;
F_7 ( V_2 , 0x8D , V_233 ) ;
F_156 ( & V_2 -> V_2 , L_97 ) ;
F_156 ( & V_2 -> V_2 , L_98 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
T_3 V_232 ;
T_3 V_234 ;
if ( F_91 ( V_2 -> V_75 ) )
return;
if ( V_2 -> V_83 == V_235 ||
V_2 -> V_83 == V_236 ) {
F_7 ( V_2 , 0xf9 , 0xfc ) ;
F_7 ( V_2 , 0x150 , 0x10 ) ;
F_7 ( V_2 , 0xf9 , 0x00 ) ;
F_7 ( V_2 , 0xfc , 0x01 ) ;
F_7 ( V_2 , 0xe1 , 0x32 ) ;
F_7 ( V_2 , 0xfc , 0x00 ) ;
F_156 ( & V_2 -> V_2 , L_99 ) ;
}
F_5 ( V_2 , 0xCB , & V_234 ) ;
if ( V_234 & 0x02 )
return;
F_5 ( V_2 , 0xCA , & V_232 ) ;
F_7 ( V_2 , 0xCA , 0x57 ) ;
F_7 ( V_2 , 0xCB , V_234 | 0x02 ) ;
F_7 ( V_2 , 0xCA , V_232 ) ;
F_156 ( & V_2 -> V_2 , L_100 ) ;
F_156 ( & V_2 -> V_2 , L_98 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
T_1 V_237 ;
F_10 ( V_2 , V_238 , & V_237 ) ;
F_63 ( V_2 , V_238 , V_237 | V_239 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_101 ) ;
V_2 -> V_100 = V_240 ;
}
static void F_160 ( struct V_1 * V_2 )
{
V_2 -> V_241 = 1 ;
}
static void F_161 ( struct V_1 * V_2 )
{
int V_242 ;
T_2 V_243 ;
if ( V_244 == V_245 )
return;
V_242 = F_33 ( V_2 , 0x48 , & V_243 ) ;
if ( V_242 ) {
F_162 ( & V_2 -> V_2 , L_102
L_103 ) ;
return;
}
if ( ! ( V_243 & ( 1 << 10 ) ) )
return;
V_243 &= ~ ( 1 << 10 ) ;
V_242 = F_49 ( V_2 , 0x48 , V_243 ) ;
if ( V_242 ) {
F_162 ( & V_2 -> V_2 , L_104
L_103 ) ;
return;
}
F_163 ( L_105
L_106 ) ;
}
static T_6 F_164 ( struct V_1 * V_2 ,
void (* F_165)( struct V_1 * V_2 ) )
{
T_6 V_246 = F_166 ( 0 , 0 ) ;
F_167 ( & V_2 -> V_2 , L_107 , F_165 ) ;
if ( V_247 ) {
F_168 ( L_108 ,
F_165 , F_169 ( V_248 ) , F_170 ( & V_2 -> V_2 ) ) ;
V_246 = F_171 () ;
}
return V_246 ;
}
static void F_172 ( struct V_1 * V_2 , T_6 V_246 ,
void (* F_165)( struct V_1 * V_2 ) )
{
T_6 V_249 , V_250 ;
unsigned long long V_251 ;
if ( V_247 ) {
V_250 = F_171 () ;
V_249 = F_173 ( V_250 , V_246 ) ;
V_251 = ( unsigned long long ) F_174 ( V_249 ) >> 10 ;
F_168 ( L_109 ,
F_165 , V_251 , F_170 ( & V_2 -> V_2 ) ) ;
}
}
static void F_175 ( struct V_1 * V_2 )
{
void T_4 * V_252 = F_176 ( V_2 , 0 , 0 ) ;
if ( V_252 == NULL ) {
F_47 ( & V_2 -> V_2 , L_110 ) ;
return;
}
if ( F_82 ( V_252 + V_253 ) != 0 ) {
F_47 ( & V_2 -> V_2 , L_111
L_76 ) ;
F_83 ( 0 , V_252 + V_253 ) ;
}
F_177 ( V_2 , V_252 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
V_2 -> V_254 = 1 ;
}
static void F_179 ( struct V_1 * V_2 , struct V_255 * V_256 ,
struct V_255 * V_32 )
{
T_6 V_246 ;
for (; V_256 < V_32 ; V_256 ++ )
if ( ( V_256 -> V_100 == ( T_1 ) ( V_2 -> V_100 >> V_256 -> V_257 ) ||
V_256 -> V_100 == ( T_1 ) V_258 ) &&
( V_256 -> V_157 == V_2 -> V_157 ||
V_256 -> V_157 == ( T_2 ) V_258 ) &&
( V_256 -> V_83 == V_2 -> V_83 ||
V_256 -> V_83 == ( T_2 ) V_258 ) ) {
V_246 = F_164 ( V_2 , V_256 -> V_259 ) ;
V_256 -> V_259 ( V_2 ) ;
F_172 ( V_2 , V_246 , V_256 -> V_259 ) ;
}
}
void F_180 ( enum V_260 V_261 , struct V_1 * V_2 )
{
struct V_255 * V_31 , * V_32 ;
switch( V_261 ) {
case V_262 :
V_31 = V_263 ;
V_32 = V_264 ;
break;
case V_265 :
V_31 = V_266 ;
V_32 = V_267 ;
break;
case V_268 :
if ( ! V_269 )
return;
V_31 = V_270 ;
V_32 = V_271 ;
break;
case V_272 :
V_31 = V_273 ;
V_32 = V_274 ;
break;
case V_275 :
V_31 = V_276 ;
V_32 = V_277 ;
break;
case V_278 :
V_31 = V_279 ;
V_32 = V_280 ;
break;
case V_281 :
V_31 = V_282 ;
V_32 = V_283 ;
break;
default:
return;
}
F_179 ( V_2 , V_31 , V_32 ) ;
}
static int T_7 F_181 ( void )
{
struct V_1 * V_2 = NULL ;
T_3 V_284 = 0 ;
T_3 V_72 ;
if ( V_285 )
F_141 ( V_286 L_112 ,
V_285 << 2 ) ;
V_269 = true ;
F_182 (dev) {
F_180 ( V_268 , V_2 ) ;
if ( ! V_285 ) {
F_5 ( V_2 , V_287 , & V_72 ) ;
if ( ! V_284 )
V_284 = V_72 ;
if ( ! V_72 || V_284 == V_72 )
continue;
F_141 ( V_286 L_113
L_114 , V_284 << 2 , V_72 << 2 ,
V_288 << 2 ) ;
V_285 = V_288 ;
}
}
if ( ! V_285 ) {
F_141 ( V_286 L_115 ,
V_284 << 2 , V_288 << 2 ) ;
V_285 = V_284 ? V_284 : V_288 ;
}
return 0 ;
}
static int F_183 ( struct V_1 * V_2 , int V_289 )
{
int V_208 ;
if ( V_2 -> V_100 == V_290 ) {
V_208 = F_109 ( V_2 , V_291 ) ;
if ( ! V_208 )
return - V_292 ;
if ( V_289 )
return 0 ;
F_7 ( V_2 , V_208 + 0x4 , 1 ) ;
F_184 ( 100 ) ;
return 0 ;
} else {
return - V_292 ;
}
}
static int F_185 ( struct V_1 * V_2 , int V_289 )
{
int V_148 ;
T_2 V_293 ;
if ( V_289 )
return 0 ;
for ( V_148 = 0 ; V_148 < 4 ; V_148 ++ ) {
if ( V_148 )
F_184 ( ( 1 << ( V_148 - 1 ) ) * 100 ) ;
F_186 ( V_2 , V_294 , & V_293 ) ;
if ( ! ( V_293 & V_295 ) )
goto V_296;
}
F_162 ( & V_2 -> V_2 , L_116
L_117 ) ;
V_296:
F_187 ( V_2 , V_297 , V_298 ) ;
F_184 ( 100 ) ;
return 0 ;
}
static int F_188 ( struct V_1 * V_2 , int V_289 )
{
void T_4 * V_299 ;
unsigned long V_300 ;
T_1 V_64 ;
if ( V_289 )
return 0 ;
V_299 = F_176 ( V_2 , 0 , 0 ) ;
if ( ! V_299 )
return - V_301 ;
F_189 ( 0x00000002 , V_299 + V_302 ) ;
F_189 ( 0x00000005 , V_299 + V_303 ) ;
V_64 = F_190 ( V_299 + V_304 ) & 0xfffffffe ;
F_189 ( V_64 , V_299 + V_304 ) ;
V_300 = V_305 + F_191 ( V_306 ) ;
do {
V_64 = F_190 ( V_299 + V_307 ) ;
if ( ( V_64 & 0xb0000000 ) == 0 )
goto V_308;
F_184 ( 10 ) ;
} while ( F_192 ( V_305 , V_300 ) );
F_47 ( & V_2 -> V_2 , L_118 ) ;
V_308:
F_189 ( 0x00000002 , V_299 + V_309 ) ;
F_177 ( V_2 , V_299 ) ;
return 0 ;
}
int F_193 ( struct V_1 * V_2 , int V_289 )
{
const struct V_310 * V_148 ;
for ( V_148 = V_310 ; V_148 -> V_311 ; V_148 ++ ) {
if ( ( V_148 -> V_157 == V_2 -> V_157 ||
V_148 -> V_157 == ( T_2 ) V_258 ) &&
( V_148 -> V_83 == V_2 -> V_83 ||
V_148 -> V_83 == ( T_2 ) V_258 ) )
return V_148 -> V_311 ( V_2 , V_289 ) ;
}
return - V_292 ;
}
static struct V_1 * F_194 ( struct V_1 * V_2 )
{
if ( ! F_91 ( V_2 -> V_75 ) )
return F_195 ( V_2 ) ;
return F_130 ( V_2 -> V_76 , F_131 ( F_58 ( V_2 -> V_75 ) , 0 ) ) ;
}
struct V_1 * F_196 ( struct V_1 * V_2 )
{
const struct V_312 * V_148 ;
for ( V_148 = V_312 ; V_148 -> V_313 ; V_148 ++ ) {
if ( ( V_148 -> V_157 == V_2 -> V_157 ||
V_148 -> V_157 == ( T_2 ) V_258 ) &&
( V_148 -> V_83 == V_2 -> V_83 ||
V_148 -> V_83 == ( T_2 ) V_258 ) )
return V_148 -> V_313 ( V_2 ) ;
}
return F_195 ( V_2 ) ;
}
int F_197 ( struct V_1 * V_2 , T_2 V_314 )
{
const struct V_315 * V_148 ;
int V_316 ;
for ( V_148 = V_315 ; V_148 -> V_317 ; V_148 ++ ) {
if ( ( V_148 -> V_157 == V_2 -> V_157 ||
V_148 -> V_157 == ( T_2 ) V_258 ) &&
( V_148 -> V_83 == V_2 -> V_83 ||
V_148 -> V_83 == ( T_2 ) V_258 ) ) {
V_316 = V_148 -> V_317 ( V_2 , V_314 ) ;
if ( V_316 >= 0 )
return V_316 ;
}
}
return - V_292 ;
}
