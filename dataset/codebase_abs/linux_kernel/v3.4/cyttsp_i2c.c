static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , void * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 V_10 [] = {
{
. V_3 = V_7 -> V_3 ,
. V_11 = 0 ,
. V_12 = 1 ,
. V_13 = & V_3 ,
} ,
{
. V_3 = V_7 -> V_3 ,
. V_11 = V_14 ,
. V_12 = V_4 ,
. V_13 = V_5 ,
} ,
} ;
int V_15 ;
V_15 = F_3 ( V_7 -> V_16 , V_10 , F_4 ( V_10 ) ) ;
if ( V_15 < 0 )
return V_15 ;
return V_15 != F_4 ( V_10 ) ? - V_17 : 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , const void * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_15 ;
V_2 -> V_18 [ 0 ] = V_3 ;
memcpy ( & V_2 -> V_18 [ 1 ] , V_5 , V_4 ) ;
V_15 = F_6 ( V_7 , V_2 -> V_18 , V_4 + 1 ) ;
return V_15 < 0 ? V_15 : 0 ;
}
static int T_2 F_7 ( struct V_6 * V_7 ,
const struct V_19 * V_20 )
{
struct V_1 * V_2 ;
if ( ! F_8 ( V_7 -> V_16 , V_21 ) ) {
F_9 ( & V_7 -> V_8 , L_1 ) ;
return - V_17 ;
}
V_2 = F_10 ( & V_22 , & V_7 -> V_8 , V_7 -> V_23 ,
V_24 ) ;
if ( F_11 ( V_2 ) )
return F_12 ( V_2 ) ;
F_13 ( V_7 , V_2 ) ;
return 0 ;
}
static int T_3 F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_15 ( V_7 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
