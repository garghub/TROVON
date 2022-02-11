static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 1 ;
V_4 -> V_6 = L_1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_4 ( L_2 ,
V_2 , V_2 -> V_9 , V_8 ) ;
F_5 ( V_2 , V_10 , V_8 -> V_11 ) ;
F_5 ( V_2 , V_12 , V_8 -> V_13 ) ;
F_5 ( V_2 , V_14 , V_8 -> V_15 | V_16 ) ;
F_5 ( V_2 , V_14 , V_8 -> V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 )
{
return F_7 ( V_18 , & V_19 ) ;
}
static inline int F_8 ( void )
{
return F_9 ( & V_20 , & V_19 ) ;
}
static inline void F_10 ( void )
{
F_11 ( & V_20 ) ;
}
