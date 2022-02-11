static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_5 ) ;
V_5 &= ~ V_6 ;
F_4 ( V_5 , V_4 -> V_5 ) ;
while ( ( F_3 ( V_4 -> V_5 ) & V_7 ) == 0 )
;
while ( ( F_3 ( V_4 -> V_5 ) & V_8 ) == 0 )
;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_5 ) ;
V_5 |= V_6 ;
F_4 ( V_5 , V_4 -> V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_5 ) ;
V_5 |= V_9 ;
F_4 ( V_5 , V_4 -> V_5 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_5 ) ;
V_5 &= ~ V_9 ;
F_4 ( V_5 , V_4 -> V_5 ) ;
}
static unsigned long F_8 ( struct V_1 * V_2 ,
unsigned long V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_11 , V_12 , V_13 , V_5 ;
V_5 = F_3 ( V_4 -> V_5 ) ;
if ( V_5 & V_14 )
return V_10 ;
V_11 = ( V_5 & V_15 ) >> V_16 ;
V_12 = ( V_5 & V_17 ) >> V_18 ;
V_13 = V_10 * ( V_11 + 1 ) ;
return V_13 / ( 1 << V_12 ) ;
}
static void F_9 ( unsigned long V_19 , unsigned long V_20 ,
T_1 * V_21 , T_1 * V_22 )
{
T_1 V_12 , V_11 ;
unsigned long V_13 ;
if ( V_19 < V_23 )
V_19 = V_23 ;
if ( V_19 > V_24 )
V_19 = V_24 ;
for ( V_12 = 1 ; V_12 <= 6 ; V_12 ++ ) {
if ( ( V_19 * ( 1 << V_12 ) ) >= V_25 )
break;
}
V_13 = V_19 * ( 1 << V_12 ) ;
V_11 = ( V_13 + ( V_20 / 2 ) ) / V_20 ;
V_11 -- ;
* V_21 = V_12 ;
* V_22 = V_11 ;
}
static long F_10 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long * V_10 )
{
T_1 V_12 , V_11 ;
unsigned long V_20 = * V_10 ;
F_9 ( V_19 , V_20 , & V_12 , & V_11 ) ;
return ( V_20 * ( V_11 + 1 ) ) / ( 1 << V_12 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_12 , V_11 ;
T_1 V_5 ;
F_9 ( V_19 , V_10 , & V_12 , & V_11 ) ;
V_5 = F_3 ( V_4 -> V_5 ) ;
if ( V_11 != ( ( V_5 & V_15 ) >> V_16 ) ) {
V_5 |= V_14 ;
F_4 ( V_5 | V_14 , V_4 -> V_5 ) ;
F_4 ( V_5 | V_6 , V_4 -> V_5 ) ;
V_5 &= ~ ( V_15 | V_17 ) ;
V_5 |= ( V_11 << V_16 ) | ( V_12 << V_18 ) ;
F_4 ( V_5 | V_6 , V_4 -> V_5 ) ;
F_4 ( V_5 , V_4 -> V_5 ) ;
while ( ( F_3 ( V_4 -> V_5 ) & V_7 ) == 0 )
;
while ( ( F_3 ( V_4 -> V_5 ) & V_8 ) == 0 )
;
V_5 |= V_9 ;
V_5 &= ~ V_14 ;
} else {
V_5 &= ~ V_17 ;
V_5 |= V_12 << V_18 ;
}
F_4 ( V_5 , V_4 -> V_5 ) ;
return 0 ;
}
static unsigned long F_12 ( struct V_1 * V_2 ,
unsigned long V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 div = ( F_3 ( V_4 -> V_5 ) & V_26 ) ? 8 : 4 ;
return V_10 / div ;
}
static unsigned long F_13 ( struct V_1 * V_2 ,
unsigned long V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 div = ( F_3 ( V_4 -> V_5 ) & V_27 ) >> V_28 ;
return V_10 / ( div + 2 ) ;
}
static unsigned long F_14 ( struct V_1 * V_2 ,
unsigned long V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 div ;
div = F_3 ( V_4 -> V_5 ) & 0x1f ;
div ++ ;
div *= 2 ;
return V_10 / div ;
}
static long F_15 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long * V_10 )
{
T_1 div ;
div = * V_10 / V_19 ;
div ++ ;
div &= ~ 0x1 ;
return * V_10 / div ;
}
static int F_16 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 div ;
div = V_10 / V_19 ;
if ( div & 0x1 )
return - V_29 ;
F_4 ( div >> 1 , V_4 -> V_5 ) ;
return 0 ;
}
void T_2 F_17 ( struct V_30 * V_31 )
{
F_18 ( V_31 , & V_32 ) ;
}
static void T_2 F_19 ( struct V_30 * V_31 )
{
F_18 ( V_31 , & V_33 ) ;
}
static void T_2 F_20 ( struct V_30 * V_31 )
{
struct V_34 * V_34 = F_18 ( V_31 , & V_35 ) ;
F_21 ( V_34 ) ;
}
static void T_2 F_22 ( struct V_30 * V_31 )
{
F_18 ( V_31 , & V_36 ) ;
}
void T_2 F_23 ( void )
{
F_24 ( V_37 ) ;
}
