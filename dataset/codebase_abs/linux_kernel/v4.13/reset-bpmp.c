static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
unsigned int V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 V_9 ;
struct V_10 V_11 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_12 = V_5 ;
V_9 . V_13 = V_6 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_15 ;
V_11 . V_16 . V_17 = & V_9 ;
V_11 . V_16 . V_18 = sizeof( V_9 ) ;
return F_4 ( V_7 , & V_11 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
unsigned long V_6 )
{
return F_3 ( V_3 , V_19 , V_6 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
unsigned long V_6 )
{
return F_3 ( V_3 , V_20 , V_6 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
unsigned long V_6 )
{
return F_3 ( V_3 , V_21 , V_6 ) ;
}
int F_8 ( struct V_1 * V_7 )
{
V_7 -> V_3 . V_22 = & V_23 ;
V_7 -> V_3 . V_24 = V_25 ;
V_7 -> V_3 . V_26 = V_7 -> V_27 -> V_26 ;
V_7 -> V_3 . V_28 = V_7 -> V_29 -> V_30 ;
return F_9 ( V_7 -> V_27 , & V_7 -> V_3 ) ;
}
