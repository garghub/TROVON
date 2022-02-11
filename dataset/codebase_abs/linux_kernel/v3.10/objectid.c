static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
if ( F_2 ( V_3 [ 0 ] ) != 1 )
F_3 ( V_2 , L_1 , L_2 ,
( long unsigned int ) F_2 ( V_3 [ 0 ] ) ) ;
}
static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{ ;
}
T_2 F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
T_1 * V_3 = F_6 ( V_2 , V_8 ) ;
T_2 V_9 ;
F_7 ( ! V_5 -> V_10 ) ;
F_1 ( V_2 , V_3 ) ;
F_8 ( V_2 , F_9 ( V_2 ) , 1 ) ;
V_9 = F_2 ( V_3 [ 1 ] ) ;
if ( V_9 == V_11 ) {
F_10 ( V_2 , L_3 , L_4 ) ;
F_11 ( V_2 , F_9 ( V_2 ) ) ;
return 0 ;
}
V_3 [ 1 ] = F_12 ( V_9 + 1 ) ;
if ( F_13 ( V_8 ) > 2 && V_3 [ 1 ] == V_3 [ 2 ] ) {
memmove ( V_3 + 1 , V_3 + 3 ,
( F_13 ( V_8 ) - 3 ) * sizeof( T_2 ) ) ;
F_14 ( V_8 , F_13 ( V_8 ) - 2 ) ;
}
F_15 ( V_5 , V_2 , F_9 ( V_2 ) ) ;
return V_9 ;
}
void F_16 ( struct V_4 * V_5 ,
T_2 V_12 )
{
struct V_1 * V_2 = V_5 -> V_6 ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
T_1 * V_3 = F_6 ( V_2 , V_8 ) ;
int V_13 = 0 ;
F_7 ( ! V_5 -> V_10 ) ;
F_1 ( V_2 , V_3 ) ;
F_8 ( V_2 , F_9 ( V_2 ) , 1 ) ;
F_15 ( V_5 , V_2 , F_9 ( V_2 ) ) ;
while ( V_13 < F_13 ( V_8 ) ) {
if ( V_12 == F_2 ( V_3 [ V_13 ] ) ) {
F_17 ( & V_3 [ V_13 ] , 1 ) ;
if ( V_3 [ V_13 ] == V_3 [ V_13 + 1 ] ) {
memmove ( V_3 + V_13 , V_3 + V_13 + 2 ,
( F_13 ( V_8 ) - V_13 -
2 ) * sizeof( T_2 ) ) ;
F_14 ( V_8 , F_13 ( V_8 ) - 2 ) ;
F_18 ( F_13 ( V_8 ) < 2 ||
F_13 ( V_8 ) > F_19 ( V_8 ) ,
L_5 ,
F_13 ( V_8 ) , F_19 ( V_8 ) ) ;
}
return;
}
if ( V_12 > F_2 ( V_3 [ V_13 ] ) &&
V_12 < F_2 ( V_3 [ V_13 + 1 ] ) ) {
if ( V_12 + 1 == F_2 ( V_3 [ V_13 + 1 ] ) ) {
F_17 ( & V_3 [ V_13 + 1 ] , - 1 ) ;
return;
}
if ( F_13 ( V_8 ) == F_19 ( V_8 ) ) {
F_20 ( V_2 , V_14 ) ;
return;
}
memmove ( V_3 + V_13 + 3 , V_3 + V_13 + 1 ,
( F_13 ( V_8 ) - V_13 - 1 ) * sizeof( T_2 ) ) ;
V_3 [ V_13 + 1 ] = F_12 ( V_12 ) ;
V_3 [ V_13 + 2 ] = F_12 ( V_12 + 1 ) ;
F_14 ( V_8 , F_13 ( V_8 ) + 2 ) ;
return;
}
V_13 += 2 ;
}
F_21 ( V_2 , L_6 , L_7 ,
( long unsigned ) V_12 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_7 * V_15 = F_5 ( V_2 ) ;
int V_16 = F_13 ( V_15 ) ;
int V_17 = ( V_2 -> V_18 - V_19 ) / sizeof( T_2 ) / 2 * 2 ;
int V_20 = F_19 ( V_15 ) ;
struct V_21 * V_22 ;
T_1 * F_6 , * V_23 ;
int V_13 ;
V_22 =
(struct V_21 * ) ( F_9 ( V_2 ) -> V_24 ) ;
F_6 = ( T_1 * ) ( V_22 + 1 ) ;
V_23 = ( T_1 * ) ( V_15 + 1 ) ;
if ( V_16 > V_17 ) {
F_6 [ V_17 - 1 ] = F_6 [ V_16 - 1 ] ;
F_14 ( V_15 , V_17 ) ;
}
for ( V_13 = V_17 - 1 ; V_13 >= 0 ; V_13 -- ) {
F_6 [ V_13 + ( V_20 - V_17 ) ] = F_6 [ V_13 ] ;
}
F_23 ( V_15 , V_17 ) ;
memset ( V_15 -> V_25 , 0 , sizeof( V_15 -> V_25 ) ) ;
F_24 ( V_15 -> V_26 ) ;
memset ( V_15 -> V_27 , 0 , sizeof( V_15 -> V_27 ) ) ;
return 0 ;
}
