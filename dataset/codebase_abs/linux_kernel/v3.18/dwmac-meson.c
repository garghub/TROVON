static void F_1 ( void * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = V_1 ;
unsigned int V_5 ;
V_5 = F_2 ( V_4 -> V_6 ) ;
switch ( V_2 ) {
case V_7 :
V_5 &= ~ V_8 ;
break;
case V_9 :
V_5 |= V_8 ;
break;
}
F_3 ( V_5 , V_4 -> V_6 ) ;
}
static void * F_4 ( struct V_10 * V_11 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
V_4 = F_5 ( & V_11 -> V_14 , sizeof( * V_4 ) , V_15 ) ;
if ( ! V_4 )
return F_6 ( - V_16 ) ;
V_13 = F_7 ( V_11 , V_17 , 1 ) ;
V_4 -> V_6 = F_8 ( & V_11 -> V_14 , V_13 ) ;
if ( F_9 ( V_4 -> V_6 ) )
return V_4 -> V_6 ;
return V_4 ;
}
