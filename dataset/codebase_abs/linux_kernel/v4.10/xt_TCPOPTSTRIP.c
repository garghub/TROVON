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
const struct V_10 * V_11 = V_7 -> V_12 ;
unsigned int V_13 , V_14 , V_15 ;
struct V_16 * V_17 ;
T_2 V_18 , V_19 ;
T_1 * V_1 ;
int V_20 , V_21 ;
if ( V_7 -> V_22 != 0 )
return V_23 ;
if ( ! F_3 ( V_5 , V_5 -> V_20 ) )
return V_24 ;
V_20 = V_5 -> V_20 - V_8 ;
if ( V_20 < ( int ) sizeof( struct V_16 ) )
return V_24 ;
V_17 = (struct V_16 * ) ( F_4 ( V_5 ) + V_8 ) ;
V_21 = V_17 -> V_25 * 4 ;
if ( V_20 < V_21 )
return V_24 ;
V_1 = ( T_1 * ) V_17 ;
for ( V_14 = sizeof( struct V_16 ) ; V_14 < V_21 - 1 ; V_14 += V_13 ) {
V_13 = F_1 ( V_1 , V_14 ) ;
if ( V_14 + V_13 > V_21 )
break;
if ( ! F_5 ( V_11 -> V_26 , V_1 [ V_14 ] ) )
continue;
for ( V_15 = 0 ; V_15 < V_13 ; ++ V_15 ) {
V_19 = V_1 [ V_14 + V_15 ] ;
V_18 = V_3 ;
if ( ( V_14 + V_15 ) % 2 == 0 ) {
V_19 <<= 8 ;
V_18 <<= 8 ;
}
F_6 ( & V_17 -> V_27 , V_5 , F_7 ( V_19 ) ,
F_7 ( V_18 ) , false ) ;
}
memset ( V_1 + V_14 , V_3 , V_13 ) ;
}
return V_23 ;
}
static unsigned int
F_8 ( struct V_4 * V_5 , const struct V_6 * V_7 )
{
return F_2 ( V_5 , V_7 , F_9 ( V_5 ) ,
sizeof( struct V_28 ) + sizeof( struct V_16 ) ) ;
}
static unsigned int
F_10 ( struct V_4 * V_5 , const struct V_6 * V_7 )
{
struct V_29 * V_30 = F_11 ( V_5 ) ;
int V_8 ;
T_1 V_31 ;
T_3 V_32 ;
V_31 = V_30 -> V_31 ;
V_8 = F_12 ( V_5 , sizeof( * V_30 ) , & V_31 , & V_32 ) ;
if ( V_8 < 0 )
return V_24 ;
return F_2 ( V_5 , V_7 , V_8 ,
sizeof( * V_30 ) + sizeof( struct V_16 ) ) ;
}
static int T_4 F_13 ( void )
{
return F_14 ( V_33 ,
F_15 ( V_33 ) ) ;
}
static void T_5 F_16 ( void )
{
F_17 ( V_33 ,
F_15 ( V_33 ) ) ;
}
