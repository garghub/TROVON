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
F_13 ( V_12 |
V_13 ) ;
}
}
static void F_14 ( void )
{
if ( F_10 () < V_7 )
return;
F_15 ( V_11 ) ;
F_16 ( V_12 |
V_13 ) ;
}
static bool F_17 ( void )
{
unsigned long V_6 ;
if ( F_10 () < V_7 )
return false ;
V_6 = F_11 () ;
if ( ! ( V_6 & V_8 ) )
return false ;
return ! ! ( V_6 & V_11 ) ;
}
static inline int F_18 ( struct V_14 * V_15 )
{
unsigned int V_16 = F_19 () ;
unsigned int V_17 ;
switch ( F_20 () ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
if ( V_16 & ( 1 << 12 ) )
return 0 ;
}
V_17 = ( V_16 >> 4 ) & 0x0f ;
if ( 0 < V_17 && V_17 <= 7 )
V_15 -> V_28 . V_29 = 2 << V_17 ;
else
return 0 ;
return 1 ;
}
static int T_1 F_21 ( void )
{
struct V_14 * V_15 = & V_30 ;
unsigned long V_31 = F_22 () ;
unsigned long V_32 , V_33 , V_34 ;
if ( V_31 & V_35 )
return 0 ;
V_32 = V_31 & V_36 ;
V_32 >>= F_23 ( V_36 ) ;
if ( V_32 )
V_15 -> V_28 . V_32 = 64 << V_32 ;
V_33 = V_31 & V_37 ;
V_33 >>= F_23 ( V_37 ) ;
if ( V_33 )
V_15 -> V_28 . V_29 = 2 << V_33 ;
V_34 = V_31 & V_38 ;
V_34 >>= F_23 ( V_38 ) ;
V_15 -> V_28 . V_39 = V_34 + 1 ;
V_15 -> V_28 . V_40 = V_15 -> V_28 . V_32 * V_15 -> V_28 . V_29 ;
V_15 -> V_28 . V_41 = F_23 ( V_15 -> V_28 . V_40 ) ;
if ( V_15 -> V_28 . V_29 ) {
V_15 -> V_28 . V_42 &= ~ V_43 ;
V_15 -> V_44 |= V_45 ;
return 1 ;
}
return 0 ;
}
static inline int T_1 F_24 ( void )
{
struct V_14 * V_15 = & V_30 ;
unsigned int V_46 , V_16 ;
unsigned int V_17 ;
V_15 -> V_28 . V_42 |= V_43 ;
if ( F_10 () >= V_47 )
return F_21 () ;
if ( ! ( V_15 -> V_48 & ( V_49 | V_50 |
V_51 | V_52 |
V_53 | V_54 ) ) )
return 0 ;
V_46 = F_25 () ;
if ( ! ( V_46 & V_55 ) )
return 0 ;
V_16 = F_19 () ;
if ( ! F_18 ( V_15 ) )
return 0 ;
V_17 = ( V_16 >> 8 ) & 0x0f ;
if ( V_17 <= 7 )
V_15 -> V_28 . V_32 = 64 << V_17 ;
else
return 0 ;
V_17 = ( V_16 >> 0 ) & 0x0f ;
if ( V_17 <= 7 )
V_15 -> V_28 . V_39 = V_17 + 1 ;
else
return 0 ;
V_15 -> V_28 . V_40 = V_15 -> V_28 . V_32 * V_15 -> V_28 . V_29 ;
V_15 -> V_28 . V_41 = F_23 ( V_15 -> V_28 . V_40 ) ;
V_15 -> V_28 . V_42 &= ~ V_43 ;
return 1 ;
}
int F_26 ( void )
{
int V_56 = F_24 () ;
if ( V_56 ) {
F_7 () ;
F_9 () ;
V_57 = & V_58 ;
}
return V_56 ;
}
