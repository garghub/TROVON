static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
F_2 ( V_2 , L_1 ) ;
F_3 ( V_2 , F_4 ( V_5 ) -> V_6 -> V_7 . V_8 ) ;
}
static int F_5 ( struct V_9 * V_10 ,
struct V_9 * V_11 , int error )
{
F_6 ( V_5 , V_12 , V_13 ) ;
F_4 ( & V_5 ) -> V_6 = V_11 ;
F_4 ( & V_5 ) -> error = error ;
return F_7 ( V_14 , V_10 , & V_5 , F_1 ) ;
}
int F_8 ( struct V_9 * V_15 , struct V_9 * V_16 ,
unsigned int V_17 )
{
if ( F_9 ( V_15 ) || V_15 == V_16 )
return 0 ;
return F_10 ( V_15 , V_18 , 1 ) ;
}
int F_11 ( struct V_19 * V_15 , struct V_19 * V_16 ,
unsigned int V_17 )
{
struct V_9 * V_20 = F_12 ( V_15 ) ;
int error = 0 ;
if ( ! F_9 ( V_20 ) ) {
struct V_9 * V_21 = F_12 ( V_16 ) ;
error = F_8 ( V_20 , V_21 , V_17 ) ;
error = F_5 ( V_20 , V_21 , error ) ;
F_13 ( V_21 ) ;
}
F_13 ( V_20 ) ;
return error ;
}
