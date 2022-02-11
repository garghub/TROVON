static int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
void * V_5 , T_1 V_6 , struct V_7 * * V_8 )
{
struct V_7 * V_9 = V_4 -> V_9 ;
union {
struct V_10 V_11 ;
} * args = V_5 ;
struct V_12 * V_13 = V_12 ( V_2 ) ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_17 = V_13 -> V_2 . V_18 . V_19 . V_17 ;
struct V_20 * V_21 = V_17 -> V_21 ;
int V_22 = - V_23 ;
F_2 ( V_9 , L_1 , V_6 ) ;
if ( ! ( V_22 = F_3 ( V_22 , & V_5 , & V_6 , args -> V_11 , 0 , 0 , false ) ) ) {
F_2 ( V_9 , L_2
L_3 , args -> V_11 . V_24 ,
args -> V_11 . V_25 , args -> V_11 . V_26 ) ;
if ( ! args -> V_11 . V_25 )
return - V_27 ;
} else
return V_22 ;
if ( ! ( V_15 = F_4 ( sizeof( * V_15 ) , V_28 ) ) )
return - V_29 ;
* V_8 = & V_15 -> V_2 . V_30 ;
V_22 = F_5 ( & V_31 , & V_13 -> V_2 ,
0x1000 , 0x1000 , false , 0 , args -> V_11 . V_25 ,
( 1ULL << V_32 ) |
( 1ULL << V_33 ) |
( 1ULL << V_34 ) |
( 1ULL << V_35 ) ,
0 , 0x800000 , 0x10000 , V_4 , & V_15 -> V_2 ) ;
V_15 -> V_13 = V_13 ;
if ( V_22 )
return V_22 ;
args -> V_11 . V_36 = V_15 -> V_2 . V_36 ;
V_15 -> V_37 = V_15 -> V_2 . V_36 * 64 ;
F_6 ( V_21 -> V_37 ) ;
F_7 ( V_21 -> V_37 , V_15 -> V_37 + 0x00 , args -> V_11 . V_26 ) ;
F_7 ( V_21 -> V_37 , V_15 -> V_37 + 0x04 , args -> V_11 . V_26 ) ;
F_7 ( V_21 -> V_37 , V_15 -> V_37 + 0x0c , V_15 -> V_2 . V_38 -> V_39 >> 4 ) ;
F_7 ( V_21 -> V_37 , V_15 -> V_37 + 0x14 ,
V_40 |
V_41 |
#ifdef F_8
V_42 |
#endif
V_43 ) ;
F_9 ( V_21 -> V_37 ) ;
return 0 ;
}
