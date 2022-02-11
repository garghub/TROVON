static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
switch ( V_7 ) {
case V_11 :
V_10 = F_3 ( V_9 -> V_12 , V_13 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_5 = ( V_10 & 0xFFF ) >> ( 12 - V_9 -> V_14 ) ;
return V_15 ;
case V_16 :
V_10 = F_4 ( V_9 -> V_17 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_5 = V_10 / 1000 ;
* V_6 = V_9 -> V_14 ;
return V_18 ;
default:
break;
}
return - V_19 ;
}
static T_1 F_5 ( int V_20 , void * V_21 )
{
struct V_22 * V_23 = V_21 ;
struct V_1 * V_24 = V_23 -> V_24 ;
struct V_8 * V_25 = F_2 ( V_24 ) ;
T_2 V_26 [ 8 ] ;
int V_27 ;
V_27 = F_3 ( V_25 -> V_12 , V_13 ) ;
if ( V_27 < 0 )
goto V_28;
V_26 [ 0 ] = V_27 ;
F_6 ( V_24 , V_26 ,
F_7 ( V_24 ) ) ;
V_28:
F_8 ( V_24 -> V_29 ) ;
return V_30 ;
}
static int F_9 ( struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_35 * V_36 ;
int V_10 ;
if ( ! F_10 ( V_32 -> V_37 , V_38 ) )
return - V_39 ;
if ( F_11 ( & V_32 -> V_40 ) ) {
const struct V_41 * V_42 ;
V_42 = F_12 ( V_32 -> V_40 . V_43 -> V_44 ,
& V_32 -> V_40 ) ;
if ( ! V_42 )
return - V_45 ;
V_36 = & V_46 [ V_42 -> V_47 ] ;
} else {
V_36 = & V_46 [ V_34 -> V_47 ] ;
}
V_2 = F_13 ( & V_32 -> V_40 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_48 ;
V_9 = F_2 ( V_2 ) ;
V_9 -> V_12 = V_32 ;
V_9 -> V_14 = V_36 -> V_14 ;
V_9 -> V_17 = F_14 ( & V_32 -> V_40 , L_1 ) ;
if ( F_15 ( V_9 -> V_17 ) )
return F_16 ( V_9 -> V_17 ) ;
V_10 = F_17 ( V_9 -> V_17 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_40 . V_49 = & V_32 -> V_40 ;
V_2 -> V_40 . V_50 = V_32 -> V_40 . V_50 ;
V_2 -> V_51 = F_18 ( & V_32 -> V_40 ) ;
V_2 -> V_52 = V_53 ;
V_2 -> V_54 = & V_55 ;
V_2 -> V_56 = V_36 -> V_56 ;
V_2 -> V_57 = V_58 ;
V_10 = F_19 ( V_2 , NULL , F_5 , NULL ) ;
if ( V_10 < 0 ) {
F_20 ( & V_32 -> V_40 , L_2 ) ;
goto V_59;
}
V_10 = F_21 ( V_2 ) ;
if ( V_10 < 0 )
goto V_60;
F_22 ( V_32 , V_2 ) ;
return 0 ;
V_60:
F_23 ( V_2 ) ;
V_59:
F_24 ( V_9 -> V_17 ) ;
return V_10 ;
}
static int F_25 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_26 ( V_32 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_27 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_9 -> V_17 ) ;
return 0 ;
}
