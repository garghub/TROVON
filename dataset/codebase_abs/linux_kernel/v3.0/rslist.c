T_1
F_1 ( T_2 * V_1 ,
T_3 V_2 ,
T_3 V_3 , T_2 V_4 , void * * V_5 )
{
struct V_6 * * V_7 =
F_2 ( struct V_6 , V_5 ) ;
struct V_6 * V_8 ;
T_1 V_9 ;
F_3 ( V_10 ) ;
V_8 = * V_7 ;
if ( F_4 ( V_8 ) ) {
F_5 ( ( V_11 ,
L_1 , V_8 ) ) ;
}
V_9 =
F_6 ( V_8 ,
F_7 ( union V_12 ,
V_1 ) ,
V_13
[ V_4 ] ) ;
if ( F_8 ( V_9 ) ) {
F_9 ( ( V_11 , V_9 ,
L_2 ,
* V_1 ) ) ;
F_10 ( V_9 ) ;
}
F_11 ( ( V_14 ,
L_3 ,
F_12 ( V_1 ) , V_2 ,
V_8 -> V_2 ) ) ;
* V_7 = F_13 ( void , V_8 , V_8 -> V_2 ) ;
F_10 ( V_15 ) ;
}
T_1
F_14 ( struct V_6 * V_8 ,
T_4 V_16 , T_2 * V_17 )
{
T_2 * V_1 = V_17 ;
T_2 * V_18 = V_17 + V_16 ;
T_1 V_9 ;
F_3 ( V_19 ) ;
while ( V_1 < V_18 ) {
if ( V_8 -> type > V_20 ) {
F_15 ( ( V_11 ,
L_4 ,
V_8 -> type ) ) ;
F_10 ( V_21 ) ;
}
V_9 = F_16 ( V_8 , F_7 ( union
V_12 ,
V_1 ) ,
V_22
[ V_8 -> type ] ) ;
if ( F_8 ( V_9 ) ) {
F_9 ( ( V_11 , V_9 ,
L_5 ,
V_8 -> type ) ) ;
F_10 ( V_9 ) ;
}
V_9 =
F_17 ( F_7
( union V_12 , V_1 ) , NULL ) ;
if ( F_8 ( V_9 ) ) {
F_10 ( V_9 ) ;
}
if ( V_8 -> type == V_23 ) {
F_10 ( V_15 ) ;
}
V_1 += F_18 ( V_1 ) ;
V_8 =
F_13 ( struct V_6 , V_8 ,
V_8 -> V_2 ) ;
}
F_10 ( V_24 ) ;
}
