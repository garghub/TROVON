static T_1
F_1 ( T_2 V_1 , T_3 * V_2 , T_4 V_3 , int * V_4 , T_5 * * V_5 )
{
int V_6 ;
V_6 = F_2 ( ( void * ) V_2 , V_3 , V_1 ) ;
if ( V_6 != V_3 ) {
* V_4 = F_3 ( V_1 , V_5 ) ;
if ( V_6 > 0 && * V_4 == 0 ) {
* V_4 = V_7 ;
}
return FALSE ;
}
return TRUE ;
}
static T_1
F_4 ( T_2 V_1 ,
T_3 * V_8 ,
T_4 * V_9 ,
int * V_4 , T_5 * * V_5 )
{
T_3 V_10 [ 2 ] ;
T_6 V_11 ;
if ( ! V_8 || ! V_9 )
return FALSE ;
V_12 ;
do {
if ( F_1 ( V_1 , V_10 , sizeof( V_10 ) , V_4 , V_5 ) == FALSE ) {
V_12 ;
return FALSE ;
}
switch ( V_10 [ 1 ] ) {
case V_13 :
if ( * V_8 != V_14 )
V_12 ;
* V_8 = V_14 ;
* V_9 |= V_10 [ 0 ] ;
V_15 ;
break;
case V_16 :
if ( * V_8 != V_14 )
V_12 ;
* V_8 = V_14 ;
* V_9 |= ( V_10 [ 0 ] << 8 ) ;
V_17 ;
break;
case V_18 :
if ( * V_8 != V_19 )
V_12 ;
* V_8 = V_19 ;
* V_9 |= V_10 [ 0 ] ;
V_15 ;
break;
case V_20 :
if ( * V_8 != V_19 )
V_12 ;
* V_8 = V_19 ;
* V_9 |= ( V_10 [ 0 ] << 8 ) ;
V_17 ;
break;
default:
break;
}
} while ( V_11 != V_21 );
return TRUE ;
}
static T_7
F_5 ( T_2 V_1 , T_3 V_8 , T_3 * V_2 , T_4 V_9 ,
int * V_4 , T_5 * * V_5 )
{
T_3 * V_22 ;
T_3 V_10 [ 2 ] ;
T_4 V_23 = 0 ;
if ( ! V_2 )
return - 1 ;
V_22 = V_2 ;
while ( V_23 < V_9 ) {
if ( F_1 ( V_1 , V_10 , sizeof( V_10 ) , V_4 , V_5 ) == FALSE )
break;
if ( V_10 [ 1 ] == V_8 ) {
* V_22 ++ = V_10 [ 0 ] ;
V_23 ++ ;
}
else if ( F_6 ( V_10 [ 1 ] ) ) {
if ( - 1 == F_7 ( V_1 , - ( V_24 ) sizeof( V_10 ) , V_25 , V_4 ) )
return - 1 ;
break;
}
}
return V_23 ;
}
static T_7
F_8 ( T_3 * V_2 , T_3 V_8 , T_4 V_9 )
{
if ( ! V_2 )
return - 1 ;
V_2 [ 0 ] = V_26 ;
if ( V_8 == V_14 )
V_2 [ 1 ] = V_27 ;
else if ( V_8 == V_19 )
V_2 [ 1 ] = V_28 ;
else
return - 1 ;
V_2 [ 2 ] = ( V_9 >> 8 ) & 0xFF ;
V_2 [ 3 ] = V_9 & 0xFF ;
return V_29 ;
}
static T_1
F_9 ( T_8 * V_30 , int * V_4 , T_5 * * V_5 , V_24 * V_31 )
{
T_3 V_8 ;
T_4 V_9 ;
T_1 V_32 ;
T_3 * V_22 ;
T_7 V_33 , V_6 ;
* V_31 = F_10 ( V_30 -> V_1 ) ;
V_32 = F_4 (
V_30 -> V_1 , & V_8 , & V_9 , V_4 , V_5 ) ;
if ( ! V_32 )
return FALSE ;
F_11 ( V_30 -> V_34 , V_29 + V_9 ) ;
V_22 = F_12 ( V_30 -> V_34 ) ;
V_33 = F_8 ( V_22 , V_8 , V_9 ) ;
if ( V_33 < 0 ) {
* V_4 = V_35 ;
return FALSE ;
}
V_6 = F_5 ( V_30 -> V_1 , V_8 ,
& V_22 [ V_33 ] , V_9 , V_4 , V_5 ) ;
if ( V_6 < 0 )
return FALSE ;
V_33 += V_6 ;
V_30 -> V_36 . V_37 = V_38 ;
V_30 -> V_36 . V_39 . V_40 = 0 ;
V_30 -> V_36 . V_39 . V_41 = 0 ;
V_30 -> V_36 . V_42 = V_33 ;
V_30 -> V_36 . V_43 = V_33 ;
return TRUE ;
}
static T_1
F_13 ( T_8 * V_30 , V_24 V_44 ,
struct V_45 * T_9 V_46 , T_3 * V_47 , int V_48 ,
int * V_4 , T_5 * * V_5 )
{
T_3 V_8 ;
T_4 V_9 ;
T_1 V_32 ;
T_7 V_33 , V_6 ;
if ( - 1 == F_7 ( V_30 -> V_49 , V_44 , V_50 , V_4 ) )
return FALSE ;
V_32 = F_4 ( V_30 -> V_49 , & V_8 ,
& V_9 , V_4 , V_5 ) ;
if ( ! V_32 )
return FALSE ;
V_33 = F_8 ( V_47 , V_8 , V_9 ) ;
if ( V_33 < 0 )
return FALSE ;
V_6 = F_5 ( V_30 -> V_49 , V_8 ,
& V_47 [ V_33 ] , V_48 , V_4 , V_5 ) ;
if ( V_6 < 0 )
return FALSE ;
return TRUE ;
}
int F_14 ( T_8 * V_30 , int * V_4 , T_5 * * V_5 V_46 )
{
T_3 V_51 = 0 ;
T_3 V_52 = 0 ;
T_3 V_10 [ 2 ] ;
int V_6 ;
do {
V_6 = F_2 ( V_10 , sizeof( V_10 ) , V_30 -> V_1 ) ;
if ( V_6 != sizeof( V_10 ) )
break;
if ( V_10 [ 0 ] == 0x00 && V_10 [ 1 ] == 0xE1 )
V_51 ++ ;
V_52 ++ ;
} while ( V_52 < 20 );
if ( V_51 < 2 )
return 0 ;
if ( - 1 == F_7 ( V_30 -> V_1 , 0 , V_50 , V_4 ) )
return - 1 ;
V_30 -> V_53 = V_38 ;
V_30 -> V_54 = 0 ;
V_30 -> V_55 = V_56 ;
V_30 -> V_57 = NULL ;
V_30 -> V_58 = F_9 ;
V_30 -> V_59 = F_13 ;
V_30 -> V_60 = V_61 ;
* V_4 = 0 ;
return 1 ;
}
