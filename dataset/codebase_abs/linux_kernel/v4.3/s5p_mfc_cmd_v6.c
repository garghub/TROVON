static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * args )
{
F_2 ( 2 , L_1 , V_3 ) ;
F_3 ( V_2 , 0x0 , V_5 ) ;
F_3 ( V_2 , V_3 , V_6 ) ;
F_3 ( V_2 , 0x1 , V_7 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 V_8 ;
struct V_9 * V_10 = V_2 -> V_11 -> V_10 -> V_12 ;
int V_13 ;
V_13 = F_5 ( V_2 -> V_14 , V_15 , V_2 ) ;
if ( V_13 )
return V_13 ;
F_3 ( V_2 , V_2 -> V_16 . V_17 , V_18 ) ;
F_3 ( V_2 , V_10 -> V_19 , V_20 ) ;
return F_1 ( V_2 , V_21 ,
& V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 V_8 ;
memset ( & V_8 , 0 , sizeof( struct V_4 ) ) ;
return F_1 ( V_2 , V_22 ,
& V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 V_8 ;
memset ( & V_8 , 0 , sizeof( struct V_4 ) ) ;
return F_1 ( V_2 , V_23 ,
& V_8 ) ;
}
static int F_8 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_4 V_8 ;
int V_26 ;
F_2 ( 2 , L_2 , V_25 -> V_27 ) ;
V_2 -> V_28 = V_25 -> V_29 ;
switch ( V_25 -> V_27 ) {
case V_30 :
V_26 = V_31 ;
break;
case V_32 :
V_26 = V_33 ;
break;
case V_34 :
V_26 = V_35 ;
break;
case V_36 :
V_26 = V_37 ;
break;
case V_38 :
V_26 = V_39 ;
break;
case V_40 :
V_26 = V_41 ;
break;
case V_42 :
V_26 = V_43 ;
break;
case V_44 :
V_26 = V_45 ;
break;
case V_46 :
V_26 = V_47 ;
break;
case V_48 :
V_26 = V_49 ;
break;
case V_50 :
V_26 = V_51 ;
break;
case V_52 :
V_26 = V_53 ;
break;
case V_54 :
V_26 = V_55 ;
break;
default:
V_26 = V_56 ;
}
F_3 ( V_2 , V_26 , V_57 ) ;
F_3 ( V_2 , V_25 -> V_25 . V_17 , V_18 ) ;
F_3 ( V_2 , V_25 -> V_25 . V_58 , V_20 ) ;
F_3 ( V_2 , 0 , V_59 ) ;
return F_1 ( V_2 , V_60 ,
& V_8 ) ;
}
static int F_9 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_4 V_8 ;
int V_13 = 0 ;
V_2 -> V_28 = V_25 -> V_29 ;
if ( V_25 -> V_61 != V_62 ) {
F_3 ( V_2 , V_25 -> V_63 , V_64 ) ;
V_13 = F_1 ( V_2 ,
V_65 ,
& V_8 ) ;
} else {
V_13 = - V_66 ;
}
return V_13 ;
}
struct V_67 * F_10 ( void )
{
return & V_68 ;
}
