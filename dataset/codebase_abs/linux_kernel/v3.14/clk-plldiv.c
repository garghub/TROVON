static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( F_3 ( V_7 , V_8 ) & V_9 )
return V_3 / 2 ;
return V_3 ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long * V_3 )
{
unsigned long div ;
if ( V_10 > * V_3 )
return * V_3 ;
div = * V_3 / 2 ;
if ( V_10 < div )
return div ;
if ( V_10 - div < * V_3 - V_10 )
return div ;
return * V_3 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_11 ;
if ( V_3 != V_10 && ( V_3 / 2 ) != V_10 )
return - V_12 ;
F_6 ( V_7 ) ;
V_11 = F_3 ( V_7 , V_8 ) & ~ V_9 ;
if ( ( V_3 / 2 ) == V_10 )
V_11 |= V_9 ;
F_7 ( V_7 , V_8 , V_11 ) ;
F_8 ( V_7 ) ;
return 0 ;
}
static struct V_13 * T_2
F_9 ( struct V_6 * V_7 , const char * V_14 ,
const char * V_15 )
{
struct V_4 * V_5 ;
struct V_13 * V_13 = NULL ;
struct V_16 V_17 ;
V_5 = F_10 ( sizeof( * V_5 ) , V_18 ) ;
if ( ! V_5 )
return F_11 ( - V_19 ) ;
V_17 . V_14 = V_14 ;
V_17 . V_20 = & V_21 ;
V_17 . V_22 = V_15 ? & V_15 : NULL ;
V_17 . V_23 = V_15 ? 1 : 0 ;
V_17 . V_24 = V_25 ;
V_5 -> V_2 . V_17 = & V_17 ;
V_5 -> V_7 = V_7 ;
V_13 = F_12 ( NULL , & V_5 -> V_2 ) ;
if ( F_13 ( V_13 ) )
F_14 ( V_5 ) ;
return V_13 ;
}
static void T_2
F_15 ( struct V_26 * V_27 , struct V_6 * V_7 )
{
struct V_13 * V_13 ;
const char * V_15 ;
const char * V_14 = V_27 -> V_14 ;
V_15 = F_16 ( V_27 , 0 ) ;
F_17 ( V_27 , L_1 , & V_14 ) ;
V_13 = F_9 ( V_7 , V_14 , V_15 ) ;
if ( F_13 ( V_13 ) )
return;
F_18 ( V_27 , V_28 , V_13 ) ;
return;
}
void T_2 F_19 ( struct V_26 * V_27 ,
struct V_6 * V_7 )
{
F_15 ( V_27 , V_7 ) ;
}
