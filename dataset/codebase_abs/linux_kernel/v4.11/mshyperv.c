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
static unsigned char F_22 ( void )
{
return 0 ;
}
static int F_23 ( unsigned int V_18 , struct V_1 * V_2 )
{
static T_4 V_19 = F_24 ( - 1 ) ;
if ( ! V_20 )
return V_21 ;
if ( F_25 ( & V_19 , - 1 , F_26 () ) != - 1 )
return V_22 ;
return V_21 ;
}
static void T_2 F_27 ( void )
{
int V_23 ;
int V_24 ;
int V_25 ;
int V_26 ;
V_27 . V_28 = F_28 ( V_29 ) ;
V_27 . V_30 = F_29 ( V_29 ) ;
V_27 . V_31 = F_28 ( V_32 ) ;
F_30 ( L_2 ,
V_27 . V_28 , V_27 . V_31 ) ;
if ( F_28 ( V_33 ) >= V_34 ) {
V_23 = F_28 ( V_34 ) ;
V_24 = F_31 ( V_34 ) ;
V_25 = F_32 ( V_34 ) ;
V_26 = F_29 ( V_34 ) ;
F_30 ( L_3 ,
V_23 , V_24 >> 16 ,
V_24 & 0xFFFF , V_25 ,
V_26 >> 24 , V_26 & 0xFFFFFF ) ;
}
#ifdef F_33
if ( V_27 . V_28 & V_35 ) {
T_5 V_36 ;
F_34 ( V_37 , V_36 ) ;
V_36 = F_35 ( V_36 , V_38 ) ;
V_39 = V_36 ;
F_30 ( L_4 ,
V_39 ) ;
}
F_36 ( V_40 , F_23 , V_41 ,
L_5 ) ;
#endif
#ifdef F_37
V_42 = 1 ;
#endif
#if F_38 ( V_43 ) && F_39 ( V_44 )
V_45 . V_46 = F_15 ;
V_45 . V_47 = F_17 ;
#endif
F_40 ( L_6 ) ;
if ( F_41 ( V_48 ) )
V_49 . V_50 = F_22 ;
#if F_38 ( V_43 )
V_49 . V_51 = V_52 ;
#endif
}
