static inline int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
V_2 -> V_3 = F_2 ( sizeof( * V_2 -> V_3 ) , V_4 ) ;
if ( ! V_2 -> V_3 )
return - V_5 ;
F_3 ( V_2 , F_4 ( 32 ) ) ;
return 0 ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
int F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
return F_8 ( V_9 , V_11 ,
V_12 ) ;
}
void F_9 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
F_10 ( V_9 ) ;
}
int F_11 ( struct V_6 * V_7 ,
struct V_1 * V_13 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
int V_14 ;
if ( F_12 ( V_9 -> V_15 ) != F_12 ( V_13 ) ) {
F_13 ( L_1 ,
F_14 ( V_13 ) ) ;
return - V_16 ;
}
V_14 = F_1 ( V_13 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_15 ( V_9 , V_13 ) ;
if ( V_14 )
F_5 ( V_13 ) ;
return 0 ;
}
void F_16 ( struct V_6 * V_7 ,
struct V_1 * V_13 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
F_17 ( V_9 , V_13 ) ;
F_5 ( V_13 ) ;
}
