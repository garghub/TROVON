static inline unsigned int F_1 ( const T_1 * V_1 , unsigned int V_2 )
{
if ( V_1 [ V_2 ] <= V_3 || V_1 [ V_2 + 1 ] == 0 )
return 1 ;
else
return V_1 [ V_2 + 1 ] ;
}
static unsigned int
F_2 ( struct V_4 * V_5 ,
const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int V_9 )
{
unsigned int V_10 , V_11 , V_12 ;
struct V_13 * V_14 ;
T_2 V_15 , V_16 ;
T_1 * V_1 ;
if ( ! F_3 ( V_5 , V_5 -> V_17 ) )
return V_18 ;
V_14 = (struct V_13 * ) ( F_4 ( V_5 ) + V_8 ) ;
V_1 = ( T_1 * ) V_14 ;
for ( V_11 = sizeof( struct V_13 ) ; V_11 < F_5 ( V_5 ) ; V_11 += V_10 ) {
V_10 = F_1 ( V_1 , V_11 ) ;
if ( V_11 + V_10 > F_5 ( V_5 ) )
break;
if ( ! F_6 ( V_7 -> V_19 , V_1 [ V_11 ] ) )
continue;
for ( V_12 = 0 ; V_12 < V_10 ; ++ V_12 ) {
V_16 = V_1 [ V_11 + V_12 ] ;
V_15 = V_3 ;
if ( ( V_11 + V_12 ) % 2 == 0 ) {
V_16 <<= 8 ;
V_15 <<= 8 ;
}
F_7 ( & V_14 -> V_20 , V_5 , F_8 ( V_16 ) ,
F_8 ( V_15 ) , 0 ) ;
}
memset ( V_1 + V_11 , V_3 , V_10 ) ;
}
return V_21 ;
}
static unsigned int
F_9 ( struct V_4 * V_5 , const struct V_22 * V_23 )
{
return F_2 ( V_5 , V_23 -> V_24 , F_10 ( V_5 ) ,
sizeof( struct V_25 ) + sizeof( struct V_13 ) ) ;
}
static unsigned int
F_11 ( struct V_4 * V_5 , const struct V_22 * V_23 )
{
struct V_26 * V_27 = F_12 ( V_5 ) ;
int V_8 ;
T_1 V_28 ;
V_28 = V_27 -> V_28 ;
V_8 = F_13 ( V_5 , sizeof( * V_27 ) , & V_28 ) ;
if ( V_8 < 0 )
return V_18 ;
return F_2 ( V_5 , V_23 -> V_24 , V_8 ,
sizeof( * V_27 ) + sizeof( struct V_13 ) ) ;
}
static int T_3 F_14 ( void )
{
return F_15 ( V_29 ,
F_16 ( V_29 ) ) ;
}
static void T_4 F_17 ( void )
{
F_18 ( V_29 ,
F_16 ( V_29 ) ) ;
}
