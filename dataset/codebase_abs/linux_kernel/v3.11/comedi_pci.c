struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ? F_2 ( V_3 -> V_4 ) : NULL ;
}
int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 ;
if ( ! V_5 )
return - V_7 ;
V_6 = F_4 ( V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_5 , V_3 -> V_8 ) ;
if ( V_6 < 0 )
F_6 ( V_5 ) ;
else
V_3 -> V_9 = true ;
return V_6 ;
}
void F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 && V_3 -> V_9 ) {
F_8 ( V_5 ) ;
F_6 ( V_5 ) ;
}
V_3 -> V_9 = false ;
}
int F_9 ( struct V_1 * V_5 ,
struct V_10 * V_11 ,
unsigned long V_12 )
{
return F_10 ( & V_5 -> V_3 , V_11 , V_12 ) ;
}
void F_11 ( struct V_1 * V_5 )
{
F_12 ( & V_5 -> V_3 ) ;
}
int F_13 ( struct V_10 * V_10 ,
struct V_13 * V_13 )
{
int V_14 ;
V_14 = F_14 ( V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_15 ( V_13 ) ;
if ( V_14 < 0 ) {
F_16 ( V_10 ) ;
return V_14 ;
}
return 0 ;
}
void F_17 ( struct V_10 * V_10 ,
struct V_13 * V_13 )
{
F_18 ( V_13 ) ;
F_16 ( V_10 ) ;
}
