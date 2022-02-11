int F_1 ( T_1 V_1 )
{
struct V_2 V_3 ;
memset ( & V_3 , 0 , sizeof( struct V_2 ) ) ;
V_3 . V_4 = V_5 ;
V_3 . V_6 = V_7 ;
switch ( V_8 -> V_9 -> V_10 ) {
case V_11 :
V_3 . V_12 = V_13 ;
break;
case V_14 :
V_3 . V_12 = V_15 ;
break;
case V_16 :
V_3 . V_12 = V_17 ;
break;
case V_18 :
V_3 . V_12 = V_19 ;
break;
case V_20 :
V_3 . V_12 = V_21 ;
break;
case V_22 :
V_3 . V_12 = V_23 ;
break;
case V_24 :
V_3 . V_12 = V_25 ;
break;
case V_26 :
V_3 . V_12 = V_27 ;
break;
case V_28 :
V_3 . V_12 = V_29 ;
break;
}
V_3 . V_30 = V_31 ;
V_3 . V_32 = V_33 ;
if ( F_2 ( ( void V_34 * ) V_1 , & V_3 , sizeof( V_3 ) ) )
return - V_35 ;
return 0 ;
}
int F_3 ( int V_36 , int V_37 , int V_38 )
{
int V_39 , V_40 = 0 ;
F_4 ( V_41 L_1 ) ;
if ( V_8 -> V_9 -> V_42 . V_43 !=
V_44 ) {
V_39 = F_5 () ;
if ( V_39 ) {
F_4 ( V_41 L_2 ) ;
if ( V_45 != V_46 ) {
V_47 = 1 ;
V_48 = 0 ;
V_49 = 0 ;
V_45 = V_46 ;
F_6 () ;
return V_45 ;
}
V_40 = 1 ;
} else
F_4 ( V_41 L_3 ) ;
}
if ( ( V_45 != V_50 ) && ( V_40 == 0 ) ) {
V_48 = 1 ;
V_47 = 0 ;
V_49 = 0 ;
V_45 = V_50 ;
F_6 () ;
return V_45 ;
}
return 0 ;
}
