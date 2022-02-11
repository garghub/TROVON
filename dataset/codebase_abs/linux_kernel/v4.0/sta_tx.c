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
F_3 ( V_6 -> V_19 , L_1 , V_4 -> V_18 ) ;
V_10 -> V_20 = - 1 ;
return V_4 -> V_21 ;
}
F_4 ( F_5 ( V_4 ) < V_22 ) ;
V_12 = F_6 ( V_4 ) ? V_23 : 0 ;
V_11 = ( ( void * ) V_4 -> V_21 - ( sizeof( * V_8 ) + V_14 ) -
NULL ) & ( V_24 - 1 ) ;
F_7 ( V_4 , sizeof( * V_8 ) + V_11 ) ;
V_8 = (struct V_7 * ) V_4 -> V_21 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_25 = V_2 -> V_25 ;
V_8 -> V_26 = V_2 -> V_26 ;
V_8 -> V_27 = F_8 ( ( T_1 ) ( V_4 -> V_18 -
( sizeof( struct V_7 ) +
V_11 ) ) ) ;
V_8 -> V_28 = ( V_29 ) V_4 -> V_28 ;
V_8 -> V_30 =
F_9 ( V_2 , V_4 ) ;
if ( V_10 -> V_31 & V_32 ||
V_10 -> V_31 & V_33 ) {
V_8 -> V_34 = V_10 -> V_35 ;
V_8 -> V_31 |= V_36 ;
}
if ( V_8 -> V_28 <
F_10 ( V_2 -> V_37 . V_38 ) )
V_8 -> V_39 =
F_11 ( V_2 -> V_37 . V_38 [ V_8 ->
V_28 ] ) ;
if ( V_6 -> V_40 ) {
if ( F_12 ( V_2 ) ) {
V_6 -> V_41 = true ;
V_8 -> V_31 =
V_42 ;
}
}
if ( V_10 -> V_31 & V_43 )
V_8 -> V_31 |= V_44 ;
V_13 = sizeof( struct V_7 ) + V_11 ;
if ( V_12 == V_23 ) {
V_8 -> V_45 = F_8 ( V_12 ) ;
V_13 += V_46 ;
}
V_8 -> V_47 = F_8 ( V_13 ) ;
F_7 ( V_4 , V_14 ) ;
if ( ! V_8 -> V_39 )
V_8 -> V_39 = F_11 ( V_2 -> V_48 ) ;
return V_4 -> V_21 ;
}
int F_13 ( struct V_1 * V_2 , V_29 V_31 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_49 V_50 ;
#define F_14 64
T_2 V_51 = F_14 ;
struct V_3 * V_4 ;
int V_52 ;
struct V_9 * V_10 = NULL ;
if ( V_6 -> V_53 )
return - 1 ;
if ( ! V_2 -> V_54 )
return - 1 ;
if ( V_6 -> V_55 )
return - 1 ;
V_4 = F_15 ( V_51 ) ;
if ( ! V_4 )
return - 1 ;
V_10 = F_2 ( V_4 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_25 = V_2 -> V_25 ;
V_10 -> V_26 = V_2 -> V_26 ;
V_10 -> V_56 = V_51 - ( sizeof( struct V_7 ) + V_17 ) ;
F_16 ( V_4 , sizeof( struct V_7 ) + V_17 ) ;
F_7 ( V_4 , sizeof( struct V_7 ) ) ;
V_8 = (struct V_7 * ) V_4 -> V_21 ;
V_8 -> V_39 = F_11 ( V_2 -> V_48 ) ;
V_8 -> V_31 = V_31 ;
V_8 -> V_28 = V_57 ;
V_8 -> V_47 = F_8 ( sizeof( struct V_7 ) ) ;
V_8 -> V_25 = V_2 -> V_25 ;
V_8 -> V_26 = V_2 -> V_26 ;
if ( V_6 -> V_15 == V_16 ) {
V_52 = V_6 -> V_58 . V_59 ( V_6 , V_60 ,
V_4 , NULL ) ;
} else {
F_7 ( V_4 , V_17 ) ;
V_50 . V_61 = 0 ;
V_52 = V_6 -> V_58 . V_59 ( V_6 , V_62 ,
V_4 , & V_50 ) ;
}
switch ( V_52 ) {
case - V_63 :
F_17 ( V_4 ) ;
F_3 ( V_6 -> V_19 , L_2 ,
V_64 , V_52 ) ;
V_6 -> V_65 . V_66 ++ ;
break;
case - 1 :
V_6 -> V_55 = false ;
F_17 ( V_4 ) ;
F_3 ( V_6 -> V_19 , L_2 ,
V_64 , V_52 ) ;
V_6 -> V_65 . V_66 ++ ;
break;
case 0 :
F_17 ( V_4 ) ;
F_18 ( V_6 -> V_19 , L_3 ,
V_64 ) ;
V_6 -> V_41 = true ;
break;
case - V_67 :
V_6 -> V_41 = true ;
break;
default:
break;
}
return V_52 ;
}
V_29
F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_29 V_52 = false ;
if ( ! V_6 -> V_68 . V_69 )
return V_52 ;
if ( F_19 ( V_6 ) )
V_52 = true ;
if ( V_52 && ! V_6 -> V_70 && ! V_6 -> V_71 &&
! F_20 ( V_6 ) ) {
V_6 -> V_72 = false ;
V_52 = true ;
} else {
V_52 = false ;
V_6 -> V_72 = true ;
}
return V_52 ;
}
