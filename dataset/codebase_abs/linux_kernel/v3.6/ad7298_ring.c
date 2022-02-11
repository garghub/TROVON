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
struct V_24 * V_25 = V_2 -> V_26 ;
T_2 V_27 = 0 ;
T_3 V_28 [ 16 ] ;
int V_29 , V_6 ;
V_29 = F_10 ( V_5 -> V_30 , & V_5 -> V_18 ) ;
if ( V_29 )
goto V_31;
if ( V_2 -> V_32 ) {
V_27 = F_11 () ;
memcpy ( ( V_33 * ) V_28 + V_2 -> V_34 - sizeof( T_2 ) ,
& V_27 , sizeof( V_27 ) ) ;
}
for ( V_6 = 0 ; V_6 < F_3 ( V_2 -> V_3 ,
V_2 -> V_10 ) ; V_6 ++ )
V_28 [ V_6 ] = F_12 ( V_5 -> V_19 [ V_6 ] ) ;
V_2 -> V_26 -> V_35 -> V_36 ( V_25 , ( V_33 * ) V_28 , V_27 ) ;
V_31:
F_13 ( V_2 -> V_37 ) ;
return V_38 ;
}
int F_14 ( struct V_1 * V_2 )
{
return F_15 ( V_2 , NULL ,
& F_9 , NULL ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
}
