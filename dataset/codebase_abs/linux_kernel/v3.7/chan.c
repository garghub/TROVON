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
bool F_3 ( struct V_10 * V_10 ,
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
return true ;
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
int V_4 , enum V_5 V_31 )
{
struct V_1 * V_7 ;
if ( ! V_3 -> V_32 -> V_33 )
return - V_34 ;
if ( ! F_5 ( V_3 ) )
return - V_35 ;
V_7 = F_1 ( V_3 , V_4 , V_31 ) ;
if ( ! V_7 )
return - V_36 ;
return V_3 -> V_32 -> V_33 ( & V_3 -> V_10 , V_7 , V_31 ) ;
}
void
F_6 ( struct V_37 * V_38 ,
struct V_1 * * V_7 ,
enum V_39 * V_40 )
{
* V_7 = NULL ;
* V_40 = V_41 ;
F_7 ( V_38 ) ;
if ( V_38 -> V_42 && ! F_8 ( V_38 -> V_42 ) )
return;
switch ( V_38 -> V_43 ) {
case V_44 :
if ( V_38 -> V_45 ) {
* V_7 = V_38 -> V_45 -> V_46 . V_47 ;
* V_40 = V_38 -> V_48
? V_49
: V_50 ;
return;
}
case V_51 :
case V_52 :
if ( V_38 -> V_45 ) {
* V_7 = V_38 -> V_45 -> V_46 . V_47 ;
* V_40 = V_49 ;
return;
}
break;
case V_53 :
case V_54 :
if ( V_38 -> V_55 ) {
* V_7 = V_38 -> V_47 ;
* V_40 = V_49 ;
}
return;
case V_56 :
if ( V_38 -> V_57 ) {
* V_7 = V_38 -> V_47 ;
* V_40 = V_49 ;
}
return;
case V_58 :
case V_59 :
case V_60 :
return;
case V_61 :
if ( V_38 -> V_10 -> V_62 &
V_63 )
* V_40 = V_50 ;
return;
case V_64 :
case V_65 :
F_9 ( 1 ) ;
}
return;
}
