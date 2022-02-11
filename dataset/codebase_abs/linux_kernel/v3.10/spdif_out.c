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
F_7 ( V_18 , V_16 , ( void * ) & V_2 -> V_23 ) ;
V_19 = F_8 ( V_2 -> V_24 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_25 = true ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_15 * V_16 ,
struct V_17 * V_26 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
if ( V_16 -> V_20 != V_21 )
return;
F_10 ( V_2 -> V_24 ) ;
V_2 -> V_25 = false ;
F_7 ( V_26 , V_16 , NULL ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_27 ,
T_1 V_28 )
{
T_1 V_29 , V_30 ;
F_12 ( V_2 -> V_24 , V_27 ) ;
V_29 = F_13 ( F_14 ( V_2 -> V_24 ) , ( V_28 * 128 ) ) ;
V_30 = F_4 ( V_2 -> V_4 + V_31 ) ;
V_30 &= ~ V_32 ;
V_30 |= ( V_29 << V_33 ) & V_32 ;
F_2 ( V_30 , V_2 -> V_4 + V_31 ) ;
}
static int F_15 ( struct V_15 * V_16 ,
struct V_34 * V_35 ,
struct V_17 * V_26 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
T_1 V_28 , V_27 ;
if ( V_16 -> V_20 != V_21 )
return - V_22 ;
V_28 = F_16 ( V_35 ) ;
switch ( V_28 ) {
case 8000 :
case 16000 :
case 32000 :
case 64000 :
V_27 = 64000 * 128 * 10 ;
break;
case 5512 :
case 11025 :
case 22050 :
case 44100 :
case 88200 :
case 176400 :
V_27 = 176400 * 128 ;
break;
case 48000 :
case 96000 :
case 192000 :
default:
V_27 = 192000 * 128 ;
break;
}
F_11 ( V_2 , V_27 , V_28 ) ;
V_2 -> V_36 . V_27 = V_27 ;
V_2 -> V_36 . V_28 = V_28 ;
return 0 ;
}
static int F_17 ( struct V_15 * V_16 , int V_37 ,
struct V_17 * V_26 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
T_1 V_30 ;
int V_19 = 0 ;
if ( V_16 -> V_20 != V_21 )
return - V_22 ;
switch ( V_37 ) {
case V_38 :
case V_39 :
case V_40 :
V_30 = F_4 ( V_2 -> V_4 + V_31 ) ;
V_30 &= ~ V_41 ;
if ( ! V_2 -> V_36 . V_42 )
V_30 |= V_43 |
V_44 ;
else
V_30 |= V_45 ;
F_2 ( V_30 , V_2 -> V_4 + V_31 ) ;
break;
case V_46 :
case V_47 :
case V_48 :
V_30 = F_4 ( V_2 -> V_4 + V_31 ) ;
V_30 &= ~ V_41 ;
V_30 |= V_49 ;
F_2 ( V_30 , V_2 -> V_4 + V_31 ) ;
break;
default:
V_19 = - V_22 ;
break;
}
return V_19 ;
}
static int F_18 ( struct V_17 * V_26 , int V_42 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
T_1 V_50 ;
V_2 -> V_36 . V_42 = V_42 ;
V_50 = F_4 ( V_2 -> V_4 + V_31 ) ;
V_50 &= ~ V_41 ;
if ( V_42 )
V_50 |= V_45 ;
else {
if ( V_2 -> V_25 )
V_50 |= V_43 | V_44 ;
else
V_50 |= V_49 ;
}
F_2 ( V_50 , V_2 -> V_4 + V_31 ) ;
return 0 ;
}
static int F_19 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = F_20 ( V_52 ) ;
struct V_57 * V_58 = V_56 -> V_58 ;
struct V_59 * V_60 = V_58 -> V_60 ;
struct V_17 * V_18 = V_60 -> V_18 ;
struct V_1 * V_2 = F_6 ( V_18 ) ;
V_54 -> V_61 . integer . V_61 [ 0 ] = V_2 -> V_36 . V_42 ;
return 0 ;
}
static int F_21 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = F_20 ( V_52 ) ;
struct V_57 * V_58 = V_56 -> V_58 ;
struct V_59 * V_60 = V_58 -> V_60 ;
struct V_17 * V_18 = V_60 -> V_18 ;
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( V_2 -> V_36 . V_42 == V_54 -> V_61 . integer . V_61 [ 0 ] )
return 0 ;
F_18 ( V_18 , V_54 -> V_61 . integer . V_61 [ 0 ] ) ;
return 1 ;
}
int F_22 ( struct V_17 * V_26 )
{
return F_23 ( V_26 , V_62 ,
F_24 ( V_62 ) ) ;
}
static int F_25 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
int V_19 ;
V_68 = F_26 ( V_64 , V_69 , 0 ) ;
if ( ! V_68 )
return - V_22 ;
if ( ! F_27 ( & V_64 -> V_70 , V_68 -> V_71 ,
F_28 ( V_68 ) , V_64 -> V_72 ) ) {
F_29 ( & V_64 -> V_70 , L_1 ) ;
return - V_73 ;
}
V_2 = F_30 ( & V_64 -> V_70 , sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 ) {
F_29 ( & V_64 -> V_70 , L_2 ) ;
return - V_75 ;
}
V_2 -> V_4 = F_31 ( & V_64 -> V_70 , V_68 -> V_71 ,
F_28 ( V_68 ) ) ;
if ( ! V_2 -> V_4 ) {
F_29 ( & V_64 -> V_70 , L_3 ) ;
return - V_75 ;
}
V_2 -> V_24 = F_32 ( & V_64 -> V_70 , NULL ) ;
if ( F_33 ( V_2 -> V_24 ) )
return F_34 ( V_2 -> V_24 ) ;
V_66 = F_35 ( & V_64 -> V_70 ) ;
V_2 -> V_23 . V_76 = V_66 -> V_23 ;
V_2 -> V_23 . V_77 = V_68 -> V_71 + V_78 ;
V_2 -> V_23 . V_79 = 16 ;
V_2 -> V_23 . V_80 = V_81 ;
V_2 -> V_23 . V_82 = V_66 -> V_82 ;
F_36 ( & V_64 -> V_70 , V_2 ) ;
V_19 = F_37 ( & V_64 -> V_70 , & V_83 ,
& V_84 , 1 ) ;
if ( V_19 != 0 ) {
F_38 ( V_2 -> V_24 ) ;
return V_19 ;
}
return 0 ;
}
static int F_39 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_40 ( & V_64 -> V_70 ) ;
F_41 ( & V_64 -> V_70 ) ;
F_36 ( & V_64 -> V_70 , NULL ) ;
F_38 ( V_2 -> V_24 ) ;
return 0 ;
}
static int F_42 ( struct V_85 * V_70 )
{
struct V_63 * V_64 = F_43 ( V_70 ) ;
struct V_1 * V_2 = F_40 ( & V_64 -> V_70 ) ;
if ( V_2 -> V_25 )
F_10 ( V_2 -> V_24 ) ;
return 0 ;
}
static int F_44 ( struct V_85 * V_70 )
{
struct V_63 * V_64 = F_43 ( V_70 ) ;
struct V_1 * V_2 = F_40 ( & V_64 -> V_70 ) ;
if ( V_2 -> V_25 ) {
F_8 ( V_2 -> V_24 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 , V_2 -> V_36 . V_27 ,
V_2 -> V_36 . V_28 ) ;
}
return 0 ;
}
