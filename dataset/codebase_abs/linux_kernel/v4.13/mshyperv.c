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
if ( ! F_9 ( V_9 , V_10 ) )
F_10 ( V_9 ,
V_11 ) ;
}
void F_11 ( void )
{
V_5 = NULL ;
}
void F_12 ( void (* F_8)( void ) )
{
V_12 = F_8 ;
}
void F_13 ( void )
{
V_12 = NULL ;
}
void F_14 ( void (* F_8)( struct V_1 * V_2 ) )
{
V_13 = F_8 ;
}
void F_15 ( void )
{
V_13 = NULL ;
}
static void F_16 ( void )
{
if ( V_14 && V_12 )
V_12 () ;
F_17 () ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( V_13 )
V_13 ( V_2 ) ;
F_19 ( V_2 ) ;
}
static T_1 T_2 F_20 ( void )
{
T_3 V_15 ;
T_3 V_16 [ 3 ] ;
if ( ! F_21 ( V_17 ) )
return 0 ;
F_22 ( V_18 ,
& V_15 , & V_16 [ 0 ] , & V_16 [ 1 ] , & V_16 [ 2 ] ) ;
if ( V_15 >= V_19 &&
V_15 <= V_20 &&
! memcmp ( L_1 , V_16 , 12 ) )
return V_18 ;
return 0 ;
}
static unsigned char F_23 ( void )
{
return 0 ;
}
static int F_24 ( unsigned int V_21 , struct V_1 * V_2 )
{
static T_4 V_22 = F_25 ( - 1 ) ;
if ( ! V_23 )
return V_24 ;
if ( F_26 ( & V_22 , - 1 , F_27 () ) != - 1 )
return V_25 ;
return V_24 ;
}
static unsigned long F_28 ( void )
{
unsigned long V_26 ;
F_29 ( V_27 , V_26 ) ;
return V_26 / 1000 ;
}
static void T_2 F_30 ( void )
{
int V_28 ;
int V_29 ;
int V_30 ;
int V_31 ;
V_6 . V_32 = F_31 ( V_33 ) ;
V_6 . V_34 = F_32 ( V_33 ) ;
V_6 . V_7 = F_31 ( V_35 ) ;
F_33 ( L_2 ,
V_6 . V_32 , V_6 . V_7 ) ;
if ( F_31 ( V_36 ) >= V_37 ) {
V_28 = F_31 ( V_37 ) ;
V_29 = F_34 ( V_37 ) ;
V_30 = F_35 ( V_37 ) ;
V_31 = F_32 ( V_37 ) ;
F_33 ( L_3 ,
V_28 , V_29 >> 16 ,
V_29 & 0xFFFF , V_30 ,
V_31 >> 24 , V_31 & 0xFFFFFF ) ;
}
if ( V_6 . V_32 & V_38 &&
V_6 . V_34 & V_39 ) {
V_40 . V_41 = F_28 ;
V_40 . V_42 = F_28 ;
}
#ifdef F_36
if ( V_6 . V_32 & V_38 &&
V_6 . V_34 & V_39 ) {
T_5 V_43 ;
F_29 ( V_44 , V_43 ) ;
V_43 = F_37 ( V_43 , V_45 ) ;
V_46 = V_43 ;
F_33 ( L_4 ,
V_46 ) ;
}
F_38 ( V_47 , F_24 , V_48 ,
L_5 ) ;
#endif
#ifdef F_39
V_49 = 1 ;
#endif
#if F_40 ( V_50 ) && F_41 ( V_51 )
V_52 . V_53 = F_16 ;
V_52 . V_54 = F_18 ;
#endif
F_42 ( L_6 ) ;
if ( F_43 ( V_55 ) )
V_40 . V_56 = F_23 ;
#if F_40 ( V_50 )
V_40 . V_57 = V_58 ;
#endif
}
