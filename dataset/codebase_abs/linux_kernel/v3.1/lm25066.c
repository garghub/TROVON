static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
if ( V_3 > 1 )
return - V_10 ;
if ( V_3 == 1 ) {
switch ( V_4 ) {
case V_11 :
V_9 = F_4 ( V_2 , 0 ,
V_12 ) ;
if ( V_9 < 0 )
break;
switch ( V_8 -> V_13 ) {
case V_14 :
V_9 = F_5 ( V_9 * 2832 , 45400 ) ;
break;
case V_15 :
V_9 = F_5 ( V_9 * 70 , 453 ) ;
break;
case V_16 :
V_9 = F_5 ( V_9 * 725 , 2180 ) ;
break;
}
break;
default:
V_9 = - V_10 ;
break;
}
goto V_17;
}
switch ( V_4 ) {
case V_18 :
V_9 = F_4 ( V_2 , 0 , V_19 ) ;
break;
case V_20 :
V_9 = F_4 ( V_2 , 0 , V_21 ) ;
break;
case V_22 :
V_9 = F_4 ( V_2 , 0 ,
V_23 ) ;
break;
case V_24 :
V_9 = F_4 ( V_2 , 0 ,
V_25 ) ;
break;
case V_26 :
V_9 = F_4 ( V_2 , 0 , V_27 ) ;
break;
case V_28 :
V_9 = F_4 ( V_2 , 0 , V_29 ) ;
break;
case V_30 :
V_9 = F_4 ( V_2 , 0 , V_31 ) ;
break;
case V_32 :
V_9 = F_4 ( V_2 , 0 , V_33 ) ;
break;
case V_34 :
V_9 = F_4 ( V_2 , 0 , V_35 ) ;
break;
case V_36 :
V_9 = 0 ;
break;
default:
V_9 = - V_37 ;
break;
}
V_17:
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_38 )
{
int V_9 ;
if ( V_3 > 1 )
return - V_10 ;
switch ( V_4 ) {
case V_22 :
V_9 = F_7 ( V_2 , 0 ,
V_23 ,
V_38 ) ;
break;
case V_24 :
V_9 = F_7 ( V_2 , 0 ,
V_25 ,
V_38 ) ;
break;
case V_36 :
V_9 = F_8 ( V_2 , 0 , V_39 ) ;
break;
default:
V_9 = - V_37 ;
break;
}
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 , int V_3 , T_2 V_40 )
{
if ( V_3 > 1 )
return - V_10 ;
if ( V_3 == 0 )
return F_8 ( V_2 , 0 , V_40 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_41 * V_13 )
{
int V_42 ;
int V_9 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
if ( ! F_11 ( V_2 -> V_43 ,
V_44 ) )
return - V_45 ;
V_8 = F_12 ( sizeof( struct V_7 ) , V_46 ) ;
if ( ! V_8 )
return - V_47 ;
V_42 = F_13 ( V_2 , V_48 ) ;
if ( V_42 < 0 ) {
V_9 = V_42 ;
goto V_49;
}
V_8 -> V_13 = V_13 -> V_50 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_51 = 2 ;
V_6 -> V_52 [ V_53 ] = V_54 ;
V_6 -> V_52 [ V_55 ] = V_54 ;
V_6 -> V_52 [ V_56 ] = V_54 ;
V_6 -> V_52 [ V_57 ] = V_54 ;
V_6 -> V_52 [ V_58 ] = V_54 ;
V_6 -> V_59 [ V_57 ] = 16 ;
V_6 -> V_60 [ V_57 ] = 0 ;
V_6 -> V_61 [ V_57 ] = 0 ;
V_6 -> V_62 [ 0 ] = V_63 | V_64
| V_65 | V_66 | V_67
| V_68 | V_69 | V_70 ;
V_6 -> V_62 [ 1 ] = V_64 ;
V_6 -> V_71 = F_1 ;
V_6 -> V_72 = F_6 ;
V_6 -> V_73 = F_9 ;
switch ( V_13 -> V_50 ) {
case V_14 :
V_6 -> V_59 [ V_53 ] = 22070 ;
V_6 -> V_60 [ V_53 ] = 0 ;
V_6 -> V_61 [ V_53 ] = - 2 ;
V_6 -> V_59 [ V_55 ] = 22070 ;
V_6 -> V_60 [ V_55 ] = 0 ;
V_6 -> V_61 [ V_55 ] = - 2 ;
if ( V_42 & V_74 ) {
V_6 -> V_59 [ V_56 ] = 6852 ;
V_6 -> V_60 [ V_56 ] = 0 ;
V_6 -> V_61 [ V_56 ] = - 2 ;
V_6 -> V_59 [ V_58 ] = 369 ;
V_6 -> V_60 [ V_58 ] = 0 ;
V_6 -> V_61 [ V_58 ] = - 2 ;
} else {
V_6 -> V_59 [ V_56 ] = 13661 ;
V_6 -> V_60 [ V_56 ] = 0 ;
V_6 -> V_61 [ V_56 ] = - 2 ;
V_6 -> V_59 [ V_58 ] = 736 ;
V_6 -> V_60 [ V_58 ] = 0 ;
V_6 -> V_61 [ V_58 ] = - 2 ;
}
break;
case V_15 :
V_6 -> V_59 [ V_53 ] = 22075 ;
V_6 -> V_60 [ V_53 ] = 0 ;
V_6 -> V_61 [ V_53 ] = - 2 ;
V_6 -> V_59 [ V_55 ] = 22075 ;
V_6 -> V_60 [ V_55 ] = 0 ;
V_6 -> V_61 [ V_55 ] = - 2 ;
if ( V_42 & V_74 ) {
V_6 -> V_59 [ V_56 ] = 6713 ;
V_6 -> V_60 [ V_56 ] = 0 ;
V_6 -> V_61 [ V_56 ] = - 2 ;
V_6 -> V_59 [ V_58 ] = 3619 ;
V_6 -> V_60 [ V_58 ] = 0 ;
V_6 -> V_61 [ V_58 ] = - 3 ;
} else {
V_6 -> V_59 [ V_56 ] = 13426 ;
V_6 -> V_60 [ V_56 ] = 0 ;
V_6 -> V_61 [ V_56 ] = - 2 ;
V_6 -> V_59 [ V_58 ] = 7238 ;
V_6 -> V_60 [ V_58 ] = 0 ;
V_6 -> V_61 [ V_58 ] = - 3 ;
}
break;
case V_16 :
V_6 -> V_59 [ V_53 ] = 4587 ;
V_6 -> V_60 [ V_53 ] = 0 ;
V_6 -> V_61 [ V_53 ] = - 2 ;
V_6 -> V_59 [ V_55 ] = 4587 ;
V_6 -> V_60 [ V_55 ] = 0 ;
V_6 -> V_61 [ V_55 ] = - 2 ;
if ( V_42 & V_74 ) {
V_6 -> V_59 [ V_56 ] = 10753 ;
V_6 -> V_60 [ V_56 ] = 0 ;
V_6 -> V_61 [ V_56 ] = - 2 ;
V_6 -> V_59 [ V_58 ] = 1204 ;
V_6 -> V_60 [ V_58 ] = 0 ;
V_6 -> V_61 [ V_58 ] = - 3 ;
} else {
V_6 -> V_59 [ V_56 ] = 5405 ;
V_6 -> V_60 [ V_56 ] = 0 ;
V_6 -> V_61 [ V_56 ] = - 2 ;
V_6 -> V_59 [ V_58 ] = 605 ;
V_6 -> V_60 [ V_58 ] = 0 ;
V_6 -> V_61 [ V_58 ] = - 3 ;
}
break;
default:
V_9 = - V_45 ;
goto V_49;
}
V_9 = F_14 ( V_2 , V_13 , V_6 ) ;
if ( V_9 )
goto V_49;
return 0 ;
V_49:
F_15 ( V_8 ) ;
return V_9 ;
}
static int F_16 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
V_9 = F_17 ( V_2 ) ;
F_15 ( V_8 ) ;
return V_9 ;
}
static int T_3 F_18 ( void )
{
return F_19 ( & V_75 ) ;
}
static void T_4 F_20 ( void )
{
F_21 ( & V_75 ) ;
}
