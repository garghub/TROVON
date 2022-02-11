static int F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
struct V_5 T_1 * V_6 ;
T_2 V_7 ;
T_3 V_8 ;
V_6 = F_2 ( sizeof( * V_6 ) ) ;
if ( F_3 ( V_6 , V_4 , 4 + 64 ) )
return - V_9 ;
if ( F_4 ( V_7 , & V_4 -> V_10 ) ||
F_5 ( F_6 ( V_7 ) , & V_6 -> V_10 ) )
return - V_9 ;
if ( F_4 ( V_8 , & V_4 -> V_11 ) ||
F_5 ( V_8 , & V_6 -> V_11 ) )
return - V_9 ;
if ( F_4 ( V_8 , & V_4 -> V_12 ) ||
F_5 ( V_8 , & V_6 -> V_12 ) )
return - V_9 ;
return F_7 ( V_2 , V_6 ) ;
}
static long F_8 ( struct V_13 * V_13 , unsigned int V_14 ,
unsigned long V_15 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
void T_1 * V_17 = F_6 ( V_15 ) ;
switch ( V_14 ) {
case V_18 :
case V_19 :
case V_20 :
return F_9 ( V_13 , V_14 , ( unsigned long ) V_17 ) ;
case V_21 :
return F_1 ( V_2 , V_17 ) ;
}
if ( V_2 -> V_22 . V_23 )
return V_2 -> V_22 . V_23 ( V_2 , V_13 , V_14 , V_15 ) ;
return - V_24 ;
}
