int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 , V_7 , V_8 ;
F_2 ( V_2 , V_9 , 0x00000000 ) ;
F_2 ( V_2 , V_10 , 0xFFFFFFFF ) ;
V_8 = 1000000 / 32 ;
if ( V_4 -> V_11 < 0x40 ) {
V_7 = V_4 -> V_12 . V_13 . V_14 ( V_2 , V_15 ) ;
} else
if ( V_4 -> V_11 == 0x40 ) {
V_7 = 0 ;
} else {
V_7 = V_4 -> V_16 ;
V_6 = 1 ;
while ( V_7 < ( V_8 * 2 ) ) {
V_7 += ( V_7 / V_6 ) ;
V_6 ++ ;
}
F_2 ( V_2 , 0x009220 , V_6 - 1 ) ;
}
if ( ! V_7 ) {
F_3 ( V_2 , L_1 ) ;
if ( ! F_4 ( V_2 , V_17 ) ||
! F_4 ( V_2 , V_18 ) ) {
F_2 ( V_2 , V_17 , 1 ) ;
F_2 ( V_2 , V_18 , 1 ) ;
}
return 0 ;
}
while ( ( ( V_7 % 5 ) == 0 ) && ( ( V_8 % 5 ) == 0 ) ) {
V_7 /= 5 ;
V_8 /= 5 ;
}
while ( ( ( V_7 % 2 ) == 0 ) && ( ( V_8 % 2 ) == 0 ) ) {
V_7 /= 2 ;
V_8 /= 2 ;
}
while ( V_7 > 0xffff || V_8 > 0xffff ) {
V_7 >>= 1 ;
V_8 >>= 1 ;
}
F_2 ( V_2 , V_17 , V_7 ) ;
F_2 ( V_2 , V_18 , V_8 ) ;
return 0 ;
}
T_2
F_5 ( struct V_1 * V_2 )
{
T_1 V_19 , V_20 ;
do {
V_19 = F_4 ( V_2 , V_21 ) ;
V_20 = F_4 ( V_2 , V_22 ) ;
} while ( V_19 != F_4 ( V_2 , V_21 ) );
return ( ( T_2 ) V_19 << 32 | V_20 ) ;
}
void
F_6 ( struct V_1 * V_2 )
{
}
