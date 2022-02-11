int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_3 ,
int V_4 ,
T_4 * * V_5 )
{
T_4 * V_6 ;
T_5 * V_7 ;
T_6 V_8 ;
int V_9 = 1 ;
int error ;
V_7 = V_4 ? V_1 -> V_10 : V_1 -> V_11 ;
error = F_2 ( V_7 , V_3 , 1 , & V_8 , & V_9 , V_12 ) ;
if ( error )
return error ;
ASSERT ( V_8 . V_13 != V_14 ) ;
error = F_3 ( V_1 , V_2 , V_1 -> V_15 ,
F_4 ( V_1 , V_8 . V_13 ) ,
V_1 -> V_16 , 0 , & V_6 , NULL ) ;
if ( error )
return error ;
* V_5 = V_6 ;
return 0 ;
}
int
F_5 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_17 ,
T_3 V_18 ,
T_3 * V_19 )
{
T_7 * V_20 ;
int V_21 ;
T_3 V_3 ;
T_4 * V_6 ;
T_7 * V_22 ;
int error ;
T_3 V_23 ;
T_3 V_24 ;
T_3 V_25 ;
T_7 V_26 ;
T_7 V_27 ;
T_7 V_28 ;
int V_29 ;
V_3 = F_6 ( V_1 , V_17 ) ;
error = F_1 ( V_1 , V_2 , V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_22 = V_6 -> V_30 ;
V_29 = F_7 ( V_1 , V_17 ) ;
V_20 = & V_22 [ V_29 ] ;
V_21 = ( int ) ( V_17 & ( V_31 - 1 ) ) ;
V_25 = V_17 - V_18 + 1 ;
V_27 = ( * V_20 & ( ( T_7 ) 1 << V_21 ) ) ? - 1 : 0 ;
if ( V_21 < V_31 - 1 ) {
V_23 = F_8 ( ( V_32 ) ( V_21 - V_25 + 1 ) , 0 ) ;
V_26 = ( ( ( T_7 ) 1 << ( V_21 - V_23 + 1 ) ) - 1 ) <<
V_23 ;
if ( ( V_28 = ( * V_20 ^ V_27 ) & V_26 ) ) {
F_9 ( V_2 , V_6 ) ;
V_24 = V_21 - F_10 ( V_28 ) ;
* V_19 = V_17 - V_24 + 1 ;
return 0 ;
}
V_24 = V_21 - V_23 + 1 ;
if ( -- V_29 == - 1 && V_24 < V_25 ) {
F_9 ( V_2 , V_6 ) ;
error = F_1 ( V_1 , V_2 , -- V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_22 = V_6 -> V_30 ;
V_29 = F_11 ( V_1 ) ;
V_20 = & V_22 [ V_29 ] ;
} else {
V_20 -- ;
}
} else {
V_24 = 0 ;
}
while ( V_25 - V_24 >= V_31 ) {
if ( ( V_28 = * V_20 ^ V_27 ) ) {
F_9 ( V_2 , V_6 ) ;
V_24 += V_31 - 1 - F_10 ( V_28 ) ;
* V_19 = V_17 - V_24 + 1 ;
return 0 ;
}
V_24 += V_31 ;
if ( -- V_29 == - 1 && V_24 < V_25 ) {
F_9 ( V_2 , V_6 ) ;
error = F_1 ( V_1 , V_2 , -- V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_22 = V_6 -> V_30 ;
V_29 = F_11 ( V_1 ) ;
V_20 = & V_22 [ V_29 ] ;
} else {
V_20 -- ;
}
}
if ( V_25 - V_24 ) {
V_23 = V_31 - ( V_25 - V_24 ) ;
V_26 = ( ( ( T_7 ) 1 << ( V_25 - V_24 ) ) - 1 ) << V_23 ;
if ( ( V_28 = ( * V_20 ^ V_27 ) & V_26 ) ) {
F_9 ( V_2 , V_6 ) ;
V_24 += V_31 - 1 - F_10 ( V_28 ) ;
* V_19 = V_17 - V_24 + 1 ;
return 0 ;
} else
V_24 = V_25 ;
}
F_9 ( V_2 , V_6 ) ;
* V_19 = V_17 - V_24 + 1 ;
return 0 ;
}
int
F_12 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_17 ,
T_3 V_18 ,
T_3 * V_19 )
{
T_7 * V_20 ;
int V_21 ;
T_3 V_3 ;
T_4 * V_6 ;
T_7 * V_22 ;
int error ;
T_3 V_24 ;
T_3 V_33 ;
T_3 V_25 ;
T_7 V_26 ;
T_7 V_27 ;
T_7 V_28 ;
int V_29 ;
V_3 = F_6 ( V_1 , V_17 ) ;
error = F_1 ( V_1 , V_2 , V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_22 = V_6 -> V_30 ;
V_29 = F_7 ( V_1 , V_17 ) ;
V_20 = & V_22 [ V_29 ] ;
V_21 = ( int ) ( V_17 & ( V_31 - 1 ) ) ;
V_25 = V_18 - V_17 + 1 ;
V_27 = ( * V_20 & ( ( T_7 ) 1 << V_21 ) ) ? - 1 : 0 ;
if ( V_21 ) {
V_33 = F_13 ( V_21 + V_25 , V_31 ) ;
V_26 = ( ( ( T_7 ) 1 << ( V_33 - V_21 ) ) - 1 ) << V_21 ;
if ( ( V_28 = ( * V_20 ^ V_27 ) & V_26 ) ) {
F_9 ( V_2 , V_6 ) ;
V_24 = F_14 ( V_28 ) - V_21 ;
* V_19 = V_17 + V_24 - 1 ;
return 0 ;
}
V_24 = V_33 - V_21 ;
if ( ++ V_29 == F_15 ( V_1 ) && V_24 < V_25 ) {
F_9 ( V_2 , V_6 ) ;
error = F_1 ( V_1 , V_2 , ++ V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_20 = V_22 = V_6 -> V_30 ;
V_29 = 0 ;
} else {
V_20 ++ ;
}
} else {
V_24 = 0 ;
}
while ( V_25 - V_24 >= V_31 ) {
if ( ( V_28 = * V_20 ^ V_27 ) ) {
F_9 ( V_2 , V_6 ) ;
V_24 += F_14 ( V_28 ) ;
* V_19 = V_17 + V_24 - 1 ;
return 0 ;
}
V_24 += V_31 ;
if ( ++ V_29 == F_15 ( V_1 ) && V_24 < V_25 ) {
F_9 ( V_2 , V_6 ) ;
error = F_1 ( V_1 , V_2 , ++ V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_20 = V_22 = V_6 -> V_30 ;
V_29 = 0 ;
} else {
V_20 ++ ;
}
}
if ( ( V_33 = V_25 - V_24 ) ) {
V_26 = ( ( T_7 ) 1 << V_33 ) - 1 ;
if ( ( V_28 = ( * V_20 ^ V_27 ) & V_26 ) ) {
F_9 ( V_2 , V_6 ) ;
V_24 += F_14 ( V_28 ) ;
* V_19 = V_17 + V_24 - 1 ;
return 0 ;
} else
V_24 = V_25 ;
}
F_9 ( V_2 , V_6 ) ;
* V_19 = V_17 + V_24 - 1 ;
return 0 ;
}
int
F_16 (
T_1 * V_1 ,
T_2 * V_2 ,
int log ,
T_3 V_34 ,
int V_35 ,
T_4 * * V_36 ,
T_8 * V_37 ,
T_9 * V_38 )
{
T_4 * V_6 ;
int error ;
T_8 V_39 ;
int V_40 ;
T_9 * V_41 ;
V_40 = F_17 ( V_1 , log , V_34 ) ;
V_39 = F_18 ( V_1 , V_40 ) ;
if ( * V_36 && * V_37 == V_39 )
V_6 = * V_36 ;
else {
if ( * V_36 )
F_9 ( V_2 , * V_36 ) ;
error = F_1 ( V_1 , V_2 , V_39 , 1 , & V_6 ) ;
if ( error ) {
return error ;
}
* V_36 = V_6 ;
* V_37 = V_39 ;
}
V_41 = F_19 ( V_1 , V_6 , V_40 ) ;
if ( V_35 ) {
T_10 V_42 = ( T_10 ) ( ( char * ) V_41 - ( char * ) V_6 -> V_30 ) ;
* V_41 += V_35 ;
F_20 ( V_2 , V_6 , V_42 , V_42 + sizeof( * V_41 ) - 1 ) ;
}
if ( V_38 )
* V_38 = * V_41 ;
return 0 ;
}
int
F_21 (
T_1 * V_1 ,
T_2 * V_2 ,
int log ,
T_3 V_34 ,
int V_35 ,
T_4 * * V_36 ,
T_8 * V_37 )
{
return F_16 ( V_1 , V_2 , log , V_34 ,
V_35 , V_36 , V_37 , NULL ) ;
}
int
F_22 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_17 ,
T_11 V_25 ,
int V_43 )
{
T_7 * V_20 ;
int V_21 ;
T_3 V_3 ;
T_4 * V_6 ;
T_7 * V_22 ;
int error ;
T_7 * V_42 ;
int V_24 ;
int V_33 ;
T_7 V_26 ;
int V_29 ;
V_3 = F_6 ( V_1 , V_17 ) ;
error = F_1 ( V_1 , V_2 , V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_22 = V_6 -> V_30 ;
V_29 = F_7 ( V_1 , V_17 ) ;
V_42 = V_20 = & V_22 [ V_29 ] ;
V_21 = ( int ) ( V_17 & ( V_31 - 1 ) ) ;
V_43 = - V_43 ;
if ( V_21 ) {
V_33 = F_13 ( V_21 + V_25 , V_31 ) ;
V_26 = ( ( ( T_7 ) 1 << ( V_33 - V_21 ) ) - 1 ) << V_21 ;
if ( V_43 )
* V_20 |= V_26 ;
else
* V_20 &= ~ V_26 ;
V_24 = V_33 - V_21 ;
if ( ++ V_29 == F_15 ( V_1 ) && V_24 < V_25 ) {
F_20 ( V_2 , V_6 ,
( T_10 ) ( ( char * ) V_42 - ( char * ) V_22 ) ,
( T_10 ) ( ( char * ) V_20 - ( char * ) V_22 ) ) ;
error = F_1 ( V_1 , V_2 , ++ V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_42 = V_20 = V_22 = V_6 -> V_30 ;
V_29 = 0 ;
} else {
V_20 ++ ;
}
} else {
V_24 = 0 ;
}
while ( V_25 - V_24 >= V_31 ) {
* V_20 = V_43 ;
V_24 += V_31 ;
if ( ++ V_29 == F_15 ( V_1 ) && V_24 < V_25 ) {
F_20 ( V_2 , V_6 ,
( T_10 ) ( ( char * ) V_42 - ( char * ) V_22 ) ,
( T_10 ) ( ( char * ) V_20 - ( char * ) V_22 ) ) ;
error = F_1 ( V_1 , V_2 , ++ V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_42 = V_20 = V_22 = V_6 -> V_30 ;
V_29 = 0 ;
} else {
V_20 ++ ;
}
}
if ( ( V_33 = V_25 - V_24 ) ) {
V_21 = 0 ;
V_26 = ( ( T_7 ) 1 << V_33 ) - 1 ;
if ( V_43 )
* V_20 |= V_26 ;
else
* V_20 &= ~ V_26 ;
V_20 ++ ;
}
if ( V_20 > V_42 )
F_20 ( V_2 , V_6 , ( T_10 ) ( ( char * ) V_42 - ( char * ) V_22 ) ,
( T_10 ) ( ( char * ) V_20 - ( char * ) V_22 - 1 ) ) ;
return 0 ;
}
int
F_23 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_17 ,
T_11 V_25 ,
T_4 * * V_36 ,
T_8 * V_37 )
{
T_3 V_44 ;
int error ;
T_3 V_45 ;
T_3 V_46 ;
V_44 = V_17 + V_25 - 1 ;
error = F_22 ( V_1 , V_2 , V_17 , V_25 , 1 ) ;
if ( error ) {
return error ;
}
error = F_5 ( V_1 , V_2 , V_17 , 0 , & V_46 ) ;
if ( error ) {
return error ;
}
error = F_12 ( V_1 , V_2 , V_44 , V_1 -> V_47 . V_48 - 1 ,
& V_45 ) ;
if ( error )
return error ;
if ( V_46 < V_17 ) {
error = F_21 ( V_1 , V_2 ,
F_24 ( V_17 - V_46 ) ,
F_6 ( V_1 , V_46 ) , - 1 , V_36 , V_37 ) ;
if ( error ) {
return error ;
}
}
if ( V_45 > V_44 ) {
error = F_21 ( V_1 , V_2 ,
F_24 ( V_45 - V_44 ) ,
F_6 ( V_1 , V_44 + 1 ) , - 1 , V_36 , V_37 ) ;
if ( error ) {
return error ;
}
}
error = F_21 ( V_1 , V_2 ,
F_24 ( V_45 + 1 - V_46 ) ,
F_6 ( V_1 , V_46 ) , 1 , V_36 , V_37 ) ;
return error ;
}
int
F_25 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_17 ,
T_11 V_25 ,
int V_43 ,
T_3 * V_49 ,
int * V_50 )
{
T_7 * V_20 ;
int V_21 ;
T_3 V_3 ;
T_4 * V_6 ;
T_7 * V_22 ;
int error ;
T_3 V_24 ;
T_3 V_33 ;
T_7 V_26 ;
T_7 V_28 ;
int V_29 ;
V_3 = F_6 ( V_1 , V_17 ) ;
error = F_1 ( V_1 , V_2 , V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_22 = V_6 -> V_30 ;
V_29 = F_7 ( V_1 , V_17 ) ;
V_20 = & V_22 [ V_29 ] ;
V_21 = ( int ) ( V_17 & ( V_31 - 1 ) ) ;
V_43 = - V_43 ;
if ( V_21 ) {
V_33 = F_13 ( V_21 + V_25 , V_31 ) ;
V_26 = ( ( ( T_7 ) 1 << ( V_33 - V_21 ) ) - 1 ) << V_21 ;
if ( ( V_28 = ( * V_20 ^ V_43 ) & V_26 ) ) {
F_9 ( V_2 , V_6 ) ;
V_24 = F_14 ( V_28 ) - V_21 ;
* V_49 = V_17 + V_24 ;
* V_50 = 0 ;
return 0 ;
}
V_24 = V_33 - V_21 ;
if ( ++ V_29 == F_15 ( V_1 ) && V_24 < V_25 ) {
F_9 ( V_2 , V_6 ) ;
error = F_1 ( V_1 , V_2 , ++ V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_20 = V_22 = V_6 -> V_30 ;
V_29 = 0 ;
} else {
V_20 ++ ;
}
} else {
V_24 = 0 ;
}
while ( V_25 - V_24 >= V_31 ) {
if ( ( V_28 = * V_20 ^ V_43 ) ) {
F_9 ( V_2 , V_6 ) ;
V_24 += F_14 ( V_28 ) ;
* V_49 = V_17 + V_24 ;
* V_50 = 0 ;
return 0 ;
}
V_24 += V_31 ;
if ( ++ V_29 == F_15 ( V_1 ) && V_24 < V_25 ) {
F_9 ( V_2 , V_6 ) ;
error = F_1 ( V_1 , V_2 , ++ V_3 , 0 , & V_6 ) ;
if ( error ) {
return error ;
}
V_20 = V_22 = V_6 -> V_30 ;
V_29 = 0 ;
} else {
V_20 ++ ;
}
}
if ( ( V_33 = V_25 - V_24 ) ) {
V_26 = ( ( T_7 ) 1 << V_33 ) - 1 ;
if ( ( V_28 = ( * V_20 ^ V_43 ) & V_26 ) ) {
F_9 ( V_2 , V_6 ) ;
V_24 += F_14 ( V_28 ) ;
* V_49 = V_17 + V_24 ;
* V_50 = 0 ;
return 0 ;
} else
V_24 = V_25 ;
}
F_9 ( V_2 , V_6 ) ;
* V_49 = V_17 + V_24 ;
* V_50 = 1 ;
return 0 ;
}
STATIC int
F_26 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 V_51 ,
T_11 V_25 )
{
T_3 V_49 ;
int V_50 ;
int error ;
error = F_25 ( V_1 , V_2 , V_51 , V_25 , 0 , & V_49 , & V_50 ) ;
if ( error )
return error ;
ASSERT ( V_50 ) ;
return 0 ;
}
int
F_27 (
T_2 * V_2 ,
T_3 V_51 ,
T_11 V_25 )
{
int error ;
T_1 * V_1 ;
T_8 V_39 ;
T_4 * V_52 = NULL ;
V_1 = V_2 -> V_53 ;
ASSERT ( V_1 -> V_11 -> V_54 != NULL ) ;
ASSERT ( F_28 ( V_1 -> V_11 , V_55 ) ) ;
error = F_26 ( V_1 , V_2 , V_51 , V_25 ) ;
if ( error )
return error ;
error = F_23 ( V_1 , V_2 , V_51 , V_25 , & V_52 , & V_39 ) ;
if ( error ) {
return error ;
}
F_29 ( V_2 , V_56 , ( long ) V_25 ) ;
if ( V_2 -> V_57 + V_1 -> V_47 . V_58 ==
V_1 -> V_47 . V_48 ) {
if ( ! ( V_1 -> V_11 -> V_59 . V_60 & V_61 ) )
V_1 -> V_11 -> V_59 . V_60 |= V_61 ;
* ( V_62 * ) & V_1 -> V_11 -> V_59 . V_63 = 0 ;
F_30 ( V_2 , V_1 -> V_11 , V_64 ) ;
}
return 0 ;
}
