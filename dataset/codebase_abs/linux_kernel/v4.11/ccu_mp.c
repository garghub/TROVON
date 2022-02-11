static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned int V_3 , unsigned int V_4 ,
unsigned int * V_5 , unsigned int * V_6 )
{
unsigned long V_7 = 0 ;
unsigned int V_8 = 0 , V_9 = 0 ;
unsigned int V_10 , V_11 ;
for ( V_11 = 1 ; V_11 <= V_4 ; V_11 <<= 1 ) {
for ( V_10 = 1 ; V_10 <= V_3 ; V_10 ++ ) {
unsigned long V_12 = V_1 / V_11 / V_10 ;
if ( V_12 > V_2 )
continue;
if ( ( V_2 - V_12 ) < ( V_2 - V_7 ) ) {
V_7 = V_12 ;
V_8 = V_10 ;
V_9 = V_11 ;
}
}
}
* V_5 = V_8 ;
* V_6 = V_9 ;
}
static unsigned long F_2 ( struct V_13 * V_14 ,
unsigned long V_15 ,
unsigned long V_2 ,
void * V_16 )
{
struct V_17 * V_18 = V_16 ;
unsigned int V_3 , V_4 ;
unsigned int V_5 , V_6 ;
V_3 = V_18 -> V_5 . V_19 ? : 1 << V_18 -> V_5 . V_20 ;
V_4 = V_18 -> V_6 . V_19 ? : 1 << ( ( 1 << V_18 -> V_6 . V_20 ) - 1 ) ;
F_1 ( V_15 , V_2 , V_3 , V_4 , & V_5 , & V_6 ) ;
return V_15 / V_6 / V_5 ;
}
static void F_3 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = F_4 ( V_22 ) ;
return F_5 ( & V_18 -> V_23 , V_18 -> V_24 ) ;
}
static int F_6 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = F_4 ( V_22 ) ;
return F_7 ( & V_18 -> V_23 , V_18 -> V_24 ) ;
}
static int F_8 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = F_4 ( V_22 ) ;
return F_9 ( & V_18 -> V_23 , V_18 -> V_24 ) ;
}
static unsigned long F_10 ( struct V_21 * V_22 ,
unsigned long V_15 )
{
struct V_17 * V_18 = F_4 ( V_22 ) ;
unsigned int V_5 , V_6 ;
T_1 V_25 ;
F_11 ( & V_18 -> V_23 , & V_18 -> V_14 ,
- 1 , & V_15 ) ;
V_25 = F_12 ( V_18 -> V_23 . V_26 + V_18 -> V_23 . V_25 ) ;
V_5 = V_25 >> V_18 -> V_5 . V_27 ;
V_5 &= ( 1 << V_18 -> V_5 . V_20 ) - 1 ;
V_5 += V_18 -> V_5 . V_28 ;
if ( ! V_5 )
V_5 ++ ;
V_6 = V_25 >> V_18 -> V_6 . V_27 ;
V_6 &= ( 1 << V_18 -> V_6 . V_20 ) - 1 ;
return ( V_15 >> V_6 ) / V_5 ;
}
static int F_13 ( struct V_21 * V_22 ,
struct V_29 * V_30 )
{
struct V_17 * V_18 = F_4 ( V_22 ) ;
return F_14 ( & V_18 -> V_23 , & V_18 -> V_14 ,
V_30 , F_2 , V_18 ) ;
}
static int F_15 ( struct V_21 * V_22 , unsigned long V_2 ,
unsigned long V_15 )
{
struct V_17 * V_18 = F_4 ( V_22 ) ;
unsigned long V_31 ;
unsigned int V_3 , V_4 ;
unsigned int V_5 , V_6 ;
T_1 V_25 ;
F_11 ( & V_18 -> V_23 , & V_18 -> V_14 ,
- 1 , & V_15 ) ;
V_3 = V_18 -> V_5 . V_19 ? : 1 << V_18 -> V_5 . V_20 ;
V_4 = V_18 -> V_6 . V_19 ? : 1 << ( ( 1 << V_18 -> V_6 . V_20 ) - 1 ) ;
F_1 ( V_15 , V_2 , V_3 , V_4 , & V_5 , & V_6 ) ;
F_16 ( V_18 -> V_23 . V_32 , V_31 ) ;
V_25 = F_12 ( V_18 -> V_23 . V_26 + V_18 -> V_23 . V_25 ) ;
V_25 &= ~ F_17 ( V_18 -> V_5 . V_20 + V_18 -> V_5 . V_27 - 1 , V_18 -> V_5 . V_27 ) ;
V_25 &= ~ F_17 ( V_18 -> V_6 . V_20 + V_18 -> V_6 . V_27 - 1 , V_18 -> V_6 . V_27 ) ;
V_25 |= ( V_5 - V_18 -> V_5 . V_28 ) << V_18 -> V_5 . V_27 ;
V_25 |= F_18 ( V_6 ) << V_18 -> V_6 . V_27 ;
F_19 ( V_25 , V_18 -> V_23 . V_26 + V_18 -> V_23 . V_25 ) ;
F_20 ( V_18 -> V_23 . V_32 , V_31 ) ;
return 0 ;
}
static T_2 F_21 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = F_4 ( V_22 ) ;
return F_22 ( & V_18 -> V_23 , & V_18 -> V_14 ) ;
}
static int F_23 ( struct V_21 * V_22 , T_2 V_33 )
{
struct V_17 * V_18 = F_4 ( V_22 ) ;
return F_24 ( & V_18 -> V_23 , & V_18 -> V_14 , V_33 ) ;
}
