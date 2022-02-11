static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_1 * V_5 )
{
struct V_1 * * V_6 = & V_3 -> V_1 ;
struct V_1 * V_7 = NULL ;
struct V_8 * V_9 ;
while ( * V_6 ) {
V_7 = * V_6 ;
V_9 = F_2 ( V_7 , struct V_8 , V_1 ) ;
if ( V_4 < V_9 -> V_4 )
V_6 = & ( * V_6 ) -> V_10 ;
else if ( V_4 > V_9 -> V_4 )
V_6 = & ( * V_6 ) -> V_11 ;
else
return V_7 ;
}
V_9 = F_2 ( V_5 , struct V_8 , V_1 ) ;
F_3 ( V_5 , V_7 , V_6 ) ;
F_4 ( V_5 , V_3 ) ;
return NULL ;
}
static struct V_1 * F_5 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_12 = V_3 -> V_1 ;
struct V_8 * V_9 ;
while ( V_12 ) {
V_9 = F_2 ( V_12 , struct V_8 , V_1 ) ;
F_6 ( ! V_9 -> V_13 ) ;
if ( V_4 < V_9 -> V_4 )
V_12 = V_12 -> V_10 ;
else if ( V_4 > V_9 -> V_4 )
V_12 = V_12 -> V_11 ;
else
return V_12 ;
}
return NULL ;
}
