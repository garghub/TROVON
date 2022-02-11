static void F_1 ( struct V_1 * V_2 , unsigned int type , unsigned int V_3 , int V_4 )
{
F_2 (KERN_DEBUG pr_fmt(L_1),
dev_name(&handle->dev->dev), type, code, value) ;
}
static int F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int error ;
V_2 = F_4 ( sizeof( struct V_1 ) , V_11 ) ;
if ( ! V_2 )
return - V_12 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_13 = L_2 ;
error = F_5 ( V_2 ) ;
if ( error )
goto V_14;
error = F_6 ( V_2 ) ;
if ( error )
goto V_15;
F_2 (KERN_DEBUG pr_fmt(L_3),
dev_name(&dev->dev),
dev->name ?: L_4 ,
dev->phys ?: L_4 ) ;
return 0 ;
V_15:
F_7 ( V_2 ) ;
V_14:
F_8 ( V_2 ) ;
return error ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_2 (KERN_DEBUG pr_fmt(L_5),
dev_name(&handle->dev->dev)) ;
F_10 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_16 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_16 ) ;
}
