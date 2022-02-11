struct V_1 * F_1 ( struct V_2 * V_3 , void * V_4 )
{
struct V_1 * V_5 = NULL ;
unsigned V_6 ;
V_5 = F_2 ( sizeof( struct V_1 ) , V_7 ) ;
if ( V_5 == NULL )
return NULL ;
V_5 -> V_4 = V_4 ;
V_5 -> V_8 = V_3 -> V_8 ;
F_3 ( & V_5 -> V_9 ) ;
V_6 = F_4 ( & V_3 -> V_10 ) ;
F_5 ( & V_5 -> V_11 , & V_12 , & V_5 -> V_9 ,
V_3 -> V_13 , V_6 ) ;
return V_5 ;
}
void F_6 ( struct V_1 * V_5 )
{
int V_14 = F_7 ( & V_5 -> V_11 ) ;
if ( ! V_14 )
F_8 ( & V_5 -> V_11 , L_1 ) ;
else
F_8 ( & V_5 -> V_11 , L_2 ) ;
}
static const char * F_9 ( struct V_5 * V_5 )
{
return L_3 ;
}
static const char * F_10 ( struct V_5 * V_15 )
{
struct V_1 * V_5 = F_11 ( V_15 ) ;
return ( const char * ) V_5 -> V_8 -> V_16 ;
}
static bool F_12 ( struct V_5 * V_15 )
{
return true ;
}
