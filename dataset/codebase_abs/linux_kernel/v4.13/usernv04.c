static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , struct V_3 * * V_6 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_2 . V_11 -> V_12 . V_13 . V_10 ;
T_1 V_14 = V_8 -> V_2 . V_15 & 0xfffff000 ;
T_1 V_16 = V_8 -> V_2 . V_15 & 0x00000fff ;
T_2 V_17 = V_8 -> V_2 . V_18 - V_8 -> V_2 . V_15 ;
int V_19 ;
if ( V_8 -> V_20 ) {
struct V_21 * V_22 = V_21 ( V_10 -> V_22 ) ;
struct V_23 * V_24 = V_22 -> V_25 -> V_24 [ 0 ] . V_26 [ 0 ] ;
if ( ! V_8 -> V_2 . V_15 )
return F_2 ( V_24 , V_6 ) ;
F_3 ( V_24 ) ;
V_14 = F_4 ( V_24 , 8 + ( V_14 >> 10 ) ) ;
V_14 &= 0xfffff000 ;
F_5 ( V_24 ) ;
}
V_19 = F_6 ( V_10 , 16 , V_5 , false , V_4 , V_6 ) ;
if ( V_19 == 0 ) {
F_3 ( * V_6 ) ;
F_7 ( * V_6 , 0x00 , V_8 -> V_27 | ( V_16 << 20 ) ) ;
F_7 ( * V_6 , 0x04 , V_17 ) ;
F_7 ( * V_6 , 0x08 , V_8 -> V_28 | V_14 ) ;
F_7 ( * V_6 , 0x0c , V_8 -> V_28 | V_14 ) ;
F_5 ( * V_6 ) ;
}
return V_19 ;
}
int
F_8 ( struct V_29 * V_11 , const struct V_30 * V_31 ,
void * V_32 , T_2 V_33 , struct V_1 * * V_34 )
{
struct V_9 * V_10 = V_11 -> V_12 . V_13 . V_10 ;
struct V_7 * V_8 ;
int V_19 ;
if ( ! ( V_8 = F_9 ( sizeof( * V_8 ) , V_35 ) ) )
return - V_36 ;
* V_34 = & V_8 -> V_2 ;
V_19 = F_10 ( & V_37 , V_11 , V_31 ,
& V_32 , & V_33 , & V_8 -> V_2 ) ;
if ( V_19 )
return V_19 ;
if ( V_8 -> V_2 . V_38 == V_39 ) {
if ( V_10 -> V_22 -> V_40 == & V_21 )
V_8 -> V_20 = true ;
V_8 -> V_2 . V_38 = V_41 ;
V_8 -> V_2 . V_42 = V_43 ;
}
V_8 -> V_27 = V_31 -> V_2 . V_31 ;
switch ( V_8 -> V_2 . V_38 ) {
case V_44 :
V_8 -> V_27 |= 0x00003000 ;
break;
case V_41 :
V_8 -> V_27 |= 0x00023000 ;
break;
case V_45 :
V_8 -> V_27 |= 0x00033000 ;
break;
default:
return - V_46 ;
}
switch ( V_8 -> V_2 . V_42 ) {
case V_47 :
V_8 -> V_27 |= 0x00004000 ;
break;
case V_48 :
V_8 -> V_27 |= 0x00008000 ;
case V_43 :
V_8 -> V_28 |= 0x00000002 ;
break;
default:
return - V_46 ;
}
return 0 ;
}
