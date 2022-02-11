int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 , V_6 ;
T_1 V_7 = V_4 -> V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
T_2 * V_15 ;
struct V_16 * V_17 ;
T_3 V_18 ;
switch ( V_7 ) {
case V_19 :
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_12 = (struct V_11 * )
( V_4 -> V_20 + V_21 ) ;
if ( F_2 ( V_12 -> type ) == V_22 ) {
V_5 = - 1 ;
if ( F_3 ( V_12 -> V_23 ) )
V_5 = 0 ;
else if ( F_4 ( V_12 -> V_23 ) )
V_5 = V_24 ;
if ( V_5 != - 1 ) {
V_10 . V_25 = V_26 ;
V_10 . V_27 = & V_12 -> V_28 [ V_5 ] ;
V_5 = ( T_2 * ) V_10 . V_27 -
( T_2 * ) & V_12 -> V_23 ;
V_10 . V_29 =
F_2 ( V_12 -> V_5 ) - ( T_3 ) V_5 ;
}
}
F_5 ( V_2 -> V_30 , V_12 -> V_31 , & V_10 ,
V_32 ) ;
V_14 = F_6 ( V_2 , V_12 -> V_31 ) ;
if ( ! V_14 ) {
F_7 ( V_4 -> V_33 ,
L_1 ) ;
return - 1 ;
}
if ( ! V_2 -> V_34 )
break;
F_8 ( V_2 , V_10 . V_27 ,
V_10 . V_29 , V_14 ) ;
for ( V_6 = 0 ; V_6 < V_35 ; V_6 ++ ) {
if ( V_14 -> V_36 )
V_14 -> V_37 [ V_6 ] =
V_2 -> V_38 [ V_6 ] . V_39 ;
else
V_14 -> V_37 [ V_6 ] = V_40 ;
}
memset ( V_14 -> V_41 , 0xff , sizeof( V_14 -> V_41 ) ) ;
break;
case V_42 :
V_15 = V_4 -> V_20 +
V_21 ;
F_9 ( V_2 -> V_30 , V_15 , V_32 ) ;
if ( V_2 -> V_34 ) {
F_10 ( V_2 , V_15 ) ;
F_11 ( V_2 , V_15 ) ;
}
F_12 ( V_2 , V_15 ) ;
break;
case V_43 :
V_2 -> V_44 = false ;
if ( F_13 ( V_2 -> V_30 ) )
F_14 ( V_2 -> V_30 ) ;
F_15 ( V_2 -> V_30 , V_4 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
break;
case V_45 :
V_2 -> V_44 = true ;
if ( ! F_13 ( V_2 -> V_30 ) )
F_18 ( V_2 -> V_30 ) ;
F_19 ( V_2 -> V_30 , V_4 ) ;
break;
case V_46 :
F_20 ( V_4 -> V_33 , L_2 , V_7 ) ;
memcpy ( V_2 -> V_30 -> V_47 , V_4 -> V_20 + 2 ,
V_24 ) ;
break;
case V_48 :
F_20 ( V_4 -> V_33 , L_2 , V_7 ) ;
break;
case V_49 :
V_18 = F_2 ( * ( V_50 * ) V_4 -> V_20 ) ;
F_20 ( V_4 -> V_33 , L_3 , V_18 ) ;
if ( V_2 -> V_44 ) {
V_4 -> V_51 =
F_21 ( T_3 , V_4 -> V_52 , V_18 ) ;
F_20 ( V_4 -> V_33 , L_4 ,
V_4 -> V_51 ) ;
}
break;
case V_53 :
F_20 ( V_4 -> V_33 , L_5 ) ;
if ( V_2 -> V_44 )
F_22 ( V_2 , V_54 ,
V_55 , 0 ,
V_4 -> V_20 , false ) ;
break;
case V_56 :
F_20 ( V_4 -> V_33 , L_6 ) ;
if ( V_2 -> V_44 )
F_23 ( V_2 , V_4 -> V_20 ) ;
break;
case V_57 :
F_20 ( V_4 -> V_33 , L_7 ) ;
if ( V_2 -> V_44 ) {
V_17 = ( void * ) V_4 -> V_20 ;
F_24 ( V_2 , V_17 ) ;
}
break;
case V_58 :
F_20 ( V_4 -> V_33 , L_8 ) ;
if ( V_4 -> V_59 )
return F_25 ( V_2 ,
V_4 -> V_60 -> V_28 ) ;
break;
default:
F_20 ( V_4 -> V_33 , L_9 ,
V_7 ) ;
break;
}
return 0 ;
}
void F_26 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
if ( V_2 -> V_34 && V_14 -> V_36 ) {
F_10 ( V_2 , V_14 -> V_61 ) ;
F_11 ( V_2 , V_14 -> V_61 ) ;
}
F_12 ( V_2 , V_14 -> V_61 ) ;
return;
}
