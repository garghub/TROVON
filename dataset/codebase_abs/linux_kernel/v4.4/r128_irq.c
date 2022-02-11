T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
const T_2 * V_4 = V_2 -> V_5 ;
if ( V_3 != 0 )
return 0 ;
return F_2 ( & V_4 -> V_6 ) ;
}
T_3 F_3 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
int V_9 ;
V_9 = F_4 ( V_10 ) ;
if ( V_9 & V_11 ) {
F_5 ( V_10 , V_12 ) ;
F_6 ( & V_4 -> V_6 ) ;
F_7 ( V_2 , 0 ) ;
return V_13 ;
}
return V_14 ;
}
int F_8 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_2 * V_4 = V_2 -> V_5 ;
if ( V_3 != 0 ) {
F_9 ( L_1 , V_15 , V_3 ) ;
return - V_16 ;
}
F_5 ( V_17 , V_18 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 != 0 )
F_9 ( L_1 , V_15 , V_3 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
F_5 ( V_17 , 0 ) ;
F_5 ( V_10 , V_12 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
if ( ! V_4 )
return;
F_5 ( V_17 , 0 ) ;
}
