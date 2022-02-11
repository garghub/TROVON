static unsigned long F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_3 /= 10000 ;
V_3 <<= 14 ;
V_3 /= ( 2 * V_8 [ V_4 ] . div ) ;
V_3 *= 10000 ;
return V_3 ;
}
static long F_3 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_10 ;
return F_4 ( V_2 , V_9 , * V_3 , F_1 ,
V_6 -> V_11 , & V_10 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_12 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_13 = 0 ;
unsigned int div = 1 , V_14 ;
if ( V_6 -> V_15 )
F_6 ( V_6 -> V_15 , V_13 ) ;
V_14 = F_7 ( V_6 -> V_16 ) ;
if ( V_6 -> V_15 )
F_8 ( V_6 -> V_15 , V_13 ) ;
div = V_14 & V_17 ;
if ( ! div )
return 0 ;
V_12 = V_12 / 10000 ;
V_12 = ( V_12 << 14 ) / ( 2 * div ) ;
return V_12 * 10000 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned long V_13 = 0 , V_14 ;
int V_18 ;
F_4 ( V_2 , V_9 , V_3 , F_1 , V_6 -> V_11 ,
& V_18 ) ;
if ( V_6 -> V_15 )
F_6 ( V_6 -> V_15 , V_13 ) ;
V_14 = F_7 ( V_6 -> V_16 ) & ~ V_17 ;
V_14 |= V_8 [ V_18 ] . div & V_17 ;
F_10 ( V_14 , V_6 -> V_16 ) ;
if ( V_6 -> V_15 )
F_8 ( V_6 -> V_15 , V_13 ) ;
return 0 ;
}
struct V_19 * F_11 ( const char * V_20 , const char * V_21 ,
unsigned long V_13 , void T_1 * V_16 ,
struct V_7 * V_8 , T_2 V_11 , T_3 * V_15 )
{
struct V_22 V_23 ;
struct V_5 * V_6 ;
struct V_19 * V_19 ;
if ( ! V_20 || ! V_21 || ! V_16 || ! V_8 || ! V_11 ) {
F_12 ( L_1 ) ;
return F_13 ( - V_24 ) ;
}
V_6 = F_14 ( sizeof( * V_6 ) , V_25 ) ;
if ( ! V_6 ) {
F_12 ( L_2 ) ;
return F_13 ( - V_26 ) ;
}
V_6 -> V_16 = V_16 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_15 = V_15 ;
V_6 -> V_2 . V_23 = & V_23 ;
V_23 . V_20 = V_20 ;
V_23 . V_27 = & V_28 ;
V_23 . V_13 = V_13 ;
V_23 . V_29 = & V_21 ;
V_23 . V_30 = 1 ;
V_19 = F_15 ( NULL , & V_6 -> V_2 ) ;
if ( ! F_16 ( V_19 ) )
return V_19 ;
F_12 ( L_3 ) ;
F_17 ( V_6 ) ;
return NULL ;
}
