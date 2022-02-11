static void F_1 ( char V_1 )
{
if ( V_1 == '\n' )
F_1 ( '\r' ) ;
while ( F_2 ( & V_2 [ 0 ] ) & 0x80000000 )
;
F_3 ( V_3 , V_1 ) ;
F_4 ( & V_2 [ 0 ] , 0xa0000001 ) ;
}
void T_1 F_5 ( void )
{
#ifdef F_6
V_2 = ( V_4 V_5 V_6 * )
( V_7 - V_8 +
V_9 ) ;
V_3 = ( V_10 V_5 V_6 * )
( F_2 ( & V_2 [ 1 ] ) - V_8 +
V_9 ) ;
#else
V_2 = ( V_4 V_5 V_6 * )
V_7 ;
V_3 = ( V_10 V_5 V_6 * ) F_2 ( & V_2 [ 1 ] ) ;
#endif
if ( V_2 ) {
#ifdef F_7
F_8 ( 1 , 0xf0000000 , 0xf0000000 , 1024 * 1024 , V_11 ) ;
#endif
V_12 = F_1 ;
}
}
static void F_9 ( struct V_13 * V_14 )
{
struct V_15 * V_16 =
F_10 ( V_14 , struct V_15 , V_14 ) ;
struct V_17 V_5 * V_18 = V_14 -> V_19 ;
V_16 -> V_20 = F_2 ( & V_18 -> V_21 ) ;
}
static int F_11 ( struct V_22 * V_23 , unsigned int V_24 )
{
struct V_13 * V_14 = F_12 ( V_23 ) ;
struct V_17 V_5 * V_18 = V_14 -> V_19 ;
V_4 V_25 ;
V_25 = 1 << ( 31 - V_24 ) ;
return ! ! ( F_2 ( & V_18 -> V_21 ) & V_25 ) ;
}
static void F_13 ( struct V_13 * V_14 , V_4 V_25 ,
int V_26 )
{
struct V_15 * V_16 = F_14 ( & V_14 -> V_23 ) ;
struct V_17 V_5 * V_18 = V_14 -> V_19 ;
if ( V_26 )
V_16 -> V_20 |= V_25 ;
else
V_16 -> V_20 &= ~ V_25 ;
F_4 ( & V_18 -> V_21 , V_16 -> V_20 ) ;
}
static void F_15 ( struct V_22 * V_23 , unsigned int V_24 , int V_26 )
{
struct V_13 * V_14 = F_12 ( V_23 ) ;
struct V_15 * V_16 = F_14 ( V_23 ) ;
unsigned long V_27 ;
V_4 V_25 = 1 << ( 31 - V_24 ) ;
F_16 ( & V_16 -> V_28 , V_27 ) ;
F_13 ( V_14 , V_25 , V_26 ) ;
F_17 ( & V_16 -> V_28 , V_27 ) ;
}
static int F_18 ( struct V_22 * V_23 , unsigned int V_24 , int V_29 )
{
struct V_13 * V_14 = F_12 ( V_23 ) ;
struct V_15 * V_16 = F_14 ( V_23 ) ;
struct V_17 V_5 * V_18 = V_14 -> V_19 ;
unsigned long V_27 ;
V_4 V_25 = 1 << ( 31 - V_24 ) ;
F_16 ( & V_16 -> V_28 , V_27 ) ;
F_19 ( & V_18 -> V_30 , V_25 ) ;
F_13 ( V_14 , V_25 , V_29 ) ;
F_17 ( & V_16 -> V_28 , V_27 ) ;
return 0 ;
}
static int F_20 ( struct V_22 * V_23 , unsigned int V_24 )
{
struct V_13 * V_14 = F_12 ( V_23 ) ;
struct V_15 * V_16 = F_14 ( V_23 ) ;
struct V_17 V_5 * V_18 = V_14 -> V_19 ;
unsigned long V_27 ;
V_4 V_25 = 1 << ( 31 - V_24 ) ;
F_16 ( & V_16 -> V_28 , V_27 ) ;
F_21 ( & V_18 -> V_30 , V_25 ) ;
F_17 ( & V_16 -> V_28 , V_27 ) ;
return 0 ;
}
int F_22 ( struct V_31 * V_32 )
{
struct V_15 * V_16 ;
struct V_13 * V_14 ;
struct V_22 * V_23 ;
V_16 = F_23 ( sizeof( * V_16 ) , V_33 ) ;
if ( ! V_16 )
return - V_34 ;
F_24 ( & V_16 -> V_28 ) ;
V_14 = & V_16 -> V_14 ;
V_23 = & V_14 -> V_23 ;
V_14 -> V_35 = F_9 ;
V_23 -> V_36 = 32 ;
V_23 -> V_37 = F_20 ;
V_23 -> V_38 = F_18 ;
V_23 -> V_39 = F_11 ;
V_23 -> V_40 = F_15 ;
return F_25 ( V_32 , V_14 , V_16 ) ;
}
