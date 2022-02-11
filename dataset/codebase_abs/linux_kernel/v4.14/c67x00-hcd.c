static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_7 ;
F_2 ( V_2 , V_3 ) ;
F_3 ( & V_5 -> V_8 , V_7 ) ;
F_4 ( V_2 , V_3 ) ;
F_5 ( & V_5 -> V_8 , V_7 ) ;
F_6 ( V_2 -> V_9 , V_10 ) ;
}
static int F_7 ( struct V_11 * V_12 , char * V_13 )
{
struct V_4 * V_5 = F_8 ( V_12 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
T_1 V_14 ;
int V_15 ;
* V_13 = 0 ;
V_14 = F_9 ( V_2 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
if ( V_14 & F_10 ( V_15 ) )
* V_13 |= ( 1 << V_15 ) ;
* V_13 <<= 1 ;
return ! ! * V_13 ;
}
static int F_11 ( struct V_11 * V_12 , T_1 V_17 , T_1 V_18 ,
T_1 V_19 , char * V_13 , T_1 V_20 )
{
struct V_4 * V_5 = F_8 ( V_12 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
T_1 V_14 , V_21 ;
int V_22 = 0 ;
unsigned int V_3 = V_19 - 1 ;
T_1 V_23 , V_24 ;
switch ( V_17 ) {
case V_25 :
* ( V_26 * ) V_13 = F_12 ( 0 ) ;
V_22 = 4 ;
break;
case V_27 :
if ( V_19 > V_16 )
return - V_28 ;
V_14 = F_9 ( V_2 ) ;
V_21 = F_13 ( V_2 ) ;
V_23 = 0 ;
if ( V_14 & F_10 ( V_3 ) )
V_23 |= V_29 ;
V_24 = V_30 ;
if ( ! ( V_14 & F_14 ( V_3 ) ) )
V_24 |= V_31 ;
if ( V_21 & F_15 ( V_3 ) ) {
V_24 |= V_32 ;
V_5 -> V_33 |= ( 1 << V_3 ) ;
} else
V_5 -> V_33 &= ~ ( 1 << V_3 ) ;
if ( V_21 & F_16 ( V_3 ) )
V_24 |= V_34 ;
* ( V_35 * ) V_13 = F_17 ( V_24 ) ;
* ( V_35 * ) ( V_13 + 2 ) = F_17 ( V_23 ) ;
V_22 = 4 ;
break;
case V_36 :
case V_37 :
switch ( V_18 ) {
case V_38 :
case V_39 :
V_22 = 0 ;
break;
default:
return - V_28 ;
}
break;
case V_40 :
if ( V_19 > V_16 )
return - V_28 ;
switch ( V_18 ) {
case V_41 :
F_18 ( F_19 ( V_5 ) ,
L_1 , V_3 ) ;
V_22 = 0 ;
break;
case V_42 :
F_1 ( V_2 , V_3 ) ;
V_22 = 0 ;
break;
case V_43 :
V_22 = 0 ;
break;
default:
F_18 ( F_19 ( V_5 ) ,
L_2 ,
V_44 , V_3 , V_18 ) ;
return - V_28 ;
}
break;
case V_45 :
if ( V_19 > V_16 )
return - V_28 ;
switch ( V_18 ) {
case V_46 :
F_1 ( V_2 , V_3 ) ;
V_22 = 0 ;
break;
case V_47 :
F_18 ( F_19 ( V_5 ) ,
L_3 , V_3 ) ;
V_22 = 0 ;
break;
case V_41 :
F_18 ( F_19 ( V_5 ) ,
L_4 , V_3 ) ;
V_22 = 0 ;
break;
case V_48 :
F_18 ( F_19 ( V_5 ) ,
L_5 , V_3 ) ;
V_22 = 0 ;
break;
case V_43 :
F_18 ( F_19 ( V_5 ) ,
L_6 , V_3 ) ;
return - V_28 ;
case V_49 :
F_20 ( V_2 ,
F_10 ( V_3 ) ) ;
V_22 = 0 ;
break;
case V_50 :
F_18 ( F_19 ( V_5 ) ,
L_7 , V_3 ) ;
V_22 = 0 ;
break;
case V_51 :
F_18 ( F_19 ( V_5 ) ,
L_8 , V_3 ) ;
V_22 = 0 ;
break;
default:
F_18 ( F_19 ( V_5 ) ,
L_9 ,
V_44 , V_3 , V_18 ) ;
return - V_28 ;
}
break;
case V_52 :
V_22 = F_21 (unsigned int, sizeof(c67x00_hub_des), wLength) ;
memcpy ( V_13 , V_53 , V_22 ) ;
break;
default:
F_18 ( F_19 ( V_5 ) , L_10 , V_44 ) ;
return - V_28 ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_54 , T_1 V_55 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_11 * V_12 = F_23 ( V_5 ) ;
if ( V_55 ) {
if ( V_55 & V_56 )
F_24 ( V_5 ) ;
else
F_25 ( F_19 ( V_5 ) ,
L_11 , V_55 ) ;
}
if ( F_26 ( V_12 -> V_57 == V_58 ) )
return;
if ( ! F_27 ( V_12 ) )
return;
if ( V_54 & F_28 ( V_2 -> V_59 ) ) {
F_20 ( V_2 , V_60 ) ;
F_24 ( V_5 ) ;
}
}
static int F_29 ( struct V_11 * V_12 )
{
V_12 -> V_61 = 1 ;
V_12 -> V_57 = V_62 ;
F_30 ( V_63 , & V_12 -> V_7 ) ;
return 0 ;
}
static void F_31 ( struct V_11 * V_12 )
{
}
static int F_32 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = F_8 ( V_12 ) ;
T_1 V_64 ;
F_18 ( F_19 ( V_5 ) , L_12 , V_44 ) ;
V_64 = F_33 ( V_5 -> V_2 ) ;
V_64 &= V_65 ;
return V_64 ? ( V_64 - 1 ) : V_65 ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_11 * V_12 ;
unsigned long V_7 ;
int V_66 ;
if ( F_35 () )
return - V_67 ;
V_12 = F_36 ( & V_68 , F_37 ( V_2 ) , L_13 ) ;
if ( ! V_12 ) {
V_66 = - V_69 ;
goto V_70;
}
V_5 = F_8 ( V_12 ) ;
F_38 ( & V_5 -> V_8 ) ;
V_5 -> V_2 = V_2 ;
F_39 ( & V_5 -> V_71 [ V_72 ] ) ;
F_39 ( & V_5 -> V_71 [ V_73 ] ) ;
F_39 ( & V_5 -> V_71 [ V_74 ] ) ;
F_39 ( & V_5 -> V_71 [ V_75 ] ) ;
V_5 -> V_76 = 0 ;
F_39 ( & V_5 -> V_77 ) ;
V_5 -> V_78 = V_79 + F_40 ( V_2 -> V_59 ) ;
V_5 -> V_80 = V_79 + F_41 ( V_2 -> V_59 ) ;
V_5 -> V_81 = V_82 ;
F_42 ( V_2 ) ;
F_43 ( & V_5 -> V_83 ) ;
V_66 = F_44 ( V_5 ) ;
if ( V_66 )
goto V_84;
V_66 = F_45 ( V_12 , 0 , 0 ) ;
if ( V_66 ) {
F_18 ( F_37 ( V_2 ) , L_14 ,
V_44 , V_66 ) ;
goto V_85;
}
F_46 ( V_12 -> V_86 . V_87 ) ;
F_3 ( & V_2 -> V_8 , V_7 ) ;
V_2 -> V_6 = V_5 ;
V_2 -> V_88 = F_22 ;
F_5 ( & V_2 -> V_8 , V_7 ) ;
return V_66 ;
V_85:
F_47 ( V_5 ) ;
V_84:
F_48 ( V_12 ) ;
V_70:
return V_66 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_11 * V_12 = F_23 ( V_5 ) ;
F_47 ( V_5 ) ;
F_50 ( V_12 ) ;
F_48 ( V_12 ) ;
}
