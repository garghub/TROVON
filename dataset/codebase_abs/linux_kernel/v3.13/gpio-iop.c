static void F_1 ( int line , int V_1 )
{
unsigned long V_2 ;
T_1 V_3 ;
F_2 ( V_2 ) ;
V_3 = F_3 ( V_4 ) ;
if ( V_1 == V_5 ) {
V_3 |= F_4 ( line ) ;
} else if ( V_1 == V_6 ) {
V_3 &= ~ F_4 ( line ) ;
}
F_5 ( V_3 , V_4 ) ;
F_6 ( V_2 ) ;
}
static int F_7 ( int line )
{
return ! ! ( F_3 ( V_7 ) & F_4 ( line ) ) ;
}
static void F_8 ( int line , int V_8 )
{
unsigned long V_2 ;
T_1 V_3 ;
F_2 ( V_2 ) ;
V_3 = F_3 ( V_9 ) ;
if ( V_8 == V_10 ) {
V_3 &= ~ F_4 ( line ) ;
} else if ( V_8 == V_11 ) {
V_3 |= F_4 ( line ) ;
}
F_5 ( V_3 , V_9 ) ;
F_6 ( V_2 ) ;
}
static int F_9 ( struct V_12 * V_13 , unsigned V_14 )
{
F_1 ( V_14 , V_5 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 , unsigned V_14 , int V_15 )
{
F_8 ( V_14 , V_15 ) ;
F_1 ( V_14 , V_6 ) ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 , unsigned V_14 )
{
return F_7 ( V_14 ) ;
}
static void F_12 ( struct V_12 * V_13 , unsigned V_14 , int V_8 )
{
F_8 ( V_14 , V_8 ) ;
}
static int F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
V_19 = F_14 ( V_17 , V_20 , 0 ) ;
V_21 = F_15 ( & V_17 -> V_22 , V_19 ) ;
return F_16 ( & V_23 ) ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_24 ) ;
}
