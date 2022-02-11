int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( ! ( ( V_1 -> V_5 == V_6 &&
V_4 -> V_7 == V_8 ) ||
V_1 -> V_5 == V_9 ||
V_1 -> V_5 == V_10 ) ) {
return - V_11 ;
}
if ( ! F_2 ( V_12 ) &&
( V_4 -> V_7 != V_13 ) ) {
F_3 ( V_1 -> V_14 ,
L_1 ,
V_1 -> V_15 ) ;
return - V_16 ;
}
if ( F_4 ( 1 , & ( V_1 -> V_17 ) ) )
return - V_18 ;
F_5 ( V_1 , V_4 ) ;
if ( V_1 -> V_19 != NULL )
V_1 -> V_19 ( V_1 , V_4 ) ;
F_6 ( 1 , & ( V_1 -> V_17 ) ) ;
return 0 ;
}
static void F_5 ( T_1 * V_1 , struct V_3 * V_4 )
{
switch ( V_4 -> V_7 ) {
case V_20 : {
struct V_21 * V_22 =
(struct V_21 * ) V_4 ;
V_1 -> V_23 &=
~ ( V_24 | V_25 ) ;
if ( V_22 -> V_26 . V_27 == V_28 )
V_1 -> V_23 |= V_24 ;
if ( V_22 -> V_29 . V_27 == V_28 )
V_1 -> V_23 |= V_25 ;
break;
}
case V_13 :
case V_30 : {
int V_31 = ( V_4 -> V_7 == V_13 ) ;
struct V_32 * V_33 =
(struct V_32 * ) V_4 ;
F_7 ( V_1 , V_33 , V_31 ) ;
break;
}
}
}
static void F_7 ( T_1 * V_1 ,
struct V_32 * V_33 ,
int V_31 )
{
T_3 * V_34 = ( T_3 * ) V_33 -> V_35 . V_27 ;
T_4 * V_36 = ( T_4 * ) V_34 -> V_27 ;
T_2 * V_37 = V_34 -> V_27 + sizeof( T_4 ) ;
switch ( V_34 -> V_38 ) {
case V_39 : {
if ( ! V_31 )
F_8 ( V_1 , 0 , V_37 , V_36 -> V_40 ) ;
break;
}
case V_41 : {
if ( ! V_31 )
F_8 ( V_1 , 1 , V_37 , V_36 -> V_40 ) ;
break;
}
case V_42 : {
if ( ! V_31 )
F_8 ( V_1 , 2 , V_37 , V_36 -> V_40 ) ;
break;
}
case V_43 : {
if ( ! V_31 )
F_8 ( V_1 , 3 , V_37 , V_36 -> V_40 ) ;
break;
}
case V_44 : {
T_5 * V_27 = ( T_5 * ) V_34 -> V_27 ;
if ( V_31 ) {
* V_27 = V_1 -> V_23 & V_45 ;
} else {
V_1 -> V_23 &= ~ ( V_45 ) ;
V_1 -> V_23 |= ( * V_27 & V_45 ) ;
}
break;
}
case V_46 : {
T_5 * V_27 = ( T_5 * ) V_34 -> V_27 ;
if ( V_31 ) {
if ( V_1 -> V_23 & V_47 )
* V_27 = V_28 ;
else
* V_27 = V_48 ;
} else {
V_1 -> V_23 &= ~ ( V_47 ) ;
if ( * V_27 == V_28 )
V_1 -> V_23 |= V_47 ;
}
break;
}
case V_49 : {
T_5 * V_27 = ( T_5 * ) V_34 -> V_27 ;
if ( V_31 ) {
if ( V_1 -> V_23 & V_50 )
* V_27 = V_28 ;
else
* V_27 = V_48 ;
} else {
V_1 -> V_23 &= ~ ( V_50 ) ;
if ( * V_27 == V_28 )
V_1 -> V_23 |= V_50 ;
}
break;
}
}
}
