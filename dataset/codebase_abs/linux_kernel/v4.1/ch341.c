static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
int V_6 ;
F_2 ( & V_2 -> V_2 , L_1 ,
V_7 | 0x40 , ( int ) V_3 , ( int ) V_4 , ( int ) V_5 ) ;
V_6 = F_3 ( V_2 , F_4 ( V_2 , 0 ) , V_3 ,
V_8 | V_9 | V_7 ,
V_4 , V_5 , NULL , 0 , V_10 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_2 V_5 ,
char * V_11 , unsigned V_12 )
{
int V_6 ;
F_2 ( & V_2 -> V_2 , L_2 ,
V_13 | 0x40 , ( int ) V_3 , ( int ) V_4 , ( int ) V_5 , V_11 ,
( int ) V_12 ) ;
V_6 = F_3 ( V_2 , F_6 ( V_2 , 0 ) , V_3 ,
V_8 | V_9 | V_13 ,
V_4 , V_5 , V_11 , V_12 , V_10 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
short V_16 , V_17 ;
int V_6 ;
unsigned long V_18 ;
short V_19 ;
if ( ! V_15 -> V_20 )
return - V_21 ;
V_18 = ( V_22 / V_15 -> V_20 ) ;
V_19 = V_23 ;
while ( ( V_18 > 0xfff0 ) && V_19 ) {
V_18 >>= 3 ;
V_19 -- ;
}
if ( V_18 > 0xfff0 )
return - V_21 ;
V_18 = 0x10000 - V_18 ;
V_16 = ( V_18 & 0xff00 ) | V_19 ;
V_17 = V_18 & 0xff ;
V_6 = F_1 ( V_2 , 0x9a , 0x1312 , V_16 ) ;
if ( ! V_6 )
V_6 = F_1 ( V_2 , 0x9a , 0x0f2c , V_17 ) ;
return V_6 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_24 )
{
return F_1 ( V_2 , 0xa4 , ~ V_24 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
char * V_25 ;
int V_6 ;
const unsigned V_26 = 8 ;
unsigned long V_27 ;
V_25 = F_10 ( V_26 , V_28 ) ;
if ( ! V_25 )
return - V_29 ;
V_6 = F_5 ( V_2 , 0x95 , 0x0706 , 0 , V_25 , V_26 ) ;
if ( V_6 < 0 )
goto V_30;
if ( V_6 == 2 ) {
V_6 = 0 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_15 -> V_32 = ( ~ ( * V_25 ) ) & V_33 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
} else
V_6 = - V_34 ;
V_30: F_13 ( V_25 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
char * V_25 ;
int V_6 ;
const unsigned V_26 = 8 ;
V_25 = F_10 ( V_26 , V_28 ) ;
if ( ! V_25 )
return - V_29 ;
V_6 = F_5 ( V_2 , 0x5f , 0 , 0 , V_25 , V_26 ) ;
if ( V_6 < 0 )
goto V_30;
V_6 = F_1 ( V_2 , 0xa1 , 0 , 0 ) ;
if ( V_6 < 0 )
goto V_30;
V_6 = F_7 ( V_2 , V_15 ) ;
if ( V_6 < 0 )
goto V_30;
V_6 = F_5 ( V_2 , 0x95 , 0x2518 , 0 , V_25 , V_26 ) ;
if ( V_6 < 0 )
goto V_30;
V_6 = F_1 ( V_2 , 0x9a , 0x2518 , 0x0050 ) ;
if ( V_6 < 0 )
goto V_30;
V_6 = F_9 ( V_2 , V_15 ) ;
if ( V_6 < 0 )
goto V_30;
V_6 = F_1 ( V_2 , 0xa1 , 0x501f , 0xd90a ) ;
if ( V_6 < 0 )
goto V_30;
V_6 = F_7 ( V_2 , V_15 ) ;
if ( V_6 < 0 )
goto V_30;
V_6 = F_8 ( V_2 , V_15 -> V_35 ) ;
if ( V_6 < 0 )
goto V_30;
V_6 = F_9 ( V_2 , V_15 ) ;
V_30: F_13 ( V_25 ) ;
return V_6 ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_14 * V_15 ;
int V_6 ;
V_15 = F_16 ( sizeof( struct V_14 ) , V_28 ) ;
if ( ! V_15 )
return - V_29 ;
F_17 ( & V_15 -> V_31 ) ;
V_15 -> V_20 = V_38 ;
V_15 -> V_35 = V_39 | V_40 ;
V_6 = F_14 ( V_37 -> V_41 -> V_2 , V_15 ) ;
if ( V_6 < 0 )
goto error;
F_18 ( V_37 , V_15 ) ;
return 0 ;
error: F_13 ( V_15 ) ;
return V_6 ;
}
static int F_19 ( struct V_36 * V_37 )
{
struct V_14 * V_15 ;
V_15 = F_20 ( V_37 ) ;
F_13 ( V_15 ) ;
return 0 ;
}
static int F_21 ( struct V_36 * V_37 )
{
struct V_14 * V_15 = F_20 ( V_37 ) ;
if ( V_15 -> V_32 & V_42 )
return 1 ;
return 0 ;
}
static void F_22 ( struct V_36 * V_37 , int V_43 )
{
struct V_14 * V_15 = F_20 ( V_37 ) ;
unsigned long V_27 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
if ( V_43 )
V_15 -> V_35 |= V_39 | V_40 ;
else
V_15 -> V_35 &= ~ ( V_39 | V_40 ) ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
F_8 ( V_37 -> V_41 -> V_2 , V_15 -> V_35 ) ;
}
static void F_23 ( struct V_36 * V_37 )
{
F_24 ( V_37 ) ;
F_25 ( V_37 -> V_44 ) ;
}
static int F_26 ( struct V_45 * V_46 , struct V_36 * V_37 )
{
struct V_47 * V_41 = V_37 -> V_41 ;
struct V_14 * V_15 = F_20 ( V_37 ) ;
int V_6 ;
V_6 = F_14 ( V_41 -> V_2 , V_15 ) ;
if ( V_6 )
goto V_30;
if ( V_46 )
F_27 ( V_46 , V_37 , NULL ) ;
F_2 ( & V_37 -> V_2 , L_3 , V_48 ) ;
V_6 = F_28 ( V_37 -> V_44 , V_28 ) ;
if ( V_6 ) {
F_29 ( & V_37 -> V_2 , L_4 ,
V_48 , V_6 ) ;
goto V_30;
}
V_6 = F_30 ( V_46 , V_37 ) ;
V_30: return V_6 ;
}
static void F_27 ( struct V_45 * V_46 ,
struct V_36 * V_37 , struct V_49 * V_50 )
{
struct V_14 * V_15 = F_20 ( V_37 ) ;
unsigned V_20 ;
unsigned long V_27 ;
V_20 = F_31 ( V_46 ) ;
V_15 -> V_20 = V_20 ;
if ( V_20 ) {
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_15 -> V_35 |= ( V_40 | V_39 ) ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
F_7 ( V_37 -> V_41 -> V_2 , V_15 ) ;
} else {
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_15 -> V_35 &= ~ ( V_40 | V_39 ) ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
}
F_8 ( V_37 -> V_41 -> V_2 , V_15 -> V_35 ) ;
}
static void F_32 ( struct V_45 * V_46 , int V_51 )
{
const T_3 V_52 =
V_53 | ( ( T_3 ) V_54 << 8 ) ;
struct V_36 * V_37 = V_46 -> V_55 ;
int V_6 ;
T_3 V_56 ;
T_4 * V_57 ;
V_57 = F_10 ( 2 , V_28 ) ;
if ( ! V_57 )
return;
V_6 = F_5 ( V_37 -> V_41 -> V_2 , V_58 ,
V_52 , 0 , V_57 , 2 ) ;
if ( V_6 < 0 ) {
F_29 ( & V_37 -> V_2 , L_5 ,
V_48 , V_6 ) ;
goto V_30;
}
F_2 ( & V_37 -> V_2 , L_6 ,
V_48 , V_57 [ 0 ] , V_57 [ 1 ] ) ;
if ( V_51 != 0 ) {
F_2 ( & V_37 -> V_2 , L_7 , V_48 ) ;
V_57 [ 0 ] &= ~ V_59 ;
V_57 [ 1 ] &= ~ V_60 ;
} else {
F_2 ( & V_37 -> V_2 , L_8 , V_48 ) ;
V_57 [ 0 ] |= V_59 ;
V_57 [ 1 ] |= V_60 ;
}
F_2 ( & V_37 -> V_2 , L_9 ,
V_48 , V_57 [ 0 ] , V_57 [ 1 ] ) ;
V_56 = F_33 ( V_57 ) ;
V_6 = F_1 ( V_37 -> V_41 -> V_2 , V_61 ,
V_52 , V_56 ) ;
if ( V_6 < 0 )
F_29 ( & V_37 -> V_2 , L_10 ,
V_48 , V_6 ) ;
V_30:
F_13 ( V_57 ) ;
}
static int F_34 ( struct V_45 * V_46 ,
unsigned int V_62 , unsigned int V_63 )
{
struct V_36 * V_37 = V_46 -> V_55 ;
struct V_14 * V_15 = F_20 ( V_37 ) ;
unsigned long V_27 ;
T_1 V_24 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
if ( V_62 & V_64 )
V_15 -> V_35 |= V_39 ;
if ( V_62 & V_65 )
V_15 -> V_35 |= V_40 ;
if ( V_63 & V_64 )
V_15 -> V_35 &= ~ V_39 ;
if ( V_63 & V_65 )
V_15 -> V_35 &= ~ V_40 ;
V_24 = V_15 -> V_35 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
return F_8 ( V_37 -> V_41 -> V_2 , V_24 ) ;
}
static void F_35 ( struct V_36 * V_37 ,
unsigned char * V_66 , T_5 V_67 )
{
struct V_14 * V_15 = F_20 ( V_37 ) ;
struct V_45 * V_46 ;
unsigned long V_27 ;
T_1 V_68 ;
T_1 V_69 ;
if ( V_67 < 4 )
return;
V_68 = ~ V_66 [ 2 ] & V_33 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_69 = V_68 ^ V_15 -> V_32 ;
V_15 -> V_32 = V_68 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
if ( V_66 [ 1 ] & V_70 )
F_2 ( & V_37 -> V_2 , L_11 , V_48 ) ;
if ( ! V_69 )
return;
if ( V_69 & V_71 )
V_37 -> V_72 . V_73 ++ ;
if ( V_69 & V_74 )
V_37 -> V_72 . V_75 ++ ;
if ( V_69 & V_76 )
V_37 -> V_72 . V_77 ++ ;
if ( V_69 & V_42 ) {
V_37 -> V_72 . V_78 ++ ;
V_46 = F_36 ( & V_37 -> V_37 ) ;
if ( V_46 ) {
F_37 ( V_37 , V_46 ,
V_68 & V_42 ) ;
F_38 ( V_46 ) ;
}
}
F_39 ( & V_37 -> V_37 . V_79 ) ;
}
static void F_40 ( struct V_80 * V_80 )
{
struct V_36 * V_37 = V_80 -> V_81 ;
unsigned char * V_66 = V_80 -> V_82 ;
unsigned int V_67 = V_80 -> V_83 ;
int V_68 ;
switch ( V_80 -> V_68 ) {
case 0 :
break;
case - V_84 :
case - V_85 :
case - V_86 :
F_2 ( & V_80 -> V_2 -> V_2 , L_12 ,
V_48 , V_80 -> V_68 ) ;
return;
default:
F_2 ( & V_80 -> V_2 -> V_2 , L_13 ,
V_48 , V_80 -> V_68 ) ;
goto exit;
}
F_41 ( & V_37 -> V_2 , V_48 , V_67 , V_66 ) ;
F_35 ( V_37 , V_66 , V_67 ) ;
exit:
V_68 = F_28 ( V_80 , V_87 ) ;
if ( V_68 ) {
F_29 ( & V_80 -> V_2 -> V_2 , L_14 ,
V_48 , V_68 ) ;
}
}
static int F_42 ( struct V_45 * V_46 )
{
struct V_36 * V_37 = V_46 -> V_55 ;
struct V_14 * V_15 = F_20 ( V_37 ) ;
unsigned long V_27 ;
T_1 V_88 ;
T_1 V_68 ;
unsigned int V_89 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_88 = V_15 -> V_35 ;
V_68 = V_15 -> V_32 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
V_89 = ( ( V_88 & V_40 ) ? V_65 : 0 )
| ( ( V_88 & V_39 ) ? V_64 : 0 )
| ( ( V_68 & V_71 ) ? V_90 : 0 )
| ( ( V_68 & V_74 ) ? V_91 : 0 )
| ( ( V_68 & V_76 ) ? V_92 : 0 )
| ( ( V_68 & V_42 ) ? V_93 : 0 ) ;
F_2 ( & V_37 -> V_2 , L_15 , V_48 , V_89 ) ;
return V_89 ;
}
static int F_43 ( struct V_47 * V_41 )
{
struct V_14 * V_15 ;
V_15 = F_20 ( V_41 -> V_37 [ 0 ] ) ;
F_14 ( V_41 -> V_2 , V_15 ) ;
return 0 ;
}
