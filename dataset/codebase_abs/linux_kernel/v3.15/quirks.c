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
V_30 -> V_33 |= V_34 ;
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0x3ffffff ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 , 0 ) != 8 ) {
struct V_29 * V_35 = & V_2 -> V_29 [ 0 ] ;
V_35 -> V_32 = V_35 -> V_31 + 8 - 1 ;
F_6 ( & V_2 -> V_2 , L_8
L_9 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , int V_36 ,
unsigned V_37 , int V_38 , const char * V_39 )
{
T_2 V_40 ;
struct V_41 V_42 ;
struct V_29 * V_35 = V_2 -> V_29 + V_38 ;
F_27 ( V_2 , V_36 , & V_40 ) ;
V_40 &= ~ ( V_37 - 1 ) ;
if ( ! V_40 )
return;
V_35 -> V_39 = F_28 ( V_2 ) ;
V_35 -> V_33 = V_43 ;
V_42 . V_31 = V_40 ;
V_42 . V_32 = V_40 + V_37 - 1 ;
F_29 ( V_2 -> V_44 , V_35 , & V_42 ) ;
if ( ! F_30 ( V_2 , V_38 ) )
F_6 ( & V_2 -> V_2 , L_10 , V_35 , V_39 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_11 ) ;
F_32 ( 0x3b0 , 0x0C , L_12 ) ;
F_32 ( 0x3d3 , 0x01 , L_12 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_26 ( V_2 , 0xE0 , 64 , V_45 , L_13 ) ;
F_26 ( V_2 , 0xE2 , 32 , V_45 + 1 , L_14 ) ;
}
static void F_34 ( struct V_1 * V_2 , const char * V_39 , unsigned int V_36 , unsigned int V_46 )
{
T_1 V_47 ;
T_1 V_48 , V_37 , V_49 ;
F_10 ( V_2 , V_36 , & V_47 ) ;
if ( ( V_47 & V_46 ) != V_46 )
return;
V_48 = ( V_47 >> 16 ) & 15 ;
V_49 = V_47 & 0xffff ;
V_37 = 16 ;
for (; ; ) {
unsigned V_50 = V_37 >> 1 ;
if ( ( V_50 & V_48 ) == V_50 )
break;
V_37 = V_50 ;
}
V_49 &= - V_37 ;
F_6 ( & V_2 -> V_2 , L_15 , V_39 , V_49 , V_49 + V_37 - 1 ) ;
}
static void F_35 ( struct V_1 * V_2 , const char * V_39 , unsigned int V_36 , unsigned int V_46 )
{
T_1 V_47 ;
T_1 V_48 , V_37 , V_49 ;
F_10 ( V_2 , V_36 , & V_47 ) ;
if ( ( V_47 & V_46 ) != V_46 )
return;
V_49 = V_47 & 0xffff0000 ;
V_48 = ( V_47 & 0x3f ) << 16 ;
V_37 = 128 << 16 ;
for (; ; ) {
unsigned V_50 = V_37 >> 1 ;
if ( ( V_50 & V_48 ) == V_50 )
break;
V_37 = V_50 ;
}
V_49 &= - V_37 ;
F_6 ( & V_2 -> V_2 , L_16 , V_39 , V_49 , V_49 + V_37 - 1 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_51 ;
F_26 ( V_2 , 0x40 , 64 , V_45 , L_17 ) ;
F_26 ( V_2 , 0x90 , 16 , V_45 + 1 , L_18 ) ;
F_10 ( V_2 , 0x5c , & V_51 ) ;
F_34 ( V_2 , L_19 , 0x60 , 3 << 21 ) ;
F_34 ( V_2 , L_20 , 0x64 , 3 << 21 ) ;
if ( V_51 & ( 1 << 29 ) ) {
F_34 ( V_2 , L_21 , 0x68 , 1 << 20 ) ;
F_35 ( V_2 , L_22 , 0x6c , 1 << 7 ) ;
}
if ( V_51 & ( 1 << 30 ) ) {
F_34 ( V_2 , L_23 , 0x70 , 1 << 20 ) ;
F_35 ( V_2 , L_24 , 0x74 , 1 << 7 ) ;
}
F_34 ( V_2 , L_25 , 0x78 , 1 << 20 ) ;
F_34 ( V_2 , L_26 , 0x7c , 1 << 20 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
T_3 V_46 ;
F_5 ( V_2 , V_52 , & V_46 ) ;
if ( V_46 & V_53 )
F_26 ( V_2 , V_54 , 128 , V_45 ,
L_27 ) ;
F_5 ( V_2 , V_55 , & V_46 ) ;
if ( V_46 & V_56 )
F_26 ( V_2 , V_57 , 64 , V_45 + 1 ,
L_28 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_3 V_46 ;
F_5 ( V_2 , V_52 , & V_46 ) ;
if ( V_46 & V_58 )
F_26 ( V_2 , V_54 , 128 , V_45 ,
L_29 ) ;
F_5 ( V_2 , V_59 , & V_46 ) ;
if ( V_46 & V_60 )
F_26 ( V_2 , V_61 , 64 , V_45 + 1 ,
L_30 ) ;
}
static void F_39 ( struct V_1 * V_2 , unsigned V_62 , const char * V_39 , int V_63 )
{
T_1 V_64 ;
T_1 V_37 , V_49 ;
F_10 ( V_2 , V_62 , & V_64 ) ;
if ( ! ( V_64 & 1 ) )
return;
V_49 = V_64 & 0xfffc ;
if ( V_63 ) {
V_37 = 16 ;
} else {
V_37 = 128 ;
}
V_49 &= ~ ( V_37 - 1 ) ;
F_6 ( & V_2 -> V_2 , L_15 , V_39 , V_49 , V_49 + V_37 - 1 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_39 ( V_2 , 0x84 , L_31 , 0 ) ;
F_39 ( V_2 , 0x88 , L_32 , 1 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned V_62 , const char * V_39 )
{
T_1 V_64 ;
T_1 V_48 , V_49 ;
F_10 ( V_2 , V_62 , & V_64 ) ;
if ( ! ( V_64 & 1 ) )
return;
V_49 = V_64 & 0xfffc ;
V_48 = ( V_64 >> 16 ) & 0xfc ;
V_48 |= 3 ;
F_6 ( & V_2 -> V_2 , L_33 , V_39 , V_49 , V_48 ) ;
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
if ( V_2 -> V_22 & 0x10 )
F_26 ( V_2 , 0x48 , 256 , V_45 ,
L_38 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_26 ( V_2 , 0x70 , 128 , V_45 + 1 ,
L_39 ) ;
F_26 ( V_2 , 0x90 , 16 , V_45 + 2 , L_40 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_26 ( V_2 , 0x88 , 128 , V_45 , L_41 ) ;
F_26 ( V_2 , 0xd0 , 16 , V_45 + 1 , L_42 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_1 * V_65 ;
T_2 V_66 ;
F_47 ( & V_2 -> V_2 , L_43
L_44 ) ;
F_48 (pdev, &dev->subordinate->devices, bus_list) {
F_27 ( V_65 , V_67 , & V_66 ) ;
if ( V_66 & V_68 )
F_49 ( V_65 , V_67 , V_66 & ~ V_68 ) ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
T_3 V_69 ;
if ( V_70 < 1 )
V_69 = 0 ;
else
V_69 = 0x1f ;
F_6 ( & V_2 -> V_2 , L_45 ,
V_69 == 0 ? L_46 : L_47 ) ;
F_7 ( V_2 , 0x58 , V_69 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_3 V_71 ;
#define F_52 8
F_5 ( V_2 , 0x5B , & V_71 ) ;
if ( ! ( V_71 & F_52 ) ) {
F_6 ( & V_2 -> V_2 , L_48 ) ;
F_7 ( V_2 , 0x5B , V_71 | F_52 ) ;
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
if ( V_2 -> V_72 == 0 && V_2 -> V_44 -> V_73 == 0 )
V_74 = 1 ;
}
static void F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 && V_2 -> V_22 <= 0x12 ) {
F_6 ( & V_2 -> V_2 , L_51
L_52 , V_2 -> V_22 ) ;
V_2 -> V_75 -> V_76 |= V_77 ;
}
}
static void F_56 ( struct V_1 * V_5 )
{
T_3 V_78 ;
F_5 ( V_5 , 0x42 , & V_78 ) ;
V_78 &= 0xf ;
if ( V_78 && ( V_78 != 2 ) )
V_5 -> V_78 = V_78 ;
}
static void F_57 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_79 ) {
case V_21 :
V_80 = F_58 ( V_2 -> V_72 ) ;
V_81 = F_58 ( V_2 -> V_72 ) ;
break;
case V_82 :
case V_83 :
V_80 = 15 ;
break;
case V_84 :
V_80 = 16 ;
break;
case V_23 :
case V_85 :
case V_86 :
case V_87 :
V_80 = 17 ;
break;
}
}
static void F_59 ( struct V_1 * V_2 )
{
T_3 V_78 , V_88 ;
if ( V_80 == - 1 )
return;
V_88 = V_2 -> V_78 ;
if ( ! V_88 || V_88 > 15 )
return;
if ( V_2 -> V_44 -> V_73 != 0 || F_58 ( V_2 -> V_72 ) > V_81 ||
F_58 ( V_2 -> V_72 ) < V_80 )
return;
F_5 ( V_2 , V_89 , & V_78 ) ;
if ( V_88 != V_78 ) {
F_6 ( & V_2 -> V_2 , L_53 ,
V_78 , V_88 ) ;
F_60 ( 15 ) ;
F_7 ( V_2 , V_89 , V_88 ) ;
}
}
static void F_61 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0xfc , 0 ) ;
F_27 ( V_2 , V_90 , & V_2 -> V_79 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 , V_91 , 0 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
T_1 V_92 ;
F_10 ( V_2 , 0x4C , & V_92 ) ;
if ( ( V_92 & 6 ) != 6 ) {
V_92 |= 6 ;
F_47 ( & V_2 -> V_2 , L_54 ) ;
F_63 ( V_2 , 0x4C , V_92 ) ;
F_10 ( V_2 , 0x84 , & V_92 ) ;
V_92 |= ( 1 << 23 ) ;
F_63 ( V_2 , 0x84 , V_92 ) ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_29 [ 1 ] ;
V_30 -> V_33 |= V_34 ;
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0xffffff ;
}
static void F_66 ( struct V_1 * V_2 )
{
V_2 -> V_93 = 1 ;
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
static void F_68 ( struct V_1 * V_65 )
{
T_2 V_94 ;
if ( V_65 -> V_22 != 0x04 )
return;
F_27 ( V_65 , 0x40 , & V_94 ) ;
if ( V_94 & ( 1 << 6 ) ) {
V_94 &= ~ ( 1 << 6 ) ;
F_49 ( V_65 , 0x40 , V_94 ) ;
F_6 ( & V_65 -> V_2 , L_56 ) ;
}
}
static void F_69 ( struct V_1 * V_65 )
{
T_3 V_69 ;
F_5 ( V_65 , V_95 , & V_69 ) ;
if ( V_69 == 0x01 ) {
F_5 ( V_65 , 0x40 , & V_69 ) ;
F_7 ( V_65 , 0x40 , V_69 | 1 ) ;
F_7 ( V_65 , 0x9 , 1 ) ;
F_7 ( V_65 , 0xa , 6 ) ;
F_7 ( V_65 , 0x40 , V_69 ) ;
V_65 -> V_96 = V_97 ;
F_6 ( & V_65 -> V_2 , L_57 ) ;
}
}
static void F_70 ( struct V_1 * V_65 )
{
T_3 V_98 ;
F_5 ( V_65 , V_99 , & V_98 ) ;
if ( V_98 & 5 ) {
V_98 &= ~ 5 ;
V_65 -> V_96 &= ~ 5 ;
F_7 ( V_65 , V_99 , V_98 ) ;
}
}
static void F_71 ( struct V_1 * V_65 )
{
T_3 V_98 ;
F_5 ( V_65 , V_99 , & V_98 ) ;
if ( ( ( V_98 & 1 ) && ! ( V_98 & 4 ) ) || ( ( V_98 & 4 ) && ! ( V_98 & 1 ) ) ) {
F_6 ( & V_65 -> V_2 , L_58 ) ;
V_98 &= ~ 5 ;
V_65 -> V_96 &= ~ 5 ;
F_7 ( V_65 , V_99 , V_98 ) ;
}
}
static void F_72 ( struct V_1 * V_65 )
{
V_65 -> V_100 |= V_101 ;
}
static void F_73 ( struct V_1 * V_2 )
{
V_2 -> V_96 = V_102 << 8 ;
}
static void F_74 ( struct V_1 * V_2 )
{
if ( F_75 ( V_2 -> V_103 == V_104 ) ) {
if ( V_2 -> V_79 == V_105 )
switch( V_2 -> V_106 ) {
case 0x8025 :
case 0x8070 :
case 0x8088 :
case 0x1626 :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_108 )
switch( V_2 -> V_106 ) {
case 0x80b1 :
case 0x80b2 :
case 0x8093 :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_109 )
switch( V_2 -> V_106 ) {
case 0x8030 :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_110 )
switch ( V_2 -> V_106 ) {
case 0x8070 :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_111 )
switch ( V_2 -> V_106 ) {
case 0x80c9 :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_112 )
switch ( V_2 -> V_106 ) {
case 0x1751 :
case 0x1821 :
case 0x1897 :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_113 )
switch ( V_2 -> V_106 ) {
case 0x184b :
case 0x186a :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_114 )
switch ( V_2 -> V_106 ) {
case 0x80f2 :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_115 )
switch ( V_2 -> V_106 ) {
case 0x1882 :
case 0x1977 :
V_107 = 1 ;
}
} else if ( F_75 ( V_2 -> V_103 == V_116 ) ) {
if ( V_2 -> V_79 == V_113 )
switch( V_2 -> V_106 ) {
case 0x088C :
case 0x0890 :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_114 )
switch ( V_2 -> V_106 ) {
case 0x12bc :
case 0x12bd :
case 0x006a :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_117 )
switch ( V_2 -> V_106 ) {
case 0x12bf :
V_107 = 1 ;
}
} else if ( F_75 ( V_2 -> V_103 == V_118 ) ) {
if ( V_2 -> V_79 == V_113 )
switch( V_2 -> V_106 ) {
case 0xC00C :
V_107 = 1 ;
}
} else if ( F_75 ( V_2 -> V_103 == V_119 ) ) {
if ( V_2 -> V_79 == V_113 )
switch( V_2 -> V_106 ) {
case 0x0058 :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_120 )
switch( V_2 -> V_106 ) {
case 0xB16C :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_121 )
switch( V_2 -> V_106 ) {
case 0x00b8 :
case 0x00b9 :
case 0x00ba :
V_107 = 1 ;
}
else if ( V_2 -> V_79 == V_122 )
switch ( V_2 -> V_106 ) {
case 0x001A :
V_107 = 1 ;
}
}
}
static void F_76 ( struct V_1 * V_2 )
{
T_2 V_64 ;
if ( F_77 ( ! V_107 ) )
return;
F_27 ( V_2 , 0xF2 , & V_64 ) ;
if ( V_64 & 0x8 ) {
F_49 ( V_2 , 0xF2 , V_64 & ( ~ 0x8 ) ) ;
F_27 ( V_2 , 0xF2 , & V_64 ) ;
if ( V_64 & 0x8 )
F_6 ( & V_2 -> V_2 , L_59 , V_64 ) ;
else
F_6 ( & V_2 -> V_2 , L_60 ) ;
}
}
static void F_78 ( struct V_1 * V_2 )
{
T_1 V_123 ;
if ( F_77 ( ! V_107 ) )
return;
F_79 ( V_124 ) ;
F_10 ( V_2 , 0xF0 , & V_123 ) ;
V_124 = F_80 ( V_123 & 0xFFFFC000 , 0x4000 ) ;
if ( V_124 == NULL )
return;
}
static void F_81 ( struct V_1 * V_2 )
{
T_1 V_64 ;
if ( F_77 ( ! V_107 || ! V_124 ) )
return;
V_64 = F_82 ( V_124 + 0x3418 ) ;
F_83 ( V_64 & 0xFFFFFFF7 , V_124 + 0x3418 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( F_77 ( ! V_107 || ! V_124 ) )
return;
F_85 ( V_124 ) ;
V_124 = NULL ;
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
T_2 V_125 ;
F_5 ( V_2 , V_126 , & V_62 ) ;
F_7 ( V_2 , V_126 , V_62 | ( 1 << 6 ) ) ;
F_27 ( V_2 , V_90 , & V_125 ) ;
if ( ( ( V_125 & 0xfff0 ) != 0x0960 ) && ( V_125 != 0x0018 ) ) {
F_7 ( V_2 , V_126 , V_62 ) ;
return;
}
V_2 -> V_79 = V_125 ;
F_87 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
T_3 V_64 ;
int V_127 = 0 ;
if ( F_77 ( V_2 -> V_103 == V_104 ) ) {
if ( V_2 -> V_79 == V_82 )
V_127 = 1 ;
}
if ( ! V_127 )
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
static void F_90 ( struct V_1 * V_65 )
{
T_1 V_128 , V_129 , V_96 ;
T_3 V_130 ;
if ( F_91 ( V_65 -> V_72 ) )
return;
F_10 ( V_65 , 0x40 , & V_128 ) ;
F_10 ( V_65 , 0x80 , & V_129 ) ;
V_128 &= ~ 0x00CFF302 ;
V_129 &= ~ ( 1 << 24 ) ;
switch ( V_65 -> V_79 ) {
case V_131 :
case V_132 :
case V_133 :
V_128 |= 0x0002A100 ;
break;
case V_134 :
case V_135 :
V_129 |= ( 1 << 24 ) ;
case V_136 :
case V_137 :
case V_138 :
V_128 |= 0x00C2A1B3 ;
break;
case V_139 :
V_128 |= 0x00C00000 ;
break;
}
F_63 ( V_65 , 0x40 , V_128 ) ;
F_63 ( V_65 , 0x80 , V_129 ) ;
F_5 ( V_65 , V_140 , & V_130 ) ;
V_65 -> V_141 = V_130 & 0x7f ;
V_65 -> V_142 = ! ! ( V_130 & 0x80 ) ;
F_10 ( V_65 , V_143 , & V_96 ) ;
V_65 -> V_96 = V_96 >> 8 ;
}
static void F_92 ( struct V_1 * V_65 )
{
int V_144 ;
if ( ( V_65 -> V_96 >> 8 ) != 0xff00 )
return;
if ( F_93 ( V_65 , 0 ) && F_25 ( V_65 , 0 ) )
F_94 ( & V_145 , & V_65 -> V_29 [ 0 ] ) ;
for ( V_144 = 1 ; V_144 < 6 ; V_144 ++ ) {
memset ( & V_65 -> V_29 [ V_144 ] , 0 , sizeof( V_65 -> V_29 [ V_144 ] ) ) ;
}
}
static void F_95 ( struct V_1 * V_65 )
{
F_96 ( V_65 ) ;
V_65 -> V_146 = 1 ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_96 ( V_2 ) ;
V_2 -> V_146 = 1 ;
F_47 ( & V_2 -> V_2 , L_65 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
V_147 = 120 ;
V_2 -> V_148 = 1 ;
}
static void F_99 ( struct V_1 * V_2 )
{
if ( V_149 || V_150 )
return;
V_2 -> V_151 = V_152 ;
F_6 ( & V_2 -> V_2 , L_66 ,
V_2 -> V_153 , V_2 -> V_79 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
T_2 V_154 ;
if ( V_149 )
return;
F_27 ( V_2 , V_155 , & V_154 ) ;
V_154 |= V_156 ;
F_49 ( V_2 , V_155 , V_154 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_153 , V_2 -> V_79 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
T_1 V_157 ;
T_3 V_78 ;
if ( V_149 )
return;
F_10 ( V_2 , V_158 , & V_157 ) ;
F_63 ( V_2 , V_158 , V_157 |
V_159 ) ;
for ( V_78 = 0x10 ; V_78 < 0x10 + 32 ; V_78 ++ ) {
F_102 ( V_78 , V_160 ) ;
F_102 ( 0x00 , V_161 ) ;
}
F_63 ( V_2 , V_158 , V_157 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_153 , V_2 -> V_79 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
T_1 V_157 ;
if ( V_149 )
return;
if ( ( V_2 -> V_22 == V_162 ) ||
( V_2 -> V_22 == V_163 ) )
return;
F_10 ( V_2 , V_164 , & V_157 ) ;
V_157 &= ~ V_165 ;
F_63 ( V_2 , V_164 , V_157 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_153 , V_2 -> V_79 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
T_2 V_154 ;
if ( V_149 )
return;
F_27 ( V_2 , V_166 , & V_154 ) ;
if ( ! V_154 ) {
F_6 ( & V_2 -> V_2 , L_68
L_69 , V_2 -> V_153 , V_2 -> V_79 ) ;
return;
}
F_49 ( V_2 , V_166 , 0 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_153 , V_2 -> V_79 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_29 [ 0 ] ;
if ( V_30 -> V_31 & 0x8 ) {
V_30 -> V_33 |= V_34 ;
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0xf ;
}
}
static void F_106 ( struct V_1 * V_2 )
{
unsigned int V_167 ;
if ( V_2 -> V_22 >= 2 )
return;
for ( V_167 = 0 ; V_167 <= 1 ; V_167 ++ )
if ( F_25 ( V_2 , V_167 ) == 0x80 &&
( F_93 ( V_2 , V_167 ) & 0x80 ) ) {
struct V_29 * V_30 = & V_2 -> V_29 [ V_167 ] ;
F_6 ( & V_2 -> V_2 ,
L_70 ,
V_167 ) ;
V_30 -> V_33 |= V_34 ;
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0xff ;
}
}
static void F_107 ( struct V_1 * V_2 )
{
unsigned int V_168 = ( V_2 -> V_106 & 0xf0 ) >> 4 ;
unsigned int V_169 = V_2 -> V_106 & 0xf ;
switch ( V_2 -> V_79 ) {
case V_170 :
if ( V_2 -> V_103 == V_171 &&
V_2 -> V_106 == 0x0299 )
return;
case V_172 :
case V_173 :
case V_174 :
case V_175 :
if ( V_168 ) {
F_6 ( & V_2 -> V_2 , L_71
L_72
L_73 ,
V_2 -> V_79 , V_168 , V_169 ) ;
V_2 -> V_96 = ( V_176 << 8 ) |
( V_2 -> V_96 & 0xff ) ;
}
}
}
static void F_108 ( struct V_1 * V_2 )
{
T_2 V_66 , V_177 ;
T_3 T_4 * V_178 ;
T_3 V_179 ;
switch ( V_2 -> V_79 ) {
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
F_27 ( V_2 , V_67 , & V_66 ) ;
if ( ! ( V_66 & V_180 ) || ! F_93 ( V_2 , 0 ) )
return;
if ( V_2 -> V_181 ) {
F_27 ( V_2 , V_2 -> V_181 + V_182 , & V_177 ) ;
if ( ( V_177 & V_183 ) != V_184 )
return;
}
V_178 = F_109 ( F_93 ( V_2 , 0 ) , 8 ) ;
if ( ! V_178 ) {
F_47 ( & V_2 -> V_2 , L_74 ) ;
return;
}
V_179 = F_110 ( V_178 + 3 ) ;
if ( V_179 == 0 ) {
F_47 ( & V_2 -> V_2 , L_75
L_76 ) ;
F_111 ( 1 , V_178 + 3 ) ;
}
F_85 ( V_178 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_77 ) ;
F_113 ( V_2 , V_185 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
if ( V_2 -> V_96 == V_186 ) {
F_6 ( & V_2 -> V_2 , L_78 ) ;
V_2 -> V_96 = V_187 ;
}
}
static void F_115 ( struct V_1 * V_2 )
{
T_2 V_188 ;
F_27 ( V_2 , 0x40 , & V_188 ) ;
if ( V_188 & 0x200 ) {
F_6 ( & V_2 -> V_2 , L_79 ) ;
V_2 -> V_189 = 1 ;
}
}
static void F_116 ( struct V_1 * V_2 )
{
T_5 V_190 ;
if ( F_5 ( V_2 , 0xf41 , & V_190 ) == 0 ) {
if ( ! ( V_190 & 0x20 ) ) {
F_7 ( V_2 , 0xf41 , V_190 | 0x20 ) ;
F_6 ( & V_2 -> V_2 ,
L_80 ) ;
}
}
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_1 * V_18 = F_4 ( V_20 ,
V_191 , NULL ) ;
T_5 V_190 ;
V_18 = F_4 ( V_20 , V_191 , V_18 ) ;
if ( ! V_18 )
return;
F_17 ( V_18 ) ;
if ( F_5 ( V_2 , 0x76 , & V_190 ) == 0 ) {
if ( V_190 & 0x40 ) {
F_7 ( V_2 , 0x76 , V_190 ^ 0x40 ) ;
F_6 ( & V_2 -> V_2 ,
L_81 ) ;
}
}
if ( F_5 ( V_2 , 0x72 , & V_190 ) == 0 ) {
if ( V_190 != 0 ) {
F_7 ( V_2 , 0x72 , 0x0 ) ;
F_7 ( V_2 , 0x75 , 0x1 ) ;
F_7 ( V_2 , 0x77 , 0x0 ) ;
F_6 ( & V_2 -> V_2 ,
L_82 ) ;
}
}
}
static void F_118 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_79 == V_192 ) ||
( V_2 -> V_79 == V_193 ) ||
( V_2 -> V_79 == V_194 ) ||
( V_2 -> V_79 == V_195 ) ||
( ( V_2 -> V_79 == V_196 ) &&
( V_2 -> V_22 & 0xf0 ) == 0x0 ) ) {
if ( V_2 -> V_197 )
V_2 -> V_197 -> V_198 = 0x80 ;
}
}
static void F_119 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_10 ( V_2 , 0xf4 , & V_15 ) ;
if ( V_15 == 0x05719000 ) {
int V_199 = F_120 ( V_2 ) ;
if ( V_199 > 2048 )
F_121 ( V_2 , 2048 ) ;
}
}
static void F_122 ( struct V_1 * V_2 )
{
T_3 V_62 ;
if ( F_5 ( V_2 , 0xF4 , & V_62 ) == 0 && ! ( V_62 & 0x02 ) ) {
F_6 ( & V_2 -> V_2 , L_83 ) ;
F_7 ( V_2 , 0xF4 , V_62 | 0x02 ) ;
}
}
static void F_123 ( struct V_1 * V_2 )
{
if ( V_200 ) {
F_63 ( V_2 , 0x98 , 0x1 ) ;
F_124 ( 50 ) ;
}
}
static void F_125 ( struct V_1 * V_2 )
{
F_126 () ;
F_47 ( & V_2 -> V_2 , L_84 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 ) {
F_47 ( & V_2 -> V_2 , L_85
L_86 ) ;
V_2 -> V_75 -> V_76 |= V_201 ;
}
}
static void F_128 ( struct V_1 * V_202 )
{
struct V_1 * V_203 ;
V_203 = F_129 ( V_202 -> V_44 , F_130 ( 1 , 0 ) ) ;
if ( V_203 ) {
if ( V_203 -> V_79 == 0x9602 )
F_127 ( V_203 ) ;
F_17 ( V_203 ) ;
}
}
static int F_131 ( struct V_1 * V_2 )
{
int V_204 , V_205 = 48 ;
V_204 = F_132 ( V_2 , V_206 ) ;
while ( V_204 && V_205 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_204 + V_207 ,
& V_33 ) == 0 )
{
F_6 ( & V_2 -> V_2 , L_87 ,
V_33 & V_208 ?
L_88 : L_89 ) ;
return ( V_33 & V_208 ) != 0 ;
}
V_204 = F_133 ( V_2 , V_204 ,
V_206 ) ;
}
return 0 ;
}
static void F_134 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 && ! F_131 ( V_2 ) ) {
F_47 ( & V_2 -> V_2 , L_85
L_86 ) ;
V_2 -> V_75 -> V_76 |= V_201 ;
}
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_1 * V_65 ;
if ( ! V_2 -> V_75 )
return;
V_65 = F_129 ( V_2 -> V_44 , 0 ) ;
if ( ! V_65 )
return;
if ( ! F_131 ( V_2 ) && ! F_131 ( V_65 ) ) {
F_47 ( & V_2 -> V_2 , L_85
L_86 ) ;
V_2 -> V_75 -> V_76 |= V_201 ;
}
F_17 ( V_65 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
int V_204 , V_205 = 48 ;
V_204 = F_132 ( V_2 , V_206 ) ;
while ( V_204 && V_205 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_204 + V_207 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_90 ) ;
F_7 ( V_2 , V_204 + V_207 ,
V_33 | V_208 ) ;
}
V_204 = F_133 ( V_2 , V_204 ,
V_206 ) ;
}
}
static void F_137 ( struct V_1 * V_2 )
{
const char * V_209 = F_138 ( V_210 ) ;
if ( V_209 &&
( strstr ( V_209 , L_91 ) ||
strstr ( V_209 , L_92 ) ) ) {
F_6 ( & V_2 -> V_2 ,
L_93 ) ;
V_2 -> V_146 = 1 ;
}
}
static void F_139 ( struct V_1 * V_2 )
{
T_1 V_211 ;
if ( ! F_140 ( V_2 , V_212 ) )
return;
F_10 ( V_2 , 0x74 , & V_211 ) ;
if ( V_211 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_141 ( V_213 L_94 ) ;
V_211 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_63 ( V_2 , 0x74 , V_211 ) ;
}
}
static int F_142 ( struct V_1 * V_2 )
{
int V_204 , V_205 = 48 ;
int V_214 = 0 ;
V_204 = F_132 ( V_2 , V_206 ) ;
while ( V_204 && V_205 -- ) {
T_3 V_33 ;
if ( V_214 < 1 )
V_214 = 1 ;
if ( F_5 ( V_2 , V_204 + V_207 ,
& V_33 ) == 0 ) {
if ( V_33 & V_208 ) {
if ( V_214 < 2 ) {
V_214 = 2 ;
break;
}
}
}
V_204 = F_133 ( V_2 , V_204 ,
V_206 ) ;
}
return V_214 ;
}
static int F_143 ( struct V_1 * V_202 )
{
struct V_1 * V_2 ;
int V_204 ;
int V_144 , V_215 ;
int V_214 = 0 ;
V_215 = V_202 -> V_72 >> 3 ;
for ( V_144 = V_215 + 1 ; V_144 < 0x20 ; V_144 ++ ) {
V_2 = F_129 ( V_202 -> V_44 , F_130 ( V_144 , 0 ) ) ;
if ( ! V_2 )
continue;
V_204 = F_132 ( V_2 , V_216 ) ;
if ( V_204 != 0 ) {
F_17 ( V_2 ) ;
break;
}
if ( F_142 ( V_2 ) ) {
V_214 = 1 ;
F_17 ( V_2 ) ;
break;
}
F_17 ( V_2 ) ;
}
return V_214 ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_204 , V_217 ;
int V_32 = 0 ;
T_2 V_33 , V_218 ;
V_204 = F_132 ( V_2 , V_216 ) ;
if ( ! V_204 )
goto V_219;
F_27 ( V_2 , V_204 + V_220 , & V_33 ) ;
V_217 = ( ( V_33 >> 10 ) & 1 ) ?
V_221 : V_222 ;
F_27 ( V_2 , V_204 + V_217 , & V_218 ) ;
if ( V_218 & ( 1 << 6 ) )
V_32 = 1 ;
V_219:
return V_32 ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_1 * V_202 ;
int V_204 ;
int V_144 , V_215 ;
int V_214 = 0 ;
V_215 = V_2 -> V_72 >> 3 ;
for ( V_144 = V_215 ; V_144 >= 0 ; V_144 -- ) {
V_202 = F_129 ( V_2 -> V_44 , F_130 ( V_144 , 0 ) ) ;
if ( ! V_202 )
continue;
V_204 = F_132 ( V_202 , V_216 ) ;
if ( V_204 != 0 ) {
V_214 = 1 ;
break;
}
F_17 ( V_202 ) ;
}
if ( ! V_214 )
return;
if ( V_202 == V_2 && F_144 ( V_202 ) &&
F_143 ( V_202 ) )
goto V_219;
if ( F_131 ( V_202 ) )
goto V_219;
F_136 ( V_2 ) ;
V_219:
F_17 ( V_202 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
int V_204 , V_205 = 48 ;
V_204 = F_132 ( V_2 , V_206 ) ;
while ( V_204 && V_205 -- ) {
T_3 V_33 ;
if ( F_5 ( V_2 , V_204 + V_207 ,
& V_33 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_95 ) ;
F_7 ( V_2 , V_204 + V_207 ,
V_33 & ~ V_208 ) ;
}
V_204 = F_133 ( V_2 , V_204 ,
V_206 ) ;
}
}
static void F_147 ( struct V_1 * V_2 , int V_223 )
{
struct V_1 * V_202 ;
int V_204 ;
int V_214 ;
if ( ! F_148 () )
return;
V_214 = F_142 ( V_2 ) ;
if ( V_214 == 0 )
return;
V_202 = F_149 ( 0 , F_130 ( 0 , 0 ) ) ;
if ( V_202 == NULL ) {
F_47 ( & V_2 -> V_2 ,
L_96 ) ;
return;
}
V_204 = F_132 ( V_202 , V_216 ) ;
if ( V_204 != 0 ) {
if ( V_214 == 1 ) {
if ( V_223 )
F_136 ( V_2 ) ;
else
F_145 ( V_2 ) ;
}
goto V_219;
}
if ( V_214 == 1 )
goto V_219;
F_146 ( V_2 ) ;
V_219:
F_17 ( V_202 ) ;
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
V_2 -> V_100 |= V_224 ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( V_225 , V_226 ,
NULL ) ;
if ( ! V_18 )
return;
if ( ( V_18 -> V_22 < 0x3B ) && ( V_18 -> V_22 >= 0x30 ) )
V_2 -> V_100 |= V_224 ;
F_17 ( V_18 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 < 0x18 ) {
F_6 ( & V_2 -> V_2 , L_97 ) ;
V_2 -> V_100 |= V_224 ;
}
}
static void F_155 ( struct V_1 * V_2 )
{
V_2 -> V_227 = 1 ;
}
static void F_156 ( struct V_1 * V_2 )
{
T_3 V_228 ;
T_3 V_229 ;
T_3 V_230 ;
if ( F_91 ( V_2 -> V_72 ) )
return;
F_5 ( V_2 , 0xB7 , & V_230 ) ;
if ( V_230 & 0x02 )
return;
F_5 ( V_2 , 0x8E , & V_228 ) ;
F_7 ( V_2 , 0x8E , 0xAA ) ;
F_5 ( V_2 , 0x8D , & V_229 ) ;
F_7 ( V_2 , 0x8D , 0xB7 ) ;
F_7 ( V_2 , 0xB7 , V_230 | 0x02 ) ;
F_7 ( V_2 , 0x8E , V_228 ) ;
F_7 ( V_2 , 0x8D , V_229 ) ;
F_157 ( & V_2 -> V_2 , L_98 ) ;
F_157 ( & V_2 -> V_2 , L_99 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
T_3 V_228 ;
T_3 V_230 ;
if ( F_91 ( V_2 -> V_72 ) )
return;
if ( V_2 -> V_79 == V_231 ||
V_2 -> V_79 == V_232 ) {
F_7 ( V_2 , 0xf9 , 0xfc ) ;
F_7 ( V_2 , 0x150 , 0x10 ) ;
F_7 ( V_2 , 0xf9 , 0x00 ) ;
F_7 ( V_2 , 0xfc , 0x01 ) ;
F_7 ( V_2 , 0xe1 , 0x32 ) ;
F_7 ( V_2 , 0xfc , 0x00 ) ;
F_157 ( & V_2 -> V_2 , L_100 ) ;
}
F_5 ( V_2 , 0xCB , & V_230 ) ;
if ( V_230 & 0x02 )
return;
F_5 ( V_2 , 0xCA , & V_228 ) ;
F_7 ( V_2 , 0xCA , 0x57 ) ;
F_7 ( V_2 , 0xCB , V_230 | 0x02 ) ;
F_7 ( V_2 , 0xCA , V_228 ) ;
F_157 ( & V_2 -> V_2 , L_101 ) ;
F_157 ( & V_2 -> V_2 , L_99 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
T_1 V_233 ;
F_10 ( V_2 , V_234 , & V_233 ) ;
F_63 ( V_2 , V_234 , V_233 | V_235 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_102 ) ;
V_2 -> V_96 = V_236 ;
}
static void F_161 ( struct V_1 * V_2 )
{
V_2 -> V_237 = 1 ;
}
static void F_162 ( struct V_1 * V_2 )
{
int V_238 ;
T_2 V_239 ;
if ( V_240 == V_241 )
return;
V_238 = F_27 ( V_2 , 0x48 , & V_239 ) ;
if ( V_238 ) {
F_163 ( & V_2 -> V_2 , L_103
L_104 ) ;
return;
}
if ( ! ( V_239 & ( 1 << 10 ) ) )
return;
V_239 &= ~ ( 1 << 10 ) ;
V_238 = F_49 ( V_2 , 0x48 , V_239 ) ;
if ( V_238 ) {
F_163 ( & V_2 -> V_2 , L_105
L_104 ) ;
return;
}
F_164 ( L_106
L_107 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
int V_242 ;
T_3 V_64 ;
V_242 = F_5 ( V_2 , 0x00D0 , & V_64 ) ;
if ( V_242 )
return;
V_2 -> V_29 [ 2 ] . V_32 = V_2 -> V_29 [ 2 ] . V_31 + ( ( V_243 ) 1 << V_64 ) - 1 ;
V_242 = F_5 ( V_2 , 0x00D1 , & V_64 ) ;
if ( V_242 )
return;
V_2 -> V_29 [ 4 ] . V_32 = V_2 -> V_29 [ 4 ] . V_31 + ( ( V_243 ) 1 << V_64 ) - 1 ;
}
static T_6 F_166 ( struct V_1 * V_2 ,
void (* F_167)( struct V_1 * V_2 ) )
{
T_6 V_244 = F_168 ( 0 , 0 ) ;
F_169 ( & V_2 -> V_2 , L_108 , F_167 ) ;
if ( V_245 ) {
F_170 ( L_109 ,
F_167 , F_171 ( V_246 ) , F_172 ( & V_2 -> V_2 ) ) ;
V_244 = F_173 () ;
}
return V_244 ;
}
static void F_174 ( struct V_1 * V_2 , T_6 V_244 ,
void (* F_167)( struct V_1 * V_2 ) )
{
T_6 V_247 , V_248 ;
unsigned long long V_249 ;
if ( V_245 ) {
V_248 = F_173 () ;
V_247 = F_175 ( V_248 , V_244 ) ;
V_249 = ( unsigned long long ) F_176 ( V_247 ) >> 10 ;
F_170 ( L_110 ,
F_167 , V_249 , F_172 ( & V_2 -> V_2 ) ) ;
}
}
static void F_177 ( struct V_1 * V_2 )
{
void T_4 * V_250 = F_178 ( V_2 , 0 , 0 ) ;
if ( V_250 == NULL ) {
F_47 ( & V_2 -> V_2 , L_111 ) ;
return;
}
if ( F_82 ( V_250 + V_251 ) != 0 ) {
F_47 ( & V_2 -> V_2 , L_112
L_76 ) ;
F_83 ( 0 , V_250 + V_251 ) ;
}
F_179 ( V_2 , V_250 ) ;
}
static void F_180 ( struct V_1 * V_2 )
{
V_2 -> V_252 = 0 ;
}
static void F_181 ( struct V_1 * V_2 )
{
V_2 -> V_253 = 1 ;
}
static void F_182 ( struct V_1 * V_2 , struct V_254 * V_255 ,
struct V_254 * V_32 )
{
T_6 V_244 ;
for (; V_255 < V_32 ; V_255 ++ )
if ( ( V_255 -> V_96 == ( T_1 ) ( V_2 -> V_96 >> V_255 -> V_256 ) ||
V_255 -> V_96 == ( T_1 ) V_257 ) &&
( V_255 -> V_153 == V_2 -> V_153 ||
V_255 -> V_153 == ( T_2 ) V_257 ) &&
( V_255 -> V_79 == V_2 -> V_79 ||
V_255 -> V_79 == ( T_2 ) V_257 ) ) {
V_244 = F_166 ( V_2 , V_255 -> V_258 ) ;
V_255 -> V_258 ( V_2 ) ;
F_174 ( V_2 , V_244 , V_255 -> V_258 ) ;
}
}
void F_183 ( enum V_259 V_260 , struct V_1 * V_2 )
{
struct V_254 * V_31 , * V_32 ;
switch( V_260 ) {
case V_261 :
V_31 = V_262 ;
V_32 = V_263 ;
break;
case V_264 :
V_31 = V_265 ;
V_32 = V_266 ;
break;
case V_267 :
if ( ! V_268 )
return;
V_31 = V_269 ;
V_32 = V_270 ;
break;
case V_271 :
V_31 = V_272 ;
V_32 = V_273 ;
break;
case V_274 :
V_31 = V_275 ;
V_32 = V_276 ;
break;
case V_277 :
V_31 = V_278 ;
V_32 = V_279 ;
break;
case V_280 :
V_31 = V_281 ;
V_32 = V_282 ;
break;
default:
return;
}
F_182 ( V_2 , V_31 , V_32 ) ;
}
static int T_7 F_184 ( void )
{
struct V_1 * V_2 = NULL ;
T_3 V_283 = 0 ;
T_3 V_69 ;
if ( V_284 )
F_141 ( V_285 L_113 ,
V_284 << 2 ) ;
V_268 = true ;
F_185 (dev) {
F_183 ( V_267 , V_2 ) ;
if ( ! V_284 ) {
F_5 ( V_2 , V_286 , & V_69 ) ;
if ( ! V_283 )
V_283 = V_69 ;
if ( ! V_69 || V_283 == V_69 )
continue;
F_141 ( V_285 L_114
L_115 , V_283 << 2 , V_69 << 2 ,
V_287 << 2 ) ;
V_284 = V_287 ;
}
}
if ( ! V_284 ) {
F_141 ( V_285 L_116 ,
V_283 << 2 , V_287 << 2 ) ;
V_284 = V_283 ? V_283 : V_287 ;
}
return 0 ;
}
static int F_186 ( struct V_1 * V_2 , int V_288 )
{
int V_204 ;
if ( V_2 -> V_96 == V_289 ) {
V_204 = F_140 ( V_2 , V_290 ) ;
if ( ! V_204 )
return - V_291 ;
if ( V_288 )
return 0 ;
F_7 ( V_2 , V_204 + 0x4 , 1 ) ;
F_187 ( 100 ) ;
return 0 ;
} else {
return - V_291 ;
}
}
static int F_188 ( struct V_1 * V_2 , int V_288 )
{
if ( V_288 )
return 0 ;
if ( ! F_189 ( V_2 ) )
F_163 ( & V_2 -> V_2 , L_117 ) ;
F_190 ( V_2 , V_292 , V_293 ) ;
F_187 ( 100 ) ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 , int V_288 )
{
void T_4 * V_294 ;
unsigned long V_295 ;
T_1 V_64 ;
if ( V_288 )
return 0 ;
V_294 = F_178 ( V_2 , 0 , 0 ) ;
if ( ! V_294 )
return - V_296 ;
F_192 ( 0x00000002 , V_294 + V_297 ) ;
F_192 ( 0x00000005 , V_294 + V_298 ) ;
V_64 = F_193 ( V_294 + V_299 ) & 0xfffffffe ;
F_192 ( V_64 , V_294 + V_299 ) ;
V_295 = V_300 + F_194 ( V_301 ) ;
do {
V_64 = F_193 ( V_294 + V_302 ) ;
if ( ( V_64 & 0xb0000000 ) == 0 )
goto V_303;
F_187 ( 10 ) ;
} while ( F_195 ( V_300 , V_295 ) );
F_47 ( & V_2 -> V_2 , L_118 ) ;
V_303:
F_192 ( 0x00000002 , V_294 + V_304 ) ;
F_179 ( V_2 , V_294 ) ;
return 0 ;
}
static int F_196 ( struct V_1 * V_2 , int V_288 )
{
T_2 V_305 ;
T_2 V_306 ;
if ( ( V_2 -> V_79 & 0xf000 ) != 0x4000 )
return - V_291 ;
if ( V_288 )
return 0 ;
F_27 ( V_2 , V_67 , & V_305 ) ;
F_49 ( V_2 , V_67 ,
V_305 | V_307 ) ;
F_197 ( V_2 ) ;
F_27 ( V_2 , V_2 -> V_308 + V_309 , & V_306 ) ;
if ( ( V_306 & V_310 ) == 0 )
F_49 ( V_2 , V_2 -> V_308 + V_309 ,
V_306 |
V_310 |
V_311 ) ;
if ( ! F_189 ( V_2 ) )
F_163 ( & V_2 -> V_2 , L_117 ) ;
F_190 ( V_2 , V_292 , V_293 ) ;
F_187 ( 100 ) ;
F_198 ( V_2 ) ;
F_49 ( V_2 , V_67 , V_305 ) ;
return 0 ;
}
int F_199 ( struct V_1 * V_2 , int V_288 )
{
const struct V_312 * V_144 ;
for ( V_144 = V_312 ; V_144 -> V_313 ; V_144 ++ ) {
if ( ( V_144 -> V_153 == V_2 -> V_153 ||
V_144 -> V_153 == ( T_2 ) V_257 ) &&
( V_144 -> V_79 == V_2 -> V_79 ||
V_144 -> V_79 == ( T_2 ) V_257 ) )
return V_144 -> V_313 ( V_2 , V_288 ) ;
}
return - V_291 ;
}
static struct V_1 * F_200 ( struct V_1 * V_2 )
{
if ( ! F_91 ( V_2 -> V_72 ) )
return F_201 ( V_2 ) ;
return F_129 ( V_2 -> V_44 , F_130 ( F_58 ( V_2 -> V_72 ) , 0 ) ) ;
}
struct V_1 * F_202 ( struct V_1 * V_2 )
{
const struct V_314 * V_144 ;
for ( V_144 = V_314 ; V_144 -> V_315 ; V_144 ++ ) {
if ( ( V_144 -> V_153 == V_2 -> V_153 ||
V_144 -> V_153 == ( T_2 ) V_257 ) &&
( V_144 -> V_79 == V_2 -> V_79 ||
V_144 -> V_79 == ( T_2 ) V_257 ) )
return V_144 -> V_315 ( V_2 ) ;
}
return F_201 ( V_2 ) ;
}
static int F_203 ( struct V_1 * V_2 , T_2 V_316 )
{
#ifdef F_204
struct V_317 * V_318 = NULL ;
T_8 V_319 ;
if ( ! V_2 -> V_142 || ! F_205 ( V_2 -> V_44 ) )
return - V_320 ;
V_319 = F_206 ( L_119 , 0 , & V_318 ) ;
if ( F_207 ( V_319 ) )
return - V_320 ;
V_316 &= ( V_321 | V_322 | V_323 | V_324 ) ;
return V_316 & ~ ( V_321 | V_322 ) ? 0 : 1 ;
#else
return - V_320 ;
#endif
}
static bool F_208 ( struct V_1 * V_2 )
{
int V_144 ;
if ( ! F_209 ( V_2 ) || F_210 ( V_2 ) != V_325 )
return false ;
for ( V_144 = 0 ; V_144 < F_211 ( V_326 ) ; V_144 ++ )
if ( V_326 [ V_144 ] == V_2 -> V_79 )
return true ;
return false ;
}
static int F_212 ( struct V_1 * V_2 , T_2 V_316 )
{
T_2 V_33 = V_2 -> V_100 & V_327 ?
V_328 : 0 ;
if ( ! F_208 ( V_2 ) )
return - V_291 ;
return V_316 & ~ V_33 ? 0 : 1 ;
}
int F_213 ( struct V_1 * V_2 , T_2 V_316 )
{
const struct V_329 * V_144 ;
int V_330 ;
for ( V_144 = V_329 ; V_144 -> V_331 ; V_144 ++ ) {
if ( ( V_144 -> V_153 == V_2 -> V_153 ||
V_144 -> V_153 == ( T_2 ) V_257 ) &&
( V_144 -> V_79 == V_2 -> V_79 ||
V_144 -> V_79 == ( T_2 ) V_257 ) ) {
V_330 = V_144 -> V_331 ( V_2 , V_316 ) ;
if ( V_330 >= 0 )
return V_330 ;
}
}
return - V_291 ;
}
static int F_214 ( struct V_1 * V_2 )
{
T_1 V_123 , V_332 , V_333 ;
void T_4 * V_334 ;
F_215 ( V_2 -> V_44 , F_130 ( 31 , 0 ) ,
V_335 , & V_123 ) ;
if ( ! ( V_123 & V_336 ) )
return - V_337 ;
V_334 = F_80 ( V_123 & V_338 ,
F_216 ( V_339 ) ) ;
if ( ! V_334 )
return - V_296 ;
V_332 = F_82 ( V_334 + V_340 ) ;
V_332 &= V_341 | V_342 ;
if ( V_332 != ( V_341 | V_342 ) ) {
V_333 = F_82 ( V_334 + V_339 ) ;
if ( V_333 & V_343 ) {
F_6 ( & V_2 -> V_2 , L_120 ) ;
V_333 &= ~ V_343 ;
F_83 ( V_333 , V_334 + V_339 ) ;
}
}
F_85 ( V_334 ) ;
return 0 ;
}
static void F_217 ( struct V_1 * V_2 )
{
T_1 V_344 ;
F_10 ( V_2 , V_345 , & V_344 ) ;
if ( ! ( V_344 & V_346 ) ) {
F_6 ( & V_2 -> V_2 , L_121 ) ;
V_344 |= V_346 ;
F_49 ( V_2 , V_345 , V_344 ) ;
}
}
static int F_218 ( struct V_1 * V_2 )
{
if ( ! F_208 ( V_2 ) )
return - V_291 ;
if ( F_214 ( V_2 ) ) {
F_47 ( & V_2 -> V_2 , L_122 ) ;
return 0 ;
}
F_217 ( V_2 ) ;
V_2 -> V_100 |= V_327 ;
F_6 ( & V_2 -> V_2 , L_123 ) ;
return 0 ;
}
void F_219 ( struct V_1 * V_2 )
{
const struct V_347 * V_144 ;
int V_330 ;
for ( V_144 = V_347 ; V_144 -> V_348 ; V_144 ++ ) {
if ( ( V_144 -> V_153 == V_2 -> V_153 ||
V_144 -> V_153 == ( T_2 ) V_257 ) &&
( V_144 -> V_79 == V_2 -> V_79 ||
V_144 -> V_79 == ( T_2 ) V_257 ) ) {
V_330 = V_144 -> V_348 ( V_2 ) ;
if ( V_330 >= 0 )
return;
}
}
}
