void
F_1 ( struct V_1 * V_2 , int V_3 , bool V_4 , T_1 V_5 ,
T_1 V_6 , T_1 * V_7 , T_1 V_8 , T_1 * V_9 , T_1 V_10 )
{
struct V_11 * V_12 = V_2 -> V_13 -> V_14 . V_15 . V_12 ;
const T_2 V_16 = 0x40000000 * V_4 |
0x1f000000 |
V_5 << 16 |
V_6 ;
const T_2 V_17 = V_3 * 0x800 ;
struct V_18 V_19 ;
struct V_18 V_20 ;
F_2 ( & V_19 , V_7 , V_8 ) ;
F_2 ( & V_20 , V_9 , V_10 ) ;
if ( ! ( V_16 & 0x40000000 ) ) {
F_3 ( V_12 , 0x6165a4 + V_17 , 0x40000000 , 0x00000000 ) ;
F_3 ( V_12 , 0x61653c + V_17 , 0x00000001 , 0x00000000 ) ;
F_3 ( V_12 , 0x616520 + V_17 , 0x00000001 , 0x00000000 ) ;
F_3 ( V_12 , 0x616500 + V_17 , 0x00000001 , 0x00000000 ) ;
return;
}
F_3 ( V_12 , 0x616520 + V_17 , 0x00000001 , 0x00000000 ) ;
if ( V_8 ) {
F_4 ( V_12 , 0x616528 + V_17 , V_19 . V_21 ) ;
F_4 ( V_12 , 0x61652c + V_17 , V_19 . V_22 ) ;
F_4 ( V_12 , 0x616530 + V_17 , V_19 . V_23 ) ;
F_4 ( V_12 , 0x616534 + V_17 , V_19 . V_24 ) ;
F_4 ( V_12 , 0x616538 + V_17 , V_19 . V_25 ) ;
F_3 ( V_12 , 0x616520 + V_17 , 0x00000001 , 0x00000001 ) ;
}
F_3 ( V_12 , 0x616500 + V_17 , 0x00000001 , 0x00000000 ) ;
F_4 ( V_12 , 0x616508 + V_17 , 0x000a0184 ) ;
F_4 ( V_12 , 0x61650c + V_17 , 0x00000071 ) ;
F_4 ( V_12 , 0x616510 + V_17 , 0x00000000 ) ;
F_3 ( V_12 , 0x616500 + V_17 , 0x00000001 , 0x00000001 ) ;
F_3 ( V_12 , 0x61653c + V_17 , 0x00010001 , 0x00010000 ) ;
if ( V_10 ) {
F_4 ( V_12 , 0x616544 + V_17 , V_20 . V_21 ) ;
F_4 ( V_12 , 0x616548 + V_17 , V_20 . V_22 ) ;
F_4 ( V_12 , 0x61654c + V_17 , V_20 . V_23 ) ;
F_3 ( V_12 , 0x61653c + V_17 , 0x00010001 , 0x00010001 ) ;
}
F_3 ( V_12 , 0x6165d0 + V_17 , 0x00070001 , 0x00010001 ) ;
F_3 ( V_12 , 0x616568 + V_17 , 0x00010101 , 0x00000000 ) ;
F_3 ( V_12 , 0x616578 + V_17 , 0x80000000 , 0x80000000 ) ;
F_3 ( V_12 , 0x61733c , 0x00100000 , 0x00100000 ) ;
F_3 ( V_12 , 0x61733c , 0x10000000 , 0x10000000 ) ;
F_3 ( V_12 , 0x61733c , 0x00100000 , 0x00000000 ) ;
F_3 ( V_12 , 0x6165a4 + V_17 , 0x5f1f007f , V_16 ) ;
}
