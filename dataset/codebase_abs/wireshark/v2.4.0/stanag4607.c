static T_1 F_1 ( T_2 V_1 )
{
#define F_2 0x3231
#define F_3 0x3330
if ( ( V_1 != F_2 ) &&
( V_1 != F_3 ) )
return FALSE ;
return TRUE ;
}
static T_1 F_4 ( T_3 * V_2 , T_4 V_3 , struct V_4 * V_5 ,
T_5 * V_6 , int * V_7 , T_6 * * V_8 )
{
T_7 * V_9 = ( T_7 * ) V_2 -> V_10 ;
T_8 V_11 , V_12 , V_13 ;
T_9 V_14 = 0 ;
T_10 V_15 [ V_16 + V_17 ] ;
T_8 V_18 ;
* V_7 = 0 ;
if ( ! F_5 ( V_3 , V_15 , sizeof V_15 , V_7 , V_8 ) )
return FALSE ;
V_14 += sizeof V_15 ;
if ( ! F_1 ( F_6 ( & V_15 [ 0 ] ) ) ) {
* V_7 = V_19 ;
* V_8 = F_7 ( L_1 ) ;
return FALSE ;
}
V_5 -> V_20 = V_21 ;
V_18 = F_8 ( & V_15 [ 2 ] ) ;
if ( V_18 > V_22 ) {
* V_7 = V_19 ;
* V_8 = F_9 ( L_2 V_23 L_3
L_4 , V_18 , V_22 ) ;
return FALSE ;
}
if ( V_18 < V_16 + V_17 ) {
* V_7 = V_19 ;
* V_8 = F_9 ( L_2 V_23 L_3
L_5 , V_18 , V_16 + V_17 ) ;
return FALSE ;
}
V_5 -> V_24 = V_18 ;
V_5 -> V_25 = V_18 ;
V_5 -> V_26 = V_27 ;
V_5 -> V_28 . V_12 = V_9 -> V_29 ;
V_5 -> V_28 . V_13 = 0 ;
V_11 = 0 ;
#define F_10 1
#define F_11 2
#define F_12 5
#define F_13 13
if ( F_10 == V_15 [ 32 ] ) {
T_10 V_30 [ 39 ] ;
struct V_31 V_31 ;
if ( ! F_14 ( V_3 , & V_30 , sizeof V_30 , V_7 , V_8 ) )
return FALSE ;
V_14 += sizeof V_30 ;
V_31 . V_32 = F_6 ( & V_30 [ 35 ] ) - 1900 ;
V_31 . V_33 = V_30 [ 37 ] - 1 ;
V_31 . V_34 = V_30 [ 38 ] ;
V_31 . V_35 = 0 ;
V_31 . V_36 = 0 ;
V_31 . V_37 = 0 ;
V_31 . V_38 = - 1 ;
V_9 -> V_29 = mktime ( & V_31 ) ;
V_5 -> V_28 . V_12 = V_9 -> V_29 ;
}
else if ( F_13 == V_15 [ 32 ] ) {
if ( ! F_14 ( V_3 , & V_11 , sizeof V_11 , V_7 , V_8 ) )
return FALSE ;
V_14 += sizeof V_11 ;
V_11 = F_15 ( V_11 ) ;
}
else if ( F_11 == V_15 [ 32 ] ) {
T_10 V_39 [ 19 ] ;
if ( ! F_14 ( V_3 , & V_39 , sizeof V_39 , V_7 , V_8 ) )
return FALSE ;
V_14 += sizeof V_39 ;
V_11 = F_8 ( & V_39 [ 15 ] ) ;
}
if ( 0 != V_11 ) {
V_12 = V_11 / 1000 ;
V_13 = ( V_11 - 1000 * V_12 ) * 1000000 ;
V_5 -> V_28 . V_12 = V_9 -> V_29 + V_12 ;
V_5 -> V_28 . V_13 = V_13 ;
}
if ( F_16 ( V_3 , - V_14 , V_40 , V_7 ) == - 1 )
return FALSE ;
return F_17 ( V_3 , V_6 , V_18 , V_7 , V_8 ) ;
}
static T_1 F_18 ( T_3 * V_2 , int * V_7 , T_6 * * V_8 , T_9 * V_41 )
{
T_9 V_14 ;
* V_7 = 0 ;
V_14 = F_19 ( V_2 -> V_3 ) ;
* V_41 = V_14 ;
return F_4 ( V_2 , V_2 -> V_3 , & V_2 -> V_5 , V_2 -> V_42 , V_7 , V_8 ) ;
}
static T_1 F_20 ( T_3 * V_2 , T_9 V_43 ,
struct V_4 * V_5 ,
T_5 * V_6 , int * V_7 , T_6 * * V_8 )
{
if ( F_16 ( V_2 -> V_44 , V_43 , V_45 , V_7 ) == - 1 )
return FALSE ;
return F_4 ( V_2 , V_2 -> V_44 , V_5 , V_6 , V_7 , V_8 ) ;
}
T_11 F_21 ( T_3 * V_2 , int * V_7 , T_6 * * V_8 )
{
T_2 V_1 ;
T_7 * V_9 ;
if ( ! F_14 ( V_2 -> V_3 , & V_1 , sizeof V_1 , V_7 , V_8 ) )
return ( * V_7 != V_46 ) ? V_47 : V_48 ;
if ( ! F_1 ( F_22 ( V_1 ) ) )
return V_48 ;
if ( F_16 ( V_2 -> V_3 , 0 , V_45 , V_7 ) == - 1 )
return V_47 ;
V_2 -> V_49 = V_50 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_53 = 0 ;
V_9 = ( T_7 * ) F_23 ( sizeof( T_7 ) ) ;
V_2 -> V_10 = ( void * ) V_9 ;
V_9 -> V_29 = 0 ;
V_2 -> V_54 = F_18 ;
V_2 -> V_55 = F_20 ;
V_2 -> V_56 = V_57 ;
return V_58 ;
}
