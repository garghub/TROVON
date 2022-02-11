int F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 ) ;
if ( F_3 ( & F_4 ( V_2 ) -> V_4 ) <= F_4 ( V_2 ) -> V_5 )
return 1 ;
F_5 ( V_2 , V_3 ) ;
F_6 ( & V_2 -> V_6 -> V_7 ) ;
return 0 ;
}
struct V_8 * F_7 ( struct V_1 * V_2 , int V_9 ,
T_1 V_10 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
int V_13 = F_8 ( V_9 ) ;
F_2 ( V_2 , V_13 ) ;
if ( F_3 ( & V_12 -> V_4 ) <= V_12 -> V_5 ) {
struct V_8 * V_14 = F_9 ( V_9 , V_10 ) ;
if ( V_14 ) {
F_10 ( V_14 -> V_3 - V_13 ,
& V_12 -> V_4 ) ;
return V_14 ;
}
}
F_5 ( V_2 , V_13 ) ;
F_6 ( & V_2 -> V_6 -> V_7 ) ;
return NULL ;
}
int F_11 ( const struct V_15 * V_16 )
{
if ( V_16 -> V_17 && V_16 -> V_17 != V_18 )
return - V_16 -> V_17 ;
if ( V_16 -> V_19 && ! V_16 -> V_17 )
return V_16 -> V_19 ;
if ( V_16 -> V_20 != V_18 )
return - V_16 -> V_20 ;
return 0 ;
}
void F_12 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
#define F_13 ( T_2 ) to->i = atomic_read(&from->i)
V_25
#undef F_13
}
void F_14 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
#define F_13 ( T_2 ) atomic_sub(to->i, &from->i)
V_25
#undef F_13
}
