static inline int F_1 ( void )
{
T_1 V_1 , V_2 , V_3 , V_4 ;
F_2 ( V_5 , V_1 , V_2 , V_3 , V_4 ) ;
return V_1 != ( T_1 ) - 1 && V_2 == V_6 ;
}
static unsigned long F_3 ( void )
{
return V_7 ;
}
static T_2 int F_4 ( char * V_8 )
{
V_9 = 0 ;
return 0 ;
}
static unsigned long long F_5 ( void )
{
unsigned long long V_10 ;
V_10 = F_6 ( F_7 () , V_11 . V_12 ,
V_11 . V_13 ) ;
V_10 -= V_11 . V_14 ;
return V_10 ;
}
static void T_2 F_8 ( void )
{
struct V_15 * V_16 = & V_11 ;
unsigned long long V_17 = F_7 () ;
F_9 ( & V_16 -> V_12 , & V_16 -> V_13 ,
V_7 , V_18 , 0 ) ;
V_16 -> V_14 = F_6 ( V_17 , V_16 -> V_12 ,
V_16 -> V_13 ) ;
V_19 . V_20 = F_5 ;
F_10 ( L_1 , V_16 -> V_14 ) ;
}
static void T_2 F_11 ( void )
{
V_21 . V_22 = L_2 ;
V_23 . V_24 = V_25 ;
if ( V_7 && V_9 )
F_8 () ;
}
static void T_2 F_12 ( void )
{
F_13 ( V_26 ) ;
F_13 ( V_27 ) ;
}
static void T_2 F_14 ( void )
{
T_1 V_1 , V_2 , V_3 , V_4 ;
T_3 V_28 , V_29 ;
F_2 ( V_30 , V_1 , V_2 , V_3 , V_4 ) ;
if ( V_2 != V_31 ) {
V_28 = V_29 = V_1 | ( ( ( T_3 ) V_2 ) << 32 ) ;
F_15 ( V_29 , 1000 ) ;
F_16 ( V_29 >> 32 ) ;
F_10 ( L_3 ,
( unsigned long ) V_29 / 1000 ,
( unsigned long ) V_29 % 1000 ) ;
if ( ! V_32 ) {
F_15 ( V_28 , V_33 ) ;
V_32 = V_28 ;
}
V_7 = V_29 ;
V_34 . V_35 = F_3 ;
V_34 . V_36 = F_3 ;
#ifdef F_17
V_37 = V_3 / V_33 ;
F_10 ( L_4 ,
V_3 ) ;
#endif
} else {
F_18 ( L_5 ) ;
}
F_11 () ;
#ifdef F_19
V_38 = 1 ;
#endif
F_12 () ;
}
static T_1 T_2 F_20 ( void )
{
if ( F_21 ( V_39 ) ) {
unsigned int V_1 ;
unsigned int V_40 [ 3 ] ;
F_22 ( V_41 , & V_1 , & V_40 [ 0 ] ,
& V_40 [ 1 ] , & V_40 [ 2 ] ) ;
if ( ! memcmp ( V_40 , L_6 , 12 ) )
return V_41 ;
} else if ( V_42 && F_23 ( L_7 ) &&
F_1 () )
return 1 ;
return 0 ;
}
static bool T_2 F_24 ( void )
{
T_1 V_1 , V_2 , V_3 , V_4 ;
F_2 ( V_43 , V_1 , V_2 , V_3 , V_4 ) ;
return ( V_1 & ( 1 << V_44 ) ) == 0 &&
( V_1 & ( 1 << V_45 ) ) != 0 ;
}
