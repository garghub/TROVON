static T_1 T_2 F_1 ( void )
{
return ( T_1 ) ( V_1 - V_2 ) ;
}
static inline T_1 T_2 F_2 ( T_1 V_3 , T_3 V_4 , T_3 V_5 )
{
return ( V_3 * V_4 ) >> V_5 ;
}
unsigned long long T_2 F_3 ( void )
{
T_1 V_3 , V_6 ;
unsigned long V_7 ;
struct V_8 * V_9 ;
do {
V_7 = F_4 ( & V_10 . V_7 ) ;
V_9 = V_10 . V_11 + ( V_7 & 1 ) ;
V_3 = ( V_9 -> V_12 () - V_9 -> V_13 ) &
V_9 -> V_14 ;
V_6 = V_9 -> V_15 + F_2 ( V_3 , V_9 -> V_4 , V_9 -> V_5 ) ;
} while ( F_5 ( & V_10 . V_7 , V_7 ) );
return V_6 ;
}
static void F_6 ( struct V_8 * V_9 )
{
V_10 . V_11 [ 1 ] = * V_9 ;
F_7 ( & V_10 . V_7 ) ;
V_10 . V_11 [ 0 ] = * V_9 ;
F_7 ( & V_10 . V_7 ) ;
}
static void F_8 ( void )
{
T_1 V_3 ;
T_1 V_16 ;
struct V_8 V_9 ;
V_9 = V_10 . V_11 [ 0 ] ;
V_3 = V_10 . V_17 () ;
V_16 = V_9 . V_15 + F_2 ( ( V_3 - V_9 . V_13 ) & V_9 . V_14 , V_9 . V_4 , V_9 . V_5 ) ;
V_9 . V_15 = V_16 ;
V_9 . V_13 = V_3 ;
F_6 ( & V_9 ) ;
}
static enum V_18 F_9 ( struct V_19 * V_20 )
{
F_8 () ;
F_10 ( V_20 , V_10 . V_21 ) ;
return V_22 ;
}
void T_4
F_11 ( T_1 (* F_12)( void ) , int V_23 , unsigned long V_24 )
{
T_1 V_6 , V_25 , V_26 , V_27 , V_3 , V_16 ;
T_3 V_28 , V_29 ;
unsigned long V_30 ;
char V_31 ;
struct V_8 V_9 ;
if ( V_10 . V_24 > V_24 )
return;
F_13 ( ! F_14 () ) ;
F_15 ( & V_28 , & V_29 , V_24 , V_32 , 3600 ) ;
V_26 = F_16 ( V_23 ) ;
V_10 . V_24 = V_24 ;
V_25 = F_17 ( V_28 , V_29 , 0 , V_26 , NULL ) ;
V_10 . V_21 = F_18 ( V_25 ) ;
V_9 = V_10 . V_11 [ 0 ] ;
V_27 = F_12 () ;
V_3 = V_10 . V_17 () ;
V_16 = V_9 . V_15 + F_2 ( ( V_3 - V_9 . V_13 ) & V_9 . V_14 , V_9 . V_4 , V_9 . V_5 ) ;
V_10 . V_17 = F_12 ;
V_9 . V_12 = F_12 ;
V_9 . V_14 = V_26 ;
V_9 . V_4 = V_28 ;
V_9 . V_5 = V_29 ;
V_9 . V_13 = V_27 ;
V_9 . V_15 = V_16 ;
F_6 ( & V_9 ) ;
if ( V_33 . V_34 != NULL ) {
F_19 ( & V_33 , V_10 . V_21 , V_35 ) ;
}
V_30 = V_24 ;
if ( V_30 >= 4000000 ) {
V_30 /= 1000000 ;
V_31 = 'M' ;
} else {
if ( V_30 >= 1000 ) {
V_30 /= 1000 ;
V_31 = 'k' ;
} else {
V_31 = ' ' ;
}
}
V_6 = F_2 ( 1ULL , V_28 , V_29 ) ;
F_20 ( L_1 ,
V_23 , V_30 , V_31 , V_6 , V_25 ) ;
if ( V_36 > 0 || ( V_36 == - 1 && V_24 >= 1000000 ) )
F_21 () ;
F_22 ( L_2 , F_12 ) ;
}
void T_4 F_23 ( void )
{
if ( V_10 . V_17 == F_1 )
F_11 ( F_1 , V_37 , V_38 ) ;
F_8 () ;
F_24 ( & V_33 , V_39 , V_35 ) ;
V_33 . V_34 = F_9 ;
F_19 ( & V_33 , V_10 . V_21 , V_35 ) ;
}
static T_1 T_2 F_25 ( void )
{
unsigned long V_7 = F_4 ( & V_10 . V_7 ) ;
return V_10 . V_11 [ V_7 & 1 ] . V_13 ;
}
static int F_26 ( void )
{
struct V_8 * V_9 = & V_10 . V_11 [ 0 ] ;
F_8 () ;
F_27 ( & V_33 ) ;
V_9 -> V_12 = F_25 ;
return 0 ;
}
static void F_28 ( void )
{
struct V_8 * V_9 = & V_10 . V_11 [ 0 ] ;
V_9 -> V_13 = V_10 . V_17 () ;
F_19 ( & V_33 , V_10 . V_21 , V_35 ) ;
V_9 -> V_12 = V_10 . V_17 ;
}
static int T_4 F_29 ( void )
{
F_30 ( & V_40 ) ;
return 0 ;
}
