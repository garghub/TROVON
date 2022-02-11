static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 ,
T_1 V_5 , int V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_9 ;
struct V_10 V_11 [] = {
F_2 ( V_5 , V_12 ) ,
F_3 ( V_6 ) ,
} ;
F_4 ( L_1 ,
V_4 , V_6 ) ;
V_9 = F_5 ( V_3 , L_2 , V_4 ,
V_11 , F_6 ( V_11 ) ,
V_8 , sizeof( * V_8 ) ) ;
if ( ! V_9 ) {
F_7 ( L_3 ,
V_4 ) ;
return NULL ;
}
return V_9 ;
}
void F_8 ( struct V_2 * V_3 )
{
F_4 ( L_4 , V_13 ) ;
F_9 ( & V_14 ) ;
F_4 ( L_5 ) ;
F_1 ( V_3 , 0 , V_15 , V_16 ,
& V_17 ) ;
F_1 ( V_3 , 1 , V_18 , V_19 ,
& V_20 ) ;
F_1 ( V_3 , 2 , V_21 , V_22 ,
& V_23 ) ;
F_1 ( V_3 , 3 , V_24 , V_19 ,
& V_25 ) ;
}
void F_10 ( struct V_2 * V_3 )
{
F_4 ( L_6 , V_13 ) ;
F_9 ( & V_26 ) ;
}
