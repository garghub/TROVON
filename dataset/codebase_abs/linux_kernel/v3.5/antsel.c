static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool V_5 )
{
if ( V_2 -> V_6 == V_7 ) {
T_1 V_8 = V_9 |
( ( V_2 -> V_10 && V_5 ) ? V_11 : 0 ) ;
V_4 -> V_12 [ V_13 ] = V_8 ;
V_4 -> V_12 [ V_14 ] = V_8 ;
V_4 -> V_12 [ V_15 ] = V_8 ;
V_4 -> V_12 [ V_16 ] = V_8 ;
V_4 -> V_17 = V_18 ;
} else if ( V_2 -> V_6 == V_19 ) {
V_4 -> V_12 [ V_13 ] = V_20 ;
V_4 -> V_12 [ V_14 ] = V_20 ;
V_4 -> V_12 [ V_15 ] = V_20 ;
V_4 -> V_12 [ V_16 ] = V_20 ;
V_4 -> V_17 = V_21 ;
} else {
V_4 -> V_12 [ V_13 ] = V_22 ;
V_4 -> V_12 [ V_14 ] = V_22 ;
V_4 -> V_12 [ V_15 ] = V_22 ;
V_4 -> V_12 [ V_16 ] = V_22 ;
V_4 -> V_17 = 0 ;
}
}
struct V_1 * F_2 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 = & V_24 -> V_27 -> V_28 -> V_29 -> V_26 ;
V_2 = F_3 ( sizeof( struct V_1 ) , V_30 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_24 = V_24 ;
V_2 -> V_31 = V_24 -> V_31 ;
V_2 -> V_6 = V_32 ;
V_2 -> V_10 = false ;
V_2 -> V_33 = V_26 -> V_34 ;
if ( ( V_2 -> V_31 -> V_35 >= 4 ) && ( V_2 -> V_33 != 0 ) ) {
switch ( V_2 -> V_33 ) {
case V_36 :
case V_37 :
case V_38 :
V_2 -> V_6 = V_7 ;
if ( ( V_26 -> V_39 == 7 ) ||
( V_26 -> V_40 == 7 ) ) {
V_2 -> V_10 = true ;
} else if (
V_26 -> V_39 == 3 ||
V_26 -> V_40 == 3 ) {
V_2 -> V_10 = false ;
} else {
V_2 -> V_10 = false ;
F_4 ( V_24 -> V_41 , L_1
L_2 ) ;
}
break;
default:
break;
}
} else if ( ( V_2 -> V_31 -> V_35 == 4 ) &&
( V_26 -> V_39 == 7 ) &&
( V_26 -> V_40 == 0 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_10 = true ;
} else if ( V_2 -> V_31 -> V_42 & V_43 ) {
V_2 -> V_6 = V_19 ;
V_2 -> V_10 = true ;
}
F_5 ( V_24 -> V_27 , V_2 -> V_6 ) ;
F_1 ( V_2 , & V_2 -> V_44 , true ) ;
F_1 ( V_2 , & V_2 -> V_45 , true ) ;
return V_2 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 , T_1 V_46 )
{
T_1 V_47 = F_9 ( F_10 ( V_46 ) ) ;
T_2 V_48 = 0 ;
if ( V_2 -> V_6 == V_19 ) {
V_48 = ( V_49 [ V_47 ] & 0xf ) ;
return V_48 ;
} else if ( V_2 -> V_6 == V_7 ) {
V_48 = ( V_50 [ V_47 ] & 0xf ) ;
return V_48 ;
}
return V_48 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_46 ;
T_2 V_48 ;
V_46 = V_4 -> V_12 [ V_13 ] ;
V_48 = F_8 ( V_2 , V_46 ) ;
F_12 ( V_24 -> V_27 , V_51 , V_48 ) ;
V_2 -> V_45 . V_12 [ V_13 ] = V_46 ;
V_46 = V_4 -> V_12 [ V_15 ] ;
V_48 = F_8 ( V_2 , V_46 ) ;
F_12 ( V_24 -> V_27 , V_52 , V_48 ) ;
V_2 -> V_45 . V_12 [ V_15 ] = V_46 ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_6 == V_7 ) ||
( V_2 -> V_6 == V_19 ) )
F_11 ( V_2 , & V_2 -> V_44 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_1 V_53 )
{
T_1 V_54 = V_22 ;
if ( V_2 -> V_6 == V_19 ) {
V_54 = ( ( ( V_53 & 0x2 ) << 3 ) | ( ( V_53 & 0x1 ) + 2 ) ) ;
return V_54 ;
} else if ( V_2 -> V_6 == V_7 ) {
V_54 = ( ( ( V_53 & 0x02 ) << 4 ) | ( ( V_53 & 0x1 ) + 1 ) ) ;
return V_54 ;
}
return V_54 ;
}
void
F_15 ( struct V_1 * V_2 , bool V_55 , bool V_56 ,
T_1 V_57 , T_1 V_58 , T_1 * V_54 ,
T_1 * V_59 )
{
T_1 V_60 ;
if ( V_55 ) {
* V_54 = V_2 -> V_44 . V_12 [ V_13 ] ;
* V_59 = * V_54 ;
return;
}
if ( ! V_56 ) {
* V_54 = V_2 -> V_44 . V_12 [ V_14 ] ;
* V_59 = * V_54 ;
} else {
V_60 = V_2 -> V_44 . V_12 [ V_14 ] ;
if ( ( V_60 & V_11 ) == V_11 ) {
* V_54 = F_14 ( V_2 , V_57 ) ;
* V_59 = F_14 ( V_2 , V_58 ) ;
} else {
* V_54 =
V_2 -> V_44 . V_12 [ V_14 ] ;
* V_59 = * V_54 ;
}
}
return;
}
T_1 F_16 ( struct V_1 * V_2 , T_2 V_4 )
{
T_1 V_57 = 0 ;
if ( V_2 -> V_6 == V_19 ) {
V_57 = V_61 [ ( V_4 & 0xf ) ] ;
return V_57 ;
} else if ( V_2 -> V_6 == V_7 ) {
V_57 = V_62 [ ( V_4 & 0xf ) ] ;
return V_57 ;
}
return V_57 ;
}
