void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_6 =
F_2 ( V_4 -> V_7 , 16 , V_8 ) ;
V_2 -> V_9 = F_3 ( 8 ) ;
V_2 -> V_10 =
1 << V_2 -> V_9 ;
V_2 -> V_11 =
F_2 ( V_4 -> V_12 , 16 , V_13 ) ;
V_2 -> V_14 =
F_2 ( V_4 -> V_12 , 16 , V_13 ) ;
V_2 -> V_15 = F_2 ( ( unsigned ) 16384 , 16 , V_8 ) ;
}
void
F_4 (
const struct V_1 * V_16 ,
unsigned V_17 )
{
if ( ! V_16 ) return;
F_5 ( V_17 , L_1 ) ;
F_5 ( V_17 , L_2 ,
L_3 , V_16 -> V_11 ) ;
F_5 ( V_17 , L_2 ,
L_4 , V_16 -> V_14 ) ;
F_5 ( V_17 , L_2 ,
L_5 ,
V_16 -> V_6 ) ;
F_5 ( V_17 , L_2 ,
L_6 ,
V_16 -> V_9 ) ;
F_5 ( V_17 , L_2 ,
L_7 ,
V_16 -> V_10 ) ;
F_5 ( V_17 , L_2 ,
L_8 , V_16 -> V_15 ) ;
}
