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
struct V_21 * V_22 = V_13 -> V_23 . V_24 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int error ;
if ( ( V_22 -> V_25 && ! V_22 -> V_26 ) ||
( ! V_22 -> V_25 && V_22 -> V_26 ) ) {
return - V_27 ;
}
error = F_13 ( V_28 , F_14 ( & V_13 -> V_23 ) ) ;
if ( error ) {
F_15 ( & V_13 -> V_23 , L_1 ) ;
return error ;
}
V_5 = F_16 ( sizeof( struct V_4 ) , V_29 ) ;
V_2 = F_17 () ;
if ( ! V_5 || ! V_2 ) {
error = - V_30 ;
goto V_31;
}
V_5 -> V_2 = V_2 ;
V_5 -> V_7 = V_22 -> V_25 ;
V_5 -> V_8 = V_22 -> V_26 ;
V_5 -> V_18 = V_22 -> V_32 ;
V_5 -> V_9 = V_22 -> V_33 ;
error = V_5 -> V_10 = F_18 ( V_13 , 0 ) ;
if ( error < 0 )
goto V_31;
V_2 -> V_34 = V_13 -> V_34 ;
V_2 -> V_35 = L_2 ;
V_2 -> V_23 . V_36 = & V_13 -> V_23 ;
F_19 ( V_2 , V_5 ) ;
V_2 -> V_37 . V_38 = V_39 ;
V_2 -> V_37 . V_40 = 0x0001 ;
V_2 -> V_37 . V_41 = 0x0001 ;
V_2 -> V_37 . V_42 = 0x0100 ;
if ( V_5 -> V_7 ) {
F_20 ( V_43 , V_2 -> V_44 ) ;
F_20 ( V_5 -> V_7 , V_2 -> V_45 ) ;
F_20 ( V_5 -> V_8 , V_2 -> V_45 ) ;
} else {
F_20 ( V_46 , V_2 -> V_44 ) ;
F_20 ( V_5 -> V_9 , V_2 -> V_47 ) ;
}
if ( V_5 -> V_18 ) {
F_20 ( V_43 , V_2 -> V_44 ) ;
F_20 ( V_5 -> V_18 , V_2 -> V_45 ) ;
}
error = F_21 ( V_5 -> V_10 , F_6 ,
0 , F_14 ( & V_13 -> V_23 ) , V_13 ) ;
if ( error ) {
F_15 ( & V_13 -> V_23 ,
L_3 ,
V_5 -> V_10 , error ) ;
goto V_31;
}
error = F_22 ( V_2 ) ;
if ( error ) {
F_15 ( & V_13 -> V_23 ,
L_4 , error ) ;
goto V_48;
}
if ( V_22 -> V_32 )
F_23 ( V_49 ) ;
if ( V_22 -> V_50 & V_51 )
F_24 ( V_22 -> V_52 & V_53 ) ;
if ( V_22 -> V_50 )
F_25 ( F_26 () |
( V_22 -> V_50 & ~ V_54 ) ) ;
F_23 ( F_27 () | V_55 | V_56 ) ;
F_25 ( F_26 () | V_54 ) ;
F_28 ( V_13 , V_5 ) ;
F_29 ( & V_13 -> V_23 , 1 ) ;
return 0 ;
V_48:
F_30 ( V_5 -> V_10 , V_13 ) ;
V_31:
F_31 ( V_2 ) ;
F_32 ( V_5 ) ;
F_33 ( V_28 ) ;
return error ;
}
static int F_34 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_7 ( V_13 ) ;
F_25 ( 0 ) ;
F_23 ( 0 ) ;
F_30 ( V_5 -> V_10 , V_13 ) ;
F_35 ( V_5 -> V_2 ) ;
F_33 ( V_28 ) ;
F_32 ( V_5 ) ;
F_28 ( V_13 , NULL ) ;
return 0 ;
}
static int F_36 ( struct V_57 * V_23 )
{
struct V_12 * V_13 = F_37 ( V_23 ) ;
struct V_4 * V_5 = F_7 ( V_13 ) ;
V_5 -> V_58 = F_26 () ;
V_5 -> V_59 = F_27 () ;
V_5 -> V_60 = F_38 () ;
if ( F_39 ( & V_13 -> V_23 ) )
F_40 ( V_5 -> V_10 ) ;
return 0 ;
}
static int F_41 ( struct V_57 * V_23 )
{
struct V_12 * V_13 = F_37 ( V_23 ) ;
struct V_4 * V_5 = F_7 ( V_13 ) ;
F_24 ( V_5 -> V_60 ) ;
F_23 ( V_5 -> V_59 ) ;
F_25 ( V_5 -> V_58 & ~ V_54 ) ;
if ( F_39 ( & V_13 -> V_23 ) )
F_42 ( V_5 -> V_10 ) ;
if ( V_5 -> V_58 & V_54 )
F_25 ( V_5 -> V_58 ) ;
return 0 ;
}
