int
F_1 ( T_1 )
{
const T_2 V_1 = V_2 -> V_3 * 0x800 ;
union {
struct V_4 V_5 ;
} * args = V_6 ;
T_2 V_7 ;
int V_8 ;
F_2 ( V_9 , L_1 , V_10 ) ;
if ( F_3 ( args -> V_5 , 0 , 0 , false ) ) {
F_2 ( V_9 , L_2
L_3 ,
args -> V_5 . V_11 , args -> V_5 . V_12 , args -> V_5 . V_6 ,
args -> V_5 . V_13 , args -> V_5 . V_14 ) ;
V_7 = 0x00000040 * ! args -> V_5 . V_12 ;
V_7 |= 0x00000010 * ! args -> V_5 . V_6 ;
V_7 |= 0x00000004 * ! args -> V_5 . V_13 ;
V_7 |= 0x00000001 * ! args -> V_5 . V_14 ;
} else
return V_8 ;
F_4 ( V_15 , 0x61a004 + V_1 , 0x80000000 , 0x00000000 ) ;
F_5 ( V_15 , 0x61a004 + V_1 , 0xc000007f , 0x80000000 | V_7 ) ;
F_4 ( V_15 , 0x61a004 + V_1 , 0x80000000 , 0x00000000 ) ;
return 0 ;
}
int
F_6 ( T_1 )
{
union {
struct V_16 V_5 ;
} * args = V_6 ;
const T_2 V_1 = V_2 -> V_3 * 0x800 ;
T_2 V_17 ;
int V_8 ;
F_2 ( V_9 , L_4 , V_10 ) ;
if ( F_3 ( args -> V_5 , 0 , 0 , false ) ) {
F_2 ( V_9 , L_5 ,
args -> V_5 . V_11 , args -> V_5 . V_6 ) ;
if ( args -> V_5 . V_6 & 0xfff00000 )
return - V_18 ;
V_17 = args -> V_5 . V_6 ;
} else
return V_8 ;
F_5 ( V_15 , 0x61a004 + V_1 , 0x807f0000 , 0x80150000 ) ;
F_4 ( V_15 , 0x61a004 + V_1 , 0x80000000 , 0x00000000 ) ;
F_7 ( V_15 , 0x61a00c + V_1 , 0x00100000 | V_17 ) ;
F_8 ( 9 ) ;
F_9 ( 500 ) ;
V_17 = F_5 ( V_15 , 0x61a00c + V_1 , 0xffffffff , 0x00000000 ) ;
F_5 ( V_15 , 0x61a004 + V_1 , 0x807f0000 , 0x80550000 ) ;
F_4 ( V_15 , 0x61a004 + V_1 , 0x80000000 , 0x00000000 ) ;
F_10 ( V_15 , L_6 , V_2 -> V_3 , V_17 ) ;
if ( ! ( V_17 & 0x80000000 ) )
return - V_19 ;
args -> V_5 . V_20 = ( V_17 & 0x38000000 ) >> 27 ;
return 0 ;
}
