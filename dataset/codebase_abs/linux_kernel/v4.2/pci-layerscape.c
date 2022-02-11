static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_5 -> V_6 , F_4 ( V_5 -> V_7 ) , & V_3 ) ;
V_3 = ( V_3 >> V_8 ) & V_9 ;
if ( V_3 < V_10 )
return 0 ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < 200 ; V_11 ++ ) {
if ( F_6 ( V_2 ) )
return 0 ;
F_7 ( 100 , 1000 ) ;
}
F_8 ( V_2 -> V_12 , L_1 ) ;
return - V_13 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 ;
F_10 ( V_2 ) ;
F_5 ( V_2 ) ;
V_14 = F_11 ( V_5 -> V_15 + V_16 ) ;
V_14 &= 0xffff ;
F_12 ( V_14 , V_5 -> V_15 + V_16 ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = & V_5 -> V_2 ;
V_2 -> V_12 = V_5 -> V_12 ;
V_2 -> V_18 = V_5 -> V_15 ;
V_2 -> V_19 = - 1 ;
V_2 -> V_20 = & V_21 ;
V_17 = F_14 ( V_2 ) ;
if ( V_17 ) {
F_8 ( V_2 -> V_12 , L_2 ) ;
return V_17 ;
}
return 0 ;
}
static int T_2 F_15 ( struct V_22 * V_23 )
{
struct V_4 * V_5 ;
struct V_24 * V_18 ;
T_1 V_7 [ 2 ] ;
int V_17 ;
V_5 = F_16 ( & V_23 -> V_12 , sizeof( * V_5 ) , V_25 ) ;
if ( ! V_5 )
return - V_26 ;
V_5 -> V_12 = & V_23 -> V_12 ;
V_18 = F_17 ( V_23 , V_27 , L_3 ) ;
V_5 -> V_15 = F_18 ( & V_23 -> V_12 , V_18 ) ;
if ( F_19 ( V_5 -> V_15 ) ) {
F_8 ( & V_23 -> V_12 , L_4 ) ;
return F_20 ( V_5 -> V_15 ) ;
}
V_5 -> V_6 = F_21 ( V_23 -> V_12 . V_28 ,
L_5 ) ;
if ( F_19 ( V_5 -> V_6 ) ) {
F_8 ( & V_23 -> V_12 , L_6 ) ;
return F_20 ( V_5 -> V_6 ) ;
}
V_17 = F_22 ( V_23 -> V_12 . V_28 ,
L_5 , V_7 , 2 ) ;
if ( V_17 )
return V_17 ;
V_5 -> V_7 = V_7 [ 1 ] ;
V_17 = F_13 ( V_5 ) ;
if ( V_17 < 0 )
return V_17 ;
F_23 ( V_23 , V_5 ) ;
return 0 ;
}
