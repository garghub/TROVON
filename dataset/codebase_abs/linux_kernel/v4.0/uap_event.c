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
V_10 . V_25 = & V_12 -> V_26 [ V_5 ] ;
V_5 = ( T_2 * ) V_10 . V_25 -
( T_2 * ) & V_12 -> V_23 ;
V_10 . V_27 =
F_2 ( V_12 -> V_5 ) - ( T_3 ) V_5 ;
}
}
F_5 ( V_2 -> V_28 , V_12 -> V_29 , & V_10 ,
V_30 ) ;
V_14 = F_6 ( V_2 , V_12 -> V_29 ) ;
if ( ! V_14 ) {
F_7 ( V_4 -> V_31 ,
L_1 ) ;
return - 1 ;
}
if ( ! V_2 -> V_32 )
break;
F_8 ( V_2 , V_10 . V_25 ,
V_10 . V_27 , V_14 ) ;
for ( V_6 = 0 ; V_6 < V_33 ; V_6 ++ ) {
if ( V_14 -> V_34 )
V_14 -> V_35 [ V_6 ] =
V_2 -> V_36 [ V_6 ] . V_37 ;
else
V_14 -> V_35 [ V_6 ] = V_38 ;
}
memset ( V_14 -> V_39 , 0xff , sizeof( V_14 -> V_39 ) ) ;
break;
case V_40 :
V_15 = V_4 -> V_20 +
V_21 ;
F_9 ( V_2 -> V_28 , V_15 , V_30 ) ;
if ( V_2 -> V_32 ) {
F_10 ( V_2 , V_15 ) ;
F_11 ( V_2 , V_15 ) ;
}
F_12 ( V_2 , V_15 ) ;
F_13 ( V_2 , V_15 ) ;
break;
case V_41 :
V_2 -> V_42 = false ;
if ( F_14 ( V_2 -> V_28 ) )
F_15 ( V_2 -> V_28 ) ;
F_16 ( V_2 -> V_28 , V_4 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
break;
case V_43 :
V_2 -> V_42 = true ;
if ( ! F_14 ( V_2 -> V_28 ) )
F_19 ( V_2 -> V_28 ) ;
F_20 ( V_2 -> V_28 , V_4 ) ;
break;
case V_44 :
F_21 ( V_4 -> V_31 , L_2 , V_7 ) ;
memcpy ( V_2 -> V_28 -> V_45 , V_4 -> V_20 + 2 ,
V_24 ) ;
if ( V_2 -> V_46 )
F_22 ( V_2 ) ;
break;
case V_47 :
F_21 ( V_4 -> V_31 , L_2 , V_7 ) ;
break;
case V_48 :
V_18 = F_2 ( * ( V_49 * ) V_4 -> V_20 ) ;
F_21 ( V_4 -> V_31 , L_3 , V_18 ) ;
if ( V_2 -> V_42 ) {
V_4 -> V_50 =
F_23 ( T_3 , V_4 -> V_51 , V_18 ) ;
F_21 ( V_4 -> V_31 , L_4 ,
V_4 -> V_50 ) ;
}
break;
case V_52 :
F_21 ( V_4 -> V_31 , L_5 ) ;
if ( V_2 -> V_42 )
F_24 ( V_2 , V_53 ,
V_54 , 0 ,
V_4 -> V_20 , false ) ;
break;
case V_55 :
F_21 ( V_4 -> V_31 , L_6 ) ;
if ( V_2 -> V_42 )
F_25 ( V_2 , V_4 -> V_20 ) ;
break;
case V_56 :
F_21 ( V_4 -> V_31 , L_7 ) ;
if ( V_2 -> V_42 ) {
V_17 = ( void * ) V_4 -> V_20 ;
F_26 ( V_2 , V_17 ) ;
}
break;
case V_57 :
F_21 ( V_4 -> V_31 , L_8 ) ;
if ( V_4 -> V_58 )
return F_27 ( V_2 ,
V_4 -> V_59 -> V_26 ) ;
break;
case V_60 :
F_21 ( V_4 -> V_31 , L_9 ) ;
F_28 ( V_2 , V_4 -> V_20 ) ;
break;
case V_61 :
F_21 ( V_4 -> V_31 , L_10 ) ;
V_4 -> V_62 = V_63 ;
F_29 ( V_4 ) ;
break;
case V_64 :
F_21 ( V_4 -> V_31 , L_11 ) ;
if ( ! V_4 -> V_65 &&
V_2 -> V_42 && V_4 -> V_66 . V_67 ) {
V_4 -> V_65 = true ;
F_21 ( V_4 -> V_31 ,
L_12 ) ;
}
V_4 -> V_68 = false ;
if ( V_4 -> V_65 && V_4 -> V_69 ) {
if ( F_30 ( V_2 ) ) {
if ( V_4 -> V_70 ) {
V_4 -> V_62 = V_71 ;
V_4 -> V_72 = false ;
V_4 -> V_73 = false ;
break;
}
if ( ! F_31
( V_2 ,
V_74 |
V_75 ) )
V_4 -> V_62 =
V_76 ;
return 0 ;
}
}
V_4 -> V_62 = V_71 ;
V_4 -> V_72 = false ;
V_4 -> V_73 = false ;
break;
case V_77 :
F_21 ( V_4 -> V_31 , L_13 ) ;
F_32 ( V_2 , V_4 -> V_59 ) ;
break;
case V_78 :
F_21 ( V_4 -> V_31 , L_14 ) ;
F_33 ( V_2 , V_4 -> V_59 ) ;
break;
default:
F_21 ( V_4 -> V_31 , L_15 ,
V_7 ) ;
break;
}
return 0 ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
if ( V_2 -> V_32 && V_14 -> V_34 ) {
F_10 ( V_2 , V_14 -> V_79 ) ;
F_11 ( V_2 , V_14 -> V_79 ) ;
}
F_13 ( V_2 , V_14 -> V_79 ) ;
return;
}
