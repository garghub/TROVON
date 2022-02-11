void * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = F_2 ( V_4 ) ;
unsigned int V_11 ;
T_1 V_12 , V_13 ;
int V_14 = V_6 -> V_15 ;
if ( ! V_4 -> V_16 ) {
F_3 ( V_6 , ERROR ,
L_1 , V_4 -> V_16 ) ;
V_10 -> V_17 = - 1 ;
return V_4 -> V_18 ;
}
F_4 ( F_5 ( V_4 ) < V_19 ) ;
V_12 = F_6 ( V_4 ) ? V_20 : 0 ;
V_11 = ( ( void * ) V_4 -> V_18 - ( sizeof( * V_8 ) + V_14 ) -
NULL ) & ( V_21 - 1 ) ;
F_7 ( V_4 , sizeof( * V_8 ) + V_11 ) ;
V_8 = (struct V_7 * ) V_4 -> V_18 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_22 = V_2 -> V_22 ;
V_8 -> V_23 = V_2 -> V_23 ;
V_8 -> V_24 = F_8 ( ( T_1 ) ( V_4 -> V_16 -
( sizeof( struct V_7 ) +
V_11 ) ) ) ;
V_8 -> V_25 = ( V_26 ) V_4 -> V_25 ;
V_8 -> V_27 =
F_9 ( V_2 , V_4 ) ;
if ( V_10 -> V_28 & V_29 ||
V_10 -> V_28 & V_30 ) {
V_8 -> V_31 = V_10 -> V_32 ;
V_8 -> V_28 |= V_33 ;
}
if ( V_8 -> V_25 <
F_10 ( V_2 -> V_34 . V_35 ) )
V_8 -> V_36 =
F_11 ( V_2 -> V_34 . V_35 [ V_8 ->
V_25 ] ) ;
if ( V_6 -> V_37 ) {
if ( F_12 ( V_2 ) ) {
V_6 -> V_38 = true ;
V_8 -> V_28 =
V_39 ;
}
}
if ( V_10 -> V_28 & V_40 )
V_8 -> V_28 |= V_41 ;
V_13 = sizeof( struct V_7 ) + V_11 ;
if ( V_12 == V_20 ) {
V_8 -> V_42 = F_8 ( V_12 ) ;
V_13 += V_43 ;
}
V_8 -> V_44 = F_8 ( V_13 ) ;
F_7 ( V_4 , V_14 ) ;
if ( ! V_8 -> V_36 )
V_8 -> V_36 = F_11 ( V_2 -> V_45 ) ;
return V_4 -> V_18 ;
}
int F_13 ( struct V_1 * V_2 , V_26 V_28 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_46 V_47 ;
#define F_14 64
T_2 V_48 = F_14 ;
struct V_3 * V_4 ;
int V_49 ;
struct V_9 * V_10 = NULL ;
if ( V_6 -> V_50 )
return - 1 ;
if ( ! V_2 -> V_51 )
return - 1 ;
if ( V_6 -> V_52 )
return - 1 ;
if ( V_6 -> V_53 . V_54 &&
! V_6 -> V_53 . V_54 ( V_2 ) )
return - 1 ;
V_4 = F_15 ( V_48 ) ;
if ( ! V_4 )
return - 1 ;
V_10 = F_2 ( V_4 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_22 = V_2 -> V_22 ;
V_10 -> V_23 = V_2 -> V_23 ;
V_10 -> V_55 = V_48 -
( sizeof( struct V_7 ) + V_6 -> V_15 ) ;
F_16 ( V_4 , sizeof( struct V_7 ) + V_6 -> V_15 ) ;
F_7 ( V_4 , sizeof( struct V_7 ) ) ;
V_8 = (struct V_7 * ) V_4 -> V_18 ;
V_8 -> V_36 = F_11 ( V_2 -> V_45 ) ;
V_8 -> V_28 = V_28 ;
V_8 -> V_25 = V_56 ;
V_8 -> V_44 = F_8 ( sizeof( struct V_7 ) ) ;
V_8 -> V_22 = V_2 -> V_22 ;
V_8 -> V_23 = V_2 -> V_23 ;
F_7 ( V_4 , V_6 -> V_15 ) ;
if ( V_6 -> V_57 == V_58 ) {
V_49 = V_6 -> V_53 . V_59 ( V_6 , V_2 -> V_60 ,
V_4 , NULL ) ;
} else {
V_47 . V_61 = 0 ;
V_49 = V_6 -> V_53 . V_59 ( V_6 , V_62 ,
V_4 , & V_47 ) ;
}
switch ( V_49 ) {
case - V_63 :
F_17 ( V_4 ) ;
F_3 ( V_6 , ERROR ,
L_2 ,
V_64 , V_49 ) ;
V_6 -> V_65 . V_66 ++ ;
break;
case - 1 :
F_17 ( V_4 ) ;
F_3 ( V_6 , ERROR ,
L_2 ,
V_64 , V_49 ) ;
V_6 -> V_65 . V_66 ++ ;
break;
case 0 :
F_17 ( V_4 ) ;
F_3 ( V_6 , V_67 ,
L_3 ,
V_64 ) ;
V_6 -> V_38 = true ;
break;
case - V_68 :
V_6 -> V_38 = true ;
break;
default:
break;
}
return V_49 ;
}
V_26
F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_26 V_49 = false ;
if ( ! V_6 -> V_69 . V_70 )
return V_49 ;
if ( F_18 ( V_6 ) )
V_49 = true ;
if ( V_49 && ! V_6 -> V_71 && ! V_6 -> V_72 &&
! F_19 ( V_6 ) ) {
V_6 -> V_73 = false ;
V_49 = true ;
} else {
V_49 = false ;
V_6 -> V_73 = true ;
}
return V_49 ;
}
