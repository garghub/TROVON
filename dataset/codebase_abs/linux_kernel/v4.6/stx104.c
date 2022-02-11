static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
if ( V_7 != V_10 )
return - V_11 ;
* V_5 = V_9 -> V_12 [ V_4 -> V_13 ] ;
return V_14 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int V_5 , int V_6 , long V_7 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
const unsigned V_15 = 2 * V_4 -> V_13 ;
if ( V_7 != V_10 )
return - V_11 ;
V_9 -> V_12 [ V_4 -> V_13 ] = V_5 ;
F_4 ( V_5 , V_9 -> V_16 + 4 + V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_17 * V_18 , unsigned int V_19 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_2 = F_6 ( V_18 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_20 ;
if ( ! F_7 ( V_18 , V_16 [ V_19 ] , V_21 ,
F_8 ( V_18 ) ) ) {
F_9 ( V_18 , L_1 ,
V_16 [ V_19 ] , V_16 [ V_19 ] + V_21 ) ;
return - V_22 ;
}
V_2 -> V_23 = & V_24 ;
V_2 -> V_25 = V_26 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = F_8 ( V_18 ) ;
V_9 = F_2 ( V_2 ) ;
V_9 -> V_16 = V_16 [ V_19 ] ;
F_4 ( 0 , V_16 [ V_19 ] + 4 ) ;
F_4 ( 0 , V_16 [ V_19 ] + 6 ) ;
return F_10 ( V_18 , V_2 ) ;
}
static void T_1 F_11 ( void )
{
F_12 ( & V_32 ) ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_32 , V_33 ) ;
}
