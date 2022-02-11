void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_6 = V_4 -> V_6 ;
}
void
F_2 (
const struct V_1 * V_7 ,
unsigned V_8 )
{
if ( ! V_7 ) return;
F_3 ( V_8 , L_1 ) ;
F_3 ( V_8 , L_2 ,
L_3 , V_7 -> V_6 ) ;
}
void
F_4 (
const struct V_3 * V_9 ,
unsigned V_8 )
{
F_3 ( V_8 ,
L_4 ,
V_9 -> V_6 ) ;
}
