static int
F_1 ( T_1 * V_1 , void * V_2 , T_2 * V_3 )
{
F_2 ( ! V_3 -> V_4 ) ;
F_2 ( ! V_3 -> V_5 ) ;
return F_3 ( V_1 , & V_3 -> V_6 , V_1 -> V_7 , V_3 , 0 ) ;
}
static int
F_4 ( T_1 * V_1 , void * V_2 , T_2 * V_3 ,
int V_8 , struct V_9 * V_10 , unsigned int V_11 )
{
T_2 * V_12 = V_2 ;
if ( V_3 ) {
if ( V_12 -> V_13 )
F_5 ( V_10 ,
V_12 -> V_14 ,
V_12 -> V_13 ,
V_12 -> V_15 ,
F_6 ( V_10 ) ) ;
else
F_7 ( V_10 ,
V_12 -> V_14 ,
V_12 -> V_16 ,
V_12 -> V_15 ,
F_6 ( V_10 ) ) ;
F_8 ( V_1 , V_3 , 0 ) ;
}
F_8 ( V_1 , V_12 , 0 ) ;
return 0 ;
}
static void
F_9 ( T_1 * V_1 )
{
F_10 ( V_17 , L_1 ) ;
F_2 ( V_18 ) ;
V_18 = 0 ;
}
static int
F_11 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_19 == & V_20 ) ;
F_2 ( ! V_18 ) ;
V_18 = 1 ;
return 0 ;
}
