static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_1 =
F_3 ( V_5 ) ;
return F_5 ( V_1 -> V_6 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 = & V_1 -> V_5 ;
int V_7 ;
if ( ! V_3 -> V_8 ) {
F_7 ( L_1 ) ;
return - V_9 ;
}
F_8 ( V_5 ,
& V_10 ) ;
V_7 = F_9 ( V_3 -> V_11 , V_5 ,
& V_12 ,
V_1 -> V_13 ) ;
if ( V_7 ) {
F_7 ( L_2 ) ;
return V_7 ;
}
F_10 ( & V_1 -> V_5 ,
V_3 -> V_8 ) ;
V_7 = F_11 ( V_1 -> V_6 , & V_1 -> V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_13 ( V_1 -> V_6 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_15 ( V_1 -> V_6 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_17 ( V_1 -> V_6 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_19 ( V_1 -> V_6 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_21 ( V_1 -> V_6 ) ;
}
struct V_2 * F_22 ( struct V_14 * V_6 ,
T_1 V_13 )
{
struct V_1 * V_1 ;
int V_7 ;
if ( ! V_6 )
return F_23 ( - V_15 ) ;
V_1 = F_24 ( V_6 -> V_11 , sizeof( * V_1 ) ,
V_16 ) ;
if ( ! V_1 )
return F_23 ( - V_17 ) ;
V_1 -> V_13 = V_13 ;
V_1 -> V_6 = V_6 ;
V_1 -> V_3 . V_18 = & V_19 ;
#ifdef F_25
V_1 -> V_3 . V_20 = V_6 -> V_11 -> V_20 ;
#endif
V_7 = F_26 ( & V_1 -> V_3 ) ;
if ( V_7 )
return F_23 ( V_7 ) ;
return & V_1 -> V_3 ;
}
void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_28 ( V_3 ) ;
F_29 ( V_1 -> V_6 -> V_11 , V_3 ) ;
}
