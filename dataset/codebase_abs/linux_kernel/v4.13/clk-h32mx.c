static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( V_5 -> V_7 , V_8 , & V_6 ) ;
if ( V_6 & V_9 )
return V_3 / 2 ;
if ( V_3 > V_10 )
F_4 ( L_1 ) ;
return V_3 ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long * V_3 )
{
unsigned long div ;
if ( V_11 > * V_3 )
return * V_3 ;
div = * V_3 / 2 ;
if ( V_11 < div )
return div ;
if ( V_11 - div < * V_3 - V_11 )
return div ;
return * V_3 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 = 0 ;
if ( V_3 != V_11 && ( V_3 / 2 ) != V_11 )
return - V_12 ;
if ( ( V_3 / 2 ) == V_11 )
V_6 = V_9 ;
F_7 ( V_5 -> V_7 , V_8 ,
V_9 , V_6 ) ;
return 0 ;
}
static void T_2 F_8 ( struct V_13 * V_14 )
{
struct V_4 * V_5 ;
struct V_15 V_16 ;
const char * V_17 ;
struct V_7 * V_7 ;
int V_18 ;
V_7 = F_9 ( F_10 ( V_14 ) ) ;
if ( F_11 ( V_7 ) )
return;
V_5 = F_12 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 )
return;
V_17 = F_13 ( V_14 , 0 ) ;
V_16 . V_20 = V_14 -> V_20 ;
V_16 . V_21 = & V_22 ;
V_16 . V_23 = V_17 ? & V_17 : NULL ;
V_16 . V_24 = V_17 ? 1 : 0 ;
V_16 . V_25 = V_26 ;
V_5 -> V_2 . V_16 = & V_16 ;
V_5 -> V_7 = V_7 ;
V_18 = F_14 ( NULL , & V_5 -> V_2 ) ;
if ( V_18 ) {
F_15 ( V_5 ) ;
return;
}
F_16 ( V_14 , V_27 , & V_5 -> V_2 ) ;
}
