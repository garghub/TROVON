static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * * V_5 )
{
int V_6 ;
struct V_4 * V_7 ;
T_2 V_8 ;
V_7 = F_2 ( & V_2 -> V_9 -> V_10 , V_11 ,
& V_8 , V_3 ) ;
if ( V_7 == NULL )
return - V_12 ;
V_7 -> V_8 = V_8 ;
F_3 ( V_7 , V_13 , V_7 -> V_8 ) ;
V_7 -> V_14 = NULL ;
V_7 -> V_5 = 0 ;
for ( V_6 = 0 ;
V_6 < ( V_11 - sizeof( struct V_4 ) -
sizeof( V_15 ) ) / sizeof( V_15 ) - 1 ;
V_6 ++ ) {
V_7 -> V_16 [ V_6 ] = V_6 + 1 ;
}
V_7 -> V_16 [ V_6 ] = 0xFFFF ;
* V_5 = V_7 ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * * V_17 )
{
return F_1 ( V_2 , V_3 , V_17 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_4 * V_17 )
{
struct V_4 * V_14 ;
while ( V_17 ) {
V_14 = V_17 -> V_14 ;
F_6 ( & V_2 -> V_9 -> V_10 , V_11 , V_17 ,
F_7 ( V_17 , V_13 ) ) ;
V_17 = V_14 ;
}
}
T_3 * F_8 ( struct V_1 * V_2 , struct V_4 * V_5 ,
T_2 * V_8 , T_1 V_3 )
{
V_15 V_18 ;
while ( V_5 ) {
V_18 = V_5 -> V_5 ;
if ( V_18 != 0xFFFF ) {
V_5 -> V_5 = V_5 -> V_16 [ V_18 ] ;
break;
} else if ( V_5 -> V_14 == NULL ) {
if ( F_1 ( V_2 , V_3 , & V_5 -> V_14 ) ==
0 ) {
V_5 = V_5 -> V_14 ;
V_18 = V_5 -> V_5 ;
V_5 -> V_5 = V_5 -> V_16 [ V_18 ] ;
break;
} else
return NULL ;
} else
V_5 = V_5 -> V_14 ;
}
if ( V_5 ) {
* V_8 = V_5 -> V_8 +
( ( unsigned long ) & ( V_5 -> V_16 [ V_18 ] ) -
( unsigned long ) V_5 ) ;
F_9 ( L_1 , V_19 ,
& ( V_5 -> V_16 [ V_18 ] ) , ( unsigned long long ) * V_8 ) ;
return ( V_20 T_3 * ) & ( V_5 -> V_16 [ V_18 ] ) ;
}
return NULL ;
}
void F_10 ( T_3 * V_18 )
{
struct V_4 * V_5 ;
V_15 V_21 ;
V_5 = (struct V_4 * ) ( ( unsigned long ) V_18 & V_22 ) ;
* V_18 = ( V_20 T_3 ) V_5 -> V_5 ;
V_21 = ( ( unsigned long ) V_18 & ~ V_22 ) >> 1 ;
V_21 -= ( unsigned long ) & ( ( (struct V_4 * ) 0 ) -> V_16 [ 0 ] ) >> 1 ;
V_5 -> V_16 [ V_21 ] = V_5 -> V_5 ;
V_5 -> V_5 = V_21 ;
}
