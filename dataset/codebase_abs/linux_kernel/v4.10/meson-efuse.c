static int F_1 ( void * V_1 , unsigned int V_2 ,
void * V_3 , T_1 V_4 )
{
T_2 * V_5 = V_3 ;
int V_6 ;
V_6 = F_2 ( V_5 , V_7 , V_2 ,
V_4 , 0 , 0 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
unsigned int V_12 ;
if ( F_4 ( V_13 , & V_12 , 0 , 0 , 0 , 0 , 0 ) < 0 )
return - V_14 ;
V_15 . V_16 = & V_9 -> V_16 ;
V_15 . V_17 = F_1 ;
V_15 . V_12 = V_12 ;
V_11 = F_5 ( & V_15 ) ;
if ( F_6 ( V_11 ) )
return F_7 ( V_11 ) ;
F_8 ( V_9 , V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_10 ( V_9 ) ;
return F_11 ( V_11 ) ;
}
