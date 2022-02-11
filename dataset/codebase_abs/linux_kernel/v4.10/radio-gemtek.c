static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 , V_6 , V_7 , V_8 ;
V_8 = V_2 -> V_9 ? V_10 : 0x00 ;
F_2 ( V_8 | V_11 | V_12 | V_13 , V_4 -> V_14 ) ;
F_3 ( V_15 ) ;
for ( V_5 = 0 , V_7 = V_2 -> V_16 ; V_5 < 32 ; V_5 ++ , V_7 >>= 1 ) {
V_6 = ( V_7 & 1 ) ? V_12 : 0 ;
F_2 ( V_8 | V_11 | V_6 , V_4 -> V_14 ) ;
F_3 ( V_17 ) ;
F_2 ( V_8 | V_11 | V_6 | V_13 , V_4 -> V_14 ) ;
F_3 ( V_17 ) ;
}
F_2 ( V_8 | V_12 | V_13 , V_4 -> V_14 ) ;
F_3 ( V_17 ) ;
}
static unsigned long F_4 ( unsigned long V_18 )
{
return ( ( V_18 << V_19 ) + V_20 + V_21 / 2 ) / V_21 ;
}
static struct V_3 * F_5 ( void )
{
struct V_1 * V_2 = F_6 ( sizeof( * V_2 ) , V_22 ) ;
if ( V_2 )
V_2 -> V_9 = true ;
return V_2 ? & V_2 -> V_4 : NULL ;
}
static int F_7 ( struct V_3 * V_4 , T_1 V_18 )
{
struct V_1 * V_2 = F_8 ( V_4 , struct V_1 , V_4 ) ;
if ( V_23 && V_2 -> V_9 )
return 0 ;
F_9 ( V_2 , V_24 , 0 ) ;
F_9 ( V_2 , V_25 , 0 ) ;
F_9 ( V_2 , V_26 , 0 ) ;
F_9 ( V_2 , V_27 , 0 ) ;
F_9 ( V_2 , V_28 , 1 ) ;
F_9 ( V_2 , V_29 , 0 ) ;
F_9 ( V_2 , V_30 , V_31 ) ;
F_9 ( V_2 , V_32 , F_4 ( V_18 ) ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 , bool V_8 , int V_33 )
{
struct V_1 * V_2 = F_8 ( V_4 , struct V_1 , V_4 ) ;
int V_5 ;
V_2 -> V_9 = V_8 ;
if ( V_23 ) {
if ( ! V_8 )
return F_7 ( V_4 , V_4 -> V_18 ) ;
F_9 ( V_2 , V_24 , 0 ) ;
F_9 ( V_2 , V_25 , 0 ) ;
F_9 ( V_2 , V_26 , 0 ) ;
F_9 ( V_2 , V_27 , 0 ) ;
F_9 ( V_2 , V_28 , 0 ) ;
F_9 ( V_2 , V_29 , 0 ) ;
F_9 ( V_2 , V_30 , V_34 ) ;
F_9 ( V_2 , V_32 , 0 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
V_5 = F_11 ( V_4 -> V_14 ) ;
F_2 ( ( V_5 >> 5 ) | ( V_8 ? V_10 : 0 ) , V_4 -> V_14 ) ;
F_3 ( V_17 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_3 * V_4 )
{
if ( F_11 ( V_4 -> V_14 ) & V_35 )
return V_36 ;
return V_37 ;
}
static bool F_13 ( struct V_3 * V_4 , int V_14 )
{
int V_5 , V_7 ;
V_7 = F_11 ( V_14 ) ;
for ( V_5 = 0 ; V_5 < 3 ; ++ V_5 ) {
F_2 ( 1 << V_5 , V_14 ) ;
F_3 ( V_17 ) ;
if ( ( F_11 ( V_14 ) & ~ V_35 ) != ( 0x17 | ( 1 << ( V_5 + 5 ) ) ) )
return false ;
}
F_2 ( V_7 >> 5 , V_14 ) ;
F_3 ( V_17 ) ;
return true ;
}
static int T_2 F_14 ( void )
{
V_38 . V_39 = V_39 ;
#ifdef F_15
F_16 ( & V_38 . V_40 ) ;
#endif
return F_17 ( & V_38 . V_41 , V_42 ) ;
}
static void T_3 F_18 ( void )
{
V_23 = true ;
#ifdef F_15
F_19 ( & V_38 . V_40 ) ;
#endif
F_20 ( & V_38 . V_41 ) ;
}
