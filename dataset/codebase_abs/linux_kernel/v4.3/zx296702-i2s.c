static void F_1 ( void T_1 * V_1 , bool V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_1 + V_4 ) ;
if ( V_2 )
V_3 |= V_5 | V_6 ;
else
V_3 &= ~ ( V_5 | V_6 ) ;
F_3 ( V_3 , V_1 + V_4 ) ;
}
static void F_4 ( void T_1 * V_1 , bool V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_1 + V_4 ) ;
if ( V_2 )
V_3 |= V_7 | V_6 ;
else
V_3 &= ~ ( V_7 | V_6 ) ;
F_3 ( V_3 , V_1 + V_4 ) ;
}
static void F_5 ( void T_1 * V_1 , bool V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_1 + V_8 ) ;
V_3 |= V_9 | ( V_10 << 8 ) ;
if ( V_2 )
V_3 |= V_11 ;
else
V_3 &= ~ V_11 ;
F_3 ( V_3 , V_1 + V_8 ) ;
}
static void F_6 ( void T_1 * V_1 , bool V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_1 + V_8 ) ;
V_3 |= V_12 | ( V_10 << 16 ) ;
if ( V_2 )
V_3 |= V_13 ;
else
V_3 &= ~ V_13 ;
F_3 ( V_3 , V_1 + V_8 ) ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_8 ( V_15 -> V_18 ) ;
F_9 ( V_15 , V_17 ) ;
V_17 -> V_19 . V_20 = V_17 -> V_21 + V_22 ;
V_17 -> V_19 . V_23 = 16 ;
V_17 -> V_24 . V_20 = V_17 -> V_21 + V_22 ;
V_17 -> V_24 . V_23 = 16 ;
F_10 ( V_15 , & V_17 -> V_19 ,
& V_17 -> V_24 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_25 , unsigned int V_26 )
{
struct V_16 * V_27 = F_12 ( V_25 ) ;
unsigned long V_3 ;
V_3 = F_2 ( V_27 -> V_28 + V_29 ) ;
V_3 &= ~ ( V_30 | V_31 |
V_32 | V_33 |
V_34 ) ;
switch ( V_26 & V_35 ) {
case V_36 :
V_3 |= ( V_37 | V_38 ) ;
break;
case V_39 :
V_3 |= ( V_37 | V_40 ) ;
break;
case V_41 :
V_3 |= ( V_37 | V_42 ) ;
break;
default:
F_13 ( V_25 -> V_18 , L_1 ) ;
return - V_43 ;
}
switch ( V_26 & V_44 ) {
case V_45 :
V_27 -> V_46 = 1 ;
V_3 |= V_47 ;
break;
case V_48 :
V_27 -> V_46 = 0 ;
V_3 |= V_49 ;
break;
default:
F_13 ( V_25 -> V_18 , L_2 ) ;
return - V_43 ;
}
F_3 ( V_3 , V_27 -> V_28 + V_29 ) ;
return 0 ;
}
static int F_14 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
struct V_14 * V_54 )
{
struct V_16 * V_27 = F_12 ( V_54 ) ;
struct V_55 * V_56 ;
unsigned int V_57 , V_58 , V_59 , V_60 = 0 ;
unsigned long V_3 , V_61 ;
unsigned long V_62 ;
V_56 = F_15 ( V_54 , V_51 ) ;
V_56 -> V_63 = F_16 ( V_53 ) >> 3 ;
V_3 = F_2 ( V_27 -> V_28 + V_29 ) ;
V_3 &= ~ ( V_64 | V_65 |
V_66 | V_67 |
V_68 ) ;
switch ( F_17 ( V_53 ) ) {
case V_69 :
V_61 = 0 ;
V_59 = 16 ;
break;
case V_70 :
V_61 = 1 ;
V_59 = 24 ;
break;
case V_71 :
V_61 = 2 ;
V_59 = 32 ;
break;
default:
F_13 ( V_54 -> V_18 , L_3 ) ;
return - V_43 ;
}
V_3 |= F_18 ( V_59 ) | F_19 ( V_59 ) ;
V_58 = F_20 ( V_53 ) ;
switch ( V_58 ) {
case 1 :
V_57 = 1 ;
V_62 = 2 ;
break;
case 2 :
case 4 :
case 6 :
case 8 :
V_57 = V_58 / 2 ;
V_62 = 3 ;
break;
default:
F_13 ( V_54 -> V_18 , L_4 , V_58 ) ;
return - V_43 ;
}
V_3 |= F_21 ( V_57 ) ;
V_3 |= F_22 ( V_62 ) ;
V_3 |= F_23 ( V_58 ) ;
F_3 ( V_3 , V_27 -> V_28 + V_29 ) ;
if ( V_27 -> V_46 )
V_60 = F_24 ( V_27 -> V_72 ,
F_25 ( V_53 ) * V_58 * V_73 ) ;
return V_60 ;
}
static int F_26 ( struct V_50 * V_51 , int V_74 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = F_8 ( V_15 -> V_18 ) ;
int V_75 = ( V_51 -> V_76 == V_77 ) ;
int V_60 = 0 ;
switch ( V_74 ) {
case V_78 :
if ( V_75 )
F_6 ( V_17 -> V_28 , true ) ;
else
F_5 ( V_17 -> V_28 , true ) ;
case V_79 :
case V_80 :
if ( V_75 )
F_4 ( V_17 -> V_28 , true ) ;
else
F_1 ( V_17 -> V_28 , true ) ;
break;
case V_81 :
if ( V_75 )
F_6 ( V_17 -> V_28 , false ) ;
else
F_5 ( V_17 -> V_28 , false ) ;
case V_82 :
case V_83 :
if ( V_75 )
F_4 ( V_17 -> V_28 , false ) ;
else
F_1 ( V_17 -> V_28 , false ) ;
break;
default:
V_60 = - V_43 ;
break;
}
return V_60 ;
}
static int F_27 ( struct V_50 * V_51 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = F_8 ( V_15 -> V_18 ) ;
return F_28 ( V_17 -> V_72 ) ;
}
static void F_29 ( struct V_50 * V_51 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = F_8 ( V_15 -> V_18 ) ;
F_30 ( V_17 -> V_72 ) ;
}
static int F_31 ( struct V_84 * V_85 )
{
struct V_86 * V_87 ;
struct V_16 * V_17 ;
int V_60 ;
V_17 = F_32 ( & V_85 -> V_18 , sizeof( * V_17 ) , V_88 ) ;
if ( ! V_17 )
return - V_89 ;
V_17 -> V_72 = F_33 ( & V_85 -> V_18 , L_5 ) ;
if ( F_34 ( V_17 -> V_72 ) ) {
F_13 ( & V_85 -> V_18 , L_6 ) ;
return F_35 ( V_17 -> V_72 ) ;
}
V_87 = F_36 ( V_85 , V_90 , 0 ) ;
V_17 -> V_21 = V_87 -> V_91 ;
V_17 -> V_28 = F_37 ( & V_85 -> V_18 , V_87 ) ;
if ( F_34 ( V_17 -> V_28 ) ) {
F_13 ( & V_85 -> V_18 , L_7 ) ;
return F_35 ( V_17 -> V_28 ) ;
}
F_3 ( 0 , V_17 -> V_28 + V_8 ) ;
F_38 ( V_85 , V_17 ) ;
V_60 = F_39 ( & V_85 -> V_18 , & V_92 ,
& V_93 , 1 ) ;
if ( V_60 ) {
F_13 ( & V_85 -> V_18 , L_8 , V_60 ) ;
return V_60 ;
}
V_60 = F_40 ( & V_85 -> V_18 , NULL , 0 ) ;
if ( V_60 )
F_13 ( & V_85 -> V_18 , L_9 , V_60 ) ;
return V_60 ;
}
