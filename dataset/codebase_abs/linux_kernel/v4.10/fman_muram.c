static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return V_3 - ( unsigned long ) V_2 -> V_4 ;
}
struct V_1 * F_2 ( T_1 V_5 , T_2 V_6 )
{
struct V_1 * V_2 ;
void T_3 * V_3 ;
int V_7 ;
V_2 = F_3 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_9 = F_4 ( F_5 ( 64 ) , - 1 ) ;
if ( ! V_2 -> V_9 ) {
F_6 ( L_1 , V_10 ) ;
goto V_11;
}
V_3 = F_7 ( V_5 , V_6 ) ;
if ( ! V_3 ) {
F_6 ( L_2 , V_10 ) ;
goto V_12;
}
V_7 = F_8 ( V_2 -> V_9 , ( unsigned long ) V_3 ,
V_5 , V_6 , - 1 ) ;
if ( V_7 < 0 ) {
F_6 ( L_3 , V_10 ) ;
F_9 ( V_3 ) ;
goto V_12;
}
F_10 ( V_3 , 0 , ( int ) V_6 ) ;
V_2 -> V_4 = V_3 ;
V_2 -> V_13 = V_5 ;
return V_2 ;
V_12:
F_11 ( V_2 -> V_9 ) ;
V_11:
F_12 ( V_2 ) ;
return NULL ;
}
unsigned long F_13 ( struct V_1 * V_2 ,
unsigned long V_14 )
{
return V_14 + ( unsigned long ) V_2 -> V_4 ;
}
unsigned long F_14 ( struct V_1 * V_2 , T_2 V_6 )
{
unsigned long V_3 ;
V_3 = F_15 ( V_2 -> V_9 , V_6 ) ;
if ( ! V_3 )
return - V_15 ;
F_10 ( ( void T_3 * ) V_3 , 0 , V_6 ) ;
return F_1 ( V_2 , V_3 ) ;
}
void F_16 ( struct V_1 * V_2 , unsigned long V_14 ,
T_2 V_6 )
{
unsigned long V_16 = F_13 ( V_2 , V_14 ) ;
F_17 ( V_2 -> V_9 , V_16 , V_6 ) ;
}
