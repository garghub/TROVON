void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_6 =
F_2 ( ( int ) V_4 -> V_6 , 16 ,
V_7 ) ;
V_2 -> V_8 =
F_2 ( ( int ) V_4 -> V_8 , 16 ,
V_7 ) ;
}
void
F_3 (
struct V_9 * V_2 ,
const struct V_10 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_11 = V_4 -> V_11 ;
V_2 -> V_12 = V_4 -> V_12 ;
}
void
F_4 (
struct V_13 * V_2 ,
const struct V_14 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
memcpy ( & V_2 -> V_15 , & V_4 -> V_16 , sizeof( V_2 -> V_15 ) ) ;
}
void
F_5 (
const struct V_1 * V_15 ,
unsigned V_17 )
{
if ( ! V_15 ) return;
F_6 ( V_17 , L_1 ) ;
F_6 ( V_17 , L_2 ,
L_3 , V_15 -> V_6 ) ;
F_6 ( V_17 , L_2 ,
L_4 , V_15 -> V_8 ) ;
}
void
F_7 (
const struct V_9 * V_18 ,
unsigned V_17 )
{
F_6 ( V_17 , L_5 ) ;
F_6 ( V_17 , L_2 ,
L_6 , V_18 -> V_11 ) ;
F_6 ( V_17 , L_2 ,
L_7 , V_18 -> V_12 ) ;
}
void
F_8 (
const struct V_3 * V_19 ,
unsigned V_17 )
{
F_6 ( V_17 ,
L_8 ,
V_19 -> V_6 , V_19 -> V_8 ) ;
}
void
F_9 (
const struct V_10 * V_19 ,
unsigned V_17 )
{
F_6 ( V_17 ,
L_9 ,
V_19 -> V_11 , V_19 -> V_12 ) ;
}
