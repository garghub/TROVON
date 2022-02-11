static void
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
T_1 V_5 = 0x140000 + ( V_3 * 0x2000 ) + ( V_4 * 0x400 ) ;
T_1 V_6 = F_2 ( V_2 , V_5 + 0x00c ) ;
if ( V_6 ) {
F_3 ( V_2 , L_1 , V_3 , V_4 , V_6 ) ;
F_4 ( V_2 , V_5 + 0x00c , V_6 ) ;
}
}
static void
F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = ( void * ) V_8 ;
T_1 V_9 ;
V_9 = F_2 ( V_2 , 0x00017c ) ;
while ( V_9 ) {
T_1 V_4 , V_3 = F_6 ( V_9 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_10 ; V_4 ++ )
F_1 ( V_2 , V_3 , V_4 ) ;
V_9 &= ~ ( 1 << V_3 ) ;
}
F_7 ( V_2 , 0x000640 , 0x02000000 , 0x00000000 ) ;
}
static void
F_8 ( struct V_11 * V_12 , T_1 V_13 , T_1 V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
T_1 V_15 = V_13 + V_14 - 1 ;
int V_16 , V_17 ;
F_9 ( ( V_13 > V_15 ) || ( V_15 >= V_2 -> V_18 ) ) ;
F_4 ( V_2 , 0x17e270 , V_13 ) ;
F_4 ( V_2 , 0x17e274 , V_15 ) ;
F_4 ( V_2 , 0x17e26c , 0x4 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_19 ; ++ V_16 ) {
for ( V_17 = 0 ; V_17 < V_2 -> V_10 ; ++ V_17 )
F_10 ( V_2 , 0x14046c + V_16 * 0x2000 + V_17 * 0x200 , ~ 0 , 0 ) ;
}
}
static int
F_11 ( struct V_20 * V_21 , struct V_20 * V_22 ,
struct V_23 * V_24 , void * V_25 , T_1 V_26 ,
struct V_20 * * V_27 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = V_28 ( V_21 ) ;
T_1 V_30 , V_9 ;
int V_31 , V_17 ;
V_31 = F_12 ( V_21 , V_22 , V_24 , & V_2 ) ;
* V_27 = F_13 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_30 = F_2 ( V_2 , 0x022438 ) ;
V_9 = F_2 ( V_2 , 0x021c14 ) ;
for ( V_17 = 0 ; V_17 < V_30 ; V_17 ++ ) {
if ( ! ( V_9 & ( 1 << V_17 ) ) )
V_2 -> V_19 ++ ;
}
V_2 -> V_10 = F_2 ( V_2 , 0x17e280 ) >> 28 ;
V_31 = F_14 ( V_29 , V_2 ) ;
if ( V_31 )
return V_31 ;
V_2 -> V_5 . V_32 = V_33 ;
V_2 -> V_5 . V_34 = V_35 ;
V_2 -> V_5 . V_36 = F_8 ;
F_15 ( V_2 ) -> V_37 = F_5 ;
return 0 ;
}
static int
F_16 ( struct V_20 * V_38 )
{
struct V_11 * V_12 = (struct V_11 * ) V_38 ;
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
int V_31 ;
V_31 = F_17 ( V_12 ) ;
if ( V_31 )
return V_31 ;
F_4 ( V_2 , 0x17e27c , V_2 -> V_19 ) ;
F_4 ( V_2 , 0x17e278 , V_2 -> V_39 ) ;
return 0 ;
}
