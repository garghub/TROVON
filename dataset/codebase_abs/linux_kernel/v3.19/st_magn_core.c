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
case V_21 :
* V_5 = V_10 -> V_22 ;
return V_13 ;
default:
return - V_23 ;
}
V_12:
return V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_24 , int V_5 , int V_6 , long V_7 )
{
int V_8 ;
switch ( V_7 ) {
case V_14 :
V_8 = F_5 ( V_2 , V_6 ) ;
break;
case V_21 :
if ( V_6 )
return - V_23 ;
F_6 ( & V_2 -> V_25 ) ;
V_8 = F_7 ( V_2 , V_5 ) ;
F_8 ( & V_2 -> V_25 ) ;
return V_8 ;
default:
V_8 = - V_23 ;
}
return V_8 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_26 = V_10 -> V_27 ( V_2 ) ;
int V_8 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = & V_31 ;
F_10 ( V_2 ) ;
V_8 = F_11 ( V_2 ,
F_12 ( V_32 ) ,
V_32 ) ;
if ( V_8 < 0 )
return V_8 ;
V_10 -> V_33 = V_34 ;
V_10 -> V_35 = V_10 -> V_36 -> V_37 ;
V_2 -> V_38 = V_10 -> V_36 -> V_4 ;
V_2 -> V_39 = V_40 ;
V_10 -> V_17 = (struct V_41 * )
& V_10 -> V_36 -> V_42 . V_43 [ 0 ] ;
V_10 -> V_22 = V_10 -> V_36 -> V_22 . V_44 [ 0 ] . V_45 ;
V_8 = F_13 ( V_2 , NULL ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_14 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_26 > 0 ) {
V_8 = F_15 ( V_2 , NULL ) ;
if ( V_8 < 0 )
goto V_46;
}
V_8 = F_16 ( V_2 ) ;
if ( V_8 )
goto V_47;
F_17 ( & V_2 -> V_48 , L_1 ,
V_2 -> V_49 ) ;
return 0 ;
V_47:
if ( V_26 > 0 )
F_18 ( V_2 ) ;
V_46:
F_19 ( V_2 ) ;
return V_8 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_10 -> V_27 ( V_2 ) > 0 )
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
}
