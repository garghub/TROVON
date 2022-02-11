static void F_1 ( void )
{
F_2 ( 0x4 , 0xcf9 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 , int V_3 )
{
V_3 = V_3 << V_2 -> V_4 ;
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_6 , V_7 , V_8 ;
if ( V_3 == V_9 ) {
V_3 = V_3 << V_2 -> V_4 ;
V_6 = F_4 ( V_2 -> V_5 + V_3 ) ;
if ( V_6 & V_10 ) {
V_7 = F_3 ( V_2 , V_11 ) ;
if ( V_7 & V_12 ) {
V_8 = F_3 ( V_2 , V_13 ) ;
if ( V_8 & ( V_14 | V_15 ) )
V_6 &= ~ V_10 ;
}
}
} else
V_6 = F_3 ( V_2 , V_3 ) ;
return V_6 ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 , int V_16 )
{
V_3 = V_3 << V_2 -> V_4 ;
F_7 ( V_16 , V_2 -> V_5 + V_3 ) ;
}
static void F_8 ( int V_17 , struct V_1 * V_18 ,
T_1 * V_19 )
{
#ifdef F_9
if ( V_18 -> V_20 != V_21 ) {
V_18 -> V_22 = 14745600 ;
V_18 -> V_23 = 0xdffe0200 ;
F_10 ( V_24 ,
V_18 -> V_23 & V_25 ) ;
V_18 -> V_5 =
( void V_26 * ) F_11 ( V_24 ) ;
V_18 -> V_5 += V_18 -> V_23 & ~ V_25 ;
V_18 -> V_23 += V_17 * 0x100 ;
V_18 -> V_5 += V_17 * 0x100 ;
V_18 -> V_20 = V_21 ;
V_18 -> V_4 = 2 ;
V_18 -> V_27 = 4 ;
}
#endif
V_18 -> V_28 = 0 ;
V_18 -> V_29 = F_5 ;
V_18 -> V_30 = F_6 ;
* V_19 |= ( 1 << 12 ) ;
}
static T_2 void F_12 ( void )
{
F_13 ( F_8 ) ;
}
static inline void F_12 ( void ) {}
static void T_2 F_14 ( void )
{
F_12 () ;
}
static void F_15 ( void )
{
F_16 () ;
}
void T_2 F_17 ( void )
{
V_31 . V_32 . V_33 = F_14 ;
V_31 . V_34 . V_35 = V_36 ;
V_31 . V_37 . V_38 = V_39 ;
V_31 . V_37 . V_40 = V_36 ;
V_31 . V_37 . V_41 = V_42 ;
V_31 . V_43 . V_44 = V_45 ;
V_31 . V_43 . V_46 = F_15 ;
V_47 = V_48 ;
V_49 = F_1 ;
}
