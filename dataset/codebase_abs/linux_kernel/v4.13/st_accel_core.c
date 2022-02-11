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
* V_5 = V_10 -> V_15 -> V_16 / 1000000 ;
* V_6 = V_10 -> V_15 -> V_16 % 1000000 ;
return V_17 ;
case V_18 :
* V_5 = V_10 -> V_19 ;
return V_13 ;
default:
return - V_20 ;
}
V_12:
return V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_21 , int V_5 , int V_6 , long V_7 )
{
int V_8 ;
switch ( V_7 ) {
case V_14 : {
int V_16 ;
V_16 = V_5 * 1000000 + V_6 ;
V_8 = F_5 ( V_2 , V_16 ) ;
break;
}
case V_18 :
if ( V_6 )
return - V_20 ;
F_6 ( & V_2 -> V_22 ) ;
V_8 = F_7 ( V_2 , V_5 ) ;
F_8 ( & V_2 -> V_22 ) ;
return V_8 ;
default:
return - V_20 ;
}
return V_8 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_23 * V_24 =
(struct V_23 * ) V_10 -> V_25 -> V_26 ;
int V_27 = V_10 -> V_28 ( V_2 ) ;
int V_8 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = & V_32 ;
F_10 ( & V_10 -> V_33 . V_34 ) ;
V_8 = F_11 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_12 ( V_2 ,
F_13 ( V_35 ) ,
V_35 ) ;
if ( V_8 < 0 )
goto V_36;
V_10 -> V_37 = V_38 ;
V_10 -> V_39 = V_10 -> V_40 -> V_41 ;
V_2 -> V_42 = V_10 -> V_40 -> V_4 ;
V_2 -> V_43 = V_44 ;
V_10 -> V_15 = (struct V_45 * )
& V_10 -> V_40 -> V_46 . V_47 [ 0 ] ;
V_10 -> V_19 = V_10 -> V_40 -> V_19 . V_48 [ 0 ] . V_49 ;
if ( ! V_24 )
V_24 = (struct V_23 * ) & V_50 ;
V_8 = F_14 ( V_2 , V_10 -> V_25 -> V_26 ) ;
if ( V_8 < 0 )
goto V_36;
V_8 = F_15 ( V_2 ) ;
if ( V_8 < 0 )
goto V_36;
if ( V_27 > 0 ) {
V_8 = F_16 ( V_2 ,
V_51 ) ;
if ( V_8 < 0 )
goto V_52;
}
V_8 = F_17 ( V_2 ) ;
if ( V_8 )
goto V_53;
F_18 ( & V_2 -> V_25 , L_1 ,
V_2 -> V_54 ) ;
return 0 ;
V_53:
if ( V_27 > 0 )
F_19 ( V_2 ) ;
V_52:
F_20 ( V_2 ) ;
V_36:
F_21 ( V_2 ) ;
return V_8 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( V_10 -> V_28 ( V_2 ) > 0 )
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
}
