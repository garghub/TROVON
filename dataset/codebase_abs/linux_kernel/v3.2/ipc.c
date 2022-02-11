static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
F_2 ( V_2 , L_1 ) ;
F_3 ( V_2 , V_5 -> V_6 . V_7 ) ;
}
static int F_4 ( struct V_8 * V_9 ,
struct V_8 * V_7 , int error )
{
struct V_4 V_5 ;
F_5 ( & V_5 , V_10 ) ;
V_5 . V_6 . V_11 = V_12 ;
V_5 . V_6 . V_7 = V_7 ;
V_5 . V_6 . error = error ;
return F_6 ( V_13 , V_9 , V_14 , & V_5 ,
F_1 ) ;
}
int F_7 ( struct V_15 * V_16 , struct V_8 * V_17 ,
struct V_8 * V_18 , unsigned int V_19 )
{
if ( F_8 ( V_17 ) || V_17 == V_18 )
return 0 ;
return F_9 ( V_16 , V_17 , V_20 , 1 ) ;
}
int F_10 ( struct V_15 * V_17 , struct V_15 * V_18 ,
unsigned int V_19 )
{
struct V_8 * V_21 ;
const struct V_22 * V_22 = F_11 ( V_17 ) ;
int error = 0 ;
V_21 = F_12 ( V_22 ) ;
if ( ! F_8 ( V_21 ) ) {
const struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_8 * V_24 = F_12 ( V_23 ) ;
error = F_7 ( V_17 , V_21 , V_24 , V_19 ) ;
error = F_4 ( V_21 , V_24 , error ) ;
F_13 ( V_23 ) ;
}
F_13 ( V_22 ) ;
return error ;
}
