static struct V_1 * T_1 F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
void T_2 * V_5 ;
V_5 = F_2 ( V_3 , 0 ) ;
if ( ! V_5 ) {
F_3 ( L_1 , V_6 ) ;
return F_4 ( - V_7 ) ;
}
V_4 = F_5 ( V_3 , V_5 , V_8 ) ;
if ( F_6 ( V_4 ) ) {
F_3 ( L_2 , V_6 ) ;
F_7 ( V_5 ) ;
return F_4 ( - V_7 ) ;
}
F_8 ( V_4 , V_9 ,
F_9 ( V_9 ) ,
V_10 ) ;
F_10 ( V_4 , V_11 ,
F_9 ( V_11 ) ) ;
F_11 ( V_4 , V_12 , L_3 ,
V_13 , F_9 ( V_13 ) ,
& V_14 , V_15 ,
F_9 ( V_15 ) ) ;
F_12 ( V_3 , 9 , V_5 + F_13 ( 0 ) ,
V_16 ) ;
F_14 ( V_4 , V_17 , NULL ) ;
return V_4 ;
}
static void T_1 F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( F_6 ( V_4 ) )
return;
F_10 ( V_4 , V_18 ,
F_9 ( V_18 ) ) ;
F_16 ( V_19 ,
F_9 ( V_19 ) ) ;
F_17 ( V_3 , V_4 ) ;
}
static void T_1 F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( F_6 ( V_4 ) )
return;
F_10 ( V_4 , V_20 ,
F_9 ( V_20 ) ) ;
F_16 ( V_19 ,
F_9 ( V_19 ) ) ;
F_17 ( V_3 , V_4 ) ;
}
