static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 1 << ( ( V_4 -> V_5 + 1 ) * 8 - 1 ) , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 1 << ( ( V_4 -> V_5 + 1 ) * 8 - 1 ) , V_4 -> V_6 + V_8 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_10 = V_9 ;
T_2 V_11 = ( F_6 ( V_4 -> V_6 ) >> ( V_4 -> V_5 * 8 ) ) & 0x3f ;
V_10 *= 18 ;
F_7 ( V_10 , V_11 ) ;
return V_10 ;
}
static long F_8 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long * V_13 )
{
unsigned long V_9 = * V_13 ;
T_1 V_10 = V_9 ;
T_2 V_11 ;
V_10 = V_10 * 18 + V_12 / 2 ;
F_7 ( V_10 , V_12 ) ;
V_11 = V_10 ;
if ( V_11 < 18 )
V_11 = 18 ;
else if ( V_11 > 35 )
V_11 = 35 ;
V_10 = V_9 ;
V_10 *= 18 ;
F_7 ( V_10 , V_11 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_14 ;
T_1 V_10 = V_9 ;
T_3 V_15 ;
T_2 V_11 , V_16 = V_4 -> V_5 * 8 ;
V_10 = V_10 * 18 + V_12 / 2 ;
F_7 ( V_10 , V_12 ) ;
V_11 = V_10 ;
if ( V_11 < 18 )
V_11 = 18 ;
else if ( V_11 > 35 )
V_11 = 35 ;
F_10 ( & V_17 , V_14 ) ;
V_15 = F_6 ( V_4 -> V_6 ) ;
V_15 &= ~ ( 0x3f << V_16 ) ;
V_15 |= V_11 << V_16 ;
F_3 ( V_15 , V_4 -> V_6 ) ;
F_11 ( & V_17 , V_14 ) ;
return 0 ;
}
struct V_18 * F_12 ( const char * V_19 , const char * V_20 ,
void T_4 * V_6 , T_2 V_5 )
{
struct V_3 * V_4 ;
struct V_18 * V_18 ;
struct V_21 V_22 ;
V_4 = F_13 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return F_14 ( - V_24 ) ;
V_22 . V_19 = V_19 ;
V_22 . V_25 = & V_26 ;
V_22 . V_14 = 0 ;
V_22 . V_27 = ( V_20 ? & V_20 : NULL ) ;
V_22 . V_28 = ( V_20 ? 1 : 0 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 . V_22 = & V_22 ;
V_18 = F_15 ( NULL , & V_4 -> V_2 ) ;
if ( F_16 ( V_18 ) )
F_17 ( V_4 ) ;
return V_18 ;
}
