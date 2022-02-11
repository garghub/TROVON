static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_2 ) ;
}
static inline T_1 F_3 ( T_1 V_3 , T_1 V_4 )
{
T_1 V_5 = 0xffffffff >> ( 32 - V_4 ) ;
return V_5 << V_3 ;
}
static unsigned long F_4 ( struct V_2 * V_2 )
{
struct V_1 * V_6 = F_1 ( V_2 ) ;
unsigned long V_7 = F_5 ( V_2 -> V_8 ) ;
T_1 V_9 = F_6 ( V_6 -> V_10 . V_11 ) ;
T_1 V_5 = F_3 ( V_6 -> V_10 . V_3 , V_6 -> V_10 . V_12 ) ;
V_9 &= V_5 ;
V_9 >>= V_6 -> V_10 . V_3 ;
V_9 ++ ;
V_7 /= V_9 ;
return V_7 ;
}
static int F_7 ( struct V_2 * V_2 , unsigned long V_7 )
{
struct V_1 * V_6 = F_1 ( V_2 ) ;
void T_2 * V_11 = V_6 -> V_10 . V_11 ;
unsigned int div ;
T_1 V_5 = F_3 ( V_6 -> V_10 . V_3 , V_6 -> V_10 . V_12 ) ;
T_1 V_13 ;
V_7 = F_8 ( V_2 , V_7 ) ;
div = F_5 ( V_2 -> V_8 ) / V_7 ;
if ( div > ( 1 << V_6 -> V_10 . V_12 ) )
return - V_14 ;
V_13 = F_6 ( V_11 ) ;
V_13 &= ~ V_5 ;
V_13 |= ( div - 1 ) << V_6 -> V_10 . V_3 ;
F_9 ( V_13 , V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_2 , struct V_2 * V_8 )
{
struct V_1 * V_6 = F_1 ( V_2 ) ;
struct V_15 * V_16 = V_6 -> V_17 ;
T_1 V_18 = F_6 ( V_6 -> V_19 . V_11 ) ;
T_1 V_5 = F_3 ( V_6 -> V_19 . V_3 , V_6 -> V_19 . V_12 ) ;
int V_20 = - 1 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_16 -> V_22 ; V_21 ++ )
if ( V_16 -> V_17 [ V_21 ] == V_8 ) {
V_20 = V_21 ;
break;
}
if ( V_20 >= 0 ) {
V_2 -> V_8 = V_8 ;
V_18 &= ~ V_5 ;
V_18 |= V_20 << V_6 -> V_19 . V_3 ;
F_9 ( V_18 , V_6 -> V_19 . V_11 ) ;
return 0 ;
}
return - V_14 ;
}
static unsigned long F_11 ( struct V_2 * V_2 ,
unsigned long V_7 )
{
struct V_1 * V_6 = F_1 ( V_2 ) ;
unsigned long V_23 = F_5 ( V_2 -> V_8 ) ;
int V_24 = 1 << V_6 -> V_10 . V_12 ;
int div ;
if ( V_7 >= V_23 )
V_7 = V_23 ;
else {
div = V_23 / V_7 ;
if ( V_23 % V_7 )
div ++ ;
if ( div == 0 )
div = 1 ;
if ( div > V_24 )
div = V_24 ;
V_7 = V_23 / div ;
}
return V_7 ;
}
void T_3 F_12 ( struct V_1 * V_2 , bool V_25 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
T_1 V_5 = F_3 ( V_2 -> V_19 . V_3 , V_2 -> V_19 . V_12 ) ;
T_1 V_18 ;
if ( ! V_2 -> V_19 . V_11 ) {
if ( ! V_2 -> V_2 . V_8 )
F_13 ( V_26 L_1 ,
V_2 -> V_2 . V_27 ) ;
return;
}
V_18 = F_6 ( V_2 -> V_19 . V_11 ) ;
V_18 &= V_5 ;
V_18 >>= V_2 -> V_19 . V_3 ;
if ( V_18 > V_16 -> V_22 || ! V_16 -> V_17 [ V_18 ] ) {
F_13 ( V_26 L_2 ,
V_2 -> V_2 . V_27 , V_18 ) ;
return;
}
V_2 -> V_2 . V_8 = V_16 -> V_17 [ V_18 ] ;
if ( V_25 )
F_13 ( V_28 L_3 ,
V_2 -> V_2 . V_27 , V_2 -> V_2 . V_8 -> V_27 , V_18 ,
F_5 ( & V_2 -> V_2 ) ) ;
}
void T_4 F_14 ( struct V_1 * V_18 , int V_12 )
{
int V_29 ;
for (; V_12 > 0 ; V_12 -- , V_18 ++ ) {
if ( ! V_18 -> V_10 . V_11 && ! V_18 -> V_19 . V_11 )
F_13 ( V_26 L_4 ,
V_30 , V_18 -> V_2 . V_27 ) ;
if ( ! V_18 -> V_2 . V_31 ) {
if ( ! V_18 -> V_10 . V_11 )
V_18 -> V_2 . V_31 = & V_32 ;
else if ( ! V_18 -> V_19 . V_11 )
V_18 -> V_2 . V_31 = & V_33 ;
else
V_18 -> V_2 . V_31 = & V_34 ;
}
F_12 ( V_18 , false ) ;
V_29 = F_15 ( & V_18 -> V_2 ) ;
if ( V_29 < 0 ) {
F_13 ( V_26 L_5 ,
V_30 , V_18 -> V_2 . V_27 , V_29 ) ;
}
}
}
