struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 ) {
F_3 ( V_3 -> V_6 , L_1 ,
V_3 -> V_7 -> V_8 ) ;
return NULL ;
}
V_4 -> V_3 = V_3 ;
V_4 -> V_7 = V_3 -> V_7 ;
V_4 -> V_9 = V_10 ;
V_4 -> V_11 = false ;
V_4 -> V_12 = ( V_13 ) F_4 ( V_4 -> V_7 -> V_14 , L_2 ) ;
if ( ( V_4 -> V_7 -> V_15 >= 4 ) && ( V_4 -> V_12 != 0 ) ) {
switch ( V_4 -> V_12 ) {
case V_16 :
case V_17 :
case V_18 :
V_4 -> V_9 = V_19 ;
if ( ( ( V_20 ) F_4 ( V_4 -> V_7 -> V_14 , L_3 ) == 7 ) ||
( ( V_20 ) F_4 ( V_4 -> V_7 -> V_14 , L_4 ) == 7 ) ) {
V_4 -> V_11 = true ;
} else
if ( ( ( V_20 ) F_4 ( V_4 -> V_7 -> V_14 , L_3 ) ==
3 )
|| ( ( V_20 ) F_4 ( V_4 -> V_7 -> V_14 , L_4 )
== 3 ) ) {
V_4 -> V_11 = false ;
} else {
V_4 -> V_11 = false ;
F_3 ( V_3 -> V_6 , L_5
L_6 ) ;
}
break;
default:
break;
}
} else if ( ( V_4 -> V_7 -> V_15 == 4 ) &&
( ( V_20 ) F_4 ( V_4 -> V_7 -> V_14 , L_3 ) == 7 ) &&
( ( V_20 ) F_4 ( V_4 -> V_7 -> V_14 , L_4 ) == 0 ) ) {
V_4 -> V_9 = V_19 ;
V_4 -> V_11 = true ;
} else if ( V_4 -> V_7 -> V_21 & V_22 ) {
V_4 -> V_9 = V_23 ;
V_4 -> V_11 = true ;
}
F_5 ( V_3 -> V_24 , V_4 -> V_9 ) ;
F_6 ( V_4 , & V_4 -> V_25 , true ) ;
F_6 ( V_4 , & V_4 -> V_26 , true ) ;
return V_4 ;
}
void F_7 ( struct V_1 * V_4 )
{
F_8 ( V_4 ) ;
}
void F_9 ( struct V_1 * V_4 )
{
if ( ( V_4 -> V_9 == V_19 ) ||
( V_4 -> V_9 == V_23 ) )
F_10 ( V_4 , & V_4 -> V_25 ) ;
}
static void
F_6 ( struct V_1 * V_4 , T_1 * V_27 ,
bool V_28 )
{
if ( V_4 -> V_9 == V_19 ) {
V_13 V_29 = V_30 |
( ( V_4 -> V_11 && V_28 ) ? V_31 : 0 ) ;
V_27 -> V_32 [ V_33 ] = V_29 ;
V_27 -> V_32 [ V_34 ] = V_29 ;
V_27 -> V_32 [ V_35 ] = V_29 ;
V_27 -> V_32 [ V_36 ] = V_29 ;
V_27 -> V_37 = V_38 ;
} else if ( V_4 -> V_9 == V_23 ) {
V_27 -> V_32 [ V_33 ] = V_39 ;
V_27 -> V_32 [ V_34 ] = V_39 ;
V_27 -> V_32 [ V_35 ] = V_39 ;
V_27 -> V_32 [ V_36 ] = V_39 ;
V_27 -> V_37 = V_40 ;
} else {
V_27 -> V_32 [ V_33 ] = V_41 ;
V_27 -> V_32 [ V_34 ] = V_41 ;
V_27 -> V_32 [ V_35 ] = V_41 ;
V_27 -> V_32 [ V_36 ] = V_41 ;
V_27 -> V_37 = 0 ;
}
}
void
F_11 ( struct V_1 * V_4 , bool V_42 , bool V_43 ,
V_13 V_44 , V_13 V_45 , V_13 * V_46 ,
V_13 * V_47 )
{
V_13 V_48 ;
if ( V_42 ) {
* V_46 = V_4 -> V_25 . V_32 [ V_33 ] ;
* V_47 = * V_46 ;
return;
}
if ( ! V_43 ) {
* V_46 = V_4 -> V_25 . V_32 [ V_34 ] ;
* V_47 = * V_46 ;
} else {
V_48 = V_4 -> V_25 . V_32 [ V_34 ] ;
if ( ( V_48 & V_31 ) == V_31 ) {
* V_46 = F_12 ( V_4 , V_44 ) ;
* V_47 = F_12 ( V_4 , V_45 ) ;
} else {
* V_46 =
V_4 -> V_25 . V_32 [ V_34 ] ;
* V_47 = * V_46 ;
}
}
return;
}
V_13 F_13 ( struct V_1 * V_4 , V_20 V_27 )
{
V_13 V_44 = 0 ;
if ( V_4 -> V_9 == V_23 ) {
V_44 = V_49 [ ( V_27 & 0xf ) ] ;
return V_44 ;
} else if ( V_4 -> V_9 == V_19 ) {
V_44 = V_50 [ ( V_27 & 0xf ) ] ;
return V_44 ;
}
return V_44 ;
}
static V_13 F_12 ( struct V_1 * V_4 , V_13 V_51 )
{
V_13 V_46 = V_41 ;
if ( V_4 -> V_9 == V_23 ) {
V_46 = ( ( ( V_51 & 0x2 ) << 3 ) | ( ( V_51 & 0x1 ) + 2 ) ) ;
return V_46 ;
} else if ( V_4 -> V_9 == V_19 ) {
V_46 = ( ( ( V_51 & 0x02 ) << 4 ) | ( ( V_51 & 0x1 ) + 1 ) ) ;
return V_46 ;
}
return V_46 ;
}
static V_20 F_14 ( struct V_1 * V_4 , V_13 V_52 )
{
V_13 V_53 = F_15 ( F_16 ( V_52 ) ) ;
V_20 V_54 = 0 ;
if ( V_4 -> V_9 == V_23 ) {
V_54 = ( V_55 [ V_53 ] & 0xf ) ;
return V_54 ;
} else if ( V_4 -> V_9 == V_19 ) {
V_54 = ( V_56 [ V_53 ] & 0xf ) ;
return V_54 ;
}
return V_54 ;
}
static int F_10 ( struct V_1 * V_4 , T_1 * V_27 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
V_13 V_52 ;
V_20 V_54 ;
V_52 = V_27 -> V_32 [ V_33 ] ;
V_54 = F_14 ( V_4 , V_52 ) ;
F_17 ( V_3 , V_57 , V_54 ) ;
V_4 -> V_26 . V_32 [ V_33 ] = V_52 ;
V_52 = V_27 -> V_32 [ V_35 ] ;
V_54 = F_14 ( V_4 , V_52 ) ;
F_17 ( V_3 , V_58 , V_54 ) ;
V_4 -> V_26 . V_32 [ V_35 ] = V_52 ;
return 0 ;
}
