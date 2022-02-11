static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 -> V_5 , 0x556c ) ;
F_3 ( & V_2 -> V_4 -> V_5 , 0xaa39 ) ;
F_4 ( & V_2 -> V_3 ) ;
}
static void F_5 ( unsigned long V_6 )
{
struct V_1 * V_2 = ( void * ) V_6 ;
F_1 ( V_2 ) ;
F_6 ( & V_2 -> V_7 , V_8 + V_9 * V_2 -> V_10 . V_11 / 2 ) ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_2 =
F_8 ( V_13 , struct V_1 , V_10 ) ;
T_1 V_14 = V_15 | V_16 ;
if ( V_17 )
V_14 |= V_18 ;
V_14 |= V_11 << 16 ;
F_9 ( & V_2 -> V_4 -> V_19 , V_14 ) ;
F_10 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 )
{
struct V_1 * V_2 =
F_8 ( V_13 , struct V_1 , V_10 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 )
{
struct V_1 * V_2 =
F_8 ( V_13 , struct V_1 , V_10 ) ;
F_6 ( & V_2 -> V_7 , V_8 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 )
{
int V_22 ;
struct V_23 * V_24 ;
const struct V_25 * V_26 ;
struct V_1 * V_2 ;
T_1 V_27 = F_14 () ;
bool V_28 ;
unsigned int V_29 ;
V_26 = F_15 ( & V_21 -> V_30 ) ;
if ( ! V_26 )
return - V_31 ;
if ( ! V_27 || V_27 == - 1 )
return - V_31 ;
V_2 = F_16 ( & V_21 -> V_30 , sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
V_24 = F_17 ( V_21 , V_34 , 0 ) ;
V_2 -> V_4 = F_18 ( & V_21 -> V_30 , V_24 ) ;
if ( F_19 ( V_2 -> V_4 ) )
return F_20 ( V_2 -> V_4 ) ;
V_28 = F_21 ( & V_2 -> V_4 -> V_19 ) & V_15 ;
if ( ! V_28 && V_26 -> V_35 ) {
F_22 ( L_1 ) ;
return - V_36 ;
}
F_23 ( & V_2 -> V_3 ) ;
F_24 ( & V_2 -> V_7 , F_5 ,
( unsigned long ) V_2 ) ;
V_2 -> V_10 . V_37 = & V_38 ,
V_2 -> V_10 . V_39 = & V_40 ,
V_29 = ( V_11 * V_26 -> V_41 ) / V_27 ;
V_2 -> V_10 . V_11 = V_29 ;
F_25 ( & V_2 -> V_10 , V_42 ) ;
V_22 = F_26 ( & V_2 -> V_10 ) ;
if ( V_22 ) {
F_27 ( L_2 , V_22 ) ;
return V_22 ;
}
F_22 ( L_3 ,
V_17 ? L_4 : L_5 , V_11 , V_29 ) ;
if ( V_28 )
F_6 ( & V_2 -> V_7 , V_8 ) ;
F_28 ( V_21 , V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_30 ( V_21 ) ;
F_31 ( L_6 ,
V_17 ? L_4 : L_7 ) ;
F_10 ( & V_2 -> V_7 ) ;
F_32 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_43 ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_43 ) ;
}
