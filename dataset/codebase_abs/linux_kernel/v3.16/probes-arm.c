void T_1 F_1 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
long V_6 = ( long ) V_5 -> V_7 - 4 ;
int V_8 = F_2 ( V_1 ) ;
if ( V_1 & ( 1 << 24 ) )
V_5 -> V_9 = V_6 + 4 ;
V_5 -> V_7 = V_6 + 8 + V_8 ;
}
void T_1 F_3 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
long V_6 = ( long ) V_5 -> V_7 - 4 ;
int V_8 = F_2 ( V_1 ) ;
V_5 -> V_9 = V_6 + 4 ;
V_5 -> V_7 = V_6 + 8 + V_8 + ( ( V_1 >> 23 ) & 0x2 ) ;
V_5 -> V_10 |= V_11 ;
}
void T_1 F_4 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_12 = V_1 & 0xf ;
long V_13 = V_5 -> V_14 [ V_12 ] ;
if ( V_1 & ( 1 << 5 ) )
V_5 -> V_9 = ( long ) V_5 -> V_7 ;
V_5 -> V_7 = V_13 & ~ 0x1 ;
V_5 -> V_10 &= ~ V_11 ;
if ( V_13 & 0x1 )
V_5 -> V_10 |= V_11 ;
}
void T_1 F_5 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_15 = ( V_1 >> 12 ) & 0xf ;
unsigned long V_16 = 0xf8ff03df ;
V_5 -> V_14 [ V_15 ] = V_5 -> V_10 & V_16 ;
}
void T_1 F_6 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
V_5 -> V_14 [ 12 ] = V_5 -> V_14 [ 13 ] ;
}
static void T_1 F_7 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
V_5 -> V_7 += 4 ;
V_3 -> V_17 ( V_1 , V_3 , V_5 ) ;
}
enum V_18 T_1
F_8 ( T_2 V_1 , struct V_2 * V_3 ,
bool V_19 , const union V_20 * V_21 )
{
V_3 -> V_22 = F_7 ;
V_3 -> V_23 = V_24 [ V_1 >> 28 ] ;
return F_9 ( V_1 , V_3 , V_25 , false ,
V_19 , V_21 ) ;
}
