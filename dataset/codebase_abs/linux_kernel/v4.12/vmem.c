static void
F_1 (
T_1 * V_1 ,
unsigned V_2 ,
T_1 V_3 ,
unsigned V_4 ,
unsigned V_5 )
{
unsigned int V_6 = V_2 / V_7 ;
unsigned int V_8 = V_2 % V_7 ;
unsigned V_9 = V_5 - V_4 ;
T_1 V_10 = F_2 ( V_3 , V_4 , V_5 ) ;
if ( V_9 + V_8 > V_7 ) {
T_1 V_11 ;
T_1 V_12 = F_3 ( V_1 [ V_6 ] , V_8 , V_7 ) ;
V_1 [ V_6 ] = V_12 | ( V_10 << V_8 ) ;
V_11 = F_3 ( V_1 [ V_6 + 1 ] , 0 , V_9 + V_8 - V_7 ) ;
V_1 [ V_6 + 1 ] = V_11 | ( V_10 >> ( V_7 - V_8 ) ) ;
} else {
T_1 V_13 = F_3 ( V_1 [ V_6 ] , V_8 , V_8 + V_9 ) ;
V_1 [ V_6 ] = V_13 | ( V_10 << V_8 ) ;
}
}
static void
F_4 (
T_2 V_14 ,
T_2 V_15 ,
T_3 V_16 ,
T_3 V_17 )
{
unsigned int V_6 = ( V_16 * V_17 ) / V_7 ;
unsigned int V_8 = ( V_16 * V_17 ) % V_7 ;
unsigned int V_18 = ( V_16 * ( V_17 + 1 ) - 1 ) / V_7 ;
unsigned int V_19 = ( ( V_16 * ( V_17 + 1 ) - 1 ) % V_7 ) + 1 ;
if ( V_16 == V_7 ) {
V_15 [ 0 ] = V_14 [ V_17 ] ;
} else if ( V_6 == V_18 ) {
F_1 ( V_15 , 0 , V_14 [ V_6 ] , V_8 , V_19 ) ;
} else {
unsigned int V_20 = 0 ;
unsigned int V_21 ;
F_5 ( V_15 , V_20 , V_14 [ V_6 ] , V_8 ) ;
V_20 += ( 64 - V_8 ) ;
for( V_21 = V_6 + 1 ; V_21 < V_18 ; V_21 ++ ) {
F_6 ( V_15 , V_20 , V_14 [ V_21 ] ) ;
V_20 += V_7 ;
}
F_7 ( V_15 , V_20 , V_14 [ V_18 ] , V_19 ) ;
}
}
static void
F_8 (
T_2 V_14 ,
T_2 V_15 ,
T_3 V_16 ,
T_3 V_17 )
{
unsigned int V_6 = ( V_16 * V_17 ) / V_7 ;
if ( V_16 == V_7 ) {
V_14 [ V_6 ] = V_15 [ 0 ] ;
} else if ( V_16 > V_7 ) {
unsigned V_22 = V_16 ;
unsigned V_8 = V_16 * V_17 ;
unsigned V_21 = 0 ;
for(; V_22 > V_7 ; V_22 -= V_7 , V_21 ++ , V_8 += V_7 ) {
F_6 ( V_14 , V_8 , V_15 [ V_21 ] ) ;
}
F_7 ( V_14 , V_8 , V_15 [ V_21 ] , V_22 ) ;
} else {
F_7 ( V_14 , V_16 * V_17 , V_15 [ 0 ] , V_16 ) ;
}
}
static void F_9 (
const T_4 V_23 ,
T_5 * V_24 ,
const T_5 * V_25 )
{
unsigned V_21 ;
T_1 * V_26 ;
unsigned V_27 = sizeof( short ) * V_28 ;
F_10 ( V_29 , 2 * V_28 ) ;
assert ( V_30 [ V_23 ] != ( V_31 ) - 1 ) ;
#if ! F_11 ( V_32 )
F_12 ( V_30 [ V_23 ] + ( unsigned long ) V_25 , & V_29 [ 0 ] [ 0 ] , V_27 ) ;
#else
F_13 ( V_30 [ V_23 ] + ( unsigned long ) V_25 , & V_29 [ 0 ] [ 0 ] , V_27 ) ;
#endif
V_26 = ( T_1 * ) V_29 ;
for ( V_21 = 0 ; V_21 < V_28 ; V_21 ++ ) {
T_1 V_15 = 0 ;
F_4 ( V_26 , & V_15 , V_33 , V_21 ) ;
V_24 [ V_21 ] = V_15 ;
}
F_14 () ;
}
static void F_15 (
const T_4 V_23 ,
T_5 * V_24 ,
const T_5 * V_25 )
{
unsigned V_21 ;
unsigned V_27 = sizeof( short ) * V_28 ;
F_10 ( V_29 , 2 * V_28 ) ;
T_1 * V_26 = ( T_1 * ) V_29 ;
for ( V_21 = 0 ; V_21 < V_28 ; V_21 ++ ) {
F_8 ( V_26 , ( T_2 ) & V_25 [ V_21 ] , V_33 , V_21 ) ;
}
assert ( V_30 [ V_23 ] != ( V_31 ) - 1 ) ;
#if ! F_11 ( V_32 )
F_16 ( V_30 [ V_23 ] + ( unsigned long ) V_24 , & V_29 , V_27 ) ;
#else
F_17 ( V_30 [ V_23 ] + ( unsigned long ) V_24 , & V_29 , V_27 ) ;
#endif
F_14 () ;
}
void F_18 (
const T_4 V_23 ,
const T_5 * V_25 ,
T_5 * V_24 ,
unsigned V_34 )
{
unsigned V_35 ;
const T_5 * V_36 = V_25 ;
assert ( V_23 < V_37 ) ;
assert ( ( unsigned long ) V_25 % V_38 == 0 ) ;
assert ( V_34 % V_28 == 0 ) ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 += V_28 ) {
F_9 ( V_23 , & V_24 [ V_35 ] , V_36 ) ;
V_36 = ( T_5 * ) ( ( char * ) V_36 + V_38 ) ;
}
}
void F_19 (
const T_4 V_23 ,
T_5 * V_24 ,
const T_5 * V_25 ,
unsigned V_34 )
{
unsigned V_35 ;
T_5 * V_36 = V_24 ;
assert ( V_23 < V_37 ) ;
assert ( ( unsigned long ) V_24 % V_38 == 0 ) ;
assert ( V_34 % V_28 == 0 ) ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 += V_28 ) {
F_15 ( V_23 , V_36 , & V_25 [ V_35 ] ) ;
V_36 = ( T_5 * ) ( ( char * ) V_36 + V_38 ) ;
}
}
void F_20 (
const T_4 V_23 ,
const T_5 * V_25 ,
T_5 * V_24 ,
unsigned V_39 ,
unsigned V_40 ,
unsigned V_41 ,
unsigned V_42 )
{
unsigned V_43 ;
assert ( V_23 < V_37 ) ;
assert ( ( unsigned long ) V_25 % V_38 == 0 ) ;
assert ( V_40 % V_28 == 0 ) ;
assert ( V_42 % V_28 == 0 ) ;
for ( V_43 = 0 ; V_43 < V_39 ; V_43 ++ ) {
unsigned V_35 ;
const T_5 * V_36 = V_25 ;
for ( V_35 = 0 ; V_35 < V_40 ; V_35 += V_28 ) {
F_9 ( V_23 , & V_24 [ V_41 * V_43 + V_35 ] , V_36 ) ;
V_36 = ( T_5 * ) ( ( char * ) V_36 + V_38 ) ;
}
V_25 = ( const T_5 * ) ( ( const char * ) V_25 + V_42 / V_28 * V_38 ) ;
}
}
void F_21 (
const T_4 V_23 ,
T_5 * V_24 ,
const T_5 * V_25 ,
unsigned V_39 ,
unsigned V_40 ,
unsigned V_41 ,
unsigned V_42 )
{
unsigned V_43 ;
assert ( V_23 < V_37 ) ;
assert ( ( unsigned long ) V_24 % V_38 == 0 ) ;
assert ( V_40 % V_28 == 0 ) ;
assert ( V_41 % V_28 == 0 ) ;
for ( V_43 = 0 ; V_43 < V_39 ; V_43 ++ ) {
unsigned V_35 ;
T_5 * V_36 = V_24 ;
for ( V_35 = 0 ; V_35 < V_40 ; V_35 += V_28 ) {
F_15 ( V_23 , V_36 , & V_25 [ V_42 * V_43 + V_35 ] ) ;
V_36 = ( T_5 * ) ( ( char * ) V_36 + V_38 ) ;
}
V_24 = ( T_5 * ) ( ( char * ) V_24 + V_41 / V_28 * V_38 ) ;
}
}
