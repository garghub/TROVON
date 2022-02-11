static inline int F_1 ( int V_1 )
{
return ( V_1 >= 8 ) && ( V_1 <= 15 ) ;
}
static inline bool F_2 ( struct V_2 * V_2 , int V_1 )
{
unsigned int V_3 ;
F_3 ( V_2 , V_4 , & V_3 ) ;
return V_3 & ( 1 << V_1 ) ? 1 : 0 ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_5 ( V_6 ) ;
F_6 ( V_8 -> V_2 , V_9 , 1 << V_8 -> V_1 ) ;
if ( ! F_1 ( V_8 -> V_1 ) )
return 0 ;
while ( ! F_2 ( V_8 -> V_2 , V_8 -> V_1 ) )
F_7 () ;
return 0 ;
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_5 ( V_6 ) ;
F_6 ( V_8 -> V_2 , V_10 , 1 << V_8 -> V_1 ) ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_5 ( V_6 ) ;
unsigned int V_3 ;
F_3 ( V_8 -> V_2 , V_11 , & V_3 ) ;
if ( ! ( V_3 & ( 1 << V_8 -> V_1 ) ) )
return 0 ;
if ( ! F_1 ( V_8 -> V_1 ) )
return 1 ;
F_3 ( V_8 -> V_2 , V_4 , & V_3 ) ;
return V_3 & ( 1 << V_8 -> V_1 ) ? 1 : 0 ;
}
static struct V_12 * T_1
F_10 ( struct V_2 * V_2 , const char * V_13 ,
const char * V_14 , T_2 V_1 )
{
struct V_7 * V_8 ;
struct V_12 * V_12 = NULL ;
struct V_15 V_16 ;
if ( ! V_14 || V_1 > V_17 )
return F_11 ( - V_18 ) ;
V_8 = F_12 ( sizeof( * V_8 ) , V_19 ) ;
if ( ! V_8 )
return F_11 ( - V_20 ) ;
V_16 . V_13 = V_13 ;
V_16 . V_21 = & V_22 ;
V_16 . V_23 = & V_14 ;
V_16 . V_24 = 1 ;
V_16 . V_25 = V_26 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_6 . V_16 = & V_16 ;
V_8 -> V_2 = V_2 ;
V_12 = F_13 ( NULL , & V_8 -> V_6 ) ;
if ( F_14 ( V_12 ) )
F_15 ( V_8 ) ;
return V_12 ;
}
static void T_1 F_16 ( struct V_27 * V_28 )
{
int V_29 ;
T_3 V_1 ;
struct V_12 * V_12 ;
const char * V_13 ;
struct V_27 * V_30 ;
const char * V_14 ;
struct V_2 * V_2 ;
V_29 = F_17 ( V_28 ) ;
if ( V_29 > ( V_17 + 1 ) )
return;
V_2 = F_18 ( F_19 ( V_28 ) ) ;
if ( F_14 ( V_2 ) )
return;
F_20 (np, sysclknp) {
if ( F_21 ( V_30 , L_1 , & V_1 ) )
continue;
if ( F_22 ( V_28 , L_2 , & V_13 ) )
V_13 = V_30 -> V_13 ;
V_14 = F_23 ( V_30 , 0 ) ;
V_12 = F_10 ( V_2 , V_13 , V_14 , V_1 ) ;
if ( F_14 ( V_12 ) )
continue;
F_24 ( V_30 , V_31 , V_12 ) ;
}
}
