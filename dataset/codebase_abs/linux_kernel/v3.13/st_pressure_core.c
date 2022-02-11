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
static void F_4 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_8 ;
V_10 -> V_24 = F_5 ( & V_2 -> V_25 , L_1 ) ;
if ( ! F_6 ( V_10 -> V_24 ) ) {
V_8 = F_7 ( V_10 -> V_24 ) ;
if ( V_8 != 0 )
F_8 ( & V_2 -> V_25 ,
L_2 ) ;
}
V_10 -> V_26 = F_5 ( & V_2 -> V_25 , L_3 ) ;
if ( ! F_6 ( V_10 -> V_26 ) ) {
V_8 = F_7 ( V_10 -> V_26 ) ;
if ( V_8 != 0 )
F_8 ( & V_2 -> V_25 ,
L_4 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! F_6 ( V_10 -> V_24 ) )
F_10 ( V_10 -> V_24 ) ;
if ( ! F_6 ( V_10 -> V_26 ) )
F_10 ( V_10 -> V_26 ) ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_29 = V_10 -> V_30 ( V_2 ) ;
int V_8 ;
V_2 -> V_31 = V_32 ;
V_2 -> V_33 = & V_34 ;
F_4 ( V_2 ) ;
V_8 = F_12 ( V_2 ,
F_13 ( V_35 ) ,
V_35 ) ;
if ( V_8 < 0 )
return V_8 ;
V_10 -> V_36 = V_37 ;
V_10 -> V_38 = V_10 -> V_39 -> V_40 ;
V_2 -> V_41 = V_10 -> V_39 -> V_4 ;
V_2 -> V_42 = V_10 -> V_39 -> V_43 ;
if ( V_10 -> V_39 -> V_44 . V_45 != 0 )
V_10 -> V_16 = (struct V_46 * )
& V_10 -> V_39 -> V_44 . V_47 [ 0 ] ;
V_10 -> V_48 = V_10 -> V_39 -> V_48 . V_49 [ 0 ] . V_50 ;
if ( ! V_28 && V_10 -> V_39 -> V_51 . V_45 )
V_28 =
(struct V_27 * ) & V_52 ;
V_8 = F_14 ( V_2 , V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_15 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_29 > 0 ) {
V_8 = F_16 ( V_2 ,
V_53 ) ;
if ( V_8 < 0 )
goto V_54;
}
V_8 = F_17 ( V_2 ) ;
if ( V_8 )
goto V_55;
return V_8 ;
V_55:
if ( V_29 > 0 )
F_18 ( V_2 ) ;
V_54:
F_19 ( V_2 ) ;
return V_8 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_9 ( V_2 ) ;
F_21 ( V_2 ) ;
if ( V_10 -> V_30 ( V_2 ) > 0 )
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
}
