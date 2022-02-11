T_1
F_1 ( union V_1 * V_2 ,
union V_1 * V_3 )
{
T_2 V_4 ;
T_3 * V_5 ;
F_2 ( V_6 , V_2 ) ;
if ( V_2 == V_3 ) {
F_3 ( V_7 ) ;
}
V_5 = F_4 ( T_3 , V_2 -> V_5 . V_8 ) ;
V_4 = V_2 -> V_5 . V_4 ;
if ( ( V_3 -> V_5 . V_4 == 0 ) ||
( V_3 -> V_9 . V_10 & V_11 ) ) {
V_3 -> V_5 . V_8 = F_5 ( V_4 ) ;
if ( ! V_3 -> V_5 . V_8 ) {
F_3 ( V_12 ) ;
}
V_3 -> V_5 . V_4 = V_4 ;
}
if ( V_4 <= V_3 -> V_5 . V_4 ) {
memset ( V_3 -> V_5 . V_8 , 0 ,
V_3 -> V_5 . V_4 ) ;
memcpy ( V_3 -> V_5 . V_8 , V_5 , V_4 ) ;
#ifdef F_6
if ( V_13 == V_14 ) {
V_3 -> V_5 . V_4 = V_4 ;
}
#endif
} else {
memcpy ( V_3 -> V_5 . V_8 , V_5 ,
V_3 -> V_5 . V_4 ) ;
F_7 ( ( V_15 ,
L_1 ,
V_4 , V_3 -> V_5 . V_4 ) ) ;
}
V_3 -> V_5 . V_10 = V_2 -> V_5 . V_10 ;
V_3 -> V_9 . V_10 &= ~ V_11 ;
F_3 ( V_7 ) ;
}
T_1
F_8 ( union V_1 * V_2 ,
union V_1 * V_3 )
{
T_2 V_4 ;
T_3 * V_5 ;
F_2 ( V_16 , V_2 ) ;
if ( V_2 == V_3 ) {
F_3 ( V_7 ) ;
}
V_5 = F_4 ( T_3 , V_2 -> string . V_8 ) ;
V_4 = V_2 -> string . V_4 ;
if ( ( V_4 < V_3 -> string . V_4 ) &&
( ! ( V_3 -> V_9 . V_10 & V_11 ) ) ) {
memset ( V_3 -> string . V_8 , 0 ,
( V_17 ) V_3 -> string . V_4 + 1 ) ;
memcpy ( V_3 -> string . V_8 , V_5 , V_4 ) ;
} else {
if ( V_3 -> string . V_8 &&
( ! ( V_3 -> V_9 . V_10 & V_11 ) ) ) {
F_9 ( V_3 -> string . V_8 ) ;
}
V_3 -> string . V_8 = F_10 ( ( V_17 )
V_4 + 1 ) ;
if ( ! V_3 -> string . V_8 ) {
F_3 ( V_12 ) ;
}
V_3 -> V_9 . V_10 &= ~ V_11 ;
memcpy ( V_3 -> string . V_8 , V_5 , V_4 ) ;
}
V_3 -> string . V_4 = V_4 ;
F_3 ( V_7 ) ;
}
