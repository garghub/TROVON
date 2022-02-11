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
* V_5 = 0 ;
switch ( V_4 -> type ) {
case V_18 :
* V_6 = V_13 -> V_19 -> V_20 ;
break;
case V_21 :
* V_6 = V_13 -> V_19 -> V_22 ;
break;
default:
V_8 = - V_10 ;
goto V_15;
}
return V_23 ;
case V_24 :
switch ( V_4 -> type ) {
case V_21 :
* V_5 = 425 ;
* V_6 = 10 ;
break;
default:
V_8 = - V_10 ;
goto V_15;
}
return V_25 ;
case V_9 :
* V_5 = V_13 -> V_26 ;
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
int V_27 = V_13 -> V_28 ( V_2 ) ;
int V_8 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = & V_32 ;
F_9 ( & V_13 -> V_33 . V_34 ) ;
F_10 ( V_2 ) ;
V_8 = F_11 ( V_2 ,
F_12 ( V_35 ) ,
V_35 ) ;
if ( V_8 < 0 )
return V_8 ;
V_13 -> V_36 = V_37 ;
V_13 -> V_38 = V_13 -> V_39 -> V_40 ;
V_2 -> V_41 = V_13 -> V_39 -> V_4 ;
V_2 -> V_42 = V_13 -> V_39 -> V_43 ;
if ( V_13 -> V_39 -> V_44 . V_45 != 0 )
V_13 -> V_19 =
(struct V_46 * )
& V_13 -> V_39 -> V_44 . V_47 [ 0 ] ;
V_13 -> V_26 = V_13 -> V_39 -> V_26 . V_48 [ 0 ] . V_49 ;
if ( ! V_13 -> V_50 -> V_51 &&
V_13 -> V_39 -> V_52 . V_45 )
V_13 -> V_50 -> V_51 =
(struct V_53 * ) & V_54 ;
V_8 = F_13 ( V_2 , V_13 -> V_50 -> V_51 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_14 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_27 > 0 ) {
V_8 = F_15 ( V_2 ,
V_55 ) ;
if ( V_8 < 0 )
goto V_56;
}
V_8 = F_16 ( V_2 ) ;
if ( V_8 )
goto V_57;
F_17 ( & V_2 -> V_50 , L_1 ,
V_2 -> V_58 ) ;
return V_8 ;
V_57:
if ( V_27 > 0 )
F_18 ( V_2 ) ;
V_56:
F_19 ( V_2 ) ;
return V_8 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_6 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_13 -> V_28 ( V_2 ) > 0 )
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
}
