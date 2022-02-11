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
T_1 V_10 = * V_13 ;
T_2 V_11 ;
V_10 = V_10 * 18 + V_12 / 2 ;
F_7 ( V_10 , V_12 ) ;
V_11 = V_10 ;
if ( V_11 < 12 )
V_11 = 12 ;
else if ( V_11 > 35 )
V_11 = 35 ;
V_10 = * V_13 ;
V_10 *= 18 ;
F_7 ( V_10 , V_11 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_10 = V_9 ;
T_2 V_11 ;
V_10 = V_10 * 18 + V_12 / 2 ;
F_7 ( V_10 , V_12 ) ;
V_11 = V_10 ;
if ( V_11 < 12 )
V_11 = 12 ;
else if ( V_11 > 35 )
V_11 = 35 ;
F_3 ( 0x3f << ( V_4 -> V_5 * 8 ) , V_4 -> V_6 + V_7 ) ;
F_3 ( V_11 << ( V_4 -> V_5 * 8 ) , V_4 -> V_6 + V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_6 ( V_4 -> V_6 ) & ( 1 << ( ( V_4 -> V_5 + 1 ) * 8 - 1 ) ) )
return 0 ;
return 1 ;
}
struct V_14 * F_11 ( const char * V_15 , const char * V_16 ,
void T_3 * V_6 , T_2 V_5 )
{
struct V_3 * V_4 ;
struct V_14 * V_14 ;
struct V_17 V_18 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return F_13 ( - V_20 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_5 = V_5 ;
V_18 . V_15 = V_15 ;
V_18 . V_21 = & V_22 ;
V_18 . V_23 = 0 ;
V_18 . V_24 = & V_16 ;
V_18 . V_25 = 1 ;
V_4 -> V_2 . V_18 = & V_18 ;
V_14 = F_14 ( NULL , & V_4 -> V_2 ) ;
if ( F_15 ( V_14 ) )
F_16 ( V_4 ) ;
return V_14 ;
}
