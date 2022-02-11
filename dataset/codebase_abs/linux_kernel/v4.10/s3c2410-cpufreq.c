static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
if ( V_2 -> V_4 . V_5 == 2 )
V_3 |= V_6 ;
if ( V_2 -> V_4 . V_7 != V_2 -> V_4 . V_5 )
V_3 |= V_8 ;
F_2 ( V_3 , V_9 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned long V_10 , V_11 , V_12 ;
unsigned int V_13 , V_14 ;
unsigned long V_15 ;
V_11 = V_2 -> V_16 . V_11 ;
V_15 = V_2 -> V_17 . V_10 ;
V_2 -> V_16 . V_18 = V_11 ;
F_4 ( L_1 ,
V_19 , V_11 , V_15 ) ;
V_13 = ( V_11 > V_2 -> V_17 . V_10 ) ? 2 : 1 ;
V_10 = V_11 / V_13 ;
if ( V_10 > V_2 -> V_17 . V_10 ) {
F_4 ( L_2 , V_19 ) ;
return - V_20 ;
}
V_14 = ( V_10 > V_2 -> V_17 . V_12 ) ? 2 : 1 ;
V_12 = V_10 / V_14 ;
if ( V_12 > V_2 -> V_17 . V_12 ) {
F_4 ( L_3 , V_19 ) ;
return - V_20 ;
}
V_14 *= V_13 ;
V_2 -> V_4 . V_7 = V_14 ;
V_2 -> V_4 . V_5 = V_13 ;
return 0 ;
}
static int F_5 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
return F_6 ( & V_25 ) ;
}
static int T_2 F_7 ( void )
{
return F_8 ( & V_26 ) ;
}
static int F_9 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
V_25 . V_17 . V_11 = 266000000 ;
V_25 . V_17 . V_10 = 133000000 ;
V_25 . V_17 . V_12 = 66500000 ;
V_25 . V_27 = L_4 ;
return F_5 ( V_22 , V_24 ) ;
}
static int T_2 F_10 ( void )
{
return F_8 ( & V_28 ) ;
}
