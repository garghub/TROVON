struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ? F_2 ( V_3 -> V_4 ) : NULL ;
}
int F_3 ( struct V_1 * V_5 ,
struct V_6 * V_7 ,
unsigned long V_8 )
{
return F_4 ( & V_5 -> V_3 , V_7 , V_8 ) ;
}
void F_5 ( struct V_1 * V_5 )
{
F_6 ( & V_5 -> V_3 ) ;
}
int F_7 ( struct V_6 * V_6 ,
struct V_9 * V_9 )
{
int V_10 ;
V_10 = F_8 ( V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_9 ( V_9 ) ;
if ( V_10 < 0 ) {
F_10 ( V_6 ) ;
return V_10 ;
}
return 0 ;
}
void F_11 ( struct V_6 * V_6 ,
struct V_9 * V_9 )
{
F_12 ( V_9 ) ;
F_10 ( V_6 ) ;
}
