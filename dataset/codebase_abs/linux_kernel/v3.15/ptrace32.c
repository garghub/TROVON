long F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
int V_6 = V_4 ;
int V_7 = V_5 ;
int V_8 ;
switch ( V_3 ) {
case V_9 :
case V_10 : {
T_3 V_11 ;
int V_12 ;
T_3 T_4 * V_13 ;
V_8 = - V_14 ;
if ( F_2 ( V_13 , ( T_3 T_4 * T_4 * ) ( unsigned long ) V_6 ) != 0 )
break;
V_12 = F_3 ( V_2 , ( V_15 ) V_13 , & V_11 ,
sizeof( V_11 ) , 0 ) ;
if ( V_12 != sizeof( V_11 ) )
break;
V_8 = F_4 ( V_11 , ( T_3 T_4 * ) ( unsigned long ) V_7 ) ;
break;
}
case V_16 : {
struct V_17 * V_18 ;
union V_19 * V_20 ;
unsigned int V_11 ;
V_18 = F_5 ( V_2 ) ;
V_8 = 0 ;
switch ( V_6 ) {
case 0 ... 31 :
V_11 = V_18 -> V_18 [ V_6 ] ;
break;
case V_21 ... V_21 + 31 :
if ( ! F_6 ( V_2 ) ) {
V_11 = - 1 ;
break;
}
V_20 = F_7 ( V_2 ) ;
if ( F_8 ( V_22 ) ) {
V_11 = F_9 ( & V_20 [ ( V_6 & ~ 1 ) - V_21 ] ,
V_6 & 1 ) ;
break;
}
V_11 = F_9 ( & V_20 [ V_6 - V_21 ] , 0 ) ;
break;
case V_23 :
V_11 = V_18 -> V_24 ;
break;
case V_25 :
V_11 = V_18 -> V_26 ;
break;
case V_27 :
V_11 = V_18 -> V_28 ;
break;
case V_29 :
V_11 = V_18 -> V_30 ;
break;
case V_31 :
V_11 = V_18 -> V_32 ;
break;
case V_33 :
V_11 = V_2 -> V_34 . V_35 . V_36 ;
break;
case V_37 :
V_11 = V_38 . V_39 ;
break;
case V_40 ... V_40 + 5 : {
T_5 * V_41 ;
if ( ! V_42 ) {
V_11 = 0 ;
V_8 = - V_14 ;
goto V_43;
}
V_41 = F_10 ( V_2 ) ;
V_11 = ( unsigned long ) ( V_41 [ V_6 - V_40 ] ) ;
break;
}
case V_44 :
if ( ! V_42 ) {
V_11 = 0 ;
V_8 = - V_14 ;
goto V_43;
}
V_11 = V_2 -> V_34 . V_45 . V_46 ;
break;
default:
V_11 = 0 ;
V_8 = - V_14 ;
goto V_43;
}
V_8 = F_4 ( V_11 , ( unsigned T_4 * ) ( unsigned long ) V_7 ) ;
break;
}
case V_47 :
case V_48 : {
T_3 T_4 * V_13 ;
V_8 = - V_14 ;
if ( F_2 ( V_13 , ( T_3 T_4 * T_4 * ) ( unsigned long ) V_6 ) != 0 )
break;
V_8 = 0 ;
if ( F_3 ( V_2 , ( V_15 ) V_13 , & V_7 ,
sizeof( V_7 ) , 1 ) == sizeof( V_7 ) )
break;
V_8 = - V_14 ;
break;
}
case V_49 : {
struct V_17 * V_18 ;
V_8 = 0 ;
V_18 = F_5 ( V_2 ) ;
switch ( V_6 ) {
case 0 ... 31 :
V_18 -> V_18 [ V_6 ] = V_7 ;
break;
case V_21 ... V_21 + 31 : {
union V_19 * V_20 = F_7 ( V_2 ) ;
if ( ! F_6 ( V_2 ) ) {
memset ( & V_2 -> V_34 . V_35 , ~ 0 ,
sizeof( V_2 -> V_34 . V_35 ) ) ;
V_2 -> V_34 . V_35 . V_36 = 0 ;
}
if ( F_8 ( V_22 ) ) {
F_11 ( & V_20 [ ( V_6 & ~ 1 ) - V_21 ] ,
V_6 & 1 , V_7 ) ;
break;
}
F_12 ( & V_20 [ V_6 - V_21 ] , 0 , V_7 ) ;
break;
}
case V_23 :
V_18 -> V_24 = V_7 ;
break;
case V_29 :
V_18 -> V_30 = V_7 ;
break;
case V_31 :
V_18 -> V_32 = V_7 ;
break;
case V_33 :
V_2 -> V_34 . V_35 . V_36 = V_7 ;
break;
case V_40 ... V_40 + 5 : {
T_5 * V_41 ;
if ( ! V_42 ) {
V_8 = - V_14 ;
break;
}
V_41 = F_10 ( V_2 ) ;
V_41 [ V_6 - V_40 ] = V_7 ;
break;
}
case V_44 :
if ( ! V_42 ) {
V_8 = - V_14 ;
break;
}
V_2 -> V_34 . V_45 . V_46 = V_7 ;
break;
default:
V_8 = - V_14 ;
break;
}
break;
}
case V_50 :
V_8 = F_13 ( V_2 , ( V_51 T_4 * ) ( V_52 ) V_7 ) ;
break;
case V_53 :
V_8 = F_14 ( V_2 , ( V_51 T_4 * ) ( V_52 ) V_7 ) ;
break;
case V_54 :
V_8 = F_15 ( V_2 , ( V_55 T_4 * ) ( V_52 ) V_7 ) ;
break;
case V_56 :
V_8 = F_16 ( V_2 , ( V_55 T_4 * ) ( V_52 ) V_7 ) ;
break;
case V_57 :
V_8 = F_4 ( F_17 ( V_2 ) -> V_58 ,
( unsigned int T_4 * ) ( unsigned long ) V_7 ) ;
break;
case V_59 :
V_8 = F_4 ( F_17 ( V_2 ) -> V_58 ,
( unsigned long T_4 * ) ( unsigned long ) V_7 ) ;
break;
case V_60 :
V_8 = F_18 ( V_2 ,
(struct V_61 T_4 * ) ( unsigned long ) V_6 ) ;
break;
case V_62 :
V_8 = F_19 ( V_2 ,
(struct V_61 T_4 * ) ( unsigned long ) V_6 ) ;
break;
default:
V_8 = F_20 ( V_2 , V_3 , V_6 , V_7 ) ;
break;
}
V_43:
return V_8 ;
}
