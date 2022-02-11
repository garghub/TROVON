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
V_6 = F_6 ( V_5 , & V_3 -> V_15 ) ;
F_7 ( 0 ) ;
V_2 -> V_16 &= ~ V_17 ;
if ( V_5 & V_8 )
V_6 |= F_8 ( V_4 , & V_3 -> V_9 [ 0 ] ,
(sizeof( unsigned int ) * 32 ) ) ;
if ( V_5 & V_10 )
V_6 |= F_8 ( V_4 + 16 , & V_3 -> V_9 [ 32 ] ,
(sizeof( unsigned int ) * 32 ) ) ;
V_6 |= F_6 ( F_2 () -> V_11 [ 0 ] , & V_3 -> V_12 ) ;
V_6 |= F_6 ( F_2 () -> V_13 [ 0 ] , & V_3 -> V_14 ) ;
F_2 () -> V_7 [ 0 ] |= V_5 ;
return V_6 ;
}
int F_9 ( int V_18 , T_3 T_2 * V_19 )
{
int V_20 , V_6 = F_4 ( V_18 , & V_19 -> V_18 ) ;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
struct V_21 * V_22 = & F_2 () -> V_21 [ V_20 ] ;
unsigned long V_23 = F_2 () -> V_24 [ V_20 ] ;
V_6 |= F_3 ( & V_19 -> V_21 [ V_20 ] , V_22 ,
sizeof( struct V_21 ) ) ;
V_6 |= F_4 ( V_23 , & V_19 -> V_24 [ V_20 ] ) ;
}
return V_6 ;
}
int F_10 ( T_3 T_2 * V_22 )
{
struct V_25 * V_26 = F_2 () ;
int V_20 , V_18 , V_6 ;
F_6 ( V_18 , & V_22 -> V_18 ) ;
if ( V_18 > V_27 )
return - V_28 ;
V_6 = 0 ;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
V_6 |= F_8 ( & V_26 -> V_21 [ V_20 ] ,
& V_22 -> V_21 [ V_20 ] ,
sizeof( struct V_21 ) ) ;
V_6 |= F_6 ( V_26 -> V_24 [ V_20 ] ,
& V_22 -> V_24 [ V_20 ] ) ;
}
if ( V_6 )
return V_6 ;
F_11 ( V_18 ) ;
F_12 () ;
if ( F_13 () )
return - V_28 ;
return 0 ;
}
