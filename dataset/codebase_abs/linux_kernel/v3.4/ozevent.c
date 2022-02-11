void F_1 ( void )
{
F_2 ( L_1 ) ;
V_1 = V_2 = 0 ;
V_3 = 0 ;
}
void F_3 ( void )
{
F_2 ( L_2 ) ;
}
void F_4 ( T_1 V_4 , T_1 V_5 , T_2 V_6 , void * V_7 , unsigned V_8 )
{
unsigned long V_9 ;
int V_10 ;
F_5 ( & V_11 , V_9 ) ;
V_10 = ( V_1 + 1 ) & ( V_12 - 1 ) ;
if ( V_10 != V_2 ) {
struct V_13 * V_14 = & V_15 [ V_1 ] ;
V_14 -> V_16 = V_16 ;
V_14 -> V_4 = V_4 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_7 = V_7 ;
V_14 -> V_8 = V_8 ;
V_1 = V_10 ;
} else {
V_3 ++ ;
}
F_6 ( & V_11 , V_9 ) ;
}
int F_7 ( struct V_17 T_3 * V_18 )
{
int V_19 ;
int V_10 ;
struct V_20 {
int V_21 ;
int V_22 ;
} V_20 ;
V_10 = V_2 ;
V_20 . V_21 = V_1 - V_10 ;
if ( V_20 . V_21 < 0 )
V_20 . V_21 += V_12 ;
if ( V_20 . V_21 > V_23 )
V_20 . V_21 = V_23 ;
V_20 . V_22 = V_3 ;
V_3 = 0 ;
if ( F_8 ( ( void T_3 * ) V_18 , & V_20 , sizeof( V_20 ) ) )
return - V_24 ;
V_19 = V_12 - V_10 ;
if ( V_19 > V_20 . V_21 )
V_19 = V_20 . V_21 ;
if ( V_19 ) {
int V_25 = V_19 * sizeof( struct V_13 ) ;
void T_3 * V_26 = ( void T_3 * ) V_18 -> V_27 ;
if ( F_8 ( V_26 , & V_15 [ V_10 ] , V_25 ) )
return - V_24 ;
if ( V_20 . V_21 > V_19 ) {
V_26 = ( void T_3 * ) & V_18 -> V_27 [ V_19 ] ;
V_25 = ( V_20 . V_21 - V_19 ) * sizeof( struct V_13 ) ;
if ( F_8 ( V_26 , V_15 , V_25 ) )
return - V_24 ;
}
}
V_10 += V_20 . V_21 ;
if ( V_10 >= V_12 )
V_10 -= V_12 ;
V_2 = V_10 ;
return 0 ;
}
void F_9 ( void )
{
unsigned long V_9 ;
F_5 ( & V_11 , V_9 ) ;
V_1 = V_2 = 0 ;
V_3 = 0 ;
F_6 ( & V_11 , V_9 ) ;
}
