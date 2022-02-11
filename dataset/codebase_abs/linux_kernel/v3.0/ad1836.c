static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
switch ( V_3 & V_4 ) {
case V_5 :
break;
default:
return - V_6 ;
}
switch ( V_3 & V_7 ) {
case V_8 :
break;
default:
return - V_6 ;
}
switch ( V_3 & V_9 ) {
case V_10 :
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_2 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_1 * V_15 )
{
int V_16 = 0 ;
struct V_17 * V_18 = V_12 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
switch ( F_3 ( V_14 ) ) {
case V_22 :
V_16 = V_23 ;
break;
case V_24 :
V_16 = V_25 ;
break;
case V_26 :
case V_27 :
V_16 = V_28 ;
break;
}
F_4 ( V_21 , V_29 , V_30 ,
V_16 << V_31 ) ;
F_4 ( V_21 , V_32 , V_33 ,
V_16 << V_34 ) ;
return 0 ;
}
static int F_5 ( struct V_20 * V_21 ,
T_1 V_35 )
{
T_2 V_36 = F_6 ( V_21 , V_32 ) ;
V_36 &= ~ V_37 ;
return F_7 ( V_21 , V_32 , V_36 ) ;
}
static int F_8 ( struct V_20 * V_21 )
{
T_2 V_36 = F_6 ( V_21 , V_32 ) ;
V_36 |= V_38 ;
return F_7 ( V_21 , V_32 , V_36 ) ;
}
static int F_9 ( struct V_20 * V_21 )
{
struct V_39 * V_40 = F_10 ( V_21 ) ;
struct V_41 * V_42 = & V_21 -> V_42 ;
int V_43 = 0 ;
V_21 -> V_44 = V_40 -> V_44 ;
V_43 = F_11 ( V_21 , 4 , 12 , V_45 ) ;
if ( V_43 < 0 ) {
F_12 ( V_21 -> V_46 , L_1 ,
V_43 ) ;
return V_43 ;
}
F_7 ( V_21 , V_29 , 0x300 ) ;
F_7 ( V_21 , V_47 , 0x0 ) ;
F_7 ( V_21 , V_48 , 0x100 ) ;
F_7 ( V_21 , V_32 , 0x180 ) ;
F_7 ( V_21 , V_49 , 0x3A ) ;
F_7 ( V_21 , V_50 , 0x3FF ) ;
F_7 ( V_21 , V_51 , 0x3FF ) ;
F_7 ( V_21 , V_52 , 0x3FF ) ;
F_7 ( V_21 , V_53 , 0x3FF ) ;
F_7 ( V_21 , V_54 , 0x3FF ) ;
F_7 ( V_21 , V_55 , 0x3FF ) ;
F_13 ( V_21 , V_56 ,
F_14 ( V_56 ) ) ;
F_15 ( V_42 , V_57 ,
F_14 ( V_57 ) ) ;
F_16 ( V_42 , V_58 , F_14 ( V_58 ) ) ;
return V_43 ;
}
static int F_17 ( struct V_20 * V_21 )
{
T_2 V_36 = F_6 ( V_21 , V_32 ) ;
V_36 &= ~ V_37 ;
return F_7 ( V_21 , V_32 , V_36 ) ;
}
static int T_3 F_18 ( struct V_59 * V_60 )
{
struct V_39 * V_40 ;
int V_43 ;
V_40 = F_19 ( sizeof( struct V_39 ) , V_61 ) ;
if ( V_40 == NULL )
return - V_62 ;
F_20 ( V_60 , V_40 ) ;
V_40 -> V_44 = V_60 ;
V_40 -> V_63 = V_45 ;
V_43 = F_21 ( & V_60 -> V_46 ,
& V_64 , & V_65 , 1 ) ;
if ( V_43 < 0 )
F_22 ( V_40 ) ;
return V_43 ;
}
static int T_4 F_23 ( struct V_59 * V_60 )
{
F_24 ( & V_60 -> V_46 ) ;
F_22 ( F_25 ( V_60 ) ) ;
return 0 ;
}
static int T_5 F_26 ( void )
{
int V_43 ;
V_43 = F_27 ( & V_66 ) ;
if ( V_43 != 0 ) {
F_28 ( V_67 L_2 ,
V_43 ) ;
}
return V_43 ;
}
static void T_6 F_29 ( void )
{
F_30 ( & V_66 ) ;
}
