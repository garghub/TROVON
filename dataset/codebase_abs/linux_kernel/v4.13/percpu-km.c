static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
return 0 ;
}
static void F_2 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
}
static struct V_1 * F_3 ( void )
{
const int V_5 = V_6 [ 0 ] >> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_10 ;
V_2 = F_4 () ;
if ( ! V_2 )
return NULL ;
V_9 = F_5 ( V_11 , F_6 ( V_5 ) ) ;
if ( ! V_9 ) {
F_7 ( V_2 ) ;
return NULL ;
}
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ )
F_8 ( F_9 ( V_9 , V_10 ) , V_2 ) ;
V_2 -> V_12 = V_9 ;
V_2 -> V_13 = F_10 ( V_9 ) - V_14 [ 0 ] ;
F_11 ( & V_15 ) ;
F_12 ( V_2 , 0 , V_5 ) ;
F_13 ( & V_15 ) ;
F_14 () ;
F_15 ( V_2 -> V_13 ) ;
return V_2 ;
}
static void F_16 ( struct V_1 * V_2 )
{
const int V_5 = V_6 [ 0 ] >> V_7 ;
if ( ! V_2 )
return;
F_17 () ;
F_18 ( V_2 -> V_13 ) ;
if ( V_2 -> V_12 )
F_19 ( V_2 -> V_12 , F_6 ( V_5 ) ) ;
F_7 ( V_2 ) ;
}
static struct V_8 * F_20 ( void * V_16 )
{
return F_21 ( V_16 ) ;
}
static int T_1 F_22 ( const struct V_17 * V_18 )
{
T_2 V_5 , F_5 ;
if ( V_18 -> V_19 != 1 ) {
F_23 ( L_1 ) ;
return - V_20 ;
}
V_5 = ( V_18 -> V_21 [ 0 ] . V_22 * V_18 -> V_23 ) >> V_7 ;
F_5 = F_24 ( V_5 ) ;
if ( F_5 > V_5 )
F_25 ( L_2 ,
F_5 - V_5 ) ;
return 0 ;
}
