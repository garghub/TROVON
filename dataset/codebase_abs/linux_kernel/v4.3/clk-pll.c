static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 1 << V_4 -> V_5 , V_4 -> V_6 + V_7 ) ;
F_4 ( 10 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 1 << V_4 -> V_5 , V_4 -> V_6 + V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 1 << 31 , V_4 -> V_6 + V_8 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 1 << 31 , V_4 -> V_6 + V_7 ) ;
}
static unsigned long F_8 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_10 ;
}
struct V_11 * F_9 ( const char * V_12 , const char * V_13 ,
void T_1 * V_6 , T_2 V_5 , unsigned long V_10 )
{
struct V_3 * V_4 ;
struct V_11 * V_11 ;
struct V_14 V_15 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_16 ) ;
if ( ! V_4 )
return F_11 ( - V_17 ) ;
V_15 . V_12 = V_12 ;
V_15 . V_18 = & V_19 ;
V_15 . V_20 = 0 ;
V_15 . V_21 = ( V_13 ? & V_13 : NULL ) ;
V_15 . V_22 = ( V_13 ? 1 : 0 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 . V_15 = & V_15 ;
V_11 = F_12 ( NULL , & V_4 -> V_2 ) ;
if ( F_13 ( V_11 ) )
F_14 ( V_4 ) ;
return V_11 ;
}
