static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
unsigned long V_6 = 0 ;
if ( V_4 -> V_7 )
F_3 ( V_4 -> V_7 , V_6 ) ;
V_5 = F_4 ( V_4 -> V_5 ) ;
V_5 |= 3 << V_4 -> V_8 ;
F_5 ( V_5 , V_4 -> V_5 ) ;
if ( V_4 -> V_7 )
F_6 ( V_4 -> V_7 , V_6 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
unsigned long V_6 = 0 ;
if ( V_4 -> V_7 )
F_3 ( V_4 -> V_7 , V_6 ) ;
V_5 = F_4 ( V_4 -> V_5 ) ;
V_5 &= ~ ( 3 << V_4 -> V_8 ) ;
F_5 ( V_5 , V_4 -> V_5 ) ;
if ( V_4 -> V_7 )
F_6 ( V_4 -> V_7 , V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_5 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_5 = F_4 ( V_4 -> V_5 ) ;
if ( ( ( V_5 >> V_4 -> V_8 ) & 3 ) == 3 )
return 1 ;
return 0 ;
}
struct V_9 * F_9 ( struct V_10 * V_11 , const char * V_12 ,
const char * V_13 , unsigned long V_6 ,
void T_2 * V_5 , T_3 V_8 ,
T_3 V_14 , T_4 * V_7 )
{
struct V_3 * V_4 ;
struct V_9 * V_9 ;
struct V_15 V_16 ;
V_4 = F_10 ( sizeof( struct V_3 ) , V_17 ) ;
if ( ! V_4 )
return F_11 ( - V_18 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_6 = V_14 ;
V_4 -> V_7 = V_7 ;
V_16 . V_12 = V_12 ;
V_16 . V_19 = & V_20 ;
V_16 . V_6 = V_6 ;
V_16 . V_21 = V_13 ? & V_13 : NULL ;
V_16 . V_22 = V_13 ? 1 : 0 ;
V_4 -> V_2 . V_16 = & V_16 ;
V_9 = F_12 ( V_11 , & V_4 -> V_2 ) ;
if ( F_13 ( V_9 ) )
F_14 ( V_4 ) ;
return V_9 ;
}
