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
F_5 ( V_2 -> V_13 , V_14 , V_2 ) ;
F_3 ( V_2 , V_2 -> V_15 . V_16 , V_17 ) ;
F_3 ( V_2 , V_10 -> V_18 , V_19 ) ;
return F_1 ( V_2 , V_20 ,
& V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 V_8 ;
memset ( & V_8 , 0 , sizeof( struct V_4 ) ) ;
return F_1 ( V_2 , V_21 ,
& V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 V_8 ;
memset ( & V_8 , 0 , sizeof( struct V_4 ) ) ;
return F_1 ( V_2 , V_22 ,
& V_8 ) ;
}
static int F_8 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_4 V_8 ;
int V_25 ;
F_2 ( 2 , L_2 , V_24 -> V_26 ) ;
V_2 -> V_27 = V_24 -> V_28 ;
switch ( V_24 -> V_26 ) {
case V_29 :
V_25 = V_30 ;
break;
case V_31 :
V_25 = V_32 ;
break;
case V_33 :
V_25 = V_34 ;
break;
case V_35 :
V_25 = V_36 ;
break;
case V_37 :
V_25 = V_38 ;
break;
case V_39 :
V_25 = V_40 ;
break;
case V_41 :
V_25 = V_42 ;
break;
case V_43 :
V_25 = V_44 ;
break;
case V_45 :
V_25 = V_46 ;
break;
case V_47 :
V_25 = V_48 ;
break;
case V_49 :
V_25 = V_50 ;
break;
case V_51 :
V_25 = V_52 ;
break;
case V_53 :
V_25 = V_54 ;
break;
default:
V_25 = V_55 ;
}
F_3 ( V_2 , V_25 , V_56 ) ;
F_3 ( V_2 , V_24 -> V_24 . V_16 , V_17 ) ;
F_3 ( V_2 , V_24 -> V_24 . V_57 , V_19 ) ;
F_3 ( V_2 , 0 , V_58 ) ;
return F_1 ( V_2 , V_59 ,
& V_8 ) ;
}
static int F_9 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_4 V_8 ;
int V_60 = 0 ;
V_2 -> V_27 = V_24 -> V_28 ;
if ( V_24 -> V_61 != V_62 ) {
F_3 ( V_2 , V_24 -> V_63 , V_64 ) ;
V_60 = F_1 ( V_2 ,
V_65 ,
& V_8 ) ;
} else {
V_60 = - V_66 ;
}
return V_60 ;
}
struct V_67 * F_10 ( void )
{
return & V_68 ;
}
