static int F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 -> V_3 ) ;
V_2 |= 1 << V_1 -> V_4 ;
F_3 ( V_2 , V_1 -> V_3 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 -> V_3 ) ;
V_2 &= ~ ( 1 << V_1 -> V_4 ) ;
F_3 ( V_2 , V_1 -> V_3 ) ;
}
static int F_5 ( const struct V_1 * V_5 [] , unsigned int V_6 ,
struct V_1 * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
if ( V_7 == V_5 [ V_8 ] )
return V_8 ;
return - V_9 ;
}
static unsigned long
F_6 ( struct V_1 * V_1 , unsigned long V_10 , unsigned int V_11 )
{
int div ;
unsigned long V_12 ;
V_12 = F_7 ( V_1 -> V_7 ) ;
div = V_12 / V_10 ;
if ( V_12 % V_10 )
div ++ ;
if ( div > V_11 )
div = V_11 ;
return V_12 / div ;
}
static unsigned long F_8 ( struct V_1 * V_1 , unsigned long V_10 )
{
return V_1 -> V_7 -> V_13 ( V_1 -> V_7 , V_10 ) ;
}
static int F_9 ( struct V_1 * V_1 , unsigned long V_10 )
{
return V_1 -> V_7 -> V_14 ( V_1 -> V_7 , V_10 ) ;
}
static unsigned long F_10 ( struct V_1 * V_1 )
{
return 16000000 ;
}
static unsigned long F_11 ( struct V_1 * V_1 )
{
return V_15 ;
}
static unsigned long F_12 ( struct V_1 * V_1 )
{
return F_7 ( V_1 -> V_7 ) * 512 ;
}
static int F_13 ( struct V_1 * V_1 , struct V_1 * V_7 )
{
int V_8 ;
unsigned int V_2 = F_2 ( V_16 ) ;
V_8 = F_5 ( V_17 , F_14 ( V_17 ) ,
V_7 ) ;
switch ( V_8 ) {
case 0 :
V_2 &= ~ V_18 ;
break;
case 1 :
V_2 |= V_18 ;
break;
default:
return V_8 ;
}
F_3 ( V_2 , V_16 ) ;
return 0 ;
}
static unsigned long F_15 ( struct V_1 * V_1 )
{
return F_16 ( F_2 ( V_19 ) ,
F_7 ( V_1 -> V_7 ) ) ;
}
static unsigned long F_17 ( struct V_1 * V_1 )
{
return F_16 ( F_2 ( V_20 ) ,
F_7 ( V_1 -> V_7 ) ) ;
}
static unsigned long F_18 ( struct V_1 * V_1 )
{
unsigned long V_21 = F_7 ( V_1 -> V_7 ) ;
if ( F_2 ( V_16 ) & V_22 )
V_21 /= 2 ;
return V_21 ;
}
static unsigned long F_19 ( struct V_1 * V_1 )
{
return F_7 ( V_1 -> V_7 ) / ( ( ( F_2 ( V_16 ) &
V_23 ) >> V_24 ) + 1 ) ;
}
static unsigned long F_20 ( struct V_1 * V_1 , unsigned long V_10 )
{
return F_6 ( V_1 , V_10 , 16 ) ;
}
static int F_21 ( struct V_1 * V_1 , unsigned long V_10 )
{
unsigned int div ;
unsigned int V_2 ;
unsigned long V_12 ;
V_12 = F_7 ( V_1 -> V_7 ) ;
div = V_12 / V_10 ;
if ( div > 16 || div < 1 || ( ( V_12 / div ) != V_10 ) )
return - V_9 ;
div -- ;
V_2 = F_2 ( V_16 ) ;
V_2 &= ~ V_23 ;
V_2 |= div << V_24 ;
F_3 ( V_2 , V_16 ) ;
return 0 ;
}
static unsigned long F_22 ( struct V_1 * V_1 )
{
return F_7 ( V_1 -> V_7 ) / ( ( ( F_2 ( V_16 ) &
V_25 ) >> V_26 ) + 1 ) ;
}
static unsigned long F_23 ( struct V_1 * V_1 , unsigned long V_10 )
{
return F_6 ( V_1 , V_10 , 8 ) ;
}
static int F_24 ( struct V_1 * V_1 , unsigned long V_10 )
{
unsigned int div ;
unsigned int V_2 ;
unsigned long V_12 ;
V_12 = F_7 ( V_1 -> V_7 ) ;
div = V_12 / V_10 ;
if ( div > 8 || div < 1 || ( ( V_12 / div ) != V_10 ) )
return - V_9 ;
div -- ;
V_2 = F_2 ( V_16 ) ;
V_2 &= ~ V_25 ;
V_2 |= div << V_26 ;
F_3 ( V_2 , V_16 ) ;
return 0 ;
}
static unsigned long F_25 ( struct V_1 * V_1 )
{
return F_7 ( V_1 -> V_7 ) / ( ( ( F_2 ( V_27 ) &
V_28 ) >> V_29 ) + 1 ) ;
}
static unsigned long F_26 ( struct V_1 * V_1 , unsigned long V_10 )
{
return F_6 ( V_1 , V_10 , 16 ) ;
}
static int F_27 ( struct V_1 * V_1 , unsigned long V_10 )
{
unsigned int div ;
unsigned int V_2 ;
unsigned long V_12 ;
V_12 = F_7 ( V_1 -> V_7 ) ;
div = V_12 / V_10 ;
if ( div > 16 || div < 1 || ( ( V_12 / div ) != V_10 ) )
return - V_9 ;
div -- ;
V_2 = F_2 ( V_27 ) ;
V_2 &= ~ V_28 ;
V_2 |= div << V_29 ;
F_3 ( V_2 , V_27 ) ;
return 0 ;
}
static unsigned long F_28 ( struct V_1 * V_1 )
{
return F_7 ( V_1 -> V_7 ) / ( ( ( F_2 ( V_27 ) &
V_30 ) >> V_31 ) + 1 ) ;
}
static unsigned long F_29 ( struct V_1 * V_1 , unsigned long V_10 )
{
return F_6 ( V_1 , V_10 , 16 ) ;
}
static int F_30 ( struct V_1 * V_1 , unsigned long V_10 )
{
unsigned int div ;
unsigned int V_2 ;
unsigned long V_12 ;
V_12 = F_7 ( V_1 -> V_7 ) ;
div = V_12 / V_10 ;
if ( div > 16 || div < 1 || ( ( V_12 / div ) != V_10 ) )
return - V_9 ;
div -- ;
V_2 = F_2 ( V_27 ) ;
V_2 &= ~ V_30 ;
V_2 |= div << V_31 ;
F_3 ( V_2 , V_27 ) ;
return 0 ;
}
static unsigned long F_31 ( struct V_1 * V_1 )
{
return F_7 ( V_1 -> V_7 ) / ( ( ( F_2 ( V_27 ) &
V_32 ) >> V_33 ) + 1 ) ;
}
static unsigned long F_32 ( struct V_1 * V_1 , unsigned long V_10 )
{
return F_6 ( V_1 , V_10 , 128 ) ;
}
static int F_33 ( struct V_1 * V_1 , unsigned long V_10 )
{
unsigned int div ;
unsigned int V_2 ;
unsigned long V_12 ;
V_12 = F_7 ( V_1 -> V_7 ) ;
div = V_12 / V_10 ;
if ( div > 128 || div < 1 || ( ( V_12 / div ) != V_10 ) )
return - V_9 ;
div -- ;
V_2 = F_2 ( V_27 ) ;
V_2 &= ~ V_32 ;
V_2 |= div << V_33 ;
F_3 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , struct V_1 * V_7 )
{
int V_8 ;
unsigned int V_2 ;
V_8 = F_5 ( V_34 , F_14 ( V_34 ) , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_2 = F_2 ( V_16 ) & ~ V_35 ;
V_2 |= V_8 << V_36 ;
F_3 ( V_2 , V_16 ) ;
if ( V_34 [ V_8 ] -> V_14 && V_34 [ V_8 ] -> V_13 ) {
V_1 -> V_14 = F_9 ;
V_1 -> V_13 = F_8 ;
} else {
V_1 -> V_14 = NULL ;
V_1 -> V_13 = NULL ;
}
return 0 ;
}
int T_1 F_35 ( unsigned long V_37 )
{
unsigned int V_2 ;
F_3 ( 0 , V_38 ) ;
V_15 = V_37 ;
V_2 = F_2 ( V_16 ) ;
if ( V_2 & V_18 ) {
V_39 . V_7 = & V_40 ;
} else {
V_2 &= ~ ( 1 << V_41 ) ;
F_3 ( V_2 , V_16 ) ;
V_39 . V_7 = & V_42 ;
}
V_2 = ( V_2 & V_35 ) >> V_36 ;
V_43 . V_7 = (struct V_1 * ) V_34 [ V_2 ] ;
F_36 ( V_44 , F_14 ( V_44 ) ) ;
F_37 ( & V_45 ) ;
F_37 ( & V_21 ) ;
F_38 ( & V_46 , F_39 ( V_47 ) ,
V_48 ) ;
return 0 ;
}
