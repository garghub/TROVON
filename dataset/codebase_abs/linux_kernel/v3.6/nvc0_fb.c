static inline void
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
T_1 V_5 = 0x141000 + ( V_3 * 0x2000 ) + ( V_4 * 0x400 ) ;
T_1 V_6 = F_2 ( V_2 , V_5 + 0x020 ) ;
if ( V_6 ) {
F_3 ( V_2 , L_1 , V_3 , V_4 , V_6 ) ;
F_4 ( V_2 , V_5 + 0x020 , V_6 ) ;
}
}
static void
F_5 ( struct V_1 * V_2 )
{
T_1 V_7 = F_2 ( V_2 , 0x00017c ) ;
while ( V_7 ) {
T_1 V_4 , V_3 = F_6 ( V_7 ) - 1 ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ )
F_1 ( V_2 , V_3 , V_4 ) ;
V_7 &= ~ ( 1 << V_3 ) ;
}
F_7 ( V_2 , 0x000640 , 0x02000000 , 0x00000000 ) ;
}
static void
F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_9 -> V_13 . V_14 ;
struct V_15 * V_16 = V_12 -> V_16 ;
F_9 ( V_2 , 25 ) ;
if ( V_16 -> V_17 ) {
F_10 ( V_2 -> V_18 , V_16 -> V_19 , V_20 ,
V_21 ) ;
F_11 ( V_16 -> V_17 ) ;
}
F_12 ( V_16 ) ;
V_12 -> V_16 = NULL ;
}
static int
F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_9 -> V_13 . V_14 ;
struct V_15 * V_16 ;
V_16 = F_14 ( sizeof( * V_16 ) , V_22 ) ;
if ( ! V_16 )
return - V_23 ;
V_12 -> V_16 = V_16 ;
V_16 -> V_17 = F_15 ( V_22 | V_24 ) ;
if ( ! V_16 -> V_17 ) {
F_8 ( V_2 ) ;
return - V_23 ;
}
V_16 -> V_19 = F_16 ( V_2 -> V_18 , V_16 -> V_17 , 0 ,
V_20 , V_21 ) ;
if ( F_17 ( V_2 -> V_18 , V_16 -> V_19 ) ) {
F_8 ( V_2 ) ;
return - V_25 ;
}
F_18 ( V_2 , 25 , F_5 ) ;
return 0 ;
}
int
F_19 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_15 * V_16 ;
int V_26 ;
if ( ! V_9 -> V_13 . V_14 . V_16 ) {
V_26 = F_13 ( V_2 ) ;
if ( V_26 )
return V_26 ;
}
V_16 = V_9 -> V_13 . V_14 . V_16 ;
F_4 ( V_2 , 0x100c10 , V_16 -> V_19 >> 8 ) ;
F_7 ( V_2 , 0x17e820 , 0x00100000 , 0x00000000 ) ;
return 0 ;
}
void
F_20 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
}
