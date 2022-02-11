static int F_1 ( int V_1 , int V_2 ,
void (* F_2) ( int V_1 , unsigned char V_3 ) ,
void (* F_3) ( int V_1 )
)
{
T_1 * V_4 = V_5 [ V_1 ] -> V_4 ;
unsigned long V_6 ;
if ( V_4 == NULL )
return - V_7 ;
F_4 ( & V_4 -> V_8 , V_6 ) ;
if ( V_4 -> V_9 )
{
F_5 ( & V_4 -> V_8 , V_6 ) ;
return - V_10 ;
}
V_4 -> V_9 = 1 ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_4 -> V_11 = 1 ;
if ( V_2 & V_12 )
{
V_4 -> V_13 = 1 ;
V_4 -> V_14 = F_2 ;
}
return 0 ;
}
static void F_6 ( int V_1 )
{
T_1 * V_4 = V_5 [ V_1 ] -> V_4 ;
unsigned long V_6 ;
if ( V_4 == NULL )
return;
F_4 ( & V_4 -> V_8 , V_6 ) ;
V_4 -> V_11 = 0 ;
V_4 -> V_13 = 0 ;
V_4 -> V_9 = 0 ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
}
static int F_7 ( int V_1 , unsigned char V_15 )
{
T_1 * V_4 = V_5 [ V_1 ] -> V_4 ;
T_1 * V_16 ;
if ( V_4 == NULL )
return - V_7 ;
V_16 = V_5 [ V_4 -> V_17 ] -> V_4 ;
if ( V_16 -> V_13 > 0 ) {
if ( F_8 ( V_16 -> V_18 ) > 500 )
return 0 ;
V_16 -> V_14 ( V_16 -> V_18 , V_15 ) ;
}
return 1 ;
}
static inline int F_9 ( int V_1 )
{
return 0 ;
}
static int F_10 ( int V_1 )
{
T_1 * V_4 = V_5 [ V_1 ] -> V_4 ;
if ( V_4 == NULL )
return - V_7 ;
V_4 -> V_11 = 0 ;
return 0 ;
}
static inline int F_11 ( int V_1 , unsigned V_19 , void T_2 * V_20 )
{
return - V_21 ;
}
static void T_3 F_12 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
V_26 = F_13 () ;
if ( V_26 == - 1 )
{
F_14 ( V_27 L_1 ) ;
return;
}
V_25 = F_15 ( sizeof( struct V_24 ) , V_28 ) ;
if ( V_25 == NULL )
{
F_14 ( V_29 L_2 ) ;
F_16 ( V_26 ) ;
return;
}
V_30 = V_25 ;
V_5 [ V_26 ] = & V_25 -> V_31 [ 0 ] ;
V_32 = F_13 () ;
if ( V_32 == - 1 )
{
F_14 ( V_27 L_1 ) ;
F_17 ( V_25 ) ;
F_16 ( V_26 ) ;
return;
}
V_5 [ V_32 ] = & V_25 -> V_31 [ 1 ] ;
V_33 [ 0 ] = & V_25 -> V_34 [ 0 ] ;
memcpy ( ( char * ) V_5 [ V_26 ] , ( char * ) & V_35 ,
sizeof ( struct V_36 ) ) ;
V_33 [ 0 ] -> V_18 = V_26 ;
V_33 [ 0 ] -> V_17 = V_32 ;
V_33 [ 0 ] -> V_9 = V_33 [ 0 ] -> V_13 = 0 ;
V_33 [ 0 ] -> V_11 = 0 ;
V_33 [ 0 ] -> V_14 = NULL ;
F_18 ( & V_33 [ 0 ] -> V_8 ) ;
V_5 [ V_26 ] -> V_4 = V_33 [ 0 ] ;
V_5 [ V_26 ] -> V_37 = & V_25 -> V_38 [ 0 ] ;
V_39 . V_40 = V_26 ;
memcpy ( ( char * ) V_5 [ V_26 ] -> V_37 , ( char * ) & V_39 ,
sizeof ( struct V_41 ) ) ;
V_5 [ V_26 ] -> V_37 -> V_42 = L_3 ;
V_33 [ 1 ] = & V_25 -> V_34 [ 1 ] ;
memcpy ( ( char * ) V_5 [ V_32 ] , ( char * ) & V_43 ,
sizeof ( struct V_36 ) ) ;
V_33 [ 1 ] -> V_18 = V_32 ;
V_33 [ 1 ] -> V_17 = V_26 ;
V_33 [ 1 ] -> V_9 = V_33 [ 1 ] -> V_13 = 0 ;
V_33 [ 1 ] -> V_11 = 0 ;
V_33 [ 1 ] -> V_14 = NULL ;
F_18 ( & V_33 [ 1 ] -> V_8 ) ;
V_5 [ V_32 ] -> V_4 = V_33 [ 1 ] ;
V_5 [ V_32 ] -> V_37 = & V_25 -> V_38 [ 1 ] ;
V_39 . V_40 = V_32 ;
memcpy ( ( char * ) V_5 [ V_32 ] -> V_37 , ( char * ) & V_39 ,
sizeof ( struct V_41 ) ) ;
V_5 [ V_32 ] -> V_37 -> V_42 = L_4 ;
F_19 () ;
}
static inline int T_3 F_20 ( struct V_22 * V_23 )
{
return ( 1 ) ;
}
static void T_4 F_21 ( struct V_22 * V_23 )
{
F_16 ( V_26 ) ;
F_16 ( V_32 ) ;
F_17 ( V_30 ) ;
}
static int T_3 F_22 ( void )
{
F_14 ( L_5 ) ;
if ( ! F_20 ( & V_44 ) )
return - V_45 ;
F_12 ( & V_44 ) ;
return 0 ;
}
static void T_4 F_23 ( void )
{
F_21 ( & V_44 ) ;
}
