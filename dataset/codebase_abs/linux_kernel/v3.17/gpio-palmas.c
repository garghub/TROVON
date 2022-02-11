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
unsigned int V_10 ;
int V_11 = ( V_5 / 8 ) ;
V_5 %= 8 ;
V_10 = ( V_11 ) ? V_12 : V_13 ;
V_9 = F_4 ( V_7 , V_14 , V_10 , & V_8 ) ;
if ( V_9 < 0 ) {
F_5 ( V_4 -> V_15 , L_1 , V_10 , V_9 ) ;
return V_9 ;
}
if ( V_8 & F_6 ( V_5 ) )
V_10 = ( V_11 ) ? V_16 : V_17 ;
else
V_10 = ( V_11 ) ? V_18 : V_19 ;
V_9 = F_4 ( V_7 , V_14 , V_10 , & V_8 ) ;
if ( V_9 < 0 ) {
F_5 ( V_4 -> V_15 , L_1 , V_10 , V_9 ) ;
return V_9 ;
}
return ! ! ( V_8 & F_6 ( V_5 ) ) ;
}
static void F_7 ( struct V_2 * V_4 , unsigned V_5 ,
int V_20 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
int V_9 ;
unsigned int V_10 ;
int V_11 = ( V_5 / 8 ) ;
V_5 %= 8 ;
if ( V_11 )
V_10 = ( V_20 ) ?
V_21 : V_22 ;
else
V_10 = ( V_20 ) ?
V_23 : V_24 ;
V_9 = F_8 ( V_7 , V_14 , V_10 , F_6 ( V_5 ) ) ;
if ( V_9 < 0 )
F_5 ( V_4 -> V_15 , L_2 , V_10 , V_9 ) ;
}
static int F_9 ( struct V_2 * V_4 , unsigned V_5 ,
int V_20 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
int V_9 ;
unsigned int V_10 ;
int V_11 = ( V_5 / 8 ) ;
V_5 %= 8 ;
V_10 = ( V_11 ) ? V_12 : V_13 ;
F_7 ( V_4 , V_5 , V_20 ) ;
V_9 = F_10 ( V_7 , V_14 , V_10 ,
F_6 ( V_5 ) , F_6 ( V_5 ) ) ;
if ( V_9 < 0 )
F_5 ( V_4 -> V_15 , L_3 , V_10 , V_9 ) ;
return V_9 ;
}
static int F_11 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
int V_9 ;
unsigned int V_10 ;
int V_11 = ( V_5 / 8 ) ;
V_5 %= 8 ;
V_10 = ( V_11 ) ? V_12 : V_13 ;
V_9 = F_10 ( V_7 , V_14 , V_10 , F_6 ( V_5 ) , 0 ) ;
if ( V_9 < 0 )
F_5 ( V_4 -> V_15 , L_3 , V_10 , V_9 ) ;
return V_9 ;
}
static int F_12 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
return F_13 ( V_7 , V_25 + V_5 ) ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_7 * V_7 = F_15 ( V_27 -> V_15 . V_28 ) ;
struct V_29 * V_30 ;
struct V_1 * V_1 ;
int V_9 ;
const struct V_31 * V_32 ;
const struct V_33 * V_34 ;
V_32 = F_16 ( V_35 , & V_27 -> V_15 ) ;
V_34 = V_32 -> V_36 ;
if ( ! V_34 )
V_34 = & V_37 ;
V_1 = F_17 ( & V_27 -> V_15 ,
sizeof( * V_1 ) , V_38 ) ;
if ( ! V_1 )
return - V_39 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_2 . V_40 = V_41 ;
V_1 -> V_2 . V_42 = F_18 ( & V_27 -> V_15 ) ;
V_1 -> V_2 . V_43 = V_34 -> V_43 ;
V_1 -> V_2 . V_44 = true ;
V_1 -> V_2 . V_45 = F_11 ;
V_1 -> V_2 . V_46 = F_9 ;
V_1 -> V_2 . V_47 = F_12 ;
V_1 -> V_2 . V_48 = F_7 ;
V_1 -> V_2 . V_49 = F_3 ;
V_1 -> V_2 . V_15 = & V_27 -> V_15 ;
#ifdef F_19
V_1 -> V_2 . V_50 = V_27 -> V_15 . V_50 ;
#endif
V_30 = F_20 ( V_7 -> V_15 ) ;
if ( V_30 && V_30 -> V_51 )
V_1 -> V_2 . V_52 = V_30 -> V_51 ;
else
V_1 -> V_2 . V_52 = - 1 ;
V_9 = F_21 ( & V_1 -> V_2 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_27 -> V_15 , L_4 , V_9 ) ;
return V_9 ;
}
F_22 ( V_27 , V_1 ) ;
return V_9 ;
}
static int F_23 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = F_24 ( V_27 ) ;
F_25 ( & V_1 -> V_2 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
return F_27 ( & V_53 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_53 ) ;
}
