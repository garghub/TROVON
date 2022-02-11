static int F_1 ( void )
{
return 0 ;
}
static void F_2 ( void )
{
F_3 ( 0x4 , 0xcf9 ) ;
}
static unsigned int F_4 ( struct V_1 * V_2 , int V_3 )
{
V_3 = V_3 << V_2 -> V_4 ;
return F_5 ( V_2 -> V_5 + V_3 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_6 , V_7 , V_8 ;
if ( V_3 == V_9 ) {
V_3 = V_3 << V_2 -> V_4 ;
V_6 = F_5 ( V_2 -> V_5 + V_3 ) ;
if ( V_6 & V_10 ) {
V_7 = F_4 ( V_2 , V_11 ) ;
if ( V_7 & V_12 ) {
V_8 = F_4 ( V_2 , V_13 ) ;
if ( V_8 & ( V_14 | V_15 ) )
V_6 &= ~ V_10 ;
}
}
} else
V_6 = F_4 ( V_2 , V_3 ) ;
return V_6 ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 , int V_16 )
{
V_3 = V_3 << V_2 -> V_4 ;
F_8 ( V_16 , V_2 -> V_5 + V_3 ) ;
}
static void F_9 ( int V_17 , struct V_1 * V_18 ,
unsigned short * V_19 )
{
#ifdef F_10
if ( V_18 -> V_20 != V_21 ) {
V_18 -> V_22 = 14745600 ;
V_18 -> V_23 = 0xdffe0200 ;
F_11 ( V_24 ,
V_18 -> V_23 & V_25 ) ;
V_18 -> V_5 =
( void V_26 * ) F_12 ( V_24 ) ;
V_18 -> V_5 += V_18 -> V_23 & ~ V_25 ;
V_18 -> V_23 += V_17 * 0x100 ;
V_18 -> V_5 += V_17 * 0x100 ;
V_18 -> V_20 = V_21 ;
V_18 -> V_4 = 2 ;
V_18 -> V_27 = 4 ;
}
#endif
V_18 -> V_28 = 0 ;
V_18 -> V_29 = F_6 ;
V_18 -> V_30 = F_7 ;
* V_19 |= ( 1 << 12 ) ;
}
static T_1 void F_13 ( void )
{
F_14 ( F_9 ) ;
}
static inline void F_13 ( void ) {}
static void T_1 F_15 ( void )
{
F_13 () ;
}
static void F_16 ( void )
{
F_17 () ;
V_31 = & V_32 ;
}
void T_1 F_18 ( void )
{
V_33 . V_34 . V_35 = F_15 ;
V_36 . V_37 = F_1 ;
V_33 . V_38 . V_39 = V_40 ;
V_33 . V_41 . V_42 = V_43 ;
V_33 . V_41 . V_44 = V_40 ;
V_33 . V_45 . V_46 = V_47 ;
V_48 = V_49 ;
#ifdef F_19
V_33 . V_45 . V_50 = F_16 ;
V_33 . V_41 . V_51 = V_52 ;
#endif
V_53 = F_2 ;
}
