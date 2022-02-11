static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , union V_5 * V_6 )
{
union V_7 * V_8 = & V_4 -> V_9 ;
memset ( V_6 , 0 , sizeof( V_4 -> V_6 ) ) ;
memset ( V_8 , 0 , sizeof( V_4 -> V_9 ) ) ;
V_6 -> V_4 . V_10 = 0 ;
V_6 -> V_4 . V_11 = 0 ;
V_6 -> V_4 . V_12 = 0 ;
V_6 -> V_4 . V_13 = 1 ;
if ( V_2 -> V_14 == 0 )
V_6 -> V_4 . V_15 = 0 ;
else
V_6 -> V_4 . V_15 = 1 ;
V_6 -> V_4 . V_16 = 1 ;
V_6 -> V_4 . V_17 = V_2 -> V_18 ;
V_6 -> V_4 . V_19 = V_2 -> V_20 ;
V_6 -> V_4 . V_21 = 0 ;
V_6 -> V_4 . V_22 = 0 ;
V_6 -> V_4 . V_23 . V_4 . V_24 = F_2 ( V_2 -> V_25 ) ;
V_6 -> V_4 . V_26 . V_4 . V_27 = V_2 -> V_28 ;
V_6 -> V_4 . V_29 = V_2 -> V_28 ;
F_3 ( L_1 ) ;
V_6 -> V_4 . V_30 = 0 ;
V_6 -> V_4 . V_31 . V_4 . V_24 = F_2 ( ( V_32 * ) V_2 -> V_33 ) ;
V_6 -> V_4 . V_34 . V_4 . V_27 = V_2 -> V_35 ;
V_6 -> V_4 . V_36 . V_4 . V_24 = F_2 ( V_8 ) ;
V_8 -> V_4 . V_37 = 0 ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_38 * V_39 )
{
union V_5 * V_6 = & V_4 -> V_6 ;
union V_7 * V_8 = & V_4 -> V_9 ;
T_1 V_40 ;
F_1 ( V_2 , V_4 , V_6 ) ;
F_5 ( V_2 -> V_35 , & V_39 -> V_41 . V_42 ) ;
V_40 = F_6 ( V_6 , V_39 ) ;
F_7 ( & V_39 -> V_41 . V_43 ) ;
while ( ! V_8 -> V_4 . V_37 )
continue;
F_7 ( & V_39 -> V_41 . V_44 ) ;
V_2 -> V_37 = V_8 -> V_4 . V_37 ;
switch ( V_2 -> V_37 ) {
case V_45 :
F_3 ( L_2 ) ;
return V_46 ;
case V_47 :
F_3 ( L_3 ) ;
break;
case V_48 :
F_3 ( L_4 ) ;
break;
default:
F_3 ( L_5 , V_2 -> V_37 ) ;
F_7 ( & V_39 -> V_41 . V_49 ) ;
F_8 ( V_39 , V_40 ) ;
return V_46 ;
}
F_8 ( V_39 , V_40 ) ;
if ( ( V_2 -> V_18 == 3 ) && ( V_2 -> V_50 == 4 ) &&
( V_2 -> V_37 != V_48 ) )
V_8 -> V_4 . V_16 = 1 ;
V_2 -> V_20 = V_8 -> V_4 . V_51 ;
F_5 ( V_8 -> V_4 . V_52 ,
& V_39 -> V_41 . V_53 ) ;
if ( V_2 -> V_28 < V_8 -> V_4 . V_52 ) {
F_9 ( L_6 ,
V_2 -> V_28 , V_8 -> V_4 . V_52 ) ;
V_2 -> V_28 = 0 ;
} else {
V_2 -> V_28 = V_8 -> V_4 . V_52 ;
}
V_2 -> V_54 = V_8 -> V_4 . V_55 ;
V_2 -> V_56 = V_8 -> V_4 . V_57 ;
V_2 -> V_58 = V_8 -> V_4 . V_16 ;
if ( V_2 -> V_58 ) {
switch ( V_2 -> V_59 ) {
case V_60 :
F_3 ( L_7 , V_2 -> V_59 ) ;
V_2 -> V_20 = V_8 -> V_4 . V_51 ;
break;
case V_61 :
F_3 ( L_8 , V_2 -> V_59 ) ;
V_2 -> V_20 = V_8 -> V_4 . V_51 ;
break;
case V_62 :
F_3 ( L_9 , V_2 -> V_59 ) ;
V_2 -> V_20 = V_8 -> V_4 . V_63 ;
break;
case V_64 :
F_3 ( L_10 , V_2 -> V_59 ) ;
break;
default:
F_9 ( L_11 , V_2 -> V_59 ) ;
}
}
return 0 ;
}
