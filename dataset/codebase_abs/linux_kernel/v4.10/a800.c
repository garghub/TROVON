static int F_1 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static int F_2 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_8 * * V_9 , int * V_10 )
{
* V_10 = V_5 -> V_11 . V_12 != 1 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_13 , int * V_14 )
{
int V_15 ;
T_2 * V_16 = F_4 ( 5 , V_17 ) ;
if ( ! V_16 )
return - V_18 ;
if ( F_5 ( V_2 -> V_5 , F_6 ( V_2 -> V_5 , 0 ) ,
0x04 , V_19 | V_20 , 0 , 0 , V_16 , 5 ,
2000 ) != 5 ) {
V_15 = - V_21 ;
goto V_22;
}
F_7 ( V_2 , V_16 , V_13 , V_14 ) ;
if ( V_16 [ 0 ] != 0 )
F_8 ( L_1 , 5 , V_16 ) ;
V_15 = 0 ;
V_22:
F_9 ( V_16 ) ;
return V_15 ;
}
static int F_10 ( struct V_23 * V_24 ,
const struct V_25 * V_26 )
{
return F_11 ( V_24 , & V_27 ,
V_28 , NULL , V_29 ) ;
}
