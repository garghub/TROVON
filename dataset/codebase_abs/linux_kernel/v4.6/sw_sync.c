struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * )
F_2 ( & V_3 -> V_3 , sizeof( struct V_5 ) ) ;
V_6 -> V_4 = V_4 ;
return (struct V_1 * ) V_6 ;
}
static int F_3 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_1 ;
struct V_2 * V_3 =
(struct V_2 * ) F_4 ( V_1 ) ;
return ( V_6 -> V_4 > V_3 -> V_4 ) ? 0 : 1 ;
}
static void F_5 ( struct V_7 * V_7 ,
char * V_8 , int V_9 )
{
struct V_2 * V_10 =
(struct V_2 * ) V_7 ;
snprintf ( V_8 , V_9 , L_1 , V_10 -> V_4 ) ;
}
static void F_6 ( struct V_1 * V_1 , char * V_8 , int V_9 )
{
struct V_5 * V_6 = (struct V_5 * ) V_1 ;
snprintf ( V_8 , V_9 , L_1 , V_6 -> V_4 ) ;
}
struct V_2 * F_7 ( const char * V_11 )
{
struct V_2 * V_3 = (struct V_2 * )
F_8 ( & V_12 ,
sizeof( struct V_2 ) ,
V_11 ) ;
return V_3 ;
}
void F_9 ( struct V_2 * V_3 , T_1 V_13 )
{
V_3 -> V_4 += V_13 ;
F_10 ( & V_3 -> V_3 ) ;
}
