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
F_2 ( L_3 , V_15 -> V_20 ) ;
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
F_2 ( L_4 , V_24 ) ;
return F_1 ( V_2 , 0xa4 , ~ V_24 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
char * V_25 ;
int V_6 ;
const unsigned V_26 = 8 ;
unsigned long V_27 ;
F_2 ( L_5 ) ;
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
F_2 ( L_6 ) ;
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
F_2 ( L_7 ) ;
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
F_2 ( L_8 , V_47 , V_43 -> V_48 ) ;
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
F_2 ( L_8 , V_47 , V_43 -> V_48 ) ;
F_25 ( V_43 ) ;
F_26 ( V_43 -> V_49 ) ;
}
static int F_27 ( struct V_50 * V_51 , struct V_44 * V_43 )
{
struct V_37 * V_38 = V_43 -> V_38 ;
struct V_14 * V_15 = F_21 ( V_38 -> V_43 [ 0 ] ) ;
int V_6 ;
F_2 ( L_9 ) ;
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
F_2 ( L_10 , V_47 ) ;
V_6 = F_28 ( V_43 -> V_49 , V_28 ) ;
if ( V_6 ) {
F_29 ( & V_43 -> V_2 , L_11
L_12 , V_47 , V_6 ) ;
F_24 ( V_43 ) ;
goto V_30;
}
V_6 = F_30 ( V_51 , V_43 ) ;
V_30: return V_6 ;
}
static void F_31 ( struct V_50 * V_51 ,
struct V_44 * V_43 , struct V_52 * V_53 )
{
struct V_14 * V_15 = F_21 ( V_43 ) ;
unsigned V_20 ;
unsigned long V_27 ;
F_2 ( L_13 ) ;
V_20 = F_32 ( V_51 ) ;
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
static void F_33 ( struct V_50 * V_51 , int V_54 )
{
const T_3 V_55 =
V_56 | ( ( T_3 ) V_57 << 8 ) ;
struct V_44 * V_43 = V_51 -> V_58 ;
int V_6 ;
T_3 V_59 ;
T_4 * V_60 ;
F_2 ( L_14 , V_47 ) ;
V_60 = F_10 ( 2 , V_28 ) ;
if ( ! V_60 ) {
F_29 ( & V_43 -> V_2 , L_15 , V_47 ) ;
return;
}
V_6 = F_5 ( V_43 -> V_38 -> V_2 , V_61 ,
V_55 , 0 , V_60 , 2 ) ;
if ( V_6 < 0 ) {
F_29 ( & V_43 -> V_2 , L_16 ,
V_47 , V_6 ) ;
goto V_30;
}
F_2 ( L_17 ,
V_47 , V_60 [ 0 ] , V_60 [ 1 ] ) ;
if ( V_54 != 0 ) {
F_2 ( L_18 , V_47 ) ;
V_60 [ 0 ] &= ~ V_62 ;
V_60 [ 1 ] &= ~ V_63 ;
} else {
F_2 ( L_19 , V_47 ) ;
V_60 [ 0 ] |= V_62 ;
V_60 [ 1 ] |= V_63 ;
}
F_2 ( L_20 ,
V_47 , V_60 [ 0 ] , V_60 [ 1 ] ) ;
V_59 = F_34 ( V_60 ) ;
V_6 = F_1 ( V_43 -> V_38 -> V_2 , V_64 ,
V_55 , V_59 ) ;
if ( V_6 < 0 )
F_29 ( & V_43 -> V_2 , L_21 ,
V_47 , V_6 ) ;
V_30:
F_13 ( V_60 ) ;
}
static int F_35 ( struct V_50 * V_51 ,
unsigned int V_65 , unsigned int V_66 )
{
struct V_44 * V_43 = V_51 -> V_58 ;
struct V_14 * V_15 = F_21 ( V_43 ) ;
unsigned long V_27 ;
T_1 V_24 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
if ( V_65 & V_67 )
V_15 -> V_36 |= V_41 ;
if ( V_65 & V_68 )
V_15 -> V_36 |= V_42 ;
if ( V_66 & V_67 )
V_15 -> V_36 &= ~ V_41 ;
if ( V_66 & V_68 )
V_15 -> V_36 &= ~ V_42 ;
V_24 = V_15 -> V_36 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
return F_8 ( V_43 -> V_38 -> V_2 , V_24 ) ;
}
static void F_36 ( struct V_69 * V_69 )
{
struct V_44 * V_43 = (struct V_44 * ) V_69 -> V_70 ;
unsigned char * V_71 = V_69 -> V_72 ;
unsigned int V_73 = V_69 -> V_73 ;
int V_74 ;
F_2 ( L_22 , V_47 , V_43 -> V_48 ) ;
switch ( V_69 -> V_74 ) {
case 0 :
break;
case - V_75 :
case - V_76 :
case - V_77 :
F_2 ( L_23 , V_47 ,
V_69 -> V_74 ) ;
return;
default:
F_2 ( L_24 , V_47 ,
V_69 -> V_74 ) ;
goto exit;
}
F_37 ( V_78 , & V_43 -> V_2 , V_47 ,
V_69 -> V_73 , V_69 -> V_72 ) ;
if ( V_73 >= 4 ) {
struct V_14 * V_15 = F_21 ( V_43 ) ;
unsigned long V_27 ;
T_1 V_79 = V_15 -> V_32 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_15 -> V_32 = ( ~ ( V_71 [ 2 ] ) ) & V_33 ;
if ( ( V_71 [ 1 ] & V_80 ) )
V_15 -> V_34 = 1 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
if ( ( V_15 -> V_32 ^ V_79 ) & V_45 ) {
struct V_50 * V_51 = F_38 ( & V_43 -> V_43 ) ;
if ( V_51 )
F_39 ( V_43 , V_51 ,
V_15 -> V_32 & V_45 ) ;
F_40 ( V_51 ) ;
}
F_23 ( & V_15 -> V_39 ) ;
}
exit:
V_74 = F_28 ( V_69 , V_81 ) ;
if ( V_74 )
F_29 ( & V_69 -> V_2 -> V_2 ,
L_25 ,
V_47 , V_74 ) ;
}
static int F_41 ( struct V_44 * V_43 , unsigned int V_82 )
{
struct V_14 * V_15 = F_21 ( V_43 ) ;
unsigned long V_27 ;
T_1 V_83 ;
T_1 V_74 ;
T_1 V_84 ;
T_1 V_85 = 0 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_83 = V_15 -> V_32 ;
V_15 -> V_34 = 0 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
while ( ! V_85 ) {
F_42 ( & V_15 -> V_39 ) ;
if ( F_43 ( V_86 ) )
return - V_87 ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_74 = V_15 -> V_32 ;
V_85 = V_15 -> V_34 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
V_84 = V_83 ^ V_74 ;
if ( ( ( V_82 & V_88 ) && ( V_84 & V_89 ) ) ||
( ( V_82 & V_90 ) && ( V_84 & V_91 ) ) ||
( ( V_82 & V_92 ) && ( V_84 & V_45 ) ) ||
( ( V_82 & V_93 ) && ( V_84 & V_94 ) ) ) {
return 0 ;
}
V_83 = V_74 ;
}
return 0 ;
}
static int F_44 ( struct V_50 * V_51 ,
unsigned int V_95 , unsigned long V_82 )
{
struct V_44 * V_43 = V_51 -> V_58 ;
F_2 ( L_26 , V_47 , V_43 -> V_48 , V_95 ) ;
switch ( V_95 ) {
case V_96 :
F_2 ( L_27 , V_47 , V_43 -> V_48 ) ;
return F_41 ( V_43 , V_82 ) ;
default:
F_2 ( L_28 , V_47 , V_95 ) ;
break;
}
return - V_97 ;
}
static int F_45 ( struct V_50 * V_51 )
{
struct V_44 * V_43 = V_51 -> V_58 ;
struct V_14 * V_15 = F_21 ( V_43 ) ;
unsigned long V_27 ;
T_1 V_98 ;
T_1 V_74 ;
unsigned int V_99 ;
F_2 ( L_22 , V_47 , V_43 -> V_48 ) ;
F_11 ( & V_15 -> V_31 , V_27 ) ;
V_98 = V_15 -> V_36 ;
V_74 = V_15 -> V_32 ;
F_12 ( & V_15 -> V_31 , V_27 ) ;
V_99 = ( ( V_98 & V_42 ) ? V_68 : 0 )
| ( ( V_98 & V_41 ) ? V_67 : 0 )
| ( ( V_74 & V_94 ) ? V_93 : 0 )
| ( ( V_74 & V_91 ) ? V_90 : 0 )
| ( ( V_74 & V_89 ) ? V_100 : 0 )
| ( ( V_74 & V_45 ) ? V_92 : 0 ) ;
F_2 ( L_29 , V_47 , V_99 ) ;
return V_99 ;
}
static int F_46 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_47 ( V_102 ) ;
struct V_37 * V_38 = NULL ;
struct V_14 * V_15 ;
V_38 = F_48 ( V_102 ) ;
V_15 = F_21 ( V_38 -> V_43 [ 0 ] ) ;
F_14 ( V_2 , V_15 ) ;
F_49 ( V_102 ) ;
return 0 ;
}
static int T_5 F_50 ( void )
{
int V_103 ;
V_103 = F_51 ( & V_104 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_52 ( & V_105 ) ;
if ( V_103 )
F_53 ( & V_104 ) ;
return V_103 ;
}
static void T_6 F_54 ( void )
{
F_55 ( & V_105 ) ;
F_53 ( & V_104 ) ;
}
