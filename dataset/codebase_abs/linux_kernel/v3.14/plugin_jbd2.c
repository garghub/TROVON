static unsigned long long
F_1 ( struct V_1 * V_2 ,
unsigned long long * args )
{
unsigned int V_3 = args [ 0 ] ;
F_2 ( V_2 , L_1 , F_3 ( V_3 ) , F_4 ( V_3 ) ) ;
return 0 ;
}
static unsigned long long
F_5 ( struct V_1 * V_2 ,
unsigned long long * args )
{
unsigned long long V_4 = args [ 0 ] ;
F_2 ( V_2 , L_2 , V_4 ) ;
return V_4 ;
}
int F_6 ( struct V_5 * V_5 )
{
F_7 ( V_5 ,
F_1 ,
V_6 ,
L_3 ,
V_7 ,
V_8 ) ;
F_7 ( V_5 ,
F_5 ,
V_9 ,
L_4 ,
V_9 ,
V_8 ) ;
return 0 ;
}
void F_8 ( struct V_5 * V_5 )
{
F_9 ( V_5 , F_1 ,
L_3 ) ;
F_9 ( V_5 , F_5 ,
L_4 ) ;
}
