static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 , V_5 ;
int V_6 ;
int V_7 ;
const char * V_8 = F_2 ( & V_2 -> V_9 . V_10 ) ;
V_5 = V_2 -> V_11 ;
V_7 = F_3 ( V_2 -> V_9 . V_12 , V_5 + V_13 , & V_3 ) ;
if ( V_7 )
return V_7 ;
if ( V_3 & V_14 )
V_4 = V_15 ;
else
V_4 = V_16 ;
for ( V_6 = 100 ; V_6 > 0 ; V_6 -- ) {
V_7 = F_3 ( V_2 -> V_9 . V_12 , V_5 + V_13 , & V_3 ) ;
if ( V_7 )
return V_7 ;
if ( ( V_3 & V_4 ) == V_4 )
return 0 ;
F_4 ( 1 ) ;
}
F_5 ( 1 , L_1 , V_8 ) ;
return - V_17 ;
}
static int F_6 ( struct V_18 * V_10 )
{
int V_7 ;
struct V_1 * V_2 = F_7 ( V_10 ) ;
T_1 V_3 , V_4 , V_5 ;
V_5 = V_2 -> V_11 ;
V_4 = V_19 | V_20 | V_21 ;
V_7 = F_3 ( V_2 -> V_9 . V_12 , V_5 + V_13 , & V_3 ) ;
if ( V_7 )
return V_7 ;
if ( V_3 & V_14 ) {
V_7 = F_8 ( V_10 ) ;
if ( V_7 )
return V_7 ;
return F_1 ( V_2 ) ;
}
if ( ( V_3 & V_4 ) == V_4 )
return 0 ;
V_7 = F_9 ( V_2 -> V_9 . V_12 , V_5 + V_13 ,
V_21 , V_21 ) ;
if ( V_7 )
return V_7 ;
F_10 () ;
F_4 ( 5 ) ;
V_7 = F_9 ( V_2 -> V_9 . V_12 , V_5 + V_13 ,
V_20 , V_20 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_9 ( V_2 -> V_9 . V_12 , V_5 + V_13 ,
V_19 , V_19 ) ;
F_10 () ;
return V_7 ;
}
static void F_11 ( struct V_18 * V_10 )
{
int V_7 ;
struct V_1 * V_2 = F_7 ( V_10 ) ;
T_1 V_3 , V_4 , V_5 ;
V_5 = V_2 -> V_11 ;
V_7 = F_3 ( V_2 -> V_9 . V_12 , V_5 + V_13 , & V_3 ) ;
if ( V_7 )
return;
if ( V_3 & V_14 ) {
F_12 ( V_10 ) ;
return;
}
V_4 = V_19 ;
F_9 ( V_2 -> V_9 . V_12 , V_5 + V_13 , V_4 , 0 ) ;
F_10 () ;
F_4 ( 1 ) ;
V_4 = V_20 | V_21 ;
F_9 ( V_2 -> V_9 . V_12 , V_5 + V_13 , V_4 , 0 ) ;
}
static unsigned long F_13 ( T_2 V_22 , T_1 V_23 , T_1 V_24 )
{
return ( V_22 * V_23 ) + ( ( V_22 * V_24 ) >> V_25 ) ;
}
static unsigned long
F_14 ( unsigned long V_26 , unsigned long V_22 , T_1 * V_23 , T_2 * V_24 )
{
T_2 V_27 ;
T_2 V_28 ;
V_28 = V_26 ;
V_27 = F_15 ( V_28 , V_22 ) ;
* V_23 = V_28 ;
if ( ! V_27 ) {
* V_24 = 0 ;
return V_26 ;
}
V_28 = V_27 << V_25 ;
V_27 = F_15 ( V_28 , V_22 ) ;
if ( V_27 )
V_28 ++ ;
* V_24 = V_28 ;
return F_13 ( V_22 , * V_23 , * V_24 ) ;
}
static const struct V_29 *
F_16 ( const struct V_1 * V_2 , unsigned long V_26 )
{
const struct V_29 * V_30 = V_2 -> V_31 ;
const struct V_29 * V_32 = V_30 + V_2 -> V_33 ;
for (; V_30 < V_32 ; V_30 ++ )
if ( V_26 >= V_30 -> V_34 && V_26 <= V_30 -> V_35 )
return V_30 ;
return NULL ;
}
static unsigned long
F_17 ( struct V_18 * V_10 , unsigned long V_36 )
{
T_1 V_23 , V_37 , V_38 , V_39 ;
T_2 V_24 = 0 , V_22 = V_36 ;
struct V_1 * V_2 = F_7 ( V_10 ) ;
T_1 V_5 = V_2 -> V_11 ;
F_3 ( V_2 -> V_9 . V_12 , V_5 + V_40 , & V_23 ) ;
F_3 ( V_2 -> V_9 . V_12 , V_5 + V_41 , & V_39 ) ;
if ( V_39 & V_42 ) {
F_3 ( V_2 -> V_9 . V_12 , V_5 + V_43 , & V_37 ) ;
F_3 ( V_2 -> V_9 . V_12 , V_5 + V_44 , & V_38 ) ;
V_24 = ( T_2 ) V_38 << 32 | V_37 ;
V_24 >>= V_45 - V_25 ;
}
return F_13 ( V_22 , V_23 , V_24 ) ;
}
static int F_18 ( struct V_18 * V_10 , unsigned long V_26 ,
unsigned long V_22 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
const struct V_29 * V_46 ;
T_1 V_23 , V_5 = V_2 -> V_11 ;
T_2 V_24 ;
V_26 = F_14 ( V_26 , V_22 , & V_23 , & V_24 ) ;
V_46 = F_16 ( V_2 , V_26 ) ;
if ( ! V_46 ) {
F_19 ( L_2 ) ;
return - V_47 ;
}
V_24 <<= ( V_45 - V_25 ) ;
F_20 ( V_2 -> V_9 . V_12 , V_5 + V_40 , V_23 ) ;
F_20 ( V_2 -> V_9 . V_12 , V_5 + V_43 , V_24 ) ;
F_20 ( V_2 -> V_9 . V_12 , V_5 + V_44 , V_24 >> 32 ) ;
F_9 ( V_2 -> V_9 . V_12 , V_5 + V_41 ,
V_48 << V_49 ,
V_46 -> V_3 << V_49 ) ;
F_9 ( V_2 -> V_9 . V_12 , V_5 + V_41 , V_42 ,
V_42 ) ;
return 0 ;
}
static long F_21 ( struct V_18 * V_10 , unsigned long V_26 ,
unsigned long * V_22 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
T_1 V_23 ;
T_2 V_24 ;
unsigned long V_34 , V_35 ;
V_26 = F_14 ( V_26 , * V_22 , & V_23 , & V_24 ) ;
if ( F_16 ( V_2 , V_26 ) )
return V_26 ;
V_34 = V_2 -> V_31 [ 0 ] . V_34 ;
V_35 = V_2 -> V_31 [ V_2 -> V_33 - 1 ] . V_35 ;
return F_22 ( V_26 , V_34 , V_35 ) ;
}
static unsigned long
F_23 ( struct V_18 * V_10 , unsigned long V_36 )
{
struct V_50 * V_2 = F_24 ( V_10 ) ;
T_1 V_39 ;
F_3 ( V_2 -> V_9 . V_12 , V_2 -> V_11 + V_41 , & V_39 ) ;
V_39 >>= V_51 ;
V_39 &= V_52 ;
return V_36 >> F_25 ( V_39 ) ;
}
static long
F_26 ( struct V_18 * V_10 , unsigned long V_26 ,
unsigned long * V_22 )
{
struct V_50 * V_2 = F_24 ( V_10 ) ;
return F_27 ( V_10 , V_26 , V_22 , V_53 ,
V_2 -> V_54 , V_55 ) ;
}
static int F_28 ( struct V_18 * V_10 , unsigned long V_26 ,
unsigned long V_36 )
{
struct V_50 * V_2 = F_24 ( V_10 ) ;
int div ;
div = F_29 ( ( T_2 ) V_36 , V_26 ) - 1 ;
return F_9 ( V_2 -> V_9 . V_12 , V_2 -> V_11 + V_41 ,
V_52 << V_51 ,
div << V_51 ) ;
}
