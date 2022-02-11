static unsigned long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = F_2 ( V_3 ) ;
if ( V_1 == & V_4 [ 1 ] ) {
V_2 &= V_5 ;
V_2 >>= V_6 ;
} else {
V_2 &= V_7 ;
}
return F_3 ( V_1 -> V_8 ) / ( V_2 + 1 ) ;
}
static unsigned long F_4 ( struct V_1 * V_1 ,
unsigned long V_9 )
{
unsigned long V_10 = F_3 ( V_1 -> V_8 ) ;
unsigned long V_11 = V_10 / V_9 ;
if ( V_11 > 256 )
V_11 = 256 ;
else if ( V_11 < 2 )
V_11 = 2 ;
return V_10 / V_11 ;
}
static int F_5 ( struct V_1 * V_1 , unsigned long V_9 )
{
unsigned long V_12 = F_4 ( V_1 , V_9 ) ;
unsigned long V_2 ;
unsigned long V_11 ;
unsigned long V_13 ;
V_11 = F_3 ( V_1 -> V_8 ) / V_12 ;
V_11 -- ;
F_6 ( V_13 ) ;
V_2 = F_2 ( V_3 ) ;
if ( V_1 == & V_4 [ 1 ] ) {
V_2 &= ~ V_5 ;
V_2 |= V_11 << V_6 ;
} else {
V_2 &= ~ V_7 ;
V_2 |= V_11 ;
}
F_7 ( V_2 , V_3 ) ;
F_8 ( V_13 ) ;
return 0 ;
}
static inline struct V_14 * F_9 ( struct V_1 * V_1 )
{
return F_10 ( V_1 , struct V_14 , V_1 ) ;
}
static unsigned long F_11 ( struct V_1 * V_1 )
{
unsigned long V_15 = F_2 ( V_16 ) ;
unsigned int V_11 ;
V_15 >>= F_12 ( V_1 -> V_17 ) ;
V_15 &= V_18 ;
if ( F_13 ( V_15 ) )
V_11 = F_9 ( V_1 ) -> V_11 ;
else
V_11 = F_14 ( V_15 ) ;
return F_3 ( V_1 -> V_8 ) / V_11 ;
}
static unsigned long F_15 ( struct V_1 * V_1 ,
unsigned long V_9 )
{
unsigned long V_10 ;
unsigned long V_11 ;
V_10 = F_3 ( V_1 -> V_8 ) ;
V_11 = V_10 / V_9 ;
if ( V_11 <= 1 && F_16 () )
V_11 = 1 ;
else if ( V_11 <= 2 )
V_11 = 2 ;
else if ( V_11 <= 4 )
V_11 = 4 ;
else if ( V_11 <= 8 )
V_11 = 8 ;
else
V_11 = 16 ;
return V_10 / V_11 ;
}
static unsigned long F_17 ( struct V_14 * V_19 )
{
return F_18 ( V_19 -> V_11 ) ;
}
static void F_19 ( struct V_14 * V_19 )
{
unsigned long V_15 = F_2 ( V_16 ) ;
unsigned long V_20 = F_17 ( V_19 ) ;
unsigned long V_13 ;
unsigned long V_21 = F_12 ( V_19 -> V_1 . V_17 ) ;
F_6 ( V_13 ) ;
V_15 = F_2 ( V_16 ) ;
V_15 &= ~ ( V_18 << V_21 ) ;
V_15 |= V_20 << V_21 ;
F_7 ( V_15 , V_16 ) ;
F_8 ( V_13 ) ;
}
static int F_20 ( struct V_1 * V_1 , unsigned long V_9 )
{
struct V_14 * V_19 = F_9 ( V_1 ) ;
unsigned long V_15 = F_2 ( V_16 ) ;
unsigned long V_10 = F_3 ( V_1 -> V_8 ) ;
unsigned long V_11 ;
V_15 >>= F_12 ( V_1 -> V_17 ) ;
V_15 &= V_18 ;
V_9 = F_21 ( V_1 , V_9 ) ;
V_11 = V_10 / V_9 ;
if ( V_11 > 16 )
return - V_22 ;
V_19 -> V_11 = V_11 ;
if ( ! F_13 ( V_15 ) )
F_19 ( V_19 ) ;
return 0 ;
}
static int T_1 F_22 ( unsigned int V_17 )
{
struct V_14 * V_19 = & V_23 [ V_17 ] ;
unsigned long V_15 = F_2 ( V_16 ) ;
V_15 >>= F_12 ( V_17 ) ;
V_15 &= V_18 ;
V_19 -> V_1 . V_17 = V_17 ;
V_19 -> V_11 = F_14 ( V_15 ) ;
return F_23 ( & V_19 -> V_1 ) ;
}
static inline struct V_1 * F_24 ( unsigned int V_17 )
{
return ( V_17 >= 2 ) ? & V_24 [ 1 ] : & V_24 [ 0 ] ;
}
static inline struct V_1 * F_25 ( unsigned int V_17 )
{
return & V_23 [ V_17 ] . V_1 ;
}
static int F_26 ( struct V_1 * V_1 , struct V_1 * V_8 )
{
unsigned int V_17 = V_1 -> V_17 ;
unsigned long V_15 ;
unsigned long V_13 ;
unsigned long V_20 ;
unsigned long V_21 = F_12 ( V_17 ) ;
unsigned long V_25 ;
if ( F_27 () )
V_25 = V_26 ;
else if ( F_28 () || F_29 () )
V_25 = 0 ;
else
V_25 = V_27 ;
if ( V_8 == F_24 ( V_17 ) )
V_20 = V_25 << V_21 ;
else if ( V_8 == F_25 ( V_17 ) )
V_20 = F_17 ( F_9 ( V_8 ) ) << V_21 ;
else
return - V_22 ;
V_1 -> V_8 = V_8 ;
F_6 ( V_13 ) ;
V_15 = F_2 ( V_16 ) ;
V_15 &= ~ ( V_18 << V_21 ) ;
F_7 ( V_15 | V_20 , V_16 ) ;
F_8 ( V_13 ) ;
return 0 ;
}
static T_1 int F_30 ( struct V_1 * V_28 )
{
unsigned long V_15 = F_2 ( V_16 ) ;
unsigned int V_17 = V_28 -> V_17 ;
struct V_1 * V_8 ;
int V_29 ;
V_29 = F_23 ( V_28 ) ;
if ( V_29 < 0 )
return V_29 ;
V_15 >>= F_12 ( V_17 ) ;
V_15 &= V_18 ;
if ( F_13 ( V_15 ) )
V_8 = F_24 ( V_17 ) ;
else
V_8 = F_25 ( V_17 ) ;
return F_31 ( V_28 , V_8 ) ;
}
T_1 void F_32 ( void )
{
struct V_1 * V_30 ;
unsigned int V_1 ;
int V_29 ;
V_30 = F_33 ( NULL , L_1 ) ;
if ( F_34 ( V_30 ) ) {
F_35 ( V_31 L_2 , V_32 ) ;
return;
}
for ( V_1 = 0 ; V_1 < F_36 ( V_4 ) ; V_1 ++ )
V_4 [ V_1 ] . V_8 = V_30 ;
F_37 ( V_4 , F_36 ( V_4 ) ) ;
F_37 ( V_24 , F_36 ( V_24 ) ) ;
for ( V_1 = 0 ; V_1 < F_36 ( V_23 ) ; V_1 ++ ) {
V_29 = F_22 ( V_1 ) ;
if ( V_29 < 0 ) {
F_35 ( V_31 L_3 , V_1 ) ;
return;
}
}
for ( V_1 = 0 ; V_1 < F_36 ( V_33 ) ; V_1 ++ ) {
V_29 = F_30 ( & V_33 [ V_1 ] ) ;
if ( V_29 < 0 ) {
F_35 ( V_31 L_4 , V_1 ) ;
return;
}
}
}
