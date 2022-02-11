int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int V_5 ;
if ( V_3 > V_6 )
V_3 = V_6 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 [ 0 ] . V_3 = V_3 ;
F_2 ( & V_2 -> V_9 ) ;
V_5 = F_3 ( & V_2 -> V_8 [ 0 ] . V_10 , 0 , V_4 ) ;
if ( V_5 )
goto V_11;
V_5 = F_3 ( & V_2 -> V_8 [ 1 ] . V_10 , 0 , V_4 ) ;
if ( V_5 )
F_4 ( & V_2 -> V_8 [ 0 ] . V_10 ) ;
V_11:
return V_5 ;
}
void F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_7 ;
int V_12 ;
T_2 V_10 ;
unsigned long V_13 ;
if ( V_3 > V_6 )
V_3 = V_6 ;
F_6 ( & V_2 -> V_9 ) ;
V_7 = V_2 -> V_7 ^ 1 ;
V_12 = V_2 -> V_8 [ V_2 -> V_7 ] . V_3 - V_3 ;
if ( ! V_12 )
goto V_11;
V_2 -> V_8 [ V_7 ] . V_3 = V_3 ;
F_7 ( V_13 ) ;
V_10 = F_8 ( & V_2 -> V_8 [ V_2 -> V_7 ] . V_10 ) ;
if ( V_12 < 0 )
V_10 <<= - V_12 ;
else
V_10 >>= V_12 ;
F_9 ( & V_2 -> V_8 [ V_7 ] . V_10 , V_10 ) ;
F_10 () ;
V_2 -> V_7 = V_7 ;
F_11 ( V_13 ) ;
F_12 () ;
V_11:
F_13 ( & V_2 -> V_9 ) ;
}
static struct V_14 * F_14 ( struct V_1 * V_2 )
__acquires( T_3 )
{
int V_7 ;
F_15 () ;
V_7 = V_2 -> V_7 ;
F_16 () ;
return & V_2 -> V_8 [ V_7 ] ;
}
static void F_17 ( struct V_1 * V_2 , struct V_14 * V_8 )
__releases( T_3 )
{
F_18 () ;
}
static void
F_19 ( int * V_15 , unsigned long * V_16 , int V_17 )
{
int V_12 = * V_15 - V_17 ;
if ( ! V_12 )
return;
if ( V_12 < 0 )
* V_16 <<= - V_12 ;
else
* V_16 >>= V_12 ;
* V_15 = V_17 ;
}
int F_20 ( struct V_18 * V_19 , T_1 V_4 )
{
F_21 ( & V_19 -> V_20 ) ;
V_19 -> V_3 = 0 ;
V_19 -> V_21 = 0 ;
return F_3 ( & V_19 -> V_10 , 0 , V_4 ) ;
}
void F_22 ( struct V_18 * V_19 )
{
F_4 ( & V_19 -> V_10 ) ;
}
static
void F_23 ( struct V_14 * V_8 , struct V_18 * V_19 )
{
unsigned long V_21 = 1UL << ( V_8 -> V_3 - 1 ) ;
unsigned long V_22 = ~ ( V_21 - 1 ) ;
unsigned long V_23 ;
unsigned long V_13 ;
V_23 = F_24 ( & V_8 -> V_10 ) ;
V_23 &= V_22 ;
if ( V_19 -> V_21 == V_23 )
return;
F_25 ( & V_19 -> V_20 , V_13 ) ;
F_19 ( & V_19 -> V_3 , & V_19 -> V_21 , V_8 -> V_3 ) ;
V_21 = ( V_23 - V_19 -> V_21 ) >> ( V_8 -> V_3 - 1 ) ;
if ( V_21 < V_24 ) {
T_4 V_25 = F_24 ( & V_19 -> V_10 ) ;
if ( V_25 < ( V_26 * V_27 ) )
V_25 = F_8 ( & V_19 -> V_10 ) ;
F_26 ( & V_19 -> V_10 , - V_25 + ( V_25 >> V_21 ) ,
V_27 ) ;
} else
F_9 ( & V_19 -> V_10 , 0 ) ;
V_19 -> V_21 = V_23 ;
F_27 ( & V_19 -> V_20 , V_13 ) ;
}
void F_28 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_14 * V_8 = F_14 ( V_2 ) ;
F_23 ( V_8 , V_19 ) ;
F_26 ( & V_19 -> V_10 , 1 , V_27 ) ;
F_29 ( & V_8 -> V_10 , 1 ) ;
F_17 ( V_2 , V_8 ) ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_18 * V_19 , long V_28 )
{
struct V_14 * V_8 = F_14 ( V_2 ) ;
F_23 ( V_8 , V_19 ) ;
if ( F_31 ( V_28 != V_29 ) ) {
unsigned long V_30 = 1UL << ( V_8 -> V_3 - 1 ) ;
unsigned long V_31 = V_30 - 1 ;
unsigned long V_32 ;
long V_33 , V_34 ;
V_33 = F_32 ( & V_19 -> V_10 ) ;
V_32 = F_24 ( & V_8 -> V_10 ) ;
V_34 = V_30 + ( V_32 & V_31 ) ;
if ( V_33 > ( ( V_34 * V_28 ) >> V_35 ) )
goto V_36;
}
F_29 ( & V_19 -> V_10 , 1 ) ;
F_29 ( & V_8 -> V_10 , 1 ) ;
V_36:
F_17 ( V_2 , V_8 ) ;
}
void F_33 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
long * V_33 , long * V_34 )
{
struct V_14 * V_8 = F_14 ( V_2 ) ;
unsigned long V_30 = 1UL << ( V_8 -> V_3 - 1 ) ;
unsigned long V_31 = V_30 - 1 ;
unsigned long V_32 ;
F_23 ( V_8 , V_19 ) ;
* V_33 = F_32 ( & V_19 -> V_10 ) ;
V_32 = F_24 ( & V_8 -> V_10 ) ;
* V_34 = V_30 + ( V_32 & V_31 ) ;
F_17 ( V_2 , V_8 ) ;
}
int F_34 ( struct V_37 * V_19 )
{
F_21 ( & V_19 -> V_20 ) ;
V_19 -> V_3 = 0 ;
V_19 -> V_21 = 0 ;
V_19 -> V_10 = 0 ;
return 0 ;
}
void F_35 ( struct V_37 * V_19 )
{
}
static
void F_36 ( struct V_14 * V_8 , struct V_37 * V_19 )
{
unsigned long V_21 = 1UL << ( V_8 -> V_3 - 1 ) ;
unsigned long V_22 = ~ ( V_21 - 1 ) ;
unsigned long V_23 ;
unsigned long V_13 ;
V_23 = F_24 ( & V_8 -> V_10 ) ;
V_23 &= V_22 ;
if ( V_19 -> V_21 == V_23 )
return;
F_25 ( & V_19 -> V_20 , V_13 ) ;
F_19 ( & V_19 -> V_3 , & V_19 -> V_21 , V_8 -> V_3 ) ;
V_21 = ( V_23 - V_19 -> V_21 ) >> ( V_8 -> V_3 - 1 ) ;
if ( F_37 ( V_21 < V_24 ) )
V_19 -> V_10 >>= V_21 ;
else
V_19 -> V_10 = 0 ;
V_19 -> V_21 = V_23 ;
F_27 ( & V_19 -> V_20 , V_13 ) ;
}
void F_38 ( struct V_1 * V_2 , struct V_37 * V_19 )
{
struct V_14 * V_8 = F_14 ( V_2 ) ;
F_36 ( V_8 , V_19 ) ;
V_19 -> V_10 ++ ;
F_29 ( & V_8 -> V_10 , 1 ) ;
F_17 ( V_2 , V_8 ) ;
}
void F_39 ( struct V_1 * V_2 ,
struct V_37 * V_19 ,
long * V_33 , long * V_34 )
{
struct V_14 * V_8 = F_14 ( V_2 ) ;
unsigned long V_30 = 1UL << ( V_8 -> V_3 - 1 ) ;
unsigned long V_31 = V_30 - 1 ;
unsigned long V_32 ;
F_36 ( V_8 , V_19 ) ;
* V_33 = V_19 -> V_10 ;
V_32 = F_24 ( & V_8 -> V_10 ) ;
* V_34 = V_30 + ( V_32 & V_31 ) ;
F_17 ( V_2 , V_8 ) ;
}
