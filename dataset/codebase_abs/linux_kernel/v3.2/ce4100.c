static int F_1 ( void )
{
return 0 ;
}
static unsigned int F_2 ( struct V_1 * V_2 , int V_3 )
{
V_3 = V_3 << V_2 -> V_4 ;
return F_3 ( V_2 -> V_5 + V_3 ) ;
}
static unsigned int F_4 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_6 , V_7 , V_8 ;
if ( V_3 == V_9 ) {
V_3 = V_3 << V_2 -> V_4 ;
V_6 = F_3 ( V_2 -> V_5 + V_3 ) ;
if ( V_6 & V_10 ) {
V_7 = F_2 ( V_2 , V_11 ) ;
if ( V_7 & V_12 ) {
V_8 = F_2 ( V_2 , V_13 ) ;
if ( V_8 & ( V_14 | V_15 ) )
V_6 &= ~ V_10 ;
}
}
} else
V_6 = F_2 ( V_2 , V_3 ) ;
return V_6 ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , int V_16 )
{
V_3 = V_3 << V_2 -> V_4 ;
F_6 ( V_16 , V_2 -> V_5 + V_3 ) ;
}
static void F_7 ( int V_17 , struct V_1 * V_18 ,
unsigned short * V_19 )
{
#ifdef F_8
if ( V_18 -> V_20 != V_21 ) {
V_18 -> V_22 = 14745600 ;
V_18 -> V_23 = 0xdffe0200 ;
F_9 ( V_24 ,
V_18 -> V_23 & V_25 ) ;
V_18 -> V_5 =
( void V_26 * ) F_10 ( V_24 ) ;
V_18 -> V_5 += V_18 -> V_23 & ~ V_25 ;
V_18 -> V_20 = V_21 ;
V_18 -> V_4 = 2 ;
}
#endif
V_18 -> V_27 = 0 ;
V_18 -> V_28 = F_4 ;
V_18 -> V_29 = F_5 ;
* V_19 |= ( 1 << 12 ) ;
}
static T_1 void F_11 ( void )
{
F_12 ( F_7 ) ;
}
static inline void F_11 ( void ) {}
static void T_1 F_13 ( void )
{
F_11 () ;
}
static void T_2 F_14 ( void )
{
F_15 () ;
V_30 = & V_31 ;
}
void T_1 F_16 ( void )
{
V_32 . V_33 . V_34 = F_13 ;
V_35 . V_36 = F_1 ;
V_32 . V_37 . V_38 = V_39 ;
V_32 . V_40 . V_41 = V_42 ;
V_32 . V_40 . V_43 = V_39 ;
V_32 . V_44 . V_45 = V_46 ;
#ifdef F_17
V_32 . V_44 . V_47 = F_14 ;
V_32 . V_40 . V_48 = V_49 ;
#endif
}
