static unsigned long F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_3 /= ( ( 1 << ( V_8 [ V_4 ] . V_9 + 1 ) ) * ( V_8 [ V_4 ] . V_10 + 1 ) ) ;
return V_3 ;
}
static long F_3 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_12 ;
return F_4 ( V_2 , V_11 , * V_3 , F_1 ,
V_6 -> V_13 , & V_12 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_15 = 0 ;
unsigned int div = 1 , V_16 ;
if ( V_6 -> V_17 )
F_6 ( V_6 -> V_17 , V_15 ) ;
V_16 = F_7 ( V_6 -> V_18 ) ;
if ( V_6 -> V_17 )
F_8 ( V_6 -> V_17 , V_15 ) ;
div += V_16 & V_19 ;
div *= 1 << ( ( ( V_16 >> V_20 ) & V_21 ) + 1 ) ;
if ( ! div )
return 0 ;
return V_14 / div ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned long V_15 = 0 , V_16 ;
int V_22 ;
F_4 ( V_2 , V_11 , V_3 , F_1 , V_6 -> V_13 ,
& V_22 ) ;
if ( V_6 -> V_17 )
F_6 ( V_6 -> V_17 , V_15 ) ;
V_16 = F_10 ( V_6 -> V_18 ) & ~ V_19 ;
V_16 &= ~ ( V_21 << V_20 ) ;
V_16 |= V_8 [ V_22 ] . V_10 & V_19 ;
V_16 |= ( V_8 [ V_22 ] . V_9 & V_21 ) << V_20 ;
F_11 ( V_16 , V_6 -> V_18 ) ;
if ( V_6 -> V_17 )
F_8 ( V_6 -> V_17 , V_15 ) ;
return 0 ;
}
struct V_23 * F_12 ( const char * V_24 , const char * V_25 , unsigned
long V_15 , void T_1 * V_18 , struct V_7 * V_8 , T_2
V_13 , T_3 * V_17 )
{
struct V_26 V_27 ;
struct V_5 * V_6 ;
struct V_23 * V_23 ;
if ( ! V_24 || ! V_25 || ! V_18 || ! V_8 || ! V_13 ) {
F_13 ( L_1 ) ;
return F_14 ( - V_28 ) ;
}
V_6 = F_15 ( sizeof( * V_6 ) , V_29 ) ;
if ( ! V_6 ) {
F_13 ( L_2 ) ;
return F_14 ( - V_30 ) ;
}
V_6 -> V_18 = V_18 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_17 = V_17 ;
V_6 -> V_2 . V_27 = & V_27 ;
V_27 . V_24 = V_24 ;
V_27 . V_31 = & V_32 ;
V_27 . V_15 = V_15 ;
V_27 . V_33 = & V_25 ;
V_27 . V_34 = 1 ;
V_23 = F_16 ( NULL , & V_6 -> V_2 ) ;
if ( ! F_17 ( V_23 ) )
return V_23 ;
F_13 ( L_3 ) ;
F_18 ( V_6 ) ;
return NULL ;
}
