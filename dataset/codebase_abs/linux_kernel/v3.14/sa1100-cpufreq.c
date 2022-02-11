static void F_1 ( int V_1 , int V_2 )
{
struct V_3 * V_4 = V_5 ;
while ( V_4 -> V_6 != 0 ) {
if ( V_2 == V_4 -> V_6 )
break;
V_4 ++ ;
}
if ( V_4 -> V_6 == 0 ) {
F_2 ( L_1 ,
V_7 , V_2 ) ;
}
if ( V_2 > V_1 ) {
V_8 |= V_9 ;
V_10 = V_4 -> V_11 ;
V_12 = V_4 -> V_13 ;
V_14 = V_4 -> V_15 ;
V_8 = V_4 -> V_16 ;
} else {
V_8 |= V_9 ;
V_14 = V_4 -> V_15 ;
V_12 = V_4 -> V_13 ;
V_10 = V_4 -> V_11 ;
V_8 = V_4 -> V_16 ;
}
}
static int F_3 ( struct V_17 * V_18 , unsigned int V_19 )
{
unsigned int V_20 = F_4 ( 0 ) ;
unsigned int V_21 ;
V_21 = V_22 [ V_19 ] . V_23 ;
if ( V_21 > V_20 )
F_1 ( V_20 , V_21 ) ;
V_24 = V_19 ;
if ( V_21 < V_20 )
F_1 ( V_20 , V_21 ) ;
return 0 ;
}
static int T_1 F_5 ( struct V_17 * V_18 )
{
return F_6 ( V_18 , V_22 , V_25 ) ;
}
static int T_1 F_7 ( void )
{
if ( F_8 () )
return F_9 ( & V_26 ) ;
else
return - V_27 ;
}
