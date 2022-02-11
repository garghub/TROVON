static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_2 V_7 [ V_8 ] ;
int V_9 ;
int V_10 ;
int V_11 ;
V_9 = F_2 ( V_6 , V_12 ,
V_8 , V_7 ) ;
if ( V_9 < 0 ) {
F_3 ( & V_6 -> V_13 , L_1 , V_14 , V_9 ) ;
goto V_15;
}
switch ( V_7 [ V_16 ] ) {
case V_17 :
F_4 ( V_4 -> V_18 , V_19 , 0 ) ;
F_5 ( V_4 -> V_18 ) ;
break;
case V_20 :
V_10 = ( V_7 [ V_21 ] << 8 ) | V_7 [ V_22 ] ;
V_11 = ( V_7 [ V_23 ] << 8 ) | V_7 [ V_24 ] ;
F_4 ( V_4 -> V_18 , V_19 , 1 ) ;
F_6 ( V_4 -> V_18 , V_25 , V_10 ) ;
F_6 ( V_4 -> V_18 , V_26 , V_11 ) ;
F_5 ( V_4 -> V_18 ) ;
break;
case V_27 :
break;
case V_28 :
break;
case V_29 :
break;
default:
F_3 ( & V_6 -> V_13 , L_2 ,
V_7 [ V_16 ] ) ;
break;
}
V_15:
return V_30 ;
}
static void F_7 ( struct V_3 * V_4 ,
const struct V_31 * V_32 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
F_8 ( V_6 , V_33 ,
V_34 | V_35 ) ;
F_8 ( V_6 , V_36 ,
V_32 -> V_37 >> 8 ) ;
F_8 ( V_6 , V_38 ,
V_32 -> V_37 & 0xff ) ;
F_8 ( V_6 , V_39 ,
V_32 -> V_40 >> 8 ) ;
F_8 ( V_6 , V_41 ,
V_32 -> V_40 & 0xff ) ;
F_8 ( V_4 -> V_6 , V_33 ,
V_42 | V_43 ) ;
}
static int F_9 ( struct V_5 * V_6 ,
const struct V_44 * V_45 )
{
const struct V_31 * V_46 ;
struct V_3 * V_4 ;
struct V_18 * V_18 ;
int error ;
V_46 = F_10 ( & V_6 -> V_13 ) ;
if ( ! V_46 )
return - V_47 ;
V_4 = F_11 ( & V_6 -> V_13 , sizeof( * V_4 ) , V_48 ) ;
if ( ! V_4 ) {
F_3 ( & V_6 -> V_13 , L_3 ) ;
return - V_49 ;
}
V_4 -> V_6 = V_6 ;
V_18 = F_12 ( & V_6 -> V_13 ) ;
if ( ! V_18 ) {
F_3 ( & V_6 -> V_13 , L_4 ) ;
return - V_49 ;
}
V_18 -> V_50 = L_5 ;
V_18 -> V_45 . V_51 = V_52 ;
V_18 -> V_13 . V_53 = & V_6 -> V_13 ;
F_13 ( V_54 , V_18 -> V_55 ) ;
F_13 ( V_56 , V_18 -> V_55 ) ;
F_13 ( V_19 , V_18 -> V_57 ) ;
F_14 ( V_18 , V_25 , 0 , V_58 , 0 , 0 ) ;
F_14 ( V_18 , V_26 , 0 , V_59 , 0 , 0 ) ;
F_15 ( V_18 , V_4 ) ;
V_4 -> V_18 = V_18 ;
if ( V_46 -> V_60 )
V_46 -> V_60 () ;
error = F_16 ( & V_6 -> V_13 , V_6 -> V_1 ,
NULL , F_1 ,
V_61 | V_62 ,
L_6 , V_4 ) ;
if ( error ) {
F_3 ( & V_6 -> V_13 , L_7 ) ;
return error ;
}
error = F_17 ( V_4 -> V_18 ) ;
if ( error ) {
F_3 ( & V_6 -> V_13 , L_8 ) ;
return error ;
}
F_7 ( V_4 , V_46 ) ;
F_18 ( V_6 , V_4 ) ;
return 0 ;
}
static int T_3 F_19 ( struct V_63 * V_13 )
{
struct V_5 * V_6 = F_20 ( V_13 ) ;
F_8 ( V_6 , V_33 , V_35 ) ;
return 0 ;
}
static int T_3 F_21 ( struct V_63 * V_13 )
{
struct V_5 * V_6 = F_20 ( V_13 ) ;
struct V_3 * V_4 = F_22 ( V_6 ) ;
const struct V_31 * V_46 = F_10 ( V_13 ) ;
F_7 ( V_4 , V_46 ) ;
return 0 ;
}
