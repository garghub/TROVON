int
F_1 ( T_1 )
{
const T_2 V_1 = ( V_2 * 0x800 ) ;
union {
struct V_3 V_4 ;
} * args = V_5 ;
T_2 V_6 ;
int V_7 ;
F_2 ( V_8 , L_1 , V_9 ) ;
if ( F_3 ( args -> V_4 , 0 , 0 , false ) ) {
F_2 ( V_8 , L_2
L_3 ,
args -> V_4 . V_10 , args -> V_4 . V_11 ,
args -> V_4 . V_12 , args -> V_4 . V_13 ) ;
if ( args -> V_4 . V_12 > 0x1f || args -> V_4 . V_13 > 0x7f )
return - V_14 ;
V_6 = 0x40000000 * ! ! args -> V_4 . V_11 ;
V_6 |= args -> V_4 . V_12 << 16 ;
V_6 |= args -> V_4 . V_13 ;
V_6 |= 0x1f000000 ;
} else
return V_7 ;
if ( ! ( V_6 & 0x40000000 ) ) {
F_4 ( V_15 , 0x6165a4 + V_1 , 0x40000000 , 0x00000000 ) ;
F_4 ( V_15 , 0x616520 + V_1 , 0x00000001 , 0x00000000 ) ;
F_4 ( V_15 , 0x616500 + V_1 , 0x00000001 , 0x00000000 ) ;
return 0 ;
}
F_4 ( V_15 , 0x616520 + V_1 , 0x00000001 , 0x00000000 ) ;
F_5 ( V_15 , 0x616528 + V_1 , 0x000d0282 ) ;
F_5 ( V_15 , 0x61652c + V_1 , 0x0000006f ) ;
F_5 ( V_15 , 0x616530 + V_1 , 0x00000000 ) ;
F_5 ( V_15 , 0x616534 + V_1 , 0x00000000 ) ;
F_5 ( V_15 , 0x616538 + V_1 , 0x00000000 ) ;
F_4 ( V_15 , 0x616520 + V_1 , 0x00000001 , 0x00000001 ) ;
F_4 ( V_15 , 0x616500 + V_1 , 0x00000001 , 0x00000000 ) ;
F_5 ( V_15 , 0x616508 + V_1 , 0x000a0184 ) ;
F_5 ( V_15 , 0x61650c + V_1 , 0x00000071 ) ;
F_5 ( V_15 , 0x616510 + V_1 , 0x00000000 ) ;
F_4 ( V_15 , 0x616500 + V_1 , 0x00000001 , 0x00000001 ) ;
F_4 ( V_15 , 0x6165d0 + V_1 , 0x00070001 , 0x00010001 ) ;
F_4 ( V_15 , 0x616568 + V_1 , 0x00010101 , 0x00000000 ) ;
F_4 ( V_15 , 0x616578 + V_1 , 0x80000000 , 0x80000000 ) ;
F_4 ( V_15 , 0x61733c , 0x00100000 , 0x00100000 ) ;
F_4 ( V_15 , 0x61733c , 0x10000000 , 0x10000000 ) ;
F_4 ( V_15 , 0x61733c , 0x00100000 , 0x00000000 ) ;
F_4 ( V_15 , 0x6165a4 + V_1 , 0x5f1f007f , V_6 ) ;
return 0 ;
}
