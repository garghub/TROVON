static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
unsigned int V_4 ;
int V_5 ;
V_5 = F_2 ( V_3 , V_6 , V_7 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_3 ( V_3 , V_8 , & V_4 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_1 , V_5 ) ;
return V_5 ;
}
F_5 ( V_2 , L_2 , V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_2 ;
struct V_3 * V_3 ;
int V_5 ;
V_3 = F_7 ( V_10 , & V_11 ) ;
if ( F_8 ( V_3 ) ) {
F_4 ( V_2 , L_3 ,
F_9 ( V_3 ) ) ;
return F_9 ( V_3 ) ;
}
F_10 ( V_10 , V_3 ) ;
V_5 = F_1 ( V_2 , V_3 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 , L_4 , V_5 ) ;
return V_5 ;
}
V_5 = F_11 ( V_2 , V_12 , V_13 ,
F_12 ( V_13 ) , NULL , 0 , NULL ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 , L_5 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
