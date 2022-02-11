static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
unsigned int V_7 ;
int V_8 ;
unsigned int V_9 ;
int V_10 = ( V_3 / 8 ) ;
V_3 %= 8 ;
V_9 = ( V_10 ) ? V_11 : V_12 ;
V_8 = F_3 ( V_6 , V_13 , V_9 , & V_7 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_14 , L_1 , V_9 , V_8 ) ;
return V_8 ;
}
if ( V_7 & F_5 ( V_3 ) )
V_9 = ( V_10 ) ? V_15 : V_16 ;
else
V_9 = ( V_10 ) ? V_17 : V_18 ;
V_8 = F_3 ( V_6 , V_13 , V_9 , & V_7 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_14 , L_1 , V_9 , V_8 ) ;
return V_8 ;
}
return ! ! ( V_7 & F_5 ( V_3 ) ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_3 ,
int V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_8 ;
unsigned int V_9 ;
int V_10 = ( V_3 / 8 ) ;
V_3 %= 8 ;
if ( V_10 )
V_9 = ( V_19 ) ?
V_20 : V_21 ;
else
V_9 = ( V_19 ) ?
V_22 : V_23 ;
V_8 = F_7 ( V_6 , V_13 , V_9 , F_5 ( V_3 ) ) ;
if ( V_8 < 0 )
F_4 ( V_2 -> V_14 , L_2 , V_9 , V_8 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_8 ;
unsigned int V_9 ;
int V_10 = ( V_3 / 8 ) ;
V_3 %= 8 ;
V_9 = ( V_10 ) ? V_11 : V_12 ;
F_6 ( V_2 , V_3 , V_19 ) ;
V_8 = F_9 ( V_6 , V_13 , V_9 ,
F_5 ( V_3 ) , F_5 ( V_3 ) ) ;
if ( V_8 < 0 )
F_4 ( V_2 -> V_14 , L_3 , V_9 ,
V_8 ) ;
return V_8 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_8 ;
unsigned int V_9 ;
int V_10 = ( V_3 / 8 ) ;
V_3 %= 8 ;
V_9 = ( V_10 ) ? V_11 : V_12 ;
V_8 = F_9 ( V_6 , V_13 , V_9 , F_5 ( V_3 ) , 0 ) ;
if ( V_8 < 0 )
F_4 ( V_2 -> V_14 , L_3 , V_9 ,
V_8 ) ;
return V_8 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
return F_12 ( V_6 , V_24 + V_3 ) ;
}
static int F_13 ( struct V_25 * V_26 )
{
struct V_6 * V_6 = F_14 ( V_26 -> V_27 . V_14 ) ;
struct V_28 * V_29 ;
struct V_4 * V_4 ;
int V_8 ;
const struct V_30 * V_31 ;
const struct V_32 * V_33 ;
V_31 = F_15 ( V_34 , & V_26 -> V_27 ) ;
if ( ! V_31 )
return - V_35 ;
V_33 = V_31 -> V_36 ;
if ( ! V_33 )
V_33 = & V_37 ;
V_4 = F_16 ( & V_26 -> V_27 ,
sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 )
return - V_39 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_1 . V_40 = V_41 ;
V_4 -> V_1 . V_42 = F_17 ( & V_26 -> V_27 ) ;
V_4 -> V_1 . V_43 = V_33 -> V_43 ;
V_4 -> V_1 . V_44 = true ;
V_4 -> V_1 . V_45 = F_10 ;
V_4 -> V_1 . V_46 = F_8 ;
V_4 -> V_1 . V_47 = F_11 ;
V_4 -> V_1 . V_48 = F_6 ;
V_4 -> V_1 . V_49 = F_1 ;
V_4 -> V_1 . V_14 = & V_26 -> V_27 ;
#ifdef F_18
V_4 -> V_1 . V_50 = V_26 -> V_27 . V_50 ;
#endif
V_29 = F_19 ( V_6 -> V_27 ) ;
if ( V_29 && V_29 -> V_51 )
V_4 -> V_1 . V_52 = V_29 -> V_51 ;
else
V_4 -> V_1 . V_52 = - 1 ;
V_8 = F_20 ( & V_26 -> V_27 , & V_4 -> V_1 ,
V_4 ) ;
if ( V_8 < 0 ) {
F_4 ( & V_26 -> V_27 , L_4 , V_8 ) ;
return V_8 ;
}
F_21 ( V_26 , V_4 ) ;
return V_8 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_53 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_53 ) ;
}
