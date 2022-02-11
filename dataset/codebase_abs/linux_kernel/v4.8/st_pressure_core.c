static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 ,
int V_6 ,
long V_7 )
{
int V_8 ;
switch ( V_7 ) {
case V_9 :
if ( V_6 )
return - V_10 ;
F_2 ( & V_2 -> V_11 ) ;
V_8 = F_3 ( V_2 , V_5 ) ;
F_4 ( & V_2 -> V_11 ) ;
return V_8 ;
default:
return - V_10 ;
}
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
int V_8 ;
struct V_12 * V_13 = F_6 ( V_2 ) ;
switch ( V_7 ) {
case V_14 :
V_8 = F_7 ( V_2 , V_4 , V_5 ) ;
if ( V_8 < 0 )
goto V_15;
return V_16 ;
case V_17 :
switch ( V_4 -> type ) {
case V_18 :
* V_5 = 0 ;
* V_6 = V_13 -> V_19 -> V_20 ;
return V_21 ;
case V_22 :
* V_5 = V_23 ;
* V_6 = V_13 -> V_19 -> V_24 ;
return V_25 ;
default:
V_8 = - V_10 ;
goto V_15;
}
case V_26 :
switch ( V_4 -> type ) {
case V_22 :
* V_5 = V_27 *
V_13 -> V_19 -> V_24 ;
* V_6 = V_23 ;
break;
default:
V_8 = - V_10 ;
goto V_15;
}
return V_25 ;
case V_9 :
* V_5 = V_13 -> V_28 ;
return V_16 ;
default:
return - V_10 ;
}
V_15:
return V_8 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_6 ( V_2 ) ;
int V_29 = V_13 -> V_30 ( V_2 ) ;
int V_8 ;
V_2 -> V_31 = V_32 ;
V_2 -> V_33 = & V_34 ;
F_9 ( & V_13 -> V_35 . V_36 ) ;
V_8 = F_10 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_11 ( V_2 ,
F_12 ( V_37 ) ,
V_37 ) ;
if ( V_8 < 0 )
goto V_38;
V_13 -> V_39 = V_13 -> V_40 -> V_41 - 1 ;
V_13 -> V_42 = V_13 -> V_40 -> V_43 ;
V_2 -> V_44 = V_13 -> V_40 -> V_4 ;
V_2 -> V_45 = V_13 -> V_40 -> V_41 ;
V_13 -> V_19 =
(struct V_46 * )
& V_13 -> V_40 -> V_47 . V_48 [ 0 ] ;
V_13 -> V_28 = V_13 -> V_40 -> V_28 . V_49 [ 0 ] . V_50 ;
if ( ! V_13 -> V_51 -> V_52 &&
V_13 -> V_40 -> V_53 . V_54 )
V_13 -> V_51 -> V_52 =
(struct V_55 * ) & V_56 ;
V_8 = F_13 ( V_2 , V_13 -> V_51 -> V_52 ) ;
if ( V_8 < 0 )
goto V_38;
V_8 = F_14 ( V_2 ) ;
if ( V_8 < 0 )
goto V_38;
if ( V_29 > 0 ) {
V_8 = F_15 ( V_2 ,
V_57 ) ;
if ( V_8 < 0 )
goto V_58;
}
V_8 = F_16 ( V_2 ) ;
if ( V_8 )
goto V_59;
F_17 ( & V_2 -> V_51 , L_1 ,
V_2 -> V_60 ) ;
return V_8 ;
V_59:
if ( V_29 > 0 )
F_18 ( V_2 ) ;
V_58:
F_19 ( V_2 ) ;
V_38:
F_20 ( V_2 ) ;
return V_8 ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_6 ( V_2 ) ;
F_20 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_13 -> V_30 ( V_2 ) > 0 )
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
}
