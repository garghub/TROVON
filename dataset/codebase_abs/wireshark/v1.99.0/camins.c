static T_1
F_1 ( T_2 V_1 ,
T_3 * V_2 ,
T_4 * V_3 ,
int * V_4 , T_5 * * V_5 )
{
T_3 V_6 [ 2 ] ;
T_6 V_7 ;
if ( ! V_2 || ! V_3 )
return FALSE ;
V_8 ;
do {
if ( ! F_2 ( V_1 , V_6 , sizeof( V_6 ) , V_4 , V_5 ) ) {
V_8 ;
return FALSE ;
}
switch ( V_6 [ 1 ] ) {
case V_9 :
if ( * V_2 != V_10 )
V_8 ;
* V_2 = V_10 ;
* V_3 |= V_6 [ 0 ] ;
V_11 ;
break;
case V_12 :
if ( * V_2 != V_10 )
V_8 ;
* V_2 = V_10 ;
* V_3 |= ( V_6 [ 0 ] << 8 ) ;
V_13 ;
break;
case V_14 :
if ( * V_2 != V_15 )
V_8 ;
* V_2 = V_15 ;
* V_3 |= V_6 [ 0 ] ;
V_11 ;
break;
case V_16 :
if ( * V_2 != V_15 )
V_8 ;
* V_2 = V_15 ;
* V_3 |= ( V_6 [ 0 ] << 8 ) ;
V_13 ;
break;
default:
break;
}
} while ( V_7 != V_17 );
return TRUE ;
}
static T_7
F_3 ( T_2 V_1 , T_3 V_2 , T_3 * V_18 , T_4 V_3 ,
int * V_4 , T_5 * * V_5 )
{
T_3 * V_19 ;
T_3 V_6 [ 2 ] ;
T_4 V_20 = 0 ;
if ( ! V_18 )
return - 1 ;
V_19 = V_18 ;
while ( V_20 < V_3 ) {
if ( ! F_2 ( V_1 , V_6 , sizeof( V_6 ) , V_4 , V_5 ) )
break;
if ( V_6 [ 1 ] == V_2 ) {
* V_19 ++ = V_6 [ 0 ] ;
V_20 ++ ;
}
else if ( F_4 ( V_6 [ 1 ] ) ) {
if ( - 1 == F_5 ( V_1 , - ( V_21 ) sizeof( V_6 ) , V_22 , V_4 ) )
return - 1 ;
break;
}
}
return V_20 ;
}
static T_7
F_6 ( T_3 * V_18 , T_3 V_2 , T_4 V_3 )
{
if ( ! V_18 )
return - 1 ;
V_18 [ 0 ] = V_23 ;
if ( V_2 == V_10 )
V_18 [ 1 ] = V_24 ;
else if ( V_2 == V_15 )
V_18 [ 1 ] = V_25 ;
else
return - 1 ;
V_18 [ 2 ] = ( V_3 >> 8 ) & 0xFF ;
V_18 [ 3 ] = V_3 & 0xFF ;
return V_26 ;
}
static T_1
F_7 ( T_2 V_1 , struct V_27 * V_28 , T_8 * V_18 ,
int * V_4 , T_5 * * V_5 )
{
T_3 V_2 ;
T_4 V_3 ;
T_3 * V_19 ;
T_7 V_29 , V_30 ;
if ( ! F_1 ( V_1 , & V_2 , & V_3 , V_4 , V_5 ) )
return FALSE ;
F_8 ( V_18 , V_26 + V_3 ) ;
V_19 = F_9 ( V_18 ) ;
V_29 = F_6 ( V_19 , V_2 , V_3 ) ;
if ( V_29 < 0 ) {
* V_4 = V_31 ;
return FALSE ;
}
V_30 = F_3 ( V_1 , V_2 ,
& V_19 [ V_29 ] , V_3 , V_4 , V_5 ) ;
if ( V_30 < 0 )
return FALSE ;
V_29 += V_30 ;
V_28 -> V_32 = V_33 ;
V_28 -> V_34 = V_35 ;
V_28 -> V_36 = V_29 ;
V_28 -> V_37 = V_29 ;
return TRUE ;
}
static T_1
F_10 ( T_9 * V_38 , int * V_4 , T_5 * * V_5 , V_21 * V_39 )
{
* V_39 = F_11 ( V_38 -> V_1 ) ;
return F_7 ( V_38 -> V_1 , & V_38 -> V_28 , V_38 -> V_40 , V_4 ,
V_5 ) ;
}
static T_1
F_12 ( T_9 * V_38 , V_21 V_41 ,
struct V_27 * V_42 , T_8 * V_18 , int * V_4 , T_5 * * V_5 )
{
if ( - 1 == F_5 ( V_38 -> V_43 , V_41 , V_44 , V_4 ) )
return FALSE ;
return F_7 ( V_38 -> V_43 , V_42 , V_18 , V_4 , V_5 ) ;
}
int F_13 ( T_9 * V_38 , int * V_4 , T_5 * * V_5 V_45 )
{
T_3 V_46 = 0 ;
T_3 V_47 = 0 ;
T_3 V_6 [ 2 ] ;
do {
if ( ! F_14 ( V_38 -> V_1 , V_6 , sizeof( V_6 ) , V_4 , V_5 ) ) {
if ( * V_4 == V_48 )
break;
return - 1 ;
}
if ( V_6 [ 0 ] == 0x00 && V_6 [ 1 ] == 0xE1 )
V_46 ++ ;
V_47 ++ ;
} while ( V_47 < 20 );
if ( V_46 < 2 )
return 0 ;
if ( - 1 == F_5 ( V_38 -> V_1 , 0 , V_44 , V_4 ) )
return - 1 ;
V_38 -> V_49 = V_35 ;
V_38 -> V_50 = 0 ;
V_38 -> V_51 = V_52 ;
V_38 -> V_53 = NULL ;
V_38 -> V_54 = F_10 ;
V_38 -> V_55 = F_12 ;
V_38 -> V_56 = V_57 ;
* V_4 = 0 ;
return 1 ;
}
