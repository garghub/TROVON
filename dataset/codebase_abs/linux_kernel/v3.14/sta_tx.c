void * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = F_2 ( V_4 ) ;
T_1 V_11 ;
T_2 V_12 , V_13 ;
if ( ! V_4 -> V_14 ) {
F_3 ( V_6 -> V_15 , L_1 , V_4 -> V_14 ) ;
V_10 -> V_16 = - 1 ;
return V_4 -> V_17 ;
}
V_12 = F_4 ( V_4 ) ? V_18 : 0 ;
V_11 = ( 4 - ( ( ( void * ) V_4 -> V_17 - NULL ) & 0x3 ) ) % 4 ;
F_5 ( F_6 ( V_4 ) < ( sizeof( * V_8 ) + V_19
+ V_11 ) ) ;
F_7 ( V_4 , sizeof( * V_8 ) + V_11 ) ;
V_8 = (struct V_7 * ) V_4 -> V_17 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_20 = V_2 -> V_20 ;
V_8 -> V_21 = V_2 -> V_21 ;
V_8 -> V_22 = F_8 ( ( T_2 ) ( V_4 -> V_14 -
( sizeof( struct V_7 )
+ V_11 ) ) ) ;
V_8 -> V_23 = ( T_1 ) V_4 -> V_23 ;
V_8 -> V_24 =
F_9 ( V_2 , V_4 ) ;
if ( V_8 -> V_23 <
F_10 ( V_2 -> V_25 . V_26 ) )
V_8 -> V_27 =
F_11 ( V_2 -> V_25 . V_26 [ V_8 ->
V_23 ] ) ;
if ( V_6 -> V_28 ) {
if ( F_12 ( V_2 ) ) {
V_6 -> V_29 = true ;
V_8 -> V_30 =
V_31 ;
}
}
V_13 = sizeof( struct V_7 ) + V_11 ;
if ( V_12 == V_18 ) {
V_8 -> V_32 = F_8 ( V_12 ) ;
V_13 += V_33 ;
}
V_8 -> V_34 = F_8 ( V_13 ) ;
F_7 ( V_4 , V_19 ) ;
if ( ! V_8 -> V_27 )
V_8 -> V_27 = F_11 ( V_2 -> V_35 ) ;
return V_4 -> V_17 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
#define F_14 64
T_3 V_36 = F_14 ;
struct V_3 * V_4 ;
int V_37 ;
struct V_9 * V_10 = NULL ;
if ( V_6 -> V_38 )
return - 1 ;
if ( ! V_2 -> V_39 )
return - 1 ;
if ( V_6 -> V_40 )
return - 1 ;
V_4 = F_15 ( V_36 ) ;
if ( ! V_4 )
return - 1 ;
V_10 = F_2 ( V_4 ) ;
V_10 -> V_20 = V_2 -> V_20 ;
V_10 -> V_21 = V_2 -> V_21 ;
V_10 -> V_41 = V_36 - ( sizeof( struct V_7 ) + V_19 ) ;
F_16 ( V_4 , sizeof( struct V_7 ) + V_19 ) ;
F_7 ( V_4 , sizeof( struct V_7 ) ) ;
V_8 = (struct V_7 * ) V_4 -> V_17 ;
V_8 -> V_27 = F_11 ( V_2 -> V_35 ) ;
V_8 -> V_30 = V_30 ;
V_8 -> V_23 = V_42 ;
V_8 -> V_34 = F_8 ( sizeof( struct V_7 ) ) ;
V_8 -> V_20 = V_2 -> V_20 ;
V_8 -> V_21 = V_2 -> V_21 ;
if ( V_6 -> V_43 == V_44 ) {
V_37 = V_6 -> V_45 . V_46 ( V_6 , V_47 ,
V_4 , NULL ) ;
} else {
F_7 ( V_4 , V_19 ) ;
V_37 = V_6 -> V_45 . V_46 ( V_6 , V_48 ,
V_4 , NULL ) ;
}
switch ( V_37 ) {
case - V_49 :
V_6 -> V_40 = true ;
case - 1 :
F_17 ( V_4 ) ;
F_3 ( V_6 -> V_15 , L_2 ,
V_50 , V_37 ) ;
V_6 -> V_51 . V_52 ++ ;
break;
case 0 :
F_17 ( V_4 ) ;
F_18 ( V_6 -> V_15 , L_3 ,
V_50 ) ;
V_6 -> V_29 = true ;
break;
case - V_53 :
break;
default:
break;
}
return V_37 ;
}
T_1
F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_37 = false ;
if ( ! V_6 -> V_54 . V_55 )
return V_37 ;
if ( F_19 ( V_6 ) )
V_37 = true ;
if ( V_37 && ! V_6 -> V_56 && ! V_6 -> V_57 &&
! F_20 ( V_6 ) ) {
V_6 -> V_58 = false ;
V_37 = true ;
} else {
V_37 = false ;
V_6 -> V_58 = true ;
}
return V_37 ;
}
