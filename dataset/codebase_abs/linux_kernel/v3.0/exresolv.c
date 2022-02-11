T_1
F_1 ( union V_1 * * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
F_2 ( V_6 , V_2 ) ;
if ( ! V_2 || ! * V_2 ) {
F_3 ( ( V_7 , L_1 ) ) ;
F_4 ( V_8 ) ;
}
if ( F_5 ( * V_2 ) == V_9 ) {
V_5 = F_6 ( V_2 , V_4 ) ;
if ( F_7 ( V_5 ) ) {
F_4 ( V_5 ) ;
}
if ( ! * V_2 ) {
F_3 ( ( V_7 , L_1 ) ) ;
F_4 ( V_8 ) ;
}
}
if ( F_5 ( * V_2 ) == V_10 ) {
V_5 =
F_8 ( F_9
( struct V_11 ,
V_2 ) , V_4 ) ;
if ( F_7 ( V_5 ) ) {
F_4 ( V_5 ) ;
}
}
F_10 ( ( V_12 , L_2 , * V_2 ) ) ;
F_4 ( V_13 ) ;
}
static T_1
F_6 ( union V_1 * * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_13 ;
union V_1 * V_14 ;
union V_1 * V_15 = NULL ;
T_2 V_16 ;
F_11 ( V_17 ) ;
V_14 = * V_2 ;
switch ( V_14 -> V_18 . type ) {
case V_19 :
V_16 = V_14 -> V_20 . V_21 ;
switch ( V_16 ) {
case V_22 :
case V_23 :
V_5 = F_12 ( V_16 ,
V_14 ->
V_20 . V_24 ,
V_4 ,
& V_15 ) ;
if ( F_7 ( V_5 ) ) {
F_4 ( V_5 ) ;
}
F_10 ( ( V_12 ,
L_3 ,
V_14 -> V_20 . V_24 ,
V_15 ) ) ;
F_13 ( V_14 ) ;
* V_2 = V_15 ;
break;
case V_25 :
switch ( V_14 -> V_20 . V_26 ) {
case V_27 :
break;
case V_28 :
if ( ( V_4 -> V_29 ==
V_30 )
|| ( V_4 -> V_29 == V_31 ) ) {
break;
}
V_15 = * V_14 -> V_20 . V_32 ;
if ( V_15 ) {
F_13 ( V_14 ) ;
F_14 ( V_15 ) ;
* V_2 = V_15 ;
} else {
F_3 ( ( V_7 ,
L_4 ,
V_14 ) ) ;
V_5 = V_33 ;
}
break;
default:
F_3 ( ( V_7 ,
L_5 ,
V_14 -> V_20 . V_26 ,
V_14 ) ) ;
V_5 = V_34 ;
break;
}
break;
case V_35 :
case V_36 :
case V_37 :
break;
case V_38 :
if ( ( V_14 -> V_20 . V_39 -> type ==
V_40 )
|| ( V_14 -> V_20 . V_39 -> type ==
V_41 ) ) {
* V_2 = ( void * ) V_14 -> V_20 . V_39 ;
} else {
* V_2 =
( V_14 -> V_20 . V_39 ) -> V_42 ;
F_14 ( * V_2 ) ;
}
F_13 ( V_14 ) ;
break;
default:
F_3 ( ( V_7 ,
L_6 ,
V_16 , V_14 ) ) ;
V_5 = V_34 ;
break;
}
break;
case V_43 :
V_5 = F_15 ( V_14 ) ;
break;
case V_28 :
V_5 = F_16 ( V_14 ) ;
break;
case V_27 :
case V_44 :
case V_45 :
case V_46 :
F_10 ( ( V_12 ,
L_7 ,
V_14 , V_14 -> V_18 . type ) ) ;
V_5 =
F_17 ( V_4 , V_14 ,
& V_15 ) ;
F_13 ( * V_2 ) ;
* V_2 = ( void * ) V_15 ;
break;
default:
break;
}
F_4 ( V_5 ) ;
}
T_1
F_18 ( struct V_3 * V_4 ,
union V_1 * V_47 ,
T_3 * V_48 ,
union V_1 * * V_49 )
{
union V_1 * V_15 = ( void * ) V_47 ;
struct V_11 * V_39 ;
T_3 type ;
T_1 V_5 ;
F_11 ( F_18 ) ;
switch ( F_5 ( V_15 ) ) {
case V_9 :
type = V_15 -> V_18 . type ;
break;
case V_10 :
type = ( (struct V_11 * ) V_15 ) -> type ;
V_15 =
F_19 ( (struct V_11 * )
V_15 ) ;
if ( type == V_50 ) {
type = ( (struct V_11 * ) V_15 ) -> type ;
V_15 =
F_19 ( (struct
V_11 * )
V_15 ) ;
}
break;
default:
F_4 ( V_51 ) ;
}
if ( type != V_19 ) {
goto exit;
}
while ( V_15 -> V_18 . type == V_19 ) {
switch ( V_15 -> V_20 . V_21 ) {
case V_35 :
case V_38 :
if ( V_15 -> V_20 . V_21 == V_35 ) {
V_39 = V_15 -> V_20 . V_42 ;
} else {
V_39 = V_15 -> V_20 . V_39 ;
}
if ( F_5 ( V_39 ) !=
V_10 ) {
F_3 ( ( V_7 ,
L_8 ,
V_39 ,
F_20 ( V_39 ) ) ) ;
F_4 ( V_34 ) ;
}
V_15 = F_19 ( V_39 ) ;
if ( ! V_15 ) {
type = F_21 ( V_39 ) ;
goto exit;
}
if ( V_15 == V_47 ) {
F_4 ( V_52 ) ;
}
break;
case V_25 :
type = V_15 -> V_20 . V_26 ;
if ( type != V_28 ) {
goto exit;
}
V_15 = * ( V_15 -> V_20 . V_32 ) ;
if ( ! V_15 ) {
type = 0 ;
goto exit;
}
break;
case V_37 :
type = V_53 ;
goto exit;
case V_22 :
case V_23 :
if ( V_49 ) {
V_5 =
F_12 ( V_15 ->
V_20 .
V_21 ,
V_15 ->
V_20 .
V_24 ,
V_4 ,
& V_15 ) ;
if ( F_7 ( V_5 ) ) {
F_4 ( V_5 ) ;
}
F_13 ( V_15 ) ;
} else {
V_5 =
F_22 ( V_15 ->
V_20 .
V_21 ,
V_15 ->
V_20 .
V_24 ,
V_4 ,
& V_39 ) ;
if ( F_7 ( V_5 ) ) {
F_4 ( V_5 ) ;
}
V_15 = F_19 ( V_39 ) ;
if ( ! V_15 ) {
type = V_54 ;
goto exit;
}
}
break;
case V_36 :
type = V_55 ;
goto exit;
default:
F_3 ( ( V_7 ,
L_9 ,
V_15 -> V_20 . V_21 ) ) ;
F_4 ( V_34 ) ;
}
}
type = V_15 -> V_18 . type ;
exit:
switch ( type ) {
case V_44 :
case V_45 :
case V_46 :
type = V_56 ;
break;
case V_57 :
type = V_54 ;
break;
default:
break;
}
* V_48 = type ;
if ( V_49 ) {
* V_49 = V_15 ;
}
F_4 ( V_13 ) ;
}
