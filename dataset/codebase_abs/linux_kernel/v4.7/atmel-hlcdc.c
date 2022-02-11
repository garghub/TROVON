static int F_1 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_1 ;
if ( V_2 <= V_6 ) {
T_1 V_7 ;
F_2 ( V_5 -> V_8 + V_9 , V_7 ,
! ( V_7 & V_10 ) , 1 , 100 ) ;
}
F_3 ( V_3 , V_5 -> V_8 + V_2 ) ;
return 0 ;
}
static int F_4 ( void * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
struct V_4 * V_5 = V_1 ;
* V_3 = F_5 ( V_5 -> V_8 + V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_4 * V_5 ;
struct V_13 * V_14 = & V_12 -> V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_5 = F_7 ( V_14 , sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 )
return - V_20 ;
V_16 = F_7 ( V_14 , sizeof( * V_16 ) , V_19 ) ;
if ( ! V_16 )
return - V_20 ;
V_18 = F_8 ( V_12 , V_21 , 0 ) ;
V_5 -> V_8 = F_9 ( V_14 , V_18 ) ;
if ( F_10 ( V_5 -> V_8 ) )
return F_11 ( V_5 -> V_8 ) ;
V_16 -> V_22 = F_12 ( V_12 , 0 ) ;
if ( V_16 -> V_22 < 0 )
return V_16 -> V_22 ;
V_16 -> V_23 = F_13 ( V_14 , L_1 ) ;
if ( F_10 ( V_16 -> V_23 ) ) {
F_14 ( V_14 , L_2 ) ;
return F_11 ( V_16 -> V_23 ) ;
}
V_16 -> V_24 = F_13 ( V_14 , L_3 ) ;
if ( F_10 ( V_16 -> V_24 ) ) {
F_14 ( V_14 , L_4 ) ;
return F_11 ( V_16 -> V_24 ) ;
}
V_16 -> V_25 = F_13 ( V_14 , L_5 ) ;
if ( F_10 ( V_16 -> V_25 ) ) {
F_14 ( V_14 , L_6 ) ;
return F_11 ( V_16 -> V_25 ) ;
}
V_16 -> V_26 = F_15 ( V_14 , NULL , V_5 ,
& V_27 ) ;
if ( F_10 ( V_16 -> V_26 ) )
return F_11 ( V_16 -> V_26 ) ;
F_16 ( V_14 , V_16 ) ;
return F_17 ( V_14 , - 1 , V_28 ,
F_18 ( V_28 ) ,
NULL , 0 , NULL ) ;
}
