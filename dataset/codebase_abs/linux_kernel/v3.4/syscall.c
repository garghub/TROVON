static int F_1 ( struct V_1 * V_2 , long * V_3 ,
unsigned long args [ 6 ] , unsigned int V_4 ,
unsigned long * V_5 , unsigned long * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_3 ( ! V_8 ) )
return - V_9 ;
* V_5 = F_4 ( V_8 ) ;
* V_6 = F_5 ( V_8 ) ;
* V_3 = F_6 ( V_2 , V_8 ) ;
if ( * V_3 != - 1L && V_4 > 0 )
F_7 ( V_2 , V_8 , 0 , V_4 , args ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , long * V_3 ,
unsigned long args [ 6 ] , unsigned int V_4 ,
unsigned long * V_5 , unsigned long * V_6 )
{
long V_10 ;
unsigned long V_11 ;
if ( F_3 ( V_4 > 6 ) )
return - V_12 ;
if ( V_2 == V_13 )
return F_1 ( V_2 , V_3 , args , V_4 , V_5 , V_6 ) ;
V_10 = V_2 -> V_10 ;
if ( F_3 ( ! V_10 ) )
return - V_9 ;
V_11 = F_9 ( V_2 , V_10 ) ;
if ( F_3 ( ! V_11 ) ||
F_3 ( F_1 ( V_2 , V_3 , args , V_4 , V_5 , V_6 ) ) ||
F_3 ( F_9 ( V_2 , V_10 ) != V_11 ) )
return - V_9 ;
return 0 ;
}
