static void F_1 ( struct V_1 * V_2 , short V_3 )
{
T_1 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 , V_6 , & V_4 ) ;
if ( V_5 )
return;
if ( V_3 )
F_3 ( V_2 , V_6 , V_4 | V_7 ) ;
else
F_3 ( V_2 , V_6 , V_4 & ~ V_7 ) ;
F_4 ( V_2 ) ;
F_5 ( V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 , V_6 , & V_4 ) ;
if ( V_5 )
return;
F_3 ( V_2 , V_6 , V_4 | V_9 ) ;
F_4 ( V_2 ) ;
F_5 ( V_8 ) ;
F_2 ( V_2 , V_6 , & V_4 ) ;
F_3 ( V_2 , V_6 , V_4 & ~ V_9 ) ;
F_4 ( V_2 ) ;
F_5 ( V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 , short V_3 )
{
T_1 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 , V_6 , & V_4 ) ;
if ( V_5 )
return;
if ( V_3 )
F_3 ( V_2 , V_6 , V_4 | V_10 ) ;
else
F_3 ( V_2 , V_6 , V_4 & ~ V_10 ) ;
F_4 ( V_2 ) ;
F_5 ( V_8 ) ;
}
static short F_8 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_5 ;
V_5 = F_2 ( V_2 , V_6 , & V_3 ) ;
if ( V_5 )
return V_5 ;
F_5 ( V_8 ) ;
if ( V_3 & V_11 )
return 1 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , short V_12 [] , int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
F_7 ( V_2 , V_12 [ V_14 ] ) ;
F_6 ( V_2 ) ;
}
}
int F_10 ( struct V_1 * V_2 , T_2 V_15 )
{
struct V_16 * V_17 = F_11 ( V_2 ) ;
short V_18 [] = { 1 , 1 , 0 } ;
short V_19 [ 8 ] ;
int V_14 ;
int V_20 ;
T_2 V_21 ;
int V_5 ;
V_21 = 0 ;
F_3 ( V_2 , V_6 ,
( V_22 << V_23 ) ) ;
F_4 ( V_2 ) ;
F_5 ( V_8 ) ;
if ( V_17 -> V_24 == V_25 ) {
V_19 [ 7 ] = V_15 & 1 ;
V_19 [ 6 ] = V_15 & ( 1 << 1 ) ;
V_19 [ 5 ] = V_15 & ( 1 << 2 ) ;
V_19 [ 4 ] = V_15 & ( 1 << 3 ) ;
V_19 [ 3 ] = V_15 & ( 1 << 4 ) ;
V_19 [ 2 ] = V_15 & ( 1 << 5 ) ;
V_19 [ 1 ] = V_15 & ( 1 << 6 ) ;
V_19 [ 0 ] = V_15 & ( 1 << 7 ) ;
V_20 = 8 ;
} else {
V_19 [ 5 ] = V_15 & 1 ;
V_19 [ 4 ] = V_15 & ( 1 << 1 ) ;
V_19 [ 3 ] = V_15 & ( 1 << 2 ) ;
V_19 [ 2 ] = V_15 & ( 1 << 3 ) ;
V_19 [ 1 ] = V_15 & ( 1 << 4 ) ;
V_19 [ 0 ] = V_15 & ( 1 << 5 ) ;
V_20 = 6 ;
}
F_1 ( V_2 , 1 ) ;
F_6 ( V_2 ) ;
F_9 ( V_2 , V_18 , 3 ) ;
F_9 ( V_2 , V_19 , V_20 ) ;
F_7 ( V_2 , 0 ) ;
for ( V_14 = 0 ; V_14 < 16 ; V_14 ++ ) {
F_6 ( V_2 ) ;
V_5 = F_8 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_21 |= V_5 << ( 15 - V_14 ) ;
}
F_1 ( V_2 , 0 ) ;
F_6 ( V_2 ) ;
F_3 ( V_2 , V_6 ,
( V_26 << V_23 ) ) ;
return V_21 ;
}
