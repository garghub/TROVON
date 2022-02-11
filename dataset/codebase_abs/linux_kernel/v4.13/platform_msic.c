static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
if ( V_3 == V_5 ) {
F_2 ( & V_6 ) ;
return 0 ;
}
return F_3 ( & V_6 ) ;
}
static int T_1 F_4 ( void )
{
static struct V_1 V_7 = {
. V_8 = F_1 ,
} ;
if ( F_5 () )
F_6 ( & V_7 ) ;
return 0 ;
}
void * F_7 ( void * V_9 , enum V_10 V_11 )
{
struct V_12 * V_13 = V_9 ;
F_8 ( V_11 < 0 || V_11 >= V_14 ) ;
V_15 . V_16 [ V_11 ] = V_13 -> V_16 ;
return NULL ;
}
