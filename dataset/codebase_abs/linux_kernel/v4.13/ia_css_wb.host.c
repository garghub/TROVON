void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_6 =
V_7 - V_4 -> V_8 ;
V_2 -> V_9 =
F_2 ( V_4 -> V_10 , 16 - V_4 -> V_8 ,
V_2 -> V_6 ) ;
V_2 -> V_11 =
F_2 ( V_4 -> V_12 , 16 - V_4 -> V_8 ,
V_2 -> V_6 ) ;
V_2 -> V_13 =
F_2 ( V_4 -> V_14 , 16 - V_4 -> V_8 ,
V_2 -> V_6 ) ;
V_2 -> V_15 =
F_2 ( V_4 -> V_16 , 16 - V_4 -> V_8 ,
V_2 -> V_6 ) ;
}
void
F_3 (
const struct V_1 * V_17 ,
unsigned V_18 )
{
if ( ! V_17 ) return;
F_4 ( V_18 , L_1 ) ;
F_4 ( V_18 , L_2 ,
L_3 , V_17 -> V_6 ) ;
F_4 ( V_18 , L_2 ,
L_4 , V_17 -> V_9 ) ;
F_4 ( V_18 , L_2 ,
L_5 , V_17 -> V_11 ) ;
F_4 ( V_18 , L_2 ,
L_6 , V_17 -> V_13 ) ;
F_4 ( V_18 , L_2 ,
L_7 , V_17 -> V_15 ) ;
}
void
F_5 (
const struct V_3 * V_19 ,
unsigned V_18 )
{
F_4 ( V_18 ,
L_8
L_9
L_10 ,
V_19 -> V_8 ,
V_19 -> V_10 , V_19 -> V_12 ,
V_19 -> V_14 , V_19 -> V_16 ) ;
}
