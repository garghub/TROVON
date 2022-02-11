static void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
int V_4 , T_1 V_5 )
{
if ( V_4 ) {
if ( V_2 -> V_6 & V_5 )
* V_3 = V_7 ;
else
* V_3 = V_8 ;
} else {
V_2 -> V_6 &= ~ V_5 ;
if ( * V_3 == V_7 )
V_2 -> V_6 |= V_5 ;
}
}
int F_2 ( struct V_1 * V_2 , T_2 * V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_9 ;
if ( ! ( ( V_2 -> V_12 == V_13 &&
V_11 -> V_14 == V_15 ) ||
V_2 -> V_12 == V_16 ||
V_2 -> V_12 == V_17 ) ) {
return - V_18 ;
}
if ( ! F_3 ( V_19 ) &&
( V_11 -> V_14 != V_20 ) ) {
F_4 ( V_2 -> V_21 ,
L_1 ,
V_2 -> V_22 ) ;
return - V_23 ;
}
if ( F_5 ( 1 , & ( V_2 -> V_24 ) ) )
return - V_25 ;
F_6 ( V_2 , V_11 ) ;
if ( V_2 -> V_26 != NULL )
V_2 -> V_26 ( V_2 , V_11 ) ;
F_7 ( 1 , & ( V_2 -> V_24 ) ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
switch ( V_11 -> V_14 ) {
case V_27 : {
struct V_28 * V_29 =
(struct V_28 * ) V_11 ;
V_2 -> V_6 &=
~ ( V_30 | V_31 ) ;
if ( V_29 -> V_32 . V_3 == V_7 )
V_2 -> V_6 |= V_30 ;
if ( V_29 -> V_33 . V_3 == V_7 )
V_2 -> V_6 |= V_31 ;
break;
}
case V_20 :
case V_34 : {
int V_4 = ( V_11 -> V_14 == V_20 ) ;
struct V_35 * V_36 =
(struct V_35 * ) V_11 ;
F_8 ( V_2 , V_36 , V_4 ) ;
break;
}
}
}
static void F_8 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
int V_4 )
{
struct V_37 * V_38 = (struct V_37 * ) V_36 -> V_39 . V_3 ;
struct V_40 * V_41 = (struct V_40 * ) V_38 -> V_3 ;
T_2 * V_42 = V_38 -> V_3 + sizeof( struct V_40 ) ;
switch ( V_38 -> V_43 ) {
case F_9 ( 1 ) :
case F_9 ( 2 ) :
case F_9 ( 3 ) :
case F_9 ( 4 ) :
if ( ! V_4 )
F_10 ( V_2 ,
F_11 ( V_38 -> V_43 ) - 1 ,
V_42 , V_41 -> V_44 ) ;
break;
case V_45 : {
T_1 * V_3 = ( T_1 * ) V_38 -> V_3 ;
if ( V_4 ) {
* V_3 = V_2 -> V_6 & V_46 ;
} else {
V_2 -> V_6 &= ~ ( V_46 ) ;
V_2 -> V_6 |= ( * V_3 & V_46 ) ;
}
break;
}
case V_47 : {
T_1 * V_3 = ( T_1 * ) V_38 -> V_3 ;
F_1 ( V_2 , V_3 , V_4 ,
V_48 ) ;
break;
}
case V_49 : {
T_1 * V_3 = ( T_1 * ) V_38 -> V_3 ;
F_1 ( V_2 , V_3 , V_4 ,
V_50 ) ;
break;
}
}
}
