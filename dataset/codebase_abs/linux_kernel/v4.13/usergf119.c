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
F_4 ( * V_6 , 0x04 , V_8 -> V_2 . V_16 >> 8 ) ;
F_4 ( * V_6 , 0x08 , V_8 -> V_2 . V_17 >> 8 ) ;
F_4 ( * V_6 , 0x0c , 0x00000000 ) ;
F_4 ( * V_6 , 0x10 , 0x00000000 ) ;
F_4 ( * V_6 , 0x14 , 0x00000000 ) ;
F_5 ( * V_6 ) ;
}
return V_14 ;
}
int
F_6 ( struct V_18 * V_11 , const struct V_19 * V_20 ,
void * V_21 , T_1 V_22 , struct V_1 * * V_23 )
{
union {
struct V_24 V_25 ;
} * args ;
struct V_26 * V_4 = V_20 -> V_4 ;
struct V_7 * V_8 ;
T_1 V_27 , V_28 ;
int V_14 ;
if ( ! ( V_8 = F_7 ( sizeof( * V_8 ) , V_29 ) ) )
return - V_30 ;
* V_23 = & V_8 -> V_2 ;
V_14 = F_8 ( & V_31 , V_11 , V_20 ,
& V_21 , & V_22 , & V_8 -> V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = - V_32 ;
args = V_21 ;
F_9 ( V_4 , L_1 , V_22 ) ;
if ( ! ( V_14 = F_10 ( V_14 , & V_21 , & V_22 , args -> V_25 , 0 , 0 , false ) ) ) {
F_9 ( V_4 ,
L_2 ,
args -> V_25 . V_33 , args -> V_25 . V_28 , args -> V_25 . V_27 ) ;
V_27 = args -> V_25 . V_27 ;
V_28 = args -> V_25 . V_28 ;
} else
if ( V_22 == 0 ) {
if ( V_8 -> V_2 . V_34 != V_35 ) {
V_27 = V_36 ;
V_28 = V_37 ;
} else {
V_27 = V_38 ;
V_28 = V_39 ;
}
} else
return V_14 ;
if ( V_28 > 1 )
return - V_40 ;
V_8 -> V_15 = ( V_27 << 20 ) | ( V_28 << 6 ) ;
switch ( V_8 -> V_2 . V_34 ) {
case V_41 :
V_8 -> V_15 |= 0x00000009 ;
break;
case V_35 :
case V_42 :
case V_43 :
break;
default:
return - V_40 ;
}
return 0 ;
}
