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
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_11 = 0 ;
T_1 V_12 ;
F_6 ( V_2 ) ;
while ( ! F_1 ( V_2 ) ) {
F_7 ( 100 , 1000 ) ;
V_11 ++ ;
if ( V_11 >= 200 ) {
F_8 ( V_2 -> V_13 , L_1 ) ;
return;
}
}
V_12 = F_9 ( V_5 -> V_14 + V_15 ) ;
V_12 &= 0xffff ;
F_10 ( V_12 , V_5 -> V_14 + V_15 ) ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = & V_5 -> V_2 ;
V_2 -> V_13 = V_5 -> V_13 ;
V_2 -> V_17 = V_5 -> V_14 ;
V_2 -> V_18 = - 1 ;
V_2 -> V_19 = & V_20 ;
V_16 = F_12 ( V_2 ) ;
if ( V_16 ) {
F_8 ( V_2 -> V_13 , L_2 ) ;
return V_16 ;
}
return 0 ;
}
static int T_2 F_13 ( struct V_21 * V_22 )
{
struct V_4 * V_5 ;
struct V_23 * V_17 ;
T_1 V_7 [ 2 ] ;
int V_16 ;
V_5 = F_14 ( & V_22 -> V_13 , sizeof( * V_5 ) , V_24 ) ;
if ( ! V_5 )
return - V_25 ;
V_5 -> V_13 = & V_22 -> V_13 ;
V_17 = F_15 ( V_22 , V_26 , L_3 ) ;
V_5 -> V_14 = F_16 ( & V_22 -> V_13 , V_17 ) ;
if ( F_17 ( V_5 -> V_14 ) ) {
F_8 ( & V_22 -> V_13 , L_4 ) ;
return F_18 ( V_5 -> V_14 ) ;
}
V_5 -> V_6 = F_19 ( V_22 -> V_13 . V_27 ,
L_5 ) ;
if ( F_17 ( V_5 -> V_6 ) ) {
F_8 ( & V_22 -> V_13 , L_6 ) ;
return F_18 ( V_5 -> V_6 ) ;
}
V_16 = F_20 ( V_22 -> V_13 . V_27 ,
L_5 , V_7 , 2 ) ;
if ( V_16 )
return V_16 ;
V_5 -> V_7 = V_7 [ 1 ] ;
V_16 = F_11 ( V_5 ) ;
if ( V_16 < 0 )
return V_16 ;
F_21 ( V_22 , V_5 ) ;
return 0 ;
}
