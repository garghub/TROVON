static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_3 ( V_6 , V_9 ) ;
switch ( V_4 ) {
case V_10 :
F_4 ( V_8 , V_11 ) ;
V_6 -> V_12 = & V_6 -> V_13 [ V_14 ] ;
break;
case V_15 :
F_4 ( V_8 , V_16 ) ;
V_6 -> V_12 = & V_6 -> V_13 [ V_17 ] ;
break;
case V_18 :
F_4 ( V_8 , V_19 ) ;
V_6 -> V_12 = & V_6 -> V_13 [ V_20 ] ;
break;
default:
return - V_21 ;
}
V_8 -> V_22 . V_23 . V_24 = V_25 ;
memcpy ( V_8 -> V_22 . V_26 . V_27 , V_3 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_30 * V_32 ,
unsigned int V_33 ,
int V_34 )
{
struct V_5 * V_6 = F_6 ( V_29 -> V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_35 ;
if ( V_33 > V_6 -> V_12 -> V_36 )
return - V_21 ;
if ( V_34 )
F_7 ( V_8 ) |= V_37 ;
else
F_7 ( V_8 ) &= ~ V_37 ;
V_35 = F_8 ( V_6 , V_29 , V_31 , V_32 , V_33 ,
V_8 -> V_22 . V_26 . V_38 ) ;
if ( V_35 )
goto V_39;
if ( ! V_6 -> V_40 . V_41 || ! V_6 -> V_40 . V_42 ) {
V_35 = - V_21 ;
goto V_39;
}
V_35 = F_9 ( V_6 , & V_6 -> V_40 ,
V_29 -> V_43 & V_44 ) ;
if ( V_35 )
goto V_39;
F_10 ( & ( V_6 -> V_45 -> V_46 ) ) ;
F_11 ( V_8 -> V_47 . V_48 ,
& ( V_6 -> V_45 -> V_49 ) ) ;
V_39:
return V_35 ;
}
static int F_12 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_30 * V_32 ,
unsigned int V_33 )
{
return F_5 ( V_29 , V_31 , V_32 , V_33 , 1 ) ;
}
static int F_13 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_30 * V_32 ,
unsigned int V_33 )
{
return F_5 ( V_29 , V_31 , V_32 , V_33 , 0 ) ;
}
