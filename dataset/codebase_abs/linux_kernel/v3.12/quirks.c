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
static void F_26 ( struct V_1 * V_2 , int V_34 ,
unsigned V_35 , int V_36 , const char * V_37 )
{
T_2 V_38 ;
struct V_39 V_40 ;
struct V_29 * V_33 = V_2 -> V_29 + V_36 ;
F_27 ( V_2 , V_34 , & V_38 ) ;
V_38 &= ~ ( V_35 - 1 ) ;
if ( ! V_38 )
return;
V_33 -> V_37 = F_28 ( V_2 ) ;
V_33 -> V_41 = V_42 ;
V_40 . V_31 = V_38 ;
V_40 . V_32 = V_38 + V_35 - 1 ;
F_29 ( V_2 , V_33 , & V_40 ) ;
if ( ! F_30 ( V_2 , V_36 ) )
F_6 ( & V_2 -> V_2 , L_10 , V_33 , V_37 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_11 ) ;
F_32 ( 0x3b0 , 0x0C , L_12 ) ;
F_32 ( 0x3d3 , 0x01 , L_12 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_26 ( V_2 , 0xE0 , 64 , V_43 , L_13 ) ;
F_26 ( V_2 , 0xE2 , 32 , V_43 + 1 , L_14 ) ;
}
static void F_34 ( struct V_1 * V_2 , const char * V_37 , unsigned int V_34 , unsigned int V_44 )
{
T_1 V_45 ;
T_1 V_46 , V_35 , V_47 ;
F_10 ( V_2 , V_34 , & V_45 ) ;
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
static void F_35 ( struct V_1 * V_2 , const char * V_37 , unsigned int V_34 , unsigned int V_44 )
{
T_1 V_45 ;
T_1 V_46 , V_35 , V_47 ;
F_10 ( V_2 , V_34 , & V_45 ) ;
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
T_1 V_49 ;
F_26 ( V_2 , 0x40 , 64 , V_43 , L_17 ) ;
F_26 ( V_2 , 0x90 , 16 , V_43 + 1 , L_18 ) ;
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
T_3 V_44 ;
F_5 ( V_2 , V_50 , & V_44 ) ;
if ( V_44 & V_51 )
F_26 ( V_2 , V_52 , 128 , V_43 ,
L_27 ) ;
F_5 ( V_2 , V_53 , & V_44 ) ;
if ( V_44 & V_54 )
F_26 ( V_2 , V_55 , 64 , V_43 + 1 ,
L_28 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_3 V_44 ;
F_5 ( V_2 , V_50 , & V_44 ) ;
if ( V_44 & V_56 )
F_26 ( V_2 , V_52 , 128 , V_43 ,
L_29 ) ;
F_5 ( V_2 , V_57 , & V_44 ) ;
if ( V_44 & V_58 )
F_26 ( V_2 , V_59 , 64 , V_43 + 1 ,
L_30 ) ;
}
static void F_39 ( struct V_1 * V_2 , unsigned V_60 , const char * V_37 , int V_61 )
{
T_1 V_62 ;
T_1 V_35 , V_47 ;
F_10 ( V_2 , V_60 , & V_62 ) ;
if ( ! ( V_62 & 1 ) )
return;
V_47 = V_62 & 0xfffc ;
if ( V_61 ) {
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
static void F_41 ( struct V_1 * V_2 , unsigned V_60 , const char * V_37 )
{
T_1 V_62 ;
T_1 V_46 , V_47 ;
F_10 ( V_2 , V_60 , & V_62 ) ;
if ( ! ( V_62 & 1 ) )
return;
V_47 = V_62 & 0xfffc ;
V_46 = ( V_62 >> 16 ) & 0xfc ;
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
if ( V_2 -> V_22 & 0x10 )
F_26 ( V_2 , 0x48 , 256 , V_43 ,
L_38 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_26 ( V_2 , 0x70 , 128 , V_43 + 1 ,
L_39 ) ;
F_26 ( V_2 , 0x90 , 16 , V_43 + 2 , L_40 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_26 ( V_2 , 0x88 , 128 , V_43 , L_41 ) ;
F_26 ( V_2 , 0xd0 , 16 , V_43 + 1 , L_42 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_1 * V_63 ;
T_2 V_64 ;
F_47 ( & V_2 -> V_2 , L_43
L_44 ) ;
F_48 (pdev, &dev->subordinate->devices, bus_list) {
F_27 ( V_63 , V_65 , & V_64 ) ;
if ( V_64 & V_66 )
F_49 ( V_63 , V_65 , V_64 & ~ V_66 ) ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
T_3 V_67 ;
if ( V_68 < 1 )
V_67 = 0 ;
else
V_67 = 0x1f ;
F_6 ( & V_2 -> V_2 , L_45 ,
V_67 == 0 ? L_46 : L_47 ) ;
F_7 ( V_2 , 0x58 , V_67 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_3 V_69 ;
#define F_52 8
F_5 ( V_2 , 0x5B , & V_69 ) ;
if ( ! ( V_69 & F_52 ) ) {
F_6 ( & V_2 -> V_2 , L_48 ) ;
F_7 ( V_2 , 0x5B , V_69 | F_52 ) ;
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
if ( V_2 -> V_70 == 0 && V_2 -> V_71 -> V_72 == 0 )
V_73 = 1 ;
}
static void F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 && V_2 -> V_22 <= 0x12 ) {
F_6 ( & V_2 -> V_2 , L_51
L_52 , V_2 -> V_22 ) ;
V_2 -> V_74 -> V_75 |= V_76 ;
}
}
static void F_56 ( struct V_1 * V_5 )
{
T_3 V_77 ;
F_5 ( V_5 , 0x42 , & V_77 ) ;
V_77 &= 0xf ;
if ( V_77 && ( V_77 != 2 ) )
V_5 -> V_77 = V_77 ;
}
static void F_57 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_78 ) {
case V_21 :
V_79 = F_58 ( V_2 -> V_70 ) ;
V_80 = F_58 ( V_2 -> V_70 ) ;
break;
case V_81 :
case V_82 :
V_79 = 15 ;
break;
case V_83 :
V_79 = 16 ;
break;
case V_23 :
case V_84 :
case V_85 :
case V_86 :
V_79 = 17 ;
break;
}
}
static void F_59 ( struct V_1 * V_2 )
{
T_3 V_77 , V_87 ;
if ( V_79 == - 1 )
return;
V_87 = V_2 -> V_77 ;
if ( ! V_87 || V_87 > 15 )
return;
if ( V_2 -> V_71 -> V_72 != 0 || F_58 ( V_2 -> V_70 ) > V_80 ||
F_58 ( V_2 -> V_70 ) < V_79 )
return;
F_5 ( V_2 , V_88 , & V_77 ) ;
if ( V_87 != V_77 ) {
F_6 ( & V_2 -> V_2 , L_53 ,
V_77 , V_87 ) ;
F_60 ( 15 ) ;
F_7 ( V_2 , V_88 , V_87 ) ;
}
}
static void F_61 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0xfc , 0 ) ;
F_27 ( V_2 , V_89 , & V_2 -> V_78 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 , V_90 , 0 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
T_1 V_91 ;
F_10 ( V_2 , 0x4C , & V_91 ) ;
if ( ( V_91 & 6 ) != 6 ) {
V_91 |= 6 ;
F_47 ( & V_2 -> V_2 , L_54 ) ;
F_63 ( V_2 , 0x4C , V_91 ) ;
F_10 ( V_2 , 0x84 , & V_91 ) ;
V_91 |= ( 1 << 23 ) ;
F_63 ( V_2 , 0x84 , V_91 ) ;
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
V_2 -> V_92 = 1 ;
}
static void F_67 ( struct V_1 * V_2 )
{
T_3 V_60 ;
F_5 ( V_2 , 0x41 , & V_60 ) ;
if ( V_60 & 2 ) {
V_60 &= ~ 2 ;
F_6 ( & V_2 -> V_2 , L_55 , V_60 ) ;
F_7 ( V_2 , 0x41 , V_60 ) ;
}
}
static void F_68 ( struct V_1 * V_63 )
{
T_2 V_93 ;
if ( V_63 -> V_22 != 0x04 )
return;
F_27 ( V_63 , 0x40 , & V_93 ) ;
if ( V_93 & ( 1 << 6 ) ) {
V_93 &= ~ ( 1 << 6 ) ;
F_49 ( V_63 , 0x40 , V_93 ) ;
F_6 ( & V_63 -> V_2 , L_56 ) ;
}
}
static void F_69 ( struct V_1 * V_63 )
{
T_3 V_67 ;
F_5 ( V_63 , V_94 , & V_67 ) ;
if ( V_67 == 0x01 ) {
F_5 ( V_63 , 0x40 , & V_67 ) ;
F_7 ( V_63 , 0x40 , V_67 | 1 ) ;
F_7 ( V_63 , 0x9 , 1 ) ;
F_7 ( V_63 , 0xa , 6 ) ;
F_7 ( V_63 , 0x40 , V_67 ) ;
V_63 -> V_95 = V_96 ;
F_6 ( & V_63 -> V_2 , L_57 ) ;
}
}
static void F_70 ( struct V_1 * V_63 )
{
T_3 V_97 ;
F_5 ( V_63 , V_98 , & V_97 ) ;
if ( V_97 & 5 ) {
V_97 &= ~ 5 ;
V_63 -> V_95 &= ~ 5 ;
F_7 ( V_63 , V_98 , V_97 ) ;
}
}
static void F_71 ( struct V_1 * V_63 )
{
T_3 V_97 ;
F_5 ( V_63 , V_98 , & V_97 ) ;
if ( ( ( V_97 & 1 ) && ! ( V_97 & 4 ) ) || ( ( V_97 & 4 ) && ! ( V_97 & 1 ) ) ) {
F_6 ( & V_63 -> V_2 , L_58 ) ;
V_97 &= ~ 5 ;
V_63 -> V_95 &= ~ 5 ;
F_7 ( V_63 , V_98 , V_97 ) ;
}
}
static void F_72 ( struct V_1 * V_63 )
{
V_63 -> V_99 |= V_100 ;
}
static void F_73 ( struct V_1 * V_2 )
{
V_2 -> V_95 = V_101 << 8 ;
}
static void F_74 ( struct V_1 * V_2 )
{
if ( F_75 ( V_2 -> V_102 == V_103 ) ) {
if ( V_2 -> V_78 == V_104 )
switch( V_2 -> V_105 ) {
case 0x8025 :
case 0x8070 :
case 0x8088 :
case 0x1626 :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_107 )
switch( V_2 -> V_105 ) {
case 0x80b1 :
case 0x80b2 :
case 0x8093 :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_108 )
switch( V_2 -> V_105 ) {
case 0x8030 :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_109 )
switch ( V_2 -> V_105 ) {
case 0x8070 :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_110 )
switch ( V_2 -> V_105 ) {
case 0x80c9 :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_111 )
switch ( V_2 -> V_105 ) {
case 0x1751 :
case 0x1821 :
case 0x1897 :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_112 )
switch ( V_2 -> V_105 ) {
case 0x184b :
case 0x186a :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_113 )
switch ( V_2 -> V_105 ) {
case 0x80f2 :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_114 )
switch ( V_2 -> V_105 ) {
case 0x1882 :
case 0x1977 :
V_106 = 1 ;
}
} else if ( F_75 ( V_2 -> V_102 == V_115 ) ) {
if ( V_2 -> V_78 == V_112 )
switch( V_2 -> V_105 ) {
case 0x088C :
case 0x0890 :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_113 )
switch ( V_2 -> V_105 ) {
case 0x12bc :
case 0x12bd :
case 0x006a :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_116 )
switch ( V_2 -> V_105 ) {
case 0x12bf :
V_106 = 1 ;
}
} else if ( F_75 ( V_2 -> V_102 == V_117 ) ) {
if ( V_2 -> V_78 == V_112 )
switch( V_2 -> V_105 ) {
case 0xC00C :
V_106 = 1 ;
}
} else if ( F_75 ( V_2 -> V_102 == V_118 ) ) {
if ( V_2 -> V_78 == V_112 )
switch( V_2 -> V_105 ) {
case 0x0058 :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_119 )
switch( V_2 -> V_105 ) {
case 0xB16C :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_120 )
switch( V_2 -> V_105 ) {
case 0x00b8 :
case 0x00b9 :
case 0x00ba :
V_106 = 1 ;
}
else if ( V_2 -> V_78 == V_121 )
switch ( V_2 -> V_105 ) {
case 0x001A :
V_106 = 1 ;
}
}
}
static void F_76 ( struct V_1 * V_2 )
{
T_2 V_62 ;
if ( F_77 ( ! V_106 ) )
return;
F_27 ( V_2 , 0xF2 , & V_62 ) ;
if ( V_62 & 0x8 ) {
F_49 ( V_2 , 0xF2 , V_62 & ( ~ 0x8 ) ) ;
F_27 ( V_2 , 0xF2 , & V_62 ) ;
if ( V_62 & 0x8 )
F_6 ( & V_2 -> V_2 , L_59 , V_62 ) ;
else
F_6 ( & V_2 -> V_2 , L_60 ) ;
}
}
static void F_78 ( struct V_1 * V_2 )
{
T_1 V_122 ;
if ( F_77 ( ! V_106 ) )
return;
F_79 ( V_123 ) ;
F_10 ( V_2 , 0xF0 , & V_122 ) ;
V_123 = F_80 ( V_122 & 0xFFFFC000 , 0x4000 ) ;
if ( V_123 == NULL )
return;
}
static void F_81 ( struct V_1 * V_2 )
{
T_1 V_62 ;
if ( F_77 ( ! V_106 || ! V_123 ) )
return;
V_62 = F_82 ( V_123 + 0x3418 ) ;
F_83 ( V_62 & 0xFFFFFFF7 , V_123 + 0x3418 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( F_77 ( ! V_106 || ! V_123 ) )
return;
F_85 ( V_123 ) ;
V_123 = NULL ;
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
T_3 V_62 = 0 ;
F_5 ( V_2 , 0x77 , & V_62 ) ;
if ( V_62 & 0x10 ) {
F_6 ( & V_2 -> V_2 , L_62 ) ;
F_7 ( V_2 , 0x77 , V_62 & ~ 0x10 ) ;
}
}
static void F_88 ( struct V_1 * V_2 )
{
T_3 V_60 ;
T_2 V_124 ;
F_5 ( V_2 , V_125 , & V_60 ) ;
F_7 ( V_2 , V_125 , V_60 | ( 1 << 6 ) ) ;
F_27 ( V_2 , V_89 , & V_124 ) ;
if ( ( ( V_124 & 0xfff0 ) != 0x0960 ) && ( V_124 != 0x0018 ) ) {
F_7 ( V_2 , V_125 , V_60 ) ;
return;
}
V_2 -> V_78 = V_124 ;
F_87 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
T_3 V_62 ;
int V_126 = 0 ;
if ( F_77 ( V_2 -> V_102 == V_103 ) ) {
if ( V_2 -> V_78 == V_81 )
V_126 = 1 ;
}
if ( ! V_126 )
return;
F_5 ( V_2 , 0x50 , & V_62 ) ;
if ( V_62 & 0xc0 ) {
F_7 ( V_2 , 0x50 , V_62 & ( ~ 0xc0 ) ) ;
F_5 ( V_2 , 0x50 , & V_62 ) ;
if ( V_62 & 0xc0 )
F_6 ( & V_2 -> V_2 , L_63 , V_62 ) ;
else
F_6 ( & V_2 -> V_2 , L_64 ) ;
}
}
static void F_90 ( struct V_1 * V_63 )
{
T_1 V_127 , V_128 , V_95 ;
T_3 V_129 ;
if ( F_91 ( V_63 -> V_70 ) )
return;
F_10 ( V_63 , 0x40 , & V_127 ) ;
F_10 ( V_63 , 0x80 , & V_128 ) ;
V_127 &= ~ 0x00CFF302 ;
V_128 &= ~ ( 1 << 24 ) ;
switch ( V_63 -> V_78 ) {
case V_130 :
case V_131 :
case V_132 :
V_127 |= 0x0002A100 ;
break;
case V_133 :
case V_134 :
V_128 |= ( 1 << 24 ) ;
case V_135 :
case V_136 :
case V_137 :
V_127 |= 0x00C2A1B3 ;
break;
case V_138 :
V_127 |= 0x00C00000 ;
break;
}
F_63 ( V_63 , 0x40 , V_127 ) ;
F_63 ( V_63 , 0x80 , V_128 ) ;
F_5 ( V_63 , V_139 , & V_129 ) ;
V_63 -> V_140 = V_129 & 0x7f ;
V_63 -> V_141 = ! ! ( V_129 & 0x80 ) ;
F_10 ( V_63 , V_142 , & V_95 ) ;
V_63 -> V_95 = V_95 >> 8 ;
}
static void F_92 ( struct V_1 * V_63 )
{
int V_143 ;
if ( ( V_63 -> V_95 >> 8 ) != 0xff00 )
return;
if ( F_93 ( V_63 , 0 ) && F_25 ( V_63 , 0 ) )
F_94 ( & V_144 , & V_63 -> V_29 [ 0 ] ) ;
for ( V_143 = 1 ; V_143 < 6 ; V_143 ++ ) {
memset ( & V_63 -> V_29 [ V_143 ] , 0 , sizeof( V_63 -> V_29 [ V_143 ] ) ) ;
}
}
static void F_95 ( struct V_1 * V_63 )
{
F_96 ( V_63 ) ;
V_63 -> V_145 = 1 ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_96 ( V_2 ) ;
V_2 -> V_145 = 1 ;
F_47 ( & V_2 -> V_2 , L_65 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
V_146 = 120 ;
V_2 -> V_147 = 1 ;
}
static void F_99 ( struct V_1 * V_2 )
{
if ( V_148 || V_149 )
return;
V_2 -> V_150 = V_151 ;
F_6 ( & V_2 -> V_2 , L_66 ,
V_2 -> V_152 , V_2 -> V_78 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
T_2 V_153 ;
if ( V_148 )
return;
F_27 ( V_2 , V_154 , & V_153 ) ;
V_153 |= V_155 ;
F_49 ( V_2 , V_154 , V_153 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_152 , V_2 -> V_78 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
T_1 V_156 ;
T_3 V_77 ;
if ( V_148 )
return;
F_10 ( V_2 , V_157 , & V_156 ) ;
F_63 ( V_2 , V_157 , V_156 |
V_158 ) ;
for ( V_77 = 0x10 ; V_77 < 0x10 + 32 ; V_77 ++ ) {
F_102 ( V_77 , V_159 ) ;
F_102 ( 0x00 , V_160 ) ;
}
F_63 ( V_2 , V_157 , V_156 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_152 , V_2 -> V_78 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
T_1 V_156 ;
if ( V_148 )
return;
if ( ( V_2 -> V_22 == V_161 ) ||
( V_2 -> V_22 == V_162 ) )
return;
F_10 ( V_2 , V_163 , & V_156 ) ;
V_156 &= ~ V_164 ;
F_63 ( V_2 , V_163 , V_156 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_152 , V_2 -> V_78 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
T_2 V_153 ;
if ( V_148 )
return;
F_27 ( V_2 , V_165 , & V_153 ) ;
if ( ! V_153 ) {
F_6 ( & V_2 -> V_2 , L_68
L_69 , V_2 -> V_152 , V_2 -> V_78 ) ;
return;
}
F_49 ( V_2 , V_165 , 0 ) ;
F_6 ( & V_2 -> V_2 , L_67 ,
V_2 -> V_152 , V_2 -> V_78 ) ;
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
unsigned int V_166 ;
if ( V_2 -> V_22 >= 2 )
return;
for ( V_166 = 0 ; V_166 <= 1 ; V_166 ++ )
if ( F_25 ( V_2 , V_166 ) == 0x80 &&
( F_93 ( V_2 , V_166 ) & 0x80 ) ) {
struct V_29 * V_30 = & V_2 -> V_29 [ V_166 ] ;
F_6 ( & V_2 -> V_2 ,
L_70 ,
V_166 ) ;
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0xff ;
}
}
static void F_107 ( struct V_1 * V_2 )
{
unsigned int V_167 = ( V_2 -> V_105 & 0xf0 ) >> 4 ;
unsigned int V_168 = V_2 -> V_105 & 0xf ;
switch ( V_2 -> V_78 ) {
case V_169 :
if ( V_2 -> V_102 == V_170 &&
V_2 -> V_105 == 0x0299 )
return;
case V_171 :
case V_172 :
case V_173 :
case V_174 :
if ( V_167 ) {
F_6 ( & V_2 -> V_2 , L_71
L_72
L_73 ,
V_2 -> V_78 , V_167 , V_168 ) ;
V_2 -> V_95 = ( V_175 << 8 ) |
( V_2 -> V_95 & 0xff ) ;
}
}
}
static void F_108 ( struct V_1 * V_2 )
{
T_2 V_64 , V_176 ;
T_3 T_4 * V_177 ;
T_3 V_178 ;
switch ( V_2 -> V_78 ) {
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
F_27 ( V_2 , V_65 , & V_64 ) ;
if ( ! ( V_64 & V_179 ) || ! F_93 ( V_2 , 0 ) )
return;
if ( V_2 -> V_180 ) {
F_27 ( V_2 , V_2 -> V_180 + V_181 , & V_176 ) ;
if ( ( V_176 & V_182 ) != V_183 )
return;
}
V_177 = F_109 ( F_93 ( V_2 , 0 ) , 8 ) ;
if ( ! V_177 ) {
F_47 ( & V_2 -> V_2 , L_74 ) ;
return;
}
V_178 = F_110 ( V_177 + 3 ) ;
if ( V_178 == 0 ) {
F_47 ( & V_2 -> V_2 , L_75
L_76 ) ;
F_111 ( 1 , V_177 + 3 ) ;
}
F_85 ( V_177 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_77 ) ;
F_113 ( V_2 , V_184 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
if ( V_2 -> V_95 == V_185 ) {
F_6 ( & V_2 -> V_2 , L_78 ) ;
V_2 -> V_95 = V_186 ;
}
}
static void F_115 ( struct V_1 * V_2 )
{
T_2 V_187 ;
F_27 ( V_2 , 0x40 , & V_187 ) ;
if ( V_187 & 0x200 ) {
F_6 ( & V_2 -> V_2 , L_79 ) ;
V_2 -> V_188 = 1 ;
}
}
static void F_116 ( struct V_1 * V_2 )
{
T_5 V_189 ;
if ( F_5 ( V_2 , 0xf41 , & V_189 ) == 0 ) {
if ( ! ( V_189 & 0x20 ) ) {
F_7 ( V_2 , 0xf41 , V_189 | 0x20 ) ;
F_6 ( & V_2 -> V_2 ,
L_80 ) ;
}
}
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_1 * V_18 = F_4 ( V_20 ,
V_190 , NULL ) ;
T_5 V_189 ;
V_18 = F_4 ( V_20 , V_190 , V_18 ) ;
if ( ! V_18 )
return;
F_17 ( V_18 ) ;
if ( F_5 ( V_2 , 0x76 , & V_189 ) == 0 ) {
if ( V_189 & 0x40 ) {
F_7 ( V_2 , 0x76 , V_189 ^ 0x40 ) ;
F_6 ( & V_2 -> V_2 ,
L_81 ) ;
}
}
if ( F_5 ( V_2 , 0x72 , & V_189 ) == 0 ) {
if ( V_189 != 0 ) {
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
if ( ( V_2 -> V_78 == V_191 ) ||
( V_2 -> V_78 == V_192 ) ||
( V_2 -> V_78 == V_193 ) ||
( V_2 -> V_78 == V_194 ) ||
( ( V_2 -> V_78 == V_195 ) &&
( V_2 -> V_22 & 0xf0 ) == 0x0 ) ) {
if ( V_2 -> V_196 )
V_2 -> V_196 -> V_197 = 0x80 ;
}
}
static void F_119 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_10 ( V_2 , 0xf4 , & V_15 ) ;
if ( V_15 == 0x05719000 ) {
int V_198 = F_120 ( V_2 ) ;
if ( V_198 > 2048 )
F_121 ( V_2 , 2048 ) ;
}
}
static void F_122 ( struct V_1 * V_2 )
{
T_3 V_60 ;
if ( F_5 ( V_2 , 0xF4 , & V_60 ) == 0 && ! ( V_60 & 0x02 ) ) {
F_6 ( & V_2 -> V_2 , L_83 ) ;
F_7 ( V_2 , 0xF4 , V_60 | 0x02 ) ;
}
}
static void F_123 ( struct V_1 * V_2 )
{
if ( V_199 ) {
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
if ( V_2 -> V_74 ) {
F_47 ( & V_2 -> V_2 , L_85
L_86 ) ;
V_2 -> V_74 -> V_75 |= V_200 ;
}
}
static void F_128 ( struct V_1 * V_201 )
{
struct V_1 * V_202 ;
V_202 = F_129 ( V_201 -> V_71 , F_130 ( 1 , 0 ) ) ;
if ( V_202 ) {
if ( V_202 -> V_78 == 0x9602 )
F_127 ( V_202 ) ;
F_17 ( V_202 ) ;
}
}
static int F_131 ( struct V_1 * V_2 )
{
int V_203 , V_204 = 48 ;
V_203 = F_132 ( V_2 , V_205 ) ;
while ( V_203 && V_204 -- ) {
T_3 V_41 ;
if ( F_5 ( V_2 , V_203 + V_206 ,
& V_41 ) == 0 )
{
F_6 ( & V_2 -> V_2 , L_87 ,
V_41 & V_207 ?
L_88 : L_89 ) ;
return ( V_41 & V_207 ) != 0 ;
}
V_203 = F_133 ( V_2 , V_203 ,
V_205 ) ;
}
return 0 ;
}
static void F_134 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 && ! F_131 ( V_2 ) ) {
F_47 ( & V_2 -> V_2 , L_85
L_86 ) ;
V_2 -> V_74 -> V_75 |= V_200 ;
}
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_1 * V_63 ;
if ( ! V_2 -> V_74 )
return;
V_63 = F_129 ( V_2 -> V_71 , 0 ) ;
if ( ! V_63 )
return;
if ( ! F_131 ( V_2 ) && ! F_131 ( V_63 ) ) {
F_47 ( & V_2 -> V_2 , L_85
L_86 ) ;
V_2 -> V_74 -> V_75 |= V_200 ;
}
F_17 ( V_63 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
int V_203 , V_204 = 48 ;
V_203 = F_132 ( V_2 , V_205 ) ;
while ( V_203 && V_204 -- ) {
T_3 V_41 ;
if ( F_5 ( V_2 , V_203 + V_206 ,
& V_41 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_90 ) ;
F_7 ( V_2 , V_203 + V_206 ,
V_41 | V_207 ) ;
}
V_203 = F_133 ( V_2 , V_203 ,
V_205 ) ;
}
}
static void F_137 ( struct V_1 * V_2 )
{
const char * V_208 = F_138 ( V_209 ) ;
if ( V_208 &&
( strstr ( V_208 , L_91 ) ||
strstr ( V_208 , L_92 ) ) ) {
F_6 ( & V_2 -> V_2 ,
L_93 ) ;
V_2 -> V_145 = 1 ;
}
}
static void F_139 ( struct V_1 * V_2 )
{
T_1 V_210 ;
if ( ! F_140 ( V_2 , V_211 ) )
return;
F_10 ( V_2 , 0x74 , & V_210 ) ;
if ( V_210 & ( ( 1 << 2 ) | ( 1 << 15 ) ) ) {
F_141 ( V_212 L_94 ) ;
V_210 &= ~ ( ( 1 << 2 ) | ( 1 << 15 ) ) ;
F_63 ( V_2 , 0x74 , V_210 ) ;
}
}
static int F_142 ( struct V_1 * V_2 )
{
int V_203 , V_204 = 48 ;
int V_213 = 0 ;
V_203 = F_132 ( V_2 , V_205 ) ;
while ( V_203 && V_204 -- ) {
T_3 V_41 ;
if ( V_213 < 1 )
V_213 = 1 ;
if ( F_5 ( V_2 , V_203 + V_206 ,
& V_41 ) == 0 ) {
if ( V_41 & V_207 ) {
if ( V_213 < 2 ) {
V_213 = 2 ;
break;
}
}
}
V_203 = F_133 ( V_2 , V_203 ,
V_205 ) ;
}
return V_213 ;
}
static int F_143 ( struct V_1 * V_201 )
{
struct V_1 * V_2 ;
int V_203 ;
int V_143 , V_214 ;
int V_213 = 0 ;
V_214 = V_201 -> V_70 >> 3 ;
for ( V_143 = V_214 + 1 ; V_143 < 0x20 ; V_143 ++ ) {
V_2 = F_129 ( V_201 -> V_71 , F_130 ( V_143 , 0 ) ) ;
if ( ! V_2 )
continue;
V_203 = F_132 ( V_2 , V_215 ) ;
if ( V_203 != 0 ) {
F_17 ( V_2 ) ;
break;
}
if ( F_142 ( V_2 ) ) {
V_213 = 1 ;
F_17 ( V_2 ) ;
break;
}
F_17 ( V_2 ) ;
}
return V_213 ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_203 , V_216 ;
int V_32 = 0 ;
T_2 V_41 , V_217 ;
V_203 = F_132 ( V_2 , V_215 ) ;
if ( ! V_203 )
goto V_218;
F_27 ( V_2 , V_203 + V_219 , & V_41 ) ;
V_216 = ( ( V_41 >> 10 ) & 1 ) ?
V_220 : V_221 ;
F_27 ( V_2 , V_203 + V_216 , & V_217 ) ;
if ( V_217 & ( 1 << 6 ) )
V_32 = 1 ;
V_218:
return V_32 ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_1 * V_201 ;
int V_203 ;
int V_143 , V_214 ;
int V_213 = 0 ;
V_214 = V_2 -> V_70 >> 3 ;
for ( V_143 = V_214 ; V_143 >= 0 ; V_143 -- ) {
V_201 = F_129 ( V_2 -> V_71 , F_130 ( V_143 , 0 ) ) ;
if ( ! V_201 )
continue;
V_203 = F_132 ( V_201 , V_215 ) ;
if ( V_203 != 0 ) {
V_213 = 1 ;
break;
}
F_17 ( V_201 ) ;
}
if ( ! V_213 )
return;
if ( V_201 == V_2 && F_144 ( V_201 ) &&
F_143 ( V_201 ) )
goto V_218;
if ( F_131 ( V_201 ) )
goto V_218;
F_136 ( V_2 ) ;
V_218:
F_17 ( V_201 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
int V_203 , V_204 = 48 ;
V_203 = F_132 ( V_2 , V_205 ) ;
while ( V_203 && V_204 -- ) {
T_3 V_41 ;
if ( F_5 ( V_2 , V_203 + V_206 ,
& V_41 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_95 ) ;
F_7 ( V_2 , V_203 + V_206 ,
V_41 & ~ V_207 ) ;
}
V_203 = F_133 ( V_2 , V_203 ,
V_205 ) ;
}
}
static void F_147 ( struct V_1 * V_2 , int V_222 )
{
struct V_1 * V_201 ;
int V_203 ;
int V_213 ;
if ( ! F_148 () )
return;
V_213 = F_142 ( V_2 ) ;
if ( V_213 == 0 )
return;
V_201 = F_149 ( 0 , F_130 ( 0 , 0 ) ) ;
if ( V_201 == NULL ) {
F_47 ( & V_2 -> V_2 ,
L_96 ) ;
return;
}
V_203 = F_132 ( V_201 , V_215 ) ;
if ( V_203 != 0 ) {
if ( V_213 == 1 ) {
if ( V_222 )
F_136 ( V_2 ) ;
else
F_145 ( V_2 ) ;
}
goto V_218;
}
if ( V_213 == 1 )
goto V_218;
F_146 ( V_2 ) ;
V_218:
F_17 ( V_201 ) ;
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
V_2 -> V_99 |= V_223 ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( V_224 , V_225 ,
NULL ) ;
if ( ! V_18 )
return;
if ( ( V_18 -> V_22 < 0x3B ) && ( V_18 -> V_22 >= 0x30 ) )
V_2 -> V_99 |= V_223 ;
F_17 ( V_18 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 < 0x18 ) {
F_6 ( & V_2 -> V_2 , L_97 ) ;
V_2 -> V_99 |= V_223 ;
}
}
static void F_155 ( struct V_1 * V_2 )
{
V_2 -> V_226 = 1 ;
}
static void F_156 ( struct V_1 * V_2 )
{
T_3 V_227 ;
T_3 V_228 ;
T_3 V_229 ;
if ( F_91 ( V_2 -> V_70 ) )
return;
F_5 ( V_2 , 0xB7 , & V_229 ) ;
if ( V_229 & 0x02 )
return;
F_5 ( V_2 , 0x8E , & V_227 ) ;
F_7 ( V_2 , 0x8E , 0xAA ) ;
F_5 ( V_2 , 0x8D , & V_228 ) ;
F_7 ( V_2 , 0x8D , 0xB7 ) ;
F_7 ( V_2 , 0xB7 , V_229 | 0x02 ) ;
F_7 ( V_2 , 0x8E , V_227 ) ;
F_7 ( V_2 , 0x8D , V_228 ) ;
F_157 ( & V_2 -> V_2 , L_98 ) ;
F_157 ( & V_2 -> V_2 , L_99 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
T_3 V_227 ;
T_3 V_229 ;
if ( F_91 ( V_2 -> V_70 ) )
return;
if ( V_2 -> V_78 == V_230 ||
V_2 -> V_78 == V_231 ) {
F_7 ( V_2 , 0xf9 , 0xfc ) ;
F_7 ( V_2 , 0x150 , 0x10 ) ;
F_7 ( V_2 , 0xf9 , 0x00 ) ;
F_7 ( V_2 , 0xfc , 0x01 ) ;
F_7 ( V_2 , 0xe1 , 0x32 ) ;
F_7 ( V_2 , 0xfc , 0x00 ) ;
F_157 ( & V_2 -> V_2 , L_100 ) ;
}
F_5 ( V_2 , 0xCB , & V_229 ) ;
if ( V_229 & 0x02 )
return;
F_5 ( V_2 , 0xCA , & V_227 ) ;
F_7 ( V_2 , 0xCA , 0x57 ) ;
F_7 ( V_2 , 0xCB , V_229 | 0x02 ) ;
F_7 ( V_2 , 0xCA , V_227 ) ;
F_157 ( & V_2 -> V_2 , L_101 ) ;
F_157 ( & V_2 -> V_2 , L_99 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
T_1 V_232 ;
F_10 ( V_2 , V_233 , & V_232 ) ;
F_63 ( V_2 , V_233 , V_232 | V_234 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_2 , L_102 ) ;
V_2 -> V_95 = V_235 ;
}
static void F_161 ( struct V_1 * V_2 )
{
V_2 -> V_236 = 1 ;
}
static void F_162 ( struct V_1 * V_2 )
{
int V_237 ;
T_2 V_238 ;
if ( V_239 == V_240 )
return;
V_237 = F_27 ( V_2 , 0x48 , & V_238 ) ;
if ( V_237 ) {
F_163 ( & V_2 -> V_2 , L_103
L_104 ) ;
return;
}
if ( ! ( V_238 & ( 1 << 10 ) ) )
return;
V_238 &= ~ ( 1 << 10 ) ;
V_237 = F_49 ( V_2 , 0x48 , V_238 ) ;
if ( V_237 ) {
F_163 ( & V_2 -> V_2 , L_105
L_104 ) ;
return;
}
F_164 ( L_106
L_107 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
int V_241 ;
T_3 V_62 ;
V_241 = F_5 ( V_2 , 0x00D0 , & V_62 ) ;
if ( V_241 )
return;
V_2 -> V_29 [ 2 ] . V_32 = V_2 -> V_29 [ 2 ] . V_31 + ( ( V_242 ) 1 << V_62 ) - 1 ;
V_241 = F_5 ( V_2 , 0x00D1 , & V_62 ) ;
if ( V_241 )
return;
V_2 -> V_29 [ 4 ] . V_32 = V_2 -> V_29 [ 4 ] . V_31 + ( ( V_242 ) 1 << V_62 ) - 1 ;
}
static T_6 F_166 ( struct V_1 * V_2 ,
void (* F_167)( struct V_1 * V_2 ) )
{
T_6 V_243 = F_168 ( 0 , 0 ) ;
F_169 ( & V_2 -> V_2 , L_108 , F_167 ) ;
if ( V_244 ) {
F_170 ( L_109 ,
F_167 , F_171 ( V_245 ) , F_172 ( & V_2 -> V_2 ) ) ;
V_243 = F_173 () ;
}
return V_243 ;
}
static void F_174 ( struct V_1 * V_2 , T_6 V_243 ,
void (* F_167)( struct V_1 * V_2 ) )
{
T_6 V_246 , V_247 ;
unsigned long long V_248 ;
if ( V_244 ) {
V_247 = F_173 () ;
V_246 = F_175 ( V_247 , V_243 ) ;
V_248 = ( unsigned long long ) F_176 ( V_246 ) >> 10 ;
F_170 ( L_110 ,
F_167 , V_248 , F_172 ( & V_2 -> V_2 ) ) ;
}
}
static void F_177 ( struct V_1 * V_2 )
{
void T_4 * V_249 = F_178 ( V_2 , 0 , 0 ) ;
if ( V_249 == NULL ) {
F_47 ( & V_2 -> V_2 , L_111 ) ;
return;
}
if ( F_82 ( V_249 + V_250 ) != 0 ) {
F_47 ( & V_2 -> V_2 , L_112
L_76 ) ;
F_83 ( 0 , V_249 + V_250 ) ;
}
F_179 ( V_2 , V_249 ) ;
}
static void F_180 ( struct V_1 * V_2 )
{
V_2 -> V_251 = 1 ;
}
static void F_181 ( struct V_1 * V_2 , struct V_252 * V_253 ,
struct V_252 * V_32 )
{
T_6 V_243 ;
for (; V_253 < V_32 ; V_253 ++ )
if ( ( V_253 -> V_95 == ( T_1 ) ( V_2 -> V_95 >> V_253 -> V_254 ) ||
V_253 -> V_95 == ( T_1 ) V_255 ) &&
( V_253 -> V_152 == V_2 -> V_152 ||
V_253 -> V_152 == ( T_2 ) V_255 ) &&
( V_253 -> V_78 == V_2 -> V_78 ||
V_253 -> V_78 == ( T_2 ) V_255 ) ) {
V_243 = F_166 ( V_2 , V_253 -> V_256 ) ;
V_253 -> V_256 ( V_2 ) ;
F_174 ( V_2 , V_243 , V_253 -> V_256 ) ;
}
}
void F_182 ( enum V_257 V_258 , struct V_1 * V_2 )
{
struct V_252 * V_31 , * V_32 ;
switch( V_258 ) {
case V_259 :
V_31 = V_260 ;
V_32 = V_261 ;
break;
case V_262 :
V_31 = V_263 ;
V_32 = V_264 ;
break;
case V_265 :
if ( ! V_266 )
return;
V_31 = V_267 ;
V_32 = V_268 ;
break;
case V_269 :
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
default:
return;
}
F_181 ( V_2 , V_31 , V_32 ) ;
}
static int T_7 F_183 ( void )
{
struct V_1 * V_2 = NULL ;
T_3 V_281 = 0 ;
T_3 V_67 ;
if ( V_282 )
F_141 ( V_283 L_113 ,
V_282 << 2 ) ;
V_266 = true ;
F_184 (dev) {
F_182 ( V_265 , V_2 ) ;
if ( ! V_282 ) {
F_5 ( V_2 , V_284 , & V_67 ) ;
if ( ! V_281 )
V_281 = V_67 ;
if ( ! V_67 || V_281 == V_67 )
continue;
F_141 ( V_283 L_114
L_115 , V_281 << 2 , V_67 << 2 ,
V_285 << 2 ) ;
V_282 = V_285 ;
}
}
if ( ! V_282 ) {
F_141 ( V_283 L_116 ,
V_281 << 2 , V_285 << 2 ) ;
V_282 = V_281 ? V_281 : V_285 ;
}
return 0 ;
}
static int F_185 ( struct V_1 * V_2 , int V_286 )
{
int V_203 ;
if ( V_2 -> V_95 == V_287 ) {
V_203 = F_140 ( V_2 , V_288 ) ;
if ( ! V_203 )
return - V_289 ;
if ( V_286 )
return 0 ;
F_7 ( V_2 , V_203 + 0x4 , 1 ) ;
F_186 ( 100 ) ;
return 0 ;
} else {
return - V_289 ;
}
}
static int F_187 ( struct V_1 * V_2 , int V_286 )
{
if ( V_286 )
return 0 ;
if ( ! F_188 ( V_2 ) )
F_163 ( & V_2 -> V_2 , L_117 ) ;
F_189 ( V_2 , V_290 , V_291 ) ;
F_186 ( 100 ) ;
return 0 ;
}
static int F_190 ( struct V_1 * V_2 , int V_286 )
{
void T_4 * V_292 ;
unsigned long V_293 ;
T_1 V_62 ;
if ( V_286 )
return 0 ;
V_292 = F_178 ( V_2 , 0 , 0 ) ;
if ( ! V_292 )
return - V_294 ;
F_191 ( 0x00000002 , V_292 + V_295 ) ;
F_191 ( 0x00000005 , V_292 + V_296 ) ;
V_62 = F_192 ( V_292 + V_297 ) & 0xfffffffe ;
F_191 ( V_62 , V_292 + V_297 ) ;
V_293 = V_298 + F_193 ( V_299 ) ;
do {
V_62 = F_192 ( V_292 + V_300 ) ;
if ( ( V_62 & 0xb0000000 ) == 0 )
goto V_301;
F_186 ( 10 ) ;
} while ( F_194 ( V_298 , V_293 ) );
F_47 ( & V_2 -> V_2 , L_118 ) ;
V_301:
F_191 ( 0x00000002 , V_292 + V_302 ) ;
F_179 ( V_2 , V_292 ) ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 , int V_286 )
{
T_2 V_303 ;
T_2 V_304 ;
if ( ( V_2 -> V_78 & 0xf000 ) != 0x4000 )
return - V_289 ;
if ( V_286 )
return 0 ;
F_27 ( V_2 , V_65 , & V_303 ) ;
F_49 ( V_2 , V_65 ,
V_303 | V_305 ) ;
F_196 ( V_2 ) ;
F_27 ( V_2 , V_2 -> V_306 + V_307 , & V_304 ) ;
if ( ( V_304 & V_308 ) == 0 )
F_49 ( V_2 , V_2 -> V_306 + V_307 ,
V_304 |
V_308 |
V_309 ) ;
if ( ! F_188 ( V_2 ) )
F_163 ( & V_2 -> V_2 , L_117 ) ;
F_189 ( V_2 , V_290 , V_291 ) ;
F_186 ( 100 ) ;
F_197 ( V_2 ) ;
F_49 ( V_2 , V_65 , V_303 ) ;
return 0 ;
}
int F_198 ( struct V_1 * V_2 , int V_286 )
{
const struct V_310 * V_143 ;
for ( V_143 = V_310 ; V_143 -> V_311 ; V_143 ++ ) {
if ( ( V_143 -> V_152 == V_2 -> V_152 ||
V_143 -> V_152 == ( T_2 ) V_255 ) &&
( V_143 -> V_78 == V_2 -> V_78 ||
V_143 -> V_78 == ( T_2 ) V_255 ) )
return V_143 -> V_311 ( V_2 , V_286 ) ;
}
return - V_289 ;
}
static struct V_1 * F_199 ( struct V_1 * V_2 )
{
if ( ! F_91 ( V_2 -> V_70 ) )
return F_200 ( V_2 ) ;
return F_129 ( V_2 -> V_71 , F_130 ( F_58 ( V_2 -> V_70 ) , 0 ) ) ;
}
struct V_1 * F_201 ( struct V_1 * V_2 )
{
const struct V_312 * V_143 ;
for ( V_143 = V_312 ; V_143 -> V_313 ; V_143 ++ ) {
if ( ( V_143 -> V_152 == V_2 -> V_152 ||
V_143 -> V_152 == ( T_2 ) V_255 ) &&
( V_143 -> V_78 == V_2 -> V_78 ||
V_143 -> V_78 == ( T_2 ) V_255 ) )
return V_143 -> V_313 ( V_2 ) ;
}
return F_200 ( V_2 ) ;
}
static int F_202 ( struct V_1 * V_2 , T_2 V_314 )
{
#ifdef F_203
struct V_315 * V_316 = NULL ;
T_8 V_317 ;
if ( ! V_2 -> V_141 || ! F_204 ( V_2 -> V_71 ) )
return - V_318 ;
V_317 = F_205 ( L_119 , 0 , & V_316 ) ;
if ( F_206 ( V_317 ) )
return - V_318 ;
V_314 &= ( V_319 | V_320 | V_321 | V_322 ) ;
return V_314 & ~ ( V_319 | V_320 ) ? 0 : 1 ;
#else
return - V_318 ;
#endif
}
int F_207 ( struct V_1 * V_2 , T_2 V_314 )
{
const struct V_323 * V_143 ;
int V_324 ;
for ( V_143 = V_323 ; V_143 -> V_325 ; V_143 ++ ) {
if ( ( V_143 -> V_152 == V_2 -> V_152 ||
V_143 -> V_152 == ( T_2 ) V_255 ) &&
( V_143 -> V_78 == V_2 -> V_78 ||
V_143 -> V_78 == ( T_2 ) V_255 ) ) {
V_324 = V_143 -> V_325 ( V_2 , V_314 ) ;
if ( V_324 >= 0 )
return V_324 ;
}
}
return - V_289 ;
}
