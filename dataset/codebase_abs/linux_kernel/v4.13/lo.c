static int
F_1 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
F_2 ( ! V_5 -> V_6 ) ;
F_2 ( ! V_5 -> V_7 ) ;
return F_3 ( V_2 , & V_5 -> V_8 , V_2 -> V_9 , V_5 , 0 ) ;
}
static int
F_4 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 ,
int V_10 , struct V_11 * V_12 , unsigned int V_13 )
{
struct V_4 * V_14 = V_3 ;
if ( V_5 ) {
if ( V_14 -> V_15 )
F_5 ( V_12 ,
V_14 -> V_16 ,
V_14 -> V_15 ,
V_14 -> V_17 ,
F_6 ( V_12 ) ) ;
else
F_7 ( V_12 ,
V_14 -> V_16 ,
V_14 -> V_18 ,
V_14 -> V_17 ,
F_6 ( V_12 ) ) ;
F_8 ( V_2 , V_5 , 0 ) ;
}
F_8 ( V_2 , V_14 , 0 ) ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
F_10 ( V_19 , L_1 ) ;
F_2 ( V_20 ) ;
V_20 = 0 ;
}
static int
F_11 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_21 == & V_22 ) ;
F_2 ( ! V_20 ) ;
V_20 = 1 ;
return 0 ;
}
