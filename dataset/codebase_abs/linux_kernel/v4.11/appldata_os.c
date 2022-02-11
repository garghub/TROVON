static void F_1 ( void * V_1 )
{
int V_2 , V_3 , V_4 ;
struct V_5 * V_6 ;
unsigned int V_7 ;
V_6 = V_1 ;
V_6 -> V_8 ++ ;
V_6 -> V_9 = V_9 ;
V_6 -> V_10 = V_10 () ;
V_6 -> V_11 = V_11 () ;
V_6 -> V_12 [ 0 ] = V_12 [ 0 ] + ( V_13 / 200 ) ;
V_6 -> V_12 [ 1 ] = V_12 [ 1 ] + ( V_13 / 200 ) ;
V_6 -> V_12 [ 2 ] = V_12 [ 2 ] + ( V_13 / 200 ) ;
V_3 = 0 ;
F_2 (i) {
V_6 -> V_14 [ V_3 ] . V_15 =
F_3 ( F_4 ( V_2 ) . V_16 [ V_17 ] ) ;
V_6 -> V_14 [ V_3 ] . V_18 =
F_3 ( F_4 ( V_2 ) . V_16 [ V_19 ] ) ;
V_6 -> V_14 [ V_3 ] . V_20 =
F_3 ( F_4 ( V_2 ) . V_16 [ V_21 ] ) ;
V_6 -> V_14 [ V_3 ] . V_22 =
F_3 ( F_4 ( V_2 ) . V_16 [ V_23 ] ) ;
V_6 -> V_14 [ V_3 ] . V_24 =
F_3 ( F_4 ( V_2 ) . V_16 [ V_25 ] ) ;
V_6 -> V_14 [ V_3 ] . V_26 =
F_3 ( F_4 ( V_2 ) . V_16 [ V_27 ] ) ;
V_6 -> V_14 [ V_3 ] . V_28 =
F_3 ( F_4 ( V_2 ) . V_16 [ V_29 ] ) ;
V_6 -> V_14 [ V_3 ] . V_30 =
F_3 ( F_4 ( V_2 ) . V_16 [ V_31 ] ) ;
V_6 -> V_14 [ V_3 ] . V_32 = V_2 ;
V_3 ++ ;
}
V_6 -> V_33 = V_3 ;
V_7 = sizeof( struct V_5 ) +
( V_6 -> V_33 * sizeof( struct V_34 ) ) ;
if ( V_35 . V_36 != V_7 ) {
if ( V_35 . V_37 ) {
V_4 = F_5 ( V_38 ,
V_39 ,
( unsigned long ) V_35 . V_1 , V_7 ,
V_35 . V_40 ) ;
if ( V_4 != 0 )
F_6 ( L_1
L_2 , V_4 ) ;
V_4 = F_5 ( V_38 ,
V_41 ,
( unsigned long ) V_35 . V_1 , V_35 . V_36 ,
V_35 . V_40 ) ;
if ( V_4 != 0 )
F_6 ( L_3
L_4 , V_4 ) ;
}
V_35 . V_36 = V_7 ;
}
V_6 -> V_42 = F_7 () ;
V_6 -> V_43 ++ ;
}
static int T_1 F_8 ( void )
{
int V_4 , V_44 ;
V_44 = sizeof( struct V_5 ) +
( F_9 () * sizeof( struct V_34 ) ) ;
if ( V_44 > V_45 ) {
F_6 ( L_5
L_6 , V_44 , V_45 ) ;
V_4 = - V_46 ;
goto V_47;
}
V_5 = F_10 ( V_44 , V_48 | V_49 ) ;
if ( V_5 == NULL ) {
V_4 = - V_46 ;
goto V_47;
}
V_5 -> V_50 = sizeof( struct V_34 ) ;
V_5 -> V_51 = F_11 ( struct V_5 ,
V_14 ) ;
V_35 . V_1 = V_5 ;
V_35 . V_52 = & F_1 ;
V_4 = F_12 ( & V_35 ) ;
if ( V_4 != 0 )
F_13 ( V_5 ) ;
V_47:
return V_4 ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_35 ) ;
F_13 ( V_5 ) ;
}
