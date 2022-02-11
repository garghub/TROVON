static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 , 1 ) ;
F_3 ( V_2 ) ;
F_2 ( V_2 , V_3 , 0 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_4 * V_5 , int V_6 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_5 -> V_7 ) {
F_1 ( V_2 ,
V_6 > 0 ? V_5 -> V_7 : V_5 -> V_8 ) ;
} else {
F_5 ( V_2 , V_5 -> V_9 , V_6 ) ;
F_3 ( V_2 ) ;
}
}
static T_1 F_6 ( int V_10 , void * V_11 )
{
struct V_12 * V_13 = V_11 ;
struct V_4 * V_5 = F_7 ( V_13 ) ;
int V_6 ;
switch ( F_8 () ) {
case V_14 :
break;
case V_15 :
case V_16 :
V_6 = F_9 () ;
if ( V_6 )
F_4 ( V_5 , V_6 ) ;
break;
case V_17 :
F_1 ( V_5 -> V_2 , V_5 -> V_18 ) ;
break;
default:
break;
}
F_10 ( V_19 ) ;
F_11 ( - 1 ) ;
return V_20 ;
}
static int F_12 ( struct V_12 * V_13 )
{
struct V_21 * V_22 = F_13 ( & V_13 -> V_23 ) ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int error ;
if ( ( V_22 -> V_24 && ! V_22 -> V_25 ) ||
( ! V_22 -> V_24 && V_22 -> V_25 ) ) {
return - V_26 ;
}
error = F_14 ( V_27 , F_15 ( & V_13 -> V_23 ) ) ;
if ( error ) {
F_16 ( & V_13 -> V_23 , L_1 ) ;
return error ;
}
V_5 = F_17 ( sizeof( struct V_4 ) , V_28 ) ;
V_2 = F_18 () ;
if ( ! V_5 || ! V_2 ) {
error = - V_29 ;
goto V_30;
}
V_5 -> V_2 = V_2 ;
V_5 -> V_7 = V_22 -> V_24 ;
V_5 -> V_8 = V_22 -> V_25 ;
V_5 -> V_18 = V_22 -> V_31 ;
V_5 -> V_9 = V_22 -> V_32 ;
error = V_5 -> V_10 = F_19 ( V_13 , 0 ) ;
if ( error < 0 )
goto V_30;
V_2 -> V_33 = V_13 -> V_33 ;
V_2 -> V_34 = L_2 ;
V_2 -> V_23 . V_35 = & V_13 -> V_23 ;
F_20 ( V_2 , V_5 ) ;
V_2 -> V_36 . V_37 = V_38 ;
V_2 -> V_36 . V_39 = 0x0001 ;
V_2 -> V_36 . V_40 = 0x0001 ;
V_2 -> V_36 . V_41 = 0x0100 ;
if ( V_5 -> V_7 ) {
F_21 ( V_42 , V_2 -> V_43 ) ;
F_21 ( V_5 -> V_7 , V_2 -> V_44 ) ;
F_21 ( V_5 -> V_8 , V_2 -> V_44 ) ;
} else {
F_21 ( V_45 , V_2 -> V_43 ) ;
F_21 ( V_5 -> V_9 , V_2 -> V_46 ) ;
}
if ( V_5 -> V_18 ) {
F_21 ( V_42 , V_2 -> V_43 ) ;
F_21 ( V_5 -> V_18 , V_2 -> V_44 ) ;
}
error = F_22 ( V_5 -> V_10 , F_6 ,
0 , F_15 ( & V_13 -> V_23 ) , V_13 ) ;
if ( error ) {
F_16 ( & V_13 -> V_23 ,
L_3 ,
V_5 -> V_10 , error ) ;
goto V_30;
}
error = F_23 ( V_2 ) ;
if ( error ) {
F_16 ( & V_13 -> V_23 ,
L_4 , error ) ;
goto V_47;
}
if ( V_22 -> V_31 )
F_24 ( V_48 ) ;
if ( V_22 -> V_49 & V_50 )
F_25 ( V_22 -> V_51 & V_52 ) ;
if ( V_22 -> V_49 )
F_26 ( F_27 () |
( V_22 -> V_49 & ~ V_53 ) ) ;
F_24 ( F_28 () | V_54 | V_55 ) ;
F_26 ( F_27 () | V_53 ) ;
F_29 ( V_13 , V_5 ) ;
F_30 ( & V_13 -> V_23 , 1 ) ;
return 0 ;
V_47:
F_31 ( V_5 -> V_10 , V_13 ) ;
V_30:
F_32 ( V_2 ) ;
F_33 ( V_5 ) ;
F_34 ( V_27 ) ;
return error ;
}
static int F_35 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_7 ( V_13 ) ;
F_26 ( 0 ) ;
F_24 ( 0 ) ;
F_31 ( V_5 -> V_10 , V_13 ) ;
F_36 ( V_5 -> V_2 ) ;
F_34 ( V_27 ) ;
F_33 ( V_5 ) ;
return 0 ;
}
static int F_37 ( struct V_56 * V_23 )
{
struct V_12 * V_13 = F_38 ( V_23 ) ;
struct V_4 * V_5 = F_7 ( V_13 ) ;
V_5 -> V_57 = F_27 () ;
V_5 -> V_58 = F_28 () ;
V_5 -> V_59 = F_39 () ;
if ( F_40 ( & V_13 -> V_23 ) )
F_41 ( V_5 -> V_10 ) ;
return 0 ;
}
static int F_42 ( struct V_56 * V_23 )
{
struct V_12 * V_13 = F_38 ( V_23 ) ;
struct V_4 * V_5 = F_7 ( V_13 ) ;
F_25 ( V_5 -> V_59 ) ;
F_24 ( V_5 -> V_58 ) ;
F_26 ( V_5 -> V_57 & ~ V_53 ) ;
if ( F_40 ( & V_13 -> V_23 ) )
F_43 ( V_5 -> V_10 ) ;
if ( V_5 -> V_57 & V_53 )
F_26 ( V_5 -> V_57 ) ;
return 0 ;
}
