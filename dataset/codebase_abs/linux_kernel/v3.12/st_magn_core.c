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
if ( ( V_4 -> V_15 == V_16 ) &&
( V_10 -> V_17 -> V_18 != 0 ) )
* V_6 = V_10 -> V_17 -> V_18 ;
else
* V_6 = V_10 -> V_17 -> V_19 ;
return V_20 ;
default:
return - V_21 ;
}
V_12:
return V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_22 , int V_5 , int V_6 , long V_7 )
{
int V_8 ;
switch ( V_7 ) {
case V_14 :
V_8 = F_5 ( V_2 , V_6 ) ;
break;
default:
V_8 = - V_21 ;
}
return V_8 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_2 -> V_25 = V_26 ;
V_2 -> V_27 = & V_28 ;
V_8 = F_7 ( V_2 ,
F_8 ( V_29 ) , V_29 ) ;
if ( V_8 < 0 )
goto V_30;
V_10 -> V_31 = V_32 ;
V_10 -> V_33 = V_10 -> V_34 -> V_35 ;
V_2 -> V_36 = V_10 -> V_34 -> V_4 ;
V_2 -> V_37 = V_38 ;
V_10 -> V_17 = (struct V_39 * )
& V_10 -> V_34 -> V_40 . V_41 [ 0 ] ;
V_10 -> V_42 = V_10 -> V_34 -> V_42 . V_43 [ 0 ] . V_44 ;
V_8 = F_9 ( V_2 , V_24 ) ;
if ( V_8 < 0 )
goto V_30;
if ( V_10 -> V_45 ( V_2 ) > 0 ) {
V_8 = F_10 ( V_2 ) ;
if ( V_8 < 0 )
goto V_30;
V_8 = F_11 ( V_2 , NULL ) ;
if ( V_8 < 0 )
goto V_46;
}
V_8 = F_12 ( V_2 ) ;
if ( V_8 )
goto V_47;
return V_8 ;
V_47:
if ( V_10 -> V_45 ( V_2 ) > 0 )
F_13 ( V_2 ) ;
V_46:
if ( V_10 -> V_45 ( V_2 ) > 0 )
F_14 ( V_2 ) ;
V_30:
return V_8 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_16 ( V_2 ) ;
if ( V_10 -> V_45 ( V_2 ) > 0 ) {
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
}
}
