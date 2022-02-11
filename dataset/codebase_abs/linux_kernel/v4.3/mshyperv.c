void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_3 () ;
F_4 ( V_4 ) ;
if ( V_5 )
V_5 () ;
F_5 () ;
F_2 ( V_3 ) ;
}
void F_6 ( void (* F_7)( void ) )
{
V_5 = F_7 ;
if ( ! F_8 ( V_6 , V_7 ) )
F_9 ( V_6 ,
V_8 ) ;
}
void F_10 ( void )
{
V_5 = NULL ;
}
void F_11 ( void (* F_7)( void ) )
{
V_9 = F_7 ;
}
void F_12 ( void )
{
V_9 = NULL ;
}
void F_13 ( void (* F_7)( struct V_1 * V_2 ) )
{
V_10 = F_7 ;
}
void F_14 ( void )
{
V_10 = NULL ;
}
static void F_15 ( void )
{
if ( V_11 && V_9 )
V_9 () ;
F_16 () ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( V_10 )
V_10 ( V_2 ) ;
F_18 ( V_2 ) ;
}
static T_1 T_2 F_19 ( void )
{
T_3 V_12 ;
T_3 V_13 [ 3 ] ;
if ( ! F_20 ( V_14 ) )
return 0 ;
F_21 ( V_15 ,
& V_12 , & V_13 [ 0 ] , & V_13 [ 1 ] , & V_13 [ 2 ] ) ;
if ( V_12 >= V_16 &&
V_12 <= V_17 &&
! memcmp ( L_1 , V_13 , 12 ) )
return V_15 ;
return 0 ;
}
static T_4 F_22 ( struct V_18 * V_19 )
{
T_4 V_20 ;
F_23 ( V_21 , V_20 ) ;
return V_20 ;
}
static void T_2 F_24 ( void )
{
V_22 . V_23 = F_25 ( V_24 ) ;
V_22 . V_25 = F_26 ( V_24 ) ;
V_22 . V_26 = F_25 ( V_27 ) ;
F_27 ( V_28 L_2 ,
V_22 . V_23 , V_22 . V_26 ) ;
#ifdef F_28
if ( V_22 . V_23 & V_29 ) {
T_5 V_30 ;
F_23 ( V_31 , V_30 ) ;
V_30 = F_29 ( V_30 , V_32 ) ;
V_33 = V_30 ;
F_27 ( V_28 L_3 ,
V_33 ) ;
}
#endif
if ( V_22 . V_23 & V_34 )
F_30 ( & V_35 , V_36 / 100 ) ;
#ifdef F_31
V_37 = 1 ;
#endif
#if F_32 ( V_38 ) && F_33 ( V_39 )
V_40 . V_41 = F_15 ;
V_40 . V_42 = F_17 ;
#endif
F_34 ( L_4 ) ;
}
