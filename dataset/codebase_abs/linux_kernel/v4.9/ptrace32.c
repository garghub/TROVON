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
sizeof( V_11 ) , V_16 ) ;
if ( V_12 != sizeof( V_11 ) )
break;
V_8 = F_4 ( V_11 , ( T_3 T_4 * ) ( unsigned long ) V_7 ) ;
break;
}
case V_17 : {
struct V_18 * V_19 ;
union V_20 * V_21 ;
unsigned int V_11 ;
V_19 = F_5 ( V_2 ) ;
V_8 = 0 ;
switch ( V_6 ) {
case 0 ... 31 :
V_11 = V_19 -> V_19 [ V_6 ] ;
break;
case V_22 ... V_22 + 31 :
if ( ! F_6 ( V_2 ) ) {
V_11 = - 1 ;
break;
}
V_21 = F_7 ( V_2 ) ;
if ( F_8 ( V_23 ) ) {
V_11 = F_9 ( & V_21 [ ( V_6 & ~ 1 ) - V_22 ] ,
V_6 & 1 ) ;
break;
}
V_11 = F_9 ( & V_21 [ V_6 - V_22 ] , 0 ) ;
break;
case V_24 :
V_11 = V_19 -> V_25 ;
break;
case V_26 :
V_11 = V_19 -> V_27 ;
break;
case V_28 :
V_11 = V_19 -> V_29 ;
break;
case V_30 :
V_11 = V_19 -> V_31 ;
break;
case V_32 :
V_11 = V_19 -> V_33 ;
break;
case V_34 :
V_11 = V_2 -> V_35 . V_36 . V_37 ;
break;
case V_38 :
V_11 = V_39 . V_40 ;
break;
case V_41 ... V_41 + 5 : {
T_5 * V_42 ;
if ( ! V_43 ) {
V_11 = 0 ;
V_8 = - V_14 ;
goto V_44;
}
V_42 = F_10 ( V_2 ) ;
V_11 = ( unsigned long ) ( V_42 [ V_6 - V_41 ] ) ;
break;
}
case V_45 :
if ( ! V_43 ) {
V_11 = 0 ;
V_8 = - V_14 ;
goto V_44;
}
V_11 = V_2 -> V_35 . V_46 . V_47 ;
break;
default:
V_11 = 0 ;
V_8 = - V_14 ;
goto V_44;
}
V_8 = F_4 ( V_11 , ( unsigned T_4 * ) ( unsigned long ) V_7 ) ;
break;
}
case V_48 :
case V_49 : {
T_3 T_4 * V_13 ;
V_8 = - V_14 ;
if ( F_2 ( V_13 , ( T_3 T_4 * T_4 * ) ( unsigned long ) V_6 ) != 0 )
break;
V_8 = 0 ;
if ( F_3 ( V_2 , ( V_15 ) V_13 , & V_7 ,
sizeof( V_7 ) ,
V_16 | V_50 ) == sizeof( V_7 ) )
break;
V_8 = - V_14 ;
break;
}
case V_51 : {
struct V_18 * V_19 ;
V_8 = 0 ;
V_19 = F_5 ( V_2 ) ;
switch ( V_6 ) {
case 0 ... 31 :
V_19 -> V_19 [ V_6 ] = V_7 ;
break;
case V_22 ... V_22 + 31 : {
union V_20 * V_21 = F_7 ( V_2 ) ;
if ( ! F_6 ( V_2 ) ) {
memset ( & V_2 -> V_35 . V_36 , ~ 0 ,
sizeof( V_2 -> V_35 . V_36 ) ) ;
V_2 -> V_35 . V_36 . V_37 = 0 ;
}
if ( F_8 ( V_23 ) ) {
F_11 ( & V_21 [ ( V_6 & ~ 1 ) - V_22 ] ,
V_6 & 1 , V_7 ) ;
break;
}
F_12 ( & V_21 [ V_6 - V_22 ] , 0 , V_7 ) ;
break;
}
case V_24 :
V_19 -> V_25 = V_7 ;
break;
case V_30 :
V_19 -> V_31 = V_7 ;
break;
case V_32 :
V_19 -> V_33 = V_7 ;
break;
case V_34 :
V_2 -> V_35 . V_36 . V_37 = V_7 ;
break;
case V_41 ... V_41 + 5 : {
T_5 * V_42 ;
if ( ! V_43 ) {
V_8 = - V_14 ;
break;
}
V_42 = F_10 ( V_2 ) ;
V_42 [ V_6 - V_41 ] = V_7 ;
break;
}
case V_45 :
if ( ! V_43 ) {
V_8 = - V_14 ;
break;
}
V_2 -> V_35 . V_46 . V_47 = V_7 ;
break;
default:
V_8 = - V_14 ;
break;
}
break;
}
case V_52 :
V_8 = F_13 ( V_2 ,
(struct V_53 T_4 * ) ( V_54 ) V_7 ) ;
break;
case V_55 :
V_8 = F_14 ( V_2 ,
(struct V_53 T_4 * ) ( V_54 ) V_7 ) ;
break;
case V_56 :
V_8 = F_15 ( V_2 , ( V_57 T_4 * ) ( V_54 ) V_7 ) ;
break;
case V_58 :
V_8 = F_16 ( V_2 , ( V_57 T_4 * ) ( V_54 ) V_7 ) ;
break;
case V_59 :
V_8 = F_4 ( F_17 ( V_2 ) -> V_60 ,
( unsigned int T_4 * ) ( unsigned long ) V_7 ) ;
break;
case V_61 :
V_8 = F_4 ( F_17 ( V_2 ) -> V_60 ,
( unsigned long T_4 * ) ( unsigned long ) V_7 ) ;
break;
case V_62 :
V_8 = F_18 ( V_2 ,
(struct V_63 T_4 * ) ( unsigned long ) V_6 ) ;
break;
case V_64 :
V_8 = F_19 ( V_2 ,
(struct V_63 T_4 * ) ( unsigned long ) V_6 ) ;
break;
default:
V_8 = F_20 ( V_2 , V_3 , V_6 , V_7 ) ;
break;
}
V_44:
return V_8 ;
}
