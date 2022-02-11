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
int V_16 ;
T_8 V_17 ;
* V_7 = 0 ;
V_16 = F_5 ( V_15 , sizeof V_15 , V_3 ) ;
if ( V_16 != sizeof V_15 )
goto V_18;
V_14 += V_16 ;
if ( ! F_1 ( F_6 ( & V_15 [ 0 ] ) ) ) {
* V_7 = V_19 ;
* V_8 = F_7 ( L_1 ) ;
return FALSE ;
}
V_5 -> V_20 = V_21 ;
V_17 = F_8 ( & V_15 [ 2 ] ) ;
V_5 -> V_22 = V_17 ;
V_5 -> V_23 = V_17 ;
V_5 -> V_24 = V_25 ;
V_5 -> V_26 . V_12 = V_9 -> V_27 ;
V_5 -> V_26 . V_13 = 0 ;
V_11 = 0 ;
#define F_9 1
#define F_10 2
#define F_11 5
#define F_12 13
if ( F_9 == V_15 [ 32 ] ) {
T_10 V_28 [ 39 ] ;
struct V_29 V_29 ;
V_16 = F_5 ( & V_28 , sizeof V_28 , V_3 ) ;
if ( V_16 != sizeof V_28 )
goto V_18;
V_14 += V_16 ;
V_29 . V_30 = F_6 ( & V_28 [ 35 ] ) - 1900 ;
V_29 . V_31 = V_28 [ 37 ] - 1 ;
V_29 . V_32 = V_28 [ 38 ] ;
V_29 . V_33 = 0 ;
V_29 . V_34 = 0 ;
V_29 . V_35 = 0 ;
V_29 . V_36 = - 1 ;
V_9 -> V_27 = mktime ( & V_29 ) ;
V_5 -> V_26 . V_12 = V_9 -> V_27 ;
}
else if ( F_12 == V_15 [ 32 ] ) {
V_16 = F_5 ( & V_11 , sizeof V_11 , V_3 ) ;
if ( V_16 != sizeof V_11 )
goto V_18;
V_14 += V_16 ;
V_11 = F_13 ( V_11 ) ;
}
else if ( F_10 == V_15 [ 32 ] ) {
T_10 V_37 [ 19 ] ;
V_16 = F_5 ( & V_37 , sizeof V_37 , V_3 ) ;
if ( V_16 != sizeof V_37 )
goto V_18;
V_14 += V_16 ;
V_11 = F_8 ( & V_37 [ 15 ] ) ;
}
if ( 0 != V_11 ) {
V_12 = V_11 / 1000 ;
V_13 = ( V_11 - 1000 * V_12 ) * 1000000 ;
V_5 -> V_26 . V_12 = V_9 -> V_27 + V_12 ;
V_5 -> V_26 . V_13 = V_13 ;
}
if ( F_14 ( V_3 , - V_14 , V_38 , V_7 ) == - 1 )
return FALSE ;
return F_15 ( V_3 , V_6 , V_17 , V_7 , V_8 ) ;
V_18:
* V_7 = F_16 ( V_2 -> V_3 , V_8 ) ;
return FALSE ;
}
static T_1 F_17 ( T_3 * V_2 , int * V_7 , T_6 * * V_8 , T_9 * V_39 )
{
T_9 V_14 ;
* V_7 = 0 ;
V_14 = F_18 ( V_2 -> V_3 ) ;
* V_39 = V_14 ;
return F_4 ( V_2 , V_2 -> V_3 , & V_2 -> V_5 , V_2 -> V_40 , V_7 , V_8 ) ;
}
static T_1 F_19 ( T_3 * V_2 , T_9 V_41 ,
struct V_4 * V_5 ,
T_5 * V_6 , int * V_7 , T_6 * * V_8 )
{
if ( F_14 ( V_2 -> V_42 , V_41 , V_43 , V_7 ) == - 1 )
return FALSE ;
return F_4 ( V_2 , V_2 -> V_42 , V_5 , V_6 , V_7 , V_8 ) ;
}
int F_20 ( T_3 * V_2 , int * V_7 , T_6 * * V_8 )
{
int V_16 ;
T_2 V_1 ;
T_7 * V_9 ;
V_16 = F_5 ( & V_1 , sizeof V_1 , V_2 -> V_3 ) ;
if ( V_16 != sizeof V_1 ) {
* V_7 = F_16 ( V_2 -> V_3 , V_8 ) ;
return ( * V_7 != 0 ) ? - 1 : 0 ;
}
if ( ! F_1 ( F_21 ( V_1 ) ) )
return 0 ;
if ( F_14 ( V_2 -> V_3 , 0 , V_43 , V_7 ) == - 1 )
return - 1 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_48 = 0 ;
V_9 = ( T_7 * ) F_22 ( sizeof( T_7 ) ) ;
V_2 -> V_10 = ( void * ) V_9 ;
V_9 -> V_27 = 0 ;
V_2 -> V_49 = F_17 ;
V_2 -> V_50 = F_19 ;
V_2 -> V_51 = V_52 ;
return 1 ;
}
