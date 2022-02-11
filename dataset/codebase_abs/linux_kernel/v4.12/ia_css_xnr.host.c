void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
memcpy ( & V_2 -> V_6 , & V_4 -> V_7 , sizeof( V_2 -> V_6 ) ) ;
}
void
F_2 (
struct V_8 * V_2 ,
const struct V_9 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_10 =
( V_11 ) F_3 ( V_4 -> V_10 , 16 , V_12 ) ;
}
void
F_4 (
const struct V_3 * V_13 ,
unsigned V_14 )
{
( void ) V_13 ;
( void ) V_14 ;
}
void
F_5 (
const struct V_9 * V_13 ,
unsigned V_14 )
{
F_6 ( V_14 ,
L_1 , V_13 -> V_10 ) ;
}
