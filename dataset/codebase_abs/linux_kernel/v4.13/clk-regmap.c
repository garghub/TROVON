int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
int V_6 ;
V_6 = F_3 ( V_4 -> V_7 , V_4 -> V_8 , & V_5 ) ;
if ( V_6 != 0 )
return V_6 ;
if ( V_4 -> V_9 )
return ( V_5 & V_4 -> V_10 ) == 0 ;
else
return ( V_5 & V_4 -> V_10 ) != 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
if ( V_4 -> V_9 )
V_5 = 0 ;
else
V_5 = V_4 -> V_10 ;
return F_5 ( V_4 -> V_7 , V_4 -> V_8 ,
V_4 -> V_10 , V_5 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
if ( V_4 -> V_9 )
V_5 = V_4 -> V_10 ;
else
V_5 = 0 ;
F_5 ( V_4 -> V_7 , V_4 -> V_8 , V_4 -> V_10 ,
V_5 ) ;
}
int F_7 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
if ( V_12 && F_8 ( V_12 , NULL ) )
V_4 -> V_7 = F_8 ( V_12 , NULL ) ;
else if ( V_12 && V_12 -> V_13 )
V_4 -> V_7 = F_8 ( V_12 -> V_13 , NULL ) ;
return F_9 ( V_12 , & V_4 -> V_2 ) ;
}
