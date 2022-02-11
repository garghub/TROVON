static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
int V_6 ;
F_2 ( & V_2 -> V_2 , L_1 ,
V_7 | 0x40 , ( int ) V_3 , ( int ) V_4 , ( int ) V_5 ) ;
V_6 = F_3 ( V_2 , F_4 ( V_2 , 0 ) , V_3 ,
V_8 | V_9 | V_7 ,
V_4 , V_5 , NULL , 0 , V_10 ) ;
if ( V_6 < 0 )
F_5 ( & V_2 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_2 V_5 ,
char * V_11 , unsigned V_12 )
{
int V_6 ;
F_2 ( & V_2 -> V_2 , L_3 ,
V_13 | 0x40 , ( int ) V_3 , ( int ) V_4 , ( int ) V_5 , V_11 ,
( int ) V_12 ) ;
V_6 = F_3 ( V_2 , F_7 ( V_2 , 0 ) , V_3 ,
V_8 | V_9 | V_13 ,
V_4 , V_5 , V_11 , V_12 , V_10 ) ;
if ( V_6 < V_12 ) {
if ( V_6 >= 0 ) {
F_5 ( & V_2 -> V_2 ,
L_4 ,
V_6 , V_12 ) ;
V_6 = - V_14 ;
}
F_5 ( & V_2 -> V_2 , L_5 ,
V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_1 V_17 )
{
short V_18 ;
int V_6 ;
unsigned long V_19 ;
short V_20 ;
if ( ! V_16 -> V_21 )
return - V_22 ;
V_19 = ( V_23 / V_16 -> V_21 ) ;
V_20 = V_24 ;
while ( ( V_19 > 0xfff0 ) && V_20 ) {
V_19 >>= 3 ;
V_20 -- ;
}
if ( V_19 > 0xfff0 )
return - V_22 ;
V_19 = 0x10000 - V_19 ;
V_18 = ( V_19 & 0xff00 ) | V_20 ;
V_18 |= F_9 ( 7 ) ;
V_6 = F_1 ( V_2 , V_25 , 0x1312 , V_18 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , V_25 , 0x2518 , V_17 ) ;
if ( V_6 )
return V_6 ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_26 )
{
return F_1 ( V_2 , V_27 , ~ V_26 , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
const unsigned int V_28 = 2 ;
char * V_29 ;
int V_6 ;
unsigned long V_30 ;
V_29 = F_12 ( V_28 , V_31 ) ;
if ( ! V_29 )
return - V_32 ;
V_6 = F_6 ( V_2 , V_33 , 0x0706 , 0 , V_29 , V_28 ) ;
if ( V_6 < 0 )
goto V_34;
F_13 ( & V_16 -> V_35 , V_30 ) ;
V_16 -> V_36 = ( ~ ( * V_29 ) ) & V_37 ;
F_14 ( & V_16 -> V_35 , V_30 ) ;
V_34: F_15 ( V_29 ) ;
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
const unsigned int V_28 = 2 ;
char * V_29 ;
int V_6 ;
V_29 = F_12 ( V_28 , V_31 ) ;
if ( ! V_29 )
return - V_32 ;
V_6 = F_6 ( V_2 , V_38 , 0 , 0 , V_29 , V_28 ) ;
if ( V_6 < 0 )
goto V_34;
F_2 ( & V_2 -> V_2 , L_6 , V_29 [ 0 ] ) ;
V_6 = F_1 ( V_2 , V_39 , 0 , 0 ) ;
if ( V_6 < 0 )
goto V_34;
V_6 = F_6 ( V_2 , V_33 , 0x2518 , 0 , V_29 , V_28 ) ;
if ( V_6 < 0 )
goto V_34;
V_6 = F_1 ( V_2 , V_25 , 0x2518 , 0x0050 ) ;
if ( V_6 < 0 )
goto V_34;
V_6 = F_11 ( V_2 , V_16 ) ;
if ( V_6 < 0 )
goto V_34;
V_6 = F_8 ( V_2 , V_16 , V_16 -> V_17 ) ;
if ( V_6 < 0 )
goto V_34;
V_6 = F_10 ( V_2 , V_16 -> V_40 ) ;
if ( V_6 < 0 )
goto V_34;
V_6 = F_11 ( V_2 , V_16 ) ;
V_34: F_15 ( V_29 ) ;
return V_6 ;
}
static int F_17 ( struct V_41 * V_42 )
{
struct V_15 * V_16 ;
int V_6 ;
V_16 = F_18 ( sizeof( struct V_15 ) , V_31 ) ;
if ( ! V_16 )
return - V_32 ;
F_19 ( & V_16 -> V_35 ) ;
V_16 -> V_21 = V_43 ;
V_6 = F_16 ( V_42 -> V_44 -> V_2 , V_16 ) ;
if ( V_6 < 0 )
goto error;
F_20 ( V_42 , V_16 ) ;
return 0 ;
error: F_15 ( V_16 ) ;
return V_6 ;
}
static int F_21 ( struct V_41 * V_42 )
{
struct V_15 * V_16 ;
V_16 = F_22 ( V_42 ) ;
F_15 ( V_16 ) ;
return 0 ;
}
static int F_23 ( struct V_41 * V_42 )
{
struct V_15 * V_16 = F_22 ( V_42 ) ;
if ( V_16 -> V_36 & V_45 )
return 1 ;
return 0 ;
}
static void F_24 ( struct V_41 * V_42 , int V_46 )
{
struct V_15 * V_16 = F_22 ( V_42 ) ;
unsigned long V_30 ;
F_13 ( & V_16 -> V_35 , V_30 ) ;
if ( V_46 )
V_16 -> V_40 |= V_47 | V_48 ;
else
V_16 -> V_40 &= ~ ( V_47 | V_48 ) ;
F_14 ( & V_16 -> V_35 , V_30 ) ;
F_10 ( V_42 -> V_44 -> V_2 , V_16 -> V_40 ) ;
}
static void F_25 ( struct V_41 * V_42 )
{
F_26 ( V_42 ) ;
F_27 ( V_42 -> V_49 ) ;
}
static int F_28 ( struct V_50 * V_51 , struct V_41 * V_42 )
{
struct V_52 * V_44 = V_42 -> V_44 ;
struct V_15 * V_16 = F_22 ( V_42 ) ;
int V_6 ;
V_6 = F_16 ( V_44 -> V_2 , V_16 ) ;
if ( V_6 )
return V_6 ;
if ( V_51 )
F_29 ( V_51 , V_42 , NULL ) ;
F_2 ( & V_42 -> V_2 , L_7 , V_53 ) ;
V_6 = F_30 ( V_42 -> V_49 , V_31 ) ;
if ( V_6 ) {
F_5 ( & V_42 -> V_2 , L_8 ,
V_53 , V_6 ) ;
return V_6 ;
}
V_6 = F_31 ( V_51 , V_42 ) ;
if ( V_6 )
goto V_54;
return 0 ;
V_54:
F_27 ( V_42 -> V_49 ) ;
return V_6 ;
}
static void F_29 ( struct V_50 * V_51 ,
struct V_41 * V_42 , struct V_55 * V_56 )
{
struct V_15 * V_16 = F_22 ( V_42 ) ;
unsigned V_21 ;
unsigned long V_30 ;
unsigned char V_57 ;
int V_6 ;
if ( V_56 && ! F_32 ( & V_51 -> V_58 , V_56 ) )
return;
V_21 = F_33 ( V_51 ) ;
V_57 = V_59 | V_60 ;
switch ( F_34 ( V_51 ) ) {
case V_61 :
V_57 |= V_62 ;
break;
case V_63 :
V_57 |= V_64 ;
break;
case V_65 :
V_57 |= V_66 ;
break;
case V_67 :
V_57 |= V_68 ;
break;
}
if ( F_35 ( V_51 ) ) {
V_57 |= V_69 ;
if ( F_36 ( V_51 ) == 0 )
V_57 |= V_70 ;
if ( F_37 ( V_51 ) )
V_57 |= V_71 ;
}
if ( F_38 ( V_51 ) )
V_57 |= V_72 ;
if ( V_21 ) {
V_16 -> V_21 = V_21 ;
V_6 = F_8 ( V_42 -> V_44 -> V_2 , V_16 , V_57 ) ;
if ( V_6 < 0 && V_56 ) {
V_16 -> V_21 = F_39 ( V_56 ) ;
F_40 ( & V_51 -> V_58 , V_56 ) ;
} else if ( V_6 == 0 ) {
V_16 -> V_17 = V_57 ;
}
}
F_13 ( & V_16 -> V_35 , V_30 ) ;
if ( F_41 ( V_51 ) == V_73 )
V_16 -> V_40 &= ~ ( V_48 | V_47 ) ;
else if ( V_56 && ( V_56 -> V_74 & V_75 ) == V_73 )
V_16 -> V_40 |= ( V_48 | V_47 ) ;
F_14 ( & V_16 -> V_35 , V_30 ) ;
F_10 ( V_42 -> V_44 -> V_2 , V_16 -> V_40 ) ;
}
static void F_42 ( struct V_50 * V_51 , int V_76 )
{
const T_3 V_77 =
( ( T_3 ) V_78 << 8 ) | V_79 ;
struct V_41 * V_42 = V_51 -> V_80 ;
int V_6 ;
T_3 V_81 ;
T_4 * V_82 ;
V_82 = F_12 ( 2 , V_31 ) ;
if ( ! V_82 )
return;
V_6 = F_6 ( V_42 -> V_44 -> V_2 , V_33 ,
V_77 , 0 , V_82 , 2 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_42 -> V_2 , L_9 ,
V_53 , V_6 ) ;
goto V_34;
}
F_2 ( & V_42 -> V_2 , L_10 ,
V_53 , V_82 [ 0 ] , V_82 [ 1 ] ) ;
if ( V_76 != 0 ) {
F_2 ( & V_42 -> V_2 , L_11 , V_53 ) ;
V_82 [ 0 ] &= ~ V_83 ;
V_82 [ 1 ] &= ~ V_60 ;
} else {
F_2 ( & V_42 -> V_2 , L_12 , V_53 ) ;
V_82 [ 0 ] |= V_83 ;
V_82 [ 1 ] |= V_60 ;
}
F_2 ( & V_42 -> V_2 , L_13 ,
V_53 , V_82 [ 0 ] , V_82 [ 1 ] ) ;
V_81 = F_43 ( V_82 ) ;
V_6 = F_1 ( V_42 -> V_44 -> V_2 , V_25 ,
V_77 , V_81 ) ;
if ( V_6 < 0 )
F_5 ( & V_42 -> V_2 , L_14 ,
V_53 , V_6 ) ;
V_34:
F_15 ( V_82 ) ;
}
static int F_44 ( struct V_50 * V_51 ,
unsigned int V_84 , unsigned int V_85 )
{
struct V_41 * V_42 = V_51 -> V_80 ;
struct V_15 * V_16 = F_22 ( V_42 ) ;
unsigned long V_30 ;
T_1 V_26 ;
F_13 ( & V_16 -> V_35 , V_30 ) ;
if ( V_84 & V_86 )
V_16 -> V_40 |= V_47 ;
if ( V_84 & V_87 )
V_16 -> V_40 |= V_48 ;
if ( V_85 & V_86 )
V_16 -> V_40 &= ~ V_47 ;
if ( V_85 & V_87 )
V_16 -> V_40 &= ~ V_48 ;
V_26 = V_16 -> V_40 ;
F_14 ( & V_16 -> V_35 , V_30 ) ;
return F_10 ( V_42 -> V_44 -> V_2 , V_26 ) ;
}
static void F_45 ( struct V_41 * V_42 ,
unsigned char * V_88 , T_5 V_89 )
{
struct V_15 * V_16 = F_22 ( V_42 ) ;
struct V_50 * V_51 ;
unsigned long V_30 ;
T_1 V_90 ;
T_1 V_91 ;
if ( V_89 < 4 )
return;
V_90 = ~ V_88 [ 2 ] & V_37 ;
F_13 ( & V_16 -> V_35 , V_30 ) ;
V_91 = V_90 ^ V_16 -> V_36 ;
V_16 -> V_36 = V_90 ;
F_14 ( & V_16 -> V_35 , V_30 ) ;
if ( V_88 [ 1 ] & V_92 )
F_2 ( & V_42 -> V_2 , L_15 , V_53 ) ;
if ( ! V_91 )
return;
if ( V_91 & V_93 )
V_42 -> V_94 . V_95 ++ ;
if ( V_91 & V_96 )
V_42 -> V_94 . V_97 ++ ;
if ( V_91 & V_98 )
V_42 -> V_94 . V_99 ++ ;
if ( V_91 & V_45 ) {
V_42 -> V_94 . V_100 ++ ;
V_51 = F_46 ( & V_42 -> V_42 ) ;
if ( V_51 ) {
F_47 ( V_42 , V_51 ,
V_90 & V_45 ) ;
F_48 ( V_51 ) ;
}
}
F_49 ( & V_42 -> V_42 . V_101 ) ;
}
static void F_50 ( struct V_102 * V_102 )
{
struct V_41 * V_42 = V_102 -> V_103 ;
unsigned char * V_88 = V_102 -> V_104 ;
unsigned int V_89 = V_102 -> V_105 ;
int V_90 ;
switch ( V_102 -> V_90 ) {
case 0 :
break;
case - V_106 :
case - V_107 :
case - V_108 :
F_2 ( & V_102 -> V_2 -> V_2 , L_16 ,
V_53 , V_102 -> V_90 ) ;
return;
default:
F_2 ( & V_102 -> V_2 -> V_2 , L_17 ,
V_53 , V_102 -> V_90 ) ;
goto exit;
}
F_51 ( & V_42 -> V_2 , V_53 , V_89 , V_88 ) ;
F_45 ( V_42 , V_88 , V_89 ) ;
exit:
V_90 = F_30 ( V_102 , V_109 ) ;
if ( V_90 ) {
F_5 ( & V_102 -> V_2 -> V_2 , L_18 ,
V_53 , V_90 ) ;
}
}
static int F_52 ( struct V_50 * V_51 )
{
struct V_41 * V_42 = V_51 -> V_80 ;
struct V_15 * V_16 = F_22 ( V_42 ) ;
unsigned long V_30 ;
T_1 V_110 ;
T_1 V_90 ;
unsigned int V_111 ;
F_13 ( & V_16 -> V_35 , V_30 ) ;
V_110 = V_16 -> V_40 ;
V_90 = V_16 -> V_36 ;
F_14 ( & V_16 -> V_35 , V_30 ) ;
V_111 = ( ( V_110 & V_48 ) ? V_87 : 0 )
| ( ( V_110 & V_47 ) ? V_86 : 0 )
| ( ( V_90 & V_93 ) ? V_112 : 0 )
| ( ( V_90 & V_96 ) ? V_113 : 0 )
| ( ( V_90 & V_98 ) ? V_114 : 0 )
| ( ( V_90 & V_45 ) ? V_115 : 0 ) ;
F_2 ( & V_42 -> V_2 , L_19 , V_53 , V_111 ) ;
return V_111 ;
}
static int F_53 ( struct V_52 * V_44 )
{
struct V_41 * V_42 = V_44 -> V_42 [ 0 ] ;
struct V_15 * V_16 = F_22 ( V_42 ) ;
int V_116 ;
F_16 ( V_44 -> V_2 , V_16 ) ;
if ( F_54 ( & V_42 -> V_42 ) ) {
V_116 = F_30 ( V_42 -> V_49 , V_117 ) ;
if ( V_116 ) {
F_5 ( & V_42 -> V_2 , L_20 ,
V_116 ) ;
return V_116 ;
}
}
return F_55 ( V_44 ) ;
}
