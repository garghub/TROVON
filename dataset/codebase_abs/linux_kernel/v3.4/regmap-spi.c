static int F_1 ( struct V_1 * V_2 , const void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 , V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
const void * V_7 , T_1 V_8 ,
const void * V_9 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 V_12 ;
struct V_13 V_14 [ 2 ] = { { . V_15 = V_7 , . V_16 = V_8 , } ,
{ . V_15 = V_9 , . V_16 = V_10 , } , } ;
F_5 ( & V_12 ) ;
F_6 ( & V_14 [ 0 ] , & V_12 ) ;
F_6 ( & V_14 [ 1 ] , & V_12 ) ;
return F_7 ( V_6 , & V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
const void * V_7 , T_1 V_17 ,
void * V_9 , T_1 V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_9 ( V_6 , V_7 , V_17 , V_9 , V_18 ) ;
}
struct V_19 * F_10 ( struct V_5 * V_6 ,
const struct V_20 * V_21 )
{
return F_11 ( & V_6 -> V_2 , & V_22 , V_21 ) ;
}
struct V_19 * F_12 ( struct V_5 * V_6 ,
const struct V_20 * V_21 )
{
return F_13 ( & V_6 -> V_2 , & V_22 , V_21 ) ;
}
