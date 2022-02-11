void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_3 () ;
F_4 ( V_4 ) ;
if ( V_5 )
V_5 () ;
if ( V_6 . V_7 & V_8 )
F_5 () ;
F_6 () ;
F_2 ( V_3 ) ;
}
void F_7 ( void (* F_8)( void ) )
{
V_5 = F_8 ;
}
void F_9 ( void )
{
V_5 = NULL ;
}
void F_10 ( void (* F_8)( void ) )
{
V_9 = F_8 ;
}
void F_11 ( void )
{
V_9 = NULL ;
}
void F_12 ( void (* F_8)( struct V_1 * V_2 ) )
{
V_10 = F_8 ;
}
void F_13 ( void )
{
V_10 = NULL ;
}
static void F_14 ( void )
{
if ( V_11 && V_9 )
V_9 () ;
F_15 () ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_10 )
V_10 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static T_1 T_2 F_18 ( void )
{
T_3 V_12 ;
T_3 V_13 [ 3 ] ;
if ( ! F_19 ( V_14 ) )
return 0 ;
F_20 ( V_15 ,
& V_12 , & V_13 [ 0 ] , & V_13 [ 1 ] , & V_13 [ 2 ] ) ;
if ( V_12 >= V_16 &&
V_12 <= V_17 &&
! memcmp ( L_1 , V_13 , 12 ) )
return V_15 ;
return 0 ;
}
static unsigned char F_21 ( void )
{
return 0 ;
}
static int F_22 ( unsigned int V_18 , struct V_1 * V_2 )
{
static T_4 V_19 = F_23 ( - 1 ) ;
if ( ! V_20 )
return V_21 ;
if ( F_24 ( & V_19 , - 1 , F_25 () ) != - 1 )
return V_22 ;
return V_21 ;
}
static unsigned long F_26 ( void )
{
unsigned long V_23 ;
F_27 ( V_24 , V_23 ) ;
return V_23 / 1000 ;
}
static void T_2 F_28 ( void )
{
int V_25 ;
int V_26 ;
int V_27 ;
int V_28 ;
V_6 . V_29 = F_29 ( V_30 ) ;
V_6 . V_31 = F_30 ( V_30 ) ;
V_6 . V_7 = F_29 ( V_32 ) ;
F_31 ( L_2 ,
V_6 . V_29 , V_6 . V_7 ) ;
V_6 . V_33 = F_29 ( V_34 ) ;
V_6 . V_35 = F_32 ( V_34 ) ;
F_33 ( L_3 ,
V_6 . V_33 , V_6 . V_35 ) ;
if ( F_29 ( V_36 ) >= V_37 ) {
V_25 = F_29 ( V_37 ) ;
V_26 = F_32 ( V_37 ) ;
V_27 = F_34 ( V_37 ) ;
V_28 = F_30 ( V_37 ) ;
F_31 ( L_4 ,
V_25 , V_26 >> 16 ,
V_26 & 0xFFFF , V_27 ,
V_28 >> 24 , V_28 & 0xFFFFFF ) ;
}
if ( V_6 . V_29 & V_38 &&
V_6 . V_31 & V_39 ) {
V_40 . V_41 = F_26 ;
V_40 . V_42 = F_26 ;
}
#ifdef F_35
if ( V_6 . V_29 & V_38 &&
V_6 . V_31 & V_39 ) {
T_5 V_43 ;
F_27 ( V_44 , V_43 ) ;
V_43 = F_36 ( V_43 , V_45 ) ;
V_46 = V_43 ;
F_31 ( L_5 ,
V_46 ) ;
}
F_37 ( V_47 , F_22 , V_48 ,
L_6 ) ;
#endif
#ifdef F_38
V_49 = 1 ;
#endif
#if F_39 ( V_50 ) && F_40 ( V_51 )
V_52 . V_53 = F_14 ;
V_52 . V_54 = F_16 ;
#endif
F_41 ( L_7 ) ;
if ( F_42 ( V_55 ) )
V_40 . V_56 = F_21 ;
#if F_39 ( V_50 )
V_40 . V_57 = V_58 ;
F_43 () ;
F_44 ( V_59 , V_60 ) ;
#endif
}
