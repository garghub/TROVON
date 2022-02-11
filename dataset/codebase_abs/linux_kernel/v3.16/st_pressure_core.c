static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_11 :
V_8 = F_3 ( V_2 , V_4 , V_5 ) ;
if ( V_8 < 0 )
goto V_12;
return V_13 ;
case V_14 :
* V_5 = 0 ;
switch ( V_4 -> type ) {
case V_15 :
* V_6 = V_10 -> V_16 -> V_17 ;
break;
case V_18 :
* V_6 = V_10 -> V_16 -> V_19 ;
break;
default:
V_8 = - V_20 ;
goto V_12;
}
return V_21 ;
case V_22 :
switch ( V_4 -> type ) {
case V_18 :
* V_5 = 425 ;
* V_6 = 10 ;
break;
default:
V_8 = - V_20 ;
goto V_12;
}
return V_23 ;
default:
return - V_20 ;
}
V_12:
return V_8 ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_26 = V_10 -> V_27 ( V_2 ) ;
int V_8 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = & V_31 ;
F_5 ( V_2 ) ;
V_8 = F_6 ( V_2 ,
F_7 ( V_32 ) ,
V_32 ) ;
if ( V_8 < 0 )
return V_8 ;
V_10 -> V_33 = V_34 ;
V_10 -> V_35 = V_10 -> V_36 -> V_37 ;
V_2 -> V_38 = V_10 -> V_36 -> V_4 ;
V_2 -> V_39 = V_10 -> V_36 -> V_40 ;
if ( V_10 -> V_36 -> V_41 . V_42 != 0 )
V_10 -> V_16 = (struct V_43 * )
& V_10 -> V_36 -> V_41 . V_44 [ 0 ] ;
V_10 -> V_45 = V_10 -> V_36 -> V_45 . V_46 [ 0 ] . V_47 ;
if ( ! V_25 && V_10 -> V_36 -> V_48 . V_42 )
V_25 =
(struct V_24 * ) & V_49 ;
V_8 = F_8 ( V_2 , V_25 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_9 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_26 > 0 ) {
V_8 = F_10 ( V_2 ,
V_50 ) ;
if ( V_8 < 0 )
goto V_51;
}
V_8 = F_11 ( V_2 ) ;
if ( V_8 )
goto V_52;
F_12 ( & V_2 -> V_53 , L_1 ,
V_2 -> V_54 ) ;
return V_8 ;
V_52:
if ( V_26 > 0 )
F_13 ( V_2 ) ;
V_51:
F_14 ( V_2 ) ;
return V_8 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
if ( V_10 -> V_27 ( V_2 ) > 0 )
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
}
