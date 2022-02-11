static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_3 ( 1 ) ;
F_2 ( F_4 ( V_2 -> V_4 + V_5 ) & ~ V_3 ,
V_2 -> V_4 + V_5 ) ;
F_2 ( V_6 | V_7 |
V_8 | V_9 |
V_10 | V_11 ,
V_2 -> V_4 + V_12 ) ;
F_2 ( 0x7F , V_2 -> V_4 + V_13 ) ;
F_2 ( 0x7F , V_2 -> V_4 + V_14 ) ;
}
static int F_5 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
int V_19 ;
if ( V_16 -> V_20 != V_21 )
return - V_22 ;
V_19 = F_7 ( V_2 -> V_23 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_24 = true ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_8 ( struct V_15 * V_16 ,
struct V_17 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
if ( V_16 -> V_20 != V_21 )
return;
F_9 ( V_2 -> V_23 ) ;
V_2 -> V_24 = false ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_26 ,
T_1 V_27 )
{
T_1 V_28 , V_29 ;
F_11 ( V_2 -> V_23 , V_26 ) ;
V_28 = F_12 ( F_13 ( V_2 -> V_23 ) , ( V_27 * 128 ) ) ;
V_29 = F_4 ( V_2 -> V_4 + V_30 ) ;
V_29 &= ~ V_31 ;
V_29 |= ( V_28 << V_32 ) & V_31 ;
F_2 ( V_29 , V_2 -> V_4 + V_30 ) ;
}
static int F_14 ( struct V_15 * V_16 ,
struct V_33 * V_34 ,
struct V_17 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_1 V_27 , V_26 ;
if ( V_16 -> V_20 != V_21 )
return - V_22 ;
V_27 = F_15 ( V_34 ) ;
switch ( V_27 ) {
case 8000 :
case 16000 :
case 32000 :
case 64000 :
V_26 = 64000 * 128 * 10 ;
break;
case 5512 :
case 11025 :
case 22050 :
case 44100 :
case 88200 :
case 176400 :
V_26 = 176400 * 128 ;
break;
case 48000 :
case 96000 :
case 192000 :
default:
V_26 = 192000 * 128 ;
break;
}
F_10 ( V_2 , V_26 , V_27 ) ;
V_2 -> V_35 . V_26 = V_26 ;
V_2 -> V_35 . V_27 = V_27 ;
return 0 ;
}
static int F_16 ( struct V_15 * V_16 , int V_36 ,
struct V_17 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_1 V_29 ;
int V_19 = 0 ;
if ( V_16 -> V_20 != V_21 )
return - V_22 ;
switch ( V_36 ) {
case V_37 :
case V_38 :
case V_39 :
V_29 = F_4 ( V_2 -> V_4 + V_30 ) ;
V_29 &= ~ V_40 ;
if ( ! V_2 -> V_35 . V_41 )
V_29 |= V_42 |
V_43 ;
else
V_29 |= V_44 ;
F_2 ( V_29 , V_2 -> V_4 + V_30 ) ;
break;
case V_45 :
case V_46 :
case V_47 :
V_29 = F_4 ( V_2 -> V_4 + V_30 ) ;
V_29 &= ~ V_40 ;
V_29 |= V_48 ;
F_2 ( V_29 , V_2 -> V_4 + V_30 ) ;
break;
default:
V_19 = - V_22 ;
break;
}
return V_19 ;
}
static int F_17 ( struct V_17 * V_25 , int V_41 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_1 V_49 ;
V_2 -> V_35 . V_41 = V_41 ;
V_49 = F_4 ( V_2 -> V_4 + V_30 ) ;
V_49 &= ~ V_40 ;
if ( V_41 )
V_49 |= V_44 ;
else {
if ( V_2 -> V_24 )
V_49 |= V_42 | V_43 ;
else
V_49 |= V_48 ;
}
F_2 ( V_49 , V_2 -> V_4 + V_30 ) ;
return 0 ;
}
static int F_18 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_19 ( V_51 ) ;
struct V_56 * V_57 = V_55 -> V_57 ;
struct V_58 * V_59 = V_57 -> V_59 ;
struct V_17 * V_18 = V_59 -> V_18 ;
struct V_1 * V_2 = F_6 ( V_18 ) ;
V_53 -> V_60 . integer . V_60 [ 0 ] = V_2 -> V_35 . V_41 ;
return 0 ;
}
static int F_20 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_19 ( V_51 ) ;
struct V_56 * V_57 = V_55 -> V_57 ;
struct V_58 * V_59 = V_57 -> V_59 ;
struct V_17 * V_18 = V_59 -> V_18 ;
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( V_2 -> V_35 . V_41 == V_53 -> V_60 . integer . V_60 [ 0 ] )
return 0 ;
F_17 ( V_18 , V_53 -> V_60 . integer . V_60 [ 0 ] ) ;
return 1 ;
}
static int F_21 ( struct V_17 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
V_25 -> V_61 = & V_2 -> V_62 ;
return F_22 ( V_25 , V_63 ,
F_23 ( V_63 ) ) ;
}
static int F_24 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
int V_19 ;
V_2 = F_25 ( & V_65 -> V_70 , sizeof( * V_2 ) , V_71 ) ;
if ( ! V_2 ) {
F_26 ( & V_65 -> V_70 , L_1 ) ;
return - V_72 ;
}
V_69 = F_27 ( V_65 , V_73 , 0 ) ;
V_2 -> V_4 = F_28 ( & V_65 -> V_70 , V_69 ) ;
if ( F_29 ( V_2 -> V_4 ) )
return F_30 ( V_2 -> V_4 ) ;
V_2 -> V_23 = F_31 ( & V_65 -> V_70 , NULL ) ;
if ( F_29 ( V_2 -> V_23 ) )
return F_30 ( V_2 -> V_23 ) ;
V_67 = F_32 ( & V_65 -> V_70 ) ;
V_2 -> V_62 . V_74 = V_67 -> V_62 ;
V_2 -> V_62 . V_75 = V_69 -> V_76 + V_77 ;
V_2 -> V_62 . V_78 = 16 ;
V_2 -> V_62 . V_79 = V_80 ;
V_2 -> V_62 . V_81 = V_67 -> V_81 ;
F_33 ( & V_65 -> V_70 , V_2 ) ;
V_19 = F_34 ( & V_65 -> V_70 , & V_82 ,
& V_83 , 1 ) ;
return V_19 ;
}
static int F_35 ( struct V_64 * V_65 )
{
F_36 ( & V_65 -> V_70 ) ;
return 0 ;
}
static int F_37 ( struct V_84 * V_70 )
{
struct V_64 * V_65 = F_38 ( V_70 ) ;
struct V_1 * V_2 = F_39 ( & V_65 -> V_70 ) ;
if ( V_2 -> V_24 )
F_9 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_40 ( struct V_84 * V_70 )
{
struct V_64 * V_65 = F_38 ( V_70 ) ;
struct V_1 * V_2 = F_39 ( & V_65 -> V_70 ) ;
if ( V_2 -> V_24 ) {
F_7 ( V_2 -> V_23 ) ;
F_1 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_35 . V_26 ,
V_2 -> V_35 . V_27 ) ;
}
return 0 ;
}
