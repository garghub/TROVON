struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ? F_2 ( V_3 -> V_4 ) : NULL ;
}
int F_3 ( struct V_1 * V_5 , const char * V_6 )
{
int V_7 ;
V_7 = F_4 ( V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_5 ( V_5 , V_6 ) ;
if ( V_7 < 0 )
F_6 ( V_5 ) ;
return V_7 ;
}
void F_7 ( struct V_1 * V_5 )
{
F_8 ( V_5 ) ;
F_6 ( V_5 ) ;
}
int F_9 ( struct V_1 * V_5 ,
struct V_8 * V_9 )
{
return F_10 ( & V_5 -> V_3 , V_9 , 0 ) ;
}
void F_11 ( struct V_1 * V_5 )
{
F_12 ( & V_5 -> V_3 ) ;
}
int F_13 ( struct V_8 * V_8 ,
struct V_10 * V_10 )
{
int V_11 ;
V_11 = F_14 ( V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_15 ( V_10 ) ;
if ( V_11 < 0 ) {
F_16 ( V_8 ) ;
return V_11 ;
}
return 0 ;
}
void F_17 ( struct V_8 * V_8 ,
struct V_10 * V_10 )
{
F_18 ( V_10 ) ;
F_16 ( V_8 ) ;
}
