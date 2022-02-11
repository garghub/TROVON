static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_9 = ( V_2 -> V_10 == V_11 ) ?
V_12 : V_13 ;
return F_3 ( V_8 , V_9 , V_2 -> V_14 -> V_15 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_16 * V_17 ;
struct V_18 V_19 ;
int V_20 ;
V_20 = V_16 ( V_6 -> V_21 . V_22 -> V_23 , 0 , V_24 ,
NULL , & V_17 ) ;
if ( V_20 < 0 )
return V_20 ;
memset ( & V_19 , 0 , sizeof( struct V_18 ) ) ;
V_20 = F_5 ( V_17 , & V_19 , & V_8 ) ;
if ( V_20 < 0 )
return V_20 ;
F_6 ( V_6 , V_8 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
F_8 ( V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
F_10 ( V_8 ) ;
return 0 ;
}
static int F_11 ( struct V_25 * V_26 )
{
return F_12 ( & V_26 -> V_27 ,
& V_28 , & V_29 , 1 ) ;
}
static int F_13 ( struct V_25 * V_26 )
{
F_14 ( & V_26 -> V_27 ) ;
return 0 ;
}
