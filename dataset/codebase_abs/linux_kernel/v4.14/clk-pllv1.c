static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> type == V_3 ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return V_2 -> type == V_4 ;
}
static inline bool F_3 ( struct V_1 * V_2 )
{
return V_2 -> type == V_5 ;
}
static inline bool F_4 ( struct V_1 * V_2 , unsigned int V_6 )
{
return ! F_1 ( V_2 ) && ! F_2 ( V_2 ) && ( V_6 & V_7 ) ;
}
static unsigned long F_5 ( struct V_8 * V_9 ,
unsigned long V_10 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned long long V_11 ;
int V_12 ;
unsigned int V_13 , V_6 , V_14 , V_15 ;
T_1 V_16 ;
unsigned long V_17 ;
V_16 = F_7 ( V_2 -> V_18 ) ;
V_13 = ( V_16 >> 10 ) & 0xf ;
V_6 = V_16 & 0x3ff ;
V_14 = ( V_16 >> 16 ) & 0x3ff ;
V_15 = ( V_16 >> 26 ) & 0xf ;
V_13 = V_13 <= 5 ? 5 : V_13 ;
V_12 = V_6 ;
if ( F_4 ( V_2 , V_6 ) ) {
if ( F_3 ( V_2 ) )
V_12 = V_6 & V_19 ;
else
V_12 = F_8 ( V_20 ) - V_6 ;
}
V_17 = V_10 * 2 ;
V_17 /= V_15 + 1 ;
V_11 = ( unsigned long long ) V_17 * V_12 ;
F_9 ( V_11 , V_14 + 1 ) ;
if ( F_4 ( V_2 , V_6 ) )
V_11 = ( V_17 * V_13 ) - V_11 ;
else
V_11 = ( V_17 * V_13 ) + V_11 ;
return V_11 ;
}
struct V_21 * F_10 ( enum V_22 type , const char * V_23 ,
const char * V_24 , void T_2 * V_18 )
{
struct V_1 * V_2 ;
struct V_21 * V_21 ;
struct V_25 V_26 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return F_12 ( - V_28 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> type = type ;
V_26 . V_23 = V_23 ;
V_26 . V_29 = & V_30 ;
V_26 . V_31 = 0 ;
V_26 . V_32 = & V_24 ;
V_26 . V_33 = 1 ;
V_2 -> V_9 . V_26 = & V_26 ;
V_21 = F_13 ( NULL , & V_2 -> V_9 ) ;
if ( F_14 ( V_21 ) )
F_15 ( V_2 ) ;
return V_21 ;
}
