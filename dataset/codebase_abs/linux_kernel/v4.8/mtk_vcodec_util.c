void T_1 * F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_1 * V_4 = (struct V_1 * ) V_2 ;
if ( ! V_2 || V_3 >= V_5 ) {
F_2 ( L_1 , V_3 ) ;
return NULL ;
}
return V_4 -> V_6 -> V_7 [ V_3 ] ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
unsigned long V_10 = V_9 -> V_10 ;
struct V_1 * V_4 = (struct V_1 * ) V_2 ;
struct V_11 * V_6 = & V_4 -> V_6 -> V_12 -> V_6 ;
V_9 -> V_13 = F_4 ( V_6 , V_10 , & V_9 -> V_14 , V_15 ) ;
if ( ! V_9 -> V_13 ) {
F_2 ( L_2 , F_5 ( V_6 ) ,
V_10 ) ;
return - V_16 ;
}
memset ( V_9 -> V_13 , 0 , V_10 ) ;
F_6 ( 3 , L_3 , V_4 -> V_17 , V_9 -> V_13 ) ;
F_6 ( 3 , L_4 , V_4 -> V_17 ,
( unsigned long ) V_9 -> V_14 ) ;
F_6 ( 3 , L_5 , V_4 -> V_17 , V_10 ) ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
unsigned long V_10 = V_9 -> V_10 ;
struct V_1 * V_4 = (struct V_1 * ) V_2 ;
struct V_11 * V_6 = & V_4 -> V_6 -> V_12 -> V_6 ;
if ( ! V_9 -> V_13 ) {
F_2 ( L_6 , F_5 ( V_6 ) ,
V_10 ) ;
return;
}
F_8 ( V_6 , V_10 , V_9 -> V_13 , V_9 -> V_14 ) ;
V_9 -> V_13 = NULL ;
V_9 -> V_14 = 0 ;
V_9 -> V_10 = 0 ;
F_6 ( 3 , L_3 , V_4 -> V_17 , V_9 -> V_13 ) ;
F_6 ( 3 , L_4 , V_4 -> V_17 ,
( unsigned long ) V_9 -> V_14 ) ;
F_6 ( 3 , L_5 , V_4 -> V_17 , V_10 ) ;
}
