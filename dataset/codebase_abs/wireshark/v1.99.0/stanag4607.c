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
T_10 V_15 [ 37 ] ;
T_8 V_16 ;
* V_7 = 0 ;
if ( ! F_5 ( V_3 , V_15 , sizeof V_15 , V_7 , V_8 ) )
return FALSE ;
V_14 += sizeof V_15 ;
if ( ! F_1 ( F_6 ( & V_15 [ 0 ] ) ) ) {
* V_7 = V_17 ;
* V_8 = F_7 ( L_1 ) ;
return FALSE ;
}
V_5 -> V_18 = V_19 ;
V_16 = F_8 ( & V_15 [ 2 ] ) ;
V_5 -> V_20 = V_16 ;
V_5 -> V_21 = V_16 ;
V_5 -> V_22 = V_23 ;
V_5 -> V_24 . V_12 = V_9 -> V_25 ;
V_5 -> V_24 . V_13 = 0 ;
V_11 = 0 ;
#define F_9 1
#define F_10 2
#define F_11 5
#define F_12 13
if ( F_9 == V_15 [ 32 ] ) {
T_10 V_26 [ 39 ] ;
struct V_27 V_27 ;
if ( ! F_13 ( V_3 , & V_26 , sizeof V_26 , V_7 , V_8 ) )
return FALSE ;
V_14 += sizeof V_26 ;
V_27 . V_28 = F_6 ( & V_26 [ 35 ] ) - 1900 ;
V_27 . V_29 = V_26 [ 37 ] - 1 ;
V_27 . V_30 = V_26 [ 38 ] ;
V_27 . V_31 = 0 ;
V_27 . V_32 = 0 ;
V_27 . V_33 = 0 ;
V_27 . V_34 = - 1 ;
V_9 -> V_25 = mktime ( & V_27 ) ;
V_5 -> V_24 . V_12 = V_9 -> V_25 ;
}
else if ( F_12 == V_15 [ 32 ] ) {
if ( ! F_13 ( V_3 , & V_11 , sizeof V_11 , V_7 , V_8 ) )
return FALSE ;
V_14 += sizeof V_11 ;
V_11 = F_14 ( V_11 ) ;
}
else if ( F_10 == V_15 [ 32 ] ) {
T_10 V_35 [ 19 ] ;
if ( ! F_13 ( V_3 , & V_35 , sizeof V_35 , V_7 , V_8 ) )
return FALSE ;
V_14 += sizeof V_35 ;
V_11 = F_8 ( & V_35 [ 15 ] ) ;
}
if ( 0 != V_11 ) {
V_12 = V_11 / 1000 ;
V_13 = ( V_11 - 1000 * V_12 ) * 1000000 ;
V_5 -> V_24 . V_12 = V_9 -> V_25 + V_12 ;
V_5 -> V_24 . V_13 = V_13 ;
}
if ( F_15 ( V_3 , - V_14 , V_36 , V_7 ) == - 1 )
return FALSE ;
return F_16 ( V_3 , V_6 , V_16 , V_7 , V_8 ) ;
}
static T_1 F_17 ( T_3 * V_2 , int * V_7 , T_6 * * V_8 , T_9 * V_37 )
{
T_9 V_14 ;
* V_7 = 0 ;
V_14 = F_18 ( V_2 -> V_3 ) ;
* V_37 = V_14 ;
return F_4 ( V_2 , V_2 -> V_3 , & V_2 -> V_5 , V_2 -> V_38 , V_7 , V_8 ) ;
}
static T_1 F_19 ( T_3 * V_2 , T_9 V_39 ,
struct V_4 * V_5 ,
T_5 * V_6 , int * V_7 , T_6 * * V_8 )
{
if ( F_15 ( V_2 -> V_40 , V_39 , V_41 , V_7 ) == - 1 )
return FALSE ;
return F_4 ( V_2 , V_2 -> V_40 , V_5 , V_6 , V_7 , V_8 ) ;
}
int F_20 ( T_3 * V_2 , int * V_7 , T_6 * * V_8 )
{
T_2 V_1 ;
T_7 * V_9 ;
if ( ! F_13 ( V_2 -> V_3 , & V_1 , sizeof V_1 , V_7 , V_8 ) )
return ( * V_7 != V_42 ) ? - 1 : 0 ;
if ( ! F_1 ( F_21 ( V_1 ) ) )
return 0 ;
if ( F_15 ( V_2 -> V_3 , 0 , V_41 , V_7 ) == - 1 )
return - 1 ;
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = V_46 ;
V_2 -> V_47 = 0 ;
V_9 = ( T_7 * ) F_22 ( sizeof( T_7 ) ) ;
V_2 -> V_10 = ( void * ) V_9 ;
V_9 -> V_25 = 0 ;
V_2 -> V_48 = F_17 ;
V_2 -> V_49 = F_19 ;
V_2 -> V_50 = V_51 ;
return 1 ;
}
