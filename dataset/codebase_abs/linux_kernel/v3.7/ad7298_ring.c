int F_1 ( struct V_1 * V_2 ,
const unsigned long * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
unsigned short V_8 ;
int V_9 ;
V_9 = F_3 ( V_3 , V_2 -> V_10 ) ;
V_8 = V_11 | V_5 -> V_12 ;
for ( V_6 = 0 , V_7 = F_4 ( 0 ) ; V_6 < V_13 ; V_6 ++ , V_7 >>= 1 )
if ( F_5 ( V_6 , V_3 ) )
V_8 |= V_7 ;
V_5 -> V_14 [ 0 ] = F_6 ( V_8 ) ;
V_5 -> V_15 [ 0 ] . V_14 = & V_5 -> V_14 [ 0 ] ;
V_5 -> V_15 [ 0 ] . V_16 = 2 ;
V_5 -> V_15 [ 0 ] . V_17 = 1 ;
V_5 -> V_15 [ 1 ] . V_14 = & V_5 -> V_14 [ 1 ] ;
V_5 -> V_15 [ 1 ] . V_16 = 2 ;
V_5 -> V_15 [ 1 ] . V_17 = 1 ;
F_7 ( & V_5 -> V_18 ) ;
F_8 ( & V_5 -> V_15 [ 0 ] , & V_5 -> V_18 ) ;
F_8 ( & V_5 -> V_15 [ 1 ] , & V_5 -> V_18 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
V_5 -> V_15 [ V_6 + 2 ] . V_19 = & V_5 -> V_19 [ V_6 ] ;
V_5 -> V_15 [ V_6 + 2 ] . V_16 = 2 ;
V_5 -> V_15 [ V_6 + 2 ] . V_17 = 1 ;
F_8 ( & V_5 -> V_15 [ V_6 + 2 ] , & V_5 -> V_18 ) ;
}
V_5 -> V_15 [ V_6 + 1 ] . V_17 = 0 ;
return 0 ;
}
static T_1 F_9 ( int V_20 , void * V_21 )
{
struct V_22 * V_23 = V_21 ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_24 = 0 ;
T_3 V_25 [ 16 ] ;
int V_26 , V_6 ;
V_26 = F_10 ( V_5 -> V_27 , & V_5 -> V_18 ) ;
if ( V_26 )
goto V_28;
if ( V_2 -> V_29 ) {
V_24 = F_11 () ;
memcpy ( ( V_30 * ) V_25 + V_2 -> V_31 - sizeof( T_2 ) ,
& V_24 , sizeof( V_24 ) ) ;
}
for ( V_6 = 0 ; V_6 < F_3 ( V_2 -> V_3 ,
V_2 -> V_10 ) ; V_6 ++ )
V_25 [ V_6 ] = F_12 ( V_5 -> V_19 [ V_6 ] ) ;
F_13 ( V_2 -> V_32 , ( V_30 * ) V_25 ) ;
V_28:
F_14 ( V_2 -> V_33 ) ;
return V_34 ;
}
int F_15 ( struct V_1 * V_2 )
{
return F_16 ( V_2 , NULL ,
& F_9 , NULL ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
}
