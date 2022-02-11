static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
V_5 = V_2 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_3 ( struct V_6 * V_7 , void * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_8 ;
return ( V_7 -> V_11 == V_10 ) &&
( V_7 -> V_12 == & V_13 . V_12 ) ;
}
struct V_1 * F_4 ( struct V_9 * V_10 )
{
if ( V_10 ) {
struct V_6 * V_7 = F_5 ( & V_14 , NULL ,
V_10 , F_3 ) ;
if ( ! V_7 )
return NULL ;
return F_6 ( V_7 ) ;
} else {
return V_5 ;
}
}
