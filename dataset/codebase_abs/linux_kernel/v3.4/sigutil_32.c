int F_1 ( struct V_1 * V_2 , T_1 T_2 * V_3 )
{
int V_4 = 0 ;
#ifdef F_2
if ( F_3 ( V_5 , V_6 ) ) {
F_4 ( F_5 () | V_7 ) ;
F_6 ( & V_5 -> V_8 . V_9 [ 0 ] , & V_5 -> V_8 . V_10 ,
& V_5 -> V_8 . V_11 [ 0 ] , & V_5 -> V_8 . V_12 ) ;
V_2 -> V_13 &= ~ ( V_7 ) ;
F_7 ( V_5 , V_6 ) ;
}
#else
if ( V_5 == V_14 ) {
F_4 ( F_5 () | V_7 ) ;
F_6 ( & V_5 -> V_8 . V_9 [ 0 ] , & V_5 -> V_8 . V_10 ,
& V_5 -> V_8 . V_11 [ 0 ] , & V_5 -> V_8 . V_12 ) ;
V_14 = NULL ;
V_2 -> V_13 &= ~ ( V_7 ) ;
}
#endif
V_4 |= F_8 ( & V_3 -> V_15 [ 0 ] ,
& V_5 -> V_8 . V_9 [ 0 ] ,
(sizeof( unsigned long ) * 32 ) ) ;
V_4 |= F_9 ( V_5 -> V_8 . V_10 , & V_3 -> V_16 ) ;
V_4 |= F_9 ( V_5 -> V_8 . V_12 , & V_3 -> V_17 ) ;
if ( V_5 -> V_8 . V_12 != 0 )
V_4 |= F_8 ( & V_3 -> V_18 [ 0 ] ,
& V_5 -> V_8 . V_11 [ 0 ] ,
( (sizeof( unsigned long ) +
(sizeof( unsigned long * ) ) ) * 16 ) ) ;
F_10 () ;
return V_4 ;
}
int F_11 ( struct V_1 * V_2 , T_1 T_2 * V_3 )
{
int V_4 ;
#ifdef F_2
if ( F_3 ( V_5 , V_6 ) )
V_2 -> V_13 &= ~ V_7 ;
#else
if ( V_5 == V_14 ) {
V_14 = NULL ;
V_2 -> V_13 &= ~ V_7 ;
}
#endif
F_12 () ;
F_7 ( V_5 , V_6 ) ;
if ( ! F_13 ( V_19 , V_3 , sizeof( * V_3 ) ) )
return - V_20 ;
V_4 = F_14 ( & V_5 -> V_8 . V_9 [ 0 ] , & V_3 -> V_15 [ 0 ] ,
(sizeof( unsigned long ) * 32 ) ) ;
V_4 |= F_15 ( V_5 -> V_8 . V_10 , & V_3 -> V_16 ) ;
V_4 |= F_15 ( V_5 -> V_8 . V_12 , & V_3 -> V_17 ) ;
if ( V_5 -> V_8 . V_12 != 0 )
V_4 |= F_14 ( & V_5 -> V_8 . V_11 [ 0 ] ,
& V_3 -> V_18 [ 0 ] ,
( (sizeof( unsigned long ) +
(sizeof( unsigned long * ) ) ) * 16 ) ) ;
return V_4 ;
}
int F_16 ( int V_21 , T_3 T_2 * V_22 )
{
int V_23 , V_4 = F_9 ( V_21 , & V_22 -> V_21 ) ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ ) {
struct V_24 * V_25 ;
unsigned long V_26 ;
V_25 = & F_17 () -> V_27 [ V_23 ] ;
V_26 = F_17 () -> V_28 [ V_23 ] ;
V_4 |= F_18 ( & V_22 -> V_27 [ V_23 ] , V_25 ,
sizeof( struct V_24 ) ) ;
V_4 |= F_9 ( V_26 , & V_22 -> V_28 [ V_23 ] ) ;
}
return V_4 ;
}
int F_19 ( T_3 T_2 * V_25 )
{
struct V_29 * V_30 = F_17 () ;
int V_23 , V_21 , V_4 ;
F_15 ( V_21 , & V_25 -> V_21 ) ;
if ( V_21 > V_31 )
return - V_20 ;
V_4 = 0 ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ ) {
V_4 |= F_20 ( & V_30 -> V_27 [ V_23 ] ,
& V_25 -> V_27 [ V_23 ] ,
sizeof( struct V_24 ) ) ;
V_4 |= F_15 ( V_30 -> V_28 [ V_23 ] ,
& V_25 -> V_28 [ V_23 ] ) ;
}
if ( V_4 )
return V_4 ;
V_30 -> V_32 = V_21 ;
F_21 () ;
if ( V_30 -> V_32 )
return - V_20 ;
return 0 ;
}
