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
static void F_26 ( struct V_1 * V_2 )
{
if ( F_27 ( V_2 , 0 ) != 8 ) {
struct V_31 * V_39 = & V_2 -> V_31 [ 0 ] ;
V_39 -> V_36 = V_39 -> V_37 + 8 - 1 ;
F_6 ( & V_2 -> V_2 , L_9 ) ;
}
}
static void F_28 ( struct V_1 * V_2 , int V_40 ,
unsigned V_41 , int V_42 , const char * V_43 )
{
T_2 V_44 ;
struct V_45 V_46 ;
struct V_31 * V_39 = V_2 -> V_31 + V_42 ;
F_29 ( V_2 , V_40 , & V_44 ) ;
V_44 &= ~ ( V_41 - 1 ) ;
if ( ! V_44 )
return;
V_39 -> V_43 = F_30 ( V_2 ) ;
V_39 -> V_33 = V_47 ;
V_46 . V_37 = V_44 ;
V_46 . V_36 = V_44 + V_41 - 1 ;
F_31 ( V_2 -> V_48 , V_39 , & V_46 ) ;
if ( ! F_32 ( V_2 , V_42 ) )
F_6 ( & V_2 -> V_2 , L_10 , V_39 , V_43 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_11 ) ;
F_34 ( 0x3b0 , 0x0C , L_12 ) ;
F_34 ( 0x3d3 , 0x01 , L_12 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_28 ( V_2 , 0xE0 , 64 , V_49 , L_13 ) ;
F_28 ( V_2 , 0xE2 , 32 , V_49 + 1 , L_14 ) ;
}
static void F_36 ( struct V_1 * V_2 , const char * V_43 , unsigned int V_40 , unsigned int V_50 )
{
T_1 V_51 ;
T_1 V_52 , V_41 , V_53 ;
F_10 ( V_2 , V_40 , & V_51 ) ;
if ( ( V_51 & V_50 ) != V_50 )
return;
V_52 = ( V_51 >> 16 ) & 15 ;
V_53 = V_51 & 0xffff ;
V_41 = 16 ;
for (; ; ) {
unsigned V_54 = V_41 >> 1 ;
if ( ( V_54 & V_52 ) == V_54 )
break;
V_41 = V_54 ;
}
V_53 &= - V_41 ;
F_6 ( & V_2 -> V_2 , L_15 , V_43 , V_53 ,
V_53 + V_41 - 1 ) ;
}
static void F_37 ( struct V_1 * V_2 , const char * V_43 , unsigned int V_40 , unsigned int V_50 )
{
T_1 V_51 ;
T_1 V_52 , V_41 , V_53 ;
F_10 ( V_2 , V_40 , & V_51 ) ;
if ( ( V_51 & V_50 ) != V_50 )
return;
V_53 = V_51 & 0xffff0000 ;
V_52 = ( V_51 & 0x3f ) << 16 ;
V_41 = 128 << 16 ;
for (; ; ) {
unsigned V_54 = V_41 >> 1 ;
if ( ( V_54 & V_52 ) == V_54 )
break;
V_41 = V_54 ;
}
V_53 &= - V_41 ;
F_6 ( & V_2 -> V_2 , L_16 , V_43 , V_53 ,
V_53 + V_41 - 1 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_55 ;
F_28 ( V_2 , 0x40 , 64 , V_49 , L_17 ) ;
F_28 ( V_2 , 0x90 , 16 , V_49 + 1 , L_18 ) ;
F_10 ( V_2 , 0x5c , & V_55 ) ;
F_36 ( V_2 , L_19 , 0x60 , 3 << 21 ) ;
F_36 ( V_2 , L_20 , 0x64 , 3 << 21 ) ;
if ( V_55 & ( 1 << 29 ) ) {
F_36 ( V_2 , L_21 , 0x68 , 1 << 20 ) ;
F_37 ( V_2 , L_22 , 0x6c , 1 << 7 ) ;
}
if ( V_55 & ( 1 << 30 ) ) {
F_36 ( V_2 , L_23 , 0x70 , 1 << 20 ) ;
F_37 ( V_2 , L_24 , 0x74 , 1 << 7 ) ;
}
F_36 ( V_2 , L_25 , 0x78 , 1 << 20 ) ;
F_36 ( V_2 , L_26 , 0x7c , 1 << 20 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_3 V_50 ;
F_5 ( V_2 , V_56 , & V_50 ) ;
if ( V_50 & V_57 )
F_28 ( V_2 , V_58 , 128 , V_49 ,
L_27 ) ;
F_5 ( V_2 , V_59 , & V_50 ) ;
if ( V_50 & V_60 )
F_28 ( V_2 , V_61 , 64 , V_49 + 1 ,
L_28 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_3 V_50 ;
F_5 ( V_2 , V_56 , & V_50 ) ;
if ( V_50 & V_62 )
F_28 ( V_2 , V_58 , 128 , V_49 ,
L_29 ) ;
F_5 ( V_2 , V_63 , & V_50 ) ;
if ( V_50 & V_64 )
F_28 ( V_2 , V_65 , 64 , V_49 + 1 ,
L_30 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned V_66 , const char * V_43 , int V_67 )
{
T_1 V_68 ;
T_1 V_41 , V_53 ;
F_10 ( V_2 , V_66 , & V_68 ) ;
if ( ! ( V_68 & 1 ) )
return;
V_53 = V_68 & 0xfffc ;
if ( V_67 ) {
V_41 = 16 ;
} else {
V_41 = 128 ;
}
V_53 &= ~ ( V_41 - 1 ) ;
F_6 ( & V_2 -> V_2 , L_15 , V_43 , V_53 , V_53 + V_41 - 1 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
F_41 ( V_2 , 0x84 , L_31 , 0 ) ;
F_41 ( V_2 , 0x88 , L_32 , 1 ) ;
}
static void F_43 ( struct V_1 * V_2 , unsigned V_66 , const char * V_43 )
{
T_1 V_68 ;
T_1 V_52 , V_53 ;
F_10 ( V_2 , V_66 , & V_68 ) ;
if ( ! ( V_68 & 1 ) )
return;
V_53 = V_68 & 0xfffc ;
V_52 = ( V_68 >> 16 ) & 0xfc ;
V_52 |= 3 ;
F_6 ( & V_2 -> V_2 , L_33 , V_43 , V_53 , V_52 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
F_43 ( V_2 , 0x84 , L_34 ) ;
F_43 ( V_2 , 0x88 , L_35 ) ;
F_43 ( V_2 , 0x8c , L_36 ) ;
F_43 ( V_2 , 0x90 , L_37 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 & 0x10 )
F_28 ( V_2 , 0x48 , 256 , V_49 ,
L_38 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
F_28 ( V_2 , 0x70 , 128 , V_49 + 1 ,
L_39 ) ;
F_28 ( V_2 , 0x90 , 16 , V_49 + 2 , L_40 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_28 ( V_2 , 0x88 , 128 , V_49 , L_41 ) ;
F_28 ( V_2 , 0xd0 , 16 , V_49 + 1 , L_42 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_1 * V_69 ;
T_2 V_70 ;
F_49 ( & V_2 -> V_2 , L_43 ) ;
F_50 (pdev, &dev->subordinate->devices, bus_list) {
F_29 ( V_69 , V_71 , & V_70 ) ;
if ( V_70 & V_72 )
F_51 ( V_69 , V_71 , V_70 & ~ V_72 ) ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
T_3 V_73 ;
if ( V_74 < 1 )
V_73 = 0 ;
else
V_73 = 0x1f ;
F_6 ( & V_2 -> V_2 , L_44 ,
V_73 == 0 ? L_45 : L_46 ) ;
F_7 ( V_2 , 0x58 , V_73 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
T_3 V_75 ;
#define F_54 8
F_5 ( V_2 , 0x5B , & V_75 ) ;
if ( ! ( V_75 & F_54 ) ) {
F_6 ( & V_2 -> V_2 , L_47 ) ;
F_7 ( V_2 , 0x5B , V_75 | F_54 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 >= 0x02 ) {
F_49 ( & V_2 -> V_2 , L_48 ) ;
F_49 ( & V_2 -> V_2 , L_49 ) ;
}
}
static void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_76 == 0 && V_2 -> V_48 -> V_77 == 0 )
V_78 = 1 ;
}
static void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 && V_2 -> V_22 <= 0x12 ) {
F_6 ( & V_2 -> V_2 , L_50 ,
V_2 -> V_22 ) ;
V_2 -> V_79 -> V_80 |= V_81 ;
}
}
static void F_58 ( struct V_1 * V_5 )
{
T_3 V_82 ;
F_5 ( V_5 , 0x42 , & V_82 ) ;
V_82 &= 0xf ;
if ( V_82 && ( V_82 != 2 ) )
V_5 -> V_82 = V_82 ;
}
static void F_59 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_83 ) {
case V_21 :
V_84 = F_60 ( V_2 -> V_76 ) ;
V_85 = F_60 ( V_2 -> V_76 ) ;
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
static void F_61 ( struct V_1 * V_2 )
{
T_3 V_82 , V_92 ;
if ( V_84 == - 1 )
return;
V_92 = V_2 -> V_82 ;
if ( ! V_92 || V_92 > 15 )
return;
if ( V_2 -> V_48 -> V_77 != 0 || F_60 ( V_2 -> V_76 ) > V_85 ||
F_60 ( V_2 -> V_76 ) < V_84 )
return;
F_5 ( V_2 , V_93 , & V_82 ) ;
if ( V_92 != V_82 ) {
F_6 ( & V_2 -> V_2 , L_51 ,
V_82 , V_92 ) ;
F_62 ( 15 ) ;
F_7 ( V_2 , V_93 , V_92 ) ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0xfc , 0 ) ;
F_29 ( V_2 , V_94 , & V_2 -> V_83 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 , V_95 , 0 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
T_1 V_96 ;
F_10 ( V_2 , 0x4C , & V_96 ) ;
if ( ( V_96 & 6 ) != 6 ) {
V_96 |= 6 ;
F_49 ( & V_2 -> V_2 , L_52 ) ;
F_65 ( V_2 , 0x4C , V_96 ) ;
F_10 ( V_2 , 0x84 , & V_96 ) ;
V_96 |= ( 1 << 23 ) ;
F_65 ( V_2 , 0x84 , V_96 ) ;
}
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_31 [ 1 ] ;
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0xffffff ;
}
static void F_68 ( struct V_1 * V_2 )
{
V_2 -> V_97 = 1 ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_3 V_66 ;
F_5 ( V_2 , 0x41 , & V_66 ) ;
if ( V_66 & 2 ) {
V_66 &= ~ 2 ;
F_6 ( & V_2 -> V_2 , L_53 ,
V_66 ) ;
F_7 ( V_2 , 0x41 , V_66 ) ;
}
}
static void F_70 ( struct V_1 * V_69 )
{
T_2 V_98 ;
if ( V_69 -> V_22 != 0x04 )
return;
F_29 ( V_69 , 0x40 , & V_98 ) ;
if ( V_98 & ( 1 << 6 ) ) {
V_98 &= ~ ( 1 << 6 ) ;
F_51 ( V_69 , 0x40 , V_98 ) ;
F_6 ( & V_69 -> V_2 , L_54 ) ;
}
}
static void F_71 ( struct V_1 * V_69 )
{
T_3 V_73 ;
F_5 ( V_69 , V_99 , & V_73 ) ;
if ( V_73 == 0x01 ) {
F_5 ( V_69 , 0x40 , & V_73 ) ;
F_7 ( V_69 , 0x40 , V_73 | 1 ) ;
F_7 ( V_69 , 0x9 , 1 ) ;
F_7 ( V_69 , 0xa , 6 ) ;
F_7 ( V_69 , 0x40 , V_73 ) ;
V_69 -> V_100 = V_101 ;
F_6 ( & V_69 -> V_2 , L_55 ) ;
}
}
static void F_72 ( struct V_1 * V_69 )
{
T_3 V_102 ;
F_5 ( V_69 , V_103 , & V_102 ) ;
if ( V_102 & 5 ) {
V_102 &= ~ 5 ;
V_69 -> V_100 &= ~ 5 ;
F_7 ( V_69 , V_103 , V_102 ) ;
}
}
static void F_73 ( struct V_1 * V_69 )
{
T_3 V_102 ;
F_5 ( V_69 , V_103 , & V_102 ) ;
if ( ( ( V_102 & 1 ) && ! ( V_102 & 4 ) ) || ( ( V_102 & 4 ) && ! ( V_102 & 1 ) ) ) {
F_6 ( & V_69 -> V_2 , L_56 ) ;
V_102 &= ~ 5 ;
V_69 -> V_100 &= ~ 5 ;
F_7 ( V_69 , V_103 , V_102 ) ;
}
}
static void F_74 ( struct V_1 * V_69 )
{
V_69 -> V_104 |= V_105 ;
}
static void F_75 ( struct V_1 * V_2 )
{
V_2 -> V_100 = V_106 << 8 ;
}
static void F_76 ( struct V_1 * V_2 )
{
if ( F_77 ( V_2 -> V_107 == V_108 ) ) {
if ( V_2 -> V_83 == V_109 )
switch ( V_2 -> V_110 ) {
case 0x8025 :
case 0x8070 :
case 0x8088 :
case 0x1626 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_112 )
switch ( V_2 -> V_110 ) {
case 0x80b1 :
case 0x80b2 :
case 0x8093 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_113 )
switch ( V_2 -> V_110 ) {
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
} else if ( F_77 ( V_2 -> V_107 == V_120 ) ) {
if ( V_2 -> V_83 == V_117 )
switch ( V_2 -> V_110 ) {
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
} else if ( F_77 ( V_2 -> V_107 == V_122 ) ) {
if ( V_2 -> V_83 == V_117 )
switch ( V_2 -> V_110 ) {
case 0xC00C :
V_111 = 1 ;
}
} else if ( F_77 ( V_2 -> V_107 == V_123 ) ) {
if ( V_2 -> V_83 == V_117 )
switch ( V_2 -> V_110 ) {
case 0x0058 :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_124 )
switch ( V_2 -> V_110 ) {
case 0xB16C :
V_111 = 1 ;
}
else if ( V_2 -> V_83 == V_125 )
switch ( V_2 -> V_110 ) {
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
static void F_78 ( struct V_1 * V_2 )
{
T_2 V_68 ;
if ( F_79 ( ! V_111 ) )
return;
F_29 ( V_2 , 0xF2 , & V_68 ) ;
if ( V_68 & 0x8 ) {
F_51 ( V_2 , 0xF2 , V_68 & ( ~ 0x8 ) ) ;
F_29 ( V_2 , 0xF2 , & V_68 ) ;
if ( V_68 & 0x8 )
F_6 ( & V_2 -> V_2 , L_57 ,
V_68 ) ;
else
F_6 ( & V_2 -> V_2 , L_58 ) ;
}
}
static void F_80 ( struct V_1 * V_2 )
{
T_1 V_127 ;
if ( F_79 ( ! V_111 ) )
return;
F_81 ( V_128 ) ;
F_10 ( V_2 , 0xF0 , & V_127 ) ;
V_128 = F_82 ( V_127 & 0xFFFFC000 , 0x4000 ) ;
if ( V_128 == NULL )
return;
}
static void F_83 ( struct V_1 * V_2 )
{
T_1 V_68 ;
if ( F_79 ( ! V_111 || ! V_128 ) )
return;
V_68 = F_84 ( V_128 + 0x3418 ) ;
F_85 ( V_68 & 0xFFFFFFF7 , V_128 + 0x3418 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
if ( F_79 ( ! V_111 || ! V_128 ) )
return;
F_87 ( V_128 ) ;
V_128 = NULL ;
F_6 ( & V_2 -> V_2 , L_59 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_80 ( V_2 ) ;
F_83 ( V_2 ) ;
F_86 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
T_3 V_68 = 0 ;
F_5 ( V_2 , 0x77 , & V_68 ) ;
if ( V_68 & 0x10 ) {
F_6 ( & V_2 -> V_2 , L_60 ) ;
F_7 ( V_2 , 0x77 , V_68 & ~ 0x10 ) ;
}
}
static void F_90 ( struct V_1 * V_2 )
{
T_3 V_66 ;
T_2 V_129 ;
F_5 ( V_2 , V_130 , & V_66 ) ;
F_7 ( V_2 , V_130 , V_66 | ( 1 << 6 ) ) ;
F_29 ( V_2 , V_94 , & V_129 ) ;
if ( ( ( V_129 & 0xfff0 ) != 0x0960 ) && ( V_129 != 0x0018 ) ) {
F_7 ( V_2 , V_130 , V_66 ) ;
return;
}
V_2 -> V_83 = V_129 ;
F_89 ( V_2 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
T_3 V_68 ;
int V_131 = 0 ;
if ( F_79 ( V_2 -> V_107 == V_108 ) ) {
if ( V_2 -> V_83 == V_86 )
V_131 = 1 ;
}
if ( ! V_131 )
return;
F_5 ( V_2 , 0x50 , & V_68 ) ;
if ( V_68 & 0xc0 ) {
F_7 ( V_2 , 0x50 , V_68 & ( ~ 0xc0 ) ) ;
F_5 ( V_2 , 0x50 , & V_68 ) ;
if ( V_68 & 0xc0 )
F_6 ( & V_2 -> V_2 , L_61 ,
V_68 ) ;
else
F_6 ( & V_2 -> V_2 , L_62 ) ;
}
}
static void F_92 ( struct V_1 * V_69 )
{
T_1 V_132 , V_133 , V_100 ;
T_3 V_134 ;
if ( F_93 ( V_69 -> V_76 ) )
return;
F_10 ( V_69 , 0x40 , & V_132 ) ;
F_10 ( V_69 , 0x80 , & V_133 ) ;
V_132 &= ~ 0x00CFF302 ;
V_133 &= ~ ( 1 << 24 ) ;
switch ( V_69 -> V_83 ) {
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
F_65 ( V_69 , 0x40 , V_132 ) ;
F_65 ( V_69 , 0x80 , V_133 ) ;
F_5 ( V_69 , V_144 , & V_134 ) ;
V_69 -> V_145 = V_134 & 0x7f ;
V_69 -> V_146 = ! ! ( V_134 & 0x80 ) ;
F_10 ( V_69 , V_147 , & V_100 ) ;
V_69 -> V_100 = V_100 >> 8 ;
}
static void F_94 ( struct V_1 * V_69 )
{
int V_29 ;
if ( ( V_69 -> V_100 >> 8 ) != 0xff00 )
return;
if ( F_95 ( V_69 , 0 ) && F_27 ( V_69 , 0 ) )
F_96 ( & V_148 , & V_69 -> V_31 [ 0 ] ) ;
for ( V_29 = 1 ; V_29 < 6 ; V_29 ++ )
memset ( & V_69 -> V_31 [ V_29 ] , 0 , sizeof( V_69 -> V_31 [ V_29 ] ) ) ;
}
static void F_97 ( struct V_1 * V_69 )
{
F_98 ( V_69 ) ;
V_69 -> V_149 = 1 ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
V_2 -> V_149 = 1 ;
F_49 ( & V_2 -> V_2 , L_63 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
V_150 = 120 ;
V_2 -> V_151 = 1 ;
}
static void F_101 ( struct V_1 * V_2 )
{
if ( V_152 || V_153 )
return;
V_2 -> V_154 = V_155 ;
F_6 ( & V_2 -> V_2 , L_64 ,
V_2 -> V_156 , V_2 -> V_83 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
T_2 V_157 ;
if ( V_152 )
return;
F_29 ( V_2 , V_158 , & V_157 ) ;
V_157 |= V_159 ;
F_51 ( V_2 , V_158 , V_157 ) ;
F_6 ( & V_2 -> V_2 , L_65 ,
V_2 -> V_156 , V_2 -> V_83 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
T_1 V_160 ;
T_3 V_82 ;
if ( V_152 )
return;
F_10 ( V_2 , V_161 , & V_160 ) ;
F_65 ( V_2 , V_161 , V_160 |
V_162 ) ;
for ( V_82 = 0x10 ; V_82 < 0x10 + 32 ; V_82 ++ ) {
F_104 ( V_82 , V_163 ) ;
F_104 ( 0x00 , V_164 ) ;
}
F_65 ( V_2 , V_161 , V_160 ) ;
F_6 ( & V_2 -> V_2 , L_65 ,
V_2 -> V_156 , V_2 -> V_83 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_1 V_160 ;
if ( V_152 )
return;
if ( ( V_2 -> V_22 == V_165 ) ||
( V_2 -> V_22 == V_166 ) )
return;
F_10 ( V_2 , V_167 , & V_160 ) ;
V_160 &= ~ V_168 ;
F_65 ( V_2 , V_167 , V_160 ) ;
F_6 ( & V_2 -> V_2 , L_65 ,
V_2 -> V_156 , V_2 -> V_83 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
T_2 V_157 ;
if ( V_152 )
return;
F_29 ( V_2 , V_169 , & V_157 ) ;
if ( ! V_157 ) {
F_6 ( & V_2 -> V_2 , L_66 ,
V_2 -> V_156 , V_2 -> V_83 ) ;
return;
}
F_51 ( V_2 , V_169 , 0 ) ;
F_6 ( & V_2 -> V_2 , L_65 ,
V_2 -> V_156 , V_2 -> V_83 ) ;
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
unsigned int V_170 ;
if ( V_2 -> V_22 >= 2 )
return;
for ( V_170 = 0 ; V_170 <= 1 ; V_170 ++ )
if ( F_27 ( V_2 , V_170 ) == 0x80 &&
( F_95 ( V_2 , V_170 ) & 0x80 ) ) {
struct V_31 * V_32 = & V_2 -> V_31 [ V_170 ] ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_170 ) ;
V_32 -> V_33 |= V_38 ;
V_32 -> V_37 = 0 ;
V_32 -> V_36 = 0xff ;
}
}
static void F_109 ( struct V_1 * V_2 )
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
F_6 ( & V_2 -> V_2 , L_68 ,
V_2 -> V_83 , V_171 , V_172 ) ;
V_2 -> V_100 = ( V_179 << 8 ) |
( V_2 -> V_100 & 0xff ) ;
}
}
}
static void F_110 ( struct V_1 * V_2 )
{
T_2 V_70 , V_180 ;
T_3 T_4 * V_181 ;
T_3 V_182 ;
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
F_29 ( V_2 , V_71 , & V_70 ) ;
if ( ! ( V_70 & V_183 ) || ! F_95 ( V_2 , 0 ) )
return;
if ( V_2 -> V_184 ) {
F_29 ( V_2 , V_2 -> V_184 + V_185 , & V_180 ) ;
if ( ( V_180 & V_186 ) != V_187 )
return;
}
V_181 = F_111 ( F_95 ( V_2 , 0 ) , 8 ) ;
if ( ! V_181 ) {
F_49 ( & V_2 -> V_2 , L_69 ) ;
return;
}
V_182 = F_112 ( V_181 + 3 ) ;
if ( V_182 == 0 ) {
F_49 ( & V_2 -> V_2 , L_70 ) ;
F_113 ( 1 , V_181 + 3 ) ;
}
F_87 ( V_181 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_71 ) ;
F_115 ( V_2 , V_188 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
if ( V_2 -> V_100 == V_189 ) {
F_6 ( & V_2 -> V_2 , L_72 ) ;
V_2 -> V_100 = V_190 ;
}
}
static void F_117 ( struct V_1 * V_2 )
{
T_2 V_191 ;
F_29 ( V_2 , 0x40 , & V_191 ) ;
if ( V_191 & 0x200 ) {
F_6 ( & V_2 -> V_2 , L_73 ) ;
V_2 -> V_192 = 1 ;
}
}
static void F_118 ( struct V_1 * V_2 )
{
T_5 V_193 ;
if ( F_5 ( V_2 , 0xf41 , & V_193 ) == 0 ) {
if ( ! ( V_193 & 0x20 ) ) {
F_7 ( V_2 , 0xf41 , V_193 | 0x20 ) ;
F_6 ( & V_2 -> V_2 , L_74 ) ;
}
}
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_1 * V_18 = F_4 ( V_20 ,
V_194 , NULL ) ;
T_5 V_193 ;
V_18 = F_4 ( V_20 , V_194 , V_18 ) ;
if ( ! V_18 )
return;
F_17 ( V_18 ) ;
if ( F_5 ( V_2 , 0x76 , & V_193 ) == 0 ) {
if ( V_193 & 0x40 ) {
F_7 ( V_2 , 0x76 , V_193 ^ 0x40 ) ;
F_6 ( & V_2 -> V_2 , L_75 ) ;
}
}
if ( F_5 ( V_2 , 0x72 , & V_193 ) == 0 ) {
if ( V_193 != 0 ) {
F_7 ( V_2 , 0x72 , 0x0 ) ;
F_7 ( V_2 , 0x75 , 0x1 ) ;
F_7 ( V_2 , 0x77 , 0x0 ) ;
F_6 ( & V_2 -> V_2 , L_76 ) ;
}
}
}
static void F_120 ( struct V_1 * V_2 )
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
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_10 ( V_2 , 0xf4 , & V_15 ) ;
if ( V_15 == 0x05719000 ) {
int V_202 = F_122 ( V_2 ) ;
if ( V_202 > 2048 )
F_123 ( V_2 , 2048 ) ;
}
}
static void F_124 ( struct V_1 * V_2 )
{
T_3 V_66 ;
if ( F_5 ( V_2 , 0xF4 , & V_66 ) == 0 && ! ( V_66 & 0x02 ) ) {
F_6 ( & V_2 -> V_2 , L_77 ) ;
F_7 ( V_2 , 0xF4 , V_66 | 0x02 ) ;
}
}
static void F_125 ( struct V_1 * V_2 )
{
if ( V_203 ) {
F_65 ( V_2 , 0x98 , 0x1 ) ;
F_126 ( 50 ) ;
}
}
static void F_127 ( struct V_1 * V_2 )
{
F_128 () ;
F_49 ( & V_2 -> V_2 , L_78 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 ) {
F_49 ( & V_2 -> V_2 , L_79 ) ;
V_2 -> V_79 -> V_80 |= V_204 ;
}
}
static void F_130 ( struct V_1 * V_205 )
{
struct V_1 * V_206 ;
V_206 = F_131 ( V_205 -> V_48 , F_132 ( 1 , 0 ) ) ;
if ( V_206 ) {
if ( V_206 -> V_83 == 0x9602 )
F_129 ( V_206 ) ;
F_17 ( V_206 ) ;
}
}
static int F_133 ( struct V_1 * V_2 )
{
int V_207 , V_208 = 48 ;
V_207 = F_134 ( V_2 , V_209 ) ;
while ( V_207 && V_208 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_207 + V_210 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_80 ,
V_33 & V_211 ?
L_81 : L_82 ) ;
return ( V_33 & V_211 ) != 0 ;
}
V_207 = F_135 ( V_2 , V_207 ,
V_209 ) ;
}
return 0 ;
}
static void F_136 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 && ! F_133 ( V_2 ) ) {
F_49 ( & V_2 -> V_2 , L_79 ) ;
V_2 -> V_79 -> V_80 |= V_204 ;
}
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_1 * V_69 ;
if ( ! V_2 -> V_79 )
return;
V_69 = F_131 ( V_2 -> V_48 , 0 ) ;
if ( ! V_69 )
return;
if ( ! F_133 ( V_2 ) && ! F_133 ( V_69 ) ) {
F_49 ( & V_2 -> V_2 , L_79 ) ;
V_2 -> V_79 -> V_80 |= V_204 ;
}
F_17 ( V_69 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
int V_207 , V_208 = 48 ;
V_207 = F_134 ( V_2 , V_209 ) ;
while ( V_207 && V_208 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_207 + V_210 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_83 ) ;
F_7 ( V_2 , V_207 + V_210 ,
V_33 | V_211 ) ;
}
V_207 = F_135 ( V_2 , V_207 ,
V_209 ) ;
}
}
static void F_139 ( struct V_1 * V_2 )
{
const char * V_212 = F_140 ( V_213 ) ;
if ( V_212 &&
( strstr ( V_212 , L_84 ) ||
strstr ( V_212 , L_85 ) ) ) {
F_6 ( & V_2 -> V_2 , L_86 ) ;
V_2 -> V_149 = 1 ;
}
}
static void F_141 ( struct V_1 * V_2 )
{
T_1 V_214 ;
if ( ! F_142 ( V_2 , V_215 ) )
return;
F_10 ( V_2 , 0x74 , & V_214 ) ;
if ( V_214 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_143 ( V_216 L_87 ) ;
V_214 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_65 ( V_2 , 0x74 , V_214 ) ;
}
}
static int F_144 ( struct V_1 * V_2 )
{
int V_207 , V_208 = 48 ;
int V_217 = 0 ;
V_207 = F_134 ( V_2 , V_209 ) ;
while ( V_207 && V_208 -- ) {
T_3 V_33 ;
if ( V_217 < 1 )
V_217 = 1 ;
if ( F_5 ( V_2 , V_207 + V_210 ,
& V_33 ) == 0 ) {
if ( V_33 & V_211 ) {
if ( V_217 < 2 ) {
V_217 = 2 ;
break;
}
}
}
V_207 = F_135 ( V_2 , V_207 ,
V_209 ) ;
}
return V_217 ;
}
static int F_145 ( struct V_1 * V_205 )
{
struct V_1 * V_2 ;
int V_207 ;
int V_29 , V_218 ;
int V_217 = 0 ;
V_218 = V_205 -> V_76 >> 3 ;
for ( V_29 = V_218 + 1 ; V_29 < 0x20 ; V_29 ++ ) {
V_2 = F_131 ( V_205 -> V_48 , F_132 ( V_29 , 0 ) ) ;
if ( ! V_2 )
continue;
V_207 = F_134 ( V_2 , V_219 ) ;
if ( V_207 != 0 ) {
F_17 ( V_2 ) ;
break;
}
if ( F_144 ( V_2 ) ) {
V_217 = 1 ;
F_17 ( V_2 ) ;
break;
}
F_17 ( V_2 ) ;
}
return V_217 ;
}
static int F_146 ( struct V_1 * V_2 )
{
int V_207 , V_220 ;
int V_36 = 0 ;
T_2 V_33 , V_221 ;
V_207 = F_134 ( V_2 , V_219 ) ;
if ( ! V_207 )
goto V_222;
F_29 ( V_2 , V_207 + V_223 , & V_33 ) ;
V_220 = ( ( V_33 >> 10 ) & 1 ) ?
V_224 : V_225 ;
F_29 ( V_2 , V_207 + V_220 , & V_221 ) ;
if ( V_221 & ( 1 << 6 ) )
V_36 = 1 ;
V_222:
return V_36 ;
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_1 * V_205 ;
int V_207 ;
int V_29 , V_218 ;
int V_217 = 0 ;
V_218 = V_2 -> V_76 >> 3 ;
for ( V_29 = V_218 ; V_29 >= 0 ; V_29 -- ) {
V_205 = F_131 ( V_2 -> V_48 , F_132 ( V_29 , 0 ) ) ;
if ( ! V_205 )
continue;
V_207 = F_134 ( V_205 , V_219 ) ;
if ( V_207 != 0 ) {
V_217 = 1 ;
break;
}
F_17 ( V_205 ) ;
}
if ( ! V_217 )
return;
if ( V_205 == V_2 && F_146 ( V_205 ) &&
F_145 ( V_205 ) )
goto V_222;
if ( F_133 ( V_205 ) )
goto V_222;
F_138 ( V_2 ) ;
V_222:
F_17 ( V_205 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
int V_207 , V_208 = 48 ;
V_207 = F_134 ( V_2 , V_209 ) ;
while ( V_207 && V_208 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_207 + V_210 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_88 ) ;
F_7 ( V_2 , V_207 + V_210 ,
V_33 & ~ V_211 ) ;
}
V_207 = F_135 ( V_2 , V_207 ,
V_209 ) ;
}
}
static void F_149 ( struct V_1 * V_2 , int V_226 )
{
struct V_1 * V_205 ;
int V_207 ;
int V_217 ;
if ( ! F_150 () )
return;
V_217 = F_144 ( V_2 ) ;
if ( V_217 == 0 )
return;
V_205 = F_151 ( 0 , F_132 ( 0 , 0 ) ) ;
if ( V_205 == NULL ) {
F_49 ( & V_2 -> V_2 , L_89 ) ;
return;
}
V_207 = F_134 ( V_205 , V_219 ) ;
if ( V_207 != 0 ) {
if ( V_217 == 1 ) {
if ( V_226 )
F_138 ( V_2 ) ;
else
F_147 ( V_2 ) ;
}
goto V_222;
}
if ( V_217 == 1 )
goto V_222;
F_148 ( V_2 ) ;
V_222:
F_17 ( V_205 ) ;
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
V_2 -> V_104 |= V_227 ;
}
static void F_155 ( struct V_1 * V_2 )
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
static void F_156 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 < 0x18 ) {
F_6 ( & V_2 -> V_2 , L_90 ) ;
V_2 -> V_104 |= V_227 ;
}
}
static void F_157 ( struct V_1 * V_2 )
{
V_2 -> V_230 = 1 ;
}
static void F_158 ( struct V_1 * V_2 )
{
T_3 V_231 ;
T_3 V_232 ;
T_3 V_233 ;
if ( F_93 ( V_2 -> V_76 ) )
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
F_159 ( & V_2 -> V_2 , L_91 ) ;
F_159 ( & V_2 -> V_2 , L_92 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
T_3 V_231 ;
T_3 V_233 ;
if ( F_93 ( V_2 -> V_76 ) )
return;
if ( V_2 -> V_83 == V_234 ||
V_2 -> V_83 == V_235 ) {
F_7 ( V_2 , 0xf9 , 0xfc ) ;
F_7 ( V_2 , 0x150 , 0x10 ) ;
F_7 ( V_2 , 0xf9 , 0x00 ) ;
F_7 ( V_2 , 0xfc , 0x01 ) ;
F_7 ( V_2 , 0xe1 , 0x32 ) ;
F_7 ( V_2 , 0xfc , 0x00 ) ;
F_159 ( & V_2 -> V_2 , L_93 ) ;
}
F_5 ( V_2 , 0xCB , & V_233 ) ;
if ( V_233 & 0x02 )
return;
F_5 ( V_2 , 0xCA , & V_231 ) ;
F_7 ( V_2 , 0xCA , 0x57 ) ;
F_7 ( V_2 , 0xCB , V_233 | 0x02 ) ;
F_7 ( V_2 , 0xCA , V_231 ) ;
F_159 ( & V_2 -> V_2 , L_94 ) ;
F_159 ( & V_2 -> V_2 , L_92 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
T_1 V_236 ;
F_10 ( V_2 , V_237 , & V_236 ) ;
F_65 ( V_2 , V_237 , V_236 | V_238 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_95 ) ;
V_2 -> V_100 = V_239 ;
}
static void F_163 ( struct V_1 * V_2 )
{
V_2 -> V_240 = 1 ;
}
static void F_164 ( struct V_1 * V_2 )
{
int V_241 ;
T_2 V_242 ;
if ( V_243 == V_244 )
return;
V_241 = F_29 ( V_2 , 0x48 , & V_242 ) ;
if ( V_241 ) {
F_165 ( & V_2 -> V_2 , L_96 ) ;
return;
}
if ( ! ( V_242 & ( 1 << 10 ) ) )
return;
V_242 &= ~ ( 1 << 10 ) ;
V_241 = F_51 ( V_2 , 0x48 , V_242 ) ;
if ( V_241 ) {
F_165 ( & V_2 -> V_2 , L_97 ) ;
return;
}
F_166 ( L_98 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
int V_245 ;
T_3 V_68 ;
V_245 = F_5 ( V_2 , 0x00D0 , & V_68 ) ;
if ( V_245 )
return;
V_2 -> V_31 [ 2 ] . V_36 = V_2 -> V_31 [ 2 ] . V_37 + ( ( V_246 ) 1 << V_68 ) - 1 ;
V_245 = F_5 ( V_2 , 0x00D1 , & V_68 ) ;
if ( V_245 )
return;
V_2 -> V_31 [ 4 ] . V_36 = V_2 -> V_31 [ 4 ] . V_37 + ( ( V_246 ) 1 << V_68 ) - 1 ;
}
static T_6 F_168 ( struct V_1 * V_2 ,
void (* F_169)( struct V_1 * V_2 ) )
{
T_6 V_247 = F_170 ( 0 , 0 ) ;
F_171 ( & V_2 -> V_2 , L_99 , F_169 ) ;
if ( V_248 ) {
F_172 ( L_100 ,
F_169 , F_173 ( V_249 ) , F_174 ( & V_2 -> V_2 ) ) ;
V_247 = F_175 () ;
}
return V_247 ;
}
static void F_176 ( struct V_1 * V_2 , T_6 V_247 ,
void (* F_169)( struct V_1 * V_2 ) )
{
T_6 V_250 , V_251 ;
unsigned long long V_252 ;
if ( V_248 ) {
V_251 = F_175 () ;
V_250 = F_177 ( V_251 , V_247 ) ;
V_252 = ( unsigned long long ) F_178 ( V_250 ) >> 10 ;
F_172 ( L_101 ,
F_169 , V_252 , F_174 ( & V_2 -> V_2 ) ) ;
}
}
static void F_179 ( struct V_1 * V_2 )
{
void T_4 * V_253 = F_180 ( V_2 , 0 , 0 ) ;
if ( V_253 == NULL ) {
F_49 ( & V_2 -> V_2 , L_102 ) ;
return;
}
if ( F_84 ( V_253 + V_254 ) != 0 ) {
F_49 ( & V_2 -> V_2 , L_103 ) ;
F_85 ( 0 , V_253 + V_254 ) ;
}
F_181 ( V_2 , V_253 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
V_2 -> V_255 = 0 ;
}
static void F_183 ( struct V_1 * V_2 )
{
V_2 -> V_256 = 1 ;
}
static void F_184 ( struct V_1 * V_2 )
{
T_7 V_257 , V_258 , V_259 , V_260 ;
if ( ! F_185 ( V_261 , L_104 ) )
return;
if ( F_186 ( V_2 ) != V_262 )
return;
V_257 = F_187 ( & V_2 -> V_2 ) ;
if ( ! V_257 )
return;
if ( F_188 ( F_189 ( V_257 , L_105 , & V_258 ) )
|| F_188 ( F_189 ( V_257 , L_106 , & V_259 ) )
|| F_188 ( F_189 ( V_257 , L_107 , & V_260 ) ) )
return;
F_6 ( & V_2 -> V_2 , L_108 ) ;
F_190 ( V_258 , NULL , 1 ) ;
F_190 ( V_259 , NULL , 0 ) ;
F_191 ( 300 ) ;
F_190 ( V_260 , NULL , 0 ) ;
F_190 ( V_258 , NULL , 0 ) ;
F_190 ( V_260 , NULL , 0 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_1 * V_263 = NULL ;
struct V_1 * V_264 = NULL ;
if ( ! F_185 ( V_261 , L_104 ) )
return;
if ( F_186 ( V_2 ) != V_265 )
return;
V_263 = F_131 ( V_2 -> V_48 , 0x0 ) ;
if ( V_263 == V_2 )
goto V_222;
if ( ! V_263 || ! V_263 -> V_79 )
goto V_222;
V_264 = F_131 ( V_263 -> V_79 , 0x0 ) ;
if ( ! V_264 )
goto V_222;
if ( V_264 -> V_156 != V_7
|| ( V_264 -> V_83 != 0x1547 && V_264 -> V_83 != 0x156c )
|| V_264 -> V_107 != 0x2222
|| V_264 -> V_110 != 0x1111 )
goto V_222;
F_6 ( & V_2 -> V_2 , L_109 ) ;
F_193 ( & V_2 -> V_2 , & V_264 -> V_2 ) ;
V_222:
F_17 ( V_264 ) ;
F_17 ( V_263 ) ;
}
static void F_194 ( struct V_1 * V_2 , struct V_266 * V_267 ,
struct V_266 * V_36 )
{
T_6 V_247 ;
for (; V_267 < V_36 ; V_267 ++ )
if ( ( V_267 -> V_100 == ( T_1 ) ( V_2 -> V_100 >> V_267 -> V_268 ) ||
V_267 -> V_100 == ( T_1 ) V_269 ) &&
( V_267 -> V_156 == V_2 -> V_156 ||
V_267 -> V_156 == ( T_2 ) V_269 ) &&
( V_267 -> V_83 == V_2 -> V_83 ||
V_267 -> V_83 == ( T_2 ) V_269 ) ) {
V_247 = F_168 ( V_2 , V_267 -> V_270 ) ;
V_267 -> V_270 ( V_2 ) ;
F_176 ( V_2 , V_247 , V_267 -> V_270 ) ;
}
}
void F_195 ( enum V_271 V_272 , struct V_1 * V_2 )
{
struct V_266 * V_37 , * V_36 ;
switch ( V_272 ) {
case V_273 :
V_37 = V_274 ;
V_36 = V_275 ;
break;
case V_276 :
V_37 = V_277 ;
V_36 = V_278 ;
break;
case V_279 :
if ( ! V_280 )
return;
V_37 = V_281 ;
V_36 = V_282 ;
break;
case V_283 :
V_37 = V_284 ;
V_36 = V_285 ;
break;
case V_286 :
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
default:
return;
}
F_194 ( V_2 , V_37 , V_36 ) ;
}
static int T_8 F_196 ( void )
{
struct V_1 * V_2 = NULL ;
T_3 V_298 = 0 ;
T_3 V_73 ;
if ( V_299 )
F_143 ( V_300 L_110 ,
V_299 << 2 ) ;
V_280 = true ;
F_197 (dev) {
F_195 ( V_279 , V_2 ) ;
if ( ! V_299 ) {
F_5 ( V_2 , V_301 , & V_73 ) ;
if ( ! V_298 )
V_298 = V_73 ;
if ( ! V_73 || V_298 == V_73 )
continue;
F_143 ( V_300 L_111 ,
V_298 << 2 , V_73 << 2 ,
V_302 << 2 ) ;
V_299 = V_302 ;
}
}
if ( ! V_299 ) {
F_143 ( V_300 L_112 ,
V_298 << 2 , V_302 << 2 ) ;
V_299 = V_298 ? V_298 : V_302 ;
}
return 0 ;
}
static int F_198 ( struct V_1 * V_2 , int V_303 )
{
int V_207 ;
if ( V_2 -> V_100 == V_304 ) {
V_207 = F_142 ( V_2 , V_305 ) ;
if ( ! V_207 )
return - V_306 ;
if ( V_303 )
return 0 ;
F_7 ( V_2 , V_207 + 0x4 , 1 ) ;
F_191 ( 100 ) ;
return 0 ;
} else {
return - V_306 ;
}
}
static int F_199 ( struct V_1 * V_2 , int V_303 )
{
if ( V_303 )
return 0 ;
if ( ! F_200 ( V_2 ) )
F_165 ( & V_2 -> V_2 , L_113 ) ;
F_201 ( V_2 , V_307 , V_308 ) ;
F_191 ( 100 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 , int V_303 )
{
void T_4 * V_309 ;
unsigned long V_310 ;
T_1 V_68 ;
if ( V_303 )
return 0 ;
V_309 = F_180 ( V_2 , 0 , 0 ) ;
if ( ! V_309 )
return - V_311 ;
F_203 ( 0x00000002 , V_309 + V_312 ) ;
F_203 ( 0x00000005 , V_309 + V_313 ) ;
V_68 = F_204 ( V_309 + V_314 ) & 0xfffffffe ;
F_203 ( V_68 , V_309 + V_314 ) ;
V_310 = V_315 + F_205 ( V_316 ) ;
do {
V_68 = F_204 ( V_309 + V_317 ) ;
if ( ( V_68 & 0xb0000000 ) == 0 )
goto V_318;
F_191 ( 10 ) ;
} while ( F_206 ( V_315 , V_310 ) );
F_49 ( & V_2 -> V_2 , L_114 ) ;
V_318:
F_203 ( 0x00000002 , V_309 + V_319 ) ;
F_181 ( V_2 , V_309 ) ;
return 0 ;
}
static int F_207 ( struct V_1 * V_2 , int V_303 )
{
T_2 V_320 ;
T_2 V_321 ;
if ( ( V_2 -> V_83 & 0xf000 ) != 0x4000 )
return - V_306 ;
if ( V_303 )
return 0 ;
F_29 ( V_2 , V_71 , & V_320 ) ;
F_51 ( V_2 , V_71 ,
V_320 | V_322 ) ;
F_208 ( V_2 ) ;
F_29 ( V_2 , V_2 -> V_323 + V_324 , & V_321 ) ;
if ( ( V_321 & V_325 ) == 0 )
F_51 ( V_2 , V_2 -> V_323 + V_324 ,
V_321 |
V_325 |
V_326 ) ;
if ( ! F_200 ( V_2 ) )
F_165 ( & V_2 -> V_2 , L_113 ) ;
F_201 ( V_2 , V_307 , V_308 ) ;
F_191 ( 100 ) ;
F_209 ( V_2 ) ;
F_51 ( V_2 , V_71 , V_320 ) ;
return 0 ;
}
int F_210 ( struct V_1 * V_2 , int V_303 )
{
const struct V_327 * V_29 ;
for ( V_29 = V_327 ; V_29 -> V_328 ; V_29 ++ ) {
if ( ( V_29 -> V_156 == V_2 -> V_156 ||
V_29 -> V_156 == ( T_2 ) V_269 ) &&
( V_29 -> V_83 == V_2 -> V_83 ||
V_29 -> V_83 == ( T_2 ) V_269 ) )
return V_29 -> V_328 ( V_2 , V_303 ) ;
}
return - V_306 ;
}
static void F_211 ( struct V_1 * V_2 )
{
if ( F_93 ( V_2 -> V_76 ) != 0 ) {
V_2 -> V_329 = F_132 ( F_60 ( V_2 -> V_76 ) , 0 ) ;
V_2 -> V_104 |= V_330 ;
}
}
static void F_212 ( struct V_1 * V_2 )
{
if ( F_93 ( V_2 -> V_76 ) != 1 ) {
V_2 -> V_329 = F_132 ( F_60 ( V_2 -> V_76 ) , 1 ) ;
V_2 -> V_104 |= V_330 ;
}
}
static void F_213 ( struct V_1 * V_69 )
{
if ( ! F_214 ( V_69 -> V_48 ) &&
V_69 -> V_145 == V_331 &&
! F_215 ( V_69 ) && F_215 ( V_69 -> V_48 -> V_332 ) &&
F_186 ( V_69 -> V_48 -> V_332 ) != V_333 )
V_69 -> V_104 |= V_334 ;
}
static int F_216 ( struct V_1 * V_2 , T_2 V_335 )
{
#ifdef F_217
struct V_336 * V_337 = NULL ;
T_9 V_338 ;
if ( ! V_2 -> V_146 || ! F_214 ( V_2 -> V_48 ) )
return - V_339 ;
V_338 = F_218 ( L_115 , 0 , & V_337 ) ;
if ( F_188 ( V_338 ) )
return - V_339 ;
V_335 &= ( V_340 | V_341 | V_342 | V_343 ) ;
return V_335 & ~ ( V_340 | V_341 ) ? 0 : 1 ;
#else
return - V_339 ;
#endif
}
static bool F_219 ( struct V_1 * V_2 )
{
int V_29 ;
if ( ! F_215 ( V_2 ) || F_186 ( V_2 ) != V_344 )
return false ;
for ( V_29 = 0 ; V_29 < F_220 ( V_345 ) ; V_29 ++ )
if ( V_345 [ V_29 ] == V_2 -> V_83 )
return true ;
return false ;
}
static int F_221 ( struct V_1 * V_2 , T_2 V_335 )
{
T_2 V_33 = V_2 -> V_104 & V_346 ?
V_347 : 0 ;
if ( ! F_219 ( V_2 ) )
return - V_306 ;
return V_335 & ~ V_33 ? 0 : 1 ;
}
static int F_222 ( struct V_1 * V_2 , T_2 V_335 )
{
V_335 &= ~ ( V_348 | V_349 | V_340 |
V_341 | V_350 | V_343 ) ;
return V_335 ? 0 : 1 ;
}
int F_223 ( struct V_1 * V_2 , T_2 V_335 )
{
const struct V_351 * V_29 ;
int V_352 ;
for ( V_29 = V_351 ; V_29 -> V_353 ; V_29 ++ ) {
if ( ( V_29 -> V_156 == V_2 -> V_156 ||
V_29 -> V_156 == ( T_2 ) V_269 ) &&
( V_29 -> V_83 == V_2 -> V_83 ||
V_29 -> V_83 == ( T_2 ) V_269 ) ) {
V_352 = V_29 -> V_353 ( V_2 , V_335 ) ;
if ( V_352 >= 0 )
return V_352 ;
}
}
return - V_306 ;
}
static int F_224 ( struct V_1 * V_2 )
{
T_1 V_127 , V_354 , V_355 ;
void T_4 * V_356 ;
F_225 ( V_2 -> V_48 , F_132 ( 31 , 0 ) ,
V_357 , & V_127 ) ;
if ( ! ( V_127 & V_358 ) )
return - V_359 ;
V_356 = F_82 ( V_127 & V_360 ,
F_226 ( V_361 ) ) ;
if ( ! V_356 )
return - V_311 ;
V_354 = F_84 ( V_356 + V_362 ) ;
V_354 &= V_363 | V_364 ;
if ( V_354 != ( V_363 | V_364 ) ) {
V_355 = F_84 ( V_356 + V_361 ) ;
if ( V_355 & V_365 ) {
F_6 ( & V_2 -> V_2 , L_116 ) ;
V_355 &= ~ V_365 ;
F_85 ( V_355 , V_356 + V_361 ) ;
}
}
F_87 ( V_356 ) ;
return 0 ;
}
static void F_227 ( struct V_1 * V_2 )
{
T_1 V_366 ;
F_10 ( V_2 , V_367 , & V_366 ) ;
if ( ! ( V_366 & V_368 ) ) {
F_6 ( & V_2 -> V_2 , L_117 ) ;
V_366 |= V_368 ;
F_51 ( V_2 , V_367 , V_366 ) ;
}
}
static int F_228 ( struct V_1 * V_2 )
{
if ( ! F_219 ( V_2 ) )
return - V_306 ;
if ( F_224 ( V_2 ) ) {
F_49 ( & V_2 -> V_2 , L_118 ) ;
return 0 ;
}
F_227 ( V_2 ) ;
V_2 -> V_104 |= V_346 ;
F_6 ( & V_2 -> V_2 , L_119 ) ;
return 0 ;
}
void F_229 ( struct V_1 * V_2 )
{
const struct V_369 * V_29 ;
int V_352 ;
for ( V_29 = V_369 ; V_29 -> V_370 ; V_29 ++ ) {
if ( ( V_29 -> V_156 == V_2 -> V_156 ||
V_29 -> V_156 == ( T_2 ) V_269 ) &&
( V_29 -> V_83 == V_2 -> V_83 ||
V_29 -> V_83 == ( T_2 ) V_269 ) ) {
V_352 = V_29 -> V_370 ( V_2 ) ;
if ( V_352 >= 0 )
return;
}
}
}
