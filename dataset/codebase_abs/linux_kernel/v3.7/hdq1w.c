int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 0 ;
F_2 ( V_2 ) ;
V_3 = F_3 ( V_2 , V_5 ) ;
V_3 |= 1 << V_6 ;
F_4 ( V_3 , V_2 , V_5 ) ;
F_5 ( ( F_3 ( V_2 ,
V_2 -> V_7 -> V_8 -> V_9 )
& V_10 ) ,
V_11 , V_4 ) ;
if ( V_4 == V_11 )
F_6 ( L_1 ,
V_12 , V_2 -> V_13 , V_11 ) ;
else
F_7 ( L_2 , V_12 ,
V_2 -> V_13 , V_4 ) ;
return 0 ;
}
static int T_2 F_8 ( void )
{
int V_14 = - 1 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
char * V_17 = L_3 ;
char * V_18 = L_4 ;
V_2 = F_9 ( V_17 ) ;
if ( ! V_2 )
return 0 ;
V_16 = F_10 ( V_18 , V_14 , V_2 , NULL , 0 , NULL , 0 , 0 ) ;
F_11 ( F_12 ( V_16 ) , L_5 ,
V_18 , V_2 -> V_13 ) ;
return 0 ;
}
