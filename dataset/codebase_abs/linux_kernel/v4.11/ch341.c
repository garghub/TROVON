static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
int V_6 ;
F_2 ( & V_2 -> V_2 , L_1 , V_7 ,
V_3 , V_4 , V_5 ) ;
V_6 = F_3 ( V_2 , F_4 ( V_2 , 0 ) , V_3 ,
V_8 | V_9 | V_10 ,
V_4 , V_5 , NULL , 0 , V_11 ) ;
if ( V_6 < 0 )
F_5 ( & V_2 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_2 V_5 ,
char * V_12 , unsigned V_13 )
{
int V_6 ;
F_2 ( & V_2 -> V_2 , L_3 , V_7 ,
V_3 , V_4 , V_5 , V_13 ) ;
V_6 = F_3 ( V_2 , F_7 ( V_2 , 0 ) , V_3 ,
V_8 | V_9 | V_14 ,
V_4 , V_5 , V_12 , V_13 , V_11 ) ;
if ( V_6 < V_13 ) {
if ( V_6 >= 0 ) {
F_5 ( & V_2 -> V_2 ,
L_4 ,
V_6 , V_13 ) ;
V_6 = - V_15 ;
}
F_5 ( & V_2 -> V_2 , L_5 ,
V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_16 * V_17 , T_1 V_18 )
{
short V_19 ;
int V_6 ;
unsigned long V_20 ;
short V_21 ;
if ( ! V_17 -> V_22 )
return - V_23 ;
V_20 = ( V_24 / V_17 -> V_22 ) ;
V_21 = V_25 ;
while ( ( V_20 > 0xfff0 ) && V_21 ) {
V_20 >>= 3 ;
V_21 -- ;
}
if ( V_20 > 0xfff0 )
return - V_23 ;
V_20 = 0x10000 - V_20 ;
V_19 = ( V_20 & 0xff00 ) | V_21 ;
V_19 |= F_9 ( 7 ) ;
V_6 = F_1 ( V_2 , V_26 , 0x1312 , V_19 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , V_26 , 0x2518 , V_18 ) ;
if ( V_6 )
return V_6 ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_27 )
{
return F_1 ( V_2 , V_28 , ~ V_27 , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
const unsigned int V_29 = 2 ;
char * V_30 ;
int V_6 ;
unsigned long V_31 ;
V_30 = F_12 ( V_29 , V_32 ) ;
if ( ! V_30 )
return - V_33 ;
V_6 = F_6 ( V_2 , V_34 , 0x0706 , 0 , V_30 , V_29 ) ;
if ( V_6 < 0 )
goto V_35;
F_13 ( & V_17 -> V_36 , V_31 ) ;
V_17 -> V_37 = ( ~ ( * V_30 ) ) & V_38 ;
F_14 ( & V_17 -> V_36 , V_31 ) ;
V_35: F_15 ( V_30 ) ;
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
const unsigned int V_29 = 2 ;
char * V_30 ;
int V_6 ;
V_30 = F_12 ( V_29 , V_32 ) ;
if ( ! V_30 )
return - V_33 ;
V_6 = F_6 ( V_2 , V_39 , 0 , 0 , V_30 , V_29 ) ;
if ( V_6 < 0 )
goto V_35;
F_2 ( & V_2 -> V_2 , L_6 , V_30 [ 0 ] ) ;
V_6 = F_1 ( V_2 , V_40 , 0 , 0 ) ;
if ( V_6 < 0 )
goto V_35;
V_6 = F_8 ( V_2 , V_17 , V_17 -> V_18 ) ;
if ( V_6 < 0 )
goto V_35;
V_6 = F_10 ( V_2 , V_17 -> V_41 ) ;
V_35: F_15 ( V_30 ) ;
return V_6 ;
}
static int F_17 ( struct V_42 * V_43 )
{
struct V_16 * V_17 ;
int V_6 ;
V_17 = F_18 ( sizeof( struct V_16 ) , V_32 ) ;
if ( ! V_17 )
return - V_33 ;
F_19 ( & V_17 -> V_36 ) ;
V_17 -> V_22 = V_44 ;
V_17 -> V_18 = V_45 | V_46 | V_47 ;
V_6 = F_16 ( V_43 -> V_48 -> V_2 , V_17 ) ;
if ( V_6 < 0 )
goto error;
F_20 ( V_43 , V_17 ) ;
return 0 ;
error: F_15 ( V_17 ) ;
return V_6 ;
}
static int F_21 ( struct V_42 * V_43 )
{
struct V_16 * V_17 ;
V_17 = F_22 ( V_43 ) ;
F_15 ( V_17 ) ;
return 0 ;
}
static int F_23 ( struct V_42 * V_43 )
{
struct V_16 * V_17 = F_22 ( V_43 ) ;
if ( V_17 -> V_37 & V_49 )
return 1 ;
return 0 ;
}
static void F_24 ( struct V_42 * V_43 , int V_50 )
{
struct V_16 * V_17 = F_22 ( V_43 ) ;
unsigned long V_31 ;
F_13 ( & V_17 -> V_36 , V_31 ) ;
if ( V_50 )
V_17 -> V_41 |= V_51 | V_52 ;
else
V_17 -> V_41 &= ~ ( V_51 | V_52 ) ;
F_14 ( & V_17 -> V_36 , V_31 ) ;
F_10 ( V_43 -> V_48 -> V_2 , V_17 -> V_41 ) ;
}
static void F_25 ( struct V_42 * V_43 )
{
F_26 ( V_43 ) ;
F_27 ( V_43 -> V_53 ) ;
}
static int F_28 ( struct V_54 * V_55 , struct V_42 * V_43 )
{
struct V_16 * V_17 = F_22 ( V_43 ) ;
int V_6 ;
if ( V_55 )
F_29 ( V_55 , V_43 , NULL ) ;
F_2 ( & V_43 -> V_2 , L_7 , V_7 ) ;
V_6 = F_30 ( V_43 -> V_53 , V_32 ) ;
if ( V_6 ) {
F_5 ( & V_43 -> V_2 , L_8 ,
V_7 , V_6 ) ;
return V_6 ;
}
V_6 = F_11 ( V_43 -> V_48 -> V_2 , V_17 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_43 -> V_2 , L_9 , V_6 ) ;
goto V_56;
}
V_6 = F_31 ( V_55 , V_43 ) ;
if ( V_6 )
goto V_56;
return 0 ;
V_56:
F_27 ( V_43 -> V_53 ) ;
return V_6 ;
}
static void F_29 ( struct V_54 * V_55 ,
struct V_42 * V_43 , struct V_57 * V_58 )
{
struct V_16 * V_17 = F_22 ( V_43 ) ;
unsigned V_22 ;
unsigned long V_31 ;
T_1 V_18 ;
int V_6 ;
if ( V_58 && ! F_32 ( & V_55 -> V_59 , V_58 ) )
return;
V_22 = F_33 ( V_55 ) ;
V_18 = V_45 | V_46 ;
switch ( F_34 ( V_55 ) ) {
case V_60 :
V_18 |= V_61 ;
break;
case V_62 :
V_18 |= V_63 ;
break;
case V_64 :
V_18 |= V_65 ;
break;
case V_66 :
V_18 |= V_47 ;
break;
}
if ( F_35 ( V_55 ) ) {
V_18 |= V_67 ;
if ( F_36 ( V_55 ) == 0 )
V_18 |= V_68 ;
if ( F_37 ( V_55 ) )
V_18 |= V_69 ;
}
if ( F_38 ( V_55 ) )
V_18 |= V_70 ;
if ( V_22 ) {
V_17 -> V_22 = V_22 ;
V_6 = F_8 ( V_43 -> V_48 -> V_2 , V_17 , V_18 ) ;
if ( V_6 < 0 && V_58 ) {
V_17 -> V_22 = F_39 ( V_58 ) ;
F_40 ( & V_55 -> V_59 , V_58 ) ;
} else if ( V_6 == 0 ) {
V_17 -> V_18 = V_18 ;
}
}
F_13 ( & V_17 -> V_36 , V_31 ) ;
if ( F_41 ( V_55 ) == V_71 )
V_17 -> V_41 &= ~ ( V_52 | V_51 ) ;
else if ( V_58 && ( V_58 -> V_72 & V_73 ) == V_71 )
V_17 -> V_41 |= ( V_52 | V_51 ) ;
F_14 ( & V_17 -> V_36 , V_31 ) ;
F_10 ( V_43 -> V_48 -> V_2 , V_17 -> V_41 ) ;
}
static void F_42 ( struct V_54 * V_55 , int V_74 )
{
const T_3 V_75 =
( ( T_3 ) V_76 << 8 ) | V_77 ;
struct V_42 * V_43 = V_55 -> V_78 ;
int V_6 ;
T_3 V_79 ;
T_4 * V_80 ;
V_80 = F_12 ( 2 , V_32 ) ;
if ( ! V_80 )
return;
V_6 = F_6 ( V_43 -> V_48 -> V_2 , V_34 ,
V_75 , 0 , V_80 , 2 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_43 -> V_2 , L_10 ,
V_7 , V_6 ) ;
goto V_35;
}
F_2 ( & V_43 -> V_2 , L_11 ,
V_7 , V_80 [ 0 ] , V_80 [ 1 ] ) ;
if ( V_74 != 0 ) {
F_2 ( & V_43 -> V_2 , L_12 , V_7 ) ;
V_80 [ 0 ] &= ~ V_81 ;
V_80 [ 1 ] &= ~ V_46 ;
} else {
F_2 ( & V_43 -> V_2 , L_13 , V_7 ) ;
V_80 [ 0 ] |= V_81 ;
V_80 [ 1 ] |= V_46 ;
}
F_2 ( & V_43 -> V_2 , L_14 ,
V_7 , V_80 [ 0 ] , V_80 [ 1 ] ) ;
V_79 = F_43 ( V_80 ) ;
V_6 = F_1 ( V_43 -> V_48 -> V_2 , V_26 ,
V_75 , V_79 ) ;
if ( V_6 < 0 )
F_5 ( & V_43 -> V_2 , L_15 ,
V_7 , V_6 ) ;
V_35:
F_15 ( V_80 ) ;
}
static int F_44 ( struct V_54 * V_55 ,
unsigned int V_82 , unsigned int V_83 )
{
struct V_42 * V_43 = V_55 -> V_78 ;
struct V_16 * V_17 = F_22 ( V_43 ) ;
unsigned long V_31 ;
T_1 V_27 ;
F_13 ( & V_17 -> V_36 , V_31 ) ;
if ( V_82 & V_84 )
V_17 -> V_41 |= V_51 ;
if ( V_82 & V_85 )
V_17 -> V_41 |= V_52 ;
if ( V_83 & V_84 )
V_17 -> V_41 &= ~ V_51 ;
if ( V_83 & V_85 )
V_17 -> V_41 &= ~ V_52 ;
V_27 = V_17 -> V_41 ;
F_14 ( & V_17 -> V_36 , V_31 ) ;
return F_10 ( V_43 -> V_48 -> V_2 , V_27 ) ;
}
static void F_45 ( struct V_42 * V_43 ,
unsigned char * V_86 , T_5 V_87 )
{
struct V_16 * V_17 = F_22 ( V_43 ) ;
struct V_54 * V_55 ;
unsigned long V_31 ;
T_1 V_88 ;
T_1 V_89 ;
if ( V_87 < 4 )
return;
V_88 = ~ V_86 [ 2 ] & V_38 ;
F_13 ( & V_17 -> V_36 , V_31 ) ;
V_89 = V_88 ^ V_17 -> V_37 ;
V_17 -> V_37 = V_88 ;
F_14 ( & V_17 -> V_36 , V_31 ) ;
if ( V_86 [ 1 ] & V_90 )
F_2 ( & V_43 -> V_2 , L_16 , V_7 ) ;
if ( ! V_89 )
return;
if ( V_89 & V_91 )
V_43 -> V_92 . V_93 ++ ;
if ( V_89 & V_94 )
V_43 -> V_92 . V_95 ++ ;
if ( V_89 & V_96 )
V_43 -> V_92 . V_97 ++ ;
if ( V_89 & V_49 ) {
V_43 -> V_92 . V_98 ++ ;
V_55 = F_46 ( & V_43 -> V_43 ) ;
if ( V_55 ) {
F_47 ( V_43 , V_55 ,
V_88 & V_49 ) ;
F_48 ( V_55 ) ;
}
}
F_49 ( & V_43 -> V_43 . V_99 ) ;
}
static void F_50 ( struct V_100 * V_100 )
{
struct V_42 * V_43 = V_100 -> V_101 ;
unsigned char * V_86 = V_100 -> V_102 ;
unsigned int V_87 = V_100 -> V_103 ;
int V_88 ;
switch ( V_100 -> V_88 ) {
case 0 :
break;
case - V_104 :
case - V_105 :
case - V_106 :
F_2 ( & V_100 -> V_2 -> V_2 , L_17 ,
V_7 , V_100 -> V_88 ) ;
return;
default:
F_2 ( & V_100 -> V_2 -> V_2 , L_18 ,
V_7 , V_100 -> V_88 ) ;
goto exit;
}
F_51 ( & V_43 -> V_2 , V_7 , V_87 , V_86 ) ;
F_45 ( V_43 , V_86 , V_87 ) ;
exit:
V_88 = F_30 ( V_100 , V_107 ) ;
if ( V_88 ) {
F_5 ( & V_100 -> V_2 -> V_2 , L_19 ,
V_7 , V_88 ) ;
}
}
static int F_52 ( struct V_54 * V_55 )
{
struct V_42 * V_43 = V_55 -> V_78 ;
struct V_16 * V_17 = F_22 ( V_43 ) ;
unsigned long V_31 ;
T_1 V_41 ;
T_1 V_88 ;
unsigned int V_108 ;
F_13 ( & V_17 -> V_36 , V_31 ) ;
V_41 = V_17 -> V_41 ;
V_88 = V_17 -> V_37 ;
F_14 ( & V_17 -> V_36 , V_31 ) ;
V_108 = ( ( V_41 & V_52 ) ? V_85 : 0 )
| ( ( V_41 & V_51 ) ? V_84 : 0 )
| ( ( V_88 & V_91 ) ? V_109 : 0 )
| ( ( V_88 & V_94 ) ? V_110 : 0 )
| ( ( V_88 & V_96 ) ? V_111 : 0 )
| ( ( V_88 & V_49 ) ? V_112 : 0 ) ;
F_2 ( & V_43 -> V_2 , L_20 , V_7 , V_108 ) ;
return V_108 ;
}
static int F_53 ( struct V_113 * V_48 )
{
struct V_42 * V_43 = V_48 -> V_43 [ 0 ] ;
struct V_16 * V_17 = F_22 ( V_43 ) ;
int V_114 ;
F_16 ( V_48 -> V_2 , V_17 ) ;
if ( F_54 ( & V_43 -> V_43 ) ) {
V_114 = F_30 ( V_43 -> V_53 , V_115 ) ;
if ( V_114 ) {
F_5 ( & V_43 -> V_2 , L_21 ,
V_114 ) ;
return V_114 ;
}
V_114 = F_11 ( V_43 -> V_48 -> V_2 , V_17 ) ;
if ( V_114 < 0 ) {
F_5 ( & V_43 -> V_2 , L_9 ,
V_114 ) ;
}
}
return F_55 ( V_48 ) ;
}
