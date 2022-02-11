static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , struct V_3 * * V_6 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_2 . V_11 -> V_12 . V_13 . V_10 ;
int V_14 ;
V_14 = F_2 ( V_10 , 24 , V_5 , false , V_4 , V_6 ) ;
if ( V_14 == 0 ) {
F_3 ( * V_6 ) ;
F_4 ( * V_6 , 0x00 , V_8 -> V_15 ) ;
F_4 ( * V_6 , 0x04 , F_5 ( V_8 -> V_2 . V_16 ) ) ;
F_4 ( * V_6 , 0x08 , F_5 ( V_8 -> V_2 . V_17 ) ) ;
F_4 ( * V_6 , 0x0c , F_6 ( V_8 -> V_2 . V_16 ) << 24 |
F_6 ( V_8 -> V_2 . V_17 ) ) ;
F_4 ( * V_6 , 0x10 , 0x00000000 ) ;
F_4 ( * V_6 , 0x14 , V_8 -> V_18 ) ;
F_7 ( * V_6 ) ;
}
return V_14 ;
}
int
F_8 ( struct V_19 * V_11 , const struct V_20 * V_21 ,
void * V_22 , T_1 V_23 , struct V_1 * * V_24 )
{
union {
struct V_25 V_26 ;
} * args ;
struct V_27 * V_4 = V_21 -> V_4 ;
struct V_7 * V_8 ;
T_1 V_28 , V_29 , V_30 ;
int V_14 ;
if ( ! ( V_8 = F_9 ( sizeof( * V_8 ) , V_31 ) ) )
return - V_32 ;
* V_24 = & V_8 -> V_2 ;
V_14 = F_10 ( & V_33 , V_11 , V_21 ,
& V_22 , & V_23 , & V_8 -> V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = - V_34 ;
args = V_22 ;
F_11 ( V_4 , L_1 , V_23 ) ;
if ( ! ( V_14 = F_12 ( V_14 , & V_22 , & V_23 , args -> V_26 , 0 , 0 , false ) ) ) {
F_11 ( V_4 ,
L_2 ,
args -> V_26 . V_35 , args -> V_26 . V_36 , args -> V_26 . V_28 ) ;
V_28 = args -> V_26 . V_28 ;
V_29 = args -> V_26 . V_36 ;
V_30 = 0 ;
} else
if ( V_23 == 0 ) {
if ( V_8 -> V_2 . V_37 != V_38 ) {
V_28 = V_39 ;
V_29 = V_40 ;
V_30 = 2 ;
} else {
V_28 = V_41 ;
V_29 = V_42 ;
V_30 = 0 ;
}
} else
return V_14 ;
if ( V_29 > 2 )
return - V_43 ;
V_8 -> V_15 |= ( V_28 << 22 ) | ( V_29 << 20 ) | V_21 -> V_2 . V_21 ;
V_8 -> V_18 |= ( V_30 << 16 ) ;
switch ( V_8 -> V_2 . V_37 ) {
case V_38 :
V_8 -> V_15 |= 0x00000000 ;
break;
case V_44 :
V_8 -> V_15 |= 0x00010000 ;
break;
case V_45 :
V_8 -> V_15 |= 0x00020000 ;
break;
case V_46 :
V_8 -> V_15 |= 0x00030000 ;
break;
default:
return - V_43 ;
}
switch ( V_8 -> V_2 . V_47 ) {
case V_48 :
break;
case V_49 :
V_8 -> V_15 |= 0x00040000 ;
break;
case V_50 :
case V_51 :
V_8 -> V_15 |= 0x00080000 ;
break;
}
return 0 ;
}
