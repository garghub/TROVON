int F_1 ( void T_1 * V_1 , struct V_2 * V_2 , int V_3 )
{
unsigned int V_4 = V_2 -> V_4 ;
T_2 V_5 ;
V_5 = F_2 ( V_1 ) ;
V_5 = V_3 ? ( V_5 | V_4 ) : ( V_5 & ~ V_4 ) ;
F_3 ( V_5 , V_1 ) ;
return 0 ;
}
int F_4 ( struct V_2 * V_2 , int V_3 )
{
unsigned int V_4 = V_2 -> V_4 ;
unsigned int V_6 = F_2 ( V_7 ) & ~ V_4 ;
if ( V_3 )
F_3 ( V_6 | V_4 , V_7 ) ;
else
F_3 ( V_6 , V_7 ) ;
return 0 ;
}
unsigned long F_5 ( struct V_2 * V_2 )
{
return V_2 -> V_8 ;
}
int F_6 ( struct V_2 * V_2 , unsigned long V_8 )
{
struct V_2 * V_9 ;
int V_10 ;
V_9 = F_7 ( V_2 ) ;
if ( F_8 ( V_9 ) )
return - V_11 ;
V_10 = V_9 -> V_12 -> V_13 ( V_9 , V_8 ) ;
F_9 ( V_9 ) ;
return V_10 ;
}
unsigned long F_10 ( struct V_2 * V_2 )
{
struct V_2 * V_9 ;
int V_8 ;
V_9 = F_7 ( V_2 ) ;
if ( F_8 ( V_9 ) )
return - V_11 ;
V_8 = V_9 -> V_12 -> V_14 ( V_9 ) ;
F_9 ( V_9 ) ;
return V_8 ;
}
void T_3 F_11 ( unsigned long V_15 )
{
int V_10 ;
V_16 . V_8 = V_15 ;
V_10 = F_12 ( V_17 , F_13 ( V_17 ) ) ;
if ( V_10 > 0 )
F_14 ( V_18 L_1 ) ;
}
