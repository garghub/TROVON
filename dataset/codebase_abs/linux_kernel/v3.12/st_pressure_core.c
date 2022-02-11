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
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_2 -> V_26 = V_27 ;
V_2 -> V_28 = & V_29 ;
V_8 = F_5 ( V_2 ,
F_6 ( V_30 ) , V_30 ) ;
if ( V_8 < 0 )
goto V_31;
V_10 -> V_32 = V_33 ;
V_10 -> V_34 = V_10 -> V_35 -> V_36 ;
V_2 -> V_37 = V_10 -> V_35 -> V_4 ;
V_2 -> V_38 = F_6 ( V_39 ) ;
V_10 -> V_16 = (struct V_40 * )
& V_10 -> V_35 -> V_41 . V_42 [ 0 ] ;
V_10 -> V_43 = V_10 -> V_35 -> V_43 . V_44 [ 0 ] . V_45 ;
if ( ! V_25 )
V_25 =
(struct V_24 * ) & V_46 ;
V_8 = F_7 ( V_2 , V_25 ) ;
if ( V_8 < 0 )
goto V_31;
if ( V_10 -> V_47 ( V_2 ) > 0 ) {
V_8 = F_8 ( V_2 ) ;
if ( V_8 < 0 )
goto V_31;
V_8 = F_9 ( V_2 ,
V_48 ) ;
if ( V_8 < 0 )
goto V_49;
}
V_8 = F_10 ( V_2 ) ;
if ( V_8 )
goto V_50;
return V_8 ;
V_50:
if ( V_10 -> V_47 ( V_2 ) > 0 )
F_11 ( V_2 ) ;
V_49:
if ( V_10 -> V_47 ( V_2 ) > 0 )
F_12 ( V_2 ) ;
V_31:
return V_8 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_10 -> V_47 ( V_2 ) > 0 ) {
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
}
}
