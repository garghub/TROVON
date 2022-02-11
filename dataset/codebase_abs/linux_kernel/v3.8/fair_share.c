static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
unsigned long V_4 ;
if ( V_2 -> V_5 == 0 || ! V_2 -> V_6 -> V_7 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_2 -> V_6 -> V_7 ( V_2 , V_3 , & V_4 ) ;
if ( V_2 -> V_8 < V_4 )
break;
}
return V_3 ;
}
static long F_2 ( struct V_1 * V_2 ,
struct V_9 * V_10 , int V_11 , int V_12 )
{
unsigned long V_13 ;
V_10 -> V_6 -> V_14 ( V_10 , & V_13 ) ;
return ( long ) ( V_11 * V_12 * V_13 ) / ( 100 * V_2 -> V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_15 )
{
const struct V_16 * V_17 ;
struct V_9 * V_10 ;
struct V_18 * V_19 ;
int V_20 ;
int V_21 = F_1 ( V_2 ) ;
if ( ! V_2 -> V_17 || ! V_2 -> V_17 -> V_22 )
return - V_23 ;
V_17 = V_2 -> V_17 ;
for ( V_20 = 0 ; V_20 < V_17 -> V_24 ; V_20 ++ ) {
if ( ! V_17 -> V_22 [ V_20 ] . V_10 )
continue;
V_10 = V_17 -> V_22 [ V_20 ] . V_10 ;
V_19 = F_4 ( V_2 , V_10 , V_15 ) ;
if ( ! V_19 )
continue;
V_19 -> V_25 = F_2 ( V_2 , V_10 ,
V_17 -> V_22 [ V_20 ] . V_11 , V_21 ) ;
V_19 -> V_10 -> V_26 = false ;
F_5 ( V_10 ) ;
}
return 0 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_27 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_27 ) ;
}
