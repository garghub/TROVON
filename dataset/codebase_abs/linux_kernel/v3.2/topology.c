const struct V_1 * F_1 ( int V_2 )
{
return & V_3 [ V_2 ] . V_4 ;
}
void F_2 ( unsigned int V_5 )
{
struct V_6 * V_7 = & V_3 [ V_5 ] ;
unsigned int V_8 ;
unsigned int V_2 ;
if ( V_7 -> V_9 != - 1 )
return;
V_8 = F_3 () ;
if ( ( V_8 & V_10 ) == V_11 ) {
if ( V_8 & V_12 ) {
V_7 -> V_13 = ( V_8 >> V_14 )
& V_15 ;
V_7 -> V_9 = ( V_8 >> V_16 )
& V_17 ;
V_7 -> V_18 = ( V_8 >> V_19 )
& V_20 ;
} else {
V_7 -> V_13 = - 1 ;
V_7 -> V_9 = ( V_8 >> V_14 )
& V_15 ;
V_7 -> V_18 = ( V_8 >> V_16 )
& V_17 ;
}
} else {
V_7 -> V_13 = - 1 ;
V_7 -> V_9 = 0 ;
V_7 -> V_18 = - 1 ;
}
F_4 (cpu) {
struct V_6 * V_21 = & V_3 [ V_2 ] ;
if ( V_7 -> V_18 == V_21 -> V_18 ) {
F_5 ( V_5 , & V_21 -> V_4 ) ;
if ( V_2 != V_5 )
F_5 ( V_2 ,
& V_7 -> V_4 ) ;
if ( V_7 -> V_9 == V_21 -> V_9 ) {
F_5 ( V_5 ,
& V_21 -> V_22 ) ;
if ( V_2 != V_5 )
F_5 ( V_2 ,
& V_7 -> V_22 ) ;
}
}
}
F_6 () ;
F_7 ( V_23 L_1 ,
V_5 , V_3 [ V_5 ] . V_13 ,
V_3 [ V_5 ] . V_9 ,
V_3 [ V_5 ] . V_18 , V_8 ) ;
}
void F_8 ( void )
{
unsigned int V_2 ;
F_4 (cpu) {
struct V_6 * V_21 = & ( V_3 [ V_2 ] ) ;
V_21 -> V_13 = - 1 ;
V_21 -> V_9 = - 1 ;
V_21 -> V_18 = - 1 ;
F_9 ( & V_21 -> V_4 ) ;
F_9 ( & V_21 -> V_22 ) ;
}
F_6 () ;
}
