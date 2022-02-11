static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_5 , const T_2 * V_6 ,
struct V_7 * V_8 , bool V_9 )
{
int V_10 ;
unsigned int V_11 ;
T_2 V_12 = V_6 [ 0 ] , V_13 ;
struct V_7 * V_14 = V_8 ;
struct V_1 * V_15 ;
for ( V_10 = 0 ; V_10 < V_4 ; V_10 ++ ) {
V_8 [ V_10 ] . V_16 = NULL ;
V_8 [ V_10 ] . V_3 = 0 ;
}
F_2 (in, sg, nents, i) {
V_11 = V_9 ? F_3 ( V_15 ) : V_15 -> V_17 ;
if ( V_5 > V_11 ) {
V_5 -= V_11 ;
continue;
}
V_13 = F_4 ( T_2 , V_12 , V_11 - V_5 ) ;
if ( ! V_14 -> V_16 ) {
V_14 -> V_16 = V_15 ;
V_14 -> V_18 = V_5 ;
}
V_12 -= V_13 ;
V_14 -> V_3 ++ ;
V_14 -> V_19 = V_13 ;
while ( ! V_12 && ( V_5 + V_13 < V_11 ) && ( -- V_4 > 0 ) ) {
V_14 ++ ;
V_12 = * ( ++ V_6 ) ;
V_5 += V_13 ;
V_13 = F_4 ( T_2 , V_12 , V_11 - V_5 ) ;
V_14 -> V_16 = V_15 ;
V_14 -> V_18 = V_5 ;
V_14 -> V_3 = 1 ;
V_14 -> V_19 = V_13 ;
V_12 -= V_13 ;
}
V_5 = 0 ;
if ( ! V_12 && -- V_4 > 0 ) {
V_14 ++ ;
V_12 = * ( ++ V_6 ) ;
}
if ( ! V_4 )
break;
}
return ( V_12 || ! V_8 [ 0 ] . V_16 ) ? - V_20 : 0 ;
}
static void F_5 ( struct V_7 * V_8 , const int V_4 )
{
int V_10 , V_21 ;
struct V_1 * V_22 , * V_23 ;
struct V_7 * V_24 ;
for ( V_10 = 0 , V_24 = V_8 ; V_10 < V_4 ; V_10 ++ , V_24 ++ ) {
V_22 = V_24 -> V_16 ;
V_23 = V_24 -> V_23 ;
for ( V_21 = 0 ; V_21 < V_24 -> V_3 ; V_21 ++ , V_23 ++ ) {
* V_23 = * V_22 ;
if ( ! V_21 ) {
V_23 -> V_25 += V_24 -> V_18 ;
V_23 -> V_17 -= V_24 -> V_18 ;
} else {
V_23 -> V_25 = 0 ;
}
F_6 ( V_23 ) = 0 ;
F_3 ( V_23 ) = 0 ;
V_22 = F_7 ( V_22 ) ;
}
V_23 [ - 1 ] . V_17 = V_24 -> V_19 ;
F_8 ( V_23 - 1 ) ;
}
}
static void F_9 ( struct V_7 * V_8 , const int V_4 )
{
int V_10 , V_21 ;
struct V_1 * V_22 , * V_23 ;
struct V_7 * V_24 ;
for ( V_10 = 0 , V_24 = V_8 ; V_10 < V_4 ; V_10 ++ , V_24 ++ ) {
V_22 = V_24 -> V_16 ;
V_23 = V_24 -> V_23 ;
for ( V_21 = 0 ; V_21 < V_24 -> V_3 ; V_21 ++ , V_23 ++ ) {
F_6 ( V_23 ) = F_6 ( V_22 ) ;
F_3 ( V_23 ) = F_3 ( V_22 ) ;
if ( ! V_21 ) {
F_6 ( V_23 ) += V_24 -> V_18 ;
F_3 ( V_23 ) -= V_24 -> V_18 ;
}
V_22 = F_7 ( V_22 ) ;
}
F_3 ( -- V_23 ) = V_24 -> V_19 ;
}
}
int F_10 ( struct V_1 * V_2 , const int V_26 ,
const T_1 V_5 , const int V_4 ,
const T_2 * V_27 ,
struct V_1 * * V_28 , int * V_29 ,
T_3 V_30 )
{
int V_10 , V_31 ;
struct V_7 * V_8 ;
V_8 = F_11 ( V_4 , sizeof( * V_8 ) , V_30 ) ;
if ( ! V_8 )
return - V_32 ;
V_31 = F_1 ( V_2 , F_12 ( V_2 ) , V_4 , V_5 , V_27 ,
V_8 , false ) ;
if ( V_31 < 0 )
goto V_33;
V_31 = - V_32 ;
for ( V_10 = 0 ; V_10 < V_4 ; V_10 ++ ) {
V_8 [ V_10 ] . V_23 = F_13 ( V_8 [ V_10 ] . V_3 ,
sizeof( struct V_1 ) ,
V_30 ) ;
if ( ! V_8 [ V_10 ] . V_23 )
goto V_33;
}
F_5 ( V_8 , V_4 ) ;
V_31 = F_1 ( V_2 , V_26 , V_4 , V_5 ,
V_27 , V_8 , true ) ;
if ( V_31 < 0 )
goto V_33;
F_9 ( V_8 , V_4 ) ;
for ( V_10 = 0 ; V_10 < V_4 ; V_10 ++ ) {
V_28 [ V_10 ] = V_8 [ V_10 ] . V_23 ;
if ( V_29 )
V_29 [ V_10 ] = V_8 [ V_10 ] . V_3 ;
}
F_14 ( V_8 ) ;
return 0 ;
V_33:
for ( V_10 = 0 ; V_10 < V_4 ; V_10 ++ )
F_14 ( V_8 [ V_10 ] . V_23 ) ;
F_14 ( V_8 ) ;
return V_31 ;
}
