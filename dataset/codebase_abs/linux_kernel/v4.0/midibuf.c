static int F_1 ( unsigned char V_1 )
{
int V_2 ;
if ( V_1 < 0x80 )
V_2 = - 1 ;
else if ( V_1 < 0xf0 ) {
static const int V_3 [] = { 3 , 3 , 3 , 3 , 2 , 2 , 3 } ;
V_2 = V_3 [ ( V_1 >> 4 ) - 8 ] ;
} else {
static const int V_3 [] = { - 1 , 2 , - 1 , 2 , - 1 , - 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , - 1 , 1 , 1
} ;
V_2 = V_3 [ V_1 & 0x0f ] ;
}
return V_2 ;
}
static int F_2 ( struct V_4 * V_5 )
{
return ( V_5 -> V_6 == V_5 -> V_7 ) && ! V_5 -> V_8 ;
}
static int F_3 ( struct V_4 * V_5 )
{
return V_5 -> V_8 ;
}
void F_4 ( struct V_4 * V_5 )
{
V_5 -> V_6 = V_5 -> V_7 = V_5 -> V_8 = 0 ;
V_5 -> V_9 = - 1 ;
}
int F_5 ( struct V_4 * V_5 , int V_10 , int V_11 )
{
V_5 -> V_12 = F_6 ( V_10 , V_13 ) ;
if ( V_5 -> V_12 == NULL )
return - V_14 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_11 = V_11 ;
F_4 ( V_5 ) ;
return 0 ;
}
int F_7 ( struct V_4 * V_5 )
{
return
F_3 ( V_5 ) ?
0 :
( V_5 -> V_6 - V_5 -> V_7 + V_5 -> V_10 - 1 ) % V_5 -> V_10 +
1 ;
}
int F_8 ( struct V_4 * V_5 )
{
return
F_2 ( V_5 ) ?
0 :
( V_5 -> V_7 - V_5 -> V_6 + V_5 -> V_10 - 1 ) % V_5 -> V_10 +
1 ;
}
int F_9 ( struct V_4 * V_5 , unsigned char * V_15 ,
int V_3 )
{
int V_16 ;
int V_17 , V_18 ;
int V_19 = 0 ;
if ( F_3 ( V_5 ) || ( V_3 <= 0 ) )
return 0 ;
if ( V_15 [ V_3 - 1 ] == 0xfe ) {
-- V_3 ;
V_19 = 1 ;
}
V_16 = F_7 ( V_5 ) ;
if ( V_3 > V_16 )
V_3 = V_16 ;
if ( V_3 > 0 ) {
V_17 = V_5 -> V_10 - V_5 -> V_7 ;
if ( V_3 < V_17 ) {
memcpy ( V_5 -> V_12 + V_5 -> V_7 , V_15 , V_3 ) ;
V_5 -> V_7 += V_3 ;
} else {
V_18 = V_3 - V_17 ;
memcpy ( V_5 -> V_12 + V_5 -> V_7 , V_15 , V_17 ) ;
memcpy ( V_5 -> V_12 , V_15 + V_17 , V_18 ) ;
V_5 -> V_7 = V_18 ;
}
if ( V_5 -> V_7 == V_5 -> V_6 )
V_5 -> V_8 = 1 ;
}
return V_3 + V_19 ;
}
int F_10 ( struct V_4 * V_5 , unsigned char * V_15 ,
int V_3 )
{
int V_20 ;
int V_17 , V_18 ;
int V_21 ;
int V_22 ;
int V_23 = 0 ;
int V_24 ;
if ( V_3 < 3 )
return - V_25 ;
if ( F_2 ( V_5 ) )
return 0 ;
V_20 = F_8 ( V_5 ) ;
if ( V_3 > V_20 )
V_3 = V_20 ;
V_17 = V_5 -> V_10 - V_5 -> V_6 ;
V_21 = V_5 -> V_12 [ V_5 -> V_6 ] ;
if ( V_21 & 0x80 ) {
V_22 = F_1 ( V_21 ) ;
V_5 -> V_9 = V_21 ;
} else {
if ( V_5 -> V_9 > 0 ) {
int V_26 =
F_1 ( V_5 -> V_9 ) ;
if ( V_26 > 0 ) {
V_22 = V_26 - 1 ;
V_23 = 1 ;
} else
V_22 = - 1 ;
} else
V_22 = - 1 ;
}
if ( V_22 < 0 ) {
if ( V_3 < V_17 ) {
for ( V_24 = 1 ; V_24 < V_3 ; ++ V_24 )
if ( V_5 -> V_12 [ V_5 -> V_6 + V_24 ] & 0x80 )
break;
V_22 = V_24 ;
} else {
V_18 = V_3 - V_17 ;
for ( V_24 = 1 ; V_24 < V_17 ; ++ V_24 )
if ( V_5 -> V_12 [ V_5 -> V_6 + V_24 ] & 0x80 )
break;
if ( V_24 < V_17 )
V_22 = V_24 ;
else {
for ( V_24 = 0 ; V_24 < V_18 ; ++ V_24 )
if ( V_5 -> V_12 [ V_24 ] & 0x80 )
break;
V_22 = V_17 + V_24 ;
}
}
if ( V_22 == V_3 )
V_22 = - 1 ;
}
if ( V_22 < 0 ) {
if ( ! V_5 -> V_11 )
return 0 ;
} else {
if ( V_3 < V_22 )
return 0 ;
V_3 = V_22 ;
}
if ( V_3 < V_17 ) {
memcpy ( V_15 + V_23 , V_5 -> V_12 + V_5 -> V_6 , V_3 ) ;
V_5 -> V_6 += V_3 ;
} else {
V_18 = V_3 - V_17 ;
memcpy ( V_15 + V_23 , V_5 -> V_12 + V_5 -> V_6 , V_17 ) ;
memcpy ( V_15 + V_23 + V_17 , V_5 -> V_12 , V_18 ) ;
V_5 -> V_6 = V_18 ;
}
if ( V_23 )
V_15 [ 0 ] = V_5 -> V_9 ;
V_5 -> V_8 = 0 ;
return V_3 + V_23 ;
}
int F_11 ( struct V_4 * V_5 , int V_3 )
{
int V_20 = F_8 ( V_5 ) ;
if ( V_3 > V_20 )
V_3 = V_20 ;
V_5 -> V_6 = ( V_5 -> V_6 + V_3 ) % V_5 -> V_10 ;
V_5 -> V_8 = 0 ;
return V_3 ;
}
void F_12 ( struct V_4 * V_5 )
{
F_13 ( V_5 -> V_12 ) ;
V_5 -> V_12 = NULL ;
}
