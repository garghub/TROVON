static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_3 ( V_5 , F_4 ( V_3 ) | V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_5 ( ( V_8 V_9 ) V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_11 [ 3 ] ;
V_11 [ 0 ] = F_4 ( V_3 ) ;
F_7 ( V_10 , & V_11 [ 1 ] ) ;
return F_8 ( V_5 , V_11 , sizeof( V_11 ) ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_10 ( V_5 , F_4 ( V_3 ) | V_7 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_11 [ 2 ] ;
V_11 [ 0 ] = F_4 ( V_3 ) ;
V_11 [ 1 ] = V_10 ;
return F_8 ( V_5 , V_11 , sizeof( V_11 ) ) ;
}
static int F_12 ( struct V_4 * V_5 )
{
return F_13 ( & V_5 -> V_2 , F_14 ( V_5 ) -> V_12 , V_5 -> V_13 ,
& V_14 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
return F_16 ( & V_5 -> V_2 , V_5 -> V_13 ) ;
}
