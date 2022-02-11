static int F_1 ( void T_1 * V_1 , T_2 V_2 )
{
unsigned long V_3 = V_4 + F_2 ( 10 ) ;
while ( F_3 ( V_1 ) & ( 1 << V_2 ) )
if ( F_4 ( V_4 , V_3 ) )
return - V_5 ;
return 0 ;
}
static inline struct V_6 * F_5 ( struct V_7 * V_8 )
{
struct V_9 * div = F_6 ( V_8 , struct V_9 , V_8 ) ;
return F_6 ( div , struct V_6 , div ) ;
}
static unsigned long F_7 ( struct V_7 * V_8 ,
unsigned long V_10 )
{
struct V_6 * V_11 = F_5 ( V_8 ) ;
return V_11 -> V_12 -> V_13 ( & V_11 -> div . V_8 , V_10 ) ;
}
static long F_8 ( struct V_7 * V_8 , unsigned long V_14 ,
unsigned long * V_15 )
{
struct V_6 * V_11 = F_5 ( V_8 ) ;
return V_11 -> V_12 -> V_16 ( & V_11 -> div . V_8 , V_14 , V_15 ) ;
}
static int F_9 ( struct V_7 * V_8 , unsigned long V_14 ,
unsigned long V_10 )
{
struct V_6 * V_11 = F_5 ( V_8 ) ;
int V_17 ;
V_17 = V_11 -> V_12 -> V_18 ( & V_11 -> div . V_8 , V_14 , V_10 ) ;
if ( ! V_17 )
V_17 = F_1 ( V_11 -> V_1 , V_11 -> V_2 ) ;
return V_17 ;
}
struct V_19 * F_10 ( const char * V_20 , const char * V_21 ,
void T_1 * V_1 , T_2 V_2 , T_2 V_22 ,
void T_1 * V_23 , T_2 V_24 )
{
struct V_6 * V_11 ;
struct V_19 * V_19 ;
struct V_25 V_26 ;
V_11 = F_11 ( sizeof( * V_11 ) , V_27 ) ;
if ( ! V_11 )
return F_12 ( - V_28 ) ;
V_11 -> V_1 = V_23 ;
V_11 -> V_2 = V_24 ;
V_11 -> div . V_1 = V_1 ;
V_11 -> div . V_2 = V_2 ;
V_11 -> div . V_22 = V_22 ;
V_11 -> div . V_29 = & V_30 ;
V_11 -> V_12 = & V_31 ;
V_26 . V_20 = V_20 ;
V_26 . V_32 = & V_33 ;
V_26 . V_34 = V_35 ;
V_26 . V_36 = & V_21 ;
V_26 . V_37 = 1 ;
V_11 -> div . V_8 . V_26 = & V_26 ;
V_19 = F_13 ( NULL , & V_11 -> div . V_8 ) ;
if ( F_14 ( V_19 ) )
F_15 ( V_11 ) ;
return V_19 ;
}
static inline struct V_38 * F_16 ( struct V_7 * V_8 )
{
struct V_39 * V_40 = F_6 ( V_8 , struct V_39 , V_8 ) ;
return F_6 ( V_40 , struct V_38 , V_40 ) ;
}
static T_2 F_17 ( struct V_7 * V_8 )
{
struct V_38 * V_11 = F_16 ( V_8 ) ;
return V_11 -> V_41 -> V_42 ( & V_11 -> V_40 . V_8 ) ;
}
static int F_18 ( struct V_7 * V_8 , T_2 V_43 )
{
struct V_38 * V_11 = F_16 ( V_8 ) ;
int V_17 ;
V_17 = V_11 -> V_41 -> V_44 ( & V_11 -> V_40 . V_8 , V_43 ) ;
if ( ! V_17 )
V_17 = F_1 ( V_11 -> V_1 , V_11 -> V_2 ) ;
return V_17 ;
}
struct V_19 * F_19 ( const char * V_20 , void T_1 * V_1 , T_2 V_2 ,
T_2 V_22 , void T_1 * V_23 , T_2 V_24 ,
const char * * V_36 , int V_37 )
{
struct V_38 * V_11 ;
struct V_19 * V_19 ;
struct V_25 V_26 ;
V_11 = F_11 ( sizeof( * V_11 ) , V_27 ) ;
if ( ! V_11 )
return F_12 ( - V_28 ) ;
V_11 -> V_1 = V_23 ;
V_11 -> V_2 = V_24 ;
V_11 -> V_40 . V_1 = V_1 ;
V_11 -> V_40 . V_2 = V_2 ;
V_11 -> V_40 . V_45 = F_20 ( V_22 ) - 1 ;
V_11 -> V_40 . V_29 = & V_30 ;
V_11 -> V_41 = & V_46 ;
V_26 . V_20 = V_20 ;
V_26 . V_32 = & V_47 ;
V_26 . V_34 = 0 ;
V_26 . V_36 = V_36 ;
V_26 . V_37 = V_37 ;
V_11 -> V_40 . V_8 . V_26 = & V_26 ;
V_19 = F_13 ( NULL , & V_11 -> V_40 . V_8 ) ;
if ( F_14 ( V_19 ) )
F_15 ( V_11 ) ;
return V_19 ;
}
