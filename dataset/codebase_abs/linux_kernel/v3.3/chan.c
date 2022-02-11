struct V_1 *
F_1 ( struct V_2 * V_3 ,
int V_4 , enum V_5 V_6 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_2 ( & V_3 -> V_10 , V_4 ) ;
if ( ! V_7 || V_7 -> V_11 & V_12 )
return NULL ;
if ( V_6 == V_13 &&
V_7 -> V_11 & V_14 )
return NULL ;
else if ( V_6 == V_15 &&
V_7 -> V_11 & V_16 )
return NULL ;
V_9 = & V_3 -> V_10 . V_17 [ V_7 -> V_18 ] -> V_9 ;
if ( V_6 != V_19 ) {
if ( ! V_9 -> V_20 )
return NULL ;
if ( V_6 != V_21 &&
( ! ( V_9 -> V_22 & V_23 ) ||
V_9 -> V_22 & V_24 ) )
return NULL ;
}
return V_7 ;
}
int F_3 ( struct V_10 * V_10 ,
struct V_1 * V_7 ,
enum V_5 V_6 )
{
struct V_1 * V_25 ;
int V_26 ;
switch ( V_6 ) {
case V_15 :
V_26 = 20 ;
break;
case V_13 :
V_26 = - 20 ;
break;
default:
return false ;
}
V_25 = F_2 ( V_10 , V_7 -> V_27 + V_26 ) ;
if ( ! V_25 )
return false ;
if ( V_25 -> V_11 & ( V_12 |
V_28 |
V_29 |
V_30 ) )
return false ;
return true ;
}
int F_4 ( struct V_2 * V_3 ,
struct V_31 * V_32 , int V_4 ,
enum V_5 V_6 )
{
struct V_1 * V_7 ;
int V_33 ;
if ( V_32 && V_32 -> V_34 == V_35 )
V_32 = NULL ;
if ( V_32 ) {
F_5 ( V_32 ) ;
if ( ! F_6 ( V_32 -> V_36 ) )
return - V_37 ;
}
if ( ! V_3 -> V_38 -> V_39 )
return - V_40 ;
V_7 = F_1 ( V_3 , V_4 , V_6 ) ;
if ( ! V_7 )
return - V_41 ;
if ( V_32 && ( V_32 -> V_34 == V_42 ||
V_32 -> V_34 == V_43 ||
V_32 -> V_34 == V_44 ||
V_32 -> V_34 == V_45 ||
V_32 -> V_34 == V_46 ) ) {
switch ( V_6 ) {
case V_15 :
case V_13 :
if ( ! F_3 ( & V_3 -> V_10 , V_7 ,
V_6 ) ) {
F_7 ( V_47
L_1
L_2 ) ;
return - V_41 ;
}
break;
default:
break;
}
}
V_33 = V_3 -> V_38 -> V_39 ( & V_3 -> V_10 ,
V_32 ? V_32 -> V_36 : NULL ,
V_7 , V_6 ) ;
if ( V_33 )
return V_33 ;
if ( V_32 )
V_32 -> V_48 = V_7 ;
return 0 ;
}
