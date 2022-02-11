T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
const T_2 * V_4 = V_2 -> V_5 ;
if ( V_3 != 0 )
return 0 ;
return F_2 ( & V_4 -> V_6 ) ;
}
T_3 F_3 ( T_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
int V_8 ;
V_8 = F_4 ( V_9 ) ;
if ( V_8 & V_10 ) {
F_5 ( V_9 , V_11 ) ;
F_6 ( & V_4 -> V_6 ) ;
F_7 ( V_2 , 0 ) ;
return V_12 ;
}
return V_13 ;
}
int F_8 ( struct V_1 * V_2 , int V_3 )
{
T_2 * V_4 = V_2 -> V_5 ;
if ( V_3 != 0 ) {
F_9 ( L_1 , V_14 , V_3 ) ;
return - V_15 ;
}
F_5 ( V_16 , V_17 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 != 0 )
F_9 ( L_1 , V_14 , V_3 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
F_5 ( V_16 , 0 ) ;
F_5 ( V_9 , V_11 ) ;
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
F_5 ( V_16 , 0 ) ;
}
