static int F_1 ( unsigned V_1 , unsigned long * V_2 )
{
return F_2 ( V_3 , V_1 , V_2 ) ;
}
static int F_3 ( unsigned V_1 , unsigned long V_2 )
{
return F_4 ( V_3 , V_1 , V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
const struct V_8 * V_9 =
F_6 ( V_10 , & V_5 -> V_11 ) ;
V_5 -> V_11 . V_12 = ( void * ) V_9 -> V_13 ;
V_7 = F_7 ( V_5 , V_14 , 0 ) ;
V_3 = F_8 ( & V_5 -> V_11 , V_7 ) ;
if ( F_9 ( V_3 ) )
return F_10 ( V_3 ) ;
return F_11 ( V_5 ) ;
}
