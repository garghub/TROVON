static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 & F_3 ( V_3 ) ? 1 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 ,
int V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_6 & F_3 ( V_3 ) )
return - V_8 ;
V_2 -> V_9 ( V_2 , V_3 , V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 & F_3 ( V_3 ) ? 0 : - V_8 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_3 , int V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_10 ;
T_1 V_11 , V_12 = F_3 ( V_3 ) ;
F_7 ( & V_5 -> V_13 , V_10 ) ;
V_11 = V_5 -> V_14 ;
if ( V_7 )
V_11 |= V_12 ;
else
V_11 &= ~ V_12 ;
V_5 -> V_14 = V_11 ;
F_8 ( V_11 , V_5 -> V_15 ) ;
F_9 ( & V_5 -> V_13 , V_10 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_11 , V_12 = F_3 ( V_3 ) ;
if ( V_5 -> V_6 & V_12 ) {
F_11 ( V_5 -> V_15 ) ;
V_11 = F_11 ( V_5 -> V_15 ) ;
} else {
V_11 = V_5 -> V_14 ;
}
return ! ! ( V_11 & V_12 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned long * V_12 ,
unsigned long * V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_10 ;
F_7 ( & V_5 -> V_13 , V_10 ) ;
V_5 -> V_14 = ( V_5 -> V_14 & ~ * V_12 ) | ( * V_16 & * V_12 ) ;
F_8 ( V_5 -> V_14 , V_5 -> V_15 ) ;
F_9 ( & V_5 -> V_13 , V_10 ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_17 = V_5 -> V_18 [ V_3 ] ;
if ( V_17 >= 0 && V_5 -> V_19 )
V_17 = F_14 ( V_5 -> V_19 , V_17 ) ;
return V_17 ;
}
struct V_1 * F_15 ( struct V_20 * V_21 , void T_2 * V_15 ,
int V_22 , int V_23 , const char * V_24 , T_1 V_6 , T_1 V_25 ,
const char * const * V_26 , struct V_27 * V_28 , const int * V_18 )
{
struct V_4 * V_5 ;
int V_29 ;
if ( V_21 )
V_5 = F_16 ( V_21 , sizeof( * V_5 ) , V_30 ) ;
else
V_5 = F_17 ( sizeof( * V_5 ) , V_30 ) ;
if ( ! V_5 )
return F_18 ( - V_31 ) ;
F_19 ( & V_5 -> V_13 ) ;
V_5 -> V_2 . V_24 = V_24 ;
V_5 -> V_2 . V_32 = F_1 ;
V_5 -> V_2 . V_33 = F_5 ;
V_5 -> V_2 . V_34 = F_4 ;
V_5 -> V_2 . V_9 = F_6 ;
V_5 -> V_2 . V_35 = F_10 ;
V_5 -> V_2 . V_36 = F_12 ;
if ( V_18 )
V_5 -> V_2 . V_37 = F_13 ;
V_5 -> V_2 . V_22 = V_22 ;
V_5 -> V_2 . V_38 = V_23 ;
V_5 -> V_2 . V_26 = V_26 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_14 = V_25 ;
V_5 -> V_15 = V_15 ;
V_5 -> V_18 = V_18 ;
if ( V_21 )
V_29 = F_20 ( V_21 , & V_5 -> V_2 , V_5 ) ;
else
V_29 = F_21 ( & V_5 -> V_2 , V_5 ) ;
return V_29 ? F_18 ( V_29 ) : & V_5 -> V_2 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_10 ;
F_7 ( & V_5 -> V_13 , V_10 ) ;
F_8 ( V_5 -> V_14 , V_5 -> V_15 ) ;
F_9 ( & V_5 -> V_13 , V_10 ) ;
return 0 ;
}
