static inline const char * F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_2 : return L_1 ;
case V_3 : return L_2 ;
case V_4 : return L_3 ;
case V_5 : return L_4 ;
case V_6 : return L_5 ;
case V_7 : return L_6 ;
default: return L_7 ;
}
}
int F_2 ( struct V_8 * * V_9 ,
struct V_10 * V_10 ,
struct V_11 * V_12 , int V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 V_21 = {
. type = L_8 ,
. V_22 = 0x60 ,
} ;
if ( ! V_12 )
return - V_23 ;
switch ( V_12 -> V_24 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
if ( V_12 -> V_24 == V_2 )
* V_9 = F_3 ( V_25 ,
& V_26 [ 0 ] ,
V_12 -> V_27 ) ;
else if ( V_12 -> V_24 == V_4 )
* V_9 = F_3 ( V_25 ,
& V_26 [ 1 ] ,
V_12 -> V_27 ) ;
else
* V_9 = F_3 ( V_25 ,
& V_26 [ 2 ] ,
V_12 -> V_27 ) ;
if ( ! * V_9 ) {
F_4 ( V_10 -> V_28 ,
L_9
, V_29 , F_1 ( V_12 -> V_24 ) ) ;
return - V_30 ;
} ;
( * V_9 ) -> V_31 . V_32 ( * V_9 ) ;
V_15 = F_5 ( V_10 -> V_28 ,
sizeof( struct V_14 ) ,
V_33 ) ;
if ( ! V_15 ) {
F_4 ( V_10 -> V_28 ,
L_10 , V_29 ) ;
return - V_34 ;
}
memcpy ( V_15 , & V_35 ,
sizeof( struct V_14 ) ) ;
V_15 -> V_9 = ( * V_9 ) ;
V_21 . V_36 = V_15 ;
F_6 ( L_8 ) ;
V_19 = F_7 ( V_12 -> V_27 , & V_21 ) ;
if ( ! V_19 || ! V_19 -> V_37 . V_38 ) {
F_8 ( * V_9 ) ;
return - V_30 ;
}
if ( ! F_9 ( V_19 -> V_37 . V_38 -> V_39 ) ) {
F_10 ( V_19 ) ;
F_8 ( * V_9 ) ;
return - V_30 ;
}
V_12 -> V_18 = V_19 ;
break;
case V_6 :
* V_9 = F_3 ( V_40 , & V_41 ,
V_12 -> V_27 , V_42 ) ;
if ( ! * V_9 ) {
F_4 ( V_10 -> V_28 , L_11
L_12 ,
V_29 , F_1 ( V_12 -> V_24 ) ) ;
return - V_30 ;
}
V_17 = F_3 ( V_43 , * V_9 ,
& V_44 , V_12 -> V_27 ) ;
if ( ! V_17 ) {
F_4 ( V_10 -> V_28 ,
L_13
, V_29 , F_1 ( V_12 -> V_24 ) ) ;
return - V_30 ;
} ;
V_41 . V_45 = V_17 -> V_45 ;
V_41 . V_46 = V_17 -> V_46 ;
V_41 . V_47 = V_17 -> V_47 ;
V_41 . V_48 = V_17 -> V_48 ;
V_41 . V_49 = V_17 -> V_49 ;
V_41 . V_50 = V_17 -> V_50 ;
V_41 . V_51 = V_17 -> V_51 ;
V_41 . V_52 = V_17 -> V_52 ;
V_41 . V_53 = V_17 -> V_53 ;
V_41 . V_54 = V_17 -> V_54 ;
F_3 ( V_55 , * V_9 , V_12 -> V_27 , 0 , 0 , 0x9 ) ;
break;
default:
F_4 ( V_10 -> V_28 ,
L_14 ,
V_29 , F_1 ( V_12 -> V_24 ) ) ;
return - V_30 ;
}
( * V_9 ) -> V_56 = V_13 ;
F_11 ( V_10 -> V_28 ,
L_15 ,
F_1 ( V_12 -> V_24 ) ) ;
return 0 ;
}
