static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , union V_5 * V_6 )
{
union V_7 * V_8 = & V_4 -> V_9 ;
memset ( V_6 , 0 , sizeof( V_4 -> V_6 ) ) ;
memset ( V_8 , 0 , sizeof( V_4 -> V_9 ) ) ;
V_6 -> V_4 . V_10 = 0 ;
V_6 -> V_4 . V_11 = 1 ;
V_6 -> V_4 . V_12 = 1 ;
if ( V_2 -> V_13 == V_14 ) {
V_6 -> V_4 . V_15 = 1 ;
V_6 -> V_4 . V_12 = 0 ;
}
V_6 -> V_4 . V_16 = V_2 -> V_17 ;
V_6 -> V_4 . V_18 = V_2 -> V_19 ;
V_6 -> V_4 . V_20 = V_2 -> V_21 ;
V_6 -> V_4 . V_22 = V_2 -> V_23 ;
V_6 -> V_4 . V_24 = 0 ;
V_6 -> V_4 . V_25 . V_4 . V_26 = F_2 ( V_2 -> V_27 ) ;
V_6 -> V_4 . V_28 . V_4 . V_29 = ( V_2 -> V_30 +
V_2 -> V_23 ) ;
V_6 -> V_4 . V_31 = 0 ;
V_6 -> V_4 . V_32 . V_4 . V_26 = F_2 ( V_2 -> V_33 ) ;
V_6 -> V_4 . V_34 . V_4 . V_29 = V_2 -> V_35 ;
V_6 -> V_4 . V_36 = V_2 -> V_35 ;
V_6 -> V_4 . V_37 . V_4 . V_26 = F_2 ( V_8 ) ;
V_8 -> V_4 . V_38 = 0 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_39 * V_40 )
{
union V_5 * V_6 = & V_4 -> V_6 ;
union V_7 * V_8 = & V_4 -> V_9 ;
T_1 V_41 ;
F_1 ( V_2 , V_4 , V_6 ) ;
F_4 ( V_2 -> V_30 , & V_40 -> V_42 . V_43 ) ;
V_41 = F_5 ( V_6 , V_40 ) ;
F_6 ( & V_40 -> V_42 . V_44 ) ;
while ( ! V_8 -> V_4 . V_38 )
continue;
F_6 ( & V_40 -> V_42 . V_45 ) ;
V_2 -> V_38 = V_8 -> V_4 . V_38 ;
switch ( V_2 -> V_38 ) {
case V_46 :
F_7 ( L_1 ) ;
return V_47 ;
case V_48 :
F_7 ( L_2 ) ;
F_8 ( V_40 , V_41 ) ;
break;
case V_49 :
F_7 ( L_3 ) ;
return V_47 ;
default:
F_9 ( L_4 , V_2 -> V_38 ) ;
return V_47 ;
}
switch ( V_2 -> V_50 ) {
case V_51 :
F_7 ( L_5 , V_2 -> V_50 ) ;
V_2 -> V_21 = V_8 -> V_4 . V_52 ;
break;
case V_53 :
F_7 ( L_6 , V_2 -> V_50 ) ;
V_2 -> V_21 = V_8 -> V_4 . V_52 ;
break;
case V_54 :
F_7 ( L_7 , V_2 -> V_50 ) ;
V_2 -> V_21 = V_8 -> V_4 . V_55 ;
break;
case V_56 :
F_7 ( L_8 , V_2 -> V_50 ) ;
break;
default:
F_9 ( L_9 , V_2 -> V_50 ) ;
}
F_4 ( V_8 -> V_4 . V_57 ,
& V_40 -> V_42 . V_58 ) ;
if ( V_2 -> V_35 < V_8 -> V_4 . V_57 ) {
F_9 ( L_10 ,
V_2 -> V_35 , V_8 -> V_4 . V_57 ) ;
V_2 -> V_35 = 0 ;
} else {
V_2 -> V_35 = V_8 -> V_4 . V_57 ;
}
return 0 ;
}
