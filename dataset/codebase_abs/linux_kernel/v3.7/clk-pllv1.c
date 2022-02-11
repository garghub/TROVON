static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
long long V_6 ;
int V_7 ;
unsigned int V_8 , V_9 , V_10 , V_11 ;
T_1 V_12 ;
unsigned long V_13 ;
V_12 = F_3 ( V_5 -> V_14 ) ;
V_8 = ( V_12 >> 10 ) & 0xf ;
V_9 = V_12 & 0x3ff ;
V_10 = ( V_12 >> 16 ) & 0x3ff ;
V_11 = ( V_12 >> 26 ) & 0xf ;
V_8 = V_8 <= 5 ? 5 : V_8 ;
V_7 = V_9 ;
if ( ! F_4 () && ! F_5 () && V_9 >= 0x200 )
V_7 = 0x400 - V_9 ;
V_13 = V_3 * 2 ;
V_13 /= V_11 + 1 ;
V_6 = ( unsigned long long ) V_13 * V_7 ;
F_6 ( V_6 , V_10 + 1 ) ;
if ( ! F_4 () && ! F_5 () && V_9 >= 0x200 )
V_6 = - V_6 ;
V_6 = ( V_13 * V_8 ) + V_6 ;
return V_6 ;
}
struct V_15 * F_7 ( const char * V_16 , const char * V_17 ,
void T_2 * V_14 )
{
struct V_4 * V_5 ;
struct V_15 * V_15 ;
struct V_18 V_19 ;
V_5 = F_8 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 )
return F_9 ( - V_21 ) ;
V_5 -> V_14 = V_14 ;
V_19 . V_16 = V_16 ;
V_19 . V_22 = & V_23 ;
V_19 . V_24 = 0 ;
V_19 . V_25 = & V_17 ;
V_19 . V_26 = 1 ;
V_5 -> V_2 . V_19 = & V_19 ;
V_15 = F_10 ( NULL , & V_5 -> V_2 ) ;
if ( F_11 ( V_15 ) )
F_12 ( V_5 ) ;
return V_15 ;
}
