int F_1 ( unsigned char V_1 , unsigned char V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_7 = - V_8 ;
V_4 = F_2 ( V_1 ) ;
if ( V_4 && V_4 -> V_9 ) {
V_6 = V_4 -> V_9 ;
if ( V_6 -> V_10 )
V_7 = V_6 -> V_10 ( V_1 , V_2 ) ;
}
return V_7 ;
}
int F_3 ( unsigned int V_1 , unsigned int type )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_7 = - V_8 ;
V_4 = F_2 ( V_1 ) ;
if ( V_4 && V_4 -> V_9 ) {
V_6 = V_4 -> V_9 ;
if ( V_6 -> V_11 )
V_7 = V_6 -> V_11 ( V_1 , type ) ;
}
return V_7 ;
}
