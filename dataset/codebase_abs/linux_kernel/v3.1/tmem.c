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
static int T_2 F_11 ( char * V_34 )
{
V_35 = 1 ;
return 1 ;
}
static int F_12 ( T_1 V_14 )
{
struct V_3 V_4 = { { 0 } } ;
return F_1 ( V_36 , V_14 , V_4 , 0 , 0 , 0 , 0 , 0 ) ;
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
( void ) F_12 ( ( T_1 ) V_37 ) ;
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
static int T_2 F_22 ( char * V_34 )
{
V_48 = 0 ;
return 1 ;
}
static inline struct V_3 F_23 ( unsigned type , T_1 V_41 )
{
struct V_3 V_4 = { . V_4 = { 0 } } ;
V_4 . V_4 [ 0 ] = F_24 ( type , V_41 ) ;
return V_4 ;
}
static int F_25 ( unsigned type , T_3 V_49 ,
struct V_40 * V_40 )
{
V_46 V_50 = ( V_46 ) V_49 ;
T_1 V_41 = ( T_1 ) V_49 ;
unsigned long V_29 = F_14 ( V_40 ) ;
int V_37 = V_51 ;
int V_42 ;
if ( V_37 < 0 )
return - 1 ;
if ( V_50 != V_41 )
return - 1 ;
F_15 () ;
V_42 = F_5 ( V_37 , F_23 ( type , V_41 ) , F_26 ( V_41 ) , V_29 ) ;
if ( V_42 == 1 )
return 0 ;
else
return - 1 ;
}
static int F_27 ( unsigned type , T_3 V_49 ,
struct V_40 * V_40 )
{
V_46 V_50 = ( V_46 ) V_49 ;
T_1 V_41 = ( T_1 ) V_49 ;
unsigned long V_29 = F_14 ( V_40 ) ;
int V_37 = V_51 ;
int V_42 ;
if ( V_37 < 0 )
return - 1 ;
if ( V_50 != V_41 )
return - 1 ;
V_42 = F_8 ( V_37 , F_23 ( type , V_41 ) , F_26 ( V_41 ) , V_29 ) ;
if ( V_42 == 1 )
return 0 ;
else
return - 1 ;
}
static void F_28 ( unsigned type , T_3 V_49 )
{
V_46 V_50 = ( V_46 ) V_49 ;
T_1 V_41 = ( T_1 ) V_49 ;
int V_37 = V_51 ;
if ( V_37 < 0 )
return;
if ( V_50 != V_41 )
return;
( void ) F_9 ( V_37 , F_23 ( type , V_41 ) , F_26 ( V_41 ) ) ;
}
static void F_29 ( unsigned type )
{
int V_37 = V_51 ;
int V_41 ;
if ( V_37 < 0 )
return;
for ( V_41 = V_52 ; V_41 >= 0 ; V_41 -- )
( void ) F_10 ( V_37 , F_23 ( type , V_41 ) ) ;
}
static void F_30 ( unsigned V_53 )
{
struct V_17 V_54 = V_44 ;
if ( V_51 < 0 )
V_51 =
F_4 ( V_54 , V_55 , V_56 ) ;
}
static int T_2 F_31 ( char * V_34 )
{
V_57 = 0 ;
return 1 ;
}
static int T_2 F_32 ( void )
{
if ( ! F_33 () )
return 0 ;
#ifdef F_34
if ( V_35 && V_57 ) {
char * V_34 = L_1 ;
struct V_58 V_59 =
F_35 ( & V_60 ) ;
V_51 = - 1 ;
if ( V_59 . V_61 != NULL )
V_34 = L_2 ;
F_36 ( V_62 L_3
L_4 ) ;
}
#endif
#ifdef F_37
F_38 ( sizeof( struct V_38 ) != sizeof( struct V_3 ) ) ;
if ( V_35 && V_48 ) {
char * V_34 = L_1 ;
struct V_63 V_59 =
F_39 ( & V_64 ) ;
if ( V_59 . V_65 != NULL )
V_34 = L_5 ;
F_36 ( V_62 L_6
L_7 , V_34 ) ;
}
#endif
return 0 ;
}
