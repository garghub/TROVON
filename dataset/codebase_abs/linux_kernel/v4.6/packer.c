static T_1 F_1 ( int V_1 , int V_2 , void * V_3 )
{
switch ( V_2 ) {
case 1 : return * ( V_4 * ) ( V_3 + V_1 ) ;
case 2 : return F_2 ( ( V_5 * ) ( V_3 + V_1 ) ) ;
case 4 : return F_3 ( ( V_6 * ) ( V_3 + V_1 ) ) ;
case 8 : return F_4 ( ( V_7 * ) ( V_3 + V_1 ) ) ;
default:
F_5 ( L_1 , V_2 * 8 ) ;
return 0 ;
}
}
void F_6 ( const struct V_8 * V_9 ,
int V_10 ,
void * V_3 ,
void * V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_10 ; ++ V_12 ) {
if ( V_9 [ V_12 ] . V_13 <= 32 ) {
int V_14 ;
T_2 V_15 ;
V_6 V_16 ;
V_6 * V_17 ;
V_14 = 32 - V_9 [ V_12 ] . V_18 - V_9 [ V_12 ] . V_13 ;
if ( V_9 [ V_12 ] . V_19 )
V_15 = F_1 ( V_9 [ V_12 ] . V_20 ,
V_9 [ V_12 ] . V_19 ,
V_3 ) << V_14 ;
else
V_15 = 0 ;
V_16 = F_7 ( ( ( 1ull << V_9 [ V_12 ] . V_13 ) - 1 ) << V_14 ) ;
V_17 = ( V_6 * ) V_11 + V_9 [ V_12 ] . V_21 ;
* V_17 = ( * V_17 & ~ V_16 ) | ( F_7 ( V_15 ) & V_16 ) ;
} else if ( V_9 [ V_12 ] . V_13 <= 64 ) {
int V_14 ;
T_1 V_15 ;
V_7 V_16 ;
V_7 * V_17 ;
V_14 = 64 - V_9 [ V_12 ] . V_18 - V_9 [ V_12 ] . V_13 ;
if ( V_9 [ V_12 ] . V_19 )
V_15 = F_1 ( V_9 [ V_12 ] . V_20 ,
V_9 [ V_12 ] . V_19 ,
V_3 ) << V_14 ;
else
V_15 = 0 ;
V_16 = F_8 ( ( ~ 0ull >> ( 64 - V_9 [ V_12 ] . V_13 ) ) << V_14 ) ;
V_17 = ( V_7 * ) ( ( V_6 * ) V_11 + V_9 [ V_12 ] . V_21 ) ;
* V_17 = ( * V_17 & ~ V_16 ) | ( F_8 ( V_15 ) & V_16 ) ;
} else {
if ( V_9 [ V_12 ] . V_18 % 8 ||
V_9 [ V_12 ] . V_13 % 8 ) {
F_5 ( L_2 ,
V_9 [ V_12 ] . V_22 , V_9 [ V_12 ] . V_13 ) ;
}
if ( V_9 [ V_12 ] . V_19 )
memcpy ( V_11 + V_9 [ V_12 ] . V_21 * 4 +
V_9 [ V_12 ] . V_18 / 8 ,
V_3 + V_9 [ V_12 ] . V_20 ,
V_9 [ V_12 ] . V_13 / 8 ) ;
else
memset ( V_11 + V_9 [ V_12 ] . V_21 * 4 +
V_9 [ V_12 ] . V_18 / 8 ,
0 ,
V_9 [ V_12 ] . V_13 / 8 ) ;
}
}
}
static void F_9 ( int V_1 , int V_2 , T_1 V_15 , void * V_3 )
{
switch ( V_2 * 8 ) {
case 8 : * ( V_4 * ) ( V_3 + V_1 ) = V_15 ; break;
case 16 : * ( V_5 * ) ( V_3 + V_1 ) = F_10 ( V_15 ) ; break;
case 32 : * ( V_6 * ) ( V_3 + V_1 ) = F_7 ( V_15 ) ; break;
case 64 : * ( V_7 * ) ( V_3 + V_1 ) = F_8 ( V_15 ) ; break;
default:
F_5 ( L_1 , V_2 * 8 ) ;
}
}
void F_11 ( const struct V_8 * V_9 ,
int V_10 ,
void * V_11 ,
void * V_3 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_10 ; ++ V_12 ) {
if ( ! V_9 [ V_12 ] . V_19 )
continue;
if ( V_9 [ V_12 ] . V_13 <= 32 ) {
int V_14 ;
T_2 V_15 ;
T_2 V_16 ;
V_6 * V_17 ;
V_14 = 32 - V_9 [ V_12 ] . V_18 - V_9 [ V_12 ] . V_13 ;
V_16 = ( ( 1ull << V_9 [ V_12 ] . V_13 ) - 1 ) << V_14 ;
V_17 = ( V_6 * ) V_11 + V_9 [ V_12 ] . V_21 ;
V_15 = ( F_3 ( V_17 ) & V_16 ) >> V_14 ;
F_9 ( V_9 [ V_12 ] . V_20 ,
V_9 [ V_12 ] . V_19 ,
V_15 ,
V_3 ) ;
} else if ( V_9 [ V_12 ] . V_13 <= 64 ) {
int V_14 ;
T_1 V_15 ;
T_1 V_16 ;
V_7 * V_17 ;
V_14 = 64 - V_9 [ V_12 ] . V_18 - V_9 [ V_12 ] . V_13 ;
V_16 = ( ~ 0ull >> ( 64 - V_9 [ V_12 ] . V_13 ) ) << V_14 ;
V_17 = ( V_7 * ) V_11 + V_9 [ V_12 ] . V_21 ;
V_15 = ( F_4 ( V_17 ) & V_16 ) >> V_14 ;
F_9 ( V_9 [ V_12 ] . V_20 ,
V_9 [ V_12 ] . V_19 ,
V_15 ,
V_3 ) ;
} else {
if ( V_9 [ V_12 ] . V_18 % 8 ||
V_9 [ V_12 ] . V_13 % 8 ) {
F_5 ( L_2 ,
V_9 [ V_12 ] . V_22 , V_9 [ V_12 ] . V_13 ) ;
}
memcpy ( V_3 + V_9 [ V_12 ] . V_20 ,
V_11 + V_9 [ V_12 ] . V_21 * 4 +
V_9 [ V_12 ] . V_18 / 8 ,
V_9 [ V_12 ] . V_13 / 8 ) ;
}
}
}
