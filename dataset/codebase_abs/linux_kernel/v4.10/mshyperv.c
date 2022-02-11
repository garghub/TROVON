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
static unsigned char F_24 ( void )
{
return 0 ;
}
static int F_25 ( unsigned int V_22 , struct V_1 * V_2 )
{
static T_5 V_23 = F_26 ( - 1 ) ;
if ( ! V_24 )
return V_25 ;
if ( F_27 ( & V_23 , - 1 , F_28 () ) != - 1 )
return V_26 ;
return V_25 ;
}
static void T_2 F_29 ( void )
{
V_27 . V_28 = F_30 ( V_29 ) ;
V_27 . V_30 = F_31 ( V_29 ) ;
V_27 . V_31 = F_30 ( V_32 ) ;
F_32 ( L_2 ,
V_27 . V_28 , V_27 . V_31 ) ;
#ifdef F_33
if ( V_27 . V_28 & V_33 ) {
T_4 V_34 ;
F_23 ( V_35 , V_34 ) ;
V_34 = F_34 ( V_34 , V_36 ) ;
V_37 = V_34 ;
F_32 ( L_3 ,
V_37 ) ;
}
F_35 ( V_38 , F_25 , V_39 ,
L_4 ) ;
#endif
if ( V_27 . V_28 & V_40 )
F_36 ( & V_41 , V_42 / 100 ) ;
#ifdef F_37
V_43 = 1 ;
#endif
#if F_38 ( V_44 ) && F_39 ( V_45 )
V_46 . V_47 = F_15 ;
V_46 . V_48 = F_17 ;
#endif
F_40 ( L_5 ) ;
if ( F_41 ( V_49 ) )
V_50 . V_51 = F_24 ;
}
