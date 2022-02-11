int F_1 ( struct V_1 * V_2 , T_1 T_2 * V_3 )
{
unsigned long * V_4 = F_2 () -> V_4 ;
unsigned long V_5 ;
int V_6 = 0 ;
V_5 = F_2 () -> V_7 [ 0 ] ;
if ( V_5 & V_8 )
V_6 |= F_3 ( & V_3 -> V_9 [ 0 ] , V_4 ,
(sizeof( unsigned int ) * 32 ) ) ;
if ( V_5 & V_10 )
V_6 |= F_3 ( & V_3 -> V_9 [ 32 ] , V_4 + 16 ,
(sizeof( unsigned int ) * 32 ) ) ;
V_6 |= F_4 ( F_2 () -> V_11 [ 0 ] , & V_3 -> V_12 ) ;
V_6 |= F_4 ( F_2 () -> V_13 [ 0 ] , & V_3 -> V_14 ) ;
V_6 |= F_4 ( V_5 , & V_3 -> V_15 ) ;
return V_6 ;
}
int F_5 ( struct V_1 * V_2 , T_1 T_2 * V_3 )
{
unsigned long * V_4 = F_2 () -> V_4 ;
unsigned long V_5 ;
int V_6 ;
if ( ( ( unsigned long ) V_3 ) & 7 )
return - V_16 ;
V_6 = F_6 ( V_5 , & V_3 -> V_15 ) ;
F_7 ( 0 ) ;
V_2 -> V_17 &= ~ V_18 ;
if ( V_5 & V_8 )
V_6 |= F_8 ( V_4 , & V_3 -> V_9 [ 0 ] ,
(sizeof( unsigned int ) * 32 ) ) ;
if ( V_5 & V_10 )
V_6 |= F_8 ( V_4 + 16 , & V_3 -> V_9 [ 32 ] ,
(sizeof( unsigned int ) * 32 ) ) ;
V_6 |= F_9 ( F_2 () -> V_11 [ 0 ] , & V_3 -> V_12 ) ;
V_6 |= F_9 ( F_2 () -> V_13 [ 0 ] , & V_3 -> V_14 ) ;
F_2 () -> V_7 [ 0 ] |= V_5 ;
return V_6 ;
}
int F_10 ( int V_19 , T_3 T_2 * V_20 )
{
int V_21 , V_6 = F_4 ( V_19 , & V_20 -> V_19 ) ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
struct V_22 * V_23 = & F_2 () -> V_22 [ V_21 ] ;
unsigned long V_24 = F_2 () -> V_25 [ V_21 ] ;
V_6 |= F_3 ( & V_20 -> V_22 [ V_21 ] , V_23 ,
sizeof( struct V_22 ) ) ;
V_6 |= F_4 ( V_24 , & V_20 -> V_25 [ V_21 ] ) ;
}
return V_6 ;
}
int F_11 ( T_3 T_2 * V_23 )
{
struct V_26 * V_27 = F_2 () ;
int V_21 , V_19 , V_6 ;
if ( ( ( unsigned long ) V_23 ) & 7 )
return - V_16 ;
F_6 ( V_19 , & V_23 -> V_19 ) ;
if ( V_19 > V_28 )
return - V_16 ;
V_6 = 0 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
V_6 |= F_8 ( & V_27 -> V_22 [ V_21 ] ,
& V_23 -> V_22 [ V_21 ] ,
sizeof( struct V_22 ) ) ;
V_6 |= F_9 ( V_27 -> V_25 [ V_21 ] ,
& V_23 -> V_25 [ V_21 ] ) ;
}
if ( V_6 )
return V_6 ;
F_12 ( V_19 ) ;
F_13 () ;
if ( F_14 () )
return - V_16 ;
return 0 ;
}
