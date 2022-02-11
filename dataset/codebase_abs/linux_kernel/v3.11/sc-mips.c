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
static inline int F_9 ( struct V_6 * V_7 )
{
unsigned int V_8 = F_10 () ;
unsigned int V_9 ;
switch ( V_7 -> V_10 ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
if ( V_8 & ( 1 << 12 ) )
return 0 ;
}
V_9 = ( V_8 >> 4 ) & 0x0f ;
if ( 0 < V_9 && V_9 <= 7 )
V_7 -> V_15 . V_16 = 2 << V_9 ;
else
return 0 ;
return 1 ;
}
static inline int T_1 F_11 ( void )
{
struct V_6 * V_7 = & V_17 ;
unsigned int V_18 , V_8 ;
unsigned int V_9 ;
V_7 -> V_15 . V_19 |= V_20 ;
if ( ! ( V_7 -> V_21 & ( V_22 | V_23 |
V_24 | V_25 ) ) )
return 0 ;
V_18 = F_12 () ;
if ( ! ( V_18 & V_26 ) )
return 0 ;
V_8 = F_10 () ;
if ( ! F_9 ( V_7 ) )
return 0 ;
V_9 = ( V_8 >> 8 ) & 0x0f ;
if ( 0 <= V_9 && V_9 <= 7 )
V_7 -> V_15 . V_27 = 64 << V_9 ;
else
return 0 ;
V_9 = ( V_8 >> 0 ) & 0x0f ;
if ( 0 <= V_9 && V_9 <= 7 )
V_7 -> V_15 . V_28 = V_9 + 1 ;
else
return 0 ;
V_7 -> V_15 . V_29 = V_7 -> V_15 . V_27 * V_7 -> V_15 . V_16 ;
V_7 -> V_15 . V_30 = F_13 ( V_7 -> V_15 . V_29 ) ;
V_7 -> V_15 . V_19 &= ~ V_20 ;
return 1 ;
}
int F_14 ( void )
{
int V_31 = F_11 () ;
if ( V_31 ) {
F_7 () ;
V_32 = & V_33 ;
}
return V_31 ;
}
