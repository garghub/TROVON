void * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = F_2 ( V_4 ) ;
T_1 V_11 ;
if ( ! V_4 -> V_12 ) {
F_3 ( V_6 -> V_13 , L_1 , V_4 -> V_12 ) ;
V_10 -> V_14 = - 1 ;
return V_4 -> V_15 ;
}
V_11 = ( 4 - ( ( ( void * ) V_4 -> V_15 - NULL ) & 0x3 ) ) % 4 ;
F_4 ( F_5 ( V_4 ) < ( sizeof( * V_8 ) + V_16
+ V_11 ) ) ;
F_6 ( V_4 , sizeof( * V_8 ) + V_11 ) ;
V_8 = (struct V_7 * ) V_4 -> V_15 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_17 = V_2 -> V_17 ;
V_8 -> V_18 = V_2 -> V_18 ;
V_8 -> V_19 = F_7 ( ( V_20 ) ( V_4 -> V_12 -
( sizeof( struct V_7 )
+ V_11 ) ) ) ;
V_8 -> V_21 = ( T_1 ) V_4 -> V_21 ;
V_8 -> V_22 =
F_8 ( V_2 , V_4 ) ;
if ( V_8 -> V_21 <
F_9 ( V_2 -> V_23 . V_24 ) )
V_8 -> V_25 =
F_10 ( V_2 -> V_23 . V_24 [ V_8 ->
V_21 ] ) ;
if ( V_6 -> V_26 ) {
if ( F_11 ( V_2 ) ) {
V_6 -> V_27 = true ;
V_8 -> V_28 =
V_29 ;
}
}
V_8 -> V_30 = F_7 ( sizeof( struct V_7 ) + V_11 ) ;
F_6 ( V_4 , V_16 ) ;
if ( ! V_8 -> V_25 )
V_8 -> V_25 = F_10 ( V_2 -> V_31 ) ;
return V_4 -> V_15 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
#define F_13 64
T_2 V_32 = F_13 ;
struct V_3 * V_4 ;
int V_33 ;
struct V_9 * V_10 = NULL ;
if ( V_6 -> V_34 )
return - 1 ;
if ( ! V_2 -> V_35 )
return - 1 ;
if ( V_6 -> V_36 )
return - 1 ;
V_4 = F_14 ( V_32 ) ;
if ( ! V_4 )
return - 1 ;
V_10 = F_2 ( V_4 ) ;
V_10 -> V_17 = V_2 -> V_17 ;
V_10 -> V_18 = V_2 -> V_18 ;
F_15 ( V_4 , sizeof( struct V_7 ) + V_16 ) ;
F_6 ( V_4 , sizeof( struct V_7 ) ) ;
V_8 = (struct V_7 * ) V_4 -> V_15 ;
V_8 -> V_25 = F_10 ( V_2 -> V_31 ) ;
V_8 -> V_28 = V_28 ;
V_8 -> V_21 = V_37 ;
V_8 -> V_30 = F_7 ( sizeof( struct V_7 ) ) ;
V_8 -> V_17 = V_2 -> V_17 ;
V_8 -> V_18 = V_2 -> V_18 ;
if ( V_6 -> V_38 == V_39 ) {
V_33 = V_6 -> V_40 . V_41 ( V_6 , V_42 ,
V_4 , NULL ) ;
} else {
F_6 ( V_4 , V_16 ) ;
V_33 = V_6 -> V_40 . V_41 ( V_6 , V_43 ,
V_4 , NULL ) ;
}
switch ( V_33 ) {
case - V_44 :
V_6 -> V_36 = true ;
case - 1 :
F_16 ( V_4 ) ;
F_3 ( V_6 -> V_13 , L_2 ,
V_45 , V_33 ) ;
V_6 -> V_46 . V_47 ++ ;
break;
case 0 :
F_16 ( V_4 ) ;
F_17 ( V_6 -> V_13 , L_3 ,
V_45 ) ;
V_6 -> V_27 = true ;
break;
case - V_48 :
break;
default:
break;
}
return V_33 ;
}
T_1
F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_33 = false ;
if ( ! V_6 -> V_49 . V_50 )
return V_33 ;
if ( F_18 ( V_6 ) )
V_33 = true ;
if ( V_33 && ! V_6 -> V_51 && ! V_6 -> V_52 &&
! F_19 ( V_6 ) ) {
V_6 -> V_53 = false ;
V_33 = true ;
} else {
V_33 = false ;
V_6 -> V_53 = true ;
}
return V_33 ;
}
