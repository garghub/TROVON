static inline int F_1 ( T_1 V_1 , T_1 V_2 , struct V_3 V_4 ,
T_1 V_5 , unsigned long V_6 , T_1 V_7 , T_1 V_8 , T_1 V_9 )
{
struct V_10 V_11 ;
int V_12 = 0 ;
V_11 . V_13 = V_1 ;
V_11 . V_14 = V_2 ;
V_11 . V_15 . V_16 . V_4 [ 0 ] = V_4 . V_4 [ 0 ] ;
V_11 . V_15 . V_16 . V_4 [ 1 ] = V_4 . V_4 [ 1 ] ;
V_11 . V_15 . V_16 . V_4 [ 2 ] = V_4 . V_4 [ 2 ] ;
V_11 . V_15 . V_16 . V_5 = V_5 ;
V_11 . V_15 . V_16 . V_7 = V_7 ;
V_11 . V_15 . V_16 . V_8 = V_8 ;
V_11 . V_15 . V_16 . V_9 = V_9 ;
F_2 ( V_11 . V_15 . V_16 . V_6 , ( void * ) V_6 ) ;
V_12 = F_3 ( & V_11 ) ;
return V_12 ;
}
static int F_4 ( struct V_17 V_18 ,
T_1 V_19 , unsigned long V_20 )
{
struct V_10 V_11 ;
int V_12 = 0 , V_21 ;
for ( V_21 = 0 ; V_20 != 1 ; V_21 ++ )
V_20 >>= 1 ;
V_19 |= ( V_21 - 12 ) << V_22 ;
V_19 |= V_23 << V_24 ;
V_11 . V_13 = V_25 ;
V_11 . V_15 . V_26 . V_18 [ 0 ] = V_18 . V_27 ;
V_11 . V_15 . V_26 . V_18 [ 1 ] = V_18 . V_28 ;
V_11 . V_15 . V_26 . V_19 = V_19 ;
V_12 = F_3 ( & V_11 ) ;
return V_12 ;
}
static int F_5 ( T_1 V_14 , struct V_3 V_4 ,
T_1 V_5 , unsigned long V_29 )
{
unsigned long V_6 = F_6 () ? F_7 ( V_29 ) : V_29 ;
return F_1 ( V_30 , V_14 , V_4 , V_5 ,
V_6 , 0 , 0 , 0 ) ;
}
static int F_8 ( T_1 V_14 , struct V_3 V_4 ,
T_1 V_5 , unsigned long V_29 )
{
unsigned long V_6 = F_6 () ? F_7 ( V_29 ) : V_29 ;
return F_1 ( V_31 , V_14 , V_4 , V_5 ,
V_6 , 0 , 0 , 0 ) ;
}
static int F_9 ( T_1 V_14 , struct V_3 V_4 , T_1 V_5 )
{
return F_1 ( V_32 , V_14 , V_4 , V_5 ,
0 , 0 , 0 , 0 ) ;
}
static int F_10 ( T_1 V_14 , struct V_3 V_4 )
{
return F_1 ( V_33 , V_14 , V_4 , 0 , 0 , 0 , 0 , 0 ) ;
}
static int F_11 ( T_1 V_14 )
{
struct V_3 V_4 = { { 0 } } ;
return F_1 ( V_34 , V_14 , V_4 , 0 , 0 , 0 , 0 , 0 ) ;
}
static int T_2 F_12 ( char * V_35 )
{
V_36 = 1 ;
return 1 ;
}
static void F_13 ( int V_37 , struct V_38 V_39 ,
T_3 V_5 , struct V_40 * V_40 )
{
T_1 V_41 = ( T_1 ) V_5 ;
struct V_3 V_4 = * (struct V_3 * ) & V_39 ;
unsigned long V_29 = F_14 ( V_40 ) ;
if ( V_37 < 0 )
return;
if ( V_41 != V_5 )
return;
F_15 () ;
( void ) F_5 ( ( T_1 ) V_37 , V_4 , V_41 , V_29 ) ;
}
static int F_16 ( int V_37 , struct V_38 V_39 ,
T_3 V_5 , struct V_40 * V_40 )
{
T_1 V_41 = ( T_1 ) V_5 ;
struct V_3 V_4 = * (struct V_3 * ) & V_39 ;
unsigned long V_29 = F_14 ( V_40 ) ;
int V_42 ;
if ( V_37 < 0 )
return - 1 ;
if ( V_41 != V_5 )
return - 1 ;
V_42 = F_8 ( ( T_1 ) V_37 , V_4 , V_41 , V_29 ) ;
if ( V_42 == 1 )
return 0 ;
else
return - 1 ;
}
static void F_17 ( int V_37 , struct V_38 V_39 ,
T_3 V_5 )
{
T_1 V_41 = ( T_1 ) V_5 ;
struct V_3 V_4 = * (struct V_3 * ) & V_39 ;
if ( V_37 < 0 )
return;
if ( V_41 != V_5 )
return;
( void ) F_9 ( ( T_1 ) V_37 , V_4 , V_41 ) ;
}
static void F_18 ( int V_37 , struct V_38 V_39 )
{
struct V_3 V_4 = * (struct V_3 * ) & V_39 ;
if ( V_37 < 0 )
return;
( void ) F_10 ( ( T_1 ) V_37 , V_4 ) ;
}
static void F_19 ( int V_37 )
{
if ( V_37 < 0 )
return;
( void ) F_11 ( ( T_1 ) V_37 ) ;
}
static int F_20 ( T_4 V_20 )
{
struct V_17 V_43 = V_44 ;
return F_4 ( V_43 , 0 , V_20 ) ;
}
static int F_21 ( char * V_18 , T_4 V_20 )
{
struct V_17 V_45 ;
V_45 . V_27 = * ( V_46 * ) V_18 ;
V_45 . V_28 = * ( V_46 * ) ( & V_18 [ 8 ] ) ;
return F_4 ( V_45 , V_47 , V_20 ) ;
}
static int T_2 F_22 ( char * V_35 )
{
V_48 = 0 ;
return 1 ;
}
static int T_2 F_23 ( void )
{
struct V_49 V_50 ;
if ( ! F_24 () )
return 0 ;
#ifdef F_25
F_26 ( sizeof( struct V_38 ) != sizeof( struct V_3 ) ) ;
if ( V_36 && V_48 ) {
char * V_35 = L_1 ;
V_50 = F_27 ( & V_51 ) ;
if ( V_50 . V_52 != NULL )
V_35 = L_2 ;
F_28 ( V_53 L_3
L_4 , V_35 ) ;
}
#endif
return 0 ;
}
