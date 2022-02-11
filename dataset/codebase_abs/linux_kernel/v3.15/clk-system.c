static inline int F_1 ( int V_1 )
{
return ( V_1 >= 8 ) && ( V_1 <= 15 ) ;
}
static T_1 F_2 ( int V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
F_3 ( & V_5 -> V_6 ) ;
F_4 ( V_5 -> V_2 ) ;
return V_7 ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = F_6 ( V_9 ) ;
struct V_10 * V_11 = V_5 -> V_11 ;
T_2 V_12 = 1 << V_5 -> V_1 ;
F_7 ( V_11 , V_13 , V_12 ) ;
if ( ! F_1 ( V_5 -> V_1 ) )
return 0 ;
while ( ! ( F_8 ( V_11 , V_14 ) & V_12 ) ) {
if ( V_5 -> V_2 ) {
F_9 ( V_5 -> V_2 ) ;
F_10 ( V_5 -> V_6 ,
F_8 ( V_11 , V_14 ) & V_12 ) ;
} else
F_11 () ;
}
return 0 ;
}
static void F_12 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = F_6 ( V_9 ) ;
struct V_10 * V_11 = V_5 -> V_11 ;
F_7 ( V_11 , V_15 , 1 << V_5 -> V_1 ) ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = F_6 ( V_9 ) ;
struct V_10 * V_11 = V_5 -> V_11 ;
if ( ! ( F_8 ( V_11 , V_16 ) & ( 1 << V_5 -> V_1 ) ) )
return 0 ;
if ( ! F_1 ( V_5 -> V_1 ) )
return 1 ;
return ! ! ( F_8 ( V_11 , V_14 ) & ( 1 << V_5 -> V_1 ) ) ;
}
static struct V_17 * T_3
F_14 ( struct V_10 * V_11 , const char * V_18 ,
const char * V_19 , T_4 V_1 , int V_2 )
{
struct V_4 * V_5 ;
struct V_17 * V_17 = NULL ;
struct V_20 V_21 ;
int V_22 ;
if ( ! V_19 || V_1 > V_23 )
return F_15 ( - V_24 ) ;
V_5 = F_16 ( sizeof( * V_5 ) , V_25 ) ;
if ( ! V_5 )
return F_15 ( - V_26 ) ;
V_21 . V_18 = V_18 ;
V_21 . V_27 = & V_28 ;
V_21 . V_29 = & V_19 ;
V_21 . V_30 = 1 ;
V_21 . V_31 = V_32 | V_33 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_9 . V_21 = & V_21 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_2 = V_2 ;
if ( V_2 ) {
F_17 ( & V_5 -> V_6 ) ;
F_18 ( V_5 -> V_2 , V_34 ) ;
V_22 = F_19 ( V_5 -> V_2 , F_2 ,
V_35 , V_18 , V_5 ) ;
if ( V_22 )
return F_15 ( V_22 ) ;
}
V_17 = F_20 ( NULL , & V_5 -> V_9 ) ;
if ( F_21 ( V_17 ) )
F_22 ( V_5 ) ;
return V_17 ;
}
static void T_3
F_23 ( struct V_36 * V_37 , struct V_10 * V_11 )
{
int V_38 ;
int V_2 = 0 ;
T_2 V_1 ;
struct V_17 * V_17 ;
const char * V_18 ;
struct V_36 * V_39 ;
const char * V_19 ;
V_38 = F_24 ( V_37 ) ;
if ( V_38 > ( V_23 + 1 ) )
return;
F_25 (np, sysclknp) {
if ( F_26 ( V_39 , L_1 , & V_1 ) )
continue;
if ( F_27 ( V_37 , L_2 , & V_18 ) )
V_18 = V_39 -> V_18 ;
if ( F_1 ( V_1 ) )
V_2 = F_28 ( V_39 , 0 ) ;
V_19 = F_29 ( V_39 , 0 ) ;
V_17 = F_14 ( V_11 , V_18 , V_19 , V_1 , V_2 ) ;
if ( F_21 ( V_17 ) )
continue;
F_30 ( V_39 , V_40 , V_17 ) ;
}
}
void T_3 F_31 ( struct V_36 * V_37 ,
struct V_10 * V_11 )
{
F_23 ( V_37 , V_11 ) ;
}
