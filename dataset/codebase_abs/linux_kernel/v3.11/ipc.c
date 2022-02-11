static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
F_2 ( V_2 , L_1 ) ;
F_3 ( V_2 , V_5 -> V_6 -> V_7 ) ;
}
static int F_4 ( struct V_8 * V_9 ,
struct V_8 * V_7 , int error )
{
struct V_4 V_5 ;
struct V_10 V_6 = { 0 ,} ;
V_5 . type = V_11 ;
V_5 . V_6 = & V_6 ;
V_6 . V_12 = V_13 ;
V_6 . V_7 = V_7 ;
V_6 . error = error ;
return F_5 ( V_14 , V_9 , V_15 , & V_5 ,
F_1 ) ;
}
int F_6 ( struct V_16 * V_17 , struct V_8 * V_18 ,
struct V_8 * V_19 , unsigned int V_20 )
{
if ( F_7 ( V_18 ) || V_18 == V_19 )
return 0 ;
return F_8 ( V_17 , V_18 , V_21 , 1 ) ;
}
int F_9 ( struct V_16 * V_18 , struct V_16 * V_19 ,
unsigned int V_20 )
{
struct V_8 * V_22 = F_10 ( V_18 ) ;
int error = 0 ;
if ( ! F_7 ( V_22 ) ) {
struct V_8 * V_23 = F_10 ( V_19 ) ;
error = F_6 ( V_18 , V_22 , V_23 , V_20 ) ;
error = F_4 ( V_22 , V_23 , error ) ;
F_11 ( V_23 ) ;
}
F_11 ( V_22 ) ;
return error ;
}
