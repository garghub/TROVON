static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
unsigned int V_8 ;
switch ( V_3 ) {
case V_9 :
case V_10 :
case V_11 :
V_8 = V_12 ;
break;
case V_13 :
case V_14 :
case V_15 :
V_8 = 0 ;
break;
default:
return - V_16 ;
}
F_3 ( V_7 -> V_17 , V_18 ,
V_12 , V_8 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_19 * V_20 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
unsigned int V_21 = F_5 ( V_20 ) ;
unsigned int V_22 , V_23 ;
switch ( F_5 ( V_20 ) ) {
case 32000 :
V_23 = V_24 ;
break;
case 44100 :
V_23 = V_25 ;
break;
case 48000 :
V_23 = V_26 ;
break;
default:
V_23 = V_27 ;
break;
}
V_22 = F_6 ( F_7 ( V_7 -> V_28 ) ,
V_21 * 64 * 2 ) - 1 ;
V_22 <<= V_29 ;
F_8 ( V_7 -> V_17 , V_30 , V_23 ) ;
F_3 ( V_7 -> V_17 , V_18 ,
V_31 , V_22 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
F_10 ( V_5 , & V_7 -> V_32 , NULL ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_33 ;
V_33 = F_12 ( V_2 -> V_34 , 0 ,
V_35 ,
& V_7 -> V_36 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_13 ( V_7 -> V_28 ) ;
if ( V_33 )
return V_33 ;
F_3 ( V_7 -> V_17 , V_18 ,
V_37 , V_37 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
F_3 ( V_7 -> V_17 , V_18 ,
V_37 , 0 ) ;
F_15 ( V_7 -> V_28 ) ;
}
static int F_16 ( struct V_38 * V_39 )
{
struct V_6 * V_7 ;
struct V_40 * V_41 ;
void T_1 * V_42 ;
int V_33 ;
V_7 = F_17 ( & V_39 -> V_43 , sizeof( * V_7 ) , V_44 ) ;
if ( ! V_7 )
return - V_45 ;
F_18 ( V_39 , V_7 ) ;
V_41 = F_19 ( V_39 , V_46 , 0 ) ;
V_42 = F_20 ( & V_39 -> V_43 , V_41 ) ;
if ( F_21 ( V_42 ) )
return F_22 ( V_42 ) ;
V_7 -> V_17 = F_23 ( & V_39 -> V_43 , V_42 ,
& V_47 ) ;
if ( F_21 ( V_7 -> V_17 ) )
return F_22 ( V_7 -> V_17 ) ;
V_7 -> V_48 = F_24 ( & V_39 -> V_43 , L_1 ) ;
if ( F_21 ( V_7 -> V_48 ) )
return F_22 ( V_7 -> V_48 ) ;
V_7 -> V_28 = F_24 ( & V_39 -> V_43 , L_2 ) ;
if ( F_21 ( V_7 -> V_28 ) )
return F_22 ( V_7 -> V_28 ) ;
V_33 = F_13 ( V_7 -> V_48 ) ;
if ( V_33 )
return V_33 ;
V_7 -> V_32 . V_49 = V_41 -> V_50 + V_51 ;
V_7 -> V_32 . V_52 = 4 ;
V_7 -> V_32 . V_53 = 1 ;
V_7 -> V_54 . V_55 = F_7 ( V_7 -> V_28 ) / 128 ;
V_7 -> V_54 . V_56 = 1 ;
V_7 -> V_54 . V_57 = 1 ;
V_7 -> V_54 . V_58 = 64 ;
V_7 -> V_36 . V_59 = & V_7 -> V_54 ;
V_7 -> V_36 . V_60 = 1 ;
V_33 = F_25 ( & V_39 -> V_43 , & V_61 ,
& V_62 , 1 ) ;
if ( V_33 )
goto V_63;
V_33 = F_26 ( & V_39 -> V_43 , NULL , 0 ) ;
if ( V_33 )
goto V_63;
return 0 ;
V_63:
F_15 ( V_7 -> V_48 ) ;
return V_33 ;
}
static int F_27 ( struct V_38 * V_39 )
{
struct V_6 * V_7 = F_28 ( V_39 ) ;
F_15 ( V_7 -> V_48 ) ;
return 0 ;
}
