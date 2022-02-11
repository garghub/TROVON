static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
int V_6 ;
F_2 ( L_1 , V_7 | 0x40 ,
( int ) V_3 , ( int ) V_4 , ( int ) V_5 ) ;
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
F_2 ( L_2 , V_13 | 0x40 ,
( int ) V_3 , ( int ) V_4 , ( int ) V_5 , V_11 , ( int ) V_12 ) ;
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
V_15 -> V_34 = 0 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
} else
V_6 = - V_35 ;
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
V_6 = F_8 ( V_2 , V_15 -> V_36 ) ;
if ( V_6 < 0 )
goto V_30;
V_6 = F_9 ( V_2 , V_15 ) ;
V_30: F_13 ( V_25 ) ;
return V_6 ;
}
static int F_15 ( struct V_37 * V_38 )
{
struct V_14 * V_15 ;
int V_6 ;
V_15 = F_16 ( sizeof( struct V_14 ) , V_28 ) ;
if ( ! V_15 )
return - V_29 ;
F_17 ( & V_15 -> V_31 ) ;
F_18 ( & V_15 -> V_39 ) ;
V_15 -> V_20 = V_40 ;
V_15 -> V_36 = V_41 | V_42 ;
V_6 = F_14 ( V_38 -> V_2 , V_15 ) ;
if ( V_6 < 0 )
goto error;
F_19 ( V_38 -> V_43 [ 0 ] , V_15 ) ;
return 0 ;
error: F_13 ( V_15 ) ;
return V_6 ;
}
static int F_20 ( struct V_44 * V_43 )
{
struct V_14 * V_15 = F_21 ( V_43 ) ;
if ( V_15 -> V_32 & V_45 )
return 1 ;
return 0 ;
}
static void F_22 ( struct V_44 * V_43 , int V_46 )
{
struct V_14 * V_15 = F_21 ( V_43 ) ;
unsigned long V_27 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
if ( V_46 )
V_15 -> V_36 |= V_41 | V_42 ;
else
V_15 -> V_36 &= ~ ( V_41 | V_42 ) ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
F_8 ( V_43 -> V_38 -> V_2 , V_15 -> V_36 ) ;
F_23 ( & V_15 -> V_39 ) ;
}
static void F_24 ( struct V_44 * V_43 )
{
F_25 ( V_43 ) ;
F_26 ( V_43 -> V_47 ) ;
}
static int F_27 ( struct V_48 * V_49 , struct V_44 * V_43 )
{
struct V_37 * V_38 = V_43 -> V_38 ;
struct V_14 * V_15 = F_21 ( V_38 -> V_43 [ 0 ] ) ;
int V_6 ;
V_15 -> V_20 = V_40 ;
V_6 = F_14 ( V_38 -> V_2 , V_15 ) ;
if ( V_6 )
goto V_30;
V_6 = F_8 ( V_38 -> V_2 , V_15 -> V_36 ) ;
if ( V_6 )
goto V_30;
V_6 = F_7 ( V_38 -> V_2 , V_15 ) ;
if ( V_6 )
goto V_30;
F_2 ( L_3 , V_50 ) ;
V_6 = F_28 ( V_43 -> V_47 , V_28 ) ;
if ( V_6 ) {
F_29 ( & V_43 -> V_2 , L_4
L_5 , V_50 , V_6 ) ;
F_24 ( V_43 ) ;
goto V_30;
}
V_6 = F_30 ( V_49 , V_43 ) ;
V_30: return V_6 ;
}
static void F_31 ( struct V_48 * V_49 ,
struct V_44 * V_43 , struct V_51 * V_52 )
{
struct V_14 * V_15 = F_21 ( V_43 ) ;
unsigned V_20 ;
unsigned long V_27 ;
V_20 = F_32 ( V_49 ) ;
V_15 -> V_20 = V_20 ;
if ( V_20 ) {
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_15 -> V_36 |= ( V_42 | V_41 ) ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
F_7 ( V_43 -> V_38 -> V_2 , V_15 ) ;
} else {
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_15 -> V_36 &= ~ ( V_42 | V_41 ) ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
}
F_8 ( V_43 -> V_38 -> V_2 , V_15 -> V_36 ) ;
}
static void F_33 ( struct V_48 * V_49 , int V_53 )
{
const T_3 V_54 =
V_55 | ( ( T_3 ) V_56 << 8 ) ;
struct V_44 * V_43 = V_49 -> V_57 ;
int V_6 ;
T_3 V_58 ;
T_4 * V_59 ;
V_59 = F_10 ( 2 , V_28 ) ;
if ( ! V_59 ) {
F_29 ( & V_43 -> V_2 , L_6 , V_50 ) ;
return;
}
V_6 = F_5 ( V_43 -> V_38 -> V_2 , V_60 ,
V_54 , 0 , V_59 , 2 ) ;
if ( V_6 < 0 ) {
F_29 ( & V_43 -> V_2 , L_7 ,
V_50 , V_6 ) ;
goto V_30;
}
F_2 ( L_8 ,
V_50 , V_59 [ 0 ] , V_59 [ 1 ] ) ;
if ( V_53 != 0 ) {
F_2 ( L_9 , V_50 ) ;
V_59 [ 0 ] &= ~ V_61 ;
V_59 [ 1 ] &= ~ V_62 ;
} else {
F_2 ( L_10 , V_50 ) ;
V_59 [ 0 ] |= V_61 ;
V_59 [ 1 ] |= V_62 ;
}
F_2 ( L_11 ,
V_50 , V_59 [ 0 ] , V_59 [ 1 ] ) ;
V_58 = F_34 ( V_59 ) ;
V_6 = F_1 ( V_43 -> V_38 -> V_2 , V_63 ,
V_54 , V_58 ) ;
if ( V_6 < 0 )
F_29 ( & V_43 -> V_2 , L_12 ,
V_50 , V_6 ) ;
V_30:
F_13 ( V_59 ) ;
}
static int F_35 ( struct V_48 * V_49 ,
unsigned int V_64 , unsigned int V_65 )
{
struct V_44 * V_43 = V_49 -> V_57 ;
struct V_14 * V_15 = F_21 ( V_43 ) ;
unsigned long V_27 ;
T_1 V_24 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
if ( V_64 & V_66 )
V_15 -> V_36 |= V_41 ;
if ( V_64 & V_67 )
V_15 -> V_36 |= V_42 ;
if ( V_65 & V_66 )
V_15 -> V_36 &= ~ V_41 ;
if ( V_65 & V_67 )
V_15 -> V_36 &= ~ V_42 ;
V_24 = V_15 -> V_36 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
return F_8 ( V_43 -> V_38 -> V_2 , V_24 ) ;
}
static void F_36 ( struct V_68 * V_68 )
{
struct V_44 * V_43 = (struct V_44 * ) V_68 -> V_69 ;
unsigned char * V_70 = V_68 -> V_71 ;
unsigned int V_72 = V_68 -> V_72 ;
int V_73 ;
switch ( V_68 -> V_73 ) {
case 0 :
break;
case - V_74 :
case - V_75 :
case - V_76 :
F_2 ( L_13 , V_50 ,
V_68 -> V_73 ) ;
return;
default:
F_2 ( L_14 , V_50 ,
V_68 -> V_73 ) ;
goto exit;
}
F_37 ( V_77 , & V_43 -> V_2 , V_50 ,
V_68 -> V_72 , V_68 -> V_71 ) ;
if ( V_72 >= 4 ) {
struct V_14 * V_15 = F_21 ( V_43 ) ;
unsigned long V_27 ;
T_1 V_78 = V_15 -> V_32 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_15 -> V_32 = ( ~ ( V_70 [ 2 ] ) ) & V_33 ;
if ( ( V_70 [ 1 ] & V_79 ) )
V_15 -> V_34 = 1 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
if ( ( V_15 -> V_32 ^ V_78 ) & V_45 ) {
struct V_48 * V_49 = F_38 ( & V_43 -> V_43 ) ;
if ( V_49 )
F_39 ( V_43 , V_49 ,
V_15 -> V_32 & V_45 ) ;
F_40 ( V_49 ) ;
}
F_23 ( & V_15 -> V_39 ) ;
}
exit:
V_73 = F_28 ( V_68 , V_80 ) ;
if ( V_73 )
F_29 ( & V_68 -> V_2 -> V_2 ,
L_15 ,
V_50 , V_73 ) ;
}
static int F_41 ( struct V_44 * V_43 , unsigned int V_81 )
{
struct V_14 * V_15 = F_21 ( V_43 ) ;
unsigned long V_27 ;
T_1 V_82 ;
T_1 V_73 ;
T_1 V_83 ;
T_1 V_84 = 0 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_82 = V_15 -> V_32 ;
V_15 -> V_34 = 0 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
while ( ! V_84 ) {
F_42 ( & V_15 -> V_39 ) ;
if ( F_43 ( V_85 ) )
return - V_86 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_73 = V_15 -> V_32 ;
V_84 = V_15 -> V_34 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
V_83 = V_82 ^ V_73 ;
if ( ( ( V_81 & V_87 ) && ( V_83 & V_88 ) ) ||
( ( V_81 & V_89 ) && ( V_83 & V_90 ) ) ||
( ( V_81 & V_91 ) && ( V_83 & V_45 ) ) ||
( ( V_81 & V_92 ) && ( V_83 & V_93 ) ) ) {
return 0 ;
}
V_82 = V_73 ;
}
return 0 ;
}
static int F_44 ( struct V_48 * V_49 ,
unsigned int V_94 , unsigned long V_81 )
{
struct V_44 * V_43 = V_49 -> V_57 ;
F_2 ( L_16 , V_50 , V_43 -> V_95 , V_94 ) ;
switch ( V_94 ) {
case V_96 :
F_2 ( L_17 , V_50 , V_43 -> V_95 ) ;
return F_41 ( V_43 , V_81 ) ;
default:
F_2 ( L_18 , V_50 , V_94 ) ;
break;
}
return - V_97 ;
}
static int F_45 ( struct V_48 * V_49 )
{
struct V_44 * V_43 = V_49 -> V_57 ;
struct V_14 * V_15 = F_21 ( V_43 ) ;
unsigned long V_27 ;
T_1 V_98 ;
T_1 V_73 ;
unsigned int V_99 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_98 = V_15 -> V_36 ;
V_73 = V_15 -> V_32 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
V_99 = ( ( V_98 & V_42 ) ? V_67 : 0 )
| ( ( V_98 & V_41 ) ? V_66 : 0 )
| ( ( V_73 & V_93 ) ? V_92 : 0 )
| ( ( V_73 & V_90 ) ? V_89 : 0 )
| ( ( V_73 & V_88 ) ? V_100 : 0 )
| ( ( V_73 & V_45 ) ? V_91 : 0 ) ;
F_2 ( L_19 , V_50 , V_99 ) ;
return V_99 ;
}
static int F_46 ( struct V_37 * V_38 )
{
struct V_14 * V_15 ;
V_15 = F_21 ( V_38 -> V_43 [ 0 ] ) ;
F_14 ( V_38 -> V_2 , V_15 ) ;
return 0 ;
}
