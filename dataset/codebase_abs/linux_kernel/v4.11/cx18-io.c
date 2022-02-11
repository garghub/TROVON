void F_1 ( struct V_1 * V_2 , void T_1 * V_3 , int V_4 , T_2 V_5 )
{
T_3 T_1 * V_6 = V_3 ;
T_4 V_7 = V_4 | ( V_4 << 8 ) ;
T_5 V_8 = V_7 | ( V_7 << 16 ) ;
if ( ( V_5 > 0 ) && ( ( unsigned long ) V_6 & 1 ) ) {
F_2 ( V_2 , ( T_3 ) V_4 , V_6 ) ;
V_5 -- ;
V_6 ++ ;
}
if ( ( V_5 > 1 ) && ( ( unsigned long ) V_6 & 2 ) ) {
F_3 ( V_2 , V_7 , V_6 ) ;
V_5 -= 2 ;
V_6 += 2 ;
}
while ( V_5 > 3 ) {
F_4 ( V_2 , V_8 , V_6 ) ;
V_5 -= 4 ;
V_6 += 4 ;
}
if ( V_5 > 1 ) {
F_3 ( V_2 , V_7 , V_6 ) ;
V_5 -= 2 ;
V_6 += 2 ;
}
if ( V_5 > 0 )
F_2 ( V_2 , ( T_3 ) V_4 , V_6 ) ;
}
void F_5 ( struct V_1 * V_2 , T_5 V_4 )
{
F_6 ( V_2 , V_4 , V_9 , ~ V_4 , V_4 ) ;
V_2 -> V_10 = F_7 ( V_2 , V_11 ) | V_4 ;
F_8 ( V_2 , V_2 -> V_10 , V_11 ) ;
}
void F_9 ( struct V_1 * V_2 , T_5 V_4 )
{
V_2 -> V_10 = F_7 ( V_2 , V_11 ) & ~ V_4 ;
F_8 ( V_2 , V_2 -> V_10 , V_11 ) ;
}
void F_10 ( struct V_1 * V_2 , T_5 V_4 )
{
F_6 ( V_2 , V_4 , V_12 , ~ V_4 , V_4 ) ;
V_2 -> V_13 = F_7 ( V_2 , V_14 ) | V_4 ;
F_8 ( V_2 , V_2 -> V_13 , V_14 ) ;
}
void F_11 ( struct V_1 * V_2 , T_5 V_4 )
{
V_2 -> V_13 = F_7 ( V_2 , V_14 ) & ~ V_4 ;
F_8 ( V_2 , V_2 -> V_13 , V_14 ) ;
}
void F_12 ( struct V_1 * V_2 , T_5 V_4 )
{
T_5 V_15 ;
V_15 = F_7 ( V_2 , V_16 ) ;
F_8 ( V_2 , V_15 & ~ V_4 , V_16 ) ;
}
void F_13 ( struct V_1 * V_2 , T_5 V_3 )
{
T_5 V_4 ;
V_4 = F_7 ( V_2 , 0xD000F8 ) ;
V_4 = ( V_4 & ~ 0x1f00 ) | ( ( V_3 >> 17 ) & 0x1f00 ) ;
F_8 ( V_2 , V_4 , 0xD000F8 ) ;
}
