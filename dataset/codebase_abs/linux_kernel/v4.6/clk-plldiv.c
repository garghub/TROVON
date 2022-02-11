static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( V_5 -> V_7 , V_8 , & V_6 ) ;
if ( V_6 & V_9 )
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
if ( ( V_3 != V_10 ) && ( V_3 / 2 != V_10 ) )
return - V_11 ;
F_6 ( V_5 -> V_7 , V_8 , V_9 ,
V_3 != V_10 ? V_9 : 0 ) ;
return 0 ;
}
static struct V_12 * T_1
F_7 ( struct V_7 * V_7 , const char * V_13 ,
const char * V_14 )
{
struct V_4 * V_5 ;
struct V_12 * V_12 = NULL ;
struct V_15 V_16 ;
V_5 = F_8 ( sizeof( * V_5 ) , V_17 ) ;
if ( ! V_5 )
return F_9 ( - V_18 ) ;
V_16 . V_13 = V_13 ;
V_16 . V_19 = & V_20 ;
V_16 . V_21 = V_14 ? & V_14 : NULL ;
V_16 . V_22 = V_14 ? 1 : 0 ;
V_16 . V_23 = V_24 ;
V_5 -> V_2 . V_16 = & V_16 ;
V_5 -> V_7 = V_7 ;
V_12 = F_10 ( NULL , & V_5 -> V_2 ) ;
if ( F_11 ( V_12 ) )
F_12 ( V_5 ) ;
return V_12 ;
}
static void T_1
F_13 ( struct V_25 * V_26 )
{
struct V_12 * V_12 ;
const char * V_14 ;
const char * V_13 = V_26 -> V_13 ;
struct V_7 * V_7 ;
V_14 = F_14 ( V_26 , 0 ) ;
F_15 ( V_26 , L_1 , & V_13 ) ;
V_7 = F_16 ( F_17 ( V_26 ) ) ;
if ( F_11 ( V_7 ) )
return;
V_12 = F_7 ( V_7 , V_13 , V_14 ) ;
if ( F_11 ( V_12 ) )
return;
F_18 ( V_26 , V_27 , V_12 ) ;
return;
}
