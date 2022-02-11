static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 ,
enum V_9 V_10 , union V_11 * V_12 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
unsigned int V_13 , V_14 ;
int V_15 ;
switch ( V_10 ) {
case V_16 :
V_15 = F_5 ( V_4 -> V_17 , V_18 , & V_14 ) ;
if ( V_15 )
return V_15 ;
V_12 -> V_19 = F_6 ( V_14 ) ;
return 0 ;
case V_20 :
V_15 = F_7 ( V_4 -> V_17 ,
V_21 , 12 ) ;
if ( V_15 < 0 )
return V_15 ;
V_12 -> V_19 = V_15 * 1700 ;
return 0 ;
case V_22 :
V_15 = F_5 ( V_4 -> V_17 , V_18 , & V_14 ) ;
if ( V_15 )
return V_15 ;
switch ( V_14 & V_23 ) {
case V_24 :
V_12 -> V_19 = 100000 ;
break;
case V_25 :
V_12 -> V_19 = 500000 ;
break;
case V_26 :
V_12 -> V_19 = 900000 ;
break;
case V_27 :
V_12 -> V_19 = - 1 ;
break;
}
return 0 ;
case V_28 :
V_15 = F_7 ( V_4 -> V_17 ,
V_29 , 12 ) ;
if ( V_15 < 0 )
return V_15 ;
V_12 -> V_19 = V_15 * 375 ;
return 0 ;
default:
break;
}
V_15 = F_5 ( V_4 -> V_17 , V_30 , & V_13 ) ;
if ( V_15 )
return V_15 ;
switch ( V_10 ) {
case V_31 :
if ( ! ( V_13 & V_32 ) ) {
V_12 -> V_19 = V_33 ;
break;
}
V_15 = F_5 ( V_4 -> V_17 , V_34 , & V_14 ) ;
if ( V_15 )
return V_15 ;
if ( ! ( V_14 & V_35 ) ) {
V_12 -> V_19 = V_36 ;
break;
}
V_12 -> V_19 = V_37 ;
break;
case V_38 :
V_12 -> V_19 = ! ! ( V_13 & V_32 ) ;
break;
case V_39 :
V_12 -> V_19 = ! ! ( V_13 & V_40 ) ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_8 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = F_9 ( V_43 -> V_46 . V_47 ) ;
struct V_48 V_49 = {} ;
struct V_3 * V_4 ;
static const char * const V_50 [] = { L_1 ,
L_2 , L_3 , L_4 } ;
int V_51 , V_1 , V_15 ;
if ( ! F_10 ( V_43 -> V_46 . V_52 ) )
return - V_53 ;
if ( ! V_45 ) {
F_11 ( & V_43 -> V_46 , L_5 ) ;
return - V_41 ;
}
V_4 = F_12 ( & V_43 -> V_46 , sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 )
return - V_55 ;
V_4 -> V_17 = V_45 -> V_17 ;
V_15 = F_13 ( V_4 -> V_17 , V_56 ,
V_57 , V_57 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_13 ( V_4 -> V_17 , V_58 ,
V_59 | V_60 ,
V_59 | V_60 ) ;
if ( V_15 )
return V_15 ;
V_49 . V_52 = V_43 -> V_46 . V_52 ;
V_49 . V_61 = V_4 ;
V_4 -> V_5 = F_14 ( & V_43 -> V_46 ,
& V_62 , & V_49 ) ;
if ( F_15 ( V_4 -> V_5 ) )
return F_16 ( V_4 -> V_5 ) ;
for ( V_51 = 0 ; V_51 < F_17 ( V_50 ) ; V_51 ++ ) {
V_1 = F_18 ( V_43 , V_50 [ V_51 ] ) ;
if ( V_1 < 0 ) {
F_19 ( & V_43 -> V_46 , L_6 ,
V_50 [ V_51 ] , V_1 ) ;
continue;
}
V_1 = F_20 ( V_45 -> V_63 , V_1 ) ;
V_15 = F_21 ( & V_43 -> V_46 , V_1 ,
F_1 , 0 , V_64 , V_4 ) ;
if ( V_15 < 0 )
F_19 ( & V_43 -> V_46 , L_7 ,
V_50 [ V_51 ] , V_15 ) ;
}
return 0 ;
}
