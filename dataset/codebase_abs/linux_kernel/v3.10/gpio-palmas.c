static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
unsigned int V_8 ;
int V_9 ;
V_9 = F_4 ( V_7 , V_10 , V_11 , & V_8 ) ;
if ( V_9 < 0 ) {
F_5 ( V_4 -> V_12 , L_1 , V_9 ) ;
return V_9 ;
}
return ! ! ( V_8 & F_6 ( V_5 ) ) ;
}
static void F_7 ( struct V_2 * V_4 , unsigned V_5 ,
int V_13 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
int V_9 ;
if ( V_13 )
V_9 = F_8 ( V_7 , V_10 ,
V_14 , F_6 ( V_5 ) ) ;
else
V_9 = F_8 ( V_7 , V_10 ,
V_15 , F_6 ( V_5 ) ) ;
if ( V_9 < 0 )
F_5 ( V_4 -> V_12 , L_2 ,
( V_13 ) ? L_3 : L_4 ,
V_9 ) ;
}
static int F_9 ( struct V_2 * V_4 , unsigned V_5 ,
int V_13 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
int V_9 ;
F_7 ( V_4 , V_5 , V_13 ) ;
V_9 = F_10 ( V_7 , V_10 ,
V_16 , F_6 ( V_5 ) , F_6 ( V_5 ) ) ;
if ( V_9 < 0 )
F_5 ( V_4 -> V_12 , L_5 , V_9 ) ;
return V_9 ;
}
static int F_11 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
int V_9 ;
V_9 = F_10 ( V_7 , V_10 ,
V_16 , F_6 ( V_5 ) , 0 ) ;
if ( V_9 < 0 )
F_5 ( V_4 -> V_12 , L_5 , V_9 ) ;
return V_9 ;
}
static int F_12 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
return F_13 ( V_7 , V_17 + V_5 ) ;
}
static int F_14 ( struct V_18 * V_19 )
{
struct V_7 * V_7 = F_15 ( V_19 -> V_12 . V_20 ) ;
struct V_21 * V_22 ;
struct V_1 * V_1 ;
int V_9 ;
V_1 = F_16 ( & V_19 -> V_12 ,
sizeof( * V_1 ) , V_23 ) ;
if ( ! V_1 ) {
F_5 ( & V_19 -> V_12 , L_6 ) ;
return - V_24 ;
}
V_1 -> V_7 = V_7 ;
V_1 -> V_2 . V_25 = V_26 ;
V_1 -> V_2 . V_27 = F_17 ( & V_19 -> V_12 ) ;
V_1 -> V_2 . V_28 = 8 ;
V_1 -> V_2 . V_29 = 1 ;
V_1 -> V_2 . V_30 = F_11 ;
V_1 -> V_2 . V_31 = F_9 ;
V_1 -> V_2 . V_32 = F_12 ;
V_1 -> V_2 . V_33 = F_7 ;
V_1 -> V_2 . V_34 = F_3 ;
V_1 -> V_2 . V_12 = & V_19 -> V_12 ;
#ifdef F_18
V_1 -> V_2 . V_35 = V_7 -> V_12 -> V_35 ;
#endif
V_22 = F_19 ( V_7 -> V_12 ) ;
if ( V_22 && V_22 -> V_36 )
V_1 -> V_2 . V_37 = V_22 -> V_36 ;
else
V_1 -> V_2 . V_37 = - 1 ;
V_9 = F_20 ( & V_1 -> V_2 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_19 -> V_12 , L_7 , V_9 ) ;
return V_9 ;
}
F_21 ( V_19 , V_1 ) ;
return V_9 ;
}
static int F_22 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = F_23 ( V_19 ) ;
return F_24 ( & V_1 -> V_2 ) ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_38 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_38 ) ;
}
