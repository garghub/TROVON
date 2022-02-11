static T_1 F_1 ( T_2 V_1 )
{
int V_2 ;
T_3 * V_3 ;
T_4 V_4 [ 2 ] ;
T_4 V_5 = 0 ;
T_4 V_6 = 0 ;
T_5 V_7 = 0 , V_8 = 0 ;
while ( F_2 ( V_1 , V_4 , sizeof( V_4 ) , & V_2 , & V_3 ) ) {
if ( V_2 == V_9 )
break;
if ( V_5 != 0 ) {
if ( V_4 [ 1 ] == V_5 ) {
V_7 ++ ;
V_5 = 0 ;
}
else {
V_6 ++ ;
if ( V_6 > 5 ) {
V_8 ++ ;
V_5 = 0 ;
}
}
}
else {
if ( V_4 [ 1 ] == V_10 ) {
V_5 = V_11 ;
V_6 = 0 ;
}
else if ( V_4 [ 1 ] == V_11 ) {
V_5 = V_10 ;
V_6 = 0 ;
}
else if ( V_4 [ 1 ] == V_12 ) {
V_5 = V_13 ;
V_6 = 0 ;
}
else if ( V_4 [ 1 ] == V_13 ) {
V_5 = V_12 ;
V_6 = 0 ;
}
}
}
if ( V_7 > 10 * V_8 )
return TRUE ;
return FALSE ;
}
static T_1
F_3 ( T_2 V_1 ,
T_4 * V_14 ,
T_6 * V_15 ,
int * V_2 , T_3 * * V_3 )
{
T_4 V_4 [ 2 ] ;
T_7 V_16 ;
if ( ! V_14 || ! V_15 )
return FALSE ;
V_17 ;
do {
if ( ! F_4 ( V_1 , V_4 , sizeof( V_4 ) , V_2 , V_3 ) ) {
V_17 ;
return FALSE ;
}
switch ( V_4 [ 1 ] ) {
case V_10 :
if ( * V_14 != V_18 )
V_17 ;
* V_14 = V_18 ;
* V_15 |= V_4 [ 0 ] ;
V_19 ;
break;
case V_11 :
if ( * V_14 != V_18 )
V_17 ;
* V_14 = V_18 ;
* V_15 |= ( V_4 [ 0 ] << 8 ) ;
V_20 ;
break;
case V_12 :
if ( * V_14 != V_21 )
V_17 ;
* V_14 = V_21 ;
* V_15 |= V_4 [ 0 ] ;
V_19 ;
break;
case V_13 :
if ( * V_14 != V_21 )
V_17 ;
* V_14 = V_21 ;
* V_15 |= ( V_4 [ 0 ] << 8 ) ;
V_20 ;
break;
default:
break;
}
} while ( V_16 != V_22 );
return TRUE ;
}
static T_8
F_5 ( T_2 V_1 , T_4 V_14 , T_4 * V_23 , T_6 V_15 ,
int * V_2 , T_3 * * V_3 )
{
T_4 * V_24 ;
T_4 V_4 [ 2 ] ;
T_6 V_25 = 0 ;
if ( ! V_23 )
return - 1 ;
V_24 = V_23 ;
while ( V_25 < V_15 ) {
if ( ! F_4 ( V_1 , V_4 , sizeof( V_4 ) , V_2 , V_3 ) )
break;
if ( V_4 [ 1 ] == V_14 ) {
* V_24 ++ = V_4 [ 0 ] ;
V_25 ++ ;
}
else if ( F_6 ( V_4 [ 1 ] ) ) {
if ( - 1 == F_7 ( V_1 , - ( V_26 ) sizeof( V_4 ) , V_27 , V_2 ) )
return - 1 ;
break;
}
}
return V_25 ;
}
static T_8
F_8 ( T_4 * V_23 , T_4 V_14 , T_6 V_15 )
{
if ( ! V_23 )
return - 1 ;
V_23 [ 0 ] = V_28 ;
if ( V_14 == V_18 )
V_23 [ 1 ] = V_29 ;
else if ( V_14 == V_21 )
V_23 [ 1 ] = V_30 ;
else
return - 1 ;
V_23 [ 2 ] = ( V_15 >> 8 ) & 0xFF ;
V_23 [ 3 ] = V_15 & 0xFF ;
return V_31 ;
}
static T_1
F_9 ( T_2 V_1 , struct V_32 * V_33 , T_9 * V_23 ,
int * V_2 , T_3 * * V_3 )
{
T_4 V_14 ;
T_6 V_15 ;
T_4 * V_24 ;
T_8 V_34 , V_35 ;
if ( ! F_3 ( V_1 , & V_14 , & V_15 , V_2 , V_3 ) )
return FALSE ;
F_10 ( V_23 , V_31 + V_15 ) ;
V_24 = F_11 ( V_23 ) ;
V_34 = F_8 ( V_24 , V_14 , V_15 ) ;
if ( V_34 < 0 ) {
* V_2 = V_36 ;
return FALSE ;
}
V_35 = F_5 ( V_1 , V_14 ,
& V_24 [ V_34 ] , V_15 , V_2 , V_3 ) ;
if ( V_35 < 0 )
return FALSE ;
V_34 += V_35 ;
V_33 -> V_37 = V_38 ;
V_33 -> V_39 = V_40 ;
V_33 -> V_41 = V_34 ;
V_33 -> V_42 = V_34 ;
return TRUE ;
}
static T_1
F_12 ( T_10 * V_43 , int * V_2 , T_3 * * V_3 , V_26 * V_44 )
{
* V_44 = F_13 ( V_43 -> V_1 ) ;
return F_9 ( V_43 -> V_1 , & V_43 -> V_33 , V_43 -> V_45 , V_2 ,
V_3 ) ;
}
static T_1
F_14 ( T_10 * V_43 , V_26 V_46 ,
struct V_32 * V_47 , T_9 * V_23 , int * V_2 , T_3 * * V_3 )
{
if ( - 1 == F_7 ( V_43 -> V_48 , V_46 , V_49 , V_2 ) )
return FALSE ;
return F_9 ( V_43 -> V_48 , V_47 , V_23 , V_2 , V_3 ) ;
}
T_11 F_15 ( T_10 * V_43 , int * V_2 , T_3 * * V_3 V_50 )
{
if ( ! F_1 ( V_43 -> V_1 ) )
return V_51 ;
if ( - 1 == F_7 ( V_43 -> V_1 , 0 , V_49 , V_2 ) )
return V_52 ;
V_43 -> V_53 = V_40 ;
V_43 -> V_54 = 0 ;
V_43 -> V_55 = V_56 ;
V_43 -> V_57 = NULL ;
V_43 -> V_58 = F_12 ;
V_43 -> V_59 = F_14 ;
V_43 -> V_60 = V_61 ;
* V_2 = 0 ;
return V_62 ;
}
