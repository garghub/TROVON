static void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
F_2 ( V_1 , V_1 + V_2 ) ;
}
static void F_3 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 = F_4 () ;
unsigned long V_4 = ~ ( V_3 - 1 ) ;
F_5 ( V_5 , V_1 & V_4 ) ;
F_5 ( V_5 , ( V_1 + V_2 - 1 ) & V_4 ) ;
F_6 ( V_1 , V_1 + V_2 ) ;
}
static void F_7 ( void )
{
}
static void F_8 ( void )
{
}
static void F_9 ( void )
{
unsigned long V_6 ;
if ( F_10 () < V_7 )
return;
V_6 = F_11 () ;
if ( V_6 & V_8 ) {
V_6 &= ~ V_9 ;
V_6 |= V_10 & V_9 ;
V_6 |= V_11 ;
F_12 ( V_6 ) ;
V_6 = F_13 () ;
V_6 |= V_12 ;
V_6 |= V_13 ;
F_14 ( V_6 ) ;
}
}
static void F_15 ( void )
{
unsigned long V_6 ;
if ( F_10 () < V_7 )
return;
V_6 = F_11 () ;
V_6 &= ~ V_11 ;
F_12 ( V_6 ) ;
V_6 = F_13 () ;
V_6 &= ~ V_12 ;
V_6 &= ~ V_13 ;
F_14 ( V_6 ) ;
}
static bool F_16 ( void )
{
unsigned long V_6 ;
if ( F_10 () < V_7 )
return false ;
V_6 = F_11 () ;
if ( ! ( V_6 & V_8 ) )
return false ;
return ! ! ( V_6 & V_11 ) ;
}
static inline int F_17 ( struct V_14 * V_15 )
{
unsigned int V_16 = F_18 () ;
unsigned int V_17 ;
switch ( F_19 () ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
if ( V_16 & ( 1 << 12 ) )
return 0 ;
}
V_17 = ( V_16 >> 4 ) & 0x0f ;
if ( 0 < V_17 && V_17 <= 7 )
V_15 -> V_27 . V_28 = 2 << V_17 ;
else
return 0 ;
return 1 ;
}
static int T_1 F_20 ( void )
{
struct V_14 * V_15 = & V_29 ;
unsigned long V_30 = F_21 () ;
unsigned long V_31 , V_32 , V_33 ;
if ( V_30 & V_34 )
return 0 ;
V_31 = V_30 & V_35 ;
V_31 >>= V_36 ;
if ( V_31 )
V_15 -> V_27 . V_31 = 64 << V_31 ;
V_32 = V_30 & V_37 ;
V_32 >>= V_38 ;
if ( V_32 )
V_15 -> V_27 . V_28 = 2 << V_32 ;
V_33 = V_30 & V_39 ;
V_33 >>= V_40 ;
V_15 -> V_27 . V_41 = V_33 + 1 ;
V_15 -> V_27 . V_42 = V_15 -> V_27 . V_31 * V_15 -> V_27 . V_28 ;
V_15 -> V_27 . V_43 = F_22 ( V_15 -> V_27 . V_42 ) ;
if ( V_15 -> V_27 . V_28 ) {
V_15 -> V_27 . V_44 &= ~ V_45 ;
return 1 ;
}
return 0 ;
}
static inline int T_1 F_23 ( void )
{
struct V_14 * V_15 = & V_29 ;
unsigned int V_46 , V_16 ;
unsigned int V_17 ;
V_15 -> V_27 . V_44 |= V_45 ;
if ( F_10 () >= V_47 )
return F_20 () ;
if ( ! ( V_15 -> V_48 & ( V_49 | V_50 |
V_51 | V_52 |
V_53 | V_54 ) ) )
return 0 ;
V_46 = F_24 () ;
if ( ! ( V_46 & V_55 ) )
return 0 ;
V_16 = F_18 () ;
if ( ! F_17 ( V_15 ) )
return 0 ;
V_17 = ( V_16 >> 8 ) & 0x0f ;
if ( V_17 <= 7 )
V_15 -> V_27 . V_31 = 64 << V_17 ;
else
return 0 ;
V_17 = ( V_16 >> 0 ) & 0x0f ;
if ( V_17 <= 7 )
V_15 -> V_27 . V_41 = V_17 + 1 ;
else
return 0 ;
V_15 -> V_27 . V_42 = V_15 -> V_27 . V_31 * V_15 -> V_27 . V_28 ;
V_15 -> V_27 . V_43 = F_22 ( V_15 -> V_27 . V_42 ) ;
V_15 -> V_27 . V_44 &= ~ V_45 ;
return 1 ;
}
int F_25 ( void )
{
int V_56 = F_23 () ;
if ( V_56 ) {
F_7 () ;
F_9 () ;
V_57 = & V_58 ;
}
return V_56 ;
}
