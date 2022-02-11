void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
int V_6 ;
V_2 -> V_7 = F_2 ( sizeof( V_8 ) * V_2 -> V_9 *
V_2 -> V_10 , V_11 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
if ( ( V_4 [ V_6 ] . V_12 >= V_2 -> V_9 ) ||
( V_4 [ V_6 ] . V_13 >= V_2 -> V_10 ) ) {
F_3 ( V_14
L_1 ,
V_6 , ( long ) V_4 [ V_6 ] . V_12 , ( long ) V_2 -> V_9 ,
( long ) V_4 [ V_6 ] . V_13 , ( long ) V_2 -> V_10 ) ;
} else
V_2 -> V_7 [ V_2 -> V_9 * V_4 [ V_6 ] . V_13 +
V_4 [ V_6 ] . V_12 ] = ( V_8 ) V_4 [ V_6 ] . V_15 ;
}
void
F_4 ( struct V_1 * V_2 )
{
F_5 ( ( void * ) V_2 -> V_7 ) ;
}
int
F_6 ( struct V_16 * V_17 , int V_13 , void * V_18 )
{
V_8 V_19 ;
if ( ( V_17 -> V_12 >= V_17 -> V_2 -> V_9 ) ||
( V_13 >= V_17 -> V_2 -> V_10 ) ) {
F_3 ( V_14
L_2 ,
( long ) V_17 -> V_12 , ( long ) V_17 -> V_2 -> V_9 , V_13 ,
( long ) V_17 -> V_2 -> V_10 ) ;
return 1 ;
}
V_19 = V_17 -> V_2 -> V_7 [ V_17 -> V_2 -> V_9 * V_13 + V_17 -> V_12 ] ;
if ( V_19 ) {
if ( V_17 -> V_20 )
V_17 -> V_21 ( V_17 , L_3 ,
V_17 -> V_2 -> V_22 [ V_17 -> V_12 ] ,
V_17 -> V_2 -> V_23 [ V_13 ] ) ;
V_19 ( V_17 , V_13 , V_18 ) ;
return 0 ;
} else {
if ( V_17 -> V_20 )
V_17 -> V_21 ( V_17 , L_4 ,
V_17 -> V_2 -> V_22 [ V_17 -> V_12 ] ,
V_17 -> V_2 -> V_23 [ V_13 ] ) ;
return 1 ;
}
}
void
F_7 ( struct V_16 * V_17 , int V_24 )
{
V_17 -> V_12 = V_24 ;
if ( V_17 -> V_20 )
V_17 -> V_21 ( V_17 , L_5 ,
V_17 -> V_2 -> V_22 [ V_24 ] ) ;
}
static void
F_8 ( struct V_25 * V_26 )
{
#if V_27
if ( V_26 -> V_17 -> V_20 )
V_26 -> V_17 -> V_21 ( V_26 -> V_17 , L_6 , ( long ) V_26 ) ;
#endif
F_6 ( V_26 -> V_17 , V_26 -> V_13 , V_26 -> V_18 ) ;
}
void
F_9 ( struct V_16 * V_17 , struct V_25 * V_26 )
{
V_26 -> V_17 = V_17 ;
#if V_27
if ( V_26 -> V_17 -> V_20 )
V_26 -> V_17 -> V_21 ( V_26 -> V_17 , L_7 , ( long ) V_26 ) ;
#endif
F_10 ( & V_26 -> V_28 , ( void * ) F_8 , ( long ) V_26 ) ;
}
void
F_11 ( struct V_25 * V_26 , int V_29 )
{
#if V_27
if ( V_26 -> V_17 -> V_20 )
V_26 -> V_17 -> V_21 ( V_26 -> V_17 , L_8 ,
( long ) V_26 , V_29 ) ;
#endif
F_12 ( & V_26 -> V_28 ) ;
}
int
F_13 ( struct V_25 * V_26 ,
int V_30 , int V_13 , void * V_18 , int V_29 )
{
#if V_27
if ( V_26 -> V_17 -> V_20 )
V_26 -> V_17 -> V_21 ( V_26 -> V_17 , L_9 ,
( long ) V_26 , V_30 , V_29 ) ;
#endif
if ( F_14 ( & V_26 -> V_28 ) ) {
if ( V_26 -> V_17 -> V_20 ) {
F_3 ( V_31
L_10 ) ;
V_26 -> V_17 -> V_21 ( V_26 -> V_17 ,
L_11 ) ;
}
return - 1 ;
}
F_15 ( & V_26 -> V_28 ) ;
V_26 -> V_13 = V_13 ;
V_26 -> V_18 = V_18 ;
V_26 -> V_28 . V_32 = V_33 + ( V_30 * V_34 ) / 1000 ;
F_16 ( & V_26 -> V_28 ) ;
return 0 ;
}
void
F_17 ( struct V_25 * V_26 ,
int V_30 , int V_13 , void * V_18 , int V_29 )
{
#if V_27
if ( V_26 -> V_17 -> V_20 )
V_26 -> V_17 -> V_21 ( V_26 -> V_17 , L_12 ,
( long ) V_26 , V_30 , V_29 ) ;
#endif
if ( F_14 ( & V_26 -> V_28 ) )
F_12 ( & V_26 -> V_28 ) ;
F_15 ( & V_26 -> V_28 ) ;
V_26 -> V_13 = V_13 ;
V_26 -> V_18 = V_18 ;
V_26 -> V_28 . V_32 = V_33 + ( V_30 * V_34 ) / 1000 ;
F_16 ( & V_26 -> V_28 ) ;
}
