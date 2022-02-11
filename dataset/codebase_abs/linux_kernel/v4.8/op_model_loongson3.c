static void F_1 ( void * V_1 )
{
F_2 ( 0 ) ;
F_3 ( 0 ) ;
F_4 ( 0xc0000000 ) ;
F_5 ( 0x40000000 ) ;
}
static void F_6 ( struct V_2 * V_3 )
{
unsigned int V_4 = 0 ;
unsigned int V_5 = 0 ;
V_6 . V_7 = 0 ;
V_6 . V_8 = 0 ;
if ( V_3 [ 0 ] . V_9 ) {
V_4 |= F_7 ( 0 , V_3 [ 0 ] . V_10 ) |
V_11 ;
if ( V_3 [ 0 ] . V_12 )
V_4 |= V_13 ;
if ( V_3 [ 0 ] . V_14 )
V_4 |= V_15 ;
V_6 . V_7 = 0x8000000000000000ULL - V_3 [ 0 ] . V_16 ;
}
if ( V_3 [ 1 ] . V_9 ) {
V_5 |= F_7 ( 1 , V_3 [ 1 ] . V_10 ) |
V_11 ;
if ( V_3 [ 1 ] . V_12 )
V_5 |= V_13 ;
if ( V_3 [ 1 ] . V_14 )
V_5 |= V_15 ;
V_6 . V_8 = 0x8000000000000000ULL - V_3 [ 1 ] . V_16 ;
}
if ( V_3 [ 0 ] . V_9 )
V_4 |= V_17 ;
if ( V_3 [ 1 ] . V_9 )
V_5 |= V_17 ;
V_6 . V_4 = V_4 ;
V_6 . V_5 = V_5 ;
V_6 . V_18 = V_3 [ 0 ] . V_9 ;
V_6 . V_19 = V_3 [ 1 ] . V_9 ;
}
static void F_8 ( void * args )
{
T_1 V_20 , V_21 ;
V_20 = V_6 . V_7 ;
V_21 = V_6 . V_8 ;
F_2 ( V_20 ) ;
F_3 ( V_21 ) ;
}
static void F_9 ( void * args )
{
V_6 . V_4 |= ( V_22 | V_23 ) ;
V_6 . V_5 |= ( V_22 | V_23 ) ;
if ( V_6 . V_18 )
F_4 ( V_6 . V_4 ) ;
if ( V_6 . V_19 )
F_5 ( V_6 . V_5 ) ;
}
static void F_10 ( void * args )
{
F_4 ( 0xc0000000 ) ;
F_5 ( 0x40000000 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
}
static int F_11 ( void )
{
unsigned long V_24 ;
T_1 V_25 , V_26 ;
T_2 V_27 , V_28 = V_29 ;
struct V_30 * V_31 = F_12 () ;
V_27 = F_13 () ;
if ( ! ( V_27 & V_32 ) )
return V_28 ;
V_25 = F_14 () ;
V_26 = F_15 () ;
F_16 ( V_24 ) ;
if ( V_25 & V_33 ) {
if ( V_6 . V_18 )
F_17 ( V_31 , 0 ) ;
V_25 = V_6 . V_7 ;
}
if ( V_26 & V_33 ) {
if ( V_6 . V_19 )
F_17 ( V_31 , 1 ) ;
V_26 = V_6 . V_8 ;
}
F_18 ( V_24 ) ;
F_2 ( V_25 ) ;
F_3 ( V_26 ) ;
if ( ! ( V_27 & V_34 ) )
V_28 = V_35 ;
return V_28 ;
}
static int F_19 ( unsigned int V_36 )
{
F_4 ( V_6 . V_4 ) ;
F_5 ( V_6 . V_5 ) ;
return 0 ;
}
static int F_20 ( unsigned int V_36 )
{
F_4 ( 0xc0000000 ) ;
F_5 ( 0x40000000 ) ;
return 0 ;
}
static int T_3 F_21 ( void )
{
F_22 ( F_1 , NULL , 1 ) ;
F_23 ( V_37 ,
L_1 ,
F_19 , F_20 ) ;
V_38 = V_39 ;
V_39 = F_11 ;
return 0 ;
}
static void F_24 ( void )
{
F_22 ( F_1 , NULL , 1 ) ;
F_25 ( V_37 ) ;
V_39 = V_38 ;
}
