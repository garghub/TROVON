T_1
F_1 ( T_2 * V_1 ,
T_3 V_2 ,
T_3 V_3 , T_2 V_4 , void * * V_5 )
{
struct V_6 * * V_7 =
F_2 ( struct V_6 , V_5 ) ;
struct V_6 * V_8 ;
union V_9 * V_9 ;
struct V_10 * V_11 ;
T_1 V_12 ;
F_3 ( V_13 ) ;
V_8 = * V_7 ;
if ( F_4 ( V_8 ) ) {
F_5 ( ( V_14 ,
L_1 , V_8 ) ) ;
}
V_9 = F_6 ( union V_9 , V_1 ) ;
if ( F_7 ( V_1 ) == V_15 ) {
if ( V_9 -> V_16 . type >
V_17 ) {
V_11 = NULL ;
} else {
V_11 =
V_18
[ V_9 -> V_16 . type ] ;
}
} else {
V_11 =
V_19 [ V_4 ] ;
}
if ( ! V_11 ) {
F_8 ( ( V_14 ,
L_2 ,
V_4 ) ) ;
return ( V_20 ) ;
}
V_12 =
F_9 ( V_8 , V_9 ,
V_11 ) ;
if ( F_10 ( V_12 ) ) {
F_11 ( ( V_14 , V_12 ,
L_3 ,
* V_1 ) ) ;
F_12 ( V_12 ) ;
}
F_13 ( ( V_21 ,
L_4 ,
F_7 ( V_1 ) , V_2 ,
V_8 -> V_2 ) ) ;
* V_7 = F_14 ( V_8 ) ;
F_12 ( V_22 ) ;
}
T_1
F_15 ( struct V_6 * V_8 ,
T_4 V_23 , T_2 * V_24 )
{
T_2 * V_1 = V_24 ;
T_2 * V_25 = V_24 + V_23 ;
struct V_10 * V_11 ;
T_1 V_12 ;
F_3 ( V_26 ) ;
while ( V_1 < V_25 ) {
if ( V_8 -> type > V_27 ) {
F_8 ( ( V_14 ,
L_5 ,
V_8 -> type ) ) ;
F_12 ( V_28 ) ;
}
if ( V_8 -> type == V_29 ) {
if ( V_8 -> V_30 . V_16 . type >
V_17 ) {
V_11 = NULL ;
} else {
V_11 =
V_18
[ V_8 -> V_30 . V_16 . type ] ;
}
} else {
V_11 =
V_31 [ V_8 -> type ] ;
}
if ( ! V_11 ) {
F_8 ( ( V_14 ,
L_2 ,
V_8 -> type ) ) ;
return ( V_20 ) ;
}
V_12 = F_16 ( V_8 ,
F_6 ( union
V_9 ,
V_1 ) ,
V_11 ) ;
if ( F_10 ( V_12 ) ) {
F_11 ( ( V_14 , V_12 ,
L_6 ,
V_8 -> type ) ) ;
F_12 ( V_12 ) ;
}
V_12 =
F_17 ( F_6
( union V_9 , V_1 ) , NULL ) ;
if ( F_10 ( V_12 ) ) {
F_12 ( V_12 ) ;
}
if ( V_8 -> type == V_32 ) {
F_12 ( V_22 ) ;
}
V_1 += F_18 ( V_1 ) ;
V_8 = F_14 ( V_8 ) ;
}
F_12 ( V_33 ) ;
}
