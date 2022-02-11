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
static int F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_14 V_15 ;
struct V_3 * V_4 ;
struct V_16 * V_17 ;
int V_18 ;
V_18 = F_5 ( V_11 , & V_15 ) ;
if ( V_18 )
return V_18 ;
V_13 = F_6 ( V_11 , & V_15 . V_19 ) ;
if ( F_7 ( V_13 ) )
return F_8 ( V_13 ) ;
V_4 = F_9 ( & V_11 -> V_20 , sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 )
return - V_22 ;
V_17 = F_10 ( V_11 , V_23 , 1 ) ;
V_4 -> V_6 = F_11 ( & V_11 -> V_20 , V_17 ) ;
if ( F_7 ( V_4 -> V_6 ) )
return F_8 ( V_4 -> V_6 ) ;
V_13 -> V_24 = V_4 ;
V_13 -> V_25 = F_1 ;
return F_12 ( & V_11 -> V_20 , V_13 , & V_15 ) ;
}
