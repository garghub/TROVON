static void F_1 ( char V_1 )
{
T_1 T_2 * V_2 = ( T_1 T_2 V_3 * ) F_2 ( & V_4 [ 1 ] ) ;
if ( V_1 == '\n' )
F_1 ( '\r' ) ;
while ( F_2 ( & V_4 [ 0 ] ) & 0x80000000 )
;
F_3 ( V_2 , V_1 ) ;
F_4 ( & V_4 [ 0 ] , 0xa0000001 ) ;
}
void T_3 F_5 ( void )
{
if ( V_4 ) {
#ifdef F_6
F_7 ( 1 , 0xf0000000 , 0xf0000000 , 1024 * 1024 , V_5 ) ;
#endif
V_6 = F_1 ;
}
}
static void F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_9 ( & V_8 -> V_11 ) ;
struct V_12 T_2 * V_13 = V_8 -> V_14 ;
V_10 -> V_15 = F_2 ( & V_13 -> V_16 ) ;
}
static int F_10 ( struct V_17 * V_11 , unsigned int V_18 )
{
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_12 T_2 * V_13 = V_8 -> V_14 ;
T_4 V_19 ;
V_19 = 1 << ( 31 - V_18 ) ;
return ! ! ( F_2 ( & V_13 -> V_16 ) & V_19 ) ;
}
static void F_12 ( struct V_7 * V_8 , T_4 V_19 ,
int V_20 )
{
struct V_9 * V_10 = F_9 ( & V_8 -> V_11 ) ;
struct V_12 T_2 * V_13 = V_8 -> V_14 ;
if ( V_20 )
V_10 -> V_15 |= V_19 ;
else
V_10 -> V_15 &= ~ V_19 ;
F_4 ( & V_13 -> V_16 , V_10 -> V_15 ) ;
}
static void F_13 ( struct V_17 * V_11 , unsigned int V_18 , int V_20 )
{
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_9 * V_10 = F_9 ( V_11 ) ;
unsigned long V_21 ;
T_4 V_19 = 1 << ( 31 - V_18 ) ;
F_14 ( & V_10 -> V_22 , V_21 ) ;
F_12 ( V_8 , V_19 , V_20 ) ;
F_15 ( & V_10 -> V_22 , V_21 ) ;
}
static int F_16 ( struct V_17 * V_11 , unsigned int V_18 , int V_23 )
{
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_9 * V_10 = F_9 ( V_11 ) ;
struct V_12 T_2 * V_13 = V_8 -> V_14 ;
unsigned long V_21 ;
T_4 V_19 = 1 << ( 31 - V_18 ) ;
F_14 ( & V_10 -> V_22 , V_21 ) ;
F_17 ( & V_13 -> V_24 , V_19 ) ;
F_12 ( V_8 , V_19 , V_23 ) ;
F_15 ( & V_10 -> V_22 , V_21 ) ;
return 0 ;
}
static int F_18 ( struct V_17 * V_11 , unsigned int V_18 )
{
struct V_7 * V_8 = F_11 ( V_11 ) ;
struct V_9 * V_10 = F_9 ( V_11 ) ;
struct V_12 T_2 * V_13 = V_8 -> V_14 ;
unsigned long V_21 ;
T_4 V_19 = 1 << ( 31 - V_18 ) ;
F_14 ( & V_10 -> V_22 , V_21 ) ;
F_19 ( & V_13 -> V_24 , V_19 ) ;
F_15 ( & V_10 -> V_22 , V_21 ) ;
return 0 ;
}
int F_20 ( struct V_25 * V_26 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 ;
struct V_17 * V_11 ;
V_10 = F_21 ( sizeof( * V_10 ) , V_27 ) ;
if ( ! V_10 )
return - V_28 ;
F_22 ( & V_10 -> V_22 ) ;
V_8 = & V_10 -> V_8 ;
V_11 = & V_8 -> V_11 ;
V_8 -> V_29 = F_8 ;
V_11 -> V_30 = 32 ;
V_11 -> V_31 = F_18 ;
V_11 -> V_32 = F_16 ;
V_11 -> V_33 = F_10 ;
V_11 -> V_34 = F_13 ;
return F_23 ( V_26 , V_8 , V_10 ) ;
}
