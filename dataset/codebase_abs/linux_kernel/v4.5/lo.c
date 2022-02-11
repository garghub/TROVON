static int
F_1 ( T_1 * V_1 , void * V_2 , T_2 * V_3 )
{
F_2 ( ! V_3 -> V_4 ) ;
F_2 ( ! V_3 -> V_5 ) ;
return F_3 ( V_1 , & V_3 -> V_6 , V_1 -> V_7 , V_3 , 0 ) ;
}
static int
F_4 ( T_1 * V_1 , void * V_2 , T_2 * V_3 ,
int V_8 , unsigned int V_9 ,
struct V_10 * V_11 , T_3 * V_12 ,
unsigned int V_13 , unsigned int V_14 , unsigned int V_15 )
{
T_2 * V_16 = V_2 ;
if ( V_3 != NULL ) {
if ( V_16 -> V_17 != NULL ) {
if ( V_11 != NULL )
F_5 ( V_9 , V_11 , V_13 ,
V_16 -> V_18 ,
V_16 -> V_17 ,
V_16 -> V_19 , V_14 ) ;
else
F_6 ( V_9 , V_12 , V_13 ,
V_16 -> V_18 ,
V_16 -> V_17 ,
V_16 -> V_19 , V_14 ) ;
} else {
if ( V_11 != NULL )
F_7 ( V_9 , V_11 , V_13 ,
V_16 -> V_18 ,
V_16 -> V_20 ,
V_16 -> V_19 , V_14 ) ;
else
F_8 ( V_9 , V_12 , V_13 ,
V_16 -> V_18 ,
V_16 -> V_20 ,
V_16 -> V_19 , V_14 ) ;
}
F_9 ( V_1 , V_3 , 0 ) ;
}
F_9 ( V_1 , V_16 , 0 ) ;
return 0 ;
}
static void
F_10 ( T_1 * V_1 )
{
F_11 ( V_21 , L_1 ) ;
F_2 ( V_22 ) ;
V_22 = 0 ;
}
static int
F_12 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_23 == & V_24 ) ;
F_2 ( ! V_22 ) ;
V_22 = 1 ;
return 0 ;
}
