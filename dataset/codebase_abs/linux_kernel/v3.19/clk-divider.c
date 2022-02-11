static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
T_1 V_5 = V_4 ;
T_2 V_6 = V_2 -> V_6 ;
int V_7 ;
if ( ! V_3 )
return 0 ;
V_7 = F_2 ( V_2 ) ;
if ( ! ( V_6 & V_8 ) )
V_5 *= V_7 ;
if ( V_6 & V_9 )
V_5 += V_3 - 1 ;
F_3 ( V_5 , V_3 ) ;
if ( V_6 & V_8 )
V_5 *= V_7 ;
V_5 -= V_7 ;
if ( V_5 < 0 )
return 0 ;
if ( V_5 > F_4 ( V_2 ) )
return F_4 ( V_2 ) ;
return V_5 ;
}
static unsigned long F_5 ( struct V_10 * V_11 ,
unsigned long V_4 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
T_3 V_12 ;
int div , V_7 ;
T_4 V_3 = V_4 ;
V_12 = F_7 ( V_2 -> V_12 ) >> V_2 -> V_13 ;
div = V_12 & F_8 ( V_2 ) ;
V_7 = F_2 ( V_2 ) ;
div += V_7 ;
V_3 *= V_7 ;
V_3 += div - 1 ;
F_3 ( V_3 , div ) ;
return V_3 ;
}
static long F_9 ( struct V_10 * V_11 , unsigned long V_3 ,
unsigned long * V_14 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
int div , V_7 ;
unsigned long V_15 = * V_14 ;
if ( ! V_3 )
return V_15 ;
div = F_1 ( V_2 , V_3 , V_15 ) ;
if ( div < 0 )
return * V_14 ;
V_7 = F_2 ( V_2 ) ;
return F_10 ( V_15 * V_7 , div + V_7 ) ;
}
static int F_11 ( struct V_10 * V_11 , unsigned long V_3 ,
unsigned long V_4 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
int div ;
unsigned long V_6 = 0 ;
T_3 V_16 ;
div = F_1 ( V_2 , V_3 , V_4 ) ;
if ( div < 0 )
return div ;
if ( V_2 -> V_17 )
F_12 ( V_2 -> V_17 , V_6 ) ;
V_16 = F_7 ( V_2 -> V_12 ) ;
V_16 &= ~ ( F_8 ( V_2 ) << V_2 -> V_13 ) ;
V_16 |= div << V_2 -> V_13 ;
if ( V_2 -> V_6 & V_18 ) {
if ( div )
V_16 |= V_19 ;
else
V_16 &= ~ V_19 ;
}
if ( V_2 -> V_6 & V_20 )
V_16 |= F_13 ( V_2 ) ;
F_14 ( V_16 , V_2 -> V_12 ) ;
if ( V_2 -> V_17 )
F_15 ( V_2 -> V_17 , V_6 ) ;
return 0 ;
}
struct V_21 * F_16 ( const char * V_22 ,
const char * V_23 , void T_5 * V_12 ,
unsigned long V_6 , T_2 V_24 , T_2 V_13 , T_2 V_25 ,
T_2 V_26 , T_6 * V_17 )
{
struct V_1 * V_2 ;
struct V_21 * V_21 ;
struct V_27 V_28 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 ) {
F_18 ( L_1 ,
V_30 ) ;
return F_19 ( - V_31 ) ;
}
V_28 . V_22 = V_22 ;
V_28 . V_32 = & V_33 ;
V_28 . V_6 = V_6 ;
V_28 . V_34 = V_23 ? & V_23 : NULL ;
V_28 . V_35 = V_23 ? 1 : 0 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_6 = V_24 ;
V_2 -> V_11 . V_28 = & V_28 ;
V_21 = F_20 ( NULL , & V_2 -> V_11 ) ;
if ( F_21 ( V_21 ) )
F_22 ( V_2 ) ;
return V_21 ;
}
struct V_21 * F_23 ( const char * V_22 , const char * V_23 ,
void T_5 * V_12 , T_6 * V_17 )
{
return F_24 ( NULL , V_22 , V_23 , 0 , V_12 ,
16 , 1 , 0 , V_36 , V_17 ) ;
}
