static int F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 ;
V_6 = F_3 ( V_3 ) ;
return F_4 ( V_5 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_8 [ 2 ] ;
V_8 [ 0 ] = F_6 ( V_3 ) ;
V_8 [ 1 ] = V_7 ;
return F_7 ( V_5 , V_8 , sizeof( V_8 ) ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned char V_3 , int V_9 ,
void * V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_10 ;
V_3 = F_9 ( V_3 ) ;
V_10 = F_10 ( V_5 , & V_3 , 1 , V_8 , V_9 ) ;
return ( V_10 < 0 ) ? V_10 : 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_11 * V_12 ;
if ( V_5 -> V_13 > V_14 ) {
F_12 ( & V_5 -> V_2 , L_1 , V_5 -> V_13 ) ;
return - V_15 ;
}
V_12 = F_13 ( & V_5 -> V_2 , V_5 -> V_16 ,
V_5 -> V_13 > V_17 ,
& V_18 ) ;
if ( F_14 ( V_12 ) )
return F_15 ( V_12 ) ;
F_16 ( V_5 , V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_18 ( V_5 ) ;
return F_19 ( V_12 ) ;
}
static int T_2 F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_18 ( V_5 ) ;
F_21 ( V_12 ) ;
return 0 ;
}
static int T_2 F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_18 ( V_5 ) ;
F_23 ( V_12 ) ;
return 0 ;
}
