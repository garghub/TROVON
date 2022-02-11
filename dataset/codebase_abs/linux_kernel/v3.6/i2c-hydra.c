static inline void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
F_2 ( V_2 , & V_4 -> V_5 ) ;
}
static inline T_1 F_3 ( void * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
return F_4 ( & V_4 -> V_5 ) ;
}
static void F_5 ( void * V_1 , int V_6 )
{
T_1 V_2 = F_3 ( V_1 ) ;
if ( V_6 )
V_2 &= ~ V_7 ;
else {
V_2 &= ~ V_8 ;
V_2 |= V_7 ;
}
F_1 ( V_1 , V_2 ) ;
}
static void F_6 ( void * V_1 , int V_6 )
{
T_1 V_2 = F_3 ( V_1 ) ;
if ( V_6 )
V_2 &= ~ V_9 ;
else {
V_2 &= ~ V_10 ;
V_2 |= V_9 ;
}
F_1 ( V_1 , V_2 ) ;
}
static int F_7 ( void * V_1 )
{
return ( F_3 ( V_1 ) & V_8 ) != 0 ;
}
static int F_8 ( void * V_1 )
{
return ( F_3 ( V_1 ) & V_10 ) != 0 ;
}
static int T_2 F_9 ( struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
unsigned long V_15 = F_10 ( V_12 , 0 ) ;
int V_16 ;
if ( ! F_11 ( V_15 + F_12 ( struct V_3 , V_5 ) , 4 ,
V_17 . V_18 ) )
return - V_19 ;
V_20 . V_1 = F_13 ( V_12 , 0 ) ;
if ( V_20 . V_1 == NULL ) {
F_14 ( V_15 + F_12 ( struct V_3 , V_5 ) , 4 ) ;
return - V_21 ;
}
F_1 ( V_20 . V_1 , 0 ) ;
V_17 . V_12 . V_22 = & V_12 -> V_12 ;
V_16 = F_15 ( & V_17 ) ;
if ( V_16 < 0 ) {
F_16 ( V_20 . V_1 ) ;
F_14 ( V_15 + F_12 ( struct V_3 , V_5 ) , 4 ) ;
return V_16 ;
}
return 0 ;
}
static void T_3 F_17 ( struct V_11 * V_12 )
{
F_1 ( V_20 . V_1 , 0 ) ;
F_18 ( & V_17 ) ;
F_16 ( V_20 . V_1 ) ;
F_14 ( F_10 ( V_12 , 0 ) +
F_12 ( struct V_3 , V_5 ) , 4 ) ;
}
