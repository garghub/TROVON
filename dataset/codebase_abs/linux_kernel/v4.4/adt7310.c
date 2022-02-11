static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 , F_4 ( V_3 ) | V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_8 [ 3 ] ;
V_8 [ 0 ] = F_4 ( V_3 ) ;
F_6 ( V_7 , & V_8 [ 1 ] ) ;
return F_7 ( V_5 , V_8 , sizeof( V_8 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_9 ( V_5 , F_4 ( V_3 ) | V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_8 [ 2 ] ;
V_8 [ 0 ] = F_4 ( V_3 ) ;
V_8 [ 1 ] = V_7 ;
return F_7 ( V_5 , V_8 , sizeof( V_8 ) ) ;
}
static int F_11 ( struct V_4 * V_5 )
{
return F_12 ( & V_5 -> V_2 , F_13 ( V_5 ) -> V_9 , V_5 -> V_10 ,
& V_11 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
return F_15 ( & V_5 -> V_2 , V_5 -> V_10 ) ;
}
