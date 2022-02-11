void * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = F_2 ( V_4 ) ;
unsigned int V_11 ;
T_1 V_12 , V_13 ;
int V_14 = ( V_2 -> V_6 -> V_15 == V_16 ) ? 0 :
V_17 ;
if ( ! V_4 -> V_18 ) {
F_3 ( V_6 , ERROR ,
L_1 , V_4 -> V_18 ) ;
V_10 -> V_19 = - 1 ;
return V_4 -> V_20 ;
}
F_4 ( F_5 ( V_4 ) < V_21 ) ;
V_12 = F_6 ( V_4 ) ? V_22 : 0 ;
V_11 = ( ( void * ) V_4 -> V_20 - ( sizeof( * V_8 ) + V_14 ) -
NULL ) & ( V_23 - 1 ) ;
F_7 ( V_4 , sizeof( * V_8 ) + V_11 ) ;
V_8 = (struct V_7 * ) V_4 -> V_20 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_24 = V_2 -> V_24 ;
V_8 -> V_25 = V_2 -> V_25 ;
V_8 -> V_26 = F_8 ( ( T_1 ) ( V_4 -> V_18 -
( sizeof( struct V_7 ) +
V_11 ) ) ) ;
V_8 -> V_27 = ( V_28 ) V_4 -> V_27 ;
V_8 -> V_29 =
F_9 ( V_2 , V_4 ) ;
if ( V_10 -> V_30 & V_31 ||
V_10 -> V_30 & V_32 ) {
V_8 -> V_33 = V_10 -> V_34 ;
V_8 -> V_30 |= V_35 ;
}
if ( V_8 -> V_27 <
F_10 ( V_2 -> V_36 . V_37 ) )
V_8 -> V_38 =
F_11 ( V_2 -> V_36 . V_37 [ V_8 ->
V_27 ] ) ;
if ( V_6 -> V_39 ) {
if ( F_12 ( V_2 ) ) {
V_6 -> V_40 = true ;
V_8 -> V_30 =
V_41 ;
}
}
if ( V_10 -> V_30 & V_42 )
V_8 -> V_30 |= V_43 ;
V_13 = sizeof( struct V_7 ) + V_11 ;
if ( V_12 == V_22 ) {
V_8 -> V_44 = F_8 ( V_12 ) ;
V_13 += V_45 ;
}
V_8 -> V_46 = F_8 ( V_13 ) ;
F_7 ( V_4 , V_14 ) ;
if ( ! V_8 -> V_38 )
V_8 -> V_38 = F_11 ( V_2 -> V_47 ) ;
return V_4 -> V_20 ;
}
int F_13 ( struct V_1 * V_2 , V_28 V_30 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_48 V_49 ;
#define F_14 64
T_2 V_50 = F_14 ;
struct V_3 * V_4 ;
int V_51 ;
struct V_9 * V_10 = NULL ;
if ( V_6 -> V_52 )
return - 1 ;
if ( ! V_2 -> V_53 )
return - 1 ;
if ( V_6 -> V_54 )
return - 1 ;
V_4 = F_15 ( V_50 ) ;
if ( ! V_4 )
return - 1 ;
V_10 = F_2 ( V_4 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_24 = V_2 -> V_24 ;
V_10 -> V_25 = V_2 -> V_25 ;
V_10 -> V_55 = V_50 - ( sizeof( struct V_7 ) + V_17 ) ;
F_16 ( V_4 , sizeof( struct V_7 ) + V_17 ) ;
F_7 ( V_4 , sizeof( struct V_7 ) ) ;
V_8 = (struct V_7 * ) V_4 -> V_20 ;
V_8 -> V_38 = F_11 ( V_2 -> V_47 ) ;
V_8 -> V_30 = V_30 ;
V_8 -> V_27 = V_56 ;
V_8 -> V_46 = F_8 ( sizeof( struct V_7 ) ) ;
V_8 -> V_24 = V_2 -> V_24 ;
V_8 -> V_25 = V_2 -> V_25 ;
if ( V_6 -> V_15 == V_16 ) {
V_51 = V_6 -> V_57 . V_58 ( V_6 , V_59 ,
V_4 , NULL ) ;
} else {
F_7 ( V_4 , V_17 ) ;
V_49 . V_60 = 0 ;
V_51 = V_6 -> V_57 . V_58 ( V_6 , V_61 ,
V_4 , & V_49 ) ;
}
switch ( V_51 ) {
case - V_62 :
F_17 ( V_4 ) ;
F_3 ( V_6 , ERROR ,
L_2 ,
V_63 , V_51 ) ;
V_6 -> V_64 . V_65 ++ ;
break;
case - 1 :
V_6 -> V_54 = false ;
F_17 ( V_4 ) ;
F_3 ( V_6 , ERROR ,
L_2 ,
V_63 , V_51 ) ;
V_6 -> V_64 . V_65 ++ ;
break;
case 0 :
F_17 ( V_4 ) ;
F_3 ( V_6 , V_66 ,
L_3 ,
V_63 ) ;
V_6 -> V_40 = true ;
break;
case - V_67 :
V_6 -> V_40 = true ;
break;
default:
break;
}
return V_51 ;
}
V_28
F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_28 V_51 = false ;
if ( ! V_6 -> V_68 . V_69 )
return V_51 ;
if ( F_18 ( V_6 ) )
V_51 = true ;
if ( V_51 && ! V_6 -> V_70 && ! V_6 -> V_71 &&
! F_19 ( V_6 ) ) {
V_6 -> V_72 = false ;
V_51 = true ;
} else {
V_51 = false ;
V_6 -> V_72 = true ;
}
return V_51 ;
}
