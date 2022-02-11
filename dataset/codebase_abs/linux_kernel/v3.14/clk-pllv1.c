static inline bool F_1 ( unsigned int V_1 )
{
return ! F_2 () && ! F_3 () && ( V_1 & V_2 ) ;
}
static unsigned long F_4 ( struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_6 * V_7 = F_5 ( V_4 ) ;
long long V_8 ;
int V_9 ;
unsigned int V_10 , V_1 , V_11 , V_12 ;
T_1 V_13 ;
unsigned long V_14 ;
V_13 = F_6 ( V_7 -> V_15 ) ;
V_10 = ( V_13 >> 10 ) & 0xf ;
V_1 = V_13 & 0x3ff ;
V_11 = ( V_13 >> 16 ) & 0x3ff ;
V_12 = ( V_13 >> 26 ) & 0xf ;
V_10 = V_10 <= 5 ? 5 : V_10 ;
V_9 = V_1 ;
if ( F_1 ( V_1 ) ) {
if ( F_7 () )
V_9 = V_1 & V_16 ;
else
V_9 = F_8 ( V_17 ) - V_1 ;
}
V_14 = V_5 * 2 ;
V_14 /= V_12 + 1 ;
V_8 = ( unsigned long long ) V_14 * V_9 ;
F_9 ( V_8 , V_11 + 1 ) ;
if ( F_1 ( V_1 ) )
V_8 = - V_8 ;
V_8 = ( V_14 * V_10 ) + V_8 ;
return V_8 ;
}
struct V_18 * F_10 ( const char * V_19 , const char * V_20 ,
void T_2 * V_15 )
{
struct V_6 * V_7 ;
struct V_18 * V_18 ;
struct V_21 V_22 ;
V_7 = F_11 ( sizeof( * V_7 ) , V_23 ) ;
if ( ! V_7 )
return F_12 ( - V_24 ) ;
V_7 -> V_15 = V_15 ;
V_22 . V_19 = V_19 ;
V_22 . V_25 = & V_26 ;
V_22 . V_27 = 0 ;
V_22 . V_28 = & V_20 ;
V_22 . V_29 = 1 ;
V_7 -> V_4 . V_22 = & V_22 ;
V_18 = F_13 ( NULL , & V_7 -> V_4 ) ;
if ( F_14 ( V_18 ) )
F_15 ( V_7 ) ;
return V_18 ;
}
