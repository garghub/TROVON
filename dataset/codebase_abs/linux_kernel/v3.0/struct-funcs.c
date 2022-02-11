void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
unsigned long V_6 = F_2 ( V_5 ) ;
if ( V_2 -> V_7 && V_6 >= V_2 -> V_8 &&
V_6 + sizeof( * V_4 ) <= V_2 -> V_8 + V_2 -> V_9 ) {
memcpy ( V_4 , V_2 -> V_10 + V_6 - V_2 -> V_8 ,
sizeof( * V_4 ) ) ;
return;
} else if ( V_2 -> V_7 ) {
F_3 ( V_2 , V_2 -> V_7 , V_11 ) ;
V_2 -> V_7 = NULL ;
}
F_4 ( V_2 , (struct V_12 * ) V_6 ,
struct V_12 , V_13 , V_4 ) ;
}
