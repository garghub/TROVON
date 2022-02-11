static int F_1 ( T_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
T_1 V_4 , V_5 ;
do {
V_4 = * V_1 ;
V_5 = ( V_4 & V_2 ) ^ V_3 ;
if ( V_4 == V_5 )
return 0 ;
} while ( F_2 ( V_1 , V_4 , V_5 ) != V_4 );
return 1 ;
}
int F_3 ( struct V_6 * V_7 ,
const T_1 * V_8 ,
const T_1 * V_2 , unsigned int V_9 )
{
struct V_10 * V_11 ;
unsigned int V_12 , V_13 ;
int V_14 = 0 ;
T_1 * V_15 ;
V_11 = F_4 ( V_7 ) ;
if ( ! V_11 )
return - V_16 ;
V_12 = sizeof( V_11 -> V_17 ) ;
if ( V_12 < ( V_9 * sizeof( T_1 ) ) )
V_9 = V_12 / sizeof( T_1 ) ;
V_15 = ( T_1 * ) V_11 -> V_17 ;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ )
V_14 |= F_1 ( & V_15 [ V_13 ] , V_2 ? ~ V_2 [ V_13 ] : 0 , V_8 [ V_13 ] ) ;
V_12 /= sizeof( T_1 ) ;
for ( V_13 = V_9 ; V_13 < V_12 ; V_13 ++ )
F_1 ( & V_15 [ V_13 ] , 0 , 0 ) ;
if ( V_14 )
F_5 ( V_18 , V_7 ) ;
return 0 ;
}
int F_6 ( struct V_19 * V_19 , unsigned int V_17 )
{
if ( F_7 ( V_17 ) >= V_20 / sizeof( long ) )
return - V_21 ;
F_8 ( & V_22 ) ;
V_19 -> V_7 . V_23 ++ ;
F_9 ( & V_22 ) ;
return 0 ;
}
void F_10 ( struct V_19 * V_19 )
{
F_8 ( & V_22 ) ;
V_19 -> V_7 . V_23 -- ;
F_9 ( & V_22 ) ;
}
int F_11 ( void )
{
F_12 ( V_20 / sizeof( long ) >= V_24 ) ;
F_13 ( & V_22 ) ;
return F_14 ( & V_25 ) ;
}
void F_15 ( void )
{
F_16 ( & V_25 ) ;
}
