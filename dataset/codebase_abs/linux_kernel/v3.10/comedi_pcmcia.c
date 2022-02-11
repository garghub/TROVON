struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ? F_2 ( V_3 -> V_4 ) : NULL ;
}
static int F_3 ( struct V_1 * V_5 ,
void * V_6 )
{
if ( V_5 -> V_7 == 0 )
return - V_8 ;
return F_4 ( V_5 ) ;
}
int F_5 ( struct V_2 * V_3 ,
int (* F_6)( struct V_1 * , void * ) )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_9 ;
if ( ! V_5 )
return - V_10 ;
if ( ! F_6 )
F_6 = F_3 ;
V_9 = F_7 ( V_5 , F_6 , NULL ) ;
if ( V_9 )
return V_9 ;
return F_8 ( V_5 ) ;
}
void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 )
F_10 ( V_5 ) ;
}
int F_11 ( struct V_1 * V_5 ,
struct V_11 * V_12 )
{
return F_12 ( & V_5 -> V_3 , V_12 , 0 ) ;
}
void F_13 ( struct V_1 * V_5 )
{
F_14 ( & V_5 -> V_3 ) ;
}
int F_15 ( struct V_11 * V_11 ,
struct V_13 * V_13 )
{
int V_9 ;
V_9 = F_16 ( V_11 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_17 ( V_13 ) ;
if ( V_9 < 0 ) {
F_18 ( V_11 ) ;
return V_9 ;
}
return 0 ;
}
void F_19 ( struct V_11 * V_11 ,
struct V_13 * V_13 )
{
F_20 ( V_13 ) ;
F_18 ( V_11 ) ;
}
