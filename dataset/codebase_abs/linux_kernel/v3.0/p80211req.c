int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
if ( ! ( ( V_1 -> V_6 == V_7 &&
V_5 -> V_8 == V_9 ) ||
V_1 -> V_6 == V_10 ||
V_1 -> V_6 == V_11 ) ) {
return - V_12 ;
}
if ( ! F_2 ( V_13 ) &&
( V_5 -> V_8 != V_14 ) ) {
F_3 ( V_15
L_1 ,
V_1 -> V_16 ) ;
return - V_17 ;
}
if ( F_4 ( 1 , & ( V_1 -> V_18 ) ) )
return - V_19 ;
F_5 ( V_1 , V_5 ) ;
if ( V_1 -> V_20 != NULL )
V_1 -> V_20 ( V_1 , V_5 ) ;
F_6 ( 1 , & ( V_1 -> V_18 ) ) ;
return V_3 ;
}
static void F_5 ( T_1 * V_1 , struct V_4 * V_5 )
{
switch ( V_5 -> V_8 ) {
case V_21 : {
struct V_22 * V_23 =
(struct V_22 * ) V_5 ;
V_1 -> V_24 &=
~ ( V_25 | V_26 ) ;
if ( V_23 -> V_27 . V_28 == V_29 )
V_1 -> V_24 |= V_25 ;
if ( V_23 -> V_30 . V_28 == V_29 )
V_1 -> V_24 |= V_26 ;
break;
}
case V_14 :
case V_31 : {
int V_32 = ( V_5 -> V_8 == V_14 ) ;
struct V_33 * V_34 =
(struct V_33 * ) V_5 ;
F_7 ( V_1 , V_34 , V_32 ) ;
}
default:
;
}
return;
}
static int F_7 ( T_1 * V_1 ,
struct V_33 * V_34 ,
int V_32 )
{
T_3 * V_35 = ( T_3 * ) V_34 -> V_36 . V_28 ;
T_4 * V_37 = ( T_4 * ) V_35 -> V_28 ;
T_2 * V_38 = V_35 -> V_28 + sizeof( T_4 ) ;
switch ( V_35 -> V_39 ) {
case V_40 : {
if ( ! V_32 )
F_8 ( V_1 , 0 , V_38 , V_37 -> V_41 ) ;
break;
}
case V_42 : {
if ( ! V_32 )
F_8 ( V_1 , 1 , V_38 , V_37 -> V_41 ) ;
break;
}
case V_43 : {
if ( ! V_32 )
F_8 ( V_1 , 2 , V_38 , V_37 -> V_41 ) ;
break;
}
case V_44 : {
if ( ! V_32 )
F_8 ( V_1 , 3 , V_38 , V_37 -> V_41 ) ;
break;
}
case V_45 : {
T_5 * V_28 = ( T_5 * ) V_35 -> V_28 ;
if ( V_32 ) {
* V_28 =
V_1 -> V_24 & V_46 ;
} else {
V_1 -> V_24 &= ~ ( V_46 ) ;
V_1 -> V_24 |=
( * V_28 & V_46 ) ;
}
break;
}
case V_47 : {
T_5 * V_28 = ( T_5 * ) V_35 -> V_28 ;
if ( V_32 ) {
if ( V_1 -> V_24 & V_48 )
* V_28 = V_29 ;
else
* V_28 = V_49 ;
} else {
V_1 -> V_24 &= ~ ( V_48 ) ;
if ( * V_28 == V_29 )
V_1 -> V_24 |=
V_48 ;
}
break;
}
case V_50 : {
T_5 * V_28 = ( T_5 * ) V_35 -> V_28 ;
if ( V_32 ) {
if ( V_1 -> V_24 &
V_51 )
* V_28 = V_29 ;
else
* V_28 = V_49 ;
} else {
V_1 -> V_24 &=
~ ( V_51 ) ;
if ( * V_28 == V_29 )
V_1 -> V_24 |=
V_51 ;
}
break;
}
default:
;
}
return 0 ;
}
