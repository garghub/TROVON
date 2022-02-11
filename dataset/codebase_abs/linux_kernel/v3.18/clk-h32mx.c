static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_3 ( V_5 -> V_6 , V_7 ) & V_8 )
return V_3 / 2 ;
if ( V_3 > V_9 )
F_4 ( L_1 ) ;
return V_3 ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_10 ,
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
static int F_6 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_11 * V_6 = V_5 -> V_6 ;
T_1 V_12 ;
if ( V_3 != V_10 && ( V_3 / 2 ) != V_10 )
return - V_13 ;
F_7 ( V_6 ) ;
V_12 = F_3 ( V_6 , V_7 ) & ~ V_8 ;
if ( ( V_3 / 2 ) == V_10 )
V_12 |= V_8 ;
F_8 ( V_6 , V_7 , V_12 ) ;
F_9 ( V_6 ) ;
return 0 ;
}
void T_2 F_10 ( struct V_14 * V_15 ,
struct V_11 * V_6 )
{
struct V_4 * V_5 ;
struct V_16 V_17 ;
const char * V_18 ;
struct V_19 * V_19 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 )
return;
V_18 = F_12 ( V_15 , 0 ) ;
V_17 . V_21 = V_15 -> V_21 ;
V_17 . V_22 = & V_23 ;
V_17 . V_24 = V_18 ? & V_18 : NULL ;
V_17 . V_25 = V_18 ? 1 : 0 ;
V_17 . V_26 = V_27 ;
V_5 -> V_2 . V_17 = & V_17 ;
V_5 -> V_6 = V_6 ;
V_19 = F_13 ( NULL , & V_5 -> V_2 ) ;
if ( ! V_19 )
return;
F_14 ( V_15 , V_28 , V_19 ) ;
}
