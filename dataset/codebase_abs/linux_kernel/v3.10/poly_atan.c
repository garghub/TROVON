void F_1 ( T_1 * V_1 , T_2 V_2 ,
T_1 * V_3 , T_2 V_4 )
{
T_2 V_5 , V_6 , V_7 , V_8 ;
int V_9 ;
long int V_10 ;
T_3 V_11 , V_12 , V_13 , V_14 , V_15 , V_16 , V_17 ;
T_2 V_18 ;
V_7 = F_2 ( V_1 ) ;
V_8 = F_2 ( V_3 ) ;
if ( V_2 == V_19 ) {
V_9 = V_9 ( V_1 ) ;
} else {
F_3 ( V_1 , V_1 ) ;
V_9 = F_4 ( V_1 ) ;
}
if ( V_4 == V_19 ) {
V_9 -= V_9 ( V_3 ) ;
} else {
F_3 ( V_3 , V_3 ) ;
V_9 -= F_4 ( V_3 ) ;
}
if ( ( V_9 < 0 ) || ( ( V_9 == 0 ) &&
( ( V_1 -> V_20 < V_3 -> V_20 ) ||
( ( V_1 -> V_20 == V_3 -> V_20 ) &&
( V_1 -> V_21 < V_3 -> V_21 ) ) ) ) ) {
V_6 = 1 ;
V_12 . V_22 = V_13 . V_22 = 0 ;
F_5 ( V_12 ) = F_6 ( V_1 ) ;
F_5 ( V_13 ) = F_6 ( V_3 ) ;
} else {
V_6 = 0 ;
V_9 = - V_9 ;
V_12 . V_22 = V_13 . V_22 = 0 ;
F_5 ( V_12 ) = F_6 ( V_3 ) ;
F_5 ( V_13 ) = F_6 ( V_1 ) ;
}
F_7 ( & V_12 , & V_13 , & V_15 ) ;
V_9 += F_8 ( & V_15 ) ;
if ( ( V_9 >= - 1 )
|| ( ( V_9 == - 2 ) && ( V_15 . V_23 > 0xd413ccd0 ) ) ) {
V_5 = 1 ;
if ( V_9 >= 0 ) {
#ifdef F_9
if ( ! ( ( V_9 == 0 ) &&
( V_15 . V_22 == 0 ) && ( V_15 . V_24 == 0 ) &&
( V_15 . V_23 == 0x80000000 ) ) ) {
F_10 ( V_25 | 0x104 ) ;
return;
}
#endif
V_15 . V_23 = 0 ;
} else {
V_12 . V_22 = V_13 . V_22 = V_15 . V_22 ;
F_5 ( V_12 ) = F_5 ( V_13 ) = F_5 ( V_15 ) ;
if ( V_9 < - 1 )
F_11 ( & V_12 , - 1 - V_9 ) ;
F_12 ( & V_12 ) ;
F_11 ( & V_13 , - V_9 ) ;
V_13 . V_23 |= 0x80000000 ;
F_7 ( & V_12 , & V_13 , & V_15 ) ;
V_9 = - 1 + F_8 ( & V_15 ) ;
}
} else {
V_5 = 0 ;
}
V_16 . V_22 = V_15 . V_22 ;
V_16 . V_24 = V_15 . V_24 ;
V_16 . V_23 = V_15 . V_23 ;
F_13 ( & V_16 , & V_16 ) ;
V_17 . V_22 = V_16 . V_22 ;
V_17 . V_24 = V_16 . V_24 ;
V_17 . V_23 = V_16 . V_23 ;
F_13 ( & V_17 , & V_17 ) ;
V_14 . V_22 = V_16 . V_22 ;
F_5 ( V_14 ) = F_5 ( V_16 ) ;
F_11 ( & V_16 , 2 * ( - 1 - V_9 - 1 ) ) ;
F_11 ( & V_17 , 4 * ( - 1 - V_9 - 1 ) ) ;
V_11 . V_23 = V_11 . V_24 = V_11 . V_22 = 0 ;
F_14 ( & V_11 , & F_5 ( V_17 ) ,
V_26 , V_27 - 1 ) ;
F_15 ( & V_11 , & F_5 ( V_16 ) ) ;
F_12 ( & V_11 ) ;
F_14 ( & V_11 , & F_5 ( V_17 ) , V_28 ,
V_29 - 1 ) ;
F_12 ( & V_11 ) ;
F_16 ( & V_11 , & V_30 , & V_10 ) ;
F_15 ( & V_14 , & V_31 ) ;
F_11 ( & V_14 , 1 + 2 * ( - 1 - V_9 ) ) ;
V_14 . V_23 |= 0x80000000 ;
F_7 ( & V_11 , & V_14 , & V_11 ) ;
F_13 ( & V_11 , & V_15 ) ;
F_13 ( & V_11 , & V_16 ) ;
F_11 ( & V_11 , 3 ) ;
F_12 ( & V_11 ) ;
F_17 ( & V_11 , & V_15 ) ;
if ( V_5 ) {
F_11 ( & V_11 , - 1 - V_9 ) ;
F_12 ( & V_11 ) ;
F_17 ( & V_11 , & V_32 ) ;
V_9 = - 1 ;
}
if ( V_6 ) {
F_11 ( & V_11 , - V_9 ) ;
F_12 ( & V_11 ) ;
F_17 ( & V_11 , & V_32 ) ;
V_9 = 0 ;
}
if ( V_7 ) {
F_11 ( & V_11 , 1 - V_9 ) ;
F_12 ( & V_11 ) ;
F_17 ( & V_11 , & V_32 ) ;
V_9 = 1 ;
}
V_9 += F_18 ( & V_11 ) ;
F_6 ( V_3 ) = F_5 ( V_11 ) ;
F_19 ( V_3 , V_9 ) ;
V_18 = F_20 ( V_3 , 1 , 0 , V_33 , V_8 ) ;
F_21 ( 1 , V_18 ) ;
F_22 () ;
}
