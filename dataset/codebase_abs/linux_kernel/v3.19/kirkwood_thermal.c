static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned long V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_4 = F_2 ( V_6 -> V_8 ) ;
if ( ! ( ( V_4 >> V_9 ) &
V_10 ) ) {
F_3 ( & V_2 -> V_11 ,
L_1 ) ;
return - V_12 ;
}
V_4 = ( V_4 >> V_13 ) &
V_14 ;
* V_3 = ( ( 3220000000UL - ( 10000000UL * V_4 ) ) / 13625 ) ;
return 0 ;
}
static int F_4 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 ;
struct V_17 * V_18 ;
V_6 = F_5 ( & V_16 -> V_19 , sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 )
return - V_21 ;
V_18 = F_6 ( V_16 , V_22 , 0 ) ;
V_6 -> V_8 = F_7 ( & V_16 -> V_19 , V_18 ) ;
if ( F_8 ( V_6 -> V_8 ) )
return F_9 ( V_6 -> V_8 ) ;
V_2 = F_10 ( L_2 , 0 , 0 ,
V_6 , & V_23 , NULL , 0 , 0 ) ;
if ( F_8 ( V_2 ) ) {
F_3 ( & V_16 -> V_19 ,
L_3 ) ;
return F_9 ( V_2 ) ;
}
F_11 ( V_16 , V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_15 * V_16 )
{
struct V_1 * V_24 =
F_13 ( V_16 ) ;
F_14 ( V_24 ) ;
return 0 ;
}
