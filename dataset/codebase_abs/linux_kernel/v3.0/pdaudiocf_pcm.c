static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 64 * 1024 ;
while ( F_2 ( V_2 -> V_4 + V_5 ) != F_2 ( V_2 -> V_4 + V_6 ) ) {
if ( V_3 -- < 0 )
return - V_7 ;
F_2 ( V_2 -> V_4 + V_8 ) ;
}
return 0 ;
}
static int F_3 ( struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_12 * V_13 = V_10 -> V_13 ;
int V_14 , V_15 = 0 , V_16 ;
unsigned short V_17 , V_18 , V_19 ;
if ( V_2 -> V_20 & V_21 )
return - V_22 ;
switch ( V_11 ) {
case V_23 :
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
case V_26 :
case V_27 :
V_17 = 0 ;
V_18 = V_28 ;
V_14 = 1 ;
V_16 = F_5 ( V_2 -> V_29 , V_30 | V_31 ) ;
break;
case V_32 :
case V_33 :
case V_34 :
V_17 = V_28 ;
V_18 = 0 ;
V_14 = - 1 ;
V_16 = 0 ;
break;
default:
return - V_35 ;
}
F_6 ( & V_2 -> V_36 ) ;
V_2 -> V_37 += V_14 ;
V_19 = F_7 ( V_2 , V_38 ) ;
if ( V_2 -> V_37 ) {
if ( ( V_2 -> V_29 -> V_39 & V_40 ) || V_13 -> V_16 != V_16 ) {
V_2 -> V_37 -= V_14 ;
V_15 = - V_7 ;
goto V_41;
}
}
V_19 &= ~ V_17 ;
V_19 |= V_18 ;
F_8 ( V_2 , V_38 , V_19 ) ;
V_41:
F_9 ( & V_2 -> V_36 ) ;
F_5 ( V_2 -> V_29 , V_31 ) ;
return V_15 ;
}
static int F_10 ( struct V_9 * V_10 ,
struct V_42 * V_43 )
{
return F_11
( V_10 , F_12 ( V_43 ) ) ;
}
static int F_13 ( struct V_9 * V_10 )
{
return F_14 ( V_10 ) ;
}
static int F_15 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_12 * V_13 = V_10 -> V_13 ;
T_1 V_18 , V_44 , V_45 ;
if ( V_2 -> V_20 & V_21 )
return - V_22 ;
V_2 -> V_46 = V_13 -> V_47 ;
V_2 -> V_48 = F_16 ( V_13 -> V_49 ) > 0 ;
#ifdef F_17
V_2 -> V_50 = F_18 ( V_13 -> V_49 ) > 0 ;
#else
V_2 -> V_50 = V_2 -> V_48 ;
#endif
if ( F_19 ( V_13 -> V_49 ) )
V_2 -> V_51 = 0x80008000 ;
if ( F_1 ( V_2 ) < 0 )
return - V_7 ;
V_18 = V_44 = F_7 ( V_2 , V_38 ) ;
V_44 &= ~ ( V_52 | V_53 ) ;
switch ( V_13 -> V_49 ) {
case V_54 :
case V_55 :
break;
default:
V_44 |= V_52 | V_53 ;
break;
}
V_45 = 0 ;
V_2 -> V_56 = 4 ;
switch ( V_13 -> V_49 ) {
case V_54 :
case V_55 :
V_45 = V_57 ;
V_2 -> V_58 = 2 ;
V_2 -> V_56 = 2 ;
break;
case V_59 :
case V_60 :
V_2 -> V_56 = 3 ;
default:
V_45 = V_61 ;
V_2 -> V_58 = 3 ;
V_2 -> V_51 &= 0xffff0000 ;
break;
}
if ( V_18 != V_44 ) {
F_20 ( V_2 -> V_29 , V_62 , V_63 | V_64 | V_65 , V_45 ) ;
F_8 ( V_2 , V_38 , V_44 ) ;
}
V_18 = F_7 ( V_2 , V_66 ) ;
V_18 &= ~ ( V_67 ) ;
V_18 |= V_68 ;
F_8 ( V_2 , V_66 , V_18 ) ;
V_2 -> V_69 = V_13 -> V_70 ;
V_2 -> V_71 = V_13 -> V_72 ;
V_2 -> V_73 = V_13 -> V_74 ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_2 -> V_20 & V_21 )
return - V_22 ;
V_13 -> V_75 = V_76 ;
V_13 -> V_77 = V_2 ;
V_2 -> V_78 = V_10 ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( ! V_2 )
return - V_35 ;
F_23 ( V_2 , 0 ) ;
V_2 -> V_78 = NULL ;
return 0 ;
}
static T_2 F_24 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
return V_2 -> V_24 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_79 * V_80 ;
int V_81 ;
V_81 = F_26 ( V_2 -> V_82 , L_1 , 0 , 0 , 1 , & V_80 ) ;
if ( V_81 < 0 )
return V_81 ;
F_27 ( V_80 , V_83 , & V_84 ) ;
V_80 -> V_77 = V_2 ;
V_80 -> V_85 = 0 ;
strcpy ( V_80 -> V_86 , V_2 -> V_82 -> V_87 ) ;
V_2 -> V_80 = V_80 ;
V_81 = F_28 ( V_2 -> V_29 , V_80 -> V_88 [ V_83 ] . V_89 ) ;
if ( V_81 < 0 )
return V_81 ;
return 0 ;
}
