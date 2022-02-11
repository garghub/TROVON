static struct V_1 * F_1 ( int V_2 , int V_3 , int (* F_2)( int ) ,
int V_4 , int V_5 , int V_6 )
{
struct V_1 * V_7 ;
int V_8 , V_9 , V_10 , V_11 , V_12 ;
V_7 = F_3 ( sizeof ( struct V_1 ) , V_13 ) ;
if ( V_7 == NULL )
return NULL ;
F_4 ( & V_7 -> V_14 ) ;
V_7 -> V_15 = V_2 ;
V_7 -> V_16 = ( 1 << V_2 ) - 1 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_6 = V_6 ;
V_7 -> V_3 = V_3 ;
V_7 -> F_2 = F_2 ;
V_7 -> V_17 = F_3 ( sizeof( V_18 ) * ( V_7 -> V_16 + 1 ) , V_13 ) ;
if ( V_7 -> V_17 == NULL )
goto V_19;
V_7 -> V_20 = F_3 ( sizeof( V_18 ) * ( V_7 -> V_16 + 1 ) , V_13 ) ;
if ( V_7 -> V_20 == NULL )
goto V_21;
V_7 -> V_22 = F_3 ( sizeof( V_18 ) * ( V_7 -> V_6 + 1 ) , V_13 ) ;
if( V_7 -> V_22 == NULL )
goto V_23;
V_7 -> V_20 [ 0 ] = V_7 -> V_16 ;
V_7 -> V_17 [ V_7 -> V_16 ] = 0 ;
if ( V_3 ) {
V_10 = 1 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_16 ; V_8 ++ ) {
V_7 -> V_20 [ V_10 ] = V_8 ;
V_7 -> V_17 [ V_8 ] = V_10 ;
V_10 <<= 1 ;
if ( V_10 & ( 1 << V_2 ) )
V_10 ^= V_3 ;
V_10 &= V_7 -> V_16 ;
}
} else {
V_10 = F_2 ( 0 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_16 ; V_8 ++ ) {
V_7 -> V_20 [ V_10 ] = V_8 ;
V_7 -> V_17 [ V_8 ] = V_10 ;
V_10 = F_2 ( V_10 ) ;
}
}
if( V_10 != V_7 -> V_17 [ 0 ] )
goto V_24;
for( V_12 = 1 ; ( V_12 % V_5 ) != 0 ; V_12 += V_7 -> V_16 ) ;
V_7 -> V_12 = V_12 / V_5 ;
V_7 -> V_22 [ 0 ] = 1 ;
for ( V_8 = 0 , V_11 = V_4 * V_5 ; V_8 < V_6 ; V_8 ++ , V_11 += V_5 ) {
V_7 -> V_22 [ V_8 + 1 ] = 1 ;
for ( V_9 = V_8 ; V_9 > 0 ; V_9 -- ) {
if ( V_7 -> V_22 [ V_9 ] != 0 ) {
V_7 -> V_22 [ V_9 ] = V_7 -> V_22 [ V_9 - 1 ] ^
V_7 -> V_17 [ F_5 ( V_7 ,
V_7 -> V_20 [ V_7 -> V_22 [ V_9 ] ] + V_11 ) ] ;
} else
V_7 -> V_22 [ V_9 ] = V_7 -> V_22 [ V_9 - 1 ] ;
}
V_7 -> V_22 [ 0 ] =
V_7 -> V_17 [ F_5 ( V_7 ,
V_7 -> V_20 [ V_7 -> V_22 [ 0 ] ] + V_11 ) ] ;
}
for ( V_8 = 0 ; V_8 <= V_6 ; V_8 ++ )
V_7 -> V_22 [ V_8 ] = V_7 -> V_20 [ V_7 -> V_22 [ V_8 ] ] ;
return V_7 ;
V_24:
F_6 ( V_7 -> V_22 ) ;
V_23:
F_6 ( V_7 -> V_20 ) ;
V_21:
F_6 ( V_7 -> V_17 ) ;
V_19:
F_6 ( V_7 ) ;
return NULL ;
}
void F_7 ( struct V_1 * V_7 )
{
F_8 ( & V_25 ) ;
V_7 -> V_26 -- ;
if( ! V_7 -> V_26 ) {
F_9 ( & V_7 -> V_14 ) ;
F_6 ( V_7 -> V_17 ) ;
F_6 ( V_7 -> V_20 ) ;
F_6 ( V_7 -> V_22 ) ;
F_6 ( V_7 ) ;
}
F_10 ( & V_25 ) ;
}
static struct V_1 * F_11 ( int V_2 , int V_3 ,
int (* F_2)( int ) , int V_4 ,
int V_5 , int V_6 )
{
struct V_27 * V_28 ;
struct V_1 * V_7 ;
if ( V_2 < 1 )
return NULL ;
if ( V_4 < 0 || V_4 >= ( 1 << V_2 ) )
return NULL ;
if ( V_5 <= 0 || V_5 >= ( 1 << V_2 ) )
return NULL ;
if ( V_6 < 0 || V_6 >= ( 1 << V_2 ) )
return NULL ;
F_8 ( & V_25 ) ;
F_12 (tmp, &rslist) {
V_7 = F_13 ( V_28 , struct V_1 , V_14 ) ;
if ( V_2 != V_7 -> V_15 )
continue;
if ( V_3 != V_7 -> V_3 )
continue;
if ( F_2 != V_7 -> F_2 )
continue;
if ( V_4 != V_7 -> V_4 )
continue;
if ( V_5 != V_7 -> V_5 )
continue;
if ( V_6 != V_7 -> V_6 )
continue;
V_7 -> V_26 ++ ;
goto V_29;
}
V_7 = F_1 ( V_2 , V_3 , F_2 , V_4 , V_5 , V_6 ) ;
if ( V_7 ) {
V_7 -> V_26 = 1 ;
F_14 ( & V_7 -> V_14 , & V_30 ) ;
}
V_29:
F_10 ( & V_25 ) ;
return V_7 ;
}
struct V_1 * F_15 ( int V_2 , int V_3 , int V_4 , int V_5 ,
int V_6 )
{
return F_11 ( V_2 , V_3 , NULL , V_4 , V_5 , V_6 ) ;
}
struct V_1 * F_16 ( int V_2 , int (* F_2)( int ) ,
int V_4 , int V_5 , int V_6 )
{
return F_11 ( V_2 , 0 , F_2 , V_4 , V_5 , V_6 ) ;
}
int F_17 ( struct V_1 * V_7 , T_1 * V_31 , int V_32 , V_18 * V_33 ,
V_18 V_34 )
{
#include "encode_rs.c"
}
int F_18 ( struct V_1 * V_7 , T_1 * V_31 , V_18 * V_33 , int V_32 ,
V_18 * V_35 , int V_36 , int * V_37 , V_18 V_34 ,
V_18 * V_38 )
{
#include "decode_rs.c"
}
int F_19 ( struct V_1 * V_7 , V_18 * V_31 , int V_32 , V_18 * V_33 ,
V_18 V_34 )
{
#include "encode_rs.c"
}
int F_20 ( struct V_1 * V_7 , V_18 * V_31 , V_18 * V_33 , int V_32 ,
V_18 * V_35 , int V_36 , int * V_37 , V_18 V_34 ,
V_18 * V_38 )
{
#include "decode_rs.c"
}
