static unsigned int F_1 ( const struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 ;
return V_3 * V_5 ;
}
bool F_2 ( const struct V_6 * V_7 , T_1 V_8 )
{
struct V_1 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 )
return false ;
return V_8 < F_1 ( V_9 ) && F_4 ( V_8 , V_9 -> V_10 ) ;
}
int F_5 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_1 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 || V_8 >= F_1 ( V_9 ) )
return - V_11 ;
if ( F_4 ( V_8 , V_9 -> V_10 ) )
return 0 ;
if ( F_6 ( V_8 , V_9 -> V_10 ) )
F_7 ( V_12 , V_7 ) ;
return 0 ;
}
static void F_8 ( T_2 * V_13 , T_2 V_14 , T_2 V_15 )
{
T_2 V_16 , V_17 ;
do {
V_16 = * V_13 ;
V_17 = ( V_16 & V_14 ) ^ V_15 ;
} while ( F_9 ( V_13 , V_16 , V_17 ) != V_16 );
}
int F_10 ( struct V_6 * V_7 ,
const T_2 * V_18 ,
const T_2 * V_14 , unsigned int V_19 )
{
struct V_1 * V_9 ;
unsigned int V_20 , V_21 ;
T_2 * V_22 ;
V_9 = F_3 ( V_7 ) ;
if ( ! V_9 )
return - V_11 ;
V_20 = V_9 -> V_4 * sizeof( long ) ;
if ( V_20 < ( V_19 * sizeof( T_2 ) ) )
V_19 = V_20 / sizeof( T_2 ) ;
V_22 = ( T_2 * ) V_9 -> V_10 ;
if ( V_19 ) {
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ )
F_8 ( & V_22 [ V_21 ] , V_14 ? ~ V_14 [ V_21 ] : 0 , V_18 [ V_21 ] ) ;
}
V_20 /= sizeof( T_2 ) ;
for ( V_21 = V_19 ; V_21 < V_20 ; V_21 ++ )
F_8 ( & V_22 [ V_21 ] , 0 , 0 ) ;
F_7 ( V_12 , V_7 ) ;
return 0 ;
}
int F_11 ( void )
{
return F_12 ( & V_23 ) ;
}
void F_13 ( void )
{
F_14 ( & V_23 ) ;
}
