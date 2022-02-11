static int F_1 ( void * V_1 , const void * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
return F_3 ( V_7 , V_2 , V_3 ) ;
}
static int F_4 ( void * V_1 ,
const void * V_8 , T_1 V_9 ,
const void * V_10 , T_1 V_11 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_12 V_13 ;
struct V_14 V_15 [ 2 ] = { { . V_16 = V_8 , . V_17 = V_9 , } ,
{ . V_16 = V_10 , . V_17 = V_11 , } , } ;
F_5 ( & V_13 ) ;
F_6 ( & V_15 [ 0 ] , & V_13 ) ;
F_6 ( & V_15 [ 1 ] , & V_13 ) ;
return F_7 ( V_7 , & V_13 ) ;
}
static int F_8 ( void * V_1 ,
const void * V_8 , T_1 V_18 ,
void * V_10 , T_1 V_19 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
return F_9 ( V_7 , V_8 , V_18 , V_10 , V_19 ) ;
}
struct V_20 * F_10 ( struct V_6 * V_7 ,
const struct V_21 * V_22 )
{
return F_11 ( & V_7 -> V_5 , & V_23 , & V_7 -> V_5 , V_22 ) ;
}
struct V_20 * F_12 ( struct V_6 * V_7 ,
const struct V_21 * V_22 )
{
return F_13 ( & V_7 -> V_5 , & V_23 , & V_7 -> V_5 , V_22 ) ;
}
