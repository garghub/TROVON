static int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
void * V_5 , T_1 V_6 , struct V_7 * * V_8 )
{
struct V_7 * V_9 = V_4 -> V_9 ;
union {
struct V_10 V_11 ;
} * args = V_5 ;
struct V_12 * V_13 = V_12 ( V_2 ) ;
struct V_14 * V_15 ;
int V_16 = - V_17 ;
F_2 ( V_9 , L_1 , V_6 ) ;
if ( ! ( V_16 = F_3 ( V_16 , & V_5 , & V_6 , args -> V_11 , 0 , 0 , false ) ) ) {
F_2 ( V_9 , L_2
L_3 ,
args -> V_11 . V_18 , args -> V_11 . V_19 , args -> V_11 . V_20 ,
args -> V_11 . V_21 ) ;
if ( ! args -> V_11 . V_20 )
return - V_22 ;
} else
return V_16 ;
if ( ! ( V_15 = F_4 ( sizeof( * V_15 ) , V_23 ) ) )
return - V_24 ;
* V_8 = & V_15 -> V_2 . V_25 ;
V_16 = F_5 ( V_13 , args -> V_11 . V_19 , args -> V_11 . V_20 ,
V_4 , V_15 ) ;
if ( V_16 )
return V_16 ;
args -> V_11 . V_26 = V_15 -> V_2 . V_26 ;
F_6 ( V_15 -> V_27 ) ;
F_7 ( V_15 -> V_27 , 0x08 , F_8 ( args -> V_11 . V_21 ) ) ;
F_7 ( V_15 -> V_27 , 0x0c , F_9 ( args -> V_11 . V_21 ) ) ;
F_7 ( V_15 -> V_27 , 0x10 , F_8 ( args -> V_11 . V_21 ) ) ;
F_7 ( V_15 -> V_27 , 0x14 , F_9 ( args -> V_11 . V_21 ) ) ;
F_7 ( V_15 -> V_27 , 0x3c , 0x003f6078 ) ;
F_7 ( V_15 -> V_27 , 0x44 , 0x01003fff ) ;
F_7 ( V_15 -> V_27 , 0x48 , V_15 -> V_2 . V_28 -> V_29 -> V_21 >> 4 ) ;
F_7 ( V_15 -> V_27 , 0x4c , 0xffffffff ) ;
F_7 ( V_15 -> V_27 , 0x60 , 0x7fffffff ) ;
F_7 ( V_15 -> V_27 , 0x78 , 0x00000000 ) ;
F_7 ( V_15 -> V_27 , 0x7c , 0x30000001 ) ;
F_7 ( V_15 -> V_27 , 0x80 , ( ( V_15 -> V_30 -> V_31 - 9 ) << 27 ) |
( 4 << 24 ) |
( V_15 -> V_30 -> V_32 -> V_29 -> V_21 >> 4 ) ) ;
F_7 ( V_15 -> V_27 , 0x88 , V_15 -> V_33 -> V_34 >> 10 ) ;
F_7 ( V_15 -> V_27 , 0x98 , V_15 -> V_2 . V_35 -> V_34 >> 12 ) ;
F_10 ( V_15 -> V_27 ) ;
return 0 ;
}
