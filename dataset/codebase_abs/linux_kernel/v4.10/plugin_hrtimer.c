static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , void * V_7 )
{
F_2 ( V_2 , L_1 ) ;
if ( F_3 ( V_2 , L_2 , V_6 , L_3 ,
V_4 , 0 ) == - 1 )
F_3 ( V_2 , L_2 , V_6 , L_4 ,
V_4 , 1 ) ;
F_2 ( V_2 , L_5 ) ;
F_3 ( V_2 , L_6 , V_6 , L_7 , V_4 , 1 ) ;
F_4 ( V_2 , L_8 , V_6 , L_9 ,
V_4 , 0 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , void * V_7 )
{
F_2 ( V_2 , L_1 ) ;
if ( F_3 ( V_2 , L_2 , V_6 , L_3 ,
V_4 , 0 ) == - 1 )
F_3 ( V_2 , L_2 , V_6 , L_4 ,
V_4 , 1 ) ;
F_4 ( V_2 , L_8 , V_6 , L_9 ,
V_4 , 0 ) ;
F_2 ( V_2 , L_10 ) ;
F_3 ( V_2 , L_6 , V_6 , L_11 , V_4 , 1 ) ;
F_2 ( V_2 , L_12 ) ;
F_3 ( V_2 , L_6 , V_6 , L_13 , V_4 , 1 ) ;
return 0 ;
}
int F_6 ( struct V_8 * V_8 )
{
F_7 ( V_8 , - 1 ,
L_3 , L_14 ,
F_1 , NULL ) ;
F_7 ( V_8 , - 1 , L_3 , L_15 ,
F_5 , NULL ) ;
return 0 ;
}
void F_8 ( struct V_8 * V_8 )
{
F_9 ( V_8 , - 1 ,
L_3 , L_14 ,
F_1 , NULL ) ;
F_9 ( V_8 , - 1 , L_3 , L_15 ,
F_5 , NULL ) ;
}
