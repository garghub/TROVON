int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( V_3 > V_5 )
V_3 = V_5 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 [ 0 ] . V_3 = V_3 ;
F_2 ( & V_2 -> V_8 ) ;
V_4 = F_3 ( & V_2 -> V_7 [ 0 ] . V_9 , 0 ) ;
if ( V_4 )
goto V_10;
V_4 = F_3 ( & V_2 -> V_7 [ 1 ] . V_9 , 0 ) ;
if ( V_4 )
F_4 ( & V_2 -> V_7 [ 0 ] . V_9 ) ;
V_10:
return V_4 ;
}
void F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_6 ;
int V_11 ;
T_1 V_9 ;
unsigned long V_12 ;
if ( V_3 > V_5 )
V_3 = V_5 ;
F_6 ( & V_2 -> V_8 ) ;
V_6 = V_2 -> V_6 ^ 1 ;
V_11 = V_2 -> V_7 [ V_2 -> V_6 ] . V_3 - V_3 ;
if ( ! V_11 )
goto V_10;
V_2 -> V_7 [ V_6 ] . V_3 = V_3 ;
F_7 ( V_12 ) ;
V_9 = F_8 ( & V_2 -> V_7 [ V_2 -> V_6 ] . V_9 ) ;
if ( V_11 < 0 )
V_9 <<= - V_11 ;
else
V_9 >>= V_11 ;
F_9 ( & V_2 -> V_7 [ V_6 ] . V_9 , V_9 ) ;
F_10 () ;
V_2 -> V_6 = V_6 ;
F_11 ( V_12 ) ;
F_12 () ;
V_10:
F_13 ( & V_2 -> V_8 ) ;
}
static struct V_13 * F_14 ( struct V_1 * V_2 )
__acquires( T_2 )
{
int V_6 ;
F_15 () ;
V_6 = V_2 -> V_6 ;
F_16 () ;
return & V_2 -> V_7 [ V_6 ] ;
}
static void F_17 ( struct V_1 * V_2 , struct V_13 * V_7 )
__releases( T_2 )
{
F_18 () ;
}
static void
F_19 ( int * V_14 , unsigned long * V_15 , int V_16 )
{
int V_11 = * V_14 - V_16 ;
if ( ! V_11 )
return;
if ( V_11 < 0 )
* V_15 <<= - V_11 ;
else
* V_15 >>= V_11 ;
* V_14 = V_16 ;
}
int F_20 ( struct V_17 * V_18 )
{
F_21 ( & V_18 -> V_19 ) ;
V_18 -> V_3 = 0 ;
V_18 -> V_20 = 0 ;
return F_3 ( & V_18 -> V_9 , 0 ) ;
}
void F_22 ( struct V_17 * V_18 )
{
F_4 ( & V_18 -> V_9 ) ;
}
static
void F_23 ( struct V_13 * V_7 , struct V_17 * V_18 )
{
unsigned long V_20 = 1UL << ( V_7 -> V_3 - 1 ) ;
unsigned long V_21 = ~ ( V_20 - 1 ) ;
unsigned long V_22 ;
unsigned long V_12 ;
V_22 = F_24 ( & V_7 -> V_9 ) ;
V_22 &= V_21 ;
if ( V_18 -> V_20 == V_22 )
return;
F_25 ( & V_18 -> V_19 , V_12 ) ;
F_19 ( & V_18 -> V_3 , & V_18 -> V_20 , V_7 -> V_3 ) ;
V_20 = ( V_22 - V_18 -> V_20 ) >> ( V_7 -> V_3 - 1 ) ;
if ( V_20 < V_23 ) {
T_3 V_24 = F_24 ( & V_18 -> V_9 ) ;
if ( V_24 < ( V_25 * V_26 ) )
V_24 = F_8 ( & V_18 -> V_9 ) ;
F_26 ( & V_18 -> V_9 , - V_24 + ( V_24 >> V_20 ) ,
V_26 ) ;
} else
F_9 ( & V_18 -> V_9 , 0 ) ;
V_18 -> V_20 = V_22 ;
F_27 ( & V_18 -> V_19 , V_12 ) ;
}
void F_28 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_13 * V_7 = F_14 ( V_2 ) ;
F_23 ( V_7 , V_18 ) ;
F_26 ( & V_18 -> V_9 , 1 , V_26 ) ;
F_29 ( & V_7 -> V_9 , 1 ) ;
F_17 ( V_2 , V_7 ) ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_17 * V_18 , long V_27 )
{
struct V_13 * V_7 = F_14 ( V_2 ) ;
F_23 ( V_7 , V_18 ) ;
if ( F_31 ( V_27 != V_28 ) ) {
unsigned long V_29 = 1UL << ( V_7 -> V_3 - 1 ) ;
unsigned long V_30 = V_29 - 1 ;
unsigned long V_31 ;
long V_32 , V_33 ;
V_32 = F_32 ( & V_18 -> V_9 ) ;
V_31 = F_24 ( & V_7 -> V_9 ) ;
V_33 = V_29 + ( V_31 & V_30 ) ;
if ( V_32 > ( ( V_33 * V_27 ) >> V_34 ) )
goto V_35;
}
F_29 ( & V_18 -> V_9 , 1 ) ;
F_29 ( & V_7 -> V_9 , 1 ) ;
V_35:
F_17 ( V_2 , V_7 ) ;
}
void F_33 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
long * V_32 , long * V_33 )
{
struct V_13 * V_7 = F_14 ( V_2 ) ;
unsigned long V_29 = 1UL << ( V_7 -> V_3 - 1 ) ;
unsigned long V_30 = V_29 - 1 ;
unsigned long V_31 ;
F_23 ( V_7 , V_18 ) ;
* V_32 = F_32 ( & V_18 -> V_9 ) ;
V_31 = F_24 ( & V_7 -> V_9 ) ;
* V_33 = V_29 + ( V_31 & V_30 ) ;
F_17 ( V_2 , V_7 ) ;
}
int F_34 ( struct V_36 * V_18 )
{
F_21 ( & V_18 -> V_19 ) ;
V_18 -> V_3 = 0 ;
V_18 -> V_20 = 0 ;
V_18 -> V_9 = 0 ;
return 0 ;
}
void F_35 ( struct V_36 * V_18 )
{
}
static
void F_36 ( struct V_13 * V_7 , struct V_36 * V_18 )
{
unsigned long V_20 = 1UL << ( V_7 -> V_3 - 1 ) ;
unsigned long V_21 = ~ ( V_20 - 1 ) ;
unsigned long V_22 ;
unsigned long V_12 ;
V_22 = F_24 ( & V_7 -> V_9 ) ;
V_22 &= V_21 ;
if ( V_18 -> V_20 == V_22 )
return;
F_25 ( & V_18 -> V_19 , V_12 ) ;
F_19 ( & V_18 -> V_3 , & V_18 -> V_20 , V_7 -> V_3 ) ;
V_20 = ( V_22 - V_18 -> V_20 ) >> ( V_7 -> V_3 - 1 ) ;
if ( F_37 ( V_20 < V_23 ) )
V_18 -> V_9 >>= V_20 ;
else
V_18 -> V_9 = 0 ;
V_18 -> V_20 = V_22 ;
F_27 ( & V_18 -> V_19 , V_12 ) ;
}
void F_38 ( struct V_1 * V_2 , struct V_36 * V_18 )
{
struct V_13 * V_7 = F_14 ( V_2 ) ;
F_36 ( V_7 , V_18 ) ;
V_18 -> V_9 ++ ;
F_29 ( & V_7 -> V_9 , 1 ) ;
F_17 ( V_2 , V_7 ) ;
}
void F_39 ( struct V_1 * V_2 ,
struct V_36 * V_18 ,
long * V_32 , long * V_33 )
{
struct V_13 * V_7 = F_14 ( V_2 ) ;
unsigned long V_29 = 1UL << ( V_7 -> V_3 - 1 ) ;
unsigned long V_30 = V_29 - 1 ;
unsigned long V_31 ;
F_36 ( V_7 , V_18 ) ;
* V_32 = V_18 -> V_9 ;
V_31 = F_24 ( & V_7 -> V_9 ) ;
* V_33 = V_29 + ( V_31 & V_30 ) ;
F_17 ( V_2 , V_7 ) ;
}
