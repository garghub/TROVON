static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 )
V_2 = F_2 ( NULL , NULL , L_2 ) ;
if ( ! V_2 )
return - V_3 ;
F_3 () ;
F_4 ( V_2 ) ;
return 0 ;
}
static void F_5 ( char V_4 )
{
if ( V_4 == '\n' )
F_5 ( '\r' ) ;
while ( F_6 ( & V_5 [ 0 ] ) & 0x80000000 )
;
F_7 ( V_6 , V_4 ) ;
F_8 ( & V_5 [ 0 ] , 0xa0000001 ) ;
}
void T_1 F_9 ( void )
{
#ifdef F_10
V_5 = ( V_7 V_8 V_9 * )
( V_10 - V_11 +
V_12 ) ;
V_6 = ( V_13 V_8 V_9 * )
( F_6 ( & V_5 [ 1 ] ) - V_11 +
V_12 ) ;
#else
V_5 = ( V_7 V_8 V_9 * )
V_10 ;
V_6 = ( V_13 V_8 V_9 * ) F_6 ( & V_5 [ 1 ] ) ;
#endif
if ( V_5 ) {
#ifdef F_11
F_12 ( 1 , 0xf0000000 , 0xf0000000 , 1024 * 1024 , V_14 ) ;
#endif
V_15 = F_5 ;
}
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_19 =
F_14 ( V_17 , struct V_18 , V_17 ) ;
struct V_20 V_8 * V_21 = V_17 -> V_22 ;
V_19 -> V_23 = F_6 ( & V_21 -> V_24 ) ;
}
static int F_15 ( struct V_25 * V_26 , unsigned int V_27 )
{
struct V_16 * V_17 = F_16 ( V_26 ) ;
struct V_20 V_8 * V_21 = V_17 -> V_22 ;
V_7 V_28 ;
V_28 = 1 << ( 31 - V_27 ) ;
return ! ! ( F_6 ( & V_21 -> V_24 ) & V_28 ) ;
}
static void F_17 ( struct V_16 * V_17 , V_7 V_28 ,
int V_29 )
{
struct V_18 * V_19 = F_18 ( & V_17 -> V_26 ) ;
struct V_20 V_8 * V_21 = V_17 -> V_22 ;
if ( V_29 )
V_19 -> V_23 |= V_28 ;
else
V_19 -> V_23 &= ~ V_28 ;
F_8 ( & V_21 -> V_24 , V_19 -> V_23 ) ;
}
static void F_19 ( struct V_25 * V_26 , unsigned int V_27 , int V_29 )
{
struct V_16 * V_17 = F_16 ( V_26 ) ;
struct V_18 * V_19 = F_18 ( V_26 ) ;
unsigned long V_30 ;
V_7 V_28 = 1 << ( 31 - V_27 ) ;
F_20 ( & V_19 -> V_31 , V_30 ) ;
F_17 ( V_17 , V_28 , V_29 ) ;
F_21 ( & V_19 -> V_31 , V_30 ) ;
}
static int F_22 ( struct V_25 * V_26 , unsigned int V_27 , int V_32 )
{
struct V_16 * V_17 = F_16 ( V_26 ) ;
struct V_18 * V_19 = F_18 ( V_26 ) ;
struct V_20 V_8 * V_21 = V_17 -> V_22 ;
unsigned long V_30 ;
V_7 V_28 = 1 << ( 31 - V_27 ) ;
F_20 ( & V_19 -> V_31 , V_30 ) ;
F_23 ( & V_21 -> V_33 , V_28 ) ;
F_17 ( V_17 , V_28 , V_32 ) ;
F_21 ( & V_19 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_24 ( struct V_25 * V_26 , unsigned int V_27 )
{
struct V_16 * V_17 = F_16 ( V_26 ) ;
struct V_18 * V_19 = F_18 ( V_26 ) ;
struct V_20 V_8 * V_21 = V_17 -> V_22 ;
unsigned long V_30 ;
V_7 V_28 = 1 << ( 31 - V_27 ) ;
F_20 ( & V_19 -> V_31 , V_30 ) ;
F_25 ( & V_21 -> V_33 , V_28 ) ;
F_21 ( & V_19 -> V_31 , V_30 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_16 * V_17 ;
struct V_25 * V_26 ;
V_19 = F_27 ( sizeof( * V_19 ) , V_34 ) ;
if ( ! V_19 )
return - V_35 ;
F_28 ( & V_19 -> V_31 ) ;
V_17 = & V_19 -> V_17 ;
V_26 = & V_17 -> V_26 ;
V_17 -> V_36 = F_13 ;
V_26 -> V_37 = 32 ;
V_26 -> V_38 = F_24 ;
V_26 -> V_39 = F_22 ;
V_26 -> V_40 = F_15 ;
V_26 -> V_41 = F_19 ;
return F_29 ( V_2 , V_17 , V_19 ) ;
}
