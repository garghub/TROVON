static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_6 * V_7 ;
V_7 = F_2 ( sizeof( struct V_6 ) , V_8 ) ;
if ( ! V_7 )
return - V_9 ;
F_3 ( & V_7 -> V_10 ) ;
V_7 -> V_11 = 0 ;
V_7 -> V_12 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 =
( F_4 ( V_4 -> V_15 . V_16 ) <= 0x0206 ) ? 1 : 0 ;
F_5 ( & V_4 -> V_4 , L_1 ,
F_4 ( V_4 -> V_15 . V_16 ) ,
V_7 -> V_14 ) ;
F_6 ( V_2 , V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = F_8 ( V_2 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_11 ( V_2 -> V_20 , V_8 ) ;
if ( V_19 ) {
F_12 ( & V_2 -> V_4 , L_2 ) ;
return V_19 ;
}
V_19 = F_13 ( V_18 , V_2 ) ;
if ( V_19 )
F_14 ( V_2 -> V_20 ) ;
return V_19 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_14 ( V_2 -> V_20 ) ;
}
static void F_17 ( struct V_21 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
struct V_6 * V_7 ;
unsigned char * V_23 = V_21 -> V_24 ;
int V_19 ;
int V_25 = V_21 -> V_25 ;
unsigned long V_26 ;
switch ( V_25 ) {
case 0 :
break;
case - V_27 :
case - V_28 :
case - V_29 :
F_18 ( & V_2 -> V_4 , L_3 ,
V_30 , V_25 ) ;
return;
default:
F_18 ( & V_2 -> V_4 , L_4 ,
V_30 , V_25 ) ;
goto exit;
}
F_19 ( & V_2 -> V_4 , V_30 , V_21 -> V_31 , V_23 ) ;
V_7 = F_8 ( V_2 ) ;
F_20 ( & V_7 -> V_10 , V_26 ) ;
V_7 -> V_13 = V_23 [ V_32 ] ;
if ( V_7 -> V_13 & V_33 )
V_7 -> V_11 |= V_34 ;
else
V_7 -> V_11 &= ~ V_34 ;
if ( V_7 -> V_13 & V_35 )
V_7 -> V_11 |= V_36 ;
else
V_7 -> V_11 &= ~ V_36 ;
if ( V_7 -> V_13 & V_37 )
V_7 -> V_11 |= V_38 ;
else
V_7 -> V_11 &= ~ V_38 ;
if ( V_7 -> V_13 & V_39 )
V_7 -> V_11 |= V_40 ;
else
V_7 -> V_11 &= ~ V_40 ;
V_7 -> V_12 = V_23 [ V_41 ] ;
F_21 ( & V_7 -> V_10 , V_26 ) ;
exit:
V_19 = F_11 ( V_21 , V_42 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_4 , L_5
L_6 , V_30 , V_19 ) ;
}
static void F_22 ( struct V_21 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
struct V_6 * V_7 = F_8 ( V_2 ) ;
struct V_17 * V_18 ;
unsigned char * V_23 = V_21 -> V_24 ;
unsigned long V_26 ;
unsigned char V_25 ;
char V_43 ;
V_43 = V_44 ;
F_20 ( & V_7 -> V_10 , V_26 ) ;
V_25 = V_7 -> V_12 ;
V_7 -> V_12 &= ~ V_45 ;
F_21 ( & V_7 -> V_10 , V_26 ) ;
if ( ! V_21 -> V_31 )
return;
V_18 = F_23 ( & V_2 -> V_2 ) ;
if ( ! V_18 )
return;
if ( V_25 & V_45 ) {
if ( V_25 & V_46 )
V_43 = V_47 ;
else if ( V_25 & V_48 )
V_43 = V_49 ;
else if ( V_25 & V_50 )
V_43 = V_51 ;
F_18 ( & V_2 -> V_4 , L_7 , V_43 ) ;
if ( V_25 & V_52 )
F_24 ( V_18 , 0 , V_53 ) ;
}
F_25 ( V_18 , V_23 , V_43 ,
V_21 -> V_31 ) ;
F_26 ( V_18 ) ;
F_27 ( V_18 ) ;
}
static void F_28 ( struct V_17 * V_18 ,
struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_56 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_8 ( V_2 ) ;
unsigned int V_57 ;
unsigned int V_58 ;
unsigned int V_59 = 0 ;
unsigned int V_60 = 0 ;
T_1 V_61 = 0 ;
unsigned long V_26 ;
unsigned long V_11 ;
int V_14 ;
T_2 V_62 ;
struct V_54 * V_63 = & V_18 -> V_63 ;
V_57 = V_63 -> V_64 ;
V_58 = V_63 -> V_65 ;
V_63 -> V_65 &= ~ V_66 ;
F_20 ( & V_7 -> V_10 , V_26 ) ;
V_11 = V_7 -> V_11 ;
V_14 = V_7 -> V_14 ;
F_21 ( & V_7 -> V_10 , V_26 ) ;
V_59 = V_55 -> V_64 ;
V_60 = V_55 -> V_65 ;
if ( ( V_58 & V_67 ) != ( V_60 & V_67 ) ) {
if ( ( V_60 & V_67 ) == V_68 ) {
V_11 |= ( V_69 | V_70 ) ;
if ( F_29 ( V_71 , 1 ) < 0 )
F_12 ( & V_2 -> V_4 , L_8 ) ;
if ( ! ( V_60 & V_72 ) )
if ( F_29 ( V_73
, 1 ) < 0 )
F_12 ( & V_2 -> V_4 , L_9 ) ;
}
}
V_62 = F_30 ( V_18 ) ;
if ( V_62 ) {
V_61 = F_31 ( V_62 ) ;
if ( V_61 == 0 )
V_61 = 1 ;
V_62 = F_31 ( V_61 ) ;
F_32 ( V_18 , V_62 , V_62 ) ;
if ( F_29 ( V_74 , V_61 ) < 0 )
F_12 ( & V_2 -> V_4 , L_10 ) ;
} else {
if ( F_29 ( V_75 ,
V_76 ) < 0 )
F_12 ( & V_2 -> V_4 , L_11 ) ;
V_11 &= ~ ( V_69 | V_70 ) ;
if ( F_29 ( V_71 , 0 ) < 0 )
F_12 ( & V_2 -> V_4 , L_12 ) ;
if ( F_29 ( V_73 , 0 ) < 0 )
F_12 ( & V_2 -> V_4 , L_13 ) ;
}
if ( ( V_58 ^ V_60 ) & ( V_77 | V_78 ) ) {
if ( V_58 & V_77 )
V_61 = ( V_58 & V_78 ) ? V_79
: V_80 ;
else
V_61 = V_81 ;
if ( F_29 ( V_82 , V_61 ) < 0 )
F_12 ( & V_2 -> V_4 , L_14 ) ;
}
if ( ( V_58 & V_83 ) != ( V_60 & V_83 ) ) {
switch ( V_58 & V_83 ) {
case V_84 :
V_61 = F_33 ( 5 ) ;
break;
case V_85 :
V_61 = F_33 ( 6 ) ;
break;
case V_86 :
V_61 = F_33 ( 7 ) ;
break;
case V_87 :
V_61 = F_33 ( 8 ) ;
break;
default:
F_18 ( & V_2 -> V_4 ,
L_15 ) ;
V_61 = F_33 ( 8 ) ;
break;
}
if ( F_29 ( V_88 , V_61 ) < 0 )
F_12 ( & V_2 -> V_4 , L_16 ) ;
}
if ( ( V_58 & V_89 ) != ( V_60 & V_89 ) ) {
V_61 = ( V_58 & V_89 ) ? F_34 ( 2 )
: F_34 ( 1 ) ;
if ( F_29 ( V_90 ,
V_61 ) < 0 )
F_12 ( & V_2 -> V_4 , L_17 ) ;
}
if ( ( ( V_57 ^ V_59 ) & ( V_91 | V_92 ) ) ||
( ( V_58 ^ V_60 ) & V_72 ) ) {
V_61 = 0 ;
if ( ( V_57 & V_91 ) || ( V_57 & V_92 ) )
V_61 |= ( V_93 | V_94 ) ;
else
V_61 &= ~ ( V_93 | V_94 ) ;
if ( V_58 & V_72 )
V_61 |= ( V_95 | V_96 ) ;
else
V_61 &= ~ ( V_95 | V_96 ) ;
if ( V_14 )
V_61 &= ~ ( V_96 ) ;
if ( F_29 ( V_75 , V_61 ) < 0 )
F_12 ( & V_2 -> V_4 , L_18 ) ;
}
F_20 ( & V_7 -> V_10 , V_26 ) ;
V_7 -> V_11 = V_11 ;
F_21 ( & V_7 -> V_10 , V_26 ) ;
}
static void F_35 ( struct V_17 * V_18 , int V_97 )
{
struct V_1 * V_2 = V_18 -> V_98 ;
struct V_56 * V_5 = V_2 -> V_5 ;
if ( F_29 ( V_99 , V_97 ? 1 : 0 ) < 0 )
F_12 ( & V_2 -> V_4 , L_19 , V_97 ) ;
}
static int F_36 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_98 ;
struct V_6 * V_7 = F_8 ( V_2 ) ;
unsigned long V_11 ;
unsigned long V_26 ;
F_20 ( & V_7 -> V_10 , V_26 ) ;
V_11 = V_7 -> V_11 ;
F_21 ( & V_7 -> V_10 , V_26 ) ;
return V_11 ;
}
static int F_37 ( struct V_17 * V_18 ,
unsigned int V_100 , unsigned int V_101 )
{
struct V_1 * V_2 = V_18 -> V_98 ;
struct V_56 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_8 ( V_2 ) ;
unsigned long V_11 ;
unsigned long V_26 ;
int V_19 ;
int V_102 = 0 ;
int V_103 = 0 ;
F_20 ( & V_7 -> V_10 , V_26 ) ;
V_11 = V_7 -> V_11 ;
if ( V_100 & V_70 ) {
V_11 |= V_70 ;
V_102 = 1 ;
}
if ( V_100 & V_69 ) {
V_11 |= V_69 ;
V_103 = 1 ;
}
if ( V_101 & V_70 ) {
V_11 &= ~ V_70 ;
V_102 = 0 ;
}
if ( V_101 & V_69 ) {
V_11 &= ~ V_69 ;
V_103 = 0 ;
}
V_7 -> V_11 = V_11 ;
F_21 ( & V_7 -> V_10 , V_26 ) ;
V_19 = F_29 ( V_73 , V_102 ) ;
if ( V_19 < 0 ) {
F_12 ( & V_2 -> V_4 , L_20 , V_19 ) ;
goto exit;
}
V_19 = F_29 ( V_71 , V_103 ) ;
if ( V_19 < 0 ) {
F_12 ( & V_2 -> V_4 , L_21 , V_19 ) ;
goto exit;
}
exit:
return V_19 ;
}
