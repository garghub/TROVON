struct V_1 * F_1 ( unsigned int V_2 )
{
if ( V_2 >= V_3 )
return NULL ;
if ( ! V_4 [ V_2 ] )
return NULL ;
return V_4 [ V_2 ] -> V_5 . V_6 ;
}
int F_2 ( unsigned int V_2 , unsigned long V_7 , unsigned long V_8 )
{
struct V_9 * V_10 ;
if ( V_2 >= V_3 ) {
return - V_11 ;
}
V_10 = V_4 [ V_2 ] ;
if ( ! V_10 )
return - V_12 ;
F_3 ( V_7 , V_8 ) ;
if ( V_13 )
F_4 ( V_10 , L_1 ) ;
return 0 ;
}
int F_5 ( unsigned int V_2 , unsigned long * V_8 )
{
struct V_9 * V_10 ;
if ( V_2 >= V_3 ) {
return - V_11 ;
}
V_10 = V_4 [ V_2 ] ;
if ( ! V_10 )
return - V_12 ;
if( V_10 -> V_14 ) {
return - V_12 ;
}
* V_8 = F_6 () ;
return 0 ;
}
int F_7 ( unsigned int V_2 , unsigned long V_7 , unsigned long V_8 )
{
struct V_9 * V_10 ;
if ( V_2 >= V_3 ) {
return - V_11 ;
}
V_10 = V_4 [ V_2 ] ;
if ( ! V_10 )
return - V_12 ;
F_8 ( V_7 , V_8 ) ;
if ( V_13 )
F_4 ( V_10 , L_2 ) ;
return 0 ;
}
