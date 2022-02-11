static int F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_2 , 0x8304 , 0xdddd ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , T_1 V_3 )
{
T_1 V_4 = 0 ;
#define F_4 0x1
F_5 ( V_1 , V_5 , V_6 , & V_4 ) ;
if ( V_3 & F_4 ) {
V_4 |= F_4 ;
F_2 ( V_1 , V_5 , V_6 , V_4 ) ;
} else {
V_4 &= ~ F_4 ;
F_2 ( V_1 , V_5 , V_6 , V_4 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , int V_7 )
{
return 0 ;
}
static int F_7 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_5 , V_8 ,
V_9 ) ;
if ( F_8 ( V_1 -> V_10 ) ) {
T_1 V_11 ;
F_9 ( V_1 -> V_10 , V_12 , & V_11 ) ;
V_11 |= V_13 ;
F_10 ( V_1 -> V_10 , V_12 , V_11 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_5 , V_8 , 0x0 ) ;
if ( F_8 ( V_1 -> V_10 ) ) {
T_1 V_11 ;
F_9 ( V_1 -> V_10 , V_12 , & V_11 ) ;
V_11 &= ~ V_13 ;
F_10 ( V_1 -> V_10 , V_12 , V_11 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
T_1 V_11 ;
T_1 V_14 ;
#ifdef F_13
F_5 ( V_1 , V_5 , V_15 , & V_14 ) ;
F_5 ( V_1 , V_5 , V_16 , & V_14 ) ;
F_5 ( V_1 , V_5 , V_17 , & V_14 ) ;
F_5 ( V_1 , V_5 , V_18 , & V_14 ) ;
#endif
F_5 ( V_1 , V_5 , V_18 , & V_14 ) ;
F_5 ( V_1 , V_5 , V_17 , & V_14 ) ;
#ifdef F_13
F_5 ( V_1 , V_5 , V_15 , & V_14 ) ;
F_5 ( V_1 , V_5 , V_16 , & V_14 ) ;
#endif
if ( F_8 ( V_1 -> V_10 ) ) {
F_9 ( V_1 -> V_10 , V_19 , & V_11 ) ;
V_11 |= V_13 ;
F_10 ( V_1 -> V_10 , V_19 , V_11 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
F_12 ( V_1 ) ;
return V_20 ;
}
static int F_15 ( struct V_1 * V_1 , int V_21 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_1 , int * V_22 ,
int * V_23 , int * V_24 , int * V_25 )
{
T_1 V_14 = 0 ;
if ( V_22 ) {
F_5 ( V_1 , V_5 , V_18 , & V_14 ) ;
V_14 &= V_26 ;
* V_22 = ( V_14 == V_26 ) ;
F_3 ( V_1 , * V_22 ) ;
}
if ( V_23 )
* V_23 = V_27 ;
if ( V_24 )
* V_24 = V_28 ;
if ( V_25 )
* V_25 = V_29 | V_30 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_1 )
{
F_18 ( V_1 ) ;
}
static struct V_1 * F_19 ( struct V_31 * V_32 , int V_33 ,
const struct V_34 * V_34 )
{
T_1 V_14 ;
struct V_1 * V_1 = F_20 ( sizeof( * V_1 ) , V_35 ) ;
if ( ! V_1 )
return NULL ;
F_21 ( V_1 , V_32 , V_33 , & V_36 , V_34 ) ;
F_5 ( V_1 , V_2 , 0x8300 , & V_14 ) ;
F_2 ( V_1 , V_2 , 0x8300 , V_14 | 1 ) ;
F_5 ( V_1 , V_5 , V_37 , & V_14 ) ;
F_5 ( V_1 , V_2 , V_37 , & V_14 ) ;
F_1 ( V_1 ) ;
return V_1 ;
}
static int F_22 ( T_2 * V_10 )
{
T_1 V_14 ;
F_9 ( V_10 , V_38 , & V_14 ) ;
V_14 &= ~ 4 ;
F_10 ( V_10 , V_38 , V_14 ) ;
F_23 ( 100 ) ;
F_10 ( V_10 , V_38 , V_14 | 4 ) ;
F_23 ( 1000 ) ;
F_9 ( V_10 , V_38 , & V_14 ) ;
V_14 |= 0x8000 ;
F_10 ( V_10 , V_38 , V_14 ) ;
F_24 ( 100 ) ;
return 0 ;
}
