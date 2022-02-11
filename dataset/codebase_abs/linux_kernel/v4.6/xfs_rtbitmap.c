static void
F_1 (
struct V_1 * V_2 )
{
return;
}
static void
F_2 (
struct V_1 * V_2 )
{
return;
}
int
F_3 (
T_1 * V_3 ,
T_2 * V_4 ,
T_3 V_5 ,
int V_6 ,
T_4 * * V_7 )
{
T_4 * V_2 ;
T_5 * V_8 ;
T_6 V_9 ;
int V_10 = 1 ;
int error ;
V_8 = V_6 ? V_3 -> V_11 : V_3 -> V_12 ;
error = F_4 ( V_8 , V_5 , 1 , & V_9 , & V_10 , V_13 ) ;
if ( error )
return error ;
ASSERT ( V_9 . V_14 != V_15 ) ;
error = F_5 ( V_3 , V_4 , V_3 -> V_16 ,
F_6 ( V_3 , V_9 . V_14 ) ,
V_3 -> V_17 , 0 , & V_2 , & V_18 ) ;
if ( error )
return error ;
F_7 ( V_4 , V_2 , V_6 ? V_19
: V_20 ) ;
* V_7 = V_2 ;
return 0 ;
}
int
F_8 (
T_1 * V_3 ,
T_2 * V_4 ,
T_3 V_21 ,
T_3 V_22 ,
T_3 * V_23 )
{
T_7 * V_24 ;
int V_25 ;
T_3 V_5 ;
T_4 * V_2 ;
T_7 * V_26 ;
int error ;
T_3 V_27 ;
T_3 V_28 ;
T_3 V_29 ;
T_7 V_30 ;
T_7 V_31 ;
T_7 V_32 ;
int V_33 ;
V_5 = F_9 ( V_3 , V_21 ) ;
error = F_3 ( V_3 , V_4 , V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_26 = V_2 -> V_34 ;
V_33 = F_10 ( V_3 , V_21 ) ;
V_24 = & V_26 [ V_33 ] ;
V_25 = ( int ) ( V_21 & ( V_35 - 1 ) ) ;
V_29 = V_21 - V_22 + 1 ;
V_31 = ( * V_24 & ( ( T_7 ) 1 << V_25 ) ) ? - 1 : 0 ;
if ( V_25 < V_35 - 1 ) {
V_27 = F_11 ( ( V_36 ) ( V_25 - V_29 + 1 ) , 0 ) ;
V_30 = ( ( ( T_7 ) 1 << ( V_25 - V_27 + 1 ) ) - 1 ) <<
V_27 ;
if ( ( V_32 = ( * V_24 ^ V_31 ) & V_30 ) ) {
F_12 ( V_4 , V_2 ) ;
V_28 = V_25 - F_13 ( V_32 ) ;
* V_23 = V_21 - V_28 + 1 ;
return 0 ;
}
V_28 = V_25 - V_27 + 1 ;
if ( -- V_33 == - 1 && V_28 < V_29 ) {
F_12 ( V_4 , V_2 ) ;
error = F_3 ( V_3 , V_4 , -- V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_26 = V_2 -> V_34 ;
V_33 = F_14 ( V_3 ) ;
V_24 = & V_26 [ V_33 ] ;
} else {
V_24 -- ;
}
} else {
V_28 = 0 ;
}
while ( V_29 - V_28 >= V_35 ) {
if ( ( V_32 = * V_24 ^ V_31 ) ) {
F_12 ( V_4 , V_2 ) ;
V_28 += V_35 - 1 - F_13 ( V_32 ) ;
* V_23 = V_21 - V_28 + 1 ;
return 0 ;
}
V_28 += V_35 ;
if ( -- V_33 == - 1 && V_28 < V_29 ) {
F_12 ( V_4 , V_2 ) ;
error = F_3 ( V_3 , V_4 , -- V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_26 = V_2 -> V_34 ;
V_33 = F_14 ( V_3 ) ;
V_24 = & V_26 [ V_33 ] ;
} else {
V_24 -- ;
}
}
if ( V_29 - V_28 ) {
V_27 = V_35 - ( V_29 - V_28 ) ;
V_30 = ( ( ( T_7 ) 1 << ( V_29 - V_28 ) ) - 1 ) << V_27 ;
if ( ( V_32 = ( * V_24 ^ V_31 ) & V_30 ) ) {
F_12 ( V_4 , V_2 ) ;
V_28 += V_35 - 1 - F_13 ( V_32 ) ;
* V_23 = V_21 - V_28 + 1 ;
return 0 ;
} else
V_28 = V_29 ;
}
F_12 ( V_4 , V_2 ) ;
* V_23 = V_21 - V_28 + 1 ;
return 0 ;
}
int
F_15 (
T_1 * V_3 ,
T_2 * V_4 ,
T_3 V_21 ,
T_3 V_22 ,
T_3 * V_23 )
{
T_7 * V_24 ;
int V_25 ;
T_3 V_5 ;
T_4 * V_2 ;
T_7 * V_26 ;
int error ;
T_3 V_28 ;
T_3 V_37 ;
T_3 V_29 ;
T_7 V_30 ;
T_7 V_31 ;
T_7 V_32 ;
int V_33 ;
V_5 = F_9 ( V_3 , V_21 ) ;
error = F_3 ( V_3 , V_4 , V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_26 = V_2 -> V_34 ;
V_33 = F_10 ( V_3 , V_21 ) ;
V_24 = & V_26 [ V_33 ] ;
V_25 = ( int ) ( V_21 & ( V_35 - 1 ) ) ;
V_29 = V_22 - V_21 + 1 ;
V_31 = ( * V_24 & ( ( T_7 ) 1 << V_25 ) ) ? - 1 : 0 ;
if ( V_25 ) {
V_37 = F_16 ( V_25 + V_29 , V_35 ) ;
V_30 = ( ( ( T_7 ) 1 << ( V_37 - V_25 ) ) - 1 ) << V_25 ;
if ( ( V_32 = ( * V_24 ^ V_31 ) & V_30 ) ) {
F_12 ( V_4 , V_2 ) ;
V_28 = F_17 ( V_32 ) - V_25 ;
* V_23 = V_21 + V_28 - 1 ;
return 0 ;
}
V_28 = V_37 - V_25 ;
if ( ++ V_33 == F_18 ( V_3 ) && V_28 < V_29 ) {
F_12 ( V_4 , V_2 ) ;
error = F_3 ( V_3 , V_4 , ++ V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_24 = V_26 = V_2 -> V_34 ;
V_33 = 0 ;
} else {
V_24 ++ ;
}
} else {
V_28 = 0 ;
}
while ( V_29 - V_28 >= V_35 ) {
if ( ( V_32 = * V_24 ^ V_31 ) ) {
F_12 ( V_4 , V_2 ) ;
V_28 += F_17 ( V_32 ) ;
* V_23 = V_21 + V_28 - 1 ;
return 0 ;
}
V_28 += V_35 ;
if ( ++ V_33 == F_18 ( V_3 ) && V_28 < V_29 ) {
F_12 ( V_4 , V_2 ) ;
error = F_3 ( V_3 , V_4 , ++ V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_24 = V_26 = V_2 -> V_34 ;
V_33 = 0 ;
} else {
V_24 ++ ;
}
}
if ( ( V_37 = V_29 - V_28 ) ) {
V_30 = ( ( T_7 ) 1 << V_37 ) - 1 ;
if ( ( V_32 = ( * V_24 ^ V_31 ) & V_30 ) ) {
F_12 ( V_4 , V_2 ) ;
V_28 += F_17 ( V_32 ) ;
* V_23 = V_21 + V_28 - 1 ;
return 0 ;
} else
V_28 = V_29 ;
}
F_12 ( V_4 , V_2 ) ;
* V_23 = V_21 + V_28 - 1 ;
return 0 ;
}
int
F_19 (
T_1 * V_3 ,
T_2 * V_4 ,
int log ,
T_3 V_38 ,
int V_39 ,
T_4 * * V_40 ,
T_8 * V_41 ,
T_9 * V_42 )
{
T_4 * V_2 ;
int error ;
T_8 V_43 ;
int V_44 ;
T_9 * V_45 ;
V_44 = F_20 ( V_3 , log , V_38 ) ;
V_43 = F_21 ( V_3 , V_44 ) ;
if ( * V_40 && * V_41 == V_43 )
V_2 = * V_40 ;
else {
if ( * V_40 )
F_12 ( V_4 , * V_40 ) ;
error = F_3 ( V_3 , V_4 , V_43 , 1 , & V_2 ) ;
if ( error ) {
return error ;
}
* V_40 = V_2 ;
* V_41 = V_43 ;
}
V_45 = F_22 ( V_3 , V_2 , V_44 ) ;
if ( V_39 ) {
T_10 V_46 = ( T_10 ) ( ( char * ) V_45 - ( char * ) V_2 -> V_34 ) ;
* V_45 += V_39 ;
F_23 ( V_4 , V_2 , V_46 , V_46 + sizeof( * V_45 ) - 1 ) ;
}
if ( V_42 )
* V_42 = * V_45 ;
return 0 ;
}
int
F_24 (
T_1 * V_3 ,
T_2 * V_4 ,
int log ,
T_3 V_38 ,
int V_39 ,
T_4 * * V_40 ,
T_8 * V_41 )
{
return F_19 ( V_3 , V_4 , log , V_38 ,
V_39 , V_40 , V_41 , NULL ) ;
}
int
F_25 (
T_1 * V_3 ,
T_2 * V_4 ,
T_3 V_21 ,
T_11 V_29 ,
int V_47 )
{
T_7 * V_24 ;
int V_25 ;
T_3 V_5 ;
T_4 * V_2 ;
T_7 * V_26 ;
int error ;
T_7 * V_46 ;
int V_28 ;
int V_37 ;
T_7 V_30 ;
int V_33 ;
V_5 = F_9 ( V_3 , V_21 ) ;
error = F_3 ( V_3 , V_4 , V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_26 = V_2 -> V_34 ;
V_33 = F_10 ( V_3 , V_21 ) ;
V_46 = V_24 = & V_26 [ V_33 ] ;
V_25 = ( int ) ( V_21 & ( V_35 - 1 ) ) ;
V_47 = - V_47 ;
if ( V_25 ) {
V_37 = F_16 ( V_25 + V_29 , V_35 ) ;
V_30 = ( ( ( T_7 ) 1 << ( V_37 - V_25 ) ) - 1 ) << V_25 ;
if ( V_47 )
* V_24 |= V_30 ;
else
* V_24 &= ~ V_30 ;
V_28 = V_37 - V_25 ;
if ( ++ V_33 == F_18 ( V_3 ) && V_28 < V_29 ) {
F_23 ( V_4 , V_2 ,
( T_10 ) ( ( char * ) V_46 - ( char * ) V_26 ) ,
( T_10 ) ( ( char * ) V_24 - ( char * ) V_26 ) ) ;
error = F_3 ( V_3 , V_4 , ++ V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_46 = V_24 = V_26 = V_2 -> V_34 ;
V_33 = 0 ;
} else {
V_24 ++ ;
}
} else {
V_28 = 0 ;
}
while ( V_29 - V_28 >= V_35 ) {
* V_24 = V_47 ;
V_28 += V_35 ;
if ( ++ V_33 == F_18 ( V_3 ) && V_28 < V_29 ) {
F_23 ( V_4 , V_2 ,
( T_10 ) ( ( char * ) V_46 - ( char * ) V_26 ) ,
( T_10 ) ( ( char * ) V_24 - ( char * ) V_26 ) ) ;
error = F_3 ( V_3 , V_4 , ++ V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_46 = V_24 = V_26 = V_2 -> V_34 ;
V_33 = 0 ;
} else {
V_24 ++ ;
}
}
if ( ( V_37 = V_29 - V_28 ) ) {
V_25 = 0 ;
V_30 = ( ( T_7 ) 1 << V_37 ) - 1 ;
if ( V_47 )
* V_24 |= V_30 ;
else
* V_24 &= ~ V_30 ;
V_24 ++ ;
}
if ( V_24 > V_46 )
F_23 ( V_4 , V_2 , ( T_10 ) ( ( char * ) V_46 - ( char * ) V_26 ) ,
( T_10 ) ( ( char * ) V_24 - ( char * ) V_26 - 1 ) ) ;
return 0 ;
}
int
F_26 (
T_1 * V_3 ,
T_2 * V_4 ,
T_3 V_21 ,
T_11 V_29 ,
T_4 * * V_40 ,
T_8 * V_41 )
{
T_3 V_48 ;
int error ;
T_3 V_49 ;
T_3 V_50 ;
V_48 = V_21 + V_29 - 1 ;
error = F_25 ( V_3 , V_4 , V_21 , V_29 , 1 ) ;
if ( error ) {
return error ;
}
error = F_8 ( V_3 , V_4 , V_21 , 0 , & V_50 ) ;
if ( error ) {
return error ;
}
error = F_15 ( V_3 , V_4 , V_48 , V_3 -> V_51 . V_52 - 1 ,
& V_49 ) ;
if ( error )
return error ;
if ( V_50 < V_21 ) {
error = F_24 ( V_3 , V_4 ,
F_27 ( V_21 - V_50 ) ,
F_9 ( V_3 , V_50 ) , - 1 , V_40 , V_41 ) ;
if ( error ) {
return error ;
}
}
if ( V_49 > V_48 ) {
error = F_24 ( V_3 , V_4 ,
F_27 ( V_49 - V_48 ) ,
F_9 ( V_3 , V_48 + 1 ) , - 1 , V_40 , V_41 ) ;
if ( error ) {
return error ;
}
}
error = F_24 ( V_3 , V_4 ,
F_27 ( V_49 + 1 - V_50 ) ,
F_9 ( V_3 , V_50 ) , 1 , V_40 , V_41 ) ;
return error ;
}
int
F_28 (
T_1 * V_3 ,
T_2 * V_4 ,
T_3 V_21 ,
T_11 V_29 ,
int V_47 ,
T_3 * V_53 ,
int * V_54 )
{
T_7 * V_24 ;
int V_25 ;
T_3 V_5 ;
T_4 * V_2 ;
T_7 * V_26 ;
int error ;
T_3 V_28 ;
T_3 V_37 ;
T_7 V_30 ;
T_7 V_32 ;
int V_33 ;
V_5 = F_9 ( V_3 , V_21 ) ;
error = F_3 ( V_3 , V_4 , V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_26 = V_2 -> V_34 ;
V_33 = F_10 ( V_3 , V_21 ) ;
V_24 = & V_26 [ V_33 ] ;
V_25 = ( int ) ( V_21 & ( V_35 - 1 ) ) ;
V_47 = - V_47 ;
if ( V_25 ) {
V_37 = F_16 ( V_25 + V_29 , V_35 ) ;
V_30 = ( ( ( T_7 ) 1 << ( V_37 - V_25 ) ) - 1 ) << V_25 ;
if ( ( V_32 = ( * V_24 ^ V_47 ) & V_30 ) ) {
F_12 ( V_4 , V_2 ) ;
V_28 = F_17 ( V_32 ) - V_25 ;
* V_53 = V_21 + V_28 ;
* V_54 = 0 ;
return 0 ;
}
V_28 = V_37 - V_25 ;
if ( ++ V_33 == F_18 ( V_3 ) && V_28 < V_29 ) {
F_12 ( V_4 , V_2 ) ;
error = F_3 ( V_3 , V_4 , ++ V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_24 = V_26 = V_2 -> V_34 ;
V_33 = 0 ;
} else {
V_24 ++ ;
}
} else {
V_28 = 0 ;
}
while ( V_29 - V_28 >= V_35 ) {
if ( ( V_32 = * V_24 ^ V_47 ) ) {
F_12 ( V_4 , V_2 ) ;
V_28 += F_17 ( V_32 ) ;
* V_53 = V_21 + V_28 ;
* V_54 = 0 ;
return 0 ;
}
V_28 += V_35 ;
if ( ++ V_33 == F_18 ( V_3 ) && V_28 < V_29 ) {
F_12 ( V_4 , V_2 ) ;
error = F_3 ( V_3 , V_4 , ++ V_5 , 0 , & V_2 ) ;
if ( error ) {
return error ;
}
V_24 = V_26 = V_2 -> V_34 ;
V_33 = 0 ;
} else {
V_24 ++ ;
}
}
if ( ( V_37 = V_29 - V_28 ) ) {
V_30 = ( ( T_7 ) 1 << V_37 ) - 1 ;
if ( ( V_32 = ( * V_24 ^ V_47 ) & V_30 ) ) {
F_12 ( V_4 , V_2 ) ;
V_28 += F_17 ( V_32 ) ;
* V_53 = V_21 + V_28 ;
* V_54 = 0 ;
return 0 ;
} else
V_28 = V_29 ;
}
F_12 ( V_4 , V_2 ) ;
* V_53 = V_21 + V_28 ;
* V_54 = 1 ;
return 0 ;
}
STATIC int
F_29 (
T_1 * V_3 ,
T_2 * V_4 ,
T_3 V_55 ,
T_11 V_29 )
{
T_3 V_53 ;
int V_54 ;
int error ;
error = F_28 ( V_3 , V_4 , V_55 , V_29 , 0 , & V_53 , & V_54 ) ;
if ( error )
return error ;
ASSERT ( V_54 ) ;
return 0 ;
}
int
F_30 (
T_2 * V_4 ,
T_3 V_55 ,
T_11 V_29 )
{
int error ;
T_1 * V_3 ;
T_8 V_43 ;
T_4 * V_56 = NULL ;
V_3 = V_4 -> V_57 ;
ASSERT ( V_3 -> V_12 -> V_58 != NULL ) ;
ASSERT ( F_31 ( V_3 -> V_12 , V_59 ) ) ;
error = F_29 ( V_3 , V_4 , V_55 , V_29 ) ;
if ( error )
return error ;
error = F_26 ( V_3 , V_4 , V_55 , V_29 , & V_56 , & V_43 ) ;
if ( error ) {
return error ;
}
F_32 ( V_4 , V_60 , ( long ) V_29 ) ;
if ( V_4 -> V_61 + V_3 -> V_51 . V_62 ==
V_3 -> V_51 . V_52 ) {
if ( ! ( V_3 -> V_12 -> V_63 . V_64 & V_65 ) )
V_3 -> V_12 -> V_63 . V_64 |= V_65 ;
* ( V_66 * ) & F_33 ( V_3 -> V_12 ) -> V_67 = 0 ;
F_34 ( V_4 , V_3 -> V_12 , V_68 ) ;
}
return 0 ;
}
