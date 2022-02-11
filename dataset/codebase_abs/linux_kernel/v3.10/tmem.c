static int T_1 F_1 ( char * V_1 )
{
V_2 = true ;
return 1 ;
}
static inline int F_2 ( T_2 V_3 , T_2 V_4 , struct V_5 V_6 ,
T_2 V_7 , unsigned long V_8 , T_2 V_9 , T_2 V_10 , T_2 V_11 )
{
struct V_12 V_13 ;
int V_14 = 0 ;
V_13 . V_15 = V_3 ;
V_13 . V_16 = V_4 ;
V_13 . V_17 . V_18 . V_6 [ 0 ] = V_6 . V_6 [ 0 ] ;
V_13 . V_17 . V_18 . V_6 [ 1 ] = V_6 . V_6 [ 1 ] ;
V_13 . V_17 . V_18 . V_6 [ 2 ] = V_6 . V_6 [ 2 ] ;
V_13 . V_17 . V_18 . V_7 = V_7 ;
V_13 . V_17 . V_18 . V_9 = V_9 ;
V_13 . V_17 . V_18 . V_10 = V_10 ;
V_13 . V_17 . V_18 . V_11 = V_11 ;
F_3 ( V_13 . V_17 . V_18 . V_8 , ( void * ) V_8 ) ;
V_14 = F_4 ( & V_13 ) ;
return V_14 ;
}
static int F_5 ( struct V_19 V_20 ,
T_2 V_21 , unsigned long V_22 )
{
struct V_12 V_13 ;
int V_14 = 0 , V_23 ;
for ( V_23 = 0 ; V_22 != 1 ; V_23 ++ )
V_22 >>= 1 ;
V_21 |= ( V_23 - 12 ) << V_24 ;
V_21 |= V_25 << V_26 ;
V_13 . V_15 = V_27 ;
V_13 . V_17 . V_28 . V_20 [ 0 ] = V_20 . V_29 ;
V_13 . V_17 . V_28 . V_20 [ 1 ] = V_20 . V_30 ;
V_13 . V_17 . V_28 . V_21 = V_21 ;
V_14 = F_4 ( & V_13 ) ;
return V_14 ;
}
static int F_6 ( T_2 V_16 , struct V_5 V_6 ,
T_2 V_7 , unsigned long V_31 )
{
unsigned long V_8 = F_7 () ? F_8 ( V_31 ) : V_31 ;
return F_2 ( V_32 , V_16 , V_6 , V_7 ,
V_8 , 0 , 0 , 0 ) ;
}
static int F_9 ( T_2 V_16 , struct V_5 V_6 ,
T_2 V_7 , unsigned long V_31 )
{
unsigned long V_8 = F_7 () ? F_8 ( V_31 ) : V_31 ;
return F_2 ( V_33 , V_16 , V_6 , V_7 ,
V_8 , 0 , 0 , 0 ) ;
}
static int F_10 ( T_2 V_16 , struct V_5 V_6 , T_2 V_7 )
{
return F_2 ( V_34 , V_16 , V_6 , V_7 ,
0 , 0 , 0 , 0 ) ;
}
static int F_11 ( T_2 V_16 , struct V_5 V_6 )
{
return F_2 ( V_35 , V_16 , V_6 , 0 , 0 , 0 , 0 , 0 ) ;
}
static int F_12 ( T_2 V_16 )
{
struct V_5 V_6 = { { 0 } } ;
return F_2 ( V_36 , V_16 , V_6 , 0 , 0 , 0 , 0 , 0 ) ;
}
static void F_13 ( int V_37 , struct V_38 V_39 ,
T_3 V_7 , struct V_40 * V_40 )
{
T_2 V_41 = ( T_2 ) V_7 ;
struct V_5 V_6 = * (struct V_5 * ) & V_39 ;
unsigned long V_31 = F_14 ( V_40 ) ;
if ( V_37 < 0 )
return;
if ( V_41 != V_7 )
return;
F_15 () ;
( void ) F_6 ( ( T_2 ) V_37 , V_6 , V_41 , V_31 ) ;
}
static int F_16 ( int V_37 , struct V_38 V_39 ,
T_3 V_7 , struct V_40 * V_40 )
{
T_2 V_41 = ( T_2 ) V_7 ;
struct V_5 V_6 = * (struct V_5 * ) & V_39 ;
unsigned long V_31 = F_14 ( V_40 ) ;
int V_42 ;
if ( V_37 < 0 )
return - 1 ;
if ( V_41 != V_7 )
return - 1 ;
V_42 = F_9 ( ( T_2 ) V_37 , V_6 , V_41 , V_31 ) ;
if ( V_42 == 1 )
return 0 ;
else
return - 1 ;
}
static void F_17 ( int V_37 , struct V_38 V_39 ,
T_3 V_7 )
{
T_2 V_41 = ( T_2 ) V_7 ;
struct V_5 V_6 = * (struct V_5 * ) & V_39 ;
if ( V_37 < 0 )
return;
if ( V_41 != V_7 )
return;
( void ) F_10 ( ( T_2 ) V_37 , V_6 , V_41 ) ;
}
static void F_18 ( int V_37 , struct V_38 V_39 )
{
struct V_5 V_6 = * (struct V_5 * ) & V_39 ;
if ( V_37 < 0 )
return;
( void ) F_11 ( ( T_2 ) V_37 , V_6 ) ;
}
static void F_19 ( int V_37 )
{
if ( V_37 < 0 )
return;
( void ) F_12 ( ( T_2 ) V_37 ) ;
}
static int F_20 ( T_4 V_22 )
{
struct V_19 V_43 = V_44 ;
return F_5 ( V_43 , 0 , V_22 ) ;
}
static int F_21 ( char * V_20 , T_4 V_22 )
{
struct V_19 V_45 ;
V_45 . V_29 = * ( V_46 * ) V_20 ;
V_45 . V_30 = * ( V_46 * ) ( & V_20 [ 8 ] ) ;
return F_5 ( V_45 , V_47 , V_22 ) ;
}
static inline struct V_5 F_22 ( unsigned type , T_2 V_41 )
{
struct V_5 V_6 = { . V_6 = { 0 } } ;
V_6 . V_6 [ 0 ] = F_23 ( type , V_41 ) ;
return V_6 ;
}
static int F_24 ( unsigned type , T_3 V_48 ,
struct V_40 * V_40 )
{
V_46 V_49 = ( V_46 ) V_48 ;
T_2 V_41 = ( T_2 ) V_48 ;
unsigned long V_31 = F_14 ( V_40 ) ;
int V_37 = V_50 ;
int V_42 ;
if ( V_37 < 0 )
return - 1 ;
if ( V_49 != V_41 )
return - 1 ;
F_15 () ;
V_42 = F_6 ( V_37 , F_22 ( type , V_41 ) , F_25 ( V_41 ) , V_31 ) ;
if ( V_42 == 1 )
return 0 ;
else
return - 1 ;
}
static int F_26 ( unsigned type , T_3 V_48 ,
struct V_40 * V_40 )
{
V_46 V_49 = ( V_46 ) V_48 ;
T_2 V_41 = ( T_2 ) V_48 ;
unsigned long V_31 = F_14 ( V_40 ) ;
int V_37 = V_50 ;
int V_42 ;
if ( V_37 < 0 )
return - 1 ;
if ( V_49 != V_41 )
return - 1 ;
V_42 = F_9 ( V_37 , F_22 ( type , V_41 ) , F_25 ( V_41 ) , V_31 ) ;
if ( V_42 == 1 )
return 0 ;
else
return - 1 ;
}
static void F_27 ( unsigned type , T_3 V_48 )
{
V_46 V_49 = ( V_46 ) V_48 ;
T_2 V_41 = ( T_2 ) V_48 ;
int V_37 = V_50 ;
if ( V_37 < 0 )
return;
if ( V_49 != V_41 )
return;
( void ) F_10 ( V_37 , F_22 ( type , V_41 ) , F_25 ( V_41 ) ) ;
}
static void F_28 ( unsigned type )
{
int V_37 = V_50 ;
int V_41 ;
if ( V_37 < 0 )
return;
for ( V_41 = V_51 ; V_41 >= 0 ; V_41 -- )
( void ) F_11 ( V_37 , F_22 ( type , V_41 ) ) ;
}
static void F_29 ( unsigned V_52 )
{
struct V_19 V_53 = V_44 ;
if ( V_50 < 0 )
V_50 =
F_5 ( V_53 , V_54 , V_55 ) ;
}
static int F_30 ( void )
{
if ( ! F_31 () )
return 0 ;
#ifdef F_32
if ( V_2 && V_56 ) {
char * V_1 = L_1 ;
struct V_57 * V_58 ;
V_50 = - 1 ;
V_58 = F_33 ( & V_59 ) ;
if ( F_34 ( V_58 ) || V_58 ) {
if ( F_34 ( V_58 ) )
return F_35 ( V_58 ) ;
V_1 = L_2 ;
}
F_36 ( V_60 L_3
L_4 , V_1 ) ;
}
#endif
#ifdef F_37
F_38 ( sizeof( struct V_38 ) != sizeof( struct V_5 ) ) ;
if ( V_2 && V_61 ) {
char * V_1 = L_1 ;
struct V_62 * V_58 =
F_39 ( & V_63 ) ;
if ( V_58 )
V_1 = L_5 ;
F_36 ( V_60 L_6
L_4 , V_1 ) ;
}
#endif
#ifdef F_40
if ( ! V_56 ) {
V_64 = false ;
V_65 = false ;
}
F_41 ( V_65 , V_64 ) ;
#endif
return 0 ;
}
