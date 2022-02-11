int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 || F_3 ( V_3 ) >= V_5 -> V_6 )
return - V_7 ;
if ( F_4 ( V_3 , V_5 -> V_8 ) )
return 0 ;
if ( ! F_5 ( V_3 , V_5 -> V_8 ) )
F_6 ( V_9 , V_2 ) ;
return 0 ;
}
static int F_7 ( T_2 * V_10 , T_2 V_11 , T_2 V_12 )
{
T_2 V_13 , V_14 ;
do {
V_13 = * V_10 ;
V_14 = ( V_13 & V_11 ) ^ V_12 ;
if ( V_13 == V_14 )
return 0 ;
} while ( F_8 ( V_10 , V_13 , V_14 ) != V_13 );
return 1 ;
}
int F_9 ( struct V_1 * V_2 ,
const T_2 * V_15 ,
const T_2 * V_11 , unsigned int V_16 )
{
struct V_4 * V_5 ;
unsigned int V_17 , V_18 ;
int V_19 = 0 ;
T_2 * V_20 ;
V_5 = F_2 ( V_2 ) ;
if ( ! V_5 )
return - V_7 ;
V_17 = V_5 -> V_6 * sizeof( long ) ;
if ( V_17 < ( V_16 * sizeof( T_2 ) ) )
V_16 = V_17 / sizeof( T_2 ) ;
V_20 = ( T_2 * ) V_5 -> V_8 ;
for ( V_18 = 0 ; V_18 < V_16 ; V_18 ++ )
V_19 |= F_7 ( & V_20 [ V_18 ] , V_11 ? ~ V_11 [ V_18 ] : 0 , V_15 [ V_18 ] ) ;
V_17 /= sizeof( T_2 ) ;
for ( V_18 = V_16 ; V_18 < V_17 ; V_18 ++ )
F_7 ( & V_20 [ V_18 ] , 0 , 0 ) ;
if ( V_19 )
F_6 ( V_9 , V_2 ) ;
return 0 ;
}
int F_10 ( struct V_21 * V_21 , unsigned int V_8 )
{
T_3 V_6 ;
V_6 = F_3 ( V_8 ) + 1 ;
if ( V_6 > V_22 / sizeof( long ) )
return - V_23 ;
F_11 ( & V_24 ) ;
V_21 -> V_2 . V_25 ++ ;
if ( V_6 > V_21 -> V_2 . V_26 )
V_21 -> V_2 . V_26 = V_6 ;
F_12 ( & V_24 ) ;
return 0 ;
}
void F_13 ( struct V_21 * V_21 )
{
F_11 ( & V_24 ) ;
V_21 -> V_2 . V_25 -- ;
if ( V_21 -> V_2 . V_25 == 0 )
V_21 -> V_2 . V_26 = 0 ;
F_12 ( & V_24 ) ;
}
int F_14 ( void )
{
F_15 ( V_22 / sizeof( long ) >= V_27 ) ;
F_16 ( & V_24 ) ;
return F_17 ( & V_28 ) ;
}
void F_18 ( void )
{
F_19 ( & V_28 ) ;
}
