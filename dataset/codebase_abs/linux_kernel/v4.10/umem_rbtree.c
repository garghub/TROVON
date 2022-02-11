static inline T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
return F_3 ( V_4 -> V_6 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
return F_5 ( V_4 -> V_6 ) - 1 ;
}
int F_6 ( struct V_7 * V_8 ,
T_1 V_9 , T_1 V_10 ,
T_2 V_11 ,
void * V_12 )
{
int V_13 = 0 ;
struct V_1 * V_14 ;
struct V_3 * V_6 ;
if ( F_7 ( V_9 == V_10 ) )
return V_13 ;
for ( V_14 = F_8 ( V_8 , V_9 , V_10 - 1 ) ; V_14 ;
V_14 = F_9 ( V_14 , V_9 , V_10 - 1 ) ) {
V_6 = F_2 ( V_14 , struct V_3 , V_5 ) ;
V_13 = V_11 ( V_6 -> V_6 , V_9 , V_10 , V_12 ) || V_13 ;
}
return V_13 ;
}
