static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
unsigned int V_5 ;
F_2 (cpu)
memset ( ( void * ) F_3 ( V_2 , V_5 , 0 ) + V_3 , 0 , V_4 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
}
static struct V_1 * F_5 ( void )
{
const int V_6 = V_7 [ 0 ] >> V_8 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_11 ;
V_2 = F_6 () ;
if ( ! V_2 )
return NULL ;
V_10 = F_7 ( V_12 , F_8 ( V_6 ) ) ;
if ( ! V_10 ) {
F_9 ( V_2 ) ;
return NULL ;
}
for ( V_11 = 0 ; V_11 < V_6 ; V_11 ++ )
F_10 ( F_11 ( V_10 , V_11 ) , V_2 ) ;
V_2 -> V_13 = V_10 ;
V_2 -> V_14 = F_12 ( V_10 ) - V_15 [ 0 ] ;
return V_2 ;
}
static void F_13 ( struct V_1 * V_2 )
{
const int V_6 = V_7 [ 0 ] >> V_8 ;
if ( V_2 && V_2 -> V_13 )
F_14 ( V_2 -> V_13 , F_8 ( V_6 ) ) ;
F_9 ( V_2 ) ;
}
static struct V_9 * F_15 ( void * V_16 )
{
return F_16 ( V_16 ) ;
}
static int T_1 F_17 ( const struct V_17 * V_18 )
{
T_2 V_6 , F_7 ;
if ( V_18 -> V_19 != 1 ) {
F_18 ( V_20 L_1 ) ;
return - V_21 ;
}
V_6 = ( V_18 -> V_22 [ 0 ] . V_23 * V_18 -> V_24 ) >> V_8 ;
F_7 = F_19 ( V_6 ) ;
if ( F_7 > V_6 )
F_18 ( V_25 L_2 ,
F_7 - V_6 ) ;
return 0 ;
}
