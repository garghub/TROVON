struct V_1 * F_1 ( T_1 V_2 ,
T_2 V_3 )
{
struct V_1 * V_4 ;
T_3 V_5 ;
V_5 = sizeof ( struct V_1 ) ;
V_5 += V_2 * sizeof ( V_4 -> V_6 [ 0 ] ) ;
V_4 = F_2 ( V_5 , V_3 ) ;
if ( ! V_4 )
return NULL ;
F_3 ( & V_4 -> V_7 , 1 ) ;
V_4 -> V_8 = V_2 ;
return V_4 ;
}
struct V_1 * F_4 ( struct V_1 * V_9 )
{
if ( V_9 )
F_5 ( & V_9 -> V_7 ) ;
return V_9 ;
}
void F_6 ( struct V_1 * V_9 )
{
if ( ! V_9 )
return;
if ( F_7 ( & V_9 -> V_7 ) ) {
F_8 ( V_9 ) ;
}
}
